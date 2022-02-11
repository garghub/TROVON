static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_8 -> type ) {
case V_9 :
F_3 ( F_4 ( V_6 ) , V_6 -> V_10 , V_8 -> V_11 ,
F_5 ( V_6 ) ) ;
break;
case V_12 :
F_6 ( F_4 ( V_6 ) , V_6 -> V_10 , F_5 ( V_6 ) ) ;
break;
default:
break;
}
V_4 -> V_13 . V_14 = V_15 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_16 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_16 ) ;
}
