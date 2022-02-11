static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_8 -> type ) {
case V_9 :
F_3 ( V_6 -> V_10 , V_8 -> V_11 , V_6 -> V_12 ) ;
break;
case V_13 :
F_4 ( V_6 -> V_14 , V_6 -> V_10 , V_6 -> V_12 ) ;
break;
default:
break;
}
V_4 -> V_15 . V_16 = V_17 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_18 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_18 ) ;
}
