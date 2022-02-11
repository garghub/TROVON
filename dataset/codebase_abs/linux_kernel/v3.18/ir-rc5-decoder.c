static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 ;
enum V_11 V_12 ;
if ( ! ( V_2 -> V_13 & ( V_14 | V_15 | V_16 ) ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_17 )
V_6 -> V_18 = V_19 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_20 , V_21 , V_21 / 2 ) )
goto V_22;
V_23:
F_4 ( 2 , L_1 ,
V_6 -> V_18 , F_5 ( V_4 . V_20 ) , F_6 ( V_4 . V_24 ) ) ;
if ( ! F_3 ( V_4 . V_20 , V_21 , V_21 / 2 ) )
return 0 ;
switch ( V_6 -> V_18 ) {
case V_19 :
if ( ! V_4 . V_24 )
break;
V_6 -> V_18 = V_25 ;
V_6 -> V_26 = 1 ;
F_7 ( & V_4 , V_27 ) ;
goto V_23;
case V_25 :
if ( ! V_4 . V_24 && F_3 ( V_4 . V_20 , V_28 , V_21 / 2 ) ) {
V_6 -> V_18 = V_29 ;
goto V_23;
}
if ( ! F_8 ( V_4 . V_20 , V_27 , V_21 / 2 ) )
break;
V_6 -> V_30 <<= 1 ;
if ( ! V_4 . V_24 )
V_6 -> V_30 |= 1 ;
V_6 -> V_26 ++ ;
V_6 -> V_18 = V_31 ;
return 0 ;
case V_31 :
if ( ! F_9 ( & V_4 , & V_2 -> V_7 -> V_32 ) )
break;
if ( V_6 -> V_26 == V_33 )
V_6 -> V_18 = V_34 ;
else
V_6 -> V_18 = V_25 ;
F_7 ( & V_4 , V_35 ) ;
goto V_23;
case V_34 :
if ( ! V_4 . V_24 && F_3 ( V_4 . V_20 , V_36 , V_21 / 2 ) ) {
V_6 -> V_37 = true ;
F_7 ( & V_4 , V_36 ) ;
} else
V_6 -> V_37 = false ;
V_6 -> V_18 = V_25 ;
goto V_23;
case V_29 :
if ( V_4 . V_24 )
break;
if ( V_6 -> V_37 && V_6 -> V_26 == V_38 ) {
T_1 V_39 , V_40 , system ;
if ( ! ( V_2 -> V_13 & V_15 ) ) {
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_39 = ( V_6 -> V_30 & 0x0003F ) >> 0 ;
V_40 = ( V_6 -> V_30 & 0x00FC0 ) >> 6 ;
system = ( V_6 -> V_30 & 0x1F000 ) >> 12 ;
V_9 = ( V_6 -> V_30 & 0x20000 ) ? 1 : 0 ;
V_40 += ( V_6 -> V_30 & 0x01000 ) ? 0 : 0x40 ;
V_10 = system << 16 | V_40 << 8 | V_39 ;
V_12 = V_41 ;
} else if ( ! V_6 -> V_37 && V_6 -> V_26 == V_42 ) {
T_1 V_40 , system ;
if ( ! ( V_2 -> V_13 & V_14 ) ) {
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_40 = ( V_6 -> V_30 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_30 & 0x007C0 ) >> 6 ;
V_9 = ( V_6 -> V_30 & 0x00800 ) ? 1 : 0 ;
V_40 += ( V_6 -> V_30 & 0x01000 ) ? 0 : 0x40 ;
V_10 = system << 8 | V_40 ;
V_12 = V_43 ;
} else if ( ! V_6 -> V_37 && V_6 -> V_26 == V_44 ) {
T_1 V_40 , system ;
if ( ! ( V_2 -> V_13 & V_16 ) ) {
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_40 = ( V_6 -> V_30 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_30 & 0x02FC0 ) >> 6 ;
V_9 = ( V_6 -> V_30 & 0x01000 ) ? 1 : 0 ;
V_10 = system << 6 | V_40 ;
V_12 = V_45 ;
} else
break;
F_4 ( 1 , L_2 ,
V_10 , V_12 , V_9 ) ;
F_10 ( V_2 , V_12 , V_10 , V_9 ) ;
V_6 -> V_18 = V_19 ;
return 0 ;
}
V_22:
F_4 ( 1 , L_3 ,
V_6 -> V_18 , V_6 -> V_26 , F_5 ( V_4 . V_20 ) , F_6 ( V_4 . V_24 ) ) ;
V_6 -> V_18 = V_19 ;
return - V_46 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_47 ) ;
F_13 ( V_48 L_4 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_47 ) ;
}
