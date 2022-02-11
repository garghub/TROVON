static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( ( V_4 -> V_9 != NULL ) ? V_4 -> V_9 : V_4 -> V_10 ) ;
F_3 ( L_1 , V_11 ) ;
switch ( V_6 -> V_12 ) {
case V_13 :
F_4 ( V_8 , V_2 , V_14 , V_4 -> V_15 ) ;
break;
case V_16 :
F_4 ( V_8 , V_2 , V_17 , V_4 -> V_15 ) ;
break;
case V_18 :
F_4 ( V_8 , V_2 , V_19 , V_4 -> V_15 ) ;
break;
case V_20 :
F_4 ( V_8 , V_2 , V_21 , V_4 -> V_15 ) ;
break;
case V_22 :
F_4 ( V_8 , V_2 , V_23 , V_4 -> V_15 ) ;
break;
case V_24 :
break;
case V_25 :
F_5 ( V_8 , V_2 , V_4 -> V_15 ) ;
break;
default:
F_6 ( L_2 , V_6 -> V_12 ) ;
break;
}
return V_26 ;
}
static int F_7 ( const struct V_27 * V_4 )
{
const struct V_5 * V_28 = V_4 -> V_7 ;
const struct V_29 * V_30 = V_4 -> V_31 ;
if ( V_28 -> V_12 == V_24 ) {
F_8 ( L_3 ) ;
return - V_32 ;
} else if ( V_28 -> V_12 == V_25 ) {
if ( V_30 -> V_33 . V_34 != V_35 ||
( V_30 -> V_33 . V_36 & V_37 ) ) {
F_8 ( L_4 ) ;
return - V_32 ;
}
}
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_38 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_38 ) ;
}
