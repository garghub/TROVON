static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
if ( F_2 ( 0xC0000000 ) >= 0xC0000001 ) {
T_1 V_5 = F_3 ( 0xC0000001 ) ;
if ( ( V_5 & ( V_6 | V_7 ) ) == V_6 ) {
F_4 ( V_8 , V_3 , V_4 ) ;
V_3 |= V_9 ;
F_5 ( V_8 , V_3 , V_4 ) ;
F_6 ( L_1 ) ;
}
if ( ( V_5 & ( V_10 | V_11 ) ) == V_10 ) {
F_4 ( V_12 , V_3 , V_4 ) ;
V_3 |= V_13 ;
F_5 ( V_12 , V_3 , V_4 ) ;
F_6 ( L_2 ) ;
}
V_2 -> V_14 [ V_15 ] = F_3 ( 0xC0000001 ) ;
}
#ifdef F_7
if ( V_2 -> V_16 >= 6 && V_2 -> V_16 <= 13 ) {
F_4 ( V_8 , V_3 , V_4 ) ;
V_3 |= ( 1 << 1 | 1 << 7 ) ;
F_5 ( V_8 , V_3 , V_4 ) ;
F_8 ( V_2 , V_17 ) ;
}
if ( V_2 -> V_16 >= 6 && V_2 -> V_16 < 9 )
F_8 ( V_2 , V_18 ) ;
#endif
if ( V_2 -> V_19 == 0x6 && V_2 -> V_16 >= 0xf ) {
V_2 -> V_20 = V_2 -> V_21 * 2 ;
F_8 ( V_2 , V_22 ) ;
}
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
#ifdef F_7
case 5 :
F_8 ( V_2 , V_23 ) ;
break;
#endif
case 6 :
if ( V_2 -> V_16 >= 0xf )
F_8 ( V_2 , V_24 ) ;
break;
}
#ifdef F_11
F_8 ( V_2 , V_25 ) ;
#endif
}
static void F_12 ( struct V_1 * V_2 )
{
#ifdef F_7
char * V_26 ;
T_1 V_27 = 0 ;
T_1 V_28 = 0 ;
T_1 V_3 , V_4 , V_29 ;
T_1 V_30 , V_31 , V_32 , V_33 ;
F_13 ( V_2 , 0 * 32 + 31 ) ;
#endif
F_10 ( V_2 ) ;
switch ( V_2 -> V_19 ) {
#ifdef F_7
case 5 :
switch ( V_2 -> V_16 ) {
case 4 :
V_26 = L_3 ;
V_27 = V_34 | V_35 | V_36 | V_37 | V_38 ;
V_28 = V_39 ;
F_14 ( L_4 ) ;
F_13 ( V_2 , V_40 ) ;
break;
case 8 :
switch ( V_2 -> V_41 ) {
default:
V_26 = L_5 ;
break;
case 7 ... 9 :
V_26 = L_6 ;
break;
case 10 ... 15 :
V_26 = L_7 ;
break;
}
V_27 = V_34 | V_35 | V_42 | V_37 | V_43 | V_38 |
V_44 | V_45 ;
V_28 = V_39 ;
break;
case 9 :
V_26 = L_8 ;
V_27 = V_34 | V_35 | V_42 | V_37 | V_43 | V_38 |
V_44 | V_45 ;
V_28 = V_39 ;
break;
default:
V_26 = L_9 ;
}
F_4 ( V_46 , V_3 , V_4 ) ;
V_29 = ( V_3 | V_27 ) & ( ~ V_28 ) ;
if ( V_29 != V_3 ) {
F_6 ( L_10 ,
V_3 , V_29 ) ;
F_5 ( V_46 , V_29 , V_4 ) ;
} else {
F_6 ( L_11 , V_3 ) ;
}
F_8 ( V_2 , V_23 ) ;
F_8 ( V_2 , V_17 ) ;
if ( V_2 -> V_16 >= 8 )
F_8 ( V_2 , V_18 ) ;
if ( F_2 ( 0x80000000 ) >= 0x80000005 ) {
F_15 ( 0x80000005 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
V_2 -> V_47 = ( V_32 >> 24 ) + ( V_33 >> 24 ) ;
}
sprintf ( V_2 -> V_48 , L_12 , V_26 ) ;
break;
#endif
case 6 :
F_1 ( V_2 ) ;
break;
}
#ifdef F_11
F_8 ( V_2 , V_49 ) ;
#endif
}
static unsigned int
F_16 ( struct V_1 * V_2 , unsigned int V_50 )
{
if ( ( V_2 -> V_19 == 6 ) && ( ( V_2 -> V_16 == 7 ) || ( V_2 -> V_16 == 8 ) ) )
V_50 >>= 8 ;
if ( ( V_2 -> V_19 == 6 ) && ( V_2 -> V_16 == 9 ) &&
( V_2 -> V_41 == 1 ) && ( V_50 == 65 ) )
V_50 -= 1 ;
return V_50 ;
}
