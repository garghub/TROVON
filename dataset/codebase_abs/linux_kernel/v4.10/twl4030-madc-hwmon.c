static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 V_9 = {
. V_10 = 1 << V_7 -> V_11 ,
. V_12 = V_13 ,
. type = V_14 ,
} ;
long V_15 ;
V_15 = F_3 ( & V_9 ) ;
if ( V_15 < 0 )
return V_15 ;
return sprintf ( V_5 , L_1 , V_9 . V_16 [ V_7 -> V_11 ] ) ;
}
static int F_4 ( struct V_17 * V_18 )
{
struct V_1 * V_19 ;
V_19 = F_5 ( & V_18 -> V_2 ,
L_2 , NULL ,
V_20 ) ;
return F_6 ( V_19 ) ;
}
