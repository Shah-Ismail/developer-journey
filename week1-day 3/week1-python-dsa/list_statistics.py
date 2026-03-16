def func (user_input):
    numbers = [int(x) for x in user_input.split()]
    if len(numbers) == 0:
        print ("0 numbers found!")
        return
        
    maximum = max(numbers)
    minimum = min(numbers)
    total_sum = sum(numbers)
    average = total_sum / len(numbers)
    
    print (f"Results for {numbers} : ")
    print (f"Maximum number is {maximum}.")
    print (f"Minimum number is {minimum}.")
    print (f"Sum is {total_sum}.")
    print (f"Average is {average}.")
    
while (True):
    print ("\n----------LISTS OPERATIONS----------\n")
    print ("Choose an option : ")
    print ("1.Perform lists operations.")
    print ("2.Exit.")
    choice = int(input("Enter your choice here : "))
    
    if choice == 1:
        user_input = input("Enter numbers separated by spaces : ")
        func (user_input)
    elif choice == 2:
        print ("Exiting...")
        break
    else:
        print ("Invalid Input!")