static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
switch ( F_2 ( V_7 -> V_8 ) -> V_9 ) {
case F_3 ( V_10 ) :
return F_4 ( V_2 , V_4 , V_7 ) ;
case F_3 ( V_11 ) :
return F_5 ( V_2 , V_4 , V_7 ) ;
default:
V_4 [ V_12 ] . V_13 = V_14 ;
break;
}
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_15 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_15 ) ;
}
