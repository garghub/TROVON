static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
switch ( V_8 -> V_11 & V_12 ) {
case V_13 :
return - 1 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_14 )
{
if ( V_14 == 256 )
return 1 ;
if ( V_14 == 0 )
return 1 ;
return 0 ;
}
static int T_2 F_3 ( void )
{
return F_4 ( & V_15 ) ;
}
static void T_3 F_5 ( void )
{
F_6 ( & V_15 ) ;
}
