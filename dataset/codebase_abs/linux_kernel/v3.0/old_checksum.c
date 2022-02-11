T_1 F_1 ( const void * V_1 , int V_2 , T_1 V_3 )
{
T_2 V_4 = ( V_5 T_2 ) V_3 ;
const T_3 * V_6 = V_1 ;
const void * V_7 = V_1 + V_2 ;
const void * V_8 = V_7 - ( V_2 % 16 ) ;
#if 0
if((int)buff & 0x3)
printk("unaligned buff %p\n", buff);
__delay(900);
#endif
V_9 ;
while ( V_6 < V_8 ) {
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
V_4 += * V_6 ++ ;
}
V_8 = V_7 - ( V_2 % 2 ) ;
while ( V_6 < V_8 )
V_4 += * V_6 ++ ;
if ( V_7 > V_6 )
V_4 += * ( const V_10 * ) V_6 ;
V_11 ;
return ( V_5 T_1 ) V_4 ;
}
