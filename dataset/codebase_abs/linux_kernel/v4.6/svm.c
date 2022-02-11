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
if ( F_33 ( V_292 ) )
F_50 ( V_293 , V_10 -> V_294 ) ;
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
++ V_9 -> V_295 . V_296 ;
F_123 ( V_10 -> V_284 . V_286 ) ;
#ifdef F_26
F_124 ( V_237 , V_10 -> V_284 . V_237 ) ;
F_50 ( V_297 , V_298 -> V_299 . V_238 ) ;
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
return F_4 ( V_9 ) -> V_1 -> V_58 . V_300 ;
}
static void F_128 ( struct V_8 * V_9 , unsigned long V_300 )
{
F_4 ( V_9 ) -> V_1 -> V_58 . V_300 = V_300 ;
}
static T_1 F_129 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_130 ( struct V_8 * V_9 , enum V_301 V_302 )
{
switch ( V_302 ) {
case V_303 :
F_73 ( ! V_55 ) ;
F_131 ( V_9 , V_9 -> V_39 . V_304 , F_132 ( V_9 ) ) ;
break;
default:
F_78 () ;
}
}
static void F_133 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_305 ) ;
}
static void F_134 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_305 ) ;
}
static struct V_179 * F_135 ( struct V_8 * V_9 , int V_180 )
{
struct V_191 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_180 ) {
case V_306 : return & V_58 -> V_87 ;
case V_307 : return & V_58 -> V_236 ;
case V_308 : return & V_58 -> V_234 ;
case V_309 : return & V_58 -> V_237 ;
case V_310 : return & V_58 -> V_238 ;
case V_311 : return & V_58 -> V_235 ;
case V_312 : return & V_58 -> V_245 ;
case V_313 : return & V_58 -> V_243 ;
}
F_78 () ;
return NULL ;
}
static T_2 F_136 ( struct V_8 * V_9 , int V_180 )
{
struct V_179 * V_314 = F_135 ( V_9 , V_180 ) ;
return V_314 -> V_88 ;
}
static void F_137 ( struct V_8 * V_9 ,
struct V_315 * V_316 , int V_180 )
{
struct V_179 * V_314 = F_135 ( V_9 , V_180 ) ;
V_316 -> V_88 = V_314 -> V_88 ;
V_316 -> V_186 = V_314 -> V_186 ;
V_316 -> V_181 = V_314 -> V_181 ;
V_316 -> type = V_314 -> V_182 & V_317 ;
V_316 -> V_314 = ( V_314 -> V_182 >> V_318 ) & 1 ;
V_316 -> V_319 = ( V_314 -> V_182 >> V_320 ) & 3 ;
V_316 -> V_321 = ( V_314 -> V_182 >> V_322 ) & 1 ;
V_316 -> V_323 = ( V_314 -> V_182 >> V_324 ) & 1 ;
V_316 -> V_325 = ( V_314 -> V_182 >> V_326 ) & 1 ;
V_316 -> V_327 = ( V_314 -> V_182 >> V_328 ) & 1 ;
V_316 -> V_15 = V_314 -> V_186 > 0xfffff ;
V_316 -> V_329 = ! V_316 -> V_321 || ( V_316 -> type == 0 ) ;
switch ( V_180 ) {
case V_312 :
V_316 -> type |= 0x2 ;
break;
case V_307 :
case V_308 :
case V_309 :
case V_310 :
if ( ! V_316 -> V_329 )
V_316 -> type |= 0x1 ;
break;
case V_311 :
if ( V_316 -> V_329 )
V_316 -> V_327 = 0 ;
V_316 -> V_319 = F_4 ( V_9 ) -> V_1 -> V_58 . V_330 ;
break;
}
}
static int F_138 ( struct V_8 * V_9 )
{
struct V_191 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_330 ;
}
static void F_139 ( struct V_8 * V_9 , struct V_115 * V_331 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_331 -> V_332 = V_10 -> V_1 -> V_58 . V_242 . V_186 ;
V_331 -> V_128 = V_10 -> V_1 -> V_58 . V_242 . V_88 ;
}
static void F_140 ( struct V_8 * V_9 , struct V_115 * V_331 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_242 . V_186 = V_331 -> V_332 ;
V_10 -> V_1 -> V_58 . V_242 . V_88 = V_331 -> V_128 ;
F_3 ( V_10 -> V_1 , V_333 ) ;
}
static void F_141 ( struct V_8 * V_9 , struct V_115 * V_331 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_331 -> V_332 = V_10 -> V_1 -> V_58 . V_241 . V_186 ;
V_331 -> V_128 = V_10 -> V_1 -> V_58 . V_241 . V_88 ;
}
static void F_142 ( struct V_8 * V_9 , struct V_115 * V_331 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_241 . V_186 = V_331 -> V_332 ;
V_10 -> V_1 -> V_58 . V_241 . V_88 = V_331 -> V_128 ;
F_3 ( V_10 -> V_1 , V_333 ) ;
}
static void F_143 ( struct V_8 * V_9 )
{
}
static void F_144 ( struct V_8 * V_9 )
{
}
static void F_145 ( struct V_8 * V_9 )
{
}
static void F_146 ( struct V_7 * V_10 )
{
T_9 V_334 = V_10 -> V_9 . V_39 . V_335 ;
T_2 * V_336 = & V_10 -> V_1 -> V_58 . V_335 ;
if ( ! V_10 -> V_9 . V_192 )
* V_336 |= V_337 ;
else
* V_336 = ( * V_336 & ~ V_337 )
| ( V_334 & V_337 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_334 == * V_336 && V_10 -> V_9 . V_192 ) {
F_10 ( V_10 , V_193 ) ;
F_10 ( V_10 , V_196 ) ;
} else {
F_9 ( V_10 , V_193 ) ;
F_9 ( V_10 , V_196 ) ;
}
}
static void F_102 ( struct V_8 * V_9 , unsigned long V_335 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_147 ( V_9 ) && ( V_335 & V_338 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_147 ( V_9 ) && ! ( V_335 & V_338 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_335 = V_335 ;
if ( ! V_55 )
V_335 |= V_338 | V_339 ;
if ( ! V_9 -> V_192 )
V_335 |= V_340 ;
if ( F_148 ( V_9 -> V_270 , V_341 ) )
V_335 &= ~ ( V_251 | V_250 ) ;
V_10 -> V_1 -> V_58 . V_335 = V_335 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_146 ( V_10 ) ;
}
static int F_149 ( struct V_8 * V_9 , unsigned long V_253 )
{
unsigned long V_342 = F_150 () & V_343 ;
unsigned long V_344 = F_4 ( V_9 ) -> V_1 -> V_58 . V_253 ;
if ( V_253 & V_345 )
return 1 ;
if ( V_55 && ( ( V_344 ^ V_253 ) & V_346 ) )
F_151 ( V_9 ) ;
V_9 -> V_39 . V_253 = V_253 ;
if ( ! V_55 )
V_253 |= V_254 ;
V_253 |= V_342 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_253 = V_253 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_152 ( struct V_8 * V_9 ,
struct V_315 * V_316 , int V_180 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_179 * V_314 = F_135 ( V_9 , V_180 ) ;
V_314 -> V_88 = V_316 -> V_88 ;
V_314 -> V_186 = V_316 -> V_186 ;
V_314 -> V_181 = V_316 -> V_181 ;
if ( V_316 -> V_329 )
V_314 -> V_182 = 0 ;
else {
V_314 -> V_182 = ( V_316 -> type & V_317 ) ;
V_314 -> V_182 |= ( V_316 -> V_314 & 1 ) << V_318 ;
V_314 -> V_182 |= ( V_316 -> V_319 & 3 ) << V_320 ;
V_314 -> V_182 |= ( V_316 -> V_321 & 1 ) << V_322 ;
V_314 -> V_182 |= ( V_316 -> V_323 & 1 ) << V_324 ;
V_314 -> V_182 |= ( V_316 -> V_325 & 1 ) << V_326 ;
V_314 -> V_182 |= ( V_316 -> V_327 & 1 ) << V_328 ;
V_314 -> V_182 |= ( V_316 -> V_15 & 1 ) << V_347 ;
}
if ( V_180 == V_311 )
V_10 -> V_1 -> V_58 . V_330 = ( V_314 -> V_182 >> V_320 ) & 3 ;
F_3 ( V_10 -> V_1 , V_348 ) ;
}
static void F_153 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_83 ) ;
if ( V_9 -> V_349 & V_350 ) {
if ( V_9 -> V_349 & V_351 )
F_14 ( V_10 , V_83 ) ;
} else
V_9 -> V_349 = 0 ;
}
static void F_154 ( struct V_7 * V_10 , struct V_113 * V_114 )
{
if ( V_114 -> V_127 > V_114 -> V_125 ) {
++ V_114 -> V_124 ;
V_114 -> V_127 = 1 ;
V_10 -> V_1 -> V_2 . V_352 = V_353 ;
}
V_10 -> V_124 = V_114 -> V_124 ;
V_10 -> V_1 -> V_2 . V_51 = V_114 -> V_127 ++ ;
F_3 ( V_10 -> V_1 , V_354 ) ;
}
static T_2 F_155 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_247 ;
}
static void F_156 ( struct V_8 * V_9 , unsigned long V_355 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_247 = V_355 ;
F_3 ( V_10 -> V_1 , V_356 ) ;
}
static void F_157 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_158 ( V_9 -> V_39 . V_327 [ 0 ] , 0 ) ;
F_158 ( V_9 -> V_39 . V_327 [ 1 ] , 1 ) ;
F_158 ( V_9 -> V_39 . V_327 [ 2 ] , 2 ) ;
F_158 ( V_9 -> V_39 . V_327 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_247 = F_155 ( V_9 ) ;
V_9 -> V_39 . V_357 = V_10 -> V_1 -> V_58 . V_357 ;
V_9 -> V_39 . V_358 &= ~ V_359 ;
F_12 ( V_10 ) ;
}
static void F_159 ( struct V_8 * V_9 , unsigned long V_355 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_357 = V_355 ;
F_3 ( V_10 -> V_1 , V_356 ) ;
}
static int F_160 ( struct V_7 * V_10 )
{
T_2 V_360 = V_10 -> V_1 -> V_2 . V_361 ;
T_1 V_81 ;
int V_141 = 1 ;
switch ( V_10 -> V_362 ) {
default:
V_81 = V_10 -> V_1 -> V_2 . V_363 ;
F_161 ( V_360 , V_81 ) ;
if ( ! V_55 && F_162 ( & V_10 -> V_9 ) )
F_163 ( & V_10 -> V_9 , V_360 ) ;
V_141 = F_164 ( & V_10 -> V_9 , V_360 , V_81 ,
V_10 -> V_1 -> V_2 . V_364 ,
V_10 -> V_1 -> V_2 . V_365 ) ;
break;
case V_366 :
V_10 -> V_362 = 0 ;
F_165 () ;
F_166 ( V_360 ) ;
F_167 () ;
break;
case V_367 :
V_10 -> V_362 = 0 ;
F_165 () ;
F_168 ( V_360 ) ;
F_167 () ;
break;
}
return V_141 ;
}
static int F_169 ( struct V_7 * V_10 )
{
struct V_368 * V_368 = V_10 -> V_9 . V_369 ;
if ( ! ( V_10 -> V_9 . V_349 &
( V_370 | V_371 ) ) &&
! V_10 -> V_372 ) {
F_170 ( & V_10 -> V_9 , V_204 ) ;
return 1 ;
}
if ( V_10 -> V_372 ) {
V_10 -> V_372 = false ;
if ( ! ( V_10 -> V_9 . V_349 & V_370 ) )
V_10 -> V_1 -> V_58 . V_300 &=
~ ( V_373 | V_374 ) ;
}
if ( V_10 -> V_9 . V_349 &
( V_370 | V_371 ) ) {
V_368 -> V_375 = V_376 ;
V_368 -> V_377 . V_39 . V_378 =
V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_368 -> V_377 . V_39 . V_379 = V_204 ;
return 0 ;
}
return 1 ;
}
static int F_171 ( struct V_7 * V_10 )
{
struct V_368 * V_368 = V_10 -> V_9 . V_369 ;
V_368 -> V_375 = V_376 ;
V_368 -> V_377 . V_39 . V_378 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_368 -> V_377 . V_39 . V_379 = V_83 ;
return 0 ;
}
static int F_172 ( struct V_7 * V_10 )
{
int V_380 ;
V_380 = F_34 ( & V_10 -> V_9 , V_381 ) ;
if ( V_380 != V_74 )
F_170 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
static int F_173 ( struct V_7 * V_10 )
{
F_174 ( & V_10 -> V_9 , V_203 , 0 ) ;
return 1 ;
}
static void F_175 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_382 ) ;
V_10 -> V_9 . V_192 = 1 ;
F_146 ( V_10 ) ;
}
static int F_176 ( struct V_7 * V_10 )
{
F_175 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_177 ( void )
{
int V_96 , V_44 ;
T_2 V_355 ;
if ( ! V_100 )
return false ;
V_355 = F_42 ( V_383 , & V_96 ) ;
if ( V_96 )
return false ;
V_355 &= ~ ( 1ULL << 62 ) ;
if ( V_355 != 0xb600000000010015ULL )
return false ;
for ( V_44 = 0 ; V_44 < 6 ; ++ V_44 )
F_45 ( F_178 ( V_44 ) , 0 , 0 ) ;
V_355 = F_42 ( V_384 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_355 &= ~ ( 1ULL << 2 ) ;
V_94 = F_43 ( V_355 ) ;
V_95 = F_44 ( V_355 ) ;
F_45 ( V_384 , V_94 , V_95 ) ;
}
F_179 () ;
return true ;
}
static void F_180 ( struct V_7 * V_10 )
{
if ( F_177 () ) {
F_56 ( L_9 ) ;
F_181 ( V_385 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_182 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_183 ( struct V_7 * V_10 )
{
struct V_368 * V_368 = V_10 -> V_9 . V_369 ;
F_111 ( V_10 -> V_1 ) ;
F_99 ( V_10 ) ;
V_368 -> V_375 = V_386 ;
return 0 ;
}
static int F_184 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_387 = V_10 -> V_1 -> V_2 . V_363 ;
int V_332 , V_388 , string ;
unsigned V_389 ;
++ V_10 -> V_9 . V_295 . V_390 ;
string = ( V_387 & V_391 ) != 0 ;
V_388 = ( V_387 & V_392 ) != 0 ;
if ( string || V_388 )
return F_34 ( V_9 , 0 ) == V_74 ;
V_389 = V_387 >> 16 ;
V_332 = ( V_387 & V_393 ) >> V_394 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_361 ;
F_31 ( & V_10 -> V_9 ) ;
return F_185 ( V_9 , V_332 , V_389 ) ;
}
static int F_186 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_187 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_295 . V_395 ;
return 1 ;
}
static int F_188 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_189 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 1 ;
return F_190 ( & V_10 -> V_9 ) ;
}
static int F_191 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
return F_192 ( & V_10 -> V_9 ) ;
}
static unsigned long F_193 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_396 ;
}
static T_2 F_194 ( struct V_8 * V_9 , int V_145 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_258 = V_10 -> V_17 . V_396 ;
T_2 V_397 ;
int V_65 ;
V_65 = F_195 ( V_9 , F_196 ( V_258 ) , & V_397 ,
F_197 ( V_258 ) + V_145 * 8 , 8 ) ;
if ( V_65 )
return 0 ;
return V_397 ;
}
static void F_198 ( struct V_8 * V_9 ,
unsigned long V_398 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_396 = V_398 ;
F_3 ( V_10 -> V_1 , V_399 ) ;
F_151 ( V_9 ) ;
}
static void F_199 ( struct V_8 * V_9 ,
struct V_400 * V_401 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_402 != V_403 ) {
V_10 -> V_1 -> V_2 . V_402 = V_403 ;
V_10 -> V_1 -> V_2 . V_404 = 0 ;
V_10 -> V_1 -> V_2 . V_363 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_361 = V_401 -> V_128 ;
}
V_10 -> V_1 -> V_2 . V_363 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_363 |= V_401 -> V_81 ;
if ( V_10 -> V_1 -> V_2 . V_363 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_363 &= ~ 1 ;
F_200 ( V_10 ) ;
}
static void F_201 ( struct V_8 * V_9 )
{
F_72 ( F_202 ( V_9 ) ) ;
F_203 ( V_9 ) ;
V_9 -> V_39 . V_405 . V_406 = F_198 ;
V_9 -> V_39 . V_405 . V_407 = F_193 ;
V_9 -> V_39 . V_405 . V_408 = F_194 ;
V_9 -> V_39 . V_405 . V_409 = F_199 ;
V_9 -> V_39 . V_405 . V_410 = F_25 () ;
F_204 ( V_9 , & V_9 -> V_39 . V_405 ) ;
V_9 -> V_39 . V_304 = & V_9 -> V_39 . V_411 ;
}
static void F_205 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_304 = & V_9 -> V_39 . V_405 ;
}
static int F_206 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_147 ( & V_10 -> V_9 ) ) {
F_170 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_330 ) {
F_207 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_7 * V_10 , unsigned V_79 ,
bool V_80 , T_1 V_81 )
{
int V_412 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_402 = V_413 + V_79 ;
V_10 -> V_1 -> V_2 . V_404 = 0 ;
V_10 -> V_1 -> V_2 . V_363 = V_81 ;
V_10 -> V_1 -> V_2 . V_361 = V_10 -> V_9 . V_39 . V_414 ;
V_412 = F_208 ( V_10 ) ;
if ( V_412 == V_415 )
V_10 -> V_17 . V_416 = true ;
return V_412 ;
}
static inline bool F_209 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_417 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_418 ) )
return false ;
if ( V_10 -> V_17 . V_416 )
return false ;
V_10 -> V_1 -> V_2 . V_402 = V_419 ;
V_10 -> V_1 -> V_2 . V_363 = 0 ;
V_10 -> V_1 -> V_2 . V_361 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_416 = true ;
F_210 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_211 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_206 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_402 = V_420 ;
V_10 -> V_17 . V_416 = true ;
return false ;
}
static void * F_212 ( struct V_7 * V_10 , T_2 V_421 , struct V_163 * * V_422 )
{
struct V_163 * V_163 ;
F_213 () ;
V_163 = F_214 ( & V_10 -> V_9 , V_421 >> V_134 ) ;
if ( F_215 ( V_163 ) )
goto error;
* V_422 = V_163 ;
return F_216 ( V_163 ) ;
error:
F_207 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_217 ( struct V_163 * V_163 )
{
F_218 ( V_163 ) ;
F_219 ( V_163 ) ;
}
static int F_220 ( struct V_7 * V_10 )
{
unsigned V_389 , V_332 , V_423 ;
T_10 V_97 , V_70 ;
T_4 V_424 ;
T_2 V_421 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_215 ) ) )
return V_425 ;
V_389 = V_10 -> V_1 -> V_2 . V_363 >> 16 ;
V_332 = ( V_10 -> V_1 -> V_2 . V_363 & V_393 ) >>
V_394 ;
V_421 = V_10 -> V_17 . V_426 + ( V_389 / 8 ) ;
V_424 = V_389 % 8 ;
V_423 = ( V_424 + V_332 > 8 ) ? 2 : 1 ;
V_70 = ( 0xf >> ( 4 - V_332 ) ) << V_424 ;
V_97 = 0 ;
if ( F_221 ( & V_10 -> V_9 , V_421 , & V_97 , V_423 ) )
return V_415 ;
return ( V_97 & V_70 ) ? V_415 : V_425 ;
}
static int F_222 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_355 ;
int V_149 , V_70 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_216 ) ) )
return V_425 ;
V_42 = V_10 -> V_9 . V_39 . V_248 [ V_427 ] ;
V_43 = F_21 ( V_42 ) ;
V_149 = V_10 -> V_1 -> V_2 . V_363 & 1 ;
V_70 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_149 ) ;
if ( V_43 == V_49 )
return V_415 ;
V_43 *= 4 ;
if ( F_221 ( & V_10 -> V_9 , V_10 -> V_17 . V_428 + V_43 , & V_355 , 4 ) )
return V_415 ;
return ( V_355 & V_70 ) ? V_415 : V_425 ;
}
static int F_223 ( struct V_7 * V_10 )
{
T_1 V_402 = V_10 -> V_1 -> V_2 . V_402 ;
switch ( V_402 ) {
case V_419 :
case V_420 :
case V_413 + V_202 :
return V_425 ;
case V_403 :
if ( V_55 )
return V_425 ;
break;
case V_413 + V_200 :
if ( ! V_55 && V_10 -> V_362 == 0 )
return V_425 ;
break;
case V_413 + V_382 :
F_176 ( V_10 ) ;
break;
default:
break;
}
return V_429 ;
}
static int F_208 ( struct V_7 * V_10 )
{
T_1 V_402 = V_10 -> V_1 -> V_2 . V_402 ;
int V_412 = V_425 ;
switch ( V_402 ) {
case V_430 :
V_412 = F_222 ( V_10 ) ;
break;
case V_431 :
V_412 = F_220 ( V_10 ) ;
break;
case V_432 ... V_433 : {
T_1 V_6 = 1U << ( V_402 - V_432 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_412 = V_415 ;
break;
}
case V_434 ... V_435 : {
T_1 V_6 = 1U << ( V_402 - V_434 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_412 = V_415 ;
break;
}
case V_413 ... V_413 + 0x1f : {
T_1 V_436 = 1 << ( V_402 - V_413 ) ;
if ( V_10 -> V_17 . V_21 & V_436 )
V_412 = V_415 ;
else if ( ( V_402 == V_413 + V_200 ) &&
V_10 -> V_362 != 0 )
V_412 = V_415 ;
break;
}
case V_437 : {
V_412 = V_415 ;
break;
}
default: {
T_2 V_438 = 1ULL << ( V_402 - V_419 ) ;
if ( V_10 -> V_17 . V_22 & V_438 )
V_412 = V_415 ;
}
}
return V_412 ;
}
static int F_224 ( struct V_7 * V_10 )
{
int V_412 ;
V_412 = F_208 ( V_10 ) ;
if ( V_412 == V_415 )
F_200 ( V_10 ) ;
return V_412 ;
}
static inline void F_225 ( struct V_1 * V_439 , struct V_1 * V_440 )
{
struct V_11 * V_441 = & V_439 -> V_2 ;
struct V_11 * V_442 = & V_440 -> V_2 ;
V_441 -> V_19 = V_442 -> V_19 ;
V_441 -> V_20 = V_442 -> V_20 ;
V_441 -> V_21 = V_442 -> V_21 ;
V_441 -> V_22 = V_442 -> V_22 ;
V_441 -> V_230 = V_442 -> V_230 ;
V_441 -> V_231 = V_442 -> V_231 ;
V_441 -> V_187 = V_442 -> V_187 ;
V_441 -> V_51 = V_442 -> V_51 ;
V_441 -> V_352 = V_442 -> V_352 ;
V_441 -> V_232 = V_442 -> V_232 ;
V_441 -> V_443 = V_442 -> V_443 ;
V_441 -> V_66 = V_442 -> V_66 ;
V_441 -> V_402 = V_442 -> V_402 ;
V_441 -> V_404 = V_442 -> V_404 ;
V_441 -> V_363 = V_442 -> V_363 ;
V_441 -> V_361 = V_442 -> V_361 ;
V_441 -> V_444 = V_442 -> V_444 ;
V_441 -> V_445 = V_442 -> V_445 ;
V_441 -> V_255 = V_442 -> V_255 ;
V_441 -> V_90 = V_442 -> V_90 ;
V_441 -> V_93 = V_442 -> V_93 ;
V_441 -> V_396 = V_442 -> V_396 ;
V_441 -> V_158 = V_442 -> V_158 ;
}
static int F_200 ( struct V_7 * V_10 )
{
struct V_1 * V_446 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
F_226 ( V_1 -> V_2 . V_402 ,
V_1 -> V_2 . V_363 ,
V_1 -> V_2 . V_361 ,
V_1 -> V_2 . V_444 ,
V_1 -> V_2 . V_445 ,
V_447 ) ;
V_446 = F_212 ( V_10 , V_10 -> V_17 . V_1 , & V_163 ) ;
if ( ! V_446 )
return 1 ;
F_227 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_446 -> V_58 . V_234 = V_1 -> V_58 . V_234 ;
V_446 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_446 -> V_58 . V_235 = V_1 -> V_58 . V_235 ;
V_446 -> V_58 . V_236 = V_1 -> V_58 . V_236 ;
V_446 -> V_58 . V_241 = V_1 -> V_58 . V_241 ;
V_446 -> V_58 . V_242 = V_1 -> V_58 . V_242 ;
V_446 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_446 -> V_58 . V_335 = F_228 ( & V_10 -> V_9 ) ;
V_446 -> V_58 . V_258 = F_132 ( & V_10 -> V_9 ) ;
V_446 -> V_58 . V_414 = V_1 -> V_58 . V_414 ;
V_446 -> V_58 . V_253 = V_10 -> V_9 . V_39 . V_253 ;
V_446 -> V_58 . V_300 = F_229 ( & V_10 -> V_9 ) ;
V_446 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_446 -> V_58 . V_448 = V_1 -> V_58 . V_448 ;
V_446 -> V_58 . V_449 = V_1 -> V_58 . V_449 ;
V_446 -> V_58 . V_357 = V_1 -> V_58 . V_357 ;
V_446 -> V_58 . V_247 = V_1 -> V_58 . V_247 ;
V_446 -> V_58 . V_330 = V_1 -> V_58 . V_330 ;
V_446 -> V_2 . V_232 = V_1 -> V_2 . V_232 ;
V_446 -> V_2 . V_443 = V_1 -> V_2 . V_443 ;
V_446 -> V_2 . V_66 = V_1 -> V_2 . V_66 ;
V_446 -> V_2 . V_402 = V_1 -> V_2 . V_402 ;
V_446 -> V_2 . V_404 = V_1 -> V_2 . V_404 ;
V_446 -> V_2 . V_363 = V_1 -> V_2 . V_363 ;
V_446 -> V_2 . V_361 = V_1 -> V_2 . V_361 ;
V_446 -> V_2 . V_444 = V_1 -> V_2 . V_444 ;
V_446 -> V_2 . V_445 = V_1 -> V_2 . V_445 ;
if ( V_10 -> V_450 )
V_446 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_451 = & V_446 -> V_2 ;
V_451 -> V_444 = V_1 -> V_2 . V_90 ;
V_451 -> V_445 = V_1 -> V_2 . V_93 ;
}
V_446 -> V_2 . V_352 = 0 ;
V_446 -> V_2 . V_90 = 0 ;
V_446 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_417 ) )
V_446 -> V_2 . V_232 &= ~ V_233 ;
F_225 ( V_1 , V_18 ) ;
F_230 ( & V_10 -> V_9 ) ;
F_231 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_396 = 0 ;
V_10 -> V_1 -> V_58 . V_234 = V_18 -> V_58 . V_234 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_235 = V_18 -> V_58 . V_235 ;
V_10 -> V_1 -> V_58 . V_236 = V_18 -> V_58 . V_236 ;
V_10 -> V_1 -> V_58 . V_241 = V_18 -> V_58 . V_241 ;
V_10 -> V_1 -> V_58 . V_242 = V_18 -> V_58 . V_242 ;
F_101 ( & V_10 -> V_9 , V_18 -> V_58 . V_300 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_102 ( & V_10 -> V_9 , V_18 -> V_58 . V_335 | V_452 ) ;
F_149 ( & V_10 -> V_9 , V_18 -> V_58 . V_253 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_258 = V_18 -> V_58 . V_258 ;
V_10 -> V_9 . V_39 . V_258 = V_18 -> V_58 . V_258 ;
} else {
( void ) F_232 ( & V_10 -> V_9 , V_18 -> V_58 . V_258 ) ;
}
F_107 ( & V_10 -> V_9 , V_453 , V_18 -> V_58 . V_449 ) ;
F_107 ( & V_10 -> V_9 , V_454 , V_18 -> V_58 . V_448 ) ;
F_107 ( & V_10 -> V_9 , V_249 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_357 = 0 ;
V_10 -> V_1 -> V_58 . V_330 = 0 ;
V_10 -> V_1 -> V_2 . V_444 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_217 ( V_163 ) ;
F_205 ( & V_10 -> V_9 ) ;
F_103 ( & V_10 -> V_9 ) ;
F_233 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_234 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_216 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_156 ; V_44 ++ ) {
T_1 V_355 , V_455 ;
T_2 V_43 ;
if ( V_157 [ V_44 ] == 0xffffffff )
break;
V_455 = V_157 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_428 + ( V_455 * 4 ) ;
if ( F_221 ( & V_10 -> V_9 , V_43 , & V_355 , 4 ) )
return false ;
V_10 -> V_17 . V_147 [ V_455 ] = V_10 -> V_147 [ V_455 ] | V_355 ;
}
V_10 -> V_1 -> V_2 . V_231 = F_100 ( V_10 -> V_17 . V_147 ) ;
return true ;
}
static bool F_235 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_219 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_255 && ! V_55 )
return false ;
return true ;
}
static bool F_236 ( struct V_7 * V_10 )
{
struct V_1 * V_446 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
T_2 V_456 ;
V_456 = V_10 -> V_1 -> V_58 . V_449 ;
V_446 = F_212 ( V_10 , V_10 -> V_1 -> V_58 . V_449 , & V_163 ) ;
if ( ! V_446 )
return false ;
if ( ! F_235 ( V_446 ) ) {
V_446 -> V_2 . V_402 = V_437 ;
V_446 -> V_2 . V_404 = 0 ;
V_446 -> V_2 . V_363 = 0 ;
V_446 -> V_2 . V_361 = 0 ;
F_217 ( V_163 ) ;
return false ;
}
F_237 ( V_10 -> V_1 -> V_58 . V_84 , V_456 ,
V_446 -> V_58 . V_84 ,
V_446 -> V_2 . V_232 ,
V_446 -> V_2 . V_90 ,
V_446 -> V_2 . V_255 ) ;
F_238 ( V_446 -> V_2 . V_19 & 0xffff ,
V_446 -> V_2 . V_19 >> 16 ,
V_446 -> V_2 . V_21 ,
V_446 -> V_2 . V_22 ) ;
F_230 ( & V_10 -> V_9 ) ;
F_231 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_234 = V_1 -> V_58 . V_234 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_235 = V_1 -> V_58 . V_235 ;
V_18 -> V_58 . V_236 = V_1 -> V_58 . V_236 ;
V_18 -> V_58 . V_241 = V_1 -> V_58 . V_241 ;
V_18 -> V_58 . V_242 = V_1 -> V_58 . V_242 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_335 = F_228 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_253 = V_10 -> V_9 . V_39 . V_253 ;
V_18 -> V_58 . V_300 = F_229 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_36 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_448 = V_1 -> V_58 . V_448 ;
V_18 -> V_58 . V_449 = V_1 -> V_58 . V_449 ;
if ( V_55 )
V_18 -> V_58 . V_258 = V_1 -> V_58 . V_258 ;
else
V_18 -> V_58 . V_258 = F_132 ( & V_10 -> V_9 ) ;
F_225 ( V_18 , V_1 ) ;
if ( F_229 ( & V_10 -> V_9 ) & V_457 )
V_10 -> V_9 . V_39 . V_40 |= V_418 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_418 ;
if ( V_446 -> V_2 . V_255 ) {
F_239 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_396 = V_446 -> V_2 . V_396 ;
F_201 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_234 = V_446 -> V_58 . V_234 ;
V_10 -> V_1 -> V_58 . V_87 = V_446 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_235 = V_446 -> V_58 . V_235 ;
V_10 -> V_1 -> V_58 . V_236 = V_446 -> V_58 . V_236 ;
V_10 -> V_1 -> V_58 . V_241 = V_446 -> V_58 . V_241 ;
V_10 -> V_1 -> V_58 . V_242 = V_446 -> V_58 . V_242 ;
F_101 ( & V_10 -> V_9 , V_446 -> V_58 . V_300 ) ;
F_27 ( & V_10 -> V_9 , V_446 -> V_58 . V_54 ) ;
F_102 ( & V_10 -> V_9 , V_446 -> V_58 . V_335 ) ;
F_149 ( & V_10 -> V_9 , V_446 -> V_58 . V_253 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_258 = V_446 -> V_58 . V_258 ;
V_10 -> V_9 . V_39 . V_258 = V_446 -> V_58 . V_258 ;
} else
( void ) F_232 ( & V_10 -> V_9 , V_446 -> V_58 . V_258 ) ;
F_103 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_414 = V_10 -> V_9 . V_39 . V_414 = V_446 -> V_58 . V_414 ;
F_107 ( & V_10 -> V_9 , V_453 , V_446 -> V_58 . V_449 ) ;
F_107 ( & V_10 -> V_9 , V_454 , V_446 -> V_58 . V_448 ) ;
F_107 ( & V_10 -> V_9 , V_249 , V_446 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_449 = V_446 -> V_58 . V_449 ;
V_10 -> V_1 -> V_58 . V_448 = V_446 -> V_58 . V_448 ;
V_10 -> V_1 -> V_58 . V_84 = V_446 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_357 = V_446 -> V_58 . V_357 ;
V_10 -> V_1 -> V_58 . V_247 = V_446 -> V_58 . V_247 ;
V_10 -> V_1 -> V_58 . V_330 = V_446 -> V_58 . V_330 ;
V_10 -> V_17 . V_428 = V_446 -> V_2 . V_231 & ~ 0x0fffULL ;
V_10 -> V_17 . V_426 = V_446 -> V_2 . V_230 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_446 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_446 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_446 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_446 -> V_2 . V_22 ;
F_151 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_232 = V_446 -> V_2 . V_232 | V_233 ;
if ( V_446 -> V_2 . V_232 & V_233 )
V_10 -> V_9 . V_39 . V_40 |= V_417 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_417 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_417 ) {
F_10 ( V_10 , V_458 ) ;
F_10 ( V_10 , V_199 ) ;
}
F_17 ( V_10 , V_220 ) ;
V_10 -> V_1 -> V_2 . V_158 = V_446 -> V_2 . V_158 ;
V_10 -> V_1 -> V_2 . V_443 = V_446 -> V_2 . V_443 ;
V_10 -> V_1 -> V_2 . V_66 = V_446 -> V_2 . V_66 ;
V_10 -> V_1 -> V_2 . V_187 += V_446 -> V_2 . V_187 ;
V_10 -> V_1 -> V_2 . V_90 = V_446 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_446 -> V_2 . V_93 ;
F_217 ( V_163 ) ;
F_240 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_456 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_241 ( struct V_1 * V_440 , struct V_1 * V_459 )
{
V_459 -> V_58 . V_237 = V_440 -> V_58 . V_237 ;
V_459 -> V_58 . V_238 = V_440 -> V_58 . V_238 ;
V_459 -> V_58 . V_245 = V_440 -> V_58 . V_245 ;
V_459 -> V_58 . V_243 = V_440 -> V_58 . V_243 ;
V_459 -> V_58 . V_460 = V_440 -> V_58 . V_460 ;
V_459 -> V_58 . V_461 = V_440 -> V_58 . V_461 ;
V_459 -> V_58 . V_462 = V_440 -> V_58 . V_462 ;
V_459 -> V_58 . V_463 = V_440 -> V_58 . V_463 ;
V_459 -> V_58 . V_464 = V_440 -> V_58 . V_464 ;
V_459 -> V_58 . V_465 = V_440 -> V_58 . V_465 ;
V_459 -> V_58 . V_466 = V_440 -> V_58 . V_466 ;
V_459 -> V_58 . V_467 = V_440 -> V_58 . V_467 ;
}
static int F_242 ( struct V_7 * V_10 )
{
struct V_1 * V_446 ;
struct V_163 * V_163 ;
if ( F_206 ( V_10 ) )
return 1 ;
V_446 = F_212 ( V_10 , V_10 -> V_1 -> V_58 . V_449 , & V_163 ) ;
if ( ! V_446 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_241 ( V_446 , V_10 -> V_1 ) ;
F_217 ( V_163 ) ;
return 1 ;
}
static int F_243 ( struct V_7 * V_10 )
{
struct V_1 * V_446 ;
struct V_163 * V_163 ;
if ( F_206 ( V_10 ) )
return 1 ;
V_446 = F_212 ( V_10 , V_10 -> V_1 -> V_58 . V_449 , & V_163 ) ;
if ( ! V_446 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_241 ( V_10 -> V_1 , V_446 ) ;
F_217 ( V_163 ) ;
return 1 ;
}
static int F_244 ( struct V_7 * V_10 )
{
if ( F_206 ( V_10 ) )
return 1 ;
F_37 ( & V_10 -> V_9 , F_36 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_236 ( V_10 ) )
return 1 ;
if ( ! F_234 ( V_10 ) )
goto V_468;
return 1 ;
V_468:
V_10 -> V_1 -> V_2 . V_402 = V_437 ;
V_10 -> V_1 -> V_2 . V_404 = 0 ;
V_10 -> V_1 -> V_2 . V_363 = 0 ;
V_10 -> V_1 -> V_2 . V_361 = 0 ;
F_200 ( V_10 ) ;
return 1 ;
}
static int F_245 ( struct V_7 * V_10 )
{
if ( F_206 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_181 ( V_469 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
if ( F_206 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_134 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_232 &= ~ V_470 ;
F_3 ( V_10 -> V_1 , V_471 ) ;
return 1 ;
}
static int F_247 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_248 ( V_10 -> V_1 -> V_58 . V_84 , F_249 ( & V_10 -> V_9 , V_427 ) ,
F_249 ( & V_10 -> V_9 , V_453 ) ) ;
F_250 ( V_9 , F_249 ( & V_10 -> V_9 , V_453 ) ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_251 ( struct V_7 * V_10 )
{
F_252 ( V_10 -> V_1 -> V_58 . V_84 , F_249 ( & V_10 -> V_9 , V_453 ) ) ;
F_170 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
static int F_253 ( struct V_7 * V_10 )
{
F_254 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_255 ( struct V_7 * V_10 )
{
T_2 V_472 = F_256 ( & V_10 -> V_9 ) ;
T_1 V_145 = F_249 ( & V_10 -> V_9 , V_427 ) ;
if ( F_257 ( & V_10 -> V_9 , V_145 , V_472 ) == 0 ) {
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_258 ( struct V_7 * V_10 )
{
T_10 V_473 ;
int V_474 ;
int V_475 = V_10 -> V_1 -> V_2 . V_444 &
V_476 ;
int V_477 = V_10 -> V_1 -> V_2 . V_444 & V_478 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_444 & V_476 ;
T_7 V_479 =
V_10 -> V_1 -> V_2 . V_444 & V_480 ;
bool V_80 = false ;
T_1 V_81 = 0 ;
V_473 = ( T_10 ) V_10 -> V_1 -> V_2 . V_363 ;
if ( V_10 -> V_1 -> V_2 . V_361 &
( 1ULL << V_481 ) )
V_474 = V_482 ;
else if ( V_10 -> V_1 -> V_2 . V_361 &
( 1ULL << V_483 ) )
V_474 = V_484 ;
else if ( V_479 )
V_474 = V_485 ;
else
V_474 = V_486 ;
if ( V_474 == V_485 ) {
switch ( type ) {
case V_487 :
V_10 -> V_9 . V_39 . V_488 = false ;
break;
case V_489 :
if ( V_10 -> V_1 -> V_2 . V_361 &
( 1ULL << V_490 ) ) {
V_80 = true ;
V_81 =
( T_1 ) V_10 -> V_1 -> V_2 . V_361 ;
}
F_230 ( & V_10 -> V_9 ) ;
break;
case V_491 :
F_231 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_474 != V_485 ||
V_475 == V_492 ||
( V_475 == V_489 &&
( V_477 == V_493 || V_477 == V_83 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_475 != V_492 )
V_477 = - 1 ;
if ( F_259 ( & V_10 -> V_9 , V_473 , V_477 , V_474 ,
V_80 , V_81 ) == V_494 ) {
V_10 -> V_9 . V_369 -> V_375 = V_495 ;
V_10 -> V_9 . V_369 -> V_496 . V_497 = V_498 ;
V_10 -> V_9 . V_369 -> V_496 . V_499 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_260 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_261 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_262 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_295 . V_500 ;
F_17 ( V_10 , V_501 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_502 ;
V_10 -> V_503 = F_36 ( & V_10 -> V_9 ) ;
F_181 ( V_469 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
if ( ! F_33 ( V_504 ) )
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
F_250 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_363 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_264 ( struct V_7 * V_10 )
{
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
}
static int F_265 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_33 ( V_72 ) )
return F_264 ( V_10 ) ;
V_96 = F_266 ( & V_10 -> V_9 ) ;
F_267 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static bool F_268 ( struct V_7 * V_10 ,
unsigned long V_97 )
{
unsigned long V_335 = V_10 -> V_9 . V_39 . V_335 ;
bool V_65 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_208 ) ) ) )
return false ;
V_335 &= ~ V_337 ;
V_97 &= ~ V_337 ;
if ( V_335 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_402 = V_505 ;
V_65 = ( F_224 ( V_10 ) == V_415 ) ;
}
return V_65 ;
}
static int F_269 ( struct V_7 * V_10 )
{
int V_302 , V_506 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_33 ( V_504 ) )
return F_264 ( V_10 ) ;
if ( F_118 ( ( V_10 -> V_1 -> V_2 . V_363 & V_507 ) == 0 ) )
return F_264 ( V_10 ) ;
V_302 = V_10 -> V_1 -> V_2 . V_363 & V_508 ;
if ( V_10 -> V_1 -> V_2 . V_402 == V_505 )
V_506 = V_509 - V_432 ;
else
V_506 = V_10 -> V_1 -> V_2 . V_402 - V_432 ;
V_96 = 0 ;
if ( V_506 >= 16 ) {
V_506 -= 16 ;
V_97 = F_249 ( & V_10 -> V_9 , V_302 ) ;
switch ( V_506 ) {
case 0 :
if ( ! F_268 ( V_10 , V_97 ) )
V_96 = F_270 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_232 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_271 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_272 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_273 ( 1 , L_10 , V_506 ) ;
F_170 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
} else {
switch ( V_506 ) {
case 0 :
V_97 = F_228 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_414 ;
break;
case 3 :
V_97 = F_132 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_274 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_275 ( & V_10 -> V_9 ) ;
break;
default:
F_273 ( 1 , L_11 , V_506 ) ;
F_170 ( & V_10 -> V_9 , V_201 ) ;
return 1 ;
}
F_107 ( & V_10 -> V_9 , V_302 , V_97 ) ;
}
F_267 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_276 ( struct V_7 * V_10 )
{
int V_302 , V_510 ;
unsigned long V_97 ;
if ( V_10 -> V_9 . V_349 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_358 |= V_359 ;
return 1 ;
}
if ( ! F_85 ( V_504 ) )
return F_264 ( V_10 ) ;
V_302 = V_10 -> V_1 -> V_2 . V_363 & V_508 ;
V_510 = V_10 -> V_1 -> V_2 . V_402 - V_434 ;
if ( V_510 >= 16 ) {
if ( ! F_277 ( & V_10 -> V_9 , V_510 - 16 ) )
return 1 ;
V_97 = F_249 ( & V_10 -> V_9 , V_302 ) ;
F_278 ( & V_10 -> V_9 , V_510 - 16 , V_97 ) ;
} else {
if ( ! F_277 ( & V_10 -> V_9 , V_510 ) )
return 1 ;
F_279 ( & V_10 -> V_9 , V_510 , & V_97 ) ;
F_107 ( & V_10 -> V_9 , V_302 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_280 ( struct V_7 * V_10 )
{
struct V_368 * V_368 = V_10 -> V_9 . V_369 ;
int V_141 ;
T_4 V_511 = F_275 ( & V_10 -> V_9 ) ;
V_141 = F_269 ( V_10 ) ;
if ( F_281 ( & V_10 -> V_9 ) )
return V_141 ;
if ( V_511 <= F_275 ( & V_10 -> V_9 ) )
return V_141 ;
V_368 -> V_375 = V_512 ;
return 0 ;
}
static T_2 F_282 ( struct V_8 * V_9 , T_2 V_513 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_187 + V_513 ;
}
static int F_283 ( struct V_8 * V_9 , struct V_514 * V_515 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_515 -> V_145 ) {
case V_516 : {
V_515 -> V_517 = V_10 -> V_1 -> V_2 . V_187 +
F_284 ( V_9 , F_285 () ) ;
break;
}
case V_518 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_461 ;
break;
#ifdef F_26
case V_519 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_462 ;
break;
case V_520 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_463 ;
break;
case V_297 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_460 ;
break;
case V_521 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_464 ;
break;
#endif
case V_522 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_465 ;
break;
case V_523 :
V_515 -> V_517 = V_10 -> V_467 ;
break;
case V_524 :
V_515 -> V_517 = V_10 -> V_466 ;
break;
case V_293 :
if ( ! F_85 ( V_292 ) )
return 1 ;
V_515 -> V_517 = V_10 -> V_294 ;
break;
case V_525 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_526 ;
break;
case V_159 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_527 ;
break;
case V_160 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_528 ;
break;
case V_161 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_529 ;
break;
case V_162 :
V_515 -> V_517 = V_10 -> V_1 -> V_58 . V_530 ;
break;
case V_132 :
V_515 -> V_517 = V_10 -> V_17 . V_531 ;
break;
case V_532 :
V_515 -> V_517 = V_10 -> V_17 . V_533 ;
break;
case V_534 :
V_515 -> V_517 = 0x01000065 ;
break;
case V_535 : {
int V_536 , V_537 ;
V_536 = F_286 ( V_9 ) ;
V_537 = F_287 ( V_9 ) ;
if ( V_536 < 0 || V_537 < 0 )
return F_288 ( V_9 , V_515 ) ;
V_515 -> V_517 = 0 ;
if ( V_536 == 0x15 &&
( V_537 >= 0x2 && V_537 < 0x20 ) )
V_515 -> V_517 = 0x1E ;
}
break;
default:
return F_288 ( V_9 , V_515 ) ;
}
return 0 ;
}
static int F_289 ( struct V_7 * V_10 )
{
T_1 V_538 = F_249 ( & V_10 -> V_9 , V_427 ) ;
struct V_514 V_515 ;
V_515 . V_145 = V_538 ;
V_515 . V_539 = false ;
if ( F_283 ( & V_10 -> V_9 , & V_515 ) ) {
F_290 ( V_538 ) ;
F_207 ( & V_10 -> V_9 , 0 ) ;
} else {
F_291 ( V_538 , V_515 . V_517 ) ;
F_107 ( & V_10 -> V_9 , V_453 ,
V_515 . V_517 & 0xffffffff ) ;
F_107 ( & V_10 -> V_9 , V_269 ,
V_515 . V_517 >> 32 ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_292 ( struct V_8 * V_9 , T_2 V_517 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_540 , V_541 ;
if ( V_517 & ~ V_542 )
return 1 ;
V_541 = V_542 ;
if ( V_10 -> V_17 . V_533 & V_543 )
V_541 &= ~ ( V_544 | V_543 ) ;
V_10 -> V_17 . V_533 &= ~ V_541 ;
V_10 -> V_17 . V_533 |= ( V_517 & V_541 ) ;
V_540 = V_10 -> V_17 . V_533 & V_543 ;
if ( V_540 && ( V_9 -> V_39 . V_54 & V_59 ) )
return 1 ;
return 0 ;
}
static int F_293 ( struct V_8 * V_9 , struct V_514 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_538 = V_42 -> V_145 ;
T_2 V_517 = V_42 -> V_517 ;
switch ( V_538 ) {
case V_516 :
F_294 ( V_9 , V_42 ) ;
break;
case V_518 :
V_10 -> V_1 -> V_58 . V_461 = V_517 ;
break;
#ifdef F_26
case V_519 :
V_10 -> V_1 -> V_58 . V_462 = V_517 ;
break;
case V_520 :
V_10 -> V_1 -> V_58 . V_463 = V_517 ;
break;
case V_297 :
V_10 -> V_1 -> V_58 . V_460 = V_517 ;
break;
case V_521 :
V_10 -> V_1 -> V_58 . V_464 = V_517 ;
break;
#endif
case V_522 :
V_10 -> V_1 -> V_58 . V_465 = V_517 ;
break;
case V_523 :
V_10 -> V_467 = V_517 ;
V_10 -> V_1 -> V_58 . V_467 = V_517 ;
break;
case V_524 :
V_10 -> V_466 = V_517 ;
V_10 -> V_1 -> V_58 . V_466 = V_517 ;
break;
case V_293 :
if ( ! F_85 ( V_292 ) )
return 1 ;
V_10 -> V_294 = V_517 ;
F_50 ( V_293 , V_10 -> V_294 ) ;
break;
case V_525 :
if ( ! F_85 ( V_545 ) ) {
F_295 ( V_9 , L_12 ,
V_76 , V_517 ) ;
break;
}
if ( V_517 & V_546 )
return 1 ;
V_10 -> V_1 -> V_58 . V_526 = V_517 ;
F_3 ( V_10 -> V_1 , V_547 ) ;
if ( V_517 & ( 1ULL << 0 ) )
F_80 ( V_10 ) ;
else
F_81 ( V_10 ) ;
break;
case V_132 :
V_10 -> V_17 . V_531 = V_517 ;
break;
case V_532 :
return F_292 ( V_9 , V_517 ) ;
case V_548 :
F_295 ( V_9 , L_13 , V_538 , V_517 ) ;
break;
default:
return F_296 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_297 ( struct V_7 * V_10 )
{
struct V_514 V_42 ;
T_1 V_538 = F_249 ( & V_10 -> V_9 , V_427 ) ;
T_2 V_517 = F_256 ( & V_10 -> V_9 ) ;
V_42 . V_517 = V_517 ;
V_42 . V_145 = V_538 ;
V_42 . V_539 = false ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
if ( F_298 ( & V_10 -> V_9 , & V_42 ) ) {
F_299 ( V_538 , V_517 ) ;
F_207 ( & V_10 -> V_9 , 0 ) ;
} else {
F_300 ( V_538 , V_517 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_301 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_363 )
return F_297 ( V_10 ) ;
else
return F_289 ( V_10 ) ;
}
static int F_302 ( struct V_7 * V_10 )
{
F_181 ( V_469 , & V_10 -> V_9 ) ;
F_134 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_232 &= ~ V_470 ;
F_3 ( V_10 -> V_1 , V_471 ) ;
++ V_10 -> V_9 . V_295 . V_549 ;
return 1 ;
}
static int F_303 ( struct V_7 * V_10 )
{
F_304 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_305 ( struct V_7 * V_10 )
{
F_31 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_306 ( struct V_7 * V_10 )
{
F_307 ( V_550 L_14 ) ;
return F_305 ( V_10 ) ;
}
static int F_308 ( struct V_7 * V_10 )
{
F_307 ( V_550 L_15 ) ;
return F_305 ( V_10 ) ;
}
static void F_309 ( struct V_8 * V_9 )
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
F_56 ( L_26 , L_32 , V_2 -> V_352 ) ;
F_56 ( L_22 , L_33 , V_2 -> V_232 ) ;
F_56 ( L_22 , L_34 , V_2 -> V_443 ) ;
F_56 ( L_22 , L_35 , V_2 -> V_66 ) ;
F_56 ( L_22 , L_36 , V_2 -> V_402 ) ;
F_56 ( L_24 , L_37 , V_2 -> V_363 ) ;
F_56 ( L_24 , L_38 , V_2 -> V_361 ) ;
F_56 ( L_22 , L_39 , V_2 -> V_444 ) ;
F_56 ( L_22 , L_40 , V_2 -> V_445 ) ;
F_56 ( L_41 , L_42 , V_2 -> V_255 ) ;
F_56 ( L_24 , L_43 , V_2 -> V_396 ) ;
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
V_58 -> V_330 , V_58 -> V_54 ) ;
F_56 ( L_61 ,
L_62 , V_58 -> V_335 , L_63 , V_58 -> V_414 ) ;
F_56 ( L_61 ,
L_64 , V_58 -> V_258 , L_65 , V_58 -> V_253 ) ;
F_56 ( L_61 ,
L_66 , V_58 -> V_247 , L_67 , V_58 -> V_357 ) ;
F_56 ( L_61 ,
L_68 , V_58 -> V_84 , L_69 , V_58 -> V_300 ) ;
F_56 ( L_61 ,
L_70 , V_58 -> V_448 , L_71 , V_58 -> V_449 ) ;
F_56 ( L_61 ,
L_72 , V_58 -> V_461 , L_73 , V_58 -> V_462 ) ;
F_56 ( L_61 ,
L_74 , V_58 -> V_463 , L_75 , V_58 -> V_464 ) ;
F_56 ( L_61 ,
L_76 , V_58 -> V_460 ,
L_77 , V_58 -> V_465 ) ;
F_56 ( L_61 ,
L_78 , V_58 -> V_466 ,
L_79 , V_58 -> V_467 ) ;
F_56 ( L_61 ,
L_80 , V_58 -> V_256 , L_81 , V_58 -> V_526 ) ;
F_56 ( L_61 ,
L_82 , V_58 -> V_527 , L_83 , V_58 -> V_528 ) ;
F_56 ( L_61 ,
L_84 , V_58 -> V_529 ,
L_85 , V_58 -> V_530 ) ;
}
static void F_310 ( struct V_8 * V_9 , T_2 * V_551 , T_2 * V_552 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_551 = V_2 -> V_363 ;
* V_552 = V_2 -> V_361 ;
}
static int F_311 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_368 * V_368 = V_9 -> V_369 ;
T_1 V_402 = V_10 -> V_1 -> V_2 . V_402 ;
F_312 ( V_402 , V_9 , V_447 ) ;
if ( ! F_11 ( V_10 , V_196 ) )
V_9 -> V_39 . V_335 = V_10 -> V_1 -> V_58 . V_335 ;
if ( V_55 )
V_9 -> V_39 . V_258 = V_10 -> V_1 -> V_58 . V_258 ;
if ( F_118 ( V_10 -> V_17 . V_416 ) ) {
F_200 ( V_10 ) ;
V_10 -> V_17 . V_416 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_412 ;
F_313 ( V_10 -> V_1 -> V_58 . V_84 , V_402 ,
V_10 -> V_1 -> V_2 . V_363 ,
V_10 -> V_1 -> V_2 . V_361 ,
V_10 -> V_1 -> V_2 . V_444 ,
V_10 -> V_1 -> V_2 . V_445 ,
V_447 ) ;
V_412 = F_223 ( V_10 ) ;
if ( V_412 == V_429 )
V_412 = F_224 ( V_10 ) ;
if ( V_412 == V_415 )
return 1 ;
}
F_314 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_402 == V_437 ) {
V_368 -> V_375 = V_553 ;
V_368 -> V_554 . V_555
= V_10 -> V_1 -> V_2 . V_402 ;
F_56 ( L_86 ) ;
F_309 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_444 ) &&
V_402 != V_413 + V_200 &&
V_402 != V_403 && V_402 != V_556 &&
V_402 != V_419 && V_402 != V_420 )
F_35 ( V_78 L_87
L_88 ,
V_76 , V_10 -> V_1 -> V_2 . V_444 ,
V_402 ) ;
if ( V_402 >= F_315 ( V_557 )
|| ! V_557 [ V_402 ] ) {
F_316 ( 1 , L_89 , V_402 ) ;
F_170 ( V_9 , V_201 ) ;
return 1 ;
}
return V_557 [ V_402 ] ( V_10 ) ;
}
static void F_317 ( struct V_8 * V_9 )
{
int V_140 = F_54 () ;
struct V_113 * V_114 = F_57 ( V_123 , V_140 ) ;
V_114 -> V_129 -> type = 9 ;
F_318 () ;
}
static void F_319 ( struct V_7 * V_10 )
{
int V_140 = F_54 () ;
struct V_113 * V_114 = F_57 ( V_123 , V_140 ) ;
if ( V_10 -> V_124 != V_114 -> V_124 )
F_154 ( V_10 , V_114 ) ;
}
static void F_320 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_558 ;
V_9 -> V_39 . V_40 |= V_559 ;
F_16 ( V_10 , V_501 ) ;
++ V_9 -> V_295 . V_560 ;
}
static inline void F_321 ( struct V_7 * V_10 , int V_561 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_443 = V_561 ;
V_2 -> V_232 &= ~ V_562 ;
V_2 -> V_232 |= V_470 |
( ( 0xf ) << V_563 ) ;
F_3 ( V_10 -> V_1 , V_471 ) ;
}
static void F_322 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_73 ( ! ( F_20 ( V_10 ) ) ) ;
F_323 ( V_9 -> V_39 . V_564 . V_79 ) ;
++ V_9 -> V_295 . V_565 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_564 . V_79 |
V_63 | V_64 ;
}
static void F_324 ( struct V_8 * V_9 , int V_566 , int V_567 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_417 ) )
return;
F_10 ( V_10 , V_199 ) ;
if ( V_567 == - 1 )
return;
if ( V_566 >= V_567 )
F_9 ( V_10 , V_199 ) ;
}
static void F_325 ( struct V_8 * V_9 , bool V_568 )
{
return;
}
static bool F_326 ( void )
{
return false ;
}
static void F_327 ( struct V_8 * V_9 )
{
}
static void F_328 ( struct V_8 * V_9 , T_2 * V_569 )
{
return;
}
static void F_329 ( struct V_8 * V_9 )
{
return;
}
static int F_330 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
V_65 = ! ( V_1 -> V_2 . V_66 & V_67 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_559 ) ;
V_65 = V_65 && F_20 ( V_10 ) && F_211 ( V_10 ) ;
return V_65 ;
}
static bool F_331 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_559 ) ;
}
static void F_332 ( struct V_8 * V_9 , bool V_570 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_570 ) {
V_10 -> V_9 . V_39 . V_40 |= V_559 ;
F_16 ( V_10 , V_501 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_559 ;
F_17 ( V_10 , V_501 ) ;
}
}
static int F_333 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_66 & V_67 ) )
return 0 ;
V_65 = ! ! ( F_229 ( V_9 ) & V_457 ) ;
if ( F_7 ( V_9 ) )
return V_65 && ! ( V_10 -> V_9 . V_39 . V_40 & V_417 ) ;
return V_65 ;
}
static void F_334 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_209 ( V_10 ) ) {
F_133 ( V_10 ) ;
F_321 ( V_10 , 0x0 ) ;
}
}
static void F_335 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_559 | V_502 ) )
== V_559 )
return;
V_10 -> V_372 = true ;
V_10 -> V_1 -> V_58 . V_300 |= ( V_373 | V_374 ) ;
}
static int F_336 ( struct V_270 * V_270 , unsigned int V_50 )
{
return 0 ;
}
static void F_151 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_33 ( V_571 ) )
V_10 -> V_1 -> V_2 . V_352 = V_572 ;
else
V_10 -> V_124 -- ;
}
static void F_337 ( struct V_8 * V_9 )
{
}
static inline void F_338 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_417 ) )
return;
if ( ! F_11 ( V_10 , V_199 ) ) {
int V_573 = V_10 -> V_1 -> V_2 . V_232 & V_574 ;
F_272 ( V_9 , V_573 ) ;
}
}
static inline void F_339 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_573 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_417 ) )
return;
V_573 = F_275 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_232 &= ~ V_574 ;
V_10 -> V_1 -> V_2 . V_232 |= V_573 & V_574 ;
}
static void F_314 ( struct V_7 * V_10 )
{
T_4 V_575 ;
int type ;
T_1 V_576 = V_10 -> V_1 -> V_2 . V_444 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_502 )
&& F_36 ( & V_10 -> V_9 ) != V_10 -> V_503 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_559 | V_502 ) ;
F_181 ( V_469 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_488 = false ;
F_230 ( & V_10 -> V_9 ) ;
F_231 ( & V_10 -> V_9 ) ;
if ( ! ( V_576 & V_480 ) )
return;
F_181 ( V_469 , & V_10 -> V_9 ) ;
V_575 = V_576 & V_577 ;
type = V_576 & V_476 ;
switch ( type ) {
case V_487 :
V_10 -> V_9 . V_39 . V_488 = true ;
break;
case V_489 :
if ( F_340 ( V_575 ) ) {
if ( V_575 == V_83 && V_89 &&
F_341 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_37 ( & V_10 -> V_9 ,
F_36 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_576 & V_578 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_445 ;
F_342 ( & V_10 -> V_9 , V_575 , V_96 ) ;
} else
F_343 ( & V_10 -> V_9 , V_575 ) ;
break;
case V_491 :
F_344 ( & V_10 -> V_9 , V_575 , false ) ;
break;
default:
break;
}
}
static void F_345 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_444 = V_2 -> V_90 ;
V_2 -> V_445 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_314 ( V_10 ) ;
}
static void F_346 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_449 = V_9 -> V_39 . V_248 [ V_453 ] ;
V_10 -> V_1 -> V_58 . V_448 = V_9 -> V_39 . V_248 [ V_454 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_248 [ V_249 ] ;
if ( F_118 ( V_10 -> V_17 . V_416 ) )
return;
F_319 ( V_10 ) ;
F_339 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_414 = V_9 -> V_39 . V_414 ;
F_22 () ;
F_167 () ;
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
F_317 ( V_9 ) ;
F_165 () ;
V_9 -> V_39 . V_414 = V_10 -> V_1 -> V_58 . V_414 ;
V_9 -> V_39 . V_248 [ V_453 ] = V_10 -> V_1 -> V_58 . V_449 ;
V_9 -> V_39 . V_248 [ V_454 ] = V_10 -> V_1 -> V_58 . V_448 ;
V_9 -> V_39 . V_248 [ V_249 ] = V_10 -> V_1 -> V_58 . V_84 ;
if ( F_118 ( V_10 -> V_1 -> V_2 . V_402 == V_420 ) )
F_347 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_118 ( V_10 -> V_1 -> V_2 . V_402 == V_420 ) )
F_348 ( & V_10 -> V_9 ) ;
F_338 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_352 = V_579 ;
if ( V_10 -> V_1 -> V_2 . V_402 == V_413 + V_200 )
V_10 -> V_362 = F_349 () ;
if ( V_55 ) {
V_9 -> V_39 . V_580 &= ~ ( 1 << V_303 ) ;
V_9 -> V_39 . V_581 &= ~ ( 1 << V_303 ) ;
}
if ( F_118 ( V_10 -> V_1 -> V_2 . V_402 ==
V_413 + V_202 ) )
F_180 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_350 ( struct V_8 * V_9 , unsigned long V_398 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_258 = V_398 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_151 ( V_9 ) ;
}
static void F_351 ( struct V_8 * V_9 , unsigned long V_398 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_396 = V_398 ;
F_3 ( V_10 -> V_1 , V_399 ) ;
V_10 -> V_1 -> V_58 . V_258 = F_132 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_151 ( V_9 ) ;
}
static int F_352 ( void )
{
T_2 V_582 ;
F_55 ( V_532 , V_582 ) ;
if ( V_582 & ( 1 << V_583 ) )
return 1 ;
return 0 ;
}
static void
F_353 ( struct V_8 * V_9 , unsigned char * V_584 )
{
V_584 [ 0 ] = 0x0f ;
V_584 [ 1 ] = 0x01 ;
V_584 [ 2 ] = 0xd9 ;
}
static void F_354 ( void * V_585 )
{
* ( int * ) V_585 = 0 ;
}
static bool F_355 ( void )
{
return false ;
}
static bool F_356 ( void )
{
return true ;
}
static T_2 F_357 ( struct V_8 * V_9 , T_11 V_586 , bool V_587 )
{
return 0 ;
}
static void F_358 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_450 = ! ! F_359 ( & V_10 -> V_9 ) ;
}
static void F_360 ( T_1 V_588 , struct V_589 * V_590 )
{
switch ( V_588 ) {
case 0x80000001 :
if ( V_17 )
V_590 -> V_538 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_590 -> V_264 = 1 ;
V_590 -> V_591 = 8 ;
V_590 -> V_538 = 0 ;
V_590 -> V_592 = 0 ;
if ( F_85 ( V_72 ) )
V_590 -> V_592 |= V_593 ;
if ( V_55 )
V_590 -> V_592 |= V_594 ;
break;
}
}
static int F_361 ( void )
{
return V_595 ;
}
static bool F_362 ( void )
{
return F_85 ( V_292 ) ;
}
static bool F_363 ( void )
{
return false ;
}
static bool F_364 ( void )
{
return false ;
}
static bool F_365 ( void )
{
return false ;
}
static bool F_366 ( void )
{
return true ;
}
static void F_367 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_382 ) ;
F_146 ( V_10 ) ;
}
static int F_368 ( struct V_8 * V_9 ,
struct V_596 * V_61 ,
enum V_597 V_598 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_412 , V_65 = V_599 ;
struct V_600 V_601 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_315 ( V_602 ) )
goto V_276;
V_601 = V_602 [ V_61 -> V_22 ] ;
if ( V_598 != V_601 . V_598 )
goto V_276;
switch ( V_601 . V_402 ) {
case V_432 :
if ( V_61 -> V_22 == V_603 )
V_601 . V_402 += V_61 -> V_604 ;
break;
case V_509 : {
unsigned long V_335 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_605 )
V_601 . V_402 += V_61 -> V_604 ;
if ( V_601 . V_402 != V_509 ||
V_61 -> V_22 == V_606 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_208 ) ) )
break;
V_335 = V_9 -> V_39 . V_335 & ~ V_337 ;
V_97 = V_61 -> V_607 & ~ V_337 ;
if ( V_61 -> V_22 == V_608 ) {
V_335 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_335 & V_452 )
V_97 |= V_452 ;
}
if ( V_335 ^ V_97 )
V_601 . V_402 = V_505 ;
break;
}
case V_434 :
case V_609 :
V_601 . V_402 += V_61 -> V_604 ;
break;
case V_430 :
if ( V_61 -> V_22 == V_610 )
V_1 -> V_2 . V_363 = 1 ;
else
V_1 -> V_2 . V_363 = 0 ;
break;
case V_611 :
if ( V_61 -> V_612 != V_613 )
goto V_276;
case V_431 : {
T_2 V_614 ;
T_1 V_615 ;
if ( V_61 -> V_22 == V_616 ||
V_61 -> V_22 == V_617 ) {
V_614 = ( ( V_61 -> V_607 & 0xffff ) << 16 ) |
V_392 ;
V_615 = V_61 -> V_618 ;
} else {
V_614 = ( V_61 -> V_619 & 0xffff ) << 16 ;
V_615 = V_61 -> V_620 ;
}
if ( V_61 -> V_22 == V_621 ||
V_61 -> V_22 == V_617 )
V_614 |= V_391 ;
if ( V_61 -> V_612 )
V_614 |= V_622 ;
V_615 = F_369 ( V_615 , 4u ) ;
V_614 |= V_615 << V_394 ;
V_614 |= ( T_1 ) V_61 -> V_623 << ( V_624 - 1 ) ;
V_1 -> V_2 . V_363 = V_614 ;
V_1 -> V_2 . V_361 = V_61 -> V_71 ;
break;
}
default:
break;
}
if ( F_33 ( V_72 ) )
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_402 = V_601 . V_402 ;
V_412 = F_224 ( V_10 ) ;
V_65 = ( V_412 == V_415 ) ? V_625
: V_599 ;
V_276:
return V_65 ;
}
static void F_370 ( struct V_8 * V_9 )
{
F_167 () ;
}
static void F_371 ( struct V_8 * V_9 , int V_140 )
{
}
static int T_5 F_372 ( void )
{
return F_373 ( & V_626 , sizeof( struct V_7 ) ,
F_374 ( struct V_7 ) , V_627 ) ;
}
static void T_6 F_375 ( void )
{
F_376 () ;
}
