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

    msgid = msgget(key, 0644 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    msg.msg_type = 1;

    printf("Message queue: ready to send message.\n");
    printf("Write Data:\n");
    fgets(msg.msg_text, 200, stdin);

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    printf("Message queue: Done sending message.\n");

    return 0;
}
