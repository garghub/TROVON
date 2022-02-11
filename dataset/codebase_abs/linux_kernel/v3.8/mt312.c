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
T_1 V_5 [ V_6 + 1 ] ;
struct V_8 V_9 ;
if ( V_21 ) {
int V_22 ;
F_4 ( L_5 , V_4 & 0x7f ) ;
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
const enum V_3 V_4 , T_1 * V_25 )
{
return F_1 ( V_2 , V_4 , V_25 , 1 ) ;
}
static inline int F_7 ( struct V_1 * V_2 ,
const enum V_3 V_4 , const T_1 V_25 )
{
return F_5 ( V_2 , V_4 , & V_25 , 1 ) ;
}
static inline T_3 F_8 ( T_3 V_26 , T_3 V_27 )
{
return ( V_26 + ( V_27 / 2 ) ) / V_27 ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 V_28 )
{
return F_7 ( V_2 , V_29 , V_28 ? 0x80 : 0x40 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_4 * V_22 )
{
int V_7 ;
T_1 V_30 ;
V_7 = F_6 ( V_2 , V_31 , & V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_30 & 0x80 )
* V_22 = ( V_30 & 0x40 ) ? V_32 : V_33 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_3 * V_34 )
{
int V_7 ;
T_1 V_35 ;
T_1 V_36 ;
T_5 V_37 ;
T_5 V_38 ;
T_1 V_5 [ 2 ] ;
V_7 = F_6 ( V_2 , V_39 , & V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_35 & 0x80 ) {
V_7 = F_7 ( V_2 , V_40 , 0x03 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_41 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_38 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_4 ( L_6 ,
F_8 ( V_38 * 15625 , 4 ) ) ;
} else {
V_7 = F_7 ( V_2 , V_40 , 0x05 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_41 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_36 = ( ( V_5 [ 0 ] >> 5 ) & 0x07 ) * 32 ;
V_7 = F_1 ( V_2 , V_42 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_37 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_4 ( L_7 ,
V_37 , V_36 ) ;
F_4 ( L_8 ,
( ( ( V_2 -> V_43 * 8192 ) / ( V_37 + 8192 ) ) *
2 ) - V_36 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_6 * V_44 )
{
const T_6 V_45 [ 8 ] =
{ V_46 , V_47 , V_48 , V_49 , V_50 , V_51 ,
V_52 , V_52 } ;
int V_7 ;
T_1 V_53 ;
V_7 = F_6 ( V_2 , V_54 , & V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_44 = V_45 [ ( V_53 >> 4 ) & 0x07 ] ;
return 0 ;
}
static int F_13 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_7 ( V_2 , V_58 ,
( V_2 -> V_59 == 6 ? 0x88 : 0x8c ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_14 ( 150 ) ;
V_7 = F_9 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
{
T_1 V_60 [ 8 ] = { 0x14 , 0x12 , 0x03 , 0x02 ,
0x01 , 0x00 , 0x00 , 0x00 } ;
V_7 = F_5 ( V_2 , V_61 , V_60 , sizeof( V_60 ) ) ;
if ( V_7 < 0 )
return V_7 ;
}
switch ( V_2 -> V_62 ) {
case V_63 :
V_7 = F_7 ( V_2 , V_64 , 0x80 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ 0 ] = 0x80 ;
V_5 [ 1 ] = 0xB0 ;
V_7 = F_5 ( V_2 , V_65 , V_5 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_65 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_66 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
V_5 [ 0 ] = F_8 ( V_2 -> V_43 * V_2 -> V_59 * 2 , 1000000 ) ;
V_5 [ 1 ] = F_8 ( V_2 -> V_43 , 22000 * 4 ) ;
V_7 = F_5 ( V_2 , V_67 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_68 , 0x32 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_2 -> V_62 ) {
case V_63 :
V_5 [ 0 ] = 0x33 ;
break;
default:
V_5 [ 0 ] = 0x53 ;
break;
}
V_7 = F_7 ( V_2 , V_69 , V_5 [ 0 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ 0 ] = 0x8c ;
V_5 [ 1 ] = 0x98 ;
V_7 = F_5 ( V_2 , V_70 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_71 , 0x69 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_15 ( struct V_55 * V_56 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_74 ;
if ( ( V_73 -> V_75 == 0 ) || ( V_73 -> V_75 > sizeof( V_73 -> V_9 ) ) )
return - V_76 ;
V_7 = F_6 ( V_2 , V_77 , & V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_5 ( V_2 , ( 0x80 | V_78 ) , V_73 -> V_9 , V_73 -> V_75 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_77 ,
( V_74 & 0x40 ) | ( ( V_73 -> V_75 - 1 ) << 3 )
| 0x04 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( 100 ) ;
if ( V_73 -> V_9 [ 0 ] & 0x02 ) {
V_7 = F_7 ( V_2 , V_77 , ( V_74 & 0x40 ) ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_17 ( struct V_55 * V_56 , const T_7 V_73 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
const T_1 V_79 [ 2 ] = { 0x02 , 0x03 } ;
int V_7 ;
T_1 V_74 ;
if ( V_73 > V_80 )
return - V_76 ;
V_7 = F_6 ( V_2 , V_77 , & V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_77 ,
( V_74 & 0x40 ) | V_79 [ V_73 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_18 ( struct V_55 * V_56 , const T_8 V_81 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
const T_1 V_82 [ 2 ] = { 0x01 , 0x00 } ;
int V_7 ;
T_1 V_74 ;
if ( V_81 > V_83 )
return - V_76 ;
V_7 = F_6 ( V_2 , V_77 , & V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_77 ,
( V_74 & 0x40 ) | V_82 [ V_81 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_19 ( struct V_55 * V_56 , const T_9 V_84 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
const T_1 V_85 [ 3 ] = { 0x00 , 0x40 , 0x00 } ;
T_1 V_25 ;
if ( V_84 > V_86 )
return - V_76 ;
V_25 = V_85 [ V_84 ] ;
if ( V_2 -> V_12 -> V_87 )
V_25 ^= 0x40 ;
return F_7 ( V_2 , V_77 , V_25 ) ;
}
static int F_20 ( struct V_55 * V_56 , T_10 * V_88 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_89 [ 3 ] ;
* V_88 = 0 ;
V_7 = F_1 ( V_2 , V_90 , V_89 , sizeof( V_89 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( L_9
L_10 , V_89 [ 0 ] , V_89 [ 1 ] , V_89 [ 2 ] ) ;
if ( V_89 [ 0 ] & 0xc0 )
* V_88 |= V_91 ;
if ( V_89 [ 0 ] & 0x04 )
* V_88 |= V_92 ;
if ( V_89 [ 2 ] & 0x02 )
* V_88 |= V_93 ;
if ( V_89 [ 2 ] & 0x04 )
* V_88 |= V_94 ;
if ( V_89 [ 0 ] & 0x01 )
* V_88 |= V_95 ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 , T_3 * V_96 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_5 [ 3 ] ;
V_7 = F_1 ( V_2 , V_97 , V_5 , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_96 = ( ( V_5 [ 0 ] << 16 ) | ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ) * 64 ;
return 0 ;
}
static int F_22 ( struct V_55 * V_56 ,
T_5 * V_98 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_5 [ 3 ] ;
T_5 V_99 ;
T_11 V_100 ;
V_7 = F_1 ( V_2 , V_101 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_99 = ( V_5 [ 0 ] << 6 ) | ( V_5 [ 1 ] >> 2 ) ;
V_100 = ( T_11 ) ( ( ( V_5 [ 1 ] & 0x03 ) << 14 ) | V_5 [ 2 ] << 6 ) >> 6 ;
* V_98 = V_99 ;
F_4 ( L_11 , V_99 , V_100 ) ;
return 0 ;
}
static int F_23 ( struct V_55 * V_56 , T_5 * V_102 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_1 ( V_2 , V_103 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_102 = 0xFFFF - ( ( ( ( V_5 [ 0 ] & 0x7f ) << 8 ) | V_5 [ 1 ] ) << 1 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 , T_3 * V_104 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_5 [ 2 ] ;
V_7 = F_1 ( V_2 , V_105 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_104 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
return 0 ;
}
static int F_25 ( struct V_55 * V_56 )
{
struct V_106 * V_107 = & V_56 -> V_108 ;
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_5 [ 5 ] , V_109 ;
T_5 V_34 ;
const T_1 V_45 [ 10 ] =
{ 0x00 , 0x01 , 0x02 , 0x04 , 0x3f , 0x08 , 0x10 , 0x20 , 0x3f , 0x3f } ;
const T_1 V_110 [ 3 ] = { 0x00 , 0x40 , 0x80 } ;
F_4 ( L_12 , V_19 , V_107 -> V_111 ) ;
if ( ( V_107 -> V_111 < V_56 -> V_112 . V_113 . V_114 )
|| ( V_107 -> V_111 > V_56 -> V_112 . V_113 . V_115 ) )
return - V_76 ;
if ( ( ( int ) V_107 -> V_116 < V_33 )
|| ( V_107 -> V_116 > V_32 ) )
return - V_76 ;
if ( ( V_107 -> V_117 < V_56 -> V_112 . V_113 . V_118 )
|| ( V_107 -> V_117 > V_56 -> V_112 . V_113 . V_119 ) )
return - V_76 ;
if ( ( ( int ) V_107 -> V_120 < V_121 )
|| ( V_107 -> V_120 > V_52 ) )
return - V_76 ;
if ( ( V_107 -> V_120 == V_122 )
|| ( V_107 -> V_120 == V_123 ) )
return - V_76 ;
switch ( V_2 -> V_62 ) {
case V_124 :
V_7 = F_6 ( V_2 , V_58 , & V_109 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_107 -> V_117 >= 30000000 ) {
if ( V_2 -> V_59 == 6 ) {
V_2 -> V_59 = 9 ;
V_7 = F_13 ( V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
}
} else {
if ( V_2 -> V_59 == 9 ) {
V_2 -> V_59 = 6 ;
V_7 = F_13 ( V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
}
}
break;
case V_125 :
case V_63 :
break;
default:
return - V_76 ;
}
if ( V_56 -> V_112 . V_126 . V_127 ) {
V_56 -> V_112 . V_126 . V_127 ( V_56 ) ;
if ( V_56 -> V_112 . V_128 )
V_56 -> V_112 . V_128 ( V_56 , 0 ) ;
}
V_34 = F_8 ( V_107 -> V_117 * 4 , 15625 ) ;
V_5 [ 0 ] = ( V_34 >> 8 ) & 0x3f ;
V_5 [ 1 ] = ( V_34 >> 0 ) & 0xff ;
V_5 [ 2 ] = V_110 [ V_107 -> V_116 ] | V_45 [ V_107 -> V_120 ] ;
V_5 [ 3 ] = 0x40 ;
if ( V_107 -> V_117 < 10000000 )
V_5 [ 3 ] |= 0x04 ;
V_5 [ 4 ] = 0x01 ;
V_7 = F_5 ( V_2 , V_39 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_9 ( V_2 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 )
{
struct V_106 * V_107 = & V_56 -> V_108 ;
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
V_7 = F_10 ( V_2 , & V_107 -> V_116 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , & V_107 -> V_117 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , & V_107 -> V_120 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_27 ( struct V_55 * V_56 , int V_129 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
T_1 V_25 = 0x00 ;
int V_7 ;
switch ( V_2 -> V_62 ) {
case V_63 :
V_7 = F_6 ( V_2 , V_64 , & V_25 ) ;
if ( V_7 < 0 )
goto error;
V_25 &= 0x80 ;
break;
}
if ( V_129 )
V_25 |= 0x40 ;
else
V_25 &= ~ 0x40 ;
V_7 = F_7 ( V_2 , V_64 , V_25 ) ;
error:
return V_7 ;
}
static int F_28 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_7 ;
T_1 V_12 ;
V_7 = F_9 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_62 == V_63 ) {
V_7 = F_7 ( V_2 , V_64 , 0x00 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_65 , 0x0d ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_6 ( V_2 , V_58 , & V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_58 , V_12 & 0x7f ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_29 ( struct V_55 * V_56 ,
struct V_130 * V_131 )
{
V_131 -> V_132 = 50 ;
V_131 -> V_133 = 0 ;
V_131 -> V_134 = 0 ;
return 0 ;
}
static void F_30 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
F_31 ( V_2 ) ;
}
struct V_55 * F_32 ( const struct V_135 * V_12 ,
struct V_136 * V_17 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_137 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_12 = V_12 ;
V_2 -> V_17 = V_17 ;
if ( F_6 ( V_2 , V_138 , & V_2 -> V_62 ) < 0 )
goto error;
memcpy ( & V_2 -> V_139 . V_112 , & V_140 ,
sizeof( struct V_141 ) ) ;
V_2 -> V_139 . V_57 = V_2 ;
switch ( V_2 -> V_62 ) {
case V_124 :
strcpy ( V_2 -> V_139 . V_112 . V_113 . V_142 , L_13 ) ;
V_2 -> V_43 = V_143 ;
V_2 -> V_59 = 9 ;
break;
case V_125 :
strcpy ( V_2 -> V_139 . V_112 . V_113 . V_142 , L_14 ) ;
V_2 -> V_43 = V_143 ;
V_2 -> V_59 = 6 ;
break;
case V_63 :
strcpy ( V_2 -> V_139 . V_112 . V_113 . V_142 , L_15 ) ;
V_2 -> V_43 = V_144 ;
V_2 -> V_59 = 9 ;
break;
default:
F_3 ( V_145 L_16
L_17 ) ;
goto error;
}
return & V_2 -> V_139 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
