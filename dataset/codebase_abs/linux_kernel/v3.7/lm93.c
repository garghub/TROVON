static int F_1 ( T_1 V_1 )
{
return F_2 ( ( V_1 & 0x3f ) , 100 ) ;
}
static unsigned F_3 ( int V_2 , T_1 V_1 )
{
const long V_3 = V_4 [ V_2 ] * 1000 ;
const long V_5 = V_6 [ V_2 ] * 1000 ;
const long V_7 = ( V_3 - V_5 ) /
( V_8 [ V_2 ] - V_9 [ V_2 ] ) ;
const long V_10 = V_5 - V_7 * V_9 [ V_2 ] ;
return ( V_7 * V_1 + V_10 + 500 ) / 1000 ;
}
static T_1 F_4 ( int V_2 , unsigned V_11 )
{
const long V_12 = F_5 ( V_11 ,
V_6 [ V_2 ] , V_4 [ V_2 ] ) ;
const long V_13 = V_12 * 1000 ;
const long V_3 = V_4 [ V_2 ] * 1000 ;
const long V_5 = V_6 [ V_2 ] * 1000 ;
const long V_7 = ( V_3 - V_5 ) /
( V_8 [ V_2 ] - V_9 [ V_2 ] ) ;
const long V_10 = V_5 - V_7 * V_9 [ V_2 ] ;
T_1 V_14 = ( ( V_13 - V_10 + ( V_7 / 2 ) ) / V_7 ) ;
V_14 = F_5 ( V_14 ,
V_9 [ V_2 ] , V_8 [ V_2 ] ) ;
return V_14 ;
}
static unsigned F_6 ( T_1 V_1 , int V_15 , int V_16 )
{
const long V_17 = V_15 ? ( ( ( V_1 >> 4 & 0x0f ) + 1 ) * 12500 ) :
( ( ( V_1 >> 0 & 0x0f ) + 1 ) * - 25000 ) ;
const long V_18 = V_16 * 1000 ;
return ( V_18 + V_17 + 5000 ) / 10000 ;
}
static T_1 F_7 ( unsigned V_11 , int V_15 , int V_16 )
{
long V_17 = V_16 * 1000 - V_11 * 10000 ;
if ( V_15 ) {
V_17 = F_5 ( V_17 , 12500 , 200000 ) ;
return ( T_1 ) ( ( V_17 / 12500 - 1 ) << 4 ) ;
} else {
V_17 = F_5 ( V_17 , - 400000 , - 25000 ) ;
return ( T_1 ) ( ( V_17 / - 25000 - 1 ) << 0 ) ;
}
}
static int F_8 ( T_1 V_1 )
{
return ( V_19 ) V_1 * 1000 ;
}
static T_1 F_9 ( long V_20 )
{
int V_21 = F_5 ( V_20 , V_22 , V_23 ) ;
V_21 += ( V_21 < 0 ? - 500 : 500 ) ;
return ( T_1 ) ( V_21 / 1000 ) ;
}
static int F_10 ( T_1 V_24 , int V_2 )
{
return V_24 & ( V_2 < 2 ? 0x10 : 0x20 ) ;
}
static int F_11 ( T_1 V_1 , int V_25 )
{
return ( V_1 & 0x0f ) * ( V_25 ? 5 : 10 ) ;
}
static T_1 F_12 ( int V_26 , int V_25 )
{
int V_27 = V_25 ? 5 : 10 ;
V_26 = F_5 ( V_26 , V_28 ,
V_25 ? V_29 : V_30 ) ;
return ( T_1 ) ( ( V_26 + V_27 / 2 ) / V_27 ) ;
}
static int F_13 ( T_1 V_1 , int V_2 , int V_25 )
{
if ( V_2 < 2 )
return F_11 ( V_1 & 0x0f , V_25 ) ;
else
return F_11 ( V_1 >> 4 & 0x0f , V_25 ) ;
}
static T_1 F_14 ( T_1 V_31 , int V_26 , int V_2 , int V_25 )
{
T_1 V_32 = F_12 ( V_26 , V_25 ) ;
if ( V_2 < 2 )
return ( V_31 & 0xf0 ) | ( V_32 & 0x0f ) ;
else
return ( V_32 << 4 & 0xf0 ) | ( V_31 & 0x0f ) ;
}
static int F_15 ( struct V_33 * V_34 , int V_2 ,
int V_25 )
{
T_1 V_1 ;
switch ( V_2 ) {
case 0 :
V_1 = V_34 -> V_35 [ 0 ] & 0x0f ;
break;
case 1 :
V_1 = V_34 -> V_35 [ 0 ] >> 4 & 0x0f ;
break;
case 2 :
V_1 = V_34 -> V_35 [ 1 ] & 0x0f ;
break;
case 3 :
default:
V_1 = V_34 -> V_35 [ 1 ] >> 4 & 0x0f ;
break;
}
return F_8 ( V_34 -> V_36 [ V_2 ] ) -
F_11 ( V_1 , V_25 ) ;
}
static T_1 F_16 ( struct V_33 * V_34 , long V_37 ,
int V_2 , int V_25 )
{
T_1 V_1 = F_12 (
( F_8 ( V_34 -> V_36 [ V_2 ] ) - V_37 ) , V_25 ) ;
switch ( V_2 ) {
case 0 :
V_1 = ( V_34 -> V_35 [ 0 ] & 0xf0 ) | ( V_1 & 0x0f ) ;
break;
case 1 :
V_1 = ( V_1 << 4 & 0xf0 ) | ( V_34 -> V_35 [ 0 ] & 0x0f ) ;
break;
case 2 :
V_1 = ( V_34 -> V_35 [ 1 ] & 0xf0 ) | ( V_1 & 0x0f ) ;
break;
case 3 :
default:
V_1 = ( V_1 << 4 & 0xf0 ) | ( V_34 -> V_35 [ 1 ] & 0x0f ) ;
break;
}
return V_1 ;
}
static int F_17 ( T_1 V_1 , enum V_38 V_39 )
{
return V_40 [ V_39 ] [ V_1 & 0x0f ] ;
}
static T_1 F_18 ( int V_41 , enum V_38 V_39 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < 13 ; V_42 ++ )
if ( V_41 <= V_40 [ V_39 ] [ V_42 ] )
break;
return ( T_1 ) V_42 ;
}
static int F_19 ( T_2 V_43 )
{
const T_2 V_44 = F_20 ( V_43 ) >> 2 ;
return V_44 == 0 ? - 1 : V_44 == 0x3fff ? 0 : 1350000 / V_44 ;
}
static T_2 F_21 ( long V_45 )
{
T_2 V_44 , V_43 ;
if ( V_45 == 0 ) {
V_44 = 0x3fff ;
} else {
V_45 = F_5 ( V_45 , 1 , 1000000 ) ;
V_44 = F_5 ( ( 1350000 + V_45 ) / V_45 , 1 , 0x3ffe ) ;
}
V_43 = V_44 << 2 ;
return F_22 ( V_43 ) ;
}
static int F_23 ( T_1 V_1 )
{
return V_46 [ V_1 & 0x07 ] ;
}
static T_1 F_24 ( int V_39 )
{
int V_42 ;
for ( V_42 = 7 ; V_42 > 0 ; V_42 -- )
if ( V_39 <= V_46 [ V_42 ] )
break;
return ( T_1 ) V_42 ;
}
static int F_25 ( T_1 V_1 )
{
return V_47 [ V_1 >> 5 & 0x07 ] ;
}
static T_1 F_26 ( int time )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < 7 ; V_42 ++ )
if ( time <= V_47 [ V_42 ] )
break;
return ( T_1 ) V_42 ;
}
static int F_27 ( T_1 V_1 )
{
return ( V_1 & 0x0f ) * 5 ;
}
static T_1 F_28 ( int V_48 )
{
V_48 = F_5 ( V_48 , V_49 , V_50 ) ;
return ( T_1 ) ( ( V_48 + 2 ) / 5 ) ;
}
static T_1 F_29 ( long V_51 )
{
V_51 = F_5 ( V_51 , 0 , 255 ) ;
return ( T_1 ) V_51 ;
}
static int F_30 ( T_1 V_1 )
{
return V_52 [ V_1 & 0x0f ] ;
}
static T_1 F_31 ( long V_53 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < 9 ; V_42 ++ )
if ( V_53 <= V_52 [ V_42 ] )
break;
return ( T_1 ) V_42 ;
}
static unsigned F_32 ( T_1 V_1 )
{
return ~ V_1 & 0xff ;
}
static unsigned F_33 ( struct V_54 V_55 )
{
unsigned V_14 ;
V_14 = V_55 . V_56 & 0x3f ;
if ( V_57 [ 0 ] )
V_14 |= ( V_55 . V_58 & 0x10 ) << 2 ;
else
V_14 |= V_55 . V_56 & 0x40 ;
if ( V_57 [ 1 ] )
V_14 |= ( V_55 . V_58 & 0x20 ) << 2 ;
else
V_14 |= V_55 . V_56 & 0x80 ;
V_14 |= V_55 . V_59 << 8 ;
V_14 |= ( V_55 . V_60 & 0x0f ) << 16 ;
V_14 |= ( V_55 . V_61 & 0x80 ) << 13 ;
V_14 |= ( V_55 . V_62 & 0x80 ) << 14 ;
V_14 |= ( V_55 . V_58 & 0xfc ) << 20 ;
V_14 |= ( V_55 . V_63 & 0x07 ) << 28 ;
return V_14 ;
}
static T_1 F_34 ( struct V_64 * V_65 , T_1 V_1 )
{
int V_66 , V_42 ;
for ( V_42 = 1 ; V_42 <= V_67 ; V_42 ++ ) {
V_66 = F_35 ( V_65 , V_1 ) ;
if ( V_66 >= 0 ) {
return V_66 ;
} else {
F_36 ( & V_65 -> V_68 , L_1
L_2 , V_1 ) ;
F_37 ( V_42 + 3 ) ;
}
}
F_38 ( & V_65 -> V_68 , L_3 ) ;
return 0 ;
}
static int F_39 ( struct V_64 * V_65 , T_1 V_1 , T_1 V_66 )
{
int V_14 ;
V_14 = F_40 ( V_65 , V_1 , V_66 ) ;
if ( V_14 < 0 )
F_36 ( & V_65 -> V_68 , L_4
L_5 , V_66 , V_1 ) ;
return V_14 ;
}
static T_2 F_41 ( struct V_64 * V_65 , T_1 V_1 )
{
int V_66 , V_42 ;
for ( V_42 = 1 ; V_42 <= V_67 ; V_42 ++ ) {
V_66 = F_42 ( V_65 , V_1 ) ;
if ( V_66 >= 0 ) {
return V_66 ;
} else {
F_36 ( & V_65 -> V_68 , L_6
L_2 , V_1 ) ;
F_37 ( V_42 + 3 ) ;
}
}
F_38 ( & V_65 -> V_68 , L_7 ) ;
return 0 ;
}
static int F_43 ( struct V_64 * V_65 , T_1 V_1 , T_2 V_66 )
{
int V_14 ;
V_14 = F_44 ( V_65 , V_1 , V_66 ) ;
if ( V_14 < 0 )
F_36 ( & V_65 -> V_68 , L_8
L_9 , V_66 , V_1 ) ;
return V_14 ;
}
static void F_45 ( struct V_64 * V_65 , T_1 V_69 , T_1 * V_70 )
{
int V_42 , V_14 = 0 ;
for ( V_42 = 1 ; V_42 <= V_67 ; V_42 ++ ) {
V_14 = F_46 ( V_65 ,
V_71 [ V_69 ] . V_72 , V_73 ) ;
if ( V_14 == V_71 [ V_69 ] . V_74 ) {
break;
} else {
F_36 ( & V_65 -> V_68 , L_10
L_11 ,
V_71 [ V_69 ] . V_72 ) ;
F_37 ( V_42 + 3 ) ;
}
}
if ( V_14 == V_71 [ V_69 ] . V_74 ) {
memcpy ( V_70 , V_73 ,
V_71 [ V_69 ] . V_74 ) ;
} else {
}
}
static struct V_33 * F_47 ( struct V_75 * V_68 )
{
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
const unsigned long V_53 = V_76 + ( V_76 / 2 ) ;
F_50 ( & V_34 -> V_77 ) ;
if ( F_51 ( V_78 , V_34 -> V_79 + V_53 ) ||
! V_34 -> V_80 ) {
V_34 -> V_81 ( V_34 , V_65 ) ;
V_34 -> V_79 = V_78 ;
V_34 -> V_80 = 1 ;
}
F_52 ( & V_34 -> V_77 ) ;
return V_34 ;
}
static void F_53 ( struct V_33 * V_34 ,
struct V_64 * V_65 )
{
int V_42 ;
T_1 * V_82 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_34 -> V_83 [ V_42 ] . V_84 =
F_34 ( V_65 , F_54 ( V_42 ) ) ;
V_34 -> V_83 [ V_42 ] . V_85 =
F_34 ( V_65 , F_55 ( V_42 ) ) ;
}
V_34 -> V_86 = F_34 ( V_65 , V_87 ) ;
for ( V_42 = 0 ; V_42 < 2 ; V_42 ++ )
V_34 -> V_16 [ V_42 ] = F_34 ( V_65 , F_56 ( V_42 ) ) ;
for ( V_42 = 0 ; V_42 < 2 ; V_42 ++ )
V_34 -> V_88 [ V_42 ] = F_34 ( V_65 ,
F_57 ( V_42 ) ) ;
for ( V_42 = 0 ; V_42 < 2 ; V_42 ++ )
V_34 -> V_89 [ V_42 ] = F_34 ( V_65 ,
F_58 ( V_42 ) ) ;
V_34 -> V_90 = F_34 ( V_65 , V_91 ) ;
V_34 -> V_92 = F_34 ( V_65 ,
V_93 ) ;
V_34 -> V_94 = F_34 ( V_65 ,
V_95 ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ )
V_34 -> V_36 [ V_42 ] = F_34 ( V_65 , F_59 ( V_42 ) ) ;
V_34 -> V_35 [ 0 ] = F_34 ( V_65 , V_96 ) ;
V_34 -> V_35 [ 1 ] = F_34 ( V_65 , V_97 ) ;
V_34 -> V_98 [ 0 ] =
F_34 ( V_65 , V_99 ) ;
V_34 -> V_98 [ 1 ] =
F_34 ( V_65 , V_100 ) ;
V_34 -> V_101 = F_34 ( V_65 , V_102 ) ;
V_34 -> V_103 = F_34 ( V_65 , V_104 ) ;
V_34 -> V_24 = F_34 ( V_65 , V_105 ) ;
V_34 -> V_106 = F_34 ( V_65 ,
V_107 ) ;
for ( V_42 = 0 , V_82 = ( T_1 * ) ( & V_34 -> V_108 ) ; V_42 < 8 ; V_42 ++ )
F_39 ( V_65 , V_109 + V_42 , * ( V_82 + V_42 ) ) ;
}
static void F_60 ( struct V_33 * V_34 ,
struct V_64 * V_65 )
{
F_61 ( & V_65 -> V_68 , L_12 ) ;
F_45 ( V_65 , 3 , ( T_1 * ) ( V_34 -> V_110 ) ) ;
F_45 ( V_65 , 7 , ( T_1 * ) ( V_34 -> V_111 ) ) ;
F_45 ( V_65 , 2 , ( T_1 * ) ( V_34 -> V_112 ) ) ;
F_45 ( V_65 , 4 , ( T_1 * ) ( V_34 -> V_113 ) ) ;
F_45 ( V_65 , 5 , ( T_1 * ) ( V_34 -> V_114 ) ) ;
F_45 ( V_65 , 8 , ( T_1 * ) ( V_34 -> V_115 ) ) ;
F_45 ( V_65 , 9 , ( T_1 * ) ( V_34 -> V_116 ) ) ;
F_45 ( V_65 , 1 , ( T_1 * ) ( & V_34 -> V_108 ) ) ;
F_45 ( V_65 , 10 , ( T_1 * ) ( & V_34 -> V_117 ) ) ;
F_53 ( V_34 , V_65 ) ;
}
static void F_62 ( struct V_33 * V_34 ,
struct V_64 * V_65 )
{
int V_42 , V_118 ;
T_1 * V_82 ;
F_61 ( & V_65 -> V_68 , L_13 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ ) {
V_34 -> V_110 [ V_42 ] =
F_34 ( V_65 , F_63 ( V_42 ) ) ;
V_34 -> V_111 [ V_42 ] . V_84 =
F_34 ( V_65 , F_64 ( V_42 ) ) ;
V_34 -> V_111 [ V_42 ] . V_85 =
F_34 ( V_65 , F_65 ( V_42 ) ) ;
}
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_34 -> V_112 [ V_42 ] =
F_34 ( V_65 , F_66 ( V_42 ) ) ;
}
for ( V_42 = 0 ; V_42 < 2 ; V_42 ++ ) {
V_34 -> V_113 [ V_42 ] . V_119 =
F_34 ( V_65 , F_67 ( V_42 ) ) ;
V_34 -> V_113 [ V_42 ] . V_120 =
F_34 ( V_65 , F_68 ( V_42 ) ) ;
}
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_34 -> V_114 [ V_42 ] =
F_41 ( V_65 , F_69 ( V_42 ) ) ;
V_34 -> V_115 [ V_42 ] =
F_41 ( V_65 , F_70 ( V_42 ) ) ;
}
for ( V_42 = 0 ; V_42 < 2 ; V_42 ++ ) {
for ( V_118 = 0 ; V_118 < 4 ; V_118 ++ ) {
V_34 -> V_116 [ V_42 ] [ V_118 ] =
F_34 ( V_65 , F_71 ( V_42 , V_118 ) ) ;
}
}
for ( V_42 = 0 , V_82 = ( T_1 * ) ( & V_34 -> V_108 ) ; V_42 < 8 ; V_42 ++ ) {
* ( V_82 + V_42 ) =
F_34 ( V_65 , V_109 + V_42 ) ;
}
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_34 -> V_117 . V_121 [ V_42 ] =
F_34 ( V_65 , F_72 ( V_42 ) ) ;
}
for ( V_42 = 0 ; V_42 < 12 ; V_42 ++ ) {
V_34 -> V_117 . V_122 [ V_42 ] =
F_34 ( V_65 , F_73 ( V_42 ) ) ;
}
F_53 ( V_34 , V_65 ) ;
}
static T_3 F_74 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_3 ( V_2 , V_34 -> V_110 [ V_2 ] ) ) ;
}
static T_3 F_76 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
int V_127 = V_2 - 6 ;
long V_128 , V_16 ;
if ( ( V_2 == 6 || V_2 == 7 ) && V_57 [ V_127 ] ) {
V_16 = F_1 ( V_34 -> V_16 [ V_127 ] ) ;
V_128 = F_77 ( V_34 -> V_89 [ V_127 ] , V_16 ) ;
} else {
V_128 = F_3 ( V_2 , V_34 -> V_111 [ V_2 ] . V_84 ) ;
}
return sprintf ( V_125 , L_15 , V_128 ) ;
}
static T_3 F_78 ( struct V_75 * V_68 , struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
int V_127 = V_2 - 6 ;
long V_16 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
if ( ( V_2 == 6 || V_2 == 7 ) && V_57 [ V_127 ] ) {
V_16 = F_1 ( V_34 -> V_16 [ V_127 ] ) ;
V_34 -> V_89 [ V_127 ] = ( V_34 -> V_89 [ V_127 ] & 0xf0 ) |
F_7 ( V_11 , 0 , V_16 ) ;
F_39 ( V_65 , F_58 ( V_127 ) ,
V_34 -> V_89 [ V_127 ] ) ;
} else {
V_34 -> V_111 [ V_2 ] . V_84 = F_4 ( V_2 , V_11 ) ;
F_39 ( V_65 , F_64 ( V_2 ) ,
V_34 -> V_111 [ V_2 ] . V_84 ) ;
}
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_80 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
int V_127 = V_2 - 6 ;
long V_128 , V_16 ;
if ( ( V_2 == 6 || V_2 == 7 ) && V_57 [ V_127 ] ) {
V_16 = F_1 ( V_34 -> V_16 [ V_127 ] ) ;
V_128 = F_81 ( V_34 -> V_89 [ V_127 ] , V_16 ) ;
} else {
V_128 = F_3 ( V_2 , V_34 -> V_111 [ V_2 ] . V_85 ) ;
}
return sprintf ( V_125 , L_15 , V_128 ) ;
}
static T_3 F_82 ( struct V_75 * V_68 , struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
int V_127 = V_2 - 6 ;
long V_16 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
if ( ( V_2 == 6 || V_2 == 7 ) && V_57 [ V_127 ] ) {
V_16 = F_1 ( V_34 -> V_16 [ V_127 ] ) ;
V_34 -> V_89 [ V_127 ] = ( V_34 -> V_89 [ V_127 ] & 0x0f ) |
F_7 ( V_11 , 1 , V_16 ) ;
F_39 ( V_65 , F_58 ( V_127 ) ,
V_34 -> V_89 [ V_127 ] ) ;
} else {
V_34 -> V_111 [ V_2 ] . V_85 = F_4 ( V_2 , V_11 ) ;
F_39 ( V_65 , F_65 ( V_2 ) ,
V_34 -> V_111 [ V_2 ] . V_85 ) ;
}
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_83 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_8 ( V_34 -> V_112 [ V_2 ] ) ) ;
}
static T_3 F_84 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_8 ( V_34 -> V_83 [ V_2 ] . V_84 ) ) ;
}
static T_3 F_85 ( struct V_75 * V_68 , struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
long V_11 ;
int V_129 ;
V_129 = F_86 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_83 [ V_2 ] . V_84 = F_9 ( V_11 ) ;
F_39 ( V_65 , F_54 ( V_2 ) , V_34 -> V_83 [ V_2 ] . V_84 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_87 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_8 ( V_34 -> V_83 [ V_2 ] . V_85 ) ) ;
}
static T_3 F_88 ( struct V_75 * V_68 , struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
long V_11 ;
int V_129 ;
V_129 = F_86 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_83 [ V_2 ] . V_85 = F_9 ( V_11 ) ;
F_39 ( V_65 , F_55 ( V_2 ) , V_34 -> V_83 [ V_2 ] . V_85 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_89 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_8 ( V_34 -> V_117 . V_121 [ V_2 ] ) ) ;
}
static T_3 F_90 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
long V_11 ;
int V_129 ;
V_129 = F_86 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_117 . V_121 [ V_2 ] = F_9 ( V_11 ) ;
F_39 ( V_65 , F_72 ( V_2 ) , V_34 -> V_117 . V_121 [ V_2 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_91 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_8 ( V_34 -> V_36 [ V_2 ] ) ) ;
}
static T_3 F_92 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
long V_11 ;
int V_129 ;
V_129 = F_86 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_36 [ V_2 ] = F_9 ( V_11 ) ;
F_39 ( V_65 , F_59 ( V_2 ) , V_34 -> V_36 [ V_2 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_93 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
int V_25 = F_10 ( V_34 -> V_24 , V_2 ) ;
return sprintf ( V_125 , L_14 ,
F_15 ( V_34 , V_2 , V_25 ) ) ;
}
static T_3 F_94 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_24 = F_34 ( V_65 , V_105 ) ;
V_34 -> V_24 |= ( ( V_2 < 2 ) ? 0x10 : 0x20 ) ;
F_39 ( V_65 , V_105 , V_34 -> V_24 ) ;
V_34 -> V_35 [ V_2 / 2 ] = F_16 ( V_34 , V_11 , V_2 , 1 ) ;
F_39 ( V_65 , F_95 ( V_2 ) ,
V_34 -> V_35 [ V_2 / 2 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_96 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
struct V_130 * V_131 = F_97 ( V_124 ) ;
int V_2 = V_131 -> V_126 ;
int V_132 = V_131 -> V_2 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
int V_25 = F_10 ( V_34 -> V_24 , V_2 ) ;
return sprintf ( V_125 , L_14 ,
F_13 ( V_34 -> V_117 . V_122 [ V_132 ] ,
V_2 , V_25 ) ) ;
}
static T_3 F_98 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
struct V_130 * V_131 = F_97 ( V_124 ) ;
int V_2 = V_131 -> V_126 ;
int V_132 = V_131 -> V_2 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_24 = F_34 ( V_65 , V_105 ) ;
V_34 -> V_24 |= ( ( V_2 < 2 ) ? 0x10 : 0x20 ) ;
F_39 ( V_65 , V_105 , V_34 -> V_24 ) ;
V_34 -> V_117 . V_122 [ V_132 ] = F_14 (
V_34 -> V_117 . V_122 [ V_132 ] , V_11 , V_2 , 1 ) ;
F_39 ( V_65 , F_73 ( V_132 ) ,
V_34 -> V_117 . V_122 [ V_132 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_99 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
T_1 V_1 , V_133 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
V_1 = V_34 -> V_98 [ V_2 / 2 ] >> 4 & 0x0f ;
V_133 = V_34 -> V_116 [ V_2 ] [ V_134 ] ;
return sprintf ( V_125 , L_14 , F_17 ( V_1 , ( V_133 & 0x07 ) ?
V_135 : V_136 ) ) ;
}
static T_3 F_100 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_1 , V_133 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_1 = F_34 ( V_65 , F_101 ( V_2 ) ) ;
V_133 = F_34 ( V_65 , F_71 ( V_2 , V_134 ) ) ;
V_1 = ( V_1 & 0x0f ) |
F_18 ( V_11 , ( V_133 & 0x07 ) ?
V_135 :
V_136 ) << 4 ;
V_34 -> V_98 [ V_2 / 2 ] = V_1 ;
F_39 ( V_65 , F_101 ( V_2 ) , V_1 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_102 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
int V_25 = F_10 ( V_34 -> V_24 , V_2 ) ;
return sprintf ( V_125 , L_14 , F_11 (
V_34 -> V_98 [ V_2 / 2 ] , V_25 ) ) ;
}
static T_3 F_103 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_1 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_24 = F_34 ( V_65 , V_105 ) ;
V_34 -> V_24 |= ( ( V_2 < 2 ) ? 0x10 : 0x20 ) ;
F_39 ( V_65 , V_105 , V_34 -> V_24 ) ;
V_1 = V_34 -> V_98 [ V_2 / 2 ] ;
V_1 = ( V_1 & 0xf0 ) | ( F_12 ( V_11 , 1 ) & 0x0f ) ;
V_34 -> V_98 [ V_2 / 2 ] = V_1 ;
F_39 ( V_65 , F_101 ( V_2 ) , V_1 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_104 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
struct V_137 * V_131 = F_75 ( V_124 ) ;
int V_2 = V_131 -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_19 ( V_34 -> V_114 [ V_2 ] ) ) ;
}
static T_3 F_105 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_19 ( V_34 -> V_115 [ V_2 ] ) ) ;
}
static T_3 F_106 ( struct V_75 * V_68 , struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_115 [ V_2 ] = F_21 ( V_11 ) ;
F_43 ( V_65 , F_70 ( V_2 ) , V_34 -> V_115 [ V_2 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_107 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
long V_128 = 0 ;
int V_138 ;
V_138 = ( V_34 -> V_106 >> ( V_2 * 2 ) ) & 0x03 ;
if ( V_138 && ( ( V_34 -> V_24 >> V_2 ) & 0x01 ) )
V_128 = V_138 ;
return sprintf ( V_125 , L_15 , V_128 ) ;
}
static void F_108 ( struct V_64 * V_65 ,
struct V_33 * V_34 , int V_139 , long V_66 )
{
V_34 -> V_106 = F_34 ( V_65 , V_107 ) ;
V_34 -> V_106 &= ~ ( 0x3 << V_139 * 2 ) ;
V_34 -> V_106 |= V_66 << V_139 * 2 ;
F_39 ( V_65 , V_107 , V_34 -> V_106 ) ;
V_34 -> V_24 = F_34 ( V_65 , V_105 ) ;
if ( V_66 )
V_34 -> V_24 |= 1 << V_139 ;
else
V_34 -> V_24 &= ~ ( 1 << V_139 ) ;
F_39 ( V_65 , V_105 , V_34 -> V_24 ) ;
}
static T_3 F_109 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
if ( V_11 <= 2 ) {
if ( V_11 ) {
T_1 V_133 = F_34 ( V_65 ,
F_71 ( V_11 - 1 , V_134 ) ) ;
if ( ( V_133 & 0x07 ) == 0 )
V_11 = 0 ;
}
F_108 ( V_65 , V_34 , V_2 , V_11 ) ;
}
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_110 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
T_1 V_140 , V_133 ;
long V_128 ;
V_140 = V_34 -> V_116 [ V_2 ] [ V_141 ] ;
V_133 = V_34 -> V_116 [ V_2 ] [ V_134 ] ;
if ( V_140 & 0x01 )
V_128 = V_34 -> V_142 [ V_2 ] ;
else
V_128 = F_17 ( V_140 >> 4 , ( V_133 & 0x07 ) ?
V_135 : V_136 ) ;
return sprintf ( V_125 , L_15 , V_128 ) ;
}
static T_3 F_111 ( struct V_75 * V_68 , struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_140 , V_133 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_140 = F_34 ( V_65 , F_71 ( V_2 , V_141 ) ) ;
V_133 = F_34 ( V_65 , F_71 ( V_2 , V_134 ) ) ;
V_140 = ( V_140 & 0x0f ) | F_18 ( V_11 , ( V_133 & 0x07 ) ?
V_135 : V_136 ) << 4 ;
V_34 -> V_142 [ V_2 ] = F_17 ( V_140 >> 4 ,
( V_133 & 0x07 ) ? V_135 :
V_136 ) ;
F_39 ( V_65 , F_71 ( V_2 , V_141 ) , V_140 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_112 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
T_1 V_140 ;
long V_128 ;
V_140 = V_34 -> V_116 [ V_2 ] [ V_141 ] ;
if ( V_140 & 0x01 )
V_128 = ( ( V_140 & 0xF0 ) == 0xF0 ) ? 0 : 1 ;
else
V_128 = 2 ;
return sprintf ( V_125 , L_15 , V_128 ) ;
}
static T_3 F_113 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_140 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_140 = F_34 ( V_65 , F_71 ( V_2 , V_141 ) ) ;
switch ( V_11 ) {
case 0 :
V_140 |= 0xF1 ;
break;
case 1 :
V_140 |= 0x01 ;
break;
case 2 :
V_140 &= ~ 0x01 ;
break;
default:
F_52 ( & V_34 -> V_77 ) ;
return - V_143 ;
}
F_39 ( V_65 , F_71 ( V_2 , V_141 ) , V_140 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_114 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
T_1 V_133 ;
V_133 = V_34 -> V_116 [ V_2 ] [ V_134 ] ;
return sprintf ( V_125 , L_14 , F_23 ( V_133 ) ) ;
}
static void F_115 ( struct V_64 * V_65 ,
struct V_33 * V_34 , int V_41 )
{
int V_138 = F_34 ( V_65 , V_107 ) ;
int V_144 ;
V_138 = ( V_138 >> V_41 ) & 0x55 ;
V_144 = V_138 & 0x01 ;
V_144 |= ( V_138 & 0x04 ) >> 1 ;
V_144 |= ( V_138 & 0x10 ) >> 2 ;
V_144 |= ( V_138 & 0x40 ) >> 3 ;
V_34 -> V_24 = F_34 ( V_65 , V_105 ) ;
V_34 -> V_24 &= ~ V_144 ;
F_39 ( V_65 , V_105 , V_34 -> V_24 ) ;
}
static T_3 F_116 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_133 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_133 = F_34 ( V_65 , F_71 ( V_2 , V_134 ) ) ;
V_133 = ( V_133 & 0xf8 ) | F_24 ( V_11 ) ;
V_34 -> V_116 [ V_2 ] [ V_134 ] = V_133 ;
if ( ! V_133 )
F_115 ( V_65 , V_34 , V_2 ) ;
F_39 ( V_65 , F_71 ( V_2 , V_134 ) , V_133 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_117 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , V_34 -> V_116 [ V_2 ] [ V_145 ] ) ;
}
static T_3 F_118 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_116 [ V_2 ] [ V_145 ] = F_5 ( V_11 , 0 , 255 ) ;
F_39 ( V_65 , F_71 ( V_2 , V_145 ) ,
V_34 -> V_116 [ V_2 ] [ V_145 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_119 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
T_1 V_146 , V_133 ;
V_146 = V_34 -> V_116 [ V_2 ] [ V_147 ] ;
V_133 = V_34 -> V_116 [ V_2 ] [ V_134 ] ;
return sprintf ( V_125 , L_14 ,
F_17 ( V_146 & 0x0f , ( V_133 & 0x07 ) ?
V_135 : V_136 ) ) ;
}
static T_3 F_120 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_146 , V_133 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_146 = F_34 ( V_65 , F_71 ( V_2 , V_147 ) ) ;
V_133 = F_34 ( V_65 , F_71 ( V_2 , V_134 ) ) ;
V_146 = ( V_146 & 0xf0 ) | F_18 ( V_11 , ( V_133 & 0x07 ) ?
V_135 :
V_136 ) ;
V_34 -> V_116 [ V_2 ] [ V_147 ] = V_146 ;
F_39 ( V_65 , F_71 ( V_2 , V_147 ) , V_146 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_121 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_25 (
V_34 -> V_116 [ V_2 ] [ V_147 ] ) ) ;
}
static T_3 F_122 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_146 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_146 = F_34 ( V_65 , F_71 ( V_2 , V_147 ) ) ;
V_146 = ( V_146 & 0x1f ) | ( F_26 ( V_11 ) << 5 & 0xe0 ) ;
V_34 -> V_116 [ V_2 ] [ V_147 ] = V_146 ;
F_39 ( V_65 , F_71 ( V_2 , V_147 ) , V_146 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_123 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 ,
F_27 ( V_34 -> V_101 >> 4 & 0x0f ) ) ;
}
static T_3 F_124 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_48 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_48 = F_34 ( V_65 , V_102 ) ;
V_48 = ( V_48 & 0x0f ) | ( F_28 ( V_11 ) << 4 & 0xf0 ) ;
F_39 ( V_65 , V_102 , V_48 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_125 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 ,
F_27 ( V_34 -> V_101 & 0x0f ) ) ;
}
static T_3 F_126 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_48 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_48 = F_34 ( V_65 , V_102 ) ;
V_48 = ( V_48 & 0xf0 ) | ( F_28 ( V_11 ) & 0x0f ) ;
F_39 ( V_65 , V_102 , V_48 ) ;
F_52 ( & V_34 -> V_77 ) ;
return 0 ;
}
static T_3 F_127 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_1 ( V_34 -> V_16 [ V_2 ] ) ) ;
}
static T_3 F_128 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , V_34 -> V_113 [ V_2 ] . V_119 ) ;
}
static T_3 F_129 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , V_34 -> V_113 [ V_2 ] . V_120 ) ;
}
static T_3 F_130 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , V_34 -> V_88 [ V_2 ] ) ;
}
static T_3 F_131 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_88 [ V_2 ] = F_29 ( V_11 ) ;
F_39 ( V_65 , F_57 ( V_2 ) ,
V_34 -> V_88 [ V_2 ] ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_132 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 ,
( V_34 -> V_92 & V_148 [ V_2 ] ) ? 1 : 0 ) ;
}
static T_3 F_133 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
if ( V_11 )
V_34 -> V_92 |= V_148 [ V_2 ] ;
else
V_34 -> V_92 &= ( ~ V_148 [ V_2 ] ) ;
F_39 ( V_65 , V_93 ,
V_34 -> V_92 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_134 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
T_1 V_149 ;
if ( V_2 == 1 )
V_149 = ( V_34 -> V_94 & 0xf0 ) >> 4 ;
else
V_149 = V_34 -> V_94 & 0x0f ;
return sprintf ( V_125 , L_14 , F_30 ( V_149 ) ) ;
}
static T_3 F_135 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
T_1 V_149 ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_149 = F_34 ( V_65 , V_95 ) ;
if ( V_2 == 1 )
V_149 = ( V_149 & 0x0f ) | ( F_31 ( V_11 ) << 4 ) ;
else
V_149 = ( V_149 & 0xf0 ) | F_31 ( V_11 ) ;
V_34 -> V_94 = V_149 ;
F_39 ( V_65 , V_95 , V_149 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_136 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
char * V_125 )
{
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , V_34 -> V_92 & 0x0f ) ;
}
static T_3 F_137 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
V_34 -> V_92 = ( V_34 -> V_92 & 0xf0 ) |
F_5 ( V_11 , 0 , 15 ) ;
F_39 ( V_65 , V_93 ,
V_34 -> V_92 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_138 ( struct V_75 * V_68 ,
struct V_123 * V_124 , char * V_125 )
{
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , ( V_34 -> V_86 & 0x10 ) ? 1 : 0 ) ;
}
static T_3 F_139 ( struct V_75 * V_68 ,
struct V_123 * V_124 ,
const char * V_125 , T_4 V_44 )
{
struct V_64 * V_65 = F_48 ( V_68 ) ;
struct V_33 * V_34 = F_49 ( V_65 ) ;
unsigned long V_11 ;
int V_129 ;
V_129 = F_79 ( V_125 , 10 , & V_11 ) ;
if ( V_129 )
return V_129 ;
F_50 ( & V_34 -> V_77 ) ;
if ( V_11 )
V_34 -> V_86 |= 0x10 ;
else
V_34 -> V_86 &= ~ 0x10 ;
F_39 ( V_65 , V_87 , V_34 -> V_86 ) ;
F_52 ( & V_34 -> V_77 ) ;
return V_44 ;
}
static T_3 F_140 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
int V_2 = ( F_75 ( V_124 ) ) -> V_126 ;
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 ,
V_34 -> V_108 . V_63 & ( 1 << ( V_2 + 4 ) ) ? 1 : 0 ) ;
}
static T_3 F_141 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_32 ( V_34 -> V_90 ) ) ;
}
static T_3 F_142 ( struct V_75 * V_68 , struct V_123 * V_124 ,
char * V_125 )
{
struct V_33 * V_34 = F_47 ( V_68 ) ;
return sprintf ( V_125 , L_14 , F_33 ( V_34 -> V_108 ) ) ;
}
static void F_143 ( struct V_64 * V_65 )
{
int V_42 ;
T_1 V_1 ;
V_1 = F_34 ( V_65 , V_150 ) ;
F_39 ( V_65 , V_150 ,
V_1 | ( V_151 ? 0x03 : 0x00 ) ) ;
if ( V_152 ) {
V_1 = F_34 ( V_65 , V_87 ) ;
F_39 ( V_65 , V_87 , V_1 | 0x08 ) ;
V_1 = F_34 ( V_65 , V_153 ) ;
F_39 ( V_65 , V_153 , V_1 | 0x02 ) ;
F_39 ( V_65 , V_154 , 0 ) ;
V_1 = F_34 ( V_65 , V_155 ) ;
V_1 &= ~ 0x03 ;
V_1 &= ~ ( V_57 [ 0 ] ? 0x10 : 0 ) ;
V_1 &= ~ ( V_57 [ 1 ] ? 0x20 : 0 ) ;
F_39 ( V_65 , V_155 , V_1 ) ;
}
V_1 = F_34 ( V_65 , V_87 ) ;
F_39 ( V_65 , V_87 , V_1 | 0x01 ) ;
for ( V_42 = 0 ; V_42 < 20 ; V_42 ++ ) {
F_144 ( 10 ) ;
if ( ( F_34 ( V_65 , V_87 ) & 0x80 ) == 0x80 )
return;
}
F_36 ( & V_65 -> V_68 , L_16
L_17 ) ;
}
static int F_145 ( struct V_64 * V_65 , struct V_156 * V_157 )
{
struct V_158 * V_159 = V_65 -> V_159 ;
int V_160 , V_161 ;
const char * V_162 ;
if ( ! F_146 ( V_159 , V_163 ) )
return - V_164 ;
V_160 = F_34 ( V_65 , V_165 ) ;
if ( V_160 != 0x01 ) {
F_61 ( & V_159 -> V_68 ,
L_18 , V_160 ) ;
return - V_164 ;
}
V_161 = F_34 ( V_65 , V_166 ) ;
switch ( V_161 ) {
case V_167 :
case V_168 :
V_162 = L_19 ;
break;
case V_169 :
case V_170 :
case V_171 :
V_162 = L_20 ;
break;
default:
F_61 ( & V_159 -> V_68 ,
L_21 , V_161 ) ;
return - V_164 ;
}
F_147 ( V_157 -> type , V_162 , V_172 ) ;
F_61 ( & V_159 -> V_68 , L_22 ,
V_65 -> V_162 , F_148 ( V_65 -> V_159 ) ,
V_65 -> V_173 ) ;
return 0 ;
}
static int F_149 ( struct V_64 * V_65 ,
const struct V_174 * V_175 )
{
struct V_33 * V_34 ;
int V_129 , V_176 ;
void (* V_81)( struct V_33 * , struct V_64 * );
V_176 = F_150 ( V_65 -> V_159 ) ;
if ( ( ( V_177 & V_176 ) == V_177 ) &&
( ! V_178 ) ) {
F_61 ( & V_65 -> V_68 , L_23 ) ;
V_81 = F_60 ;
} else if ( ( V_163 & V_176 ) == V_163 ) {
F_61 ( & V_65 -> V_68 , L_24
L_25 ) ;
V_81 = F_62 ;
} else {
F_61 ( & V_65 -> V_68 , L_26
L_27 ) ;
return - V_164 ;
}
V_34 = F_151 ( & V_65 -> V_68 , sizeof( struct V_33 ) , V_179 ) ;
if ( ! V_34 ) {
F_61 ( & V_65 -> V_68 , L_28 ) ;
return - V_180 ;
}
F_152 ( V_65 , V_34 ) ;
V_34 -> V_80 = 0 ;
V_34 -> V_81 = V_81 ;
F_153 ( & V_34 -> V_77 ) ;
F_143 ( V_65 ) ;
V_129 = F_154 ( & V_65 -> V_68 . V_181 , & V_182 ) ;
if ( V_129 )
return V_129 ;
V_34 -> V_183 = F_155 ( & V_65 -> V_68 ) ;
if ( ! F_156 ( V_34 -> V_183 ) )
return 0 ;
V_129 = F_157 ( V_34 -> V_183 ) ;
F_38 ( & V_65 -> V_68 , L_29 ) ;
F_158 ( & V_65 -> V_68 . V_181 , & V_182 ) ;
return V_129 ;
}
static int F_159 ( struct V_64 * V_65 )
{
struct V_33 * V_34 = F_49 ( V_65 ) ;
F_160 ( V_34 -> V_183 ) ;
F_158 ( & V_65 -> V_68 . V_181 , & V_182 ) ;
return 0 ;
}
