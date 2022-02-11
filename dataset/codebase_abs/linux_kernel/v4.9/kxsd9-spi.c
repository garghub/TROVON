static int F_1 ( struct V_1 * V_2 )
{
static const struct V_3 V_4 = {
. V_5 = 8 ,
. V_6 = 8 ,
. V_7 = 0x0e ,
} ;
struct V_8 * V_8 ;
V_2 -> V_9 = V_10 ;
V_8 = F_2 ( V_2 , & V_4 ) ;
if ( F_3 ( V_8 ) ) {
F_4 ( & V_2 -> V_11 , L_1 ,
V_12 , F_5 ( V_8 ) ) ;
return F_5 ( V_8 ) ;
}
return F_6 ( & V_2 -> V_11 ,
V_8 ,
F_7 ( V_2 ) -> V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( & V_2 -> V_11 ) ;
}
