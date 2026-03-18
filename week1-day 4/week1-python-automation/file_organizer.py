import os
import shutil

def organize_folder(path):
    
    if not os.path.exists(path):
        print ("\nPath does not exist!")
        return
        
    os.chdir(path)
    
    extension_map = { 
    "Images" : [ ".jpg", ".jpeg", ".png", ".gif", ".bmp" ] , 
    "Videos" : [ ".mp4", ".mov", ".mkv" ] , 
    "Documents" : [ ".pdf", ".txt", ".docx", ".pptx", ".xlsx" ] ,
    "Programs" : [ ".exe", ".msi" ] 
     }
     
    for file in os.listdir():
         if os.path.isdir(file):
             continue
         
         name, extension = os.path.splitext(file)
         extension = extension.lower()
         
         for folder_name, extensions in extension_map.items():
             if extension in extensions:
                 if not os.path.exists(folder_name):
                     os.makedirs(folder_name)
                 
                 print (f"Moving {file} -> {folder_name}")
                 shutil.move (file, folder_name)
                 break

print ("---------- FILE ORGANIZER ----------\n")

path = input("Enter complete path of the folder to\norgazine files(or . for current) : \n")

organize_folder(path)
 
print ("\nTask Completed.\n")