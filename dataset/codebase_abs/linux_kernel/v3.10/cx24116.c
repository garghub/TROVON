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
F_2 ( V_17 L_2
L_3 , V_15 , V_13 , V_3 , V_4 ) ;
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
F_2 ( L_4 ) ;
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
F_2 ( V_22 L_5 ,
V_15 , V_3 , V_12 ) ;
V_19 = F_3 ( V_2 -> V_16 , & V_7 , 1 ) ;
if ( V_19 != 1 ) {
F_2 ( V_17 L_6 ,
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
F_2 ( V_17 L_7 ,
V_15 , V_3 , V_19 ) ;
return V_19 ;
}
if ( V_14 > 1 )
F_2 ( V_22 L_8 ,
V_3 , V_24 [ 0 ] ) ;
return V_24 [ 0 ] ;
}
static int F_8 ( struct V_1 * V_2 ,
T_3 V_26 )
{
F_9 ( L_9 , V_15 , V_26 ) ;
switch ( V_26 ) {
case V_27 :
V_2 -> V_28 . V_29 = 0x00 ;
break;
case V_30 :
V_2 -> V_28 . V_29 = 0x04 ;
break;
case V_31 :
V_2 -> V_28 . V_29 = 0x0C ;
break;
default:
return - V_32 ;
}
V_2 -> V_28 . V_26 = V_26 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_4 V_33 , T_5 V_34 , T_6 V_35 )
{
int V_36 , V_19 = - V_37 ;
F_9 ( L_10 , V_15 , V_34 , V_35 ) ;
for ( V_36 = 0 ; V_36 < F_11 ( V_38 ) ; V_36 ++ ) {
if ( ( V_33 == V_38 [ V_36 ] . V_39 ) &&
( V_34 == V_38 [ V_36 ] . V_40 ) &&
( V_35 == V_38 [ V_36 ] . V_41 ) ) {
V_19 = V_36 ;
break;
}
}
return V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_4 V_42 , T_5 V_43 , T_6 V_41 )
{
int V_19 = 0 ;
F_9 ( L_10 , V_15 , V_43 , V_41 ) ;
V_19 = F_10 ( V_2 , V_42 , V_43 , V_41 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_28 . V_41 = V_41 ;
V_2 -> V_28 . V_44 = V_38 [ V_19 ] . V_45 ;
V_2 -> V_28 . V_46 = V_38 [ V_19 ] . V_47 ;
F_9 ( L_11 , V_15 ,
V_2 -> V_28 . V_46 , V_2 -> V_28 . V_44 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_7 V_48 )
{
F_9 ( L_9 , V_15 , V_48 ) ;
if ( ( V_48 > V_2 -> V_49 . V_50 . V_51 . V_52 ) ||
( V_48 < V_2 -> V_49 . V_50 . V_51 . V_53 ) ) {
F_9 ( L_12 , V_15 , V_48 ) ;
return - V_37 ;
}
V_2 -> V_28 . V_54 = V_48 ;
F_9 ( L_13 , V_15 , V_48 ) ;
return 0 ;
}
static int F_14 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
const struct V_58 * V_59 ;
int V_19 = 0 ;
F_9 ( L_14 , V_15 ) ;
if ( F_7 ( V_2 , 0x20 ) > 0 ) {
if ( V_2 -> V_60 )
return 0 ;
F_2 ( V_22 L_15 ,
V_15 , V_61 ) ;
V_19 = F_15 ( & V_59 , V_61 ,
V_2 -> V_16 -> V_62 . V_63 ) ;
F_2 ( V_22 L_16 ,
V_15 ) ;
if ( V_19 ) {
F_2 ( V_17 L_17
L_18 , V_15 ) ;
return V_19 ;
}
V_2 -> V_60 = 1 ;
V_19 = F_16 ( V_56 , V_59 ) ;
if ( V_19 )
F_2 ( V_17 L_19 ,
V_15 ) ;
F_17 ( V_59 ) ;
F_2 ( V_22 L_20 , V_15 ,
V_19 == 0 ? L_21 : L_22 ) ;
V_2 -> V_60 = 0 ;
}
return V_19 ;
}
static int F_18 ( struct V_55 * V_56 , struct V_64 * V_65 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_36 , V_19 ;
F_9 ( L_14 , V_15 ) ;
V_19 = F_14 ( V_56 ) ;
if ( V_19 != 0 ) {
F_2 ( V_17 L_23 ,
V_15 ) ;
return V_19 ;
}
for ( V_36 = 0 ; V_36 < V_65 -> V_12 ; V_36 ++ ) {
F_9 ( L_24 , V_15 , V_36 , V_65 -> args [ V_36 ] ) ;
F_1 ( V_2 , V_36 , V_65 -> args [ V_36 ] ) ;
}
F_1 ( V_2 , V_66 , 0x01 ) ;
while ( F_7 ( V_2 , V_66 ) ) {
F_19 ( 10 ) ;
if ( V_36 ++ > 64 ) {
F_2 ( V_67 L_25 ,
V_15 ) ;
return - V_18 ;
}
}
return 0 ;
}
static int F_16 ( struct V_55 * V_56 ,
const struct V_58 * V_59 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_64 V_65 ;
int V_36 , V_19 , V_12 , V_68 , V_69 ;
unsigned char V_70 [ 4 ] ;
F_9 ( L_26 , V_15 ) ;
F_9 ( L_27 ,
V_59 -> V_71 ,
V_59 -> V_4 [ 0 ] ,
V_59 -> V_4 [ 1 ] ,
V_59 -> V_4 [ V_59 -> V_71 - 2 ] ,
V_59 -> V_4 [ V_59 -> V_71 - 1 ] ) ;
if ( V_2 -> V_9 -> V_72 )
V_2 -> V_9 -> V_72 ( V_56 ) ;
F_1 ( V_2 , 0xE5 , 0x00 ) ;
F_1 ( V_2 , 0xF1 , 0x08 ) ;
F_1 ( V_2 , 0xF2 , 0x13 ) ;
F_1 ( V_2 , 0xe0 , 0x03 ) ;
F_1 ( V_2 , 0xe0 , 0x00 ) ;
F_1 ( V_2 , V_73 , 0x46 ) ;
F_1 ( V_2 , V_74 , 0x00 ) ;
F_1 ( V_2 , 0xF0 , 0x03 ) ;
F_1 ( V_2 , 0xF4 , 0x81 ) ;
F_1 ( V_2 , 0xF5 , 0x00 ) ;
F_1 ( V_2 , 0xF6 , 0x00 ) ;
if ( V_2 -> V_9 -> V_75 )
V_68 = V_2 -> V_9 -> V_75 ;
else
V_68 = V_76 ;
for ( V_69 = V_59 -> V_71 ; V_69 > 0 ; V_69 -= V_68 - 1 ) {
V_12 = V_69 ;
if ( V_12 > V_68 - 1 )
V_12 = V_68 - 1 ;
F_4 ( V_2 , 0xF7 , & V_59 -> V_4 [ V_59 -> V_71 - V_69 ] ,
V_12 ) ;
}
F_1 ( V_2 , 0xF4 , 0x10 ) ;
F_1 ( V_2 , 0xF0 , 0x00 ) ;
F_1 ( V_2 , 0xF8 , 0x06 ) ;
V_65 . args [ 0x00 ] = V_77 ;
V_65 . args [ 0x01 ] = 0x05 ;
V_65 . args [ 0x02 ] = 0xdc ;
V_65 . args [ 0x03 ] = 0xda ;
V_65 . args [ 0x04 ] = 0xae ;
V_65 . args [ 0x05 ] = 0xaa ;
V_65 . args [ 0x06 ] = 0x04 ;
V_65 . args [ 0x07 ] = 0x9d ;
V_65 . args [ 0x08 ] = 0xfc ;
V_65 . args [ 0x09 ] = 0x06 ;
V_65 . V_12 = 0x0a ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
F_1 ( V_2 , V_78 , 0x00 ) ;
V_65 . args [ 0x00 ] = V_79 ;
V_65 . args [ 0x01 ] = 0x00 ;
V_65 . args [ 0x02 ] = 0x00 ;
V_65 . V_12 = 0x03 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
F_1 ( V_2 , 0xe5 , 0x00 ) ;
V_65 . args [ 0x00 ] = V_80 ;
V_65 . args [ 0x01 ] = 0x01 ;
V_65 . args [ 0x02 ] = 0x75 ;
V_65 . args [ 0x03 ] = 0x00 ;
if ( V_2 -> V_9 -> V_81 )
V_65 . args [ 0x04 ] = V_2 -> V_9 -> V_81 ;
else
V_65 . args [ 0x04 ] = 0x02 ;
V_65 . args [ 0x05 ] = 0x00 ;
V_65 . V_12 = 0x06 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
V_65 . args [ 0x00 ] = V_82 ;
V_65 . V_12 = 0x02 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_65 . args [ 0x01 ] = V_36 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
V_70 [ V_36 ] = F_7 ( V_2 , V_83 ) ;
}
F_2 ( V_22 L_28 , V_15 ,
V_70 [ 0 ] , V_70 [ 1 ] , V_70 [ 2 ] , V_70 [ 3 ] ) ;
return 0 ;
}
static int F_20 ( struct V_55 * V_56 , T_8 * V_84 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_85 = F_7 ( V_2 , V_78 ) &
V_86 ;
F_9 ( L_29 , V_15 , V_85 ) ;
* V_84 = 0 ;
if ( V_85 & V_87 )
* V_84 |= V_88 ;
if ( V_85 & V_89 )
* V_84 |= V_90 ;
if ( V_85 & V_91 )
* V_84 |= V_92 ;
if ( V_85 & V_93 )
* V_84 |= V_94 | V_95 ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 , T_7 * V_96 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
F_9 ( L_14 , V_15 ) ;
* V_96 = ( F_7 ( V_2 , V_97 ) << 24 ) |
( F_7 ( V_2 , V_98 ) << 16 ) |
( F_7 ( V_2 , V_99 ) << 8 ) |
F_7 ( V_2 , V_100 ) ;
return 0 ;
}
static int F_22 ( struct V_55 * V_56 ,
T_2 * V_101 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_64 V_65 ;
int V_19 ;
T_2 V_102 ;
F_9 ( L_14 , V_15 ) ;
V_65 . args [ 0x00 ] = V_103 ;
V_65 . V_12 = 0x01 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
V_102 =
( F_7 ( V_2 ,
V_78 ) & V_104 ) |
( F_7 ( V_2 , V_105 ) << 6 ) ;
* V_101 = 0 - V_102 ;
F_9 ( L_30 ,
V_15 , V_102 , * V_101 ) ;
return 0 ;
}
static int F_23 ( struct V_55 * V_56 , T_2 * V_106 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
T_1 V_107 ;
static const T_7 V_108 [] = {
0x00000 , 0x0199A , 0x03333 , 0x04ccD , 0x06667 ,
0x08000 , 0x0999A , 0x0b333 , 0x0cccD , 0x0e667 ,
0x10000 , 0x1199A , 0x13333 , 0x14ccD , 0x16667 ,
0x18000 } ;
F_9 ( L_14 , V_15 ) ;
V_107 = F_7 ( V_2 , V_109 ) ;
if ( V_107 >= 0xa0 )
* V_106 = 0xffff ;
else
* V_106 = V_108 [ ( V_107 & 0xf0 ) >> 4 ] +
( V_108 [ ( V_107 & 0x0f ) ] >> 4 ) ;
F_9 ( L_31 , V_15 ,
V_107 , * V_106 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 , T_2 * V_106 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
F_9 ( L_14 , V_15 ) ;
* V_106 = F_7 ( V_2 , V_110 ) << 8 |
F_7 ( V_2 , V_109 ) ;
F_9 ( L_32 , V_15 , * V_106 ) ;
return 0 ;
}
static int F_25 ( struct V_55 * V_56 , T_2 * V_106 )
{
if ( V_111 == 1 )
return F_24 ( V_56 , V_106 ) ;
else
return F_23 ( V_56 , V_106 ) ;
}
static int F_26 ( struct V_55 * V_56 , T_7 * V_112 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
F_9 ( L_14 , V_15 ) ;
* V_112 = ( F_7 ( V_2 , V_113 ) << 8 ) |
F_7 ( V_2 , V_114 ) ;
return 0 ;
}
static void F_27 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
V_2 -> V_115 = V_2 -> V_28 ;
}
static int F_28 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_36 ;
F_9 ( L_33 , V_15 ,
F_7 ( V_2 , V_116 ) ) ;
for ( V_36 = 0 ; V_36 < 30 ; V_36 ++ ) {
if ( F_7 ( V_2 , V_116 ) & 0x20 )
return 0 ;
F_19 ( 10 ) ;
}
F_9 ( L_34 , V_15 ) ;
return - V_117 ;
}
static int F_29 ( struct V_55 * V_56 ,
T_9 V_118 )
{
struct V_64 V_65 ;
int V_19 ;
F_9 ( L_35 , V_15 ,
V_118 == V_119 ? L_36 :
V_118 == V_120 ? L_37 : L_38 ) ;
V_19 = F_28 ( V_56 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 100 ) ;
V_65 . args [ 0x00 ] = V_121 ;
V_65 . args [ 0x01 ] = ( V_118 == V_120 ? 0x01 : 0x00 ) ;
V_65 . V_12 = 0x02 ;
F_19 ( 15 ) ;
return F_18 ( V_56 , & V_65 ) ;
}
static int F_30 ( struct V_55 * V_56 ,
T_10 V_122 )
{
struct V_64 V_65 ;
int V_19 ;
F_9 ( L_9 , V_15 , V_122 ) ;
if ( ( V_122 != V_123 ) && ( V_122 != V_124 ) ) {
F_2 ( V_17 L_39 , V_15 , V_122 ) ;
return - V_32 ;
}
V_19 = F_28 ( V_56 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 15 ) ;
V_65 . args [ 0x00 ] = V_125 ;
V_65 . args [ 0x01 ] = 0x00 ;
V_65 . args [ 0x02 ] = 0x00 ;
switch ( V_122 ) {
case V_123 :
F_9 ( L_40 , V_15 ) ;
V_65 . args [ 0x03 ] = 0x01 ;
break;
case V_124 :
F_9 ( L_41 , V_15 ) ;
V_65 . args [ 0x03 ] = 0x00 ;
break;
}
V_65 . V_12 = 0x04 ;
F_19 ( 15 ) ;
return F_18 ( V_56 , & V_65 ) ;
}
static int F_31 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_64 V_65 ;
int V_19 ;
V_65 . args [ 0x00 ] = V_126 ;
V_65 . args [ 0x01 ] = 0x00 ;
V_65 . args [ 0x02 ] = 0x10 ;
V_65 . args [ 0x03 ] = 0x00 ;
V_65 . args [ 0x04 ] = 0x8f ;
V_65 . args [ 0x05 ] = 0x28 ;
V_65 . args [ 0x06 ] = ( V_127 == V_128 ) ? 0x00 : 0x01 ;
V_65 . args [ 0x07 ] = 0x01 ;
V_65 . V_12 = 0x08 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
V_2 -> V_129 . args [ 0x00 ] = V_130 ;
V_2 -> V_129 . args [ V_131 ] = V_132 ;
V_2 -> V_129 . args [ V_133 ] = 0x02 ;
V_2 -> V_129 . args [ V_134 ] = 0x00 ;
V_2 -> V_129 . args [ V_135 ] = 0x00 ;
V_2 -> V_129 . args [ V_136 ] = 0x00 ;
V_2 -> V_129 . V_12 = V_137 ;
return 0 ;
}
static int F_32 ( struct V_55 * V_56 ,
struct V_138 * V_33 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_36 , V_19 ;
if ( V_14 ) {
F_2 ( V_22 L_42 , V_15 ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_139 ; ) {
F_2 ( V_22 L_43 , V_33 -> V_7 [ V_36 ] ) ;
if ( ++ V_36 < V_33 -> V_139 )
F_2 ( V_22 L_44 ) ;
}
F_2 ( L_45 , V_127 ) ;
}
if ( V_33 -> V_139 > ( V_140 - V_137 ) )
return - V_32 ;
for ( V_36 = 0 ; V_36 < V_33 -> V_139 ; V_36 ++ )
V_2 -> V_129 . args [ V_137 + V_36 ] = V_33 -> V_7 [ V_36 ] ;
V_2 -> V_129 . args [ V_136 ] = V_33 -> V_139 ;
V_2 -> V_129 . V_12 = V_137 +
V_2 -> V_129 . args [ V_136 ] ;
if ( V_127 == V_141 )
return 0 ;
else if ( V_127 == V_128 )
V_2 -> V_129 . args [ V_131 ] = 0 ;
else if ( V_127 == V_142 ) {
if ( V_33 -> V_139 >= 4 && V_33 -> V_7 [ 2 ] == 0x38 )
V_2 -> V_129 . args [ V_131 ] =
( ( V_33 -> V_7 [ 3 ] & 4 ) >> 2 ) ;
if ( V_14 )
F_9 ( L_46 , V_15 ,
V_2 -> V_129 . args [ V_131 ] ) ;
}
V_19 = F_28 ( V_56 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 100 ) ;
V_19 = F_18 ( V_56 , & V_2 -> V_129 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( ( V_2 -> V_129 . args [ V_136 ] << 4 ) +
( ( V_127 == V_128 ) ? 30 : 60 ) ) ;
return 0 ;
}
static int F_33 ( struct V_55 * V_56 ,
T_11 V_143 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
int V_19 ;
F_9 ( L_47 , V_15 , V_143 , V_127 ) ;
if ( V_143 == V_144 )
V_2 -> V_129 . args [ V_131 ] =
V_132 ;
else if ( V_143 == V_145 )
V_2 -> V_129 . args [ V_131 ] =
V_146 ;
else
return - V_32 ;
if ( V_127 != V_141 )
return 0 ;
V_19 = F_28 ( V_56 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( 100 ) ;
V_19 = F_18 ( V_56 , & V_2 -> V_129 ) ;
if ( V_19 != 0 )
return V_19 ;
F_19 ( ( V_2 -> V_129 . args [ V_136 ] << 4 ) + 60 ) ;
return 0 ;
}
static void F_34 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
F_9 ( L_26 , V_15 ) ;
F_6 ( V_2 ) ;
}
struct V_55 * F_35 ( const struct V_147 * V_9 ,
struct V_148 * V_16 )
{
struct V_1 * V_2 = NULL ;
int V_19 ;
F_9 ( L_26 , V_15 ) ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_20 ) ;
if ( V_2 == NULL )
goto V_149;
V_2 -> V_9 = V_9 ;
V_2 -> V_16 = V_16 ;
V_19 = ( F_7 ( V_2 , 0xFF ) << 8 ) |
F_7 ( V_2 , 0xFE ) ;
if ( V_19 != 0x0501 ) {
F_2 ( V_22 L_48 ) ;
goto V_150;
}
memcpy ( & V_2 -> V_49 . V_50 , & V_151 ,
sizeof( struct V_152 ) ) ;
V_2 -> V_49 . V_57 = V_2 ;
return & V_2 -> V_49 ;
V_150: F_6 ( V_2 ) ;
V_149: return NULL ;
}
static int F_37 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_64 V_65 ;
int V_19 ;
F_9 ( L_14 , V_15 ) ;
F_1 ( V_2 , 0xe0 , 0 ) ;
F_1 ( V_2 , 0xe1 , 0 ) ;
F_1 ( V_2 , 0xea , 0 ) ;
V_65 . args [ 0x00 ] = V_153 ;
V_65 . args [ 0x01 ] = 0 ;
V_65 . V_12 = 0x02 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_31 ( V_56 ) ;
if ( V_19 != 0 )
return V_19 ;
return F_29 ( V_56 , V_119 ) ;
}
static int F_38 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_64 V_65 ;
int V_19 ;
F_9 ( L_14 , V_15 ) ;
V_65 . args [ 0x00 ] = V_153 ;
V_65 . args [ 0x01 ] = 1 ;
V_65 . V_12 = 0x02 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
F_1 ( V_2 , 0xea , 0xff ) ;
F_1 ( V_2 , 0xe1 , 1 ) ;
F_1 ( V_2 , 0xe0 , 1 ) ;
return 0 ;
}
static int F_39 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_154 * V_155 = & V_56 -> V_156 ;
struct V_64 V_65 ;
T_8 V_157 ;
int V_36 , V_84 , V_19 , V_158 = 1 ;
F_9 ( L_14 , V_15 ) ;
switch ( V_155 -> V_39 ) {
case V_159 :
F_9 ( L_49 , V_15 ) ;
if ( V_155 -> V_40 != V_160 ) {
F_9 ( L_50 ,
V_15 , V_155 -> V_40 ) ;
return - V_37 ;
}
V_2 -> V_28 . V_161 = V_162 ;
if ( V_155 -> V_163 != V_164 ) {
F_9 ( L_51 ,
V_15 , V_155 -> V_163 ) ;
return - V_37 ;
}
V_2 -> V_28 . V_165 = V_166 ;
break;
case V_167 :
F_9 ( L_52 , V_15 ) ;
if ( V_155 -> V_40 != V_168 && V_155 -> V_40 != V_160 ) {
F_9 ( L_50 ,
V_15 , V_155 -> V_40 ) ;
return - V_37 ;
}
switch ( V_155 -> V_169 ) {
case V_170 :
V_2 -> V_28 . V_161 = ( V_155 -> V_40 == V_160 )
? V_162 : V_171 ;
V_158 ++ ;
break;
case V_172 :
V_2 -> V_28 . V_161 = V_162 ;
break;
case V_173 :
V_2 -> V_28 . V_161 = V_171 ;
break;
default:
F_9 ( L_53 ,
V_15 , V_155 -> V_169 ) ;
return - V_37 ;
}
switch ( V_155 -> V_163 ) {
case V_174 :
V_2 -> V_28 . V_165 = V_175 ;
break;
case V_176 :
V_2 -> V_28 . V_165 = V_177 ;
break;
case V_164 :
V_2 -> V_28 . V_165 = V_166 ;
break;
case V_178 :
default:
F_9 ( L_51 ,
V_15 , V_155 -> V_163 ) ;
return - V_37 ;
}
break;
default:
F_9 ( L_54 ,
V_15 , V_155 -> V_39 ) ;
return - V_37 ;
}
V_2 -> V_28 . V_42 = V_155 -> V_39 ;
V_2 -> V_28 . V_40 = V_155 -> V_40 ;
V_2 -> V_28 . V_179 = V_155 -> V_179 ;
V_2 -> V_28 . V_169 = V_155 -> V_169 ;
V_2 -> V_28 . V_163 = V_155 -> V_163 ;
V_19 = F_8 ( V_2 , V_155 -> V_26 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_12 ( V_2 , V_155 -> V_39 , V_155 -> V_40 , V_155 -> V_180 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_13 ( V_2 , V_155 -> V_54 ) ;
if ( V_19 != 0 )
return V_19 ;
F_27 ( V_56 ) ;
F_9 ( L_55 , V_15 , V_2 -> V_115 . V_42 ) ;
F_9 ( L_56 , V_15 , V_2 -> V_115 . V_40 ) ;
F_9 ( L_57 , V_15 , V_2 -> V_115 . V_179 ) ;
F_9 ( L_58 , V_15 ,
V_2 -> V_115 . V_169 , V_2 -> V_115 . V_161 ) ;
F_9 ( L_59 , V_15 , V_158 ) ;
F_9 ( L_60 , V_15 ,
V_2 -> V_115 . V_163 , V_2 -> V_115 . V_165 ) ;
F_9 ( L_61 , V_15 , V_2 -> V_115 . V_54 ) ;
F_9 ( L_62 , V_15 ,
V_2 -> V_115 . V_41 , V_2 -> V_115 . V_46 , V_2 -> V_115 . V_44 ) ;
F_9 ( L_63 , V_15 ,
V_2 -> V_115 . V_26 , V_2 -> V_115 . V_29 ) ;
if ( V_2 -> V_9 -> V_181 )
V_2 -> V_9 -> V_181 ( V_56 , 0 ) ;
V_65 . args [ 0x00 ] = V_182 ;
V_65 . args [ 0x01 ] = 0x01 ;
V_65 . V_12 = 0x02 ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
return V_19 ;
V_65 . args [ 0x00 ] = V_183 ;
V_65 . args [ 0x01 ] = ( V_2 -> V_115 . V_179 & 0xff0000 ) >> 16 ;
V_65 . args [ 0x02 ] = ( V_2 -> V_115 . V_179 & 0x00ff00 ) >> 8 ;
V_65 . args [ 0x03 ] = ( V_2 -> V_115 . V_179 & 0x0000ff ) ;
V_65 . args [ 0x04 ] = ( ( V_2 -> V_115 . V_54 / 1000 ) & 0xff00 ) >> 8 ;
V_65 . args [ 0x05 ] = ( ( V_2 -> V_115 . V_54 / 1000 ) & 0x00ff ) ;
V_65 . args [ 0x06 ] = V_2 -> V_115 . V_29 ;
V_65 . args [ 0x07 ] = V_2 -> V_115 . V_44 | V_2 -> V_115 . V_161 ;
V_65 . args [ 0x08 ] = V_184 >> 8 ;
V_65 . args [ 0x09 ] = V_184 & 0xff ;
V_65 . args [ 0x0a ] = 0x00 ;
V_65 . args [ 0x0b ] = 0x00 ;
V_65 . args [ 0x0c ] = V_2 -> V_115 . V_165 ;
V_65 . args [ 0x0d ] = V_2 -> V_115 . V_46 ;
if ( V_2 -> V_115 . V_54 > 30000000 ) {
V_65 . args [ 0x0e ] = 0x04 ;
V_65 . args [ 0x0f ] = 0x00 ;
V_65 . args [ 0x10 ] = 0x01 ;
V_65 . args [ 0x11 ] = 0x77 ;
V_65 . args [ 0x12 ] = 0x36 ;
F_1 ( V_2 , V_73 , 0x44 ) ;
F_1 ( V_2 , V_74 , 0x01 ) ;
} else {
V_65 . args [ 0x0e ] = 0x06 ;
V_65 . args [ 0x0f ] = 0x00 ;
V_65 . args [ 0x10 ] = 0x00 ;
V_65 . args [ 0x11 ] = 0xFA ;
V_65 . args [ 0x12 ] = 0x24 ;
F_1 ( V_2 , V_73 , 0x46 ) ;
F_1 ( V_2 , V_74 , 0x00 ) ;
}
V_65 . V_12 = 0x13 ;
do {
V_84 = F_7 ( V_2 , V_78 )
& V_104 ;
F_1 ( V_2 , V_78 , V_84 ) ;
V_19 = F_18 ( V_56 , & V_65 ) ;
if ( V_19 != 0 )
break;
for ( V_36 = 0 ; V_36 < 50 ; V_36 ++ ) {
F_20 ( V_56 , & V_157 ) ;
V_84 = V_157 & ( V_88 | V_94 ) ;
if ( V_84 == ( V_88 | V_94 ) ) {
F_9 ( L_64 , V_15 ) ;
goto V_185;
}
F_19 ( 10 ) ;
}
F_9 ( L_65 , V_15 ) ;
if ( V_2 -> V_115 . V_169 == V_170 )
V_65 . args [ 0x07 ] ^= V_171 ;
} while ( -- V_158 );
V_185:
V_65 . args [ 0x00 ] = V_182 ;
V_65 . args [ 0x01 ] = 0x00 ;
V_65 . V_12 = 0x02 ;
return F_18 ( V_56 , & V_65 ) ;
}
static int F_40 ( struct V_55 * V_56 , bool V_186 ,
unsigned int V_187 , unsigned int * V_188 , T_8 * V_84 )
{
* V_188 = V_189 / 5 ;
if ( V_186 ) {
int V_19 = F_39 ( V_56 ) ;
if ( V_19 )
return V_19 ;
}
return F_20 ( V_56 , V_84 ) ;
}
static int F_41 ( struct V_55 * V_56 )
{
return V_190 ;
}
