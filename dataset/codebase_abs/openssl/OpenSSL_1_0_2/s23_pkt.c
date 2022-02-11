int F_1 ( T_1 * V_1 )
{
int V_2 , V_3 , V_4 ;
char * V_5 ;
V_5 = V_1 -> V_6 -> V_7 ;
V_4 = V_1 -> V_8 ;
V_3 = V_1 -> V_9 ;
for (; ; ) {
V_1 -> V_10 = V_11 ;
V_2 = F_2 ( V_1 -> V_12 , & ( V_5 [ V_4 ] ) , V_3 ) ;
if ( V_2 <= 0 ) {
V_1 -> V_8 = V_4 ;
V_1 -> V_9 = V_3 ;
return ( V_2 ) ;
}
V_1 -> V_10 = V_13 ;
if ( V_2 == V_3 )
return ( V_4 + V_2 ) ;
V_3 -= V_2 ;
V_4 += V_2 ;
}
}
int F_3 ( T_1 * V_1 , int V_14 )
{
unsigned char * V_15 ;
int V_16 ;
if ( V_1 -> V_17 < ( unsigned int ) V_14 ) {
V_15 = V_1 -> V_18 ;
for (; ; ) {
V_1 -> V_10 = V_19 ;
V_16 = F_4 ( V_1 -> V_20 , ( char * ) & ( V_15 [ V_1 -> V_17 ] ) ,
V_14 - V_1 -> V_17 ) ;
if ( V_16 <= 0 )
return ( V_16 ) ;
V_1 -> V_10 = V_13 ;
V_1 -> V_17 += V_16 ;
if ( V_1 -> V_17 >= ( unsigned int ) V_14 )
return ( V_1 -> V_17 ) ;
}
}
return ( V_14 ) ;
}
