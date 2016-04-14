#include<stdio.h>
#include <iostream>
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode
{
    int num;
    ListNode* next;
   
};
//找到倒数第k个数 从倒数第一个数开始计数
ListNode * FindKthToTail(ListNode* pListHead , unsigned int k)
{
    if (pListHead==NULL ||k==0) {
        return NULL;
    }
    
    ListNode *pre;
    ListNode *next;
    pre=pListHead;
    next=pListHead;
    //move to k-1
    for(int i=0;i<k-1;++i)
    {
        if(pre->next!=NULL)
        {
        pre=pre->next;
        }
        else
        {
            return NULL;
        }
        
        
    }
    while(pre->next!=NULL)
    {
        pre=pre->next;
        next=next->next;
    }
    return next;
}
//创建节点并插入到链表尾端
void createNode(ListNode * & head,int num)
{
    if(head==NULL)
    {
        head =new ListNode;
        head->next=NULL;
        head->num=num;
    }
    else
    {
        ListNode *p=head;
        while (p->next!=NULL) {
            p=p->next;
        }
        p->next=new ListNode;
        p->next->next=NULL;
        p->next->num=num;
        
    }
}
//在制定位置插入节点 从1计数
ListNode* insertNode(ListNode *head,int position,int data) //position从1开始计数
{
    
//如果链表是一个空表，返回
    if(NULL==head&& position!=1)
    {
        cout<<"the list is empty and position is not 1"<<endl;
        return NULL;
    }
    
    ListNode *p=head;
    ListNode *temp=new ListNode;
    temp->next=NULL;
    temp->num=data;
    //在表头插入结点
    if(position==1)
    {
        if(NULL==head)
        {
            return temp;
        }
        else
        {
            temp->next=head;
            return temp;
        }
    }
    else
    {
        //找到插入结点前一个的位置
        int count=1;
        while(count<position-1 && p->next!=NULL)
        {
            count++;
            p=p->next;
        }
        //没到位置但是已经没有结点了
        if(p->next==NULL && count<position-1)
        {
            cout<<"there is no position "<<position<<endl;
            return head;
        }
        //在尾结点插入
        else if(p->next==NULL && count==position-1)
        {
            p->next=temp;
            return head;
        }
        //正常插入
        else
        {
            ListNode *q=p->next;
            p->next=temp;
            temp->next=q;
            return head;
        }
    }
}
//删除制定位置节点 从1计数
ListNode * deleteNode(ListNode *head, int position)
{
    //如果链表是空链表
    if(NULL==head&& position!=1)
    {
        cout<<"the list is empty and position is not 1"<<endl;
        return NULL;
    }
    ListNode *p=head;
    //如果删除表头元素
    if(position==1)
    {
        //表头没有元素
        if(NULL==head)
        {
            return NULL;
        }
        else
        {
            ListNode * del=head;
            head=head->next;
            delete del;
            return head;
        }
    }
    else
    {
        //找到插入结点前一个的位置
        int count=1;
        while(count<position-1 && p->next!=NULL)
        {
            count++;
            p=p->next;
        }
        //没到位置但是已经没有结点了
        if(p->next==NULL && count<position-1)
        {
            cout<<"there is no position "<<position<<endl;
            return head;
        }
        //在尾结点删除
        else if(p->next==NULL && count==position-1)
        {
            p->next=NULL;
            return head;
        }
        //正常删除
        else
        {
            ListNode *del=p->next;
            ListNode *q=p->next->next;
            p->next=q;
            delete del;
            return head;
        }

        
    }

}
//反转链表
ListNode *reverseList(ListNode *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    ListNode *pre=head->next;
    ListNode *thisOne=head;
    ListNode *bott=head;
    while (thisOne->next!=NULL) {
        //翻转头结点
        if(thisOne==head)
        {
            thisOne->next=NULL;
            bott=thisOne;
            thisOne=pre;
            pre=pre->next;
        }
        //中间正常翻转部分
        
        else
        {
        thisOne->next=bott;
        bott=thisOne;
        thisOne=pre;
        pre=pre->next;
        }
        
    }
    //翻转尾节点
    thisOne->next=bott;
    return thisOne;

}
//打印链表
void printList(ListNode *head)
{
    ListNode *temp;
    temp=head;
    while (temp!=NULL) {
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    // build a list
    ListNode * head=NULL;
    for (int i=0; i<6; ++i) {
        createNode(head, i);//from butt
    }
    //insert list from position 1
    head=insertNode(head, 7, 6);
    printList(head);
    head=deleteNode(head, 7);
    printList(head);
    //cout<<FindKthToTail(head, 2)->num<<endl;
    head=reverseList(head);
    printList(head);
}