void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , unsigned V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 ;
while ( 1 ) {
if ( ! ( F_3 ( V_2 , V_8 ) & V_9 ) )
return 0 ;
if ( F_6 ( V_7 , V_6 + V_10 ) )
break;
F_7 ( 10 , 20 ) ;
}
F_8 ( V_2 -> V_11 , L_1 ) ;
return - 1 ;
}
T_1 F_9 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
if ( F_5 ( V_2 ) )
return - 1 ;
V_14 &= 0xffff ;
F_1 ( V_2 , V_9 | V_15 | V_16 |
( V_13 << V_17 ) |
( V_12 << V_18 ) | V_14 ,
V_8 ) ;
if ( F_5 ( V_2 ) )
return - 1 ;
return 0 ;
}
T_1 F_10 ( struct V_1 * V_2 , int V_12 , int V_19 )
{
T_1 V_20 ;
if ( F_5 ( V_2 ) )
return 0xffff ;
F_1 ( V_2 , V_9 | V_15 | V_21 |
( V_19 << V_17 ) |
( V_12 << V_18 ) ,
V_8 ) ;
if ( F_5 ( V_2 ) )
return 0xffff ;
V_20 = F_3 ( V_2 , V_8 ) & 0xffff ;
return V_20 ;
}
static int F_11 ( struct V_22 * V_23 , int V_12 ,
int V_19 , T_2 V_3 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
return F_9 ( V_2 , V_12 , V_19 , V_3 ) ;
}
static int F_12 ( struct V_22 * V_23 , int V_12 , int V_19 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
return F_10 ( V_2 , V_12 , V_19 ) ;
}
static void F_13 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
T_2 V_28 = 0 , V_29 = 0 ;
T_3 V_30 ;
T_1 V_31 = V_32 | V_33 |
V_34 | V_35 |
V_36 | V_37 |
V_38 ;
switch ( V_27 -> V_39 -> V_40 ) {
case V_41 :
V_31 |= V_42 ;
break;
case V_43 :
V_31 |= V_44 ;
break;
} ;
if ( V_27 -> V_39 -> V_45 )
V_31 |= V_46 ;
if ( V_27 -> V_39 -> V_47 ) {
V_31 |= V_48 ;
if ( V_27 -> V_39 -> V_49 )
V_29 = V_50 ;
if ( V_27 -> V_39 -> V_51 )
V_29 |= V_52 ;
if ( V_27 -> V_39 -> V_53 & V_54 )
V_28 |= V_55 ;
if ( V_27 -> V_39 -> V_53 & V_56 )
V_28 |= V_57 ;
V_30 = F_15 ( V_28 , V_29 ) ;
if ( V_30 & V_58 )
V_31 |= V_59 ;
if ( V_30 & V_60 )
V_31 |= V_61 ;
F_16 ( V_27 -> V_62 , V_45 , V_11 , L_2 ,
V_30 & V_60 ? L_3 : L_4 ,
V_30 & V_58 ? L_3 : L_4 ) ;
}
F_1 ( V_27 -> V_62 , V_31 , F_17 ( V_27 -> V_63 ) ) ;
if ( V_27 -> V_39 -> V_45 )
F_18 ( V_11 ) ;
else
F_19 ( V_11 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_26 * V_27 ,
struct V_64 * V_65 )
{
const T_4 * V_66 = NULL ;
struct V_67 * V_68 ;
int V_69 , V_70 ;
V_66 = F_21 ( V_65 , L_5 , NULL ) ;
if ( ! V_66 || ( F_22 ( * V_66 ) >= 0x20 ) ) {
F_23 ( L_6 , V_65 -> V_71 ) ;
return - V_72 ;
}
V_70 = F_22 ( * V_66 ) ;
V_69 = F_24 ( V_65 ) ;
if ( V_69 < 0 ) {
F_8 ( V_2 -> V_11 , L_7 , V_69 ) ;
return - V_72 ;
}
V_68 = F_25 ( V_2 -> V_73 [ V_27 -> V_63 ] , V_65 ,
F_13 , 0 , V_69 ) ;
if ( ! V_68 ) {
F_8 ( V_2 -> V_11 , L_8 ) ;
return - V_74 ;
}
F_26 ( V_2 -> V_11 ,
L_9 ,
V_27 -> V_63 , F_27 ( V_68 ) , V_68 -> V_75 ,
V_68 -> V_76 -> V_71 ) ;
V_27 -> V_39 = V_68 ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_62 ;
struct V_64 * V_77 ;
T_1 V_3 , V_78 ;
V_77 = F_29 ( V_27 -> V_79 , L_10 , 0 ) ;
if ( ! V_77 && F_30 ( V_27 -> V_79 ) )
if ( ! F_31 ( V_27 -> V_79 ) )
V_77 = F_32 ( V_27 -> V_79 ) ;
if ( ! V_77 )
return - V_74 ;
switch ( F_24 ( V_77 ) ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_78 = 0 ;
break;
case V_84 :
V_78 = 1 ;
break;
case V_85 :
V_78 = 2 ;
break;
default:
F_8 ( V_2 -> V_11 , L_11 ) ;
return - 1 ;
}
F_33 ( V_2 -> V_86 , V_87 , & V_3 ) ;
V_3 &= ~ F_34 ( V_88 , V_27 -> V_63 ) ;
V_3 |= F_34 ( V_78 , V_27 -> V_63 ) ;
F_35 ( V_2 -> V_86 , V_87 , V_3 ) ;
F_20 ( V_2 , V_27 , V_77 ) ;
V_27 -> V_39 -> V_89 = V_90 ;
V_27 -> V_39 -> V_40 = 0 ;
V_27 -> V_39 -> V_47 = 0 ;
V_27 -> V_39 -> V_91 &= V_92 | V_93 |
V_94 ;
V_27 -> V_39 -> V_53 = V_27 -> V_39 -> V_91 |
V_95 ;
F_36 ( V_27 -> V_39 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_64 * V_96 ;
int V_97 ;
V_96 = F_38 ( V_2 -> V_11 -> V_79 , L_12 ) ;
if ( ! V_96 ) {
F_8 ( V_2 -> V_11 , L_13 , L_12 ) ;
return - V_74 ;
}
if ( ! F_39 ( V_96 ) ) {
V_97 = 0 ;
goto V_98;
}
V_2 -> V_22 = F_40 () ;
if ( ! V_2 -> V_22 ) {
V_97 = - V_99 ;
goto V_98;
}
V_2 -> V_22 -> V_71 = L_14 ;
V_2 -> V_22 -> V_100 = F_12 ;
V_2 -> V_22 -> V_101 = F_11 ;
V_2 -> V_22 -> V_24 = V_2 ;
V_2 -> V_22 -> V_102 = V_2 -> V_11 ;
snprintf ( V_2 -> V_22 -> V_63 , V_103 , L_15 , V_96 -> V_71 ) ;
V_97 = F_41 ( V_2 -> V_22 , V_96 ) ;
if ( V_97 )
goto V_104;
return 0 ;
V_104:
F_42 ( V_2 -> V_22 ) ;
V_98:
F_43 ( V_96 ) ;
V_2 -> V_22 = NULL ;
return V_97 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
return;
F_45 ( V_2 -> V_22 ) ;
F_43 ( V_2 -> V_22 -> V_11 . V_79 ) ;
F_42 ( V_2 -> V_22 ) ;
}
static inline void F_46 ( struct V_1 * V_2 , T_1 V_105 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_106 ) ;
F_1 ( V_2 , V_3 & ~ V_105 , V_106 ) ;
F_3 ( V_2 , V_106 ) ;
}
static inline void F_47 ( struct V_1 * V_2 , T_1 V_105 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_106 ) ;
F_1 ( V_2 , V_3 | V_105 , V_106 ) ;
F_3 ( V_2 , V_106 ) ;
}
static int F_48 ( struct V_25 * V_11 , void * V_107 )
{
int V_108 = F_49 ( V_11 , V_107 ) ;
struct V_26 * V_27 = F_14 ( V_11 ) ;
const char * V_109 = V_11 -> V_110 ;
unsigned long V_111 ;
if ( V_108 )
return V_108 ;
F_50 ( & V_27 -> V_62 -> V_112 , V_111 ) ;
F_1 ( V_27 -> V_62 , ( V_109 [ 0 ] << 8 ) | V_109 [ 1 ] ,
F_51 ( V_27 -> V_63 ) ) ;
F_1 ( V_27 -> V_62 , ( V_109 [ 2 ] << 24 ) | ( V_109 [ 3 ] << 16 ) |
( V_109 [ 4 ] << 8 ) | V_109 [ 5 ] ,
F_52 ( V_27 -> V_63 ) ) ;
F_53 ( & V_27 -> V_62 -> V_112 , V_111 ) ;
return 0 ;
}
void F_54 ( struct V_26 * V_27 )
{
struct V_113 * V_114 = V_27 -> V_114 ;
unsigned int V_5 = V_115 ;
T_5 V_116 ;
V_5 += V_114 -> V_117 ;
F_55 ( & V_114 -> V_118 ) ;
V_114 -> V_119 += F_3 ( V_27 -> V_62 , V_5 ) ;
V_116 = F_3 ( V_27 -> V_62 , V_5 + 0x04 ) ;
if ( V_116 )
V_114 -> V_119 += ( V_116 << 32 ) ;
V_114 -> V_120 += F_3 ( V_27 -> V_62 , V_5 + 0x08 ) ;
V_114 -> V_121 += F_3 ( V_27 -> V_62 , V_5 + 0x10 ) ;
V_114 -> V_122 += F_3 ( V_27 -> V_62 , V_5 + 0x14 ) ;
V_114 -> V_123 += F_3 ( V_27 -> V_62 , V_5 + 0x18 ) ;
V_114 -> V_124 += F_3 ( V_27 -> V_62 , V_5 + 0x1c ) ;
V_114 -> V_125 += F_3 ( V_27 -> V_62 , V_5 + 0x20 ) ;
V_114 -> V_126 +=
F_3 ( V_27 -> V_62 , V_5 + 0x24 ) ;
V_114 -> V_127 += F_3 ( V_27 -> V_62 , V_5 + 0x28 ) ;
V_114 -> V_128 += F_3 ( V_27 -> V_62 , V_5 + 0x2c ) ;
V_114 -> V_129 += F_3 ( V_27 -> V_62 , V_5 + 0x30 ) ;
V_116 = F_3 ( V_27 -> V_62 , V_5 + 0x34 ) ;
if ( V_116 )
V_114 -> V_129 += ( V_116 << 32 ) ;
V_114 -> V_130 += F_3 ( V_27 -> V_62 , V_5 + 0x38 ) ;
F_56 ( & V_114 -> V_118 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_27 [ V_131 ] || ! V_2 -> V_27 [ V_131 ] -> V_114 )
continue;
if ( F_58 ( & V_2 -> V_27 [ V_131 ] -> V_114 -> V_133 ) ) {
F_54 ( V_2 -> V_27 [ V_131 ] ) ;
F_59 ( & V_2 -> V_27 [ V_131 ] -> V_114 -> V_133 ) ;
}
}
}
static struct V_134 * F_60 ( struct V_25 * V_11 ,
struct V_134 * V_135 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_113 * V_114 = V_27 -> V_114 ;
unsigned int V_136 ;
if ( F_61 ( V_11 ) && F_62 ( V_11 ) ) {
if ( F_58 ( & V_114 -> V_133 ) ) {
F_54 ( V_27 ) ;
F_59 ( & V_114 -> V_133 ) ;
}
}
do {
V_136 = F_63 ( & V_114 -> V_118 ) ;
V_135 -> V_120 = V_114 -> V_120 ;
V_135 -> V_130 = V_114 -> V_130 ;
V_135 -> V_119 = V_114 -> V_119 ;
V_135 -> V_129 = V_114 -> V_129 ;
V_135 -> V_137 = V_114 -> V_128 ;
V_135 -> V_138 = V_114 -> V_123 +
V_114 -> V_124 ;
V_135 -> V_139 = V_114 -> V_121 ;
V_135 -> V_140 = V_114 -> V_122 ;
V_135 -> V_141 = V_114 -> V_125 ;
V_135 -> V_142 = V_114 -> V_127 ;
} while ( F_64 ( & V_114 -> V_118 , V_136 ) );
V_135 -> V_143 = V_11 -> V_116 . V_143 ;
V_135 -> V_144 = V_11 -> V_116 . V_144 ;
V_135 -> V_145 = V_11 -> V_116 . V_145 ;
return V_135 ;
}
static inline int F_65 ( int V_146 )
{
if ( V_146 + V_147 < V_148 )
V_146 = V_148 - V_147 ;
return F_66 ( V_149 + V_146 ) +
F_66 ( sizeof( struct V_150 ) ) ;
}
static inline int F_67 ( int V_151 )
{
int V_152 = V_151 - V_153 - V_154 -
F_66 ( sizeof( struct V_150 ) ) ;
F_68 ( V_152 < V_148 ) ;
return V_152 ;
}
static inline void F_69 ( struct V_155 * V_156 ,
struct V_155 * V_157 )
{
V_156 -> V_158 = F_70 ( V_157 -> V_158 ) ;
V_156 -> V_159 = F_70 ( V_157 -> V_159 ) ;
V_156 -> V_160 = F_70 ( V_157 -> V_160 ) ;
V_156 -> V_161 = F_70 ( V_157 -> V_161 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
T_6 V_162 ;
int V_163 = V_164 ;
T_6 V_165 ;
int V_131 ;
V_2 -> V_166 = F_72 ( V_2 -> V_11 ,
V_163 * sizeof( struct V_167 ) ,
& V_2 -> V_168 ,
V_169 | V_170 ) ;
if ( F_73 ( ! V_2 -> V_166 ) )
return - V_99 ;
V_2 -> V_171 = F_74 ( V_163 , V_172 ,
V_173 ) ;
if ( F_73 ( ! V_2 -> V_171 ) )
return - V_99 ;
V_165 = F_75 ( V_2 -> V_11 ,
V_2 -> V_171 , V_163 * V_172 ,
V_174 ) ;
if ( F_73 ( F_76 ( V_2 -> V_11 , V_165 ) ) )
return - V_99 ;
memset ( V_2 -> V_166 , 0x0 , sizeof( struct V_167 ) * V_163 ) ;
V_162 = V_2 -> V_168 +
( sizeof( struct V_167 ) * ( V_163 - 1 ) ) ;
for ( V_131 = 0 ; V_131 < V_163 ; V_131 ++ ) {
V_2 -> V_166 [ V_131 ] . V_175 =
( V_165 + ( V_131 * V_172 ) ) ;
if ( V_131 < V_163 - 1 )
V_2 -> V_166 [ V_131 ] . V_176 = ( V_2 -> V_168 +
( ( V_131 + 1 ) * sizeof( struct V_167 ) ) ) ;
V_2 -> V_166 [ V_131 ] . V_177 = F_77 ( V_172 ) ;
}
F_1 ( V_2 , V_2 -> V_168 , V_178 ) ;
F_1 ( V_2 , V_162 , V_179 ) ;
F_1 ( V_2 , ( V_163 << 16 ) | V_163 , V_180 ) ;
F_1 ( V_2 , V_172 << 16 , V_181 ) ;
return 0 ;
}
static inline void * F_78 ( struct V_182 * V_183 , T_1 V_184 )
{
void * V_108 = V_183 -> V_185 ;
return V_108 + ( V_184 - V_183 -> V_186 ) ;
}
static inline struct V_187 * F_79 ( struct V_182 * V_183 ,
struct V_167 * V_188 )
{
int V_189 = V_188 - V_183 -> V_185 ;
return & V_183 -> V_190 [ V_189 ] ;
}
static void F_80 ( struct V_191 * V_11 , struct V_187 * V_192 )
{
if ( V_192 -> V_111 & V_193 ) {
F_81 ( V_11 ,
F_82 ( V_192 , V_194 ) ,
F_83 ( V_192 , V_195 ) ,
V_196 ) ;
} else if ( V_192 -> V_111 & V_197 ) {
F_84 ( V_11 ,
F_82 ( V_192 , V_194 ) ,
F_83 ( V_192 , V_195 ) ,
V_196 ) ;
}
V_192 -> V_111 = 0 ;
if ( V_192 -> V_198 &&
( V_192 -> V_198 != (struct V_199 * ) V_200 ) )
F_85 ( V_192 -> V_198 ) ;
V_192 -> V_198 = NULL ;
}
static int F_86 ( struct V_199 * V_198 , struct V_25 * V_11 ,
int V_201 , struct V_182 * V_183 , bool V_202 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
struct V_167 * V_203 , * V_188 ;
struct V_187 * V_192 ;
T_6 V_204 ;
unsigned int V_205 ;
int V_131 , V_206 = 1 ;
T_1 V_207 = 0 ;
V_203 = V_183 -> V_208 ;
if ( V_203 == V_183 -> V_209 )
return - V_99 ;
V_207 |= ( V_27 -> V_63 + 1 ) << V_210 ;
V_192 = F_79 ( V_183 , V_203 ) ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
if ( V_202 )
V_207 |= V_211 ;
if ( V_198 -> V_212 == V_213 )
V_207 |= V_214 ;
if ( F_87 ( V_198 ) )
V_207 |= V_215 | F_88 ( V_198 ) ;
V_204 = F_75 ( & V_11 -> V_11 , V_198 -> V_216 ,
F_89 ( V_198 ) , V_196 ) ;
if ( F_73 ( F_76 ( & V_11 -> V_11 , V_204 ) ) )
return - V_99 ;
F_90 ( V_203 -> V_175 , V_204 ) ;
V_192 -> V_111 |= V_193 ;
F_91 ( V_192 , V_194 , V_204 ) ;
F_92 ( V_192 , V_195 , F_89 ( V_198 ) ) ;
V_188 = V_203 ;
V_205 = F_93 ( V_198 ) -> V_205 ;
for ( V_131 = 0 ; V_131 < V_205 ; V_131 ++ ) {
struct V_217 * V_218 = & F_93 ( V_198 ) -> V_219 [ V_131 ] ;
unsigned int V_220 = 0 ;
int V_151 = F_94 ( V_218 ) ;
while ( V_151 ) {
bool V_221 = false ;
unsigned int V_222 ;
V_188 = F_78 ( V_183 , V_188 -> V_176 ) ;
if ( V_188 == V_183 -> V_209 )
goto V_223;
V_206 ++ ;
V_222 = F_95 ( V_151 , V_224 ) ;
V_204 = F_96 ( & V_11 -> V_11 , V_218 , V_220 ,
V_222 ,
V_196 ) ;
if ( F_73 ( F_76 ( & V_11 -> V_11 , V_204 ) ) )
goto V_223;
if ( V_131 == V_205 - 1 &&
( V_151 - V_222 ) == 0 )
V_221 = true ;
F_90 ( V_188 -> V_175 , V_204 ) ;
F_90 ( V_188 -> V_177 , ( V_225 |
F_97 ( V_222 ) |
V_221 * V_226 ) ) ;
F_90 ( V_188 -> V_207 , 0 ) ;
V_192 -> V_198 = (struct V_199 * ) V_200 ;
V_192 = F_79 ( V_183 , V_188 ) ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> V_111 |= V_197 ;
F_91 ( V_192 , V_194 , V_204 ) ;
F_92 ( V_192 , V_195 , V_222 ) ;
V_151 -= V_222 ;
V_220 += V_222 ;
}
}
V_192 -> V_198 = V_198 ;
F_90 ( V_203 -> V_207 , V_207 ) ;
F_90 ( V_203 -> V_177 , ( V_225 | F_97 ( F_89 ( V_198 ) ) |
( ! V_205 * V_226 ) ) ) ;
F_98 ( V_11 , V_198 -> V_227 ) ;
F_99 ( V_198 ) ;
V_183 -> V_208 = F_78 ( V_183 , V_188 -> V_176 ) ;
F_100 ( V_206 , & V_183 -> V_228 ) ;
F_101 () ;
if ( F_102 ( F_103 ( V_11 , 0 ) ) || ! V_198 -> V_229 )
F_1 ( V_2 , V_188 -> V_176 , V_230 ) ;
return 0 ;
V_223:
do {
V_192 = F_79 ( V_183 , V_203 ) ;
F_80 ( & V_11 -> V_11 , V_192 ) ;
V_203 -> V_177 = V_226 | V_231 ;
V_203 = F_78 ( V_183 , V_203 -> V_176 ) ;
} while ( V_203 != V_188 );
return - V_99 ;
}
static inline int F_104 ( struct V_199 * V_198 )
{
int V_131 , V_232 ;
struct V_217 * V_218 ;
V_232 = 1 ;
if ( F_105 ( V_198 ) ) {
for ( V_131 = 0 ; V_131 < F_93 ( V_198 ) -> V_205 ; V_131 ++ ) {
V_218 = & F_93 ( V_198 ) -> V_219 [ V_131 ] ;
V_232 += F_106 ( V_218 -> V_233 , V_224 ) ;
}
} else {
V_232 += F_93 ( V_198 ) -> V_205 ;
}
return V_232 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_73 [ V_131 ] )
continue;
if ( F_108 ( V_2 -> V_73 [ V_131 ] ) )
return 1 ;
}
return 0 ;
}
static void F_109 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_73 [ V_131 ] )
continue;
F_110 ( V_2 -> V_73 [ V_131 ] ) ;
}
}
static void F_111 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_73 [ V_131 ] )
continue;
F_112 ( V_2 -> V_73 [ V_131 ] ) ;
}
}
static int F_113 ( struct V_199 * V_198 , struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
struct V_182 * V_183 = & V_2 -> V_234 ;
struct V_235 * V_116 = & V_11 -> V_116 ;
unsigned long V_111 ;
bool V_202 = false ;
int V_201 ;
F_50 ( & V_2 -> V_112 , V_111 ) ;
V_201 = F_104 ( V_198 ) ;
if ( F_73 ( F_114 ( & V_183 -> V_228 ) <= V_201 ) ) {
F_111 ( V_2 ) ;
F_115 ( V_2 , V_236 , V_11 ,
L_16 ) ;
F_53 ( & V_2 -> V_112 , V_111 ) ;
return V_237 ;
}
if ( F_105 ( V_198 ) ) {
if ( F_116 ( V_198 , 0 ) ) {
F_117 ( V_2 , V_238 , V_11 ,
L_17 ) ;
goto V_239;
}
if ( F_93 ( V_198 ) -> V_240 &
( V_241 | V_242 ) ) {
V_202 = true ;
F_118 ( V_198 ) -> V_243 = F_119 ( F_93 ( V_198 ) -> V_244 ) ;
}
}
if ( F_86 ( V_198 , V_11 , V_201 , V_183 , V_202 ) < 0 )
goto V_239;
if ( F_73 ( F_114 ( & V_183 -> V_228 ) <= V_183 -> V_245 ) )
F_111 ( V_2 ) ;
F_53 ( & V_2 -> V_112 , V_111 ) ;
return V_246 ;
V_239:
F_53 ( & V_2 -> V_112 , V_111 ) ;
V_116 -> V_145 ++ ;
F_120 ( V_198 ) ;
return V_246 ;
}
static int F_121 ( struct V_247 * V_248 , int V_249 ,
struct V_1 * V_2 , T_1 V_250 )
{
struct V_251 * V_183 = & V_2 -> V_252 ;
int V_189 = V_183 -> V_253 ;
struct V_199 * V_198 ;
T_3 * V_216 , * V_254 ;
struct V_155 * V_156 , V_255 ;
int V_256 = 0 ;
while ( V_256 < V_249 ) {
struct V_25 * V_73 ;
unsigned int V_257 ;
T_6 V_165 ;
int V_27 = 0 ;
V_189 = F_122 ( V_189 ) ;
V_156 = & V_183 -> V_185 [ V_189 ] ;
V_216 = V_183 -> V_216 [ V_189 ] ;
F_69 ( & V_255 , V_156 ) ;
if ( ! ( V_255 . V_159 & V_258 ) )
break;
V_27 = ( V_255 . V_161 >> V_259 ) &
V_260 ;
V_27 -- ;
V_73 = V_2 -> V_73 [ V_27 ] ;
V_254 = F_123 ( V_183 -> V_151 ) ;
if ( F_73 ( ! V_254 ) ) {
V_73 -> V_116 . V_144 ++ ;
goto V_261;
}
V_165 = F_75 ( & V_2 -> V_73 [ V_27 ] -> V_11 ,
V_254 + V_153 ,
V_183 -> V_152 ,
V_174 ) ;
if ( F_73 ( F_76 ( & V_73 -> V_11 , V_165 ) ) ) {
F_124 ( V_254 ) ;
V_73 -> V_116 . V_144 ++ ;
goto V_261;
}
V_198 = F_125 ( V_216 , V_183 -> V_151 ) ;
if ( F_73 ( ! V_198 ) ) {
F_126 ( F_127 ( V_254 ) ) ;
V_73 -> V_116 . V_144 ++ ;
goto V_261;
}
F_128 ( V_198 , V_153 + V_154 ) ;
F_81 ( & V_73 -> V_11 , V_255 . V_158 ,
V_183 -> V_152 , V_174 ) ;
V_257 = F_129 ( V_255 . V_159 ) ;
V_198 -> V_11 = V_73 ;
F_130 ( V_198 , V_257 ) ;
if ( V_255 . V_161 & V_262 )
V_198 -> V_212 = V_263 ;
else
F_131 ( V_198 ) ;
V_198 -> V_264 = F_132 ( V_198 , V_73 ) ;
if ( V_73 -> V_265 & V_266 &&
F_133 ( V_255 . V_160 ) )
F_134 ( V_198 , F_119 ( V_267 ) ,
F_133 ( V_255 . V_160 ) ) ;
F_135 ( V_248 , V_198 ) ;
V_183 -> V_216 [ V_189 ] = V_254 ;
V_156 -> V_158 = ( unsigned int ) V_165 ;
V_261:
V_156 -> V_159 = F_136 ( V_183 -> V_152 ) ;
V_183 -> V_253 = V_189 ;
F_101 () ;
F_1 ( V_2 , V_183 -> V_253 , V_268 ) ;
V_256 ++ ;
}
if ( V_256 < V_249 )
F_1 ( V_2 , V_250 , V_269 ) ;
return V_256 ;
}
static int F_137 ( struct V_1 * V_2 , int V_249 , bool * V_270 )
{
struct V_182 * V_183 = & V_2 -> V_234 ;
struct V_167 * V_184 ;
struct V_199 * V_198 ;
struct V_187 * V_192 ;
int V_271 = 0 , V_256 [ V_272 ] ;
unsigned int V_273 [ V_272 ] ;
T_1 V_274 , V_185 ;
static int V_275 ;
int V_131 ;
memset ( V_256 , 0 , sizeof( V_256 ) ) ;
memset ( V_273 , 0 , sizeof( V_273 ) ) ;
V_274 = F_3 ( V_2 , V_276 ) ;
V_185 = F_3 ( V_2 , V_277 ) ;
V_184 = F_78 ( V_183 , V_274 ) ;
while ( ( V_274 != V_185 ) && V_249 ) {
T_1 V_278 = V_184 -> V_176 ;
int V_27 ;
V_184 = F_78 ( V_183 , V_184 -> V_176 ) ;
if ( ( V_184 -> V_177 & V_231 ) == 0 )
break;
V_27 = ( V_184 -> V_207 >> V_210 ) &
V_279 ;
V_27 -- ;
V_192 = F_79 ( V_183 , V_184 ) ;
V_198 = V_192 -> V_198 ;
if ( ! V_198 ) {
V_275 = 1 ;
break;
}
if ( V_198 != (struct V_199 * ) V_200 ) {
V_273 [ V_27 ] += V_198 -> V_227 ;
V_256 [ V_27 ] ++ ;
V_249 -- ;
}
F_80 ( V_2 -> V_11 , V_192 ) ;
V_183 -> V_209 = V_184 ;
F_138 ( & V_183 -> V_228 ) ;
V_274 = V_278 ;
}
F_1 ( V_2 , V_274 , V_276 ) ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_73 [ V_131 ] || ! V_256 [ V_131 ] )
continue;
F_139 ( V_2 -> V_73 [ V_131 ] , V_256 [ V_131 ] , V_273 [ V_131 ] ) ;
V_271 += V_256 [ V_131 ] ;
}
if ( V_274 != V_185 || V_274 != F_3 ( V_2 , V_277 ) )
* V_270 = true ;
else
F_1 ( V_2 , V_280 , V_269 ) ;
if ( ! V_271 )
return 0 ;
if ( F_107 ( V_2 ) &&
( F_114 ( & V_183 -> V_228 ) > V_183 -> V_245 ) )
F_109 ( V_2 ) ;
return V_271 ;
}
static int F_140 ( struct V_247 * V_248 , int V_249 )
{
struct V_1 * V_2 = F_141 ( V_248 , struct V_1 , V_281 ) ;
T_1 V_282 , V_283 , V_105 , V_284 , V_250 , V_285 ;
int V_286 , V_287 ;
bool V_270 = false ;
V_282 = F_3 ( V_2 , V_269 ) ;
V_283 = F_3 ( V_2 , V_288 ) ;
V_284 = V_280 ;
V_250 = V_289 ;
V_285 = ( V_290 | V_291 ) ;
V_286 = 0 ;
V_287 = 0 ;
V_270 = 0 ;
if ( V_282 & V_284 )
V_286 = F_137 ( V_2 , V_249 , & V_270 ) ;
if ( V_282 & V_250 )
V_287 = F_121 ( V_248 , V_249 , V_2 , V_250 ) ;
if ( F_73 ( V_283 & V_285 ) ) {
F_57 ( V_2 ) ;
F_1 ( V_2 , V_285 , V_288 ) ;
}
if ( F_73 ( F_142 ( V_2 ) ) ) {
V_105 = F_3 ( V_2 , V_106 ) ;
F_143 ( V_2 -> V_73 [ 0 ] ,
L_18 ,
V_286 , V_287 , V_282 , V_105 ) ;
}
if ( V_270 || V_287 == V_249 )
return V_249 ;
V_282 = F_3 ( V_2 , V_269 ) ;
if ( V_282 & ( V_284 | V_250 ) )
return V_249 ;
F_144 ( V_248 ) ;
F_47 ( V_2 , V_284 | V_250 ) ;
return V_287 ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_182 * V_183 = & V_2 -> V_234 ;
int V_131 , V_292 = sizeof( * V_183 -> V_185 ) ;
V_183 -> V_190 = F_74 ( V_164 , sizeof( * V_183 -> V_190 ) ,
V_173 ) ;
if ( ! V_183 -> V_190 )
goto V_293;
V_183 -> V_185 = F_72 ( V_2 -> V_11 ,
V_164 * V_292 ,
& V_183 -> V_186 ,
V_169 | V_170 ) ;
if ( ! V_183 -> V_185 )
goto V_293;
memset ( V_183 -> V_185 , 0 , V_164 * V_292 ) ;
for ( V_131 = 0 ; V_131 < V_164 ; V_131 ++ ) {
int V_294 = ( V_131 + 1 ) % V_164 ;
T_1 V_295 = V_183 -> V_186 + V_294 * V_292 ;
V_183 -> V_185 [ V_131 ] . V_176 = V_295 ;
V_183 -> V_185 [ V_131 ] . V_177 = V_226 | V_231 ;
}
F_146 ( & V_183 -> V_228 , V_164 - 2 ) ;
V_183 -> V_208 = & V_183 -> V_185 [ 0 ] ;
V_183 -> V_209 = & V_183 -> V_185 [ V_164 - 1 ] ;
V_183 -> V_245 = V_296 ;
F_101 () ;
F_1 ( V_2 , V_183 -> V_186 , V_230 ) ;
F_1 ( V_2 , V_183 -> V_186 , V_297 ) ;
F_1 ( V_2 ,
V_183 -> V_186 + ( ( V_164 - 1 ) * V_292 ) ,
V_276 ) ;
F_1 ( V_2 ,
V_183 -> V_186 + ( ( V_164 - 1 ) * V_292 ) ,
V_277 ) ;
return 0 ;
V_293:
return - V_99 ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_182 * V_183 = & V_2 -> V_234 ;
int V_131 ;
if ( V_183 -> V_190 ) {
for ( V_131 = 0 ; V_131 < V_164 ; V_131 ++ )
F_80 ( V_2 -> V_11 , & V_183 -> V_190 [ V_131 ] ) ;
F_148 ( V_183 -> V_190 ) ;
V_183 -> V_190 = NULL ;
}
if ( V_183 -> V_185 ) {
F_149 ( V_2 -> V_11 ,
V_164 * sizeof( * V_183 -> V_185 ) ,
V_183 -> V_185 ,
V_183 -> V_186 ) ;
V_183 -> V_185 = NULL ;
}
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_251 * V_183 = & V_2 -> V_252 ;
int V_131 ;
V_183 -> V_151 = F_65 ( V_298 ) ;
V_183 -> V_152 = F_67 ( V_183 -> V_151 ) ;
V_183 -> V_216 = F_74 ( V_164 , sizeof( * V_183 -> V_216 ) ,
V_173 ) ;
if ( ! V_183 -> V_216 )
return - V_99 ;
for ( V_131 = 0 ; V_131 < V_164 ; V_131 ++ ) {
V_183 -> V_216 [ V_131 ] = F_151 ( V_183 -> V_151 ) ;
if ( ! V_183 -> V_216 [ V_131 ] )
return - V_99 ;
}
V_183 -> V_185 = F_72 ( V_2 -> V_11 ,
V_164 * sizeof( * V_183 -> V_185 ) ,
& V_183 -> V_186 ,
V_169 | V_170 ) ;
if ( ! V_183 -> V_185 )
return - V_99 ;
for ( V_131 = 0 ; V_131 < V_164 ; V_131 ++ ) {
T_6 V_165 = F_75 ( V_2 -> V_11 ,
V_183 -> V_216 [ V_131 ] + V_153 ,
V_183 -> V_152 ,
V_174 ) ;
if ( F_73 ( F_76 ( V_2 -> V_11 , V_165 ) ) )
return - V_99 ;
V_183 -> V_185 [ V_131 ] . V_158 = ( unsigned int ) V_165 ;
V_183 -> V_185 [ V_131 ] . V_159 = F_136 ( V_183 -> V_152 ) ;
}
V_183 -> V_253 = V_164 - 1 ;
F_101 () ;
F_1 ( V_2 , V_2 -> V_252 . V_186 , V_299 ) ;
F_1 ( V_2 , V_164 , V_300 ) ;
F_1 ( V_2 , V_2 -> V_252 . V_253 , V_268 ) ;
F_1 ( V_2 , V_301 , V_302 ) ;
F_1 ( V_2 , ( V_303 << 8 ) | V_303 , F_152 ( 0 ) ) ;
return 0 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_251 * V_183 = & V_2 -> V_252 ;
int V_131 ;
if ( V_183 -> V_216 && V_183 -> V_185 ) {
for ( V_131 = 0 ; V_131 < V_164 ; V_131 ++ ) {
if ( ! V_183 -> V_216 [ V_131 ] )
continue;
if ( ! V_183 -> V_185 [ V_131 ] . V_158 )
continue;
F_81 ( V_2 -> V_11 ,
V_183 -> V_185 [ V_131 ] . V_158 ,
V_183 -> V_152 ,
V_174 ) ;
F_124 ( V_183 -> V_216 [ V_131 ] ) ;
}
F_148 ( V_183 -> V_216 ) ;
V_183 -> V_216 = NULL ;
}
if ( V_183 -> V_185 ) {
F_149 ( V_2 -> V_11 ,
V_164 * sizeof( * V_183 -> V_185 ) ,
V_183 -> V_185 ,
V_183 -> V_186 ) ;
V_183 -> V_185 = NULL ;
}
}
static int F_154 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 ;
while ( 1 ) {
if ( ! ( F_3 ( V_2 , V_304 ) &
( V_305 | V_306 ) ) )
return 0 ;
if ( F_6 ( V_7 , V_6 + V_307 ) )
break;
}
F_8 ( V_2 -> V_11 , L_19 ) ;
return - 1 ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_97 ;
if ( F_154 ( V_2 ) )
return - V_308 ;
V_97 = F_71 ( V_2 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_145 ( V_2 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_150 ( V_2 ) ;
if ( V_97 )
return V_97 ;
F_1 ( V_2 , V_309 | V_310 | V_311 ,
V_312 ) ;
F_1 ( V_2 , 0x0 , V_313 ) ;
return 0 ;
}
static void F_156 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ )
if ( V_2 -> V_73 [ V_131 ] )
F_157 ( V_2 -> V_73 [ V_131 ] ) ;
if ( V_2 -> V_166 ) {
F_149 ( V_2 -> V_11 ,
V_164 * sizeof( struct V_167 ) ,
V_2 -> V_166 ,
V_2 -> V_168 ) ;
V_2 -> V_166 = NULL ;
V_2 -> V_168 = 0 ;
}
F_147 ( V_2 ) ;
F_153 ( V_2 ) ;
F_148 ( V_2 -> V_171 ) ;
}
static void F_158 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
V_2 -> V_73 [ V_27 -> V_63 ] -> V_116 . V_143 ++ ;
F_115 ( V_2 , V_238 , V_11 ,
L_20 ) ;
F_159 ( & V_2 -> V_314 ) ;
}
static T_7 F_160 ( int V_315 , void * V_316 )
{
struct V_1 * V_2 = V_316 ;
T_1 V_282 ;
V_282 = F_3 ( V_2 , V_269 ) ;
if ( F_73 ( ! V_282 ) )
return V_317 ;
if ( F_161 ( V_282 & ( V_289 | V_280 ) ) ) {
if ( F_161 ( F_162 ( & V_2 -> V_281 ) ) )
F_163 ( & V_2 -> V_281 ) ;
} else {
F_1 ( V_2 , V_282 , V_269 ) ;
}
F_46 ( V_2 , ( V_289 | V_280 ) ) ;
return V_318 ;
}
static void F_164 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
T_1 V_319 = V_280 | V_289 ;
F_46 ( V_2 , V_319 ) ;
F_160 ( V_11 -> V_315 , V_11 ) ;
F_47 ( V_2 , V_319 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_97 ;
V_97 = F_155 ( V_2 ) ;
if ( V_97 ) {
F_156 ( V_2 ) ;
return V_97 ;
}
F_1 ( V_2 ,
V_320 | V_321 | V_322 |
V_323 | V_324 |
V_325 | V_326 ,
V_304 ) ;
return 0 ;
}
static int F_166 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
if ( ! F_114 ( & V_2 -> V_327 ) ) {
int V_97 = F_165 ( V_2 ) ;
if ( V_97 )
return V_97 ;
F_167 ( & V_2 -> V_281 ) ;
F_47 ( V_2 , V_280 | V_289 ) ;
}
F_138 ( & V_2 -> V_327 ) ;
F_168 ( V_27 -> V_39 ) ;
F_169 ( V_11 ) ;
return 0 ;
}
static void F_170 ( struct V_1 * V_2 , T_1 V_328 )
{
unsigned long V_111 ;
T_1 V_3 ;
int V_131 ;
F_50 ( & V_2 -> V_112 , V_111 ) ;
V_3 = F_3 ( V_2 , V_328 ) ;
F_1 ( V_2 , V_3 & ~ ( V_320 | V_321 | V_322 ) ,
V_328 ) ;
F_53 ( & V_2 -> V_112 , V_111 ) ;
for ( V_131 = 0 ; V_131 < 10 ; V_131 ++ ) {
V_3 = F_3 ( V_2 , V_328 ) ;
if ( V_3 & ( V_306 | V_305 ) ) {
F_171 ( 20 ) ;
continue;
}
break;
}
}
static int F_172 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
F_173 ( V_11 ) ;
F_174 ( V_27 -> V_39 ) ;
if ( ! F_175 ( & V_2 -> V_327 ) )
return 0 ;
F_46 ( V_2 , V_280 | V_289 ) ;
F_176 ( & V_2 -> V_281 ) ;
F_170 ( V_2 , V_304 ) ;
F_156 ( V_2 ) ;
return 0 ;
}
static int T_8 F_177 ( struct V_1 * V_2 )
{
int V_97 , V_131 ;
F_178 ( V_2 -> V_329 ) ;
F_7 ( 10 , 20 ) ;
F_179 ( V_2 -> V_329 ) ;
F_7 ( 10 , 20 ) ;
F_35 ( V_2 -> V_330 , V_331 , 0xa00 ) ;
F_35 ( V_2 -> V_330 , V_332 , 0x5 ) ;
F_35 ( V_2 -> V_330 , V_333 , 0x0 ) ;
F_1 ( V_2 , V_334 , F_17 ( 0 ) ) ;
F_1 ( V_2 , V_334 , F_17 ( 1 ) ) ;
F_1 ( V_2 , 1 , V_335 ) ;
V_97 = F_180 ( V_2 -> V_11 , V_2 -> V_315 , F_160 , 0 ,
F_181 ( V_2 -> V_11 ) , V_2 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_37 ( V_2 ) ;
if ( V_97 )
return V_97 ;
F_1 ( V_2 , 0 , V_336 ) ;
F_46 ( V_2 , ~ 0 ) ;
F_1 ( V_2 , V_337 , V_338 ) ;
F_1 ( V_2 , 0 , V_338 ) ;
F_1 ( V_2 , 0 , V_339 ) ;
for ( V_131 = 0 ; V_131 < 2 ; V_131 ++ ) {
T_1 V_3 = F_3 ( V_2 , F_182 ( V_131 ) ) ;
V_3 &= ~ 0xffff ;
V_3 |= 0x5555 ;
V_3 |= V_340 | V_341 | V_342 ;
F_1 ( V_2 , V_3 , F_182 ( V_131 ) ) ;
}
return 0 ;
}
static int T_8 F_183 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
const char * V_343 ;
V_343 = F_184 ( V_27 -> V_79 ) ;
if ( V_343 )
F_185 ( V_11 -> V_110 , V_343 ) ;
if ( ! F_186 ( V_11 -> V_110 ) ) {
F_187 ( V_11 -> V_110 ) ;
F_8 ( V_2 -> V_11 , L_21 ,
V_11 -> V_110 ) ;
V_11 -> V_344 = V_345 ;
}
return F_28 ( V_27 ) ;
}
static void F_188 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_1 * V_2 = V_27 -> V_62 ;
F_189 ( V_27 -> V_39 ) ;
F_44 ( V_2 ) ;
F_46 ( V_2 , ~ 0 ) ;
F_190 ( V_11 -> V_315 , V_11 ) ;
}
static int F_191 ( struct V_25 * V_11 , struct V_346 * V_347 , int V_348 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
switch ( V_348 ) {
case V_349 :
case V_350 :
case V_351 :
return F_192 ( V_27 -> V_39 , V_347 , V_348 ) ;
default:
break;
}
return - V_352 ;
}
static void F_193 ( struct V_353 * V_354 )
{
struct V_1 * V_2 = F_141 ( V_354 , struct V_1 , V_314 ) ;
int V_97 , V_131 ;
unsigned long V_355 = 0 ;
F_194 () ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_73 [ V_131 ] )
continue;
F_172 ( V_2 -> V_73 [ V_131 ] ) ;
F_195 ( V_131 , & V_355 ) ;
}
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! F_196 ( V_131 , & V_355 ) )
continue;
V_97 = F_166 ( V_2 -> V_73 [ V_131 ] ) ;
if ( V_97 ) {
F_197 ( V_2 , V_356 , V_2 -> V_73 [ V_131 ] ,
L_22 ) ;
F_198 ( V_2 -> V_73 [ V_131 ] ) ;
}
}
F_199 () ;
}
static int F_200 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
if ( ! V_2 -> V_73 [ V_131 ] )
continue;
F_201 ( V_2 -> V_73 [ V_131 ] ) ;
F_202 ( V_2 -> V_73 [ V_131 ] ) ;
}
F_203 ( & V_2 -> V_314 ) ;
return 0 ;
}
static int F_204 ( struct V_25 * V_11 ,
struct V_357 * V_348 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
int V_97 ;
V_97 = F_205 ( V_27 -> V_39 ) ;
if ( V_97 )
return - V_74 ;
return F_206 ( V_27 -> V_39 , V_348 ) ;
}
static int F_207 ( struct V_25 * V_11 ,
struct V_357 * V_348 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
if ( V_348 -> V_358 != V_27 -> V_39 -> V_359 . V_70 ) {
V_27 -> V_39 = F_208 ( V_27 -> V_62 -> V_22 ,
V_348 -> V_358 ) ;
if ( ! V_27 -> V_39 )
return - V_74 ;
}
return F_209 ( V_27 -> V_39 , V_348 ) ;
}
static void F_210 ( struct V_25 * V_11 ,
struct V_360 * V_361 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
F_211 ( V_361 -> V_362 , V_27 -> V_62 -> V_11 -> V_362 -> V_71 , sizeof( V_361 -> V_362 ) ) ;
F_211 ( V_361 -> V_363 , F_181 ( V_27 -> V_62 -> V_11 ) , sizeof( V_361 -> V_363 ) ) ;
V_361 -> V_364 = F_212 ( V_365 ) ;
}
static T_1 F_213 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
return V_27 -> V_62 -> V_366 ;
}
static void F_214 ( struct V_25 * V_11 , T_1 V_367 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
V_27 -> V_62 -> V_366 = V_367 ;
}
static int F_215 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
return F_216 ( V_27 -> V_39 ) ;
}
static T_1 F_217 ( struct V_25 * V_11 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
int V_97 ;
V_97 = F_218 ( V_27 -> V_39 ) ;
if ( V_97 )
return F_219 ( V_11 ) ;
return V_27 -> V_39 -> V_45 ;
}
static void F_220 ( struct V_25 * V_11 , T_1 V_368 , T_3 * V_216 )
{
int V_131 ;
switch ( V_368 ) {
case V_369 :
for ( V_131 = 0 ; V_131 < F_212 ( V_365 ) ; V_131 ++ ) {
memcpy ( V_216 , V_365 [ V_131 ] . V_370 , V_371 ) ;
V_216 += V_371 ;
}
break;
}
}
static int F_221 ( struct V_25 * V_11 , int V_372 )
{
switch ( V_372 ) {
case V_369 :
return F_212 ( V_365 ) ;
default:
return - V_352 ;
}
}
static void F_222 ( struct V_25 * V_11 ,
struct V_373 * V_116 , T_5 * V_216 )
{
struct V_26 * V_27 = F_14 ( V_11 ) ;
struct V_113 * V_374 = V_27 -> V_114 ;
T_5 * V_375 , * V_376 ;
unsigned int V_136 ;
int V_131 ;
if ( F_61 ( V_11 ) && F_62 ( V_11 ) ) {
if ( F_58 ( & V_374 -> V_133 ) ) {
F_54 ( V_27 ) ;
F_59 ( & V_374 -> V_133 ) ;
}
}
do {
V_375 = ( T_5 * ) V_374 ;
V_376 = V_216 ;
V_136 = F_63 ( & V_374 -> V_118 ) ;
for ( V_131 = 0 ; V_131 < F_212 ( V_365 ) ; V_131 ++ )
* V_376 ++ = * ( V_375 + V_365 [ V_131 ] . V_220 ) ;
} while ( F_64 ( & V_374 -> V_118 , V_136 ) );
}
static int F_223 ( struct V_1 * V_2 , struct V_64 * V_77 )
{
struct V_26 * V_27 ;
const T_4 * V_377 = F_21 ( V_77 , L_5 , NULL ) ;
int V_63 , V_97 ;
if ( ! V_377 ) {
F_8 ( V_2 -> V_11 , L_23 ) ;
return - V_72 ;
}
V_63 = F_224 ( V_377 ) ;
if ( V_63 >= V_132 ) {
F_8 ( V_2 -> V_11 , L_24 , V_63 ) ;
return - V_72 ;
}
if ( V_2 -> V_73 [ V_63 ] ) {
F_8 ( V_2 -> V_11 , L_25 , V_63 ) ;
return - V_72 ;
}
V_2 -> V_73 [ V_63 ] = F_225 ( sizeof( * V_27 ) ) ;
if ( ! V_2 -> V_73 [ V_63 ] ) {
F_8 ( V_2 -> V_11 , L_26 ) ;
return - V_99 ;
}
V_27 = F_14 ( V_2 -> V_73 [ V_63 ] ) ;
V_2 -> V_27 [ V_63 ] = V_27 ;
V_27 -> V_63 = V_63 ;
V_27 -> V_62 = V_2 ;
V_27 -> V_79 = V_77 ;
V_27 -> V_114 = F_226 ( V_2 -> V_11 ,
sizeof( * V_27 -> V_114 ) ,
V_173 ) ;
if ( ! V_27 -> V_114 ) {
F_8 ( V_2 -> V_11 , L_27 ) ;
V_97 = - V_99 ;
goto F_202;
}
F_227 ( & V_27 -> V_114 -> V_133 ) ;
V_27 -> V_114 -> V_117 = V_63 * V_378 ;
F_228 ( V_2 -> V_73 [ V_63 ] , V_2 -> V_11 ) ;
V_2 -> V_73 [ V_63 ] -> V_379 = 5 * V_380 ;
V_2 -> V_73 [ V_63 ] -> V_381 = & V_382 ;
V_2 -> V_73 [ V_63 ] -> V_383 = ( unsigned long ) V_2 -> V_5 ;
V_2 -> V_73 [ V_63 ] -> V_384 = V_385 &
~ ( V_386 | V_266 ) ;
V_2 -> V_73 [ V_63 ] -> V_265 |= V_385 ;
V_2 -> V_73 [ V_63 ] -> V_387 = & V_388 ;
V_97 = F_229 ( V_2 -> V_73 [ V_63 ] ) ;
if ( V_97 ) {
F_8 ( V_2 -> V_11 , L_28 ) ;
goto F_202;
}
V_2 -> V_73 [ V_63 ] -> V_315 = V_2 -> V_315 ;
F_230 ( V_2 , V_389 , V_2 -> V_73 [ V_63 ] ,
L_29 ,
V_2 -> V_73 [ V_63 ] -> V_383 , V_2 -> V_73 [ V_63 ] -> V_315 ) ;
return 0 ;
F_202:
F_202 ( V_2 -> V_73 [ V_63 ] ) ;
return V_97 ;
}
static int F_231 ( struct V_390 * V_391 )
{
struct V_392 * V_393 = F_232 ( V_391 , V_394 , 0 ) ;
struct V_64 * V_395 ;
const struct V_396 * V_397 ;
struct V_398 * V_399 ;
struct V_1 * V_2 ;
int V_97 ;
V_397 = F_233 ( V_400 , & V_391 -> V_11 ) ;
V_399 = (struct V_398 * ) V_397 -> V_216 ;
V_2 = F_226 ( & V_391 -> V_11 , sizeof( * V_2 ) , V_173 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_5 = F_234 ( & V_391 -> V_11 , V_393 ) ;
if ( F_235 ( V_2 -> V_5 ) )
return F_236 ( V_2 -> V_5 ) ;
F_227 ( & V_2 -> V_112 ) ;
V_2 -> V_86 = F_237 ( V_391 -> V_11 . V_79 ,
L_30 ) ;
if ( F_235 ( V_2 -> V_86 ) ) {
F_8 ( & V_391 -> V_11 , L_31 ) ;
return F_236 ( V_2 -> V_86 ) ;
}
V_2 -> V_330 = F_237 ( V_391 -> V_11 . V_79 ,
L_32 ) ;
if ( F_235 ( V_2 -> V_330 ) ) {
F_8 ( & V_391 -> V_11 , L_33 ) ;
return F_236 ( V_2 -> V_330 ) ;
}
V_2 -> V_329 = F_238 ( & V_391 -> V_11 , L_34 ) ;
if ( F_235 ( V_2 -> V_329 ) ) {
F_8 ( & V_391 -> V_11 , L_35 ) ;
return F_236 ( V_2 -> V_329 ) ;
}
V_2 -> V_315 = F_239 ( V_391 , 0 ) ;
if ( V_2 -> V_315 < 0 ) {
F_8 ( & V_391 -> V_11 , L_36 ) ;
return - V_401 ;
}
V_2 -> V_402 = F_240 ( & V_391 -> V_11 , L_37 ) ;
V_2 -> V_403 = F_240 ( & V_391 -> V_11 , L_38 ) ;
V_2 -> V_404 = F_240 ( & V_391 -> V_11 , L_39 ) ;
V_2 -> V_405 = F_240 ( & V_391 -> V_11 , L_40 ) ;
if ( F_235 ( V_2 -> V_403 ) || F_235 ( V_2 -> V_404 ) ||
F_235 ( V_2 -> V_405 ) || F_235 ( V_2 -> V_402 ) )
return - V_74 ;
F_241 ( V_2 -> V_402 ) ;
F_241 ( V_2 -> V_403 ) ;
F_241 ( V_2 -> V_404 ) ;
F_241 ( V_2 -> V_405 ) ;
V_2 -> V_11 = & V_391 -> V_11 ;
V_2 -> V_366 = F_242 ( V_406 , V_407 ) ;
F_243 ( & V_2 -> V_314 , F_193 ) ;
V_97 = F_177 ( V_2 ) ;
if ( V_97 )
return V_97 ;
F_244 (pdev->dev.of_node, mac_np) {
if ( ! F_245 ( V_395 ,
L_41 ) )
continue;
if ( ! F_39 ( V_395 ) )
continue;
V_97 = F_223 ( V_2 , V_395 ) ;
if ( V_97 )
goto V_408;
}
F_246 ( & V_2 -> V_409 ) ;
F_247 ( & V_2 -> V_409 , & V_2 -> V_281 , F_140 ,
V_410 ) ;
F_248 ( V_391 , V_2 ) ;
return 0 ;
V_408:
F_200 ( V_2 ) ;
return V_97 ;
}
static int F_249 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_250 ( V_391 ) ;
F_251 ( V_2 -> V_402 ) ;
F_251 ( V_2 -> V_403 ) ;
F_251 ( V_2 -> V_404 ) ;
F_251 ( V_2 -> V_405 ) ;
F_252 ( & V_2 -> V_281 ) ;
F_200 ( V_2 ) ;
F_248 ( V_391 , NULL ) ;
return 0 ;
}
