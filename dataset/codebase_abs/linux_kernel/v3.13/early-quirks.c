static void T_1 F_1 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 , V_2 , V_3 , 0x68 ) ;
if ( V_4 & ( 1 << 18 ) ) {
F_3 ( V_5 L_1
L_2 ) ;
if ( ( V_4 & ( 1 << 17 ) ) == 0 ) {
F_3 ( V_5 L_3
L_4 ) ;
F_3 ( V_5 L_5
L_6 ) ;
V_4 |= ( 1 << 17 ) ;
F_4 ( V_1 , V_2 , V_3 , 0x68 , V_4 ) ;
}
}
}
static void T_1 F_5 ( int V_1 , int V_2 , int V_3 )
{
#ifdef F_6
if ( ( V_6 > V_7 || V_8 ) &&
! V_9 ) {
F_3 ( V_5
L_7
L_8 ) ;
V_10 = 1 ;
}
#endif
}
static int T_1 F_7 ( struct V_11 * V_12 )
{
return 0 ;
}
static void T_1 F_8 ( int V_1 , int V_2 , int V_3 )
{
#ifdef F_9
#ifdef F_10
if ( V_13 )
return;
if ( F_11 ( V_14 , F_7 ) ) {
V_15 = 1 ;
F_3 ( V_5 L_9
L_10
L_11 ) ;
F_3 ( V_5 L_12
L_13 ) ;
}
#endif
#endif
}
static T_2 T_1 F_12 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 ;
T_3 V_17 ;
V_17 = F_13 ( V_1 , V_2 , V_3 , 0xac ) ;
V_17 &= ~ ( 1 << 5 ) ;
F_14 ( V_1 , V_2 , V_3 , 0xac , V_17 ) ;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x70 ) ;
V_16 |= 1 << 8 ;
F_4 ( V_1 , V_2 , V_3 , 0x70 , V_16 ) ;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x8 ) ;
V_16 &= 0xff ;
return V_16 ;
}
static void T_1 F_15 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 ;
T_3 V_17 ;
if ( V_13 )
return;
V_16 = F_12 ( V_1 , V_2 , V_3 ) ;
if ( V_16 < 0x82 )
V_15 = 1 ;
else {
F_16 ( 0x72 , 0xcd6 ) ; V_17 = F_17 ( 0xcd7 ) ;
if ( ! ( V_17 & 0x2 ) )
V_15 = 1 ;
}
if ( V_15 ) {
F_3 ( V_5 L_14 , V_16 ) ;
F_3 ( V_5 L_15 ) ;
F_3 ( V_5 L_12
L_13 ) ;
}
}
static T_2 T_1 F_18 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 ;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x8 ) ;
V_16 &= 0xff ;
return V_16 ;
}
static void T_1 F_19 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 , V_18 ;
V_18 = F_18 ( V_1 , V_2 , V_3 ) ;
if ( V_18 >= 0x40 )
V_19 = 1 ;
if ( V_18 >= 0x39 )
return;
if ( V_13 )
return;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x64 ) ;
if ( ! ( V_16 & ( 1 << 14 ) ) )
V_15 = 1 ;
if ( V_15 ) {
F_3 ( V_5 L_16 , V_18 ) ;
F_3 ( V_5 L_15 ) ;
F_3 ( V_5 L_12
L_13 ) ;
}
}
static void T_1 F_15 ( int V_1 , int V_2 , int V_3 )
{
}
static void T_1 F_19 ( int V_1 , int V_2 , int V_3 )
{
}
static void T_1 F_20 ( int V_1 , int V_2 , int V_3 )
{
T_3 V_20 ;
T_4 V_21 ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
V_20 = F_13 ( V_1 , V_2 , V_3 , V_23 ) ;
if ( V_20 == 0x13 )
F_22 () ;
else if ( ( V_21 == 0x3405 ) &&
( ( V_20 == 0x12 ) ||
( V_20 == 0x22 ) ) )
F_22 () ;
}
static T_2 T_1 F_23 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_24 ;
V_24 = F_2 ( V_1 , V_2 , V_3 , 0x5c ) ;
V_24 &= ~ ( ( 1 << 20 ) - 1 ) ;
return V_24 ;
}
static T_5 T_1 F_24 ( int V_1 , int V_2 , int V_3 )
{
T_5 V_25 ;
T_4 V_26 ;
V_26 = F_21 ( 0 , 0 , 0 , V_27 ) ;
switch ( V_26 & V_28 ) {
case V_29 :
V_25 = F_25 ( 1 ) ;
break;
case V_30 :
V_25 = F_25 ( 4 ) ;
break;
case V_31 :
V_25 = F_25 ( 8 ) ;
break;
case V_32 :
V_25 = F_25 ( 16 ) ;
break;
case V_33 :
V_25 = F_25 ( 32 ) ;
break;
case V_34 :
V_25 = F_25 ( 48 ) ;
break;
case V_35 :
V_25 = F_25 ( 64 ) ;
break;
case V_36 :
V_25 = F_25 ( 128 ) ;
break;
case V_37 :
V_25 = F_25 ( 256 ) ;
break;
case V_38 :
V_25 = F_25 ( 96 ) ;
break;
case V_39 :
V_25 = F_25 ( 160 ) ;
break;
case V_40 :
V_25 = F_25 ( 224 ) ;
break;
case V_41 :
V_25 = F_25 ( 352 ) ;
break;
default:
V_25 = 0 ;
break;
}
return V_25 ;
}
static T_5 T_1 F_26 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_26 ;
V_26 = F_21 ( V_1 , V_2 , V_3 , V_42 ) ;
V_26 >>= V_43 ;
V_26 &= V_44 ;
return V_26 << 25 ;
}
static inline T_5 F_27 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_26 ;
V_26 = F_21 ( V_1 , V_2 , V_3 , V_42 ) ;
V_26 >>= V_45 ;
V_26 &= V_46 ;
return V_26 << 25 ;
}
static void T_1 F_28 ( int V_1 , int V_2 , int V_3 )
{
T_5 V_47 ;
int V_48 ;
T_2 V_49 ;
T_4 V_21 , V_50 , V_51 ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
V_50 = F_21 ( V_1 , V_2 , V_3 ,
V_52 ) ;
V_51 = F_21 ( V_1 , V_2 , V_3 , V_53 ) ;
for ( V_48 = 0 ; V_48 < F_29 ( V_54 ) ; V_48 ++ ) {
if ( V_54 [ V_48 ] . V_21 == V_21 ) {
T_6 V_25 =
( T_6 ) V_54 [ V_48 ] . V_55 ;
V_47 = V_25 ( V_1 , V_2 , V_3 ) ;
V_49 = F_23 ( V_1 , V_2 , V_3 ) ;
if ( V_47 && V_49 ) {
F_30 ( V_49 , V_47 , V_56 ) ;
F_31 ( V_57 . V_58 ,
F_29 ( V_57 . V_58 ) ,
& V_57 . V_59 ) ;
}
return;
}
}
}
static int T_1 F_32 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_60 ;
T_4 V_61 ;
T_4 V_21 ;
T_3 type ;
int V_48 ;
V_60 = F_21 ( V_1 , V_2 , V_3 , V_62 ) ;
if ( V_60 == 0xffff )
return - 1 ;
V_61 = F_21 ( V_1 , V_2 , V_3 , V_63 ) ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
for ( V_48 = 0 ; V_64 [ V_48 ] . V_65 != NULL ; V_48 ++ ) {
if ( ( ( V_64 [ V_48 ] . V_61 == V_66 ) ||
( V_64 [ V_48 ] . V_61 == V_61 ) ) &&
( ( V_64 [ V_48 ] . V_21 == V_66 ) ||
( V_64 [ V_48 ] . V_21 == V_21 ) ) &&
( ! ( ( V_64 [ V_48 ] . V_60 ^ V_60 ) &
V_64 [ V_48 ] . V_67 ) ) ) {
if ( ( V_64 [ V_48 ] . V_68 &
V_69 ) != V_69 )
V_64 [ V_48 ] . V_65 ( V_1 , V_2 , V_3 ) ;
V_64 [ V_48 ] . V_68 |= V_70 ;
}
}
type = F_13 ( V_1 , V_2 , V_3 ,
V_71 ) ;
if ( ! ( type & 0x80 ) )
return - 1 ;
return 0 ;
}
void T_1 F_33 ( void )
{
int V_2 , V_3 ;
if ( ! F_34 () )
return;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ )
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_32 ( 0 , V_2 , V_3 ) )
break;
}
}
