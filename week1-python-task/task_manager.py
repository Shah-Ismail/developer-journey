def add_task(tasks):
    task = input("Enter task : ")
    tasks.append(task)
    print("Task added!")

def view_tasks(tasks):
    print("\nYour tasks  : \n")
    for i, task in enumerate(tasks, 1):
        print(f"{i}. {task}")

def save_tasks(tasks):
    with open("tasks.txt", "w") as file:
        for task in tasks:
            file.write(task + "\n")

def load_tasks():
    try:
        with open("tasks.txt", "r") as file:
            return [line.strip() for line in file]
    except FileNotFoundError:
        return []
    
def menu():
    tasks = load_tasks()

    while True:
        print("\nChoose 1-3 : ")
        print("1.Add task.")
        print("2.View tasks:")
        print("3.Exit.")

        choice = input("Enter you choice : ")

        if choice == "1":
            add_task(tasks)
            save_tasks(tasks)
        
        elif choice == "2":
            view_tasks(tasks)
        
        elif choice == "3":
            break
        
        else:
            print("Invalid Choice!")

menu()