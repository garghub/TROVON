static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = F_2 ( V_4 ) ;
switch ( V_6 -> V_9 ) {
case V_10 :
F_3 ( V_2 , V_11 , V_8 ) ;
break;
case V_12 :
F_3 ( V_2 , V_13 , V_8 ) ;
break;
case V_14 :
F_3 ( V_2 , V_15 , V_8 ) ;
break;
case V_16 :
F_3 ( V_2 , V_17 , V_8 ) ;
break;
case V_18 :
F_3 ( V_2 , V_19 , V_8 ) ;
break;
case V_20 :
F_3 ( V_2 , V_21 , V_8 ) ;
break;
case V_22 :
F_3 ( V_2 , V_23 , V_8 ) ;
break;
case V_24 :
F_4 ( F_5 ( V_4 ) , V_2 , V_8 ) ;
case V_25 :
break;
}
return V_26 ;
}
static int F_6 ( const struct V_27 * V_4 )
{
const struct V_5 * V_28 = V_4 -> V_7 ;
const struct V_29 * V_30 = V_4 -> V_31 ;
if ( V_28 -> V_9 == V_25 ) {
F_7 ( L_1 ) ;
return - V_32 ;
} else if ( V_28 -> V_9 == V_24 ) {
if ( V_30 -> V_33 . V_34 != V_35 ||
( V_30 -> V_33 . V_36 & V_37 ) ) {
F_7 ( L_2 ) ;
return - V_32 ;
}
}
return 0 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_38 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_38 ) ;
}
