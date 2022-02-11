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
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_9 , V_4 ;
V_4 = V_2 -> V_4 % V_10 ;
V_9 = V_2 -> V_4 / V_10 ;
switch ( V_4 ) {
case V_11 :
V_3 = F_2 ( V_9 , 1 ) ;
break;
case V_12 :
V_3 = F_2 ( V_9 , 2 ) ;
break;
default:
F_3 ( L_2 , V_4 , V_9 ) ;
return;
}
F_4 ( V_3 , V_8 , 0xffffffff ) ;
}
static void F_6 ( int V_9 , int V_13 )
{
T_1 V_3 , V_14 , V_15 ;
void T_2 * V_16 ;
T_3 V_17 ;
V_3 = F_2 ( V_9 , V_13 ) ;
V_17 = F_7 ( V_3 , V_18 ) ;
V_17 &= ~ ( 0x3f << V_19 ) ;
V_17 |= ( 0x27 << V_19 ) ;
F_4 ( V_3 , V_18 , V_17 ) ;
V_17 = F_7 ( V_3 , V_20 ) ;
V_17 |= ( 1 << V_21 ) ;
F_4 ( V_3 , V_20 , V_17 ) ;
V_17 = F_7 ( V_3 , V_22 ) ;
V_17 &= ( V_23 | V_24 | V_25
| V_26 | V_27 ) ;
F_4 ( V_3 , V_22 , V_17 ) ;
V_17 = V_28 | V_29 | ( 1 << V_30 )
| ( 1 << V_31 ) | V_32 | V_33
| V_34 | V_35 ;
F_4 ( V_3 , V_36 , V_17 ) ;
F_4 ( V_3 , V_37 , 0x00000001 ) ;
F_4 ( V_3 , V_8 , 0xffffffff ) ;
F_8 ( 2000 ) ;
V_15 = F_9 ( V_9 , V_13 ) ;
V_14 = F_7 ( V_15 , 0x4 ) & ~ 0xf ;
V_16 = F_10 ( V_14 , 0x10000 ) ;
if ( ! V_16 )
return;
F_11 ( 0x240002 , V_16 + 0xc2c0 ) ;
V_17 = F_12 ( V_16 + 0xc110 ) ;
V_17 &= ~ ( 0x3 << 12 ) ;
V_17 |= ( 1 << 12 ) ;
F_11 ( V_17 , V_16 + 0xc110 ) ;
F_8 ( 100 ) ;
V_17 = F_12 ( V_16 + 0xc200 ) ;
V_17 &= ~ ( 1 << 6 ) ;
F_11 ( V_17 , V_16 + 0xc200 ) ;
F_8 ( 100 ) ;
V_17 = F_12 ( V_16 + 0xc2c0 ) ;
V_17 &= ~ ( 1 << 17 ) ;
F_11 ( V_17 , V_16 + 0xc2c0 ) ;
F_13 ( V_16 ) ;
}
static int T_4 F_14 ( void )
{
int V_9 ;
if ( ! F_15 () )
return 0 ;
if ( ! F_16 () ) {
F_17 ( L_3 ) ;
F_6 ( 0 , 1 ) ;
F_6 ( 0 , 2 ) ;
F_6 ( 0 , 3 ) ;
F_18 ( 0 , V_5 , F_1 ) ;
F_18 ( 0 , V_6 , F_1 ) ;
F_18 ( 0 , V_7 , F_1 ) ;
return 0 ;
}
F_17 ( L_4 ) ;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
if ( ! F_19 ( V_9 ) )
continue;
F_6 ( V_9 , 1 ) ;
F_6 ( V_9 , 2 ) ;
F_18 ( V_9 , V_11 , F_5 ) ;
F_18 ( V_9 , V_12 , F_5 ) ;
}
return 0 ;
}
static void F_20 ( struct V_39 * V_40 )
{
int V_9 ;
V_9 = F_21 ( V_40 ) ;
V_40 -> V_40 . V_41 = & V_42 ;
V_40 -> V_40 . V_43 = F_22 ( 32 ) ;
switch ( V_40 -> V_44 ) {
case 0x21 :
V_40 -> V_4 = F_23 ( V_9 , V_11 ) ;
break;
case 0x22 :
V_40 -> V_4 = F_23 ( V_9 , V_12 ) ;
break;
}
}
static void F_24 ( struct V_39 * V_40 )
{
V_40 -> V_40 . V_41 = & V_42 ;
V_40 -> V_40 . V_43 = F_22 ( 32 ) ;
switch ( V_40 -> V_44 ) {
case 0x21 :
V_40 -> V_4 = V_5 ;
break;
case 0x22 :
V_40 -> V_4 = V_6 ;
break;
case 0x23 :
V_40 -> V_4 = V_7 ;
break;
}
}
