#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stringnode.h"
#include "loggingstringnode.h"

struct LoggingStringNode_class LoggingStringNode_class_table = {
        &StringNode_class_table,  /* super */
        StringNode_compareTo,
        StringNode_printNode,
        LoggingNode_insert,
        Node_print,
        Node_delete
};

/**
 * insert
 */
void LoggingNode_insert(void* thisv, void* nodev) {
    struct StringNode* node = nodev;
    printf("insert %s\n",node->s);
    StringNode_class_table.insert(thisv, nodev);
}

void* new_LoggingStringNode(char* s) {
    struct LoggingStringNode* obj = malloc(sizeof(struct LoggingStringNode));
    obj->class = &LoggingStringNode_class_table;
    StringNode_ctor(obj, s);
    return obj;
}