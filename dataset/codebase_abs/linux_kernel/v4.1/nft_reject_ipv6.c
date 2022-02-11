static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = F_3 ( ( V_6 -> V_10 != NULL ) ? V_6 -> V_10 : V_6 -> V_11 ) ;
switch ( V_8 -> type ) {
case V_12 :
F_4 ( V_9 , V_6 -> V_13 , V_8 -> V_14 ,
V_6 -> V_15 -> V_16 ) ;
break;
case V_17 :
F_5 ( V_9 , V_6 -> V_13 , V_6 -> V_15 -> V_16 ) ;
break;
default:
break;
}
V_4 -> V_18 . V_19 = V_20 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_21 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_21 ) ;
}
