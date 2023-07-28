class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def Tinsert(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def Hinsert(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    def size(self):
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

    def Vdelete(self, value):
        if not self.head:
            return
        if self.head.value == value:
            self.head = self.head.next
            return
        current = self.head
        while current.next:
            if current.next.value == value:
                current.next = current.next.next
                return
            current = current.next

    def exists(self, value):
        current = self.head
        while current:
            if current.value == value:
                return True
            current = current.next
        return False

    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    def print(self):
        elements = []
        current = self.head
        while current:
            elements.append(str(current.value))
            current = current.next
        elements.append("None")
        print("->".join(elements))


ll = LinkedList()
while True:
    inpt = input().split()
    if inpt[0] == 'exit':
        break
    elif inpt[0] == 'Tinsert':
        ll.Tinsert(int(inpt[1]))
    elif inpt[0] == 'Hinsert':
        ll.Hinsert(int(inpt[1]))
    elif inpt[0] == 'size':
        print(ll.size())
    elif inpt[0] == 'Vdelete':
        ll.Vdelete(int(inpt[1]))
    elif inpt[0] == 'exists':
        print(ll.exists(int(inpt[1])))
    elif inpt[0] == 'Reverse':
        ll.reverse()
    elif inpt[0] == 'print':
        ll.print()
