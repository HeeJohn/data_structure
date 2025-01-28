#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

// 단일 연결 리스트 :

/* ADT : Operations that data structure should have.
-- > list
    1. append
    2. remove
    3. get at
    4. insert after

    - node : create & destroy

*/


// Implementation : Singly Linked list


/*
 *  - 장점 :
 *      1. 새로운 노드의 추가, 삽입, 삭제가 쉽고 빠름, 반면 배열은 새로운 요소를 삽입하거나 기존 요소를 제거하기가 어려움 (재배치가 요구됨)
 *      2. 현재 노드의 다음 노드를 얻어오는 연산에 대해서는 비용이 발생하지 않음 (탐색 중 유일하게 비용이 없는 것 : 이전 노드에서 다음 노드)*
 *
 *  - 단점 :
 *      1. 다음 노드를 가리크는 포인터 때문에 각 노드마다 추가적인 메모리(32비트 시스템에서는 4바이트, 64비트 시스템에서는 8바이트)가 필요함.
 *      2. 특정 위치에 있는 노드에 접근하기 위한 비용이 크고, 접근하기까지 시간도 많이 소요됨.
 *          (가령 n번째 위치에 있는 노드에 접근하려면 n회의 노드 탐색 루프를 실행해야 해당 위치에 접근 가능)
 *          (반면, 배열은 상수시간 접근 가능, 배열에서의 노드 위치는 '첨자 x 노드 크기' 로 계산)
 *
 *  - 결론 : 노드의 추가, 삽입, 삭제 연산은 빠르지만
 *  특정 위치에 있는 노드에 접근하는 연산은 느린 것.
 *
 *  ** 삽입, 삭제 연산은 이전 노드를 찾는 찾기 연산이 있으므로, 느릴 수 있음.
 */


// 자료구조

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
    struct tagNode *  next;
}Node;


int init_sll();

// 함수 선언

// 노드 생성 & 소멸
Node* SLL_CreateNode(ElementType data) ;
void SLL_DestroyNode(Node* oldNode) ;


// 연산
void SLL_AppendNode(Node** head, Node*newNode);
void SLL_PrintNodes(Node* head);
Node * SLL_GetNodeAt(Node* head, int location);
void SLL_RemoveNode(Node**head, Node * targetNode);
int SLL_GetNodesCount(Node* head);
void SLL_InsertBefore(Node**head, Node*current, Node* newHead);
void SLL_DestroyAllNodes(Node ** list);


#endif
