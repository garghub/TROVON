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
if ( V_1 )
return;
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
static T_5 T_1 F_23 ( void )
{
T_3 V_24 = F_13 ( 0 , 0 , 0 , V_25 ) ;
if ( ! ( V_24 & V_26 ) )
return 0 ;
if ( V_24 & V_27 )
return F_24 ( 1 ) ;
else
return F_25 ( 512 ) ;
}
static T_5 T_1 F_26 ( void )
{
T_3 V_24 = F_13 ( 0 , 0 , 0 , V_28 ) ;
T_3 V_29 = V_24 & V_30 ;
if ( ! ( V_24 & V_26 ) )
return 0 ;
switch ( V_29 ) {
case V_31 : return F_25 ( 512 ) ;
case V_32 : return F_24 ( 1 ) ;
default:
F_27 ( 1 , L_17 , V_24 ) ;
}
return 0 ;
}
static T_5 T_1 F_28 ( void )
{
T_3 V_24 = F_13 ( 0 , 0 , 0 , V_33 ) ;
if ( ! ( V_24 & V_26 ) )
return 0 ;
return F_24 ( 1 ) ;
}
static T_5 T_1 F_29 ( void )
{
return F_13 ( 0 , 0 , 0 , V_34 ) * F_24 ( 32 ) ;
}
static T_5 T_1 F_30 ( void )
{
return F_13 ( 0 , 0 , 1 , V_35 ) * F_24 ( 32 ) ;
}
static T_6 T_1 F_31 ( int V_1 , int V_2 , int V_3 ,
T_5 V_36 )
{
return ( T_6 ) F_29 () - F_23 () - V_36 ;
}
static T_6 T_1 F_32 ( int V_1 , int V_2 , int V_3 ,
T_5 V_36 )
{
return ( T_6 ) F_29 () - F_26 () - V_36 ;
}
static T_6 T_1 F_33 ( int V_1 , int V_2 , int V_3 ,
T_5 V_36 )
{
return ( T_6 ) F_30 () - F_28 () - V_36 ;
}
static T_6 T_1 F_34 ( int V_1 , int V_2 , int V_3 ,
T_5 V_36 )
{
T_4 V_37 = 0 ;
V_37 = F_21 ( 0 , 0 , 0 , V_38 ) ;
return ( T_6 ) ( V_37 << 16 ) + F_26 () ;
}
static T_6 T_1 F_35 ( int V_1 , int V_2 , int V_3 ,
T_5 V_36 )
{
T_2 V_39 ;
V_39 = F_2 ( V_1 , V_2 , V_3 , V_40 ) ;
return ( T_6 ) V_39 & V_41 ;
}
static T_5 T_1 F_36 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_42 ;
T_4 V_43 ;
V_42 = F_21 ( 0 , 0 , 0 , V_44 ) ;
V_43 = V_42 & V_45 ;
switch ( V_43 ) {
case V_46 : return F_25 ( 512 ) ;
case V_47 : return F_24 ( 1 ) ;
case V_48 : return F_24 ( 8 ) ;
case V_49 : return 0 ;
default:
F_27 ( 1 , L_18 , V_42 ) ;
}
return 0 ;
}
static T_5 T_1 F_37 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_42 ;
T_4 V_43 ;
V_42 = F_21 ( 0 , 0 , 0 , V_44 ) ;
V_43 = V_42 & V_50 ;
switch ( V_43 ) {
case V_51 : return F_24 ( 1 ) ;
case V_52 : return F_24 ( 4 ) ;
case V_53 : return F_24 ( 8 ) ;
case V_54 : return F_24 ( 16 ) ;
case V_55 : return F_24 ( 32 ) ;
case V_56 : return F_24 ( 48 ) ;
case V_57 : return F_24 ( 64 ) ;
case V_58 : return F_24 ( 128 ) ;
case V_59 : return F_24 ( 256 ) ;
case V_60 : return F_24 ( 96 ) ;
case V_61 : return F_24 ( 160 ) ;
case V_62 : return F_24 ( 224 ) ;
case V_63 : return F_24 ( 352 ) ;
default:
F_27 ( 1 , L_18 , V_42 ) ;
}
return 0 ;
}
static T_5 T_1 F_38 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_42 ;
T_4 V_43 ;
V_42 = F_21 ( V_1 , V_2 , V_3 , V_64 ) ;
V_43 = ( V_42 >> V_65 ) & V_66 ;
return ( T_5 ) V_43 * F_24 ( 32 ) ;
}
static T_5 T_1 F_39 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_42 ;
T_4 V_43 ;
V_42 = F_21 ( V_1 , V_2 , V_3 , V_64 ) ;
V_43 = ( V_42 >> V_67 ) & V_68 ;
return ( T_5 ) V_43 * F_24 ( 32 ) ;
}
static T_5 T_1 F_40 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_42 ;
T_4 V_43 ;
V_42 = F_21 ( V_1 , V_2 , V_3 , V_64 ) ;
V_43 = ( V_42 >> V_65 ) & V_66 ;
if ( V_43 < 0x11 )
return ( T_5 ) V_43 * F_24 ( 32 ) ;
else if ( V_43 < 0x17 )
return ( T_5 ) ( V_43 - 0x11 + 2 ) * F_24 ( 4 ) ;
else
return ( T_5 ) ( V_43 - 0x17 + 9 ) * F_24 ( 4 ) ;
}
static T_5 T_1 F_41 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_42 ;
T_4 V_43 ;
V_42 = F_21 ( V_1 , V_2 , V_3 , V_64 ) ;
V_43 = ( V_42 >> V_67 ) & V_68 ;
if ( V_43 < 0xf0 )
return ( T_5 ) V_43 * F_24 ( 32 ) ;
else
return ( T_5 ) ( V_43 - 0xf0 + 1 ) * F_24 ( 4 ) ;
}
static void T_1
F_42 ( int V_1 , int V_2 , int V_3 ,
const struct V_69 * V_70 )
{
T_6 V_71 , V_72 ;
T_5 V_73 ;
V_73 = V_70 -> V_36 ( V_1 , V_2 , V_3 ) ;
V_71 = V_70 -> V_74 ( V_1 , V_2 , V_3 , V_73 ) ;
if ( ! V_73 || ! V_71 )
return;
V_72 = V_71 + V_73 - 1 ;
F_3 ( V_5 L_19 ,
& V_71 , & V_72 ) ;
F_43 ( V_71 , V_73 , V_75 ) ;
F_44 ( V_76 -> V_77 , F_45 ( V_76 -> V_77 ) , & V_76 -> V_78 ) ;
}
static void T_1 F_46 ( int V_1 , int V_2 , int V_3 )
{
const struct V_69 * V_70 ;
T_4 V_21 ;
int V_79 ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
for ( V_79 = 0 ; V_79 < F_45 ( V_80 ) ; V_79 ++ ) {
T_7 V_81 = V_80 [ V_79 ] . V_81 ;
if ( V_80 [ V_79 ] . V_21 != V_21 )
continue;
V_70 = ( F_47 ( V_70 ) ) V_81 ;
F_42 ( V_1 , V_2 , V_3 , V_70 ) ;
return;
}
}
static void T_1 F_48 ( int V_1 , int V_2 , int V_3 )
{
#ifdef F_49
V_82 = true ;
F_50 ( L_20 ) ;
#endif
}
static void T_1 F_51 ( int V_83 , int V_2 , int V_3 )
{
void T_8 * V_84 ;
T_4 V_85 ;
T_9 V_86 ;
int V_79 ;
if ( ! F_52 ( V_87 , L_21 ) )
return;
V_85 = F_21 ( V_83 , V_2 , V_3 , V_88 + V_89 ) ;
if ( ( V_85 & V_90 ) != V_91 ) {
V_85 &= ~ V_90 ;
F_53 ( V_83 , V_2 , V_3 , V_88 + V_89 , V_85 ) ;
F_54 ( 10 ) ;
V_85 = F_21 ( V_83 , V_2 , V_3 , V_88 + V_89 ) ;
if ( ( V_85 & V_90 ) != V_91 ) {
F_55 ( L_22 ) ;
return;
}
}
V_86 = F_2 ( V_83 , V_2 , V_3 , V_92 ) ;
V_86 |= ( T_9 ) F_2 ( V_83 , V_2 , V_3 , V_93 ) << 32 ;
V_86 &= V_94 ;
V_84 = F_56 ( V_86 , V_95 ) ;
if ( ! V_84 ) {
F_55 ( L_23 ) ;
return;
}
F_50 ( L_24 ) ;
for ( V_79 = 0 ; F_57 ( V_96 ) && V_79 < 30 ; V_79 ++ )
F_58 ( 10 ) ;
F_59 ( V_97 , V_98 ) ;
F_57 ( V_97 ) ;
F_58 ( 1 ) ;
F_59 ( V_97 , 0 ) ;
F_57 ( V_97 ) ;
F_58 ( 10 ) ;
F_60 ( V_84 , V_95 ) ;
}
static int T_1 F_61 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_99 ;
T_4 V_100 ;
T_4 V_21 ;
T_3 type ;
T_3 V_101 ;
int V_79 ;
V_99 = F_21 ( V_1 , V_2 , V_3 , V_102 ) ;
if ( V_99 == 0xffff )
return - 1 ;
V_100 = F_21 ( V_1 , V_2 , V_3 , V_103 ) ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
for ( V_79 = 0 ; V_104 [ V_79 ] . V_105 != NULL ; V_79 ++ ) {
if ( ( ( V_104 [ V_79 ] . V_100 == V_106 ) ||
( V_104 [ V_79 ] . V_100 == V_100 ) ) &&
( ( V_104 [ V_79 ] . V_21 == V_106 ) ||
( V_104 [ V_79 ] . V_21 == V_21 ) ) &&
( ! ( ( V_104 [ V_79 ] . V_99 ^ V_99 ) &
V_104 [ V_79 ] . V_107 ) ) ) {
if ( ( V_104 [ V_79 ] . V_108 &
V_109 ) != V_109 )
V_104 [ V_79 ] . V_105 ( V_1 , V_2 , V_3 ) ;
V_104 [ V_79 ] . V_108 |= V_110 ;
}
}
type = F_13 ( V_1 , V_2 , V_3 ,
V_111 ) ;
if ( ( type & 0x7f ) == V_112 ) {
V_101 = F_13 ( V_1 , V_2 , V_3 , V_113 ) ;
if ( V_101 > V_1 )
F_62 ( V_101 ) ;
}
if ( ! ( type & 0x80 ) )
return - 1 ;
return 0 ;
}
static void T_1 F_62 ( int V_83 )
{
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ )
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_61 ( V_83 , V_2 , V_3 ) )
break;
}
}
void T_1 F_63 ( void )
{
if ( ! F_64 () )
return;
F_62 ( 0 ) ;
}
