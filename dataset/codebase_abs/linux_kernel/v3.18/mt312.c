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
T_4 * V_22 )
{
int V_7 ;
T_1 V_33 ;
V_7 = F_6 ( V_2 , V_34 , & V_33 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_33 & 0x80 )
* V_22 = ( V_33 & 0x40 ) ? V_35 : V_36 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_3 * V_37 )
{
int V_7 ;
T_1 V_38 ;
T_1 V_39 ;
T_5 V_40 ;
T_5 V_41 ;
T_1 V_5 [ 2 ] ;
V_7 = F_6 ( V_2 , V_42 , & V_38 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_38 & 0x80 ) {
V_7 = F_7 ( V_2 , V_43 , 0x03 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_44 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_41 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_4 ( L_7 ,
F_8 ( V_41 * 15625 , 4 ) ) ;
} else {
V_7 = F_7 ( V_2 , V_43 , 0x05 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_44 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_39 = ( ( V_5 [ 0 ] >> 5 ) & 0x07 ) * 32 ;
V_7 = F_1 ( V_2 , V_45 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_40 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_4 ( L_8 ,
V_40 , V_39 ) ;
F_4 ( L_9 ,
( ( ( V_2 -> V_46 * 8192 ) / ( V_40 + 8192 ) ) *
2 ) - V_39 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_6 * V_47 )
{
const T_6 V_48 [ 8 ] =
{ V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ,
V_55 , V_55 } ;
int V_7 ;
T_1 V_56 ;
V_7 = F_6 ( V_2 , V_57 , & V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_47 = V_48 [ ( V_56 >> 4 ) & 0x07 ] ;
return 0 ;
}
static int F_13 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_7 ( V_2 , V_61 ,
( V_2 -> V_62 == 6 ? 0x88 : 0x8c ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_14 ( 150 ) ;
V_7 = F_9 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
{
T_1 V_63 [ 8 ] = { 0x14 , 0x12 , 0x03 , 0x02 ,
0x01 , 0x00 , 0x00 , 0x00 } ;
V_7 = F_5 ( V_2 , V_64 , V_63 , sizeof( V_63 ) ) ;
if ( V_7 < 0 )
return V_7 ;
}
switch ( V_2 -> V_65 ) {
case V_66 :
V_7 = F_7 ( V_2 , V_67 , 0x80 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ 0 ] = 0x80 ;
V_5 [ 1 ] = 0xB0 ;
V_7 = F_5 ( V_2 , V_68 , V_5 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_68 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_69 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
V_5 [ 0 ] = F_8 ( V_2 -> V_46 * V_2 -> V_62 * 2 , 1000000 ) ;
V_5 [ 1 ] = F_8 ( V_2 -> V_46 , 22000 * 4 ) ;
V_7 = F_5 ( V_2 , V_70 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_71 , 0x32 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_2 -> V_65 ) {
case V_66 :
V_5 [ 0 ] = 0x33 ;
break;
default:
V_5 [ 0 ] = 0x53 ;
break;
}
V_7 = F_7 ( V_2 , V_72 , V_5 [ 0 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ 0 ] = 0x8c ;
V_5 [ 1 ] = 0x98 ;
V_7 = F_5 ( V_2 , V_73 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_74 , 0x69 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_15 ( struct V_58 * V_59 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_77 ;
if ( ( V_76 -> V_78 == 0 ) || ( V_76 -> V_78 > sizeof( V_76 -> V_9 ) ) )
return - V_27 ;
V_7 = F_6 ( V_2 , V_79 , & V_77 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_5 ( V_2 , ( 0x80 | V_80 ) , V_76 -> V_9 , V_76 -> V_78 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_79 ,
( V_77 & 0x40 ) | ( ( V_76 -> V_78 - 1 ) << 3 )
| 0x04 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( 100 ) ;
if ( V_76 -> V_9 [ 0 ] & 0x02 ) {
V_7 = F_7 ( V_2 , V_79 , ( V_77 & 0x40 ) ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_17 ( struct V_58 * V_59 , const T_7 V_76 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
const T_1 V_81 [ 2 ] = { 0x02 , 0x03 } ;
int V_7 ;
T_1 V_77 ;
if ( V_76 > V_82 )
return - V_27 ;
V_7 = F_6 ( V_2 , V_79 , & V_77 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_79 ,
( V_77 & 0x40 ) | V_81 [ V_76 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_18 ( struct V_58 * V_59 , const T_8 V_83 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
const T_1 V_84 [ 2 ] = { 0x01 , 0x00 } ;
int V_7 ;
T_1 V_77 ;
if ( V_83 > V_85 )
return - V_27 ;
V_7 = F_6 ( V_2 , V_79 , & V_77 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_79 ,
( V_77 & 0x40 ) | V_84 [ V_83 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_19 ( struct V_58 * V_59 , const T_9 V_86 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
const T_1 V_87 [ 3 ] = { 0x00 , 0x40 , 0x00 } ;
T_1 V_28 ;
if ( V_86 > V_88 )
return - V_27 ;
V_28 = V_87 [ V_86 ] ;
if ( V_2 -> V_12 -> V_89 )
V_28 ^= 0x40 ;
return F_7 ( V_2 , V_79 , V_28 ) ;
}
static int F_20 ( struct V_58 * V_59 , T_10 * V_90 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_91 [ 3 ] ;
* V_90 = 0 ;
V_7 = F_1 ( V_2 , V_92 , V_91 , sizeof( V_91 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( L_10
L_11 , V_91 [ 0 ] , V_91 [ 1 ] , V_91 [ 2 ] ) ;
if ( V_91 [ 0 ] & 0xc0 )
* V_90 |= V_93 ;
if ( V_91 [ 0 ] & 0x04 )
* V_90 |= V_94 ;
if ( V_91 [ 2 ] & 0x02 )
* V_90 |= V_95 ;
if ( V_91 [ 2 ] & 0x04 )
* V_90 |= V_96 ;
if ( V_91 [ 0 ] & 0x01 )
* V_90 |= V_97 ;
return 0 ;
}
static int F_21 ( struct V_58 * V_59 , T_3 * V_98 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_5 [ 3 ] ;
V_7 = F_1 ( V_2 , V_99 , V_5 , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_98 = ( ( V_5 [ 0 ] << 16 ) | ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ) * 64 ;
return 0 ;
}
static int F_22 ( struct V_58 * V_59 ,
T_5 * V_100 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_5 [ 3 ] ;
T_5 V_101 ;
T_11 V_102 ;
V_7 = F_1 ( V_2 , V_103 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_101 = ( V_5 [ 0 ] << 6 ) | ( V_5 [ 1 ] >> 2 ) ;
V_102 = ( T_11 ) ( ( ( V_5 [ 1 ] & 0x03 ) << 14 ) | V_5 [ 2 ] << 6 ) >> 6 ;
* V_100 = V_101 ;
F_4 ( L_12 , V_101 , V_102 ) ;
return 0 ;
}
static int F_23 ( struct V_58 * V_59 , T_5 * V_104 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_1 ( V_2 , V_105 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_104 = 0xFFFF - ( ( ( ( V_5 [ 0 ] & 0x7f ) << 8 ) | V_5 [ 1 ] ) << 1 ) ;
return 0 ;
}
static int F_24 ( struct V_58 * V_59 , T_3 * V_106 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_1 ( V_2 , V_107 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_106 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
return 0 ;
}
static int F_25 ( struct V_58 * V_59 )
{
struct V_108 * V_109 = & V_59 -> V_110 ;
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_5 [ 5 ] , V_111 ;
T_5 V_37 ;
const T_1 V_48 [ 10 ] =
{ 0x00 , 0x01 , 0x02 , 0x04 , 0x3f , 0x08 , 0x10 , 0x20 , 0x3f , 0x3f } ;
const T_1 V_112 [ 3 ] = { 0x00 , 0x40 , 0x80 } ;
F_4 ( L_13 , V_19 , V_109 -> V_113 ) ;
if ( ( V_109 -> V_113 < V_59 -> V_114 . V_115 . V_116 )
|| ( V_109 -> V_113 > V_59 -> V_114 . V_115 . V_117 ) )
return - V_27 ;
if ( ( ( int ) V_109 -> V_118 < V_36 )
|| ( V_109 -> V_118 > V_35 ) )
return - V_27 ;
if ( ( V_109 -> V_119 < V_59 -> V_114 . V_115 . V_120 )
|| ( V_109 -> V_119 > V_59 -> V_114 . V_115 . V_121 ) )
return - V_27 ;
if ( ( ( int ) V_109 -> V_122 < V_123 )
|| ( V_109 -> V_122 > V_55 ) )
return - V_27 ;
if ( ( V_109 -> V_122 == V_124 )
|| ( V_109 -> V_122 == V_125 ) )
return - V_27 ;
switch ( V_2 -> V_65 ) {
case V_126 :
V_7 = F_6 ( V_2 , V_61 , & V_111 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_109 -> V_119 >= 30000000 ) {
if ( V_2 -> V_62 == 6 ) {
V_2 -> V_62 = 9 ;
V_7 = F_13 ( V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
}
} else {
if ( V_2 -> V_62 == 9 ) {
V_2 -> V_62 = 6 ;
V_7 = F_13 ( V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
}
}
break;
case V_127 :
case V_66 :
break;
default:
return - V_27 ;
}
if ( V_59 -> V_114 . V_128 . V_129 ) {
V_59 -> V_114 . V_128 . V_129 ( V_59 ) ;
if ( V_59 -> V_114 . V_130 )
V_59 -> V_114 . V_130 ( V_59 , 0 ) ;
}
V_37 = F_8 ( V_109 -> V_119 * 4 , 15625 ) ;
V_5 [ 0 ] = ( V_37 >> 8 ) & 0x3f ;
V_5 [ 1 ] = ( V_37 >> 0 ) & 0xff ;
V_5 [ 2 ] = V_112 [ V_109 -> V_118 ] | V_48 [ V_109 -> V_122 ] ;
V_5 [ 3 ] = 0x40 ;
if ( V_109 -> V_119 < 10000000 )
V_5 [ 3 ] |= 0x04 ;
V_5 [ 4 ] = 0x01 ;
V_7 = F_5 ( V_2 , V_42 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_9 ( V_2 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_59 )
{
struct V_108 * V_109 = & V_59 -> V_110 ;
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
V_7 = F_10 ( V_2 , & V_109 -> V_118 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , & V_109 -> V_119 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , & V_109 -> V_122 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_27 ( struct V_58 * V_59 , int V_131 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
T_1 V_28 = 0x00 ;
int V_7 ;
switch ( V_2 -> V_65 ) {
case V_66 :
V_7 = F_6 ( V_2 , V_67 , & V_28 ) ;
if ( V_7 < 0 )
goto error;
V_28 &= 0x80 ;
break;
}
if ( V_131 )
V_28 |= 0x40 ;
else
V_28 &= ~ 0x40 ;
V_7 = F_7 ( V_2 , V_67 , V_28 ) ;
error:
return V_7 ;
}
static int F_28 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_7 ;
T_1 V_12 ;
V_7 = F_9 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_65 == V_66 ) {
V_7 = F_7 ( V_2 , V_67 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_68 , 0x0d ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_6 ( V_2 , V_61 , & V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_61 , V_12 & 0x7f ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_29 ( struct V_58 * V_59 ,
struct V_132 * V_133 )
{
V_133 -> V_134 = 50 ;
V_133 -> V_135 = 0 ;
V_133 -> V_136 = 0 ;
return 0 ;
}
static void F_30 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
F_31 ( V_2 ) ;
}
struct V_58 * F_32 ( const struct V_137 * V_12 ,
struct V_138 * V_17 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_139 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_12 = V_12 ;
V_2 -> V_17 = V_17 ;
if ( F_6 ( V_2 , V_140 , & V_2 -> V_65 ) < 0 )
goto error;
memcpy ( & V_2 -> V_141 . V_114 , & V_142 ,
sizeof( struct V_143 ) ) ;
V_2 -> V_141 . V_60 = V_2 ;
switch ( V_2 -> V_65 ) {
case V_126 :
strcpy ( V_2 -> V_141 . V_114 . V_115 . V_144 , L_14 ) ;
V_2 -> V_46 = V_145 ;
V_2 -> V_62 = 9 ;
break;
case V_127 :
strcpy ( V_2 -> V_141 . V_114 . V_115 . V_144 , L_15 ) ;
V_2 -> V_46 = V_145 ;
V_2 -> V_62 = 6 ;
break;
case V_66 :
strcpy ( V_2 -> V_141 . V_114 . V_115 . V_144 , L_16 ) ;
V_2 -> V_46 = V_146 ;
V_2 -> V_62 = 9 ;
break;
default:
F_3 ( V_26 L_17
L_18 ) ;
goto error;
}
return & V_2 -> V_141 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
