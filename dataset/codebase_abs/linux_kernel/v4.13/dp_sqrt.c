union V_1 F_1 ( union V_1 V_2 )
{
struct V_3 V_4 ;
union V_1 V_5 , V_6 , V_7 ;
unsigned V_8 , V_9 ;
V_10 ;
V_11 ;
F_2 () ;
V_12 ;
switch ( V_13 ) {
case V_14 :
return F_3 ( V_2 ) ;
case V_15 :
return V_2 ;
case V_16 :
return V_2 ;
case V_17 :
if ( V_18 ) {
F_4 ( V_19 ) ;
return F_5 () ;
}
return V_2 ;
case V_20 :
V_21 ;
case V_22 :
if ( V_18 ) {
F_4 ( V_19 ) ;
return F_5 () ;
}
break;
}
V_4 = V_23 ;
V_23 . V_24 &= ~ V_25 ;
V_23 . V_26 &= ~ V_25 ;
V_23 . V_27 = V_28 ;
V_8 = 0 ;
if ( V_29 > 512 ) {
V_29 -= 512 ;
V_8 += 256 ;
} else if ( V_29 < - 512 ) {
V_29 += 512 ;
V_8 -= 256 ;
}
V_5 = V_2 = F_6 ( 0 , V_29 + V_30 , V_31 & ~ V_32 ) ;
V_9 = V_5 . V_33 >> 32 ;
V_9 = ( V_9 >> 1 ) + 0x1ff80000 ;
V_9 = V_9 - V_34 [ ( V_9 >> 15 ) & 31 ] ;
V_5 . V_33 = ( ( V_35 ) V_9 << 32 ) | ( V_5 . V_33 & 0xffffffff ) ;
V_7 = F_7 ( V_2 , V_5 ) ;
V_5 = F_8 ( V_5 , V_7 ) ;
V_5 . V_33 -= 0x0010000600000000LL ;
V_5 . V_33 &= 0xffffffff00000000LL ;
V_6 = V_7 = F_9 ( V_5 , V_5 ) ;
V_7 . V_36 += 0x001 ;
V_7 = F_8 ( V_7 , V_6 ) ;
V_6 = F_9 ( F_10 ( V_2 , V_6 ) , V_5 ) ;
V_7 = F_7 ( V_6 , F_8 ( V_7 , V_2 ) ) ;
V_7 . V_36 += 0x001 ;
V_5 = F_8 ( V_5 , V_7 ) ;
V_23 . V_27 = V_37 ;
V_23 . V_26 &= ~ V_25 ;
V_7 = F_7 ( V_2 , V_5 ) ;
if ( V_23 . V_26 & V_25 || V_7 . V_33 != V_5 . V_33 ) {
if ( ! ( V_23 . V_26 & V_25 ) )
V_7 . V_33 -= 1 ;
V_4 . V_38 |= V_25 ;
V_4 . V_26 |= V_25 ;
switch ( V_4 . V_27 ) {
case V_39 :
V_5 . V_33 += 1 ;
case V_28 :
V_7 . V_33 += 1 ;
break;
}
V_5 = F_8 ( V_5 , V_7 ) ;
V_8 -= 1 ;
}
V_5 . V_36 += V_8 ;
V_23 = V_4 ;
return V_5 ;
}
