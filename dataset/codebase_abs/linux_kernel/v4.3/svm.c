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
T_2 V_172 ;
V_173 = true ;
V_172 = F_87 ( 0x7fffffffULL , F_88 ( V_174 , V_175 ) ) ;
V_176 = V_172 ;
}
if ( V_17 ) {
F_35 ( V_109 L_6 ) ;
F_86 ( V_59 | V_177 ) ;
}
F_89 (cpu) {
V_141 = F_67 ( V_140 ) ;
if ( V_141 )
goto V_96;
}
if ( ! F_85 ( V_178 ) )
V_55 = false ;
if ( V_55 && ! V_179 ) {
F_35 ( V_109 L_7 ) ;
V_55 = false ;
}
if ( V_55 ) {
F_35 ( V_109 L_8 ) ;
F_90 () ;
} else
F_91 () ;
return 0 ;
V_96:
F_92 ( V_164 , V_166 ) ;
V_167 = 0 ;
return V_141 ;
}
static T_6 void F_93 ( void )
{
int V_140 ;
F_89 (cpu)
F_64 ( V_140 ) ;
F_92 ( F_94 ( V_167 >> V_134 ) , V_166 ) ;
V_167 = 0 ;
}
static void F_95 ( struct V_180 * V_181 )
{
V_181 -> V_182 = 0 ;
V_181 -> V_183 = V_184 | V_185 |
V_186 ;
V_181 -> V_187 = 0xffff ;
V_181 -> V_88 = 0 ;
}
static void F_96 ( struct V_180 * V_181 , T_7 type )
{
V_181 -> V_182 = 0 ;
V_181 -> V_183 = V_184 | type ;
V_181 -> V_187 = 0xffff ;
V_181 -> V_88 = 0 ;
}
static T_2 F_88 ( T_2 V_188 , T_2 V_189 )
{
T_2 V_190 , V_191 , V_192 ;
V_190 = V_188 >> 32 ;
V_191 = V_188 & ( ( 1ULL << 32 ) - 1 ) ;
V_192 = V_189 ;
V_192 *= V_190 ;
V_192 += ( V_189 >> 32 ) * V_191 ;
V_192 += ( ( V_189 & ( ( 1ULL << 32 ) - 1 ) ) * V_191 ) >> 32 ;
return V_192 ;
}
static T_2 F_97 ( struct V_8 * V_9 , T_2 V_189 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_192 = V_189 ;
if ( V_10 -> V_193 != V_112 )
V_192 = F_88 ( V_10 -> V_193 , V_189 ) ;
return V_192 ;
}
static void F_98 ( struct V_8 * V_9 , T_1 V_194 , bool V_195 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_188 ;
T_2 V_196 ;
if ( ! V_195 ) {
V_10 -> V_193 = V_112 ;
return;
}
if ( ! F_85 ( V_110 ) ) {
if ( V_194 > V_174 ) {
V_9 -> V_39 . V_197 = 1 ;
V_9 -> V_39 . V_198 = 1 ;
} else
F_99 ( 1 , L_9 ) ;
return;
}
V_196 = V_194 ;
V_188 = V_196 << 32 ;
F_100 ( V_188 , V_174 ) ;
if ( V_188 == 0 || V_188 & V_199 ) {
F_101 ( 1 , L_10 ,
V_194 ) ;
return;
}
V_10 -> V_193 = V_188 ;
}
static T_2 F_102 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_200 ;
}
static void F_103 ( struct V_8 * V_9 , T_2 V_43 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_201 = 0 ;
if ( F_7 ( V_9 ) ) {
V_201 = V_10 -> V_1 -> V_2 . V_200 -
V_10 -> V_17 . V_18 -> V_2 . V_200 ;
V_10 -> V_17 . V_18 -> V_2 . V_200 = V_43 ;
} else
F_104 ( V_9 -> V_202 ,
V_10 -> V_1 -> V_2 . V_200 ,
V_43 ) ;
V_10 -> V_1 -> V_2 . V_200 = V_43 + V_201 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_105 ( struct V_8 * V_9 , T_8 V_203 , bool V_204 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_204 ) {
if ( V_10 -> V_193 != V_112 )
F_72 ( V_203 < 0 ) ;
V_203 = F_97 ( V_9 , ( T_2 ) V_203 ) ;
}
V_10 -> V_1 -> V_2 . V_200 += V_203 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_200 += V_203 ;
else
F_104 ( V_9 -> V_202 ,
V_10 -> V_1 -> V_2 . V_200 - V_203 ,
V_10 -> V_1 -> V_2 . V_200 ) ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_106 ( struct V_8 * V_9 , T_2 V_205 )
{
T_2 V_189 ;
V_189 = F_97 ( V_9 , F_107 () ) ;
return V_205 - V_189 ;
}
static void F_108 ( struct V_7 * V_10 , bool V_206 )
{
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_207 * V_58 = & V_10 -> V_1 -> V_58 ;
V_10 -> V_9 . V_208 = 1 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
F_9 ( V_10 , V_209 ) ;
F_9 ( V_10 , V_210 ) ;
F_9 ( V_10 , V_211 ) ;
F_9 ( V_10 , V_212 ) ;
F_9 ( V_10 , V_213 ) ;
F_9 ( V_10 , V_214 ) ;
F_9 ( V_10 , V_215 ) ;
F_12 ( V_10 ) ;
F_14 ( V_10 , V_216 ) ;
F_14 ( V_10 , V_217 ) ;
F_14 ( V_10 , V_218 ) ;
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
F_16 ( V_10 , V_230 ) ;
F_16 ( V_10 , V_231 ) ;
F_16 ( V_10 , V_232 ) ;
F_16 ( V_10 , V_233 ) ;
F_16 ( V_10 , V_234 ) ;
F_16 ( V_10 , V_235 ) ;
F_16 ( V_10 , V_236 ) ;
F_16 ( V_10 , V_237 ) ;
F_16 ( V_10 , V_238 ) ;
F_16 ( V_10 , V_239 ) ;
F_16 ( V_10 , V_240 ) ;
F_16 ( V_10 , V_241 ) ;
F_16 ( V_10 , V_242 ) ;
F_16 ( V_10 , V_243 ) ;
V_2 -> V_244 = V_167 ;
V_2 -> V_245 = F_109 ( V_10 -> V_147 ) ;
V_2 -> V_246 = V_247 ;
F_95 ( & V_58 -> V_248 ) ;
F_95 ( & V_58 -> V_249 ) ;
F_95 ( & V_58 -> V_250 ) ;
F_95 ( & V_58 -> V_251 ) ;
F_95 ( & V_58 -> V_252 ) ;
V_58 -> V_87 . V_182 = 0xf000 ;
V_58 -> V_87 . V_88 = 0xffff0000 ;
V_58 -> V_87 . V_183 = V_253 | V_184 |
V_185 | V_254 ;
V_58 -> V_87 . V_187 = 0xffff ;
V_58 -> V_255 . V_187 = 0xffff ;
V_58 -> V_256 . V_187 = 0xffff ;
F_96 ( & V_58 -> V_257 , V_258 ) ;
F_96 ( & V_58 -> V_259 , V_260 ) ;
if ( ! V_206 )
F_27 ( & V_10 -> V_9 , 0 ) ;
V_58 -> V_261 = 0xffff0ff0 ;
F_110 ( & V_10 -> V_9 , 2 ) ;
V_58 -> V_84 = 0x0000fff0 ;
V_10 -> V_9 . V_39 . V_262 [ V_263 ] = V_58 -> V_84 ;
F_111 ( & V_10 -> V_9 , V_264 | V_265 | V_266 ) ;
F_112 ( & V_10 -> V_9 ) ;
V_58 -> V_267 = V_268 ;
if ( V_55 ) {
V_2 -> V_269 = 1 ;
F_17 ( V_10 , V_227 ) ;
F_15 ( V_10 , V_216 ) ;
F_10 ( V_10 , V_210 ) ;
F_10 ( V_10 , V_213 ) ;
V_58 -> V_270 = V_10 -> V_9 . V_39 . V_271 ;
V_58 -> V_272 = 0 ;
V_58 -> V_267 = 0 ;
}
V_10 -> V_124 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
if ( F_85 ( V_273 ) ) {
V_2 -> V_274 = 3000 ;
F_16 ( V_10 , V_275 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static void F_113 ( struct V_8 * V_9 , bool V_206 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_276 ;
T_1 V_277 = 1 ;
if ( ! V_206 ) {
V_10 -> V_9 . V_39 . V_278 = V_279 |
V_280 ;
if ( F_114 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_39 . V_278 |= V_281 ;
}
F_108 ( V_10 , V_206 ) ;
F_115 ( V_9 , & V_277 , & V_276 , & V_276 , & V_276 ) ;
F_116 ( V_9 , V_282 , V_277 ) ;
}
static struct V_8 * F_117 ( struct V_283 * V_283 , unsigned int V_284 )
{
struct V_7 * V_10 ;
struct V_163 * V_163 ;
struct V_163 * V_285 ;
struct V_163 * V_286 ;
struct V_163 * V_287 ;
int V_96 ;
V_10 = F_118 ( V_288 , V_142 ) ;
if ( ! V_10 ) {
V_96 = - V_143 ;
goto V_289;
}
V_10 -> V_193 = V_112 ;
V_96 = F_119 ( & V_10 -> V_9 , V_283 , V_284 ) ;
if ( V_96 )
goto V_290;
V_96 = - V_143 ;
V_163 = F_69 ( V_142 ) ;
if ( ! V_163 )
goto V_291;
V_285 = F_83 ( V_142 , V_154 ) ;
if ( ! V_285 )
goto V_292;
V_287 = F_83 ( V_142 , V_154 ) ;
if ( ! V_287 )
goto V_293;
V_286 = F_69 ( V_142 ) ;
if ( ! V_286 )
goto V_294;
V_10 -> V_17 . V_18 = F_84 ( V_286 ) ;
V_10 -> V_147 = F_84 ( V_285 ) ;
F_76 ( V_10 -> V_147 ) ;
V_10 -> V_17 . V_147 = F_84 ( V_287 ) ;
F_76 ( V_10 -> V_17 . V_147 ) ;
V_10 -> V_1 = F_84 ( V_163 ) ;
F_120 ( V_10 -> V_1 ) ;
V_10 -> V_295 = F_60 ( V_163 ) << V_134 ;
V_10 -> V_124 = 0 ;
F_108 ( V_10 , false ) ;
F_46 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_294:
F_92 ( V_287 , V_154 ) ;
V_293:
F_92 ( V_285 , V_154 ) ;
V_292:
F_65 ( V_163 ) ;
V_291:
F_121 ( & V_10 -> V_9 ) ;
V_290:
F_122 ( V_288 , V_10 ) ;
V_289:
return F_123 ( V_96 ) ;
}
static void F_124 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_65 ( F_94 ( V_10 -> V_295 >> V_134 ) ) ;
F_92 ( F_125 ( V_10 -> V_147 ) , V_154 ) ;
F_65 ( F_125 ( V_10 -> V_17 . V_18 ) ) ;
F_92 ( F_125 ( V_10 -> V_17 . V_147 ) , V_154 ) ;
F_121 ( V_9 ) ;
F_122 ( V_288 , V_10 ) ;
}
static void F_126 ( struct V_8 * V_9 , int V_140 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
if ( F_127 ( V_140 != V_9 -> V_140 ) ) {
V_10 -> V_124 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_55 ( V_296 , F_4 ( V_9 ) -> V_204 . V_297 ) ;
#endif
F_128 ( V_251 , V_10 -> V_204 . V_251 ) ;
F_128 ( V_252 , V_10 -> V_204 . V_252 ) ;
V_10 -> V_204 . V_298 = F_129 () ;
for ( V_44 = 0 ; V_44 < V_299 ; V_44 ++ )
F_55 ( V_300 [ V_44 ] , V_10 -> V_301 [ V_44 ] ) ;
if ( F_33 ( V_110 ) &&
V_10 -> V_193 != F_130 ( V_135 ) ) {
F_61 ( V_135 , V_10 -> V_193 ) ;
F_50 ( V_111 , V_10 -> V_193 ) ;
}
}
static void F_131 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
++ V_9 -> V_302 . V_303 ;
F_132 ( V_10 -> V_204 . V_298 ) ;
#ifdef F_26
F_133 ( V_251 , V_10 -> V_204 . V_251 ) ;
F_50 ( V_304 , V_305 -> V_306 . V_252 ) ;
F_134 ( V_10 -> V_204 . V_252 ) ;
#else
#ifdef F_135
F_133 ( V_252 , V_10 -> V_204 . V_252 ) ;
#endif
#endif
for ( V_44 = 0 ; V_44 < V_299 ; V_44 ++ )
F_50 ( V_300 [ V_44 ] , V_10 -> V_301 [ V_44 ] ) ;
}
static unsigned long F_136 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_307 ;
}
static void F_137 ( struct V_8 * V_9 , unsigned long V_307 )
{
F_4 ( V_9 ) -> V_1 -> V_58 . V_307 = V_307 ;
}
static void F_138 ( struct V_8 * V_9 , enum V_308 V_309 )
{
switch ( V_309 ) {
case V_310 :
F_73 ( ! V_55 ) ;
F_139 ( V_9 , V_9 -> V_39 . V_311 , F_140 ( V_9 ) ) ;
break;
default:
F_78 () ;
}
}
static void F_141 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_312 ) ;
}
static void F_142 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_312 ) ;
}
static struct V_180 * F_143 ( struct V_8 * V_9 , int V_181 )
{
struct V_207 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_181 ) {
case V_313 : return & V_58 -> V_87 ;
case V_314 : return & V_58 -> V_250 ;
case V_315 : return & V_58 -> V_248 ;
case V_316 : return & V_58 -> V_251 ;
case V_317 : return & V_58 -> V_252 ;
case V_318 : return & V_58 -> V_249 ;
case V_319 : return & V_58 -> V_259 ;
case V_320 : return & V_58 -> V_257 ;
}
F_78 () ;
return NULL ;
}
static T_2 F_144 ( struct V_8 * V_9 , int V_181 )
{
struct V_180 * V_321 = F_143 ( V_9 , V_181 ) ;
return V_321 -> V_88 ;
}
static void F_145 ( struct V_8 * V_9 ,
struct V_322 * V_323 , int V_181 )
{
struct V_180 * V_321 = F_143 ( V_9 , V_181 ) ;
V_323 -> V_88 = V_321 -> V_88 ;
V_323 -> V_187 = V_321 -> V_187 ;
V_323 -> V_182 = V_321 -> V_182 ;
V_323 -> type = V_321 -> V_183 & V_324 ;
V_323 -> V_321 = ( V_321 -> V_183 >> V_325 ) & 1 ;
V_323 -> V_326 = ( V_321 -> V_183 >> V_327 ) & 3 ;
V_323 -> V_328 = ( V_321 -> V_183 >> V_329 ) & 1 ;
V_323 -> V_330 = ( V_321 -> V_183 >> V_331 ) & 1 ;
V_323 -> V_332 = ( V_321 -> V_183 >> V_333 ) & 1 ;
V_323 -> V_334 = ( V_321 -> V_183 >> V_335 ) & 1 ;
V_323 -> V_15 = V_321 -> V_187 > 0xfffff ;
V_323 -> V_336 = ! V_323 -> V_328 || ( V_323 -> type == 0 ) ;
switch ( V_181 ) {
case V_319 :
V_323 -> type |= 0x2 ;
break;
case V_314 :
case V_315 :
case V_316 :
case V_317 :
if ( ! V_323 -> V_336 )
V_323 -> type |= 0x1 ;
break;
case V_318 :
if ( V_323 -> V_336 )
V_323 -> V_334 = 0 ;
V_323 -> V_326 = F_4 ( V_9 ) -> V_1 -> V_58 . V_337 ;
break;
}
}
static int F_146 ( struct V_8 * V_9 )
{
struct V_207 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_337 ;
}
static void F_147 ( struct V_8 * V_9 , struct V_115 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_338 -> V_339 = V_10 -> V_1 -> V_58 . V_256 . V_187 ;
V_338 -> V_128 = V_10 -> V_1 -> V_58 . V_256 . V_88 ;
}
static void F_148 ( struct V_8 * V_9 , struct V_115 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_256 . V_187 = V_338 -> V_339 ;
V_10 -> V_1 -> V_58 . V_256 . V_88 = V_338 -> V_128 ;
F_3 ( V_10 -> V_1 , V_340 ) ;
}
static void F_149 ( struct V_8 * V_9 , struct V_115 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_338 -> V_339 = V_10 -> V_1 -> V_58 . V_255 . V_187 ;
V_338 -> V_128 = V_10 -> V_1 -> V_58 . V_255 . V_88 ;
}
static void F_150 ( struct V_8 * V_9 , struct V_115 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_255 . V_187 = V_338 -> V_339 ;
V_10 -> V_1 -> V_58 . V_255 . V_88 = V_338 -> V_128 ;
F_3 ( V_10 -> V_1 , V_340 ) ;
}
static void F_151 ( struct V_8 * V_9 )
{
}
static void F_152 ( struct V_8 * V_9 )
{
}
static void F_153 ( struct V_8 * V_9 )
{
}
static void F_154 ( struct V_7 * V_10 )
{
T_9 V_341 = V_10 -> V_9 . V_39 . V_342 ;
T_2 * V_343 = & V_10 -> V_1 -> V_58 . V_342 ;
if ( ! V_10 -> V_9 . V_208 )
* V_343 |= V_344 ;
else
* V_343 = ( * V_343 & ~ V_344 )
| ( V_341 & V_344 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_341 == * V_343 && V_10 -> V_9 . V_208 ) {
F_10 ( V_10 , V_209 ) ;
F_10 ( V_10 , V_212 ) ;
} else {
F_9 ( V_10 , V_209 ) ;
F_9 ( V_10 , V_212 ) ;
}
}
static void F_111 ( struct V_8 * V_9 , unsigned long V_342 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_155 ( V_9 ) && ( V_342 & V_345 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_155 ( V_9 ) && ! ( V_342 & V_345 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_342 = V_342 ;
if ( ! V_55 )
V_342 |= V_345 | V_346 ;
if ( ! V_9 -> V_208 )
V_342 |= V_347 ;
if ( F_156 ( V_9 -> V_283 , V_348 ) )
V_342 &= ~ ( V_265 | V_264 ) ;
V_10 -> V_1 -> V_58 . V_342 = V_342 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_154 ( V_10 ) ;
}
static int F_157 ( struct V_8 * V_9 , unsigned long V_267 )
{
unsigned long V_349 = F_158 () & V_350 ;
unsigned long V_351 = F_4 ( V_9 ) -> V_1 -> V_58 . V_267 ;
if ( V_267 & V_352 )
return 1 ;
if ( V_55 && ( ( V_351 ^ V_267 ) & V_353 ) )
F_159 ( V_9 ) ;
V_9 -> V_39 . V_267 = V_267 ;
if ( ! V_55 )
V_267 |= V_268 ;
V_267 |= V_349 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_267 = V_267 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_160 ( struct V_8 * V_9 ,
struct V_322 * V_323 , int V_181 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_180 * V_321 = F_143 ( V_9 , V_181 ) ;
V_321 -> V_88 = V_323 -> V_88 ;
V_321 -> V_187 = V_323 -> V_187 ;
V_321 -> V_182 = V_323 -> V_182 ;
if ( V_323 -> V_336 )
V_321 -> V_183 = 0 ;
else {
V_321 -> V_183 = ( V_323 -> type & V_324 ) ;
V_321 -> V_183 |= ( V_323 -> V_321 & 1 ) << V_325 ;
V_321 -> V_183 |= ( V_323 -> V_326 & 3 ) << V_327 ;
V_321 -> V_183 |= ( V_323 -> V_328 & 1 ) << V_329 ;
V_321 -> V_183 |= ( V_323 -> V_330 & 1 ) << V_331 ;
V_321 -> V_183 |= ( V_323 -> V_332 & 1 ) << V_333 ;
V_321 -> V_183 |= ( V_323 -> V_334 & 1 ) << V_335 ;
V_321 -> V_183 |= ( V_323 -> V_15 & 1 ) << V_354 ;
}
if ( V_181 == V_318 )
V_10 -> V_1 -> V_58 . V_337 = ( V_321 -> V_183 >> V_327 ) & 3 ;
F_3 ( V_10 -> V_1 , V_355 ) ;
}
static void F_161 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_356 ) ;
F_15 ( V_10 , V_83 ) ;
if ( V_10 -> V_357 )
F_14 ( V_10 , V_356 ) ;
if ( V_9 -> V_358 & V_359 ) {
if ( V_9 -> V_358 &
( V_360 | V_361 ) )
F_14 ( V_10 , V_356 ) ;
if ( V_9 -> V_358 & V_362 )
F_14 ( V_10 , V_83 ) ;
} else
V_9 -> V_358 = 0 ;
}
static void F_162 ( struct V_7 * V_10 , struct V_113 * V_114 )
{
if ( V_114 -> V_127 > V_114 -> V_125 ) {
++ V_114 -> V_124 ;
V_114 -> V_127 = 1 ;
V_10 -> V_1 -> V_2 . V_363 = V_364 ;
}
V_10 -> V_124 = V_114 -> V_124 ;
V_10 -> V_1 -> V_2 . V_51 = V_114 -> V_127 ++ ;
F_3 ( V_10 -> V_1 , V_365 ) ;
}
static T_2 F_163 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_261 ;
}
static void F_164 ( struct V_8 * V_9 , unsigned long V_366 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_261 = V_366 ;
F_3 ( V_10 -> V_1 , V_367 ) ;
}
static void F_165 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_166 ( V_9 -> V_39 . V_334 [ 0 ] , 0 ) ;
F_166 ( V_9 -> V_39 . V_334 [ 1 ] , 1 ) ;
F_166 ( V_9 -> V_39 . V_334 [ 2 ] , 2 ) ;
F_166 ( V_9 -> V_39 . V_334 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_261 = F_163 ( V_9 ) ;
V_9 -> V_39 . V_368 = V_10 -> V_1 -> V_58 . V_368 ;
V_9 -> V_39 . V_369 &= ~ V_370 ;
F_12 ( V_10 ) ;
}
static void F_167 ( struct V_8 * V_9 , unsigned long V_366 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_368 = V_366 ;
F_3 ( V_10 -> V_1 , V_367 ) ;
}
static int F_168 ( struct V_7 * V_10 )
{
T_2 V_371 = V_10 -> V_1 -> V_2 . V_372 ;
T_1 V_81 ;
int V_141 = 1 ;
switch ( V_10 -> V_373 ) {
default:
V_81 = V_10 -> V_1 -> V_2 . V_374 ;
F_169 ( V_371 , V_81 ) ;
if ( ! V_55 && F_170 ( & V_10 -> V_9 ) )
F_171 ( & V_10 -> V_9 , V_371 ) ;
V_141 = F_172 ( & V_10 -> V_9 , V_371 , V_81 ,
V_10 -> V_1 -> V_2 . V_375 ,
V_10 -> V_1 -> V_2 . V_376 ) ;
break;
case V_377 :
V_10 -> V_373 = 0 ;
F_173 () ;
F_174 ( V_371 ) ;
F_175 () ;
break;
case V_378 :
V_10 -> V_373 = 0 ;
F_173 () ;
F_176 ( V_371 ) ;
F_175 () ;
break;
}
return V_141 ;
}
static int F_177 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
if ( ! ( V_10 -> V_9 . V_358 &
( V_360 | V_361 ) ) &&
! V_10 -> V_357 ) {
F_178 ( & V_10 -> V_9 , V_356 ) ;
return 1 ;
}
if ( V_10 -> V_357 ) {
V_10 -> V_357 = false ;
if ( ! ( V_10 -> V_9 . V_358 & V_360 ) )
V_10 -> V_1 -> V_58 . V_307 &=
~ ( V_381 | V_382 ) ;
F_161 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_358 &
( V_360 | V_361 ) ) {
V_379 -> V_383 = V_384 ;
V_379 -> V_385 . V_39 . V_386 =
V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_379 -> V_385 . V_39 . V_387 = V_356 ;
return 0 ;
}
return 1 ;
}
static int F_179 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
V_379 -> V_383 = V_384 ;
V_379 -> V_385 . V_39 . V_386 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_379 -> V_385 . V_39 . V_387 = V_83 ;
return 0 ;
}
static int F_180 ( struct V_7 * V_10 )
{
int V_388 ;
V_388 = F_34 ( & V_10 -> V_9 , V_389 ) ;
if ( V_388 != V_74 )
F_178 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static void F_181 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_390 ) ;
V_10 -> V_9 . V_208 = 1 ;
F_154 ( V_10 ) ;
}
static int F_182 ( struct V_7 * V_10 )
{
F_181 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_183 ( void )
{
int V_96 , V_44 ;
T_2 V_366 ;
if ( ! V_100 )
return false ;
V_366 = F_42 ( V_391 , & V_96 ) ;
if ( V_96 )
return false ;
V_366 &= ~ ( 1ULL << 62 ) ;
if ( V_366 != 0xb600000000010015ULL )
return false ;
for ( V_44 = 0 ; V_44 < 6 ; ++ V_44 )
F_45 ( F_184 ( V_44 ) , 0 , 0 ) ;
V_366 = F_42 ( V_392 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_366 &= ~ ( 1ULL << 2 ) ;
V_94 = F_43 ( V_366 ) ;
V_95 = F_44 ( V_366 ) ;
F_45 ( V_392 , V_94 , V_95 ) ;
}
F_185 () ;
return true ;
}
static void F_186 ( struct V_7 * V_10 )
{
if ( F_183 () ) {
F_56 ( L_11 ) ;
F_187 ( V_393 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_188 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_189 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
F_120 ( V_10 -> V_1 ) ;
F_108 ( V_10 , false ) ;
V_379 -> V_383 = V_394 ;
return 0 ;
}
static int F_190 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_395 = V_10 -> V_1 -> V_2 . V_374 ;
int V_339 , V_396 , string ;
unsigned V_397 ;
++ V_10 -> V_9 . V_302 . V_398 ;
string = ( V_395 & V_399 ) != 0 ;
V_396 = ( V_395 & V_400 ) != 0 ;
if ( string || V_396 )
return F_34 ( V_9 , 0 ) == V_74 ;
V_397 = V_395 >> 16 ;
V_339 = ( V_395 & V_401 ) >> V_402 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_372 ;
F_31 ( & V_10 -> V_9 ) ;
return F_191 ( V_9 , V_339 , V_397 ) ;
}
static int F_192 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_193 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_302 . V_403 ;
return 1 ;
}
static int F_194 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_195 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 1 ;
return F_196 ( & V_10 -> V_9 ) ;
}
static int F_197 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_198 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_199 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_404 ;
}
static T_2 F_200 ( struct V_8 * V_9 , int V_145 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_272 = V_10 -> V_17 . V_404 ;
T_2 V_405 ;
int V_65 ;
V_65 = F_201 ( V_9 , F_202 ( V_272 ) , & V_405 ,
F_203 ( V_272 ) + V_145 * 8 , 8 ) ;
if ( V_65 )
return 0 ;
return V_405 ;
}
static void F_204 ( struct V_8 * V_9 ,
unsigned long V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_404 = V_406 ;
F_3 ( V_10 -> V_1 , V_407 ) ;
F_159 ( V_9 ) ;
}
static void F_205 ( struct V_8 * V_9 ,
struct V_408 * V_409 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_410 != V_411 ) {
V_10 -> V_1 -> V_2 . V_410 = V_411 ;
V_10 -> V_1 -> V_2 . V_412 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_372 = V_409 -> V_128 ;
}
V_10 -> V_1 -> V_2 . V_374 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_374 |= V_409 -> V_81 ;
if ( V_10 -> V_1 -> V_2 . V_374 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_374 &= ~ 1 ;
F_206 ( V_10 ) ;
}
static void F_207 ( struct V_8 * V_9 )
{
F_72 ( F_208 ( V_9 ) ) ;
F_209 ( V_9 ) ;
V_9 -> V_39 . V_413 . V_414 = F_204 ;
V_9 -> V_39 . V_413 . V_415 = F_199 ;
V_9 -> V_39 . V_413 . V_416 = F_200 ;
V_9 -> V_39 . V_413 . V_417 = F_205 ;
V_9 -> V_39 . V_413 . V_418 = F_25 () ;
F_210 ( V_9 , & V_9 -> V_39 . V_413 ) ;
V_9 -> V_39 . V_311 = & V_9 -> V_39 . V_419 ;
}
static void F_211 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_311 = & V_9 -> V_39 . V_413 ;
}
static int F_212 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_155 ( & V_10 -> V_9 ) ) {
F_178 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_337 ) {
F_213 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_7 * V_10 , unsigned V_79 ,
bool V_80 , T_1 V_81 )
{
int V_420 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_410 = V_421 + V_79 ;
V_10 -> V_1 -> V_2 . V_412 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = V_81 ;
V_10 -> V_1 -> V_2 . V_372 = V_10 -> V_9 . V_39 . V_422 ;
V_420 = F_214 ( V_10 ) ;
if ( V_420 == V_423 )
V_10 -> V_17 . V_424 = true ;
return V_420 ;
}
static inline bool F_215 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_425 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_426 ) )
return false ;
if ( V_10 -> V_17 . V_424 )
return false ;
V_10 -> V_1 -> V_2 . V_410 = V_427 ;
V_10 -> V_1 -> V_2 . V_374 = 0 ;
V_10 -> V_1 -> V_2 . V_372 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_424 = true ;
F_216 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_217 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_220 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_410 = V_428 ;
V_10 -> V_17 . V_424 = true ;
return false ;
}
static void * F_218 ( struct V_7 * V_10 , T_2 V_429 , struct V_163 * * V_430 )
{
struct V_163 * V_163 ;
F_219 () ;
V_163 = F_220 ( & V_10 -> V_9 , V_429 >> V_134 ) ;
if ( F_221 ( V_163 ) )
goto error;
* V_430 = V_163 ;
return F_222 ( V_163 ) ;
error:
F_213 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_223 ( struct V_163 * V_163 )
{
F_224 ( V_163 ) ;
F_225 ( V_163 ) ;
}
static int F_226 ( struct V_7 * V_10 )
{
unsigned V_397 , V_339 , V_431 ;
T_10 V_97 , V_70 ;
T_4 V_432 ;
T_2 V_429 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return V_433 ;
V_397 = V_10 -> V_1 -> V_2 . V_374 >> 16 ;
V_339 = ( V_10 -> V_1 -> V_2 . V_374 & V_401 ) >>
V_402 ;
V_429 = V_10 -> V_17 . V_434 + ( V_397 / 8 ) ;
V_432 = V_397 % 8 ;
V_431 = ( V_432 + V_339 > 8 ) ? 2 : 1 ;
V_70 = ( 0xf >> ( 4 - V_339 ) ) << V_432 ;
V_97 = 0 ;
if ( F_227 ( & V_10 -> V_9 , V_429 , & V_97 , V_431 ) )
return V_423 ;
return ( V_97 & V_70 ) ? V_423 : V_433 ;
}
static int F_228 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_366 ;
int V_149 , V_70 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_230 ) ) )
return V_433 ;
V_42 = V_10 -> V_9 . V_39 . V_262 [ V_435 ] ;
V_43 = F_21 ( V_42 ) ;
V_149 = V_10 -> V_1 -> V_2 . V_374 & 1 ;
V_70 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_149 ) ;
if ( V_43 == V_49 )
return V_423 ;
V_43 *= 4 ;
if ( F_227 ( & V_10 -> V_9 , V_10 -> V_17 . V_436 + V_43 , & V_366 , 4 ) )
return V_423 ;
return ( V_366 & V_70 ) ? V_423 : V_433 ;
}
static int F_229 ( struct V_7 * V_10 )
{
T_1 V_410 = V_10 -> V_1 -> V_2 . V_410 ;
switch ( V_410 ) {
case V_427 :
case V_428 :
case V_421 + V_218 :
return V_433 ;
case V_411 :
if ( V_55 )
return V_433 ;
break;
case V_421 + V_216 :
if ( ! V_55 && V_10 -> V_373 == 0 )
return V_433 ;
break;
case V_421 + V_390 :
F_182 ( V_10 ) ;
break;
default:
break;
}
return V_437 ;
}
static int F_214 ( struct V_7 * V_10 )
{
T_1 V_410 = V_10 -> V_1 -> V_2 . V_410 ;
int V_420 = V_433 ;
switch ( V_410 ) {
case V_438 :
V_420 = F_228 ( V_10 ) ;
break;
case V_439 :
V_420 = F_226 ( V_10 ) ;
break;
case V_440 ... V_441 : {
T_1 V_6 = 1U << ( V_410 - V_440 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_420 = V_423 ;
break;
}
case V_442 ... V_443 : {
T_1 V_6 = 1U << ( V_410 - V_442 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_420 = V_423 ;
break;
}
case V_421 ... V_421 + 0x1f : {
T_1 V_444 = 1 << ( V_410 - V_421 ) ;
if ( V_10 -> V_17 . V_21 & V_444 )
V_420 = V_423 ;
else if ( ( V_410 == V_421 + V_216 ) &&
V_10 -> V_373 != 0 )
V_420 = V_423 ;
break;
}
case V_445 : {
V_420 = V_423 ;
break;
}
default: {
T_2 V_446 = 1ULL << ( V_410 - V_427 ) ;
if ( V_10 -> V_17 . V_22 & V_446 )
V_420 = V_423 ;
}
}
return V_420 ;
}
static int F_230 ( struct V_7 * V_10 )
{
int V_420 ;
V_420 = F_214 ( V_10 ) ;
if ( V_420 == V_423 )
F_206 ( V_10 ) ;
return V_420 ;
}
static inline void F_231 ( struct V_1 * V_447 , struct V_1 * V_448 )
{
struct V_11 * V_449 = & V_447 -> V_2 ;
struct V_11 * V_450 = & V_448 -> V_2 ;
V_449 -> V_19 = V_450 -> V_19 ;
V_449 -> V_20 = V_450 -> V_20 ;
V_449 -> V_21 = V_450 -> V_21 ;
V_449 -> V_22 = V_450 -> V_22 ;
V_449 -> V_244 = V_450 -> V_244 ;
V_449 -> V_245 = V_450 -> V_245 ;
V_449 -> V_200 = V_450 -> V_200 ;
V_449 -> V_51 = V_450 -> V_51 ;
V_449 -> V_363 = V_450 -> V_363 ;
V_449 -> V_246 = V_450 -> V_246 ;
V_449 -> V_451 = V_450 -> V_451 ;
V_449 -> V_66 = V_450 -> V_66 ;
V_449 -> V_410 = V_450 -> V_410 ;
V_449 -> V_412 = V_450 -> V_412 ;
V_449 -> V_374 = V_450 -> V_374 ;
V_449 -> V_372 = V_450 -> V_372 ;
V_449 -> V_452 = V_450 -> V_452 ;
V_449 -> V_453 = V_450 -> V_453 ;
V_449 -> V_269 = V_450 -> V_269 ;
V_449 -> V_90 = V_450 -> V_90 ;
V_449 -> V_93 = V_450 -> V_93 ;
V_449 -> V_404 = V_450 -> V_404 ;
V_449 -> V_158 = V_450 -> V_158 ;
}
static int F_206 ( struct V_7 * V_10 )
{
struct V_1 * V_454 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
F_232 ( V_1 -> V_2 . V_410 ,
V_1 -> V_2 . V_374 ,
V_1 -> V_2 . V_372 ,
V_1 -> V_2 . V_452 ,
V_1 -> V_2 . V_453 ,
V_455 ) ;
V_454 = F_218 ( V_10 , V_10 -> V_17 . V_1 , & V_163 ) ;
if ( ! V_454 )
return 1 ;
F_233 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_454 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_454 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_454 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_454 -> V_58 . V_250 = V_1 -> V_58 . V_250 ;
V_454 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_454 -> V_58 . V_256 = V_1 -> V_58 . V_256 ;
V_454 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_454 -> V_58 . V_342 = F_234 ( & V_10 -> V_9 ) ;
V_454 -> V_58 . V_272 = F_140 ( & V_10 -> V_9 ) ;
V_454 -> V_58 . V_422 = V_1 -> V_58 . V_422 ;
V_454 -> V_58 . V_267 = V_10 -> V_9 . V_39 . V_267 ;
V_454 -> V_58 . V_307 = F_235 ( & V_10 -> V_9 ) ;
V_454 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_454 -> V_58 . V_456 = V_1 -> V_58 . V_456 ;
V_454 -> V_58 . V_457 = V_1 -> V_58 . V_457 ;
V_454 -> V_58 . V_368 = V_1 -> V_58 . V_368 ;
V_454 -> V_58 . V_261 = V_1 -> V_58 . V_261 ;
V_454 -> V_58 . V_337 = V_1 -> V_58 . V_337 ;
V_454 -> V_2 . V_246 = V_1 -> V_2 . V_246 ;
V_454 -> V_2 . V_451 = V_1 -> V_2 . V_451 ;
V_454 -> V_2 . V_66 = V_1 -> V_2 . V_66 ;
V_454 -> V_2 . V_410 = V_1 -> V_2 . V_410 ;
V_454 -> V_2 . V_412 = V_1 -> V_2 . V_412 ;
V_454 -> V_2 . V_374 = V_1 -> V_2 . V_374 ;
V_454 -> V_2 . V_372 = V_1 -> V_2 . V_372 ;
V_454 -> V_2 . V_452 = V_1 -> V_2 . V_452 ;
V_454 -> V_2 . V_453 = V_1 -> V_2 . V_453 ;
V_454 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_458 = & V_454 -> V_2 ;
V_458 -> V_452 = V_1 -> V_2 . V_90 ;
V_458 -> V_453 = V_1 -> V_2 . V_93 ;
}
V_454 -> V_2 . V_363 = 0 ;
V_454 -> V_2 . V_90 = 0 ;
V_454 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_425 ) )
V_454 -> V_2 . V_246 &= ~ V_247 ;
F_231 ( V_1 , V_18 ) ;
F_236 ( & V_10 -> V_9 ) ;
F_237 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_404 = 0 ;
V_10 -> V_1 -> V_58 . V_248 = V_18 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_249 = V_18 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_250 = V_18 -> V_58 . V_250 ;
V_10 -> V_1 -> V_58 . V_255 = V_18 -> V_58 . V_255 ;
V_10 -> V_1 -> V_58 . V_256 = V_18 -> V_58 . V_256 ;
F_110 ( & V_10 -> V_9 , V_18 -> V_58 . V_307 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_111 ( & V_10 -> V_9 , V_18 -> V_58 . V_342 | V_459 ) ;
F_157 ( & V_10 -> V_9 , V_18 -> V_58 . V_267 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_272 = V_18 -> V_58 . V_272 ;
V_10 -> V_9 . V_39 . V_272 = V_18 -> V_58 . V_272 ;
} else {
( void ) F_238 ( & V_10 -> V_9 , V_18 -> V_58 . V_272 ) ;
}
F_116 ( & V_10 -> V_9 , V_460 , V_18 -> V_58 . V_457 ) ;
F_116 ( & V_10 -> V_9 , V_461 , V_18 -> V_58 . V_456 ) ;
F_116 ( & V_10 -> V_9 , V_263 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_368 = 0 ;
V_10 -> V_1 -> V_58 . V_337 = 0 ;
V_10 -> V_1 -> V_2 . V_452 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_223 ( V_163 ) ;
F_211 ( & V_10 -> V_9 ) ;
F_112 ( & V_10 -> V_9 ) ;
F_239 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_240 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_230 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_156 ; V_44 ++ ) {
T_1 V_366 , V_462 ;
T_2 V_43 ;
if ( V_157 [ V_44 ] == 0xffffffff )
break;
V_462 = V_157 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_436 + ( V_462 * 4 ) ;
if ( F_227 ( & V_10 -> V_9 , V_43 , & V_366 , 4 ) )
return false ;
V_10 -> V_17 . V_147 [ V_462 ] = V_10 -> V_147 [ V_462 ] | V_366 ;
}
V_10 -> V_1 -> V_2 . V_245 = F_109 ( V_10 -> V_17 . V_147 ) ;
return true ;
}
static bool F_241 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_233 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_269 && ! V_55 )
return false ;
return true ;
}
static bool F_242 ( struct V_7 * V_10 )
{
struct V_1 * V_454 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
T_2 V_463 ;
V_463 = V_10 -> V_1 -> V_58 . V_457 ;
V_454 = F_218 ( V_10 , V_10 -> V_1 -> V_58 . V_457 , & V_163 ) ;
if ( ! V_454 )
return false ;
if ( ! F_241 ( V_454 ) ) {
V_454 -> V_2 . V_410 = V_445 ;
V_454 -> V_2 . V_412 = 0 ;
V_454 -> V_2 . V_374 = 0 ;
V_454 -> V_2 . V_372 = 0 ;
F_223 ( V_163 ) ;
return false ;
}
F_243 ( V_10 -> V_1 -> V_58 . V_84 , V_463 ,
V_454 -> V_58 . V_84 ,
V_454 -> V_2 . V_246 ,
V_454 -> V_2 . V_90 ,
V_454 -> V_2 . V_269 ) ;
F_244 ( V_454 -> V_2 . V_19 & 0xffff ,
V_454 -> V_2 . V_19 >> 16 ,
V_454 -> V_2 . V_21 ,
V_454 -> V_2 . V_22 ) ;
F_236 ( & V_10 -> V_9 ) ;
F_237 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_18 -> V_58 . V_250 = V_1 -> V_58 . V_250 ;
V_18 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_18 -> V_58 . V_256 = V_1 -> V_58 . V_256 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_342 = F_234 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_267 = V_10 -> V_9 . V_39 . V_267 ;
V_18 -> V_58 . V_307 = F_235 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_36 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_456 = V_1 -> V_58 . V_456 ;
V_18 -> V_58 . V_457 = V_1 -> V_58 . V_457 ;
if ( V_55 )
V_18 -> V_58 . V_272 = V_1 -> V_58 . V_272 ;
else
V_18 -> V_58 . V_272 = F_140 ( & V_10 -> V_9 ) ;
F_231 ( V_18 , V_1 ) ;
if ( F_235 ( & V_10 -> V_9 ) & V_464 )
V_10 -> V_9 . V_39 . V_40 |= V_426 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_426 ;
if ( V_454 -> V_2 . V_269 ) {
F_245 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_404 = V_454 -> V_2 . V_404 ;
F_207 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_248 = V_454 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_87 = V_454 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_249 = V_454 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_250 = V_454 -> V_58 . V_250 ;
V_10 -> V_1 -> V_58 . V_255 = V_454 -> V_58 . V_255 ;
V_10 -> V_1 -> V_58 . V_256 = V_454 -> V_58 . V_256 ;
F_110 ( & V_10 -> V_9 , V_454 -> V_58 . V_307 ) ;
F_27 ( & V_10 -> V_9 , V_454 -> V_58 . V_54 ) ;
F_111 ( & V_10 -> V_9 , V_454 -> V_58 . V_342 ) ;
F_157 ( & V_10 -> V_9 , V_454 -> V_58 . V_267 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_272 = V_454 -> V_58 . V_272 ;
V_10 -> V_9 . V_39 . V_272 = V_454 -> V_58 . V_272 ;
} else
( void ) F_238 ( & V_10 -> V_9 , V_454 -> V_58 . V_272 ) ;
F_112 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_422 = V_10 -> V_9 . V_39 . V_422 = V_454 -> V_58 . V_422 ;
F_116 ( & V_10 -> V_9 , V_460 , V_454 -> V_58 . V_457 ) ;
F_116 ( & V_10 -> V_9 , V_461 , V_454 -> V_58 . V_456 ) ;
F_116 ( & V_10 -> V_9 , V_263 , V_454 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_457 = V_454 -> V_58 . V_457 ;
V_10 -> V_1 -> V_58 . V_456 = V_454 -> V_58 . V_456 ;
V_10 -> V_1 -> V_58 . V_84 = V_454 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_368 = V_454 -> V_58 . V_368 ;
V_10 -> V_1 -> V_58 . V_261 = V_454 -> V_58 . V_261 ;
V_10 -> V_1 -> V_58 . V_337 = V_454 -> V_58 . V_337 ;
V_10 -> V_17 . V_436 = V_454 -> V_2 . V_245 & ~ 0x0fffULL ;
V_10 -> V_17 . V_434 = V_454 -> V_2 . V_244 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_454 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_454 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_454 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_454 -> V_2 . V_22 ;
F_159 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_246 = V_454 -> V_2 . V_246 | V_247 ;
if ( V_454 -> V_2 . V_246 & V_247 )
V_10 -> V_9 . V_39 . V_40 |= V_425 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_425 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_425 ) {
F_10 ( V_10 , V_465 ) ;
F_10 ( V_10 , V_215 ) ;
}
F_17 ( V_10 , V_234 ) ;
V_10 -> V_1 -> V_2 . V_158 = V_454 -> V_2 . V_158 ;
V_10 -> V_1 -> V_2 . V_451 = V_454 -> V_2 . V_451 ;
V_10 -> V_1 -> V_2 . V_66 = V_454 -> V_2 . V_66 ;
V_10 -> V_1 -> V_2 . V_200 += V_454 -> V_2 . V_200 ;
V_10 -> V_1 -> V_2 . V_90 = V_454 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_454 -> V_2 . V_93 ;
F_223 ( V_163 ) ;
F_246 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_463 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_247 ( struct V_1 * V_448 , struct V_1 * V_466 )
{
V_466 -> V_58 . V_251 = V_448 -> V_58 . V_251 ;
V_466 -> V_58 . V_252 = V_448 -> V_58 . V_252 ;
V_466 -> V_58 . V_259 = V_448 -> V_58 . V_259 ;
V_466 -> V_58 . V_257 = V_448 -> V_58 . V_257 ;
V_466 -> V_58 . V_467 = V_448 -> V_58 . V_467 ;
V_466 -> V_58 . V_468 = V_448 -> V_58 . V_468 ;
V_466 -> V_58 . V_469 = V_448 -> V_58 . V_469 ;
V_466 -> V_58 . V_470 = V_448 -> V_58 . V_470 ;
V_466 -> V_58 . V_471 = V_448 -> V_58 . V_471 ;
V_466 -> V_58 . V_472 = V_448 -> V_58 . V_472 ;
V_466 -> V_58 . V_473 = V_448 -> V_58 . V_473 ;
V_466 -> V_58 . V_474 = V_448 -> V_58 . V_474 ;
}
static int F_248 ( struct V_7 * V_10 )
{
struct V_1 * V_454 ;
struct V_163 * V_163 ;
if ( F_212 ( V_10 ) )
return 1 ;
V_454 = F_218 ( V_10 , V_10 -> V_1 -> V_58 . V_457 , & V_163 ) ;
if ( ! V_454 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_247 ( V_454 , V_10 -> V_1 ) ;
F_223 ( V_163 ) ;
return 1 ;
}
static int F_249 ( struct V_7 * V_10 )
{
struct V_1 * V_454 ;
struct V_163 * V_163 ;
if ( F_212 ( V_10 ) )
return 1 ;
V_454 = F_218 ( V_10 , V_10 -> V_1 -> V_58 . V_457 , & V_163 ) ;
if ( ! V_454 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_247 ( V_10 -> V_1 , V_454 ) ;
F_223 ( V_163 ) ;
return 1 ;
}
static int F_250 ( struct V_7 * V_10 )
{
if ( F_212 ( V_10 ) )
return 1 ;
F_37 ( & V_10 -> V_9 , F_36 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_242 ( V_10 ) )
return 1 ;
if ( ! F_240 ( V_10 ) )
goto V_475;
return 1 ;
V_475:
V_10 -> V_1 -> V_2 . V_410 = V_445 ;
V_10 -> V_1 -> V_2 . V_412 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = 0 ;
V_10 -> V_1 -> V_2 . V_372 = 0 ;
F_206 ( V_10 ) ;
return 1 ;
}
static int F_251 ( struct V_7 * V_10 )
{
if ( F_212 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_187 ( V_476 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_252 ( struct V_7 * V_10 )
{
if ( F_212 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_142 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_477 ;
F_3 ( V_10 -> V_1 , V_478 ) ;
return 1 ;
}
static int F_253 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_254 ( V_10 -> V_1 -> V_58 . V_84 , F_255 ( & V_10 -> V_9 , V_435 ) ,
F_255 ( & V_10 -> V_9 , V_460 ) ) ;
F_256 ( V_9 , F_255 ( & V_10 -> V_9 , V_460 ) ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_257 ( struct V_7 * V_10 )
{
F_258 ( V_10 -> V_1 -> V_58 . V_84 , F_255 ( & V_10 -> V_9 , V_460 ) ) ;
F_178 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static int F_259 ( struct V_7 * V_10 )
{
F_260 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_261 ( struct V_7 * V_10 )
{
T_2 V_479 = F_262 ( & V_10 -> V_9 ) ;
T_1 V_145 = F_255 ( & V_10 -> V_9 , V_435 ) ;
if ( F_263 ( & V_10 -> V_9 , V_145 , V_479 ) == 0 ) {
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_264 ( struct V_7 * V_10 )
{
T_10 V_480 ;
int V_481 ;
int V_482 = V_10 -> V_1 -> V_2 . V_452 &
V_483 ;
int V_484 = V_10 -> V_1 -> V_2 . V_452 & V_485 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_452 & V_483 ;
T_7 V_486 =
V_10 -> V_1 -> V_2 . V_452 & V_487 ;
bool V_80 = false ;
T_1 V_81 = 0 ;
V_480 = ( T_10 ) V_10 -> V_1 -> V_2 . V_374 ;
if ( V_10 -> V_1 -> V_2 . V_372 &
( 1ULL << V_488 ) )
V_481 = V_489 ;
else if ( V_10 -> V_1 -> V_2 . V_372 &
( 1ULL << V_490 ) )
V_481 = V_491 ;
else if ( V_486 )
V_481 = V_492 ;
else
V_481 = V_493 ;
if ( V_481 == V_492 ) {
switch ( type ) {
case V_494 :
V_10 -> V_9 . V_39 . V_495 = false ;
break;
case V_496 :
if ( V_10 -> V_1 -> V_2 . V_372 &
( 1ULL << V_497 ) ) {
V_80 = true ;
V_81 =
( T_1 ) V_10 -> V_1 -> V_2 . V_372 ;
}
F_236 ( & V_10 -> V_9 ) ;
break;
case V_498 :
F_237 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_481 != V_492 ||
V_482 == V_499 ||
( V_482 == V_496 &&
( V_484 == V_500 || V_484 == V_83 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_482 != V_499 )
V_484 = - 1 ;
if ( F_265 ( & V_10 -> V_9 , V_480 , V_484 , V_481 ,
V_80 , V_81 ) == V_501 ) {
V_10 -> V_9 . V_380 -> V_383 = V_502 ;
V_10 -> V_9 . V_380 -> V_503 . V_504 = V_505 ;
V_10 -> V_9 . V_380 -> V_503 . V_506 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_266 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_267 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_268 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_302 . V_507 ;
F_17 ( V_10 , V_508 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_509 ;
V_10 -> V_510 = F_36 ( & V_10 -> V_9 ) ;
F_187 ( V_476 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_269 ( struct V_7 * V_10 )
{
if ( ! F_33 ( V_511 ) )
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
F_256 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_374 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_270 ( struct V_7 * V_10 )
{
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
}
static int F_271 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_33 ( V_72 ) )
return F_270 ( V_10 ) ;
V_96 = F_272 ( & V_10 -> V_9 ) ;
F_273 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static bool F_274 ( struct V_7 * V_10 ,
unsigned long V_97 )
{
unsigned long V_342 = V_10 -> V_9 . V_39 . V_342 ;
bool V_65 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_222 ) ) ) )
return false ;
V_342 &= ~ V_344 ;
V_97 &= ~ V_344 ;
if ( V_342 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_410 = V_512 ;
V_65 = ( F_230 ( V_10 ) == V_423 ) ;
}
return V_65 ;
}
static int F_275 ( struct V_7 * V_10 )
{
int V_309 , V_513 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_33 ( V_511 ) )
return F_270 ( V_10 ) ;
if ( F_127 ( ( V_10 -> V_1 -> V_2 . V_374 & V_514 ) == 0 ) )
return F_270 ( V_10 ) ;
V_309 = V_10 -> V_1 -> V_2 . V_374 & V_515 ;
if ( V_10 -> V_1 -> V_2 . V_410 == V_512 )
V_513 = V_516 - V_440 ;
else
V_513 = V_10 -> V_1 -> V_2 . V_410 - V_440 ;
V_96 = 0 ;
if ( V_513 >= 16 ) {
V_513 -= 16 ;
V_97 = F_255 ( & V_10 -> V_9 , V_309 ) ;
switch ( V_513 ) {
case 0 :
if ( ! F_274 ( V_10 , V_97 ) )
V_96 = F_276 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_238 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_277 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_278 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_99 ( 1 , L_12 , V_513 ) ;
F_178 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
} else {
switch ( V_513 ) {
case 0 :
V_97 = F_234 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_422 ;
break;
case 3 :
V_97 = F_140 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_279 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_280 ( & V_10 -> V_9 ) ;
break;
default:
F_99 ( 1 , L_13 , V_513 ) ;
F_178 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
F_116 ( & V_10 -> V_9 , V_309 , V_97 ) ;
}
F_273 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_281 ( struct V_7 * V_10 )
{
int V_309 , V_517 ;
unsigned long V_97 ;
if ( V_10 -> V_9 . V_358 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_369 |= V_370 ;
return 1 ;
}
if ( ! F_85 ( V_511 ) )
return F_270 ( V_10 ) ;
V_309 = V_10 -> V_1 -> V_2 . V_374 & V_515 ;
V_517 = V_10 -> V_1 -> V_2 . V_410 - V_442 ;
if ( V_517 >= 16 ) {
if ( ! F_282 ( & V_10 -> V_9 , V_517 - 16 ) )
return 1 ;
V_97 = F_255 ( & V_10 -> V_9 , V_309 ) ;
F_283 ( & V_10 -> V_9 , V_517 - 16 , V_97 ) ;
} else {
if ( ! F_282 ( & V_10 -> V_9 , V_517 ) )
return 1 ;
F_284 ( & V_10 -> V_9 , V_517 , & V_97 ) ;
F_116 ( & V_10 -> V_9 , V_309 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_285 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
int V_141 ;
T_4 V_518 = F_280 ( & V_10 -> V_9 ) ;
V_141 = F_275 ( V_10 ) ;
if ( F_286 ( V_10 -> V_9 . V_283 ) )
return V_141 ;
if ( V_518 <= F_280 ( & V_10 -> V_9 ) )
return V_141 ;
V_379 -> V_383 = V_519 ;
return 0 ;
}
static T_2 F_287 ( struct V_8 * V_9 , T_2 V_520 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_200 +
F_97 ( V_9 , V_520 ) ;
}
static int F_288 ( struct V_8 * V_9 , struct V_521 * V_522 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_522 -> V_145 ) {
case V_523 : {
V_522 -> V_524 = V_10 -> V_1 -> V_2 . V_200 +
F_97 ( V_9 , F_107 () ) ;
break;
}
case V_525 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_468 ;
break;
#ifdef F_26
case V_526 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_469 ;
break;
case V_527 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_470 ;
break;
case V_304 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_467 ;
break;
case V_528 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_471 ;
break;
#endif
case V_529 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_472 ;
break;
case V_530 :
V_522 -> V_524 = V_10 -> V_474 ;
break;
case V_531 :
V_522 -> V_524 = V_10 -> V_473 ;
break;
case V_532 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_533 ;
break;
case V_159 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_534 ;
break;
case V_160 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_535 ;
break;
case V_161 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_536 ;
break;
case V_162 :
V_522 -> V_524 = V_10 -> V_1 -> V_58 . V_537 ;
break;
case V_132 :
V_522 -> V_524 = V_10 -> V_17 . V_538 ;
break;
case V_539 :
V_522 -> V_524 = V_10 -> V_17 . V_540 ;
break;
case V_541 :
V_522 -> V_524 = 0x01000065 ;
break;
default:
return F_289 ( V_9 , V_522 ) ;
}
return 0 ;
}
static int F_290 ( struct V_7 * V_10 )
{
T_1 V_542 = F_255 ( & V_10 -> V_9 , V_435 ) ;
struct V_521 V_522 ;
V_522 . V_145 = V_542 ;
V_522 . V_543 = false ;
if ( F_288 ( & V_10 -> V_9 , & V_522 ) ) {
F_291 ( V_542 ) ;
F_213 ( & V_10 -> V_9 , 0 ) ;
} else {
F_292 ( V_542 , V_522 . V_524 ) ;
F_116 ( & V_10 -> V_9 , V_460 ,
V_522 . V_524 & 0xffffffff ) ;
F_116 ( & V_10 -> V_9 , V_282 ,
V_522 . V_524 >> 32 ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_293 ( struct V_8 * V_9 , T_2 V_524 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_544 , V_545 ;
if ( V_524 & ~ V_546 )
return 1 ;
V_545 = V_546 ;
if ( V_10 -> V_17 . V_540 & V_547 )
V_545 &= ~ ( V_548 | V_547 ) ;
V_10 -> V_17 . V_540 &= ~ V_545 ;
V_10 -> V_17 . V_540 |= ( V_524 & V_545 ) ;
V_544 = V_10 -> V_17 . V_540 & V_547 ;
if ( V_544 && ( V_9 -> V_39 . V_54 & V_59 ) )
return 1 ;
return 0 ;
}
static int F_294 ( struct V_8 * V_9 , struct V_521 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_542 = V_42 -> V_145 ;
T_2 V_524 = V_42 -> V_524 ;
switch ( V_542 ) {
case V_523 :
F_295 ( V_9 , V_42 ) ;
break;
case V_525 :
V_10 -> V_1 -> V_58 . V_468 = V_524 ;
break;
#ifdef F_26
case V_526 :
V_10 -> V_1 -> V_58 . V_469 = V_524 ;
break;
case V_527 :
V_10 -> V_1 -> V_58 . V_470 = V_524 ;
break;
case V_304 :
V_10 -> V_1 -> V_58 . V_467 = V_524 ;
break;
case V_528 :
V_10 -> V_1 -> V_58 . V_471 = V_524 ;
break;
#endif
case V_529 :
V_10 -> V_1 -> V_58 . V_472 = V_524 ;
break;
case V_530 :
V_10 -> V_474 = V_524 ;
V_10 -> V_1 -> V_58 . V_474 = V_524 ;
break;
case V_531 :
V_10 -> V_473 = V_524 ;
V_10 -> V_1 -> V_58 . V_473 = V_524 ;
break;
case V_532 :
if ( ! F_85 ( V_549 ) ) {
F_296 ( V_9 , L_14 ,
V_76 , V_524 ) ;
break;
}
if ( V_524 & V_550 )
return 1 ;
V_10 -> V_1 -> V_58 . V_533 = V_524 ;
F_3 ( V_10 -> V_1 , V_551 ) ;
if ( V_524 & ( 1ULL << 0 ) )
F_80 ( V_10 ) ;
else
F_81 ( V_10 ) ;
break;
case V_132 :
V_10 -> V_17 . V_538 = V_524 ;
break;
case V_539 :
return F_293 ( V_9 , V_524 ) ;
case V_552 :
F_296 ( V_9 , L_15 , V_542 , V_524 ) ;
break;
default:
return F_297 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_298 ( struct V_7 * V_10 )
{
struct V_521 V_42 ;
T_1 V_542 = F_255 ( & V_10 -> V_9 , V_435 ) ;
T_2 V_524 = F_262 ( & V_10 -> V_9 ) ;
V_42 . V_524 = V_524 ;
V_42 . V_145 = V_542 ;
V_42 . V_543 = false ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
if ( F_299 ( & V_10 -> V_9 , & V_42 ) ) {
F_300 ( V_542 , V_524 ) ;
F_213 ( & V_10 -> V_9 , 0 ) ;
} else {
F_301 ( V_542 , V_524 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_302 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_374 )
return F_298 ( V_10 ) ;
else
return F_290 ( V_10 ) ;
}
static int F_303 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
F_187 ( V_476 , & V_10 -> V_9 ) ;
F_142 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_477 ;
F_3 ( V_10 -> V_1 , V_478 ) ;
++ V_10 -> V_9 . V_302 . V_553 ;
if ( ! F_286 ( V_10 -> V_9 . V_283 ) &&
V_379 -> V_554 &&
! F_304 ( & V_10 -> V_9 ) ) {
V_379 -> V_383 = V_555 ;
return 0 ;
}
return 1 ;
}
static int F_305 ( struct V_7 * V_10 )
{
F_306 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_307 ( struct V_7 * V_10 )
{
F_31 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_308 ( struct V_7 * V_10 )
{
F_309 ( V_556 L_16 ) ;
return F_307 ( V_10 ) ;
}
static int F_310 ( struct V_7 * V_10 )
{
F_309 ( V_556 L_17 ) ;
return F_307 ( V_10 ) ;
}
static void F_311 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_207 * V_58 = & V_10 -> V_1 -> V_58 ;
F_56 ( L_18 ) ;
F_56 ( L_19 , L_20 , V_2 -> V_19 & 0xffff ) ;
F_56 ( L_19 , L_21 , V_2 -> V_19 >> 16 ) ;
F_56 ( L_19 , L_22 , V_2 -> V_20 & 0xffff ) ;
F_56 ( L_19 , L_23 , V_2 -> V_20 >> 16 ) ;
F_56 ( L_24 , L_25 , V_2 -> V_21 ) ;
F_56 ( L_26 , L_27 , V_2 -> V_22 ) ;
F_56 ( L_28 , L_29 , V_2 -> V_274 ) ;
F_56 ( L_26 , L_30 , V_2 -> V_244 ) ;
F_56 ( L_26 , L_31 , V_2 -> V_245 ) ;
F_56 ( L_26 , L_32 , V_2 -> V_200 ) ;
F_56 ( L_28 , L_33 , V_2 -> V_51 ) ;
F_56 ( L_28 , L_34 , V_2 -> V_363 ) ;
F_56 ( L_24 , L_35 , V_2 -> V_246 ) ;
F_56 ( L_24 , L_36 , V_2 -> V_451 ) ;
F_56 ( L_24 , L_37 , V_2 -> V_66 ) ;
F_56 ( L_24 , L_38 , V_2 -> V_410 ) ;
F_56 ( L_26 , L_39 , V_2 -> V_374 ) ;
F_56 ( L_26 , L_40 , V_2 -> V_372 ) ;
F_56 ( L_24 , L_41 , V_2 -> V_452 ) ;
F_56 ( L_24 , L_42 , V_2 -> V_453 ) ;
F_56 ( L_43 , L_44 , V_2 -> V_269 ) ;
F_56 ( L_26 , L_45 , V_2 -> V_404 ) ;
F_56 ( L_24 , L_46 , V_2 -> V_90 ) ;
F_56 ( L_24 , L_47 , V_2 -> V_93 ) ;
F_56 ( L_43 , L_48 , V_2 -> V_158 ) ;
F_56 ( L_26 , L_49 , V_2 -> V_71 ) ;
F_56 ( L_50 ) ;
F_56 ( L_51 ,
L_52 ,
V_58 -> V_248 . V_182 , V_58 -> V_248 . V_183 ,
V_58 -> V_248 . V_187 , V_58 -> V_248 . V_88 ) ;
F_56 ( L_51 ,
L_53 ,
V_58 -> V_87 . V_182 , V_58 -> V_87 . V_183 ,
V_58 -> V_87 . V_187 , V_58 -> V_87 . V_88 ) ;
F_56 ( L_51 ,
L_54 ,
V_58 -> V_249 . V_182 , V_58 -> V_249 . V_183 ,
V_58 -> V_249 . V_187 , V_58 -> V_249 . V_88 ) ;
F_56 ( L_51 ,
L_55 ,
V_58 -> V_250 . V_182 , V_58 -> V_250 . V_183 ,
V_58 -> V_250 . V_187 , V_58 -> V_250 . V_88 ) ;
F_56 ( L_51 ,
L_56 ,
V_58 -> V_251 . V_182 , V_58 -> V_251 . V_183 ,
V_58 -> V_251 . V_187 , V_58 -> V_251 . V_88 ) ;
F_56 ( L_51 ,
L_57 ,
V_58 -> V_252 . V_182 , V_58 -> V_252 . V_183 ,
V_58 -> V_252 . V_187 , V_58 -> V_252 . V_88 ) ;
F_56 ( L_51 ,
L_58 ,
V_58 -> V_255 . V_182 , V_58 -> V_255 . V_183 ,
V_58 -> V_255 . V_187 , V_58 -> V_255 . V_88 ) ;
F_56 ( L_51 ,
L_59 ,
V_58 -> V_257 . V_182 , V_58 -> V_257 . V_183 ,
V_58 -> V_257 . V_187 , V_58 -> V_257 . V_88 ) ;
F_56 ( L_51 ,
L_60 ,
V_58 -> V_256 . V_182 , V_58 -> V_256 . V_183 ,
V_58 -> V_256 . V_187 , V_58 -> V_256 . V_88 ) ;
F_56 ( L_51 ,
L_61 ,
V_58 -> V_259 . V_182 , V_58 -> V_259 . V_183 ,
V_58 -> V_259 . V_187 , V_58 -> V_259 . V_88 ) ;
F_56 ( L_62 ,
V_58 -> V_337 , V_58 -> V_54 ) ;
F_56 ( L_63 ,
L_64 , V_58 -> V_342 , L_65 , V_58 -> V_422 ) ;
F_56 ( L_63 ,
L_66 , V_58 -> V_272 , L_67 , V_58 -> V_267 ) ;
F_56 ( L_63 ,
L_68 , V_58 -> V_261 , L_69 , V_58 -> V_368 ) ;
F_56 ( L_63 ,
L_70 , V_58 -> V_84 , L_71 , V_58 -> V_307 ) ;
F_56 ( L_63 ,
L_72 , V_58 -> V_456 , L_73 , V_58 -> V_457 ) ;
F_56 ( L_63 ,
L_74 , V_58 -> V_468 , L_75 , V_58 -> V_469 ) ;
F_56 ( L_63 ,
L_76 , V_58 -> V_470 , L_77 , V_58 -> V_471 ) ;
F_56 ( L_63 ,
L_78 , V_58 -> V_467 ,
L_79 , V_58 -> V_472 ) ;
F_56 ( L_63 ,
L_80 , V_58 -> V_473 ,
L_81 , V_58 -> V_474 ) ;
F_56 ( L_63 ,
L_82 , V_58 -> V_270 , L_83 , V_58 -> V_533 ) ;
F_56 ( L_63 ,
L_84 , V_58 -> V_534 , L_85 , V_58 -> V_535 ) ;
F_56 ( L_63 ,
L_86 , V_58 -> V_536 ,
L_87 , V_58 -> V_537 ) ;
}
static void F_312 ( struct V_8 * V_9 , T_2 * V_557 , T_2 * V_558 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_557 = V_2 -> V_374 ;
* V_558 = V_2 -> V_372 ;
}
static int F_313 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_379 * V_379 = V_9 -> V_380 ;
T_1 V_410 = V_10 -> V_1 -> V_2 . V_410 ;
if ( ! F_11 ( V_10 , V_212 ) )
V_9 -> V_39 . V_342 = V_10 -> V_1 -> V_58 . V_342 ;
if ( V_55 )
V_9 -> V_39 . V_272 = V_10 -> V_1 -> V_58 . V_272 ;
if ( F_127 ( V_10 -> V_17 . V_424 ) ) {
F_206 ( V_10 ) ;
V_10 -> V_17 . V_424 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_420 ;
F_314 ( V_10 -> V_1 -> V_58 . V_84 , V_410 ,
V_10 -> V_1 -> V_2 . V_374 ,
V_10 -> V_1 -> V_2 . V_372 ,
V_10 -> V_1 -> V_2 . V_452 ,
V_10 -> V_1 -> V_2 . V_453 ,
V_455 ) ;
V_420 = F_229 ( V_10 ) ;
if ( V_420 == V_437 )
V_420 = F_230 ( V_10 ) ;
if ( V_420 == V_423 )
return 1 ;
}
F_315 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_410 == V_445 ) {
V_379 -> V_383 = V_559 ;
V_379 -> V_560 . V_561
= V_10 -> V_1 -> V_2 . V_410 ;
F_56 ( L_88 ) ;
F_311 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_452 ) &&
V_410 != V_421 + V_216 &&
V_410 != V_411 && V_410 != V_562 &&
V_410 != V_427 && V_410 != V_428 )
F_35 ( V_78 L_89
L_90 ,
V_76 , V_10 -> V_1 -> V_2 . V_452 ,
V_410 ) ;
if ( V_410 >= F_316 ( V_563 )
|| ! V_563 [ V_410 ] ) {
F_101 ( 1 , L_91 , V_410 ) ;
F_178 ( V_9 , V_217 ) ;
return 1 ;
}
return V_563 [ V_410 ] ( V_10 ) ;
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
F_162 ( V_10 , V_114 ) ;
}
static void F_320 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_564 ;
V_9 -> V_39 . V_40 |= V_565 ;
F_16 ( V_10 , V_508 ) ;
++ V_9 -> V_302 . V_566 ;
}
static inline void F_321 ( struct V_7 * V_10 , int V_567 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_451 = V_567 ;
V_2 -> V_246 &= ~ V_568 ;
V_2 -> V_246 |= V_477 |
( ( 0xf ) << V_569 ) ;
F_3 ( V_10 -> V_1 , V_478 ) ;
}
static void F_322 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_73 ( ! ( F_20 ( V_10 ) ) ) ;
F_323 ( V_9 -> V_39 . V_570 . V_79 ) ;
++ V_9 -> V_302 . V_571 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_570 . V_79 |
V_63 | V_64 ;
}
static void F_324 ( struct V_8 * V_9 , int V_572 , int V_573 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_425 ) )
return;
F_10 ( V_10 , V_215 ) ;
if ( V_573 == - 1 )
return;
if ( V_572 >= V_573 )
F_9 ( V_10 , V_215 ) ;
}
static void F_325 ( struct V_8 * V_9 , bool V_574 )
{
return;
}
static int F_326 ( struct V_283 * V_283 )
{
return 0 ;
}
static void F_327 ( struct V_8 * V_9 , T_2 * V_575 )
{
return;
}
static void F_328 ( struct V_8 * V_9 )
{
return;
}
static int F_329 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
V_65 = ! ( V_1 -> V_2 . V_66 & V_67 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_565 ) ;
V_65 = V_65 && F_20 ( V_10 ) && F_217 ( V_10 ) ;
return V_65 ;
}
static bool F_330 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_565 ) ;
}
static void F_331 ( struct V_8 * V_9 , bool V_576 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_576 ) {
V_10 -> V_9 . V_39 . V_40 |= V_565 ;
F_16 ( V_10 , V_508 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_565 ;
F_17 ( V_10 , V_508 ) ;
}
}
static int F_332 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_66 & V_67 ) )
return 0 ;
V_65 = ! ! ( F_235 ( V_9 ) & V_464 ) ;
if ( F_7 ( V_9 ) )
return V_65 && ! ( V_10 -> V_9 . V_39 . V_40 & V_425 ) ;
return V_65 ;
}
static void F_333 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_215 ( V_10 ) ) {
F_141 ( V_10 ) ;
F_321 ( V_10 , 0x0 ) ;
}
}
static void F_334 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_565 | V_509 ) )
== V_565 )
return;
V_10 -> V_357 = true ;
V_10 -> V_1 -> V_58 . V_307 |= ( V_381 | V_382 ) ;
F_161 ( V_9 ) ;
}
static int F_335 ( struct V_283 * V_283 , unsigned int V_50 )
{
return 0 ;
}
static void F_159 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_33 ( V_577 ) )
V_10 -> V_1 -> V_2 . V_363 = V_578 ;
else
V_10 -> V_124 -- ;
}
static void F_336 ( struct V_8 * V_9 )
{
}
static inline void F_337 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_425 ) )
return;
if ( ! F_11 ( V_10 , V_215 ) ) {
int V_579 = V_10 -> V_1 -> V_2 . V_246 & V_580 ;
F_278 ( V_9 , V_579 ) ;
}
}
static inline void F_338 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_579 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_425 ) )
return;
V_579 = F_280 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_580 ;
V_10 -> V_1 -> V_2 . V_246 |= V_579 & V_580 ;
}
static void F_315 ( struct V_7 * V_10 )
{
T_4 V_581 ;
int type ;
T_1 V_582 = V_10 -> V_1 -> V_2 . V_452 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_509 )
&& F_36 ( & V_10 -> V_9 ) != V_10 -> V_510 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_565 | V_509 ) ;
F_187 ( V_476 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_495 = false ;
F_236 ( & V_10 -> V_9 ) ;
F_237 ( & V_10 -> V_9 ) ;
if ( ! ( V_582 & V_487 ) )
return;
F_187 ( V_476 , & V_10 -> V_9 ) ;
V_581 = V_582 & V_583 ;
type = V_582 & V_483 ;
switch ( type ) {
case V_494 :
V_10 -> V_9 . V_39 . V_495 = true ;
break;
case V_496 :
if ( F_339 ( V_581 ) ) {
if ( V_581 == V_83 && V_89 &&
F_340 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_37 ( & V_10 -> V_9 ,
F_36 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_582 & V_584 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_453 ;
F_341 ( & V_10 -> V_9 , V_581 , V_96 ) ;
} else
F_342 ( & V_10 -> V_9 , V_581 ) ;
break;
case V_498 :
F_343 ( & V_10 -> V_9 , V_581 , false ) ;
break;
default:
break;
}
}
static void F_344 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_452 = V_2 -> V_90 ;
V_2 -> V_453 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_315 ( V_10 ) ;
}
static void F_345 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_457 = V_9 -> V_39 . V_262 [ V_460 ] ;
V_10 -> V_1 -> V_58 . V_456 = V_9 -> V_39 . V_262 [ V_461 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_262 [ V_263 ] ;
if ( F_127 ( V_10 -> V_17 . V_424 ) )
return;
F_319 ( V_10 ) ;
F_338 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_422 = V_9 -> V_39 . V_422 ;
F_22 () ;
F_175 () ;
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
F_50 ( V_296 , V_10 -> V_204 . V_297 ) ;
#else
F_133 ( V_251 , V_10 -> V_204 . V_251 ) ;
#ifndef F_135
F_133 ( V_252 , V_10 -> V_204 . V_252 ) ;
#endif
#endif
F_317 ( V_9 ) ;
F_173 () ;
V_9 -> V_39 . V_422 = V_10 -> V_1 -> V_58 . V_422 ;
V_9 -> V_39 . V_262 [ V_460 ] = V_10 -> V_1 -> V_58 . V_457 ;
V_9 -> V_39 . V_262 [ V_461 ] = V_10 -> V_1 -> V_58 . V_456 ;
V_9 -> V_39 . V_262 [ V_263 ] = V_10 -> V_1 -> V_58 . V_84 ;
F_346 ( V_10 -> V_1 -> V_2 . V_410 , V_9 , V_455 ) ;
if ( F_127 ( V_10 -> V_1 -> V_2 . V_410 == V_428 ) )
F_347 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_127 ( V_10 -> V_1 -> V_2 . V_410 == V_428 ) )
F_348 ( & V_10 -> V_9 ) ;
F_337 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_363 = V_585 ;
if ( V_10 -> V_1 -> V_2 . V_410 == V_421 + V_216 )
V_10 -> V_373 = F_349 () ;
if ( V_55 ) {
V_9 -> V_39 . V_586 &= ~ ( 1 << V_310 ) ;
V_9 -> V_39 . V_587 &= ~ ( 1 << V_310 ) ;
}
if ( F_127 ( V_10 -> V_1 -> V_2 . V_410 ==
V_421 + V_218 ) )
F_186 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_350 ( struct V_8 * V_9 , unsigned long V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_272 = V_406 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_159 ( V_9 ) ;
}
static void F_351 ( struct V_8 * V_9 , unsigned long V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_404 = V_406 ;
F_3 ( V_10 -> V_1 , V_407 ) ;
V_10 -> V_1 -> V_58 . V_272 = F_140 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_159 ( V_9 ) ;
}
static int F_352 ( void )
{
T_2 V_588 ;
F_55 ( V_539 , V_588 ) ;
if ( V_588 & ( 1 << V_589 ) )
return 1 ;
return 0 ;
}
static void
F_353 ( struct V_8 * V_9 , unsigned char * V_590 )
{
V_590 [ 0 ] = 0x0f ;
V_590 [ 1 ] = 0x01 ;
V_590 [ 2 ] = 0xd9 ;
}
static void F_354 ( void * V_591 )
{
* ( int * ) V_591 = 0 ;
}
static bool F_355 ( void )
{
return false ;
}
static bool F_356 ( void )
{
return true ;
}
static T_2 F_357 ( struct V_8 * V_9 , T_11 V_592 , bool V_593 )
{
return 0 ;
}
static void F_358 ( struct V_8 * V_9 )
{
}
static void F_359 ( T_1 V_594 , struct V_595 * V_596 )
{
switch ( V_594 ) {
case 0x80000001 :
if ( V_17 )
V_596 -> V_542 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_596 -> V_277 = 1 ;
V_596 -> V_597 = 8 ;
V_596 -> V_542 = 0 ;
V_596 -> V_598 = 0 ;
if ( F_85 ( V_72 ) )
V_596 -> V_598 |= V_599 ;
if ( V_55 )
V_596 -> V_598 |= V_600 ;
break;
}
}
static int F_360 ( void )
{
return V_601 ;
}
static bool F_361 ( void )
{
return false ;
}
static bool F_362 ( void )
{
return false ;
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
return true ;
}
static void F_366 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_390 ) ;
F_154 ( V_10 ) ;
}
static int F_367 ( struct V_8 * V_9 ,
struct V_602 * V_61 ,
enum V_603 V_604 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_420 , V_65 = V_605 ;
struct V_606 V_607 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_316 ( V_608 ) )
goto V_289;
V_607 = V_608 [ V_61 -> V_22 ] ;
if ( V_604 != V_607 . V_604 )
goto V_289;
switch ( V_607 . V_410 ) {
case V_440 :
if ( V_61 -> V_22 == V_609 )
V_607 . V_410 += V_61 -> V_610 ;
break;
case V_516 : {
unsigned long V_342 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_611 )
V_607 . V_410 += V_61 -> V_610 ;
if ( V_607 . V_410 != V_516 ||
V_61 -> V_22 == V_612 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_222 ) ) )
break;
V_342 = V_9 -> V_39 . V_342 & ~ V_344 ;
V_97 = V_61 -> V_613 & ~ V_344 ;
if ( V_61 -> V_22 == V_614 ) {
V_342 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_342 & V_459 )
V_97 |= V_459 ;
}
if ( V_342 ^ V_97 )
V_607 . V_410 = V_512 ;
break;
}
case V_442 :
case V_615 :
V_607 . V_410 += V_61 -> V_610 ;
break;
case V_438 :
if ( V_61 -> V_22 == V_616 )
V_1 -> V_2 . V_374 = 1 ;
else
V_1 -> V_2 . V_374 = 0 ;
break;
case V_617 :
if ( V_61 -> V_618 != V_619 )
goto V_289;
case V_439 : {
T_2 V_620 ;
T_1 V_621 ;
if ( V_61 -> V_22 == V_622 ||
V_61 -> V_22 == V_623 ) {
V_620 = ( ( V_61 -> V_613 & 0xffff ) << 16 ) |
V_400 ;
V_621 = V_61 -> V_624 ;
} else {
V_620 = ( V_61 -> V_625 & 0xffff ) << 16 ;
V_621 = V_61 -> V_626 ;
}
if ( V_61 -> V_22 == V_627 ||
V_61 -> V_22 == V_623 )
V_620 |= V_399 ;
if ( V_61 -> V_618 )
V_620 |= V_628 ;
V_621 = F_87 ( V_621 , 4u ) ;
V_620 |= V_621 << V_402 ;
V_620 |= ( T_1 ) V_61 -> V_629 << ( V_630 - 1 ) ;
V_1 -> V_2 . V_374 = V_620 ;
V_1 -> V_2 . V_372 = V_61 -> V_71 ;
break;
}
default:
break;
}
if ( F_33 ( V_72 ) )
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_410 = V_607 . V_410 ;
V_420 = F_230 ( V_10 ) ;
V_65 = ( V_420 == V_423 ) ? V_631
: V_605 ;
V_289:
return V_65 ;
}
static void F_368 ( struct V_8 * V_9 )
{
F_175 () ;
}
static void F_369 ( struct V_8 * V_9 , int V_140 )
{
}
static int T_5 F_370 ( void )
{
return F_371 ( & V_632 , sizeof( struct V_7 ) ,
F_372 ( struct V_7 ) , V_633 ) ;
}
static void T_6 F_373 ( void )
{
F_374 () ;
}
