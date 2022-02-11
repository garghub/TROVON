void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = V_4 -> V_7 ;
V_2 -> V_8 = V_4 -> V_8 ;
V_2 -> V_9 = V_4 -> V_9 ;
V_2 -> V_10 = V_4 -> V_10 ;
V_2 -> V_11 = V_4 -> V_11 ;
V_2 -> V_12 = V_4 -> V_12 ;
V_2 -> V_13 = V_4 -> V_13 ;
}
void
F_2 (
const struct V_3 * V_14 ,
unsigned V_15 )
{
F_3 ( V_15 ,
L_1
L_2
L_3
L_4 ,
V_14 -> V_6 , V_14 -> V_7 ,
V_14 -> V_8 , V_14 -> V_11 ,
V_14 -> V_9 , V_14 -> V_12 ,
V_14 -> V_10 , V_14 -> V_13 ) ;
}
void
F_4 (
void * V_16 ,
T_1 V_5 )
{
memset ( V_16 , 0 , V_5 ) ;
}
