import json
import os

filename = "contacts.json"

def load_contacts():
    if os.path.exists(filename):
        with open(filename, 'r') as file:
            try:
                return json.load(file)
            except:
                return {}
    else:
        return {}

def save_contacts(contacts):
    with open(filename, 'w') as file:
        json.dump(contacts, file, indent = 4)

def add_contact():
    contacts = load_contacts()
    
    name = input("\nEnter name : ")
    
    if name in contacts:
        print (f"Name already exits!")
        return
    else:
        phone = input("Enter phone number : ")
        contacts[name] = phone
        save_contacts(contacts)
        print (f"\nContact {name} added successfully.\n")

def view_contacts():
    contacts = load_contacts()
    
    if contacts:
        print ("----- Contacts List -----")
        for name, phone in contacts.items():
            print (f"Name : {name}\tPhone : {phone}")
    else:
        print ("No contacts found!")

def search_contact():
    contacts = load_contacts()
    
    targetName = input("Enter name to search : ")
    
    if targetName in contacts:
        phone = contacts[targetName]
        print (f"Name : {targetName}\tPhone : {phone}")
    else:
        print (f"{targetName} not found in contacts")

def delete_contact():
    contacts = load_contacts()
    targetName = input("Enter name to delete : ")
    
    if targetName in contacts:
        del contacts[targetName]
        save_contacts(contacts)
        print (f"{targetName} deleted successfully.")
    else:
        print (f"{targetName} not found!")

def menu():
    while (True):
        try:
            print ("\n---------- Contact Book ----------\n")
            print ("Choose an option :")
            print ("1.Add new contact.")
            print ("2.View all contacts.")
            print ("3.Search contact.")
            print ("4.Delete contact.")
            print ("5.Exit.")
            
            choice = int(input("Enter your choice here : "))
            
            if choice == 1:
                add_contact()
            elif choice == 2:
                view_contacts()
            elif choice == 3:
                search_contact()
            elif choice == 4:
                delete_contact()
            elif choice == 5:
                print ("\nExiting...")
                break
            else :
                print ("\nInvalid Input!")
        except ValueError:
                print ("\nInvalid Input!")

menu()