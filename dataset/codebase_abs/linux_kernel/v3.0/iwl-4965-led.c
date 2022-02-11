static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = {
. V_7 = V_8 ,
. V_9 = sizeof( struct V_3 ) ,
. V_10 = V_4 ,
. V_11 = V_12 ,
. V_13 = NULL ,
} ;
T_1 V_14 ;
V_14 = F_2 ( V_2 , V_15 ) ;
if ( V_14 != ( V_14 & V_16 ) )
F_3 ( V_2 , V_15 , V_14 & V_16 ) ;
return F_4 ( V_2 , & V_6 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_15 , V_17 ) ;
}
