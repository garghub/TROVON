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
if ( V_20 <= 0x13 )
F_22 () ;
else if ( V_21 == 0x3405 && V_20 == 0x22 )
F_22 () ;
}
static T_2 T_1 F_23 ( int V_1 , int V_2 , int V_3 , T_5 V_24 )
{
T_2 V_25 ;
V_25 = F_2 ( V_1 , V_2 , V_3 , 0x5c ) ;
V_25 &= ~ ( ( 1 << 20 ) - 1 ) ;
return V_25 ;
}
static T_5 T_1 F_24 ( void )
{
T_3 V_26 = F_13 ( 0 , 0 , 0 , V_27 ) ;
if ( ! ( V_26 & V_28 ) )
return 0 ;
if ( V_26 & V_29 )
return F_25 ( 1 ) ;
else
return F_26 ( 512 ) ;
}
static T_5 T_1 F_27 ( void )
{
T_3 V_26 = F_13 ( 0 , 0 , 0 , V_30 ) ;
if ( ! ( V_26 & V_28 ) )
return 0 ;
switch ( V_26 & V_31 ) {
case V_32 :
return F_26 ( 512 ) ;
case V_33 :
return F_25 ( 1 ) ;
default:
F_28 ( 1 ) ;
return 0 ;
}
}
static T_5 T_1 F_29 ( void )
{
T_3 V_26 = F_13 ( 0 , 0 , 0 , V_34 ) ;
if ( ! ( V_26 & V_28 ) )
return 0 ;
return F_25 ( 1 ) ;
}
static T_5 T_1 F_30 ( void )
{
return F_13 ( 0 , 0 , 0 , V_35 ) * F_25 ( 32 ) ;
}
static T_5 T_1 F_31 ( void )
{
return F_13 ( 0 , 0 , 1 , V_36 ) * F_25 ( 32 ) ;
}
static T_2 T_1 F_32 ( int V_1 , int V_2 , int V_3 , T_5 V_24 )
{
return F_30 () - F_24 () - V_24 ;
}
static T_2 T_1 F_33 ( int V_1 , int V_2 , int V_3 , T_5 V_24 )
{
return F_30 () - F_27 () - V_24 ;
}
static T_2 T_1 F_34 ( int V_1 , int V_2 , int V_3 , T_5 V_24 )
{
return F_31 () - F_29 () - V_24 ;
}
static T_2 T_1 F_35 ( int V_1 , int V_2 , int V_3 , T_5 V_24 )
{
return F_21 ( 0 , 0 , 0 , V_37 ) << 16 ;
}
static T_5 T_1 F_36 ( int V_1 , int V_2 , int V_3 )
{
T_5 V_24 ;
T_4 V_38 ;
V_38 = F_21 ( 0 , 0 , 0 , V_39 ) ;
switch ( V_38 & V_40 ) {
case V_41 :
V_24 = F_26 ( 512 ) ;
break;
case V_42 :
V_24 = F_25 ( 1 ) ;
break;
case V_43 :
V_24 = F_25 ( 8 ) ;
break;
case V_44 :
V_24 = 0 ;
break;
default:
return 0 ;
}
return V_24 ;
}
static T_5 T_1 F_37 ( int V_1 , int V_2 , int V_3 )
{
T_5 V_24 ;
T_4 V_38 ;
V_38 = F_21 ( 0 , 0 , 0 , V_39 ) ;
switch ( V_38 & V_45 ) {
case V_46 :
V_24 = F_25 ( 1 ) ;
break;
case V_47 :
V_24 = F_25 ( 4 ) ;
break;
case V_48 :
V_24 = F_25 ( 8 ) ;
break;
case V_49 :
V_24 = F_25 ( 16 ) ;
break;
case V_50 :
V_24 = F_25 ( 32 ) ;
break;
case V_51 :
V_24 = F_25 ( 48 ) ;
break;
case V_52 :
V_24 = F_25 ( 64 ) ;
break;
case V_53 :
V_24 = F_25 ( 128 ) ;
break;
case V_54 :
V_24 = F_25 ( 256 ) ;
break;
case V_55 :
V_24 = F_25 ( 96 ) ;
break;
case V_56 :
V_24 = F_25 ( 160 ) ;
break;
case V_57 :
V_24 = F_25 ( 224 ) ;
break;
case V_58 :
V_24 = F_25 ( 352 ) ;
break;
default:
V_24 = 0 ;
break;
}
return V_24 ;
}
static T_5 T_1 F_38 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_38 ;
V_38 = F_21 ( V_1 , V_2 , V_3 , V_59 ) ;
V_38 >>= V_60 ;
V_38 &= V_61 ;
return V_38 << 25 ;
}
static T_5 T_1 F_39 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_38 ;
V_38 = F_21 ( V_1 , V_2 , V_3 , V_59 ) ;
V_38 >>= V_62 ;
V_38 &= V_63 ;
return V_38 << 25 ;
}
static T_5 T_1 F_40 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_38 ;
V_38 = F_21 ( V_1 , V_2 , V_3 , V_59 ) ;
V_38 >>= V_60 ;
V_38 &= V_61 ;
if ( V_38 < 0x11 )
return V_38 << 25 ;
else if ( V_38 < 0x17 )
return ( V_38 - 0x11 + 2 ) << 22 ;
else
return ( V_38 - 0x17 + 9 ) << 22 ;
}
static T_5 T_1 F_41 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_38 ;
V_38 = F_21 ( V_1 , V_2 , V_3 , V_59 ) ;
V_38 >>= V_62 ;
V_38 &= V_63 ;
if ( V_38 < 0xf0 )
return V_38 << 25 ;
else
return ( V_38 - 0xf0 + 1 ) << 22 ;
}
static void T_1 F_42 ( int V_1 , int V_2 , int V_3 )
{
T_5 V_64 ;
int V_65 ;
T_2 V_66 ;
T_4 V_21 , V_67 , V_68 ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
V_67 = F_21 ( V_1 , V_2 , V_3 ,
V_69 ) ;
V_68 = F_21 ( V_1 , V_2 , V_3 , V_70 ) ;
for ( V_65 = 0 ; V_65 < F_43 ( V_71 ) ; V_65 ++ ) {
if ( V_71 [ V_65 ] . V_21 == V_21 ) {
const struct V_72 * V_73 =
( const struct V_72 * ) V_71 [ V_65 ] . V_74 ;
V_64 = V_73 -> V_64 ( V_1 , V_2 , V_3 ) ;
V_66 = V_73 -> V_25 ( V_1 , V_2 , V_3 , V_64 ) ;
if ( V_64 && V_66 ) {
F_3 ( V_5 L_17 ,
V_66 , V_66 + ( T_2 ) V_64 - 1 ) ;
F_44 ( V_66 , V_64 , V_75 ) ;
F_45 ( V_76 . V_77 ,
F_43 ( V_76 . V_77 ) ,
& V_76 . V_78 ) ;
}
return;
}
}
}
static void T_1 F_46 ( int V_1 , int V_2 , int V_3 )
{
#ifdef F_47
V_79 = true ;
F_48 ( L_18 ) ;
#endif
}
static int T_1 F_49 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_80 ;
T_4 V_81 ;
T_4 V_21 ;
T_3 type ;
int V_65 ;
V_80 = F_21 ( V_1 , V_2 , V_3 , V_82 ) ;
if ( V_80 == 0xffff )
return - 1 ;
V_81 = F_21 ( V_1 , V_2 , V_3 , V_83 ) ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
for ( V_65 = 0 ; V_84 [ V_65 ] . V_85 != NULL ; V_65 ++ ) {
if ( ( ( V_84 [ V_65 ] . V_81 == V_86 ) ||
( V_84 [ V_65 ] . V_81 == V_81 ) ) &&
( ( V_84 [ V_65 ] . V_21 == V_86 ) ||
( V_84 [ V_65 ] . V_21 == V_21 ) ) &&
( ! ( ( V_84 [ V_65 ] . V_80 ^ V_80 ) &
V_84 [ V_65 ] . V_87 ) ) ) {
if ( ( V_84 [ V_65 ] . V_88 &
V_89 ) != V_89 )
V_84 [ V_65 ] . V_85 ( V_1 , V_2 , V_3 ) ;
V_84 [ V_65 ] . V_88 |= V_90 ;
}
}
type = F_13 ( V_1 , V_2 , V_3 ,
V_91 ) ;
if ( ! ( type & 0x80 ) )
return - 1 ;
return 0 ;
}
void T_1 F_50 ( void )
{
int V_2 , V_3 ;
if ( ! F_51 () )
return;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ )
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_49 ( 0 , V_2 , V_3 ) )
break;
}
}
