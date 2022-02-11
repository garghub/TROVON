static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 ;
if ( ! ( V_2 -> V_7 -> V_11 & V_12 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_13 )
V_6 -> V_14 = V_15 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_16 , V_17 , V_17 / 2 ) )
goto V_18;
V_19:
F_4 ( 2 , L_1 ,
V_6 -> V_14 , F_5 ( V_4 . V_16 ) , F_6 ( V_4 . V_20 ) ) ;
if ( ! F_3 ( V_4 . V_16 , V_17 , V_17 / 2 ) )
return 0 ;
switch ( V_6 -> V_14 ) {
case V_15 :
if ( ! V_4 . V_20 )
break;
V_6 -> V_14 = V_21 ;
V_6 -> V_22 = 1 ;
V_6 -> V_23 = V_24 ;
F_7 ( & V_4 , V_25 ) ;
goto V_19;
case V_21 :
if ( ! F_8 ( V_4 . V_16 , V_25 , V_17 / 2 ) )
break;
V_6 -> V_26 <<= 1 ;
if ( ! V_4 . V_20 )
V_6 -> V_26 |= 1 ;
V_6 -> V_22 ++ ;
V_6 -> V_14 = V_27 ;
return 0 ;
case V_27 :
if ( ! F_9 ( & V_4 , & V_2 -> V_7 -> V_28 ) )
break;
if ( V_6 -> V_22 == V_6 -> V_23 )
V_6 -> V_14 = V_29 ;
else if ( V_6 -> V_22 == V_30 )
V_6 -> V_14 = V_31 ;
else
V_6 -> V_14 = V_21 ;
F_7 ( & V_4 , V_32 ) ;
goto V_19;
case V_31 :
if ( ! V_4 . V_20 && F_3 ( V_4 . V_16 , V_33 , V_17 / 2 ) ) {
V_6 -> V_23 = V_24 ;
F_7 ( & V_4 , V_33 ) ;
} else {
V_6 -> V_23 = V_34 ;
}
V_6 -> V_14 = V_21 ;
goto V_19;
case V_29 :
if ( V_4 . V_20 )
break;
if ( V_6 -> V_23 == V_24 ) {
T_1 V_35 , V_36 , system ;
V_35 = ( V_6 -> V_26 & 0x0003F ) >> 0 ;
V_36 = ( V_6 -> V_26 & 0x00FC0 ) >> 6 ;
system = ( V_6 -> V_26 & 0x1F000 ) >> 12 ;
V_9 = ( V_6 -> V_26 & 0x20000 ) ? 1 : 0 ;
V_36 += ( V_6 -> V_26 & 0x01000 ) ? 0 : 0x40 ;
V_10 = system << 16 | V_36 << 8 | V_35 ;
F_4 ( 1 , L_2 ,
V_10 , V_9 ) ;
} else {
T_1 V_36 , system ;
V_36 = ( V_6 -> V_26 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_26 & 0x007C0 ) >> 6 ;
V_9 = ( V_6 -> V_26 & 0x00800 ) ? 1 : 0 ;
V_36 += ( V_6 -> V_26 & 0x01000 ) ? 0 : 0x40 ;
V_10 = system << 8 | V_36 ;
F_4 ( 1 , L_3 ,
V_10 , V_9 ) ;
}
F_10 ( V_2 , V_10 , V_9 ) ;
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_18:
F_4 ( 1 , L_4 ,
V_6 -> V_14 , F_5 ( V_4 . V_16 ) , F_6 ( V_4 . V_20 ) ) ;
V_6 -> V_14 = V_15 ;
return - V_37 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_38 ) ;
F_13 ( V_39 L_5 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_38 ) ;
}
