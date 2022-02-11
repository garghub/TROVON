int F_1 ( int V_1 , int V_2 )
{
struct V_3 V_4 ;
struct V_3 * V_5 = & V_4 ;
V_5 -> V_6 . V_7 . V_8 = V_2 ;
return F_2 ( V_1 , 0 , ( V_9 ) V_5 , sizeof( * V_5 ) ,
V_10 ) ;
}
int F_3 ( int V_1 , int V_2 )
{
struct V_11 V_4 ;
struct V_11 * V_5 = & V_4 ;
V_5 -> V_6 . V_7 . V_8 = V_2 ;
return F_2 ( V_1 , 0 , ( V_9 ) V_5 , sizeof( * V_5 ) ,
V_12 ) ;
}
int F_4 ( int V_1 , T_1 * V_13 )
{
int V_14 ;
struct V_15 V_4 ;
struct V_15 * V_5 = & V_4 ;
V_14 =
F_5 ( V_1 , 0 , ( V_9 ) V_5 , sizeof( * V_5 ) ,
V_16 ) ;
* V_13 = V_5 -> V_13 ;
return V_14 ;
}
int F_6 ( int V_1 , unsigned long V_17 , unsigned long V_18 )
{
struct V_19 V_4 ;
struct V_19 * V_5 = & V_4 ;
V_5 -> V_17 = V_17 ;
V_5 -> V_18 = V_18 ;
return F_2 ( V_1 , 0 , ( V_9 ) V_5 , sizeof( * V_5 ) ,
V_20 ) ;
}
