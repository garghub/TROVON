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
static unsigned long F_133 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_306 ;
}
static void F_134 ( struct V_8 * V_9 , unsigned long V_306 )
{
F_4 ( V_9 ) -> V_1 -> V_58 . V_306 = V_306 ;
}
static void F_135 ( struct V_8 * V_9 , enum V_307 V_308 )
{
switch ( V_308 ) {
case V_309 :
F_72 ( ! V_55 ) ;
F_136 ( V_9 , V_9 -> V_39 . V_310 , F_137 ( V_9 ) ) ;
break;
default:
F_77 () ;
}
}
static void F_138 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_311 ) ;
}
static void F_139 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_311 ) ;
}
static struct V_181 * F_140 ( struct V_8 * V_9 , int V_182 )
{
struct V_207 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_182 ) {
case V_312 : return & V_58 -> V_87 ;
case V_313 : return & V_58 -> V_250 ;
case V_314 : return & V_58 -> V_248 ;
case V_315 : return & V_58 -> V_251 ;
case V_316 : return & V_58 -> V_252 ;
case V_317 : return & V_58 -> V_249 ;
case V_318 : return & V_58 -> V_259 ;
case V_319 : return & V_58 -> V_257 ;
}
F_77 () ;
return NULL ;
}
static T_2 F_141 ( struct V_8 * V_9 , int V_182 )
{
struct V_181 * V_320 = F_140 ( V_9 , V_182 ) ;
return V_320 -> V_88 ;
}
static void F_142 ( struct V_8 * V_9 ,
struct V_321 * V_322 , int V_182 )
{
struct V_181 * V_320 = F_140 ( V_9 , V_182 ) ;
V_322 -> V_88 = V_320 -> V_88 ;
V_322 -> V_188 = V_320 -> V_188 ;
V_322 -> V_183 = V_320 -> V_183 ;
V_322 -> type = V_320 -> V_184 & V_323 ;
V_322 -> V_320 = ( V_320 -> V_184 >> V_324 ) & 1 ;
V_322 -> V_325 = ( V_320 -> V_184 >> V_326 ) & 3 ;
V_322 -> V_327 = ( V_320 -> V_184 >> V_328 ) & 1 ;
V_322 -> V_329 = ( V_320 -> V_184 >> V_330 ) & 1 ;
V_322 -> V_331 = ( V_320 -> V_184 >> V_332 ) & 1 ;
V_322 -> V_333 = ( V_320 -> V_184 >> V_334 ) & 1 ;
V_322 -> V_15 = ( V_320 -> V_184 >> V_335 ) & 1 ;
V_322 -> V_336 = ! V_322 -> V_327 || ( V_322 -> type == 0 ) ;
switch ( V_182 ) {
case V_312 :
V_322 -> V_15 = V_320 -> V_188 > 0xfffff ;
break;
case V_318 :
V_322 -> type |= 0x2 ;
break;
case V_313 :
case V_314 :
case V_315 :
case V_316 :
if ( ! V_322 -> V_336 )
V_322 -> type |= 0x1 ;
break;
case V_317 :
if ( V_322 -> V_336 )
V_322 -> V_333 = 0 ;
V_322 -> V_325 = F_4 ( V_9 ) -> V_1 -> V_58 . V_337 ;
break;
}
}
static int F_143 ( struct V_8 * V_9 )
{
struct V_207 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_337 ;
}
static void F_144 ( struct V_8 * V_9 , struct V_116 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_338 -> V_339 = V_10 -> V_1 -> V_58 . V_256 . V_188 ;
V_338 -> V_129 = V_10 -> V_1 -> V_58 . V_256 . V_88 ;
}
static void F_145 ( struct V_8 * V_9 , struct V_116 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_256 . V_188 = V_338 -> V_339 ;
V_10 -> V_1 -> V_58 . V_256 . V_88 = V_338 -> V_129 ;
F_3 ( V_10 -> V_1 , V_340 ) ;
}
static void F_146 ( struct V_8 * V_9 , struct V_116 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_338 -> V_339 = V_10 -> V_1 -> V_58 . V_255 . V_188 ;
V_338 -> V_129 = V_10 -> V_1 -> V_58 . V_255 . V_88 ;
}
static void F_147 ( struct V_8 * V_9 , struct V_116 * V_338 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_255 . V_188 = V_338 -> V_339 ;
V_10 -> V_1 -> V_58 . V_255 . V_88 = V_338 -> V_129 ;
F_3 ( V_10 -> V_1 , V_340 ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
}
static void F_149 ( struct V_8 * V_9 )
{
}
static void F_150 ( struct V_8 * V_9 )
{
}
static void F_151 ( struct V_7 * V_10 )
{
T_9 V_341 = V_10 -> V_9 . V_39 . V_264 ;
T_2 * V_342 = & V_10 -> V_1 -> V_58 . V_264 ;
if ( ! V_10 -> V_9 . V_208 )
* V_342 |= V_343 ;
else
* V_342 = ( * V_342 & ~ V_343 )
| ( V_341 & V_343 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_341 == * V_342 && V_10 -> V_9 . V_208 ) {
F_10 ( V_10 , V_209 ) ;
F_10 ( V_10 , V_212 ) ;
} else {
F_9 ( V_10 , V_209 ) ;
F_9 ( V_10 , V_212 ) ;
}
}
static void F_152 ( struct V_8 * V_9 , unsigned long V_264 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_153 ( V_9 ) && ( V_264 & V_344 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_153 ( V_9 ) && ! ( V_264 & V_344 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_264 = V_264 ;
if ( ! V_55 )
V_264 |= V_344 | V_345 ;
if ( ! V_9 -> V_208 )
V_264 |= V_346 ;
V_264 &= ~ ( V_266 | V_265 ) ;
V_10 -> V_1 -> V_58 . V_264 = V_264 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_151 ( V_10 ) ;
}
static int F_154 ( struct V_8 * V_9 , unsigned long V_268 )
{
unsigned long V_347 = F_155 () & V_348 ;
unsigned long V_349 = F_4 ( V_9 ) -> V_1 -> V_58 . V_268 ;
if ( V_268 & V_350 )
return 1 ;
if ( V_55 && ( ( V_349 ^ V_268 ) & V_351 ) )
F_156 ( V_9 ) ;
V_9 -> V_39 . V_268 = V_268 ;
if ( ! V_55 )
V_268 |= V_269 ;
V_268 |= V_347 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_268 = V_268 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_157 ( struct V_8 * V_9 ,
struct V_321 * V_322 , int V_182 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_181 * V_320 = F_140 ( V_9 , V_182 ) ;
V_320 -> V_88 = V_322 -> V_88 ;
V_320 -> V_188 = V_322 -> V_188 ;
V_320 -> V_183 = V_322 -> V_183 ;
if ( V_322 -> V_336 )
V_320 -> V_184 = 0 ;
else {
V_320 -> V_184 = ( V_322 -> type & V_323 ) ;
V_320 -> V_184 |= ( V_322 -> V_320 & 1 ) << V_324 ;
V_320 -> V_184 |= ( V_322 -> V_325 & 3 ) << V_326 ;
V_320 -> V_184 |= ( V_322 -> V_327 & 1 ) << V_328 ;
V_320 -> V_184 |= ( V_322 -> V_329 & 1 ) << V_330 ;
V_320 -> V_184 |= ( V_322 -> V_331 & 1 ) << V_332 ;
V_320 -> V_184 |= ( V_322 -> V_333 & 1 ) << V_334 ;
V_320 -> V_184 |= ( V_322 -> V_15 & 1 ) << V_335 ;
}
if ( V_182 == V_317 )
V_10 -> V_1 -> V_58 . V_337 = ( V_320 -> V_184 >> V_326 ) & 3 ;
F_3 ( V_10 -> V_1 , V_352 ) ;
}
static void F_158 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_353 ) ;
F_15 ( V_10 , V_82 ) ;
if ( V_10 -> V_354 )
F_14 ( V_10 , V_353 ) ;
if ( V_9 -> V_355 & V_356 ) {
if ( V_9 -> V_355 &
( V_357 | V_358 ) )
F_14 ( V_10 , V_353 ) ;
if ( V_9 -> V_355 & V_359 )
F_14 ( V_10 , V_82 ) ;
} else
V_9 -> V_355 = 0 ;
}
static void F_159 ( struct V_7 * V_10 , struct V_114 * V_115 )
{
if ( V_115 -> V_128 > V_115 -> V_126 ) {
++ V_115 -> V_125 ;
V_115 -> V_128 = 1 ;
V_10 -> V_1 -> V_2 . V_360 = V_361 ;
}
V_10 -> V_125 = V_115 -> V_125 ;
V_10 -> V_1 -> V_2 . V_51 = V_115 -> V_128 ++ ;
F_3 ( V_10 -> V_1 , V_362 ) ;
}
static T_2 F_160 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_261 ;
}
static void F_161 ( struct V_8 * V_9 , unsigned long V_363 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_261 = V_363 ;
F_3 ( V_10 -> V_1 , V_364 ) ;
}
static void F_162 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_163 ( V_9 -> V_39 . V_333 [ 0 ] , 0 ) ;
F_163 ( V_9 -> V_39 . V_333 [ 1 ] , 1 ) ;
F_163 ( V_9 -> V_39 . V_333 [ 2 ] , 2 ) ;
F_163 ( V_9 -> V_39 . V_333 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_261 = F_160 ( V_9 ) ;
V_9 -> V_39 . V_365 = V_10 -> V_1 -> V_58 . V_365 ;
V_9 -> V_39 . V_366 &= ~ V_367 ;
F_12 ( V_10 ) ;
}
static void F_164 ( struct V_8 * V_9 , unsigned long V_363 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_365 = V_363 ;
F_3 ( V_10 -> V_1 , V_364 ) ;
}
static int F_165 ( struct V_7 * V_10 )
{
T_2 V_368 = V_10 -> V_1 -> V_2 . V_369 ;
T_1 V_80 ;
int V_142 = 1 ;
switch ( V_10 -> V_370 ) {
default:
V_80 = V_10 -> V_1 -> V_2 . V_371 ;
F_166 ( V_368 , V_80 ) ;
if ( ! V_55 && F_167 ( & V_10 -> V_9 ) )
F_168 ( & V_10 -> V_9 , V_368 ) ;
V_142 = F_169 ( & V_10 -> V_9 , V_368 , V_80 ,
V_10 -> V_1 -> V_2 . V_372 ,
V_10 -> V_1 -> V_2 . V_373 ) ;
break;
case V_374 :
V_10 -> V_370 = 0 ;
F_170 () ;
F_171 ( V_368 ) ;
F_172 () ;
break;
case V_375 :
V_10 -> V_370 = 0 ;
F_170 () ;
F_173 ( V_368 ) ;
F_172 () ;
break;
}
return V_142 ;
}
static int F_174 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
if ( ! ( V_10 -> V_9 . V_355 &
( V_357 | V_358 ) ) &&
! V_10 -> V_354 ) {
F_175 ( & V_10 -> V_9 , V_353 ) ;
return 1 ;
}
if ( V_10 -> V_354 ) {
V_10 -> V_354 = false ;
if ( ! ( V_10 -> V_9 . V_355 & V_357 ) )
V_10 -> V_1 -> V_58 . V_306 &=
~ ( V_378 | V_379 ) ;
F_158 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_355 &
( V_357 | V_358 ) ) {
V_376 -> V_380 = V_381 ;
V_376 -> V_382 . V_39 . V_383 =
V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_376 -> V_382 . V_39 . V_384 = V_353 ;
return 0 ;
}
return 1 ;
}
static int F_176 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
V_376 -> V_380 = V_381 ;
V_376 -> V_382 . V_39 . V_383 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_376 -> V_382 . V_39 . V_384 = V_82 ;
return 0 ;
}
static int F_177 ( struct V_7 * V_10 )
{
int V_385 ;
V_385 = F_32 ( & V_10 -> V_9 , V_386 ) ;
if ( V_385 != V_73 )
F_175 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static void F_178 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_387 ) ;
V_10 -> V_9 . V_208 = 1 ;
F_151 ( V_10 ) ;
}
static int F_179 ( struct V_7 * V_10 )
{
F_178 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_180 ( void )
{
int V_96 , V_44 ;
T_2 V_363 ;
if ( ! V_100 )
return false ;
V_363 = F_41 ( V_388 , & V_96 ) ;
if ( V_96 )
return false ;
V_363 &= ~ ( 1ULL << 62 ) ;
if ( V_363 != 0xb600000000010015ULL )
return false ;
for ( V_44 = 0 ; V_44 < 6 ; ++ V_44 )
F_44 ( F_181 ( V_44 ) , 0 , 0 ) ;
V_363 = F_41 ( V_389 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_363 &= ~ ( 1ULL << 2 ) ;
V_94 = F_42 ( V_363 ) ;
V_95 = F_43 ( V_363 ) ;
F_44 ( V_389 , V_94 , V_95 ) ;
}
F_182 () ;
return true ;
}
static void F_183 ( struct V_7 * V_10 )
{
if ( F_180 () ) {
F_55 ( L_11 ) ;
F_184 ( V_390 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_185 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_186 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
F_117 ( V_10 -> V_1 ) ;
F_107 ( V_10 ) ;
V_376 -> V_380 = V_391 ;
return 0 ;
}
static int F_187 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_392 = V_10 -> V_1 -> V_2 . V_371 ;
int V_339 , V_393 , string ;
unsigned V_394 ;
++ V_10 -> V_9 . V_301 . V_395 ;
string = ( V_392 & V_396 ) != 0 ;
V_393 = ( V_392 & V_397 ) != 0 ;
if ( string || V_393 )
return F_32 ( V_9 , 0 ) == V_73 ;
V_394 = V_392 >> 16 ;
V_339 = ( V_392 & V_398 ) >> V_399 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_369 ;
F_31 ( & V_10 -> V_9 ) ;
return F_188 ( V_9 , V_339 , V_394 ) ;
}
static int F_189 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_190 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_301 . V_400 ;
return 1 ;
}
static int F_191 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_192 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 1 ;
F_31 ( & V_10 -> V_9 ) ;
return F_193 ( & V_10 -> V_9 ) ;
}
static int F_194 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_195 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_196 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_401 ;
}
static T_2 F_197 ( struct V_8 * V_9 , int V_146 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_272 = V_10 -> V_17 . V_401 ;
T_2 V_402 ;
int V_66 ;
V_66 = F_198 ( V_9 -> V_279 , F_199 ( V_272 ) , & V_402 ,
F_200 ( V_272 ) + V_146 * 8 , 8 ) ;
if ( V_66 )
return 0 ;
return V_402 ;
}
static void F_201 ( struct V_8 * V_9 ,
unsigned long V_403 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_401 = V_403 ;
F_3 ( V_10 -> V_1 , V_404 ) ;
F_156 ( V_9 ) ;
}
static void F_202 ( struct V_8 * V_9 ,
struct V_405 * V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_407 = V_408 ;
V_10 -> V_1 -> V_2 . V_409 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = V_406 -> V_80 ;
V_10 -> V_1 -> V_2 . V_369 = V_406 -> V_129 ;
F_203 ( V_10 ) ;
}
static void F_204 ( struct V_8 * V_9 )
{
F_205 ( V_9 , & V_9 -> V_39 . V_410 ) ;
V_9 -> V_39 . V_410 . V_411 = F_201 ;
V_9 -> V_39 . V_410 . V_412 = F_196 ;
V_9 -> V_39 . V_410 . V_413 = F_197 ;
V_9 -> V_39 . V_410 . V_414 = F_202 ;
V_9 -> V_39 . V_410 . V_415 = F_25 () ;
V_9 -> V_39 . V_310 = & V_9 -> V_39 . V_416 ;
}
static void F_206 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_310 = & V_9 -> V_39 . V_410 ;
}
static int F_207 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_153 ( & V_10 -> V_9 ) ) {
F_175 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_337 ) {
F_208 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_10 , unsigned V_78 ,
bool V_79 , T_1 V_80 )
{
int V_417 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_407 = V_418 + V_78 ;
V_10 -> V_1 -> V_2 . V_409 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = V_80 ;
V_10 -> V_1 -> V_2 . V_369 = V_10 -> V_9 . V_39 . V_419 ;
V_417 = F_209 ( V_10 ) ;
if ( V_417 == V_420 )
V_10 -> V_17 . V_421 = true ;
return V_417 ;
}
static inline bool F_210 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_422 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_423 ) )
return false ;
if ( V_10 -> V_17 . V_421 )
return false ;
V_10 -> V_1 -> V_2 . V_407 = V_424 ;
V_10 -> V_1 -> V_2 . V_371 = 0 ;
V_10 -> V_1 -> V_2 . V_369 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_421 = true ;
F_211 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_212 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_220 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_407 = V_425 ;
V_10 -> V_17 . V_421 = true ;
return false ;
}
static void * F_213 ( struct V_7 * V_10 , T_2 V_426 , struct V_164 * * V_427 )
{
struct V_164 * V_164 ;
F_214 () ;
V_164 = F_215 ( V_10 -> V_9 . V_279 , V_426 >> V_135 ) ;
if ( F_216 ( V_164 ) )
goto error;
* V_427 = V_164 ;
return F_217 ( V_164 ) ;
error:
F_208 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_218 ( struct V_164 * V_164 )
{
F_219 ( V_164 ) ;
F_220 ( V_164 ) ;
}
static int F_221 ( struct V_7 * V_10 )
{
unsigned V_394 ;
T_4 V_97 , V_6 ;
T_2 V_426 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return V_428 ;
V_394 = V_10 -> V_1 -> V_2 . V_371 >> 16 ;
V_426 = V_10 -> V_17 . V_429 + ( V_394 / 8 ) ;
V_6 = V_394 % 8 ;
V_97 = 0 ;
if ( F_222 ( V_10 -> V_9 . V_279 , V_426 , & V_97 , 1 ) )
V_97 &= ( 1 << V_6 ) ;
return V_97 ? V_420 : V_428 ;
}
static int F_223 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_363 ;
int V_150 , V_65 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_230 ) ) )
return V_428 ;
V_42 = V_10 -> V_9 . V_39 . V_262 [ V_430 ] ;
V_43 = F_21 ( V_42 ) ;
V_150 = V_10 -> V_1 -> V_2 . V_371 & 1 ;
V_65 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_150 ) ;
if ( V_43 == V_49 )
return V_420 ;
V_43 *= 4 ;
if ( F_222 ( V_10 -> V_9 . V_279 , V_10 -> V_17 . V_431 + V_43 , & V_363 , 4 ) )
return V_420 ;
return ( V_363 & V_65 ) ? V_420 : V_428 ;
}
static int F_224 ( struct V_7 * V_10 )
{
T_1 V_407 = V_10 -> V_1 -> V_2 . V_407 ;
switch ( V_407 ) {
case V_424 :
case V_425 :
case V_418 + V_218 :
return V_428 ;
case V_408 :
if ( V_55 )
return V_428 ;
break;
case V_418 + V_216 :
if ( ! V_55 && V_10 -> V_370 == 0 )
return V_428 ;
break;
case V_418 + V_387 :
F_179 ( V_10 ) ;
break;
default:
break;
}
return V_432 ;
}
static int F_209 ( struct V_7 * V_10 )
{
T_1 V_407 = V_10 -> V_1 -> V_2 . V_407 ;
int V_417 = V_428 ;
switch ( V_407 ) {
case V_433 :
V_417 = F_223 ( V_10 ) ;
break;
case V_434 :
V_417 = F_221 ( V_10 ) ;
break;
case V_435 ... V_436 : {
T_1 V_6 = 1U << ( V_407 - V_435 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_417 = V_420 ;
break;
}
case V_437 ... V_438 : {
T_1 V_6 = 1U << ( V_407 - V_437 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_417 = V_420 ;
break;
}
case V_418 ... V_418 + 0x1f : {
T_1 V_439 = 1 << ( V_407 - V_418 ) ;
if ( V_10 -> V_17 . V_21 & V_439 )
V_417 = V_420 ;
else if ( ( V_407 == V_418 + V_216 ) &&
V_10 -> V_370 != 0 )
V_417 = V_420 ;
break;
}
case V_440 : {
V_417 = V_420 ;
break;
}
default: {
T_2 V_441 = 1ULL << ( V_407 - V_424 ) ;
if ( V_10 -> V_17 . V_22 & V_441 )
V_417 = V_420 ;
}
}
return V_417 ;
}
static int F_225 ( struct V_7 * V_10 )
{
int V_417 ;
V_417 = F_209 ( V_10 ) ;
if ( V_417 == V_420 )
F_203 ( V_10 ) ;
return V_417 ;
}
static inline void F_226 ( struct V_1 * V_442 , struct V_1 * V_443 )
{
struct V_11 * V_444 = & V_442 -> V_2 ;
struct V_11 * V_445 = & V_443 -> V_2 ;
V_444 -> V_19 = V_445 -> V_19 ;
V_444 -> V_20 = V_445 -> V_20 ;
V_444 -> V_21 = V_445 -> V_21 ;
V_444 -> V_22 = V_445 -> V_22 ;
V_444 -> V_244 = V_445 -> V_244 ;
V_444 -> V_245 = V_445 -> V_245 ;
V_444 -> V_201 = V_445 -> V_201 ;
V_444 -> V_51 = V_445 -> V_51 ;
V_444 -> V_360 = V_445 -> V_360 ;
V_444 -> V_246 = V_445 -> V_246 ;
V_444 -> V_446 = V_445 -> V_446 ;
V_444 -> V_67 = V_445 -> V_67 ;
V_444 -> V_407 = V_445 -> V_407 ;
V_444 -> V_409 = V_445 -> V_409 ;
V_444 -> V_371 = V_445 -> V_371 ;
V_444 -> V_369 = V_445 -> V_369 ;
V_444 -> V_447 = V_445 -> V_447 ;
V_444 -> V_448 = V_445 -> V_448 ;
V_444 -> V_270 = V_445 -> V_270 ;
V_444 -> V_90 = V_445 -> V_90 ;
V_444 -> V_93 = V_445 -> V_93 ;
V_444 -> V_401 = V_445 -> V_401 ;
V_444 -> V_159 = V_445 -> V_159 ;
}
static int F_203 ( struct V_7 * V_10 )
{
struct V_1 * V_449 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_164 * V_164 ;
F_227 ( V_1 -> V_2 . V_407 ,
V_1 -> V_2 . V_371 ,
V_1 -> V_2 . V_369 ,
V_1 -> V_2 . V_447 ,
V_1 -> V_2 . V_448 ,
V_450 ) ;
V_449 = F_213 ( V_10 , V_10 -> V_17 . V_1 , & V_164 ) ;
if ( ! V_449 )
return 1 ;
F_228 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_449 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_449 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_449 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_449 -> V_58 . V_250 = V_1 -> V_58 . V_250 ;
V_449 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_449 -> V_58 . V_256 = V_1 -> V_58 . V_256 ;
V_449 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_449 -> V_58 . V_264 = F_229 ( & V_10 -> V_9 ) ;
V_449 -> V_58 . V_272 = F_137 ( & V_10 -> V_9 ) ;
V_449 -> V_58 . V_419 = V_1 -> V_58 . V_419 ;
V_449 -> V_58 . V_268 = V_10 -> V_9 . V_39 . V_268 ;
V_449 -> V_58 . V_306 = F_230 ( & V_10 -> V_9 ) ;
V_449 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_449 -> V_58 . V_451 = V_1 -> V_58 . V_451 ;
V_449 -> V_58 . V_452 = V_1 -> V_58 . V_452 ;
V_449 -> V_58 . V_365 = V_1 -> V_58 . V_365 ;
V_449 -> V_58 . V_261 = V_1 -> V_58 . V_261 ;
V_449 -> V_58 . V_337 = V_1 -> V_58 . V_337 ;
V_449 -> V_2 . V_246 = V_1 -> V_2 . V_246 ;
V_449 -> V_2 . V_446 = V_1 -> V_2 . V_446 ;
V_449 -> V_2 . V_67 = V_1 -> V_2 . V_67 ;
V_449 -> V_2 . V_407 = V_1 -> V_2 . V_407 ;
V_449 -> V_2 . V_409 = V_1 -> V_2 . V_409 ;
V_449 -> V_2 . V_371 = V_1 -> V_2 . V_371 ;
V_449 -> V_2 . V_369 = V_1 -> V_2 . V_369 ;
V_449 -> V_2 . V_447 = V_1 -> V_2 . V_447 ;
V_449 -> V_2 . V_448 = V_1 -> V_2 . V_448 ;
V_449 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_453 = & V_449 -> V_2 ;
V_453 -> V_447 = V_1 -> V_2 . V_90 ;
V_453 -> V_448 = V_1 -> V_2 . V_93 ;
}
V_449 -> V_2 . V_360 = 0 ;
V_449 -> V_2 . V_90 = 0 ;
V_449 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_422 ) )
V_449 -> V_2 . V_246 &= ~ V_247 ;
F_226 ( V_1 , V_18 ) ;
F_231 ( & V_10 -> V_9 ) ;
F_232 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_401 = 0 ;
V_10 -> V_1 -> V_58 . V_248 = V_18 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_249 = V_18 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_250 = V_18 -> V_58 . V_250 ;
V_10 -> V_1 -> V_58 . V_255 = V_18 -> V_58 . V_255 ;
V_10 -> V_1 -> V_58 . V_256 = V_18 -> V_58 . V_256 ;
F_109 ( & V_10 -> V_9 , V_18 -> V_58 . V_306 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_152 ( & V_10 -> V_9 , V_18 -> V_58 . V_264 | V_454 ) ;
F_154 ( & V_10 -> V_9 , V_18 -> V_58 . V_268 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_272 = V_18 -> V_58 . V_272 ;
V_10 -> V_9 . V_39 . V_272 = V_18 -> V_58 . V_272 ;
} else {
( void ) F_233 ( & V_10 -> V_9 , V_18 -> V_58 . V_272 ) ;
}
F_113 ( & V_10 -> V_9 , V_455 , V_18 -> V_58 . V_452 ) ;
F_113 ( & V_10 -> V_9 , V_456 , V_18 -> V_58 . V_451 ) ;
F_113 ( & V_10 -> V_9 , V_263 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_365 = 0 ;
V_10 -> V_1 -> V_58 . V_337 = 0 ;
V_10 -> V_1 -> V_2 . V_447 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_218 ( V_164 ) ;
F_206 ( & V_10 -> V_9 ) ;
F_234 ( & V_10 -> V_9 ) ;
F_235 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_236 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_230 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_157 ; V_44 ++ ) {
T_1 V_363 , V_457 ;
T_2 V_43 ;
if ( V_158 [ V_44 ] == 0xffffffff )
break;
V_457 = V_158 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_431 + ( V_457 * 4 ) ;
if ( F_222 ( V_10 -> V_9 . V_279 , V_43 , & V_363 , 4 ) )
return false ;
V_10 -> V_17 . V_148 [ V_457 ] = V_10 -> V_148 [ V_457 ] | V_363 ;
}
V_10 -> V_1 -> V_2 . V_245 = F_108 ( V_10 -> V_17 . V_148 ) ;
return true ;
}
static bool F_237 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_233 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_270 && ! V_55 )
return false ;
return true ;
}
static bool F_238 ( struct V_7 * V_10 )
{
struct V_1 * V_449 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_164 * V_164 ;
T_2 V_458 ;
V_458 = V_10 -> V_1 -> V_58 . V_452 ;
V_449 = F_213 ( V_10 , V_10 -> V_1 -> V_58 . V_452 , & V_164 ) ;
if ( ! V_449 )
return false ;
if ( ! F_237 ( V_449 ) ) {
V_449 -> V_2 . V_407 = V_440 ;
V_449 -> V_2 . V_409 = 0 ;
V_449 -> V_2 . V_371 = 0 ;
V_449 -> V_2 . V_369 = 0 ;
F_218 ( V_164 ) ;
return false ;
}
F_239 ( V_10 -> V_1 -> V_58 . V_84 , V_458 ,
V_449 -> V_58 . V_84 ,
V_449 -> V_2 . V_246 ,
V_449 -> V_2 . V_90 ,
V_449 -> V_2 . V_270 ) ;
F_240 ( V_449 -> V_2 . V_19 & 0xffff ,
V_449 -> V_2 . V_19 >> 16 ,
V_449 -> V_2 . V_21 ,
V_449 -> V_2 . V_22 ) ;
F_231 ( & V_10 -> V_9 ) ;
F_232 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_18 -> V_58 . V_250 = V_1 -> V_58 . V_250 ;
V_18 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_18 -> V_58 . V_256 = V_1 -> V_58 . V_256 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_264 = F_229 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_268 = V_10 -> V_9 . V_39 . V_268 ;
V_18 -> V_58 . V_306 = F_230 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_451 = V_1 -> V_58 . V_451 ;
V_18 -> V_58 . V_452 = V_1 -> V_58 . V_452 ;
if ( V_55 )
V_18 -> V_58 . V_272 = V_1 -> V_58 . V_272 ;
else
V_18 -> V_58 . V_272 = F_137 ( & V_10 -> V_9 ) ;
F_226 ( V_18 , V_1 ) ;
if ( F_230 ( & V_10 -> V_9 ) & V_459 )
V_10 -> V_9 . V_39 . V_40 |= V_423 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_423 ;
if ( V_449 -> V_2 . V_270 ) {
F_241 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_401 = V_449 -> V_2 . V_401 ;
F_204 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_248 = V_449 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_87 = V_449 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_249 = V_449 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_250 = V_449 -> V_58 . V_250 ;
V_10 -> V_1 -> V_58 . V_255 = V_449 -> V_58 . V_255 ;
V_10 -> V_1 -> V_58 . V_256 = V_449 -> V_58 . V_256 ;
F_109 ( & V_10 -> V_9 , V_449 -> V_58 . V_306 ) ;
F_27 ( & V_10 -> V_9 , V_449 -> V_58 . V_54 ) ;
F_152 ( & V_10 -> V_9 , V_449 -> V_58 . V_264 ) ;
F_154 ( & V_10 -> V_9 , V_449 -> V_58 . V_268 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_272 = V_449 -> V_58 . V_272 ;
V_10 -> V_9 . V_39 . V_272 = V_449 -> V_58 . V_272 ;
} else
( void ) F_233 ( & V_10 -> V_9 , V_449 -> V_58 . V_272 ) ;
F_234 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_419 = V_10 -> V_9 . V_39 . V_419 = V_449 -> V_58 . V_419 ;
F_113 ( & V_10 -> V_9 , V_455 , V_449 -> V_58 . V_452 ) ;
F_113 ( & V_10 -> V_9 , V_456 , V_449 -> V_58 . V_451 ) ;
F_113 ( & V_10 -> V_9 , V_263 , V_449 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_452 = V_449 -> V_58 . V_452 ;
V_10 -> V_1 -> V_58 . V_451 = V_449 -> V_58 . V_451 ;
V_10 -> V_1 -> V_58 . V_84 = V_449 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_365 = V_449 -> V_58 . V_365 ;
V_10 -> V_1 -> V_58 . V_261 = V_449 -> V_58 . V_261 ;
V_10 -> V_1 -> V_58 . V_337 = V_449 -> V_58 . V_337 ;
V_10 -> V_17 . V_431 = V_449 -> V_2 . V_245 & ~ 0x0fffULL ;
V_10 -> V_17 . V_429 = V_449 -> V_2 . V_244 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_449 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_449 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_449 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_449 -> V_2 . V_22 ;
F_156 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_246 = V_449 -> V_2 . V_246 | V_247 ;
if ( V_449 -> V_2 . V_246 & V_247 )
V_10 -> V_9 . V_39 . V_40 |= V_422 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_422 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_422 ) {
F_10 ( V_10 , V_460 ) ;
F_10 ( V_10 , V_215 ) ;
}
F_17 ( V_10 , V_234 ) ;
V_10 -> V_1 -> V_2 . V_159 = V_449 -> V_2 . V_159 ;
V_10 -> V_1 -> V_2 . V_446 = V_449 -> V_2 . V_446 ;
V_10 -> V_1 -> V_2 . V_67 = V_449 -> V_2 . V_67 ;
V_10 -> V_1 -> V_2 . V_201 += V_449 -> V_2 . V_201 ;
V_10 -> V_1 -> V_2 . V_90 = V_449 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_449 -> V_2 . V_93 ;
F_218 ( V_164 ) ;
F_242 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_458 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_243 ( struct V_1 * V_443 , struct V_1 * V_461 )
{
V_461 -> V_58 . V_251 = V_443 -> V_58 . V_251 ;
V_461 -> V_58 . V_252 = V_443 -> V_58 . V_252 ;
V_461 -> V_58 . V_259 = V_443 -> V_58 . V_259 ;
V_461 -> V_58 . V_257 = V_443 -> V_58 . V_257 ;
V_461 -> V_58 . V_462 = V_443 -> V_58 . V_462 ;
V_461 -> V_58 . V_463 = V_443 -> V_58 . V_463 ;
V_461 -> V_58 . V_464 = V_443 -> V_58 . V_464 ;
V_461 -> V_58 . V_465 = V_443 -> V_58 . V_465 ;
V_461 -> V_58 . V_466 = V_443 -> V_58 . V_466 ;
V_461 -> V_58 . V_467 = V_443 -> V_58 . V_467 ;
V_461 -> V_58 . V_468 = V_443 -> V_58 . V_468 ;
V_461 -> V_58 . V_469 = V_443 -> V_58 . V_469 ;
}
static int F_244 ( struct V_7 * V_10 )
{
struct V_1 * V_449 ;
struct V_164 * V_164 ;
if ( F_207 ( V_10 ) )
return 1 ;
V_449 = F_213 ( V_10 , V_10 -> V_1 -> V_58 . V_452 , & V_164 ) ;
if ( ! V_449 )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_243 ( V_449 , V_10 -> V_1 ) ;
F_218 ( V_164 ) ;
return 1 ;
}
static int F_245 ( struct V_7 * V_10 )
{
struct V_1 * V_449 ;
struct V_164 * V_164 ;
if ( F_207 ( V_10 ) )
return 1 ;
V_449 = F_213 ( V_10 , V_10 -> V_1 -> V_58 . V_452 , & V_164 ) ;
if ( ! V_449 )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_243 ( V_10 -> V_1 , V_449 ) ;
F_218 ( V_164 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
if ( F_207 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_238 ( V_10 ) )
return 1 ;
if ( ! F_236 ( V_10 ) )
goto V_470;
return 1 ;
V_470:
V_10 -> V_1 -> V_2 . V_407 = V_440 ;
V_10 -> V_1 -> V_2 . V_409 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = 0 ;
V_10 -> V_1 -> V_2 . V_369 = 0 ;
F_203 ( V_10 ) ;
return 1 ;
}
static int F_247 ( struct V_7 * V_10 )
{
if ( F_207 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_184 ( V_471 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_248 ( struct V_7 * V_10 )
{
if ( F_207 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_139 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_472 ;
F_3 ( V_10 -> V_1 , V_473 ) ;
return 1 ;
}
static int F_249 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_250 ( V_10 -> V_1 -> V_58 . V_84 , V_9 -> V_39 . V_262 [ V_430 ] ,
V_9 -> V_39 . V_262 [ V_455 ] ) ;
F_251 ( V_9 , V_9 -> V_39 . V_262 [ V_455 ] ) ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_252 ( struct V_7 * V_10 )
{
F_253 ( V_10 -> V_1 -> V_58 . V_84 , V_10 -> V_9 . V_39 . V_262 [ V_455 ] ) ;
F_175 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
static int F_254 ( struct V_7 * V_10 )
{
T_2 V_474 = F_255 ( & V_10 -> V_9 ) ;
T_1 V_146 = F_256 ( & V_10 -> V_9 , V_430 ) ;
if ( F_257 ( & V_10 -> V_9 , V_146 , V_474 ) == 0 ) {
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_258 ( struct V_7 * V_10 )
{
T_10 V_475 ;
int V_476 ;
int V_477 = V_10 -> V_1 -> V_2 . V_447 &
V_478 ;
int V_479 = V_10 -> V_1 -> V_2 . V_447 & V_480 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_447 & V_478 ;
T_7 V_481 =
V_10 -> V_1 -> V_2 . V_447 & V_482 ;
bool V_79 = false ;
T_1 V_80 = 0 ;
V_475 = ( T_10 ) V_10 -> V_1 -> V_2 . V_371 ;
if ( V_10 -> V_1 -> V_2 . V_369 &
( 1ULL << V_483 ) )
V_476 = V_484 ;
else if ( V_10 -> V_1 -> V_2 . V_369 &
( 1ULL << V_485 ) )
V_476 = V_486 ;
else if ( V_481 )
V_476 = V_487 ;
else
V_476 = V_488 ;
if ( V_476 == V_487 ) {
switch ( type ) {
case V_489 :
V_10 -> V_9 . V_39 . V_490 = false ;
break;
case V_491 :
if ( V_10 -> V_1 -> V_2 . V_369 &
( 1ULL << V_492 ) ) {
V_79 = true ;
V_80 =
( T_1 ) V_10 -> V_1 -> V_2 . V_369 ;
}
F_231 ( & V_10 -> V_9 ) ;
break;
case V_493 :
F_232 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_476 != V_487 ||
V_477 == V_494 ||
( V_477 == V_491 &&
( V_479 == V_495 || V_479 == V_82 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_477 != V_494 )
V_479 = - 1 ;
if ( F_259 ( & V_10 -> V_9 , V_475 , V_479 , V_476 ,
V_79 , V_80 ) == V_496 ) {
V_10 -> V_9 . V_377 -> V_380 = V_497 ;
V_10 -> V_9 . V_377 -> V_498 . V_499 = V_500 ;
V_10 -> V_9 . V_377 -> V_498 . V_501 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_260 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_261 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_262 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_301 . V_502 ;
F_17 ( V_10 , V_503 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_504 ;
V_10 -> V_505 = F_34 ( & V_10 -> V_9 ) ;
F_184 ( V_471 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_506 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_73 ;
F_251 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_371 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_264 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_73 ;
}
static int F_265 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_38 ( V_83 ) )
return F_264 ( V_10 ) ;
V_96 = F_266 ( & V_10 -> V_9 ) ;
F_267 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
bool F_268 ( struct V_7 * V_10 , unsigned long V_97 )
{
unsigned long V_264 = V_10 -> V_9 . V_39 . V_264 ;
bool V_66 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_222 ) ) ) )
return false ;
V_264 &= ~ V_343 ;
V_97 &= ~ V_343 ;
if ( V_264 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_407 = V_507 ;
V_66 = ( F_225 ( V_10 ) == V_420 ) ;
}
return V_66 ;
}
static int F_269 ( struct V_7 * V_10 )
{
int V_308 , V_508 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_38 ( V_506 ) )
return F_264 ( V_10 ) ;
if ( F_125 ( ( V_10 -> V_1 -> V_2 . V_371 & V_509 ) == 0 ) )
return F_264 ( V_10 ) ;
V_308 = V_10 -> V_1 -> V_2 . V_371 & V_510 ;
V_508 = V_10 -> V_1 -> V_2 . V_407 - V_435 ;
V_96 = 0 ;
if ( V_508 >= 16 ) {
V_508 -= 16 ;
V_97 = F_256 ( & V_10 -> V_9 , V_308 ) ;
switch ( V_508 ) {
case 0 :
if ( ! F_268 ( V_10 , V_97 ) )
V_96 = F_110 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_233 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_270 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_271 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_98 ( 1 , L_12 , V_508 ) ;
F_175 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
} else {
switch ( V_508 ) {
case 0 :
V_97 = F_229 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_419 ;
break;
case 3 :
V_97 = F_137 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_272 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_273 ( & V_10 -> V_9 ) ;
break;
default:
F_98 ( 1 , L_13 , V_508 ) ;
F_175 ( & V_10 -> V_9 , V_217 ) ;
return 1 ;
}
F_113 ( & V_10 -> V_9 , V_308 , V_97 ) ;
}
F_267 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_274 ( struct V_7 * V_10 )
{
int V_308 , V_511 ;
unsigned long V_97 ;
int V_96 ;
if ( V_10 -> V_9 . V_355 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_366 |= V_367 ;
return 1 ;
}
if ( ! F_84 ( V_506 ) )
return F_264 ( V_10 ) ;
V_308 = V_10 -> V_1 -> V_2 . V_371 & V_510 ;
V_511 = V_10 -> V_1 -> V_2 . V_407 - V_437 ;
if ( V_511 >= 16 ) {
V_97 = F_256 ( & V_10 -> V_9 , V_308 ) ;
F_275 ( & V_10 -> V_9 , V_511 - 16 , V_97 ) ;
} else {
V_96 = F_276 ( & V_10 -> V_9 , V_511 , & V_97 ) ;
if ( ! V_96 )
F_113 ( & V_10 -> V_9 , V_308 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_277 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
int V_142 ;
T_4 V_512 = F_273 ( & V_10 -> V_9 ) ;
V_142 = F_269 ( V_10 ) ;
if ( F_278 ( V_10 -> V_9 . V_279 ) )
return V_142 ;
if ( V_512 <= F_273 ( & V_10 -> V_9 ) )
return V_142 ;
V_376 -> V_380 = V_513 ;
return 0 ;
}
T_2 F_279 ( struct V_8 * V_9 , T_2 V_514 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_201 +
F_96 ( V_9 , V_514 ) ;
}
static int F_280 ( struct V_8 * V_9 , unsigned V_515 , T_2 * V_516 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_515 ) {
case V_517 : {
* V_516 = V_10 -> V_1 -> V_2 . V_201 +
F_96 ( V_9 , F_106 () ) ;
break;
}
case V_518 :
* V_516 = V_10 -> V_1 -> V_58 . V_463 ;
break;
#ifdef F_26
case V_519 :
* V_516 = V_10 -> V_1 -> V_58 . V_464 ;
break;
case V_520 :
* V_516 = V_10 -> V_1 -> V_58 . V_465 ;
break;
case V_303 :
* V_516 = V_10 -> V_1 -> V_58 . V_462 ;
break;
case V_521 :
* V_516 = V_10 -> V_1 -> V_58 . V_466 ;
break;
#endif
case V_522 :
* V_516 = V_10 -> V_1 -> V_58 . V_467 ;
break;
case V_523 :
* V_516 = V_10 -> V_469 ;
break;
case V_524 :
* V_516 = V_10 -> V_468 ;
break;
case V_525 :
* V_516 = V_10 -> V_1 -> V_58 . V_526 ;
break;
case V_160 :
* V_516 = V_10 -> V_1 -> V_58 . V_527 ;
break;
case V_161 :
* V_516 = V_10 -> V_1 -> V_58 . V_528 ;
break;
case V_162 :
* V_516 = V_10 -> V_1 -> V_58 . V_529 ;
break;
case V_163 :
* V_516 = V_10 -> V_1 -> V_58 . V_530 ;
break;
case V_133 :
* V_516 = V_10 -> V_17 . V_531 ;
break;
case V_532 :
* V_516 = V_10 -> V_17 . V_533 ;
break;
case V_534 :
* V_516 = 0x01000065 ;
break;
default:
return F_281 ( V_9 , V_515 , V_516 ) ;
}
return 0 ;
}
static int F_282 ( struct V_7 * V_10 )
{
T_1 V_515 = V_10 -> V_9 . V_39 . V_262 [ V_430 ] ;
T_2 V_516 ;
if ( F_280 ( & V_10 -> V_9 , V_515 , & V_516 ) ) {
F_283 ( V_515 ) ;
F_208 ( & V_10 -> V_9 , 0 ) ;
} else {
F_284 ( V_515 , V_516 ) ;
V_10 -> V_9 . V_39 . V_262 [ V_455 ] = V_516 & 0xffffffff ;
V_10 -> V_9 . V_39 . V_262 [ V_278 ] = V_516 >> 32 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_285 ( struct V_8 * V_9 , T_2 V_516 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_535 , V_536 ;
if ( V_516 & ~ V_537 )
return 1 ;
V_536 = V_537 ;
if ( V_10 -> V_17 . V_533 & V_538 )
V_536 &= ~ ( V_539 | V_538 ) ;
V_10 -> V_17 . V_533 &= ~ V_536 ;
V_10 -> V_17 . V_533 |= ( V_516 & V_536 ) ;
V_535 = V_10 -> V_17 . V_533 & V_538 ;
if ( V_535 && ( V_9 -> V_39 . V_54 & V_59 ) )
return 1 ;
return 0 ;
}
static int F_286 ( struct V_8 * V_9 , struct V_540 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_515 = V_42 -> V_146 ;
T_2 V_516 = V_42 -> V_516 ;
switch ( V_515 ) {
case V_517 :
F_287 ( V_9 , V_42 ) ;
break;
case V_518 :
V_10 -> V_1 -> V_58 . V_463 = V_516 ;
break;
#ifdef F_26
case V_519 :
V_10 -> V_1 -> V_58 . V_464 = V_516 ;
break;
case V_520 :
V_10 -> V_1 -> V_58 . V_465 = V_516 ;
break;
case V_303 :
V_10 -> V_1 -> V_58 . V_462 = V_516 ;
break;
case V_521 :
V_10 -> V_1 -> V_58 . V_466 = V_516 ;
break;
#endif
case V_522 :
V_10 -> V_1 -> V_58 . V_467 = V_516 ;
break;
case V_523 :
V_10 -> V_469 = V_516 ;
V_10 -> V_1 -> V_58 . V_469 = V_516 ;
break;
case V_524 :
V_10 -> V_468 = V_516 ;
V_10 -> V_1 -> V_58 . V_468 = V_516 ;
break;
case V_525 :
if ( ! F_84 ( V_541 ) ) {
F_288 ( V_9 , L_14 ,
V_75 , V_516 ) ;
break;
}
if ( V_516 & V_542 )
return 1 ;
V_10 -> V_1 -> V_58 . V_526 = V_516 ;
F_3 ( V_10 -> V_1 , V_543 ) ;
if ( V_516 & ( 1ULL << 0 ) )
F_79 ( V_10 ) ;
else
F_80 ( V_10 ) ;
break;
case V_133 :
V_10 -> V_17 . V_531 = V_516 ;
break;
case V_532 :
return F_285 ( V_9 , V_516 ) ;
case V_544 :
F_288 ( V_9 , L_15 , V_515 , V_516 ) ;
break;
default:
return F_289 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_290 ( struct V_7 * V_10 )
{
struct V_540 V_42 ;
T_1 V_515 = V_10 -> V_9 . V_39 . V_262 [ V_430 ] ;
T_2 V_516 = ( V_10 -> V_9 . V_39 . V_262 [ V_455 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_39 . V_262 [ V_278 ] & - 1u ) << 32 ) ;
V_42 . V_516 = V_516 ;
V_42 . V_146 = V_515 ;
V_42 . V_545 = false ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_286 ( & V_10 -> V_9 , & V_42 ) ) {
F_291 ( V_515 , V_516 ) ;
F_208 ( & V_10 -> V_9 , 0 ) ;
} else {
F_292 ( V_515 , V_516 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_293 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_371 )
return F_290 ( V_10 ) ;
else
return F_282 ( V_10 ) ;
}
static int F_294 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
F_184 ( V_471 , & V_10 -> V_9 ) ;
F_139 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_472 ;
F_3 ( V_10 -> V_1 , V_473 ) ;
++ V_10 -> V_9 . V_301 . V_546 ;
if ( ! F_278 ( V_10 -> V_9 . V_279 ) &&
V_376 -> V_547 &&
! F_295 ( & V_10 -> V_9 ) ) {
V_376 -> V_380 = V_548 ;
return 0 ;
}
return 1 ;
}
static int F_296 ( struct V_7 * V_10 )
{
F_297 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_298 ( struct V_7 * V_10 )
{
F_31 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_299 ( struct V_7 * V_10 )
{
F_300 ( V_549 L_16 ) ;
return F_298 ( V_10 ) ;
}
static int F_301 ( struct V_7 * V_10 )
{
F_300 ( V_549 L_17 ) ;
return F_298 ( V_10 ) ;
}
static void F_302 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_207 * V_58 = & V_10 -> V_1 -> V_58 ;
F_55 ( L_18 ) ;
F_55 ( L_19 , L_20 , V_2 -> V_19 & 0xffff ) ;
F_55 ( L_19 , L_21 , V_2 -> V_19 >> 16 ) ;
F_55 ( L_19 , L_22 , V_2 -> V_20 & 0xffff ) ;
F_55 ( L_19 , L_23 , V_2 -> V_20 >> 16 ) ;
F_55 ( L_24 , L_25 , V_2 -> V_21 ) ;
F_55 ( L_26 , L_27 , V_2 -> V_22 ) ;
F_55 ( L_28 , L_29 , V_2 -> V_274 ) ;
F_55 ( L_26 , L_30 , V_2 -> V_244 ) ;
F_55 ( L_26 , L_31 , V_2 -> V_245 ) ;
F_55 ( L_26 , L_32 , V_2 -> V_201 ) ;
F_55 ( L_28 , L_33 , V_2 -> V_51 ) ;
F_55 ( L_28 , L_34 , V_2 -> V_360 ) ;
F_55 ( L_24 , L_35 , V_2 -> V_246 ) ;
F_55 ( L_24 , L_36 , V_2 -> V_446 ) ;
F_55 ( L_24 , L_37 , V_2 -> V_67 ) ;
F_55 ( L_24 , L_38 , V_2 -> V_407 ) ;
F_55 ( L_26 , L_39 , V_2 -> V_371 ) ;
F_55 ( L_26 , L_40 , V_2 -> V_369 ) ;
F_55 ( L_24 , L_41 , V_2 -> V_447 ) ;
F_55 ( L_24 , L_42 , V_2 -> V_448 ) ;
F_55 ( L_43 , L_44 , V_2 -> V_270 ) ;
F_55 ( L_26 , L_45 , V_2 -> V_401 ) ;
F_55 ( L_24 , L_46 , V_2 -> V_90 ) ;
F_55 ( L_24 , L_47 , V_2 -> V_93 ) ;
F_55 ( L_43 , L_48 , V_2 -> V_159 ) ;
F_55 ( L_26 , L_49 , V_2 -> V_71 ) ;
F_55 ( L_50 ) ;
F_55 ( L_51 ,
L_52 ,
V_58 -> V_248 . V_183 , V_58 -> V_248 . V_184 ,
V_58 -> V_248 . V_188 , V_58 -> V_248 . V_88 ) ;
F_55 ( L_51 ,
L_53 ,
V_58 -> V_87 . V_183 , V_58 -> V_87 . V_184 ,
V_58 -> V_87 . V_188 , V_58 -> V_87 . V_88 ) ;
F_55 ( L_51 ,
L_54 ,
V_58 -> V_249 . V_183 , V_58 -> V_249 . V_184 ,
V_58 -> V_249 . V_188 , V_58 -> V_249 . V_88 ) ;
F_55 ( L_51 ,
L_55 ,
V_58 -> V_250 . V_183 , V_58 -> V_250 . V_184 ,
V_58 -> V_250 . V_188 , V_58 -> V_250 . V_88 ) ;
F_55 ( L_51 ,
L_56 ,
V_58 -> V_251 . V_183 , V_58 -> V_251 . V_184 ,
V_58 -> V_251 . V_188 , V_58 -> V_251 . V_88 ) ;
F_55 ( L_51 ,
L_57 ,
V_58 -> V_252 . V_183 , V_58 -> V_252 . V_184 ,
V_58 -> V_252 . V_188 , V_58 -> V_252 . V_88 ) ;
F_55 ( L_51 ,
L_58 ,
V_58 -> V_255 . V_183 , V_58 -> V_255 . V_184 ,
V_58 -> V_255 . V_188 , V_58 -> V_255 . V_88 ) ;
F_55 ( L_51 ,
L_59 ,
V_58 -> V_257 . V_183 , V_58 -> V_257 . V_184 ,
V_58 -> V_257 . V_188 , V_58 -> V_257 . V_88 ) ;
F_55 ( L_51 ,
L_60 ,
V_58 -> V_256 . V_183 , V_58 -> V_256 . V_184 ,
V_58 -> V_256 . V_188 , V_58 -> V_256 . V_88 ) ;
F_55 ( L_51 ,
L_61 ,
V_58 -> V_259 . V_183 , V_58 -> V_259 . V_184 ,
V_58 -> V_259 . V_188 , V_58 -> V_259 . V_88 ) ;
F_55 ( L_62 ,
V_58 -> V_337 , V_58 -> V_54 ) ;
F_55 ( L_63 ,
L_64 , V_58 -> V_264 , L_65 , V_58 -> V_419 ) ;
F_55 ( L_63 ,
L_66 , V_58 -> V_272 , L_67 , V_58 -> V_268 ) ;
F_55 ( L_63 ,
L_68 , V_58 -> V_261 , L_69 , V_58 -> V_365 ) ;
F_55 ( L_63 ,
L_70 , V_58 -> V_84 , L_71 , V_58 -> V_306 ) ;
F_55 ( L_63 ,
L_72 , V_58 -> V_451 , L_73 , V_58 -> V_452 ) ;
F_55 ( L_63 ,
L_74 , V_58 -> V_463 , L_75 , V_58 -> V_464 ) ;
F_55 ( L_63 ,
L_76 , V_58 -> V_465 , L_77 , V_58 -> V_466 ) ;
F_55 ( L_63 ,
L_78 , V_58 -> V_462 ,
L_79 , V_58 -> V_467 ) ;
F_55 ( L_63 ,
L_80 , V_58 -> V_468 ,
L_81 , V_58 -> V_469 ) ;
F_55 ( L_63 ,
L_82 , V_58 -> V_271 , L_83 , V_58 -> V_526 ) ;
F_55 ( L_63 ,
L_84 , V_58 -> V_527 , L_85 , V_58 -> V_528 ) ;
F_55 ( L_63 ,
L_86 , V_58 -> V_529 ,
L_87 , V_58 -> V_530 ) ;
}
static void F_303 ( struct V_8 * V_9 , T_2 * V_550 , T_2 * V_551 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_550 = V_2 -> V_371 ;
* V_551 = V_2 -> V_369 ;
}
static int F_304 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_376 * V_376 = V_9 -> V_377 ;
T_1 V_407 = V_10 -> V_1 -> V_2 . V_407 ;
if ( ! F_11 ( V_10 , V_212 ) )
V_9 -> V_39 . V_264 = V_10 -> V_1 -> V_58 . V_264 ;
if ( V_55 )
V_9 -> V_39 . V_272 = V_10 -> V_1 -> V_58 . V_272 ;
if ( F_125 ( V_10 -> V_17 . V_421 ) ) {
F_203 ( V_10 ) ;
V_10 -> V_17 . V_421 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_417 ;
F_305 ( V_10 -> V_1 -> V_58 . V_84 , V_407 ,
V_10 -> V_1 -> V_2 . V_371 ,
V_10 -> V_1 -> V_2 . V_369 ,
V_10 -> V_1 -> V_2 . V_447 ,
V_10 -> V_1 -> V_2 . V_448 ,
V_450 ) ;
V_417 = F_224 ( V_10 ) ;
if ( V_417 == V_432 )
V_417 = F_225 ( V_10 ) ;
if ( V_417 == V_420 )
return 1 ;
}
F_306 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_407 == V_440 ) {
V_376 -> V_380 = V_552 ;
V_376 -> V_553 . V_554
= V_10 -> V_1 -> V_2 . V_407 ;
F_55 ( L_88 ) ;
F_302 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_447 ) &&
V_407 != V_418 + V_216 &&
V_407 != V_408 && V_407 != V_555 &&
V_407 != V_424 && V_407 != V_425 )
F_33 ( V_77 L_89
L_90 ,
V_75 , V_10 -> V_1 -> V_2 . V_447 ,
V_407 ) ;
if ( V_407 >= F_307 ( V_556 )
|| ! V_556 [ V_407 ] ) {
V_376 -> V_380 = V_557 ;
V_376 -> V_558 . V_559 = V_407 ;
return 0 ;
}
return V_556 [ V_407 ] ( V_10 ) ;
}
static void F_308 ( struct V_8 * V_9 )
{
int V_141 = F_53 () ;
struct V_114 * V_115 = F_56 ( V_124 , V_141 ) ;
V_115 -> V_130 -> type = 9 ;
F_309 () ;
}
static void F_310 ( struct V_7 * V_10 )
{
int V_141 = F_53 () ;
struct V_114 * V_115 = F_56 ( V_124 , V_141 ) ;
if ( V_10 -> V_125 != V_115 -> V_125 )
F_159 ( V_10 , V_115 ) ;
}
static void F_311 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_560 ;
V_9 -> V_39 . V_40 |= V_561 ;
F_16 ( V_10 , V_503 ) ;
++ V_9 -> V_301 . V_562 ;
}
static inline void F_312 ( struct V_7 * V_10 , int V_563 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_446 = V_563 ;
V_2 -> V_246 &= ~ V_564 ;
V_2 -> V_246 |= V_472 |
( ( 0xf ) << V_565 ) ;
F_3 ( V_10 -> V_1 , V_473 ) ;
}
static void F_313 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_72 ( ! ( F_20 ( V_10 ) ) ) ;
F_314 ( V_9 -> V_39 . V_566 . V_78 ) ;
++ V_9 -> V_301 . V_567 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_566 . V_78 |
V_63 | V_64 ;
}
static void F_315 ( struct V_8 * V_9 , int V_568 , int V_569 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_422 ) )
return;
F_10 ( V_10 , V_215 ) ;
if ( V_569 == - 1 )
return;
if ( V_568 >= V_569 )
F_9 ( V_10 , V_215 ) ;
}
static void F_316 ( struct V_8 * V_9 , bool V_570 )
{
return;
}
static int F_317 ( struct V_279 * V_279 )
{
return 0 ;
}
static void F_318 ( struct V_8 * V_9 , T_2 * V_571 )
{
return;
}
static void F_319 ( struct V_279 * V_279 , int V_572 )
{
return;
}
static void F_320 ( struct V_8 * V_9 )
{
return;
}
static int F_321 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_66 ;
V_66 = ! ( V_1 -> V_2 . V_67 & V_68 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_561 ) ;
V_66 = V_66 && F_20 ( V_10 ) && F_212 ( V_10 ) ;
return V_66 ;
}
static bool F_322 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_561 ) ;
}
static void F_323 ( struct V_8 * V_9 , bool V_573 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_573 ) {
V_10 -> V_9 . V_39 . V_40 |= V_561 ;
F_16 ( V_10 , V_503 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_561 ;
F_17 ( V_10 , V_503 ) ;
}
}
static int F_324 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_66 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_67 & V_68 ) )
return 0 ;
V_66 = ! ! ( F_230 ( V_9 ) & V_459 ) ;
if ( F_7 ( V_9 ) )
return V_66 && ! ( V_10 -> V_9 . V_39 . V_40 & V_422 ) ;
return V_66 ;
}
static void F_325 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_210 ( V_10 ) ) {
F_138 ( V_10 ) ;
F_312 ( V_10 , 0x0 ) ;
}
}
static void F_326 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_561 | V_504 ) )
== V_561 )
return;
V_10 -> V_354 = true ;
V_10 -> V_1 -> V_58 . V_306 |= ( V_378 | V_379 ) ;
F_158 ( V_9 ) ;
}
static int F_327 ( struct V_279 * V_279 , unsigned int V_50 )
{
return 0 ;
}
static void F_156 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_574 ) )
V_10 -> V_1 -> V_2 . V_360 = V_575 ;
else
V_10 -> V_125 -- ;
}
static void F_328 ( struct V_8 * V_9 )
{
}
static inline void F_329 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_422 ) )
return;
if ( ! F_11 ( V_10 , V_215 ) ) {
int V_576 = V_10 -> V_1 -> V_2 . V_246 & V_577 ;
F_271 ( V_9 , V_576 ) ;
}
}
static inline void F_330 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_576 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_422 ) )
return;
V_576 = F_273 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_246 &= ~ V_577 ;
V_10 -> V_1 -> V_2 . V_246 |= V_576 & V_577 ;
}
static void F_306 ( struct V_7 * V_10 )
{
T_4 V_578 ;
int type ;
T_1 V_579 = V_10 -> V_1 -> V_2 . V_447 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_504 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_505 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_561 | V_504 ) ;
F_184 ( V_471 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_490 = false ;
F_231 ( & V_10 -> V_9 ) ;
F_232 ( & V_10 -> V_9 ) ;
if ( ! ( V_579 & V_482 ) )
return;
F_184 ( V_471 , & V_10 -> V_9 ) ;
V_578 = V_579 & V_580 ;
type = V_579 & V_478 ;
switch ( type ) {
case V_489 :
V_10 -> V_9 . V_39 . V_490 = true ;
break;
case V_491 :
if ( F_331 ( V_578 ) ) {
if ( V_578 == V_82 && V_89 &&
F_332 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_579 & V_581 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_448 ;
F_333 ( & V_10 -> V_9 , V_578 , V_96 ) ;
} else
F_334 ( & V_10 -> V_9 , V_578 ) ;
break;
case V_493 :
F_335 ( & V_10 -> V_9 , V_578 , false ) ;
break;
default:
break;
}
}
static void F_336 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_447 = V_2 -> V_90 ;
V_2 -> V_448 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_306 ( V_10 ) ;
}
static void F_337 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_452 = V_9 -> V_39 . V_262 [ V_455 ] ;
V_10 -> V_1 -> V_58 . V_451 = V_9 -> V_39 . V_262 [ V_456 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_262 [ V_263 ] ;
if ( F_125 ( V_10 -> V_17 . V_421 ) )
return;
F_310 ( V_10 ) ;
F_330 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_419 = V_9 -> V_39 . V_419 ;
F_22 () ;
F_172 () ;
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
F_308 ( V_9 ) ;
F_170 () ;
V_9 -> V_39 . V_419 = V_10 -> V_1 -> V_58 . V_419 ;
V_9 -> V_39 . V_262 [ V_455 ] = V_10 -> V_1 -> V_58 . V_452 ;
V_9 -> V_39 . V_262 [ V_456 ] = V_10 -> V_1 -> V_58 . V_451 ;
V_9 -> V_39 . V_262 [ V_263 ] = V_10 -> V_1 -> V_58 . V_84 ;
F_338 ( V_10 -> V_1 -> V_2 . V_407 , V_9 , V_450 ) ;
if ( F_125 ( V_10 -> V_1 -> V_2 . V_407 == V_425 ) )
F_339 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_125 ( V_10 -> V_1 -> V_2 . V_407 == V_425 ) )
F_340 ( & V_10 -> V_9 ) ;
F_329 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_360 = V_582 ;
if ( V_10 -> V_1 -> V_2 . V_407 == V_418 + V_216 )
V_10 -> V_370 = F_341 () ;
if ( V_55 ) {
V_9 -> V_39 . V_583 &= ~ ( 1 << V_309 ) ;
V_9 -> V_39 . V_584 &= ~ ( 1 << V_309 ) ;
}
if ( F_125 ( V_10 -> V_1 -> V_2 . V_407 ==
V_418 + V_218 ) )
F_183 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_342 ( struct V_8 * V_9 , unsigned long V_403 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_272 = V_403 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_156 ( V_9 ) ;
}
static void F_343 ( struct V_8 * V_9 , unsigned long V_403 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_401 = V_403 ;
F_3 ( V_10 -> V_1 , V_404 ) ;
V_10 -> V_1 -> V_58 . V_272 = F_137 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_156 ( V_9 ) ;
}
static int F_344 ( void )
{
T_2 V_585 ;
F_54 ( V_532 , V_585 ) ;
if ( V_585 & ( 1 << V_586 ) )
return 1 ;
return 0 ;
}
static void
F_345 ( struct V_8 * V_9 , unsigned char * V_587 )
{
V_587 [ 0 ] = 0x0f ;
V_587 [ 1 ] = 0x01 ;
V_587 [ 2 ] = 0xd9 ;
}
static void F_346 ( void * V_588 )
{
* ( int * ) V_588 = 0 ;
}
static bool F_347 ( void )
{
return false ;
}
static T_2 F_348 ( struct V_8 * V_9 , T_11 V_589 , bool V_590 )
{
return 0 ;
}
static void F_349 ( struct V_8 * V_9 )
{
}
static void F_350 ( T_1 V_591 , struct V_592 * V_593 )
{
switch ( V_591 ) {
case 0x80000001 :
if ( V_17 )
V_593 -> V_515 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_593 -> V_277 = 1 ;
V_593 -> V_594 = 8 ;
V_593 -> V_515 = 0 ;
V_593 -> V_595 = 0 ;
if ( F_84 ( V_83 ) )
V_593 -> V_595 |= V_596 ;
if ( V_55 )
V_593 -> V_595 |= V_597 ;
break;
}
}
static int F_351 ( void )
{
return V_598 ;
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
return false ;
}
static bool F_355 ( void )
{
return true ;
}
static void F_356 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_387 ) ;
F_151 ( V_10 ) ;
}
static int F_357 ( struct V_8 * V_9 ,
struct V_599 * V_61 ,
enum V_600 V_601 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_417 , V_66 = V_602 ;
struct V_603 V_604 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_307 ( V_605 ) )
goto V_285;
V_604 = V_605 [ V_61 -> V_22 ] ;
if ( V_601 != V_604 . V_601 )
goto V_285;
switch ( V_604 . V_407 ) {
case V_435 :
if ( V_61 -> V_22 == V_606 )
V_604 . V_407 += V_61 -> V_607 ;
break;
case V_608 : {
unsigned long V_264 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_609 )
V_604 . V_407 += V_61 -> V_607 ;
if ( V_604 . V_407 != V_608 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_222 ) ) )
break;
V_264 = V_9 -> V_39 . V_264 & ~ V_343 ;
V_97 = V_61 -> V_610 & ~ V_343 ;
if ( V_61 -> V_22 == V_611 ) {
V_264 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_264 & V_454 )
V_97 |= V_454 ;
}
if ( V_264 ^ V_97 )
V_604 . V_407 = V_507 ;
break;
}
case V_437 :
case V_612 :
V_604 . V_407 += V_61 -> V_607 ;
break;
case V_433 :
if ( V_61 -> V_22 == V_613 )
V_1 -> V_2 . V_371 = 1 ;
else
V_1 -> V_2 . V_371 = 0 ;
break;
case V_614 :
if ( V_61 -> V_615 != V_616 )
goto V_285;
case V_434 : {
T_2 V_617 ;
T_1 V_618 ;
V_617 = ( V_9 -> V_39 . V_262 [ V_278 ] & 0xffff ) << 16 ;
if ( V_61 -> V_22 == V_619 ||
V_61 -> V_22 == V_620 ) {
V_617 |= V_397 ;
V_618 = V_61 -> V_621 ;
} else {
V_618 = V_61 -> V_622 ;
}
if ( V_61 -> V_22 == V_623 ||
V_61 -> V_22 == V_620 )
V_617 |= V_396 ;
if ( V_61 -> V_615 )
V_617 |= V_624 ;
V_618 = F_86 ( V_618 , 4u ) ;
V_617 |= V_618 << V_399 ;
V_617 |= ( T_1 ) V_61 -> V_625 << ( V_626 - 1 ) ;
V_1 -> V_2 . V_371 = V_617 ;
V_1 -> V_2 . V_369 = V_61 -> V_71 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_407 = V_604 . V_407 ;
V_417 = F_225 ( V_10 ) ;
V_66 = ( V_417 == V_420 ) ? V_627
: V_602 ;
V_285:
return V_66 ;
}
static void F_358 ( struct V_8 * V_9 )
{
F_172 () ;
}
static int T_5 F_359 ( void )
{
return F_360 ( & V_628 , sizeof( struct V_7 ) ,
F_361 ( struct V_7 ) , V_629 ) ;
}
static void T_6 F_362 ( void )
{
F_363 () ;
}
