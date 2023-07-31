// ListEntryDlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// testptr.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
//#include <windows.h>

#include <stdio.h>
#include<malloc.h>

typedef struct _LIST_ENTRY {
  struct _LIST_ENTRY  *Flink;
  struct _LIST_ENTRY  *Blink;
} LIST_ENTRY, *PLIST_ENTRY;

void InitializeListHead(
     PLIST_ENTRY ListHead
    )
{
    ListHead->Flink = ListHead->Blink = ListHead;
}

//bool
//IsListEmpty(
//     const LIST_ENTRY * ListHead
//    )
//{
//    return (bool)(ListHead->Flink == ListHead);
//}

//bool
//RemoveEntryList(
//     PLIST_ENTRY Entry
//    )
//{
//    PLIST_ENTRY Blink;
//    PLIST_ENTRY Flink;
//
//    Flink = Entry->Flink;
//    Blink = Entry->Blink;
//    Blink->Flink = Flink;
//    Flink->Blink = Blink;
//    return (bool)(Flink == Blink);
//}


//PLIST_ENTRY RemoveHeadList(
//     PLIST_ENTRY ListHead
//    )
//{
//    PLIST_ENTRY Flink;
//    PLIST_ENTRY Entry;
//
//    Entry = ListHead->Flink;
//    Flink = Entry->Flink;
//    ListHead->Flink = Flink;
//    Flink->Blink = ListHead;
//    return Entry;
//}




//PLIST_ENTRY RemoveTailList(
//     PLIST_ENTRY ListHead
//    )
//{
//    PLIST_ENTRY Blink;
//    PLIST_ENTRY Entry;
//
//    Entry = ListHead->Blink;
//    Blink = Entry->Blink;
//    ListHead->Blink = Blink;
//    Blink->Flink = ListHead;
//    return Entry;
//}


//void
//InsertTailList(
//    PLIST_ENTRY ListHead,
//    PLIST_ENTRY Entry
//    )
//{
//    PLIST_ENTRY Blink;
//
//    Blink = ListHead->Blink;
//    Entry->Flink = ListHead;
//    Entry->Blink = Blink;
//    Blink->Flink = Entry;
//    ListHead->Blink = Entry;
//}


void InsertHeadList(
    PLIST_ENTRY ListHead,
    PLIST_ENTRY Entry
    )
{
    PLIST_ENTRY Flink;

    Flink = ListHead->Flink;
    Entry->Flink = Flink;
    Entry->Blink = ListHead;
    Flink->Blink = Entry;
    ListHead->Flink = Entry;
}

//void AppendTailList(
//     PLIST_ENTRY ListHead,
//     PLIST_ENTRY ListToAppend
//    )
//{
//    PLIST_ENTRY ListEnd = ListHead->Blink;
//
//    ListHead->Blink->Flink = ListToAppend;
//    ListHead->Blink = ListToAppend->Blink;
//    ListToAppend->Blink->Flink = ListHead;
//    ListToAppend->Blink = ListEnd;
//}


#define CONTAINING_RECORD(address, type, field) ((type *)( \
                                                  (char*)(address) - \
                                                  (unsigned long)(&((type *)0)->field)))

struct MY_TEST_LIST
{
	int a;
	int b;
	char c;
	LIST_ENTRY list_entry;
	float d;
};

PLIST_ENTRY MtListHead;

int main(void)
{
	
	MtListHead = (PLIST_ENTRY)malloc(sizeof(LIST_ENTRY));
	InitializeListHead(MtListHead);
	
	MY_TEST_LIST * myNewNode = (MY_TEST_LIST *)malloc(sizeof(MY_TEST_LIST));

	myNewNode->a = 100;
	myNewNode->b = 1000;
	myNewNode->c = 10;
	myNewNode->d = 1.0;

	//mtl = myNewNode;

	InsertHeadList( MtListHead, &(myNewNode->list_entry) );
	/////////////////////////////////////////////////////////////////////////////////////////

	myNewNode = (MY_TEST_LIST *)malloc(sizeof(MY_TEST_LIST));

	myNewNode->a = 200;
	myNewNode->b = 2000;
	myNewNode->c = 20;
	myNewNode->d = 2.0;
	
	InsertHeadList( MtListHead, &myNewNode->list_entry);
	////////////////////////////////////////////////////////////////////////////////
	
	myNewNode = (MY_TEST_LIST *)malloc(sizeof(MY_TEST_LIST));

	myNewNode->a = 300;
	myNewNode->b = 3000;
	myNewNode->c = 30;
	myNewNode->d = 3.0;

	InsertHeadList( MtListHead, &myNewNode->list_entry);
	//////////////////////////////////////////////////////////////////////////////////

	PLIST_ENTRY templist = 0;
	
	templist = MtListHead;
	while(MtListHead!=templist->Flink)
	{	
		templist = templist->Flink;
		int a =  CONTAINING_RECORD( templist, MY_TEST_LIST, list_entry )->a;
		printf( "a = %d \n", a );
	}



	return 0;
}
