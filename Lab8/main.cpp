#include <iostream>
#include <cstring>

static char input[100]; //введённая пользователем строка
static char commands[5][100]; //строка, разбитая по отдельным командам

short input_command (char input[100], char commands[5][100]); //0-add; 1-delete; 2-incorrect input; 3-print; 4-exit

bool isnumber (char* string); //проверяет, дано ли в строке число

struct detail {
    int id;
    char name[100];
    int amount;
    detail* next;
    detail* prev;
};

int main() {
    detail *first, *last;
    first = nullptr;
    puts("To add an item, type:\n"
         "Add <id> <Name> <Amount>\n"
         "To delete an existing item, type:\n"
         "Delete <id> <Name> <Amount>\n"
         "To print a list of items, type: Print\n"
         "To exit, type: Exit");
    short input_code = input_command(input, commands);
    while (input_code!=4) { //работает пока не будет получена команда выхода
        switch (input_code) {
        case 0: //add
            detail *item;
            item  = new detail;
            item->id = atoi(commands[1]);
            strcpy(item->name, commands[2]);
            item->amount = atoi(commands[3]);
            item->next=nullptr;
            if (first==nullptr) {first=item; last=item;} //если элементов нет, то создает первый
            else {last->next=item; last=item;} //если элементы есть, то добавляет в конец
            puts("Added");
            break;
        case 1: //delete
            if (first==nullptr) puts("No such item in the list. Try again:"); //если список пустой
            else if (first->id==atoi(commands[1]) and strcmp(first->name, commands[2])==0 and first->amount==atoi(commands[3])) { //если нужно удалить первый
                detail *current_item=first; first=current_item->next; delete current_item; puts("Deleted");
            }
            else if (last->id==atoi(commands[1]) and strcmp(last->name, commands[2])==0 and last->amount==atoi(commands[3])) { //если нужно удалить последний
                detail *current_item=first;
                while (current_item->next!=last) current_item=current_item->next;
                current_item->next=nullptr; delete last; last=current_item; puts("Deleted");
            }
            else { //удалить элемент внутри
                detail *current_item=first; detail *next_item = current_item->next;
                while (next_item!=nullptr and next_item->id==atoi(commands[1]) and strcmp(next_item->name, commands[2])!=0 and next_item->amount==atoi(commands[3])) current_item=current_item->next; next_item=next_item->next;
                if (next_item==nullptr) puts("No such item in the list. Try again:"); //если элемент не был найден, то ошибка
                else { //если найден, то удаляет его
                    current_item->next=next_item->next; delete next_item; puts("Deleted");}
            }
            break;
        case 2: //incorrect input
            puts("Incorrect input. Try again:");
            break;
        case 3: //print
            detail *current_item=first;
            while (current_item!=nullptr) {
                printf("%5d %15s %5d\n", current_item->id, current_item->name, current_item->amount);
                current_item=current_item->next;
            }
            break;
        }
        input_code = input_command(input, commands);
    }
}

bool isnumber (char* string) {
    short len = (short) strlen(string);
    if (len==0) return false;
    for (int i=0; i<len; i++) if (not isdigit(string[i])) return false;
    return true;
}

short input_command (char input[100], char commands[5][100]) {
    for (int i=0; i<5; i++) commands[i][0]='\0'; //костыль, чтобы "очистить" команды
    gets(input);
    char* token = strtok(input, " "); //берёт слово до пробела
    int i=0;
    while (token!=nullptr) {
        strcpy(commands[i], token);
        if (i==4) return 2;
        token = strtok(nullptr, " "); i++; //не знаю, почему nullptr, но оно работает :)
    }
    if (strcmp(commands[0], "Add")==0) {
        if (isnumber(commands[1]) and isnumber(commands[3])) return 0; //проверяет, что команда Add введена проавильно
        else return 2;
    } else if (strcmp(commands[0], "Delete")==0) {
        if (isnumber(commands[1]) and isnumber(commands[3])) return 1; //проверяет, что команда Delete введена проавильно
        else return 2;
    } else if (strcmp(commands[0], "Print")==0) { //проверяет, что команда Print введена проавильно
        if (commands[1][0]=='\0') return 3;
        else return 2;
    } else if (strcmp(commands[0], "Exit")==0) { //проверяет, что команда Exit введена проавильно
        if (commands[1][0]=='\0') return 4;
        else return 2;
    }
    return 2; //Во всех неподходящих случаях возвращает "Incorrect input"
}
