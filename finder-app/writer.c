#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int write_to_file(const char *file_path, const char *content_string)
{

    if (file_path == NULL)
    {
        syslog(LOG_ERR, "file_path is empty");
        return 1;
    }

    if (content_string == NULL)
    {
        syslog(LOG_ERR, "content_string is empty");
        return 1;
    }

    FILE *file = fopen(file_path, "w");
    if (file == NULL)
    {
        syslog(LOG_ERR, "Unable to open the file");
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to file %s", content_string, file_path);
    fputs(content_string, file);

    fclose(file);
    return 0;
}

int main(int argc, char *argv[])
{

    openlog(NULL, 0, LOG_USER);

    if (argc < 3)
    {
        syslog(LOG_ERR, "Parameters are missing");
        closelog();
        exit(1);
    }

    int res = write_to_file(argv[1], argv[2]);
    if (res != 0)
    {
        closelog();
        exit(1);
    }

    closelog();
    return 0;
}