static T_1 F_1 ( void )
{
static char V_1 [ 32 ] ;
static T_1 V_2 ;
sprintf ( V_1 , L_1 ,
( unsigned int ) ( long ) & V_2 ) ;
F_2 ( V_1 ) ;
return V_2 ;
}
static int F_3 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
F_4 ( F_1 () , V_6 ) ;
return F_5 ( V_6 ) ;
}
static int T_2 F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_7 ( & V_8 -> V_4 , L_2 ,
& V_11 , V_12 ) ;
if ( F_8 ( V_10 ) )
return F_9 ( V_10 ) ;
F_10 ( V_8 , V_10 ) ;
return 0 ;
}
static int T_3 F_11 ( struct V_7 * V_8 )
{
return 0 ;
}
