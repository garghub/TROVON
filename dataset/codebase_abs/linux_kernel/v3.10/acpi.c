int F_1 ( T_1 V_1 ,
T_2 V_2 , T_2 V_3 )
{
struct V_4 V_5 = {
. V_6 = V_7 ,
. V_8 = V_9 ,
. V_10 = {
. V_11 = {
. V_12 = ( V_13 ) V_2 ,
. V_14 = ( V_13 ) V_3 ,
. V_1 = V_1 ,
} ,
} ,
} ;
if ( ( V_2 & 0xffff0000 ) || ( V_3 & 0xffff0000 ) ) {
F_2 ( 1 , L_1
L_2 , \
V_2 , V_3 ) ;
return - 1 ;
}
F_3 ( & V_5 ) ;
return 1 ;
}
