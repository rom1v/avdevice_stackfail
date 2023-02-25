#include <pthread.h>
#include <libavdevice/avdevice.h>

static void *run(void *) {
    return NULL;
}

int main(void) {
    //avdevice_version();

    pthread_attr_t attr;
    if (pthread_attr_init(&attr)) {
        fprintf(stderr, "Could not initialize pthread attributes\n");
        return 1;
    }

    if (pthread_attr_setstacksize(&attr, 64 * 1024)) {
        fprintf(stderr, "Could not set stacksize\n");
        return 1;
    }

    pthread_t thread;
    if (pthread_create(&thread, &attr, run, NULL)) {
        fprintf(stderr, "Could not create thread\n");
        sleep(100);
        return 1;
    }

    pthread_join(thread, NULL);

    printf("OK\n");

    return 0;
}
