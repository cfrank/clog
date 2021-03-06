#include <clog.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        struct logger *log = create_logger("file");

        FILE *f = fopen("log.txt", "w");

        if (f == NULL) {
                LOG_ERROR_LONG(log, "Could not open log.txt for writing");
        }

        set_logging_stream(log, f);

        LOG_ERROR(log, "Logging to file %s", "log.txt");
        LOG_CRITICAL_LONG(log, "This was a critical error");

        fclose(f);
        destroy_logger(log);

        return EXIT_SUCCESS;
}
