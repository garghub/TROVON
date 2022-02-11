int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 = { 0 } ;
struct V_8 * V_9 ;
int V_10 ;
V_7 . V_11 = F_2 ( V_12 ,
V_3 ,
0 ) ;
V_10 = F_3 ( V_2 , & V_7 ) ;
if ( V_10 )
return V_10 ;
V_9 = (struct V_8 * ) V_7 . V_13 ;
V_5 -> V_14 = F_4 ( V_9 -> V_14 ) ;
V_5 -> V_15 = F_4 ( V_9 -> V_16 ) ;
V_5 -> V_17 = F_4 ( V_9 -> V_18 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
T_1 V_3 ,
int * V_19 )
{
struct V_6 V_7 = { 0 } ;
struct V_20 * V_9 ;
int V_10 ;
V_7 . V_11 = F_2 ( V_21 ,
V_3 ,
0 ) ;
V_10 = F_3 ( V_2 , & V_7 ) ;
if ( V_10 )
return V_10 ;
V_9 = (struct V_20 * ) V_7 . V_13 ;
* V_19 = F_4 ( V_9 -> V_19 ) ;
return 0 ;
}
