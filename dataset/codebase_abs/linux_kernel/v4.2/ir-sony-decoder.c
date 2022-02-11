static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
enum V_9 V_10 ;
T_1 V_11 ;
T_2 V_12 , V_13 , V_14 ;
if ( ! ( V_2 -> V_15 &
( V_16 | V_17 | V_18 ) ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_19 )
V_6 -> V_20 = V_21 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_22 , V_23 , V_23 / 2 ) )
goto V_24;
F_4 ( 2 , L_1 ,
V_6 -> V_20 , F_5 ( V_4 . V_22 ) , F_6 ( V_4 . V_25 ) ) ;
switch ( V_6 -> V_20 ) {
case V_21 :
if ( ! V_4 . V_25 )
break;
if ( ! F_7 ( V_4 . V_22 , V_26 , V_23 / 2 ) )
break;
V_6 -> V_27 = 0 ;
V_6 -> V_20 = V_28 ;
return 0 ;
case V_28 :
if ( V_4 . V_25 )
break;
if ( ! F_7 ( V_4 . V_22 , V_29 , V_23 / 2 ) )
break;
V_6 -> V_20 = V_30 ;
return 0 ;
case V_30 :
if ( ! V_4 . V_25 )
break;
V_6 -> V_31 <<= 1 ;
if ( F_7 ( V_4 . V_22 , V_32 , V_23 / 2 ) )
V_6 -> V_31 |= 1 ;
else if ( ! F_7 ( V_4 . V_22 , V_33 , V_23 / 2 ) )
break;
V_6 -> V_27 ++ ;
V_6 -> V_20 = V_34 ;
return 0 ;
case V_34 :
if ( V_4 . V_25 )
break;
if ( ! F_3 ( V_4 . V_22 , V_35 , V_23 / 2 ) )
break;
F_8 ( & V_4 , V_35 ) ;
if ( ! F_3 ( V_4 . V_22 , V_23 , V_23 / 2 ) ) {
V_6 -> V_20 = V_30 ;
return 0 ;
}
V_6 -> V_20 = V_36 ;
case V_36 :
if ( V_4 . V_25 )
break;
if ( ! F_3 ( V_4 . V_22 , V_37 , V_23 / 2 ) )
break;
switch ( V_6 -> V_27 ) {
case 12 :
if ( ! ( V_2 -> V_15 & V_16 ) )
goto V_38;
V_12 = F_9 ( ( V_6 -> V_31 << 3 ) & 0xF8 ) ;
V_13 = 0 ;
V_14 = F_9 ( ( V_6 -> V_31 >> 4 ) & 0xFE ) ;
V_10 = V_39 ;
break;
case 15 :
if ( ! ( V_2 -> V_15 & V_17 ) )
goto V_38;
V_12 = F_9 ( ( V_6 -> V_31 >> 0 ) & 0xFF ) ;
V_13 = 0 ;
V_14 = F_9 ( ( V_6 -> V_31 >> 7 ) & 0xFE ) ;
V_10 = V_40 ;
break;
case 20 :
if ( ! ( V_2 -> V_15 & V_18 ) )
goto V_38;
V_12 = F_9 ( ( V_6 -> V_31 >> 5 ) & 0xF8 ) ;
V_13 = F_9 ( ( V_6 -> V_31 >> 0 ) & 0xFF ) ;
V_14 = F_9 ( ( V_6 -> V_31 >> 12 ) & 0xFE ) ;
V_10 = V_41 ;
break;
default:
F_4 ( 1 , L_2 , V_6 -> V_27 ) ;
goto V_24;
}
V_11 = V_12 << 16 | V_13 << 8 | V_14 ;
F_4 ( 1 , L_3 , V_6 -> V_27 , V_11 ) ;
F_10 ( V_2 , V_10 , V_11 , 0 ) ;
goto V_38;
}
V_24:
F_4 ( 1 , L_4 ,
V_6 -> V_20 , F_5 ( V_4 . V_22 ) , F_6 ( V_4 . V_25 ) ) ;
V_6 -> V_20 = V_21 ;
return - V_42 ;
V_38:
V_6 -> V_20 = V_21 ;
return 0 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_43 ) ;
F_13 ( V_44 L_5 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_43 ) ;
}
