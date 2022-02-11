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
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
if ( F_6 ( V_4 , V_7 ) ) {
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
F_7 ( ( V_4 -> V_16 >> ( 8 * V_11 ) ) & 0xff ,
V_2 -> V_13 + V_9 -> V_14 + V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
int V_11 ;
if ( F_6 ( V_4 , V_7 ) ) {
for ( V_11 = 0 ; V_11 < V_9 -> V_12 ; V_11 ++ )
F_9 ( ( V_4 -> V_16 >> ( 16 * V_11 ) ) & 0xffff ,
V_2 -> V_13 + V_9 -> V_14 + 2 * V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_20 ;
V_17 = F_11 ( V_6 -> V_21 ) ;
V_18 = V_17 / 3 ;
V_19 = V_17 - ( 3 * V_18 ) ;
F_12 ( & V_4 -> V_22 , V_20 ) ;
V_7 [ 0 ] = F_13 ( V_2 -> V_13 + V_9 -> V_14 + ( V_23 * V_18 ) ,
0 , V_19 ) ;
F_14 ( & V_4 -> V_22 , V_20 ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_20 ;
V_17 = F_11 ( V_6 -> V_21 ) ;
V_18 = V_17 / 3 ;
V_19 = V_17 - ( 3 * V_18 ) ;
F_12 ( & V_4 -> V_22 , V_20 ) ;
F_16 ( V_2 -> V_13 + V_9 -> V_14 + ( V_23 * V_18 ) ,
0 , V_19 , V_7 [ 0 ] ) ;
F_14 ( & V_4 -> V_22 , V_20 ) ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 -> V_10 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_13 ;
int V_24 = 0 ;
unsigned long V_20 ;
V_17 = F_11 ( V_6 -> V_21 ) ;
V_18 = V_17 / 3 ;
V_19 = V_17 - ( 3 * V_18 ) ;
V_13 = V_2 -> V_13 + V_9 -> V_14 + ( V_23 * V_18 ) ;
F_12 ( & V_4 -> V_22 , V_20 ) ;
switch ( V_7 [ 0 ] ) {
case V_25 :
V_24 = F_18 ( V_13 , 0 , V_19 , V_7 [ 1 ] ) ;
if ( V_24 < 0 )
V_24 = - V_26 ;
break;
case V_27 :
V_7 [ 1 ] = F_19 ( V_13 , 0 , V_19 ) ;
break;
default:
V_24 = - V_26 ;
break;
}
F_14 ( & V_4 -> V_22 , V_20 ) ;
return V_24 < 0 ? V_24 : V_6 -> V_15 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned char * V_28 , unsigned char * V_29 ,
int V_30 )
{
int V_31 , V_32 , V_33 = 0 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
F_7 ( V_28 [ 0 ] , V_2 -> V_13 + V_34 ) ;
F_7 ( V_28 [ 1 ] , V_2 -> V_13 + V_35 ) ;
F_7 ( V_28 [ 2 ] , V_2 -> V_13 + V_36 ) ;
F_7 ( V_28 [ 3 ] , V_2 -> V_13 + V_37 ) ;
for ( V_32 = 0 ; V_32 < 251 ; V_32 ++ ) {
V_29 [ 2 ] = F_2 ( V_2 -> V_13 + V_38 ) ;
if ( V_29 [ 2 ] == V_28 [ 2 ] ) {
V_29 [ 0 ] = F_2 ( V_2 -> V_13 + V_39 ) ;
V_29 [ 1 ] = F_2 ( V_2 -> V_13 + V_40 ) ;
V_29 [ 3 ] = F_2 ( V_2 -> V_13 + V_41 ) ;
V_33 = 1 ;
break;
}
F_21 ( 1 ) ;
}
if ( V_33 )
return 0 ;
}
F_22 ( V_2 -> V_42 , L_1 ) ;
return - V_43 ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned char V_28 [ 4 ] = { 0x0 , 0x0 , V_44 , 0x0 } ;
unsigned char V_29 [ 4 ] ;
if ( F_2 ( V_2 -> V_13 + V_38 ) == V_44 )
return 0 ;
return F_20 ( V_2 , V_28 , V_29 , V_45 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned char * V_28 , unsigned char * V_29 )
{
if ( V_28 [ 2 ] == V_44 ) {
F_22 ( V_2 -> V_42 ,
L_2 ) ;
return - V_26 ;
}
if ( F_2 ( V_2 -> V_13 + V_38 ) == V_28 [ 2 ] ) {
int V_46 ;
V_46 = F_23 ( V_2 ) ;
if ( V_46 < 0 )
return V_46 ;
}
return F_20 ( V_2 , V_28 , V_29 , V_45 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_13 + V_41 ) ;
return V_6 -> V_15 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_24 ;
unsigned char V_28 [ 4 ] = {
0x00 ,
0x00 ,
V_47 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( F_6 ( V_4 , V_7 ) ) {
V_28 [ 0 ] = V_4 -> V_16 ;
V_24 = F_24 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_24 , V_15 ;
unsigned char V_28 [ 4 ] = {
F_11 ( V_6 -> V_21 ) & 0x07 ,
0x00 ,
V_48 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
V_24 = F_24 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_7 [ V_15 ] = ( V_29 [ 1 ] << 8 ) + V_29 [ 0 ] ;
}
return V_15 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_49 * V_50 = V_2 -> V_10 ;
int V_24 ;
unsigned char V_17 = F_11 ( V_6 -> V_21 ) & 0x07 ;
unsigned char V_51 = 1 << V_17 ;
unsigned char V_28 [ 4 ] = {
V_7 [ 0 ] & 0xff ,
( V_7 [ 0 ] >> 8 ) & 0xff ,
V_52 + V_17 ,
0x00
} ;
unsigned char V_29 [ 4 ] ;
if ( V_50 -> V_53 [ V_17 ] != ( V_7 [ 0 ] & 0xffff ) ) {
V_24 = F_24 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_50 -> V_53 [ V_17 ] = V_7 [ 0 ] & 0xffff ;
}
V_28 [ 0 ] = V_51 ;
V_28 [ 2 ] = V_54 ;
V_24 = F_24 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
if ( ! ( V_51 & V_50 -> V_55 ) ) {
V_28 [ 0 ] = V_51 ;
V_28 [ 2 ] = V_56 ;
V_24 = F_24 ( V_2 , V_28 , V_29 ) ;
if ( ! V_24 )
return V_24 ;
V_50 -> V_55 |= V_51 ;
}
return 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_10 ;
int V_11 ;
unsigned char V_28 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_29 [ 4 ] ;
F_7 ( 0 , V_2 -> V_13 + V_57 ) ;
F_7 ( 0 , V_2 -> V_13 + V_58 ) ;
F_7 ( 0 , V_2 -> V_13 + V_59 ) ;
F_7 ( 0 , V_2 -> V_13 + V_60 ) ;
V_50 -> V_61 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_47 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_56 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_55 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_62 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_63 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_64 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_65 = 0 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 1 ] = 0x80 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_28 [ 2 ] = V_66 + V_11 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_67 [ V_11 ] = 0x8000 ;
}
V_28 [ 0 ] = 0x00 ;
V_28 [ 1 ] = 0x00 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_28 [ 2 ] = V_52 + V_11 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_53 [ V_11 ] = 0x0000 ;
}
V_28 [ 0 ] = 0xff ;
V_28 [ 2 ] = V_54 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_68 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_69 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_70 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_71 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_72 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_73 = 0x00 ;
V_28 [ 0 ] = 0x00 ;
V_28 [ 2 ] = V_74 ;
F_24 ( V_2 , V_28 , V_29 ) ;
V_50 -> V_75 = 0x00 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
const struct V_76 * V_77 = V_2 -> V_78 ;
switch ( V_77 -> V_79 ) {
case V_80 :
F_7 ( 0 , V_2 -> V_13 + V_81 ) ;
F_7 ( 0 , V_2 -> V_13 + V_81 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_82 ) ;
F_7 ( 0 , V_2 -> V_13 + V_82 + 1 ) ;
case V_83 :
F_7 ( 0 , V_2 -> V_13 + V_84 ) ;
F_7 ( 0x0f , V_2 -> V_13 + V_85 ) ;
F_7 ( 0 , V_2 -> V_13 + V_86 ) ;
break;
case V_87 :
F_7 ( 0 , V_2 -> V_13 + V_88 ) ;
F_7 ( 0 , V_2 -> V_13 + V_88 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_88 + 2 ) ;
F_7 ( 0 , V_2 -> V_13 + V_88 + 3 ) ;
break;
case V_89 :
F_7 ( 0 , V_2 -> V_13 + V_90 ) ;
F_7 ( 0 , V_2 -> V_13 + V_90 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_90 + 2 ) ;
F_7 ( 0 , V_2 -> V_13 + V_90 + 3 ) ;
F_18 ( V_2 -> V_13 + V_91 , 0 , 0 , V_92 ) ;
F_18 ( V_2 -> V_13 + V_91 , 0 , 1 , V_92 ) ;
F_18 ( V_2 -> V_13 + V_91 , 0 , 2 , V_92 ) ;
break;
case V_93 :
F_7 ( 0 , V_2 -> V_13 + V_94 ) ;
F_7 ( 0 , V_2 -> V_13 + V_94 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_95 ) ;
F_7 ( 0x0f , V_2 -> V_13 + V_96 ) ;
F_7 ( 0 , V_2 -> V_13 + V_97 ) ;
break;
case V_98 :
F_7 ( 0x88 , V_2 -> V_13 + V_99 ) ;
break;
case V_100 :
case V_101 :
F_7 ( 0x88 , V_2 -> V_13 + V_102 ) ;
break;
case V_103 :
F_9 ( 0 , V_2 -> V_13 + V_104 ) ;
F_9 ( 0 , V_2 -> V_13 + V_105 ) ;
F_9 ( 0 , V_2 -> V_13 + V_105 + 2 ) ;
F_9 ( 0 , V_2 -> V_13 + V_106 ) ;
F_9 ( 0 , V_2 -> V_13 + V_106 + 2 ) ;
break;
case V_107 :
F_7 ( 0x88 , V_2 -> V_13 + V_108 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_109 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_110 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_111 ) ;
case V_112 :
F_7 ( 0x88 , V_2 -> V_13 + V_113 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_114 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_115 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_116 ) ;
break;
case V_117 :
F_9 ( 0x08 , V_2 -> V_13 + V_118 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_119 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_120 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_121 ) ;
break;
case V_122 :
F_9 ( 0 , V_2 -> V_13 + V_104 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_118 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_119 ) ;
F_9 ( 0 , V_2 -> V_13 + V_123 ) ;
F_9 ( 0 , V_2 -> V_13 + V_123 + 2 ) ;
break;
case V_124 :
F_29 ( V_2 ) ;
break;
case V_125 :
F_9 ( 0x0101 , V_2 -> V_13 + V_126 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = & V_2 -> V_127 [ 0 ] ;
V_4 -> type = V_128 ;
V_4 -> V_129 = V_130 ;
V_4 -> V_131 = 8 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = 8 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_136 = F_25 ;
V_4 = & V_2 -> V_127 [ 1 ] ;
V_4 -> type = V_137 ;
V_4 -> V_129 = V_138 ;
V_4 -> V_131 = 8 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = 8 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_16 = 0 ;
V_4 -> V_136 = F_26 ;
V_4 = & V_2 -> V_127 [ 2 ] ;
V_4 -> type = V_139 ;
V_4 -> V_129 = V_138 | V_140 ;
V_4 -> V_131 = 2 ;
V_4 -> V_132 = 0xffffffff ;
V_4 -> V_133 = 2 ;
V_4 = & V_2 -> V_127 [ 3 ] ;
V_4 -> type = V_141 ;
V_4 -> V_129 = V_130 | V_138 ;
V_4 -> V_131 = 8 ;
V_4 -> V_132 = 0xffff ;
V_4 -> V_133 = 8 ;
V_4 -> V_142 = F_27 ;
V_4 -> V_143 = F_28 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
const struct V_76 * V_77 = V_2 -> V_78 ;
V_4 -> type = V_128 ;
V_4 -> V_129 = V_130 | V_9 -> V_144 ;
if ( V_9 -> V_145 > 16 )
V_4 -> V_129 |= V_140 ;
V_4 -> V_131 = V_9 -> V_145 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = V_9 -> V_145 ;
V_4 -> V_134 = & V_135 ;
switch ( V_77 -> V_146 ) {
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
const struct V_76 * V_77 = V_2 -> V_78 ;
V_4 -> type = V_137 ;
V_4 -> V_129 = V_138 ;
if ( V_9 -> V_145 > 16 )
V_4 -> V_129 |= V_140 ;
V_4 -> V_131 = V_9 -> V_145 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 = V_9 -> V_145 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_16 = 0 ;
switch ( V_77 -> V_146 ) {
case V_147 :
V_4 -> V_136 = F_5 ;
break;
case V_148 :
V_4 -> V_136 = F_8 ;
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
V_4 -> V_129 = V_138 | V_130 ;
V_4 -> V_131 = V_9 -> V_145 ;
V_4 -> V_132 = 65535 ;
V_4 -> V_133 = V_9 -> V_145 ;
V_4 -> V_142 = F_10 ;
V_4 -> V_143 = F_15 ;
V_4 -> V_149 = F_17 ;
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static unsigned long F_35 ( struct V_150 * V_151 ,
unsigned long V_79 )
{
if ( V_79 != V_112 )
return V_79 ;
if ( F_36 ( V_151 ) < 0 )
return V_79 ;
if ( F_37 ( V_151 , V_152 , L_3 ) == 0 ) {
unsigned long V_153 =
F_38 ( V_151 , V_152 ) + 53 ;
F_7 ( 0x05 , V_153 ) ;
if ( ( F_2 ( V_153 ) & 0x07 ) == 0x02 ) {
F_7 ( 0x02 , V_153 ) ;
if ( ( F_2 ( V_153 ) & 0x07 ) == 0x05 )
V_79 = V_107 ;
}
F_39 ( V_151 , V_152 ) ;
}
F_40 ( V_151 ) ;
return V_79 ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned long V_154 )
{
struct V_150 * V_151 = F_42 ( V_2 ) ;
const struct V_76 * V_77 = NULL ;
struct V_49 * V_50 ;
struct V_3 * V_4 ;
int V_24 , V_155 , V_11 , V_156 ;
if ( V_154 < F_43 ( V_157 ) )
V_77 = & V_157 [ V_154 ] ;
if ( ! V_77 )
return - V_158 ;
V_2 -> V_78 = V_77 ;
V_2 -> V_159 = V_77 -> V_160 ;
V_50 = F_44 ( V_2 , sizeof( * V_50 ) ) ;
if ( ! V_50 )
return - V_161 ;
V_24 = F_45 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_13 = F_38 ( V_151 , V_77 -> V_162 ) ;
V_24 = F_46 ( V_2 , V_77 -> V_163 ) ;
if ( V_24 )
return V_24 ;
V_155 = 0 ;
for ( V_11 = 0 ; V_11 < V_164 ; V_11 ++ )
if ( V_77 -> V_165 [ V_11 ] . V_145 ) {
V_4 = & V_2 -> V_127 [ V_155 ] ;
F_32 ( V_2 , V_4 , & V_77 -> V_165 [ V_11 ] ) ;
V_155 ++ ;
}
for ( V_11 = 0 ; V_11 < V_166 ; V_11 ++ )
if ( V_77 -> V_167 [ V_11 ] . V_145 ) {
V_4 = & V_2 -> V_127 [ V_155 ] ;
F_33 ( V_2 , V_4 , & V_77 -> V_167 [ V_11 ] ) ;
V_155 ++ ;
}
for ( V_11 = 0 ; V_11 < V_168 ; V_11 ++ )
for ( V_156 = 0 ; V_156 < V_77 -> V_169 [ V_11 ] . V_12 ; V_156 ++ ) {
V_4 = & V_2 -> V_127 [ V_155 ] ;
V_24 = F_47 ( V_2 , V_4 , NULL ,
V_77 -> V_169 [ V_11 ] . V_14 +
V_156 * V_170 ) ;
if ( V_24 )
return V_24 ;
V_155 ++ ;
}
if ( V_77 -> V_171 . V_145 ) {
V_4 = & V_2 -> V_127 [ V_155 ] ;
V_4 -> type = V_128 ;
F_32 ( V_2 , V_4 , & V_77 -> V_171 ) ;
V_155 ++ ;
}
for ( V_11 = 0 ; V_11 < V_172 ; V_11 ++ )
if ( V_77 -> V_173 [ V_11 ] . V_145 ) {
V_4 = & V_2 -> V_127 [ V_155 ] ;
F_34 ( V_2 , V_4 , & V_77 -> V_173 [ V_11 ] ) ;
V_155 ++ ;
}
if ( V_77 -> V_79 == V_124 )
F_31 ( V_2 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 )
F_30 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_150 * V_2 ,
const struct V_174 * V_175 )
{
unsigned long V_79 ;
V_79 = F_35 ( V_2 , V_175 -> V_176 ) ;
return F_51 ( V_2 , & V_177 , V_79 ) ;
}
