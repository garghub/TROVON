int F_1 ( T_1 * V_1 ,
unsigned int V_2 ,
T_2 * V_3 ,
T_3 * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
struct V_6 * V_8 = & V_7 ;
V_5 =
F_2 ( V_1 -> V_9 , 0 , ( V_10 ) V_8 , sizeof( * V_8 ) ,
( ( ( V_11 ) V_2 << 32 ) |
V_12 ) ) ;
* V_3 = V_8 -> V_3 ;
* V_4 = V_8 -> V_4 ;
return V_5 ;
}
int F_3 ( T_1 * V_1 ,
T_4 * V_13 )
{
int V_5 ;
struct V_14 V_7 ;
struct V_14 * V_8 = & V_7 ;
V_5 =
F_2 ( V_1 -> V_9 , 0 , ( V_10 ) V_8 , sizeof( * V_8 ) ,
V_15 ) ;
* V_13 = V_8 -> V_13 ;
return V_5 ;
}
int F_4 ( T_1 * V_1 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_18 V_7 ;
struct V_18 * V_8 = & V_7 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_17 = V_17 ;
return F_5 ( V_1 -> V_9 , 0 , ( V_10 ) V_8 ,
sizeof( * V_8 ) ,
V_19 ) ;
}
