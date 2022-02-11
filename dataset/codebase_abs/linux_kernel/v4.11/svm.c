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
F_104 ( & F_85 ) ;
}
}
return 0 ;
V_103:
F_105 ( V_183 , V_185 ) ;
V_186 = 0 ;
return V_148 ;
}
static T_6 void F_106 ( void )
{
int V_147 ;
F_99 (cpu)
F_67 ( V_147 ) ;
F_105 ( F_107 ( V_186 >> V_141 ) , V_185 ) ;
V_186 = 0 ;
}
static void F_108 ( struct V_201 * V_202 )
{
V_202 -> V_203 = 0 ;
V_202 -> V_204 = V_205 | V_206 |
V_207 ;
V_202 -> V_208 = 0xffff ;
V_202 -> V_95 = 0 ;
}
static void F_109 ( struct V_201 * V_202 , T_7 type )
{
V_202 -> V_203 = 0 ;
V_202 -> V_204 = V_205 | type ;
V_202 -> V_208 = 0xffff ;
V_202 -> V_95 = 0 ;
}
static void F_110 ( struct V_8 * V_9 , T_1 V_50 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_209 = 0 ;
if ( F_10 ( V_9 ) ) {
V_209 = V_10 -> V_1 -> V_2 . V_210 -
V_10 -> V_24 . V_25 -> V_2 . V_210 ;
V_10 -> V_24 . V_25 -> V_2 . V_210 = V_50 ;
} else
F_111 ( V_9 -> V_175 ,
V_10 -> V_1 -> V_2 . V_210 ,
V_50 ) ;
V_10 -> V_1 -> V_2 . V_210 = V_50 + V_209 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_112 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_172 * V_178 = & V_10 -> V_9 . V_177 -> V_46 ;
T_8 V_211 = F_113 ( V_10 -> V_212 ) ;
T_8 V_213 = F_113 ( V_178 -> V_214 ) ;
T_8 V_215 = F_113 ( V_178 -> V_216 ) ;
V_1 -> V_2 . V_212 = V_211 & V_217 ;
V_1 -> V_2 . V_218 = V_213 & V_217 ;
V_1 -> V_2 . V_219 = V_215 & V_217 ;
V_1 -> V_2 . V_219 |= V_220 ;
V_1 -> V_2 . V_221 |= V_222 ;
V_10 -> V_9 . V_46 . V_223 = true ;
}
static void F_114 ( struct V_7 * V_10 )
{
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_224 * V_65 = & V_10 -> V_1 -> V_65 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
F_12 ( V_10 , V_225 ) ;
F_12 ( V_10 , V_226 ) ;
F_12 ( V_10 , V_227 ) ;
F_12 ( V_10 , V_228 ) ;
F_12 ( V_10 , V_229 ) ;
F_12 ( V_10 , V_230 ) ;
if ( ! F_115 ( & V_10 -> V_9 ) )
F_12 ( V_10 , V_231 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_232 ) ;
F_17 ( V_10 , V_233 ) ;
F_17 ( V_10 , V_234 ) ;
F_17 ( V_10 , V_235 ) ;
F_17 ( V_10 , V_236 ) ;
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
F_19 ( V_10 , V_256 ) ;
F_19 ( V_10 , V_257 ) ;
F_19 ( V_10 , V_258 ) ;
F_19 ( V_10 , V_259 ) ;
F_19 ( V_10 , V_260 ) ;
F_19 ( V_10 , V_261 ) ;
V_2 -> V_262 = V_186 ;
V_2 -> V_263 = F_116 ( V_10 -> V_154 ) ;
V_2 -> V_221 = V_264 ;
F_108 ( & V_65 -> V_265 ) ;
F_108 ( & V_65 -> V_266 ) ;
F_108 ( & V_65 -> V_267 ) ;
F_108 ( & V_65 -> V_268 ) ;
F_108 ( & V_65 -> V_269 ) ;
V_65 -> V_94 . V_203 = 0xf000 ;
V_65 -> V_94 . V_95 = 0xffff0000 ;
V_65 -> V_94 . V_204 = V_270 | V_205 |
V_206 | V_271 ;
V_65 -> V_94 . V_208 = 0xffff ;
V_65 -> V_272 . V_208 = 0xffff ;
V_65 -> V_273 . V_208 = 0xffff ;
F_109 ( & V_65 -> V_274 , V_275 ) ;
F_109 ( & V_65 -> V_276 , V_277 ) ;
F_30 ( & V_10 -> V_9 , 0 ) ;
V_65 -> V_278 = 0xffff0ff0 ;
F_117 ( & V_10 -> V_9 , 2 ) ;
V_65 -> V_91 = 0x0000fff0 ;
V_10 -> V_9 . V_46 . V_279 [ V_280 ] = V_65 -> V_91 ;
F_118 ( & V_10 -> V_9 , V_281 | V_282 | V_283 ) ;
F_119 ( & V_10 -> V_9 ) ;
V_65 -> V_284 = V_285 ;
if ( V_62 ) {
V_2 -> V_286 = 1 ;
F_20 ( V_10 , V_245 ) ;
F_18 ( V_10 , V_232 ) ;
F_13 ( V_10 , V_226 ) ;
F_13 ( V_10 , V_229 ) ;
V_65 -> V_287 = V_10 -> V_9 . V_46 . V_288 ;
V_65 -> V_289 = 0 ;
V_65 -> V_284 = 0 ;
}
V_10 -> V_131 = 0 ;
V_10 -> V_24 . V_1 = 0 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
if ( F_97 ( V_290 ) ) {
V_2 -> V_291 = 3000 ;
F_19 ( V_10 , V_292 ) ;
}
if ( V_198 )
F_112 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
F_21 ( V_10 ) ;
}
static T_1 * F_120 ( struct V_8 * V_9 , int V_152 )
{
T_1 * V_293 ;
struct V_172 * V_178 = & V_9 -> V_177 -> V_46 ;
if ( V_152 >= V_220 )
return NULL ;
V_293 = F_96 ( V_178 -> V_216 ) ;
return & V_293 [ V_152 ] ;
}
static int F_121 ( struct V_8 * V_9 )
{
struct V_177 * V_177 = V_9 -> V_177 ;
int V_72 ;
if ( V_177 -> V_46 . V_294 )
return 0 ;
V_72 = F_122 ( V_177 ,
V_295 ,
V_296 ,
V_160 ) ;
if ( V_72 )
return V_72 ;
V_177 -> V_46 . V_294 = true ;
return 0 ;
}
static int F_123 ( struct V_8 * V_9 )
{
int V_72 ;
T_1 * V_15 , V_297 ;
int V_298 = V_9 -> V_175 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_72 = F_121 ( V_9 ) ;
if ( V_72 )
return V_72 ;
if ( V_298 >= V_220 )
return - V_129 ;
if ( ! V_10 -> V_9 . V_46 . V_299 -> V_279 )
return - V_129 ;
V_10 -> V_212 = F_124 ( V_10 -> V_9 . V_46 . V_299 -> V_279 ) ;
V_15 = F_120 ( V_9 , V_298 ) ;
if ( ! V_15 )
return - V_129 ;
V_297 = F_8 ( * V_15 ) ;
V_297 = ( F_113 ( V_10 -> V_212 ) &
V_300 ) |
V_301 ;
F_125 ( * V_15 , V_297 ) ;
V_10 -> V_16 = V_15 ;
return 0 ;
}
static inline int F_126 ( void )
{
int V_298 ;
F_127 ( & V_302 ) ;
V_298 = F_128 ( V_303 , V_304 , 1 ) ;
if ( V_298 <= V_305 )
F_129 ( V_298 , V_303 ) ;
else
V_298 = - V_306 ;
F_130 ( & V_302 ) ;
return V_298 ;
}
static inline int F_131 ( int V_298 )
{
if ( V_298 <= 0 || V_298 > V_305 )
return - V_129 ;
F_127 ( & V_302 ) ;
F_132 ( V_298 , V_303 ) ;
F_130 ( & V_302 ) ;
return 0 ;
}
static void F_133 ( struct V_177 * V_177 )
{
unsigned long V_171 ;
struct V_172 * V_178 = & V_177 -> V_46 ;
if ( ! V_198 )
return;
F_131 ( V_178 -> V_179 ) ;
if ( V_178 -> V_214 )
F_68 ( V_178 -> V_214 ) ;
if ( V_178 -> V_216 )
F_68 ( V_178 -> V_216 ) ;
F_89 ( & V_176 , V_171 ) ;
F_134 ( & V_178 -> V_307 ) ;
F_92 ( & V_176 , V_171 ) ;
}
static int F_135 ( struct V_177 * V_177 )
{
unsigned long V_171 ;
int V_174 , V_103 = - V_150 ;
struct V_172 * V_178 = & V_177 -> V_46 ;
struct V_182 * V_308 ;
struct V_182 * V_309 ;
if ( ! V_198 )
return 0 ;
V_174 = F_126 () ;
if ( V_174 < 0 )
return V_174 ;
V_178 -> V_179 = ( T_2 ) V_174 ;
V_308 = F_72 ( V_149 ) ;
if ( ! V_308 )
goto V_310;
V_178 -> V_216 = V_308 ;
F_136 ( F_96 ( V_308 ) ) ;
V_309 = F_72 ( V_149 ) ;
if ( ! V_309 )
goto V_310;
V_178 -> V_214 = V_309 ;
F_136 ( F_96 ( V_309 ) ) ;
F_89 ( & V_176 , V_171 ) ;
F_137 ( V_311 , & V_178 -> V_307 , V_178 -> V_179 ) ;
F_92 ( & V_176 , V_171 ) ;
return 0 ;
V_310:
F_133 ( V_177 ) ;
return V_103 ;
}
static inline int
F_138 ( struct V_8 * V_9 , int V_147 , bool V_148 )
{
int V_72 = 0 ;
unsigned long V_171 ;
struct V_312 * V_313 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_139 ( V_9 -> V_177 ) )
return 0 ;
F_89 ( & V_10 -> V_314 , V_171 ) ;
if ( F_140 ( & V_10 -> V_315 ) )
goto V_316;
F_141 (ir, &svm->ir_list, node) {
V_72 = F_142 ( V_147 , V_148 , V_313 -> V_11 ) ;
if ( V_72 )
break;
}
V_316:
F_92 ( & V_10 -> V_314 , V_171 ) ;
return V_72 ;
}
static void F_143 ( struct V_8 * V_9 , int V_147 )
{
T_1 V_15 ;
int V_317 = F_144 ( V_147 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_115 ( V_9 ) )
return;
if ( F_75 ( V_317 >= V_220 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_75 ( V_15 & V_17 ) ;
V_15 &= ~ V_318 ;
V_15 |= ( V_317 & V_318 ) ;
V_15 &= ~ V_17 ;
if ( V_10 -> V_319 )
V_15 |= V_17 ;
F_125 ( * ( V_10 -> V_16 ) , V_15 ) ;
F_138 ( V_9 , V_317 ,
V_10 -> V_319 ) ;
}
static void F_145 ( struct V_8 * V_9 )
{
T_1 V_15 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_115 ( V_9 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
if ( V_15 & V_17 )
F_138 ( V_9 , - 1 , 0 ) ;
V_15 &= ~ V_17 ;
F_125 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_146 ( struct V_8 * V_9 , bool V_320 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_319 = V_320 ;
if ( V_320 )
F_143 ( V_9 , V_9 -> V_147 ) ;
else
F_145 ( V_9 ) ;
}
static void F_147 ( struct V_8 * V_9 , bool V_321 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_322 ;
T_2 V_323 = 1 ;
if ( ! V_321 ) {
V_10 -> V_9 . V_46 . V_324 = V_296 |
V_325 ;
if ( F_148 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_46 . V_324 |= V_326 ;
}
F_114 ( V_10 ) ;
F_149 ( V_9 , & V_323 , & V_322 , & V_322 , & V_322 ) ;
F_150 ( V_9 , V_327 , V_323 ) ;
if ( F_115 ( V_9 ) && ! V_321 )
F_6 ( V_10 , V_296 ) ;
}
static struct V_8 * F_151 ( struct V_177 * V_177 , unsigned int V_298 )
{
struct V_7 * V_10 ;
struct V_182 * V_182 ;
struct V_182 * V_328 ;
struct V_182 * V_329 ;
struct V_182 * V_330 ;
int V_103 ;
V_10 = F_152 ( V_331 , V_149 ) ;
if ( ! V_10 ) {
V_103 = - V_150 ;
goto V_316;
}
V_103 = F_153 ( & V_10 -> V_9 , V_177 , V_298 ) ;
if ( V_103 )
goto V_332;
V_103 = - V_150 ;
V_182 = F_72 ( V_149 ) ;
if ( ! V_182 )
goto V_333;
V_328 = F_95 ( V_149 , V_161 ) ;
if ( ! V_328 )
goto V_334;
V_330 = F_95 ( V_149 , V_161 ) ;
if ( ! V_330 )
goto V_335;
V_329 = F_72 ( V_149 ) ;
if ( ! V_329 )
goto V_336;
if ( V_198 ) {
V_103 = F_123 ( & V_10 -> V_9 ) ;
if ( V_103 )
goto V_337;
F_154 ( & V_10 -> V_315 ) ;
F_155 ( & V_10 -> V_314 ) ;
}
V_10 -> V_319 = true ;
V_10 -> V_24 . V_25 = F_96 ( V_329 ) ;
V_10 -> V_154 = F_96 ( V_328 ) ;
F_79 ( V_10 -> V_154 ) ;
V_10 -> V_24 . V_154 = F_96 ( V_330 ) ;
F_79 ( V_10 -> V_24 . V_154 ) ;
V_10 -> V_1 = F_96 ( V_182 ) ;
F_136 ( V_10 -> V_1 ) ;
V_10 -> V_338 = F_63 ( V_182 ) << V_141 ;
V_10 -> V_131 = 0 ;
F_114 ( V_10 ) ;
F_49 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_337:
F_68 ( V_329 ) ;
V_336:
F_105 ( V_330 , V_161 ) ;
V_335:
F_105 ( V_328 , V_161 ) ;
V_334:
F_68 ( V_182 ) ;
V_333:
F_156 ( & V_10 -> V_9 ) ;
V_332:
F_157 ( V_331 , V_10 ) ;
V_316:
return F_158 ( V_103 ) ;
}
static void F_159 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_68 ( F_107 ( V_10 -> V_338 >> V_141 ) ) ;
F_105 ( F_124 ( V_10 -> V_154 ) , V_161 ) ;
F_68 ( F_124 ( V_10 -> V_24 . V_25 ) ) ;
F_105 ( F_124 ( V_10 -> V_24 . V_154 ) , V_161 ) ;
F_156 ( V_9 ) ;
F_157 ( V_331 , V_10 ) ;
}
static void F_160 ( struct V_8 * V_9 , int V_147 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
if ( F_161 ( V_147 != V_9 -> V_147 ) ) {
V_10 -> V_131 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_29
F_58 ( V_339 , F_4 ( V_9 ) -> V_340 . V_341 ) ;
#endif
F_162 ( V_268 , V_10 -> V_340 . V_268 ) ;
F_162 ( V_269 , V_10 -> V_340 . V_269 ) ;
V_10 -> V_340 . V_342 = F_163 () ;
for ( V_51 = 0 ; V_51 < V_343 ; V_51 ++ )
F_58 ( V_344 [ V_51 ] , V_10 -> V_345 [ V_51 ] ) ;
if ( F_36 ( V_117 ) ) {
T_1 V_346 = V_9 -> V_46 . V_347 ;
if ( V_346 != F_164 ( V_142 ) ) {
F_64 ( V_142 , V_346 ) ;
F_53 ( V_118 , V_346 ) ;
}
}
if ( F_36 ( V_348 ) )
F_53 ( V_349 , V_10 -> V_350 ) ;
F_143 ( V_9 , V_147 ) ;
}
static void F_165 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
F_145 ( V_9 ) ;
++ V_9 -> V_351 . V_352 ;
F_166 ( V_10 -> V_340 . V_342 ) ;
#ifdef F_29
F_167 ( V_268 , V_10 -> V_340 . V_268 ) ;
F_53 ( V_353 , V_354 -> V_355 . V_356 ) ;
F_168 ( V_10 -> V_340 . V_269 ) ;
#else
#ifdef F_169
F_167 ( V_269 , V_10 -> V_340 . V_269 ) ;
#endif
#endif
for ( V_51 = 0 ; V_51 < V_343 ; V_51 ++ )
F_53 ( V_344 [ V_51 ] , V_10 -> V_345 [ V_51 ] ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
F_146 ( V_9 , false ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_146 ( V_9 , true ) ;
}
static unsigned long F_172 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_357 ;
}
static void F_173 ( struct V_8 * V_9 , unsigned long V_357 )
{
F_4 ( V_9 ) -> V_1 -> V_65 . V_357 = V_357 ;
}
static T_2 F_174 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_175 ( struct V_8 * V_9 , enum V_358 V_359 )
{
switch ( V_359 ) {
case V_360 :
F_76 ( ! V_62 ) ;
F_176 ( V_9 , V_9 -> V_46 . V_361 , F_177 ( V_9 ) ) ;
break;
default:
F_81 () ;
}
}
static void F_178 ( struct V_7 * V_10 )
{
F_19 ( V_10 , V_362 ) ;
}
static void F_179 ( struct V_7 * V_10 )
{
F_20 ( V_10 , V_362 ) ;
}
static struct V_201 * F_180 ( struct V_8 * V_9 , int V_202 )
{
struct V_224 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
switch ( V_202 ) {
case V_363 : return & V_65 -> V_94 ;
case V_364 : return & V_65 -> V_267 ;
case V_365 : return & V_65 -> V_265 ;
case V_366 : return & V_65 -> V_268 ;
case V_367 : return & V_65 -> V_269 ;
case V_368 : return & V_65 -> V_266 ;
case V_369 : return & V_65 -> V_276 ;
case V_370 : return & V_65 -> V_274 ;
}
F_81 () ;
return NULL ;
}
static T_1 F_181 ( struct V_8 * V_9 , int V_202 )
{
struct V_201 * V_371 = F_180 ( V_9 , V_202 ) ;
return V_371 -> V_95 ;
}
static void F_182 ( struct V_8 * V_9 ,
struct V_372 * V_373 , int V_202 )
{
struct V_201 * V_371 = F_180 ( V_9 , V_202 ) ;
V_373 -> V_95 = V_371 -> V_95 ;
V_373 -> V_208 = V_371 -> V_208 ;
V_373 -> V_203 = V_371 -> V_203 ;
V_373 -> type = V_371 -> V_204 & V_374 ;
V_373 -> V_371 = ( V_371 -> V_204 >> V_375 ) & 1 ;
V_373 -> V_376 = ( V_371 -> V_204 >> V_377 ) & 3 ;
V_373 -> V_378 = ( V_371 -> V_204 >> V_379 ) & 1 ;
V_373 -> V_380 = ( V_371 -> V_204 >> V_381 ) & 1 ;
V_373 -> V_382 = ( V_371 -> V_204 >> V_383 ) & 1 ;
V_373 -> V_384 = ( V_371 -> V_204 >> V_385 ) & 1 ;
V_373 -> V_22 = V_371 -> V_208 > 0xfffff ;
V_373 -> V_386 = ! V_373 -> V_378 || ( V_373 -> type == 0 ) ;
switch ( V_202 ) {
case V_369 :
V_373 -> type |= 0x2 ;
break;
case V_364 :
case V_365 :
case V_366 :
case V_367 :
if ( ! V_373 -> V_386 )
V_373 -> type |= 0x1 ;
break;
case V_368 :
if ( V_373 -> V_386 )
V_373 -> V_384 = 0 ;
V_373 -> V_376 = F_4 ( V_9 ) -> V_1 -> V_65 . V_387 ;
break;
}
}
static int F_183 ( struct V_8 * V_9 )
{
struct V_224 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
return V_65 -> V_387 ;
}
static void F_184 ( struct V_8 * V_9 , struct V_122 * V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_388 -> V_389 = V_10 -> V_1 -> V_65 . V_273 . V_208 ;
V_388 -> V_135 = V_10 -> V_1 -> V_65 . V_273 . V_95 ;
}
static void F_185 ( struct V_8 * V_9 , struct V_122 * V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_273 . V_208 = V_388 -> V_389 ;
V_10 -> V_1 -> V_65 . V_273 . V_95 = V_388 -> V_135 ;
F_3 ( V_10 -> V_1 , V_390 ) ;
}
static void F_186 ( struct V_8 * V_9 , struct V_122 * V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_388 -> V_389 = V_10 -> V_1 -> V_65 . V_272 . V_208 ;
V_388 -> V_135 = V_10 -> V_1 -> V_65 . V_272 . V_95 ;
}
static void F_187 ( struct V_8 * V_9 , struct V_122 * V_388 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_272 . V_208 = V_388 -> V_389 ;
V_10 -> V_1 -> V_65 . V_272 . V_95 = V_388 -> V_135 ;
F_3 ( V_10 -> V_1 , V_390 ) ;
}
static void F_188 ( struct V_8 * V_9 )
{
}
static void F_189 ( struct V_8 * V_9 )
{
}
static void F_190 ( struct V_8 * V_9 )
{
}
static void F_191 ( struct V_7 * V_10 )
{
T_9 V_391 = V_10 -> V_9 . V_46 . V_392 ;
T_1 * V_393 = & V_10 -> V_1 -> V_65 . V_392 ;
* V_393 = ( * V_393 & ~ V_394 )
| ( V_391 & V_394 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
if ( V_391 == * V_393 ) {
F_13 ( V_10 , V_225 ) ;
F_13 ( V_10 , V_228 ) ;
} else {
F_12 ( V_10 , V_225 ) ;
F_12 ( V_10 , V_228 ) ;
}
}
static void F_118 ( struct V_8 * V_9 , unsigned long V_392 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_29
if ( V_9 -> V_46 . V_61 & V_64 ) {
if ( ! F_192 ( V_9 ) && ( V_392 & V_395 ) ) {
V_9 -> V_46 . V_61 |= V_63 ;
V_10 -> V_1 -> V_65 . V_61 |= V_63 | V_64 ;
}
if ( F_192 ( V_9 ) && ! ( V_392 & V_395 ) ) {
V_9 -> V_46 . V_61 &= ~ V_63 ;
V_10 -> V_1 -> V_65 . V_61 &= ~ ( V_63 | V_64 ) ;
}
}
#endif
V_9 -> V_46 . V_392 = V_392 ;
if ( ! V_62 )
V_392 |= V_395 | V_396 ;
if ( F_193 ( V_9 -> V_177 , V_397 ) )
V_392 &= ~ ( V_282 | V_281 ) ;
V_10 -> V_1 -> V_65 . V_392 = V_392 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_191 ( V_10 ) ;
}
static int F_194 ( struct V_8 * V_9 , unsigned long V_284 )
{
unsigned long V_398 = F_195 () & V_399 ;
unsigned long V_400 = F_4 ( V_9 ) -> V_1 -> V_65 . V_284 ;
if ( V_284 & V_401 )
return 1 ;
if ( V_62 && ( ( V_400 ^ V_284 ) & V_402 ) )
F_196 ( V_9 ) ;
V_9 -> V_46 . V_284 = V_284 ;
if ( ! V_62 )
V_284 |= V_285 ;
V_284 |= V_398 ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_284 = V_284 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_67 ) ;
return 0 ;
}
static void F_197 ( struct V_8 * V_9 ,
struct V_372 * V_373 , int V_202 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_201 * V_371 = F_180 ( V_9 , V_202 ) ;
V_371 -> V_95 = V_373 -> V_95 ;
V_371 -> V_208 = V_373 -> V_208 ;
V_371 -> V_203 = V_373 -> V_203 ;
if ( V_373 -> V_386 )
V_371 -> V_204 = 0 ;
else {
V_371 -> V_204 = ( V_373 -> type & V_374 ) ;
V_371 -> V_204 |= ( V_373 -> V_371 & 1 ) << V_375 ;
V_371 -> V_204 |= ( V_373 -> V_376 & 3 ) << V_377 ;
V_371 -> V_204 |= ( V_373 -> V_378 & 1 ) << V_379 ;
V_371 -> V_204 |= ( V_373 -> V_380 & 1 ) << V_381 ;
V_371 -> V_204 |= ( V_373 -> V_382 & 1 ) << V_383 ;
V_371 -> V_204 |= ( V_373 -> V_384 & 1 ) << V_385 ;
V_371 -> V_204 |= ( V_373 -> V_22 & 1 ) << V_403 ;
}
if ( V_202 == V_368 )
V_10 -> V_1 -> V_65 . V_387 = ( V_371 -> V_204 >> V_377 ) & 3 ;
F_3 ( V_10 -> V_1 , V_404 ) ;
}
static void F_198 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_90 ) ;
if ( V_9 -> V_405 & V_406 ) {
if ( V_9 -> V_405 & V_407 )
F_17 ( V_10 , V_90 ) ;
} else
V_9 -> V_405 = 0 ;
}
static void F_199 ( struct V_7 * V_10 , struct V_120 * V_121 )
{
if ( V_121 -> V_134 > V_121 -> V_132 ) {
++ V_121 -> V_131 ;
V_121 -> V_134 = 1 ;
V_10 -> V_1 -> V_2 . V_408 = V_409 ;
}
V_10 -> V_131 = V_121 -> V_131 ;
V_10 -> V_1 -> V_2 . V_58 = V_121 -> V_134 ++ ;
F_3 ( V_10 -> V_1 , V_410 ) ;
}
static T_1 F_200 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_278 ;
}
static void F_201 ( struct V_8 * V_9 , unsigned long V_411 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_278 = V_411 ;
F_3 ( V_10 -> V_1 , V_412 ) ;
}
static void F_202 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_203 ( V_9 -> V_46 . V_384 [ 0 ] , 0 ) ;
F_203 ( V_9 -> V_46 . V_384 [ 1 ] , 1 ) ;
F_203 ( V_9 -> V_46 . V_384 [ 2 ] , 2 ) ;
F_203 ( V_9 -> V_46 . V_384 [ 3 ] , 3 ) ;
V_9 -> V_46 . V_278 = F_200 ( V_9 ) ;
V_9 -> V_46 . V_413 = V_10 -> V_1 -> V_65 . V_413 ;
V_9 -> V_46 . V_414 &= ~ V_415 ;
F_15 ( V_10 ) ;
}
static void F_204 ( struct V_8 * V_9 , unsigned long V_411 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_413 = V_411 ;
F_3 ( V_10 -> V_1 , V_412 ) ;
}
static int F_205 ( struct V_7 * V_10 )
{
T_1 V_416 = V_10 -> V_1 -> V_2 . V_417 ;
T_1 V_88 ;
int V_148 = 1 ;
switch ( V_10 -> V_418 ) {
default:
V_88 = V_10 -> V_1 -> V_2 . V_419 ;
F_206 ( V_416 , V_88 ) ;
if ( ! V_62 && F_207 ( & V_10 -> V_9 ) )
F_208 ( & V_10 -> V_9 , V_416 ) ;
V_148 = F_209 ( & V_10 -> V_9 , V_416 , V_88 ,
V_10 -> V_1 -> V_2 . V_420 ,
V_10 -> V_1 -> V_2 . V_421 ) ;
break;
case V_422 :
V_10 -> V_418 = 0 ;
F_210 () ;
F_211 ( V_416 ) ;
F_212 () ;
break;
case V_423 :
V_10 -> V_418 = 0 ;
F_210 () ;
F_213 ( V_416 ) ;
F_212 () ;
break;
}
return V_148 ;
}
static int F_214 ( struct V_7 * V_10 )
{
struct V_424 * V_424 = V_10 -> V_9 . V_425 ;
if ( ! ( V_10 -> V_9 . V_405 &
( V_426 | V_427 ) ) &&
! V_10 -> V_428 ) {
F_215 ( & V_10 -> V_9 , V_236 ) ;
return 1 ;
}
if ( V_10 -> V_428 ) {
V_10 -> V_428 = false ;
if ( ! ( V_10 -> V_9 . V_405 & V_426 ) )
V_10 -> V_1 -> V_65 . V_357 &=
~ ( V_429 | V_430 ) ;
}
if ( V_10 -> V_9 . V_405 &
( V_426 | V_427 ) ) {
V_424 -> V_431 = V_432 ;
V_424 -> V_433 . V_46 . V_434 =
V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_424 -> V_433 . V_46 . V_435 = V_236 ;
return 0 ;
}
return 1 ;
}
static int F_216 ( struct V_7 * V_10 )
{
struct V_424 * V_424 = V_10 -> V_9 . V_425 ;
V_424 -> V_431 = V_432 ;
V_424 -> V_433 . V_46 . V_434 = V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_424 -> V_433 . V_46 . V_435 = V_90 ;
return 0 ;
}
static int F_217 ( struct V_7 * V_10 )
{
int V_436 ;
V_436 = F_37 ( & V_10 -> V_9 , V_437 ) ;
if ( V_436 != V_81 )
F_215 ( & V_10 -> V_9 , V_233 ) ;
return 1 ;
}
static int F_218 ( struct V_7 * V_10 )
{
F_219 ( & V_10 -> V_9 , V_235 , 0 ) ;
return 1 ;
}
static bool F_220 ( void )
{
int V_103 , V_51 ;
T_1 V_411 ;
if ( ! V_107 )
return false ;
V_411 = F_45 ( V_438 , & V_103 ) ;
if ( V_103 )
return false ;
V_411 &= ~ ( 1ULL << 62 ) ;
if ( V_411 != 0xb600000000010015ULL )
return false ;
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 )
F_48 ( F_221 ( V_51 ) , 0 , 0 ) ;
V_411 = F_45 ( V_439 , & V_103 ) ;
if ( ! V_103 ) {
T_2 V_101 , V_102 ;
V_411 &= ~ ( 1ULL << 2 ) ;
V_101 = F_46 ( V_411 ) ;
V_102 = F_47 ( V_411 ) ;
F_48 ( V_439 , V_101 , V_102 ) ;
}
F_222 () ;
return true ;
}
static void F_223 ( struct V_7 * V_10 )
{
if ( F_220 () ) {
F_59 ( L_11 ) ;
F_224 ( V_440 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_225 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_226 ( struct V_7 * V_10 )
{
struct V_424 * V_424 = V_10 -> V_9 . V_425 ;
F_136 ( V_10 -> V_1 ) ;
F_114 ( V_10 ) ;
V_424 -> V_431 = V_441 ;
return 0 ;
}
static int F_227 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_2 V_442 = V_10 -> V_1 -> V_2 . V_419 ;
int V_389 , V_443 , string ;
unsigned V_444 ;
++ V_10 -> V_9 . V_351 . V_445 ;
string = ( V_442 & V_446 ) != 0 ;
V_443 = ( V_442 & V_447 ) != 0 ;
if ( string )
return F_37 ( V_9 , 0 ) == V_81 ;
V_444 = V_442 >> 16 ;
V_389 = ( V_442 & V_448 ) >> V_449 ;
V_10 -> V_78 = V_10 -> V_1 -> V_2 . V_417 ;
F_34 ( & V_10 -> V_9 ) ;
return V_443 ? F_228 ( V_9 , V_389 , V_444 )
: F_229 ( V_9 , V_389 , V_444 ) ;
}
static int F_230 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_231 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_351 . V_450 ;
return 1 ;
}
static int F_232 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_233 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 1 ;
return F_234 ( & V_10 -> V_9 ) ;
}
static int F_235 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_236 ( & V_10 -> V_9 ) ;
}
static unsigned long F_237 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_24 . V_451 ;
}
static T_1 F_238 ( struct V_8 * V_9 , int V_152 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_289 = V_10 -> V_24 . V_451 ;
T_1 V_452 ;
int V_72 ;
V_72 = F_239 ( V_9 , F_240 ( V_289 ) , & V_452 ,
F_241 ( V_289 ) + V_152 * 8 , 8 ) ;
if ( V_72 )
return 0 ;
return V_452 ;
}
static void F_242 ( struct V_8 * V_9 ,
unsigned long V_453 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_451 = V_453 ;
F_3 ( V_10 -> V_1 , V_454 ) ;
F_196 ( V_9 ) ;
}
static void F_243 ( struct V_8 * V_9 ,
struct V_455 * V_456 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_457 != V_458 ) {
V_10 -> V_1 -> V_2 . V_457 = V_458 ;
V_10 -> V_1 -> V_2 . V_459 = 0 ;
V_10 -> V_1 -> V_2 . V_419 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_417 = V_456 -> V_135 ;
}
V_10 -> V_1 -> V_2 . V_419 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_419 |= V_456 -> V_88 ;
if ( V_10 -> V_1 -> V_2 . V_419 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_419 &= ~ 1 ;
F_244 ( V_10 ) ;
}
static void F_245 ( struct V_8 * V_9 )
{
F_75 ( F_246 ( V_9 ) ) ;
F_247 ( V_9 ) ;
V_9 -> V_46 . V_460 . V_461 = F_242 ;
V_9 -> V_46 . V_460 . V_462 = F_237 ;
V_9 -> V_46 . V_460 . V_463 = F_238 ;
V_9 -> V_46 . V_460 . V_464 = F_243 ;
V_9 -> V_46 . V_460 . V_465 = F_28 () ;
F_248 ( V_9 , & V_9 -> V_46 . V_460 ) ;
V_9 -> V_46 . V_361 = & V_9 -> V_46 . V_466 ;
}
static void F_249 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_361 = & V_9 -> V_46 . V_460 ;
}
static int F_250 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_46 . V_61 & V_66 )
|| ! F_192 ( & V_10 -> V_9 ) ) {
F_215 ( & V_10 -> V_9 , V_233 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_65 . V_387 ) {
F_251 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_10 , unsigned V_86 ,
bool V_87 , T_2 V_88 )
{
int V_467 ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_457 = V_468 + V_86 ;
V_10 -> V_1 -> V_2 . V_459 = 0 ;
V_10 -> V_1 -> V_2 . V_419 = V_88 ;
V_10 -> V_1 -> V_2 . V_417 = V_10 -> V_9 . V_46 . V_469 ;
V_467 = F_252 ( V_10 ) ;
if ( V_467 == V_470 )
V_10 -> V_24 . V_471 = true ;
return V_467 ;
}
static inline bool F_253 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_472 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_473 ) )
return false ;
if ( V_10 -> V_24 . V_471 )
return false ;
V_10 -> V_1 -> V_2 . V_457 = V_474 ;
V_10 -> V_1 -> V_2 . V_419 = 0 ;
V_10 -> V_1 -> V_2 . V_417 = 0 ;
if ( V_10 -> V_24 . V_29 & 1ULL ) {
V_10 -> V_24 . V_471 = true ;
F_254 ( V_10 -> V_1 -> V_65 . V_91 ) ;
return false ;
}
return true ;
}
static inline bool F_255 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_238 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_457 = V_475 ;
V_10 -> V_24 . V_471 = true ;
return false ;
}
static void * F_256 ( struct V_7 * V_10 , T_1 V_476 , struct V_182 * * V_477 )
{
struct V_182 * V_182 ;
F_257 () ;
V_182 = F_258 ( & V_10 -> V_9 , V_476 >> V_141 ) ;
if ( F_259 ( V_182 ) )
goto error;
* V_477 = V_182 ;
return F_260 ( V_182 ) ;
error:
F_251 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_261 ( struct V_182 * V_182 )
{
F_262 ( V_182 ) ;
F_263 ( V_182 ) ;
}
static int F_264 ( struct V_7 * V_10 )
{
unsigned V_444 , V_389 , V_478 ;
T_10 V_104 , V_77 ;
T_4 V_479 ;
T_1 V_476 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_247 ) ) )
return V_480 ;
V_444 = V_10 -> V_1 -> V_2 . V_419 >> 16 ;
V_389 = ( V_10 -> V_1 -> V_2 . V_419 & V_448 ) >>
V_449 ;
V_476 = V_10 -> V_24 . V_481 + ( V_444 / 8 ) ;
V_479 = V_444 % 8 ;
V_478 = ( V_479 + V_389 > 8 ) ? 2 : 1 ;
V_77 = ( 0xf >> ( 4 - V_389 ) ) << V_479 ;
V_104 = 0 ;
if ( F_265 ( & V_10 -> V_9 , V_476 , & V_104 , V_478 ) )
return V_470 ;
return ( V_104 & V_77 ) ? V_470 : V_480 ;
}
static int F_266 ( struct V_7 * V_10 )
{
T_2 V_50 , V_49 , V_411 ;
int V_156 , V_77 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_248 ) ) )
return V_480 ;
V_49 = V_10 -> V_9 . V_46 . V_279 [ V_482 ] ;
V_50 = F_24 ( V_49 ) ;
V_156 = V_10 -> V_1 -> V_2 . V_419 & 1 ;
V_77 = 1 << ( ( 2 * ( V_49 & 0xf ) ) + V_156 ) ;
if ( V_50 == V_56 )
return V_470 ;
V_50 *= 4 ;
if ( F_265 ( & V_10 -> V_9 , V_10 -> V_24 . V_483 + V_50 , & V_411 , 4 ) )
return V_470 ;
return ( V_411 & V_77 ) ? V_470 : V_480 ;
}
static int F_267 ( struct V_7 * V_10 )
{
T_2 V_457 = V_10 -> V_1 -> V_2 . V_457 ;
switch ( V_457 ) {
case V_474 :
case V_475 :
case V_468 + V_234 :
return V_480 ;
case V_458 :
if ( V_62 )
return V_480 ;
break;
case V_468 + V_232 :
if ( ! V_62 && V_10 -> V_418 == 0 )
return V_480 ;
break;
default:
break;
}
return V_484 ;
}
static int F_252 ( struct V_7 * V_10 )
{
T_2 V_457 = V_10 -> V_1 -> V_2 . V_457 ;
int V_467 = V_480 ;
switch ( V_457 ) {
case V_485 :
V_467 = F_266 ( V_10 ) ;
break;
case V_486 :
V_467 = F_264 ( V_10 ) ;
break;
case V_487 ... V_488 : {
T_2 V_6 = 1U << ( V_457 - V_487 ) ;
if ( V_10 -> V_24 . V_26 & V_6 )
V_467 = V_470 ;
break;
}
case V_489 ... V_490 : {
T_2 V_6 = 1U << ( V_457 - V_489 ) ;
if ( V_10 -> V_24 . V_27 & V_6 )
V_467 = V_470 ;
break;
}
case V_468 ... V_468 + 0x1f : {
T_2 V_491 = 1 << ( V_457 - V_468 ) ;
if ( V_10 -> V_24 . V_28 & V_491 )
V_467 = V_470 ;
else if ( ( V_457 == V_468 + V_232 ) &&
V_10 -> V_418 != 0 )
V_467 = V_470 ;
break;
}
case V_492 : {
V_467 = V_470 ;
break;
}
default: {
T_1 V_493 = 1ULL << ( V_457 - V_474 ) ;
if ( V_10 -> V_24 . V_29 & V_493 )
V_467 = V_470 ;
}
}
return V_467 ;
}
static int F_268 ( struct V_7 * V_10 )
{
int V_467 ;
V_467 = F_252 ( V_10 ) ;
if ( V_467 == V_470 )
F_244 ( V_10 ) ;
return V_467 ;
}
static inline void F_269 ( struct V_1 * V_494 , struct V_1 * V_495 )
{
struct V_18 * V_496 = & V_494 -> V_2 ;
struct V_18 * V_497 = & V_495 -> V_2 ;
V_496 -> V_26 = V_497 -> V_26 ;
V_496 -> V_27 = V_497 -> V_27 ;
V_496 -> V_28 = V_497 -> V_28 ;
V_496 -> V_29 = V_497 -> V_29 ;
V_496 -> V_262 = V_497 -> V_262 ;
V_496 -> V_263 = V_497 -> V_263 ;
V_496 -> V_210 = V_497 -> V_210 ;
V_496 -> V_58 = V_497 -> V_58 ;
V_496 -> V_408 = V_497 -> V_408 ;
V_496 -> V_221 = V_497 -> V_221 ;
V_496 -> V_498 = V_497 -> V_498 ;
V_496 -> V_73 = V_497 -> V_73 ;
V_496 -> V_457 = V_497 -> V_457 ;
V_496 -> V_459 = V_497 -> V_459 ;
V_496 -> V_419 = V_497 -> V_419 ;
V_496 -> V_417 = V_497 -> V_417 ;
V_496 -> V_499 = V_497 -> V_499 ;
V_496 -> V_500 = V_497 -> V_500 ;
V_496 -> V_286 = V_497 -> V_286 ;
V_496 -> V_97 = V_497 -> V_97 ;
V_496 -> V_100 = V_497 -> V_100 ;
V_496 -> V_451 = V_497 -> V_451 ;
V_496 -> V_165 = V_497 -> V_165 ;
}
static int F_244 ( struct V_7 * V_10 )
{
struct V_1 * V_501 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_182 * V_182 ;
F_270 ( V_1 -> V_2 . V_457 ,
V_1 -> V_2 . V_419 ,
V_1 -> V_2 . V_417 ,
V_1 -> V_2 . V_499 ,
V_1 -> V_2 . V_500 ,
V_502 ) ;
V_501 = F_256 ( V_10 , V_10 -> V_24 . V_1 , & V_182 ) ;
if ( ! V_501 )
return 1 ;
F_271 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_1 = 0 ;
F_22 ( V_10 ) ;
V_501 -> V_65 . V_265 = V_1 -> V_65 . V_265 ;
V_501 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_501 -> V_65 . V_266 = V_1 -> V_65 . V_266 ;
V_501 -> V_65 . V_267 = V_1 -> V_65 . V_267 ;
V_501 -> V_65 . V_272 = V_1 -> V_65 . V_272 ;
V_501 -> V_65 . V_273 = V_1 -> V_65 . V_273 ;
V_501 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_501 -> V_65 . V_392 = F_272 ( & V_10 -> V_9 ) ;
V_501 -> V_65 . V_289 = F_177 ( & V_10 -> V_9 ) ;
V_501 -> V_65 . V_469 = V_1 -> V_65 . V_469 ;
V_501 -> V_65 . V_284 = V_10 -> V_9 . V_46 . V_284 ;
V_501 -> V_65 . V_357 = F_273 ( & V_10 -> V_9 ) ;
V_501 -> V_65 . V_91 = V_1 -> V_65 . V_91 ;
V_501 -> V_65 . V_503 = V_1 -> V_65 . V_503 ;
V_501 -> V_65 . V_504 = V_1 -> V_65 . V_504 ;
V_501 -> V_65 . V_413 = V_1 -> V_65 . V_413 ;
V_501 -> V_65 . V_278 = V_1 -> V_65 . V_278 ;
V_501 -> V_65 . V_387 = V_1 -> V_65 . V_387 ;
V_501 -> V_2 . V_221 = V_1 -> V_2 . V_221 ;
V_501 -> V_2 . V_498 = V_1 -> V_2 . V_498 ;
V_501 -> V_2 . V_73 = V_1 -> V_2 . V_73 ;
V_501 -> V_2 . V_457 = V_1 -> V_2 . V_457 ;
V_501 -> V_2 . V_459 = V_1 -> V_2 . V_459 ;
V_501 -> V_2 . V_419 = V_1 -> V_2 . V_419 ;
V_501 -> V_2 . V_417 = V_1 -> V_2 . V_417 ;
V_501 -> V_2 . V_499 = V_1 -> V_2 . V_499 ;
V_501 -> V_2 . V_500 = V_1 -> V_2 . V_500 ;
if ( V_10 -> V_505 )
V_501 -> V_2 . V_78 = V_1 -> V_2 . V_78 ;
if ( V_1 -> V_2 . V_97 & V_70 ) {
struct V_18 * V_506 = & V_501 -> V_2 ;
V_506 -> V_499 = V_1 -> V_2 . V_97 ;
V_506 -> V_500 = V_1 -> V_2 . V_100 ;
}
V_501 -> V_2 . V_408 = 0 ;
V_501 -> V_2 . V_97 = 0 ;
V_501 -> V_2 . V_100 = 0 ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_472 ) )
V_501 -> V_2 . V_221 &= ~ V_264 ;
F_269 ( V_1 , V_25 ) ;
F_274 ( & V_10 -> V_9 ) ;
F_275 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_451 = 0 ;
V_10 -> V_1 -> V_65 . V_265 = V_25 -> V_65 . V_265 ;
V_10 -> V_1 -> V_65 . V_94 = V_25 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_266 = V_25 -> V_65 . V_266 ;
V_10 -> V_1 -> V_65 . V_267 = V_25 -> V_65 . V_267 ;
V_10 -> V_1 -> V_65 . V_272 = V_25 -> V_65 . V_272 ;
V_10 -> V_1 -> V_65 . V_273 = V_25 -> V_65 . V_273 ;
F_117 ( & V_10 -> V_9 , V_25 -> V_65 . V_357 ) ;
F_30 ( & V_10 -> V_9 , V_25 -> V_65 . V_61 ) ;
F_118 ( & V_10 -> V_9 , V_25 -> V_65 . V_392 | V_507 ) ;
F_194 ( & V_10 -> V_9 , V_25 -> V_65 . V_284 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_289 = V_25 -> V_65 . V_289 ;
V_10 -> V_9 . V_46 . V_289 = V_25 -> V_65 . V_289 ;
} else {
( void ) F_276 ( & V_10 -> V_9 , V_25 -> V_65 . V_289 ) ;
}
F_150 ( & V_10 -> V_9 , V_508 , V_25 -> V_65 . V_504 ) ;
F_150 ( & V_10 -> V_9 , V_509 , V_25 -> V_65 . V_503 ) ;
F_150 ( & V_10 -> V_9 , V_280 , V_25 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_413 = 0 ;
V_10 -> V_1 -> V_65 . V_387 = 0 ;
V_10 -> V_1 -> V_2 . V_499 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_261 ( V_182 ) ;
F_249 ( & V_10 -> V_9 ) ;
F_119 ( & V_10 -> V_9 ) ;
F_277 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_278 ( struct V_7 * V_10 )
{
int V_51 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_248 ) ) )
return true ;
for ( V_51 = 0 ; V_51 < V_163 ; V_51 ++ ) {
T_2 V_411 , V_510 ;
T_1 V_50 ;
if ( V_164 [ V_51 ] == 0xffffffff )
break;
V_510 = V_164 [ V_51 ] ;
V_50 = V_10 -> V_24 . V_483 + ( V_510 * 4 ) ;
if ( F_265 ( & V_10 -> V_9 , V_50 , & V_411 , 4 ) )
return false ;
V_10 -> V_24 . V_154 [ V_510 ] = V_10 -> V_154 [ V_510 ] | V_411 ;
}
V_10 -> V_1 -> V_2 . V_263 = F_116 ( V_10 -> V_24 . V_154 ) ;
return true ;
}
static bool F_279 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_29 & ( 1ULL << V_251 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_58 == 0 )
return false ;
if ( V_1 -> V_2 . V_286 && ! V_62 )
return false ;
return true ;
}
static bool F_280 ( struct V_7 * V_10 )
{
struct V_1 * V_501 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_182 * V_182 ;
T_1 V_511 ;
V_511 = V_10 -> V_1 -> V_65 . V_504 ;
V_501 = F_256 ( V_10 , V_10 -> V_1 -> V_65 . V_504 , & V_182 ) ;
if ( ! V_501 )
return false ;
if ( ! F_279 ( V_501 ) ) {
V_501 -> V_2 . V_457 = V_492 ;
V_501 -> V_2 . V_459 = 0 ;
V_501 -> V_2 . V_419 = 0 ;
V_501 -> V_2 . V_417 = 0 ;
F_261 ( V_182 ) ;
return false ;
}
F_281 ( V_10 -> V_1 -> V_65 . V_91 , V_511 ,
V_501 -> V_65 . V_91 ,
V_501 -> V_2 . V_221 ,
V_501 -> V_2 . V_97 ,
V_501 -> V_2 . V_286 ) ;
F_282 ( V_501 -> V_2 . V_26 & 0xffff ,
V_501 -> V_2 . V_26 >> 16 ,
V_501 -> V_2 . V_28 ,
V_501 -> V_2 . V_29 ) ;
F_274 ( & V_10 -> V_9 ) ;
F_275 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_265 = V_1 -> V_65 . V_265 ;
V_25 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_25 -> V_65 . V_266 = V_1 -> V_65 . V_266 ;
V_25 -> V_65 . V_267 = V_1 -> V_65 . V_267 ;
V_25 -> V_65 . V_272 = V_1 -> V_65 . V_272 ;
V_25 -> V_65 . V_273 = V_1 -> V_65 . V_273 ;
V_25 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_25 -> V_65 . V_392 = F_272 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_284 = V_10 -> V_9 . V_46 . V_284 ;
V_25 -> V_65 . V_357 = F_273 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_91 = F_39 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_503 = V_1 -> V_65 . V_503 ;
V_25 -> V_65 . V_504 = V_1 -> V_65 . V_504 ;
if ( V_62 )
V_25 -> V_65 . V_289 = V_1 -> V_65 . V_289 ;
else
V_25 -> V_65 . V_289 = F_177 ( & V_10 -> V_9 ) ;
F_269 ( V_25 , V_1 ) ;
if ( F_273 ( & V_10 -> V_9 ) & V_512 )
V_10 -> V_9 . V_46 . V_47 |= V_473 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_473 ;
if ( V_501 -> V_2 . V_286 ) {
F_283 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_451 = V_501 -> V_2 . V_451 ;
F_245 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_65 . V_265 = V_501 -> V_65 . V_265 ;
V_10 -> V_1 -> V_65 . V_94 = V_501 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_266 = V_501 -> V_65 . V_266 ;
V_10 -> V_1 -> V_65 . V_267 = V_501 -> V_65 . V_267 ;
V_10 -> V_1 -> V_65 . V_272 = V_501 -> V_65 . V_272 ;
V_10 -> V_1 -> V_65 . V_273 = V_501 -> V_65 . V_273 ;
F_117 ( & V_10 -> V_9 , V_501 -> V_65 . V_357 ) ;
F_30 ( & V_10 -> V_9 , V_501 -> V_65 . V_61 ) ;
F_118 ( & V_10 -> V_9 , V_501 -> V_65 . V_392 ) ;
F_194 ( & V_10 -> V_9 , V_501 -> V_65 . V_284 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_289 = V_501 -> V_65 . V_289 ;
V_10 -> V_9 . V_46 . V_289 = V_501 -> V_65 . V_289 ;
} else
( void ) F_276 ( & V_10 -> V_9 , V_501 -> V_65 . V_289 ) ;
F_119 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_65 . V_469 = V_10 -> V_9 . V_46 . V_469 = V_501 -> V_65 . V_469 ;
F_150 ( & V_10 -> V_9 , V_508 , V_501 -> V_65 . V_504 ) ;
F_150 ( & V_10 -> V_9 , V_509 , V_501 -> V_65 . V_503 ) ;
F_150 ( & V_10 -> V_9 , V_280 , V_501 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_504 = V_501 -> V_65 . V_504 ;
V_10 -> V_1 -> V_65 . V_503 = V_501 -> V_65 . V_503 ;
V_10 -> V_1 -> V_65 . V_91 = V_501 -> V_65 . V_91 ;
V_10 -> V_1 -> V_65 . V_413 = V_501 -> V_65 . V_413 ;
V_10 -> V_1 -> V_65 . V_278 = V_501 -> V_65 . V_278 ;
V_10 -> V_1 -> V_65 . V_387 = V_501 -> V_65 . V_387 ;
V_10 -> V_24 . V_483 = V_501 -> V_2 . V_263 & ~ 0x0fffULL ;
V_10 -> V_24 . V_481 = V_501 -> V_2 . V_262 & ~ 0x0fffULL ;
V_10 -> V_24 . V_26 = V_501 -> V_2 . V_26 ;
V_10 -> V_24 . V_27 = V_501 -> V_2 . V_27 ;
V_10 -> V_24 . V_28 = V_501 -> V_2 . V_28 ;
V_10 -> V_24 . V_29 = V_501 -> V_2 . V_29 ;
F_196 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_221 = V_501 -> V_2 . V_221 | V_264 ;
if ( V_501 -> V_2 . V_221 & V_264 )
V_10 -> V_9 . V_46 . V_47 |= V_472 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_472 ;
if ( V_10 -> V_9 . V_46 . V_47 & V_472 ) {
F_13 ( V_10 , V_513 ) ;
F_13 ( V_10 , V_231 ) ;
}
F_20 ( V_10 , V_252 ) ;
V_10 -> V_1 -> V_2 . V_165 = V_501 -> V_2 . V_165 ;
V_10 -> V_1 -> V_2 . V_498 = V_501 -> V_2 . V_498 ;
V_10 -> V_1 -> V_2 . V_73 = V_501 -> V_2 . V_73 ;
V_10 -> V_1 -> V_2 . V_210 += V_501 -> V_2 . V_210 ;
V_10 -> V_1 -> V_2 . V_97 = V_501 -> V_2 . V_97 ;
V_10 -> V_1 -> V_2 . V_100 = V_501 -> V_2 . V_100 ;
F_261 ( V_182 ) ;
F_284 ( & V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
V_10 -> V_24 . V_1 = V_511 ;
F_21 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_285 ( struct V_1 * V_495 , struct V_1 * V_514 )
{
V_514 -> V_65 . V_268 = V_495 -> V_65 . V_268 ;
V_514 -> V_65 . V_269 = V_495 -> V_65 . V_269 ;
V_514 -> V_65 . V_276 = V_495 -> V_65 . V_276 ;
V_514 -> V_65 . V_274 = V_495 -> V_65 . V_274 ;
V_514 -> V_65 . V_515 = V_495 -> V_65 . V_515 ;
V_514 -> V_65 . V_516 = V_495 -> V_65 . V_516 ;
V_514 -> V_65 . V_517 = V_495 -> V_65 . V_517 ;
V_514 -> V_65 . V_518 = V_495 -> V_65 . V_518 ;
V_514 -> V_65 . V_519 = V_495 -> V_65 . V_519 ;
V_514 -> V_65 . V_520 = V_495 -> V_65 . V_520 ;
V_514 -> V_65 . V_521 = V_495 -> V_65 . V_521 ;
V_514 -> V_65 . V_522 = V_495 -> V_65 . V_522 ;
}
static int F_286 ( struct V_7 * V_10 )
{
struct V_1 * V_501 ;
struct V_182 * V_182 ;
if ( F_250 ( V_10 ) )
return 1 ;
V_501 = F_256 ( V_10 , V_10 -> V_1 -> V_65 . V_504 , & V_182 ) ;
if ( ! V_501 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_285 ( V_501 , V_10 -> V_1 ) ;
F_261 ( V_182 ) ;
return 1 ;
}
static int F_287 ( struct V_7 * V_10 )
{
struct V_1 * V_501 ;
struct V_182 * V_182 ;
if ( F_250 ( V_10 ) )
return 1 ;
V_501 = F_256 ( V_10 , V_10 -> V_1 -> V_65 . V_504 , & V_182 ) ;
if ( ! V_501 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_285 ( V_10 -> V_1 , V_501 ) ;
F_261 ( V_182 ) ;
return 1 ;
}
static int F_288 ( struct V_7 * V_10 )
{
if ( F_250 ( V_10 ) )
return 1 ;
F_40 ( & V_10 -> V_9 , F_39 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_280 ( V_10 ) )
return 1 ;
if ( ! F_278 ( V_10 ) )
goto V_523;
return 1 ;
V_523:
V_10 -> V_1 -> V_2 . V_457 = V_492 ;
V_10 -> V_1 -> V_2 . V_459 = 0 ;
V_10 -> V_1 -> V_2 . V_419 = 0 ;
V_10 -> V_1 -> V_2 . V_417 = 0 ;
F_244 ( V_10 ) ;
return 1 ;
}
static int F_289 ( struct V_7 * V_10 )
{
if ( F_250 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_224 ( V_524 , & V_10 -> V_9 ) ;
F_21 ( V_10 ) ;
return 1 ;
}
static int F_290 ( struct V_7 * V_10 )
{
if ( F_250 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_22 ( V_10 ) ;
if ( ! F_115 ( & V_10 -> V_9 ) ) {
F_179 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_221 &= ~ V_525 ;
F_3 ( V_10 -> V_1 , V_526 ) ;
}
return 1 ;
}
static int F_291 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_292 ( V_10 -> V_1 -> V_65 . V_91 , F_293 ( & V_10 -> V_9 , V_482 ) ,
F_293 ( & V_10 -> V_9 , V_508 ) ) ;
F_294 ( V_9 , F_293 ( & V_10 -> V_9 , V_508 ) ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_295 ( struct V_7 * V_10 )
{
F_296 ( V_10 -> V_1 -> V_65 . V_91 , F_293 ( & V_10 -> V_9 , V_508 ) ) ;
F_215 ( & V_10 -> V_9 , V_233 ) ;
return 1 ;
}
static int F_297 ( struct V_7 * V_10 )
{
return F_298 ( & V_10 -> V_9 ) ;
}
static int F_299 ( struct V_7 * V_10 )
{
T_1 V_527 = F_300 ( & V_10 -> V_9 ) ;
T_2 V_152 = F_293 ( & V_10 -> V_9 , V_482 ) ;
if ( F_301 ( & V_10 -> V_9 , V_152 , V_527 ) == 0 ) {
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_302 ( struct V_7 * V_10 )
{
T_10 V_528 ;
int V_529 ;
int V_530 = V_10 -> V_1 -> V_2 . V_499 &
V_531 ;
int V_532 = V_10 -> V_1 -> V_2 . V_499 & V_533 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_499 & V_531 ;
T_7 V_534 =
V_10 -> V_1 -> V_2 . V_499 & V_535 ;
bool V_87 = false ;
T_2 V_88 = 0 ;
V_528 = ( T_10 ) V_10 -> V_1 -> V_2 . V_419 ;
if ( V_10 -> V_1 -> V_2 . V_417 &
( 1ULL << V_536 ) )
V_529 = V_537 ;
else if ( V_10 -> V_1 -> V_2 . V_417 &
( 1ULL << V_538 ) )
V_529 = V_539 ;
else if ( V_534 )
V_529 = V_540 ;
else
V_529 = V_541 ;
if ( V_529 == V_540 ) {
switch ( type ) {
case V_542 :
V_10 -> V_9 . V_46 . V_543 = false ;
break;
case V_544 :
if ( V_10 -> V_1 -> V_2 . V_417 &
( 1ULL << V_545 ) ) {
V_87 = true ;
V_88 =
( T_2 ) V_10 -> V_1 -> V_2 . V_417 ;
}
F_274 ( & V_10 -> V_9 ) ;
break;
case V_546 :
F_275 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_529 != V_540 ||
V_530 == V_547 ||
( V_530 == V_544 &&
( V_532 == V_548 || V_532 == V_90 ) ) )
F_34 ( & V_10 -> V_9 ) ;
if ( V_530 != V_547 )
V_532 = - 1 ;
if ( F_303 ( & V_10 -> V_9 , V_528 , V_532 , V_529 ,
V_87 , V_88 ) == V_549 ) {
V_10 -> V_9 . V_425 -> V_431 = V_550 ;
V_10 -> V_9 . V_425 -> V_551 . V_552 = V_553 ;
V_10 -> V_9 . V_425 -> V_551 . V_554 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_304 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
return F_305 ( & V_10 -> V_9 ) ;
}
static int F_306 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_351 . V_555 ;
F_20 ( V_10 , V_556 ) ;
V_10 -> V_9 . V_46 . V_47 |= V_557 ;
V_10 -> V_558 = F_39 ( & V_10 -> V_9 ) ;
F_224 ( V_524 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_307 ( struct V_7 * V_10 )
{
if ( ! F_36 ( V_559 ) )
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
F_294 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_419 ) ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_308 ( struct V_7 * V_10 )
{
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
}
static int F_309 ( struct V_7 * V_10 )
{
int V_103 ;
if ( ! F_36 ( V_79 ) )
return F_308 ( V_10 ) ;
V_103 = F_310 ( & V_10 -> V_9 ) ;
return F_311 ( & V_10 -> V_9 , V_103 ) ;
}
static bool F_312 ( struct V_7 * V_10 ,
unsigned long V_104 )
{
unsigned long V_392 = V_10 -> V_9 . V_46 . V_392 ;
bool V_72 = false ;
T_1 V_29 ;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! F_10 ( & V_10 -> V_9 ) ||
( ! ( V_29 & ( 1ULL << V_240 ) ) ) )
return false ;
V_392 &= ~ V_394 ;
V_104 &= ~ V_394 ;
if ( V_392 ^ V_104 ) {
V_10 -> V_1 -> V_2 . V_457 = V_560 ;
V_72 = ( F_268 ( V_10 ) == V_470 ) ;
}
return V_72 ;
}
static int F_313 ( struct V_7 * V_10 )
{
int V_359 , V_561 ;
unsigned long V_104 ;
int V_103 ;
if ( ! F_36 ( V_559 ) )
return F_308 ( V_10 ) ;
if ( F_161 ( ( V_10 -> V_1 -> V_2 . V_419 & V_562 ) == 0 ) )
return F_308 ( V_10 ) ;
V_359 = V_10 -> V_1 -> V_2 . V_419 & V_563 ;
if ( V_10 -> V_1 -> V_2 . V_457 == V_560 )
V_561 = V_564 - V_487 ;
else
V_561 = V_10 -> V_1 -> V_2 . V_457 - V_487 ;
V_103 = 0 ;
if ( V_561 >= 16 ) {
V_561 -= 16 ;
V_104 = F_293 ( & V_10 -> V_9 , V_359 ) ;
switch ( V_561 ) {
case 0 :
if ( ! F_312 ( V_10 , V_104 ) )
V_103 = F_314 ( & V_10 -> V_9 , V_104 ) ;
else
return 1 ;
break;
case 3 :
V_103 = F_276 ( & V_10 -> V_9 , V_104 ) ;
break;
case 4 :
V_103 = F_315 ( & V_10 -> V_9 , V_104 ) ;
break;
case 8 :
V_103 = F_316 ( & V_10 -> V_9 , V_104 ) ;
break;
default:
F_317 ( 1 , L_12 , V_561 ) ;
F_215 ( & V_10 -> V_9 , V_233 ) ;
return 1 ;
}
} else {
switch ( V_561 ) {
case 0 :
V_104 = F_272 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_104 = V_10 -> V_9 . V_46 . V_469 ;
break;
case 3 :
V_104 = F_177 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_104 = F_318 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_104 = F_319 ( & V_10 -> V_9 ) ;
break;
default:
F_317 ( 1 , L_13 , V_561 ) ;
F_215 ( & V_10 -> V_9 , V_233 ) ;
return 1 ;
}
F_150 ( & V_10 -> V_9 , V_359 , V_104 ) ;
}
return F_311 ( & V_10 -> V_9 , V_103 ) ;
}
static int F_320 ( struct V_7 * V_10 )
{
int V_359 , V_565 ;
unsigned long V_104 ;
if ( V_10 -> V_9 . V_405 == 0 ) {
F_16 ( V_10 ) ;
V_10 -> V_9 . V_46 . V_414 |= V_415 ;
return 1 ;
}
if ( ! F_97 ( V_559 ) )
return F_308 ( V_10 ) ;
V_359 = V_10 -> V_1 -> V_2 . V_419 & V_563 ;
V_565 = V_10 -> V_1 -> V_2 . V_457 - V_489 ;
if ( V_565 >= 16 ) {
if ( ! F_321 ( & V_10 -> V_9 , V_565 - 16 ) )
return 1 ;
V_104 = F_293 ( & V_10 -> V_9 , V_359 ) ;
F_322 ( & V_10 -> V_9 , V_565 - 16 , V_104 ) ;
} else {
if ( ! F_321 ( & V_10 -> V_9 , V_565 ) )
return 1 ;
F_323 ( & V_10 -> V_9 , V_565 , & V_104 ) ;
F_150 ( & V_10 -> V_9 , V_359 , V_104 ) ;
}
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_324 ( struct V_7 * V_10 )
{
struct V_424 * V_424 = V_10 -> V_9 . V_425 ;
int V_148 ;
T_4 V_566 = F_319 ( & V_10 -> V_9 ) ;
V_148 = F_313 ( V_10 ) ;
if ( F_325 ( & V_10 -> V_9 ) )
return V_148 ;
if ( V_566 <= F_319 ( & V_10 -> V_9 ) )
return V_148 ;
V_424 -> V_431 = V_567 ;
return 0 ;
}
static int F_326 ( struct V_8 * V_9 , struct V_568 * V_569 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_569 -> V_152 ) {
case V_570 : {
V_569 -> V_11 = V_10 -> V_1 -> V_2 . V_210 +
F_327 ( V_9 , F_328 () ) ;
break;
}
case V_571 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_516 ;
break;
#ifdef F_29
case V_572 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_517 ;
break;
case V_573 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_518 ;
break;
case V_353 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_515 ;
break;
case V_574 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_519 ;
break;
#endif
case V_575 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_520 ;
break;
case V_576 :
V_569 -> V_11 = V_10 -> V_522 ;
break;
case V_577 :
V_569 -> V_11 = V_10 -> V_521 ;
break;
case V_349 :
if ( ! F_97 ( V_348 ) )
return 1 ;
V_569 -> V_11 = V_10 -> V_350 ;
break;
case V_578 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_579 ;
break;
case V_166 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_580 ;
break;
case V_167 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_581 ;
break;
case V_168 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_582 ;
break;
case V_169 :
V_569 -> V_11 = V_10 -> V_1 -> V_65 . V_583 ;
break;
case V_139 :
V_569 -> V_11 = V_10 -> V_24 . V_584 ;
break;
case V_585 :
V_569 -> V_11 = V_10 -> V_24 . V_586 ;
break;
case V_587 :
V_569 -> V_11 = 0x01000065 ;
break;
case V_588 : {
int V_589 , V_590 ;
V_589 = F_329 ( V_9 ) ;
V_590 = F_330 ( V_9 ) ;
if ( V_589 < 0 || V_590 < 0 )
return F_331 ( V_9 , V_569 ) ;
V_569 -> V_11 = 0 ;
if ( V_589 == 0x15 &&
( V_590 >= 0x2 && V_590 < 0x20 ) )
V_569 -> V_11 = 0x1E ;
}
break;
default:
return F_331 ( V_9 , V_569 ) ;
}
return 0 ;
}
static int F_332 ( struct V_7 * V_10 )
{
T_2 V_591 = F_293 ( & V_10 -> V_9 , V_482 ) ;
struct V_568 V_569 ;
V_569 . V_152 = V_591 ;
V_569 . V_592 = false ;
if ( F_326 ( & V_10 -> V_9 , & V_569 ) ) {
F_333 ( V_591 ) ;
F_251 ( & V_10 -> V_9 , 0 ) ;
} else {
F_334 ( V_591 , V_569 . V_11 ) ;
F_150 ( & V_10 -> V_9 , V_508 ,
V_569 . V_11 & 0xffffffff ) ;
F_150 ( & V_10 -> V_9 , V_327 ,
V_569 . V_11 >> 32 ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_335 ( struct V_8 * V_9 , T_1 V_11 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_593 , V_594 ;
if ( V_11 & ~ V_595 )
return 1 ;
V_594 = V_595 ;
if ( V_10 -> V_24 . V_586 & V_596 )
V_594 &= ~ ( V_597 | V_596 ) ;
V_10 -> V_24 . V_586 &= ~ V_594 ;
V_10 -> V_24 . V_586 |= ( V_11 & V_594 ) ;
V_593 = V_10 -> V_24 . V_586 & V_596 ;
if ( V_593 && ( V_9 -> V_46 . V_61 & V_66 ) )
return 1 ;
return 0 ;
}
static int F_336 ( struct V_8 * V_9 , struct V_568 * V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_591 = V_49 -> V_152 ;
T_1 V_11 = V_49 -> V_11 ;
switch ( V_591 ) {
case V_570 :
F_337 ( V_9 , V_49 ) ;
break;
case V_571 :
V_10 -> V_1 -> V_65 . V_516 = V_11 ;
break;
#ifdef F_29
case V_572 :
V_10 -> V_1 -> V_65 . V_517 = V_11 ;
break;
case V_573 :
V_10 -> V_1 -> V_65 . V_518 = V_11 ;
break;
case V_353 :
V_10 -> V_1 -> V_65 . V_515 = V_11 ;
break;
case V_574 :
V_10 -> V_1 -> V_65 . V_519 = V_11 ;
break;
#endif
case V_575 :
V_10 -> V_1 -> V_65 . V_520 = V_11 ;
break;
case V_576 :
V_10 -> V_522 = V_11 ;
V_10 -> V_1 -> V_65 . V_522 = V_11 ;
break;
case V_577 :
V_10 -> V_521 = V_11 ;
V_10 -> V_1 -> V_65 . V_521 = V_11 ;
break;
case V_349 :
if ( ! F_97 ( V_348 ) )
return 1 ;
V_10 -> V_350 = V_11 ;
F_53 ( V_349 , V_10 -> V_350 ) ;
break;
case V_578 :
if ( ! F_97 ( V_598 ) ) {
F_338 ( V_9 , L_14 ,
V_83 , V_11 ) ;
break;
}
if ( V_11 & V_599 )
return 1 ;
V_10 -> V_1 -> V_65 . V_579 = V_11 ;
F_3 ( V_10 -> V_1 , V_600 ) ;
if ( V_11 & ( 1ULL << 0 ) )
F_83 ( V_10 ) ;
else
F_84 ( V_10 ) ;
break;
case V_139 :
V_10 -> V_24 . V_584 = V_11 ;
break;
case V_585 :
return F_335 ( V_9 , V_11 ) ;
case V_601 :
F_338 ( V_9 , L_15 , V_591 , V_11 ) ;
break;
case V_602 :
if ( F_115 ( V_9 ) )
F_6 ( F_4 ( V_9 ) , V_11 ) ;
default:
return F_339 ( V_9 , V_49 ) ;
}
return 0 ;
}
static int F_340 ( struct V_7 * V_10 )
{
struct V_568 V_49 ;
T_2 V_591 = F_293 ( & V_10 -> V_9 , V_482 ) ;
T_1 V_11 = F_300 ( & V_10 -> V_9 ) ;
V_49 . V_11 = V_11 ;
V_49 . V_152 = V_591 ;
V_49 . V_592 = false ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
if ( F_341 ( & V_10 -> V_9 , & V_49 ) ) {
F_342 ( V_591 , V_11 ) ;
F_251 ( & V_10 -> V_9 , 0 ) ;
} else {
F_343 ( V_591 , V_11 ) ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_344 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_419 )
return F_340 ( V_10 ) ;
else
return F_332 ( V_10 ) ;
}
static int F_345 ( struct V_7 * V_10 )
{
F_224 ( V_524 , & V_10 -> V_9 ) ;
F_179 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_221 &= ~ V_525 ;
F_3 ( V_10 -> V_1 , V_526 ) ;
++ V_10 -> V_9 . V_351 . V_603 ;
return 1 ;
}
static int F_346 ( struct V_7 * V_10 )
{
F_347 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_348 ( struct V_7 * V_10 )
{
F_34 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_349 ( struct V_7 * V_10 )
{
F_350 ( V_604 L_16 ) ;
return F_348 ( V_10 ) ;
}
static int F_351 ( struct V_7 * V_10 )
{
F_350 ( V_604 L_17 ) ;
return F_348 ( V_10 ) ;
}
static int F_352 ( struct V_7 * V_10 )
{
T_2 V_605 = V_10 -> V_1 -> V_2 . V_419 >> 32 ;
T_2 V_606 = V_10 -> V_1 -> V_2 . V_419 ;
T_2 V_298 = V_10 -> V_1 -> V_2 . V_417 >> 32 ;
T_2 V_152 = V_10 -> V_1 -> V_2 . V_417 & 0xFF ;
struct V_607 * V_299 = V_10 -> V_9 . V_46 . V_299 ;
F_353 ( V_10 -> V_9 . V_175 , V_605 , V_606 , V_298 , V_152 ) ;
switch ( V_298 ) {
case V_608 :
F_354 ( V_299 , V_609 , V_605 ) ;
F_354 ( V_299 , V_610 , V_606 ) ;
break;
case V_611 : {
int V_51 ;
struct V_8 * V_9 ;
struct V_177 * V_177 = V_10 -> V_9 . V_177 ;
struct V_607 * V_299 = V_10 -> V_9 . V_46 . V_299 ;
F_355 (i, vcpu, kvm) {
bool V_612 = F_356 ( V_9 , V_299 ,
V_606 & V_613 ,
F_357 ( V_605 ) ,
V_606 & V_614 ) ;
if ( V_612 && ! F_7 ( V_9 ) )
F_93 ( V_9 ) ;
}
break;
}
case V_615 :
break;
case V_616 :
F_358 ( 1 , L_18 ) ;
break;
default:
F_59 ( L_19 ) ;
}
return 1 ;
}
static T_2 * F_359 ( struct V_8 * V_9 , T_2 V_617 , bool V_618 )
{
struct V_172 * V_178 = & V_9 -> V_177 -> V_46 ;
int V_152 ;
T_2 * V_619 ;
int V_620 = F_360 ( V_617 ) ;
if ( ! V_620 )
return NULL ;
if ( V_618 ) {
V_152 = F_361 ( V_620 ) - 1 ;
if ( V_152 > 7 )
return NULL ;
} else {
int V_621 = ( V_620 & 0xf0 ) >> 4 ;
int V_299 = F_361 ( V_620 & 0x0f ) - 1 ;
if ( ( V_299 < 0 ) || ( V_299 > 7 ) ||
( V_621 >= 0xf ) )
return NULL ;
V_152 = ( V_621 << 2 ) + V_299 ;
}
V_619 = ( T_2 * ) F_96 ( V_178 -> V_214 ) ;
return & V_619 [ V_152 ] ;
}
static int F_362 ( struct V_8 * V_9 , T_4 V_622 , T_2 V_617 ,
bool V_623 )
{
bool V_618 ;
T_2 * V_15 , V_297 ;
V_618 = F_363 ( V_9 -> V_46 . V_299 , V_624 ) == V_625 ;
V_15 = F_359 ( V_9 , V_617 , V_618 ) ;
if ( ! V_15 )
return - V_129 ;
V_297 = F_8 ( * V_15 ) ;
V_297 &= ~ V_626 ;
V_297 |= ( V_622 & V_626 ) ;
if ( V_623 )
V_297 |= V_627 ;
else
V_297 &= ~ V_627 ;
F_125 ( * V_15 , V_297 ) ;
return 0 ;
}
static int F_364 ( struct V_8 * V_9 )
{
int V_72 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_617 = F_363 ( V_9 -> V_46 . V_299 , V_628 ) ;
if ( ! V_617 )
return 1 ;
V_72 = F_362 ( V_9 , V_9 -> V_175 , V_617 , true ) ;
if ( V_72 && V_10 -> V_629 ) {
F_362 ( V_9 , 0 , V_10 -> V_629 , false ) ;
V_10 -> V_629 = 0 ;
} else {
V_10 -> V_629 = V_617 ;
}
return V_72 ;
}
static int F_365 ( struct V_8 * V_9 )
{
T_1 * V_630 , * V_631 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_632 = F_363 ( V_9 -> V_46 . V_299 , V_633 ) ;
T_2 V_298 = ( V_632 >> 24 ) & 0xff ;
if ( V_9 -> V_175 == V_298 )
return 0 ;
V_630 = F_120 ( V_9 , V_9 -> V_175 ) ;
V_631 = F_120 ( V_9 , V_298 ) ;
if ( ! V_631 || ! V_630 )
return 1 ;
* V_631 = * V_630 ;
* V_630 = 0ULL ;
F_4 ( V_9 ) -> V_16 = V_631 ;
if ( V_10 -> V_629 )
F_364 ( V_9 ) ;
return 0 ;
}
static int F_366 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_172 * V_178 = & V_9 -> V_177 -> V_46 ;
T_2 V_634 = F_363 ( V_9 -> V_46 . V_299 , V_624 ) ;
T_2 V_635 = ( V_634 >> 28 ) & 0xf ;
if ( V_178 -> V_636 == V_635 )
return 0 ;
F_136 ( F_96 ( V_178 -> V_214 ) ) ;
V_178 -> V_636 = V_635 ;
if ( V_10 -> V_629 )
F_364 ( V_9 ) ;
return 0 ;
}
static int F_367 ( struct V_7 * V_10 )
{
struct V_607 * V_299 = V_10 -> V_9 . V_46 . V_299 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_419 &
V_637 ;
switch ( V_50 ) {
case V_633 :
if ( F_365 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_628 :
if ( F_364 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_624 :
F_366 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
F_354 ( V_299 , V_50 , F_363 ( V_299 , V_50 ) ) ;
return 1 ;
}
static bool F_368 ( T_2 V_50 )
{
bool V_72 = false ;
switch ( V_50 ) {
case V_633 :
case V_638 :
case V_639 :
case V_628 :
case V_624 :
case V_640 :
case V_641 :
case V_610 :
case V_642 :
case V_643 :
case V_644 :
case V_645 :
case V_646 :
case V_647 :
case V_648 :
case V_649 :
V_72 = true ;
break;
default:
break;
}
return V_72 ;
}
static int F_369 ( struct V_7 * V_10 )
{
int V_72 = 0 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_419 &
V_637 ;
T_2 V_650 = V_10 -> V_1 -> V_2 . V_417 &
V_651 ;
bool V_156 = ( V_10 -> V_1 -> V_2 . V_419 >> 32 ) &
V_652 ;
bool V_653 = F_368 ( V_50 ) ;
F_370 ( V_10 -> V_9 . V_175 , V_50 ,
V_653 , V_156 , V_650 ) ;
if ( V_653 ) {
F_358 ( ! V_156 , L_20 ) ;
V_72 = F_367 ( V_10 ) ;
} else {
V_72 = ( F_37 ( & V_10 -> V_9 , 0 ) == V_81 ) ;
}
return V_72 ;
}
static void F_371 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_224 * V_65 = & V_10 -> V_1 -> V_65 ;
F_59 ( L_21 ) ;
F_59 ( L_22 , L_23 , V_2 -> V_26 & 0xffff ) ;
F_59 ( L_22 , L_24 , V_2 -> V_26 >> 16 ) ;
F_59 ( L_22 , L_25 , V_2 -> V_27 & 0xffff ) ;
F_59 ( L_22 , L_26 , V_2 -> V_27 >> 16 ) ;
F_59 ( L_27 , L_28 , V_2 -> V_28 ) ;
F_59 ( L_29 , L_30 , V_2 -> V_29 ) ;
F_59 ( L_31 , L_32 , V_2 -> V_291 ) ;
F_59 ( L_29 , L_33 , V_2 -> V_262 ) ;
F_59 ( L_29 , L_34 , V_2 -> V_263 ) ;
F_59 ( L_29 , L_35 , V_2 -> V_210 ) ;
F_59 ( L_31 , L_36 , V_2 -> V_58 ) ;
F_59 ( L_31 , L_37 , V_2 -> V_408 ) ;
F_59 ( L_27 , L_38 , V_2 -> V_221 ) ;
F_59 ( L_27 , L_39 , V_2 -> V_498 ) ;
F_59 ( L_27 , L_40 , V_2 -> V_73 ) ;
F_59 ( L_27 , L_41 , V_2 -> V_457 ) ;
F_59 ( L_29 , L_42 , V_2 -> V_419 ) ;
F_59 ( L_29 , L_43 , V_2 -> V_417 ) ;
F_59 ( L_27 , L_44 , V_2 -> V_499 ) ;
F_59 ( L_27 , L_45 , V_2 -> V_500 ) ;
F_59 ( L_46 , L_47 , V_2 -> V_286 ) ;
F_59 ( L_29 , L_48 , V_2 -> V_451 ) ;
F_59 ( L_29 , L_49 , V_2 -> V_12 ) ;
F_59 ( L_27 , L_50 , V_2 -> V_97 ) ;
F_59 ( L_27 , L_51 , V_2 -> V_100 ) ;
F_59 ( L_46 , L_52 , V_2 -> V_165 ) ;
F_59 ( L_29 , L_53 , V_2 -> V_78 ) ;
F_59 ( L_29 , L_54 , V_2 -> V_212 ) ;
F_59 ( L_29 , L_55 , V_2 -> V_218 ) ;
F_59 ( L_29 , L_56 , V_2 -> V_219 ) ;
F_59 ( L_57 ) ;
F_59 ( L_58 ,
L_59 ,
V_65 -> V_265 . V_203 , V_65 -> V_265 . V_204 ,
V_65 -> V_265 . V_208 , V_65 -> V_265 . V_95 ) ;
F_59 ( L_58 ,
L_60 ,
V_65 -> V_94 . V_203 , V_65 -> V_94 . V_204 ,
V_65 -> V_94 . V_208 , V_65 -> V_94 . V_95 ) ;
F_59 ( L_58 ,
L_61 ,
V_65 -> V_266 . V_203 , V_65 -> V_266 . V_204 ,
V_65 -> V_266 . V_208 , V_65 -> V_266 . V_95 ) ;
F_59 ( L_58 ,
L_62 ,
V_65 -> V_267 . V_203 , V_65 -> V_267 . V_204 ,
V_65 -> V_267 . V_208 , V_65 -> V_267 . V_95 ) ;
F_59 ( L_58 ,
L_63 ,
V_65 -> V_268 . V_203 , V_65 -> V_268 . V_204 ,
V_65 -> V_268 . V_208 , V_65 -> V_268 . V_95 ) ;
F_59 ( L_58 ,
L_64 ,
V_65 -> V_269 . V_203 , V_65 -> V_269 . V_204 ,
V_65 -> V_269 . V_208 , V_65 -> V_269 . V_95 ) ;
F_59 ( L_58 ,
L_65 ,
V_65 -> V_272 . V_203 , V_65 -> V_272 . V_204 ,
V_65 -> V_272 . V_208 , V_65 -> V_272 . V_95 ) ;
F_59 ( L_58 ,
L_66 ,
V_65 -> V_274 . V_203 , V_65 -> V_274 . V_204 ,
V_65 -> V_274 . V_208 , V_65 -> V_274 . V_95 ) ;
F_59 ( L_58 ,
L_67 ,
V_65 -> V_273 . V_203 , V_65 -> V_273 . V_204 ,
V_65 -> V_273 . V_208 , V_65 -> V_273 . V_95 ) ;
F_59 ( L_58 ,
L_68 ,
V_65 -> V_276 . V_203 , V_65 -> V_276 . V_204 ,
V_65 -> V_276 . V_208 , V_65 -> V_276 . V_95 ) ;
F_59 ( L_69 ,
V_65 -> V_387 , V_65 -> V_61 ) ;
F_59 ( L_70 ,
L_71 , V_65 -> V_392 , L_72 , V_65 -> V_469 ) ;
F_59 ( L_70 ,
L_73 , V_65 -> V_289 , L_74 , V_65 -> V_284 ) ;
F_59 ( L_70 ,
L_75 , V_65 -> V_278 , L_76 , V_65 -> V_413 ) ;
F_59 ( L_70 ,
L_77 , V_65 -> V_91 , L_78 , V_65 -> V_357 ) ;
F_59 ( L_70 ,
L_79 , V_65 -> V_503 , L_80 , V_65 -> V_504 ) ;
F_59 ( L_70 ,
L_81 , V_65 -> V_516 , L_82 , V_65 -> V_517 ) ;
F_59 ( L_70 ,
L_83 , V_65 -> V_518 , L_84 , V_65 -> V_519 ) ;
F_59 ( L_70 ,
L_85 , V_65 -> V_515 ,
L_86 , V_65 -> V_520 ) ;
F_59 ( L_70 ,
L_87 , V_65 -> V_521 ,
L_88 , V_65 -> V_522 ) ;
F_59 ( L_70 ,
L_89 , V_65 -> V_287 , L_90 , V_65 -> V_579 ) ;
F_59 ( L_70 ,
L_91 , V_65 -> V_580 , L_92 , V_65 -> V_581 ) ;
F_59 ( L_70 ,
L_93 , V_65 -> V_582 ,
L_94 , V_65 -> V_583 ) ;
}
static void F_372 ( struct V_8 * V_9 , T_1 * V_654 , T_1 * V_655 )
{
struct V_18 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_654 = V_2 -> V_419 ;
* V_655 = V_2 -> V_417 ;
}
static int F_373 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_424 * V_424 = V_9 -> V_425 ;
T_2 V_457 = V_10 -> V_1 -> V_2 . V_457 ;
F_374 ( V_457 , V_9 , V_502 ) ;
V_9 -> V_46 . V_656 = ( V_457 == V_458 ) ;
if ( ! F_14 ( V_10 , V_228 ) )
V_9 -> V_46 . V_392 = V_10 -> V_1 -> V_65 . V_392 ;
if ( V_62 )
V_9 -> V_46 . V_289 = V_10 -> V_1 -> V_65 . V_289 ;
if ( F_161 ( V_10 -> V_24 . V_471 ) ) {
F_244 ( V_10 ) ;
V_10 -> V_24 . V_471 = false ;
return 1 ;
}
if ( F_10 ( V_9 ) ) {
int V_467 ;
F_375 ( V_10 -> V_1 -> V_65 . V_91 , V_457 ,
V_10 -> V_1 -> V_2 . V_419 ,
V_10 -> V_1 -> V_2 . V_417 ,
V_10 -> V_1 -> V_2 . V_499 ,
V_10 -> V_1 -> V_2 . V_500 ,
V_502 ) ;
V_467 = F_267 ( V_10 ) ;
if ( V_467 == V_484 )
V_467 = F_268 ( V_10 ) ;
if ( V_467 == V_470 )
return 1 ;
}
F_376 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_457 == V_492 ) {
V_424 -> V_431 = V_657 ;
V_424 -> V_658 . V_659
= V_10 -> V_1 -> V_2 . V_457 ;
F_59 ( L_95 ) ;
F_371 ( V_9 ) ;
return 0 ;
}
if ( F_31 ( V_10 -> V_1 -> V_2 . V_499 ) &&
V_457 != V_468 + V_232 &&
V_457 != V_458 && V_457 != V_660 &&
V_457 != V_474 && V_457 != V_475 )
F_38 ( V_85 L_96
L_97 ,
V_83 , V_10 -> V_1 -> V_2 . V_499 ,
V_457 ) ;
if ( V_457 >= F_377 ( V_661 )
|| ! V_661 [ V_457 ] ) {
F_358 ( 1 , L_98 , V_457 ) ;
F_215 ( V_9 , V_233 ) ;
return 1 ;
}
return V_661 [ V_457 ] ( V_10 ) ;
}
static void F_378 ( struct V_8 * V_9 )
{
int V_147 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_130 , V_147 ) ;
V_121 -> V_136 -> type = 9 ;
F_379 () ;
}
static void F_380 ( struct V_7 * V_10 )
{
int V_147 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_130 , V_147 ) ;
if ( V_10 -> V_131 != V_121 -> V_131 )
F_199 ( V_10 , V_121 ) ;
}
static void F_381 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_97 = V_70 | V_662 ;
V_9 -> V_46 . V_47 |= V_663 ;
F_19 ( V_10 , V_556 ) ;
++ V_9 -> V_351 . V_664 ;
}
static inline void F_382 ( struct V_7 * V_10 , int V_665 )
{
struct V_18 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_498 = V_665 ;
V_2 -> V_221 &= ~ V_666 ;
V_2 -> V_221 |= V_525 |
( ( 0xf ) << V_667 ) ;
F_3 ( V_10 -> V_1 , V_526 ) ;
}
static void F_383 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_76 ( ! ( F_23 ( V_10 ) ) ) ;
F_384 ( V_9 -> V_46 . V_668 . V_86 ) ;
++ V_9 -> V_351 . V_669 ;
V_10 -> V_1 -> V_2 . V_97 = V_9 -> V_46 . V_668 . V_86 |
V_70 | V_71 ;
}
static inline bool F_385 ( struct V_8 * V_9 )
{
return F_10 ( V_9 ) && ( V_9 -> V_46 . V_47 & V_472 ) ;
}
static void F_386 ( struct V_8 * V_9 , int V_670 , int V_671 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_385 ( V_9 ) ||
F_115 ( V_9 ) )
return;
F_13 ( V_10 , V_231 ) ;
if ( V_671 == - 1 )
return;
if ( V_670 >= V_671 )
F_12 ( V_10 , V_231 ) ;
}
static void F_387 ( struct V_8 * V_9 , bool V_672 )
{
return;
}
static bool F_388 ( void )
{
return V_198 ;
}
static void F_389 ( struct V_8 * V_9 , int V_673 )
{
}
static void F_390 ( struct V_8 * V_9 , int V_674 )
{
}
static void F_391 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( ! V_198 )
return;
V_1 -> V_2 . V_221 &= ~ V_222 ;
F_3 ( V_1 , V_526 ) ;
}
static void F_392 ( struct V_8 * V_9 , T_1 * V_675 )
{
return;
}
static void F_393 ( struct V_8 * V_9 , int V_676 )
{
F_394 ( V_676 , V_9 -> V_46 . V_299 ) ;
F_395 () ;
if ( F_7 ( V_9 ) )
F_53 ( V_677 ,
F_144 ( V_9 -> V_147 ) ) ;
else
F_93 ( V_9 ) ;
}
static void F_396 ( struct V_7 * V_10 , struct V_678 * V_679 )
{
unsigned long V_171 ;
struct V_312 * V_680 ;
F_89 ( & V_10 -> V_314 , V_171 ) ;
F_141 (cur, &svm->ir_list, node) {
if ( V_680 -> V_11 != V_679 -> V_681 )
continue;
F_397 ( & V_680 -> V_682 ) ;
F_69 ( V_680 ) ;
break;
}
F_92 ( & V_10 -> V_314 , V_171 ) ;
}
static int F_398 ( struct V_7 * V_10 , struct V_678 * V_679 )
{
int V_72 = 0 ;
unsigned long V_171 ;
struct V_312 * V_313 ;
if ( V_679 -> V_681 && ( V_679 -> V_683 != 0 ) ) {
struct V_177 * V_177 = V_10 -> V_9 . V_177 ;
T_2 V_175 = F_87 ( V_679 -> V_683 ) ;
struct V_8 * V_684 = F_91 ( V_177 , V_175 ) ;
struct V_7 * V_685 ;
if ( ! V_684 ) {
V_72 = - V_129 ;
goto V_316;
}
V_685 = F_4 ( V_684 ) ;
F_396 ( V_685 , V_679 ) ;
}
V_313 = F_71 ( sizeof( struct V_312 ) , V_149 ) ;
if ( ! V_313 ) {
V_72 = - V_150 ;
goto V_316;
}
V_313 -> V_11 = V_679 -> V_681 ;
F_89 ( & V_10 -> V_314 , V_171 ) ;
F_399 ( & V_313 -> V_682 , & V_10 -> V_315 ) ;
F_92 ( & V_10 -> V_314 , V_171 ) ;
V_316:
return V_72 ;
}
static int
F_400 ( struct V_177 * V_177 , struct V_686 * V_687 ,
struct V_688 * V_689 , struct V_7 * * V_10 )
{
struct V_690 V_665 ;
struct V_8 * V_9 = NULL ;
F_401 ( V_177 , V_687 , & V_665 ) ;
if ( ! F_402 ( V_177 , & V_665 , & V_9 ) ) {
F_88 ( L_99 ,
V_83 , V_665 . V_650 ) ;
return - 1 ;
}
F_88 ( L_100 , V_83 ,
V_665 . V_650 ) ;
* V_10 = F_4 ( V_9 ) ;
V_689 -> V_691 = F_113 ( ( * V_10 ) -> V_212 ) ;
V_689 -> V_650 = V_665 . V_650 ;
return 0 ;
}
static int F_403 ( struct V_177 * V_177 , unsigned int V_692 ,
T_7 V_693 , bool V_672 )
{
struct V_686 * V_687 ;
struct V_694 * V_695 ;
int V_696 , V_72 = - V_129 ;
if ( ! F_139 ( V_177 ) ||
! F_404 ( V_697 ) )
return 0 ;
F_88 ( L_101 ,
V_83 , V_692 , V_693 , V_672 ) ;
V_696 = F_405 ( & V_177 -> V_698 ) ;
V_695 = F_406 ( V_177 -> V_699 , & V_177 -> V_698 ) ;
F_75 ( V_693 >= V_695 -> V_700 ) ;
F_407 (e, &irq_rt->map[guest_irq], link) {
struct V_688 V_689 ;
struct V_7 * V_10 = NULL ;
if ( V_687 -> type != V_701 )
continue;
if ( ! F_400 ( V_177 , V_687 , & V_689 , & V_10 ) && V_672 &&
F_115 ( & V_10 -> V_9 ) ) {
struct V_678 V_679 ;
V_679 . V_95 = F_113 ( V_10 -> V_212 ) & V_217 ;
V_679 . V_170 = F_408 ( V_177 -> V_46 . V_179 ,
V_10 -> V_9 . V_175 ) ;
V_679 . F_10 = true ;
V_679 . V_688 = & V_689 ;
V_72 = F_409 ( V_692 , & V_679 ) ;
if ( ! V_72 && V_679 . F_10 )
F_398 ( V_10 , & V_679 ) ;
} else {
struct V_678 V_679 ;
V_679 . F_10 = false ;
V_72 = F_409 ( V_692 , & V_679 ) ;
if ( ! V_72 && V_679 . V_683 ) {
int V_298 = F_87 ( V_679 . V_683 ) ;
struct V_8 * V_9 ;
V_9 = F_91 ( V_177 , V_298 ) ;
if ( V_9 )
F_396 ( F_4 ( V_9 ) , & V_679 ) ;
}
}
if ( ! V_72 && V_10 ) {
F_410 ( V_10 -> V_9 . V_175 ,
V_692 , V_687 -> V_702 ,
V_689 . V_650 ,
V_689 . V_691 , V_672 ) ;
}
if ( V_72 < 0 ) {
F_59 ( L_102 , V_83 ) ;
goto V_316;
}
}
V_72 = 0 ;
V_316:
F_411 ( & V_177 -> V_698 , V_696 ) ;
return V_72 ;
}
static int F_412 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
V_72 = ! ( V_1 -> V_2 . V_73 & V_74 ) &&
! ( V_10 -> V_9 . V_46 . V_47 & V_663 ) ;
V_72 = V_72 && F_23 ( V_10 ) && F_255 ( V_10 ) ;
return V_72 ;
}
static bool F_413 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_46 . V_47 & V_663 ) ;
}
static void F_414 ( struct V_8 * V_9 , bool V_703 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_703 ) {
V_10 -> V_9 . V_46 . V_47 |= V_663 ;
F_19 ( V_10 , V_556 ) ;
} else {
V_10 -> V_9 . V_46 . V_47 &= ~ V_663 ;
F_20 ( V_10 , V_556 ) ;
}
}
static int F_415 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
if ( ! F_23 ( V_10 ) ||
( V_1 -> V_2 . V_73 & V_74 ) )
return 0 ;
V_72 = ! ! ( F_273 ( V_9 ) & V_512 ) ;
if ( F_10 ( V_9 ) )
return V_72 && ! ( V_10 -> V_9 . V_46 . V_47 & V_472 ) ;
return V_72 ;
}
static void F_416 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_115 ( V_9 ) )
return;
if ( F_23 ( V_10 ) && F_253 ( V_10 ) ) {
F_178 ( V_10 ) ;
F_382 ( V_10 , 0x0 ) ;
}
}
static void F_417 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_46 . V_47 & ( V_663 | V_557 ) )
== V_663 )
return;
V_10 -> V_428 = true ;
V_10 -> V_1 -> V_65 . V_357 |= ( V_429 | V_430 ) ;
}
static int F_418 ( struct V_177 * V_177 , unsigned int V_57 )
{
return 0 ;
}
static void F_196 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_36 ( V_704 ) )
V_10 -> V_1 -> V_2 . V_408 = V_705 ;
else
V_10 -> V_131 -- ;
}
static void F_419 ( struct V_8 * V_9 )
{
}
static inline void F_420 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_385 ( V_9 ) )
return;
if ( ! F_14 ( V_10 , V_231 ) ) {
int V_706 = V_10 -> V_1 -> V_2 . V_221 & V_707 ;
F_316 ( V_9 , V_706 ) ;
}
}
static inline void F_421 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_706 ;
if ( F_385 ( V_9 ) ||
F_115 ( V_9 ) )
return;
V_706 = F_319 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_221 &= ~ V_707 ;
V_10 -> V_1 -> V_2 . V_221 |= V_706 & V_707 ;
}
static void F_376 ( struct V_7 * V_10 )
{
T_4 V_650 ;
int type ;
T_2 V_708 = V_10 -> V_1 -> V_2 . V_499 ;
unsigned V_96 = V_10 -> V_96 ;
V_10 -> V_96 = 0 ;
if ( ( V_10 -> V_9 . V_46 . V_47 & V_557 )
&& F_39 ( & V_10 -> V_9 ) != V_10 -> V_558 ) {
V_10 -> V_9 . V_46 . V_47 &= ~ ( V_663 | V_557 ) ;
F_224 ( V_524 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_46 . V_543 = false ;
F_274 ( & V_10 -> V_9 ) ;
F_275 ( & V_10 -> V_9 ) ;
if ( ! ( V_708 & V_535 ) )
return;
F_224 ( V_524 , & V_10 -> V_9 ) ;
V_650 = V_708 & V_709 ;
type = V_708 & V_531 ;
switch ( type ) {
case V_542 :
V_10 -> V_9 . V_46 . V_543 = true ;
break;
case V_544 :
if ( F_422 ( V_650 ) ) {
if ( V_650 == V_90 && V_96 &&
F_423 ( & V_10 -> V_9 , V_10 -> V_93 ) )
F_40 ( & V_10 -> V_9 ,
F_39 ( & V_10 -> V_9 ) -
V_96 ) ;
break;
}
if ( V_708 & V_710 ) {
T_2 V_103 = V_10 -> V_1 -> V_2 . V_500 ;
F_424 ( & V_10 -> V_9 , V_650 , V_103 ) ;
} else
F_425 ( & V_10 -> V_9 , V_650 ) ;
break;
case V_546 :
F_426 ( & V_10 -> V_9 , V_650 , false ) ;
break;
default:
break;
}
}
static void F_427 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_499 = V_2 -> V_97 ;
V_2 -> V_500 = V_2 -> V_100 ;
V_2 -> V_97 = 0 ;
F_376 ( V_10 ) ;
}
static void F_428 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_504 = V_9 -> V_46 . V_279 [ V_508 ] ;
V_10 -> V_1 -> V_65 . V_503 = V_9 -> V_46 . V_279 [ V_509 ] ;
V_10 -> V_1 -> V_65 . V_91 = V_9 -> V_46 . V_279 [ V_280 ] ;
if ( F_161 ( V_10 -> V_24 . V_471 ) )
return;
F_380 ( V_10 ) ;
F_421 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_469 = V_9 -> V_46 . V_469 ;
F_25 () ;
F_212 () ;
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
F_53 ( V_339 , V_10 -> V_340 . V_341 ) ;
#else
F_167 ( V_268 , V_10 -> V_340 . V_268 ) ;
#ifndef F_169
F_167 ( V_269 , V_10 -> V_340 . V_269 ) ;
#endif
#endif
F_378 ( V_9 ) ;
F_210 () ;
V_9 -> V_46 . V_469 = V_10 -> V_1 -> V_65 . V_469 ;
V_9 -> V_46 . V_279 [ V_508 ] = V_10 -> V_1 -> V_65 . V_504 ;
V_9 -> V_46 . V_279 [ V_509 ] = V_10 -> V_1 -> V_65 . V_503 ;
V_9 -> V_46 . V_279 [ V_280 ] = V_10 -> V_1 -> V_65 . V_91 ;
if ( F_161 ( V_10 -> V_1 -> V_2 . V_457 == V_475 ) )
F_429 ( & V_10 -> V_9 ) ;
F_26 () ;
if ( F_161 ( V_10 -> V_1 -> V_2 . V_457 == V_475 ) )
F_430 ( & V_10 -> V_9 ) ;
F_420 ( V_9 ) ;
V_10 -> V_78 = 0 ;
V_10 -> V_1 -> V_2 . V_408 = V_711 ;
if ( V_10 -> V_1 -> V_2 . V_457 == V_468 + V_232 )
V_10 -> V_418 = F_431 () ;
if ( V_62 ) {
V_9 -> V_46 . V_712 &= ~ ( 1 << V_360 ) ;
V_9 -> V_46 . V_713 &= ~ ( 1 << V_360 ) ;
}
if ( F_161 ( V_10 -> V_1 -> V_2 . V_457 ==
V_468 + V_234 ) )
F_223 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_432 ( struct V_8 * V_9 , unsigned long V_453 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_289 = V_453 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_196 ( V_9 ) ;
}
static void F_433 ( struct V_8 * V_9 , unsigned long V_453 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_451 = V_453 ;
F_3 ( V_10 -> V_1 , V_454 ) ;
V_10 -> V_1 -> V_65 . V_289 = F_177 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_196 ( V_9 ) ;
}
static int F_434 ( void )
{
T_1 V_714 ;
F_58 ( V_585 , V_714 ) ;
if ( V_714 & ( 1 << V_715 ) )
return 1 ;
return 0 ;
}
static void
F_435 ( struct V_8 * V_9 , unsigned char * V_716 )
{
V_716 [ 0 ] = 0x0f ;
V_716 [ 1 ] = 0x01 ;
V_716 [ 2 ] = 0xd9 ;
}
static void F_436 ( void * V_717 )
{
* ( int * ) V_717 = 0 ;
}
static bool F_437 ( void )
{
return false ;
}
static bool F_438 ( void )
{
return true ;
}
static T_1 F_439 ( struct V_8 * V_9 , T_11 V_718 , bool V_719 )
{
return 0 ;
}
static void F_440 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_720 * V_15 ;
V_10 -> V_505 = ! ! F_441 ( & V_10 -> V_9 ) ;
if ( ! F_115 ( V_9 ) )
return;
V_15 = F_442 ( V_9 , 1 , 0 ) ;
if ( V_15 )
V_15 -> V_591 &= ~ V_6 ( V_721 ) ;
}
static void F_443 ( T_2 V_722 , struct V_720 * V_15 )
{
switch ( V_722 ) {
case 0x1 :
if ( V_198 )
V_15 -> V_591 &= ~ V_6 ( V_721 ) ;
break;
case 0x80000001 :
if ( V_24 )
V_15 -> V_591 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_15 -> V_323 = 1 ;
V_15 -> V_723 = 8 ;
V_15 -> V_591 = 0 ;
V_15 -> V_724 = 0 ;
if ( F_97 ( V_79 ) )
V_15 -> V_724 |= V_725 ;
if ( V_62 )
V_15 -> V_724 |= V_726 ;
break;
}
}
static int F_444 ( void )
{
return V_727 ;
}
static bool F_445 ( void )
{
return F_97 ( V_348 ) ;
}
static bool F_446 ( void )
{
return false ;
}
static bool F_447 ( void )
{
return false ;
}
static bool F_448 ( void )
{
return false ;
}
static bool F_449 ( void )
{
return true ;
}
static int F_450 ( struct V_8 * V_9 ,
struct V_728 * V_68 ,
enum V_729 V_730 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_467 , V_72 = V_731 ;
struct V_732 V_733 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_68 -> V_29 >= F_377 ( V_734 ) )
goto V_316;
V_733 = V_734 [ V_68 -> V_29 ] ;
if ( V_730 != V_733 . V_730 )
goto V_316;
switch ( V_733 . V_457 ) {
case V_487 :
if ( V_68 -> V_29 == V_735 )
V_733 . V_457 += V_68 -> V_736 ;
break;
case V_564 : {
unsigned long V_392 , V_104 ;
T_1 V_29 ;
if ( V_68 -> V_29 == V_737 )
V_733 . V_457 += V_68 -> V_736 ;
if ( V_733 . V_457 != V_564 ||
V_68 -> V_29 == V_738 )
break;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! ( V_29 & ( 1ULL << V_240 ) ) )
break;
V_392 = V_9 -> V_46 . V_392 & ~ V_394 ;
V_104 = V_68 -> V_739 & ~ V_394 ;
if ( V_68 -> V_29 == V_740 ) {
V_392 &= 0xfUL ;
V_104 &= 0xfUL ;
if ( V_392 & V_507 )
V_104 |= V_507 ;
}
if ( V_392 ^ V_104 )
V_733 . V_457 = V_560 ;
break;
}
case V_489 :
case V_741 :
V_733 . V_457 += V_68 -> V_736 ;
break;
case V_485 :
if ( V_68 -> V_29 == V_742 )
V_1 -> V_2 . V_419 = 1 ;
else
V_1 -> V_2 . V_419 = 0 ;
break;
case V_743 :
if ( V_68 -> V_744 != V_745 )
goto V_316;
case V_486 : {
T_1 V_746 ;
T_2 V_747 ;
if ( V_68 -> V_29 == V_748 ||
V_68 -> V_29 == V_749 ) {
V_746 = ( ( V_68 -> V_739 & 0xffff ) << 16 ) |
V_447 ;
V_747 = V_68 -> V_750 ;
} else {
V_746 = ( V_68 -> V_751 & 0xffff ) << 16 ;
V_747 = V_68 -> V_752 ;
}
if ( V_68 -> V_29 == V_753 ||
V_68 -> V_29 == V_749 )
V_746 |= V_446 ;
if ( V_68 -> V_744 )
V_746 |= V_754 ;
V_747 = F_451 ( V_747 , 4u ) ;
V_746 |= V_747 << V_449 ;
V_746 |= ( T_2 ) V_68 -> V_755 << ( V_756 - 1 ) ;
V_1 -> V_2 . V_419 = V_746 ;
V_1 -> V_2 . V_417 = V_68 -> V_78 ;
break;
}
default:
break;
}
if ( F_36 ( V_79 ) )
V_1 -> V_2 . V_78 = V_68 -> V_78 ;
V_1 -> V_2 . V_457 = V_733 . V_457 ;
V_467 = F_268 ( V_10 ) ;
V_72 = ( V_467 == V_470 ) ? V_757
: V_731 ;
V_316:
return V_72 ;
}
static void F_452 ( struct V_8 * V_9 )
{
F_212 () ;
asm("nop");
F_210 () ;
}
static void F_453 ( struct V_8 * V_9 , int V_147 )
{
}
static inline void F_454 ( struct V_8 * V_9 )
{
if ( F_365 ( V_9 ) != 0 )
return;
if ( F_366 ( V_9 ) != 0 )
return;
F_364 ( V_9 ) ;
}
static int T_5 F_455 ( void )
{
return F_456 ( & V_758 , sizeof( struct V_7 ) ,
F_457 ( struct V_7 ) , V_759 ) ;
}
static void T_6 F_458 ( void )
{
F_459 () ;
}
