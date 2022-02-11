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
static T_1 F_29 ( struct V_8 * V_9 , int V_65 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_66 = 0 ;
if ( V_10 -> V_1 -> V_2 . V_67 & V_68 )
V_66 |= V_69 | V_70 ;
return V_66 & V_65 ;
}
static void F_30 ( struct V_8 * V_9 , int V_65 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_65 == 0 )
V_10 -> V_1 -> V_2 . V_67 &= ~ V_68 ;
else
V_10 -> V_1 -> V_2 . V_67 |= V_68 ;
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_71 != 0 )
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_71 ;
if ( ! V_10 -> V_71 ) {
if ( F_32 ( V_9 , V_72 ) !=
V_73 )
F_33 ( V_74 L_1 , V_75 ) ;
return;
}
if ( V_10 -> V_71 - F_34 ( V_9 ) > V_76 )
F_33 ( V_77 L_2 ,
V_75 , F_34 ( V_9 ) , V_10 -> V_71 ) ;
F_35 ( V_9 , V_10 -> V_71 ) ;
F_30 ( V_9 , 0 ) ;
}
static void F_36 ( struct V_8 * V_9 , unsigned V_78 ,
bool V_79 , T_1 V_80 ,
bool V_81 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! V_81 &&
F_37 ( V_10 , V_78 , V_79 , V_80 ) )
return;
if ( V_78 == V_82 && ! F_38 ( V_83 ) ) {
unsigned long V_84 , V_85 = F_34 ( & V_10 -> V_9 ) ;
F_31 ( & V_10 -> V_9 ) ;
V_84 = F_34 ( & V_10 -> V_9 ) ;
V_10 -> V_86 = V_84 + V_10 -> V_1 -> V_58 . V_87 . V_88 ;
V_10 -> V_89 = V_84 - V_85 ;
}
V_10 -> V_1 -> V_2 . V_90 = V_78
| V_63
| ( V_79 ? V_91 : 0 )
| V_92 ;
V_10 -> V_1 -> V_2 . V_93 = V_80 ;
}
static void F_39 ( void )
{
T_1 V_94 , V_95 ;
int V_96 ;
T_2 V_97 ;
if ( ! F_40 ( V_98 ) )
return;
V_97 = F_41 ( V_99 , & V_96 ) ;
if ( V_96 )
return;
V_97 |= ( 1ULL << 47 ) ;
V_94 = F_42 ( V_97 ) ;
V_95 = F_43 ( V_97 ) ;
F_44 ( V_99 , V_94 , V_95 ) ;
V_100 = true ;
}
static void F_45 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_101 . V_102 = ( V_103 >= 3 ) ? ( V_103 ) : 3 ;
V_9 -> V_39 . V_101 . V_104 = V_105 & ~ ( 6ULL ) ;
if ( V_103 == 0 && V_106 . V_107 == 0x10 )
V_9 -> V_39 . V_101 . V_104 |= 1 ;
}
static int F_46 ( void )
{
const char * V_108 ;
if ( ! F_47 ( & V_108 ) ) {
F_33 ( V_109 L_3 , V_108 ) ;
return 0 ;
}
return 1 ;
}
static void F_48 ( void * V_110 )
{
if ( F_38 ( V_111 ) )
F_49 ( V_112 , V_113 ) ;
F_50 () ;
F_51 () ;
}
static int F_52 ( void * V_110 )
{
struct V_114 * V_115 ;
T_3 V_54 ;
struct V_116 V_117 ;
struct V_118 * V_119 ;
int V_120 = F_53 () ;
F_54 ( V_121 , V_54 ) ;
if ( V_54 & V_59 )
return - V_122 ;
if ( ! F_46 () ) {
F_55 ( L_4 , V_75 , V_120 ) ;
return - V_123 ;
}
V_115 = F_56 ( V_124 , V_120 ) ;
if ( ! V_115 ) {
F_55 ( L_5 , V_75 , V_120 ) ;
return - V_123 ;
}
V_115 -> V_125 = 1 ;
V_115 -> V_126 = F_57 ( V_127 ) - 1 ;
V_115 -> V_128 = V_115 -> V_126 + 1 ;
F_58 ( & V_117 ) ;
V_119 = (struct V_118 * ) V_117 . V_129 ;
V_115 -> V_130 = (struct V_131 * ) ( V_119 + V_132 ) ;
F_49 ( V_121 , V_54 | V_59 ) ;
F_49 ( V_133 , F_59 ( V_115 -> V_134 ) << V_135 ) ;
if ( F_38 ( V_111 ) ) {
F_49 ( V_112 , V_113 ) ;
F_60 ( V_136 ) = V_113 ;
}
if ( F_61 ( & V_106 , V_137 ) ) {
T_3 V_138 , V_104 = 0 ;
int V_96 ;
V_138 = F_41 ( V_139 , & V_96 ) ;
if ( ! V_96 )
V_104 = F_41 ( V_140 ,
& V_96 ) ;
if ( V_96 )
V_105 = V_103 = 0 ;
else {
if ( V_138 < V_103 )
V_103 = V_138 ;
V_105 |= V_104 ;
V_105 &= ( 1ULL << V_103 ) - 1 ;
}
} else
V_105 = V_103 = 0 ;
F_39 () ;
F_62 () ;
return 0 ;
}
static void F_63 ( int V_141 )
{
struct V_114 * V_115 = F_56 ( V_124 , F_53 () ) ;
if ( ! V_115 )
return;
F_56 ( V_124 , F_53 () ) = NULL ;
F_64 ( V_115 -> V_134 ) ;
F_65 ( V_115 ) ;
}
static int F_66 ( int V_141 )
{
struct V_114 * V_115 ;
int V_142 ;
V_115 = F_67 ( sizeof( struct V_114 ) , V_143 ) ;
if ( ! V_115 )
return - V_144 ;
V_115 -> V_141 = V_141 ;
V_115 -> V_134 = F_68 ( V_143 ) ;
V_142 = - V_144 ;
if ( ! V_115 -> V_134 )
goto V_145;
F_56 ( V_124 , V_141 ) = V_115 ;
return 0 ;
V_145:
F_65 ( V_115 ) ;
return V_142 ;
}
static bool F_69 ( T_1 V_146 )
{
int V_44 ;
for ( V_44 = 0 ; V_147 [ V_44 ] . V_146 != V_49 ; V_44 ++ )
if ( V_147 [ V_44 ] . V_146 == V_146 )
return true ;
return false ;
}
static void F_70 ( T_1 * V_148 , unsigned V_42 ,
int V_149 , int V_150 )
{
T_4 V_151 , V_152 ;
unsigned long V_153 ;
T_1 V_43 ;
F_71 ( ! F_69 ( V_42 ) ) ;
V_43 = F_21 ( V_42 ) ;
V_151 = 2 * ( V_42 & 0x0f ) ;
V_152 = 2 * ( V_42 & 0x0f ) + 1 ;
V_153 = V_148 [ V_43 ] ;
F_72 ( V_43 == V_49 ) ;
V_149 ? F_73 ( V_151 , & V_153 ) : F_74 ( V_151 , & V_153 ) ;
V_150 ? F_73 ( V_152 , & V_153 ) : F_74 ( V_152 , & V_153 ) ;
V_148 [ V_43 ] = V_153 ;
}
static void F_75 ( T_1 * V_148 )
{
int V_44 ;
memset ( V_148 , 0xff , V_154 * ( 1 << V_155 ) ) ;
for ( V_44 = 0 ; V_147 [ V_44 ] . V_146 != V_49 ; V_44 ++ ) {
if ( ! V_147 [ V_44 ] . V_156 )
continue;
F_70 ( V_148 , V_147 [ V_44 ] . V_146 , 1 , 1 ) ;
}
}
static void F_76 ( T_1 V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_157 ; ++ V_44 ) {
if ( V_158 [ V_44 ] == V_43 )
return;
if ( V_158 [ V_44 ] != V_49 )
continue;
V_158 [ V_44 ] = V_43 ;
return;
}
F_77 () ;
}
static void F_78 ( void )
{
int V_44 ;
memset ( V_158 , 0xff , sizeof( V_158 ) ) ;
for ( V_44 = 0 ; V_147 [ V_44 ] . V_146 != V_49 ; V_44 ++ ) {
T_1 V_43 ;
V_43 = F_21 ( V_147 [ V_44 ] . V_146 ) ;
F_72 ( V_43 == V_49 ) ;
F_76 ( V_43 ) ;
}
}
static void F_79 ( struct V_7 * V_10 )
{
T_1 * V_148 = V_10 -> V_148 ;
V_10 -> V_1 -> V_2 . V_159 = 1 ;
F_70 ( V_148 , V_160 , 1 , 1 ) ;
F_70 ( V_148 , V_161 , 1 , 1 ) ;
F_70 ( V_148 , V_162 , 1 , 1 ) ;
F_70 ( V_148 , V_163 , 1 , 1 ) ;
}
static void F_80 ( struct V_7 * V_10 )
{
T_1 * V_148 = V_10 -> V_148 ;
V_10 -> V_1 -> V_2 . V_159 = 0 ;
F_70 ( V_148 , V_160 , 0 , 0 ) ;
F_70 ( V_148 , V_161 , 0 , 0 ) ;
F_70 ( V_148 , V_162 , 0 , 0 ) ;
F_70 ( V_148 , V_163 , 0 , 0 ) ;
}
static T_5 int F_81 ( void )
{
int V_141 ;
struct V_164 * V_165 ;
void * V_166 ;
int V_142 ;
V_165 = F_82 ( V_143 , V_167 ) ;
if ( ! V_165 )
return - V_144 ;
V_166 = F_83 ( V_165 ) ;
memset ( V_166 , 0xff , V_154 * ( 1 << V_167 ) ) ;
V_168 = F_59 ( V_165 ) << V_135 ;
F_78 () ;
if ( F_84 ( V_169 ) )
F_85 ( V_170 ) ;
if ( F_84 ( V_171 ) )
F_85 ( V_172 ) ;
if ( F_84 ( V_111 ) ) {
T_2 V_173 ;
V_174 = true ;
V_173 = F_86 ( 0x7fffffffULL , F_87 ( V_175 , V_176 ) ) ;
V_177 = V_173 ;
}
if ( V_17 ) {
F_33 ( V_109 L_6 ) ;
F_85 ( V_59 | V_178 ) ;
}
F_88 (cpu) {
V_142 = F_66 ( V_141 ) ;
if ( V_142 )
goto V_96;
}
if ( ! F_84 ( V_179 ) )
V_55 = false ;
if ( V_55 && ! V_180 ) {
F_33 ( V_109 L_7 ) ;
V_55 = false ;
}
if ( V_55 ) {
F_33 ( V_109 L_8 ) ;
F_89 () ;
} else
F_90 () ;
return 0 ;
V_96:
F_91 ( V_165 , V_167 ) ;
V_168 = 0 ;
return V_142 ;
}
static T_6 void F_92 ( void )
{
int V_141 ;
F_88 (cpu)
F_63 ( V_141 ) ;
F_91 ( F_93 ( V_168 >> V_135 ) , V_167 ) ;
V_168 = 0 ;
}
static void F_94 ( struct V_181 * V_182 )
{
V_182 -> V_183 = 0 ;
V_182 -> V_184 = V_185 | V_186 |
V_187 ;
V_182 -> V_188 = 0xffff ;
V_182 -> V_88 = 0 ;
}
static void F_95 ( struct V_181 * V_182 , T_7 type )
{
V_182 -> V_183 = 0 ;
V_182 -> V_184 = V_185 | type ;
V_182 -> V_188 = 0xffff ;
V_182 -> V_88 = 0 ;
}
static T_2 F_87 ( T_2 V_189 , T_2 V_190 )
{
T_2 V_191 , V_192 , V_193 ;
V_191 = V_189 >> 32 ;
V_192 = V_189 & ( ( 1ULL << 32 ) - 1 ) ;
V_193 = V_190 ;
V_193 *= V_191 ;
V_193 += ( V_190 >> 32 ) * V_192 ;
V_193 += ( ( V_190 & ( ( 1ULL << 32 ) - 1 ) ) * V_192 ) >> 32 ;
return V_193 ;
}
static T_2 F_96 ( struct V_8 * V_9 , T_2 V_190 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_193 = V_190 ;
if ( V_10 -> V_194 != V_113 )
V_193 = F_87 ( V_10 -> V_194 , V_190 ) ;
return V_193 ;
}
static void F_97 ( struct V_8 * V_9 , T_1 V_195 , bool V_196 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_189 ;
T_2 V_197 ;
if ( ! V_196 ) {
V_10 -> V_194 = V_113 ;
return;
}
if ( ! F_84 ( V_111 ) ) {
if ( V_195 > V_175 ) {
V_9 -> V_39 . V_198 = 1 ;
V_9 -> V_39 . V_199 = 1 ;
} else
F_98 ( 1 , L_9 ) ;
return;
}
V_197 = V_195 ;
V_189 = V_197 << 32 ;
F_99 ( V_189 , V_175 ) ;
if ( V_189 == 0 || V_189 & V_200 ) {
F_100 ( 1 , L_10 ,
V_195 ) ;
return;
}
V_10 -> V_194 = V_189 ;
}
static T_2 F_101 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_201 ;
}
static void F_102 ( struct V_8 * V_9 , T_2 V_43 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_202 = 0 ;
if ( F_7 ( V_9 ) ) {
V_202 = V_10 -> V_1 -> V_2 . V_201 -
V_10 -> V_17 . V_18 -> V_2 . V_201 ;
V_10 -> V_17 . V_18 -> V_2 . V_201 = V_43 ;
} else
F_103 ( V_9 -> V_203 ,
V_10 -> V_1 -> V_2 . V_201 ,
V_43 ) ;
V_10 -> V_1 -> V_2 . V_201 = V_43 + V_202 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_104 ( struct V_8 * V_9 , T_8 V_204 , bool V_205 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_71 ( V_204 < 0 ) ;
if ( V_205 )
V_204 = F_96 ( V_9 , V_204 ) ;
V_10 -> V_1 -> V_2 . V_201 += V_204 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_201 += V_204 ;
else
F_103 ( V_9 -> V_203 ,
V_10 -> V_1 -> V_2 . V_201 - V_204 ,
V_10 -> V_1 -> V_2 . V_201 ) ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_105 ( struct V_8 * V_9 , T_2 V_206 )
{
T_2 V_190 ;
V_190 = F_96 ( V_9 , F_106 () ) ;
return V_206 - V_190 ;
}
static void F_107 ( struct V_7 * V_10 )
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
V_2 -> V_244 = V_168 ;
V_2 -> V_245 = F_108 ( V_10 -> V_148 ) ;
V_2 -> V_246 = V_247 ;
F_94 ( & V_58 -> V_248 ) ;
F_94 ( & V_58 -> V_249 ) ;
F_94 ( & V_58 -> V_250 ) ;
F_94 ( & V_58 -> V_251 ) ;
F_94 ( & V_58 -> V_252 ) ;
V_58 -> V_87 . V_183 = 0xf000 ;
V_58 -> V_87 . V_88 = 0xffff0000 ;
V_58 -> V_87 . V_184 = V_253 | V_185 |
V_186 | V_254 ;
V_58 -> V_87 . V_188 = 0xffff ;
V_58 -> V_255 . V_188 = 0xffff ;
V_58 -> V_256 . V_188 = 0xffff ;
F_95 ( & V_58 -> V_257 , V_258 ) ;
F_95 ( & V_58 -> V_259 , V_260 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_58 -> V_261 = 0xffff0ff0 ;
F_109 ( & V_10 -> V_9 , 2 ) ;
V_58 -> V_84 = 0x0000fff0 ;
V_10 -> V_9 . V_39 . V_262 [ V_263 ] = V_58 -> V_84 ;
V_10 -> V_9 . V_39 . V_264 = 0 ;
( void ) F_110 ( & V_10 -> V_9 , V_265 | V_266 | V_267 ) ;
V_58 -> V_268 = V_269 ;
if ( V_55 ) {
V_2 -> V_270 = 1 ;
F_17 ( V_10 , V_227 ) ;
F_15 ( V_10 , V_216 ) ;
F_10 ( V_10 , V_210 ) ;
F_10 ( V_10 , V_213 ) ;
V_58 -> V_271 = 0x0007040600070406ULL ;
V_58 -> V_272 = 0 ;
V_58 -> V_268 = 0 ;
}
V_10 -> V_125 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
if ( F_84 ( V_273 ) ) {
V_2 -> V_274 = 3000 ;
F_16 ( V_10 , V_275 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static void F_111 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_276 ;
T_1 V_277 = 1 ;
F_107 ( V_10 ) ;
F_112 ( V_9 , & V_277 , & V_276 , & V_276 , & V_276 ) ;
F_113 ( V_9 , V_278 , V_277 ) ;
}
static struct V_8 * F_114 ( struct V_279 * V_279 , unsigned int V_280 )
{
struct V_7 * V_10 ;
struct V_164 * V_164 ;
struct V_164 * V_281 ;
struct V_164 * V_282 ;
struct V_164 * V_283 ;
int V_96 ;
V_10 = F_115 ( V_284 , V_143 ) ;
if ( ! V_10 ) {
V_96 = - V_144 ;
goto V_285;
}
V_10 -> V_194 = V_113 ;
V_96 = F_116 ( & V_10 -> V_9 , V_279 , V_280 ) ;
if ( V_96 )
goto V_286;
V_96 = - V_144 ;
V_164 = F_68 ( V_143 ) ;
if ( ! V_164 )
goto V_287;
V_281 = F_82 ( V_143 , V_155 ) ;
if ( ! V_281 )
goto V_288;
V_283 = F_82 ( V_143 , V_155 ) ;
if ( ! V_283 )
goto V_289;
V_282 = F_68 ( V_143 ) ;
if ( ! V_282 )
goto V_290;
V_10 -> V_17 . V_18 = F_83 ( V_282 ) ;
V_10 -> V_148 = F_83 ( V_281 ) ;
F_75 ( V_10 -> V_148 ) ;
V_10 -> V_17 . V_148 = F_83 ( V_283 ) ;
F_75 ( V_10 -> V_17 . V_148 ) ;
V_10 -> V_1 = F_83 ( V_164 ) ;
F_117 ( V_10 -> V_1 ) ;
V_10 -> V_291 = F_59 ( V_164 ) << V_135 ;
V_10 -> V_125 = 0 ;
F_107 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_292 = 0xfee00000 | V_293 ;
if ( F_118 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_39 . V_292 |= V_294 ;
F_45 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_290:
F_91 ( V_283 , V_155 ) ;
V_289:
F_91 ( V_281 , V_155 ) ;
V_288:
F_64 ( V_164 ) ;
V_287:
F_119 ( & V_10 -> V_9 ) ;
V_286:
F_120 ( V_284 , V_10 ) ;
V_285:
return F_121 ( V_96 ) ;
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_64 ( F_93 ( V_10 -> V_291 >> V_135 ) ) ;
F_91 ( F_123 ( V_10 -> V_148 ) , V_155 ) ;
F_64 ( F_123 ( V_10 -> V_17 . V_18 ) ) ;
F_91 ( F_123 ( V_10 -> V_17 . V_148 ) , V_155 ) ;
F_119 ( V_9 ) ;
F_120 ( V_284 , V_10 ) ;
}
static void F_124 ( struct V_8 * V_9 , int V_141 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
if ( F_125 ( V_141 != V_9 -> V_141 ) ) {
V_10 -> V_125 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_54 ( V_295 , F_4 ( V_9 ) -> V_205 . V_296 ) ;
#endif
F_126 ( V_251 , V_10 -> V_205 . V_251 ) ;
F_126 ( V_252 , V_10 -> V_205 . V_252 ) ;
V_10 -> V_205 . V_297 = F_127 () ;
for ( V_44 = 0 ; V_44 < V_298 ; V_44 ++ )
F_54 ( V_299 [ V_44 ] , V_10 -> V_300 [ V_44 ] ) ;
if ( F_38 ( V_111 ) &&
V_10 -> V_194 != F_60 ( V_136 ) ) {
F_60 ( V_136 ) = V_10 -> V_194 ;
F_49 ( V_112 , V_10 -> V_194 ) ;
}
}
static void F_128 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
++ V_9 -> V_301 . V_302 ;
F_129 ( V_10 -> V_205 . V_297 ) ;
#ifdef F_26
F_130 ( V_251 , V_10 -> V_205 . V_251 ) ;
F_49 ( V_303 , V_304 -> V_305 . V_252 ) ;
F_131 ( V_10 -> V_205 . V_252 ) ;
#else
#ifdef F_132
F_130 ( V_252 , V_10 -> V_205 . V_252 ) ;
#endif
#endif
for ( V_44 = 0 ; V_44 < V_298 ; V_44 ++ )
F_49 ( V_299 [ V_44 ] , V_10 -> V_300 [ V_44 ] ) ;
}
static void F_133 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_306 ;
if ( ! F_134 ( V_9 ) )
V_306 = 0 ;
else if ( V_10 -> V_1 -> V_58 . V_307 & V_308 )
V_306 = 3 ;
else
V_306 = V_10 -> V_1 -> V_58 . V_87 . V_183 & 0x3 ;
V_10 -> V_1 -> V_58 . V_306 = V_306 ;
}
static unsigned long F_135 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_307 ;
}
static void F_136 ( struct V_8 * V_9 , unsigned long V_307 )
{
unsigned long V_309 = F_4 ( V_9 ) -> V_1 -> V_58 . V_307 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_307 = V_307 ;
if ( ( V_309 ^ V_307 ) & V_308 )
F_133 ( V_9 ) ;
}
static void F_137 ( struct V_8 * V_9 , enum V_310 V_311 )
{
switch ( V_311 ) {
case V_312 :
F_72 ( ! V_55 ) ;
F_138 ( V_9 , V_9 -> V_39 . V_313 , F_139 ( V_9 ) ) ;
break;
default:
F_77 () ;
}
}
static void F_140 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_314 ) ;
}
static void F_141 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_314 ) ;
}
static struct V_181 * F_142 ( struct V_8 * V_9 , int V_182 )
{
struct V_207 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_182 ) {
case V_315 : return & V_58 -> V_87 ;
case V_316 : return & V_58 -> V_250 ;
case V_317 : return & V_58 -> V_248 ;
case V_318 : return & V_58 -> V_251 ;
case V_319 : return & V_58 -> V_252 ;
case V_320 : return & V_58 -> V_249 ;
case V_321 : return & V_58 -> V_259 ;
case V_322 : return & V_58 -> V_257 ;
}
F_77 () ;
return NULL ;
}
static T_2 F_143 ( struct V_8 * V_9 , int V_182 )
{
struct V_181 * V_323 = F_142 ( V_9 , V_182 ) ;
return V_323 -> V_88 ;
}
static void F_144 ( struct V_8 * V_9 ,
struct V_324 * V_325 , int V_182 )
{
struct V_181 * V_323 = F_142 ( V_9 , V_182 ) ;
V_325 -> V_88 = V_323 -> V_88 ;
V_325 -> V_188 = V_323 -> V_188 ;
V_325 -> V_183 = V_323 -> V_183 ;
V_325 -> type = V_323 -> V_184 & V_326 ;
V_325 -> V_323 = ( V_323 -> V_184 >> V_327 ) & 1 ;
V_325 -> V_328 = ( V_323 -> V_184 >> V_329 ) & 3 ;
V_325 -> V_330 = ( V_323 -> V_184 >> V_331 ) & 1 ;
V_325 -> V_332 = ( V_323 -> V_184 >> V_333 ) & 1 ;
V_325 -> V_334 = ( V_323 -> V_184 >> V_335 ) & 1 ;
V_325 -> V_336 = ( V_323 -> V_184 >> V_337 ) & 1 ;
V_325 -> V_15 = ( V_323 -> V_184 >> V_338 ) & 1 ;
V_325 -> V_339 = ! V_325 -> V_330 || ( V_325 -> type == 0 ) ;
switch ( V_182 ) {
case V_315 :
V_325 -> V_15 = V_323 -> V_188 > 0xfffff ;
break;
case V_321 :
V_325 -> type |= 0x2 ;
break;
case V_316 :
case V_317 :
case V_318 :
case V_319 :
if ( ! V_325 -> V_339 )
V_325 -> type |= 0x1 ;
break;
case V_320 :
if ( V_325 -> V_339 )
V_325 -> V_336 = 0 ;
break;
}
}
static int F_145 ( struct V_8 * V_9 )
{
struct V_207 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_306 ;
}
static void F_146 ( struct V_8 * V_9 , struct V_116 * V_340 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_340 -> V_341 = V_10 -> V_1 -> V_58 . V_256 . V_188 ;
V_340 -> V_129 = V_10 -> V_1 -> V_58 . V_256 . V_88 ;
}
static void F_147 ( struct V_8 * V_9 , struct V_116 * V_340 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_256 . V_188 = V_340 -> V_341 ;
V_10 -> V_1 -> V_58 . V_256 . V_88 = V_340 -> V_129 ;
F_3 ( V_10 -> V_1 , V_342 ) ;
}
static void F_148 ( struct V_8 * V_9 , struct V_116 * V_340 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_340 -> V_341 = V_10 -> V_1 -> V_58 . V_255 . V_188 ;
V_340 -> V_129 = V_10 -> V_1 -> V_58 . V_255 . V_88 ;
}
static void F_149 ( struct V_8 * V_9 , struct V_116 * V_340 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_255 . V_188 = V_340 -> V_341 ;
V_10 -> V_1 -> V_58 . V_255 . V_88 = V_340 -> V_129 ;
F_3 ( V_10 -> V_1 , V_342 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
}
static void F_151 ( struct V_8 * V_9 )
{
}
static void F_152 ( struct V_8 * V_9 )
{
}
static void F_153 ( struct V_7 * V_10 )
{
T_9 V_343 = V_10 -> V_9 . V_39 . V_264 ;
T_2 * V_344 = & V_10 -> V_1 -> V_58 . V_264 ;
if ( ! V_10 -> V_9 . V_208 )
* V_344 |= V_345 ;
else
* V_344 = ( * V_344 & ~ V_345 )
| ( V_343 & V_345 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_343 == * V_344 && V_10 -> V_9 . V_208 ) {
F_10 ( V_10 , V_209 ) ;
F_10 ( V_10 , V_212 ) ;
} else {
F_9 ( V_10 , V_209 ) ;
F_9 ( V_10 , V_212 ) ;
}
}
static void F_154 ( struct V_8 * V_9 , unsigned long V_264 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_155 ( V_9 ) && ( V_264 & V_346 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_155 ( V_9 ) && ! ( V_264 & V_346 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_264 = V_264 ;
if ( ! V_55 )
V_264 |= V_346 | V_347 ;
if ( ! V_9 -> V_208 )
V_264 |= V_348 ;
V_264 &= ~ ( V_266 | V_265 ) ;
V_10 -> V_1 -> V_58 . V_264 = V_264 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_153 ( V_10 ) ;
}
static int F_156 ( struct V_8 * V_9 , unsigned long V_268 )
{
unsigned long V_349 = F_157 () & V_350 ;
unsigned long V_351 = F_4 ( V_9 ) -> V_1 -> V_58 . V_268 ;
if ( V_268 & V_352 )
return 1 ;
if ( V_55 && ( ( V_351 ^ V_268 ) & V_353 ) )
F_158 ( V_9 ) ;
V_9 -> V_39 . V_268 = V_268 ;
if ( ! V_55 )
V_268 |= V_269 ;
V_268 |= V_349 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_268 = V_268 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_159 ( struct V_8 * V_9 ,
struct V_324 * V_325 , int V_182 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_181 * V_323 = F_142 ( V_9 , V_182 ) ;
V_323 -> V_88 = V_325 -> V_88 ;
V_323 -> V_188 = V_325 -> V_188 ;
V_323 -> V_183 = V_325 -> V_183 ;
if ( V_325 -> V_339 )
V_323 -> V_184 = 0 ;
else {
V_323 -> V_184 = ( V_325 -> type & V_326 ) ;
V_323 -> V_184 |= ( V_325 -> V_323 & 1 ) << V_327 ;
V_323 -> V_184 |= ( V_325 -> V_328 & 3 ) << V_329 ;
V_323 -> V_184 |= ( V_325 -> V_330 & 1 ) << V_331 ;
V_323 -> V_184 |= ( V_325 -> V_332 & 1 ) << V_333 ;
V_323 -> V_184 |= ( V_325 -> V_334 & 1 ) << V_335 ;
V_323 -> V_184 |= ( V_325 -> V_336 & 1 ) << V_337 ;
V_323 -> V_184 |= ( V_325 -> V_15 & 1 ) << V_338 ;
}
if ( V_182 == V_315 )
F_133 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_354 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_355 ) ;
F_15 ( V_10 , V_82 ) ;
if ( V_10 -> V_356 )
F_14 ( V_10 , V_355 ) ;
if ( V_9 -> V_357 & V_358 ) {
if ( V_9 -> V_357 &
( V_359 | V_360 ) )
F_14 ( V_10 , V_355 ) ;
if ( V_9 -> V_357 & V_361 )
F_14 ( V_10 , V_82 ) ;
} else
V_9 -> V_357 = 0 ;
}
static void F_161 ( struct V_7 * V_10 , struct V_114 * V_115 )
{
if ( V_115 -> V_128 > V_115 -> V_126 ) {
++ V_115 -> V_125 ;
V_115 -> V_128 = 1 ;
V_10 -> V_1 -> V_2 . V_362 = V_363 ;
}
V_10 -> V_125 = V_115 -> V_125 ;
V_10 -> V_1 -> V_2 . V_51 = V_115 -> V_128 ++ ;
F_3 ( V_10 -> V_1 , V_364 ) ;
}
static T_2 F_162 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_261 ;
}
static void F_163 ( struct V_8 * V_9 , unsigned long V_365 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_261 = V_365 ;
F_3 ( V_10 -> V_1 , V_366 ) ;
}
static void F_164 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_165 ( V_9 -> V_39 . V_336 [ 0 ] , 0 ) ;
F_165 ( V_9 -> V_39 . V_336 [ 1 ] , 1 ) ;
F_165 ( V_9 -> V_39 . V_336 [ 2 ] , 2 ) ;
F_165 ( V_9 -> V_39 . V_336 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_261 = F_162 ( V_9 ) ;
V_9 -> V_39 . V_367 = V_10 -> V_1 -> V_58 . V_367 ;
V_9 -> V_39 . V_368 &= ~ V_369 ;
F_12 ( V_10 ) ;
}
static void F_166 ( struct V_8 * V_9 , unsigned long V_365 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_367 = V_365 ;
F_3 ( V_10 -> V_1 , V_366 ) ;
}
static int F_167 ( struct V_7 * V_10 )
{
T_2 V_370 = V_10 -> V_1 -> V_2 . V_371 ;
T_1 V_80 ;
int V_142 = 1 ;
switch ( V_10 -> V_372 ) {
default:
V_80 = V_10 -> V_1 -> V_2 . V_373 ;
F_168 ( V_370 , V_80 ) ;
if ( ! V_55 && F_169 ( & V_10 -> V_9 ) )
F_170 ( & V_10 -> V_9 , V_370 ) ;
V_142 = F_171 ( & V_10 -> V_9 , V_370 , V_80 ,
V_10 -> V_1 -> V_2 . V_374 ,
V_10 -> V_1 -> V_2 . V_375 ) ;
break;
case V_376 :
V_10 -> V_372 = 0 ;
F_172 () ;
F_173 ( V_370 ) ;
F_174 () ;
break;
case V_377 :
V_10 -> V_372 = 0 ;
F_172 () ;
F_175 ( V_370 ) ;
F_174 () ;
break;
}
return V_142 ;
}
static int F_176 ( struct V_7 * V_10 )
{
struct V_378 * V_378 = V_10 -> V_9 . V_379 ;
if ( ! ( V_10 -> V_9 . V_357 &
( V_359 | V_360 ) ) &&
! V_10 -> V_356 ) {
F_177 ( & V_10 -> V_9 , V_355 ) ;
return 1 ;
}
if ( V_10 -> V_356 ) {
V_10 -> V_356 = false ;
if ( ! ( V_10 -> V_9 . V_357 & V_359 ) )
V_10 -> V_1 -> V_58 . V_307 &=
~ ( V_380 | V_381 ) ;
F_160 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_357 &
( V_359 | V_360 ) ) {
V_378 -> V_382 = V_383 ;
V_378 -> V_384 . V_39 . V_385 =
V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_378 -> V_384 . V_39 . V_386 = V_355 ;
return 0 ;
}
return 1 ;
}
static int F_178 ( struct V_7 * V_10 )
{
struct V_378 * V_378 = V_10 -> V_9 . V_379 ;
V_378 -> V_382 = V_383 ;
V_378 -> V_384 . V_39 . V_385 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_378 -> V_384 . V_39 . V_386 = V_82 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_10 )
{
int V_387 ;
V_387 = F_32 ( & V_10 -> V_9 , V_388 ) ;
if ( V_387 != V_73 )
F_177 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static void F_180 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_389 ) ;
V_10 -> V_9 . V_208 = 1 ;
F_153 ( V_10 ) ;
}
static int F_181 ( struct V_7 * V_10 )
{
F_180 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_182 ( void )
{
int V_96 , V_44 ;
T_2 V_365 ;
if ( ! V_100 )
return false ;
V_365 = F_41 ( V_390 , & V_96 ) ;
if ( V_96 )
return false ;
V_365 &= ~ ( 1ULL << 62 ) ;
if ( V_365 != 0xb600000000010015ULL )
return false ;
for ( V_44 = 0 ; V_44 < 6 ; ++ V_44 )
F_44 ( F_183 ( V_44 ) , 0 , 0 ) ;
V_365 = F_41 ( V_391 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_365 &= ~ ( 1ULL << 2 ) ;
V_94 = F_42 ( V_365 ) ;
V_95 = F_43 ( V_365 ) ;
F_44 ( V_391 , V_94 , V_95 ) ;
}
F_184 () ;
return true ;
}
static void F_185 ( struct V_7 * V_10 )
{
if ( F_182 () ) {
F_55 ( L_11 ) ;
F_186 ( V_392 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_187 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_188 ( struct V_7 * V_10 )
{
struct V_378 * V_378 = V_10 -> V_9 . V_379 ;
F_117 ( V_10 -> V_1 ) ;
F_107 ( V_10 ) ;
V_378 -> V_382 = V_393 ;
return 0 ;
}
static int F_189 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_394 = V_10 -> V_1 -> V_2 . V_373 ;
int V_341 , V_395 , string ;
unsigned V_396 ;
++ V_10 -> V_9 . V_301 . V_397 ;
string = ( V_394 & V_398 ) != 0 ;
V_395 = ( V_394 & V_399 ) != 0 ;
if ( string || V_395 )
return F_32 ( V_9 , 0 ) == V_73 ;
V_396 = V_394 >> 16 ;
V_341 = ( V_394 & V_400 ) >> V_401 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_371 ;
F_31 ( & V_10 -> V_9 ) ;
return F_190 ( V_9 , V_341 , V_396 ) ;
}
static int F_191 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_192 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_301 . V_402 ;
return 1 ;
}
static int F_193 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_194 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 1 ;
F_31 ( & V_10 -> V_9 ) ;
return F_195 ( & V_10 -> V_9 ) ;
}
static int F_196 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_197 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_198 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_403 ;
}
static T_2 F_199 ( struct V_8 * V_9 , int V_146 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_272 = V_10 -> V_17 . V_403 ;
T_2 V_404 ;
int V_66 ;
V_66 = F_200 ( V_9 -> V_279 , F_201 ( V_272 ) , & V_404 ,
F_202 ( V_272 ) + V_146 * 8 , 8 ) ;
if ( V_66 )
return 0 ;
return V_404 ;
}
static void F_203 ( struct V_8 * V_9 ,
unsigned long V_405 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_403 = V_405 ;
F_3 ( V_10 -> V_1 , V_406 ) ;
F_158 ( V_9 ) ;
}
static void F_204 ( struct V_8 * V_9 ,
struct V_407 * V_408 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_409 = V_410 ;
V_10 -> V_1 -> V_2 . V_411 = 0 ;
V_10 -> V_1 -> V_2 . V_373 = V_408 -> V_80 ;
V_10 -> V_1 -> V_2 . V_371 = V_408 -> V_129 ;
F_205 ( V_10 ) ;
}
static void F_206 ( struct V_8 * V_9 )
{
F_207 ( V_9 , & V_9 -> V_39 . V_412 ) ;
V_9 -> V_39 . V_412 . V_413 = F_203 ;
V_9 -> V_39 . V_412 . V_414 = F_198 ;
V_9 -> V_39 . V_412 . V_415 = F_199 ;
V_9 -> V_39 . V_412 . V_416 = F_204 ;
V_9 -> V_39 . V_412 . V_417 = F_25 () ;
V_9 -> V_39 . V_313 = & V_9 -> V_39 . V_418 ;
}
static void F_208 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_313 = & V_9 -> V_39 . V_412 ;
}
static int F_209 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_155 ( & V_10 -> V_9 ) ) {
F_177 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_306 ) {
F_210 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_10 , unsigned V_78 ,
bool V_79 , T_1 V_80 )
{
int V_419 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_409 = V_420 + V_78 ;
V_10 -> V_1 -> V_2 . V_411 = 0 ;
V_10 -> V_1 -> V_2 . V_373 = V_80 ;
V_10 -> V_1 -> V_2 . V_371 = V_10 -> V_9 . V_39 . V_421 ;
V_419 = F_211 ( V_10 ) ;
if ( V_419 == V_422 )
V_10 -> V_17 . V_423 = true ;
return V_419 ;
}
static inline bool F_212 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_424 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_425 ) )
return false ;
if ( V_10 -> V_17 . V_423 )
return false ;
V_10 -> V_1 -> V_2 . V_409 = V_426 ;
V_10 -> V_1 -> V_2 . V_373 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_423 = true ;
F_213 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_214 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_220 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_409 = V_427 ;
V_10 -> V_17 . V_423 = true ;
return false ;
}
static void * F_215 ( struct V_7 * V_10 , T_2 V_428 , struct V_164 * * V_429 )
{
struct V_164 * V_164 ;
F_216 () ;
V_164 = F_217 ( V_10 -> V_9 . V_279 , V_428 >> V_135 ) ;
if ( F_218 ( V_164 ) )
goto error;
* V_429 = V_164 ;
return F_219 ( V_164 ) ;
error:
F_210 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_220 ( struct V_164 * V_164 )
{
F_221 ( V_164 ) ;
F_222 ( V_164 ) ;
}
static int F_223 ( struct V_7 * V_10 )
{
unsigned V_396 ;
T_4 V_97 , V_6 ;
T_2 V_428 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return V_430 ;
V_396 = V_10 -> V_1 -> V_2 . V_373 >> 16 ;
V_428 = V_10 -> V_17 . V_431 + ( V_396 / 8 ) ;
V_6 = V_396 % 8 ;
V_97 = 0 ;
if ( F_224 ( V_10 -> V_9 . V_279 , V_428 , & V_97 , 1 ) )
V_97 &= ( 1 << V_6 ) ;
return V_97 ? V_422 : V_430 ;
}
static int F_225 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_365 ;
int V_150 , V_65 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_230 ) ) )
return V_430 ;
V_42 = V_10 -> V_9 . V_39 . V_262 [ V_432 ] ;
V_43 = F_21 ( V_42 ) ;
V_150 = V_10 -> V_1 -> V_2 . V_373 & 1 ;
V_65 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_150 ) ;
if ( V_43 == V_49 )
return V_422 ;
V_43 *= 4 ;
if ( F_224 ( V_10 -> V_9 . V_279 , V_10 -> V_17 . V_433 + V_43 , & V_365 , 4 ) )
return V_422 ;
return ( V_365 & V_65 ) ? V_422 : V_430 ;
}
static int F_226 ( struct V_7 * V_10 )
{
T_1 V_409 = V_10 -> V_1 -> V_2 . V_409 ;
switch ( V_409 ) {
case V_426 :
case V_427 :
case V_420 + V_218 :
return V_430 ;
case V_410 :
if ( V_55 )
return V_430 ;
break;
case V_420 + V_216 :
if ( ! V_55 && V_10 -> V_372 == 0 )
return V_430 ;
break;
case V_420 + V_389 :
F_181 ( V_10 ) ;
break;
default:
break;
}
return V_434 ;
}
static int F_211 ( struct V_7 * V_10 )
{
T_1 V_409 = V_10 -> V_1 -> V_2 . V_409 ;
int V_419 = V_430 ;
switch ( V_409 ) {
case V_435 :
V_419 = F_225 ( V_10 ) ;
break;
case V_436 :
V_419 = F_223 ( V_10 ) ;
break;
case V_437 ... V_438 : {
T_1 V_6 = 1U << ( V_409 - V_437 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_419 = V_422 ;
break;
}
case V_439 ... V_440 : {
T_1 V_6 = 1U << ( V_409 - V_439 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_419 = V_422 ;
break;
}
case V_420 ... V_420 + 0x1f : {
T_1 V_441 = 1 << ( V_409 - V_420 ) ;
if ( V_10 -> V_17 . V_21 & V_441 )
V_419 = V_422 ;
else if ( ( V_409 == V_420 + V_216 ) &&
V_10 -> V_372 != 0 )
V_419 = V_422 ;
break;
}
case V_442 : {
V_419 = V_422 ;
break;
}
default: {
T_2 V_443 = 1ULL << ( V_409 - V_426 ) ;
if ( V_10 -> V_17 . V_22 & V_443 )
V_419 = V_422 ;
}
}
return V_419 ;
}
static int F_227 ( struct V_7 * V_10 )
{
int V_419 ;
V_419 = F_211 ( V_10 ) ;
if ( V_419 == V_422 )
F_205 ( V_10 ) ;
return V_419 ;
}
static inline void F_228 ( struct V_1 * V_444 , struct V_1 * V_445 )
{
struct V_11 * V_446 = & V_444 -> V_2 ;
struct V_11 * V_447 = & V_445 -> V_2 ;
V_446 -> V_19 = V_447 -> V_19 ;
V_446 -> V_20 = V_447 -> V_20 ;
V_446 -> V_21 = V_447 -> V_21 ;
V_446 -> V_22 = V_447 -> V_22 ;
V_446 -> V_244 = V_447 -> V_244 ;
V_446 -> V_245 = V_447 -> V_245 ;
V_446 -> V_201 = V_447 -> V_201 ;
V_446 -> V_51 = V_447 -> V_51 ;
V_446 -> V_362 = V_447 -> V_362 ;
V_446 -> V_246 = V_447 -> V_246 ;
V_446 -> V_448 = V_447 -> V_448 ;
V_446 -> V_67 = V_447 -> V_67 ;
V_446 -> V_409 = V_447 -> V_409 ;
V_446 -> V_411 = V_447 -> V_411 ;
V_446 -> V_373 = V_447 -> V_373 ;
V_446 -> V_371 = V_447 -> V_371 ;
V_446 -> V_449 = V_447 -> V_449 ;
V_446 -> V_450 = V_447 -> V_450 ;
V_446 -> V_270 = V_447 -> V_270 ;
V_446 -> V_90 = V_447 -> V_90 ;
V_446 -> V_93 = V_447 -> V_93 ;
V_446 -> V_403 = V_447 -> V_403 ;
V_446 -> V_159 = V_447 -> V_159 ;
}
static int F_205 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_164 * V_164 ;
F_229 ( V_1 -> V_2 . V_409 ,
V_1 -> V_2 . V_373 ,
V_1 -> V_2 . V_371 ,
V_1 -> V_2 . V_449 ,
V_1 -> V_2 . V_450 ,
V_452 ) ;
V_451 = F_215 ( V_10 , V_10 -> V_17 . V_1 , & V_164 ) ;
if ( ! V_451 )
return 1 ;
F_230 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_451 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_451 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_451 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_451 -> V_58 . V_250 = V_1 -> V_58 . V_250 ;
V_451 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_451 -> V_58 . V_256 = V_1 -> V_58 . V_256 ;
V_451 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_451 -> V_58 . V_264 = F_231 ( & V_10 -> V_9 ) ;
V_451 -> V_58 . V_272 = F_139 ( & V_10 -> V_9 ) ;
V_451 -> V_58 . V_421 = V_1 -> V_58 . V_421 ;
V_451 -> V_58 . V_268 = V_10 -> V_9 . V_39 . V_268 ;
V_451 -> V_58 . V_307 = F_232 ( & V_10 -> V_9 ) ;
V_451 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_451 -> V_58 . V_453 = V_1 -> V_58 . V_453 ;
V_451 -> V_58 . V_454 = V_1 -> V_58 . V_454 ;
V_451 -> V_58 . V_367 = V_1 -> V_58 . V_367 ;
V_451 -> V_58 . V_261 = V_1 -> V_58 . V_261 ;
V_451 -> V_58 . V_306 = V_1 -> V_58 . V_306 ;
V_451 -> V_2 . V_246 = V_1 -> V_2 . V_246 ;
V_451 -> V_2 . V_448 = V_1 -> V_2 . V_448 ;
V_451 -> V_2 . V_67 = V_1 -> V_2 . V_67 ;
V_451 -> V_2 . V_409 = V_1 -> V_2 . V_409 ;
V_451 -> V_2 . V_411 = V_1 -> V_2 . V_411 ;
V_451 -> V_2 . V_373 = V_1 -> V_2 . V_373 ;
V_451 -> V_2 . V_371 = V_1 -> V_2 . V_371 ;
V_451 -> V_2 . V_449 = V_1 -> V_2 . V_449 ;
V_451 -> V_2 . V_450 = V_1 -> V_2 . V_450 ;
V_451 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_455 = & V_451 -> V_2 ;
V_455 -> V_449 = V_1 -> V_2 . V_90 ;
V_455 -> V_450 = V_1 -> V_2 . V_93 ;
}
V_451 -> V_2 . V_362 = 0 ;
V_451 -> V_2 . V_90 = 0 ;
V_451 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_424 ) )
V_451 -> V_2 . V_246 &= ~ V_247 ;
F_228 ( V_1 , V_18 ) ;
F_233 ( & V_10 -> V_9 ) ;
F_234 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_403 = 0 ;
V_10 -> V_1 -> V_58 . V_248 = V_18 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_249 = V_18 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_250 = V_18 -> V_58 . V_250 ;
V_10 -> V_1 -> V_58 . V_255 = V_18 -> V_58 . V_255 ;
V_10 -> V_1 -> V_58 . V_256 = V_18 -> V_58 . V_256 ;
F_109 ( & V_10 -> V_9 , V_18 -> V_58 . V_307 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_154 ( & V_10 -> V_9 , V_18 -> V_58 . V_264 | V_456 ) ;
F_156 ( & V_10 -> V_9 , V_18 -> V_58 . V_268 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_272 = V_18 -> V_58 . V_272 ;
V_10 -> V_9 . V_39 . V_272 = V_18 -> V_58 . V_272 ;
} else {
( void ) F_235 ( & V_10 -> V_9 , V_18 -> V_58 . V_272 ) ;
}
F_113 ( & V_10 -> V_9 , V_457 , V_18 -> V_58 . V_454 ) ;
F_113 ( & V_10 -> V_9 , V_458 , V_18 -> V_58 . V_453 ) ;
F_113 ( & V_10 -> V_9 , V_263 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_367 = 0 ;
V_10 -> V_1 -> V_58 . V_306 = 0 ;
V_10 -> V_1 -> V_2 . V_449 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_220 ( V_164 ) ;
F_208 ( & V_10 -> V_9 ) ;
F_236 ( & V_10 -> V_9 ) ;
F_237 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_238 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_230 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_157 ; V_44 ++ ) {
T_1 V_365 , V_459 ;
T_2 V_43 ;
if ( V_158 [ V_44 ] == 0xffffffff )
break;
V_459 = V_158 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_433 + ( V_459 * 4 ) ;
if ( F_224 ( V_10 -> V_9 . V_279 , V_43 , & V_365 , 4 ) )
return false ;
V_10 -> V_17 . V_148 [ V_459 ] = V_10 -> V_148 [ V_459 ] | V_365 ;
}
V_10 -> V_1 -> V_2 . V_245 = F_108 ( V_10 -> V_17 . V_148 ) ;
return true ;
}
static bool F_239 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_233 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_270 && ! V_55 )
return false ;
return true ;
}
static bool F_240 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_164 * V_164 ;
T_2 V_460 ;
V_460 = V_10 -> V_1 -> V_58 . V_454 ;
V_451 = F_215 ( V_10 , V_10 -> V_1 -> V_58 . V_454 , & V_164 ) ;
if ( ! V_451 )
return false ;
if ( ! F_239 ( V_451 ) ) {
V_451 -> V_2 . V_409 = V_442 ;
V_451 -> V_2 . V_411 = 0 ;
V_451 -> V_2 . V_373 = 0 ;
V_451 -> V_2 . V_371 = 0 ;
F_220 ( V_164 ) ;
return false ;
}
F_241 ( V_10 -> V_1 -> V_58 . V_84 , V_460 ,
V_451 -> V_58 . V_84 ,
V_451 -> V_2 . V_246 ,
V_451 -> V_2 . V_90 ,
V_451 -> V_2 . V_270 ) ;
F_242 ( V_451 -> V_2 . V_19 & 0xffff ,
V_451 -> V_2 . V_19 >> 16 ,
V_451 -> V_2 . V_21 ,
V_451 -> V_2 . V_22 ) ;
F_233 ( & V_10 -> V_9 ) ;
F_234 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_18 -> V_58 . V_250 = V_1 -> V_58 . V_250 ;
V_18 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_18 -> V_58 . V_256 = V_1 -> V_58 . V_256 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_264 = F_231 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_268 = V_10 -> V_9 . V_39 . V_268 ;
V_18 -> V_58 . V_307 = F_232 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_453 = V_1 -> V_58 . V_453 ;
V_18 -> V_58 . V_454 = V_1 -> V_58 . V_454 ;
if ( V_55 )
V_18 -> V_58 . V_272 = V_1 -> V_58 . V_272 ;
else
V_18 -> V_58 . V_272 = F_139 ( & V_10 -> V_9 ) ;
F_228 ( V_18 , V_1 ) ;
if ( F_232 ( & V_10 -> V_9 ) & V_461 )
V_10 -> V_9 . V_39 . V_40 |= V_425 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_425 ;
if ( V_451 -> V_2 . V_270 ) {
F_243 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_403 = V_451 -> V_2 . V_403 ;
F_206 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_248 = V_451 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_87 = V_451 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_249 = V_451 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_250 = V_451 -> V_58 . V_250 ;
V_10 -> V_1 -> V_58 . V_255 = V_451 -> V_58 . V_255 ;
V_10 -> V_1 -> V_58 . V_256 = V_451 -> V_58 . V_256 ;
F_109 ( & V_10 -> V_9 , V_451 -> V_58 . V_307 ) ;
F_27 ( & V_10 -> V_9 , V_451 -> V_58 . V_54 ) ;
F_154 ( & V_10 -> V_9 , V_451 -> V_58 . V_264 ) ;
F_156 ( & V_10 -> V_9 , V_451 -> V_58 . V_268 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_272 = V_451 -> V_58 . V_272 ;
V_10 -> V_9 . V_39 . V_272 = V_451 -> V_58 . V_272 ;
} else
( void ) F_235 ( & V_10 -> V_9 , V_451 -> V_58 . V_272 ) ;
F_236 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_421 = V_10 -> V_9 . V_39 . V_421 = V_451 -> V_58 . V_421 ;
F_113 ( & V_10 -> V_9 , V_457 , V_451 -> V_58 . V_454 ) ;
F_113 ( & V_10 -> V_9 , V_458 , V_451 -> V_58 . V_453 ) ;
F_113 ( & V_10 -> V_9 , V_263 , V_451 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_454 = V_451 -> V_58 . V_454 ;
V_10 -> V_1 -> V_58 . V_453 = V_451 -> V_58 . V_453 ;
V_10 -> V_1 -> V_58 . V_84 = V_451 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_367 = V_451 -> V_58 . V_367 ;
V_10 -> V_1 -> V_58 . V_261 = V_451 -> V_58 . V_261 ;
V_10 -> V_1 -> V_58 . V_306 = V_451 -> V_58 . V_306 ;
V_10 -> V_17 . V_433 = V_451 -> V_2 . V_245 & ~ 0x0fffULL ;
V_10 -> V_17 . V_431 = V_451 -> V_2 . V_244 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_451 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_451 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_451 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_451 -> V_2 . V_22 ;
F_158 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_246 = V_451 -> V_2 . V_246 | V_247 ;
if ( V_451 -> V_2 . V_246 & V_247 )
V_10 -> V_9 . V_39 . V_40 |= V_424 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_424 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_424 ) {
F_10 ( V_10 , V_462 ) ;
F_10 ( V_10 , V_215 ) ;
}
F_17 ( V_10 , V_234 ) ;
V_10 -> V_1 -> V_2 . V_159 = V_451 -> V_2 . V_159 ;
V_10 -> V_1 -> V_2 . V_448 = V_451 -> V_2 . V_448 ;
V_10 -> V_1 -> V_2 . V_67 = V_451 -> V_2 . V_67 ;
V_10 -> V_1 -> V_2 . V_201 += V_451 -> V_2 . V_201 ;
V_10 -> V_1 -> V_2 . V_90 = V_451 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_451 -> V_2 . V_93 ;
F_220 ( V_164 ) ;
F_244 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_460 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_245 ( struct V_1 * V_445 , struct V_1 * V_463 )
{
V_463 -> V_58 . V_251 = V_445 -> V_58 . V_251 ;
V_463 -> V_58 . V_252 = V_445 -> V_58 . V_252 ;
V_463 -> V_58 . V_259 = V_445 -> V_58 . V_259 ;
V_463 -> V_58 . V_257 = V_445 -> V_58 . V_257 ;
V_463 -> V_58 . V_464 = V_445 -> V_58 . V_464 ;
V_463 -> V_58 . V_465 = V_445 -> V_58 . V_465 ;
V_463 -> V_58 . V_466 = V_445 -> V_58 . V_466 ;
V_463 -> V_58 . V_467 = V_445 -> V_58 . V_467 ;
V_463 -> V_58 . V_468 = V_445 -> V_58 . V_468 ;
V_463 -> V_58 . V_469 = V_445 -> V_58 . V_469 ;
V_463 -> V_58 . V_470 = V_445 -> V_58 . V_470 ;
V_463 -> V_58 . V_471 = V_445 -> V_58 . V_471 ;
}
static int F_246 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_164 * V_164 ;
if ( F_209 ( V_10 ) )
return 1 ;
V_451 = F_215 ( V_10 , V_10 -> V_1 -> V_58 . V_454 , & V_164 ) ;
if ( ! V_451 )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_245 ( V_451 , V_10 -> V_1 ) ;
F_220 ( V_164 ) ;
return 1 ;
}
static int F_247 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_164 * V_164 ;
if ( F_209 ( V_10 ) )
return 1 ;
V_451 = F_215 ( V_10 , V_10 -> V_1 -> V_58 . V_454 , & V_164 ) ;
if ( ! V_451 )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_245 ( V_10 -> V_1 , V_451 ) ;
F_220 ( V_164 ) ;
return 1 ;
}
static int F_248 ( struct V_7 * V_10 )
{
if ( F_209 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_240 ( V_10 ) )
return 1 ;
if ( ! F_238 ( V_10 ) )
goto V_472;
return 1 ;
V_472:
V_10 -> V_1 -> V_2 . V_409 = V_442 ;
V_10 -> V_1 -> V_2 . V_411 = 0 ;
V_10 -> V_1 -> V_2 . V_373 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = 0 ;
F_205 ( V_10 ) ;
return 1 ;
}
static int F_249 ( struct V_7 * V_10 )
{
if ( F_209 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_186 ( V_473 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_250 ( struct V_7 * V_10 )
{
if ( F_209 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_141 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_474 ;
F_3 ( V_10 -> V_1 , V_475 ) ;
return 1 ;
}
static int F_251 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_252 ( V_10 -> V_1 -> V_58 . V_84 , V_9 -> V_39 . V_262 [ V_432 ] ,
V_9 -> V_39 . V_262 [ V_457 ] ) ;
F_253 ( V_9 , V_9 -> V_39 . V_262 [ V_457 ] ) ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_254 ( struct V_7 * V_10 )
{
F_255 ( V_10 -> V_1 -> V_58 . V_84 , V_10 -> V_9 . V_39 . V_262 [ V_457 ] ) ;
F_177 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static int F_256 ( struct V_7 * V_10 )
{
T_2 V_476 = F_257 ( & V_10 -> V_9 ) ;
T_1 V_146 = F_258 ( & V_10 -> V_9 , V_432 ) ;
if ( F_259 ( & V_10 -> V_9 , V_146 , V_476 ) == 0 ) {
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_260 ( struct V_7 * V_10 )
{
F_177 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static int F_261 ( struct V_7 * V_10 )
{
T_10 V_477 ;
int V_478 ;
int V_479 = V_10 -> V_1 -> V_2 . V_449 &
V_480 ;
int V_481 = V_10 -> V_1 -> V_2 . V_449 & V_482 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_449 & V_480 ;
T_7 V_483 =
V_10 -> V_1 -> V_2 . V_449 & V_484 ;
bool V_79 = false ;
T_1 V_80 = 0 ;
V_477 = ( T_10 ) V_10 -> V_1 -> V_2 . V_373 ;
if ( V_10 -> V_1 -> V_2 . V_371 &
( 1ULL << V_485 ) )
V_478 = V_486 ;
else if ( V_10 -> V_1 -> V_2 . V_371 &
( 1ULL << V_487 ) )
V_478 = V_488 ;
else if ( V_483 )
V_478 = V_489 ;
else
V_478 = V_490 ;
if ( V_478 == V_489 ) {
switch ( type ) {
case V_491 :
V_10 -> V_9 . V_39 . V_492 = false ;
break;
case V_493 :
if ( V_10 -> V_1 -> V_2 . V_371 &
( 1ULL << V_494 ) ) {
V_79 = true ;
V_80 =
( T_1 ) V_10 -> V_1 -> V_2 . V_371 ;
}
F_233 ( & V_10 -> V_9 ) ;
break;
case V_495 :
F_234 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_478 != V_489 ||
V_479 == V_496 ||
( V_479 == V_493 &&
( V_481 == V_497 || V_481 == V_82 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_479 != V_496 )
V_481 = - 1 ;
if ( F_262 ( & V_10 -> V_9 , V_477 , V_481 , V_478 ,
V_79 , V_80 ) == V_498 ) {
V_10 -> V_9 . V_379 -> V_382 = V_499 ;
V_10 -> V_9 . V_379 -> V_500 . V_501 = V_502 ;
V_10 -> V_9 . V_379 -> V_500 . V_503 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_264 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_265 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_301 . V_504 ;
F_17 ( V_10 , V_505 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_506 ;
V_10 -> V_507 = F_34 ( & V_10 -> V_9 ) ;
F_186 ( V_473 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_266 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_508 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_73 ;
F_253 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_373 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_267 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_73 ;
}
static int F_268 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_38 ( V_83 ) )
return F_267 ( V_10 ) ;
V_96 = F_269 ( & V_10 -> V_9 ) ;
F_270 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
bool F_271 ( struct V_7 * V_10 , unsigned long V_97 )
{
unsigned long V_264 = V_10 -> V_9 . V_39 . V_264 ;
bool V_66 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_222 ) ) ) )
return false ;
V_264 &= ~ V_345 ;
V_97 &= ~ V_345 ;
if ( V_264 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_409 = V_509 ;
V_66 = ( F_227 ( V_10 ) == V_422 ) ;
}
return V_66 ;
}
static int F_272 ( struct V_7 * V_10 )
{
int V_311 , V_510 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_38 ( V_508 ) )
return F_267 ( V_10 ) ;
if ( F_125 ( ( V_10 -> V_1 -> V_2 . V_373 & V_511 ) == 0 ) )
return F_267 ( V_10 ) ;
V_311 = V_10 -> V_1 -> V_2 . V_373 & V_512 ;
V_510 = V_10 -> V_1 -> V_2 . V_409 - V_437 ;
V_96 = 0 ;
if ( V_510 >= 16 ) {
V_510 -= 16 ;
V_97 = F_258 ( & V_10 -> V_9 , V_311 ) ;
switch ( V_510 ) {
case 0 :
if ( ! F_271 ( V_10 , V_97 ) )
V_96 = F_110 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_235 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_273 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_274 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_98 ( 1 , L_12 , V_510 ) ;
F_177 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
} else {
switch ( V_510 ) {
case 0 :
V_97 = F_231 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_421 ;
break;
case 3 :
V_97 = F_139 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_275 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_276 ( & V_10 -> V_9 ) ;
break;
default:
F_98 ( 1 , L_13 , V_510 ) ;
F_177 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
F_113 ( & V_10 -> V_9 , V_311 , V_97 ) ;
}
F_270 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_277 ( struct V_7 * V_10 )
{
int V_311 , V_513 ;
unsigned long V_97 ;
int V_96 ;
if ( V_10 -> V_9 . V_357 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_368 |= V_369 ;
return 1 ;
}
if ( ! F_84 ( V_508 ) )
return F_267 ( V_10 ) ;
V_311 = V_10 -> V_1 -> V_2 . V_373 & V_512 ;
V_513 = V_10 -> V_1 -> V_2 . V_409 - V_439 ;
if ( V_513 >= 16 ) {
V_97 = F_258 ( & V_10 -> V_9 , V_311 ) ;
F_278 ( & V_10 -> V_9 , V_513 - 16 , V_97 ) ;
} else {
V_96 = F_279 ( & V_10 -> V_9 , V_513 , & V_97 ) ;
if ( ! V_96 )
F_113 ( & V_10 -> V_9 , V_311 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_280 ( struct V_7 * V_10 )
{
struct V_378 * V_378 = V_10 -> V_9 . V_379 ;
int V_142 ;
T_4 V_514 = F_276 ( & V_10 -> V_9 ) ;
V_142 = F_272 ( V_10 ) ;
if ( F_281 ( V_10 -> V_9 . V_279 ) )
return V_142 ;
if ( V_514 <= F_276 ( & V_10 -> V_9 ) )
return V_142 ;
V_378 -> V_382 = V_515 ;
return 0 ;
}
T_2 F_282 ( struct V_8 * V_9 , T_2 V_516 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_201 +
F_96 ( V_9 , V_516 ) ;
}
static int F_283 ( struct V_8 * V_9 , unsigned V_517 , T_2 * V_518 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_517 ) {
case V_519 : {
* V_518 = V_10 -> V_1 -> V_2 . V_201 +
F_96 ( V_9 , F_106 () ) ;
break;
}
case V_520 :
* V_518 = V_10 -> V_1 -> V_58 . V_465 ;
break;
#ifdef F_26
case V_521 :
* V_518 = V_10 -> V_1 -> V_58 . V_466 ;
break;
case V_522 :
* V_518 = V_10 -> V_1 -> V_58 . V_467 ;
break;
case V_303 :
* V_518 = V_10 -> V_1 -> V_58 . V_464 ;
break;
case V_523 :
* V_518 = V_10 -> V_1 -> V_58 . V_468 ;
break;
#endif
case V_524 :
* V_518 = V_10 -> V_1 -> V_58 . V_469 ;
break;
case V_525 :
* V_518 = V_10 -> V_471 ;
break;
case V_526 :
* V_518 = V_10 -> V_470 ;
break;
case V_527 :
* V_518 = V_10 -> V_1 -> V_58 . V_528 ;
break;
case V_160 :
* V_518 = V_10 -> V_1 -> V_58 . V_529 ;
break;
case V_161 :
* V_518 = V_10 -> V_1 -> V_58 . V_530 ;
break;
case V_162 :
* V_518 = V_10 -> V_1 -> V_58 . V_531 ;
break;
case V_163 :
* V_518 = V_10 -> V_1 -> V_58 . V_532 ;
break;
case V_133 :
* V_518 = V_10 -> V_17 . V_533 ;
break;
case V_534 :
* V_518 = V_10 -> V_17 . V_535 ;
break;
case V_536 :
* V_518 = 0x01000065 ;
break;
default:
return F_284 ( V_9 , V_517 , V_518 ) ;
}
return 0 ;
}
static int F_285 ( struct V_7 * V_10 )
{
T_1 V_517 = V_10 -> V_9 . V_39 . V_262 [ V_432 ] ;
T_2 V_518 ;
if ( F_283 ( & V_10 -> V_9 , V_517 , & V_518 ) ) {
F_286 ( V_517 ) ;
F_210 ( & V_10 -> V_9 , 0 ) ;
} else {
F_287 ( V_517 , V_518 ) ;
V_10 -> V_9 . V_39 . V_262 [ V_457 ] = V_518 & 0xffffffff ;
V_10 -> V_9 . V_39 . V_262 [ V_278 ] = V_518 >> 32 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_288 ( struct V_8 * V_9 , T_2 V_518 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_537 , V_538 ;
if ( V_518 & ~ V_539 )
return 1 ;
V_538 = V_539 ;
if ( V_10 -> V_17 . V_535 & V_540 )
V_538 &= ~ ( V_541 | V_540 ) ;
V_10 -> V_17 . V_535 &= ~ V_538 ;
V_10 -> V_17 . V_535 |= ( V_518 & V_538 ) ;
V_537 = V_10 -> V_17 . V_535 & V_540 ;
if ( V_537 && ( V_9 -> V_39 . V_54 & V_59 ) )
return 1 ;
return 0 ;
}
static int F_289 ( struct V_8 * V_9 , struct V_542 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_517 = V_42 -> V_146 ;
T_2 V_518 = V_42 -> V_518 ;
switch ( V_517 ) {
case V_519 :
F_290 ( V_9 , V_42 ) ;
break;
case V_520 :
V_10 -> V_1 -> V_58 . V_465 = V_518 ;
break;
#ifdef F_26
case V_521 :
V_10 -> V_1 -> V_58 . V_466 = V_518 ;
break;
case V_522 :
V_10 -> V_1 -> V_58 . V_467 = V_518 ;
break;
case V_303 :
V_10 -> V_1 -> V_58 . V_464 = V_518 ;
break;
case V_523 :
V_10 -> V_1 -> V_58 . V_468 = V_518 ;
break;
#endif
case V_524 :
V_10 -> V_1 -> V_58 . V_469 = V_518 ;
break;
case V_525 :
V_10 -> V_471 = V_518 ;
V_10 -> V_1 -> V_58 . V_471 = V_518 ;
break;
case V_526 :
V_10 -> V_470 = V_518 ;
V_10 -> V_1 -> V_58 . V_470 = V_518 ;
break;
case V_527 :
if ( ! F_84 ( V_543 ) ) {
F_291 ( V_9 , L_14 ,
V_75 , V_518 ) ;
break;
}
if ( V_518 & V_544 )
return 1 ;
V_10 -> V_1 -> V_58 . V_528 = V_518 ;
F_3 ( V_10 -> V_1 , V_545 ) ;
if ( V_518 & ( 1ULL << 0 ) )
F_79 ( V_10 ) ;
else
F_80 ( V_10 ) ;
break;
case V_133 :
V_10 -> V_17 . V_533 = V_518 ;
break;
case V_534 :
return F_288 ( V_9 , V_518 ) ;
case V_546 :
F_291 ( V_9 , L_15 , V_517 , V_518 ) ;
break;
default:
return F_292 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_293 ( struct V_7 * V_10 )
{
struct V_542 V_42 ;
T_1 V_517 = V_10 -> V_9 . V_39 . V_262 [ V_432 ] ;
T_2 V_518 = ( V_10 -> V_9 . V_39 . V_262 [ V_457 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_39 . V_262 [ V_278 ] & - 1u ) << 32 ) ;
V_42 . V_518 = V_518 ;
V_42 . V_146 = V_517 ;
V_42 . V_547 = false ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_289 ( & V_10 -> V_9 , & V_42 ) ) {
F_294 ( V_517 , V_518 ) ;
F_210 ( & V_10 -> V_9 , 0 ) ;
} else {
F_295 ( V_517 , V_518 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_296 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_373 )
return F_293 ( V_10 ) ;
else
return F_285 ( V_10 ) ;
}
static int F_297 ( struct V_7 * V_10 )
{
struct V_378 * V_378 = V_10 -> V_9 . V_379 ;
F_186 ( V_473 , & V_10 -> V_9 ) ;
F_141 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_474 ;
F_3 ( V_10 -> V_1 , V_475 ) ;
++ V_10 -> V_9 . V_301 . V_548 ;
if ( ! F_281 ( V_10 -> V_9 . V_279 ) &&
V_378 -> V_549 &&
! F_298 ( & V_10 -> V_9 ) ) {
V_378 -> V_382 = V_550 ;
return 0 ;
}
return 1 ;
}
static int F_299 ( struct V_7 * V_10 )
{
F_300 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static void F_301 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_207 * V_58 = & V_10 -> V_1 -> V_58 ;
F_55 ( L_16 ) ;
F_55 ( L_17 , L_18 , V_2 -> V_19 & 0xffff ) ;
F_55 ( L_17 , L_19 , V_2 -> V_19 >> 16 ) ;
F_55 ( L_17 , L_20 , V_2 -> V_20 & 0xffff ) ;
F_55 ( L_17 , L_21 , V_2 -> V_20 >> 16 ) ;
F_55 ( L_22 , L_23 , V_2 -> V_21 ) ;
F_55 ( L_24 , L_25 , V_2 -> V_22 ) ;
F_55 ( L_26 , L_27 , V_2 -> V_274 ) ;
F_55 ( L_24 , L_28 , V_2 -> V_244 ) ;
F_55 ( L_24 , L_29 , V_2 -> V_245 ) ;
F_55 ( L_24 , L_30 , V_2 -> V_201 ) ;
F_55 ( L_26 , L_31 , V_2 -> V_51 ) ;
F_55 ( L_26 , L_32 , V_2 -> V_362 ) ;
F_55 ( L_22 , L_33 , V_2 -> V_246 ) ;
F_55 ( L_22 , L_34 , V_2 -> V_448 ) ;
F_55 ( L_22 , L_35 , V_2 -> V_67 ) ;
F_55 ( L_22 , L_36 , V_2 -> V_409 ) ;
F_55 ( L_24 , L_37 , V_2 -> V_373 ) ;
F_55 ( L_24 , L_38 , V_2 -> V_371 ) ;
F_55 ( L_22 , L_39 , V_2 -> V_449 ) ;
F_55 ( L_22 , L_40 , V_2 -> V_450 ) ;
F_55 ( L_41 , L_42 , V_2 -> V_270 ) ;
F_55 ( L_24 , L_43 , V_2 -> V_403 ) ;
F_55 ( L_22 , L_44 , V_2 -> V_90 ) ;
F_55 ( L_22 , L_45 , V_2 -> V_93 ) ;
F_55 ( L_41 , L_46 , V_2 -> V_159 ) ;
F_55 ( L_24 , L_47 , V_2 -> V_71 ) ;
F_55 ( L_48 ) ;
F_55 ( L_49 ,
L_50 ,
V_58 -> V_248 . V_183 , V_58 -> V_248 . V_184 ,
V_58 -> V_248 . V_188 , V_58 -> V_248 . V_88 ) ;
F_55 ( L_49 ,
L_51 ,
V_58 -> V_87 . V_183 , V_58 -> V_87 . V_184 ,
V_58 -> V_87 . V_188 , V_58 -> V_87 . V_88 ) ;
F_55 ( L_49 ,
L_52 ,
V_58 -> V_249 . V_183 , V_58 -> V_249 . V_184 ,
V_58 -> V_249 . V_188 , V_58 -> V_249 . V_88 ) ;
F_55 ( L_49 ,
L_53 ,
V_58 -> V_250 . V_183 , V_58 -> V_250 . V_184 ,
V_58 -> V_250 . V_188 , V_58 -> V_250 . V_88 ) ;
F_55 ( L_49 ,
L_54 ,
V_58 -> V_251 . V_183 , V_58 -> V_251 . V_184 ,
V_58 -> V_251 . V_188 , V_58 -> V_251 . V_88 ) ;
F_55 ( L_49 ,
L_55 ,
V_58 -> V_252 . V_183 , V_58 -> V_252 . V_184 ,
V_58 -> V_252 . V_188 , V_58 -> V_252 . V_88 ) ;
F_55 ( L_49 ,
L_56 ,
V_58 -> V_255 . V_183 , V_58 -> V_255 . V_184 ,
V_58 -> V_255 . V_188 , V_58 -> V_255 . V_88 ) ;
F_55 ( L_49 ,
L_57 ,
V_58 -> V_257 . V_183 , V_58 -> V_257 . V_184 ,
V_58 -> V_257 . V_188 , V_58 -> V_257 . V_88 ) ;
F_55 ( L_49 ,
L_58 ,
V_58 -> V_256 . V_183 , V_58 -> V_256 . V_184 ,
V_58 -> V_256 . V_188 , V_58 -> V_256 . V_88 ) ;
F_55 ( L_49 ,
L_59 ,
V_58 -> V_259 . V_183 , V_58 -> V_259 . V_184 ,
V_58 -> V_259 . V_188 , V_58 -> V_259 . V_88 ) ;
F_55 ( L_60 ,
V_58 -> V_306 , V_58 -> V_54 ) ;
F_55 ( L_61 ,
L_62 , V_58 -> V_264 , L_63 , V_58 -> V_421 ) ;
F_55 ( L_61 ,
L_64 , V_58 -> V_272 , L_65 , V_58 -> V_268 ) ;
F_55 ( L_61 ,
L_66 , V_58 -> V_261 , L_67 , V_58 -> V_367 ) ;
F_55 ( L_61 ,
L_68 , V_58 -> V_84 , L_69 , V_58 -> V_307 ) ;
F_55 ( L_61 ,
L_70 , V_58 -> V_453 , L_71 , V_58 -> V_454 ) ;
F_55 ( L_61 ,
L_72 , V_58 -> V_465 , L_73 , V_58 -> V_466 ) ;
F_55 ( L_61 ,
L_74 , V_58 -> V_467 , L_75 , V_58 -> V_468 ) ;
F_55 ( L_61 ,
L_76 , V_58 -> V_464 ,
L_77 , V_58 -> V_469 ) ;
F_55 ( L_61 ,
L_78 , V_58 -> V_470 ,
L_79 , V_58 -> V_471 ) ;
F_55 ( L_61 ,
L_80 , V_58 -> V_271 , L_81 , V_58 -> V_528 ) ;
F_55 ( L_61 ,
L_82 , V_58 -> V_529 , L_83 , V_58 -> V_530 ) ;
F_55 ( L_61 ,
L_84 , V_58 -> V_531 ,
L_85 , V_58 -> V_532 ) ;
}
static void F_302 ( struct V_8 * V_9 , T_2 * V_551 , T_2 * V_552 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_551 = V_2 -> V_373 ;
* V_552 = V_2 -> V_371 ;
}
static int F_303 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_378 * V_378 = V_9 -> V_379 ;
T_1 V_409 = V_10 -> V_1 -> V_2 . V_409 ;
if ( ! F_11 ( V_10 , V_212 ) )
V_9 -> V_39 . V_264 = V_10 -> V_1 -> V_58 . V_264 ;
if ( V_55 )
V_9 -> V_39 . V_272 = V_10 -> V_1 -> V_58 . V_272 ;
if ( F_125 ( V_10 -> V_17 . V_423 ) ) {
F_205 ( V_10 ) ;
V_10 -> V_17 . V_423 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_419 ;
F_304 ( V_10 -> V_1 -> V_58 . V_84 , V_409 ,
V_10 -> V_1 -> V_2 . V_373 ,
V_10 -> V_1 -> V_2 . V_371 ,
V_10 -> V_1 -> V_2 . V_449 ,
V_10 -> V_1 -> V_2 . V_450 ,
V_452 ) ;
V_419 = F_226 ( V_10 ) ;
if ( V_419 == V_434 )
V_419 = F_227 ( V_10 ) ;
if ( V_419 == V_422 )
return 1 ;
}
F_305 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_409 == V_442 ) {
V_378 -> V_382 = V_553 ;
V_378 -> V_554 . V_555
= V_10 -> V_1 -> V_2 . V_409 ;
F_55 ( L_86 ) ;
F_301 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_449 ) &&
V_409 != V_420 + V_216 &&
V_409 != V_410 && V_409 != V_556 &&
V_409 != V_426 && V_409 != V_427 )
F_33 ( V_77 L_87
L_88 ,
V_75 , V_10 -> V_1 -> V_2 . V_449 ,
V_409 ) ;
if ( V_409 >= F_306 ( V_557 )
|| ! V_557 [ V_409 ] ) {
V_378 -> V_382 = V_558 ;
V_378 -> V_559 . V_560 = V_409 ;
return 0 ;
}
return V_557 [ V_409 ] ( V_10 ) ;
}
static void F_307 ( struct V_8 * V_9 )
{
int V_141 = F_53 () ;
struct V_114 * V_115 = F_56 ( V_124 , V_141 ) ;
V_115 -> V_130 -> type = 9 ;
F_308 () ;
}
static void F_309 ( struct V_7 * V_10 )
{
int V_141 = F_53 () ;
struct V_114 * V_115 = F_56 ( V_124 , V_141 ) ;
if ( V_10 -> V_125 != V_115 -> V_125 )
F_161 ( V_10 , V_115 ) ;
}
static void F_310 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_561 ;
V_9 -> V_39 . V_40 |= V_562 ;
F_16 ( V_10 , V_505 ) ;
++ V_9 -> V_301 . V_563 ;
}
static inline void F_311 ( struct V_7 * V_10 , int V_564 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_448 = V_564 ;
V_2 -> V_246 &= ~ V_565 ;
V_2 -> V_246 |= V_474 |
( ( 0xf ) << V_566 ) ;
F_3 ( V_10 -> V_1 , V_475 ) ;
}
static void F_312 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_72 ( ! ( F_20 ( V_10 ) ) ) ;
F_313 ( V_9 -> V_39 . V_567 . V_78 ) ;
++ V_9 -> V_301 . V_568 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_567 . V_78 |
V_63 | V_64 ;
}
static void F_314 ( struct V_8 * V_9 , int V_569 , int V_570 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_424 ) )
return;
F_10 ( V_10 , V_215 ) ;
if ( V_570 == - 1 )
return;
if ( V_569 >= V_570 )
F_9 ( V_10 , V_215 ) ;
}
static void F_315 ( struct V_8 * V_9 , bool V_571 )
{
return;
}
static int F_316 ( struct V_279 * V_279 )
{
return 0 ;
}
static void F_317 ( struct V_8 * V_9 , T_2 * V_572 )
{
return;
}
static void F_318 ( struct V_279 * V_279 , int V_573 )
{
return;
}
static void F_319 ( struct V_8 * V_9 )
{
return;
}
static int F_320 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_66 ;
V_66 = ! ( V_1 -> V_2 . V_67 & V_68 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_562 ) ;
V_66 = V_66 && F_20 ( V_10 ) && F_214 ( V_10 ) ;
return V_66 ;
}
static bool F_321 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_562 ) ;
}
static void F_322 ( struct V_8 * V_9 , bool V_574 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_574 ) {
V_10 -> V_9 . V_39 . V_40 |= V_562 ;
F_16 ( V_10 , V_505 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_562 ;
F_17 ( V_10 , V_505 ) ;
}
}
static int F_323 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_66 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_67 & V_68 ) )
return 0 ;
V_66 = ! ! ( F_232 ( V_9 ) & V_461 ) ;
if ( F_7 ( V_9 ) )
return V_66 && ! ( V_10 -> V_9 . V_39 . V_40 & V_424 ) ;
return V_66 ;
}
static void F_324 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_212 ( V_10 ) ) {
F_140 ( V_10 ) ;
F_311 ( V_10 , 0x0 ) ;
}
}
static void F_325 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_562 | V_506 ) )
== V_562 )
return;
V_10 -> V_356 = true ;
V_10 -> V_1 -> V_58 . V_307 |= ( V_380 | V_381 ) ;
F_160 ( V_9 ) ;
}
static int F_326 ( struct V_279 * V_279 , unsigned int V_50 )
{
return 0 ;
}
static void F_158 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_575 ) )
V_10 -> V_1 -> V_2 . V_362 = V_576 ;
else
V_10 -> V_125 -- ;
}
static void F_327 ( struct V_8 * V_9 )
{
}
static inline void F_328 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_424 ) )
return;
if ( ! F_11 ( V_10 , V_215 ) ) {
int V_577 = V_10 -> V_1 -> V_2 . V_246 & V_578 ;
F_274 ( V_9 , V_577 ) ;
}
}
static inline void F_329 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_577 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_424 ) )
return;
V_577 = F_276 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_578 ;
V_10 -> V_1 -> V_2 . V_246 |= V_577 & V_578 ;
}
static void F_305 ( struct V_7 * V_10 )
{
T_4 V_579 ;
int type ;
T_1 V_580 = V_10 -> V_1 -> V_2 . V_449 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_506 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_507 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_562 | V_506 ) ;
F_186 ( V_473 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_492 = false ;
F_233 ( & V_10 -> V_9 ) ;
F_234 ( & V_10 -> V_9 ) ;
if ( ! ( V_580 & V_484 ) )
return;
F_186 ( V_473 , & V_10 -> V_9 ) ;
V_579 = V_580 & V_581 ;
type = V_580 & V_480 ;
switch ( type ) {
case V_491 :
V_10 -> V_9 . V_39 . V_492 = true ;
break;
case V_493 :
if ( F_330 ( V_579 ) ) {
if ( V_579 == V_82 && V_89 &&
F_331 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_580 & V_582 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_450 ;
F_332 ( & V_10 -> V_9 , V_579 , V_96 ) ;
} else
F_333 ( & V_10 -> V_9 , V_579 ) ;
break;
case V_495 :
F_334 ( & V_10 -> V_9 , V_579 , false ) ;
break;
default:
break;
}
}
static void F_335 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_449 = V_2 -> V_90 ;
V_2 -> V_450 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_305 ( V_10 ) ;
}
static void F_336 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_454 = V_9 -> V_39 . V_262 [ V_457 ] ;
V_10 -> V_1 -> V_58 . V_453 = V_9 -> V_39 . V_262 [ V_458 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_262 [ V_263 ] ;
if ( F_125 ( V_10 -> V_17 . V_423 ) )
return;
F_309 ( V_10 ) ;
F_329 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_421 = V_9 -> V_39 . V_421 ;
F_22 () ;
F_174 () ;
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
F_49 ( V_295 , V_10 -> V_205 . V_296 ) ;
#else
F_130 ( V_251 , V_10 -> V_205 . V_251 ) ;
#ifndef F_132
F_130 ( V_252 , V_10 -> V_205 . V_252 ) ;
#endif
#endif
F_307 ( V_9 ) ;
F_172 () ;
V_9 -> V_39 . V_421 = V_10 -> V_1 -> V_58 . V_421 ;
V_9 -> V_39 . V_262 [ V_457 ] = V_10 -> V_1 -> V_58 . V_454 ;
V_9 -> V_39 . V_262 [ V_458 ] = V_10 -> V_1 -> V_58 . V_453 ;
V_9 -> V_39 . V_262 [ V_263 ] = V_10 -> V_1 -> V_58 . V_84 ;
F_337 ( V_10 -> V_1 -> V_2 . V_409 , V_9 , V_452 ) ;
if ( F_125 ( V_10 -> V_1 -> V_2 . V_409 == V_427 ) )
F_338 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_125 ( V_10 -> V_1 -> V_2 . V_409 == V_427 ) )
F_339 ( & V_10 -> V_9 ) ;
F_328 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_362 = V_583 ;
if ( V_10 -> V_1 -> V_2 . V_409 == V_420 + V_216 )
V_10 -> V_372 = F_340 () ;
if ( V_55 ) {
V_9 -> V_39 . V_584 &= ~ ( 1 << V_312 ) ;
V_9 -> V_39 . V_585 &= ~ ( 1 << V_312 ) ;
}
if ( F_125 ( V_10 -> V_1 -> V_2 . V_409 ==
V_420 + V_218 ) )
F_185 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_341 ( struct V_8 * V_9 , unsigned long V_405 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_272 = V_405 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_158 ( V_9 ) ;
}
static void F_342 ( struct V_8 * V_9 , unsigned long V_405 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_403 = V_405 ;
F_3 ( V_10 -> V_1 , V_406 ) ;
V_10 -> V_1 -> V_58 . V_272 = F_139 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_158 ( V_9 ) ;
}
static int F_343 ( void )
{
T_2 V_586 ;
F_54 ( V_534 , V_586 ) ;
if ( V_586 & ( 1 << V_587 ) )
return 1 ;
return 0 ;
}
static void
F_344 ( struct V_8 * V_9 , unsigned char * V_588 )
{
V_588 [ 0 ] = 0x0f ;
V_588 [ 1 ] = 0x01 ;
V_588 [ 2 ] = 0xd9 ;
}
static void F_345 ( void * V_589 )
{
* ( int * ) V_589 = 0 ;
}
static bool F_346 ( void )
{
return false ;
}
static T_2 F_347 ( struct V_8 * V_9 , T_11 V_590 , bool V_591 )
{
return 0 ;
}
static void F_348 ( struct V_8 * V_9 )
{
}
static void F_349 ( T_1 V_592 , struct V_593 * V_594 )
{
switch ( V_592 ) {
case 0x80000001 :
if ( V_17 )
V_594 -> V_517 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_594 -> V_277 = 1 ;
V_594 -> V_595 = 8 ;
V_594 -> V_517 = 0 ;
V_594 -> V_596 = 0 ;
if ( F_84 ( V_83 ) )
V_594 -> V_596 |= V_597 ;
if ( V_55 )
V_594 -> V_596 |= V_598 ;
break;
}
}
static int F_350 ( void )
{
return V_599 ;
}
static bool F_351 ( void )
{
return false ;
}
static bool F_352 ( void )
{
return false ;
}
static bool F_353 ( void )
{
return false ;
}
static bool F_354 ( void )
{
return true ;
}
static void F_355 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_389 ) ;
F_153 ( V_10 ) ;
}
static int F_356 ( struct V_8 * V_9 ,
struct V_600 * V_61 ,
enum V_601 V_602 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_419 , V_66 = V_603 ;
struct V_604 V_605 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_306 ( V_606 ) )
goto V_285;
V_605 = V_606 [ V_61 -> V_22 ] ;
if ( V_602 != V_605 . V_602 )
goto V_285;
switch ( V_605 . V_409 ) {
case V_437 :
if ( V_61 -> V_22 == V_607 )
V_605 . V_409 += V_61 -> V_608 ;
break;
case V_609 : {
unsigned long V_264 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_610 )
V_605 . V_409 += V_61 -> V_608 ;
if ( V_605 . V_409 != V_609 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_222 ) ) )
break;
V_264 = V_9 -> V_39 . V_264 & ~ V_345 ;
V_97 = V_61 -> V_611 & ~ V_345 ;
if ( V_61 -> V_22 == V_612 ) {
V_264 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_264 & V_456 )
V_97 |= V_456 ;
}
if ( V_264 ^ V_97 )
V_605 . V_409 = V_509 ;
break;
}
case V_439 :
case V_613 :
V_605 . V_409 += V_61 -> V_608 ;
break;
case V_435 :
if ( V_61 -> V_22 == V_614 )
V_1 -> V_2 . V_373 = 1 ;
else
V_1 -> V_2 . V_373 = 0 ;
break;
case V_615 :
if ( V_61 -> V_616 != V_617 )
goto V_285;
case V_436 : {
T_2 V_618 ;
T_1 V_619 ;
V_618 = ( V_9 -> V_39 . V_262 [ V_278 ] & 0xffff ) << 16 ;
if ( V_61 -> V_22 == V_620 ||
V_61 -> V_22 == V_621 ) {
V_618 |= V_399 ;
V_619 = V_61 -> V_622 ;
} else {
V_619 = V_61 -> V_623 ;
}
if ( V_61 -> V_22 == V_624 ||
V_61 -> V_22 == V_621 )
V_618 |= V_398 ;
if ( V_61 -> V_616 )
V_618 |= V_625 ;
V_619 = F_86 ( V_619 , 4u ) ;
V_618 |= V_619 << V_401 ;
V_618 |= ( T_1 ) V_61 -> V_626 << ( V_627 - 1 ) ;
V_1 -> V_2 . V_373 = V_618 ;
V_1 -> V_2 . V_371 = V_61 -> V_71 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_409 = V_605 . V_409 ;
V_419 = F_227 ( V_10 ) ;
V_66 = ( V_419 == V_422 ) ? V_628
: V_603 ;
V_285:
return V_66 ;
}
static void F_357 ( struct V_8 * V_9 )
{
F_174 () ;
}
static int T_5 F_358 ( void )
{
return F_359 ( & V_629 , sizeof( struct V_7 ) ,
F_360 ( struct V_7 ) , V_630 ) ;
}
static void T_6 F_361 ( void )
{
F_362 () ;
}
