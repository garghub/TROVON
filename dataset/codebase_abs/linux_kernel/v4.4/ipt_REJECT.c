static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = V_4 -> V_9 ;
switch ( V_6 -> V_10 ) {
case V_11 :
F_2 ( V_2 , V_12 , V_8 ) ;
break;
case V_13 :
F_2 ( V_2 , V_14 , V_8 ) ;
break;
case V_15 :
F_2 ( V_2 , V_16 , V_8 ) ;
break;
case V_17 :
F_2 ( V_2 , V_18 , V_8 ) ;
break;
case V_19 :
F_2 ( V_2 , V_20 , V_8 ) ;
break;
case V_21 :
F_2 ( V_2 , V_22 , V_8 ) ;
break;
case V_23 :
F_2 ( V_2 , V_24 , V_8 ) ;
break;
case V_25 :
F_3 ( V_4 -> V_26 , V_2 , V_8 ) ;
case V_27 :
break;
}
return V_28 ;
}
static int F_4 ( const struct V_29 * V_4 )
{
const struct V_5 * V_30 = V_4 -> V_7 ;
const struct V_31 * V_32 = V_4 -> V_33 ;
if ( V_30 -> V_10 == V_27 ) {
F_5 ( L_1 ) ;
return - V_34 ;
} else if ( V_30 -> V_10 == V_25 ) {
if ( V_32 -> V_35 . V_36 != V_37 ||
( V_32 -> V_35 . V_38 & V_39 ) ) {
F_5 ( L_2 ) ;
return - V_34 ;
}
}
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_40 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_40 ) ;
}
