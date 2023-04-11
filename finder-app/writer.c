#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename = NULL;
    char *writestr = NULL;

    if(argc != 3)
    {
        syslog(LOG_ERR, "The arguments should be ./writer [writefile] [writestr]");
        return 1;
    }

    filename = argv[1];
    writestr = argv[2];

    fp = fopen(filename, "w");
    if (fp==NULL)
    {
        syslog(LOG_ERR, "fail to open file %s. Reason:%s", filename, strerror(errno));
        return 1;
    }

    fputs(writestr, fp);

    fclose(fp);
    fp = NULL;

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, filename);

    return 0;
}
