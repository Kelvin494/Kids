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
			cout << "����Ϊ��" << endl;
		}

		duilie::duilie() {
			cout <<"��ʼ����"<<endl;
			kongdui();
			cout <<"�������  "<<changdu<<endl;
		}

		duilie::~duilie() {
			cout<<"��ʼ�ر�"<<endl;
			while(changdu) {
				tuidui();
			}

			cout<<"�ر����  "<<changdu<<endl;
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
			tou->shuju = i;//�����¶���
			
			if(changdu==1) {//���¶ӽ���ʱ����ֵ��β 
				wei = temp; 
			}
			
			cout<<"���г���:"<<changdu<<"//�������:"<<tou->shuju<<endl;
			return 0;
		}
		
		int duilie::tuidui() {
			
			if(changdu==0) {
				cout << "cannot tuidui ,����Ϊ0" << endl;
				return 1;
			}
			QUEUEDATATPYE tempshuju;
			tempshuju = wei->shuju;//������
			duilieti* temp =wei;
			wei = wei->xiayige ;//����β

			delete temp;//ɾ��ԭβ
			
			changdu--;
			cout<<"���г���:"<<changdu<<"//��������:"<<tempshuju<<endl;
			if(changdu<=0){//�жϿն�ʱ��ն�����Ϣ
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
