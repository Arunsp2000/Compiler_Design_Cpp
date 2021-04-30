import csv
import re
import copy
from prettytable import PrettyTable

class optimize:
    def __init__(self):
        self.leaderspos=set()
        self.leaderspos.add(0)
        self.basicblocks=[]
        self.reader=[]
        self.log=['and','or']
        with open('ICG.txt') as file:
            self.reader=list(csv.reader(file))
            # print(self.reader)
            for row in range(len(self.reader)):
                # print(self.reader[row][3])
                if(self.reader[row][0]=="if" or self.reader[row][0]=="goto"):
                    self.leaderspos.add(row+1)
                if(self.reader[row][0]=="label"):
                    self.leaderspos.add(row)
                

            self.leaderspos.add(len(self.reader))
            self.leaderspos=sorted(self.leaderspos)
            for i in range(len(self.leaderspos)-1):
                self.basicblocks.append(self.reader[self.leaderspos[i]:self.leaderspos[i+1]])

    
    def string_to_num(self,string1):
        return bool(re.match(r'^-?\d+(\.\d+)?$', string1))
    
    def isPowerOfTwo(self,num):
        count_pwr=0
        while (num != 1):
            if (num % 2 != 0):
                return 0
            num = num // 2
            count_pwr=count_pwr+1  
        return count_pwr
        
    def strength_red(self):
        for j in self.basicblocks:
            for i in j:
                if(i[0]=='*'):
                    if(self.string_to_num(i[2])):
                        is_two=self.isPowerOfTwo(int(i[2]))
                        if(is_two):
                            i[0]="<<"
                            i[2]=str(is_two)
                    
                    elif(self.string_to_num(i[1])):
                        is_two=self.isPowerOfTwo(int(i[1]))
                        if(is_two):
                            i[0]="<<"
                            i[1]=i[2]
                            i[2]=str(is_two)
                
                if(i[0]=="/"):
                    if(self.string_to_num(i[2])):
                        is_two=self.isPowerOfTwo(int(i[2]))
                        if(is_two):
                            i[0]=">>"
                            i[2]=str(is_two)
        
    
    def const_fold(self):
        for j in self.basicblocks:
            for i in j:
                if(self.string_to_num(i[1]) and self.string_to_num(i[2])):
                    oper=i[0]
                    if(oper == '&&'):
                        oper='and'
                    if(oper=='||'):
                        oper='or'
                    
                    expr_str=i[1] +" " + oper + " " + i[2]
                    i[1]=str(eval(expr_str))
                    i[0]='='
                    i[2]=""
    

    def const_prop(self):
        for j in self.basicblocks:
            keep_var={}
            for i in j:
                if(i[0]=='=' and i[2]==''):
                    keep_var[i[3]]=i[1]

                if(i[1] in keep_var):
                    i[1]=keep_var[i[1]]

                if(i[2] in keep_var):
                    i[2]=keep_var[i[2]]

    def remove_dead_control(self):
        remove_el=set()
        remove_bl=set()
        index=0
        block=-1
        label=[]
        old_index=-35
        for j in self.basicblocks:
            block=block+1
            for i in j:
                if(i[0]=="if"):
                    if(int(i[1])==0):
                        remove_el.add(index)
                        # remove_bl.add(block+1)
                        old_index=index
                        label.append(i[3])
                if(i[0]=="label"):
                    if(i[3] in label):
                        remove_bl.add(block)
                if(i[0]=="goto" and (index-1)==old_index):
                        remove_bl.add(block)

                
                index=index+1
        
        new_icg=[]
        block=-1
        index=0
        for j in self.basicblocks:
            block=block+1
            for i in j:
                if(block not in remove_bl):
                    if(index not in remove_el):
                        new_icg.append(i)
            
                index=index+1
        
        self.basicblocks=new_icg


    def process(self):
        scam=copy.deepcopy(self.basicblocks)
        self.strength_red()
        self.show()
        self.const_fold()
        self.const_prop()
        while(scam!=self.basicblocks):
            scam=copy.deepcopy(self.basicblocks)
            self.const_fold()
            self.const_prop()
            # self.strength_red()
        self.remove_dead_control()

        
    def show(self):
        tab=PrettyTable(["Operator","Arg1","Arg2","Destination"])
        for j in self.basicblocks:
            for i in j:
                tab.add_row(i)
        

        print(tab)
    
    def final_show(self):
        tab=PrettyTable(["Operator","Arg1","Arg2","Destination"])
        for j in self.basicblocks:
                tab.add_row(j)
        

        print(tab)


icg=optimize()
print(icg.show())


icg.process()
print(icg.final_show())
