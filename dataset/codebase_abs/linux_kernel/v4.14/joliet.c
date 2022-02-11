static int
F_1 ( unsigned char * V_1 , T_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
T_1 * V_6 , V_7 ;
unsigned char * V_8 ;
V_6 = V_2 ;
V_8 = V_1 ;
while ( ( V_7 = F_2 ( V_6 ) ) && V_3 ) {
int V_9 ;
V_9 = V_5 -> V_10 ( F_3 ( V_7 ) , V_8 , V_11 ) ;
if ( V_9 > 0 )
V_8 += V_9 ;
else
* V_8 ++ = '?' ;
V_6 ++ ;
V_3 -- ;
}
* V_8 = 0 ;
return ( V_8 - V_1 ) ;
}
int
F_4 ( struct V_12 * V_13 , unsigned char * V_14 , struct V_15 * V_15 )
{
unsigned char V_16 ;
struct V_4 * V_5 ;
unsigned char V_3 = 0 ;
V_16 = F_5 ( V_15 -> V_17 ) -> V_18 ;
V_5 = F_5 ( V_15 -> V_17 ) -> V_19 ;
if ( V_16 ) {
V_3 = F_6 ( ( const V_20 * ) V_13 -> V_21 ,
V_13 -> V_22 [ 0 ] >> 1 , V_23 ,
V_14 , V_24 ) ;
} else {
V_3 = F_1 ( V_14 , ( T_1 * ) V_13 -> V_21 ,
V_13 -> V_22 [ 0 ] >> 1 , V_5 ) ;
}
if ( ( V_3 > 2 ) && ( V_14 [ V_3 - 2 ] == ';' ) && ( V_14 [ V_3 - 1 ] == '1' ) )
V_3 -= 2 ;
while ( V_3 >= 2 && ( V_14 [ V_3 - 1 ] == '.' ) )
V_3 -- ;
return V_3 ;
}
