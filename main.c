#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *task;
    int completed;
} Task;

Task *tasks = NULL;
int length=0;

void addTask(const char *task ){
    tasks = (Task *)realloc(tasks,(length +1)* sizeof(Task));
    tasks[length].task= (char *)malloc(strlen(task)+1);
    tasks[length].completed= 0;

    strcpy(tasks[length].task, task);

    length++;
    printf("Task Added \n");
    
}

void listTasks(){
    char status;
    for (int i = 0; i < length; i++)
    {
        if (tasks[i].completed==1)
        {
            status = 'd';
        }else
        {
            status='n';
        }
        
        printf("%d. %s [%c] \n", i+1, tasks[i].task, status);
        
    }
    
}

void markCompleted(int index){
    if (index==length && index>0)
    {
        tasks[index-1].completed=1;
        printf("Task marked as completed \n");
        
    }else
    {
        printf("Invalid index \n");
        
    }
    
    
}

void deletedTask(int index){
    if (index<= length && index>0)
    {
        index = index-1;

        free(tasks[index].task);
        for (int i = index; i < length-1; i++)
        {
            tasks[i]= tasks[i+1];
        }
        length--;

        tasks = (Task *)realloc(tasks,(length * sizeof(Task)));
    }else
    {
        printf("Invalid Index \n");
        
    }
    
    
}
void editTask(int index, const char* task){
    if (index<=length && index>0)
    {
        index = index-1;


        char *editedTask = (char *)realloc(tasks[index].task, strlen(task)+1);
        if (editedTask != NULL)
        {
            tasks[index].task = editedTask;
            strcpy(tasks[index].task, task);
            printf("Task Updated Succesfully \n");
            
        }
        
    }else
    {
        printf("Invalid Index \n");
        
    }
    
    
}
 
int main(){
    int choice;
    int running=1;
    int indexInput;
    char taskInput[100];

    printf(" \n Options\n");
    printf("1. Add a task \n");
    printf("2. List all tasks \n");
    printf("3. Mark as completed \n");
    printf("4. Edit task \n");
    printf("5. Delete task \n");
    printf("6. EXIT \n");
    
    while (running)
    {
        printf("Enter choice (1 ,2 ,3 ,4 ,5 ,6 ): ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Task: ");
            getchar();
            fgets(taskInput, sizeof(taskInput), stdin);
            taskInput[strcspn(taskInput, "\n")]= '\0';
            addTask(taskInput);

            break;
        case 2:
            listTasks();
            break;

        case 3:
            printf("Enter Index: \t");
            scanf("%d", &indexInput);
            markCompleted(indexInput);
            
            break;
        case 4:
            printf("Enter Index \t");
            scanf("%d", &indexInput);
            printf("Enter edited task; \t");
            getchar();
            fgets(taskInput, sizeof(taskInput), stdin);
            taskInput[strcspn(taskInput, "\n")]= '\0';

            editTask(indexInput, taskInput);

        case 5:
            printf("Enter Index: \t");
            scanf("%d", &indexInput);

            deletedTask(indexInput);

            break;
        case 6:
            running=0;
            break;
        default:
            printf("Invalid Choice \n");
            break;
        }
    }
    free(tasks);
    
    return 0;
}