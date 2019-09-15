#include<stdio.h>
#define nh 3
#define ns 10
#define nsph 2

void main()
{
	int hospital_preference[nh][ns]={
		{1,2,3,4,5,6,7,8,9,0},
		{0,1,2,3,4,5,6,7,8,9},
		{2,4,6,8,0,1,3,5,7,9}
	};
	int student_preference[ns][nh]={
		{0,1,2},
		{2,1,0},
		{2,0,1},
		{1,0,2},
		{0,2,1},
		{0,1,2},
		{2,1,0},
		{1,0,2},
		{1,0,2},
		{2,1,0}
	};
	int result[ns];//student is mapped with hospital
	int i,j,x,y,z,count=0,s,k,h;
	int student_matched[ns];
	int hospital_matched[nh];
	int seat_index[nh];
	//initializing hospital and students to be unmatched
	for(i=0;i<ns;i++)
	{
		student_matched[i]=0;
		result[i]=245;
	}
	for(i=0;i<nh;i++)
	{
		hospital_matched[i]=0;
		seat_index[i]=0; //seat no to be filled
	}
	//<---initialize student and hospitalpreference list logic---->
	while(count<nh)
	{
		h=0;//h for hospital
		while(hospital_matched[h]!=0)
			h++;
		if (h>=nh)
		{
			printf("all hospital matched but count did not increase");
			return;	
		}
		printf("\n hospital - %d entering loop hospital_matched %d \n",h,hospital_matched[h]);
			
		for(j=0;j<ns;j++)
		{
			s=hospital_preference[h][j];//student
			printf("\n student -%d and hospital-%d student_matched-%d hospital_matched-%d \n",s,h,student_matched[s],hospital_matched[h]);
			if(student_matched[s]==0&&result[s]!=h)
			{
				result[s]=h;
				seat_index[h]++;
				student_matched[s]=1;
				printf("\n student - %d matched to hospital  - %d in loop1\n",s,h);
				if(seat_index[h]==nsph)
				{
					hospital_matched[h]=1;
					count++;
					printf("\n hosptal - %d is matched in loop1 \n",h);
					printf("\n count-%d\n",count);
					break;	
				}						
			}else if(student_matched[s]==1&&result[s]!=h)
			{
				for(k=0;k<nh;k++)
				{
					if(result[s]==245)
					{
						printf("error1");
						return;
					}else if(result[s] == student_preference[s][k])
					{
						x=k;
						printf("\n k=%d s=%d h=%d result[s]=%d x=%d \n",k,s,h,result[s],x);
					}else if(h==student_preference[s][k])
					{
						y=k;
						printf("\n k=%d s=%d h=%d result[s]=%d x=%d y=%d \n",k,s,h,result[s],x,y);
						//if (y==x)
						//{
						//	printf("error2");
						//	return;
						//}
					}
					
				}
				if(y<x)
				{
					if (hospital_matched[result[s]]==1)
					{
						count--;
						printf("\n count-%d\n",count);
					}
					hospital_matched[result[s]]=0;
					seat_index[result[s]]--;
					printf("\n hosptal - %d is unmatched to student - %d in loop2\n ",result[s],s);
					printf("\n seat index of hospital-%d is %d \n",result[s],seat_index[result[s]]);
					result[s]=h;
					student_matched[s]=1;
					seat_index[h]++;
					printf("\n seat index of hospital-%d is %d \n",h,seat_index[h]);						
					if(seat_index[h]==nsph)
					{	
						hospital_matched[h]=1;
						count++;
						printf("\n hosptal - %d is matched in loop2 \n ",h);
						printf("\n count-%d\n",count);
						break;
					}
				}
		
			}
		}		
	}
	for (i=0;i<ns;i++)
	{
		printf(" \n  sutdent-%d is matched to hospital-%d \n",i,result[i]);
	}
}

