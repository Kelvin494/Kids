
.global _start


 _start:
    //1.����SVC��������ģʽ
    mrs r0, cpsr  
    bic r0, r0, #0x1f @����bit4-0
    orr r0, r0, #0x13 @λ��ԭcpsr���ݣ�д��(10011)B
    msr cpsr, r0 @д������

    //2.����sp������оƬ�����������Ҫ��ʼ��DDR��
    ldr sp, =0x80200000
    
    //3.��תC���
    b main
