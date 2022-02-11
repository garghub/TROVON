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
static void F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
unsigned V_86 = V_9 -> V_46 . V_87 . V_86 ;
bool V_88 = V_9 -> V_46 . V_87 . V_88 ;
bool V_89 = V_9 -> V_46 . V_87 . V_89 ;
T_2 V_90 = V_9 -> V_46 . V_87 . V_90 ;
if ( ! V_89 &&
F_42 ( V_10 , V_86 , V_88 , V_90 ) )
return;
if ( V_86 == V_91 && ! F_36 ( V_79 ) ) {
unsigned long V_92 , V_93 = F_39 ( & V_10 -> V_9 ) ;
F_34 ( & V_10 -> V_9 ) ;
V_92 = F_39 ( & V_10 -> V_9 ) ;
V_10 -> V_94 = V_92 + V_10 -> V_1 -> V_65 . V_95 . V_96 ;
V_10 -> V_97 = V_92 - V_93 ;
}
V_10 -> V_1 -> V_2 . V_98 = V_86
| V_70
| ( V_88 ? V_99 : 0 )
| V_100 ;
V_10 -> V_1 -> V_2 . V_101 = V_90 ;
}
static void F_43 ( void )
{
T_2 V_102 , V_103 ;
int V_104 ;
T_1 V_105 ;
if ( ! F_44 ( V_106 ) )
return;
V_105 = F_45 ( V_107 , & V_104 ) ;
if ( V_104 )
return;
V_105 |= ( 1ULL << 47 ) ;
V_102 = F_46 ( V_105 ) ;
V_103 = F_47 ( V_105 ) ;
F_48 ( V_107 , V_102 , V_103 ) ;
V_108 = true ;
}
static void F_49 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_109 . V_110 = ( V_111 >= 3 ) ? ( V_111 ) : 3 ;
V_9 -> V_46 . V_109 . V_112 = V_113 & ~ ( 6ULL ) ;
if ( V_111 == 0 && V_114 . V_115 == 0x10 )
V_9 -> V_46 . V_109 . V_112 |= 1 ;
}
static int F_50 ( void )
{
const char * V_116 ;
if ( ! F_51 ( & V_116 ) ) {
F_38 ( V_117 L_3 , V_116 ) ;
return 0 ;
}
return 1 ;
}
static void F_52 ( void )
{
if ( F_36 ( V_118 ) )
F_53 ( V_119 , V_120 ) ;
F_54 () ;
F_55 () ;
}
static int F_56 ( void )
{
struct V_121 * V_122 ;
T_3 V_61 ;
struct V_123 * V_124 ;
int V_125 = F_57 () ;
F_58 ( V_126 , V_61 ) ;
if ( V_61 & V_66 )
return - V_127 ;
if ( ! F_50 () ) {
F_59 ( L_4 , V_83 , V_125 ) ;
return - V_128 ;
}
V_122 = F_60 ( V_129 , V_125 ) ;
if ( ! V_122 ) {
F_59 ( L_5 , V_83 , V_125 ) ;
return - V_128 ;
}
V_122 -> V_130 = 1 ;
V_122 -> V_131 = F_61 ( V_132 ) - 1 ;
V_122 -> V_133 = V_122 -> V_131 + 1 ;
V_124 = F_62 () ;
V_122 -> V_134 = (struct V_135 * ) ( V_124 + V_136 ) ;
F_53 ( V_126 , V_61 | V_66 ) ;
F_53 ( V_137 , F_63 ( V_122 -> V_138 ) << V_139 ) ;
if ( F_36 ( V_118 ) ) {
F_53 ( V_119 , V_120 ) ;
F_64 ( V_140 , V_120 ) ;
}
if ( F_65 ( & V_114 , V_141 ) ) {
T_3 V_142 , V_112 = 0 ;
int V_104 ;
V_142 = F_45 ( V_143 , & V_104 ) ;
if ( ! V_104 )
V_112 = F_45 ( V_144 ,
& V_104 ) ;
if ( V_104 )
V_113 = V_111 = 0 ;
else {
if ( V_142 < V_111 )
V_111 = V_142 ;
V_113 |= V_112 ;
V_113 &= ( 1ULL << V_111 ) - 1 ;
}
} else
V_113 = V_111 = 0 ;
F_43 () ;
F_66 () ;
return 0 ;
}
static void F_67 ( int V_145 )
{
struct V_121 * V_122 = F_60 ( V_129 , F_57 () ) ;
if ( ! V_122 )
return;
F_60 ( V_129 , F_57 () ) = NULL ;
F_68 ( V_122 -> V_138 ) ;
F_69 ( V_122 ) ;
}
static int F_70 ( int V_145 )
{
struct V_121 * V_122 ;
int V_146 ;
V_122 = F_71 ( sizeof( struct V_121 ) , V_147 ) ;
if ( ! V_122 )
return - V_148 ;
V_122 -> V_145 = V_145 ;
V_122 -> V_138 = F_72 ( V_147 ) ;
V_146 = - V_148 ;
if ( ! V_122 -> V_138 )
goto V_149;
F_60 ( V_129 , V_145 ) = V_122 ;
return 0 ;
V_149:
F_69 ( V_122 ) ;
return V_146 ;
}
static bool F_73 ( T_2 V_150 )
{
int V_51 ;
for ( V_51 = 0 ; V_151 [ V_51 ] . V_150 != V_56 ; V_51 ++ )
if ( V_151 [ V_51 ] . V_150 == V_150 )
return true ;
return false ;
}
static void F_74 ( T_2 * V_152 , unsigned V_49 ,
int V_153 , int V_154 )
{
T_4 V_155 , V_156 ;
unsigned long V_157 ;
T_2 V_50 ;
F_75 ( ! F_73 ( V_49 ) ) ;
V_50 = F_24 ( V_49 ) ;
V_155 = 2 * ( V_49 & 0x0f ) ;
V_156 = 2 * ( V_49 & 0x0f ) + 1 ;
V_157 = V_152 [ V_50 ] ;
F_76 ( V_50 == V_56 ) ;
V_153 ? F_77 ( V_155 , & V_157 ) : F_78 ( V_155 , & V_157 ) ;
V_154 ? F_77 ( V_156 , & V_157 ) : F_78 ( V_156 , & V_157 ) ;
V_152 [ V_50 ] = V_157 ;
}
static void F_79 ( T_2 * V_152 )
{
int V_51 ;
memset ( V_152 , 0xff , V_158 * ( 1 << V_159 ) ) ;
for ( V_51 = 0 ; V_151 [ V_51 ] . V_150 != V_56 ; V_51 ++ ) {
if ( ! V_151 [ V_51 ] . V_160 )
continue;
F_74 ( V_152 , V_151 [ V_51 ] . V_150 , 1 , 1 ) ;
}
}
static void F_80 ( T_2 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_161 ; ++ V_51 ) {
if ( V_162 [ V_51 ] == V_50 )
return;
if ( V_162 [ V_51 ] != V_56 )
continue;
V_162 [ V_51 ] = V_50 ;
return;
}
F_81 () ;
}
static void F_82 ( void )
{
int V_51 ;
memset ( V_162 , 0xff , sizeof( V_162 ) ) ;
for ( V_51 = 0 ; V_151 [ V_51 ] . V_150 != V_56 ; V_51 ++ ) {
T_2 V_50 ;
V_50 = F_24 ( V_151 [ V_51 ] . V_150 ) ;
F_76 ( V_50 == V_56 ) ;
F_80 ( V_50 ) ;
}
}
static void F_83 ( struct V_7 * V_10 )
{
T_2 * V_152 = V_10 -> V_152 ;
V_10 -> V_1 -> V_2 . V_163 |= V_164 ;
F_74 ( V_152 , V_165 , 1 , 1 ) ;
F_74 ( V_152 , V_166 , 1 , 1 ) ;
F_74 ( V_152 , V_167 , 1 , 1 ) ;
F_74 ( V_152 , V_168 , 1 , 1 ) ;
}
static void F_84 ( struct V_7 * V_10 )
{
T_2 * V_152 = V_10 -> V_152 ;
V_10 -> V_1 -> V_2 . V_163 &= ~ V_164 ;
F_74 ( V_152 , V_165 , 0 , 0 ) ;
F_74 ( V_152 , V_166 , 0 , 0 ) ;
F_74 ( V_152 , V_167 , 0 , 0 ) ;
F_74 ( V_152 , V_168 , 0 , 0 ) ;
}
static void F_85 ( struct V_7 * V_10 )
{
V_10 -> V_169 = false ;
if ( ! ( V_10 -> V_9 . V_170 & V_171 ) ) {
if ( ! ( V_10 -> V_172 & V_173 ) )
V_10 -> V_1 -> V_65 . V_174 &= ~ V_173 ;
if ( ! ( V_10 -> V_172 & V_175 ) )
V_10 -> V_1 -> V_65 . V_174 &= ~ V_175 ;
}
}
static int F_86 ( T_2 V_176 )
{
unsigned long V_177 ;
struct V_178 * V_179 = NULL ;
struct V_8 * V_9 = NULL ;
T_2 V_180 = F_87 ( V_176 ) ;
T_2 V_181 = F_88 ( V_176 ) ;
F_89 ( L_6 , V_83 , V_180 , V_181 ) ;
F_90 ( & V_182 , V_177 ) ;
F_91 (svm_vm_data_hash, ka, hnode, vm_id) {
struct V_183 * V_183 = F_5 ( V_179 , struct V_183 , V_46 ) ;
struct V_178 * V_184 = & V_183 -> V_46 ;
if ( V_184 -> V_185 != V_180 )
continue;
V_9 = F_92 ( V_183 , V_181 ) ;
break;
}
F_93 ( & V_182 , V_177 ) ;
if ( ! V_9 )
return 0 ;
if ( V_9 -> V_186 == V_187 )
F_94 ( V_9 ) ;
return 0 ;
}
static T_5 int F_95 ( void )
{
int V_145 ;
struct V_188 * V_189 ;
void * V_190 ;
int V_146 ;
V_189 = F_96 ( V_147 , V_191 ) ;
if ( ! V_189 )
return - V_148 ;
V_190 = F_97 ( V_189 ) ;
memset ( V_190 , 0xff , V_158 * ( 1 << V_191 ) ) ;
V_192 = F_63 ( V_189 ) << V_139 ;
F_82 () ;
if ( F_98 ( V_193 ) )
F_99 ( V_194 ) ;
if ( F_98 ( V_195 ) )
F_99 ( V_196 ) ;
if ( F_98 ( V_118 ) ) {
V_197 = true ;
V_198 = V_199 ;
V_200 = 32 ;
}
if ( V_24 ) {
F_38 ( V_117 L_7 ) ;
F_99 ( V_66 | V_201 ) ;
}
F_100 (cpu) {
V_146 = F_70 ( V_145 ) ;
if ( V_146 )
goto V_104;
}
if ( ! F_98 ( V_202 ) )
V_62 = false ;
if ( V_62 && ! V_203 ) {
F_38 ( V_117 L_8 ) ;
V_62 = false ;
}
if ( V_62 ) {
F_38 ( V_117 L_9 ) ;
F_101 () ;
} else
F_102 () ;
if ( V_204 ) {
if ( ! V_62 ||
! F_98 ( V_205 ) ||
! F_103 ( V_206 ) ) {
V_204 = false ;
} else {
F_104 ( L_10 ) ;
F_105 ( & F_86 ) ;
}
}
if ( V_207 ) {
if ( ! V_62 ||
! F_98 ( V_208 ) ||
! F_103 ( F_29 ) ) {
V_207 = false ;
} else {
F_104 ( L_11 ) ;
}
}
return 0 ;
V_104:
F_106 ( V_189 , V_191 ) ;
V_192 = 0 ;
return V_146 ;
}
static T_6 void F_107 ( void )
{
int V_145 ;
F_100 (cpu)
F_67 ( V_145 ) ;
F_106 ( F_108 ( V_192 >> V_139 ) , V_191 ) ;
V_192 = 0 ;
}
static void F_109 ( struct V_209 * V_210 )
{
V_210 -> V_211 = 0 ;
V_210 -> V_212 = V_213 | V_214 |
V_215 ;
V_210 -> V_216 = 0xffff ;
V_210 -> V_96 = 0 ;
}
static void F_110 ( struct V_209 * V_210 , T_7 type )
{
V_210 -> V_211 = 0 ;
V_210 -> V_212 = V_213 | type ;
V_210 -> V_216 = 0xffff ;
V_210 -> V_96 = 0 ;
}
static void F_111 ( struct V_8 * V_9 , T_1 V_50 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_217 = 0 ;
if ( F_10 ( V_9 ) ) {
V_217 = V_10 -> V_1 -> V_2 . V_218 -
V_10 -> V_24 . V_25 -> V_2 . V_218 ;
V_10 -> V_24 . V_25 -> V_2 . V_218 = V_50 ;
} else
F_112 ( V_9 -> V_181 ,
V_10 -> V_1 -> V_2 . V_218 ,
V_50 ) ;
V_10 -> V_1 -> V_2 . V_218 = V_50 + V_217 ;
F_3 ( V_10 -> V_1 , V_23 ) ;
}
static void F_113 ( struct V_7 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_178 * V_184 = & V_10 -> V_9 . V_183 -> V_46 ;
T_8 V_219 = F_114 ( V_10 -> V_220 ) ;
T_8 V_221 = F_114 ( V_184 -> V_222 ) ;
T_8 V_223 = F_114 ( V_184 -> V_224 ) ;
V_1 -> V_2 . V_220 = V_219 & V_225 ;
V_1 -> V_2 . V_226 = V_221 & V_225 ;
V_1 -> V_2 . V_227 = V_223 & V_225 ;
V_1 -> V_2 . V_227 |= V_228 ;
V_1 -> V_2 . V_229 |= V_230 ;
V_10 -> V_9 . V_46 . V_231 = true ;
}
static void F_115 ( struct V_7 * V_10 )
{
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_232 * V_65 = & V_10 -> V_1 -> V_65 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
F_12 ( V_10 , V_233 ) ;
F_12 ( V_10 , V_234 ) ;
F_12 ( V_10 , V_235 ) ;
F_12 ( V_10 , V_236 ) ;
F_12 ( V_10 , V_237 ) ;
F_12 ( V_10 , V_238 ) ;
if ( ! F_116 ( & V_10 -> V_9 ) )
F_12 ( V_10 , V_239 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_240 ) ;
F_17 ( V_10 , V_241 ) ;
F_17 ( V_10 , V_242 ) ;
F_17 ( V_10 , V_243 ) ;
F_17 ( V_10 , V_244 ) ;
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
F_19 ( V_10 , V_264 ) ;
F_19 ( V_10 , V_265 ) ;
F_19 ( V_10 , V_266 ) ;
F_19 ( V_10 , V_267 ) ;
if ( ! F_117 () ) {
F_19 ( V_10 , V_268 ) ;
F_19 ( V_10 , V_269 ) ;
}
V_2 -> V_270 = V_192 ;
V_2 -> V_271 = F_118 ( V_10 -> V_152 ) ;
V_2 -> V_229 = V_272 ;
F_109 ( & V_65 -> V_273 ) ;
F_109 ( & V_65 -> V_274 ) ;
F_109 ( & V_65 -> V_275 ) ;
F_109 ( & V_65 -> V_276 ) ;
F_109 ( & V_65 -> V_277 ) ;
V_65 -> V_95 . V_211 = 0xf000 ;
V_65 -> V_95 . V_96 = 0xffff0000 ;
V_65 -> V_95 . V_212 = V_278 | V_213 |
V_214 | V_279 ;
V_65 -> V_95 . V_216 = 0xffff ;
V_65 -> V_280 . V_216 = 0xffff ;
V_65 -> V_281 . V_216 = 0xffff ;
F_110 ( & V_65 -> V_282 , V_283 ) ;
F_110 ( & V_65 -> V_284 , V_285 ) ;
F_30 ( & V_10 -> V_9 , 0 ) ;
V_65 -> V_286 = 0xffff0ff0 ;
F_119 ( & V_10 -> V_9 , 2 ) ;
V_65 -> V_92 = 0x0000fff0 ;
V_10 -> V_9 . V_46 . V_287 [ V_288 ] = V_65 -> V_92 ;
F_120 ( & V_10 -> V_9 , V_289 | V_290 | V_291 ) ;
F_121 ( & V_10 -> V_9 ) ;
V_65 -> V_292 = V_293 ;
if ( V_62 ) {
V_2 -> V_294 = 1 ;
F_20 ( V_10 , V_253 ) ;
F_18 ( V_10 , V_240 ) ;
F_13 ( V_10 , V_234 ) ;
F_13 ( V_10 , V_237 ) ;
V_65 -> V_295 = V_10 -> V_9 . V_46 . V_296 ;
V_65 -> V_297 = 0 ;
V_65 -> V_292 = 0 ;
}
V_10 -> V_130 = 0 ;
V_10 -> V_24 . V_1 = 0 ;
V_10 -> V_9 . V_46 . V_47 = 0 ;
if ( F_98 ( V_298 ) ) {
V_2 -> V_299 = 3000 ;
F_19 ( V_10 , V_300 ) ;
}
if ( V_204 )
F_113 ( V_10 ) ;
if ( V_207 ) {
F_20 ( V_10 , V_261 ) ;
F_20 ( V_10 , V_262 ) ;
V_10 -> V_1 -> V_2 . V_163 |= V_301 ;
}
F_1 ( V_10 -> V_1 ) ;
F_21 ( V_10 ) ;
}
static T_1 * F_122 ( struct V_8 * V_9 ,
unsigned int V_150 )
{
T_1 * V_302 ;
struct V_178 * V_184 = & V_9 -> V_183 -> V_46 ;
if ( V_150 >= V_228 )
return NULL ;
V_302 = F_97 ( V_184 -> V_224 ) ;
return & V_302 [ V_150 ] ;
}
static int F_123 ( struct V_8 * V_9 )
{
struct V_183 * V_183 = V_9 -> V_183 ;
int V_72 ;
if ( V_183 -> V_46 . V_303 )
return 0 ;
V_72 = F_124 ( V_183 ,
V_304 ,
V_305 ,
V_158 ) ;
if ( V_72 )
return V_72 ;
V_183 -> V_46 . V_303 = true ;
return 0 ;
}
static int F_125 ( struct V_8 * V_9 )
{
int V_72 ;
T_1 * V_15 , V_306 ;
int V_307 = V_9 -> V_181 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_72 = F_123 ( V_9 ) ;
if ( V_72 )
return V_72 ;
if ( V_307 >= V_228 )
return - V_128 ;
if ( ! V_10 -> V_9 . V_46 . V_308 -> V_287 )
return - V_128 ;
V_10 -> V_220 = F_126 ( V_10 -> V_9 . V_46 . V_308 -> V_287 ) ;
V_15 = F_122 ( V_9 , V_307 ) ;
if ( ! V_15 )
return - V_128 ;
V_306 = F_8 ( * V_15 ) ;
V_306 = ( F_114 ( V_10 -> V_220 ) &
V_309 ) |
V_310 ;
F_127 ( * V_15 , V_306 ) ;
V_10 -> V_16 = V_15 ;
return 0 ;
}
static inline int F_128 ( void )
{
int V_307 ;
F_129 ( & V_311 ) ;
V_307 = F_130 ( V_312 , V_313 , 1 ) ;
if ( V_307 <= V_314 )
F_131 ( V_307 , V_312 ) ;
else
V_307 = - V_315 ;
F_132 ( & V_311 ) ;
return V_307 ;
}
static inline int F_133 ( int V_307 )
{
if ( V_307 <= 0 || V_307 > V_314 )
return - V_128 ;
F_129 ( & V_311 ) ;
F_134 ( V_307 , V_312 ) ;
F_132 ( & V_311 ) ;
return 0 ;
}
static void F_135 ( struct V_183 * V_183 )
{
unsigned long V_177 ;
struct V_178 * V_184 = & V_183 -> V_46 ;
if ( ! V_204 )
return;
F_133 ( V_184 -> V_185 ) ;
if ( V_184 -> V_222 )
F_68 ( V_184 -> V_222 ) ;
if ( V_184 -> V_224 )
F_68 ( V_184 -> V_224 ) ;
F_90 ( & V_182 , V_177 ) ;
F_136 ( & V_184 -> V_316 ) ;
F_93 ( & V_182 , V_177 ) ;
}
static int F_137 ( struct V_183 * V_183 )
{
unsigned long V_177 ;
int V_180 , V_104 = - V_148 ;
struct V_178 * V_184 = & V_183 -> V_46 ;
struct V_188 * V_317 ;
struct V_188 * V_318 ;
if ( ! V_204 )
return 0 ;
V_180 = F_128 () ;
if ( V_180 < 0 )
return V_180 ;
V_184 -> V_185 = ( T_2 ) V_180 ;
V_317 = F_72 ( V_147 ) ;
if ( ! V_317 )
goto V_319;
V_184 -> V_224 = V_317 ;
F_138 ( F_97 ( V_317 ) ) ;
V_318 = F_72 ( V_147 ) ;
if ( ! V_318 )
goto V_319;
V_184 -> V_222 = V_318 ;
F_138 ( F_97 ( V_318 ) ) ;
F_90 ( & V_182 , V_177 ) ;
F_139 ( V_320 , & V_184 -> V_316 , V_184 -> V_185 ) ;
F_93 ( & V_182 , V_177 ) ;
return 0 ;
V_319:
F_135 ( V_183 ) ;
return V_104 ;
}
static inline int
F_140 ( struct V_8 * V_9 , int V_145 , bool V_146 )
{
int V_72 = 0 ;
unsigned long V_177 ;
struct V_321 * V_322 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_141 ( V_9 -> V_183 ) )
return 0 ;
F_90 ( & V_10 -> V_323 , V_177 ) ;
if ( F_142 ( & V_10 -> V_324 ) )
goto V_325;
F_143 (ir, &svm->ir_list, node) {
V_72 = F_144 ( V_145 , V_146 , V_322 -> V_11 ) ;
if ( V_72 )
break;
}
V_325:
F_93 ( & V_10 -> V_323 , V_177 ) ;
return V_72 ;
}
static void F_145 ( struct V_8 * V_9 , int V_145 )
{
T_1 V_15 ;
int V_326 = F_146 ( V_145 ) ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_116 ( V_9 ) )
return;
if ( F_75 ( V_326 >= V_228 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
F_75 ( V_15 & V_17 ) ;
V_15 &= ~ V_327 ;
V_15 |= ( V_326 & V_327 ) ;
V_15 &= ~ V_17 ;
if ( V_10 -> V_328 )
V_15 |= V_17 ;
F_127 ( * ( V_10 -> V_16 ) , V_15 ) ;
F_140 ( V_9 , V_326 ,
V_10 -> V_328 ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
T_1 V_15 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! F_116 ( V_9 ) )
return;
V_15 = F_8 ( * ( V_10 -> V_16 ) ) ;
if ( V_15 & V_17 )
F_140 ( V_9 , - 1 , 0 ) ;
V_15 &= ~ V_17 ;
F_127 ( * ( V_10 -> V_16 ) , V_15 ) ;
}
static void F_148 ( struct V_8 * V_9 , bool V_329 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_328 = V_329 ;
if ( V_329 )
F_145 ( V_9 , V_9 -> V_145 ) ;
else
F_147 ( V_9 ) ;
}
static void F_149 ( struct V_8 * V_9 , bool V_330 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_331 ;
T_2 V_332 = 1 ;
if ( ! V_330 ) {
V_10 -> V_9 . V_46 . V_333 = V_305 |
V_334 ;
if ( F_150 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_46 . V_333 |= V_335 ;
}
F_115 ( V_10 ) ;
F_151 ( V_9 , & V_332 , & V_331 , & V_331 , & V_331 ) ;
F_152 ( V_9 , V_336 , V_332 ) ;
if ( F_116 ( V_9 ) && ! V_330 )
F_6 ( V_10 , V_305 ) ;
}
static struct V_8 * F_153 ( struct V_183 * V_183 , unsigned int V_307 )
{
struct V_7 * V_10 ;
struct V_188 * V_188 ;
struct V_188 * V_337 ;
struct V_188 * V_338 ;
struct V_188 * V_339 ;
int V_104 ;
V_10 = F_154 ( V_340 , V_147 ) ;
if ( ! V_10 ) {
V_104 = - V_148 ;
goto V_325;
}
V_104 = F_155 ( & V_10 -> V_9 , V_183 , V_307 ) ;
if ( V_104 )
goto V_341;
V_104 = - V_148 ;
V_188 = F_72 ( V_147 ) ;
if ( ! V_188 )
goto V_342;
V_337 = F_96 ( V_147 , V_159 ) ;
if ( ! V_337 )
goto V_343;
V_339 = F_96 ( V_147 , V_159 ) ;
if ( ! V_339 )
goto V_344;
V_338 = F_72 ( V_147 ) ;
if ( ! V_338 )
goto V_345;
if ( V_204 ) {
V_104 = F_125 ( & V_10 -> V_9 ) ;
if ( V_104 )
goto V_346;
F_156 ( & V_10 -> V_324 ) ;
F_157 ( & V_10 -> V_323 ) ;
}
V_10 -> V_328 = true ;
V_10 -> V_24 . V_25 = F_97 ( V_338 ) ;
V_10 -> V_152 = F_97 ( V_337 ) ;
F_79 ( V_10 -> V_152 ) ;
V_10 -> V_24 . V_152 = F_97 ( V_339 ) ;
F_79 ( V_10 -> V_24 . V_152 ) ;
V_10 -> V_1 = F_97 ( V_188 ) ;
F_138 ( V_10 -> V_1 ) ;
V_10 -> V_347 = F_63 ( V_188 ) << V_139 ;
V_10 -> V_130 = 0 ;
F_115 ( V_10 ) ;
F_49 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_346:
F_68 ( V_338 ) ;
V_345:
F_106 ( V_339 , V_159 ) ;
V_344:
F_106 ( V_337 , V_159 ) ;
V_343:
F_68 ( V_188 ) ;
V_342:
F_158 ( & V_10 -> V_9 ) ;
V_341:
F_159 ( V_340 , V_10 ) ;
V_325:
return F_160 ( V_104 ) ;
}
static void F_161 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_68 ( F_108 ( V_10 -> V_347 >> V_139 ) ) ;
F_106 ( F_126 ( V_10 -> V_152 ) , V_159 ) ;
F_68 ( F_126 ( V_10 -> V_24 . V_25 ) ) ;
F_106 ( F_126 ( V_10 -> V_24 . V_152 ) , V_159 ) ;
F_158 ( V_9 ) ;
F_159 ( V_340 , V_10 ) ;
}
static void F_162 ( struct V_8 * V_9 , int V_145 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
if ( F_163 ( V_145 != V_9 -> V_145 ) ) {
V_10 -> V_130 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_29
F_58 ( V_348 , F_4 ( V_9 ) -> V_349 . V_350 ) ;
#endif
F_164 ( V_276 , V_10 -> V_349 . V_276 ) ;
F_164 ( V_277 , V_10 -> V_349 . V_277 ) ;
V_10 -> V_349 . V_351 = F_165 () ;
for ( V_51 = 0 ; V_51 < V_352 ; V_51 ++ )
F_58 ( V_353 [ V_51 ] , V_10 -> V_354 [ V_51 ] ) ;
if ( F_36 ( V_118 ) ) {
T_1 V_355 = V_9 -> V_46 . V_356 ;
if ( V_355 != F_166 ( V_140 ) ) {
F_64 ( V_140 , V_355 ) ;
F_53 ( V_119 , V_355 ) ;
}
}
if ( F_36 ( V_357 ) )
F_53 ( V_358 , V_10 -> V_359 ) ;
F_145 ( V_9 , V_145 ) ;
}
static void F_167 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_51 ;
F_147 ( V_9 ) ;
++ V_9 -> V_360 . V_361 ;
F_168 ( V_10 -> V_349 . V_351 ) ;
#ifdef F_29
F_169 ( V_276 , V_10 -> V_349 . V_276 ) ;
F_53 ( V_362 , V_363 -> V_364 . V_365 ) ;
F_170 ( V_10 -> V_349 . V_277 ) ;
#else
#ifdef F_171
F_169 ( V_277 , V_10 -> V_349 . V_277 ) ;
#endif
#endif
for ( V_51 = 0 ; V_51 < V_352 ; V_51 ++ )
F_53 ( V_353 [ V_51 ] , V_10 -> V_354 [ V_51 ] ) ;
}
static void F_172 ( struct V_8 * V_9 )
{
F_148 ( V_9 , false ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_148 ( V_9 , true ) ;
}
static unsigned long F_174 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
unsigned long V_174 = V_10 -> V_1 -> V_65 . V_174 ;
if ( V_10 -> V_169 ) {
if ( ! ( V_10 -> V_172 & V_173 ) )
V_174 &= ~ V_173 ;
if ( ! ( V_10 -> V_172 & V_175 ) )
V_174 &= ~ V_175 ;
}
return V_174 ;
}
static void F_175 ( struct V_8 * V_9 , unsigned long V_174 )
{
if ( F_4 ( V_9 ) -> V_169 )
V_174 |= ( V_173 | V_175 ) ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_174 = V_174 ;
}
static void F_176 ( struct V_8 * V_9 , enum V_366 V_367 )
{
switch ( V_367 ) {
case V_368 :
F_76 ( ! V_62 ) ;
F_177 ( V_9 , V_9 -> V_46 . V_369 , F_178 ( V_9 ) ) ;
break;
default:
F_81 () ;
}
}
static void F_179 ( struct V_7 * V_10 )
{
F_19 ( V_10 , V_370 ) ;
}
static void F_180 ( struct V_7 * V_10 )
{
F_20 ( V_10 , V_370 ) ;
}
static struct V_209 * F_181 ( struct V_8 * V_9 , int V_210 )
{
struct V_232 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
switch ( V_210 ) {
case V_371 : return & V_65 -> V_95 ;
case V_372 : return & V_65 -> V_275 ;
case V_373 : return & V_65 -> V_273 ;
case V_374 : return & V_65 -> V_276 ;
case V_375 : return & V_65 -> V_277 ;
case V_376 : return & V_65 -> V_274 ;
case V_377 : return & V_65 -> V_284 ;
case V_378 : return & V_65 -> V_282 ;
}
F_81 () ;
return NULL ;
}
static T_1 F_182 ( struct V_8 * V_9 , int V_210 )
{
struct V_209 * V_379 = F_181 ( V_9 , V_210 ) ;
return V_379 -> V_96 ;
}
static void F_183 ( struct V_8 * V_9 ,
struct V_380 * V_381 , int V_210 )
{
struct V_209 * V_379 = F_181 ( V_9 , V_210 ) ;
V_381 -> V_96 = V_379 -> V_96 ;
V_381 -> V_216 = V_379 -> V_216 ;
V_381 -> V_211 = V_379 -> V_211 ;
V_381 -> type = V_379 -> V_212 & V_382 ;
V_381 -> V_379 = ( V_379 -> V_212 >> V_383 ) & 1 ;
V_381 -> V_384 = ( V_379 -> V_212 >> V_385 ) & 3 ;
V_381 -> V_386 = ( V_379 -> V_212 >> V_387 ) & 1 ;
V_381 -> V_388 = ( V_379 -> V_212 >> V_389 ) & 1 ;
V_381 -> V_390 = ( V_379 -> V_212 >> V_391 ) & 1 ;
V_381 -> V_392 = ( V_379 -> V_212 >> V_393 ) & 1 ;
V_381 -> V_22 = V_379 -> V_216 > 0xfffff ;
V_381 -> V_394 = ! V_381 -> V_386 ;
switch ( V_210 ) {
case V_377 :
V_381 -> type |= 0x2 ;
break;
case V_372 :
case V_373 :
case V_374 :
case V_375 :
if ( ! V_381 -> V_394 )
V_381 -> type |= 0x1 ;
break;
case V_376 :
if ( V_381 -> V_394 )
V_381 -> V_392 = 0 ;
V_381 -> V_384 = F_4 ( V_9 ) -> V_1 -> V_65 . V_395 ;
break;
}
}
static int F_184 ( struct V_8 * V_9 )
{
struct V_232 * V_65 = & F_4 ( V_9 ) -> V_1 -> V_65 ;
return V_65 -> V_395 ;
}
static void F_185 ( struct V_8 * V_9 , struct V_396 * V_397 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_397 -> V_398 = V_10 -> V_1 -> V_65 . V_281 . V_216 ;
V_397 -> V_399 = V_10 -> V_1 -> V_65 . V_281 . V_96 ;
}
static void F_186 ( struct V_8 * V_9 , struct V_396 * V_397 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_281 . V_216 = V_397 -> V_398 ;
V_10 -> V_1 -> V_65 . V_281 . V_96 = V_397 -> V_399 ;
F_3 ( V_10 -> V_1 , V_400 ) ;
}
static void F_187 ( struct V_8 * V_9 , struct V_396 * V_397 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_397 -> V_398 = V_10 -> V_1 -> V_65 . V_280 . V_216 ;
V_397 -> V_399 = V_10 -> V_1 -> V_65 . V_280 . V_96 ;
}
static void F_188 ( struct V_8 * V_9 , struct V_396 * V_397 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_280 . V_216 = V_397 -> V_398 ;
V_10 -> V_1 -> V_65 . V_280 . V_96 = V_397 -> V_399 ;
F_3 ( V_10 -> V_1 , V_400 ) ;
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
T_9 V_401 = V_10 -> V_9 . V_46 . V_402 ;
T_1 * V_403 = & V_10 -> V_1 -> V_65 . V_402 ;
* V_403 = ( * V_403 & ~ V_404 )
| ( V_401 & V_404 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
if ( V_401 == * V_403 ) {
F_13 ( V_10 , V_233 ) ;
F_13 ( V_10 , V_236 ) ;
} else {
F_12 ( V_10 , V_233 ) ;
F_12 ( V_10 , V_236 ) ;
}
}
static void F_120 ( struct V_8 * V_9 , unsigned long V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_29
if ( V_9 -> V_46 . V_61 & V_64 ) {
if ( ! F_193 ( V_9 ) && ( V_402 & V_405 ) ) {
V_9 -> V_46 . V_61 |= V_63 ;
V_10 -> V_1 -> V_65 . V_61 |= V_63 | V_64 ;
}
if ( F_193 ( V_9 ) && ! ( V_402 & V_405 ) ) {
V_9 -> V_46 . V_61 &= ~ V_63 ;
V_10 -> V_1 -> V_65 . V_61 &= ~ ( V_63 | V_64 ) ;
}
}
#endif
V_9 -> V_46 . V_402 = V_402 ;
if ( ! V_62 )
V_402 |= V_405 | V_406 ;
if ( F_194 ( V_9 -> V_183 , V_407 ) )
V_402 &= ~ ( V_290 | V_289 ) ;
V_10 -> V_1 -> V_65 . V_402 = V_402 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_192 ( V_10 ) ;
}
static int F_195 ( struct V_8 * V_9 , unsigned long V_292 )
{
unsigned long V_408 = F_196 () & V_409 ;
unsigned long V_410 = F_4 ( V_9 ) -> V_1 -> V_65 . V_292 ;
if ( V_292 & V_411 )
return 1 ;
if ( V_62 && ( ( V_410 ^ V_292 ) & V_412 ) )
F_197 ( V_9 ) ;
V_9 -> V_46 . V_292 = V_292 ;
if ( ! V_62 )
V_292 |= V_293 ;
V_292 |= V_408 ;
F_4 ( V_9 ) -> V_1 -> V_65 . V_292 = V_292 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_67 ) ;
return 0 ;
}
static void F_198 ( struct V_8 * V_9 ,
struct V_380 * V_381 , int V_210 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_209 * V_379 = F_181 ( V_9 , V_210 ) ;
V_379 -> V_96 = V_381 -> V_96 ;
V_379 -> V_216 = V_381 -> V_216 ;
V_379 -> V_211 = V_381 -> V_211 ;
V_379 -> V_212 = ( V_381 -> type & V_382 ) ;
V_379 -> V_212 |= ( V_381 -> V_379 & 1 ) << V_383 ;
V_379 -> V_212 |= ( V_381 -> V_384 & 3 ) << V_385 ;
V_379 -> V_212 |= ( ( V_381 -> V_386 & 1 ) && ! V_381 -> V_394 ) << V_387 ;
V_379 -> V_212 |= ( V_381 -> V_388 & 1 ) << V_389 ;
V_379 -> V_212 |= ( V_381 -> V_390 & 1 ) << V_391 ;
V_379 -> V_212 |= ( V_381 -> V_392 & 1 ) << V_393 ;
V_379 -> V_212 |= ( V_381 -> V_22 & 1 ) << V_413 ;
if ( V_210 == V_376 )
V_10 -> V_1 -> V_65 . V_395 = ( V_381 -> V_384 & 3 ) ;
F_3 ( V_10 -> V_1 , V_414 ) ;
}
static void F_199 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_18 ( V_10 , V_91 ) ;
if ( V_9 -> V_170 & V_415 ) {
if ( V_9 -> V_170 & V_416 )
F_17 ( V_10 , V_91 ) ;
} else
V_9 -> V_170 = 0 ;
}
static void F_200 ( struct V_7 * V_10 , struct V_121 * V_122 )
{
if ( V_122 -> V_133 > V_122 -> V_131 ) {
++ V_122 -> V_130 ;
V_122 -> V_133 = 1 ;
V_10 -> V_1 -> V_2 . V_417 = V_418 ;
}
V_10 -> V_130 = V_122 -> V_130 ;
V_10 -> V_1 -> V_2 . V_58 = V_122 -> V_133 ++ ;
F_3 ( V_10 -> V_1 , V_419 ) ;
}
static T_1 F_201 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_65 . V_286 ;
}
static void F_202 ( struct V_8 * V_9 , unsigned long V_420 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_286 = V_420 ;
F_3 ( V_10 -> V_1 , V_421 ) ;
}
static void F_203 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_204 ( V_9 -> V_46 . V_392 [ 0 ] , 0 ) ;
F_204 ( V_9 -> V_46 . V_392 [ 1 ] , 1 ) ;
F_204 ( V_9 -> V_46 . V_392 [ 2 ] , 2 ) ;
F_204 ( V_9 -> V_46 . V_392 [ 3 ] , 3 ) ;
V_9 -> V_46 . V_286 = F_201 ( V_9 ) ;
V_9 -> V_46 . V_422 = V_10 -> V_1 -> V_65 . V_422 ;
V_9 -> V_46 . V_423 &= ~ V_424 ;
F_15 ( V_10 ) ;
}
static void F_205 ( struct V_8 * V_9 , unsigned long V_420 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_422 = V_420 ;
F_3 ( V_10 -> V_1 , V_421 ) ;
}
static int F_206 ( struct V_7 * V_10 )
{
T_1 V_425 = V_10 -> V_1 -> V_2 . V_426 ;
T_1 V_90 = V_10 -> V_1 -> V_2 . V_427 ;
return F_207 ( & V_10 -> V_9 , V_90 , V_425 ,
V_10 -> V_1 -> V_2 . V_428 ,
V_10 -> V_1 -> V_2 . V_429 , ! V_62 ) ;
}
static int F_208 ( struct V_7 * V_10 )
{
struct V_430 * V_430 = V_10 -> V_9 . V_431 ;
if ( ! ( V_10 -> V_9 . V_170 &
( V_171 | V_432 ) ) &&
! V_10 -> V_169 ) {
F_209 ( & V_10 -> V_9 , V_244 ) ;
return 1 ;
}
if ( V_10 -> V_169 ) {
F_85 ( V_10 ) ;
}
if ( V_10 -> V_9 . V_170 &
( V_171 | V_432 ) ) {
V_430 -> V_433 = V_434 ;
V_430 -> V_435 . V_46 . V_436 =
V_10 -> V_1 -> V_65 . V_95 . V_96 + V_10 -> V_1 -> V_65 . V_92 ;
V_430 -> V_435 . V_46 . V_87 = V_244 ;
return 0 ;
}
return 1 ;
}
static int F_210 ( struct V_7 * V_10 )
{
struct V_430 * V_430 = V_10 -> V_9 . V_431 ;
V_430 -> V_433 = V_434 ;
V_430 -> V_435 . V_46 . V_436 = V_10 -> V_1 -> V_65 . V_95 . V_96 + V_10 -> V_1 -> V_65 . V_92 ;
V_430 -> V_435 . V_46 . V_87 = V_91 ;
return 0 ;
}
static int F_211 ( struct V_7 * V_10 )
{
int V_437 ;
V_437 = F_37 ( & V_10 -> V_9 , V_438 ) ;
if ( V_437 != V_81 )
F_209 ( & V_10 -> V_9 , V_241 ) ;
return 1 ;
}
static int F_212 ( struct V_7 * V_10 )
{
F_213 ( & V_10 -> V_9 , V_243 , 0 ) ;
return 1 ;
}
static bool F_214 ( void )
{
int V_104 , V_51 ;
T_1 V_420 ;
if ( ! V_108 )
return false ;
V_420 = F_45 ( V_439 , & V_104 ) ;
if ( V_104 )
return false ;
V_420 &= ~ ( 1ULL << 62 ) ;
if ( V_420 != 0xb600000000010015ULL )
return false ;
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 )
F_48 ( F_215 ( V_51 ) , 0 , 0 ) ;
V_420 = F_45 ( V_440 , & V_104 ) ;
if ( ! V_104 ) {
T_2 V_102 , V_103 ;
V_420 &= ~ ( 1ULL << 2 ) ;
V_102 = F_46 ( V_420 ) ;
V_103 = F_47 ( V_420 ) ;
F_48 ( V_440 , V_102 , V_103 ) ;
}
F_216 () ;
return true ;
}
static void F_217 ( struct V_7 * V_10 )
{
if ( F_214 () ) {
F_59 ( L_12 ) ;
F_218 ( V_441 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_219 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_220 ( struct V_7 * V_10 )
{
struct V_430 * V_430 = V_10 -> V_9 . V_431 ;
F_138 ( V_10 -> V_1 ) ;
F_115 ( V_10 ) ;
V_430 -> V_433 = V_442 ;
return 0 ;
}
static int F_221 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_2 V_443 = V_10 -> V_1 -> V_2 . V_427 ;
int V_398 , V_444 , string , V_72 ;
unsigned V_445 ;
++ V_10 -> V_9 . V_360 . V_446 ;
string = ( V_443 & V_447 ) != 0 ;
V_444 = ( V_443 & V_448 ) != 0 ;
if ( string )
return F_37 ( V_9 , 0 ) == V_81 ;
V_445 = V_443 >> 16 ;
V_398 = ( V_443 & V_449 ) >> V_450 ;
V_10 -> V_78 = V_10 -> V_1 -> V_2 . V_426 ;
V_72 = F_222 ( & V_10 -> V_9 ) ;
if ( V_444 )
return F_223 ( V_9 , V_398 , V_445 ) && V_72 ;
else
return F_224 ( V_9 , V_398 , V_445 ) && V_72 ;
}
static int F_225 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_226 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_360 . V_451 ;
return 1 ;
}
static int F_227 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_228 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 1 ;
return F_229 ( & V_10 -> V_9 ) ;
}
static int F_230 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_231 ( & V_10 -> V_9 ) ;
}
static unsigned long F_232 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_24 . V_452 ;
}
static T_1 F_233 ( struct V_8 * V_9 , int V_150 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_297 = V_10 -> V_24 . V_452 ;
T_1 V_453 ;
int V_72 ;
V_72 = F_234 ( V_9 , F_235 ( V_297 ) , & V_453 ,
F_236 ( V_297 ) + V_150 * 8 , 8 ) ;
if ( V_72 )
return 0 ;
return V_453 ;
}
static void F_237 ( struct V_8 * V_9 ,
unsigned long V_454 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_452 = V_454 ;
F_3 ( V_10 -> V_1 , V_455 ) ;
F_197 ( V_9 ) ;
}
static void F_238 ( struct V_8 * V_9 ,
struct V_456 * V_457 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_458 != V_459 ) {
V_10 -> V_1 -> V_2 . V_458 = V_459 ;
V_10 -> V_1 -> V_2 . V_460 = 0 ;
V_10 -> V_1 -> V_2 . V_427 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_426 = V_457 -> V_399 ;
}
V_10 -> V_1 -> V_2 . V_427 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_427 |= V_457 -> V_90 ;
if ( V_10 -> V_1 -> V_2 . V_427 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_427 &= ~ 1 ;
F_239 ( V_10 ) ;
}
static void F_240 ( struct V_8 * V_9 )
{
F_75 ( F_241 ( V_9 ) ) ;
F_242 ( V_9 ) ;
V_9 -> V_46 . V_461 . V_462 = F_237 ;
V_9 -> V_46 . V_461 . V_463 = F_232 ;
V_9 -> V_46 . V_461 . V_464 = F_233 ;
V_9 -> V_46 . V_461 . V_465 = F_238 ;
V_9 -> V_46 . V_461 . V_466 = F_28 () ;
F_243 ( V_9 , & V_9 -> V_46 . V_461 ) ;
V_9 -> V_46 . V_369 = & V_9 -> V_46 . V_467 ;
}
static void F_244 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_369 = & V_9 -> V_46 . V_461 ;
}
static int F_245 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_46 . V_61 & V_66 ) ||
! F_193 ( & V_10 -> V_9 ) ) {
F_209 ( & V_10 -> V_9 , V_241 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_65 . V_395 ) {
F_246 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_10 , unsigned V_86 ,
bool V_88 , T_2 V_90 )
{
int V_468 ;
if ( ! F_10 ( & V_10 -> V_9 ) )
return 0 ;
V_468 = F_247 ( V_10 ) ;
if ( V_468 != V_469 )
return 0 ;
V_10 -> V_1 -> V_2 . V_458 = V_470 + V_86 ;
V_10 -> V_1 -> V_2 . V_460 = 0 ;
V_10 -> V_1 -> V_2 . V_427 = V_90 ;
if ( V_10 -> V_9 . V_46 . V_87 . V_471 )
V_10 -> V_1 -> V_2 . V_426 = V_10 -> V_9 . V_46 . V_472 . V_473 ;
else
V_10 -> V_1 -> V_2 . V_426 = V_10 -> V_9 . V_46 . V_474 ;
V_10 -> V_24 . V_475 = true ;
return V_468 ;
}
static inline bool F_248 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_476 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_477 ) )
return false ;
if ( V_10 -> V_24 . V_475 )
return false ;
V_10 -> V_1 -> V_2 . V_458 = V_478 ;
V_10 -> V_1 -> V_2 . V_427 = 0 ;
V_10 -> V_1 -> V_2 . V_426 = 0 ;
if ( V_10 -> V_24 . V_29 & 1ULL ) {
V_10 -> V_24 . V_475 = true ;
F_249 ( V_10 -> V_1 -> V_65 . V_92 ) ;
return false ;
}
return true ;
}
static inline bool F_250 ( struct V_7 * V_10 )
{
if ( ! F_10 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_246 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_458 = V_479 ;
V_10 -> V_24 . V_475 = true ;
return false ;
}
static void * F_251 ( struct V_7 * V_10 , T_1 V_480 , struct V_188 * * V_481 )
{
struct V_188 * V_188 ;
F_252 () ;
V_188 = F_253 ( & V_10 -> V_9 , V_480 >> V_139 ) ;
if ( F_254 ( V_188 ) )
goto error;
* V_481 = V_188 ;
return F_255 ( V_188 ) ;
error:
F_246 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_256 ( struct V_188 * V_188 )
{
F_257 ( V_188 ) ;
F_258 ( V_188 ) ;
}
static int F_259 ( struct V_7 * V_10 )
{
unsigned V_445 , V_398 , V_482 ;
T_10 V_105 , V_77 ;
T_4 V_483 ;
T_1 V_480 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_255 ) ) )
return V_484 ;
V_445 = V_10 -> V_1 -> V_2 . V_427 >> 16 ;
V_398 = ( V_10 -> V_1 -> V_2 . V_427 & V_449 ) >>
V_450 ;
V_480 = V_10 -> V_24 . V_485 + ( V_445 / 8 ) ;
V_483 = V_445 % 8 ;
V_482 = ( V_483 + V_398 > 8 ) ? 2 : 1 ;
V_77 = ( 0xf >> ( 4 - V_398 ) ) << V_483 ;
V_105 = 0 ;
if ( F_260 ( & V_10 -> V_9 , V_480 , & V_105 , V_482 ) )
return V_469 ;
return ( V_105 & V_77 ) ? V_469 : V_484 ;
}
static int F_261 ( struct V_7 * V_10 )
{
T_2 V_50 , V_49 , V_420 ;
int V_154 , V_77 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_256 ) ) )
return V_484 ;
V_49 = V_10 -> V_9 . V_46 . V_287 [ V_486 ] ;
V_50 = F_24 ( V_49 ) ;
V_154 = V_10 -> V_1 -> V_2 . V_427 & 1 ;
V_77 = 1 << ( ( 2 * ( V_49 & 0xf ) ) + V_154 ) ;
if ( V_50 == V_56 )
return V_469 ;
V_50 *= 4 ;
if ( F_260 ( & V_10 -> V_9 , V_10 -> V_24 . V_487 + V_50 , & V_420 , 4 ) )
return V_469 ;
return ( V_420 & V_77 ) ? V_469 : V_484 ;
}
static int F_262 ( struct V_7 * V_10 )
{
unsigned long V_286 ;
if ( ! V_10 -> V_169 )
return V_469 ;
if ( F_263 ( & V_10 -> V_9 , 6 , & V_286 ) )
return V_469 ;
if ( ! ( V_286 & V_488 ) )
return V_469 ;
if ( V_10 -> V_172 & V_173 ) {
F_85 ( V_10 ) ;
return V_469 ;
}
return V_484 ;
}
static int F_264 ( struct V_7 * V_10 )
{
T_2 V_458 = V_10 -> V_1 -> V_2 . V_458 ;
switch ( V_458 ) {
case V_478 :
case V_479 :
case V_470 + V_242 :
return V_484 ;
case V_459 :
if ( V_62 )
return V_484 ;
break;
case V_470 + V_240 :
if ( ! V_62 && V_10 -> V_9 . V_46 . V_472 . V_489 == 0 )
return V_484 ;
break;
default:
break;
}
return V_490 ;
}
static int F_247 ( struct V_7 * V_10 )
{
T_2 V_458 = V_10 -> V_1 -> V_2 . V_458 ;
int V_468 = V_484 ;
switch ( V_458 ) {
case V_491 :
V_468 = F_261 ( V_10 ) ;
break;
case V_492 :
V_468 = F_259 ( V_10 ) ;
break;
case V_493 ... V_494 : {
T_2 V_6 = 1U << ( V_458 - V_493 ) ;
if ( V_10 -> V_24 . V_26 & V_6 )
V_468 = V_469 ;
break;
}
case V_495 ... V_496 : {
T_2 V_6 = 1U << ( V_458 - V_495 ) ;
if ( V_10 -> V_24 . V_27 & V_6 )
V_468 = V_469 ;
break;
}
case V_470 ... V_470 + 0x1f : {
T_2 V_497 = 1 << ( V_458 - V_470 ) ;
if ( V_10 -> V_24 . V_28 & V_497 ) {
if ( V_458 == V_470 + V_244 )
V_468 = F_262 ( V_10 ) ;
else
V_468 = V_469 ;
}
else if ( ( V_458 == V_470 + V_240 ) &&
V_10 -> V_9 . V_46 . V_87 . V_471 != 0 )
V_468 = V_469 ;
break;
}
case V_498 : {
V_468 = V_469 ;
break;
}
default: {
T_1 V_499 = 1ULL << ( V_458 - V_478 ) ;
if ( V_10 -> V_24 . V_29 & V_499 )
V_468 = V_469 ;
}
}
return V_468 ;
}
static int F_265 ( struct V_7 * V_10 )
{
int V_468 ;
V_468 = F_247 ( V_10 ) ;
if ( V_468 == V_469 )
F_239 ( V_10 ) ;
return V_468 ;
}
static inline void F_266 ( struct V_1 * V_500 , struct V_1 * V_501 )
{
struct V_18 * V_502 = & V_500 -> V_2 ;
struct V_18 * V_503 = & V_501 -> V_2 ;
V_502 -> V_26 = V_503 -> V_26 ;
V_502 -> V_27 = V_503 -> V_27 ;
V_502 -> V_28 = V_503 -> V_28 ;
V_502 -> V_29 = V_503 -> V_29 ;
V_502 -> V_270 = V_503 -> V_270 ;
V_502 -> V_271 = V_503 -> V_271 ;
V_502 -> V_218 = V_503 -> V_218 ;
V_502 -> V_58 = V_503 -> V_58 ;
V_502 -> V_417 = V_503 -> V_417 ;
V_502 -> V_229 = V_503 -> V_229 ;
V_502 -> V_504 = V_503 -> V_504 ;
V_502 -> V_73 = V_503 -> V_73 ;
V_502 -> V_458 = V_503 -> V_458 ;
V_502 -> V_460 = V_503 -> V_460 ;
V_502 -> V_427 = V_503 -> V_427 ;
V_502 -> V_426 = V_503 -> V_426 ;
V_502 -> V_505 = V_503 -> V_505 ;
V_502 -> V_506 = V_503 -> V_506 ;
V_502 -> V_294 = V_503 -> V_294 ;
V_502 -> V_98 = V_503 -> V_98 ;
V_502 -> V_101 = V_503 -> V_101 ;
V_502 -> V_452 = V_503 -> V_452 ;
V_502 -> V_163 = V_503 -> V_163 ;
}
static int F_239 ( struct V_7 * V_10 )
{
struct V_1 * V_507 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_188 * V_188 ;
F_267 ( V_1 -> V_2 . V_458 ,
V_1 -> V_2 . V_427 ,
V_1 -> V_2 . V_426 ,
V_1 -> V_2 . V_505 ,
V_1 -> V_2 . V_506 ,
V_508 ) ;
V_507 = F_251 ( V_10 , V_10 -> V_24 . V_1 , & V_188 ) ;
if ( ! V_507 )
return 1 ;
F_268 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_1 = 0 ;
F_22 ( V_10 ) ;
V_507 -> V_65 . V_273 = V_1 -> V_65 . V_273 ;
V_507 -> V_65 . V_95 = V_1 -> V_65 . V_95 ;
V_507 -> V_65 . V_274 = V_1 -> V_65 . V_274 ;
V_507 -> V_65 . V_275 = V_1 -> V_65 . V_275 ;
V_507 -> V_65 . V_280 = V_1 -> V_65 . V_280 ;
V_507 -> V_65 . V_281 = V_1 -> V_65 . V_281 ;
V_507 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_507 -> V_65 . V_402 = F_269 ( & V_10 -> V_9 ) ;
V_507 -> V_65 . V_297 = F_178 ( & V_10 -> V_9 ) ;
V_507 -> V_65 . V_474 = V_1 -> V_65 . V_474 ;
V_507 -> V_65 . V_292 = V_10 -> V_9 . V_46 . V_292 ;
V_507 -> V_65 . V_174 = F_270 ( & V_10 -> V_9 ) ;
V_507 -> V_65 . V_92 = V_1 -> V_65 . V_92 ;
V_507 -> V_65 . V_509 = V_1 -> V_65 . V_509 ;
V_507 -> V_65 . V_510 = V_1 -> V_65 . V_510 ;
V_507 -> V_65 . V_422 = V_1 -> V_65 . V_422 ;
V_507 -> V_65 . V_286 = V_1 -> V_65 . V_286 ;
V_507 -> V_65 . V_395 = V_1 -> V_65 . V_395 ;
V_507 -> V_2 . V_229 = V_1 -> V_2 . V_229 ;
V_507 -> V_2 . V_504 = V_1 -> V_2 . V_504 ;
V_507 -> V_2 . V_73 = V_1 -> V_2 . V_73 ;
V_507 -> V_2 . V_458 = V_1 -> V_2 . V_458 ;
V_507 -> V_2 . V_460 = V_1 -> V_2 . V_460 ;
V_507 -> V_2 . V_427 = V_1 -> V_2 . V_427 ;
V_507 -> V_2 . V_426 = V_1 -> V_2 . V_426 ;
V_507 -> V_2 . V_505 = V_1 -> V_2 . V_505 ;
V_507 -> V_2 . V_506 = V_1 -> V_2 . V_506 ;
if ( V_10 -> V_511 )
V_507 -> V_2 . V_78 = V_1 -> V_2 . V_78 ;
if ( V_1 -> V_2 . V_98 & V_70 ) {
struct V_18 * V_512 = & V_507 -> V_2 ;
V_512 -> V_505 = V_1 -> V_2 . V_98 ;
V_512 -> V_506 = V_1 -> V_2 . V_101 ;
}
V_507 -> V_2 . V_417 = 0 ;
V_507 -> V_2 . V_98 = 0 ;
V_507 -> V_2 . V_101 = 0 ;
if ( ! ( V_10 -> V_9 . V_46 . V_47 & V_476 ) )
V_507 -> V_2 . V_229 &= ~ V_272 ;
F_266 ( V_1 , V_25 ) ;
F_271 ( & V_10 -> V_9 ) ;
F_272 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_452 = 0 ;
V_10 -> V_1 -> V_65 . V_273 = V_25 -> V_65 . V_273 ;
V_10 -> V_1 -> V_65 . V_95 = V_25 -> V_65 . V_95 ;
V_10 -> V_1 -> V_65 . V_274 = V_25 -> V_65 . V_274 ;
V_10 -> V_1 -> V_65 . V_275 = V_25 -> V_65 . V_275 ;
V_10 -> V_1 -> V_65 . V_280 = V_25 -> V_65 . V_280 ;
V_10 -> V_1 -> V_65 . V_281 = V_25 -> V_65 . V_281 ;
F_119 ( & V_10 -> V_9 , V_25 -> V_65 . V_174 ) ;
F_30 ( & V_10 -> V_9 , V_25 -> V_65 . V_61 ) ;
F_120 ( & V_10 -> V_9 , V_25 -> V_65 . V_402 | V_513 ) ;
F_195 ( & V_10 -> V_9 , V_25 -> V_65 . V_292 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_297 = V_25 -> V_65 . V_297 ;
V_10 -> V_9 . V_46 . V_297 = V_25 -> V_65 . V_297 ;
} else {
( void ) F_273 ( & V_10 -> V_9 , V_25 -> V_65 . V_297 ) ;
}
F_152 ( & V_10 -> V_9 , V_514 , V_25 -> V_65 . V_510 ) ;
F_152 ( & V_10 -> V_9 , V_515 , V_25 -> V_65 . V_509 ) ;
F_152 ( & V_10 -> V_9 , V_288 , V_25 -> V_65 . V_92 ) ;
V_10 -> V_1 -> V_65 . V_422 = 0 ;
V_10 -> V_1 -> V_65 . V_395 = 0 ;
V_10 -> V_1 -> V_2 . V_505 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_256 ( V_188 ) ;
F_244 ( & V_10 -> V_9 ) ;
F_121 ( & V_10 -> V_9 ) ;
F_274 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_275 ( struct V_7 * V_10 )
{
int V_51 ;
if ( ! ( V_10 -> V_24 . V_29 & ( 1ULL << V_256 ) ) )
return true ;
for ( V_51 = 0 ; V_51 < V_161 ; V_51 ++ ) {
T_2 V_420 , V_516 ;
T_1 V_50 ;
if ( V_162 [ V_51 ] == 0xffffffff )
break;
V_516 = V_162 [ V_51 ] ;
V_50 = V_10 -> V_24 . V_487 + ( V_516 * 4 ) ;
if ( F_260 ( & V_10 -> V_9 , V_50 , & V_420 , 4 ) )
return false ;
V_10 -> V_24 . V_152 [ V_516 ] = V_10 -> V_152 [ V_516 ] | V_420 ;
}
V_10 -> V_1 -> V_2 . V_271 = F_118 ( V_10 -> V_24 . V_152 ) ;
return true ;
}
static bool F_276 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_29 & ( 1ULL << V_259 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_58 == 0 )
return false ;
if ( V_1 -> V_2 . V_294 && ! V_62 )
return false ;
return true ;
}
static bool F_277 ( struct V_7 * V_10 )
{
struct V_1 * V_507 ;
struct V_1 * V_25 = V_10 -> V_24 . V_25 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_188 * V_188 ;
T_1 V_517 ;
V_517 = V_10 -> V_1 -> V_65 . V_510 ;
V_507 = F_251 ( V_10 , V_10 -> V_1 -> V_65 . V_510 , & V_188 ) ;
if ( ! V_507 )
return false ;
if ( ! F_276 ( V_507 ) ) {
V_507 -> V_2 . V_458 = V_498 ;
V_507 -> V_2 . V_460 = 0 ;
V_507 -> V_2 . V_427 = 0 ;
V_507 -> V_2 . V_426 = 0 ;
F_256 ( V_188 ) ;
return false ;
}
F_278 ( V_10 -> V_1 -> V_65 . V_92 , V_517 ,
V_507 -> V_65 . V_92 ,
V_507 -> V_2 . V_229 ,
V_507 -> V_2 . V_98 ,
V_507 -> V_2 . V_294 ) ;
F_279 ( V_507 -> V_2 . V_26 & 0xffff ,
V_507 -> V_2 . V_26 >> 16 ,
V_507 -> V_2 . V_28 ,
V_507 -> V_2 . V_29 ) ;
F_271 ( & V_10 -> V_9 ) ;
F_272 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_273 = V_1 -> V_65 . V_273 ;
V_25 -> V_65 . V_95 = V_1 -> V_65 . V_95 ;
V_25 -> V_65 . V_274 = V_1 -> V_65 . V_274 ;
V_25 -> V_65 . V_275 = V_1 -> V_65 . V_275 ;
V_25 -> V_65 . V_280 = V_1 -> V_65 . V_280 ;
V_25 -> V_65 . V_281 = V_1 -> V_65 . V_281 ;
V_25 -> V_65 . V_61 = V_10 -> V_9 . V_46 . V_61 ;
V_25 -> V_65 . V_402 = F_269 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_292 = V_10 -> V_9 . V_46 . V_292 ;
V_25 -> V_65 . V_174 = F_270 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_92 = F_39 ( & V_10 -> V_9 ) ;
V_25 -> V_65 . V_509 = V_1 -> V_65 . V_509 ;
V_25 -> V_65 . V_510 = V_1 -> V_65 . V_510 ;
if ( V_62 )
V_25 -> V_65 . V_297 = V_1 -> V_65 . V_297 ;
else
V_25 -> V_65 . V_297 = F_178 ( & V_10 -> V_9 ) ;
F_266 ( V_25 , V_1 ) ;
if ( F_270 ( & V_10 -> V_9 ) & V_518 )
V_10 -> V_9 . V_46 . V_47 |= V_477 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_477 ;
if ( V_507 -> V_2 . V_294 ) {
F_280 ( & V_10 -> V_9 ) ;
V_10 -> V_24 . V_452 = V_507 -> V_2 . V_452 ;
F_240 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_65 . V_273 = V_507 -> V_65 . V_273 ;
V_10 -> V_1 -> V_65 . V_95 = V_507 -> V_65 . V_95 ;
V_10 -> V_1 -> V_65 . V_274 = V_507 -> V_65 . V_274 ;
V_10 -> V_1 -> V_65 . V_275 = V_507 -> V_65 . V_275 ;
V_10 -> V_1 -> V_65 . V_280 = V_507 -> V_65 . V_280 ;
V_10 -> V_1 -> V_65 . V_281 = V_507 -> V_65 . V_281 ;
F_119 ( & V_10 -> V_9 , V_507 -> V_65 . V_174 ) ;
F_30 ( & V_10 -> V_9 , V_507 -> V_65 . V_61 ) ;
F_120 ( & V_10 -> V_9 , V_507 -> V_65 . V_402 ) ;
F_195 ( & V_10 -> V_9 , V_507 -> V_65 . V_292 ) ;
if ( V_62 ) {
V_10 -> V_1 -> V_65 . V_297 = V_507 -> V_65 . V_297 ;
V_10 -> V_9 . V_46 . V_297 = V_507 -> V_65 . V_297 ;
} else
( void ) F_273 ( & V_10 -> V_9 , V_507 -> V_65 . V_297 ) ;
F_121 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_65 . V_474 = V_10 -> V_9 . V_46 . V_474 = V_507 -> V_65 . V_474 ;
F_152 ( & V_10 -> V_9 , V_514 , V_507 -> V_65 . V_510 ) ;
F_152 ( & V_10 -> V_9 , V_515 , V_507 -> V_65 . V_509 ) ;
F_152 ( & V_10 -> V_9 , V_288 , V_507 -> V_65 . V_92 ) ;
V_10 -> V_1 -> V_65 . V_510 = V_507 -> V_65 . V_510 ;
V_10 -> V_1 -> V_65 . V_509 = V_507 -> V_65 . V_509 ;
V_10 -> V_1 -> V_65 . V_92 = V_507 -> V_65 . V_92 ;
V_10 -> V_1 -> V_65 . V_422 = V_507 -> V_65 . V_422 ;
V_10 -> V_1 -> V_65 . V_286 = V_507 -> V_65 . V_286 ;
V_10 -> V_1 -> V_65 . V_395 = V_507 -> V_65 . V_395 ;
V_10 -> V_24 . V_487 = V_507 -> V_2 . V_271 & ~ 0x0fffULL ;
V_10 -> V_24 . V_485 = V_507 -> V_2 . V_270 & ~ 0x0fffULL ;
V_10 -> V_24 . V_26 = V_507 -> V_2 . V_26 ;
V_10 -> V_24 . V_27 = V_507 -> V_2 . V_27 ;
V_10 -> V_24 . V_28 = V_507 -> V_2 . V_28 ;
V_10 -> V_24 . V_29 = V_507 -> V_2 . V_29 ;
F_197 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_229 = V_507 -> V_2 . V_229 | V_272 ;
if ( V_507 -> V_2 . V_229 & V_272 )
V_10 -> V_9 . V_46 . V_47 |= V_476 ;
else
V_10 -> V_9 . V_46 . V_47 &= ~ V_476 ;
if ( V_10 -> V_9 . V_46 . V_47 & V_476 ) {
F_13 ( V_10 , V_519 ) ;
F_13 ( V_10 , V_239 ) ;
}
F_20 ( V_10 , V_260 ) ;
V_10 -> V_1 -> V_2 . V_163 = V_507 -> V_2 . V_163 ;
V_10 -> V_1 -> V_2 . V_504 = V_507 -> V_2 . V_504 ;
V_10 -> V_1 -> V_2 . V_73 = V_507 -> V_2 . V_73 ;
V_10 -> V_1 -> V_2 . V_218 += V_507 -> V_2 . V_218 ;
V_10 -> V_1 -> V_2 . V_98 = V_507 -> V_2 . V_98 ;
V_10 -> V_1 -> V_2 . V_101 = V_507 -> V_2 . V_101 ;
F_256 ( V_188 ) ;
F_281 ( & V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
V_10 -> V_24 . V_1 = V_517 ;
F_21 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_282 ( struct V_1 * V_501 , struct V_1 * V_520 )
{
V_520 -> V_65 . V_276 = V_501 -> V_65 . V_276 ;
V_520 -> V_65 . V_277 = V_501 -> V_65 . V_277 ;
V_520 -> V_65 . V_284 = V_501 -> V_65 . V_284 ;
V_520 -> V_65 . V_282 = V_501 -> V_65 . V_282 ;
V_520 -> V_65 . V_521 = V_501 -> V_65 . V_521 ;
V_520 -> V_65 . V_522 = V_501 -> V_65 . V_522 ;
V_520 -> V_65 . V_523 = V_501 -> V_65 . V_523 ;
V_520 -> V_65 . V_524 = V_501 -> V_65 . V_524 ;
V_520 -> V_65 . V_525 = V_501 -> V_65 . V_525 ;
V_520 -> V_65 . V_526 = V_501 -> V_65 . V_526 ;
V_520 -> V_65 . V_527 = V_501 -> V_65 . V_527 ;
V_520 -> V_65 . V_528 = V_501 -> V_65 . V_528 ;
}
static int F_283 ( struct V_7 * V_10 )
{
struct V_1 * V_507 ;
struct V_188 * V_188 ;
int V_72 ;
if ( F_245 ( V_10 ) )
return 1 ;
V_507 = F_251 ( V_10 , V_10 -> V_1 -> V_65 . V_510 , & V_188 ) ;
if ( ! V_507 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
V_72 = F_222 ( & V_10 -> V_9 ) ;
F_282 ( V_507 , V_10 -> V_1 ) ;
F_256 ( V_188 ) ;
return V_72 ;
}
static int F_284 ( struct V_7 * V_10 )
{
struct V_1 * V_507 ;
struct V_188 * V_188 ;
int V_72 ;
if ( F_245 ( V_10 ) )
return 1 ;
V_507 = F_251 ( V_10 , V_10 -> V_1 -> V_65 . V_510 , & V_188 ) ;
if ( ! V_507 )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
V_72 = F_222 ( & V_10 -> V_9 ) ;
F_282 ( V_10 -> V_1 , V_507 ) ;
F_256 ( V_188 ) ;
return V_72 ;
}
static int F_285 ( struct V_7 * V_10 )
{
if ( F_245 ( V_10 ) )
return 1 ;
F_40 ( & V_10 -> V_9 , F_39 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_277 ( V_10 ) )
return 1 ;
if ( ! F_275 ( V_10 ) )
goto V_529;
return 1 ;
V_529:
V_10 -> V_1 -> V_2 . V_458 = V_498 ;
V_10 -> V_1 -> V_2 . V_460 = 0 ;
V_10 -> V_1 -> V_2 . V_427 = 0 ;
V_10 -> V_1 -> V_2 . V_426 = 0 ;
F_239 ( V_10 ) ;
return 1 ;
}
static int F_286 ( struct V_7 * V_10 )
{
int V_72 ;
if ( F_245 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
V_72 = F_222 ( & V_10 -> V_9 ) ;
F_218 ( V_530 , & V_10 -> V_9 ) ;
F_21 ( V_10 ) ;
return V_72 ;
}
static int F_287 ( struct V_7 * V_10 )
{
int V_72 ;
if ( F_245 ( V_10 ) )
return 1 ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
V_72 = F_222 ( & V_10 -> V_9 ) ;
F_22 ( V_10 ) ;
if ( ! F_116 ( & V_10 -> V_9 ) ) {
F_180 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_229 &= ~ V_531 ;
F_3 ( V_10 -> V_1 , V_532 ) ;
}
return V_72 ;
}
static int F_288 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_289 ( V_10 -> V_1 -> V_65 . V_92 , F_290 ( & V_10 -> V_9 , V_486 ) ,
F_290 ( & V_10 -> V_9 , V_514 ) ) ;
F_291 ( V_9 , F_290 ( & V_10 -> V_9 , V_514 ) ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_222 ( & V_10 -> V_9 ) ;
}
static int F_292 ( struct V_7 * V_10 )
{
F_293 ( V_10 -> V_1 -> V_65 . V_92 , F_290 ( & V_10 -> V_9 , V_514 ) ) ;
F_209 ( & V_10 -> V_9 , V_241 ) ;
return 1 ;
}
static int F_294 ( struct V_7 * V_10 )
{
return F_295 ( & V_10 -> V_9 ) ;
}
static int F_296 ( struct V_7 * V_10 )
{
T_1 V_533 = F_297 ( & V_10 -> V_9 ) ;
T_2 V_150 = F_290 ( & V_10 -> V_9 , V_486 ) ;
if ( F_298 ( & V_10 -> V_9 , V_150 , V_533 ) == 0 ) {
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 3 ;
return F_222 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_299 ( struct V_7 * V_10 )
{
T_10 V_534 ;
int V_535 ;
int V_536 = V_10 -> V_1 -> V_2 . V_505 &
V_537 ;
int V_538 = V_10 -> V_1 -> V_2 . V_505 & V_539 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_505 & V_537 ;
T_7 V_540 =
V_10 -> V_1 -> V_2 . V_505 & V_541 ;
bool V_88 = false ;
T_2 V_90 = 0 ;
V_534 = ( T_10 ) V_10 -> V_1 -> V_2 . V_427 ;
if ( V_10 -> V_1 -> V_2 . V_426 &
( 1ULL << V_542 ) )
V_535 = V_543 ;
else if ( V_10 -> V_1 -> V_2 . V_426 &
( 1ULL << V_544 ) )
V_535 = V_545 ;
else if ( V_540 )
V_535 = V_546 ;
else
V_535 = V_547 ;
if ( V_535 == V_546 ) {
switch ( type ) {
case V_548 :
V_10 -> V_9 . V_46 . V_549 = false ;
break;
case V_550 :
if ( V_10 -> V_1 -> V_2 . V_426 &
( 1ULL << V_551 ) ) {
V_88 = true ;
V_90 =
( T_2 ) V_10 -> V_1 -> V_2 . V_426 ;
}
F_271 ( & V_10 -> V_9 ) ;
break;
case V_552 :
F_272 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_535 != V_546 ||
V_536 == V_553 ||
( V_536 == V_550 &&
( V_538 == V_554 || V_538 == V_91 ) ) )
F_34 ( & V_10 -> V_9 ) ;
if ( V_536 != V_553 )
V_538 = - 1 ;
if ( F_300 ( & V_10 -> V_9 , V_534 , V_538 , V_535 ,
V_88 , V_90 ) == V_555 ) {
V_10 -> V_9 . V_431 -> V_433 = V_556 ;
V_10 -> V_9 . V_431 -> V_557 . V_558 = V_559 ;
V_10 -> V_9 . V_431 -> V_557 . V_560 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_301 ( struct V_7 * V_10 )
{
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
return F_302 ( & V_10 -> V_9 ) ;
}
static int F_303 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_360 . V_561 ;
F_20 ( V_10 , V_562 ) ;
V_10 -> V_9 . V_46 . V_47 |= V_563 ;
V_10 -> V_564 = F_39 ( & V_10 -> V_9 ) ;
F_218 ( V_530 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_304 ( struct V_7 * V_10 )
{
if ( ! F_36 ( V_565 ) )
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
F_291 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_427 ) ;
return F_222 ( & V_10 -> V_9 ) ;
}
static int F_305 ( struct V_7 * V_10 )
{
return F_37 ( & V_10 -> V_9 , 0 ) == V_81 ;
}
static int F_306 ( struct V_7 * V_10 )
{
int V_104 ;
if ( ! F_36 ( V_79 ) )
return F_305 ( V_10 ) ;
V_104 = F_307 ( & V_10 -> V_9 ) ;
return F_308 ( & V_10 -> V_9 , V_104 ) ;
}
static bool F_309 ( struct V_7 * V_10 ,
unsigned long V_105 )
{
unsigned long V_402 = V_10 -> V_9 . V_46 . V_402 ;
bool V_72 = false ;
T_1 V_29 ;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! F_10 ( & V_10 -> V_9 ) ||
( ! ( V_29 & ( 1ULL << V_248 ) ) ) )
return false ;
V_402 &= ~ V_404 ;
V_105 &= ~ V_404 ;
if ( V_402 ^ V_105 ) {
V_10 -> V_1 -> V_2 . V_458 = V_566 ;
V_72 = ( F_265 ( V_10 ) == V_469 ) ;
}
return V_72 ;
}
static int F_310 ( struct V_7 * V_10 )
{
int V_367 , V_567 ;
unsigned long V_105 ;
int V_104 ;
if ( ! F_36 ( V_565 ) )
return F_305 ( V_10 ) ;
if ( F_163 ( ( V_10 -> V_1 -> V_2 . V_427 & V_568 ) == 0 ) )
return F_305 ( V_10 ) ;
V_367 = V_10 -> V_1 -> V_2 . V_427 & V_569 ;
if ( V_10 -> V_1 -> V_2 . V_458 == V_566 )
V_567 = V_570 - V_493 ;
else
V_567 = V_10 -> V_1 -> V_2 . V_458 - V_493 ;
V_104 = 0 ;
if ( V_567 >= 16 ) {
V_567 -= 16 ;
V_105 = F_290 ( & V_10 -> V_9 , V_367 ) ;
switch ( V_567 ) {
case 0 :
if ( ! F_309 ( V_10 , V_105 ) )
V_104 = F_311 ( & V_10 -> V_9 , V_105 ) ;
else
return 1 ;
break;
case 3 :
V_104 = F_273 ( & V_10 -> V_9 , V_105 ) ;
break;
case 4 :
V_104 = F_312 ( & V_10 -> V_9 , V_105 ) ;
break;
case 8 :
V_104 = F_313 ( & V_10 -> V_9 , V_105 ) ;
break;
default:
F_314 ( 1 , L_13 , V_567 ) ;
F_209 ( & V_10 -> V_9 , V_241 ) ;
return 1 ;
}
} else {
switch ( V_567 ) {
case 0 :
V_105 = F_269 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_105 = V_10 -> V_9 . V_46 . V_474 ;
break;
case 3 :
V_105 = F_178 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_105 = F_315 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_105 = F_316 ( & V_10 -> V_9 ) ;
break;
default:
F_314 ( 1 , L_14 , V_567 ) ;
F_209 ( & V_10 -> V_9 , V_241 ) ;
return 1 ;
}
F_152 ( & V_10 -> V_9 , V_367 , V_105 ) ;
}
return F_308 ( & V_10 -> V_9 , V_104 ) ;
}
static int F_317 ( struct V_7 * V_10 )
{
int V_367 , V_571 ;
unsigned long V_105 ;
if ( V_10 -> V_9 . V_170 == 0 ) {
F_16 ( V_10 ) ;
V_10 -> V_9 . V_46 . V_423 |= V_424 ;
return 1 ;
}
if ( ! F_98 ( V_565 ) )
return F_305 ( V_10 ) ;
V_367 = V_10 -> V_1 -> V_2 . V_427 & V_569 ;
V_571 = V_10 -> V_1 -> V_2 . V_458 - V_495 ;
if ( V_571 >= 16 ) {
if ( ! F_318 ( & V_10 -> V_9 , V_571 - 16 ) )
return 1 ;
V_105 = F_290 ( & V_10 -> V_9 , V_367 ) ;
F_319 ( & V_10 -> V_9 , V_571 - 16 , V_105 ) ;
} else {
if ( ! F_318 ( & V_10 -> V_9 , V_571 ) )
return 1 ;
F_263 ( & V_10 -> V_9 , V_571 , & V_105 ) ;
F_152 ( & V_10 -> V_9 , V_367 , V_105 ) ;
}
return F_222 ( & V_10 -> V_9 ) ;
}
static int F_320 ( struct V_7 * V_10 )
{
struct V_430 * V_430 = V_10 -> V_9 . V_431 ;
int V_146 ;
T_4 V_572 = F_316 ( & V_10 -> V_9 ) ;
V_146 = F_310 ( V_10 ) ;
if ( F_321 ( & V_10 -> V_9 ) )
return V_146 ;
if ( V_572 <= F_316 ( & V_10 -> V_9 ) )
return V_146 ;
V_430 -> V_433 = V_573 ;
return 0 ;
}
static int F_322 ( struct V_8 * V_9 , struct V_574 * V_575 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_575 -> V_150 ) {
case V_576 : {
V_575 -> V_11 = V_10 -> V_1 -> V_2 . V_218 +
F_323 ( V_9 , F_324 () ) ;
break;
}
case V_577 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_522 ;
break;
#ifdef F_29
case V_578 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_523 ;
break;
case V_579 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_524 ;
break;
case V_362 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_521 ;
break;
case V_580 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_525 ;
break;
#endif
case V_581 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_526 ;
break;
case V_582 :
V_575 -> V_11 = V_10 -> V_528 ;
break;
case V_583 :
V_575 -> V_11 = V_10 -> V_527 ;
break;
case V_358 :
if ( ! F_98 ( V_357 ) )
return 1 ;
V_575 -> V_11 = V_10 -> V_359 ;
break;
case V_584 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_585 ;
break;
case V_165 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_586 ;
break;
case V_166 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_587 ;
break;
case V_167 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_588 ;
break;
case V_168 :
V_575 -> V_11 = V_10 -> V_1 -> V_65 . V_589 ;
break;
case V_137 :
V_575 -> V_11 = V_10 -> V_24 . V_590 ;
break;
case V_591 :
V_575 -> V_11 = V_10 -> V_24 . V_592 ;
break;
case V_593 :
V_575 -> V_11 = 0x01000065 ;
break;
case V_594 : {
int V_595 , V_596 ;
V_595 = F_325 ( V_9 ) ;
V_596 = F_326 ( V_9 ) ;
if ( V_595 < 0 || V_596 < 0 )
return F_327 ( V_9 , V_575 ) ;
V_575 -> V_11 = 0 ;
if ( V_595 == 0x15 &&
( V_596 >= 0x2 && V_596 < 0x20 ) )
V_575 -> V_11 = 0x1E ;
}
break;
default:
return F_327 ( V_9 , V_575 ) ;
}
return 0 ;
}
static int F_328 ( struct V_7 * V_10 )
{
T_2 V_597 = F_290 ( & V_10 -> V_9 , V_486 ) ;
struct V_574 V_575 ;
V_575 . V_150 = V_597 ;
V_575 . V_598 = false ;
if ( F_322 ( & V_10 -> V_9 , & V_575 ) ) {
F_329 ( V_597 ) ;
F_246 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
} else {
F_330 ( V_597 , V_575 . V_11 ) ;
F_152 ( & V_10 -> V_9 , V_514 ,
V_575 . V_11 & 0xffffffff ) ;
F_152 ( & V_10 -> V_9 , V_336 ,
V_575 . V_11 >> 32 ) ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
return F_222 ( & V_10 -> V_9 ) ;
}
}
static int F_331 ( struct V_8 * V_9 , T_1 V_11 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_599 , V_600 ;
if ( V_11 & ~ V_601 )
return 1 ;
V_600 = V_601 ;
if ( V_10 -> V_24 . V_592 & V_602 )
V_600 &= ~ ( V_603 | V_602 ) ;
V_10 -> V_24 . V_592 &= ~ V_600 ;
V_10 -> V_24 . V_592 |= ( V_11 & V_600 ) ;
V_599 = V_10 -> V_24 . V_592 & V_602 ;
if ( V_599 && ( V_9 -> V_46 . V_61 & V_66 ) )
return 1 ;
return 0 ;
}
static int F_332 ( struct V_8 * V_9 , struct V_574 * V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_597 = V_49 -> V_150 ;
T_1 V_11 = V_49 -> V_11 ;
switch ( V_597 ) {
case V_576 :
F_333 ( V_9 , V_49 ) ;
break;
case V_577 :
V_10 -> V_1 -> V_65 . V_522 = V_11 ;
break;
#ifdef F_29
case V_578 :
V_10 -> V_1 -> V_65 . V_523 = V_11 ;
break;
case V_579 :
V_10 -> V_1 -> V_65 . V_524 = V_11 ;
break;
case V_362 :
V_10 -> V_1 -> V_65 . V_521 = V_11 ;
break;
case V_580 :
V_10 -> V_1 -> V_65 . V_525 = V_11 ;
break;
#endif
case V_581 :
V_10 -> V_1 -> V_65 . V_526 = V_11 ;
break;
case V_582 :
V_10 -> V_528 = V_11 ;
V_10 -> V_1 -> V_65 . V_528 = V_11 ;
break;
case V_583 :
V_10 -> V_527 = V_11 ;
V_10 -> V_1 -> V_65 . V_527 = V_11 ;
break;
case V_358 :
if ( ! F_98 ( V_357 ) )
return 1 ;
V_10 -> V_359 = V_11 ;
F_53 ( V_358 , V_10 -> V_359 ) ;
break;
case V_584 :
if ( ! F_98 ( V_604 ) ) {
F_334 ( V_9 , L_15 ,
V_83 , V_11 ) ;
break;
}
if ( V_11 & V_605 )
return 1 ;
V_10 -> V_1 -> V_65 . V_585 = V_11 ;
F_3 ( V_10 -> V_1 , V_606 ) ;
if ( V_11 & ( 1ULL << 0 ) )
F_83 ( V_10 ) ;
else
F_84 ( V_10 ) ;
break;
case V_137 :
V_10 -> V_24 . V_590 = V_11 ;
break;
case V_591 :
return F_331 ( V_9 , V_11 ) ;
case V_607 :
F_334 ( V_9 , L_16 , V_597 , V_11 ) ;
break;
case V_608 :
if ( F_116 ( V_9 ) )
F_6 ( F_4 ( V_9 ) , V_11 ) ;
default:
return F_335 ( V_9 , V_49 ) ;
}
return 0 ;
}
static int F_336 ( struct V_7 * V_10 )
{
struct V_574 V_49 ;
T_2 V_597 = F_290 ( & V_10 -> V_9 , V_486 ) ;
T_1 V_11 = F_297 ( & V_10 -> V_9 ) ;
V_49 . V_11 = V_11 ;
V_49 . V_150 = V_597 ;
V_49 . V_598 = false ;
V_10 -> V_78 = F_39 ( & V_10 -> V_9 ) + 2 ;
if ( F_337 ( & V_10 -> V_9 , & V_49 ) ) {
F_338 ( V_597 , V_11 ) ;
F_246 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
} else {
F_339 ( V_597 , V_11 ) ;
return F_222 ( & V_10 -> V_9 ) ;
}
}
static int F_340 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_427 )
return F_336 ( V_10 ) ;
else
return F_328 ( V_10 ) ;
}
static int F_341 ( struct V_7 * V_10 )
{
F_218 ( V_530 , & V_10 -> V_9 ) ;
F_180 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_229 &= ~ V_531 ;
F_3 ( V_10 -> V_1 , V_532 ) ;
++ V_10 -> V_9 . V_360 . V_609 ;
return 1 ;
}
static int F_342 ( struct V_7 * V_10 )
{
F_343 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_344 ( struct V_7 * V_10 )
{
return F_222 ( & ( V_10 -> V_9 ) ) ;
}
static int F_345 ( struct V_7 * V_10 )
{
F_346 ( V_610 L_17 ) ;
return F_344 ( V_10 ) ;
}
static int F_347 ( struct V_7 * V_10 )
{
F_346 ( V_610 L_18 ) ;
return F_344 ( V_10 ) ;
}
static int F_348 ( struct V_7 * V_10 )
{
T_2 V_611 = V_10 -> V_1 -> V_2 . V_427 >> 32 ;
T_2 V_612 = V_10 -> V_1 -> V_2 . V_427 ;
T_2 V_307 = V_10 -> V_1 -> V_2 . V_426 >> 32 ;
T_2 V_150 = V_10 -> V_1 -> V_2 . V_426 & 0xFF ;
struct V_613 * V_308 = V_10 -> V_9 . V_46 . V_308 ;
F_349 ( V_10 -> V_9 . V_181 , V_611 , V_612 , V_307 , V_150 ) ;
switch ( V_307 ) {
case V_614 :
F_350 ( V_308 , V_615 , V_611 ) ;
F_350 ( V_308 , V_616 , V_612 ) ;
break;
case V_617 : {
int V_51 ;
struct V_8 * V_9 ;
struct V_183 * V_183 = V_10 -> V_9 . V_183 ;
struct V_613 * V_308 = V_10 -> V_9 . V_46 . V_308 ;
F_351 (i, vcpu, kvm) {
bool V_618 = F_352 ( V_9 , V_308 ,
V_612 & V_619 ,
F_353 ( V_611 ) ,
V_612 & V_620 ) ;
if ( V_618 && ! F_7 ( V_9 ) )
F_94 ( V_9 ) ;
}
break;
}
case V_621 :
break;
case V_622 :
F_354 ( 1 , L_19 ) ;
break;
default:
F_59 ( L_20 ) ;
}
return 1 ;
}
static T_2 * F_355 ( struct V_8 * V_9 , T_2 V_623 , bool V_624 )
{
struct V_178 * V_184 = & V_9 -> V_183 -> V_46 ;
int V_150 ;
T_2 * V_625 ;
int V_626 = F_356 ( V_623 ) ;
if ( ! V_626 )
return NULL ;
if ( V_624 ) {
V_150 = F_357 ( V_626 ) - 1 ;
if ( V_150 > 7 )
return NULL ;
} else {
int V_627 = ( V_626 & 0xf0 ) >> 4 ;
int V_308 = F_357 ( V_626 & 0x0f ) - 1 ;
if ( ( V_308 < 0 ) || ( V_308 > 7 ) ||
( V_627 >= 0xf ) )
return NULL ;
V_150 = ( V_627 << 2 ) + V_308 ;
}
V_625 = ( T_2 * ) F_97 ( V_184 -> V_222 ) ;
return & V_625 [ V_150 ] ;
}
static int F_358 ( struct V_8 * V_9 , T_4 V_628 , T_2 V_623 ,
bool V_629 )
{
bool V_624 ;
T_2 * V_15 , V_306 ;
V_624 = F_359 ( V_9 -> V_46 . V_308 , V_630 ) == V_631 ;
V_15 = F_355 ( V_9 , V_623 , V_624 ) ;
if ( ! V_15 )
return - V_128 ;
V_306 = F_8 ( * V_15 ) ;
V_306 &= ~ V_632 ;
V_306 |= ( V_628 & V_632 ) ;
if ( V_629 )
V_306 |= V_633 ;
else
V_306 &= ~ V_633 ;
F_127 ( * V_15 , V_306 ) ;
return 0 ;
}
static int F_360 ( struct V_8 * V_9 )
{
int V_72 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_623 = F_359 ( V_9 -> V_46 . V_308 , V_634 ) ;
if ( ! V_623 )
return 1 ;
V_72 = F_358 ( V_9 , V_9 -> V_181 , V_623 , true ) ;
if ( V_72 && V_10 -> V_635 ) {
F_358 ( V_9 , 0 , V_10 -> V_635 , false ) ;
V_10 -> V_635 = 0 ;
} else {
V_10 -> V_635 = V_623 ;
}
return V_72 ;
}
static int F_361 ( struct V_8 * V_9 )
{
T_1 * V_636 , * V_637 ;
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_638 = F_359 ( V_9 -> V_46 . V_308 , V_639 ) ;
T_2 V_307 = ( V_638 >> 24 ) & 0xff ;
if ( V_9 -> V_181 == V_307 )
return 0 ;
V_636 = F_122 ( V_9 , V_9 -> V_181 ) ;
V_637 = F_122 ( V_9 , V_307 ) ;
if ( ! V_637 || ! V_636 )
return 1 ;
* V_637 = * V_636 ;
* V_636 = 0ULL ;
F_4 ( V_9 ) -> V_16 = V_637 ;
if ( V_10 -> V_635 )
F_360 ( V_9 ) ;
return 0 ;
}
static int F_362 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_178 * V_184 = & V_9 -> V_183 -> V_46 ;
T_2 V_640 = F_359 ( V_9 -> V_46 . V_308 , V_630 ) ;
T_2 V_641 = ( V_640 >> 28 ) & 0xf ;
if ( V_184 -> V_642 == V_641 )
return 0 ;
F_138 ( F_97 ( V_184 -> V_222 ) ) ;
V_184 -> V_642 = V_641 ;
if ( V_10 -> V_635 )
F_360 ( V_9 ) ;
return 0 ;
}
static int F_363 ( struct V_7 * V_10 )
{
struct V_613 * V_308 = V_10 -> V_9 . V_46 . V_308 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_427 &
V_643 ;
switch ( V_50 ) {
case V_639 :
if ( F_361 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_634 :
if ( F_360 ( & V_10 -> V_9 ) )
return 0 ;
break;
case V_630 :
F_362 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
F_350 ( V_308 , V_50 , F_359 ( V_308 , V_50 ) ) ;
return 1 ;
}
static bool F_364 ( T_2 V_50 )
{
bool V_72 = false ;
switch ( V_50 ) {
case V_639 :
case V_644 :
case V_645 :
case V_634 :
case V_630 :
case V_646 :
case V_647 :
case V_616 :
case V_648 :
case V_649 :
case V_650 :
case V_651 :
case V_652 :
case V_653 :
case V_654 :
case V_655 :
V_72 = true ;
break;
default:
break;
}
return V_72 ;
}
static int F_365 ( struct V_7 * V_10 )
{
int V_72 = 0 ;
T_2 V_50 = V_10 -> V_1 -> V_2 . V_427 &
V_643 ;
T_2 V_656 = V_10 -> V_1 -> V_2 . V_426 &
V_657 ;
bool V_154 = ( V_10 -> V_1 -> V_2 . V_427 >> 32 ) &
V_658 ;
bool V_659 = F_364 ( V_50 ) ;
F_366 ( V_10 -> V_9 . V_181 , V_50 ,
V_659 , V_154 , V_656 ) ;
if ( V_659 ) {
F_354 ( ! V_154 , L_21 ) ;
V_72 = F_363 ( V_10 ) ;
} else {
V_72 = ( F_37 ( & V_10 -> V_9 , 0 ) == V_81 ) ;
}
return V_72 ;
}
static void F_367 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_232 * V_65 = & V_10 -> V_1 -> V_65 ;
F_59 ( L_22 ) ;
F_59 ( L_23 , L_24 , V_2 -> V_26 & 0xffff ) ;
F_59 ( L_23 , L_25 , V_2 -> V_26 >> 16 ) ;
F_59 ( L_23 , L_26 , V_2 -> V_27 & 0xffff ) ;
F_59 ( L_23 , L_27 , V_2 -> V_27 >> 16 ) ;
F_59 ( L_28 , L_29 , V_2 -> V_28 ) ;
F_59 ( L_30 , L_31 , V_2 -> V_29 ) ;
F_59 ( L_32 , L_33 , V_2 -> V_299 ) ;
F_59 ( L_30 , L_34 , V_2 -> V_270 ) ;
F_59 ( L_30 , L_35 , V_2 -> V_271 ) ;
F_59 ( L_30 , L_36 , V_2 -> V_218 ) ;
F_59 ( L_32 , L_37 , V_2 -> V_58 ) ;
F_59 ( L_32 , L_38 , V_2 -> V_417 ) ;
F_59 ( L_28 , L_39 , V_2 -> V_229 ) ;
F_59 ( L_28 , L_40 , V_2 -> V_504 ) ;
F_59 ( L_28 , L_41 , V_2 -> V_73 ) ;
F_59 ( L_28 , L_42 , V_2 -> V_458 ) ;
F_59 ( L_30 , L_43 , V_2 -> V_427 ) ;
F_59 ( L_30 , L_44 , V_2 -> V_426 ) ;
F_59 ( L_28 , L_45 , V_2 -> V_505 ) ;
F_59 ( L_28 , L_46 , V_2 -> V_506 ) ;
F_59 ( L_47 , L_48 , V_2 -> V_294 ) ;
F_59 ( L_30 , L_49 , V_2 -> V_452 ) ;
F_59 ( L_30 , L_50 , V_2 -> V_12 ) ;
F_59 ( L_28 , L_51 , V_2 -> V_98 ) ;
F_59 ( L_28 , L_52 , V_2 -> V_101 ) ;
F_59 ( L_47 , L_53 , V_2 -> V_163 ) ;
F_59 ( L_30 , L_54 , V_2 -> V_78 ) ;
F_59 ( L_30 , L_55 , V_2 -> V_220 ) ;
F_59 ( L_30 , L_56 , V_2 -> V_226 ) ;
F_59 ( L_30 , L_57 , V_2 -> V_227 ) ;
F_59 ( L_58 ) ;
F_59 ( L_59 ,
L_60 ,
V_65 -> V_273 . V_211 , V_65 -> V_273 . V_212 ,
V_65 -> V_273 . V_216 , V_65 -> V_273 . V_96 ) ;
F_59 ( L_59 ,
L_61 ,
V_65 -> V_95 . V_211 , V_65 -> V_95 . V_212 ,
V_65 -> V_95 . V_216 , V_65 -> V_95 . V_96 ) ;
F_59 ( L_59 ,
L_62 ,
V_65 -> V_274 . V_211 , V_65 -> V_274 . V_212 ,
V_65 -> V_274 . V_216 , V_65 -> V_274 . V_96 ) ;
F_59 ( L_59 ,
L_63 ,
V_65 -> V_275 . V_211 , V_65 -> V_275 . V_212 ,
V_65 -> V_275 . V_216 , V_65 -> V_275 . V_96 ) ;
F_59 ( L_59 ,
L_64 ,
V_65 -> V_276 . V_211 , V_65 -> V_276 . V_212 ,
V_65 -> V_276 . V_216 , V_65 -> V_276 . V_96 ) ;
F_59 ( L_59 ,
L_65 ,
V_65 -> V_277 . V_211 , V_65 -> V_277 . V_212 ,
V_65 -> V_277 . V_216 , V_65 -> V_277 . V_96 ) ;
F_59 ( L_59 ,
L_66 ,
V_65 -> V_280 . V_211 , V_65 -> V_280 . V_212 ,
V_65 -> V_280 . V_216 , V_65 -> V_280 . V_96 ) ;
F_59 ( L_59 ,
L_67 ,
V_65 -> V_282 . V_211 , V_65 -> V_282 . V_212 ,
V_65 -> V_282 . V_216 , V_65 -> V_282 . V_96 ) ;
F_59 ( L_59 ,
L_68 ,
V_65 -> V_281 . V_211 , V_65 -> V_281 . V_212 ,
V_65 -> V_281 . V_216 , V_65 -> V_281 . V_96 ) ;
F_59 ( L_59 ,
L_69 ,
V_65 -> V_284 . V_211 , V_65 -> V_284 . V_212 ,
V_65 -> V_284 . V_216 , V_65 -> V_284 . V_96 ) ;
F_59 ( L_70 ,
V_65 -> V_395 , V_65 -> V_61 ) ;
F_59 ( L_71 ,
L_72 , V_65 -> V_402 , L_73 , V_65 -> V_474 ) ;
F_59 ( L_71 ,
L_74 , V_65 -> V_297 , L_75 , V_65 -> V_292 ) ;
F_59 ( L_71 ,
L_76 , V_65 -> V_286 , L_77 , V_65 -> V_422 ) ;
F_59 ( L_71 ,
L_78 , V_65 -> V_92 , L_79 , V_65 -> V_174 ) ;
F_59 ( L_71 ,
L_80 , V_65 -> V_509 , L_81 , V_65 -> V_510 ) ;
F_59 ( L_71 ,
L_82 , V_65 -> V_522 , L_83 , V_65 -> V_523 ) ;
F_59 ( L_71 ,
L_84 , V_65 -> V_524 , L_85 , V_65 -> V_525 ) ;
F_59 ( L_71 ,
L_86 , V_65 -> V_521 ,
L_87 , V_65 -> V_526 ) ;
F_59 ( L_71 ,
L_88 , V_65 -> V_527 ,
L_89 , V_65 -> V_528 ) ;
F_59 ( L_71 ,
L_90 , V_65 -> V_295 , L_91 , V_65 -> V_585 ) ;
F_59 ( L_71 ,
L_92 , V_65 -> V_586 , L_93 , V_65 -> V_587 ) ;
F_59 ( L_71 ,
L_94 , V_65 -> V_588 ,
L_95 , V_65 -> V_589 ) ;
}
static void F_368 ( struct V_8 * V_9 , T_1 * V_660 , T_1 * V_661 )
{
struct V_18 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_660 = V_2 -> V_427 ;
* V_661 = V_2 -> V_426 ;
}
static int F_369 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_430 * V_430 = V_9 -> V_431 ;
T_2 V_458 = V_10 -> V_1 -> V_2 . V_458 ;
F_370 ( V_458 , V_9 , V_508 ) ;
V_9 -> V_46 . V_662 = ( V_458 == V_459 ) ;
if ( ! F_14 ( V_10 , V_236 ) )
V_9 -> V_46 . V_402 = V_10 -> V_1 -> V_65 . V_402 ;
if ( V_62 )
V_9 -> V_46 . V_297 = V_10 -> V_1 -> V_65 . V_297 ;
if ( F_163 ( V_10 -> V_24 . V_475 ) ) {
F_239 ( V_10 ) ;
V_10 -> V_24 . V_475 = false ;
return 1 ;
}
if ( F_10 ( V_9 ) ) {
int V_468 ;
F_371 ( V_10 -> V_1 -> V_65 . V_92 , V_458 ,
V_10 -> V_1 -> V_2 . V_427 ,
V_10 -> V_1 -> V_2 . V_426 ,
V_10 -> V_1 -> V_2 . V_505 ,
V_10 -> V_1 -> V_2 . V_506 ,
V_508 ) ;
V_468 = F_264 ( V_10 ) ;
if ( V_468 == V_490 )
V_468 = F_265 ( V_10 ) ;
if ( V_468 == V_469 )
return 1 ;
}
F_372 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_458 == V_498 ) {
V_430 -> V_433 = V_663 ;
V_430 -> V_664 . V_665
= V_10 -> V_1 -> V_2 . V_458 ;
F_59 ( L_96 ) ;
F_367 ( V_9 ) ;
return 0 ;
}
if ( F_31 ( V_10 -> V_1 -> V_2 . V_505 ) &&
V_458 != V_470 + V_240 &&
V_458 != V_459 && V_458 != V_666 &&
V_458 != V_478 && V_458 != V_479 )
F_38 ( V_85 L_97
L_98 ,
V_83 , V_10 -> V_1 -> V_2 . V_505 ,
V_458 ) ;
if ( V_458 >= F_373 ( V_667 )
|| ! V_667 [ V_458 ] ) {
F_354 ( 1 , L_99 , V_458 ) ;
F_209 ( V_9 , V_241 ) ;
return 1 ;
}
return V_667 [ V_458 ] ( V_10 ) ;
}
static void F_374 ( struct V_8 * V_9 )
{
int V_145 = F_57 () ;
struct V_121 * V_122 = F_60 ( V_129 , V_145 ) ;
V_122 -> V_134 -> type = 9 ;
F_375 () ;
}
static void F_376 ( struct V_7 * V_10 )
{
int V_145 = F_57 () ;
struct V_121 * V_122 = F_60 ( V_129 , V_145 ) ;
if ( V_10 -> V_130 != V_122 -> V_130 )
F_200 ( V_10 , V_122 ) ;
}
static void F_377 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_98 = V_70 | V_668 ;
V_9 -> V_46 . V_47 |= V_669 ;
F_19 ( V_10 , V_562 ) ;
++ V_9 -> V_360 . V_670 ;
}
static inline void F_378 ( struct V_7 * V_10 , int V_671 )
{
struct V_18 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_504 = V_671 ;
V_2 -> V_229 &= ~ V_672 ;
V_2 -> V_229 |= V_531 |
( ( 0xf ) << V_673 ) ;
F_3 ( V_10 -> V_1 , V_532 ) ;
}
static void F_379 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_76 ( ! ( F_23 ( V_10 ) ) ) ;
F_380 ( V_9 -> V_46 . V_674 . V_86 ) ;
++ V_9 -> V_360 . V_675 ;
V_10 -> V_1 -> V_2 . V_98 = V_9 -> V_46 . V_674 . V_86 |
V_70 | V_71 ;
}
static inline bool F_381 ( struct V_8 * V_9 )
{
return F_10 ( V_9 ) && ( V_9 -> V_46 . V_47 & V_476 ) ;
}
static void F_382 ( struct V_8 * V_9 , int V_676 , int V_677 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_381 ( V_9 ) ||
F_116 ( V_9 ) )
return;
F_13 ( V_10 , V_239 ) ;
if ( V_677 == - 1 )
return;
if ( V_676 >= V_677 )
F_12 ( V_10 , V_239 ) ;
}
static void F_383 ( struct V_8 * V_9 , bool V_678 )
{
return;
}
static bool F_384 ( void )
{
return V_204 ;
}
static void F_385 ( struct V_8 * V_9 , int V_679 )
{
}
static void F_386 ( struct V_8 * V_9 , int V_680 )
{
}
static void F_387 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( ! V_204 )
return;
V_1 -> V_2 . V_229 &= ~ V_230 ;
F_3 ( V_1 , V_532 ) ;
}
static void F_388 ( struct V_8 * V_9 , T_1 * V_681 )
{
return;
}
static void F_389 ( struct V_8 * V_9 , int V_682 )
{
F_390 ( V_682 , V_9 -> V_46 . V_308 ) ;
F_391 () ;
if ( F_7 ( V_9 ) )
F_53 ( V_683 ,
F_146 ( V_9 -> V_145 ) ) ;
else
F_94 ( V_9 ) ;
}
static void F_392 ( struct V_7 * V_10 , struct V_684 * V_685 )
{
unsigned long V_177 ;
struct V_321 * V_686 ;
F_90 ( & V_10 -> V_323 , V_177 ) ;
F_143 (cur, &svm->ir_list, node) {
if ( V_686 -> V_11 != V_685 -> V_687 )
continue;
F_393 ( & V_686 -> V_688 ) ;
F_69 ( V_686 ) ;
break;
}
F_93 ( & V_10 -> V_323 , V_177 ) ;
}
static int F_394 ( struct V_7 * V_10 , struct V_684 * V_685 )
{
int V_72 = 0 ;
unsigned long V_177 ;
struct V_321 * V_322 ;
if ( V_685 -> V_687 && ( V_685 -> V_689 != 0 ) ) {
struct V_183 * V_183 = V_10 -> V_9 . V_183 ;
T_2 V_181 = F_88 ( V_685 -> V_689 ) ;
struct V_8 * V_690 = F_92 ( V_183 , V_181 ) ;
struct V_7 * V_691 ;
if ( ! V_690 ) {
V_72 = - V_128 ;
goto V_325;
}
V_691 = F_4 ( V_690 ) ;
F_392 ( V_691 , V_685 ) ;
}
V_322 = F_71 ( sizeof( struct V_321 ) , V_147 ) ;
if ( ! V_322 ) {
V_72 = - V_148 ;
goto V_325;
}
V_322 -> V_11 = V_685 -> V_687 ;
F_90 ( & V_10 -> V_323 , V_177 ) ;
F_395 ( & V_322 -> V_688 , & V_10 -> V_324 ) ;
F_93 ( & V_10 -> V_323 , V_177 ) ;
V_325:
return V_72 ;
}
static int
F_396 ( struct V_183 * V_183 , struct V_692 * V_693 ,
struct V_694 * V_695 , struct V_7 * * V_10 )
{
struct V_696 V_671 ;
struct V_8 * V_9 = NULL ;
F_397 ( V_183 , V_693 , & V_671 ) ;
if ( ! F_398 ( V_183 , & V_671 , & V_9 ) ) {
F_89 ( L_100 ,
V_83 , V_671 . V_656 ) ;
return - 1 ;
}
F_89 ( L_101 , V_83 ,
V_671 . V_656 ) ;
* V_10 = F_4 ( V_9 ) ;
V_695 -> V_697 = F_114 ( ( * V_10 ) -> V_220 ) ;
V_695 -> V_656 = V_671 . V_656 ;
return 0 ;
}
static int F_399 ( struct V_183 * V_183 , unsigned int V_698 ,
T_7 V_699 , bool V_678 )
{
struct V_692 * V_693 ;
struct V_700 * V_701 ;
int V_702 , V_72 = - V_128 ;
if ( ! F_141 ( V_183 ) ||
! F_400 ( V_703 ) )
return 0 ;
F_89 ( L_102 ,
V_83 , V_698 , V_699 , V_678 ) ;
V_702 = F_401 ( & V_183 -> V_704 ) ;
V_701 = F_402 ( V_183 -> V_705 , & V_183 -> V_704 ) ;
F_75 ( V_699 >= V_701 -> V_706 ) ;
F_403 (e, &irq_rt->map[guest_irq], link) {
struct V_694 V_695 ;
struct V_7 * V_10 = NULL ;
if ( V_693 -> type != V_707 )
continue;
if ( ! F_396 ( V_183 , V_693 , & V_695 , & V_10 ) && V_678 &&
F_116 ( & V_10 -> V_9 ) ) {
struct V_684 V_685 ;
V_685 . V_96 = F_114 ( V_10 -> V_220 ) & V_225 ;
V_685 . V_176 = F_404 ( V_183 -> V_46 . V_185 ,
V_10 -> V_9 . V_181 ) ;
V_685 . F_10 = true ;
V_685 . V_694 = & V_695 ;
V_72 = F_405 ( V_698 , & V_685 ) ;
if ( ! V_72 && V_685 . F_10 )
F_394 ( V_10 , & V_685 ) ;
} else {
struct V_684 V_685 ;
V_685 . F_10 = false ;
V_72 = F_405 ( V_698 , & V_685 ) ;
if ( ! V_72 && V_685 . V_689 ) {
int V_307 = F_88 ( V_685 . V_689 ) ;
struct V_8 * V_9 ;
V_9 = F_92 ( V_183 , V_307 ) ;
if ( V_9 )
F_392 ( F_4 ( V_9 ) , & V_685 ) ;
}
}
if ( ! V_72 && V_10 ) {
F_406 ( V_10 -> V_9 . V_181 ,
V_698 , V_693 -> V_708 ,
V_695 . V_656 ,
V_695 . V_697 , V_678 ) ;
}
if ( V_72 < 0 ) {
F_59 ( L_103 , V_83 ) ;
goto V_325;
}
}
V_72 = 0 ;
V_325:
F_407 ( & V_183 -> V_704 , V_702 ) ;
return V_72 ;
}
static int F_408 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
V_72 = ! ( V_1 -> V_2 . V_73 & V_74 ) &&
! ( V_10 -> V_9 . V_46 . V_47 & V_669 ) ;
V_72 = V_72 && F_23 ( V_10 ) && F_250 ( V_10 ) ;
return V_72 ;
}
static bool F_409 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_46 . V_47 & V_669 ) ;
}
static void F_410 ( struct V_8 * V_9 , bool V_709 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_709 ) {
V_10 -> V_9 . V_46 . V_47 |= V_669 ;
F_19 ( V_10 , V_562 ) ;
} else {
V_10 -> V_9 . V_46 . V_47 &= ~ V_669 ;
F_20 ( V_10 , V_562 ) ;
}
}
static int F_411 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_72 ;
if ( ! F_23 ( V_10 ) ||
( V_1 -> V_2 . V_73 & V_74 ) )
return 0 ;
V_72 = ! ! ( F_270 ( V_9 ) & V_518 ) ;
if ( F_10 ( V_9 ) )
return V_72 && ! ( V_10 -> V_9 . V_46 . V_47 & V_476 ) ;
return V_72 ;
}
static void F_412 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_116 ( V_9 ) )
return;
if ( F_23 ( V_10 ) && F_248 ( V_10 ) ) {
F_179 ( V_10 ) ;
F_378 ( V_10 , 0x0 ) ;
}
}
static void F_413 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_46 . V_47 & ( V_669 | V_563 ) )
== V_669 )
return;
if ( ( V_10 -> V_9 . V_46 . V_47 & V_48 ) == 0 )
return;
if ( V_10 -> V_24 . V_475 )
return;
V_10 -> V_172 = F_174 ( V_9 ) ;
V_10 -> V_169 = true ;
V_10 -> V_1 -> V_65 . V_174 |= ( V_173 | V_175 ) ;
}
static int F_414 ( struct V_183 * V_183 , unsigned int V_57 )
{
return 0 ;
}
static void F_197 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_36 ( V_710 ) )
V_10 -> V_1 -> V_2 . V_417 = V_711 ;
else
V_10 -> V_130 -- ;
}
static void F_415 ( struct V_8 * V_9 )
{
}
static inline void F_416 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_381 ( V_9 ) )
return;
if ( ! F_14 ( V_10 , V_239 ) ) {
int V_712 = V_10 -> V_1 -> V_2 . V_229 & V_713 ;
F_313 ( V_9 , V_712 ) ;
}
}
static inline void F_417 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_712 ;
if ( F_381 ( V_9 ) ||
F_116 ( V_9 ) )
return;
V_712 = F_316 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_229 &= ~ V_713 ;
V_10 -> V_1 -> V_2 . V_229 |= V_712 & V_713 ;
}
static void F_372 ( struct V_7 * V_10 )
{
T_4 V_656 ;
int type ;
T_2 V_714 = V_10 -> V_1 -> V_2 . V_505 ;
unsigned V_97 = V_10 -> V_97 ;
V_10 -> V_97 = 0 ;
if ( ( V_10 -> V_9 . V_46 . V_47 & V_563 )
&& F_39 ( & V_10 -> V_9 ) != V_10 -> V_564 ) {
V_10 -> V_9 . V_46 . V_47 &= ~ ( V_669 | V_563 ) ;
F_218 ( V_530 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_46 . V_549 = false ;
F_271 ( & V_10 -> V_9 ) ;
F_272 ( & V_10 -> V_9 ) ;
if ( ! ( V_714 & V_541 ) )
return;
F_218 ( V_530 , & V_10 -> V_9 ) ;
V_656 = V_714 & V_715 ;
type = V_714 & V_537 ;
switch ( type ) {
case V_548 :
V_10 -> V_9 . V_46 . V_549 = true ;
break;
case V_550 :
if ( F_418 ( V_656 ) ) {
if ( V_656 == V_91 && V_97 &&
F_419 ( & V_10 -> V_9 , V_10 -> V_94 ) )
F_40 ( & V_10 -> V_9 ,
F_39 ( & V_10 -> V_9 ) -
V_97 ) ;
break;
}
if ( V_714 & V_716 ) {
T_2 V_104 = V_10 -> V_1 -> V_2 . V_506 ;
F_420 ( & V_10 -> V_9 , V_656 , V_104 ) ;
} else
F_421 ( & V_10 -> V_9 , V_656 ) ;
break;
case V_552 :
F_422 ( & V_10 -> V_9 , V_656 , false ) ;
break;
default:
break;
}
}
static void F_423 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_18 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_505 = V_2 -> V_98 ;
V_2 -> V_506 = V_2 -> V_101 ;
V_2 -> V_98 = 0 ;
F_372 ( V_10 ) ;
}
static void F_424 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_510 = V_9 -> V_46 . V_287 [ V_514 ] ;
V_10 -> V_1 -> V_65 . V_509 = V_9 -> V_46 . V_287 [ V_515 ] ;
V_10 -> V_1 -> V_65 . V_92 = V_9 -> V_46 . V_287 [ V_288 ] ;
if ( F_163 ( V_10 -> V_24 . V_475 ) )
return;
if ( V_10 -> V_169 && V_10 -> V_1 -> V_2 . V_98 ) {
F_85 ( V_10 ) ;
F_425 ( V_9 -> V_145 ) ;
}
F_376 ( V_10 ) ;
F_417 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_474 = V_9 -> V_46 . V_474 ;
F_25 () ;
F_426 () ;
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
F_53 ( V_348 , V_10 -> V_349 . V_350 ) ;
#else
F_169 ( V_276 , V_10 -> V_349 . V_276 ) ;
#ifndef F_171
F_169 ( V_277 , V_10 -> V_349 . V_277 ) ;
#endif
#endif
F_374 ( V_9 ) ;
F_427 () ;
V_9 -> V_46 . V_474 = V_10 -> V_1 -> V_65 . V_474 ;
V_9 -> V_46 . V_287 [ V_514 ] = V_10 -> V_1 -> V_65 . V_510 ;
V_9 -> V_46 . V_287 [ V_515 ] = V_10 -> V_1 -> V_65 . V_509 ;
V_9 -> V_46 . V_287 [ V_288 ] = V_10 -> V_1 -> V_65 . V_92 ;
if ( F_163 ( V_10 -> V_1 -> V_2 . V_458 == V_479 ) )
F_428 ( & V_10 -> V_9 ) ;
F_26 () ;
if ( F_163 ( V_10 -> V_1 -> V_2 . V_458 == V_479 ) )
F_429 ( & V_10 -> V_9 ) ;
F_416 ( V_9 ) ;
V_10 -> V_78 = 0 ;
V_10 -> V_1 -> V_2 . V_417 = V_717 ;
if ( V_10 -> V_1 -> V_2 . V_458 == V_470 + V_240 )
V_10 -> V_9 . V_46 . V_472 . V_489 = F_430 () ;
if ( V_62 ) {
V_9 -> V_46 . V_718 &= ~ ( 1 << V_368 ) ;
V_9 -> V_46 . V_719 &= ~ ( 1 << V_368 ) ;
}
if ( F_163 ( V_10 -> V_1 -> V_2 . V_458 ==
V_470 + V_242 ) )
F_217 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_431 ( struct V_8 * V_9 , unsigned long V_454 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_65 . V_297 = V_454 ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_197 ( V_9 ) ;
}
static void F_432 ( struct V_8 * V_9 , unsigned long V_454 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_452 = V_454 ;
F_3 ( V_10 -> V_1 , V_455 ) ;
V_10 -> V_1 -> V_65 . V_297 = F_178 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_67 ) ;
F_197 ( V_9 ) ;
}
static int F_433 ( void )
{
T_1 V_720 ;
F_58 ( V_591 , V_720 ) ;
if ( V_720 & ( 1 << V_721 ) )
return 1 ;
return 0 ;
}
static void
F_434 ( struct V_8 * V_9 , unsigned char * V_722 )
{
V_722 [ 0 ] = 0x0f ;
V_722 [ 1 ] = 0x01 ;
V_722 [ 2 ] = 0xd9 ;
}
static void F_435 ( void * V_723 )
{
* ( int * ) V_723 = 0 ;
}
static bool F_436 ( void )
{
return false ;
}
static bool F_437 ( void )
{
return true ;
}
static T_1 F_438 ( struct V_8 * V_9 , T_11 V_724 , bool V_725 )
{
return 0 ;
}
static void F_439 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_726 * V_15 ;
V_10 -> V_511 = ! ! F_440 ( & V_10 -> V_9 ) ;
if ( ! F_116 ( V_9 ) )
return;
V_15 = F_441 ( V_9 , 1 , 0 ) ;
if ( V_15 )
V_15 -> V_597 &= ~ V_6 ( V_727 ) ;
}
static void F_442 ( T_2 V_728 , struct V_726 * V_15 )
{
switch ( V_728 ) {
case 0x1 :
if ( V_204 )
V_15 -> V_597 &= ~ V_6 ( V_727 ) ;
break;
case 0x80000001 :
if ( V_24 )
V_15 -> V_597 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_15 -> V_332 = 1 ;
V_15 -> V_729 = 8 ;
V_15 -> V_597 = 0 ;
V_15 -> V_730 = 0 ;
if ( F_98 ( V_79 ) )
V_15 -> V_730 |= V_731 ;
if ( V_62 )
V_15 -> V_730 |= V_732 ;
break;
}
}
static int F_443 ( void )
{
return V_733 ;
}
static bool F_444 ( void )
{
return F_98 ( V_357 ) ;
}
static bool F_445 ( void )
{
return false ;
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
return true ;
}
static int F_449 ( struct V_8 * V_9 ,
struct V_734 * V_68 ,
enum V_735 V_736 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_468 , V_72 = V_737 ;
struct V_738 V_739 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_68 -> V_29 >= F_373 ( V_740 ) )
goto V_325;
V_739 = V_740 [ V_68 -> V_29 ] ;
if ( V_736 != V_739 . V_736 )
goto V_325;
switch ( V_739 . V_458 ) {
case V_493 :
if ( V_68 -> V_29 == V_741 )
V_739 . V_458 += V_68 -> V_742 ;
break;
case V_570 : {
unsigned long V_402 , V_105 ;
T_1 V_29 ;
if ( V_68 -> V_29 == V_743 )
V_739 . V_458 += V_68 -> V_742 ;
if ( V_739 . V_458 != V_570 ||
V_68 -> V_29 == V_744 )
break;
V_29 = V_10 -> V_24 . V_29 ;
if ( ! ( V_29 & ( 1ULL << V_248 ) ) )
break;
V_402 = V_9 -> V_46 . V_402 & ~ V_404 ;
V_105 = V_68 -> V_745 & ~ V_404 ;
if ( V_68 -> V_29 == V_746 ) {
V_402 &= 0xfUL ;
V_105 &= 0xfUL ;
if ( V_402 & V_513 )
V_105 |= V_513 ;
}
if ( V_402 ^ V_105 )
V_739 . V_458 = V_566 ;
break;
}
case V_495 :
case V_747 :
V_739 . V_458 += V_68 -> V_742 ;
break;
case V_491 :
if ( V_68 -> V_29 == V_748 )
V_1 -> V_2 . V_427 = 1 ;
else
V_1 -> V_2 . V_427 = 0 ;
break;
case V_749 :
if ( V_68 -> V_750 != V_751 )
goto V_325;
case V_492 : {
T_1 V_752 ;
T_2 V_753 ;
if ( V_68 -> V_29 == V_754 ||
V_68 -> V_29 == V_755 ) {
V_752 = ( ( V_68 -> V_745 & 0xffff ) << 16 ) |
V_448 ;
V_753 = V_68 -> V_756 ;
} else {
V_752 = ( V_68 -> V_757 & 0xffff ) << 16 ;
V_753 = V_68 -> V_758 ;
}
if ( V_68 -> V_29 == V_759 ||
V_68 -> V_29 == V_755 )
V_752 |= V_447 ;
if ( V_68 -> V_750 )
V_752 |= V_760 ;
V_753 = F_450 ( V_753 , 4u ) ;
V_752 |= V_753 << V_450 ;
V_752 |= ( T_2 ) V_68 -> V_761 << ( V_762 - 1 ) ;
V_1 -> V_2 . V_427 = V_752 ;
V_1 -> V_2 . V_426 = V_68 -> V_78 ;
break;
}
default:
break;
}
if ( F_36 ( V_79 ) )
V_1 -> V_2 . V_78 = V_68 -> V_78 ;
V_1 -> V_2 . V_458 = V_739 . V_458 ;
V_468 = F_265 ( V_10 ) ;
V_72 = ( V_468 == V_469 ) ? V_763
: V_737 ;
V_325:
return V_72 ;
}
static void F_451 ( struct V_8 * V_9 )
{
F_426 () ;
asm("nop");
F_427 () ;
}
static void F_452 ( struct V_8 * V_9 , int V_145 )
{
}
static inline void F_453 ( struct V_8 * V_9 )
{
if ( F_361 ( V_9 ) != 0 )
return;
if ( F_362 ( V_9 ) != 0 )
return;
F_360 ( V_9 ) ;
}
static void F_454 ( struct V_8 * V_9 )
{
V_9 -> V_46 . V_764 &= 0x1ff ;
}
static int T_5 F_455 ( void )
{
return F_456 ( & V_765 , sizeof( struct V_7 ) ,
F_457 ( struct V_7 ) , V_766 ) ;
}
static void T_6 F_458 ( void )
{
F_459 () ;
}
