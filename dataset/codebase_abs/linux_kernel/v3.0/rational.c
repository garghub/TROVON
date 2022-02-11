void F_1 (
unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long * V_5 , unsigned long * V_6 )
{
unsigned long V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
V_7 = V_1 ;
V_8 = V_2 ;
V_9 = V_12 = 0 ;
V_11 = V_10 = 1 ;
for (; ; ) {
unsigned long V_13 , V_14 ;
if ( ( V_11 > V_3 ) || ( V_12 > V_4 ) ) {
V_11 = V_9 ;
V_12 = V_10 ;
break;
}
if ( V_8 == 0 )
break;
V_13 = V_8 ;
V_14 = V_7 / V_8 ;
V_8 = V_7 % V_8 ;
V_7 = V_13 ;
V_13 = V_9 + V_14 * V_11 ;
V_9 = V_11 ;
V_11 = V_13 ;
V_13 = V_10 + V_14 * V_12 ;
V_10 = V_12 ;
V_12 = V_13 ;
}
* V_5 = V_11 ;
* V_6 = V_12 ;
}
