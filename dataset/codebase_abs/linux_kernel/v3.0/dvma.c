static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
unsigned long V_4 ;
T_1 V_5 ;
V_4 = * ( volatile unsigned long * ) V_1 ;
* ( volatile unsigned long * ) V_1 = V_4 ;
V_5 = F_2 ( F_3 ( V_1 ) , V_6 ) ;
V_3 = F_4 ( V_5 ) ;
if( V_7 [ ( V_2 & 0xff000 ) >> V_8 ] != V_3 ) {
F_5 ( V_2 , V_3 ) ;
V_7 [ ( V_2 & 0xff000 ) >> V_8 ] = V_3 ;
}
return ( V_2 + ( V_1 & ~ V_9 ) ) ;
}
int F_6 ( unsigned long V_1 , unsigned long V_10 ,
int V_11 )
{
unsigned long V_12 ;
unsigned long V_2 ;
V_2 = F_7 ( V_10 ) ;
V_12 = V_2 + V_11 ;
while( V_2 < V_12 ) {
F_1 ( V_1 , V_2 ) ;
V_1 += V_13 ;
V_2 += V_13 ;
}
return 0 ;
}
void F_8 ( void )
{
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
}
