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
struct V_48 * V_49 = V_2 -> V_10 ;
int V_24 ;
unsigned char V_17 = F_10 ( V_6 -> V_21 ) & 0x07 ;
unsigned char V_50 = 1 << V_17 ;
unsigned char V_28 [ 4 ] = {
V_7 [ 0 ] & 0xff ,
( V_7 [ 0 ] >> 8 ) & 0xff ,
V_51 + V_17 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( V_49 -> V_52 [ V_17 ] != ( V_7 [ 0 ] & 0xffff ) ) {
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_49 -> V_52 [ V_17 ] = V_7 [ 0 ] & 0xffff ;
}
V_28 [ 0 ] = V_50 ;
V_28 [ 2 ] = V_53 ;
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
if ( ! ( V_50 & V_49 -> V_54 ) ) {
V_28 [ 0 ] = V_50 ;
V_28 [ 2 ] = V_55 ;
V_24 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_49 -> V_54 |= V_50 ;
}
return 1 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_10 ;
int V_11 ;
unsigned char V_28 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_29 [ 4 ] ;
F_6 ( 0 , V_2 -> V_13 + V_56 ) ;
F_6 ( 0 , V_2 -> V_13 + V_57 ) ;
F_6 ( 0 , V_2 -> V_13 + V_58 ) ;
F_6 ( 0 , V_2 -> V_13 + V_59 ) ;
V_49 -> V_60 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_46 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_55 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_54 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_61 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_62 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_63 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_64 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 1 ] = 0x80 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_28 [ 2 ] = V_65 + V_11 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_66 [ V_11 ] = 0x8000 ;
}
V_28 [ 0 ] = 0x00 ;
V_28 [ 1 ] = 0x00 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_28 [ 2 ] = V_51 + V_11 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_52 [ V_11 ] = 0x0000 ;
}
V_28 [ 0 ] = 0xff ;
V_28 [ 2 ] = V_53 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_67 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_68 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_69 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_70 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_71 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_72 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_73 ;
F_23 ( V_2 , V_28 , V_29 ) ;
V_49 -> V_74 = 0x00 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_75 * V_76 = F_30 ( V_2 ) ;
switch ( V_76 -> V_77 ) {
case V_78 :
F_6 ( 0 , V_2 -> V_13 + V_79 ) ;
F_6 ( 0 , V_2 -> V_13 + V_79 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_80 ) ;
F_6 ( 0 , V_2 -> V_13 + V_80 + 1 ) ;
case V_81 :
F_6 ( 0 , V_2 -> V_13 + V_82 ) ;
F_6 ( 0x0f , V_2 -> V_13 + V_83 ) ;
F_6 ( 0 , V_2 -> V_13 + V_84 ) ;
break;
case V_85 :
F_6 ( 0 , V_2 -> V_13 + V_86 ) ;
F_6 ( 0 , V_2 -> V_13 + V_86 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_86 + 2 ) ;
F_6 ( 0 , V_2 -> V_13 + V_86 + 3 ) ;
break;
case V_87 :
F_6 ( 0 , V_2 -> V_13 + V_88 ) ;
F_6 ( 0 , V_2 -> V_13 + V_88 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_88 + 2 ) ;
F_6 ( 0 , V_2 -> V_13 + V_88 + 3 ) ;
F_17 ( V_2 -> V_13 + V_89 , 0 , 0 , V_90 ) ;
F_17 ( V_2 -> V_13 + V_89 , 0 , 1 , V_90 ) ;
F_17 ( V_2 -> V_13 + V_89 , 0 , 2 , V_90 ) ;
break;
case V_91 :
F_6 ( 0 , V_2 -> V_13 + V_92 ) ;
F_6 ( 0 , V_2 -> V_13 + V_92 + 1 ) ;
F_6 ( 0 , V_2 -> V_13 + V_93 ) ;
F_6 ( 0x0f , V_2 -> V_13 + V_94 ) ;
F_6 ( 0 , V_2 -> V_13 + V_95 ) ;
break;
case V_96 :
F_6 ( 0x88 , V_2 -> V_13 + V_97 ) ;
break;
case V_98 :
case V_99 :
F_6 ( 0x88 , V_2 -> V_13 + V_100 ) ;
break;
case V_101 :
F_8 ( 0 , V_2 -> V_13 + V_102 ) ;
F_8 ( 0 , V_2 -> V_13 + V_103 ) ;
F_8 ( 0 , V_2 -> V_13 + V_103 + 2 ) ;
F_8 ( 0 , V_2 -> V_13 + V_104 ) ;
F_8 ( 0 , V_2 -> V_13 + V_104 + 2 ) ;
break;
case V_105 :
F_6 ( 0x88 , V_2 -> V_13 + V_106 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_107 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_108 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_109 ) ;
case V_110 :
F_6 ( 0x88 , V_2 -> V_13 + V_111 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_112 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_113 ) ;
F_6 ( 0x80 , V_2 -> V_13 + V_114 ) ;
break;
case V_115 :
F_8 ( 0x08 , V_2 -> V_13 + V_116 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_117 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_118 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_119 ) ;
break;
case V_120 :
F_8 ( 0 , V_2 -> V_13 + V_102 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_116 ) ;
F_8 ( 0x08 , V_2 -> V_13 + V_117 ) ;
F_8 ( 0 , V_2 -> V_13 + V_121 ) ;
F_8 ( 0 , V_2 -> V_13 + V_121 + 2 ) ;
break;
case V_122 :
F_28 ( V_2 ) ;
break;
case V_123 :
F_8 ( 0x0101 , V_2 -> V_13 + V_124 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = & V_2 -> V_125 [ 0 ] ;
V_4 -> type = V_126 ;
V_4 -> V_127 = V_128 | V_129 | V_130 ;
V_4 -> V_131 = 8 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = 8 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_136 = F_24 ;
V_4 = & V_2 -> V_125 [ 1 ] ;
V_4 -> type = V_137 ;
V_4 -> V_127 = V_138 | V_129 | V_130 ;
V_4 -> V_131 = 8 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = 8 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_16 = 0 ;
V_4 -> V_136 = F_25 ;
V_4 = & V_2 -> V_125 [ 2 ] ;
V_4 -> type = V_139 ;
V_4 -> V_127 = V_138 | V_140 ;
V_4 -> V_131 = 2 ;
V_4 -> V_132 = 0xffffffff ;
V_4 -> V_133 = 2 ;
V_4 = & V_2 -> V_125 [ 3 ] ;
V_4 -> type = V_141 ;
V_4 -> V_127 = V_128 | V_138 ;
V_4 -> V_131 = 8 ;
V_4 -> V_132 = 0xffff ;
V_4 -> V_133 = 8 ;
V_4 -> V_142 = F_26 ;
V_4 -> V_143 = F_27 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
const struct V_75 * V_76 = F_30 ( V_2 ) ;
V_4 -> type = V_126 ;
V_4 -> V_127 = V_128 | V_129 | V_130 | V_9 -> V_144 ;
if ( V_9 -> V_145 > 16 )
V_4 -> V_127 |= V_140 ;
V_4 -> V_131 = V_9 -> V_145 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = V_9 -> V_145 ;
V_4 -> V_134 = & V_135 ;
switch ( V_76 -> V_146 ) {
case V_147 :
V_4 -> V_136 = F_1 ;
break;
case V_148 :
V_4 -> V_136 = F_3 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
const struct V_75 * V_76 = F_30 ( V_2 ) ;
V_4 -> type = V_137 ;
V_4 -> V_127 = V_138 | V_129 | V_130 ;
if ( V_9 -> V_145 > 16 )
V_4 -> V_127 |= V_140 ;
V_4 -> V_131 = V_9 -> V_145 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = V_9 -> V_145 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_16 = 0 ;
switch ( V_76 -> V_146 ) {
case V_147 :
V_4 -> V_136 = F_5 ;
break;
case V_148 :
V_4 -> V_136 = F_7 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
V_4 -> type = V_141 ;
V_4 -> V_127 = V_138 | V_128 ;
V_4 -> V_131 = V_9 -> V_145 ;
V_4 -> V_132 = 65535 ;
V_4 -> V_133 = V_9 -> V_145 ;
V_4 -> V_142 = F_9 ;
V_4 -> V_143 = F_14 ;
V_4 -> V_149 = F_16 ;
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static const void * F_35 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
const struct V_75 * V_76 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_36 ( V_152 ) ; ++ V_11 ) {
V_76 = & V_152 [ V_11 ] ;
if ( V_76 -> V_153 == V_151 -> V_154 &&
V_76 -> V_155 == V_151 -> V_156 )
return V_76 ;
}
return NULL ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned long V_157 )
{
struct V_150 * V_151 = F_38 ( V_2 ) ;
const struct V_75 * V_76 ;
struct V_48 * V_49 ;
struct V_3 * V_4 ;
int V_24 , V_158 , V_11 , V_159 ;
V_76 = F_35 ( V_2 , V_151 ) ;
if ( ! V_76 )
return - V_160 ;
V_2 -> V_161 = V_76 ;
V_2 -> V_162 = V_76 -> V_163 ;
V_49 = F_39 ( sizeof( * V_49 ) , V_164 ) ;
if ( ! V_49 )
return - V_165 ;
V_2 -> V_10 = V_49 ;
V_24 = F_40 ( V_151 , V_2 -> V_162 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_13 = F_41 ( V_151 , V_76 -> V_166 ) ;
V_24 = F_42 ( V_2 , V_76 -> V_167 ) ;
if ( V_24 )
return V_24 ;
V_158 = 0 ;
for ( V_11 = 0 ; V_11 < V_168 ; V_11 ++ )
if ( V_76 -> V_169 [ V_11 ] . V_145 ) {
V_4 = & V_2 -> V_125 [ V_158 ] ;
F_32 ( V_2 , V_4 , & V_76 -> V_169 [ V_11 ] ) ;
V_158 ++ ;
}
for ( V_11 = 0 ; V_11 < V_170 ; V_11 ++ )
if ( V_76 -> V_171 [ V_11 ] . V_145 ) {
V_4 = & V_2 -> V_125 [ V_158 ] ;
F_33 ( V_2 , V_4 , & V_76 -> V_171 [ V_11 ] ) ;
V_158 ++ ;
}
for ( V_11 = 0 ; V_11 < V_172 ; V_11 ++ )
for ( V_159 = 0 ; V_159 < V_76 -> V_173 [ V_11 ] . V_12 ; V_159 ++ ) {
V_4 = & V_2 -> V_125 [ V_158 ] ;
F_43 ( V_2 , V_4 , NULL ,
V_2 -> V_13 +
V_76 -> V_173 [ V_11 ] . V_14 +
V_174 * V_159 ) ;
V_158 ++ ;
}
if ( V_76 -> V_175 . V_145 ) {
V_4 = & V_2 -> V_125 [ V_158 ] ;
V_4 -> type = V_126 ;
F_32 ( V_2 , V_4 , & V_76 -> V_175 ) ;
V_158 ++ ;
}
for ( V_11 = 0 ; V_11 < V_176 ; V_11 ++ )
if ( V_76 -> V_177 [ V_11 ] . V_145 ) {
V_4 = & V_2 -> V_125 [ V_158 ] ;
F_34 ( V_2 , V_4 , & V_76 -> V_177 [ V_11 ] ) ;
V_158 ++ ;
}
if ( V_76 -> V_77 == V_122 )
F_31 ( V_2 ) ;
V_49 -> V_178 = 1 ;
F_29 ( V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_10 ;
struct V_150 * V_151 = F_38 ( V_2 ) ;
struct V_3 * V_4 ;
int V_11 ;
if ( V_49 ) {
if ( V_49 -> V_178 )
F_29 ( V_2 ) ;
}
if ( V_2 -> V_125 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_179 ; V_11 ++ ) {
V_4 = & V_2 -> V_125 [ V_11 ] ;
if ( V_4 -> type == V_180 )
F_45 ( V_2 , V_4 ) ;
V_4 -> V_10 = NULL ;
}
}
if ( V_151 ) {
if ( V_2 -> V_13 )
F_46 ( V_151 ) ;
}
}
static int F_47 ( struct V_150 * V_2 ,
const struct V_181 * V_182 )
{
return F_48 ( V_2 , & V_183 ) ;
}
static void F_49 ( struct V_150 * V_2 )
{
F_50 ( V_2 ) ;
}
