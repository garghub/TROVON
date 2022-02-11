static unsigned int F_1 ( const struct V_1 * V_2 )
{
#define F_2 ( T_1 ) (_addr & BIT(0))
#define F_3 (1)
return ( V_3 |
( F_2 ( V_2 -> V_4 ) << F_3 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_5 ( V_2 , & V_8 ) ;
if ( F_6 ( V_7 ) ) {
F_7 ( & V_2 -> V_9 , L_1 ) ;
return F_8 ( V_7 ) ;
}
return F_9 ( & V_2 -> V_9 , V_6 -> V_10 , V_2 -> V_11 ,
F_1 ( V_2 ) , V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_9 ) ;
return 0 ;
}
