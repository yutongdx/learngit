#include<stdio.h>
#include<time.h>
#define VIP 699085    //须有VIP码才能进行部长注册 
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
	printf("         IMA部员管理系统\n");
	printf("\n");
	printf("          1.部长注册\n");
	printf("          2.部员注册\n");
	printf("          3.登录\n");
	printf("********************************\n");
	
	int com;       //指令 
	int p1=0,p2=0;    //声明人数 
	int date=0;   //输出记录 
	int chance;  //验证密码 
	IMA buzhang[12];
	IMA buyuan[500];
	printf("请输入指令：");
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
	
	long size,a;  //a作转化p类型用 
	size=sizeof(IMA)+3;
	long long vip;
	switch(com)
	{
		case 1:
		    {
		    	chance=0;
		    	printf("请先输入部长注册码：");
		    	scanf("%lld",&vip);
		    	while(vip!=VIP&&chance<3)
		    	{
		    		printf("\a密码输入错误，请重新输入(仅三次机会):");
		    		scanf("%lld",&vip);
				}
				if(chance>=3)
				{
					printf("请重新打开程序！");
					return -1;
				}
			printf("输入正确，请注册！\n\n");
		    printf("********************************\n");
		    printf("提示：部门请选填移动互联网部、游戏部、智能硬件部、产品部、设计部、运营部。\n");
		    printf("********************************\n");
			printf("         部长注册\n");
			printf("请输入你的姓名：");
            scanf("%s",buzhang[p1].name);
            printf("请输入你的性别：");
            scanf("%s",buzhang[p1].sex);
            printf("请输入你的学号：");
            scanf("%lld",&buzhang[p1].id);
            printf("请输入你的部门：");
            scanf("%s",buzhang[p1].bumen);
            printf("请输入你的电话：");
            scanf("%lld",&buzhang[p1].tele);
            printf("请输入你的qq：");
            scanf("%lld",&buzhang[p1].qq);
            printf("请输入密码：");
            scanf("%lld",&buzhang[p1].code);
            printf("注册成功！\n"); 
            
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
		    printf("提示：部门请选填移动互联网部、游戏部、智能硬件部、产品部、设计部、运营部。\n");
		    printf("********************************\n\n");
			printf("         部员注册\n");
			printf("请输入你的姓名：");
            scanf("%s",buyuan[p2].name);
            printf("请输入你的性别：");
            scanf("%s",buyuan[p2].sex);
            printf("请输入你的学号：");
            scanf("%lld",&buyuan[p2].id);
            printf("请输入你的部门：");
            scanf("%s",buyuan[p2].bumen);
            printf("请输入你的电话：");
            scanf("%lld",&buyuan[p2].tele);
            printf("请输入你的qq：");
            scanf("%lld",&buyuan[p2].qq);
            printf("请输入密码：");
            scanf("%lld",&buyuan[p2].code);
            printf("注册成功！\n");
            
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
	
	int copy;   //录入信息 
	
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
	
	printf("         登录提示\n");
	printf("        1.部长登录\n");
	printf("        2.部员登录\n");
	printf("\n");
	printf("*********************************\n");
	printf("请输入指令：");
	scanf("%d",&com);
	printf("\n");
	printf("\n");
    long long pass;
    int validate=0;      //验证密码 
    int flag=1;
    
    switch(com)
    {
        case 1:
        	{
        		break;  //操作太多，在下面进行 
			}
		case 2:
			{
	            printf("         部员登录\n");
	            printf("请输入密码：");
                scanf("%lld",&pass);
                while(validate<=p2&&pass!=buyuan[validate].code)
                    validate++;
                if(validate>p2)
                {
        	        printf("         \a密码错误！\n");
        	        chance=0;
        	        while(chance<3&&flag)
        	        {
        		        printf("请重新输入(只有三次机会)：\n");
        		        scanf("%lld",&pass);
        		        validate=0;
        		        while(validate<=p2&&pass!=buyuan[validate].code)
                            validate++;  
                    
                        if(validate>p2)
                        chance+=1;
                        else
                        flag=0;   //跳出循环 
			        }
			    if(chance>=3)
	            return -1;
		        }
	
	            printf("         登录成功!\n");
	            printf("\n");
	            printf("*********************************\n");
	            printf("         部员信息\n");
	            printf("1.姓名：%s\n",buyuan[validate].name);
	            printf("2.性别：%s\n",buyuan[validate].sex);
	            printf("3.学号：%lld\n",buyuan[validate].id);
	            printf("4.部门：%s\n",buyuan[validate].bumen);
	            printf("5.电话：%lld\n",buyuan[validate].tele);
	            printf("6.QQ：%lld\n",buyuan[validate].qq);
	            return -1;
				break;
			}
	}
	
	printf("         部长登录\n");
	printf("请输入密码：");
    scanf("%lld",&pass);
    while(validate<=p1&&pass!=buzhang[validate].code)
        validate++;
    if(validate>p1)
        {
        	printf("         \a密码错误！\n");
        	chance=0;
        	while(chance<3&&flag)
        	{
        		printf("请重新输入(只有三次机会)：\n");
        		scanf("%lld",&pass);
        		validate=0;
        		while(validate<=p1&&pass!=buzhang[validate].code)
                    validate++;  
                    
                if(validate>p1)
                chance+=1;
                else
                flag=0;   //跳出循环 
			}
			if(chance>=3)
	        return -1;
	        
		}
	
	printf("         登录成功!\n");
	printf("\n");
	
	flag=1;
	while(flag)
	{
		fp=fopen("buzhang.txt","r");  //录入更改后信息 
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
	    printf("         部长管理目录\n");
	    printf("        1.查改部员信息\n");
    	printf("        2.增加部员\n");
	    printf("        3.删除部员\n");
	    printf("        4.查看操作记录\n");
	    printf("        5.关闭程序\n");
	    printf("请输入指令：");
	    scanf("%d",&com);
	    printf("\n");
	
	    time_t now;
        struct tm *tm_now;
        int t[10];
	    int b=0;  //用于输出信息 
	    switch(com)     //部长管理 
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
					    printf("         部长信息\n");
	                    printf("1.姓名：%s\n",buzhang[b].name);
	                    printf("2.性别：%s\n",buzhang[b].sex);
	                    printf("3.学号：%lld\n",buzhang[b].id);
	                    printf("4.部门：%s\n",buzhang[b].bumen);
	                    printf("5.电话：%lld\n",buzhang[b].tele);
	                    printf("6.QQ：%lld\n",buzhang[b].qq);
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
					    printf("         部员信息\n");
	                    printf("1.姓名：%s\n",buyuan[b].name);
	                    printf("2.性别：%s\n",buyuan[b].sex);
	                    printf("3.学号：%lld\n",buyuan[b].id);
	                    printf("4.部门：%s\n",buyuan[b].bumen);
	                    printf("5.电话：%lld\n",buyuan[b].tele);
	                    printf("6.QQ：%lld\n",buyuan[b].qq);
	                    b++;
				    }
				    printf("*********************************\n");
				    printf("1.修改信息   2.部门变动   3.返回管理目录   4.关闭程序\n");
				    printf("请输入指令：");
				    scanf("%d",&com);
				
				    char xm[10];
				    switch(com)    //查改部员信息 
				    {
					    case 1:
						{
							b=0;
							printf("请输入部员姓名：");
							scanf("%s",xm);
							while(strcmp(xm,buyuan[b].name)!=0&&b<p2)   
							b++;
					        if(b>=p2)
					        {
						        printf("\n");
						        printf("        \a不是部员或无此人！\n");
						        break; 
					        }
					        if(strcmp(buyuan[b].bumen,buzhang[validate].bumen)!=0)
					        {
						        printf("\n");
						        printf("        \a部员不从属于你的部门！\n");
						        break;
					        }
					        flag=1;
					        while(flag)
							{
								printf("*********************************\n");
								printf("1.性别     2.学号     3.电话     4.QQ\n");
					        	printf("请选择要更改的信息(输入5时返回管理目录)：");
					        	scanf("%d",&com);
					        	switch(com)
					        	{
					        		case 1:
					        		{
					        			printf("更改性别为：");
					        			scanf("%s",buyuan[b].sex);
					        			break;
									}
								    case 2:
									{
										printf("更改学号为：");
										scanf("%lld",&buyuan[b].id);
										break;
									}
								    case 3:
									{
										printf("更改电话为：");
										scanf("%lld",&buyuan[b].tele);
										break;
									}
								    case 4:
									{
										printf("更改QQ为：");
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
					        printf("修改成功！\n");
					        flag=1;
					        
					    break;
						}
					    case 2:
						{
							b=0;
							printf("请输入部员姓名：");
							scanf("%s",xm);
							while(strcmp(xm,buyuan[b].name)!=0&&b<p2) 
							b++;
					        if(b>=p2)
					        {
						        printf("\n");
						        printf("        \a不是部员或无此人！\n");
						        break; 
					        }
					        if(strcmp(buyuan[b].bumen,buzhang[validate].bumen)!=0)
					        {
						        printf("\n");
						        printf("        \a部员不从属于你的部门！\n");
						        break;
					        }
					        printf("请输入更改的部门：");
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
					        
					        printf("更改成功！\n");
					        break;
						}
						case 3:
							break;
					    case 4:
						    flag=0;
				    }
			        break;
			    }
		    case 2:   //增加部员 
			    {
			        printf("请输入姓名：");
                    scanf("%s",buyuan[p2].name);
                    printf("请输入性别：");
                    scanf("%s",buyuan[p2].sex);
                    printf("请输入学号：");
                    scanf("%lld",&buyuan[p2].id);
                    printf("请输入电话：");
                    scanf("%lld",&buyuan[p2].tele);
                    printf("请输入qq：");
                    scanf("%lld",&buyuan[p2].qq);
                    printf("请输入密码：");
                    scanf("%lld",&buyuan[p2].code);
                    printf("增加成功！\n");
            
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
		    case 3:   //删除部员 
				{
					int change;
					int p;    //过渡p2值 
					char delete[10];
					printf("请输入要删除的部员姓名：");
					scanf("%s",delete);
					b=0;   //用于找到部员 
					while(strcmp(delete,buyuan[b].name)!=0&&b<p2)   b++;
					if(b>=p2)
					{
						printf("\n");
						printf("        \a不是部员或无此人！\n");
						break; 
					}
					if(strcmp(buyuan[b].bumen,buzhang[validate].bumen)!=0)
					{
						printf("\n");
						printf("        \a部员不从属于你的部门！\n");
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
					printf("        删除成功！\n");
					printf("\n");
				    break;
				}
			case 4:   //查看操作记录 
			    {
			    	b=0;
			    	fp=fopen("note.txt","r");
			    	printf("*********************************\n");
			    	if(date==0)
			    	printf("无操作记录！\n");
			    	while(b<date)
			    	{
			    		fscanf(fp,"%d%d%d%d%d%d%d",&t[0],&t[1],&t[2],&t[3],&t[4],&t[5],&t[6]);
			    	    printf("%d-%02d-%02d  %02d:%02d:%02d 进行信息修改！\n",t[0],t[1],t[2],t[3],t[4],t[5]);
			    	    b++;
					}
			    	fclose(fp);
			    	
				    break;
				}	
			case 5:  //关闭程序 
				flag=0;
	    }
	}
	printf("程序正常关闭！");
	return 0;
}


