int
F_1 ( unsigned int V_1 , T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
if ( V_1 == 0 )
return 0 ;
if ( V_1 == 0xff )
V_3 = 0x9fffffff ;
else {
V_3 = 0 ;
if ( V_1 & ( 1 << 0 ) )
V_3 |= 0x90000000 ;
if ( V_1 & ( 1 << 1 ) )
V_3 |= 0x0f000000 ;
if ( V_1 & ( 1 << 2 ) )
V_3 |= 0x00f00000 ;
if ( V_1 & ( 1 << 3 ) )
V_3 |= 0x000f0000 ;
if ( V_1 & ( 1 << 4 ) )
V_3 |= 0x0000f000 ;
if ( V_1 & ( 1 << 5 ) )
V_3 |= 0x00000f00 ;
if ( V_1 & ( 1 << 6 ) )
V_3 |= 0x000000f0 ;
if ( V_1 & ( 1 << 7 ) )
V_3 |= 0x0000000f ;
}
V_5 &= ~ ( V_3 ) ;
V_5 |= ( V_2 [ 1 ] & V_3 ) ;
V_5 &= ~ ( V_6 ) ;
if ( V_5 & ( V_7 | V_8 | V_9 |
V_10 | V_11 | V_12 |
V_13 | V_14 | V_15 ) )
V_5 |= V_6 ;
V_4 = V_5 ;
V_4 &= ~ ( V_16 ) ;
if ( ( ( V_4 & V_6 ) && ( V_4 & V_17 ) ) ||
( ( V_4 & V_18 ) && ( V_4 & V_19 ) ) ||
( ( V_4 & V_20 ) && ( V_4 & V_21 ) ) ||
( ( V_4 & V_22 ) && ( V_4 & V_23 ) ) ||
( ( V_4 & V_24 ) && ( V_4 & V_25 ) ) )
V_4 |= V_16 ;
V_5 = V_4 ;
#ifdef F_2
F_3 ( L_1 , V_26 , V_1 , V_2 , V_5 ) ;
#endif
return 0 ;
}
