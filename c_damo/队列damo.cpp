#include<iostream>
#include<stdio.h>

using namespace std;
typedef char QUEUEDATATPYE;

struct duilieti {
	QUEUEDATATPYE shuju;
	duilieti* xiayige;
};


class duilie {
	public:
	
		int changdu;

		duilieti* tou;
		duilieti* wei;

		duilie();
		~duilie();
		void kongdui();
		int rudui(QUEUEDATATPYE i);
		int tuidui();
		
		

		
};
		void duilie::kongdui() {
			changdu =0;
			tou=NULL;
			wei=NULL;
			cout << "队列为空" << endl;
		}

		duilie::duilie() {
			cout <<"开始创建"<<endl;
			kongdui();
			cout <<"创建完成  "<<changdu<<endl;
		}

		duilie::~duilie() {
			cout<<"开始关闭"<<endl;
			while(changdu) {
				tuidui();
			}

			cout<<"关闭完成  "<<changdu<<endl;
		}
		
		int duilie::rudui(QUEUEDATATPYE i) {
			
			changdu++;
			
			duilieti* temp=new duilieti;
			if(tou!=NULL) 
			{
				tou->xiayige = temp;
			}
			tou = temp;
			tou->xiayige = NULL;
			tou->shuju = i;//建立新队首
			
			if(changdu==1) {//当新队建立时，赋值队尾 
				wei = temp; 
			}
			
			cout<<"队列长度:"<<changdu<<"//入队数据:"<<tou->shuju<<endl;
			return 0;
		}
		
		int duilie::tuidui() {
			
			if(changdu==0) {
				cout << "cannot tuidui ,长度为0" << endl;
				return 1;
			}
			QUEUEDATATPYE tempshuju;
			tempshuju = wei->shuju;//换数据
			duilieti* temp =wei;
			wei = wei->xiayige ;//换队尾

			delete temp;//删除原尾
			
			changdu--;
			cout<<"队列长度:"<<changdu<<"//出队数据:"<<tempshuju<<endl;
			if(changdu<=0){//判断空队时清空队列信息
				kongdui();	
			}
			
			return tempshuju;
		}




int main() {
	cout << "Hello,World!"<<endl;
	duilie x;
	x.rudui('a');
	x.rudui('s');
		x.rudui('d');
			x.rudui('f');
				x.rudui('g');
	x.tuidui();
	
	return 0;
}
