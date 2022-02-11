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
static int F_17 ( T_1 V_1 , T_2 V_38 )
{
return V_39 [ V_38 ] [ V_1 & 0x0f ] ;
}
static T_1 F_18 ( int V_40 , T_2 V_38 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 13 ; V_41 ++ )
if ( V_40 <= V_39 [ V_38 ] [ V_41 ] )
break;
return ( T_1 ) V_41 ;
}
static int F_19 ( T_3 V_42 )
{
const T_3 V_43 = F_20 ( V_42 ) >> 2 ;
return V_43 == 0 ? - 1 : V_43 == 0x3fff ? 0 : 1350000 / V_43 ;
}
static T_3 F_21 ( long V_44 )
{
T_3 V_43 , V_42 ;
if ( V_44 == 0 ) {
V_43 = 0x3fff ;
} else {
V_44 = F_5 ( V_44 , 1 , 1000000 ) ;
V_43 = F_5 ( ( 1350000 + V_44 ) / V_44 , 1 , 0x3ffe ) ;
}
V_42 = V_43 << 2 ;
return F_22 ( V_42 ) ;
}
static int F_23 ( T_1 V_1 )
{
return V_45 [ V_1 & 0x07 ] ;
}
static T_1 F_24 ( int V_38 )
{
int V_41 ;
for ( V_41 = 7 ; V_41 > 0 ; V_41 -- )
if ( V_38 <= V_45 [ V_41 ] )
break;
return ( T_1 ) V_41 ;
}
static int F_25 ( T_1 V_1 )
{
return V_46 [ V_1 >> 5 & 0x07 ] ;
}
static T_1 F_26 ( int time )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 7 ; V_41 ++ )
if ( time <= V_46 [ V_41 ] )
break;
return ( T_1 ) V_41 ;
}
static int F_27 ( T_1 V_1 )
{
return ( V_1 & 0x0f ) * 5 ;
}
static T_1 F_28 ( int V_47 )
{
V_47 = F_5 ( V_47 , V_48 , V_49 ) ;
return ( T_1 ) ( ( V_47 + 2 ) / 5 ) ;
}
static T_1 F_29 ( long V_50 )
{
V_50 = F_5 ( V_50 , 0 , 255 ) ;
return ( T_1 ) V_50 ;
}
static int F_30 ( T_1 V_1 )
{
return V_51 [ V_1 & 0x0f ] ;
}
static T_1 F_31 ( long V_52 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 9 ; V_41 ++ )
if ( V_52 <= V_51 [ V_41 ] )
break;
return ( T_1 ) V_41 ;
}
static unsigned F_32 ( T_1 V_1 )
{
return ~ V_1 & 0xff ;
}
static unsigned F_33 ( struct V_53 V_54 )
{
unsigned V_14 ;
V_14 = V_54 . V_55 & 0x3f ;
if ( V_56 [ 0 ] )
V_14 |= ( V_54 . V_57 & 0x10 ) << 2 ;
else
V_14 |= V_54 . V_55 & 0x40 ;
if ( V_56 [ 1 ] )
V_14 |= ( V_54 . V_57 & 0x20 ) << 2 ;
else
V_14 |= V_54 . V_55 & 0x80 ;
V_14 |= V_54 . V_58 << 8 ;
V_14 |= ( V_54 . V_59 & 0x0f ) << 16 ;
V_14 |= ( V_54 . V_60 & 0x80 ) << 13 ;
V_14 |= ( V_54 . V_61 & 0x80 ) << 14 ;
V_14 |= ( V_54 . V_57 & 0xfc ) << 20 ;
V_14 |= ( V_54 . V_62 & 0x07 ) << 28 ;
return V_14 ;
}
static T_1 F_34 ( struct V_63 * V_64 , T_1 V_1 )
{
int V_65 , V_41 ;
for ( V_41 = 1 ; V_41 <= V_66 ; V_41 ++ ) {
if ( ( V_65 = F_35 ( V_64 , V_1 ) ) >= 0 ) {
return V_65 ;
} else {
F_36 ( & V_64 -> V_67 , L_1
L_2 , V_1 ) ;
F_37 ( V_41 + 3 ) ;
}
}
F_38 ( & V_64 -> V_67 , L_3 ) ;
return 0 ;
}
static int F_39 ( struct V_63 * V_64 , T_1 V_1 , T_1 V_65 )
{
int V_14 ;
V_14 = F_40 ( V_64 , V_1 , V_65 ) ;
if ( V_14 < 0 )
F_36 ( & V_64 -> V_67 , L_4
L_5 , V_65 , V_1 ) ;
return V_14 ;
}
static T_3 F_41 ( struct V_63 * V_64 , T_1 V_1 )
{
int V_65 , V_41 ;
for ( V_41 = 1 ; V_41 <= V_66 ; V_41 ++ ) {
if ( ( V_65 = F_42 ( V_64 , V_1 ) ) >= 0 ) {
return V_65 ;
} else {
F_36 ( & V_64 -> V_67 , L_6
L_2 , V_1 ) ;
F_37 ( V_41 + 3 ) ;
}
}
F_38 ( & V_64 -> V_67 , L_7 ) ;
return 0 ;
}
static int F_43 ( struct V_63 * V_64 , T_1 V_1 , T_3 V_65 )
{
int V_14 ;
V_14 = F_44 ( V_64 , V_1 , V_65 ) ;
if ( V_14 < 0 )
F_36 ( & V_64 -> V_67 , L_8
L_9 , V_65 , V_1 ) ;
return V_14 ;
}
static void F_45 ( struct V_63 * V_64 , T_1 V_68 , T_1 * V_69 )
{
int V_41 , V_14 = 0 ;
for ( V_41 = 1 ; V_41 <= V_66 ; V_41 ++ ) {
V_14 = F_46 ( V_64 ,
V_70 [ V_68 ] . V_71 , V_72 ) ;
if ( V_14 == V_70 [ V_68 ] . V_73 ) {
break;
} else {
F_36 ( & V_64 -> V_67 , L_10
L_11 ,
V_70 [ V_68 ] . V_71 ) ;
F_37 ( V_41 + 3 ) ;
}
}
if ( V_14 == V_70 [ V_68 ] . V_73 ) {
memcpy ( V_69 , V_72 , V_70 [ V_68 ] . V_73 ) ;
} else {
}
}
static struct V_33 * F_47 ( struct V_74 * V_67 )
{
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
const unsigned long V_52 = V_75 + ( V_75 / 2 ) ;
F_50 ( & V_34 -> V_76 ) ;
if ( F_51 ( V_77 , V_34 -> V_78 + V_52 ) ||
! V_34 -> V_79 ) {
V_34 -> V_80 ( V_34 , V_64 ) ;
V_34 -> V_78 = V_77 ;
V_34 -> V_79 = 1 ;
}
F_52 ( & V_34 -> V_76 ) ;
return V_34 ;
}
static void F_53 ( struct V_33 * V_34 ,
struct V_63 * V_64 )
{
int V_41 ;
T_1 * V_81 ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_34 -> V_82 [ V_41 ] . V_83 =
F_34 ( V_64 , F_54 ( V_41 ) ) ;
V_34 -> V_82 [ V_41 ] . V_84 =
F_34 ( V_64 , F_55 ( V_41 ) ) ;
}
V_34 -> V_85 = F_34 ( V_64 , V_86 ) ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ )
V_34 -> V_16 [ V_41 ] = F_34 ( V_64 , F_56 ( V_41 ) ) ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ )
V_34 -> V_87 [ V_41 ] = F_34 ( V_64 ,
F_57 ( V_41 ) ) ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ )
V_34 -> V_88 [ V_41 ] = F_34 ( V_64 ,
F_58 ( V_41 ) ) ;
V_34 -> V_89 = F_34 ( V_64 , V_90 ) ;
V_34 -> V_91 = F_34 ( V_64 ,
V_92 ) ;
V_34 -> V_93 = F_34 ( V_64 ,
V_94 ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ )
V_34 -> V_36 [ V_41 ] = F_34 ( V_64 , F_59 ( V_41 ) ) ;
V_34 -> V_35 [ 0 ] = F_34 ( V_64 , V_95 ) ;
V_34 -> V_35 [ 1 ] = F_34 ( V_64 , V_96 ) ;
V_34 -> V_97 [ 0 ] =
F_34 ( V_64 , V_98 ) ;
V_34 -> V_97 [ 1 ] =
F_34 ( V_64 , V_99 ) ;
V_34 -> V_100 = F_34 ( V_64 , V_101 ) ;
V_34 -> V_102 = F_34 ( V_64 , V_103 ) ;
V_34 -> V_24 = F_34 ( V_64 , V_104 ) ;
V_34 -> V_105 = F_34 ( V_64 ,
V_106 ) ;
for ( V_41 = 0 , V_81 = ( T_1 * ) ( & V_34 -> V_107 ) ; V_41 < 8 ; V_41 ++ )
F_39 ( V_64 , V_108 + V_41 , * ( V_81 + V_41 ) ) ;
}
static void F_60 ( struct V_33 * V_34 ,
struct V_63 * V_64 )
{
F_61 ( & V_64 -> V_67 , L_12 ) ;
F_45 ( V_64 , 3 , ( T_1 * ) ( V_34 -> V_109 ) ) ;
F_45 ( V_64 , 7 , ( T_1 * ) ( V_34 -> V_110 ) ) ;
F_45 ( V_64 , 2 , ( T_1 * ) ( V_34 -> V_111 ) ) ;
F_45 ( V_64 , 4 , ( T_1 * ) ( V_34 -> V_112 ) ) ;
F_45 ( V_64 , 5 , ( T_1 * ) ( V_34 -> V_113 ) ) ;
F_45 ( V_64 , 8 , ( T_1 * ) ( V_34 -> V_114 ) ) ;
F_45 ( V_64 , 9 , ( T_1 * ) ( V_34 -> V_115 ) ) ;
F_45 ( V_64 , 1 , ( T_1 * ) ( & V_34 -> V_107 ) ) ;
F_45 ( V_64 , 10 , ( T_1 * ) ( & V_34 -> V_116 ) ) ;
F_53 ( V_34 , V_64 ) ;
}
static void F_62 ( struct V_33 * V_34 ,
struct V_63 * V_64 )
{
int V_41 , V_117 ;
T_1 * V_81 ;
F_61 ( & V_64 -> V_67 , L_13 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ ) {
V_34 -> V_109 [ V_41 ] =
F_34 ( V_64 , F_63 ( V_41 ) ) ;
V_34 -> V_110 [ V_41 ] . V_83 =
F_34 ( V_64 , F_64 ( V_41 ) ) ;
V_34 -> V_110 [ V_41 ] . V_84 =
F_34 ( V_64 , F_65 ( V_41 ) ) ;
}
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_34 -> V_111 [ V_41 ] =
F_34 ( V_64 , F_66 ( V_41 ) ) ;
}
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
V_34 -> V_112 [ V_41 ] . V_118 =
F_34 ( V_64 , F_67 ( V_41 ) ) ;
V_34 -> V_112 [ V_41 ] . V_119 =
F_34 ( V_64 , F_68 ( V_41 ) ) ;
}
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_34 -> V_113 [ V_41 ] =
F_41 ( V_64 , F_69 ( V_41 ) ) ;
V_34 -> V_114 [ V_41 ] =
F_41 ( V_64 , F_70 ( V_41 ) ) ;
}
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
V_34 -> V_115 [ V_41 ] [ V_117 ] =
F_34 ( V_64 , F_71 ( V_41 , V_117 ) ) ;
}
}
for ( V_41 = 0 , V_81 = ( T_1 * ) ( & V_34 -> V_107 ) ; V_41 < 8 ; V_41 ++ ) {
* ( V_81 + V_41 ) =
F_34 ( V_64 , V_108 + V_41 ) ;
}
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_34 -> V_116 . V_120 [ V_41 ] =
F_34 ( V_64 , F_72 ( V_41 ) ) ;
}
for ( V_41 = 0 ; V_41 < 12 ; V_41 ++ ) {
V_34 -> V_116 . V_121 [ V_41 ] =
F_34 ( V_64 , F_73 ( V_41 ) ) ;
}
F_53 ( V_34 , V_64 ) ;
}
static T_4 F_74 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_3 ( V_2 , V_34 -> V_109 [ V_2 ] ) ) ;
}
static T_4 F_76 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
int V_126 = V_2 - 6 ;
long V_127 , V_16 ;
if ( ( V_2 == 6 || V_2 == 7 ) && ( V_56 [ V_126 ] ) ) {
V_16 = F_1 ( V_34 -> V_16 [ V_126 ] ) ;
V_127 = F_77 ( V_34 -> V_88 [ V_126 ] , V_16 ) ;
}
else {
V_127 = F_3 ( V_2 , V_34 -> V_110 [ V_2 ] . V_83 ) ; \
}
return sprintf ( V_124 , L_15 , V_127 ) ; \
}
static T_4 F_78 ( struct V_74 * V_67 , struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
int V_126 = V_2 - 6 ;
long V_16 ;
F_50 ( & V_34 -> V_76 ) ;
if ( ( V_2 == 6 || V_2 == 7 ) && ( V_56 [ V_126 ] ) ) {
V_16 = F_1 ( V_34 -> V_16 [ V_126 ] ) ;
V_34 -> V_88 [ V_126 ] = ( V_34 -> V_88 [ V_126 ] & 0xf0 ) |
F_7 ( V_11 , 0 , V_16 ) ;
F_39 ( V_64 , F_58 ( V_126 ) ,
V_34 -> V_88 [ V_126 ] ) ;
}
else {
V_34 -> V_110 [ V_2 ] . V_83 = F_4 ( V_2 , V_11 ) ;
F_39 ( V_64 , F_64 ( V_2 ) ,
V_34 -> V_110 [ V_2 ] . V_83 ) ;
}
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_80 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
int V_126 = V_2 - 6 ;
long V_127 , V_16 ;
if ( ( V_2 == 6 || V_2 == 7 ) && ( V_56 [ V_126 ] ) ) {
V_16 = F_1 ( V_34 -> V_16 [ V_126 ] ) ;
V_127 = F_81 ( V_34 -> V_88 [ V_126 ] , V_16 ) ;
}
else {
V_127 = F_3 ( V_2 , V_34 -> V_110 [ V_2 ] . V_84 ) ; \
}
return sprintf ( V_124 , L_15 , V_127 ) ; \
}
static T_4 F_82 ( struct V_74 * V_67 , struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
int V_126 = V_2 - 6 ;
long V_16 ;
F_50 ( & V_34 -> V_76 ) ;
if ( ( V_2 == 6 || V_2 == 7 ) && ( V_56 [ V_126 ] ) ) {
V_16 = F_1 ( V_34 -> V_16 [ V_126 ] ) ;
V_34 -> V_88 [ V_126 ] = ( V_34 -> V_88 [ V_126 ] & 0x0f ) |
F_7 ( V_11 , 1 , V_16 ) ;
F_39 ( V_64 , F_58 ( V_126 ) ,
V_34 -> V_88 [ V_126 ] ) ;
}
else {
V_34 -> V_110 [ V_2 ] . V_84 = F_4 ( V_2 , V_11 ) ;
F_39 ( V_64 , F_65 ( V_2 ) ,
V_34 -> V_110 [ V_2 ] . V_84 ) ;
}
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_83 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_8 ( V_34 -> V_111 [ V_2 ] ) ) ;
}
static T_4 F_84 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_8 ( V_34 -> V_82 [ V_2 ] . V_83 ) ) ;
}
static T_4 F_85 ( struct V_74 * V_67 , struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
long V_11 = F_86 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_82 [ V_2 ] . V_83 = F_9 ( V_11 ) ;
F_39 ( V_64 , F_54 ( V_2 ) , V_34 -> V_82 [ V_2 ] . V_83 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_87 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_8 ( V_34 -> V_82 [ V_2 ] . V_84 ) ) ;
}
static T_4 F_88 ( struct V_74 * V_67 , struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
long V_11 = F_86 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_82 [ V_2 ] . V_84 = F_9 ( V_11 ) ;
F_39 ( V_64 , F_55 ( V_2 ) , V_34 -> V_82 [ V_2 ] . V_84 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_89 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_8 ( V_34 -> V_116 . V_120 [ V_2 ] ) ) ;
}
static T_4 F_90 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
long V_11 = F_86 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_116 . V_120 [ V_2 ] = F_9 ( V_11 ) ;
F_39 ( V_64 , F_72 ( V_2 ) , V_34 -> V_116 . V_120 [ V_2 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_91 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_8 ( V_34 -> V_36 [ V_2 ] ) ) ;
}
static T_4 F_92 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
long V_11 = F_86 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_36 [ V_2 ] = F_9 ( V_11 ) ;
F_39 ( V_64 , F_59 ( V_2 ) , V_34 -> V_36 [ V_2 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_93 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
int V_25 = F_10 ( V_34 -> V_24 , V_2 ) ;
return sprintf ( V_124 , L_14 ,
F_15 ( V_34 , V_2 , V_25 ) ) ;
}
static T_4 F_94 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_24 = F_34 ( V_64 , V_104 ) ;
V_34 -> V_24 |= ( ( V_2 < 2 ) ? 0x10 : 0x20 ) ;
F_39 ( V_64 , V_104 , V_34 -> V_24 ) ;
V_34 -> V_35 [ V_2 / 2 ] = F_16 ( V_34 , V_11 , V_2 , 1 ) ;
F_39 ( V_64 , F_95 ( V_2 ) ,
V_34 -> V_35 [ V_2 / 2 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_96 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_128 * V_129 = F_97 ( V_123 ) ;
int V_2 = V_129 -> V_125 ;
int V_130 = V_129 -> V_2 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
int V_25 = F_10 ( V_34 -> V_24 , V_2 ) ;
return sprintf ( V_124 , L_14 ,
F_13 ( V_34 -> V_116 . V_121 [ V_130 ] ,
V_2 , V_25 ) ) ;
}
static T_4 F_98 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
struct V_128 * V_129 = F_97 ( V_123 ) ;
int V_2 = V_129 -> V_125 ;
int V_130 = V_129 -> V_2 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_24 = F_34 ( V_64 , V_104 ) ;
V_34 -> V_24 |= ( ( V_2 < 2 ) ? 0x10 : 0x20 ) ;
F_39 ( V_64 , V_104 , V_34 -> V_24 ) ;
V_34 -> V_116 . V_121 [ V_130 ] = F_14 (
V_34 -> V_116 . V_121 [ V_130 ] , V_11 , V_2 , 1 ) ;
F_39 ( V_64 , F_73 ( V_130 ) ,
V_34 -> V_116 . V_121 [ V_130 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_99 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
T_1 V_1 , V_131 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
V_1 = V_34 -> V_97 [ V_2 / 2 ] >> 4 & 0x0f ;
V_131 = V_34 -> V_115 [ V_2 ] [ V_132 ] ;
return sprintf ( V_124 , L_14 , F_17 ( V_1 , ( V_131 & 0x07 ) ?
V_133 : V_134 ) ) ;
}
static T_4 F_100 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_1 , V_131 ;
F_50 ( & V_34 -> V_76 ) ;
V_1 = F_34 ( V_64 , F_101 ( V_2 ) ) ;
V_131 = F_34 ( V_64 , F_71 ( V_2 , V_132 ) ) ;
V_1 = ( V_1 & 0x0f ) |
F_18 ( V_11 , ( V_131 & 0x07 ) ?
V_133 :
V_134 ) << 4 ;
V_34 -> V_97 [ V_2 / 2 ] = V_1 ;
F_39 ( V_64 , F_101 ( V_2 ) , V_1 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_102 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
int V_25 = F_10 ( V_34 -> V_24 , V_2 ) ;
return sprintf ( V_124 , L_14 , F_11 (
V_34 -> V_97 [ V_2 / 2 ] , V_25 ) ) ;
}
static T_4 F_103 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_1 ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_24 = F_34 ( V_64 , V_104 ) ;
V_34 -> V_24 |= ( ( V_2 < 2 ) ? 0x10 : 0x20 ) ;
F_39 ( V_64 , V_104 , V_34 -> V_24 ) ;
V_1 = V_34 -> V_97 [ V_2 / 2 ] ;
V_1 = ( V_1 & 0xf0 ) | ( F_12 ( V_11 , 1 ) & 0x0f ) ;
V_34 -> V_97 [ V_2 / 2 ] = V_1 ;
F_39 ( V_64 , F_101 ( V_2 ) , V_1 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_104 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_135 * V_129 = F_75 ( V_123 ) ;
int V_2 = V_129 -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_19 ( V_34 -> V_113 [ V_2 ] ) ) ;
}
static T_4 F_105 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_19 ( V_34 -> V_114 [ V_2 ] ) ) ;
}
static T_4 F_106 ( struct V_74 * V_67 , struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_114 [ V_2 ] = F_21 ( V_11 ) ;
F_43 ( V_64 , F_70 ( V_2 ) , V_34 -> V_114 [ V_2 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_107 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
long V_127 = 0 ;
int V_136 ;
V_136 = ( V_34 -> V_105 >> ( V_2 * 2 ) ) & 0x03 ;
if ( V_136 && ( ( V_34 -> V_24 >> V_2 ) & 0x01 ) )
V_127 = V_136 ;
return sprintf ( V_124 , L_15 , V_127 ) ;
}
static void F_108 ( struct V_63 * V_64 ,
struct V_33 * V_34 , int V_137 , long V_65 )
{
V_34 -> V_105 = F_34 ( V_64 , V_106 ) ;
V_34 -> V_105 &= ~ ( 0x3 << V_137 * 2 ) ;
V_34 -> V_105 |= V_65 << V_137 * 2 ;
F_39 ( V_64 , V_106 , V_34 -> V_105 ) ;
V_34 -> V_24 = F_34 ( V_64 , V_104 ) ;
if ( V_65 )
V_34 -> V_24 |= 1 << V_137 ;
else
V_34 -> V_24 &= ~ ( 1 << V_137 ) ;
F_39 ( V_64 , V_104 , V_34 -> V_24 ) ;
}
static T_4 F_109 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
if ( 0 <= V_11 && V_11 <= 2 ) {
if ( V_11 ) {
T_1 V_131 = F_34 ( V_64 ,
F_71 ( V_11 - 1 , V_132 ) ) ;
if ( ( V_131 & 0x07 ) == 0 )
V_11 = 0 ;
}
F_108 ( V_64 , V_34 , V_2 , V_11 ) ;
}
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_110 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
T_1 V_138 , V_131 ;
long V_127 ;
V_138 = V_34 -> V_115 [ V_2 ] [ V_139 ] ;
V_131 = V_34 -> V_115 [ V_2 ] [ V_132 ] ;
if ( V_138 & 0x01 )
V_127 = V_34 -> V_140 [ V_2 ] ;
else
V_127 = F_17 ( V_138 >> 4 , ( V_131 & 0x07 ) ?
V_133 : V_134 ) ;
return sprintf ( V_124 , L_15 , V_127 ) ;
}
static T_4 F_111 ( struct V_74 * V_67 , struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_138 , V_131 ;
F_50 ( & V_34 -> V_76 ) ;
V_138 = F_34 ( V_64 , F_71 ( V_2 , V_139 ) ) ;
V_131 = F_34 ( V_64 , F_71 ( V_2 , V_132 ) ) ;
V_138 = ( V_138 & 0x0f ) | F_18 ( V_11 , ( V_131 & 0x07 ) ?
V_133 : V_134 ) << 4 ;
V_34 -> V_140 [ V_2 ] = F_17 ( V_138 >> 4 ,
( V_131 & 0x07 ) ? V_133 :
V_134 ) ;
F_39 ( V_64 , F_71 ( V_2 , V_139 ) , V_138 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_112 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
T_1 V_138 ;
long V_127 ;
V_138 = V_34 -> V_115 [ V_2 ] [ V_139 ] ;
if ( V_138 & 0x01 )
V_127 = ( ( V_138 & 0xF0 ) == 0xF0 ) ? 0 : 1 ;
else
V_127 = 2 ;
return sprintf ( V_124 , L_15 , V_127 ) ;
}
static T_4 F_113 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_138 ;
F_50 ( & V_34 -> V_76 ) ;
V_138 = F_34 ( V_64 , F_71 ( V_2 , V_139 ) ) ;
switch ( V_11 ) {
case 0 :
V_138 |= 0xF1 ;
break;
case 1 : V_138 |= 0x01 ;
break;
case 2 : V_138 &= ~ 0x01 ;
break;
default:
F_52 ( & V_34 -> V_76 ) ;
return - V_141 ;
}
F_39 ( V_64 , F_71 ( V_2 , V_139 ) , V_138 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_114 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
T_1 V_131 ;
V_131 = V_34 -> V_115 [ V_2 ] [ V_132 ] ;
return sprintf ( V_124 , L_14 , F_23 ( V_131 ) ) ;
}
static void F_115 ( struct V_63 * V_64 ,
struct V_33 * V_34 , int V_40 )
{
int V_136 = F_34 ( V_64 , V_106 ) ;
int V_142 ;
V_136 = ( V_136 >> V_40 ) & 0x55 ;
V_142 = V_136 & 0x01 ;
V_142 |= ( V_136 & 0x04 ) >> 1 ;
V_142 |= ( V_136 & 0x10 ) >> 2 ;
V_142 |= ( V_136 & 0x40 ) >> 3 ;
V_34 -> V_24 = F_34 ( V_64 , V_104 ) ;
V_34 -> V_24 &= ~ V_142 ;
F_39 ( V_64 , V_104 , V_34 -> V_24 ) ;
}
static T_4 F_116 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_131 ;
F_50 ( & V_34 -> V_76 ) ;
V_131 = F_34 ( V_64 , F_71 ( V_2 , V_132 ) ) ;
V_131 = ( V_131 & 0xf8 ) | F_24 ( V_11 ) ;
V_34 -> V_115 [ V_2 ] [ V_132 ] = V_131 ;
if ( ! V_131 )
F_115 ( V_64 , V_34 , V_2 ) ;
F_39 ( V_64 , F_71 ( V_2 , V_132 ) , V_131 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_117 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , V_34 -> V_115 [ V_2 ] [ V_143 ] ) ;
}
static T_4 F_118 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_115 [ V_2 ] [ V_143 ] = F_5 ( V_11 , 0 , 255 ) ;
F_39 ( V_64 , F_71 ( V_2 , V_143 ) ,
V_34 -> V_115 [ V_2 ] [ V_143 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_119 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
T_1 V_144 , V_131 ;
V_144 = V_34 -> V_115 [ V_2 ] [ V_145 ] ;
V_131 = V_34 -> V_115 [ V_2 ] [ V_132 ] ;
return sprintf ( V_124 , L_14 ,
F_17 ( V_144 & 0x0f , ( V_131 & 0x07 ) ?
V_133 : V_134 ) ) ;
}
static T_4 F_120 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_144 , V_131 ;
F_50 ( & V_34 -> V_76 ) ;
V_144 = F_34 ( V_64 , F_71 ( V_2 , V_145 ) ) ;
V_131 = F_34 ( V_64 , F_71 ( V_2 , V_132 ) ) ;
V_144 = ( V_144 & 0xf0 ) | F_18 ( V_11 , ( V_131 & 0x07 ) ?
V_133 :
V_134 ) ;
V_34 -> V_115 [ V_2 ] [ V_145 ] = V_144 ;
F_39 ( V_64 , F_71 ( V_2 , V_145 ) , V_144 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_121 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_25 (
V_34 -> V_115 [ V_2 ] [ V_145 ] ) ) ;
}
static T_4 F_122 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_144 ;
F_50 ( & V_34 -> V_76 ) ;
V_144 = F_34 ( V_64 , F_71 ( V_2 , V_145 ) ) ;
V_144 = ( V_144 & 0x1f ) | ( F_26 ( V_11 ) << 5 & 0xe0 ) ;
V_34 -> V_115 [ V_2 ] [ V_145 ] = V_144 ;
F_39 ( V_64 , F_71 ( V_2 , V_145 ) , V_144 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_123 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 ,
F_27 ( V_34 -> V_100 >> 4 & 0x0f ) ) ;
}
static T_4 F_124 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_47 ;
F_50 ( & V_34 -> V_76 ) ;
V_47 = F_34 ( V_64 , V_101 ) ;
V_47 = ( V_47 & 0x0f ) | ( F_28 ( V_11 ) << 4 & 0xf0 ) ;
F_39 ( V_64 , V_101 , V_47 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_125 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 ,
F_27 ( V_34 -> V_100 & 0x0f ) ) ;
}
static T_4 F_126 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_47 ;
F_50 ( & V_34 -> V_76 ) ;
V_47 = F_34 ( V_64 , V_101 ) ;
V_47 = ( V_47 & 0xf0 ) | ( F_28 ( V_11 ) & 0x0f ) ;
F_39 ( V_64 , V_101 , V_47 ) ;
F_52 ( & V_34 -> V_76 ) ;
return 0 ;
}
static T_4 F_127 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_1 ( V_34 -> V_16 [ V_2 ] ) ) ;
}
static T_4 F_128 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , V_34 -> V_112 [ V_2 ] . V_118 ) ;
}
static T_4 F_129 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , V_34 -> V_112 [ V_2 ] . V_119 ) ;
}
static T_4 F_130 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , V_34 -> V_87 [ V_2 ] ) ;
}
static T_4 F_131 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_87 [ V_2 ] = F_29 ( V_11 ) ;
F_39 ( V_64 , F_57 ( V_2 ) ,
V_34 -> V_87 [ V_2 ] ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_132 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 ,
( V_34 -> V_91 & V_146 [ V_2 ] ) ? 1 : 0 ) ;
}
static T_4 F_133 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
if ( V_11 )
V_34 -> V_91 |= V_146 [ V_2 ] ;
else
V_34 -> V_91 &= ( ~ V_146 [ V_2 ] ) ;
F_39 ( V_64 , V_92 ,
V_34 -> V_91 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_134 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
T_1 V_147 ;
if ( V_2 == 1 )
V_147 = ( V_34 -> V_93 & 0xf0 ) >> 4 ;
else
V_147 = V_34 -> V_93 & 0x0f ;
return sprintf ( V_124 , L_14 , F_30 ( V_147 ) ) ;
}
static T_4 F_135 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
T_1 V_147 ;
F_50 ( & V_34 -> V_76 ) ;
V_147 = F_34 ( V_64 , V_94 ) ;
if ( V_2 == 1 )
V_147 = ( V_147 & 0x0f ) | ( F_31 ( V_11 ) << 4 ) ;
else
V_147 = ( V_147 & 0xf0 ) | F_31 ( V_11 ) ;
V_34 -> V_93 = V_147 ;
F_39 ( V_64 , V_94 , V_147 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_136 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
char * V_124 )
{
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , V_34 -> V_91 & 0x0f ) ;
}
static T_4 F_137 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
V_34 -> V_91 = ( V_34 -> V_91 & 0xf0 ) |
F_5 ( V_11 , 0 , 15 ) ;
F_39 ( V_64 , V_92 ,
V_34 -> V_91 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_138 ( struct V_74 * V_67 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , ( V_34 -> V_85 & 0x10 ) ? 1 : 0 ) ;
}
static T_4 F_139 ( struct V_74 * V_67 ,
struct V_122 * V_123 ,
const char * V_124 , T_5 V_43 )
{
struct V_63 * V_64 = F_48 ( V_67 ) ;
struct V_33 * V_34 = F_49 ( V_64 ) ;
T_6 V_11 = F_79 ( V_124 , NULL , 10 ) ;
F_50 ( & V_34 -> V_76 ) ;
if ( V_11 )
V_34 -> V_85 |= 0x10 ;
else
V_34 -> V_85 &= ~ 0x10 ;
F_39 ( V_64 , V_86 , V_34 -> V_85 ) ;
F_52 ( & V_34 -> V_76 ) ;
return V_43 ;
}
static T_4 F_140 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
int V_2 = ( F_75 ( V_123 ) ) -> V_125 ;
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 ,
V_34 -> V_107 . V_62 & ( 1 << ( V_2 + 4 ) ) ? 1 : 0 ) ;
}
static T_4 F_141 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_32 ( V_34 -> V_89 ) ) ;
}
static T_4 F_142 ( struct V_74 * V_67 , struct V_122 * V_123 ,
char * V_124 )
{
struct V_33 * V_34 = F_47 ( V_67 ) ;
return sprintf ( V_124 , L_14 , F_33 ( V_34 -> V_107 ) ) ;
}
static void F_143 ( struct V_63 * V_64 )
{
int V_41 ;
T_1 V_1 ;
V_1 = F_34 ( V_64 , V_148 ) ;
F_39 ( V_64 , V_148 ,
V_1 | ( V_149 ? 0x03 : 0x00 ) ) ;
if ( V_150 ) {
V_1 = F_34 ( V_64 , V_86 ) ;
F_39 ( V_64 , V_86 , V_1 | 0x08 ) ;
V_1 = F_34 ( V_64 , V_151 ) ;
F_39 ( V_64 , V_151 , V_1 | 0x02 ) ;
F_39 ( V_64 , V_152 , 0 ) ;
V_1 = F_34 ( V_64 , V_153 ) ;
V_1 &= ~ 0x03 ;
V_1 &= ~ ( V_56 [ 0 ] ? 0x10 : 0 ) ;
V_1 &= ~ ( V_56 [ 1 ] ? 0x20 : 0 ) ;
F_39 ( V_64 , V_153 , V_1 ) ;
}
V_1 = F_34 ( V_64 , V_86 ) ;
F_39 ( V_64 , V_86 , V_1 | 0x01 ) ;
for ( V_41 = 0 ; V_41 < 20 ; V_41 ++ ) {
F_144 ( 10 ) ;
if ( ( F_34 ( V_64 , V_86 ) & 0x80 ) == 0x80 )
return;
}
F_36 ( & V_64 -> V_67 , L_16
L_17 ) ;
}
static int F_145 ( struct V_63 * V_64 , struct V_154 * V_155 )
{
struct V_156 * V_157 = V_64 -> V_157 ;
int V_158 , V_159 ;
const char * V_160 ;
if ( ! F_146 ( V_157 , V_161 ) )
return - V_162 ;
V_158 = F_34 ( V_64 , V_163 ) ;
if ( V_158 != 0x01 ) {
F_61 ( & V_157 -> V_67 ,
L_18 , V_158 ) ;
return - V_162 ;
}
V_159 = F_34 ( V_64 , V_164 ) ;
switch ( V_159 ) {
case V_165 :
case V_166 :
V_160 = L_19 ;
break;
case V_167 :
case V_168 :
case V_169 :
V_160 = L_20 ;
break;
default:
F_61 ( & V_157 -> V_67 ,
L_21 , V_159 ) ;
return - V_162 ;
}
F_147 ( V_155 -> type , V_160 , V_170 ) ;
F_61 ( & V_157 -> V_67 , L_22 ,
V_64 -> V_160 , F_148 ( V_64 -> V_157 ) ,
V_64 -> V_171 ) ;
return 0 ;
}
static int F_149 ( struct V_63 * V_64 ,
const struct V_172 * V_173 )
{
struct V_33 * V_34 ;
int V_174 , V_175 ;
void (* V_80)( struct V_33 * , struct V_63 * );
V_175 = F_150 ( V_64 -> V_157 ) ;
if ( ( ( V_176 & V_175 ) == V_176 ) &&
( ! V_177 ) ) {
F_61 ( & V_64 -> V_67 , L_23 ) ;
V_80 = F_60 ;
} else if ( ( V_161 & V_175 ) == V_161 ) {
F_61 ( & V_64 -> V_67 , L_24
L_25 ) ;
V_80 = F_62 ;
} else {
F_61 ( & V_64 -> V_67 , L_26
L_27 ) ;
V_174 = - V_162 ;
goto V_178;
}
V_34 = F_151 ( sizeof( struct V_33 ) , V_179 ) ;
if ( ! V_34 ) {
F_61 ( & V_64 -> V_67 , L_28 ) ;
V_174 = - V_180 ;
goto V_178;
}
F_152 ( V_64 , V_34 ) ;
V_34 -> V_79 = 0 ;
V_34 -> V_80 = V_80 ;
F_153 ( & V_34 -> V_76 ) ;
F_143 ( V_64 ) ;
V_174 = F_154 ( & V_64 -> V_67 . V_181 , & V_182 ) ;
if ( V_174 )
goto V_183;
V_34 -> V_184 = F_155 ( & V_64 -> V_67 ) ;
if ( ! F_156 ( V_34 -> V_184 ) )
return 0 ;
V_174 = F_157 ( V_34 -> V_184 ) ;
F_38 ( & V_64 -> V_67 , L_29 ) ;
F_158 ( & V_64 -> V_67 . V_181 , & V_182 ) ;
V_183:
F_159 ( V_34 ) ;
V_178:
return V_174 ;
}
static int F_160 ( struct V_63 * V_64 )
{
struct V_33 * V_34 = F_49 ( V_64 ) ;
F_161 ( V_34 -> V_184 ) ;
F_158 ( & V_64 -> V_67 . V_181 , & V_182 ) ;
F_159 ( V_34 ) ;
return 0 ;
}
static int T_7 F_162 ( void )
{
return F_163 ( & V_185 ) ;
}
static void T_8 F_164 ( void )
{
F_165 ( & V_185 ) ;
}
