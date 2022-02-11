static inline bool F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
return true ;
default:
return false ;
}
}
static inline T_1 F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_3 ( V_6 -> V_8 + V_7 ) ;
}
static inline void F_4 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 V_9 )
{
F_5 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static inline void F_6 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 V_9 , T_1 V_10 )
{
T_1 V_11 = F_2 ( V_6 , V_7 ) ;
V_9 = ( V_9 & V_10 ) | ( V_11 & ~ V_10 ) ;
F_5 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static inline T_1 F_7 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_3 ( V_6 -> V_12 + V_7 ) ;
}
static inline void F_8 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 V_9 )
{
F_5 ( V_9 , V_6 -> V_12 + V_7 ) ;
}
static inline void F_9 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_9 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_6 , V_7 ) ;
V_9 = ( V_9 & V_10 ) | ( V_11 & ~ V_10 ) ;
F_5 ( V_9 , V_6 -> V_12 + V_7 ) ;
}
static void F_10 ( struct V_13 * V_14 )
{
#define F_11 ( V_7 ) \
do { \
DRM_DEBUG_KMS(#reg_id " = %08x\n", \
(u32)readl(ctx->mixer_res.mixer_regs + reg_id)); \
} while (0)
F_11 ( V_15 ) ;
F_11 ( V_16 ) ;
F_11 ( V_17 ) ;
F_11 ( V_18 ) ;
F_11 ( V_19 ) ;
F_11 ( V_20 ) ;
F_11 ( V_21 ) ;
F_11 ( V_22 ) ;
F_11 ( V_23 ) ;
F_11 ( V_24 ) ;
F_11 ( V_25 ) ;
F_11 ( V_26 ) ;
F_11 ( V_27 ) ;
F_11 ( V_28 ) ;
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
F_11 ( V_31 ) ;
F_11 ( V_32 ) ;
#undef F_11
}
static void F_12 ( struct V_13 * V_14 )
{
#define F_11 ( V_7 ) \
do { \
DRM_DEBUG_KMS(#reg_id " = %08x\n", \
(u32) readl(ctx->mixer_res.vp_regs + reg_id)); \
} while (0)
F_11 ( V_33 ) ;
F_11 ( V_34 ) ;
F_11 ( V_35 ) ;
F_11 ( V_36 ) ;
F_11 ( V_37 ) ;
F_11 ( V_38 ) ;
F_11 ( V_39 ) ;
F_11 ( V_40 ) ;
F_11 ( V_41 ) ;
F_11 ( V_42 ) ;
F_11 ( V_43 ) ;
F_11 ( V_44 ) ;
F_11 ( V_45 ) ;
F_11 ( V_46 ) ;
F_11 ( V_47 ) ;
F_11 ( V_48 ) ;
F_11 ( V_49 ) ;
F_11 ( V_50 ) ;
F_11 ( V_51 ) ;
F_11 ( V_52 ) ;
F_11 ( V_53 ) ;
F_11 ( V_54 ) ;
F_11 ( V_55 ) ;
#undef F_11
}
static inline void F_13 ( struct V_5 * V_6 ,
int V_7 , const T_2 * V_56 , unsigned int V_57 )
{
F_14 ( V_57 & 3 ) ;
for (; V_57 ; V_57 -= 4 , V_7 += 4 , V_56 += 4 ) {
T_1 V_9 = ( V_56 [ 0 ] << 24 ) | ( V_56 [ 1 ] << 16 ) |
( V_56 [ 2 ] << 8 ) | V_56 [ 3 ] ;
F_4 ( V_6 , V_7 , V_9 ) ;
}
}
static void F_15 ( struct V_5 * V_6 )
{
F_13 ( V_6 , V_58 ,
V_59 , sizeof( V_59 ) ) ;
F_13 ( V_6 , V_60 ,
V_61 , sizeof( V_61 ) ) ;
F_13 ( V_6 , V_62 ,
V_63 , sizeof( V_63 ) ) ;
}
static void F_16 ( struct V_13 * V_14 , unsigned int V_64 ,
bool V_65 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 ;
V_9 = V_67 ;
if ( V_65 ) {
V_9 |= V_68 ;
V_9 |= V_69 ;
}
F_9 ( V_6 , F_17 ( V_64 ) ,
V_9 , V_70 ) ;
}
static void F_18 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 ;
V_9 = 0 ;
F_8 ( V_6 , V_20 , V_9 ) ;
}
static void F_19 ( struct V_13 * V_14 , bool V_71 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_15 , V_71 ?
V_72 : 0 , V_72 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) )
F_4 ( V_6 , V_35 , V_71 ?
V_75 : 0 ) ;
}
static void F_21 ( struct V_13 * V_14 , unsigned int V_76 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 ;
V_9 = F_20 ( V_77 , & V_14 -> V_74 ) ?
V_78 : V_79 ;
if ( V_14 -> V_80 != V_81 ) {
if ( V_76 <= 480 )
V_9 |= V_82 | V_83 ;
else if ( V_76 <= 576 )
V_9 |= V_84 | V_83 ;
else if ( V_76 <= 720 )
V_9 |= V_85 | V_86 ;
else if ( V_76 <= 1080 )
V_9 |= V_87 | V_86 ;
else
V_9 |= V_85 | V_86 ;
}
F_9 ( V_6 , V_16 , V_9 , V_88 ) ;
}
static void F_22 ( struct V_13 * V_14 , unsigned int V_76 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 ;
switch ( V_76 ) {
case 480 :
case 576 :
V_9 = V_89 ;
break;
case 720 :
case 1080 :
default:
V_9 = V_90 ;
F_8 ( V_6 , V_91 ,
F_23 ( 0.184 , 0.614 , 0.063 ) |
V_92 ) ;
F_8 ( V_6 , V_93 ,
F_23 ( - 0.102 , - 0.338 , 0.440 ) ) ;
F_8 ( V_6 , V_94 ,
F_23 ( 0.440 , - 0.399 , - 0.040 ) ) ;
break;
}
F_9 ( V_6 , V_16 , V_9 , V_95 ) ;
}
static void F_24 ( struct V_13 * V_14 , unsigned int V_64 ,
unsigned int V_96 , bool V_71 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 = V_71 ? ~ 0 : 0 ;
switch ( V_64 ) {
case 0 :
F_9 ( V_6 , V_16 , V_9 , V_97 ) ;
F_9 ( V_6 , V_19 ,
F_25 ( V_96 ) ,
V_98 ) ;
break;
case 1 :
F_9 ( V_6 , V_16 , V_9 , V_99 ) ;
F_9 ( V_6 , V_19 ,
F_26 ( V_96 ) ,
V_100 ) ;
break;
case V_101 :
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_6 ( V_6 , V_33 , V_9 , V_102 ) ;
F_9 ( V_6 , V_16 , V_9 ,
V_103 ) ;
F_9 ( V_6 , V_19 ,
F_27 ( V_96 ) ,
V_104 ) ;
}
break;
}
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_15 , ~ 0 , V_105 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_106 = 20 ;
F_9 ( V_6 , V_15 , 0 , V_105 ) ;
while ( ! ( F_7 ( V_6 , V_15 ) & V_107 ) &&
-- V_106 )
F_30 ( 10000 , 12000 ) ;
}
static void F_31 ( struct V_13 * V_14 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 =
F_32 ( V_109 -> V_112 . V_111 ) ;
struct V_113 * V_114 = & V_111 -> V_112 . V_115 -> V_111 -> V_116 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_117 * V_118 = V_111 -> V_112 . V_118 ;
unsigned int V_96 = V_111 -> V_112 . V_119 + 1 ;
unsigned long V_74 ;
T_3 V_120 [ 2 ] , V_121 [ 2 ] ;
bool V_122 = false ;
bool V_123 = false ;
T_1 V_9 ;
switch ( V_118 -> V_124 -> V_124 ) {
case V_125 :
V_123 = false ;
break;
case V_126 :
V_123 = true ;
break;
default:
F_33 ( L_1 ,
V_118 -> V_124 -> V_124 ) ;
return;
}
V_120 [ 0 ] = F_34 ( V_118 , 0 ) ;
V_121 [ 0 ] = F_34 ( V_118 , 1 ) ;
if ( V_114 -> V_74 & V_127 ) {
F_35 ( V_77 , & V_14 -> V_74 ) ;
if ( V_122 ) {
V_120 [ 1 ] = V_120 [ 0 ] + 0x40 ;
V_121 [ 1 ] = V_121 [ 0 ] + 0x40 ;
} else {
V_120 [ 1 ] = V_120 [ 0 ] + V_118 -> V_128 [ 0 ] ;
V_121 [ 1 ] = V_121 [ 0 ] + V_118 -> V_128 [ 0 ] ;
}
} else {
F_36 ( V_77 , & V_14 -> V_74 ) ;
V_120 [ 1 ] = 0 ;
V_121 [ 1 ] = 0 ;
}
F_37 ( & V_6 -> V_129 , V_74 ) ;
V_9 = ( F_20 ( V_77 , & V_14 -> V_74 ) ? ~ 0 : 0 ) ;
F_6 ( V_6 , V_37 , V_9 , V_130 ) ;
V_9 = ( V_123 ? V_131 : V_132 ) ;
V_9 |= ( V_122 ? V_133 : V_134 ) ;
F_6 ( V_6 , V_37 , V_9 , V_135 ) ;
F_4 ( V_6 , V_38 , F_38 ( V_118 -> V_128 [ 0 ] ) |
F_39 ( V_118 -> V_76 ) ) ;
F_4 ( V_6 , V_39 , F_38 ( V_118 -> V_128 [ 0 ] ) |
F_39 ( V_118 -> V_76 / 2 ) ) ;
F_4 ( V_6 , V_48 , V_111 -> V_136 . V_137 ) ;
F_4 ( V_6 , V_49 , V_111 -> V_136 . V_138 ) ;
F_4 ( V_6 , V_46 ,
F_40 ( V_111 -> V_136 . V_139 ) ) ;
F_4 ( V_6 , V_47 , V_111 -> V_136 . V_140 ) ;
F_4 ( V_6 , V_52 , V_111 -> V_115 . V_137 ) ;
F_4 ( V_6 , V_50 , V_111 -> V_115 . V_139 ) ;
if ( F_20 ( V_77 , & V_14 -> V_74 ) ) {
F_4 ( V_6 , V_53 , V_111 -> V_115 . V_138 / 2 ) ;
F_4 ( V_6 , V_51 , V_111 -> V_115 . V_140 / 2 ) ;
} else {
F_4 ( V_6 , V_53 , V_111 -> V_115 . V_138 ) ;
F_4 ( V_6 , V_51 , V_111 -> V_115 . V_140 ) ;
}
F_4 ( V_6 , V_54 , V_111 -> V_141 ) ;
F_4 ( V_6 , V_55 , V_111 -> V_142 ) ;
F_4 ( V_6 , V_45 , V_143 ) ;
F_4 ( V_6 , V_41 , V_120 [ 0 ] ) ;
F_4 ( V_6 , V_42 , V_120 [ 1 ] ) ;
F_4 ( V_6 , V_43 , V_121 [ 0 ] ) ;
F_4 ( V_6 , V_44 , V_121 [ 1 ] ) ;
F_21 ( V_14 , V_114 -> V_144 ) ;
F_22 ( V_14 , V_114 -> V_144 ) ;
F_24 ( V_14 , V_109 -> V_145 , V_96 , true ) ;
F_18 ( V_14 ) ;
F_28 ( V_14 ) ;
F_41 ( & V_6 -> V_129 , V_74 ) ;
F_10 ( V_14 ) ;
F_12 ( V_14 ) ;
}
static void F_42 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_16 , ~ 0 , V_146 ) ;
}
static void F_43 ( struct V_13 * V_14 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 =
F_32 ( V_109 -> V_112 . V_111 ) ;
struct V_113 * V_114 = & V_111 -> V_112 . V_115 -> V_111 -> V_116 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_117 * V_118 = V_111 -> V_112 . V_118 ;
unsigned int V_96 = V_111 -> V_112 . V_119 + 1 ;
unsigned long V_74 ;
unsigned int V_64 = V_109 -> V_145 ;
unsigned int V_147 = 0 , V_148 = 0 ;
unsigned int V_149 , V_150 , V_151 , V_152 ;
T_3 V_153 ;
unsigned int V_154 ;
T_1 V_9 ;
switch ( V_118 -> V_124 -> V_124 ) {
case V_155 :
case V_4 :
V_154 = V_156 ;
break;
case V_157 :
case V_3 :
V_154 = V_158 ;
break;
case V_159 :
V_154 = V_160 ;
break;
case V_161 :
case V_2 :
V_154 = V_162 ;
break;
default:
F_44 ( L_2 ) ;
return;
}
V_147 = V_111 -> V_141 == ( 1 << 15 ) ;
V_148 = V_111 -> V_142 == ( 1 << 15 ) ;
V_151 = V_111 -> V_115 . V_139 ;
V_152 = V_111 -> V_115 . V_140 ;
V_153 = F_34 ( V_118 , 0 )
+ ( V_111 -> V_136 . V_139 * V_118 -> V_124 -> V_163 [ 0 ] )
+ ( V_111 -> V_136 . V_140 * V_118 -> V_128 [ 0 ] ) ;
V_149 = 0 ;
V_150 = 0 ;
if ( V_114 -> V_74 & V_127 )
F_35 ( V_77 , & V_14 -> V_74 ) ;
else
F_36 ( V_77 , & V_14 -> V_74 ) ;
F_37 ( & V_6 -> V_129 , V_74 ) ;
F_9 ( V_6 , F_17 ( V_64 ) ,
F_45 ( V_154 ) , V_164 ) ;
F_8 ( V_6 , F_46 ( V_64 ) ,
V_118 -> V_128 [ 0 ] / V_118 -> V_124 -> V_163 [ 0 ] ) ;
if ( V_14 -> V_80 == V_81 &&
V_64 == V_165 ) {
V_9 = F_47 ( V_114 -> V_144 ) ;
V_9 |= F_48 ( V_114 -> V_166 ) ;
F_8 ( V_6 , V_167 , V_9 ) ;
}
V_9 = F_49 ( V_111 -> V_136 . V_137 ) ;
V_9 |= F_50 ( V_111 -> V_136 . V_138 ) ;
V_9 |= F_51 ( V_147 ) ;
V_9 |= F_52 ( V_148 ) ;
F_8 ( V_6 , F_53 ( V_64 ) , V_9 ) ;
V_9 = F_54 ( V_149 ) ;
V_9 |= F_55 ( V_150 ) ;
F_8 ( V_6 , F_56 ( V_64 ) , V_9 ) ;
V_9 = F_57 ( V_151 ) ;
V_9 |= F_58 ( V_152 ) ;
F_8 ( V_6 , F_59 ( V_64 ) , V_9 ) ;
F_8 ( V_6 , F_60 ( V_64 ) , V_153 ) ;
F_21 ( V_14 , V_114 -> V_144 ) ;
F_22 ( V_14 , V_114 -> V_144 ) ;
F_24 ( V_14 , V_64 , V_96 , true ) ;
F_16 ( V_14 , V_64 , F_1 ( V_118 -> V_124 -> V_124 ) ) ;
if ( V_14 -> V_80 == V_168 ||
V_14 -> V_80 == V_81 )
F_42 ( V_14 ) ;
F_28 ( V_14 ) ;
F_41 ( & V_6 -> V_129 , V_74 ) ;
F_10 ( V_14 ) ;
}
static void F_61 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned int V_169 = 100 ;
F_4 ( V_6 , V_34 , V_170 ) ;
while ( -- V_169 ) {
if ( ~ F_2 ( V_6 , V_34 ) & V_170 )
break;
F_62 ( 10 ) ;
}
F_63 ( V_169 == 0 , L_3 ) ;
}
static void F_64 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned long V_74 ;
F_37 ( & V_6 -> V_129 , V_74 ) ;
F_9 ( V_6 , V_16 , V_171 , V_172 ) ;
F_9 ( V_6 , V_16 , V_173 , V_174 ) ;
F_9 ( V_6 , V_15 , V_175 ,
V_176 ) ;
F_8 ( V_6 , V_19 , 0 ) ;
F_8 ( V_6 , V_177 , F_65 ( 0 , 128 , 128 ) ) ;
F_8 ( V_6 , V_178 , F_65 ( 0 , 128 , 128 ) ) ;
F_8 ( V_6 , V_179 , F_65 ( 0 , 128 , 128 ) ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_61 ( V_14 ) ;
F_15 ( V_6 ) ;
}
F_9 ( V_6 , V_16 , 0 , V_97 ) ;
F_9 ( V_6 , V_16 , 0 , V_99 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) )
F_9 ( V_6 , V_16 , 0 , V_103 ) ;
F_41 ( & V_6 -> V_129 , V_74 ) ;
}
static T_4 F_66 ( int V_180 , void * V_181 )
{
struct V_13 * V_14 = V_181 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 , V_112 , V_182 ;
F_67 ( & V_6 -> V_129 ) ;
V_9 = F_7 ( V_6 , V_18 ) ;
if ( V_9 & V_183 ) {
V_9 |= V_184 ;
V_9 &= ~ V_183 ;
if ( F_20 ( V_77 , & V_14 -> V_74 ) ) {
V_112 = F_7 ( V_6 , F_60 ( 0 ) ) ;
V_182 = F_7 ( V_6 , F_68 ( 0 ) ) ;
if ( V_112 != V_182 )
goto V_185;
V_112 = F_7 ( V_6 , F_60 ( 1 ) ) ;
V_182 = F_7 ( V_6 , F_68 ( 1 ) ) ;
if ( V_112 != V_182 )
goto V_185;
}
F_69 ( & V_14 -> V_115 -> V_112 ) ;
}
V_185:
F_8 ( V_6 , V_18 , V_9 ) ;
F_70 ( & V_6 -> V_129 ) ;
return V_186 ;
}
static int F_71 ( struct V_13 * V_187 )
{
struct V_188 * V_189 = & V_187 -> V_190 -> V_189 ;
struct V_5 * V_66 = & V_187 -> V_66 ;
struct V_191 * V_6 ;
int V_192 ;
F_72 ( & V_66 -> V_129 ) ;
V_66 -> V_193 = F_73 ( V_189 , L_4 ) ;
if ( F_74 ( V_66 -> V_193 ) ) {
F_75 ( V_189 , L_5 ) ;
return - V_194 ;
}
V_66 -> V_195 = F_73 ( V_189 , L_6 ) ;
if ( F_74 ( V_66 -> V_195 ) ) {
F_75 ( V_189 , L_7 ) ;
return F_76 ( V_66 -> V_195 ) ;
}
V_66 -> V_196 = F_73 ( V_189 , L_8 ) ;
if ( F_74 ( V_66 -> V_196 ) ) {
F_75 ( V_189 , L_9 ) ;
return - V_194 ;
}
V_6 = F_77 ( V_187 -> V_190 , V_197 , 0 ) ;
if ( V_6 == NULL ) {
F_75 ( V_189 , L_10 ) ;
return - V_198 ;
}
V_66 -> V_12 = F_78 ( V_189 , V_6 -> V_199 ,
F_79 ( V_6 ) ) ;
if ( V_66 -> V_12 == NULL ) {
F_75 ( V_189 , L_11 ) ;
return - V_198 ;
}
V_6 = F_77 ( V_187 -> V_190 , V_200 , 0 ) ;
if ( V_6 == NULL ) {
F_75 ( V_189 , L_12 ) ;
return - V_198 ;
}
V_192 = F_80 ( V_189 , V_6 -> V_199 , F_66 ,
0 , L_13 , V_187 ) ;
if ( V_192 ) {
F_75 ( V_189 , L_14 ) ;
return V_192 ;
}
V_66 -> V_180 = V_6 -> V_199 ;
return 0 ;
}
static int F_81 ( struct V_13 * V_187 )
{
struct V_188 * V_189 = & V_187 -> V_190 -> V_189 ;
struct V_5 * V_66 = & V_187 -> V_66 ;
struct V_191 * V_6 ;
V_66 -> V_201 = F_73 ( V_189 , L_15 ) ;
if ( F_74 ( V_66 -> V_201 ) ) {
F_75 ( V_189 , L_16 ) ;
return - V_194 ;
}
if ( F_20 ( V_202 , & V_187 -> V_74 ) ) {
V_66 -> V_203 = F_73 ( V_189 , L_17 ) ;
if ( F_74 ( V_66 -> V_203 ) ) {
F_75 ( V_189 , L_18 ) ;
return - V_194 ;
}
V_66 -> V_204 = F_73 ( V_189 , L_19 ) ;
if ( F_74 ( V_66 -> V_204 ) ) {
F_75 ( V_189 , L_20 ) ;
return - V_194 ;
}
if ( V_66 -> V_196 && V_66 -> V_204 )
F_82 ( V_66 -> V_204 ,
V_66 -> V_196 ) ;
}
V_6 = F_77 ( V_187 -> V_190 , V_197 , 1 ) ;
if ( V_6 == NULL ) {
F_75 ( V_189 , L_10 ) ;
return - V_198 ;
}
V_66 -> V_8 = F_78 ( V_189 , V_6 -> V_199 ,
F_79 ( V_6 ) ) ;
if ( V_66 -> V_8 == NULL ) {
F_75 ( V_189 , L_11 ) ;
return - V_198 ;
}
return 0 ;
}
static int F_83 ( struct V_13 * V_187 ,
struct V_205 * V_206 )
{
int V_192 ;
struct V_207 * V_208 ;
V_208 = V_206 -> V_209 ;
V_187 -> V_206 = V_206 ;
V_192 = F_71 ( V_187 ) ;
if ( V_192 ) {
F_33 ( L_21 , V_192 ) ;
return V_192 ;
}
if ( F_20 ( V_73 , & V_187 -> V_74 ) ) {
V_192 = F_81 ( V_187 ) ;
if ( V_192 ) {
F_33 ( L_22 , V_192 ) ;
return V_192 ;
}
}
return F_84 ( V_206 , V_187 -> V_189 ) ;
}
static void F_85 ( struct V_13 * V_187 )
{
F_86 ( V_187 -> V_206 , V_187 -> V_189 ) ;
}
static int F_87 ( struct V_210 * V_115 )
{
struct V_13 * V_187 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_187 -> V_66 ;
F_35 ( V_211 , & V_187 -> V_74 ) ;
if ( ! F_20 ( V_212 , & V_187 -> V_74 ) )
return 0 ;
F_9 ( V_6 , V_18 , ~ 0 , V_184 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_213 ) ;
return 0 ;
}
static void F_88 ( struct V_210 * V_115 )
{
struct V_13 * V_187 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_187 -> V_66 ;
F_36 ( V_211 , & V_187 -> V_74 ) ;
if ( ! F_20 ( V_212 , & V_187 -> V_74 ) )
return;
F_9 ( V_6 , V_18 , ~ 0 , V_184 ) ;
F_9 ( V_6 , V_17 , 0 , V_213 ) ;
}
static void F_89 ( struct V_210 * V_115 )
{
struct V_13 * V_187 = V_115 -> V_14 ;
if ( ! F_20 ( V_212 , & V_187 -> V_74 ) )
return;
F_19 ( V_187 , false ) ;
}
static void F_90 ( struct V_210 * V_115 ,
struct V_108 * V_109 )
{
struct V_13 * V_187 = V_115 -> V_14 ;
F_44 ( L_23 , V_109 -> V_145 ) ;
if ( ! F_20 ( V_212 , & V_187 -> V_74 ) )
return;
if ( V_109 -> V_145 == V_101 )
F_31 ( V_187 , V_109 ) ;
else
F_43 ( V_187 , V_109 ) ;
}
static void F_91 ( struct V_210 * V_115 ,
struct V_108 * V_109 )
{
struct V_13 * V_187 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_187 -> V_66 ;
unsigned long V_74 ;
F_44 ( L_23 , V_109 -> V_145 ) ;
if ( ! F_20 ( V_212 , & V_187 -> V_74 ) )
return;
F_37 ( & V_6 -> V_129 , V_74 ) ;
F_24 ( V_187 , V_109 -> V_145 , 0 , false ) ;
F_41 ( & V_6 -> V_129 , V_74 ) ;
}
static void F_92 ( struct V_210 * V_115 )
{
struct V_13 * V_187 = V_115 -> V_14 ;
if ( ! F_20 ( V_212 , & V_187 -> V_74 ) )
return;
F_19 ( V_187 , true ) ;
F_93 ( V_115 ) ;
}
static void F_94 ( struct V_210 * V_115 )
{
struct V_13 * V_14 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
if ( F_20 ( V_212 , & V_14 -> V_74 ) )
return;
F_95 ( V_14 -> V_189 ) ;
F_96 ( V_115 , true ) ;
F_19 ( V_14 , false ) ;
F_9 ( V_6 , V_15 , ~ 0 , V_214 ) ;
if ( F_20 ( V_211 , & V_14 -> V_74 ) ) {
F_9 ( V_6 , V_18 , ~ 0 , V_184 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_213 ) ;
}
F_64 ( V_14 ) ;
F_19 ( V_14 , true ) ;
F_97 ( V_212 , & V_14 -> V_74 ) ;
}
static void F_98 ( struct V_210 * V_115 )
{
struct V_13 * V_14 = V_115 -> V_14 ;
int V_215 ;
if ( ! F_20 ( V_212 , & V_14 -> V_74 ) )
return;
F_29 ( V_14 ) ;
F_10 ( V_14 ) ;
for ( V_215 = 0 ; V_215 < V_216 ; V_215 ++ )
F_91 ( V_115 , & V_14 -> V_217 [ V_215 ] ) ;
F_96 ( V_115 , false ) ;
F_99 ( V_14 -> V_189 ) ;
F_100 ( V_212 , & V_14 -> V_74 ) ;
}
static int F_101 ( struct V_210 * V_115 ,
struct V_218 * V_111 )
{
struct V_113 * V_114 = & V_111 -> V_116 ;
T_1 V_137 , V_138 ;
V_137 = V_114 -> V_166 ;
V_138 = V_114 -> V_144 ;
F_44 ( L_24 ,
V_114 -> V_166 , V_114 -> V_144 , V_114 -> V_219 ,
( V_114 -> V_74 & V_127 ) ? 1 : 0 ) ;
if ( ( V_137 >= 464 && V_137 <= 720 && V_138 >= 261 && V_138 <= 576 ) ||
( V_137 >= 1024 && V_137 <= 1280 && V_138 >= 576 && V_138 <= 720 ) ||
( V_137 >= 1664 && V_137 <= 1920 && V_138 >= 936 && V_138 <= 1080 ) )
return 0 ;
return - V_220 ;
}
static int F_102 ( struct V_188 * V_189 , struct V_188 * V_221 , void * V_56 )
{
struct V_13 * V_14 = F_103 ( V_189 ) ;
struct V_205 * V_206 = V_56 ;
struct V_108 * V_222 ;
unsigned int V_215 ;
int V_192 ;
V_192 = F_83 ( V_14 , V_206 ) ;
if ( V_192 )
return V_192 ;
for ( V_215 = 0 ; V_215 < V_216 ; V_215 ++ ) {
if ( V_215 == V_101 && ! F_20 ( V_73 ,
& V_14 -> V_74 ) )
continue;
V_192 = F_104 ( V_206 , & V_14 -> V_217 [ V_215 ] , V_215 ,
& V_223 [ V_215 ] ) ;
if ( V_192 )
return V_192 ;
}
V_222 = & V_14 -> V_217 [ V_165 ] ;
V_14 -> V_115 = F_105 ( V_206 , & V_222 -> V_112 ,
V_224 , & V_225 , V_14 ) ;
if ( F_74 ( V_14 -> V_115 ) ) {
F_85 ( V_14 ) ;
V_192 = F_76 ( V_14 -> V_115 ) ;
goto V_226;
}
return 0 ;
V_226:
F_106 ( V_189 , V_14 ) ;
return V_192 ;
}
static void F_107 ( struct V_188 * V_189 , struct V_188 * V_227 , void * V_56 )
{
struct V_13 * V_14 = F_103 ( V_189 ) ;
F_85 ( V_14 ) ;
}
static int F_108 ( struct V_228 * V_190 )
{
struct V_188 * V_189 = & V_190 -> V_189 ;
const struct V_229 * V_230 ;
struct V_13 * V_14 ;
int V_192 ;
V_14 = F_109 ( & V_190 -> V_189 , sizeof( * V_14 ) , V_231 ) ;
if ( ! V_14 ) {
F_33 ( L_25 ) ;
return - V_232 ;
}
V_230 = F_110 ( V_189 ) ;
V_14 -> V_190 = V_190 ;
V_14 -> V_189 = V_189 ;
V_14 -> V_80 = V_230 -> V_233 ;
if ( V_230 -> V_234 )
F_35 ( V_73 , & V_14 -> V_74 ) ;
if ( V_230 -> V_235 )
F_35 ( V_202 , & V_14 -> V_74 ) ;
F_111 ( V_190 , V_14 ) ;
V_192 = F_112 ( & V_190 -> V_189 , & V_236 ) ;
if ( ! V_192 )
F_113 ( V_189 ) ;
return V_192 ;
}
static int F_114 ( struct V_228 * V_190 )
{
F_115 ( & V_190 -> V_189 ) ;
F_116 ( & V_190 -> V_189 , & V_236 ) ;
return 0 ;
}
static int T_5 F_117 ( struct V_188 * V_189 )
{
struct V_13 * V_14 = F_103 ( V_189 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
F_118 ( V_6 -> V_195 ) ;
F_118 ( V_6 -> V_193 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_118 ( V_6 -> V_201 ) ;
if ( F_20 ( V_202 , & V_14 -> V_74 ) )
F_118 ( V_6 -> V_203 ) ;
}
return 0 ;
}
static int T_5 F_119 ( struct V_188 * V_189 )
{
struct V_13 * V_14 = F_103 ( V_189 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_192 ;
V_192 = F_120 ( V_6 -> V_193 ) ;
if ( V_192 < 0 ) {
F_33 ( L_26 , V_192 ) ;
return V_192 ;
}
V_192 = F_120 ( V_6 -> V_195 ) ;
if ( V_192 < 0 ) {
F_33 ( L_27 , V_192 ) ;
return V_192 ;
}
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
V_192 = F_120 ( V_6 -> V_201 ) ;
if ( V_192 < 0 ) {
F_33 ( L_28 ,
V_192 ) ;
return V_192 ;
}
if ( F_20 ( V_202 , & V_14 -> V_74 ) ) {
V_192 = F_120 ( V_6 -> V_203 ) ;
if ( V_192 < 0 ) {
F_33 ( L_29 \
L_30 ,
V_192 ) ;
return V_192 ;
}
}
}
return 0 ;
}
