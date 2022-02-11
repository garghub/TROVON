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
F_32 ( ! F_70 ( V_42 ) ) ;
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
F_71 ( V_147 , V_146 [ V_44 ] . V_145 , 1 , 1 ) ;
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
F_71 ( V_147 , V_159 , 1 , 1 ) ;
F_71 ( V_147 , V_160 , 1 , 1 ) ;
F_71 ( V_147 , V_161 , 1 , 1 ) ;
F_71 ( V_147 , V_162 , 1 , 1 ) ;
}
static void F_80 ( struct V_7 * V_10 )
{
T_1 * V_147 = V_10 -> V_147 ;
V_10 -> V_1 -> V_2 . V_158 = 0 ;
F_71 ( V_147 , V_159 , 0 , 0 ) ;
F_71 ( V_147 , V_160 , 0 , 0 ) ;
F_71 ( V_147 , V_161 , 0 , 0 ) ;
F_71 ( V_147 , V_162 , 0 , 0 ) ;
}
static T_4 F_81 ( int V_163 )
{
switch ( V_163 )
{
case V_164 :
return V_165 ;
case V_166 :
return V_167 ;
default:
F_77 () ;
}
}
static void F_82 ( void )
{
int V_44 ;
T_2 V_168 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_169 [ V_44 ] = V_170 ;
V_169 [ 2 ] = 0 ;
V_169 [ 3 ] = 0 ;
F_55 ( V_171 , V_168 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
T_4 V_163 = V_168 >> ( 8 * V_44 ) ;
if ( V_169 [ V_163 ] == V_170 )
V_169 [ V_163 ] = F_83 ( V_44 ) ;
}
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
if ( V_169 [ V_44 ] == V_170 ) {
T_4 V_172 = F_81 ( V_44 ) ;
V_169 [ V_44 ] = V_169 [ V_172 ] ;
F_72 ( V_169 [ V_44 ] == V_170 ) ;
}
}
}
static T_5 int F_84 ( void )
{
int V_140 ;
struct V_173 * V_174 ;
void * V_175 ;
int V_141 ;
V_174 = F_85 ( V_142 , V_176 ) ;
if ( ! V_174 )
return - V_143 ;
V_175 = F_86 ( V_174 ) ;
memset ( V_175 , 0xff , V_153 * ( 1 << V_176 ) ) ;
V_177 = F_60 ( V_174 ) << V_134 ;
F_78 () ;
if ( F_87 ( V_178 ) )
F_88 ( V_179 ) ;
if ( F_87 ( V_180 ) )
F_88 ( V_181 ) ;
if ( F_87 ( V_110 ) ) {
T_2 V_182 ;
V_183 = true ;
V_182 = F_89 ( 0x7fffffffULL , F_90 ( V_184 , V_185 ) ) ;
V_186 = V_182 ;
}
if ( V_17 ) {
F_35 ( V_109 L_6 ) ;
F_88 ( V_59 | V_187 ) ;
}
F_91 (cpu) {
V_141 = F_67 ( V_140 ) ;
if ( V_141 )
goto V_96;
}
if ( ! F_87 ( V_188 ) )
V_55 = false ;
if ( V_55 && ! V_189 ) {
F_35 ( V_109 L_7 ) ;
V_55 = false ;
}
if ( V_55 ) {
F_35 ( V_109 L_8 ) ;
F_92 () ;
} else
F_93 () ;
F_82 () ;
return 0 ;
V_96:
F_94 ( V_174 , V_176 ) ;
V_177 = 0 ;
return V_141 ;
}
static T_6 void F_95 ( void )
{
int V_140 ;
F_91 (cpu)
F_64 ( V_140 ) ;
F_94 ( F_96 ( V_177 >> V_134 ) , V_176 ) ;
V_177 = 0 ;
}
static void F_97 ( struct V_190 * V_191 )
{
V_191 -> V_192 = 0 ;
V_191 -> V_193 = V_194 | V_195 |
V_196 ;
V_191 -> V_197 = 0xffff ;
V_191 -> V_88 = 0 ;
}
static void F_98 ( struct V_190 * V_191 , T_7 type )
{
V_191 -> V_192 = 0 ;
V_191 -> V_193 = V_194 | type ;
V_191 -> V_197 = 0xffff ;
V_191 -> V_88 = 0 ;
}
static T_2 F_90 ( T_2 V_198 , T_2 V_199 )
{
T_2 V_200 , V_201 , V_202 ;
V_200 = V_198 >> 32 ;
V_201 = V_198 & ( ( 1ULL << 32 ) - 1 ) ;
V_202 = V_199 ;
V_202 *= V_200 ;
V_202 += ( V_199 >> 32 ) * V_201 ;
V_202 += ( ( V_199 & ( ( 1ULL << 32 ) - 1 ) ) * V_201 ) >> 32 ;
return V_202 ;
}
static T_2 F_99 ( struct V_8 * V_9 , T_2 V_199 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_202 = V_199 ;
if ( V_10 -> V_203 != V_112 )
V_202 = F_90 ( V_10 -> V_203 , V_199 ) ;
return V_202 ;
}
static void F_100 ( struct V_8 * V_9 , T_1 V_204 , bool V_205 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_198 ;
T_2 V_206 ;
if ( ! V_205 ) {
V_10 -> V_203 = V_112 ;
return;
}
if ( ! F_87 ( V_110 ) ) {
if ( V_204 > V_184 ) {
V_9 -> V_39 . V_207 = 1 ;
V_9 -> V_39 . V_208 = 1 ;
} else
F_101 ( 1 , L_9 ) ;
return;
}
V_206 = V_204 ;
V_198 = V_206 << 32 ;
F_102 ( V_198 , V_184 ) ;
if ( V_198 == 0 || V_198 & V_209 ) {
F_103 ( 1 , L_10 ,
V_204 ) ;
return;
}
V_10 -> V_203 = V_198 ;
}
static T_2 F_104 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_210 ;
}
static void F_105 ( struct V_8 * V_9 , T_2 V_43 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_211 = 0 ;
if ( F_7 ( V_9 ) ) {
V_211 = V_10 -> V_1 -> V_2 . V_210 -
V_10 -> V_17 . V_18 -> V_2 . V_210 ;
V_10 -> V_17 . V_18 -> V_2 . V_210 = V_43 ;
} else
F_106 ( V_9 -> V_212 ,
V_10 -> V_1 -> V_2 . V_210 ,
V_43 ) ;
V_10 -> V_1 -> V_2 . V_210 = V_43 + V_211 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_107 ( struct V_8 * V_9 , T_8 V_213 , bool V_214 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_214 ) {
if ( V_10 -> V_203 != V_112 )
F_32 ( V_213 < 0 ) ;
V_213 = F_99 ( V_9 , ( T_2 ) V_213 ) ;
}
V_10 -> V_1 -> V_2 . V_210 += V_213 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_210 += V_213 ;
else
F_106 ( V_9 -> V_212 ,
V_10 -> V_1 -> V_2 . V_210 - V_213 ,
V_10 -> V_1 -> V_2 . V_210 ) ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_108 ( struct V_8 * V_9 , T_2 V_215 )
{
T_2 V_199 ;
V_199 = F_99 ( V_9 , F_109 () ) ;
return V_215 - V_199 ;
}
static void F_110 ( struct V_7 * V_10 , T_2 * V_216 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
if ( ! F_111 ( V_9 -> V_217 ) )
* V_216 = 0x0606060606060606 ;
else
* V_216 = V_9 -> V_39 . V_168 ;
}
static T_2 F_112 ( struct V_8 * V_9 , T_9 V_218 , bool V_219 )
{
T_4 V_163 ;
if ( ! V_219 && ! F_111 ( V_9 -> V_217 ) )
return 0 ;
V_163 = F_113 ( V_9 , V_218 ) ;
return V_169 [ V_163 ] ;
}
static void F_114 ( struct V_7 * V_10 , bool V_220 )
{
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_221 * V_58 = & V_10 -> V_1 -> V_58 ;
V_10 -> V_9 . V_222 = 1 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
F_9 ( V_10 , V_223 ) ;
F_9 ( V_10 , V_224 ) ;
F_9 ( V_10 , V_225 ) ;
F_9 ( V_10 , V_226 ) ;
F_9 ( V_10 , V_227 ) ;
F_9 ( V_10 , V_228 ) ;
F_9 ( V_10 , V_229 ) ;
F_12 ( V_10 ) ;
F_14 ( V_10 , V_230 ) ;
F_14 ( V_10 , V_231 ) ;
F_14 ( V_10 , V_232 ) ;
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
F_16 ( V_10 , V_244 ) ;
F_16 ( V_10 , V_245 ) ;
F_16 ( V_10 , V_246 ) ;
F_16 ( V_10 , V_247 ) ;
F_16 ( V_10 , V_248 ) ;
F_16 ( V_10 , V_249 ) ;
F_16 ( V_10 , V_250 ) ;
F_16 ( V_10 , V_251 ) ;
F_16 ( V_10 , V_252 ) ;
F_16 ( V_10 , V_253 ) ;
F_16 ( V_10 , V_254 ) ;
F_16 ( V_10 , V_255 ) ;
F_16 ( V_10 , V_256 ) ;
F_16 ( V_10 , V_257 ) ;
V_2 -> V_258 = V_177 ;
V_2 -> V_259 = F_115 ( V_10 -> V_147 ) ;
V_2 -> V_260 = V_261 ;
F_97 ( & V_58 -> V_262 ) ;
F_97 ( & V_58 -> V_263 ) ;
F_97 ( & V_58 -> V_264 ) ;
F_97 ( & V_58 -> V_265 ) ;
F_97 ( & V_58 -> V_266 ) ;
V_58 -> V_87 . V_192 = 0xf000 ;
V_58 -> V_87 . V_88 = 0xffff0000 ;
V_58 -> V_87 . V_193 = V_267 | V_194 |
V_195 | V_268 ;
V_58 -> V_87 . V_197 = 0xffff ;
V_58 -> V_269 . V_197 = 0xffff ;
V_58 -> V_270 . V_197 = 0xffff ;
F_98 ( & V_58 -> V_271 , V_272 ) ;
F_98 ( & V_58 -> V_273 , V_274 ) ;
if ( ! V_220 )
F_27 ( & V_10 -> V_9 , 0 ) ;
V_58 -> V_275 = 0xffff0ff0 ;
F_116 ( & V_10 -> V_9 , 2 ) ;
V_58 -> V_84 = 0x0000fff0 ;
V_10 -> V_9 . V_39 . V_276 [ V_277 ] = V_58 -> V_84 ;
( void ) F_117 ( & V_10 -> V_9 , V_278 | V_279 | V_280 ) ;
V_58 -> V_281 = V_282 ;
if ( V_55 ) {
V_2 -> V_283 = 1 ;
F_17 ( V_10 , V_241 ) ;
F_15 ( V_10 , V_230 ) ;
F_10 ( V_10 , V_224 ) ;
F_10 ( V_10 , V_227 ) ;
V_58 -> V_216 = V_10 -> V_9 . V_39 . V_168 ;
F_110 ( V_10 , & V_58 -> V_216 ) ;
V_58 -> V_284 = 0 ;
V_58 -> V_281 = 0 ;
}
V_10 -> V_124 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_39 . V_40 = 0 ;
if ( F_87 ( V_285 ) ) {
V_2 -> V_286 = 3000 ;
F_16 ( V_10 , V_287 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static void F_118 ( struct V_8 * V_9 , bool V_220 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_288 ;
T_1 V_289 = 1 ;
if ( ! V_220 ) {
V_10 -> V_9 . V_39 . V_290 = V_291 |
V_292 ;
if ( F_119 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_39 . V_290 |= V_293 ;
}
F_114 ( V_10 , V_220 ) ;
F_120 ( V_9 , & V_289 , & V_288 , & V_288 , & V_288 ) ;
F_121 ( V_9 , V_294 , V_289 ) ;
}
static struct V_8 * F_122 ( struct V_217 * V_217 , unsigned int V_295 )
{
struct V_7 * V_10 ;
struct V_173 * V_173 ;
struct V_173 * V_296 ;
struct V_173 * V_297 ;
struct V_173 * V_298 ;
int V_96 ;
V_10 = F_123 ( V_299 , V_142 ) ;
if ( ! V_10 ) {
V_96 = - V_143 ;
goto V_300;
}
V_10 -> V_203 = V_112 ;
V_96 = F_124 ( & V_10 -> V_9 , V_217 , V_295 ) ;
if ( V_96 )
goto V_301;
V_96 = - V_143 ;
V_173 = F_69 ( V_142 ) ;
if ( ! V_173 )
goto V_302;
V_296 = F_85 ( V_142 , V_154 ) ;
if ( ! V_296 )
goto V_303;
V_298 = F_85 ( V_142 , V_154 ) ;
if ( ! V_298 )
goto V_304;
V_297 = F_69 ( V_142 ) ;
if ( ! V_297 )
goto V_305;
V_10 -> V_17 . V_18 = F_86 ( V_297 ) ;
V_10 -> V_147 = F_86 ( V_296 ) ;
F_75 ( V_10 -> V_147 ) ;
V_10 -> V_17 . V_147 = F_86 ( V_298 ) ;
F_75 ( V_10 -> V_17 . V_147 ) ;
V_10 -> V_1 = F_86 ( V_173 ) ;
F_125 ( V_10 -> V_1 ) ;
V_10 -> V_306 = F_60 ( V_173 ) << V_134 ;
V_10 -> V_124 = 0 ;
F_114 ( V_10 , false ) ;
F_46 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_305:
F_94 ( V_298 , V_154 ) ;
V_304:
F_94 ( V_296 , V_154 ) ;
V_303:
F_65 ( V_173 ) ;
V_302:
F_126 ( & V_10 -> V_9 ) ;
V_301:
F_127 ( V_299 , V_10 ) ;
V_300:
return F_128 ( V_96 ) ;
}
static void F_129 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_65 ( F_96 ( V_10 -> V_306 >> V_134 ) ) ;
F_94 ( F_130 ( V_10 -> V_147 ) , V_154 ) ;
F_65 ( F_130 ( V_10 -> V_17 . V_18 ) ) ;
F_94 ( F_130 ( V_10 -> V_17 . V_147 ) , V_154 ) ;
F_126 ( V_9 ) ;
F_127 ( V_299 , V_10 ) ;
}
static void F_131 ( struct V_8 * V_9 , int V_140 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
if ( F_132 ( V_140 != V_9 -> V_140 ) ) {
V_10 -> V_124 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_55 ( V_307 , F_4 ( V_9 ) -> V_214 . V_308 ) ;
#endif
F_133 ( V_265 , V_10 -> V_214 . V_265 ) ;
F_133 ( V_266 , V_10 -> V_214 . V_266 ) ;
V_10 -> V_214 . V_309 = F_134 () ;
for ( V_44 = 0 ; V_44 < V_310 ; V_44 ++ )
F_55 ( V_311 [ V_44 ] , V_10 -> V_312 [ V_44 ] ) ;
if ( F_33 ( V_110 ) &&
V_10 -> V_203 != F_135 ( V_135 ) ) {
F_61 ( V_135 , V_10 -> V_203 ) ;
F_50 ( V_111 , V_10 -> V_203 ) ;
}
}
static void F_136 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_44 ;
++ V_9 -> V_313 . V_314 ;
F_137 ( V_10 -> V_214 . V_309 ) ;
#ifdef F_26
F_138 ( V_265 , V_10 -> V_214 . V_265 ) ;
F_50 ( V_315 , V_316 -> V_317 . V_266 ) ;
F_139 ( V_10 -> V_214 . V_266 ) ;
#else
#ifdef F_140
F_138 ( V_266 , V_10 -> V_214 . V_266 ) ;
#endif
#endif
for ( V_44 = 0 ; V_44 < V_310 ; V_44 ++ )
F_50 ( V_311 [ V_44 ] , V_10 -> V_312 [ V_44 ] ) ;
}
static unsigned long F_141 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_318 ;
}
static void F_142 ( struct V_8 * V_9 , unsigned long V_318 )
{
F_4 ( V_9 ) -> V_1 -> V_58 . V_318 = V_318 ;
}
static void F_143 ( struct V_8 * V_9 , enum V_319 V_320 )
{
switch ( V_320 ) {
case V_321 :
F_72 ( ! V_55 ) ;
F_144 ( V_9 , V_9 -> V_39 . V_322 , F_145 ( V_9 ) ) ;
break;
default:
F_77 () ;
}
}
static void F_146 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_323 ) ;
}
static void F_147 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_323 ) ;
}
static struct V_190 * F_148 ( struct V_8 * V_9 , int V_191 )
{
struct V_221 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
switch ( V_191 ) {
case V_324 : return & V_58 -> V_87 ;
case V_325 : return & V_58 -> V_264 ;
case V_326 : return & V_58 -> V_262 ;
case V_327 : return & V_58 -> V_265 ;
case V_328 : return & V_58 -> V_266 ;
case V_329 : return & V_58 -> V_263 ;
case V_330 : return & V_58 -> V_273 ;
case V_331 : return & V_58 -> V_271 ;
}
F_77 () ;
return NULL ;
}
static T_2 F_149 ( struct V_8 * V_9 , int V_191 )
{
struct V_190 * V_332 = F_148 ( V_9 , V_191 ) ;
return V_332 -> V_88 ;
}
static void F_150 ( struct V_8 * V_9 ,
struct V_333 * V_334 , int V_191 )
{
struct V_190 * V_332 = F_148 ( V_9 , V_191 ) ;
V_334 -> V_88 = V_332 -> V_88 ;
V_334 -> V_197 = V_332 -> V_197 ;
V_334 -> V_192 = V_332 -> V_192 ;
V_334 -> type = V_332 -> V_193 & V_335 ;
V_334 -> V_332 = ( V_332 -> V_193 >> V_336 ) & 1 ;
V_334 -> V_337 = ( V_332 -> V_193 >> V_338 ) & 3 ;
V_334 -> V_339 = ( V_332 -> V_193 >> V_340 ) & 1 ;
V_334 -> V_341 = ( V_332 -> V_193 >> V_342 ) & 1 ;
V_334 -> V_343 = ( V_332 -> V_193 >> V_344 ) & 1 ;
V_334 -> V_345 = ( V_332 -> V_193 >> V_346 ) & 1 ;
V_334 -> V_15 = V_332 -> V_197 > 0xfffff ;
V_334 -> V_347 = ! V_334 -> V_339 || ( V_334 -> type == 0 ) ;
switch ( V_191 ) {
case V_330 :
V_334 -> type |= 0x2 ;
break;
case V_325 :
case V_326 :
case V_327 :
case V_328 :
if ( ! V_334 -> V_347 )
V_334 -> type |= 0x1 ;
break;
case V_329 :
if ( V_334 -> V_347 )
V_334 -> V_345 = 0 ;
V_334 -> V_337 = F_4 ( V_9 ) -> V_1 -> V_58 . V_348 ;
break;
}
}
static int F_151 ( struct V_8 * V_9 )
{
struct V_221 * V_58 = & F_4 ( V_9 ) -> V_1 -> V_58 ;
return V_58 -> V_348 ;
}
static void F_152 ( struct V_8 * V_9 , struct V_115 * V_349 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_349 -> V_350 = V_10 -> V_1 -> V_58 . V_270 . V_197 ;
V_349 -> V_128 = V_10 -> V_1 -> V_58 . V_270 . V_88 ;
}
static void F_153 ( struct V_8 * V_9 , struct V_115 * V_349 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_270 . V_197 = V_349 -> V_350 ;
V_10 -> V_1 -> V_58 . V_270 . V_88 = V_349 -> V_128 ;
F_3 ( V_10 -> V_1 , V_351 ) ;
}
static void F_154 ( struct V_8 * V_9 , struct V_115 * V_349 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_349 -> V_350 = V_10 -> V_1 -> V_58 . V_269 . V_197 ;
V_349 -> V_128 = V_10 -> V_1 -> V_58 . V_269 . V_88 ;
}
static void F_155 ( struct V_8 * V_9 , struct V_115 * V_349 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_269 . V_197 = V_349 -> V_350 ;
V_10 -> V_1 -> V_58 . V_269 . V_88 = V_349 -> V_128 ;
F_3 ( V_10 -> V_1 , V_351 ) ;
}
static void F_156 ( struct V_8 * V_9 )
{
}
static void F_157 ( struct V_8 * V_9 )
{
}
static void F_158 ( struct V_8 * V_9 )
{
}
static void F_159 ( struct V_7 * V_10 )
{
T_10 V_352 = V_10 -> V_9 . V_39 . V_353 ;
T_2 * V_354 = & V_10 -> V_1 -> V_58 . V_353 ;
if ( ! V_10 -> V_9 . V_222 )
* V_354 |= V_355 ;
else
* V_354 = ( * V_354 & ~ V_355 )
| ( V_352 & V_355 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
if ( V_352 == * V_354 && V_10 -> V_9 . V_222 ) {
F_10 ( V_10 , V_223 ) ;
F_10 ( V_10 , V_226 ) ;
} else {
F_9 ( V_10 , V_223 ) ;
F_9 ( V_10 , V_226 ) ;
}
}
static void F_160 ( struct V_8 * V_9 , unsigned long V_353 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_39 . V_54 & V_57 ) {
if ( ! F_161 ( V_9 ) && ( V_353 & V_356 ) ) {
V_9 -> V_39 . V_54 |= V_56 ;
V_10 -> V_1 -> V_58 . V_54 |= V_56 | V_57 ;
}
if ( F_161 ( V_9 ) && ! ( V_353 & V_356 ) ) {
V_9 -> V_39 . V_54 &= ~ V_56 ;
V_10 -> V_1 -> V_58 . V_54 &= ~ ( V_56 | V_57 ) ;
}
}
#endif
V_9 -> V_39 . V_353 = V_353 ;
if ( ! V_55 )
V_353 |= V_356 | V_357 ;
if ( ! V_9 -> V_222 )
V_353 |= V_358 ;
if ( F_162 ( V_9 -> V_217 , V_359 ) )
V_353 &= ~ ( V_279 | V_278 ) ;
V_10 -> V_1 -> V_58 . V_353 = V_353 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_159 ( V_10 ) ;
}
static int F_163 ( struct V_8 * V_9 , unsigned long V_281 )
{
unsigned long V_360 = F_164 () & V_361 ;
unsigned long V_362 = F_4 ( V_9 ) -> V_1 -> V_58 . V_281 ;
if ( V_281 & V_363 )
return 1 ;
if ( V_55 && ( ( V_362 ^ V_281 ) & V_364 ) )
F_165 ( V_9 ) ;
V_9 -> V_39 . V_281 = V_281 ;
if ( ! V_55 )
V_281 |= V_282 ;
V_281 |= V_360 ;
F_4 ( V_9 ) -> V_1 -> V_58 . V_281 = V_281 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_60 ) ;
return 0 ;
}
static void F_166 ( struct V_8 * V_9 ,
struct V_333 * V_334 , int V_191 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_190 * V_332 = F_148 ( V_9 , V_191 ) ;
V_332 -> V_88 = V_334 -> V_88 ;
V_332 -> V_197 = V_334 -> V_197 ;
V_332 -> V_192 = V_334 -> V_192 ;
if ( V_334 -> V_347 )
V_332 -> V_193 = 0 ;
else {
V_332 -> V_193 = ( V_334 -> type & V_335 ) ;
V_332 -> V_193 |= ( V_334 -> V_332 & 1 ) << V_336 ;
V_332 -> V_193 |= ( V_334 -> V_337 & 3 ) << V_338 ;
V_332 -> V_193 |= ( V_334 -> V_339 & 1 ) << V_340 ;
V_332 -> V_193 |= ( V_334 -> V_341 & 1 ) << V_342 ;
V_332 -> V_193 |= ( V_334 -> V_343 & 1 ) << V_344 ;
V_332 -> V_193 |= ( V_334 -> V_345 & 1 ) << V_346 ;
V_332 -> V_193 |= ( V_334 -> V_15 & 1 ) << V_365 ;
}
if ( V_191 == V_329 )
V_10 -> V_1 -> V_58 . V_348 = ( V_332 -> V_193 >> V_338 ) & 3 ;
F_3 ( V_10 -> V_1 , V_366 ) ;
}
static void F_167 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_367 ) ;
F_15 ( V_10 , V_83 ) ;
if ( V_10 -> V_368 )
F_14 ( V_10 , V_367 ) ;
if ( V_9 -> V_369 & V_370 ) {
if ( V_9 -> V_369 &
( V_371 | V_372 ) )
F_14 ( V_10 , V_367 ) ;
if ( V_9 -> V_369 & V_373 )
F_14 ( V_10 , V_83 ) ;
} else
V_9 -> V_369 = 0 ;
}
static void F_168 ( struct V_7 * V_10 , struct V_113 * V_114 )
{
if ( V_114 -> V_127 > V_114 -> V_125 ) {
++ V_114 -> V_124 ;
V_114 -> V_127 = 1 ;
V_10 -> V_1 -> V_2 . V_374 = V_375 ;
}
V_10 -> V_124 = V_114 -> V_124 ;
V_10 -> V_1 -> V_2 . V_51 = V_114 -> V_127 ++ ;
F_3 ( V_10 -> V_1 , V_376 ) ;
}
static T_2 F_169 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_58 . V_275 ;
}
static void F_170 ( struct V_8 * V_9 , unsigned long V_377 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_275 = V_377 ;
F_3 ( V_10 -> V_1 , V_378 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_172 ( V_9 -> V_39 . V_345 [ 0 ] , 0 ) ;
F_172 ( V_9 -> V_39 . V_345 [ 1 ] , 1 ) ;
F_172 ( V_9 -> V_39 . V_345 [ 2 ] , 2 ) ;
F_172 ( V_9 -> V_39 . V_345 [ 3 ] , 3 ) ;
V_9 -> V_39 . V_275 = F_169 ( V_9 ) ;
V_9 -> V_39 . V_379 = V_10 -> V_1 -> V_58 . V_379 ;
V_9 -> V_39 . V_380 &= ~ V_381 ;
F_12 ( V_10 ) ;
}
static void F_173 ( struct V_8 * V_9 , unsigned long V_377 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_379 = V_377 ;
F_3 ( V_10 -> V_1 , V_378 ) ;
}
static int F_174 ( struct V_7 * V_10 )
{
T_2 V_382 = V_10 -> V_1 -> V_2 . V_383 ;
T_1 V_81 ;
int V_141 = 1 ;
switch ( V_10 -> V_384 ) {
default:
V_81 = V_10 -> V_1 -> V_2 . V_385 ;
F_175 ( V_382 , V_81 ) ;
if ( ! V_55 && F_176 ( & V_10 -> V_9 ) )
F_177 ( & V_10 -> V_9 , V_382 ) ;
V_141 = F_178 ( & V_10 -> V_9 , V_382 , V_81 ,
V_10 -> V_1 -> V_2 . V_386 ,
V_10 -> V_1 -> V_2 . V_387 ) ;
break;
case V_388 :
V_10 -> V_384 = 0 ;
F_179 () ;
F_180 ( V_382 ) ;
F_181 () ;
break;
case V_389 :
V_10 -> V_384 = 0 ;
F_179 () ;
F_182 ( V_382 ) ;
F_181 () ;
break;
}
return V_141 ;
}
static int F_183 ( struct V_7 * V_10 )
{
struct V_390 * V_390 = V_10 -> V_9 . V_391 ;
if ( ! ( V_10 -> V_9 . V_369 &
( V_371 | V_372 ) ) &&
! V_10 -> V_368 ) {
F_184 ( & V_10 -> V_9 , V_367 ) ;
return 1 ;
}
if ( V_10 -> V_368 ) {
V_10 -> V_368 = false ;
if ( ! ( V_10 -> V_9 . V_369 & V_371 ) )
V_10 -> V_1 -> V_58 . V_318 &=
~ ( V_392 | V_393 ) ;
F_167 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_369 &
( V_371 | V_372 ) ) {
V_390 -> V_394 = V_395 ;
V_390 -> V_396 . V_39 . V_397 =
V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_390 -> V_396 . V_39 . V_398 = V_367 ;
return 0 ;
}
return 1 ;
}
static int F_185 ( struct V_7 * V_10 )
{
struct V_390 * V_390 = V_10 -> V_9 . V_391 ;
V_390 -> V_394 = V_395 ;
V_390 -> V_396 . V_39 . V_397 = V_10 -> V_1 -> V_58 . V_87 . V_88 + V_10 -> V_1 -> V_58 . V_84 ;
V_390 -> V_396 . V_39 . V_398 = V_83 ;
return 0 ;
}
static int F_186 ( struct V_7 * V_10 )
{
int V_399 ;
V_399 = F_34 ( & V_10 -> V_9 , V_400 ) ;
if ( V_399 != V_74 )
F_184 ( & V_10 -> V_9 , V_231 ) ;
return 1 ;
}
static void F_187 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_401 ) ;
V_10 -> V_9 . V_222 = 1 ;
F_159 ( V_10 ) ;
}
static int F_188 ( struct V_7 * V_10 )
{
F_187 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_189 ( void )
{
int V_96 , V_44 ;
T_2 V_377 ;
if ( ! V_100 )
return false ;
V_377 = F_42 ( V_402 , & V_96 ) ;
if ( V_96 )
return false ;
V_377 &= ~ ( 1ULL << 62 ) ;
if ( V_377 != 0xb600000000010015ULL )
return false ;
for ( V_44 = 0 ; V_44 < 6 ; ++ V_44 )
F_45 ( F_190 ( V_44 ) , 0 , 0 ) ;
V_377 = F_42 ( V_403 , & V_96 ) ;
if ( ! V_96 ) {
T_1 V_94 , V_95 ;
V_377 &= ~ ( 1ULL << 2 ) ;
V_94 = F_43 ( V_377 ) ;
V_95 = F_44 ( V_377 ) ;
F_45 ( V_403 , V_94 , V_95 ) ;
}
F_191 () ;
return true ;
}
static void F_192 ( struct V_7 * V_10 )
{
if ( F_189 () ) {
F_56 ( L_11 ) ;
F_193 ( V_404 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_194 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_195 ( struct V_7 * V_10 )
{
struct V_390 * V_390 = V_10 -> V_9 . V_391 ;
F_125 ( V_10 -> V_1 ) ;
F_114 ( V_10 , false ) ;
V_390 -> V_394 = V_405 ;
return 0 ;
}
static int F_196 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_406 = V_10 -> V_1 -> V_2 . V_385 ;
int V_350 , V_407 , string ;
unsigned V_408 ;
++ V_10 -> V_9 . V_313 . V_409 ;
string = ( V_406 & V_410 ) != 0 ;
V_407 = ( V_406 & V_411 ) != 0 ;
if ( string || V_407 )
return F_34 ( V_9 , 0 ) == V_74 ;
V_408 = V_406 >> 16 ;
V_350 = ( V_406 & V_412 ) >> V_413 ;
V_10 -> V_71 = V_10 -> V_1 -> V_2 . V_383 ;
F_31 ( & V_10 -> V_9 ) ;
return F_197 ( V_9 , V_350 , V_408 ) ;
}
static int F_198 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_199 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_313 . V_414 ;
return 1 ;
}
static int F_200 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_201 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 1 ;
return F_202 ( & V_10 -> V_9 ) ;
}
static int F_203 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_204 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_205 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_415 ;
}
static T_2 F_206 ( struct V_8 * V_9 , int V_145 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_284 = V_10 -> V_17 . V_415 ;
T_2 V_416 ;
int V_65 ;
V_65 = F_207 ( V_9 , F_208 ( V_284 ) , & V_416 ,
F_209 ( V_284 ) + V_145 * 8 , 8 ) ;
if ( V_65 )
return 0 ;
return V_416 ;
}
static void F_210 ( struct V_8 * V_9 ,
unsigned long V_417 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_415 = V_417 ;
F_3 ( V_10 -> V_1 , V_418 ) ;
F_165 ( V_9 ) ;
}
static void F_211 ( struct V_8 * V_9 ,
struct V_419 * V_420 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_421 != V_422 ) {
V_10 -> V_1 -> V_2 . V_421 = V_422 ;
V_10 -> V_1 -> V_2 . V_423 = 0 ;
V_10 -> V_1 -> V_2 . V_385 = ( 1ULL << 32 ) ;
V_10 -> V_1 -> V_2 . V_383 = V_420 -> V_128 ;
}
V_10 -> V_1 -> V_2 . V_385 &= ~ 0xffffffffULL ;
V_10 -> V_1 -> V_2 . V_385 |= V_420 -> V_81 ;
if ( V_10 -> V_1 -> V_2 . V_385 & ( 2ULL << 32 ) )
V_10 -> V_1 -> V_2 . V_385 &= ~ 1 ;
F_212 ( V_10 ) ;
}
static void F_213 ( struct V_8 * V_9 )
{
F_32 ( F_214 ( V_9 ) ) ;
F_215 ( V_9 ) ;
V_9 -> V_39 . V_424 . V_425 = F_210 ;
V_9 -> V_39 . V_424 . V_426 = F_205 ;
V_9 -> V_39 . V_424 . V_427 = F_206 ;
V_9 -> V_39 . V_424 . V_428 = F_211 ;
V_9 -> V_39 . V_424 . V_429 = F_25 () ;
V_9 -> V_39 . V_322 = & V_9 -> V_39 . V_430 ;
}
static void F_216 ( struct V_8 * V_9 )
{
V_9 -> V_39 . V_322 = & V_9 -> V_39 . V_424 ;
}
static int F_217 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_39 . V_54 & V_59 )
|| ! F_161 ( & V_10 -> V_9 ) ) {
F_184 ( & V_10 -> V_9 , V_231 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_58 . V_348 ) {
F_218 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_7 * V_10 , unsigned V_79 ,
bool V_80 , T_1 V_81 )
{
int V_431 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_421 = V_432 + V_79 ;
V_10 -> V_1 -> V_2 . V_423 = 0 ;
V_10 -> V_1 -> V_2 . V_385 = V_81 ;
V_10 -> V_1 -> V_2 . V_383 = V_10 -> V_9 . V_39 . V_433 ;
V_431 = F_219 ( V_10 ) ;
if ( V_431 == V_434 )
V_10 -> V_17 . V_435 = true ;
return V_431 ;
}
static inline bool F_220 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_436 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_437 ) )
return false ;
if ( V_10 -> V_17 . V_435 )
return false ;
V_10 -> V_1 -> V_2 . V_421 = V_438 ;
V_10 -> V_1 -> V_2 . V_385 = 0 ;
V_10 -> V_1 -> V_2 . V_383 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_435 = true ;
F_221 ( V_10 -> V_1 -> V_58 . V_84 ) ;
return false ;
}
return true ;
}
static inline bool F_222 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_234 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_421 = V_439 ;
V_10 -> V_17 . V_435 = true ;
return false ;
}
static void * F_223 ( struct V_7 * V_10 , T_2 V_440 , struct V_173 * * V_441 )
{
struct V_173 * V_173 ;
F_224 () ;
V_173 = F_225 ( & V_10 -> V_9 , V_440 >> V_134 ) ;
if ( F_226 ( V_173 ) )
goto error;
* V_441 = V_173 ;
return F_227 ( V_173 ) ;
error:
F_218 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_228 ( struct V_173 * V_173 )
{
F_229 ( V_173 ) ;
F_230 ( V_173 ) ;
}
static int F_231 ( struct V_7 * V_10 )
{
unsigned V_408 , V_350 , V_442 ;
T_11 V_97 , V_70 ;
T_4 V_443 ;
T_2 V_440 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_243 ) ) )
return V_444 ;
V_408 = V_10 -> V_1 -> V_2 . V_385 >> 16 ;
V_350 = ( V_10 -> V_1 -> V_2 . V_385 & V_412 ) >>
V_413 ;
V_440 = V_10 -> V_17 . V_445 + ( V_408 / 8 ) ;
V_443 = V_408 % 8 ;
V_442 = ( V_443 + V_350 > 8 ) ? 2 : 1 ;
V_70 = ( 0xf >> ( 4 - V_350 ) ) << V_443 ;
V_97 = 0 ;
if ( F_232 ( & V_10 -> V_9 , V_440 , & V_97 , V_442 ) )
return V_434 ;
return ( V_97 & V_70 ) ? V_434 : V_444 ;
}
static int F_233 ( struct V_7 * V_10 )
{
T_1 V_43 , V_42 , V_377 ;
int V_149 , V_70 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_244 ) ) )
return V_444 ;
V_42 = V_10 -> V_9 . V_39 . V_276 [ V_446 ] ;
V_43 = F_21 ( V_42 ) ;
V_149 = V_10 -> V_1 -> V_2 . V_385 & 1 ;
V_70 = 1 << ( ( 2 * ( V_42 & 0xf ) ) + V_149 ) ;
if ( V_43 == V_49 )
return V_434 ;
V_43 *= 4 ;
if ( F_232 ( & V_10 -> V_9 , V_10 -> V_17 . V_447 + V_43 , & V_377 , 4 ) )
return V_434 ;
return ( V_377 & V_70 ) ? V_434 : V_444 ;
}
static int F_234 ( struct V_7 * V_10 )
{
T_1 V_421 = V_10 -> V_1 -> V_2 . V_421 ;
switch ( V_421 ) {
case V_438 :
case V_439 :
case V_432 + V_232 :
return V_444 ;
case V_422 :
if ( V_55 )
return V_444 ;
break;
case V_432 + V_230 :
if ( ! V_55 && V_10 -> V_384 == 0 )
return V_444 ;
break;
case V_432 + V_401 :
F_188 ( V_10 ) ;
break;
default:
break;
}
return V_448 ;
}
static int F_219 ( struct V_7 * V_10 )
{
T_1 V_421 = V_10 -> V_1 -> V_2 . V_421 ;
int V_431 = V_444 ;
switch ( V_421 ) {
case V_449 :
V_431 = F_233 ( V_10 ) ;
break;
case V_450 :
V_431 = F_231 ( V_10 ) ;
break;
case V_451 ... V_452 : {
T_1 V_6 = 1U << ( V_421 - V_451 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_431 = V_434 ;
break;
}
case V_453 ... V_454 : {
T_1 V_6 = 1U << ( V_421 - V_453 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_431 = V_434 ;
break;
}
case V_432 ... V_432 + 0x1f : {
T_1 V_455 = 1 << ( V_421 - V_432 ) ;
if ( V_10 -> V_17 . V_21 & V_455 )
V_431 = V_434 ;
else if ( ( V_421 == V_432 + V_230 ) &&
V_10 -> V_384 != 0 )
V_431 = V_434 ;
break;
}
case V_456 : {
V_431 = V_434 ;
break;
}
default: {
T_2 V_457 = 1ULL << ( V_421 - V_438 ) ;
if ( V_10 -> V_17 . V_22 & V_457 )
V_431 = V_434 ;
}
}
return V_431 ;
}
static int F_235 ( struct V_7 * V_10 )
{
int V_431 ;
V_431 = F_219 ( V_10 ) ;
if ( V_431 == V_434 )
F_212 ( V_10 ) ;
return V_431 ;
}
static inline void F_236 ( struct V_1 * V_458 , struct V_1 * V_459 )
{
struct V_11 * V_460 = & V_458 -> V_2 ;
struct V_11 * V_461 = & V_459 -> V_2 ;
V_460 -> V_19 = V_461 -> V_19 ;
V_460 -> V_20 = V_461 -> V_20 ;
V_460 -> V_21 = V_461 -> V_21 ;
V_460 -> V_22 = V_461 -> V_22 ;
V_460 -> V_258 = V_461 -> V_258 ;
V_460 -> V_259 = V_461 -> V_259 ;
V_460 -> V_210 = V_461 -> V_210 ;
V_460 -> V_51 = V_461 -> V_51 ;
V_460 -> V_374 = V_461 -> V_374 ;
V_460 -> V_260 = V_461 -> V_260 ;
V_460 -> V_462 = V_461 -> V_462 ;
V_460 -> V_66 = V_461 -> V_66 ;
V_460 -> V_421 = V_461 -> V_421 ;
V_460 -> V_423 = V_461 -> V_423 ;
V_460 -> V_385 = V_461 -> V_385 ;
V_460 -> V_383 = V_461 -> V_383 ;
V_460 -> V_463 = V_461 -> V_463 ;
V_460 -> V_464 = V_461 -> V_464 ;
V_460 -> V_283 = V_461 -> V_283 ;
V_460 -> V_90 = V_461 -> V_90 ;
V_460 -> V_93 = V_461 -> V_93 ;
V_460 -> V_415 = V_461 -> V_415 ;
V_460 -> V_158 = V_461 -> V_158 ;
}
static int F_212 ( struct V_7 * V_10 )
{
struct V_1 * V_465 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_173 * V_173 ;
F_237 ( V_1 -> V_2 . V_421 ,
V_1 -> V_2 . V_385 ,
V_1 -> V_2 . V_383 ,
V_1 -> V_2 . V_463 ,
V_1 -> V_2 . V_464 ,
V_466 ) ;
V_465 = F_223 ( V_10 , V_10 -> V_17 . V_1 , & V_173 ) ;
if ( ! V_465 )
return 1 ;
F_238 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_465 -> V_58 . V_262 = V_1 -> V_58 . V_262 ;
V_465 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_465 -> V_58 . V_263 = V_1 -> V_58 . V_263 ;
V_465 -> V_58 . V_264 = V_1 -> V_58 . V_264 ;
V_465 -> V_58 . V_269 = V_1 -> V_58 . V_269 ;
V_465 -> V_58 . V_270 = V_1 -> V_58 . V_270 ;
V_465 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_465 -> V_58 . V_353 = F_239 ( & V_10 -> V_9 ) ;
V_465 -> V_58 . V_284 = F_145 ( & V_10 -> V_9 ) ;
V_465 -> V_58 . V_433 = V_1 -> V_58 . V_433 ;
V_465 -> V_58 . V_281 = V_10 -> V_9 . V_39 . V_281 ;
V_465 -> V_58 . V_318 = F_240 ( & V_10 -> V_9 ) ;
V_465 -> V_58 . V_84 = V_1 -> V_58 . V_84 ;
V_465 -> V_58 . V_467 = V_1 -> V_58 . V_467 ;
V_465 -> V_58 . V_468 = V_1 -> V_58 . V_468 ;
V_465 -> V_58 . V_379 = V_1 -> V_58 . V_379 ;
V_465 -> V_58 . V_275 = V_1 -> V_58 . V_275 ;
V_465 -> V_58 . V_348 = V_1 -> V_58 . V_348 ;
V_465 -> V_2 . V_260 = V_1 -> V_2 . V_260 ;
V_465 -> V_2 . V_462 = V_1 -> V_2 . V_462 ;
V_465 -> V_2 . V_66 = V_1 -> V_2 . V_66 ;
V_465 -> V_2 . V_421 = V_1 -> V_2 . V_421 ;
V_465 -> V_2 . V_423 = V_1 -> V_2 . V_423 ;
V_465 -> V_2 . V_385 = V_1 -> V_2 . V_385 ;
V_465 -> V_2 . V_383 = V_1 -> V_2 . V_383 ;
V_465 -> V_2 . V_463 = V_1 -> V_2 . V_463 ;
V_465 -> V_2 . V_464 = V_1 -> V_2 . V_464 ;
V_465 -> V_2 . V_71 = V_1 -> V_2 . V_71 ;
if ( V_1 -> V_2 . V_90 & V_63 ) {
struct V_11 * V_469 = & V_465 -> V_2 ;
V_469 -> V_463 = V_1 -> V_2 . V_90 ;
V_469 -> V_464 = V_1 -> V_2 . V_93 ;
}
V_465 -> V_2 . V_374 = 0 ;
V_465 -> V_2 . V_90 = 0 ;
V_465 -> V_2 . V_93 = 0 ;
if ( ! ( V_10 -> V_9 . V_39 . V_40 & V_436 ) )
V_465 -> V_2 . V_260 &= ~ V_261 ;
F_236 ( V_1 , V_18 ) ;
F_241 ( & V_10 -> V_9 ) ;
F_242 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_415 = 0 ;
V_10 -> V_1 -> V_58 . V_262 = V_18 -> V_58 . V_262 ;
V_10 -> V_1 -> V_58 . V_87 = V_18 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_263 = V_18 -> V_58 . V_263 ;
V_10 -> V_1 -> V_58 . V_264 = V_18 -> V_58 . V_264 ;
V_10 -> V_1 -> V_58 . V_269 = V_18 -> V_58 . V_269 ;
V_10 -> V_1 -> V_58 . V_270 = V_18 -> V_58 . V_270 ;
F_116 ( & V_10 -> V_9 , V_18 -> V_58 . V_318 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_58 . V_54 ) ;
F_160 ( & V_10 -> V_9 , V_18 -> V_58 . V_353 | V_470 ) ;
F_163 ( & V_10 -> V_9 , V_18 -> V_58 . V_281 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_284 = V_18 -> V_58 . V_284 ;
V_10 -> V_9 . V_39 . V_284 = V_18 -> V_58 . V_284 ;
} else {
( void ) F_243 ( & V_10 -> V_9 , V_18 -> V_58 . V_284 ) ;
}
F_121 ( & V_10 -> V_9 , V_471 , V_18 -> V_58 . V_468 ) ;
F_121 ( & V_10 -> V_9 , V_472 , V_18 -> V_58 . V_467 ) ;
F_121 ( & V_10 -> V_9 , V_277 , V_18 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_379 = 0 ;
V_10 -> V_1 -> V_58 . V_348 = 0 ;
V_10 -> V_1 -> V_2 . V_463 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_228 ( V_173 ) ;
F_216 ( & V_10 -> V_9 ) ;
F_244 ( & V_10 -> V_9 ) ;
F_245 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_246 ( struct V_7 * V_10 )
{
int V_44 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_244 ) ) )
return true ;
for ( V_44 = 0 ; V_44 < V_156 ; V_44 ++ ) {
T_1 V_377 , V_473 ;
T_2 V_43 ;
if ( V_157 [ V_44 ] == 0xffffffff )
break;
V_473 = V_157 [ V_44 ] ;
V_43 = V_10 -> V_17 . V_447 + ( V_473 * 4 ) ;
if ( F_232 ( & V_10 -> V_9 , V_43 , & V_377 , 4 ) )
return false ;
V_10 -> V_17 . V_147 [ V_473 ] = V_10 -> V_147 [ V_473 ] | V_377 ;
}
V_10 -> V_1 -> V_2 . V_259 = F_115 ( V_10 -> V_17 . V_147 ) ;
return true ;
}
static bool F_247 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_247 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_51 == 0 )
return false ;
if ( V_1 -> V_2 . V_283 && ! V_55 )
return false ;
return true ;
}
static bool F_248 ( struct V_7 * V_10 )
{
struct V_1 * V_465 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_173 * V_173 ;
T_2 V_474 ;
V_474 = V_10 -> V_1 -> V_58 . V_468 ;
V_465 = F_223 ( V_10 , V_10 -> V_1 -> V_58 . V_468 , & V_173 ) ;
if ( ! V_465 )
return false ;
if ( ! F_247 ( V_465 ) ) {
V_465 -> V_2 . V_421 = V_456 ;
V_465 -> V_2 . V_423 = 0 ;
V_465 -> V_2 . V_385 = 0 ;
V_465 -> V_2 . V_383 = 0 ;
F_228 ( V_173 ) ;
return false ;
}
F_249 ( V_10 -> V_1 -> V_58 . V_84 , V_474 ,
V_465 -> V_58 . V_84 ,
V_465 -> V_2 . V_260 ,
V_465 -> V_2 . V_90 ,
V_465 -> V_2 . V_283 ) ;
F_250 ( V_465 -> V_2 . V_19 & 0xffff ,
V_465 -> V_2 . V_19 >> 16 ,
V_465 -> V_2 . V_21 ,
V_465 -> V_2 . V_22 ) ;
F_241 ( & V_10 -> V_9 ) ;
F_242 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_262 = V_1 -> V_58 . V_262 ;
V_18 -> V_58 . V_87 = V_1 -> V_58 . V_87 ;
V_18 -> V_58 . V_263 = V_1 -> V_58 . V_263 ;
V_18 -> V_58 . V_264 = V_1 -> V_58 . V_264 ;
V_18 -> V_58 . V_269 = V_1 -> V_58 . V_269 ;
V_18 -> V_58 . V_270 = V_1 -> V_58 . V_270 ;
V_18 -> V_58 . V_54 = V_10 -> V_9 . V_39 . V_54 ;
V_18 -> V_58 . V_353 = F_239 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_281 = V_10 -> V_9 . V_39 . V_281 ;
V_18 -> V_58 . V_318 = F_240 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_84 = F_36 ( & V_10 -> V_9 ) ;
V_18 -> V_58 . V_467 = V_1 -> V_58 . V_467 ;
V_18 -> V_58 . V_468 = V_1 -> V_58 . V_468 ;
if ( V_55 )
V_18 -> V_58 . V_284 = V_1 -> V_58 . V_284 ;
else
V_18 -> V_58 . V_284 = F_145 ( & V_10 -> V_9 ) ;
F_236 ( V_18 , V_1 ) ;
if ( F_240 ( & V_10 -> V_9 ) & V_475 )
V_10 -> V_9 . V_39 . V_40 |= V_437 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_437 ;
if ( V_465 -> V_2 . V_283 ) {
F_251 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_415 = V_465 -> V_2 . V_415 ;
F_213 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_58 . V_262 = V_465 -> V_58 . V_262 ;
V_10 -> V_1 -> V_58 . V_87 = V_465 -> V_58 . V_87 ;
V_10 -> V_1 -> V_58 . V_263 = V_465 -> V_58 . V_263 ;
V_10 -> V_1 -> V_58 . V_264 = V_465 -> V_58 . V_264 ;
V_10 -> V_1 -> V_58 . V_269 = V_465 -> V_58 . V_269 ;
V_10 -> V_1 -> V_58 . V_270 = V_465 -> V_58 . V_270 ;
F_116 ( & V_10 -> V_9 , V_465 -> V_58 . V_318 ) ;
F_27 ( & V_10 -> V_9 , V_465 -> V_58 . V_54 ) ;
F_160 ( & V_10 -> V_9 , V_465 -> V_58 . V_353 ) ;
F_163 ( & V_10 -> V_9 , V_465 -> V_58 . V_281 ) ;
if ( V_55 ) {
V_10 -> V_1 -> V_58 . V_284 = V_465 -> V_58 . V_284 ;
V_10 -> V_9 . V_39 . V_284 = V_465 -> V_58 . V_284 ;
} else
( void ) F_243 ( & V_10 -> V_9 , V_465 -> V_58 . V_284 ) ;
F_244 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_58 . V_433 = V_10 -> V_9 . V_39 . V_433 = V_465 -> V_58 . V_433 ;
F_121 ( & V_10 -> V_9 , V_471 , V_465 -> V_58 . V_468 ) ;
F_121 ( & V_10 -> V_9 , V_472 , V_465 -> V_58 . V_467 ) ;
F_121 ( & V_10 -> V_9 , V_277 , V_465 -> V_58 . V_84 ) ;
V_10 -> V_1 -> V_58 . V_468 = V_465 -> V_58 . V_468 ;
V_10 -> V_1 -> V_58 . V_467 = V_465 -> V_58 . V_467 ;
V_10 -> V_1 -> V_58 . V_84 = V_465 -> V_58 . V_84 ;
V_10 -> V_1 -> V_58 . V_379 = V_465 -> V_58 . V_379 ;
V_10 -> V_1 -> V_58 . V_275 = V_465 -> V_58 . V_275 ;
V_10 -> V_1 -> V_58 . V_348 = V_465 -> V_58 . V_348 ;
V_10 -> V_17 . V_447 = V_465 -> V_2 . V_259 & ~ 0x0fffULL ;
V_10 -> V_17 . V_445 = V_465 -> V_2 . V_258 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_465 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_465 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_465 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_465 -> V_2 . V_22 ;
F_165 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_260 = V_465 -> V_2 . V_260 | V_261 ;
if ( V_465 -> V_2 . V_260 & V_261 )
V_10 -> V_9 . V_39 . V_40 |= V_436 ;
else
V_10 -> V_9 . V_39 . V_40 &= ~ V_436 ;
if ( V_10 -> V_9 . V_39 . V_40 & V_436 ) {
F_10 ( V_10 , V_476 ) ;
F_10 ( V_10 , V_229 ) ;
}
F_17 ( V_10 , V_248 ) ;
V_10 -> V_1 -> V_2 . V_158 = V_465 -> V_2 . V_158 ;
V_10 -> V_1 -> V_2 . V_462 = V_465 -> V_2 . V_462 ;
V_10 -> V_1 -> V_2 . V_66 = V_465 -> V_2 . V_66 ;
V_10 -> V_1 -> V_2 . V_210 += V_465 -> V_2 . V_210 ;
V_10 -> V_1 -> V_2 . V_90 = V_465 -> V_2 . V_90 ;
V_10 -> V_1 -> V_2 . V_93 = V_465 -> V_2 . V_93 ;
F_228 ( V_173 ) ;
F_252 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_474 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_253 ( struct V_1 * V_459 , struct V_1 * V_477 )
{
V_477 -> V_58 . V_265 = V_459 -> V_58 . V_265 ;
V_477 -> V_58 . V_266 = V_459 -> V_58 . V_266 ;
V_477 -> V_58 . V_273 = V_459 -> V_58 . V_273 ;
V_477 -> V_58 . V_271 = V_459 -> V_58 . V_271 ;
V_477 -> V_58 . V_478 = V_459 -> V_58 . V_478 ;
V_477 -> V_58 . V_479 = V_459 -> V_58 . V_479 ;
V_477 -> V_58 . V_480 = V_459 -> V_58 . V_480 ;
V_477 -> V_58 . V_481 = V_459 -> V_58 . V_481 ;
V_477 -> V_58 . V_482 = V_459 -> V_58 . V_482 ;
V_477 -> V_58 . V_483 = V_459 -> V_58 . V_483 ;
V_477 -> V_58 . V_484 = V_459 -> V_58 . V_484 ;
V_477 -> V_58 . V_485 = V_459 -> V_58 . V_485 ;
}
static int F_254 ( struct V_7 * V_10 )
{
struct V_1 * V_465 ;
struct V_173 * V_173 ;
if ( F_217 ( V_10 ) )
return 1 ;
V_465 = F_223 ( V_10 , V_10 -> V_1 -> V_58 . V_468 , & V_173 ) ;
if ( ! V_465 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_253 ( V_465 , V_10 -> V_1 ) ;
F_228 ( V_173 ) ;
return 1 ;
}
static int F_255 ( struct V_7 * V_10 )
{
struct V_1 * V_465 ;
struct V_173 * V_173 ;
if ( F_217 ( V_10 ) )
return 1 ;
V_465 = F_223 ( V_10 , V_10 -> V_1 -> V_58 . V_468 , & V_173 ) ;
if ( ! V_465 )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_253 ( V_10 -> V_1 , V_465 ) ;
F_228 ( V_173 ) ;
return 1 ;
}
static int F_256 ( struct V_7 * V_10 )
{
if ( F_217 ( V_10 ) )
return 1 ;
F_37 ( & V_10 -> V_9 , F_36 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_248 ( V_10 ) )
return 1 ;
if ( ! F_246 ( V_10 ) )
goto V_486;
return 1 ;
V_486:
V_10 -> V_1 -> V_2 . V_421 = V_456 ;
V_10 -> V_1 -> V_2 . V_423 = 0 ;
V_10 -> V_1 -> V_2 . V_385 = 0 ;
V_10 -> V_1 -> V_2 . V_383 = 0 ;
F_212 ( V_10 ) ;
return 1 ;
}
static int F_257 ( struct V_7 * V_10 )
{
if ( F_217 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_193 ( V_487 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_258 ( struct V_7 * V_10 )
{
if ( F_217 ( V_10 ) )
return 1 ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_147 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_260 &= ~ V_488 ;
F_3 ( V_10 -> V_1 , V_489 ) ;
return 1 ;
}
static int F_259 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_260 ( V_10 -> V_1 -> V_58 . V_84 , F_261 ( & V_10 -> V_9 , V_446 ) ,
F_261 ( & V_10 -> V_9 , V_471 ) ) ;
F_262 ( V_9 , F_261 ( & V_10 -> V_9 , V_471 ) ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
F_264 ( V_10 -> V_1 -> V_58 . V_84 , F_261 ( & V_10 -> V_9 , V_471 ) ) ;
F_184 ( & V_10 -> V_9 , V_231 ) ;
return 1 ;
}
static int F_265 ( struct V_7 * V_10 )
{
F_266 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_267 ( struct V_7 * V_10 )
{
T_2 V_490 = F_268 ( & V_10 -> V_9 ) ;
T_1 V_145 = F_261 ( & V_10 -> V_9 , V_446 ) ;
if ( F_269 ( & V_10 -> V_9 , V_145 , V_490 ) == 0 ) {
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_270 ( struct V_7 * V_10 )
{
T_11 V_491 ;
int V_492 ;
int V_493 = V_10 -> V_1 -> V_2 . V_463 &
V_494 ;
int V_495 = V_10 -> V_1 -> V_2 . V_463 & V_496 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_463 & V_494 ;
T_7 V_497 =
V_10 -> V_1 -> V_2 . V_463 & V_498 ;
bool V_80 = false ;
T_1 V_81 = 0 ;
V_491 = ( T_11 ) V_10 -> V_1 -> V_2 . V_385 ;
if ( V_10 -> V_1 -> V_2 . V_383 &
( 1ULL << V_499 ) )
V_492 = V_500 ;
else if ( V_10 -> V_1 -> V_2 . V_383 &
( 1ULL << V_501 ) )
V_492 = V_502 ;
else if ( V_497 )
V_492 = V_503 ;
else
V_492 = V_504 ;
if ( V_492 == V_503 ) {
switch ( type ) {
case V_505 :
V_10 -> V_9 . V_39 . V_506 = false ;
break;
case V_507 :
if ( V_10 -> V_1 -> V_2 . V_383 &
( 1ULL << V_508 ) ) {
V_80 = true ;
V_81 =
( T_1 ) V_10 -> V_1 -> V_2 . V_383 ;
}
F_241 ( & V_10 -> V_9 ) ;
break;
case V_509 :
F_242 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_492 != V_503 ||
V_493 == V_510 ||
( V_493 == V_507 &&
( V_495 == V_511 || V_495 == V_83 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_493 != V_510 )
V_495 = - 1 ;
if ( F_271 ( & V_10 -> V_9 , V_491 , V_495 , V_492 ,
V_80 , V_81 ) == V_512 ) {
V_10 -> V_9 . V_391 -> V_394 = V_513 ;
V_10 -> V_9 . V_391 -> V_514 . V_515 = V_516 ;
V_10 -> V_9 . V_391 -> V_514 . V_517 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_272 ( struct V_7 * V_10 )
{
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_273 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_274 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_313 . V_518 ;
F_17 ( V_10 , V_519 ) ;
V_10 -> V_9 . V_39 . V_40 |= V_520 ;
V_10 -> V_521 = F_36 ( & V_10 -> V_9 ) ;
F_193 ( V_487 , & V_10 -> V_9 ) ;
return 1 ;
}
static int F_275 ( struct V_7 * V_10 )
{
if ( ! F_33 ( V_522 ) )
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
F_262 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_385 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_276 ( struct V_7 * V_10 )
{
return F_34 ( & V_10 -> V_9 , 0 ) == V_74 ;
}
static int F_277 ( struct V_7 * V_10 )
{
int V_96 ;
if ( ! F_33 ( V_72 ) )
return F_276 ( V_10 ) ;
V_96 = F_278 ( & V_10 -> V_9 ) ;
F_279 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static bool F_280 ( struct V_7 * V_10 ,
unsigned long V_97 )
{
unsigned long V_353 = V_10 -> V_9 . V_39 . V_353 ;
bool V_65 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_236 ) ) ) )
return false ;
V_353 &= ~ V_355 ;
V_97 &= ~ V_355 ;
if ( V_353 ^ V_97 ) {
V_10 -> V_1 -> V_2 . V_421 = V_523 ;
V_65 = ( F_235 ( V_10 ) == V_434 ) ;
}
return V_65 ;
}
static int F_281 ( struct V_7 * V_10 )
{
int V_320 , V_524 ;
unsigned long V_97 ;
int V_96 ;
if ( ! F_33 ( V_522 ) )
return F_276 ( V_10 ) ;
if ( F_132 ( ( V_10 -> V_1 -> V_2 . V_385 & V_525 ) == 0 ) )
return F_276 ( V_10 ) ;
V_320 = V_10 -> V_1 -> V_2 . V_385 & V_526 ;
if ( V_10 -> V_1 -> V_2 . V_421 == V_523 )
V_524 = V_527 - V_451 ;
else
V_524 = V_10 -> V_1 -> V_2 . V_421 - V_451 ;
V_96 = 0 ;
if ( V_524 >= 16 ) {
V_524 -= 16 ;
V_97 = F_261 ( & V_10 -> V_9 , V_320 ) ;
switch ( V_524 ) {
case 0 :
if ( ! F_280 ( V_10 , V_97 ) )
V_96 = F_117 ( & V_10 -> V_9 , V_97 ) ;
else
return 1 ;
break;
case 3 :
V_96 = F_243 ( & V_10 -> V_9 , V_97 ) ;
break;
case 4 :
V_96 = F_282 ( & V_10 -> V_9 , V_97 ) ;
break;
case 8 :
V_96 = F_283 ( & V_10 -> V_9 , V_97 ) ;
break;
default:
F_101 ( 1 , L_12 , V_524 ) ;
F_184 ( & V_10 -> V_9 , V_231 ) ;
return 1 ;
}
} else {
switch ( V_524 ) {
case 0 :
V_97 = F_239 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_97 = V_10 -> V_9 . V_39 . V_433 ;
break;
case 3 :
V_97 = F_145 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_97 = F_284 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_97 = F_285 ( & V_10 -> V_9 ) ;
break;
default:
F_101 ( 1 , L_13 , V_524 ) ;
F_184 ( & V_10 -> V_9 , V_231 ) ;
return 1 ;
}
F_121 ( & V_10 -> V_9 , V_320 , V_97 ) ;
}
F_279 ( & V_10 -> V_9 , V_96 ) ;
return 1 ;
}
static int F_286 ( struct V_7 * V_10 )
{
int V_320 , V_528 ;
unsigned long V_97 ;
if ( V_10 -> V_9 . V_369 == 0 ) {
F_13 ( V_10 ) ;
V_10 -> V_9 . V_39 . V_380 |= V_381 ;
return 1 ;
}
if ( ! F_87 ( V_522 ) )
return F_276 ( V_10 ) ;
V_320 = V_10 -> V_1 -> V_2 . V_385 & V_526 ;
V_528 = V_10 -> V_1 -> V_2 . V_421 - V_453 ;
if ( V_528 >= 16 ) {
if ( ! F_287 ( & V_10 -> V_9 , V_528 - 16 ) )
return 1 ;
V_97 = F_261 ( & V_10 -> V_9 , V_320 ) ;
F_288 ( & V_10 -> V_9 , V_528 - 16 , V_97 ) ;
} else {
if ( ! F_287 ( & V_10 -> V_9 , V_528 ) )
return 1 ;
F_289 ( & V_10 -> V_9 , V_528 , & V_97 ) ;
F_121 ( & V_10 -> V_9 , V_320 , V_97 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_290 ( struct V_7 * V_10 )
{
struct V_390 * V_390 = V_10 -> V_9 . V_391 ;
int V_141 ;
T_4 V_529 = F_285 ( & V_10 -> V_9 ) ;
V_141 = F_281 ( V_10 ) ;
if ( F_291 ( V_10 -> V_9 . V_217 ) )
return V_141 ;
if ( V_529 <= F_285 ( & V_10 -> V_9 ) )
return V_141 ;
V_390 -> V_394 = V_530 ;
return 0 ;
}
static T_2 F_292 ( struct V_8 * V_9 , T_2 V_531 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_210 +
F_99 ( V_9 , V_531 ) ;
}
static int F_293 ( struct V_8 * V_9 , struct V_532 * V_533 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_533 -> V_145 ) {
case V_534 : {
V_533 -> V_535 = V_10 -> V_1 -> V_2 . V_210 +
F_99 ( V_9 , F_109 () ) ;
break;
}
case V_536 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_479 ;
break;
#ifdef F_26
case V_537 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_480 ;
break;
case V_538 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_481 ;
break;
case V_315 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_478 ;
break;
case V_539 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_482 ;
break;
#endif
case V_540 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_483 ;
break;
case V_541 :
V_533 -> V_535 = V_10 -> V_485 ;
break;
case V_542 :
V_533 -> V_535 = V_10 -> V_484 ;
break;
case V_543 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_544 ;
break;
case V_159 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_545 ;
break;
case V_160 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_546 ;
break;
case V_161 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_547 ;
break;
case V_162 :
V_533 -> V_535 = V_10 -> V_1 -> V_58 . V_548 ;
break;
case V_132 :
V_533 -> V_535 = V_10 -> V_17 . V_549 ;
break;
case V_550 :
V_533 -> V_535 = V_10 -> V_17 . V_551 ;
break;
case V_552 :
V_533 -> V_535 = 0x01000065 ;
break;
default:
return F_294 ( V_9 , V_533 ) ;
}
return 0 ;
}
static int F_295 ( struct V_7 * V_10 )
{
T_1 V_553 = F_261 ( & V_10 -> V_9 , V_446 ) ;
struct V_532 V_533 ;
V_533 . V_145 = V_553 ;
V_533 . V_554 = false ;
if ( F_293 ( & V_10 -> V_9 , & V_533 ) ) {
F_296 ( V_553 ) ;
F_218 ( & V_10 -> V_9 , 0 ) ;
} else {
F_297 ( V_553 , V_533 . V_535 ) ;
F_121 ( & V_10 -> V_9 , V_471 ,
V_533 . V_535 & 0xffffffff ) ;
F_121 ( & V_10 -> V_9 , V_294 ,
V_533 . V_535 >> 32 ) ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_298 ( struct V_8 * V_9 , T_2 V_535 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_555 , V_556 ;
if ( V_535 & ~ V_557 )
return 1 ;
V_556 = V_557 ;
if ( V_10 -> V_17 . V_551 & V_558 )
V_556 &= ~ ( V_559 | V_558 ) ;
V_10 -> V_17 . V_551 &= ~ V_556 ;
V_10 -> V_17 . V_551 |= ( V_535 & V_556 ) ;
V_555 = V_10 -> V_17 . V_551 & V_558 ;
if ( V_555 && ( V_9 -> V_39 . V_54 & V_59 ) )
return 1 ;
return 0 ;
}
static int F_299 ( struct V_8 * V_9 , struct V_532 * V_42 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_553 = V_42 -> V_145 ;
T_2 V_535 = V_42 -> V_535 ;
switch ( V_553 ) {
case V_534 :
F_300 ( V_9 , V_42 ) ;
break;
case V_536 :
V_10 -> V_1 -> V_58 . V_479 = V_535 ;
break;
#ifdef F_26
case V_537 :
V_10 -> V_1 -> V_58 . V_480 = V_535 ;
break;
case V_538 :
V_10 -> V_1 -> V_58 . V_481 = V_535 ;
break;
case V_315 :
V_10 -> V_1 -> V_58 . V_478 = V_535 ;
break;
case V_539 :
V_10 -> V_1 -> V_58 . V_482 = V_535 ;
break;
#endif
case V_540 :
V_10 -> V_1 -> V_58 . V_483 = V_535 ;
break;
case V_541 :
V_10 -> V_485 = V_535 ;
V_10 -> V_1 -> V_58 . V_485 = V_535 ;
break;
case V_542 :
V_10 -> V_484 = V_535 ;
V_10 -> V_1 -> V_58 . V_484 = V_535 ;
break;
case V_543 :
if ( ! F_87 ( V_560 ) ) {
F_301 ( V_9 , L_14 ,
V_76 , V_535 ) ;
break;
}
if ( V_535 & V_561 )
return 1 ;
V_10 -> V_1 -> V_58 . V_544 = V_535 ;
F_3 ( V_10 -> V_1 , V_562 ) ;
if ( V_535 & ( 1ULL << 0 ) )
F_79 ( V_10 ) ;
else
F_80 ( V_10 ) ;
break;
case V_132 :
V_10 -> V_17 . V_549 = V_535 ;
break;
case V_550 :
return F_298 ( V_9 , V_535 ) ;
case V_563 :
F_301 ( V_9 , L_15 , V_553 , V_535 ) ;
break;
case V_171 :
if ( V_55 ) {
if ( ! F_302 ( V_9 , V_171 , V_535 ) )
return 1 ;
V_9 -> V_39 . V_168 = V_535 ;
F_110 ( V_10 , & V_10 -> V_1 -> V_58 . V_216 ) ;
F_3 ( V_10 -> V_1 , V_418 ) ;
break;
}
default:
return F_303 ( V_9 , V_42 ) ;
}
return 0 ;
}
static int F_304 ( struct V_7 * V_10 )
{
struct V_532 V_42 ;
T_1 V_553 = F_261 ( & V_10 -> V_9 , V_446 ) ;
T_2 V_535 = F_268 ( & V_10 -> V_9 ) ;
V_42 . V_535 = V_535 ;
V_42 . V_145 = V_553 ;
V_42 . V_554 = false ;
V_10 -> V_71 = F_36 ( & V_10 -> V_9 ) + 2 ;
if ( F_305 ( & V_10 -> V_9 , & V_42 ) ) {
F_306 ( V_553 , V_535 ) ;
F_218 ( & V_10 -> V_9 , 0 ) ;
} else {
F_307 ( V_553 , V_535 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_308 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_385 )
return F_304 ( V_10 ) ;
else
return F_295 ( V_10 ) ;
}
static int F_309 ( struct V_7 * V_10 )
{
struct V_390 * V_390 = V_10 -> V_9 . V_391 ;
F_193 ( V_487 , & V_10 -> V_9 ) ;
F_147 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_260 &= ~ V_488 ;
F_3 ( V_10 -> V_1 , V_489 ) ;
++ V_10 -> V_9 . V_313 . V_564 ;
if ( ! F_291 ( V_10 -> V_9 . V_217 ) &&
V_390 -> V_565 &&
! F_310 ( & V_10 -> V_9 ) ) {
V_390 -> V_394 = V_566 ;
return 0 ;
}
return 1 ;
}
static int F_311 ( struct V_7 * V_10 )
{
F_312 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_313 ( struct V_7 * V_10 )
{
F_31 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static int F_314 ( struct V_7 * V_10 )
{
F_315 ( V_567 L_16 ) ;
return F_313 ( V_10 ) ;
}
static int F_316 ( struct V_7 * V_10 )
{
F_315 ( V_567 L_17 ) ;
return F_313 ( V_10 ) ;
}
static void F_317 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_221 * V_58 = & V_10 -> V_1 -> V_58 ;
F_56 ( L_18 ) ;
F_56 ( L_19 , L_20 , V_2 -> V_19 & 0xffff ) ;
F_56 ( L_19 , L_21 , V_2 -> V_19 >> 16 ) ;
F_56 ( L_19 , L_22 , V_2 -> V_20 & 0xffff ) ;
F_56 ( L_19 , L_23 , V_2 -> V_20 >> 16 ) ;
F_56 ( L_24 , L_25 , V_2 -> V_21 ) ;
F_56 ( L_26 , L_27 , V_2 -> V_22 ) ;
F_56 ( L_28 , L_29 , V_2 -> V_286 ) ;
F_56 ( L_26 , L_30 , V_2 -> V_258 ) ;
F_56 ( L_26 , L_31 , V_2 -> V_259 ) ;
F_56 ( L_26 , L_32 , V_2 -> V_210 ) ;
F_56 ( L_28 , L_33 , V_2 -> V_51 ) ;
F_56 ( L_28 , L_34 , V_2 -> V_374 ) ;
F_56 ( L_24 , L_35 , V_2 -> V_260 ) ;
F_56 ( L_24 , L_36 , V_2 -> V_462 ) ;
F_56 ( L_24 , L_37 , V_2 -> V_66 ) ;
F_56 ( L_24 , L_38 , V_2 -> V_421 ) ;
F_56 ( L_26 , L_39 , V_2 -> V_385 ) ;
F_56 ( L_26 , L_40 , V_2 -> V_383 ) ;
F_56 ( L_24 , L_41 , V_2 -> V_463 ) ;
F_56 ( L_24 , L_42 , V_2 -> V_464 ) ;
F_56 ( L_43 , L_44 , V_2 -> V_283 ) ;
F_56 ( L_26 , L_45 , V_2 -> V_415 ) ;
F_56 ( L_24 , L_46 , V_2 -> V_90 ) ;
F_56 ( L_24 , L_47 , V_2 -> V_93 ) ;
F_56 ( L_43 , L_48 , V_2 -> V_158 ) ;
F_56 ( L_26 , L_49 , V_2 -> V_71 ) ;
F_56 ( L_50 ) ;
F_56 ( L_51 ,
L_52 ,
V_58 -> V_262 . V_192 , V_58 -> V_262 . V_193 ,
V_58 -> V_262 . V_197 , V_58 -> V_262 . V_88 ) ;
F_56 ( L_51 ,
L_53 ,
V_58 -> V_87 . V_192 , V_58 -> V_87 . V_193 ,
V_58 -> V_87 . V_197 , V_58 -> V_87 . V_88 ) ;
F_56 ( L_51 ,
L_54 ,
V_58 -> V_263 . V_192 , V_58 -> V_263 . V_193 ,
V_58 -> V_263 . V_197 , V_58 -> V_263 . V_88 ) ;
F_56 ( L_51 ,
L_55 ,
V_58 -> V_264 . V_192 , V_58 -> V_264 . V_193 ,
V_58 -> V_264 . V_197 , V_58 -> V_264 . V_88 ) ;
F_56 ( L_51 ,
L_56 ,
V_58 -> V_265 . V_192 , V_58 -> V_265 . V_193 ,
V_58 -> V_265 . V_197 , V_58 -> V_265 . V_88 ) ;
F_56 ( L_51 ,
L_57 ,
V_58 -> V_266 . V_192 , V_58 -> V_266 . V_193 ,
V_58 -> V_266 . V_197 , V_58 -> V_266 . V_88 ) ;
F_56 ( L_51 ,
L_58 ,
V_58 -> V_269 . V_192 , V_58 -> V_269 . V_193 ,
V_58 -> V_269 . V_197 , V_58 -> V_269 . V_88 ) ;
F_56 ( L_51 ,
L_59 ,
V_58 -> V_271 . V_192 , V_58 -> V_271 . V_193 ,
V_58 -> V_271 . V_197 , V_58 -> V_271 . V_88 ) ;
F_56 ( L_51 ,
L_60 ,
V_58 -> V_270 . V_192 , V_58 -> V_270 . V_193 ,
V_58 -> V_270 . V_197 , V_58 -> V_270 . V_88 ) ;
F_56 ( L_51 ,
L_61 ,
V_58 -> V_273 . V_192 , V_58 -> V_273 . V_193 ,
V_58 -> V_273 . V_197 , V_58 -> V_273 . V_88 ) ;
F_56 ( L_62 ,
V_58 -> V_348 , V_58 -> V_54 ) ;
F_56 ( L_63 ,
L_64 , V_58 -> V_353 , L_65 , V_58 -> V_433 ) ;
F_56 ( L_63 ,
L_66 , V_58 -> V_284 , L_67 , V_58 -> V_281 ) ;
F_56 ( L_63 ,
L_68 , V_58 -> V_275 , L_69 , V_58 -> V_379 ) ;
F_56 ( L_63 ,
L_70 , V_58 -> V_84 , L_71 , V_58 -> V_318 ) ;
F_56 ( L_63 ,
L_72 , V_58 -> V_467 , L_73 , V_58 -> V_468 ) ;
F_56 ( L_63 ,
L_74 , V_58 -> V_479 , L_75 , V_58 -> V_480 ) ;
F_56 ( L_63 ,
L_76 , V_58 -> V_481 , L_77 , V_58 -> V_482 ) ;
F_56 ( L_63 ,
L_78 , V_58 -> V_478 ,
L_79 , V_58 -> V_483 ) ;
F_56 ( L_63 ,
L_80 , V_58 -> V_484 ,
L_81 , V_58 -> V_485 ) ;
F_56 ( L_63 ,
L_82 , V_58 -> V_216 , L_83 , V_58 -> V_544 ) ;
F_56 ( L_63 ,
L_84 , V_58 -> V_545 , L_85 , V_58 -> V_546 ) ;
F_56 ( L_63 ,
L_86 , V_58 -> V_547 ,
L_87 , V_58 -> V_548 ) ;
}
static void F_318 ( struct V_8 * V_9 , T_2 * V_568 , T_2 * V_569 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_568 = V_2 -> V_385 ;
* V_569 = V_2 -> V_383 ;
}
static int F_319 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_390 * V_390 = V_9 -> V_391 ;
T_1 V_421 = V_10 -> V_1 -> V_2 . V_421 ;
if ( ! F_11 ( V_10 , V_226 ) )
V_9 -> V_39 . V_353 = V_10 -> V_1 -> V_58 . V_353 ;
if ( V_55 )
V_9 -> V_39 . V_284 = V_10 -> V_1 -> V_58 . V_284 ;
if ( F_132 ( V_10 -> V_17 . V_435 ) ) {
F_212 ( V_10 ) ;
V_10 -> V_17 . V_435 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_431 ;
F_320 ( V_10 -> V_1 -> V_58 . V_84 , V_421 ,
V_10 -> V_1 -> V_2 . V_385 ,
V_10 -> V_1 -> V_2 . V_383 ,
V_10 -> V_1 -> V_2 . V_463 ,
V_10 -> V_1 -> V_2 . V_464 ,
V_466 ) ;
V_431 = F_234 ( V_10 ) ;
if ( V_431 == V_448 )
V_431 = F_235 ( V_10 ) ;
if ( V_431 == V_434 )
return 1 ;
}
F_321 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_421 == V_456 ) {
V_390 -> V_394 = V_570 ;
V_390 -> V_571 . V_572
= V_10 -> V_1 -> V_2 . V_421 ;
F_56 ( L_88 ) ;
F_317 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_463 ) &&
V_421 != V_432 + V_230 &&
V_421 != V_422 && V_421 != V_573 &&
V_421 != V_438 && V_421 != V_439 )
F_35 ( V_78 L_89
L_90 ,
V_76 , V_10 -> V_1 -> V_2 . V_463 ,
V_421 ) ;
if ( V_421 >= F_322 ( V_574 )
|| ! V_574 [ V_421 ] ) {
F_103 ( 1 , L_91 , V_421 ) ;
F_184 ( V_9 , V_231 ) ;
return 1 ;
}
return V_574 [ V_421 ] ( V_10 ) ;
}
static void F_323 ( struct V_8 * V_9 )
{
int V_140 = F_54 () ;
struct V_113 * V_114 = F_57 ( V_123 , V_140 ) ;
V_114 -> V_129 -> type = 9 ;
F_324 () ;
}
static void F_325 ( struct V_7 * V_10 )
{
int V_140 = F_54 () ;
struct V_113 * V_114 = F_57 ( V_123 , V_140 ) ;
if ( V_10 -> V_124 != V_114 -> V_124 )
F_168 ( V_10 , V_114 ) ;
}
static void F_326 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_90 = V_63 | V_575 ;
V_9 -> V_39 . V_40 |= V_576 ;
F_16 ( V_10 , V_519 ) ;
++ V_9 -> V_313 . V_577 ;
}
static inline void F_327 ( struct V_7 * V_10 , int V_578 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_462 = V_578 ;
V_2 -> V_260 &= ~ V_579 ;
V_2 -> V_260 |= V_488 |
( ( 0xf ) << V_580 ) ;
F_3 ( V_10 -> V_1 , V_489 ) ;
}
static void F_328 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_72 ( ! ( F_20 ( V_10 ) ) ) ;
F_329 ( V_9 -> V_39 . V_581 . V_79 ) ;
++ V_9 -> V_313 . V_582 ;
V_10 -> V_1 -> V_2 . V_90 = V_9 -> V_39 . V_581 . V_79 |
V_63 | V_64 ;
}
static void F_330 ( struct V_8 * V_9 , int V_583 , int V_584 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_436 ) )
return;
F_10 ( V_10 , V_229 ) ;
if ( V_584 == - 1 )
return;
if ( V_583 >= V_584 )
F_9 ( V_10 , V_229 ) ;
}
static void F_331 ( struct V_8 * V_9 , bool V_585 )
{
return;
}
static int F_332 ( struct V_217 * V_217 )
{
return 0 ;
}
static void F_333 ( struct V_8 * V_9 , T_2 * V_586 )
{
return;
}
static void F_334 ( struct V_8 * V_9 )
{
return;
}
static int F_335 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
V_65 = ! ( V_1 -> V_2 . V_66 & V_67 ) &&
! ( V_10 -> V_9 . V_39 . V_40 & V_576 ) ;
V_65 = V_65 && F_20 ( V_10 ) && F_222 ( V_10 ) ;
return V_65 ;
}
static bool F_336 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_39 . V_40 & V_576 ) ;
}
static void F_337 ( struct V_8 * V_9 , bool V_587 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_587 ) {
V_10 -> V_9 . V_39 . V_40 |= V_576 ;
F_16 ( V_10 , V_519 ) ;
} else {
V_10 -> V_9 . V_39 . V_40 &= ~ V_576 ;
F_17 ( V_10 , V_519 ) ;
}
}
static int F_338 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_65 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_66 & V_67 ) )
return 0 ;
V_65 = ! ! ( F_240 ( V_9 ) & V_475 ) ;
if ( F_7 ( V_9 ) )
return V_65 && ! ( V_10 -> V_9 . V_39 . V_40 & V_436 ) ;
return V_65 ;
}
static void F_339 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_220 ( V_10 ) ) {
F_146 ( V_10 ) ;
F_327 ( V_10 , 0x0 ) ;
}
}
static void F_340 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_39 . V_40 & ( V_576 | V_520 ) )
== V_576 )
return;
V_10 -> V_368 = true ;
V_10 -> V_1 -> V_58 . V_318 |= ( V_392 | V_393 ) ;
F_167 ( V_9 ) ;
}
static int F_341 ( struct V_217 * V_217 , unsigned int V_50 )
{
return 0 ;
}
static void F_165 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_33 ( V_588 ) )
V_10 -> V_1 -> V_2 . V_374 = V_589 ;
else
V_10 -> V_124 -- ;
}
static void F_342 ( struct V_8 * V_9 )
{
}
static inline void F_343 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_436 ) )
return;
if ( ! F_11 ( V_10 , V_229 ) ) {
int V_590 = V_10 -> V_1 -> V_2 . V_260 & V_591 ;
F_283 ( V_9 , V_590 ) ;
}
}
static inline void F_344 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_590 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_39 . V_40 & V_436 ) )
return;
V_590 = F_285 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_260 &= ~ V_591 ;
V_10 -> V_1 -> V_2 . V_260 |= V_590 & V_591 ;
}
static void F_321 ( struct V_7 * V_10 )
{
T_4 V_592 ;
int type ;
T_1 V_593 = V_10 -> V_1 -> V_2 . V_463 ;
unsigned V_89 = V_10 -> V_89 ;
V_10 -> V_89 = 0 ;
if ( ( V_10 -> V_9 . V_39 . V_40 & V_520 )
&& F_36 ( & V_10 -> V_9 ) != V_10 -> V_521 ) {
V_10 -> V_9 . V_39 . V_40 &= ~ ( V_576 | V_520 ) ;
F_193 ( V_487 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_39 . V_506 = false ;
F_241 ( & V_10 -> V_9 ) ;
F_242 ( & V_10 -> V_9 ) ;
if ( ! ( V_593 & V_498 ) )
return;
F_193 ( V_487 , & V_10 -> V_9 ) ;
V_592 = V_593 & V_594 ;
type = V_593 & V_494 ;
switch ( type ) {
case V_505 :
V_10 -> V_9 . V_39 . V_506 = true ;
break;
case V_507 :
if ( F_345 ( V_592 ) ) {
if ( V_592 == V_83 && V_89 &&
F_346 ( & V_10 -> V_9 , V_10 -> V_86 ) )
F_37 ( & V_10 -> V_9 ,
F_36 ( & V_10 -> V_9 ) -
V_89 ) ;
break;
}
if ( V_593 & V_595 ) {
T_1 V_96 = V_10 -> V_1 -> V_2 . V_464 ;
F_347 ( & V_10 -> V_9 , V_592 , V_96 ) ;
} else
F_348 ( & V_10 -> V_9 , V_592 ) ;
break;
case V_509 :
F_349 ( & V_10 -> V_9 , V_592 , false ) ;
break;
default:
break;
}
}
static void F_350 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_463 = V_2 -> V_90 ;
V_2 -> V_464 = V_2 -> V_93 ;
V_2 -> V_90 = 0 ;
F_321 ( V_10 ) ;
}
static void F_351 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_468 = V_9 -> V_39 . V_276 [ V_471 ] ;
V_10 -> V_1 -> V_58 . V_467 = V_9 -> V_39 . V_276 [ V_472 ] ;
V_10 -> V_1 -> V_58 . V_84 = V_9 -> V_39 . V_276 [ V_277 ] ;
if ( F_132 ( V_10 -> V_17 . V_435 ) )
return;
F_325 ( V_10 ) ;
F_344 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_433 = V_9 -> V_39 . V_433 ;
F_22 () ;
F_181 () ;
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
F_50 ( V_307 , V_10 -> V_214 . V_308 ) ;
#else
F_138 ( V_265 , V_10 -> V_214 . V_265 ) ;
#ifndef F_140
F_138 ( V_266 , V_10 -> V_214 . V_266 ) ;
#endif
#endif
F_323 ( V_9 ) ;
F_179 () ;
V_9 -> V_39 . V_433 = V_10 -> V_1 -> V_58 . V_433 ;
V_9 -> V_39 . V_276 [ V_471 ] = V_10 -> V_1 -> V_58 . V_468 ;
V_9 -> V_39 . V_276 [ V_472 ] = V_10 -> V_1 -> V_58 . V_467 ;
V_9 -> V_39 . V_276 [ V_277 ] = V_10 -> V_1 -> V_58 . V_84 ;
F_352 ( V_10 -> V_1 -> V_2 . V_421 , V_9 , V_466 ) ;
if ( F_132 ( V_10 -> V_1 -> V_2 . V_421 == V_439 ) )
F_353 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_132 ( V_10 -> V_1 -> V_2 . V_421 == V_439 ) )
F_354 ( & V_10 -> V_9 ) ;
F_343 ( V_9 ) ;
V_10 -> V_71 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = V_596 ;
if ( V_10 -> V_1 -> V_2 . V_421 == V_432 + V_230 )
V_10 -> V_384 = F_355 () ;
if ( V_55 ) {
V_9 -> V_39 . V_597 &= ~ ( 1 << V_321 ) ;
V_9 -> V_39 . V_598 &= ~ ( 1 << V_321 ) ;
}
if ( F_132 ( V_10 -> V_1 -> V_2 . V_421 ==
V_432 + V_232 ) )
F_192 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_356 ( struct V_8 * V_9 , unsigned long V_417 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_58 . V_284 = V_417 ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_165 ( V_9 ) ;
}
static void F_357 ( struct V_8 * V_9 , unsigned long V_417 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_415 = V_417 ;
F_3 ( V_10 -> V_1 , V_418 ) ;
V_10 -> V_1 -> V_58 . V_284 = F_145 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_60 ) ;
F_165 ( V_9 ) ;
}
static int F_358 ( void )
{
T_2 V_599 ;
F_55 ( V_550 , V_599 ) ;
if ( V_599 & ( 1 << V_600 ) )
return 1 ;
return 0 ;
}
static void
F_359 ( struct V_8 * V_9 , unsigned char * V_601 )
{
V_601 [ 0 ] = 0x0f ;
V_601 [ 1 ] = 0x01 ;
V_601 [ 2 ] = 0xd9 ;
}
static void F_360 ( void * V_602 )
{
* ( int * ) V_602 = 0 ;
}
static bool F_361 ( void )
{
return false ;
}
static bool F_362 ( void )
{
return true ;
}
static void F_363 ( struct V_8 * V_9 )
{
}
static void F_364 ( T_1 V_603 , struct V_604 * V_605 )
{
switch ( V_603 ) {
case 0x80000001 :
if ( V_17 )
V_605 -> V_553 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_605 -> V_289 = 1 ;
V_605 -> V_606 = 8 ;
V_605 -> V_553 = 0 ;
V_605 -> V_607 = 0 ;
if ( F_87 ( V_72 ) )
V_605 -> V_607 |= V_608 ;
if ( V_55 )
V_605 -> V_607 |= V_609 ;
break;
}
}
static int F_365 ( void )
{
return V_610 ;
}
static bool F_366 ( void )
{
return false ;
}
static bool F_367 ( void )
{
return false ;
}
static bool F_368 ( void )
{
return false ;
}
static bool F_369 ( void )
{
return false ;
}
static bool F_370 ( void )
{
return true ;
}
static void F_371 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_401 ) ;
F_159 ( V_10 ) ;
}
static int F_372 ( struct V_8 * V_9 ,
struct V_611 * V_61 ,
enum V_612 V_613 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_431 , V_65 = V_614 ;
struct V_615 V_616 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_61 -> V_22 >= F_322 ( V_617 ) )
goto V_300;
V_616 = V_617 [ V_61 -> V_22 ] ;
if ( V_613 != V_616 . V_613 )
goto V_300;
switch ( V_616 . V_421 ) {
case V_451 :
if ( V_61 -> V_22 == V_618 )
V_616 . V_421 += V_61 -> V_619 ;
break;
case V_527 : {
unsigned long V_353 , V_97 ;
T_2 V_22 ;
if ( V_61 -> V_22 == V_620 )
V_616 . V_421 += V_61 -> V_619 ;
if ( V_616 . V_421 != V_527 ||
V_61 -> V_22 == V_621 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_236 ) ) )
break;
V_353 = V_9 -> V_39 . V_353 & ~ V_355 ;
V_97 = V_61 -> V_622 & ~ V_355 ;
if ( V_61 -> V_22 == V_623 ) {
V_353 &= 0xfUL ;
V_97 &= 0xfUL ;
if ( V_353 & V_470 )
V_97 |= V_470 ;
}
if ( V_353 ^ V_97 )
V_616 . V_421 = V_523 ;
break;
}
case V_453 :
case V_624 :
V_616 . V_421 += V_61 -> V_619 ;
break;
case V_449 :
if ( V_61 -> V_22 == V_625 )
V_1 -> V_2 . V_385 = 1 ;
else
V_1 -> V_2 . V_385 = 0 ;
break;
case V_626 :
if ( V_61 -> V_627 != V_628 )
goto V_300;
case V_450 : {
T_2 V_629 ;
T_1 V_630 ;
if ( V_61 -> V_22 == V_631 ||
V_61 -> V_22 == V_632 ) {
V_629 = ( ( V_61 -> V_622 & 0xffff ) << 16 ) |
V_411 ;
V_630 = V_61 -> V_633 ;
} else {
V_629 = ( V_61 -> V_634 & 0xffff ) << 16 ;
V_630 = V_61 -> V_635 ;
}
if ( V_61 -> V_22 == V_636 ||
V_61 -> V_22 == V_632 )
V_629 |= V_410 ;
if ( V_61 -> V_627 )
V_629 |= V_637 ;
V_630 = F_89 ( V_630 , 4u ) ;
V_629 |= V_630 << V_413 ;
V_629 |= ( T_1 ) V_61 -> V_638 << ( V_639 - 1 ) ;
V_1 -> V_2 . V_385 = V_629 ;
V_1 -> V_2 . V_383 = V_61 -> V_71 ;
break;
}
default:
break;
}
if ( F_33 ( V_72 ) )
V_1 -> V_2 . V_71 = V_61 -> V_71 ;
V_1 -> V_2 . V_421 = V_616 . V_421 ;
V_431 = F_235 ( V_10 ) ;
V_65 = ( V_431 == V_434 ) ? V_640
: V_614 ;
V_300:
return V_65 ;
}
static void F_373 ( struct V_8 * V_9 )
{
F_181 () ;
}
static void F_374 ( struct V_8 * V_9 , int V_140 )
{
}
static int T_5 F_375 ( void )
{
return F_376 ( & V_641 , sizeof( struct V_7 ) ,
F_377 ( struct V_7 ) , V_642 ) ;
}
static void T_6 F_378 ( void )
{
F_379 () ;
}
