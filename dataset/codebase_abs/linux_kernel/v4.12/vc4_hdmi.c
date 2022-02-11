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
static void F_50 ( struct V_2 * V_3 ,
struct V_69 * V_91 ,
struct V_69 * V_70 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
bool V_92 = false ;
bool V_93 = V_70 -> V_94 & V_95 ;
bool V_96 = V_70 -> V_94 & V_97 ;
bool V_98 = V_70 -> V_94 & V_99 ;
T_1 V_100 = ( V_70 -> V_94 & V_101 ) ? 2 : 1 ;
T_1 V_102 = ( F_51 ( V_70 -> V_103 - V_70 -> V_104 ,
V_105 ) |
F_51 ( V_70 -> V_104 - V_70 -> V_106 ,
V_107 ) |
F_51 ( V_70 -> V_106 , V_108 ) ) ;
T_1 V_109 = ( F_51 ( 0 , V_110 ) |
F_51 ( V_70 -> V_111 - V_70 -> V_103 ,
V_112 ) ) ;
T_1 V_113 = ( F_51 ( 0 , V_110 ) |
F_51 ( V_70 -> V_111 -
V_70 -> V_103 -
V_98 ,
V_112 ) ) ;
T_1 V_114 ;
if ( V_92 ) {
F_11 ( L_10 ) ;
F_10 ( V_15 ) ;
}
F_52 ( V_115 , 0 ) ;
F_53 ( V_18 -> V_26 -> V_116 , V_70 -> clock * 1000 *
( ( V_70 -> V_94 & V_101 ) ? 2 : 1 ) ) ;
F_34 ( V_117 ,
F_8 ( V_117 ) |
V_118 |
V_119 ) ;
F_34 ( V_120 ,
( V_96 ? V_121 : 0 ) |
( V_93 ? V_122 : 0 ) |
F_51 ( V_70 -> V_123 * V_100 ,
V_124 ) ) ;
F_34 ( V_125 ,
F_51 ( ( V_70 -> V_126 -
V_70 -> V_127 ) * V_100 ,
V_128 ) |
F_51 ( ( V_70 -> V_127 -
V_70 -> V_129 ) * V_100 ,
V_130 ) |
F_51 ( ( V_70 -> V_129 -
V_70 -> V_123 ) * V_100 ,
V_131 ) ) ;
F_34 ( V_132 , V_102 ) ;
F_34 ( V_133 , V_102 ) ;
F_34 ( V_134 , V_113 ) ;
F_34 ( V_135 , V_109 ) ;
F_52 ( V_115 ,
( V_96 ? 0 : V_136 ) |
( V_93 ? 0 : V_137 ) ) ;
V_114 = F_51 ( V_138 ,
V_139 ) ;
if ( V_35 -> V_39 &&
F_54 ( V_70 ) ==
V_75 ) {
V_114 |= V_140 ;
V_114 |= V_141 ;
V_114 |= F_51 ( V_142 ,
V_143 ) ;
F_52 ( V_144 , ( 0x000 << 16 ) | 0x000 ) ;
F_52 ( V_145 , ( 0x100 << 16 ) | 0x6e0 ) ;
F_52 ( V_146 , ( 0x6e0 << 16 ) | 0x000 ) ;
F_52 ( V_147 , ( 0x100 << 16 ) | 0x000 ) ;
F_52 ( V_148 , ( 0x000 << 16 ) | 0x6e0 ) ;
F_52 ( V_149 , ( 0x100 << 16 ) | 0x000 ) ;
V_35 -> V_74 = true ;
} else {
V_35 -> V_74 = false ;
}
F_52 ( V_150 , V_114 ) ;
F_34 ( V_151 , V_152 ) ;
if ( V_92 ) {
F_11 ( L_11 ) ;
F_10 ( V_15 ) ;
}
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
F_34 ( V_57 , 0 ) ;
F_34 ( V_153 , 0xf << 16 ) ;
F_52 ( V_115 ,
F_9 ( V_115 ) & ~ V_154 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_36 ;
F_34 ( V_153 , 0 ) ;
F_52 ( V_115 ,
F_9 ( V_115 ) |
V_154 |
V_155 |
V_156 ) ;
if ( V_35 -> V_39 ) {
F_34 ( V_117 ,
F_8 ( V_117 ) |
V_157 ) ;
V_36 = F_36 ( F_8 ( V_117 ) &
V_158 , 1000 ) ;
F_39 ( V_36 , L_12
L_13 ) ;
} else {
F_34 ( V_57 ,
F_8 ( V_57 ) &
~ ( V_66 ) ) ;
F_34 ( V_117 ,
F_8 ( V_117 ) &
~ V_157 ) ;
V_36 = F_36 ( ! ( F_8 ( V_117 ) &
V_158 ) , 1000 ) ;
F_39 ( V_36 , L_12
L_14 ) ;
}
if ( V_35 -> V_39 ) {
T_1 V_159 ;
F_57 ( ! ( F_8 ( V_117 ) &
V_158 ) ) ;
F_34 ( V_117 ,
F_8 ( V_117 ) |
V_160 ) ;
F_34 ( V_57 ,
V_66 ) ;
F_49 ( V_3 ) ;
V_159 = F_8 ( V_151 ) ;
V_159 &= V_161 ;
F_34 ( V_151 ,
V_159 & ~ V_162 ) ;
F_34 ( V_151 ,
V_159 | V_162 ) ;
F_58 ( 1000 ) ;
F_34 ( V_151 ,
V_159 & ~ V_162 ) ;
F_34 ( V_151 ,
V_159 | V_162 ) ;
V_36 = F_36 ( F_8 ( V_151 ) &
V_163 , 1 ) ;
F_39 ( V_36 , L_12
L_15 ) ;
}
}
static void F_59 ( struct V_82 * V_26 )
{
struct V_14 * V_80 = V_26 -> V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
T_1 V_164 = F_60 ( V_26 -> V_164 ) ;
unsigned long V_165 , V_9 ;
F_61 ( V_164 , V_26 -> V_83 . V_166 ,
V_167 >>
V_168 ,
( V_169 >>
V_170 ) + 1 ,
& V_165 , & V_9 ) ;
F_52 ( V_171 ,
F_51 ( V_165 , V_172 ) |
F_51 ( V_9 - 1 , V_173 ) ) ;
}
static void F_62 ( struct V_82 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_67 * V_68 = V_3 -> V_68 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
const struct V_69 * V_70 = & V_68 -> V_71 -> V_72 ;
T_1 V_166 = V_26 -> V_83 . V_166 ;
T_1 V_165 , V_174 ;
T_4 V_175 ;
V_165 = 128 * V_166 / 1000 ;
V_175 = ( T_4 ) ( V_70 -> clock * 1000 ) * V_165 ;
F_63 ( V_175 , 128 * V_166 ) ;
V_174 = V_175 ;
F_34 ( V_176 ,
V_177 |
F_51 ( V_165 , V_178 ) ) ;
F_34 ( V_179 , V_174 ) ;
F_34 ( V_180 , V_174 ) ;
}
static inline struct V_82 * F_64 ( struct V_181 * V_182 )
{
struct V_183 * V_184 = F_65 ( V_182 ) ;
return F_66 ( V_184 ) ;
}
static int F_67 ( struct V_185 * V_186 ,
struct V_181 * V_182 )
{
struct V_82 * V_26 = F_64 ( V_182 ) ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_17 * V_18 = F_5 ( V_3 -> V_15 ) ;
int V_36 ;
if ( V_26 -> V_83 . V_186 && V_26 -> V_83 . V_186 != V_186 )
return - V_187 ;
V_26 -> V_83 . V_186 = V_186 ;
if ( ! V_3 -> V_68 || ! ( F_8 ( V_57 ) &
V_66 ) )
return - V_38 ;
V_36 = F_68 ( V_186 -> V_188 ,
V_26 -> V_7 -> V_189 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
static int F_69 ( struct V_181 * V_182 , unsigned int V_190 )
{
return 0 ;
}
static void F_70 ( struct V_82 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_191 * V_15 = & V_26 -> V_192 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
int V_36 ;
V_36 = F_33 ( V_3 , V_193 ) ;
if ( V_36 )
F_71 ( V_15 , L_16 , V_36 ) ;
F_52 ( V_194 , V_195 ) ;
F_52 ( V_194 , V_196 ) ;
F_52 ( V_194 , V_197 ) ;
}
static void F_72 ( struct V_185 * V_186 ,
struct V_181 * V_182 )
{
struct V_82 * V_26 = F_64 ( V_182 ) ;
if ( V_186 != V_26 -> V_83 . V_186 )
return;
F_70 ( V_26 ) ;
V_26 -> V_83 . V_186 = NULL ;
}
static int F_73 ( struct V_185 * V_186 ,
struct V_198 * V_199 ,
struct V_181 * V_182 )
{
struct V_82 * V_26 = F_64 ( V_182 ) ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_191 * V_15 = & V_26 -> V_192 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
T_1 V_200 , V_201 ;
T_1 V_202 , V_19 ;
if ( V_186 != V_26 -> V_83 . V_186 )
return - V_187 ;
F_74 ( V_15 , L_17 , V_203 ,
F_75 ( V_199 ) , F_76 ( V_199 ) ,
F_77 ( V_199 ) ) ;
V_26 -> V_83 . V_90 = F_77 ( V_199 ) ;
V_26 -> V_83 . V_166 = F_75 ( V_199 ) ;
F_52 ( V_194 ,
V_195 |
V_197 |
V_204 |
V_205 |
V_196 ) ;
F_59 ( V_26 ) ;
V_200 =
V_206 |
V_207 |
F_51 ( 0xf , V_208 ) ;
V_201 = F_78 ( V_26 -> V_83 . V_90 - 1 , 0 ) ;
V_200 |= F_51 ( V_201 ,
V_209 ) ;
if ( V_26 -> V_83 . V_166 > 96000 ) {
F_52 ( V_210 ,
F_51 ( 0x12 , V_211 ) |
F_51 ( 0x12 , V_212 ) ) ;
} else if ( V_26 -> V_83 . V_166 > 48000 ) {
F_52 ( V_210 ,
F_51 ( 0x14 , V_211 ) |
F_51 ( 0x12 , V_212 ) ) ;
} else {
F_52 ( V_210 ,
F_51 ( 0x10 , V_213 ) |
F_51 ( 0x10 , V_214 ) |
F_51 ( 0x10 , V_211 ) |
F_51 ( 0x10 , V_212 ) ) ;
}
F_34 ( V_215 ,
V_216 |
F_51 ( V_201 , V_217 ) ) ;
V_202 = 0 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_201 & F_35 ( V_19 ) )
V_202 |= V_19 << ( 3 * V_19 ) ;
}
F_34 ( V_218 , V_202 ) ;
F_34 ( V_219 , V_200 ) ;
F_62 ( V_26 ) ;
return 0 ;
}
static int F_79 ( struct V_185 * V_186 , int V_220 ,
struct V_181 * V_182 )
{
struct V_82 * V_26 = F_64 ( V_182 ) ;
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_14 * V_80 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_80 ) ;
switch ( V_220 ) {
case V_221 :
F_47 ( V_3 ) ;
F_34 ( V_222 ,
F_8 ( V_222 ) &
~ V_223 ) ;
F_52 ( V_194 ,
F_51 ( V_26 -> V_83 . V_90 ,
V_224 ) |
V_225 ) ;
break;
case V_226 :
F_52 ( V_194 ,
V_204 |
V_205 |
V_196 ) ;
F_34 ( V_222 ,
F_8 ( V_222 ) |
V_223 ) ;
break;
default:
break;
}
return 0 ;
}
static inline struct V_82 *
F_80 ( struct V_227 * V_228 )
{
struct V_183 * V_184 = F_81 ( V_228 ) ;
return F_66 ( V_184 ) ;
}
static int F_82 ( struct V_229 * V_230 ,
struct V_231 * V_232 )
{
struct V_227 * V_228 = F_83 ( V_230 ) ;
struct V_82 * V_26 = F_80 ( V_228 ) ;
V_232 -> type = V_233 ;
V_232 -> V_234 = sizeof( V_26 -> V_7 -> V_189 ) ;
return 0 ;
}
static int F_84 ( struct V_229 * V_230 ,
struct V_235 * V_236 )
{
struct V_227 * V_228 = F_83 ( V_230 ) ;
struct V_82 * V_26 = F_80 ( V_228 ) ;
memcpy ( V_236 -> V_237 . V_238 . V_239 , V_26 -> V_7 -> V_189 ,
sizeof( V_26 -> V_7 -> V_189 ) ) ;
return 0 ;
}
static int F_85 ( struct V_181 * V_182 )
{
struct V_82 * V_26 = F_64 ( V_182 ) ;
F_86 ( V_182 , & V_26 -> V_83 . V_240 , NULL ) ;
return 0 ;
}
static int F_87 ( struct V_82 * V_26 )
{
struct V_241 * V_242 = & V_26 -> V_83 . V_243 ;
struct V_183 * V_184 = & V_26 -> V_83 . V_184 ;
struct V_191 * V_15 = & V_26 -> V_192 -> V_15 ;
const T_5 * V_244 ;
int V_36 ;
if ( ! F_88 ( V_15 -> V_245 , L_18 , NULL ) ) {
F_89 ( V_15 ,
L_19 ) ;
return 0 ;
}
V_244 = F_90 ( V_15 -> V_245 , 1 , NULL , NULL ) ;
V_26 -> V_83 . V_240 . V_244 = F_91 ( V_244 ) + V_246 ;
V_26 -> V_83 . V_240 . V_247 = V_248 ;
V_26 -> V_83 . V_240 . V_249 = 2 ;
V_36 = F_92 ( V_15 , & V_250 , 0 ) ;
if ( V_36 ) {
F_71 ( V_15 , L_20 , V_36 ) ;
return V_36 ;
}
V_36 = F_93 ( V_15 , & V_251 ,
& V_252 , 1 ) ;
if ( V_36 ) {
F_71 ( V_15 , L_21 , V_36 ) ;
return V_36 ;
}
V_36 = F_94 ( V_15 , & V_253 ,
& V_254 , 1 ) ;
if ( V_36 ) {
F_71 ( V_15 , L_22 , V_36 ) ;
return V_36 ;
}
V_242 -> V_21 = L_23 ;
V_242 -> V_255 = L_24 ;
V_242 -> V_256 = V_254 . V_21 ;
V_242 -> V_257 = F_95 ( V_15 ) ;
V_242 -> V_258 = F_95 ( V_15 ) ;
V_242 -> V_259 = F_95 ( V_15 ) ;
V_184 -> V_242 = V_242 ;
V_184 -> V_260 = 1 ;
V_184 -> V_21 = L_25 ;
V_184 -> V_15 = V_15 ;
F_96 ( V_184 , V_26 ) ;
V_36 = F_97 ( V_15 , V_184 ) ;
if ( V_36 ) {
F_71 ( V_15 , L_26 , V_36 ) ;
goto V_261;
}
return 0 ;
V_261:
F_98 ( V_15 ) ;
return V_36 ;
}
static void F_99 ( struct V_82 * V_26 )
{
struct V_191 * V_15 = & V_26 -> V_192 -> V_15 ;
if ( F_100 ( V_15 ) )
F_98 ( V_15 ) ;
}
static int F_101 ( struct V_191 * V_15 , struct V_191 * V_262 , void * V_239 )
{
struct V_263 * V_192 = F_102 ( V_15 ) ;
struct V_14 * V_80 = F_100 ( V_262 ) ;
struct V_17 * V_18 = V_80 -> V_81 ;
struct V_82 * V_26 ;
struct V_1 * V_1 ;
struct V_264 * V_265 ;
T_1 V_237 ;
int V_36 ;
V_26 = F_26 ( V_15 , sizeof( * V_26 ) , V_44 ) ;
if ( ! V_26 )
return - V_45 ;
V_1 = F_26 ( V_15 , sizeof( * V_1 ) ,
V_44 ) ;
if ( ! V_1 )
return - V_45 ;
V_1 -> V_4 . type = V_266 ;
V_26 -> V_3 = & V_1 -> V_4 . V_4 ;
V_26 -> V_192 = V_192 ;
V_26 -> V_267 = F_103 ( V_192 , 0 ) ;
if ( F_104 ( V_26 -> V_267 ) )
return F_105 ( V_26 -> V_267 ) ;
V_26 -> V_23 = F_103 ( V_192 , 1 ) ;
if ( F_104 ( V_26 -> V_23 ) )
return F_105 ( V_26 -> V_23 ) ;
V_26 -> V_116 = F_106 ( V_15 , L_27 ) ;
if ( F_104 ( V_26 -> V_116 ) ) {
F_41 ( L_28 ) ;
return F_105 ( V_26 -> V_116 ) ;
}
V_26 -> V_164 = F_106 ( V_15 , L_29 ) ;
if ( F_104 ( V_26 -> V_164 ) ) {
F_41 ( L_30 ) ;
return F_105 ( V_26 -> V_164 ) ;
}
V_265 = F_107 ( V_15 -> V_245 , L_31 , 0 ) ;
if ( ! V_265 ) {
F_41 ( L_32 ) ;
return - V_38 ;
}
V_26 -> V_31 = F_108 ( V_265 ) ;
F_109 ( V_265 ) ;
if ( ! V_26 -> V_31 ) {
F_110 ( L_33 ) ;
return - V_268 ;
}
V_36 = F_111 ( V_26 -> V_116 ) ;
if ( V_36 ) {
F_41 ( L_34 , V_36 ) ;
goto V_269;
}
V_36 = F_53 ( V_26 -> V_164 , 163682864 ) ;
if ( V_36 ) {
F_41 ( L_35 , V_36 ) ;
goto V_270;
}
V_36 = F_111 ( V_26 -> V_164 ) ;
if ( V_36 ) {
F_41 ( L_36 ,
V_36 ) ;
goto V_270;
}
if ( F_88 ( V_15 -> V_245 , L_37 , & V_237 ) ) {
enum V_271 V_272 ;
V_26 -> V_27 = F_112 ( V_15 -> V_245 ,
L_37 , 0 ,
& V_272 ) ;
if ( V_26 -> V_27 < 0 ) {
V_36 = V_26 -> V_27 ;
goto V_273;
}
V_26 -> V_28 = V_272 & V_274 ;
}
V_18 -> V_26 = V_26 ;
if ( ! ( F_9 ( V_275 ) & V_276 ) ) {
F_52 ( V_275 , V_277 ) ;
F_58 ( 1 ) ;
F_52 ( V_275 , 0 ) ;
F_52 ( V_275 , V_276 ) ;
F_34 ( V_278 ,
V_279 |
V_280 ) ;
F_34 ( V_278 , 0 ) ;
F_34 ( V_153 , 0xf << 16 ) ;
}
F_113 ( V_80 , V_26 -> V_3 , & V_281 ,
V_282 , NULL ) ;
F_114 ( V_26 -> V_3 , & V_283 ) ;
V_26 -> V_7 = F_25 ( V_80 , V_26 -> V_3 ) ;
if ( F_104 ( V_26 -> V_7 ) ) {
V_36 = F_105 ( V_26 -> V_7 ) ;
goto V_284;
}
V_36 = F_87 ( V_26 ) ;
if ( V_36 )
goto V_284;
return 0 ;
V_284:
F_31 ( V_26 -> V_3 ) ;
V_273:
F_115 ( V_26 -> V_164 ) ;
V_270:
F_115 ( V_26 -> V_116 ) ;
V_269:
F_116 ( & V_26 -> V_31 -> V_15 ) ;
return V_36 ;
}
static void F_117 ( struct V_191 * V_15 , struct V_191 * V_262 ,
void * V_239 )
{
struct V_14 * V_80 = F_100 ( V_262 ) ;
struct V_17 * V_18 = V_80 -> V_81 ;
struct V_82 * V_26 = V_18 -> V_26 ;
F_99 ( V_26 ) ;
F_15 ( V_26 -> V_7 ) ;
F_31 ( V_26 -> V_3 ) ;
F_115 ( V_26 -> V_116 ) ;
F_115 ( V_26 -> V_164 ) ;
F_116 ( & V_26 -> V_31 -> V_15 ) ;
V_18 -> V_26 = NULL ;
}
static int F_118 ( struct V_263 * V_192 )
{
return F_119 ( & V_192 -> V_15 , & V_285 ) ;
}
static int F_120 ( struct V_263 * V_192 )
{
F_121 ( & V_192 -> V_15 , & V_285 ) ;
return 0 ;
}
