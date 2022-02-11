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
if ( ! ( V_11 -> V_17 &
( V_18 | V_19 | V_20 |
V_21 | V_22 ) ) )
return 0 ;
if ( ! F_2 ( V_13 ) ) {
if ( V_13 . V_23 )
V_3 -> V_24 = V_25 ;
return 0 ;
}
if ( ! F_3 ( V_13 . V_26 , V_27 , V_27 / 2 ) )
goto V_28;
V_29:
F_4 ( 2 , L_1 ,
V_3 -> V_24 , F_5 ( V_13 . V_26 ) , F_6 ( V_13 . V_30 ) ) ;
if ( ! F_3 ( V_13 . V_26 , V_27 , V_27 / 2 ) )
return 0 ;
switch ( V_3 -> V_24 ) {
case V_25 :
if ( ! V_13 . V_30 )
break;
if ( ! F_7 ( V_13 . V_26 , V_31 , V_27 ) )
break;
V_3 -> V_24 = V_32 ;
V_3 -> V_33 = 0 ;
return 0 ;
case V_32 :
if ( V_13 . V_30 )
break;
if ( ! F_7 ( V_13 . V_26 , V_34 , V_27 / 2 ) )
break;
V_3 -> V_24 = V_35 ;
V_3 -> V_4 = 0 ;
return 0 ;
case V_35 :
if ( ! F_7 ( V_13 . V_26 , V_36 , V_27 / 2 ) )
break;
V_3 -> V_4 <<= 1 ;
if ( V_13 . V_30 )
V_3 -> V_4 |= 1 ;
V_3 -> V_33 ++ ;
V_3 -> V_24 = V_37 ;
return 0 ;
case V_37 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_38 ) )
break;
if ( V_3 -> V_33 == V_39 )
V_3 -> V_24 = V_40 ;
else
V_3 -> V_24 = V_35 ;
F_9 ( & V_13 , V_41 ) ;
goto V_29;
case V_40 :
if ( ! F_7 ( V_13 . V_26 , V_42 , V_27 / 2 ) )
break;
V_3 -> V_7 = V_13 . V_30 ;
V_3 -> V_24 = V_43 ;
return 0 ;
case V_43 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_38 ) ||
! F_3 ( V_13 . V_26 , V_44 , V_27 / 2 ) )
break;
if ( ! ( V_3 -> V_4 & V_45 ) ) {
F_4 ( 1 , L_2 ) ;
break;
}
V_3 -> V_24 = V_46 ;
F_9 ( & V_13 , V_44 ) ;
V_3 -> V_33 = 0 ;
V_3 -> V_47 = 0 ;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_3 -> V_48 = V_49 ;
break;
case V_8 :
V_3 -> V_48 = V_50 ;
break;
default:
F_4 ( 1 , L_3 ) ;
goto V_28;
}
goto V_29;
case V_46 :
if ( F_7 ( V_13 . V_26 , V_36 , V_27 / 2 ) ) {
if ( V_3 -> V_33 ++ < V_51 * sizeof V_3 -> V_47 ) {
V_3 -> V_47 <<= 1 ;
if ( V_13 . V_30 )
V_3 -> V_47 |= 1 ;
}
V_3 -> V_24 = V_52 ;
return 0 ;
} else if ( V_8 == V_1 ( V_3 ) && ! V_13 . V_30 &&
F_3 ( V_13 . V_26 , V_53 , V_27 / 2 ) ) {
V_3 -> V_24 = V_54 ;
goto V_29;
}
break;
case V_52 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_38 ) )
break;
if ( V_3 -> V_33 == V_3 -> V_48 )
V_3 -> V_24 = V_54 ;
else
V_3 -> V_24 = V_46 ;
F_9 ( & V_13 , V_41 ) ;
goto V_29;
case V_54 :
if ( V_13 . V_30 )
break;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_16 = V_3 -> V_47 ;
V_7 = V_3 -> V_7 ;
F_4 ( 1 , L_4 ,
V_16 , V_7 ) ;
break;
case V_8 :
if ( V_3 -> V_33 > V_51 * sizeof V_3 -> V_47 ) {
F_4 ( 1 , L_5 ,
V_3 -> V_33 ) ;
goto V_28;
}
V_16 = V_3 -> V_47 ;
if ( V_3 -> V_33 == V_55 &&
( V_16 & V_56 ) == V_57 ) {
V_7 = ( V_16 & V_58 ) ? 1 : 0 ;
V_16 &= ~ V_58 ;
} else {
V_7 = 0 ;
}
F_4 ( 1 , L_6 ,
V_16 , V_7 ) ;
break;
default:
F_4 ( 1 , L_3 ) ;
goto V_28;
}
F_10 ( V_11 , V_16 , V_7 ) ;
V_3 -> V_24 = V_25 ;
return 0 ;
}
V_28:
F_4 ( 1 , L_7 ,
V_3 -> V_24 , F_5 ( V_13 . V_26 ) , F_6 ( V_13 . V_30 ) ) ;
V_3 -> V_24 = V_25 ;
return - V_59 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_60 ) ;
F_13 ( V_61 L_8 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_60 ) ;
}
