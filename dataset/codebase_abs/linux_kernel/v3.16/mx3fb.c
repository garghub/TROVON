static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( V_2 -> V_6 . V_7 != V_8 )
V_5 = 0 ;
if ( V_2 -> V_6 . V_9 != V_8 )
V_5 = 0 ;
V_4 -> V_10 = ( V_4 -> V_10 & ~ 0xFF ) | V_5 ;
F_5 ( V_4 , V_4 -> V_10 ) ;
return 0 ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_11 V_6 ;
struct V_1 * V_2 ;
if ( V_4 -> V_2 )
return;
memset ( & V_6 , 0 , sizeof( struct V_11 ) ) ;
V_6 . V_12 = 0xff ;
V_6 . type = V_13 ;
F_5 ( V_4 , V_4 -> V_10 ) ;
V_2 = F_7 ( L_1 , V_4 -> V_14 , V_4 ,
& V_15 , & V_6 ) ;
if ( F_8 ( V_2 ) ) {
F_9 ( V_4 -> V_14 , L_2 ,
F_10 ( V_2 ) ) ;
return;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_6 . V_7 = V_8 ;
V_2 -> V_6 . V_9 = V_8 ;
V_2 -> V_6 . V_5 = F_1 ( V_2 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 )
F_12 ( V_4 -> V_2 ) ;
}
static T_1 F_13 ( struct V_3 * V_16 , unsigned long V_17 )
{
return F_14 ( V_16 -> V_18 + V_17 ) ;
}
static void F_15 ( struct V_3 * V_16 , T_1 V_19 , unsigned long V_17 )
{
F_16 ( V_19 , V_16 -> V_18 + V_17 ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_3 * V_16 = V_21 -> V_16 ;
T_2 V_17 ;
V_17 = F_13 ( V_16 , V_22 ) ;
F_15 ( V_16 , V_17 | V_23 , V_22 ) ;
}
static T_2 F_18 ( struct V_20 * V_21 )
{
struct V_3 * V_16 = V_21 -> V_16 ;
T_2 V_17 ;
V_17 = F_13 ( V_16 , V_22 ) ;
F_15 ( V_16 , V_17 & ~ V_23 , V_22 ) ;
return V_17 & V_23 ;
}
static void F_19 ( struct V_20 * V_24 )
{
struct V_3 * V_16 = V_24 -> V_16 ;
struct V_25 * V_26 = V_24 -> V_25 ;
struct V_27 * V_27 = & V_26 -> V_27 ;
unsigned long V_28 ;
T_3 V_29 ;
if ( V_24 -> V_30 )
F_20 ( V_16 -> V_14 , L_3 , V_24 ,
F_21 ( V_24 -> V_30 ) , F_21 ( V_24 -> V_30 ) -> V_31 ) ;
else
F_20 ( V_16 -> V_14 , L_4 , V_24 ) ;
if ( V_24 -> V_29 < 0 ) {
V_24 -> V_30 = F_22 ( V_27 ,
& V_24 -> V_31 [ 0 ] , 1 , V_32 , V_33 ) ;
if ( ! V_24 -> V_30 ) {
F_9 ( V_16 -> V_14 , L_5 ,
V_27 -> V_34 ) ;
return;
}
V_24 -> V_30 -> V_35 = V_24 -> V_30 ;
V_24 -> V_30 -> V_36 = V_37 ;
V_29 = V_24 -> V_30 -> V_38 ( V_24 -> V_30 ) ;
F_20 ( V_16 -> V_14 , L_6 , __LINE__ ,
V_24 -> V_30 , V_29 , F_23 ( & V_26 -> V_39 ) ? '-' : '+' ) ;
} else {
if ( ! V_24 -> V_30 || ! V_24 -> V_30 -> V_38 ) {
F_9 ( V_16 -> V_14 , L_7 ,
V_27 -> V_34 ) ;
return;
}
F_24 ( V_27 ) ;
V_29 = V_24 -> V_29 ;
F_20 ( V_16 -> V_14 , L_8 , __LINE__ ,
V_24 -> V_30 , V_29 , F_23 ( & V_26 -> V_39 ) ? '-' : '+' ) ;
}
if ( V_29 >= 0 ) {
F_25 ( & V_16 -> V_40 , V_28 ) ;
F_17 ( V_24 ) ;
V_24 -> V_29 = V_29 ;
F_26 ( & V_16 -> V_40 , V_28 ) ;
}
F_27 ( 2 ) ;
}
static void F_28 ( struct V_20 * V_24 )
{
struct V_3 * V_16 = V_24 -> V_16 ;
T_2 V_41 ;
unsigned long V_28 ;
if ( V_24 -> V_30 == NULL )
return;
F_25 ( & V_16 -> V_40 , V_28 ) ;
V_41 = F_18 ( V_24 ) ;
F_26 ( & V_16 -> V_40 , V_28 ) ;
V_24 -> V_30 -> V_42 -> V_43 -> V_44 ( V_24 -> V_30 -> V_42 ,
V_45 , 0 ) ;
V_24 -> V_30 = NULL ;
V_24 -> V_29 = - V_46 ;
}
static int F_29 ( struct V_3 * V_16 , enum V_47 V_48 ,
T_4 V_49 , T_4 V_50 )
{
if ( V_48 != V_51 )
return - V_46 ;
V_49 += V_16 -> V_52 ;
V_50 += V_16 -> V_53 ;
F_15 ( V_16 , ( V_49 << 16 ) | V_50 , V_54 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_16 , enum V_55 V_56 ,
T_2 V_57 ,
T_5 V_58 , T_5 V_59 ,
T_5 V_52 , T_5 V_60 ,
T_5 V_61 , T_5 V_53 ,
T_5 V_62 , T_5 V_63 ,
struct V_64 V_65 )
{
unsigned long V_66 ;
T_2 V_17 ;
T_2 V_67 ;
T_2 div ;
struct V_68 * V_69 ;
const struct V_70 * V_71 ;
F_20 ( V_16 -> V_14 , L_9 , V_58 , V_59 ) ;
if ( V_62 == 0 || V_60 == 0 )
return - V_46 ;
V_17 = ( ( T_2 ) ( V_60 - 1 ) << 26 ) |
( ( T_2 ) ( V_58 + V_52 + V_61 - 1 ) << 16 ) ;
F_15 ( V_16 , V_17 , V_72 ) ;
#ifdef F_31
F_32 ( V_73 L_10 , V_17 ) ;
#endif
V_17 = ( ( T_2 ) ( V_62 - 1 ) << 26 ) | V_74 |
( ( T_2 ) ( V_59 + V_53 + V_63 - 1 ) << 16 ) ;
F_15 ( V_16 , V_17 , V_75 ) ;
#ifdef F_31
F_32 ( V_73 L_11 , V_17 ) ;
#endif
V_16 -> V_52 = V_52 ;
V_16 -> V_53 = V_53 ;
switch ( V_56 ) {
case V_76 :
F_15 ( V_16 , 0x00FD0102L , V_77 ) ;
F_15 ( V_16 , 0x00F500F4L , V_78 ) ;
F_15 ( V_16 , V_79 | V_80 , V_22 ) ;
break;
case V_81 :
F_15 ( V_16 , V_80 , V_22 ) ;
break;
default:
return - V_46 ;
}
V_69 = F_33 ( V_16 -> V_14 , NULL ) ;
if ( ! F_8 ( V_69 ) ) {
div = F_34 ( V_69 ) * 16 / V_57 ;
F_35 ( V_69 ) ;
} else {
div = 0 ;
}
if ( div < 0x40 ) {
F_20 ( V_16 -> V_14 ,
L_12 ) ;
div = 0x40 ;
}
F_20 ( V_16 -> V_14 , L_13 ,
V_57 , div >> 4 , ( div & 7 ) * 125 ) ;
F_25 ( & V_16 -> V_40 , V_66 ) ;
F_15 ( V_16 , ( ( ( div / 8 ) - 1 ) << 22 ) | div , V_82 ) ;
V_67 = F_13 ( V_16 , V_83 ) & 0x78FFFFFF ;
V_67 |= V_65 . V_84 << V_85 |
V_65 . V_86 << V_87 |
V_65 . V_88 << V_89 ;
F_15 ( V_16 , V_67 , V_83 ) ;
V_67 = F_13 ( V_16 , V_90 ) & 0xE0FFFFFF ;
V_67 |= V_65 . V_91 << V_92 |
V_65 . V_93 << V_94 |
V_65 . V_95 << V_96 |
V_65 . V_97 << V_98 |
V_65 . V_99 << V_100 ;
F_15 ( V_16 , V_67 , V_90 ) ;
V_71 = & V_101 [ V_16 -> V_102 ] ;
F_15 ( V_16 , V_71 -> V_103 , V_104 ) ;
F_15 ( V_16 , V_71 -> V_105 , V_106 ) ;
F_15 ( V_16 , V_71 -> V_107 , V_108 ) ;
F_26 ( & V_16 -> V_40 , V_66 ) ;
F_20 ( V_16 -> V_14 , L_14 ,
F_13 ( V_16 , V_83 ) ) ;
F_20 ( V_16 -> V_14 , L_15 ,
F_13 ( V_16 , V_90 ) ) ;
F_20 ( V_16 -> V_14 , L_16 ,
F_13 ( V_16 , V_82 ) ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_16 , enum V_47 V_48 ,
bool V_109 , T_2 V_110 )
{
T_2 V_17 , V_111 ;
unsigned long V_66 ;
F_25 ( & V_16 -> V_40 , V_66 ) ;
V_111 = F_13 ( V_16 , V_22 ) ;
if ( V_48 == V_51 )
V_111 &= ~ V_112 ;
else
V_111 |= V_112 ;
if ( V_109 ) {
V_17 = F_13 ( V_16 , V_113 ) & 0xFF000000L ;
F_15 ( V_16 , V_17 | ( V_110 & 0x00FFFFFFL ) ,
V_113 ) ;
V_111 |= V_114 ;
} else {
V_111 &= ~ V_114 ;
}
F_15 ( V_16 , V_111 , V_22 ) ;
F_26 ( & V_16 -> V_40 , V_66 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_16 , bool V_109 , T_6 V_115 )
{
T_2 V_17 ;
unsigned long V_66 ;
F_25 ( & V_16 -> V_40 , V_66 ) ;
if ( V_109 ) {
V_17 = F_13 ( V_16 , V_113 ) & 0x00FFFFFFL ;
F_15 ( V_16 , V_17 | ( ( T_2 ) V_115 << 24 ) , V_113 ) ;
V_17 = F_13 ( V_16 , V_22 ) ;
F_15 ( V_16 , V_17 | V_116 , V_22 ) ;
} else {
V_17 = F_13 ( V_16 , V_22 ) ;
F_15 ( V_16 , V_17 & ~ V_116 , V_22 ) ;
}
F_26 ( & V_16 -> V_40 , V_66 ) ;
return 0 ;
}
static T_1 F_3 ( struct V_3 * V_16 )
{
T_1 V_5 ;
V_5 = F_13 ( V_16 , V_117 ) ;
V_5 = ( V_5 >> 16 ) & 0xFF ;
return V_5 ;
}
static void F_5 ( struct V_3 * V_16 , T_6 V_19 )
{
F_20 ( V_16 -> V_14 , L_17 , V_118 , V_19 ) ;
F_15 ( V_16 , 0x03000000UL | V_19 << 16 , V_117 ) ;
return;
}
static T_2 F_38 ( int V_119 )
{
T_2 V_120 = 0 ;
switch ( V_119 ) {
case 24 :
V_120 = V_121 ;
break;
case 32 :
V_120 = V_122 ;
break;
case 16 :
V_120 = V_123 ;
break;
}
return V_120 ;
}
static int F_39 ( struct V_124 * V_21 )
{
struct V_125 * V_126 = & V_21 -> V_126 ;
struct V_127 * V_128 = & V_21 -> V_128 ;
strncpy ( V_126 -> V_129 , L_18 , 8 ) ;
V_126 -> V_130 = V_128 -> V_131 * V_128 -> V_132 / 8 ;
V_126 -> type = V_133 ;
V_126 -> V_134 = V_135 ;
V_126 -> V_136 = V_137 ;
V_126 -> V_138 = 1 ;
V_126 -> V_139 = 1 ;
return 0 ;
}
static void V_37 ( void * V_140 )
{
struct V_141 * V_142 = F_21 ( V_140 ) ;
struct V_27 * V_42 = V_142 -> V_30 . V_42 ;
struct V_25 * V_143 = F_40 ( V_42 ) ;
struct V_3 * V_16 = V_143 -> V_144 ;
struct V_20 * V_24 = V_16 -> V_21 -> V_145 ;
F_20 ( V_16 -> V_14 , L_19 , V_143 -> V_146 ) ;
F_41 ( V_143 -> V_146 ) ;
F_42 ( & V_24 -> V_147 ) ;
}
static bool F_43 ( struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
struct V_127 V_148 = V_24 -> V_149 ;
struct V_127 V_150 = V_21 -> V_128 ;
if ( ( V_21 -> V_128 . V_151 & V_152 ) &&
( V_21 -> V_128 . V_151 & V_153 ) == V_154 )
return true ;
V_148 . V_155 = V_150 . V_155 ;
V_148 . V_156 = V_150 . V_156 ;
return ! ! memcmp ( & V_148 , & V_150 , sizeof( struct V_127 ) ) ;
}
static int F_44 ( struct V_124 * V_21 , bool V_40 )
{
T_1 V_157 , V_158 , V_159 ;
struct V_64 V_160 ;
enum V_55 V_161 = V_81 ;
struct V_20 * V_24 = V_21 -> V_145 ;
struct V_3 * V_16 = V_24 -> V_16 ;
struct V_25 * V_26 = V_24 -> V_25 ;
struct V_162 * V_163 = & V_26 -> V_164 . V_163 ;
struct V_165 * V_31 = V_24 -> V_31 ;
if ( V_24 -> V_30 )
F_28 ( V_24 ) ;
F_39 ( V_21 ) ;
V_157 = V_21 -> V_128 . V_166 * V_21 -> V_126 . V_130 ;
if ( V_157 > V_21 -> V_126 . V_167 ) {
if ( V_21 -> V_126 . V_168 )
F_45 ( V_21 ) ;
if ( F_46 ( V_21 , V_157 , V_40 ) < 0 )
return - V_169 ;
}
F_47 ( & V_31 [ 0 ] , 1 ) ;
F_47 ( & V_31 [ 1 ] , 1 ) ;
F_48 ( & V_31 [ 0 ] ) = V_21 -> V_126 . V_168 ;
F_49 ( & V_31 [ 0 ] , F_50 ( V_21 -> V_170 ) ,
V_21 -> V_126 . V_167 ,
F_51 ( V_21 -> V_170 ) ) ;
if ( V_24 -> V_171 == V_51 ) {
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
if ( V_21 -> V_128 . V_172 & V_173 )
V_160 . V_97 = true ;
if ( V_21 -> V_128 . V_172 & V_174 )
V_160 . V_99 = true ;
if ( V_21 -> V_128 . V_172 & V_175 )
V_160 . V_93 = true ;
if ( V_21 -> V_128 . V_172 & V_176 )
V_160 . V_91 = true ;
if ( V_21 -> V_128 . V_172 & V_177 )
V_160 . V_95 = true ;
if ( V_21 -> V_128 . V_172 & V_178 )
V_160 . V_88 = true ;
if ( V_21 -> V_128 . V_172 & V_179 )
V_160 . V_86 = true ;
if ( V_21 -> V_128 . V_172 & V_180 )
V_161 = V_76 ;
F_20 ( V_21 -> V_43 , L_20 ,
( T_1 ) ( F_52 ( V_21 -> V_128 . V_181 ) * 1000UL ) ) ;
if ( F_30 ( V_16 , V_161 ,
( F_52 ( V_21 -> V_128 . V_181 ) ) * 1000UL ,
V_21 -> V_128 . V_182 , V_21 -> V_128 . V_183 ,
V_21 -> V_128 . V_184 ,
V_21 -> V_128 . V_185 ,
V_21 -> V_128 . V_186 +
V_21 -> V_128 . V_185 ,
V_21 -> V_128 . V_187 ,
V_21 -> V_128 . V_188 ,
V_21 -> V_128 . V_189 +
V_21 -> V_128 . V_188 , V_160 ) != 0 ) {
F_9 ( V_21 -> V_43 ,
L_21 ) ;
return - V_46 ;
}
}
F_29 ( V_16 , V_24 -> V_171 , 0 , 0 ) ;
V_24 -> V_190 = 0 ;
V_163 -> V_191 = F_38 ( V_21 -> V_128 . V_132 ) ;
V_163 -> V_192 = V_21 -> V_128 . V_182 ;
V_163 -> V_193 = V_21 -> V_128 . V_183 ;
V_163 -> V_194 = V_21 -> V_128 . V_131 ;
if ( V_24 -> V_195 == V_8 ) {
F_19 ( V_24 ) ;
V_24 -> V_149 . V_155 = 0 ;
V_24 -> V_149 . V_156 = 0 ;
}
V_158 = V_24 -> V_149 . V_155 ;
V_159 = V_24 -> V_149 . V_156 ;
V_24 -> V_149 = V_21 -> V_128 ;
V_24 -> V_149 . V_155 = V_158 ;
V_24 -> V_149 . V_156 = V_159 ;
return 0 ;
}
static int F_53 ( struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
struct V_3 * V_16 = V_24 -> V_16 ;
struct V_25 * V_26 = V_24 -> V_25 ;
int V_196 ;
F_20 ( V_16 -> V_14 , L_22 , V_118 , F_23 ( & V_26 -> V_39 ) ? '-' : '+' ) ;
F_54 ( & V_24 -> V_197 ) ;
V_196 = F_43 ( V_21 ) ? F_44 ( V_21 , true ) : 0 ;
F_55 ( & V_24 -> V_197 ) ;
return V_196 ;
}
static int F_56 ( struct V_127 * V_128 , struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
T_1 V_198 ;
T_1 V_199 ;
F_20 ( V_21 -> V_43 , L_23 , V_118 ) ;
if ( V_128 -> V_131 < V_128 -> V_182 )
V_128 -> V_131 = V_128 -> V_182 ;
if ( V_128 -> V_166 < V_128 -> V_183 )
V_128 -> V_166 = V_128 -> V_183 ;
if ( ( V_128 -> V_132 != 32 ) && ( V_128 -> V_132 != 24 ) &&
( V_128 -> V_132 != 16 ) )
V_128 -> V_132 = V_200 ;
switch ( V_128 -> V_132 ) {
case 16 :
V_128 -> V_201 . V_202 = 5 ;
V_128 -> V_201 . V_203 = 11 ;
V_128 -> V_201 . V_204 = 0 ;
V_128 -> V_205 . V_202 = 6 ;
V_128 -> V_205 . V_203 = 5 ;
V_128 -> V_205 . V_204 = 0 ;
V_128 -> V_206 . V_202 = 5 ;
V_128 -> V_206 . V_203 = 0 ;
V_128 -> V_206 . V_204 = 0 ;
V_128 -> V_207 . V_202 = 0 ;
V_128 -> V_207 . V_203 = 0 ;
V_128 -> V_207 . V_204 = 0 ;
break;
case 24 :
V_128 -> V_201 . V_202 = 8 ;
V_128 -> V_201 . V_203 = 16 ;
V_128 -> V_201 . V_204 = 0 ;
V_128 -> V_205 . V_202 = 8 ;
V_128 -> V_205 . V_203 = 8 ;
V_128 -> V_205 . V_204 = 0 ;
V_128 -> V_206 . V_202 = 8 ;
V_128 -> V_206 . V_203 = 0 ;
V_128 -> V_206 . V_204 = 0 ;
V_128 -> V_207 . V_202 = 0 ;
V_128 -> V_207 . V_203 = 0 ;
V_128 -> V_207 . V_204 = 0 ;
break;
case 32 :
V_128 -> V_201 . V_202 = 8 ;
V_128 -> V_201 . V_203 = 16 ;
V_128 -> V_201 . V_204 = 0 ;
V_128 -> V_205 . V_202 = 8 ;
V_128 -> V_205 . V_203 = 8 ;
V_128 -> V_205 . V_204 = 0 ;
V_128 -> V_206 . V_202 = 8 ;
V_128 -> V_206 . V_203 = 0 ;
V_128 -> V_206 . V_204 = 0 ;
V_128 -> V_207 . V_202 = 8 ;
V_128 -> V_207 . V_203 = 24 ;
V_128 -> V_207 . V_204 = 0 ;
break;
}
if ( V_128 -> V_181 < 1000 ) {
V_199 = V_128 -> V_182 + V_128 -> V_186 + V_128 -> V_185 +
V_128 -> V_184 ;
V_198 = V_128 -> V_183 + V_128 -> V_189 + V_128 -> V_188 +
V_128 -> V_187 ;
V_128 -> V_181 = ( V_198 * V_199 * 6UL ) / 100UL ;
V_128 -> V_181 = F_57 ( V_128 -> V_181 ) ;
F_20 ( V_21 -> V_43 , L_24 ,
V_128 -> V_181 ) ;
}
V_128 -> V_59 = - 1 ;
V_128 -> V_58 = - 1 ;
V_128 -> V_208 = 0 ;
V_128 -> V_172 |= V_24 -> V_149 . V_172 ;
V_24 -> V_149 . V_172 |= V_128 -> V_172 ;
return 0 ;
}
static T_1 F_58 ( unsigned int V_42 , struct V_209 * V_210 )
{
V_42 &= 0xffff ;
V_42 >>= 16 - V_210 -> V_202 ;
return V_42 << V_210 -> V_203 ;
}
static int F_59 ( unsigned int V_211 , unsigned int V_201 ,
unsigned int V_205 , unsigned int V_206 ,
unsigned int V_212 , struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
T_1 V_213 ;
int V_196 = 1 ;
F_20 ( V_21 -> V_43 , L_25 , V_118 , V_211 ) ;
F_54 ( & V_24 -> V_197 ) ;
if ( V_21 -> V_128 . V_208 )
V_201 = V_205 = V_206 = ( 19595 * V_201 + 38470 * V_205 +
7471 * V_206 ) >> 16 ;
switch ( V_21 -> V_126 . V_136 ) {
case V_137 :
if ( V_211 < 16 ) {
T_1 * V_214 = V_21 -> V_215 ;
V_213 = F_58 ( V_201 , & V_21 -> V_128 . V_201 ) ;
V_213 |= F_58 ( V_205 , & V_21 -> V_128 . V_205 ) ;
V_213 |= F_58 ( V_206 , & V_21 -> V_128 . V_206 ) ;
V_214 [ V_211 ] = V_213 ;
V_196 = 0 ;
}
break;
case V_216 :
case V_217 :
break;
}
F_55 ( & V_24 -> V_197 ) ;
return V_196 ;
}
static void F_60 ( int V_195 , struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
struct V_3 * V_16 = V_24 -> V_16 ;
int V_218 = V_24 -> V_195 ;
V_24 -> V_195 = V_195 ;
if ( V_195 > V_8 && V_218 > V_8 )
return;
switch ( V_195 ) {
case V_219 :
case V_220 :
case V_221 :
case V_222 :
F_5 ( V_16 , 0 ) ;
memset ( ( char * ) V_21 -> V_170 , 0 , V_21 -> V_126 . V_167 ) ;
F_27 ( 25 ) ;
F_28 ( V_24 ) ;
break;
case V_8 :
F_19 ( V_24 ) ;
F_5 ( V_16 , V_16 -> V_10 ) ;
break;
}
}
static int F_61 ( int V_195 , struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
F_20 ( V_21 -> V_43 , L_26 , V_118 ,
V_195 , V_21 -> V_170 , V_21 -> V_126 . V_167 ) ;
if ( V_24 -> V_195 == V_195 )
return 0 ;
F_54 ( & V_24 -> V_197 ) ;
F_60 ( V_195 , V_21 ) ;
F_55 ( & V_24 -> V_197 ) ;
return 0 ;
}
static int F_62 ( struct V_127 * V_128 ,
struct V_124 * V_21 )
{
struct V_20 * V_24 = V_21 -> V_145 ;
T_1 V_223 ;
unsigned long V_224 ;
T_7 V_203 ;
T_3 V_29 ;
struct V_165 * V_31 = V_24 -> V_31 ;
struct V_27 * V_27 = & V_24 -> V_25 -> V_27 ;
struct V_225 * V_30 ;
int V_196 ;
F_20 ( V_21 -> V_43 , L_22 , V_118 ,
F_23 ( & V_24 -> V_25 -> V_39 ) ? '-' : '+' ) ;
if ( V_128 -> V_155 > 0 ) {
F_20 ( V_21 -> V_43 , L_27 ) ;
return - V_46 ;
}
if ( V_24 -> V_149 . V_155 == V_128 -> V_155 &&
V_24 -> V_149 . V_156 == V_128 -> V_156 )
return 0 ;
V_223 = V_128 -> V_156 ;
if ( ! ( V_128 -> V_226 & V_227 ) )
V_223 += V_21 -> V_128 . V_183 ;
if ( V_223 > V_21 -> V_128 . V_166 )
return - V_46 ;
F_54 ( & V_24 -> V_197 ) ;
V_203 = V_128 -> V_156 * V_21 -> V_126 . V_130
+ V_128 -> V_155 * ( V_21 -> V_128 . V_132 / 8 ) ;
V_224 = V_21 -> V_126 . V_168 + V_203 ;
F_20 ( V_21 -> V_43 , L_28 ,
V_24 -> V_190 , V_224 ) ;
F_63 ( & V_24 -> V_147 ) ;
F_64 ( V_24 -> V_25 -> V_146 ) ;
V_196 = F_65 ( & V_24 -> V_147 , V_228 / 10 ) ;
if ( V_196 <= 0 ) {
F_55 ( & V_24 -> V_197 ) ;
F_66 ( V_21 -> V_43 , L_29 , V_196 < 0 ?
L_30 : L_31 ) ;
F_67 ( V_24 -> V_25 -> V_146 ) ;
return V_196 ? : - V_229 ;
}
V_24 -> V_190 = ! V_24 -> V_190 ;
F_48 ( & V_31 [ V_24 -> V_190 ] ) = V_224 ;
F_49 ( & V_31 [ V_24 -> V_190 ] ,
F_50 ( V_21 -> V_170 + V_203 ) , V_21 -> V_126 . V_167 ,
F_51 ( V_21 -> V_170 + V_203 ) ) ;
if ( V_24 -> V_30 )
F_68 ( V_24 -> V_30 ) ;
V_30 = F_22 ( V_27 , V_31 +
V_24 -> V_190 , 1 , V_32 , V_33 ) ;
if ( ! V_30 ) {
F_9 ( V_21 -> V_43 ,
L_32 ) ;
F_55 ( & V_24 -> V_197 ) ;
return - V_230 ;
}
V_30 -> V_35 = V_30 ;
V_30 -> V_36 = V_37 ;
V_29 = V_30 -> V_38 ( V_30 ) ;
F_20 ( V_21 -> V_43 , L_33 , __LINE__ , V_30 , V_29 ) ;
if ( V_29 < 0 ) {
F_9 ( V_21 -> V_43 ,
L_34 ,
V_24 -> V_190 , V_224 ) ;
F_55 ( & V_24 -> V_197 ) ;
return - V_230 ;
}
V_24 -> V_30 = V_30 ;
V_21 -> V_128 . V_155 = V_128 -> V_155 ;
V_21 -> V_128 . V_156 = V_128 -> V_156 ;
if ( V_128 -> V_226 & V_227 )
V_21 -> V_128 . V_226 |= V_227 ;
else
V_21 -> V_128 . V_226 &= ~ V_227 ;
V_24 -> V_149 = V_21 -> V_128 ;
F_55 ( & V_24 -> V_197 ) ;
F_20 ( V_21 -> V_43 , L_35 ) ;
return 0 ;
}
static int F_69 ( struct V_231 * V_232 , T_8 V_233 )
{
struct V_3 * V_16 = F_70 ( V_232 ) ;
struct V_20 * V_24 = V_16 -> V_21 -> V_145 ;
F_71 () ;
F_72 ( V_16 -> V_21 , 1 ) ;
F_73 () ;
if ( V_24 -> V_195 == V_8 ) {
F_28 ( V_24 ) ;
F_5 ( V_16 , 0 ) ;
}
return 0 ;
}
static int F_74 ( struct V_231 * V_232 )
{
struct V_3 * V_16 = F_70 ( V_232 ) ;
struct V_20 * V_24 = V_16 -> V_21 -> V_145 ;
if ( V_24 -> V_195 == V_8 ) {
F_19 ( V_24 ) ;
F_5 ( V_16 , V_16 -> V_10 ) ;
}
F_71 () ;
F_72 ( V_16 -> V_21 , 0 ) ;
F_73 () ;
return 0 ;
}
static int F_46 ( struct V_124 * V_21 , unsigned int V_157 ,
bool V_40 )
{
int V_234 = 0 ;
T_9 V_235 ;
V_21 -> V_170 = F_75 ( V_21 -> V_43 ,
V_157 ,
& V_235 , V_236 | V_237 ) ;
if ( ! V_21 -> V_170 ) {
F_9 ( V_21 -> V_43 , L_36 ,
V_157 ) ;
V_234 = - V_238 ;
goto V_239;
}
if ( V_40 )
F_54 ( & V_21 -> V_240 ) ;
V_21 -> V_126 . V_168 = V_235 ;
V_21 -> V_126 . V_167 = V_157 ;
if ( V_40 )
F_55 ( & V_21 -> V_240 ) ;
F_20 ( V_21 -> V_43 , L_37 ,
( T_2 ) V_21 -> V_126 . V_168 , V_21 -> V_170 , V_21 -> V_126 . V_167 ) ;
V_21 -> V_241 = V_21 -> V_126 . V_167 ;
memset ( ( char * ) V_21 -> V_170 , 0 , V_21 -> V_126 . V_167 ) ;
return 0 ;
V_239:
V_21 -> V_126 . V_167 = 0 ;
V_21 -> V_126 . V_168 = 0 ;
V_21 -> V_170 = NULL ;
return V_234 ;
}
static int F_45 ( struct V_124 * V_21 )
{
F_76 ( V_21 -> V_43 , V_21 -> V_126 . V_167 ,
V_21 -> V_170 , V_21 -> V_126 . V_168 ) ;
V_21 -> V_170 = NULL ;
F_54 ( & V_21 -> V_240 ) ;
V_21 -> V_126 . V_168 = 0 ;
V_21 -> V_126 . V_167 = 0 ;
F_55 ( & V_21 -> V_240 ) ;
return 0 ;
}
static struct V_124 * F_77 ( struct V_43 * V_14 , struct V_242 * V_243 )
{
struct V_124 * V_21 ;
struct V_20 * V_244 ;
int V_196 ;
V_21 = F_78 ( sizeof( struct V_20 ) , V_14 ) ;
if ( ! V_21 )
return NULL ;
V_244 = V_21 -> V_145 ;
V_244 -> V_29 = - V_46 ;
V_244 -> V_190 = 0 ;
V_21 -> V_128 . V_151 = V_154 ;
V_21 -> V_245 = V_243 ;
V_21 -> V_28 = V_246 ;
V_21 -> V_215 = V_244 -> V_215 ;
F_79 ( & V_244 -> V_197 ) ;
V_196 = F_80 ( & V_21 -> V_247 , 16 , 0 ) ;
if ( V_196 < 0 ) {
F_81 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
static int F_82 ( struct V_3 * V_16 , struct V_25 * V_26 )
{
struct V_43 * V_14 = V_16 -> V_14 ;
struct V_248 * V_249 = F_83 ( V_14 ) ;
const char * V_250 = V_249 -> V_250 ;
unsigned int V_251 ;
struct V_124 * V_21 ;
struct V_20 * V_244 ;
const struct V_252 * V_161 ;
int V_196 , V_253 ;
if ( V_249 -> V_102 >= F_84 ( V_101 ) ) {
F_9 ( V_14 , L_38 ,
V_249 -> V_102 ) ;
return - V_46 ;
}
V_26 -> V_144 = V_16 ;
V_251 = V_26 -> V_146 ;
if ( V_26 -> V_27 . V_34 != V_51 )
return - V_46 ;
V_21 = F_77 ( V_14 , & V_254 ) ;
if ( ! V_21 )
return - V_169 ;
if ( ! V_255 )
V_255 = V_250 ;
if ( ! V_255 ) {
V_196 = - V_46 ;
goto V_256;
}
if ( V_249 -> V_161 && V_249 -> V_253 ) {
V_161 = V_249 -> V_161 ;
V_253 = V_249 -> V_253 ;
} else {
V_161 = V_257 ;
V_253 = F_84 ( V_257 ) ;
}
if ( ! F_85 ( & V_21 -> V_128 , V_21 , V_255 , V_161 ,
V_253 , NULL , V_200 ) ) {
V_196 = - V_238 ;
goto V_256;
}
F_86 ( V_161 , V_253 , & V_21 -> V_258 ) ;
V_21 -> V_128 . V_166 = V_21 -> V_128 . V_183 * 2 ;
V_16 -> V_21 = V_21 ;
F_15 ( V_16 , 0x00100010L , V_259 ) ;
F_5 ( V_16 , 255 ) ;
F_37 ( V_16 , true , 0xFF ) ;
F_36 ( V_16 , V_51 , false , 0 ) ;
V_244 = V_21 -> V_145 ;
V_244 -> V_25 = V_26 ;
V_244 -> V_171 = V_26 -> V_27 . V_34 ;
V_244 -> V_16 = V_16 ;
V_244 -> V_195 = V_222 ;
V_16 -> V_102 = V_249 -> V_102 ;
F_63 ( & V_244 -> V_147 ) ;
F_67 ( V_26 -> V_146 ) ;
F_20 ( V_16 -> V_14 , L_39 , V_26 -> V_146 ) ;
V_196 = F_44 ( V_21 , false ) ;
if ( V_196 < 0 )
goto V_260;
F_60 ( V_8 , V_21 ) ;
F_66 ( V_14 , L_40 , V_255 ) ;
V_196 = F_87 ( V_21 ) ;
if ( V_196 < 0 )
goto V_261;
return 0 ;
V_261:
V_260:
V_256:
F_88 ( & V_21 -> V_247 ) ;
F_81 ( V_21 ) ;
return V_196 ;
}
static bool F_89 ( struct V_27 * V_42 , void * V_140 )
{
struct V_262 * V_263 = V_140 ;
struct V_43 * V_14 ;
struct V_248 * V_249 ;
if ( ! F_90 ( V_42 ) )
return false ;
if ( ! V_263 )
return false ;
V_14 = V_263 -> V_16 -> V_14 ;
V_249 = F_83 ( V_14 ) ;
return V_263 -> V_129 == V_42 -> V_34 &&
V_249 -> V_264 == V_42 -> V_43 -> V_14 ;
}
static void F_91 ( struct V_124 * V_21 )
{
F_45 ( V_21 ) ;
F_88 ( & V_21 -> V_247 ) ;
F_92 ( V_21 ) ;
F_81 ( V_21 ) ;
}
static int F_93 ( struct V_231 * V_232 )
{
struct V_43 * V_14 = & V_232 -> V_14 ;
int V_196 ;
struct V_265 * V_266 ;
struct V_3 * V_16 ;
T_10 V_267 ;
struct V_27 * V_42 ;
struct V_262 V_263 ;
V_266 = F_94 ( V_232 , V_268 , 0 ) ;
if ( ! V_266 )
return - V_46 ;
V_16 = F_95 ( & V_232 -> V_14 , sizeof( * V_16 ) , V_237 ) ;
if ( ! V_16 )
return - V_169 ;
F_96 ( & V_16 -> V_40 ) ;
V_16 -> V_18 = F_97 ( V_266 -> V_269 , F_98 ( V_266 ) ) ;
if ( ! V_16 -> V_18 ) {
V_196 = - V_169 ;
goto V_270;
}
F_99 ( L_41 , V_266 , V_16 -> V_18 ) ;
F_100 () ;
V_16 -> V_14 = V_14 ;
F_101 ( V_232 , V_16 ) ;
V_263 . V_16 = V_16 ;
F_102 ( V_267 ) ;
F_103 ( V_271 , V_267 ) ;
F_103 ( V_272 , V_267 ) ;
V_263 . V_129 = V_51 ;
V_42 = F_104 ( V_267 , F_89 , & V_263 ) ;
if ( ! V_42 ) {
V_196 = - V_238 ;
goto V_273;
}
V_16 -> V_10 = 255 ;
V_196 = F_82 ( V_16 , F_40 ( V_42 ) ) ;
if ( V_196 < 0 )
goto V_274;
F_6 ( V_16 ) ;
return 0 ;
V_274:
F_105 ( V_42 ) ;
V_273:
F_106 () ;
F_107 ( V_16 -> V_18 ) ;
V_270:
F_9 ( V_14 , L_42 ) ;
return V_196 ;
}
static int F_108 ( struct V_231 * V_14 )
{
struct V_3 * V_16 = F_70 ( V_14 ) ;
struct V_124 * V_21 = V_16 -> V_21 ;
struct V_20 * V_24 = V_21 -> V_145 ;
struct V_27 * V_42 ;
V_42 = & V_24 -> V_25 -> V_27 ;
F_91 ( V_21 ) ;
F_11 ( V_16 ) ;
F_105 ( V_42 ) ;
F_106 () ;
F_107 ( V_16 -> V_18 ) ;
return 0 ;
}
static int T_11 F_109 ( void )
{
#ifndef F_110
char * V_275 , * V_276 = NULL ;
if ( F_111 ( L_43 , & V_276 ) )
return - V_277 ;
if ( ! V_276 || ! * V_276 )
return 0 ;
while ( ( V_275 = F_112 ( & V_276 , L_44 ) ) != NULL ) {
if ( ! * V_275 )
continue;
if ( ! strncmp ( V_275 , L_45 , 4 ) )
V_200 = F_113 ( V_275 + 4 , NULL , 0 ) ;
else
V_255 = V_275 ;
}
#endif
return 0 ;
}
static int T_11 F_114 ( void )
{
int V_196 = F_109 () ;
if ( V_196 < 0 )
return V_196 ;
V_196 = F_115 ( & V_278 ) ;
return V_196 ;
}
static void T_12 F_116 ( void )
{
F_117 ( & V_278 ) ;
}
