void
F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
while ( V_2 -> V_4 [ V_3 ] && V_2 -> V_5 -- ) {
F_2 ( V_2 -> V_4 [ V_3 ] ) ;
V_3 ++ ;
}
}
int
F_3 ( struct V_6 * V_7 )
{
unsigned long V_8 , V_9 ;
V_8 = ( unsigned long ) V_7 -> V_10 -> V_11 >> V_12 ;
V_9 = ( ( unsigned long ) V_7 -> V_10 -> V_11 + V_7 -> V_10 -> V_13 +
V_14 - 1 ) >> V_12 ;
return V_9 - V_8 ;
}
int
F_4 ( struct V_6 * V_7 , T_1 * V_15 , int * V_16 ,
int V_17 , T_2 V_18 )
{
T_3 V_19 = 0 ;
T_4 V_20 ;
struct V_1 * V_2 ;
* V_15 = ( V_21 T_1 ) V_7 -> V_10 -> V_11 & ( V_14 - 1 ) ;
if ( * V_15 )
V_19 = F_5 ( ( ( T_1 ) V_14 - * V_15 ) ,
V_7 -> V_10 -> V_13 ) ;
V_2 = V_7 -> V_10 -> V_22 ;
V_20 = F_6 ( ( unsigned long ) V_7 -> V_10 -> V_11 ,
V_17 , V_18 , & V_2 -> V_4 [ 0 ] ) ;
if ( V_20 <= 0 )
return V_20 ;
V_2 -> V_5 = V_20 ;
if ( * V_15 ) {
* V_16 = V_19 ;
* V_16 += F_5 ( ( V_7 -> V_10 -> V_13 - * V_16 ) ,
( ( T_1 ) V_20 - 1 ) << V_12 ) ;
} else {
* V_16 = F_5 ( V_7 -> V_10 -> V_13 ,
( T_1 ) V_20 << V_12 ) ;
}
return 0 ;
}
