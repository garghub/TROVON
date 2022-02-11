static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 ;
if ( ! ( V_2 -> V_13 &
( V_14 | V_15 | V_16 ) ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_17 )
V_6 -> V_18 = V_19 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_20 , V_21 , V_21 / 2 ) )
goto V_22;
F_4 ( 2 , L_1 ,
V_6 -> V_18 , F_5 ( V_4 . V_20 ) , F_6 ( V_4 . V_23 ) ) ;
switch ( V_6 -> V_18 ) {
case V_19 :
if ( ! V_4 . V_23 )
break;
if ( ! F_7 ( V_4 . V_20 , V_24 , V_21 / 2 ) )
break;
V_6 -> V_25 = 0 ;
V_6 -> V_18 = V_26 ;
return 0 ;
case V_26 :
if ( V_4 . V_23 )
break;
if ( ! F_7 ( V_4 . V_20 , V_27 , V_21 / 2 ) )
break;
V_6 -> V_18 = V_28 ;
return 0 ;
case V_28 :
if ( ! V_4 . V_23 )
break;
V_6 -> V_29 <<= 1 ;
if ( F_7 ( V_4 . V_20 , V_30 , V_21 / 2 ) )
V_6 -> V_29 |= 1 ;
else if ( ! F_7 ( V_4 . V_20 , V_31 , V_21 / 2 ) )
break;
V_6 -> V_25 ++ ;
V_6 -> V_18 = V_32 ;
return 0 ;
case V_32 :
if ( V_4 . V_23 )
break;
if ( ! F_3 ( V_4 . V_20 , V_33 , V_21 / 2 ) )
break;
F_8 ( & V_4 , V_33 ) ;
if ( ! F_3 ( V_4 . V_20 , V_21 , V_21 / 2 ) ) {
V_6 -> V_18 = V_28 ;
return 0 ;
}
V_6 -> V_18 = V_34 ;
case V_34 :
if ( V_4 . V_23 )
break;
if ( ! F_3 ( V_4 . V_20 , V_35 , V_21 / 2 ) )
break;
switch ( V_6 -> V_25 ) {
case 12 :
if ( ! ( V_2 -> V_13 & V_14 ) ) {
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_10 = F_9 ( ( V_6 -> V_29 << 3 ) & 0xF8 ) ;
V_11 = 0 ;
V_12 = F_9 ( ( V_6 -> V_29 >> 4 ) & 0xFE ) ;
break;
case 15 :
if ( ! ( V_2 -> V_13 & V_15 ) ) {
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_10 = F_9 ( ( V_6 -> V_29 >> 0 ) & 0xFF ) ;
V_11 = 0 ;
V_12 = F_9 ( ( V_6 -> V_29 >> 7 ) & 0xFE ) ;
break;
case 20 :
if ( ! ( V_2 -> V_13 & V_16 ) ) {
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_10 = F_9 ( ( V_6 -> V_29 >> 5 ) & 0xF8 ) ;
V_11 = F_9 ( ( V_6 -> V_29 >> 0 ) & 0xFF ) ;
V_12 = F_9 ( ( V_6 -> V_29 >> 12 ) & 0xFE ) ;
break;
default:
F_4 ( 1 , L_2 , V_6 -> V_25 ) ;
goto V_22;
}
V_9 = V_10 << 16 | V_11 << 8 | V_12 ;
F_4 ( 1 , L_3 , V_6 -> V_25 , V_9 ) ;
F_10 ( V_2 , V_9 , 0 ) ;
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_22:
F_4 ( 1 , L_4 ,
V_6 -> V_18 , F_5 ( V_4 . V_20 ) , F_6 ( V_4 . V_23 ) ) ;
V_6 -> V_18 = V_19 ;
return - V_36 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_37 ) ;
F_13 ( V_38 L_5 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_37 ) ;
}
