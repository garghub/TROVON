static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
if ( V_14 > 1 )
F_2 ( L_1 ,
V_15 , V_3 , V_4 ) ;
V_13 = F_3 ( V_2 -> V_16 , & V_7 , 1 ) ;
if ( V_13 != 1 ) {
F_2 ( V_17 L_2 ,
V_15 , V_13 , V_3 , V_4 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
const T_1 * V_4 , T_2 V_12 )
{
int V_19 = - V_18 ;
struct V_6 V_7 ;
T_1 * V_5 ;
V_5 = F_5 ( V_12 + 1 , V_20 ) ;
if ( V_5 == NULL ) {
F_2 ( L_3 ) ;
V_19 = - V_21 ;
goto error;
}
* ( V_5 ) = V_3 ;
memcpy ( V_5 + 1 , V_4 , V_12 ) ;
V_7 . V_8 = V_2 -> V_9 -> V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_5 = V_5 ;
V_7 . V_12 = V_12 + 1 ;
if ( V_14 > 1 )
F_2 ( V_22 L_4 ,
V_15 , V_3 , V_12 ) ;
V_19 = F_3 ( V_2 -> V_16 , & V_7 , 1 ) ;
if ( V_19 != 1 ) {
F_2 ( V_17 L_5 ,
V_15 , V_19 , V_3 ) ;
V_19 = - V_18 ;
}
error:
F_6 ( V_5 ) ;
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_19 ;
T_1 V_23 [] = { V_3 } ;
T_1 V_24 [] = { 0 } ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 ,
. V_5 = V_23 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_25 ,
. V_5 = V_24 , . V_12 = 1 }
} ;
V_19 = F_3 ( V_2 -> V_16 , V_7 , 2 ) ;
if ( V_19 != 2 ) {
F_2 ( V_17 L_6 ,
V_15 , V_3 , V_19 ) ;
return V_19 ;
}
if ( V_14 > 1 )
F_2 ( V_22 L_7 ,
V_3 , V_24 [ 0 ] ) ;
return V_24 [ 0 ] ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_26 V_27 )
{
F_9 ( L_8 , V_15 , V_27 ) ;
switch ( V_27 ) {
case V_28 :
V_2 -> V_29 . V_30 = 0x00 ;
break;
case V_31 :
V_2 -> V_29 . V_30 = 0x04 ;
break;
case V_32 :
V_2 -> V_29 . V_30 = 0x0C ;
break;
default:
return - V_33 ;
}
V_2 -> V_29 . V_27 = V_27 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_34 V_35 , enum V_36 V_37 , enum V_38 V_39 )
{
int V_40 , V_19 = - V_41 ;
F_9 ( L_9 , V_15 , V_37 , V_39 ) ;
for ( V_40 = 0 ; V_40 < F_11 ( V_42 ) ; V_40 ++ ) {
if ( ( V_35 == V_42 [ V_40 ] . V_43 ) &&
( V_37 == V_42 [ V_40 ] . V_44 ) &&
( V_39 == V_42 [ V_40 ] . V_45 ) ) {
V_19 = V_40 ;
break;
}
}
return V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_34 V_46 ,
enum V_36 V_47 ,
enum V_38 V_45 )
{
int V_19 = 0 ;
F_9 ( L_9 , V_15 , V_47 , V_45 ) ;
V_19 = F_10 ( V_2 , V_46 , V_47 , V_45 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_29 . V_45 = V_45 ;
V_2 -> V_29 . V_48 = V_42 [ V_19 ] . V_49 ;
V_2 -> V_29 . V_50 = V_42 [ V_19 ] . V_51 ;
F_9 ( L_10 , V_15 ,
V_2 -> V_29 . V_50 , V_2 -> V_29 . V_48 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 V_52 )
{
F_9 ( L_8 , V_15 , V_52 ) ;
if ( ( V_52 > V_2 -> V_53 . V_54 . V_55 . V_56 ) ||
( V_52 < V_2 -> V_53 . V_54 . V_55 . V_57 ) ) {
F_9 ( L_11 , V_15 , V_52 ) ;
return - V_41 ;
}
V_2 -> V_29 . V_58 = V_52 ;
F_9 ( L_12 , V_15 , V_52 ) ;
return 0 ;
}
static int F_14 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
const struct V_62 * V_63 ;
int V_19 = 0 ;
F_9 ( L_13 , V_15 ) ;
if ( F_7 ( V_2 , 0x20 ) > 0 ) {
if ( V_2 -> V_64 )
return 0 ;
F_2 ( V_22 L_14 ,
V_15 , V_65 ) ;
V_19 = F_15 ( & V_63 , V_65 ,
V_2 -> V_16 -> V_66 . V_67 ) ;
F_2 ( V_22 L_15 ,
V_15 ) ;
if ( V_19 ) {
F_2 ( V_17 L_16 ,
V_15 ) ;
return V_19 ;
}
V_2 -> V_64 = 1 ;
V_19 = F_16 ( V_60 , V_63 ) ;
if ( V_19 )
F_2 ( V_17 L_17 ,
V_15 ) ;
F_17 ( V_63 ) ;
F_2 ( V_22 L_18 , V_15 ,
V_19 == 0 ? L_19 : L_20 ) ;
V_2 -> V_64 = 0 ;
}
return V_19 ;
}
static int F_18 ( struct V_59 * V_60 , struct V_68 * V_69 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
int V_40 , V_19 ;
F_9 ( L_13 , V_15 ) ;
V_19 = F_14 ( V_60 ) ;
if ( V_19 != 0 ) {
F_2 ( V_17 L_21 ,
V_15 ) ;
return V_19 ;
}
for ( V_40 = 0 ; V_40 < V_69 -> V_12 ; V_40 ++ ) {
F_9 ( L_22 , V_15 , V_40 , V_69 -> args [ V_40 ] ) ;
F_1 ( V_2 , V_40 , V_69 -> args [ V_40 ] ) ;
}
F_1 ( V_2 , V_70 , 0x01 ) ;
while ( F_7 ( V_2 , V_70 ) ) {
F_19 ( 10 ) ;
if ( V_40 ++ > 64 ) {
F_2 ( V_71 L_23 ,
V_15 ) ;
return - V_18 ;
}
}
return 0 ;
}
static int F_16 ( struct V_59 * V_60 ,
const struct V_62 * V_63 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_68 V_69 ;
int V_40 , V_19 , V_12 , V_72 , V_73 ;
unsigned char V_74 [ 4 ] ;
F_9 ( L_24 , V_15 ) ;
F_9 ( L_25 ,
V_63 -> V_75 ,
V_63 -> V_4 [ 0 ] ,
V_63 -> V_4 [ 1 ] ,
V_63 -> V_4 [ V_63 -> V_75 - 2 ] ,
V_63 -> V_4 [ V_63 -> V_75 - 1 ] ) ;
if ( V_2 -> V_9 -> V_76 )
V_2 -> V_9 -> V_76 ( V_60 ) ;
F_1 ( V_2 , 0xE5 , 0x00 ) ;
F_1 ( V_2 , 0xF1 , 0x08 ) ;
F_1 ( V_2 , 0xF2 , 0x13 ) ;
F_1 ( V_2 , 0xe0 , 0x03 ) ;
F_1 ( V_2 , 0xe0 , 0x00 ) ;
F_1 ( V_2 , V_77 , 0x46 ) ;
F_1 ( V_2 , V_78 , 0x00 ) ;
F_1 ( V_2 , 0xF0 , 0x03 ) ;
F_1 ( V_2 , 0xF4 , 0x81 ) ;
F_1 ( V_2 , 0xF5 , 0x00 ) ;
F_1 ( V_2 , 0xF6 , 0x00 ) ;
if ( V_2 -> V_9 -> V_79 )
V_72 = V_2 -> V_9 -> V_79 ;
else
V_72 = V_80 ;
for ( V_73 = V_63 -> V_75 ; V_73 > 0 ; V_73 -= V_72 - 1 ) {
V_12 = V_73 ;
if ( V_12 > V_72 - 1 )
V_12 = V_72 - 1 ;
F_4 ( V_2 , 0xF7 , & V_63 -> V_4 [ V_63 -> V_75 - V_73 ] ,
V_12 ) ;
}
F_1 ( V_2 , 0xF4 , 0x10 ) ;
F_1 ( V_2 , 0xF0 , 0x00 ) ;
F_1 ( V_2 , 0xF8 , 0x06 ) ;
V_69 . args [ 0x00 ] = V_81 ;
V_69 . args [ 0x01 ] = 0x05 ;
V_69 . args [ 0x02 ] = 0xdc ;
V_69 . args [ 0x03 ] = 0xda ;
V_69 . args [ 0x04 ] = 0xae ;
V_69 . args [ 0x05 ] = 0xaa ;
V_69 . args [ 0x06 ] = 0x04 ;
V_69 . args [ 0x07 ] = 0x9d ;
V_69 . args [ 0x08 ] = 0xfc ;
V_69 . args [ 0x09 ] = 0x06 ;
V_69 . V_12 = 0x0a ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
F_1 ( V_2 , V_82 , 0x00 ) ;
V_69 . args [ 0x00 ] = V_83 ;
V_69 . args [ 0x01 ] = 0x00 ;
V_69 . args [ 0x02 ] = 0x00 ;
V_69 . V_12 = 0x03 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
F_1 ( V_2 , 0xe5 , 0x00 ) ;
V_69 . args [ 0x00 ] = V_84 ;
V_69 . args [ 0x01 ] = 0x01 ;
V_69 . args [ 0x02 ] = 0x75 ;
V_69 . args [ 0x03 ] = 0x00 ;
if ( V_2 -> V_9 -> V_85 )
V_69 . args [ 0x04 ] = V_2 -> V_9 -> V_85 ;
else
V_69 . args [ 0x04 ] = 0x02 ;
V_69 . args [ 0x05 ] = 0x00 ;
V_69 . V_12 = 0x06 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
V_69 . args [ 0x00 ] = V_86 ;
V_69 . V_12 = 0x02 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
V_69 . args [ 0x01 ] = V_40 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
V_74 [ V_40 ] = F_7 ( V_2 , V_87 ) ;
}
F_2 ( V_22 L_26 , V_15 ,
V_74 [ 0 ] , V_74 [ 1 ] , V_74 [ 2 ] , V_74 [ 3 ] ) ;
return 0 ;
}
static int F_20 ( struct V_59 * V_60 , enum V_88 * V_89 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
int V_90 = F_7 ( V_2 , V_82 ) &
V_91 ;
F_9 ( L_27 , V_15 , V_90 ) ;
* V_89 = 0 ;
if ( V_90 & V_92 )
* V_89 |= V_93 ;
if ( V_90 & V_94 )
* V_89 |= V_95 ;
if ( V_90 & V_96 )
* V_89 |= V_97 ;
if ( V_90 & V_98 )
* V_89 |= V_99 | V_100 ;
return 0 ;
}
static int F_21 ( struct V_59 * V_60 , T_3 * V_101 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
F_9 ( L_13 , V_15 ) ;
* V_101 = ( F_7 ( V_2 , V_102 ) << 24 ) |
( F_7 ( V_2 , V_103 ) << 16 ) |
( F_7 ( V_2 , V_104 ) << 8 ) |
F_7 ( V_2 , V_105 ) ;
return 0 ;
}
static int F_22 ( struct V_59 * V_60 ,
T_2 * V_106 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_68 V_69 ;
int V_19 ;
T_2 V_107 ;
F_9 ( L_13 , V_15 ) ;
V_69 . args [ 0x00 ] = V_108 ;
V_69 . V_12 = 0x01 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
V_107 =
( F_7 ( V_2 ,
V_82 ) & V_109 ) |
( F_7 ( V_2 , V_110 ) << 6 ) ;
* V_106 = 0 - V_107 ;
F_9 ( L_28 ,
V_15 , V_107 , * V_106 ) ;
return 0 ;
}
static int F_23 ( struct V_59 * V_60 , T_2 * V_111 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
T_1 V_112 ;
static const T_3 V_113 [] = {
0x00000 , 0x0199A , 0x03333 , 0x04ccD , 0x06667 ,
0x08000 , 0x0999A , 0x0b333 , 0x0cccD , 0x0e667 ,
0x10000 , 0x1199A , 0x13333 , 0x14ccD , 0x16667 ,
0x18000 } ;
F_9 ( L_13 , V_15 ) ;
V_112 = F_7 ( V_2 , V_114 ) ;
if ( V_112 >= 0xa0 )
* V_111 = 0xffff ;
else
* V_111 = V_113 [ ( V_112 & 0xf0 ) >> 4 ] +
( V_113 [ ( V_112 & 0x0f ) ] >> 4 ) ;
F_9 ( L_29 , V_15 ,
V_112 , * V_111 ) ;
return 0 ;
}
static int F_24 ( struct V_59 * V_60 , T_2 * V_111 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
F_9 ( L_13 , V_15 ) ;
* V_111 = F_7 ( V_2 , V_115 ) << 8 |
F_7 ( V_2 , V_114 ) ;
F_9 ( L_30 , V_15 , * V_111 ) ;
return 0 ;
}
static int F_25 ( struct V_59 * V_60 , T_2 * V_111 )
{
if ( V_116 == 1 )
return F_24 ( V_60 , V_111 ) ;
else
return F_23 ( V_60 , V_111 ) ;
}
static int F_26 ( struct V_59 * V_60 , T_3 * V_117 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
F_9 ( L_13 , V_15 ) ;
* V_117 = ( F_7 ( V_2 , V_118 ) << 8 ) |
F_7 ( V_2 , V_119 ) ;
return 0 ;
}
static void F_27 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
V_2 -> V_120 = V_2 -> V_29 ;
}
static int F_28 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
int V_40 ;
F_9 ( L_31 , V_15 ,
F_7 ( V_2 , V_121 ) ) ;
for ( V_40 = 0 ; V_40 < 30 ; V_40 ++ ) {
if ( F_7 ( V_2 , V_121 ) & 0x20 )
return 0 ;
F_19 ( 10 ) ;
}
F_9 ( L_32 , V_15 ) ;
return - V_122 ;
}
static int F_29 ( struct V_59 * V_60 ,
enum V_123 V_124 )
{
struct V_68 V_69 ;
int V_19 ;
F_9 ( L_33 , V_15 ,
V_124 == V_125 ? L_34 :
V_124 == V_126 ? L_35 : L_36 ) ;
V_19 = F_28 ( V_60 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 100 ) ;
V_69 . args [ 0x00 ] = V_127 ;
V_69 . args [ 0x01 ] = ( V_124 == V_126 ? 0x01 : 0x00 ) ;
V_69 . V_12 = 0x02 ;
F_19 ( 15 ) ;
return F_18 ( V_60 , & V_69 ) ;
}
static int F_30 ( struct V_59 * V_60 ,
enum V_128 V_129 )
{
struct V_68 V_69 ;
int V_19 ;
F_9 ( L_8 , V_15 , V_129 ) ;
if ( ( V_129 != V_130 ) && ( V_129 != V_131 ) ) {
F_2 ( V_17 L_37 , V_15 , V_129 ) ;
return - V_33 ;
}
V_19 = F_28 ( V_60 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 15 ) ;
V_69 . args [ 0x00 ] = V_132 ;
V_69 . args [ 0x01 ] = 0x00 ;
V_69 . args [ 0x02 ] = 0x00 ;
switch ( V_129 ) {
case V_130 :
F_9 ( L_38 , V_15 ) ;
V_69 . args [ 0x03 ] = 0x01 ;
break;
case V_131 :
F_9 ( L_39 , V_15 ) ;
V_69 . args [ 0x03 ] = 0x00 ;
break;
}
V_69 . V_12 = 0x04 ;
F_19 ( 15 ) ;
return F_18 ( V_60 , & V_69 ) ;
}
static int F_31 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_68 V_69 ;
int V_19 ;
V_69 . args [ 0x00 ] = V_133 ;
V_69 . args [ 0x01 ] = 0x00 ;
V_69 . args [ 0x02 ] = 0x10 ;
V_69 . args [ 0x03 ] = 0x00 ;
V_69 . args [ 0x04 ] = 0x8f ;
V_69 . args [ 0x05 ] = 0x28 ;
V_69 . args [ 0x06 ] = ( V_134 == V_135 ) ? 0x00 : 0x01 ;
V_69 . args [ 0x07 ] = 0x01 ;
V_69 . V_12 = 0x08 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
V_2 -> V_136 . args [ 0x00 ] = V_137 ;
V_2 -> V_136 . args [ V_138 ] = V_139 ;
V_2 -> V_136 . args [ V_140 ] = 0x02 ;
V_2 -> V_136 . args [ V_141 ] = 0x00 ;
V_2 -> V_136 . args [ V_142 ] = 0x00 ;
V_2 -> V_136 . args [ V_143 ] = 0x00 ;
V_2 -> V_136 . V_12 = V_144 ;
return 0 ;
}
static int F_32 ( struct V_59 * V_60 ,
struct V_145 * V_35 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
int V_40 , V_19 ;
if ( V_35 -> V_146 > sizeof( V_35 -> V_7 ) )
return - V_33 ;
if ( V_14 ) {
F_2 ( V_22 L_40 , V_15 ) ;
for ( V_40 = 0 ; V_40 < V_35 -> V_146 ; ) {
F_2 ( V_22 L_41 , V_35 -> V_7 [ V_40 ] ) ;
if ( ++ V_40 < V_35 -> V_146 )
F_2 ( V_22 L_42 ) ;
}
F_2 ( L_43 , V_134 ) ;
}
for ( V_40 = 0 ; V_40 < V_35 -> V_146 ; V_40 ++ )
V_2 -> V_136 . args [ V_144 + V_40 ] = V_35 -> V_7 [ V_40 ] ;
V_2 -> V_136 . args [ V_143 ] = V_35 -> V_146 ;
V_2 -> V_136 . V_12 = V_144 +
V_2 -> V_136 . args [ V_143 ] ;
if ( V_134 == V_147 )
return 0 ;
else if ( V_134 == V_135 )
V_2 -> V_136 . args [ V_138 ] = 0 ;
else if ( V_134 == V_148 ) {
if ( V_35 -> V_146 >= 4 && V_35 -> V_7 [ 2 ] == 0x38 )
V_2 -> V_136 . args [ V_138 ] =
( ( V_35 -> V_7 [ 3 ] & 4 ) >> 2 ) ;
if ( V_14 )
F_9 ( L_44 , V_15 ,
V_2 -> V_136 . args [ V_138 ] ) ;
}
V_19 = F_28 ( V_60 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 100 ) ;
V_19 = F_18 ( V_60 , & V_2 -> V_136 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( ( V_2 -> V_136 . args [ V_143 ] << 4 ) +
( ( V_134 == V_135 ) ? 30 : 60 ) ) ;
return 0 ;
}
static int F_33 ( struct V_59 * V_60 ,
enum V_149 V_150 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
int V_19 ;
F_9 ( L_45 , V_15 , V_150 , V_134 ) ;
if ( V_150 == V_151 )
V_2 -> V_136 . args [ V_138 ] =
V_139 ;
else if ( V_150 == V_152 )
V_2 -> V_136 . args [ V_138 ] =
V_153 ;
else
return - V_33 ;
if ( V_134 != V_147 )
return 0 ;
V_19 = F_28 ( V_60 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 100 ) ;
V_19 = F_18 ( V_60 , & V_2 -> V_136 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( ( V_2 -> V_136 . args [ V_143 ] << 4 ) + 60 ) ;
return 0 ;
}
static void F_34 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
F_9 ( L_24 , V_15 ) ;
F_6 ( V_2 ) ;
}
struct V_59 * F_35 ( const struct V_154 * V_9 ,
struct V_155 * V_16 )
{
struct V_1 * V_2 = NULL ;
int V_19 ;
F_9 ( L_24 , V_15 ) ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_20 ) ;
if ( V_2 == NULL )
goto V_156;
V_2 -> V_9 = V_9 ;
V_2 -> V_16 = V_16 ;
V_19 = ( F_7 ( V_2 , 0xFF ) << 8 ) |
F_7 ( V_2 , 0xFE ) ;
if ( V_19 != 0x0501 ) {
F_2 ( V_22 L_46 ) ;
goto V_157;
}
memcpy ( & V_2 -> V_53 . V_54 , & V_158 ,
sizeof( struct V_159 ) ) ;
V_2 -> V_53 . V_61 = V_2 ;
return & V_2 -> V_53 ;
V_157: F_6 ( V_2 ) ;
V_156: return NULL ;
}
static int F_37 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_68 V_69 ;
int V_19 ;
F_9 ( L_13 , V_15 ) ;
F_1 ( V_2 , 0xe0 , 0 ) ;
F_1 ( V_2 , 0xe1 , 0 ) ;
F_1 ( V_2 , 0xea , 0 ) ;
V_69 . args [ 0x00 ] = V_160 ;
V_69 . args [ 0x01 ] = 0 ;
V_69 . V_12 = 0x02 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_31 ( V_60 ) ;
if ( V_19 != 0 )
return V_19 ;
return F_29 ( V_60 , V_125 ) ;
}
static int F_38 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_68 V_69 ;
int V_19 ;
F_9 ( L_13 , V_15 ) ;
V_69 . args [ 0x00 ] = V_160 ;
V_69 . args [ 0x01 ] = 1 ;
V_69 . V_12 = 0x02 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
F_1 ( V_2 , 0xea , 0xff ) ;
F_1 ( V_2 , 0xe1 , 1 ) ;
F_1 ( V_2 , 0xe0 , 1 ) ;
return 0 ;
}
static int F_39 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_161 * V_162 = & V_60 -> V_163 ;
struct V_68 V_69 ;
enum V_88 V_164 ;
int V_40 , V_89 , V_19 , V_165 = 1 ;
F_9 ( L_13 , V_15 ) ;
switch ( V_162 -> V_43 ) {
case V_166 :
F_9 ( L_47 , V_15 ) ;
if ( V_162 -> V_44 != V_167 ) {
F_9 ( L_48 ,
V_15 , V_162 -> V_44 ) ;
return - V_41 ;
}
V_2 -> V_29 . V_168 = V_169 ;
if ( V_162 -> V_170 != V_171 ) {
F_9 ( L_49 ,
V_15 , V_162 -> V_170 ) ;
return - V_41 ;
}
V_2 -> V_29 . V_172 = V_173 ;
break;
case V_174 :
F_9 ( L_50 , V_15 ) ;
if ( V_162 -> V_44 != V_175 && V_162 -> V_44 != V_167 ) {
F_9 ( L_48 ,
V_15 , V_162 -> V_44 ) ;
return - V_41 ;
}
switch ( V_162 -> V_176 ) {
case V_177 :
V_2 -> V_29 . V_168 = ( V_162 -> V_44 == V_167 )
? V_169 : V_178 ;
V_165 ++ ;
break;
case V_179 :
V_2 -> V_29 . V_168 = V_169 ;
break;
case V_180 :
V_2 -> V_29 . V_168 = V_178 ;
break;
default:
F_9 ( L_51 ,
V_15 , V_162 -> V_176 ) ;
return - V_41 ;
}
switch ( V_162 -> V_170 ) {
case V_181 :
V_2 -> V_29 . V_172 = V_182 ;
break;
case V_183 :
V_2 -> V_29 . V_172 = V_184 ;
break;
case V_171 :
V_2 -> V_29 . V_172 = V_173 ;
break;
case V_185 :
default:
F_9 ( L_49 ,
V_15 , V_162 -> V_170 ) ;
return - V_41 ;
}
break;
default:
F_9 ( L_52 ,
V_15 , V_162 -> V_43 ) ;
return - V_41 ;
}
V_2 -> V_29 . V_46 = V_162 -> V_43 ;
V_2 -> V_29 . V_44 = V_162 -> V_44 ;
V_2 -> V_29 . V_186 = V_162 -> V_186 ;
V_2 -> V_29 . V_176 = V_162 -> V_176 ;
V_2 -> V_29 . V_170 = V_162 -> V_170 ;
V_19 = F_8 ( V_2 , V_162 -> V_27 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_12 ( V_2 , V_162 -> V_43 , V_162 -> V_44 , V_162 -> V_187 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_13 ( V_2 , V_162 -> V_58 ) ;
if ( V_19 != 0 )
return V_19 ;
F_27 ( V_60 ) ;
F_9 ( L_53 , V_15 , V_2 -> V_120 . V_46 ) ;
F_9 ( L_54 , V_15 , V_2 -> V_120 . V_44 ) ;
F_9 ( L_55 , V_15 , V_2 -> V_120 . V_186 ) ;
F_9 ( L_56 , V_15 ,
V_2 -> V_120 . V_176 , V_2 -> V_120 . V_168 ) ;
F_9 ( L_57 , V_15 , V_165 ) ;
F_9 ( L_58 , V_15 ,
V_2 -> V_120 . V_170 , V_2 -> V_120 . V_172 ) ;
F_9 ( L_59 , V_15 , V_2 -> V_120 . V_58 ) ;
F_9 ( L_60 , V_15 ,
V_2 -> V_120 . V_45 , V_2 -> V_120 . V_50 , V_2 -> V_120 . V_48 ) ;
F_9 ( L_61 , V_15 ,
V_2 -> V_120 . V_27 , V_2 -> V_120 . V_30 ) ;
if ( V_2 -> V_9 -> V_188 )
V_2 -> V_9 -> V_188 ( V_60 , 0 ) ;
V_69 . args [ 0x00 ] = V_189 ;
V_69 . args [ 0x01 ] = 0x01 ;
V_69 . V_12 = 0x02 ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
return V_19 ;
V_69 . args [ 0x00 ] = V_190 ;
V_69 . args [ 0x01 ] = ( V_2 -> V_120 . V_186 & 0xff0000 ) >> 16 ;
V_69 . args [ 0x02 ] = ( V_2 -> V_120 . V_186 & 0x00ff00 ) >> 8 ;
V_69 . args [ 0x03 ] = ( V_2 -> V_120 . V_186 & 0x0000ff ) ;
V_69 . args [ 0x04 ] = ( ( V_2 -> V_120 . V_58 / 1000 ) & 0xff00 ) >> 8 ;
V_69 . args [ 0x05 ] = ( ( V_2 -> V_120 . V_58 / 1000 ) & 0x00ff ) ;
V_69 . args [ 0x06 ] = V_2 -> V_120 . V_30 ;
V_69 . args [ 0x07 ] = V_2 -> V_120 . V_48 | V_2 -> V_120 . V_168 ;
V_69 . args [ 0x08 ] = V_191 >> 8 ;
V_69 . args [ 0x09 ] = V_191 & 0xff ;
V_69 . args [ 0x0a ] = 0x00 ;
V_69 . args [ 0x0b ] = 0x00 ;
V_69 . args [ 0x0c ] = V_2 -> V_120 . V_172 ;
V_69 . args [ 0x0d ] = V_2 -> V_120 . V_50 ;
if ( V_2 -> V_120 . V_58 > 30000000 ) {
V_69 . args [ 0x0e ] = 0x04 ;
V_69 . args [ 0x0f ] = 0x00 ;
V_69 . args [ 0x10 ] = 0x01 ;
V_69 . args [ 0x11 ] = 0x77 ;
V_69 . args [ 0x12 ] = 0x36 ;
F_1 ( V_2 , V_77 , 0x44 ) ;
F_1 ( V_2 , V_78 , 0x01 ) ;
} else {
V_69 . args [ 0x0e ] = 0x06 ;
V_69 . args [ 0x0f ] = 0x00 ;
V_69 . args [ 0x10 ] = 0x00 ;
V_69 . args [ 0x11 ] = 0xFA ;
V_69 . args [ 0x12 ] = 0x24 ;
F_1 ( V_2 , V_77 , 0x46 ) ;
F_1 ( V_2 , V_78 , 0x00 ) ;
}
V_69 . V_12 = 0x13 ;
do {
V_89 = F_7 ( V_2 , V_82 )
& V_109 ;
F_1 ( V_2 , V_82 , V_89 ) ;
V_19 = F_18 ( V_60 , & V_69 ) ;
if ( V_19 != 0 )
break;
for ( V_40 = 0 ; V_40 < 50 ; V_40 ++ ) {
F_20 ( V_60 , & V_164 ) ;
V_89 = V_164 & ( V_93 | V_99 ) ;
if ( V_89 == ( V_93 | V_99 ) ) {
F_9 ( L_62 , V_15 ) ;
goto V_192;
}
F_19 ( 10 ) ;
}
F_9 ( L_63 , V_15 ) ;
if ( V_2 -> V_120 . V_176 == V_177 )
V_69 . args [ 0x07 ] ^= V_178 ;
} while ( -- V_165 );
V_192:
V_69 . args [ 0x00 ] = V_189 ;
V_69 . args [ 0x01 ] = 0x00 ;
V_69 . V_12 = 0x02 ;
return F_18 ( V_60 , & V_69 ) ;
}
static int F_40 ( struct V_59 * V_60 , bool V_193 ,
unsigned int V_194 , unsigned int * V_195 , enum V_88 * V_89 )
{
* V_195 = V_196 / 5 ;
if ( V_193 ) {
int V_19 = F_39 ( V_60 ) ;
if ( V_19 )
return V_19 ;
}
return F_20 ( V_60 , V_89 ) ;
}
static int F_41 ( struct V_59 * V_60 )
{
return V_197 ;
}
