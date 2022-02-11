struct V_1 T_1 T_2 * F_1 ( char * V_2 ,
T_3 V_3 , int V_4 , int V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 ,
. V_9 = V_3 + V_10 - 1 ,
. V_11 = V_12 ,
} , {
. V_8 = V_4 ,
. V_9 = V_4 ,
. V_11 = V_13 ,
} , {
. V_8 = V_5 ,
. V_9 = V_5 ,
. V_11 = V_13 ,
} ,
} ;
return F_2 ( & V_14 ,
V_2 , - 1 , V_7 , F_3 ( V_7 ) , NULL , 0 ) ;
}
struct V_1 T_1 T_2 * F_4 ( char * V_2 ,
T_3 V_3 , int V_4 , struct V_15 * V_16 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 ,
. V_9 = V_3 + V_17 - 1 ,
. V_11 = V_12 ,
} , {
. V_8 = V_4 ,
. V_9 = V_4 ,
. V_11 = V_13 ,
} ,
} ;
return F_2 ( & V_14 , V_2 ,
- 1 , V_7 , F_3 ( V_7 ) , V_16 , sizeof( * V_16 ) ) ;
}
