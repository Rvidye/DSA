# Consider telephone book database of N clients. Make use of hash table implementation to quickly look up client's telephone number, Make use of two collision handaling techniques
# and compare then using number of comparison required to find a set of telephone numbers.

class Hash:
    def __init__(self):
        self.size = int (input("Enter the Size of Hash Table : "))
        self.HashTable = list(0 for i in range(self.size))
        self.num_of_number = 0
        self.comparison = 0
    
    def isTableFull(self):
        if self.num_of_number == self.size:
            return True
        else:
            return False
    
    def HashFun(self,element):
        return element%self.size

    def InsertElement_Linear(self,element):
        if self.isTableFull():
            print("Hash Table Is Full")
            return False
        
        OccupiedStatus = False
        position = self.HashFun(element)
        if self.HashTable[position] == 0:
            self.HashTable[position] = element
            print("Telephone Number "+str(element) +" at position "+str(position))
            OccupiedStatus = True
        else:
            print("Collision has occurred for Telephone Number "+str(element)+" at index "+str(position))
            position = self.LinearProbing(element,position)
            self.HashTable[position] = element
            OccupiedStatus = True
            self.num_of_number += 1
        return OccupiedStatus

    def LinearProbing(self,element,position):
        while self.HashTable[position] != 0:
            position += 1
            if position >= self.size:
                position = 0
        return position

    def Search(self,element):
        found = False
        position = self.HashFun(element)
        self.comparison += 1

        if self.HashTable[position] == element:
            return position
            isFound = True
        else :
            temp = position - 1
            while position < self.size:
                if self.HashTable[position] != element:
                    position += 1
                    self.comparison += 1
                else:
                    return position
            
            position = temp
            while position > 0:
                if self.HashTable[position] != element:
                    position -= 1
                    self.comparison += 1
                else :
                    return position
    
            if not found:
                print("Element Not Found")
                return False
        
    def display(self):
        print("---------------------------")
        print("Position\tTelephone Number\n")
        for i in range(self.size):
            print("\t"+str(i) + " -->"+str(self.HashTable[i]))

# main 
hash_object = Hash()

hash_object.InsertElement_Linear(79)
hash_object.InsertElement_Linear(29)
hash_object.InsertElement_Linear(85)
hash_object.InsertElement_Linear(40)
hash_object.InsertElement_Linear(33)
hash_object.InsertElement_Linear(77)
hash_object.InsertElement_Linear(67)
hash_object.InsertElement_Linear(66)
hash_object.InsertElement_Linear(75)
hash_object.InsertElement_Linear(88)

hash_object.display()

print("Position of 88 is : " + str(hash_object.Search(88)))
print("Number of Comparisons done while searching : "+str(hash_object.comparison))
