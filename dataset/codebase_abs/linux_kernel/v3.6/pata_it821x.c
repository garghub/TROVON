static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = V_2 -> V_14 ;
T_2 V_15 ;
if ( V_11 -> V_16 == V_17 )
V_15 = V_5 >> 8 ;
else
V_15 = V_5 & 0xFF ;
F_3 ( V_7 , 0x54 + 4 * V_13 , V_15 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
int V_13 = V_2 -> V_14 ;
int V_18 = V_4 -> V_19 ;
T_2 V_15 ;
if ( V_11 -> V_16 == V_17 )
V_15 = V_5 >> 8 ;
else
V_15 = V_5 & 0xFF ;
if ( V_11 -> V_20 == 0 )
F_3 ( V_7 , 0x56 + 4 * V_13 + V_18 , V_15 ) ;
else {
F_3 ( V_7 , 0x56 + 4 * V_13 , V_15 ) ;
F_3 ( V_7 , 0x56 + 4 * V_13 + 1 , V_15 ) ;
}
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
T_2 V_18 = V_4 -> V_19 ;
struct V_3 * V_21 = F_6 ( V_4 ) ;
int clock , V_22 ;
T_2 V_23 ;
int V_24 = 0 ;
if ( V_11 -> V_25 [ 0 ] [ 0 ] > V_11 -> V_25 [ 1 ] [ 0 ] ) {
clock = V_11 -> V_25 [ 0 ] [ 1 ] ;
V_22 = V_11 -> V_25 [ 1 ] [ 1 ] ;
} else {
clock = V_11 -> V_25 [ 1 ] [ 1 ] ;
V_22 = V_11 -> V_25 [ 0 ] [ 1 ] ;
}
if ( clock == V_26 )
clock = V_22 ;
if ( clock == V_26 )
return;
if ( clock == V_11 -> V_16 )
return;
if ( clock == V_17 )
V_11 -> V_16 = V_17 ;
else {
V_11 -> V_16 = V_27 ;
V_24 = 1 ;
}
F_7 ( V_7 , 0x50 , & V_23 ) ;
V_23 &= ~ ( 1 << ( 1 + V_2 -> V_14 ) ) ;
V_23 |= V_24 << ( 1 + V_2 -> V_14 ) ;
F_3 ( V_7 , 0x50 , V_23 ) ;
if ( V_21 && V_11 -> V_28 [ 1 - V_18 ] != V_29 ) {
F_4 ( V_2 , V_21 , V_11 -> V_28 [ 1 - V_18 ] ) ;
F_1 ( V_2 , V_21 , V_11 -> V_30 [ 1 - V_18 ] ) ;
}
if ( V_11 -> V_28 [ V_18 ] != V_29 ) {
F_4 ( V_2 , V_4 , V_11 -> V_28 [ V_18 ] ) ;
F_1 ( V_2 , V_4 , V_11 -> V_30 [ V_18 ] ) ;
}
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const T_1 V_30 [] = { 0xAA88 , 0xA382 , 0xA181 , 0x3332 , 0x3121 } ;
static const T_2 V_31 [] = { V_17 , V_17 , V_17 , V_17 , V_26 } ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 = V_4 -> V_19 ;
int V_32 = V_4 -> V_33 - V_34 ;
V_11 -> V_25 [ V_18 ] [ 1 ] = V_31 [ V_32 ] ;
V_11 -> V_25 [ V_18 ] [ 0 ] = 1 ;
V_11 -> V_30 [ V_18 ] = V_30 [ V_32 ] ;
F_5 ( V_2 , V_4 ) ;
F_1 ( V_2 , V_4 , V_11 -> V_30 [ V_18 ] ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const T_1 V_35 [] = { 0x8866 , 0x3222 , 0x3121 } ;
static const T_2 V_36 [] = { V_26 , V_17 , V_26 } ;
static const T_1 V_28 [] = { 0x4433 , 0x4231 , 0x3121 , 0x2121 , 0x1111 , 0x2211 , 0x1111 } ;
static const T_2 V_37 [] = { V_26 , V_27 , V_26 , V_17 , V_17 , V_27 , V_17 } ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = V_2 -> V_14 ;
int V_18 = V_4 -> V_19 ;
T_2 V_15 ;
if ( V_4 -> V_38 >= V_39 ) {
int V_32 = V_4 -> V_38 - V_39 ;
V_11 -> V_25 [ V_18 ] [ 1 ] = V_37 [ V_32 ] ;
V_11 -> V_25 [ V_18 ] [ 0 ] = 3 ;
V_11 -> V_40 [ V_18 ] = V_41 ;
V_11 -> V_28 [ V_18 ] = V_28 [ V_32 ] ;
if ( V_32 >= 5 )
V_11 -> V_28 [ V_18 ] |= 0x8080 ;
F_7 ( V_7 , 0x50 , & V_15 ) ;
if ( V_11 -> V_20 )
V_15 &= V_13 ? 0x9F : 0xE7 ;
else
V_15 &= ~ ( 1 << ( 3 + 2 * V_13 + V_18 ) ) ;
F_3 ( V_7 , 0x50 , V_15 ) ;
F_5 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_4 , V_11 -> V_28 [ V_18 ] ) ;
} else {
int V_32 = V_4 -> V_38 - V_42 ;
V_11 -> V_25 [ V_18 ] [ 1 ] = V_36 [ V_32 ] ;
V_11 -> V_25 [ V_18 ] [ 0 ] = 2 ;
V_11 -> V_40 [ V_18 ] = V_35 [ V_32 ] ;
V_11 -> V_28 [ V_18 ] = V_29 ;
F_7 ( V_7 , 0x50 , & V_15 ) ;
if ( V_11 -> V_20 )
V_15 |= V_13 ? 0x60 : 0x18 ;
else
V_15 |= 1 << ( 3 + 2 * V_13 + V_18 ) ;
F_3 ( V_7 , 0x50 , V_15 ) ;
F_5 ( V_2 , V_4 ) ;
}
}
static void F_10 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_3 * V_4 = V_44 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 = V_4 -> V_19 ;
if ( V_11 -> V_40 [ V_18 ] != V_41 )
F_1 ( V_2 , V_4 , V_11 -> V_40 [ V_18 ] ) ;
else if ( V_11 -> V_28 [ V_18 ] != V_29 && V_11 -> V_20 )
F_4 ( V_2 , V_4 , V_11 -> V_28 [ V_18 ] ) ;
F_11 ( V_44 ) ;
}
static void F_12 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_3 * V_4 = V_44 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 = V_4 -> V_19 ;
F_13 ( V_44 ) ;
if ( V_11 -> V_40 [ V_18 ] != V_41 )
F_1 ( V_2 , V_4 , V_11 -> V_30 [ V_18 ] ) ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned int V_45 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_11 && V_45 != V_11 -> V_46 ) {
struct V_3 * V_4 = & V_2 -> V_47 . V_45 [ V_45 ] ;
F_1 ( V_2 , V_4 , V_11 -> V_30 [ V_4 -> V_19 ] ) ;
V_11 -> V_46 = V_45 ;
}
F_15 ( V_2 , V_45 ) ;
}
static unsigned int F_16 ( struct V_43 * V_44 )
{
switch( V_44 -> V_48 . V_49 )
{
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case 0xFC :
case V_64 :
return F_17 ( V_44 ) ;
}
F_18 ( V_65 L_1 , V_44 -> V_48 . V_49 ) ;
return V_66 ;
}
static unsigned int F_19 ( struct V_43 * V_44 )
{
F_14 ( V_44 -> V_2 , V_44 -> V_9 -> V_19 ) ;
return F_17 ( V_44 ) ;
}
static int F_20 ( struct V_67 * V_47 , struct V_3 * * V_68 )
{
struct V_3 * V_9 ;
F_21 (dev, link, ENABLED) {
V_9 -> V_33 = V_34 ;
V_9 -> V_38 = V_42 ;
if ( F_22 ( V_9 -> V_69 ) ) {
F_23 ( V_9 , L_2 ) ;
V_9 -> V_70 = V_42 ;
V_9 -> V_71 = V_72 ;
V_9 -> V_73 &= ~ V_74 ;
} else {
F_23 ( V_9 , L_3 ) ;
V_9 -> V_70 = V_34 ;
V_9 -> V_71 = V_75 ;
V_9 -> V_73 |= V_74 ;
}
}
return 0 ;
}
static void F_24 ( struct V_3 * V_4 )
{
unsigned char V_76 [ V_77 + 1 ] ;
F_25 ( V_4 -> V_69 , V_76 , V_78 , sizeof( V_76 ) ) ;
if ( V_4 -> V_79 > 255 )
V_4 -> V_79 = 255 ;
if ( strstr ( V_76 , L_4 ) ) {
F_23 ( V_4 , L_5 ,
V_4 -> V_69 [ 147 ] ? L_6 : L_7 ,
V_4 -> V_69 [ 129 ] ) ;
if ( V_4 -> V_69 [ 129 ] != 1 )
F_26 ( L_8 , V_4 -> V_69 [ 146 ] ) ;
F_26 ( L_9 ) ;
}
V_4 -> V_80 &= ~ V_81 ;
V_4 -> V_80 |= V_82 ;
}
static unsigned int F_27 ( struct V_3 * V_4 ,
struct V_83 * V_48 , T_1 * V_69 )
{
unsigned int V_84 ;
unsigned char V_76 [ V_77 + 1 ] ;
V_84 = F_28 ( V_4 , V_48 , V_69 ) ;
if ( V_84 )
return V_84 ;
F_25 ( V_69 , V_76 , V_78 , sizeof( V_76 ) ) ;
V_69 [ 83 ] &= ~ ( 1 << 12 ) ;
V_69 [ 83 ] &= ~ ( 1 << 13 ) ;
V_69 [ 84 ] &= ~ ( 1 << 6 ) ;
V_69 [ 85 ] &= ~ ( 1 << 10 ) ;
V_69 [ 76 ] = 0 ;
if ( strstr ( V_76 , L_4 ) ) {
V_69 [ 49 ] |= 0x0300 ;
V_69 [ 83 ] &= 0x7FFF ;
V_69 [ 83 ] |= 0x4400 ;
V_69 [ 86 ] |= 0x0400 ;
V_69 [ V_85 ] |= 0x1F ;
memset ( & V_69 [ V_86 ] , 0x20 , V_87 ) ;
}
return V_84 ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_12 ;
if ( F_30 ( V_44 ) < 2048 )
return - V_88 ;
if ( V_11 -> V_89 )
return - V_88 ;
if ( V_11 -> V_20 )
return - V_88 ;
return 0 ;
}
static void F_31 ( int V_90 , T_2 * V_91 )
{
unsigned char V_69 [ 41 ] ;
int V_92 = 0 ;
char * V_93 = L_7 ;
char V_94 [ 8 ] ;
char * V_95 = L_10 ;
static const char * V_96 [ 5 ] = {
L_11 , L_12 , L_13 , L_14 , L_15
} ;
if ( V_91 [ 52 ] > 4 )
return;
F_25 ( ( T_1 * ) V_91 , V_69 , 0 , 41 ) ;
if ( V_91 [ 51 ] ) {
V_92 = F_32 ( V_91 [ 51 ] ) ;
V_93 = L_16 ;
} else if ( V_91 [ 49 ] ) {
V_92 = F_32 ( V_91 [ 49 ] ) ;
V_93 = L_17 ;
}
if ( V_91 [ 76 ] )
V_95 = L_7 ;
if ( V_92 )
snprintf ( V_94 , 8 , L_18 , V_93 , V_92 - 1 ) ;
else
strcpy ( V_94 , L_19 ) ;
if ( V_91 [ 52 ] == 4 )
F_18 ( V_97 L_20 ,
V_90 , V_94 , V_96 [ V_91 [ 52 ] ] , V_69 , V_95 ) ;
else
F_18 ( V_97 L_21 ,
V_90 , V_94 , V_96 [ V_91 [ 52 ] ] , V_91 [ 53 ] , V_69 , V_95 ) ;
if ( V_91 [ 125 ] < 100 )
F_18 ( V_97 L_22 , V_90 , V_91 [ 125 ] ) ;
}
static T_2 * F_33 ( struct V_1 * V_2 , T_2 V_98 , int V_99 )
{
T_2 V_100 ;
int V_90 = 0 ;
T_1 * V_91 = F_34 ( V_99 , V_101 ) ;
if ( V_91 == NULL ) {
F_18 ( V_102 L_23 ) ;
return NULL ;
}
V_2 -> V_103 |= V_104 ;
F_35 ( V_2 -> V_103 , V_2 -> V_105 . V_106 ) ;
F_36 ( V_2 ) ;
F_35 ( V_107 , V_2 -> V_105 . V_108 ) ;
F_35 ( V_98 , V_2 -> V_105 . V_109 ) ;
F_37 ( 1 ) ;
while( V_90 ++ < 10 ) {
V_100 = F_38 ( V_2 -> V_105 . V_110 ) ;
if ( V_100 & V_111 ) {
F_39 ( V_91 ) ;
F_18 ( V_102 L_24 ) ;
return NULL ;
}
if ( V_100 & V_112 ) {
F_40 ( V_2 -> V_105 . V_113 , V_91 , V_99 / 2 ) ;
return ( T_2 * ) V_91 ;
}
F_41 ( 1 ) ;
}
F_39 ( V_91 ) ;
F_18 ( V_102 L_25 ) ;
return NULL ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_2 * V_91 ;
int V_114 ;
V_91 = F_33 ( V_2 , 0xFA , 512 ) ;
if ( V_91 != NULL ) {
F_18 ( V_97 L_26 ,
V_91 [ 505 ] ,
V_91 [ 506 ] ,
V_91 [ 507 ] ,
V_91 [ 508 ] ) ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ )
F_31 ( V_114 , V_91 + 128 * V_114 ) ;
F_39 ( V_91 ) ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
struct V_10 * V_11 ;
T_2 V_15 ;
int V_115 = F_44 ( V_2 ) ;
if ( V_115 < 0 )
return V_115 ;
V_11 = F_45 ( & V_7 -> V_9 , sizeof( struct V_10 ) , V_101 ) ;
if ( V_11 == NULL )
return - V_116 ;
V_2 -> V_12 = V_11 ;
F_7 ( V_7 , 0x50 , & V_15 ) ;
if ( V_15 & 1 ) {
V_11 -> V_89 = 1 ;
if ( V_2 -> V_14 == 0 )
F_42 ( V_2 ) ;
}
if ( V_15 & ( 1 << ( 1 + V_2 -> V_14 ) ) )
V_11 -> V_16 = V_27 ;
else
V_11 -> V_16 = V_17 ;
V_11 -> V_25 [ 0 ] [ 1 ] = V_26 ;
V_11 -> V_25 [ 1 ] [ 1 ] = V_26 ;
V_11 -> V_46 = - 1 ;
if ( V_7 -> V_117 == 0x10 ) {
V_11 -> V_20 = 1 ;
if ( ! V_11 -> V_89 )
F_18 (KERN_WARNING DRV_NAMEL_27 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_118 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
F_47 ( V_7 , 0x40 , & V_118 ) ;
if ( V_118 & ( 1 << ( 2 + V_2 -> V_14 ) ) )
return V_119 ;
return V_120 ;
}
static void F_48 ( struct V_6 * V_7 )
{
if ( V_7 -> V_121 != V_122 ||
V_7 -> V_45 != V_123 )
return;
F_3 ( V_7 , 0x5E , 0x01 ) ;
F_3 ( V_7 , 0x50 , 0x00 ) ;
F_49 ( V_7 , V_124 ,
V_125 | V_126 |
V_127 | V_128 ) ;
F_49 ( V_7 , 0x40 , 0xA0F3 ) ;
F_50 ( V_7 , 0x4C , 0x02040204 ) ;
F_3 ( V_7 , 0x42 , 0x36 ) ;
F_3 ( V_7 , V_129 , 0x20 ) ;
}
static int F_51 ( struct V_6 * V_7 , const struct V_130 * V_69 )
{
T_2 V_15 ;
static const struct V_131 V_132 = {
. V_73 = V_133 ,
. V_134 = V_135 ,
. V_136 = V_137 ,
. V_138 = V_139 ,
. V_140 = & V_141
} ;
static const struct V_131 V_142 = {
. V_73 = V_133 ,
. V_134 = V_135 ,
. V_136 = V_137 ,
. V_138 = V_139 ,
. V_140 = & V_143
} ;
static const struct V_131 V_144 = {
. V_73 = V_133 ,
. V_134 = V_135 ,
. V_136 = V_137 ,
. V_138 = V_139 ,
. V_140 = & V_145
} ;
static const struct V_131 V_146 = {
. V_73 = V_133 ,
. V_134 = V_135 ,
. V_136 = V_137 ,
. V_140 = & V_145
} ;
const struct V_131 * V_147 [] = { NULL , NULL } ;
static char * V_92 [ 2 ] = { L_28 , L_29 } ;
int V_148 ;
V_148 = F_52 ( V_7 ) ;
if ( V_148 )
return V_148 ;
if ( V_7 -> V_121 == V_149 ) {
if ( V_7 -> V_117 == 0x11 )
V_147 [ 0 ] = & V_146 ;
else
V_147 [ 0 ] = & V_144 ;
} else {
if ( V_150 ) {
F_18 (KERN_INFO DRV_NAME L_30 ) ;
F_48 ( V_7 ) ;
}
F_7 ( V_7 , 0x50 , & V_15 ) ;
V_15 &= 1 ;
F_18 (KERN_INFO DRV_NAMEL_31 ,
mode[conf]) ;
if ( V_15 == 0 )
V_147 [ 0 ] = & V_142 ;
else
V_147 [ 0 ] = & V_132 ;
}
return F_53 ( V_7 , V_147 , & V_151 , NULL , 0 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
struct V_152 * V_8 = F_55 ( & V_7 -> V_9 ) ;
int V_148 ;
V_148 = F_56 ( V_7 ) ;
if ( V_148 )
return V_148 ;
if ( V_150 )
F_48 ( V_7 ) ;
F_57 ( V_8 ) ;
return V_148 ;
}
