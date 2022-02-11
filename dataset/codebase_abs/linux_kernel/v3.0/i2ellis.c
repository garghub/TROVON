static int
F_1 ( T_1 V_1 , int V_2 , T_2 V_3 )
{
V_1 -> V_4 = V_5 ;
if ( ( unsigned int ) V_2 <= 0x100
|| ( unsigned int ) V_2 >= 0xfff8
|| ( V_2 & 0x7 )
)
{
F_2 ( V_1 , V_6 ) ;
}
V_1 -> V_7 = V_2 ;
V_1 -> V_8 = V_2 + V_9 ;
V_1 -> V_10 = V_2 + V_11 ;
V_1 -> V_12 = V_2 + V_13 ;
V_1 -> V_14 = V_2 + V_15 ;
V_1 -> V_16 = V_2 + V_17 ;
V_18 = V_2 + V_19 ;
V_1 -> V_20 = ( ( V_3 != ( T_2 ) NULL ) ? V_3 : ( T_2 ) V_21 ) ;
V_1 -> V_4 = V_22 ;
V_1 -> V_23 = V_24 ;
F_2 ( V_1 , V_25 ) ;
}
static int
F_3 ( T_1 V_1 )
{
if ( V_1 -> V_4 != V_22 )
{
F_2 ( V_1 , V_26 ) ;
}
F_4 ( 0 , V_1 -> V_7 + V_27 ) ;
F_5 ( V_1 , 50 ) ;
F_4 ( 0 , V_1 -> V_7 + V_27 ) ;
V_1 -> V_23 = V_28 ;
V_29 = 0 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = 0 ;
V_1 -> V_33 = 0 ;
V_1 -> V_34 = NULL ;
V_1 -> V_35 = 0 ;
V_1 -> V_36 [ 0 ] = 0 ;
V_1 -> V_37 = 0 ;
V_1 -> V_38 = 0 ;
V_1 -> V_39 = NULL ;
V_1 -> V_40 = 0 ;
F_2 ( V_1 , V_25 ) ;
}
static int
F_6 ( T_1 V_1 )
{
if ( V_1 -> V_4 != V_22 ) {
F_2 ( V_1 , V_26 ) ;
}
if ( V_1 -> V_23 != V_28 ) {
F_2 ( V_1 , V_41 ) ;
}
F_5 ( V_1 , 2000 ) ;
V_29 = 1 ;
F_2 ( V_1 , V_25 ) ;
}
static int
F_7 ( T_1 V_1 )
{
int V_42 ;
unsigned char V_43 ;
unsigned short V_44 ;
unsigned int V_45 ;
if ( V_1 -> V_4 != V_22 )
{
F_2 ( V_1 , V_26 ) ;
}
if ( V_1 -> V_23 != V_28 || ! V_29 )
{
F_2 ( V_1 , V_41 ) ;
}
V_1 -> V_4 = V_5 ;
for ( V_42 = 0 ; V_42 < sizeof( V_46 ) ; V_42 ++ )
{
if ( ! F_8 ( V_1 ) ) {
V_1 -> V_47 = V_42 ;
F_2 ( V_1 , V_48 ) ;
}
V_1 -> V_49 . V_43 [ V_42 ] = V_43 = F_9 ( V_1 -> V_8 ) ;
if ( ( V_42 == V_50 && V_43 != V_51 ) ||
( V_42 == V_52 && V_43 != V_53 ) )
{
V_1 -> V_47 = V_42 + 1 ;
F_2 ( V_1 , V_26 ) ;
}
}
V_1 -> V_47 = V_42 ;
if ( F_8 ( V_1 ) )
F_2 ( V_1 , V_54 ) ;
if ( V_1 -> V_49 . V_55 . V_56 & V_57 )
{
F_2 ( V_1 , V_58 ) ;
}
switch ( V_1 -> V_49 . V_55 . V_59 & V_60 )
{
case V_61 :
V_1 -> V_62 = V_63 ;
V_1 -> V_64 = 512 ;
V_1 -> V_65 = false ;
V_1 -> V_66 = 15 ;
V_1 -> V_67 [ 1 ] =
V_1 -> V_67 [ 2 ] =
V_1 -> V_67 [ 3 ] =
V_1 -> V_68 [ 1 ] =
V_1 -> V_68 [ 2 ] =
V_1 -> V_68 [ 3 ] = 0 ;
switch ( V_1 -> V_49 . V_55 . V_59 & V_69 )
{
case V_70 :
V_1 -> V_67 [ 0 ] =
V_1 -> V_68 [ 0 ] = 0x0f ;
if ( V_1 -> V_49 . V_55 . V_71 != 4 )
{
F_2 ( V_1 , V_72 ) ;
}
break;
case V_73 :
case V_74 :
V_1 -> V_67 [ 0 ] =
V_1 -> V_68 [ 0 ] = 0xff ;
if ( V_1 -> V_49 . V_55 . V_71 != 8 )
{
F_2 ( V_1 , V_72 ) ;
}
break;
case V_75 :
V_1 -> V_67 [ 0 ] =
V_1 -> V_68 [ 0 ] = 0x3f ;
if ( V_1 -> V_49 . V_55 . V_71 != 6 )
{
F_2 ( V_1 , V_72 ) ;
}
break;
}
if ( V_1 -> V_49 . V_55 . V_56 & V_76 )
{
V_1 -> V_67 [ 0 ] &= ~ 0x0f ;
}
if ( V_1 -> V_49 . V_55 . V_56 & V_77 )
{
V_1 -> V_67 [ 0 ] &= ~ 0xf0 ;
}
break;
case V_78 :
V_1 -> V_62 = V_79 ;
V_42 = V_1 -> V_49 . V_55 . V_80 ;
if ( V_42 < 8 || V_42 > 15 )
{
F_2 ( V_1 , V_72 ) ;
}
V_1 -> V_64 = ( 1 << V_42 ) ;
V_45 = V_1 -> V_49 . V_55 . V_81 ;
if ( V_45 > V_82 )
{
V_45 = V_82 ;
}
V_44 = V_1 -> V_49 . V_55 . V_83 ;
if ( V_44 & V_84 )
{
V_1 -> V_68 [ 0 ] = 0x000f ;
} else {
V_44 &= V_85 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
{
V_1 -> V_68 [ V_42 ] =
( ( V_44 & V_86 ) ? 0xffff : 0x00ff ) ;
V_44 >>= 1 ;
}
}
V_44 = ( V_1 -> V_49 . V_55 . V_87 << 8 ) + V_1 -> V_49 . V_55 . V_71 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
{
V_1 -> V_67 [ V_42 ] = 0 ;
if ( V_44 & 1 ) V_1 -> V_67 [ V_42 ] |= 0x000f ;
if ( V_44 & 2 ) V_1 -> V_67 [ V_42 ] |= 0x00f0 ;
if ( V_44 & 4 ) V_1 -> V_67 [ V_42 ] |= 0x0f00 ;
if ( V_44 & 8 ) V_1 -> V_67 [ V_42 ] |= 0xf000 ;
V_44 >>= 4 ;
}
switch ( V_1 -> V_49 . V_55 . V_88 & ( V_89 | V_90 ) )
{
case V_89 | V_90 :
V_1 -> V_65 = true ;
V_1 -> V_66 = 15 ;
break;
case V_89 :
V_1 -> V_65 = false ;
V_1 -> V_66 = 15 ;
break;
case 0 :
case V_90 :
default:
V_1 -> V_65 = false ;
V_1 -> V_66 = 7 ;
break;
}
break;
default:
F_2 ( V_1 , V_91 ) ;
break;
}
V_1 -> V_92 = 0 ;
switch ( V_1 -> V_49 . V_55 . V_88 & V_93 )
{
case V_94 :
case V_95 :
case V_96 :
case V_97 :
break;
default:
F_2 ( V_1 , V_98 ) ;
}
if ( V_1 -> V_65 )
{
V_1 -> V_99 = V_100 ;
V_1 -> V_101 = V_102 ;
V_1 -> V_103 = V_104 ;
V_1 -> V_105 = V_106 ;
} else {
V_1 -> V_99 = V_107 ;
V_1 -> V_101 = V_108 ;
V_1 -> V_103 = V_109 ;
V_1 -> V_105 = V_110 ;
}
switch( V_1 -> V_62 )
{
case V_63 :
V_1 -> V_111 = V_112 ;
V_1 -> V_113 = V_114 ;
V_1 -> V_115 = V_116 ;
V_1 -> V_117 = V_118 ;
V_1 -> V_119 = V_120 ;
V_1 -> V_121 = V_122 ;
break;
case V_79 :
V_1 -> V_111 = V_123 ;
V_1 -> V_113 = V_124 ;
V_1 -> V_115 = V_125 ;
V_1 -> V_117 = V_126 ;
V_1 -> V_119 = V_127 ;
V_1 -> V_121 = V_128 ;
break;
default:
F_2 ( V_1 , V_72 ) ;
}
V_1 -> V_23 = V_129 ;
V_1 -> V_130 = F_10 ( V_1 ) ;
V_1 -> V_130 = V_131 ;
V_1 -> V_4 = V_22 ;
F_2 ( V_1 , V_25 ) ;
}
static void
F_11 ( unsigned int V_132 )
{
F_12 ( V_132 ) ;
}
static void
V_21 ( void )
{
return;
}
static int
V_100 ( T_1 V_1 , unsigned char * V_2 , int V_133 )
{
if ( V_1 -> V_4 != V_22 )
F_2 ( V_1 , V_134 ) ;
F_13 ( V_1 -> V_8 , V_2 , V_133 ) ;
F_2 ( V_1 , V_25 ) ;
}
static int
V_107 ( T_1 V_1 , unsigned char * V_2 , int V_133 )
{
if ( V_1 -> V_4 != V_22 )
F_2 ( V_1 , V_134 ) ;
F_14 ( V_1 -> V_8 , V_2 , V_133 ) ;
F_2 ( V_1 , V_25 ) ;
}
static int
V_102 ( T_1 V_1 , unsigned char * V_2 , int V_133 )
{
if ( V_1 -> V_4 != V_22 )
F_2 ( V_1 , V_134 ) ;
F_15 ( V_1 -> V_8 , V_2 , V_133 ) ;
F_2 ( V_1 , V_25 ) ;
}
static int
V_108 ( T_1 V_1 , unsigned char * V_2 , int V_133 )
{
if ( V_1 -> V_4 != V_22 )
F_2 ( V_1 , V_134 ) ;
F_16 ( V_1 -> V_8 , V_2 , V_133 ) ;
F_2 ( V_1 , V_25 ) ;
}
static unsigned short
V_106 ( T_1 V_1 )
{
return F_17 ( V_1 -> V_8 ) ;
}
static unsigned short
V_110 ( T_1 V_1 )
{
unsigned short V_135 ;
V_135 = F_9 ( V_1 -> V_8 ) ;
return ( F_9 ( V_1 -> V_8 ) << 8 ) | V_135 ;
}
static void
V_104 ( T_1 V_1 , unsigned short V_136 )
{
F_18 ( ( int ) V_136 , V_1 -> V_8 ) ;
}
static void
V_109 ( T_1 V_1 , unsigned short V_136 )
{
F_4 ( ( char ) V_136 , V_1 -> V_8 ) ;
F_4 ( ( char ) ( V_136 >> 8 ) , V_1 -> V_8 ) ;
}
static int
V_112 ( T_1 V_1 , int V_137 )
{
unsigned long V_138 ;
int V_42 ;
for (; ; )
{
F_19 ( & V_139 , V_138 ) ;
F_4 ( V_140 , V_1 -> V_12 ) ;
F_4 ( V_141 , V_1 -> V_12 ) ;
V_42 = F_9 ( V_1 -> V_10 ) ;
F_4 ( V_140 , V_1 -> V_12 ) ;
F_4 ( V_142 , V_1 -> V_12 ) ;
if ( V_42 & V_143 )
{
F_20 ( V_1 ) ;
F_21 ( & V_139 , V_138 ) ;
F_2 ( V_1 , V_25 ) ;
}
F_21 ( & V_139 , V_138 ) ;
if ( V_137 -- == 0 )
break;
F_5 ( V_1 , 1 ) ;
}
F_2 ( V_1 , V_144 ) ;
}
static int
V_123 ( T_1 V_1 , int V_137 )
{
unsigned long V_138 ;
for (; ; )
{
F_19 ( & V_139 , V_138 ) ;
if ( F_9 ( V_1 -> V_10 ) & V_145 ) {
F_20 ( V_1 ) ;
F_21 ( & V_139 , V_138 ) ;
F_2 ( V_1 , V_25 ) ;
}
F_21 ( & V_139 , V_138 ) ;
if ( V_137 -- == 0 )
break;
F_5 ( V_1 , 1 ) ;
}
F_2 ( V_1 , V_144 ) ;
}
static int
V_114 ( T_1 V_1 )
{
int V_146 = V_1 -> V_12 ;
F_4 ( V_147 , V_146 ) ;
return F_9 ( V_146 ) == 0 ;
}
static int
V_124 ( T_1 V_1 )
{
return ! ( F_9 ( V_1 -> V_10 ) & V_148 ) ;
}
static int
V_116 ( T_1 V_1 , unsigned char V_149 )
{
int V_146 = V_1 -> V_12 ;
F_4 ( V_147 , V_146 ) ;
if ( F_9 ( V_146 ) == 0 ) {
F_4 ( V_147 , V_146 ) ;
F_4 ( V_149 , V_146 ) ;
return 1 ;
}
return 0 ;
}
static int
V_125 ( T_1 V_1 , unsigned char V_149 )
{
if ( F_9 ( V_1 -> V_10 ) & V_148 )
return 0 ;
F_4 ( V_149 , V_1 -> V_14 ) ;
return 1 ;
}
static unsigned short
V_118 ( T_1 V_1 )
{
if ( F_22 ( V_1 ) ) {
F_4 ( V_150 , V_1 -> V_12 ) ;
return F_9 ( V_1 -> V_12 ) ;
} else {
return V_131 ;
}
}
static unsigned short
V_126 ( T_1 V_1 )
{
if ( F_22 ( V_1 ) )
return F_9 ( V_1 -> V_14 ) ;
else
return V_131 ;
}
static void
V_120 ( T_1 V_1 )
{
F_4 ( V_151 , V_1 -> V_12 ) ;
F_4 ( V_152 , V_1 -> V_12 ) ;
}
static void
V_127 ( T_1 V_1 )
{
F_4 ( V_153 , V_1 -> V_16 ) ;
}
static void
V_122 ( T_1 V_1 , unsigned char V_136 )
{
F_4 ( V_151 , V_1 -> V_12 ) ;
F_4 ( V_136 , V_1 -> V_12 ) ;
}
static void
V_128 ( T_1 V_1 , unsigned char V_136 )
{
F_4 ( V_136 , V_1 -> V_16 ) ;
}
static int
F_23 ( T_1 V_1 , T_3 V_154 , int V_155 )
{
int V_42 ;
int V_156 ;
if ( V_1 -> V_4 != V_22 ) return V_157 ;
switch( V_1 -> V_23 )
{
case V_129 :
if ( V_154 -> V_55 . V_158 != V_159 )
{
return V_160 ;
}
V_1 -> V_161 = 1 + V_154 -> V_55 . V_162 ;
V_1 -> V_23 = V_163 ;
V_1 -> V_164 = V_154 -> V_55 . V_165 ;
V_1 -> V_166 = V_154 -> V_55 . V_167 ;
V_1 -> V_168 = V_154 -> V_55 . V_169 ;
V_156 = 1 ;
break;
case V_163 :
V_156 = 0 ;
break;
default:
return V_170 ;
}
if ( ! F_24 ( V_1 , V_171 ) ) {
return V_172 ;
}
if ( ! F_25 ( V_1 , V_154 -> V_43 , V_173 ) ) {
return V_157 ;
}
if ( V_156 ) {
if ( ! F_24 ( V_1 , V_174 ) ) {
return V_172 ;
}
}
if ( -- ( V_1 -> V_161 ) ) {
return V_175 ;
}
if ( ! F_24 ( V_1 , V_171 ) ) {
return V_172 ;
}
V_42 = V_176 / 10 ;
while ( -- V_42 ) {
if ( F_8 ( V_1 ) ) {
switch ( F_9 ( V_1 -> V_8 ) ) {
case V_177 :
V_1 -> V_23 =
V_155 ? V_178 : V_179 ;
if ( V_1 -> V_49 . V_55 . V_180 & V_181 ) {
F_5 ( V_1 , 700 ) ;
}
return V_182 ;
case V_183 :
default:
return V_184 ;
}
}
F_5 ( V_1 , 10 ) ;
}
V_1 -> V_23 = V_185 ;
return V_172 ;
}
static int
F_26 ( T_1 V_1 , T_3 V_154 , int V_155 , int V_186 )
{
int V_187 ;
if ( V_1 -> V_23 != V_129 ) return V_170 ;
while ( V_186 > 0 ) {
V_186 -= V_173 ;
V_187 = F_23 ( V_1 , V_154 ++ , V_155 ) ;
switch( V_187 )
{
case V_182 :
return ( ( V_186 > 0 ) ? V_188 : V_182 ) ;
case V_175 :
break;
default:
return V_187 ;
}
}
return V_189 ;
}
