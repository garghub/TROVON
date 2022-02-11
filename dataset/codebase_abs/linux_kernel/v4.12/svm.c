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
struct V_122 * V_123 ;
int V_124 = F_57 () ;
F_58 ( V_125 , V_61 ) ;
if ( V_61 & V_66 )
return - V_126 ;
if ( ! F_50 () ) {
F_59 ( L_4 , V_83 , V_124 ) ;
return - V_127 ;
}
V_121 = F_60 ( V_128 , V_124 ) ;
if ( ! V_121 ) {
F_59 ( L_5 , V_83 , V_124 ) ;
return - V_127 ;
}
V_121 -> V_129 = 1 ;
V_121 -> V_130 = F_61 ( V_131 ) - 1 ;
V_121 -> V_132 = V_121 -> V_130 + 1 ;
V_123 = F_62 () ;
V_121 -> V_133 = (struct V_134 * ) ( V_123 + V_135 ) ;
F_53 ( V_125 , V_61 | V_66 ) ;
F_53 ( V_136 , F_63 ( V_121 -> V_137 ) << V_138 ) ;
if ( F_36 ( V_117 ) ) {
F_53 ( V_118 , V_119 ) ;
F_64 ( V_139 , V_119 ) ;
}
if ( F_65 ( & V_113 , V_140 ) ) {
T_3 V_141 , V_111 = 0 ;
int V_103 ;
V_141 = F_45 ( V_142 , & V_103 ) ;
if ( ! V_103 )
V_111 = F_45 ( V_143 ,
& V_103 ) ;
if ( V_103 )
V_112 = V_110 = 0 ;
else {
if ( V_141 < V_110 )
V_110 = V_141 ;
V_112 |= V_111 ;
V_112 &= ( 1ULL << V_110 ) - 1 ;
}
} else
V_112 = V_110 = 0 ;
F_43 () ;
F_66 () ;
return 0 ;
}
static void F_67 ( int V_144 )
{
struct V_120 * V_121 = F_60 ( V_128 , F_57 () ) ;
if ( ! V_121 )
return;
F_60 ( V_128 , F_57 () ) = NULL ;
F_68 ( V_121 -> V_137 ) ;
F_69 ( V_121 ) ;
}
static int F_70 ( int V_144 )
{
struct V_120 * V_121 ;
int V_145 ;
V_121 = F_71 ( sizeof( struct V_120 ) , V_146 ) ;
if ( ! V_121 )
return - V_147 ;
V_121 -> V_144 = V_144 ;
V_121 -> V_137 = F_72 ( V_146 ) ;
V_145 = - V_147 ;
if ( ! V_121 -> V_137 )
goto V_148;
F_60 ( V_128 , V_144 ) = V_121 ;
return 0 ;
V_148:
F_69 ( V_121 ) ;
return V_145 ;
}
static bool F_73 ( T_2 V_149 )
{
int V_51 ;
for ( V_51 = 0 ; V_150 [ V_51 ] . V_149 != V_56 ; V_51 ++ )
if ( V_150 [ V_51 ] . V_149 == V_149 )
return true ;
return false ;
}
static void F_74 ( T_2 * V_151 , unsigned V_49 ,
int V_152 , int V_153 )
{
T_4 V_154 , V_155 ;
unsigned long V_156 ;
T_2 V_50 ;
F_75 ( ! F_73 ( V_49 ) ) ;
V_50 = F_24 ( V_49 ) ;
V_154 = 2 * ( V_49 & 0x0f ) ;
V_155 = 2 * ( V_49 & 0x0f ) + 1 ;
V_156 = V_151 [ V_50 ] ;
F_76 ( V_50 == V_56 ) ;
V_152 ? F_77 ( V_154 , & V_156 ) : F_78 ( V_154 , & V_156 ) ;
V_153 ? F_77 ( V_155 , & V_156 ) : F_78 ( V_155 , & V_156 ) ;
V_151 [ V_50 ] = V_156 ;
}
static void F_79 ( T_2 * V_151 )
{
int V_51 ;
memset ( V_151 , 0xff , V_157 * ( 1 << V_158 ) ) ;
for ( V_51 = 0 ; V_150 [ V_51 ] . V_149 != V_56 ; V_51 ++ ) {
if ( ! V_150 [ V_51 ] . V_159 )
continue;
F_74 ( V_151 , V_150 [ V_51 ] . V_149 , 1 , 1 ) ;
}
}
static void F_80 ( T_2 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_160 ; ++ V_51 ) {
if ( V_161 [ V_51 ] == V_50 )
return;
if ( V_161 [ V_51 ] != V_56 )
continue;
V_161 [ V_51 ] = V_50 ;
return;
}
F_81 () ;
}
static void F_82 ( void )
{
int V_51 ;
memset ( V_161 , 0xff , sizeof( V_161 ) ) ;
for ( V_51 = 0 ; V_150 [ V_51 ] . V_149 != V_56 ; V_51 ++ ) {
T_2 V_50 ;
V_50 = F_24 ( V_150 [ V_51 ] . V_149 ) ;
F_76 ( V_50 == V_56 ) ;
F_80 ( V_50 ) ;
}
}
static void F_83 ( struct V_7 * V_10 )
{
T_2 * V_151 = V_10 -> V_151 ;
V_10 -> V_1 -> V_2 . V_162 = 1 ;
F_74 ( V_151 , V_163 , 1 , 1 ) ;
F_74 ( V_151 , V_164 , 1 , 1 ) ;
F_74 ( V_151 , V_165 , 1 , 1 ) ;
F_74 ( V_151 , V_166 , 1 , 1 ) ;
}
static void F_84 ( struct V_7 * V_10 )
{
T_2 * V_151 = V_10 -> V_151 ;
V_10 -> V_1 -> V_2 . V_162 = 0 ;
F_74 ( V_151 , V_163 , 0 , 0 ) ;
F_74 ( V_151 , V_164 , 0 , 0 ) ;
F_74 ( V_151 , V_165 , 0 , 0 ) ;
F_74 ( V_151 , V_166 , 0 , 0 ) ;
}
static int F_85 ( T_2 V_167 )
{
unsigned long V_168 ;
struct V_169 * V_170 = NULL ;
struct V_8 * V_9 = NULL ;
T_2 V_171 = F_86 ( V_167 ) ;
T_2 V_172 = F_87 ( V_167 ) ;
F_88 ( L_6 , V_83 , V_171 , V_172 ) ;
F_89 ( & V_173 , V_168 ) ;
F_90 (svm_vm_data_hash, ka, hnode, vm_id) {
struct V_174 * V_174 = F_5 ( V_170 , struct V_174 , V_46 ) ;
struct V_169 * V_175 = & V_174 -> V_46 ;
if ( V_175 -> V_176 != V_171 )
continue;
V_9 = F_91 ( V_174 , V_172 ) ;
break;
}
F_92 ( & V_173 , V_168 ) ;
if ( ! V_9 )
return 0 ;
if ( V_9 -> V_177 == V_178 )
F_93 ( V_9 ) ;
return 0 ;
}
static T_5 int F_94 ( void )
{
int V_144 ;
struct V_179 * V_180 ;
void * V_181 ;
int V_145 ;
V_180 = F_95 ( V_146 , V_182 ) ;
if ( ! V_180 )
return - V_147 ;
V_181 = F_96 ( V_180 ) ;
memset ( V_181 , 0xff , V_157 * ( 1 << V_182 ) ) ;
V_183 = F_63 ( V_180 ) << V_138 ;
F_82 () ;
if ( F_97 ( V_184 ) )
F_98 ( V_185 ) ;
if ( F_97 ( V_186 ) )
F_98 ( V_187 ) ;
if ( F_97 ( V_117 ) ) {
V_188 = true ;
V_189 = V_190 ;
V_191 = 32 ;
}
if ( V_24 ) {
F_38 ( V_116 L_7 ) ;
F_98 ( V_66 | V_192 ) ;
}
F_99 (cpu) {
V_145 = F_70 ( V_144 ) ;
if ( V_145 )
goto V_103;
}
if ( ! F_97 ( V_193 ) )
V_62 = false ;
if ( V_62 && ! V_194 ) {
F_38 ( V_116 L_8 ) ;
V_62 = false ;
}
if ( V_62 ) {
F_38 ( V_116 L_9 ) ;
F_100 () ;
} else
F_101 () ;
if ( V_195 ) {
if ( ! V_62 ||
! F_97 ( V_196 ) ||
! F_102 ( V_197 ) ) {
V_195 = false ;
} else {
F_103 ( L_10 ) ;
F_104 ( & F_85 ) ;
}
}
return 0 ;
V_103:
F_105 ( V_180 , V_182 ) ;
V_183 = 0 ;
return V_145 ;
}
static T_6 void F_106 ( void )
{
int V_144 ;
F_99 (cpu)
F_67 ( V_144 ) ;
F_105 ( F_107 ( V_183 >> V_138 ) , V_182 ) ;
V_183 = 0 ;
}
static void F_108 ( struct V_198 * V_199 )
{
V_199 -> V_200 = 0 ;
V_199 -> V_201 = V_202 | V_203 |
V_204 ;
V_199 -> V_205 = 0xffff ;
V_199 -> V_95 = 0 ;
}
static void F_109 ( struct V_198 * V_199 , T_7 type )
{
V_199 -> V_200 = 0 ;
V_199 -> V_201 = V_202 | type ;
V_199 -> V_205 = 0xffff ;
V_199 -> V_95 = 0 ;
}
static void F_110 ( struct V_8 * V_9 , T_1 V_50 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_206 = 0 ;
if ( F_10 ( V_9 ) ) {
V_206 = V_10 -> V_1 -> V_2 . V_207 -
V_10 -> V_24 . V_25 -> V_2 . V_207 ;
V_10 -> V_24 . V_25 -> V_2 . V_207 = V_50 ;
} else
F_111 ( V_9 -> V_172 ,
V_10 -> V_1 -> V_2 . V_207 ,
V_50 ) ;
V_10 -> V_1 -> V_2 . V_207 = V_50 + V_206 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_112 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_169 * V_175 = & V_10 -> V_9 . V_174 -> V_46 ;
T_8 V_208 = F_113 ( V_10 -> V_209 ) ;
T_8 V_210 = F_113 ( V_175 -> V_211 ) ;
T_8 V_212 = F_113 ( V_175 -> V_213 ) ;
V_1 -> V_2 . V_209 = V_208 & V_214 ;
V_1 -> V_2 . V_215 = V_210 & V_214 ;
V_1 -> V_2 . V_216 = V_212 & V_214 ;
V_1 -> V_2 . V_216 |= V_217 ;
V_1 -> V_2 . V_218 |= V_219 ;
V_10 -> V_9 . V_46 . V_220 = true ;
}
static void F_114 ( struct V_7 * V_10 )
{
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_221 * V_65 = & V_10 -> V_1 -> V_65 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
F_12 ( V_10 , V_222 ) ;
F_12 ( V_10 , V_223 ) ;
F_12 ( V_10 , V_224 ) ;
F_12 ( V_10 , V_225 ) ;
F_12 ( V_10 , V_226 ) ;
F_12 ( V_10 , V_227 ) ;
if ( ! F_115 ( & V_10 -> V_9 ) )
F_12 ( V_10 , V_228 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_229 ) ;
F_17 ( V_10 , V_230 ) ;
F_17 ( V_10 , V_231 ) ;
F_17 ( V_10 , V_232 ) ;
F_17 ( V_10 , V_233 ) ;
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
F_19 ( V_10 , V_256 ) ;
if ( ! F_116 () ) {
F_19 ( V_10 , V_257 ) ;
F_19 ( V_10 , V_258 ) ;
}
V_2 -> V_259 = V_183 ;
V_2 -> V_260 = F_117 ( V_10 -> V_151 ) ;
V_2 -> V_218 = V_261 ;
F_108 ( & V_65 -> V_262 ) ;
F_108 ( & V_65 -> V_263 ) ;
F_108 ( & V_65 -> V_264 ) ;
F_108 ( & V_65 -> V_265 ) ;
F_108 ( & V_65 -> V_266 ) ;
V_65 -> V_94 . V_200 = 0xf000 ;
V_65 -> V_94 . V_95 = 0xffff0000 ;
V_65 -> V_94 . V_201 = V_267 | V_202 |
V_203 | V_268 ;
V_65 -> V_94 . V_205 = 0xffff ;
V_65 -> V_269 . V_205 = 0xffff ;
V_65 -> V_270 . V_205 = 0xffff ;
F_109 ( & V_65 -> V_271 , V_272 ) ;
F_109 ( & V_65 -> V_273 , V_274 ) ;
F_30 ( & V_10 -> V_9 , 0 ) ;
V_65 -> V_275 = 0xffff0ff0 ;
F_118 ( & V_10 -> V_9 , 2 ) ;
V_65 -> V_91 = 0x0000fff0 ;
V_10 -> V_9 . V_46 . V_276 [ V_277 ] = V_65 -> V_91 ;
F_119 ( & V_10 -> V_9 , V_278 | V_279 | V_280 ) ;
F_120 ( & V_10 -> V_9 ) ;
V_65 -> V_281 = V_282 ;
if ( V_62 ) {
V_2 -> V_283 = 1 ;
F_20 ( V_10 , V_242 ) ;
F_18 ( V_10 , V_229 ) ;
F_13 ( V_10 , V_223 ) ;
F_13 ( V_10 , V_226 ) ;
V_65 -> V_284 = V_10 -> V_9 . V_46 . V_285 ;
V_65 -> V_286 = 0 ;
V_65 -> V_281 = 0 ;
}
V_10 -> V_129 = 0 ;
V_10 -> V_24 . V_1 = 0 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
if ( F_97 ( V_287 ) ) {
V_2 -> V_288 = 3000 ;
F_19 ( V_10 , V_289 ) ;
}
if ( V_195 )
F_112 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
F_21 ( V_10 ) ;
}
static T_1 * F_121 ( struct V_8 * V_9 ,
unsigned int V_149 )
{
T_1 * V_290 ;
struct V_169 * V_175 = & V_9 -> V_174 -> V_46 ;
if ( V_149 >= V_217 )
return NULL ;
V_290 = F_96 ( V_175 -> V_213 ) ;
return & V_290 [ V_149 ] ;
}
static int F_122 ( struct V_8 * V_9 )
{
struct V_174 * V_174 = V_9 -> V_174 ;
int V_72 ;
if ( V_174 -> V_46 . V_291 )
return 0 ;
V_72 = F_123 ( V_174 ,
V_292 ,
V_293 ,
V_157 ) ;
if ( V_72 )
return V_72 ;
V_174 -> V_46 . V_291 = true ;
return 0 ;
}
static int F_124 ( struct V_8 * V_9 )
{
int V_72 ;
T_1 * V_15 , V_294 ;
int V_295 = V_9 -> V_172 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_72 = F_122 ( V_9 ) ;
if ( V_72 )
return V_72 ;
if ( V_295 >= V_217 )
return - V_127 ;
if ( ! V_10 -> V_9 . V_46 . V_296 -> V_276 )
return - V_127 ;
V_10 -> V_209 = F_125 ( V_10 -> V_9 . V_46 . V_296 -> V_276 ) ;
V_15 = F_121 ( V_9 , V_295 ) ;
if ( ! V_15 )
return - V_127 ;
V_294 = F_8 ( * V_15 ) ;
V_294 = ( F_113 ( V_10 -> V_209 ) &
V_297 ) |
V_298 ;
F_126 ( * V_15 , V_294 ) ;
V_10 -> V_16 = V_15 ;
return 0 ;
}
static inline int F_127 ( void )
{
int V_295 ;
F_128 ( & V_299 ) ;
V_295 = F_129 ( V_300 , V_301 , 1 ) ;
if ( V_295 <= V_302 )
F_130 ( V_295 , V_300 ) ;
else
V_295 = - V_303 ;
F_131 ( & V_299 ) ;
return V_295 ;
}
static inline int F_132 ( int V_295 )
{
if ( V_295 <= 0 || V_295 > V_302 )
return - V_127 ;
F_128 ( & V_299 ) ;
F_133 ( V_295 , V_300 ) ;
F_131 ( & V_299 ) ;
return 0 ;
}
static void F_134 ( struct V_174 * V_174 )
{
unsigned long V_168 ;
struct V_169 * V_175 = & V_174 -> V_46 ;
if ( ! V_195 )
return;
F_132 ( V_175 -> V_176 ) ;
if ( V_175 -> V_211 )
F_68 ( V_175 -> V_211 ) ;
if ( V_175 -> V_213 )
F_68 ( V_175 -> V_213 ) ;
F_89 ( & V_173 , V_168 ) ;
F_135 ( & V_175 -> V_304 ) ;
F_92 ( & V_173 , V_168 ) ;
}
static int F_136 ( struct V_174 * V_174 )
{
unsigned long V_168 ;
int V_171 , V_103 = - V_147 ;
struct V_169 * V_175 = & V_174 -> V_46 ;
struct V_179 * V_305 ;
struct V_179 * V_306 ;
if ( ! V_195 )
return 0 ;
V_171 = F_127 () ;
if ( V_171 < 0 )
return V_171 ;
V_175 -> V_176 = ( T_2 ) V_171 ;
V_305 = F_72 ( V_146 ) ;
if ( ! V_305 )
goto V_307;
V_175 -> V_213 = V_305 ;
F_137 ( F_96 ( V_305 ) ) ;
V_306 = F_72 ( V_146 ) ;
if ( ! V_306 )
goto V_307;
V_175 -> V_211 = V_306 ;
F_137 ( F_96 ( V_306 ) ) ;
F_89 ( & V_173 , V_168 ) ;
F_138 ( V_308 , & V_175 -> V_304 , V_175 -> V_176 ) ;
F_92 ( & V_173 , V_168 ) ;
return 0 ;
V_307:
F_134 ( V_174 ) ;
return V_103 ;
}
static inline int
F_139 ( struct V_8 * V_9 , int V_144 , bool V_145 )
{
int V_72 = 0 ;
unsigned long V_168 ;
struct V_309 * V_310 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_140 ( V_9 -> V_174 ) )
return 0 ;
F_89 ( & V_10 -> V_311 , V_168 ) ;
if ( F_141 ( & V_10 -> V_312 ) )
goto V_313;
F_142 (ir, &svm->ir_list, node) {
V_72 = F_143 ( V_144 , V_145 , V_310 -> V_11 ) ;
if ( V_72 )
break;
}
V_313:
F_92 ( & V_10 -> V_311 , V_168 ) ;
return V_72 ;
}
static void F_144 ( struct V_8 * V_9 , int V_144 )
{
T_1 V_15 ;
int V_314 = F_145 ( V_144 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_115 ( V_9 ) )
return;
if ( F_75 ( V_314 >= V_217 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_75 ( V_15 & V_17 ) ;
V_15 &= ~ V_315 ;
V_15 |= ( V_314 & V_315 ) ;
V_15 &= ~ V_17 ;
if ( V_10 -> V_316 )
V_15 |= V_17 ;
F_126 ( * ( V_10 -> V_16 ) , V_15 ) ;
F_139 ( V_9 , V_314 ,
V_10 -> V_316 ) ;
}
static void F_146 ( struct V_8 * V_9 )
{
T_1 V_15 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_115 ( V_9 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
if ( V_15 & V_17 )
F_139 ( V_9 , - 1 , 0 ) ;
V_15 &= ~ V_17 ;
F_126 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_147 ( struct V_8 * V_9 , bool V_317 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_316 = V_317 ;
if ( V_317 )
F_144 ( V_9 , V_9 -> V_144 ) ;
else
F_146 ( V_9 ) ;
}
static void F_148 ( struct V_8 * V_9 , bool V_318 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_319 ;
T_2 V_320 = 1 ;
if ( ! V_318 ) {
V_10 -> V_9 . V_46 . V_321 = V_293 |
V_322 ;
if ( F_149 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_46 . V_321 |= V_323 ;
}
F_114 ( V_10 ) ;
F_150 ( V_9 , & V_320 , & V_319 , & V_319 , & V_319 ) ;
F_151 ( V_9 , V_324 , V_320 ) ;
if ( F_115 ( V_9 ) && ! V_318 )
F_6 ( V_10 , V_293 ) ;
}
static struct V_8 * F_152 ( struct V_174 * V_174 , unsigned int V_295 )
{
struct V_7 * V_10 ;
struct V_179 * V_179 ;
struct V_179 * V_325 ;
struct V_179 * V_326 ;
struct V_179 * V_327 ;
int V_103 ;
V_10 = F_153 ( V_328 , V_146 ) ;
if ( ! V_10 ) {
V_103 = - V_147 ;
goto V_313;
}
V_103 = F_154 ( & V_10 -> V_9 , V_174 , V_295 ) ;
if ( V_103 )
goto V_329;
V_103 = - V_147 ;
V_179 = F_72 ( V_146 ) ;
if ( ! V_179 )
goto V_330;
V_325 = F_95 ( V_146 , V_158 ) ;
if ( ! V_325 )
goto V_331;
V_327 = F_95 ( V_146 , V_158 ) ;
if ( ! V_327 )
goto V_332;
V_326 = F_72 ( V_146 ) ;
if ( ! V_326 )
goto V_333;
if ( V_195 ) {
V_103 = F_124 ( & V_10 -> V_9 ) ;
if ( V_103 )
goto V_334;
F_155 ( & V_10 -> V_312 ) ;
F_156 ( & V_10 -> V_311 ) ;
}
V_10 -> V_316 = true ;
V_10 -> V_24 . V_25 = F_96 ( V_326 ) ;
V_10 -> V_151 = F_96 ( V_325 ) ;
F_79 ( V_10 -> V_151 ) ;
V_10 -> V_24 . V_151 = F_96 ( V_327 ) ;
F_79 ( V_10 -> V_24 . V_151 ) ;
V_10 -> V_1 = F_96 ( V_179 ) ;
F_137 ( V_10 -> V_1 ) ;
V_10 -> V_335 = F_63 ( V_179 ) << V_138 ;
V_10 -> V_129 = 0 ;
F_114 ( V_10 ) ;
F_49 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_334:
F_68 ( V_326 ) ;
V_333:
F_105 ( V_327 , V_158 ) ;
V_332:
F_105 ( V_325 , V_158 ) ;
V_331:
F_68 ( V_179 ) ;
V_330:
F_157 ( & V_10 -> V_9 ) ;
V_329:
F_158 ( V_328 , V_10 ) ;
V_313:
return F_159 ( V_103 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_68 ( F_107 ( V_10 -> V_335 >> V_138 ) ) ;
F_105 ( F_125 ( V_10 -> V_151 ) , V_158 ) ;
F_68 ( F_125 ( V_10 -> V_24 . V_25 ) ) ;
F_105 ( F_125 ( V_10 -> V_24 . V_151 ) , V_158 ) ;
F_157 ( V_9 ) ;
F_158 ( V_328 , V_10 ) ;
}
static void F_161 ( struct V_8 * V_9 , int V_144 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
if ( F_162 ( V_144 != V_9 -> V_144 ) ) {
V_10 -> V_129 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_29
F_58 ( V_336 , F_4 ( V_9 ) -> V_337 . V_338 ) ;
#endif
F_163 ( V_265 , V_10 -> V_337 . V_265 ) ;
F_163 ( V_266 , V_10 -> V_337 . V_266 ) ;
V_10 -> V_337 . V_339 = F_164 () ;
for ( V_51 = 0 ; V_51 < V_340 ; V_51 ++ )
F_58 ( V_341 [ V_51 ] , V_10 -> V_342 [ V_51 ] ) ;
if ( F_36 ( V_117 ) ) {
T_1 V_343 = V_9 -> V_46 . V_344 ;
if ( V_343 != F_165 ( V_139 ) ) {
F_64 ( V_139 , V_343 ) ;
F_53 ( V_118 , V_343 ) ;
}
}
if ( F_36 ( V_345 ) )
F_53 ( V_346 , V_10 -> V_347 ) ;
F_144 ( V_9 , V_144 ) ;
}
static void F_166 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
F_146 ( V_9 ) ;
++ V_9 -> V_348 . V_349 ;
F_167 ( V_10 -> V_337 . V_339 ) ;
#ifdef F_29
F_168 ( V_265 , V_10 -> V_337 . V_265 ) ;
F_53 ( V_350 , V_351 -> V_352 . V_353 ) ;
F_169 ( V_10 -> V_337 . V_266 ) ;
#else
#ifdef F_170
F_168 ( V_266 , V_10 -> V_337 . V_266 ) ;
#endif
#endif
for ( V_51 = 0 ; V_51 < V_340 ; V_51 ++ )
F_53 ( V_341 [ V_51 ] , V_10 -> V_342 [ V_51 ] ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_147 ( V_9 , false ) ;
}
static void F_172 ( struct V_8 * V_9 )
{
F_147 ( V_9 , true ) ;
}
static unsigned long F_173 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_354 ;
}
static void F_174 ( struct V_8 * V_9 , unsigned long V_354 )
{
F_4 ( V_9 ) -> V_1 -> V_65 . V_354 = V_354 ;
}
static T_2 F_175 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_176 ( struct V_8 * V_9 , enum V_355 V_356 )
{
switch ( V_356 ) {
case V_357 :
F_76 ( ! V_62 ) ;
F_177 ( V_9 , V_9 -> V_46 . V_358 , F_178 ( V_9 ) ) ;
break;
default:
F_81 () ;
}
}
static void F_179 ( struct V_7 * V_10 )
{
F_19 ( V_10 , V_359 ) ;
}
static void F_180 ( struct V_7 * V_10 )
{
F_20 ( V_10 , V_359 ) ;
}
static struct V_198 * F_181 ( struct V_8 * V_9 , int V_199 )
{
struct V_221 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
switch ( V_199 ) {
case V_360 : return & V_65 -> V_94 ;
case V_361 : return & V_65 -> V_264 ;
case V_362 : return & V_65 -> V_262 ;
case V_363 : return & V_65 -> V_265 ;
case V_364 : return & V_65 -> V_266 ;
case V_365 : return & V_65 -> V_263 ;
case V_366 : return & V_65 -> V_273 ;
case V_367 : return & V_65 -> V_271 ;
}
F_81 () ;
return NULL ;
}
static T_1 F_182 ( struct V_8 * V_9 , int V_199 )
{
struct V_198 * V_368 = F_181 ( V_9 , V_199 ) ;
return V_368 -> V_95 ;
}
static void F_183 ( struct V_8 * V_9 ,
struct V_369 * V_370 , int V_199 )
{
struct V_198 * V_368 = F_181 ( V_9 , V_199 ) ;
V_370 -> V_95 = V_368 -> V_95 ;
V_370 -> V_205 = V_368 -> V_205 ;
V_370 -> V_200 = V_368 -> V_200 ;
V_370 -> type = V_368 -> V_201 & V_371 ;
V_370 -> V_368 = ( V_368 -> V_201 >> V_372 ) & 1 ;
V_370 -> V_373 = ( V_368 -> V_201 >> V_374 ) & 3 ;
V_370 -> V_375 = ( V_368 -> V_201 >> V_376 ) & 1 ;
V_370 -> V_377 = ( V_368 -> V_201 >> V_378 ) & 1 ;
V_370 -> V_379 = ( V_368 -> V_201 >> V_380 ) & 1 ;
V_370 -> V_381 = ( V_368 -> V_201 >> V_382 ) & 1 ;
V_370 -> V_22 = V_368 -> V_205 > 0xfffff ;
V_370 -> V_383 = ! V_370 -> V_375 ;
switch ( V_199 ) {
case V_366 :
V_370 -> type |= 0x2 ;
break;
case V_361 :
case V_362 :
case V_363 :
case V_364 :
if ( ! V_370 -> V_383 )
V_370 -> type |= 0x1 ;
break;
case V_365 :
if ( V_370 -> V_383 )
V_370 -> V_381 = 0 ;
V_370 -> V_373 = F_4 ( V_9 ) -> V_1 -> V_65 . V_384 ;
break;
}
}
static int F_184 ( struct V_8 * V_9 )
{
struct V_221 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
return V_65 -> V_384 ;
}
static void F_185 ( struct V_8 * V_9 , struct V_385 * V_386 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_386 -> V_387 = V_10 -> V_1 -> V_65 . V_270 . V_205 ;
V_386 -> V_388 = V_10 -> V_1 -> V_65 . V_270 . V_95 ;
}
static void F_186 ( struct V_8 * V_9 , struct V_385 * V_386 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_270 . V_205 = V_386 -> V_387 ;
V_10 -> V_1 -> V_65 . V_270 . V_95 = V_386 -> V_388 ;
F_3 ( V_10 -> V_1 , V_389 ) ;
}
static void F_187 ( struct V_8 * V_9 , struct V_385 * V_386 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_386 -> V_387 = V_10 -> V_1 -> V_65 . V_269 . V_205 ;
V_386 -> V_388 = V_10 -> V_1 -> V_65 . V_269 . V_95 ;
}
static void F_188 ( struct V_8 * V_9 , struct V_385 * V_386 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_269 . V_205 = V_386 -> V_387 ;
V_10 -> V_1 -> V_65 . V_269 . V_95 = V_386 -> V_388 ;
F_3 ( V_10 -> V_1 , V_389 ) ;
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
T_9 V_390 = V_10 -> V_9 . V_46 . V_391 ;
T_1 * V_392 = & V_10 -> V_1 -> V_65 . V_391 ;
* V_392 = ( * V_392 & ~ V_393 )
| ( V_390 & V_393 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
if ( V_390 == * V_392 ) {
F_13 ( V_10 , V_222 ) ;
F_13 ( V_10 , V_225 ) ;
} else {
F_12 ( V_10 , V_222 ) ;
F_12 ( V_10 , V_225 ) ;
}
}
static void F_119 ( struct V_8 * V_9 , unsigned long V_391 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_29
if ( V_9 -> V_46 . V_61 & V_64 ) {
if ( ! F_193 ( V_9 ) && ( V_391 & V_394 ) ) {
V_9 -> V_46 . V_61 |= V_63 ;
V_10 -> V_1 -> V_65 . V_61 |= V_63 | V_64 ;
}
if ( F_193 ( V_9 ) && ! ( V_391 & V_394 ) ) {
V_9 -> V_46 . V_61 &= ~ V_63 ;
V_10 -> V_1 -> V_65 . V_61 &= ~ ( V_63 | V_64 ) ;
}
}
#endif
V_9 -> V_46 . V_391 = V_391 ;
if ( ! V_62 )
V_391 |= V_394 | V_395 ;
if ( F_194 ( V_9 -> V_174 , V_396 ) )
V_391 &= ~ ( V_279 | V_278 ) ;
V_10 -> V_1 -> V_65 . V_391 = V_391 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_192 ( V_10 ) ;
}
static int F_195 ( struct V_8 * V_9 , unsigned long V_281 )
{
unsigned long V_397 = F_196 () & V_398 ;
unsigned long V_399 = F_4 ( V_9 ) -> V_1 -> V_65 . V_281 ;
if ( V_281 & V_400 )
return 1 ;
if ( V_62 && ( ( V_399 ^ V_281 ) & V_401 ) )
F_197 ( V_9 ) ;
V_9 -> V_46 . V_281 = V_281 ;
if ( ! V_62 )
V_281 |= V_282 ;
V_281 |= V_397 ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_281 = V_281 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_67 ) ;
return 0 ;
}
static void F_198 ( struct V_8 * V_9 ,
struct V_369 * V_370 , int V_199 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_198 * V_368 = F_181 ( V_9 , V_199 ) ;
V_368 -> V_95 = V_370 -> V_95 ;
V_368 -> V_205 = V_370 -> V_205 ;
V_368 -> V_200 = V_370 -> V_200 ;
V_368 -> V_201 = ( V_370 -> type & V_371 ) ;
V_368 -> V_201 |= ( V_370 -> V_368 & 1 ) << V_372 ;
V_368 -> V_201 |= ( V_370 -> V_373 & 3 ) << V_374 ;
V_368 -> V_201 |= ( ( V_370 -> V_375 & 1 ) && ! V_370 -> V_383 ) << V_376 ;
V_368 -> V_201 |= ( V_370 -> V_377 & 1 ) << V_378 ;
V_368 -> V_201 |= ( V_370 -> V_379 & 1 ) << V_380 ;
V_368 -> V_201 |= ( V_370 -> V_381 & 1 ) << V_382 ;
V_368 -> V_201 |= ( V_370 -> V_22 & 1 ) << V_402 ;
if ( V_199 == V_365 )
V_10 -> V_1 -> V_65 . V_384 = ( V_370 -> V_373 & 3 ) ;
F_3 ( V_10 -> V_1 , V_403 ) ;
}
static void F_199 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_90 ) ;
if ( V_9 -> V_404 & V_405 ) {
if ( V_9 -> V_404 & V_406 )
F_17 ( V_10 , V_90 ) ;
} else
V_9 -> V_404 = 0 ;
}
static void F_200 ( struct V_7 * V_10 , struct V_120 * V_121 )
{
if ( V_121 -> V_132 > V_121 -> V_130 ) {
++ V_121 -> V_129 ;
V_121 -> V_132 = 1 ;
V_10 -> V_1 -> V_2 . V_407 = V_408 ;
}
V_10 -> V_129 = V_121 -> V_129 ;
V_10 -> V_1 -> V_2 . V_58 = V_121 -> V_132 ++ ;
F_3 ( V_10 -> V_1 , V_409 ) ;
}
static T_1 F_201 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_275 ;
}
static void F_202 ( struct V_8 * V_9 , unsigned long V_410 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_275 = V_410 ;
F_3 ( V_10 -> V_1 , V_411 ) ;
}
static void F_203 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_204 ( V_9 -> V_46 . V_381 [ 0 ] , 0 ) ;
F_204 ( V_9 -> V_46 . V_381 [ 1 ] , 1 ) ;
F_204 ( V_9 -> V_46 . V_381 [ 2 ] , 2 ) ;
F_204 ( V_9 -> V_46 . V_381 [ 3 ] , 3 ) ;
V_9 -> V_46 . V_275 = F_201 ( V_9 ) ;
V_9 -> V_46 . V_412 = V_10 -> V_1 -> V_65 . V_412 ;
V_9 -> V_46 . V_413 &= ~ V_414 ;
F_15 ( V_10 ) ;
}
static void F_205 ( struct V_8 * V_9 , unsigned long V_410 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_412 = V_410 ;
F_3 ( V_10 -> V_1 , V_411 ) ;
}
static int F_206 ( struct V_7 * V_10 )
{
T_1 V_415 = V_10 -> V_1 -> V_2 . V_416 ;
T_1 V_88 ;
int V_145 = 1 ;
switch ( V_10 -> V_417 ) {
default:
V_88 = V_10 -> V_1 -> V_2 . V_418 ;
F_207 ( V_415 , V_88 ) ;
if ( ! V_62 && F_208 ( & V_10 -> V_9 ) )
F_209 ( & V_10 -> V_9 , V_415 ) ;
V_145 = F_210 ( & V_10 -> V_9 , V_415 , V_88 ,
V_10 -> V_1 -> V_2 . V_419 ,
V_10 -> V_1 -> V_2 . V_420 ) ;
break;
case V_421 :
V_10 -> V_417 = 0 ;
F_211 () ;
F_212 ( V_415 ) ;
F_213 () ;
break;
case V_422 :
V_10 -> V_417 = 0 ;
F_211 () ;
F_214 ( V_415 ) ;
F_213 () ;
break;
}
return V_145 ;
}
static int F_215 ( struct V_7 * V_10 )
{
struct V_423 * V_423 = V_10 -> V_9 . V_424 ;
if ( ! ( V_10 -> V_9 . V_404 &
( V_425 | V_426 ) ) &&
! V_10 -> V_427 ) {
F_216 ( & V_10 -> V_9 , V_233 ) ;
return 1 ;
}
if ( V_10 -> V_427 ) {
V_10 -> V_427 = false ;
if ( ! ( V_10 -> V_9 . V_404 & V_425 ) )
V_10 -> V_1 -> V_65 . V_354 &=
~ ( V_428 | V_429 ) ;
}
if ( V_10 -> V_9 . V_404 &
( V_425 | V_426 ) ) {
V_423 -> V_430 = V_431 ;
V_423 -> V_432 . V_46 . V_433 =
V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_423 -> V_432 . V_46 . V_434 = V_233 ;
return 0 ;
}
return 1 ;
}
static int F_217 ( struct V_7 * V_10 )
{
struct V_423 * V_423 = V_10 -> V_9 . V_424 ;
V_423 -> V_430 = V_431 ;
V_423 -> V_432 . V_46 . V_433 = V_10 -> V_1 -> V_65 . V_94 . V_95 + V_10 -> V_1 -> V_65 . V_91 ;
V_423 -> V_432 . V_46 . V_434 = V_90 ;
return 0 ;
}
static int F_218 ( struct V_7 * V_10 )
{
int V_435 ;
V_435 = F_37 ( & V_10 -> V_9 , V_436 ) ;
if ( V_435 != V_81 )
F_216 ( & V_10 -> V_9 , V_230 ) ;
return 1 ;
}
static int F_219 ( struct V_7 * V_10 )
{
F_220 ( & V_10 -> V_9 , V_232 , 0 ) ;
return 1 ;
}
static bool F_221 ( void )
{
int V_103 , V_51 ;
T_1 V_410 ;
if ( ! V_107 )
return false ;
V_410 = F_45 ( V_437 , & V_103 ) ;
if ( V_103 )
return false ;
V_410 &= ~ ( 1ULL << 62 ) ;
if ( V_410 != 0xb600000000010015ULL )
return false ;
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 )
F_48 ( F_222 ( V_51 ) , 0 , 0 ) ;
V_410 = F_45 ( V_438 , & V_103 ) ;
if ( ! V_103 ) {
T_2 V_101 , V_102 ;
V_410 &= ~ ( 1ULL << 2 ) ;
V_101 = F_46 ( V_410 ) ;
V_102 = F_47 ( V_410 ) ;
F_48 ( V_438 , V_101 , V_102 ) ;
}
F_223 () ;
return true ;
}
static void F_224 ( struct V_7 * V_10 )
{
if ( F_221 () ) {
F_59 ( L_11 ) ;
F_225 ( V_439 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_226 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_227 ( struct V_7 * V_10 )
{
struct V_423 * V_423 = V_10 -> V_9 . V_424 ;
F_137 ( V_10 -> V_1 ) ;
F_114 ( V_10 ) ;
V_423 -> V_430 = V_440 ;
return 0 ;
}
static int F_228 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_2 V_441 = V_10 -> V_1 -> V_2 . V_418 ;
int V_387 , V_442 , string ;
unsigned V_443 ;
++ V_10 -> V_9 . V_348 . V_444 ;
string = ( V_441 & V_445 ) != 0 ;
V_442 = ( V_441 & V_446 ) != 0 ;
if ( string )
return F_37 ( V_9 , 0 ) == V_81 ;
V_443 = V_441 >> 16 ;
V_387 = ( V_441 & V_447 ) >> V_448 ;
V_10 -> V_78 = V_10 -> V_1 -> V_2 . V_416 ;
F_34 ( & V_10 -> V_9 ) ;
return V_442 ? F_229 ( V_9 , V_387 , V_443 )
: F_230 ( V_9 , V_387 , V_443 ) ;
}
static int F_231 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_232 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_348 . V_449 ;
return 1 ;
}
static int F_233 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_234 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 1 ;
return F_235 ( & V_10 -> V_9 ) ;
}
static int F_236 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_237 ( & V_10 -> V_9 ) ;
}
static unsigned long F_238 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_24 . V_450 ;
}
static T_1 F_239 ( struct V_8 * V_9 , int V_149 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_286 = V_10 -> V_24 . V_450 ;
T_1 V_451 ;
int V_72 ;
V_72 = F_240 ( V_9 , F_241 ( V_286 ) , & V_451 ,
F_242 ( V_286 ) + V_149 * 8 , 8 ) ;
if ( V_72 )
return 0 ;
return V_451 ;
}
static void F_243 ( struct V_8 * V_9 ,
unsigned long V_452 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_450 = V_452 ;
F_3 ( V_10 -> V_1 , V_453 ) ;
F_197 ( V_9 ) ;
}
static void F_244 ( struct V_8 * V_9 ,
struct V_454 * V_455 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_456 != V_457 ) {
V_10 -> V_1 -> V_2 . V_456 = V_457 ;
V_10 -> V_1 -> V_2 . V_458 = 0 ;
V_10 -> V_1 -> V_2 . V_418 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_416 = V_455 -> V_388 ;
}
V_10 -> V_1 -> V_2 . V_418 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_418 |= V_455 -> V_88 ;
if ( V_10 -> V_1 -> V_2 . V_418 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_418 &= ~ 1 ;
F_245 ( V_10 ) ;
}
static void F_246 ( struct V_8 * V_9 )
{
F_75 ( F_247 ( V_9 ) ) ;
F_248 ( V_9 ) ;
V_9 -> V_46 . V_459 . V_460 = F_243 ;
V_9 -> V_46 . V_459 . V_461 = F_238 ;
V_9 -> V_46 . V_459 . V_462 = F_239 ;
V_9 -> V_46 . V_459 . V_463 = F_244 ;
V_9 -> V_46 . V_459 . V_464 = F_28 () ;
F_249 ( V_9 , & V_9 -> V_46 . V_459 ) ;
V_9 -> V_46 . V_358 = & V_9 -> V_46 . V_465 ;
}
static void F_250 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_358 = & V_9 -> V_46 . V_459 ;
}
static int F_251 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_46 . V_61 & V_66 )
|| ! F_193 ( & V_10 -> V_9 ) ) {
F_216 ( & V_10 -> V_9 , V_230 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_65 . V_384 ) {
F_252 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_10 , unsigned V_86 ,
bool V_87 , T_2 V_88 )
{
int V_466 ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_456 = V_467 + V_86 ;
V_10 -> V_1 -> V_2 . V_458 = 0 ;
V_10 -> V_1 -> V_2 . V_418 = V_88 ;
V_10 -> V_1 -> V_2 . V_416 = V_10 -> V_9 . V_46 . V_468 ;
V_466 = F_253 ( V_10 ) ;
if ( V_466 == V_469 )
V_10 -> V_24 . V_470 = true ;
return V_466 ;
}
static inline bool F_254 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_471 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_472 ) )
return false ;
if ( V_10 -> V_24 . V_470 )
return false ;
V_10 -> V_1 -> V_2 . V_456 = V_473 ;
V_10 -> V_1 -> V_2 . V_418 = 0 ;
V_10 -> V_1 -> V_2 . V_416 = 0 ;
if ( V_10 -> V_24 . V_29 & 1ULL ) {
V_10 -> V_24 . V_470 = true ;
F_255 ( V_10 -> V_1 -> V_65 . V_91 ) ;
return false ;
}
return true ;
}
static inline bool F_256 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_235 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_456 = V_474 ;
V_10 -> V_24 . V_470 = true ;
return false ;
}
static void * F_257 ( struct V_7 * V_10 , T_1 V_475 , struct V_179 * * V_476 )
{
struct V_179 * V_179 ;
F_258 () ;
V_179 = F_259 ( & V_10 -> V_9 , V_475 >> V_138 ) ;
if ( F_260 ( V_179 ) )
goto error;
* V_476 = V_179 ;
return F_261 ( V_179 ) ;
error:
F_252 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_262 ( struct V_179 * V_179 )
{
F_263 ( V_179 ) ;
F_264 ( V_179 ) ;
}
static int F_265 ( struct V_7 * V_10 )
{
unsigned V_443 , V_387 , V_477 ;
T_10 V_104 , V_77 ;
T_4 V_478 ;
T_1 V_475 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_244 ) ) )
return V_479 ;
V_443 = V_10 -> V_1 -> V_2 . V_418 >> 16 ;
V_387 = ( V_10 -> V_1 -> V_2 . V_418 & V_447 ) >>
V_448 ;
V_475 = V_10 -> V_24 . V_480 + ( V_443 / 8 ) ;
V_478 = V_443 % 8 ;
V_477 = ( V_478 + V_387 > 8 ) ? 2 : 1 ;
V_77 = ( 0xf >> ( 4 - V_387 ) ) << V_478 ;
V_104 = 0 ;
if ( F_266 ( & V_10 -> V_9 , V_475 , & V_104 , V_477 ) )
return V_469 ;
return ( V_104 & V_77 ) ? V_469 : V_479 ;
}
static int F_267 ( struct V_7 * V_10 )
{
T_2 V_50 , V_49 , V_410 ;
int V_153 , V_77 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_245 ) ) )
return V_479 ;
V_49 = V_10 -> V_9 . V_46 . V_276 [ V_481 ] ;
V_50 = F_24 ( V_49 ) ;
V_153 = V_10 -> V_1 -> V_2 . V_418 & 1 ;
V_77 = 1 << ( ( 2 * ( V_49 & 0xf ) ) + V_153 ) ;
if ( V_50 == V_56 )
return V_469 ;
V_50 *= 4 ;
if ( F_266 ( & V_10 -> V_9 , V_10 -> V_24 . V_482 + V_50 , & V_410 , 4 ) )
return V_469 ;
return ( V_410 & V_77 ) ? V_469 : V_479 ;
}
static int F_268 ( struct V_7 * V_10 )
{
T_2 V_456 = V_10 -> V_1 -> V_2 . V_456 ;
switch ( V_456 ) {
case V_473 :
case V_474 :
case V_467 + V_231 :
return V_479 ;
case V_457 :
if ( V_62 )
return V_479 ;
break;
case V_467 + V_229 :
if ( ! V_62 && V_10 -> V_417 == 0 )
return V_479 ;
break;
default:
break;
}
return V_483 ;
}
static int F_253 ( struct V_7 * V_10 )
{
T_2 V_456 = V_10 -> V_1 -> V_2 . V_456 ;
int V_466 = V_479 ;
switch ( V_456 ) {
case V_484 :
V_466 = F_267 ( V_10 ) ;
break;
case V_485 :
V_466 = F_265 ( V_10 ) ;
break;
case V_486 ... V_487 : {
T_2 V_6 = 1U << ( V_456 - V_486 ) ;
if ( V_10 -> V_24 . V_26 & V_6 )
V_466 = V_469 ;
break;
}
case V_488 ... V_489 : {
T_2 V_6 = 1U << ( V_456 - V_488 ) ;
if ( V_10 -> V_24 . V_27 & V_6 )
V_466 = V_469 ;
break;
}
case V_467 ... V_467 + 0x1f : {
T_2 V_490 = 1 << ( V_456 - V_467 ) ;
if ( V_10 -> V_24 . V_28 & V_490 )
V_466 = V_469 ;
else if ( ( V_456 == V_467 + V_229 ) &&
V_10 -> V_417 != 0 )
V_466 = V_469 ;
break;
}
case V_491 : {
V_466 = V_469 ;
break;
}
default: {
T_1 V_492 = 1ULL << ( V_456 - V_473 ) ;
if ( V_10 -> V_24 . V_29 & V_492 )
V_466 = V_469 ;
}
}
return V_466 ;
}
static int F_269 ( struct V_7 * V_10 )
{
int V_466 ;
V_466 = F_253 ( V_10 ) ;
if ( V_466 == V_469 )
F_245 ( V_10 ) ;
return V_466 ;
}
static inline void F_270 ( struct V_1 * V_493 , struct V_1 * V_494 )
{
struct V_18 * V_495 = & V_493 -> V_2 ;
struct V_18 * V_496 = & V_494 -> V_2 ;
V_495 -> V_26 = V_496 -> V_26 ;
V_495 -> V_27 = V_496 -> V_27 ;
V_495 -> V_28 = V_496 -> V_28 ;
V_495 -> V_29 = V_496 -> V_29 ;
V_495 -> V_259 = V_496 -> V_259 ;
V_495 -> V_260 = V_496 -> V_260 ;
V_495 -> V_207 = V_496 -> V_207 ;
V_495 -> V_58 = V_496 -> V_58 ;
V_495 -> V_407 = V_496 -> V_407 ;
V_495 -> V_218 = V_496 -> V_218 ;
V_495 -> V_497 = V_496 -> V_497 ;
V_495 -> V_73 = V_496 -> V_73 ;
V_495 -> V_456 = V_496 -> V_456 ;
V_495 -> V_458 = V_496 -> V_458 ;
V_495 -> V_418 = V_496 -> V_418 ;
V_495 -> V_416 = V_496 -> V_416 ;
V_495 -> V_498 = V_496 -> V_498 ;
V_495 -> V_499 = V_496 -> V_499 ;
V_495 -> V_283 = V_496 -> V_283 ;
V_495 -> V_97 = V_496 -> V_97 ;
V_495 -> V_100 = V_496 -> V_100 ;
V_495 -> V_450 = V_496 -> V_450 ;
V_495 -> V_162 = V_496 -> V_162 ;
}
static int F_245 ( struct V_7 * V_10 )
{
struct V_1 * V_500 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_179 * V_179 ;
F_271 ( V_1 -> V_2 . V_456 ,
V_1 -> V_2 . V_418 ,
V_1 -> V_2 . V_416 ,
V_1 -> V_2 . V_498 ,
V_1 -> V_2 . V_499 ,
V_501 ) ;
V_500 = F_257 ( V_10 , V_10 -> V_24 . V_1 , & V_179 ) ;
if ( ! V_500 )
return 1 ;
F_272 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_1 = 0 ;
F_22 ( V_10 ) ;
V_500 -> V_65 . V_262 = V_1 -> V_65 . V_262 ;
V_500 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_500 -> V_65 . V_263 = V_1 -> V_65 . V_263 ;
V_500 -> V_65 . V_264 = V_1 -> V_65 . V_264 ;
V_500 -> V_65 . V_269 = V_1 -> V_65 . V_269 ;
V_500 -> V_65 . V_270 = V_1 -> V_65 . V_270 ;
V_500 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_500 -> V_65 . V_391 = F_273 ( & V_10 -> V_9 ) ;
V_500 -> V_65 . V_286 = F_178 ( & V_10 -> V_9 ) ;
V_500 -> V_65 . V_468 = V_1 -> V_65 . V_468 ;
V_500 -> V_65 . V_281 = V_10 -> V_9 . V_46 . V_281 ;
V_500 -> V_65 . V_354 = F_274 ( & V_10 -> V_9 ) ;
V_500 -> V_65 . V_91 = V_1 -> V_65 . V_91 ;
V_500 -> V_65 . V_502 = V_1 -> V_65 . V_502 ;
V_500 -> V_65 . V_503 = V_1 -> V_65 . V_503 ;
V_500 -> V_65 . V_412 = V_1 -> V_65 . V_412 ;
V_500 -> V_65 . V_275 = V_1 -> V_65 . V_275 ;
V_500 -> V_65 . V_384 = V_1 -> V_65 . V_384 ;
V_500 -> V_2 . V_218 = V_1 -> V_2 . V_218 ;
V_500 -> V_2 . V_497 = V_1 -> V_2 . V_497 ;
V_500 -> V_2 . V_73 = V_1 -> V_2 . V_73 ;
V_500 -> V_2 . V_456 = V_1 -> V_2 . V_456 ;
V_500 -> V_2 . V_458 = V_1 -> V_2 . V_458 ;
V_500 -> V_2 . V_418 = V_1 -> V_2 . V_418 ;
V_500 -> V_2 . V_416 = V_1 -> V_2 . V_416 ;
V_500 -> V_2 . V_498 = V_1 -> V_2 . V_498 ;
V_500 -> V_2 . V_499 = V_1 -> V_2 . V_499 ;
if ( V_10 -> V_504 )
V_500 -> V_2 . V_78 = V_1 -> V_2 . V_78 ;
if ( V_1 -> V_2 . V_97 & V_70 ) {
struct V_18 * V_505 = & V_500 -> V_2 ;
V_505 -> V_498 = V_1 -> V_2 . V_97 ;
V_505 -> V_499 = V_1 -> V_2 . V_100 ;
}
V_500 -> V_2 . V_407 = 0 ;
V_500 -> V_2 . V_97 = 0 ;
V_500 -> V_2 . V_100 = 0 ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_471 ) )
V_500 -> V_2 . V_218 &= ~ V_261 ;
F_270 ( V_1 , V_25 ) ;
F_275 ( & V_10 -> V_9 ) ;
F_276 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_450 = 0 ;
V_10 -> V_1 -> V_65 . V_262 = V_25 -> V_65 . V_262 ;
V_10 -> V_1 -> V_65 . V_94 = V_25 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_263 = V_25 -> V_65 . V_263 ;
V_10 -> V_1 -> V_65 . V_264 = V_25 -> V_65 . V_264 ;
V_10 -> V_1 -> V_65 . V_269 = V_25 -> V_65 . V_269 ;
V_10 -> V_1 -> V_65 . V_270 = V_25 -> V_65 . V_270 ;
F_118 ( & V_10 -> V_9 , V_25 -> V_65 . V_354 ) ;
F_30 ( & V_10 -> V_9 , V_25 -> V_65 . V_61 ) ;
F_119 ( & V_10 -> V_9 , V_25 -> V_65 . V_391 | V_506 ) ;
F_195 ( & V_10 -> V_9 , V_25 -> V_65 . V_281 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_286 = V_25 -> V_65 . V_286 ;
V_10 -> V_9 . V_46 . V_286 = V_25 -> V_65 . V_286 ;
} else {
( void ) F_277 ( & V_10 -> V_9 , V_25 -> V_65 . V_286 ) ;
}
F_151 ( & V_10 -> V_9 , V_507 , V_25 -> V_65 . V_503 ) ;
F_151 ( & V_10 -> V_9 , V_508 , V_25 -> V_65 . V_502 ) ;
F_151 ( & V_10 -> V_9 , V_277 , V_25 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_412 = 0 ;
V_10 -> V_1 -> V_65 . V_384 = 0 ;
V_10 -> V_1 -> V_2 . V_498 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_262 ( V_179 ) ;
F_250 ( & V_10 -> V_9 ) ;
F_120 ( & V_10 -> V_9 ) ;
F_278 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_279 ( struct V_7 * V_10 )
{
int V_51 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_245 ) ) )
return true ;
for ( V_51 = 0 ; V_51 < V_160 ; V_51 ++ ) {
T_2 V_410 , V_509 ;
T_1 V_50 ;
if ( V_161 [ V_51 ] == 0xffffffff )
break;
V_509 = V_161 [ V_51 ] ;
V_50 = V_10 -> V_24 . V_482 + ( V_509 * 4 ) ;
if ( F_266 ( & V_10 -> V_9 , V_50 , & V_410 , 4 ) )
return false ;
V_10 -> V_24 . V_151 [ V_509 ] = V_10 -> V_151 [ V_509 ] | V_410 ;
}
V_10 -> V_1 -> V_2 . V_260 = F_117 ( V_10 -> V_24 . V_151 ) ;
return true ;
}
static bool F_280 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_29 & ( 1ULL << V_248 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_58 == 0 )
return false ;
if ( V_1 -> V_2 . V_283 && ! V_62 )
return false ;
return true ;
}
static bool F_281 ( struct V_7 * V_10 )
{
struct V_1 * V_500 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_179 * V_179 ;
T_1 V_510 ;
V_510 = V_10 -> V_1 -> V_65 . V_503 ;
V_500 = F_257 ( V_10 , V_10 -> V_1 -> V_65 . V_503 , & V_179 ) ;
if ( ! V_500 )
return false ;
if ( ! F_280 ( V_500 ) ) {
V_500 -> V_2 . V_456 = V_491 ;
V_500 -> V_2 . V_458 = 0 ;
V_500 -> V_2 . V_418 = 0 ;
V_500 -> V_2 . V_416 = 0 ;
F_262 ( V_179 ) ;
return false ;
}
F_282 ( V_10 -> V_1 -> V_65 . V_91 , V_510 ,
V_500 -> V_65 . V_91 ,
V_500 -> V_2 . V_218 ,
V_500 -> V_2 . V_97 ,
V_500 -> V_2 . V_283 ) ;
F_283 ( V_500 -> V_2 . V_26 & 0xffff ,
V_500 -> V_2 . V_26 >> 16 ,
V_500 -> V_2 . V_28 ,
V_500 -> V_2 . V_29 ) ;
F_275 ( & V_10 -> V_9 ) ;
F_276 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_262 = V_1 -> V_65 . V_262 ;
V_25 -> V_65 . V_94 = V_1 -> V_65 . V_94 ;
V_25 -> V_65 . V_263 = V_1 -> V_65 . V_263 ;
V_25 -> V_65 . V_264 = V_1 -> V_65 . V_264 ;
V_25 -> V_65 . V_269 = V_1 -> V_65 . V_269 ;
V_25 -> V_65 . V_270 = V_1 -> V_65 . V_270 ;
V_25 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_25 -> V_65 . V_391 = F_273 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_281 = V_10 -> V_9 . V_46 . V_281 ;
V_25 -> V_65 . V_354 = F_274 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_91 = F_39 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_502 = V_1 -> V_65 . V_502 ;
V_25 -> V_65 . V_503 = V_1 -> V_65 . V_503 ;
if ( V_62 )
V_25 -> V_65 . V_286 = V_1 -> V_65 . V_286 ;
else
V_25 -> V_65 . V_286 = F_178 ( & V_10 -> V_9 ) ;
F_270 ( V_25 , V_1 ) ;
if ( F_274 ( & V_10 -> V_9 ) & V_511 )
V_10 -> V_9 . V_46 . V_47 |= V_472 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_472 ;
if ( V_500 -> V_2 . V_283 ) {
F_284 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_450 = V_500 -> V_2 . V_450 ;
F_246 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_65 . V_262 = V_500 -> V_65 . V_262 ;
V_10 -> V_1 -> V_65 . V_94 = V_500 -> V_65 . V_94 ;
V_10 -> V_1 -> V_65 . V_263 = V_500 -> V_65 . V_263 ;
V_10 -> V_1 -> V_65 . V_264 = V_500 -> V_65 . V_264 ;
V_10 -> V_1 -> V_65 . V_269 = V_500 -> V_65 . V_269 ;
V_10 -> V_1 -> V_65 . V_270 = V_500 -> V_65 . V_270 ;
F_118 ( & V_10 -> V_9 , V_500 -> V_65 . V_354 ) ;
F_30 ( & V_10 -> V_9 , V_500 -> V_65 . V_61 ) ;
F_119 ( & V_10 -> V_9 , V_500 -> V_65 . V_391 ) ;
F_195 ( & V_10 -> V_9 , V_500 -> V_65 . V_281 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_286 = V_500 -> V_65 . V_286 ;
V_10 -> V_9 . V_46 . V_286 = V_500 -> V_65 . V_286 ;
} else
( void ) F_277 ( & V_10 -> V_9 , V_500 -> V_65 . V_286 ) ;
F_120 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_65 . V_468 = V_10 -> V_9 . V_46 . V_468 = V_500 -> V_65 . V_468 ;
F_151 ( & V_10 -> V_9 , V_507 , V_500 -> V_65 . V_503 ) ;
F_151 ( & V_10 -> V_9 , V_508 , V_500 -> V_65 . V_502 ) ;
F_151 ( & V_10 -> V_9 , V_277 , V_500 -> V_65 . V_91 ) ;
V_10 -> V_1 -> V_65 . V_503 = V_500 -> V_65 . V_503 ;
V_10 -> V_1 -> V_65 . V_502 = V_500 -> V_65 . V_502 ;
V_10 -> V_1 -> V_65 . V_91 = V_500 -> V_65 . V_91 ;
V_10 -> V_1 -> V_65 . V_412 = V_500 -> V_65 . V_412 ;
V_10 -> V_1 -> V_65 . V_275 = V_500 -> V_65 . V_275 ;
V_10 -> V_1 -> V_65 . V_384 = V_500 -> V_65 . V_384 ;
V_10 -> V_24 . V_482 = V_500 -> V_2 . V_260 & ~ 0x0fffULL ;
V_10 -> V_24 . V_480 = V_500 -> V_2 . V_259 & ~ 0x0fffULL ;
V_10 -> V_24 . V_26 = V_500 -> V_2 . V_26 ;
V_10 -> V_24 . V_27 = V_500 -> V_2 . V_27 ;
V_10 -> V_24 . V_28 = V_500 -> V_2 . V_28 ;
V_10 -> V_24 . V_29 = V_500 -> V_2 . V_29 ;
F_197 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_218 = V_500 -> V_2 . V_218 | V_261 ;
if ( V_500 -> V_2 . V_218 & V_261 )
V_10 -> V_9 . V_46 . V_47 |= V_471 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_471 ;
if ( V_10 -> V_9 . V_46 . V_47 & V_471 ) {
F_13 ( V_10 , V_512 ) ;
F_13 ( V_10 , V_228 ) ;
}
F_20 ( V_10 , V_249 ) ;
V_10 -> V_1 -> V_2 . V_162 = V_500 -> V_2 . V_162 ;
V_10 -> V_1 -> V_2 . V_497 = V_500 -> V_2 . V_497 ;
V_10 -> V_1 -> V_2 . V_73 = V_500 -> V_2 . V_73 ;
V_10 -> V_1 -> V_2 . V_207 += V_500 -> V_2 . V_207 ;
V_10 -> V_1 -> V_2 . V_97 = V_500 -> V_2 . V_97 ;
V_10 -> V_1 -> V_2 . V_100 = V_500 -> V_2 . V_100 ;
F_262 ( V_179 ) ;
F_285 ( & V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
V_10 -> V_24 . V_1 = V_510 ;
F_21 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_286 ( struct V_1 * V_494 , struct V_1 * V_513 )
{
V_513 -> V_65 . V_265 = V_494 -> V_65 . V_265 ;
V_513 -> V_65 . V_266 = V_494 -> V_65 . V_266 ;
V_513 -> V_65 . V_273 = V_494 -> V_65 . V_273 ;
V_513 -> V_65 . V_271 = V_494 -> V_65 . V_271 ;
V_513 -> V_65 . V_514 = V_494 -> V_65 . V_514 ;
V_513 -> V_65 . V_515 = V_494 -> V_65 . V_515 ;
V_513 -> V_65 . V_516 = V_494 -> V_65 . V_516 ;
V_513 -> V_65 . V_517 = V_494 -> V_65 . V_517 ;
V_513 -> V_65 . V_518 = V_494 -> V_65 . V_518 ;
V_513 -> V_65 . V_519 = V_494 -> V_65 . V_519 ;
V_513 -> V_65 . V_520 = V_494 -> V_65 . V_520 ;
V_513 -> V_65 . V_521 = V_494 -> V_65 . V_521 ;
}
static int F_287 ( struct V_7 * V_10 )
{
struct V_1 * V_500 ;
struct V_179 * V_179 ;
if ( F_251 ( V_10 ) )
return 1 ;
V_500 = F_257 ( V_10 , V_10 -> V_1 -> V_65 . V_503 , & V_179 ) ;
if ( ! V_500 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_286 ( V_500 , V_10 -> V_1 ) ;
F_262 ( V_179 ) ;
return 1 ;
}
static int F_288 ( struct V_7 * V_10 )
{
struct V_1 * V_500 ;
struct V_179 * V_179 ;
if ( F_251 ( V_10 ) )
return 1 ;
V_500 = F_257 ( V_10 , V_10 -> V_1 -> V_65 . V_503 , & V_179 ) ;
if ( ! V_500 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_286 ( V_10 -> V_1 , V_500 ) ;
F_262 ( V_179 ) ;
return 1 ;
}
static int F_289 ( struct V_7 * V_10 )
{
if ( F_251 ( V_10 ) )
return 1 ;
F_40 ( & V_10 -> V_9 , F_39 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_281 ( V_10 ) )
return 1 ;
if ( ! F_279 ( V_10 ) )
goto V_522;
return 1 ;
V_522:
V_10 -> V_1 -> V_2 . V_456 = V_491 ;
V_10 -> V_1 -> V_2 . V_458 = 0 ;
V_10 -> V_1 -> V_2 . V_418 = 0 ;
V_10 -> V_1 -> V_2 . V_416 = 0 ;
F_245 ( V_10 ) ;
return 1 ;
}
static int F_290 ( struct V_7 * V_10 )
{
if ( F_251 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_225 ( V_523 , & V_10 -> V_9 ) ;
F_21 ( V_10 ) ;
return 1 ;
}
static int F_291 ( struct V_7 * V_10 )
{
if ( F_251 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
F_22 ( V_10 ) ;
if ( ! F_115 ( & V_10 -> V_9 ) ) {
F_180 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_218 &= ~ V_524 ;
F_3 ( V_10 -> V_1 , V_525 ) ;
}
return 1 ;
}
static int F_292 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_293 ( V_10 -> V_1 -> V_65 . V_91 , F_294 ( & V_10 -> V_9 , V_481 ) ,
F_294 ( & V_10 -> V_9 , V_507 ) ) ;
F_295 ( V_9 , F_294 ( & V_10 -> V_9 , V_507 ) ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_296 ( struct V_7 * V_10 )
{
F_297 ( V_10 -> V_1 -> V_65 . V_91 , F_294 ( & V_10 -> V_9 , V_507 ) ) ;
F_216 ( & V_10 -> V_9 , V_230 ) ;
return 1 ;
}
static int F_298 ( struct V_7 * V_10 )
{
return F_299 ( & V_10 -> V_9 ) ;
}
static int F_300 ( struct V_7 * V_10 )
{
T_1 V_526 = F_301 ( & V_10 -> V_9 ) ;
T_2 V_149 = F_294 ( & V_10 -> V_9 , V_481 ) ;
if ( F_302 ( & V_10 -> V_9 , V_149 , V_526 ) == 0 ) {
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_303 ( struct V_7 * V_10 )
{
T_10 V_527 ;
int V_528 ;
int V_529 = V_10 -> V_1 -> V_2 . V_498 &
V_530 ;
int V_531 = V_10 -> V_1 -> V_2 . V_498 & V_532 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_498 & V_530 ;
T_7 V_533 =
V_10 -> V_1 -> V_2 . V_498 & V_534 ;
bool V_87 = false ;
T_2 V_88 = 0 ;
V_527 = ( T_10 ) V_10 -> V_1 -> V_2 . V_418 ;
if ( V_10 -> V_1 -> V_2 . V_416 &
( 1ULL << V_535 ) )
V_528 = V_536 ;
else if ( V_10 -> V_1 -> V_2 . V_416 &
( 1ULL << V_537 ) )
V_528 = V_538 ;
else if ( V_533 )
V_528 = V_539 ;
else
V_528 = V_540 ;
if ( V_528 == V_539 ) {
switch ( type ) {
case V_541 :
V_10 -> V_9 . V_46 . V_542 = false ;
break;
case V_543 :
if ( V_10 -> V_1 -> V_2 . V_416 &
( 1ULL << V_544 ) ) {
V_87 = true ;
V_88 =
( T_2 ) V_10 -> V_1 -> V_2 . V_416 ;
}
F_275 ( & V_10 -> V_9 ) ;
break;
case V_545 :
F_276 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_528 != V_539 ||
V_529 == V_546 ||
( V_529 == V_543 &&
( V_531 == V_547 || V_531 == V_90 ) ) )
F_34 ( & V_10 -> V_9 ) ;
if ( V_529 != V_546 )
V_531 = - 1 ;
if ( F_304 ( & V_10 -> V_9 , V_527 , V_531 , V_528 ,
V_87 , V_88 ) == V_548 ) {
V_10 -> V_9 . V_424 -> V_430 = V_549 ;
V_10 -> V_9 . V_424 -> V_550 . V_551 = V_552 ;
V_10 -> V_9 . V_424 -> V_550 . V_553 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_305 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
return F_306 ( & V_10 -> V_9 ) ;
}
static int F_307 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_348 . V_554 ;
F_20 ( V_10 , V_555 ) ;
V_10 -> V_9 . V_46 . V_47 |= V_556 ;
V_10 -> V_557 = F_39 ( & V_10 -> V_9 ) ;
F_225 ( V_523 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_308 ( struct V_7 * V_10 )
{
if ( ! F_36 ( V_558 ) )
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
F_295 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_418 ) ;
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_309 ( struct V_7 * V_10 )
{
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
}
static int F_310 ( struct V_7 * V_10 )
{
int V_103 ;
if ( ! F_36 ( V_79 ) )
return F_309 ( V_10 ) ;
V_103 = F_311 ( & V_10 -> V_9 ) ;
return F_312 ( & V_10 -> V_9 , V_103 ) ;
}
static bool F_313 ( struct V_7 * V_10 ,
unsigned long V_104 )
{
unsigned long V_391 = V_10 -> V_9 . V_46 . V_391 ;
bool V_72 = false ;
T_1 V_29 ;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! F_10 ( & V_10 -> V_9 ) ||
( ! ( V_29 & ( 1ULL << V_237 ) ) ) )
return false ;
V_391 &= ~ V_393 ;
V_104 &= ~ V_393 ;
if ( V_391 ^ V_104 ) {
V_10 -> V_1 -> V_2 . V_456 = V_559 ;
V_72 = ( F_269 ( V_10 ) == V_469 ) ;
}
return V_72 ;
}
static int F_314 ( struct V_7 * V_10 )
{
int V_356 , V_560 ;
unsigned long V_104 ;
int V_103 ;
if ( ! F_36 ( V_558 ) )
return F_309 ( V_10 ) ;
if ( F_162 ( ( V_10 -> V_1 -> V_2 . V_418 & V_561 ) == 0 ) )
return F_309 ( V_10 ) ;
V_356 = V_10 -> V_1 -> V_2 . V_418 & V_562 ;
if ( V_10 -> V_1 -> V_2 . V_456 == V_559 )
V_560 = V_563 - V_486 ;
else
V_560 = V_10 -> V_1 -> V_2 . V_456 - V_486 ;
V_103 = 0 ;
if ( V_560 >= 16 ) {
V_560 -= 16 ;
V_104 = F_294 ( & V_10 -> V_9 , V_356 ) ;
switch ( V_560 ) {
case 0 :
if ( ! F_313 ( V_10 , V_104 ) )
V_103 = F_315 ( & V_10 -> V_9 , V_104 ) ;
else
return 1 ;
break;
case 3 :
V_103 = F_277 ( & V_10 -> V_9 , V_104 ) ;
break;
case 4 :
V_103 = F_316 ( & V_10 -> V_9 , V_104 ) ;
break;
case 8 :
V_103 = F_317 ( & V_10 -> V_9 , V_104 ) ;
break;
default:
F_318 ( 1 , L_12 , V_560 ) ;
F_216 ( & V_10 -> V_9 , V_230 ) ;
return 1 ;
}
} else {
switch ( V_560 ) {
case 0 :
V_104 = F_273 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_104 = V_10 -> V_9 . V_46 . V_468 ;
break;
case 3 :
V_104 = F_178 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_104 = F_319 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_104 = F_320 ( & V_10 -> V_9 ) ;
break;
default:
F_318 ( 1 , L_13 , V_560 ) ;
F_216 ( & V_10 -> V_9 , V_230 ) ;
return 1 ;
}
F_151 ( & V_10 -> V_9 , V_356 , V_104 ) ;
}
return F_312 ( & V_10 -> V_9 , V_103 ) ;
}
static int F_321 ( struct V_7 * V_10 )
{
int V_356 , V_564 ;
unsigned long V_104 ;
if ( V_10 -> V_9 . V_404 == 0 ) {
F_16 ( V_10 ) ;
V_10 -> V_9 . V_46 . V_413 |= V_414 ;
return 1 ;
}
if ( ! F_97 ( V_558 ) )
return F_309 ( V_10 ) ;
V_356 = V_10 -> V_1 -> V_2 . V_418 & V_562 ;
V_564 = V_10 -> V_1 -> V_2 . V_456 - V_488 ;
if ( V_564 >= 16 ) {
if ( ! F_322 ( & V_10 -> V_9 , V_564 - 16 ) )
return 1 ;
V_104 = F_294 ( & V_10 -> V_9 , V_356 ) ;
F_323 ( & V_10 -> V_9 , V_564 - 16 , V_104 ) ;
} else {
if ( ! F_322 ( & V_10 -> V_9 , V_564 ) )
return 1 ;
F_324 ( & V_10 -> V_9 , V_564 , & V_104 ) ;
F_151 ( & V_10 -> V_9 , V_356 , V_104 ) ;
}
F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_325 ( struct V_7 * V_10 )
{
struct V_423 * V_423 = V_10 -> V_9 . V_424 ;
int V_145 ;
T_4 V_565 = F_320 ( & V_10 -> V_9 ) ;
V_145 = F_314 ( V_10 ) ;
if ( F_326 ( & V_10 -> V_9 ) )
return V_145 ;
if ( V_565 <= F_320 ( & V_10 -> V_9 ) )
return V_145 ;
V_423 -> V_430 = V_566 ;
return 0 ;
}
static int F_327 ( struct V_8 * V_9 , struct V_567 * V_568 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_568 -> V_149 ) {
case V_569 : {
V_568 -> V_11 = V_10 -> V_1 -> V_2 . V_207 +
F_328 ( V_9 , F_329 () ) ;
break;
}
case V_570 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_515 ;
break;
#ifdef F_29
case V_571 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_516 ;
break;
case V_572 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_517 ;
break;
case V_350 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_514 ;
break;
case V_573 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_518 ;
break;
#endif
case V_574 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_519 ;
break;
case V_575 :
V_568 -> V_11 = V_10 -> V_521 ;
break;
case V_576 :
V_568 -> V_11 = V_10 -> V_520 ;
break;
case V_346 :
if ( ! F_97 ( V_345 ) )
return 1 ;
V_568 -> V_11 = V_10 -> V_347 ;
break;
case V_577 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_578 ;
break;
case V_163 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_579 ;
break;
case V_164 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_580 ;
break;
case V_165 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_581 ;
break;
case V_166 :
V_568 -> V_11 = V_10 -> V_1 -> V_65 . V_582 ;
break;
case V_136 :
V_568 -> V_11 = V_10 -> V_24 . V_583 ;
break;
case V_584 :
V_568 -> V_11 = V_10 -> V_24 . V_585 ;
break;
case V_586 :
V_568 -> V_11 = 0x01000065 ;
break;
case V_587 : {
int V_588 , V_589 ;
V_588 = F_330 ( V_9 ) ;
V_589 = F_331 ( V_9 ) ;
if ( V_588 < 0 || V_589 < 0 )
return F_332 ( V_9 , V_568 ) ;
V_568 -> V_11 = 0 ;
if ( V_588 == 0x15 &&
( V_589 >= 0x2 && V_589 < 0x20 ) )
V_568 -> V_11 = 0x1E ;
}
break;
default:
return F_332 ( V_9 , V_568 ) ;
}
return 0 ;
}
static int F_333 ( struct V_7 * V_10 )
{
T_2 V_590 = F_294 ( & V_10 -> V_9 , V_481 ) ;
struct V_567 V_568 ;
V_568 . V_149 = V_590 ;
V_568 . V_591 = false ;
if ( F_327 ( & V_10 -> V_9 , & V_568 ) ) {
F_334 ( V_590 ) ;
F_252 ( & V_10 -> V_9 , 0 ) ;
} else {
F_335 ( V_590 , V_568 . V_11 ) ;
F_151 ( & V_10 -> V_9 , V_507 ,
V_568 . V_11 & 0xffffffff ) ;
F_151 ( & V_10 -> V_9 , V_324 ,
V_568 . V_11 >> 32 ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_336 ( struct V_8 * V_9 , T_1 V_11 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_592 , V_593 ;
if ( V_11 & ~ V_594 )
return 1 ;
V_593 = V_594 ;
if ( V_10 -> V_24 . V_585 & V_595 )
V_593 &= ~ ( V_596 | V_595 ) ;
V_10 -> V_24 . V_585 &= ~ V_593 ;
V_10 -> V_24 . V_585 |= ( V_11 & V_593 ) ;
V_592 = V_10 -> V_24 . V_585 & V_595 ;
if ( V_592 && ( V_9 -> V_46 . V_61 & V_66 ) )
return 1 ;
return 0 ;
}
static int F_337 ( struct V_8 * V_9 , struct V_567 * V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_590 = V_49 -> V_149 ;
T_1 V_11 = V_49 -> V_11 ;
switch ( V_590 ) {
case V_569 :
F_338 ( V_9 , V_49 ) ;
break;
case V_570 :
V_10 -> V_1 -> V_65 . V_515 = V_11 ;
break;
#ifdef F_29
case V_571 :
V_10 -> V_1 -> V_65 . V_516 = V_11 ;
break;
case V_572 :
V_10 -> V_1 -> V_65 . V_517 = V_11 ;
break;
case V_350 :
V_10 -> V_1 -> V_65 . V_514 = V_11 ;
break;
case V_573 :
V_10 -> V_1 -> V_65 . V_518 = V_11 ;
break;
#endif
case V_574 :
V_10 -> V_1 -> V_65 . V_519 = V_11 ;
break;
case V_575 :
V_10 -> V_521 = V_11 ;
V_10 -> V_1 -> V_65 . V_521 = V_11 ;
break;
case V_576 :
V_10 -> V_520 = V_11 ;
V_10 -> V_1 -> V_65 . V_520 = V_11 ;
break;
case V_346 :
if ( ! F_97 ( V_345 ) )
return 1 ;
V_10 -> V_347 = V_11 ;
F_53 ( V_346 , V_10 -> V_347 ) ;
break;
case V_577 :
if ( ! F_97 ( V_597 ) ) {
F_339 ( V_9 , L_14 ,
V_83 , V_11 ) ;
break;
}
if ( V_11 & V_598 )
return 1 ;
V_10 -> V_1 -> V_65 . V_578 = V_11 ;
F_3 ( V_10 -> V_1 , V_599 ) ;
if ( V_11 & ( 1ULL << 0 ) )
F_83 ( V_10 ) ;
else
F_84 ( V_10 ) ;
break;
case V_136 :
V_10 -> V_24 . V_583 = V_11 ;
break;
case V_584 :
return F_336 ( V_9 , V_11 ) ;
case V_600 :
F_339 ( V_9 , L_15 , V_590 , V_11 ) ;
break;
case V_601 :
if ( F_115 ( V_9 ) )
F_6 ( F_4 ( V_9 ) , V_11 ) ;
default:
return F_340 ( V_9 , V_49 ) ;
}
return 0 ;
}
static int F_341 ( struct V_7 * V_10 )
{
struct V_567 V_49 ;
T_2 V_590 = F_294 ( & V_10 -> V_9 , V_481 ) ;
T_1 V_11 = F_301 ( & V_10 -> V_9 ) ;
V_49 . V_11 = V_11 ;
V_49 . V_149 = V_590 ;
V_49 . V_591 = false ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
if ( F_342 ( & V_10 -> V_9 , & V_49 ) ) {
F_343 ( V_590 , V_11 ) ;
F_252 ( & V_10 -> V_9 , 0 ) ;
} else {
F_344 ( V_590 , V_11 ) ;
F_34 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_345 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_418 )
return F_341 ( V_10 ) ;
else
return F_333 ( V_10 ) ;
}
static int F_346 ( struct V_7 * V_10 )
{
F_225 ( V_523 , & V_10 -> V_9 ) ;
F_180 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_218 &= ~ V_524 ;
F_3 ( V_10 -> V_1 , V_525 ) ;
++ V_10 -> V_9 . V_348 . V_602 ;
return 1 ;
}
static int F_347 ( struct V_7 * V_10 )
{
F_348 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_349 ( struct V_7 * V_10 )
{
F_34 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_350 ( struct V_7 * V_10 )
{
F_351 ( V_603 L_16 ) ;
return F_349 ( V_10 ) ;
}
static int F_352 ( struct V_7 * V_10 )
{
F_351 ( V_603 L_17 ) ;
return F_349 ( V_10 ) ;
}
static int F_353 ( struct V_7 * V_10 )
{
T_2 V_604 = V_10 -> V_1 -> V_2 . V_418 >> 32 ;
T_2 V_605 = V_10 -> V_1 -> V_2 . V_418 ;
T_2 V_295 = V_10 -> V_1 -> V_2 . V_416 >> 32 ;
T_2 V_149 = V_10 -> V_1 -> V_2 . V_416 & 0xFF ;
struct V_606 * V_296 = V_10 -> V_9 . V_46 . V_296 ;
F_354 ( V_10 -> V_9 . V_172 , V_604 , V_605 , V_295 , V_149 ) ;
switch ( V_295 ) {
case V_607 :
F_355 ( V_296 , V_608 , V_604 ) ;
F_355 ( V_296 , V_609 , V_605 ) ;
break;
case V_610 : {
int V_51 ;
struct V_8 * V_9 ;
struct V_174 * V_174 = V_10 -> V_9 . V_174 ;
struct V_606 * V_296 = V_10 -> V_9 . V_46 . V_296 ;
F_356 (i, vcpu, kvm) {
bool V_611 = F_357 ( V_9 , V_296 ,
V_605 & V_612 ,
F_358 ( V_604 ) ,
V_605 & V_613 ) ;
if ( V_611 && ! F_7 ( V_9 ) )
F_93 ( V_9 ) ;
}
break;
}
case V_614 :
break;
case V_615 :
F_359 ( 1 , L_18 ) ;
break;
default:
F_59 ( L_19 ) ;
}
return 1 ;
}
static T_2 * F_360 ( struct V_8 * V_9 , T_2 V_616 , bool V_617 )
{
struct V_169 * V_175 = & V_9 -> V_174 -> V_46 ;
int V_149 ;
T_2 * V_618 ;
int V_619 = F_361 ( V_616 ) ;
if ( ! V_619 )
return NULL ;
if ( V_617 ) {
V_149 = F_362 ( V_619 ) - 1 ;
if ( V_149 > 7 )
return NULL ;
} else {
int V_620 = ( V_619 & 0xf0 ) >> 4 ;
int V_296 = F_362 ( V_619 & 0x0f ) - 1 ;
if ( ( V_296 < 0 ) || ( V_296 > 7 ) ||
( V_620 >= 0xf ) )
return NULL ;
V_149 = ( V_620 << 2 ) + V_296 ;
}
V_618 = ( T_2 * ) F_96 ( V_175 -> V_211 ) ;
return & V_618 [ V_149 ] ;
}
static int F_363 ( struct V_8 * V_9 , T_4 V_621 , T_2 V_616 ,
bool V_622 )
{
bool V_617 ;
T_2 * V_15 , V_294 ;
V_617 = F_364 ( V_9 -> V_46 . V_296 , V_623 ) == V_624 ;
V_15 = F_360 ( V_9 , V_616 , V_617 ) ;
if ( ! V_15 )
return - V_127 ;
V_294 = F_8 ( * V_15 ) ;
V_294 &= ~ V_625 ;
V_294 |= ( V_621 & V_625 ) ;
if ( V_622 )
V_294 |= V_626 ;
else
V_294 &= ~ V_626 ;
F_126 ( * V_15 , V_294 ) ;
return 0 ;
}
static int F_365 ( struct V_8 * V_9 )
{
int V_72 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_616 = F_364 ( V_9 -> V_46 . V_296 , V_627 ) ;
if ( ! V_616 )
return 1 ;
V_72 = F_363 ( V_9 , V_9 -> V_172 , V_616 , true ) ;
if ( V_72 && V_10 -> V_628 ) {
F_363 ( V_9 , 0 , V_10 -> V_628 , false ) ;
V_10 -> V_628 = 0 ;
} else {
V_10 -> V_628 = V_616 ;
}
return V_72 ;
}
static int F_366 ( struct V_8 * V_9 )
{
T_1 * V_629 , * V_630 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_631 = F_364 ( V_9 -> V_46 . V_296 , V_632 ) ;
T_2 V_295 = ( V_631 >> 24 ) & 0xff ;
if ( V_9 -> V_172 == V_295 )
return 0 ;
V_629 = F_121 ( V_9 , V_9 -> V_172 ) ;
V_630 = F_121 ( V_9 , V_295 ) ;
if ( ! V_630 || ! V_629 )
return 1 ;
* V_630 = * V_629 ;
* V_629 = 0ULL ;
F_4 ( V_9 ) -> V_16 = V_630 ;
if ( V_10 -> V_628 )
F_365 ( V_9 ) ;
return 0 ;
}
static int F_367 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_169 * V_175 = & V_9 -> V_174 -> V_46 ;
T_2 V_633 = F_364 ( V_9 -> V_46 . V_296 , V_623 ) ;
T_2 V_634 = ( V_633 >> 28 ) & 0xf ;
if ( V_175 -> V_635 == V_634 )
return 0 ;
F_137 ( F_96 ( V_175 -> V_211 ) ) ;
V_175 -> V_635 = V_634 ;
if ( V_10 -> V_628 )
F_365 ( V_9 ) ;
return 0 ;
}
static int F_368 ( struct V_7 * V_10 )
{
struct V_606 * V_296 = V_10 -> V_9 . V_46 . V_296 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_418 &
V_636 ;
switch ( V_50 ) {
case V_632 :
if ( F_366 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_627 :
if ( F_365 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_623 :
F_367 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
F_355 ( V_296 , V_50 , F_364 ( V_296 , V_50 ) ) ;
return 1 ;
}
static bool F_369 ( T_2 V_50 )
{
bool V_72 = false ;
switch ( V_50 ) {
case V_632 :
case V_637 :
case V_638 :
case V_627 :
case V_623 :
case V_639 :
case V_640 :
case V_609 :
case V_641 :
case V_642 :
case V_643 :
case V_644 :
case V_645 :
case V_646 :
case V_647 :
case V_648 :
V_72 = true ;
break;
default:
break;
}
return V_72 ;
}
static int F_370 ( struct V_7 * V_10 )
{
int V_72 = 0 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_418 &
V_636 ;
T_2 V_649 = V_10 -> V_1 -> V_2 . V_416 &
V_650 ;
bool V_153 = ( V_10 -> V_1 -> V_2 . V_418 >> 32 ) &
V_651 ;
bool V_652 = F_369 ( V_50 ) ;
F_371 ( V_10 -> V_9 . V_172 , V_50 ,
V_652 , V_153 , V_649 ) ;
if ( V_652 ) {
F_359 ( ! V_153 , L_20 ) ;
V_72 = F_368 ( V_10 ) ;
} else {
V_72 = ( F_37 ( & V_10 -> V_9 , 0 ) == V_81 ) ;
}
return V_72 ;
}
static void F_372 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_221 * V_65 = & V_10 -> V_1 -> V_65 ;
F_59 ( L_21 ) ;
F_59 ( L_22 , L_23 , V_2 -> V_26 & 0xffff ) ;
F_59 ( L_22 , L_24 , V_2 -> V_26 >> 16 ) ;
F_59 ( L_22 , L_25 , V_2 -> V_27 & 0xffff ) ;
F_59 ( L_22 , L_26 , V_2 -> V_27 >> 16 ) ;
F_59 ( L_27 , L_28 , V_2 -> V_28 ) ;
F_59 ( L_29 , L_30 , V_2 -> V_29 ) ;
F_59 ( L_31 , L_32 , V_2 -> V_288 ) ;
F_59 ( L_29 , L_33 , V_2 -> V_259 ) ;
F_59 ( L_29 , L_34 , V_2 -> V_260 ) ;
F_59 ( L_29 , L_35 , V_2 -> V_207 ) ;
F_59 ( L_31 , L_36 , V_2 -> V_58 ) ;
F_59 ( L_31 , L_37 , V_2 -> V_407 ) ;
F_59 ( L_27 , L_38 , V_2 -> V_218 ) ;
F_59 ( L_27 , L_39 , V_2 -> V_497 ) ;
F_59 ( L_27 , L_40 , V_2 -> V_73 ) ;
F_59 ( L_27 , L_41 , V_2 -> V_456 ) ;
F_59 ( L_29 , L_42 , V_2 -> V_418 ) ;
F_59 ( L_29 , L_43 , V_2 -> V_416 ) ;
F_59 ( L_27 , L_44 , V_2 -> V_498 ) ;
F_59 ( L_27 , L_45 , V_2 -> V_499 ) ;
F_59 ( L_46 , L_47 , V_2 -> V_283 ) ;
F_59 ( L_29 , L_48 , V_2 -> V_450 ) ;
F_59 ( L_29 , L_49 , V_2 -> V_12 ) ;
F_59 ( L_27 , L_50 , V_2 -> V_97 ) ;
F_59 ( L_27 , L_51 , V_2 -> V_100 ) ;
F_59 ( L_46 , L_52 , V_2 -> V_162 ) ;
F_59 ( L_29 , L_53 , V_2 -> V_78 ) ;
F_59 ( L_29 , L_54 , V_2 -> V_209 ) ;
F_59 ( L_29 , L_55 , V_2 -> V_215 ) ;
F_59 ( L_29 , L_56 , V_2 -> V_216 ) ;
F_59 ( L_57 ) ;
F_59 ( L_58 ,
L_59 ,
V_65 -> V_262 . V_200 , V_65 -> V_262 . V_201 ,
V_65 -> V_262 . V_205 , V_65 -> V_262 . V_95 ) ;
F_59 ( L_58 ,
L_60 ,
V_65 -> V_94 . V_200 , V_65 -> V_94 . V_201 ,
V_65 -> V_94 . V_205 , V_65 -> V_94 . V_95 ) ;
F_59 ( L_58 ,
L_61 ,
V_65 -> V_263 . V_200 , V_65 -> V_263 . V_201 ,
V_65 -> V_263 . V_205 , V_65 -> V_263 . V_95 ) ;
F_59 ( L_58 ,
L_62 ,
V_65 -> V_264 . V_200 , V_65 -> V_264 . V_201 ,
V_65 -> V_264 . V_205 , V_65 -> V_264 . V_95 ) ;
F_59 ( L_58 ,
L_63 ,
V_65 -> V_265 . V_200 , V_65 -> V_265 . V_201 ,
V_65 -> V_265 . V_205 , V_65 -> V_265 . V_95 ) ;
F_59 ( L_58 ,
L_64 ,
V_65 -> V_266 . V_200 , V_65 -> V_266 . V_201 ,
V_65 -> V_266 . V_205 , V_65 -> V_266 . V_95 ) ;
F_59 ( L_58 ,
L_65 ,
V_65 -> V_269 . V_200 , V_65 -> V_269 . V_201 ,
V_65 -> V_269 . V_205 , V_65 -> V_269 . V_95 ) ;
F_59 ( L_58 ,
L_66 ,
V_65 -> V_271 . V_200 , V_65 -> V_271 . V_201 ,
V_65 -> V_271 . V_205 , V_65 -> V_271 . V_95 ) ;
F_59 ( L_58 ,
L_67 ,
V_65 -> V_270 . V_200 , V_65 -> V_270 . V_201 ,
V_65 -> V_270 . V_205 , V_65 -> V_270 . V_95 ) ;
F_59 ( L_58 ,
L_68 ,
V_65 -> V_273 . V_200 , V_65 -> V_273 . V_201 ,
V_65 -> V_273 . V_205 , V_65 -> V_273 . V_95 ) ;
F_59 ( L_69 ,
V_65 -> V_384 , V_65 -> V_61 ) ;
F_59 ( L_70 ,
L_71 , V_65 -> V_391 , L_72 , V_65 -> V_468 ) ;
F_59 ( L_70 ,
L_73 , V_65 -> V_286 , L_74 , V_65 -> V_281 ) ;
F_59 ( L_70 ,
L_75 , V_65 -> V_275 , L_76 , V_65 -> V_412 ) ;
F_59 ( L_70 ,
L_77 , V_65 -> V_91 , L_78 , V_65 -> V_354 ) ;
F_59 ( L_70 ,
L_79 , V_65 -> V_502 , L_80 , V_65 -> V_503 ) ;
F_59 ( L_70 ,
L_81 , V_65 -> V_515 , L_82 , V_65 -> V_516 ) ;
F_59 ( L_70 ,
L_83 , V_65 -> V_517 , L_84 , V_65 -> V_518 ) ;
F_59 ( L_70 ,
L_85 , V_65 -> V_514 ,
L_86 , V_65 -> V_519 ) ;
F_59 ( L_70 ,
L_87 , V_65 -> V_520 ,
L_88 , V_65 -> V_521 ) ;
F_59 ( L_70 ,
L_89 , V_65 -> V_284 , L_90 , V_65 -> V_578 ) ;
F_59 ( L_70 ,
L_91 , V_65 -> V_579 , L_92 , V_65 -> V_580 ) ;
F_59 ( L_70 ,
L_93 , V_65 -> V_581 ,
L_94 , V_65 -> V_582 ) ;
}
static void F_373 ( struct V_8 * V_9 , T_1 * V_653 , T_1 * V_654 )
{
struct V_18 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_653 = V_2 -> V_418 ;
* V_654 = V_2 -> V_416 ;
}
static int F_374 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_423 * V_423 = V_9 -> V_424 ;
T_2 V_456 = V_10 -> V_1 -> V_2 . V_456 ;
F_375 ( V_456 , V_9 , V_501 ) ;
V_9 -> V_46 . V_655 = ( V_456 == V_457 ) ;
if ( ! F_14 ( V_10 , V_225 ) )
V_9 -> V_46 . V_391 = V_10 -> V_1 -> V_65 . V_391 ;
if ( V_62 )
V_9 -> V_46 . V_286 = V_10 -> V_1 -> V_65 . V_286 ;
if ( F_162 ( V_10 -> V_24 . V_470 ) ) {
F_245 ( V_10 ) ;
V_10 -> V_24 . V_470 = false ;
return 1 ;
}
if ( F_10 ( V_9 ) ) {
int V_466 ;
F_376 ( V_10 -> V_1 -> V_65 . V_91 , V_456 ,
V_10 -> V_1 -> V_2 . V_418 ,
V_10 -> V_1 -> V_2 . V_416 ,
V_10 -> V_1 -> V_2 . V_498 ,
V_10 -> V_1 -> V_2 . V_499 ,
V_501 ) ;
V_466 = F_268 ( V_10 ) ;
if ( V_466 == V_483 )
V_466 = F_269 ( V_10 ) ;
if ( V_466 == V_469 )
return 1 ;
}
F_377 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_456 == V_491 ) {
V_423 -> V_430 = V_656 ;
V_423 -> V_657 . V_658
= V_10 -> V_1 -> V_2 . V_456 ;
F_59 ( L_95 ) ;
F_372 ( V_9 ) ;
return 0 ;
}
if ( F_31 ( V_10 -> V_1 -> V_2 . V_498 ) &&
V_456 != V_467 + V_229 &&
V_456 != V_457 && V_456 != V_659 &&
V_456 != V_473 && V_456 != V_474 )
F_38 ( V_85 L_96
L_97 ,
V_83 , V_10 -> V_1 -> V_2 . V_498 ,
V_456 ) ;
if ( V_456 >= F_378 ( V_660 )
|| ! V_660 [ V_456 ] ) {
F_359 ( 1 , L_98 , V_456 ) ;
F_216 ( V_9 , V_230 ) ;
return 1 ;
}
return V_660 [ V_456 ] ( V_10 ) ;
}
static void F_379 ( struct V_8 * V_9 )
{
int V_144 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_128 , V_144 ) ;
V_121 -> V_133 -> type = 9 ;
F_380 () ;
}
static void F_381 ( struct V_7 * V_10 )
{
int V_144 = F_57 () ;
struct V_120 * V_121 = F_60 ( V_128 , V_144 ) ;
if ( V_10 -> V_129 != V_121 -> V_129 )
F_200 ( V_10 , V_121 ) ;
}
static void F_382 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_97 = V_70 | V_661 ;
V_9 -> V_46 . V_47 |= V_662 ;
F_19 ( V_10 , V_555 ) ;
++ V_9 -> V_348 . V_663 ;
}
static inline void F_383 ( struct V_7 * V_10 , int V_664 )
{
struct V_18 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_497 = V_664 ;
V_2 -> V_218 &= ~ V_665 ;
V_2 -> V_218 |= V_524 |
( ( 0xf ) << V_666 ) ;
F_3 ( V_10 -> V_1 , V_525 ) ;
}
static void F_384 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_76 ( ! ( F_23 ( V_10 ) ) ) ;
F_385 ( V_9 -> V_46 . V_667 . V_86 ) ;
++ V_9 -> V_348 . V_668 ;
V_10 -> V_1 -> V_2 . V_97 = V_9 -> V_46 . V_667 . V_86 |
V_70 | V_71 ;
}
static inline bool F_386 ( struct V_8 * V_9 )
{
return F_10 ( V_9 ) && ( V_9 -> V_46 . V_47 & V_471 ) ;
}
static void F_387 ( struct V_8 * V_9 , int V_669 , int V_670 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_386 ( V_9 ) ||
F_115 ( V_9 ) )
return;
F_13 ( V_10 , V_228 ) ;
if ( V_670 == - 1 )
return;
if ( V_669 >= V_670 )
F_12 ( V_10 , V_228 ) ;
}
static void F_388 ( struct V_8 * V_9 , bool V_671 )
{
return;
}
static bool F_389 ( void )
{
return V_195 ;
}
static void F_390 ( struct V_8 * V_9 , int V_672 )
{
}
static void F_391 ( struct V_8 * V_9 , int V_673 )
{
}
static void F_392 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( ! V_195 )
return;
V_1 -> V_2 . V_218 &= ~ V_219 ;
F_3 ( V_1 , V_525 ) ;
}
static void F_393 ( struct V_8 * V_9 , T_1 * V_674 )
{
return;
}
static void F_394 ( struct V_8 * V_9 , int V_675 )
{
F_395 ( V_675 , V_9 -> V_46 . V_296 ) ;
F_396 () ;
if ( F_7 ( V_9 ) )
F_53 ( V_676 ,
F_145 ( V_9 -> V_144 ) ) ;
else
F_93 ( V_9 ) ;
}
static void F_397 ( struct V_7 * V_10 , struct V_677 * V_678 )
{
unsigned long V_168 ;
struct V_309 * V_679 ;
F_89 ( & V_10 -> V_311 , V_168 ) ;
F_142 (cur, &svm->ir_list, node) {
if ( V_679 -> V_11 != V_678 -> V_680 )
continue;
F_398 ( & V_679 -> V_681 ) ;
F_69 ( V_679 ) ;
break;
}
F_92 ( & V_10 -> V_311 , V_168 ) ;
}
static int F_399 ( struct V_7 * V_10 , struct V_677 * V_678 )
{
int V_72 = 0 ;
unsigned long V_168 ;
struct V_309 * V_310 ;
if ( V_678 -> V_680 && ( V_678 -> V_682 != 0 ) ) {
struct V_174 * V_174 = V_10 -> V_9 . V_174 ;
T_2 V_172 = F_87 ( V_678 -> V_682 ) ;
struct V_8 * V_683 = F_91 ( V_174 , V_172 ) ;
struct V_7 * V_684 ;
if ( ! V_683 ) {
V_72 = - V_127 ;
goto V_313;
}
V_684 = F_4 ( V_683 ) ;
F_397 ( V_684 , V_678 ) ;
}
V_310 = F_71 ( sizeof( struct V_309 ) , V_146 ) ;
if ( ! V_310 ) {
V_72 = - V_147 ;
goto V_313;
}
V_310 -> V_11 = V_678 -> V_680 ;
F_89 ( & V_10 -> V_311 , V_168 ) ;
F_400 ( & V_310 -> V_681 , & V_10 -> V_312 ) ;
F_92 ( & V_10 -> V_311 , V_168 ) ;
V_313:
return V_72 ;
}
static int
F_401 ( struct V_174 * V_174 , struct V_685 * V_686 ,
struct V_687 * V_688 , struct V_7 * * V_10 )
{
struct V_689 V_664 ;
struct V_8 * V_9 = NULL ;
F_402 ( V_174 , V_686 , & V_664 ) ;
if ( ! F_403 ( V_174 , & V_664 , & V_9 ) ) {
F_88 ( L_99 ,
V_83 , V_664 . V_649 ) ;
return - 1 ;
}
F_88 ( L_100 , V_83 ,
V_664 . V_649 ) ;
* V_10 = F_4 ( V_9 ) ;
V_688 -> V_690 = F_113 ( ( * V_10 ) -> V_209 ) ;
V_688 -> V_649 = V_664 . V_649 ;
return 0 ;
}
static int F_404 ( struct V_174 * V_174 , unsigned int V_691 ,
T_7 V_692 , bool V_671 )
{
struct V_685 * V_686 ;
struct V_693 * V_694 ;
int V_695 , V_72 = - V_127 ;
if ( ! F_140 ( V_174 ) ||
! F_405 ( V_696 ) )
return 0 ;
F_88 ( L_101 ,
V_83 , V_691 , V_692 , V_671 ) ;
V_695 = F_406 ( & V_174 -> V_697 ) ;
V_694 = F_407 ( V_174 -> V_698 , & V_174 -> V_697 ) ;
F_75 ( V_692 >= V_694 -> V_699 ) ;
F_408 (e, &irq_rt->map[guest_irq], link) {
struct V_687 V_688 ;
struct V_7 * V_10 = NULL ;
if ( V_686 -> type != V_700 )
continue;
if ( ! F_401 ( V_174 , V_686 , & V_688 , & V_10 ) && V_671 &&
F_115 ( & V_10 -> V_9 ) ) {
struct V_677 V_678 ;
V_678 . V_95 = F_113 ( V_10 -> V_209 ) & V_214 ;
V_678 . V_167 = F_409 ( V_174 -> V_46 . V_176 ,
V_10 -> V_9 . V_172 ) ;
V_678 . F_10 = true ;
V_678 . V_687 = & V_688 ;
V_72 = F_410 ( V_691 , & V_678 ) ;
if ( ! V_72 && V_678 . F_10 )
F_399 ( V_10 , & V_678 ) ;
} else {
struct V_677 V_678 ;
V_678 . F_10 = false ;
V_72 = F_410 ( V_691 , & V_678 ) ;
if ( ! V_72 && V_678 . V_682 ) {
int V_295 = F_87 ( V_678 . V_682 ) ;
struct V_8 * V_9 ;
V_9 = F_91 ( V_174 , V_295 ) ;
if ( V_9 )
F_397 ( F_4 ( V_9 ) , & V_678 ) ;
}
}
if ( ! V_72 && V_10 ) {
F_411 ( V_10 -> V_9 . V_172 ,
V_691 , V_686 -> V_701 ,
V_688 . V_649 ,
V_688 . V_690 , V_671 ) ;
}
if ( V_72 < 0 ) {
F_59 ( L_102 , V_83 ) ;
goto V_313;
}
}
V_72 = 0 ;
V_313:
F_412 ( & V_174 -> V_697 , V_695 ) ;
return V_72 ;
}
static int F_413 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
V_72 = ! ( V_1 -> V_2 . V_73 & V_74 ) &&
! ( V_10 -> V_9 . V_46 . V_47 & V_662 ) ;
V_72 = V_72 && F_23 ( V_10 ) && F_256 ( V_10 ) ;
return V_72 ;
}
static bool F_414 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_46 . V_47 & V_662 ) ;
}
static void F_415 ( struct V_8 * V_9 , bool V_702 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_702 ) {
V_10 -> V_9 . V_46 . V_47 |= V_662 ;
F_19 ( V_10 , V_555 ) ;
} else {
V_10 -> V_9 . V_46 . V_47 &= ~ V_662 ;
F_20 ( V_10 , V_555 ) ;
}
}
static int F_416 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
if ( ! F_23 ( V_10 ) ||
( V_1 -> V_2 . V_73 & V_74 ) )
return 0 ;
V_72 = ! ! ( F_274 ( V_9 ) & V_511 ) ;
if ( F_10 ( V_9 ) )
return V_72 && ! ( V_10 -> V_9 . V_46 . V_47 & V_471 ) ;
return V_72 ;
}
static void F_417 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_115 ( V_9 ) )
return;
if ( F_23 ( V_10 ) && F_254 ( V_10 ) ) {
F_179 ( V_10 ) ;
F_383 ( V_10 , 0x0 ) ;
}
}
static void F_418 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_46 . V_47 & ( V_662 | V_556 ) )
== V_662 )
return;
V_10 -> V_427 = true ;
V_10 -> V_1 -> V_65 . V_354 |= ( V_428 | V_429 ) ;
}
static int F_419 ( struct V_174 * V_174 , unsigned int V_57 )
{
return 0 ;
}
static void F_197 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_36 ( V_703 ) )
V_10 -> V_1 -> V_2 . V_407 = V_704 ;
else
V_10 -> V_129 -- ;
}
static void F_420 ( struct V_8 * V_9 )
{
}
static inline void F_421 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_386 ( V_9 ) )
return;
if ( ! F_14 ( V_10 , V_228 ) ) {
int V_705 = V_10 -> V_1 -> V_2 . V_218 & V_706 ;
F_317 ( V_9 , V_705 ) ;
}
}
static inline void F_422 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_705 ;
if ( F_386 ( V_9 ) ||
F_115 ( V_9 ) )
return;
V_705 = F_320 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_218 &= ~ V_706 ;
V_10 -> V_1 -> V_2 . V_218 |= V_705 & V_706 ;
}
static void F_377 ( struct V_7 * V_10 )
{
T_4 V_649 ;
int type ;
T_2 V_707 = V_10 -> V_1 -> V_2 . V_498 ;
unsigned V_96 = V_10 -> V_96 ;
V_10 -> V_96 = 0 ;
if ( ( V_10 -> V_9 . V_46 . V_47 & V_556 )
&& F_39 ( & V_10 -> V_9 ) != V_10 -> V_557 ) {
V_10 -> V_9 . V_46 . V_47 &= ~ ( V_662 | V_556 ) ;
F_225 ( V_523 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_46 . V_542 = false ;
F_275 ( & V_10 -> V_9 ) ;
F_276 ( & V_10 -> V_9 ) ;
if ( ! ( V_707 & V_534 ) )
return;
F_225 ( V_523 , & V_10 -> V_9 ) ;
V_649 = V_707 & V_708 ;
type = V_707 & V_530 ;
switch ( type ) {
case V_541 :
V_10 -> V_9 . V_46 . V_542 = true ;
break;
case V_543 :
if ( F_423 ( V_649 ) ) {
if ( V_649 == V_90 && V_96 &&
F_424 ( & V_10 -> V_9 , V_10 -> V_93 ) )
F_40 ( & V_10 -> V_9 ,
F_39 ( & V_10 -> V_9 ) -
V_96 ) ;
break;
}
if ( V_707 & V_709 ) {
T_2 V_103 = V_10 -> V_1 -> V_2 . V_499 ;
F_425 ( & V_10 -> V_9 , V_649 , V_103 ) ;
} else
F_426 ( & V_10 -> V_9 , V_649 ) ;
break;
case V_545 :
F_427 ( & V_10 -> V_9 , V_649 , false ) ;
break;
default:
break;
}
}
static void F_428 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_498 = V_2 -> V_97 ;
V_2 -> V_499 = V_2 -> V_100 ;
V_2 -> V_97 = 0 ;
F_377 ( V_10 ) ;
}
static void F_429 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_503 = V_9 -> V_46 . V_276 [ V_507 ] ;
V_10 -> V_1 -> V_65 . V_502 = V_9 -> V_46 . V_276 [ V_508 ] ;
V_10 -> V_1 -> V_65 . V_91 = V_9 -> V_46 . V_276 [ V_277 ] ;
if ( F_162 ( V_10 -> V_24 . V_470 ) )
return;
F_381 ( V_10 ) ;
F_422 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_468 = V_9 -> V_46 . V_468 ;
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
F_53 ( V_336 , V_10 -> V_337 . V_338 ) ;
#else
F_168 ( V_265 , V_10 -> V_337 . V_265 ) ;
#ifndef F_170
F_168 ( V_266 , V_10 -> V_337 . V_266 ) ;
#endif
#endif
F_379 ( V_9 ) ;
F_211 () ;
V_9 -> V_46 . V_468 = V_10 -> V_1 -> V_65 . V_468 ;
V_9 -> V_46 . V_276 [ V_507 ] = V_10 -> V_1 -> V_65 . V_503 ;
V_9 -> V_46 . V_276 [ V_508 ] = V_10 -> V_1 -> V_65 . V_502 ;
V_9 -> V_46 . V_276 [ V_277 ] = V_10 -> V_1 -> V_65 . V_91 ;
if ( F_162 ( V_10 -> V_1 -> V_2 . V_456 == V_474 ) )
F_430 ( & V_10 -> V_9 ) ;
F_26 () ;
if ( F_162 ( V_10 -> V_1 -> V_2 . V_456 == V_474 ) )
F_431 ( & V_10 -> V_9 ) ;
F_421 ( V_9 ) ;
V_10 -> V_78 = 0 ;
V_10 -> V_1 -> V_2 . V_407 = V_710 ;
if ( V_10 -> V_1 -> V_2 . V_456 == V_467 + V_229 )
V_10 -> V_417 = F_432 () ;
if ( V_62 ) {
V_9 -> V_46 . V_711 &= ~ ( 1 << V_357 ) ;
V_9 -> V_46 . V_712 &= ~ ( 1 << V_357 ) ;
}
if ( F_162 ( V_10 -> V_1 -> V_2 . V_456 ==
V_467 + V_231 ) )
F_224 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_433 ( struct V_8 * V_9 , unsigned long V_452 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_286 = V_452 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_197 ( V_9 ) ;
}
static void F_434 ( struct V_8 * V_9 , unsigned long V_452 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_450 = V_452 ;
F_3 ( V_10 -> V_1 , V_453 ) ;
V_10 -> V_1 -> V_65 . V_286 = F_178 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_197 ( V_9 ) ;
}
static int F_435 ( void )
{
T_1 V_713 ;
F_58 ( V_584 , V_713 ) ;
if ( V_713 & ( 1 << V_714 ) )
return 1 ;
return 0 ;
}
static void
F_436 ( struct V_8 * V_9 , unsigned char * V_715 )
{
V_715 [ 0 ] = 0x0f ;
V_715 [ 1 ] = 0x01 ;
V_715 [ 2 ] = 0xd9 ;
}
static void F_437 ( void * V_716 )
{
* ( int * ) V_716 = 0 ;
}
static bool F_438 ( void )
{
return false ;
}
static bool F_439 ( void )
{
return true ;
}
static T_1 F_440 ( struct V_8 * V_9 , T_11 V_717 , bool V_718 )
{
return 0 ;
}
static void F_441 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_719 * V_15 ;
V_10 -> V_504 = ! ! F_442 ( & V_10 -> V_9 ) ;
if ( ! F_115 ( V_9 ) )
return;
V_15 = F_443 ( V_9 , 1 , 0 ) ;
if ( V_15 )
V_15 -> V_590 &= ~ V_6 ( V_720 ) ;
}
static void F_444 ( T_2 V_721 , struct V_719 * V_15 )
{
switch ( V_721 ) {
case 0x1 :
if ( V_195 )
V_15 -> V_590 &= ~ V_6 ( V_720 ) ;
break;
case 0x80000001 :
if ( V_24 )
V_15 -> V_590 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_15 -> V_320 = 1 ;
V_15 -> V_722 = 8 ;
V_15 -> V_590 = 0 ;
V_15 -> V_723 = 0 ;
if ( F_97 ( V_79 ) )
V_15 -> V_723 |= V_724 ;
if ( V_62 )
V_15 -> V_723 |= V_725 ;
break;
}
}
static int F_445 ( void )
{
return V_726 ;
}
static bool F_446 ( void )
{
return F_97 ( V_345 ) ;
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
return false ;
}
static bool F_450 ( void )
{
return true ;
}
static int F_451 ( struct V_8 * V_9 ,
struct V_727 * V_68 ,
enum V_728 V_729 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_466 , V_72 = V_730 ;
struct V_731 V_732 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_68 -> V_29 >= F_378 ( V_733 ) )
goto V_313;
V_732 = V_733 [ V_68 -> V_29 ] ;
if ( V_729 != V_732 . V_729 )
goto V_313;
switch ( V_732 . V_456 ) {
case V_486 :
if ( V_68 -> V_29 == V_734 )
V_732 . V_456 += V_68 -> V_735 ;
break;
case V_563 : {
unsigned long V_391 , V_104 ;
T_1 V_29 ;
if ( V_68 -> V_29 == V_736 )
V_732 . V_456 += V_68 -> V_735 ;
if ( V_732 . V_456 != V_563 ||
V_68 -> V_29 == V_737 )
break;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! ( V_29 & ( 1ULL << V_237 ) ) )
break;
V_391 = V_9 -> V_46 . V_391 & ~ V_393 ;
V_104 = V_68 -> V_738 & ~ V_393 ;
if ( V_68 -> V_29 == V_739 ) {
V_391 &= 0xfUL ;
V_104 &= 0xfUL ;
if ( V_391 & V_506 )
V_104 |= V_506 ;
}
if ( V_391 ^ V_104 )
V_732 . V_456 = V_559 ;
break;
}
case V_488 :
case V_740 :
V_732 . V_456 += V_68 -> V_735 ;
break;
case V_484 :
if ( V_68 -> V_29 == V_741 )
V_1 -> V_2 . V_418 = 1 ;
else
V_1 -> V_2 . V_418 = 0 ;
break;
case V_742 :
if ( V_68 -> V_743 != V_744 )
goto V_313;
case V_485 : {
T_1 V_745 ;
T_2 V_746 ;
if ( V_68 -> V_29 == V_747 ||
V_68 -> V_29 == V_748 ) {
V_745 = ( ( V_68 -> V_738 & 0xffff ) << 16 ) |
V_446 ;
V_746 = V_68 -> V_749 ;
} else {
V_745 = ( V_68 -> V_750 & 0xffff ) << 16 ;
V_746 = V_68 -> V_751 ;
}
if ( V_68 -> V_29 == V_752 ||
V_68 -> V_29 == V_748 )
V_745 |= V_445 ;
if ( V_68 -> V_743 )
V_745 |= V_753 ;
V_746 = F_452 ( V_746 , 4u ) ;
V_745 |= V_746 << V_448 ;
V_745 |= ( T_2 ) V_68 -> V_754 << ( V_755 - 1 ) ;
V_1 -> V_2 . V_418 = V_745 ;
V_1 -> V_2 . V_416 = V_68 -> V_78 ;
break;
}
default:
break;
}
if ( F_36 ( V_79 ) )
V_1 -> V_2 . V_78 = V_68 -> V_78 ;
V_1 -> V_2 . V_456 = V_732 . V_456 ;
V_466 = F_269 ( V_10 ) ;
V_72 = ( V_466 == V_469 ) ? V_756
: V_730 ;
V_313:
return V_72 ;
}
static void F_453 ( struct V_8 * V_9 )
{
F_213 () ;
asm("nop");
F_211 () ;
}
static void F_454 ( struct V_8 * V_9 , int V_144 )
{
}
static inline void F_455 ( struct V_8 * V_9 )
{
if ( F_366 ( V_9 ) != 0 )
return;
if ( F_367 ( V_9 ) != 0 )
return;
F_365 ( V_9 ) ;
}
static void F_456 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_757 &= 0x1ff ;
}
static int T_5 F_457 ( void )
{
return F_458 ( & V_758 , sizeof( struct V_7 ) ,
F_459 ( struct V_7 ) , V_759 ) ;
}
static void T_6 F_460 ( void )
{
F_461 () ;
}
