unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 , V_3 , V_4 = 0 ;
if ( V_1 <= 1 )
return V_1 ;
V_3 = 1UL << ( V_5 - 2 ) ;
while ( V_3 != 0 ) {
V_2 = V_4 + V_3 ;
V_4 >>= 1 ;
if ( V_1 >= V_2 ) {
V_1 -= V_2 ;
V_4 += V_3 ;
}
V_3 >>= 2 ;
}
return V_4 ;
}
