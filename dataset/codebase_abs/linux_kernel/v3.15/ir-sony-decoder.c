static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 ;
if ( ! F_2 ( V_2 , V_13 | V_14 |
V_15 ) )
return 0 ;
if ( ! F_3 ( V_4 ) ) {
if ( V_4 . V_16 )
V_6 -> V_17 = V_18 ;
return 0 ;
}
if ( ! F_4 ( V_4 . V_19 , V_20 , V_20 / 2 ) )
goto V_21;
F_5 ( 2 , L_1 ,
V_6 -> V_17 , F_6 ( V_4 . V_19 ) , F_7 ( V_4 . V_22 ) ) ;
switch ( V_6 -> V_17 ) {
case V_18 :
if ( ! V_4 . V_22 )
break;
if ( ! F_8 ( V_4 . V_19 , V_23 , V_20 / 2 ) )
break;
V_6 -> V_24 = 0 ;
V_6 -> V_17 = V_25 ;
return 0 ;
case V_25 :
if ( V_4 . V_22 )
break;
if ( ! F_8 ( V_4 . V_19 , V_26 , V_20 / 2 ) )
break;
V_6 -> V_17 = V_27 ;
return 0 ;
case V_27 :
if ( ! V_4 . V_22 )
break;
V_6 -> V_28 <<= 1 ;
if ( F_8 ( V_4 . V_19 , V_29 , V_20 / 2 ) )
V_6 -> V_28 |= 1 ;
else if ( ! F_8 ( V_4 . V_19 , V_30 , V_20 / 2 ) )
break;
V_6 -> V_24 ++ ;
V_6 -> V_17 = V_31 ;
return 0 ;
case V_31 :
if ( V_4 . V_22 )
break;
if ( ! F_4 ( V_4 . V_19 , V_32 , V_20 / 2 ) )
break;
F_9 ( & V_4 , V_32 ) ;
if ( ! F_4 ( V_4 . V_19 , V_20 , V_20 / 2 ) ) {
V_6 -> V_17 = V_27 ;
return 0 ;
}
V_6 -> V_17 = V_33 ;
case V_33 :
if ( V_4 . V_22 )
break;
if ( ! F_4 ( V_4 . V_19 , V_34 , V_20 / 2 ) )
break;
switch ( V_6 -> V_24 ) {
case 12 :
if ( ! F_2 ( V_2 , V_13 ) ) {
V_6 -> V_17 = V_18 ;
return 0 ;
}
V_10 = F_10 ( ( V_6 -> V_28 << 3 ) & 0xF8 ) ;
V_11 = 0 ;
V_12 = F_10 ( ( V_6 -> V_28 >> 4 ) & 0xFE ) ;
break;
case 15 :
if ( ! F_2 ( V_2 , V_14 ) ) {
V_6 -> V_17 = V_18 ;
return 0 ;
}
V_10 = F_10 ( ( V_6 -> V_28 >> 0 ) & 0xFF ) ;
V_11 = 0 ;
V_12 = F_10 ( ( V_6 -> V_28 >> 7 ) & 0xFE ) ;
break;
case 20 :
if ( ! F_2 ( V_2 , V_15 ) ) {
V_6 -> V_17 = V_18 ;
return 0 ;
}
V_10 = F_10 ( ( V_6 -> V_28 >> 5 ) & 0xF8 ) ;
V_11 = F_10 ( ( V_6 -> V_28 >> 0 ) & 0xFF ) ;
V_12 = F_10 ( ( V_6 -> V_28 >> 12 ) & 0xFE ) ;
break;
default:
F_5 ( 1 , L_2 , V_6 -> V_24 ) ;
goto V_21;
}
V_9 = V_10 << 16 | V_11 << 8 | V_12 ;
F_5 ( 1 , L_3 , V_6 -> V_24 , V_9 ) ;
F_11 ( V_2 , V_9 , 0 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
}
V_21:
F_5 ( 1 , L_4 ,
V_6 -> V_17 , F_6 ( V_4 . V_19 ) , F_7 ( V_4 . V_22 ) ) ;
V_6 -> V_17 = V_18 ;
return - V_35 ;
}
static int T_3 F_12 ( void )
{
F_13 ( & V_36 ) ;
F_14 ( V_37 L_5 ) ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_36 ) ;
}
