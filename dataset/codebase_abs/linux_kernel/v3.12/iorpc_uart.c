int F_1 ( T_1 * V_1 , int V_2 ,
int V_3 , int V_4 , int V_5 )
{
struct V_6 V_7 ;
struct V_6 * V_8 = & V_7 ;
V_8 -> V_9 . V_10 . V_11 = V_2 ;
V_8 -> V_9 . V_10 . V_12 = V_3 ;
V_8 -> V_9 . V_10 . V_13 = V_4 ;
V_8 -> V_9 . V_10 . V_14 = V_5 ;
return F_2 ( V_1 -> V_15 , 0 , ( V_16 ) V_8 ,
sizeof( * V_8 ) , V_17 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * V_18 )
{
int V_19 ;
struct V_20 V_7 ;
struct V_20 * V_8 = & V_7 ;
V_19 =
F_4 ( V_1 -> V_15 , 0 , ( V_16 ) V_8 , sizeof( * V_8 ) ,
V_21 ) ;
* V_18 = V_8 -> V_18 ;
return V_19 ;
}
int F_5 ( T_1 * V_1 ,
unsigned long V_22 , unsigned long V_23 )
{
struct V_24 V_7 ;
struct V_24 * V_8 = & V_7 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_23 = V_23 ;
return F_2 ( V_1 -> V_15 , 0 , ( V_16 ) V_8 ,
sizeof( * V_8 ) , V_25 ) ;
}
