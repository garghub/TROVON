static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
V_7 [ 1 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
V_7 [ 1 ] |= F_2 ( V_2 -> V_13 + V_9 -> V_14 + V_11 ) << ( 8 * V_11 ) ;
return 2 ;
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
return 2 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_15 &= ~ V_7 [ 0 ] ;
V_4 -> V_15 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
F_6 ( ( V_4 -> V_15 >> ( 8 * V_11 ) ) & 0xff ,
V_2 -> V_13 + V_9 -> V_14 + V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_15 ;
return 2 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_15 &= ~ V_7 [ 0 ] ;
V_4 -> V_15 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
F_8 ( ( V_4 -> V_15 >> ( 16 * V_11 ) ) & 0xffff ,
V_2 -> V_13 + V_9 -> V_14 + 2 * V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_15 ;
return 2 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_16 , V_17 , V_18 ;
unsigned long V_19 ;
V_16 = F_10 ( V_6 -> V_20 ) ;
V_17 = V_16 / 3 ;
V_18 = V_16 - ( 3 * V_17 ) ;
F_11 ( & V_4 -> V_21 , V_19 ) ;
V_7 [ 0 ] = F_12 ( V_2 -> V_13 + V_9 -> V_14 + ( V_22 * V_17 ) ,
0 , V_18 ) ;
F_13 ( & V_4 -> V_21 , V_19 ) ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_16 , V_17 , V_18 ;
unsigned long V_19 ;
V_16 = F_10 ( V_6 -> V_20 ) ;
V_17 = V_16 / 3 ;
V_18 = V_16 - ( 3 * V_17 ) ;
F_11 ( & V_4 -> V_21 , V_19 ) ;
F_15 ( V_2 -> V_13 + V_9 -> V_14 + ( V_22 * V_17 ) ,
0 , V_18 , V_7 [ 0 ] ) ;
F_13 ( & V_4 -> V_21 , V_19 ) ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_16 , V_17 , V_18 ;
unsigned long V_13 ;
int V_23 = 0 ;
unsigned long V_19 ;
V_16 = F_10 ( V_6 -> V_20 ) ;
V_17 = V_16 / 3 ;
V_18 = V_16 - ( 3 * V_17 ) ;
V_13 = V_2 -> V_13 + V_9 -> V_14 + ( V_22 * V_17 ) ;
F_11 ( & V_4 -> V_21 , V_19 ) ;
switch ( V_7 [ 0 ] ) {
case V_24 :
V_23 = F_17 ( V_13 , 0 , V_18 , V_7 [ 1 ] ) ;
if ( V_23 < 0 )
V_23 = - V_25 ;
break;
case V_26 :
V_7 [ 1 ] = F_18 ( V_13 , 0 , V_18 ) ;
break;
default:
V_23 = - V_25 ;
break;
}
F_13 ( & V_4 -> V_21 , V_19 ) ;
return V_23 < 0 ? V_23 : V_6 -> V_27 ;
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
return - V_25 ;
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
return 2 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_23 ;
unsigned char V_28 [ 4 ] = {
0x00 ,
0x00 ,
V_46 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( V_7 [ 0 ] ) {
V_4 -> V_15 &= ~ V_7 [ 0 ] ;
V_4 -> V_15 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
V_28 [ 0 ] = V_4 -> V_15 ;
V_23 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_23 )
return V_23 ;
}
V_7 [ 1 ] = V_4 -> V_15 ;
return 2 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_23 , V_27 ;
unsigned char V_28 [ 4 ] = {
F_10 ( V_6 -> V_20 ) & 0x07 ,
0x00 ,
V_47 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
for ( V_27 = 0 ; V_27 < V_6 -> V_27 ; V_27 ++ ) {
V_23 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_23 )
return V_23 ;
V_7 [ V_27 ] = ( V_29 [ 1 ] << 8 ) + V_29 [ 0 ] ;
}
return V_27 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_23 ;
unsigned char V_16 = F_10 ( V_6 -> V_20 ) & 0x07 ;
unsigned char V_48 = 1 << V_16 ;
unsigned char V_28 [ 4 ] = {
V_7 [ 0 ] & 0xff ,
( V_7 [ 0 ] >> 8 ) & 0xff ,
V_49 + V_16 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( V_50 -> V_51 [ V_16 ] != ( V_7 [ 0 ] & 0xffff ) ) {
V_23 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_23 )
return V_23 ;
V_50 -> V_51 [ V_16 ] = V_7 [ 0 ] & 0xffff ;
}
V_28 [ 0 ] = V_48 ;
V_28 [ 2 ] = V_52 ;
V_23 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_23 )
return V_23 ;
if ( ! ( V_48 & V_50 -> V_53 ) ) {
V_28 [ 0 ] = V_48 ;
V_28 [ 2 ] = V_54 ;
V_23 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_23 )
return V_23 ;
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
case V_95 :
F_6 ( 0x88 , V_2 -> V_13 + V_96 ) ;
break;
case V_97 :
F_8 ( 0 , V_2 -> V_13 + V_98 ) ;
F_8 ( 0 , V_2 -> V_13 + V_99 ) ;
F_8 ( 0 , V_2 -> V_13 + V_99 + 2 ) ;
F_8 ( 0 , V_2 -> V_13 + V_100 ) ;
F_8 ( 0 , V_2 -> V_13 + V_100 + 2 ) ;
break;
case V_101 :
F_6 ( 0x88 , V_2 -> V_13 + V_102 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_103 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_104 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_105 ) ;
case V_106 :
F_6 ( 0x88 , V_2 -> V_13 + V_107 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_108 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_109 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_110 ) ;
break;
case V_111 :
F_8 ( 0x08 , V_2 -> V_13 + V_112 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_113 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_114 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_115 ) ;
break;
case V_116 :
F_8 ( 0 , V_2 -> V_13 + V_98 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_112 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_113 ) ;
F_8 ( 0 , V_2 -> V_13 + V_117 ) ;
F_8 ( 0 , V_2 -> V_13 + V_117 + 2 ) ;
break;
case V_118 :
F_28 ( V_2 ) ;
break;
case V_119 :
F_8 ( 0x0101 , V_2 -> V_13 + V_120 ) ;
break;
}
F_30 ( L_4 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_3 * V_4 ;
int V_123 = 0 ;
V_4 = V_2 -> V_124 + V_123 ;
V_4 -> type = V_125 ;
V_4 -> V_126 = V_127 | V_128 | V_129 ;
V_4 -> V_130 = 8 ;
V_4 -> V_131 = 1 ;
V_4 -> V_132 = 8 ;
V_4 -> V_133 = & V_134 ;
V_4 -> V_135 = F_24 ;
V_123 ++ ;
V_4 = V_2 -> V_124 + V_123 ;
V_4 -> type = V_136 ;
V_4 -> V_126 = V_137 | V_128 | V_129 ;
V_4 -> V_130 = 8 ;
V_4 -> V_131 = 1 ;
V_4 -> V_132 = 8 ;
V_4 -> V_133 = & V_134 ;
V_4 -> V_15 = 0 ;
V_4 -> V_135 = F_25 ;
V_123 ++ ;
V_4 = V_2 -> V_124 + V_123 ;
V_4 -> type = V_138 ;
V_4 -> V_126 = V_137 | V_139 ;
V_4 -> V_130 = 2 ;
V_4 -> V_131 = 0xffffffff ;
V_4 -> V_132 = 2 ;
V_123 ++ ;
V_4 = V_2 -> V_124 + V_123 ;
V_4 -> type = V_140 ;
V_4 -> V_126 = V_127 | V_137 ;
V_4 -> V_130 = 8 ;
V_4 -> V_131 = 0xffff ;
V_4 -> V_132 = 8 ;
V_4 -> V_141 = F_26 ;
V_4 -> V_142 = F_27 ;
V_123 ++ ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_8 * V_9 , int V_123 )
{
V_4 -> type = V_125 ;
V_4 -> V_126 = V_127 | V_128 | V_129 | V_9 -> V_143 ;
if ( V_9 -> V_144 > 16 )
V_4 -> V_126 |= V_139 ;
V_4 -> V_130 = V_9 -> V_144 ;
V_4 -> V_131 = 1 ;
V_4 -> V_132 = V_9 -> V_144 ;
V_4 -> V_133 = & V_134 ;
switch ( V_74 -> V_145 ) {
case V_146 :
V_4 -> V_135 = F_1 ;
break;
case V_147 :
V_4 -> V_135 = F_3 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_8 * V_9 , int V_123 )
{
V_4 -> type = V_136 ;
V_4 -> V_126 = V_137 | V_128 | V_129 ;
if ( V_9 -> V_144 > 16 )
V_4 -> V_126 |= V_139 ;
V_4 -> V_130 = V_9 -> V_144 ;
V_4 -> V_131 = 1 ;
V_4 -> V_132 = V_9 -> V_144 ;
V_4 -> V_133 = & V_134 ;
V_4 -> V_15 = 0 ;
switch ( V_74 -> V_145 ) {
case V_146 :
V_4 -> V_135 = F_5 ;
break;
case V_147 :
V_4 -> V_135 = F_7 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 , int V_123 )
{
V_4 -> type = V_140 ;
V_4 -> V_126 = V_137 | V_127 ;
V_4 -> V_130 = V_9 -> V_144 ;
V_4 -> V_131 = 65535 ;
V_4 -> V_132 = V_9 -> V_144 ;
V_4 -> V_141 = F_9 ;
V_4 -> V_142 = F_14 ;
V_4 -> V_148 = F_16 ;
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_121 * V_122 ,
struct V_149 * V_150 )
{
struct V_151 * V_152 , * V_153 ;
for ( V_152 = V_154 , V_153 = NULL ; V_152 != NULL ; V_153 = V_152 , V_152 = V_152 -> V_155 ) {
if ( V_152 -> V_150 == V_150 )
return 0 ;
}
if ( V_153 ) {
V_50 -> V_153 = V_153 ;
V_153 -> V_155 = V_50 ;
} else {
V_154 = V_50 ;
}
V_50 -> V_150 = V_150 ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_3 * V_4 ;
int V_23 , V_123 , V_156 , V_11 , V_157 ;
unsigned long V_13 ;
struct V_149 * V_150 = NULL ;
V_23 = F_37 ( V_2 , sizeof( struct V_151 ) ) ;
if ( V_23 < 0 )
return - V_158 ;
F_38 (pcidev) {
for ( V_11 = 0 ; V_11 < V_159 ; ++ V_11 ) {
if ( V_160 [ V_11 ] . V_161 != V_150 -> V_162 )
continue;
if ( V_160 [ V_11 ] . V_163 != V_150 -> V_164 )
continue;
if ( V_122 -> V_165 [ 0 ] || V_122 -> V_165 [ 1 ] ) {
if ( V_150 -> V_166 -> V_167 != V_122 -> V_165 [ 0 ] ||
F_39 ( V_150 -> V_168 ) != V_122 -> V_165 [ 1 ] ) {
continue;
}
}
V_23 = F_35 ( V_2 , V_122 , V_150 ) ;
if ( V_23 != 1 )
continue;
V_2 -> V_169 = V_160 + V_11 ;
break;
}
if ( V_2 -> V_169 )
break;
}
if ( ! V_2 -> V_169 ) {
F_40 ( V_2 -> V_170 , L_5 ) ;
return - V_171 ;
}
if ( F_41 ( V_150 , V_172 . V_173 ) ) {
F_40 ( V_2 -> V_170 , L_6 ) ;
return - V_171 ;
}
V_13 = F_42 ( V_150 , V_74 -> V_174 ) ;
F_43 ( V_2 -> V_170 , L_7 ,
V_150 -> V_166 -> V_167 , F_39 ( V_150 -> V_168 ) ,
F_44 ( V_150 -> V_168 ) , V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_175 = V_74 -> V_176 ;
if ( V_74 -> V_75 == V_118 ) {
V_156 = 4 ;
} else {
V_156 = 0 ;
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ )
if ( V_74 -> V_178 [ V_11 ] . V_144 )
V_156 ++ ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ )
if ( V_74 -> V_180 [ V_11 ] . V_144 )
V_156 ++ ;
for ( V_11 = 0 ; V_11 < V_181 ; V_11 ++ )
V_156 += V_74 -> V_182 [ V_11 ] . V_12 ;
if ( V_74 -> V_183 . V_144 )
V_156 ++ ;
for ( V_11 = 0 ; V_11 < V_184 ; V_11 ++ )
if ( V_74 -> V_185 [ V_11 ] . V_144 )
V_156 ++ ;
}
V_23 = F_45 ( V_2 , V_156 ) ;
if ( V_23 < 0 )
return V_23 ;
V_123 = 0 ;
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ )
if ( V_74 -> V_178 [ V_11 ] . V_144 ) {
V_4 = V_2 -> V_124 + V_123 ;
F_32 ( V_2 , V_4 , & V_74 -> V_178 [ V_11 ] , V_123 ) ;
V_123 ++ ;
}
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ )
if ( V_74 -> V_180 [ V_11 ] . V_144 ) {
V_4 = V_2 -> V_124 + V_123 ;
F_33 ( V_2 , V_4 , & V_74 -> V_180 [ V_11 ] , V_123 ) ;
V_123 ++ ;
}
for ( V_11 = 0 ; V_11 < V_181 ; V_11 ++ )
for ( V_157 = 0 ; V_157 < V_74 -> V_182 [ V_11 ] . V_12 ; V_157 ++ ) {
V_4 = V_2 -> V_124 + V_123 ;
F_46 ( V_2 , V_4 , NULL ,
V_2 -> V_13 +
V_74 -> V_182 [ V_11 ] . V_14 +
V_186 * V_157 ) ;
V_123 ++ ;
}
if ( V_74 -> V_183 . V_144 ) {
V_4 = V_2 -> V_124 + V_123 ;
V_4 -> type = V_125 ;
F_32 ( V_2 , V_4 , & V_74 -> V_183 , V_123 ) ;
V_123 ++ ;
}
for ( V_11 = 0 ; V_11 < V_184 ; V_11 ++ )
if ( V_74 -> V_185 [ V_11 ] . V_144 ) {
V_4 = V_2 -> V_124 + V_123 ;
F_34 ( V_2 , V_4 , & V_74 -> V_185 [ V_11 ] , V_123 ) ;
V_123 ++ ;
}
if ( V_74 -> V_75 == V_118 )
F_31 ( V_2 , V_122 ) ;
V_50 -> V_187 = 1 ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_11 , V_157 ;
struct V_3 * V_4 ;
int V_123 ;
if ( V_2 -> V_10 ) {
if ( V_50 -> V_187 )
F_29 ( V_2 ) ;
V_123 = 0 ;
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ ) {
if ( V_74 -> V_178 [ V_11 ] . V_144 )
V_123 ++ ;
}
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
if ( V_74 -> V_180 [ V_11 ] . V_144 )
V_123 ++ ;
}
for ( V_11 = 0 ; V_11 < V_181 ; V_11 ++ ) {
for ( V_157 = 0 ; V_157 < V_74 -> V_182 [ V_11 ] . V_12 ; V_157 ++ ) {
V_4 = V_2 -> V_124 + V_123 ;
F_48 ( V_2 , V_4 ) ;
V_123 ++ ;
}
}
if ( V_74 -> V_183 . V_144 )
V_123 ++ ;
for ( V_11 = 0 ; V_11 < V_184 ; V_11 ++ )
if ( V_74 -> V_185 [ V_11 ] . V_144 )
V_123 ++ ;
for ( V_11 = 0 ; V_11 < V_2 -> V_156 ; V_11 ++ ) {
V_4 = V_2 -> V_124 + V_11 ;
V_4 -> V_10 = NULL ;
}
if ( V_50 -> V_150 ) {
if ( V_2 -> V_13 )
F_49 ( V_50 -> V_150 ) ;
F_50 ( V_50 -> V_150 ) ;
}
if ( V_50 -> V_153 )
V_50 -> V_153 -> V_155 = V_50 -> V_155 ;
else
V_154 = V_50 -> V_155 ;
if ( V_50 -> V_155 )
V_50 -> V_155 -> V_153 = V_50 -> V_153 ;
}
return 0 ;
}
static int T_1 F_51 ( struct V_149 * V_2 ,
const struct V_188 * V_189 )
{
return F_52 ( V_2 , V_172 . V_173 ) ;
}
static void T_2 F_53 ( struct V_149 * V_2 )
{
F_54 ( V_2 ) ;
}
static int T_3 F_55 ( void )
{
int V_45 ;
V_45 = F_56 ( & V_172 ) ;
if ( V_45 < 0 )
return V_45 ;
V_190 . V_176 = ( char * ) V_172 . V_173 ;
return F_57 ( & V_190 ) ;
}
static void T_4 F_58 ( void )
{
F_59 ( & V_190 ) ;
F_60 ( & V_172 ) ;
}
