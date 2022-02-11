struct V_1 * T_1 F_1 (
const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 -> V_9 ,
. V_10 = V_3 -> V_9 + V_3 -> V_11 - 1 ,
. V_12 = V_13 ,
} , {
. V_8 = V_3 -> V_14 ,
. V_10 = V_3 -> V_14 ,
. V_12 = V_15 ,
} ,
} ;
return F_2 ( L_1 , V_3 -> V_16 ,
V_7 , F_3 ( V_7 ) , V_5 , sizeof( * V_5 ) ) ;
}
