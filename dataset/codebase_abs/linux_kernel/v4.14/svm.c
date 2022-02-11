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
static inline bool F_21 ( struct V_7 * V_10 )
{
return ! ! ( V_10 -> V_1 -> V_2 . V_46 & V_47 ) ;
}
static inline void F_22 ( struct V_7 * V_10 )
{
if ( F_21 ( V_10 ) )
V_10 -> V_1 -> V_2 . V_46 |= V_48 ;
else
V_10 -> V_9 . V_49 . V_50 |= V_51 ;
}
static inline void F_23 ( struct V_7 * V_10 )
{
if ( F_21 ( V_10 ) )
V_10 -> V_1 -> V_2 . V_46 &= ~ V_48 ;
else
V_10 -> V_9 . V_49 . V_50 &= ~ V_51 ;
}
static inline bool F_24 ( struct V_7 * V_10 )
{
if ( F_21 ( V_10 ) )
return ! ! ( V_10 -> V_1 -> V_2 . V_46 & V_48 ) ;
else
return ! ! ( V_10 -> V_9 . V_49 . V_50 & V_51 ) ;
}
static T_2 F_25 ( T_2 V_52 )
{
T_2 V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
if ( V_52 < V_56 [ V_54 ] ||
V_52 >= V_56 [ V_54 ] + V_57 )
continue;
V_53 = ( V_52 - V_56 [ V_54 ] ) / 4 ;
V_53 += ( V_54 * V_58 ) ;
return V_53 / 4 ;
}
return V_59 ;
}
static inline void F_26 ( void )
{
asm volatile (__ex(SVM_CLGI));
}
static inline void F_27 ( void )
{
asm volatile (__ex(SVM_STGI));
}
static inline void F_28 ( unsigned long V_60 , T_2 V_61 )
{
asm volatile (__ex(SVM_INVLPGA) : : "a"(addr), "c"(asid));
}
static int F_29 ( struct V_8 * V_9 )
{
#ifdef F_30
return V_62 ;
#else
return V_63 ;
#endif
}
static void F_31 ( struct V_8 * V_9 , T_1 V_64 )
{
V_9 -> V_49 . V_64 = V_64 ;
if ( ! V_65 && ! ( V_64 & V_66 ) )
V_64 &= ~ V_67 ;
F_4 ( V_9 ) -> V_1 -> V_68 . V_64 = V_64 | V_69 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_70 ) ;
}
static int F_32 ( T_2 V_71 )
{
V_71 &= V_72 | V_73 ;
return V_71 == ( V_73 | V_74 ) ;
}
static T_2 F_33 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_75 = 0 ;
if ( V_10 -> V_1 -> V_2 . V_76 & V_77 )
V_75 = V_78 | V_79 ;
return V_75 ;
}
static void F_34 ( struct V_8 * V_9 , int V_80 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_80 == 0 )
V_10 -> V_1 -> V_2 . V_76 &= ~ V_77 ;
else
V_10 -> V_1 -> V_2 . V_76 |= V_77 ;
}
static void F_35 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_81 != 0 ) {
F_36 ( ! F_37 ( V_82 ) ) ;
V_10 -> V_81 = V_10 -> V_1 -> V_2 . V_81 ;
}
if ( ! V_10 -> V_81 ) {
if ( F_38 ( V_9 , V_83 ) !=
V_84 )
F_39 ( V_85 L_1 , V_86 ) ;
return;
}
if ( V_10 -> V_81 - F_40 ( V_9 ) > V_87 )
F_39 ( V_88 L_2 ,
V_86 , F_40 ( V_9 ) , V_10 -> V_81 ) ;
F_41 ( V_9 , V_10 -> V_81 ) ;
F_34 ( V_9 , 0 ) ;
}
static void F_42 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
unsigned V_89 = V_9 -> V_49 . V_90 . V_89 ;
bool V_91 = V_9 -> V_49 . V_90 . V_91 ;
bool V_92 = V_9 -> V_49 . V_90 . V_93 ;
T_2 V_94 = V_9 -> V_49 . V_90 . V_94 ;
if ( ! V_92 &&
F_43 ( V_10 , V_89 , V_91 , V_94 ) )
return;
if ( V_89 == V_95 && ! F_37 ( V_82 ) ) {
unsigned long V_96 , V_97 = F_40 ( & V_10 -> V_9 ) ;
F_35 ( & V_10 -> V_9 ) ;
V_96 = F_40 ( & V_10 -> V_9 ) ;
V_10 -> V_98 = V_96 + V_10 -> V_1 -> V_68 . V_99 . V_100 ;
V_10 -> V_101 = V_96 - V_97 ;
}
V_10 -> V_1 -> V_2 . V_102 = V_89
| V_73
| ( V_91 ? V_103 : 0 )
| V_104 ;
V_10 -> V_1 -> V_2 . V_105 = V_94 ;
}
static void F_44 ( void )
{
T_2 V_106 , V_107 ;
int V_108 ;
T_1 V_109 ;
if ( ! F_45 ( V_110 ) )
return;
V_109 = F_46 ( V_111 , & V_108 ) ;
if ( V_108 )
return;
V_109 |= ( 1ULL << 47 ) ;
V_106 = F_47 ( V_109 ) ;
V_107 = F_48 ( V_109 ) ;
F_49 ( V_111 , V_106 , V_107 ) ;
V_112 = true ;
}
static void F_50 ( struct V_8 * V_9 )
{
V_9 -> V_49 . V_113 . V_114 = ( V_115 >= 3 ) ? ( V_115 ) : 3 ;
V_9 -> V_49 . V_113 . V_116 = V_117 & ~ ( 6ULL ) ;
if ( V_115 == 0 && V_118 . V_119 == 0x10 )
V_9 -> V_49 . V_113 . V_116 |= 1 ;
}
static int F_51 ( void )
{
const char * V_120 ;
if ( ! F_52 ( & V_120 ) ) {
F_39 ( V_121 L_3 , V_120 ) ;
return 0 ;
}
return 1 ;
}
static void F_53 ( void )
{
if ( F_37 ( V_122 ) )
F_54 ( V_123 , V_124 ) ;
F_55 () ;
F_56 () ;
}
static int F_57 ( void )
{
struct V_125 * V_126 ;
T_3 V_64 ;
struct V_127 * V_128 ;
int V_129 = F_58 () ;
F_59 ( V_130 , V_64 ) ;
if ( V_64 & V_69 )
return - V_131 ;
if ( ! F_51 () ) {
F_60 ( L_4 , V_86 , V_129 ) ;
return - V_132 ;
}
V_126 = F_61 ( V_133 , V_129 ) ;
if ( ! V_126 ) {
F_60 ( L_5 , V_86 , V_129 ) ;
return - V_132 ;
}
V_126 -> V_134 = 1 ;
V_126 -> V_135 = F_62 ( V_136 ) - 1 ;
V_126 -> V_137 = V_126 -> V_135 + 1 ;
V_128 = F_63 () ;
V_126 -> V_138 = (struct V_139 * ) ( V_128 + V_140 ) ;
F_54 ( V_130 , V_64 | V_69 ) ;
F_54 ( V_141 , F_64 ( V_126 -> V_142 ) << V_143 ) ;
if ( F_37 ( V_122 ) ) {
F_54 ( V_123 , V_124 ) ;
F_65 ( V_144 , V_124 ) ;
}
if ( F_66 ( & V_118 , V_145 ) ) {
T_3 V_146 , V_116 = 0 ;
int V_108 ;
V_146 = F_46 ( V_147 , & V_108 ) ;
if ( ! V_108 )
V_116 = F_46 ( V_148 ,
& V_108 ) ;
if ( V_108 )
V_117 = V_115 = 0 ;
else {
if ( V_146 < V_115 )
V_115 = V_146 ;
V_117 |= V_116 ;
V_117 &= ( 1ULL << V_115 ) - 1 ;
}
} else
V_117 = V_115 = 0 ;
F_44 () ;
F_67 () ;
return 0 ;
}
static void F_68 ( int V_149 )
{
struct V_125 * V_126 = F_61 ( V_133 , F_58 () ) ;
if ( ! V_126 )
return;
F_61 ( V_133 , F_58 () ) = NULL ;
F_69 ( V_126 -> V_142 ) ;
F_70 ( V_126 ) ;
}
static int F_71 ( int V_149 )
{
struct V_125 * V_126 ;
int V_150 ;
V_126 = F_72 ( sizeof( struct V_125 ) , V_151 ) ;
if ( ! V_126 )
return - V_152 ;
V_126 -> V_149 = V_149 ;
V_126 -> V_142 = F_73 ( V_151 ) ;
V_150 = - V_152 ;
if ( ! V_126 -> V_142 )
goto V_153;
F_61 ( V_133 , V_149 ) = V_126 ;
return 0 ;
V_153:
F_70 ( V_126 ) ;
return V_150 ;
}
static bool F_74 ( T_2 V_154 )
{
int V_54 ;
for ( V_54 = 0 ; V_155 [ V_54 ] . V_154 != V_59 ; V_54 ++ )
if ( V_155 [ V_54 ] . V_154 == V_154 )
return true ;
return false ;
}
static void F_75 ( T_2 * V_156 , unsigned V_52 ,
int V_157 , int V_158 )
{
T_4 V_159 , V_160 ;
unsigned long V_161 ;
T_2 V_53 ;
F_76 ( ! F_74 ( V_52 ) ) ;
V_53 = F_25 ( V_52 ) ;
V_159 = 2 * ( V_52 & 0x0f ) ;
V_160 = 2 * ( V_52 & 0x0f ) + 1 ;
V_161 = V_156 [ V_53 ] ;
F_77 ( V_53 == V_59 ) ;
V_157 ? F_78 ( V_159 , & V_161 ) : F_79 ( V_159 , & V_161 ) ;
V_158 ? F_78 ( V_160 , & V_161 ) : F_79 ( V_160 , & V_161 ) ;
V_156 [ V_53 ] = V_161 ;
}
static void F_80 ( T_2 * V_156 )
{
int V_54 ;
memset ( V_156 , 0xff , V_162 * ( 1 << V_163 ) ) ;
for ( V_54 = 0 ; V_155 [ V_54 ] . V_154 != V_59 ; V_54 ++ ) {
if ( ! V_155 [ V_54 ] . V_164 )
continue;
F_75 ( V_156 , V_155 [ V_54 ] . V_154 , 1 , 1 ) ;
}
}
static void F_81 ( T_2 V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_165 ; ++ V_54 ) {
if ( V_166 [ V_54 ] == V_53 )
return;
if ( V_166 [ V_54 ] != V_59 )
continue;
V_166 [ V_54 ] = V_53 ;
return;
}
F_82 () ;
}
static void F_83 ( void )
{
int V_54 ;
memset ( V_166 , 0xff , sizeof( V_166 ) ) ;
for ( V_54 = 0 ; V_155 [ V_54 ] . V_154 != V_59 ; V_54 ++ ) {
T_2 V_53 ;
V_53 = F_25 ( V_155 [ V_54 ] . V_154 ) ;
F_77 ( V_53 == V_59 ) ;
F_81 ( V_53 ) ;
}
}
static void F_84 ( struct V_7 * V_10 )
{
T_2 * V_156 = V_10 -> V_156 ;
V_10 -> V_1 -> V_2 . V_167 |= V_168 ;
F_75 ( V_156 , V_169 , 1 , 1 ) ;
F_75 ( V_156 , V_170 , 1 , 1 ) ;
F_75 ( V_156 , V_171 , 1 , 1 ) ;
F_75 ( V_156 , V_172 , 1 , 1 ) ;
}
static void F_85 ( struct V_7 * V_10 )
{
T_2 * V_156 = V_10 -> V_156 ;
V_10 -> V_1 -> V_2 . V_167 &= ~ V_168 ;
F_75 ( V_156 , V_169 , 0 , 0 ) ;
F_75 ( V_156 , V_170 , 0 , 0 ) ;
F_75 ( V_156 , V_171 , 0 , 0 ) ;
F_75 ( V_156 , V_172 , 0 , 0 ) ;
}
static void F_86 ( struct V_7 * V_10 )
{
V_10 -> V_173 = false ;
if ( ! ( V_10 -> V_9 . V_174 & V_175 ) ) {
if ( ! ( V_10 -> V_176 & V_177 ) )
V_10 -> V_1 -> V_68 . V_178 &= ~ V_177 ;
if ( ! ( V_10 -> V_176 & V_179 ) )
V_10 -> V_1 -> V_68 . V_178 &= ~ V_179 ;
}
}
static int F_87 ( T_2 V_180 )
{
unsigned long V_181 ;
struct V_182 * V_183 = NULL ;
struct V_8 * V_9 = NULL ;
T_2 V_184 = F_88 ( V_180 ) ;
T_2 V_185 = F_89 ( V_180 ) ;
F_90 ( L_6 , V_86 , V_184 , V_185 ) ;
F_91 ( & V_186 , V_181 ) ;
F_92 (svm_vm_data_hash, ka, hnode, vm_id) {
struct V_187 * V_187 = F_5 ( V_183 , struct V_187 , V_49 ) ;
struct V_182 * V_188 = & V_187 -> V_49 ;
if ( V_188 -> V_189 != V_184 )
continue;
V_9 = F_93 ( V_187 , V_185 ) ;
break;
}
F_94 ( & V_186 , V_181 ) ;
if ( ! V_9 )
return 0 ;
if ( V_9 -> V_190 == V_191 )
F_95 ( V_9 ) ;
return 0 ;
}
static T_5 int F_96 ( void )
{
int V_149 ;
struct V_192 * V_193 ;
void * V_194 ;
int V_150 ;
V_193 = F_97 ( V_151 , V_195 ) ;
if ( ! V_193 )
return - V_152 ;
V_194 = F_98 ( V_193 ) ;
memset ( V_194 , 0xff , V_162 * ( 1 << V_195 ) ) ;
V_196 = F_64 ( V_193 ) << V_143 ;
F_83 () ;
if ( F_99 ( V_197 ) )
F_100 ( V_198 ) ;
if ( F_99 ( V_199 ) )
F_100 ( V_200 ) ;
if ( F_99 ( V_122 ) ) {
V_201 = true ;
V_202 = V_203 ;
V_204 = 32 ;
}
if ( V_24 ) {
F_39 ( V_121 L_7 ) ;
F_100 ( V_69 | V_205 ) ;
}
F_101 (cpu) {
V_150 = F_71 ( V_149 ) ;
if ( V_150 )
goto V_108;
}
if ( ! F_99 ( V_206 ) )
V_65 = false ;
if ( V_65 && ! V_207 ) {
F_39 ( V_121 L_8 ) ;
V_65 = false ;
}
if ( V_65 ) {
F_39 ( V_121 L_9 ) ;
F_102 () ;
} else
F_103 () ;
if ( V_208 ) {
if ( ! V_65 ||
! F_99 ( V_209 ) ||
! F_104 ( V_210 ) ) {
V_208 = false ;
} else {
F_105 ( L_10 ) ;
F_106 ( & F_87 ) ;
}
}
if ( V_211 ) {
if ( ! V_65 ||
! F_99 ( V_212 ) ||
! F_104 ( F_30 ) ) {
V_211 = false ;
} else {
F_105 ( L_11 ) ;
}
}
if ( V_213 ) {
if ( ! F_99 ( V_214 ) )
V_213 = false ;
else
F_105 ( L_12 ) ;
}
return 0 ;
V_108:
F_107 ( V_193 , V_195 ) ;
V_196 = 0 ;
return V_150 ;
}
static T_6 void F_108 ( void )
{
int V_149 ;
F_101 (cpu)
F_68 ( V_149 ) ;
F_107 ( F_109 ( V_196 >> V_143 ) , V_195 ) ;
V_196 = 0 ;
}
static void F_110 ( struct V_215 * V_216 )
{
V_216 -> V_217 = 0 ;
V_216 -> V_218 = V_219 | V_220 |
V_221 ;
V_216 -> V_222 = 0xffff ;
V_216 -> V_100 = 0 ;
}
static void F_111 ( struct V_215 * V_216 , T_7 type )
{
V_216 -> V_217 = 0 ;
V_216 -> V_218 = V_219 | type ;
V_216 -> V_222 = 0xffff ;
V_216 -> V_100 = 0 ;
}
static void F_112 ( struct V_8 * V_9 , T_1 V_53 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_223 = 0 ;
if ( F_10 ( V_9 ) ) {
V_223 = V_10 -> V_1 -> V_2 . V_224 -
V_10 -> V_24 . V_25 -> V_2 . V_224 ;
V_10 -> V_24 . V_25 -> V_2 . V_224 = V_53 ;
} else
F_113 ( V_9 -> V_185 ,
V_10 -> V_1 -> V_2 . V_224 ,
V_53 ) ;
V_10 -> V_1 -> V_2 . V_224 = V_53 + V_223 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_114 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_182 * V_188 = & V_10 -> V_9 . V_187 -> V_49 ;
T_8 V_225 = F_115 ( F_116 ( V_10 -> V_226 ) ) ;
T_8 V_227 = F_115 ( F_116 ( V_188 -> V_228 ) ) ;
T_8 V_229 = F_115 ( F_116 ( V_188 -> V_230 ) ) ;
V_1 -> V_2 . V_226 = V_225 & V_231 ;
V_1 -> V_2 . V_232 = V_227 & V_231 ;
V_1 -> V_2 . V_233 = V_229 & V_231 ;
V_1 -> V_2 . V_233 |= V_234 ;
V_1 -> V_2 . V_46 |= V_235 ;
}
static void F_117 ( struct V_7 * V_10 )
{
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_236 * V_68 = & V_10 -> V_1 -> V_68 ;
V_10 -> V_9 . V_49 . V_50 = 0 ;
F_12 ( V_10 , V_237 ) ;
F_12 ( V_10 , V_238 ) ;
F_12 ( V_10 , V_239 ) ;
F_12 ( V_10 , V_240 ) ;
F_12 ( V_10 , V_241 ) ;
F_12 ( V_10 , V_242 ) ;
if ( ! F_118 ( & V_10 -> V_9 ) )
F_12 ( V_10 , V_243 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_244 ) ;
F_17 ( V_10 , V_245 ) ;
F_17 ( V_10 , V_246 ) ;
F_17 ( V_10 , V_247 ) ;
F_17 ( V_10 , V_248 ) ;
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
F_19 ( V_10 , V_264 ) ;
F_19 ( V_10 , V_265 ) ;
F_19 ( V_10 , V_266 ) ;
F_19 ( V_10 , V_267 ) ;
F_19 ( V_10 , V_268 ) ;
F_19 ( V_10 , V_269 ) ;
F_19 ( V_10 , V_270 ) ;
F_19 ( V_10 , V_271 ) ;
if ( ! F_119 () ) {
F_19 ( V_10 , V_272 ) ;
F_19 ( V_10 , V_273 ) ;
}
V_2 -> V_274 = F_115 ( V_196 ) ;
V_2 -> V_275 = F_115 ( F_120 ( V_10 -> V_156 ) ) ;
V_2 -> V_46 = V_276 ;
F_110 ( & V_68 -> V_277 ) ;
F_110 ( & V_68 -> V_278 ) ;
F_110 ( & V_68 -> V_279 ) ;
F_110 ( & V_68 -> V_280 ) ;
F_110 ( & V_68 -> V_281 ) ;
V_68 -> V_99 . V_217 = 0xf000 ;
V_68 -> V_99 . V_100 = 0xffff0000 ;
V_68 -> V_99 . V_218 = V_282 | V_219 |
V_220 | V_283 ;
V_68 -> V_99 . V_222 = 0xffff ;
V_68 -> V_284 . V_222 = 0xffff ;
V_68 -> V_285 . V_222 = 0xffff ;
F_111 ( & V_68 -> V_286 , V_287 ) ;
F_111 ( & V_68 -> V_288 , V_289 ) ;
F_31 ( & V_10 -> V_9 , 0 ) ;
V_68 -> V_290 = 0xffff0ff0 ;
F_121 ( & V_10 -> V_9 , 2 ) ;
V_68 -> V_96 = 0x0000fff0 ;
V_10 -> V_9 . V_49 . V_291 [ V_292 ] = V_68 -> V_96 ;
F_122 ( & V_10 -> V_9 , V_293 | V_294 | V_295 ) ;
F_123 ( & V_10 -> V_9 ) ;
V_68 -> V_296 = V_297 ;
if ( V_65 ) {
V_2 -> V_298 = 1 ;
F_20 ( V_10 , V_257 ) ;
F_18 ( V_10 , V_244 ) ;
F_13 ( V_10 , V_238 ) ;
F_13 ( V_10 , V_241 ) ;
V_68 -> V_299 = V_10 -> V_9 . V_49 . V_300 ;
V_68 -> V_301 = 0 ;
V_68 -> V_296 = 0 ;
}
V_10 -> V_134 = 0 ;
V_10 -> V_24 . V_1 = 0 ;
V_10 -> V_9 . V_49 . V_50 = 0 ;
if ( F_99 ( V_302 ) ) {
V_2 -> V_303 = 3000 ;
F_19 ( V_10 , V_304 ) ;
}
if ( F_118 ( & V_10 -> V_9 ) )
F_114 ( V_10 ) ;
if ( V_211 ) {
F_20 ( V_10 , V_265 ) ;
F_20 ( V_10 , V_266 ) ;
V_10 -> V_1 -> V_2 . V_167 |= V_305 ;
}
if ( V_213 ) {
F_20 ( V_10 , V_267 ) ;
F_20 ( V_10 , V_268 ) ;
V_10 -> V_1 -> V_2 . V_46 |= V_47 ;
}
F_1 ( V_10 -> V_1 ) ;
F_22 ( V_10 ) ;
}
static T_1 * F_124 ( struct V_8 * V_9 ,
unsigned int V_154 )
{
T_1 * V_306 ;
struct V_182 * V_188 = & V_9 -> V_187 -> V_49 ;
if ( V_154 >= V_234 )
return NULL ;
V_306 = F_98 ( V_188 -> V_230 ) ;
return & V_306 [ V_154 ] ;
}
static int F_125 ( struct V_8 * V_9 )
{
struct V_187 * V_187 = V_9 -> V_187 ;
int V_75 ;
if ( V_187 -> V_49 . V_307 )
return 0 ;
V_75 = F_126 ( V_187 ,
V_308 ,
V_309 ,
V_162 ) ;
if ( V_75 )
return V_75 ;
V_187 -> V_49 . V_307 = true ;
return 0 ;
}
static int F_127 ( struct V_8 * V_9 )
{
int V_75 ;
T_1 * V_15 , V_310 ;
int V_311 = V_9 -> V_185 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_75 = F_125 ( V_9 ) ;
if ( V_75 )
return V_75 ;
if ( V_311 >= V_234 )
return - V_132 ;
if ( ! V_10 -> V_9 . V_49 . V_312 -> V_291 )
return - V_132 ;
V_10 -> V_226 = F_128 ( V_10 -> V_9 . V_49 . V_312 -> V_291 ) ;
V_15 = F_124 ( V_9 , V_311 ) ;
if ( ! V_15 )
return - V_132 ;
V_310 = F_8 ( * V_15 ) ;
V_310 = F_115 ( ( F_116 ( V_10 -> V_226 ) &
V_313 ) |
V_314 ) ;
F_129 ( * V_15 , V_310 ) ;
V_10 -> V_16 = V_15 ;
return 0 ;
}
static void F_130 ( struct V_187 * V_187 )
{
unsigned long V_181 ;
struct V_182 * V_188 = & V_187 -> V_49 ;
if ( ! V_208 )
return;
if ( V_188 -> V_228 )
F_69 ( V_188 -> V_228 ) ;
if ( V_188 -> V_230 )
F_69 ( V_188 -> V_230 ) ;
F_91 ( & V_186 , V_181 ) ;
F_131 ( & V_188 -> V_315 ) ;
F_94 ( & V_186 , V_181 ) ;
}
static int F_132 ( struct V_187 * V_187 )
{
unsigned long V_181 ;
int V_108 = - V_152 ;
struct V_182 * V_188 = & V_187 -> V_49 ;
struct V_192 * V_316 ;
struct V_192 * V_317 ;
struct V_182 * V_183 ;
T_2 V_184 ;
if ( ! V_208 )
return 0 ;
V_316 = F_73 ( V_151 ) ;
if ( ! V_316 )
goto V_318;
V_188 -> V_230 = V_316 ;
F_133 ( F_98 ( V_316 ) ) ;
V_317 = F_73 ( V_151 ) ;
if ( ! V_317 )
goto V_318;
V_188 -> V_228 = V_317 ;
F_133 ( F_98 ( V_317 ) ) ;
F_91 ( & V_186 , V_181 ) ;
V_319:
V_184 = V_320 = ( V_320 + 1 ) & V_321 ;
if ( V_184 == 0 ) {
V_322 = 1 ;
goto V_319;
}
if ( V_322 ) {
F_92 (svm_vm_data_hash, ka, hnode, vm_id) {
struct V_187 * V_323 = F_5 ( V_183 , struct V_187 , V_49 ) ;
struct V_182 * V_324 = & V_323 -> V_49 ;
if ( V_324 -> V_189 == V_184 )
goto V_319;
}
}
V_188 -> V_189 = V_184 ;
F_134 ( V_325 , & V_188 -> V_315 , V_188 -> V_189 ) ;
F_94 ( & V_186 , V_181 ) ;
return 0 ;
V_318:
F_130 ( V_187 ) ;
return V_108 ;
}
static inline int
F_135 ( struct V_8 * V_9 , int V_149 , bool V_150 )
{
int V_75 = 0 ;
unsigned long V_181 ;
struct V_326 * V_327 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_136 ( V_9 -> V_187 ) )
return 0 ;
F_91 ( & V_10 -> V_328 , V_181 ) ;
if ( F_137 ( & V_10 -> V_329 ) )
goto V_330;
F_138 (ir, &svm->ir_list, node) {
V_75 = F_139 ( V_149 , V_150 , V_327 -> V_11 ) ;
if ( V_75 )
break;
}
V_330:
F_94 ( & V_10 -> V_328 , V_181 ) ;
return V_75 ;
}
static void F_140 ( struct V_8 * V_9 , int V_149 )
{
T_1 V_15 ;
int V_331 = F_141 ( V_149 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_118 ( V_9 ) )
return;
if ( F_76 ( V_331 >= V_234 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_76 ( V_15 & V_17 ) ;
V_15 &= ~ V_332 ;
V_15 |= ( V_331 & V_332 ) ;
V_15 &= ~ V_17 ;
if ( V_10 -> V_333 )
V_15 |= V_17 ;
F_129 ( * ( V_10 -> V_16 ) , V_15 ) ;
F_135 ( V_9 , V_331 ,
V_10 -> V_333 ) ;
}
static void F_142 ( struct V_8 * V_9 )
{
T_1 V_15 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_118 ( V_9 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
if ( V_15 & V_17 )
F_135 ( V_9 , - 1 , 0 ) ;
V_15 &= ~ V_17 ;
F_129 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_143 ( struct V_8 * V_9 , bool V_334 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_333 = V_334 ;
if ( V_334 )
F_140 ( V_9 , V_9 -> V_149 ) ;
else
F_142 ( V_9 ) ;
}
static void F_144 ( struct V_8 * V_9 , bool V_335 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_336 ;
T_2 V_337 = 1 ;
if ( ! V_335 ) {
V_10 -> V_9 . V_49 . V_338 = V_309 |
V_339 ;
if ( F_145 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_49 . V_338 |= V_340 ;
}
F_117 ( V_10 ) ;
F_146 ( V_9 , & V_337 , & V_336 , & V_336 , & V_336 , true ) ;
F_147 ( V_9 , V_341 , V_337 ) ;
if ( F_118 ( V_9 ) && ! V_335 )
F_6 ( V_10 , V_309 ) ;
}
static int F_148 ( struct V_7 * V_10 )
{
int V_75 ;
if ( ! F_118 ( & V_10 -> V_9 ) )
return 0 ;
V_75 = F_127 ( & V_10 -> V_9 ) ;
if ( V_75 )
return V_75 ;
F_149 ( & V_10 -> V_329 ) ;
F_150 ( & V_10 -> V_328 ) ;
return V_75 ;
}
static struct V_8 * F_151 ( struct V_187 * V_187 , unsigned int V_311 )
{
struct V_7 * V_10 ;
struct V_192 * V_192 ;
struct V_192 * V_342 ;
struct V_192 * V_343 ;
struct V_192 * V_344 ;
int V_108 ;
V_10 = F_152 ( V_345 , V_151 ) ;
if ( ! V_10 ) {
V_108 = - V_152 ;
goto V_330;
}
V_108 = F_153 ( & V_10 -> V_9 , V_187 , V_311 ) ;
if ( V_108 )
goto V_346;
V_108 = - V_152 ;
V_192 = F_73 ( V_151 ) ;
if ( ! V_192 )
goto V_347;
V_342 = F_97 ( V_151 , V_163 ) ;
if ( ! V_342 )
goto V_348;
V_344 = F_97 ( V_151 , V_163 ) ;
if ( ! V_344 )
goto V_349;
V_343 = F_73 ( V_151 ) ;
if ( ! V_343 )
goto V_350;
V_108 = F_148 ( V_10 ) ;
if ( V_108 )
goto V_351;
V_10 -> V_333 = true ;
V_10 -> V_24 . V_25 = F_98 ( V_343 ) ;
V_10 -> V_156 = F_98 ( V_342 ) ;
F_80 ( V_10 -> V_156 ) ;
V_10 -> V_24 . V_156 = F_98 ( V_344 ) ;
F_80 ( V_10 -> V_24 . V_156 ) ;
V_10 -> V_1 = F_98 ( V_192 ) ;
F_133 ( V_10 -> V_1 ) ;
V_10 -> V_352 = F_115 ( F_64 ( V_192 ) << V_143 ) ;
V_10 -> V_134 = 0 ;
F_117 ( V_10 ) ;
F_50 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_351:
F_69 ( V_343 ) ;
V_350:
F_107 ( V_344 , V_163 ) ;
V_349:
F_107 ( V_342 , V_163 ) ;
V_348:
F_69 ( V_192 ) ;
V_347:
F_154 ( & V_10 -> V_9 ) ;
V_346:
F_155 ( V_345 , V_10 ) ;
V_330:
return F_156 ( V_108 ) ;
}
static void F_157 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_69 ( F_109 ( F_158 ( V_10 -> V_352 ) >> V_143 ) ) ;
F_107 ( F_128 ( V_10 -> V_156 ) , V_163 ) ;
F_69 ( F_128 ( V_10 -> V_24 . V_25 ) ) ;
F_107 ( F_128 ( V_10 -> V_24 . V_156 ) , V_163 ) ;
F_154 ( V_9 ) ;
F_155 ( V_345 , V_10 ) ;
}
static void F_159 ( struct V_8 * V_9 , int V_149 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_54 ;
if ( F_160 ( V_149 != V_9 -> V_149 ) ) {
V_10 -> V_134 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_30
F_59 ( V_353 , F_4 ( V_9 ) -> V_354 . V_355 ) ;
#endif
F_161 ( V_280 , V_10 -> V_354 . V_280 ) ;
F_161 ( V_281 , V_10 -> V_354 . V_281 ) ;
V_10 -> V_354 . V_356 = F_162 () ;
for ( V_54 = 0 ; V_54 < V_357 ; V_54 ++ )
F_59 ( V_358 [ V_54 ] , V_10 -> V_359 [ V_54 ] ) ;
if ( F_37 ( V_122 ) ) {
T_1 V_360 = V_9 -> V_49 . V_361 ;
if ( V_360 != F_163 ( V_144 ) ) {
F_65 ( V_144 , V_360 ) ;
F_54 ( V_123 , V_360 ) ;
}
}
if ( F_37 ( V_362 ) )
F_54 ( V_363 , V_10 -> V_364 ) ;
F_140 ( V_9 , V_149 ) ;
}
static void F_164 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_54 ;
F_142 ( V_9 ) ;
++ V_9 -> V_365 . V_366 ;
F_165 ( V_10 -> V_354 . V_356 ) ;
#ifdef F_30
F_166 ( V_280 , V_10 -> V_354 . V_280 ) ;
F_54 ( V_367 , V_368 -> V_369 . V_370 ) ;
F_167 ( V_10 -> V_354 . V_281 ) ;
#else
#ifdef F_168
F_166 ( V_281 , V_10 -> V_354 . V_281 ) ;
#endif
#endif
for ( V_54 = 0 ; V_54 < V_357 ; V_54 ++ )
F_54 ( V_358 [ V_54 ] , V_10 -> V_359 [ V_54 ] ) ;
}
static void F_169 ( struct V_8 * V_9 )
{
F_143 ( V_9 , false ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
F_143 ( V_9 , true ) ;
}
static unsigned long F_171 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
unsigned long V_178 = V_10 -> V_1 -> V_68 . V_178 ;
if ( V_10 -> V_173 ) {
if ( ! ( V_10 -> V_176 & V_177 ) )
V_178 &= ~ V_177 ;
if ( ! ( V_10 -> V_176 & V_179 ) )
V_178 &= ~ V_179 ;
}
return V_178 ;
}
static void F_172 ( struct V_8 * V_9 , unsigned long V_178 )
{
if ( F_4 ( V_9 ) -> V_173 )
V_178 |= ( V_177 | V_179 ) ;
F_4 ( V_9 ) -> V_1 -> V_68 . V_178 = V_178 ;
}
static void F_173 ( struct V_8 * V_9 , enum V_371 V_372 )
{
switch ( V_372 ) {
case V_373 :
F_77 ( ! V_65 ) ;
F_174 ( V_9 , V_9 -> V_49 . V_374 , F_175 ( V_9 ) ) ;
break;
default:
F_82 () ;
}
}
static void F_176 ( struct V_7 * V_10 )
{
F_19 ( V_10 , V_375 ) ;
}
static void F_177 ( struct V_7 * V_10 )
{
F_20 ( V_10 , V_375 ) ;
}
static struct V_215 * F_178 ( struct V_8 * V_9 , int V_216 )
{
struct V_236 * V_68 = & F_4 ( V_9 ) -> V_1 -> V_68 ;
switch ( V_216 ) {
case V_376 : return & V_68 -> V_99 ;
case V_377 : return & V_68 -> V_279 ;
case V_378 : return & V_68 -> V_277 ;
case V_379 : return & V_68 -> V_280 ;
case V_380 : return & V_68 -> V_281 ;
case V_381 : return & V_68 -> V_278 ;
case V_382 : return & V_68 -> V_288 ;
case V_383 : return & V_68 -> V_286 ;
}
F_82 () ;
return NULL ;
}
static T_1 F_179 ( struct V_8 * V_9 , int V_216 )
{
struct V_215 * V_384 = F_178 ( V_9 , V_216 ) ;
return V_384 -> V_100 ;
}
static void F_180 ( struct V_8 * V_9 ,
struct V_385 * V_386 , int V_216 )
{
struct V_215 * V_384 = F_178 ( V_9 , V_216 ) ;
V_386 -> V_100 = V_384 -> V_100 ;
V_386 -> V_222 = V_384 -> V_222 ;
V_386 -> V_217 = V_384 -> V_217 ;
V_386 -> type = V_384 -> V_218 & V_387 ;
V_386 -> V_384 = ( V_384 -> V_218 >> V_388 ) & 1 ;
V_386 -> V_389 = ( V_384 -> V_218 >> V_390 ) & 3 ;
V_386 -> V_391 = ( V_384 -> V_218 >> V_392 ) & 1 ;
V_386 -> V_393 = ( V_384 -> V_218 >> V_394 ) & 1 ;
V_386 -> V_395 = ( V_384 -> V_218 >> V_396 ) & 1 ;
V_386 -> V_397 = ( V_384 -> V_218 >> V_398 ) & 1 ;
V_386 -> V_22 = V_384 -> V_222 > 0xfffff ;
V_386 -> V_399 = ! V_386 -> V_391 ;
switch ( V_216 ) {
case V_382 :
V_386 -> type |= 0x2 ;
break;
case V_377 :
case V_378 :
case V_379 :
case V_380 :
if ( ! V_386 -> V_399 )
V_386 -> type |= 0x1 ;
break;
case V_381 :
if ( V_386 -> V_399 )
V_386 -> V_397 = 0 ;
V_386 -> V_389 = F_4 ( V_9 ) -> V_1 -> V_68 . V_400 ;
break;
}
}
static int F_181 ( struct V_8 * V_9 )
{
struct V_236 * V_68 = & F_4 ( V_9 ) -> V_1 -> V_68 ;
return V_68 -> V_400 ;
}
static void F_182 ( struct V_8 * V_9 , struct V_401 * V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_402 -> V_403 = V_10 -> V_1 -> V_68 . V_285 . V_222 ;
V_402 -> V_404 = V_10 -> V_1 -> V_68 . V_285 . V_100 ;
}
static void F_183 ( struct V_8 * V_9 , struct V_401 * V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_285 . V_222 = V_402 -> V_403 ;
V_10 -> V_1 -> V_68 . V_285 . V_100 = V_402 -> V_404 ;
F_3 ( V_10 -> V_1 , V_405 ) ;
}
static void F_184 ( struct V_8 * V_9 , struct V_401 * V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_402 -> V_403 = V_10 -> V_1 -> V_68 . V_284 . V_222 ;
V_402 -> V_404 = V_10 -> V_1 -> V_68 . V_284 . V_100 ;
}
static void F_185 ( struct V_8 * V_9 , struct V_401 * V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_284 . V_222 = V_402 -> V_403 ;
V_10 -> V_1 -> V_68 . V_284 . V_100 = V_402 -> V_404 ;
F_3 ( V_10 -> V_1 , V_405 ) ;
}
static void F_186 ( struct V_8 * V_9 )
{
}
static void F_187 ( struct V_8 * V_9 )
{
}
static void F_188 ( struct V_8 * V_9 )
{
}
static void F_189 ( struct V_7 * V_10 )
{
T_9 V_406 = V_10 -> V_9 . V_49 . V_407 ;
T_1 * V_408 = & V_10 -> V_1 -> V_68 . V_407 ;
* V_408 = ( * V_408 & ~ V_409 )
| ( V_406 & V_409 ) ;
F_3 ( V_10 -> V_1 , V_70 ) ;
if ( V_406 == * V_408 ) {
F_13 ( V_10 , V_237 ) ;
F_13 ( V_10 , V_240 ) ;
} else {
F_12 ( V_10 , V_237 ) ;
F_12 ( V_10 , V_240 ) ;
}
}
static void F_122 ( struct V_8 * V_9 , unsigned long V_407 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_30
if ( V_9 -> V_49 . V_64 & V_67 ) {
if ( ! F_190 ( V_9 ) && ( V_407 & V_410 ) ) {
V_9 -> V_49 . V_64 |= V_66 ;
V_10 -> V_1 -> V_68 . V_64 |= V_66 | V_67 ;
}
if ( F_190 ( V_9 ) && ! ( V_407 & V_410 ) ) {
V_9 -> V_49 . V_64 &= ~ V_66 ;
V_10 -> V_1 -> V_68 . V_64 &= ~ ( V_66 | V_67 ) ;
}
}
#endif
V_9 -> V_49 . V_407 = V_407 ;
if ( ! V_65 )
V_407 |= V_410 | V_411 ;
if ( F_191 ( V_9 -> V_187 , V_412 ) )
V_407 &= ~ ( V_294 | V_293 ) ;
V_10 -> V_1 -> V_68 . V_407 = V_407 ;
F_3 ( V_10 -> V_1 , V_70 ) ;
F_189 ( V_10 ) ;
}
static int F_192 ( struct V_8 * V_9 , unsigned long V_296 )
{
unsigned long V_413 = F_193 () & V_414 ;
unsigned long V_415 = F_4 ( V_9 ) -> V_1 -> V_68 . V_296 ;
if ( V_296 & V_416 )
return 1 ;
if ( V_65 && ( ( V_415 ^ V_296 ) & V_417 ) )
F_194 ( V_9 ) ;
V_9 -> V_49 . V_296 = V_296 ;
if ( ! V_65 )
V_296 |= V_297 ;
V_296 |= V_413 ;
F_4 ( V_9 ) -> V_1 -> V_68 . V_296 = V_296 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_70 ) ;
return 0 ;
}
static void F_195 ( struct V_8 * V_9 ,
struct V_385 * V_386 , int V_216 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_215 * V_384 = F_178 ( V_9 , V_216 ) ;
V_384 -> V_100 = V_386 -> V_100 ;
V_384 -> V_222 = V_386 -> V_222 ;
V_384 -> V_217 = V_386 -> V_217 ;
V_384 -> V_218 = ( V_386 -> type & V_387 ) ;
V_384 -> V_218 |= ( V_386 -> V_384 & 1 ) << V_388 ;
V_384 -> V_218 |= ( V_386 -> V_389 & 3 ) << V_390 ;
V_384 -> V_218 |= ( ( V_386 -> V_391 & 1 ) && ! V_386 -> V_399 ) << V_392 ;
V_384 -> V_218 |= ( V_386 -> V_393 & 1 ) << V_394 ;
V_384 -> V_218 |= ( V_386 -> V_395 & 1 ) << V_396 ;
V_384 -> V_218 |= ( V_386 -> V_397 & 1 ) << V_398 ;
V_384 -> V_218 |= ( V_386 -> V_22 & 1 ) << V_418 ;
if ( V_216 == V_381 )
V_10 -> V_1 -> V_68 . V_400 = ( V_386 -> V_389 & 3 ) ;
F_3 ( V_10 -> V_1 , V_419 ) ;
}
static void F_196 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_95 ) ;
if ( V_9 -> V_174 & V_420 ) {
if ( V_9 -> V_174 & V_421 )
F_17 ( V_10 , V_95 ) ;
} else
V_9 -> V_174 = 0 ;
}
static void F_197 ( struct V_7 * V_10 , struct V_125 * V_126 )
{
if ( V_126 -> V_137 > V_126 -> V_135 ) {
++ V_126 -> V_134 ;
V_126 -> V_137 = 1 ;
V_10 -> V_1 -> V_2 . V_422 = V_423 ;
}
V_10 -> V_134 = V_126 -> V_134 ;
V_10 -> V_1 -> V_2 . V_61 = V_126 -> V_137 ++ ;
F_3 ( V_10 -> V_1 , V_424 ) ;
}
static T_1 F_198 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_68 . V_290 ;
}
static void F_199 ( struct V_8 * V_9 , unsigned long V_425 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_290 = V_425 ;
F_3 ( V_10 -> V_1 , V_426 ) ;
}
static void F_200 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_201 ( V_9 -> V_49 . V_397 [ 0 ] , 0 ) ;
F_201 ( V_9 -> V_49 . V_397 [ 1 ] , 1 ) ;
F_201 ( V_9 -> V_49 . V_397 [ 2 ] , 2 ) ;
F_201 ( V_9 -> V_49 . V_397 [ 3 ] , 3 ) ;
V_9 -> V_49 . V_290 = F_198 ( V_9 ) ;
V_9 -> V_49 . V_427 = V_10 -> V_1 -> V_68 . V_427 ;
V_9 -> V_49 . V_428 &= ~ V_429 ;
F_15 ( V_10 ) ;
}
static void F_202 ( struct V_8 * V_9 , unsigned long V_425 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_427 = V_425 ;
F_3 ( V_10 -> V_1 , V_426 ) ;
}
static int F_203 ( struct V_7 * V_10 )
{
T_1 V_430 = V_10 -> V_1 -> V_2 . V_431 ;
T_1 V_94 = V_10 -> V_1 -> V_2 . V_432 ;
return F_204 ( & V_10 -> V_9 , V_94 , V_430 ,
V_10 -> V_1 -> V_2 . V_433 ,
V_10 -> V_1 -> V_2 . V_434 , ! V_65 ) ;
}
static int F_205 ( struct V_7 * V_10 )
{
struct V_435 * V_435 = V_10 -> V_9 . V_436 ;
if ( ! ( V_10 -> V_9 . V_174 &
( V_175 | V_437 ) ) &&
! V_10 -> V_173 ) {
F_206 ( & V_10 -> V_9 , V_248 ) ;
return 1 ;
}
if ( V_10 -> V_173 ) {
F_86 ( V_10 ) ;
}
if ( V_10 -> V_9 . V_174 &
( V_175 | V_437 ) ) {
V_435 -> V_438 = V_439 ;
V_435 -> V_440 . V_49 . V_441 =
V_10 -> V_1 -> V_68 . V_99 . V_100 + V_10 -> V_1 -> V_68 . V_96 ;
V_435 -> V_440 . V_49 . V_90 = V_248 ;
return 0 ;
}
return 1 ;
}
static int F_207 ( struct V_7 * V_10 )
{
struct V_435 * V_435 = V_10 -> V_9 . V_436 ;
V_435 -> V_438 = V_439 ;
V_435 -> V_440 . V_49 . V_441 = V_10 -> V_1 -> V_68 . V_99 . V_100 + V_10 -> V_1 -> V_68 . V_96 ;
V_435 -> V_440 . V_49 . V_90 = V_95 ;
return 0 ;
}
static int F_208 ( struct V_7 * V_10 )
{
int V_442 ;
V_442 = F_38 ( & V_10 -> V_9 , V_443 ) ;
if ( V_442 != V_84 )
F_206 ( & V_10 -> V_9 , V_245 ) ;
return 1 ;
}
static int F_209 ( struct V_7 * V_10 )
{
F_210 ( & V_10 -> V_9 , V_247 , 0 ) ;
return 1 ;
}
static bool F_211 ( void )
{
int V_108 , V_54 ;
T_1 V_425 ;
if ( ! V_112 )
return false ;
V_425 = F_46 ( V_444 , & V_108 ) ;
if ( V_108 )
return false ;
V_425 &= ~ ( 1ULL << 62 ) ;
if ( V_425 != 0xb600000000010015ULL )
return false ;
for ( V_54 = 0 ; V_54 < 6 ; ++ V_54 )
F_49 ( F_212 ( V_54 ) , 0 , 0 ) ;
V_425 = F_46 ( V_445 , & V_108 ) ;
if ( ! V_108 ) {
T_2 V_106 , V_107 ;
V_425 &= ~ ( 1ULL << 2 ) ;
V_106 = F_47 ( V_425 ) ;
V_107 = F_48 ( V_425 ) ;
F_49 ( V_445 , V_106 , V_107 ) ;
}
F_213 () ;
return true ;
}
static void F_214 ( struct V_7 * V_10 )
{
if ( F_211 () ) {
F_60 ( L_13 ) ;
F_215 ( V_446 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_216 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_217 ( struct V_7 * V_10 )
{
struct V_435 * V_435 = V_10 -> V_9 . V_436 ;
F_133 ( V_10 -> V_1 ) ;
F_117 ( V_10 ) ;
V_435 -> V_438 = V_447 ;
return 0 ;
}
static int F_218 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_2 V_448 = V_10 -> V_1 -> V_2 . V_432 ;
int V_403 , V_449 , string , V_75 ;
unsigned V_450 ;
++ V_10 -> V_9 . V_365 . V_451 ;
string = ( V_448 & V_452 ) != 0 ;
V_449 = ( V_448 & V_453 ) != 0 ;
if ( string )
return F_38 ( V_9 , 0 ) == V_84 ;
V_450 = V_448 >> 16 ;
V_403 = ( V_448 & V_454 ) >> V_455 ;
V_10 -> V_81 = V_10 -> V_1 -> V_2 . V_431 ;
V_75 = F_219 ( & V_10 -> V_9 ) ;
if ( V_449 )
return F_220 ( V_9 , V_403 , V_450 ) && V_75 ;
else
return F_221 ( V_9 , V_403 , V_450 ) && V_75 ;
}
static int F_222 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_223 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_365 . V_456 ;
return 1 ;
}
static int F_224 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_225 ( struct V_7 * V_10 )
{
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 1 ;
return F_226 ( & V_10 -> V_9 ) ;
}
static int F_227 ( struct V_7 * V_10 )
{
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
return F_228 ( & V_10 -> V_9 ) ;
}
static unsigned long F_229 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_24 . V_457 ;
}
static T_1 F_230 ( struct V_8 * V_9 , int V_154 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_301 = V_10 -> V_24 . V_457 ;
T_1 V_458 ;
int V_75 ;
V_75 = F_231 ( V_9 , F_232 ( F_158 ( V_301 ) ) , & V_458 ,
F_233 ( V_301 ) + V_154 * 8 , 8 ) ;
if ( V_75 )
return 0 ;
return V_458 ;
}
static void F_234 ( struct V_8 * V_9 ,
unsigned long V_459 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_457 = F_115 ( V_459 ) ;
F_3 ( V_10 -> V_1 , V_460 ) ;
F_194 ( V_9 ) ;
}
static void F_235 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_463 != V_464 ) {
V_10 -> V_1 -> V_2 . V_463 = V_464 ;
V_10 -> V_1 -> V_2 . V_465 = 0 ;
V_10 -> V_1 -> V_2 . V_432 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_431 = V_462 -> V_404 ;
}
V_10 -> V_1 -> V_2 . V_432 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_432 |= V_462 -> V_94 ;
if ( V_10 -> V_1 -> V_2 . V_432 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_432 &= ~ 1 ;
F_236 ( V_10 ) ;
}
static void F_237 ( struct V_8 * V_9 )
{
F_76 ( F_238 ( V_9 ) ) ;
F_239 ( V_9 ) ;
V_9 -> V_49 . V_466 . V_467 = F_234 ;
V_9 -> V_49 . V_466 . V_468 = F_229 ;
V_9 -> V_49 . V_466 . V_469 = F_230 ;
V_9 -> V_49 . V_466 . V_470 = F_235 ;
V_9 -> V_49 . V_466 . V_471 = F_29 ( V_9 ) ;
F_240 ( V_9 , & V_9 -> V_49 . V_466 ) ;
V_9 -> V_49 . V_374 = & V_9 -> V_49 . V_472 ;
}
static void F_241 ( struct V_8 * V_9 )
{
V_9 -> V_49 . V_374 = & V_9 -> V_49 . V_466 ;
}
static int F_242 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_49 . V_64 & V_69 ) ||
! F_190 ( & V_10 -> V_9 ) ) {
F_206 ( & V_10 -> V_9 , V_245 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_68 . V_400 ) {
F_243 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_43 ( struct V_7 * V_10 , unsigned V_89 ,
bool V_91 , T_2 V_94 )
{
int V_473 ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return 0 ;
V_473 = F_244 ( V_10 ) ;
if ( V_473 != V_474 )
return 0 ;
V_10 -> V_1 -> V_2 . V_463 = V_475 + V_89 ;
V_10 -> V_1 -> V_2 . V_465 = 0 ;
V_10 -> V_1 -> V_2 . V_432 = V_94 ;
if ( V_10 -> V_9 . V_49 . V_90 . V_476 )
V_10 -> V_1 -> V_2 . V_431 = V_10 -> V_9 . V_49 . V_477 . V_478 ;
else
V_10 -> V_1 -> V_2 . V_431 = V_10 -> V_9 . V_49 . V_479 ;
V_10 -> V_24 . V_480 = true ;
return V_473 ;
}
static inline bool F_245 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_49 . V_50 & V_481 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_49 . V_50 & V_482 ) )
return false ;
if ( V_10 -> V_24 . V_480 )
return false ;
V_10 -> V_1 -> V_2 . V_463 = V_483 ;
V_10 -> V_1 -> V_2 . V_432 = 0 ;
V_10 -> V_1 -> V_2 . V_431 = 0 ;
if ( V_10 -> V_24 . V_29 & 1ULL ) {
V_10 -> V_24 . V_480 = true ;
F_246 ( V_10 -> V_1 -> V_68 . V_96 ) ;
return false ;
}
return true ;
}
static inline bool F_247 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_250 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_463 = V_484 ;
V_10 -> V_24 . V_480 = true ;
return false ;
}
static void * F_248 ( struct V_7 * V_10 , T_1 V_485 , struct V_192 * * V_486 )
{
struct V_192 * V_192 ;
F_249 () ;
V_192 = F_250 ( & V_10 -> V_9 , V_485 >> V_143 ) ;
if ( F_251 ( V_192 ) )
goto error;
* V_486 = V_192 ;
return F_252 ( V_192 ) ;
error:
F_243 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_253 ( struct V_192 * V_192 )
{
F_254 ( V_192 ) ;
F_255 ( V_192 ) ;
}
static int F_256 ( struct V_7 * V_10 )
{
unsigned V_450 , V_403 , V_487 ;
T_10 V_109 , V_80 ;
T_4 V_488 ;
T_1 V_485 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_259 ) ) )
return V_489 ;
V_450 = V_10 -> V_1 -> V_2 . V_432 >> 16 ;
V_403 = ( V_10 -> V_1 -> V_2 . V_432 & V_454 ) >>
V_455 ;
V_485 = V_10 -> V_24 . V_490 + ( V_450 / 8 ) ;
V_488 = V_450 % 8 ;
V_487 = ( V_488 + V_403 > 8 ) ? 2 : 1 ;
V_80 = ( 0xf >> ( 4 - V_403 ) ) << V_488 ;
V_109 = 0 ;
if ( F_257 ( & V_10 -> V_9 , V_485 , & V_109 , V_487 ) )
return V_474 ;
return ( V_109 & V_80 ) ? V_474 : V_489 ;
}
static int F_258 ( struct V_7 * V_10 )
{
T_2 V_53 , V_52 , V_425 ;
int V_158 , V_80 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_260 ) ) )
return V_489 ;
V_52 = V_10 -> V_9 . V_49 . V_291 [ V_491 ] ;
V_53 = F_25 ( V_52 ) ;
V_158 = V_10 -> V_1 -> V_2 . V_432 & 1 ;
V_80 = 1 << ( ( 2 * ( V_52 & 0xf ) ) + V_158 ) ;
if ( V_53 == V_59 )
return V_474 ;
V_53 *= 4 ;
if ( F_257 ( & V_10 -> V_9 , V_10 -> V_24 . V_492 + V_53 , & V_425 , 4 ) )
return V_474 ;
return ( V_425 & V_80 ) ? V_474 : V_489 ;
}
static int F_259 ( struct V_7 * V_10 )
{
unsigned long V_290 ;
if ( ! V_10 -> V_173 )
return V_474 ;
if ( F_260 ( & V_10 -> V_9 , 6 , & V_290 ) )
return V_474 ;
if ( ! ( V_290 & V_493 ) )
return V_474 ;
if ( V_10 -> V_176 & V_177 ) {
F_86 ( V_10 ) ;
return V_474 ;
}
return V_489 ;
}
static int F_261 ( struct V_7 * V_10 )
{
T_2 V_463 = V_10 -> V_1 -> V_2 . V_463 ;
switch ( V_463 ) {
case V_483 :
case V_484 :
case V_475 + V_246 :
return V_489 ;
case V_464 :
if ( V_65 )
return V_489 ;
break;
case V_475 + V_244 :
if ( ! V_65 && V_10 -> V_9 . V_49 . V_477 . V_494 == 0 )
return V_489 ;
break;
default:
break;
}
return V_495 ;
}
static int F_244 ( struct V_7 * V_10 )
{
T_2 V_463 = V_10 -> V_1 -> V_2 . V_463 ;
int V_473 = V_489 ;
switch ( V_463 ) {
case V_496 :
V_473 = F_258 ( V_10 ) ;
break;
case V_497 :
V_473 = F_256 ( V_10 ) ;
break;
case V_498 ... V_499 : {
T_2 V_6 = 1U << ( V_463 - V_498 ) ;
if ( V_10 -> V_24 . V_26 & V_6 )
V_473 = V_474 ;
break;
}
case V_500 ... V_501 : {
T_2 V_6 = 1U << ( V_463 - V_500 ) ;
if ( V_10 -> V_24 . V_27 & V_6 )
V_473 = V_474 ;
break;
}
case V_475 ... V_475 + 0x1f : {
T_2 V_502 = 1 << ( V_463 - V_475 ) ;
if ( V_10 -> V_24 . V_28 & V_502 ) {
if ( V_463 == V_475 + V_248 )
V_473 = F_259 ( V_10 ) ;
else
V_473 = V_474 ;
}
else if ( ( V_463 == V_475 + V_244 ) &&
V_10 -> V_9 . V_49 . V_90 . V_476 != 0 )
V_473 = V_474 ;
break;
}
case V_503 : {
V_473 = V_474 ;
break;
}
default: {
T_1 V_504 = 1ULL << ( V_463 - V_483 ) ;
if ( V_10 -> V_24 . V_29 & V_504 )
V_473 = V_474 ;
}
}
return V_473 ;
}
static int F_262 ( struct V_7 * V_10 )
{
int V_473 ;
V_473 = F_244 ( V_10 ) ;
if ( V_473 == V_474 )
F_236 ( V_10 ) ;
return V_473 ;
}
static inline void F_263 ( struct V_1 * V_505 , struct V_1 * V_506 )
{
struct V_18 * V_507 = & V_505 -> V_2 ;
struct V_18 * V_508 = & V_506 -> V_2 ;
V_507 -> V_26 = V_508 -> V_26 ;
V_507 -> V_27 = V_508 -> V_27 ;
V_507 -> V_28 = V_508 -> V_28 ;
V_507 -> V_29 = V_508 -> V_29 ;
V_507 -> V_274 = V_508 -> V_274 ;
V_507 -> V_275 = V_508 -> V_275 ;
V_507 -> V_224 = V_508 -> V_224 ;
V_507 -> V_61 = V_508 -> V_61 ;
V_507 -> V_422 = V_508 -> V_422 ;
V_507 -> V_46 = V_508 -> V_46 ;
V_507 -> V_509 = V_508 -> V_509 ;
V_507 -> V_76 = V_508 -> V_76 ;
V_507 -> V_463 = V_508 -> V_463 ;
V_507 -> V_465 = V_508 -> V_465 ;
V_507 -> V_432 = V_508 -> V_432 ;
V_507 -> V_431 = V_508 -> V_431 ;
V_507 -> V_510 = V_508 -> V_510 ;
V_507 -> V_511 = V_508 -> V_511 ;
V_507 -> V_298 = V_508 -> V_298 ;
V_507 -> V_102 = V_508 -> V_102 ;
V_507 -> V_105 = V_508 -> V_105 ;
V_507 -> V_457 = V_508 -> V_457 ;
V_507 -> V_167 = V_508 -> V_167 ;
}
static int F_236 ( struct V_7 * V_10 )
{
struct V_1 * V_512 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_192 * V_192 ;
F_264 ( V_1 -> V_2 . V_463 ,
V_1 -> V_2 . V_432 ,
V_1 -> V_2 . V_431 ,
V_1 -> V_2 . V_510 ,
V_1 -> V_2 . V_511 ,
V_513 ) ;
V_512 = F_248 ( V_10 , V_10 -> V_24 . V_1 , & V_192 ) ;
if ( ! V_512 )
return 1 ;
F_265 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_1 = 0 ;
F_23 ( V_10 ) ;
V_512 -> V_68 . V_277 = V_1 -> V_68 . V_277 ;
V_512 -> V_68 . V_99 = V_1 -> V_68 . V_99 ;
V_512 -> V_68 . V_278 = V_1 -> V_68 . V_278 ;
V_512 -> V_68 . V_279 = V_1 -> V_68 . V_279 ;
V_512 -> V_68 . V_284 = V_1 -> V_68 . V_284 ;
V_512 -> V_68 . V_285 = V_1 -> V_68 . V_285 ;
V_512 -> V_68 . V_64 = V_10 -> V_9 . V_49 . V_64 ;
V_512 -> V_68 . V_407 = F_266 ( & V_10 -> V_9 ) ;
V_512 -> V_68 . V_301 = F_175 ( & V_10 -> V_9 ) ;
V_512 -> V_68 . V_479 = V_1 -> V_68 . V_479 ;
V_512 -> V_68 . V_296 = V_10 -> V_9 . V_49 . V_296 ;
V_512 -> V_68 . V_178 = F_267 ( & V_10 -> V_9 ) ;
V_512 -> V_68 . V_96 = V_1 -> V_68 . V_96 ;
V_512 -> V_68 . V_514 = V_1 -> V_68 . V_514 ;
V_512 -> V_68 . V_515 = V_1 -> V_68 . V_515 ;
V_512 -> V_68 . V_427 = V_1 -> V_68 . V_427 ;
V_512 -> V_68 . V_290 = V_1 -> V_68 . V_290 ;
V_512 -> V_68 . V_400 = V_1 -> V_68 . V_400 ;
V_512 -> V_2 . V_46 = V_1 -> V_2 . V_46 ;
V_512 -> V_2 . V_509 = V_1 -> V_2 . V_509 ;
V_512 -> V_2 . V_76 = V_1 -> V_2 . V_76 ;
V_512 -> V_2 . V_463 = V_1 -> V_2 . V_463 ;
V_512 -> V_2 . V_465 = V_1 -> V_2 . V_465 ;
V_512 -> V_2 . V_432 = V_1 -> V_2 . V_432 ;
V_512 -> V_2 . V_431 = V_1 -> V_2 . V_431 ;
V_512 -> V_2 . V_510 = V_1 -> V_2 . V_510 ;
V_512 -> V_2 . V_511 = V_1 -> V_2 . V_511 ;
if ( V_10 -> V_516 )
V_512 -> V_2 . V_81 = V_1 -> V_2 . V_81 ;
if ( V_1 -> V_2 . V_102 & V_73 ) {
struct V_18 * V_517 = & V_512 -> V_2 ;
V_517 -> V_510 = V_1 -> V_2 . V_102 ;
V_517 -> V_511 = V_1 -> V_2 . V_105 ;
}
V_512 -> V_2 . V_422 = 0 ;
V_512 -> V_2 . V_102 = 0 ;
V_512 -> V_2 . V_105 = 0 ;
if ( ! ( V_10 -> V_9 . V_49 . V_50 & V_481 ) )
V_512 -> V_2 . V_46 &= ~ V_276 ;
F_263 ( V_1 , V_25 ) ;
F_268 ( & V_10 -> V_9 ) ;
F_269 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_457 = 0 ;
V_10 -> V_1 -> V_68 . V_277 = V_25 -> V_68 . V_277 ;
V_10 -> V_1 -> V_68 . V_99 = V_25 -> V_68 . V_99 ;
V_10 -> V_1 -> V_68 . V_278 = V_25 -> V_68 . V_278 ;
V_10 -> V_1 -> V_68 . V_279 = V_25 -> V_68 . V_279 ;
V_10 -> V_1 -> V_68 . V_284 = V_25 -> V_68 . V_284 ;
V_10 -> V_1 -> V_68 . V_285 = V_25 -> V_68 . V_285 ;
F_121 ( & V_10 -> V_9 , V_25 -> V_68 . V_178 ) ;
F_31 ( & V_10 -> V_9 , V_25 -> V_68 . V_64 ) ;
F_122 ( & V_10 -> V_9 , V_25 -> V_68 . V_407 | V_518 ) ;
F_192 ( & V_10 -> V_9 , V_25 -> V_68 . V_296 ) ;
if ( V_65 ) {
V_10 -> V_1 -> V_68 . V_301 = V_25 -> V_68 . V_301 ;
V_10 -> V_9 . V_49 . V_301 = V_25 -> V_68 . V_301 ;
} else {
( void ) F_270 ( & V_10 -> V_9 , V_25 -> V_68 . V_301 ) ;
}
F_147 ( & V_10 -> V_9 , V_519 , V_25 -> V_68 . V_515 ) ;
F_147 ( & V_10 -> V_9 , V_520 , V_25 -> V_68 . V_514 ) ;
F_147 ( & V_10 -> V_9 , V_292 , V_25 -> V_68 . V_96 ) ;
V_10 -> V_1 -> V_68 . V_427 = 0 ;
V_10 -> V_1 -> V_68 . V_400 = 0 ;
V_10 -> V_1 -> V_2 . V_510 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_253 ( V_192 ) ;
F_241 ( & V_10 -> V_9 ) ;
F_123 ( & V_10 -> V_9 ) ;
F_271 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_272 ( struct V_7 * V_10 )
{
int V_54 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_260 ) ) )
return true ;
for ( V_54 = 0 ; V_54 < V_165 ; V_54 ++ ) {
T_2 V_425 , V_521 ;
T_1 V_53 ;
if ( V_166 [ V_54 ] == 0xffffffff )
break;
V_521 = V_166 [ V_54 ] ;
V_53 = V_10 -> V_24 . V_492 + ( V_521 * 4 ) ;
if ( F_257 ( & V_10 -> V_9 , V_53 , & V_425 , 4 ) )
return false ;
V_10 -> V_24 . V_156 [ V_521 ] = V_10 -> V_156 [ V_521 ] | V_425 ;
}
V_10 -> V_1 -> V_2 . V_275 = F_115 ( F_120 ( V_10 -> V_24 . V_156 ) ) ;
return true ;
}
static bool F_273 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_29 & ( 1ULL << V_263 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_61 == 0 )
return false ;
if ( V_1 -> V_2 . V_298 && ! V_65 )
return false ;
return true ;
}
static bool F_274 ( struct V_7 * V_10 )
{
struct V_1 * V_512 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_192 * V_192 ;
T_1 V_522 ;
V_522 = V_10 -> V_1 -> V_68 . V_515 ;
V_512 = F_248 ( V_10 , V_10 -> V_1 -> V_68 . V_515 , & V_192 ) ;
if ( ! V_512 )
return false ;
if ( ! F_273 ( V_512 ) ) {
V_512 -> V_2 . V_463 = V_503 ;
V_512 -> V_2 . V_465 = 0 ;
V_512 -> V_2 . V_432 = 0 ;
V_512 -> V_2 . V_431 = 0 ;
F_253 ( V_192 ) ;
return false ;
}
F_275 ( V_10 -> V_1 -> V_68 . V_96 , V_522 ,
V_512 -> V_68 . V_96 ,
V_512 -> V_2 . V_46 ,
V_512 -> V_2 . V_102 ,
V_512 -> V_2 . V_298 ) ;
F_276 ( V_512 -> V_2 . V_26 & 0xffff ,
V_512 -> V_2 . V_26 >> 16 ,
V_512 -> V_2 . V_28 ,
V_512 -> V_2 . V_29 ) ;
F_268 ( & V_10 -> V_9 ) ;
F_269 ( & V_10 -> V_9 ) ;
V_25 -> V_68 . V_277 = V_1 -> V_68 . V_277 ;
V_25 -> V_68 . V_99 = V_1 -> V_68 . V_99 ;
V_25 -> V_68 . V_278 = V_1 -> V_68 . V_278 ;
V_25 -> V_68 . V_279 = V_1 -> V_68 . V_279 ;
V_25 -> V_68 . V_284 = V_1 -> V_68 . V_284 ;
V_25 -> V_68 . V_285 = V_1 -> V_68 . V_285 ;
V_25 -> V_68 . V_64 = V_10 -> V_9 . V_49 . V_64 ;
V_25 -> V_68 . V_407 = F_266 ( & V_10 -> V_9 ) ;
V_25 -> V_68 . V_296 = V_10 -> V_9 . V_49 . V_296 ;
V_25 -> V_68 . V_178 = F_267 ( & V_10 -> V_9 ) ;
V_25 -> V_68 . V_96 = F_40 ( & V_10 -> V_9 ) ;
V_25 -> V_68 . V_514 = V_1 -> V_68 . V_514 ;
V_25 -> V_68 . V_515 = V_1 -> V_68 . V_515 ;
if ( V_65 )
V_25 -> V_68 . V_301 = V_1 -> V_68 . V_301 ;
else
V_25 -> V_68 . V_301 = F_175 ( & V_10 -> V_9 ) ;
F_263 ( V_25 , V_1 ) ;
if ( F_267 ( & V_10 -> V_9 ) & V_523 )
V_10 -> V_9 . V_49 . V_50 |= V_482 ;
else
V_10 -> V_9 . V_49 . V_50 &= ~ V_482 ;
if ( V_512 -> V_2 . V_298 ) {
F_277 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_457 = V_512 -> V_2 . V_457 ;
F_237 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_68 . V_277 = V_512 -> V_68 . V_277 ;
V_10 -> V_1 -> V_68 . V_99 = V_512 -> V_68 . V_99 ;
V_10 -> V_1 -> V_68 . V_278 = V_512 -> V_68 . V_278 ;
V_10 -> V_1 -> V_68 . V_279 = V_512 -> V_68 . V_279 ;
V_10 -> V_1 -> V_68 . V_284 = V_512 -> V_68 . V_284 ;
V_10 -> V_1 -> V_68 . V_285 = V_512 -> V_68 . V_285 ;
F_121 ( & V_10 -> V_9 , V_512 -> V_68 . V_178 ) ;
F_31 ( & V_10 -> V_9 , V_512 -> V_68 . V_64 ) ;
F_122 ( & V_10 -> V_9 , V_512 -> V_68 . V_407 ) ;
F_192 ( & V_10 -> V_9 , V_512 -> V_68 . V_296 ) ;
if ( V_65 ) {
V_10 -> V_1 -> V_68 . V_301 = V_512 -> V_68 . V_301 ;
V_10 -> V_9 . V_49 . V_301 = V_512 -> V_68 . V_301 ;
} else
( void ) F_270 ( & V_10 -> V_9 , V_512 -> V_68 . V_301 ) ;
F_123 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_68 . V_479 = V_10 -> V_9 . V_49 . V_479 = V_512 -> V_68 . V_479 ;
F_147 ( & V_10 -> V_9 , V_519 , V_512 -> V_68 . V_515 ) ;
F_147 ( & V_10 -> V_9 , V_520 , V_512 -> V_68 . V_514 ) ;
F_147 ( & V_10 -> V_9 , V_292 , V_512 -> V_68 . V_96 ) ;
V_10 -> V_1 -> V_68 . V_515 = V_512 -> V_68 . V_515 ;
V_10 -> V_1 -> V_68 . V_514 = V_512 -> V_68 . V_514 ;
V_10 -> V_1 -> V_68 . V_96 = V_512 -> V_68 . V_96 ;
V_10 -> V_1 -> V_68 . V_427 = V_512 -> V_68 . V_427 ;
V_10 -> V_1 -> V_68 . V_290 = V_512 -> V_68 . V_290 ;
V_10 -> V_1 -> V_68 . V_400 = V_512 -> V_68 . V_400 ;
V_10 -> V_24 . V_492 = V_512 -> V_2 . V_275 & ~ 0x0fffULL ;
V_10 -> V_24 . V_490 = V_512 -> V_2 . V_274 & ~ 0x0fffULL ;
V_10 -> V_24 . V_26 = V_512 -> V_2 . V_26 ;
V_10 -> V_24 . V_27 = V_512 -> V_2 . V_27 ;
V_10 -> V_24 . V_28 = V_512 -> V_2 . V_28 ;
V_10 -> V_24 . V_29 = V_512 -> V_2 . V_29 ;
F_194 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_46 = V_512 -> V_2 . V_46 | V_276 ;
if ( V_512 -> V_2 . V_46 & V_276 )
V_10 -> V_9 . V_49 . V_50 |= V_481 ;
else
V_10 -> V_9 . V_49 . V_50 &= ~ V_481 ;
if ( V_10 -> V_9 . V_49 . V_50 & V_481 ) {
F_13 ( V_10 , V_524 ) ;
F_13 ( V_10 , V_243 ) ;
}
F_20 ( V_10 , V_264 ) ;
V_10 -> V_1 -> V_2 . V_167 = V_512 -> V_2 . V_167 ;
V_10 -> V_1 -> V_2 . V_509 = V_512 -> V_2 . V_509 ;
V_10 -> V_1 -> V_2 . V_76 = V_512 -> V_2 . V_76 ;
V_10 -> V_1 -> V_2 . V_224 += V_512 -> V_2 . V_224 ;
V_10 -> V_1 -> V_2 . V_102 = V_512 -> V_2 . V_102 ;
V_10 -> V_1 -> V_2 . V_105 = V_512 -> V_2 . V_105 ;
F_253 ( V_192 ) ;
F_278 ( & V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
V_10 -> V_24 . V_1 = V_522 ;
F_22 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_279 ( struct V_1 * V_506 , struct V_1 * V_525 )
{
V_525 -> V_68 . V_280 = V_506 -> V_68 . V_280 ;
V_525 -> V_68 . V_281 = V_506 -> V_68 . V_281 ;
V_525 -> V_68 . V_288 = V_506 -> V_68 . V_288 ;
V_525 -> V_68 . V_286 = V_506 -> V_68 . V_286 ;
V_525 -> V_68 . V_526 = V_506 -> V_68 . V_526 ;
V_525 -> V_68 . V_527 = V_506 -> V_68 . V_527 ;
V_525 -> V_68 . V_528 = V_506 -> V_68 . V_528 ;
V_525 -> V_68 . V_529 = V_506 -> V_68 . V_529 ;
V_525 -> V_68 . V_530 = V_506 -> V_68 . V_530 ;
V_525 -> V_68 . V_531 = V_506 -> V_68 . V_531 ;
V_525 -> V_68 . V_532 = V_506 -> V_68 . V_532 ;
V_525 -> V_68 . V_533 = V_506 -> V_68 . V_533 ;
}
static int F_280 ( struct V_7 * V_10 )
{
struct V_1 * V_512 ;
struct V_192 * V_192 ;
int V_75 ;
if ( F_242 ( V_10 ) )
return 1 ;
V_512 = F_248 ( V_10 , V_10 -> V_1 -> V_68 . V_515 , & V_192 ) ;
if ( ! V_512 )
return 1 ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
V_75 = F_219 ( & V_10 -> V_9 ) ;
F_279 ( V_512 , V_10 -> V_1 ) ;
F_253 ( V_192 ) ;
return V_75 ;
}
static int F_281 ( struct V_7 * V_10 )
{
struct V_1 * V_512 ;
struct V_192 * V_192 ;
int V_75 ;
if ( F_242 ( V_10 ) )
return 1 ;
V_512 = F_248 ( V_10 , V_10 -> V_1 -> V_68 . V_515 , & V_192 ) ;
if ( ! V_512 )
return 1 ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
V_75 = F_219 ( & V_10 -> V_9 ) ;
F_279 ( V_10 -> V_1 , V_512 ) ;
F_253 ( V_192 ) ;
return V_75 ;
}
static int F_282 ( struct V_7 * V_10 )
{
if ( F_242 ( V_10 ) )
return 1 ;
F_41 ( & V_10 -> V_9 , F_40 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_274 ( V_10 ) )
return 1 ;
if ( ! F_272 ( V_10 ) )
goto V_534;
return 1 ;
V_534:
V_10 -> V_1 -> V_2 . V_463 = V_503 ;
V_10 -> V_1 -> V_2 . V_465 = 0 ;
V_10 -> V_1 -> V_2 . V_432 = 0 ;
V_10 -> V_1 -> V_2 . V_431 = 0 ;
F_236 ( V_10 ) ;
return 1 ;
}
static int F_283 ( struct V_7 * V_10 )
{
int V_75 ;
if ( F_242 ( V_10 ) )
return 1 ;
if ( F_21 ( V_10 ) )
F_20 ( V_10 , V_267 ) ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
V_75 = F_219 ( & V_10 -> V_9 ) ;
F_215 ( V_535 , & V_10 -> V_9 ) ;
F_22 ( V_10 ) ;
return V_75 ;
}
static int F_284 ( struct V_7 * V_10 )
{
int V_75 ;
if ( F_242 ( V_10 ) )
return 1 ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
V_75 = F_219 ( & V_10 -> V_9 ) ;
F_23 ( V_10 ) ;
if ( ! F_118 ( & V_10 -> V_9 ) ) {
F_177 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_46 &= ~ V_536 ;
F_3 ( V_10 -> V_1 , V_537 ) ;
}
return V_75 ;
}
static int F_285 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_286 ( V_10 -> V_1 -> V_68 . V_96 , F_287 ( & V_10 -> V_9 , V_491 ) ,
F_287 ( & V_10 -> V_9 , V_519 ) ) ;
F_288 ( V_9 , F_287 ( & V_10 -> V_9 , V_519 ) ) ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
return F_219 ( & V_10 -> V_9 ) ;
}
static int F_289 ( struct V_7 * V_10 )
{
F_290 ( V_10 -> V_1 -> V_68 . V_96 , F_287 ( & V_10 -> V_9 , V_519 ) ) ;
F_206 ( & V_10 -> V_9 , V_245 ) ;
return 1 ;
}
static int F_291 ( struct V_7 * V_10 )
{
return F_292 ( & V_10 -> V_9 ) ;
}
static int F_293 ( struct V_7 * V_10 )
{
T_1 V_538 = F_294 ( & V_10 -> V_9 ) ;
T_2 V_154 = F_287 ( & V_10 -> V_9 , V_491 ) ;
if ( F_295 ( & V_10 -> V_9 , V_154 , V_538 ) == 0 ) {
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 3 ;
return F_219 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_296 ( struct V_7 * V_10 )
{
T_10 V_539 ;
int V_540 ;
int V_541 = V_10 -> V_1 -> V_2 . V_510 &
V_542 ;
int V_543 = V_10 -> V_1 -> V_2 . V_510 & V_544 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_510 & V_542 ;
T_7 V_545 =
V_10 -> V_1 -> V_2 . V_510 & V_546 ;
bool V_91 = false ;
T_2 V_94 = 0 ;
V_539 = ( T_10 ) V_10 -> V_1 -> V_2 . V_432 ;
if ( V_10 -> V_1 -> V_2 . V_431 &
( 1ULL << V_547 ) )
V_540 = V_548 ;
else if ( V_10 -> V_1 -> V_2 . V_431 &
( 1ULL << V_549 ) )
V_540 = V_550 ;
else if ( V_545 )
V_540 = V_551 ;
else
V_540 = V_552 ;
if ( V_540 == V_551 ) {
switch ( type ) {
case V_553 :
V_10 -> V_9 . V_49 . V_554 = false ;
break;
case V_555 :
if ( V_10 -> V_1 -> V_2 . V_431 &
( 1ULL << V_556 ) ) {
V_91 = true ;
V_94 =
( T_2 ) V_10 -> V_1 -> V_2 . V_431 ;
}
F_268 ( & V_10 -> V_9 ) ;
break;
case V_557 :
F_269 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_540 != V_551 ||
V_541 == V_558 ||
( V_541 == V_555 &&
( V_543 == V_559 || V_543 == V_95 ) ) )
F_35 ( & V_10 -> V_9 ) ;
if ( V_541 != V_558 )
V_543 = - 1 ;
if ( F_297 ( & V_10 -> V_9 , V_539 , V_543 , V_540 ,
V_91 , V_94 ) == V_560 ) {
V_10 -> V_9 . V_436 -> V_438 = V_561 ;
V_10 -> V_9 . V_436 -> V_562 . V_563 = V_564 ;
V_10 -> V_9 . V_436 -> V_562 . V_565 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_298 ( struct V_7 * V_10 )
{
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 2 ;
return F_299 ( & V_10 -> V_9 ) ;
}
static int F_300 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_365 . V_566 ;
F_20 ( V_10 , V_567 ) ;
V_10 -> V_9 . V_49 . V_50 |= V_568 ;
V_10 -> V_569 = F_40 ( & V_10 -> V_9 ) ;
F_215 ( V_535 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_301 ( struct V_7 * V_10 )
{
if ( ! F_37 ( V_570 ) )
return F_38 ( & V_10 -> V_9 , 0 ) == V_84 ;
F_288 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_432 ) ;
return F_219 ( & V_10 -> V_9 ) ;
}
static int F_302 ( struct V_7 * V_10 )
{
return F_38 ( & V_10 -> V_9 , 0 ) == V_84 ;
}
static int F_303 ( struct V_7 * V_10 )
{
int V_108 ;
if ( ! F_37 ( V_82 ) )
return F_302 ( V_10 ) ;
V_108 = F_304 ( & V_10 -> V_9 ) ;
return F_305 ( & V_10 -> V_9 , V_108 ) ;
}
static bool F_306 ( struct V_7 * V_10 ,
unsigned long V_109 )
{
unsigned long V_407 = V_10 -> V_9 . V_49 . V_407 ;
bool V_75 = false ;
T_1 V_29 ;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! F_10 ( & V_10 -> V_9 ) ||
( ! ( V_29 & ( 1ULL << V_252 ) ) ) )
return false ;
V_407 &= ~ V_409 ;
V_109 &= ~ V_409 ;
if ( V_407 ^ V_109 ) {
V_10 -> V_1 -> V_2 . V_463 = V_571 ;
V_75 = ( F_262 ( V_10 ) == V_474 ) ;
}
return V_75 ;
}
static int F_307 ( struct V_7 * V_10 )
{
int V_372 , V_572 ;
unsigned long V_109 ;
int V_108 ;
if ( ! F_37 ( V_570 ) )
return F_302 ( V_10 ) ;
if ( F_160 ( ( V_10 -> V_1 -> V_2 . V_432 & V_573 ) == 0 ) )
return F_302 ( V_10 ) ;
V_372 = V_10 -> V_1 -> V_2 . V_432 & V_574 ;
if ( V_10 -> V_1 -> V_2 . V_463 == V_571 )
V_572 = V_575 - V_498 ;
else
V_572 = V_10 -> V_1 -> V_2 . V_463 - V_498 ;
V_108 = 0 ;
if ( V_572 >= 16 ) {
V_572 -= 16 ;
V_109 = F_287 ( & V_10 -> V_9 , V_372 ) ;
switch ( V_572 ) {
case 0 :
if ( ! F_306 ( V_10 , V_109 ) )
V_108 = F_308 ( & V_10 -> V_9 , V_109 ) ;
else
return 1 ;
break;
case 3 :
V_108 = F_270 ( & V_10 -> V_9 , V_109 ) ;
break;
case 4 :
V_108 = F_309 ( & V_10 -> V_9 , V_109 ) ;
break;
case 8 :
V_108 = F_310 ( & V_10 -> V_9 , V_109 ) ;
break;
default:
F_311 ( 1 , L_14 , V_572 ) ;
F_206 ( & V_10 -> V_9 , V_245 ) ;
return 1 ;
}
} else {
switch ( V_572 ) {
case 0 :
V_109 = F_266 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_109 = V_10 -> V_9 . V_49 . V_479 ;
break;
case 3 :
V_109 = F_175 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_109 = F_312 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_109 = F_313 ( & V_10 -> V_9 ) ;
break;
default:
F_311 ( 1 , L_15 , V_572 ) ;
F_206 ( & V_10 -> V_9 , V_245 ) ;
return 1 ;
}
F_147 ( & V_10 -> V_9 , V_372 , V_109 ) ;
}
return F_305 ( & V_10 -> V_9 , V_108 ) ;
}
static int F_314 ( struct V_7 * V_10 )
{
int V_372 , V_576 ;
unsigned long V_109 ;
if ( V_10 -> V_9 . V_174 == 0 ) {
F_16 ( V_10 ) ;
V_10 -> V_9 . V_49 . V_428 |= V_429 ;
return 1 ;
}
if ( ! F_99 ( V_570 ) )
return F_302 ( V_10 ) ;
V_372 = V_10 -> V_1 -> V_2 . V_432 & V_574 ;
V_576 = V_10 -> V_1 -> V_2 . V_463 - V_500 ;
if ( V_576 >= 16 ) {
if ( ! F_315 ( & V_10 -> V_9 , V_576 - 16 ) )
return 1 ;
V_109 = F_287 ( & V_10 -> V_9 , V_372 ) ;
F_316 ( & V_10 -> V_9 , V_576 - 16 , V_109 ) ;
} else {
if ( ! F_315 ( & V_10 -> V_9 , V_576 ) )
return 1 ;
F_260 ( & V_10 -> V_9 , V_576 , & V_109 ) ;
F_147 ( & V_10 -> V_9 , V_372 , V_109 ) ;
}
return F_219 ( & V_10 -> V_9 ) ;
}
static int F_317 ( struct V_7 * V_10 )
{
struct V_435 * V_435 = V_10 -> V_9 . V_436 ;
int V_150 ;
T_4 V_577 = F_313 ( & V_10 -> V_9 ) ;
V_150 = F_307 ( V_10 ) ;
if ( F_318 ( & V_10 -> V_9 ) )
return V_150 ;
if ( V_577 <= F_313 ( & V_10 -> V_9 ) )
return V_150 ;
V_435 -> V_438 = V_578 ;
return 0 ;
}
static int F_319 ( struct V_8 * V_9 , struct V_579 * V_580 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_580 -> V_154 ) {
case V_581 : {
V_580 -> V_11 = V_10 -> V_1 -> V_2 . V_224 +
F_320 ( V_9 , F_321 () ) ;
break;
}
case V_582 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_527 ;
break;
#ifdef F_30
case V_583 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_528 ;
break;
case V_584 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_529 ;
break;
case V_367 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_526 ;
break;
case V_585 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_530 ;
break;
#endif
case V_586 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_531 ;
break;
case V_587 :
V_580 -> V_11 = V_10 -> V_533 ;
break;
case V_588 :
V_580 -> V_11 = V_10 -> V_532 ;
break;
case V_363 :
if ( ! F_99 ( V_362 ) )
return 1 ;
V_580 -> V_11 = V_10 -> V_364 ;
break;
case V_589 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_590 ;
break;
case V_169 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_591 ;
break;
case V_170 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_592 ;
break;
case V_171 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_593 ;
break;
case V_172 :
V_580 -> V_11 = V_10 -> V_1 -> V_68 . V_594 ;
break;
case V_141 :
V_580 -> V_11 = V_10 -> V_24 . V_595 ;
break;
case V_596 :
V_580 -> V_11 = V_10 -> V_24 . V_597 ;
break;
case V_598 :
V_580 -> V_11 = 0x01000065 ;
break;
case V_599 : {
int V_600 , V_601 ;
V_600 = F_322 ( V_9 ) ;
V_601 = F_323 ( V_9 ) ;
if ( V_600 < 0 || V_601 < 0 )
return F_324 ( V_9 , V_580 ) ;
V_580 -> V_11 = 0 ;
if ( V_600 == 0x15 &&
( V_601 >= 0x2 && V_601 < 0x20 ) )
V_580 -> V_11 = 0x1E ;
}
break;
default:
return F_324 ( V_9 , V_580 ) ;
}
return 0 ;
}
static int F_325 ( struct V_7 * V_10 )
{
T_2 V_602 = F_287 ( & V_10 -> V_9 , V_491 ) ;
struct V_579 V_580 ;
V_580 . V_154 = V_602 ;
V_580 . V_603 = false ;
if ( F_319 ( & V_10 -> V_9 , & V_580 ) ) {
F_326 ( V_602 ) ;
F_243 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
} else {
F_327 ( V_602 , V_580 . V_11 ) ;
F_147 ( & V_10 -> V_9 , V_519 ,
V_580 . V_11 & 0xffffffff ) ;
F_147 ( & V_10 -> V_9 , V_341 ,
V_580 . V_11 >> 32 ) ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 2 ;
return F_219 ( & V_10 -> V_9 ) ;
}
}
static int F_328 ( struct V_8 * V_9 , T_1 V_11 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_604 , V_605 ;
if ( V_11 & ~ V_606 )
return 1 ;
V_605 = V_606 ;
if ( V_10 -> V_24 . V_597 & V_607 )
V_605 &= ~ ( V_608 | V_607 ) ;
V_10 -> V_24 . V_597 &= ~ V_605 ;
V_10 -> V_24 . V_597 |= ( V_11 & V_605 ) ;
V_604 = V_10 -> V_24 . V_597 & V_607 ;
if ( V_604 && ( V_9 -> V_49 . V_64 & V_69 ) )
return 1 ;
return 0 ;
}
static int F_329 ( struct V_8 * V_9 , struct V_579 * V_52 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_602 = V_52 -> V_154 ;
T_1 V_11 = V_52 -> V_11 ;
switch ( V_602 ) {
case V_581 :
F_330 ( V_9 , V_52 ) ;
break;
case V_582 :
V_10 -> V_1 -> V_68 . V_527 = V_11 ;
break;
#ifdef F_30
case V_583 :
V_10 -> V_1 -> V_68 . V_528 = V_11 ;
break;
case V_584 :
V_10 -> V_1 -> V_68 . V_529 = V_11 ;
break;
case V_367 :
V_10 -> V_1 -> V_68 . V_526 = V_11 ;
break;
case V_585 :
V_10 -> V_1 -> V_68 . V_530 = V_11 ;
break;
#endif
case V_586 :
V_10 -> V_1 -> V_68 . V_531 = V_11 ;
break;
case V_587 :
V_10 -> V_533 = V_11 ;
V_10 -> V_1 -> V_68 . V_533 = V_11 ;
break;
case V_588 :
V_10 -> V_532 = V_11 ;
V_10 -> V_1 -> V_68 . V_532 = V_11 ;
break;
case V_363 :
if ( ! F_99 ( V_362 ) )
return 1 ;
V_10 -> V_364 = V_11 ;
F_54 ( V_363 , V_10 -> V_364 ) ;
break;
case V_589 :
if ( ! F_99 ( V_609 ) ) {
F_331 ( V_9 , L_16 ,
V_86 , V_11 ) ;
break;
}
if ( V_11 & V_610 )
return 1 ;
V_10 -> V_1 -> V_68 . V_590 = V_11 ;
F_3 ( V_10 -> V_1 , V_611 ) ;
if ( V_11 & ( 1ULL << 0 ) )
F_84 ( V_10 ) ;
else
F_85 ( V_10 ) ;
break;
case V_141 :
V_10 -> V_24 . V_595 = V_11 ;
break;
case V_596 :
return F_328 ( V_9 , V_11 ) ;
case V_612 :
F_331 ( V_9 , L_17 , V_602 , V_11 ) ;
break;
case V_613 :
if ( F_118 ( V_9 ) )
F_6 ( F_4 ( V_9 ) , V_11 ) ;
default:
return F_332 ( V_9 , V_52 ) ;
}
return 0 ;
}
static int F_333 ( struct V_7 * V_10 )
{
struct V_579 V_52 ;
T_2 V_602 = F_287 ( & V_10 -> V_9 , V_491 ) ;
T_1 V_11 = F_294 ( & V_10 -> V_9 ) ;
V_52 . V_11 = V_11 ;
V_52 . V_154 = V_602 ;
V_52 . V_603 = false ;
V_10 -> V_81 = F_40 ( & V_10 -> V_9 ) + 2 ;
if ( F_334 ( & V_10 -> V_9 , & V_52 ) ) {
F_335 ( V_602 , V_11 ) ;
F_243 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
} else {
F_336 ( V_602 , V_11 ) ;
return F_219 ( & V_10 -> V_9 ) ;
}
}
static int F_337 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_432 )
return F_333 ( V_10 ) ;
else
return F_325 ( V_10 ) ;
}
static int F_338 ( struct V_7 * V_10 )
{
F_215 ( V_535 , & V_10 -> V_9 ) ;
F_177 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_46 &= ~ V_536 ;
F_3 ( V_10 -> V_1 , V_537 ) ;
++ V_10 -> V_9 . V_365 . V_614 ;
return 1 ;
}
static int F_339 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
bool V_615 = ( F_181 ( V_9 ) == 0 ) ;
F_340 ( V_9 , V_615 ) ;
return 1 ;
}
static int F_341 ( struct V_7 * V_10 )
{
return F_219 ( & ( V_10 -> V_9 ) ) ;
}
static int F_342 ( struct V_7 * V_10 )
{
F_343 ( V_616 L_18 ) ;
return F_341 ( V_10 ) ;
}
static int F_344 ( struct V_7 * V_10 )
{
F_343 ( V_616 L_19 ) ;
return F_341 ( V_10 ) ;
}
static int F_345 ( struct V_7 * V_10 )
{
T_2 V_617 = V_10 -> V_1 -> V_2 . V_432 >> 32 ;
T_2 V_618 = V_10 -> V_1 -> V_2 . V_432 ;
T_2 V_311 = V_10 -> V_1 -> V_2 . V_431 >> 32 ;
T_2 V_154 = V_10 -> V_1 -> V_2 . V_431 & 0xFF ;
struct V_619 * V_312 = V_10 -> V_9 . V_49 . V_312 ;
F_346 ( V_10 -> V_9 . V_185 , V_617 , V_618 , V_311 , V_154 ) ;
switch ( V_311 ) {
case V_620 :
F_347 ( V_312 , V_621 , V_617 ) ;
F_347 ( V_312 , V_622 , V_618 ) ;
break;
case V_623 : {
int V_54 ;
struct V_8 * V_9 ;
struct V_187 * V_187 = V_10 -> V_9 . V_187 ;
struct V_619 * V_312 = V_10 -> V_9 . V_49 . V_312 ;
F_348 (i, vcpu, kvm) {
bool V_624 = F_349 ( V_9 , V_312 ,
V_618 & V_625 ,
F_350 ( V_617 ) ,
V_618 & V_626 ) ;
if ( V_624 && ! F_7 ( V_9 ) )
F_95 ( V_9 ) ;
}
break;
}
case V_627 :
break;
case V_628 :
F_351 ( 1 , L_20 ) ;
break;
default:
F_60 ( L_21 ) ;
}
return 1 ;
}
static T_2 * F_352 ( struct V_8 * V_9 , T_2 V_629 , bool V_630 )
{
struct V_182 * V_188 = & V_9 -> V_187 -> V_49 ;
int V_154 ;
T_2 * V_631 ;
int V_632 = F_353 ( V_629 ) ;
if ( ! V_632 )
return NULL ;
if ( V_630 ) {
V_154 = F_354 ( V_632 ) - 1 ;
if ( V_154 > 7 )
return NULL ;
} else {
int V_633 = ( V_632 & 0xf0 ) >> 4 ;
int V_312 = F_354 ( V_632 & 0x0f ) - 1 ;
if ( ( V_312 < 0 ) || ( V_312 > 7 ) ||
( V_633 >= 0xf ) )
return NULL ;
V_154 = ( V_633 << 2 ) + V_312 ;
}
V_631 = ( T_2 * ) F_98 ( V_188 -> V_228 ) ;
return & V_631 [ V_154 ] ;
}
static int F_355 ( struct V_8 * V_9 , T_4 V_634 , T_2 V_629 ,
bool V_635 )
{
bool V_630 ;
T_2 * V_15 , V_310 ;
V_630 = F_356 ( V_9 -> V_49 . V_312 , V_636 ) == V_637 ;
V_15 = F_352 ( V_9 , V_629 , V_630 ) ;
if ( ! V_15 )
return - V_132 ;
V_310 = F_8 ( * V_15 ) ;
V_310 &= ~ V_638 ;
V_310 |= ( V_634 & V_638 ) ;
if ( V_635 )
V_310 |= V_639 ;
else
V_310 &= ~ V_639 ;
F_129 ( * V_15 , V_310 ) ;
return 0 ;
}
static int F_357 ( struct V_8 * V_9 )
{
int V_75 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_629 = F_356 ( V_9 -> V_49 . V_312 , V_640 ) ;
if ( ! V_629 )
return 1 ;
V_75 = F_355 ( V_9 , V_9 -> V_185 , V_629 , true ) ;
if ( V_75 && V_10 -> V_641 ) {
F_355 ( V_9 , 0 , V_10 -> V_641 , false ) ;
V_10 -> V_641 = 0 ;
} else {
V_10 -> V_641 = V_629 ;
}
return V_75 ;
}
static int F_358 ( struct V_8 * V_9 )
{
T_1 * V_642 , * V_643 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_644 = F_356 ( V_9 -> V_49 . V_312 , V_645 ) ;
T_2 V_311 = ( V_644 >> 24 ) & 0xff ;
if ( V_9 -> V_185 == V_311 )
return 0 ;
V_642 = F_124 ( V_9 , V_9 -> V_185 ) ;
V_643 = F_124 ( V_9 , V_311 ) ;
if ( ! V_643 || ! V_642 )
return 1 ;
* V_643 = * V_642 ;
* V_642 = 0ULL ;
F_4 ( V_9 ) -> V_16 = V_643 ;
if ( V_10 -> V_641 )
F_357 ( V_9 ) ;
return 0 ;
}
static int F_359 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_182 * V_188 = & V_9 -> V_187 -> V_49 ;
T_2 V_646 = F_356 ( V_9 -> V_49 . V_312 , V_636 ) ;
T_2 V_647 = ( V_646 >> 28 ) & 0xf ;
if ( V_188 -> V_648 == V_647 )
return 0 ;
F_133 ( F_98 ( V_188 -> V_228 ) ) ;
V_188 -> V_648 = V_647 ;
if ( V_10 -> V_641 )
F_357 ( V_9 ) ;
return 0 ;
}
static int F_360 ( struct V_7 * V_10 )
{
struct V_619 * V_312 = V_10 -> V_9 . V_49 . V_312 ;
T_2 V_53 = V_10 -> V_1 -> V_2 . V_432 &
V_649 ;
switch ( V_53 ) {
case V_645 :
if ( F_358 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_640 :
if ( F_357 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_636 :
F_359 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
F_347 ( V_312 , V_53 , F_356 ( V_312 , V_53 ) ) ;
return 1 ;
}
static bool F_361 ( T_2 V_53 )
{
bool V_75 = false ;
switch ( V_53 ) {
case V_645 :
case V_650 :
case V_651 :
case V_640 :
case V_636 :
case V_652 :
case V_653 :
case V_622 :
case V_654 :
case V_655 :
case V_656 :
case V_657 :
case V_658 :
case V_659 :
case V_660 :
case V_661 :
V_75 = true ;
break;
default:
break;
}
return V_75 ;
}
static int F_362 ( struct V_7 * V_10 )
{
int V_75 = 0 ;
T_2 V_53 = V_10 -> V_1 -> V_2 . V_432 &
V_649 ;
T_2 V_662 = V_10 -> V_1 -> V_2 . V_431 &
V_663 ;
bool V_158 = ( V_10 -> V_1 -> V_2 . V_432 >> 32 ) &
V_664 ;
bool V_665 = F_361 ( V_53 ) ;
F_363 ( V_10 -> V_9 . V_185 , V_53 ,
V_665 , V_158 , V_662 ) ;
if ( V_665 ) {
F_351 ( ! V_158 , L_22 ) ;
V_75 = F_360 ( V_10 ) ;
} else {
V_75 = ( F_38 ( & V_10 -> V_9 , 0 ) == V_84 ) ;
}
return V_75 ;
}
static void F_364 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_236 * V_68 = & V_10 -> V_1 -> V_68 ;
F_60 ( L_23 ) ;
F_60 ( L_24 , L_25 , V_2 -> V_26 & 0xffff ) ;
F_60 ( L_24 , L_26 , V_2 -> V_26 >> 16 ) ;
F_60 ( L_24 , L_27 , V_2 -> V_27 & 0xffff ) ;
F_60 ( L_24 , L_28 , V_2 -> V_27 >> 16 ) ;
F_60 ( L_29 , L_30 , V_2 -> V_28 ) ;
F_60 ( L_31 , L_32 , V_2 -> V_29 ) ;
F_60 ( L_33 , L_34 , V_2 -> V_303 ) ;
F_60 ( L_31 , L_35 , V_2 -> V_274 ) ;
F_60 ( L_31 , L_36 , V_2 -> V_275 ) ;
F_60 ( L_31 , L_37 , V_2 -> V_224 ) ;
F_60 ( L_33 , L_38 , V_2 -> V_61 ) ;
F_60 ( L_33 , L_39 , V_2 -> V_422 ) ;
F_60 ( L_29 , L_40 , V_2 -> V_46 ) ;
F_60 ( L_29 , L_41 , V_2 -> V_509 ) ;
F_60 ( L_29 , L_42 , V_2 -> V_76 ) ;
F_60 ( L_29 , L_43 , V_2 -> V_463 ) ;
F_60 ( L_31 , L_44 , V_2 -> V_432 ) ;
F_60 ( L_31 , L_45 , V_2 -> V_431 ) ;
F_60 ( L_29 , L_46 , V_2 -> V_510 ) ;
F_60 ( L_29 , L_47 , V_2 -> V_511 ) ;
F_60 ( L_48 , L_49 , V_2 -> V_298 ) ;
F_60 ( L_31 , L_50 , V_2 -> V_457 ) ;
F_60 ( L_31 , L_51 , V_2 -> V_12 ) ;
F_60 ( L_29 , L_52 , V_2 -> V_102 ) ;
F_60 ( L_29 , L_53 , V_2 -> V_105 ) ;
F_60 ( L_48 , L_54 , V_2 -> V_167 ) ;
F_60 ( L_31 , L_55 , V_2 -> V_81 ) ;
F_60 ( L_31 , L_56 , V_2 -> V_226 ) ;
F_60 ( L_31 , L_57 , V_2 -> V_232 ) ;
F_60 ( L_31 , L_58 , V_2 -> V_233 ) ;
F_60 ( L_59 ) ;
F_60 ( L_60 ,
L_61 ,
V_68 -> V_277 . V_217 , V_68 -> V_277 . V_218 ,
V_68 -> V_277 . V_222 , V_68 -> V_277 . V_100 ) ;
F_60 ( L_60 ,
L_62 ,
V_68 -> V_99 . V_217 , V_68 -> V_99 . V_218 ,
V_68 -> V_99 . V_222 , V_68 -> V_99 . V_100 ) ;
F_60 ( L_60 ,
L_63 ,
V_68 -> V_278 . V_217 , V_68 -> V_278 . V_218 ,
V_68 -> V_278 . V_222 , V_68 -> V_278 . V_100 ) ;
F_60 ( L_60 ,
L_64 ,
V_68 -> V_279 . V_217 , V_68 -> V_279 . V_218 ,
V_68 -> V_279 . V_222 , V_68 -> V_279 . V_100 ) ;
F_60 ( L_60 ,
L_65 ,
V_68 -> V_280 . V_217 , V_68 -> V_280 . V_218 ,
V_68 -> V_280 . V_222 , V_68 -> V_280 . V_100 ) ;
F_60 ( L_60 ,
L_66 ,
V_68 -> V_281 . V_217 , V_68 -> V_281 . V_218 ,
V_68 -> V_281 . V_222 , V_68 -> V_281 . V_100 ) ;
F_60 ( L_60 ,
L_67 ,
V_68 -> V_284 . V_217 , V_68 -> V_284 . V_218 ,
V_68 -> V_284 . V_222 , V_68 -> V_284 . V_100 ) ;
F_60 ( L_60 ,
L_68 ,
V_68 -> V_286 . V_217 , V_68 -> V_286 . V_218 ,
V_68 -> V_286 . V_222 , V_68 -> V_286 . V_100 ) ;
F_60 ( L_60 ,
L_69 ,
V_68 -> V_285 . V_217 , V_68 -> V_285 . V_218 ,
V_68 -> V_285 . V_222 , V_68 -> V_285 . V_100 ) ;
F_60 ( L_60 ,
L_70 ,
V_68 -> V_288 . V_217 , V_68 -> V_288 . V_218 ,
V_68 -> V_288 . V_222 , V_68 -> V_288 . V_100 ) ;
F_60 ( L_71 ,
V_68 -> V_400 , V_68 -> V_64 ) ;
F_60 ( L_72 ,
L_73 , V_68 -> V_407 , L_74 , V_68 -> V_479 ) ;
F_60 ( L_72 ,
L_75 , V_68 -> V_301 , L_76 , V_68 -> V_296 ) ;
F_60 ( L_72 ,
L_77 , V_68 -> V_290 , L_78 , V_68 -> V_427 ) ;
F_60 ( L_72 ,
L_79 , V_68 -> V_96 , L_80 , V_68 -> V_178 ) ;
F_60 ( L_72 ,
L_81 , V_68 -> V_514 , L_82 , V_68 -> V_515 ) ;
F_60 ( L_72 ,
L_83 , V_68 -> V_527 , L_84 , V_68 -> V_528 ) ;
F_60 ( L_72 ,
L_85 , V_68 -> V_529 , L_86 , V_68 -> V_530 ) ;
F_60 ( L_72 ,
L_87 , V_68 -> V_526 ,
L_88 , V_68 -> V_531 ) ;
F_60 ( L_72 ,
L_89 , V_68 -> V_532 ,
L_90 , V_68 -> V_533 ) ;
F_60 ( L_72 ,
L_91 , V_68 -> V_299 , L_92 , V_68 -> V_590 ) ;
F_60 ( L_72 ,
L_93 , V_68 -> V_591 , L_94 , V_68 -> V_592 ) ;
F_60 ( L_72 ,
L_95 , V_68 -> V_593 ,
L_96 , V_68 -> V_594 ) ;
}
static void F_365 ( struct V_8 * V_9 , T_1 * V_666 , T_1 * V_667 )
{
struct V_18 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_666 = V_2 -> V_432 ;
* V_667 = V_2 -> V_431 ;
}
static int F_366 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_435 * V_435 = V_9 -> V_436 ;
T_2 V_463 = V_10 -> V_1 -> V_2 . V_463 ;
F_367 ( V_463 , V_9 , V_513 ) ;
if ( ! F_14 ( V_10 , V_240 ) )
V_9 -> V_49 . V_407 = V_10 -> V_1 -> V_68 . V_407 ;
if ( V_65 )
V_9 -> V_49 . V_301 = V_10 -> V_1 -> V_68 . V_301 ;
if ( F_160 ( V_10 -> V_24 . V_480 ) ) {
F_236 ( V_10 ) ;
V_10 -> V_24 . V_480 = false ;
return 1 ;
}
if ( F_10 ( V_9 ) ) {
int V_473 ;
F_368 ( V_10 -> V_1 -> V_68 . V_96 , V_463 ,
V_10 -> V_1 -> V_2 . V_432 ,
V_10 -> V_1 -> V_2 . V_431 ,
V_10 -> V_1 -> V_2 . V_510 ,
V_10 -> V_1 -> V_2 . V_511 ,
V_513 ) ;
V_473 = F_261 ( V_10 ) ;
if ( V_473 == V_495 )
V_473 = F_262 ( V_10 ) ;
if ( V_473 == V_474 )
return 1 ;
}
F_369 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_463 == V_503 ) {
V_435 -> V_438 = V_668 ;
V_435 -> V_669 . V_670
= V_10 -> V_1 -> V_2 . V_463 ;
F_60 ( L_97 ) ;
F_364 ( V_9 ) ;
return 0 ;
}
if ( F_32 ( V_10 -> V_1 -> V_2 . V_510 ) &&
V_463 != V_475 + V_244 &&
V_463 != V_464 && V_463 != V_671 &&
V_463 != V_483 && V_463 != V_484 )
F_39 ( V_88 L_98
L_99 ,
V_86 , V_10 -> V_1 -> V_2 . V_510 ,
V_463 ) ;
if ( V_463 >= F_370 ( V_672 )
|| ! V_672 [ V_463 ] ) {
F_351 ( 1 , L_100 , V_463 ) ;
F_206 ( V_9 , V_245 ) ;
return 1 ;
}
return V_672 [ V_463 ] ( V_10 ) ;
}
static void F_371 ( struct V_8 * V_9 )
{
int V_149 = F_58 () ;
struct V_125 * V_126 = F_61 ( V_133 , V_149 ) ;
V_126 -> V_138 -> type = 9 ;
F_372 () ;
}
static void F_373 ( struct V_7 * V_10 )
{
int V_149 = F_58 () ;
struct V_125 * V_126 = F_61 ( V_133 , V_149 ) ;
if ( V_10 -> V_134 != V_126 -> V_134 )
F_197 ( V_10 , V_126 ) ;
}
static void F_374 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_102 = V_73 | V_673 ;
V_9 -> V_49 . V_50 |= V_674 ;
F_19 ( V_10 , V_567 ) ;
++ V_9 -> V_365 . V_675 ;
}
static inline void F_375 ( struct V_7 * V_10 , int V_676 )
{
struct V_18 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_509 = V_676 ;
V_2 -> V_46 &= ~ V_677 ;
V_2 -> V_46 |= V_536 |
( ( 0xf ) << V_678 ) ;
F_3 ( V_10 -> V_1 , V_537 ) ;
}
static void F_376 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_77 ( ! ( F_24 ( V_10 ) ) ) ;
F_377 ( V_9 -> V_49 . V_679 . V_89 ) ;
++ V_9 -> V_365 . V_680 ;
V_10 -> V_1 -> V_2 . V_102 = V_9 -> V_49 . V_679 . V_89 |
V_73 | V_74 ;
}
static inline bool F_378 ( struct V_8 * V_9 )
{
return F_10 ( V_9 ) && ( V_9 -> V_49 . V_50 & V_481 ) ;
}
static void F_379 ( struct V_8 * V_9 , int V_681 , int V_682 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_378 ( V_9 ) ||
F_118 ( V_9 ) )
return;
F_13 ( V_10 , V_243 ) ;
if ( V_682 == - 1 )
return;
if ( V_681 >= V_682 )
F_12 ( V_10 , V_243 ) ;
}
static void F_380 ( struct V_8 * V_9 , bool V_683 )
{
return;
}
static bool F_381 ( struct V_8 * V_9 )
{
return V_208 && F_382 ( V_9 -> V_187 ) ;
}
static void F_383 ( struct V_8 * V_9 , int V_684 )
{
}
static void F_384 ( struct V_8 * V_9 , int V_685 )
{
}
static void F_385 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( ! F_118 ( & V_10 -> V_9 ) )
return;
V_1 -> V_2 . V_46 &= ~ V_235 ;
F_3 ( V_1 , V_537 ) ;
}
static void F_386 ( struct V_8 * V_9 , T_1 * V_686 )
{
return;
}
static void F_387 ( struct V_8 * V_9 , int V_687 )
{
F_388 ( V_687 , V_9 -> V_49 . V_312 ) ;
F_389 () ;
if ( F_7 ( V_9 ) )
F_54 ( V_688 ,
F_141 ( V_9 -> V_149 ) ) ;
else
F_95 ( V_9 ) ;
}
static void F_390 ( struct V_7 * V_10 , struct V_689 * V_690 )
{
unsigned long V_181 ;
struct V_326 * V_691 ;
F_91 ( & V_10 -> V_328 , V_181 ) ;
F_138 (cur, &svm->ir_list, node) {
if ( V_691 -> V_11 != V_690 -> V_692 )
continue;
F_391 ( & V_691 -> V_693 ) ;
F_70 ( V_691 ) ;
break;
}
F_94 ( & V_10 -> V_328 , V_181 ) ;
}
static int F_392 ( struct V_7 * V_10 , struct V_689 * V_690 )
{
int V_75 = 0 ;
unsigned long V_181 ;
struct V_326 * V_327 ;
if ( V_690 -> V_692 && ( V_690 -> V_694 != 0 ) ) {
struct V_187 * V_187 = V_10 -> V_9 . V_187 ;
T_2 V_185 = F_89 ( V_690 -> V_694 ) ;
struct V_8 * V_695 = F_93 ( V_187 , V_185 ) ;
struct V_7 * V_696 ;
if ( ! V_695 ) {
V_75 = - V_132 ;
goto V_330;
}
V_696 = F_4 ( V_695 ) ;
F_390 ( V_696 , V_690 ) ;
}
V_327 = F_72 ( sizeof( struct V_326 ) , V_151 ) ;
if ( ! V_327 ) {
V_75 = - V_152 ;
goto V_330;
}
V_327 -> V_11 = V_690 -> V_692 ;
F_91 ( & V_10 -> V_328 , V_181 ) ;
F_393 ( & V_327 -> V_693 , & V_10 -> V_329 ) ;
F_94 ( & V_10 -> V_328 , V_181 ) ;
V_330:
return V_75 ;
}
static int
F_394 ( struct V_187 * V_187 , struct V_697 * V_698 ,
struct V_699 * V_700 , struct V_7 * * V_10 )
{
struct V_701 V_676 ;
struct V_8 * V_9 = NULL ;
F_395 ( V_187 , V_698 , & V_676 ) ;
if ( ! F_396 ( V_187 , & V_676 , & V_9 ) ) {
F_90 ( L_101 ,
V_86 , V_676 . V_662 ) ;
return - 1 ;
}
F_90 ( L_102 , V_86 ,
V_676 . V_662 ) ;
* V_10 = F_4 ( V_9 ) ;
V_700 -> V_702 = F_115 ( F_116 ( ( * V_10 ) -> V_226 ) ) ;
V_700 -> V_662 = V_676 . V_662 ;
return 0 ;
}
static int F_397 ( struct V_187 * V_187 , unsigned int V_703 ,
T_7 V_704 , bool V_683 )
{
struct V_697 * V_698 ;
struct V_705 * V_706 ;
int V_707 , V_75 = - V_132 ;
if ( ! F_136 ( V_187 ) ||
! F_398 ( V_708 ) )
return 0 ;
F_90 ( L_103 ,
V_86 , V_703 , V_704 , V_683 ) ;
V_707 = F_399 ( & V_187 -> V_709 ) ;
V_706 = F_400 ( V_187 -> V_710 , & V_187 -> V_709 ) ;
F_76 ( V_704 >= V_706 -> V_711 ) ;
F_401 (e, &irq_rt->map[guest_irq], link) {
struct V_699 V_700 ;
struct V_7 * V_10 = NULL ;
if ( V_698 -> type != V_712 )
continue;
if ( ! F_394 ( V_187 , V_698 , & V_700 , & V_10 ) && V_683 &&
F_118 ( & V_10 -> V_9 ) ) {
struct V_689 V_690 ;
V_690 . V_100 = F_115 ( F_116 ( V_10 -> V_226 ) &
V_231 ) ;
V_690 . V_180 = F_402 ( V_187 -> V_49 . V_189 ,
V_10 -> V_9 . V_185 ) ;
V_690 . F_10 = true ;
V_690 . V_699 = & V_700 ;
V_75 = F_403 ( V_703 , & V_690 ) ;
if ( ! V_75 && V_690 . F_10 )
F_392 ( V_10 , & V_690 ) ;
} else {
struct V_689 V_690 ;
V_690 . F_10 = false ;
V_75 = F_403 ( V_703 , & V_690 ) ;
if ( ! V_75 && V_690 . V_694 ) {
int V_311 = F_89 ( V_690 . V_694 ) ;
struct V_8 * V_9 ;
V_9 = F_93 ( V_187 , V_311 ) ;
if ( V_9 )
F_390 ( F_4 ( V_9 ) , & V_690 ) ;
}
}
if ( ! V_75 && V_10 ) {
F_404 ( V_10 -> V_9 . V_185 ,
V_703 , V_698 -> V_713 ,
V_700 . V_662 ,
V_700 . V_702 , V_683 ) ;
}
if ( V_75 < 0 ) {
F_60 ( L_104 , V_86 ) ;
goto V_330;
}
}
V_75 = 0 ;
V_330:
F_405 ( & V_187 -> V_709 , V_707 ) ;
return V_75 ;
}
static int F_406 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_75 ;
V_75 = ! ( V_1 -> V_2 . V_76 & V_77 ) &&
! ( V_10 -> V_9 . V_49 . V_50 & V_674 ) ;
V_75 = V_75 && F_24 ( V_10 ) && F_247 ( V_10 ) ;
return V_75 ;
}
static bool F_407 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_49 . V_50 & V_674 ) ;
}
static void F_408 ( struct V_8 * V_9 , bool V_714 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_714 ) {
V_10 -> V_9 . V_49 . V_50 |= V_674 ;
F_19 ( V_10 , V_567 ) ;
} else {
V_10 -> V_9 . V_49 . V_50 &= ~ V_674 ;
F_20 ( V_10 , V_567 ) ;
}
}
static int F_409 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_75 ;
if ( ! F_24 ( V_10 ) ||
( V_1 -> V_2 . V_76 & V_77 ) )
return 0 ;
V_75 = ! ! ( F_267 ( V_9 ) & V_523 ) ;
if ( F_10 ( V_9 ) )
return V_75 && ! ( V_10 -> V_9 . V_49 . V_50 & V_481 ) ;
return V_75 ;
}
static void F_410 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_118 ( V_9 ) )
return;
if ( ( F_21 ( V_10 ) || F_24 ( V_10 ) ) && F_245 ( V_10 ) ) {
F_176 ( V_10 ) ;
F_375 ( V_10 , 0x0 ) ;
}
}
static void F_411 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_49 . V_50 & ( V_674 | V_568 ) )
== V_674 )
return;
if ( ! F_24 ( V_10 ) ) {
if ( F_21 ( V_10 ) )
F_19 ( V_10 , V_267 ) ;
return;
}
if ( V_10 -> V_24 . V_480 )
return;
V_10 -> V_176 = F_171 ( V_9 ) ;
V_10 -> V_173 = true ;
V_10 -> V_1 -> V_68 . V_178 |= ( V_177 | V_179 ) ;
}
static int F_412 ( struct V_187 * V_187 , unsigned int V_60 )
{
return 0 ;
}
static void F_194 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_37 ( V_715 ) )
V_10 -> V_1 -> V_2 . V_422 = V_716 ;
else
V_10 -> V_134 -- ;
}
static void F_413 ( struct V_8 * V_9 )
{
}
static inline void F_414 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_378 ( V_9 ) )
return;
if ( ! F_14 ( V_10 , V_243 ) ) {
int V_717 = V_10 -> V_1 -> V_2 . V_46 & V_718 ;
F_310 ( V_9 , V_717 ) ;
}
}
static inline void F_415 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_717 ;
if ( F_378 ( V_9 ) ||
F_118 ( V_9 ) )
return;
V_717 = F_313 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_46 &= ~ V_718 ;
V_10 -> V_1 -> V_2 . V_46 |= V_717 & V_718 ;
}
static void F_369 ( struct V_7 * V_10 )
{
T_4 V_662 ;
int type ;
T_2 V_719 = V_10 -> V_1 -> V_2 . V_510 ;
unsigned V_101 = V_10 -> V_101 ;
V_10 -> V_101 = 0 ;
if ( ( V_10 -> V_9 . V_49 . V_50 & V_568 )
&& F_40 ( & V_10 -> V_9 ) != V_10 -> V_569 ) {
V_10 -> V_9 . V_49 . V_50 &= ~ ( V_674 | V_568 ) ;
F_215 ( V_535 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_49 . V_554 = false ;
F_268 ( & V_10 -> V_9 ) ;
F_269 ( & V_10 -> V_9 ) ;
if ( ! ( V_719 & V_546 ) )
return;
F_215 ( V_535 , & V_10 -> V_9 ) ;
V_662 = V_719 & V_720 ;
type = V_719 & V_542 ;
switch ( type ) {
case V_553 :
V_10 -> V_9 . V_49 . V_554 = true ;
break;
case V_555 :
if ( F_416 ( V_662 ) ) {
if ( V_662 == V_95 && V_101 &&
F_417 ( & V_10 -> V_9 , V_10 -> V_98 ) )
F_41 ( & V_10 -> V_9 ,
F_40 ( & V_10 -> V_9 ) -
V_101 ) ;
break;
}
if ( V_719 & V_721 ) {
T_2 V_108 = V_10 -> V_1 -> V_2 . V_511 ;
F_418 ( & V_10 -> V_9 , V_662 , V_108 ) ;
} else
F_419 ( & V_10 -> V_9 , V_662 ) ;
break;
case V_557 :
F_420 ( & V_10 -> V_9 , V_662 , false ) ;
break;
default:
break;
}
}
static void F_421 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_510 = V_2 -> V_102 ;
V_2 -> V_511 = V_2 -> V_105 ;
V_2 -> V_102 = 0 ;
F_369 ( V_10 ) ;
}
static void F_422 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_515 = V_9 -> V_49 . V_291 [ V_519 ] ;
V_10 -> V_1 -> V_68 . V_514 = V_9 -> V_49 . V_291 [ V_520 ] ;
V_10 -> V_1 -> V_68 . V_96 = V_9 -> V_49 . V_291 [ V_292 ] ;
if ( F_160 ( V_10 -> V_24 . V_480 ) )
return;
if ( V_10 -> V_173 && V_10 -> V_1 -> V_2 . V_102 ) {
F_86 ( V_10 ) ;
F_423 ( V_9 -> V_149 ) ;
}
F_373 ( V_10 ) ;
F_415 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_479 = V_9 -> V_49 . V_479 ;
F_26 () ;
F_424 () ;
asm volatile (
"push %%" _ASM_BP "; \n\t"
"mov %c[rbx](%[svm]), %%" _ASM_BX " \n\t"
"mov %c[rcx](%[svm]), %%" _ASM_CX " \n\t"
"mov %c[rdx](%[svm]), %%" _ASM_DX " \n\t"
"mov %c[rsi](%[svm]), %%" _ASM_SI " \n\t"
"mov %c[rdi](%[svm]), %%" _ASM_DI " \n\t"
"mov %c[rbp](%[svm]), %%" _ASM_BP " \n\t"
#ifdef F_30
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
#ifdef F_30
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
#ifdef F_30
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
#ifdef F_30
, "rbx", "rcx", "rdx", "rsi", "rdi"
, "r8", "r9", "r10", "r11" , "r12", "r13", "r14", "r15"
#else
, "ebx", "ecx", "edx", "esi", "edi"
#endif
);
#ifdef F_30
F_54 ( V_353 , V_10 -> V_354 . V_355 ) ;
#else
F_166 ( V_280 , V_10 -> V_354 . V_280 ) ;
#ifndef F_168
F_166 ( V_281 , V_10 -> V_354 . V_281 ) ;
#endif
#endif
F_371 ( V_9 ) ;
F_425 () ;
V_9 -> V_49 . V_479 = V_10 -> V_1 -> V_68 . V_479 ;
V_9 -> V_49 . V_291 [ V_519 ] = V_10 -> V_1 -> V_68 . V_515 ;
V_9 -> V_49 . V_291 [ V_520 ] = V_10 -> V_1 -> V_68 . V_514 ;
V_9 -> V_49 . V_291 [ V_292 ] = V_10 -> V_1 -> V_68 . V_96 ;
if ( F_160 ( V_10 -> V_1 -> V_2 . V_463 == V_484 ) )
F_426 ( & V_10 -> V_9 ) ;
F_27 () ;
if ( F_160 ( V_10 -> V_1 -> V_2 . V_463 == V_484 ) )
F_427 ( & V_10 -> V_9 ) ;
F_414 ( V_9 ) ;
V_10 -> V_81 = 0 ;
V_10 -> V_1 -> V_2 . V_422 = V_722 ;
if ( V_10 -> V_1 -> V_2 . V_463 == V_475 + V_244 )
V_10 -> V_9 . V_49 . V_477 . V_494 = F_428 () ;
if ( V_65 ) {
V_9 -> V_49 . V_723 &= ~ ( 1 << V_373 ) ;
V_9 -> V_49 . V_724 &= ~ ( 1 << V_373 ) ;
}
if ( F_160 ( V_10 -> V_1 -> V_2 . V_463 ==
V_475 + V_246 ) )
F_214 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_429 ( struct V_8 * V_9 , unsigned long V_459 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_68 . V_301 = F_115 ( V_459 ) ;
F_3 ( V_10 -> V_1 , V_70 ) ;
F_194 ( V_9 ) ;
}
static void F_430 ( struct V_8 * V_9 , unsigned long V_459 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_457 = F_115 ( V_459 ) ;
F_3 ( V_10 -> V_1 , V_460 ) ;
V_10 -> V_1 -> V_68 . V_301 = F_175 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_70 ) ;
F_194 ( V_9 ) ;
}
static int F_431 ( void )
{
T_1 V_725 ;
F_59 ( V_596 , V_725 ) ;
if ( V_725 & ( 1 << V_726 ) )
return 1 ;
return 0 ;
}
static void
F_432 ( struct V_8 * V_9 , unsigned char * V_727 )
{
V_727 [ 0 ] = 0x0f ;
V_727 [ 1 ] = 0x01 ;
V_727 [ 2 ] = 0xd9 ;
}
static void F_433 ( void * V_728 )
{
* ( int * ) V_728 = 0 ;
}
static bool F_434 ( void )
{
return false ;
}
static bool F_435 ( void )
{
return true ;
}
static T_1 F_436 ( struct V_8 * V_9 , T_11 V_729 , bool V_730 )
{
return 0 ;
}
static void F_437 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_516 = ! ! F_438 ( & V_10 -> V_9 , V_82 ) ;
if ( ! F_118 ( V_9 ) )
return;
F_439 ( V_9 , V_731 ) ;
}
static void F_440 ( T_2 V_732 , struct V_733 * V_15 )
{
switch ( V_732 ) {
case 0x1 :
if ( V_208 )
V_15 -> V_602 &= ~ V_6 ( V_731 ) ;
break;
case 0x80000001 :
if ( V_24 )
V_15 -> V_602 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_15 -> V_337 = 1 ;
V_15 -> V_734 = 8 ;
V_15 -> V_602 = 0 ;
V_15 -> V_735 = 0 ;
if ( F_99 ( V_82 ) )
V_15 -> V_735 |= V_736 ;
if ( V_65 )
V_15 -> V_735 |= V_737 ;
break;
}
}
static int F_441 ( void )
{
return V_738 ;
}
static bool F_442 ( void )
{
return F_99 ( V_362 ) ;
}
static bool F_443 ( void )
{
return false ;
}
static bool F_444 ( void )
{
return false ;
}
static bool F_445 ( void )
{
return false ;
}
static bool F_446 ( void )
{
return true ;
}
static int F_447 ( struct V_8 * V_9 ,
struct V_739 * V_71 ,
enum V_740 V_741 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_473 , V_75 = V_742 ;
struct V_743 V_744 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_71 -> V_29 >= F_370 ( V_745 ) )
goto V_330;
V_744 = V_745 [ V_71 -> V_29 ] ;
if ( V_741 != V_744 . V_741 )
goto V_330;
switch ( V_744 . V_463 ) {
case V_498 :
if ( V_71 -> V_29 == V_746 )
V_744 . V_463 += V_71 -> V_747 ;
break;
case V_575 : {
unsigned long V_407 , V_109 ;
T_1 V_29 ;
if ( V_71 -> V_29 == V_748 )
V_744 . V_463 += V_71 -> V_747 ;
if ( V_744 . V_463 != V_575 ||
V_71 -> V_29 == V_749 )
break;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! ( V_29 & ( 1ULL << V_252 ) ) )
break;
V_407 = V_9 -> V_49 . V_407 & ~ V_409 ;
V_109 = V_71 -> V_750 & ~ V_409 ;
if ( V_71 -> V_29 == V_751 ) {
V_407 &= 0xfUL ;
V_109 &= 0xfUL ;
if ( V_407 & V_518 )
V_109 |= V_518 ;
}
if ( V_407 ^ V_109 )
V_744 . V_463 = V_571 ;
break;
}
case V_500 :
case V_752 :
V_744 . V_463 += V_71 -> V_747 ;
break;
case V_496 :
if ( V_71 -> V_29 == V_753 )
V_1 -> V_2 . V_432 = 1 ;
else
V_1 -> V_2 . V_432 = 0 ;
break;
case V_754 :
if ( V_71 -> V_755 != V_756 )
goto V_330;
break;
case V_497 : {
T_1 V_757 ;
T_2 V_758 ;
if ( V_71 -> V_29 == V_759 ||
V_71 -> V_29 == V_760 ) {
V_757 = ( ( V_71 -> V_750 & 0xffff ) << 16 ) |
V_453 ;
V_758 = V_71 -> V_761 ;
} else {
V_757 = ( V_71 -> V_762 & 0xffff ) << 16 ;
V_758 = V_71 -> V_763 ;
}
if ( V_71 -> V_29 == V_764 ||
V_71 -> V_29 == V_760 )
V_757 |= V_452 ;
if ( V_71 -> V_755 )
V_757 |= V_765 ;
V_758 = F_448 ( V_758 , 4u ) ;
V_757 |= V_758 << V_455 ;
V_757 |= ( T_2 ) V_71 -> V_766 << ( V_767 - 1 ) ;
V_1 -> V_2 . V_432 = V_757 ;
V_1 -> V_2 . V_431 = V_71 -> V_81 ;
break;
}
default:
break;
}
if ( F_37 ( V_82 ) )
V_1 -> V_2 . V_81 = V_71 -> V_81 ;
V_1 -> V_2 . V_463 = V_744 . V_463 ;
V_473 = F_262 ( V_10 ) ;
V_75 = ( V_473 == V_474 ) ? V_768
: V_742 ;
V_330:
return V_75 ;
}
static void F_449 ( struct V_8 * V_9 )
{
F_424 () ;
asm("nop");
F_425 () ;
}
static void F_450 ( struct V_8 * V_9 , int V_149 )
{
}
static inline void F_451 ( struct V_8 * V_9 )
{
if ( F_358 ( V_9 ) != 0 )
return;
if ( F_359 ( V_9 ) != 0 )
return;
F_357 ( V_9 ) ;
}
static void F_452 ( struct V_8 * V_9 )
{
V_9 -> V_49 . V_769 &= 0x1ff ;
}
static int T_5 F_453 ( void )
{
return F_454 ( & V_770 , sizeof( struct V_7 ) ,
F_455 ( struct V_7 ) , V_771 ) ;
}
static void T_6 F_456 ( void )
{
F_457 () ;
}
