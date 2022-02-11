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
if ( V_14 -> V_73 )
F_4 ( V_6 , V_35 , V_71 ?
V_74 : 0 ) ;
}
static void F_20 ( struct V_13 * V_14 , unsigned int V_75 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 ;
V_9 = ( V_14 -> V_76 ? V_77 :
V_78 ) ;
if ( V_14 -> V_79 != V_80 ) {
if ( V_75 <= 480 )
V_9 |= V_81 | V_82 ;
else if ( V_75 <= 576 )
V_9 |= V_83 | V_82 ;
else if ( V_75 <= 720 )
V_9 |= V_84 | V_85 ;
else if ( V_75 <= 1080 )
V_9 |= V_86 | V_85 ;
else
V_9 |= V_84 | V_85 ;
}
F_9 ( V_6 , V_16 , V_9 , V_87 ) ;
}
static void F_21 ( struct V_13 * V_14 , unsigned int V_75 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 ;
if ( V_75 == 480 ) {
V_9 = V_88 ;
} else if ( V_75 == 576 ) {
V_9 = V_88 ;
} else if ( V_75 == 720 ) {
V_9 = V_89 ;
F_8 ( V_6 , V_90 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_8 ( V_6 , V_91 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_8 ( V_6 , V_92 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else if ( V_75 == 1080 ) {
V_9 = V_89 ;
F_8 ( V_6 , V_90 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_8 ( V_6 , V_91 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_8 ( V_6 , V_92 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else {
V_9 = V_89 ;
F_8 ( V_6 , V_90 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_8 ( V_6 , V_91 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_8 ( V_6 , V_92 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
}
F_9 ( V_6 , V_16 , V_9 , V_93 ) ;
}
static void F_22 ( struct V_13 * V_14 , unsigned int V_64 ,
unsigned int V_94 , bool V_71 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 = V_71 ? ~ 0 : 0 ;
switch ( V_64 ) {
case 0 :
F_9 ( V_6 , V_16 , V_9 , V_95 ) ;
F_9 ( V_6 , V_19 ,
F_23 ( V_94 ) ,
V_96 ) ;
break;
case 1 :
F_9 ( V_6 , V_16 , V_9 , V_97 ) ;
F_9 ( V_6 , V_19 ,
F_24 ( V_94 ) ,
V_98 ) ;
break;
case V_99 :
if ( V_14 -> V_73 ) {
F_6 ( V_6 , V_33 , V_9 , V_100 ) ;
F_9 ( V_6 , V_16 , V_9 ,
V_101 ) ;
F_9 ( V_6 , V_19 ,
F_25 ( V_94 ) ,
V_102 ) ;
}
break;
}
}
static void F_26 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_15 , ~ 0 , V_103 ) ;
}
static void F_27 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_104 = 20 ;
F_9 ( V_6 , V_15 , 0 , V_103 ) ;
while ( ! ( F_7 ( V_6 , V_15 ) & V_105 ) &&
-- V_104 )
F_28 ( 10000 , 12000 ) ;
}
static void F_29 ( struct V_13 * V_14 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 =
F_30 ( V_107 -> V_110 . V_109 ) ;
struct V_111 * V_112 = & V_109 -> V_110 . V_113 -> V_109 -> V_114 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_115 * V_116 = V_109 -> V_110 . V_116 ;
unsigned long V_117 ;
T_3 V_118 [ 2 ] , V_119 [ 2 ] ;
bool V_120 = false ;
bool V_121 = false ;
T_1 V_9 ;
switch ( V_116 -> V_1 ) {
case V_122 :
V_121 = false ;
break;
case V_123 :
V_121 = true ;
break;
default:
F_31 ( L_1 ,
V_116 -> V_1 ) ;
return;
}
V_118 [ 0 ] = F_32 ( V_116 , 0 ) ;
V_119 [ 0 ] = F_32 ( V_116 , 1 ) ;
if ( V_112 -> V_117 & V_124 ) {
V_14 -> V_76 = true ;
if ( V_120 ) {
V_118 [ 1 ] = V_118 [ 0 ] + 0x40 ;
V_119 [ 1 ] = V_119 [ 0 ] + 0x40 ;
} else {
V_118 [ 1 ] = V_118 [ 0 ] + V_116 -> V_125 [ 0 ] ;
V_119 [ 1 ] = V_119 [ 0 ] + V_116 -> V_125 [ 0 ] ;
}
} else {
V_14 -> V_76 = false ;
V_118 [ 1 ] = 0 ;
V_119 [ 1 ] = 0 ;
}
F_33 ( & V_6 -> V_126 , V_117 ) ;
V_9 = ( V_14 -> V_76 ? ~ 0 : 0 ) ;
F_6 ( V_6 , V_37 , V_9 , V_127 ) ;
V_9 = ( V_121 ? V_128 : V_129 ) ;
V_9 |= ( V_120 ? V_130 : V_131 ) ;
F_6 ( V_6 , V_37 , V_9 , V_132 ) ;
F_4 ( V_6 , V_38 , F_34 ( V_116 -> V_125 [ 0 ] ) |
F_35 ( V_116 -> V_75 ) ) ;
F_4 ( V_6 , V_39 , F_34 ( V_116 -> V_125 [ 0 ] ) |
F_35 ( V_116 -> V_75 / 2 ) ) ;
F_4 ( V_6 , V_48 , V_109 -> V_133 . V_134 ) ;
F_4 ( V_6 , V_49 , V_109 -> V_133 . V_135 ) ;
F_4 ( V_6 , V_46 ,
F_36 ( V_109 -> V_133 . V_136 ) ) ;
F_4 ( V_6 , V_47 , V_109 -> V_133 . V_137 ) ;
F_4 ( V_6 , V_52 , V_109 -> V_113 . V_134 ) ;
F_4 ( V_6 , V_50 , V_109 -> V_113 . V_136 ) ;
if ( V_14 -> V_76 ) {
F_4 ( V_6 , V_53 , V_109 -> V_113 . V_135 / 2 ) ;
F_4 ( V_6 , V_51 , V_109 -> V_113 . V_137 / 2 ) ;
} else {
F_4 ( V_6 , V_53 , V_109 -> V_113 . V_135 ) ;
F_4 ( V_6 , V_51 , V_109 -> V_113 . V_137 ) ;
}
F_4 ( V_6 , V_54 , V_109 -> V_138 ) ;
F_4 ( V_6 , V_55 , V_109 -> V_139 ) ;
F_4 ( V_6 , V_45 , V_140 ) ;
F_4 ( V_6 , V_41 , V_118 [ 0 ] ) ;
F_4 ( V_6 , V_42 , V_118 [ 1 ] ) ;
F_4 ( V_6 , V_43 , V_119 [ 0 ] ) ;
F_4 ( V_6 , V_44 , V_119 [ 1 ] ) ;
F_20 ( V_14 , V_112 -> V_141 ) ;
F_21 ( V_14 , V_112 -> V_141 ) ;
F_22 ( V_14 , V_107 -> V_142 , V_109 -> V_143 + 1 , true ) ;
F_18 ( V_14 ) ;
F_26 ( V_14 ) ;
F_37 ( & V_6 -> V_126 , V_117 ) ;
F_10 ( V_14 ) ;
F_12 ( V_14 ) ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
F_9 ( V_6 , V_16 , ~ 0 , V_144 ) ;
}
static void F_39 ( struct V_13 * V_14 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 =
F_30 ( V_107 -> V_110 . V_109 ) ;
struct V_111 * V_112 = & V_109 -> V_110 . V_113 -> V_109 -> V_114 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
struct V_115 * V_116 = V_109 -> V_110 . V_116 ;
unsigned long V_117 ;
unsigned int V_64 = V_107 -> V_142 ;
unsigned int V_145 = 0 , V_146 = 0 ;
unsigned int V_147 , V_148 , V_149 , V_150 ;
T_3 V_151 ;
unsigned int V_152 ;
T_1 V_9 ;
switch ( V_116 -> V_1 ) {
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
F_40 ( L_2 ) ;
return;
}
V_145 = V_109 -> V_138 == ( 1 << 15 ) ;
V_146 = V_109 -> V_139 == ( 1 << 15 ) ;
V_149 = V_109 -> V_113 . V_136 ;
V_150 = V_109 -> V_113 . V_137 ;
V_151 = F_32 ( V_116 , 0 )
+ ( V_109 -> V_133 . V_136 * V_116 -> V_161 >> 3 )
+ ( V_109 -> V_133 . V_137 * V_116 -> V_125 [ 0 ] ) ;
V_147 = 0 ;
V_148 = 0 ;
if ( V_112 -> V_117 & V_124 )
V_14 -> V_76 = true ;
else
V_14 -> V_76 = false ;
F_33 ( & V_6 -> V_126 , V_117 ) ;
F_9 ( V_6 , F_17 ( V_64 ) ,
F_41 ( V_152 ) , V_162 ) ;
F_8 ( V_6 , F_42 ( V_64 ) ,
V_116 -> V_125 [ 0 ] / ( V_116 -> V_161 >> 3 ) ) ;
if ( V_14 -> V_79 == V_80 &&
V_64 == V_163 ) {
V_9 = F_43 ( V_112 -> V_141 ) ;
V_9 |= F_44 ( V_112 -> V_164 ) ;
F_8 ( V_6 , V_165 , V_9 ) ;
}
V_9 = F_45 ( V_109 -> V_133 . V_134 ) ;
V_9 |= F_46 ( V_109 -> V_133 . V_135 ) ;
V_9 |= F_47 ( V_145 ) ;
V_9 |= F_48 ( V_146 ) ;
F_8 ( V_6 , F_49 ( V_64 ) , V_9 ) ;
V_9 = F_50 ( V_147 ) ;
V_9 |= F_51 ( V_148 ) ;
F_8 ( V_6 , F_52 ( V_64 ) , V_9 ) ;
V_9 = F_53 ( V_149 ) ;
V_9 |= F_54 ( V_150 ) ;
F_8 ( V_6 , F_55 ( V_64 ) , V_9 ) ;
F_8 ( V_6 , F_56 ( V_64 ) , V_151 ) ;
F_20 ( V_14 , V_112 -> V_141 ) ;
F_21 ( V_14 , V_112 -> V_141 ) ;
F_22 ( V_14 , V_64 , V_109 -> V_143 + 1 , true ) ;
F_16 ( V_14 , V_64 , F_1 ( V_116 -> V_1 ) ) ;
if ( V_14 -> V_79 == V_166 ||
V_14 -> V_79 == V_80 )
F_38 ( V_14 ) ;
F_26 ( V_14 ) ;
F_37 ( & V_6 -> V_126 , V_117 ) ;
F_10 ( V_14 ) ;
}
static void F_57 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_167 = 100 ;
F_4 ( V_6 , V_34 , V_168 ) ;
for ( V_167 = 100 ; V_167 ; -- V_167 ) {
if ( ~ F_2 ( V_6 , V_34 ) & V_168 )
break;
F_58 ( 10 ) ;
}
F_59 ( V_167 == 0 , L_3 ) ;
}
static void F_60 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_66 ;
unsigned long V_117 ;
F_33 ( & V_6 -> V_126 , V_117 ) ;
F_9 ( V_6 , V_16 , V_169 , V_170 ) ;
F_9 ( V_6 , V_16 , V_171 , V_172 ) ;
F_9 ( V_6 , V_15 , V_173 ,
V_174 ) ;
F_8 ( V_6 , V_19 , 0 ) ;
F_8 ( V_6 , V_175 , 0x008080 ) ;
F_8 ( V_6 , V_176 , 0x008080 ) ;
F_8 ( V_6 , V_177 , 0x008080 ) ;
if ( V_14 -> V_73 ) {
F_57 ( V_14 ) ;
F_15 ( V_6 ) ;
}
F_9 ( V_6 , V_16 , 0 , V_95 ) ;
F_9 ( V_6 , V_16 , 0 , V_97 ) ;
if ( V_14 -> V_73 )
F_9 ( V_6 , V_16 , 0 , V_101 ) ;
F_37 ( & V_6 -> V_126 , V_117 ) ;
}
static T_4 F_61 ( int V_178 , void * V_179 )
{
struct V_13 * V_14 = V_179 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
T_1 V_9 , V_110 , V_180 ;
int V_64 ;
F_62 ( & V_6 -> V_126 ) ;
V_9 = F_7 ( V_6 , V_18 ) ;
if ( V_9 & V_181 ) {
V_9 |= V_182 ;
V_9 &= ~ V_181 ;
if ( V_14 -> V_76 ) {
V_110 = F_7 ( V_6 , F_56 ( 0 ) ) ;
V_180 = F_7 ( V_6 , F_63 ( 0 ) ) ;
if ( V_110 != V_180 )
goto V_183;
V_110 = F_7 ( V_6 , F_56 ( 1 ) ) ;
V_180 = F_7 ( V_6 , F_63 ( 1 ) ) ;
if ( V_110 != V_180 )
goto V_183;
}
F_64 ( & V_14 -> V_113 -> V_110 ) ;
for ( V_64 = 0 ; V_64 < V_184 ; V_64 ++ ) {
struct V_106 * V_107 = & V_14 -> V_185 [ V_64 ] ;
if ( ! V_107 -> V_186 )
continue;
F_65 ( V_14 -> V_113 , V_107 ) ;
}
}
V_183:
F_8 ( V_6 , V_18 , V_9 ) ;
F_66 ( & V_6 -> V_126 ) ;
return V_187 ;
}
static int F_67 ( struct V_13 * V_188 )
{
struct V_189 * V_190 = & V_188 -> V_191 -> V_190 ;
struct V_5 * V_66 = & V_188 -> V_66 ;
struct V_192 * V_6 ;
int V_193 ;
F_68 ( & V_66 -> V_126 ) ;
V_66 -> V_194 = F_69 ( V_190 , L_4 ) ;
if ( F_70 ( V_66 -> V_194 ) ) {
F_71 ( V_190 , L_5 ) ;
return - V_195 ;
}
V_66 -> V_196 = F_69 ( V_190 , L_6 ) ;
if ( F_70 ( V_66 -> V_196 ) ) {
F_71 ( V_190 , L_7 ) ;
return F_72 ( V_66 -> V_196 ) ;
}
V_66 -> V_197 = F_69 ( V_190 , L_8 ) ;
if ( F_70 ( V_66 -> V_197 ) ) {
F_71 ( V_190 , L_9 ) ;
return - V_195 ;
}
V_6 = F_73 ( V_188 -> V_191 , V_198 , 0 ) ;
if ( V_6 == NULL ) {
F_71 ( V_190 , L_10 ) ;
return - V_199 ;
}
V_66 -> V_12 = F_74 ( V_190 , V_6 -> V_200 ,
F_75 ( V_6 ) ) ;
if ( V_66 -> V_12 == NULL ) {
F_71 ( V_190 , L_11 ) ;
return - V_199 ;
}
V_6 = F_73 ( V_188 -> V_191 , V_201 , 0 ) ;
if ( V_6 == NULL ) {
F_71 ( V_190 , L_12 ) ;
return - V_199 ;
}
V_193 = F_76 ( V_190 , V_6 -> V_200 , F_61 ,
0 , L_13 , V_188 ) ;
if ( V_193 ) {
F_71 ( V_190 , L_14 ) ;
return V_193 ;
}
V_66 -> V_178 = V_6 -> V_200 ;
return 0 ;
}
static int F_77 ( struct V_13 * V_188 )
{
struct V_189 * V_190 = & V_188 -> V_191 -> V_190 ;
struct V_5 * V_66 = & V_188 -> V_66 ;
struct V_192 * V_6 ;
V_66 -> V_202 = F_69 ( V_190 , L_15 ) ;
if ( F_70 ( V_66 -> V_202 ) ) {
F_71 ( V_190 , L_16 ) ;
return - V_195 ;
}
if ( V_188 -> V_203 ) {
V_66 -> V_204 = F_69 ( V_190 , L_17 ) ;
if ( F_70 ( V_66 -> V_204 ) ) {
F_71 ( V_190 , L_18 ) ;
return - V_195 ;
}
V_66 -> V_205 = F_69 ( V_190 , L_19 ) ;
if ( F_70 ( V_66 -> V_205 ) ) {
F_71 ( V_190 , L_20 ) ;
return - V_195 ;
}
if ( V_66 -> V_197 && V_66 -> V_205 )
F_78 ( V_66 -> V_205 ,
V_66 -> V_197 ) ;
}
V_6 = F_73 ( V_188 -> V_191 , V_198 , 1 ) ;
if ( V_6 == NULL ) {
F_71 ( V_190 , L_10 ) ;
return - V_199 ;
}
V_66 -> V_8 = F_74 ( V_190 , V_6 -> V_200 ,
F_75 ( V_6 ) ) ;
if ( V_66 -> V_8 == NULL ) {
F_71 ( V_190 , L_11 ) ;
return - V_199 ;
}
return 0 ;
}
static int F_79 ( struct V_13 * V_188 ,
struct V_206 * V_207 )
{
int V_193 ;
struct V_208 * V_209 ;
V_209 = V_207 -> V_210 ;
V_188 -> V_207 = V_207 ;
V_188 -> V_211 = V_209 -> V_211 ++ ;
V_193 = F_67 ( V_188 ) ;
if ( V_193 ) {
F_31 ( L_21 , V_193 ) ;
return V_193 ;
}
if ( V_188 -> V_73 ) {
V_193 = F_77 ( V_188 ) ;
if ( V_193 ) {
F_31 ( L_22 , V_193 ) ;
return V_193 ;
}
}
V_193 = F_80 ( V_207 , V_188 -> V_190 ) ;
if ( V_193 )
V_209 -> V_211 -- ;
return V_193 ;
}
static void F_81 ( struct V_13 * V_188 )
{
F_82 ( V_188 -> V_207 , V_188 -> V_190 ) ;
}
static int F_83 ( struct V_212 * V_113 )
{
struct V_13 * V_188 = V_113 -> V_14 ;
struct V_5 * V_6 = & V_188 -> V_66 ;
F_84 ( V_213 , & V_188 -> V_117 ) ;
if ( ! F_85 ( V_214 , & V_188 -> V_117 ) )
return 0 ;
F_9 ( V_6 , V_18 , ~ 0 , V_182 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_215 ) ;
return 0 ;
}
static void F_86 ( struct V_212 * V_113 )
{
struct V_13 * V_188 = V_113 -> V_14 ;
struct V_5 * V_6 = & V_188 -> V_66 ;
F_87 ( V_213 , & V_188 -> V_117 ) ;
if ( ! F_85 ( V_214 , & V_188 -> V_117 ) )
return;
F_9 ( V_6 , V_18 , ~ 0 , V_182 ) ;
F_9 ( V_6 , V_17 , 0 , V_215 ) ;
}
static void F_88 ( struct V_212 * V_113 )
{
struct V_13 * V_188 = V_113 -> V_14 ;
if ( ! F_85 ( V_214 , & V_188 -> V_117 ) )
return;
F_19 ( V_188 , false ) ;
}
static void F_89 ( struct V_212 * V_113 ,
struct V_106 * V_107 )
{
struct V_13 * V_188 = V_113 -> V_14 ;
F_40 ( L_23 , V_107 -> V_142 ) ;
if ( ! F_85 ( V_214 , & V_188 -> V_117 ) )
return;
if ( V_107 -> V_142 == V_99 )
F_29 ( V_188 , V_107 ) ;
else
F_39 ( V_188 , V_107 ) ;
}
static void F_90 ( struct V_212 * V_113 ,
struct V_106 * V_107 )
{
struct V_13 * V_188 = V_113 -> V_14 ;
struct V_5 * V_6 = & V_188 -> V_66 ;
unsigned long V_117 ;
F_40 ( L_23 , V_107 -> V_142 ) ;
if ( ! F_85 ( V_214 , & V_188 -> V_117 ) )
return;
F_33 ( & V_6 -> V_126 , V_117 ) ;
F_22 ( V_188 , V_107 -> V_142 , 0 , false ) ;
F_37 ( & V_6 -> V_126 , V_117 ) ;
}
static void F_91 ( struct V_212 * V_113 )
{
struct V_13 * V_188 = V_113 -> V_14 ;
if ( ! F_85 ( V_214 , & V_188 -> V_117 ) )
return;
F_19 ( V_188 , true ) ;
}
static void F_92 ( struct V_212 * V_113 )
{
struct V_13 * V_14 = V_113 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_66 ;
if ( F_85 ( V_214 , & V_14 -> V_117 ) )
return;
F_93 ( V_14 -> V_190 ) ;
F_94 ( V_113 , true ) ;
F_19 ( V_14 , false ) ;
F_9 ( V_6 , V_15 , ~ 0 , V_216 ) ;
if ( F_85 ( V_213 , & V_14 -> V_117 ) ) {
F_9 ( V_6 , V_18 , ~ 0 , V_182 ) ;
F_9 ( V_6 , V_17 , ~ 0 , V_215 ) ;
}
F_60 ( V_14 ) ;
F_19 ( V_14 , true ) ;
F_95 ( V_214 , & V_14 -> V_117 ) ;
}
static void F_96 ( struct V_212 * V_113 )
{
struct V_13 * V_14 = V_113 -> V_14 ;
int V_217 ;
if ( ! F_85 ( V_214 , & V_14 -> V_117 ) )
return;
F_27 ( V_14 ) ;
F_10 ( V_14 ) ;
for ( V_217 = 0 ; V_217 < V_184 ; V_217 ++ )
F_90 ( V_113 , & V_14 -> V_185 [ V_217 ] ) ;
F_94 ( V_113 , false ) ;
F_97 ( V_14 -> V_190 ) ;
F_98 ( V_214 , & V_14 -> V_117 ) ;
}
static int F_99 ( struct V_212 * V_113 ,
struct V_218 * V_109 )
{
struct V_111 * V_112 = & V_109 -> V_114 ;
T_1 V_134 , V_135 ;
V_134 = V_112 -> V_164 ;
V_135 = V_112 -> V_141 ;
F_40 ( L_24 ,
V_112 -> V_164 , V_112 -> V_141 , V_112 -> V_219 ,
( V_112 -> V_117 & V_124 ) ? 1 : 0 ) ;
if ( ( V_134 >= 464 && V_134 <= 720 && V_135 >= 261 && V_135 <= 576 ) ||
( V_134 >= 1024 && V_134 <= 1280 && V_135 >= 576 && V_135 <= 720 ) ||
( V_134 >= 1664 && V_134 <= 1920 && V_135 >= 936 && V_135 <= 1080 ) )
return 0 ;
return - V_220 ;
}
static int F_100 ( struct V_189 * V_190 , struct V_189 * V_221 , void * V_56 )
{
struct V_13 * V_14 = F_101 ( V_190 ) ;
struct V_206 * V_207 = V_56 ;
struct V_106 * V_222 ;
unsigned int V_217 ;
int V_193 ;
V_193 = F_79 ( V_14 , V_207 ) ;
if ( V_193 )
return V_193 ;
for ( V_217 = 0 ; V_217 < V_184 ; V_217 ++ ) {
if ( V_217 == V_99 && ! V_14 -> V_73 )
continue;
V_193 = F_102 ( V_207 , & V_14 -> V_185 [ V_217 ] , V_217 ,
1 << V_14 -> V_211 , & V_223 [ V_217 ] ) ;
if ( V_193 )
return V_193 ;
}
V_222 = & V_14 -> V_185 [ V_163 ] ;
V_14 -> V_113 = F_103 ( V_207 , & V_222 -> V_110 ,
V_14 -> V_211 , V_224 ,
& V_225 , V_14 ) ;
if ( F_70 ( V_14 -> V_113 ) ) {
F_81 ( V_14 ) ;
V_193 = F_72 ( V_14 -> V_113 ) ;
goto V_226;
}
return 0 ;
V_226:
F_104 ( V_190 , V_14 ) ;
return V_193 ;
}
static void F_105 ( struct V_189 * V_190 , struct V_189 * V_227 , void * V_56 )
{
struct V_13 * V_14 = F_101 ( V_190 ) ;
F_81 ( V_14 ) ;
}
static int F_106 ( struct V_228 * V_191 )
{
struct V_189 * V_190 = & V_191 -> V_190 ;
const struct V_229 * V_230 ;
struct V_13 * V_14 ;
int V_193 ;
V_14 = F_107 ( & V_191 -> V_190 , sizeof( * V_14 ) , V_231 ) ;
if ( ! V_14 ) {
F_31 ( L_25 ) ;
return - V_232 ;
}
V_230 = F_108 ( V_190 ) ;
V_14 -> V_191 = V_191 ;
V_14 -> V_190 = V_190 ;
V_14 -> V_73 = V_230 -> V_233 ;
V_14 -> V_203 = V_230 -> V_203 ;
V_14 -> V_79 = V_230 -> V_234 ;
F_109 ( V_191 , V_14 ) ;
V_193 = F_110 ( & V_191 -> V_190 , & V_235 ) ;
if ( ! V_193 )
F_111 ( V_190 ) ;
return V_193 ;
}
static int F_112 ( struct V_228 * V_191 )
{
F_113 ( & V_191 -> V_190 ) ;
F_114 ( & V_191 -> V_190 , & V_235 ) ;
return 0 ;
}
static int T_5 F_115 ( struct V_189 * V_190 )
{
struct V_13 * V_14 = F_101 ( V_190 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
F_116 ( V_6 -> V_196 ) ;
F_116 ( V_6 -> V_194 ) ;
if ( V_14 -> V_73 ) {
F_116 ( V_6 -> V_202 ) ;
if ( V_14 -> V_203 )
F_116 ( V_6 -> V_204 ) ;
}
return 0 ;
}
static int T_5 F_117 ( struct V_189 * V_190 )
{
struct V_13 * V_14 = F_101 ( V_190 ) ;
struct V_5 * V_6 = & V_14 -> V_66 ;
int V_193 ;
V_193 = F_118 ( V_6 -> V_194 ) ;
if ( V_193 < 0 ) {
F_31 ( L_26 , V_193 ) ;
return V_193 ;
}
V_193 = F_118 ( V_6 -> V_196 ) ;
if ( V_193 < 0 ) {
F_31 ( L_27 , V_193 ) ;
return V_193 ;
}
if ( V_14 -> V_73 ) {
V_193 = F_118 ( V_6 -> V_202 ) ;
if ( V_193 < 0 ) {
F_31 ( L_28 ,
V_193 ) ;
return V_193 ;
}
if ( V_14 -> V_203 ) {
V_193 = F_118 ( V_6 -> V_204 ) ;
if ( V_193 < 0 ) {
F_31 ( L_29 \
L_30 ,
V_193 ) ;
return V_193 ;
}
}
}
return 0 ;
}
