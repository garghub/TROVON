struct V_1 T_1 T_2 * F_1 ( void )
{
return F_2 ( & V_2 ,
L_1 , - 1 , NULL , 0 , NULL , 0 ) ;
}
struct V_1 T_1 T_2 * F_3 ( char * V_3 ,
T_3 V_4 , int V_5 , struct V_6 * V_7 )
{
struct V_8 V_9 [] = {
{
. V_10 = V_4 ,
. V_11 = V_4 + V_12 - 1 ,
. V_13 = V_14 ,
} , {
. V_10 = V_5 ,
. V_11 = V_5 ,
. V_13 = V_15 ,
} ,
} ;
return F_2 ( & V_2 , V_3 ,
- 1 , V_9 , F_4 ( V_9 ) , V_7 , sizeof( * V_7 ) ) ;
}
