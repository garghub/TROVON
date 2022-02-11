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
F_50 () ;
}
static int F_51 ( void * V_87 )
{
struct V_91 * V_92 ;
T_3 V_38 ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
int V_97 = F_52 () ;
F_53 ( V_98 , V_38 ) ;
if ( V_38 & V_43 )
return - V_99 ;
if ( ! F_45 () ) {
F_33 ( V_61 L_4 ,
V_97 ) ;
return - V_100 ;
}
V_92 = F_54 ( V_101 , V_97 ) ;
if ( ! V_92 ) {
F_33 ( V_61 L_5 ,
V_97 ) ;
return - V_100 ;
}
V_92 -> V_102 = 1 ;
V_92 -> V_103 = F_55 ( V_104 ) - 1 ;
V_92 -> V_105 = V_92 -> V_103 + 1 ;
F_56 ( & V_94 ) ;
V_96 = (struct V_95 * ) V_94 . V_106 ;
V_92 -> V_107 = (struct V_108 * ) ( V_96 + V_109 ) ;
F_48 ( V_98 , V_38 | V_43 ) ;
F_48 ( V_110 , F_57 ( V_92 -> V_111 ) << V_112 ) ;
if ( F_38 ( V_88 ) ) {
F_48 ( V_89 , V_90 ) ;
F_58 ( V_113 ) = V_90 ;
}
F_39 () ;
F_59 () ;
return 0 ;
}
static void F_60 ( int V_114 )
{
struct V_91 * V_92 = F_54 ( V_101 , F_52 () ) ;
if ( ! V_92 )
return;
F_54 ( V_101 , F_52 () ) = NULL ;
F_61 ( V_92 -> V_111 ) ;
F_62 ( V_92 ) ;
}
static int F_63 ( int V_114 )
{
struct V_91 * V_92 ;
int V_115 ;
V_92 = F_64 ( sizeof( struct V_91 ) , V_116 ) ;
if ( ! V_92 )
return - V_117 ;
V_92 -> V_114 = V_114 ;
V_92 -> V_111 = F_65 ( V_116 ) ;
V_115 = - V_117 ;
if ( ! V_92 -> V_111 )
goto V_118;
F_54 ( V_101 , V_114 ) = V_92 ;
return 0 ;
V_118:
F_62 ( V_92 ) ;
return V_115 ;
}
static bool F_66 ( T_1 V_119 )
{
int V_28 ;
for ( V_28 = 0 ; V_120 [ V_28 ] . V_119 != V_33 ; V_28 ++ )
if ( V_120 [ V_28 ] . V_119 == V_119 )
return true ;
return false ;
}
static void F_67 ( T_1 * V_121 , unsigned V_26 ,
int V_122 , int V_123 )
{
T_4 V_124 , V_125 ;
unsigned long V_126 ;
T_1 V_27 ;
F_68 ( ! F_66 ( V_26 ) ) ;
V_27 = F_21 ( V_26 ) ;
V_124 = 2 * ( V_26 & 0x0f ) ;
V_125 = 2 * ( V_26 & 0x0f ) + 1 ;
V_126 = V_121 [ V_27 ] ;
F_69 ( V_27 == V_33 ) ;
V_122 ? F_70 ( V_124 , & V_126 ) : F_71 ( V_124 , & V_126 ) ;
V_123 ? F_70 ( V_125 , & V_126 ) : F_71 ( V_125 , & V_126 ) ;
V_121 [ V_27 ] = V_126 ;
}
static void F_72 ( T_1 * V_121 )
{
int V_28 ;
memset ( V_121 , 0xff , V_127 * ( 1 << V_128 ) ) ;
for ( V_28 = 0 ; V_120 [ V_28 ] . V_119 != V_33 ; V_28 ++ ) {
if ( ! V_120 [ V_28 ] . V_129 )
continue;
F_67 ( V_121 , V_120 [ V_28 ] . V_119 , 1 , 1 ) ;
}
}
static void F_73 ( T_1 V_27 )
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
F_74 () ;
}
static void F_75 ( void )
{
int V_28 ;
memset ( V_131 , 0xff , sizeof( V_131 ) ) ;
for ( V_28 = 0 ; V_120 [ V_28 ] . V_119 != V_33 ; V_28 ++ ) {
T_1 V_27 ;
V_27 = F_21 ( V_120 [ V_28 ] . V_119 ) ;
F_69 ( V_27 == V_33 ) ;
F_73 ( V_27 ) ;
}
}
static void F_76 ( struct V_7 * V_10 )
{
T_1 * V_121 = V_10 -> V_121 ;
V_10 -> V_1 -> V_2 . V_132 = 1 ;
F_67 ( V_121 , V_133 , 1 , 1 ) ;
F_67 ( V_121 , V_134 , 1 , 1 ) ;
F_67 ( V_121 , V_135 , 1 , 1 ) ;
F_67 ( V_121 , V_136 , 1 , 1 ) ;
}
static void F_77 ( struct V_7 * V_10 )
{
T_1 * V_121 = V_10 -> V_121 ;
V_10 -> V_1 -> V_2 . V_132 = 0 ;
F_67 ( V_121 , V_133 , 0 , 0 ) ;
F_67 ( V_121 , V_134 , 0 , 0 ) ;
F_67 ( V_121 , V_135 , 0 , 0 ) ;
F_67 ( V_121 , V_136 , 0 , 0 ) ;
}
static T_5 int F_78 ( void )
{
int V_114 ;
struct V_137 * V_138 ;
void * V_139 ;
int V_115 ;
V_138 = F_79 ( V_116 , V_140 ) ;
if ( ! V_138 )
return - V_117 ;
V_139 = F_80 ( V_138 ) ;
memset ( V_139 , 0xff , V_127 * ( 1 << V_140 ) ) ;
V_141 = F_57 ( V_138 ) << V_112 ;
F_75 () ;
if ( F_81 ( V_142 ) )
F_82 ( V_143 ) ;
if ( F_81 ( V_144 ) )
F_82 ( V_145 ) ;
if ( F_81 ( V_88 ) ) {
T_2 V_146 ;
V_147 = true ;
V_146 = F_83 ( 0x7fffffffULL , F_84 ( V_148 , V_149 ) ) ;
V_150 = V_146 ;
}
if ( V_17 ) {
F_33 ( V_86 L_6 ) ;
F_82 ( V_43 | V_151 ) ;
}
F_85 (cpu) {
V_115 = F_63 ( V_114 ) ;
if ( V_115 )
goto V_80;
}
if ( ! F_81 ( V_152 ) )
V_39 = false ;
if ( V_39 && ! V_153 ) {
F_33 ( V_86 L_7 ) ;
V_39 = false ;
}
if ( V_39 ) {
F_33 ( V_86 L_8 ) ;
F_86 () ;
} else
F_87 () ;
return 0 ;
V_80:
F_88 ( V_138 , V_140 ) ;
V_141 = 0 ;
return V_115 ;
}
static T_6 void F_89 ( void )
{
int V_114 ;
F_85 (cpu)
F_60 ( V_114 ) ;
F_88 ( F_90 ( V_141 >> V_112 ) , V_140 ) ;
V_141 = 0 ;
}
static void F_91 ( struct V_154 * V_155 )
{
V_155 -> V_156 = 0 ;
V_155 -> V_157 = V_158 | V_159 |
V_160 ;
V_155 -> V_161 = 0xffff ;
V_155 -> V_72 = 0 ;
}
static void F_92 ( struct V_154 * V_155 , T_7 type )
{
V_155 -> V_156 = 0 ;
V_155 -> V_157 = V_158 | type ;
V_155 -> V_161 = 0xffff ;
V_155 -> V_72 = 0 ;
}
static T_2 F_84 ( T_2 V_162 , T_2 V_163 )
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
static T_2 F_93 ( struct V_8 * V_9 , T_2 V_163 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_166 = V_163 ;
if ( V_10 -> V_167 != V_90 )
V_166 = F_84 ( V_10 -> V_167 , V_163 ) ;
return V_166 ;
}
static void F_94 ( struct V_8 * V_9 , T_1 V_168 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_162 ;
T_2 V_169 ;
if ( ! F_81 ( V_88 ) )
return;
if ( V_168 == 0 ) {
V_9 -> V_23 . V_170 = 0 ;
V_10 -> V_167 = V_90 ;
return;
}
V_169 = V_168 ;
V_162 = V_169 << 32 ;
F_95 ( V_162 , V_148 ) ;
if ( V_162 == 0 || V_162 & V_171 ) {
F_96 ( 1 , L_9 ,
V_168 ) ;
return;
}
V_9 -> V_23 . V_170 = V_168 ;
V_10 -> V_167 = V_162 ;
}
static void F_97 ( struct V_8 * V_9 , T_2 V_27 )
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
static void F_98 ( struct V_8 * V_9 , T_8 V_174 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_173 += V_174 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_173 += V_174 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_99 ( struct V_8 * V_9 , T_2 V_175 )
{
T_2 V_163 ;
V_163 = F_93 ( V_9 , F_100 () ) ;
return V_175 - V_163 ;
}
static void F_101 ( struct V_7 * V_10 )
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
F_16 ( V_10 , V_228 ) ;
V_2 -> V_229 = V_141 ;
V_2 -> V_230 = F_102 ( V_10 -> V_121 ) ;
V_2 -> V_231 = V_232 ;
F_91 ( & V_42 -> V_233 ) ;
F_91 ( & V_42 -> V_234 ) ;
F_91 ( & V_42 -> V_235 ) ;
F_91 ( & V_42 -> V_236 ) ;
F_91 ( & V_42 -> V_237 ) ;
V_42 -> V_71 . V_156 = 0xf000 ;
V_42 -> V_71 . V_157 = V_238 | V_158 |
V_159 | V_239 ;
V_42 -> V_71 . V_161 = 0xffff ;
V_42 -> V_71 . V_72 = 0xf0000 ;
V_42 -> V_240 . V_161 = 0xffff ;
V_42 -> V_241 . V_161 = 0xffff ;
F_92 ( & V_42 -> V_242 , V_243 ) ;
F_92 ( & V_42 -> V_244 , V_245 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_42 -> V_246 = 0xffff0ff0 ;
V_42 -> V_247 = 0x400 ;
F_103 ( & V_10 -> V_9 , 2 ) ;
V_42 -> V_68 = 0x0000fff0 ;
V_10 -> V_9 . V_23 . V_248 [ V_249 ] = V_42 -> V_68 ;
V_10 -> V_9 . V_23 . V_250 = 0 ;
( void ) F_104 ( & V_10 -> V_9 , V_251 | V_252 | V_253 ) ;
V_42 -> V_254 = V_255 ;
if ( V_39 ) {
V_2 -> V_256 = 1 ;
F_17 ( V_10 , V_212 ) ;
F_15 ( V_10 , V_201 ) ;
F_10 ( V_10 , V_179 ) ;
F_10 ( V_10 , V_182 ) ;
V_42 -> V_257 = 0x0007040600070406ULL ;
V_42 -> V_258 = 0 ;
V_42 -> V_254 = 0 ;
}
V_10 -> V_102 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_23 . V_24 = 0 ;
if ( F_81 ( V_259 ) ) {
V_2 -> V_260 = 3000 ;
F_16 ( V_10 , V_261 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static int F_105 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_101 ( V_10 ) ;
if ( ! F_106 ( V_9 ) ) {
F_35 ( V_9 , 0 ) ;
V_10 -> V_1 -> V_42 . V_71 . V_72 = V_10 -> V_9 . V_23 . V_262 << 12 ;
V_10 -> V_1 -> V_42 . V_71 . V_156 = V_10 -> V_9 . V_23 . V_262 << 8 ;
}
V_9 -> V_23 . V_263 = ~ 0 ;
V_9 -> V_23 . V_264 = ~ 0 ;
return 0 ;
}
static struct V_8 * F_107 ( struct V_265 * V_265 , unsigned int V_266 )
{
struct V_7 * V_10 ;
struct V_137 * V_137 ;
struct V_137 * V_267 ;
struct V_137 * V_268 ;
struct V_137 * V_269 ;
int V_80 ;
V_10 = F_108 ( V_270 , V_116 ) ;
if ( ! V_10 ) {
V_80 = - V_117 ;
goto V_271;
}
V_10 -> V_167 = V_90 ;
V_80 = F_109 ( & V_10 -> V_9 , V_265 , V_266 ) ;
if ( V_80 )
goto V_272;
V_80 = - V_117 ;
V_137 = F_65 ( V_116 ) ;
if ( ! V_137 )
goto V_273;
V_267 = F_79 ( V_116 , V_128 ) ;
if ( ! V_267 )
goto V_274;
V_269 = F_79 ( V_116 , V_128 ) ;
if ( ! V_269 )
goto V_275;
V_268 = F_65 ( V_116 ) ;
if ( ! V_268 )
goto V_276;
V_10 -> V_17 . V_18 = F_80 ( V_268 ) ;
V_10 -> V_121 = F_80 ( V_267 ) ;
F_72 ( V_10 -> V_121 ) ;
V_10 -> V_17 . V_121 = F_80 ( V_269 ) ;
F_72 ( V_10 -> V_17 . V_121 ) ;
V_10 -> V_1 = F_80 ( V_137 ) ;
F_110 ( V_10 -> V_1 ) ;
V_10 -> V_277 = F_57 ( V_137 ) << V_112 ;
V_10 -> V_102 = 0 ;
F_101 ( V_10 ) ;
F_111 ( & V_10 -> V_9 , 0 ) ;
V_80 = F_112 ( & V_10 -> V_9 ) ;
if ( V_80 )
goto V_278;
V_10 -> V_9 . V_23 . V_279 = 0xfee00000 | V_280 ;
if ( F_106 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_23 . V_279 |= V_281 ;
return & V_10 -> V_9 ;
V_278:
F_61 ( V_268 ) ;
V_276:
F_88 ( V_269 , V_128 ) ;
V_275:
F_88 ( V_267 , V_128 ) ;
V_274:
F_61 ( V_137 ) ;
V_273:
F_113 ( & V_10 -> V_9 ) ;
V_272:
F_114 ( V_270 , V_10 ) ;
V_271:
return F_115 ( V_80 ) ;
}
static void F_116 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_61 ( F_90 ( V_10 -> V_277 >> V_112 ) ) ;
F_88 ( F_117 ( V_10 -> V_121 ) , V_128 ) ;
F_61 ( F_117 ( V_10 -> V_17 . V_18 ) ) ;
F_88 ( F_117 ( V_10 -> V_17 . V_121 ) , V_128 ) ;
F_113 ( V_9 ) ;
F_114 ( V_270 , V_10 ) ;
}
static void F_118 ( struct V_8 * V_9 , int V_114 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
if ( F_119 ( V_114 != V_9 -> V_114 ) ) {
V_10 -> V_102 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_53 ( V_282 , F_4 ( V_9 ) -> V_283 . V_284 ) ;
#endif
F_120 ( V_236 , V_10 -> V_283 . V_236 ) ;
F_120 ( V_237 , V_10 -> V_283 . V_237 ) ;
V_10 -> V_283 . V_285 = F_121 () ;
for ( V_28 = 0 ; V_28 < V_286 ; V_28 ++ )
F_53 ( V_287 [ V_28 ] , V_10 -> V_288 [ V_28 ] ) ;
if ( F_38 ( V_88 ) &&
V_10 -> V_167 != F_58 ( V_113 ) ) {
F_58 ( V_113 ) = V_10 -> V_167 ;
F_48 ( V_89 , V_10 -> V_167 ) ;
}
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
++ V_9 -> V_289 . V_290 ;
F_123 ( V_10 -> V_283 . V_285 ) ;
#ifdef F_26
F_124 ( V_236 , V_10 -> V_283 . V_236 ) ;
F_48 ( V_291 , V_292 -> V_293 . V_237 ) ;
F_125 ( V_10 -> V_283 . V_237 ) ;
#else
#ifdef F_126
F_124 ( V_237 , V_10 -> V_283 . V_237 ) ;
#endif
#endif
for ( V_28 = 0 ; V_28 < V_286 ; V_28 ++ )
F_48 ( V_287 [ V_28 ] , V_10 -> V_288 [ V_28 ] ) ;
}
static unsigned long F_127 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_42 . V_294 ;
}
static void F_128 ( struct V_8 * V_9 , unsigned long V_294 )
{
F_4 ( V_9 ) -> V_1 -> V_42 . V_294 = V_294 ;
}
static void F_129 ( struct V_8 * V_9 , enum V_295 V_296 )
{
switch ( V_296 ) {
case V_297 :
F_69 ( ! V_39 ) ;
F_130 ( V_9 , V_9 -> V_23 . V_298 , F_131 ( V_9 ) ) ;
break;
default:
F_74 () ;
}
}
static void F_132 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_299 ) ;
}
static void F_133 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_299 ) ;
}
static struct V_154 * F_134 ( struct V_8 * V_9 , int V_155 )
{
struct V_176 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
switch ( V_155 ) {
case V_300 : return & V_42 -> V_71 ;
case V_301 : return & V_42 -> V_235 ;
case V_302 : return & V_42 -> V_233 ;
case V_303 : return & V_42 -> V_236 ;
case V_304 : return & V_42 -> V_237 ;
case V_305 : return & V_42 -> V_234 ;
case V_306 : return & V_42 -> V_244 ;
case V_307 : return & V_42 -> V_242 ;
}
F_74 () ;
return NULL ;
}
static T_2 F_135 ( struct V_8 * V_9 , int V_155 )
{
struct V_154 * V_308 = F_134 ( V_9 , V_155 ) ;
return V_308 -> V_72 ;
}
static void F_136 ( struct V_8 * V_9 ,
struct V_309 * V_310 , int V_155 )
{
struct V_154 * V_308 = F_134 ( V_9 , V_155 ) ;
V_310 -> V_72 = V_308 -> V_72 ;
V_310 -> V_161 = V_308 -> V_161 ;
V_310 -> V_156 = V_308 -> V_156 ;
V_310 -> type = V_308 -> V_157 & V_311 ;
V_310 -> V_308 = ( V_308 -> V_157 >> V_312 ) & 1 ;
V_310 -> V_313 = ( V_308 -> V_157 >> V_314 ) & 3 ;
V_310 -> V_315 = ( V_308 -> V_157 >> V_316 ) & 1 ;
V_310 -> V_317 = ( V_308 -> V_157 >> V_318 ) & 1 ;
V_310 -> V_319 = ( V_308 -> V_157 >> V_320 ) & 1 ;
V_310 -> V_321 = ( V_308 -> V_157 >> V_322 ) & 1 ;
V_310 -> V_15 = ( V_308 -> V_157 >> V_323 ) & 1 ;
V_310 -> V_324 = ! V_310 -> V_315 || ( V_310 -> type == 0 ) ;
switch ( V_155 ) {
case V_300 :
V_310 -> V_15 = V_308 -> V_161 > 0xfffff ;
break;
case V_306 :
V_310 -> type |= 0x2 ;
break;
case V_301 :
case V_302 :
case V_303 :
case V_304 :
if ( ! V_310 -> V_324 )
V_310 -> type |= 0x1 ;
break;
case V_305 :
if ( V_310 -> V_324 )
V_310 -> V_321 = 0 ;
break;
}
}
static int F_137 ( struct V_8 * V_9 )
{
struct V_176 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
return V_42 -> V_325 ;
}
static void F_138 ( struct V_8 * V_9 , struct V_93 * V_326 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_326 -> V_327 = V_10 -> V_1 -> V_42 . V_241 . V_161 ;
V_326 -> V_106 = V_10 -> V_1 -> V_42 . V_241 . V_72 ;
}
static void F_139 ( struct V_8 * V_9 , struct V_93 * V_326 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_241 . V_161 = V_326 -> V_327 ;
V_10 -> V_1 -> V_42 . V_241 . V_72 = V_326 -> V_106 ;
F_3 ( V_10 -> V_1 , V_328 ) ;
}
static void F_140 ( struct V_8 * V_9 , struct V_93 * V_326 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_326 -> V_327 = V_10 -> V_1 -> V_42 . V_240 . V_161 ;
V_326 -> V_106 = V_10 -> V_1 -> V_42 . V_240 . V_72 ;
}
static void F_141 ( struct V_8 * V_9 , struct V_93 * V_326 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_240 . V_161 = V_326 -> V_327 ;
V_10 -> V_1 -> V_42 . V_240 . V_72 = V_326 -> V_106 ;
F_3 ( V_10 -> V_1 , V_328 ) ;
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
T_9 V_329 = V_10 -> V_9 . V_23 . V_250 ;
T_2 * V_330 = & V_10 -> V_1 -> V_42 . V_250 ;
if ( ! V_10 -> V_9 . V_177 )
* V_330 |= V_331 ;
else
* V_330 = ( * V_330 & ~ V_331 )
| ( V_329 & V_331 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
if ( V_329 == * V_330 && V_10 -> V_9 . V_177 ) {
F_10 ( V_10 , V_178 ) ;
F_10 ( V_10 , V_181 ) ;
} else {
F_9 ( V_10 , V_178 ) ;
F_9 ( V_10 , V_181 ) ;
}
}
static void F_146 ( struct V_8 * V_9 , unsigned long V_250 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_23 . V_38 & V_41 ) {
if ( ! F_147 ( V_9 ) && ( V_250 & V_332 ) ) {
V_9 -> V_23 . V_38 |= V_40 ;
V_10 -> V_1 -> V_42 . V_38 |= V_40 | V_41 ;
}
if ( F_147 ( V_9 ) && ! ( V_250 & V_332 ) ) {
V_9 -> V_23 . V_38 &= ~ V_40 ;
V_10 -> V_1 -> V_42 . V_38 &= ~ ( V_40 | V_41 ) ;
}
}
#endif
V_9 -> V_23 . V_250 = V_250 ;
if ( ! V_39 )
V_250 |= V_332 | V_333 ;
if ( ! V_9 -> V_177 )
V_250 |= V_334 ;
V_250 &= ~ ( V_252 | V_251 ) ;
V_10 -> V_1 -> V_42 . V_250 = V_250 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_145 ( V_10 ) ;
}
static int F_148 ( struct V_8 * V_9 , unsigned long V_254 )
{
unsigned long V_335 = F_149 () & V_336 ;
unsigned long V_337 = F_4 ( V_9 ) -> V_1 -> V_42 . V_254 ;
if ( V_254 & V_338 )
return 1 ;
if ( V_39 && ( ( V_337 ^ V_254 ) & V_339 ) )
F_150 ( V_9 ) ;
V_9 -> V_23 . V_254 = V_254 ;
if ( ! V_39 )
V_254 |= V_255 ;
V_254 |= V_335 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_254 = V_254 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
return 0 ;
}
static void F_151 ( struct V_8 * V_9 ,
struct V_309 * V_310 , int V_155 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_154 * V_308 = F_134 ( V_9 , V_155 ) ;
V_308 -> V_72 = V_310 -> V_72 ;
V_308 -> V_161 = V_310 -> V_161 ;
V_308 -> V_156 = V_310 -> V_156 ;
if ( V_310 -> V_324 )
V_308 -> V_157 = 0 ;
else {
V_308 -> V_157 = ( V_310 -> type & V_311 ) ;
V_308 -> V_157 |= ( V_310 -> V_308 & 1 ) << V_312 ;
V_308 -> V_157 |= ( V_310 -> V_313 & 3 ) << V_314 ;
V_308 -> V_157 |= ( V_310 -> V_315 & 1 ) << V_316 ;
V_308 -> V_157 |= ( V_310 -> V_317 & 1 ) << V_318 ;
V_308 -> V_157 |= ( V_310 -> V_319 & 1 ) << V_320 ;
V_308 -> V_157 |= ( V_310 -> V_321 & 1 ) << V_322 ;
V_308 -> V_157 |= ( V_310 -> V_15 & 1 ) << V_323 ;
}
if ( V_155 == V_300 )
V_10 -> V_1 -> V_42 . V_325
= ( V_10 -> V_1 -> V_42 . V_71 . V_157
>> V_314 ) & 3 ;
F_3 ( V_10 -> V_1 , V_340 ) ;
}
static void F_152 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_341 ) ;
F_15 ( V_10 , V_66 ) ;
if ( V_10 -> V_342 )
F_14 ( V_10 , V_341 ) ;
if ( V_9 -> V_343 & V_344 ) {
if ( V_9 -> V_343 &
( V_345 | V_346 ) )
F_14 ( V_10 , V_341 ) ;
if ( V_9 -> V_343 & V_347 )
F_14 ( V_10 , V_66 ) ;
} else
V_9 -> V_343 = 0 ;
}
static void F_153 ( struct V_8 * V_9 , struct V_348 * V_349 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_9 -> V_343 & V_346 )
V_10 -> V_1 -> V_42 . V_247 = V_349 -> V_23 . V_350 [ 7 ] ;
else
V_10 -> V_1 -> V_42 . V_247 = V_9 -> V_23 . V_247 ;
F_3 ( V_10 -> V_1 , V_351 ) ;
F_152 ( V_9 ) ;
}
static void F_154 ( struct V_7 * V_10 , struct V_91 * V_92 )
{
if ( V_92 -> V_105 > V_92 -> V_103 ) {
++ V_92 -> V_102 ;
V_92 -> V_105 = 1 ;
V_10 -> V_1 -> V_2 . V_352 = V_353 ;
}
V_10 -> V_102 = V_92 -> V_102 ;
V_10 -> V_1 -> V_2 . V_35 = V_92 -> V_105 ++ ;
F_3 ( V_10 -> V_1 , V_354 ) ;
}
static void F_155 ( struct V_8 * V_9 , unsigned long V_355 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_247 = V_355 ;
F_3 ( V_10 -> V_1 , V_351 ) ;
}
static int F_156 ( struct V_7 * V_10 )
{
T_2 V_356 = V_10 -> V_1 -> V_2 . V_357 ;
T_1 V_64 ;
int V_115 = 1 ;
switch ( V_10 -> V_358 ) {
default:
V_64 = V_10 -> V_1 -> V_2 . V_359 ;
F_157 ( V_356 , V_64 ) ;
if ( ! V_39 && F_158 ( & V_10 -> V_9 ) )
F_159 ( & V_10 -> V_9 , V_356 ) ;
V_115 = F_160 ( & V_10 -> V_9 , V_356 , V_64 ,
V_10 -> V_1 -> V_2 . V_360 ,
V_10 -> V_1 -> V_2 . V_361 ) ;
break;
case V_362 :
V_10 -> V_358 = 0 ;
F_161 () ;
F_162 ( V_356 ) ;
F_163 () ;
break;
case V_363 :
V_10 -> V_358 = 0 ;
F_161 () ;
F_164 ( V_356 ) ;
F_163 () ;
break;
}
return V_115 ;
}
static int F_165 ( struct V_7 * V_10 )
{
struct V_364 * V_364 = V_10 -> V_9 . V_365 ;
if ( ! ( V_10 -> V_9 . V_343 &
( V_345 | V_346 ) ) &&
! V_10 -> V_342 ) {
F_166 ( & V_10 -> V_9 , V_341 ) ;
return 1 ;
}
if ( V_10 -> V_342 ) {
V_10 -> V_342 = false ;
if ( ! ( V_10 -> V_9 . V_343 & V_345 ) )
V_10 -> V_1 -> V_42 . V_294 &=
~ ( V_366 | V_367 ) ;
F_152 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_343 &
( V_345 | V_346 ) ) {
V_364 -> V_368 = V_369 ;
V_364 -> V_370 . V_23 . V_371 =
V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_364 -> V_370 . V_23 . V_372 = V_341 ;
return 0 ;
}
return 1 ;
}
static int F_167 ( struct V_7 * V_10 )
{
struct V_364 * V_364 = V_10 -> V_9 . V_365 ;
V_364 -> V_368 = V_369 ;
V_364 -> V_370 . V_23 . V_371 = V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_364 -> V_370 . V_23 . V_372 = V_66 ;
return 0 ;
}
static int F_168 ( struct V_7 * V_10 )
{
int V_373 ;
V_373 = F_32 ( & V_10 -> V_9 , V_374 ) ;
if ( V_373 != V_57 )
F_166 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static void F_169 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_375 ) ;
V_10 -> V_9 . V_177 = 1 ;
F_145 ( V_10 ) ;
}
static int F_170 ( struct V_7 * V_10 )
{
F_169 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_171 ( void )
{
int V_80 , V_28 ;
T_2 V_355 ;
if ( ! V_84 )
return false ;
V_355 = F_41 ( V_376 , & V_80 ) ;
if ( V_80 )
return false ;
V_355 &= ~ ( 1ULL << 62 ) ;
if ( V_355 != 0xb600000000010015ULL )
return false ;
for ( V_28 = 0 ; V_28 < 6 ; ++ V_28 )
F_44 ( F_172 ( V_28 ) , 0 , 0 ) ;
V_355 = F_41 ( V_377 , & V_80 ) ;
if ( ! V_80 ) {
T_1 V_78 , V_79 ;
V_355 &= ~ ( 1ULL << 2 ) ;
V_78 = F_42 ( V_355 ) ;
V_79 = F_43 ( V_355 ) ;
F_44 ( V_377 , V_78 , V_79 ) ;
}
F_173 () ;
return true ;
}
static void F_174 ( struct V_7 * V_10 )
{
if ( F_171 () ) {
F_175 ( L_10 ) ;
F_176 ( V_378 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_177 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_178 ( struct V_7 * V_10 )
{
struct V_364 * V_364 = V_10 -> V_9 . V_365 ;
F_110 ( V_10 -> V_1 ) ;
F_101 ( V_10 ) ;
V_364 -> V_368 = V_379 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_380 = V_10 -> V_1 -> V_2 . V_359 ;
int V_327 , V_381 , string ;
unsigned V_382 ;
++ V_10 -> V_9 . V_289 . V_383 ;
string = ( V_380 & V_384 ) != 0 ;
V_381 = ( V_380 & V_385 ) != 0 ;
if ( string || V_381 )
return F_32 ( V_9 , 0 ) == V_57 ;
V_382 = V_380 >> 16 ;
V_327 = ( V_380 & V_386 ) >> V_387 ;
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_357 ;
F_31 ( & V_10 -> V_9 ) ;
return F_180 ( V_9 , V_327 , V_382 ) ;
}
static int F_181 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_182 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_289 . V_388 ;
return 1 ;
}
static int F_183 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_184 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 1 ;
F_31 ( & V_10 -> V_9 ) ;
return F_185 ( & V_10 -> V_9 ) ;
}
static int F_186 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_187 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_188 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_389 ;
}
static T_2 F_189 ( struct V_8 * V_9 , int V_119 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_258 = V_10 -> V_17 . V_389 ;
T_2 V_390 ;
int V_50 ;
V_50 = F_190 ( V_9 -> V_265 , F_191 ( V_258 ) , & V_390 ,
F_192 ( V_258 ) + V_119 * 8 , 8 ) ;
if ( V_50 )
return 0 ;
return V_390 ;
}
static void F_193 ( struct V_8 * V_9 ,
unsigned long V_391 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_389 = V_391 ;
F_3 ( V_10 -> V_1 , V_392 ) ;
F_150 ( V_9 ) ;
}
static void F_194 ( struct V_8 * V_9 ,
struct V_393 * V_394 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_395 = V_396 ;
V_10 -> V_1 -> V_2 . V_397 = 0 ;
V_10 -> V_1 -> V_2 . V_359 = V_394 -> V_64 ;
V_10 -> V_1 -> V_2 . V_357 = V_394 -> V_106 ;
F_195 ( V_10 ) ;
}
static int F_196 ( struct V_8 * V_9 )
{
int V_115 ;
V_115 = F_197 ( V_9 , & V_9 -> V_23 . V_398 ) ;
V_9 -> V_23 . V_398 . V_399 = F_193 ;
V_9 -> V_23 . V_398 . V_400 = F_188 ;
V_9 -> V_23 . V_398 . V_401 = F_189 ;
V_9 -> V_23 . V_398 . V_402 = F_194 ;
V_9 -> V_23 . V_398 . V_403 = F_25 () ;
V_9 -> V_23 . V_298 = & V_9 -> V_23 . V_404 ;
return V_115 ;
}
static void F_198 ( struct V_8 * V_9 )
{
V_9 -> V_23 . V_298 = & V_9 -> V_23 . V_398 ;
}
static int F_199 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_23 . V_38 & V_43 )
|| ! F_147 ( & V_10 -> V_9 ) ) {
F_166 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_42 . V_325 ) {
F_200 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_10 , unsigned V_62 ,
bool V_63 , T_1 V_64 )
{
int V_405 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_395 = V_406 + V_62 ;
V_10 -> V_1 -> V_2 . V_397 = 0 ;
V_10 -> V_1 -> V_2 . V_359 = V_64 ;
V_10 -> V_1 -> V_2 . V_357 = V_10 -> V_9 . V_23 . V_407 ;
V_405 = F_201 ( V_10 ) ;
if ( V_405 == V_408 )
V_10 -> V_17 . V_409 = true ;
return V_405 ;
}
static inline bool F_202 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_410 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_411 ) )
return false ;
if ( V_10 -> V_17 . V_409 )
return false ;
V_10 -> V_1 -> V_2 . V_395 = V_412 ;
V_10 -> V_1 -> V_2 . V_359 = 0 ;
V_10 -> V_1 -> V_2 . V_357 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_409 = true ;
F_203 ( V_10 -> V_1 -> V_42 . V_68 ) ;
return false ;
}
return true ;
}
static inline bool F_204 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_205 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_395 = V_413 ;
V_10 -> V_17 . V_409 = true ;
return false ;
}
static void * F_205 ( struct V_7 * V_10 , T_2 V_414 , struct V_137 * * V_415 )
{
struct V_137 * V_137 ;
F_206 () ;
V_137 = F_207 ( V_10 -> V_9 . V_265 , V_414 >> V_112 ) ;
if ( F_208 ( V_137 ) )
goto error;
* V_415 = V_137 ;
return F_209 ( V_137 ) ;
error:
F_210 ( V_137 ) ;
F_200 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_211 ( struct V_137 * V_137 )
{
F_212 ( V_137 ) ;
F_213 ( V_137 ) ;
}
static int F_214 ( struct V_7 * V_10 )
{
unsigned V_382 ;
T_4 V_81 , V_6 ;
T_2 V_414 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_214 ) ) )
return V_416 ;
V_382 = V_10 -> V_1 -> V_2 . V_359 >> 16 ;
V_414 = V_10 -> V_17 . V_417 + ( V_382 / 8 ) ;
V_6 = V_382 % 8 ;
V_81 = 0 ;
if ( F_215 ( V_10 -> V_9 . V_265 , V_414 , & V_81 , 1 ) )
V_81 &= ( 1 << V_6 ) ;
return V_81 ? V_408 : V_416 ;
}
static int F_216 ( struct V_7 * V_10 )
{
T_1 V_27 , V_26 , V_355 ;
int V_123 , V_49 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_215 ) ) )
return V_416 ;
V_26 = V_10 -> V_9 . V_23 . V_248 [ V_418 ] ;
V_27 = F_21 ( V_26 ) ;
V_123 = V_10 -> V_1 -> V_2 . V_359 & 1 ;
V_49 = 1 << ( ( 2 * ( V_26 & 0xf ) ) + V_123 ) ;
if ( V_27 == V_33 )
return V_408 ;
V_27 *= 4 ;
if ( F_215 ( V_10 -> V_9 . V_265 , V_10 -> V_17 . V_419 + V_27 , & V_355 , 4 ) )
return V_408 ;
return ( V_355 & V_49 ) ? V_408 : V_416 ;
}
static int F_217 ( struct V_7 * V_10 )
{
T_1 V_395 = V_10 -> V_1 -> V_2 . V_395 ;
switch ( V_395 ) {
case V_412 :
case V_413 :
case V_406 + V_203 :
return V_416 ;
case V_396 :
if ( V_39 )
return V_416 ;
break;
case V_406 + V_201 :
if ( ! V_39 && V_10 -> V_358 == 0 )
return V_416 ;
break;
case V_406 + V_375 :
F_170 ( V_10 ) ;
break;
default:
break;
}
return V_420 ;
}
static int F_201 ( struct V_7 * V_10 )
{
T_1 V_395 = V_10 -> V_1 -> V_2 . V_395 ;
int V_405 = V_416 ;
switch ( V_395 ) {
case V_421 :
V_405 = F_216 ( V_10 ) ;
break;
case V_422 :
V_405 = F_214 ( V_10 ) ;
break;
case V_423 ... V_424 : {
T_1 V_6 = 1U << ( V_395 - V_423 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_405 = V_408 ;
break;
}
case V_425 ... V_426 : {
T_1 V_6 = 1U << ( V_395 - V_425 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_405 = V_408 ;
break;
}
case V_406 ... V_406 + 0x1f : {
T_1 V_427 = 1 << ( V_395 - V_406 ) ;
if ( V_10 -> V_17 . V_21 & V_427 )
V_405 = V_408 ;
else if ( ( V_395 == V_406 + V_201 ) &&
V_10 -> V_358 != 0 )
V_405 = V_408 ;
break;
}
case V_428 : {
V_405 = V_408 ;
break;
}
default: {
T_2 V_429 = 1ULL << ( V_395 - V_412 ) ;
if ( V_10 -> V_17 . V_22 & V_429 )
V_405 = V_408 ;
}
}
return V_405 ;
}
static int F_218 ( struct V_7 * V_10 )
{
int V_405 ;
V_405 = F_201 ( V_10 ) ;
if ( V_405 == V_408 )
F_195 ( V_10 ) ;
return V_405 ;
}
static inline void F_219 ( struct V_1 * V_430 , struct V_1 * V_431 )
{
struct V_11 * V_432 = & V_430 -> V_2 ;
struct V_11 * V_433 = & V_431 -> V_2 ;
V_432 -> V_19 = V_433 -> V_19 ;
V_432 -> V_20 = V_433 -> V_20 ;
V_432 -> V_21 = V_433 -> V_21 ;
V_432 -> V_22 = V_433 -> V_22 ;
V_432 -> V_229 = V_433 -> V_229 ;
V_432 -> V_230 = V_433 -> V_230 ;
V_432 -> V_173 = V_433 -> V_173 ;
V_432 -> V_35 = V_433 -> V_35 ;
V_432 -> V_352 = V_433 -> V_352 ;
V_432 -> V_231 = V_433 -> V_231 ;
V_432 -> V_434 = V_433 -> V_434 ;
V_432 -> V_51 = V_433 -> V_51 ;
V_432 -> V_395 = V_433 -> V_395 ;
V_432 -> V_397 = V_433 -> V_397 ;
V_432 -> V_359 = V_433 -> V_359 ;
V_432 -> V_357 = V_433 -> V_357 ;
V_432 -> V_435 = V_433 -> V_435 ;
V_432 -> V_436 = V_433 -> V_436 ;
V_432 -> V_256 = V_433 -> V_256 ;
V_432 -> V_74 = V_433 -> V_74 ;
V_432 -> V_77 = V_433 -> V_77 ;
V_432 -> V_389 = V_433 -> V_389 ;
V_432 -> V_132 = V_433 -> V_132 ;
}
static int F_195 ( struct V_7 * V_10 )
{
struct V_1 * V_437 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_137 * V_137 ;
F_220 ( V_1 -> V_2 . V_395 ,
V_1 -> V_2 . V_359 ,
V_1 -> V_2 . V_357 ,
V_1 -> V_2 . V_435 ,
V_1 -> V_2 . V_436 ,
V_438 ) ;
V_437 = F_205 ( V_10 , V_10 -> V_17 . V_1 , & V_137 ) ;
if ( ! V_437 )
return 1 ;
F_221 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_437 -> V_42 . V_233 = V_1 -> V_42 . V_233 ;
V_437 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_437 -> V_42 . V_234 = V_1 -> V_42 . V_234 ;
V_437 -> V_42 . V_235 = V_1 -> V_42 . V_235 ;
V_437 -> V_42 . V_240 = V_1 -> V_42 . V_240 ;
V_437 -> V_42 . V_241 = V_1 -> V_42 . V_241 ;
V_437 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_437 -> V_42 . V_250 = F_222 ( & V_10 -> V_9 ) ;
V_437 -> V_42 . V_258 = F_131 ( & V_10 -> V_9 ) ;
V_437 -> V_42 . V_407 = V_1 -> V_42 . V_407 ;
V_437 -> V_42 . V_254 = V_10 -> V_9 . V_23 . V_254 ;
V_437 -> V_42 . V_294 = F_223 ( & V_10 -> V_9 ) ;
V_437 -> V_42 . V_68 = V_1 -> V_42 . V_68 ;
V_437 -> V_42 . V_439 = V_1 -> V_42 . V_439 ;
V_437 -> V_42 . V_440 = V_1 -> V_42 . V_440 ;
V_437 -> V_42 . V_247 = V_1 -> V_42 . V_247 ;
V_437 -> V_42 . V_246 = V_1 -> V_42 . V_246 ;
V_437 -> V_42 . V_325 = V_1 -> V_42 . V_325 ;
V_437 -> V_2 . V_231 = V_1 -> V_2 . V_231 ;
V_437 -> V_2 . V_434 = V_1 -> V_2 . V_434 ;
V_437 -> V_2 . V_51 = V_1 -> V_2 . V_51 ;
V_437 -> V_2 . V_395 = V_1 -> V_2 . V_395 ;
V_437 -> V_2 . V_397 = V_1 -> V_2 . V_397 ;
V_437 -> V_2 . V_359 = V_1 -> V_2 . V_359 ;
V_437 -> V_2 . V_357 = V_1 -> V_2 . V_357 ;
V_437 -> V_2 . V_435 = V_1 -> V_2 . V_435 ;
V_437 -> V_2 . V_436 = V_1 -> V_2 . V_436 ;
V_437 -> V_2 . V_55 = V_1 -> V_2 . V_55 ;
if ( V_1 -> V_2 . V_74 & V_47 ) {
struct V_11 * V_441 = & V_437 -> V_2 ;
V_441 -> V_435 = V_1 -> V_2 . V_74 ;
V_441 -> V_436 = V_1 -> V_2 . V_77 ;
}
V_437 -> V_2 . V_352 = 0 ;
V_437 -> V_2 . V_74 = 0 ;
V_437 -> V_2 . V_77 = 0 ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_410 ) )
V_437 -> V_2 . V_231 &= ~ V_232 ;
F_219 ( V_1 , V_18 ) ;
F_224 ( & V_10 -> V_9 ) ;
F_225 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_389 = 0 ;
V_10 -> V_1 -> V_42 . V_233 = V_18 -> V_42 . V_233 ;
V_10 -> V_1 -> V_42 . V_71 = V_18 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_234 = V_18 -> V_42 . V_234 ;
V_10 -> V_1 -> V_42 . V_235 = V_18 -> V_42 . V_235 ;
V_10 -> V_1 -> V_42 . V_240 = V_18 -> V_42 . V_240 ;
V_10 -> V_1 -> V_42 . V_241 = V_18 -> V_42 . V_241 ;
F_103 ( & V_10 -> V_9 , V_18 -> V_42 . V_294 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_42 . V_38 ) ;
F_146 ( & V_10 -> V_9 , V_18 -> V_42 . V_250 | V_442 ) ;
F_148 ( & V_10 -> V_9 , V_18 -> V_42 . V_254 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_258 = V_18 -> V_42 . V_258 ;
V_10 -> V_9 . V_23 . V_258 = V_18 -> V_42 . V_258 ;
} else {
( void ) F_226 ( & V_10 -> V_9 , V_18 -> V_42 . V_258 ) ;
}
F_227 ( & V_10 -> V_9 , V_443 , V_18 -> V_42 . V_440 ) ;
F_227 ( & V_10 -> V_9 , V_444 , V_18 -> V_42 . V_439 ) ;
F_227 ( & V_10 -> V_9 , V_249 , V_18 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_247 = 0 ;
V_10 -> V_1 -> V_42 . V_325 = 0 ;
V_10 -> V_1 -> V_2 . V_435 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_211 ( V_137 ) ;
F_198 ( & V_10 -> V_9 ) ;
F_228 ( & V_10 -> V_9 ) ;
F_229 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_230 ( struct V_7 * V_10 )
{
int V_28 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_215 ) ) )
return true ;
for ( V_28 = 0 ; V_28 < V_130 ; V_28 ++ ) {
T_1 V_355 , V_445 ;
T_2 V_27 ;
if ( V_131 [ V_28 ] == 0xffffffff )
break;
V_445 = V_131 [ V_28 ] ;
V_27 = V_10 -> V_17 . V_419 + ( V_445 * 4 ) ;
if ( F_215 ( V_10 -> V_9 . V_265 , V_27 , & V_355 , 4 ) )
return false ;
V_10 -> V_17 . V_121 [ V_445 ] = V_10 -> V_121 [ V_445 ] | V_355 ;
}
V_10 -> V_1 -> V_2 . V_230 = F_102 ( V_10 -> V_17 . V_121 ) ;
return true ;
}
static bool F_231 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_218 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_35 == 0 )
return false ;
if ( V_1 -> V_2 . V_256 && ! V_39 )
return false ;
return true ;
}
static bool F_232 ( struct V_7 * V_10 )
{
struct V_1 * V_437 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_137 * V_137 ;
T_2 V_446 ;
V_446 = V_10 -> V_1 -> V_42 . V_440 ;
V_437 = F_205 ( V_10 , V_10 -> V_1 -> V_42 . V_440 , & V_137 ) ;
if ( ! V_437 )
return false ;
if ( ! F_231 ( V_437 ) ) {
V_437 -> V_2 . V_395 = V_428 ;
V_437 -> V_2 . V_397 = 0 ;
V_437 -> V_2 . V_359 = 0 ;
V_437 -> V_2 . V_357 = 0 ;
F_211 ( V_137 ) ;
return false ;
}
F_233 ( V_10 -> V_1 -> V_42 . V_68 , V_446 ,
V_437 -> V_42 . V_68 ,
V_437 -> V_2 . V_231 ,
V_437 -> V_2 . V_74 ,
V_437 -> V_2 . V_256 ) ;
F_234 ( V_437 -> V_2 . V_19 & 0xffff ,
V_437 -> V_2 . V_19 >> 16 ,
V_437 -> V_2 . V_21 ,
V_437 -> V_2 . V_22 ) ;
F_224 ( & V_10 -> V_9 ) ;
F_225 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_233 = V_1 -> V_42 . V_233 ;
V_18 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_18 -> V_42 . V_234 = V_1 -> V_42 . V_234 ;
V_18 -> V_42 . V_235 = V_1 -> V_42 . V_235 ;
V_18 -> V_42 . V_240 = V_1 -> V_42 . V_240 ;
V_18 -> V_42 . V_241 = V_1 -> V_42 . V_241 ;
V_18 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_18 -> V_42 . V_250 = F_222 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_254 = V_10 -> V_9 . V_23 . V_254 ;
V_18 -> V_42 . V_294 = F_223 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_68 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_439 = V_1 -> V_42 . V_439 ;
V_18 -> V_42 . V_440 = V_1 -> V_42 . V_440 ;
if ( V_39 )
V_18 -> V_42 . V_258 = V_1 -> V_42 . V_258 ;
else
V_18 -> V_42 . V_258 = F_131 ( & V_10 -> V_9 ) ;
F_219 ( V_18 , V_1 ) ;
if ( F_223 ( & V_10 -> V_9 ) & V_447 )
V_10 -> V_9 . V_23 . V_24 |= V_411 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_411 ;
if ( V_437 -> V_2 . V_256 ) {
F_235 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_389 = V_437 -> V_2 . V_389 ;
F_196 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_42 . V_233 = V_437 -> V_42 . V_233 ;
V_10 -> V_1 -> V_42 . V_71 = V_437 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_234 = V_437 -> V_42 . V_234 ;
V_10 -> V_1 -> V_42 . V_235 = V_437 -> V_42 . V_235 ;
V_10 -> V_1 -> V_42 . V_240 = V_437 -> V_42 . V_240 ;
V_10 -> V_1 -> V_42 . V_241 = V_437 -> V_42 . V_241 ;
F_103 ( & V_10 -> V_9 , V_437 -> V_42 . V_294 ) ;
F_27 ( & V_10 -> V_9 , V_437 -> V_42 . V_38 ) ;
F_146 ( & V_10 -> V_9 , V_437 -> V_42 . V_250 ) ;
F_148 ( & V_10 -> V_9 , V_437 -> V_42 . V_254 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_258 = V_437 -> V_42 . V_258 ;
V_10 -> V_9 . V_23 . V_258 = V_437 -> V_42 . V_258 ;
} else
( void ) F_226 ( & V_10 -> V_9 , V_437 -> V_42 . V_258 ) ;
F_228 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_42 . V_407 = V_10 -> V_9 . V_23 . V_407 = V_437 -> V_42 . V_407 ;
F_227 ( & V_10 -> V_9 , V_443 , V_437 -> V_42 . V_440 ) ;
F_227 ( & V_10 -> V_9 , V_444 , V_437 -> V_42 . V_439 ) ;
F_227 ( & V_10 -> V_9 , V_249 , V_437 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_440 = V_437 -> V_42 . V_440 ;
V_10 -> V_1 -> V_42 . V_439 = V_437 -> V_42 . V_439 ;
V_10 -> V_1 -> V_42 . V_68 = V_437 -> V_42 . V_68 ;
V_10 -> V_1 -> V_42 . V_247 = V_437 -> V_42 . V_247 ;
V_10 -> V_1 -> V_42 . V_246 = V_437 -> V_42 . V_246 ;
V_10 -> V_1 -> V_42 . V_325 = V_437 -> V_42 . V_325 ;
V_10 -> V_17 . V_419 = V_437 -> V_2 . V_230 & ~ 0x0fffULL ;
V_10 -> V_17 . V_417 = V_437 -> V_2 . V_229 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_437 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_437 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_437 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_437 -> V_2 . V_22 ;
F_150 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_231 = V_437 -> V_2 . V_231 | V_232 ;
if ( V_437 -> V_2 . V_231 & V_232 )
V_10 -> V_9 . V_23 . V_24 |= V_410 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_410 ;
if ( V_10 -> V_9 . V_23 . V_24 & V_410 ) {
F_10 ( V_10 , V_448 ) ;
F_10 ( V_10 , V_184 ) ;
}
F_17 ( V_10 , V_219 ) ;
V_10 -> V_1 -> V_2 . V_132 = V_437 -> V_2 . V_132 ;
V_10 -> V_1 -> V_2 . V_434 = V_437 -> V_2 . V_434 ;
V_10 -> V_1 -> V_2 . V_51 = V_437 -> V_2 . V_51 ;
V_10 -> V_1 -> V_2 . V_173 += V_437 -> V_2 . V_173 ;
V_10 -> V_1 -> V_2 . V_74 = V_437 -> V_2 . V_74 ;
V_10 -> V_1 -> V_2 . V_77 = V_437 -> V_2 . V_77 ;
F_211 ( V_137 ) ;
F_236 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_446 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_237 ( struct V_1 * V_431 , struct V_1 * V_449 )
{
V_449 -> V_42 . V_236 = V_431 -> V_42 . V_236 ;
V_449 -> V_42 . V_237 = V_431 -> V_42 . V_237 ;
V_449 -> V_42 . V_244 = V_431 -> V_42 . V_244 ;
V_449 -> V_42 . V_242 = V_431 -> V_42 . V_242 ;
V_449 -> V_42 . V_450 = V_431 -> V_42 . V_450 ;
V_449 -> V_42 . V_451 = V_431 -> V_42 . V_451 ;
V_449 -> V_42 . V_452 = V_431 -> V_42 . V_452 ;
V_449 -> V_42 . V_453 = V_431 -> V_42 . V_453 ;
V_449 -> V_42 . V_454 = V_431 -> V_42 . V_454 ;
V_449 -> V_42 . V_455 = V_431 -> V_42 . V_455 ;
V_449 -> V_42 . V_456 = V_431 -> V_42 . V_456 ;
V_449 -> V_42 . V_457 = V_431 -> V_42 . V_457 ;
}
static int F_238 ( struct V_7 * V_10 )
{
struct V_1 * V_437 ;
struct V_137 * V_137 ;
if ( F_199 ( V_10 ) )
return 1 ;
V_437 = F_205 ( V_10 , V_10 -> V_1 -> V_42 . V_440 , & V_137 ) ;
if ( ! V_437 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_237 ( V_437 , V_10 -> V_1 ) ;
F_211 ( V_137 ) ;
return 1 ;
}
static int F_239 ( struct V_7 * V_10 )
{
struct V_1 * V_437 ;
struct V_137 * V_137 ;
if ( F_199 ( V_10 ) )
return 1 ;
V_437 = F_205 ( V_10 , V_10 -> V_1 -> V_42 . V_440 , & V_137 ) ;
if ( ! V_437 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_237 ( V_10 -> V_1 , V_437 ) ;
F_211 ( V_137 ) ;
return 1 ;
}
static int F_240 ( struct V_7 * V_10 )
{
if ( F_199 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_232 ( V_10 ) )
return 1 ;
if ( ! F_230 ( V_10 ) )
goto V_458;
return 1 ;
V_458:
V_10 -> V_1 -> V_2 . V_395 = V_428 ;
V_10 -> V_1 -> V_2 . V_397 = 0 ;
V_10 -> V_1 -> V_2 . V_359 = 0 ;
V_10 -> V_1 -> V_2 . V_357 = 0 ;
F_195 ( V_10 ) ;
return 1 ;
}
static int F_241 ( struct V_7 * V_10 )
{
if ( F_199 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_176 ( V_459 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_242 ( struct V_7 * V_10 )
{
if ( F_199 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_133 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_231 &= ~ V_460 ;
F_3 ( V_10 -> V_1 , V_461 ) ;
return 1 ;
}
static int F_243 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_244 ( V_10 -> V_1 -> V_42 . V_68 , V_9 -> V_23 . V_248 [ V_418 ] ,
V_9 -> V_23 . V_248 [ V_443 ] ) ;
F_245 ( V_9 , V_9 -> V_23 . V_248 [ V_443 ] ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
F_247 ( V_10 -> V_1 -> V_42 . V_68 , V_10 -> V_9 . V_23 . V_248 [ V_443 ] ) ;
F_166 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static int F_248 ( struct V_7 * V_10 )
{
T_2 V_462 = F_249 ( & V_10 -> V_9 ) ;
T_1 V_119 = F_250 ( & V_10 -> V_9 , V_418 ) ;
if ( F_251 ( & V_10 -> V_9 , V_119 , V_462 ) == 0 ) {
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_252 ( struct V_7 * V_10 )
{
F_166 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
static int F_253 ( struct V_7 * V_10 )
{
T_10 V_463 ;
int V_464 ;
int V_465 = V_10 -> V_1 -> V_2 . V_435 &
V_466 ;
int V_467 = V_10 -> V_1 -> V_2 . V_435 & V_468 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_435 & V_466 ;
T_7 V_469 =
V_10 -> V_1 -> V_2 . V_435 & V_470 ;
bool V_63 = false ;
T_1 V_64 = 0 ;
V_463 = ( T_10 ) V_10 -> V_1 -> V_2 . V_359 ;
if ( V_10 -> V_1 -> V_2 . V_357 &
( 1ULL << V_471 ) )
V_464 = V_472 ;
else if ( V_10 -> V_1 -> V_2 . V_357 &
( 1ULL << V_473 ) )
V_464 = V_474 ;
else if ( V_469 )
V_464 = V_475 ;
else
V_464 = V_476 ;
if ( V_464 == V_475 ) {
switch ( type ) {
case V_477 :
V_10 -> V_9 . V_23 . V_478 = false ;
break;
case V_479 :
if ( V_10 -> V_1 -> V_2 . V_357 &
( 1ULL << V_480 ) ) {
V_63 = true ;
V_64 =
( T_1 ) V_10 -> V_1 -> V_2 . V_357 ;
}
F_224 ( & V_10 -> V_9 ) ;
break;
case V_481 :
F_225 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_464 != V_475 ||
V_465 == V_482 ||
( V_465 == V_479 &&
( V_467 == V_483 || V_467 == V_66 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( F_254 ( & V_10 -> V_9 , V_463 , V_464 ,
V_63 , V_64 ) == V_484 ) {
V_10 -> V_9 . V_365 -> V_368 = V_485 ;
V_10 -> V_9 . V_365 -> V_486 . V_487 = V_488 ;
V_10 -> V_9 . V_365 -> V_486 . V_489 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_255 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_256 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_257 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_289 . V_490 ;
F_17 ( V_10 , V_491 ) ;
V_10 -> V_9 . V_23 . V_24 |= V_492 ;
V_10 -> V_493 = F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_258 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_494 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
F_245 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_359 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_259 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
}
static int F_260 ( struct V_7 * V_10 )
{
int V_80 ;
if ( ! F_38 ( V_67 ) )
return F_259 ( V_10 ) ;
V_80 = F_261 ( & V_10 -> V_9 ) ;
F_262 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
bool F_263 ( struct V_7 * V_10 , unsigned long V_81 )
{
unsigned long V_250 = V_10 -> V_9 . V_23 . V_250 ;
bool V_50 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_207 ) ) ) )
return false ;
V_250 &= ~ V_331 ;
V_81 &= ~ V_331 ;
if ( V_250 ^ V_81 ) {
V_10 -> V_1 -> V_2 . V_395 = V_495 ;
V_50 = ( F_218 ( V_10 ) == V_408 ) ;
}
return V_50 ;
}
static int F_264 ( struct V_7 * V_10 )
{
int V_296 , V_496 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_38 ( V_494 ) )
return F_259 ( V_10 ) ;
if ( F_119 ( ( V_10 -> V_1 -> V_2 . V_359 & V_497 ) == 0 ) )
return F_259 ( V_10 ) ;
V_296 = V_10 -> V_1 -> V_2 . V_359 & V_498 ;
V_496 = V_10 -> V_1 -> V_2 . V_395 - V_423 ;
V_80 = 0 ;
if ( V_496 >= 16 ) {
V_496 -= 16 ;
V_81 = F_250 ( & V_10 -> V_9 , V_296 ) ;
switch ( V_496 ) {
case 0 :
if ( ! F_263 ( V_10 , V_81 ) )
V_80 = F_104 ( & V_10 -> V_9 , V_81 ) ;
else
return 1 ;
break;
case 3 :
V_80 = F_226 ( & V_10 -> V_9 , V_81 ) ;
break;
case 4 :
V_80 = F_265 ( & V_10 -> V_9 , V_81 ) ;
break;
case 8 :
V_80 = F_266 ( & V_10 -> V_9 , V_81 ) ;
break;
default:
F_267 ( 1 , L_11 , V_496 ) ;
F_166 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
} else {
switch ( V_496 ) {
case 0 :
V_81 = F_222 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_81 = V_10 -> V_9 . V_23 . V_407 ;
break;
case 3 :
V_81 = F_131 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_81 = F_268 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_81 = F_269 ( & V_10 -> V_9 ) ;
break;
default:
F_267 ( 1 , L_12 , V_496 ) ;
F_166 ( & V_10 -> V_9 , V_202 ) ;
return 1 ;
}
F_227 ( & V_10 -> V_9 , V_296 , V_81 ) ;
}
F_262 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
static int F_270 ( struct V_7 * V_10 )
{
int V_296 , V_499 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_81 ( V_494 ) )
return F_259 ( V_10 ) ;
V_296 = V_10 -> V_1 -> V_2 . V_359 & V_498 ;
V_499 = V_10 -> V_1 -> V_2 . V_395 - V_425 ;
if ( V_499 >= 16 ) {
V_81 = F_250 ( & V_10 -> V_9 , V_296 ) ;
F_271 ( & V_10 -> V_9 , V_499 - 16 , V_81 ) ;
} else {
V_80 = F_272 ( & V_10 -> V_9 , V_499 , & V_81 ) ;
if ( ! V_80 )
F_227 ( & V_10 -> V_9 , V_296 , V_81 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_273 ( struct V_7 * V_10 )
{
struct V_364 * V_364 = V_10 -> V_9 . V_365 ;
int V_115 ;
T_4 V_500 = F_269 ( & V_10 -> V_9 ) ;
V_115 = F_264 ( V_10 ) ;
if ( F_274 ( V_10 -> V_9 . V_265 ) ) {
F_10 ( V_10 , V_184 ) ;
return V_115 ;
}
if ( V_500 <= F_269 ( & V_10 -> V_9 ) )
return V_115 ;
V_364 -> V_368 = V_501 ;
return 0 ;
}
T_2 F_275 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_173 +
F_93 ( V_9 , F_100 () ) ;
}
static int F_276 ( struct V_8 * V_9 , unsigned V_502 , T_2 * V_503 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_502 ) {
case V_504 : {
* V_503 = V_10 -> V_1 -> V_2 . V_173 +
F_93 ( V_9 , F_100 () ) ;
break;
}
case V_505 :
* V_503 = V_10 -> V_1 -> V_42 . V_451 ;
break;
#ifdef F_26
case V_506 :
* V_503 = V_10 -> V_1 -> V_42 . V_452 ;
break;
case V_507 :
* V_503 = V_10 -> V_1 -> V_42 . V_453 ;
break;
case V_291 :
* V_503 = V_10 -> V_1 -> V_42 . V_450 ;
break;
case V_508 :
* V_503 = V_10 -> V_1 -> V_42 . V_454 ;
break;
#endif
case V_509 :
* V_503 = V_10 -> V_1 -> V_42 . V_455 ;
break;
case V_510 :
* V_503 = V_10 -> V_457 ;
break;
case V_511 :
* V_503 = V_10 -> V_456 ;
break;
case V_512 :
* V_503 = V_10 -> V_1 -> V_42 . V_513 ;
break;
case V_133 :
* V_503 = V_10 -> V_1 -> V_42 . V_514 ;
break;
case V_134 :
* V_503 = V_10 -> V_1 -> V_42 . V_515 ;
break;
case V_135 :
* V_503 = V_10 -> V_1 -> V_42 . V_516 ;
break;
case V_136 :
* V_503 = V_10 -> V_1 -> V_42 . V_517 ;
break;
case V_110 :
* V_503 = V_10 -> V_17 . V_518 ;
break;
case V_519 :
* V_503 = V_10 -> V_17 . V_520 ;
break;
case V_521 :
* V_503 = 0x01000065 ;
break;
default:
return F_277 ( V_9 , V_502 , V_503 ) ;
}
return 0 ;
}
static int F_278 ( struct V_7 * V_10 )
{
T_1 V_502 = V_10 -> V_9 . V_23 . V_248 [ V_418 ] ;
T_2 V_503 ;
if ( F_276 ( & V_10 -> V_9 , V_502 , & V_503 ) ) {
F_279 ( V_502 ) ;
F_200 ( & V_10 -> V_9 , 0 ) ;
} else {
F_280 ( V_502 , V_503 ) ;
V_10 -> V_9 . V_23 . V_248 [ V_443 ] = V_503 & 0xffffffff ;
V_10 -> V_9 . V_23 . V_248 [ V_522 ] = V_503 >> 32 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_281 ( struct V_8 * V_9 , T_2 V_503 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_523 , V_524 ;
if ( V_503 & ~ V_525 )
return 1 ;
V_524 = V_525 ;
if ( V_10 -> V_17 . V_520 & V_526 )
V_524 &= ~ ( V_527 | V_526 ) ;
V_10 -> V_17 . V_520 &= ~ V_524 ;
V_10 -> V_17 . V_520 |= ( V_503 & V_524 ) ;
V_523 = V_10 -> V_17 . V_520 & V_526 ;
if ( V_523 && ( V_9 -> V_23 . V_38 & V_43 ) )
return 1 ;
return 0 ;
}
static int F_282 ( struct V_8 * V_9 , unsigned V_502 , T_2 V_503 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_502 ) {
case V_504 :
F_111 ( V_9 , V_503 ) ;
break;
case V_505 :
V_10 -> V_1 -> V_42 . V_451 = V_503 ;
break;
#ifdef F_26
case V_506 :
V_10 -> V_1 -> V_42 . V_452 = V_503 ;
break;
case V_507 :
V_10 -> V_1 -> V_42 . V_453 = V_503 ;
break;
case V_291 :
V_10 -> V_1 -> V_42 . V_450 = V_503 ;
break;
case V_508 :
V_10 -> V_1 -> V_42 . V_454 = V_503 ;
break;
#endif
case V_509 :
V_10 -> V_1 -> V_42 . V_455 = V_503 ;
break;
case V_510 :
V_10 -> V_457 = V_503 ;
V_10 -> V_1 -> V_42 . V_457 = V_503 ;
break;
case V_511 :
V_10 -> V_456 = V_503 ;
V_10 -> V_1 -> V_42 . V_456 = V_503 ;
break;
case V_512 :
if ( ! F_81 ( V_528 ) ) {
F_283 ( V_9 , L_13 ,
V_59 , V_503 ) ;
break;
}
if ( V_503 & V_529 )
return 1 ;
V_10 -> V_1 -> V_42 . V_513 = V_503 ;
F_3 ( V_10 -> V_1 , V_530 ) ;
if ( V_503 & ( 1ULL << 0 ) )
F_76 ( V_10 ) ;
else
F_77 ( V_10 ) ;
break;
case V_110 :
V_10 -> V_17 . V_518 = V_503 ;
break;
case V_519 :
return F_281 ( V_9 , V_503 ) ;
case V_531 :
F_283 ( V_9 , L_14 , V_502 , V_503 ) ;
break;
default:
return F_284 ( V_9 , V_502 , V_503 ) ;
}
return 0 ;
}
static int F_285 ( struct V_7 * V_10 )
{
T_1 V_502 = V_10 -> V_9 . V_23 . V_248 [ V_418 ] ;
T_2 V_503 = ( V_10 -> V_9 . V_23 . V_248 [ V_443 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_23 . V_248 [ V_522 ] & - 1u ) << 32 ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_282 ( & V_10 -> V_9 , V_502 , V_503 ) ) {
F_286 ( V_502 , V_503 ) ;
F_200 ( & V_10 -> V_9 , 0 ) ;
} else {
F_287 ( V_502 , V_503 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_288 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_359 )
return F_285 ( V_10 ) ;
else
return F_278 ( V_10 ) ;
}
static int F_289 ( struct V_7 * V_10 )
{
struct V_364 * V_364 = V_10 -> V_9 . V_365 ;
F_176 ( V_459 , & V_10 -> V_9 ) ;
F_133 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_231 &= ~ V_460 ;
F_3 ( V_10 -> V_1 , V_461 ) ;
if ( ! F_274 ( V_10 -> V_9 . V_265 ) &&
V_364 -> V_532 &&
! F_290 ( & V_10 -> V_9 ) ) {
++ V_10 -> V_9 . V_289 . V_533 ;
V_364 -> V_368 = V_534 ;
return 0 ;
}
return 1 ;
}
static int F_291 ( struct V_7 * V_10 )
{
F_292 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static void F_293 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_176 * V_42 = & V_10 -> V_1 -> V_42 ;
F_175 ( L_15 ) ;
F_175 ( L_16 , L_17 , V_2 -> V_19 & 0xffff ) ;
F_175 ( L_16 , L_18 , V_2 -> V_19 >> 16 ) ;
F_175 ( L_16 , L_19 , V_2 -> V_20 & 0xffff ) ;
F_175 ( L_16 , L_20 , V_2 -> V_20 >> 16 ) ;
F_175 ( L_21 , L_22 , V_2 -> V_21 ) ;
F_175 ( L_23 , L_24 , V_2 -> V_22 ) ;
F_175 ( L_25 , L_26 , V_2 -> V_260 ) ;
F_175 ( L_23 , L_27 , V_2 -> V_229 ) ;
F_175 ( L_23 , L_28 , V_2 -> V_230 ) ;
F_175 ( L_23 , L_29 , V_2 -> V_173 ) ;
F_175 ( L_25 , L_30 , V_2 -> V_35 ) ;
F_175 ( L_25 , L_31 , V_2 -> V_352 ) ;
F_175 ( L_21 , L_32 , V_2 -> V_231 ) ;
F_175 ( L_21 , L_33 , V_2 -> V_434 ) ;
F_175 ( L_21 , L_34 , V_2 -> V_51 ) ;
F_175 ( L_21 , L_35 , V_2 -> V_395 ) ;
F_175 ( L_23 , L_36 , V_2 -> V_359 ) ;
F_175 ( L_23 , L_37 , V_2 -> V_357 ) ;
F_175 ( L_21 , L_38 , V_2 -> V_435 ) ;
F_175 ( L_21 , L_39 , V_2 -> V_436 ) ;
F_175 ( L_40 , L_41 , V_2 -> V_256 ) ;
F_175 ( L_23 , L_42 , V_2 -> V_389 ) ;
F_175 ( L_21 , L_43 , V_2 -> V_74 ) ;
F_175 ( L_21 , L_44 , V_2 -> V_77 ) ;
F_175 ( L_40 , L_45 , V_2 -> V_132 ) ;
F_175 ( L_23 , L_46 , V_2 -> V_55 ) ;
F_175 ( L_47 ) ;
F_175 ( L_48 ,
L_49 ,
V_42 -> V_233 . V_156 , V_42 -> V_233 . V_157 ,
V_42 -> V_233 . V_161 , V_42 -> V_233 . V_72 ) ;
F_175 ( L_48 ,
L_50 ,
V_42 -> V_71 . V_156 , V_42 -> V_71 . V_157 ,
V_42 -> V_71 . V_161 , V_42 -> V_71 . V_72 ) ;
F_175 ( L_48 ,
L_51 ,
V_42 -> V_234 . V_156 , V_42 -> V_234 . V_157 ,
V_42 -> V_234 . V_161 , V_42 -> V_234 . V_72 ) ;
F_175 ( L_48 ,
L_52 ,
V_42 -> V_235 . V_156 , V_42 -> V_235 . V_157 ,
V_42 -> V_235 . V_161 , V_42 -> V_235 . V_72 ) ;
F_175 ( L_48 ,
L_53 ,
V_42 -> V_236 . V_156 , V_42 -> V_236 . V_157 ,
V_42 -> V_236 . V_161 , V_42 -> V_236 . V_72 ) ;
F_175 ( L_48 ,
L_54 ,
V_42 -> V_237 . V_156 , V_42 -> V_237 . V_157 ,
V_42 -> V_237 . V_161 , V_42 -> V_237 . V_72 ) ;
F_175 ( L_48 ,
L_55 ,
V_42 -> V_240 . V_156 , V_42 -> V_240 . V_157 ,
V_42 -> V_240 . V_161 , V_42 -> V_240 . V_72 ) ;
F_175 ( L_48 ,
L_56 ,
V_42 -> V_242 . V_156 , V_42 -> V_242 . V_157 ,
V_42 -> V_242 . V_161 , V_42 -> V_242 . V_72 ) ;
F_175 ( L_48 ,
L_57 ,
V_42 -> V_241 . V_156 , V_42 -> V_241 . V_157 ,
V_42 -> V_241 . V_161 , V_42 -> V_241 . V_72 ) ;
F_175 ( L_48 ,
L_58 ,
V_42 -> V_244 . V_156 , V_42 -> V_244 . V_157 ,
V_42 -> V_244 . V_161 , V_42 -> V_244 . V_72 ) ;
F_175 ( L_59 ,
V_42 -> V_325 , V_42 -> V_38 ) ;
F_175 ( L_60 ,
L_61 , V_42 -> V_250 , L_62 , V_42 -> V_407 ) ;
F_175 ( L_60 ,
L_63 , V_42 -> V_258 , L_64 , V_42 -> V_254 ) ;
F_175 ( L_60 ,
L_65 , V_42 -> V_246 , L_66 , V_42 -> V_247 ) ;
F_175 ( L_60 ,
L_67 , V_42 -> V_68 , L_68 , V_42 -> V_294 ) ;
F_175 ( L_60 ,
L_69 , V_42 -> V_439 , L_70 , V_42 -> V_440 ) ;
F_175 ( L_60 ,
L_71 , V_42 -> V_451 , L_72 , V_42 -> V_452 ) ;
F_175 ( L_60 ,
L_73 , V_42 -> V_453 , L_74 , V_42 -> V_454 ) ;
F_175 ( L_60 ,
L_75 , V_42 -> V_450 ,
L_76 , V_42 -> V_455 ) ;
F_175 ( L_60 ,
L_77 , V_42 -> V_456 ,
L_78 , V_42 -> V_457 ) ;
F_175 ( L_60 ,
L_79 , V_42 -> V_257 , L_80 , V_42 -> V_513 ) ;
F_175 ( L_60 ,
L_81 , V_42 -> V_514 , L_82 , V_42 -> V_515 ) ;
F_175 ( L_60 ,
L_83 , V_42 -> V_516 ,
L_84 , V_42 -> V_517 ) ;
}
static void F_294 ( struct V_8 * V_9 , T_2 * V_535 , T_2 * V_536 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_535 = V_2 -> V_359 ;
* V_536 = V_2 -> V_357 ;
}
static int F_295 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_364 * V_364 = V_9 -> V_365 ;
T_1 V_395 = V_10 -> V_1 -> V_2 . V_395 ;
if ( ! F_11 ( V_10 , V_181 ) )
V_9 -> V_23 . V_250 = V_10 -> V_1 -> V_42 . V_250 ;
if ( V_39 )
V_9 -> V_23 . V_258 = V_10 -> V_1 -> V_42 . V_258 ;
if ( F_119 ( V_10 -> V_17 . V_409 ) ) {
F_195 ( V_10 ) ;
V_10 -> V_17 . V_409 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_405 ;
F_296 ( V_10 -> V_1 -> V_42 . V_68 , V_395 ,
V_10 -> V_1 -> V_2 . V_359 ,
V_10 -> V_1 -> V_2 . V_357 ,
V_10 -> V_1 -> V_2 . V_435 ,
V_10 -> V_1 -> V_2 . V_436 ,
V_438 ) ;
V_405 = F_217 ( V_10 ) ;
if ( V_405 == V_420 )
V_405 = F_218 ( V_10 ) ;
if ( V_405 == V_408 )
return 1 ;
}
F_297 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_395 == V_428 ) {
V_364 -> V_368 = V_537 ;
V_364 -> V_538 . V_539
= V_10 -> V_1 -> V_2 . V_395 ;
F_175 ( L_85 ) ;
F_293 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_435 ) &&
V_395 != V_406 + V_201 &&
V_395 != V_396 && V_395 != V_540 &&
V_395 != V_412 && V_395 != V_413 )
F_33 ( V_61 L_86
L_87 ,
V_59 , V_10 -> V_1 -> V_2 . V_435 ,
V_395 ) ;
if ( V_395 >= F_298 ( V_541 )
|| ! V_541 [ V_395 ] ) {
V_364 -> V_368 = V_542 ;
V_364 -> V_543 . V_544 = V_395 ;
return 0 ;
}
return V_541 [ V_395 ] ( V_10 ) ;
}
static void F_299 ( struct V_8 * V_9 )
{
int V_114 = F_52 () ;
struct V_91 * V_92 = F_54 ( V_101 , V_114 ) ;
V_92 -> V_107 -> type = 9 ;
F_300 () ;
}
static void F_301 ( struct V_7 * V_10 )
{
int V_114 = F_52 () ;
struct V_91 * V_92 = F_54 ( V_101 , V_114 ) ;
if ( V_10 -> V_102 != V_92 -> V_102 )
F_154 ( V_10 , V_92 ) ;
}
static void F_302 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_74 = V_47 | V_545 ;
V_9 -> V_23 . V_24 |= V_546 ;
F_16 ( V_10 , V_491 ) ;
++ V_9 -> V_289 . V_547 ;
}
static inline void F_303 ( struct V_7 * V_10 , int V_548 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_434 = V_548 ;
V_2 -> V_231 &= ~ V_549 ;
V_2 -> V_231 |= V_460 |
( ( 0xf ) << V_550 ) ;
F_3 ( V_10 -> V_1 , V_461 ) ;
}
static void F_304 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_69 ( ! ( F_20 ( V_10 ) ) ) ;
F_305 ( V_9 -> V_23 . V_551 . V_62 ) ;
++ V_9 -> V_289 . V_552 ;
V_10 -> V_1 -> V_2 . V_74 = V_9 -> V_23 . V_551 . V_62 |
V_47 | V_48 ;
}
static void F_306 ( struct V_8 * V_9 , int V_553 , int V_554 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_410 ) )
return;
if ( V_554 == - 1 )
return;
if ( V_553 >= V_554 )
F_9 ( V_10 , V_184 ) ;
}
static int F_307 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
V_50 = ! ( V_1 -> V_2 . V_51 & V_52 ) &&
! ( V_10 -> V_9 . V_23 . V_24 & V_546 ) ;
V_50 = V_50 && F_20 ( V_10 ) && F_204 ( V_10 ) ;
return V_50 ;
}
static bool F_308 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_546 ) ;
}
static void F_309 ( struct V_8 * V_9 , bool V_555 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_555 ) {
V_10 -> V_9 . V_23 . V_24 |= V_546 ;
F_16 ( V_10 , V_491 ) ;
} else {
V_10 -> V_9 . V_23 . V_24 &= ~ V_546 ;
F_17 ( V_10 , V_491 ) ;
}
}
static int F_310 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_51 & V_52 ) )
return 0 ;
V_50 = ! ! ( F_223 ( V_9 ) & V_447 ) ;
if ( F_7 ( V_9 ) )
return V_50 && ! ( V_10 -> V_9 . V_23 . V_24 & V_410 ) ;
return V_50 ;
}
static void F_311 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_202 ( V_10 ) ) {
F_132 ( V_10 ) ;
F_303 ( V_10 , 0x0 ) ;
}
}
static void F_312 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_23 . V_24 & ( V_546 | V_492 ) )
== V_546 )
return;
V_10 -> V_342 = true ;
V_10 -> V_1 -> V_42 . V_294 |= ( V_366 | V_367 ) ;
F_152 ( V_9 ) ;
}
static int F_313 ( struct V_265 * V_265 , unsigned int V_34 )
{
return 0 ;
}
static void F_150 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_556 ) )
V_10 -> V_1 -> V_2 . V_352 = V_557 ;
else
V_10 -> V_102 -- ;
}
static void F_314 ( struct V_8 * V_9 )
{
}
static inline void F_315 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_410 ) )
return;
if ( ! F_11 ( V_10 , V_184 ) ) {
int V_558 = V_10 -> V_1 -> V_2 . V_231 & V_559 ;
F_266 ( V_9 , V_558 ) ;
}
}
static inline void F_316 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_558 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_410 ) )
return;
V_558 = F_269 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_231 &= ~ V_559 ;
V_10 -> V_1 -> V_2 . V_231 |= V_558 & V_559 ;
}
static void F_297 ( struct V_7 * V_10 )
{
T_4 V_560 ;
int type ;
T_1 V_561 = V_10 -> V_1 -> V_2 . V_435 ;
unsigned V_73 = V_10 -> V_73 ;
V_10 -> V_73 = 0 ;
if ( ( V_10 -> V_9 . V_23 . V_24 & V_492 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_493 ) {
V_10 -> V_9 . V_23 . V_24 &= ~ ( V_546 | V_492 ) ;
F_176 ( V_459 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_23 . V_478 = false ;
F_224 ( & V_10 -> V_9 ) ;
F_225 ( & V_10 -> V_9 ) ;
if ( ! ( V_561 & V_470 ) )
return;
F_176 ( V_459 , & V_10 -> V_9 ) ;
V_560 = V_561 & V_562 ;
type = V_561 & V_466 ;
switch ( type ) {
case V_477 :
V_10 -> V_9 . V_23 . V_478 = true ;
break;
case V_479 :
if ( F_317 ( V_560 ) ) {
if ( V_560 == V_66 && V_73 &&
F_318 ( & V_10 -> V_9 , V_10 -> V_70 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_73 ) ;
break;
}
if ( V_561 & V_563 ) {
T_1 V_80 = V_10 -> V_1 -> V_2 . V_436 ;
F_319 ( & V_10 -> V_9 , V_560 , V_80 ) ;
} else
F_320 ( & V_10 -> V_9 , V_560 ) ;
break;
case V_481 :
F_321 ( & V_10 -> V_9 , V_560 , false ) ;
break;
default:
break;
}
}
static void F_322 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_435 = V_2 -> V_74 ;
V_2 -> V_436 = V_2 -> V_77 ;
V_2 -> V_74 = 0 ;
F_297 ( V_10 ) ;
}
static void F_323 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_440 = V_9 -> V_23 . V_248 [ V_443 ] ;
V_10 -> V_1 -> V_42 . V_439 = V_9 -> V_23 . V_248 [ V_444 ] ;
V_10 -> V_1 -> V_42 . V_68 = V_9 -> V_23 . V_248 [ V_249 ] ;
if ( F_119 ( V_10 -> V_17 . V_409 ) )
return;
F_301 ( V_10 ) ;
F_316 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_407 = V_9 -> V_23 . V_407 ;
F_22 () ;
F_163 () ;
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
F_48 ( V_282 , V_10 -> V_283 . V_284 ) ;
#else
F_124 ( V_236 , V_10 -> V_283 . V_236 ) ;
#ifndef F_126
F_124 ( V_237 , V_10 -> V_283 . V_237 ) ;
#endif
#endif
F_299 ( V_9 ) ;
F_161 () ;
V_9 -> V_23 . V_407 = V_10 -> V_1 -> V_42 . V_407 ;
V_9 -> V_23 . V_248 [ V_443 ] = V_10 -> V_1 -> V_42 . V_440 ;
V_9 -> V_23 . V_248 [ V_444 ] = V_10 -> V_1 -> V_42 . V_439 ;
V_9 -> V_23 . V_248 [ V_249 ] = V_10 -> V_1 -> V_42 . V_68 ;
F_324 ( V_10 -> V_1 -> V_2 . V_395 , V_9 , V_438 ) ;
if ( F_119 ( V_10 -> V_1 -> V_2 . V_395 == V_413 ) )
F_325 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_119 ( V_10 -> V_1 -> V_2 . V_395 == V_413 ) )
F_326 ( & V_10 -> V_9 ) ;
F_315 ( V_9 ) ;
V_10 -> V_55 = 0 ;
V_10 -> V_1 -> V_2 . V_352 = V_564 ;
if ( V_10 -> V_1 -> V_2 . V_395 == V_406 + V_201 )
V_10 -> V_358 = F_327 () ;
if ( V_39 ) {
V_9 -> V_23 . V_263 &= ~ ( 1 << V_297 ) ;
V_9 -> V_23 . V_264 &= ~ ( 1 << V_297 ) ;
}
if ( F_119 ( V_10 -> V_1 -> V_2 . V_395 ==
V_406 + V_203 ) )
F_174 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_328 ( struct V_8 * V_9 , unsigned long V_391 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_258 = V_391 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_150 ( V_9 ) ;
}
static void F_329 ( struct V_8 * V_9 , unsigned long V_391 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_389 = V_391 ;
F_3 ( V_10 -> V_1 , V_392 ) ;
V_10 -> V_1 -> V_42 . V_258 = F_131 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_150 ( V_9 ) ;
}
static int F_330 ( void )
{
T_2 V_565 ;
F_53 ( V_519 , V_565 ) ;
if ( V_565 & ( 1 << V_566 ) )
return 1 ;
return 0 ;
}
static void
F_331 ( struct V_8 * V_9 , unsigned char * V_567 )
{
V_567 [ 0 ] = 0x0f ;
V_567 [ 1 ] = 0x01 ;
V_567 [ 2 ] = 0xd9 ;
}
static void F_332 ( void * V_568 )
{
* ( int * ) V_568 = 0 ;
}
static bool F_333 ( void )
{
return false ;
}
static T_2 F_334 ( struct V_8 * V_9 , T_11 V_569 , bool V_570 )
{
return 0 ;
}
static void F_335 ( struct V_8 * V_9 )
{
}
static void F_336 ( T_1 V_571 , struct V_572 * V_573 )
{
switch ( V_571 ) {
case 0x80000001 :
if ( V_17 )
V_573 -> V_502 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_573 -> V_574 = 1 ;
V_573 -> V_575 = 8 ;
V_573 -> V_502 = 0 ;
V_573 -> V_576 = 0 ;
if ( F_81 ( V_67 ) )
V_573 -> V_576 |= V_577 ;
if ( V_39 )
V_573 -> V_576 |= V_578 ;
break;
}
}
static int F_337 ( void )
{
return V_579 ;
}
static bool F_338 ( void )
{
return false ;
}
static bool F_339 ( void )
{
return true ;
}
static void F_340 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_375 ) ;
F_145 ( V_10 ) ;
}
static int F_341 ( struct V_8 * V_9 ,
struct V_580 * V_45 ,
enum V_581 V_582 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_405 , V_50 = V_583 ;
struct V_584 V_585 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_45 -> V_22 >= F_298 ( V_586 ) )
goto V_271;
V_585 = V_586 [ V_45 -> V_22 ] ;
if ( V_582 != V_585 . V_582 )
goto V_271;
switch ( V_585 . V_395 ) {
case V_423 :
if ( V_45 -> V_22 == V_587 )
V_585 . V_395 += V_45 -> V_588 ;
break;
case V_589 : {
unsigned long V_250 , V_81 ;
T_2 V_22 ;
if ( V_45 -> V_22 == V_590 )
V_585 . V_395 += V_45 -> V_588 ;
if ( V_585 . V_395 != V_589 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_207 ) ) )
break;
V_250 = V_9 -> V_23 . V_250 & ~ V_331 ;
V_81 = V_45 -> V_591 & ~ V_331 ;
if ( V_45 -> V_22 == V_592 ) {
V_250 &= 0xfUL ;
V_81 &= 0xfUL ;
if ( V_250 & V_442 )
V_81 |= V_442 ;
}
if ( V_250 ^ V_81 )
V_585 . V_395 = V_495 ;
break;
}
case V_425 :
case V_593 :
V_585 . V_395 += V_45 -> V_588 ;
break;
case V_421 :
if ( V_45 -> V_22 == V_594 )
V_1 -> V_2 . V_359 = 1 ;
else
V_1 -> V_2 . V_359 = 0 ;
break;
case V_595 :
if ( V_45 -> V_596 != V_597 )
goto V_271;
case V_422 : {
T_2 V_598 ;
T_1 V_599 ;
V_598 = ( V_9 -> V_23 . V_248 [ V_522 ] & 0xffff ) << 16 ;
if ( V_45 -> V_22 == V_600 ||
V_45 -> V_22 == V_601 ) {
V_598 |= V_385 ;
V_599 = V_45 -> V_602 ;
} else {
V_599 = V_45 -> V_603 ;
}
if ( V_45 -> V_22 == V_604 ||
V_45 -> V_22 == V_601 )
V_598 |= V_384 ;
if ( V_45 -> V_596 )
V_598 |= V_605 ;
V_599 = F_83 ( V_599 , 4u ) ;
V_598 |= V_599 << V_387 ;
V_598 |= ( T_1 ) V_45 -> V_606 << ( V_607 - 1 ) ;
V_1 -> V_2 . V_359 = V_598 ;
V_1 -> V_2 . V_357 = V_45 -> V_55 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_55 = V_45 -> V_55 ;
V_1 -> V_2 . V_395 = V_585 . V_395 ;
V_405 = F_218 ( V_10 ) ;
V_50 = ( V_405 == V_408 ) ? V_608
: V_583 ;
V_271:
return V_50 ;
}
static int T_5 F_342 ( void )
{
return F_343 ( & V_609 , sizeof( struct V_7 ) ,
F_344 ( struct V_7 ) , V_610 ) ;
}
static void T_6 F_345 ( void )
{
F_346 () ;
}
