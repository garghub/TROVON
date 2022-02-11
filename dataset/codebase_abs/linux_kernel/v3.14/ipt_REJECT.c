static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
switch ( V_6 -> V_8 ) {
case V_9 :
F_2 ( V_2 , V_10 ) ;
break;
case V_11 :
F_2 ( V_2 , V_12 ) ;
break;
case V_13 :
F_2 ( V_2 , V_14 ) ;
break;
case V_15 :
F_2 ( V_2 , V_16 ) ;
break;
case V_17 :
F_2 ( V_2 , V_18 ) ;
break;
case V_19 :
F_2 ( V_2 , V_20 ) ;
break;
case V_21 :
F_2 ( V_2 , V_22 ) ;
break;
case V_23 :
F_3 ( V_2 , V_4 -> V_24 ) ;
case V_25 :
break;
}
return V_26 ;
}
static int F_4 ( const struct V_27 * V_4 )
{
const struct V_5 * V_28 = V_4 -> V_7 ;
const struct V_29 * V_30 = V_4 -> V_31 ;
if ( V_28 -> V_8 == V_25 ) {
F_5 ( L_1 ) ;
return - V_32 ;
} else if ( V_28 -> V_8 == V_23 ) {
if ( V_30 -> V_33 . V_34 != V_35 ||
( V_30 -> V_33 . V_36 & V_37 ) ) {
F_5 ( L_2 ) ;
return - V_32 ;
}
}
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_38 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_38 ) ;
}
