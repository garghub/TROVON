static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_3 = F_2 ( 0 , 1 ) ;
break;
case V_6 :
V_3 = F_2 ( 0 , 2 ) ;
break;
case V_7 :
V_3 = F_2 ( 0 , 3 ) ;
break;
default:
F_3 ( L_1 ) ;
return;
}
F_4 ( V_3 , V_8 , 0xffffffff ) ;
}
static void F_5 ( int V_9 , int V_10 )
{
T_1 V_3 , V_11 , V_12 ;
void T_2 * V_13 ;
T_3 V_14 ;
V_3 = F_2 ( V_9 , V_10 ) ;
V_14 = F_6 ( V_3 , V_15 ) ;
V_14 &= ~ ( 0x3f << V_16 ) ;
V_14 |= ( 0x27 << V_16 ) ;
F_4 ( V_3 , V_15 , V_14 ) ;
V_14 = F_6 ( V_3 , V_17 ) ;
V_14 |= ( 1 << V_18 ) ;
F_4 ( V_3 , V_17 , V_14 ) ;
V_14 = F_6 ( V_3 , V_19 ) ;
V_14 &= ( V_20 | V_21 | V_22
| V_23 | V_24 ) ;
F_4 ( V_3 , V_19 , V_14 ) ;
V_14 = V_25 | V_26 | ( 1 << V_27 )
| ( 1 << V_28 ) | V_29 | V_30
| V_31 | V_32 ;
F_4 ( V_3 , V_33 , V_14 ) ;
F_4 ( V_3 , V_34 , 0x00000001 ) ;
F_4 ( V_3 , V_8 , 0xffffffff ) ;
F_7 ( 2000 ) ;
V_12 = F_8 ( V_9 , V_10 ) ;
V_11 = F_6 ( V_12 , 0x4 ) & ~ 0xf ;
V_13 = F_9 ( V_11 , 0x10000 ) ;
if ( ! V_13 )
return;
F_10 ( 0x240002 , V_13 + 0xc2c0 ) ;
V_14 = F_11 ( V_13 + 0xc110 ) ;
V_14 &= ~ ( 0x3 << 12 ) ;
V_14 |= ( 1 << 12 ) ;
F_10 ( V_14 , V_13 + 0xc110 ) ;
F_7 ( 100 ) ;
V_14 = F_11 ( V_13 + 0xc200 ) ;
V_14 &= ~ ( 1 << 6 ) ;
F_10 ( V_14 , V_13 + 0xc200 ) ;
F_7 ( 100 ) ;
V_14 = F_11 ( V_13 + 0xc2c0 ) ;
V_14 &= ~ ( 1 << 17 ) ;
F_10 ( V_14 , V_13 + 0xc2c0 ) ;
F_12 ( V_13 ) ;
}
static int T_4 F_13 ( void )
{
if ( ! F_14 () )
return 0 ;
F_15 ( L_2 ) ;
F_5 ( 0 , 1 ) ;
F_5 ( 0 , 2 ) ;
F_5 ( 0 , 3 ) ;
F_16 ( 0 , V_5 , F_1 ) ;
F_16 ( 0 , V_6 , F_1 ) ;
F_16 ( 0 , V_7 , F_1 ) ;
return 0 ;
}
static void F_17 ( struct V_35 * V_36 )
{
V_36 -> V_36 . V_37 = & V_38 ;
V_36 -> V_36 . V_39 = F_18 ( 32 ) ;
switch ( V_36 -> V_40 ) {
case 0x21 :
V_36 -> V_4 = V_5 ;
break;
case 0x22 :
V_36 -> V_4 = V_6 ;
break;
case 0x23 :
V_36 -> V_4 = V_7 ;
break;
}
}
