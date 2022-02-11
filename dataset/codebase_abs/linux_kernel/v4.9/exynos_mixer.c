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
if ( V_76 == 480 ) {
V_9 = V_89 ;
} else if ( V_76 == 576 ) {
V_9 = V_89 ;
} else if ( V_76 == 720 ) {
V_9 = V_90 ;
F_8 ( V_6 , V_91 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_8 ( V_6 , V_92 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_8 ( V_6 , V_93 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else if ( V_76 == 1080 ) {
V_9 = V_90 ;
F_8 ( V_6 , V_91 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_8 ( V_6 , V_92 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_8 ( V_6 , V_93 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else {
V_9 = V_90 ;
F_8 ( V_6 , V_91 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_8 ( V_6 , V_92 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_8 ( V_6 , V_93 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
}
F_9 ( V_6 , V_16 , V_9 , V_94 ) ;
}
static void F_23 ( struct V_13 * V_14 , unsigned int V_64 ,
unsigned int V_95 , bool V_71 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 = V_71 ? ~ 0 : 0 ;
switch ( V_64 ) {
case 0 :
F_9 ( V_6 , V_16 , V_9 , V_96 ) ;
F_9 ( V_6 , V_19 ,
F_24 ( V_95 ) ,
V_97 ) ;
break;
case 1 :
F_9 ( V_6 , V_16 , V_9 , V_98 ) ;
F_9 ( V_6 , V_19 ,
F_25 ( V_95 ) ,
V_99 ) ;
break;
case V_100 :
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_6 ( V_6 , V_33 , V_9 , V_101 ) ;
F_9 ( V_6 , V_16 , V_9 ,
V_102 ) ;
F_9 ( V_6 , V_19 ,
F_26 ( V_95 ) ,
V_103 ) ;
}
break;
}
}
static void F_27 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_15 , ~ 0 , V_104 ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_105 = 20 ;
F_9 ( V_6 , V_15 , 0 , V_104 ) ;
while ( ! ( F_7 ( V_6 , V_15 ) & V_106 ) &&
-- V_105 )
F_29 ( 10000 , 12000 ) ;
}
static void F_30 ( struct V_13 * V_14 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 =
F_31 ( V_108 -> V_111 . V_110 ) ;
struct V_112 * V_113 = & V_110 -> V_111 . V_114 -> V_110 -> V_115 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_116 * V_117 = V_110 -> V_111 . V_117 ;
unsigned int V_95 = V_110 -> V_111 . V_118 + 1 ;
unsigned long V_74 ;
T_3 V_119 [ 2 ] , V_120 [ 2 ] ;
bool V_121 = false ;
bool V_122 = false ;
T_1 V_9 ;
switch ( V_117 -> V_1 ) {
case V_123 :
V_122 = false ;
break;
case V_124 :
V_122 = true ;
break;
default:
F_32 ( L_1 ,
V_117 -> V_1 ) ;
return;
}
V_119 [ 0 ] = F_33 ( V_117 , 0 ) ;
V_120 [ 0 ] = F_33 ( V_117 , 1 ) ;
if ( V_113 -> V_74 & V_125 ) {
F_34 ( V_77 , & V_14 -> V_74 ) ;
if ( V_121 ) {
V_119 [ 1 ] = V_119 [ 0 ] + 0x40 ;
V_120 [ 1 ] = V_120 [ 0 ] + 0x40 ;
} else {
V_119 [ 1 ] = V_119 [ 0 ] + V_117 -> V_126 [ 0 ] ;
V_120 [ 1 ] = V_120 [ 0 ] + V_117 -> V_126 [ 0 ] ;
}
} else {
F_35 ( V_77 , & V_14 -> V_74 ) ;
V_119 [ 1 ] = 0 ;
V_120 [ 1 ] = 0 ;
}
F_36 ( & V_6 -> V_127 , V_74 ) ;
V_9 = ( F_20 ( V_77 , & V_14 -> V_74 ) ? ~ 0 : 0 ) ;
F_6 ( V_6 , V_37 , V_9 , V_128 ) ;
V_9 = ( V_122 ? V_129 : V_130 ) ;
V_9 |= ( V_121 ? V_131 : V_132 ) ;
F_6 ( V_6 , V_37 , V_9 , V_133 ) ;
F_4 ( V_6 , V_38 , F_37 ( V_117 -> V_126 [ 0 ] ) |
F_38 ( V_117 -> V_76 ) ) ;
F_4 ( V_6 , V_39 , F_37 ( V_117 -> V_126 [ 0 ] ) |
F_38 ( V_117 -> V_76 / 2 ) ) ;
F_4 ( V_6 , V_48 , V_110 -> V_134 . V_135 ) ;
F_4 ( V_6 , V_49 , V_110 -> V_134 . V_136 ) ;
F_4 ( V_6 , V_46 ,
F_39 ( V_110 -> V_134 . V_137 ) ) ;
F_4 ( V_6 , V_47 , V_110 -> V_134 . V_138 ) ;
F_4 ( V_6 , V_52 , V_110 -> V_114 . V_135 ) ;
F_4 ( V_6 , V_50 , V_110 -> V_114 . V_137 ) ;
if ( F_20 ( V_77 , & V_14 -> V_74 ) ) {
F_4 ( V_6 , V_53 , V_110 -> V_114 . V_136 / 2 ) ;
F_4 ( V_6 , V_51 , V_110 -> V_114 . V_138 / 2 ) ;
} else {
F_4 ( V_6 , V_53 , V_110 -> V_114 . V_136 ) ;
F_4 ( V_6 , V_51 , V_110 -> V_114 . V_138 ) ;
}
F_4 ( V_6 , V_54 , V_110 -> V_139 ) ;
F_4 ( V_6 , V_55 , V_110 -> V_140 ) ;
F_4 ( V_6 , V_45 , V_141 ) ;
F_4 ( V_6 , V_41 , V_119 [ 0 ] ) ;
F_4 ( V_6 , V_42 , V_119 [ 1 ] ) ;
F_4 ( V_6 , V_43 , V_120 [ 0 ] ) ;
F_4 ( V_6 , V_44 , V_120 [ 1 ] ) ;
F_21 ( V_14 , V_113 -> V_142 ) ;
F_22 ( V_14 , V_113 -> V_142 ) ;
F_23 ( V_14 , V_108 -> V_143 , V_95 , true ) ;
F_18 ( V_14 ) ;
F_27 ( V_14 ) ;
F_40 ( & V_6 -> V_127 , V_74 ) ;
F_10 ( V_14 ) ;
F_12 ( V_14 ) ;
}
static void F_41 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_16 , ~ 0 , V_144 ) ;
}
static void F_42 ( struct V_13 * V_14 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 =
F_31 ( V_108 -> V_111 . V_110 ) ;
struct V_112 * V_113 = & V_110 -> V_111 . V_114 -> V_110 -> V_115 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_116 * V_117 = V_110 -> V_111 . V_117 ;
unsigned int V_95 = V_110 -> V_111 . V_118 + 1 ;
unsigned long V_74 ;
unsigned int V_64 = V_108 -> V_143 ;
unsigned int V_145 = 0 , V_146 = 0 ;
unsigned int V_147 , V_148 , V_149 , V_150 ;
T_3 V_151 ;
unsigned int V_152 ;
T_1 V_9 ;
switch ( V_117 -> V_1 ) {
case V_153 :
case V_4 :
V_152 = V_154 ;
break;
case V_155 :
case V_3 :
V_152 = V_156 ;
break;
case V_157 :
V_152 = V_158 ;
break;
case V_159 :
case V_2 :
V_152 = V_160 ;
break;
default:
F_43 ( L_2 ) ;
return;
}
V_145 = V_110 -> V_139 == ( 1 << 15 ) ;
V_146 = V_110 -> V_140 == ( 1 << 15 ) ;
V_149 = V_110 -> V_114 . V_137 ;
V_150 = V_110 -> V_114 . V_138 ;
V_151 = F_33 ( V_117 , 0 )
+ ( V_110 -> V_134 . V_137 * V_117 -> V_161 >> 3 )
+ ( V_110 -> V_134 . V_138 * V_117 -> V_126 [ 0 ] ) ;
V_147 = 0 ;
V_148 = 0 ;
if ( V_113 -> V_74 & V_125 )
F_34 ( V_77 , & V_14 -> V_74 ) ;
else
F_35 ( V_77 , & V_14 -> V_74 ) ;
F_36 ( & V_6 -> V_127 , V_74 ) ;
F_9 ( V_6 , F_17 ( V_64 ) ,
F_44 ( V_152 ) , V_162 ) ;
F_8 ( V_6 , F_45 ( V_64 ) ,
V_117 -> V_126 [ 0 ] / ( V_117 -> V_161 >> 3 ) ) ;
if ( V_14 -> V_80 == V_81 &&
V_64 == V_163 ) {
V_9 = F_46 ( V_113 -> V_142 ) ;
V_9 |= F_47 ( V_113 -> V_164 ) ;
F_8 ( V_6 , V_165 , V_9 ) ;
}
V_9 = F_48 ( V_110 -> V_134 . V_135 ) ;
V_9 |= F_49 ( V_110 -> V_134 . V_136 ) ;
V_9 |= F_50 ( V_145 ) ;
V_9 |= F_51 ( V_146 ) ;
F_8 ( V_6 , F_52 ( V_64 ) , V_9 ) ;
V_9 = F_53 ( V_147 ) ;
V_9 |= F_54 ( V_148 ) ;
F_8 ( V_6 , F_55 ( V_64 ) , V_9 ) ;
V_9 = F_56 ( V_149 ) ;
V_9 |= F_57 ( V_150 ) ;
F_8 ( V_6 , F_58 ( V_64 ) , V_9 ) ;
F_8 ( V_6 , F_59 ( V_64 ) , V_151 ) ;
F_21 ( V_14 , V_113 -> V_142 ) ;
F_22 ( V_14 , V_113 -> V_142 ) ;
F_23 ( V_14 , V_64 , V_95 , true ) ;
F_16 ( V_14 , V_64 , F_1 ( V_117 -> V_1 ) ) ;
if ( V_14 -> V_80 == V_166 ||
V_14 -> V_80 == V_81 )
F_41 ( V_14 ) ;
F_27 ( V_14 ) ;
F_40 ( & V_6 -> V_127 , V_74 ) ;
F_10 ( V_14 ) ;
}
static void F_60 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned int V_167 = 100 ;
F_4 ( V_6 , V_34 , V_168 ) ;
while ( V_167 -- ) {
if ( ~ F_2 ( V_6 , V_34 ) & V_168 )
break;
F_61 ( 10 ) ;
}
F_62 ( V_167 == 0 , L_3 ) ;
}
static void F_63 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned long V_74 ;
F_36 ( & V_6 -> V_127 , V_74 ) ;
F_9 ( V_6 , V_16 , V_169 , V_170 ) ;
F_9 ( V_6 , V_16 , V_171 , V_172 ) ;
F_9 ( V_6 , V_15 , V_173 ,
V_174 ) ;
F_8 ( V_6 , V_19 , 0 ) ;
F_8 ( V_6 , V_175 , 0x008080 ) ;
F_8 ( V_6 , V_176 , 0x008080 ) ;
F_8 ( V_6 , V_177 , 0x008080 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_60 ( V_14 ) ;
F_15 ( V_6 ) ;
}
F_9 ( V_6 , V_16 , 0 , V_96 ) ;
F_9 ( V_6 , V_16 , 0 , V_98 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) )
F_9 ( V_6 , V_16 , 0 , V_102 ) ;
F_40 ( & V_6 -> V_127 , V_74 ) ;
}
static T_4 F_64 ( int V_178 , void * V_179 )
{
struct V_13 * V_14 = V_179 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 , V_111 , V_180 ;
F_65 ( & V_6 -> V_127 ) ;
V_9 = F_7 ( V_6 , V_18 ) ;
if ( V_9 & V_181 ) {
V_9 |= V_182 ;
V_9 &= ~ V_181 ;
if ( F_20 ( V_77 , & V_14 -> V_74 ) ) {
V_111 = F_7 ( V_6 , F_59 ( 0 ) ) ;
V_180 = F_7 ( V_6 , F_66 ( 0 ) ) ;
if ( V_111 != V_180 )
goto V_183;
V_111 = F_7 ( V_6 , F_59 ( 1 ) ) ;
V_180 = F_7 ( V_6 , F_66 ( 1 ) ) ;
if ( V_111 != V_180 )
goto V_183;
}
F_67 ( & V_14 -> V_114 -> V_111 ) ;
}
V_183:
F_8 ( V_6 , V_18 , V_9 ) ;
F_68 ( & V_6 -> V_127 ) ;
return V_184 ;
}
static int F_69 ( struct V_13 * V_185 )
{
struct V_186 * V_187 = & V_185 -> V_188 -> V_187 ;
struct V_5 * V_66 = & V_185 -> V_66 ;
struct V_189 * V_6 ;
int V_190 ;
F_70 ( & V_66 -> V_127 ) ;
V_66 -> V_191 = F_71 ( V_187 , L_4 ) ;
if ( F_72 ( V_66 -> V_191 ) ) {
F_73 ( V_187 , L_5 ) ;
return - V_192 ;
}
V_66 -> V_193 = F_71 ( V_187 , L_6 ) ;
if ( F_72 ( V_66 -> V_193 ) ) {
F_73 ( V_187 , L_7 ) ;
return F_74 ( V_66 -> V_193 ) ;
}
V_66 -> V_194 = F_71 ( V_187 , L_8 ) ;
if ( F_72 ( V_66 -> V_194 ) ) {
F_73 ( V_187 , L_9 ) ;
return - V_192 ;
}
V_6 = F_75 ( V_185 -> V_188 , V_195 , 0 ) ;
if ( V_6 == NULL ) {
F_73 ( V_187 , L_10 ) ;
return - V_196 ;
}
V_66 -> V_12 = F_76 ( V_187 , V_6 -> V_197 ,
F_77 ( V_6 ) ) ;
if ( V_66 -> V_12 == NULL ) {
F_73 ( V_187 , L_11 ) ;
return - V_196 ;
}
V_6 = F_75 ( V_185 -> V_188 , V_198 , 0 ) ;
if ( V_6 == NULL ) {
F_73 ( V_187 , L_12 ) ;
return - V_196 ;
}
V_190 = F_78 ( V_187 , V_6 -> V_197 , F_64 ,
0 , L_13 , V_185 ) ;
if ( V_190 ) {
F_73 ( V_187 , L_14 ) ;
return V_190 ;
}
V_66 -> V_178 = V_6 -> V_197 ;
return 0 ;
}
static int F_79 ( struct V_13 * V_185 )
{
struct V_186 * V_187 = & V_185 -> V_188 -> V_187 ;
struct V_5 * V_66 = & V_185 -> V_66 ;
struct V_189 * V_6 ;
V_66 -> V_199 = F_71 ( V_187 , L_15 ) ;
if ( F_72 ( V_66 -> V_199 ) ) {
F_73 ( V_187 , L_16 ) ;
return - V_192 ;
}
if ( F_20 ( V_200 , & V_185 -> V_74 ) ) {
V_66 -> V_201 = F_71 ( V_187 , L_17 ) ;
if ( F_72 ( V_66 -> V_201 ) ) {
F_73 ( V_187 , L_18 ) ;
return - V_192 ;
}
V_66 -> V_202 = F_71 ( V_187 , L_19 ) ;
if ( F_72 ( V_66 -> V_202 ) ) {
F_73 ( V_187 , L_20 ) ;
return - V_192 ;
}
if ( V_66 -> V_194 && V_66 -> V_202 )
F_80 ( V_66 -> V_202 ,
V_66 -> V_194 ) ;
}
V_6 = F_75 ( V_185 -> V_188 , V_195 , 1 ) ;
if ( V_6 == NULL ) {
F_73 ( V_187 , L_10 ) ;
return - V_196 ;
}
V_66 -> V_8 = F_76 ( V_187 , V_6 -> V_197 ,
F_77 ( V_6 ) ) ;
if ( V_66 -> V_8 == NULL ) {
F_73 ( V_187 , L_11 ) ;
return - V_196 ;
}
return 0 ;
}
static int F_81 ( struct V_13 * V_185 ,
struct V_203 * V_204 )
{
int V_190 ;
struct V_205 * V_206 ;
V_206 = V_204 -> V_207 ;
V_185 -> V_204 = V_204 ;
V_185 -> V_208 = V_206 -> V_208 ++ ;
V_190 = F_69 ( V_185 ) ;
if ( V_190 ) {
F_32 ( L_21 , V_190 ) ;
return V_190 ;
}
if ( F_20 ( V_73 , & V_185 -> V_74 ) ) {
V_190 = F_79 ( V_185 ) ;
if ( V_190 ) {
F_32 ( L_22 , V_190 ) ;
return V_190 ;
}
}
V_190 = F_82 ( V_204 , V_185 -> V_187 ) ;
if ( V_190 )
V_206 -> V_208 -- ;
return V_190 ;
}
static void F_83 ( struct V_13 * V_185 )
{
F_84 ( V_185 -> V_204 , V_185 -> V_187 ) ;
}
static int F_85 ( struct V_209 * V_114 )
{
struct V_13 * V_185 = V_114 -> V_14 ;
struct V_5 * V_6 = & V_185 -> V_66 ;
F_34 ( V_210 , & V_185 -> V_74 ) ;
if ( ! F_20 ( V_211 , & V_185 -> V_74 ) )
return 0 ;
F_9 ( V_6 , V_18 , ~ 0 , V_182 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_212 ) ;
return 0 ;
}
static void F_86 ( struct V_209 * V_114 )
{
struct V_13 * V_185 = V_114 -> V_14 ;
struct V_5 * V_6 = & V_185 -> V_66 ;
F_35 ( V_210 , & V_185 -> V_74 ) ;
if ( ! F_20 ( V_211 , & V_185 -> V_74 ) )
return;
F_9 ( V_6 , V_18 , ~ 0 , V_182 ) ;
F_9 ( V_6 , V_17 , 0 , V_212 ) ;
}
static void F_87 ( struct V_209 * V_114 )
{
struct V_13 * V_185 = V_114 -> V_14 ;
if ( ! F_20 ( V_211 , & V_185 -> V_74 ) )
return;
F_19 ( V_185 , false ) ;
}
static void F_88 ( struct V_209 * V_114 ,
struct V_107 * V_108 )
{
struct V_13 * V_185 = V_114 -> V_14 ;
F_43 ( L_23 , V_108 -> V_143 ) ;
if ( ! F_20 ( V_211 , & V_185 -> V_74 ) )
return;
if ( V_108 -> V_143 == V_100 )
F_30 ( V_185 , V_108 ) ;
else
F_42 ( V_185 , V_108 ) ;
}
static void F_89 ( struct V_209 * V_114 ,
struct V_107 * V_108 )
{
struct V_13 * V_185 = V_114 -> V_14 ;
struct V_5 * V_6 = & V_185 -> V_66 ;
unsigned long V_74 ;
F_43 ( L_23 , V_108 -> V_143 ) ;
if ( ! F_20 ( V_211 , & V_185 -> V_74 ) )
return;
F_36 ( & V_6 -> V_127 , V_74 ) ;
F_23 ( V_185 , V_108 -> V_143 , 0 , false ) ;
F_40 ( & V_6 -> V_127 , V_74 ) ;
}
static void F_90 ( struct V_209 * V_114 )
{
struct V_13 * V_185 = V_114 -> V_14 ;
if ( ! F_20 ( V_211 , & V_185 -> V_74 ) )
return;
F_19 ( V_185 , true ) ;
}
static void F_91 ( struct V_209 * V_114 )
{
struct V_13 * V_14 = V_114 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
if ( F_20 ( V_211 , & V_14 -> V_74 ) )
return;
F_92 ( V_14 -> V_187 ) ;
F_93 ( V_114 , true ) ;
F_19 ( V_14 , false ) ;
F_9 ( V_6 , V_15 , ~ 0 , V_213 ) ;
if ( F_20 ( V_210 , & V_14 -> V_74 ) ) {
F_9 ( V_6 , V_18 , ~ 0 , V_182 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_212 ) ;
}
F_63 ( V_14 ) ;
F_19 ( V_14 , true ) ;
F_94 ( V_211 , & V_14 -> V_74 ) ;
}
static void F_95 ( struct V_209 * V_114 )
{
struct V_13 * V_14 = V_114 -> V_14 ;
int V_214 ;
if ( ! F_20 ( V_211 , & V_14 -> V_74 ) )
return;
F_28 ( V_14 ) ;
F_10 ( V_14 ) ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ )
F_89 ( V_114 , & V_14 -> V_216 [ V_214 ] ) ;
F_93 ( V_114 , false ) ;
F_96 ( V_14 -> V_187 ) ;
F_97 ( V_211 , & V_14 -> V_74 ) ;
}
static int F_98 ( struct V_209 * V_114 ,
struct V_217 * V_110 )
{
struct V_112 * V_113 = & V_110 -> V_115 ;
T_1 V_135 , V_136 ;
V_135 = V_113 -> V_164 ;
V_136 = V_113 -> V_142 ;
F_43 ( L_24 ,
V_113 -> V_164 , V_113 -> V_142 , V_113 -> V_218 ,
( V_113 -> V_74 & V_125 ) ? 1 : 0 ) ;
if ( ( V_135 >= 464 && V_135 <= 720 && V_136 >= 261 && V_136 <= 576 ) ||
( V_135 >= 1024 && V_135 <= 1280 && V_136 >= 576 && V_136 <= 720 ) ||
( V_135 >= 1664 && V_135 <= 1920 && V_136 >= 936 && V_136 <= 1080 ) )
return 0 ;
return - V_219 ;
}
static int F_99 ( struct V_186 * V_187 , struct V_186 * V_220 , void * V_56 )
{
struct V_13 * V_14 = F_100 ( V_187 ) ;
struct V_203 * V_204 = V_56 ;
struct V_107 * V_221 ;
unsigned int V_214 ;
int V_190 ;
V_190 = F_81 ( V_14 , V_204 ) ;
if ( V_190 )
return V_190 ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ ) {
if ( V_214 == V_100 && ! F_20 ( V_73 ,
& V_14 -> V_74 ) )
continue;
V_190 = F_101 ( V_204 , & V_14 -> V_216 [ V_214 ] , V_214 ,
1 << V_14 -> V_208 , & V_222 [ V_214 ] ) ;
if ( V_190 )
return V_190 ;
}
V_221 = & V_14 -> V_216 [ V_163 ] ;
V_14 -> V_114 = F_102 ( V_204 , & V_221 -> V_111 ,
V_14 -> V_208 , V_223 ,
& V_224 , V_14 ) ;
if ( F_72 ( V_14 -> V_114 ) ) {
F_83 ( V_14 ) ;
V_190 = F_74 ( V_14 -> V_114 ) ;
goto V_225;
}
return 0 ;
V_225:
F_103 ( V_187 , V_14 ) ;
return V_190 ;
}
static void F_104 ( struct V_186 * V_187 , struct V_186 * V_226 , void * V_56 )
{
struct V_13 * V_14 = F_100 ( V_187 ) ;
F_83 ( V_14 ) ;
}
static int F_105 ( struct V_227 * V_188 )
{
struct V_186 * V_187 = & V_188 -> V_187 ;
const struct V_228 * V_229 ;
struct V_13 * V_14 ;
int V_190 ;
V_14 = F_106 ( & V_188 -> V_187 , sizeof( * V_14 ) , V_230 ) ;
if ( ! V_14 ) {
F_32 ( L_25 ) ;
return - V_231 ;
}
V_229 = F_107 ( V_187 ) ;
V_14 -> V_188 = V_188 ;
V_14 -> V_187 = V_187 ;
V_14 -> V_80 = V_229 -> V_232 ;
if ( V_229 -> V_233 )
F_34 ( V_73 , & V_14 -> V_74 ) ;
if ( V_229 -> V_234 )
F_34 ( V_200 , & V_14 -> V_74 ) ;
F_108 ( V_188 , V_14 ) ;
V_190 = F_109 ( & V_188 -> V_187 , & V_235 ) ;
if ( ! V_190 )
F_110 ( V_187 ) ;
return V_190 ;
}
static int F_111 ( struct V_227 * V_188 )
{
F_112 ( & V_188 -> V_187 ) ;
F_113 ( & V_188 -> V_187 , & V_235 ) ;
return 0 ;
}
static int T_5 F_114 ( struct V_186 * V_187 )
{
struct V_13 * V_14 = F_100 ( V_187 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
F_115 ( V_6 -> V_193 ) ;
F_115 ( V_6 -> V_191 ) ;
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
F_115 ( V_6 -> V_199 ) ;
if ( F_20 ( V_200 , & V_14 -> V_74 ) )
F_115 ( V_6 -> V_201 ) ;
}
return 0 ;
}
static int T_5 F_116 ( struct V_186 * V_187 )
{
struct V_13 * V_14 = F_100 ( V_187 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_190 ;
V_190 = F_117 ( V_6 -> V_191 ) ;
if ( V_190 < 0 ) {
F_32 ( L_26 , V_190 ) ;
return V_190 ;
}
V_190 = F_117 ( V_6 -> V_193 ) ;
if ( V_190 < 0 ) {
F_32 ( L_27 , V_190 ) ;
return V_190 ;
}
if ( F_20 ( V_73 , & V_14 -> V_74 ) ) {
V_190 = F_117 ( V_6 -> V_199 ) ;
if ( V_190 < 0 ) {
F_32 ( L_28 ,
V_190 ) ;
return V_190 ;
}
if ( F_20 ( V_200 , & V_14 -> V_74 ) ) {
V_190 = F_117 ( V_6 -> V_201 ) ;
if ( V_190 < 0 ) {
F_32 ( L_29 \
L_30 ,
V_190 ) ;
return V_190 ;
}
}
}
return 0 ;
}
