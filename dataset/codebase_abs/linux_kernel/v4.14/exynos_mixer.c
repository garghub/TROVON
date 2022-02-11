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
bool V_122 , V_123 ;
T_1 V_9 ;
V_123 = ( V_118 -> V_124 -> V_124 == V_125 ) ;
V_122 = ( V_118 -> V_126 == V_127 ) ;
V_120 [ 0 ] = F_33 ( V_118 , 0 ) ;
V_121 [ 0 ] = F_33 ( V_118 , 1 ) ;
if ( V_114 -> V_74 & V_128 ) {
F_34 ( V_77 , & V_14 -> V_74 ) ;
if ( V_122 ) {
V_120 [ 1 ] = V_120 [ 0 ] + 0x40 ;
V_121 [ 1 ] = V_121 [ 0 ] + 0x40 ;
} else {
V_120 [ 1 ] = V_120 [ 0 ] + V_118 -> V_129 [ 0 ] ;
V_121 [ 1 ] = V_121 [ 0 ] + V_118 -> V_129 [ 0 ] ;
}
} else {
F_35 ( V_77 , & V_14 -> V_74 ) ;
V_120 [ 1 ] = 0 ;
V_121 [ 1 ] = 0 ;
}
F_36 ( & V_6 -> V_130 , V_74 ) ;
V_9 = ( F_20 ( V_77 , & V_14 -> V_74 ) ? ~ 0 : 0 ) ;
F_6 ( V_6 , V_37 , V_9 , V_131 ) ;
V_9 = ( V_123 ? V_132 : V_133 ) ;
V_9 |= ( V_122 ? V_134 : V_135 ) ;
F_6 ( V_6 , V_37 , V_9 , V_136 ) ;
F_4 ( V_6 , V_38 , F_37 ( V_118 -> V_129 [ 0 ] ) |
F_38 ( V_118 -> V_76 ) ) ;
F_4 ( V_6 , V_39 , F_37 ( V_118 -> V_129 [ 0 ] ) |
F_38 ( V_118 -> V_76 / 2 ) ) ;
F_4 ( V_6 , V_48 , V_111 -> V_137 . V_138 ) ;
F_4 ( V_6 , V_49 , V_111 -> V_137 . V_139 ) ;
F_4 ( V_6 , V_46 ,
F_39 ( V_111 -> V_137 . V_140 ) ) ;
F_4 ( V_6 , V_47 , V_111 -> V_137 . V_141 ) ;
F_4 ( V_6 , V_52 , V_111 -> V_115 . V_138 ) ;
F_4 ( V_6 , V_50 , V_111 -> V_115 . V_140 ) ;
if ( F_20 ( V_77 , & V_14 -> V_74 ) ) {
F_4 ( V_6 , V_53 , V_111 -> V_115 . V_139 / 2 ) ;
F_4 ( V_6 , V_51 , V_111 -> V_115 . V_141 / 2 ) ;
} else {
F_4 ( V_6 , V_53 , V_111 -> V_115 . V_139 ) ;
F_4 ( V_6 , V_51 , V_111 -> V_115 . V_141 ) ;
}
F_4 ( V_6 , V_54 , V_111 -> V_142 ) ;
F_4 ( V_6 , V_55 , V_111 -> V_143 ) ;
F_4 ( V_6 , V_45 , V_144 ) ;
F_4 ( V_6 , V_41 , V_120 [ 0 ] ) ;
F_4 ( V_6 , V_42 , V_120 [ 1 ] ) ;
F_4 ( V_6 , V_43 , V_121 [ 0 ] ) ;
F_4 ( V_6 , V_44 , V_121 [ 1 ] ) ;
F_21 ( V_14 , V_114 -> V_145 ) ;
F_22 ( V_14 , V_114 -> V_145 ) ;
F_24 ( V_14 , V_109 -> V_146 , V_96 , true ) ;
F_18 ( V_14 ) ;
F_28 ( V_14 ) ;
F_40 ( & V_6 -> V_130 , V_74 ) ;
F_10 ( V_14 ) ;
F_12 ( V_14 ) ;
}
static void F_41 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_16 , ~ 0 , V_147 ) ;
}
static void F_42 ( struct V_13 * V_14 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 =
F_32 ( V_109 -> V_112 . V_111 ) ;
struct V_113 * V_114 = & V_111 -> V_112 . V_115 -> V_111 -> V_116 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_117 * V_118 = V_111 -> V_112 . V_118 ;
unsigned int V_96 = V_111 -> V_112 . V_119 + 1 ;
unsigned long V_74 ;
unsigned int V_64 = V_109 -> V_146 ;
unsigned int V_148 = 0 , V_149 = 0 ;
unsigned int V_150 , V_151 ;
T_3 V_152 ;
unsigned int V_153 ;
T_1 V_9 ;
switch ( V_118 -> V_124 -> V_124 ) {
case V_154 :
case V_4 :
V_153 = V_155 ;
break;
case V_156 :
case V_3 :
V_153 = V_157 ;
break;
case V_158 :
V_153 = V_159 ;
break;
case V_160 :
case V_2 :
default:
V_153 = V_161 ;
break;
}
V_148 = V_111 -> V_142 == ( 1 << 15 ) ;
V_149 = V_111 -> V_143 == ( 1 << 15 ) ;
V_150 = V_111 -> V_115 . V_140 ;
V_151 = V_111 -> V_115 . V_141 ;
V_152 = F_33 ( V_118 , 0 )
+ ( V_111 -> V_137 . V_140 * V_118 -> V_124 -> V_162 [ 0 ] )
+ ( V_111 -> V_137 . V_141 * V_118 -> V_129 [ 0 ] ) ;
if ( V_114 -> V_74 & V_128 )
F_34 ( V_77 , & V_14 -> V_74 ) ;
else
F_35 ( V_77 , & V_14 -> V_74 ) ;
F_36 ( & V_6 -> V_130 , V_74 ) ;
F_9 ( V_6 , F_17 ( V_64 ) ,
F_43 ( V_153 ) , V_163 ) ;
F_8 ( V_6 , F_44 ( V_64 ) ,
V_118 -> V_129 [ 0 ] / V_118 -> V_124 -> V_162 [ 0 ] ) ;
if ( V_14 -> V_80 == V_81 &&
V_64 == V_164 ) {
V_9 = F_45 ( V_114 -> V_145 ) ;
V_9 |= F_46 ( V_114 -> V_165 ) ;
F_8 ( V_6 , V_166 , V_9 ) ;
}
V_9 = F_47 ( V_111 -> V_137 . V_138 ) ;
V_9 |= F_48 ( V_111 -> V_137 . V_139 ) ;
V_9 |= F_49 ( V_148 ) ;
V_9 |= F_50 ( V_149 ) ;
F_8 ( V_6 , F_51 ( V_64 ) , V_9 ) ;
V_9 = F_52 ( V_150 ) ;
V_9 |= F_53 ( V_151 ) ;
F_8 ( V_6 , F_54 ( V_64 ) , V_9 ) ;
F_8 ( V_6 , F_55 ( V_64 ) , V_152 ) ;
F_21 ( V_14 , V_114 -> V_145 ) ;
F_22 ( V_14 , V_114 -> V_145 ) ;
F_24 ( V_14 , V_64 , V_96 , true ) ;
F_16 ( V_14 , V_64 , F_1 ( V_118 -> V_124 -> V_124 ) ) ;
if ( V_14 -> V_80 == V_167 ||
V_14 -> V_80 == V_81 )
F_41 ( V_14 ) ;
F_28 ( V_14 ) ;
F_40 ( & V_6 -> V_130 , V_74 ) ;
F_10 ( V_14 ) ;
}
static void F_56 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned int V_168 = 100 ;
F_4 ( V_6 , V_34 , V_169 ) ;
while ( -- V_168 ) {
if ( ~ F_2 ( V_6 , V_34 ) & V_169 )
break;
F_57 ( 10 ) ;
}
F_58 ( V_168 == 0 , L_1 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned long V_74 ;
F_36 ( & V_6 -> V_130 , V_74 ) ;
F_9 ( V_6 , V_16 , V_170 , V_171 ) ;
F_9 ( V_6 , V_16 , V_172 , V_173 ) ;
F_9 ( V_6 , V_15 , V_174 ,
V_175 ) ;
F_8 ( V_6 , V_19 , 0 ) ;
F_8 ( V_6 , V_176 , F_60 ( 0 , 128 , 128 ) ) ;
F_8 ( V_6 , V_177 , F_60 ( 0 , 128 , 128 ) ) ;
F_8 ( V_6 , V_178 , F_60 ( 0 , 128 , 128 ) ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_56 ( V_14 ) ;
F_15 ( V_6 ) ;
}
F_9 ( V_6 , V_16 , 0 , V_97 ) ;
F_9 ( V_6 , V_16 , 0 , V_99 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) )
F_9 ( V_6 , V_16 , 0 , V_103 ) ;
F_8 ( V_6 , F_61 ( 0 ) , 0 ) ;
F_8 ( V_6 , F_61 ( 1 ) , 0 ) ;
F_40 ( & V_6 -> V_130 , V_74 ) ;
}
static T_4 F_62 ( int V_179 , void * V_180 )
{
struct V_13 * V_14 = V_180 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 , V_112 , V_181 ;
F_63 ( & V_6 -> V_130 ) ;
V_9 = F_7 ( V_6 , V_18 ) ;
if ( V_9 & V_182 ) {
V_9 |= V_183 ;
V_9 &= ~ V_182 ;
if ( F_20 ( V_77 , & V_14 -> V_74 ) ) {
V_112 = F_7 ( V_6 , F_55 ( 0 ) ) ;
V_181 = F_7 ( V_6 , F_64 ( 0 ) ) ;
if ( V_112 != V_181 )
goto V_184;
V_112 = F_7 ( V_6 , F_55 ( 1 ) ) ;
V_181 = F_7 ( V_6 , F_64 ( 1 ) ) ;
if ( V_112 != V_181 )
goto V_184;
}
F_65 ( & V_14 -> V_115 -> V_112 ) ;
}
V_184:
F_8 ( V_6 , V_18 , V_9 ) ;
F_66 ( & V_6 -> V_130 ) ;
return V_185 ;
}
static int F_67 ( struct V_13 * V_186 )
{
struct V_187 * V_188 = & V_186 -> V_189 -> V_188 ;
struct V_5 * V_66 = & V_186 -> V_66 ;
struct V_190 * V_6 ;
int V_191 ;
F_68 ( & V_66 -> V_130 ) ;
V_66 -> V_192 = F_69 ( V_188 , L_2 ) ;
if ( F_70 ( V_66 -> V_192 ) ) {
F_71 ( V_188 , L_3 ) ;
return - V_193 ;
}
V_66 -> V_194 = F_69 ( V_188 , L_4 ) ;
if ( F_70 ( V_66 -> V_194 ) ) {
F_71 ( V_188 , L_5 ) ;
return F_72 ( V_66 -> V_194 ) ;
}
V_66 -> V_195 = F_69 ( V_188 , L_6 ) ;
if ( F_70 ( V_66 -> V_195 ) ) {
F_71 ( V_188 , L_7 ) ;
return - V_193 ;
}
V_6 = F_73 ( V_186 -> V_189 , V_196 , 0 ) ;
if ( V_6 == NULL ) {
F_71 ( V_188 , L_8 ) ;
return - V_197 ;
}
V_66 -> V_12 = F_74 ( V_188 , V_6 -> V_198 ,
F_75 ( V_6 ) ) ;
if ( V_66 -> V_12 == NULL ) {
F_71 ( V_188 , L_9 ) ;
return - V_197 ;
}
V_6 = F_73 ( V_186 -> V_189 , V_199 , 0 ) ;
if ( V_6 == NULL ) {
F_71 ( V_188 , L_10 ) ;
return - V_197 ;
}
V_191 = F_76 ( V_188 , V_6 -> V_198 , F_62 ,
0 , L_11 , V_186 ) ;
if ( V_191 ) {
F_71 ( V_188 , L_12 ) ;
return V_191 ;
}
V_66 -> V_179 = V_6 -> V_198 ;
return 0 ;
}
static int F_77 ( struct V_13 * V_186 )
{
struct V_187 * V_188 = & V_186 -> V_189 -> V_188 ;
struct V_5 * V_66 = & V_186 -> V_66 ;
struct V_190 * V_6 ;
V_66 -> V_200 = F_69 ( V_188 , L_13 ) ;
if ( F_70 ( V_66 -> V_200 ) ) {
F_71 ( V_188 , L_14 ) ;
return - V_193 ;
}
if ( F_20 ( V_201 , & V_186 -> V_74 ) ) {
V_66 -> V_202 = F_69 ( V_188 , L_15 ) ;
if ( F_70 ( V_66 -> V_202 ) ) {
F_71 ( V_188 , L_16 ) ;
return - V_193 ;
}
V_66 -> V_203 = F_69 ( V_188 , L_17 ) ;
if ( F_70 ( V_66 -> V_203 ) ) {
F_71 ( V_188 , L_18 ) ;
return - V_193 ;
}
if ( V_66 -> V_195 && V_66 -> V_203 )
F_78 ( V_66 -> V_203 ,
V_66 -> V_195 ) ;
}
V_6 = F_73 ( V_186 -> V_189 , V_196 , 1 ) ;
if ( V_6 == NULL ) {
F_71 ( V_188 , L_8 ) ;
return - V_197 ;
}
V_66 -> V_8 = F_74 ( V_188 , V_6 -> V_198 ,
F_75 ( V_6 ) ) ;
if ( V_66 -> V_8 == NULL ) {
F_71 ( V_188 , L_9 ) ;
return - V_197 ;
}
return 0 ;
}
static int F_79 ( struct V_13 * V_186 ,
struct V_204 * V_205 )
{
int V_191 ;
struct V_206 * V_207 ;
V_207 = V_205 -> V_208 ;
V_186 -> V_205 = V_205 ;
V_191 = F_67 ( V_186 ) ;
if ( V_191 ) {
F_80 ( L_19 , V_191 ) ;
return V_191 ;
}
if ( F_20 ( V_73 , & V_186 -> V_74 ) ) {
V_191 = F_77 ( V_186 ) ;
if ( V_191 ) {
F_80 ( L_20 , V_191 ) ;
return V_191 ;
}
}
return F_81 ( V_205 , V_186 -> V_188 ) ;
}
static void F_82 ( struct V_13 * V_186 )
{
F_83 ( V_186 -> V_205 , V_186 -> V_188 ) ;
}
static int F_84 ( struct V_209 * V_115 )
{
struct V_13 * V_186 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_186 -> V_66 ;
F_34 ( V_210 , & V_186 -> V_74 ) ;
if ( ! F_20 ( V_211 , & V_186 -> V_74 ) )
return 0 ;
F_9 ( V_6 , V_18 , ~ 0 , V_183 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_212 ) ;
return 0 ;
}
static void F_85 ( struct V_209 * V_115 )
{
struct V_13 * V_186 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_186 -> V_66 ;
F_35 ( V_210 , & V_186 -> V_74 ) ;
if ( ! F_20 ( V_211 , & V_186 -> V_74 ) )
return;
F_9 ( V_6 , V_18 , ~ 0 , V_183 ) ;
F_9 ( V_6 , V_17 , 0 , V_212 ) ;
}
static void F_86 ( struct V_209 * V_115 )
{
struct V_13 * V_186 = V_115 -> V_14 ;
if ( ! F_20 ( V_211 , & V_186 -> V_74 ) )
return;
F_19 ( V_186 , false ) ;
}
static void F_87 ( struct V_209 * V_115 ,
struct V_108 * V_109 )
{
struct V_13 * V_186 = V_115 -> V_14 ;
F_88 ( L_21 , V_109 -> V_146 ) ;
if ( ! F_20 ( V_211 , & V_186 -> V_74 ) )
return;
if ( V_109 -> V_146 == V_101 )
F_31 ( V_186 , V_109 ) ;
else
F_42 ( V_186 , V_109 ) ;
}
static void F_89 ( struct V_209 * V_115 ,
struct V_108 * V_109 )
{
struct V_13 * V_186 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_186 -> V_66 ;
unsigned long V_74 ;
F_88 ( L_21 , V_109 -> V_146 ) ;
if ( ! F_20 ( V_211 , & V_186 -> V_74 ) )
return;
F_36 ( & V_6 -> V_130 , V_74 ) ;
F_24 ( V_186 , V_109 -> V_146 , 0 , false ) ;
F_40 ( & V_6 -> V_130 , V_74 ) ;
}
static void F_90 ( struct V_209 * V_115 )
{
struct V_13 * V_186 = V_115 -> V_14 ;
if ( ! F_20 ( V_211 , & V_186 -> V_74 ) )
return;
F_19 ( V_186 , true ) ;
F_91 ( V_115 ) ;
}
static void F_92 ( struct V_209 * V_115 )
{
struct V_13 * V_14 = V_115 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
if ( F_20 ( V_211 , & V_14 -> V_74 ) )
return;
F_93 ( V_14 -> V_188 ) ;
F_94 ( V_115 , true ) ;
F_19 ( V_14 , false ) ;
F_9 ( V_6 , V_15 , ~ 0 , V_213 ) ;
if ( F_20 ( V_210 , & V_14 -> V_74 ) ) {
F_9 ( V_6 , V_18 , ~ 0 , V_183 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_212 ) ;
}
F_59 ( V_14 ) ;
F_19 ( V_14 , true ) ;
F_95 ( V_211 , & V_14 -> V_74 ) ;
}
static void F_96 ( struct V_209 * V_115 )
{
struct V_13 * V_14 = V_115 -> V_14 ;
int V_214 ;
if ( ! F_20 ( V_211 , & V_14 -> V_74 ) )
return;
F_29 ( V_14 ) ;
F_10 ( V_14 ) ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ )
F_89 ( V_115 , & V_14 -> V_216 [ V_214 ] ) ;
F_94 ( V_115 , false ) ;
F_97 ( V_14 -> V_188 ) ;
F_98 ( V_211 , & V_14 -> V_74 ) ;
}
static int F_99 ( struct V_209 * V_115 ,
struct V_217 * V_111 )
{
struct V_113 * V_114 = & V_111 -> V_116 ;
T_1 V_138 , V_139 ;
V_138 = V_114 -> V_165 ;
V_139 = V_114 -> V_145 ;
F_88 ( L_22 ,
V_114 -> V_165 , V_114 -> V_145 , V_114 -> V_218 ,
( V_114 -> V_74 & V_128 ) ? 1 : 0 ) ;
if ( ( V_138 >= 464 && V_138 <= 720 && V_139 >= 261 && V_139 <= 576 ) ||
( V_138 >= 1024 && V_138 <= 1280 && V_139 >= 576 && V_139 <= 720 ) ||
( V_138 >= 1664 && V_138 <= 1920 && V_139 >= 936 && V_139 <= 1080 ) )
return 0 ;
return - V_219 ;
}
static int F_100 ( struct V_187 * V_188 , struct V_187 * V_220 , void * V_56 )
{
struct V_13 * V_14 = F_101 ( V_188 ) ;
struct V_204 * V_205 = V_56 ;
struct V_108 * V_221 ;
unsigned int V_214 ;
int V_191 ;
V_191 = F_79 ( V_14 , V_205 ) ;
if ( V_191 )
return V_191 ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ ) {
if ( V_214 == V_101 && ! F_20 ( V_73 ,
& V_14 -> V_74 ) )
continue;
V_191 = F_102 ( V_205 , & V_14 -> V_216 [ V_214 ] , V_214 ,
& V_222 [ V_214 ] ) ;
if ( V_191 )
return V_191 ;
}
V_221 = & V_14 -> V_216 [ V_164 ] ;
V_14 -> V_115 = F_103 ( V_205 , & V_221 -> V_112 ,
V_223 , & V_224 , V_14 ) ;
if ( F_70 ( V_14 -> V_115 ) ) {
F_82 ( V_14 ) ;
V_191 = F_72 ( V_14 -> V_115 ) ;
goto V_225;
}
return 0 ;
V_225:
F_104 ( V_188 , V_14 ) ;
return V_191 ;
}
static void F_105 ( struct V_187 * V_188 , struct V_187 * V_226 , void * V_56 )
{
struct V_13 * V_14 = F_101 ( V_188 ) ;
F_82 ( V_14 ) ;
}
static int F_106 ( struct V_227 * V_189 )
{
struct V_187 * V_188 = & V_189 -> V_188 ;
const struct V_228 * V_229 ;
struct V_13 * V_14 ;
int V_191 ;
V_14 = F_107 ( & V_189 -> V_188 , sizeof( * V_14 ) , V_230 ) ;
if ( ! V_14 ) {
F_80 ( L_23 ) ;
return - V_231 ;
}
V_229 = F_108 ( V_188 ) ;
V_14 -> V_189 = V_189 ;
V_14 -> V_188 = V_188 ;
V_14 -> V_80 = V_229 -> V_232 ;
if ( V_229 -> V_233 )
F_34 ( V_73 , & V_14 -> V_74 ) ;
if ( V_229 -> V_234 )
F_34 ( V_201 , & V_14 -> V_74 ) ;
F_109 ( V_189 , V_14 ) ;
V_191 = F_110 ( & V_189 -> V_188 , & V_235 ) ;
if ( ! V_191 )
F_111 ( V_188 ) ;
return V_191 ;
}
static int F_112 ( struct V_227 * V_189 )
{
F_113 ( & V_189 -> V_188 ) ;
F_114 ( & V_189 -> V_188 , & V_235 ) ;
return 0 ;
}
static int T_5 F_115 ( struct V_187 * V_188 )
{
struct V_13 * V_14 = F_101 ( V_188 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
F_116 ( V_6 -> V_194 ) ;
F_116 ( V_6 -> V_192 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_116 ( V_6 -> V_200 ) ;
if ( F_20 ( V_201 , & V_14 -> V_74 ) )
F_116 ( V_6 -> V_202 ) ;
}
return 0 ;
}
static int T_5 F_117 ( struct V_187 * V_188 )
{
struct V_13 * V_14 = F_101 ( V_188 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_191 ;
V_191 = F_118 ( V_6 -> V_192 ) ;
if ( V_191 < 0 ) {
F_80 ( L_24 , V_191 ) ;
return V_191 ;
}
V_191 = F_118 ( V_6 -> V_194 ) ;
if ( V_191 < 0 ) {
F_80 ( L_25 , V_191 ) ;
return V_191 ;
}
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
V_191 = F_118 ( V_6 -> V_200 ) ;
if ( V_191 < 0 ) {
F_80 ( L_26 ,
V_191 ) ;
return V_191 ;
}
if ( F_20 ( V_201 , & V_14 -> V_74 ) ) {
V_191 = F_118 ( V_6 -> V_202 ) ;
if ( V_191 < 0 ) {
F_80 ( L_27 \
L_28 ,
V_191 ) ;
return V_191 ;
}
}
}
return 0 ;
}
