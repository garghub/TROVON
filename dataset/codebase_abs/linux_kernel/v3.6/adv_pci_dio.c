static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
V_7 [ 1 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
V_7 [ 1 ] |= F_2 ( V_2 -> V_13 + V_9 -> V_14 + V_11 ) << ( 8 * V_11 ) ;
return V_6 -> V_15 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
V_7 [ 1 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
V_7 [ 1 ] |= F_4 ( V_2 -> V_13 + V_9 -> V_14 + 2 * V_11 ) << ( 16 * V_11 ) ;
return V_6 -> V_15 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_16 &= ~ V_7 [ 0 ] ;
V_4 -> V_16 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
F_6 ( ( V_4 -> V_16 >> ( 8 * V_11 ) ) & 0xff ,
V_2 -> V_13 + V_9 -> V_14 + V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_16 &= ~ V_7 [ 0 ] ;
V_4 -> V_16 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
F_8 ( ( V_4 -> V_16 >> ( 16 * V_11 ) ) & 0xffff ,
V_2 -> V_13 + V_9 -> V_14 + 2 * V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_20 ;
V_17 = F_10 ( V_6 -> V_21 ) ;
V_18 = V_17 / 3 ;
V_19 = V_17 - ( 3 * V_18 ) ;
F_11 ( & V_4 -> V_22 , V_20 ) ;
V_7 [ 0 ] = F_12 ( V_2 -> V_13 + V_9 -> V_14 + ( V_23 * V_18 ) ,
0 , V_19 ) ;
F_13 ( & V_4 -> V_22 , V_20 ) ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_20 ;
V_17 = F_10 ( V_6 -> V_21 ) ;
V_18 = V_17 / 3 ;
V_19 = V_17 - ( 3 * V_18 ) ;
F_11 ( & V_4 -> V_22 , V_20 ) ;
F_15 ( V_2 -> V_13 + V_9 -> V_14 + ( V_23 * V_18 ) ,
0 , V_19 , V_7 [ 0 ] ) ;
F_13 ( & V_4 -> V_22 , V_20 ) ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_13 ;
int V_24 = 0 ;
unsigned long V_20 ;
V_17 = F_10 ( V_6 -> V_21 ) ;
V_18 = V_17 / 3 ;
V_19 = V_17 - ( 3 * V_18 ) ;
V_13 = V_2 -> V_13 + V_9 -> V_14 + ( V_23 * V_18 ) ;
F_11 ( & V_4 -> V_22 , V_20 ) ;
switch ( V_7 [ 0 ] ) {
case V_25 :
V_24 = F_17 ( V_13 , 0 , V_19 , V_7 [ 1 ] ) ;
if ( V_24 < 0 )
V_24 = - V_26 ;
break;
case V_27 :
V_7 [ 1 ] = F_18 ( V_13 , 0 , V_19 ) ;
break;
default:
V_24 = - V_26 ;
break;
}
F_13 ( & V_4 -> V_22 , V_20 ) ;
return V_24 < 0 ? V_24 : V_6 -> V_15 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned char * V_28 , unsigned char * V_29 ,
int V_30 )
{
int V_31 , V_32 , V_33 = 0 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
F_6 ( V_28 [ 0 ] , V_2 -> V_13 + V_34 ) ;
F_6 ( V_28 [ 1 ] , V_2 -> V_13 + V_35 ) ;
F_6 ( V_28 [ 2 ] , V_2 -> V_13 + V_36 ) ;
F_6 ( V_28 [ 3 ] , V_2 -> V_13 + V_37 ) ;
for ( V_32 = 0 ; V_32 < 251 ; V_32 ++ ) {
V_29 [ 2 ] = F_2 ( V_2 -> V_13 + V_38 ) ;
if ( V_29 [ 2 ] == V_28 [ 2 ] ) {
V_29 [ 0 ] = F_2 ( V_2 -> V_13 + V_39 ) ;
V_29 [ 1 ] = F_2 ( V_2 -> V_13 + V_40 ) ;
V_29 [ 3 ] = F_2 ( V_2 -> V_13 + V_41 ) ;
V_33 = 1 ;
break;
}
F_20 ( 1 ) ;
}
if ( V_33 )
return 0 ;
}
F_21 ( V_2 , L_1 ) ;
return - V_42 ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned char V_28 [ 4 ] = { 0x0 , 0x0 , V_43 , 0x0 } ;
unsigned char V_29 [ 4 ] ;
if ( F_2 ( V_2 -> V_13 + V_38 ) == V_43 )
return 0 ;
return F_19 ( V_2 , V_28 , V_29 , V_44 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned char * V_28 , unsigned char * V_29 )
{
if ( V_28 [ 2 ] == V_43 ) {
F_21 ( V_2 ,
L_2 ) ;
return - V_26 ;
}
if ( F_2 ( V_2 -> V_13 + V_38 ) == V_28 [ 2 ] ) {
int V_45 ;
V_45 = F_22 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
}
return F_19 ( V_2 , V_28 , V_29 , V_44 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_13 + V_41 ) ;
return V_6 -> V_15 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_24 ;
unsigned char V_28 [ 4 ] = {
0x00 ,
0x00 ,
V_46 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( V_7 [ 0 ] ) {
V_4 -> V_16 &= ~ V_7 [ 0 ] ;
V_4 -> V_16 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
V_28 [ 0 ] = V_4 -> V_16 ;
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_24 , V_15 ;
unsigned char V_28 [ 4 ] = {
F_10 ( V_6 -> V_21 ) & 0x07 ,
0x00 ,
V_47 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_7 [ V_15 ] = ( V_29 [ 1 ] << 8 ) + V_29 [ 0 ] ;
}
return V_15 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_24 ;
unsigned char V_17 = F_10 ( V_6 -> V_21 ) & 0x07 ;
unsigned char V_48 = 1 << V_17 ;
unsigned char V_28 [ 4 ] = {
V_7 [ 0 ] & 0xff ,
( V_7 [ 0 ] >> 8 ) & 0xff ,
V_49 + V_17 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( V_50 -> V_51 [ V_17 ] != ( V_7 [ 0 ] & 0xffff ) ) {
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_50 -> V_51 [ V_17 ] = V_7 [ 0 ] & 0xffff ;
}
V_28 [ 0 ] = V_48 ;
V_28 [ 2 ] = V_52 ;
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
if ( ! ( V_48 & V_50 -> V_53 ) ) {
V_28 [ 0 ] = V_48 ;
V_28 [ 2 ] = V_54 ;
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_50 -> V_53 |= V_48 ;
}
return 1 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_11 ;
unsigned char V_28 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_29 [ 4 ] ;
F_6 ( 0 , V_2 -> V_13 + V_55 ) ;
F_6 ( 0 , V_2 -> V_13 + V_56 ) ;
F_6 ( 0 , V_2 -> V_13 + V_57 ) ;
F_6 ( 0 , V_2 -> V_13 + V_58 ) ;
V_50 -> V_59 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_46 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_54 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_53 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_60 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_61 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_62 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_63 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 1 ] = 0x80 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_28 [ 2 ] = V_64 + V_11 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_65 [ V_11 ] = 0x8000 ;
}
V_28 [ 0 ] = 0x00 ;
V_28 [ 1 ] = 0x00 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_28 [ 2 ] = V_49 + V_11 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_51 [ V_11 ] = 0x0000 ;
}
V_28 [ 0 ] = 0xff ;
V_28 [ 2 ] = V_52 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_66 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_67 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_68 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_69 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_70 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_71 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_72 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_73 = 0x00 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_30 ( L_3 ) ;
switch ( V_74 -> V_75 ) {
case V_76 :
F_6 ( 0 , V_2 -> V_13 + V_77 ) ;
F_6 ( 0 , V_2 -> V_13 + V_77 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_78 ) ;
F_6 ( 0 , V_2 -> V_13 + V_78 + 1 ) ;
case V_79 :
F_6 ( 0 , V_2 -> V_13 + V_80 ) ;
F_6 ( 0x0f , V_2 -> V_13 + V_81 ) ;
F_6 ( 0 , V_2 -> V_13 + V_82 ) ;
break;
case V_83 :
F_6 ( 0 , V_2 -> V_13 + V_84 ) ;
F_6 ( 0 , V_2 -> V_13 + V_84 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_84 + 2 ) ;
F_6 ( 0 , V_2 -> V_13 + V_84 + 3 ) ;
break;
case V_85 :
F_6 ( 0 , V_2 -> V_13 + V_86 ) ;
F_6 ( 0 , V_2 -> V_13 + V_86 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_86 + 2 ) ;
F_6 ( 0 , V_2 -> V_13 + V_86 + 3 ) ;
F_17 ( V_2 -> V_13 + V_87 , 0 , 0 , V_88 ) ;
F_17 ( V_2 -> V_13 + V_87 , 0 , 1 , V_88 ) ;
F_17 ( V_2 -> V_13 + V_87 , 0 , 2 , V_88 ) ;
break;
case V_89 :
F_6 ( 0 , V_2 -> V_13 + V_90 ) ;
F_6 ( 0 , V_2 -> V_13 + V_90 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_91 ) ;
F_6 ( 0x0f , V_2 -> V_13 + V_92 ) ;
F_6 ( 0 , V_2 -> V_13 + V_93 ) ;
break;
case V_94 :
F_6 ( 0x88 , V_2 -> V_13 + V_95 ) ;
break;
case V_96 :
case V_97 :
F_6 ( 0x88 , V_2 -> V_13 + V_98 ) ;
break;
case V_99 :
F_8 ( 0 , V_2 -> V_13 + V_100 ) ;
F_8 ( 0 , V_2 -> V_13 + V_101 ) ;
F_8 ( 0 , V_2 -> V_13 + V_101 + 2 ) ;
F_8 ( 0 , V_2 -> V_13 + V_102 ) ;
F_8 ( 0 , V_2 -> V_13 + V_102 + 2 ) ;
break;
case V_103 :
F_6 ( 0x88 , V_2 -> V_13 + V_104 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_105 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_106 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_107 ) ;
case V_108 :
F_6 ( 0x88 , V_2 -> V_13 + V_109 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_110 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_111 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_112 ) ;
break;
case V_113 :
F_8 ( 0x08 , V_2 -> V_13 + V_114 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_115 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_116 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_117 ) ;
break;
case V_118 :
F_8 ( 0 , V_2 -> V_13 + V_100 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_114 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_115 ) ;
F_8 ( 0 , V_2 -> V_13 + V_119 ) ;
F_8 ( 0 , V_2 -> V_13 + V_119 + 2 ) ;
break;
case V_120 :
F_28 ( V_2 ) ;
break;
case V_121 :
F_8 ( 0x0101 , V_2 -> V_13 + V_122 ) ;
break;
}
F_30 ( L_4 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
struct V_3 * V_4 ;
int V_125 = 0 ;
V_4 = V_2 -> V_126 + V_125 ;
V_4 -> type = V_127 ;
V_4 -> V_128 = V_129 | V_130 | V_131 ;
V_4 -> V_132 = 8 ;
V_4 -> V_133 = 1 ;
V_4 -> V_134 = 8 ;
V_4 -> V_135 = & V_136 ;
V_4 -> V_137 = F_24 ;
V_125 ++ ;
V_4 = V_2 -> V_126 + V_125 ;
V_4 -> type = V_138 ;
V_4 -> V_128 = V_139 | V_130 | V_131 ;
V_4 -> V_132 = 8 ;
V_4 -> V_133 = 1 ;
V_4 -> V_134 = 8 ;
V_4 -> V_135 = & V_136 ;
V_4 -> V_16 = 0 ;
V_4 -> V_137 = F_25 ;
V_125 ++ ;
V_4 = V_2 -> V_126 + V_125 ;
V_4 -> type = V_140 ;
V_4 -> V_128 = V_139 | V_141 ;
V_4 -> V_132 = 2 ;
V_4 -> V_133 = 0xffffffff ;
V_4 -> V_134 = 2 ;
V_125 ++ ;
V_4 = V_2 -> V_126 + V_125 ;
V_4 -> type = V_142 ;
V_4 -> V_128 = V_129 | V_139 ;
V_4 -> V_132 = 8 ;
V_4 -> V_133 = 0xffff ;
V_4 -> V_134 = 8 ;
V_4 -> V_143 = F_26 ;
V_4 -> V_144 = F_27 ;
V_125 ++ ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_8 * V_9 , int V_125 )
{
V_4 -> type = V_127 ;
V_4 -> V_128 = V_129 | V_130 | V_131 | V_9 -> V_145 ;
if ( V_9 -> V_146 > 16 )
V_4 -> V_128 |= V_141 ;
V_4 -> V_132 = V_9 -> V_146 ;
V_4 -> V_133 = 1 ;
V_4 -> V_134 = V_9 -> V_146 ;
V_4 -> V_135 = & V_136 ;
switch ( V_74 -> V_147 ) {
case V_148 :
V_4 -> V_137 = F_1 ;
break;
case V_149 :
V_4 -> V_137 = F_3 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_8 * V_9 , int V_125 )
{
V_4 -> type = V_138 ;
V_4 -> V_128 = V_139 | V_130 | V_131 ;
if ( V_9 -> V_146 > 16 )
V_4 -> V_128 |= V_141 ;
V_4 -> V_132 = V_9 -> V_146 ;
V_4 -> V_133 = 1 ;
V_4 -> V_134 = V_9 -> V_146 ;
V_4 -> V_135 = & V_136 ;
V_4 -> V_16 = 0 ;
switch ( V_74 -> V_147 ) {
case V_148 :
V_4 -> V_137 = F_5 ;
break;
case V_149 :
V_4 -> V_137 = F_7 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 , int V_125 )
{
V_4 -> type = V_142 ;
V_4 -> V_128 = V_139 | V_129 ;
V_4 -> V_132 = V_9 -> V_146 ;
V_4 -> V_133 = 65535 ;
V_4 -> V_134 = V_9 -> V_146 ;
V_4 -> V_143 = F_9 ;
V_4 -> V_144 = F_14 ;
V_4 -> V_150 = F_16 ;
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static struct V_151 * F_35 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
struct V_151 * V_152 = NULL ;
int V_153 = V_124 -> V_154 [ 0 ] ;
int V_155 = V_124 -> V_154 [ 1 ] ;
int V_11 ;
F_36 (pcidev) {
if ( V_153 || V_155 ) {
if ( V_153 != V_152 -> V_153 -> V_156 ||
V_155 != F_37 ( V_152 -> V_157 ) )
continue;
}
for ( V_11 = 0 ; V_11 < F_38 ( V_158 ) ; ++ V_11 ) {
if ( V_158 [ V_11 ] . V_159 != V_152 -> V_160 )
continue;
if ( V_158 [ V_11 ] . V_161 != V_152 -> V_162 )
continue;
V_2 -> V_163 = V_158 + V_11 ;
return V_152 ;
}
}
F_39 ( V_2 -> V_164 ,
L_5 ,
V_153 , V_155 ) ;
return NULL ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
struct V_151 * V_152 ;
struct V_3 * V_4 ;
int V_24 , V_125 , V_165 , V_11 , V_166 ;
V_24 = F_41 ( V_2 , sizeof( struct V_167 ) ) ;
if ( V_24 < 0 )
return - V_168 ;
V_152 = F_35 ( V_2 , V_124 ) ;
if ( ! V_152 )
return - V_169 ;
F_42 ( V_2 , & V_152 -> V_2 ) ;
if ( F_43 ( V_152 , V_2 -> V_170 -> V_171 ) ) {
F_39 ( V_2 -> V_164 ,
L_6 ) ;
return - V_169 ;
}
V_2 -> V_13 = F_44 ( V_152 , V_74 -> V_172 ) ;
V_2 -> V_173 = V_74 -> V_174 ;
if ( V_74 -> V_75 == V_120 ) {
V_165 = 4 ;
} else {
V_165 = 0 ;
for ( V_11 = 0 ; V_11 < V_175 ; V_11 ++ )
if ( V_74 -> V_176 [ V_11 ] . V_146 )
V_165 ++ ;
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ )
if ( V_74 -> V_178 [ V_11 ] . V_146 )
V_165 ++ ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ )
V_165 += V_74 -> V_180 [ V_11 ] . V_12 ;
if ( V_74 -> V_181 . V_146 )
V_165 ++ ;
for ( V_11 = 0 ; V_11 < V_182 ; V_11 ++ )
if ( V_74 -> V_183 [ V_11 ] . V_146 )
V_165 ++ ;
}
V_24 = F_45 ( V_2 , V_165 ) ;
if ( V_24 )
return V_24 ;
V_125 = 0 ;
for ( V_11 = 0 ; V_11 < V_175 ; V_11 ++ )
if ( V_74 -> V_176 [ V_11 ] . V_146 ) {
V_4 = V_2 -> V_126 + V_125 ;
F_32 ( V_2 , V_4 , & V_74 -> V_176 [ V_11 ] , V_125 ) ;
V_125 ++ ;
}
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ )
if ( V_74 -> V_178 [ V_11 ] . V_146 ) {
V_4 = V_2 -> V_126 + V_125 ;
F_33 ( V_2 , V_4 , & V_74 -> V_178 [ V_11 ] , V_125 ) ;
V_125 ++ ;
}
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ )
for ( V_166 = 0 ; V_166 < V_74 -> V_180 [ V_11 ] . V_12 ; V_166 ++ ) {
V_4 = V_2 -> V_126 + V_125 ;
F_46 ( V_2 , V_4 , NULL ,
V_2 -> V_13 +
V_74 -> V_180 [ V_11 ] . V_14 +
V_184 * V_166 ) ;
V_125 ++ ;
}
if ( V_74 -> V_181 . V_146 ) {
V_4 = V_2 -> V_126 + V_125 ;
V_4 -> type = V_127 ;
F_32 ( V_2 , V_4 , & V_74 -> V_181 , V_125 ) ;
V_125 ++ ;
}
for ( V_11 = 0 ; V_11 < V_182 ; V_11 ++ )
if ( V_74 -> V_183 [ V_11 ] . V_146 ) {
V_4 = V_2 -> V_126 + V_125 ;
F_34 ( V_2 , V_4 , & V_74 -> V_183 [ V_11 ] , V_125 ) ;
V_125 ++ ;
}
if ( V_74 -> V_75 == V_120 )
F_31 ( V_2 , V_124 ) ;
V_50 -> V_185 = 1 ;
F_29 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = F_48 ( V_2 ) ;
int V_11 , V_166 ;
struct V_3 * V_4 ;
int V_125 ;
if ( V_2 -> V_10 ) {
if ( V_50 -> V_185 )
F_29 ( V_2 ) ;
V_125 = 0 ;
for ( V_11 = 0 ; V_11 < V_175 ; V_11 ++ ) {
if ( V_74 -> V_176 [ V_11 ] . V_146 )
V_125 ++ ;
}
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ ) {
if ( V_74 -> V_178 [ V_11 ] . V_146 )
V_125 ++ ;
}
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
for ( V_166 = 0 ; V_166 < V_74 -> V_180 [ V_11 ] . V_12 ; V_166 ++ ) {
V_4 = V_2 -> V_126 + V_125 ;
F_49 ( V_2 , V_4 ) ;
V_125 ++ ;
}
}
if ( V_74 -> V_181 . V_146 )
V_125 ++ ;
for ( V_11 = 0 ; V_11 < V_182 ; V_11 ++ )
if ( V_74 -> V_183 [ V_11 ] . V_146 )
V_125 ++ ;
for ( V_11 = 0 ; V_11 < V_2 -> V_165 ; V_11 ++ ) {
V_4 = V_2 -> V_126 + V_11 ;
V_4 -> V_10 = NULL ;
}
}
if ( V_152 ) {
if ( V_2 -> V_13 )
F_50 ( V_152 ) ;
F_51 ( V_152 ) ;
}
}
static int T_1 F_52 ( struct V_151 * V_2 ,
const struct V_186 * V_187 )
{
return F_53 ( V_2 , & V_188 ) ;
}
static void T_2 F_54 ( struct V_151 * V_2 )
{
F_55 ( V_2 ) ;
}
