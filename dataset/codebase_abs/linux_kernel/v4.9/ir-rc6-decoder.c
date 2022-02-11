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
if ( ! F_2 ( V_13 ) ) {
if ( V_13 . V_19 )
V_3 -> V_20 = V_21 ;
return 0 ;
}
if ( ! F_3 ( V_13 . V_22 , V_23 , V_23 / 2 ) )
goto V_24;
V_25:
F_4 ( 2 , L_1 ,
V_3 -> V_20 , F_5 ( V_13 . V_22 ) , F_6 ( V_13 . V_26 ) ) ;
if ( ! F_3 ( V_13 . V_22 , V_23 , V_23 / 2 ) )
return 0 ;
switch ( V_3 -> V_20 ) {
case V_21 :
if ( ! V_13 . V_26 )
break;
if ( ! F_7 ( V_13 . V_22 , V_27 , V_23 ) )
break;
V_3 -> V_20 = V_28 ;
V_3 -> V_29 = 0 ;
return 0 ;
case V_28 :
if ( V_13 . V_26 )
break;
if ( ! F_7 ( V_13 . V_22 , V_30 , V_23 / 2 ) )
break;
V_3 -> V_20 = V_31 ;
V_3 -> V_4 = 0 ;
return 0 ;
case V_31 :
if ( ! F_7 ( V_13 . V_22 , V_32 , V_23 / 2 ) )
break;
V_3 -> V_4 <<= 1 ;
if ( V_13 . V_26 )
V_3 -> V_4 |= 1 ;
V_3 -> V_29 ++ ;
V_3 -> V_20 = V_33 ;
return 0 ;
case V_33 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_34 ) )
break;
if ( V_3 -> V_29 == V_35 )
V_3 -> V_20 = V_36 ;
else
V_3 -> V_20 = V_31 ;
F_9 ( & V_13 , V_37 ) ;
goto V_25;
case V_36 :
if ( ! F_7 ( V_13 . V_22 , V_38 , V_23 / 2 ) )
break;
V_3 -> V_7 = V_13 . V_26 ;
V_3 -> V_20 = V_39 ;
return 0 ;
case V_39 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_34 ) ||
! F_3 ( V_13 . V_22 , V_40 , V_23 / 2 ) )
break;
if ( ! ( V_3 -> V_4 & V_41 ) ) {
F_4 ( 1 , L_2 ) ;
break;
}
V_3 -> V_20 = V_42 ;
F_9 ( & V_13 , V_40 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_43 = 0 ;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_3 -> V_44 = V_45 ;
break;
case V_8 :
V_3 -> V_44 = V_46 ;
break;
default:
F_4 ( 1 , L_3 ) ;
goto V_24;
}
goto V_25;
case V_42 :
if ( F_7 ( V_13 . V_22 , V_32 , V_23 / 2 ) ) {
if ( V_3 -> V_29 ++ < V_47 * sizeof V_3 -> V_43 ) {
V_3 -> V_43 <<= 1 ;
if ( V_13 . V_26 )
V_3 -> V_43 |= 1 ;
}
V_3 -> V_20 = V_48 ;
return 0 ;
} else if ( V_8 == V_1 ( V_3 ) && ! V_13 . V_26 &&
F_3 ( V_13 . V_22 , V_49 , V_23 / 2 ) ) {
V_3 -> V_20 = V_50 ;
goto V_25;
}
break;
case V_48 :
if ( ! F_8 ( & V_13 , & V_11 -> V_14 -> V_34 ) )
break;
if ( V_3 -> V_29 == V_3 -> V_44 )
V_3 -> V_20 = V_50 ;
else
V_3 -> V_20 = V_42 ;
F_9 ( & V_13 , V_37 ) ;
goto V_25;
case V_50 :
if ( V_13 . V_26 )
break;
switch ( V_1 ( V_3 ) ) {
case V_6 :
V_16 = V_3 -> V_43 ;
V_7 = V_3 -> V_7 ;
V_18 = V_51 ;
F_4 ( 1 , L_4 ,
V_16 , V_7 ) ;
break;
case V_8 :
if ( V_3 -> V_29 > V_47 * sizeof V_3 -> V_43 ) {
F_4 ( 1 , L_5 ,
V_3 -> V_29 ) ;
goto V_24;
}
V_16 = V_3 -> V_43 ;
switch ( V_3 -> V_29 ) {
case 20 :
V_18 = V_52 ;
V_7 = 0 ;
break;
case 24 :
V_18 = V_53 ;
V_7 = 0 ;
break;
case 32 :
if ( ( V_16 & V_54 ) == V_55 ) {
V_18 = V_56 ;
V_7 = ! ! ( V_16 & V_57 ) ;
V_16 &= ~ V_57 ;
} else {
V_18 = V_58 ;
V_7 = 0 ;
}
break;
default:
F_4 ( 1 , L_6 ) ;
goto V_24;
}
F_4 ( 1 , L_7 ,
V_18 , V_16 , V_7 ) ;
break;
default:
F_4 ( 1 , L_3 ) ;
goto V_24;
}
F_10 ( V_11 , V_18 , V_16 , V_7 ) ;
V_3 -> V_20 = V_21 ;
return 0 ;
}
V_24:
F_4 ( 1 , L_8 ,
V_3 -> V_20 , F_5 ( V_13 . V_22 ) , F_6 ( V_13 . V_26 ) ) ;
V_3 -> V_20 = V_21 ;
return - V_59 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_60 ) ;
F_13 ( V_61 L_9 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_60 ) ;
}
