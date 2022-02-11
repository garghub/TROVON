static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
enum V_9 V_10 ;
T_1 V_11 ;
T_2 V_12 , V_13 , V_14 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_15 )
V_6 -> V_16 = V_17 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_18 , V_19 , V_19 / 2 ) )
goto V_20;
F_4 ( 2 , L_1 ,
V_6 -> V_16 , F_5 ( V_4 . V_18 ) , F_6 ( V_4 . V_21 ) ) ;
switch ( V_6 -> V_16 ) {
case V_17 :
if ( ! V_4 . V_21 )
break;
if ( ! F_7 ( V_4 . V_18 , V_22 , V_19 / 2 ) )
break;
V_6 -> V_23 = 0 ;
V_6 -> V_16 = V_24 ;
return 0 ;
case V_24 :
if ( V_4 . V_21 )
break;
if ( ! F_7 ( V_4 . V_18 , V_25 , V_19 / 2 ) )
break;
V_6 -> V_16 = V_26 ;
return 0 ;
case V_26 :
if ( ! V_4 . V_21 )
break;
V_6 -> V_27 <<= 1 ;
if ( F_7 ( V_4 . V_18 , V_28 , V_19 / 2 ) )
V_6 -> V_27 |= 1 ;
else if ( ! F_7 ( V_4 . V_18 , V_29 , V_19 / 2 ) )
break;
V_6 -> V_23 ++ ;
V_6 -> V_16 = V_30 ;
return 0 ;
case V_30 :
if ( V_4 . V_21 )
break;
if ( ! F_3 ( V_4 . V_18 , V_31 , V_19 / 2 ) )
break;
F_8 ( & V_4 , V_31 ) ;
if ( ! F_3 ( V_4 . V_18 , V_19 , V_19 / 2 ) ) {
V_6 -> V_16 = V_26 ;
return 0 ;
}
V_6 -> V_16 = V_32 ;
case V_32 :
if ( V_4 . V_21 )
break;
if ( ! F_3 ( V_4 . V_18 , V_33 , V_19 / 2 ) )
break;
switch ( V_6 -> V_23 ) {
case 12 :
if ( ! ( V_2 -> V_34 & V_35 ) )
goto V_36;
V_12 = F_9 ( ( V_6 -> V_27 << 3 ) & 0xF8 ) ;
V_13 = 0 ;
V_14 = F_9 ( ( V_6 -> V_27 >> 4 ) & 0xFE ) ;
V_10 = V_37 ;
break;
case 15 :
if ( ! ( V_2 -> V_34 & V_38 ) )
goto V_36;
V_12 = F_9 ( ( V_6 -> V_27 >> 0 ) & 0xFF ) ;
V_13 = 0 ;
V_14 = F_9 ( ( V_6 -> V_27 >> 7 ) & 0xFE ) ;
V_10 = V_39 ;
break;
case 20 :
if ( ! ( V_2 -> V_34 & V_40 ) )
goto V_36;
V_12 = F_9 ( ( V_6 -> V_27 >> 5 ) & 0xF8 ) ;
V_13 = F_9 ( ( V_6 -> V_27 >> 0 ) & 0xFF ) ;
V_14 = F_9 ( ( V_6 -> V_27 >> 12 ) & 0xFE ) ;
V_10 = V_41 ;
break;
default:
F_4 ( 1 , L_2 , V_6 -> V_23 ) ;
goto V_20;
}
V_11 = V_12 << 16 | V_13 << 8 | V_14 ;
F_4 ( 1 , L_3 , V_6 -> V_23 , V_11 ) ;
F_10 ( V_2 , V_10 , V_11 , 0 ) ;
goto V_36;
}
V_20:
F_4 ( 1 , L_4 ,
V_6 -> V_16 , F_5 ( V_4 . V_18 ) , F_6 ( V_4 . V_21 ) ) ;
V_6 -> V_16 = V_17 ;
return - V_42 ;
V_36:
V_6 -> V_16 = V_17 ;
return 0 ;
}
static int F_11 ( enum V_9 V_10 , T_1 V_11 ,
struct V_3 * V_43 , unsigned int V_44 )
{
struct V_3 * V_45 = V_43 ;
T_1 V_7 , V_46 ;
int V_47 ;
if ( V_10 == V_37 ) {
V_7 = ( V_11 & 0x7f ) | ( ( V_11 & 0x1f0000 ) >> 9 ) ;
V_46 = 12 ;
} else if ( V_10 == V_39 ) {
V_7 = ( V_11 & 0x7f ) | ( ( V_11 & 0xff0000 ) >> 9 ) ;
V_46 = 15 ;
} else {
V_7 = ( V_11 & 0x7f ) | ( ( V_11 & 0x1f0000 ) >> 9 ) |
( ( V_11 & 0xff00 ) << 4 ) ;
V_46 = 20 ;
}
V_47 = F_12 ( & V_45 , V_44 , & V_48 , V_46 , V_7 ) ;
if ( V_47 < 0 )
return V_47 ;
return V_45 - V_43 ;
}
static int T_3 F_13 ( void )
{
F_14 ( & V_49 ) ;
F_15 ( V_50 L_5 ) ;
return 0 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_49 ) ;
}
