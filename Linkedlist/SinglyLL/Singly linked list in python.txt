class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class LinkedList:
    def _init_(self,data):
        self.head=Node(data)
    def addbegining(self,data):
        newnode=Node(data)
        newnode.next=self.head
        self.head=newnode
    def addmiddle(self,midnode,data):
        newnode=Node(data)
        newnode.next=midnode.next
        midnode.next=newnode
    def addend(self,data):
        if self.head==None:
            self.head=Node(data)
            return
        last=self.head
        while last.next:
            last=last.next
        last.next=Node(data)
    def addposition(self,data,position):
        if position==1:
            self.addbegining(data)
            return
        if self.head==None:
            self.head=Node(data)
            return
        last=self.head
        while last.next:
            if position==2:
                self.addmiddle(last,data)
                return
            last=last.next
            position-=1
        self.addend(data)
    def deletebegining(self):
        if self.head==None:
            return
        self.head=self.head.next
    def deletemiddle(self,midnode):
        last=self.head
        if midnode==None:
            return
        if last==midnode:
            self.head=self.head.next
            return
        while last.next:
            if last.next==midnode:
                last.next=last.next.next
                return
            last=last.next
    def deleteend(self):
        if self.head==None or self.head.next==None:
            self.head=None
            return
        last=self.head
        while last.next.next:
            last=last.next
        last.next=None
    def deleteposition(self,position):
        if self.head==None:
            return
        last=self.head
        while last and position>1:
            position-=1
            last=last.next
        self.deletemiddle(last)
    def printdata(self):
        last=self.head
        while last:
            print(last.data,end=' ')
            last=last.next
        print()
l=LinkedList(4)
l.addend(5)
l.addend(6)
l.addend(7)
l.addend(8)
l.addbegining(1)
l.addposition(3,2)
l.addposition(2,2)
l.addposition(1,1)
l.addposition(8,10)
l.printdata()
l.deletebegining()
l.deleteend()
l.printdata()
l.addposition(2,2)
l.addposition(6,7)
l.printdata()
l.deletemiddle(l.head.next)
l.deleteposition(6)
l.printdata()
