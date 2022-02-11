static enum V_1 V_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_4 & V_5 ) {
case 0 :
return V_6 ;
case 6 :
if ( ! V_3 -> V_7 )
return V_8 ;
default:
return V_9 ;
}
}
static int F_1 ( struct V_10 * V_11 , struct V_12 V_13 )
{
struct V_2 * V_3 = & V_11 -> V_14 -> V_15 ;
T_1 V_16 ;
T_2 V_7 ;
if ( ! F_2 ( V_11 , V_17 | V_18 |
V_19 | V_20 |
V_21 ) )
return 0 ;
if ( ! F_3 ( V_13 ) ) {
if ( V_13 . V_22 )
V_3 -> V_23 = V_24 ;
return 0 ;
}
if ( ! F_4 ( V_13 . V_25 , V_26 , V_26 / 2 ) )
goto V_27;
V_28:
F_5 ( 2 , L_1 ,
V_3 -> V_23 , F_6 ( V_13 . V_25 ) , F_7 ( V_13 . V_29 ) ) ;
if ( ! F_4 ( V_13 . V_25 , V_26 , V_26 / 2 ) )
return 0 ;
switch ( V_3 -> V_23 ) {
case V_24 :
if ( ! V_13 . V_29 )
break;
if ( ! F_8 ( V_13 . V_25 , V_30 , V_26 ) )
break;
V_3 -> V_23 = V_31 ;
V_3 -> V_32 = 0 ;
return 0 ;
case V_31 :
if ( V_13 . V_29 )
break;
if ( ! F_8 ( V_13 . V_25 , V_33 , V_26 / 2 ) )
break;
V_3 -> V_23 = V_34 ;
V_3 -> V_4 = 0 ;
return 0 ;
case V_34 :
if ( ! F_8 ( V_13 . V_25 , V_35 , V_26 / 2 ) )
break;
V_3 -> V_4 <<= 1 ;
if ( V_13 . V_29 )
V_3 -> V_4 |= 1 ;
V_3 -> V_32 ++ ;
V_3 -> V_23 = V_36 ;
return 0 ;
case V_36 :
if ( ! F_9 ( & V_13 , & V_11 -> V_14 -> V_37 ) )
break;
if ( V_3 -> V_32 == V_38 )
V_3 -> V_23 = V_39 ;
else
V_3 -> V_23 = V_34 ;
F_10 ( & V_13 , V_40 ) ;
goto V_28;
case V_39 :
if ( ! F_8 ( V_13 . V_25 , V_41 , V_26 / 2 ) )
break;
V_3 -> V_7 = V_13 . V_29 ;
V_3 -> V_23 = V_42 ;
return 0 ;
case V_42 :
if ( ! F_9 ( & V_13 , & V_11 -> V_14 -> V_37 ) ||
! F_4 ( V_13 . V_25 , V_43 , V_26 / 2 ) )
break;
if ( ! ( V_3 -> V_4 & V_44 ) ) {
F_5 ( 1 , L_2 ) ;
break;
}
V_3 -> V_23 = V_45 ;
F_10 ( & V_13 , V_43 ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_46 = 0 ;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_3 -> V_47 = V_48 ;
break;
case V_8 :
V_3 -> V_47 = V_49 ;
break;
default:
F_5 ( 1 , L_3 ) ;
goto V_27;
}
goto V_28;
case V_45 :
if ( F_8 ( V_13 . V_25 , V_35 , V_26 / 2 ) ) {
if ( V_3 -> V_32 ++ < V_50 * sizeof V_3 -> V_46 ) {
V_3 -> V_46 <<= 1 ;
if ( V_13 . V_29 )
V_3 -> V_46 |= 1 ;
}
V_3 -> V_23 = V_51 ;
return 0 ;
} else if ( V_8 == V_1 ( V_3 ) && ! V_13 . V_29 &&
F_4 ( V_13 . V_25 , V_52 , V_26 / 2 ) ) {
V_3 -> V_23 = V_53 ;
goto V_28;
}
break;
case V_51 :
if ( ! F_9 ( & V_13 , & V_11 -> V_14 -> V_37 ) )
break;
if ( V_3 -> V_32 == V_3 -> V_47 )
V_3 -> V_23 = V_53 ;
else
V_3 -> V_23 = V_45 ;
F_10 ( & V_13 , V_40 ) ;
goto V_28;
case V_53 :
if ( V_13 . V_29 )
break;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_16 = V_3 -> V_46 ;
V_7 = V_3 -> V_7 ;
F_5 ( 1 , L_4 ,
V_16 , V_7 ) ;
break;
case V_8 :
if ( V_3 -> V_32 > V_50 * sizeof V_3 -> V_46 ) {
F_5 ( 1 , L_5 ,
V_3 -> V_32 ) ;
goto V_27;
}
V_16 = V_3 -> V_46 ;
if ( V_3 -> V_32 == V_54 &&
( V_16 & V_55 ) == V_56 ) {
V_7 = ( V_16 & V_57 ) ? 1 : 0 ;
V_16 &= ~ V_57 ;
} else {
V_7 = 0 ;
}
F_5 ( 1 , L_6 ,
V_16 , V_7 ) ;
break;
default:
F_5 ( 1 , L_3 ) ;
goto V_27;
}
F_11 ( V_11 , V_16 , V_7 ) ;
V_3 -> V_23 = V_24 ;
return 0 ;
}
V_27:
F_5 ( 1 , L_7 ,
V_3 -> V_23 , F_6 ( V_13 . V_25 ) , F_7 ( V_13 . V_29 ) ) ;
V_3 -> V_23 = V_24 ;
return - V_58 ;
}
static int T_3 F_12 ( void )
{
F_13 ( & V_59 ) ;
F_14 ( V_60 L_8 ) ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_59 ) ;
}
