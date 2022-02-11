static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
if ( F_2 ( 0xC0000000 ) >= 0xC0000001 ) {
T_1 V_5 = F_3 ( 0xC0000001 ) ;
if ( ( V_5 & ( V_6 | V_7 ) ) == V_6 ) {
F_4 ( V_8 , V_3 , V_4 ) ;
V_3 |= V_9 ;
F_5 ( V_8 , V_3 , V_4 ) ;
F_6 ( V_10 L_1 ) ;
}
if ( ( V_5 & ( V_11 | V_12 ) ) == V_11 ) {
F_4 ( V_13 , V_3 , V_4 ) ;
V_3 |= V_14 ;
F_5 ( V_13 , V_3 , V_4 ) ;
F_6 ( V_10 L_2 ) ;
}
V_2 -> V_15 [ V_16 ] = F_3 ( 0xC0000001 ) ;
}
#ifdef F_7
if ( V_2 -> V_17 >= 6 && V_2 -> V_17 <= 13 ) {
F_4 ( V_8 , V_3 , V_4 ) ;
V_3 |= ( 1 << 1 | 1 << 7 ) ;
F_5 ( V_8 , V_3 , V_4 ) ;
F_8 ( V_2 , V_18 ) ;
}
if ( V_2 -> V_17 >= 6 && V_2 -> V_17 < 9 )
F_8 ( V_2 , V_19 ) ;
#endif
if ( V_2 -> V_20 == 0x6 && V_2 -> V_17 >= 0xf ) {
V_2 -> V_21 = V_2 -> V_22 * 2 ;
F_8 ( V_2 , V_23 ) ;
}
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_20 ) {
#ifdef F_7
case 5 :
F_8 ( V_2 , V_24 ) ;
break;
#endif
case 6 :
if ( V_2 -> V_17 >= 0xf )
F_8 ( V_2 , V_25 ) ;
break;
}
#ifdef F_11
F_8 ( V_2 , V_26 ) ;
#endif
}
static void F_12 ( struct V_1 * V_2 )
{
#ifdef F_7
char * V_27 ;
T_1 V_28 = 0 ;
T_1 V_29 = 0 ;
T_1 V_3 , V_4 , V_30 ;
T_1 V_31 , V_32 , V_33 , V_34 ;
F_13 ( V_2 , 0 * 32 + 31 ) ;
#endif
F_10 ( V_2 ) ;
switch ( V_2 -> V_20 ) {
#ifdef F_7
case 5 :
switch ( V_2 -> V_17 ) {
case 4 :
V_27 = L_3 ;
V_28 = V_35 | V_36 | V_37 | V_38 | V_39 ;
V_29 = V_40 ;
F_6 ( V_41 L_4 ) ;
F_13 ( V_2 , V_42 ) ;
break;
case 8 :
switch ( V_2 -> V_43 ) {
default:
V_27 = L_5 ;
break;
case 7 ... 9 :
V_27 = L_6 ;
break;
case 10 ... 15 :
V_27 = L_7 ;
break;
}
V_28 = V_35 | V_36 | V_44 | V_38 | V_45 | V_39 |
V_46 | V_47 ;
V_29 = V_40 ;
break;
case 9 :
V_27 = L_8 ;
V_28 = V_35 | V_36 | V_44 | V_38 | V_45 | V_39 |
V_46 | V_47 ;
V_29 = V_40 ;
break;
default:
V_27 = L_9 ;
}
F_4 ( V_48 , V_3 , V_4 ) ;
V_30 = ( V_3 | V_28 ) & ( ~ V_29 ) ;
if ( V_30 != V_3 ) {
F_6 ( V_10 L_10 ,
V_3 , V_30 ) ;
F_5 ( V_48 , V_30 , V_4 ) ;
} else {
F_6 ( V_10 L_11 , V_3 ) ;
}
F_8 ( V_2 , V_24 ) ;
F_8 ( V_2 , V_18 ) ;
if ( V_2 -> V_17 >= 8 )
F_8 ( V_2 , V_19 ) ;
if ( F_2 ( 0x80000000 ) >= 0x80000005 ) {
F_14 ( 0x80000005 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_2 -> V_49 = ( V_33 >> 24 ) + ( V_34 >> 24 ) ;
}
sprintf ( V_2 -> V_50 , L_12 , V_27 ) ;
break;
#endif
case 6 :
F_1 ( V_2 ) ;
break;
}
#ifdef F_11
F_8 ( V_2 , V_51 ) ;
#endif
}
static unsigned int
F_15 ( struct V_1 * V_2 , unsigned int V_52 )
{
if ( ( V_2 -> V_20 == 6 ) && ( ( V_2 -> V_17 == 7 ) || ( V_2 -> V_17 == 8 ) ) )
V_52 >>= 8 ;
if ( ( V_2 -> V_20 == 6 ) && ( V_2 -> V_17 == 9 ) &&
( V_2 -> V_43 == 1 ) && ( V_52 == 65 ) )
V_52 -= 1 ;
return V_52 ;
}
