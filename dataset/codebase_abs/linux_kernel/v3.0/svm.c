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
static inline void F_12 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_20 |= ( 1U << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_13 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_20 &= ~ ( 1U << V_6 ) ;
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
V_10 -> V_9 . V_23 . V_24 |= V_25 ;
}
static inline void F_19 ( struct V_7 * V_10 )
{
V_10 -> V_9 . V_23 . V_24 &= ~ V_25 ;
}
static inline bool F_20 ( struct V_7 * V_10 )
{
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_25 ) ;
}
static T_1 F_21 ( T_1 V_26 )
{
T_1 V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( V_26 < V_30 [ V_28 ] ||
V_26 >= V_30 [ V_28 ] + V_31 )
continue;
V_27 = ( V_26 - V_30 [ V_28 ] ) / 4 ;
V_27 += ( V_28 * V_32 ) ;
return V_27 / 4 ;
}
return V_33 ;
}
static inline void F_22 ( void )
{
asm volatile (__ex(SVM_CLGI));
}
static inline void F_23 ( void )
{
asm volatile (__ex(SVM_STGI));
}
static inline void F_24 ( unsigned long V_34 , T_1 V_35 )
{
asm volatile (__ex(SVM_INVLPGA) : : "a"(addr), "c"(asid));
}
static int F_25 ( void )
{
#ifdef F_26
return V_36 ;
#else
return V_37 ;
#endif
}
static void F_27 ( struct V_8 * V_9 , T_2 V_38 )
{
V_9 -> V_23 . V_38 = V_38 ;
if ( ! V_39 && ! ( V_38 & V_40 ) )
V_38 &= ~ V_41 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_38 = V_38 | V_43 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
}
static int F_28 ( T_1 V_45 )
{
V_45 &= V_46 | V_47 ;
return V_45 == ( V_47 | V_48 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , int V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_50 = 0 ;
if ( V_10 -> V_1 -> V_2 . V_51 & V_52 )
V_50 |= V_53 | V_54 ;
return V_50 & V_49 ;
}
static void F_30 ( struct V_8 * V_9 , int V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_49 == 0 )
V_10 -> V_1 -> V_2 . V_51 &= ~ V_52 ;
else
V_10 -> V_1 -> V_2 . V_51 |= V_52 ;
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_55 != 0 )
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_55 ;
if ( ! V_10 -> V_55 ) {
if ( F_32 ( V_9 , V_56 ) !=
V_57 )
F_33 ( V_58 L_1 , V_59 ) ;
return;
}
if ( V_10 -> V_55 - F_34 ( V_9 ) > V_60 )
F_33 ( V_61 L_2 ,
V_59 , F_34 ( V_9 ) , V_10 -> V_55 ) ;
F_35 ( V_9 , V_10 -> V_55 ) ;
F_30 ( V_9 , 0 ) ;
}
static void F_36 ( struct V_8 * V_9 , unsigned V_62 ,
bool V_63 , T_1 V_64 ,
bool V_65 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! V_65 &&
F_37 ( V_10 , V_62 , V_63 , V_64 ) )
return;
if ( V_62 == V_66 && ! F_38 ( V_67 ) ) {
unsigned long V_68 , V_69 = F_34 ( & V_10 -> V_9 ) ;
F_31 ( & V_10 -> V_9 ) ;
V_68 = F_34 ( & V_10 -> V_9 ) ;
V_10 -> V_70 = V_68 + V_10 -> V_1 -> V_42 . V_71 . V_72 ;
V_10 -> V_73 = V_68 - V_69 ;
}
V_10 -> V_1 -> V_2 . V_74 = V_62
| V_47
| ( V_63 ? V_75 : 0 )
| V_76 ;
V_10 -> V_1 -> V_2 . V_77 = V_64 ;
}
static void F_39 ( void )
{
T_1 V_78 , V_79 ;
int V_80 ;
T_2 V_81 ;
if ( ! F_40 ( V_82 ) )
return;
V_81 = F_41 ( V_83 , & V_80 ) ;
if ( V_80 )
return;
V_81 |= ( 1ULL << 47 ) ;
V_78 = F_42 ( V_81 ) ;
V_79 = F_43 ( V_81 ) ;
F_44 ( V_83 , V_78 , V_79 ) ;
V_84 = true ;
}
static int F_45 ( void )
{
const char * V_85 ;
if ( ! F_46 ( & V_85 ) ) {
F_33 ( V_86 L_3 , V_85 ) ;
return 0 ;
}
return 1 ;
}
static void F_47 ( void * V_87 )
{
if ( F_38 ( V_88 ) )
F_48 ( V_89 , V_90 ) ;
F_49 () ;
}
static int F_50 ( void * V_87 )
{
struct V_91 * V_92 ;
T_3 V_38 ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
int V_97 = F_51 () ;
F_52 ( V_98 , V_38 ) ;
if ( V_38 & V_43 )
return - V_99 ;
if ( ! F_45 () ) {
F_33 ( V_61 L_4 ,
V_97 ) ;
return - V_100 ;
}
V_92 = F_53 ( V_101 , V_97 ) ;
if ( ! V_92 ) {
F_33 ( V_61 L_5 ,
V_97 ) ;
return - V_100 ;
}
V_92 -> V_102 = 1 ;
V_92 -> V_103 = F_54 ( V_104 ) - 1 ;
V_92 -> V_105 = V_92 -> V_103 + 1 ;
F_55 ( & V_94 ) ;
V_96 = (struct V_95 * ) V_94 . V_106 ;
V_92 -> V_107 = (struct V_108 * ) ( V_96 + V_109 ) ;
F_48 ( V_98 , V_38 | V_43 ) ;
F_48 ( V_110 , F_56 ( V_92 -> V_111 ) << V_112 ) ;
if ( F_38 ( V_88 ) ) {
F_48 ( V_89 , V_90 ) ;
F_57 ( V_113 ) = V_90 ;
}
F_39 () ;
return 0 ;
}
static void F_58 ( int V_114 )
{
struct V_91 * V_92 = F_53 ( V_101 , F_51 () ) ;
if ( ! V_92 )
return;
F_53 ( V_101 , F_51 () ) = NULL ;
F_59 ( V_92 -> V_111 ) ;
F_60 ( V_92 ) ;
}
static int F_61 ( int V_114 )
{
struct V_91 * V_92 ;
int V_115 ;
V_92 = F_62 ( sizeof( struct V_91 ) , V_116 ) ;
if ( ! V_92 )
return - V_117 ;
V_92 -> V_114 = V_114 ;
V_92 -> V_111 = F_63 ( V_116 ) ;
V_115 = - V_117 ;
if ( ! V_92 -> V_111 )
goto V_118;
F_53 ( V_101 , V_114 ) = V_92 ;
return 0 ;
V_118:
F_60 ( V_92 ) ;
return V_115 ;
}
static bool F_64 ( T_1 V_119 )
{
int V_28 ;
for ( V_28 = 0 ; V_120 [ V_28 ] . V_119 != V_33 ; V_28 ++ )
if ( V_120 [ V_28 ] . V_119 == V_119 )
return true ;
return false ;
}
static void F_65 ( T_1 * V_121 , unsigned V_26 ,
int V_122 , int V_123 )
{
T_4 V_124 , V_125 ;
unsigned long V_126 ;
T_1 V_27 ;
F_66 ( ! F_64 ( V_26 ) ) ;
V_27 = F_21 ( V_26 ) ;
V_124 = 2 * ( V_26 & 0x0f ) ;
V_125 = 2 * ( V_26 & 0x0f ) + 1 ;
V_126 = V_121 [ V_27 ] ;
F_67 ( V_27 == V_33 ) ;
V_122 ? F_68 ( V_124 , & V_126 ) : F_69 ( V_124 , & V_126 ) ;
V_123 ? F_68 ( V_125 , & V_126 ) : F_69 ( V_125 , & V_126 ) ;
V_121 [ V_27 ] = V_126 ;
}
static void F_70 ( T_1 * V_121 )
{
int V_28 ;
memset ( V_121 , 0xff , V_127 * ( 1 << V_128 ) ) ;
for ( V_28 = 0 ; V_120 [ V_28 ] . V_119 != V_33 ; V_28 ++ ) {
if ( ! V_120 [ V_28 ] . V_129 )
continue;
F_65 ( V_121 , V_120 [ V_28 ] . V_119 , 1 , 1 ) ;
}
}
static void F_71 ( T_1 V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_130 ; ++ V_28 ) {
if ( V_131 [ V_28 ] == V_27 )
return;
if ( V_131 [ V_28 ] != V_33 )
continue;
V_131 [ V_28 ] = V_27 ;
return;
}
F_72 () ;
}
static void F_73 ( void )
{
int V_28 ;
memset ( V_131 , 0xff , sizeof( V_131 ) ) ;
for ( V_28 = 0 ; V_120 [ V_28 ] . V_119 != V_33 ; V_28 ++ ) {
T_1 V_27 ;
V_27 = F_21 ( V_120 [ V_28 ] . V_119 ) ;
F_67 ( V_27 == V_33 ) ;
F_71 ( V_27 ) ;
}
}
static void F_74 ( struct V_7 * V_10 )
{
T_1 * V_121 = V_10 -> V_121 ;
V_10 -> V_1 -> V_2 . V_132 = 1 ;
F_65 ( V_121 , V_133 , 1 , 1 ) ;
F_65 ( V_121 , V_134 , 1 , 1 ) ;
F_65 ( V_121 , V_135 , 1 , 1 ) ;
F_65 ( V_121 , V_136 , 1 , 1 ) ;
}
static void F_75 ( struct V_7 * V_10 )
{
T_1 * V_121 = V_10 -> V_121 ;
V_10 -> V_1 -> V_2 . V_132 = 0 ;
F_65 ( V_121 , V_133 , 0 , 0 ) ;
F_65 ( V_121 , V_134 , 0 , 0 ) ;
F_65 ( V_121 , V_135 , 0 , 0 ) ;
F_65 ( V_121 , V_136 , 0 , 0 ) ;
}
static T_5 int F_76 ( void )
{
int V_114 ;
struct V_137 * V_138 ;
void * V_139 ;
int V_115 ;
V_138 = F_77 ( V_116 , V_140 ) ;
if ( ! V_138 )
return - V_117 ;
V_139 = F_78 ( V_138 ) ;
memset ( V_139 , 0xff , V_127 * ( 1 << V_140 ) ) ;
V_141 = F_56 ( V_138 ) << V_112 ;
F_73 () ;
if ( F_79 ( V_142 ) )
F_80 ( V_143 ) ;
if ( F_79 ( V_144 ) )
F_80 ( V_145 ) ;
if ( F_79 ( V_88 ) ) {
T_2 V_146 ;
V_147 = true ;
V_146 = F_81 ( 0x7fffffffULL , F_82 ( V_148 , V_149 ) ) ;
V_150 = V_146 ;
}
if ( V_17 ) {
F_33 ( V_86 L_6 ) ;
F_80 ( V_43 | V_151 ) ;
}
F_83 (cpu) {
V_115 = F_61 ( V_114 ) ;
if ( V_115 )
goto V_80;
}
if ( ! F_79 ( V_152 ) )
V_39 = false ;
if ( V_39 && ! V_153 ) {
F_33 ( V_86 L_7 ) ;
V_39 = false ;
}
if ( V_39 ) {
F_33 ( V_86 L_8 ) ;
F_84 () ;
} else
F_85 () ;
return 0 ;
V_80:
F_86 ( V_138 , V_140 ) ;
V_141 = 0 ;
return V_115 ;
}
static T_6 void F_87 ( void )
{
int V_114 ;
F_83 (cpu)
F_58 ( V_114 ) ;
F_86 ( F_88 ( V_141 >> V_112 ) , V_140 ) ;
V_141 = 0 ;
}
static void F_89 ( struct V_154 * V_155 )
{
V_155 -> V_156 = 0 ;
V_155 -> V_157 = V_158 | V_159 |
V_160 ;
V_155 -> V_161 = 0xffff ;
V_155 -> V_72 = 0 ;
}
static void F_90 ( struct V_154 * V_155 , T_7 type )
{
V_155 -> V_156 = 0 ;
V_155 -> V_157 = V_158 | type ;
V_155 -> V_161 = 0xffff ;
V_155 -> V_72 = 0 ;
}
static T_2 F_82 ( T_2 V_162 , T_2 V_163 )
{
T_2 V_164 , V_165 , V_166 ;
V_164 = V_162 >> 32 ;
V_165 = V_162 & ( ( 1ULL << 32 ) - 1 ) ;
V_166 = V_163 ;
V_166 *= V_164 ;
V_166 += ( V_163 >> 32 ) * V_165 ;
V_166 += ( ( V_163 & ( ( 1ULL << 32 ) - 1 ) ) * V_165 ) >> 32 ;
return V_166 ;
}
static T_2 F_91 ( struct V_8 * V_9 , T_2 V_163 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_166 = V_163 ;
if ( V_10 -> V_167 != V_90 )
V_166 = F_82 ( V_10 -> V_167 , V_163 ) ;
return V_166 ;
}
static void F_92 ( struct V_8 * V_9 , T_1 V_168 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_162 ;
T_2 V_169 ;
if ( ! F_79 ( V_88 ) )
return;
if ( V_168 == 0 ) {
V_9 -> V_23 . V_170 = 0 ;
V_10 -> V_167 = V_90 ;
return;
}
V_169 = V_168 ;
V_162 = V_169 << 32 ;
F_93 ( V_162 , V_148 ) ;
if ( V_162 == 0 || V_162 & V_171 ) {
F_94 ( 1 , L_9 ,
V_168 ) ;
return;
}
V_9 -> V_23 . V_170 = V_168 ;
V_10 -> V_167 = V_162 ;
}
static void F_95 ( struct V_8 * V_9 , T_2 V_27 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_172 = 0 ;
if ( F_7 ( V_9 ) ) {
V_172 = V_10 -> V_1 -> V_2 . V_173 -
V_10 -> V_17 . V_18 -> V_2 . V_173 ;
V_10 -> V_17 . V_18 -> V_2 . V_173 = V_27 ;
}
V_10 -> V_1 -> V_2 . V_173 = V_27 + V_172 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_96 ( struct V_8 * V_9 , T_8 V_174 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_173 += V_174 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_173 += V_174 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_97 ( struct V_8 * V_9 , T_2 V_175 )
{
T_2 V_163 ;
V_163 = F_91 ( V_9 , F_98 () ) ;
return V_175 - V_163 ;
}
static void F_99 ( struct V_7 * V_10 )
{
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_176 * V_42 = & V_10 -> V_1 -> V_42 ;
V_10 -> V_9 . V_177 = 1 ;
V_10 -> V_9 . V_23 . V_24 = 0 ;
F_9 ( V_10 , V_178 ) ;
F_9 ( V_10 , V_179 ) ;
F_9 ( V_10 , V_180 ) ;
F_9 ( V_10 , V_181 ) ;
F_9 ( V_10 , V_182 ) ;
F_9 ( V_10 , V_183 ) ;
F_9 ( V_10 , V_184 ) ;
F_12 ( V_10 , V_185 ) ;
F_12 ( V_10 , V_186 ) ;
F_12 ( V_10 , V_187 ) ;
F_12 ( V_10 , V_188 ) ;
F_12 ( V_10 , V_189 ) ;
F_12 ( V_10 , V_190 ) ;
F_12 ( V_10 , V_191 ) ;
F_12 ( V_10 , V_192 ) ;
F_12 ( V_10 , V_193 ) ;
F_12 ( V_10 , V_194 ) ;
F_12 ( V_10 , V_195 ) ;
F_12 ( V_10 , V_196 ) ;
F_12 ( V_10 , V_197 ) ;
F_12 ( V_10 , V_198 ) ;
F_12 ( V_10 , V_199 ) ;
F_12 ( V_10 , V_200 ) ;
F_14 ( V_10 , V_201 ) ;
F_14 ( V_10 , V_202 ) ;
F_14 ( V_10 , V_203 ) ;
F_16 ( V_10 , V_204 ) ;
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
V_2 -> V_228 = V_141 ;
V_2 -> V_229 = F_100 ( V_10 -> V_121 ) ;
V_2 -> V_230 = V_231 ;
F_89 ( & V_42 -> V_232 ) ;
F_89 ( & V_42 -> V_233 ) ;
F_89 ( & V_42 -> V_234 ) ;
F_89 ( & V_42 -> V_235 ) ;
F_89 ( & V_42 -> V_236 ) ;
V_42 -> V_71 . V_156 = 0xf000 ;
V_42 -> V_71 . V_157 = V_237 | V_158 |
V_159 | V_238 ;
V_42 -> V_71 . V_161 = 0xffff ;
V_42 -> V_71 . V_72 = 0xf0000 ;
V_42 -> V_239 . V_161 = 0xffff ;
V_42 -> V_240 . V_161 = 0xffff ;
F_90 ( & V_42 -> V_241 , V_242 ) ;
F_90 ( & V_42 -> V_243 , V_244 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_42 -> V_245 = 0xffff0ff0 ;
V_42 -> V_246 = 0x400 ;
F_101 ( & V_10 -> V_9 , 2 ) ;
V_42 -> V_68 = 0x0000fff0 ;
V_10 -> V_9 . V_23 . V_247 [ V_248 ] = V_42 -> V_68 ;
V_10 -> V_9 . V_23 . V_249 = 0 ;
( void ) F_102 ( & V_10 -> V_9 , V_250 | V_251 | V_252 ) ;
V_42 -> V_253 = V_254 ;
if ( V_39 ) {
V_2 -> V_255 = 1 ;
F_17 ( V_10 , V_215 ) ;
F_17 ( V_10 , V_211 ) ;
F_15 ( V_10 , V_201 ) ;
F_10 ( V_10 , V_179 ) ;
F_10 ( V_10 , V_182 ) ;
V_42 -> V_256 = 0x0007040600070406ULL ;
V_42 -> V_257 = 0 ;
V_42 -> V_253 = 0 ;
}
V_10 -> V_102 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_23 . V_24 = 0 ;
if ( F_79 ( V_258 ) ) {
V_2 -> V_259 = 3000 ;
F_16 ( V_10 , V_260 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static int F_103 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_99 ( V_10 ) ;
if ( ! F_104 ( V_9 ) ) {
F_35 ( V_9 , 0 ) ;
V_10 -> V_1 -> V_42 . V_71 . V_72 = V_10 -> V_9 . V_23 . V_261 << 12 ;
V_10 -> V_1 -> V_42 . V_71 . V_156 = V_10 -> V_9 . V_23 . V_261 << 8 ;
}
V_9 -> V_23 . V_262 = ~ 0 ;
V_9 -> V_23 . V_263 = ~ 0 ;
return 0 ;
}
static struct V_8 * F_105 ( struct V_264 * V_264 , unsigned int V_265 )
{
struct V_7 * V_10 ;
struct V_137 * V_137 ;
struct V_137 * V_266 ;
struct V_137 * V_267 ;
struct V_137 * V_268 ;
int V_80 ;
V_10 = F_106 ( V_269 , V_116 ) ;
if ( ! V_10 ) {
V_80 = - V_117 ;
goto V_270;
}
V_10 -> V_167 = V_90 ;
V_80 = F_107 ( & V_10 -> V_9 , V_264 , V_265 ) ;
if ( V_80 )
goto V_271;
V_80 = - V_117 ;
V_137 = F_63 ( V_116 ) ;
if ( ! V_137 )
goto V_272;
V_266 = F_77 ( V_116 , V_128 ) ;
if ( ! V_266 )
goto V_273;
V_268 = F_77 ( V_116 , V_128 ) ;
if ( ! V_268 )
goto V_274;
V_267 = F_63 ( V_116 ) ;
if ( ! V_267 )
goto V_275;
V_10 -> V_17 . V_18 = F_78 ( V_267 ) ;
V_10 -> V_121 = F_78 ( V_266 ) ;
F_70 ( V_10 -> V_121 ) ;
V_10 -> V_17 . V_121 = F_78 ( V_268 ) ;
F_70 ( V_10 -> V_17 . V_121 ) ;
V_10 -> V_1 = F_78 ( V_137 ) ;
F_108 ( V_10 -> V_1 ) ;
V_10 -> V_276 = F_56 ( V_137 ) << V_112 ;
V_10 -> V_102 = 0 ;
F_99 ( V_10 ) ;
F_109 ( & V_10 -> V_9 , 0 ) ;
V_80 = F_110 ( & V_10 -> V_9 ) ;
if ( V_80 )
goto V_277;
V_10 -> V_9 . V_23 . V_278 = 0xfee00000 | V_279 ;
if ( F_104 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_23 . V_278 |= V_280 ;
return & V_10 -> V_9 ;
V_277:
F_59 ( V_267 ) ;
V_275:
F_86 ( V_268 , V_128 ) ;
V_274:
F_86 ( V_266 , V_128 ) ;
V_273:
F_59 ( V_137 ) ;
V_272:
F_111 ( & V_10 -> V_9 ) ;
V_271:
F_112 ( V_269 , V_10 ) ;
V_270:
return F_113 ( V_80 ) ;
}
static void F_114 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_59 ( F_88 ( V_10 -> V_276 >> V_112 ) ) ;
F_86 ( F_115 ( V_10 -> V_121 ) , V_128 ) ;
F_59 ( F_115 ( V_10 -> V_17 . V_18 ) ) ;
F_86 ( F_115 ( V_10 -> V_17 . V_121 ) , V_128 ) ;
F_111 ( V_9 ) ;
F_112 ( V_269 , V_10 ) ;
}
static void F_116 ( struct V_8 * V_9 , int V_114 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
if ( F_117 ( V_114 != V_9 -> V_114 ) ) {
V_10 -> V_102 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_52 ( V_281 , F_4 ( V_9 ) -> V_282 . V_283 ) ;
#endif
F_118 ( V_235 , V_10 -> V_282 . V_235 ) ;
F_118 ( V_236 , V_10 -> V_282 . V_236 ) ;
V_10 -> V_282 . V_284 = F_119 () ;
for ( V_28 = 0 ; V_28 < V_285 ; V_28 ++ )
F_52 ( V_286 [ V_28 ] , V_10 -> V_287 [ V_28 ] ) ;
if ( F_38 ( V_88 ) &&
V_10 -> V_167 != F_57 ( V_113 ) ) {
F_57 ( V_113 ) = V_10 -> V_167 ;
F_48 ( V_89 , V_10 -> V_167 ) ;
}
}
static void F_120 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
++ V_9 -> V_288 . V_289 ;
F_121 ( V_10 -> V_282 . V_284 ) ;
#ifdef F_26
F_122 ( V_235 , V_10 -> V_282 . V_235 ) ;
F_48 ( V_290 , V_291 -> V_292 . V_236 ) ;
F_123 ( V_10 -> V_282 . V_236 ) ;
#else
#ifdef F_124
F_122 ( V_236 , V_10 -> V_282 . V_236 ) ;
#endif
#endif
for ( V_28 = 0 ; V_28 < V_285 ; V_28 ++ )
F_48 ( V_286 [ V_28 ] , V_10 -> V_287 [ V_28 ] ) ;
}
static unsigned long F_125 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_42 . V_293 ;
}
static void F_126 ( struct V_8 * V_9 , unsigned long V_293 )
{
F_4 ( V_9 ) -> V_1 -> V_42 . V_293 = V_293 ;
}
static void F_127 ( struct V_8 * V_9 , enum V_294 V_295 )
{
switch ( V_295 ) {
case V_296 :
F_67 ( ! V_39 ) ;
F_128 ( V_9 , V_9 -> V_23 . V_297 , F_129 ( V_9 ) ) ;
break;
default:
F_72 () ;
}
}
static void F_130 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_298 ) ;
}
static void F_131 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_298 ) ;
}
static struct V_154 * F_132 ( struct V_8 * V_9 , int V_155 )
{
struct V_176 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
switch ( V_155 ) {
case V_299 : return & V_42 -> V_71 ;
case V_300 : return & V_42 -> V_234 ;
case V_301 : return & V_42 -> V_232 ;
case V_302 : return & V_42 -> V_235 ;
case V_303 : return & V_42 -> V_236 ;
case V_304 : return & V_42 -> V_233 ;
case V_305 : return & V_42 -> V_243 ;
case V_306 : return & V_42 -> V_241 ;
}
F_72 () ;
return NULL ;
}
static T_2 F_133 ( struct V_8 * V_9 , int V_155 )
{
struct V_154 * V_307 = F_132 ( V_9 , V_155 ) ;
return V_307 -> V_72 ;
}
static void F_134 ( struct V_8 * V_9 ,
struct V_308 * V_309 , int V_155 )
{
struct V_154 * V_307 = F_132 ( V_9 , V_155 ) ;
V_309 -> V_72 = V_307 -> V_72 ;
V_309 -> V_161 = V_307 -> V_161 ;
V_309 -> V_156 = V_307 -> V_156 ;
V_309 -> type = V_307 -> V_157 & V_310 ;
V_309 -> V_307 = ( V_307 -> V_157 >> V_311 ) & 1 ;
V_309 -> V_312 = ( V_307 -> V_157 >> V_313 ) & 3 ;
V_309 -> V_314 = ( V_307 -> V_157 >> V_315 ) & 1 ;
V_309 -> V_316 = ( V_307 -> V_157 >> V_317 ) & 1 ;
V_309 -> V_318 = ( V_307 -> V_157 >> V_319 ) & 1 ;
V_309 -> V_320 = ( V_307 -> V_157 >> V_321 ) & 1 ;
V_309 -> V_15 = ( V_307 -> V_157 >> V_322 ) & 1 ;
V_309 -> V_323 = ! V_309 -> V_314 || ( V_309 -> type == 0 ) ;
switch ( V_155 ) {
case V_299 :
V_309 -> V_15 = V_307 -> V_161 > 0xfffff ;
break;
case V_305 :
V_309 -> type |= 0x2 ;
break;
case V_300 :
case V_301 :
case V_302 :
case V_303 :
if ( ! V_309 -> V_323 )
V_309 -> type |= 0x1 ;
break;
case V_304 :
if ( V_309 -> V_323 )
V_309 -> V_320 = 0 ;
break;
}
}
static int F_135 ( struct V_8 * V_9 )
{
struct V_176 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
return V_42 -> V_324 ;
}
static void F_136 ( struct V_8 * V_9 , struct V_93 * V_325 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_325 -> V_326 = V_10 -> V_1 -> V_42 . V_240 . V_161 ;
V_325 -> V_106 = V_10 -> V_1 -> V_42 . V_240 . V_72 ;
}
static void F_137 ( struct V_8 * V_9 , struct V_93 * V_325 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_240 . V_161 = V_325 -> V_326 ;
V_10 -> V_1 -> V_42 . V_240 . V_72 = V_325 -> V_106 ;
F_3 ( V_10 -> V_1 , V_327 ) ;
}
static void F_138 ( struct V_8 * V_9 , struct V_93 * V_325 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_325 -> V_326 = V_10 -> V_1 -> V_42 . V_239 . V_161 ;
V_325 -> V_106 = V_10 -> V_1 -> V_42 . V_239 . V_72 ;
}
static void F_139 ( struct V_8 * V_9 , struct V_93 * V_325 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_239 . V_161 = V_325 -> V_326 ;
V_10 -> V_1 -> V_42 . V_239 . V_72 = V_325 -> V_106 ;
F_3 ( V_10 -> V_1 , V_327 ) ;
}
static void F_140 ( struct V_8 * V_9 )
{
}
static void F_141 ( struct V_8 * V_9 )
{
}
static void F_142 ( struct V_8 * V_9 )
{
}
static void F_143 ( struct V_7 * V_10 )
{
T_9 V_328 = V_10 -> V_9 . V_23 . V_249 ;
T_2 * V_329 = & V_10 -> V_1 -> V_42 . V_249 ;
if ( ! V_10 -> V_9 . V_177 )
* V_329 |= V_330 ;
else
* V_329 = ( * V_329 & ~ V_330 )
| ( V_328 & V_330 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
if ( V_328 == * V_329 && V_10 -> V_9 . V_177 ) {
F_10 ( V_10 , V_178 ) ;
F_10 ( V_10 , V_181 ) ;
} else {
F_9 ( V_10 , V_178 ) ;
F_9 ( V_10 , V_181 ) ;
}
}
static void F_144 ( struct V_8 * V_9 , unsigned long V_249 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_23 . V_38 & V_41 ) {
if ( ! F_145 ( V_9 ) && ( V_249 & V_331 ) ) {
V_9 -> V_23 . V_38 |= V_40 ;
V_10 -> V_1 -> V_42 . V_38 |= V_40 | V_41 ;
}
if ( F_145 ( V_9 ) && ! ( V_249 & V_331 ) ) {
V_9 -> V_23 . V_38 &= ~ V_40 ;
V_10 -> V_1 -> V_42 . V_38 &= ~ ( V_40 | V_41 ) ;
}
}
#endif
V_9 -> V_23 . V_249 = V_249 ;
if ( ! V_39 )
V_249 |= V_331 | V_332 ;
if ( ! V_9 -> V_177 )
V_249 |= V_333 ;
V_249 &= ~ ( V_251 | V_250 ) ;
V_10 -> V_1 -> V_42 . V_249 = V_249 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_143 ( V_10 ) ;
}
static void F_146 ( struct V_8 * V_9 , unsigned long V_253 )
{
unsigned long V_334 = F_147 () & V_335 ;
unsigned long V_336 = F_4 ( V_9 ) -> V_1 -> V_42 . V_253 ;
if ( V_39 && ( ( V_336 ^ V_253 ) & V_337 ) )
F_148 ( V_9 ) ;
V_9 -> V_23 . V_253 = V_253 ;
if ( ! V_39 )
V_253 |= V_254 ;
V_253 |= V_334 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_253 = V_253 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
}
static void F_149 ( struct V_8 * V_9 ,
struct V_308 * V_309 , int V_155 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_154 * V_307 = F_132 ( V_9 , V_155 ) ;
V_307 -> V_72 = V_309 -> V_72 ;
V_307 -> V_161 = V_309 -> V_161 ;
V_307 -> V_156 = V_309 -> V_156 ;
if ( V_309 -> V_323 )
V_307 -> V_157 = 0 ;
else {
V_307 -> V_157 = ( V_309 -> type & V_310 ) ;
V_307 -> V_157 |= ( V_309 -> V_307 & 1 ) << V_311 ;
V_307 -> V_157 |= ( V_309 -> V_312 & 3 ) << V_313 ;
V_307 -> V_157 |= ( V_309 -> V_314 & 1 ) << V_315 ;
V_307 -> V_157 |= ( V_309 -> V_316 & 1 ) << V_317 ;
V_307 -> V_157 |= ( V_309 -> V_318 & 1 ) << V_319 ;
V_307 -> V_157 |= ( V_309 -> V_320 & 1 ) << V_321 ;
V_307 -> V_157 |= ( V_309 -> V_15 & 1 ) << V_322 ;
}
if ( V_155 == V_299 )
V_10 -> V_1 -> V_42 . V_324
= ( V_10 -> V_1 -> V_42 . V_71 . V_157
>> V_313 ) & 3 ;
F_3 ( V_10 -> V_1 , V_338 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_339 ) ;
F_15 ( V_10 , V_66 ) ;
if ( V_10 -> V_340 )
F_14 ( V_10 , V_339 ) ;
if ( V_9 -> V_341 & V_342 ) {
if ( V_9 -> V_341 &
( V_343 | V_344 ) )
F_14 ( V_10 , V_339 ) ;
if ( V_9 -> V_341 & V_345 )
F_14 ( V_10 , V_66 ) ;
} else
V_9 -> V_341 = 0 ;
}
static void F_151 ( struct V_8 * V_9 , struct V_346 * V_347 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_9 -> V_341 & V_344 )
V_10 -> V_1 -> V_42 . V_246 = V_347 -> V_23 . V_348 [ 7 ] ;
else
V_10 -> V_1 -> V_42 . V_246 = V_9 -> V_23 . V_246 ;
F_3 ( V_10 -> V_1 , V_349 ) ;
F_150 ( V_9 ) ;
}
static void F_152 ( struct V_7 * V_10 , struct V_91 * V_92 )
{
if ( V_92 -> V_105 > V_92 -> V_103 ) {
++ V_92 -> V_102 ;
V_92 -> V_105 = 1 ;
V_10 -> V_1 -> V_2 . V_350 = V_351 ;
}
V_10 -> V_102 = V_92 -> V_102 ;
V_10 -> V_1 -> V_2 . V_35 = V_92 -> V_105 ++ ;
F_3 ( V_10 -> V_1 , V_352 ) ;
}
static void F_153 ( struct V_8 * V_9 , unsigned long V_353 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_246 = V_353 ;
F_3 ( V_10 -> V_1 , V_349 ) ;
}
static int F_154 ( struct V_7 * V_10 )
{
T_2 V_354 = V_10 -> V_1 -> V_2 . V_355 ;
T_1 V_64 ;
int V_115 = 1 ;
switch ( V_10 -> V_356 ) {
default:
V_64 = V_10 -> V_1 -> V_2 . V_357 ;
F_155 ( V_354 , V_64 ) ;
if ( ! V_39 && F_156 ( & V_10 -> V_9 ) )
F_157 ( & V_10 -> V_9 , V_354 ) ;
V_115 = F_158 ( & V_10 -> V_9 , V_354 , V_64 ,
V_10 -> V_1 -> V_2 . V_358 ,
V_10 -> V_1 -> V_2 . V_359 ) ;
break;
case V_360 :
V_10 -> V_356 = 0 ;
F_159 () ;
F_160 ( V_354 ) ;
F_161 () ;
break;
case V_361 :
V_10 -> V_356 = 0 ;
F_159 () ;
F_162 ( V_354 ) ;
F_161 () ;
break;
}
return V_115 ;
}
static int F_163 ( struct V_7 * V_10 )
{
struct V_362 * V_362 = V_10 -> V_9 . V_363 ;
if ( ! ( V_10 -> V_9 . V_341 &
( V_343 | V_344 ) ) &&
! V_10 -> V_340 ) {
F_164 ( & V_10 -> V_9 , V_339 ) ;
return 1 ;
}
if ( V_10 -> V_340 ) {
V_10 -> V_340 = false ;
if ( ! ( V_10 -> V_9 . V_341 & V_343 ) )
V_10 -> V_1 -> V_42 . V_293 &=
~ ( V_364 | V_365 ) ;
F_150 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_341 &
( V_343 | V_344 ) ) {
V_362 -> V_366 = V_367 ;
V_362 -> V_368 . V_23 . V_369 =
V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_362 -> V_368 . V_23 . V_370 = V_339 ;
return 0 ;
}
return 1 ;
}
static int F_165 ( struct V_7 * V_10 )
{
struct V_362 * V_362 = V_10 -> V_9 . V_363 ;
V_362 -> V_366 = V_367 ;
V_362 -> V_368 . V_23 . V_369 = V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_362 -> V_368 . V_23 . V_370 = V_66 ;
return 0 ;
}
static int F_166 ( struct V_7 * V_10 )
{
int V_371 ;
V_371 = F_32 ( & V_10 -> V_9 , V_372 ) ;
if ( V_371 != V_57 )
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static void F_167 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_373 ) ;
V_10 -> V_9 . V_177 = 1 ;
F_143 ( V_10 ) ;
}
static int F_168 ( struct V_7 * V_10 )
{
F_167 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_169 ( void )
{
int V_80 , V_28 ;
T_2 V_353 ;
if ( ! V_84 )
return false ;
V_353 = F_41 ( V_374 , & V_80 ) ;
if ( V_80 )
return false ;
V_353 &= ~ ( 1ULL << 62 ) ;
if ( V_353 != 0xb600000000010015ULL )
return false ;
for ( V_28 = 0 ; V_28 < 6 ; ++ V_28 )
F_44 ( F_170 ( V_28 ) , 0 , 0 ) ;
V_353 = F_41 ( V_375 , & V_80 ) ;
if ( ! V_80 ) {
T_1 V_78 , V_79 ;
V_353 &= ~ ( 1ULL << 2 ) ;
V_78 = F_42 ( V_353 ) ;
V_79 = F_43 ( V_353 ) ;
F_44 ( V_375 , V_78 , V_79 ) ;
}
F_171 () ;
return true ;
}
static void F_172 ( struct V_7 * V_10 )
{
if ( F_169 () ) {
F_173 ( L_10 ) ;
F_174 ( V_376 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_175 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_176 ( struct V_7 * V_10 )
{
struct V_362 * V_362 = V_10 -> V_9 . V_363 ;
F_108 ( V_10 -> V_1 ) ;
F_99 ( V_10 ) ;
V_362 -> V_366 = V_377 ;
return 0 ;
}
static int F_177 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_378 = V_10 -> V_1 -> V_2 . V_357 ;
int V_326 , V_379 , string ;
unsigned V_380 ;
++ V_10 -> V_9 . V_288 . V_381 ;
string = ( V_378 & V_382 ) != 0 ;
V_379 = ( V_378 & V_383 ) != 0 ;
if ( string || V_379 )
return F_32 ( V_9 , 0 ) == V_57 ;
V_380 = V_378 >> 16 ;
V_326 = ( V_378 & V_384 ) >> V_385 ;
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_355 ;
F_31 ( & V_10 -> V_9 ) ;
return F_178 ( V_9 , V_326 , V_380 ) ;
}
static int F_179 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_180 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_288 . V_386 ;
return 1 ;
}
static int F_181 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_182 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 1 ;
F_31 ( & V_10 -> V_9 ) ;
return F_183 ( & V_10 -> V_9 ) ;
}
static int F_184 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_185 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_186 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_387 ;
}
static void F_187 ( struct V_8 * V_9 ,
unsigned long V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_387 = V_388 ;
F_3 ( V_10 -> V_1 , V_389 ) ;
F_148 ( V_9 ) ;
}
static void F_188 ( struct V_8 * V_9 ,
struct V_390 * V_391 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_392 = V_393 ;
V_10 -> V_1 -> V_2 . V_394 = 0 ;
V_10 -> V_1 -> V_2 . V_357 = V_391 -> V_64 ;
V_10 -> V_1 -> V_2 . V_355 = V_391 -> V_106 ;
F_189 ( V_10 ) ;
}
static int F_190 ( struct V_8 * V_9 )
{
int V_115 ;
V_115 = F_191 ( V_9 , & V_9 -> V_23 . V_395 ) ;
V_9 -> V_23 . V_395 . V_396 = F_187 ;
V_9 -> V_23 . V_395 . V_397 = F_186 ;
V_9 -> V_23 . V_395 . V_398 = F_188 ;
V_9 -> V_23 . V_395 . V_399 = F_25 () ;
V_9 -> V_23 . V_297 = & V_9 -> V_23 . V_400 ;
return V_115 ;
}
static void F_192 ( struct V_8 * V_9 )
{
V_9 -> V_23 . V_297 = & V_9 -> V_23 . V_395 ;
}
static int F_193 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_23 . V_38 & V_43 )
|| ! F_145 ( & V_10 -> V_9 ) ) {
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_42 . V_324 ) {
F_194 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_10 , unsigned V_62 ,
bool V_63 , T_1 V_64 )
{
int V_401 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_392 = V_402 + V_62 ;
V_10 -> V_1 -> V_2 . V_394 = 0 ;
V_10 -> V_1 -> V_2 . V_357 = V_64 ;
V_10 -> V_1 -> V_2 . V_355 = V_10 -> V_9 . V_23 . V_403 ;
V_401 = F_195 ( V_10 ) ;
if ( V_401 == V_404 )
V_10 -> V_17 . V_405 = true ;
return V_401 ;
}
static inline bool F_196 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_406 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_407 ) )
return false ;
if ( V_10 -> V_17 . V_405 )
return false ;
V_10 -> V_1 -> V_2 . V_392 = V_408 ;
V_10 -> V_1 -> V_2 . V_357 = 0 ;
V_10 -> V_1 -> V_2 . V_355 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_405 = true ;
F_197 ( V_10 -> V_1 -> V_42 . V_68 ) ;
return false ;
}
return true ;
}
static inline bool F_198 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_205 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_392 = V_409 ;
V_10 -> V_17 . V_405 = true ;
return false ;
}
static void * F_199 ( struct V_7 * V_10 , T_2 V_410 , struct V_137 * * V_411 )
{
struct V_137 * V_137 ;
F_200 () ;
V_137 = F_201 ( V_10 -> V_9 . V_264 , V_410 >> V_112 ) ;
if ( F_202 ( V_137 ) )
goto error;
* V_411 = V_137 ;
return F_203 ( V_137 ) ;
error:
F_204 ( V_137 ) ;
F_194 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_205 ( struct V_137 * V_137 )
{
F_206 ( V_137 ) ;
F_207 ( V_137 ) ;
}
static int F_208 ( struct V_7 * V_10 )
{
unsigned V_380 ;
T_4 V_81 , V_6 ;
T_2 V_410 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_213 ) ) )
return V_412 ;
V_380 = V_10 -> V_1 -> V_2 . V_357 >> 16 ;
V_410 = V_10 -> V_17 . V_413 + ( V_380 / 8 ) ;
V_6 = V_380 % 8 ;
V_81 = 0 ;
if ( F_209 ( V_10 -> V_9 . V_264 , V_410 , & V_81 , 1 ) )
V_81 &= ( 1 << V_6 ) ;
return V_81 ? V_404 : V_412 ;
}
static int F_210 ( struct V_7 * V_10 )
{
T_1 V_27 , V_26 , V_353 ;
int V_123 , V_49 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_214 ) ) )
return V_412 ;
V_26 = V_10 -> V_9 . V_23 . V_247 [ V_414 ] ;
V_27 = F_21 ( V_26 ) ;
V_123 = V_10 -> V_1 -> V_2 . V_357 & 1 ;
V_49 = 1 << ( ( 2 * ( V_26 & 0xf ) ) + V_123 ) ;
if ( V_27 == V_33 )
return V_404 ;
V_27 *= 4 ;
if ( F_209 ( V_10 -> V_9 . V_264 , V_10 -> V_17 . V_415 + V_27 , & V_353 , 4 ) )
return V_404 ;
return ( V_353 & V_49 ) ? V_404 : V_412 ;
}
static int F_211 ( struct V_7 * V_10 )
{
T_1 V_392 = V_10 -> V_1 -> V_2 . V_392 ;
switch ( V_392 ) {
case V_408 :
case V_409 :
case V_402 + V_203 :
return V_412 ;
case V_393 :
if ( V_39 )
return V_412 ;
break;
case V_402 + V_201 :
if ( ! V_39 && V_10 -> V_356 == 0 )
return V_412 ;
break;
case V_402 + V_373 :
F_168 ( V_10 ) ;
break;
default:
break;
}
return V_416 ;
}
static int F_195 ( struct V_7 * V_10 )
{
T_1 V_392 = V_10 -> V_1 -> V_2 . V_392 ;
int V_401 = V_412 ;
switch ( V_392 ) {
case V_417 :
V_401 = F_210 ( V_10 ) ;
break;
case V_418 :
V_401 = F_208 ( V_10 ) ;
break;
case V_419 ... V_420 : {
T_1 V_6 = 1U << ( V_392 - V_419 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_401 = V_404 ;
break;
}
case V_421 ... V_422 : {
T_1 V_6 = 1U << ( V_392 - V_421 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_401 = V_404 ;
break;
}
case V_402 ... V_402 + 0x1f : {
T_1 V_423 = 1 << ( V_392 - V_402 ) ;
if ( V_10 -> V_17 . V_21 & V_423 )
V_401 = V_404 ;
else if ( ( V_392 == V_402 + V_201 ) &&
V_10 -> V_356 != 0 )
V_401 = V_404 ;
break;
}
case V_424 : {
V_401 = V_404 ;
break;
}
default: {
T_2 V_425 = 1ULL << ( V_392 - V_408 ) ;
if ( V_10 -> V_17 . V_22 & V_425 )
V_401 = V_404 ;
}
}
return V_401 ;
}
static int F_212 ( struct V_7 * V_10 )
{
int V_401 ;
V_401 = F_195 ( V_10 ) ;
if ( V_401 == V_404 )
F_189 ( V_10 ) ;
return V_401 ;
}
static inline void F_213 ( struct V_1 * V_426 , struct V_1 * V_427 )
{
struct V_11 * V_428 = & V_426 -> V_2 ;
struct V_11 * V_429 = & V_427 -> V_2 ;
V_428 -> V_19 = V_429 -> V_19 ;
V_428 -> V_20 = V_429 -> V_20 ;
V_428 -> V_21 = V_429 -> V_21 ;
V_428 -> V_22 = V_429 -> V_22 ;
V_428 -> V_228 = V_429 -> V_228 ;
V_428 -> V_229 = V_429 -> V_229 ;
V_428 -> V_173 = V_429 -> V_173 ;
V_428 -> V_35 = V_429 -> V_35 ;
V_428 -> V_350 = V_429 -> V_350 ;
V_428 -> V_230 = V_429 -> V_230 ;
V_428 -> V_430 = V_429 -> V_430 ;
V_428 -> V_51 = V_429 -> V_51 ;
V_428 -> V_392 = V_429 -> V_392 ;
V_428 -> V_394 = V_429 -> V_394 ;
V_428 -> V_357 = V_429 -> V_357 ;
V_428 -> V_355 = V_429 -> V_355 ;
V_428 -> V_431 = V_429 -> V_431 ;
V_428 -> V_432 = V_429 -> V_432 ;
V_428 -> V_255 = V_429 -> V_255 ;
V_428 -> V_74 = V_429 -> V_74 ;
V_428 -> V_77 = V_429 -> V_77 ;
V_428 -> V_387 = V_429 -> V_387 ;
V_428 -> V_132 = V_429 -> V_132 ;
}
static int F_189 ( struct V_7 * V_10 )
{
struct V_1 * V_433 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_137 * V_137 ;
F_214 ( V_1 -> V_2 . V_392 ,
V_1 -> V_2 . V_357 ,
V_1 -> V_2 . V_355 ,
V_1 -> V_2 . V_431 ,
V_1 -> V_2 . V_432 ) ;
V_433 = F_199 ( V_10 , V_10 -> V_17 . V_1 , & V_137 ) ;
if ( ! V_433 )
return 1 ;
F_215 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_433 -> V_42 . V_232 = V_1 -> V_42 . V_232 ;
V_433 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_433 -> V_42 . V_233 = V_1 -> V_42 . V_233 ;
V_433 -> V_42 . V_234 = V_1 -> V_42 . V_234 ;
V_433 -> V_42 . V_239 = V_1 -> V_42 . V_239 ;
V_433 -> V_42 . V_240 = V_1 -> V_42 . V_240 ;
V_433 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_433 -> V_42 . V_249 = F_216 ( & V_10 -> V_9 ) ;
V_433 -> V_42 . V_257 = F_129 ( & V_10 -> V_9 ) ;
V_433 -> V_42 . V_403 = V_1 -> V_42 . V_403 ;
V_433 -> V_42 . V_253 = V_10 -> V_9 . V_23 . V_253 ;
V_433 -> V_42 . V_293 = F_217 ( & V_10 -> V_9 ) ;
V_433 -> V_42 . V_68 = V_1 -> V_42 . V_68 ;
V_433 -> V_42 . V_434 = V_1 -> V_42 . V_434 ;
V_433 -> V_42 . V_435 = V_1 -> V_42 . V_435 ;
V_433 -> V_42 . V_246 = V_1 -> V_42 . V_246 ;
V_433 -> V_42 . V_245 = V_1 -> V_42 . V_245 ;
V_433 -> V_42 . V_324 = V_1 -> V_42 . V_324 ;
V_433 -> V_2 . V_230 = V_1 -> V_2 . V_230 ;
V_433 -> V_2 . V_430 = V_1 -> V_2 . V_430 ;
V_433 -> V_2 . V_51 = V_1 -> V_2 . V_51 ;
V_433 -> V_2 . V_392 = V_1 -> V_2 . V_392 ;
V_433 -> V_2 . V_394 = V_1 -> V_2 . V_394 ;
V_433 -> V_2 . V_357 = V_1 -> V_2 . V_357 ;
V_433 -> V_2 . V_355 = V_1 -> V_2 . V_355 ;
V_433 -> V_2 . V_431 = V_1 -> V_2 . V_431 ;
V_433 -> V_2 . V_432 = V_1 -> V_2 . V_432 ;
V_433 -> V_2 . V_55 = V_1 -> V_2 . V_55 ;
if ( V_1 -> V_2 . V_74 & V_47 ) {
struct V_11 * V_436 = & V_433 -> V_2 ;
V_436 -> V_431 = V_1 -> V_2 . V_74 ;
V_436 -> V_432 = V_1 -> V_2 . V_77 ;
}
V_433 -> V_2 . V_350 = 0 ;
V_433 -> V_2 . V_74 = 0 ;
V_433 -> V_2 . V_77 = 0 ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_406 ) )
V_433 -> V_2 . V_230 &= ~ V_231 ;
F_213 ( V_1 , V_18 ) ;
F_218 ( & V_10 -> V_9 ) ;
F_219 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_387 = 0 ;
V_10 -> V_1 -> V_42 . V_232 = V_18 -> V_42 . V_232 ;
V_10 -> V_1 -> V_42 . V_71 = V_18 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_233 = V_18 -> V_42 . V_233 ;
V_10 -> V_1 -> V_42 . V_234 = V_18 -> V_42 . V_234 ;
V_10 -> V_1 -> V_42 . V_239 = V_18 -> V_42 . V_239 ;
V_10 -> V_1 -> V_42 . V_240 = V_18 -> V_42 . V_240 ;
F_101 ( & V_10 -> V_9 , V_18 -> V_42 . V_293 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_42 . V_38 ) ;
F_144 ( & V_10 -> V_9 , V_18 -> V_42 . V_249 | V_437 ) ;
F_146 ( & V_10 -> V_9 , V_18 -> V_42 . V_253 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_257 = V_18 -> V_42 . V_257 ;
V_10 -> V_9 . V_23 . V_257 = V_18 -> V_42 . V_257 ;
} else {
( void ) F_220 ( & V_10 -> V_9 , V_18 -> V_42 . V_257 ) ;
}
F_221 ( & V_10 -> V_9 , V_438 , V_18 -> V_42 . V_435 ) ;
F_221 ( & V_10 -> V_9 , V_439 , V_18 -> V_42 . V_434 ) ;
F_221 ( & V_10 -> V_9 , V_248 , V_18 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_246 = 0 ;
V_10 -> V_1 -> V_42 . V_324 = 0 ;
V_10 -> V_1 -> V_2 . V_431 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_205 ( V_137 ) ;
F_192 ( & V_10 -> V_9 ) ;
F_222 ( & V_10 -> V_9 ) ;
F_223 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_224 ( struct V_7 * V_10 )
{
int V_28 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_214 ) ) )
return true ;
for ( V_28 = 0 ; V_28 < V_130 ; V_28 ++ ) {
T_1 V_353 , V_440 ;
T_2 V_27 ;
if ( V_131 [ V_28 ] == 0xffffffff )
break;
V_440 = V_131 [ V_28 ] ;
V_27 = V_10 -> V_17 . V_415 + ( V_440 * 4 ) ;
if ( F_209 ( V_10 -> V_9 . V_264 , V_27 , & V_353 , 4 ) )
return false ;
V_10 -> V_17 . V_121 [ V_440 ] = V_10 -> V_121 [ V_440 ] | V_353 ;
}
V_10 -> V_1 -> V_2 . V_229 = F_100 ( V_10 -> V_17 . V_121 ) ;
return true ;
}
static bool F_225 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_217 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_35 == 0 )
return false ;
if ( V_1 -> V_2 . V_255 && ! V_39 )
return false ;
return true ;
}
static bool F_226 ( struct V_7 * V_10 )
{
struct V_1 * V_433 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_137 * V_137 ;
T_2 V_441 ;
V_441 = V_10 -> V_1 -> V_42 . V_435 ;
V_433 = F_199 ( V_10 , V_10 -> V_1 -> V_42 . V_435 , & V_137 ) ;
if ( ! V_433 )
return false ;
if ( ! F_225 ( V_433 ) ) {
V_433 -> V_2 . V_392 = V_424 ;
V_433 -> V_2 . V_394 = 0 ;
V_433 -> V_2 . V_357 = 0 ;
V_433 -> V_2 . V_355 = 0 ;
F_205 ( V_137 ) ;
return false ;
}
F_227 ( V_10 -> V_1 -> V_42 . V_68 , V_441 ,
V_433 -> V_42 . V_68 ,
V_433 -> V_2 . V_230 ,
V_433 -> V_2 . V_74 ,
V_433 -> V_2 . V_255 ) ;
F_228 ( V_433 -> V_2 . V_19 & 0xffff ,
V_433 -> V_2 . V_19 >> 16 ,
V_433 -> V_2 . V_21 ,
V_433 -> V_2 . V_22 ) ;
F_218 ( & V_10 -> V_9 ) ;
F_219 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_232 = V_1 -> V_42 . V_232 ;
V_18 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_18 -> V_42 . V_233 = V_1 -> V_42 . V_233 ;
V_18 -> V_42 . V_234 = V_1 -> V_42 . V_234 ;
V_18 -> V_42 . V_239 = V_1 -> V_42 . V_239 ;
V_18 -> V_42 . V_240 = V_1 -> V_42 . V_240 ;
V_18 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_18 -> V_42 . V_249 = F_216 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_253 = V_10 -> V_9 . V_23 . V_253 ;
V_18 -> V_42 . V_293 = F_217 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_68 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_434 = V_1 -> V_42 . V_434 ;
V_18 -> V_42 . V_435 = V_1 -> V_42 . V_435 ;
if ( V_39 )
V_18 -> V_42 . V_257 = V_1 -> V_42 . V_257 ;
else
V_18 -> V_42 . V_257 = F_129 ( & V_10 -> V_9 ) ;
F_213 ( V_18 , V_1 ) ;
if ( F_217 ( & V_10 -> V_9 ) & V_442 )
V_10 -> V_9 . V_23 . V_24 |= V_407 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_407 ;
if ( V_433 -> V_2 . V_255 ) {
F_229 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_387 = V_433 -> V_2 . V_387 ;
F_190 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_42 . V_232 = V_433 -> V_42 . V_232 ;
V_10 -> V_1 -> V_42 . V_71 = V_433 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_233 = V_433 -> V_42 . V_233 ;
V_10 -> V_1 -> V_42 . V_234 = V_433 -> V_42 . V_234 ;
V_10 -> V_1 -> V_42 . V_239 = V_433 -> V_42 . V_239 ;
V_10 -> V_1 -> V_42 . V_240 = V_433 -> V_42 . V_240 ;
F_101 ( & V_10 -> V_9 , V_433 -> V_42 . V_293 ) ;
F_27 ( & V_10 -> V_9 , V_433 -> V_42 . V_38 ) ;
F_144 ( & V_10 -> V_9 , V_433 -> V_42 . V_249 ) ;
F_146 ( & V_10 -> V_9 , V_433 -> V_42 . V_253 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_257 = V_433 -> V_42 . V_257 ;
V_10 -> V_9 . V_23 . V_257 = V_433 -> V_42 . V_257 ;
} else
( void ) F_220 ( & V_10 -> V_9 , V_433 -> V_42 . V_257 ) ;
F_222 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_42 . V_403 = V_10 -> V_9 . V_23 . V_403 = V_433 -> V_42 . V_403 ;
F_221 ( & V_10 -> V_9 , V_438 , V_433 -> V_42 . V_435 ) ;
F_221 ( & V_10 -> V_9 , V_439 , V_433 -> V_42 . V_434 ) ;
F_221 ( & V_10 -> V_9 , V_248 , V_433 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_435 = V_433 -> V_42 . V_435 ;
V_10 -> V_1 -> V_42 . V_434 = V_433 -> V_42 . V_434 ;
V_10 -> V_1 -> V_42 . V_68 = V_433 -> V_42 . V_68 ;
V_10 -> V_1 -> V_42 . V_246 = V_433 -> V_42 . V_246 ;
V_10 -> V_1 -> V_42 . V_245 = V_433 -> V_42 . V_245 ;
V_10 -> V_1 -> V_42 . V_324 = V_433 -> V_42 . V_324 ;
V_10 -> V_17 . V_415 = V_433 -> V_2 . V_229 & ~ 0x0fffULL ;
V_10 -> V_17 . V_413 = V_433 -> V_2 . V_228 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_433 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_433 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_433 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_433 -> V_2 . V_22 ;
F_148 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_230 = V_433 -> V_2 . V_230 | V_231 ;
if ( V_433 -> V_2 . V_230 & V_231 )
V_10 -> V_9 . V_23 . V_24 |= V_406 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_406 ;
if ( V_10 -> V_9 . V_23 . V_24 & V_406 ) {
F_10 ( V_10 , V_443 ) ;
F_10 ( V_10 , V_184 ) ;
}
F_17 ( V_10 , V_218 ) ;
V_10 -> V_1 -> V_2 . V_132 = V_433 -> V_2 . V_132 ;
V_10 -> V_1 -> V_2 . V_430 = V_433 -> V_2 . V_430 ;
V_10 -> V_1 -> V_2 . V_51 = V_433 -> V_2 . V_51 ;
V_10 -> V_1 -> V_2 . V_173 += V_433 -> V_2 . V_173 ;
V_10 -> V_1 -> V_2 . V_74 = V_433 -> V_2 . V_74 ;
V_10 -> V_1 -> V_2 . V_77 = V_433 -> V_2 . V_77 ;
F_205 ( V_137 ) ;
F_230 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_441 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_231 ( struct V_1 * V_427 , struct V_1 * V_444 )
{
V_444 -> V_42 . V_235 = V_427 -> V_42 . V_235 ;
V_444 -> V_42 . V_236 = V_427 -> V_42 . V_236 ;
V_444 -> V_42 . V_243 = V_427 -> V_42 . V_243 ;
V_444 -> V_42 . V_241 = V_427 -> V_42 . V_241 ;
V_444 -> V_42 . V_445 = V_427 -> V_42 . V_445 ;
V_444 -> V_42 . V_446 = V_427 -> V_42 . V_446 ;
V_444 -> V_42 . V_447 = V_427 -> V_42 . V_447 ;
V_444 -> V_42 . V_448 = V_427 -> V_42 . V_448 ;
V_444 -> V_42 . V_449 = V_427 -> V_42 . V_449 ;
V_444 -> V_42 . V_450 = V_427 -> V_42 . V_450 ;
V_444 -> V_42 . V_451 = V_427 -> V_42 . V_451 ;
V_444 -> V_42 . V_452 = V_427 -> V_42 . V_452 ;
}
static int F_232 ( struct V_7 * V_10 )
{
struct V_1 * V_433 ;
struct V_137 * V_137 ;
if ( F_193 ( V_10 ) )
return 1 ;
V_433 = F_199 ( V_10 , V_10 -> V_1 -> V_42 . V_435 , & V_137 ) ;
if ( ! V_433 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_231 ( V_433 , V_10 -> V_1 ) ;
F_205 ( V_137 ) ;
return 1 ;
}
static int F_233 ( struct V_7 * V_10 )
{
struct V_1 * V_433 ;
struct V_137 * V_137 ;
if ( F_193 ( V_10 ) )
return 1 ;
V_433 = F_199 ( V_10 , V_10 -> V_1 -> V_42 . V_435 , & V_137 ) ;
if ( ! V_433 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_231 ( V_10 -> V_1 , V_433 ) ;
F_205 ( V_137 ) ;
return 1 ;
}
static int F_234 ( struct V_7 * V_10 )
{
if ( F_193 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_226 ( V_10 ) )
return 1 ;
if ( ! F_224 ( V_10 ) )
goto V_453;
return 1 ;
V_453:
V_10 -> V_1 -> V_2 . V_392 = V_424 ;
V_10 -> V_1 -> V_2 . V_394 = 0 ;
V_10 -> V_1 -> V_2 . V_357 = 0 ;
V_10 -> V_1 -> V_2 . V_355 = 0 ;
F_189 ( V_10 ) ;
return 1 ;
}
static int F_235 ( struct V_7 * V_10 )
{
if ( F_193 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_174 ( V_454 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_236 ( struct V_7 * V_10 )
{
if ( F_193 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_131 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_230 &= ~ V_455 ;
F_3 ( V_10 -> V_1 , V_456 ) ;
return 1 ;
}
static int F_237 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_238 ( V_10 -> V_1 -> V_42 . V_68 , V_9 -> V_23 . V_247 [ V_414 ] ,
V_9 -> V_23 . V_247 [ V_438 ] ) ;
F_239 ( V_9 , V_9 -> V_23 . V_247 [ V_438 ] ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_240 ( struct V_7 * V_10 )
{
F_241 ( V_10 -> V_1 -> V_42 . V_68 , V_10 -> V_9 . V_23 . V_247 [ V_438 ] ) ;
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static int F_242 ( struct V_7 * V_10 )
{
T_2 V_457 = F_243 ( & V_10 -> V_9 ) ;
T_1 V_119 = F_244 ( & V_10 -> V_9 , V_414 ) ;
if ( F_245 ( & V_10 -> V_9 , V_119 , V_457 ) == 0 ) {
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static int F_247 ( struct V_7 * V_10 )
{
T_10 V_458 ;
int V_459 ;
int V_460 = V_10 -> V_1 -> V_2 . V_431 &
V_461 ;
int V_462 = V_10 -> V_1 -> V_2 . V_431 & V_463 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_431 & V_461 ;
T_7 V_464 =
V_10 -> V_1 -> V_2 . V_431 & V_465 ;
bool V_63 = false ;
T_1 V_64 = 0 ;
V_458 = ( T_10 ) V_10 -> V_1 -> V_2 . V_357 ;
if ( V_10 -> V_1 -> V_2 . V_355 &
( 1ULL << V_466 ) )
V_459 = V_467 ;
else if ( V_10 -> V_1 -> V_2 . V_355 &
( 1ULL << V_468 ) )
V_459 = V_469 ;
else if ( V_464 )
V_459 = V_470 ;
else
V_459 = V_471 ;
if ( V_459 == V_470 ) {
switch ( type ) {
case V_472 :
V_10 -> V_9 . V_23 . V_473 = false ;
break;
case V_474 :
if ( V_10 -> V_1 -> V_2 . V_355 &
( 1ULL << V_475 ) ) {
V_63 = true ;
V_64 =
( T_1 ) V_10 -> V_1 -> V_2 . V_355 ;
}
F_218 ( & V_10 -> V_9 ) ;
break;
case V_476 :
F_219 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_459 != V_470 ||
V_460 == V_477 ||
( V_460 == V_474 &&
( V_462 == V_478 || V_462 == V_66 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( F_248 ( & V_10 -> V_9 , V_458 , V_459 ,
V_63 , V_64 ) == V_479 ) {
V_10 -> V_9 . V_363 -> V_366 = V_480 ;
V_10 -> V_9 . V_363 -> V_481 . V_482 = V_483 ;
V_10 -> V_9 . V_363 -> V_481 . V_484 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_249 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_250 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_251 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_288 . V_485 ;
F_17 ( V_10 , V_486 ) ;
V_10 -> V_9 . V_23 . V_24 |= V_487 ;
V_10 -> V_488 = F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_252 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_489 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
F_239 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_357 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_253 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
}
bool F_254 ( struct V_7 * V_10 , unsigned long V_81 )
{
unsigned long V_249 = V_10 -> V_9 . V_23 . V_249 ;
bool V_50 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_207 ) ) ) )
return false ;
V_249 &= ~ V_330 ;
V_81 &= ~ V_330 ;
if ( V_249 ^ V_81 ) {
V_10 -> V_1 -> V_2 . V_392 = V_490 ;
V_50 = ( F_212 ( V_10 ) == V_404 ) ;
}
return V_50 ;
}
static int F_255 ( struct V_7 * V_10 )
{
int V_295 , V_491 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_38 ( V_489 ) )
return F_253 ( V_10 ) ;
if ( F_117 ( ( V_10 -> V_1 -> V_2 . V_357 & V_492 ) == 0 ) )
return F_253 ( V_10 ) ;
V_295 = V_10 -> V_1 -> V_2 . V_357 & V_493 ;
V_491 = V_10 -> V_1 -> V_2 . V_392 - V_419 ;
V_80 = 0 ;
if ( V_491 >= 16 ) {
V_491 -= 16 ;
V_81 = F_244 ( & V_10 -> V_9 , V_295 ) ;
switch ( V_491 ) {
case 0 :
if ( ! F_254 ( V_10 , V_81 ) )
V_80 = F_102 ( & V_10 -> V_9 , V_81 ) ;
else
return 1 ;
break;
case 3 :
V_80 = F_220 ( & V_10 -> V_9 , V_81 ) ;
break;
case 4 :
V_80 = F_256 ( & V_10 -> V_9 , V_81 ) ;
break;
case 8 :
V_80 = F_257 ( & V_10 -> V_9 , V_81 ) ;
break;
default:
F_258 ( 1 , L_11 , V_491 ) ;
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
} else {
switch ( V_491 ) {
case 0 :
V_81 = F_216 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_81 = V_10 -> V_9 . V_23 . V_403 ;
break;
case 3 :
V_81 = F_129 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_81 = F_259 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_81 = F_260 ( & V_10 -> V_9 ) ;
break;
default:
F_258 ( 1 , L_12 , V_491 ) ;
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
F_221 ( & V_10 -> V_9 , V_295 , V_81 ) ;
}
F_261 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
static int F_262 ( struct V_7 * V_10 )
{
int V_295 , V_494 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_79 ( V_489 ) )
return F_253 ( V_10 ) ;
V_295 = V_10 -> V_1 -> V_2 . V_357 & V_493 ;
V_494 = V_10 -> V_1 -> V_2 . V_392 - V_421 ;
if ( V_494 >= 16 ) {
V_81 = F_244 ( & V_10 -> V_9 , V_295 ) ;
F_263 ( & V_10 -> V_9 , V_494 - 16 , V_81 ) ;
} else {
V_80 = F_264 ( & V_10 -> V_9 , V_494 , & V_81 ) ;
if ( ! V_80 )
F_221 ( & V_10 -> V_9 , V_295 , V_81 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_265 ( struct V_7 * V_10 )
{
struct V_362 * V_362 = V_10 -> V_9 . V_363 ;
int V_115 ;
T_4 V_495 = F_260 ( & V_10 -> V_9 ) ;
V_115 = F_255 ( V_10 ) ;
if ( F_266 ( V_10 -> V_9 . V_264 ) ) {
F_10 ( V_10 , V_184 ) ;
return V_115 ;
}
if ( V_495 <= F_260 ( & V_10 -> V_9 ) )
return V_115 ;
V_362 -> V_366 = V_496 ;
return 0 ;
}
static int F_267 ( struct V_8 * V_9 , unsigned V_497 , T_2 * V_498 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_497 ) {
case V_499 : {
struct V_1 * V_1 = F_8 ( V_10 ) ;
* V_498 = V_1 -> V_2 . V_173 +
F_91 ( V_9 , F_98 () ) ;
break;
}
case V_500 :
* V_498 = V_10 -> V_1 -> V_42 . V_446 ;
break;
#ifdef F_26
case V_501 :
* V_498 = V_10 -> V_1 -> V_42 . V_447 ;
break;
case V_502 :
* V_498 = V_10 -> V_1 -> V_42 . V_448 ;
break;
case V_290 :
* V_498 = V_10 -> V_1 -> V_42 . V_445 ;
break;
case V_503 :
* V_498 = V_10 -> V_1 -> V_42 . V_449 ;
break;
#endif
case V_504 :
* V_498 = V_10 -> V_1 -> V_42 . V_450 ;
break;
case V_505 :
* V_498 = V_10 -> V_452 ;
break;
case V_506 :
* V_498 = V_10 -> V_451 ;
break;
case V_507 :
* V_498 = V_10 -> V_1 -> V_42 . V_508 ;
break;
case V_133 :
* V_498 = V_10 -> V_1 -> V_42 . V_509 ;
break;
case V_134 :
* V_498 = V_10 -> V_1 -> V_42 . V_510 ;
break;
case V_135 :
* V_498 = V_10 -> V_1 -> V_42 . V_511 ;
break;
case V_136 :
* V_498 = V_10 -> V_1 -> V_42 . V_512 ;
break;
case V_110 :
* V_498 = V_10 -> V_17 . V_513 ;
break;
case V_514 :
* V_498 = V_10 -> V_17 . V_515 ;
break;
case V_516 :
* V_498 = 0x01000065 ;
break;
default:
return F_268 ( V_9 , V_497 , V_498 ) ;
}
return 0 ;
}
static int F_269 ( struct V_7 * V_10 )
{
T_1 V_497 = V_10 -> V_9 . V_23 . V_247 [ V_414 ] ;
T_2 V_498 ;
if ( F_267 ( & V_10 -> V_9 , V_497 , & V_498 ) ) {
F_270 ( V_497 ) ;
F_194 ( & V_10 -> V_9 , 0 ) ;
} else {
F_271 ( V_497 , V_498 ) ;
V_10 -> V_9 . V_23 . V_247 [ V_438 ] = V_498 & 0xffffffff ;
V_10 -> V_9 . V_23 . V_247 [ V_517 ] = V_498 >> 32 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_272 ( struct V_8 * V_9 , T_2 V_498 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_518 , V_519 ;
if ( V_498 & ~ V_520 )
return 1 ;
V_519 = V_520 ;
if ( V_10 -> V_17 . V_515 & V_521 )
V_519 &= ~ ( V_522 | V_521 ) ;
V_10 -> V_17 . V_515 &= ~ V_519 ;
V_10 -> V_17 . V_515 |= ( V_498 & V_519 ) ;
V_518 = V_10 -> V_17 . V_515 & V_521 ;
if ( V_518 && ( V_9 -> V_23 . V_38 & V_43 ) )
return 1 ;
return 0 ;
}
static int F_273 ( struct V_8 * V_9 , unsigned V_497 , T_2 V_498 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_497 ) {
case V_499 :
F_109 ( V_9 , V_498 ) ;
break;
case V_500 :
V_10 -> V_1 -> V_42 . V_446 = V_498 ;
break;
#ifdef F_26
case V_501 :
V_10 -> V_1 -> V_42 . V_447 = V_498 ;
break;
case V_502 :
V_10 -> V_1 -> V_42 . V_448 = V_498 ;
break;
case V_290 :
V_10 -> V_1 -> V_42 . V_445 = V_498 ;
break;
case V_503 :
V_10 -> V_1 -> V_42 . V_449 = V_498 ;
break;
#endif
case V_504 :
V_10 -> V_1 -> V_42 . V_450 = V_498 ;
break;
case V_505 :
V_10 -> V_452 = V_498 ;
V_10 -> V_1 -> V_42 . V_452 = V_498 ;
break;
case V_506 :
V_10 -> V_451 = V_498 ;
V_10 -> V_1 -> V_42 . V_451 = V_498 ;
break;
case V_507 :
if ( ! F_79 ( V_523 ) ) {
F_274 ( V_9 , L_13 ,
V_59 , V_498 ) ;
break;
}
if ( V_498 & V_524 )
return 1 ;
V_10 -> V_1 -> V_42 . V_508 = V_498 ;
F_3 ( V_10 -> V_1 , V_525 ) ;
if ( V_498 & ( 1ULL << 0 ) )
F_74 ( V_10 ) ;
else
F_75 ( V_10 ) ;
break;
case V_110 :
V_10 -> V_17 . V_513 = V_498 ;
break;
case V_514 :
return F_272 ( V_9 , V_498 ) ;
case V_526 :
F_274 ( V_9 , L_14 , V_497 , V_498 ) ;
break;
default:
return F_275 ( V_9 , V_497 , V_498 ) ;
}
return 0 ;
}
static int F_276 ( struct V_7 * V_10 )
{
T_1 V_497 = V_10 -> V_9 . V_23 . V_247 [ V_414 ] ;
T_2 V_498 = ( V_10 -> V_9 . V_23 . V_247 [ V_438 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_23 . V_247 [ V_517 ] & - 1u ) << 32 ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_273 ( & V_10 -> V_9 , V_497 , V_498 ) ) {
F_277 ( V_497 , V_498 ) ;
F_194 ( & V_10 -> V_9 , 0 ) ;
} else {
F_278 ( V_497 , V_498 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_279 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_357 )
return F_276 ( V_10 ) ;
else
return F_269 ( V_10 ) ;
}
static int F_280 ( struct V_7 * V_10 )
{
struct V_362 * V_362 = V_10 -> V_9 . V_363 ;
F_174 ( V_454 , & V_10 -> V_9 ) ;
F_131 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_230 &= ~ V_455 ;
F_3 ( V_10 -> V_1 , V_456 ) ;
if ( ! F_266 ( V_10 -> V_9 . V_264 ) &&
V_362 -> V_527 &&
! F_281 ( & V_10 -> V_9 ) ) {
++ V_10 -> V_9 . V_288 . V_528 ;
V_362 -> V_366 = V_529 ;
return 0 ;
}
return 1 ;
}
static int F_282 ( struct V_7 * V_10 )
{
F_283 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static void F_284 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_176 * V_42 = & V_10 -> V_1 -> V_42 ;
F_173 ( L_15 ) ;
F_173 ( L_16 , L_17 , V_2 -> V_19 & 0xffff ) ;
F_173 ( L_16 , L_18 , V_2 -> V_19 >> 16 ) ;
F_173 ( L_16 , L_19 , V_2 -> V_20 & 0xffff ) ;
F_173 ( L_16 , L_20 , V_2 -> V_20 >> 16 ) ;
F_173 ( L_21 , L_22 , V_2 -> V_21 ) ;
F_173 ( L_23 , L_24 , V_2 -> V_22 ) ;
F_173 ( L_25 , L_26 , V_2 -> V_259 ) ;
F_173 ( L_23 , L_27 , V_2 -> V_228 ) ;
F_173 ( L_23 , L_28 , V_2 -> V_229 ) ;
F_173 ( L_23 , L_29 , V_2 -> V_173 ) ;
F_173 ( L_25 , L_30 , V_2 -> V_35 ) ;
F_173 ( L_25 , L_31 , V_2 -> V_350 ) ;
F_173 ( L_21 , L_32 , V_2 -> V_230 ) ;
F_173 ( L_21 , L_33 , V_2 -> V_430 ) ;
F_173 ( L_21 , L_34 , V_2 -> V_51 ) ;
F_173 ( L_21 , L_35 , V_2 -> V_392 ) ;
F_173 ( L_23 , L_36 , V_2 -> V_357 ) ;
F_173 ( L_23 , L_37 , V_2 -> V_355 ) ;
F_173 ( L_21 , L_38 , V_2 -> V_431 ) ;
F_173 ( L_21 , L_39 , V_2 -> V_432 ) ;
F_173 ( L_40 , L_41 , V_2 -> V_255 ) ;
F_173 ( L_23 , L_42 , V_2 -> V_387 ) ;
F_173 ( L_21 , L_43 , V_2 -> V_74 ) ;
F_173 ( L_21 , L_44 , V_2 -> V_77 ) ;
F_173 ( L_40 , L_45 , V_2 -> V_132 ) ;
F_173 ( L_23 , L_46 , V_2 -> V_55 ) ;
F_173 ( L_47 ) ;
F_173 ( L_48 ,
L_49 ,
V_42 -> V_232 . V_156 , V_42 -> V_232 . V_157 ,
V_42 -> V_232 . V_161 , V_42 -> V_232 . V_72 ) ;
F_173 ( L_48 ,
L_50 ,
V_42 -> V_71 . V_156 , V_42 -> V_71 . V_157 ,
V_42 -> V_71 . V_161 , V_42 -> V_71 . V_72 ) ;
F_173 ( L_48 ,
L_51 ,
V_42 -> V_233 . V_156 , V_42 -> V_233 . V_157 ,
V_42 -> V_233 . V_161 , V_42 -> V_233 . V_72 ) ;
F_173 ( L_48 ,
L_52 ,
V_42 -> V_234 . V_156 , V_42 -> V_234 . V_157 ,
V_42 -> V_234 . V_161 , V_42 -> V_234 . V_72 ) ;
F_173 ( L_48 ,
L_53 ,
V_42 -> V_235 . V_156 , V_42 -> V_235 . V_157 ,
V_42 -> V_235 . V_161 , V_42 -> V_235 . V_72 ) ;
F_173 ( L_48 ,
L_54 ,
V_42 -> V_236 . V_156 , V_42 -> V_236 . V_157 ,
V_42 -> V_236 . V_161 , V_42 -> V_236 . V_72 ) ;
F_173 ( L_48 ,
L_55 ,
V_42 -> V_239 . V_156 , V_42 -> V_239 . V_157 ,
V_42 -> V_239 . V_161 , V_42 -> V_239 . V_72 ) ;
F_173 ( L_48 ,
L_56 ,
V_42 -> V_241 . V_156 , V_42 -> V_241 . V_157 ,
V_42 -> V_241 . V_161 , V_42 -> V_241 . V_72 ) ;
F_173 ( L_48 ,
L_57 ,
V_42 -> V_240 . V_156 , V_42 -> V_240 . V_157 ,
V_42 -> V_240 . V_161 , V_42 -> V_240 . V_72 ) ;
F_173 ( L_48 ,
L_58 ,
V_42 -> V_243 . V_156 , V_42 -> V_243 . V_157 ,
V_42 -> V_243 . V_161 , V_42 -> V_243 . V_72 ) ;
F_173 ( L_59 ,
V_42 -> V_324 , V_42 -> V_38 ) ;
F_173 ( L_60 ,
L_61 , V_42 -> V_249 , L_62 , V_42 -> V_403 ) ;
F_173 ( L_60 ,
L_63 , V_42 -> V_257 , L_64 , V_42 -> V_253 ) ;
F_173 ( L_60 ,
L_65 , V_42 -> V_245 , L_66 , V_42 -> V_246 ) ;
F_173 ( L_60 ,
L_67 , V_42 -> V_68 , L_68 , V_42 -> V_293 ) ;
F_173 ( L_60 ,
L_69 , V_42 -> V_434 , L_70 , V_42 -> V_435 ) ;
F_173 ( L_60 ,
L_71 , V_42 -> V_446 , L_72 , V_42 -> V_447 ) ;
F_173 ( L_60 ,
L_73 , V_42 -> V_448 , L_74 , V_42 -> V_449 ) ;
F_173 ( L_60 ,
L_75 , V_42 -> V_445 ,
L_76 , V_42 -> V_450 ) ;
F_173 ( L_60 ,
L_77 , V_42 -> V_451 ,
L_78 , V_42 -> V_452 ) ;
F_173 ( L_60 ,
L_79 , V_42 -> V_256 , L_80 , V_42 -> V_508 ) ;
F_173 ( L_60 ,
L_81 , V_42 -> V_509 , L_82 , V_42 -> V_510 ) ;
F_173 ( L_60 ,
L_83 , V_42 -> V_511 ,
L_84 , V_42 -> V_512 ) ;
}
static void F_285 ( struct V_8 * V_9 , T_2 * V_530 , T_2 * V_531 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_530 = V_2 -> V_357 ;
* V_531 = V_2 -> V_355 ;
}
static int F_286 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_362 * V_362 = V_9 -> V_363 ;
T_1 V_392 = V_10 -> V_1 -> V_2 . V_392 ;
F_287 ( V_392 , V_9 , V_532 ) ;
if ( ! F_11 ( V_10 , V_181 ) )
V_9 -> V_23 . V_249 = V_10 -> V_1 -> V_42 . V_249 ;
if ( V_39 )
V_9 -> V_23 . V_257 = V_10 -> V_1 -> V_42 . V_257 ;
if ( F_117 ( V_10 -> V_17 . V_405 ) ) {
F_189 ( V_10 ) ;
V_10 -> V_17 . V_405 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_401 ;
F_288 ( V_10 -> V_1 -> V_42 . V_68 , V_392 ,
V_10 -> V_1 -> V_2 . V_357 ,
V_10 -> V_1 -> V_2 . V_355 ,
V_10 -> V_1 -> V_2 . V_431 ,
V_10 -> V_1 -> V_2 . V_432 ) ;
V_401 = F_211 ( V_10 ) ;
if ( V_401 == V_416 )
V_401 = F_212 ( V_10 ) ;
if ( V_401 == V_404 )
return 1 ;
}
F_289 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_392 == V_424 ) {
V_362 -> V_366 = V_533 ;
V_362 -> V_534 . V_535
= V_10 -> V_1 -> V_2 . V_392 ;
F_173 ( L_85 ) ;
F_284 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_431 ) &&
V_392 != V_402 + V_201 &&
V_392 != V_393 && V_392 != V_536 &&
V_392 != V_408 && V_392 != V_409 )
F_33 ( V_61 L_86
L_87 ,
V_59 , V_10 -> V_1 -> V_2 . V_431 ,
V_392 ) ;
if ( V_392 >= F_290 ( V_537 )
|| ! V_537 [ V_392 ] ) {
V_362 -> V_366 = V_538 ;
V_362 -> V_539 . V_540 = V_392 ;
return 0 ;
}
return V_537 [ V_392 ] ( V_10 ) ;
}
static void F_291 ( struct V_8 * V_9 )
{
int V_114 = F_51 () ;
struct V_91 * V_92 = F_53 ( V_101 , V_114 ) ;
V_92 -> V_107 -> type = 9 ;
F_292 () ;
}
static void F_293 ( struct V_7 * V_10 )
{
int V_114 = F_51 () ;
struct V_91 * V_92 = F_53 ( V_101 , V_114 ) ;
if ( V_10 -> V_102 != V_92 -> V_102 )
F_152 ( V_10 , V_92 ) ;
}
static void F_294 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_74 = V_47 | V_541 ;
V_9 -> V_23 . V_24 |= V_542 ;
F_16 ( V_10 , V_486 ) ;
++ V_9 -> V_288 . V_543 ;
}
static inline void F_295 ( struct V_7 * V_10 , int V_544 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_430 = V_544 ;
V_2 -> V_230 &= ~ V_545 ;
V_2 -> V_230 |= V_455 |
( ( 0xf ) << V_546 ) ;
F_3 ( V_10 -> V_1 , V_456 ) ;
}
static void F_296 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_67 ( ! ( F_20 ( V_10 ) ) ) ;
F_297 ( V_9 -> V_23 . V_547 . V_62 ) ;
++ V_9 -> V_288 . V_548 ;
V_10 -> V_1 -> V_2 . V_74 = V_9 -> V_23 . V_547 . V_62 |
V_47 | V_48 ;
}
static void F_298 ( struct V_8 * V_9 , int V_549 , int V_550 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_406 ) )
return;
if ( V_550 == - 1 )
return;
if ( V_549 >= V_550 )
F_9 ( V_10 , V_184 ) ;
}
static int F_299 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
V_50 = ! ( V_1 -> V_2 . V_51 & V_52 ) &&
! ( V_10 -> V_9 . V_23 . V_24 & V_542 ) ;
V_50 = V_50 && F_20 ( V_10 ) && F_198 ( V_10 ) ;
return V_50 ;
}
static bool F_300 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_542 ) ;
}
static void F_301 ( struct V_8 * V_9 , bool V_551 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_551 ) {
V_10 -> V_9 . V_23 . V_24 |= V_542 ;
F_16 ( V_10 , V_486 ) ;
} else {
V_10 -> V_9 . V_23 . V_24 &= ~ V_542 ;
F_17 ( V_10 , V_486 ) ;
}
}
static int F_302 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_51 & V_52 ) )
return 0 ;
V_50 = ! ! ( F_217 ( V_9 ) & V_442 ) ;
if ( F_7 ( V_9 ) )
return V_50 && ! ( V_10 -> V_9 . V_23 . V_24 & V_406 ) ;
return V_50 ;
}
static void F_303 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_196 ( V_10 ) ) {
F_130 ( V_10 ) ;
F_295 ( V_10 , 0x0 ) ;
}
}
static void F_304 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_23 . V_24 & ( V_542 | V_487 ) )
== V_542 )
return;
V_10 -> V_340 = true ;
V_10 -> V_1 -> V_42 . V_293 |= ( V_364 | V_365 ) ;
F_150 ( V_9 ) ;
}
static int F_305 ( struct V_264 * V_264 , unsigned int V_34 )
{
return 0 ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_552 ) )
V_10 -> V_1 -> V_2 . V_350 = V_553 ;
else
V_10 -> V_102 -- ;
}
static void F_306 ( struct V_8 * V_9 )
{
}
static inline void F_307 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_406 ) )
return;
if ( ! F_11 ( V_10 , V_184 ) ) {
int V_554 = V_10 -> V_1 -> V_2 . V_230 & V_555 ;
F_257 ( V_9 , V_554 ) ;
}
}
static inline void F_308 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_554 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_406 ) )
return;
V_554 = F_260 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_230 &= ~ V_555 ;
V_10 -> V_1 -> V_2 . V_230 |= V_554 & V_555 ;
}
static void F_289 ( struct V_7 * V_10 )
{
T_4 V_556 ;
int type ;
T_1 V_557 = V_10 -> V_1 -> V_2 . V_431 ;
unsigned V_73 = V_10 -> V_73 ;
V_10 -> V_73 = 0 ;
if ( ( V_10 -> V_9 . V_23 . V_24 & V_487 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_488 ) {
V_10 -> V_9 . V_23 . V_24 &= ~ ( V_542 | V_487 ) ;
F_174 ( V_454 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_23 . V_473 = false ;
F_218 ( & V_10 -> V_9 ) ;
F_219 ( & V_10 -> V_9 ) ;
if ( ! ( V_557 & V_465 ) )
return;
F_174 ( V_454 , & V_10 -> V_9 ) ;
V_556 = V_557 & V_558 ;
type = V_557 & V_461 ;
switch ( type ) {
case V_472 :
V_10 -> V_9 . V_23 . V_473 = true ;
break;
case V_474 :
if ( F_309 ( V_556 ) ) {
if ( V_556 == V_66 && V_73 &&
F_310 ( & V_10 -> V_9 , V_10 -> V_70 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_73 ) ;
break;
}
if ( V_557 & V_559 ) {
T_1 V_80 = V_10 -> V_1 -> V_2 . V_432 ;
F_311 ( & V_10 -> V_9 , V_556 , V_80 ) ;
} else
F_312 ( & V_10 -> V_9 , V_556 ) ;
break;
case V_476 :
F_313 ( & V_10 -> V_9 , V_556 , false ) ;
break;
default:
break;
}
}
static void F_314 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_431 = V_2 -> V_74 ;
V_2 -> V_432 = V_2 -> V_77 ;
V_2 -> V_74 = 0 ;
F_289 ( V_10 ) ;
}
static void F_315 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_435 = V_9 -> V_23 . V_247 [ V_438 ] ;
V_10 -> V_1 -> V_42 . V_434 = V_9 -> V_23 . V_247 [ V_439 ] ;
V_10 -> V_1 -> V_42 . V_68 = V_9 -> V_23 . V_247 [ V_248 ] ;
if ( F_117 ( V_10 -> V_17 . V_405 ) )
return;
F_293 ( V_10 ) ;
F_308 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_403 = V_9 -> V_23 . V_403 ;
F_22 () ;
F_161 () ;
asm volatile (
"push %%"R"bp; \n\t"
"mov %c[rbx](%[svm]), %%"R"bx \n\t"
"mov %c[rcx](%[svm]), %%"R"cx \n\t"
"mov %c[rdx](%[svm]), %%"R"dx \n\t"
"mov %c[rsi](%[svm]), %%"R"si \n\t"
"mov %c[rdi](%[svm]), %%"R"di \n\t"
"mov %c[rbp](%[svm]), %%"R"bp \n\t"
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
"push %%"R"ax \n\t"
"mov %c[vmcb](%[svm]), %%"R"ax \n\t"
__ex(SVM_VMLOAD) "\n\t"
__ex(SVM_VMRUN) "\n\t"
__ex(SVM_VMSAVE) "\n\t"
"pop %%"R"ax \n\t"
"mov %%"R"bx, %c[rbx](%[svm]) \n\t"
"mov %%"R"cx, %c[rcx](%[svm]) \n\t"
"mov %%"R"dx, %c[rdx](%[svm]) \n\t"
"mov %%"R"si, %c[rsi](%[svm]) \n\t"
"mov %%"R"di, %c[rdi](%[svm]) \n\t"
"mov %%"R"bp, %c[rbp](%[svm]) \n\t"
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
"pop %%"R"bp"
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
, R"bx", R"cx", R"dx", R"si", R"di"
#ifdef F_26
, "r8", "r9", "r10", "r11" , "r12", "r13", "r14", "r15"
#endif
);
#ifdef F_26
F_48 ( V_281 , V_10 -> V_282 . V_283 ) ;
#else
F_122 ( V_235 , V_10 -> V_282 . V_235 ) ;
#ifndef F_124
F_122 ( V_236 , V_10 -> V_282 . V_236 ) ;
#endif
#endif
F_291 ( V_9 ) ;
F_159 () ;
V_9 -> V_23 . V_403 = V_10 -> V_1 -> V_42 . V_403 ;
V_9 -> V_23 . V_247 [ V_438 ] = V_10 -> V_1 -> V_42 . V_435 ;
V_9 -> V_23 . V_247 [ V_439 ] = V_10 -> V_1 -> V_42 . V_434 ;
V_9 -> V_23 . V_247 [ V_248 ] = V_10 -> V_1 -> V_42 . V_68 ;
if ( F_117 ( V_10 -> V_1 -> V_2 . V_392 == V_409 ) )
F_316 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_117 ( V_10 -> V_1 -> V_2 . V_392 == V_409 ) )
F_317 ( & V_10 -> V_9 ) ;
F_307 ( V_9 ) ;
V_10 -> V_55 = 0 ;
V_10 -> V_1 -> V_2 . V_350 = V_560 ;
if ( V_10 -> V_1 -> V_2 . V_392 == V_402 + V_201 )
V_10 -> V_356 = F_318 () ;
if ( V_39 ) {
V_9 -> V_23 . V_262 &= ~ ( 1 << V_296 ) ;
V_9 -> V_23 . V_263 &= ~ ( 1 << V_296 ) ;
}
if ( F_117 ( V_10 -> V_1 -> V_2 . V_392 ==
V_402 + V_203 ) )
F_172 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_319 ( struct V_8 * V_9 , unsigned long V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_257 = V_388 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_148 ( V_9 ) ;
}
static void F_320 ( struct V_8 * V_9 , unsigned long V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_387 = V_388 ;
F_3 ( V_10 -> V_1 , V_389 ) ;
V_10 -> V_1 -> V_42 . V_257 = F_129 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_148 ( V_9 ) ;
}
static int F_321 ( void )
{
T_2 V_561 ;
F_52 ( V_514 , V_561 ) ;
if ( V_561 & ( 1 << V_562 ) )
return 1 ;
return 0 ;
}
static void
F_322 ( struct V_8 * V_9 , unsigned char * V_563 )
{
V_563 [ 0 ] = 0x0f ;
V_563 [ 1 ] = 0x01 ;
V_563 [ 2 ] = 0xd9 ;
}
static void F_323 ( void * V_564 )
{
* ( int * ) V_564 = 0 ;
}
static bool F_324 ( void )
{
return false ;
}
static T_2 F_325 ( struct V_8 * V_9 , T_11 V_565 , bool V_566 )
{
return 0 ;
}
static void F_326 ( struct V_8 * V_9 )
{
}
static void F_327 ( T_1 V_567 , struct V_568 * V_569 )
{
switch ( V_567 ) {
case 0x80000001 :
if ( V_17 )
V_569 -> V_497 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_569 -> V_570 = 1 ;
V_569 -> V_571 = 8 ;
V_569 -> V_497 = 0 ;
V_569 -> V_572 = 0 ;
if ( F_79 ( V_67 ) )
V_569 -> V_572 |= V_573 ;
if ( V_39 )
V_569 -> V_572 |= V_574 ;
break;
}
}
static int F_328 ( void )
{
return V_575 ;
}
static bool F_329 ( void )
{
return false ;
}
static bool F_330 ( void )
{
return true ;
}
static void F_331 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_373 ) ;
F_143 ( V_10 ) ;
}
static int F_332 ( struct V_8 * V_9 ,
struct V_576 * V_45 ,
enum V_577 V_578 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_401 , V_50 = V_579 ;
struct V_580 V_581 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_45 -> V_22 >= F_290 ( V_582 ) )
goto V_270;
V_581 = V_582 [ V_45 -> V_22 ] ;
if ( V_578 != V_581 . V_578 )
goto V_270;
switch ( V_581 . V_392 ) {
case V_419 :
if ( V_45 -> V_22 == V_583 )
V_581 . V_392 += V_45 -> V_584 ;
break;
case V_585 : {
unsigned long V_249 , V_81 ;
T_2 V_22 ;
if ( V_45 -> V_22 == V_586 )
V_581 . V_392 += V_45 -> V_584 ;
if ( V_581 . V_392 != V_585 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_207 ) ) )
break;
V_249 = V_9 -> V_23 . V_249 & ~ V_330 ;
V_81 = V_45 -> V_587 & ~ V_330 ;
if ( V_45 -> V_22 == V_588 ) {
V_249 &= 0xfUL ;
V_81 &= 0xfUL ;
if ( V_249 & V_437 )
V_81 |= V_437 ;
}
if ( V_249 ^ V_81 )
V_581 . V_392 = V_490 ;
break;
}
case V_421 :
case V_589 :
V_581 . V_392 += V_45 -> V_584 ;
break;
case V_417 :
if ( V_45 -> V_22 == V_590 )
V_1 -> V_2 . V_357 = 1 ;
else
V_1 -> V_2 . V_357 = 0 ;
break;
case V_591 :
if ( V_45 -> V_592 != V_593 )
goto V_270;
case V_418 : {
T_2 V_594 ;
T_1 V_595 ;
V_594 = ( V_9 -> V_23 . V_247 [ V_517 ] & 0xffff ) << 16 ;
if ( V_45 -> V_22 == V_596 ||
V_45 -> V_22 == V_597 ) {
V_594 |= V_383 ;
V_595 = V_45 -> V_598 ;
} else {
V_595 = V_45 -> V_599 ;
}
if ( V_45 -> V_22 == V_600 ||
V_45 -> V_22 == V_597 )
V_594 |= V_382 ;
if ( V_45 -> V_592 )
V_594 |= V_601 ;
V_595 = F_81 ( V_595 , 4u ) ;
V_594 |= V_595 << V_385 ;
V_594 |= ( T_1 ) V_45 -> V_602 << ( V_603 - 1 ) ;
V_1 -> V_2 . V_357 = V_594 ;
V_1 -> V_2 . V_355 = V_45 -> V_55 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_55 = V_45 -> V_55 ;
V_1 -> V_2 . V_392 = V_581 . V_392 ;
V_401 = F_212 ( V_10 ) ;
V_50 = ( V_401 == V_404 ) ? V_604
: V_579 ;
V_270:
return V_50 ;
}
static int T_5 F_333 ( void )
{
return F_334 ( & V_605 , sizeof( struct V_7 ) ,
F_335 ( struct V_7 ) , V_606 ) ;
}
static void T_6 F_336 ( void )
{
F_337 () ;
}
