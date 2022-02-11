static inline void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 = 0 ;
}
static inline void F_2 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 = ( ( 1 << V_4 ) - 1 )
& ~ V_5 ;
}
static inline void F_3 ( struct V_1 * V_1 , int V_6 )
{
V_1 -> V_2 . V_3 &= ~ ( 1 << V_6 ) ;
}
static inline struct V_7 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( V_9 , struct V_7 , V_9 ) ;
}
static void F_6 ( struct V_7 * V_10 )
{
struct V_11 * V_12 , * V_13 ;
struct V_14 * V_15 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return;
V_12 = & V_10 -> V_1 -> V_2 ;
V_13 = & V_10 -> V_17 . V_18 -> V_2 ;
V_15 = & V_10 -> V_17 ;
V_12 -> V_19 = V_13 -> V_19 | V_15 -> V_19 ;
V_12 -> V_20 = V_13 -> V_20 | V_15 -> V_20 ;
V_12 -> V_21 = V_13 -> V_21 | V_15 -> V_21 ;
V_12 -> V_22 = V_13 -> V_22 | V_15 -> V_22 ;
}
static inline struct V_1 * F_8 ( struct V_7 * V_10 )
{
if ( F_7 ( & V_10 -> V_9 ) )
return V_10 -> V_17 . V_18 ;
else
return V_10 -> V_1 ;
}
static inline void F_9 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_19 |= ( 1U << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_10 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_19 &= ~ ( 1U << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline bool F_11 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
return V_1 -> V_2 . V_19 & ( 1U << V_6 ) ;
}
static inline void F_12 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_20 = ( 1 << V_23 )
| ( 1 << V_24 )
| ( 1 << V_25 )
| ( 1 << V_26 )
| ( 1 << V_27 )
| ( 1 << V_28 )
| ( 1 << V_29 )
| ( 1 << V_30 )
| ( 1 << V_31 )
| ( 1 << V_32 )
| ( 1 << V_33 )
| ( 1 << V_34 )
| ( 1 << V_35 )
| ( 1 << V_36 )
| ( 1 << V_37 )
| ( 1 << V_38 ) ;
F_6 ( V_10 ) ;
}
static inline void F_13 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_20 = 0 ;
F_6 ( V_10 ) ;
}
static inline void F_14 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_21 |= ( 1U << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_15 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_21 &= ~ ( 1U << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_16 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_22 |= ( 1ULL << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_17 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_22 &= ~ ( 1ULL << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_18 ( struct V_7 * V_10 )
{
V_10 -> V_9 . V_39 . V_40 |= V_41 ;
}
static inline void F_19 ( struct V_7 * V_10 )
{
V_10 -> V_9 . V_39 . V_40 &= ~ V_41 ;
}
static inline bool F_20 ( struct V_7 * V_10 )
{
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_41 ) ;
}
static T_1 F_21 ( T_1 V_42 )
{
T_1 V_43 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( V_42 < V_46 [ V_44 ] ||
V_42 >= V_46 [ V_44 ] + V_47 )
continue;
V_43 = ( V_42 - V_46 [ V_44 ] ) / 4 ;
V_43 += ( V_44 * V_48 ) ;
return V_43 / 4 ;
}
return V_49 ;
}
static inline void F_22 ( void )
{
asm volatile (__ex(SVM_CLGI));
}
static inline void F_23 ( void )
{
asm volatile (__ex(SVM_STGI));
}
static inline void F_24 ( unsigned long V_50 , T_1 V_51 )
{
asm volatile (__ex(SVM_INVLPGA) : : "a"(addr), "c"(asid));
}
static int F_25 ( void )
{
#ifdef F_26
return V_52 ;
#else
return V_53 ;
#endif
}
static void F_27 ( struct V_8 * V_9 , T_2 V_54 )
{
V_9 -> V_39 . V_54 = V_54 ;
if ( ! V_55 && ! ( V_54 & V_56 ) )
V_54 &= ~ V_57 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_54 = V_54 | V_59 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
}
static int F_28 ( T_1 V_61 )
{
V_61 &= V_62 | V_63 ;
return V_61 == ( V_63 | V_64 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_65 = 0 ;
if ( V_10 -> V_1 -> V_2 . V_66 & V_67 )
V_65 = V_68 | V_69 ;
return V_65 ;
}
static void F_30 ( struct V_8 * V_9 , int V_70 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_70 == 0 )
V_10 -> V_1 -> V_2 . V_66 &= ~ V_67 ;
else
V_10 -> V_1 -> V_2 . V_66 |= V_67 ;
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_71 != 0 ) {
F_32 ( ! F_33 ( V_72 ) ) ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_71 ;
}
if ( ! V_10 -> V_71 ) {
if ( F_34 ( V_9 , V_73 ) !=
V_74 )
F_35 ( V_75 L_1 , V_76 ) ;
return;
}
if ( V_10 -> V_71 - F_36 ( V_9 ) > V_77 )
F_35 ( V_78 L_2 ,
V_76 , F_36 ( V_9 ) , V_10 -> V_71 ) ;
F_37 ( V_9 , V_10 -> V_71 ) ;
F_30 ( V_9 , 0 ) ;
}
static void F_38 ( struct V_8 * V_9 , unsigned V_79 ,
bool V_80 , T_1 V_81 ,
bool V_82 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! V_82 &&
F_39 ( V_10 , V_79 , V_80 , V_81 ) )
return;
if ( V_79 == V_83 && ! F_33 ( V_72 ) ) {
unsigned long V_84 , V_85 = F_36 ( & V_10 -> V_9 ) ;
F_31 ( & V_10 -> V_9 ) ;
V_84 = F_36 ( & V_10 -> V_9 ) ;
V_10 -> V_86 = V_84 + V_10 -> V_1 -> V_58 . V_87 . V_88 ;
V_10 -> V_89 = V_84 - V_85 ;
}
V_10 -> V_1 -> V_2 . V_90 = V_79
| V_63
| ( V_80 ? V_91 : 0 )
| V_92 ;
V_10 -> V_1 -> V_2 . V_93 = V_81 ;
}
static void F_40 ( void )
{
T_1 V_94 , V_95 ;
int V_96 ;
T_2 V_97 ;
if ( ! F_41 ( V_98 ) )
return;
V_97 = F_42 ( V_99 , & V_96 ) ;
if ( V_96 )
return;
V_97 |= ( 1ULL << 47 ) ;
V_94 = F_43 ( V_97 ) ;
V_95 = F_44 ( V_97 ) ;
F_45 ( V_99 , V_94 , V_95 ) ;
V_100 = true ;
}
static void F_46 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_101 . V_102 = ( V_103 >= 3 ) ? ( V_103 ) : 3 ;
V_9 -> V_39 . V_101 . V_104 = V_105 & ~ ( 6ULL ) ;
if ( V_103 == 0 && V_106 . V_107 == 0x10 )
V_9 -> V_39 . V_101 . V_104 |= 1 ;
}
static int F_47 ( void )
{
const char * V_108 ;
if ( ! F_48 ( & V_108 ) ) {
F_35 ( V_109 L_3 , V_108 ) ;
return 0 ;
}
return 1 ;
}
static void F_49 ( void )
{
if ( F_33 ( V_110 ) )
F_50 ( V_111 , V_112 ) ;
F_51 () ;
F_52 () ;
}
static int F_53 ( void )
{
struct V_113 * V_114 ;
T_3 V_54 ;
struct V_115 V_116 ;
struct V_117 * V_118 ;
int V_119 = F_54 () ;
F_55 ( V_120 , V_54 ) ;
if ( V_54 & V_59 )
return - V_121 ;
if ( ! F_47 () ) {
F_56 ( L_4 , V_76 , V_119 ) ;
return - V_122 ;
}
V_114 = F_57 ( V_123 , V_119 ) ;
if ( ! V_114 ) {
F_56 ( L_5 , V_76 , V_119 ) ;
return - V_122 ;
}
V_114 -> V_124 = 1 ;
V_114 -> V_125 = F_58 ( V_126 ) - 1 ;
V_114 -> V_127 = V_114 -> V_125 + 1 ;
F_59 ( & V_116 ) ;
V_118 = (struct V_117 * ) V_116 . V_128 ;
V_114 -> V_129 = (struct V_130 * ) ( V_118 + V_131 ) ;
F_50 ( V_120 , V_54 | V_59 ) ;
F_50 ( V_132 , F_60 ( V_114 -> V_133 ) << V_134 ) ;
if ( F_33 ( V_110 ) ) {
F_50 ( V_111 , V_112 ) ;
F_61 ( V_135 , V_112 ) ;
}
if ( F_62 ( & V_106 , V_136 ) ) {
T_3 V_137 , V_104 = 0 ;
int V_96 ;
V_137 = F_42 ( V_138 , & V_96 ) ;
if ( ! V_96 )
V_104 = F_42 ( V_139 ,
& V_96 ) ;
if ( V_96 )
V_105 = V_103 = 0 ;
else {
if ( V_137 < V_103 )
V_103 = V_137 ;
V_105 |= V_104 ;
V_105 &= ( 1ULL << V_103 ) - 1 ;
}
} else
V_105 = V_103 = 0 ;
F_40 () ;
F_63 () ;
return 0 ;
}
static void F_64 ( int V_140 )
{
struct V_113 * V_114 = F_57 ( V_123 , F_54 () ) ;
if ( ! V_114 )
return;
F_57 ( V_123 , F_54 () ) = NULL ;
F_65 ( V_114 -> V_133 ) ;
F_66 ( V_114 ) ;
}
static int F_67 ( int V_140 )
{
struct V_113 * V_114 ;
int V_141 ;
V_114 = F_68 ( sizeof( struct V_113 ) , V_142 ) ;
if ( ! V_114 )
return - V_143 ;
V_114 -> V_140 = V_140 ;
V_114 -> V_133 = F_69 ( V_142 ) ;
V_141 = - V_143 ;
if ( ! V_114 -> V_133 )
goto V_144;
F_57 ( V_123 , V_140 ) = V_114 ;
return 0 ;
V_144:
F_66 ( V_114 ) ;
return V_141 ;
}
static bool F_70 ( T_1 V_145 )
{
int V_44 ;
for ( V_44 = 0 ; V_146 [ V_44 ] . V_145 != V_49 ; V_44 ++ )
if ( V_146 [ V_44 ] . V_145 == V_145 )
return true ;
return false ;
}
static void F_71 ( T_1 * V_147 , unsigned V_42 ,
int V_148 , int V_149 )
{
T_4 V_150 , V_151 ;
unsigned long V_152 ;
T_1 V_43 ;
F_72 ( ! F_70 ( V_42 ) ) ;
V_43 = F_21 ( V_42 ) ;
V_150 = 2 * ( V_42 & 0x0f ) ;
V_151 = 2 * ( V_42 & 0x0f ) + 1 ;
V_152 = V_147 [ V_43 ] ;
F_73 ( V_43 == V_49 ) ;
V_148 ? F_74 ( V_150 , & V_152 ) : F_75 ( V_150 , & V_152 ) ;
V_149 ? F_74 ( V_151 , & V_152 ) : F_75 ( V_151 , & V_152 ) ;
V_147 [ V_43 ] = V_152 ;
}
static void F_76 ( T_1 * V_147 )
{
int V_44 ;
memset ( V_147 , 0xff , V_153 * ( 1 << V_154 ) ) ;
for ( V_44 = 0 ; V_146 [ V_44 ] . V_145 != V_49 ; V_44 ++ ) {
if ( ! V_146 [ V_44 ] . V_155 )
continue;
F_71 ( V_147 , V_146 [ V_44 ] . V_145 , 1 , 1 ) ;
}
}
static void F_77 ( T_1 V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_156 ; ++ V_44 ) {
if ( V_157 [ V_44 ] == V_43 )
return;
if ( V_157 [ V_44 ] != V_49 )
continue;
V_157 [ V_44 ] = V_43 ;
return;
}
F_78 () ;
}
static void F_79 ( void )
{
int V_44 ;
memset ( V_157 , 0xff , sizeof( V_157 ) ) ;
for ( V_44 = 0 ; V_146 [ V_44 ] . V_145 != V_49 ; V_44 ++ ) {
T_1 V_43 ;
V_43 = F_21 ( V_146 [ V_44 ] . V_145 ) ;
F_73 ( V_43 == V_49 ) ;
F_77 ( V_43 ) ;
}
}
static void F_80 ( struct V_7 * V_10 )
{
T_1 * V_147 = V_10 -> V_147 ;
V_10 -> V_1 -> V_2 . V_158 = 1 ;
F_71 ( V_147 , V_159 , 1 , 1 ) ;
F_71 ( V_147 , V_160 , 1 , 1 ) ;
F_71 ( V_147 , V_161 , 1 , 1 ) ;
F_71 ( V_147 , V_162 , 1 , 1 ) ;
}
static void F_81 ( struct V_7 * V_10 )
{
T_1 * V_147 = V_10 -> V_147 ;
V_10 -> V_1 -> V_2 . V_158 = 0 ;
F_71 ( V_147 , V_159 , 0 , 0 ) ;
F_71 ( V_147 , V_160 , 0 , 0 ) ;
F_71 ( V_147 , V_161 , 0 , 0 ) ;
F_71 ( V_147 , V_162 , 0 , 0 ) ;
}
static T_5 int F_82 ( void )
{
int V_140 ;
struct V_163 * V_164 ;
void * V_165 ;
int V_141 ;
V_164 = F_83 ( V_142 , V_166 ) ;
if ( ! V_164 )
return - V_143 ;
V_165 = F_84 ( V_164 ) ;
memset ( V_165 , 0xff , V_153 * ( 1 << V_166 ) ) ;
V_167 = F_60 ( V_164 ) << V_134 ;
F_79 () ;
if ( F_85 ( V_168 ) )
F_86 ( V_169 ) ;
if ( F_85 ( V_170 ) )
F_86 ( V_171 ) ;
if ( F_85 ( V_110 ) ) {
V_172 = true ;
V_173 = V_174 ;
V_175 = 32 ;
}
if ( V_17 ) {
F_35 ( V_109 L_6 ) ;
F_86 ( V_59 | V_176 ) ;
}
F_87 (cpu) {
V_141 = F_67 ( V_140 ) ;
if ( V_141 )
goto V_96;
}
if ( ! F_85 ( V_177 ) )
V_55 = false ;
if ( V_55 && ! V_178 ) {
F_35 ( V_109 L_7 ) ;
V_55 = false ;
}
if ( V_55 ) {
F_35 ( V_109 L_8 ) ;
F_88 () ;
} else
F_89 () ;
return 0 ;
V_96:
F_90 ( V_164 , V_166 ) ;
V_167 = 0 ;
return V_141 ;
}
static T_6 void F_91 ( void )
{
int V_140 ;
F_87 (cpu)
F_64 ( V_140 ) ;
F_90 ( F_92 ( V_167 >> V_134 ) , V_166 ) ;
V_167 = 0 ;
}
static void F_93 ( struct V_179 * V_180 )
{
V_180 -> V_181 = 0 ;
V_180 -> V_182 = V_183 | V_184 |
V_185 ;
V_180 -> V_186 = 0xffff ;
V_180 -> V_88 = 0 ;
}
static void F_94 ( struct V_179 * V_180 , T_7 type )
{
V_180 -> V_181 = 0 ;
V_180 -> V_182 = V_183 | type ;
V_180 -> V_186 = 0xffff ;
V_180 -> V_88 = 0 ;
}
static T_2 F_95 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_187 ;
}
static void F_96 ( struct V_8 * V_9 , T_2 V_43 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_188 = 0 ;
if ( F_7 ( V_9 ) ) {
V_188 = V_10 -> V_1 -> V_2 . V_187 -
V_10 -> V_17 . V_18 -> V_2 . V_187 ;
V_10 -> V_17 . V_18 -> V_2 . V_187 = V_43 ;
} else
F_97 ( V_9 -> V_189 ,
V_10 -> V_1 -> V_2 . V_187 ,
V_43 ) ;
V_10 -> V_1 -> V_2 . V_187 = V_43 + V_188 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_98 ( struct V_8 * V_9 , T_8 V_190 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_187 += V_190 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_187 += V_190 ;
else
F_97 ( V_9 -> V_189 ,
V_10 -> V_1 -> V_2 . V_187 - V_190 ,
V_10 -> V_1 -> V_2 . V_187 ) ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_99 ( struct V_7 * V_10 )
{
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_191 * V_58 = & V_10 -> V_1 -> V_58 ;
V_10 -> V_9 . V_192 = 1 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
F_9 ( V_10 , V_193 ) ;
F_9 ( V_10 , V_194 ) ;
F_9 ( V_10 , V_195 ) ;
F_9 ( V_10 , V_196 ) ;
F_9 ( V_10 , V_197 ) ;
F_9 ( V_10 , V_198 ) ;
F_9 ( V_10 , V_199 ) ;
F_12 ( V_10 ) ;
F_14 ( V_10 , V_200 ) ;
F_14 ( V_10 , V_201 ) ;
F_14 ( V_10 , V_202 ) ;
F_14 ( V_10 , V_203 ) ;
F_14 ( V_10 , V_204 ) ;
F_16 ( V_10 , V_205 ) ;
F_16 ( V_10 , V_206 ) ;
F_16 ( V_10 , V_207 ) ;
F_16 ( V_10 , V_208 ) ;
F_16 ( V_10 , V_209 ) ;
F_16 ( V_10 , V_210 ) ;
F_16 ( V_10 , V_211 ) ;
F_16 ( V_10 , V_212 ) ;
F_16 ( V_10 , V_213 ) ;
F_16 ( V_10 , V_214 ) ;
F_16 ( V_10 , V_215 ) ;
F_16 ( V_10 , V_216 ) ;
F_16 ( V_10 , V_217 ) ;
F_16 ( V_10 , V_218 ) ;
F_16 ( V_10 , V_219 ) ;
F_16 ( V_10 , V_220 ) ;
F_16 ( V_10 , V_221 ) ;
F_16 ( V_10 , V_222 ) ;
F_16 ( V_10 , V_223 ) ;
F_16 ( V_10 , V_224 ) ;
F_16 ( V_10 , V_225 ) ;
F_16 ( V_10 , V_226 ) ;
F_16 ( V_10 , V_227 ) ;
F_16 ( V_10 , V_228 ) ;
F_16 ( V_10 , V_229 ) ;
V_2 -> V_230 = V_167 ;
V_2 -> V_231 = F_100 ( V_10 -> V_147 ) ;
V_2 -> V_232 = V_233 ;
F_93 ( & V_58 -> V_234 ) ;
F_93 ( & V_58 -> V_235 ) ;
F_93 ( & V_58 -> V_236 ) ;
F_93 ( & V_58 -> V_237 ) ;
F_93 ( & V_58 -> V_238 ) ;
V_58 -> V_87 . V_181 = 0xf000 ;
V_58 -> V_87 . V_88 = 0xffff0000 ;
V_58 -> V_87 . V_182 = V_239 | V_183 |
V_184 | V_240 ;
V_58 -> V_87 . V_186 = 0xffff ;
V_58 -> V_241 . V_186 = 0xffff ;
V_58 -> V_242 . V_186 = 0xffff ;
F_94 ( & V_58 -> V_243 , V_244 ) ;
F_94 ( & V_58 -> V_245 , V_246 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_58 -> V_247 = 0xffff0ff0 ;
F_101 ( & V_10 -> V_9 , 2 ) ;
V_58 -> V_84 = 0x0000fff0 ;
V_10 -> V_9 . V_39 . V_248 [ V_249 ] = V_58 -> V_84 ;
F_102 ( & V_10 -> V_9 , V_250 | V_251 | V_252 ) ;
F_103 ( & V_10 -> V_9 ) ;
V_58 -> V_253 = V_254 ;
if ( V_55 ) {
V_2 -> V_255 = 1 ;
F_17 ( V_10 , V_213 ) ;
F_15 ( V_10 , V_200 ) ;
F_10 ( V_10 , V_194 ) ;
F_10 ( V_10 , V_197 ) ;
V_58 -> V_256 = V_10 -> V_9 . V_39 . V_257 ;
V_58 -> V_258 = 0 ;
V_58 -> V_253 = 0 ;
}
V_10 -> V_124 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
if ( F_85 ( V_259 ) ) {
V_2 -> V_260 = 3000 ;
F_16 ( V_10 , V_261 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static void F_104 ( struct V_8 * V_9 , bool V_262 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_263 ;
T_1 V_264 = 1 ;
if ( ! V_262 ) {
V_10 -> V_9 . V_39 . V_265 = V_266 |
V_267 ;
if ( F_105 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_39 . V_265 |= V_268 ;
}
F_99 ( V_10 ) ;
F_106 ( V_9 , & V_264 , & V_263 , & V_263 , & V_263 ) ;
F_107 ( V_9 , V_269 , V_264 ) ;
}
static struct V_8 * F_108 ( struct V_270 * V_270 , unsigned int V_271 )
{
struct V_7 * V_10 ;
struct V_163 * V_163 ;
struct V_163 * V_272 ;
struct V_163 * V_273 ;
struct V_163 * V_274 ;
int V_96 ;
V_10 = F_109 ( V_275 , V_142 ) ;
if ( ! V_10 ) {
V_96 = - V_143 ;
goto V_276;
}
V_96 = F_110 ( & V_10 -> V_9 , V_270 , V_271 ) ;
if ( V_96 )
goto V_277;
V_96 = - V_143 ;
V_163 = F_69 ( V_142 ) ;
if ( ! V_163 )
goto V_278;
V_272 = F_83 ( V_142 , V_154 ) ;
if ( ! V_272 )
goto V_279;
V_274 = F_83 ( V_142 , V_154 ) ;
if ( ! V_274 )
goto V_280;
V_273 = F_69 ( V_142 ) ;
if ( ! V_273 )
goto V_281;
V_10 -> V_17 . V_18 = F_84 ( V_273 ) ;
V_10 -> V_147 = F_84 ( V_272 ) ;
F_76 ( V_10 -> V_147 ) ;
V_10 -> V_17 . V_147 = F_84 ( V_274 ) ;
F_76 ( V_10 -> V_17 . V_147 ) ;
V_10 -> V_1 = F_84 ( V_163 ) ;
F_111 ( V_10 -> V_1 ) ;
V_10 -> V_282 = F_60 ( V_163 ) << V_134 ;
V_10 -> V_124 = 0 ;
F_99 ( V_10 ) ;
F_46 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_281:
F_90 ( V_274 , V_154 ) ;
V_280:
F_90 ( V_272 , V_154 ) ;
V_279:
F_65 ( V_163 ) ;
V_278:
F_112 ( & V_10 -> V_9 ) ;
V_277:
F_113 ( V_275 , V_10 ) ;
V_276:
return F_114 ( V_96 ) ;
}
static void F_115 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_65 ( F_92 ( V_10 -> V_282 >> V_134 ) ) ;
F_90 ( F_116 ( V_10 -> V_147 ) , V_154 ) ;
F_65 ( F_116 ( V_10 -> V_17 . V_18 ) ) ;
F_90 ( F_116 ( V_10 -> V_17 . V_147 ) , V_154 ) ;
F_112 ( V_9 ) ;
F_113 ( V_275 , V_10 ) ;
}
static void F_117 ( struct V_8 * V_9 , int V_140 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
if ( F_118 ( V_140 != V_9 -> V_140 ) ) {
V_10 -> V_124 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_55 ( V_283 , F_4 ( V_9 ) -> V_284 . V_285 ) ;
#endif
F_119 ( V_237 , V_10 -> V_284 . V_237 ) ;
F_119 ( V_238 , V_10 -> V_284 . V_238 ) ;
V_10 -> V_284 . V_286 = F_120 () ;
for ( V_44 = 0 ; V_44 < V_287 ; V_44 ++ )
F_55 ( V_288 [ V_44 ] , V_10 -> V_289 [ V_44 ] ) ;
if ( F_33 ( V_110 ) ) {
T_2 V_290 = V_9 -> V_39 . V_291 ;
if ( V_290 != F_121 ( V_135 ) ) {
F_61 ( V_135 , V_290 ) ;
F_50 ( V_111 , V_290 ) ;
}
}
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
++ V_9 -> V_292 . V_293 ;
F_123 ( V_10 -> V_284 . V_286 ) ;
#ifdef F_26
F_124 ( V_237 , V_10 -> V_284 . V_237 ) ;
F_50 ( V_294 , V_295 -> V_296 . V_238 ) ;
F_125 ( V_10 -> V_284 . V_238 ) ;
#else
#ifdef F_126
F_124 ( V_238 , V_10 -> V_284 . V_238 ) ;
#endif
#endif
for ( V_44 = 0 ; V_44 < V_287 ; V_44 ++ )
F_50 ( V_288 [ V_44 ] , V_10 -> V_289 [ V_44 ] ) ;
}
static unsigned long F_127 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_297 ;
}
static void F_128 ( struct V_8 * V_9 , unsigned long V_297 )
{
F_4 ( V_9 ) -> V_1 -> V_58 . V_297 = V_297 ;
}
static void F_129 ( struct V_8 * V_9 , enum V_298 V_299 )
{
switch ( V_299 ) {
case V_300 :
F_73 ( ! V_55 ) ;
F_130 ( V_9 , V_9 -> V_39 . V_301 , F_131 ( V_9 ) ) ;
break;
default:
F_78 () ;
}
}
static void F_132 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_302 ) ;
}
static void F_133 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_302 ) ;
}
static struct V_179 * F_134 ( struct V_8 * V_9 , int V_180 )
{
struct V_191 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_180 ) {
case V_303 : return & V_58 -> V_87 ;
case V_304 : return & V_58 -> V_236 ;
case V_305 : return & V_58 -> V_234 ;
case V_306 : return & V_58 -> V_237 ;
case V_307 : return & V_58 -> V_238 ;
case V_308 : return & V_58 -> V_235 ;
case V_309 : return & V_58 -> V_245 ;
case V_310 : return & V_58 -> V_243 ;
}
F_78 () ;
return NULL ;
}
static T_2 F_135 ( struct V_8 * V_9 , int V_180 )
{
struct V_179 * V_311 = F_134 ( V_9 , V_180 ) ;
return V_311 -> V_88 ;
}
static void F_136 ( struct V_8 * V_9 ,
struct V_312 * V_313 , int V_180 )
{
struct V_179 * V_311 = F_134 ( V_9 , V_180 ) ;
V_313 -> V_88 = V_311 -> V_88 ;
V_313 -> V_186 = V_311 -> V_186 ;
V_313 -> V_181 = V_311 -> V_181 ;
V_313 -> type = V_311 -> V_182 & V_314 ;
V_313 -> V_311 = ( V_311 -> V_182 >> V_315 ) & 1 ;
V_313 -> V_316 = ( V_311 -> V_182 >> V_317 ) & 3 ;
V_313 -> V_318 = ( V_311 -> V_182 >> V_319 ) & 1 ;
V_313 -> V_320 = ( V_311 -> V_182 >> V_321 ) & 1 ;
V_313 -> V_322 = ( V_311 -> V_182 >> V_323 ) & 1 ;
V_313 -> V_324 = ( V_311 -> V_182 >> V_325 ) & 1 ;
V_313 -> V_15 = V_311 -> V_186 > 0xfffff ;
V_313 -> V_326 = ! V_313 -> V_318 || ( V_313 -> type == 0 ) ;
switch ( V_180 ) {
case V_309 :
V_313 -> type |= 0x2 ;
break;
case V_304 :
case V_305 :
case V_306 :
case V_307 :
if ( ! V_313 -> V_326 )
V_313 -> type |= 0x1 ;
break;
case V_308 :
if ( V_313 -> V_326 )
V_313 -> V_324 = 0 ;
V_313 -> V_316 = F_4 ( V_9 ) -> V_1 -> V_58 . V_327 ;
break;
}
}
static int F_137 ( struct V_8 * V_9 )
{
struct V_191 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_327 ;
}
static void F_138 ( struct V_8 * V_9 , struct V_115 * V_328 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_328 -> V_329 = V_10 -> V_1 -> V_58 . V_242 . V_186 ;
V_328 -> V_128 = V_10 -> V_1 -> V_58 . V_242 . V_88 ;
}
static void F_139 ( struct V_8 * V_9 , struct V_115 * V_328 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_242 . V_186 = V_328 -> V_329 ;
V_10 -> V_1 -> V_58 . V_242 . V_88 = V_328 -> V_128 ;
F_3 ( V_10 -> V_1 , V_330 ) ;
}
static void F_140 ( struct V_8 * V_9 , struct V_115 * V_328 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_328 -> V_329 = V_10 -> V_1 -> V_58 . V_241 . V_186 ;
V_328 -> V_128 = V_10 -> V_1 -> V_58 . V_241 . V_88 ;
}
static void F_141 ( struct V_8 * V_9 , struct V_115 * V_328 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_241 . V_186 = V_328 -> V_329 ;
V_10 -> V_1 -> V_58 . V_241 . V_88 = V_328 -> V_128 ;
F_3 ( V_10 -> V_1 , V_330 ) ;
}
static void F_142 ( struct V_8 * V_9 )
{
}
static void F_143 ( struct V_8 * V_9 )
{
}
static void F_144 ( struct V_8 * V_9 )
{
}
static void F_145 ( struct V_7 * V_10 )
{
T_9 V_331 = V_10 -> V_9 . V_39 . V_332 ;
T_2 * V_333 = & V_10 -> V_1 -> V_58 . V_332 ;
if ( ! V_10 -> V_9 . V_192 )
* V_333 |= V_334 ;
else
* V_333 = ( * V_333 & ~ V_334 )
| ( V_331 & V_334 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_331 == * V_333 && V_10 -> V_9 . V_192 ) {
F_10 ( V_10 , V_193 ) ;
F_10 ( V_10 , V_196 ) ;
} else {
F_9 ( V_10 , V_193 ) ;
F_9 ( V_10 , V_196 ) ;
}
}
static void F_102 ( struct V_8 * V_9 , unsigned long V_332 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_146 ( V_9 ) && ( V_332 & V_335 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_146 ( V_9 ) && ! ( V_332 & V_335 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_332 = V_332 ;
if ( ! V_55 )
V_332 |= V_335 | V_336 ;
if ( ! V_9 -> V_192 )
V_332 |= V_337 ;
if ( F_147 ( V_9 -> V_270 , V_338 ) )
V_332 &= ~ ( V_251 | V_250 ) ;
V_10 -> V_1 -> V_58 . V_332 = V_332 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_145 ( V_10 ) ;
}
static int F_148 ( struct V_8 * V_9 , unsigned long V_253 )
{
unsigned long V_339 = F_149 () & V_340 ;
unsigned long V_341 = F_4 ( V_9 ) -> V_1 -> V_58 . V_253 ;
if ( V_253 & V_342 )
return 1 ;
if ( V_55 && ( ( V_341 ^ V_253 ) & V_343 ) )
F_150 ( V_9 ) ;
V_9 -> V_39 . V_253 = V_253 ;
if ( ! V_55 )
V_253 |= V_254 ;
V_253 |= V_339 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_253 = V_253 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_151 ( struct V_8 * V_9 ,
struct V_312 * V_313 , int V_180 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_179 * V_311 = F_134 ( V_9 , V_180 ) ;
V_311 -> V_88 = V_313 -> V_88 ;
V_311 -> V_186 = V_313 -> V_186 ;
V_311 -> V_181 = V_313 -> V_181 ;
if ( V_313 -> V_326 )
V_311 -> V_182 = 0 ;
else {
V_311 -> V_182 = ( V_313 -> type & V_314 ) ;
V_311 -> V_182 |= ( V_313 -> V_311 & 1 ) << V_315 ;
V_311 -> V_182 |= ( V_313 -> V_316 & 3 ) << V_317 ;
V_311 -> V_182 |= ( V_313 -> V_318 & 1 ) << V_319 ;
V_311 -> V_182 |= ( V_313 -> V_320 & 1 ) << V_321 ;
V_311 -> V_182 |= ( V_313 -> V_322 & 1 ) << V_323 ;
V_311 -> V_182 |= ( V_313 -> V_324 & 1 ) << V_325 ;
V_311 -> V_182 |= ( V_313 -> V_15 & 1 ) << V_344 ;
}
if ( V_180 == V_308 )
V_10 -> V_1 -> V_58 . V_327 = ( V_311 -> V_182 >> V_317 ) & 3 ;
F_3 ( V_10 -> V_1 , V_345 ) ;
}
static void F_152 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_83 ) ;
if ( V_9 -> V_346 & V_347 ) {
if ( V_9 -> V_346 & V_348 )
F_14 ( V_10 , V_83 ) ;
} else
V_9 -> V_346 = 0 ;
}
static void F_153 ( struct V_7 * V_10 , struct V_113 * V_114 )
{
if ( V_114 -> V_127 > V_114 -> V_125 ) {
++ V_114 -> V_124 ;
V_114 -> V_127 = 1 ;
V_10 -> V_1 -> V_2 . V_349 = V_350 ;
}
V_10 -> V_124 = V_114 -> V_124 ;
V_10 -> V_1 -> V_2 . V_51 = V_114 -> V_127 ++ ;
F_3 ( V_10 -> V_1 , V_351 ) ;
}
static T_2 F_154 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_247 ;
}
static void F_155 ( struct V_8 * V_9 , unsigned long V_352 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_247 = V_352 ;
F_3 ( V_10 -> V_1 , V_353 ) ;
}
static void F_156 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_157 ( V_9 -> V_39 . V_324 [ 0 ] , 0 ) ;
F_157 ( V_9 -> V_39 . V_324 [ 1 ] , 1 ) ;
F_157 ( V_9 -> V_39 . V_324 [ 2 ] , 2 ) ;
F_157 ( V_9 -> V_39 . V_324 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_247 = F_154 ( V_9 ) ;
V_9 -> V_39 . V_354 = V_10 -> V_1 -> V_58 . V_354 ;
V_9 -> V_39 . V_355 &= ~ V_356 ;
F_12 ( V_10 ) ;
}
static void F_158 ( struct V_8 * V_9 , unsigned long V_352 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_354 = V_352 ;
F_3 ( V_10 -> V_1 , V_353 ) ;
}
static int F_159 ( struct V_7 * V_10 )
{
T_2 V_357 = V_10 -> V_1 -> V_2 . V_358 ;
T_1 V_81 ;
int V_141 = 1 ;
switch ( V_10 -> V_359 ) {
default:
V_81 = V_10 -> V_1 -> V_2 . V_360 ;
F_160 ( V_357 , V_81 ) ;
if ( ! V_55 && F_161 ( & V_10 -> V_9 ) )
F_162 ( & V_10 -> V_9 , V_357 ) ;
V_141 = F_163 ( & V_10 -> V_9 , V_357 , V_81 ,
V_10 -> V_1 -> V_2 . V_361 ,
V_10 -> V_1 -> V_2 . V_362 ) ;
break;
case V_363 :
V_10 -> V_359 = 0 ;
F_164 () ;
F_165 ( V_357 ) ;
F_166 () ;
break;
case V_364 :
V_10 -> V_359 = 0 ;
F_164 () ;
F_167 ( V_357 ) ;
F_166 () ;
break;
}
return V_141 ;
}
static int F_168 ( struct V_7 * V_10 )
{
struct V_365 * V_365 = V_10 -> V_9 . V_366 ;
if ( ! ( V_10 -> V_9 . V_346 &
( V_367 | V_368 ) ) &&
! V_10 -> V_369 ) {
F_169 ( & V_10 -> V_9 , V_204 ) ;
return 1 ;
}
if ( V_10 -> V_369 ) {
V_10 -> V_369 = false ;
if ( ! ( V_10 -> V_9 . V_346 & V_367 ) )
V_10 -> V_1 -> V_58 . V_297 &=
~ ( V_370 | V_371 ) ;
}
if ( V_10 -> V_9 . V_346 &
( V_367 | V_368 ) ) {
V_365 -> V_372 = V_373 ;
V_365 -> V_374 . V_39 . V_375 =
V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_365 -> V_374 . V_39 . V_376 = V_204 ;
return 0 ;
}
return 1 ;
}
static int F_170 ( struct V_7 * V_10 )
{
struct V_365 * V_365 = V_10 -> V_9 . V_366 ;
V_365 -> V_372 = V_373 ;
V_365 -> V_374 . V_39 . V_375 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_365 -> V_374 . V_39 . V_376 = V_83 ;
return 0 ;
}
static int F_171 ( struct V_7 * V_10 )
{
int V_377 ;
V_377 = F_34 ( & V_10 -> V_9 , V_378 ) ;
if ( V_377 != V_74 )
F_169 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
static int F_172 ( struct V_7 * V_10 )
{
F_173 ( & V_10 -> V_9 , V_203 , 0 ) ;
return 1 ;
}
static void F_174 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_379 ) ;
V_10 -> V_9 . V_192 = 1 ;
F_145 ( V_10 ) ;
}
static int F_175 ( struct V_7 * V_10 )
{
F_174 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_176 ( void )
{
int V_96 , V_44 ;
T_2 V_352 ;
if ( ! V_100 )
return false ;
V_352 = F_42 ( V_380 , & V_96 ) ;
if ( V_96 )
return false ;
V_352 &= ~ ( 1ULL << 62 ) ;
if ( V_352 != 0xb600000000010015ULL )
return false ;
for ( V_44 = 0 ; V_44 < 6 ; ++ V_44 )
F_45 ( F_177 ( V_44 ) , 0 , 0 ) ;
V_352 = F_42 ( V_381 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_352 &= ~ ( 1ULL << 2 ) ;
V_94 = F_43 ( V_352 ) ;
V_95 = F_44 ( V_352 ) ;
F_45 ( V_381 , V_94 , V_95 ) ;
}
F_178 () ;
return true ;
}
static void F_179 ( struct V_7 * V_10 )
{
if ( F_176 () ) {
F_56 ( L_9 ) ;
F_180 ( V_382 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_181 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_182 ( struct V_7 * V_10 )
{
struct V_365 * V_365 = V_10 -> V_9 . V_366 ;
F_111 ( V_10 -> V_1 ) ;
F_99 ( V_10 ) ;
V_365 -> V_372 = V_383 ;
return 0 ;
}
static int F_183 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_384 = V_10 -> V_1 -> V_2 . V_360 ;
int V_329 , V_385 , string ;
unsigned V_386 ;
++ V_10 -> V_9 . V_292 . V_387 ;
string = ( V_384 & V_388 ) != 0 ;
V_385 = ( V_384 & V_389 ) != 0 ;
if ( string || V_385 )
return F_34 ( V_9 , 0 ) == V_74 ;
V_386 = V_384 >> 16 ;
V_329 = ( V_384 & V_390 ) >> V_391 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_358 ;
F_31 ( & V_10 -> V_9 ) ;
return F_184 ( V_9 , V_329 , V_386 ) ;
}
static int F_185 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_186 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_292 . V_392 ;
return 1 ;
}
static int F_187 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_188 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 1 ;
return F_189 ( & V_10 -> V_9 ) ;
}
static int F_190 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_191 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_192 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_393 ;
}
static T_2 F_193 ( struct V_8 * V_9 , int V_145 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_258 = V_10 -> V_17 . V_393 ;
T_2 V_394 ;
int V_65 ;
V_65 = F_194 ( V_9 , F_195 ( V_258 ) , & V_394 ,
F_196 ( V_258 ) + V_145 * 8 , 8 ) ;
if ( V_65 )
return 0 ;
return V_394 ;
}
static void F_197 ( struct V_8 * V_9 ,
unsigned long V_395 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_393 = V_395 ;
F_3 ( V_10 -> V_1 , V_396 ) ;
F_150 ( V_9 ) ;
}
static void F_198 ( struct V_8 * V_9 ,
struct V_397 * V_398 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_399 != V_400 ) {
V_10 -> V_1 -> V_2 . V_399 = V_400 ;
V_10 -> V_1 -> V_2 . V_401 = 0 ;
V_10 -> V_1 -> V_2 . V_360 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_358 = V_398 -> V_128 ;
}
V_10 -> V_1 -> V_2 . V_360 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_360 |= V_398 -> V_81 ;
if ( V_10 -> V_1 -> V_2 . V_360 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_360 &= ~ 1 ;
F_199 ( V_10 ) ;
}
static void F_200 ( struct V_8 * V_9 )
{
F_72 ( F_201 ( V_9 ) ) ;
F_202 ( V_9 ) ;
V_9 -> V_39 . V_402 . V_403 = F_197 ;
V_9 -> V_39 . V_402 . V_404 = F_192 ;
V_9 -> V_39 . V_402 . V_405 = F_193 ;
V_9 -> V_39 . V_402 . V_406 = F_198 ;
V_9 -> V_39 . V_402 . V_407 = F_25 () ;
F_203 ( V_9 , & V_9 -> V_39 . V_402 ) ;
V_9 -> V_39 . V_301 = & V_9 -> V_39 . V_408 ;
}
static void F_204 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_301 = & V_9 -> V_39 . V_402 ;
}
static int F_205 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_146 ( & V_10 -> V_9 ) ) {
F_169 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_327 ) {
F_206 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_7 * V_10 , unsigned V_79 ,
bool V_80 , T_1 V_81 )
{
int V_409 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_399 = V_410 + V_79 ;
V_10 -> V_1 -> V_2 . V_401 = 0 ;
V_10 -> V_1 -> V_2 . V_360 = V_81 ;
V_10 -> V_1 -> V_2 . V_358 = V_10 -> V_9 . V_39 . V_411 ;
V_409 = F_207 ( V_10 ) ;
if ( V_409 == V_412 )
V_10 -> V_17 . V_413 = true ;
return V_409 ;
}
static inline bool F_208 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_414 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_415 ) )
return false ;
if ( V_10 -> V_17 . V_413 )
return false ;
V_10 -> V_1 -> V_2 . V_399 = V_416 ;
V_10 -> V_1 -> V_2 . V_360 = 0 ;
V_10 -> V_1 -> V_2 . V_358 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_413 = true ;
F_209 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_210 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_206 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_399 = V_417 ;
V_10 -> V_17 . V_413 = true ;
return false ;
}
static void * F_211 ( struct V_7 * V_10 , T_2 V_418 , struct V_163 * * V_419 )
{
struct V_163 * V_163 ;
F_212 () ;
V_163 = F_213 ( & V_10 -> V_9 , V_418 >> V_134 ) ;
if ( F_214 ( V_163 ) )
goto error;
* V_419 = V_163 ;
return F_215 ( V_163 ) ;
error:
F_206 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_216 ( struct V_163 * V_163 )
{
F_217 ( V_163 ) ;
F_218 ( V_163 ) ;
}
static int F_219 ( struct V_7 * V_10 )
{
unsigned V_386 , V_329 , V_420 ;
T_10 V_97 , V_70 ;
T_4 V_421 ;
T_2 V_418 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_215 ) ) )
return V_422 ;
V_386 = V_10 -> V_1 -> V_2 . V_360 >> 16 ;
V_329 = ( V_10 -> V_1 -> V_2 . V_360 & V_390 ) >>
V_391 ;
V_418 = V_10 -> V_17 . V_423 + ( V_386 / 8 ) ;
V_421 = V_386 % 8 ;
V_420 = ( V_421 + V_329 > 8 ) ? 2 : 1 ;
V_70 = ( 0xf >> ( 4 - V_329 ) ) << V_421 ;
V_97 = 0 ;
if ( F_220 ( & V_10 -> V_9 , V_418 , & V_97 , V_420 ) )
return V_412 ;
return ( V_97 & V_70 ) ? V_412 : V_422 ;
}
static int F_221 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_352 ;
int V_149 , V_70 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_216 ) ) )
return V_422 ;
V_42 = V_10 -> V_9 . V_39 . V_248 [ V_424 ] ;
V_43 = F_21 ( V_42 ) ;
V_149 = V_10 -> V_1 -> V_2 . V_360 & 1 ;
V_70 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_149 ) ;
if ( V_43 == V_49 )
return V_412 ;
V_43 *= 4 ;
if ( F_220 ( & V_10 -> V_9 , V_10 -> V_17 . V_425 + V_43 , & V_352 , 4 ) )
return V_412 ;
return ( V_352 & V_70 ) ? V_412 : V_422 ;
}
static int F_222 ( struct V_7 * V_10 )
{
T_1 V_399 = V_10 -> V_1 -> V_2 . V_399 ;
switch ( V_399 ) {
case V_416 :
case V_417 :
case V_410 + V_202 :
return V_422 ;
case V_400 :
if ( V_55 )
return V_422 ;
break;
case V_410 + V_200 :
if ( ! V_55 && V_10 -> V_359 == 0 )
return V_422 ;
break;
case V_410 + V_379 :
F_175 ( V_10 ) ;
break;
default:
break;
}
return V_426 ;
}
static int F_207 ( struct V_7 * V_10 )
{
T_1 V_399 = V_10 -> V_1 -> V_2 . V_399 ;
int V_409 = V_422 ;
switch ( V_399 ) {
case V_427 :
V_409 = F_221 ( V_10 ) ;
break;
case V_428 :
V_409 = F_219 ( V_10 ) ;
break;
case V_429 ... V_430 : {
T_1 V_6 = 1U << ( V_399 - V_429 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_409 = V_412 ;
break;
}
case V_431 ... V_432 : {
T_1 V_6 = 1U << ( V_399 - V_431 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_409 = V_412 ;
break;
}
case V_410 ... V_410 + 0x1f : {
T_1 V_433 = 1 << ( V_399 - V_410 ) ;
if ( V_10 -> V_17 . V_21 & V_433 )
V_409 = V_412 ;
else if ( ( V_399 == V_410 + V_200 ) &&
V_10 -> V_359 != 0 )
V_409 = V_412 ;
break;
}
case V_434 : {
V_409 = V_412 ;
break;
}
default: {
T_2 V_435 = 1ULL << ( V_399 - V_416 ) ;
if ( V_10 -> V_17 . V_22 & V_435 )
V_409 = V_412 ;
}
}
return V_409 ;
}
static int F_223 ( struct V_7 * V_10 )
{
int V_409 ;
V_409 = F_207 ( V_10 ) ;
if ( V_409 == V_412 )
F_199 ( V_10 ) ;
return V_409 ;
}
static inline void F_224 ( struct V_1 * V_436 , struct V_1 * V_437 )
{
struct V_11 * V_438 = & V_436 -> V_2 ;
struct V_11 * V_439 = & V_437 -> V_2 ;
V_438 -> V_19 = V_439 -> V_19 ;
V_438 -> V_20 = V_439 -> V_20 ;
V_438 -> V_21 = V_439 -> V_21 ;
V_438 -> V_22 = V_439 -> V_22 ;
V_438 -> V_230 = V_439 -> V_230 ;
V_438 -> V_231 = V_439 -> V_231 ;
V_438 -> V_187 = V_439 -> V_187 ;
V_438 -> V_51 = V_439 -> V_51 ;
V_438 -> V_349 = V_439 -> V_349 ;
V_438 -> V_232 = V_439 -> V_232 ;
V_438 -> V_440 = V_439 -> V_440 ;
V_438 -> V_66 = V_439 -> V_66 ;
V_438 -> V_399 = V_439 -> V_399 ;
V_438 -> V_401 = V_439 -> V_401 ;
V_438 -> V_360 = V_439 -> V_360 ;
V_438 -> V_358 = V_439 -> V_358 ;
V_438 -> V_441 = V_439 -> V_441 ;
V_438 -> V_442 = V_439 -> V_442 ;
V_438 -> V_255 = V_439 -> V_255 ;
V_438 -> V_90 = V_439 -> V_90 ;
V_438 -> V_93 = V_439 -> V_93 ;
V_438 -> V_393 = V_439 -> V_393 ;
V_438 -> V_158 = V_439 -> V_158 ;
}
static int F_199 ( struct V_7 * V_10 )
{
struct V_1 * V_443 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
F_225 ( V_1 -> V_2 . V_399 ,
V_1 -> V_2 . V_360 ,
V_1 -> V_2 . V_358 ,
V_1 -> V_2 . V_441 ,
V_1 -> V_2 . V_442 ,
V_444 ) ;
V_443 = F_211 ( V_10 , V_10 -> V_17 . V_1 , & V_163 ) ;
if ( ! V_443 )
return 1 ;
F_226 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_443 -> V_58 . V_234 = V_1 -> V_58 . V_234 ;
V_443 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_443 -> V_58 . V_235 = V_1 -> V_58 . V_235 ;
V_443 -> V_58 . V_236 = V_1 -> V_58 . V_236 ;
V_443 -> V_58 . V_241 = V_1 -> V_58 . V_241 ;
V_443 -> V_58 . V_242 = V_1 -> V_58 . V_242 ;
V_443 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_443 -> V_58 . V_332 = F_227 ( & V_10 -> V_9 ) ;
V_443 -> V_58 . V_258 = F_131 ( & V_10 -> V_9 ) ;
V_443 -> V_58 . V_411 = V_1 -> V_58 . V_411 ;
V_443 -> V_58 . V_253 = V_10 -> V_9 . V_39 . V_253 ;
V_443 -> V_58 . V_297 = F_228 ( & V_10 -> V_9 ) ;
V_443 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_443 -> V_58 . V_445 = V_1 -> V_58 . V_445 ;
V_443 -> V_58 . V_446 = V_1 -> V_58 . V_446 ;
V_443 -> V_58 . V_354 = V_1 -> V_58 . V_354 ;
V_443 -> V_58 . V_247 = V_1 -> V_58 . V_247 ;
V_443 -> V_58 . V_327 = V_1 -> V_58 . V_327 ;
V_443 -> V_2 . V_232 = V_1 -> V_2 . V_232 ;
V_443 -> V_2 . V_440 = V_1 -> V_2 . V_440 ;
V_443 -> V_2 . V_66 = V_1 -> V_2 . V_66 ;
V_443 -> V_2 . V_399 = V_1 -> V_2 . V_399 ;
V_443 -> V_2 . V_401 = V_1 -> V_2 . V_401 ;
V_443 -> V_2 . V_360 = V_1 -> V_2 . V_360 ;
V_443 -> V_2 . V_358 = V_1 -> V_2 . V_358 ;
V_443 -> V_2 . V_441 = V_1 -> V_2 . V_441 ;
V_443 -> V_2 . V_442 = V_1 -> V_2 . V_442 ;
if ( V_10 -> V_447 )
V_443 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_448 = & V_443 -> V_2 ;
V_448 -> V_441 = V_1 -> V_2 . V_90 ;
V_448 -> V_442 = V_1 -> V_2 . V_93 ;
}
V_443 -> V_2 . V_349 = 0 ;
V_443 -> V_2 . V_90 = 0 ;
V_443 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_414 ) )
V_443 -> V_2 . V_232 &= ~ V_233 ;
F_224 ( V_1 , V_18 ) ;
F_229 ( & V_10 -> V_9 ) ;
F_230 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_393 = 0 ;
V_10 -> V_1 -> V_58 . V_234 = V_18 -> V_58 . V_234 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_235 = V_18 -> V_58 . V_235 ;
V_10 -> V_1 -> V_58 . V_236 = V_18 -> V_58 . V_236 ;
V_10 -> V_1 -> V_58 . V_241 = V_18 -> V_58 . V_241 ;
V_10 -> V_1 -> V_58 . V_242 = V_18 -> V_58 . V_242 ;
F_101 ( & V_10 -> V_9 , V_18 -> V_58 . V_297 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_102 ( & V_10 -> V_9 , V_18 -> V_58 . V_332 | V_449 ) ;
F_148 ( & V_10 -> V_9 , V_18 -> V_58 . V_253 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_258 = V_18 -> V_58 . V_258 ;
V_10 -> V_9 . V_39 . V_258 = V_18 -> V_58 . V_258 ;
} else {
( void ) F_231 ( & V_10 -> V_9 , V_18 -> V_58 . V_258 ) ;
}
F_107 ( & V_10 -> V_9 , V_450 , V_18 -> V_58 . V_446 ) ;
F_107 ( & V_10 -> V_9 , V_451 , V_18 -> V_58 . V_445 ) ;
F_107 ( & V_10 -> V_9 , V_249 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_354 = 0 ;
V_10 -> V_1 -> V_58 . V_327 = 0 ;
V_10 -> V_1 -> V_2 . V_441 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_216 ( V_163 ) ;
F_204 ( & V_10 -> V_9 ) ;
F_103 ( & V_10 -> V_9 ) ;
F_232 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_233 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_216 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_156 ; V_44 ++ ) {
T_1 V_352 , V_452 ;
T_2 V_43 ;
if ( V_157 [ V_44 ] == 0xffffffff )
break;
V_452 = V_157 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_425 + ( V_452 * 4 ) ;
if ( F_220 ( & V_10 -> V_9 , V_43 , & V_352 , 4 ) )
return false ;
V_10 -> V_17 . V_147 [ V_452 ] = V_10 -> V_147 [ V_452 ] | V_352 ;
}
V_10 -> V_1 -> V_2 . V_231 = F_100 ( V_10 -> V_17 . V_147 ) ;
return true ;
}
static bool F_234 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_219 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_255 && ! V_55 )
return false ;
return true ;
}
static bool F_235 ( struct V_7 * V_10 )
{
struct V_1 * V_443 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
T_2 V_453 ;
V_453 = V_10 -> V_1 -> V_58 . V_446 ;
V_443 = F_211 ( V_10 , V_10 -> V_1 -> V_58 . V_446 , & V_163 ) ;
if ( ! V_443 )
return false ;
if ( ! F_234 ( V_443 ) ) {
V_443 -> V_2 . V_399 = V_434 ;
V_443 -> V_2 . V_401 = 0 ;
V_443 -> V_2 . V_360 = 0 ;
V_443 -> V_2 . V_358 = 0 ;
F_216 ( V_163 ) ;
return false ;
}
F_236 ( V_10 -> V_1 -> V_58 . V_84 , V_453 ,
V_443 -> V_58 . V_84 ,
V_443 -> V_2 . V_232 ,
V_443 -> V_2 . V_90 ,
V_443 -> V_2 . V_255 ) ;
F_237 ( V_443 -> V_2 . V_19 & 0xffff ,
V_443 -> V_2 . V_19 >> 16 ,
V_443 -> V_2 . V_21 ,
V_443 -> V_2 . V_22 ) ;
F_229 ( & V_10 -> V_9 ) ;
F_230 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_234 = V_1 -> V_58 . V_234 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_235 = V_1 -> V_58 . V_235 ;
V_18 -> V_58 . V_236 = V_1 -> V_58 . V_236 ;
V_18 -> V_58 . V_241 = V_1 -> V_58 . V_241 ;
V_18 -> V_58 . V_242 = V_1 -> V_58 . V_242 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_332 = F_227 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_253 = V_10 -> V_9 . V_39 . V_253 ;
V_18 -> V_58 . V_297 = F_228 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_36 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_445 = V_1 -> V_58 . V_445 ;
V_18 -> V_58 . V_446 = V_1 -> V_58 . V_446 ;
if ( V_55 )
V_18 -> V_58 . V_258 = V_1 -> V_58 . V_258 ;
else
V_18 -> V_58 . V_258 = F_131 ( & V_10 -> V_9 ) ;
F_224 ( V_18 , V_1 ) ;
if ( F_228 ( & V_10 -> V_9 ) & V_454 )
V_10 -> V_9 . V_39 . V_40 |= V_415 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_415 ;
if ( V_443 -> V_2 . V_255 ) {
F_238 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_393 = V_443 -> V_2 . V_393 ;
F_200 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_234 = V_443 -> V_58 . V_234 ;
V_10 -> V_1 -> V_58 . V_87 = V_443 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_235 = V_443 -> V_58 . V_235 ;
V_10 -> V_1 -> V_58 . V_236 = V_443 -> V_58 . V_236 ;
V_10 -> V_1 -> V_58 . V_241 = V_443 -> V_58 . V_241 ;
V_10 -> V_1 -> V_58 . V_242 = V_443 -> V_58 . V_242 ;
F_101 ( & V_10 -> V_9 , V_443 -> V_58 . V_297 ) ;
F_27 ( & V_10 -> V_9 , V_443 -> V_58 . V_54 ) ;
F_102 ( & V_10 -> V_9 , V_443 -> V_58 . V_332 ) ;
F_148 ( & V_10 -> V_9 , V_443 -> V_58 . V_253 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_258 = V_443 -> V_58 . V_258 ;
V_10 -> V_9 . V_39 . V_258 = V_443 -> V_58 . V_258 ;
} else
( void ) F_231 ( & V_10 -> V_9 , V_443 -> V_58 . V_258 ) ;
F_103 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_411 = V_10 -> V_9 . V_39 . V_411 = V_443 -> V_58 . V_411 ;
F_107 ( & V_10 -> V_9 , V_450 , V_443 -> V_58 . V_446 ) ;
F_107 ( & V_10 -> V_9 , V_451 , V_443 -> V_58 . V_445 ) ;
F_107 ( & V_10 -> V_9 , V_249 , V_443 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_446 = V_443 -> V_58 . V_446 ;
V_10 -> V_1 -> V_58 . V_445 = V_443 -> V_58 . V_445 ;
V_10 -> V_1 -> V_58 . V_84 = V_443 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_354 = V_443 -> V_58 . V_354 ;
V_10 -> V_1 -> V_58 . V_247 = V_443 -> V_58 . V_247 ;
V_10 -> V_1 -> V_58 . V_327 = V_443 -> V_58 . V_327 ;
V_10 -> V_17 . V_425 = V_443 -> V_2 . V_231 & ~ 0x0fffULL ;
V_10 -> V_17 . V_423 = V_443 -> V_2 . V_230 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_443 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_443 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_443 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_443 -> V_2 . V_22 ;
F_150 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_232 = V_443 -> V_2 . V_232 | V_233 ;
if ( V_443 -> V_2 . V_232 & V_233 )
V_10 -> V_9 . V_39 . V_40 |= V_414 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_414 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_414 ) {
F_10 ( V_10 , V_455 ) ;
F_10 ( V_10 , V_199 ) ;
}
F_17 ( V_10 , V_220 ) ;
V_10 -> V_1 -> V_2 . V_158 = V_443 -> V_2 . V_158 ;
V_10 -> V_1 -> V_2 . V_440 = V_443 -> V_2 . V_440 ;
V_10 -> V_1 -> V_2 . V_66 = V_443 -> V_2 . V_66 ;
V_10 -> V_1 -> V_2 . V_187 += V_443 -> V_2 . V_187 ;
V_10 -> V_1 -> V_2 . V_90 = V_443 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_443 -> V_2 . V_93 ;
F_216 ( V_163 ) ;
F_239 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_453 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_240 ( struct V_1 * V_437 , struct V_1 * V_456 )
{
V_456 -> V_58 . V_237 = V_437 -> V_58 . V_237 ;
V_456 -> V_58 . V_238 = V_437 -> V_58 . V_238 ;
V_456 -> V_58 . V_245 = V_437 -> V_58 . V_245 ;
V_456 -> V_58 . V_243 = V_437 -> V_58 . V_243 ;
V_456 -> V_58 . V_457 = V_437 -> V_58 . V_457 ;
V_456 -> V_58 . V_458 = V_437 -> V_58 . V_458 ;
V_456 -> V_58 . V_459 = V_437 -> V_58 . V_459 ;
V_456 -> V_58 . V_460 = V_437 -> V_58 . V_460 ;
V_456 -> V_58 . V_461 = V_437 -> V_58 . V_461 ;
V_456 -> V_58 . V_462 = V_437 -> V_58 . V_462 ;
V_456 -> V_58 . V_463 = V_437 -> V_58 . V_463 ;
V_456 -> V_58 . V_464 = V_437 -> V_58 . V_464 ;
}
static int F_241 ( struct V_7 * V_10 )
{
struct V_1 * V_443 ;
struct V_163 * V_163 ;
if ( F_205 ( V_10 ) )
return 1 ;
V_443 = F_211 ( V_10 , V_10 -> V_1 -> V_58 . V_446 , & V_163 ) ;
if ( ! V_443 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_240 ( V_443 , V_10 -> V_1 ) ;
F_216 ( V_163 ) ;
return 1 ;
}
static int F_242 ( struct V_7 * V_10 )
{
struct V_1 * V_443 ;
struct V_163 * V_163 ;
if ( F_205 ( V_10 ) )
return 1 ;
V_443 = F_211 ( V_10 , V_10 -> V_1 -> V_58 . V_446 , & V_163 ) ;
if ( ! V_443 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_240 ( V_10 -> V_1 , V_443 ) ;
F_216 ( V_163 ) ;
return 1 ;
}
static int F_243 ( struct V_7 * V_10 )
{
if ( F_205 ( V_10 ) )
return 1 ;
F_37 ( & V_10 -> V_9 , F_36 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_235 ( V_10 ) )
return 1 ;
if ( ! F_233 ( V_10 ) )
goto V_465;
return 1 ;
V_465:
V_10 -> V_1 -> V_2 . V_399 = V_434 ;
V_10 -> V_1 -> V_2 . V_401 = 0 ;
V_10 -> V_1 -> V_2 . V_360 = 0 ;
V_10 -> V_1 -> V_2 . V_358 = 0 ;
F_199 ( V_10 ) ;
return 1 ;
}
static int F_244 ( struct V_7 * V_10 )
{
if ( F_205 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_180 ( V_466 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_245 ( struct V_7 * V_10 )
{
if ( F_205 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_133 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_232 &= ~ V_467 ;
F_3 ( V_10 -> V_1 , V_468 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_247 ( V_10 -> V_1 -> V_58 . V_84 , F_248 ( & V_10 -> V_9 , V_424 ) ,
F_248 ( & V_10 -> V_9 , V_450 ) ) ;
F_249 ( V_9 , F_248 ( & V_10 -> V_9 , V_450 ) ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_250 ( struct V_7 * V_10 )
{
F_251 ( V_10 -> V_1 -> V_58 . V_84 , F_248 ( & V_10 -> V_9 , V_450 ) ) ;
F_169 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
static int F_252 ( struct V_7 * V_10 )
{
F_253 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_254 ( struct V_7 * V_10 )
{
T_2 V_469 = F_255 ( & V_10 -> V_9 ) ;
T_1 V_145 = F_248 ( & V_10 -> V_9 , V_424 ) ;
if ( F_256 ( & V_10 -> V_9 , V_145 , V_469 ) == 0 ) {
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_257 ( struct V_7 * V_10 )
{
T_10 V_470 ;
int V_471 ;
int V_472 = V_10 -> V_1 -> V_2 . V_441 &
V_473 ;
int V_474 = V_10 -> V_1 -> V_2 . V_441 & V_475 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_441 & V_473 ;
T_7 V_476 =
V_10 -> V_1 -> V_2 . V_441 & V_477 ;
bool V_80 = false ;
T_1 V_81 = 0 ;
V_470 = ( T_10 ) V_10 -> V_1 -> V_2 . V_360 ;
if ( V_10 -> V_1 -> V_2 . V_358 &
( 1ULL << V_478 ) )
V_471 = V_479 ;
else if ( V_10 -> V_1 -> V_2 . V_358 &
( 1ULL << V_480 ) )
V_471 = V_481 ;
else if ( V_476 )
V_471 = V_482 ;
else
V_471 = V_483 ;
if ( V_471 == V_482 ) {
switch ( type ) {
case V_484 :
V_10 -> V_9 . V_39 . V_485 = false ;
break;
case V_486 :
if ( V_10 -> V_1 -> V_2 . V_358 &
( 1ULL << V_487 ) ) {
V_80 = true ;
V_81 =
( T_1 ) V_10 -> V_1 -> V_2 . V_358 ;
}
F_229 ( & V_10 -> V_9 ) ;
break;
case V_488 :
F_230 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_471 != V_482 ||
V_472 == V_489 ||
( V_472 == V_486 &&
( V_474 == V_490 || V_474 == V_83 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_472 != V_489 )
V_474 = - 1 ;
if ( F_258 ( & V_10 -> V_9 , V_470 , V_474 , V_471 ,
V_80 , V_81 ) == V_491 ) {
V_10 -> V_9 . V_366 -> V_372 = V_492 ;
V_10 -> V_9 . V_366 -> V_493 . V_494 = V_495 ;
V_10 -> V_9 . V_366 -> V_493 . V_496 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_259 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_260 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_261 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_292 . V_497 ;
F_17 ( V_10 , V_498 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_499 ;
V_10 -> V_500 = F_36 ( & V_10 -> V_9 ) ;
F_180 ( V_466 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_262 ( struct V_7 * V_10 )
{
if ( ! F_33 ( V_501 ) )
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
F_249 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_360 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
}
static int F_264 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_33 ( V_72 ) )
return F_263 ( V_10 ) ;
V_96 = F_265 ( & V_10 -> V_9 ) ;
F_266 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static bool F_267 ( struct V_7 * V_10 ,
unsigned long V_97 )
{
unsigned long V_332 = V_10 -> V_9 . V_39 . V_332 ;
bool V_65 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_208 ) ) ) )
return false ;
V_332 &= ~ V_334 ;
V_97 &= ~ V_334 ;
if ( V_332 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_399 = V_502 ;
V_65 = ( F_223 ( V_10 ) == V_412 ) ;
}
return V_65 ;
}
static int F_268 ( struct V_7 * V_10 )
{
int V_299 , V_503 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_33 ( V_501 ) )
return F_263 ( V_10 ) ;
if ( F_118 ( ( V_10 -> V_1 -> V_2 . V_360 & V_504 ) == 0 ) )
return F_263 ( V_10 ) ;
V_299 = V_10 -> V_1 -> V_2 . V_360 & V_505 ;
if ( V_10 -> V_1 -> V_2 . V_399 == V_502 )
V_503 = V_506 - V_429 ;
else
V_503 = V_10 -> V_1 -> V_2 . V_399 - V_429 ;
V_96 = 0 ;
if ( V_503 >= 16 ) {
V_503 -= 16 ;
V_97 = F_248 ( & V_10 -> V_9 , V_299 ) ;
switch ( V_503 ) {
case 0 :
if ( ! F_267 ( V_10 , V_97 ) )
V_96 = F_269 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_231 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_270 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_271 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_272 ( 1 , L_10 , V_503 ) ;
F_169 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
} else {
switch ( V_503 ) {
case 0 :
V_97 = F_227 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_411 ;
break;
case 3 :
V_97 = F_131 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_273 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_274 ( & V_10 -> V_9 ) ;
break;
default:
F_272 ( 1 , L_11 , V_503 ) ;
F_169 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
F_107 ( & V_10 -> V_9 , V_299 , V_97 ) ;
}
F_266 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_275 ( struct V_7 * V_10 )
{
int V_299 , V_507 ;
unsigned long V_97 ;
if ( V_10 -> V_9 . V_346 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_355 |= V_356 ;
return 1 ;
}
if ( ! F_85 ( V_501 ) )
return F_263 ( V_10 ) ;
V_299 = V_10 -> V_1 -> V_2 . V_360 & V_505 ;
V_507 = V_10 -> V_1 -> V_2 . V_399 - V_431 ;
if ( V_507 >= 16 ) {
if ( ! F_276 ( & V_10 -> V_9 , V_507 - 16 ) )
return 1 ;
V_97 = F_248 ( & V_10 -> V_9 , V_299 ) ;
F_277 ( & V_10 -> V_9 , V_507 - 16 , V_97 ) ;
} else {
if ( ! F_276 ( & V_10 -> V_9 , V_507 ) )
return 1 ;
F_278 ( & V_10 -> V_9 , V_507 , & V_97 ) ;
F_107 ( & V_10 -> V_9 , V_299 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_279 ( struct V_7 * V_10 )
{
struct V_365 * V_365 = V_10 -> V_9 . V_366 ;
int V_141 ;
T_4 V_508 = F_274 ( & V_10 -> V_9 ) ;
V_141 = F_268 ( V_10 ) ;
if ( F_280 ( & V_10 -> V_9 ) )
return V_141 ;
if ( V_508 <= F_274 ( & V_10 -> V_9 ) )
return V_141 ;
V_365 -> V_372 = V_509 ;
return 0 ;
}
static T_2 F_281 ( struct V_8 * V_9 , T_2 V_510 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_187 + V_510 ;
}
static int F_282 ( struct V_8 * V_9 , struct V_511 * V_512 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_512 -> V_145 ) {
case V_513 : {
V_512 -> V_514 = V_10 -> V_1 -> V_2 . V_187 +
F_283 ( V_9 , F_284 () ) ;
break;
}
case V_515 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_458 ;
break;
#ifdef F_26
case V_516 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_459 ;
break;
case V_517 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_460 ;
break;
case V_294 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_457 ;
break;
case V_518 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_461 ;
break;
#endif
case V_519 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_462 ;
break;
case V_520 :
V_512 -> V_514 = V_10 -> V_464 ;
break;
case V_521 :
V_512 -> V_514 = V_10 -> V_463 ;
break;
case V_522 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_523 ;
break;
case V_159 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_524 ;
break;
case V_160 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_525 ;
break;
case V_161 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_526 ;
break;
case V_162 :
V_512 -> V_514 = V_10 -> V_1 -> V_58 . V_527 ;
break;
case V_132 :
V_512 -> V_514 = V_10 -> V_17 . V_528 ;
break;
case V_529 :
V_512 -> V_514 = V_10 -> V_17 . V_530 ;
break;
case V_531 :
V_512 -> V_514 = 0x01000065 ;
break;
default:
return F_285 ( V_9 , V_512 ) ;
}
return 0 ;
}
static int F_286 ( struct V_7 * V_10 )
{
T_1 V_532 = F_248 ( & V_10 -> V_9 , V_424 ) ;
struct V_511 V_512 ;
V_512 . V_145 = V_532 ;
V_512 . V_533 = false ;
if ( F_282 ( & V_10 -> V_9 , & V_512 ) ) {
F_287 ( V_532 ) ;
F_206 ( & V_10 -> V_9 , 0 ) ;
} else {
F_288 ( V_532 , V_512 . V_514 ) ;
F_107 ( & V_10 -> V_9 , V_450 ,
V_512 . V_514 & 0xffffffff ) ;
F_107 ( & V_10 -> V_9 , V_269 ,
V_512 . V_514 >> 32 ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_289 ( struct V_8 * V_9 , T_2 V_514 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_534 , V_535 ;
if ( V_514 & ~ V_536 )
return 1 ;
V_535 = V_536 ;
if ( V_10 -> V_17 . V_530 & V_537 )
V_535 &= ~ ( V_538 | V_537 ) ;
V_10 -> V_17 . V_530 &= ~ V_535 ;
V_10 -> V_17 . V_530 |= ( V_514 & V_535 ) ;
V_534 = V_10 -> V_17 . V_530 & V_537 ;
if ( V_534 && ( V_9 -> V_39 . V_54 & V_59 ) )
return 1 ;
return 0 ;
}
static int F_290 ( struct V_8 * V_9 , struct V_511 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_532 = V_42 -> V_145 ;
T_2 V_514 = V_42 -> V_514 ;
switch ( V_532 ) {
case V_513 :
F_291 ( V_9 , V_42 ) ;
break;
case V_515 :
V_10 -> V_1 -> V_58 . V_458 = V_514 ;
break;
#ifdef F_26
case V_516 :
V_10 -> V_1 -> V_58 . V_459 = V_514 ;
break;
case V_517 :
V_10 -> V_1 -> V_58 . V_460 = V_514 ;
break;
case V_294 :
V_10 -> V_1 -> V_58 . V_457 = V_514 ;
break;
case V_518 :
V_10 -> V_1 -> V_58 . V_461 = V_514 ;
break;
#endif
case V_519 :
V_10 -> V_1 -> V_58 . V_462 = V_514 ;
break;
case V_520 :
V_10 -> V_464 = V_514 ;
V_10 -> V_1 -> V_58 . V_464 = V_514 ;
break;
case V_521 :
V_10 -> V_463 = V_514 ;
V_10 -> V_1 -> V_58 . V_463 = V_514 ;
break;
case V_522 :
if ( ! F_85 ( V_539 ) ) {
F_292 ( V_9 , L_12 ,
V_76 , V_514 ) ;
break;
}
if ( V_514 & V_540 )
return 1 ;
V_10 -> V_1 -> V_58 . V_523 = V_514 ;
F_3 ( V_10 -> V_1 , V_541 ) ;
if ( V_514 & ( 1ULL << 0 ) )
F_80 ( V_10 ) ;
else
F_81 ( V_10 ) ;
break;
case V_132 :
V_10 -> V_17 . V_528 = V_514 ;
break;
case V_529 :
return F_289 ( V_9 , V_514 ) ;
case V_542 :
F_292 ( V_9 , L_13 , V_532 , V_514 ) ;
break;
default:
return F_293 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_294 ( struct V_7 * V_10 )
{
struct V_511 V_42 ;
T_1 V_532 = F_248 ( & V_10 -> V_9 , V_424 ) ;
T_2 V_514 = F_255 ( & V_10 -> V_9 ) ;
V_42 . V_514 = V_514 ;
V_42 . V_145 = V_532 ;
V_42 . V_533 = false ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
if ( F_295 ( & V_10 -> V_9 , & V_42 ) ) {
F_296 ( V_532 , V_514 ) ;
F_206 ( & V_10 -> V_9 , 0 ) ;
} else {
F_297 ( V_532 , V_514 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_298 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_360 )
return F_294 ( V_10 ) ;
else
return F_286 ( V_10 ) ;
}
static int F_299 ( struct V_7 * V_10 )
{
F_180 ( V_466 , & V_10 -> V_9 ) ;
F_133 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_232 &= ~ V_467 ;
F_3 ( V_10 -> V_1 , V_468 ) ;
++ V_10 -> V_9 . V_292 . V_543 ;
return 1 ;
}
static int F_300 ( struct V_7 * V_10 )
{
F_301 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_302 ( struct V_7 * V_10 )
{
F_31 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_303 ( struct V_7 * V_10 )
{
F_304 ( V_544 L_14 ) ;
return F_302 ( V_10 ) ;
}
static int F_305 ( struct V_7 * V_10 )
{
F_304 ( V_544 L_15 ) ;
return F_302 ( V_10 ) ;
}
static void F_306 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_191 * V_58 = & V_10 -> V_1 -> V_58 ;
F_56 ( L_16 ) ;
F_56 ( L_17 , L_18 , V_2 -> V_19 & 0xffff ) ;
F_56 ( L_17 , L_19 , V_2 -> V_19 >> 16 ) ;
F_56 ( L_17 , L_20 , V_2 -> V_20 & 0xffff ) ;
F_56 ( L_17 , L_21 , V_2 -> V_20 >> 16 ) ;
F_56 ( L_22 , L_23 , V_2 -> V_21 ) ;
F_56 ( L_24 , L_25 , V_2 -> V_22 ) ;
F_56 ( L_26 , L_27 , V_2 -> V_260 ) ;
F_56 ( L_24 , L_28 , V_2 -> V_230 ) ;
F_56 ( L_24 , L_29 , V_2 -> V_231 ) ;
F_56 ( L_24 , L_30 , V_2 -> V_187 ) ;
F_56 ( L_26 , L_31 , V_2 -> V_51 ) ;
F_56 ( L_26 , L_32 , V_2 -> V_349 ) ;
F_56 ( L_22 , L_33 , V_2 -> V_232 ) ;
F_56 ( L_22 , L_34 , V_2 -> V_440 ) ;
F_56 ( L_22 , L_35 , V_2 -> V_66 ) ;
F_56 ( L_22 , L_36 , V_2 -> V_399 ) ;
F_56 ( L_24 , L_37 , V_2 -> V_360 ) ;
F_56 ( L_24 , L_38 , V_2 -> V_358 ) ;
F_56 ( L_22 , L_39 , V_2 -> V_441 ) ;
F_56 ( L_22 , L_40 , V_2 -> V_442 ) ;
F_56 ( L_41 , L_42 , V_2 -> V_255 ) ;
F_56 ( L_24 , L_43 , V_2 -> V_393 ) ;
F_56 ( L_22 , L_44 , V_2 -> V_90 ) ;
F_56 ( L_22 , L_45 , V_2 -> V_93 ) ;
F_56 ( L_41 , L_46 , V_2 -> V_158 ) ;
F_56 ( L_24 , L_47 , V_2 -> V_71 ) ;
F_56 ( L_48 ) ;
F_56 ( L_49 ,
L_50 ,
V_58 -> V_234 . V_181 , V_58 -> V_234 . V_182 ,
V_58 -> V_234 . V_186 , V_58 -> V_234 . V_88 ) ;
F_56 ( L_49 ,
L_51 ,
V_58 -> V_87 . V_181 , V_58 -> V_87 . V_182 ,
V_58 -> V_87 . V_186 , V_58 -> V_87 . V_88 ) ;
F_56 ( L_49 ,
L_52 ,
V_58 -> V_235 . V_181 , V_58 -> V_235 . V_182 ,
V_58 -> V_235 . V_186 , V_58 -> V_235 . V_88 ) ;
F_56 ( L_49 ,
L_53 ,
V_58 -> V_236 . V_181 , V_58 -> V_236 . V_182 ,
V_58 -> V_236 . V_186 , V_58 -> V_236 . V_88 ) ;
F_56 ( L_49 ,
L_54 ,
V_58 -> V_237 . V_181 , V_58 -> V_237 . V_182 ,
V_58 -> V_237 . V_186 , V_58 -> V_237 . V_88 ) ;
F_56 ( L_49 ,
L_55 ,
V_58 -> V_238 . V_181 , V_58 -> V_238 . V_182 ,
V_58 -> V_238 . V_186 , V_58 -> V_238 . V_88 ) ;
F_56 ( L_49 ,
L_56 ,
V_58 -> V_241 . V_181 , V_58 -> V_241 . V_182 ,
V_58 -> V_241 . V_186 , V_58 -> V_241 . V_88 ) ;
F_56 ( L_49 ,
L_57 ,
V_58 -> V_243 . V_181 , V_58 -> V_243 . V_182 ,
V_58 -> V_243 . V_186 , V_58 -> V_243 . V_88 ) ;
F_56 ( L_49 ,
L_58 ,
V_58 -> V_242 . V_181 , V_58 -> V_242 . V_182 ,
V_58 -> V_242 . V_186 , V_58 -> V_242 . V_88 ) ;
F_56 ( L_49 ,
L_59 ,
V_58 -> V_245 . V_181 , V_58 -> V_245 . V_182 ,
V_58 -> V_245 . V_186 , V_58 -> V_245 . V_88 ) ;
F_56 ( L_60 ,
V_58 -> V_327 , V_58 -> V_54 ) ;
F_56 ( L_61 ,
L_62 , V_58 -> V_332 , L_63 , V_58 -> V_411 ) ;
F_56 ( L_61 ,
L_64 , V_58 -> V_258 , L_65 , V_58 -> V_253 ) ;
F_56 ( L_61 ,
L_66 , V_58 -> V_247 , L_67 , V_58 -> V_354 ) ;
F_56 ( L_61 ,
L_68 , V_58 -> V_84 , L_69 , V_58 -> V_297 ) ;
F_56 ( L_61 ,
L_70 , V_58 -> V_445 , L_71 , V_58 -> V_446 ) ;
F_56 ( L_61 ,
L_72 , V_58 -> V_458 , L_73 , V_58 -> V_459 ) ;
F_56 ( L_61 ,
L_74 , V_58 -> V_460 , L_75 , V_58 -> V_461 ) ;
F_56 ( L_61 ,
L_76 , V_58 -> V_457 ,
L_77 , V_58 -> V_462 ) ;
F_56 ( L_61 ,
L_78 , V_58 -> V_463 ,
L_79 , V_58 -> V_464 ) ;
F_56 ( L_61 ,
L_80 , V_58 -> V_256 , L_81 , V_58 -> V_523 ) ;
F_56 ( L_61 ,
L_82 , V_58 -> V_524 , L_83 , V_58 -> V_525 ) ;
F_56 ( L_61 ,
L_84 , V_58 -> V_526 ,
L_85 , V_58 -> V_527 ) ;
}
static void F_307 ( struct V_8 * V_9 , T_2 * V_545 , T_2 * V_546 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_545 = V_2 -> V_360 ;
* V_546 = V_2 -> V_358 ;
}
static int F_308 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_365 * V_365 = V_9 -> V_366 ;
T_1 V_399 = V_10 -> V_1 -> V_2 . V_399 ;
F_309 ( V_399 , V_9 , V_444 ) ;
if ( ! F_11 ( V_10 , V_196 ) )
V_9 -> V_39 . V_332 = V_10 -> V_1 -> V_58 . V_332 ;
if ( V_55 )
V_9 -> V_39 . V_258 = V_10 -> V_1 -> V_58 . V_258 ;
if ( F_118 ( V_10 -> V_17 . V_413 ) ) {
F_199 ( V_10 ) ;
V_10 -> V_17 . V_413 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_409 ;
F_310 ( V_10 -> V_1 -> V_58 . V_84 , V_399 ,
V_10 -> V_1 -> V_2 . V_360 ,
V_10 -> V_1 -> V_2 . V_358 ,
V_10 -> V_1 -> V_2 . V_441 ,
V_10 -> V_1 -> V_2 . V_442 ,
V_444 ) ;
V_409 = F_222 ( V_10 ) ;
if ( V_409 == V_426 )
V_409 = F_223 ( V_10 ) ;
if ( V_409 == V_412 )
return 1 ;
}
F_311 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_399 == V_434 ) {
V_365 -> V_372 = V_547 ;
V_365 -> V_548 . V_549
= V_10 -> V_1 -> V_2 . V_399 ;
F_56 ( L_86 ) ;
F_306 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_441 ) &&
V_399 != V_410 + V_200 &&
V_399 != V_400 && V_399 != V_550 &&
V_399 != V_416 && V_399 != V_417 )
F_35 ( V_78 L_87
L_88 ,
V_76 , V_10 -> V_1 -> V_2 . V_441 ,
V_399 ) ;
if ( V_399 >= F_312 ( V_551 )
|| ! V_551 [ V_399 ] ) {
F_313 ( 1 , L_89 , V_399 ) ;
F_169 ( V_9 , V_201 ) ;
return 1 ;
}
return V_551 [ V_399 ] ( V_10 ) ;
}
static void F_314 ( struct V_8 * V_9 )
{
int V_140 = F_54 () ;
struct V_113 * V_114 = F_57 ( V_123 , V_140 ) ;
V_114 -> V_129 -> type = 9 ;
F_315 () ;
}
static void F_316 ( struct V_7 * V_10 )
{
int V_140 = F_54 () ;
struct V_113 * V_114 = F_57 ( V_123 , V_140 ) ;
if ( V_10 -> V_124 != V_114 -> V_124 )
F_153 ( V_10 , V_114 ) ;
}
static void F_317 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_552 ;
V_9 -> V_39 . V_40 |= V_553 ;
F_16 ( V_10 , V_498 ) ;
++ V_9 -> V_292 . V_554 ;
}
static inline void F_318 ( struct V_7 * V_10 , int V_555 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_440 = V_555 ;
V_2 -> V_232 &= ~ V_556 ;
V_2 -> V_232 |= V_467 |
( ( 0xf ) << V_557 ) ;
F_3 ( V_10 -> V_1 , V_468 ) ;
}
static void F_319 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_73 ( ! ( F_20 ( V_10 ) ) ) ;
F_320 ( V_9 -> V_39 . V_558 . V_79 ) ;
++ V_9 -> V_292 . V_559 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_558 . V_79 |
V_63 | V_64 ;
}
static void F_321 ( struct V_8 * V_9 , int V_560 , int V_561 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_414 ) )
return;
F_10 ( V_10 , V_199 ) ;
if ( V_561 == - 1 )
return;
if ( V_560 >= V_561 )
F_9 ( V_10 , V_199 ) ;
}
static void F_322 ( struct V_8 * V_9 , bool V_562 )
{
return;
}
static int F_323 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_324 ( struct V_8 * V_9 )
{
return;
}
static void F_325 ( struct V_8 * V_9 )
{
return;
}
static int F_326 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
V_65 = ! ( V_1 -> V_2 . V_66 & V_67 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_553 ) ;
V_65 = V_65 && F_20 ( V_10 ) && F_210 ( V_10 ) ;
return V_65 ;
}
static bool F_327 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_553 ) ;
}
static void F_328 ( struct V_8 * V_9 , bool V_563 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_563 ) {
V_10 -> V_9 . V_39 . V_40 |= V_553 ;
F_16 ( V_10 , V_498 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_553 ;
F_17 ( V_10 , V_498 ) ;
}
}
static int F_329 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_66 & V_67 ) )
return 0 ;
V_65 = ! ! ( F_228 ( V_9 ) & V_454 ) ;
if ( F_7 ( V_9 ) )
return V_65 && ! ( V_10 -> V_9 . V_39 . V_40 & V_414 ) ;
return V_65 ;
}
static void F_330 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_208 ( V_10 ) ) {
F_132 ( V_10 ) ;
F_318 ( V_10 , 0x0 ) ;
}
}
static void F_331 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_553 | V_499 ) )
== V_553 )
return;
V_10 -> V_369 = true ;
V_10 -> V_1 -> V_58 . V_297 |= ( V_370 | V_371 ) ;
}
static int F_332 ( struct V_270 * V_270 , unsigned int V_50 )
{
return 0 ;
}
static void F_150 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_33 ( V_564 ) )
V_10 -> V_1 -> V_2 . V_349 = V_565 ;
else
V_10 -> V_124 -- ;
}
static void F_333 ( struct V_8 * V_9 )
{
}
static inline void F_334 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_414 ) )
return;
if ( ! F_11 ( V_10 , V_199 ) ) {
int V_566 = V_10 -> V_1 -> V_2 . V_232 & V_567 ;
F_271 ( V_9 , V_566 ) ;
}
}
static inline void F_335 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_566 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_414 ) )
return;
V_566 = F_274 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_232 &= ~ V_567 ;
V_10 -> V_1 -> V_2 . V_232 |= V_566 & V_567 ;
}
static void F_311 ( struct V_7 * V_10 )
{
T_4 V_568 ;
int type ;
T_1 V_569 = V_10 -> V_1 -> V_2 . V_441 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_499 )
&& F_36 ( & V_10 -> V_9 ) != V_10 -> V_500 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_553 | V_499 ) ;
F_180 ( V_466 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_485 = false ;
F_229 ( & V_10 -> V_9 ) ;
F_230 ( & V_10 -> V_9 ) ;
if ( ! ( V_569 & V_477 ) )
return;
F_180 ( V_466 , & V_10 -> V_9 ) ;
V_568 = V_569 & V_570 ;
type = V_569 & V_473 ;
switch ( type ) {
case V_484 :
V_10 -> V_9 . V_39 . V_485 = true ;
break;
case V_486 :
if ( F_336 ( V_568 ) ) {
if ( V_568 == V_83 && V_89 &&
F_337 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_37 ( & V_10 -> V_9 ,
F_36 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_569 & V_571 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_442 ;
F_338 ( & V_10 -> V_9 , V_568 , V_96 ) ;
} else
F_339 ( & V_10 -> V_9 , V_568 ) ;
break;
case V_488 :
F_340 ( & V_10 -> V_9 , V_568 , false ) ;
break;
default:
break;
}
}
static void F_341 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_441 = V_2 -> V_90 ;
V_2 -> V_442 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_311 ( V_10 ) ;
}
static void F_342 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_446 = V_9 -> V_39 . V_248 [ V_450 ] ;
V_10 -> V_1 -> V_58 . V_445 = V_9 -> V_39 . V_248 [ V_451 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_248 [ V_249 ] ;
if ( F_118 ( V_10 -> V_17 . V_413 ) )
return;
F_316 ( V_10 ) ;
F_335 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_411 = V_9 -> V_39 . V_411 ;
F_22 () ;
F_166 () ;
asm volatile (
"push %%" _ASM_BP "; \n\t"
"mov %c[rbx](%[svm]), %%" _ASM_BX " \n\t"
"mov %c[rcx](%[svm]), %%" _ASM_CX " \n\t"
"mov %c[rdx](%[svm]), %%" _ASM_DX " \n\t"
"mov %c[rsi](%[svm]), %%" _ASM_SI " \n\t"
"mov %c[rdi](%[svm]), %%" _ASM_DI " \n\t"
"mov %c[rbp](%[svm]), %%" _ASM_BP " \n\t"
#ifdef F_26
"mov %c[r8](%[svm]), %%r8 \n\t"
"mov %c[r9](%[svm]), %%r9 \n\t"
"mov %c[r10](%[svm]), %%r10 \n\t"
"mov %c[r11](%[svm]), %%r11 \n\t"
"mov %c[r12](%[svm]), %%r12 \n\t"
"mov %c[r13](%[svm]), %%r13 \n\t"
"mov %c[r14](%[svm]), %%r14 \n\t"
"mov %c[r15](%[svm]), %%r15 \n\t"
#endif
"push %%" _ASM_AX " \n\t"
"mov %c[vmcb](%[svm]), %%" _ASM_AX " \n\t"
__ex(SVM_VMLOAD) "\n\t"
__ex(SVM_VMRUN) "\n\t"
__ex(SVM_VMSAVE) "\n\t"
"pop %%" _ASM_AX " \n\t"
"mov %%" _ASM_BX ", %c[rbx](%[svm]) \n\t"
"mov %%" _ASM_CX ", %c[rcx](%[svm]) \n\t"
"mov %%" _ASM_DX ", %c[rdx](%[svm]) \n\t"
"mov %%" _ASM_SI ", %c[rsi](%[svm]) \n\t"
"mov %%" _ASM_DI ", %c[rdi](%[svm]) \n\t"
"mov %%" _ASM_BP ", %c[rbp](%[svm]) \n\t"
#ifdef F_26
"mov %%r8, %c[r8](%[svm]) \n\t"
"mov %%r9, %c[r9](%[svm]) \n\t"
"mov %%r10, %c[r10](%[svm]) \n\t"
"mov %%r11, %c[r11](%[svm]) \n\t"
"mov %%r12, %c[r12](%[svm]) \n\t"
"mov %%r13, %c[r13](%[svm]) \n\t"
"mov %%r14, %c[r14](%[svm]) \n\t"
"mov %%r15, %c[r15](%[svm]) \n\t"
#endif
"pop %%" _ASM_BP
:
: [svm]"a"(svm),
[vmcb]"i"(offsetof(struct vcpu_svm, vmcb_pa)),
[rbx]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RBX])),
[rcx]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RCX])),
[rdx]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RDX])),
[rsi]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RSI])),
[rdi]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RDI])),
[rbp]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RBP]))
#ifdef F_26
, [r8]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R8])),
[r9]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R9])),
[r10]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R10])),
[r11]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R11])),
[r12]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R12])),
[r13]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R13])),
[r14]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R14])),
[r15]"i"(offsetof(struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R15]))
#endif
: "cc", "memory"
#ifdef F_26
, "rbx", "rcx", "rdx", "rsi", "rdi"
, "r8", "r9", "r10", "r11" , "r12", "r13", "r14", "r15"
#else
, "ebx", "ecx", "edx", "esi", "edi"
#endif
);
#ifdef F_26
F_50 ( V_283 , V_10 -> V_284 . V_285 ) ;
#else
F_124 ( V_237 , V_10 -> V_284 . V_237 ) ;
#ifndef F_126
F_124 ( V_238 , V_10 -> V_284 . V_238 ) ;
#endif
#endif
F_314 ( V_9 ) ;
F_164 () ;
V_9 -> V_39 . V_411 = V_10 -> V_1 -> V_58 . V_411 ;
V_9 -> V_39 . V_248 [ V_450 ] = V_10 -> V_1 -> V_58 . V_446 ;
V_9 -> V_39 . V_248 [ V_451 ] = V_10 -> V_1 -> V_58 . V_445 ;
V_9 -> V_39 . V_248 [ V_249 ] = V_10 -> V_1 -> V_58 . V_84 ;
if ( F_118 ( V_10 -> V_1 -> V_2 . V_399 == V_417 ) )
F_343 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_118 ( V_10 -> V_1 -> V_2 . V_399 == V_417 ) )
F_344 ( & V_10 -> V_9 ) ;
F_334 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_349 = V_572 ;
if ( V_10 -> V_1 -> V_2 . V_399 == V_410 + V_200 )
V_10 -> V_359 = F_345 () ;
if ( V_55 ) {
V_9 -> V_39 . V_573 &= ~ ( 1 << V_300 ) ;
V_9 -> V_39 . V_574 &= ~ ( 1 << V_300 ) ;
}
if ( F_118 ( V_10 -> V_1 -> V_2 . V_399 ==
V_410 + V_202 ) )
F_179 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_346 ( struct V_8 * V_9 , unsigned long V_395 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_258 = V_395 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_150 ( V_9 ) ;
}
static void F_347 ( struct V_8 * V_9 , unsigned long V_395 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_393 = V_395 ;
F_3 ( V_10 -> V_1 , V_396 ) ;
V_10 -> V_1 -> V_58 . V_258 = F_131 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_150 ( V_9 ) ;
}
static int F_348 ( void )
{
T_2 V_575 ;
F_55 ( V_529 , V_575 ) ;
if ( V_575 & ( 1 << V_576 ) )
return 1 ;
return 0 ;
}
static void
F_349 ( struct V_8 * V_9 , unsigned char * V_577 )
{
V_577 [ 0 ] = 0x0f ;
V_577 [ 1 ] = 0x01 ;
V_577 [ 2 ] = 0xd9 ;
}
static void F_350 ( void * V_578 )
{
* ( int * ) V_578 = 0 ;
}
static bool F_351 ( void )
{
return false ;
}
static bool F_352 ( void )
{
return true ;
}
static T_2 F_353 ( struct V_8 * V_9 , T_11 V_579 , bool V_580 )
{
return 0 ;
}
static void F_354 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_447 = ! ! F_355 ( & V_10 -> V_9 ) ;
}
static void F_356 ( T_1 V_581 , struct V_582 * V_583 )
{
switch ( V_581 ) {
case 0x80000001 :
if ( V_17 )
V_583 -> V_532 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_583 -> V_264 = 1 ;
V_583 -> V_584 = 8 ;
V_583 -> V_532 = 0 ;
V_583 -> V_585 = 0 ;
if ( F_85 ( V_72 ) )
V_583 -> V_585 |= V_586 ;
if ( V_55 )
V_583 -> V_585 |= V_587 ;
break;
}
}
static int F_357 ( void )
{
return V_588 ;
}
static bool F_358 ( void )
{
return false ;
}
static bool F_359 ( void )
{
return false ;
}
static bool F_360 ( void )
{
return false ;
}
static bool F_361 ( void )
{
return false ;
}
static bool F_362 ( void )
{
return true ;
}
static void F_363 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_379 ) ;
F_145 ( V_10 ) ;
}
static int F_364 ( struct V_8 * V_9 ,
struct V_589 * V_61 ,
enum V_590 V_591 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_409 , V_65 = V_592 ;
struct V_593 V_594 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_312 ( V_595 ) )
goto V_276;
V_594 = V_595 [ V_61 -> V_22 ] ;
if ( V_591 != V_594 . V_591 )
goto V_276;
switch ( V_594 . V_399 ) {
case V_429 :
if ( V_61 -> V_22 == V_596 )
V_594 . V_399 += V_61 -> V_597 ;
break;
case V_506 : {
unsigned long V_332 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_598 )
V_594 . V_399 += V_61 -> V_597 ;
if ( V_594 . V_399 != V_506 ||
V_61 -> V_22 == V_599 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_208 ) ) )
break;
V_332 = V_9 -> V_39 . V_332 & ~ V_334 ;
V_97 = V_61 -> V_600 & ~ V_334 ;
if ( V_61 -> V_22 == V_601 ) {
V_332 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_332 & V_449 )
V_97 |= V_449 ;
}
if ( V_332 ^ V_97 )
V_594 . V_399 = V_502 ;
break;
}
case V_431 :
case V_602 :
V_594 . V_399 += V_61 -> V_597 ;
break;
case V_427 :
if ( V_61 -> V_22 == V_603 )
V_1 -> V_2 . V_360 = 1 ;
else
V_1 -> V_2 . V_360 = 0 ;
break;
case V_604 :
if ( V_61 -> V_605 != V_606 )
goto V_276;
case V_428 : {
T_2 V_607 ;
T_1 V_608 ;
if ( V_61 -> V_22 == V_609 ||
V_61 -> V_22 == V_610 ) {
V_607 = ( ( V_61 -> V_600 & 0xffff ) << 16 ) |
V_389 ;
V_608 = V_61 -> V_611 ;
} else {
V_607 = ( V_61 -> V_612 & 0xffff ) << 16 ;
V_608 = V_61 -> V_613 ;
}
if ( V_61 -> V_22 == V_614 ||
V_61 -> V_22 == V_610 )
V_607 |= V_388 ;
if ( V_61 -> V_605 )
V_607 |= V_615 ;
V_608 = F_365 ( V_608 , 4u ) ;
V_607 |= V_608 << V_391 ;
V_607 |= ( T_1 ) V_61 -> V_616 << ( V_617 - 1 ) ;
V_1 -> V_2 . V_360 = V_607 ;
V_1 -> V_2 . V_358 = V_61 -> V_71 ;
break;
}
default:
break;
}
if ( F_33 ( V_72 ) )
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_399 = V_594 . V_399 ;
V_409 = F_223 ( V_10 ) ;
V_65 = ( V_409 == V_412 ) ? V_618
: V_592 ;
V_276:
return V_65 ;
}
static void F_366 ( struct V_8 * V_9 )
{
F_166 () ;
}
static void F_367 ( struct V_8 * V_9 , int V_140 )
{
}
static int T_5 F_368 ( void )
{
return F_369 ( & V_619 , sizeof( struct V_7 ) ,
F_370 ( struct V_7 ) , V_620 ) ;
}
static void T_6 F_371 ( void )
{
F_372 () ;
}
