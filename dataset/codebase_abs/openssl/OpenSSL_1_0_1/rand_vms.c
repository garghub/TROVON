int F_1 ( void )
{
long V_1 , V_2 [ 2 ] ;
int V_3 = 0 ;
struct
{
short V_4 , V_5 ;
long * V_6 ;
int * V_7 ;
} V_8 [ 32 ] , * V_9 ;
unsigned char V_10 [ 256 ] ;
short V_11 = 0 ;
struct V_12 * V_13 ;
V_13 = V_14 ;
V_9 = V_8 ;
while ( V_13 -> V_4
&& ( V_11 + V_13 -> V_4 <= 256 ) )
{
V_9 -> V_4 = V_13 -> V_4 ;
V_9 -> V_5 = V_13 -> V_5 ;
V_9 -> V_6 = ( long * ) & V_10 [ V_11 ] ;
V_9 -> V_7 = 0 ;
V_11 += V_13 -> V_4 ;
V_13 ++ ;
V_9 ++ ;
}
V_9 -> V_4 = V_9 -> V_5 = 0 ;
V_1 = - 1 ;
while ( ( V_3 = F_2 ( 0 , & V_1 , 0 , V_8 , V_2 , 0 , 0 ) )
!= V_15 )
{
if ( V_3 == V_16 )
{
F_3 ( ( V_17 ) V_10 , V_11 ,
V_11 / 2 ) ;
}
}
F_4 ( V_2 ) ;
F_3 ( ( V_17 ) V_2 , sizeof( V_2 ) , sizeof( V_2 ) / 2 ) ;
return 1 ;
}
