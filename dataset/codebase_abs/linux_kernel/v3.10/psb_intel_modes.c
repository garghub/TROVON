bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [] = { 0x0 , 0x0 } ;
T_1 V_4 [ 2 ] ;
int V_5 ;
struct V_6 V_7 [] = {
{
. V_8 = 0x50 ,
. V_9 = 0 ,
. V_10 = 1 ,
. V_4 = V_3 ,
} ,
{
. V_8 = 0x50 ,
. V_9 = V_11 ,
. V_10 = 1 ,
. V_4 = V_4 ,
}
} ;
V_5 = F_2 ( V_2 , V_7 , 2 ) ;
if ( V_5 == 2 )
return true ;
return false ;
}
int F_3 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_14 * V_14 ;
int V_5 = 0 ;
V_14 = F_4 ( V_13 , V_2 ) ;
if ( V_14 ) {
F_5 ( V_13 , V_14 ) ;
V_5 = F_6 ( V_13 , V_14 ) ;
F_7 ( V_14 ) ;
}
return V_5 ;
}
