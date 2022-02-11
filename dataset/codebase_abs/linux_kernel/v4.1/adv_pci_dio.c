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
unsigned char * V_17 , unsigned char * V_18 ,
int V_19 )
{
int V_20 , V_21 , V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
F_7 ( V_17 [ 0 ] , V_2 -> V_13 + V_23 ) ;
F_7 ( V_17 [ 1 ] , V_2 -> V_13 + V_24 ) ;
F_7 ( V_17 [ 2 ] , V_2 -> V_13 + V_25 ) ;
F_7 ( V_17 [ 3 ] , V_2 -> V_13 + V_26 ) ;
for ( V_21 = 0 ; V_21 < 251 ; V_21 ++ ) {
V_18 [ 2 ] = F_2 ( V_2 -> V_13 + V_27 ) ;
if ( V_18 [ 2 ] == V_17 [ 2 ] ) {
V_18 [ 0 ] = F_2 ( V_2 -> V_13 + V_28 ) ;
V_18 [ 1 ] = F_2 ( V_2 -> V_13 + V_29 ) ;
V_18 [ 3 ] = F_2 ( V_2 -> V_13 + V_30 ) ;
V_22 = 1 ;
break;
}
F_11 ( 1 ) ;
}
if ( V_22 )
return 0 ;
}
F_12 ( V_2 -> V_31 , L_1 ) ;
return - V_32 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned char V_17 [ 4 ] = { 0x0 , 0x0 , V_33 , 0x0 } ;
unsigned char V_18 [ 4 ] ;
if ( F_2 ( V_2 -> V_13 + V_27 ) == V_33 )
return 0 ;
return F_10 ( V_2 , V_17 , V_18 , V_34 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned char * V_17 , unsigned char * V_18 )
{
if ( V_17 [ 2 ] == V_33 ) {
F_12 ( V_2 -> V_31 ,
L_2 ) ;
return - V_35 ;
}
if ( F_2 ( V_2 -> V_13 + V_27 ) == V_17 [ 2 ] ) {
int V_36 ;
V_36 = F_13 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return F_10 ( V_2 , V_17 , V_18 , V_34 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_13 + V_30 ) ;
return V_6 -> V_15 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_37 ;
unsigned char V_17 [ 4 ] = {
0x00 ,
0x00 ,
V_38 ,
0x00
} ;
unsigned char V_18 [ 4 ] ;
if ( F_6 ( V_4 , V_7 ) ) {
V_17 [ 0 ] = V_4 -> V_16 ;
V_37 = F_14 ( V_2 , V_17 , V_18 ) ;
if ( ! V_37 )
return V_37 ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_15 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_37 , V_15 ;
unsigned char V_17 [ 4 ] = {
F_18 ( V_6 -> V_39 ) & 0x07 ,
0x00 ,
V_40 ,
0x00
} ;
unsigned char V_18 [ 4 ] ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
V_37 = F_14 ( V_2 , V_17 , V_18 ) ;
if ( ! V_37 )
return V_37 ;
V_7 [ V_15 ] = ( V_18 [ 1 ] << 8 ) + V_18 [ 0 ] ;
}
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_41 * V_42 = V_2 -> V_10 ;
int V_37 ;
unsigned char V_43 = F_18 ( V_6 -> V_39 ) & 0x07 ;
unsigned char V_44 = 1 << V_43 ;
unsigned char V_17 [ 4 ] = {
V_7 [ 0 ] & 0xff ,
( V_7 [ 0 ] >> 8 ) & 0xff ,
V_45 + V_43 ,
0x00
} ;
unsigned char V_18 [ 4 ] ;
if ( V_42 -> V_46 [ V_43 ] != ( V_7 [ 0 ] & 0xffff ) ) {
V_37 = F_14 ( V_2 , V_17 , V_18 ) ;
if ( ! V_37 )
return V_37 ;
V_42 -> V_46 [ V_43 ] = V_7 [ 0 ] & 0xffff ;
}
V_17 [ 0 ] = V_44 ;
V_17 [ 2 ] = V_47 ;
V_37 = F_14 ( V_2 , V_17 , V_18 ) ;
if ( ! V_37 )
return V_37 ;
if ( ! ( V_44 & V_42 -> V_48 ) ) {
V_17 [ 0 ] = V_44 ;
V_17 [ 2 ] = V_49 ;
V_37 = F_14 ( V_2 , V_17 , V_18 ) ;
if ( ! V_37 )
return V_37 ;
V_42 -> V_48 |= V_44 ;
}
return 1 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_10 ;
int V_11 ;
unsigned char V_17 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_18 [ 4 ] ;
F_7 ( 0 , V_2 -> V_13 + V_50 ) ;
F_7 ( 0 , V_2 -> V_13 + V_51 ) ;
F_7 ( 0 , V_2 -> V_13 + V_52 ) ;
F_7 ( 0 , V_2 -> V_13 + V_53 ) ;
V_42 -> V_54 = 0 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_38 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_49 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_48 = 0 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_55 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_56 = 0 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_57 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_58 = 0 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 1 ] = 0x80 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_17 [ 2 ] = V_59 + V_11 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_60 [ V_11 ] = 0x8000 ;
}
V_17 [ 0 ] = 0x00 ;
V_17 [ 1 ] = 0x00 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_17 [ 2 ] = V_45 + V_11 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_46 [ V_11 ] = 0x0000 ;
}
V_17 [ 0 ] = 0xff ;
V_17 [ 2 ] = V_47 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_61 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_62 = 0x00 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_63 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_64 = 0x00 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_65 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_66 = 0x00 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 2 ] = V_67 ;
F_14 ( V_2 , V_17 , V_18 ) ;
V_42 -> V_68 = 0x00 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_69 * V_70 = V_2 -> V_71 ;
switch ( V_70 -> V_72 ) {
case V_73 :
F_7 ( 0 , V_2 -> V_13 + V_74 ) ;
F_7 ( 0 , V_2 -> V_13 + V_74 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_75 ) ;
F_7 ( 0 , V_2 -> V_13 + V_75 + 1 ) ;
case V_76 :
F_7 ( 0 , V_2 -> V_13 + V_77 ) ;
F_7 ( 0x0f , V_2 -> V_13 + V_78 ) ;
F_7 ( 0 , V_2 -> V_13 + V_79 ) ;
break;
case V_80 :
F_7 ( 0 , V_2 -> V_13 + V_81 ) ;
F_7 ( 0 , V_2 -> V_13 + V_81 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_81 + 2 ) ;
F_7 ( 0 , V_2 -> V_13 + V_81 + 3 ) ;
break;
case V_82 :
F_7 ( 0 , V_2 -> V_13 + V_83 ) ;
F_7 ( 0 , V_2 -> V_13 + V_83 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_83 + 2 ) ;
F_7 ( 0 , V_2 -> V_13 + V_83 + 3 ) ;
break;
case V_84 :
F_7 ( 0 , V_2 -> V_13 + V_85 ) ;
F_7 ( 0 , V_2 -> V_13 + V_85 + 1 ) ;
F_7 ( 0 , V_2 -> V_13 + V_86 ) ;
F_7 ( 0x0f , V_2 -> V_13 + V_87 ) ;
F_7 ( 0 , V_2 -> V_13 + V_88 ) ;
break;
case V_89 :
F_7 ( 0x88 , V_2 -> V_13 + V_90 ) ;
break;
case V_91 :
case V_92 :
F_7 ( 0x88 , V_2 -> V_13 + V_93 ) ;
break;
case V_94 :
F_9 ( 0 , V_2 -> V_13 + V_95 ) ;
F_9 ( 0 , V_2 -> V_13 + V_96 ) ;
F_9 ( 0 , V_2 -> V_13 + V_96 + 2 ) ;
F_9 ( 0 , V_2 -> V_13 + V_97 ) ;
F_9 ( 0 , V_2 -> V_13 + V_97 + 2 ) ;
break;
case V_98 :
F_7 ( 0x88 , V_2 -> V_13 + V_99 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_100 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_101 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_102 ) ;
case V_103 :
F_7 ( 0x88 , V_2 -> V_13 + V_104 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_105 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_106 ) ;
F_7 ( 0x80 , V_2 -> V_13 + V_107 ) ;
break;
case V_108 :
F_9 ( 0x08 , V_2 -> V_13 + V_109 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_110 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_111 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_112 ) ;
break;
case V_113 :
F_9 ( 0 , V_2 -> V_13 + V_95 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_109 ) ;
F_9 ( 0x08 , V_2 -> V_13 + V_110 ) ;
F_9 ( 0 , V_2 -> V_13 + V_114 ) ;
F_9 ( 0 , V_2 -> V_13 + V_114 + 2 ) ;
break;
case V_115 :
F_20 ( V_2 ) ;
break;
case V_116 :
F_9 ( 0x0101 , V_2 -> V_13 + V_117 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = & V_2 -> V_118 [ 0 ] ;
V_4 -> type = V_119 ;
V_4 -> V_120 = V_121 ;
V_4 -> V_122 = 8 ;
V_4 -> V_123 = 1 ;
V_4 -> V_124 = 8 ;
V_4 -> V_125 = & V_126 ;
V_4 -> V_127 = F_15 ;
V_4 = & V_2 -> V_118 [ 1 ] ;
V_4 -> type = V_128 ;
V_4 -> V_120 = V_129 ;
V_4 -> V_122 = 8 ;
V_4 -> V_123 = 1 ;
V_4 -> V_124 = 8 ;
V_4 -> V_125 = & V_126 ;
V_4 -> V_16 = 0 ;
V_4 -> V_127 = F_16 ;
V_4 = & V_2 -> V_118 [ 2 ] ;
V_4 -> type = V_130 ;
V_4 -> V_120 = V_129 | V_131 ;
V_4 -> V_122 = 2 ;
V_4 -> V_123 = 0xffffffff ;
V_4 -> V_124 = 2 ;
V_4 = & V_2 -> V_118 [ 3 ] ;
V_4 -> type = V_132 ;
V_4 -> V_120 = V_121 | V_129 ;
V_4 -> V_122 = 8 ;
V_4 -> V_123 = 0xffff ;
V_4 -> V_124 = 8 ;
V_4 -> V_133 = F_17 ;
V_4 -> V_134 = F_19 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
const struct V_69 * V_70 = V_2 -> V_71 ;
V_4 -> type = V_119 ;
V_4 -> V_120 = V_121 | V_9 -> V_135 ;
if ( V_9 -> V_136 > 16 )
V_4 -> V_120 |= V_131 ;
V_4 -> V_122 = V_9 -> V_136 ;
V_4 -> V_123 = 1 ;
V_4 -> V_124 = V_9 -> V_136 ;
V_4 -> V_125 = & V_126 ;
switch ( V_70 -> V_137 ) {
case V_138 :
V_4 -> V_127 = F_1 ;
break;
case V_139 :
V_4 -> V_127 = F_3 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
const struct V_69 * V_70 = V_2 -> V_71 ;
V_4 -> type = V_128 ;
V_4 -> V_120 = V_129 ;
if ( V_9 -> V_136 > 16 )
V_4 -> V_120 |= V_131 ;
V_4 -> V_122 = V_9 -> V_136 ;
V_4 -> V_123 = 1 ;
V_4 -> V_124 = V_9 -> V_136 ;
V_4 -> V_125 = & V_126 ;
V_4 -> V_16 = 0 ;
switch ( V_70 -> V_137 ) {
case V_138 :
V_4 -> V_127 = F_5 ;
break;
case V_139 :
V_4 -> V_127 = F_8 ;
break;
}
V_4 -> V_10 = ( void * ) V_9 ;
return 0 ;
}
static unsigned long F_25 ( struct V_140 * V_141 ,
unsigned long V_72 )
{
if ( V_72 != V_103 )
return V_72 ;
if ( F_26 ( V_141 ) < 0 )
return V_72 ;
if ( F_27 ( V_141 , V_142 , L_3 ) == 0 ) {
unsigned long V_143 =
F_28 ( V_141 , V_142 ) + 53 ;
F_7 ( 0x05 , V_143 ) ;
if ( ( F_2 ( V_143 ) & 0x07 ) == 0x02 ) {
F_7 ( 0x02 , V_143 ) ;
if ( ( F_2 ( V_143 ) & 0x07 ) == 0x05 )
V_72 = V_98 ;
}
F_29 ( V_141 , V_142 ) ;
}
F_30 ( V_141 ) ;
return V_72 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned long V_144 )
{
struct V_140 * V_141 = F_32 ( V_2 ) ;
const struct V_69 * V_70 = NULL ;
struct V_41 * V_42 ;
struct V_3 * V_4 ;
int V_37 , V_145 , V_11 , V_146 ;
if ( V_144 < F_33 ( V_147 ) )
V_70 = & V_147 [ V_144 ] ;
if ( ! V_70 )
return - V_148 ;
V_2 -> V_71 = V_70 ;
V_2 -> V_149 = V_70 -> V_150 ;
V_42 = F_34 ( V_2 , sizeof( * V_42 ) ) ;
if ( ! V_42 )
return - V_151 ;
V_37 = F_35 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_13 = F_28 ( V_141 , V_70 -> V_152 ) ;
V_37 = F_36 ( V_2 , V_70 -> V_153 ) ;
if ( V_37 )
return V_37 ;
V_145 = 0 ;
for ( V_11 = 0 ; V_11 < V_154 ; V_11 ++ )
if ( V_70 -> V_155 [ V_11 ] . V_136 ) {
V_4 = & V_2 -> V_118 [ V_145 ] ;
F_23 ( V_2 , V_4 , & V_70 -> V_155 [ V_11 ] ) ;
V_145 ++ ;
}
for ( V_11 = 0 ; V_11 < V_156 ; V_11 ++ )
if ( V_70 -> V_157 [ V_11 ] . V_136 ) {
V_4 = & V_2 -> V_118 [ V_145 ] ;
F_24 ( V_2 , V_4 , & V_70 -> V_157 [ V_11 ] ) ;
V_145 ++ ;
}
for ( V_11 = 0 ; V_11 < V_158 ; V_11 ++ )
for ( V_146 = 0 ; V_146 < V_70 -> V_159 [ V_11 ] . V_12 ; V_146 ++ ) {
V_4 = & V_2 -> V_118 [ V_145 ] ;
V_37 = F_37 ( V_2 , V_4 , NULL ,
V_70 -> V_159 [ V_11 ] . V_14 +
V_146 * V_160 ) ;
if ( V_37 )
return V_37 ;
V_145 ++ ;
}
if ( V_70 -> V_161 . V_136 ) {
V_4 = & V_2 -> V_118 [ V_145 ] ;
V_4 -> type = V_119 ;
F_23 ( V_2 , V_4 , & V_70 -> V_161 ) ;
V_145 ++ ;
}
if ( V_70 -> V_162 ) {
V_4 = & V_2 -> V_118 [ V_145 ] ;
V_2 -> V_163 = F_38 ( V_2 -> V_13 +
V_70 -> V_162 ,
0 , V_164 , 0 ) ;
if ( ! V_2 -> V_163 )
return - V_151 ;
F_39 ( V_4 , V_2 -> V_163 ) ;
V_145 ++ ;
}
if ( V_70 -> V_72 == V_115 )
F_22 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 )
F_21 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static int F_42 ( struct V_140 * V_2 ,
const struct V_165 * V_166 )
{
unsigned long V_72 ;
V_72 = F_25 ( V_2 , V_166 -> V_167 ) ;
return F_43 ( V_2 , & V_168 , V_72 ) ;
}
