/*
 *  Info:       Singally Linked List for integer datatype storage.
 *  Created:    02.July.2013
 *  Modified:   06.July.2013
 *  Author:     James Muldoon
 */

#ifndef SLL_H
#define SLL_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node SLL;

/* Creates a new node, assigns the data value to the parameter num, and returns it.
 * Parameter description as defined below:
 *      <int>num: value that is to be stored as the data in the node to be appended.
 * Return type is SLL *.
 */
SLL *CreateNode(long long int num);

/* Append a new node to the end/tail of the linked list.
 * Parameter description as defined below:
 *		<SLL>*head:	The root/head node of the linked list.
 *      <int>num: value that is to be stored as the data in the node to be appended.
 * Return type is SLL * and is the head of the list.
 */
SLL *AppendTail(SLL *head, long long int num);

/* Append a new node to the root/head of the linked list.
 * Parameter description as defined below:
 *		<SLL>*head:	The root/head node of the linked list.
 *      <int>num:	value that is to be stored as the data in the node to be appended.
 * Return type is SLL * and is the head of the list.
 */
SLL *AppendHead(SLL *head, long long int num);

/* Append a new node, in order, based on the value of the parameter num that is passed; into the linked list.
 * Parameter description as defined below:
 *		<SLL>*head:	The root/head node of the linked list.
 *      <int>num: value that is to be stored as the data in the node to be appended.
 * Return type is SLL * and is the head of the list.
 */
SLL *InsertOrdered(SLL *head, long long int num);

/* Delete a node from the linked list that has the parameter num. Will delete the first occurance of this value.
 * Parameter description as defined below:
 *		<SLL>*head:	The root/head node of the linked list.
 *      <int>num: value that is stored as the data in the node to be deleted.
 * Return type is SLL * and is the head of the list.
 */
SLL *Delete(SLL *head, long long int num);

/* Traverses every node in the linked list starting from the SLL * parameter and compares it with the previous node,
 * thuse finding the maximal data value stored in the entire linked list.
 *		<SLL>*head:	The root/head node of the linked list.
 * Return type is int, the max value that is found in the linked list.
 */
int MaxValue(SLL *head);

/* Prints out the data of the linked list beginning at the root/head.
 *		<SLL>*head:	The root/head node of the linked list.
 * Return type is void.
 */
void Display(SLL *head);

/* Counts every node in the linked list starting from the SLL * parameter.
 *		<SLL>*head:	The root/head node of the linked list.
 * Return type is int.
 */
int Count(SLL *head);

#endif //SLL_H
