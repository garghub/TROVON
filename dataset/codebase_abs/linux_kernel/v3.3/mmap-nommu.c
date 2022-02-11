static unsigned long F_1 ( struct V_1 * V_1 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
struct V_6 * V_6 = V_1 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_11 -> V_12 ;
unsigned long V_13 , V_14 , V_15 , V_16 ;
int V_17 ;
if ( ! V_10 )
return ( unsigned long ) - V_18 ;
V_16 = ( V_3 + V_19 - 1 ) >> V_20 ;
V_13 = F_2 ( V_6 ) ;
V_14 = V_4 << V_20 ;
V_15 = ( V_13 + V_19 - 1 ) >> V_20 ;
if ( ( V_4 >= V_15 ) || ( V_15 - V_4 < V_16 ) )
return ( unsigned long ) - V_21 ;
if ( V_2 != 0 )
return ( unsigned long ) - V_21 ;
if ( V_3 > V_10 -> V_22 || V_4 >= ( V_10 -> V_22 >> V_20 ) )
return ( unsigned long ) - V_21 ;
V_14 += F_3 ( V_6 ) -> V_23 ;
if ( V_14 > V_10 -> V_22 - V_3 )
return ( unsigned long ) - V_21 ;
V_17 = F_4 ( V_10 , V_3 , V_14 , V_5 ) ;
if ( V_17 == - V_24 )
V_17 = - V_18 ;
return ( unsigned long ) V_17 ;
}
static int F_5 ( struct V_1 * V_1 , struct V_25 * V_26 )
{
return V_26 -> V_27 & ( V_28 | V_29 ) ? 0 : - V_18 ;
}
