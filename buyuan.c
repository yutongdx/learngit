#include<stdio.h>
#include<time.h>
#define VIP 699085    //����VIP����ܽ��в���ע�� 
typedef struct
{
	char name[10];
	char sex[5];
	long long id;
	char bumen[10];
	long long tele;
	long long qq;
	long long code;
	
}IMA;

int main(void)
{
	FILE *fp,*temp;
	printf("\n");
	printf("         IMA��Ա����ϵͳ\n");
	printf("\n");
	printf("          1.����ע��\n");
	printf("          2.��Աע��\n");
	printf("          3.��¼\n");
	printf("********************************\n");
	
	int com;       //ָ�� 
	int p1=0,p2=0;    //�������� 
	int date=0;   //�����¼ 
	int chance;  //��֤���� 
	IMA buzhang[12];
	IMA buyuan[500];
	printf("������ָ�");
	scanf("%d",&com);
	printf("\n");
	
	fp=fopen("buzhang.txt","r");
	fseek(fp,-5L,2);
	fscanf(fp,"%d",&p1);
	fclose(fp);
	
	fp=fopen("buyuan.txt","r");
	fseek(fp,-5L,2);
	fscanf(fp,"%d",&p2);
	fclose(fp);

    fp=fopen("note.txt","r");
	fseek(fp,-5L,2);
	fscanf(fp,"%d",&date);
	fclose(fp);
	
	long size,a;  //a��ת��p������ 
	size=sizeof(IMA)+3;
	long long vip;
	switch(com)
	{
		case 1:
		    {
		    	chance=0;
		    	printf("�������벿��ע���룺");
		    	scanf("%lld",&vip);
		    	while(vip!=VIP&&chance<3)
		    	{
		    		printf("\a���������������������(�����λ���):");
		    		scanf("%lld",&vip);
				}
				if(chance>=3)
				{
					printf("�����´򿪳���");
					return -1;
				}
			printf("������ȷ����ע�ᣡ\n\n");
		    printf("********************************\n");
		    printf("��ʾ��������ѡ���ƶ�������������Ϸ��������Ӳ��������Ʒ������Ʋ�����Ӫ����\n");
		    printf("********************************\n");
			printf("         ����ע��\n");
			printf("���������������");
            scanf("%s",buzhang[p1].name);
            printf("����������Ա�");
            scanf("%s",buzhang[p1].sex);
            printf("���������ѧ�ţ�");
            scanf("%lld",&buzhang[p1].id);
            printf("��������Ĳ��ţ�");
            scanf("%s",buzhang[p1].bumen);
            printf("��������ĵ绰��");
            scanf("%lld",&buzhang[p1].tele);
            printf("���������qq��");
            scanf("%lld",&buzhang[p1].qq);
            printf("���������룺");
            scanf("%lld",&buzhang[p1].code);
            printf("ע��ɹ���\n"); 
            
            a=p1;
            fp=fopen("buzhang.txt","a");
            fseek(fp,-a*size,0);
            fprintf(fp,"%s\n",buzhang[p1].name);
            fprintf(fp,"%s\n",buzhang[p1].sex);
            fprintf(fp,"%lld\n",buzhang[p1].id);
            fprintf(fp,"%s\n",buzhang[p1].bumen);
            fprintf(fp,"%lld\n",buzhang[p1].tele);
            fprintf(fp,"%lld\n",buzhang[p1].qq);
            fprintf(fp,"%lld\n",buzhang[p1].code);
            p1++;
            fprintf(fp,"%d\n",p1);
            fclose(fp);
            
			break;
		    }
		case 2:
			{
			printf("********************************\n");
		    printf("��ʾ��������ѡ���ƶ�������������Ϸ��������Ӳ��������Ʒ������Ʋ�����Ӫ����\n");
		    printf("********************************\n\n");
			printf("         ��Աע��\n");
			printf("���������������");
            scanf("%s",buyuan[p2].name);
            printf("����������Ա�");
            scanf("%s",buyuan[p2].sex);
            printf("���������ѧ�ţ�");
            scanf("%lld",&buyuan[p2].id);
            printf("��������Ĳ��ţ�");
            scanf("%s",buyuan[p2].bumen);
            printf("��������ĵ绰��");
            scanf("%lld",&buyuan[p2].tele);
            printf("���������qq��");
            scanf("%lld",&buyuan[p2].qq);
            printf("���������룺");
            scanf("%lld",&buyuan[p2].code);
            printf("ע��ɹ���\n");
            
            a=p2;
            fp=fopen("buyuan.txt","a");
            fseek(fp,-a*size,0);
            fprintf(fp,"%s\n",buyuan[p2].name);
            fprintf(fp,"%s\n",buyuan[p2].sex);
            fprintf(fp,"%lld\n",buyuan[p2].id);
            fprintf(fp,"%s\n",buyuan[p2].bumen);
            fprintf(fp,"%lld\n",buyuan[p2].tele);
            fprintf(fp,"%lld\n",buyuan[p2].qq);
            fprintf(fp,"%lld\n",buyuan[p2].code);
            p2++;
            fprintf(fp,"%d\n",p2);
            fclose(fp);
            
			break;
			}
		case 3:
			{
				break;
			}
	}
	printf("\n");
	
	int copy;   //¼����Ϣ 
	
	fp=fopen("buzhang.txt","r");
	for(copy=0;copy<p1;copy++)
	{
		fscanf(fp,"%s%s%lld%s%lld%lld%lld",buzhang[copy].name,buzhang[copy].sex,&buzhang[copy].id,buzhang[copy].bumen,&buzhang[copy].tele,&buzhang[copy].qq,&buzhang[copy].code);
		fseek(fp,5L,1);
	}
	fclose(fp);
	
	fp=fopen("buyuan.txt","r");
	for(copy=0;copy<p2;copy++)
	{
		fscanf(fp,"%s%s%lld%s%lld%lld%lld",buyuan[copy].name,buyuan[copy].sex,&buyuan[copy].id,buyuan[copy].bumen,&buyuan[copy].tele,&buyuan[copy].qq,&buyuan[copy].code);
		fseek(fp,5L,1);
	}
	fclose(fp);
	
	printf("         ��¼��ʾ\n");
	printf("        1.������¼\n");
	printf("        2.��Ա��¼\n");
	printf("\n");
	printf("*********************************\n");
	printf("������ָ�");
	scanf("%d",&com);
	printf("\n");
	printf("\n");
    long long pass;
    int validate=0;      //��֤���� 
    int flag=1;
    
    switch(com)
    {
        case 1:
        	{
        		break;  //����̫�࣬��������� 
			}
		case 2:
			{
	            printf("         ��Ա��¼\n");
	            printf("���������룺");
                scanf("%lld",&pass);
                while(validate<=p2&&pass!=buyuan[validate].code)
                    validate++;
                if(validate>p2)
                {
        	        printf("         \a�������\n");
        	        chance=0;
        	        while(chance<3&&flag)
        	        {
        		        printf("����������(ֻ�����λ���)��\n");
        		        scanf("%lld",&pass);
        		        validate=0;
        		        while(validate<=p2&&pass!=buyuan[validate].code)
                            validate++;  
                    
                        if(validate>p2)
                        chance+=1;
                        else
                        flag=0;   //����ѭ�� 
			        }
			    if(chance>=3)
	            return -1;
		        }
	
	            printf("         ��¼�ɹ�!\n");
	            printf("\n");
	            printf("*********************************\n");
	            printf("         ��Ա��Ϣ\n");
	            printf("1.������%s\n",buyuan[validate].name);
	            printf("2.�Ա�%s\n",buyuan[validate].sex);
	            printf("3.ѧ�ţ�%lld\n",buyuan[validate].id);
	            printf("4.���ţ�%s\n",buyuan[validate].bumen);
	            printf("5.�绰��%lld\n",buyuan[validate].tele);
	            printf("6.QQ��%lld\n",buyuan[validate].qq);
	            return -1;
				break;
			}
	}
	
	printf("         ������¼\n");
	printf("���������룺");
    scanf("%lld",&pass);
    while(validate<=p1&&pass!=buzhang[validate].code)
        validate++;
    if(validate>p1)
        {
        	printf("         \a�������\n");
        	chance=0;
        	while(chance<3&&flag)
        	{
        		printf("����������(ֻ�����λ���)��\n");
        		scanf("%lld",&pass);
        		validate=0;
        		while(validate<=p1&&pass!=buzhang[validate].code)
                    validate++;  
                    
                if(validate>p1)
                chance+=1;
                else
                flag=0;   //����ѭ�� 
			}
			if(chance>=3)
	        return -1;
	        
		}
	
	printf("         ��¼�ɹ�!\n");
	printf("\n");
	
	flag=1;
	while(flag)
	{
		fp=fopen("buzhang.txt","r");  //¼����ĺ���Ϣ 
	    for(copy=0;copy<p1;copy++)
	    {
		    fscanf(fp,"%s%s%lld%s%lld%lld%lld",buzhang[copy].name,buzhang[copy].sex,&buzhang[copy].id,buzhang[copy].bumen,&buzhang[copy].tele,&buzhang[copy].qq,&buzhang[copy].code);
		    fseek(fp,5L,1);
	    }
	    fclose(fp);
	
	    fp=fopen("buyuan.txt","r");
	    for(copy=0;copy<p2;copy++)
	    {
		    fscanf(fp,"%s%s%lld%s%lld%lld%lld",buyuan[copy].name,buyuan[copy].sex,&buyuan[copy].id,buyuan[copy].bumen,&buyuan[copy].tele,&buyuan[copy].qq,&buyuan[copy].code);
		    fseek(fp,5L,1);
	    }
	    fclose(fp);
	    
		printf("*********************************\n");
	    printf("         ��������Ŀ¼\n");
	    printf("        1.��Ĳ�Ա��Ϣ\n");
    	printf("        2.���Ӳ�Ա\n");
	    printf("        3.ɾ����Ա\n");
	    printf("        4.�鿴������¼\n");
	    printf("        5.�رճ���\n");
	    printf("������ָ�");
	    scanf("%d",&com);
	    printf("\n");
	
	    time_t now;
        struct tm *tm_now;
        int t[10];
	    int b=0;  //���������Ϣ 
	    switch(com)     //�������� 
	    {
		    case 1:
			    {
				    while(b<p1)
				    {
					    if(strcmp(buzhang[validate].bumen,buzhang[b].bumen)!=0)
					    {
						    b++;
						    continue;
					    }
					    printf("*********************************\n");
					    printf("         ������Ϣ\n");
	                    printf("1.������%s\n",buzhang[b].name);
	                    printf("2.�Ա�%s\n",buzhang[b].sex);
	                    printf("3.ѧ�ţ�%lld\n",buzhang[b].id);
	                    printf("4.���ţ�%s\n",buzhang[b].bumen);
	                    printf("5.�绰��%lld\n",buzhang[b].tele);
	                    printf("6.QQ��%lld\n",buzhang[b].qq);
	                    b++;
				    }
				    b=0;
                    while(b<p2)
				    {
					    if(strcmp(buzhang[validate].bumen,buyuan[b].bumen)!=0)
					    {
						b++;
						continue;
					    }
					    printf("*********************************\n");
					    printf("         ��Ա��Ϣ\n");
	                    printf("1.������%s\n",buyuan[b].name);
	                    printf("2.�Ա�%s\n",buyuan[b].sex);
	                    printf("3.ѧ�ţ�%lld\n",buyuan[b].id);
	                    printf("4.���ţ�%s\n",buyuan[b].bumen);
	                    printf("5.�绰��%lld\n",buyuan[b].tele);
	                    printf("6.QQ��%lld\n",buyuan[b].qq);
	                    b++;
				    }
				    printf("*********************************\n");
				    printf("1.�޸���Ϣ   2.���ű䶯   3.���ع���Ŀ¼   4.�رճ���\n");
				    printf("������ָ�");
				    scanf("%d",&com);
				
				    char xm[10];
				    switch(com)    //��Ĳ�Ա��Ϣ 
				    {
					    case 1:
						{
							b=0;
							printf("�����벿Ա������");
							scanf("%s",xm);
							while(strcmp(xm,buyuan[b].name)!=0&&b<p2)   
							b++;
					        if(b>=p2)
					        {
						        printf("\n");
						        printf("        \a���ǲ�Ա���޴��ˣ�\n");
						        break; 
					        }
					        if(strcmp(buyuan[b].bumen,buzhang[validate].bumen)!=0)
					        {
						        printf("\n");
						        printf("        \a��Ա����������Ĳ��ţ�\n");
						        break;
					        }
					        flag=1;
					        while(flag)
							{
								printf("*********************************\n");
								printf("1.�Ա�     2.ѧ��     3.�绰     4.QQ\n");
					        	printf("��ѡ��Ҫ���ĵ���Ϣ(����5ʱ���ع���Ŀ¼)��");
					        	scanf("%d",&com);
					        	switch(com)
					        	{
					        		case 1:
					        		{
					        			printf("�����Ա�Ϊ��");
					        			scanf("%s",buyuan[b].sex);
					        			break;
									}
								    case 2:
									{
										printf("����ѧ��Ϊ��");
										scanf("%lld",&buyuan[b].id);
										break;
									}
								    case 3:
									{
										printf("���ĵ绰Ϊ��");
										scanf("%lld",&buyuan[b].tele);
										break;
									}
								    case 4:
									{
										printf("����QQΪ��");
										scanf("%lld",&buyuan[b].qq);
										break;
									}
								    case 5:
								    {
									    flag=0;
									    break;
								    }
							    }
						    }
						    now=time(NULL);
                            tm_now=localtime(&now);
						    fp=fopen("note.txt","a");
						    date++;
					        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",tm_now->tm_year+1900,tm_now->tm_mon+1,tm_now->tm_mday,tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec,date);
					        fclose(fp);
					        
							fp=fopen("buyuan.txt","w");
					        for(b=0;b<p2;b++)
					        fprintf(fp,"%s\n%s\n%lld\n%s\n%lld\n%lld\n%lld\n%d\n",buyuan[b].name,buyuan[b].sex,buyuan[b].id,buyuan[b].bumen,buyuan[b].tele,buyuan[b].qq,buyuan[b].code,b+1);
					        fclose(fp);
					        printf("�޸ĳɹ���\n");
					        flag=1;
					        
					    break;
						}
					    case 2:
						{
							b=0;
							printf("�����벿Ա������");
							scanf("%s",xm);
							while(strcmp(xm,buyuan[b].name)!=0&&b<p2) 
							b++;
					        if(b>=p2)
					        {
						        printf("\n");
						        printf("        \a���ǲ�Ա���޴��ˣ�\n");
						        break; 
					        }
					        if(strcmp(buyuan[b].bumen,buzhang[validate].bumen)!=0)
					        {
						        printf("\n");
						        printf("        \a��Ա����������Ĳ��ţ�\n");
						        break;
					        }
					        printf("��������ĵĲ��ţ�");
					        scanf("%s",buyuan[b].bumen);
					        fp=fopen("buyuan.txt","w");
					        for(b=0;b<p2;b++)
					        fprintf(fp,"%s\n%s\n%lld\n%s\n%lld\n%lld\n%lld\n%d\n",buyuan[b].name,buyuan[b].sex,buyuan[b].id,buyuan[b].bumen,buyuan[b].tele,buyuan[b].qq,buyuan[b].code,b+1);
					        fclose(fp);
					        
					        now=time(NULL);
                            tm_now=localtime(&now);
						    fp=fopen("note.txt","a");
						    date++;
					        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",tm_now->tm_year+1900,tm_now->tm_mon+1,tm_now->tm_mday,tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec,date);
					        fclose(fp);
					        
					        printf("���ĳɹ���\n");
					        break;
						}
						case 3:
							break;
					    case 4:
						    flag=0;
				    }
			        break;
			    }
		    case 2:   //���Ӳ�Ա 
			    {
			        printf("������������");
                    scanf("%s",buyuan[p2].name);
                    printf("�������Ա�");
                    scanf("%s",buyuan[p2].sex);
                    printf("������ѧ�ţ�");
                    scanf("%lld",&buyuan[p2].id);
                    printf("������绰��");
                    scanf("%lld",&buyuan[p2].tele);
                    printf("������qq��");
                    scanf("%lld",&buyuan[p2].qq);
                    printf("���������룺");
                    scanf("%lld",&buyuan[p2].code);
                    printf("���ӳɹ���\n");
            
                    a=p2;
                    fp=fopen("buyuan.txt","a");
                    fseek(fp,-a*size,0);
                    fprintf(fp,"%s\n",buyuan[p2].name);
                    fprintf(fp,"%s\n",buyuan[p2].sex);
                    fprintf(fp,"%lld\n",buyuan[p2].id);
                    fprintf(fp,"%s\n",buzhang[validate].bumen);
                    fprintf(fp,"%lld\n",buyuan[p2].tele);
                    fprintf(fp,"%lld\n",buyuan[p2].qq);
                    fprintf(fp,"%lld\n",buyuan[p2].code);
                    p2++;
                    fprintf(fp,"%d\n",p2);
                    fclose(fp);
                    
                    now=time(NULL);
                    tm_now=localtime(&now);
					fp=fopen("note.txt","a");
					date++;
					fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",tm_now->tm_year+1900,tm_now->tm_mon+1,tm_now->tm_mday,tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec,date);
					fclose(fp);
					
                    break;
			    }
		    case 3:   //ɾ����Ա 
				{
					int change;
					int p;    //����p2ֵ 
					char delete[10];
					printf("������Ҫɾ���Ĳ�Ա������");
					scanf("%s",delete);
					b=0;   //�����ҵ���Ա 
					while(strcmp(delete,buyuan[b].name)!=0&&b<p2)   b++;
					if(b>=p2)
					{
						printf("\n");
						printf("        \a���ǲ�Ա���޴��ˣ�\n");
						break; 
					}
					if(strcmp(buyuan[b].bumen,buzhang[validate].bumen)!=0)
					{
						printf("\n");
						printf("        \a��Ա����������Ĳ��ţ�\n");
						break;
					}
					fp=fopen("buyuan.txt","r");
					temp=fopen("1.txt","w");
					for(change=0;change<p2;change++)
					{
						fscanf(fp,"%s%s%lld%s%lld%lld%lld%d",buyuan[change].name,buyuan[change].sex,&buyuan[change].id,buyuan[change].bumen,&buyuan[change].tele,&buyuan[change].qq,&buyuan[change].code,&p);
						if(change>b) p--;
						if(change!=b)
						fprintf(temp,"%s\n%s\n%lld\n%s\n%lld\n%lld\n%lld\n%d\n",buyuan[change].name,buyuan[change].sex,buyuan[change].id,buyuan[change].bumen,buyuan[change].tele,buyuan[change].qq,buyuan[change].code,p);
					}
					
					p2--;
					fclose(fp);
					fclose(temp);
					remove("buyuan.txt");
					rename("1.txt","buyuan.txt");
					
					now=time(NULL);
                    tm_now=localtime(&now);
					fp=fopen("note.txt","a");
					date++;
					fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",tm_now->tm_year+1900,tm_now->tm_mon+1,tm_now->tm_mday,tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec,date);
					fclose(fp);
					
					printf("\n");
					printf("        ɾ���ɹ���\n");
					printf("\n");
				    break;
				}
			case 4:   //�鿴������¼ 
			    {
			    	b=0;
			    	fp=fopen("note.txt","r");
			    	printf("*********************************\n");
			    	if(date==0)
			    	printf("�޲�����¼��\n");
			    	while(b<date)
			    	{
			    		fscanf(fp,"%d%d%d%d%d%d%d",&t[0],&t[1],&t[2],&t[3],&t[4],&t[5],&t[6]);
			    	    printf("%d-%02d-%02d  %02d:%02d:%02d ������Ϣ�޸ģ�\n",t[0],t[1],t[2],t[3],t[4],t[5]);
			    	    b++;
					}
			    	fclose(fp);
			    	
				    break;
				}	
			case 5:  //�رճ��� 
				flag=0;
	    }
	}
	printf("���������رգ�");
	return 0;
}


