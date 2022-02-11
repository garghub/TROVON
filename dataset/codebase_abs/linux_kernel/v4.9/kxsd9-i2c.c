static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static const struct V_5 V_6 = {
. V_7 = 8 ,
. V_8 = 8 ,
. V_9 = 0x0e ,
} ;
struct V_10 * V_10 ;
V_10 = F_2 ( V_2 , & V_6 ) ;
if ( F_3 ( V_10 ) ) {
F_4 ( & V_2 -> V_11 , L_1 ,
( int ) F_5 ( V_10 ) ) ;
return F_5 ( V_10 ) ;
}
return F_6 ( & V_2 -> V_11 ,
V_10 ,
V_2 -> V_12 ) ;
}
static int F_7 ( struct V_1 * V_13 )
{
return F_8 ( & V_13 -> V_11 ) ;
}
