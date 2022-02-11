struct V_1 * T_1 F_1 ( char * V_2 , int V_3 ,
T_2 V_4 , T_2 V_5 , int V_6 , int V_7 )
{
struct V_8 V_9 [] = {
{
. V_10 = V_4 ,
. V_11 = V_4 + V_5 - 1 ,
. V_12 = V_13 ,
} , {
. V_10 = V_6 ,
. V_11 = V_6 ,
. V_12 = V_14 ,
} , {
. V_10 = V_7 ,
. V_11 = V_7 ,
. V_12 = V_14 ,
} ,
} ;
return F_2 ( & V_15 ,
V_2 , V_3 , V_9 , F_3 ( V_9 ) , NULL , 0 ) ;
}
