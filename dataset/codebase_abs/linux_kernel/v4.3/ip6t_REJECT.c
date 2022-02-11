static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( ( V_4 -> V_9 != NULL ) ? V_4 -> V_9 : V_4 -> V_10 ) ;
switch ( V_6 -> V_11 ) {
case V_12 :
F_3 ( V_8 , V_2 , V_13 , V_4 -> V_14 ) ;
break;
case V_15 :
F_3 ( V_8 , V_2 , V_16 , V_4 -> V_14 ) ;
break;
case V_17 :
F_3 ( V_8 , V_2 , V_18 , V_4 -> V_14 ) ;
break;
case V_19 :
F_3 ( V_8 , V_2 , V_20 , V_4 -> V_14 ) ;
break;
case V_21 :
F_3 ( V_8 , V_2 , V_22 , V_4 -> V_14 ) ;
break;
case V_23 :
break;
case V_24 :
F_4 ( V_8 , V_2 , V_4 -> V_14 ) ;
break;
case V_25 :
F_3 ( V_8 , V_2 , V_26 , V_4 -> V_14 ) ;
break;
case V_27 :
F_3 ( V_8 , V_2 , V_28 , V_4 -> V_14 ) ;
break;
}
return V_29 ;
}
static int F_5 ( const struct V_30 * V_4 )
{
const struct V_5 * V_31 = V_4 -> V_7 ;
const struct V_32 * V_33 = V_4 -> V_34 ;
if ( V_31 -> V_11 == V_23 ) {
F_6 ( L_1 ) ;
return - V_35 ;
} else if ( V_31 -> V_11 == V_24 ) {
if ( ! ( V_33 -> V_36 . V_37 & V_38 ) ||
V_33 -> V_36 . V_39 != V_40 ||
( V_33 -> V_36 . V_41 & V_42 ) ) {
F_6 ( L_2 ) ;
return - V_35 ;
}
}
return 0 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_43 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_43 ) ;
}
