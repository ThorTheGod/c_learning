#include<iostream>
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	LNode *next;
}LNode;
void showLinkList(LNode *L){
	
	printf("输出链表：\n");	//从首元结点遍历输出直到尾结点 
	LNode *p = L->next;		//以p指针读值并移动 
	while(p != NULL){
		if(p->next!=NULL) 
			printf("%d->",p->data);	
		else
			printf("%d\n",p->data);	
		p = p->next;
	}
}

bool find(LNode *L,int e){
	LNode *p = L->next;//遍历判断元素存在 
	bool status = false;
	while(p != NULL){
		if(p->data == e){
			status = true;
			break;
		}
		else
		p = p->next;
	}
	return status;
}

void deleteEleByValue(LNode *L,int e){
	printf("正在删除%d!\n",e);
	LNode *p = L->next;	//删除值为e的元素 
	LNode *q = L;
	while(p!=NULL){
		if(p->next->data==e){
			q = p->next;
			p->next = q->next;
			free(q);
			break;
		}
		p = p->next;
	}
}

int getLength(LNode *L){
	LNode *p = L->next;
	int length = 0;
	while(p!=NULL){
		length++;
		p = p->next;
	}
	return length;
}

void insertEle(LNode *L,int posi){
	LNode *p = L;
	LNode *q = (LNode*)malloc(sizeof(LNode));  //分配内存
	printf("请输入元素的值!\n"); 
	scanf("%d",&q->data);
	for(int i=0;i<posi;i++){				   //p指针定位到目标位置
		p = p->next;
	}
	q->next = p->next;				//即使p在最后一个，q的指针域也能赋值，为空 
	p->next = q;
}

int main(){
	struct LNode *L,*p,*q;
	
	L = (LNode*)malloc(sizeof(LNode));//表头结点
	L->next = NULL;
	q = L;
	
	
	printf("在开始操作链表前，请先创建链表：\n");
	int nums = 0;
	printf("请输入要创建的链表元素个数:");
	scanf("%d",&nums);
	for(int i = 0;i<nums;i++){ //创建6个节点并赋值，串连 
		p = (LNode*)malloc(sizeof(LNode));
		printf("请输入第%d个元素的值：",i+1);
		scanf("%d",&p->data);
		q->next = p;  //当前结点串上下一个结点 
		q = p;		//当前结点移动 
	}
	p->next = NULL;
	printf("已自动生成链表。\n");
	
	
	int status = 1;
	int e;
	while(status){
		printf("0.退出链表操作	1.展示链表	2.查找元素	3.删除元素	4.插入元素	5.显示链表长度\n");
		printf("请输入你想要进行的操作的编号：\n");
		scanf("%d",&status);
		if(status==0){
			continue;
		}
		else if(status == 1){
			showLinkList(L);
		}
		else if(status == 2){
			printf("请输入要查询的元素值:");
			scanf("%d",&e);
			if(find(L,e))
				printf("表中存在%d!\n",e);
			else
				printf("表中不存在%d!\n",e);
		}
		else if(status == 3){
			printf("请输入你要删除的元素值:");
			scanf("%d",&e);
			if(find(L,e)){
				deleteEleByValue(L,e);
				printf("删除%d成功！\n",e);
			}
			else
				printf("表中不存在%d!\n",e);
		}
		else if(status == 4){
			int IET = 0; 	//InsertElementTotal
			mark:printf("请输入插入元素的个数:");
			scanf("%d",&IET);
			if(IET<=0){
				printf("个数不合法！\n");
				goto mark;
			}
			else
				while(IET){
				
					printf("请输入链表中需要插入的位置(后插)（默认不可插在表头空值结点前）:");
					int posi = 1;
					scanf("%d",&posi);
					if(posi<=0||posi>getLength(L)){
						printf("位置不合法！");
					}
					else{
						insertEle(L,posi);
					}
					IET--;
				}
		}
		else if(status == 5){
			int len = getLength(L);
		printf("输出长度，当前长度为%d\n",len);
		}
	}
}
