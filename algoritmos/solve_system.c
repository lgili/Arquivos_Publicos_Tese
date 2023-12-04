

void acharxs(int line, int curto1, int value_curto, int rs2, int rs3, int rs4, int rs5, int *x1, int *x2, int *x3, int *x4, int *x5, int *x6, int *x7, int *x8, int *x9)
{
	switch (line)
	{
		case 0: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 1: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 2: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 3: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 4: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 5: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 6: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 7: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 8: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 9: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 10: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 11: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 12: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 13: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 14: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 15: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 16: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 17: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 18: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 19: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 20: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 21: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 22: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 23: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 24: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 25: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 26: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 27: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 28: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 29: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 30: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 31: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 32: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 33: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 34: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 35: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 36: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 37: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 38: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 39: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 40: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 41: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 42: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 43: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 44: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;

		case 45: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 46: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto - rs5;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs5 - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =rs5 - rs3 - rs2 + value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 + rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =rs5 - rs3 + value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + rs5 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 - rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 - rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 - rs4 - rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 47: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 48: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 49: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 50: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 51: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 52: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 53: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 54: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 55: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 56: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs5 - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs5 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs4 - rs5 - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs5;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs5 - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 + rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 + rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 57: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 58: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 59: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 60: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 61: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 62: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 63: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 64: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 65: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 66: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 67: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 68: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 69: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 70: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 71: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 72: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 73: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 74: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 75: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 76: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 77: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 78: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 79: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 80: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;

	default:

		*x1 = 0;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 = 0;
		break;
	}
}

