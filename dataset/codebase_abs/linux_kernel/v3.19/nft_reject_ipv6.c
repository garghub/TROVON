static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_10 = F_3 ( ( V_7 -> V_11 != NULL ) ? V_7 -> V_11 : V_7 -> V_12 ) ;
switch ( V_9 -> type ) {
case V_13 :
F_4 ( V_10 , V_7 -> V_14 , V_9 -> V_15 ,
V_7 -> V_16 -> V_17 ) ;
break;
case V_18 :
F_5 ( V_10 , V_7 -> V_14 , V_7 -> V_16 -> V_17 ) ;
break;
}
V_4 [ V_19 ] . V_20 = V_21 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_22 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_22 ) ;
}
