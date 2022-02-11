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
static void F_48 ( void )
{
if ( F_38 ( V_110 ) )
F_49 ( V_111 , V_112 ) ;
F_50 () ;
F_51 () ;
}
static int F_52 ( void )
{
struct V_113 * V_114 ;
T_3 V_54 ;
struct V_115 V_116 ;
struct V_117 * V_118 ;
int V_119 = F_53 () ;
F_54 ( V_120 , V_54 ) ;
if ( V_54 & V_59 )
return - V_121 ;
if ( ! F_46 () ) {
F_55 ( L_4 , V_75 , V_119 ) ;
return - V_122 ;
}
V_114 = F_56 ( V_123 , V_119 ) ;
if ( ! V_114 ) {
F_55 ( L_5 , V_75 , V_119 ) ;
return - V_122 ;
}
V_114 -> V_124 = 1 ;
V_114 -> V_125 = F_57 ( V_126 ) - 1 ;
V_114 -> V_127 = V_114 -> V_125 + 1 ;
F_58 ( & V_116 ) ;
V_118 = (struct V_117 * ) V_116 . V_128 ;
V_114 -> V_129 = (struct V_130 * ) ( V_118 + V_131 ) ;
F_49 ( V_120 , V_54 | V_59 ) ;
F_49 ( V_132 , F_59 ( V_114 -> V_133 ) << V_134 ) ;
if ( F_38 ( V_110 ) ) {
F_49 ( V_111 , V_112 ) ;
F_60 ( V_135 , V_112 ) ;
}
if ( F_61 ( & V_106 , V_136 ) ) {
T_3 V_137 , V_104 = 0 ;
int V_96 ;
V_137 = F_41 ( V_138 , & V_96 ) ;
if ( ! V_96 )
V_104 = F_41 ( V_139 ,
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
F_39 () ;
F_62 () ;
return 0 ;
}
static void F_63 ( int V_140 )
{
struct V_113 * V_114 = F_56 ( V_123 , F_53 () ) ;
if ( ! V_114 )
return;
F_56 ( V_123 , F_53 () ) = NULL ;
F_64 ( V_114 -> V_133 ) ;
F_65 ( V_114 ) ;
}
static int F_66 ( int V_140 )
{
struct V_113 * V_114 ;
int V_141 ;
V_114 = F_67 ( sizeof( struct V_113 ) , V_142 ) ;
if ( ! V_114 )
return - V_143 ;
V_114 -> V_140 = V_140 ;
V_114 -> V_133 = F_68 ( V_142 ) ;
V_141 = - V_143 ;
if ( ! V_114 -> V_133 )
goto V_144;
F_56 ( V_123 , V_140 ) = V_114 ;
return 0 ;
V_144:
F_65 ( V_114 ) ;
return V_141 ;
}
static bool F_69 ( T_1 V_145 )
{
int V_44 ;
for ( V_44 = 0 ; V_146 [ V_44 ] . V_145 != V_49 ; V_44 ++ )
if ( V_146 [ V_44 ] . V_145 == V_145 )
return true ;
return false ;
}
static void F_70 ( T_1 * V_147 , unsigned V_42 ,
int V_148 , int V_149 )
{
T_4 V_150 , V_151 ;
unsigned long V_152 ;
T_1 V_43 ;
F_71 ( ! F_69 ( V_42 ) ) ;
V_43 = F_21 ( V_42 ) ;
V_150 = 2 * ( V_42 & 0x0f ) ;
V_151 = 2 * ( V_42 & 0x0f ) + 1 ;
V_152 = V_147 [ V_43 ] ;
F_72 ( V_43 == V_49 ) ;
V_148 ? F_73 ( V_150 , & V_152 ) : F_74 ( V_150 , & V_152 ) ;
V_149 ? F_73 ( V_151 , & V_152 ) : F_74 ( V_151 , & V_152 ) ;
V_147 [ V_43 ] = V_152 ;
}
static void F_75 ( T_1 * V_147 )
{
int V_44 ;
memset ( V_147 , 0xff , V_153 * ( 1 << V_154 ) ) ;
for ( V_44 = 0 ; V_146 [ V_44 ] . V_145 != V_49 ; V_44 ++ ) {
if ( ! V_146 [ V_44 ] . V_155 )
continue;
F_70 ( V_147 , V_146 [ V_44 ] . V_145 , 1 , 1 ) ;
}
}
static void F_76 ( T_1 V_43 )
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
F_77 () ;
}
static void F_78 ( void )
{
int V_44 ;
memset ( V_157 , 0xff , sizeof( V_157 ) ) ;
for ( V_44 = 0 ; V_146 [ V_44 ] . V_145 != V_49 ; V_44 ++ ) {
T_1 V_43 ;
V_43 = F_21 ( V_146 [ V_44 ] . V_145 ) ;
F_72 ( V_43 == V_49 ) ;
F_76 ( V_43 ) ;
}
}
static void F_79 ( struct V_7 * V_10 )
{
T_1 * V_147 = V_10 -> V_147 ;
V_10 -> V_1 -> V_2 . V_158 = 1 ;
F_70 ( V_147 , V_159 , 1 , 1 ) ;
F_70 ( V_147 , V_160 , 1 , 1 ) ;
F_70 ( V_147 , V_161 , 1 , 1 ) ;
F_70 ( V_147 , V_162 , 1 , 1 ) ;
}
static void F_80 ( struct V_7 * V_10 )
{
T_1 * V_147 = V_10 -> V_147 ;
V_10 -> V_1 -> V_2 . V_158 = 0 ;
F_70 ( V_147 , V_159 , 0 , 0 ) ;
F_70 ( V_147 , V_160 , 0 , 0 ) ;
F_70 ( V_147 , V_161 , 0 , 0 ) ;
F_70 ( V_147 , V_162 , 0 , 0 ) ;
}
static T_5 int F_81 ( void )
{
int V_140 ;
struct V_163 * V_164 ;
void * V_165 ;
int V_141 ;
V_164 = F_82 ( V_142 , V_166 ) ;
if ( ! V_164 )
return - V_143 ;
V_165 = F_83 ( V_164 ) ;
memset ( V_165 , 0xff , V_153 * ( 1 << V_166 ) ) ;
V_167 = F_59 ( V_164 ) << V_134 ;
F_78 () ;
if ( F_84 ( V_168 ) )
F_85 ( V_169 ) ;
if ( F_84 ( V_170 ) )
F_85 ( V_171 ) ;
if ( F_84 ( V_110 ) ) {
T_2 V_172 ;
V_173 = true ;
V_172 = F_86 ( 0x7fffffffULL , F_87 ( V_174 , V_175 ) ) ;
V_176 = V_172 ;
}
if ( V_17 ) {
F_33 ( V_109 L_6 ) ;
F_85 ( V_59 | V_177 ) ;
}
F_88 (cpu) {
V_141 = F_66 ( V_140 ) ;
if ( V_141 )
goto V_96;
}
if ( ! F_84 ( V_178 ) )
V_55 = false ;
if ( V_55 && ! V_179 ) {
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
F_91 ( V_164 , V_166 ) ;
V_167 = 0 ;
return V_141 ;
}
static T_6 void F_92 ( void )
{
int V_140 ;
F_88 (cpu)
F_63 ( V_140 ) ;
F_91 ( F_93 ( V_167 >> V_134 ) , V_166 ) ;
V_167 = 0 ;
}
static void F_94 ( struct V_180 * V_181 )
{
V_181 -> V_182 = 0 ;
V_181 -> V_183 = V_184 | V_185 |
V_186 ;
V_181 -> V_187 = 0xffff ;
V_181 -> V_88 = 0 ;
}
static void F_95 ( struct V_180 * V_181 , T_7 type )
{
V_181 -> V_182 = 0 ;
V_181 -> V_183 = V_184 | type ;
V_181 -> V_187 = 0xffff ;
V_181 -> V_88 = 0 ;
}
static T_2 F_87 ( T_2 V_188 , T_2 V_189 )
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
static T_2 F_96 ( struct V_8 * V_9 , T_2 V_189 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_192 = V_189 ;
if ( V_10 -> V_193 != V_112 )
V_192 = F_87 ( V_10 -> V_193 , V_189 ) ;
return V_192 ;
}
static void F_97 ( struct V_8 * V_9 , T_1 V_194 , bool V_195 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_188 ;
T_2 V_196 ;
if ( ! V_195 ) {
V_10 -> V_193 = V_112 ;
return;
}
if ( ! F_84 ( V_110 ) ) {
if ( V_194 > V_174 ) {
V_9 -> V_39 . V_197 = 1 ;
V_9 -> V_39 . V_198 = 1 ;
} else
F_98 ( 1 , L_9 ) ;
return;
}
V_196 = V_194 ;
V_188 = V_196 << 32 ;
F_99 ( V_188 , V_174 ) ;
if ( V_188 == 0 || V_188 & V_199 ) {
F_100 ( 1 , L_10 ,
V_194 ) ;
return;
}
V_10 -> V_193 = V_188 ;
}
static T_2 F_101 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_200 ;
}
static void F_102 ( struct V_8 * V_9 , T_2 V_43 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_201 = 0 ;
if ( F_7 ( V_9 ) ) {
V_201 = V_10 -> V_1 -> V_2 . V_200 -
V_10 -> V_17 . V_18 -> V_2 . V_200 ;
V_10 -> V_17 . V_18 -> V_2 . V_200 = V_43 ;
} else
F_103 ( V_9 -> V_202 ,
V_10 -> V_1 -> V_2 . V_200 ,
V_43 ) ;
V_10 -> V_1 -> V_2 . V_200 = V_43 + V_201 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_104 ( struct V_8 * V_9 , T_8 V_203 , bool V_204 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_71 ( V_203 < 0 ) ;
if ( V_204 )
V_203 = F_96 ( V_9 , V_203 ) ;
V_10 -> V_1 -> V_2 . V_200 += V_203 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_200 += V_203 ;
else
F_103 ( V_9 -> V_202 ,
V_10 -> V_1 -> V_2 . V_200 - V_203 ,
V_10 -> V_1 -> V_2 . V_200 ) ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_105 ( struct V_8 * V_9 , T_2 V_205 )
{
T_2 V_189 ;
V_189 = F_96 ( V_9 , F_106 () ) ;
return V_205 - V_189 ;
}
static void F_107 ( struct V_7 * V_10 )
{
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_206 * V_58 = & V_10 -> V_1 -> V_58 ;
V_10 -> V_9 . V_207 = 1 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
F_9 ( V_10 , V_208 ) ;
F_9 ( V_10 , V_209 ) ;
F_9 ( V_10 , V_210 ) ;
F_9 ( V_10 , V_211 ) ;
F_9 ( V_10 , V_212 ) ;
F_9 ( V_10 , V_213 ) ;
F_9 ( V_10 , V_214 ) ;
F_12 ( V_10 ) ;
F_14 ( V_10 , V_215 ) ;
F_14 ( V_10 , V_216 ) ;
F_14 ( V_10 , V_217 ) ;
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
V_2 -> V_243 = V_167 ;
V_2 -> V_244 = F_108 ( V_10 -> V_147 ) ;
V_2 -> V_245 = V_246 ;
F_94 ( & V_58 -> V_247 ) ;
F_94 ( & V_58 -> V_248 ) ;
F_94 ( & V_58 -> V_249 ) ;
F_94 ( & V_58 -> V_250 ) ;
F_94 ( & V_58 -> V_251 ) ;
V_58 -> V_87 . V_182 = 0xf000 ;
V_58 -> V_87 . V_88 = 0xffff0000 ;
V_58 -> V_87 . V_183 = V_252 | V_184 |
V_185 | V_253 ;
V_58 -> V_87 . V_187 = 0xffff ;
V_58 -> V_254 . V_187 = 0xffff ;
V_58 -> V_255 . V_187 = 0xffff ;
F_95 ( & V_58 -> V_256 , V_257 ) ;
F_95 ( & V_58 -> V_258 , V_259 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_58 -> V_260 = 0xffff0ff0 ;
F_109 ( & V_10 -> V_9 , 2 ) ;
V_58 -> V_84 = 0x0000fff0 ;
V_10 -> V_9 . V_39 . V_261 [ V_262 ] = V_58 -> V_84 ;
V_10 -> V_9 . V_39 . V_263 = 0 ;
( void ) F_110 ( & V_10 -> V_9 , V_264 | V_265 | V_266 ) ;
V_58 -> V_267 = V_268 ;
if ( V_55 ) {
V_2 -> V_269 = 1 ;
F_17 ( V_10 , V_226 ) ;
F_15 ( V_10 , V_215 ) ;
F_10 ( V_10 , V_209 ) ;
F_10 ( V_10 , V_212 ) ;
V_58 -> V_270 = 0x0007040600070406ULL ;
V_58 -> V_271 = 0 ;
V_58 -> V_267 = 0 ;
}
V_10 -> V_124 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
if ( F_84 ( V_272 ) ) {
V_2 -> V_273 = 3000 ;
F_16 ( V_10 , V_274 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static void F_111 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_275 ;
T_1 V_276 = 1 ;
F_107 ( V_10 ) ;
F_112 ( V_9 , & V_276 , & V_275 , & V_275 , & V_275 ) ;
F_113 ( V_9 , V_277 , V_276 ) ;
}
static struct V_8 * F_114 ( struct V_278 * V_278 , unsigned int V_279 )
{
struct V_7 * V_10 ;
struct V_163 * V_163 ;
struct V_163 * V_280 ;
struct V_163 * V_281 ;
struct V_163 * V_282 ;
int V_96 ;
V_10 = F_115 ( V_283 , V_142 ) ;
if ( ! V_10 ) {
V_96 = - V_143 ;
goto V_284;
}
V_10 -> V_193 = V_112 ;
V_96 = F_116 ( & V_10 -> V_9 , V_278 , V_279 ) ;
if ( V_96 )
goto V_285;
V_96 = - V_143 ;
V_163 = F_68 ( V_142 ) ;
if ( ! V_163 )
goto V_286;
V_280 = F_82 ( V_142 , V_154 ) ;
if ( ! V_280 )
goto V_287;
V_282 = F_82 ( V_142 , V_154 ) ;
if ( ! V_282 )
goto V_288;
V_281 = F_68 ( V_142 ) ;
if ( ! V_281 )
goto V_289;
V_10 -> V_17 . V_18 = F_83 ( V_281 ) ;
V_10 -> V_147 = F_83 ( V_280 ) ;
F_75 ( V_10 -> V_147 ) ;
V_10 -> V_17 . V_147 = F_83 ( V_282 ) ;
F_75 ( V_10 -> V_17 . V_147 ) ;
V_10 -> V_1 = F_83 ( V_163 ) ;
F_117 ( V_10 -> V_1 ) ;
V_10 -> V_290 = F_59 ( V_163 ) << V_134 ;
V_10 -> V_124 = 0 ;
F_107 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_291 = V_292 |
V_293 ;
if ( F_118 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_39 . V_291 |= V_294 ;
F_45 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_289:
F_91 ( V_282 , V_154 ) ;
V_288:
F_91 ( V_280 , V_154 ) ;
V_287:
F_64 ( V_163 ) ;
V_286:
F_119 ( & V_10 -> V_9 ) ;
V_285:
F_120 ( V_283 , V_10 ) ;
V_284:
return F_121 ( V_96 ) ;
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_64 ( F_93 ( V_10 -> V_290 >> V_134 ) ) ;
F_91 ( F_123 ( V_10 -> V_147 ) , V_154 ) ;
F_64 ( F_123 ( V_10 -> V_17 . V_18 ) ) ;
F_91 ( F_123 ( V_10 -> V_17 . V_147 ) , V_154 ) ;
F_119 ( V_9 ) ;
F_120 ( V_283 , V_10 ) ;
}
static void F_124 ( struct V_8 * V_9 , int V_140 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
if ( F_125 ( V_140 != V_9 -> V_140 ) ) {
V_10 -> V_124 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_54 ( V_295 , F_4 ( V_9 ) -> V_204 . V_296 ) ;
#endif
F_126 ( V_250 , V_10 -> V_204 . V_250 ) ;
F_126 ( V_251 , V_10 -> V_204 . V_251 ) ;
V_10 -> V_204 . V_297 = F_127 () ;
for ( V_44 = 0 ; V_44 < V_298 ; V_44 ++ )
F_54 ( V_299 [ V_44 ] , V_10 -> V_300 [ V_44 ] ) ;
if ( F_38 ( V_110 ) &&
V_10 -> V_193 != F_128 ( V_135 ) ) {
F_60 ( V_135 , V_10 -> V_193 ) ;
F_49 ( V_111 , V_10 -> V_193 ) ;
}
}
static void F_129 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
++ V_9 -> V_301 . V_302 ;
F_130 ( V_10 -> V_204 . V_297 ) ;
#ifdef F_26
F_131 ( V_250 , V_10 -> V_204 . V_250 ) ;
F_49 ( V_303 , V_304 -> V_305 . V_251 ) ;
F_132 ( V_10 -> V_204 . V_251 ) ;
#else
#ifdef F_133
F_131 ( V_251 , V_10 -> V_204 . V_251 ) ;
#endif
#endif
for ( V_44 = 0 ; V_44 < V_298 ; V_44 ++ )
F_49 ( V_299 [ V_44 ] , V_10 -> V_300 [ V_44 ] ) ;
}
static unsigned long F_134 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_306 ;
}
static void F_135 ( struct V_8 * V_9 , unsigned long V_306 )
{
F_4 ( V_9 ) -> V_1 -> V_58 . V_306 = V_306 ;
}
static void F_136 ( struct V_8 * V_9 , enum V_307 V_308 )
{
switch ( V_308 ) {
case V_309 :
F_72 ( ! V_55 ) ;
F_137 ( V_9 , V_9 -> V_39 . V_310 , F_138 ( V_9 ) ) ;
break;
default:
F_77 () ;
}
}
static void F_139 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_311 ) ;
}
static void F_140 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_311 ) ;
}
static struct V_180 * F_141 ( struct V_8 * V_9 , int V_181 )
{
struct V_206 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_181 ) {
case V_312 : return & V_58 -> V_87 ;
case V_313 : return & V_58 -> V_249 ;
case V_314 : return & V_58 -> V_247 ;
case V_315 : return & V_58 -> V_250 ;
case V_316 : return & V_58 -> V_251 ;
case V_317 : return & V_58 -> V_248 ;
case V_318 : return & V_58 -> V_258 ;
case V_319 : return & V_58 -> V_256 ;
}
F_77 () ;
return NULL ;
}
static T_2 F_142 ( struct V_8 * V_9 , int V_181 )
{
struct V_180 * V_320 = F_141 ( V_9 , V_181 ) ;
return V_320 -> V_88 ;
}
static void F_143 ( struct V_8 * V_9 ,
struct V_321 * V_322 , int V_181 )
{
struct V_180 * V_320 = F_141 ( V_9 , V_181 ) ;
V_322 -> V_88 = V_320 -> V_88 ;
V_322 -> V_187 = V_320 -> V_187 ;
V_322 -> V_182 = V_320 -> V_182 ;
V_322 -> type = V_320 -> V_183 & V_323 ;
V_322 -> V_320 = ( V_320 -> V_183 >> V_324 ) & 1 ;
V_322 -> V_325 = ( V_320 -> V_183 >> V_326 ) & 3 ;
V_322 -> V_327 = ( V_320 -> V_183 >> V_328 ) & 1 ;
V_322 -> V_329 = ( V_320 -> V_183 >> V_330 ) & 1 ;
V_322 -> V_331 = ( V_320 -> V_183 >> V_332 ) & 1 ;
V_322 -> V_333 = ( V_320 -> V_183 >> V_334 ) & 1 ;
V_322 -> V_15 = V_320 -> V_187 > 0xfffff ;
V_322 -> V_335 = ! V_322 -> V_327 || ( V_322 -> type == 0 ) ;
switch ( V_181 ) {
case V_318 :
V_322 -> type |= 0x2 ;
break;
case V_313 :
case V_314 :
case V_315 :
case V_316 :
if ( ! V_322 -> V_335 )
V_322 -> type |= 0x1 ;
break;
case V_317 :
if ( V_322 -> V_335 )
V_322 -> V_333 = 0 ;
V_322 -> V_325 = F_4 ( V_9 ) -> V_1 -> V_58 . V_336 ;
break;
}
}
static int F_144 ( struct V_8 * V_9 )
{
struct V_206 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_336 ;
}
static void F_145 ( struct V_8 * V_9 , struct V_115 * V_337 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_337 -> V_338 = V_10 -> V_1 -> V_58 . V_255 . V_187 ;
V_337 -> V_128 = V_10 -> V_1 -> V_58 . V_255 . V_88 ;
}
static void F_146 ( struct V_8 * V_9 , struct V_115 * V_337 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_255 . V_187 = V_337 -> V_338 ;
V_10 -> V_1 -> V_58 . V_255 . V_88 = V_337 -> V_128 ;
F_3 ( V_10 -> V_1 , V_339 ) ;
}
static void F_147 ( struct V_8 * V_9 , struct V_115 * V_337 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_337 -> V_338 = V_10 -> V_1 -> V_58 . V_254 . V_187 ;
V_337 -> V_128 = V_10 -> V_1 -> V_58 . V_254 . V_88 ;
}
static void F_148 ( struct V_8 * V_9 , struct V_115 * V_337 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_254 . V_187 = V_337 -> V_338 ;
V_10 -> V_1 -> V_58 . V_254 . V_88 = V_337 -> V_128 ;
F_3 ( V_10 -> V_1 , V_339 ) ;
}
static void F_149 ( struct V_8 * V_9 )
{
}
static void F_150 ( struct V_8 * V_9 )
{
}
static void F_151 ( struct V_8 * V_9 )
{
}
static void F_152 ( struct V_7 * V_10 )
{
T_9 V_340 = V_10 -> V_9 . V_39 . V_263 ;
T_2 * V_341 = & V_10 -> V_1 -> V_58 . V_263 ;
if ( ! V_10 -> V_9 . V_207 )
* V_341 |= V_342 ;
else
* V_341 = ( * V_341 & ~ V_342 )
| ( V_340 & V_342 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_340 == * V_341 && V_10 -> V_9 . V_207 ) {
F_10 ( V_10 , V_208 ) ;
F_10 ( V_10 , V_211 ) ;
} else {
F_9 ( V_10 , V_208 ) ;
F_9 ( V_10 , V_211 ) ;
}
}
static void F_153 ( struct V_8 * V_9 , unsigned long V_263 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_154 ( V_9 ) && ( V_263 & V_343 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_154 ( V_9 ) && ! ( V_263 & V_343 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_263 = V_263 ;
if ( ! V_55 )
V_263 |= V_343 | V_344 ;
if ( ! V_9 -> V_207 )
V_263 |= V_345 ;
V_263 &= ~ ( V_265 | V_264 ) ;
V_10 -> V_1 -> V_58 . V_263 = V_263 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_152 ( V_10 ) ;
}
static int F_155 ( struct V_8 * V_9 , unsigned long V_267 )
{
unsigned long V_346 = F_156 () & V_347 ;
unsigned long V_348 = F_4 ( V_9 ) -> V_1 -> V_58 . V_267 ;
if ( V_267 & V_349 )
return 1 ;
if ( V_55 && ( ( V_348 ^ V_267 ) & V_350 ) )
F_157 ( V_9 ) ;
V_9 -> V_39 . V_267 = V_267 ;
if ( ! V_55 )
V_267 |= V_268 ;
V_267 |= V_346 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_267 = V_267 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_158 ( struct V_8 * V_9 ,
struct V_321 * V_322 , int V_181 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_180 * V_320 = F_141 ( V_9 , V_181 ) ;
V_320 -> V_88 = V_322 -> V_88 ;
V_320 -> V_187 = V_322 -> V_187 ;
V_320 -> V_182 = V_322 -> V_182 ;
if ( V_322 -> V_335 )
V_320 -> V_183 = 0 ;
else {
V_320 -> V_183 = ( V_322 -> type & V_323 ) ;
V_320 -> V_183 |= ( V_322 -> V_320 & 1 ) << V_324 ;
V_320 -> V_183 |= ( V_322 -> V_325 & 3 ) << V_326 ;
V_320 -> V_183 |= ( V_322 -> V_327 & 1 ) << V_328 ;
V_320 -> V_183 |= ( V_322 -> V_329 & 1 ) << V_330 ;
V_320 -> V_183 |= ( V_322 -> V_331 & 1 ) << V_332 ;
V_320 -> V_183 |= ( V_322 -> V_333 & 1 ) << V_334 ;
V_320 -> V_183 |= ( V_322 -> V_15 & 1 ) << V_351 ;
}
if ( V_181 == V_317 )
V_10 -> V_1 -> V_58 . V_336 = ( V_320 -> V_183 >> V_326 ) & 3 ;
F_3 ( V_10 -> V_1 , V_352 ) ;
}
static void F_159 ( struct V_8 * V_9 )
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
static void F_160 ( struct V_7 * V_10 , struct V_113 * V_114 )
{
if ( V_114 -> V_127 > V_114 -> V_125 ) {
++ V_114 -> V_124 ;
V_114 -> V_127 = 1 ;
V_10 -> V_1 -> V_2 . V_360 = V_361 ;
}
V_10 -> V_124 = V_114 -> V_124 ;
V_10 -> V_1 -> V_2 . V_51 = V_114 -> V_127 ++ ;
F_3 ( V_10 -> V_1 , V_362 ) ;
}
static T_2 F_161 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_260 ;
}
static void F_162 ( struct V_8 * V_9 , unsigned long V_363 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_260 = V_363 ;
F_3 ( V_10 -> V_1 , V_364 ) ;
}
static void F_163 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_164 ( V_9 -> V_39 . V_333 [ 0 ] , 0 ) ;
F_164 ( V_9 -> V_39 . V_333 [ 1 ] , 1 ) ;
F_164 ( V_9 -> V_39 . V_333 [ 2 ] , 2 ) ;
F_164 ( V_9 -> V_39 . V_333 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_260 = F_161 ( V_9 ) ;
V_9 -> V_39 . V_365 = V_10 -> V_1 -> V_58 . V_365 ;
V_9 -> V_39 . V_366 &= ~ V_367 ;
F_12 ( V_10 ) ;
}
static void F_165 ( struct V_8 * V_9 , unsigned long V_363 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_365 = V_363 ;
F_3 ( V_10 -> V_1 , V_364 ) ;
}
static int F_166 ( struct V_7 * V_10 )
{
T_2 V_368 = V_10 -> V_1 -> V_2 . V_369 ;
T_1 V_80 ;
int V_141 = 1 ;
switch ( V_10 -> V_370 ) {
default:
V_80 = V_10 -> V_1 -> V_2 . V_371 ;
F_167 ( V_368 , V_80 ) ;
if ( ! V_55 && F_168 ( & V_10 -> V_9 ) )
F_169 ( & V_10 -> V_9 , V_368 ) ;
V_141 = F_170 ( & V_10 -> V_9 , V_368 , V_80 ,
V_10 -> V_1 -> V_2 . V_372 ,
V_10 -> V_1 -> V_2 . V_373 ) ;
break;
case V_374 :
V_10 -> V_370 = 0 ;
F_171 () ;
F_172 ( V_368 ) ;
F_173 () ;
break;
case V_375 :
V_10 -> V_370 = 0 ;
F_171 () ;
F_174 ( V_368 ) ;
F_173 () ;
break;
}
return V_141 ;
}
static int F_175 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
if ( ! ( V_10 -> V_9 . V_355 &
( V_357 | V_358 ) ) &&
! V_10 -> V_354 ) {
F_176 ( & V_10 -> V_9 , V_353 ) ;
return 1 ;
}
if ( V_10 -> V_354 ) {
V_10 -> V_354 = false ;
if ( ! ( V_10 -> V_9 . V_355 & V_357 ) )
V_10 -> V_1 -> V_58 . V_306 &=
~ ( V_378 | V_379 ) ;
F_159 ( & V_10 -> V_9 ) ;
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
static int F_177 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
V_376 -> V_380 = V_381 ;
V_376 -> V_382 . V_39 . V_383 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_376 -> V_382 . V_39 . V_384 = V_82 ;
return 0 ;
}
static int F_178 ( struct V_7 * V_10 )
{
int V_385 ;
V_385 = F_32 ( & V_10 -> V_9 , V_386 ) ;
if ( V_385 != V_73 )
F_176 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static void F_179 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_387 ) ;
V_10 -> V_9 . V_207 = 1 ;
F_152 ( V_10 ) ;
}
static int F_180 ( struct V_7 * V_10 )
{
F_179 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_181 ( void )
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
F_44 ( F_182 ( V_44 ) , 0 , 0 ) ;
V_363 = F_41 ( V_389 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_363 &= ~ ( 1ULL << 2 ) ;
V_94 = F_42 ( V_363 ) ;
V_95 = F_43 ( V_363 ) ;
F_44 ( V_389 , V_94 , V_95 ) ;
}
F_183 () ;
return true ;
}
static void F_184 ( struct V_7 * V_10 )
{
if ( F_181 () ) {
F_55 ( L_11 ) ;
F_185 ( V_390 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_186 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_187 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
F_117 ( V_10 -> V_1 ) ;
F_107 ( V_10 ) ;
V_376 -> V_380 = V_391 ;
return 0 ;
}
static int F_188 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_392 = V_10 -> V_1 -> V_2 . V_371 ;
int V_338 , V_393 , string ;
unsigned V_394 ;
++ V_10 -> V_9 . V_301 . V_395 ;
string = ( V_392 & V_396 ) != 0 ;
V_393 = ( V_392 & V_397 ) != 0 ;
if ( string || V_393 )
return F_32 ( V_9 , 0 ) == V_73 ;
V_394 = V_392 >> 16 ;
V_338 = ( V_392 & V_398 ) >> V_399 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_369 ;
F_31 ( & V_10 -> V_9 ) ;
return F_189 ( V_9 , V_338 , V_394 ) ;
}
static int F_190 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_191 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_301 . V_400 ;
return 1 ;
}
static int F_192 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_193 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 1 ;
F_31 ( & V_10 -> V_9 ) ;
return F_194 ( & V_10 -> V_9 ) ;
}
static int F_195 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_196 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_197 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_401 ;
}
static T_2 F_198 ( struct V_8 * V_9 , int V_145 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_271 = V_10 -> V_17 . V_401 ;
T_2 V_402 ;
int V_65 ;
V_65 = F_199 ( V_9 -> V_278 , F_200 ( V_271 ) , & V_402 ,
F_201 ( V_271 ) + V_145 * 8 , 8 ) ;
if ( V_65 )
return 0 ;
return V_402 ;
}
static void F_202 ( struct V_8 * V_9 ,
unsigned long V_403 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_401 = V_403 ;
F_3 ( V_10 -> V_1 , V_404 ) ;
F_157 ( V_9 ) ;
}
static void F_203 ( struct V_8 * V_9 ,
struct V_405 * V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_407 != V_408 ) {
V_10 -> V_1 -> V_2 . V_407 = V_408 ;
V_10 -> V_1 -> V_2 . V_409 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_369 = V_406 -> V_128 ;
}
V_10 -> V_1 -> V_2 . V_371 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_371 |= V_406 -> V_80 ;
if ( V_10 -> V_1 -> V_2 . V_371 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_371 &= ~ 1 ;
F_204 ( V_10 ) ;
}
static void F_205 ( struct V_8 * V_9 )
{
F_206 ( V_9 , & V_9 -> V_39 . V_410 ) ;
V_9 -> V_39 . V_410 . V_411 = F_202 ;
V_9 -> V_39 . V_410 . V_412 = F_197 ;
V_9 -> V_39 . V_410 . V_413 = F_198 ;
V_9 -> V_39 . V_410 . V_414 = F_203 ;
V_9 -> V_39 . V_410 . V_415 = F_25 () ;
V_9 -> V_39 . V_310 = & V_9 -> V_39 . V_416 ;
}
static void F_207 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_310 = & V_9 -> V_39 . V_410 ;
}
static int F_208 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_154 ( & V_10 -> V_9 ) ) {
F_176 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_336 ) {
F_209 ( & V_10 -> V_9 , 0 ) ;
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
V_417 = F_210 ( V_10 ) ;
if ( V_417 == V_420 )
V_10 -> V_17 . V_421 = true ;
return V_417 ;
}
static inline bool F_211 ( struct V_7 * V_10 )
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
F_212 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_213 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_219 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_407 = V_425 ;
V_10 -> V_17 . V_421 = true ;
return false ;
}
static void * F_214 ( struct V_7 * V_10 , T_2 V_426 , struct V_163 * * V_427 )
{
struct V_163 * V_163 ;
F_215 () ;
V_163 = F_216 ( V_10 -> V_9 . V_278 , V_426 >> V_134 ) ;
if ( F_217 ( V_163 ) )
goto error;
* V_427 = V_163 ;
return F_218 ( V_163 ) ;
error:
F_209 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_219 ( struct V_163 * V_163 )
{
F_220 ( V_163 ) ;
F_221 ( V_163 ) ;
}
static int F_222 ( struct V_7 * V_10 )
{
unsigned V_394 , V_338 , V_428 ;
T_10 V_97 , V_70 ;
T_4 V_429 ;
T_2 V_426 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_228 ) ) )
return V_430 ;
V_394 = V_10 -> V_1 -> V_2 . V_371 >> 16 ;
V_338 = ( V_10 -> V_1 -> V_2 . V_371 & V_398 ) >>
V_399 ;
V_426 = V_10 -> V_17 . V_431 + ( V_394 / 8 ) ;
V_429 = V_394 % 8 ;
V_428 = ( V_429 + V_338 > 8 ) ? 2 : 1 ;
V_70 = ( 0xf >> ( 4 - V_338 ) ) << V_429 ;
V_97 = 0 ;
if ( F_223 ( V_10 -> V_9 . V_278 , V_426 , & V_97 , V_428 ) )
return V_420 ;
return ( V_97 & V_70 ) ? V_420 : V_430 ;
}
static int F_224 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_363 ;
int V_149 , V_70 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return V_430 ;
V_42 = V_10 -> V_9 . V_39 . V_261 [ V_432 ] ;
V_43 = F_21 ( V_42 ) ;
V_149 = V_10 -> V_1 -> V_2 . V_371 & 1 ;
V_70 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_149 ) ;
if ( V_43 == V_49 )
return V_420 ;
V_43 *= 4 ;
if ( F_223 ( V_10 -> V_9 . V_278 , V_10 -> V_17 . V_433 + V_43 , & V_363 , 4 ) )
return V_420 ;
return ( V_363 & V_70 ) ? V_420 : V_430 ;
}
static int F_225 ( struct V_7 * V_10 )
{
T_1 V_407 = V_10 -> V_1 -> V_2 . V_407 ;
switch ( V_407 ) {
case V_424 :
case V_425 :
case V_418 + V_217 :
return V_430 ;
case V_408 :
if ( V_55 )
return V_430 ;
break;
case V_418 + V_215 :
if ( ! V_55 && V_10 -> V_370 == 0 )
return V_430 ;
break;
case V_418 + V_387 :
F_180 ( V_10 ) ;
break;
default:
break;
}
return V_434 ;
}
static int F_210 ( struct V_7 * V_10 )
{
T_1 V_407 = V_10 -> V_1 -> V_2 . V_407 ;
int V_417 = V_430 ;
switch ( V_407 ) {
case V_435 :
V_417 = F_224 ( V_10 ) ;
break;
case V_436 :
V_417 = F_222 ( V_10 ) ;
break;
case V_437 ... V_438 : {
T_1 V_6 = 1U << ( V_407 - V_437 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_417 = V_420 ;
break;
}
case V_439 ... V_440 : {
T_1 V_6 = 1U << ( V_407 - V_439 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_417 = V_420 ;
break;
}
case V_418 ... V_418 + 0x1f : {
T_1 V_441 = 1 << ( V_407 - V_418 ) ;
if ( V_10 -> V_17 . V_21 & V_441 )
V_417 = V_420 ;
else if ( ( V_407 == V_418 + V_215 ) &&
V_10 -> V_370 != 0 )
V_417 = V_420 ;
break;
}
case V_442 : {
V_417 = V_420 ;
break;
}
default: {
T_2 V_443 = 1ULL << ( V_407 - V_424 ) ;
if ( V_10 -> V_17 . V_22 & V_443 )
V_417 = V_420 ;
}
}
return V_417 ;
}
static int F_226 ( struct V_7 * V_10 )
{
int V_417 ;
V_417 = F_210 ( V_10 ) ;
if ( V_417 == V_420 )
F_204 ( V_10 ) ;
return V_417 ;
}
static inline void F_227 ( struct V_1 * V_444 , struct V_1 * V_445 )
{
struct V_11 * V_446 = & V_444 -> V_2 ;
struct V_11 * V_447 = & V_445 -> V_2 ;
V_446 -> V_19 = V_447 -> V_19 ;
V_446 -> V_20 = V_447 -> V_20 ;
V_446 -> V_21 = V_447 -> V_21 ;
V_446 -> V_22 = V_447 -> V_22 ;
V_446 -> V_243 = V_447 -> V_243 ;
V_446 -> V_244 = V_447 -> V_244 ;
V_446 -> V_200 = V_447 -> V_200 ;
V_446 -> V_51 = V_447 -> V_51 ;
V_446 -> V_360 = V_447 -> V_360 ;
V_446 -> V_245 = V_447 -> V_245 ;
V_446 -> V_448 = V_447 -> V_448 ;
V_446 -> V_66 = V_447 -> V_66 ;
V_446 -> V_407 = V_447 -> V_407 ;
V_446 -> V_409 = V_447 -> V_409 ;
V_446 -> V_371 = V_447 -> V_371 ;
V_446 -> V_369 = V_447 -> V_369 ;
V_446 -> V_449 = V_447 -> V_449 ;
V_446 -> V_450 = V_447 -> V_450 ;
V_446 -> V_269 = V_447 -> V_269 ;
V_446 -> V_90 = V_447 -> V_90 ;
V_446 -> V_93 = V_447 -> V_93 ;
V_446 -> V_401 = V_447 -> V_401 ;
V_446 -> V_158 = V_447 -> V_158 ;
}
static int F_204 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
F_228 ( V_1 -> V_2 . V_407 ,
V_1 -> V_2 . V_371 ,
V_1 -> V_2 . V_369 ,
V_1 -> V_2 . V_449 ,
V_1 -> V_2 . V_450 ,
V_452 ) ;
V_451 = F_214 ( V_10 , V_10 -> V_17 . V_1 , & V_163 ) ;
if ( ! V_451 )
return 1 ;
F_229 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_451 -> V_58 . V_247 = V_1 -> V_58 . V_247 ;
V_451 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_451 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_451 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_451 -> V_58 . V_254 = V_1 -> V_58 . V_254 ;
V_451 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_451 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_451 -> V_58 . V_263 = F_230 ( & V_10 -> V_9 ) ;
V_451 -> V_58 . V_271 = F_138 ( & V_10 -> V_9 ) ;
V_451 -> V_58 . V_419 = V_1 -> V_58 . V_419 ;
V_451 -> V_58 . V_267 = V_10 -> V_9 . V_39 . V_267 ;
V_451 -> V_58 . V_306 = F_231 ( & V_10 -> V_9 ) ;
V_451 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_451 -> V_58 . V_453 = V_1 -> V_58 . V_453 ;
V_451 -> V_58 . V_454 = V_1 -> V_58 . V_454 ;
V_451 -> V_58 . V_365 = V_1 -> V_58 . V_365 ;
V_451 -> V_58 . V_260 = V_1 -> V_58 . V_260 ;
V_451 -> V_58 . V_336 = V_1 -> V_58 . V_336 ;
V_451 -> V_2 . V_245 = V_1 -> V_2 . V_245 ;
V_451 -> V_2 . V_448 = V_1 -> V_2 . V_448 ;
V_451 -> V_2 . V_66 = V_1 -> V_2 . V_66 ;
V_451 -> V_2 . V_407 = V_1 -> V_2 . V_407 ;
V_451 -> V_2 . V_409 = V_1 -> V_2 . V_409 ;
V_451 -> V_2 . V_371 = V_1 -> V_2 . V_371 ;
V_451 -> V_2 . V_369 = V_1 -> V_2 . V_369 ;
V_451 -> V_2 . V_449 = V_1 -> V_2 . V_449 ;
V_451 -> V_2 . V_450 = V_1 -> V_2 . V_450 ;
V_451 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_455 = & V_451 -> V_2 ;
V_455 -> V_449 = V_1 -> V_2 . V_90 ;
V_455 -> V_450 = V_1 -> V_2 . V_93 ;
}
V_451 -> V_2 . V_360 = 0 ;
V_451 -> V_2 . V_90 = 0 ;
V_451 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_422 ) )
V_451 -> V_2 . V_245 &= ~ V_246 ;
F_227 ( V_1 , V_18 ) ;
F_232 ( & V_10 -> V_9 ) ;
F_233 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_401 = 0 ;
V_10 -> V_1 -> V_58 . V_247 = V_18 -> V_58 . V_247 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_248 = V_18 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_249 = V_18 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_254 = V_18 -> V_58 . V_254 ;
V_10 -> V_1 -> V_58 . V_255 = V_18 -> V_58 . V_255 ;
F_109 ( & V_10 -> V_9 , V_18 -> V_58 . V_306 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_153 ( & V_10 -> V_9 , V_18 -> V_58 . V_263 | V_456 ) ;
F_155 ( & V_10 -> V_9 , V_18 -> V_58 . V_267 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_271 = V_18 -> V_58 . V_271 ;
V_10 -> V_9 . V_39 . V_271 = V_18 -> V_58 . V_271 ;
} else {
( void ) F_234 ( & V_10 -> V_9 , V_18 -> V_58 . V_271 ) ;
}
F_113 ( & V_10 -> V_9 , V_457 , V_18 -> V_58 . V_454 ) ;
F_113 ( & V_10 -> V_9 , V_458 , V_18 -> V_58 . V_453 ) ;
F_113 ( & V_10 -> V_9 , V_262 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_365 = 0 ;
V_10 -> V_1 -> V_58 . V_336 = 0 ;
V_10 -> V_1 -> V_2 . V_449 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_219 ( V_163 ) ;
F_207 ( & V_10 -> V_9 ) ;
F_235 ( & V_10 -> V_9 ) ;
F_236 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_237 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_156 ; V_44 ++ ) {
T_1 V_363 , V_459 ;
T_2 V_43 ;
if ( V_157 [ V_44 ] == 0xffffffff )
break;
V_459 = V_157 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_433 + ( V_459 * 4 ) ;
if ( F_223 ( V_10 -> V_9 . V_278 , V_43 , & V_363 , 4 ) )
return false ;
V_10 -> V_17 . V_147 [ V_459 ] = V_10 -> V_147 [ V_459 ] | V_363 ;
}
V_10 -> V_1 -> V_2 . V_244 = F_108 ( V_10 -> V_17 . V_147 ) ;
return true ;
}
static bool F_238 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_232 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_269 && ! V_55 )
return false ;
return true ;
}
static bool F_239 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_163 * V_163 ;
T_2 V_460 ;
V_460 = V_10 -> V_1 -> V_58 . V_454 ;
V_451 = F_214 ( V_10 , V_10 -> V_1 -> V_58 . V_454 , & V_163 ) ;
if ( ! V_451 )
return false ;
if ( ! F_238 ( V_451 ) ) {
V_451 -> V_2 . V_407 = V_442 ;
V_451 -> V_2 . V_409 = 0 ;
V_451 -> V_2 . V_371 = 0 ;
V_451 -> V_2 . V_369 = 0 ;
F_219 ( V_163 ) ;
return false ;
}
F_240 ( V_10 -> V_1 -> V_58 . V_84 , V_460 ,
V_451 -> V_58 . V_84 ,
V_451 -> V_2 . V_245 ,
V_451 -> V_2 . V_90 ,
V_451 -> V_2 . V_269 ) ;
F_241 ( V_451 -> V_2 . V_19 & 0xffff ,
V_451 -> V_2 . V_19 >> 16 ,
V_451 -> V_2 . V_21 ,
V_451 -> V_2 . V_22 ) ;
F_232 ( & V_10 -> V_9 ) ;
F_233 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_247 = V_1 -> V_58 . V_247 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_248 = V_1 -> V_58 . V_248 ;
V_18 -> V_58 . V_249 = V_1 -> V_58 . V_249 ;
V_18 -> V_58 . V_254 = V_1 -> V_58 . V_254 ;
V_18 -> V_58 . V_255 = V_1 -> V_58 . V_255 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_263 = F_230 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_267 = V_10 -> V_9 . V_39 . V_267 ;
V_18 -> V_58 . V_306 = F_231 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_453 = V_1 -> V_58 . V_453 ;
V_18 -> V_58 . V_454 = V_1 -> V_58 . V_454 ;
if ( V_55 )
V_18 -> V_58 . V_271 = V_1 -> V_58 . V_271 ;
else
V_18 -> V_58 . V_271 = F_138 ( & V_10 -> V_9 ) ;
F_227 ( V_18 , V_1 ) ;
if ( F_231 ( & V_10 -> V_9 ) & V_461 )
V_10 -> V_9 . V_39 . V_40 |= V_423 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_423 ;
if ( V_451 -> V_2 . V_269 ) {
F_242 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_401 = V_451 -> V_2 . V_401 ;
F_205 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_247 = V_451 -> V_58 . V_247 ;
V_10 -> V_1 -> V_58 . V_87 = V_451 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_248 = V_451 -> V_58 . V_248 ;
V_10 -> V_1 -> V_58 . V_249 = V_451 -> V_58 . V_249 ;
V_10 -> V_1 -> V_58 . V_254 = V_451 -> V_58 . V_254 ;
V_10 -> V_1 -> V_58 . V_255 = V_451 -> V_58 . V_255 ;
F_109 ( & V_10 -> V_9 , V_451 -> V_58 . V_306 ) ;
F_27 ( & V_10 -> V_9 , V_451 -> V_58 . V_54 ) ;
F_153 ( & V_10 -> V_9 , V_451 -> V_58 . V_263 ) ;
F_155 ( & V_10 -> V_9 , V_451 -> V_58 . V_267 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_271 = V_451 -> V_58 . V_271 ;
V_10 -> V_9 . V_39 . V_271 = V_451 -> V_58 . V_271 ;
} else
( void ) F_234 ( & V_10 -> V_9 , V_451 -> V_58 . V_271 ) ;
F_235 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_419 = V_10 -> V_9 . V_39 . V_419 = V_451 -> V_58 . V_419 ;
F_113 ( & V_10 -> V_9 , V_457 , V_451 -> V_58 . V_454 ) ;
F_113 ( & V_10 -> V_9 , V_458 , V_451 -> V_58 . V_453 ) ;
F_113 ( & V_10 -> V_9 , V_262 , V_451 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_454 = V_451 -> V_58 . V_454 ;
V_10 -> V_1 -> V_58 . V_453 = V_451 -> V_58 . V_453 ;
V_10 -> V_1 -> V_58 . V_84 = V_451 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_365 = V_451 -> V_58 . V_365 ;
V_10 -> V_1 -> V_58 . V_260 = V_451 -> V_58 . V_260 ;
V_10 -> V_1 -> V_58 . V_336 = V_451 -> V_58 . V_336 ;
V_10 -> V_17 . V_433 = V_451 -> V_2 . V_244 & ~ 0x0fffULL ;
V_10 -> V_17 . V_431 = V_451 -> V_2 . V_243 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_451 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_451 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_451 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_451 -> V_2 . V_22 ;
F_157 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_245 = V_451 -> V_2 . V_245 | V_246 ;
if ( V_451 -> V_2 . V_245 & V_246 )
V_10 -> V_9 . V_39 . V_40 |= V_422 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_422 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_422 ) {
F_10 ( V_10 , V_462 ) ;
F_10 ( V_10 , V_214 ) ;
}
F_17 ( V_10 , V_233 ) ;
V_10 -> V_1 -> V_2 . V_158 = V_451 -> V_2 . V_158 ;
V_10 -> V_1 -> V_2 . V_448 = V_451 -> V_2 . V_448 ;
V_10 -> V_1 -> V_2 . V_66 = V_451 -> V_2 . V_66 ;
V_10 -> V_1 -> V_2 . V_200 += V_451 -> V_2 . V_200 ;
V_10 -> V_1 -> V_2 . V_90 = V_451 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_451 -> V_2 . V_93 ;
F_219 ( V_163 ) ;
F_243 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_460 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_244 ( struct V_1 * V_445 , struct V_1 * V_463 )
{
V_463 -> V_58 . V_250 = V_445 -> V_58 . V_250 ;
V_463 -> V_58 . V_251 = V_445 -> V_58 . V_251 ;
V_463 -> V_58 . V_258 = V_445 -> V_58 . V_258 ;
V_463 -> V_58 . V_256 = V_445 -> V_58 . V_256 ;
V_463 -> V_58 . V_464 = V_445 -> V_58 . V_464 ;
V_463 -> V_58 . V_465 = V_445 -> V_58 . V_465 ;
V_463 -> V_58 . V_466 = V_445 -> V_58 . V_466 ;
V_463 -> V_58 . V_467 = V_445 -> V_58 . V_467 ;
V_463 -> V_58 . V_468 = V_445 -> V_58 . V_468 ;
V_463 -> V_58 . V_469 = V_445 -> V_58 . V_469 ;
V_463 -> V_58 . V_470 = V_445 -> V_58 . V_470 ;
V_463 -> V_58 . V_471 = V_445 -> V_58 . V_471 ;
}
static int F_245 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_163 * V_163 ;
if ( F_208 ( V_10 ) )
return 1 ;
V_451 = F_214 ( V_10 , V_10 -> V_1 -> V_58 . V_454 , & V_163 ) ;
if ( ! V_451 )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_244 ( V_451 , V_10 -> V_1 ) ;
F_219 ( V_163 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
struct V_1 * V_451 ;
struct V_163 * V_163 ;
if ( F_208 ( V_10 ) )
return 1 ;
V_451 = F_214 ( V_10 , V_10 -> V_1 -> V_58 . V_454 , & V_163 ) ;
if ( ! V_451 )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_244 ( V_10 -> V_1 , V_451 ) ;
F_219 ( V_163 ) ;
return 1 ;
}
static int F_247 ( struct V_7 * V_10 )
{
if ( F_208 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_239 ( V_10 ) )
return 1 ;
if ( ! F_237 ( V_10 ) )
goto V_472;
return 1 ;
V_472:
V_10 -> V_1 -> V_2 . V_407 = V_442 ;
V_10 -> V_1 -> V_2 . V_409 = 0 ;
V_10 -> V_1 -> V_2 . V_371 = 0 ;
V_10 -> V_1 -> V_2 . V_369 = 0 ;
F_204 ( V_10 ) ;
return 1 ;
}
static int F_248 ( struct V_7 * V_10 )
{
if ( F_208 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_185 ( V_473 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_249 ( struct V_7 * V_10 )
{
if ( F_208 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_140 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_474 ;
F_3 ( V_10 -> V_1 , V_475 ) ;
return 1 ;
}
static int F_250 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_251 ( V_10 -> V_1 -> V_58 . V_84 , V_9 -> V_39 . V_261 [ V_432 ] ,
V_9 -> V_39 . V_261 [ V_457 ] ) ;
F_252 ( V_9 , V_9 -> V_39 . V_261 [ V_457 ] ) ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_253 ( struct V_7 * V_10 )
{
F_254 ( V_10 -> V_1 -> V_58 . V_84 , V_10 -> V_9 . V_39 . V_261 [ V_457 ] ) ;
F_176 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static int F_255 ( struct V_7 * V_10 )
{
T_2 V_476 = F_256 ( & V_10 -> V_9 ) ;
T_1 V_145 = F_257 ( & V_10 -> V_9 , V_432 ) ;
if ( F_258 ( & V_10 -> V_9 , V_145 , V_476 ) == 0 ) {
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_259 ( struct V_7 * V_10 )
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
V_477 = ( T_10 ) V_10 -> V_1 -> V_2 . V_371 ;
if ( V_10 -> V_1 -> V_2 . V_369 &
( 1ULL << V_485 ) )
V_478 = V_486 ;
else if ( V_10 -> V_1 -> V_2 . V_369 &
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
if ( V_10 -> V_1 -> V_2 . V_369 &
( 1ULL << V_494 ) ) {
V_79 = true ;
V_80 =
( T_1 ) V_10 -> V_1 -> V_2 . V_369 ;
}
F_232 ( & V_10 -> V_9 ) ;
break;
case V_495 :
F_233 ( & V_10 -> V_9 ) ;
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
if ( F_260 ( & V_10 -> V_9 , V_477 , V_481 , V_478 ,
V_79 , V_80 ) == V_498 ) {
V_10 -> V_9 . V_377 -> V_380 = V_499 ;
V_10 -> V_9 . V_377 -> V_500 . V_501 = V_502 ;
V_10 -> V_9 . V_377 -> V_500 . V_503 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_261 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_262 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_301 . V_504 ;
F_17 ( V_10 , V_505 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_506 ;
V_10 -> V_507 = F_34 ( & V_10 -> V_9 ) ;
F_185 ( V_473 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_264 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_508 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_73 ;
F_252 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_371 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_265 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_73 ;
}
static int F_266 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_38 ( V_83 ) )
return F_265 ( V_10 ) ;
V_96 = F_267 ( & V_10 -> V_9 ) ;
F_268 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
bool F_269 ( struct V_7 * V_10 , unsigned long V_97 )
{
unsigned long V_263 = V_10 -> V_9 . V_39 . V_263 ;
bool V_65 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_221 ) ) ) )
return false ;
V_263 &= ~ V_342 ;
V_97 &= ~ V_342 ;
if ( V_263 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_407 = V_509 ;
V_65 = ( F_226 ( V_10 ) == V_420 ) ;
}
return V_65 ;
}
static int F_270 ( struct V_7 * V_10 )
{
int V_308 , V_510 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_38 ( V_508 ) )
return F_265 ( V_10 ) ;
if ( F_125 ( ( V_10 -> V_1 -> V_2 . V_371 & V_511 ) == 0 ) )
return F_265 ( V_10 ) ;
V_308 = V_10 -> V_1 -> V_2 . V_371 & V_512 ;
V_510 = V_10 -> V_1 -> V_2 . V_407 - V_437 ;
V_96 = 0 ;
if ( V_510 >= 16 ) {
V_510 -= 16 ;
V_97 = F_257 ( & V_10 -> V_9 , V_308 ) ;
switch ( V_510 ) {
case 0 :
if ( ! F_269 ( V_10 , V_97 ) )
V_96 = F_110 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_234 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_271 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_272 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_98 ( 1 , L_12 , V_510 ) ;
F_176 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
} else {
switch ( V_510 ) {
case 0 :
V_97 = F_230 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_419 ;
break;
case 3 :
V_97 = F_138 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_273 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_274 ( & V_10 -> V_9 ) ;
break;
default:
F_98 ( 1 , L_13 , V_510 ) ;
F_176 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
F_113 ( & V_10 -> V_9 , V_308 , V_97 ) ;
}
F_268 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_275 ( struct V_7 * V_10 )
{
int V_308 , V_513 ;
unsigned long V_97 ;
int V_96 ;
if ( V_10 -> V_9 . V_355 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_366 |= V_367 ;
return 1 ;
}
if ( ! F_84 ( V_508 ) )
return F_265 ( V_10 ) ;
V_308 = V_10 -> V_1 -> V_2 . V_371 & V_512 ;
V_513 = V_10 -> V_1 -> V_2 . V_407 - V_439 ;
if ( V_513 >= 16 ) {
V_97 = F_257 ( & V_10 -> V_9 , V_308 ) ;
F_276 ( & V_10 -> V_9 , V_513 - 16 , V_97 ) ;
} else {
V_96 = F_277 ( & V_10 -> V_9 , V_513 , & V_97 ) ;
if ( ! V_96 )
F_113 ( & V_10 -> V_9 , V_308 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_278 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
int V_141 ;
T_4 V_514 = F_274 ( & V_10 -> V_9 ) ;
V_141 = F_270 ( V_10 ) ;
if ( F_279 ( V_10 -> V_9 . V_278 ) )
return V_141 ;
if ( V_514 <= F_274 ( & V_10 -> V_9 ) )
return V_141 ;
V_376 -> V_380 = V_515 ;
return 0 ;
}
static T_2 F_280 ( struct V_8 * V_9 , T_2 V_516 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_200 +
F_96 ( V_9 , V_516 ) ;
}
static int F_281 ( struct V_8 * V_9 , unsigned V_517 , T_2 * V_518 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_517 ) {
case V_519 : {
* V_518 = V_10 -> V_1 -> V_2 . V_200 +
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
case V_159 :
* V_518 = V_10 -> V_1 -> V_58 . V_529 ;
break;
case V_160 :
* V_518 = V_10 -> V_1 -> V_58 . V_530 ;
break;
case V_161 :
* V_518 = V_10 -> V_1 -> V_58 . V_531 ;
break;
case V_162 :
* V_518 = V_10 -> V_1 -> V_58 . V_532 ;
break;
case V_132 :
* V_518 = V_10 -> V_17 . V_533 ;
break;
case V_534 :
* V_518 = V_10 -> V_17 . V_535 ;
break;
case V_536 :
* V_518 = 0x01000065 ;
break;
default:
return F_282 ( V_9 , V_517 , V_518 ) ;
}
return 0 ;
}
static int F_283 ( struct V_7 * V_10 )
{
T_1 V_517 = V_10 -> V_9 . V_39 . V_261 [ V_432 ] ;
T_2 V_518 ;
if ( F_281 ( & V_10 -> V_9 , V_517 , & V_518 ) ) {
F_284 ( V_517 ) ;
F_209 ( & V_10 -> V_9 , 0 ) ;
} else {
F_285 ( V_517 , V_518 ) ;
V_10 -> V_9 . V_39 . V_261 [ V_457 ] = V_518 & 0xffffffff ;
V_10 -> V_9 . V_39 . V_261 [ V_277 ] = V_518 >> 32 ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_286 ( struct V_8 * V_9 , T_2 V_518 )
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
static int F_287 ( struct V_8 * V_9 , struct V_542 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_517 = V_42 -> V_145 ;
T_2 V_518 = V_42 -> V_518 ;
switch ( V_517 ) {
case V_519 :
F_288 ( V_9 , V_42 ) ;
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
F_289 ( V_9 , L_14 ,
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
case V_132 :
V_10 -> V_17 . V_533 = V_518 ;
break;
case V_534 :
return F_286 ( V_9 , V_518 ) ;
case V_546 :
F_289 ( V_9 , L_15 , V_517 , V_518 ) ;
break;
default:
return F_290 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_291 ( struct V_7 * V_10 )
{
struct V_542 V_42 ;
T_1 V_517 = V_10 -> V_9 . V_39 . V_261 [ V_432 ] ;
T_2 V_518 = ( V_10 -> V_9 . V_39 . V_261 [ V_457 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_39 . V_261 [ V_277 ] & - 1u ) << 32 ) ;
V_42 . V_518 = V_518 ;
V_42 . V_145 = V_517 ;
V_42 . V_547 = false ;
V_10 -> V_71 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_292 ( & V_10 -> V_9 , & V_42 ) ) {
F_293 ( V_517 , V_518 ) ;
F_209 ( & V_10 -> V_9 , 0 ) ;
} else {
F_294 ( V_517 , V_518 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_295 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_371 )
return F_291 ( V_10 ) ;
else
return F_283 ( V_10 ) ;
}
static int F_296 ( struct V_7 * V_10 )
{
struct V_376 * V_376 = V_10 -> V_9 . V_377 ;
F_185 ( V_473 , & V_10 -> V_9 ) ;
F_140 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_474 ;
F_3 ( V_10 -> V_1 , V_475 ) ;
++ V_10 -> V_9 . V_301 . V_548 ;
if ( ! F_279 ( V_10 -> V_9 . V_278 ) &&
V_376 -> V_549 &&
! F_297 ( & V_10 -> V_9 ) ) {
V_376 -> V_380 = V_550 ;
return 0 ;
}
return 1 ;
}
static int F_298 ( struct V_7 * V_10 )
{
F_299 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_300 ( struct V_7 * V_10 )
{
F_31 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_301 ( struct V_7 * V_10 )
{
F_302 ( V_551 L_16 ) ;
return F_300 ( V_10 ) ;
}
static int F_303 ( struct V_7 * V_10 )
{
F_302 ( V_551 L_17 ) ;
return F_300 ( V_10 ) ;
}
static void F_304 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_206 * V_58 = & V_10 -> V_1 -> V_58 ;
F_55 ( L_18 ) ;
F_55 ( L_19 , L_20 , V_2 -> V_19 & 0xffff ) ;
F_55 ( L_19 , L_21 , V_2 -> V_19 >> 16 ) ;
F_55 ( L_19 , L_22 , V_2 -> V_20 & 0xffff ) ;
F_55 ( L_19 , L_23 , V_2 -> V_20 >> 16 ) ;
F_55 ( L_24 , L_25 , V_2 -> V_21 ) ;
F_55 ( L_26 , L_27 , V_2 -> V_22 ) ;
F_55 ( L_28 , L_29 , V_2 -> V_273 ) ;
F_55 ( L_26 , L_30 , V_2 -> V_243 ) ;
F_55 ( L_26 , L_31 , V_2 -> V_244 ) ;
F_55 ( L_26 , L_32 , V_2 -> V_200 ) ;
F_55 ( L_28 , L_33 , V_2 -> V_51 ) ;
F_55 ( L_28 , L_34 , V_2 -> V_360 ) ;
F_55 ( L_24 , L_35 , V_2 -> V_245 ) ;
F_55 ( L_24 , L_36 , V_2 -> V_448 ) ;
F_55 ( L_24 , L_37 , V_2 -> V_66 ) ;
F_55 ( L_24 , L_38 , V_2 -> V_407 ) ;
F_55 ( L_26 , L_39 , V_2 -> V_371 ) ;
F_55 ( L_26 , L_40 , V_2 -> V_369 ) ;
F_55 ( L_24 , L_41 , V_2 -> V_449 ) ;
F_55 ( L_24 , L_42 , V_2 -> V_450 ) ;
F_55 ( L_43 , L_44 , V_2 -> V_269 ) ;
F_55 ( L_26 , L_45 , V_2 -> V_401 ) ;
F_55 ( L_24 , L_46 , V_2 -> V_90 ) ;
F_55 ( L_24 , L_47 , V_2 -> V_93 ) ;
F_55 ( L_43 , L_48 , V_2 -> V_158 ) ;
F_55 ( L_26 , L_49 , V_2 -> V_71 ) ;
F_55 ( L_50 ) ;
F_55 ( L_51 ,
L_52 ,
V_58 -> V_247 . V_182 , V_58 -> V_247 . V_183 ,
V_58 -> V_247 . V_187 , V_58 -> V_247 . V_88 ) ;
F_55 ( L_51 ,
L_53 ,
V_58 -> V_87 . V_182 , V_58 -> V_87 . V_183 ,
V_58 -> V_87 . V_187 , V_58 -> V_87 . V_88 ) ;
F_55 ( L_51 ,
L_54 ,
V_58 -> V_248 . V_182 , V_58 -> V_248 . V_183 ,
V_58 -> V_248 . V_187 , V_58 -> V_248 . V_88 ) ;
F_55 ( L_51 ,
L_55 ,
V_58 -> V_249 . V_182 , V_58 -> V_249 . V_183 ,
V_58 -> V_249 . V_187 , V_58 -> V_249 . V_88 ) ;
F_55 ( L_51 ,
L_56 ,
V_58 -> V_250 . V_182 , V_58 -> V_250 . V_183 ,
V_58 -> V_250 . V_187 , V_58 -> V_250 . V_88 ) ;
F_55 ( L_51 ,
L_57 ,
V_58 -> V_251 . V_182 , V_58 -> V_251 . V_183 ,
V_58 -> V_251 . V_187 , V_58 -> V_251 . V_88 ) ;
F_55 ( L_51 ,
L_58 ,
V_58 -> V_254 . V_182 , V_58 -> V_254 . V_183 ,
V_58 -> V_254 . V_187 , V_58 -> V_254 . V_88 ) ;
F_55 ( L_51 ,
L_59 ,
V_58 -> V_256 . V_182 , V_58 -> V_256 . V_183 ,
V_58 -> V_256 . V_187 , V_58 -> V_256 . V_88 ) ;
F_55 ( L_51 ,
L_60 ,
V_58 -> V_255 . V_182 , V_58 -> V_255 . V_183 ,
V_58 -> V_255 . V_187 , V_58 -> V_255 . V_88 ) ;
F_55 ( L_51 ,
L_61 ,
V_58 -> V_258 . V_182 , V_58 -> V_258 . V_183 ,
V_58 -> V_258 . V_187 , V_58 -> V_258 . V_88 ) ;
F_55 ( L_62 ,
V_58 -> V_336 , V_58 -> V_54 ) ;
F_55 ( L_63 ,
L_64 , V_58 -> V_263 , L_65 , V_58 -> V_419 ) ;
F_55 ( L_63 ,
L_66 , V_58 -> V_271 , L_67 , V_58 -> V_267 ) ;
F_55 ( L_63 ,
L_68 , V_58 -> V_260 , L_69 , V_58 -> V_365 ) ;
F_55 ( L_63 ,
L_70 , V_58 -> V_84 , L_71 , V_58 -> V_306 ) ;
F_55 ( L_63 ,
L_72 , V_58 -> V_453 , L_73 , V_58 -> V_454 ) ;
F_55 ( L_63 ,
L_74 , V_58 -> V_465 , L_75 , V_58 -> V_466 ) ;
F_55 ( L_63 ,
L_76 , V_58 -> V_467 , L_77 , V_58 -> V_468 ) ;
F_55 ( L_63 ,
L_78 , V_58 -> V_464 ,
L_79 , V_58 -> V_469 ) ;
F_55 ( L_63 ,
L_80 , V_58 -> V_470 ,
L_81 , V_58 -> V_471 ) ;
F_55 ( L_63 ,
L_82 , V_58 -> V_270 , L_83 , V_58 -> V_528 ) ;
F_55 ( L_63 ,
L_84 , V_58 -> V_529 , L_85 , V_58 -> V_530 ) ;
F_55 ( L_63 ,
L_86 , V_58 -> V_531 ,
L_87 , V_58 -> V_532 ) ;
}
static void F_305 ( struct V_8 * V_9 , T_2 * V_552 , T_2 * V_553 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_552 = V_2 -> V_371 ;
* V_553 = V_2 -> V_369 ;
}
static int F_306 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_376 * V_376 = V_9 -> V_377 ;
T_1 V_407 = V_10 -> V_1 -> V_2 . V_407 ;
if ( ! F_11 ( V_10 , V_211 ) )
V_9 -> V_39 . V_263 = V_10 -> V_1 -> V_58 . V_263 ;
if ( V_55 )
V_9 -> V_39 . V_271 = V_10 -> V_1 -> V_58 . V_271 ;
if ( F_125 ( V_10 -> V_17 . V_421 ) ) {
F_204 ( V_10 ) ;
V_10 -> V_17 . V_421 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_417 ;
F_307 ( V_10 -> V_1 -> V_58 . V_84 , V_407 ,
V_10 -> V_1 -> V_2 . V_371 ,
V_10 -> V_1 -> V_2 . V_369 ,
V_10 -> V_1 -> V_2 . V_449 ,
V_10 -> V_1 -> V_2 . V_450 ,
V_452 ) ;
V_417 = F_225 ( V_10 ) ;
if ( V_417 == V_434 )
V_417 = F_226 ( V_10 ) ;
if ( V_417 == V_420 )
return 1 ;
}
F_308 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_407 == V_442 ) {
V_376 -> V_380 = V_554 ;
V_376 -> V_555 . V_556
= V_10 -> V_1 -> V_2 . V_407 ;
F_55 ( L_88 ) ;
F_304 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_449 ) &&
V_407 != V_418 + V_215 &&
V_407 != V_408 && V_407 != V_557 &&
V_407 != V_424 && V_407 != V_425 )
F_33 ( V_77 L_89
L_90 ,
V_75 , V_10 -> V_1 -> V_2 . V_449 ,
V_407 ) ;
if ( V_407 >= F_309 ( V_558 )
|| ! V_558 [ V_407 ] ) {
F_100 ( 1 , L_91 , V_407 ) ;
F_176 ( V_9 , V_216 ) ;
return 1 ;
}
return V_558 [ V_407 ] ( V_10 ) ;
}
static void F_310 ( struct V_8 * V_9 )
{
int V_140 = F_53 () ;
struct V_113 * V_114 = F_56 ( V_123 , V_140 ) ;
V_114 -> V_129 -> type = 9 ;
F_311 () ;
}
static void F_312 ( struct V_7 * V_10 )
{
int V_140 = F_53 () ;
struct V_113 * V_114 = F_56 ( V_123 , V_140 ) ;
if ( V_10 -> V_124 != V_114 -> V_124 )
F_160 ( V_10 , V_114 ) ;
}
static void F_313 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_559 ;
V_9 -> V_39 . V_40 |= V_560 ;
F_16 ( V_10 , V_505 ) ;
++ V_9 -> V_301 . V_561 ;
}
static inline void F_314 ( struct V_7 * V_10 , int V_562 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_448 = V_562 ;
V_2 -> V_245 &= ~ V_563 ;
V_2 -> V_245 |= V_474 |
( ( 0xf ) << V_564 ) ;
F_3 ( V_10 -> V_1 , V_475 ) ;
}
static void F_315 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_72 ( ! ( F_20 ( V_10 ) ) ) ;
F_316 ( V_9 -> V_39 . V_565 . V_78 ) ;
++ V_9 -> V_301 . V_566 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_565 . V_78 |
V_63 | V_64 ;
}
static void F_317 ( struct V_8 * V_9 , int V_567 , int V_568 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_422 ) )
return;
F_10 ( V_10 , V_214 ) ;
if ( V_568 == - 1 )
return;
if ( V_567 >= V_568 )
F_9 ( V_10 , V_214 ) ;
}
static void F_318 ( struct V_8 * V_9 , bool V_569 )
{
return;
}
static int F_319 ( struct V_278 * V_278 )
{
return 0 ;
}
static void F_320 ( struct V_8 * V_9 , T_2 * V_570 )
{
return;
}
static void F_321 ( struct V_278 * V_278 , int V_571 )
{
return;
}
static void F_322 ( struct V_8 * V_9 )
{
return;
}
static int F_323 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
V_65 = ! ( V_1 -> V_2 . V_66 & V_67 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_560 ) ;
V_65 = V_65 && F_20 ( V_10 ) && F_213 ( V_10 ) ;
return V_65 ;
}
static bool F_324 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_560 ) ;
}
static void F_325 ( struct V_8 * V_9 , bool V_572 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_572 ) {
V_10 -> V_9 . V_39 . V_40 |= V_560 ;
F_16 ( V_10 , V_505 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_560 ;
F_17 ( V_10 , V_505 ) ;
}
}
static int F_326 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_66 & V_67 ) )
return 0 ;
V_65 = ! ! ( F_231 ( V_9 ) & V_461 ) ;
if ( F_7 ( V_9 ) )
return V_65 && ! ( V_10 -> V_9 . V_39 . V_40 & V_422 ) ;
return V_65 ;
}
static void F_327 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_211 ( V_10 ) ) {
F_139 ( V_10 ) ;
F_314 ( V_10 , 0x0 ) ;
}
}
static void F_328 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_560 | V_506 ) )
== V_560 )
return;
V_10 -> V_354 = true ;
V_10 -> V_1 -> V_58 . V_306 |= ( V_378 | V_379 ) ;
F_159 ( V_9 ) ;
}
static int F_329 ( struct V_278 * V_278 , unsigned int V_50 )
{
return 0 ;
}
static void F_157 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_573 ) )
V_10 -> V_1 -> V_2 . V_360 = V_574 ;
else
V_10 -> V_124 -- ;
}
static void F_330 ( struct V_8 * V_9 )
{
}
static inline void F_331 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_422 ) )
return;
if ( ! F_11 ( V_10 , V_214 ) ) {
int V_575 = V_10 -> V_1 -> V_2 . V_245 & V_576 ;
F_272 ( V_9 , V_575 ) ;
}
}
static inline void F_332 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_575 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_422 ) )
return;
V_575 = F_274 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_576 ;
V_10 -> V_1 -> V_2 . V_245 |= V_575 & V_576 ;
}
static void F_308 ( struct V_7 * V_10 )
{
T_4 V_577 ;
int type ;
T_1 V_578 = V_10 -> V_1 -> V_2 . V_449 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_506 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_507 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_560 | V_506 ) ;
F_185 ( V_473 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_492 = false ;
F_232 ( & V_10 -> V_9 ) ;
F_233 ( & V_10 -> V_9 ) ;
if ( ! ( V_578 & V_484 ) )
return;
F_185 ( V_473 , & V_10 -> V_9 ) ;
V_577 = V_578 & V_579 ;
type = V_578 & V_480 ;
switch ( type ) {
case V_491 :
V_10 -> V_9 . V_39 . V_492 = true ;
break;
case V_493 :
if ( F_333 ( V_577 ) ) {
if ( V_577 == V_82 && V_89 &&
F_334 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_578 & V_580 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_450 ;
F_335 ( & V_10 -> V_9 , V_577 , V_96 ) ;
} else
F_336 ( & V_10 -> V_9 , V_577 ) ;
break;
case V_495 :
F_337 ( & V_10 -> V_9 , V_577 , false ) ;
break;
default:
break;
}
}
static void F_338 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_449 = V_2 -> V_90 ;
V_2 -> V_450 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_308 ( V_10 ) ;
}
static void F_339 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_454 = V_9 -> V_39 . V_261 [ V_457 ] ;
V_10 -> V_1 -> V_58 . V_453 = V_9 -> V_39 . V_261 [ V_458 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_261 [ V_262 ] ;
if ( F_125 ( V_10 -> V_17 . V_421 ) )
return;
F_312 ( V_10 ) ;
F_332 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_419 = V_9 -> V_39 . V_419 ;
F_22 () ;
F_173 () ;
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
F_49 ( V_295 , V_10 -> V_204 . V_296 ) ;
#else
F_131 ( V_250 , V_10 -> V_204 . V_250 ) ;
#ifndef F_133
F_131 ( V_251 , V_10 -> V_204 . V_251 ) ;
#endif
#endif
F_310 ( V_9 ) ;
F_171 () ;
V_9 -> V_39 . V_419 = V_10 -> V_1 -> V_58 . V_419 ;
V_9 -> V_39 . V_261 [ V_457 ] = V_10 -> V_1 -> V_58 . V_454 ;
V_9 -> V_39 . V_261 [ V_458 ] = V_10 -> V_1 -> V_58 . V_453 ;
V_9 -> V_39 . V_261 [ V_262 ] = V_10 -> V_1 -> V_58 . V_84 ;
F_340 ( V_10 -> V_1 -> V_2 . V_407 , V_9 , V_452 ) ;
if ( F_125 ( V_10 -> V_1 -> V_2 . V_407 == V_425 ) )
F_341 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_125 ( V_10 -> V_1 -> V_2 . V_407 == V_425 ) )
F_342 ( & V_10 -> V_9 ) ;
F_331 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_360 = V_581 ;
if ( V_10 -> V_1 -> V_2 . V_407 == V_418 + V_215 )
V_10 -> V_370 = F_343 () ;
if ( V_55 ) {
V_9 -> V_39 . V_582 &= ~ ( 1 << V_309 ) ;
V_9 -> V_39 . V_583 &= ~ ( 1 << V_309 ) ;
}
if ( F_125 ( V_10 -> V_1 -> V_2 . V_407 ==
V_418 + V_217 ) )
F_184 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_344 ( struct V_8 * V_9 , unsigned long V_403 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_271 = V_403 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_157 ( V_9 ) ;
}
static void F_345 ( struct V_8 * V_9 , unsigned long V_403 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_401 = V_403 ;
F_3 ( V_10 -> V_1 , V_404 ) ;
V_10 -> V_1 -> V_58 . V_271 = F_138 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_157 ( V_9 ) ;
}
static int F_346 ( void )
{
T_2 V_584 ;
F_54 ( V_534 , V_584 ) ;
if ( V_584 & ( 1 << V_585 ) )
return 1 ;
return 0 ;
}
static void
F_347 ( struct V_8 * V_9 , unsigned char * V_586 )
{
V_586 [ 0 ] = 0x0f ;
V_586 [ 1 ] = 0x01 ;
V_586 [ 2 ] = 0xd9 ;
}
static void F_348 ( void * V_587 )
{
* ( int * ) V_587 = 0 ;
}
static bool F_349 ( void )
{
return false ;
}
static T_2 F_350 ( struct V_8 * V_9 , T_11 V_588 , bool V_589 )
{
return 0 ;
}
static void F_351 ( struct V_8 * V_9 )
{
}
static void F_352 ( T_1 V_590 , struct V_591 * V_592 )
{
switch ( V_590 ) {
case 0x80000001 :
if ( V_17 )
V_592 -> V_517 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_592 -> V_276 = 1 ;
V_592 -> V_593 = 8 ;
V_592 -> V_517 = 0 ;
V_592 -> V_594 = 0 ;
if ( F_84 ( V_83 ) )
V_592 -> V_594 |= V_595 ;
if ( V_55 )
V_592 -> V_594 |= V_596 ;
break;
}
}
static int F_353 ( void )
{
return V_597 ;
}
static bool F_354 ( void )
{
return false ;
}
static bool F_355 ( void )
{
return false ;
}
static bool F_356 ( void )
{
return false ;
}
static bool F_357 ( void )
{
return true ;
}
static void F_358 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_387 ) ;
F_152 ( V_10 ) ;
}
static int F_359 ( struct V_8 * V_9 ,
struct V_598 * V_61 ,
enum V_599 V_600 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_417 , V_65 = V_601 ;
struct V_602 V_603 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_309 ( V_604 ) )
goto V_284;
V_603 = V_604 [ V_61 -> V_22 ] ;
if ( V_600 != V_603 . V_600 )
goto V_284;
switch ( V_603 . V_407 ) {
case V_437 :
if ( V_61 -> V_22 == V_605 )
V_603 . V_407 += V_61 -> V_606 ;
break;
case V_607 : {
unsigned long V_263 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_608 )
V_603 . V_407 += V_61 -> V_606 ;
if ( V_603 . V_407 != V_607 ||
V_61 -> V_22 == V_609 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_221 ) ) )
break;
V_263 = V_9 -> V_39 . V_263 & ~ V_342 ;
V_97 = V_61 -> V_610 & ~ V_342 ;
if ( V_61 -> V_22 == V_611 ) {
V_263 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_263 & V_456 )
V_97 |= V_456 ;
}
if ( V_263 ^ V_97 )
V_603 . V_407 = V_509 ;
break;
}
case V_439 :
case V_612 :
V_603 . V_407 += V_61 -> V_606 ;
break;
case V_435 :
if ( V_61 -> V_22 == V_613 )
V_1 -> V_2 . V_371 = 1 ;
else
V_1 -> V_2 . V_371 = 0 ;
break;
case V_614 :
if ( V_61 -> V_615 != V_616 )
goto V_284;
case V_436 : {
T_2 V_617 ;
T_1 V_618 ;
if ( V_61 -> V_22 == V_619 ||
V_61 -> V_22 == V_620 ) {
V_617 = ( ( V_61 -> V_610 & 0xffff ) << 16 ) |
V_397 ;
V_618 = V_61 -> V_621 ;
} else {
V_617 = ( V_61 -> V_622 & 0xffff ) << 16 ;
V_618 = V_61 -> V_623 ;
}
if ( V_61 -> V_22 == V_624 ||
V_61 -> V_22 == V_620 )
V_617 |= V_396 ;
if ( V_61 -> V_615 )
V_617 |= V_625 ;
V_618 = F_86 ( V_618 , 4u ) ;
V_617 |= V_618 << V_399 ;
V_617 |= ( T_1 ) V_61 -> V_626 << ( V_627 - 1 ) ;
V_1 -> V_2 . V_371 = V_617 ;
V_1 -> V_2 . V_369 = V_61 -> V_71 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_407 = V_603 . V_407 ;
V_417 = F_226 ( V_10 ) ;
V_65 = ( V_417 == V_420 ) ? V_628
: V_601 ;
V_284:
return V_65 ;
}
static void F_360 ( struct V_8 * V_9 )
{
F_173 () ;
}
static void F_361 ( struct V_8 * V_9 , int V_140 )
{
}
static int T_5 F_362 ( void )
{
return F_363 ( & V_629 , sizeof( struct V_7 ) ,
F_364 ( struct V_7 ) , V_630 ) ;
}
static void T_6 F_365 ( void )
{
F_366 () ;
}
