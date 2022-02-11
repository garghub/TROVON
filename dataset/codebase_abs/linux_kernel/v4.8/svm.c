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
static inline void F_6 ( struct V_7 * V_10 , T_1 V_11 )
{
V_10 -> V_1 -> V_2 . V_12 = V_11 & V_13 ;
F_3 ( V_10 -> V_1 , V_14 ) ;
}
static inline bool F_7 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 * V_15 = V_10 -> V_16 ;
if ( ! V_15 )
return false ;
return ( F_8 ( * V_15 ) & V_17 ) ;
}
static void F_9 ( struct V_7 * V_10 )
{
struct V_18 * V_19 , * V_20 ;
struct V_21 * V_22 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return;
V_19 = & V_10 -> V_1 -> V_2 ;
V_20 = & V_10 -> V_24 . V_25 -> V_2 ;
V_22 = & V_10 -> V_24 ;
V_19 -> V_26 = V_20 -> V_26 | V_22 -> V_26 ;
V_19 -> V_27 = V_20 -> V_27 | V_22 -> V_27 ;
V_19 -> V_28 = V_20 -> V_28 | V_22 -> V_28 ;
V_19 -> V_29 = V_20 -> V_29 | V_22 -> V_29 ;
}
static inline struct V_1 * F_11 ( struct V_7 * V_10 )
{
if ( F_10 ( & V_10 -> V_9 ) )
return V_10 -> V_24 . V_25 ;
else
return V_10 -> V_1 ;
}
static inline void F_12 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_26 |= ( 1U << V_6 ) ;
F_9 ( V_10 ) ;
}
static inline void F_13 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_26 &= ~ ( 1U << V_6 ) ;
F_9 ( V_10 ) ;
}
static inline bool F_14 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
return V_1 -> V_2 . V_26 & ( 1U << V_6 ) ;
}
static inline void F_15 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_27 = ( 1 << V_30 )
| ( 1 << V_31 )
| ( 1 << V_32 )
| ( 1 << V_33 )
| ( 1 << V_34 )
| ( 1 << V_35 )
| ( 1 << V_36 )
| ( 1 << V_37 )
| ( 1 << V_38 )
| ( 1 << V_39 )
| ( 1 << V_40 )
| ( 1 << V_41 )
| ( 1 << V_42 )
| ( 1 << V_43 )
| ( 1 << V_44 )
| ( 1 << V_45 ) ;
F_9 ( V_10 ) ;
}
static inline void F_16 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_27 = 0 ;
F_9 ( V_10 ) ;
}
static inline void F_17 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_28 |= ( 1U << V_6 ) ;
F_9 ( V_10 ) ;
}
static inline void F_18 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_28 &= ~ ( 1U << V_6 ) ;
F_9 ( V_10 ) ;
}
static inline void F_19 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_29 |= ( 1ULL << V_6 ) ;
F_9 ( V_10 ) ;
}
static inline void F_20 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_11 ( V_10 ) ;
V_1 -> V_2 . V_29 &= ~ ( 1ULL << V_6 ) ;
F_9 ( V_10 ) ;
}
static inline void F_21 ( struct V_7 * V_10 )
{
V_10 -> V_9 . V_46 . V_47 |= V_48 ;
}
static inline void F_22 ( struct V_7 * V_10 )
{
V_10 -> V_9 . V_46 . V_47 &= ~ V_48 ;
}
static inline bool F_23 ( struct V_7 * V_10 )
{
return ! ! ( V_10 -> V_9 . V_46 . V_47 & V_48 ) ;
}
static T_2 F_24 ( T_2 V_49 )
{
T_2 V_50 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( V_49 < V_53 [ V_51 ] ||
V_49 >= V_53 [ V_51 ] + V_54 )
continue;
V_50 = ( V_49 - V_53 [ V_51 ] ) / 4 ;
V_50 += ( V_51 * V_55 ) ;
return V_50 / 4 ;
}
return V_56 ;
}
static inline void F_25 ( void )
{
asm volatile (__ex(SVM_CLGI));
}
static inline void F_26 ( void )
{
asm volatile (__ex(SVM_STGI));
}
static inline void F_27 ( unsigned long V_57 , T_2 V_58 )
{
asm volatile (__ex(SVM_INVLPGA) : : "a"(addr), "c"(asid));
}
static int F_28 ( void )
{
#ifdef F_29
return V_59 ;
#else
return V_60 ;
#endif
}
static void F_30 ( struct V_8 * V_9 , T_1 V_61 )
{
V_9 -> V_46 . V_61 = V_61 ;
if ( ! V_62 && ! ( V_61 & V_63 ) )
V_61 &= ~ V_64 ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_61 = V_61 | V_66 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_67 ) ;
}
static int F_31 ( T_2 V_68 )
{
V_68 &= V_69 | V_70 ;
return V_68 == ( V_70 | V_71 ) ;
}
static T_2 F_32 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_72 = 0 ;
if ( V_10 -> V_1 -> V_2 . V_73 & V_74 )
V_72 = V_75 | V_76 ;
return V_72 ;
}
static void F_33 ( struct V_8 * V_9 , int V_77 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_77 == 0 )
V_10 -> V_1 -> V_2 . V_73 &= ~ V_74 ;
else
V_10 -> V_1 -> V_2 . V_73 |= V_74 ;
}
static void F_34 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_78 != 0 ) {
F_35 ( ! F_36 ( V_79 ) ) ;
V_10 -> V_78 = V_10 -> V_1 -> V_2 . V_78 ;
}
if ( ! V_10 -> V_78 ) {
if ( F_37 ( V_9 , V_80 ) !=
V_81 )
F_38 ( V_82 L_1 , V_83 ) ;
return;
}
if ( V_10 -> V_78 - F_39 ( V_9 ) > V_84 )
F_38 ( V_85 L_2 ,
V_83 , F_39 ( V_9 ) , V_10 -> V_78 ) ;
F_40 ( V_9 , V_10 -> V_78 ) ;
F_33 ( V_9 , 0 ) ;
}
static void F_41 ( struct V_8 * V_9 , unsigned V_86 ,
bool V_87 , T_2 V_88 ,
bool V_89 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! V_89 &&
F_42 ( V_10 , V_86 , V_87 , V_88 ) )
return;
if ( V_86 == V_90 && ! F_36 ( V_79 ) ) {
unsigned long V_91 , V_92 = F_39 ( & V_10 -> V_9 ) ;
F_34 ( & V_10 -> V_9 ) ;
V_91 = F_39 ( & V_10 -> V_9 ) ;
V_10 -> V_93 = V_91 + V_10 -> V_1 -> V_65 . V_94 . V_95 ;
V_10 -> V_96 = V_91 - V_92 ;
}
V_10 -> V_1 -> V_2 . V_97 = V_86
| V_70
| ( V_87 ? V_98 : 0 )
| V_99 ;
V_10 -> V_1 -> V_2 . V_100 = V_88 ;
}
static void F_43 ( void )
{
T_2 V_101 , V_102 ;
int V_103 ;
T_1 V_104 ;
if ( ! F_44 ( V_105 ) )
return;
V_104 = F_45 ( V_106 , & V_103 ) ;
if ( V_103 )
return;
V_104 |= ( 1ULL << 47 ) ;
V_101 = F_46 ( V_104 ) ;
V_102 = F_47 ( V_104 ) ;
F_48 ( V_106 , V_101 , V_102 ) ;
V_107 = true ;
}
static void F_49 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_108 . V_109 = ( V_110 >= 3 ) ? ( V_110 ) : 3 ;
V_9 -> V_46 . V_108 . V_111 = V_112 & ~ ( 6ULL ) ;
if ( V_110 == 0 && V_113 . V_114 == 0x10 )
V_9 -> V_46 . V_108 . V_111 |= 1 ;
}
static int F_50 ( void )
{
const char * V_115 ;
if ( ! F_51 ( & V_115 ) ) {
F_38 ( V_116 L_3 , V_115 ) ;
return 0 ;
}
return 1 ;
}
static void F_52 ( void )
{
if ( F_36 ( V_117 ) )
F_53 ( V_118 , V_119 ) ;
F_54 () ;
F_55 () ;
}
static int F_56 ( void )
{
struct V_120 * V_121 ;
T_3 V_61 ;
struct V_122 V_123 ;
struct V_124 * V_125 ;
int V_126 = F_57 () ;
F_58 ( V_127 , V_61 ) ;
if ( V_61 & V_66 )
return - V_128 ;
if ( ! F_50 () ) {
F_59 ( L_4 , V_83 , V_126 ) ;
return - V_129 ;
}
V_121 = F_60 ( V_130 , V_126 ) ;
if ( ! V_121 ) {
F_59 ( L_5 , V_83 , V_126 ) ;
return - V_129 ;
}
V_121 -> V_131 = 1 ;
V_121 -> V_132 = F_61 ( V_133 ) - 1 ;
V_121 -> V_134 = V_121 -> V_132 + 1 ;
F_62 ( & V_123 ) ;
V_125 = (struct V_124 * ) V_123 . V_135 ;
V_121 -> V_136 = (struct V_137 * ) ( V_125 + V_138 ) ;
F_53 ( V_127 , V_61 | V_66 ) ;
F_53 ( V_139 , F_63 ( V_121 -> V_140 ) << V_141 ) ;
if ( F_36 ( V_117 ) ) {
F_53 ( V_118 , V_119 ) ;
F_64 ( V_142 , V_119 ) ;
}
if ( F_65 ( & V_113 , V_143 ) ) {
T_3 V_144 , V_111 = 0 ;
int V_103 ;
V_144 = F_45 ( V_145 , & V_103 ) ;
if ( ! V_103 )
V_111 = F_45 ( V_146 ,
& V_103 ) ;
if ( V_103 )
V_112 = V_110 = 0 ;
else {
if ( V_144 < V_110 )
V_110 = V_144 ;
V_112 |= V_111 ;
V_112 &= ( 1ULL << V_110 ) - 1 ;
}
} else
V_112 = V_110 = 0 ;
F_43 () ;
F_66 () ;
return 0 ;
}
static void F_67 ( int V_147 )
{
struct V_120 * V_121 = F_60 ( V_130 , F_57 () ) ;
if ( ! V_121 )
return;
F_60 ( V_130 , F_57 () ) = NULL ;
F_68 ( V_121 -> V_140 ) ;
F_69 ( V_121 ) ;
}
static int F_70 ( int V_147 )
{
struct V_120 * V_121 ;
int V_148 ;
V_121 = F_71 ( sizeof( struct V_120 ) , V_149 ) ;
if ( ! V_121 )
return - V_150 ;
V_121 -> V_147 = V_147 ;
V_121 -> V_140 = F_72 ( V_149 ) ;
V_148 = - V_150 ;
if ( ! V_121 -> V_140 )
goto V_151;
F_60 ( V_130 , V_147 ) = V_121 ;
return 0 ;
V_151:
F_69 ( V_121 ) ;
return V_148 ;
}
static bool F_73 ( T_2 V_152 )
{
int V_51 ;
for ( V_51 = 0 ; V_153 [ V_51 ] . V_152 != V_56 ; V_51 ++ )
if ( V_153 [ V_51 ] . V_152 == V_152 )
return true ;
return false ;
}
static void F_74 ( T_2 * V_154 , unsigned V_49 ,
int V_155 , int V_156 )
{
T_4 V_157 , V_158 ;
unsigned long V_159 ;
T_2 V_50 ;
F_75 ( ! F_73 ( V_49 ) ) ;
V_50 = F_24 ( V_49 ) ;
V_157 = 2 * ( V_49 & 0x0f ) ;
V_158 = 2 * ( V_49 & 0x0f ) + 1 ;
V_159 = V_154 [ V_50 ] ;
F_76 ( V_50 == V_56 ) ;
V_155 ? F_77 ( V_157 , & V_159 ) : F_78 ( V_157 , & V_159 ) ;
V_156 ? F_77 ( V_158 , & V_159 ) : F_78 ( V_158 , & V_159 ) ;
V_154 [ V_50 ] = V_159 ;
}
static void F_79 ( T_2 * V_154 )
{
int V_51 ;
memset ( V_154 , 0xff , V_160 * ( 1 << V_161 ) ) ;
for ( V_51 = 0 ; V_153 [ V_51 ] . V_152 != V_56 ; V_51 ++ ) {
if ( ! V_153 [ V_51 ] . V_162 )
continue;
F_74 ( V_154 , V_153 [ V_51 ] . V_152 , 1 , 1 ) ;
}
}
static void F_80 ( T_2 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_163 ; ++ V_51 ) {
if ( V_164 [ V_51 ] == V_50 )
return;
if ( V_164 [ V_51 ] != V_56 )
continue;
V_164 [ V_51 ] = V_50 ;
return;
}
F_81 () ;
}
static void F_82 ( void )
{
int V_51 ;
memset ( V_164 , 0xff , sizeof( V_164 ) ) ;
for ( V_51 = 0 ; V_153 [ V_51 ] . V_152 != V_56 ; V_51 ++ ) {
T_2 V_50 ;
V_50 = F_24 ( V_153 [ V_51 ] . V_152 ) ;
F_76 ( V_50 == V_56 ) ;
F_80 ( V_50 ) ;
}
}
static void F_83 ( struct V_7 * V_10 )
{
T_2 * V_154 = V_10 -> V_154 ;
V_10 -> V_1 -> V_2 . V_165 = 1 ;
F_74 ( V_154 , V_166 , 1 , 1 ) ;
F_74 ( V_154 , V_167 , 1 , 1 ) ;
F_74 ( V_154 , V_168 , 1 , 1 ) ;
F_74 ( V_154 , V_169 , 1 , 1 ) ;
}
static void F_84 ( struct V_7 * V_10 )
{
T_2 * V_154 = V_10 -> V_154 ;
V_10 -> V_1 -> V_2 . V_165 = 0 ;
F_74 ( V_154 , V_166 , 0 , 0 ) ;
F_74 ( V_154 , V_167 , 0 , 0 ) ;
F_74 ( V_154 , V_168 , 0 , 0 ) ;
F_74 ( V_154 , V_169 , 0 , 0 ) ;
}
static T_5 int F_85 ( void )
{
int V_147 ;
struct V_170 * V_171 ;
void * V_172 ;
int V_148 ;
V_171 = F_86 ( V_149 , V_173 ) ;
if ( ! V_171 )
return - V_150 ;
V_172 = F_87 ( V_171 ) ;
memset ( V_172 , 0xff , V_160 * ( 1 << V_173 ) ) ;
V_174 = F_63 ( V_171 ) << V_141 ;
F_82 () ;
if ( F_88 ( V_175 ) )
F_89 ( V_176 ) ;
if ( F_88 ( V_177 ) )
F_89 ( V_178 ) ;
if ( F_88 ( V_117 ) ) {
V_179 = true ;
V_180 = V_181 ;
V_182 = 32 ;
}
if ( V_24 ) {
F_38 ( V_116 L_6 ) ;
F_89 ( V_66 | V_183 ) ;
}
F_90 (cpu) {
V_148 = F_70 ( V_147 ) ;
if ( V_148 )
goto V_103;
}
if ( ! F_88 ( V_184 ) )
V_62 = false ;
if ( V_62 && ! V_185 ) {
F_38 ( V_116 L_7 ) ;
V_62 = false ;
}
if ( V_62 ) {
F_38 ( V_116 L_8 ) ;
F_91 () ;
} else
F_92 () ;
if ( V_186 ) {
if ( ! V_62 ||
! F_88 ( V_187 ) ||
! F_93 ( V_188 ) )
V_186 = false ;
else
F_94 ( L_9 ) ;
}
return 0 ;
V_103:
F_95 ( V_171 , V_173 ) ;
V_174 = 0 ;
return V_148 ;
}
static T_6 void F_96 ( void )
{
int V_147 ;
F_90 (cpu)
F_67 ( V_147 ) ;
F_95 ( F_97 ( V_174 >> V_141 ) , V_173 ) ;
V_174 = 0 ;
}
static void F_98 ( struct V_189 * V_190 )
{
V_190 -> V_191 = 0 ;
V_190 -> V_192 = V_193 | V_194 |
V_195 ;
V_190 -> V_196 = 0xffff ;
V_190 -> V_95 = 0 ;
}
static void F_99 ( struct V_189 * V_190 , T_7 type )
{
V_190 -> V_191 = 0 ;
V_190 -> V_192 = V_193 | type ;
V_190 -> V_196 = 0xffff ;
V_190 -> V_95 = 0 ;
}
static T_1 F_100 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_197 ;
}
static void F_101 ( struct V_8 * V_9 , T_1 V_50 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_198 = 0 ;
if ( F_10 ( V_9 ) ) {
V_198 = V_10 -> V_1 -> V_2 . V_197 -
V_10 -> V_24 . V_25 -> V_2 . V_197 ;
V_10 -> V_24 . V_25 -> V_2 . V_197 = V_50 ;
} else
F_102 ( V_9 -> V_199 ,
V_10 -> V_1 -> V_2 . V_197 ,
V_50 ) ;
V_10 -> V_1 -> V_2 . V_197 = V_50 + V_198 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_103 ( struct V_8 * V_9 , T_8 V_200 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_197 += V_200 ;
if ( F_10 ( V_9 ) )
V_10 -> V_24 . V_25 -> V_2 . V_197 += V_200 ;
else
F_102 ( V_9 -> V_199 ,
V_10 -> V_1 -> V_2 . V_197 - V_200 ,
V_10 -> V_1 -> V_2 . V_197 ) ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_104 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_201 * V_202 = & V_10 -> V_9 . V_203 -> V_46 ;
T_9 V_204 = F_105 ( V_10 -> V_205 ) ;
T_9 V_206 = F_105 ( V_202 -> V_207 ) ;
T_9 V_208 = F_105 ( V_202 -> V_209 ) ;
V_1 -> V_2 . V_205 = V_204 & V_210 ;
V_1 -> V_2 . V_211 = V_206 & V_210 ;
V_1 -> V_2 . V_212 = V_208 & V_210 ;
V_1 -> V_2 . V_212 |= V_213 ;
V_1 -> V_2 . V_214 |= V_215 ;
V_10 -> V_9 . V_46 . V_216 = true ;
}
static void F_106 ( struct V_7 * V_10 )
{
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_217 * V_65 = & V_10 -> V_1 -> V_65 ;
V_10 -> V_9 . V_218 = 1 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
F_12 ( V_10 , V_219 ) ;
F_12 ( V_10 , V_220 ) ;
F_12 ( V_10 , V_221 ) ;
F_12 ( V_10 , V_222 ) ;
F_12 ( V_10 , V_223 ) ;
F_12 ( V_10 , V_224 ) ;
if ( ! F_107 ( & V_10 -> V_9 ) )
F_12 ( V_10 , V_225 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_226 ) ;
F_17 ( V_10 , V_227 ) ;
F_17 ( V_10 , V_228 ) ;
F_17 ( V_10 , V_229 ) ;
F_17 ( V_10 , V_230 ) ;
F_19 ( V_10 , V_231 ) ;
F_19 ( V_10 , V_232 ) ;
F_19 ( V_10 , V_233 ) ;
F_19 ( V_10 , V_234 ) ;
F_19 ( V_10 , V_235 ) ;
F_19 ( V_10 , V_236 ) ;
F_19 ( V_10 , V_237 ) ;
F_19 ( V_10 , V_238 ) ;
F_19 ( V_10 , V_239 ) ;
F_19 ( V_10 , V_240 ) ;
F_19 ( V_10 , V_241 ) ;
F_19 ( V_10 , V_242 ) ;
F_19 ( V_10 , V_243 ) ;
F_19 ( V_10 , V_244 ) ;
F_19 ( V_10 , V_245 ) ;
F_19 ( V_10 , V_246 ) ;
F_19 ( V_10 , V_247 ) ;
F_19 ( V_10 , V_248 ) ;
F_19 ( V_10 , V_249 ) ;
F_19 ( V_10 , V_250 ) ;
F_19 ( V_10 , V_251 ) ;
F_19 ( V_10 , V_252 ) ;
F_19 ( V_10 , V_253 ) ;
F_19 ( V_10 , V_254 ) ;
F_19 ( V_10 , V_255 ) ;
V_2 -> V_256 = V_174 ;
V_2 -> V_257 = F_108 ( V_10 -> V_154 ) ;
V_2 -> V_214 = V_258 ;
F_98 ( & V_65 -> V_259 ) ;
F_98 ( & V_65 -> V_260 ) ;
F_98 ( & V_65 -> V_261 ) ;
F_98 ( & V_65 -> V_262 ) ;
F_98 ( & V_65 -> V_263 ) ;
V_65 -> V_94 . V_191 = 0xf000 ;
V_65 -> V_94 . V_95 = 0xffff0000 ;
V_65 -> V_94 . V_192 = V_264 | V_193 |
V_194 | V_265 ;
V_65 -> V_94 . V_196 = 0xffff ;
V_65 -> V_266 . V_196 = 0xffff ;
V_65 -> V_267 . V_196 = 0xffff ;
F_99 ( & V_65 -> V_268 , V_269 ) ;
F_99 ( & V_65 -> V_270 , V_271 ) ;
F_30 ( & V_10 -> V_9 , 0 ) ;
V_65 -> V_272 = 0xffff0ff0 ;
F_109 ( & V_10 -> V_9 , 2 ) ;
V_65 -> V_91 = 0x0000fff0 ;
V_10 -> V_9 . V_46 . V_273 [ V_274 ] = V_65 -> V_91 ;
F_110 ( & V_10 -> V_9 , V_275 | V_276 | V_277 ) ;
F_111 ( & V_10 -> V_9 ) ;
V_65 -> V_278 = V_279 ;
if ( V_62 ) {
V_2 -> V_280 = 1 ;
F_20 ( V_10 , V_239 ) ;
F_18 ( V_10 , V_226 ) ;
F_13 ( V_10 , V_220 ) ;
F_13 ( V_10 , V_223 ) ;
V_65 -> V_281 = V_10 -> V_9 . V_46 . V_282 ;
V_65 -> V_283 = 0 ;
V_65 -> V_278 = 0 ;
}
V_10 -> V_131 = 0 ;
V_10 -> V_24 . V_1 = 0 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
if ( F_88 ( V_284 ) ) {
V_2 -> V_285 = 3000 ;
F_19 ( V_10 , V_286 ) ;
}
if ( V_186 )
F_104 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
F_21 ( V_10 ) ;
}
static T_1 * F_112 ( struct V_8 * V_9 , int V_152 )
{
T_1 * V_287 ;
struct V_201 * V_202 = & V_9 -> V_203 -> V_46 ;
if ( V_152 >= V_213 )
return NULL ;
V_287 = F_87 ( V_202 -> V_209 ) ;
return & V_287 [ V_152 ] ;
}
static int F_113 ( struct V_8 * V_9 )
{
struct V_203 * V_203 = V_9 -> V_203 ;
int V_72 ;
if ( V_203 -> V_46 . V_288 )
return 0 ;
V_72 = F_114 ( V_203 ,
V_289 ,
V_290 ,
V_160 ) ;
if ( V_72 )
return V_72 ;
V_203 -> V_46 . V_288 = true ;
return 0 ;
}
static int F_115 ( struct V_8 * V_9 )
{
int V_72 ;
T_1 * V_15 , V_291 ;
int V_292 = V_9 -> V_199 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_72 = F_113 ( V_9 ) ;
if ( V_72 )
return V_72 ;
if ( V_292 >= V_213 )
return - V_129 ;
if ( ! V_10 -> V_9 . V_46 . V_293 -> V_273 )
return - V_129 ;
V_10 -> V_205 = F_116 ( V_10 -> V_9 . V_46 . V_293 -> V_273 ) ;
V_15 = F_112 ( V_9 , V_292 ) ;
if ( ! V_15 )
return - V_129 ;
V_291 = F_8 ( * V_15 ) ;
V_291 = ( F_105 ( V_10 -> V_205 ) &
V_294 ) |
V_295 ;
F_117 ( * V_15 , V_291 ) ;
V_10 -> V_16 = V_15 ;
return 0 ;
}
static void F_118 ( struct V_203 * V_203 )
{
struct V_201 * V_202 = & V_203 -> V_46 ;
if ( V_202 -> V_207 )
F_68 ( V_202 -> V_207 ) ;
if ( V_202 -> V_209 )
F_68 ( V_202 -> V_209 ) ;
}
static int F_119 ( struct V_203 * V_203 )
{
int V_103 = - V_150 ;
struct V_201 * V_202 = & V_203 -> V_46 ;
struct V_170 * V_296 ;
struct V_170 * V_297 ;
if ( ! V_186 )
return 0 ;
V_296 = F_72 ( V_149 ) ;
if ( ! V_296 )
goto V_298;
V_202 -> V_209 = V_296 ;
F_120 ( F_87 ( V_296 ) ) ;
V_297 = F_72 ( V_149 ) ;
if ( ! V_297 )
goto V_298;
V_202 -> V_207 = V_297 ;
F_120 ( F_87 ( V_297 ) ) ;
return 0 ;
V_298:
F_118 ( V_203 ) ;
return V_103 ;
}
static void F_121 ( struct V_8 * V_9 , bool V_299 )
{
T_1 V_15 ;
int V_300 = F_122 ( V_9 -> V_147 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_107 ( V_9 ) )
return;
V_10 -> V_301 = V_299 ;
if ( F_75 ( V_300 >= V_213 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_75 ( V_299 == ! ! ( V_15 & V_17 ) ) ;
V_15 &= ~ V_17 ;
if ( V_299 )
V_15 |= V_17 ;
F_117 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_123 ( struct V_8 * V_9 , int V_147 )
{
T_1 V_15 ;
int V_300 = F_122 ( V_147 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_107 ( V_9 ) )
return;
if ( F_75 ( V_300 >= V_213 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_75 ( V_15 & V_17 ) ;
V_15 &= ~ V_302 ;
V_15 |= ( V_300 & V_302 ) ;
V_15 &= ~ V_17 ;
if ( V_10 -> V_301 )
V_15 |= V_17 ;
F_117 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_124 ( struct V_8 * V_9 )
{
T_1 V_15 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_107 ( V_9 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
V_15 &= ~ V_17 ;
F_117 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_125 ( struct V_8 * V_9 , bool V_303 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_304 ;
T_2 V_305 = 1 ;
if ( ! V_303 ) {
V_10 -> V_9 . V_46 . V_306 = V_290 |
V_307 ;
if ( F_126 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_46 . V_306 |= V_308 ;
}
F_106 ( V_10 ) ;
F_127 ( V_9 , & V_305 , & V_304 , & V_304 , & V_304 ) ;
F_128 ( V_9 , V_309 , V_305 ) ;
if ( F_107 ( V_9 ) && ! V_303 )
F_6 ( V_10 , V_290 ) ;
}
static struct V_8 * F_129 ( struct V_203 * V_203 , unsigned int V_292 )
{
struct V_7 * V_10 ;
struct V_170 * V_170 ;
struct V_170 * V_310 ;
struct V_170 * V_311 ;
struct V_170 * V_312 ;
int V_103 ;
V_10 = F_130 ( V_313 , V_149 ) ;
if ( ! V_10 ) {
V_103 = - V_150 ;
goto V_314;
}
V_103 = F_131 ( & V_10 -> V_9 , V_203 , V_292 ) ;
if ( V_103 )
goto V_315;
V_103 = - V_150 ;
V_170 = F_72 ( V_149 ) ;
if ( ! V_170 )
goto V_316;
V_310 = F_86 ( V_149 , V_161 ) ;
if ( ! V_310 )
goto V_317;
V_312 = F_86 ( V_149 , V_161 ) ;
if ( ! V_312 )
goto V_318;
V_311 = F_72 ( V_149 ) ;
if ( ! V_311 )
goto V_319;
if ( V_186 ) {
V_103 = F_115 ( & V_10 -> V_9 ) ;
if ( V_103 )
goto V_320;
}
V_10 -> V_301 = true ;
V_10 -> V_24 . V_25 = F_87 ( V_311 ) ;
V_10 -> V_154 = F_87 ( V_310 ) ;
F_79 ( V_10 -> V_154 ) ;
V_10 -> V_24 . V_154 = F_87 ( V_312 ) ;
F_79 ( V_10 -> V_24 . V_154 ) ;
V_10 -> V_1 = F_87 ( V_170 ) ;
F_120 ( V_10 -> V_1 ) ;
V_10 -> V_321 = F_63 ( V_170 ) << V_141 ;
V_10 -> V_131 = 0 ;
F_106 ( V_10 ) ;
F_49 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_320:
F_68 ( V_311 ) ;
V_319:
F_95 ( V_312 , V_161 ) ;
V_318:
F_95 ( V_310 , V_161 ) ;
V_317:
F_68 ( V_170 ) ;
V_316:
F_132 ( & V_10 -> V_9 ) ;
V_315:
F_133 ( V_313 , V_10 ) ;
V_314:
return F_134 ( V_103 ) ;
}
static void F_135 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_68 ( F_97 ( V_10 -> V_321 >> V_141 ) ) ;
F_95 ( F_116 ( V_10 -> V_154 ) , V_161 ) ;
F_68 ( F_116 ( V_10 -> V_24 . V_25 ) ) ;
F_95 ( F_116 ( V_10 -> V_24 . V_154 ) , V_161 ) ;
F_132 ( V_9 ) ;
F_133 ( V_313 , V_10 ) ;
}
static void F_136 ( struct V_8 * V_9 , int V_147 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
if ( F_137 ( V_147 != V_9 -> V_147 ) ) {
V_10 -> V_131 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_29
F_58 ( V_322 , F_4 ( V_9 ) -> V_323 . V_324 ) ;
#endif
F_138 ( V_262 , V_10 -> V_323 . V_262 ) ;
F_138 ( V_263 , V_10 -> V_323 . V_263 ) ;
V_10 -> V_323 . V_325 = F_139 () ;
for ( V_51 = 0 ; V_51 < V_326 ; V_51 ++ )
F_58 ( V_327 [ V_51 ] , V_10 -> V_328 [ V_51 ] ) ;
if ( F_36 ( V_117 ) ) {
T_1 V_329 = V_9 -> V_46 . V_330 ;
if ( V_329 != F_140 ( V_142 ) ) {
F_64 ( V_142 , V_329 ) ;
F_53 ( V_118 , V_329 ) ;
}
}
if ( F_36 ( V_331 ) )
F_53 ( V_332 , V_10 -> V_333 ) ;
F_123 ( V_9 , V_147 ) ;
}
static void F_141 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
F_124 ( V_9 ) ;
++ V_9 -> V_334 . V_335 ;
F_142 ( V_10 -> V_323 . V_325 ) ;
#ifdef F_29
F_143 ( V_262 , V_10 -> V_323 . V_262 ) ;
F_53 ( V_336 , V_337 -> V_338 . V_339 ) ;
F_144 ( V_10 -> V_323 . V_263 ) ;
#else
#ifdef F_145
F_143 ( V_263 , V_10 -> V_323 . V_263 ) ;
#endif
#endif
for ( V_51 = 0 ; V_51 < V_326 ; V_51 ++ )
F_53 ( V_327 [ V_51 ] , V_10 -> V_328 [ V_51 ] ) ;
}
static void F_146 ( struct V_8 * V_9 )
{
F_121 ( V_9 , false ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
F_121 ( V_9 , true ) ;
}
static unsigned long F_148 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_340 ;
}
static void F_149 ( struct V_8 * V_9 , unsigned long V_340 )
{
F_4 ( V_9 ) -> V_1 -> V_65 . V_340 = V_340 ;
}
static T_2 F_150 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_151 ( struct V_8 * V_9 , enum V_341 V_342 )
{
switch ( V_342 ) {
case V_343 :
F_76 ( ! V_62 ) ;
F_152 ( V_9 , V_9 -> V_46 . V_344 , F_153 ( V_9 ) ) ;
break;
default:
F_81 () ;
}
}
static void F_154 ( struct V_7 * V_10 )
{
F_19 ( V_10 , V_345 ) ;
}
static void F_155 ( struct V_7 * V_10 )
{
F_20 ( V_10 , V_345 ) ;
}
static struct V_189 * F_156 ( struct V_8 * V_9 , int V_190 )
{
struct V_217 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
switch ( V_190 ) {
case V_346 : return & V_65 -> V_94 ;
case V_347 : return & V_65 -> V_261 ;
case V_348 : return & V_65 -> V_259 ;
case V_349 : return & V_65 -> V_262 ;
case V_350 : return & V_65 -> V_263 ;
case V_351 : return & V_65 -> V_260 ;
case V_352 : return & V_65 -> V_270 ;
case V_353 : return & V_65 -> V_268 ;
}
F_81 () ;
return NULL ;
}
static T_1 F_157 ( struct V_8 * V_9 , int V_190 )
{
struct V_189 * V_354 = F_156 ( V_9 , V_190 ) ;
return V_354 -> V_95 ;
}
static void F_158 ( struct V_8 * V_9 ,
struct V_355 * V_356 , int V_190 )
{
struct V_189 * V_354 = F_156 ( V_9 , V_190 ) ;
V_356 -> V_95 = V_354 -> V_95 ;
V_356 -> V_196 = V_354 -> V_196 ;
V_356 -> V_191 = V_354 -> V_191 ;
V_356 -> type = V_354 -> V_192 & V_357 ;
V_356 -> V_354 = ( V_354 -> V_192 >> V_358 ) & 1 ;
V_356 -> V_359 = ( V_354 -> V_192 >> V_360 ) & 3 ;
V_356 -> V_361 = ( V_354 -> V_192 >> V_362 ) & 1 ;
V_356 -> V_363 = ( V_354 -> V_192 >> V_364 ) & 1 ;
V_356 -> V_365 = ( V_354 -> V_192 >> V_366 ) & 1 ;
V_356 -> V_367 = ( V_354 -> V_192 >> V_368 ) & 1 ;
V_356 -> V_22 = V_354 -> V_196 > 0xfffff ;
V_356 -> V_369 = ! V_356 -> V_361 || ( V_356 -> type == 0 ) ;
switch ( V_190 ) {
case V_352 :
V_356 -> type |= 0x2 ;
break;
case V_347 :
case V_348 :
case V_349 :
case V_350 :
if ( ! V_356 -> V_369 )
V_356 -> type |= 0x1 ;
break;
case V_351 :
if ( V_356 -> V_369 )
V_356 -> V_367 = 0 ;
V_356 -> V_359 = F_4 ( V_9 ) -> V_1 -> V_65 . V_370 ;
break;
}
}
static int F_159 ( struct V_8 * V_9 )
{
struct V_217 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
return V_65 -> V_370 ;
}
static void F_160 ( struct V_8 * V_9 , struct V_122 * V_371 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_371 -> V_372 = V_10 -> V_1 -> V_65 . V_267 . V_196 ;
V_371 -> V_135 = V_10 -> V_1 -> V_65 . V_267 . V_95 ;
}
static void F_161 ( struct V_8 * V_9 , struct V_122 * V_371 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_267 . V_196 = V_371 -> V_372 ;
V_10 -> V_1 -> V_65 . V_267 . V_95 = V_371 -> V_135 ;
F_3 ( V_10 -> V_1 , V_373 ) ;
}
static void F_162 ( struct V_8 * V_9 , struct V_122 * V_371 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_371 -> V_372 = V_10 -> V_1 -> V_65 . V_266 . V_196 ;
V_371 -> V_135 = V_10 -> V_1 -> V_65 . V_266 . V_95 ;
}
static void F_163 ( struct V_8 * V_9 , struct V_122 * V_371 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_266 . V_196 = V_371 -> V_372 ;
V_10 -> V_1 -> V_65 . V_266 . V_95 = V_371 -> V_135 ;
F_3 ( V_10 -> V_1 , V_373 ) ;
}
static void F_164 ( struct V_8 * V_9 )
{
}
static void F_165 ( struct V_8 * V_9 )
{
}
static void F_166 ( struct V_8 * V_9 )
{
}
static void F_167 ( struct V_7 * V_10 )
{
T_10 V_374 = V_10 -> V_9 . V_46 . V_375 ;
T_1 * V_376 = & V_10 -> V_1 -> V_65 . V_375 ;
if ( ! V_10 -> V_9 . V_218 )
* V_376 |= V_377 ;
else
* V_376 = ( * V_376 & ~ V_377 )
| ( V_374 & V_377 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
if ( V_374 == * V_376 && V_10 -> V_9 . V_218 ) {
F_13 ( V_10 , V_219 ) ;
F_13 ( V_10 , V_222 ) ;
} else {
F_12 ( V_10 , V_219 ) ;
F_12 ( V_10 , V_222 ) ;
}
}
static void F_110 ( struct V_8 * V_9 , unsigned long V_375 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_29
if ( V_9 -> V_46 . V_61 & V_64 ) {
if ( ! F_168 ( V_9 ) && ( V_375 & V_378 ) ) {
V_9 -> V_46 . V_61 |= V_63 ;
V_10 -> V_1 -> V_65 . V_61 |= V_63 | V_64 ;
}
if ( F_168 ( V_9 ) && ! ( V_375 & V_378 ) ) {
V_9 -> V_46 . V_61 &= ~ V_63 ;
V_10 -> V_1 -> V_65 . V_61 &= ~ ( V_63 | V_64 ) ;
}
}
#endif
V_9 -> V_46 . V_375 = V_375 ;
if ( ! V_62 )
V_375 |= V_378 | V_379 ;
if ( ! V_9 -> V_218 )
V_375 |= V_380 ;
if ( F_169 ( V_9 -> V_203 , V_381 ) )
V_375 &= ~ ( V_276 | V_275 ) ;
V_10 -> V_1 -> V_65 . V_375 = V_375 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_167 ( V_10 ) ;
}
static int F_170 ( struct V_8 * V_9 , unsigned long V_278 )
{
unsigned long V_382 = F_171 () & V_383 ;
unsigned long V_384 = F_4 ( V_9 ) -> V_1 -> V_65 . V_278 ;
if ( V_278 & V_385 )
return 1 ;
if ( V_62 && ( ( V_384 ^ V_278 ) & V_386 ) )
F_172 ( V_9 ) ;
V_9 -> V_46 . V_278 = V_278 ;
if ( ! V_62 )
V_278 |= V_279 ;
V_278 |= V_382 ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_278 = V_278 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_67 ) ;
return 0 ;
}
static void F_173 ( struct V_8 * V_9 ,
struct V_355 * V_356 , int V_190 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_189 * V_354 = F_156 ( V_9 , V_190 ) ;
V_354 -> V_95 = V_356 -> V_95 ;
V_354 -> V_196 = V_356 -> V_196 ;
V_354 -> V_191 = V_356 -> V_191 ;
if ( V_356 -> V_369 )
V_354 -> V_192 = 0 ;
else {
V_354 -> V_192 = ( V_356 -> type & V_357 ) ;
V_354 -> V_192 |= ( V_356 -> V_354 & 1 ) << V_358 ;
V_354 -> V_192 |= ( V_356 -> V_359 & 3 ) << V_360 ;
V_354 -> V_192 |= ( V_356 -> V_361 & 1 ) << V_362 ;
V_354 -> V_192 |= ( V_356 -> V_363 & 1 ) << V_364 ;
V_354 -> V_192 |= ( V_356 -> V_365 & 1 ) << V_366 ;
V_354 -> V_192 |= ( V_356 -> V_367 & 1 ) << V_368 ;
V_354 -> V_192 |= ( V_356 -> V_22 & 1 ) << V_387 ;
}
if ( V_190 == V_351 )
V_10 -> V_1 -> V_65 . V_370 = ( V_354 -> V_192 >> V_360 ) & 3 ;
F_3 ( V_10 -> V_1 , V_388 ) ;
}
static void F_174 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_90 ) ;
if ( V_9 -> V_389 & V_390 ) {
if ( V_9 -> V_389 & V_391 )
F_17 ( V_10 , V_90 ) ;
} else
V_9 -> V_389 = 0 ;
}
static void F_175 ( struct V_7 * V_10 , struct V_120 * V_121 )
{
if ( V_121 -> V_134 > V_121 -> V_132 ) {
++ V_121 -> V_131 ;
V_121 -> V_134 = 1 ;
V_10 -> V_1 -> V_2 . V_392 = V_393 ;
}
V_10 -> V_131 = V_121 -> V_131 ;
V_10 -> V_1 -> V_2 . V_58 = V_121 -> V_134 ++ ;
F_3 ( V_10 -> V_1 , V_394 ) ;
}
static T_1 F_176 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_272 ;
}
static void F_177 ( struct V_8 * V_9 , unsigned long V_395 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_272 = V_395 ;
F_3 ( V_10 -> V_1 , V_396 ) ;
}
static void F_178 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_179 ( V_9 -> V_46 . V_367 [ 0 ] , 0 ) ;
F_179 ( V_9 -> V_46 . V_367 [ 1 ] , 1 ) ;
F_179 ( V_9 -> V_46 . V_367 [ 2 ] , 2 ) ;
F_179 ( V_9 -> V_46 . V_367 [ 3 ] , 3 ) ;
V_9 -> V_46 . V_272 = F_176 ( V_9 ) ;
V_9 -> V_46 . V_397 = V_10 -> V_1 -> V_65 . V_397 ;
V_9 -> V_46 . V_398 &= ~ V_399 ;
F_15 ( V_10 ) ;
}
static void F_180 ( struct V_8 * V_9 , unsigned long V_395 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_397 = V_395 ;
F_3 ( V_10 -> V_1 , V_396 ) ;
}
static int F_181 ( struct V_7 * V_10 )
{
T_1 V_400 = V_10 -> V_1 -> V_2 . V_401 ;
T_2 V_88 ;
int V_148 = 1 ;
switch ( V_10 -> V_402 ) {
default:
V_88 = V_10 -> V_1 -> V_2 . V_403 ;
F_182 ( V_400 , V_88 ) ;
if ( ! V_62 && F_183 ( & V_10 -> V_9 ) )
F_184 ( & V_10 -> V_9 , V_400 ) ;
V_148 = F_185 ( & V_10 -> V_9 , V_400 , V_88 ,
V_10 -> V_1 -> V_2 . V_404 ,
V_10 -> V_1 -> V_2 . V_405 ) ;
break;
case V_406 :
V_10 -> V_402 = 0 ;
F_186 () ;
F_187 ( V_400 ) ;
F_188 () ;
break;
case V_407 :
V_10 -> V_402 = 0 ;
F_186 () ;
F_189 ( V_400 ) ;
F_188 () ;
break;
}
return V_148 ;
}
static int F_190 ( struct V_7 * V_10 )
{
struct V_408 * V_408 = V_10 -> V_9 . V_409 ;
if ( ! ( V_10 -> V_9 . V_389 &
( V_410 | V_411 ) ) &&
! V_10 -> V_412 ) {
F_191 ( & V_10 -> V_9 , V_230 ) ;
return 1 ;
}
if ( V_10 -> V_412 ) {
V_10 -> V_412 = false ;
if ( ! ( V_10 -> V_9 . V_389 & V_410 ) )
V_10 -> V_1 -> V_65 . V_340 &=
~ ( V_413 | V_414 ) ;
}
if ( V_10 -> V_9 . V_389 &
( V_410 | V_411 ) ) {
V_408 -> V_415 = V_416 ;
V_408 -> V_417 . V_46 . V_418 =
V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_408 -> V_417 . V_46 . V_419 = V_230 ;
return 0 ;
}
return 1 ;
}
static int F_192 ( struct V_7 * V_10 )
{
struct V_408 * V_408 = V_10 -> V_9 . V_409 ;
V_408 -> V_415 = V_416 ;
V_408 -> V_417 . V_46 . V_418 = V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_408 -> V_417 . V_46 . V_419 = V_90 ;
return 0 ;
}
static int F_193 ( struct V_7 * V_10 )
{
int V_420 ;
V_420 = F_37 ( & V_10 -> V_9 , V_421 ) ;
if ( V_420 != V_81 )
F_191 ( & V_10 -> V_9 , V_227 ) ;
return 1 ;
}
static int F_194 ( struct V_7 * V_10 )
{
F_195 ( & V_10 -> V_9 , V_229 , 0 ) ;
return 1 ;
}
static void F_196 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_422 ) ;
V_10 -> V_9 . V_218 = 1 ;
F_167 ( V_10 ) ;
}
static int F_197 ( struct V_7 * V_10 )
{
F_196 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_198 ( void )
{
int V_103 , V_51 ;
T_1 V_395 ;
if ( ! V_107 )
return false ;
V_395 = F_45 ( V_423 , & V_103 ) ;
if ( V_103 )
return false ;
V_395 &= ~ ( 1ULL << 62 ) ;
if ( V_395 != 0xb600000000010015ULL )
return false ;
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 )
F_48 ( F_199 ( V_51 ) , 0 , 0 ) ;
V_395 = F_45 ( V_424 , & V_103 ) ;
if ( ! V_103 ) {
T_2 V_101 , V_102 ;
V_395 &= ~ ( 1ULL << 2 ) ;
V_101 = F_46 ( V_395 ) ;
V_102 = F_47 ( V_395 ) ;
F_48 ( V_424 , V_101 , V_102 ) ;
}
F_200 () ;
return true ;
}
static void F_201 ( struct V_7 * V_10 )
{
if ( F_198 () ) {
F_59 ( L_10 ) ;
F_202 ( V_425 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_203 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_204 ( struct V_7 * V_10 )
{
struct V_408 * V_408 = V_10 -> V_9 . V_409 ;
F_120 ( V_10 -> V_1 ) ;
F_106 ( V_10 ) ;
V_408 -> V_415 = V_426 ;
return 0 ;
}
static int F_205 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_2 V_427 = V_10 -> V_1 -> V_2 . V_403 ;
int V_372 , V_428 , string ;
unsigned V_429 ;
++ V_10 -> V_9 . V_334 . V_430 ;
string = ( V_427 & V_431 ) != 0 ;
V_428 = ( V_427 & V_432 ) != 0 ;
if ( string || V_428 )
return F_37 ( V_9 , 0 ) == V_81 ;
V_429 = V_427 >> 16 ;
V_372 = ( V_427 & V_433 ) >> V_434 ;
V_10 -> V_78 = V_10 -> V_1 -> V_2 . V_401 ;
F_34 ( & V_10 -> V_9 ) ;
return F_206 ( V_9 , V_372 , V_429 ) ;
}
static int F_207 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_208 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_334 . V_435 ;
return 1 ;
}
static int F_209 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_210 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 1 ;
return F_211 ( & V_10 -> V_9 ) ;
}
static int F_212 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_213 ( & V_10 -> V_9 ) ;
}
static unsigned long F_214 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_24 . V_436 ;
}
static T_1 F_215 ( struct V_8 * V_9 , int V_152 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_283 = V_10 -> V_24 . V_436 ;
T_1 V_437 ;
int V_72 ;
V_72 = F_216 ( V_9 , F_217 ( V_283 ) , & V_437 ,
F_218 ( V_283 ) + V_152 * 8 , 8 ) ;
if ( V_72 )
return 0 ;
return V_437 ;
}
static void F_219 ( struct V_8 * V_9 ,
unsigned long V_438 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_436 = V_438 ;
F_3 ( V_10 -> V_1 , V_439 ) ;
F_172 ( V_9 ) ;
}
static void F_220 ( struct V_8 * V_9 ,
struct V_440 * V_441 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_442 != V_443 ) {
V_10 -> V_1 -> V_2 . V_442 = V_443 ;
V_10 -> V_1 -> V_2 . V_444 = 0 ;
V_10 -> V_1 -> V_2 . V_403 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_401 = V_441 -> V_135 ;
}
V_10 -> V_1 -> V_2 . V_403 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_403 |= V_441 -> V_88 ;
if ( V_10 -> V_1 -> V_2 . V_403 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_403 &= ~ 1 ;
F_221 ( V_10 ) ;
}
static void F_222 ( struct V_8 * V_9 )
{
F_75 ( F_223 ( V_9 ) ) ;
F_224 ( V_9 ) ;
V_9 -> V_46 . V_445 . V_446 = F_219 ;
V_9 -> V_46 . V_445 . V_447 = F_214 ;
V_9 -> V_46 . V_445 . V_448 = F_215 ;
V_9 -> V_46 . V_445 . V_449 = F_220 ;
V_9 -> V_46 . V_445 . V_450 = F_28 () ;
F_225 ( V_9 , & V_9 -> V_46 . V_445 ) ;
V_9 -> V_46 . V_344 = & V_9 -> V_46 . V_451 ;
}
static void F_226 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_344 = & V_9 -> V_46 . V_445 ;
}
static int F_227 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_46 . V_61 & V_66 )
|| ! F_168 ( & V_10 -> V_9 ) ) {
F_191 ( & V_10 -> V_9 , V_227 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_65 . V_370 ) {
F_228 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_10 , unsigned V_86 ,
bool V_87 , T_2 V_88 )
{
int V_452 ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_442 = V_453 + V_86 ;
V_10 -> V_1 -> V_2 . V_444 = 0 ;
V_10 -> V_1 -> V_2 . V_403 = V_88 ;
V_10 -> V_1 -> V_2 . V_401 = V_10 -> V_9 . V_46 . V_454 ;
V_452 = F_229 ( V_10 ) ;
if ( V_452 == V_455 )
V_10 -> V_24 . V_456 = true ;
return V_452 ;
}
static inline bool F_230 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_457 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_458 ) )
return false ;
if ( V_10 -> V_24 . V_456 )
return false ;
V_10 -> V_1 -> V_2 . V_442 = V_459 ;
V_10 -> V_1 -> V_2 . V_403 = 0 ;
V_10 -> V_1 -> V_2 . V_401 = 0 ;
if ( V_10 -> V_24 . V_29 & 1ULL ) {
V_10 -> V_24 . V_456 = true ;
F_231 ( V_10 -> V_1 -> V_65 . V_91 ) ;
return false ;
}
return true ;
}
static inline bool F_232 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_232 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_442 = V_460 ;
V_10 -> V_24 . V_456 = true ;
return false ;
}
static void * F_233 ( struct V_7 * V_10 , T_1 V_461 , struct V_170 * * V_462 )
{
struct V_170 * V_170 ;
F_234 () ;
V_170 = F_235 ( & V_10 -> V_9 , V_461 >> V_141 ) ;
if ( F_236 ( V_170 ) )
goto error;
* V_462 = V_170 ;
return F_237 ( V_170 ) ;
error:
F_228 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_238 ( struct V_170 * V_170 )
{
F_239 ( V_170 ) ;
F_240 ( V_170 ) ;
}
static int F_241 ( struct V_7 * V_10 )
{
unsigned V_429 , V_372 , V_463 ;
T_11 V_104 , V_77 ;
T_4 V_464 ;
T_1 V_461 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_241 ) ) )
return V_465 ;
V_429 = V_10 -> V_1 -> V_2 . V_403 >> 16 ;
V_372 = ( V_10 -> V_1 -> V_2 . V_403 & V_433 ) >>
V_434 ;
V_461 = V_10 -> V_24 . V_466 + ( V_429 / 8 ) ;
V_464 = V_429 % 8 ;
V_463 = ( V_464 + V_372 > 8 ) ? 2 : 1 ;
V_77 = ( 0xf >> ( 4 - V_372 ) ) << V_464 ;
V_104 = 0 ;
if ( F_242 ( & V_10 -> V_9 , V_461 , & V_104 , V_463 ) )
return V_455 ;
return ( V_104 & V_77 ) ? V_455 : V_465 ;
}
static int F_243 ( struct V_7 * V_10 )
{
T_2 V_50 , V_49 , V_395 ;
int V_156 , V_77 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_242 ) ) )
return V_465 ;
V_49 = V_10 -> V_9 . V_46 . V_273 [ V_467 ] ;
V_50 = F_24 ( V_49 ) ;
V_156 = V_10 -> V_1 -> V_2 . V_403 & 1 ;
V_77 = 1 << ( ( 2 * ( V_49 & 0xf ) ) + V_156 ) ;
if ( V_50 == V_56 )
return V_455 ;
V_50 *= 4 ;
if ( F_242 ( & V_10 -> V_9 , V_10 -> V_24 . V_468 + V_50 , & V_395 , 4 ) )
return V_455 ;
return ( V_395 & V_77 ) ? V_455 : V_465 ;
}
static int F_244 ( struct V_7 * V_10 )
{
T_2 V_442 = V_10 -> V_1 -> V_2 . V_442 ;
switch ( V_442 ) {
case V_459 :
case V_460 :
case V_453 + V_228 :
return V_465 ;
case V_443 :
if ( V_62 )
return V_465 ;
break;
case V_453 + V_226 :
if ( ! V_62 && V_10 -> V_402 == 0 )
return V_465 ;
break;
case V_453 + V_422 :
F_197 ( V_10 ) ;
break;
default:
break;
}
return V_469 ;
}
static int F_229 ( struct V_7 * V_10 )
{
T_2 V_442 = V_10 -> V_1 -> V_2 . V_442 ;
int V_452 = V_465 ;
switch ( V_442 ) {
case V_470 :
V_452 = F_243 ( V_10 ) ;
break;
case V_471 :
V_452 = F_241 ( V_10 ) ;
break;
case V_472 ... V_473 : {
T_2 V_6 = 1U << ( V_442 - V_472 ) ;
if ( V_10 -> V_24 . V_26 & V_6 )
V_452 = V_455 ;
break;
}
case V_474 ... V_475 : {
T_2 V_6 = 1U << ( V_442 - V_474 ) ;
if ( V_10 -> V_24 . V_27 & V_6 )
V_452 = V_455 ;
break;
}
case V_453 ... V_453 + 0x1f : {
T_2 V_476 = 1 << ( V_442 - V_453 ) ;
if ( V_10 -> V_24 . V_28 & V_476 )
V_452 = V_455 ;
else if ( ( V_442 == V_453 + V_226 ) &&
V_10 -> V_402 != 0 )
V_452 = V_455 ;
break;
}
case V_477 : {
V_452 = V_455 ;
break;
}
default: {
T_1 V_478 = 1ULL << ( V_442 - V_459 ) ;
if ( V_10 -> V_24 . V_29 & V_478 )
V_452 = V_455 ;
}
}
return V_452 ;
}
static int F_245 ( struct V_7 * V_10 )
{
int V_452 ;
V_452 = F_229 ( V_10 ) ;
if ( V_452 == V_455 )
F_221 ( V_10 ) ;
return V_452 ;
}
static inline void F_246 ( struct V_1 * V_479 , struct V_1 * V_480 )
{
struct V_18 * V_481 = & V_479 -> V_2 ;
struct V_18 * V_482 = & V_480 -> V_2 ;
V_481 -> V_26 = V_482 -> V_26 ;
V_481 -> V_27 = V_482 -> V_27 ;
V_481 -> V_28 = V_482 -> V_28 ;
V_481 -> V_29 = V_482 -> V_29 ;
V_481 -> V_256 = V_482 -> V_256 ;
V_481 -> V_257 = V_482 -> V_257 ;
V_481 -> V_197 = V_482 -> V_197 ;
V_481 -> V_58 = V_482 -> V_58 ;
V_481 -> V_392 = V_482 -> V_392 ;
V_481 -> V_214 = V_482 -> V_214 ;
V_481 -> V_483 = V_482 -> V_483 ;
V_481 -> V_73 = V_482 -> V_73 ;
V_481 -> V_442 = V_482 -> V_442 ;
V_481 -> V_444 = V_482 -> V_444 ;
V_481 -> V_403 = V_482 -> V_403 ;
V_481 -> V_401 = V_482 -> V_401 ;
V_481 -> V_484 = V_482 -> V_484 ;
V_481 -> V_485 = V_482 -> V_485 ;
V_481 -> V_280 = V_482 -> V_280 ;
V_481 -> V_97 = V_482 -> V_97 ;
V_481 -> V_100 = V_482 -> V_100 ;
V_481 -> V_436 = V_482 -> V_436 ;
V_481 -> V_165 = V_482 -> V_165 ;
}
static int F_221 ( struct V_7 * V_10 )
{
struct V_1 * V_486 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_170 * V_170 ;
F_247 ( V_1 -> V_2 . V_442 ,
V_1 -> V_2 . V_403 ,
V_1 -> V_2 . V_401 ,
V_1 -> V_2 . V_484 ,
V_1 -> V_2 . V_485 ,
V_487 ) ;
V_486 = F_233 ( V_10 , V_10 -> V_24 . V_1 , & V_170 ) ;
if ( ! V_486 )
return 1 ;
F_248 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_1 = 0 ;
F_22 ( V_10 ) ;
V_486 -> V_65 . V_259 = V_1 -> V_65 . V_259 ;
V_486 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_486 -> V_65 . V_260 = V_1 -> V_65 . V_260 ;
V_486 -> V_65 . V_261 = V_1 -> V_65 . V_261 ;
V_486 -> V_65 . V_266 = V_1 -> V_65 . V_266 ;
V_486 -> V_65 . V_267 = V_1 -> V_65 . V_267 ;
V_486 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_486 -> V_65 . V_375 = F_249 ( & V_10 -> V_9 ) ;
V_486 -> V_65 . V_283 = F_153 ( & V_10 -> V_9 ) ;
V_486 -> V_65 . V_454 = V_1 -> V_65 . V_454 ;
V_486 -> V_65 . V_278 = V_10 -> V_9 . V_46 . V_278 ;
V_486 -> V_65 . V_340 = F_250 ( & V_10 -> V_9 ) ;
V_486 -> V_65 . V_91 = V_1 -> V_65 . V_91 ;
V_486 -> V_65 . V_488 = V_1 -> V_65 . V_488 ;
V_486 -> V_65 . V_489 = V_1 -> V_65 . V_489 ;
V_486 -> V_65 . V_397 = V_1 -> V_65 . V_397 ;
V_486 -> V_65 . V_272 = V_1 -> V_65 . V_272 ;
V_486 -> V_65 . V_370 = V_1 -> V_65 . V_370 ;
V_486 -> V_2 . V_214 = V_1 -> V_2 . V_214 ;
V_486 -> V_2 . V_483 = V_1 -> V_2 . V_483 ;
V_486 -> V_2 . V_73 = V_1 -> V_2 . V_73 ;
V_486 -> V_2 . V_442 = V_1 -> V_2 . V_442 ;
V_486 -> V_2 . V_444 = V_1 -> V_2 . V_444 ;
V_486 -> V_2 . V_403 = V_1 -> V_2 . V_403 ;
V_486 -> V_2 . V_401 = V_1 -> V_2 . V_401 ;
V_486 -> V_2 . V_484 = V_1 -> V_2 . V_484 ;
V_486 -> V_2 . V_485 = V_1 -> V_2 . V_485 ;
if ( V_10 -> V_490 )
V_486 -> V_2 . V_78 = V_1 -> V_2 . V_78 ;
if ( V_1 -> V_2 . V_97 & V_70 ) {
struct V_18 * V_491 = & V_486 -> V_2 ;
V_491 -> V_484 = V_1 -> V_2 . V_97 ;
V_491 -> V_485 = V_1 -> V_2 . V_100 ;
}
V_486 -> V_2 . V_392 = 0 ;
V_486 -> V_2 . V_97 = 0 ;
V_486 -> V_2 . V_100 = 0 ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_457 ) )
V_486 -> V_2 . V_214 &= ~ V_258 ;
F_246 ( V_1 , V_25 ) ;
F_251 ( & V_10 -> V_9 ) ;
F_252 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_436 = 0 ;
V_10 -> V_1 -> V_65 . V_259 = V_25 -> V_65 . V_259 ;
V_10 -> V_1 -> V_65 . V_94 = V_25 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_260 = V_25 -> V_65 . V_260 ;
V_10 -> V_1 -> V_65 . V_261 = V_25 -> V_65 . V_261 ;
V_10 -> V_1 -> V_65 . V_266 = V_25 -> V_65 . V_266 ;
V_10 -> V_1 -> V_65 . V_267 = V_25 -> V_65 . V_267 ;
F_109 ( & V_10 -> V_9 , V_25 -> V_65 . V_340 ) ;
F_30 ( & V_10 -> V_9 , V_25 -> V_65 . V_61 ) ;
F_110 ( & V_10 -> V_9 , V_25 -> V_65 . V_375 | V_492 ) ;
F_170 ( & V_10 -> V_9 , V_25 -> V_65 . V_278 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_283 = V_25 -> V_65 . V_283 ;
V_10 -> V_9 . V_46 . V_283 = V_25 -> V_65 . V_283 ;
} else {
( void ) F_253 ( & V_10 -> V_9 , V_25 -> V_65 . V_283 ) ;
}
F_128 ( & V_10 -> V_9 , V_493 , V_25 -> V_65 . V_489 ) ;
F_128 ( & V_10 -> V_9 , V_494 , V_25 -> V_65 . V_488 ) ;
F_128 ( & V_10 -> V_9 , V_274 , V_25 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_397 = 0 ;
V_10 -> V_1 -> V_65 . V_370 = 0 ;
V_10 -> V_1 -> V_2 . V_484 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_238 ( V_170 ) ;
F_226 ( & V_10 -> V_9 ) ;
F_111 ( & V_10 -> V_9 ) ;
F_254 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_255 ( struct V_7 * V_10 )
{
int V_51 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_242 ) ) )
return true ;
for ( V_51 = 0 ; V_51 < V_163 ; V_51 ++ ) {
T_2 V_395 , V_495 ;
T_1 V_50 ;
if ( V_164 [ V_51 ] == 0xffffffff )
break;
V_495 = V_164 [ V_51 ] ;
V_50 = V_10 -> V_24 . V_468 + ( V_495 * 4 ) ;
if ( F_242 ( & V_10 -> V_9 , V_50 , & V_395 , 4 ) )
return false ;
V_10 -> V_24 . V_154 [ V_495 ] = V_10 -> V_154 [ V_495 ] | V_395 ;
}
V_10 -> V_1 -> V_2 . V_257 = F_108 ( V_10 -> V_24 . V_154 ) ;
return true ;
}
static bool F_256 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_29 & ( 1ULL << V_245 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_58 == 0 )
return false ;
if ( V_1 -> V_2 . V_280 && ! V_62 )
return false ;
return true ;
}
static bool F_257 ( struct V_7 * V_10 )
{
struct V_1 * V_486 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_170 * V_170 ;
T_1 V_496 ;
V_496 = V_10 -> V_1 -> V_65 . V_489 ;
V_486 = F_233 ( V_10 , V_10 -> V_1 -> V_65 . V_489 , & V_170 ) ;
if ( ! V_486 )
return false ;
if ( ! F_256 ( V_486 ) ) {
V_486 -> V_2 . V_442 = V_477 ;
V_486 -> V_2 . V_444 = 0 ;
V_486 -> V_2 . V_403 = 0 ;
V_486 -> V_2 . V_401 = 0 ;
F_238 ( V_170 ) ;
return false ;
}
F_258 ( V_10 -> V_1 -> V_65 . V_91 , V_496 ,
V_486 -> V_65 . V_91 ,
V_486 -> V_2 . V_214 ,
V_486 -> V_2 . V_97 ,
V_486 -> V_2 . V_280 ) ;
F_259 ( V_486 -> V_2 . V_26 & 0xffff ,
V_486 -> V_2 . V_26 >> 16 ,
V_486 -> V_2 . V_28 ,
V_486 -> V_2 . V_29 ) ;
F_251 ( & V_10 -> V_9 ) ;
F_252 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_259 = V_1 -> V_65 . V_259 ;
V_25 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_25 -> V_65 . V_260 = V_1 -> V_65 . V_260 ;
V_25 -> V_65 . V_261 = V_1 -> V_65 . V_261 ;
V_25 -> V_65 . V_266 = V_1 -> V_65 . V_266 ;
V_25 -> V_65 . V_267 = V_1 -> V_65 . V_267 ;
V_25 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_25 -> V_65 . V_375 = F_249 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_278 = V_10 -> V_9 . V_46 . V_278 ;
V_25 -> V_65 . V_340 = F_250 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_91 = F_39 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_488 = V_1 -> V_65 . V_488 ;
V_25 -> V_65 . V_489 = V_1 -> V_65 . V_489 ;
if ( V_62 )
V_25 -> V_65 . V_283 = V_1 -> V_65 . V_283 ;
else
V_25 -> V_65 . V_283 = F_153 ( & V_10 -> V_9 ) ;
F_246 ( V_25 , V_1 ) ;
if ( F_250 ( & V_10 -> V_9 ) & V_497 )
V_10 -> V_9 . V_46 . V_47 |= V_458 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_458 ;
if ( V_486 -> V_2 . V_280 ) {
F_260 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_436 = V_486 -> V_2 . V_436 ;
F_222 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_65 . V_259 = V_486 -> V_65 . V_259 ;
V_10 -> V_1 -> V_65 . V_94 = V_486 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_260 = V_486 -> V_65 . V_260 ;
V_10 -> V_1 -> V_65 . V_261 = V_486 -> V_65 . V_261 ;
V_10 -> V_1 -> V_65 . V_266 = V_486 -> V_65 . V_266 ;
V_10 -> V_1 -> V_65 . V_267 = V_486 -> V_65 . V_267 ;
F_109 ( & V_10 -> V_9 , V_486 -> V_65 . V_340 ) ;
F_30 ( & V_10 -> V_9 , V_486 -> V_65 . V_61 ) ;
F_110 ( & V_10 -> V_9 , V_486 -> V_65 . V_375 ) ;
F_170 ( & V_10 -> V_9 , V_486 -> V_65 . V_278 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_283 = V_486 -> V_65 . V_283 ;
V_10 -> V_9 . V_46 . V_283 = V_486 -> V_65 . V_283 ;
} else
( void ) F_253 ( & V_10 -> V_9 , V_486 -> V_65 . V_283 ) ;
F_111 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_65 . V_454 = V_10 -> V_9 . V_46 . V_454 = V_486 -> V_65 . V_454 ;
F_128 ( & V_10 -> V_9 , V_493 , V_486 -> V_65 . V_489 ) ;
F_128 ( & V_10 -> V_9 , V_494 , V_486 -> V_65 . V_488 ) ;
F_128 ( & V_10 -> V_9 , V_274 , V_486 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_489 = V_486 -> V_65 . V_489 ;
V_10 -> V_1 -> V_65 . V_488 = V_486 -> V_65 . V_488 ;
V_10 -> V_1 -> V_65 . V_91 = V_486 -> V_65 . V_91 ;
V_10 -> V_1 -> V_65 . V_397 = V_486 -> V_65 . V_397 ;
V_10 -> V_1 -> V_65 . V_272 = V_486 -> V_65 . V_272 ;
V_10 -> V_1 -> V_65 . V_370 = V_486 -> V_65 . V_370 ;
V_10 -> V_24 . V_468 = V_486 -> V_2 . V_257 & ~ 0x0fffULL ;
V_10 -> V_24 . V_466 = V_486 -> V_2 . V_256 & ~ 0x0fffULL ;
V_10 -> V_24 . V_26 = V_486 -> V_2 . V_26 ;
V_10 -> V_24 . V_27 = V_486 -> V_2 . V_27 ;
V_10 -> V_24 . V_28 = V_486 -> V_2 . V_28 ;
V_10 -> V_24 . V_29 = V_486 -> V_2 . V_29 ;
F_172 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_214 = V_486 -> V_2 . V_214 | V_258 ;
if ( V_486 -> V_2 . V_214 & V_258 )
V_10 -> V_9 . V_46 . V_47 |= V_457 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_457 ;
if ( V_10 -> V_9 . V_46 . V_47 & V_457 ) {
F_13 ( V_10 , V_498 ) ;
F_13 ( V_10 , V_225 ) ;
}
F_20 ( V_10 , V_246 ) ;
V_10 -> V_1 -> V_2 . V_165 = V_486 -> V_2 . V_165 ;
V_10 -> V_1 -> V_2 . V_483 = V_486 -> V_2 . V_483 ;
V_10 -> V_1 -> V_2 . V_73 = V_486 -> V_2 . V_73 ;
V_10 -> V_1 -> V_2 . V_197 += V_486 -> V_2 . V_197 ;
V_10 -> V_1 -> V_2 . V_97 = V_486 -> V_2 . V_97 ;
V_10 -> V_1 -> V_2 . V_100 = V_486 -> V_2 . V_100 ;
F_238 ( V_170 ) ;
F_261 ( & V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
V_10 -> V_24 . V_1 = V_496 ;
F_21 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_262 ( struct V_1 * V_480 , struct V_1 * V_499 )
{
V_499 -> V_65 . V_262 = V_480 -> V_65 . V_262 ;
V_499 -> V_65 . V_263 = V_480 -> V_65 . V_263 ;
V_499 -> V_65 . V_270 = V_480 -> V_65 . V_270 ;
V_499 -> V_65 . V_268 = V_480 -> V_65 . V_268 ;
V_499 -> V_65 . V_500 = V_480 -> V_65 . V_500 ;
V_499 -> V_65 . V_501 = V_480 -> V_65 . V_501 ;
V_499 -> V_65 . V_502 = V_480 -> V_65 . V_502 ;
V_499 -> V_65 . V_503 = V_480 -> V_65 . V_503 ;
V_499 -> V_65 . V_504 = V_480 -> V_65 . V_504 ;
V_499 -> V_65 . V_505 = V_480 -> V_65 . V_505 ;
V_499 -> V_65 . V_506 = V_480 -> V_65 . V_506 ;
V_499 -> V_65 . V_507 = V_480 -> V_65 . V_507 ;
}
static int F_263 ( struct V_7 * V_10 )
{
struct V_1 * V_486 ;
struct V_170 * V_170 ;
if ( F_227 ( V_10 ) )
return 1 ;
V_486 = F_233 ( V_10 , V_10 -> V_1 -> V_65 . V_489 , & V_170 ) ;
if ( ! V_486 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_262 ( V_486 , V_10 -> V_1 ) ;
F_238 ( V_170 ) ;
return 1 ;
}
static int F_264 ( struct V_7 * V_10 )
{
struct V_1 * V_486 ;
struct V_170 * V_170 ;
if ( F_227 ( V_10 ) )
return 1 ;
V_486 = F_233 ( V_10 , V_10 -> V_1 -> V_65 . V_489 , & V_170 ) ;
if ( ! V_486 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_262 ( V_10 -> V_1 , V_486 ) ;
F_238 ( V_170 ) ;
return 1 ;
}
static int F_265 ( struct V_7 * V_10 )
{
if ( F_227 ( V_10 ) )
return 1 ;
F_40 ( & V_10 -> V_9 , F_39 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_257 ( V_10 ) )
return 1 ;
if ( ! F_255 ( V_10 ) )
goto V_508;
return 1 ;
V_508:
V_10 -> V_1 -> V_2 . V_442 = V_477 ;
V_10 -> V_1 -> V_2 . V_444 = 0 ;
V_10 -> V_1 -> V_2 . V_403 = 0 ;
V_10 -> V_1 -> V_2 . V_401 = 0 ;
F_221 ( V_10 ) ;
return 1 ;
}
static int F_266 ( struct V_7 * V_10 )
{
if ( F_227 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_202 ( V_509 , & V_10 -> V_9 ) ;
F_21 ( V_10 ) ;
return 1 ;
}
static int F_267 ( struct V_7 * V_10 )
{
if ( F_227 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_22 ( V_10 ) ;
if ( ! F_107 ( & V_10 -> V_9 ) ) {
F_155 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_214 &= ~ V_510 ;
F_3 ( V_10 -> V_1 , V_511 ) ;
}
return 1 ;
}
static int F_268 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_269 ( V_10 -> V_1 -> V_65 . V_91 , F_270 ( & V_10 -> V_9 , V_467 ) ,
F_270 ( & V_10 -> V_9 , V_493 ) ) ;
F_271 ( V_9 , F_270 ( & V_10 -> V_9 , V_493 ) ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_272 ( struct V_7 * V_10 )
{
F_273 ( V_10 -> V_1 -> V_65 . V_91 , F_270 ( & V_10 -> V_9 , V_493 ) ) ;
F_191 ( & V_10 -> V_9 , V_227 ) ;
return 1 ;
}
static int F_274 ( struct V_7 * V_10 )
{
F_275 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_276 ( struct V_7 * V_10 )
{
T_1 V_512 = F_277 ( & V_10 -> V_9 ) ;
T_2 V_152 = F_270 ( & V_10 -> V_9 , V_467 ) ;
if ( F_278 ( & V_10 -> V_9 , V_152 , V_512 ) == 0 ) {
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_279 ( struct V_7 * V_10 )
{
T_11 V_513 ;
int V_514 ;
int V_515 = V_10 -> V_1 -> V_2 . V_484 &
V_516 ;
int V_517 = V_10 -> V_1 -> V_2 . V_484 & V_518 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_484 & V_516 ;
T_7 V_519 =
V_10 -> V_1 -> V_2 . V_484 & V_520 ;
bool V_87 = false ;
T_2 V_88 = 0 ;
V_513 = ( T_11 ) V_10 -> V_1 -> V_2 . V_403 ;
if ( V_10 -> V_1 -> V_2 . V_401 &
( 1ULL << V_521 ) )
V_514 = V_522 ;
else if ( V_10 -> V_1 -> V_2 . V_401 &
( 1ULL << V_523 ) )
V_514 = V_524 ;
else if ( V_519 )
V_514 = V_525 ;
else
V_514 = V_526 ;
if ( V_514 == V_525 ) {
switch ( type ) {
case V_527 :
V_10 -> V_9 . V_46 . V_528 = false ;
break;
case V_529 :
if ( V_10 -> V_1 -> V_2 . V_401 &
( 1ULL << V_530 ) ) {
V_87 = true ;
V_88 =
( T_2 ) V_10 -> V_1 -> V_2 . V_401 ;
}
F_251 ( & V_10 -> V_9 ) ;
break;
case V_531 :
F_252 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_514 != V_525 ||
V_515 == V_532 ||
( V_515 == V_529 &&
( V_517 == V_533 || V_517 == V_90 ) ) )
F_34 ( & V_10 -> V_9 ) ;
if ( V_515 != V_532 )
V_517 = - 1 ;
if ( F_280 ( & V_10 -> V_9 , V_513 , V_517 , V_514 ,
V_87 , V_88 ) == V_534 ) {
V_10 -> V_9 . V_409 -> V_415 = V_535 ;
V_10 -> V_9 . V_409 -> V_536 . V_537 = V_538 ;
V_10 -> V_9 . V_409 -> V_536 . V_539 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_281 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
F_282 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_283 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_334 . V_540 ;
F_20 ( V_10 , V_541 ) ;
V_10 -> V_9 . V_46 . V_47 |= V_542 ;
V_10 -> V_543 = F_39 ( & V_10 -> V_9 ) ;
F_202 ( V_509 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_284 ( struct V_7 * V_10 )
{
if ( ! F_36 ( V_544 ) )
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
F_271 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_403 ) ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_285 ( struct V_7 * V_10 )
{
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
}
static int F_286 ( struct V_7 * V_10 )
{
int V_103 ;
if ( ! F_36 ( V_79 ) )
return F_285 ( V_10 ) ;
V_103 = F_287 ( & V_10 -> V_9 ) ;
F_288 ( & V_10 -> V_9 , V_103 ) ;
return 1 ;
}
static bool F_289 ( struct V_7 * V_10 ,
unsigned long V_104 )
{
unsigned long V_375 = V_10 -> V_9 . V_46 . V_375 ;
bool V_72 = false ;
T_1 V_29 ;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! F_10 ( & V_10 -> V_9 ) ||
( ! ( V_29 & ( 1ULL << V_234 ) ) ) )
return false ;
V_375 &= ~ V_377 ;
V_104 &= ~ V_377 ;
if ( V_375 ^ V_104 ) {
V_10 -> V_1 -> V_2 . V_442 = V_545 ;
V_72 = ( F_245 ( V_10 ) == V_455 ) ;
}
return V_72 ;
}
static int F_290 ( struct V_7 * V_10 )
{
int V_342 , V_546 ;
unsigned long V_104 ;
int V_103 ;
if ( ! F_36 ( V_544 ) )
return F_285 ( V_10 ) ;
if ( F_137 ( ( V_10 -> V_1 -> V_2 . V_403 & V_547 ) == 0 ) )
return F_285 ( V_10 ) ;
V_342 = V_10 -> V_1 -> V_2 . V_403 & V_548 ;
if ( V_10 -> V_1 -> V_2 . V_442 == V_545 )
V_546 = V_549 - V_472 ;
else
V_546 = V_10 -> V_1 -> V_2 . V_442 - V_472 ;
V_103 = 0 ;
if ( V_546 >= 16 ) {
V_546 -= 16 ;
V_104 = F_270 ( & V_10 -> V_9 , V_342 ) ;
switch ( V_546 ) {
case 0 :
if ( ! F_289 ( V_10 , V_104 ) )
V_103 = F_291 ( & V_10 -> V_9 , V_104 ) ;
else
return 1 ;
break;
case 3 :
V_103 = F_253 ( & V_10 -> V_9 , V_104 ) ;
break;
case 4 :
V_103 = F_292 ( & V_10 -> V_9 , V_104 ) ;
break;
case 8 :
V_103 = F_293 ( & V_10 -> V_9 , V_104 ) ;
break;
default:
F_294 ( 1 , L_11 , V_546 ) ;
F_191 ( & V_10 -> V_9 , V_227 ) ;
return 1 ;
}
} else {
switch ( V_546 ) {
case 0 :
V_104 = F_249 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_104 = V_10 -> V_9 . V_46 . V_454 ;
break;
case 3 :
V_104 = F_153 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_104 = F_295 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_104 = F_296 ( & V_10 -> V_9 ) ;
break;
default:
F_294 ( 1 , L_12 , V_546 ) ;
F_191 ( & V_10 -> V_9 , V_227 ) ;
return 1 ;
}
F_128 ( & V_10 -> V_9 , V_342 , V_104 ) ;
}
F_288 ( & V_10 -> V_9 , V_103 ) ;
return 1 ;
}
static int F_297 ( struct V_7 * V_10 )
{
int V_342 , V_550 ;
unsigned long V_104 ;
if ( V_10 -> V_9 . V_389 == 0 ) {
F_16 ( V_10 ) ;
V_10 -> V_9 . V_46 . V_398 |= V_399 ;
return 1 ;
}
if ( ! F_88 ( V_544 ) )
return F_285 ( V_10 ) ;
V_342 = V_10 -> V_1 -> V_2 . V_403 & V_548 ;
V_550 = V_10 -> V_1 -> V_2 . V_442 - V_474 ;
if ( V_550 >= 16 ) {
if ( ! F_298 ( & V_10 -> V_9 , V_550 - 16 ) )
return 1 ;
V_104 = F_270 ( & V_10 -> V_9 , V_342 ) ;
F_299 ( & V_10 -> V_9 , V_550 - 16 , V_104 ) ;
} else {
if ( ! F_298 ( & V_10 -> V_9 , V_550 ) )
return 1 ;
F_300 ( & V_10 -> V_9 , V_550 , & V_104 ) ;
F_128 ( & V_10 -> V_9 , V_342 , V_104 ) ;
}
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_301 ( struct V_7 * V_10 )
{
struct V_408 * V_408 = V_10 -> V_9 . V_409 ;
int V_148 ;
T_4 V_551 = F_296 ( & V_10 -> V_9 ) ;
V_148 = F_290 ( V_10 ) ;
if ( F_302 ( & V_10 -> V_9 ) )
return V_148 ;
if ( V_551 <= F_296 ( & V_10 -> V_9 ) )
return V_148 ;
V_408 -> V_415 = V_552 ;
return 0 ;
}
static T_1 F_303 ( struct V_8 * V_9 , T_1 V_553 )
{
struct V_1 * V_1 = F_11 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_197 + V_553 ;
}
static int F_304 ( struct V_8 * V_9 , struct V_554 * V_555 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_555 -> V_152 ) {
case V_556 : {
V_555 -> V_11 = V_10 -> V_1 -> V_2 . V_197 +
F_305 ( V_9 , F_306 () ) ;
break;
}
case V_557 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_501 ;
break;
#ifdef F_29
case V_558 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_502 ;
break;
case V_559 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_503 ;
break;
case V_336 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_500 ;
break;
case V_560 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_504 ;
break;
#endif
case V_561 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_505 ;
break;
case V_562 :
V_555 -> V_11 = V_10 -> V_507 ;
break;
case V_563 :
V_555 -> V_11 = V_10 -> V_506 ;
break;
case V_332 :
if ( ! F_88 ( V_331 ) )
return 1 ;
V_555 -> V_11 = V_10 -> V_333 ;
break;
case V_564 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_565 ;
break;
case V_166 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_566 ;
break;
case V_167 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_567 ;
break;
case V_168 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_568 ;
break;
case V_169 :
V_555 -> V_11 = V_10 -> V_1 -> V_65 . V_569 ;
break;
case V_139 :
V_555 -> V_11 = V_10 -> V_24 . V_570 ;
break;
case V_571 :
V_555 -> V_11 = V_10 -> V_24 . V_572 ;
break;
case V_573 :
V_555 -> V_11 = 0x01000065 ;
break;
case V_574 : {
int V_575 , V_576 ;
V_575 = F_307 ( V_9 ) ;
V_576 = F_308 ( V_9 ) ;
if ( V_575 < 0 || V_576 < 0 )
return F_309 ( V_9 , V_555 ) ;
V_555 -> V_11 = 0 ;
if ( V_575 == 0x15 &&
( V_576 >= 0x2 && V_576 < 0x20 ) )
V_555 -> V_11 = 0x1E ;
}
break;
default:
return F_309 ( V_9 , V_555 ) ;
}
return 0 ;
}
static int F_310 ( struct V_7 * V_10 )
{
T_2 V_577 = F_270 ( & V_10 -> V_9 , V_467 ) ;
struct V_554 V_555 ;
V_555 . V_152 = V_577 ;
V_555 . V_578 = false ;
if ( F_304 ( & V_10 -> V_9 , & V_555 ) ) {
F_311 ( V_577 ) ;
F_228 ( & V_10 -> V_9 , 0 ) ;
} else {
F_312 ( V_577 , V_555 . V_11 ) ;
F_128 ( & V_10 -> V_9 , V_493 ,
V_555 . V_11 & 0xffffffff ) ;
F_128 ( & V_10 -> V_9 , V_309 ,
V_555 . V_11 >> 32 ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_313 ( struct V_8 * V_9 , T_1 V_11 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_579 , V_580 ;
if ( V_11 & ~ V_581 )
return 1 ;
V_580 = V_581 ;
if ( V_10 -> V_24 . V_572 & V_582 )
V_580 &= ~ ( V_583 | V_582 ) ;
V_10 -> V_24 . V_572 &= ~ V_580 ;
V_10 -> V_24 . V_572 |= ( V_11 & V_580 ) ;
V_579 = V_10 -> V_24 . V_572 & V_582 ;
if ( V_579 && ( V_9 -> V_46 . V_61 & V_66 ) )
return 1 ;
return 0 ;
}
static int F_314 ( struct V_8 * V_9 , struct V_554 * V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_577 = V_49 -> V_152 ;
T_1 V_11 = V_49 -> V_11 ;
switch ( V_577 ) {
case V_556 :
F_315 ( V_9 , V_49 ) ;
break;
case V_557 :
V_10 -> V_1 -> V_65 . V_501 = V_11 ;
break;
#ifdef F_29
case V_558 :
V_10 -> V_1 -> V_65 . V_502 = V_11 ;
break;
case V_559 :
V_10 -> V_1 -> V_65 . V_503 = V_11 ;
break;
case V_336 :
V_10 -> V_1 -> V_65 . V_500 = V_11 ;
break;
case V_560 :
V_10 -> V_1 -> V_65 . V_504 = V_11 ;
break;
#endif
case V_561 :
V_10 -> V_1 -> V_65 . V_505 = V_11 ;
break;
case V_562 :
V_10 -> V_507 = V_11 ;
V_10 -> V_1 -> V_65 . V_507 = V_11 ;
break;
case V_563 :
V_10 -> V_506 = V_11 ;
V_10 -> V_1 -> V_65 . V_506 = V_11 ;
break;
case V_332 :
if ( ! F_88 ( V_331 ) )
return 1 ;
V_10 -> V_333 = V_11 ;
F_53 ( V_332 , V_10 -> V_333 ) ;
break;
case V_564 :
if ( ! F_88 ( V_584 ) ) {
F_316 ( V_9 , L_13 ,
V_83 , V_11 ) ;
break;
}
if ( V_11 & V_585 )
return 1 ;
V_10 -> V_1 -> V_65 . V_565 = V_11 ;
F_3 ( V_10 -> V_1 , V_586 ) ;
if ( V_11 & ( 1ULL << 0 ) )
F_83 ( V_10 ) ;
else
F_84 ( V_10 ) ;
break;
case V_139 :
V_10 -> V_24 . V_570 = V_11 ;
break;
case V_571 :
return F_313 ( V_9 , V_11 ) ;
case V_587 :
F_316 ( V_9 , L_14 , V_577 , V_11 ) ;
break;
case V_588 :
if ( F_107 ( V_9 ) )
F_6 ( F_4 ( V_9 ) , V_11 ) ;
default:
return F_317 ( V_9 , V_49 ) ;
}
return 0 ;
}
static int F_318 ( struct V_7 * V_10 )
{
struct V_554 V_49 ;
T_2 V_577 = F_270 ( & V_10 -> V_9 , V_467 ) ;
T_1 V_11 = F_277 ( & V_10 -> V_9 ) ;
V_49 . V_11 = V_11 ;
V_49 . V_152 = V_577 ;
V_49 . V_578 = false ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
if ( F_319 ( & V_10 -> V_9 , & V_49 ) ) {
F_320 ( V_577 , V_11 ) ;
F_228 ( & V_10 -> V_9 , 0 ) ;
} else {
F_321 ( V_577 , V_11 ) ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_322 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_403 )
return F_318 ( V_10 ) ;
else
return F_310 ( V_10 ) ;
}
static int F_323 ( struct V_7 * V_10 )
{
F_202 ( V_509 , & V_10 -> V_9 ) ;
F_155 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_214 &= ~ V_510 ;
F_3 ( V_10 -> V_1 , V_511 ) ;
++ V_10 -> V_9 . V_334 . V_589 ;
return 1 ;
}
static int F_324 ( struct V_7 * V_10 )
{
F_325 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_326 ( struct V_7 * V_10 )
{
F_34 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_327 ( struct V_7 * V_10 )
{
F_328 ( V_590 L_15 ) ;
return F_326 ( V_10 ) ;
}
static int F_329 ( struct V_7 * V_10 )
{
F_328 ( V_590 L_16 ) ;
return F_326 ( V_10 ) ;
}
static int F_330 ( struct V_7 * V_10 )
{
T_2 V_591 = V_10 -> V_1 -> V_2 . V_403 >> 32 ;
T_2 V_592 = V_10 -> V_1 -> V_2 . V_403 ;
T_2 V_292 = V_10 -> V_1 -> V_2 . V_401 >> 32 ;
T_2 V_152 = V_10 -> V_1 -> V_2 . V_401 & 0xFF ;
struct V_593 * V_293 = V_10 -> V_9 . V_46 . V_293 ;
F_331 ( V_10 -> V_9 . V_199 , V_591 , V_592 , V_292 , V_152 ) ;
switch ( V_292 ) {
case V_594 :
F_332 ( V_293 , V_595 , V_591 ) ;
F_332 ( V_293 , V_596 , V_592 ) ;
break;
case V_597 : {
int V_51 ;
struct V_8 * V_9 ;
struct V_203 * V_203 = V_10 -> V_9 . V_203 ;
struct V_593 * V_293 = V_10 -> V_9 . V_46 . V_293 ;
F_333 (i, vcpu, kvm) {
bool V_598 = F_334 ( V_9 , V_293 ,
V_592 & V_599 ,
F_335 ( V_591 ) ,
V_592 & V_600 ) ;
if ( V_598 && ! F_7 ( V_9 ) )
F_336 ( V_9 ) ;
}
break;
}
case V_601 :
break;
case V_602 :
F_337 ( 1 , L_17 ) ;
break;
default:
F_59 ( L_18 ) ;
}
return 1 ;
}
static T_2 * F_338 ( struct V_8 * V_9 , T_2 V_603 , bool V_604 )
{
struct V_201 * V_202 = & V_9 -> V_203 -> V_46 ;
int V_152 ;
T_2 * V_605 ;
int V_606 = F_339 ( V_603 ) ;
if ( ! V_606 )
return NULL ;
if ( V_604 ) {
V_152 = F_340 ( V_606 ) - 1 ;
if ( V_152 > 7 )
return NULL ;
} else {
int V_607 = ( V_606 & 0xf0 ) >> 4 ;
int V_293 = F_340 ( V_606 & 0x0f ) - 1 ;
if ( ( V_293 < 0 ) || ( V_293 > 7 ) ||
( V_607 >= 0xf ) )
return NULL ;
V_152 = ( V_607 << 2 ) + V_293 ;
}
V_605 = ( T_2 * ) F_87 ( V_202 -> V_207 ) ;
return & V_605 [ V_152 ] ;
}
static int F_341 ( struct V_8 * V_9 , T_4 V_608 , T_2 V_603 ,
bool V_609 )
{
bool V_604 ;
T_2 * V_15 , V_291 ;
V_604 = F_342 ( V_9 -> V_46 . V_293 , V_610 ) == V_611 ;
V_15 = F_338 ( V_9 , V_603 , V_604 ) ;
if ( ! V_15 )
return - V_129 ;
V_291 = F_8 ( * V_15 ) ;
V_291 &= ~ V_612 ;
V_291 |= ( V_608 & V_612 ) ;
if ( V_609 )
V_291 |= V_613 ;
else
V_291 &= ~ V_613 ;
F_117 ( * V_15 , V_291 ) ;
return 0 ;
}
static int F_343 ( struct V_8 * V_9 )
{
int V_72 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_603 = F_342 ( V_9 -> V_46 . V_293 , V_614 ) ;
if ( ! V_603 )
return 1 ;
V_72 = F_341 ( V_9 , V_9 -> V_199 , V_603 , true ) ;
if ( V_72 && V_10 -> V_615 ) {
F_341 ( V_9 , 0 , V_10 -> V_615 , false ) ;
V_10 -> V_615 = 0 ;
} else {
V_10 -> V_615 = V_603 ;
}
return V_72 ;
}
static int F_344 ( struct V_8 * V_9 )
{
T_1 * V_616 , * V_617 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_618 = F_342 ( V_9 -> V_46 . V_293 , V_619 ) ;
T_2 V_292 = ( V_618 >> 24 ) & 0xff ;
if ( V_9 -> V_199 == V_292 )
return 0 ;
V_616 = F_112 ( V_9 , V_9 -> V_199 ) ;
V_617 = F_112 ( V_9 , V_292 ) ;
if ( ! V_617 || ! V_616 )
return 1 ;
* V_617 = * V_616 ;
* V_616 = 0ULL ;
F_4 ( V_9 ) -> V_16 = V_617 ;
if ( V_10 -> V_615 )
F_343 ( V_9 ) ;
return 0 ;
}
static int F_345 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_201 * V_202 = & V_9 -> V_203 -> V_46 ;
T_2 V_620 = F_342 ( V_9 -> V_46 . V_293 , V_610 ) ;
T_2 V_621 = ( V_620 >> 28 ) & 0xf ;
if ( V_202 -> V_622 == V_621 )
return 0 ;
F_120 ( F_87 ( V_202 -> V_207 ) ) ;
V_202 -> V_622 = V_621 ;
if ( V_10 -> V_615 )
F_343 ( V_9 ) ;
return 0 ;
}
static int F_346 ( struct V_7 * V_10 )
{
struct V_593 * V_293 = V_10 -> V_9 . V_46 . V_293 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_403 &
V_623 ;
switch ( V_50 ) {
case V_619 :
if ( F_344 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_614 :
if ( F_343 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_610 :
F_345 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
F_332 ( V_293 , V_50 , F_342 ( V_293 , V_50 ) ) ;
return 1 ;
}
static bool F_347 ( T_2 V_50 )
{
bool V_72 = false ;
switch ( V_50 ) {
case V_619 :
case V_624 :
case V_625 :
case V_614 :
case V_610 :
case V_626 :
case V_627 :
case V_596 :
case V_628 :
case V_629 :
case V_630 :
case V_631 :
case V_632 :
case V_633 :
case V_634 :
case V_635 :
V_72 = true ;
break;
default:
break;
}
return V_72 ;
}
static int F_348 ( struct V_7 * V_10 )
{
int V_72 = 0 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_403 &
V_623 ;
T_2 V_636 = V_10 -> V_1 -> V_2 . V_401 &
V_637 ;
bool V_156 = ( V_10 -> V_1 -> V_2 . V_403 >> 32 ) &
V_638 ;
bool V_639 = F_347 ( V_50 ) ;
F_349 ( V_10 -> V_9 . V_199 , V_50 ,
V_639 , V_156 , V_636 ) ;
if ( V_639 ) {
F_337 ( ! V_156 , L_19 ) ;
V_72 = F_346 ( V_10 ) ;
} else {
V_72 = ( F_37 ( & V_10 -> V_9 , 0 ) == V_81 ) ;
}
return V_72 ;
}
static void F_350 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_217 * V_65 = & V_10 -> V_1 -> V_65 ;
F_59 ( L_20 ) ;
F_59 ( L_21 , L_22 , V_2 -> V_26 & 0xffff ) ;
F_59 ( L_21 , L_23 , V_2 -> V_26 >> 16 ) ;
F_59 ( L_21 , L_24 , V_2 -> V_27 & 0xffff ) ;
F_59 ( L_21 , L_25 , V_2 -> V_27 >> 16 ) ;
F_59 ( L_26 , L_27 , V_2 -> V_28 ) ;
F_59 ( L_28 , L_29 , V_2 -> V_29 ) ;
F_59 ( L_30 , L_31 , V_2 -> V_285 ) ;
F_59 ( L_28 , L_32 , V_2 -> V_256 ) ;
F_59 ( L_28 , L_33 , V_2 -> V_257 ) ;
F_59 ( L_28 , L_34 , V_2 -> V_197 ) ;
F_59 ( L_30 , L_35 , V_2 -> V_58 ) ;
F_59 ( L_30 , L_36 , V_2 -> V_392 ) ;
F_59 ( L_26 , L_37 , V_2 -> V_214 ) ;
F_59 ( L_26 , L_38 , V_2 -> V_483 ) ;
F_59 ( L_26 , L_39 , V_2 -> V_73 ) ;
F_59 ( L_26 , L_40 , V_2 -> V_442 ) ;
F_59 ( L_28 , L_41 , V_2 -> V_403 ) ;
F_59 ( L_28 , L_42 , V_2 -> V_401 ) ;
F_59 ( L_26 , L_43 , V_2 -> V_484 ) ;
F_59 ( L_26 , L_44 , V_2 -> V_485 ) ;
F_59 ( L_45 , L_46 , V_2 -> V_280 ) ;
F_59 ( L_28 , L_47 , V_2 -> V_436 ) ;
F_59 ( L_28 , L_48 , V_2 -> V_12 ) ;
F_59 ( L_26 , L_49 , V_2 -> V_97 ) ;
F_59 ( L_26 , L_50 , V_2 -> V_100 ) ;
F_59 ( L_45 , L_51 , V_2 -> V_165 ) ;
F_59 ( L_28 , L_52 , V_2 -> V_78 ) ;
F_59 ( L_28 , L_53 , V_2 -> V_205 ) ;
F_59 ( L_28 , L_54 , V_2 -> V_211 ) ;
F_59 ( L_28 , L_55 , V_2 -> V_212 ) ;
F_59 ( L_56 ) ;
F_59 ( L_57 ,
L_58 ,
V_65 -> V_259 . V_191 , V_65 -> V_259 . V_192 ,
V_65 -> V_259 . V_196 , V_65 -> V_259 . V_95 ) ;
F_59 ( L_57 ,
L_59 ,
V_65 -> V_94 . V_191 , V_65 -> V_94 . V_192 ,
V_65 -> V_94 . V_196 , V_65 -> V_94 . V_95 ) ;
F_59 ( L_57 ,
L_60 ,
V_65 -> V_260 . V_191 , V_65 -> V_260 . V_192 ,
V_65 -> V_260 . V_196 , V_65 -> V_260 . V_95 ) ;
F_59 ( L_57 ,
L_61 ,
V_65 -> V_261 . V_191 , V_65 -> V_261 . V_192 ,
V_65 -> V_261 . V_196 , V_65 -> V_261 . V_95 ) ;
F_59 ( L_57 ,
L_62 ,
V_65 -> V_262 . V_191 , V_65 -> V_262 . V_192 ,
V_65 -> V_262 . V_196 , V_65 -> V_262 . V_95 ) ;
F_59 ( L_57 ,
L_63 ,
V_65 -> V_263 . V_191 , V_65 -> V_263 . V_192 ,
V_65 -> V_263 . V_196 , V_65 -> V_263 . V_95 ) ;
F_59 ( L_57 ,
L_64 ,
V_65 -> V_266 . V_191 , V_65 -> V_266 . V_192 ,
V_65 -> V_266 . V_196 , V_65 -> V_266 . V_95 ) ;
F_59 ( L_57 ,
L_65 ,
V_65 -> V_268 . V_191 , V_65 -> V_268 . V_192 ,
V_65 -> V_268 . V_196 , V_65 -> V_268 . V_95 ) ;
F_59 ( L_57 ,
L_66 ,
V_65 -> V_267 . V_191 , V_65 -> V_267 . V_192 ,
V_65 -> V_267 . V_196 , V_65 -> V_267 . V_95 ) ;
F_59 ( L_57 ,
L_67 ,
V_65 -> V_270 . V_191 , V_65 -> V_270 . V_192 ,
V_65 -> V_270 . V_196 , V_65 -> V_270 . V_95 ) ;
F_59 ( L_68 ,
V_65 -> V_370 , V_65 -> V_61 ) ;
F_59 ( L_69 ,
L_70 , V_65 -> V_375 , L_71 , V_65 -> V_454 ) ;
F_59 ( L_69 ,
L_72 , V_65 -> V_283 , L_73 , V_65 -> V_278 ) ;
F_59 ( L_69 ,
L_74 , V_65 -> V_272 , L_75 , V_65 -> V_397 ) ;
F_59 ( L_69 ,
L_76 , V_65 -> V_91 , L_77 , V_65 -> V_340 ) ;
F_59 ( L_69 ,
L_78 , V_65 -> V_488 , L_79 , V_65 -> V_489 ) ;
F_59 ( L_69 ,
L_80 , V_65 -> V_501 , L_81 , V_65 -> V_502 ) ;
F_59 ( L_69 ,
L_82 , V_65 -> V_503 , L_83 , V_65 -> V_504 ) ;
F_59 ( L_69 ,
L_84 , V_65 -> V_500 ,
L_85 , V_65 -> V_505 ) ;
F_59 ( L_69 ,
L_86 , V_65 -> V_506 ,
L_87 , V_65 -> V_507 ) ;
F_59 ( L_69 ,
L_88 , V_65 -> V_281 , L_89 , V_65 -> V_565 ) ;
F_59 ( L_69 ,
L_90 , V_65 -> V_566 , L_91 , V_65 -> V_567 ) ;
F_59 ( L_69 ,
L_92 , V_65 -> V_568 ,
L_93 , V_65 -> V_569 ) ;
}
static void F_351 ( struct V_8 * V_9 , T_1 * V_640 , T_1 * V_641 )
{
struct V_18 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_640 = V_2 -> V_403 ;
* V_641 = V_2 -> V_401 ;
}
static int F_352 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_408 * V_408 = V_9 -> V_409 ;
T_2 V_442 = V_10 -> V_1 -> V_2 . V_442 ;
F_353 ( V_442 , V_9 , V_487 ) ;
if ( ! F_14 ( V_10 , V_222 ) )
V_9 -> V_46 . V_375 = V_10 -> V_1 -> V_65 . V_375 ;
if ( V_62 )
V_9 -> V_46 . V_283 = V_10 -> V_1 -> V_65 . V_283 ;
if ( F_137 ( V_10 -> V_24 . V_456 ) ) {
F_221 ( V_10 ) ;
V_10 -> V_24 . V_456 = false ;
return 1 ;
}
if ( F_10 ( V_9 ) ) {
int V_452 ;
F_354 ( V_10 -> V_1 -> V_65 . V_91 , V_442 ,
V_10 -> V_1 -> V_2 . V_403 ,
V_10 -> V_1 -> V_2 . V_401 ,
V_10 -> V_1 -> V_2 . V_484 ,
V_10 -> V_1 -> V_2 . V_485 ,
V_487 ) ;
V_452 = F_244 ( V_10 ) ;
if ( V_452 == V_469 )
V_452 = F_245 ( V_10 ) ;
if ( V_452 == V_455 )
return 1 ;
}
F_355 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_442 == V_477 ) {
V_408 -> V_415 = V_642 ;
V_408 -> V_643 . V_644
= V_10 -> V_1 -> V_2 . V_442 ;
F_59 ( L_94 ) ;
F_350 ( V_9 ) ;
return 0 ;
}
if ( F_31 ( V_10 -> V_1 -> V_2 . V_484 ) &&
V_442 != V_453 + V_226 &&
V_442 != V_443 && V_442 != V_645 &&
V_442 != V_459 && V_442 != V_460 )
F_38 ( V_85 L_95
L_96 ,
V_83 , V_10 -> V_1 -> V_2 . V_484 ,
V_442 ) ;
if ( V_442 >= F_356 ( V_646 )
|| ! V_646 [ V_442 ] ) {
F_337 ( 1 , L_97 , V_442 ) ;
F_191 ( V_9 , V_227 ) ;
return 1 ;
}
return V_646 [ V_442 ] ( V_10 ) ;
}
static void F_357 ( struct V_8 * V_9 )
{
int V_147 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_130 , V_147 ) ;
V_121 -> V_136 -> type = 9 ;
F_358 () ;
}
static void F_359 ( struct V_7 * V_10 )
{
int V_147 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_130 , V_147 ) ;
if ( V_10 -> V_131 != V_121 -> V_131 )
F_175 ( V_10 , V_121 ) ;
}
static void F_360 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_97 = V_70 | V_647 ;
V_9 -> V_46 . V_47 |= V_648 ;
F_19 ( V_10 , V_541 ) ;
++ V_9 -> V_334 . V_649 ;
}
static inline void F_361 ( struct V_7 * V_10 , int V_650 )
{
struct V_18 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_483 = V_650 ;
V_2 -> V_214 &= ~ V_651 ;
V_2 -> V_214 |= V_510 |
( ( 0xf ) << V_652 ) ;
F_3 ( V_10 -> V_1 , V_511 ) ;
}
static void F_362 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_76 ( ! ( F_23 ( V_10 ) ) ) ;
F_363 ( V_9 -> V_46 . V_653 . V_86 ) ;
++ V_9 -> V_334 . V_654 ;
V_10 -> V_1 -> V_2 . V_97 = V_9 -> V_46 . V_653 . V_86 |
V_70 | V_71 ;
}
static inline bool F_364 ( struct V_8 * V_9 )
{
return F_10 ( V_9 ) && ( V_9 -> V_46 . V_47 & V_457 ) ;
}
static void F_365 ( struct V_8 * V_9 , int V_655 , int V_656 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_364 ( V_9 ) ||
F_107 ( V_9 ) )
return;
F_13 ( V_10 , V_225 ) ;
if ( V_656 == - 1 )
return;
if ( V_655 >= V_656 )
F_12 ( V_10 , V_225 ) ;
}
static void F_366 ( struct V_8 * V_9 , bool V_657 )
{
return;
}
static bool F_367 ( void )
{
return V_186 ;
}
static void F_368 ( struct V_8 * V_9 , int V_658 )
{
}
static void F_369 ( struct V_8 * V_9 , int V_659 )
{
}
static void F_370 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( ! V_186 )
return;
V_1 -> V_2 . V_214 &= ~ V_215 ;
F_3 ( V_1 , V_511 ) ;
}
static void F_371 ( struct V_8 * V_9 , T_1 * V_660 )
{
return;
}
static void F_372 ( struct V_8 * V_9 )
{
return;
}
static void F_373 ( struct V_8 * V_9 , int V_661 )
{
F_374 ( V_661 , V_9 -> V_46 . V_293 ) ;
F_375 () ;
if ( F_7 ( V_9 ) )
F_53 ( V_662 ,
F_122 ( V_9 -> V_147 ) ) ;
else
F_336 ( V_9 ) ;
}
static int F_376 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
V_72 = ! ( V_1 -> V_2 . V_73 & V_74 ) &&
! ( V_10 -> V_9 . V_46 . V_47 & V_648 ) ;
V_72 = V_72 && F_23 ( V_10 ) && F_232 ( V_10 ) ;
return V_72 ;
}
static bool F_377 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_46 . V_47 & V_648 ) ;
}
static void F_378 ( struct V_8 * V_9 , bool V_663 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_663 ) {
V_10 -> V_9 . V_46 . V_47 |= V_648 ;
F_19 ( V_10 , V_541 ) ;
} else {
V_10 -> V_9 . V_46 . V_47 &= ~ V_648 ;
F_20 ( V_10 , V_541 ) ;
}
}
static int F_379 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
if ( ! F_23 ( V_10 ) ||
( V_1 -> V_2 . V_73 & V_74 ) )
return 0 ;
V_72 = ! ! ( F_250 ( V_9 ) & V_497 ) ;
if ( F_10 ( V_9 ) )
return V_72 && ! ( V_10 -> V_9 . V_46 . V_47 & V_457 ) ;
return V_72 ;
}
static void F_380 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_107 ( V_9 ) )
return;
if ( F_23 ( V_10 ) && F_230 ( V_10 ) ) {
F_154 ( V_10 ) ;
F_361 ( V_10 , 0x0 ) ;
}
}
static void F_381 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_46 . V_47 & ( V_648 | V_542 ) )
== V_648 )
return;
V_10 -> V_412 = true ;
V_10 -> V_1 -> V_65 . V_340 |= ( V_413 | V_414 ) ;
}
static int F_382 ( struct V_203 * V_203 , unsigned int V_57 )
{
return 0 ;
}
static void F_172 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_36 ( V_664 ) )
V_10 -> V_1 -> V_2 . V_392 = V_665 ;
else
V_10 -> V_131 -- ;
}
static void F_383 ( struct V_8 * V_9 )
{
}
static inline void F_384 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_364 ( V_9 ) )
return;
if ( ! F_14 ( V_10 , V_225 ) ) {
int V_666 = V_10 -> V_1 -> V_2 . V_214 & V_667 ;
F_293 ( V_9 , V_666 ) ;
}
}
static inline void F_385 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_666 ;
if ( F_364 ( V_9 ) ||
F_107 ( V_9 ) )
return;
V_666 = F_296 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_214 &= ~ V_667 ;
V_10 -> V_1 -> V_2 . V_214 |= V_666 & V_667 ;
}
static void F_355 ( struct V_7 * V_10 )
{
T_4 V_636 ;
int type ;
T_2 V_668 = V_10 -> V_1 -> V_2 . V_484 ;
unsigned V_96 = V_10 -> V_96 ;
V_10 -> V_96 = 0 ;
if ( ( V_10 -> V_9 . V_46 . V_47 & V_542 )
&& F_39 ( & V_10 -> V_9 ) != V_10 -> V_543 ) {
V_10 -> V_9 . V_46 . V_47 &= ~ ( V_648 | V_542 ) ;
F_202 ( V_509 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_46 . V_528 = false ;
F_251 ( & V_10 -> V_9 ) ;
F_252 ( & V_10 -> V_9 ) ;
if ( ! ( V_668 & V_520 ) )
return;
F_202 ( V_509 , & V_10 -> V_9 ) ;
V_636 = V_668 & V_669 ;
type = V_668 & V_516 ;
switch ( type ) {
case V_527 :
V_10 -> V_9 . V_46 . V_528 = true ;
break;
case V_529 :
if ( F_386 ( V_636 ) ) {
if ( V_636 == V_90 && V_96 &&
F_387 ( & V_10 -> V_9 , V_10 -> V_93 ) )
F_40 ( & V_10 -> V_9 ,
F_39 ( & V_10 -> V_9 ) -
V_96 ) ;
break;
}
if ( V_668 & V_670 ) {
T_2 V_103 = V_10 -> V_1 -> V_2 . V_485 ;
F_388 ( & V_10 -> V_9 , V_636 , V_103 ) ;
} else
F_389 ( & V_10 -> V_9 , V_636 ) ;
break;
case V_531 :
F_390 ( & V_10 -> V_9 , V_636 , false ) ;
break;
default:
break;
}
}
static void F_391 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_484 = V_2 -> V_97 ;
V_2 -> V_485 = V_2 -> V_100 ;
V_2 -> V_97 = 0 ;
F_355 ( V_10 ) ;
}
static void F_392 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_489 = V_9 -> V_46 . V_273 [ V_493 ] ;
V_10 -> V_1 -> V_65 . V_488 = V_9 -> V_46 . V_273 [ V_494 ] ;
V_10 -> V_1 -> V_65 . V_91 = V_9 -> V_46 . V_273 [ V_274 ] ;
if ( F_137 ( V_10 -> V_24 . V_456 ) )
return;
F_359 ( V_10 ) ;
F_385 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_454 = V_9 -> V_46 . V_454 ;
F_25 () ;
F_188 () ;
asm volatile (
"push %%" _ASM_BP "; \n\t"
"mov %c[rbx](%[svm]), %%" _ASM_BX " \n\t"
"mov %c[rcx](%[svm]), %%" _ASM_CX " \n\t"
"mov %c[rdx](%[svm]), %%" _ASM_DX " \n\t"
"mov %c[rsi](%[svm]), %%" _ASM_SI " \n\t"
"mov %c[rdi](%[svm]), %%" _ASM_DI " \n\t"
"mov %c[rbp](%[svm]), %%" _ASM_BP " \n\t"
#ifdef F_29
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
#ifdef F_29
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
#ifdef F_29
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
#ifdef F_29
, "rbx", "rcx", "rdx", "rsi", "rdi"
, "r8", "r9", "r10", "r11" , "r12", "r13", "r14", "r15"
#else
, "ebx", "ecx", "edx", "esi", "edi"
#endif
);
#ifdef F_29
F_53 ( V_322 , V_10 -> V_323 . V_324 ) ;
#else
F_143 ( V_262 , V_10 -> V_323 . V_262 ) ;
#ifndef F_145
F_143 ( V_263 , V_10 -> V_323 . V_263 ) ;
#endif
#endif
F_357 ( V_9 ) ;
F_186 () ;
V_9 -> V_46 . V_454 = V_10 -> V_1 -> V_65 . V_454 ;
V_9 -> V_46 . V_273 [ V_493 ] = V_10 -> V_1 -> V_65 . V_489 ;
V_9 -> V_46 . V_273 [ V_494 ] = V_10 -> V_1 -> V_65 . V_488 ;
V_9 -> V_46 . V_273 [ V_274 ] = V_10 -> V_1 -> V_65 . V_91 ;
if ( F_137 ( V_10 -> V_1 -> V_2 . V_442 == V_460 ) )
F_393 ( & V_10 -> V_9 ) ;
F_26 () ;
if ( F_137 ( V_10 -> V_1 -> V_2 . V_442 == V_460 ) )
F_394 ( & V_10 -> V_9 ) ;
F_384 ( V_9 ) ;
V_10 -> V_78 = 0 ;
V_10 -> V_1 -> V_2 . V_392 = V_671 ;
if ( V_10 -> V_1 -> V_2 . V_442 == V_453 + V_226 )
V_10 -> V_402 = F_395 () ;
if ( V_62 ) {
V_9 -> V_46 . V_672 &= ~ ( 1 << V_343 ) ;
V_9 -> V_46 . V_673 &= ~ ( 1 << V_343 ) ;
}
if ( F_137 ( V_10 -> V_1 -> V_2 . V_442 ==
V_453 + V_228 ) )
F_201 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_396 ( struct V_8 * V_9 , unsigned long V_438 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_283 = V_438 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_172 ( V_9 ) ;
}
static void F_397 ( struct V_8 * V_9 , unsigned long V_438 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_436 = V_438 ;
F_3 ( V_10 -> V_1 , V_439 ) ;
V_10 -> V_1 -> V_65 . V_283 = F_153 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_172 ( V_9 ) ;
}
static int F_398 ( void )
{
T_1 V_674 ;
F_58 ( V_571 , V_674 ) ;
if ( V_674 & ( 1 << V_675 ) )
return 1 ;
return 0 ;
}
static void
F_399 ( struct V_8 * V_9 , unsigned char * V_676 )
{
V_676 [ 0 ] = 0x0f ;
V_676 [ 1 ] = 0x01 ;
V_676 [ 2 ] = 0xd9 ;
}
static void F_400 ( void * V_677 )
{
* ( int * ) V_677 = 0 ;
}
static bool F_401 ( void )
{
return false ;
}
static bool F_402 ( void )
{
return true ;
}
static T_1 F_403 ( struct V_8 * V_9 , T_12 V_678 , bool V_679 )
{
return 0 ;
}
static void F_404 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_680 * V_15 ;
V_10 -> V_490 = ! ! F_405 ( & V_10 -> V_9 ) ;
if ( ! F_107 ( V_9 ) )
return;
V_15 = F_406 ( V_9 , 1 , 0 ) ;
if ( V_15 )
V_15 -> V_577 &= ~ V_6 ( V_681 ) ;
}
static void F_407 ( T_2 V_682 , struct V_680 * V_15 )
{
switch ( V_682 ) {
case 0x1 :
if ( V_186 )
V_15 -> V_577 &= ~ V_6 ( V_681 ) ;
break;
case 0x80000001 :
if ( V_24 )
V_15 -> V_577 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_15 -> V_305 = 1 ;
V_15 -> V_683 = 8 ;
V_15 -> V_577 = 0 ;
V_15 -> V_684 = 0 ;
if ( F_88 ( V_79 ) )
V_15 -> V_684 |= V_685 ;
if ( V_62 )
V_15 -> V_684 |= V_686 ;
break;
}
}
static int F_408 ( void )
{
return V_687 ;
}
static bool F_409 ( void )
{
return F_88 ( V_331 ) ;
}
static bool F_410 ( void )
{
return false ;
}
static bool F_411 ( void )
{
return false ;
}
static bool F_412 ( void )
{
return false ;
}
static bool F_413 ( void )
{
return true ;
}
static void F_414 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_17 ( V_10 , V_422 ) ;
F_167 ( V_10 ) ;
}
static int F_415 ( struct V_8 * V_9 ,
struct V_688 * V_68 ,
enum V_689 V_690 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_452 , V_72 = V_691 ;
struct V_692 V_693 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_68 -> V_29 >= F_356 ( V_694 ) )
goto V_314;
V_693 = V_694 [ V_68 -> V_29 ] ;
if ( V_690 != V_693 . V_690 )
goto V_314;
switch ( V_693 . V_442 ) {
case V_472 :
if ( V_68 -> V_29 == V_695 )
V_693 . V_442 += V_68 -> V_696 ;
break;
case V_549 : {
unsigned long V_375 , V_104 ;
T_1 V_29 ;
if ( V_68 -> V_29 == V_697 )
V_693 . V_442 += V_68 -> V_696 ;
if ( V_693 . V_442 != V_549 ||
V_68 -> V_29 == V_698 )
break;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! ( V_29 & ( 1ULL << V_234 ) ) )
break;
V_375 = V_9 -> V_46 . V_375 & ~ V_377 ;
V_104 = V_68 -> V_699 & ~ V_377 ;
if ( V_68 -> V_29 == V_700 ) {
V_375 &= 0xfUL ;
V_104 &= 0xfUL ;
if ( V_375 & V_492 )
V_104 |= V_492 ;
}
if ( V_375 ^ V_104 )
V_693 . V_442 = V_545 ;
break;
}
case V_474 :
case V_701 :
V_693 . V_442 += V_68 -> V_696 ;
break;
case V_470 :
if ( V_68 -> V_29 == V_702 )
V_1 -> V_2 . V_403 = 1 ;
else
V_1 -> V_2 . V_403 = 0 ;
break;
case V_703 :
if ( V_68 -> V_704 != V_705 )
goto V_314;
case V_471 : {
T_1 V_706 ;
T_2 V_707 ;
if ( V_68 -> V_29 == V_708 ||
V_68 -> V_29 == V_709 ) {
V_706 = ( ( V_68 -> V_699 & 0xffff ) << 16 ) |
V_432 ;
V_707 = V_68 -> V_710 ;
} else {
V_706 = ( V_68 -> V_711 & 0xffff ) << 16 ;
V_707 = V_68 -> V_712 ;
}
if ( V_68 -> V_29 == V_713 ||
V_68 -> V_29 == V_709 )
V_706 |= V_431 ;
if ( V_68 -> V_704 )
V_706 |= V_714 ;
V_707 = F_416 ( V_707 , 4u ) ;
V_706 |= V_707 << V_434 ;
V_706 |= ( T_2 ) V_68 -> V_715 << ( V_716 - 1 ) ;
V_1 -> V_2 . V_403 = V_706 ;
V_1 -> V_2 . V_401 = V_68 -> V_78 ;
break;
}
default:
break;
}
if ( F_36 ( V_79 ) )
V_1 -> V_2 . V_78 = V_68 -> V_78 ;
V_1 -> V_2 . V_442 = V_693 . V_442 ;
V_452 = F_245 ( V_10 ) ;
V_72 = ( V_452 == V_455 ) ? V_717
: V_691 ;
V_314:
return V_72 ;
}
static void F_417 ( struct V_8 * V_9 )
{
F_188 () ;
asm("nop");
F_186 () ;
}
static void F_418 ( struct V_8 * V_9 , int V_147 )
{
}
static inline void F_419 ( struct V_8 * V_9 )
{
if ( F_344 ( V_9 ) != 0 )
return;
if ( F_345 ( V_9 ) != 0 )
return;
F_343 ( V_9 ) ;
}
static int T_5 F_420 ( void )
{
return F_421 ( & V_718 , sizeof( struct V_7 ) ,
F_422 ( struct V_7 ) , V_719 ) ;
}
static void T_6 F_423 ( void )
{
F_424 () ;
}
