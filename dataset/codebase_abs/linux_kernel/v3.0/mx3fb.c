static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_2 V_3 ;
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 | V_9 , V_8 ) ;
}
static T_2 F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_2 V_3 ;
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 & ~ V_9 , V_8 ) ;
return V_3 & V_9 ;
}
static void F_7 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_13 * V_13 = & V_12 -> V_13 ;
unsigned long V_14 ;
T_3 V_15 ;
if ( V_10 -> V_16 )
F_8 ( V_2 -> V_17 , L_1 , V_10 ,
F_9 ( V_10 -> V_16 ) , F_9 ( V_10 -> V_16 ) -> V_18 ) ;
else
F_8 ( V_2 -> V_17 , L_2 , V_10 ) ;
if ( V_10 -> V_15 < 0 ) {
V_10 -> V_16 = V_13 -> V_19 -> V_20 ( V_13 ,
& V_10 -> V_18 [ 0 ] , 1 , V_21 , V_22 ) ;
if ( ! V_10 -> V_16 ) {
F_10 ( V_2 -> V_17 , L_3 ,
V_13 -> V_23 ) ;
return;
}
V_10 -> V_16 -> V_24 = V_10 -> V_16 ;
V_10 -> V_16 -> V_25 = V_26 ;
V_15 = V_10 -> V_16 -> V_27 ( V_10 -> V_16 ) ;
F_8 ( V_2 -> V_17 , L_4 , __LINE__ ,
V_10 -> V_16 , V_15 , F_11 ( & V_12 -> V_28 ) ? '-' : '+' ) ;
} else {
if ( ! V_10 -> V_16 || ! V_10 -> V_16 -> V_27 ) {
F_10 ( V_2 -> V_17 , L_5 ,
V_13 -> V_23 ) ;
return;
}
F_12 ( V_13 ) ;
V_15 = V_10 -> V_15 ;
F_8 ( V_2 -> V_17 , L_6 , __LINE__ ,
V_10 -> V_16 , V_15 , F_11 ( & V_12 -> V_28 ) ? '-' : '+' ) ;
}
if ( V_15 >= 0 ) {
F_13 ( & V_2 -> V_29 , V_14 ) ;
F_5 ( V_10 ) ;
V_10 -> V_15 = V_15 ;
F_14 ( & V_2 -> V_29 , V_14 ) ;
}
F_15 ( 2 ) ;
}
static void F_16 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_30 ;
unsigned long V_14 ;
F_13 ( & V_2 -> V_29 , V_14 ) ;
V_30 = F_6 ( V_10 ) ;
F_14 ( & V_2 -> V_29 , V_14 ) ;
V_10 -> V_16 -> V_31 -> V_19 -> V_32 ( V_10 -> V_16 -> V_31 ,
V_33 , 0 ) ;
V_10 -> V_16 = NULL ;
V_10 -> V_15 = - V_34 ;
}
static int F_17 ( struct V_1 * V_2 , enum V_35 V_36 ,
T_4 V_37 , T_4 V_38 )
{
if ( V_36 != V_39 )
return - V_34 ;
V_37 += V_2 -> V_40 ;
V_38 += V_2 -> V_41 ;
F_3 ( V_2 , ( V_37 << 16 ) | V_38 , V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , enum V_43 V_44 ,
T_2 V_45 ,
T_5 V_46 , T_5 V_47 ,
enum V_48 V_48 ,
T_5 V_40 , T_5 V_49 ,
T_5 V_50 , T_5 V_41 ,
T_5 V_51 , T_5 V_52 ,
struct V_53 V_54 )
{
unsigned long V_55 ;
T_2 V_3 ;
T_2 V_56 ;
T_2 div ;
struct V_57 * V_58 ;
F_8 ( V_2 -> V_17 , L_7 , V_46 , V_47 ) ;
if ( V_51 == 0 || V_49 == 0 )
return - V_34 ;
V_3 = ( ( T_2 ) ( V_49 - 1 ) << 26 ) |
( ( T_2 ) ( V_46 + V_40 + V_50 - 1 ) << 16 ) ;
F_3 ( V_2 , V_3 , V_59 ) ;
#ifdef F_19
F_20 ( V_60 L_8 , V_3 ) ;
#endif
V_3 = ( ( T_2 ) ( V_51 - 1 ) << 26 ) | V_61 |
( ( T_2 ) ( V_47 + V_41 + V_52 - 1 ) << 16 ) ;
F_3 ( V_2 , V_3 , V_62 ) ;
#ifdef F_19
F_20 ( V_60 L_9 , V_3 ) ;
#endif
V_2 -> V_40 = V_40 ;
V_2 -> V_41 = V_41 ;
switch ( V_44 ) {
case V_63 :
F_3 ( V_2 , 0x00FD0102L , V_64 ) ;
F_3 ( V_2 , 0x00F500F4L , V_65 ) ;
F_3 ( V_2 , V_66 | V_67 , V_8 ) ;
break;
case V_68 :
F_3 ( V_2 , V_67 , V_8 ) ;
break;
default:
return - V_34 ;
}
V_58 = F_21 ( V_2 -> V_17 , NULL ) ;
if ( ! F_22 ( V_58 ) ) {
div = F_23 ( V_58 ) * 16 / V_45 ;
F_24 ( V_58 ) ;
} else {
div = 0 ;
}
if ( div < 0x40 ) {
F_8 ( V_2 -> V_17 ,
L_10 ) ;
div = 0x40 ;
}
F_8 ( V_2 -> V_17 , L_11 ,
V_45 , div >> 4 , ( div & 7 ) * 125 ) ;
F_13 ( & V_2 -> V_29 , V_55 ) ;
F_3 ( V_2 , ( ( ( div / 8 ) - 1 ) << 22 ) | div , V_69 ) ;
V_56 = F_1 ( V_2 , V_70 ) & 0x78FFFFFF ;
V_56 |= V_54 . V_71 << V_72 |
V_54 . V_73 << V_74 |
V_54 . V_75 << V_76 ;
F_3 ( V_2 , V_56 , V_70 ) ;
V_56 = F_1 ( V_2 , V_77 ) & 0xE0FFFFFF ;
V_56 |= V_54 . V_78 << V_79 |
V_54 . V_80 << V_81 |
V_54 . V_82 << V_83 |
V_54 . V_84 << V_85 |
V_54 . V_86 << V_87 ;
F_3 ( V_2 , V_56 , V_77 ) ;
switch ( V_48 ) {
case V_88 :
F_3 ( V_2 , V_89 [ 0 ] , V_90 ) ;
F_3 ( V_2 , V_89 [ 1 ] , V_91 ) ;
F_3 ( V_2 , V_89 [ 2 ] , V_92 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_93 ) |
( ( V_89 [ 3 ] - 1 ) << 12 ) , V_93 ) ;
break;
case V_94 :
F_3 ( V_2 , V_89 [ 4 ] , V_90 ) ;
F_3 ( V_2 , V_89 [ 5 ] , V_91 ) ;
F_3 ( V_2 , V_89 [ 6 ] , V_92 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_93 ) |
( ( V_89 [ 7 ] - 1 ) << 12 ) , V_93 ) ;
break;
case V_95 :
F_3 ( V_2 , V_89 [ 8 ] , V_90 ) ;
F_3 ( V_2 , V_89 [ 9 ] , V_91 ) ;
F_3 ( V_2 , V_89 [ 10 ] , V_92 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_93 ) |
( ( V_89 [ 11 ] - 1 ) << 12 ) , V_93 ) ;
break;
default:
F_3 ( V_2 , V_89 [ 12 ] , V_90 ) ;
F_3 ( V_2 , V_89 [ 13 ] , V_91 ) ;
F_3 ( V_2 , V_89 [ 14 ] , V_92 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_93 ) |
( ( V_89 [ 15 ] - 1 ) << 12 ) , V_93 ) ;
break;
}
F_14 ( & V_2 -> V_29 , V_55 ) ;
F_8 ( V_2 -> V_17 , L_12 ,
F_1 ( V_2 , V_70 ) ) ;
F_8 ( V_2 -> V_17 , L_13 ,
F_1 ( V_2 , V_77 ) ) ;
F_8 ( V_2 -> V_17 , L_14 ,
F_1 ( V_2 , V_69 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , enum V_35 V_36 ,
bool V_96 , T_2 V_97 )
{
T_2 V_3 , V_98 ;
unsigned long V_55 ;
F_13 ( & V_2 -> V_29 , V_55 ) ;
V_98 = F_1 ( V_2 , V_8 ) ;
if ( V_36 == V_39 )
V_98 &= ~ V_99 ;
else
V_98 |= V_99 ;
if ( V_96 ) {
V_3 = F_1 ( V_2 , V_100 ) & 0xFF000000L ;
F_3 ( V_2 , V_3 | ( V_97 & 0x00FFFFFFL ) ,
V_100 ) ;
V_98 |= V_101 ;
} else {
V_98 &= ~ V_101 ;
}
F_3 ( V_2 , V_98 , V_8 ) ;
F_14 ( & V_2 -> V_29 , V_55 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , bool V_96 , T_6 V_102 )
{
T_2 V_3 ;
unsigned long V_55 ;
F_13 ( & V_2 -> V_29 , V_55 ) ;
if ( V_96 ) {
V_3 = F_1 ( V_2 , V_100 ) & 0x00FFFFFFL ;
F_3 ( V_2 , V_3 | ( ( T_2 ) V_102 << 24 ) , V_100 ) ;
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 | V_103 , V_8 ) ;
} else {
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 & ~ V_103 , V_8 ) ;
}
F_14 ( & V_2 -> V_29 , V_55 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , T_6 V_5 )
{
F_8 ( V_2 -> V_17 , L_15 , V_104 , V_5 ) ;
F_3 ( V_2 , 0x03000000UL | V_5 << 16 , V_105 ) ;
return;
}
static T_2 F_28 ( int V_106 )
{
T_2 V_107 = 0 ;
switch ( V_106 ) {
case 24 :
V_107 = V_108 ;
break;
case 32 :
V_107 = V_109 ;
break;
case 16 :
V_107 = V_110 ;
break;
}
return V_107 ;
}
static int F_29 ( struct V_111 * V_7 )
{
struct V_112 * V_113 = & V_7 -> V_113 ;
struct V_114 * V_115 = & V_7 -> V_115 ;
strncpy ( V_113 -> V_116 , L_16 , 8 ) ;
V_113 -> V_117 = V_115 -> V_118 * V_115 -> V_119 / 8 ;
V_113 -> type = V_120 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = V_124 ;
V_113 -> V_125 = 1 ;
V_113 -> V_126 = 1 ;
return 0 ;
}
static void V_26 ( void * V_127 )
{
struct V_128 * V_129 = F_9 ( V_127 ) ;
struct V_13 * V_31 = V_129 -> V_16 . V_31 ;
struct V_11 * V_130 = F_30 ( V_31 ) ;
struct V_1 * V_2 = V_130 -> V_131 ;
struct V_6 * V_10 = V_2 -> V_7 -> V_132 ;
F_8 ( V_2 -> V_17 , L_17 , V_130 -> V_133 ) ;
F_31 ( V_130 -> V_133 ) ;
F_32 ( & V_10 -> V_134 ) ;
}
static int F_33 ( struct V_111 * V_7 , bool V_29 )
{
T_1 V_135 ;
struct V_53 V_136 ;
enum V_43 V_137 = V_68 ;
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_138 * V_139 = & V_12 -> V_140 . V_139 ;
struct V_141 * V_18 = V_10 -> V_18 ;
if ( V_10 -> V_16 )
F_16 ( V_10 ) ;
F_29 ( V_7 ) ;
V_135 = V_7 -> V_115 . V_142 * V_7 -> V_113 . V_117 ;
if ( V_135 > V_7 -> V_113 . V_143 ) {
if ( V_7 -> V_113 . V_144 )
F_34 ( V_7 ) ;
if ( F_35 ( V_7 , V_135 , V_29 ) < 0 )
return - V_145 ;
}
F_36 ( & V_18 [ 0 ] , 1 ) ;
F_36 ( & V_18 [ 1 ] , 1 ) ;
F_37 ( & V_18 [ 0 ] ) = V_7 -> V_113 . V_144 ;
F_38 ( & V_18 [ 0 ] , F_39 ( V_7 -> V_146 ) ,
V_7 -> V_113 . V_143 ,
F_40 ( V_7 -> V_146 ) ) ;
if ( V_10 -> V_147 == V_39 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
if ( V_7 -> V_115 . V_148 & V_149 )
V_136 . V_84 = true ;
if ( V_7 -> V_115 . V_148 & V_150 )
V_136 . V_86 = true ;
if ( V_7 -> V_115 . V_148 & V_151 )
V_136 . V_80 = true ;
if ( V_7 -> V_115 . V_148 & V_152 )
V_136 . V_78 = true ;
if ( V_7 -> V_115 . V_148 & V_153 )
V_136 . V_82 = true ;
if ( V_7 -> V_115 . V_148 & V_154 )
V_136 . V_75 = true ;
if ( V_7 -> V_115 . V_148 & V_155 )
V_136 . V_73 = true ;
if ( V_7 -> V_115 . V_148 & V_156 )
V_137 = V_63 ;
F_8 ( V_7 -> V_19 , L_18 ,
( T_1 ) ( F_41 ( V_7 -> V_115 . V_157 ) * 1000UL ) ) ;
if ( F_18 ( V_2 , V_137 ,
( F_41 ( V_7 -> V_115 . V_157 ) ) * 1000UL ,
V_7 -> V_115 . V_158 , V_7 -> V_115 . V_159 ,
( V_7 -> V_115 . V_148 & V_160 ) ?
V_95 : V_94 ,
V_7 -> V_115 . V_161 ,
V_7 -> V_115 . V_162 ,
V_7 -> V_115 . V_163 +
V_7 -> V_115 . V_162 ,
V_7 -> V_115 . V_164 ,
V_7 -> V_115 . V_165 ,
V_7 -> V_115 . V_166 +
V_7 -> V_115 . V_165 , V_136 ) != 0 ) {
F_10 ( V_7 -> V_19 ,
L_19 ) ;
return - V_34 ;
}
}
F_17 ( V_2 , V_10 -> V_147 , 0 , 0 ) ;
V_10 -> V_167 = 0 ;
V_139 -> V_168 = F_28 ( V_7 -> V_115 . V_119 ) ;
V_139 -> V_169 = V_7 -> V_115 . V_158 ;
V_139 -> V_170 = V_7 -> V_115 . V_159 ;
V_139 -> V_171 = V_7 -> V_115 . V_118 ;
if ( V_10 -> V_172 == V_173 )
F_7 ( V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 = V_10 -> V_11 ;
int V_174 ;
F_8 ( V_2 -> V_17 , L_20 , V_104 , F_11 ( & V_12 -> V_28 ) ? '-' : '+' ) ;
F_43 ( & V_10 -> V_175 ) ;
V_174 = F_33 ( V_7 , true ) ;
F_44 ( & V_10 -> V_175 ) ;
return V_174 ;
}
static int F_45 ( struct V_114 * V_115 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
T_1 V_176 ;
T_1 V_177 ;
F_8 ( V_7 -> V_19 , L_21 , V_104 ) ;
if ( V_115 -> V_118 < V_115 -> V_158 )
V_115 -> V_118 = V_115 -> V_158 ;
if ( V_115 -> V_142 < V_115 -> V_159 )
V_115 -> V_142 = V_115 -> V_159 ;
if ( ( V_115 -> V_119 != 32 ) && ( V_115 -> V_119 != 24 ) &&
( V_115 -> V_119 != 16 ) )
V_115 -> V_119 = V_178 ;
switch ( V_115 -> V_119 ) {
case 16 :
V_115 -> V_179 . V_180 = 5 ;
V_115 -> V_179 . V_181 = 11 ;
V_115 -> V_179 . V_182 = 0 ;
V_115 -> V_183 . V_180 = 6 ;
V_115 -> V_183 . V_181 = 5 ;
V_115 -> V_183 . V_182 = 0 ;
V_115 -> V_184 . V_180 = 5 ;
V_115 -> V_184 . V_181 = 0 ;
V_115 -> V_184 . V_182 = 0 ;
V_115 -> V_185 . V_180 = 0 ;
V_115 -> V_185 . V_181 = 0 ;
V_115 -> V_185 . V_182 = 0 ;
break;
case 24 :
V_115 -> V_179 . V_180 = 8 ;
V_115 -> V_179 . V_181 = 16 ;
V_115 -> V_179 . V_182 = 0 ;
V_115 -> V_183 . V_180 = 8 ;
V_115 -> V_183 . V_181 = 8 ;
V_115 -> V_183 . V_182 = 0 ;
V_115 -> V_184 . V_180 = 8 ;
V_115 -> V_184 . V_181 = 0 ;
V_115 -> V_184 . V_182 = 0 ;
V_115 -> V_185 . V_180 = 0 ;
V_115 -> V_185 . V_181 = 0 ;
V_115 -> V_185 . V_182 = 0 ;
break;
case 32 :
V_115 -> V_179 . V_180 = 8 ;
V_115 -> V_179 . V_181 = 16 ;
V_115 -> V_179 . V_182 = 0 ;
V_115 -> V_183 . V_180 = 8 ;
V_115 -> V_183 . V_181 = 8 ;
V_115 -> V_183 . V_182 = 0 ;
V_115 -> V_184 . V_180 = 8 ;
V_115 -> V_184 . V_181 = 0 ;
V_115 -> V_184 . V_182 = 0 ;
V_115 -> V_185 . V_180 = 8 ;
V_115 -> V_185 . V_181 = 24 ;
V_115 -> V_185 . V_182 = 0 ;
break;
}
if ( V_115 -> V_157 < 1000 ) {
V_177 = V_115 -> V_158 + V_115 -> V_163 + V_115 -> V_162 +
V_115 -> V_161 ;
V_176 = V_115 -> V_159 + V_115 -> V_166 + V_115 -> V_165 +
V_115 -> V_164 ;
V_115 -> V_157 = ( V_176 * V_177 * 6UL ) / 100UL ;
V_115 -> V_157 = F_46 ( V_115 -> V_157 ) ;
F_8 ( V_7 -> V_19 , L_22 ,
V_115 -> V_157 ) ;
}
V_115 -> V_47 = - 1 ;
V_115 -> V_46 = - 1 ;
V_115 -> V_186 = 0 ;
V_115 -> V_148 |= V_10 -> V_148 ;
V_10 -> V_148 |= V_115 -> V_148 ;
return 0 ;
}
static T_1 F_47 ( unsigned int V_31 , struct V_187 * V_188 )
{
V_31 &= 0xffff ;
V_31 >>= 16 - V_188 -> V_180 ;
return V_31 << V_188 -> V_181 ;
}
static int F_48 ( unsigned int V_189 , unsigned int V_179 ,
unsigned int V_183 , unsigned int V_184 ,
unsigned int V_190 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
T_1 V_191 ;
int V_174 = 1 ;
F_8 ( V_7 -> V_19 , L_23 , V_104 , V_189 ) ;
F_43 ( & V_10 -> V_175 ) ;
if ( V_7 -> V_115 . V_186 )
V_179 = V_183 = V_184 = ( 19595 * V_179 + 38470 * V_183 +
7471 * V_184 ) >> 16 ;
switch ( V_7 -> V_113 . V_123 ) {
case V_124 :
if ( V_189 < 16 ) {
T_1 * V_192 = V_7 -> V_193 ;
V_191 = F_47 ( V_179 , & V_7 -> V_115 . V_179 ) ;
V_191 |= F_47 ( V_183 , & V_7 -> V_115 . V_183 ) ;
V_191 |= F_47 ( V_184 , & V_7 -> V_115 . V_184 ) ;
V_192 [ V_189 ] = V_191 ;
V_174 = 0 ;
}
break;
case V_194 :
case V_195 :
break;
}
F_44 ( & V_10 -> V_175 ) ;
return V_174 ;
}
static void F_49 ( int V_172 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_172 = V_172 ;
switch ( V_172 ) {
case V_196 :
case V_197 :
case V_198 :
case V_199 :
F_27 ( V_2 , 0 ) ;
memset ( ( char * ) V_7 -> V_146 , 0 , V_7 -> V_113 . V_143 ) ;
F_15 ( 25 ) ;
F_16 ( V_10 ) ;
break;
case V_173 :
F_7 ( V_10 ) ;
F_27 ( V_2 , V_2 -> V_200 ) ;
break;
}
}
static int F_50 ( int V_172 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
F_8 ( V_7 -> V_19 , L_24 , V_104 ,
V_172 , V_7 -> V_146 , V_7 -> V_113 . V_143 ) ;
if ( V_10 -> V_172 == V_172 )
return 0 ;
F_43 ( & V_10 -> V_175 ) ;
F_49 ( V_172 , V_7 ) ;
F_44 ( & V_10 -> V_175 ) ;
return 0 ;
}
static int F_51 ( struct V_114 * V_115 ,
struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
T_1 V_201 ;
unsigned long V_202 ;
T_7 V_181 ;
T_3 V_15 ;
struct V_141 * V_18 = V_10 -> V_18 ;
struct V_13 * V_13 = & V_10 -> V_11 -> V_13 ;
struct V_203 * V_16 ;
int V_174 ;
F_8 ( V_7 -> V_19 , L_20 , V_104 ,
F_11 ( & V_10 -> V_11 -> V_28 ) ? '-' : '+' ) ;
if ( V_115 -> V_204 > 0 ) {
F_8 ( V_7 -> V_19 , L_25 ) ;
return - V_34 ;
}
if ( V_7 -> V_115 . V_204 == V_115 -> V_204 &&
V_7 -> V_115 . V_205 == V_115 -> V_205 )
return 0 ;
V_201 = V_115 -> V_205 ;
if ( ! ( V_115 -> V_206 & V_207 ) )
V_201 += V_115 -> V_159 ;
if ( V_201 > V_7 -> V_115 . V_142 )
return - V_34 ;
F_43 ( & V_10 -> V_175 ) ;
V_181 = ( V_115 -> V_205 * V_115 -> V_118 + V_115 -> V_204 ) *
( V_115 -> V_119 / 8 ) ;
V_202 = V_7 -> V_113 . V_144 + V_181 ;
F_8 ( V_7 -> V_19 , L_26 ,
V_10 -> V_167 , V_202 ) ;
F_52 ( & V_10 -> V_134 ) ;
F_53 ( V_10 -> V_11 -> V_133 ) ;
V_174 = F_54 ( & V_10 -> V_134 , V_208 / 10 ) ;
if ( V_174 <= 0 ) {
F_44 ( & V_10 -> V_175 ) ;
F_55 ( V_7 -> V_19 , L_27 , V_174 < 0 ?
L_28 : L_29 ) ;
F_56 ( V_10 -> V_11 -> V_133 ) ;
return V_174 ? : - V_209 ;
}
V_10 -> V_167 = ! V_10 -> V_167 ;
F_37 ( & V_18 [ V_10 -> V_167 ] ) = V_202 ;
F_38 ( & V_18 [ V_10 -> V_167 ] ,
F_39 ( V_7 -> V_146 + V_181 ) , V_7 -> V_113 . V_143 ,
F_40 ( V_7 -> V_146 + V_181 ) ) ;
if ( V_10 -> V_16 )
F_57 ( V_10 -> V_16 ) ;
V_16 = V_13 -> V_19 -> V_20 ( V_13 , V_18 +
V_10 -> V_167 , 1 , V_21 , V_22 ) ;
if ( ! V_16 ) {
F_10 ( V_7 -> V_19 ,
L_30 ) ;
F_44 ( & V_10 -> V_175 ) ;
return - V_210 ;
}
V_16 -> V_24 = V_16 ;
V_16 -> V_25 = V_26 ;
V_15 = V_16 -> V_27 ( V_16 ) ;
F_8 ( V_7 -> V_19 , L_31 , __LINE__ , V_16 , V_15 ) ;
if ( V_15 < 0 ) {
F_10 ( V_7 -> V_19 ,
L_32 ,
V_10 -> V_167 , V_202 ) ;
F_44 ( & V_10 -> V_175 ) ;
return - V_210 ;
}
V_10 -> V_16 = V_16 ;
V_7 -> V_115 . V_204 = V_115 -> V_204 ;
V_7 -> V_115 . V_205 = V_115 -> V_205 ;
if ( V_115 -> V_206 & V_207 )
V_7 -> V_115 . V_206 |= V_207 ;
else
V_7 -> V_115 . V_206 &= ~ V_207 ;
F_44 ( & V_10 -> V_175 ) ;
F_8 ( V_7 -> V_19 , L_33 ) ;
return 0 ;
}
static int F_58 ( struct V_211 * V_212 , T_8 V_213 )
{
struct V_1 * V_2 = F_59 ( V_212 ) ;
struct V_6 * V_10 = V_2 -> V_7 -> V_132 ;
F_60 () ;
F_61 ( V_2 -> V_7 , 1 ) ;
F_62 () ;
if ( V_10 -> V_172 == V_173 ) {
F_16 ( V_10 ) ;
F_27 ( V_2 , 0 ) ;
}
return 0 ;
}
static int F_63 ( struct V_211 * V_212 )
{
struct V_1 * V_2 = F_59 ( V_212 ) ;
struct V_6 * V_10 = V_2 -> V_7 -> V_132 ;
if ( V_10 -> V_172 == V_173 ) {
F_7 ( V_10 ) ;
F_27 ( V_2 , V_2 -> V_200 ) ;
}
F_60 () ;
F_61 ( V_2 -> V_7 , 0 ) ;
F_62 () ;
return 0 ;
}
static int F_35 ( struct V_111 * V_7 , unsigned int V_135 ,
bool V_29 )
{
int V_214 = 0 ;
T_9 V_215 ;
V_7 -> V_146 = F_64 ( V_7 -> V_19 ,
V_135 ,
& V_215 , V_216 ) ;
if ( ! V_7 -> V_146 ) {
F_10 ( V_7 -> V_19 , L_34 ,
V_135 ) ;
V_214 = - V_217 ;
goto V_218;
}
if ( V_29 )
F_43 ( & V_7 -> V_219 ) ;
V_7 -> V_113 . V_144 = V_215 ;
V_7 -> V_113 . V_143 = V_135 ;
if ( V_29 )
F_44 ( & V_7 -> V_219 ) ;
F_8 ( V_7 -> V_19 , L_35 ,
( T_2 ) V_7 -> V_113 . V_144 , V_7 -> V_146 , V_7 -> V_113 . V_143 ) ;
V_7 -> V_220 = V_7 -> V_113 . V_143 ;
memset ( ( char * ) V_7 -> V_146 , 0 , V_7 -> V_113 . V_143 ) ;
return 0 ;
V_218:
V_7 -> V_113 . V_143 = 0 ;
V_7 -> V_113 . V_144 = 0 ;
V_7 -> V_146 = NULL ;
return V_214 ;
}
static int F_34 ( struct V_111 * V_7 )
{
F_65 ( V_7 -> V_19 , V_7 -> V_113 . V_143 ,
V_7 -> V_146 , V_7 -> V_113 . V_144 ) ;
V_7 -> V_146 = 0 ;
F_43 ( & V_7 -> V_219 ) ;
V_7 -> V_113 . V_144 = 0 ;
V_7 -> V_113 . V_143 = 0 ;
F_44 ( & V_7 -> V_219 ) ;
return 0 ;
}
static struct V_111 * F_66 ( struct V_19 * V_17 , struct V_221 * V_222 )
{
struct V_111 * V_7 ;
struct V_6 * V_223 ;
int V_174 ;
V_7 = F_67 ( sizeof( struct V_6 ) , V_17 ) ;
if ( ! V_7 )
return NULL ;
V_223 = V_7 -> V_132 ;
V_223 -> V_15 = - V_34 ;
V_223 -> V_167 = 0 ;
V_7 -> V_115 . V_224 = V_225 ;
V_7 -> V_226 = V_222 ;
V_7 -> V_14 = V_227 ;
V_7 -> V_193 = V_223 -> V_193 ;
F_68 ( & V_223 -> V_175 ) ;
V_174 = F_69 ( & V_7 -> V_228 , 16 , 0 ) ;
if ( V_174 < 0 ) {
F_70 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_19 * V_17 = V_2 -> V_17 ;
struct V_229 * V_230 = V_17 -> V_231 ;
const char * V_232 = V_230 -> V_232 ;
unsigned int V_233 ;
struct V_111 * V_7 ;
struct V_6 * V_223 ;
const struct V_234 * V_137 ;
int V_174 , V_235 ;
V_12 -> V_131 = V_2 ;
V_233 = V_12 -> V_133 ;
if ( V_12 -> V_13 . V_23 != V_39 )
return - V_34 ;
V_7 = F_66 ( V_17 , & V_236 ) ;
if ( ! V_7 )
return - V_145 ;
if ( ! V_237 )
V_237 = V_232 ;
if ( ! V_237 ) {
V_174 = - V_34 ;
goto V_238;
}
if ( V_230 -> V_137 && V_230 -> V_235 ) {
V_137 = V_230 -> V_137 ;
V_235 = V_230 -> V_235 ;
} else {
V_137 = V_239 ;
V_235 = F_72 ( V_239 ) ;
}
if ( ! F_73 ( & V_7 -> V_115 , V_7 , V_237 , V_137 ,
V_235 , NULL , V_178 ) ) {
V_174 = - V_217 ;
goto V_238;
}
F_74 ( V_137 , V_235 , & V_7 -> V_240 ) ;
V_7 -> V_115 . V_142 = V_7 -> V_115 . V_159 * 2 ;
V_2 -> V_7 = V_7 ;
F_3 ( V_2 , 0x00100010L , V_241 ) ;
F_27 ( V_2 , 255 ) ;
F_26 ( V_2 , true , 0xFF ) ;
F_25 ( V_2 , V_39 , false , 0 ) ;
V_223 = V_7 -> V_132 ;
V_223 -> V_11 = V_12 ;
V_223 -> V_147 = V_12 -> V_13 . V_23 ;
V_223 -> V_2 = V_2 ;
V_223 -> V_172 = V_199 ;
F_52 ( & V_223 -> V_134 ) ;
F_56 ( V_12 -> V_133 ) ;
F_8 ( V_2 -> V_17 , L_36 , V_12 -> V_133 ) ;
V_174 = F_33 ( V_7 , false ) ;
if ( V_174 < 0 )
goto V_242;
F_49 ( V_173 , V_7 ) ;
F_55 ( V_17 , L_37 , V_237 ) ;
V_174 = F_75 ( V_7 ) ;
if ( V_174 < 0 )
goto V_243;
return 0 ;
V_243:
V_242:
V_238:
F_76 ( & V_7 -> V_228 ) ;
F_70 ( V_7 ) ;
return V_174 ;
}
static bool F_77 ( struct V_13 * V_31 , void * V_127 )
{
struct V_244 * V_245 = V_127 ;
struct V_19 * V_17 ;
struct V_229 * V_230 ;
if ( ! F_78 ( V_31 ) )
return false ;
if ( ! V_245 )
return false ;
V_17 = V_245 -> V_2 -> V_17 ;
V_230 = V_17 -> V_231 ;
return V_245 -> V_116 == V_31 -> V_23 &&
V_230 -> V_246 == V_31 -> V_19 -> V_17 ;
}
static void F_79 ( struct V_111 * V_7 )
{
F_34 ( V_7 ) ;
F_76 ( & V_7 -> V_228 ) ;
F_80 ( V_7 ) ;
F_70 ( V_7 ) ;
}
static int F_81 ( struct V_211 * V_212 )
{
struct V_19 * V_17 = & V_212 -> V_17 ;
int V_174 ;
struct V_247 * V_248 ;
struct V_1 * V_2 ;
T_10 V_249 ;
struct V_13 * V_31 ;
struct V_244 V_245 ;
V_248 = F_82 ( V_212 , V_250 , 0 ) ;
if ( ! V_248 )
return - V_34 ;
V_2 = F_83 ( sizeof( * V_2 ) , V_251 ) ;
if ( ! V_2 )
return - V_145 ;
F_84 ( & V_2 -> V_29 ) ;
V_2 -> V_4 = F_85 ( V_248 -> V_252 , F_86 ( V_248 ) ) ;
if ( ! V_2 -> V_4 ) {
V_174 = - V_145 ;
goto V_253;
}
F_87 ( L_38 , V_248 , V_2 -> V_4 ) ;
F_88 () ;
V_2 -> V_17 = V_17 ;
F_89 ( V_212 , V_2 ) ;
V_245 . V_2 = V_2 ;
F_90 ( V_249 ) ;
F_91 ( V_254 , V_249 ) ;
F_91 ( V_255 , V_249 ) ;
V_245 . V_116 = V_39 ;
V_31 = F_92 ( V_249 , F_77 , & V_245 ) ;
if ( ! V_31 ) {
V_174 = - V_217 ;
goto V_256;
}
V_2 -> V_200 = 255 ;
V_174 = F_71 ( V_2 , F_30 ( V_31 ) ) ;
if ( V_174 < 0 )
goto V_257;
return 0 ;
V_257:
F_93 ( V_31 ) ;
V_256:
F_94 () ;
F_95 ( V_2 -> V_4 ) ;
V_253:
F_96 ( V_2 ) ;
F_10 ( V_17 , L_39 ) ;
return V_174 ;
}
static int F_97 ( struct V_211 * V_17 )
{
struct V_1 * V_2 = F_59 ( V_17 ) ;
struct V_111 * V_7 = V_2 -> V_7 ;
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_13 * V_31 ;
V_31 = & V_10 -> V_11 -> V_13 ;
F_79 ( V_7 ) ;
F_93 ( V_31 ) ;
F_94 () ;
F_95 ( V_2 -> V_4 ) ;
F_96 ( V_2 ) ;
return 0 ;
}
static int T_11 F_98 ( void )
{
#ifndef F_99
char * V_258 , * V_259 = NULL ;
if ( F_100 ( L_40 , & V_259 ) )
return - V_260 ;
if ( ! V_259 || ! * V_259 )
return 0 ;
while ( ( V_258 = F_101 ( & V_259 , L_41 ) ) != NULL ) {
if ( ! * V_258 )
continue;
if ( ! strncmp ( V_258 , L_42 , 4 ) )
V_178 = F_102 ( V_258 + 4 , NULL , 0 ) ;
else
V_237 = V_258 ;
}
#endif
return 0 ;
}
static int T_11 F_103 ( void )
{
int V_174 = F_98 () ;
if ( V_174 < 0 )
return V_174 ;
V_174 = F_104 ( & V_261 ) ;
return V_174 ;
}
static void T_12 F_105 ( void )
{
F_106 ( & V_261 ) ;
}
