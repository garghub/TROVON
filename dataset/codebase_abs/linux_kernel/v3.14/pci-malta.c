void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 , V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , V_11 ;
switch ( V_12 ) {
case V_13 :
F_2 ( V_14 ,
( 0 << V_15 ) |
( 0 << V_16 ) |
( 0 << V_17 ) |
( ( 0x20 / 4 ) << V_18 ) |
V_19 ) ;
F_2 ( V_20 , F_3 ( V_21 ) ) ;
V_3 = F_4 ( V_22 ) ;
V_4 = F_4 ( V_23 ) ;
V_5 = F_4 ( V_24 ) ;
V_4 = ( V_4 & V_25 ) | ( V_3 & ~ V_25 ) ;
V_6 = F_4 ( V_26 ) ;
V_7 = F_4 ( V_27 ) ;
V_8 = F_4 ( V_28 ) ;
V_7 = ( V_7 & V_25 ) | ( V_6 & ~ V_25 ) ;
if ( V_7 - V_6 > V_4 - V_3 ) {
V_3 = V_6 ;
V_4 = V_7 ;
V_5 = V_8 ;
}
V_11 = ~ ( V_3 ^ V_4 ) ;
F_5 ( ( V_3 & V_25 ) != ( V_5 & V_25 ) &&
V_11 != ~ ( ( V_11 & - V_11 ) - 1 ) ) ;
V_29 . V_3 = V_3 ;
V_29 . V_4 = V_4 ;
V_30 . V_31 = ( V_3 & V_11 ) - ( V_5 & V_11 ) ;
V_29 . V_3 <<= V_32 ;
V_29 . V_4 <<= V_32 ;
V_29 . V_4 |= ( 1 << V_32 ) - 1 ;
V_30 . V_31 <<= V_32 ;
V_3 = F_4 ( V_33 ) ;
V_4 = F_4 ( V_34 ) ;
V_5 = F_4 ( V_35 ) ;
V_4 = ( V_4 & V_25 ) | ( V_3 & ~ V_25 ) ;
V_11 = ~ ( V_3 ^ V_4 ) ;
F_5 ( ( V_3 & V_25 ) != ( V_5 & V_25 ) &&
V_11 != ~ ( ( V_11 & - V_11 ) - 1 ) ) ;
V_36 . V_3 = V_5 & V_11 ;
V_36 . V_4 = ( V_5 & V_11 ) | ~ V_11 ;
V_30 . V_37 = 0 ;
V_36 . V_3 <<= V_32 ;
V_36 . V_4 <<= V_32 ;
V_36 . V_4 |= ( 1 << V_32 ) - 1 ;
V_2 = & V_30 ;
break;
case V_38 :
V_5 = V_39 ;
V_8 = ( V_39 & V_40 ) >>
V_41 ;
V_9 = ( V_39 & V_42 ) >>
V_43 ;
V_10 = ( V_39 & V_44 ) >>
V_45 ;
V_5 = V_8 ;
V_3 = V_46 ;
V_4 = 1 ;
if ( V_10 == V_9 + 1 ) {
V_5 = V_9 ;
V_3 = V_47 ;
V_4 ++ ;
}
if ( V_9 == V_8 + 1 ) {
V_5 = V_8 ;
V_3 = V_46 ;
V_4 ++ ;
}
V_48 . V_3 = V_3 ;
V_48 . V_4 = V_3 +
F_6 ( V_4 ) - 1 ;
V_49 . V_31 = V_3 -
F_6 ( V_5 ) ;
V_2 = & V_49 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_7 ( V_54 , V_3 ) ;
F_7 ( V_55 , V_11 ) ;
F_7 ( V_56 , V_5 ) ;
V_57 . V_3 = V_3 & V_11 ;
V_57 . V_4 = ( V_3 & V_11 ) | ~ V_11 ;
V_58 . V_31 = ( V_3 & V_11 ) - ( V_5 & V_11 ) ;
#ifdef F_8
if ( F_9 () )
F_10 ( 0 , V_3 , V_11 ,
V_59 ) ;
#endif
F_7 ( V_60 , V_3 ) ;
F_7 ( V_61 , V_11 ) ;
F_7 ( V_62 , V_5 ) ;
V_63 . V_3 = V_5 & V_11 ;
V_63 . V_4 = ( V_5 & V_11 ) | ~ V_11 ;
V_58 . V_37 = 0 ;
V_64 . V_4 = ~ V_11 ;
#ifdef F_8
if ( F_9 () )
F_10 ( 1 , V_3 , V_11 ,
V_59 ) ;
#endif
V_3 = V_3 & V_11 ;
V_4 = V_3 | ~ V_11 ;
if ( ( V_3 >= V_57 . V_3 &&
V_3 <= V_57 . V_4 ) ||
( V_4 >= V_57 . V_3 &&
V_4 <= V_57 . V_4 ) ) {
V_3 = F_11 ( V_3 , V_57 . V_3 ) ;
V_4 = F_12 ( V_4 , V_57 . V_4 ) ;
if ( V_3 - V_57 . V_3 >=
V_57 . V_4 - V_4 )
V_57 . V_4 = V_3 - 1 ;
else
V_57 . V_3 = V_4 + 1 ;
}
V_2 = & V_58 ;
break;
default:
return;
}
if ( V_2 -> V_65 -> V_3 < 0x00001000UL )
V_2 -> V_65 -> V_3 = 0x00001000UL ;
V_66 . V_4 &= 0xfffffffffULL ;
V_64 . V_4 = V_2 -> V_65 -> V_4 ;
V_2 -> V_67 = V_68 ;
F_13 ( V_2 ) ;
}
