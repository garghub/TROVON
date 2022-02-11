struct V_1 * T_1 F_1 (
const struct V_2 * V_3 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 -> V_7 ,
. V_8 = V_3 -> V_7 + V_3 -> V_9 - 1 ,
. V_10 = V_11 ,
} , {
. V_6 = V_3 -> V_12 ,
. V_8 = V_3 -> V_12 ,
. V_10 = V_13 ,
} ,
} ;
return F_2 ( L_1 , V_3 -> V_14 ,
V_5 , F_3 ( V_5 ) , NULL , 0 ) ;
}
