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
static int F_146 ( struct V_8 * V_9 , unsigned long V_253 )
{
unsigned long V_334 = F_147 () & V_335 ;
unsigned long V_336 = F_4 ( V_9 ) -> V_1 -> V_42 . V_253 ;
if ( V_253 & V_337 )
return 1 ;
if ( V_39 && ( ( V_336 ^ V_253 ) & V_338 ) )
F_148 ( V_9 ) ;
V_9 -> V_23 . V_253 = V_253 ;
if ( ! V_39 )
V_253 |= V_254 ;
V_253 |= V_334 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_253 = V_253 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
return 0 ;
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
F_3 ( V_10 -> V_1 , V_339 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_340 ) ;
F_15 ( V_10 , V_66 ) ;
if ( V_10 -> V_341 )
F_14 ( V_10 , V_340 ) ;
if ( V_9 -> V_342 & V_343 ) {
if ( V_9 -> V_342 &
( V_344 | V_345 ) )
F_14 ( V_10 , V_340 ) ;
if ( V_9 -> V_342 & V_346 )
F_14 ( V_10 , V_66 ) ;
} else
V_9 -> V_342 = 0 ;
}
static void F_151 ( struct V_8 * V_9 , struct V_347 * V_348 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_9 -> V_342 & V_345 )
V_10 -> V_1 -> V_42 . V_246 = V_348 -> V_23 . V_349 [ 7 ] ;
else
V_10 -> V_1 -> V_42 . V_246 = V_9 -> V_23 . V_246 ;
F_3 ( V_10 -> V_1 , V_350 ) ;
F_150 ( V_9 ) ;
}
static void F_152 ( struct V_7 * V_10 , struct V_91 * V_92 )
{
if ( V_92 -> V_105 > V_92 -> V_103 ) {
++ V_92 -> V_102 ;
V_92 -> V_105 = 1 ;
V_10 -> V_1 -> V_2 . V_351 = V_352 ;
}
V_10 -> V_102 = V_92 -> V_102 ;
V_10 -> V_1 -> V_2 . V_35 = V_92 -> V_105 ++ ;
F_3 ( V_10 -> V_1 , V_353 ) ;
}
static void F_153 ( struct V_8 * V_9 , unsigned long V_354 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_246 = V_354 ;
F_3 ( V_10 -> V_1 , V_350 ) ;
}
static int F_154 ( struct V_7 * V_10 )
{
T_2 V_355 = V_10 -> V_1 -> V_2 . V_356 ;
T_1 V_64 ;
int V_115 = 1 ;
switch ( V_10 -> V_357 ) {
default:
V_64 = V_10 -> V_1 -> V_2 . V_358 ;
F_155 ( V_355 , V_64 ) ;
if ( ! V_39 && F_156 ( & V_10 -> V_9 ) )
F_157 ( & V_10 -> V_9 , V_355 ) ;
V_115 = F_158 ( & V_10 -> V_9 , V_355 , V_64 ,
V_10 -> V_1 -> V_2 . V_359 ,
V_10 -> V_1 -> V_2 . V_360 ) ;
break;
case V_361 :
V_10 -> V_357 = 0 ;
F_159 () ;
F_160 ( V_355 ) ;
F_161 () ;
break;
case V_362 :
V_10 -> V_357 = 0 ;
F_159 () ;
F_162 ( V_355 ) ;
F_161 () ;
break;
}
return V_115 ;
}
static int F_163 ( struct V_7 * V_10 )
{
struct V_363 * V_363 = V_10 -> V_9 . V_364 ;
if ( ! ( V_10 -> V_9 . V_342 &
( V_344 | V_345 ) ) &&
! V_10 -> V_341 ) {
F_164 ( & V_10 -> V_9 , V_340 ) ;
return 1 ;
}
if ( V_10 -> V_341 ) {
V_10 -> V_341 = false ;
if ( ! ( V_10 -> V_9 . V_342 & V_344 ) )
V_10 -> V_1 -> V_42 . V_293 &=
~ ( V_365 | V_366 ) ;
F_150 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_342 &
( V_344 | V_345 ) ) {
V_363 -> V_367 = V_368 ;
V_363 -> V_369 . V_23 . V_370 =
V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_363 -> V_369 . V_23 . V_371 = V_340 ;
return 0 ;
}
return 1 ;
}
static int F_165 ( struct V_7 * V_10 )
{
struct V_363 * V_363 = V_10 -> V_9 . V_364 ;
V_363 -> V_367 = V_368 ;
V_363 -> V_369 . V_23 . V_370 = V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_363 -> V_369 . V_23 . V_371 = V_66 ;
return 0 ;
}
static int F_166 ( struct V_7 * V_10 )
{
int V_372 ;
V_372 = F_32 ( & V_10 -> V_9 , V_373 ) ;
if ( V_372 != V_57 )
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static void F_167 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_374 ) ;
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
T_2 V_354 ;
if ( ! V_84 )
return false ;
V_354 = F_41 ( V_375 , & V_80 ) ;
if ( V_80 )
return false ;
V_354 &= ~ ( 1ULL << 62 ) ;
if ( V_354 != 0xb600000000010015ULL )
return false ;
for ( V_28 = 0 ; V_28 < 6 ; ++ V_28 )
F_44 ( F_170 ( V_28 ) , 0 , 0 ) ;
V_354 = F_41 ( V_376 , & V_80 ) ;
if ( ! V_80 ) {
T_1 V_78 , V_79 ;
V_354 &= ~ ( 1ULL << 2 ) ;
V_78 = F_42 ( V_354 ) ;
V_79 = F_43 ( V_354 ) ;
F_44 ( V_376 , V_78 , V_79 ) ;
}
F_171 () ;
return true ;
}
static void F_172 ( struct V_7 * V_10 )
{
if ( F_169 () ) {
F_173 ( L_10 ) ;
F_174 ( V_377 , & V_10 -> V_9 ) ;
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
struct V_363 * V_363 = V_10 -> V_9 . V_364 ;
F_108 ( V_10 -> V_1 ) ;
F_99 ( V_10 ) ;
V_363 -> V_367 = V_378 ;
return 0 ;
}
static int F_177 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_379 = V_10 -> V_1 -> V_2 . V_358 ;
int V_326 , V_380 , string ;
unsigned V_381 ;
++ V_10 -> V_9 . V_288 . V_382 ;
string = ( V_379 & V_383 ) != 0 ;
V_380 = ( V_379 & V_384 ) != 0 ;
if ( string || V_380 )
return F_32 ( V_9 , 0 ) == V_57 ;
V_381 = V_379 >> 16 ;
V_326 = ( V_379 & V_385 ) >> V_386 ;
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_356 ;
F_31 ( & V_10 -> V_9 ) ;
return F_178 ( V_9 , V_326 , V_381 ) ;
}
static int F_179 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_180 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_288 . V_387 ;
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
return V_10 -> V_17 . V_388 ;
}
static void F_187 ( struct V_8 * V_9 ,
unsigned long V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_388 = V_389 ;
F_3 ( V_10 -> V_1 , V_390 ) ;
F_148 ( V_9 ) ;
}
static void F_188 ( struct V_8 * V_9 ,
struct V_391 * V_392 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_393 = V_394 ;
V_10 -> V_1 -> V_2 . V_395 = 0 ;
V_10 -> V_1 -> V_2 . V_358 = V_392 -> V_64 ;
V_10 -> V_1 -> V_2 . V_356 = V_392 -> V_106 ;
F_189 ( V_10 ) ;
}
static int F_190 ( struct V_8 * V_9 )
{
int V_115 ;
V_115 = F_191 ( V_9 , & V_9 -> V_23 . V_396 ) ;
V_9 -> V_23 . V_396 . V_397 = F_187 ;
V_9 -> V_23 . V_396 . V_398 = F_186 ;
V_9 -> V_23 . V_396 . V_399 = F_188 ;
V_9 -> V_23 . V_396 . V_400 = F_25 () ;
V_9 -> V_23 . V_297 = & V_9 -> V_23 . V_401 ;
return V_115 ;
}
static void F_192 ( struct V_8 * V_9 )
{
V_9 -> V_23 . V_297 = & V_9 -> V_23 . V_396 ;
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
int V_402 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_393 = V_403 + V_62 ;
V_10 -> V_1 -> V_2 . V_395 = 0 ;
V_10 -> V_1 -> V_2 . V_358 = V_64 ;
V_10 -> V_1 -> V_2 . V_356 = V_10 -> V_9 . V_23 . V_404 ;
V_402 = F_195 ( V_10 ) ;
if ( V_402 == V_405 )
V_10 -> V_17 . V_406 = true ;
return V_402 ;
}
static inline bool F_196 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_407 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_408 ) )
return false ;
if ( V_10 -> V_17 . V_406 )
return false ;
V_10 -> V_1 -> V_2 . V_393 = V_409 ;
V_10 -> V_1 -> V_2 . V_358 = 0 ;
V_10 -> V_1 -> V_2 . V_356 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_406 = true ;
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
V_10 -> V_1 -> V_2 . V_393 = V_410 ;
V_10 -> V_17 . V_406 = true ;
return false ;
}
static void * F_199 ( struct V_7 * V_10 , T_2 V_411 , struct V_137 * * V_412 )
{
struct V_137 * V_137 ;
F_200 () ;
V_137 = F_201 ( V_10 -> V_9 . V_264 , V_411 >> V_112 ) ;
if ( F_202 ( V_137 ) )
goto error;
* V_412 = V_137 ;
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
unsigned V_381 ;
T_4 V_81 , V_6 ;
T_2 V_411 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_213 ) ) )
return V_413 ;
V_381 = V_10 -> V_1 -> V_2 . V_358 >> 16 ;
V_411 = V_10 -> V_17 . V_414 + ( V_381 / 8 ) ;
V_6 = V_381 % 8 ;
V_81 = 0 ;
if ( F_209 ( V_10 -> V_9 . V_264 , V_411 , & V_81 , 1 ) )
V_81 &= ( 1 << V_6 ) ;
return V_81 ? V_405 : V_413 ;
}
static int F_210 ( struct V_7 * V_10 )
{
T_1 V_27 , V_26 , V_354 ;
int V_123 , V_49 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_214 ) ) )
return V_413 ;
V_26 = V_10 -> V_9 . V_23 . V_247 [ V_415 ] ;
V_27 = F_21 ( V_26 ) ;
V_123 = V_10 -> V_1 -> V_2 . V_358 & 1 ;
V_49 = 1 << ( ( 2 * ( V_26 & 0xf ) ) + V_123 ) ;
if ( V_27 == V_33 )
return V_405 ;
V_27 *= 4 ;
if ( F_209 ( V_10 -> V_9 . V_264 , V_10 -> V_17 . V_416 + V_27 , & V_354 , 4 ) )
return V_405 ;
return ( V_354 & V_49 ) ? V_405 : V_413 ;
}
static int F_211 ( struct V_7 * V_10 )
{
T_1 V_393 = V_10 -> V_1 -> V_2 . V_393 ;
switch ( V_393 ) {
case V_409 :
case V_410 :
case V_403 + V_203 :
return V_413 ;
case V_394 :
if ( V_39 )
return V_413 ;
break;
case V_403 + V_201 :
if ( ! V_39 && V_10 -> V_357 == 0 )
return V_413 ;
break;
case V_403 + V_374 :
F_168 ( V_10 ) ;
break;
default:
break;
}
return V_417 ;
}
static int F_195 ( struct V_7 * V_10 )
{
T_1 V_393 = V_10 -> V_1 -> V_2 . V_393 ;
int V_402 = V_413 ;
switch ( V_393 ) {
case V_418 :
V_402 = F_210 ( V_10 ) ;
break;
case V_419 :
V_402 = F_208 ( V_10 ) ;
break;
case V_420 ... V_421 : {
T_1 V_6 = 1U << ( V_393 - V_420 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_402 = V_405 ;
break;
}
case V_422 ... V_423 : {
T_1 V_6 = 1U << ( V_393 - V_422 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_402 = V_405 ;
break;
}
case V_403 ... V_403 + 0x1f : {
T_1 V_424 = 1 << ( V_393 - V_403 ) ;
if ( V_10 -> V_17 . V_21 & V_424 )
V_402 = V_405 ;
else if ( ( V_393 == V_403 + V_201 ) &&
V_10 -> V_357 != 0 )
V_402 = V_405 ;
break;
}
case V_425 : {
V_402 = V_405 ;
break;
}
default: {
T_2 V_426 = 1ULL << ( V_393 - V_409 ) ;
if ( V_10 -> V_17 . V_22 & V_426 )
V_402 = V_405 ;
}
}
return V_402 ;
}
static int F_212 ( struct V_7 * V_10 )
{
int V_402 ;
V_402 = F_195 ( V_10 ) ;
if ( V_402 == V_405 )
F_189 ( V_10 ) ;
return V_402 ;
}
static inline void F_213 ( struct V_1 * V_427 , struct V_1 * V_428 )
{
struct V_11 * V_429 = & V_427 -> V_2 ;
struct V_11 * V_430 = & V_428 -> V_2 ;
V_429 -> V_19 = V_430 -> V_19 ;
V_429 -> V_20 = V_430 -> V_20 ;
V_429 -> V_21 = V_430 -> V_21 ;
V_429 -> V_22 = V_430 -> V_22 ;
V_429 -> V_228 = V_430 -> V_228 ;
V_429 -> V_229 = V_430 -> V_229 ;
V_429 -> V_173 = V_430 -> V_173 ;
V_429 -> V_35 = V_430 -> V_35 ;
V_429 -> V_351 = V_430 -> V_351 ;
V_429 -> V_230 = V_430 -> V_230 ;
V_429 -> V_431 = V_430 -> V_431 ;
V_429 -> V_51 = V_430 -> V_51 ;
V_429 -> V_393 = V_430 -> V_393 ;
V_429 -> V_395 = V_430 -> V_395 ;
V_429 -> V_358 = V_430 -> V_358 ;
V_429 -> V_356 = V_430 -> V_356 ;
V_429 -> V_432 = V_430 -> V_432 ;
V_429 -> V_433 = V_430 -> V_433 ;
V_429 -> V_255 = V_430 -> V_255 ;
V_429 -> V_74 = V_430 -> V_74 ;
V_429 -> V_77 = V_430 -> V_77 ;
V_429 -> V_388 = V_430 -> V_388 ;
V_429 -> V_132 = V_430 -> V_132 ;
}
static int F_189 ( struct V_7 * V_10 )
{
struct V_1 * V_434 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_137 * V_137 ;
F_214 ( V_1 -> V_2 . V_393 ,
V_1 -> V_2 . V_358 ,
V_1 -> V_2 . V_356 ,
V_1 -> V_2 . V_432 ,
V_1 -> V_2 . V_433 ) ;
V_434 = F_199 ( V_10 , V_10 -> V_17 . V_1 , & V_137 ) ;
if ( ! V_434 )
return 1 ;
F_215 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_434 -> V_42 . V_232 = V_1 -> V_42 . V_232 ;
V_434 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_434 -> V_42 . V_233 = V_1 -> V_42 . V_233 ;
V_434 -> V_42 . V_234 = V_1 -> V_42 . V_234 ;
V_434 -> V_42 . V_239 = V_1 -> V_42 . V_239 ;
V_434 -> V_42 . V_240 = V_1 -> V_42 . V_240 ;
V_434 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_434 -> V_42 . V_249 = F_216 ( & V_10 -> V_9 ) ;
V_434 -> V_42 . V_257 = F_129 ( & V_10 -> V_9 ) ;
V_434 -> V_42 . V_404 = V_1 -> V_42 . V_404 ;
V_434 -> V_42 . V_253 = V_10 -> V_9 . V_23 . V_253 ;
V_434 -> V_42 . V_293 = F_217 ( & V_10 -> V_9 ) ;
V_434 -> V_42 . V_68 = V_1 -> V_42 . V_68 ;
V_434 -> V_42 . V_435 = V_1 -> V_42 . V_435 ;
V_434 -> V_42 . V_436 = V_1 -> V_42 . V_436 ;
V_434 -> V_42 . V_246 = V_1 -> V_42 . V_246 ;
V_434 -> V_42 . V_245 = V_1 -> V_42 . V_245 ;
V_434 -> V_42 . V_324 = V_1 -> V_42 . V_324 ;
V_434 -> V_2 . V_230 = V_1 -> V_2 . V_230 ;
V_434 -> V_2 . V_431 = V_1 -> V_2 . V_431 ;
V_434 -> V_2 . V_51 = V_1 -> V_2 . V_51 ;
V_434 -> V_2 . V_393 = V_1 -> V_2 . V_393 ;
V_434 -> V_2 . V_395 = V_1 -> V_2 . V_395 ;
V_434 -> V_2 . V_358 = V_1 -> V_2 . V_358 ;
V_434 -> V_2 . V_356 = V_1 -> V_2 . V_356 ;
V_434 -> V_2 . V_432 = V_1 -> V_2 . V_432 ;
V_434 -> V_2 . V_433 = V_1 -> V_2 . V_433 ;
V_434 -> V_2 . V_55 = V_1 -> V_2 . V_55 ;
if ( V_1 -> V_2 . V_74 & V_47 ) {
struct V_11 * V_437 = & V_434 -> V_2 ;
V_437 -> V_432 = V_1 -> V_2 . V_74 ;
V_437 -> V_433 = V_1 -> V_2 . V_77 ;
}
V_434 -> V_2 . V_351 = 0 ;
V_434 -> V_2 . V_74 = 0 ;
V_434 -> V_2 . V_77 = 0 ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_407 ) )
V_434 -> V_2 . V_230 &= ~ V_231 ;
F_213 ( V_1 , V_18 ) ;
F_218 ( & V_10 -> V_9 ) ;
F_219 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_388 = 0 ;
V_10 -> V_1 -> V_42 . V_232 = V_18 -> V_42 . V_232 ;
V_10 -> V_1 -> V_42 . V_71 = V_18 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_233 = V_18 -> V_42 . V_233 ;
V_10 -> V_1 -> V_42 . V_234 = V_18 -> V_42 . V_234 ;
V_10 -> V_1 -> V_42 . V_239 = V_18 -> V_42 . V_239 ;
V_10 -> V_1 -> V_42 . V_240 = V_18 -> V_42 . V_240 ;
F_101 ( & V_10 -> V_9 , V_18 -> V_42 . V_293 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_42 . V_38 ) ;
F_144 ( & V_10 -> V_9 , V_18 -> V_42 . V_249 | V_438 ) ;
F_146 ( & V_10 -> V_9 , V_18 -> V_42 . V_253 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_257 = V_18 -> V_42 . V_257 ;
V_10 -> V_9 . V_23 . V_257 = V_18 -> V_42 . V_257 ;
} else {
( void ) F_220 ( & V_10 -> V_9 , V_18 -> V_42 . V_257 ) ;
}
F_221 ( & V_10 -> V_9 , V_439 , V_18 -> V_42 . V_436 ) ;
F_221 ( & V_10 -> V_9 , V_440 , V_18 -> V_42 . V_435 ) ;
F_221 ( & V_10 -> V_9 , V_248 , V_18 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_246 = 0 ;
V_10 -> V_1 -> V_42 . V_324 = 0 ;
V_10 -> V_1 -> V_2 . V_432 = 0 ;
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
T_1 V_354 , V_441 ;
T_2 V_27 ;
if ( V_131 [ V_28 ] == 0xffffffff )
break;
V_441 = V_131 [ V_28 ] ;
V_27 = V_10 -> V_17 . V_416 + ( V_441 * 4 ) ;
if ( F_209 ( V_10 -> V_9 . V_264 , V_27 , & V_354 , 4 ) )
return false ;
V_10 -> V_17 . V_121 [ V_441 ] = V_10 -> V_121 [ V_441 ] | V_354 ;
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
struct V_1 * V_434 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_137 * V_137 ;
T_2 V_442 ;
V_442 = V_10 -> V_1 -> V_42 . V_436 ;
V_434 = F_199 ( V_10 , V_10 -> V_1 -> V_42 . V_436 , & V_137 ) ;
if ( ! V_434 )
return false ;
if ( ! F_225 ( V_434 ) ) {
V_434 -> V_2 . V_393 = V_425 ;
V_434 -> V_2 . V_395 = 0 ;
V_434 -> V_2 . V_358 = 0 ;
V_434 -> V_2 . V_356 = 0 ;
F_205 ( V_137 ) ;
return false ;
}
F_227 ( V_10 -> V_1 -> V_42 . V_68 , V_442 ,
V_434 -> V_42 . V_68 ,
V_434 -> V_2 . V_230 ,
V_434 -> V_2 . V_74 ,
V_434 -> V_2 . V_255 ) ;
F_228 ( V_434 -> V_2 . V_19 & 0xffff ,
V_434 -> V_2 . V_19 >> 16 ,
V_434 -> V_2 . V_21 ,
V_434 -> V_2 . V_22 ) ;
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
V_18 -> V_42 . V_435 = V_1 -> V_42 . V_435 ;
V_18 -> V_42 . V_436 = V_1 -> V_42 . V_436 ;
if ( V_39 )
V_18 -> V_42 . V_257 = V_1 -> V_42 . V_257 ;
else
V_18 -> V_42 . V_257 = F_129 ( & V_10 -> V_9 ) ;
F_213 ( V_18 , V_1 ) ;
if ( F_217 ( & V_10 -> V_9 ) & V_443 )
V_10 -> V_9 . V_23 . V_24 |= V_408 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_408 ;
if ( V_434 -> V_2 . V_255 ) {
F_229 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_388 = V_434 -> V_2 . V_388 ;
F_190 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_42 . V_232 = V_434 -> V_42 . V_232 ;
V_10 -> V_1 -> V_42 . V_71 = V_434 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_233 = V_434 -> V_42 . V_233 ;
V_10 -> V_1 -> V_42 . V_234 = V_434 -> V_42 . V_234 ;
V_10 -> V_1 -> V_42 . V_239 = V_434 -> V_42 . V_239 ;
V_10 -> V_1 -> V_42 . V_240 = V_434 -> V_42 . V_240 ;
F_101 ( & V_10 -> V_9 , V_434 -> V_42 . V_293 ) ;
F_27 ( & V_10 -> V_9 , V_434 -> V_42 . V_38 ) ;
F_144 ( & V_10 -> V_9 , V_434 -> V_42 . V_249 ) ;
F_146 ( & V_10 -> V_9 , V_434 -> V_42 . V_253 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_257 = V_434 -> V_42 . V_257 ;
V_10 -> V_9 . V_23 . V_257 = V_434 -> V_42 . V_257 ;
} else
( void ) F_220 ( & V_10 -> V_9 , V_434 -> V_42 . V_257 ) ;
F_222 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_42 . V_404 = V_10 -> V_9 . V_23 . V_404 = V_434 -> V_42 . V_404 ;
F_221 ( & V_10 -> V_9 , V_439 , V_434 -> V_42 . V_436 ) ;
F_221 ( & V_10 -> V_9 , V_440 , V_434 -> V_42 . V_435 ) ;
F_221 ( & V_10 -> V_9 , V_248 , V_434 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_436 = V_434 -> V_42 . V_436 ;
V_10 -> V_1 -> V_42 . V_435 = V_434 -> V_42 . V_435 ;
V_10 -> V_1 -> V_42 . V_68 = V_434 -> V_42 . V_68 ;
V_10 -> V_1 -> V_42 . V_246 = V_434 -> V_42 . V_246 ;
V_10 -> V_1 -> V_42 . V_245 = V_434 -> V_42 . V_245 ;
V_10 -> V_1 -> V_42 . V_324 = V_434 -> V_42 . V_324 ;
V_10 -> V_17 . V_416 = V_434 -> V_2 . V_229 & ~ 0x0fffULL ;
V_10 -> V_17 . V_414 = V_434 -> V_2 . V_228 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_434 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_434 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_434 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_434 -> V_2 . V_22 ;
F_148 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_230 = V_434 -> V_2 . V_230 | V_231 ;
if ( V_434 -> V_2 . V_230 & V_231 )
V_10 -> V_9 . V_23 . V_24 |= V_407 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_407 ;
if ( V_10 -> V_9 . V_23 . V_24 & V_407 ) {
F_10 ( V_10 , V_444 ) ;
F_10 ( V_10 , V_184 ) ;
}
F_17 ( V_10 , V_218 ) ;
V_10 -> V_1 -> V_2 . V_132 = V_434 -> V_2 . V_132 ;
V_10 -> V_1 -> V_2 . V_431 = V_434 -> V_2 . V_431 ;
V_10 -> V_1 -> V_2 . V_51 = V_434 -> V_2 . V_51 ;
V_10 -> V_1 -> V_2 . V_173 += V_434 -> V_2 . V_173 ;
V_10 -> V_1 -> V_2 . V_74 = V_434 -> V_2 . V_74 ;
V_10 -> V_1 -> V_2 . V_77 = V_434 -> V_2 . V_77 ;
F_205 ( V_137 ) ;
F_230 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_442 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_231 ( struct V_1 * V_428 , struct V_1 * V_445 )
{
V_445 -> V_42 . V_235 = V_428 -> V_42 . V_235 ;
V_445 -> V_42 . V_236 = V_428 -> V_42 . V_236 ;
V_445 -> V_42 . V_243 = V_428 -> V_42 . V_243 ;
V_445 -> V_42 . V_241 = V_428 -> V_42 . V_241 ;
V_445 -> V_42 . V_446 = V_428 -> V_42 . V_446 ;
V_445 -> V_42 . V_447 = V_428 -> V_42 . V_447 ;
V_445 -> V_42 . V_448 = V_428 -> V_42 . V_448 ;
V_445 -> V_42 . V_449 = V_428 -> V_42 . V_449 ;
V_445 -> V_42 . V_450 = V_428 -> V_42 . V_450 ;
V_445 -> V_42 . V_451 = V_428 -> V_42 . V_451 ;
V_445 -> V_42 . V_452 = V_428 -> V_42 . V_452 ;
V_445 -> V_42 . V_453 = V_428 -> V_42 . V_453 ;
}
static int F_232 ( struct V_7 * V_10 )
{
struct V_1 * V_434 ;
struct V_137 * V_137 ;
if ( F_193 ( V_10 ) )
return 1 ;
V_434 = F_199 ( V_10 , V_10 -> V_1 -> V_42 . V_436 , & V_137 ) ;
if ( ! V_434 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_231 ( V_434 , V_10 -> V_1 ) ;
F_205 ( V_137 ) ;
return 1 ;
}
static int F_233 ( struct V_7 * V_10 )
{
struct V_1 * V_434 ;
struct V_137 * V_137 ;
if ( F_193 ( V_10 ) )
return 1 ;
V_434 = F_199 ( V_10 , V_10 -> V_1 -> V_42 . V_436 , & V_137 ) ;
if ( ! V_434 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_231 ( V_10 -> V_1 , V_434 ) ;
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
goto V_454;
return 1 ;
V_454:
V_10 -> V_1 -> V_2 . V_393 = V_425 ;
V_10 -> V_1 -> V_2 . V_395 = 0 ;
V_10 -> V_1 -> V_2 . V_358 = 0 ;
V_10 -> V_1 -> V_2 . V_356 = 0 ;
F_189 ( V_10 ) ;
return 1 ;
}
static int F_235 ( struct V_7 * V_10 )
{
if ( F_193 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_174 ( V_455 , & V_10 -> V_9 ) ;
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
V_10 -> V_1 -> V_2 . V_230 &= ~ V_456 ;
F_3 ( V_10 -> V_1 , V_457 ) ;
return 1 ;
}
static int F_237 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_238 ( V_10 -> V_1 -> V_42 . V_68 , V_9 -> V_23 . V_247 [ V_415 ] ,
V_9 -> V_23 . V_247 [ V_439 ] ) ;
F_239 ( V_9 , V_9 -> V_23 . V_247 [ V_439 ] ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_240 ( struct V_7 * V_10 )
{
F_241 ( V_10 -> V_1 -> V_42 . V_68 , V_10 -> V_9 . V_23 . V_247 [ V_439 ] ) ;
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static int F_242 ( struct V_7 * V_10 )
{
T_2 V_458 = F_243 ( & V_10 -> V_9 ) ;
T_1 V_119 = F_244 ( & V_10 -> V_9 , V_415 ) ;
if ( F_245 ( & V_10 -> V_9 , V_119 , V_458 ) == 0 ) {
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
T_10 V_459 ;
int V_460 ;
int V_461 = V_10 -> V_1 -> V_2 . V_432 &
V_462 ;
int V_463 = V_10 -> V_1 -> V_2 . V_432 & V_464 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_432 & V_462 ;
T_7 V_465 =
V_10 -> V_1 -> V_2 . V_432 & V_466 ;
bool V_63 = false ;
T_1 V_64 = 0 ;
V_459 = ( T_10 ) V_10 -> V_1 -> V_2 . V_358 ;
if ( V_10 -> V_1 -> V_2 . V_356 &
( 1ULL << V_467 ) )
V_460 = V_468 ;
else if ( V_10 -> V_1 -> V_2 . V_356 &
( 1ULL << V_469 ) )
V_460 = V_470 ;
else if ( V_465 )
V_460 = V_471 ;
else
V_460 = V_472 ;
if ( V_460 == V_471 ) {
switch ( type ) {
case V_473 :
V_10 -> V_9 . V_23 . V_474 = false ;
break;
case V_475 :
if ( V_10 -> V_1 -> V_2 . V_356 &
( 1ULL << V_476 ) ) {
V_63 = true ;
V_64 =
( T_1 ) V_10 -> V_1 -> V_2 . V_356 ;
}
F_218 ( & V_10 -> V_9 ) ;
break;
case V_477 :
F_219 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_460 != V_471 ||
V_461 == V_478 ||
( V_461 == V_475 &&
( V_463 == V_479 || V_463 == V_66 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( F_248 ( & V_10 -> V_9 , V_459 , V_460 ,
V_63 , V_64 ) == V_480 ) {
V_10 -> V_9 . V_364 -> V_367 = V_481 ;
V_10 -> V_9 . V_364 -> V_482 . V_483 = V_484 ;
V_10 -> V_9 . V_364 -> V_482 . V_485 = 0 ;
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
++ V_10 -> V_9 . V_288 . V_486 ;
F_17 ( V_10 , V_487 ) ;
V_10 -> V_9 . V_23 . V_24 |= V_488 ;
V_10 -> V_489 = F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_252 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_490 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
F_239 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_358 ) ;
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
V_10 -> V_1 -> V_2 . V_393 = V_491 ;
V_50 = ( F_212 ( V_10 ) == V_405 ) ;
}
return V_50 ;
}
static int F_255 ( struct V_7 * V_10 )
{
int V_295 , V_492 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_38 ( V_490 ) )
return F_253 ( V_10 ) ;
if ( F_117 ( ( V_10 -> V_1 -> V_2 . V_358 & V_493 ) == 0 ) )
return F_253 ( V_10 ) ;
V_295 = V_10 -> V_1 -> V_2 . V_358 & V_494 ;
V_492 = V_10 -> V_1 -> V_2 . V_393 - V_420 ;
V_80 = 0 ;
if ( V_492 >= 16 ) {
V_492 -= 16 ;
V_81 = F_244 ( & V_10 -> V_9 , V_295 ) ;
switch ( V_492 ) {
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
F_258 ( 1 , L_11 , V_492 ) ;
F_164 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
} else {
switch ( V_492 ) {
case 0 :
V_81 = F_216 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_81 = V_10 -> V_9 . V_23 . V_404 ;
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
F_258 ( 1 , L_12 , V_492 ) ;
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
int V_295 , V_495 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_79 ( V_490 ) )
return F_253 ( V_10 ) ;
V_295 = V_10 -> V_1 -> V_2 . V_358 & V_494 ;
V_495 = V_10 -> V_1 -> V_2 . V_393 - V_422 ;
if ( V_495 >= 16 ) {
V_81 = F_244 ( & V_10 -> V_9 , V_295 ) ;
F_263 ( & V_10 -> V_9 , V_495 - 16 , V_81 ) ;
} else {
V_80 = F_264 ( & V_10 -> V_9 , V_495 , & V_81 ) ;
if ( ! V_80 )
F_221 ( & V_10 -> V_9 , V_295 , V_81 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_265 ( struct V_7 * V_10 )
{
struct V_363 * V_363 = V_10 -> V_9 . V_364 ;
int V_115 ;
T_4 V_496 = F_260 ( & V_10 -> V_9 ) ;
V_115 = F_255 ( V_10 ) ;
if ( F_266 ( V_10 -> V_9 . V_264 ) ) {
F_10 ( V_10 , V_184 ) ;
return V_115 ;
}
if ( V_496 <= F_260 ( & V_10 -> V_9 ) )
return V_115 ;
V_363 -> V_367 = V_497 ;
return 0 ;
}
static int F_267 ( struct V_8 * V_9 , unsigned V_498 , T_2 * V_499 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_498 ) {
case V_500 : {
struct V_1 * V_1 = F_8 ( V_10 ) ;
* V_499 = V_1 -> V_2 . V_173 +
F_91 ( V_9 , F_98 () ) ;
break;
}
case V_501 :
* V_499 = V_10 -> V_1 -> V_42 . V_447 ;
break;
#ifdef F_26
case V_502 :
* V_499 = V_10 -> V_1 -> V_42 . V_448 ;
break;
case V_503 :
* V_499 = V_10 -> V_1 -> V_42 . V_449 ;
break;
case V_290 :
* V_499 = V_10 -> V_1 -> V_42 . V_446 ;
break;
case V_504 :
* V_499 = V_10 -> V_1 -> V_42 . V_450 ;
break;
#endif
case V_505 :
* V_499 = V_10 -> V_1 -> V_42 . V_451 ;
break;
case V_506 :
* V_499 = V_10 -> V_453 ;
break;
case V_507 :
* V_499 = V_10 -> V_452 ;
break;
case V_508 :
* V_499 = V_10 -> V_1 -> V_42 . V_509 ;
break;
case V_133 :
* V_499 = V_10 -> V_1 -> V_42 . V_510 ;
break;
case V_134 :
* V_499 = V_10 -> V_1 -> V_42 . V_511 ;
break;
case V_135 :
* V_499 = V_10 -> V_1 -> V_42 . V_512 ;
break;
case V_136 :
* V_499 = V_10 -> V_1 -> V_42 . V_513 ;
break;
case V_110 :
* V_499 = V_10 -> V_17 . V_514 ;
break;
case V_515 :
* V_499 = V_10 -> V_17 . V_516 ;
break;
case V_517 :
* V_499 = 0x01000065 ;
break;
default:
return F_268 ( V_9 , V_498 , V_499 ) ;
}
return 0 ;
}
static int F_269 ( struct V_7 * V_10 )
{
T_1 V_498 = V_10 -> V_9 . V_23 . V_247 [ V_415 ] ;
T_2 V_499 ;
if ( F_267 ( & V_10 -> V_9 , V_498 , & V_499 ) ) {
F_270 ( V_498 ) ;
F_194 ( & V_10 -> V_9 , 0 ) ;
} else {
F_271 ( V_498 , V_499 ) ;
V_10 -> V_9 . V_23 . V_247 [ V_439 ] = V_499 & 0xffffffff ;
V_10 -> V_9 . V_23 . V_247 [ V_518 ] = V_499 >> 32 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_272 ( struct V_8 * V_9 , T_2 V_499 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_519 , V_520 ;
if ( V_499 & ~ V_521 )
return 1 ;
V_520 = V_521 ;
if ( V_10 -> V_17 . V_516 & V_522 )
V_520 &= ~ ( V_523 | V_522 ) ;
V_10 -> V_17 . V_516 &= ~ V_520 ;
V_10 -> V_17 . V_516 |= ( V_499 & V_520 ) ;
V_519 = V_10 -> V_17 . V_516 & V_522 ;
if ( V_519 && ( V_9 -> V_23 . V_38 & V_43 ) )
return 1 ;
return 0 ;
}
static int F_273 ( struct V_8 * V_9 , unsigned V_498 , T_2 V_499 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_498 ) {
case V_500 :
F_109 ( V_9 , V_499 ) ;
break;
case V_501 :
V_10 -> V_1 -> V_42 . V_447 = V_499 ;
break;
#ifdef F_26
case V_502 :
V_10 -> V_1 -> V_42 . V_448 = V_499 ;
break;
case V_503 :
V_10 -> V_1 -> V_42 . V_449 = V_499 ;
break;
case V_290 :
V_10 -> V_1 -> V_42 . V_446 = V_499 ;
break;
case V_504 :
V_10 -> V_1 -> V_42 . V_450 = V_499 ;
break;
#endif
case V_505 :
V_10 -> V_1 -> V_42 . V_451 = V_499 ;
break;
case V_506 :
V_10 -> V_453 = V_499 ;
V_10 -> V_1 -> V_42 . V_453 = V_499 ;
break;
case V_507 :
V_10 -> V_452 = V_499 ;
V_10 -> V_1 -> V_42 . V_452 = V_499 ;
break;
case V_508 :
if ( ! F_79 ( V_524 ) ) {
F_274 ( V_9 , L_13 ,
V_59 , V_499 ) ;
break;
}
if ( V_499 & V_525 )
return 1 ;
V_10 -> V_1 -> V_42 . V_509 = V_499 ;
F_3 ( V_10 -> V_1 , V_526 ) ;
if ( V_499 & ( 1ULL << 0 ) )
F_74 ( V_10 ) ;
else
F_75 ( V_10 ) ;
break;
case V_110 :
V_10 -> V_17 . V_514 = V_499 ;
break;
case V_515 :
return F_272 ( V_9 , V_499 ) ;
case V_527 :
F_274 ( V_9 , L_14 , V_498 , V_499 ) ;
break;
default:
return F_275 ( V_9 , V_498 , V_499 ) ;
}
return 0 ;
}
static int F_276 ( struct V_7 * V_10 )
{
T_1 V_498 = V_10 -> V_9 . V_23 . V_247 [ V_415 ] ;
T_2 V_499 = ( V_10 -> V_9 . V_23 . V_247 [ V_439 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_23 . V_247 [ V_518 ] & - 1u ) << 32 ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_273 ( & V_10 -> V_9 , V_498 , V_499 ) ) {
F_277 ( V_498 , V_499 ) ;
F_194 ( & V_10 -> V_9 , 0 ) ;
} else {
F_278 ( V_498 , V_499 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_279 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_358 )
return F_276 ( V_10 ) ;
else
return F_269 ( V_10 ) ;
}
static int F_280 ( struct V_7 * V_10 )
{
struct V_363 * V_363 = V_10 -> V_9 . V_364 ;
F_174 ( V_455 , & V_10 -> V_9 ) ;
F_131 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_230 &= ~ V_456 ;
F_3 ( V_10 -> V_1 , V_457 ) ;
if ( ! F_266 ( V_10 -> V_9 . V_264 ) &&
V_363 -> V_528 &&
! F_281 ( & V_10 -> V_9 ) ) {
++ V_10 -> V_9 . V_288 . V_529 ;
V_363 -> V_367 = V_530 ;
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
F_173 ( L_25 , L_31 , V_2 -> V_351 ) ;
F_173 ( L_21 , L_32 , V_2 -> V_230 ) ;
F_173 ( L_21 , L_33 , V_2 -> V_431 ) ;
F_173 ( L_21 , L_34 , V_2 -> V_51 ) ;
F_173 ( L_21 , L_35 , V_2 -> V_393 ) ;
F_173 ( L_23 , L_36 , V_2 -> V_358 ) ;
F_173 ( L_23 , L_37 , V_2 -> V_356 ) ;
F_173 ( L_21 , L_38 , V_2 -> V_432 ) ;
F_173 ( L_21 , L_39 , V_2 -> V_433 ) ;
F_173 ( L_40 , L_41 , V_2 -> V_255 ) ;
F_173 ( L_23 , L_42 , V_2 -> V_388 ) ;
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
L_61 , V_42 -> V_249 , L_62 , V_42 -> V_404 ) ;
F_173 ( L_60 ,
L_63 , V_42 -> V_257 , L_64 , V_42 -> V_253 ) ;
F_173 ( L_60 ,
L_65 , V_42 -> V_245 , L_66 , V_42 -> V_246 ) ;
F_173 ( L_60 ,
L_67 , V_42 -> V_68 , L_68 , V_42 -> V_293 ) ;
F_173 ( L_60 ,
L_69 , V_42 -> V_435 , L_70 , V_42 -> V_436 ) ;
F_173 ( L_60 ,
L_71 , V_42 -> V_447 , L_72 , V_42 -> V_448 ) ;
F_173 ( L_60 ,
L_73 , V_42 -> V_449 , L_74 , V_42 -> V_450 ) ;
F_173 ( L_60 ,
L_75 , V_42 -> V_446 ,
L_76 , V_42 -> V_451 ) ;
F_173 ( L_60 ,
L_77 , V_42 -> V_452 ,
L_78 , V_42 -> V_453 ) ;
F_173 ( L_60 ,
L_79 , V_42 -> V_256 , L_80 , V_42 -> V_509 ) ;
F_173 ( L_60 ,
L_81 , V_42 -> V_510 , L_82 , V_42 -> V_511 ) ;
F_173 ( L_60 ,
L_83 , V_42 -> V_512 ,
L_84 , V_42 -> V_513 ) ;
}
static void F_285 ( struct V_8 * V_9 , T_2 * V_531 , T_2 * V_532 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_531 = V_2 -> V_358 ;
* V_532 = V_2 -> V_356 ;
}
static int F_286 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_363 * V_363 = V_9 -> V_364 ;
T_1 V_393 = V_10 -> V_1 -> V_2 . V_393 ;
F_287 ( V_393 , V_9 , V_533 ) ;
if ( ! F_11 ( V_10 , V_181 ) )
V_9 -> V_23 . V_249 = V_10 -> V_1 -> V_42 . V_249 ;
if ( V_39 )
V_9 -> V_23 . V_257 = V_10 -> V_1 -> V_42 . V_257 ;
if ( F_117 ( V_10 -> V_17 . V_406 ) ) {
F_189 ( V_10 ) ;
V_10 -> V_17 . V_406 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_402 ;
F_288 ( V_10 -> V_1 -> V_42 . V_68 , V_393 ,
V_10 -> V_1 -> V_2 . V_358 ,
V_10 -> V_1 -> V_2 . V_356 ,
V_10 -> V_1 -> V_2 . V_432 ,
V_10 -> V_1 -> V_2 . V_433 ) ;
V_402 = F_211 ( V_10 ) ;
if ( V_402 == V_417 )
V_402 = F_212 ( V_10 ) ;
if ( V_402 == V_405 )
return 1 ;
}
F_289 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_393 == V_425 ) {
V_363 -> V_367 = V_534 ;
V_363 -> V_535 . V_536
= V_10 -> V_1 -> V_2 . V_393 ;
F_173 ( L_85 ) ;
F_284 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_432 ) &&
V_393 != V_403 + V_201 &&
V_393 != V_394 && V_393 != V_537 &&
V_393 != V_409 && V_393 != V_410 )
F_33 ( V_61 L_86
L_87 ,
V_59 , V_10 -> V_1 -> V_2 . V_432 ,
V_393 ) ;
if ( V_393 >= F_290 ( V_538 )
|| ! V_538 [ V_393 ] ) {
V_363 -> V_367 = V_539 ;
V_363 -> V_540 . V_541 = V_393 ;
return 0 ;
}
return V_538 [ V_393 ] ( V_10 ) ;
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
V_10 -> V_1 -> V_2 . V_74 = V_47 | V_542 ;
V_9 -> V_23 . V_24 |= V_543 ;
F_16 ( V_10 , V_487 ) ;
++ V_9 -> V_288 . V_544 ;
}
static inline void F_295 ( struct V_7 * V_10 , int V_545 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_431 = V_545 ;
V_2 -> V_230 &= ~ V_546 ;
V_2 -> V_230 |= V_456 |
( ( 0xf ) << V_547 ) ;
F_3 ( V_10 -> V_1 , V_457 ) ;
}
static void F_296 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_67 ( ! ( F_20 ( V_10 ) ) ) ;
F_297 ( V_9 -> V_23 . V_548 . V_62 ) ;
++ V_9 -> V_288 . V_549 ;
V_10 -> V_1 -> V_2 . V_74 = V_9 -> V_23 . V_548 . V_62 |
V_47 | V_48 ;
}
static void F_298 ( struct V_8 * V_9 , int V_550 , int V_551 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_407 ) )
return;
if ( V_551 == - 1 )
return;
if ( V_550 >= V_551 )
F_9 ( V_10 , V_184 ) ;
}
static int F_299 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
V_50 = ! ( V_1 -> V_2 . V_51 & V_52 ) &&
! ( V_10 -> V_9 . V_23 . V_24 & V_543 ) ;
V_50 = V_50 && F_20 ( V_10 ) && F_198 ( V_10 ) ;
return V_50 ;
}
static bool F_300 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_543 ) ;
}
static void F_301 ( struct V_8 * V_9 , bool V_552 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_552 ) {
V_10 -> V_9 . V_23 . V_24 |= V_543 ;
F_16 ( V_10 , V_487 ) ;
} else {
V_10 -> V_9 . V_23 . V_24 &= ~ V_543 ;
F_17 ( V_10 , V_487 ) ;
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
V_50 = ! ! ( F_217 ( V_9 ) & V_443 ) ;
if ( F_7 ( V_9 ) )
return V_50 && ! ( V_10 -> V_9 . V_23 . V_24 & V_407 ) ;
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
if ( ( V_10 -> V_9 . V_23 . V_24 & ( V_543 | V_488 ) )
== V_543 )
return;
V_10 -> V_341 = true ;
V_10 -> V_1 -> V_42 . V_293 |= ( V_365 | V_366 ) ;
F_150 ( V_9 ) ;
}
static int F_305 ( struct V_264 * V_264 , unsigned int V_34 )
{
return 0 ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_553 ) )
V_10 -> V_1 -> V_2 . V_351 = V_554 ;
else
V_10 -> V_102 -- ;
}
static void F_306 ( struct V_8 * V_9 )
{
}
static inline void F_307 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_407 ) )
return;
if ( ! F_11 ( V_10 , V_184 ) ) {
int V_555 = V_10 -> V_1 -> V_2 . V_230 & V_556 ;
F_257 ( V_9 , V_555 ) ;
}
}
static inline void F_308 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_555 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_407 ) )
return;
V_555 = F_260 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_230 &= ~ V_556 ;
V_10 -> V_1 -> V_2 . V_230 |= V_555 & V_556 ;
}
static void F_289 ( struct V_7 * V_10 )
{
T_4 V_557 ;
int type ;
T_1 V_558 = V_10 -> V_1 -> V_2 . V_432 ;
unsigned V_73 = V_10 -> V_73 ;
V_10 -> V_73 = 0 ;
if ( ( V_10 -> V_9 . V_23 . V_24 & V_488 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_489 ) {
V_10 -> V_9 . V_23 . V_24 &= ~ ( V_543 | V_488 ) ;
F_174 ( V_455 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_23 . V_474 = false ;
F_218 ( & V_10 -> V_9 ) ;
F_219 ( & V_10 -> V_9 ) ;
if ( ! ( V_558 & V_466 ) )
return;
F_174 ( V_455 , & V_10 -> V_9 ) ;
V_557 = V_558 & V_559 ;
type = V_558 & V_462 ;
switch ( type ) {
case V_473 :
V_10 -> V_9 . V_23 . V_474 = true ;
break;
case V_475 :
if ( F_309 ( V_557 ) ) {
if ( V_557 == V_66 && V_73 &&
F_310 ( & V_10 -> V_9 , V_10 -> V_70 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_73 ) ;
break;
}
if ( V_558 & V_560 ) {
T_1 V_80 = V_10 -> V_1 -> V_2 . V_433 ;
F_311 ( & V_10 -> V_9 , V_557 , V_80 ) ;
} else
F_312 ( & V_10 -> V_9 , V_557 ) ;
break;
case V_477 :
F_313 ( & V_10 -> V_9 , V_557 , false ) ;
break;
default:
break;
}
}
static void F_314 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_432 = V_2 -> V_74 ;
V_2 -> V_433 = V_2 -> V_77 ;
V_2 -> V_74 = 0 ;
F_289 ( V_10 ) ;
}
static void F_315 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_436 = V_9 -> V_23 . V_247 [ V_439 ] ;
V_10 -> V_1 -> V_42 . V_435 = V_9 -> V_23 . V_247 [ V_440 ] ;
V_10 -> V_1 -> V_42 . V_68 = V_9 -> V_23 . V_247 [ V_248 ] ;
if ( F_117 ( V_10 -> V_17 . V_406 ) )
return;
F_293 ( V_10 ) ;
F_308 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_404 = V_9 -> V_23 . V_404 ;
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
V_9 -> V_23 . V_404 = V_10 -> V_1 -> V_42 . V_404 ;
V_9 -> V_23 . V_247 [ V_439 ] = V_10 -> V_1 -> V_42 . V_436 ;
V_9 -> V_23 . V_247 [ V_440 ] = V_10 -> V_1 -> V_42 . V_435 ;
V_9 -> V_23 . V_247 [ V_248 ] = V_10 -> V_1 -> V_42 . V_68 ;
if ( F_117 ( V_10 -> V_1 -> V_2 . V_393 == V_410 ) )
F_316 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_117 ( V_10 -> V_1 -> V_2 . V_393 == V_410 ) )
F_317 ( & V_10 -> V_9 ) ;
F_307 ( V_9 ) ;
V_10 -> V_55 = 0 ;
V_10 -> V_1 -> V_2 . V_351 = V_561 ;
if ( V_10 -> V_1 -> V_2 . V_393 == V_403 + V_201 )
V_10 -> V_357 = F_318 () ;
if ( V_39 ) {
V_9 -> V_23 . V_262 &= ~ ( 1 << V_296 ) ;
V_9 -> V_23 . V_263 &= ~ ( 1 << V_296 ) ;
}
if ( F_117 ( V_10 -> V_1 -> V_2 . V_393 ==
V_403 + V_203 ) )
F_172 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_319 ( struct V_8 * V_9 , unsigned long V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_257 = V_389 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_148 ( V_9 ) ;
}
static void F_320 ( struct V_8 * V_9 , unsigned long V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_388 = V_389 ;
F_3 ( V_10 -> V_1 , V_390 ) ;
V_10 -> V_1 -> V_42 . V_257 = F_129 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_148 ( V_9 ) ;
}
static int F_321 ( void )
{
T_2 V_562 ;
F_52 ( V_515 , V_562 ) ;
if ( V_562 & ( 1 << V_563 ) )
return 1 ;
return 0 ;
}
static void
F_322 ( struct V_8 * V_9 , unsigned char * V_564 )
{
V_564 [ 0 ] = 0x0f ;
V_564 [ 1 ] = 0x01 ;
V_564 [ 2 ] = 0xd9 ;
}
static void F_323 ( void * V_565 )
{
* ( int * ) V_565 = 0 ;
}
static bool F_324 ( void )
{
return false ;
}
static T_2 F_325 ( struct V_8 * V_9 , T_11 V_566 , bool V_567 )
{
return 0 ;
}
static void F_326 ( struct V_8 * V_9 )
{
}
static void F_327 ( T_1 V_568 , struct V_569 * V_570 )
{
switch ( V_568 ) {
case 0x80000001 :
if ( V_17 )
V_570 -> V_498 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_570 -> V_571 = 1 ;
V_570 -> V_572 = 8 ;
V_570 -> V_498 = 0 ;
V_570 -> V_573 = 0 ;
if ( F_79 ( V_67 ) )
V_570 -> V_573 |= V_574 ;
if ( V_39 )
V_570 -> V_573 |= V_575 ;
break;
}
}
static int F_328 ( void )
{
return V_576 ;
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
F_14 ( V_10 , V_374 ) ;
F_143 ( V_10 ) ;
}
static int F_332 ( struct V_8 * V_9 ,
struct V_577 * V_45 ,
enum V_578 V_579 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_402 , V_50 = V_580 ;
struct V_581 V_582 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_45 -> V_22 >= F_290 ( V_583 ) )
goto V_270;
V_582 = V_583 [ V_45 -> V_22 ] ;
if ( V_579 != V_582 . V_579 )
goto V_270;
switch ( V_582 . V_393 ) {
case V_420 :
if ( V_45 -> V_22 == V_584 )
V_582 . V_393 += V_45 -> V_585 ;
break;
case V_586 : {
unsigned long V_249 , V_81 ;
T_2 V_22 ;
if ( V_45 -> V_22 == V_587 )
V_582 . V_393 += V_45 -> V_585 ;
if ( V_582 . V_393 != V_586 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_207 ) ) )
break;
V_249 = V_9 -> V_23 . V_249 & ~ V_330 ;
V_81 = V_45 -> V_588 & ~ V_330 ;
if ( V_45 -> V_22 == V_589 ) {
V_249 &= 0xfUL ;
V_81 &= 0xfUL ;
if ( V_249 & V_438 )
V_81 |= V_438 ;
}
if ( V_249 ^ V_81 )
V_582 . V_393 = V_491 ;
break;
}
case V_422 :
case V_590 :
V_582 . V_393 += V_45 -> V_585 ;
break;
case V_418 :
if ( V_45 -> V_22 == V_591 )
V_1 -> V_2 . V_358 = 1 ;
else
V_1 -> V_2 . V_358 = 0 ;
break;
case V_592 :
if ( V_45 -> V_593 != V_594 )
goto V_270;
case V_419 : {
T_2 V_595 ;
T_1 V_596 ;
V_595 = ( V_9 -> V_23 . V_247 [ V_518 ] & 0xffff ) << 16 ;
if ( V_45 -> V_22 == V_597 ||
V_45 -> V_22 == V_598 ) {
V_595 |= V_384 ;
V_596 = V_45 -> V_599 ;
} else {
V_596 = V_45 -> V_600 ;
}
if ( V_45 -> V_22 == V_601 ||
V_45 -> V_22 == V_598 )
V_595 |= V_383 ;
if ( V_45 -> V_593 )
V_595 |= V_602 ;
V_596 = F_81 ( V_596 , 4u ) ;
V_595 |= V_596 << V_386 ;
V_595 |= ( T_1 ) V_45 -> V_603 << ( V_604 - 1 ) ;
V_1 -> V_2 . V_358 = V_595 ;
V_1 -> V_2 . V_356 = V_45 -> V_55 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_55 = V_45 -> V_55 ;
V_1 -> V_2 . V_393 = V_582 . V_393 ;
V_402 = F_212 ( V_10 ) ;
V_50 = ( V_402 == V_405 ) ? V_605
: V_580 ;
V_270:
return V_50 ;
}
static int T_5 F_333 ( void )
{
return F_334 ( & V_606 , sizeof( struct V_7 ) ,
F_335 ( struct V_7 ) , V_607 ) ;
}
static void T_6 F_336 ( void )
{
F_337 () ;
}
