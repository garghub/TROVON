static int F_1 ( struct V_1 * V_2 , const enum V_3 V_4 ,
T_1 * V_5 , const T_2 V_6 )
{
int V_7 ;
struct V_8 V_9 [ 2 ] ;
T_1 V_10 [ 1 ] = { V_4 } ;
V_9 [ 0 ] . V_11 = V_2 -> V_12 -> V_13 ;
V_9 [ 0 ] . V_14 = 0 ;
V_9 [ 0 ] . V_5 = V_10 ;
V_9 [ 0 ] . V_15 = 1 ;
V_9 [ 1 ] . V_11 = V_2 -> V_12 -> V_13 ;
V_9 [ 1 ] . V_14 = V_16 ;
V_9 [ 1 ] . V_5 = V_5 ;
V_9 [ 1 ] . V_15 = V_6 ;
V_7 = F_2 ( V_2 -> V_17 , V_9 , 2 ) ;
if ( V_7 != 2 ) {
F_3 ( V_18 L_1 , V_19 , V_7 ) ;
return - V_20 ;
}
if ( V_21 ) {
int V_22 ;
F_4 ( L_2 , V_4 & 0x7f ) ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ )
F_3 ( V_23 L_3 , V_5 [ V_22 ] ) ;
F_3 ( L_4 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const enum V_3 V_4 ,
const T_1 * V_24 , const T_2 V_6 )
{
int V_7 ;
T_1 V_5 [ V_25 ] ;
struct V_8 V_9 ;
if ( 1 + V_6 > sizeof( V_5 ) ) {
F_3 ( V_26
L_5 , V_6 ) ;
return - V_27 ;
}
if ( V_21 ) {
int V_22 ;
F_4 ( L_6 , V_4 & 0x7f ) ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ )
F_3 ( V_23 L_3 , V_24 [ V_22 ] ) ;
F_3 ( L_4 ) ;
}
V_5 [ 0 ] = V_4 ;
memcpy ( & V_5 [ 1 ] , V_24 , V_6 ) ;
V_9 . V_11 = V_2 -> V_12 -> V_13 ;
V_9 . V_14 = 0 ;
V_9 . V_5 = V_5 ;
V_9 . V_15 = V_6 + 1 ;
V_7 = F_2 ( V_2 -> V_17 , & V_9 , 1 ) ;
if ( V_7 != 1 ) {
F_4 ( L_1 , V_19 , V_7 ) ;
return - V_20 ;
}
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 ,
const enum V_3 V_4 , T_1 * V_28 )
{
return F_1 ( V_2 , V_4 , V_28 , 1 ) ;
}
static inline int F_7 ( struct V_1 * V_2 ,
const enum V_3 V_4 , const T_1 V_28 )
{
return F_5 ( V_2 , V_4 , & V_28 , 1 ) ;
}
static inline T_3 F_8 ( T_3 V_29 , T_3 V_30 )
{
return ( V_29 + ( V_30 / 2 ) ) / V_30 ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 V_31 )
{
return F_7 ( V_2 , V_32 , V_31 ? 0x80 : 0x40 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_33 * V_22 )
{
int V_7 ;
T_1 V_34 ;
V_7 = F_6 ( V_2 , V_35 , & V_34 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_34 & 0x80 )
* V_22 = ( V_34 & 0x40 ) ? V_36 : V_37 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_3 * V_38 )
{
int V_7 ;
T_1 V_39 ;
T_1 V_40 ;
T_4 V_41 ;
T_4 V_42 ;
T_1 V_5 [ 2 ] ;
V_7 = F_6 ( V_2 , V_43 , & V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_39 & 0x80 ) {
V_7 = F_7 ( V_2 , V_44 , 0x03 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_45 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_42 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_4 ( L_7 ,
F_8 ( V_42 * 15625 , 4 ) ) ;
} else {
V_7 = F_7 ( V_2 , V_44 , 0x05 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_45 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_40 = ( ( V_5 [ 0 ] >> 5 ) & 0x07 ) * 32 ;
V_7 = F_1 ( V_2 , V_46 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_41 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_4 ( L_8 ,
V_41 , V_40 ) ;
F_4 ( L_9 ,
( ( ( V_2 -> V_47 * 8192 ) / ( V_41 + 8192 ) ) *
2 ) - V_40 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , enum V_48 * V_49 )
{
const enum V_48 V_50 [ 8 ] =
{ V_51 , V_52 , V_53 , V_54 , V_55 , V_56 ,
V_57 , V_57 } ;
int V_7 ;
T_1 V_58 ;
V_7 = F_6 ( V_2 , V_59 , & V_58 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_49 = V_50 [ ( V_58 >> 4 ) & 0x07 ] ;
return 0 ;
}
static int F_13 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_7 ( V_2 , V_63 ,
( V_2 -> V_64 == 6 ? 0x88 : 0x8c ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_14 ( 150 ) ;
V_7 = F_9 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
{
T_1 V_65 [ 8 ] = { 0x14 , 0x12 , 0x03 , 0x02 ,
0x01 , 0x00 , 0x00 , 0x00 } ;
V_7 = F_5 ( V_2 , V_66 , V_65 , sizeof( V_65 ) ) ;
if ( V_7 < 0 )
return V_7 ;
}
switch ( V_2 -> V_67 ) {
case V_68 :
V_7 = F_7 ( V_2 , V_69 , 0x80 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ 0 ] = 0x80 ;
V_5 [ 1 ] = 0xB0 ;
V_7 = F_5 ( V_2 , V_70 , V_5 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_70 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_71 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
V_5 [ 0 ] = F_8 ( V_2 -> V_47 * V_2 -> V_64 * 2 , 1000000 ) ;
V_5 [ 1 ] = F_8 ( V_2 -> V_47 , 22000 * 4 ) ;
V_7 = F_5 ( V_2 , V_72 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_73 , 0x32 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_2 -> V_67 ) {
case V_68 :
V_5 [ 0 ] = 0x33 ;
break;
default:
V_5 [ 0 ] = 0x53 ;
break;
}
V_7 = F_7 ( V_2 , V_74 , V_5 [ 0 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ 0 ] = 0x8c ;
V_5 [ 1 ] = 0x98 ;
V_7 = F_5 ( V_2 , V_75 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_76 , 0x69 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_15 ( struct V_60 * V_61 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_79 ;
if ( ( V_78 -> V_80 == 0 ) || ( V_78 -> V_80 > sizeof( V_78 -> V_9 ) ) )
return - V_27 ;
V_7 = F_6 ( V_2 , V_81 , & V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_5 ( V_2 , ( 0x80 | V_82 ) , V_78 -> V_9 , V_78 -> V_80 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_81 ,
( V_79 & 0x40 ) | ( ( V_78 -> V_80 - 1 ) << 3 )
| 0x04 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( 100 ) ;
if ( V_78 -> V_9 [ 0 ] & 0x02 ) {
V_7 = F_7 ( V_2 , V_81 , ( V_79 & 0x40 ) ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_17 ( struct V_60 * V_61 ,
const enum V_83 V_78 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
const T_1 V_84 [ 2 ] = { 0x02 , 0x03 } ;
int V_7 ;
T_1 V_79 ;
if ( V_78 > V_85 )
return - V_27 ;
V_7 = F_6 ( V_2 , V_81 , & V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_81 ,
( V_79 & 0x40 ) | V_84 [ V_78 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_18 ( struct V_60 * V_61 ,
const enum V_86 V_87 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
const T_1 V_88 [ 2 ] = { 0x01 , 0x00 } ;
int V_7 ;
T_1 V_79 ;
if ( V_87 > V_89 )
return - V_27 ;
V_7 = F_6 ( V_2 , V_81 , & V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_81 ,
( V_79 & 0x40 ) | V_88 [ V_87 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_19 ( struct V_60 * V_61 ,
const enum V_90 V_91 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
const T_1 V_92 [ 3 ] = { 0x00 , 0x40 , 0x00 } ;
T_1 V_28 ;
if ( V_91 > V_93 )
return - V_27 ;
V_28 = V_92 [ V_91 ] ;
if ( V_2 -> V_12 -> V_94 )
V_28 ^= 0x40 ;
return F_7 ( V_2 , V_81 , V_28 ) ;
}
static int F_20 ( struct V_60 * V_61 , enum V_95 * V_96 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_97 [ 3 ] ;
* V_96 = 0 ;
V_7 = F_1 ( V_2 , V_98 , V_97 , sizeof( V_97 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( L_10
L_11 , V_97 [ 0 ] , V_97 [ 1 ] , V_97 [ 2 ] ) ;
if ( V_97 [ 0 ] & 0xc0 )
* V_96 |= V_99 ;
if ( V_97 [ 0 ] & 0x04 )
* V_96 |= V_100 ;
if ( V_97 [ 2 ] & 0x02 )
* V_96 |= V_101 ;
if ( V_97 [ 2 ] & 0x04 )
* V_96 |= V_102 ;
if ( V_97 [ 0 ] & 0x01 )
* V_96 |= V_103 ;
return 0 ;
}
static int F_21 ( struct V_60 * V_61 , T_3 * V_104 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_5 [ 3 ] ;
V_7 = F_1 ( V_2 , V_105 , V_5 , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_104 = ( ( V_5 [ 0 ] << 16 ) | ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ) * 64 ;
return 0 ;
}
static int F_22 ( struct V_60 * V_61 ,
T_4 * V_106 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_5 [ 3 ] ;
T_4 V_107 ;
T_5 V_108 ;
V_7 = F_1 ( V_2 , V_109 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_107 = ( V_5 [ 0 ] << 6 ) | ( V_5 [ 1 ] >> 2 ) ;
V_108 = ( T_5 ) ( ( ( V_5 [ 1 ] & 0x03 ) << 14 ) | V_5 [ 2 ] << 6 ) >> 6 ;
* V_106 = V_107 ;
F_4 ( L_12 , V_107 , V_108 ) ;
return 0 ;
}
static int F_23 ( struct V_60 * V_61 , T_4 * V_110 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_1 ( V_2 , V_111 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_110 = 0xFFFF - ( ( ( ( V_5 [ 0 ] & 0x7f ) << 8 ) | V_5 [ 1 ] ) << 1 ) ;
return 0 ;
}
static int F_24 ( struct V_60 * V_61 , T_3 * V_112 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_1 ( V_2 , V_113 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_112 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
return 0 ;
}
static int F_25 ( struct V_60 * V_61 )
{
struct V_114 * V_115 = & V_61 -> V_116 ;
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_5 [ 5 ] , V_117 ;
T_4 V_38 ;
const T_1 V_50 [ 10 ] =
{ 0x00 , 0x01 , 0x02 , 0x04 , 0x3f , 0x08 , 0x10 , 0x20 , 0x3f , 0x3f } ;
const T_1 V_118 [ 3 ] = { 0x00 , 0x40 , 0x80 } ;
F_4 ( L_13 , V_19 , V_115 -> V_119 ) ;
if ( ( V_115 -> V_119 < V_61 -> V_120 . V_121 . V_122 )
|| ( V_115 -> V_119 > V_61 -> V_120 . V_121 . V_123 ) )
return - V_27 ;
if ( ( ( int ) V_115 -> V_124 < V_37 )
|| ( V_115 -> V_124 > V_36 ) )
return - V_27 ;
if ( ( V_115 -> V_125 < V_61 -> V_120 . V_121 . V_126 )
|| ( V_115 -> V_125 > V_61 -> V_120 . V_121 . V_127 ) )
return - V_27 ;
if ( ( ( int ) V_115 -> V_128 < V_129 )
|| ( V_115 -> V_128 > V_57 ) )
return - V_27 ;
if ( ( V_115 -> V_128 == V_130 )
|| ( V_115 -> V_128 == V_131 ) )
return - V_27 ;
switch ( V_2 -> V_67 ) {
case V_132 :
V_7 = F_6 ( V_2 , V_63 , & V_117 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_115 -> V_125 >= 30000000 ) {
if ( V_2 -> V_64 == 6 ) {
V_2 -> V_64 = 9 ;
V_7 = F_13 ( V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
}
} else {
if ( V_2 -> V_64 == 9 ) {
V_2 -> V_64 = 6 ;
V_7 = F_13 ( V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
}
}
break;
case V_133 :
case V_68 :
break;
default:
return - V_27 ;
}
if ( V_61 -> V_120 . V_134 . V_135 ) {
V_61 -> V_120 . V_134 . V_135 ( V_61 ) ;
if ( V_61 -> V_120 . V_136 )
V_61 -> V_120 . V_136 ( V_61 , 0 ) ;
}
V_38 = F_8 ( V_115 -> V_125 * 4 , 15625 ) ;
V_5 [ 0 ] = ( V_38 >> 8 ) & 0x3f ;
V_5 [ 1 ] = ( V_38 >> 0 ) & 0xff ;
V_5 [ 2 ] = V_118 [ V_115 -> V_124 ] | V_50 [ V_115 -> V_128 ] ;
V_5 [ 3 ] = 0x40 ;
if ( V_115 -> V_125 < 10000000 )
V_5 [ 3 ] |= 0x04 ;
V_5 [ 4 ] = 0x01 ;
V_7 = F_5 ( V_2 , V_43 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_9 ( V_2 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_60 * V_61 )
{
struct V_114 * V_115 = & V_61 -> V_116 ;
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
V_7 = F_10 ( V_2 , & V_115 -> V_124 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , & V_115 -> V_125 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , & V_115 -> V_128 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_27 ( struct V_60 * V_61 , int V_137 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
T_1 V_28 = 0x00 ;
int V_7 ;
switch ( V_2 -> V_67 ) {
case V_68 :
V_7 = F_6 ( V_2 , V_69 , & V_28 ) ;
if ( V_7 < 0 )
goto error;
V_28 &= 0x80 ;
break;
}
if ( V_137 )
V_28 |= 0x40 ;
else
V_28 &= ~ 0x40 ;
V_7 = F_7 ( V_2 , V_69 , V_28 ) ;
error:
return V_7 ;
}
static int F_28 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
int V_7 ;
T_1 V_12 ;
V_7 = F_9 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_67 == V_68 ) {
V_7 = F_7 ( V_2 , V_69 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_70 , 0x0d ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_6 ( V_2 , V_63 , & V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_63 , V_12 & 0x7f ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_29 ( struct V_60 * V_61 ,
struct V_138 * V_139 )
{
V_139 -> V_140 = 50 ;
V_139 -> V_141 = 0 ;
V_139 -> V_142 = 0 ;
return 0 ;
}
static void F_30 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
F_31 ( V_2 ) ;
}
struct V_60 * F_32 ( const struct V_143 * V_12 ,
struct V_144 * V_17 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_145 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_12 = V_12 ;
V_2 -> V_17 = V_17 ;
if ( F_6 ( V_2 , V_146 , & V_2 -> V_67 ) < 0 )
goto error;
memcpy ( & V_2 -> V_147 . V_120 , & V_148 ,
sizeof( struct V_149 ) ) ;
V_2 -> V_147 . V_62 = V_2 ;
switch ( V_2 -> V_67 ) {
case V_132 :
strcpy ( V_2 -> V_147 . V_120 . V_121 . V_150 , L_14 ) ;
V_2 -> V_47 = V_151 ;
V_2 -> V_64 = 9 ;
break;
case V_133 :
strcpy ( V_2 -> V_147 . V_120 . V_121 . V_150 , L_15 ) ;
V_2 -> V_47 = V_151 ;
V_2 -> V_64 = 6 ;
break;
case V_68 :
strcpy ( V_2 -> V_147 . V_120 . V_121 . V_150 , L_16 ) ;
V_2 -> V_47 = V_152 ;
V_2 -> V_64 = 9 ;
break;
default:
F_3 ( V_26 L_17
L_18 ) ;
goto error;
}
return & V_2 -> V_147 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
