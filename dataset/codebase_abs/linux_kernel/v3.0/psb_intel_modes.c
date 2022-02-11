bool F_1 ( struct V_1 * V_1 )
{
T_1 V_2 [] = { 0x0 , 0x0 } ;
T_1 V_3 [ 2 ] ;
int V_4 ;
struct V_5 V_6 [] = {
{
. V_7 = 0x50 ,
. V_8 = 0 ,
. V_9 = 1 ,
. V_3 = V_2 ,
} ,
{
. V_7 = 0x50 ,
. V_8 = V_10 ,
. V_9 = 1 ,
. V_3 = V_3 ,
}
} ;
V_4 = F_2 ( & V_1 -> V_11 -> V_12 , V_6 , 2 ) ;
if ( V_4 == 2 )
return true ;
return false ;
}
int F_3 ( struct V_1 * V_1 )
{
struct V_13 * V_13 ;
int V_4 = 0 ;
V_13 =
F_4 ( & V_1 -> V_14 ,
& V_1 -> V_11 -> V_12 ) ;
if ( V_13 ) {
F_5 ( & V_1 ->
V_14 , V_13 ) ;
V_4 = F_6 ( & V_1 -> V_14 , V_13 ) ;
F_7 ( V_13 ) ;
}
return V_4 ;
}
