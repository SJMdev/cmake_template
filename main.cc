#include <string>
#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>

int main()
{
    int inotify_fd = inotify_init();
    if (inotify_fd == -1)
    {
        printf("failed to init.exiting..");
        exit(1);
    }
    else 
    {
        printf("init successful!");
        
    }
    std::string to_watch = "to_watch.txt";
    if (inotify_add_watch(inotify_fd, to_watch.c_str(), IN_MODIFY) == -1)
    {
        printf("failed to add watch");
        exit(1);
    }
    else
    {
        printf("succesfully added watch.\n");
        
    }
    
    char *buffer = (char *)malloc(sizeof(struct inotify_event) + NAME_MAX +1);
    while (true)
    {
        int result = read(inotify_fd,static_cast<void *>(buffer), 1);
        
        if(result == 0)
        {
            printf("eof..");            
        }
        if(result)
        {
            printf("result!");
            inotify_event *event = reinterpret_cast<inotify_event *>(buffer); 
            
            if (event->mask == IN_MODIFY)
            {
                printf("modified file!");
            }
        }
        else if (result == -1)
        {
            printf("failed.");
            exit(1);
        }
    }
}
