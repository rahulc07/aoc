file=open("input", "r")
lines=[]
indicies_of_fail=[]
safe = 0
fails = 0
def always_i_or_d(array):
    global fails
    def use_i_or_d():
        sum = 0
        for num in range(1, len(array)):
            sum+=(array[num] - array[num-1])
        return sum > 0
    def check(increasing):
        for index in range(1, len(array)):
            global fails
            if (increasing and (array[index] < array[index-1])) or ((not increasing) and (array[index] > array[index-1])):
               fails+=1
               indicies_of_fail.append(index)
    check(use_i_or_d())
    
	 
def convert_to_int_array(array):
    for num in range(len(array)):
       array[num] = int(array[num])
       
def calc(array):
   global fails
   global indicies_of_fail
   fails = 0
   indicies_of_fail = []
   current_num = array[0]
   always_i_or_d(array)
   if fails > 1:
     return False
   for index in range(1, len(array)):
     diff = abs(array[index] - current_num)
     if (diff < 1 or diff > 3) and (not index in indicies_of_fail):
       fails+=1
     current_num = array[index]
   if fails > 1:
     return False
   if fails == 1:
     print(indicies_of_fail)
     print(array)
   return True

for line in file:
  lines.append(line.strip())
for line in lines:
   array = line.split(" ")
   convert_to_int_array(array)
   if (calc(array)):
     safe+=1
print(safe)

     
     
     

	
	
