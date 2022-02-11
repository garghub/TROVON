static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
int F_4 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_16 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_20 ) ; V_19 ++ ) {
F_7 ( V_9 , L_1 ,
V_20 [ V_19 ] . V_21 , V_20 [ V_19 ] . V_22 ,
F_8 ( V_20 [ V_19 ] . V_22 ) ) ;
}
for ( V_19 = 0 ; V_19 < F_6 ( V_23 ) ; V_19 ++ ) {
F_7 ( V_9 , L_1 ,
V_23 [ V_19 ] . V_21 , V_23 [ V_19 ] . V_22 ,
F_9 ( V_23 [ V_19 ] . V_22 ) ) ;
}
return 0 ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_20 ) ; V_19 ++ ) {
F_11 ( L_2 ,
V_20 [ V_19 ] . V_22 , V_20 [ V_19 ] . V_21 ,
F_8 ( V_20 [ V_19 ] . V_22 ) ) ;
}
for ( V_19 = 0 ; V_19 < F_6 ( V_23 ) ; V_19 ++ ) {
F_11 ( L_2 ,
V_23 [ V_19 ] . V_22 , V_23 [ V_19 ] . V_21 ,
F_9 ( V_23 [ V_19 ] . V_22 ) ) ;
}
}
static enum V_24
F_12 ( struct V_6 * V_7 , bool V_25 )
{
struct V_14 * V_15 = V_7 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
if ( V_18 -> V_26 -> V_27 ) {
if ( F_13 ( V_18 -> V_26 -> V_27 ) ^
V_18 -> V_26 -> V_28 )
return V_29 ;
else
return V_30 ;
}
if ( F_14 ( V_18 -> V_26 -> V_31 ) )
return V_29 ;
if ( F_8 ( V_32 ) & V_33 )
return V_29 ;
else
return V_30 ;
}
static void F_15 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_5 * V_34 =
F_3 ( V_7 ) ;
struct V_2 * V_3 = V_34 -> V_3 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_36 = 0 ;
struct V_37 * V_37 ;
V_37 = F_19 ( V_7 , V_18 -> V_26 -> V_31 ) ;
if ( ! V_37 )
return - V_38 ;
V_35 -> V_39 = F_20 ( V_37 ) ;
if ( V_37 && V_37 -> V_40 & V_41 ) {
V_35 -> V_42 =
F_21 ( V_37 ) ;
}
F_22 ( V_7 , V_37 ) ;
V_36 = F_23 ( V_7 , V_37 ) ;
F_24 ( V_7 , V_37 ) ;
return V_36 ;
}
static struct V_6 * F_25 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_43 ;
int V_36 = 0 ;
V_43 = F_26 ( V_15 -> V_15 , sizeof( * V_43 ) ,
V_44 ) ;
if ( ! V_43 ) {
V_36 = - V_45 ;
goto V_46;
}
V_7 = & V_43 -> V_4 ;
V_43 -> V_3 = V_3 ;
F_27 ( V_15 , V_7 , & V_47 ,
V_48 ) ;
F_28 ( V_7 , & V_49 ) ;
V_7 -> V_50 = ( V_51 |
V_52 ) ;
V_7 -> V_53 = 1 ;
V_7 -> V_54 = 0 ;
F_29 ( V_7 , V_3 ) ;
return V_7 ;
V_46:
if ( V_7 )
F_15 ( V_7 ) ;
return F_30 ( V_36 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
F_32 ( V_3 ) ;
}
static int F_33 ( struct V_2 * V_3 ,
enum V_55 type )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
T_1 V_56 = type - 0x80 ;
F_34 ( V_57 ,
F_8 ( V_57 ) & ~ F_35 ( V_56 ) ) ;
return F_36 ( ! ( F_8 ( V_58 ) &
F_35 ( V_56 ) ) , 100 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
union V_59 * V_60 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
T_1 V_56 = V_60 -> V_61 . type - 0x80 ;
T_1 V_62 = F_38 ( V_56 ) ;
T_2 V_63 [ V_64 ] ;
T_3 V_65 , V_19 ;
int V_36 ;
F_39 ( ! ( F_8 ( V_57 ) &
V_66 ) ,
L_3 ) ;
V_65 = F_40 ( V_60 , V_63 , sizeof( V_63 ) ) ;
if ( V_65 < 0 )
return;
V_36 = F_33 ( V_3 , V_60 -> V_61 . type ) ;
if ( V_36 ) {
F_41 ( L_4 , V_36 ) ;
return;
}
for ( V_19 = 0 ; V_19 < V_65 ; V_19 += 7 ) {
F_34 ( V_62 ,
V_63 [ V_19 + 0 ] << 0 |
V_63 [ V_19 + 1 ] << 8 |
V_63 [ V_19 + 2 ] << 16 ) ;
V_62 += 4 ;
F_34 ( V_62 ,
V_63 [ V_19 + 3 ] << 0 |
V_63 [ V_19 + 4 ] << 8 |
V_63 [ V_19 + 5 ] << 16 |
V_63 [ V_19 + 6 ] << 24 ) ;
V_62 += 4 ;
}
F_34 ( V_57 ,
F_8 ( V_57 ) | F_35 ( V_56 ) ) ;
V_36 = F_36 ( ( F_8 ( V_58 ) &
F_35 ( V_56 ) ) , 100 ) ;
if ( V_36 )
F_41 ( L_5 , V_36 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_67 * V_68 = V_3 -> V_68 ;
const struct V_69 * V_70 = & V_68 -> V_71 -> V_72 ;
union V_59 V_60 ;
int V_36 ;
V_36 = F_43 ( & V_60 . V_73 , V_70 ) ;
if ( V_36 < 0 ) {
F_41 ( L_6 ) ;
return;
}
F_44 ( & V_60 . V_73 , V_70 ,
V_35 -> V_74 ?
V_75 :
V_76 ,
V_35 -> V_42 ) ;
F_37 ( V_3 , & V_60 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
union V_59 V_60 ;
int V_36 ;
V_36 = F_46 ( & V_60 . V_77 , L_7 , L_8 ) ;
if ( V_36 < 0 ) {
F_41 ( L_9 ) ;
return;
}
V_60 . V_77 . V_78 = V_79 ;
F_37 ( V_3 , & V_60 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_17 * V_18 = V_80 -> V_81 ;
struct V_82 * V_26 = V_18 -> V_26 ;
union V_59 V_60 ;
int V_36 ;
V_36 = F_48 ( & V_60 . V_83 ) ;
V_60 . V_83 . V_84 = V_85 ;
V_60 . V_83 . V_86 = V_87 ;
V_60 . V_83 . V_88 = V_89 ;
V_60 . V_83 . V_90 = V_26 -> V_83 . V_90 ;
F_37 ( V_3 , & V_60 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_42 ( V_3 ) ;
F_45 ( V_3 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
struct V_82 * V_26 = V_18 -> V_26 ;
int V_36 ;
F_34 ( V_57 , 0 ) ;
F_34 ( V_91 , 0xf << 16 ) ;
F_51 ( V_92 ,
F_9 ( V_92 ) & ~ V_93 ) ;
F_51 ( V_94 , V_95 ) ;
F_52 ( 1 ) ;
F_51 ( V_94 , 0 ) ;
F_53 ( V_26 -> V_96 ) ;
F_53 ( V_26 -> V_97 ) ;
V_36 = F_54 ( & V_26 -> V_98 -> V_15 ) ;
if ( V_36 < 0 )
F_41 ( L_10 , V_36 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_69 * V_70 = & V_3 -> V_68 -> V_71 -> V_72 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
struct V_82 * V_26 = V_18 -> V_26 ;
bool V_99 = false ;
bool V_100 = V_70 -> V_101 & V_102 ;
bool V_103 = V_70 -> V_101 & V_104 ;
bool V_105 = V_70 -> V_101 & V_106 ;
T_1 V_107 = ( V_70 -> V_101 & V_108 ) ? 2 : 1 ;
T_1 V_109 = ( F_56 ( V_70 -> V_110 - V_70 -> V_111 ,
V_112 ) |
F_56 ( V_70 -> V_111 - V_70 -> V_113 ,
V_114 ) |
F_56 ( V_70 -> V_113 , V_115 ) ) ;
T_1 V_116 = ( F_56 ( 0 , V_117 ) |
F_56 ( V_70 -> V_118 - V_70 -> V_110 ,
V_119 ) ) ;
T_1 V_120 = ( F_56 ( 0 , V_117 ) |
F_56 ( V_70 -> V_118 -
V_70 -> V_110 -
V_105 ,
V_119 ) ) ;
T_1 V_121 ;
int V_36 ;
V_36 = F_57 ( & V_26 -> V_98 -> V_15 ) ;
if ( V_36 < 0 ) {
F_41 ( L_11 , V_36 ) ;
return;
}
V_36 = F_58 ( V_26 -> V_96 , 163682864 ) ;
if ( V_36 ) {
F_41 ( L_12 , V_36 ) ;
return;
}
V_36 = F_58 ( V_26 -> V_97 ,
V_70 -> clock * 1000 *
( ( V_70 -> V_101 & V_108 ) ? 2 : 1 ) ) ;
if ( V_36 ) {
F_41 ( L_13 , V_36 ) ;
return;
}
V_36 = F_59 ( V_26 -> V_97 ) ;
if ( V_36 ) {
F_41 ( L_14 , V_36 ) ;
return;
}
V_36 = F_59 ( V_26 -> V_96 ) ;
if ( V_36 ) {
F_41 ( L_15 ,
V_36 ) ;
F_53 ( V_26 -> V_97 ) ;
return;
}
F_51 ( V_94 , V_95 ) ;
F_52 ( 1 ) ;
F_51 ( V_94 , 0 ) ;
F_51 ( V_94 , V_122 ) ;
F_34 ( V_123 ,
V_124 |
V_125 ) ;
F_34 ( V_123 , 0 ) ;
F_34 ( V_91 , 0xf << 16 ) ;
F_34 ( V_91 , 0 ) ;
if ( V_99 ) {
F_11 ( L_16 ) ;
F_10 ( V_15 ) ;
}
F_51 ( V_92 , 0 ) ;
F_34 ( V_126 ,
F_8 ( V_126 ) |
V_127 |
V_128 ) ;
F_34 ( V_129 ,
( V_103 ? V_130 : 0 ) |
( V_100 ? V_131 : 0 ) |
F_56 ( V_70 -> V_132 * V_107 ,
V_133 ) ) ;
F_34 ( V_134 ,
F_56 ( ( V_70 -> V_135 -
V_70 -> V_136 ) * V_107 ,
V_137 ) |
F_56 ( ( V_70 -> V_136 -
V_70 -> V_138 ) * V_107 ,
V_139 ) |
F_56 ( ( V_70 -> V_138 -
V_70 -> V_132 ) * V_107 ,
V_140 ) ) ;
F_34 ( V_141 , V_109 ) ;
F_34 ( V_142 , V_109 ) ;
F_34 ( V_143 , V_120 ) ;
F_34 ( V_144 , V_116 ) ;
F_51 ( V_92 ,
( V_103 ? 0 : V_145 ) |
( V_100 ? 0 : V_146 ) ) ;
V_121 = F_56 ( V_147 ,
V_148 ) ;
if ( V_35 -> V_39 &&
F_60 ( V_70 ) ==
V_75 ) {
V_121 |= V_149 ;
V_121 |= V_150 ;
V_121 |= F_56 ( V_151 ,
V_152 ) ;
F_51 ( V_153 , ( 0x000 << 16 ) | 0x000 ) ;
F_51 ( V_154 , ( 0x100 << 16 ) | 0x6e0 ) ;
F_51 ( V_155 , ( 0x6e0 << 16 ) | 0x000 ) ;
F_51 ( V_156 , ( 0x100 << 16 ) | 0x000 ) ;
F_51 ( V_157 , ( 0x000 << 16 ) | 0x6e0 ) ;
F_51 ( V_158 , ( 0x100 << 16 ) | 0x000 ) ;
V_35 -> V_74 = true ;
} else {
V_35 -> V_74 = false ;
}
F_51 ( V_159 , V_121 ) ;
F_34 ( V_160 , V_161 ) ;
if ( V_99 ) {
F_11 ( L_17 ) ;
F_10 ( V_15 ) ;
}
F_51 ( V_92 ,
F_9 ( V_92 ) |
V_93 |
V_162 |
V_163 ) ;
if ( V_35 -> V_39 ) {
F_34 ( V_126 ,
F_8 ( V_126 ) |
V_164 ) ;
V_36 = F_36 ( F_8 ( V_126 ) &
V_165 , 1000 ) ;
F_39 ( V_36 , L_18
L_19 ) ;
} else {
F_34 ( V_57 ,
F_8 ( V_57 ) &
~ ( V_66 ) ) ;
F_34 ( V_126 ,
F_8 ( V_126 ) &
~ V_164 ) ;
V_36 = F_36 ( ! ( F_8 ( V_126 ) &
V_165 ) , 1000 ) ;
F_39 ( V_36 , L_18
L_20 ) ;
}
if ( V_35 -> V_39 ) {
T_1 V_166 ;
F_61 ( ! ( F_8 ( V_126 ) &
V_165 ) ) ;
F_34 ( V_126 ,
F_8 ( V_126 ) |
V_167 ) ;
F_34 ( V_57 ,
V_66 ) ;
F_49 ( V_3 ) ;
V_166 = F_8 ( V_160 ) ;
V_166 &= V_168 ;
F_34 ( V_160 ,
V_166 & ~ V_169 ) ;
F_34 ( V_160 ,
V_166 | V_169 ) ;
F_52 ( 1000 ) ;
F_34 ( V_160 ,
V_166 & ~ V_169 ) ;
F_34 ( V_160 ,
V_166 | V_169 ) ;
V_36 = F_36 ( F_8 ( V_160 ) &
V_170 , 1 ) ;
F_39 ( V_36 , L_18
L_21 ) ;
}
}
static void F_62 ( struct V_82 * V_26 )
{
struct V_14 * V_80 = V_26 -> V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
T_1 V_96 = F_63 ( V_26 -> V_96 ) ;
unsigned long V_171 , V_9 ;
F_64 ( V_96 , V_26 -> V_83 . V_172 ,
V_173 >>
V_174 ,
( V_175 >>
V_176 ) + 1 ,
& V_171 , & V_9 ) ;
F_51 ( V_177 ,
F_56 ( V_171 , V_178 ) |
F_56 ( V_9 - 1 , V_179 ) ) ;
}
static void F_65 ( struct V_82 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_67 * V_68 = V_3 -> V_68 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
const struct V_69 * V_70 = & V_68 -> V_71 -> V_72 ;
T_1 V_172 = V_26 -> V_83 . V_172 ;
T_1 V_171 , V_180 ;
T_4 V_181 ;
V_171 = 128 * V_172 / 1000 ;
V_181 = ( T_4 ) ( V_70 -> clock * 1000 ) * V_171 ;
F_66 ( V_181 , 128 * V_172 ) ;
V_180 = V_181 ;
F_34 ( V_182 ,
V_183 |
F_56 ( V_171 , V_184 ) ) ;
F_34 ( V_185 , V_180 ) ;
F_34 ( V_186 , V_180 ) ;
}
static inline struct V_82 * F_67 ( struct V_187 * V_188 )
{
struct V_189 * V_190 = F_68 ( V_188 ) ;
return F_69 ( V_190 ) ;
}
static int F_70 ( struct V_191 * V_192 ,
struct V_187 * V_188 )
{
struct V_82 * V_26 = F_67 ( V_188 ) ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_17 * V_18 = F_5 ( V_3 -> V_15 ) ;
int V_36 ;
if ( V_26 -> V_83 . V_192 && V_26 -> V_83 . V_192 != V_192 )
return - V_193 ;
V_26 -> V_83 . V_192 = V_192 ;
if ( ! V_3 -> V_68 || ! ( F_8 ( V_57 ) &
V_66 ) )
return - V_38 ;
V_36 = F_71 ( V_192 -> V_194 ,
V_26 -> V_7 -> V_195 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
static int F_72 ( struct V_187 * V_188 , unsigned int V_196 )
{
return 0 ;
}
static void F_73 ( struct V_82 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_197 * V_15 = & V_26 -> V_98 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
int V_36 ;
V_36 = F_33 ( V_3 , V_198 ) ;
if ( V_36 )
F_74 ( V_15 , L_22 , V_36 ) ;
F_51 ( V_199 , V_200 ) ;
F_51 ( V_199 , V_201 ) ;
F_51 ( V_199 , V_202 ) ;
}
static void F_75 ( struct V_191 * V_192 ,
struct V_187 * V_188 )
{
struct V_82 * V_26 = F_67 ( V_188 ) ;
if ( V_192 != V_26 -> V_83 . V_192 )
return;
F_73 ( V_26 ) ;
V_26 -> V_83 . V_192 = NULL ;
}
static int F_76 ( struct V_191 * V_192 ,
struct V_203 * V_204 ,
struct V_187 * V_188 )
{
struct V_82 * V_26 = F_67 ( V_188 ) ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_197 * V_15 = & V_26 -> V_98 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
T_1 V_205 , V_206 ;
T_1 V_207 , V_19 ;
if ( V_192 != V_26 -> V_83 . V_192 )
return - V_193 ;
F_77 ( V_15 , L_23 , V_208 ,
F_78 ( V_204 ) , F_79 ( V_204 ) ,
F_80 ( V_204 ) ) ;
V_26 -> V_83 . V_90 = F_80 ( V_204 ) ;
V_26 -> V_83 . V_172 = F_78 ( V_204 ) ;
F_51 ( V_199 ,
V_200 |
V_202 |
V_209 |
V_210 |
V_201 ) ;
F_62 ( V_26 ) ;
V_205 =
V_211 |
V_212 |
F_56 ( 0xf , V_213 ) ;
V_206 = F_81 ( V_26 -> V_83 . V_90 - 1 , 0 ) ;
V_205 |= F_56 ( V_206 ,
V_214 ) ;
if ( V_26 -> V_83 . V_172 > 96000 ) {
F_51 ( V_215 ,
F_56 ( 0x12 , V_216 ) |
F_56 ( 0x12 , V_217 ) ) ;
} else if ( V_26 -> V_83 . V_172 > 48000 ) {
F_51 ( V_215 ,
F_56 ( 0x14 , V_216 ) |
F_56 ( 0x12 , V_217 ) ) ;
} else {
F_51 ( V_215 ,
F_56 ( 0x10 , V_218 ) |
F_56 ( 0x10 , V_219 ) |
F_56 ( 0x10 , V_216 ) |
F_56 ( 0x10 , V_217 ) ) ;
}
F_34 ( V_220 ,
V_221 |
F_56 ( V_206 , V_222 ) ) ;
V_207 = 0 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_206 & F_35 ( V_19 ) )
V_207 |= V_19 << ( 3 * V_19 ) ;
}
F_34 ( V_223 , V_207 ) ;
F_34 ( V_224 , V_205 ) ;
F_65 ( V_26 ) ;
return 0 ;
}
static int F_82 ( struct V_191 * V_192 , int V_225 ,
struct V_187 * V_188 )
{
struct V_82 * V_26 = F_67 ( V_188 ) ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
switch ( V_225 ) {
case V_226 :
F_47 ( V_3 ) ;
F_34 ( V_227 ,
F_8 ( V_227 ) &
~ V_228 ) ;
F_51 ( V_199 ,
F_56 ( V_26 -> V_83 . V_90 ,
V_229 ) |
V_230 ) ;
break;
case V_231 :
F_51 ( V_199 ,
V_209 |
V_210 |
V_201 ) ;
F_34 ( V_227 ,
F_8 ( V_227 ) |
V_228 ) ;
break;
default:
break;
}
return 0 ;
}
static inline struct V_82 *
F_83 ( struct V_232 * V_233 )
{
struct V_189 * V_190 = F_84 ( V_233 ) ;
return F_69 ( V_190 ) ;
}
static int F_85 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_232 * V_233 = F_86 ( V_235 ) ;
struct V_82 * V_26 = F_83 ( V_233 ) ;
V_237 -> type = V_238 ;
V_237 -> V_239 = sizeof( V_26 -> V_7 -> V_195 ) ;
return 0 ;
}
static int F_87 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_232 * V_233 = F_86 ( V_235 ) ;
struct V_82 * V_26 = F_83 ( V_233 ) ;
memcpy ( V_241 -> V_242 . V_243 . V_244 , V_26 -> V_7 -> V_195 ,
sizeof( V_26 -> V_7 -> V_195 ) ) ;
return 0 ;
}
static int F_88 ( struct V_187 * V_188 )
{
struct V_82 * V_26 = F_67 ( V_188 ) ;
F_89 ( V_188 , & V_26 -> V_83 . V_245 , NULL ) ;
return 0 ;
}
static int F_90 ( struct V_82 * V_26 )
{
struct V_246 * V_247 = & V_26 -> V_83 . V_248 ;
struct V_189 * V_190 = & V_26 -> V_83 . V_190 ;
struct V_197 * V_15 = & V_26 -> V_98 -> V_15 ;
const T_5 * V_249 ;
int V_36 ;
if ( ! F_91 ( V_15 -> V_250 , L_24 , NULL ) ) {
F_92 ( V_15 ,
L_25 ) ;
return 0 ;
}
V_249 = F_93 ( V_15 -> V_250 , 1 , NULL , NULL ) ;
V_26 -> V_83 . V_245 . V_249 = F_94 ( V_249 ) + V_251 ;
V_26 -> V_83 . V_245 . V_252 = V_253 ;
V_26 -> V_83 . V_245 . V_254 = 2 ;
V_36 = F_95 ( V_15 , & V_255 , 0 ) ;
if ( V_36 ) {
F_74 ( V_15 , L_26 , V_36 ) ;
return V_36 ;
}
V_36 = F_96 ( V_15 , & V_256 ,
& V_257 , 1 ) ;
if ( V_36 ) {
F_74 ( V_15 , L_27 , V_36 ) ;
return V_36 ;
}
V_36 = F_97 ( V_15 , & V_258 ,
& V_259 , 1 ) ;
if ( V_36 ) {
F_74 ( V_15 , L_28 , V_36 ) ;
return V_36 ;
}
V_247 -> V_21 = L_29 ;
V_247 -> V_260 = L_30 ;
V_247 -> V_261 = V_259 . V_21 ;
V_247 -> V_262 = F_98 ( V_15 ) ;
V_247 -> V_263 = F_98 ( V_15 ) ;
V_247 -> V_264 = F_98 ( V_15 ) ;
V_190 -> V_247 = V_247 ;
V_190 -> V_265 = 1 ;
V_190 -> V_21 = L_31 ;
V_190 -> V_15 = V_15 ;
F_99 ( V_190 , V_26 ) ;
V_36 = F_100 ( V_15 , V_190 ) ;
if ( V_36 ) {
F_74 ( V_15 , L_32 , V_36 ) ;
goto V_266;
}
return 0 ;
V_266:
F_101 ( V_15 ) ;
return V_36 ;
}
static void F_102 ( struct V_82 * V_26 )
{
struct V_197 * V_15 = & V_26 -> V_98 -> V_15 ;
if ( F_103 ( V_15 ) )
F_101 ( V_15 ) ;
}
static int F_104 ( struct V_197 * V_15 , struct V_197 * V_267 , void * V_244 )
{
struct V_268 * V_98 = F_105 ( V_15 ) ;
struct V_14 * V_80 = F_103 ( V_267 ) ;
struct V_17 * V_18 = V_80 -> V_81 ;
struct V_82 * V_26 ;
struct V_1 * V_1 ;
struct V_269 * V_270 ;
T_1 V_242 ;
int V_36 ;
V_26 = F_26 ( V_15 , sizeof( * V_26 ) , V_44 ) ;
if ( ! V_26 )
return - V_45 ;
V_1 = F_26 ( V_15 , sizeof( * V_1 ) ,
V_44 ) ;
if ( ! V_1 )
return - V_45 ;
V_1 -> V_4 . type = V_271 ;
V_26 -> V_3 = & V_1 -> V_4 . V_4 ;
V_26 -> V_98 = V_98 ;
V_26 -> V_272 = F_106 ( V_98 , 0 ) ;
if ( F_107 ( V_26 -> V_272 ) )
return F_108 ( V_26 -> V_272 ) ;
V_26 -> V_23 = F_106 ( V_98 , 1 ) ;
if ( F_107 ( V_26 -> V_23 ) )
return F_108 ( V_26 -> V_23 ) ;
V_26 -> V_97 = F_109 ( V_15 , L_33 ) ;
if ( F_107 ( V_26 -> V_97 ) ) {
F_41 ( L_34 ) ;
return F_108 ( V_26 -> V_97 ) ;
}
V_26 -> V_96 = F_109 ( V_15 , L_35 ) ;
if ( F_107 ( V_26 -> V_96 ) ) {
F_41 ( L_36 ) ;
return F_108 ( V_26 -> V_96 ) ;
}
V_270 = F_110 ( V_15 -> V_250 , L_37 , 0 ) ;
if ( ! V_270 ) {
F_41 ( L_38 ) ;
return - V_38 ;
}
V_26 -> V_31 = F_111 ( V_270 ) ;
F_112 ( V_270 ) ;
if ( ! V_26 -> V_31 ) {
F_113 ( L_39 ) ;
return - V_273 ;
}
if ( F_91 ( V_15 -> V_250 , L_40 , & V_242 ) ) {
enum V_274 V_275 ;
V_26 -> V_27 = F_114 ( V_15 -> V_250 ,
L_40 , 0 ,
& V_275 ) ;
if ( V_26 -> V_27 < 0 ) {
V_36 = V_26 -> V_27 ;
goto V_276;
}
V_26 -> V_28 = V_275 & V_277 ;
}
V_18 -> V_26 = V_26 ;
F_115 ( V_15 ) ;
F_116 ( V_80 , V_26 -> V_3 , & V_278 ,
V_279 , NULL ) ;
F_117 ( V_26 -> V_3 , & V_280 ) ;
V_26 -> V_7 = F_25 ( V_80 , V_26 -> V_3 ) ;
if ( F_107 ( V_26 -> V_7 ) ) {
V_36 = F_108 ( V_26 -> V_7 ) ;
goto V_281;
}
V_36 = F_90 ( V_26 ) ;
if ( V_36 )
goto V_281;
return 0 ;
V_281:
F_31 ( V_26 -> V_3 ) ;
F_118 ( V_15 ) ;
V_276:
F_119 ( & V_26 -> V_31 -> V_15 ) ;
return V_36 ;
}
static void F_120 ( struct V_197 * V_15 , struct V_197 * V_267 ,
void * V_244 )
{
struct V_14 * V_80 = F_103 ( V_267 ) ;
struct V_17 * V_18 = V_80 -> V_81 ;
struct V_82 * V_26 = V_18 -> V_26 ;
F_102 ( V_26 ) ;
F_15 ( V_26 -> V_7 ) ;
F_31 ( V_26 -> V_3 ) ;
F_118 ( V_15 ) ;
F_119 ( & V_26 -> V_31 -> V_15 ) ;
V_18 -> V_26 = NULL ;
}
static int F_121 ( struct V_268 * V_98 )
{
return F_122 ( & V_98 -> V_15 , & V_282 ) ;
}
static int F_123 ( struct V_268 * V_98 )
{
F_124 ( & V_98 -> V_15 , & V_282 ) ;
return 0 ;
}
