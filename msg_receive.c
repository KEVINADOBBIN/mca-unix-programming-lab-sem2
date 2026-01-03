#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* Message structure */
struct message {
    long msg_type;
    char msg_text[200];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("shmfile", 65);

    msgid = msgget(key, 0644);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Message queue: Ready to receive messages.\n");

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

    printf("Received data: %s", msg.msg_text);
    printf("Message queue: Done receiving messages.\n");

    msgctl(msgid, IPC_RMID, NULL); // Remove message queue

    return 0;
}
