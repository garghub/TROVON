int F_1 ( T_1 * V_1 ,
T_2 V_2 )
{
struct V_3 V_4 ;
struct V_3 * V_5 = & V_4 ;
V_5 -> V_2 = V_2 ;
return F_2 ( V_1 -> V_6 , 0 , ( V_7 ) V_5 ,
sizeof( * V_5 ) , V_8 ) ;
}
int F_3 ( T_1 * V_1 ,
unsigned int V_9 ,
T_2 * V_2 ,
T_3 * V_10 )
{
int V_11 ;
struct V_12 V_4 ;
struct V_12 * V_5 = & V_4 ;
V_11 =
F_4 ( V_1 -> V_6 , 0 , ( V_7 ) V_5 , sizeof( * V_5 ) ,
( ( ( V_13 ) V_9 << 32 ) |
V_14 ) ) ;
* V_2 = V_5 -> V_2 ;
* V_10 = V_5 -> V_10 ;
return V_11 ;
}
int F_5 ( T_1 * V_1 ,
T_4 * V_15 )
{
int V_11 ;
struct V_16 V_4 ;
struct V_16 * V_5 = & V_4 ;
V_11 =
F_4 ( V_1 -> V_6 , 0 , ( V_7 ) V_5 , sizeof( * V_5 ) ,
V_17 ) ;
* V_15 = V_5 -> V_15 ;
return V_11 ;
}
int F_6 ( T_1 * V_1 ,
unsigned long V_18 , unsigned long V_19 )
{
struct V_20 V_4 ;
struct V_20 * V_5 = & V_4 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_19 = V_19 ;
return F_2 ( V_1 -> V_6 , 0 , ( V_7 ) V_5 ,
sizeof( * V_5 ) ,
V_21 ) ;
}
