void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_9 -> type ) {
case V_10 :
F_3 ( V_7 -> V_11 , V_9 -> V_12 ) ;
break;
case V_13 :
F_4 ( V_7 -> V_11 , V_7 -> V_14 -> V_15 ) ;
break;
}
V_4 [ V_16 ] . V_17 = V_18 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_19 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_19 ) ;
}
