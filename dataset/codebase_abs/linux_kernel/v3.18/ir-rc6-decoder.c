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
enum V_17 V_18 ;
if ( ! ( V_11 -> V_19 &
( V_20 | V_21 | V_22 |
V_23 | V_24 ) ) )
return 0 ;
if ( ! F_2 ( V_13 ) ) {
if ( V_13 . V_25 )
V_3 -> V_26 = V_27 ;
return 0 ;
}
if ( ! F_3 ( V_13 . V_28 , V_29 , V_29 / 2 ) )
goto V_30;
V_31:
F_4 ( 2 , L_1 ,
V_3 -> V_26 , F_5 ( V_13 . V_28 ) , F_6 ( V_13 . V_32 ) ) ;
if ( ! F_3 ( V_13 . V_28 , V_29 , V_29 / 2 ) )
return 0 ;
switch ( V_3 -> V_26 ) {
case V_27 :
if ( ! V_13 . V_32 )
break;
if ( ! F_7 ( V_13 . V_28 , V_33 , V_29 ) )
break;
V_3 -> V_26 = V_34 ;
V_3 -> V_35 = 0 ;
return 0 ;
case V_34 :
if ( V_13 . V_32 )
break;
if ( ! F_7 ( V_13 . V_28 , V_36 , V_29 / 2 ) )
break;
V_3 -> V_26 = V_37 ;
V_3 -> V_4 = 0 ;
return 0 ;
case V_37 :
if ( ! F_7 ( V_13 . V_28 , V_38 , V_29 / 2 ) )
break;
V_3 -> V_4 <<= 1 ;
if ( V_13 . V_32 )
V_3 -> V_4 |= 1 ;
V_3 -> V_35 ++ ;
V_3 -> V_26 = V_39 ;
return 0 ;
case V_39 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_40 ) )
break;
if ( V_3 -> V_35 == V_41 )
V_3 -> V_26 = V_42 ;
else
V_3 -> V_26 = V_37 ;
F_9 ( & V_13 , V_43 ) ;
goto V_31;
case V_42 :
if ( ! F_7 ( V_13 . V_28 , V_44 , V_29 / 2 ) )
break;
V_3 -> V_7 = V_13 . V_32 ;
V_3 -> V_26 = V_45 ;
return 0 ;
case V_45 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_40 ) ||
! F_3 ( V_13 . V_28 , V_46 , V_29 / 2 ) )
break;
if ( ! ( V_3 -> V_4 & V_47 ) ) {
F_4 ( 1 , L_2 ) ;
break;
}
V_3 -> V_26 = V_48 ;
F_9 ( & V_13 , V_46 ) ;
V_3 -> V_35 = 0 ;
V_3 -> V_49 = 0 ;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_3 -> V_50 = V_51 ;
break;
case V_8 :
V_3 -> V_50 = V_52 ;
break;
default:
F_4 ( 1 , L_3 ) ;
goto V_30;
}
goto V_31;
case V_48 :
if ( F_7 ( V_13 . V_28 , V_38 , V_29 / 2 ) ) {
if ( V_3 -> V_35 ++ < V_53 * sizeof V_3 -> V_49 ) {
V_3 -> V_49 <<= 1 ;
if ( V_13 . V_32 )
V_3 -> V_49 |= 1 ;
}
V_3 -> V_26 = V_54 ;
return 0 ;
} else if ( V_8 == V_1 ( V_3 ) && ! V_13 . V_32 &&
F_3 ( V_13 . V_28 , V_55 , V_29 / 2 ) ) {
V_3 -> V_26 = V_56 ;
goto V_31;
}
break;
case V_54 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_40 ) )
break;
if ( V_3 -> V_35 == V_3 -> V_50 )
V_3 -> V_26 = V_56 ;
else
V_3 -> V_26 = V_48 ;
F_9 ( & V_13 , V_43 ) ;
goto V_31;
case V_56 :
if ( V_13 . V_32 )
break;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_16 = V_3 -> V_49 ;
V_7 = V_3 -> V_7 ;
V_18 = V_57 ;
F_4 ( 1 , L_4 ,
V_16 , V_7 ) ;
break;
case V_8 :
if ( V_3 -> V_35 > V_53 * sizeof V_3 -> V_49 ) {
F_4 ( 1 , L_5 ,
V_3 -> V_35 ) ;
goto V_30;
}
V_16 = V_3 -> V_49 ;
switch ( V_3 -> V_35 ) {
case 20 :
V_18 = V_58 ;
V_7 = 0 ;
break;
case 24 :
V_18 = V_22 ;
V_7 = 0 ;
break;
case 32 :
if ( ( V_16 & V_59 ) == V_60 ) {
V_18 = V_61 ;
V_7 = ! ! ( V_16 & V_62 ) ;
V_16 &= ~ V_62 ;
} else {
V_18 = V_23 ;
V_7 = 0 ;
}
break;
default:
F_4 ( 1 , L_6 ) ;
goto V_30;
}
F_4 ( 1 , L_7 ,
V_18 , V_16 , V_7 ) ;
break;
default:
F_4 ( 1 , L_3 ) ;
goto V_30;
}
F_10 ( V_11 , V_18 , V_16 , V_7 ) ;
V_3 -> V_26 = V_27 ;
return 0 ;
}
V_30:
F_4 ( 1 , L_8 ,
V_3 -> V_26 , F_5 ( V_13 . V_28 ) , F_6 ( V_13 . V_32 ) ) ;
V_3 -> V_26 = V_27 ;
return - V_63 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_64 ) ;
F_13 ( V_65 L_9 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_64 ) ;
}
