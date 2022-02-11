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
static int F_85 ( T_2 V_170 )
{
unsigned long V_171 ;
struct V_172 * V_173 = NULL ;
struct V_8 * V_9 = NULL ;
T_2 V_174 = F_86 ( V_170 ) ;
T_2 V_175 = F_87 ( V_170 ) ;
F_88 ( L_6 , V_83 , V_174 , V_175 ) ;
F_89 ( & V_176 , V_171 ) ;
F_90 (svm_vm_data_hash, ka, hnode, vm_id) {
struct V_177 * V_177 = F_5 ( V_173 , struct V_177 , V_46 ) ;
struct V_172 * V_178 = & V_177 -> V_46 ;
if ( V_178 -> V_179 != V_174 )
continue;
V_9 = F_91 ( V_177 , V_175 ) ;
break;
}
F_92 ( & V_176 , V_171 ) ;
if ( ! V_9 )
return 0 ;
if ( V_9 -> V_180 == V_181 )
F_93 ( V_9 ) ;
return 0 ;
}
static T_5 int F_94 ( void )
{
int V_147 ;
struct V_182 * V_183 ;
void * V_184 ;
int V_148 ;
V_183 = F_95 ( V_149 , V_185 ) ;
if ( ! V_183 )
return - V_150 ;
V_184 = F_96 ( V_183 ) ;
memset ( V_184 , 0xff , V_160 * ( 1 << V_185 ) ) ;
V_186 = F_63 ( V_183 ) << V_141 ;
F_82 () ;
if ( F_97 ( V_187 ) )
F_98 ( V_188 ) ;
if ( F_97 ( V_189 ) )
F_98 ( V_190 ) ;
if ( F_97 ( V_117 ) ) {
V_191 = true ;
V_192 = V_193 ;
V_194 = 32 ;
}
if ( V_24 ) {
F_38 ( V_116 L_7 ) ;
F_98 ( V_66 | V_195 ) ;
}
F_99 (cpu) {
V_148 = F_70 ( V_147 ) ;
if ( V_148 )
goto V_103;
}
if ( ! F_97 ( V_196 ) )
V_62 = false ;
if ( V_62 && ! V_197 ) {
F_38 ( V_116 L_8 ) ;
V_62 = false ;
}
if ( V_62 ) {
F_38 ( V_116 L_9 ) ;
F_100 () ;
} else
F_101 () ;
if ( V_198 ) {
if ( ! V_62 ||
! F_97 ( V_199 ) ||
! F_102 ( V_200 ) ) {
V_198 = false ;
} else {
F_103 ( L_10 ) ;
F_104 ( V_201 ) ;
F_105 ( & V_176 ) ;
F_106 ( & F_85 ) ;
}
}
return 0 ;
V_103:
F_107 ( V_183 , V_185 ) ;
V_186 = 0 ;
return V_148 ;
}
static T_6 void F_108 ( void )
{
int V_147 ;
F_99 (cpu)
F_67 ( V_147 ) ;
F_107 ( F_109 ( V_186 >> V_141 ) , V_185 ) ;
V_186 = 0 ;
}
static void F_110 ( struct V_202 * V_203 )
{
V_203 -> V_204 = 0 ;
V_203 -> V_205 = V_206 | V_207 |
V_208 ;
V_203 -> V_209 = 0xffff ;
V_203 -> V_95 = 0 ;
}
static void F_111 ( struct V_202 * V_203 , T_7 type )
{
V_203 -> V_204 = 0 ;
V_203 -> V_205 = V_206 | type ;
V_203 -> V_209 = 0xffff ;
V_203 -> V_95 = 0 ;
}
static void F_112 ( struct V_8 * V_9 , T_1 V_50 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_210 = 0 ;
if ( F_10 ( V_9 ) ) {
V_210 = V_10 -> V_1 -> V_2 . V_211 -
V_10 -> V_24 . V_25 -> V_2 . V_211 ;
V_10 -> V_24 . V_25 -> V_2 . V_211 = V_50 ;
} else
F_113 ( V_9 -> V_175 ,
V_10 -> V_1 -> V_2 . V_211 ,
V_50 ) ;
V_10 -> V_1 -> V_2 . V_211 = V_50 + V_210 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_114 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_172 * V_178 = & V_10 -> V_9 . V_177 -> V_46 ;
T_8 V_212 = F_115 ( V_10 -> V_213 ) ;
T_8 V_214 = F_115 ( V_178 -> V_215 ) ;
T_8 V_216 = F_115 ( V_178 -> V_217 ) ;
V_1 -> V_2 . V_213 = V_212 & V_218 ;
V_1 -> V_2 . V_219 = V_214 & V_218 ;
V_1 -> V_2 . V_220 = V_216 & V_218 ;
V_1 -> V_2 . V_220 |= V_221 ;
V_1 -> V_2 . V_222 |= V_223 ;
V_10 -> V_9 . V_46 . V_224 = true ;
}
static void F_116 ( struct V_7 * V_10 )
{
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_225 * V_65 = & V_10 -> V_1 -> V_65 ;
V_10 -> V_9 . V_226 = 1 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
F_12 ( V_10 , V_227 ) ;
F_12 ( V_10 , V_228 ) ;
F_12 ( V_10 , V_229 ) ;
F_12 ( V_10 , V_230 ) ;
F_12 ( V_10 , V_231 ) ;
F_12 ( V_10 , V_232 ) ;
if ( ! F_117 ( & V_10 -> V_9 ) )
F_12 ( V_10 , V_233 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_234 ) ;
F_17 ( V_10 , V_235 ) ;
F_17 ( V_10 , V_236 ) ;
F_17 ( V_10 , V_237 ) ;
F_17 ( V_10 , V_238 ) ;
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
F_19 ( V_10 , V_256 ) ;
F_19 ( V_10 , V_257 ) ;
F_19 ( V_10 , V_258 ) ;
F_19 ( V_10 , V_259 ) ;
F_19 ( V_10 , V_260 ) ;
F_19 ( V_10 , V_261 ) ;
F_19 ( V_10 , V_262 ) ;
F_19 ( V_10 , V_263 ) ;
V_2 -> V_264 = V_186 ;
V_2 -> V_265 = F_118 ( V_10 -> V_154 ) ;
V_2 -> V_222 = V_266 ;
F_110 ( & V_65 -> V_267 ) ;
F_110 ( & V_65 -> V_268 ) ;
F_110 ( & V_65 -> V_269 ) ;
F_110 ( & V_65 -> V_270 ) ;
F_110 ( & V_65 -> V_271 ) ;
V_65 -> V_94 . V_204 = 0xf000 ;
V_65 -> V_94 . V_95 = 0xffff0000 ;
V_65 -> V_94 . V_205 = V_272 | V_206 |
V_207 | V_273 ;
V_65 -> V_94 . V_209 = 0xffff ;
V_65 -> V_274 . V_209 = 0xffff ;
V_65 -> V_275 . V_209 = 0xffff ;
F_111 ( & V_65 -> V_276 , V_277 ) ;
F_111 ( & V_65 -> V_278 , V_279 ) ;
F_30 ( & V_10 -> V_9 , 0 ) ;
V_65 -> V_280 = 0xffff0ff0 ;
F_119 ( & V_10 -> V_9 , 2 ) ;
V_65 -> V_91 = 0x0000fff0 ;
V_10 -> V_9 . V_46 . V_281 [ V_282 ] = V_65 -> V_91 ;
F_120 ( & V_10 -> V_9 , V_283 | V_284 | V_285 ) ;
F_121 ( & V_10 -> V_9 ) ;
V_65 -> V_286 = V_287 ;
if ( V_62 ) {
V_2 -> V_288 = 1 ;
F_20 ( V_10 , V_247 ) ;
F_18 ( V_10 , V_234 ) ;
F_13 ( V_10 , V_228 ) ;
F_13 ( V_10 , V_231 ) ;
V_65 -> V_289 = V_10 -> V_9 . V_46 . V_290 ;
V_65 -> V_291 = 0 ;
V_65 -> V_286 = 0 ;
}
V_10 -> V_131 = 0 ;
V_10 -> V_24 . V_1 = 0 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
if ( F_97 ( V_292 ) ) {
V_2 -> V_293 = 3000 ;
F_19 ( V_10 , V_294 ) ;
}
if ( V_198 )
F_114 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
F_21 ( V_10 ) ;
}
static T_1 * F_122 ( struct V_8 * V_9 , int V_152 )
{
T_1 * V_295 ;
struct V_172 * V_178 = & V_9 -> V_177 -> V_46 ;
if ( V_152 >= V_221 )
return NULL ;
V_295 = F_96 ( V_178 -> V_217 ) ;
return & V_295 [ V_152 ] ;
}
static int F_123 ( struct V_8 * V_9 )
{
struct V_177 * V_177 = V_9 -> V_177 ;
int V_72 ;
if ( V_177 -> V_46 . V_296 )
return 0 ;
V_72 = F_124 ( V_177 ,
V_297 ,
V_298 ,
V_160 ) ;
if ( V_72 )
return V_72 ;
V_177 -> V_46 . V_296 = true ;
return 0 ;
}
static int F_125 ( struct V_8 * V_9 )
{
int V_72 ;
T_1 * V_15 , V_299 ;
int V_300 = V_9 -> V_175 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_72 = F_123 ( V_9 ) ;
if ( V_72 )
return V_72 ;
if ( V_300 >= V_221 )
return - V_129 ;
if ( ! V_10 -> V_9 . V_46 . V_301 -> V_281 )
return - V_129 ;
V_10 -> V_213 = F_126 ( V_10 -> V_9 . V_46 . V_301 -> V_281 ) ;
V_15 = F_122 ( V_9 , V_300 ) ;
if ( ! V_15 )
return - V_129 ;
V_299 = F_8 ( * V_15 ) ;
V_299 = ( F_115 ( V_10 -> V_213 ) &
V_302 ) |
V_303 ;
F_127 ( * V_15 , V_299 ) ;
V_10 -> V_16 = V_15 ;
return 0 ;
}
static inline int F_128 ( void )
{
int V_300 ;
F_129 ( & V_304 ) ;
V_300 = F_130 ( V_305 , V_306 , 1 ) ;
if ( V_300 <= V_307 )
F_131 ( V_300 , V_305 ) ;
else
V_300 = - V_308 ;
F_132 ( & V_304 ) ;
return V_300 ;
}
static inline int F_133 ( int V_300 )
{
if ( V_300 <= 0 || V_300 > V_307 )
return - V_129 ;
F_129 ( & V_304 ) ;
F_134 ( V_300 , V_305 ) ;
F_132 ( & V_304 ) ;
return 0 ;
}
static void F_135 ( struct V_177 * V_177 )
{
unsigned long V_171 ;
struct V_172 * V_178 = & V_177 -> V_46 ;
F_133 ( V_178 -> V_179 ) ;
if ( V_178 -> V_215 )
F_68 ( V_178 -> V_215 ) ;
if ( V_178 -> V_217 )
F_68 ( V_178 -> V_217 ) ;
F_89 ( & V_176 , V_171 ) ;
F_136 ( & V_178 -> V_309 ) ;
F_92 ( & V_176 , V_171 ) ;
}
static int F_137 ( struct V_177 * V_177 )
{
unsigned long V_171 ;
int V_174 , V_103 = - V_150 ;
struct V_172 * V_178 = & V_177 -> V_46 ;
struct V_182 * V_310 ;
struct V_182 * V_311 ;
if ( ! V_198 )
return 0 ;
V_174 = F_128 () ;
if ( V_174 < 0 )
return V_174 ;
V_178 -> V_179 = ( T_2 ) V_174 ;
V_310 = F_72 ( V_149 ) ;
if ( ! V_310 )
goto V_312;
V_178 -> V_217 = V_310 ;
F_138 ( F_96 ( V_310 ) ) ;
V_311 = F_72 ( V_149 ) ;
if ( ! V_311 )
goto V_312;
V_178 -> V_215 = V_311 ;
F_138 ( F_96 ( V_311 ) ) ;
F_89 ( & V_176 , V_171 ) ;
F_139 ( V_201 , & V_178 -> V_309 , V_178 -> V_179 ) ;
F_92 ( & V_176 , V_171 ) ;
return 0 ;
V_312:
F_135 ( V_177 ) ;
return V_103 ;
}
static inline int
F_140 ( struct V_8 * V_9 , int V_147 , bool V_148 )
{
int V_72 = 0 ;
unsigned long V_171 ;
struct V_313 * V_314 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_141 ( V_9 -> V_177 ) )
return 0 ;
F_89 ( & V_10 -> V_315 , V_171 ) ;
if ( F_142 ( & V_10 -> V_316 ) )
goto V_317;
F_143 (ir, &svm->ir_list, node) {
V_72 = F_144 ( V_147 , V_148 , V_314 -> V_11 ) ;
if ( V_72 )
break;
}
V_317:
F_92 ( & V_10 -> V_315 , V_171 ) ;
return V_72 ;
}
static void F_145 ( struct V_8 * V_9 , int V_147 )
{
T_1 V_15 ;
int V_318 = F_146 ( V_147 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_117 ( V_9 ) )
return;
if ( F_75 ( V_318 >= V_221 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_75 ( V_15 & V_17 ) ;
V_15 &= ~ V_319 ;
V_15 |= ( V_318 & V_319 ) ;
V_15 &= ~ V_17 ;
if ( V_10 -> V_320 )
V_15 |= V_17 ;
F_127 ( * ( V_10 -> V_16 ) , V_15 ) ;
F_140 ( V_9 , V_318 ,
V_10 -> V_320 ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
T_1 V_15 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_117 ( V_9 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
if ( V_15 & V_17 )
F_140 ( V_9 , - 1 , 0 ) ;
V_15 &= ~ V_17 ;
F_127 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_148 ( struct V_8 * V_9 , bool V_321 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_320 = V_321 ;
if ( V_321 )
F_145 ( V_9 , V_9 -> V_147 ) ;
else
F_147 ( V_9 ) ;
}
static void F_149 ( struct V_8 * V_9 , bool V_322 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_323 ;
T_2 V_324 = 1 ;
if ( ! V_322 ) {
V_10 -> V_9 . V_46 . V_325 = V_298 |
V_326 ;
if ( F_150 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_46 . V_325 |= V_327 ;
}
F_116 ( V_10 ) ;
F_151 ( V_9 , & V_324 , & V_323 , & V_323 , & V_323 ) ;
F_152 ( V_9 , V_328 , V_324 ) ;
if ( F_117 ( V_9 ) && ! V_322 )
F_6 ( V_10 , V_298 ) ;
}
static struct V_8 * F_153 ( struct V_177 * V_177 , unsigned int V_300 )
{
struct V_7 * V_10 ;
struct V_182 * V_182 ;
struct V_182 * V_329 ;
struct V_182 * V_330 ;
struct V_182 * V_331 ;
int V_103 ;
V_10 = F_154 ( V_332 , V_149 ) ;
if ( ! V_10 ) {
V_103 = - V_150 ;
goto V_317;
}
V_103 = F_155 ( & V_10 -> V_9 , V_177 , V_300 ) ;
if ( V_103 )
goto V_333;
V_103 = - V_150 ;
V_182 = F_72 ( V_149 ) ;
if ( ! V_182 )
goto V_334;
V_329 = F_95 ( V_149 , V_161 ) ;
if ( ! V_329 )
goto V_335;
V_331 = F_95 ( V_149 , V_161 ) ;
if ( ! V_331 )
goto V_336;
V_330 = F_72 ( V_149 ) ;
if ( ! V_330 )
goto V_337;
if ( V_198 ) {
V_103 = F_125 ( & V_10 -> V_9 ) ;
if ( V_103 )
goto V_338;
F_156 ( & V_10 -> V_316 ) ;
F_105 ( & V_10 -> V_315 ) ;
}
V_10 -> V_320 = true ;
V_10 -> V_24 . V_25 = F_96 ( V_330 ) ;
V_10 -> V_154 = F_96 ( V_329 ) ;
F_79 ( V_10 -> V_154 ) ;
V_10 -> V_24 . V_154 = F_96 ( V_331 ) ;
F_79 ( V_10 -> V_24 . V_154 ) ;
V_10 -> V_1 = F_96 ( V_182 ) ;
F_138 ( V_10 -> V_1 ) ;
V_10 -> V_339 = F_63 ( V_182 ) << V_141 ;
V_10 -> V_131 = 0 ;
F_116 ( V_10 ) ;
F_49 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_338:
F_68 ( V_330 ) ;
V_337:
F_107 ( V_331 , V_161 ) ;
V_336:
F_107 ( V_329 , V_161 ) ;
V_335:
F_68 ( V_182 ) ;
V_334:
F_157 ( & V_10 -> V_9 ) ;
V_333:
F_158 ( V_332 , V_10 ) ;
V_317:
return F_159 ( V_103 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_68 ( F_109 ( V_10 -> V_339 >> V_141 ) ) ;
F_107 ( F_126 ( V_10 -> V_154 ) , V_161 ) ;
F_68 ( F_126 ( V_10 -> V_24 . V_25 ) ) ;
F_107 ( F_126 ( V_10 -> V_24 . V_154 ) , V_161 ) ;
F_157 ( V_9 ) ;
F_158 ( V_332 , V_10 ) ;
}
static void F_161 ( struct V_8 * V_9 , int V_147 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
if ( F_162 ( V_147 != V_9 -> V_147 ) ) {
V_10 -> V_131 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_29
F_58 ( V_340 , F_4 ( V_9 ) -> V_341 . V_342 ) ;
#endif
F_163 ( V_270 , V_10 -> V_341 . V_270 ) ;
F_163 ( V_271 , V_10 -> V_341 . V_271 ) ;
V_10 -> V_341 . V_343 = F_164 () ;
for ( V_51 = 0 ; V_51 < V_344 ; V_51 ++ )
F_58 ( V_345 [ V_51 ] , V_10 -> V_346 [ V_51 ] ) ;
if ( F_36 ( V_117 ) ) {
T_1 V_347 = V_9 -> V_46 . V_348 ;
if ( V_347 != F_165 ( V_142 ) ) {
F_64 ( V_142 , V_347 ) ;
F_53 ( V_118 , V_347 ) ;
}
}
if ( F_36 ( V_349 ) )
F_53 ( V_350 , V_10 -> V_351 ) ;
F_145 ( V_9 , V_147 ) ;
}
static void F_166 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
F_147 ( V_9 ) ;
++ V_9 -> V_352 . V_353 ;
F_167 ( V_10 -> V_341 . V_343 ) ;
#ifdef F_29
F_168 ( V_270 , V_10 -> V_341 . V_270 ) ;
F_53 ( V_354 , V_355 -> V_356 . V_357 ) ;
F_169 ( V_10 -> V_341 . V_271 ) ;
#else
#ifdef F_170
F_168 ( V_271 , V_10 -> V_341 . V_271 ) ;
#endif
#endif
for ( V_51 = 0 ; V_51 < V_344 ; V_51 ++ )
F_53 ( V_345 [ V_51 ] , V_10 -> V_346 [ V_51 ] ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_148 ( V_9 , false ) ;
}
static void F_172 ( struct V_8 * V_9 )
{
F_148 ( V_9 , true ) ;
}
static unsigned long F_173 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_358 ;
}
static void F_174 ( struct V_8 * V_9 , unsigned long V_358 )
{
F_4 ( V_9 ) -> V_1 -> V_65 . V_358 = V_358 ;
}
static T_2 F_175 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_176 ( struct V_8 * V_9 , enum V_359 V_360 )
{
switch ( V_360 ) {
case V_361 :
F_76 ( ! V_62 ) ;
F_177 ( V_9 , V_9 -> V_46 . V_362 , F_178 ( V_9 ) ) ;
break;
default:
F_81 () ;
}
}
static void F_179 ( struct V_7 * V_10 )
{
F_19 ( V_10 , V_363 ) ;
}
static void F_180 ( struct V_7 * V_10 )
{
F_20 ( V_10 , V_363 ) ;
}
static struct V_202 * F_181 ( struct V_8 * V_9 , int V_203 )
{
struct V_225 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
switch ( V_203 ) {
case V_364 : return & V_65 -> V_94 ;
case V_365 : return & V_65 -> V_269 ;
case V_366 : return & V_65 -> V_267 ;
case V_367 : return & V_65 -> V_270 ;
case V_368 : return & V_65 -> V_271 ;
case V_369 : return & V_65 -> V_268 ;
case V_370 : return & V_65 -> V_278 ;
case V_371 : return & V_65 -> V_276 ;
}
F_81 () ;
return NULL ;
}
static T_1 F_182 ( struct V_8 * V_9 , int V_203 )
{
struct V_202 * V_372 = F_181 ( V_9 , V_203 ) ;
return V_372 -> V_95 ;
}
static void F_183 ( struct V_8 * V_9 ,
struct V_373 * V_374 , int V_203 )
{
struct V_202 * V_372 = F_181 ( V_9 , V_203 ) ;
V_374 -> V_95 = V_372 -> V_95 ;
V_374 -> V_209 = V_372 -> V_209 ;
V_374 -> V_204 = V_372 -> V_204 ;
V_374 -> type = V_372 -> V_205 & V_375 ;
V_374 -> V_372 = ( V_372 -> V_205 >> V_376 ) & 1 ;
V_374 -> V_377 = ( V_372 -> V_205 >> V_378 ) & 3 ;
V_374 -> V_379 = ( V_372 -> V_205 >> V_380 ) & 1 ;
V_374 -> V_381 = ( V_372 -> V_205 >> V_382 ) & 1 ;
V_374 -> V_383 = ( V_372 -> V_205 >> V_384 ) & 1 ;
V_374 -> V_385 = ( V_372 -> V_205 >> V_386 ) & 1 ;
V_374 -> V_22 = V_372 -> V_209 > 0xfffff ;
V_374 -> V_387 = ! V_374 -> V_379 || ( V_374 -> type == 0 ) ;
switch ( V_203 ) {
case V_370 :
V_374 -> type |= 0x2 ;
break;
case V_365 :
case V_366 :
case V_367 :
case V_368 :
if ( ! V_374 -> V_387 )
V_374 -> type |= 0x1 ;
break;
case V_369 :
if ( V_374 -> V_387 )
V_374 -> V_385 = 0 ;
V_374 -> V_377 = F_4 ( V_9 ) -> V_1 -> V_65 . V_388 ;
break;
}
}
static int F_184 ( struct V_8 * V_9 )
{
struct V_225 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
return V_65 -> V_388 ;
}
static void F_185 ( struct V_8 * V_9 , struct V_122 * V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_389 -> V_390 = V_10 -> V_1 -> V_65 . V_275 . V_209 ;
V_389 -> V_135 = V_10 -> V_1 -> V_65 . V_275 . V_95 ;
}
static void F_186 ( struct V_8 * V_9 , struct V_122 * V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_275 . V_209 = V_389 -> V_390 ;
V_10 -> V_1 -> V_65 . V_275 . V_95 = V_389 -> V_135 ;
F_3 ( V_10 -> V_1 , V_391 ) ;
}
static void F_187 ( struct V_8 * V_9 , struct V_122 * V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_389 -> V_390 = V_10 -> V_1 -> V_65 . V_274 . V_209 ;
V_389 -> V_135 = V_10 -> V_1 -> V_65 . V_274 . V_95 ;
}
static void F_188 ( struct V_8 * V_9 , struct V_122 * V_389 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_274 . V_209 = V_389 -> V_390 ;
V_10 -> V_1 -> V_65 . V_274 . V_95 = V_389 -> V_135 ;
F_3 ( V_10 -> V_1 , V_391 ) ;
}
static void F_189 ( struct V_8 * V_9 )
{
}
static void F_190 ( struct V_8 * V_9 )
{
}
static void F_191 ( struct V_8 * V_9 )
{
}
static void F_192 ( struct V_7 * V_10 )
{
T_9 V_392 = V_10 -> V_9 . V_46 . V_393 ;
T_1 * V_394 = & V_10 -> V_1 -> V_65 . V_393 ;
if ( ! V_10 -> V_9 . V_226 )
* V_394 |= V_395 ;
else
* V_394 = ( * V_394 & ~ V_395 )
| ( V_392 & V_395 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
if ( V_392 == * V_394 && V_10 -> V_9 . V_226 ) {
F_13 ( V_10 , V_227 ) ;
F_13 ( V_10 , V_230 ) ;
} else {
F_12 ( V_10 , V_227 ) ;
F_12 ( V_10 , V_230 ) ;
}
}
static void F_120 ( struct V_8 * V_9 , unsigned long V_393 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_29
if ( V_9 -> V_46 . V_61 & V_64 ) {
if ( ! F_193 ( V_9 ) && ( V_393 & V_396 ) ) {
V_9 -> V_46 . V_61 |= V_63 ;
V_10 -> V_1 -> V_65 . V_61 |= V_63 | V_64 ;
}
if ( F_193 ( V_9 ) && ! ( V_393 & V_396 ) ) {
V_9 -> V_46 . V_61 &= ~ V_63 ;
V_10 -> V_1 -> V_65 . V_61 &= ~ ( V_63 | V_64 ) ;
}
}
#endif
V_9 -> V_46 . V_393 = V_393 ;
if ( ! V_62 )
V_393 |= V_396 | V_397 ;
if ( ! V_9 -> V_226 )
V_393 |= V_398 ;
if ( F_194 ( V_9 -> V_177 , V_399 ) )
V_393 &= ~ ( V_284 | V_283 ) ;
V_10 -> V_1 -> V_65 . V_393 = V_393 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_192 ( V_10 ) ;
}
static int F_195 ( struct V_8 * V_9 , unsigned long V_286 )
{
unsigned long V_400 = F_196 () & V_401 ;
unsigned long V_402 = F_4 ( V_9 ) -> V_1 -> V_65 . V_286 ;
if ( V_286 & V_403 )
return 1 ;
if ( V_62 && ( ( V_402 ^ V_286 ) & V_404 ) )
F_197 ( V_9 ) ;
V_9 -> V_46 . V_286 = V_286 ;
if ( ! V_62 )
V_286 |= V_287 ;
V_286 |= V_400 ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_286 = V_286 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_67 ) ;
return 0 ;
}
static void F_198 ( struct V_8 * V_9 ,
struct V_373 * V_374 , int V_203 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_202 * V_372 = F_181 ( V_9 , V_203 ) ;
V_372 -> V_95 = V_374 -> V_95 ;
V_372 -> V_209 = V_374 -> V_209 ;
V_372 -> V_204 = V_374 -> V_204 ;
if ( V_374 -> V_387 )
V_372 -> V_205 = 0 ;
else {
V_372 -> V_205 = ( V_374 -> type & V_375 ) ;
V_372 -> V_205 |= ( V_374 -> V_372 & 1 ) << V_376 ;
V_372 -> V_205 |= ( V_374 -> V_377 & 3 ) << V_378 ;
V_372 -> V_205 |= ( V_374 -> V_379 & 1 ) << V_380 ;
V_372 -> V_205 |= ( V_374 -> V_381 & 1 ) << V_382 ;
V_372 -> V_205 |= ( V_374 -> V_383 & 1 ) << V_384 ;
V_372 -> V_205 |= ( V_374 -> V_385 & 1 ) << V_386 ;
V_372 -> V_205 |= ( V_374 -> V_22 & 1 ) << V_405 ;
}
if ( V_203 == V_369 )
V_10 -> V_1 -> V_65 . V_388 = ( V_372 -> V_205 >> V_378 ) & 3 ;
F_3 ( V_10 -> V_1 , V_406 ) ;
}
static void F_199 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_90 ) ;
if ( V_9 -> V_407 & V_408 ) {
if ( V_9 -> V_407 & V_409 )
F_17 ( V_10 , V_90 ) ;
} else
V_9 -> V_407 = 0 ;
}
static void F_200 ( struct V_7 * V_10 , struct V_120 * V_121 )
{
if ( V_121 -> V_134 > V_121 -> V_132 ) {
++ V_121 -> V_131 ;
V_121 -> V_134 = 1 ;
V_10 -> V_1 -> V_2 . V_410 = V_411 ;
}
V_10 -> V_131 = V_121 -> V_131 ;
V_10 -> V_1 -> V_2 . V_58 = V_121 -> V_134 ++ ;
F_3 ( V_10 -> V_1 , V_412 ) ;
}
static T_1 F_201 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_280 ;
}
static void F_202 ( struct V_8 * V_9 , unsigned long V_413 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_280 = V_413 ;
F_3 ( V_10 -> V_1 , V_414 ) ;
}
static void F_203 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_204 ( V_9 -> V_46 . V_385 [ 0 ] , 0 ) ;
F_204 ( V_9 -> V_46 . V_385 [ 1 ] , 1 ) ;
F_204 ( V_9 -> V_46 . V_385 [ 2 ] , 2 ) ;
F_204 ( V_9 -> V_46 . V_385 [ 3 ] , 3 ) ;
V_9 -> V_46 . V_280 = F_201 ( V_9 ) ;
V_9 -> V_46 . V_415 = V_10 -> V_1 -> V_65 . V_415 ;
V_9 -> V_46 . V_416 &= ~ V_417 ;
F_15 ( V_10 ) ;
}
static void F_205 ( struct V_8 * V_9 , unsigned long V_413 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_415 = V_413 ;
F_3 ( V_10 -> V_1 , V_414 ) ;
}
static int F_206 ( struct V_7 * V_10 )
{
T_1 V_418 = V_10 -> V_1 -> V_2 . V_419 ;
T_1 V_88 ;
int V_148 = 1 ;
switch ( V_10 -> V_420 ) {
default:
V_88 = V_10 -> V_1 -> V_2 . V_421 ;
F_207 ( V_418 , V_88 ) ;
if ( ! V_62 && F_208 ( & V_10 -> V_9 ) )
F_209 ( & V_10 -> V_9 , V_418 ) ;
V_148 = F_210 ( & V_10 -> V_9 , V_418 , V_88 ,
V_10 -> V_1 -> V_2 . V_422 ,
V_10 -> V_1 -> V_2 . V_423 ) ;
break;
case V_424 :
V_10 -> V_420 = 0 ;
F_211 () ;
F_212 ( V_418 ) ;
F_213 () ;
break;
case V_425 :
V_10 -> V_420 = 0 ;
F_211 () ;
F_214 ( V_418 ) ;
F_213 () ;
break;
}
return V_148 ;
}
static int F_215 ( struct V_7 * V_10 )
{
struct V_426 * V_426 = V_10 -> V_9 . V_427 ;
if ( ! ( V_10 -> V_9 . V_407 &
( V_428 | V_429 ) ) &&
! V_10 -> V_430 ) {
F_216 ( & V_10 -> V_9 , V_238 ) ;
return 1 ;
}
if ( V_10 -> V_430 ) {
V_10 -> V_430 = false ;
if ( ! ( V_10 -> V_9 . V_407 & V_428 ) )
V_10 -> V_1 -> V_65 . V_358 &=
~ ( V_431 | V_432 ) ;
}
if ( V_10 -> V_9 . V_407 &
( V_428 | V_429 ) ) {
V_426 -> V_433 = V_434 ;
V_426 -> V_435 . V_46 . V_436 =
V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_426 -> V_435 . V_46 . V_437 = V_238 ;
return 0 ;
}
return 1 ;
}
static int F_217 ( struct V_7 * V_10 )
{
struct V_426 * V_426 = V_10 -> V_9 . V_427 ;
V_426 -> V_433 = V_434 ;
V_426 -> V_435 . V_46 . V_436 = V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_426 -> V_435 . V_46 . V_437 = V_90 ;
return 0 ;
}
static int F_218 ( struct V_7 * V_10 )
{
int V_438 ;
V_438 = F_37 ( & V_10 -> V_9 , V_439 ) ;
if ( V_438 != V_81 )
F_216 ( & V_10 -> V_9 , V_235 ) ;
return 1 ;
}
static int F_219 ( struct V_7 * V_10 )
{
F_220 ( & V_10 -> V_9 , V_237 , 0 ) ;
return 1 ;
}
static void F_221 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_440 ) ;
V_10 -> V_9 . V_226 = 1 ;
F_192 ( V_10 ) ;
}
static int F_222 ( struct V_7 * V_10 )
{
F_221 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_223 ( void )
{
int V_103 , V_51 ;
T_1 V_413 ;
if ( ! V_107 )
return false ;
V_413 = F_45 ( V_441 , & V_103 ) ;
if ( V_103 )
return false ;
V_413 &= ~ ( 1ULL << 62 ) ;
if ( V_413 != 0xb600000000010015ULL )
return false ;
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 )
F_48 ( F_224 ( V_51 ) , 0 , 0 ) ;
V_413 = F_45 ( V_442 , & V_103 ) ;
if ( ! V_103 ) {
T_2 V_101 , V_102 ;
V_413 &= ~ ( 1ULL << 2 ) ;
V_101 = F_46 ( V_413 ) ;
V_102 = F_47 ( V_413 ) ;
F_48 ( V_442 , V_101 , V_102 ) ;
}
F_225 () ;
return true ;
}
static void F_226 ( struct V_7 * V_10 )
{
if ( F_223 () ) {
F_59 ( L_11 ) ;
F_227 ( V_443 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_228 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_229 ( struct V_7 * V_10 )
{
struct V_426 * V_426 = V_10 -> V_9 . V_427 ;
F_138 ( V_10 -> V_1 ) ;
F_116 ( V_10 ) ;
V_426 -> V_433 = V_444 ;
return 0 ;
}
static int F_230 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_2 V_445 = V_10 -> V_1 -> V_2 . V_421 ;
int V_390 , V_446 , string ;
unsigned V_447 ;
++ V_10 -> V_9 . V_352 . V_448 ;
string = ( V_445 & V_449 ) != 0 ;
V_446 = ( V_445 & V_450 ) != 0 ;
if ( string )
return F_37 ( V_9 , 0 ) == V_81 ;
V_447 = V_445 >> 16 ;
V_390 = ( V_445 & V_451 ) >> V_452 ;
V_10 -> V_78 = V_10 -> V_1 -> V_2 . V_419 ;
F_34 ( & V_10 -> V_9 ) ;
return V_446 ? F_231 ( V_9 , V_390 , V_447 )
: F_232 ( V_9 , V_390 , V_447 ) ;
}
static int F_233 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_234 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_352 . V_453 ;
return 1 ;
}
static int F_235 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_236 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 1 ;
return F_237 ( & V_10 -> V_9 ) ;
}
static int F_238 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_239 ( & V_10 -> V_9 ) ;
}
static unsigned long F_240 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_24 . V_454 ;
}
static T_1 F_241 ( struct V_8 * V_9 , int V_152 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_291 = V_10 -> V_24 . V_454 ;
T_1 V_455 ;
int V_72 ;
V_72 = F_242 ( V_9 , F_243 ( V_291 ) , & V_455 ,
F_244 ( V_291 ) + V_152 * 8 , 8 ) ;
if ( V_72 )
return 0 ;
return V_455 ;
}
static void F_245 ( struct V_8 * V_9 ,
unsigned long V_456 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_454 = V_456 ;
F_3 ( V_10 -> V_1 , V_457 ) ;
F_197 ( V_9 ) ;
}
static void F_246 ( struct V_8 * V_9 ,
struct V_458 * V_459 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_460 != V_461 ) {
V_10 -> V_1 -> V_2 . V_460 = V_461 ;
V_10 -> V_1 -> V_2 . V_462 = 0 ;
V_10 -> V_1 -> V_2 . V_421 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_419 = V_459 -> V_135 ;
}
V_10 -> V_1 -> V_2 . V_421 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_421 |= V_459 -> V_88 ;
if ( V_10 -> V_1 -> V_2 . V_421 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_421 &= ~ 1 ;
F_247 ( V_10 ) ;
}
static void F_248 ( struct V_8 * V_9 )
{
F_75 ( F_249 ( V_9 ) ) ;
F_250 ( V_9 ) ;
V_9 -> V_46 . V_463 . V_464 = F_245 ;
V_9 -> V_46 . V_463 . V_465 = F_240 ;
V_9 -> V_46 . V_463 . V_466 = F_241 ;
V_9 -> V_46 . V_463 . V_467 = F_246 ;
V_9 -> V_46 . V_463 . V_468 = F_28 () ;
F_251 ( V_9 , & V_9 -> V_46 . V_463 ) ;
V_9 -> V_46 . V_362 = & V_9 -> V_46 . V_469 ;
}
static void F_252 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_362 = & V_9 -> V_46 . V_463 ;
}
static int F_253 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_46 . V_61 & V_66 )
|| ! F_193 ( & V_10 -> V_9 ) ) {
F_216 ( & V_10 -> V_9 , V_235 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_65 . V_388 ) {
F_254 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_10 , unsigned V_86 ,
bool V_87 , T_2 V_88 )
{
int V_470 ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_460 = V_471 + V_86 ;
V_10 -> V_1 -> V_2 . V_462 = 0 ;
V_10 -> V_1 -> V_2 . V_421 = V_88 ;
V_10 -> V_1 -> V_2 . V_419 = V_10 -> V_9 . V_46 . V_472 ;
V_470 = F_255 ( V_10 ) ;
if ( V_470 == V_473 )
V_10 -> V_24 . V_474 = true ;
return V_470 ;
}
static inline bool F_256 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_475 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_476 ) )
return false ;
if ( V_10 -> V_24 . V_474 )
return false ;
V_10 -> V_1 -> V_2 . V_460 = V_477 ;
V_10 -> V_1 -> V_2 . V_421 = 0 ;
V_10 -> V_1 -> V_2 . V_419 = 0 ;
if ( V_10 -> V_24 . V_29 & 1ULL ) {
V_10 -> V_24 . V_474 = true ;
F_257 ( V_10 -> V_1 -> V_65 . V_91 ) ;
return false ;
}
return true ;
}
static inline bool F_258 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_240 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_460 = V_478 ;
V_10 -> V_24 . V_474 = true ;
return false ;
}
static void * F_259 ( struct V_7 * V_10 , T_1 V_479 , struct V_182 * * V_480 )
{
struct V_182 * V_182 ;
F_260 () ;
V_182 = F_261 ( & V_10 -> V_9 , V_479 >> V_141 ) ;
if ( F_262 ( V_182 ) )
goto error;
* V_480 = V_182 ;
return F_263 ( V_182 ) ;
error:
F_254 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_264 ( struct V_182 * V_182 )
{
F_265 ( V_182 ) ;
F_266 ( V_182 ) ;
}
static int F_267 ( struct V_7 * V_10 )
{
unsigned V_447 , V_390 , V_481 ;
T_10 V_104 , V_77 ;
T_4 V_482 ;
T_1 V_479 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_249 ) ) )
return V_483 ;
V_447 = V_10 -> V_1 -> V_2 . V_421 >> 16 ;
V_390 = ( V_10 -> V_1 -> V_2 . V_421 & V_451 ) >>
V_452 ;
V_479 = V_10 -> V_24 . V_484 + ( V_447 / 8 ) ;
V_482 = V_447 % 8 ;
V_481 = ( V_482 + V_390 > 8 ) ? 2 : 1 ;
V_77 = ( 0xf >> ( 4 - V_390 ) ) << V_482 ;
V_104 = 0 ;
if ( F_268 ( & V_10 -> V_9 , V_479 , & V_104 , V_481 ) )
return V_473 ;
return ( V_104 & V_77 ) ? V_473 : V_483 ;
}
static int F_269 ( struct V_7 * V_10 )
{
T_2 V_50 , V_49 , V_413 ;
int V_156 , V_77 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_250 ) ) )
return V_483 ;
V_49 = V_10 -> V_9 . V_46 . V_281 [ V_485 ] ;
V_50 = F_24 ( V_49 ) ;
V_156 = V_10 -> V_1 -> V_2 . V_421 & 1 ;
V_77 = 1 << ( ( 2 * ( V_49 & 0xf ) ) + V_156 ) ;
if ( V_50 == V_56 )
return V_473 ;
V_50 *= 4 ;
if ( F_268 ( & V_10 -> V_9 , V_10 -> V_24 . V_486 + V_50 , & V_413 , 4 ) )
return V_473 ;
return ( V_413 & V_77 ) ? V_473 : V_483 ;
}
static int F_270 ( struct V_7 * V_10 )
{
T_2 V_460 = V_10 -> V_1 -> V_2 . V_460 ;
switch ( V_460 ) {
case V_477 :
case V_478 :
case V_471 + V_236 :
return V_483 ;
case V_461 :
if ( V_62 )
return V_483 ;
break;
case V_471 + V_234 :
if ( ! V_62 && V_10 -> V_420 == 0 )
return V_483 ;
break;
case V_471 + V_440 :
F_222 ( V_10 ) ;
break;
default:
break;
}
return V_487 ;
}
static int F_255 ( struct V_7 * V_10 )
{
T_2 V_460 = V_10 -> V_1 -> V_2 . V_460 ;
int V_470 = V_483 ;
switch ( V_460 ) {
case V_488 :
V_470 = F_269 ( V_10 ) ;
break;
case V_489 :
V_470 = F_267 ( V_10 ) ;
break;
case V_490 ... V_491 : {
T_2 V_6 = 1U << ( V_460 - V_490 ) ;
if ( V_10 -> V_24 . V_26 & V_6 )
V_470 = V_473 ;
break;
}
case V_492 ... V_493 : {
T_2 V_6 = 1U << ( V_460 - V_492 ) ;
if ( V_10 -> V_24 . V_27 & V_6 )
V_470 = V_473 ;
break;
}
case V_471 ... V_471 + 0x1f : {
T_2 V_494 = 1 << ( V_460 - V_471 ) ;
if ( V_10 -> V_24 . V_28 & V_494 )
V_470 = V_473 ;
else if ( ( V_460 == V_471 + V_234 ) &&
V_10 -> V_420 != 0 )
V_470 = V_473 ;
break;
}
case V_495 : {
V_470 = V_473 ;
break;
}
default: {
T_1 V_496 = 1ULL << ( V_460 - V_477 ) ;
if ( V_10 -> V_24 . V_29 & V_496 )
V_470 = V_473 ;
}
}
return V_470 ;
}
static int F_271 ( struct V_7 * V_10 )
{
int V_470 ;
V_470 = F_255 ( V_10 ) ;
if ( V_470 == V_473 )
F_247 ( V_10 ) ;
return V_470 ;
}
static inline void F_272 ( struct V_1 * V_497 , struct V_1 * V_498 )
{
struct V_18 * V_499 = & V_497 -> V_2 ;
struct V_18 * V_500 = & V_498 -> V_2 ;
V_499 -> V_26 = V_500 -> V_26 ;
V_499 -> V_27 = V_500 -> V_27 ;
V_499 -> V_28 = V_500 -> V_28 ;
V_499 -> V_29 = V_500 -> V_29 ;
V_499 -> V_264 = V_500 -> V_264 ;
V_499 -> V_265 = V_500 -> V_265 ;
V_499 -> V_211 = V_500 -> V_211 ;
V_499 -> V_58 = V_500 -> V_58 ;
V_499 -> V_410 = V_500 -> V_410 ;
V_499 -> V_222 = V_500 -> V_222 ;
V_499 -> V_501 = V_500 -> V_501 ;
V_499 -> V_73 = V_500 -> V_73 ;
V_499 -> V_460 = V_500 -> V_460 ;
V_499 -> V_462 = V_500 -> V_462 ;
V_499 -> V_421 = V_500 -> V_421 ;
V_499 -> V_419 = V_500 -> V_419 ;
V_499 -> V_502 = V_500 -> V_502 ;
V_499 -> V_503 = V_500 -> V_503 ;
V_499 -> V_288 = V_500 -> V_288 ;
V_499 -> V_97 = V_500 -> V_97 ;
V_499 -> V_100 = V_500 -> V_100 ;
V_499 -> V_454 = V_500 -> V_454 ;
V_499 -> V_165 = V_500 -> V_165 ;
}
static int F_247 ( struct V_7 * V_10 )
{
struct V_1 * V_504 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_182 * V_182 ;
F_273 ( V_1 -> V_2 . V_460 ,
V_1 -> V_2 . V_421 ,
V_1 -> V_2 . V_419 ,
V_1 -> V_2 . V_502 ,
V_1 -> V_2 . V_503 ,
V_505 ) ;
V_504 = F_259 ( V_10 , V_10 -> V_24 . V_1 , & V_182 ) ;
if ( ! V_504 )
return 1 ;
F_274 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_1 = 0 ;
F_22 ( V_10 ) ;
V_504 -> V_65 . V_267 = V_1 -> V_65 . V_267 ;
V_504 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_504 -> V_65 . V_268 = V_1 -> V_65 . V_268 ;
V_504 -> V_65 . V_269 = V_1 -> V_65 . V_269 ;
V_504 -> V_65 . V_274 = V_1 -> V_65 . V_274 ;
V_504 -> V_65 . V_275 = V_1 -> V_65 . V_275 ;
V_504 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_504 -> V_65 . V_393 = F_275 ( & V_10 -> V_9 ) ;
V_504 -> V_65 . V_291 = F_178 ( & V_10 -> V_9 ) ;
V_504 -> V_65 . V_472 = V_1 -> V_65 . V_472 ;
V_504 -> V_65 . V_286 = V_10 -> V_9 . V_46 . V_286 ;
V_504 -> V_65 . V_358 = F_276 ( & V_10 -> V_9 ) ;
V_504 -> V_65 . V_91 = V_1 -> V_65 . V_91 ;
V_504 -> V_65 . V_506 = V_1 -> V_65 . V_506 ;
V_504 -> V_65 . V_507 = V_1 -> V_65 . V_507 ;
V_504 -> V_65 . V_415 = V_1 -> V_65 . V_415 ;
V_504 -> V_65 . V_280 = V_1 -> V_65 . V_280 ;
V_504 -> V_65 . V_388 = V_1 -> V_65 . V_388 ;
V_504 -> V_2 . V_222 = V_1 -> V_2 . V_222 ;
V_504 -> V_2 . V_501 = V_1 -> V_2 . V_501 ;
V_504 -> V_2 . V_73 = V_1 -> V_2 . V_73 ;
V_504 -> V_2 . V_460 = V_1 -> V_2 . V_460 ;
V_504 -> V_2 . V_462 = V_1 -> V_2 . V_462 ;
V_504 -> V_2 . V_421 = V_1 -> V_2 . V_421 ;
V_504 -> V_2 . V_419 = V_1 -> V_2 . V_419 ;
V_504 -> V_2 . V_502 = V_1 -> V_2 . V_502 ;
V_504 -> V_2 . V_503 = V_1 -> V_2 . V_503 ;
if ( V_10 -> V_508 )
V_504 -> V_2 . V_78 = V_1 -> V_2 . V_78 ;
if ( V_1 -> V_2 . V_97 & V_70 ) {
struct V_18 * V_509 = & V_504 -> V_2 ;
V_509 -> V_502 = V_1 -> V_2 . V_97 ;
V_509 -> V_503 = V_1 -> V_2 . V_100 ;
}
V_504 -> V_2 . V_410 = 0 ;
V_504 -> V_2 . V_97 = 0 ;
V_504 -> V_2 . V_100 = 0 ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_475 ) )
V_504 -> V_2 . V_222 &= ~ V_266 ;
F_272 ( V_1 , V_25 ) ;
F_277 ( & V_10 -> V_9 ) ;
F_278 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_454 = 0 ;
V_10 -> V_1 -> V_65 . V_267 = V_25 -> V_65 . V_267 ;
V_10 -> V_1 -> V_65 . V_94 = V_25 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_268 = V_25 -> V_65 . V_268 ;
V_10 -> V_1 -> V_65 . V_269 = V_25 -> V_65 . V_269 ;
V_10 -> V_1 -> V_65 . V_274 = V_25 -> V_65 . V_274 ;
V_10 -> V_1 -> V_65 . V_275 = V_25 -> V_65 . V_275 ;
F_119 ( & V_10 -> V_9 , V_25 -> V_65 . V_358 ) ;
F_30 ( & V_10 -> V_9 , V_25 -> V_65 . V_61 ) ;
F_120 ( & V_10 -> V_9 , V_25 -> V_65 . V_393 | V_510 ) ;
F_195 ( & V_10 -> V_9 , V_25 -> V_65 . V_286 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_291 = V_25 -> V_65 . V_291 ;
V_10 -> V_9 . V_46 . V_291 = V_25 -> V_65 . V_291 ;
} else {
( void ) F_279 ( & V_10 -> V_9 , V_25 -> V_65 . V_291 ) ;
}
F_152 ( & V_10 -> V_9 , V_511 , V_25 -> V_65 . V_507 ) ;
F_152 ( & V_10 -> V_9 , V_512 , V_25 -> V_65 . V_506 ) ;
F_152 ( & V_10 -> V_9 , V_282 , V_25 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_415 = 0 ;
V_10 -> V_1 -> V_65 . V_388 = 0 ;
V_10 -> V_1 -> V_2 . V_502 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_264 ( V_182 ) ;
F_252 ( & V_10 -> V_9 ) ;
F_121 ( & V_10 -> V_9 ) ;
F_280 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_281 ( struct V_7 * V_10 )
{
int V_51 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_250 ) ) )
return true ;
for ( V_51 = 0 ; V_51 < V_163 ; V_51 ++ ) {
T_2 V_413 , V_513 ;
T_1 V_50 ;
if ( V_164 [ V_51 ] == 0xffffffff )
break;
V_513 = V_164 [ V_51 ] ;
V_50 = V_10 -> V_24 . V_486 + ( V_513 * 4 ) ;
if ( F_268 ( & V_10 -> V_9 , V_50 , & V_413 , 4 ) )
return false ;
V_10 -> V_24 . V_154 [ V_513 ] = V_10 -> V_154 [ V_513 ] | V_413 ;
}
V_10 -> V_1 -> V_2 . V_265 = F_118 ( V_10 -> V_24 . V_154 ) ;
return true ;
}
static bool F_282 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_29 & ( 1ULL << V_253 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_58 == 0 )
return false ;
if ( V_1 -> V_2 . V_288 && ! V_62 )
return false ;
return true ;
}
static bool F_283 ( struct V_7 * V_10 )
{
struct V_1 * V_504 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_182 * V_182 ;
T_1 V_514 ;
V_514 = V_10 -> V_1 -> V_65 . V_507 ;
V_504 = F_259 ( V_10 , V_10 -> V_1 -> V_65 . V_507 , & V_182 ) ;
if ( ! V_504 )
return false ;
if ( ! F_282 ( V_504 ) ) {
V_504 -> V_2 . V_460 = V_495 ;
V_504 -> V_2 . V_462 = 0 ;
V_504 -> V_2 . V_421 = 0 ;
V_504 -> V_2 . V_419 = 0 ;
F_264 ( V_182 ) ;
return false ;
}
F_284 ( V_10 -> V_1 -> V_65 . V_91 , V_514 ,
V_504 -> V_65 . V_91 ,
V_504 -> V_2 . V_222 ,
V_504 -> V_2 . V_97 ,
V_504 -> V_2 . V_288 ) ;
F_285 ( V_504 -> V_2 . V_26 & 0xffff ,
V_504 -> V_2 . V_26 >> 16 ,
V_504 -> V_2 . V_28 ,
V_504 -> V_2 . V_29 ) ;
F_277 ( & V_10 -> V_9 ) ;
F_278 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_267 = V_1 -> V_65 . V_267 ;
V_25 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_25 -> V_65 . V_268 = V_1 -> V_65 . V_268 ;
V_25 -> V_65 . V_269 = V_1 -> V_65 . V_269 ;
V_25 -> V_65 . V_274 = V_1 -> V_65 . V_274 ;
V_25 -> V_65 . V_275 = V_1 -> V_65 . V_275 ;
V_25 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_25 -> V_65 . V_393 = F_275 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_286 = V_10 -> V_9 . V_46 . V_286 ;
V_25 -> V_65 . V_358 = F_276 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_91 = F_39 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_506 = V_1 -> V_65 . V_506 ;
V_25 -> V_65 . V_507 = V_1 -> V_65 . V_507 ;
if ( V_62 )
V_25 -> V_65 . V_291 = V_1 -> V_65 . V_291 ;
else
V_25 -> V_65 . V_291 = F_178 ( & V_10 -> V_9 ) ;
F_272 ( V_25 , V_1 ) ;
if ( F_276 ( & V_10 -> V_9 ) & V_515 )
V_10 -> V_9 . V_46 . V_47 |= V_476 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_476 ;
if ( V_504 -> V_2 . V_288 ) {
F_286 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_454 = V_504 -> V_2 . V_454 ;
F_248 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_65 . V_267 = V_504 -> V_65 . V_267 ;
V_10 -> V_1 -> V_65 . V_94 = V_504 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_268 = V_504 -> V_65 . V_268 ;
V_10 -> V_1 -> V_65 . V_269 = V_504 -> V_65 . V_269 ;
V_10 -> V_1 -> V_65 . V_274 = V_504 -> V_65 . V_274 ;
V_10 -> V_1 -> V_65 . V_275 = V_504 -> V_65 . V_275 ;
F_119 ( & V_10 -> V_9 , V_504 -> V_65 . V_358 ) ;
F_30 ( & V_10 -> V_9 , V_504 -> V_65 . V_61 ) ;
F_120 ( & V_10 -> V_9 , V_504 -> V_65 . V_393 ) ;
F_195 ( & V_10 -> V_9 , V_504 -> V_65 . V_286 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_291 = V_504 -> V_65 . V_291 ;
V_10 -> V_9 . V_46 . V_291 = V_504 -> V_65 . V_291 ;
} else
( void ) F_279 ( & V_10 -> V_9 , V_504 -> V_65 . V_291 ) ;
F_121 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_65 . V_472 = V_10 -> V_9 . V_46 . V_472 = V_504 -> V_65 . V_472 ;
F_152 ( & V_10 -> V_9 , V_511 , V_504 -> V_65 . V_507 ) ;
F_152 ( & V_10 -> V_9 , V_512 , V_504 -> V_65 . V_506 ) ;
F_152 ( & V_10 -> V_9 , V_282 , V_504 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_507 = V_504 -> V_65 . V_507 ;
V_10 -> V_1 -> V_65 . V_506 = V_504 -> V_65 . V_506 ;
V_10 -> V_1 -> V_65 . V_91 = V_504 -> V_65 . V_91 ;
V_10 -> V_1 -> V_65 . V_415 = V_504 -> V_65 . V_415 ;
V_10 -> V_1 -> V_65 . V_280 = V_504 -> V_65 . V_280 ;
V_10 -> V_1 -> V_65 . V_388 = V_504 -> V_65 . V_388 ;
V_10 -> V_24 . V_486 = V_504 -> V_2 . V_265 & ~ 0x0fffULL ;
V_10 -> V_24 . V_484 = V_504 -> V_2 . V_264 & ~ 0x0fffULL ;
V_10 -> V_24 . V_26 = V_504 -> V_2 . V_26 ;
V_10 -> V_24 . V_27 = V_504 -> V_2 . V_27 ;
V_10 -> V_24 . V_28 = V_504 -> V_2 . V_28 ;
V_10 -> V_24 . V_29 = V_504 -> V_2 . V_29 ;
F_197 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_222 = V_504 -> V_2 . V_222 | V_266 ;
if ( V_504 -> V_2 . V_222 & V_266 )
V_10 -> V_9 . V_46 . V_47 |= V_475 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_475 ;
if ( V_10 -> V_9 . V_46 . V_47 & V_475 ) {
F_13 ( V_10 , V_516 ) ;
F_13 ( V_10 , V_233 ) ;
}
F_20 ( V_10 , V_254 ) ;
V_10 -> V_1 -> V_2 . V_165 = V_504 -> V_2 . V_165 ;
V_10 -> V_1 -> V_2 . V_501 = V_504 -> V_2 . V_501 ;
V_10 -> V_1 -> V_2 . V_73 = V_504 -> V_2 . V_73 ;
V_10 -> V_1 -> V_2 . V_211 += V_504 -> V_2 . V_211 ;
V_10 -> V_1 -> V_2 . V_97 = V_504 -> V_2 . V_97 ;
V_10 -> V_1 -> V_2 . V_100 = V_504 -> V_2 . V_100 ;
F_264 ( V_182 ) ;
F_287 ( & V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
V_10 -> V_24 . V_1 = V_514 ;
F_21 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_288 ( struct V_1 * V_498 , struct V_1 * V_517 )
{
V_517 -> V_65 . V_270 = V_498 -> V_65 . V_270 ;
V_517 -> V_65 . V_271 = V_498 -> V_65 . V_271 ;
V_517 -> V_65 . V_278 = V_498 -> V_65 . V_278 ;
V_517 -> V_65 . V_276 = V_498 -> V_65 . V_276 ;
V_517 -> V_65 . V_518 = V_498 -> V_65 . V_518 ;
V_517 -> V_65 . V_519 = V_498 -> V_65 . V_519 ;
V_517 -> V_65 . V_520 = V_498 -> V_65 . V_520 ;
V_517 -> V_65 . V_521 = V_498 -> V_65 . V_521 ;
V_517 -> V_65 . V_522 = V_498 -> V_65 . V_522 ;
V_517 -> V_65 . V_523 = V_498 -> V_65 . V_523 ;
V_517 -> V_65 . V_524 = V_498 -> V_65 . V_524 ;
V_517 -> V_65 . V_525 = V_498 -> V_65 . V_525 ;
}
static int F_289 ( struct V_7 * V_10 )
{
struct V_1 * V_504 ;
struct V_182 * V_182 ;
if ( F_253 ( V_10 ) )
return 1 ;
V_504 = F_259 ( V_10 , V_10 -> V_1 -> V_65 . V_507 , & V_182 ) ;
if ( ! V_504 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_288 ( V_504 , V_10 -> V_1 ) ;
F_264 ( V_182 ) ;
return 1 ;
}
static int F_290 ( struct V_7 * V_10 )
{
struct V_1 * V_504 ;
struct V_182 * V_182 ;
if ( F_253 ( V_10 ) )
return 1 ;
V_504 = F_259 ( V_10 , V_10 -> V_1 -> V_65 . V_507 , & V_182 ) ;
if ( ! V_504 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_288 ( V_10 -> V_1 , V_504 ) ;
F_264 ( V_182 ) ;
return 1 ;
}
static int F_291 ( struct V_7 * V_10 )
{
if ( F_253 ( V_10 ) )
return 1 ;
F_40 ( & V_10 -> V_9 , F_39 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_283 ( V_10 ) )
return 1 ;
if ( ! F_281 ( V_10 ) )
goto V_526;
return 1 ;
V_526:
V_10 -> V_1 -> V_2 . V_460 = V_495 ;
V_10 -> V_1 -> V_2 . V_462 = 0 ;
V_10 -> V_1 -> V_2 . V_421 = 0 ;
V_10 -> V_1 -> V_2 . V_419 = 0 ;
F_247 ( V_10 ) ;
return 1 ;
}
static int F_292 ( struct V_7 * V_10 )
{
if ( F_253 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_227 ( V_527 , & V_10 -> V_9 ) ;
F_21 ( V_10 ) ;
return 1 ;
}
static int F_293 ( struct V_7 * V_10 )
{
if ( F_253 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_22 ( V_10 ) ;
if ( ! F_117 ( & V_10 -> V_9 ) ) {
F_180 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_222 &= ~ V_528 ;
F_3 ( V_10 -> V_1 , V_529 ) ;
}
return 1 ;
}
static int F_294 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_295 ( V_10 -> V_1 -> V_65 . V_91 , F_296 ( & V_10 -> V_9 , V_485 ) ,
F_296 ( & V_10 -> V_9 , V_511 ) ) ;
F_297 ( V_9 , F_296 ( & V_10 -> V_9 , V_511 ) ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_298 ( struct V_7 * V_10 )
{
F_299 ( V_10 -> V_1 -> V_65 . V_91 , F_296 ( & V_10 -> V_9 , V_511 ) ) ;
F_216 ( & V_10 -> V_9 , V_235 ) ;
return 1 ;
}
static int F_300 ( struct V_7 * V_10 )
{
return F_301 ( & V_10 -> V_9 ) ;
}
static int F_302 ( struct V_7 * V_10 )
{
T_1 V_530 = F_303 ( & V_10 -> V_9 ) ;
T_2 V_152 = F_296 ( & V_10 -> V_9 , V_485 ) ;
if ( F_304 ( & V_10 -> V_9 , V_152 , V_530 ) == 0 ) {
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_305 ( struct V_7 * V_10 )
{
T_10 V_531 ;
int V_532 ;
int V_533 = V_10 -> V_1 -> V_2 . V_502 &
V_534 ;
int V_535 = V_10 -> V_1 -> V_2 . V_502 & V_536 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_502 & V_534 ;
T_7 V_537 =
V_10 -> V_1 -> V_2 . V_502 & V_538 ;
bool V_87 = false ;
T_2 V_88 = 0 ;
V_531 = ( T_10 ) V_10 -> V_1 -> V_2 . V_421 ;
if ( V_10 -> V_1 -> V_2 . V_419 &
( 1ULL << V_539 ) )
V_532 = V_540 ;
else if ( V_10 -> V_1 -> V_2 . V_419 &
( 1ULL << V_541 ) )
V_532 = V_542 ;
else if ( V_537 )
V_532 = V_543 ;
else
V_532 = V_544 ;
if ( V_532 == V_543 ) {
switch ( type ) {
case V_545 :
V_10 -> V_9 . V_46 . V_546 = false ;
break;
case V_547 :
if ( V_10 -> V_1 -> V_2 . V_419 &
( 1ULL << V_548 ) ) {
V_87 = true ;
V_88 =
( T_2 ) V_10 -> V_1 -> V_2 . V_419 ;
}
F_277 ( & V_10 -> V_9 ) ;
break;
case V_549 :
F_278 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_532 != V_543 ||
V_533 == V_550 ||
( V_533 == V_547 &&
( V_535 == V_551 || V_535 == V_90 ) ) )
F_34 ( & V_10 -> V_9 ) ;
if ( V_533 != V_550 )
V_535 = - 1 ;
if ( F_306 ( & V_10 -> V_9 , V_531 , V_535 , V_532 ,
V_87 , V_88 ) == V_552 ) {
V_10 -> V_9 . V_427 -> V_433 = V_553 ;
V_10 -> V_9 . V_427 -> V_554 . V_555 = V_556 ;
V_10 -> V_9 . V_427 -> V_554 . V_557 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_307 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
return F_308 ( & V_10 -> V_9 ) ;
}
static int F_309 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_352 . V_558 ;
F_20 ( V_10 , V_559 ) ;
V_10 -> V_9 . V_46 . V_47 |= V_560 ;
V_10 -> V_561 = F_39 ( & V_10 -> V_9 ) ;
F_227 ( V_527 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_310 ( struct V_7 * V_10 )
{
if ( ! F_36 ( V_562 ) )
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
F_297 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_421 ) ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_311 ( struct V_7 * V_10 )
{
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
}
static int F_312 ( struct V_7 * V_10 )
{
int V_103 ;
if ( ! F_36 ( V_79 ) )
return F_311 ( V_10 ) ;
V_103 = F_313 ( & V_10 -> V_9 ) ;
return F_314 ( & V_10 -> V_9 , V_103 ) ;
}
static bool F_315 ( struct V_7 * V_10 ,
unsigned long V_104 )
{
unsigned long V_393 = V_10 -> V_9 . V_46 . V_393 ;
bool V_72 = false ;
T_1 V_29 ;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! F_10 ( & V_10 -> V_9 ) ||
( ! ( V_29 & ( 1ULL << V_242 ) ) ) )
return false ;
V_393 &= ~ V_395 ;
V_104 &= ~ V_395 ;
if ( V_393 ^ V_104 ) {
V_10 -> V_1 -> V_2 . V_460 = V_563 ;
V_72 = ( F_271 ( V_10 ) == V_473 ) ;
}
return V_72 ;
}
static int F_316 ( struct V_7 * V_10 )
{
int V_360 , V_564 ;
unsigned long V_104 ;
int V_103 ;
if ( ! F_36 ( V_562 ) )
return F_311 ( V_10 ) ;
if ( F_162 ( ( V_10 -> V_1 -> V_2 . V_421 & V_565 ) == 0 ) )
return F_311 ( V_10 ) ;
V_360 = V_10 -> V_1 -> V_2 . V_421 & V_566 ;
if ( V_10 -> V_1 -> V_2 . V_460 == V_563 )
V_564 = V_567 - V_490 ;
else
V_564 = V_10 -> V_1 -> V_2 . V_460 - V_490 ;
V_103 = 0 ;
if ( V_564 >= 16 ) {
V_564 -= 16 ;
V_104 = F_296 ( & V_10 -> V_9 , V_360 ) ;
switch ( V_564 ) {
case 0 :
if ( ! F_315 ( V_10 , V_104 ) )
V_103 = F_317 ( & V_10 -> V_9 , V_104 ) ;
else
return 1 ;
break;
case 3 :
V_103 = F_279 ( & V_10 -> V_9 , V_104 ) ;
break;
case 4 :
V_103 = F_318 ( & V_10 -> V_9 , V_104 ) ;
break;
case 8 :
V_103 = F_319 ( & V_10 -> V_9 , V_104 ) ;
break;
default:
F_320 ( 1 , L_12 , V_564 ) ;
F_216 ( & V_10 -> V_9 , V_235 ) ;
return 1 ;
}
} else {
switch ( V_564 ) {
case 0 :
V_104 = F_275 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_104 = V_10 -> V_9 . V_46 . V_472 ;
break;
case 3 :
V_104 = F_178 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_104 = F_321 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_104 = F_322 ( & V_10 -> V_9 ) ;
break;
default:
F_320 ( 1 , L_13 , V_564 ) ;
F_216 ( & V_10 -> V_9 , V_235 ) ;
return 1 ;
}
F_152 ( & V_10 -> V_9 , V_360 , V_104 ) ;
}
return F_314 ( & V_10 -> V_9 , V_103 ) ;
}
static int F_323 ( struct V_7 * V_10 )
{
int V_360 , V_568 ;
unsigned long V_104 ;
if ( V_10 -> V_9 . V_407 == 0 ) {
F_16 ( V_10 ) ;
V_10 -> V_9 . V_46 . V_416 |= V_417 ;
return 1 ;
}
if ( ! F_97 ( V_562 ) )
return F_311 ( V_10 ) ;
V_360 = V_10 -> V_1 -> V_2 . V_421 & V_566 ;
V_568 = V_10 -> V_1 -> V_2 . V_460 - V_492 ;
if ( V_568 >= 16 ) {
if ( ! F_324 ( & V_10 -> V_9 , V_568 - 16 ) )
return 1 ;
V_104 = F_296 ( & V_10 -> V_9 , V_360 ) ;
F_325 ( & V_10 -> V_9 , V_568 - 16 , V_104 ) ;
} else {
if ( ! F_324 ( & V_10 -> V_9 , V_568 ) )
return 1 ;
F_326 ( & V_10 -> V_9 , V_568 , & V_104 ) ;
F_152 ( & V_10 -> V_9 , V_360 , V_104 ) ;
}
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_327 ( struct V_7 * V_10 )
{
struct V_426 * V_426 = V_10 -> V_9 . V_427 ;
int V_148 ;
T_4 V_569 = F_322 ( & V_10 -> V_9 ) ;
V_148 = F_316 ( V_10 ) ;
if ( F_328 ( & V_10 -> V_9 ) )
return V_148 ;
if ( V_569 <= F_322 ( & V_10 -> V_9 ) )
return V_148 ;
V_426 -> V_433 = V_570 ;
return 0 ;
}
static int F_329 ( struct V_8 * V_9 , struct V_571 * V_572 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_572 -> V_152 ) {
case V_573 : {
V_572 -> V_11 = V_10 -> V_1 -> V_2 . V_211 +
F_330 ( V_9 , F_331 () ) ;
break;
}
case V_574 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_519 ;
break;
#ifdef F_29
case V_575 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_520 ;
break;
case V_576 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_521 ;
break;
case V_354 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_518 ;
break;
case V_577 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_522 ;
break;
#endif
case V_578 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_523 ;
break;
case V_579 :
V_572 -> V_11 = V_10 -> V_525 ;
break;
case V_580 :
V_572 -> V_11 = V_10 -> V_524 ;
break;
case V_350 :
if ( ! F_97 ( V_349 ) )
return 1 ;
V_572 -> V_11 = V_10 -> V_351 ;
break;
case V_581 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_582 ;
break;
case V_166 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_583 ;
break;
case V_167 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_584 ;
break;
case V_168 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_585 ;
break;
case V_169 :
V_572 -> V_11 = V_10 -> V_1 -> V_65 . V_586 ;
break;
case V_139 :
V_572 -> V_11 = V_10 -> V_24 . V_587 ;
break;
case V_588 :
V_572 -> V_11 = V_10 -> V_24 . V_589 ;
break;
case V_590 :
V_572 -> V_11 = 0x01000065 ;
break;
case V_591 : {
int V_592 , V_593 ;
V_592 = F_332 ( V_9 ) ;
V_593 = F_333 ( V_9 ) ;
if ( V_592 < 0 || V_593 < 0 )
return F_334 ( V_9 , V_572 ) ;
V_572 -> V_11 = 0 ;
if ( V_592 == 0x15 &&
( V_593 >= 0x2 && V_593 < 0x20 ) )
V_572 -> V_11 = 0x1E ;
}
break;
default:
return F_334 ( V_9 , V_572 ) ;
}
return 0 ;
}
static int F_335 ( struct V_7 * V_10 )
{
T_2 V_594 = F_296 ( & V_10 -> V_9 , V_485 ) ;
struct V_571 V_572 ;
V_572 . V_152 = V_594 ;
V_572 . V_595 = false ;
if ( F_329 ( & V_10 -> V_9 , & V_572 ) ) {
F_336 ( V_594 ) ;
F_254 ( & V_10 -> V_9 , 0 ) ;
} else {
F_337 ( V_594 , V_572 . V_11 ) ;
F_152 ( & V_10 -> V_9 , V_511 ,
V_572 . V_11 & 0xffffffff ) ;
F_152 ( & V_10 -> V_9 , V_328 ,
V_572 . V_11 >> 32 ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_338 ( struct V_8 * V_9 , T_1 V_11 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_596 , V_597 ;
if ( V_11 & ~ V_598 )
return 1 ;
V_597 = V_598 ;
if ( V_10 -> V_24 . V_589 & V_599 )
V_597 &= ~ ( V_600 | V_599 ) ;
V_10 -> V_24 . V_589 &= ~ V_597 ;
V_10 -> V_24 . V_589 |= ( V_11 & V_597 ) ;
V_596 = V_10 -> V_24 . V_589 & V_599 ;
if ( V_596 && ( V_9 -> V_46 . V_61 & V_66 ) )
return 1 ;
return 0 ;
}
static int F_339 ( struct V_8 * V_9 , struct V_571 * V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_594 = V_49 -> V_152 ;
T_1 V_11 = V_49 -> V_11 ;
switch ( V_594 ) {
case V_573 :
F_340 ( V_9 , V_49 ) ;
break;
case V_574 :
V_10 -> V_1 -> V_65 . V_519 = V_11 ;
break;
#ifdef F_29
case V_575 :
V_10 -> V_1 -> V_65 . V_520 = V_11 ;
break;
case V_576 :
V_10 -> V_1 -> V_65 . V_521 = V_11 ;
break;
case V_354 :
V_10 -> V_1 -> V_65 . V_518 = V_11 ;
break;
case V_577 :
V_10 -> V_1 -> V_65 . V_522 = V_11 ;
break;
#endif
case V_578 :
V_10 -> V_1 -> V_65 . V_523 = V_11 ;
break;
case V_579 :
V_10 -> V_525 = V_11 ;
V_10 -> V_1 -> V_65 . V_525 = V_11 ;
break;
case V_580 :
V_10 -> V_524 = V_11 ;
V_10 -> V_1 -> V_65 . V_524 = V_11 ;
break;
case V_350 :
if ( ! F_97 ( V_349 ) )
return 1 ;
V_10 -> V_351 = V_11 ;
F_53 ( V_350 , V_10 -> V_351 ) ;
break;
case V_581 :
if ( ! F_97 ( V_601 ) ) {
F_341 ( V_9 , L_14 ,
V_83 , V_11 ) ;
break;
}
if ( V_11 & V_602 )
return 1 ;
V_10 -> V_1 -> V_65 . V_582 = V_11 ;
F_3 ( V_10 -> V_1 , V_603 ) ;
if ( V_11 & ( 1ULL << 0 ) )
F_83 ( V_10 ) ;
else
F_84 ( V_10 ) ;
break;
case V_139 :
V_10 -> V_24 . V_587 = V_11 ;
break;
case V_588 :
return F_338 ( V_9 , V_11 ) ;
case V_604 :
F_341 ( V_9 , L_15 , V_594 , V_11 ) ;
break;
case V_605 :
if ( F_117 ( V_9 ) )
F_6 ( F_4 ( V_9 ) , V_11 ) ;
default:
return F_342 ( V_9 , V_49 ) ;
}
return 0 ;
}
static int F_343 ( struct V_7 * V_10 )
{
struct V_571 V_49 ;
T_2 V_594 = F_296 ( & V_10 -> V_9 , V_485 ) ;
T_1 V_11 = F_303 ( & V_10 -> V_9 ) ;
V_49 . V_11 = V_11 ;
V_49 . V_152 = V_594 ;
V_49 . V_595 = false ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
if ( F_344 ( & V_10 -> V_9 , & V_49 ) ) {
F_345 ( V_594 , V_11 ) ;
F_254 ( & V_10 -> V_9 , 0 ) ;
} else {
F_346 ( V_594 , V_11 ) ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_347 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_421 )
return F_343 ( V_10 ) ;
else
return F_335 ( V_10 ) ;
}
static int F_348 ( struct V_7 * V_10 )
{
F_227 ( V_527 , & V_10 -> V_9 ) ;
F_180 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_222 &= ~ V_528 ;
F_3 ( V_10 -> V_1 , V_529 ) ;
++ V_10 -> V_9 . V_352 . V_606 ;
return 1 ;
}
static int F_349 ( struct V_7 * V_10 )
{
F_350 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_351 ( struct V_7 * V_10 )
{
F_34 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_352 ( struct V_7 * V_10 )
{
F_353 ( V_607 L_16 ) ;
return F_351 ( V_10 ) ;
}
static int F_354 ( struct V_7 * V_10 )
{
F_353 ( V_607 L_17 ) ;
return F_351 ( V_10 ) ;
}
static int F_355 ( struct V_7 * V_10 )
{
T_2 V_608 = V_10 -> V_1 -> V_2 . V_421 >> 32 ;
T_2 V_609 = V_10 -> V_1 -> V_2 . V_421 ;
T_2 V_300 = V_10 -> V_1 -> V_2 . V_419 >> 32 ;
T_2 V_152 = V_10 -> V_1 -> V_2 . V_419 & 0xFF ;
struct V_610 * V_301 = V_10 -> V_9 . V_46 . V_301 ;
F_356 ( V_10 -> V_9 . V_175 , V_608 , V_609 , V_300 , V_152 ) ;
switch ( V_300 ) {
case V_611 :
F_357 ( V_301 , V_612 , V_608 ) ;
F_357 ( V_301 , V_613 , V_609 ) ;
break;
case V_614 : {
int V_51 ;
struct V_8 * V_9 ;
struct V_177 * V_177 = V_10 -> V_9 . V_177 ;
struct V_610 * V_301 = V_10 -> V_9 . V_46 . V_301 ;
F_358 (i, vcpu, kvm) {
bool V_615 = F_359 ( V_9 , V_301 ,
V_609 & V_616 ,
F_360 ( V_608 ) ,
V_609 & V_617 ) ;
if ( V_615 && ! F_7 ( V_9 ) )
F_93 ( V_9 ) ;
}
break;
}
case V_618 :
break;
case V_619 :
F_361 ( 1 , L_18 ) ;
break;
default:
F_59 ( L_19 ) ;
}
return 1 ;
}
static T_2 * F_362 ( struct V_8 * V_9 , T_2 V_620 , bool V_621 )
{
struct V_172 * V_178 = & V_9 -> V_177 -> V_46 ;
int V_152 ;
T_2 * V_622 ;
int V_623 = F_363 ( V_620 ) ;
if ( ! V_623 )
return NULL ;
if ( V_621 ) {
V_152 = F_364 ( V_623 ) - 1 ;
if ( V_152 > 7 )
return NULL ;
} else {
int V_624 = ( V_623 & 0xf0 ) >> 4 ;
int V_301 = F_364 ( V_623 & 0x0f ) - 1 ;
if ( ( V_301 < 0 ) || ( V_301 > 7 ) ||
( V_624 >= 0xf ) )
return NULL ;
V_152 = ( V_624 << 2 ) + V_301 ;
}
V_622 = ( T_2 * ) F_96 ( V_178 -> V_215 ) ;
return & V_622 [ V_152 ] ;
}
static int F_365 ( struct V_8 * V_9 , T_4 V_625 , T_2 V_620 ,
bool V_626 )
{
bool V_621 ;
T_2 * V_15 , V_299 ;
V_621 = F_366 ( V_9 -> V_46 . V_301 , V_627 ) == V_628 ;
V_15 = F_362 ( V_9 , V_620 , V_621 ) ;
if ( ! V_15 )
return - V_129 ;
V_299 = F_8 ( * V_15 ) ;
V_299 &= ~ V_629 ;
V_299 |= ( V_625 & V_629 ) ;
if ( V_626 )
V_299 |= V_630 ;
else
V_299 &= ~ V_630 ;
F_127 ( * V_15 , V_299 ) ;
return 0 ;
}
static int F_367 ( struct V_8 * V_9 )
{
int V_72 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_620 = F_366 ( V_9 -> V_46 . V_301 , V_631 ) ;
if ( ! V_620 )
return 1 ;
V_72 = F_365 ( V_9 , V_9 -> V_175 , V_620 , true ) ;
if ( V_72 && V_10 -> V_632 ) {
F_365 ( V_9 , 0 , V_10 -> V_632 , false ) ;
V_10 -> V_632 = 0 ;
} else {
V_10 -> V_632 = V_620 ;
}
return V_72 ;
}
static int F_368 ( struct V_8 * V_9 )
{
T_1 * V_633 , * V_634 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_635 = F_366 ( V_9 -> V_46 . V_301 , V_636 ) ;
T_2 V_300 = ( V_635 >> 24 ) & 0xff ;
if ( V_9 -> V_175 == V_300 )
return 0 ;
V_633 = F_122 ( V_9 , V_9 -> V_175 ) ;
V_634 = F_122 ( V_9 , V_300 ) ;
if ( ! V_634 || ! V_633 )
return 1 ;
* V_634 = * V_633 ;
* V_633 = 0ULL ;
F_4 ( V_9 ) -> V_16 = V_634 ;
if ( V_10 -> V_632 )
F_367 ( V_9 ) ;
return 0 ;
}
static int F_369 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_172 * V_178 = & V_9 -> V_177 -> V_46 ;
T_2 V_637 = F_366 ( V_9 -> V_46 . V_301 , V_627 ) ;
T_2 V_638 = ( V_637 >> 28 ) & 0xf ;
if ( V_178 -> V_639 == V_638 )
return 0 ;
F_138 ( F_96 ( V_178 -> V_215 ) ) ;
V_178 -> V_639 = V_638 ;
if ( V_10 -> V_632 )
F_367 ( V_9 ) ;
return 0 ;
}
static int F_370 ( struct V_7 * V_10 )
{
struct V_610 * V_301 = V_10 -> V_9 . V_46 . V_301 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_421 &
V_640 ;
switch ( V_50 ) {
case V_636 :
if ( F_368 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_631 :
if ( F_367 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_627 :
F_369 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
F_357 ( V_301 , V_50 , F_366 ( V_301 , V_50 ) ) ;
return 1 ;
}
static bool F_371 ( T_2 V_50 )
{
bool V_72 = false ;
switch ( V_50 ) {
case V_636 :
case V_641 :
case V_642 :
case V_631 :
case V_627 :
case V_643 :
case V_644 :
case V_613 :
case V_645 :
case V_646 :
case V_647 :
case V_648 :
case V_649 :
case V_650 :
case V_651 :
case V_652 :
V_72 = true ;
break;
default:
break;
}
return V_72 ;
}
static int F_372 ( struct V_7 * V_10 )
{
int V_72 = 0 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_421 &
V_640 ;
T_2 V_653 = V_10 -> V_1 -> V_2 . V_419 &
V_654 ;
bool V_156 = ( V_10 -> V_1 -> V_2 . V_421 >> 32 ) &
V_655 ;
bool V_656 = F_371 ( V_50 ) ;
F_373 ( V_10 -> V_9 . V_175 , V_50 ,
V_656 , V_156 , V_653 ) ;
if ( V_656 ) {
F_361 ( ! V_156 , L_20 ) ;
V_72 = F_370 ( V_10 ) ;
} else {
V_72 = ( F_37 ( & V_10 -> V_9 , 0 ) == V_81 ) ;
}
return V_72 ;
}
static void F_374 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_225 * V_65 = & V_10 -> V_1 -> V_65 ;
F_59 ( L_21 ) ;
F_59 ( L_22 , L_23 , V_2 -> V_26 & 0xffff ) ;
F_59 ( L_22 , L_24 , V_2 -> V_26 >> 16 ) ;
F_59 ( L_22 , L_25 , V_2 -> V_27 & 0xffff ) ;
F_59 ( L_22 , L_26 , V_2 -> V_27 >> 16 ) ;
F_59 ( L_27 , L_28 , V_2 -> V_28 ) ;
F_59 ( L_29 , L_30 , V_2 -> V_29 ) ;
F_59 ( L_31 , L_32 , V_2 -> V_293 ) ;
F_59 ( L_29 , L_33 , V_2 -> V_264 ) ;
F_59 ( L_29 , L_34 , V_2 -> V_265 ) ;
F_59 ( L_29 , L_35 , V_2 -> V_211 ) ;
F_59 ( L_31 , L_36 , V_2 -> V_58 ) ;
F_59 ( L_31 , L_37 , V_2 -> V_410 ) ;
F_59 ( L_27 , L_38 , V_2 -> V_222 ) ;
F_59 ( L_27 , L_39 , V_2 -> V_501 ) ;
F_59 ( L_27 , L_40 , V_2 -> V_73 ) ;
F_59 ( L_27 , L_41 , V_2 -> V_460 ) ;
F_59 ( L_29 , L_42 , V_2 -> V_421 ) ;
F_59 ( L_29 , L_43 , V_2 -> V_419 ) ;
F_59 ( L_27 , L_44 , V_2 -> V_502 ) ;
F_59 ( L_27 , L_45 , V_2 -> V_503 ) ;
F_59 ( L_46 , L_47 , V_2 -> V_288 ) ;
F_59 ( L_29 , L_48 , V_2 -> V_454 ) ;
F_59 ( L_29 , L_49 , V_2 -> V_12 ) ;
F_59 ( L_27 , L_50 , V_2 -> V_97 ) ;
F_59 ( L_27 , L_51 , V_2 -> V_100 ) ;
F_59 ( L_46 , L_52 , V_2 -> V_165 ) ;
F_59 ( L_29 , L_53 , V_2 -> V_78 ) ;
F_59 ( L_29 , L_54 , V_2 -> V_213 ) ;
F_59 ( L_29 , L_55 , V_2 -> V_219 ) ;
F_59 ( L_29 , L_56 , V_2 -> V_220 ) ;
F_59 ( L_57 ) ;
F_59 ( L_58 ,
L_59 ,
V_65 -> V_267 . V_204 , V_65 -> V_267 . V_205 ,
V_65 -> V_267 . V_209 , V_65 -> V_267 . V_95 ) ;
F_59 ( L_58 ,
L_60 ,
V_65 -> V_94 . V_204 , V_65 -> V_94 . V_205 ,
V_65 -> V_94 . V_209 , V_65 -> V_94 . V_95 ) ;
F_59 ( L_58 ,
L_61 ,
V_65 -> V_268 . V_204 , V_65 -> V_268 . V_205 ,
V_65 -> V_268 . V_209 , V_65 -> V_268 . V_95 ) ;
F_59 ( L_58 ,
L_62 ,
V_65 -> V_269 . V_204 , V_65 -> V_269 . V_205 ,
V_65 -> V_269 . V_209 , V_65 -> V_269 . V_95 ) ;
F_59 ( L_58 ,
L_63 ,
V_65 -> V_270 . V_204 , V_65 -> V_270 . V_205 ,
V_65 -> V_270 . V_209 , V_65 -> V_270 . V_95 ) ;
F_59 ( L_58 ,
L_64 ,
V_65 -> V_271 . V_204 , V_65 -> V_271 . V_205 ,
V_65 -> V_271 . V_209 , V_65 -> V_271 . V_95 ) ;
F_59 ( L_58 ,
L_65 ,
V_65 -> V_274 . V_204 , V_65 -> V_274 . V_205 ,
V_65 -> V_274 . V_209 , V_65 -> V_274 . V_95 ) ;
F_59 ( L_58 ,
L_66 ,
V_65 -> V_276 . V_204 , V_65 -> V_276 . V_205 ,
V_65 -> V_276 . V_209 , V_65 -> V_276 . V_95 ) ;
F_59 ( L_58 ,
L_67 ,
V_65 -> V_275 . V_204 , V_65 -> V_275 . V_205 ,
V_65 -> V_275 . V_209 , V_65 -> V_275 . V_95 ) ;
F_59 ( L_58 ,
L_68 ,
V_65 -> V_278 . V_204 , V_65 -> V_278 . V_205 ,
V_65 -> V_278 . V_209 , V_65 -> V_278 . V_95 ) ;
F_59 ( L_69 ,
V_65 -> V_388 , V_65 -> V_61 ) ;
F_59 ( L_70 ,
L_71 , V_65 -> V_393 , L_72 , V_65 -> V_472 ) ;
F_59 ( L_70 ,
L_73 , V_65 -> V_291 , L_74 , V_65 -> V_286 ) ;
F_59 ( L_70 ,
L_75 , V_65 -> V_280 , L_76 , V_65 -> V_415 ) ;
F_59 ( L_70 ,
L_77 , V_65 -> V_91 , L_78 , V_65 -> V_358 ) ;
F_59 ( L_70 ,
L_79 , V_65 -> V_506 , L_80 , V_65 -> V_507 ) ;
F_59 ( L_70 ,
L_81 , V_65 -> V_519 , L_82 , V_65 -> V_520 ) ;
F_59 ( L_70 ,
L_83 , V_65 -> V_521 , L_84 , V_65 -> V_522 ) ;
F_59 ( L_70 ,
L_85 , V_65 -> V_518 ,
L_86 , V_65 -> V_523 ) ;
F_59 ( L_70 ,
L_87 , V_65 -> V_524 ,
L_88 , V_65 -> V_525 ) ;
F_59 ( L_70 ,
L_89 , V_65 -> V_289 , L_90 , V_65 -> V_582 ) ;
F_59 ( L_70 ,
L_91 , V_65 -> V_583 , L_92 , V_65 -> V_584 ) ;
F_59 ( L_70 ,
L_93 , V_65 -> V_585 ,
L_94 , V_65 -> V_586 ) ;
}
static void F_375 ( struct V_8 * V_9 , T_1 * V_657 , T_1 * V_658 )
{
struct V_18 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_657 = V_2 -> V_421 ;
* V_658 = V_2 -> V_419 ;
}
static int F_376 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_426 * V_426 = V_9 -> V_427 ;
T_2 V_460 = V_10 -> V_1 -> V_2 . V_460 ;
F_377 ( V_460 , V_9 , V_505 ) ;
if ( ! F_14 ( V_10 , V_230 ) )
V_9 -> V_46 . V_393 = V_10 -> V_1 -> V_65 . V_393 ;
if ( V_62 )
V_9 -> V_46 . V_291 = V_10 -> V_1 -> V_65 . V_291 ;
if ( F_162 ( V_10 -> V_24 . V_474 ) ) {
F_247 ( V_10 ) ;
V_10 -> V_24 . V_474 = false ;
return 1 ;
}
if ( F_10 ( V_9 ) ) {
int V_470 ;
F_378 ( V_10 -> V_1 -> V_65 . V_91 , V_460 ,
V_10 -> V_1 -> V_2 . V_421 ,
V_10 -> V_1 -> V_2 . V_419 ,
V_10 -> V_1 -> V_2 . V_502 ,
V_10 -> V_1 -> V_2 . V_503 ,
V_505 ) ;
V_470 = F_270 ( V_10 ) ;
if ( V_470 == V_487 )
V_470 = F_271 ( V_10 ) ;
if ( V_470 == V_473 )
return 1 ;
}
F_379 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_460 == V_495 ) {
V_426 -> V_433 = V_659 ;
V_426 -> V_660 . V_661
= V_10 -> V_1 -> V_2 . V_460 ;
F_59 ( L_95 ) ;
F_374 ( V_9 ) ;
return 0 ;
}
if ( F_31 ( V_10 -> V_1 -> V_2 . V_502 ) &&
V_460 != V_471 + V_234 &&
V_460 != V_461 && V_460 != V_662 &&
V_460 != V_477 && V_460 != V_478 )
F_38 ( V_85 L_96
L_97 ,
V_83 , V_10 -> V_1 -> V_2 . V_502 ,
V_460 ) ;
if ( V_460 >= F_380 ( V_663 )
|| ! V_663 [ V_460 ] ) {
F_361 ( 1 , L_98 , V_460 ) ;
F_216 ( V_9 , V_235 ) ;
return 1 ;
}
return V_663 [ V_460 ] ( V_10 ) ;
}
static void F_381 ( struct V_8 * V_9 )
{
int V_147 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_130 , V_147 ) ;
V_121 -> V_136 -> type = 9 ;
F_382 () ;
}
static void F_383 ( struct V_7 * V_10 )
{
int V_147 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_130 , V_147 ) ;
if ( V_10 -> V_131 != V_121 -> V_131 )
F_200 ( V_10 , V_121 ) ;
}
static void F_384 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_97 = V_70 | V_664 ;
V_9 -> V_46 . V_47 |= V_665 ;
F_19 ( V_10 , V_559 ) ;
++ V_9 -> V_352 . V_666 ;
}
static inline void F_385 ( struct V_7 * V_10 , int V_667 )
{
struct V_18 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_501 = V_667 ;
V_2 -> V_222 &= ~ V_668 ;
V_2 -> V_222 |= V_528 |
( ( 0xf ) << V_669 ) ;
F_3 ( V_10 -> V_1 , V_529 ) ;
}
static void F_386 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_76 ( ! ( F_23 ( V_10 ) ) ) ;
F_387 ( V_9 -> V_46 . V_670 . V_86 ) ;
++ V_9 -> V_352 . V_671 ;
V_10 -> V_1 -> V_2 . V_97 = V_9 -> V_46 . V_670 . V_86 |
V_70 | V_71 ;
}
static inline bool F_388 ( struct V_8 * V_9 )
{
return F_10 ( V_9 ) && ( V_9 -> V_46 . V_47 & V_475 ) ;
}
static void F_389 ( struct V_8 * V_9 , int V_672 , int V_673 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_388 ( V_9 ) ||
F_117 ( V_9 ) )
return;
F_13 ( V_10 , V_233 ) ;
if ( V_673 == - 1 )
return;
if ( V_672 >= V_673 )
F_12 ( V_10 , V_233 ) ;
}
static void F_390 ( struct V_8 * V_9 , bool V_674 )
{
return;
}
static bool F_391 ( void )
{
return V_198 ;
}
static void F_392 ( struct V_8 * V_9 , int V_675 )
{
}
static void F_393 ( struct V_8 * V_9 , int V_676 )
{
}
static void F_394 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( ! V_198 )
return;
V_1 -> V_2 . V_222 &= ~ V_223 ;
F_3 ( V_1 , V_529 ) ;
}
static void F_395 ( struct V_8 * V_9 , T_1 * V_677 )
{
return;
}
static void F_396 ( struct V_8 * V_9 )
{
return;
}
static void F_397 ( struct V_8 * V_9 , int V_678 )
{
F_398 ( V_678 , V_9 -> V_46 . V_301 ) ;
F_399 () ;
if ( F_7 ( V_9 ) )
F_53 ( V_679 ,
F_146 ( V_9 -> V_147 ) ) ;
else
F_93 ( V_9 ) ;
}
static void F_400 ( struct V_7 * V_10 , struct V_680 * V_681 )
{
unsigned long V_171 ;
struct V_313 * V_682 ;
F_89 ( & V_10 -> V_315 , V_171 ) ;
F_143 (cur, &svm->ir_list, node) {
if ( V_682 -> V_11 != V_681 -> V_683 )
continue;
F_401 ( & V_682 -> V_684 ) ;
F_69 ( V_682 ) ;
break;
}
F_92 ( & V_10 -> V_315 , V_171 ) ;
}
static int F_402 ( struct V_7 * V_10 , struct V_680 * V_681 )
{
int V_72 = 0 ;
unsigned long V_171 ;
struct V_313 * V_314 ;
if ( V_681 -> V_683 && ( V_681 -> V_685 != 0 ) ) {
struct V_177 * V_177 = V_10 -> V_9 . V_177 ;
T_2 V_175 = F_87 ( V_681 -> V_685 ) ;
struct V_8 * V_686 = F_91 ( V_177 , V_175 ) ;
struct V_7 * V_687 ;
if ( ! V_686 ) {
V_72 = - V_129 ;
goto V_317;
}
V_687 = F_4 ( V_686 ) ;
F_400 ( V_687 , V_681 ) ;
}
V_314 = F_71 ( sizeof( struct V_313 ) , V_149 ) ;
if ( ! V_314 ) {
V_72 = - V_150 ;
goto V_317;
}
V_314 -> V_11 = V_681 -> V_683 ;
F_89 ( & V_10 -> V_315 , V_171 ) ;
F_403 ( & V_314 -> V_684 , & V_10 -> V_316 ) ;
F_92 ( & V_10 -> V_315 , V_171 ) ;
V_317:
return V_72 ;
}
static int
F_404 ( struct V_177 * V_177 , struct V_688 * V_689 ,
struct V_690 * V_691 , struct V_7 * * V_10 )
{
struct V_692 V_667 ;
struct V_8 * V_9 = NULL ;
F_405 ( V_177 , V_689 , & V_667 ) ;
if ( ! F_406 ( V_177 , & V_667 , & V_9 ) ) {
F_88 ( L_99 ,
V_83 , V_667 . V_653 ) ;
return - 1 ;
}
F_88 ( L_100 , V_83 ,
V_667 . V_653 ) ;
* V_10 = F_4 ( V_9 ) ;
V_691 -> V_693 = F_115 ( ( * V_10 ) -> V_213 ) ;
V_691 -> V_653 = V_667 . V_653 ;
return 0 ;
}
static int F_407 ( struct V_177 * V_177 , unsigned int V_694 ,
T_7 V_695 , bool V_674 )
{
struct V_688 * V_689 ;
struct V_696 * V_697 ;
int V_698 , V_72 = - V_129 ;
if ( ! F_141 ( V_177 ) ||
! F_408 ( V_699 ) )
return 0 ;
F_88 ( L_101 ,
V_83 , V_694 , V_695 , V_674 ) ;
V_698 = F_409 ( & V_177 -> V_700 ) ;
V_697 = F_410 ( V_177 -> V_701 , & V_177 -> V_700 ) ;
F_75 ( V_695 >= V_697 -> V_702 ) ;
F_411 (e, &irq_rt->map[guest_irq], link) {
struct V_690 V_691 ;
struct V_7 * V_10 = NULL ;
if ( V_689 -> type != V_703 )
continue;
if ( ! F_404 ( V_177 , V_689 , & V_691 , & V_10 ) && V_674 &&
F_117 ( & V_10 -> V_9 ) ) {
struct V_680 V_681 ;
V_681 . V_95 = F_115 ( V_10 -> V_213 ) & V_218 ;
V_681 . V_170 = F_412 ( V_177 -> V_46 . V_179 ,
V_10 -> V_9 . V_175 ) ;
V_681 . F_10 = true ;
V_681 . V_690 = & V_691 ;
V_72 = F_413 ( V_694 , & V_681 ) ;
if ( ! V_72 && V_681 . F_10 )
F_402 ( V_10 , & V_681 ) ;
} else {
struct V_680 V_681 ;
V_681 . F_10 = false ;
V_72 = F_413 ( V_694 , & V_681 ) ;
if ( ! V_72 && V_681 . V_685 ) {
int V_300 = F_87 ( V_681 . V_685 ) ;
struct V_8 * V_9 ;
V_9 = F_91 ( V_177 , V_300 ) ;
if ( V_9 )
F_400 ( F_4 ( V_9 ) , & V_681 ) ;
}
}
if ( ! V_72 && V_10 ) {
F_414 ( V_10 -> V_9 . V_175 ,
V_694 , V_689 -> V_704 ,
V_691 . V_653 ,
V_691 . V_693 , V_674 ) ;
}
if ( V_72 < 0 ) {
F_59 ( L_102 , V_83 ) ;
goto V_317;
}
}
V_72 = 0 ;
V_317:
F_415 ( & V_177 -> V_700 , V_698 ) ;
return V_72 ;
}
static int F_416 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
V_72 = ! ( V_1 -> V_2 . V_73 & V_74 ) &&
! ( V_10 -> V_9 . V_46 . V_47 & V_665 ) ;
V_72 = V_72 && F_23 ( V_10 ) && F_258 ( V_10 ) ;
return V_72 ;
}
static bool F_417 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_46 . V_47 & V_665 ) ;
}
static void F_418 ( struct V_8 * V_9 , bool V_705 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_705 ) {
V_10 -> V_9 . V_46 . V_47 |= V_665 ;
F_19 ( V_10 , V_559 ) ;
} else {
V_10 -> V_9 . V_46 . V_47 &= ~ V_665 ;
F_20 ( V_10 , V_559 ) ;
}
}
static int F_419 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
if ( ! F_23 ( V_10 ) ||
( V_1 -> V_2 . V_73 & V_74 ) )
return 0 ;
V_72 = ! ! ( F_276 ( V_9 ) & V_515 ) ;
if ( F_10 ( V_9 ) )
return V_72 && ! ( V_10 -> V_9 . V_46 . V_47 & V_475 ) ;
return V_72 ;
}
static void F_420 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_117 ( V_9 ) )
return;
if ( F_23 ( V_10 ) && F_256 ( V_10 ) ) {
F_179 ( V_10 ) ;
F_385 ( V_10 , 0x0 ) ;
}
}
static void F_421 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_46 . V_47 & ( V_665 | V_560 ) )
== V_665 )
return;
V_10 -> V_430 = true ;
V_10 -> V_1 -> V_65 . V_358 |= ( V_431 | V_432 ) ;
}
static int F_422 ( struct V_177 * V_177 , unsigned int V_57 )
{
return 0 ;
}
static void F_197 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_36 ( V_706 ) )
V_10 -> V_1 -> V_2 . V_410 = V_707 ;
else
V_10 -> V_131 -- ;
}
static void F_423 ( struct V_8 * V_9 )
{
}
static inline void F_424 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_388 ( V_9 ) )
return;
if ( ! F_14 ( V_10 , V_233 ) ) {
int V_708 = V_10 -> V_1 -> V_2 . V_222 & V_709 ;
F_319 ( V_9 , V_708 ) ;
}
}
static inline void F_425 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_708 ;
if ( F_388 ( V_9 ) ||
F_117 ( V_9 ) )
return;
V_708 = F_322 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_222 &= ~ V_709 ;
V_10 -> V_1 -> V_2 . V_222 |= V_708 & V_709 ;
}
static void F_379 ( struct V_7 * V_10 )
{
T_4 V_653 ;
int type ;
T_2 V_710 = V_10 -> V_1 -> V_2 . V_502 ;
unsigned V_96 = V_10 -> V_96 ;
V_10 -> V_96 = 0 ;
if ( ( V_10 -> V_9 . V_46 . V_47 & V_560 )
&& F_39 ( & V_10 -> V_9 ) != V_10 -> V_561 ) {
V_10 -> V_9 . V_46 . V_47 &= ~ ( V_665 | V_560 ) ;
F_227 ( V_527 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_46 . V_546 = false ;
F_277 ( & V_10 -> V_9 ) ;
F_278 ( & V_10 -> V_9 ) ;
if ( ! ( V_710 & V_538 ) )
return;
F_227 ( V_527 , & V_10 -> V_9 ) ;
V_653 = V_710 & V_711 ;
type = V_710 & V_534 ;
switch ( type ) {
case V_545 :
V_10 -> V_9 . V_46 . V_546 = true ;
break;
case V_547 :
if ( F_426 ( V_653 ) ) {
if ( V_653 == V_90 && V_96 &&
F_427 ( & V_10 -> V_9 , V_10 -> V_93 ) )
F_40 ( & V_10 -> V_9 ,
F_39 ( & V_10 -> V_9 ) -
V_96 ) ;
break;
}
if ( V_710 & V_712 ) {
T_2 V_103 = V_10 -> V_1 -> V_2 . V_503 ;
F_428 ( & V_10 -> V_9 , V_653 , V_103 ) ;
} else
F_429 ( & V_10 -> V_9 , V_653 ) ;
break;
case V_549 :
F_430 ( & V_10 -> V_9 , V_653 , false ) ;
break;
default:
break;
}
}
static void F_431 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_502 = V_2 -> V_97 ;
V_2 -> V_503 = V_2 -> V_100 ;
V_2 -> V_97 = 0 ;
F_379 ( V_10 ) ;
}
static void F_432 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_507 = V_9 -> V_46 . V_281 [ V_511 ] ;
V_10 -> V_1 -> V_65 . V_506 = V_9 -> V_46 . V_281 [ V_512 ] ;
V_10 -> V_1 -> V_65 . V_91 = V_9 -> V_46 . V_281 [ V_282 ] ;
if ( F_162 ( V_10 -> V_24 . V_474 ) )
return;
F_383 ( V_10 ) ;
F_425 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_472 = V_9 -> V_46 . V_472 ;
F_25 () ;
F_213 () ;
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
F_53 ( V_340 , V_10 -> V_341 . V_342 ) ;
#else
F_168 ( V_270 , V_10 -> V_341 . V_270 ) ;
#ifndef F_170
F_168 ( V_271 , V_10 -> V_341 . V_271 ) ;
#endif
#endif
F_381 ( V_9 ) ;
F_211 () ;
V_9 -> V_46 . V_472 = V_10 -> V_1 -> V_65 . V_472 ;
V_9 -> V_46 . V_281 [ V_511 ] = V_10 -> V_1 -> V_65 . V_507 ;
V_9 -> V_46 . V_281 [ V_512 ] = V_10 -> V_1 -> V_65 . V_506 ;
V_9 -> V_46 . V_281 [ V_282 ] = V_10 -> V_1 -> V_65 . V_91 ;
if ( F_162 ( V_10 -> V_1 -> V_2 . V_460 == V_478 ) )
F_433 ( & V_10 -> V_9 ) ;
F_26 () ;
if ( F_162 ( V_10 -> V_1 -> V_2 . V_460 == V_478 ) )
F_434 ( & V_10 -> V_9 ) ;
F_424 ( V_9 ) ;
V_10 -> V_78 = 0 ;
V_10 -> V_1 -> V_2 . V_410 = V_713 ;
if ( V_10 -> V_1 -> V_2 . V_460 == V_471 + V_234 )
V_10 -> V_420 = F_435 () ;
if ( V_62 ) {
V_9 -> V_46 . V_714 &= ~ ( 1 << V_361 ) ;
V_9 -> V_46 . V_715 &= ~ ( 1 << V_361 ) ;
}
if ( F_162 ( V_10 -> V_1 -> V_2 . V_460 ==
V_471 + V_236 ) )
F_226 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_436 ( struct V_8 * V_9 , unsigned long V_456 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_291 = V_456 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_197 ( V_9 ) ;
}
static void F_437 ( struct V_8 * V_9 , unsigned long V_456 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_454 = V_456 ;
F_3 ( V_10 -> V_1 , V_457 ) ;
V_10 -> V_1 -> V_65 . V_291 = F_178 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_197 ( V_9 ) ;
}
static int F_438 ( void )
{
T_1 V_716 ;
F_58 ( V_588 , V_716 ) ;
if ( V_716 & ( 1 << V_717 ) )
return 1 ;
return 0 ;
}
static void
F_439 ( struct V_8 * V_9 , unsigned char * V_718 )
{
V_718 [ 0 ] = 0x0f ;
V_718 [ 1 ] = 0x01 ;
V_718 [ 2 ] = 0xd9 ;
}
static void F_440 ( void * V_719 )
{
* ( int * ) V_719 = 0 ;
}
static bool F_441 ( void )
{
return false ;
}
static bool F_442 ( void )
{
return true ;
}
static T_1 F_443 ( struct V_8 * V_9 , T_11 V_720 , bool V_721 )
{
return 0 ;
}
static void F_444 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_722 * V_15 ;
V_10 -> V_508 = ! ! F_445 ( & V_10 -> V_9 ) ;
if ( ! F_117 ( V_9 ) )
return;
V_15 = F_446 ( V_9 , 1 , 0 ) ;
if ( V_15 )
V_15 -> V_594 &= ~ V_6 ( V_723 ) ;
}
static void F_447 ( T_2 V_724 , struct V_722 * V_15 )
{
switch ( V_724 ) {
case 0x1 :
if ( V_198 )
V_15 -> V_594 &= ~ V_6 ( V_723 ) ;
break;
case 0x80000001 :
if ( V_24 )
V_15 -> V_594 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_15 -> V_324 = 1 ;
V_15 -> V_725 = 8 ;
V_15 -> V_594 = 0 ;
V_15 -> V_726 = 0 ;
if ( F_97 ( V_79 ) )
V_15 -> V_726 |= V_727 ;
if ( V_62 )
V_15 -> V_726 |= V_728 ;
break;
}
}
static int F_448 ( void )
{
return V_729 ;
}
static bool F_449 ( void )
{
return F_97 ( V_349 ) ;
}
static bool F_450 ( void )
{
return false ;
}
static bool F_451 ( void )
{
return false ;
}
static bool F_452 ( void )
{
return false ;
}
static bool F_453 ( void )
{
return true ;
}
static void F_454 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_17 ( V_10 , V_440 ) ;
F_192 ( V_10 ) ;
}
static int F_455 ( struct V_8 * V_9 ,
struct V_730 * V_68 ,
enum V_731 V_732 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_470 , V_72 = V_733 ;
struct V_734 V_735 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_68 -> V_29 >= F_380 ( V_736 ) )
goto V_317;
V_735 = V_736 [ V_68 -> V_29 ] ;
if ( V_732 != V_735 . V_732 )
goto V_317;
switch ( V_735 . V_460 ) {
case V_490 :
if ( V_68 -> V_29 == V_737 )
V_735 . V_460 += V_68 -> V_738 ;
break;
case V_567 : {
unsigned long V_393 , V_104 ;
T_1 V_29 ;
if ( V_68 -> V_29 == V_739 )
V_735 . V_460 += V_68 -> V_738 ;
if ( V_735 . V_460 != V_567 ||
V_68 -> V_29 == V_740 )
break;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! ( V_29 & ( 1ULL << V_242 ) ) )
break;
V_393 = V_9 -> V_46 . V_393 & ~ V_395 ;
V_104 = V_68 -> V_741 & ~ V_395 ;
if ( V_68 -> V_29 == V_742 ) {
V_393 &= 0xfUL ;
V_104 &= 0xfUL ;
if ( V_393 & V_510 )
V_104 |= V_510 ;
}
if ( V_393 ^ V_104 )
V_735 . V_460 = V_563 ;
break;
}
case V_492 :
case V_743 :
V_735 . V_460 += V_68 -> V_738 ;
break;
case V_488 :
if ( V_68 -> V_29 == V_744 )
V_1 -> V_2 . V_421 = 1 ;
else
V_1 -> V_2 . V_421 = 0 ;
break;
case V_745 :
if ( V_68 -> V_746 != V_747 )
goto V_317;
case V_489 : {
T_1 V_748 ;
T_2 V_749 ;
if ( V_68 -> V_29 == V_750 ||
V_68 -> V_29 == V_751 ) {
V_748 = ( ( V_68 -> V_741 & 0xffff ) << 16 ) |
V_450 ;
V_749 = V_68 -> V_752 ;
} else {
V_748 = ( V_68 -> V_753 & 0xffff ) << 16 ;
V_749 = V_68 -> V_754 ;
}
if ( V_68 -> V_29 == V_755 ||
V_68 -> V_29 == V_751 )
V_748 |= V_449 ;
if ( V_68 -> V_746 )
V_748 |= V_756 ;
V_749 = F_456 ( V_749 , 4u ) ;
V_748 |= V_749 << V_452 ;
V_748 |= ( T_2 ) V_68 -> V_757 << ( V_758 - 1 ) ;
V_1 -> V_2 . V_421 = V_748 ;
V_1 -> V_2 . V_419 = V_68 -> V_78 ;
break;
}
default:
break;
}
if ( F_36 ( V_79 ) )
V_1 -> V_2 . V_78 = V_68 -> V_78 ;
V_1 -> V_2 . V_460 = V_735 . V_460 ;
V_470 = F_271 ( V_10 ) ;
V_72 = ( V_470 == V_473 ) ? V_759
: V_733 ;
V_317:
return V_72 ;
}
static void F_457 ( struct V_8 * V_9 )
{
F_213 () ;
asm("nop");
F_211 () ;
}
static void F_458 ( struct V_8 * V_9 , int V_147 )
{
}
static inline void F_459 ( struct V_8 * V_9 )
{
if ( F_368 ( V_9 ) != 0 )
return;
if ( F_369 ( V_9 ) != 0 )
return;
F_367 ( V_9 ) ;
}
static int T_5 F_460 ( void )
{
return F_461 ( & V_760 , sizeof( struct V_7 ) ,
F_462 ( struct V_7 ) , V_761 ) ;
}
static void T_6 F_463 ( void )
{
F_464 () ;
}
