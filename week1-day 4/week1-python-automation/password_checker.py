def password_checker(password):
    uppercase = False
    lowercase = False
    digit = False
    special_char = False
    length = len(password)
    
    if (length >= 8):
        for char in password:
            if char >= 'A' and char <= 'Z':
                uppercase = True
            if char >= 'a' and char <= 'z':
                lowercase = True
            if char >= '0' and char <= '9':
                digit = True
            if not char.isalnum():
                special_char = True
        if uppercase and lowercase and digit and special_char:
            print ("Password Strength : Strong ")
        elif (uppercase and lowercase and digit) or (uppercase and lowercase and special_char) or (uppercase and special_char and digit) or (special_char and lowercase and digit):
            print ("Password Strength : Very Good")
        elif (uppercase and lowercase) or (uppercase and digit) or (uppercase and special_char) or (lowercase and digit) or (lowercase and special_char) or (digit and special_char) :
            print ("Password Strength : Good ")
        elif uppercase or lowercase or digit or special_char:
            print ("Password Strength : Weak ")
    else:
        print (f"\nLength {length} of the password is low\nLength must be 8 or more!\n")
    
while True:
    print ("\n---------- PASSWORD STRENGTH CHECKER ----------\n")
    print ("Choose an option from the following :")
    print ("1.Check password strength.")
    print ("2.Exit.")
    
    try:
        choice = int(input("Enter your choice here : "))
    except ValueError:
        print ("\nInvalid Input!\n")
        continue
    
    if choice == 1:
        print ("\nPassword must contain : \n1.Atleast 8 characters.\n2.Atleast 1 uppercase letter(A-Z).\n3.Atleast 1 lowercase letter(a-z).\n4.Atleast 1 digit(0-9).\n")
        password = input("Enter your password here : ")
        print("")
        password_checker(password)
    elif choice == 2:
        print ("\nExiting...\n")
        break
    else:
        print ("\nInvalid Input!\n")