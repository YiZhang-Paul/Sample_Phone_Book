#include "../header/utility.h"
#include "../header/phoneBook.h"

int position;
struct trieNode *tries[3];

static void initialize(void) {

    for(int i = 0; i < FIELDS; i++) {

        tries[i] = createTrieNode();
    }

    load(tries, FILE_NAME);
    position = 0;
}

static char * readLine(void) {

    char *line = malloc(LINE_LENGTH);
    line = fgets(line, LINE_LENGTH, stdin);
    line[strlen(line) - 1] = '\0';

    return line;
}

static void quit(void) {

    printf("<Exiting Program, Press Any Key to Proceed.>");
    getchar();
    exit(0);
}

static void saveAll(void) {

    createFile(FILE_NAME);
    save(tries[2], FILE_NAME);
}

static void getMainOption(void) {

    char *input = readLine();

    if(!isValidOption(input, 1, 5)) {

        printf("<Invalid Option, Please Choose Again.>\n");
        getMainOption();

        free(input);

        return;
    }

    switch(input[0]) {

        case '1' : case '2' : case '3' : case '4' :

            position = input[0] - '0';

            break;

        case '5' :

            quit();

            break;
    }

    free(input);
}

static void getDeleteOption(void) {

    printf("<Enter Phone Number You Wish to Delete:>");
    char *input = readLine();

    if(!isValidInput(input)) {

        printf("<Invalid Phone Number. Please Enter Again.>\n");
        getDeleteOption();

        free(input);

        return;
    }

    struct trieNode *node = retrieveTrieNode(tries[2], input);

    if(node == NULL || isEmpty(node->dataList)) {

        printf("\nRecord not Found.\n\n");
    }
    else {

        printf("\nRecord: ");
        printRecord(node->dataList->data);
        printf(" is Deleted Successfully.\n\n");
        deleteFromTrie(tries[2], input, freeRecord);
    }

    position = 0;
}

void run(void) {

    initialize();

    while(true) {

        switch(position) {

            case 0 :

                printf("<What Would You Like to Do? (Enter Option Number to Proceed)>\n");
                printf("1. Add Record\n");
                printf("2. Delete Record\n");
                printf("3. Update Record\n");
                printf("4. Display Record(s)\n");
                printf("5. Exit Program\n");
                getMainOption();

                break;

            case 1 :



            case 2 :

                getDeleteOption();

                break;

            case 3 :
            case 4 :

                break;
        }
    }
}