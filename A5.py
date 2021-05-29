
class Node:
    def __init__(self,key,value):
        self.key = key
        self.value = value

class Hash:
    def __init__(self):
        self.size = int (input("Enter the Size of Hash Table : "))
        self.HashTable = [[]for i in range(self.size)]
        self.num_of_number = 0
        self.comparison = 0
    
    def isTableFull(self):
        if self.num_of_number == self.size:
            return True
        else:
            return False
    
    def HashFun(self,key):
        return key % self.size

    def InsertElement(self,Node):
        if self.isTableFull():
            print("Hash Table Is Full")
            return False
        position = self.HashFun(Node.key)
        self.HashTable[position].append(Node)

    def search(self,key):
        hash_key = self.HashFun(key)
        bucket = self.HashTable[hash_key]
        for i in bucket:
            if i.key == key:
                return i.value

    def delete(self,key):
        hash_key = self.HashFun(key)
        key_exist = False
        bucket = self.HashTable[hash_key]
        for i in bucket:
            if i.key == key:
                key_exist = True
                break
        if key_exist:
            bucket.remove(i)
            print("Key {} Deleted",format(key))
        else:
            print("Key {} Not Found",format(key))

    def display(self):
        print("---------------------------")
        for i in range(len(self.HashTable)):
            print(i, end = " ")
            for j in self.HashTable[i]:
                print("-->", end = " ")
                print(j.value, end = " ")
            print()

# main 
hash_object = Hash()

hash_object.InsertElement(Node(10,"Hello"))
hash_object.InsertElement(Node(11,"There"))
hash_object.InsertElement(Node(12,"General"))
hash_object.InsertElement(Node(20,"Kanobi"))

hash_object.display()
print(hash_object.search(20))
hash_object.delete(20)
hash_object.display()
