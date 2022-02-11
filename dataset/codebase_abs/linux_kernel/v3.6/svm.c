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
static inline void F_12 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_20 |= ( 1U << V_6 ) ;
F_6 ( V_10 ) ;
}
static inline void F_13 ( struct V_7 * V_10 , int V_6 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
V_1 -> V_2 . V_20 &= ~ ( 1U << V_6 ) ;
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
V_10 -> V_9 . V_23 . V_24 |= V_25 ;
}
static inline void F_19 ( struct V_7 * V_10 )
{
V_10 -> V_9 . V_23 . V_24 &= ~ V_25 ;
}
static inline bool F_20 ( struct V_7 * V_10 )
{
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_25 ) ;
}
static T_1 F_21 ( T_1 V_26 )
{
T_1 V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( V_26 < V_30 [ V_28 ] ||
V_26 >= V_30 [ V_28 ] + V_31 )
continue;
V_27 = ( V_26 - V_30 [ V_28 ] ) / 4 ;
V_27 += ( V_28 * V_32 ) ;
return V_27 / 4 ;
}
return V_33 ;
}
static inline void F_22 ( void )
{
asm volatile (__ex(SVM_CLGI));
}
static inline void F_23 ( void )
{
asm volatile (__ex(SVM_STGI));
}
static inline void F_24 ( unsigned long V_34 , T_1 V_35 )
{
asm volatile (__ex(SVM_INVLPGA) : : "a"(addr), "c"(asid));
}
static int F_25 ( void )
{
#ifdef F_26
return V_36 ;
#else
return V_37 ;
#endif
}
static void F_27 ( struct V_8 * V_9 , T_2 V_38 )
{
V_9 -> V_23 . V_38 = V_38 ;
if ( ! V_39 && ! ( V_38 & V_40 ) )
V_38 &= ~ V_41 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_38 = V_38 | V_43 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
}
static int F_28 ( T_1 V_45 )
{
V_45 &= V_46 | V_47 ;
return V_45 == ( V_47 | V_48 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , int V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_50 = 0 ;
if ( V_10 -> V_1 -> V_2 . V_51 & V_52 )
V_50 |= V_53 | V_54 ;
return V_50 & V_49 ;
}
static void F_30 ( struct V_8 * V_9 , int V_49 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_49 == 0 )
V_10 -> V_1 -> V_2 . V_51 &= ~ V_52 ;
else
V_10 -> V_1 -> V_2 . V_51 |= V_52 ;
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_10 -> V_1 -> V_2 . V_55 != 0 )
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_55 ;
if ( ! V_10 -> V_55 ) {
if ( F_32 ( V_9 , V_56 ) !=
V_57 )
F_33 ( V_58 L_1 , V_59 ) ;
return;
}
if ( V_10 -> V_55 - F_34 ( V_9 ) > V_60 )
F_33 ( V_61 L_2 ,
V_59 , F_34 ( V_9 ) , V_10 -> V_55 ) ;
F_35 ( V_9 , V_10 -> V_55 ) ;
F_30 ( V_9 , 0 ) ;
}
static void F_36 ( struct V_8 * V_9 , unsigned V_62 ,
bool V_63 , T_1 V_64 ,
bool V_65 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ! V_65 &&
F_37 ( V_10 , V_62 , V_63 , V_64 ) )
return;
if ( V_62 == V_66 && ! F_38 ( V_67 ) ) {
unsigned long V_68 , V_69 = F_34 ( & V_10 -> V_9 ) ;
F_31 ( & V_10 -> V_9 ) ;
V_68 = F_34 ( & V_10 -> V_9 ) ;
V_10 -> V_70 = V_68 + V_10 -> V_1 -> V_42 . V_71 . V_72 ;
V_10 -> V_73 = V_68 - V_69 ;
}
V_10 -> V_1 -> V_2 . V_74 = V_62
| V_47
| ( V_63 ? V_75 : 0 )
| V_76 ;
V_10 -> V_1 -> V_2 . V_77 = V_64 ;
}
static void F_39 ( void )
{
T_1 V_78 , V_79 ;
int V_80 ;
T_2 V_81 ;
if ( ! F_40 ( V_82 ) )
return;
V_81 = F_41 ( V_83 , & V_80 ) ;
if ( V_80 )
return;
V_81 |= ( 1ULL << 47 ) ;
V_78 = F_42 ( V_81 ) ;
V_79 = F_43 ( V_81 ) ;
F_44 ( V_83 , V_78 , V_79 ) ;
V_84 = true ;
}
static void F_45 ( struct V_8 * V_9 )
{
V_9 -> V_23 . V_85 . V_86 = ( V_87 >= 3 ) ? ( V_87 ) : 3 ;
V_9 -> V_23 . V_85 . V_88 = V_89 & ~ ( 6ULL ) ;
if ( V_87 == 0 && V_90 . V_91 == 0x10 )
V_9 -> V_23 . V_85 . V_88 |= 1 ;
}
static int F_46 ( void )
{
const char * V_92 ;
if ( ! F_47 ( & V_92 ) ) {
F_33 ( V_93 L_3 , V_92 ) ;
return 0 ;
}
return 1 ;
}
static void F_48 ( void * V_94 )
{
if ( F_38 ( V_95 ) )
F_49 ( V_96 , V_97 ) ;
F_50 () ;
F_51 () ;
}
static int F_52 ( void * V_94 )
{
struct V_98 * V_99 ;
T_3 V_38 ;
struct V_100 V_101 ;
struct V_102 * V_103 ;
int V_104 = F_53 () ;
F_54 ( V_105 , V_38 ) ;
if ( V_38 & V_43 )
return - V_106 ;
if ( ! F_46 () ) {
F_33 ( V_61 L_4 ,
V_104 ) ;
return - V_107 ;
}
V_99 = F_55 ( V_108 , V_104 ) ;
if ( ! V_99 ) {
F_33 ( V_61 L_5 ,
V_104 ) ;
return - V_107 ;
}
V_99 -> V_109 = 1 ;
V_99 -> V_110 = F_56 ( V_111 ) - 1 ;
V_99 -> V_112 = V_99 -> V_110 + 1 ;
F_57 ( & V_101 ) ;
V_103 = (struct V_102 * ) V_101 . V_113 ;
V_99 -> V_114 = (struct V_115 * ) ( V_103 + V_116 ) ;
F_49 ( V_105 , V_38 | V_43 ) ;
F_49 ( V_117 , F_58 ( V_99 -> V_118 ) << V_119 ) ;
if ( F_38 ( V_95 ) ) {
F_49 ( V_96 , V_97 ) ;
F_59 ( V_120 ) = V_97 ;
}
if ( F_60 ( & V_90 , V_121 ) ) {
T_3 V_122 , V_88 = 0 ;
int V_80 ;
V_122 = F_41 ( V_123 , & V_80 ) ;
if ( ! V_80 )
V_88 = F_41 ( V_124 ,
& V_80 ) ;
if ( V_80 )
V_89 = V_87 = 0 ;
else {
if ( V_122 < V_87 )
V_87 = V_122 ;
V_89 |= V_88 ;
V_89 &= ( 1ULL << V_87 ) - 1 ;
}
} else
V_89 = V_87 = 0 ;
F_39 () ;
F_61 () ;
return 0 ;
}
static void F_62 ( int V_125 )
{
struct V_98 * V_99 = F_55 ( V_108 , F_53 () ) ;
if ( ! V_99 )
return;
F_55 ( V_108 , F_53 () ) = NULL ;
F_63 ( V_99 -> V_118 ) ;
F_64 ( V_99 ) ;
}
static int F_65 ( int V_125 )
{
struct V_98 * V_99 ;
int V_126 ;
V_99 = F_66 ( sizeof( struct V_98 ) , V_127 ) ;
if ( ! V_99 )
return - V_128 ;
V_99 -> V_125 = V_125 ;
V_99 -> V_118 = F_67 ( V_127 ) ;
V_126 = - V_128 ;
if ( ! V_99 -> V_118 )
goto V_129;
F_55 ( V_108 , V_125 ) = V_99 ;
return 0 ;
V_129:
F_64 ( V_99 ) ;
return V_126 ;
}
static bool F_68 ( T_1 V_130 )
{
int V_28 ;
for ( V_28 = 0 ; V_131 [ V_28 ] . V_130 != V_33 ; V_28 ++ )
if ( V_131 [ V_28 ] . V_130 == V_130 )
return true ;
return false ;
}
static void F_69 ( T_1 * V_132 , unsigned V_26 ,
int V_133 , int V_134 )
{
T_4 V_135 , V_136 ;
unsigned long V_137 ;
T_1 V_27 ;
F_70 ( ! F_68 ( V_26 ) ) ;
V_27 = F_21 ( V_26 ) ;
V_135 = 2 * ( V_26 & 0x0f ) ;
V_136 = 2 * ( V_26 & 0x0f ) + 1 ;
V_137 = V_132 [ V_27 ] ;
F_71 ( V_27 == V_33 ) ;
V_133 ? F_72 ( V_135 , & V_137 ) : F_73 ( V_135 , & V_137 ) ;
V_134 ? F_72 ( V_136 , & V_137 ) : F_73 ( V_136 , & V_137 ) ;
V_132 [ V_27 ] = V_137 ;
}
static void F_74 ( T_1 * V_132 )
{
int V_28 ;
memset ( V_132 , 0xff , V_138 * ( 1 << V_139 ) ) ;
for ( V_28 = 0 ; V_131 [ V_28 ] . V_130 != V_33 ; V_28 ++ ) {
if ( ! V_131 [ V_28 ] . V_140 )
continue;
F_69 ( V_132 , V_131 [ V_28 ] . V_130 , 1 , 1 ) ;
}
}
static void F_75 ( T_1 V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_141 ; ++ V_28 ) {
if ( V_142 [ V_28 ] == V_27 )
return;
if ( V_142 [ V_28 ] != V_33 )
continue;
V_142 [ V_28 ] = V_27 ;
return;
}
F_76 () ;
}
static void F_77 ( void )
{
int V_28 ;
memset ( V_142 , 0xff , sizeof( V_142 ) ) ;
for ( V_28 = 0 ; V_131 [ V_28 ] . V_130 != V_33 ; V_28 ++ ) {
T_1 V_27 ;
V_27 = F_21 ( V_131 [ V_28 ] . V_130 ) ;
F_71 ( V_27 == V_33 ) ;
F_75 ( V_27 ) ;
}
}
static void F_78 ( struct V_7 * V_10 )
{
T_1 * V_132 = V_10 -> V_132 ;
V_10 -> V_1 -> V_2 . V_143 = 1 ;
F_69 ( V_132 , V_144 , 1 , 1 ) ;
F_69 ( V_132 , V_145 , 1 , 1 ) ;
F_69 ( V_132 , V_146 , 1 , 1 ) ;
F_69 ( V_132 , V_147 , 1 , 1 ) ;
}
static void F_79 ( struct V_7 * V_10 )
{
T_1 * V_132 = V_10 -> V_132 ;
V_10 -> V_1 -> V_2 . V_143 = 0 ;
F_69 ( V_132 , V_144 , 0 , 0 ) ;
F_69 ( V_132 , V_145 , 0 , 0 ) ;
F_69 ( V_132 , V_146 , 0 , 0 ) ;
F_69 ( V_132 , V_147 , 0 , 0 ) ;
}
static T_5 int F_80 ( void )
{
int V_125 ;
struct V_148 * V_149 ;
void * V_150 ;
int V_126 ;
V_149 = F_81 ( V_127 , V_151 ) ;
if ( ! V_149 )
return - V_128 ;
V_150 = F_82 ( V_149 ) ;
memset ( V_150 , 0xff , V_138 * ( 1 << V_151 ) ) ;
V_152 = F_58 ( V_149 ) << V_119 ;
F_77 () ;
if ( F_83 ( V_153 ) )
F_84 ( V_154 ) ;
if ( F_83 ( V_155 ) )
F_84 ( V_156 ) ;
if ( F_83 ( V_95 ) ) {
T_2 V_157 ;
V_158 = true ;
V_157 = F_85 ( 0x7fffffffULL , F_86 ( V_159 , V_160 ) ) ;
V_161 = V_157 ;
}
if ( V_17 ) {
F_33 ( V_93 L_6 ) ;
F_84 ( V_43 | V_162 ) ;
}
F_87 (cpu) {
V_126 = F_65 ( V_125 ) ;
if ( V_126 )
goto V_80;
}
if ( ! F_83 ( V_163 ) )
V_39 = false ;
if ( V_39 && ! V_164 ) {
F_33 ( V_93 L_7 ) ;
V_39 = false ;
}
if ( V_39 ) {
F_33 ( V_93 L_8 ) ;
F_88 () ;
} else
F_89 () ;
return 0 ;
V_80:
F_90 ( V_149 , V_151 ) ;
V_152 = 0 ;
return V_126 ;
}
static T_6 void F_91 ( void )
{
int V_125 ;
F_87 (cpu)
F_62 ( V_125 ) ;
F_90 ( F_92 ( V_152 >> V_119 ) , V_151 ) ;
V_152 = 0 ;
}
static void F_93 ( struct V_165 * V_166 )
{
V_166 -> V_167 = 0 ;
V_166 -> V_168 = V_169 | V_170 |
V_171 ;
V_166 -> V_172 = 0xffff ;
V_166 -> V_72 = 0 ;
}
static void F_94 ( struct V_165 * V_166 , T_7 type )
{
V_166 -> V_167 = 0 ;
V_166 -> V_168 = V_169 | type ;
V_166 -> V_172 = 0xffff ;
V_166 -> V_72 = 0 ;
}
static T_2 F_86 ( T_2 V_173 , T_2 V_174 )
{
T_2 V_175 , V_176 , V_177 ;
V_175 = V_173 >> 32 ;
V_176 = V_173 & ( ( 1ULL << 32 ) - 1 ) ;
V_177 = V_174 ;
V_177 *= V_175 ;
V_177 += ( V_174 >> 32 ) * V_176 ;
V_177 += ( ( V_174 & ( ( 1ULL << 32 ) - 1 ) ) * V_176 ) >> 32 ;
return V_177 ;
}
static T_2 F_95 ( struct V_8 * V_9 , T_2 V_174 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_177 = V_174 ;
if ( V_10 -> V_178 != V_97 )
V_177 = F_86 ( V_10 -> V_178 , V_174 ) ;
return V_177 ;
}
static void F_96 ( struct V_8 * V_9 , T_1 V_179 , bool V_180 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_173 ;
T_2 V_181 ;
if ( ! V_180 ) {
V_10 -> V_178 = V_97 ;
return;
}
if ( ! F_83 ( V_95 ) ) {
if ( V_179 > V_159 ) {
V_9 -> V_23 . V_182 = 1 ;
V_9 -> V_23 . V_183 = 1 ;
} else
F_97 ( 1 , L_9 ) ;
return;
}
V_181 = V_179 ;
V_173 = V_181 << 32 ;
F_98 ( V_173 , V_159 ) ;
if ( V_173 == 0 || V_173 & V_184 ) {
F_99 ( 1 , L_10 ,
V_179 ) ;
return;
}
V_10 -> V_178 = V_173 ;
}
static void F_100 ( struct V_8 * V_9 , T_2 V_27 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_185 = 0 ;
if ( F_7 ( V_9 ) ) {
V_185 = V_10 -> V_1 -> V_2 . V_186 -
V_10 -> V_17 . V_18 -> V_2 . V_186 ;
V_10 -> V_17 . V_18 -> V_2 . V_186 = V_27 ;
}
V_10 -> V_1 -> V_2 . V_186 = V_27 + V_185 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_101 ( struct V_8 * V_9 , T_8 V_187 , bool V_188 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_70 ( V_187 < 0 ) ;
if ( V_188 )
V_187 = F_95 ( V_9 , V_187 ) ;
V_10 -> V_1 -> V_2 . V_186 += V_187 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_186 += V_187 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_102 ( struct V_8 * V_9 , T_2 V_189 )
{
T_2 V_174 ;
V_174 = F_95 ( V_9 , F_103 () ) ;
return V_189 - V_174 ;
}
static void F_104 ( struct V_7 * V_10 )
{
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_190 * V_42 = & V_10 -> V_1 -> V_42 ;
V_10 -> V_9 . V_191 = 1 ;
V_10 -> V_9 . V_23 . V_24 = 0 ;
F_9 ( V_10 , V_192 ) ;
F_9 ( V_10 , V_193 ) ;
F_9 ( V_10 , V_194 ) ;
F_9 ( V_10 , V_195 ) ;
F_9 ( V_10 , V_196 ) ;
F_9 ( V_10 , V_197 ) ;
F_9 ( V_10 , V_198 ) ;
F_12 ( V_10 , V_199 ) ;
F_12 ( V_10 , V_200 ) ;
F_12 ( V_10 , V_201 ) ;
F_12 ( V_10 , V_202 ) ;
F_12 ( V_10 , V_203 ) ;
F_12 ( V_10 , V_204 ) ;
F_12 ( V_10 , V_205 ) ;
F_12 ( V_10 , V_206 ) ;
F_12 ( V_10 , V_207 ) ;
F_12 ( V_10 , V_208 ) ;
F_12 ( V_10 , V_209 ) ;
F_12 ( V_10 , V_210 ) ;
F_12 ( V_10 , V_211 ) ;
F_12 ( V_10 , V_212 ) ;
F_12 ( V_10 , V_213 ) ;
F_12 ( V_10 , V_214 ) ;
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
V_2 -> V_243 = V_152 ;
V_2 -> V_244 = F_105 ( V_10 -> V_132 ) ;
V_2 -> V_245 = V_246 ;
F_93 ( & V_42 -> V_247 ) ;
F_93 ( & V_42 -> V_248 ) ;
F_93 ( & V_42 -> V_249 ) ;
F_93 ( & V_42 -> V_250 ) ;
F_93 ( & V_42 -> V_251 ) ;
V_42 -> V_71 . V_167 = 0xf000 ;
V_42 -> V_71 . V_168 = V_252 | V_169 |
V_170 | V_253 ;
V_42 -> V_71 . V_172 = 0xffff ;
V_42 -> V_71 . V_72 = 0xf0000 ;
V_42 -> V_254 . V_172 = 0xffff ;
V_42 -> V_255 . V_172 = 0xffff ;
F_94 ( & V_42 -> V_256 , V_257 ) ;
F_94 ( & V_42 -> V_258 , V_259 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_42 -> V_260 = 0xffff0ff0 ;
V_42 -> V_261 = 0x400 ;
F_106 ( & V_10 -> V_9 , 2 ) ;
V_42 -> V_68 = 0x0000fff0 ;
V_10 -> V_9 . V_23 . V_262 [ V_263 ] = V_42 -> V_68 ;
V_10 -> V_9 . V_23 . V_264 = 0 ;
( void ) F_107 ( & V_10 -> V_9 , V_265 | V_266 | V_267 ) ;
V_42 -> V_268 = V_269 ;
if ( V_39 ) {
V_2 -> V_270 = 1 ;
F_17 ( V_10 , V_226 ) ;
F_15 ( V_10 , V_215 ) ;
F_10 ( V_10 , V_193 ) ;
F_10 ( V_10 , V_196 ) ;
V_42 -> V_271 = 0x0007040600070406ULL ;
V_42 -> V_272 = 0 ;
V_42 -> V_268 = 0 ;
}
V_10 -> V_109 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_23 . V_24 = 0 ;
if ( F_83 ( V_273 ) ) {
V_2 -> V_274 = 3000 ;
F_16 ( V_10 , V_275 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static int F_108 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_104 ( V_10 ) ;
if ( ! F_109 ( V_9 ) ) {
F_35 ( V_9 , 0 ) ;
V_10 -> V_1 -> V_42 . V_71 . V_72 = V_10 -> V_9 . V_23 . V_276 << 12 ;
V_10 -> V_1 -> V_42 . V_71 . V_167 = V_10 -> V_9 . V_23 . V_276 << 8 ;
}
V_9 -> V_23 . V_277 = ~ 0 ;
V_9 -> V_23 . V_278 = ~ 0 ;
return 0 ;
}
static struct V_8 * F_110 ( struct V_279 * V_279 , unsigned int V_280 )
{
struct V_7 * V_10 ;
struct V_148 * V_148 ;
struct V_148 * V_281 ;
struct V_148 * V_282 ;
struct V_148 * V_283 ;
int V_80 ;
V_10 = F_111 ( V_284 , V_127 ) ;
if ( ! V_10 ) {
V_80 = - V_128 ;
goto V_285;
}
V_10 -> V_178 = V_97 ;
V_80 = F_112 ( & V_10 -> V_9 , V_279 , V_280 ) ;
if ( V_80 )
goto V_286;
V_80 = - V_128 ;
V_148 = F_67 ( V_127 ) ;
if ( ! V_148 )
goto V_287;
V_281 = F_81 ( V_127 , V_139 ) ;
if ( ! V_281 )
goto V_288;
V_283 = F_81 ( V_127 , V_139 ) ;
if ( ! V_283 )
goto V_289;
V_282 = F_67 ( V_127 ) ;
if ( ! V_282 )
goto V_290;
V_10 -> V_17 . V_18 = F_82 ( V_282 ) ;
V_10 -> V_132 = F_82 ( V_281 ) ;
F_74 ( V_10 -> V_132 ) ;
V_10 -> V_17 . V_132 = F_82 ( V_283 ) ;
F_74 ( V_10 -> V_17 . V_132 ) ;
V_10 -> V_1 = F_82 ( V_148 ) ;
F_113 ( V_10 -> V_1 ) ;
V_10 -> V_291 = F_58 ( V_148 ) << V_119 ;
V_10 -> V_109 = 0 ;
F_104 ( V_10 ) ;
F_114 ( & V_10 -> V_9 , 0 ) ;
V_80 = F_115 ( & V_10 -> V_9 ) ;
if ( V_80 )
goto V_292;
V_10 -> V_9 . V_23 . V_293 = 0xfee00000 | V_294 ;
if ( F_109 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_23 . V_293 |= V_295 ;
F_45 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_292:
F_63 ( V_282 ) ;
V_290:
F_90 ( V_283 , V_139 ) ;
V_289:
F_90 ( V_281 , V_139 ) ;
V_288:
F_63 ( V_148 ) ;
V_287:
F_116 ( & V_10 -> V_9 ) ;
V_286:
F_117 ( V_284 , V_10 ) ;
V_285:
return F_118 ( V_80 ) ;
}
static void F_119 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_63 ( F_92 ( V_10 -> V_291 >> V_119 ) ) ;
F_90 ( F_120 ( V_10 -> V_132 ) , V_139 ) ;
F_63 ( F_120 ( V_10 -> V_17 . V_18 ) ) ;
F_90 ( F_120 ( V_10 -> V_17 . V_132 ) , V_139 ) ;
F_116 ( V_9 ) ;
F_117 ( V_284 , V_10 ) ;
}
static void F_121 ( struct V_8 * V_9 , int V_125 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
if ( F_122 ( V_125 != V_9 -> V_125 ) ) {
V_10 -> V_109 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_54 ( V_296 , F_4 ( V_9 ) -> V_188 . V_297 ) ;
#endif
F_123 ( V_250 , V_10 -> V_188 . V_250 ) ;
F_123 ( V_251 , V_10 -> V_188 . V_251 ) ;
V_10 -> V_188 . V_298 = F_124 () ;
for ( V_28 = 0 ; V_28 < V_299 ; V_28 ++ )
F_54 ( V_300 [ V_28 ] , V_10 -> V_301 [ V_28 ] ) ;
if ( F_38 ( V_95 ) &&
V_10 -> V_178 != F_59 ( V_120 ) ) {
F_59 ( V_120 ) = V_10 -> V_178 ;
F_49 ( V_96 , V_10 -> V_178 ) ;
}
}
static void F_125 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
++ V_9 -> V_302 . V_303 ;
F_126 ( V_10 -> V_188 . V_298 ) ;
#ifdef F_26
F_127 ( V_250 , V_10 -> V_188 . V_250 ) ;
F_49 ( V_304 , V_305 -> V_306 . V_251 ) ;
F_128 ( V_10 -> V_188 . V_251 ) ;
#else
#ifdef F_129
F_127 ( V_251 , V_10 -> V_188 . V_251 ) ;
#endif
#endif
for ( V_28 = 0 ; V_28 < V_299 ; V_28 ++ )
F_49 ( V_300 [ V_28 ] , V_10 -> V_301 [ V_28 ] ) ;
}
static void F_130 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_307 ;
if ( ! F_131 ( V_9 ) )
V_307 = 0 ;
else if ( V_10 -> V_1 -> V_42 . V_308 & V_309 )
V_307 = 3 ;
else
V_307 = V_10 -> V_1 -> V_42 . V_71 . V_167 & 0x3 ;
V_10 -> V_1 -> V_42 . V_307 = V_307 ;
}
static unsigned long F_132 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_42 . V_308 ;
}
static void F_133 ( struct V_8 * V_9 , unsigned long V_308 )
{
unsigned long V_310 = F_4 ( V_9 ) -> V_1 -> V_42 . V_308 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_308 = V_308 ;
if ( ( V_310 ^ V_308 ) & V_309 )
F_130 ( V_9 ) ;
}
static void F_134 ( struct V_8 * V_9 , enum V_311 V_312 )
{
switch ( V_312 ) {
case V_313 :
F_71 ( ! V_39 ) ;
F_135 ( V_9 , V_9 -> V_23 . V_314 , F_136 ( V_9 ) ) ;
break;
default:
F_76 () ;
}
}
static void F_137 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_315 ) ;
}
static void F_138 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_315 ) ;
}
static struct V_165 * F_139 ( struct V_8 * V_9 , int V_166 )
{
struct V_190 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
switch ( V_166 ) {
case V_316 : return & V_42 -> V_71 ;
case V_317 : return & V_42 -> V_249 ;
case V_318 : return & V_42 -> V_247 ;
case V_319 : return & V_42 -> V_250 ;
case V_320 : return & V_42 -> V_251 ;
case V_321 : return & V_42 -> V_248 ;
case V_322 : return & V_42 -> V_258 ;
case V_323 : return & V_42 -> V_256 ;
}
F_76 () ;
return NULL ;
}
static T_2 F_140 ( struct V_8 * V_9 , int V_166 )
{
struct V_165 * V_324 = F_139 ( V_9 , V_166 ) ;
return V_324 -> V_72 ;
}
static void F_141 ( struct V_8 * V_9 ,
struct V_325 * V_326 , int V_166 )
{
struct V_165 * V_324 = F_139 ( V_9 , V_166 ) ;
V_326 -> V_72 = V_324 -> V_72 ;
V_326 -> V_172 = V_324 -> V_172 ;
V_326 -> V_167 = V_324 -> V_167 ;
V_326 -> type = V_324 -> V_168 & V_327 ;
V_326 -> V_324 = ( V_324 -> V_168 >> V_328 ) & 1 ;
V_326 -> V_329 = ( V_324 -> V_168 >> V_330 ) & 3 ;
V_326 -> V_331 = ( V_324 -> V_168 >> V_332 ) & 1 ;
V_326 -> V_333 = ( V_324 -> V_168 >> V_334 ) & 1 ;
V_326 -> V_335 = ( V_324 -> V_168 >> V_336 ) & 1 ;
V_326 -> V_337 = ( V_324 -> V_168 >> V_338 ) & 1 ;
V_326 -> V_15 = ( V_324 -> V_168 >> V_339 ) & 1 ;
V_326 -> V_340 = ! V_326 -> V_331 || ( V_326 -> type == 0 ) ;
switch ( V_166 ) {
case V_316 :
V_326 -> V_15 = V_324 -> V_172 > 0xfffff ;
break;
case V_322 :
V_326 -> type |= 0x2 ;
break;
case V_317 :
case V_318 :
case V_319 :
case V_320 :
if ( ! V_326 -> V_340 )
V_326 -> type |= 0x1 ;
break;
case V_321 :
if ( V_326 -> V_340 )
V_326 -> V_337 = 0 ;
break;
}
}
static int F_142 ( struct V_8 * V_9 )
{
struct V_190 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
return V_42 -> V_307 ;
}
static void F_143 ( struct V_8 * V_9 , struct V_100 * V_341 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_341 -> V_342 = V_10 -> V_1 -> V_42 . V_255 . V_172 ;
V_341 -> V_113 = V_10 -> V_1 -> V_42 . V_255 . V_72 ;
}
static void F_144 ( struct V_8 * V_9 , struct V_100 * V_341 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_255 . V_172 = V_341 -> V_342 ;
V_10 -> V_1 -> V_42 . V_255 . V_72 = V_341 -> V_113 ;
F_3 ( V_10 -> V_1 , V_343 ) ;
}
static void F_145 ( struct V_8 * V_9 , struct V_100 * V_341 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_341 -> V_342 = V_10 -> V_1 -> V_42 . V_254 . V_172 ;
V_341 -> V_113 = V_10 -> V_1 -> V_42 . V_254 . V_72 ;
}
static void F_146 ( struct V_8 * V_9 , struct V_100 * V_341 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_254 . V_172 = V_341 -> V_342 ;
V_10 -> V_1 -> V_42 . V_254 . V_72 = V_341 -> V_113 ;
F_3 ( V_10 -> V_1 , V_343 ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
}
static void F_148 ( struct V_8 * V_9 )
{
}
static void F_149 ( struct V_8 * V_9 )
{
}
static void F_150 ( struct V_7 * V_10 )
{
T_9 V_344 = V_10 -> V_9 . V_23 . V_264 ;
T_2 * V_345 = & V_10 -> V_1 -> V_42 . V_264 ;
if ( ! V_10 -> V_9 . V_191 )
* V_345 |= V_346 ;
else
* V_345 = ( * V_345 & ~ V_346 )
| ( V_344 & V_346 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
if ( V_344 == * V_345 && V_10 -> V_9 . V_191 ) {
F_10 ( V_10 , V_192 ) ;
F_10 ( V_10 , V_195 ) ;
} else {
F_9 ( V_10 , V_192 ) ;
F_9 ( V_10 , V_195 ) ;
}
}
static void F_151 ( struct V_8 * V_9 , unsigned long V_264 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_23 . V_38 & V_41 ) {
if ( ! F_152 ( V_9 ) && ( V_264 & V_347 ) ) {
V_9 -> V_23 . V_38 |= V_40 ;
V_10 -> V_1 -> V_42 . V_38 |= V_40 | V_41 ;
}
if ( F_152 ( V_9 ) && ! ( V_264 & V_347 ) ) {
V_9 -> V_23 . V_38 &= ~ V_40 ;
V_10 -> V_1 -> V_42 . V_38 &= ~ ( V_40 | V_41 ) ;
}
}
#endif
V_9 -> V_23 . V_264 = V_264 ;
if ( ! V_39 )
V_264 |= V_347 | V_348 ;
if ( ! V_9 -> V_191 )
V_264 |= V_349 ;
V_264 &= ~ ( V_266 | V_265 ) ;
V_10 -> V_1 -> V_42 . V_264 = V_264 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_150 ( V_10 ) ;
}
static int F_153 ( struct V_8 * V_9 , unsigned long V_268 )
{
unsigned long V_350 = F_154 () & V_351 ;
unsigned long V_352 = F_4 ( V_9 ) -> V_1 -> V_42 . V_268 ;
if ( V_268 & V_353 )
return 1 ;
if ( V_39 && ( ( V_352 ^ V_268 ) & V_354 ) )
F_155 ( V_9 ) ;
V_9 -> V_23 . V_268 = V_268 ;
if ( ! V_39 )
V_268 |= V_269 ;
V_268 |= V_350 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_268 = V_268 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
return 0 ;
}
static void F_156 ( struct V_8 * V_9 ,
struct V_325 * V_326 , int V_166 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_165 * V_324 = F_139 ( V_9 , V_166 ) ;
V_324 -> V_72 = V_326 -> V_72 ;
V_324 -> V_172 = V_326 -> V_172 ;
V_324 -> V_167 = V_326 -> V_167 ;
if ( V_326 -> V_340 )
V_324 -> V_168 = 0 ;
else {
V_324 -> V_168 = ( V_326 -> type & V_327 ) ;
V_324 -> V_168 |= ( V_326 -> V_324 & 1 ) << V_328 ;
V_324 -> V_168 |= ( V_326 -> V_329 & 3 ) << V_330 ;
V_324 -> V_168 |= ( V_326 -> V_331 & 1 ) << V_332 ;
V_324 -> V_168 |= ( V_326 -> V_333 & 1 ) << V_334 ;
V_324 -> V_168 |= ( V_326 -> V_335 & 1 ) << V_336 ;
V_324 -> V_168 |= ( V_326 -> V_337 & 1 ) << V_338 ;
V_324 -> V_168 |= ( V_326 -> V_15 & 1 ) << V_339 ;
}
if ( V_166 == V_316 )
F_130 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_355 ) ;
}
static void F_157 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_356 ) ;
F_15 ( V_10 , V_66 ) ;
if ( V_10 -> V_357 )
F_14 ( V_10 , V_356 ) ;
if ( V_9 -> V_358 & V_359 ) {
if ( V_9 -> V_358 &
( V_360 | V_361 ) )
F_14 ( V_10 , V_356 ) ;
if ( V_9 -> V_358 & V_362 )
F_14 ( V_10 , V_66 ) ;
} else
V_9 -> V_358 = 0 ;
}
static void F_158 ( struct V_8 * V_9 , struct V_363 * V_364 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_9 -> V_358 & V_361 )
V_10 -> V_1 -> V_42 . V_261 = V_364 -> V_23 . V_365 [ 7 ] ;
else
V_10 -> V_1 -> V_42 . V_261 = V_9 -> V_23 . V_261 ;
F_3 ( V_10 -> V_1 , V_366 ) ;
F_157 ( V_9 ) ;
}
static void F_159 ( struct V_7 * V_10 , struct V_98 * V_99 )
{
if ( V_99 -> V_112 > V_99 -> V_110 ) {
++ V_99 -> V_109 ;
V_99 -> V_112 = 1 ;
V_10 -> V_1 -> V_2 . V_367 = V_368 ;
}
V_10 -> V_109 = V_99 -> V_109 ;
V_10 -> V_1 -> V_2 . V_35 = V_99 -> V_112 ++ ;
F_3 ( V_10 -> V_1 , V_369 ) ;
}
static void F_160 ( struct V_8 * V_9 , unsigned long V_370 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_261 = V_370 ;
F_3 ( V_10 -> V_1 , V_366 ) ;
}
static int F_161 ( struct V_7 * V_10 )
{
T_2 V_371 = V_10 -> V_1 -> V_2 . V_372 ;
T_1 V_64 ;
int V_126 = 1 ;
switch ( V_10 -> V_373 ) {
default:
V_64 = V_10 -> V_1 -> V_2 . V_374 ;
F_162 ( V_371 , V_64 ) ;
if ( ! V_39 && F_163 ( & V_10 -> V_9 ) )
F_164 ( & V_10 -> V_9 , V_371 ) ;
V_126 = F_165 ( & V_10 -> V_9 , V_371 , V_64 ,
V_10 -> V_1 -> V_2 . V_375 ,
V_10 -> V_1 -> V_2 . V_376 ) ;
break;
case V_377 :
V_10 -> V_373 = 0 ;
F_166 () ;
F_167 ( V_371 ) ;
F_168 () ;
break;
case V_378 :
V_10 -> V_373 = 0 ;
F_166 () ;
F_169 ( V_371 ) ;
F_168 () ;
break;
}
return V_126 ;
}
static int F_170 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
if ( ! ( V_10 -> V_9 . V_358 &
( V_360 | V_361 ) ) &&
! V_10 -> V_357 ) {
F_171 ( & V_10 -> V_9 , V_356 ) ;
return 1 ;
}
if ( V_10 -> V_357 ) {
V_10 -> V_357 = false ;
if ( ! ( V_10 -> V_9 . V_358 & V_360 ) )
V_10 -> V_1 -> V_42 . V_308 &=
~ ( V_381 | V_382 ) ;
F_157 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_358 &
( V_360 | V_361 ) ) {
V_379 -> V_383 = V_384 ;
V_379 -> V_385 . V_23 . V_386 =
V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_379 -> V_385 . V_23 . V_387 = V_356 ;
return 0 ;
}
return 1 ;
}
static int F_172 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
V_379 -> V_383 = V_384 ;
V_379 -> V_385 . V_23 . V_386 = V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_379 -> V_385 . V_23 . V_387 = V_66 ;
return 0 ;
}
static int F_173 ( struct V_7 * V_10 )
{
int V_388 ;
V_388 = F_32 ( & V_10 -> V_9 , V_389 ) ;
if ( V_388 != V_57 )
F_171 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static void F_174 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_390 ) ;
V_10 -> V_9 . V_191 = 1 ;
F_150 ( V_10 ) ;
}
static int F_175 ( struct V_7 * V_10 )
{
F_174 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_176 ( void )
{
int V_80 , V_28 ;
T_2 V_370 ;
if ( ! V_84 )
return false ;
V_370 = F_41 ( V_391 , & V_80 ) ;
if ( V_80 )
return false ;
V_370 &= ~ ( 1ULL << 62 ) ;
if ( V_370 != 0xb600000000010015ULL )
return false ;
for ( V_28 = 0 ; V_28 < 6 ; ++ V_28 )
F_44 ( F_177 ( V_28 ) , 0 , 0 ) ;
V_370 = F_41 ( V_392 , & V_80 ) ;
if ( ! V_80 ) {
T_1 V_78 , V_79 ;
V_370 &= ~ ( 1ULL << 2 ) ;
V_78 = F_42 ( V_370 ) ;
V_79 = F_43 ( V_370 ) ;
F_44 ( V_392 , V_78 , V_79 ) ;
}
F_178 () ;
return true ;
}
static void F_179 ( struct V_7 * V_10 )
{
if ( F_176 () ) {
F_180 ( L_11 ) ;
F_181 ( V_393 , & V_10 -> V_9 ) ;
return;
}
asm volatile (
"int $0x12\n");
return;
}
static int F_182 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_183 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
F_113 ( V_10 -> V_1 ) ;
F_104 ( V_10 ) ;
V_379 -> V_383 = V_394 ;
return 0 ;
}
static int F_184 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_395 = V_10 -> V_1 -> V_2 . V_374 ;
int V_342 , V_396 , string ;
unsigned V_397 ;
++ V_10 -> V_9 . V_302 . V_398 ;
string = ( V_395 & V_399 ) != 0 ;
V_396 = ( V_395 & V_400 ) != 0 ;
if ( string || V_396 )
return F_32 ( V_9 , 0 ) == V_57 ;
V_397 = V_395 >> 16 ;
V_342 = ( V_395 & V_401 ) >> V_402 ;
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_372 ;
F_31 ( & V_10 -> V_9 ) ;
return F_185 ( V_9 , V_342 , V_397 ) ;
}
static int F_186 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_187 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_302 . V_403 ;
return 1 ;
}
static int F_188 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_189 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 1 ;
F_31 ( & V_10 -> V_9 ) ;
return F_190 ( & V_10 -> V_9 ) ;
}
static int F_191 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_192 ( & V_10 -> V_9 ) ;
return 1 ;
}
static unsigned long F_193 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_17 . V_404 ;
}
static T_2 F_194 ( struct V_8 * V_9 , int V_130 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_272 = V_10 -> V_17 . V_404 ;
T_2 V_405 ;
int V_50 ;
V_50 = F_195 ( V_9 -> V_279 , F_196 ( V_272 ) , & V_405 ,
F_197 ( V_272 ) + V_130 * 8 , 8 ) ;
if ( V_50 )
return 0 ;
return V_405 ;
}
static void F_198 ( struct V_8 * V_9 ,
unsigned long V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_404 = V_406 ;
F_3 ( V_10 -> V_1 , V_407 ) ;
F_155 ( V_9 ) ;
}
static void F_199 ( struct V_8 * V_9 ,
struct V_408 * V_409 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_410 = V_411 ;
V_10 -> V_1 -> V_2 . V_412 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = V_409 -> V_64 ;
V_10 -> V_1 -> V_2 . V_372 = V_409 -> V_113 ;
F_200 ( V_10 ) ;
}
static int F_201 ( struct V_8 * V_9 )
{
int V_126 ;
V_126 = F_202 ( V_9 , & V_9 -> V_23 . V_413 ) ;
V_9 -> V_23 . V_413 . V_414 = F_198 ;
V_9 -> V_23 . V_413 . V_415 = F_193 ;
V_9 -> V_23 . V_413 . V_416 = F_194 ;
V_9 -> V_23 . V_413 . V_417 = F_199 ;
V_9 -> V_23 . V_413 . V_418 = F_25 () ;
V_9 -> V_23 . V_314 = & V_9 -> V_23 . V_419 ;
return V_126 ;
}
static void F_203 ( struct V_8 * V_9 )
{
V_9 -> V_23 . V_314 = & V_9 -> V_23 . V_413 ;
}
static int F_204 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_23 . V_38 & V_43 )
|| ! F_152 ( & V_10 -> V_9 ) ) {
F_171 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_42 . V_307 ) {
F_205 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_10 , unsigned V_62 ,
bool V_63 , T_1 V_64 )
{
int V_420 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_410 = V_421 + V_62 ;
V_10 -> V_1 -> V_2 . V_412 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = V_64 ;
V_10 -> V_1 -> V_2 . V_372 = V_10 -> V_9 . V_23 . V_422 ;
V_420 = F_206 ( V_10 ) ;
if ( V_420 == V_423 )
V_10 -> V_17 . V_424 = true ;
return V_420 ;
}
static inline bool F_207 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_425 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_426 ) )
return false ;
if ( V_10 -> V_17 . V_424 )
return false ;
V_10 -> V_1 -> V_2 . V_410 = V_427 ;
V_10 -> V_1 -> V_2 . V_374 = 0 ;
V_10 -> V_1 -> V_2 . V_372 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_424 = true ;
F_208 ( V_10 -> V_1 -> V_42 . V_68 ) ;
return false ;
}
return true ;
}
static inline bool F_209 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_219 ) ) )
return true ;
V_10 -> V_1 -> V_2 . V_410 = V_428 ;
V_10 -> V_17 . V_424 = true ;
return false ;
}
static void * F_210 ( struct V_7 * V_10 , T_2 V_429 , struct V_148 * * V_430 )
{
struct V_148 * V_148 ;
F_211 () ;
V_148 = F_212 ( V_10 -> V_9 . V_279 , V_429 >> V_119 ) ;
if ( F_213 ( V_148 ) )
goto error;
* V_430 = V_148 ;
return F_214 ( V_148 ) ;
error:
F_215 ( V_148 ) ;
F_205 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_216 ( struct V_148 * V_148 )
{
F_217 ( V_148 ) ;
F_218 ( V_148 ) ;
}
static int F_219 ( struct V_7 * V_10 )
{
unsigned V_397 ;
T_4 V_81 , V_6 ;
T_2 V_429 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_228 ) ) )
return V_431 ;
V_397 = V_10 -> V_1 -> V_2 . V_374 >> 16 ;
V_429 = V_10 -> V_17 . V_432 + ( V_397 / 8 ) ;
V_6 = V_397 % 8 ;
V_81 = 0 ;
if ( F_220 ( V_10 -> V_9 . V_279 , V_429 , & V_81 , 1 ) )
V_81 &= ( 1 << V_6 ) ;
return V_81 ? V_423 : V_431 ;
}
static int F_221 ( struct V_7 * V_10 )
{
T_1 V_27 , V_26 , V_370 ;
int V_134 , V_49 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return V_431 ;
V_26 = V_10 -> V_9 . V_23 . V_262 [ V_433 ] ;
V_27 = F_21 ( V_26 ) ;
V_134 = V_10 -> V_1 -> V_2 . V_374 & 1 ;
V_49 = 1 << ( ( 2 * ( V_26 & 0xf ) ) + V_134 ) ;
if ( V_27 == V_33 )
return V_423 ;
V_27 *= 4 ;
if ( F_220 ( V_10 -> V_9 . V_279 , V_10 -> V_17 . V_434 + V_27 , & V_370 , 4 ) )
return V_423 ;
return ( V_370 & V_49 ) ? V_423 : V_431 ;
}
static int F_222 ( struct V_7 * V_10 )
{
T_1 V_410 = V_10 -> V_1 -> V_2 . V_410 ;
switch ( V_410 ) {
case V_427 :
case V_428 :
case V_421 + V_217 :
return V_431 ;
case V_411 :
if ( V_39 )
return V_431 ;
break;
case V_421 + V_215 :
if ( ! V_39 && V_10 -> V_373 == 0 )
return V_431 ;
break;
case V_421 + V_390 :
F_175 ( V_10 ) ;
break;
default:
break;
}
return V_435 ;
}
static int F_206 ( struct V_7 * V_10 )
{
T_1 V_410 = V_10 -> V_1 -> V_2 . V_410 ;
int V_420 = V_431 ;
switch ( V_410 ) {
case V_436 :
V_420 = F_221 ( V_10 ) ;
break;
case V_437 :
V_420 = F_219 ( V_10 ) ;
break;
case V_438 ... V_439 : {
T_1 V_6 = 1U << ( V_410 - V_438 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_420 = V_423 ;
break;
}
case V_440 ... V_441 : {
T_1 V_6 = 1U << ( V_410 - V_440 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_420 = V_423 ;
break;
}
case V_421 ... V_421 + 0x1f : {
T_1 V_442 = 1 << ( V_410 - V_421 ) ;
if ( V_10 -> V_17 . V_21 & V_442 )
V_420 = V_423 ;
else if ( ( V_410 == V_421 + V_215 ) &&
V_10 -> V_373 != 0 )
V_420 = V_423 ;
break;
}
case V_443 : {
V_420 = V_423 ;
break;
}
default: {
T_2 V_444 = 1ULL << ( V_410 - V_427 ) ;
if ( V_10 -> V_17 . V_22 & V_444 )
V_420 = V_423 ;
}
}
return V_420 ;
}
static int F_223 ( struct V_7 * V_10 )
{
int V_420 ;
V_420 = F_206 ( V_10 ) ;
if ( V_420 == V_423 )
F_200 ( V_10 ) ;
return V_420 ;
}
static inline void F_224 ( struct V_1 * V_445 , struct V_1 * V_446 )
{
struct V_11 * V_447 = & V_445 -> V_2 ;
struct V_11 * V_448 = & V_446 -> V_2 ;
V_447 -> V_19 = V_448 -> V_19 ;
V_447 -> V_20 = V_448 -> V_20 ;
V_447 -> V_21 = V_448 -> V_21 ;
V_447 -> V_22 = V_448 -> V_22 ;
V_447 -> V_243 = V_448 -> V_243 ;
V_447 -> V_244 = V_448 -> V_244 ;
V_447 -> V_186 = V_448 -> V_186 ;
V_447 -> V_35 = V_448 -> V_35 ;
V_447 -> V_367 = V_448 -> V_367 ;
V_447 -> V_245 = V_448 -> V_245 ;
V_447 -> V_449 = V_448 -> V_449 ;
V_447 -> V_51 = V_448 -> V_51 ;
V_447 -> V_410 = V_448 -> V_410 ;
V_447 -> V_412 = V_448 -> V_412 ;
V_447 -> V_374 = V_448 -> V_374 ;
V_447 -> V_372 = V_448 -> V_372 ;
V_447 -> V_450 = V_448 -> V_450 ;
V_447 -> V_451 = V_448 -> V_451 ;
V_447 -> V_270 = V_448 -> V_270 ;
V_447 -> V_74 = V_448 -> V_74 ;
V_447 -> V_77 = V_448 -> V_77 ;
V_447 -> V_404 = V_448 -> V_404 ;
V_447 -> V_143 = V_448 -> V_143 ;
}
static int F_200 ( struct V_7 * V_10 )
{
struct V_1 * V_452 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_148 * V_148 ;
F_225 ( V_1 -> V_2 . V_410 ,
V_1 -> V_2 . V_374 ,
V_1 -> V_2 . V_372 ,
V_1 -> V_2 . V_450 ,
V_1 -> V_2 . V_451 ,
V_453 ) ;
V_452 = F_210 ( V_10 , V_10 -> V_17 . V_1 , & V_148 ) ;
if ( ! V_452 )
return 1 ;
F_226 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_452 -> V_42 . V_247 = V_1 -> V_42 . V_247 ;
V_452 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_452 -> V_42 . V_248 = V_1 -> V_42 . V_248 ;
V_452 -> V_42 . V_249 = V_1 -> V_42 . V_249 ;
V_452 -> V_42 . V_254 = V_1 -> V_42 . V_254 ;
V_452 -> V_42 . V_255 = V_1 -> V_42 . V_255 ;
V_452 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_452 -> V_42 . V_264 = F_227 ( & V_10 -> V_9 ) ;
V_452 -> V_42 . V_272 = F_136 ( & V_10 -> V_9 ) ;
V_452 -> V_42 . V_422 = V_1 -> V_42 . V_422 ;
V_452 -> V_42 . V_268 = V_10 -> V_9 . V_23 . V_268 ;
V_452 -> V_42 . V_308 = F_228 ( & V_10 -> V_9 ) ;
V_452 -> V_42 . V_68 = V_1 -> V_42 . V_68 ;
V_452 -> V_42 . V_454 = V_1 -> V_42 . V_454 ;
V_452 -> V_42 . V_455 = V_1 -> V_42 . V_455 ;
V_452 -> V_42 . V_261 = V_1 -> V_42 . V_261 ;
V_452 -> V_42 . V_260 = V_1 -> V_42 . V_260 ;
V_452 -> V_42 . V_307 = V_1 -> V_42 . V_307 ;
V_452 -> V_2 . V_245 = V_1 -> V_2 . V_245 ;
V_452 -> V_2 . V_449 = V_1 -> V_2 . V_449 ;
V_452 -> V_2 . V_51 = V_1 -> V_2 . V_51 ;
V_452 -> V_2 . V_410 = V_1 -> V_2 . V_410 ;
V_452 -> V_2 . V_412 = V_1 -> V_2 . V_412 ;
V_452 -> V_2 . V_374 = V_1 -> V_2 . V_374 ;
V_452 -> V_2 . V_372 = V_1 -> V_2 . V_372 ;
V_452 -> V_2 . V_450 = V_1 -> V_2 . V_450 ;
V_452 -> V_2 . V_451 = V_1 -> V_2 . V_451 ;
V_452 -> V_2 . V_55 = V_1 -> V_2 . V_55 ;
if ( V_1 -> V_2 . V_74 & V_47 ) {
struct V_11 * V_456 = & V_452 -> V_2 ;
V_456 -> V_450 = V_1 -> V_2 . V_74 ;
V_456 -> V_451 = V_1 -> V_2 . V_77 ;
}
V_452 -> V_2 . V_367 = 0 ;
V_452 -> V_2 . V_74 = 0 ;
V_452 -> V_2 . V_77 = 0 ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_425 ) )
V_452 -> V_2 . V_245 &= ~ V_246 ;
F_224 ( V_1 , V_18 ) ;
F_229 ( & V_10 -> V_9 ) ;
F_230 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_404 = 0 ;
V_10 -> V_1 -> V_42 . V_247 = V_18 -> V_42 . V_247 ;
V_10 -> V_1 -> V_42 . V_71 = V_18 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_248 = V_18 -> V_42 . V_248 ;
V_10 -> V_1 -> V_42 . V_249 = V_18 -> V_42 . V_249 ;
V_10 -> V_1 -> V_42 . V_254 = V_18 -> V_42 . V_254 ;
V_10 -> V_1 -> V_42 . V_255 = V_18 -> V_42 . V_255 ;
F_106 ( & V_10 -> V_9 , V_18 -> V_42 . V_308 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_42 . V_38 ) ;
F_151 ( & V_10 -> V_9 , V_18 -> V_42 . V_264 | V_457 ) ;
F_153 ( & V_10 -> V_9 , V_18 -> V_42 . V_268 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_272 = V_18 -> V_42 . V_272 ;
V_10 -> V_9 . V_23 . V_272 = V_18 -> V_42 . V_272 ;
} else {
( void ) F_231 ( & V_10 -> V_9 , V_18 -> V_42 . V_272 ) ;
}
F_232 ( & V_10 -> V_9 , V_458 , V_18 -> V_42 . V_455 ) ;
F_232 ( & V_10 -> V_9 , V_459 , V_18 -> V_42 . V_454 ) ;
F_232 ( & V_10 -> V_9 , V_263 , V_18 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_261 = 0 ;
V_10 -> V_1 -> V_42 . V_307 = 0 ;
V_10 -> V_1 -> V_2 . V_450 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_216 ( V_148 ) ;
F_203 ( & V_10 -> V_9 ) ;
F_233 ( & V_10 -> V_9 ) ;
F_234 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_235 ( struct V_7 * V_10 )
{
int V_28 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return true ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
T_1 V_370 , V_460 ;
T_2 V_27 ;
if ( V_142 [ V_28 ] == 0xffffffff )
break;
V_460 = V_142 [ V_28 ] ;
V_27 = V_10 -> V_17 . V_434 + ( V_460 * 4 ) ;
if ( F_220 ( V_10 -> V_9 . V_279 , V_27 , & V_370 , 4 ) )
return false ;
V_10 -> V_17 . V_132 [ V_460 ] = V_10 -> V_132 [ V_460 ] | V_370 ;
}
V_10 -> V_1 -> V_2 . V_244 = F_105 ( V_10 -> V_17 . V_132 ) ;
return true ;
}
static bool F_236 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_232 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_35 == 0 )
return false ;
if ( V_1 -> V_2 . V_270 && ! V_39 )
return false ;
return true ;
}
static bool F_237 ( struct V_7 * V_10 )
{
struct V_1 * V_452 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_148 * V_148 ;
T_2 V_461 ;
V_461 = V_10 -> V_1 -> V_42 . V_455 ;
V_452 = F_210 ( V_10 , V_10 -> V_1 -> V_42 . V_455 , & V_148 ) ;
if ( ! V_452 )
return false ;
if ( ! F_236 ( V_452 ) ) {
V_452 -> V_2 . V_410 = V_443 ;
V_452 -> V_2 . V_412 = 0 ;
V_452 -> V_2 . V_374 = 0 ;
V_452 -> V_2 . V_372 = 0 ;
F_216 ( V_148 ) ;
return false ;
}
F_238 ( V_10 -> V_1 -> V_42 . V_68 , V_461 ,
V_452 -> V_42 . V_68 ,
V_452 -> V_2 . V_245 ,
V_452 -> V_2 . V_74 ,
V_452 -> V_2 . V_270 ) ;
F_239 ( V_452 -> V_2 . V_19 & 0xffff ,
V_452 -> V_2 . V_19 >> 16 ,
V_452 -> V_2 . V_21 ,
V_452 -> V_2 . V_22 ) ;
F_229 ( & V_10 -> V_9 ) ;
F_230 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_247 = V_1 -> V_42 . V_247 ;
V_18 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_18 -> V_42 . V_248 = V_1 -> V_42 . V_248 ;
V_18 -> V_42 . V_249 = V_1 -> V_42 . V_249 ;
V_18 -> V_42 . V_254 = V_1 -> V_42 . V_254 ;
V_18 -> V_42 . V_255 = V_1 -> V_42 . V_255 ;
V_18 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_18 -> V_42 . V_264 = F_227 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_268 = V_10 -> V_9 . V_23 . V_268 ;
V_18 -> V_42 . V_308 = F_228 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_68 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_454 = V_1 -> V_42 . V_454 ;
V_18 -> V_42 . V_455 = V_1 -> V_42 . V_455 ;
if ( V_39 )
V_18 -> V_42 . V_272 = V_1 -> V_42 . V_272 ;
else
V_18 -> V_42 . V_272 = F_136 ( & V_10 -> V_9 ) ;
F_224 ( V_18 , V_1 ) ;
if ( F_228 ( & V_10 -> V_9 ) & V_462 )
V_10 -> V_9 . V_23 . V_24 |= V_426 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_426 ;
if ( V_452 -> V_2 . V_270 ) {
F_240 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_404 = V_452 -> V_2 . V_404 ;
F_201 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_42 . V_247 = V_452 -> V_42 . V_247 ;
V_10 -> V_1 -> V_42 . V_71 = V_452 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_248 = V_452 -> V_42 . V_248 ;
V_10 -> V_1 -> V_42 . V_249 = V_452 -> V_42 . V_249 ;
V_10 -> V_1 -> V_42 . V_254 = V_452 -> V_42 . V_254 ;
V_10 -> V_1 -> V_42 . V_255 = V_452 -> V_42 . V_255 ;
F_106 ( & V_10 -> V_9 , V_452 -> V_42 . V_308 ) ;
F_27 ( & V_10 -> V_9 , V_452 -> V_42 . V_38 ) ;
F_151 ( & V_10 -> V_9 , V_452 -> V_42 . V_264 ) ;
F_153 ( & V_10 -> V_9 , V_452 -> V_42 . V_268 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_272 = V_452 -> V_42 . V_272 ;
V_10 -> V_9 . V_23 . V_272 = V_452 -> V_42 . V_272 ;
} else
( void ) F_231 ( & V_10 -> V_9 , V_452 -> V_42 . V_272 ) ;
F_233 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_42 . V_422 = V_10 -> V_9 . V_23 . V_422 = V_452 -> V_42 . V_422 ;
F_232 ( & V_10 -> V_9 , V_458 , V_452 -> V_42 . V_455 ) ;
F_232 ( & V_10 -> V_9 , V_459 , V_452 -> V_42 . V_454 ) ;
F_232 ( & V_10 -> V_9 , V_263 , V_452 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_455 = V_452 -> V_42 . V_455 ;
V_10 -> V_1 -> V_42 . V_454 = V_452 -> V_42 . V_454 ;
V_10 -> V_1 -> V_42 . V_68 = V_452 -> V_42 . V_68 ;
V_10 -> V_1 -> V_42 . V_261 = V_452 -> V_42 . V_261 ;
V_10 -> V_1 -> V_42 . V_260 = V_452 -> V_42 . V_260 ;
V_10 -> V_1 -> V_42 . V_307 = V_452 -> V_42 . V_307 ;
V_10 -> V_17 . V_434 = V_452 -> V_2 . V_244 & ~ 0x0fffULL ;
V_10 -> V_17 . V_432 = V_452 -> V_2 . V_243 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_452 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_452 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_452 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_452 -> V_2 . V_22 ;
F_155 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_245 = V_452 -> V_2 . V_245 | V_246 ;
if ( V_452 -> V_2 . V_245 & V_246 )
V_10 -> V_9 . V_23 . V_24 |= V_425 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_425 ;
if ( V_10 -> V_9 . V_23 . V_24 & V_425 ) {
F_10 ( V_10 , V_463 ) ;
F_10 ( V_10 , V_198 ) ;
}
F_17 ( V_10 , V_233 ) ;
V_10 -> V_1 -> V_2 . V_143 = V_452 -> V_2 . V_143 ;
V_10 -> V_1 -> V_2 . V_449 = V_452 -> V_2 . V_449 ;
V_10 -> V_1 -> V_2 . V_51 = V_452 -> V_2 . V_51 ;
V_10 -> V_1 -> V_2 . V_186 += V_452 -> V_2 . V_186 ;
V_10 -> V_1 -> V_2 . V_74 = V_452 -> V_2 . V_74 ;
V_10 -> V_1 -> V_2 . V_77 = V_452 -> V_2 . V_77 ;
F_216 ( V_148 ) ;
F_241 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_461 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_242 ( struct V_1 * V_446 , struct V_1 * V_464 )
{
V_464 -> V_42 . V_250 = V_446 -> V_42 . V_250 ;
V_464 -> V_42 . V_251 = V_446 -> V_42 . V_251 ;
V_464 -> V_42 . V_258 = V_446 -> V_42 . V_258 ;
V_464 -> V_42 . V_256 = V_446 -> V_42 . V_256 ;
V_464 -> V_42 . V_465 = V_446 -> V_42 . V_465 ;
V_464 -> V_42 . V_466 = V_446 -> V_42 . V_466 ;
V_464 -> V_42 . V_467 = V_446 -> V_42 . V_467 ;
V_464 -> V_42 . V_468 = V_446 -> V_42 . V_468 ;
V_464 -> V_42 . V_469 = V_446 -> V_42 . V_469 ;
V_464 -> V_42 . V_470 = V_446 -> V_42 . V_470 ;
V_464 -> V_42 . V_471 = V_446 -> V_42 . V_471 ;
V_464 -> V_42 . V_472 = V_446 -> V_42 . V_472 ;
}
static int F_243 ( struct V_7 * V_10 )
{
struct V_1 * V_452 ;
struct V_148 * V_148 ;
if ( F_204 ( V_10 ) )
return 1 ;
V_452 = F_210 ( V_10 , V_10 -> V_1 -> V_42 . V_455 , & V_148 ) ;
if ( ! V_452 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_242 ( V_452 , V_10 -> V_1 ) ;
F_216 ( V_148 ) ;
return 1 ;
}
static int F_244 ( struct V_7 * V_10 )
{
struct V_1 * V_452 ;
struct V_148 * V_148 ;
if ( F_204 ( V_10 ) )
return 1 ;
V_452 = F_210 ( V_10 , V_10 -> V_1 -> V_42 . V_455 , & V_148 ) ;
if ( ! V_452 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_242 ( V_10 -> V_1 , V_452 ) ;
F_216 ( V_148 ) ;
return 1 ;
}
static int F_245 ( struct V_7 * V_10 )
{
if ( F_204 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_237 ( V_10 ) )
return 1 ;
if ( ! F_235 ( V_10 ) )
goto V_473;
return 1 ;
V_473:
V_10 -> V_1 -> V_2 . V_410 = V_443 ;
V_10 -> V_1 -> V_2 . V_412 = 0 ;
V_10 -> V_1 -> V_2 . V_374 = 0 ;
V_10 -> V_1 -> V_2 . V_372 = 0 ;
F_200 ( V_10 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
if ( F_204 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_181 ( V_474 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_247 ( struct V_7 * V_10 )
{
if ( F_204 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_138 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_475 ;
F_3 ( V_10 -> V_1 , V_476 ) ;
return 1 ;
}
static int F_248 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_249 ( V_10 -> V_1 -> V_42 . V_68 , V_9 -> V_23 . V_262 [ V_433 ] ,
V_9 -> V_23 . V_262 [ V_458 ] ) ;
F_250 ( V_9 , V_9 -> V_23 . V_262 [ V_458 ] ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_251 ( struct V_7 * V_10 )
{
F_252 ( V_10 -> V_1 -> V_42 . V_68 , V_10 -> V_9 . V_23 . V_262 [ V_458 ] ) ;
F_171 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static int F_253 ( struct V_7 * V_10 )
{
T_2 V_477 = F_254 ( & V_10 -> V_9 ) ;
T_1 V_130 = F_255 ( & V_10 -> V_9 , V_433 ) ;
if ( F_256 ( & V_10 -> V_9 , V_130 , V_477 ) == 0 ) {
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_257 ( struct V_7 * V_10 )
{
F_171 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static int F_258 ( struct V_7 * V_10 )
{
T_10 V_478 ;
int V_479 ;
int V_480 = V_10 -> V_1 -> V_2 . V_450 &
V_481 ;
int V_482 = V_10 -> V_1 -> V_2 . V_450 & V_483 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_450 & V_481 ;
T_7 V_484 =
V_10 -> V_1 -> V_2 . V_450 & V_485 ;
bool V_63 = false ;
T_1 V_64 = 0 ;
V_478 = ( T_10 ) V_10 -> V_1 -> V_2 . V_374 ;
if ( V_10 -> V_1 -> V_2 . V_372 &
( 1ULL << V_486 ) )
V_479 = V_487 ;
else if ( V_10 -> V_1 -> V_2 . V_372 &
( 1ULL << V_488 ) )
V_479 = V_489 ;
else if ( V_484 )
V_479 = V_490 ;
else
V_479 = V_491 ;
if ( V_479 == V_490 ) {
switch ( type ) {
case V_492 :
V_10 -> V_9 . V_23 . V_493 = false ;
break;
case V_494 :
if ( V_10 -> V_1 -> V_2 . V_372 &
( 1ULL << V_495 ) ) {
V_63 = true ;
V_64 =
( T_1 ) V_10 -> V_1 -> V_2 . V_372 ;
}
F_229 ( & V_10 -> V_9 ) ;
break;
case V_496 :
F_230 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_479 != V_490 ||
V_480 == V_497 ||
( V_480 == V_494 &&
( V_482 == V_498 || V_482 == V_66 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_480 != V_497 )
V_482 = - 1 ;
if ( F_259 ( & V_10 -> V_9 , V_478 , V_482 , V_479 ,
V_63 , V_64 ) == V_499 ) {
V_10 -> V_9 . V_380 -> V_383 = V_500 ;
V_10 -> V_9 . V_380 -> V_501 . V_502 = V_503 ;
V_10 -> V_9 . V_380 -> V_501 . V_504 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_260 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_261 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_262 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_302 . V_505 ;
F_17 ( V_10 , V_506 ) ;
V_10 -> V_9 . V_23 . V_24 |= V_507 ;
V_10 -> V_508 = F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_263 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_509 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
F_250 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_374 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_264 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
}
static int F_265 ( struct V_7 * V_10 )
{
int V_80 ;
if ( ! F_38 ( V_67 ) )
return F_264 ( V_10 ) ;
V_80 = F_266 ( & V_10 -> V_9 ) ;
F_267 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
bool F_268 ( struct V_7 * V_10 , unsigned long V_81 )
{
unsigned long V_264 = V_10 -> V_9 . V_23 . V_264 ;
bool V_50 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_221 ) ) ) )
return false ;
V_264 &= ~ V_346 ;
V_81 &= ~ V_346 ;
if ( V_264 ^ V_81 ) {
V_10 -> V_1 -> V_2 . V_410 = V_510 ;
V_50 = ( F_223 ( V_10 ) == V_423 ) ;
}
return V_50 ;
}
static int F_269 ( struct V_7 * V_10 )
{
int V_312 , V_511 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_38 ( V_509 ) )
return F_264 ( V_10 ) ;
if ( F_122 ( ( V_10 -> V_1 -> V_2 . V_374 & V_512 ) == 0 ) )
return F_264 ( V_10 ) ;
V_312 = V_10 -> V_1 -> V_2 . V_374 & V_513 ;
V_511 = V_10 -> V_1 -> V_2 . V_410 - V_438 ;
V_80 = 0 ;
if ( V_511 >= 16 ) {
V_511 -= 16 ;
V_81 = F_255 ( & V_10 -> V_9 , V_312 ) ;
switch ( V_511 ) {
case 0 :
if ( ! F_268 ( V_10 , V_81 ) )
V_80 = F_107 ( & V_10 -> V_9 , V_81 ) ;
else
return 1 ;
break;
case 3 :
V_80 = F_231 ( & V_10 -> V_9 , V_81 ) ;
break;
case 4 :
V_80 = F_270 ( & V_10 -> V_9 , V_81 ) ;
break;
case 8 :
V_80 = F_271 ( & V_10 -> V_9 , V_81 ) ;
break;
default:
F_97 ( 1 , L_12 , V_511 ) ;
F_171 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
} else {
switch ( V_511 ) {
case 0 :
V_81 = F_227 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_81 = V_10 -> V_9 . V_23 . V_422 ;
break;
case 3 :
V_81 = F_136 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_81 = F_272 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_81 = F_273 ( & V_10 -> V_9 ) ;
break;
default:
F_97 ( 1 , L_13 , V_511 ) ;
F_171 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
F_232 ( & V_10 -> V_9 , V_312 , V_81 ) ;
}
F_267 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
static int F_274 ( struct V_7 * V_10 )
{
int V_312 , V_514 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_83 ( V_509 ) )
return F_264 ( V_10 ) ;
V_312 = V_10 -> V_1 -> V_2 . V_374 & V_513 ;
V_514 = V_10 -> V_1 -> V_2 . V_410 - V_440 ;
if ( V_514 >= 16 ) {
V_81 = F_255 ( & V_10 -> V_9 , V_312 ) ;
F_275 ( & V_10 -> V_9 , V_514 - 16 , V_81 ) ;
} else {
V_80 = F_276 ( & V_10 -> V_9 , V_514 , & V_81 ) ;
if ( ! V_80 )
F_232 ( & V_10 -> V_9 , V_312 , V_81 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_277 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
int V_126 ;
T_4 V_515 = F_273 ( & V_10 -> V_9 ) ;
V_126 = F_269 ( V_10 ) ;
if ( F_278 ( V_10 -> V_9 . V_279 ) ) {
F_10 ( V_10 , V_198 ) ;
return V_126 ;
}
if ( V_515 <= F_273 ( & V_10 -> V_9 ) )
return V_126 ;
V_379 -> V_383 = V_516 ;
return 0 ;
}
T_2 F_279 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_186 +
F_95 ( V_9 , F_103 () ) ;
}
static int F_280 ( struct V_8 * V_9 , unsigned V_517 , T_2 * V_518 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_517 ) {
case V_519 : {
* V_518 = V_10 -> V_1 -> V_2 . V_186 +
F_95 ( V_9 , F_103 () ) ;
break;
}
case V_520 :
* V_518 = V_10 -> V_1 -> V_42 . V_466 ;
break;
#ifdef F_26
case V_521 :
* V_518 = V_10 -> V_1 -> V_42 . V_467 ;
break;
case V_522 :
* V_518 = V_10 -> V_1 -> V_42 . V_468 ;
break;
case V_304 :
* V_518 = V_10 -> V_1 -> V_42 . V_465 ;
break;
case V_523 :
* V_518 = V_10 -> V_1 -> V_42 . V_469 ;
break;
#endif
case V_524 :
* V_518 = V_10 -> V_1 -> V_42 . V_470 ;
break;
case V_525 :
* V_518 = V_10 -> V_472 ;
break;
case V_526 :
* V_518 = V_10 -> V_471 ;
break;
case V_527 :
* V_518 = V_10 -> V_1 -> V_42 . V_528 ;
break;
case V_144 :
* V_518 = V_10 -> V_1 -> V_42 . V_529 ;
break;
case V_145 :
* V_518 = V_10 -> V_1 -> V_42 . V_530 ;
break;
case V_146 :
* V_518 = V_10 -> V_1 -> V_42 . V_531 ;
break;
case V_147 :
* V_518 = V_10 -> V_1 -> V_42 . V_532 ;
break;
case V_117 :
* V_518 = V_10 -> V_17 . V_533 ;
break;
case V_534 :
* V_518 = V_10 -> V_17 . V_535 ;
break;
case V_536 :
* V_518 = 0x01000065 ;
break;
default:
return F_281 ( V_9 , V_517 , V_518 ) ;
}
return 0 ;
}
static int F_282 ( struct V_7 * V_10 )
{
T_1 V_517 = V_10 -> V_9 . V_23 . V_262 [ V_433 ] ;
T_2 V_518 ;
if ( F_280 ( & V_10 -> V_9 , V_517 , & V_518 ) ) {
F_283 ( V_517 ) ;
F_205 ( & V_10 -> V_9 , 0 ) ;
} else {
F_284 ( V_517 , V_518 ) ;
V_10 -> V_9 . V_23 . V_262 [ V_458 ] = V_518 & 0xffffffff ;
V_10 -> V_9 . V_23 . V_262 [ V_537 ] = V_518 >> 32 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_285 ( struct V_8 * V_9 , T_2 V_518 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_538 , V_539 ;
if ( V_518 & ~ V_540 )
return 1 ;
V_539 = V_540 ;
if ( V_10 -> V_17 . V_535 & V_541 )
V_539 &= ~ ( V_542 | V_541 ) ;
V_10 -> V_17 . V_535 &= ~ V_539 ;
V_10 -> V_17 . V_535 |= ( V_518 & V_539 ) ;
V_538 = V_10 -> V_17 . V_535 & V_541 ;
if ( V_538 && ( V_9 -> V_23 . V_38 & V_43 ) )
return 1 ;
return 0 ;
}
static int F_286 ( struct V_8 * V_9 , unsigned V_517 , T_2 V_518 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_517 ) {
case V_519 :
F_114 ( V_9 , V_518 ) ;
break;
case V_520 :
V_10 -> V_1 -> V_42 . V_466 = V_518 ;
break;
#ifdef F_26
case V_521 :
V_10 -> V_1 -> V_42 . V_467 = V_518 ;
break;
case V_522 :
V_10 -> V_1 -> V_42 . V_468 = V_518 ;
break;
case V_304 :
V_10 -> V_1 -> V_42 . V_465 = V_518 ;
break;
case V_523 :
V_10 -> V_1 -> V_42 . V_469 = V_518 ;
break;
#endif
case V_524 :
V_10 -> V_1 -> V_42 . V_470 = V_518 ;
break;
case V_525 :
V_10 -> V_472 = V_518 ;
V_10 -> V_1 -> V_42 . V_472 = V_518 ;
break;
case V_526 :
V_10 -> V_471 = V_518 ;
V_10 -> V_1 -> V_42 . V_471 = V_518 ;
break;
case V_527 :
if ( ! F_83 ( V_543 ) ) {
F_287 ( V_9 , L_14 ,
V_59 , V_518 ) ;
break;
}
if ( V_518 & V_544 )
return 1 ;
V_10 -> V_1 -> V_42 . V_528 = V_518 ;
F_3 ( V_10 -> V_1 , V_545 ) ;
if ( V_518 & ( 1ULL << 0 ) )
F_78 ( V_10 ) ;
else
F_79 ( V_10 ) ;
break;
case V_117 :
V_10 -> V_17 . V_533 = V_518 ;
break;
case V_534 :
return F_285 ( V_9 , V_518 ) ;
case V_546 :
F_287 ( V_9 , L_15 , V_517 , V_518 ) ;
break;
default:
return F_288 ( V_9 , V_517 , V_518 ) ;
}
return 0 ;
}
static int F_289 ( struct V_7 * V_10 )
{
T_1 V_517 = V_10 -> V_9 . V_23 . V_262 [ V_433 ] ;
T_2 V_518 = ( V_10 -> V_9 . V_23 . V_262 [ V_458 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_23 . V_262 [ V_537 ] & - 1u ) << 32 ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_286 ( & V_10 -> V_9 , V_517 , V_518 ) ) {
F_290 ( V_517 , V_518 ) ;
F_205 ( & V_10 -> V_9 , 0 ) ;
} else {
F_291 ( V_517 , V_518 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_292 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_374 )
return F_289 ( V_10 ) ;
else
return F_282 ( V_10 ) ;
}
static int F_293 ( struct V_7 * V_10 )
{
struct V_379 * V_379 = V_10 -> V_9 . V_380 ;
F_181 ( V_474 , & V_10 -> V_9 ) ;
F_138 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_475 ;
F_3 ( V_10 -> V_1 , V_476 ) ;
++ V_10 -> V_9 . V_302 . V_547 ;
if ( ! F_278 ( V_10 -> V_9 . V_279 ) &&
V_379 -> V_548 &&
! F_294 ( & V_10 -> V_9 ) ) {
V_379 -> V_383 = V_549 ;
return 0 ;
}
return 1 ;
}
static int F_295 ( struct V_7 * V_10 )
{
F_296 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static void F_297 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_190 * V_42 = & V_10 -> V_1 -> V_42 ;
F_180 ( L_16 ) ;
F_180 ( L_17 , L_18 , V_2 -> V_19 & 0xffff ) ;
F_180 ( L_17 , L_19 , V_2 -> V_19 >> 16 ) ;
F_180 ( L_17 , L_20 , V_2 -> V_20 & 0xffff ) ;
F_180 ( L_17 , L_21 , V_2 -> V_20 >> 16 ) ;
F_180 ( L_22 , L_23 , V_2 -> V_21 ) ;
F_180 ( L_24 , L_25 , V_2 -> V_22 ) ;
F_180 ( L_26 , L_27 , V_2 -> V_274 ) ;
F_180 ( L_24 , L_28 , V_2 -> V_243 ) ;
F_180 ( L_24 , L_29 , V_2 -> V_244 ) ;
F_180 ( L_24 , L_30 , V_2 -> V_186 ) ;
F_180 ( L_26 , L_31 , V_2 -> V_35 ) ;
F_180 ( L_26 , L_32 , V_2 -> V_367 ) ;
F_180 ( L_22 , L_33 , V_2 -> V_245 ) ;
F_180 ( L_22 , L_34 , V_2 -> V_449 ) ;
F_180 ( L_22 , L_35 , V_2 -> V_51 ) ;
F_180 ( L_22 , L_36 , V_2 -> V_410 ) ;
F_180 ( L_24 , L_37 , V_2 -> V_374 ) ;
F_180 ( L_24 , L_38 , V_2 -> V_372 ) ;
F_180 ( L_22 , L_39 , V_2 -> V_450 ) ;
F_180 ( L_22 , L_40 , V_2 -> V_451 ) ;
F_180 ( L_41 , L_42 , V_2 -> V_270 ) ;
F_180 ( L_24 , L_43 , V_2 -> V_404 ) ;
F_180 ( L_22 , L_44 , V_2 -> V_74 ) ;
F_180 ( L_22 , L_45 , V_2 -> V_77 ) ;
F_180 ( L_41 , L_46 , V_2 -> V_143 ) ;
F_180 ( L_24 , L_47 , V_2 -> V_55 ) ;
F_180 ( L_48 ) ;
F_180 ( L_49 ,
L_50 ,
V_42 -> V_247 . V_167 , V_42 -> V_247 . V_168 ,
V_42 -> V_247 . V_172 , V_42 -> V_247 . V_72 ) ;
F_180 ( L_49 ,
L_51 ,
V_42 -> V_71 . V_167 , V_42 -> V_71 . V_168 ,
V_42 -> V_71 . V_172 , V_42 -> V_71 . V_72 ) ;
F_180 ( L_49 ,
L_52 ,
V_42 -> V_248 . V_167 , V_42 -> V_248 . V_168 ,
V_42 -> V_248 . V_172 , V_42 -> V_248 . V_72 ) ;
F_180 ( L_49 ,
L_53 ,
V_42 -> V_249 . V_167 , V_42 -> V_249 . V_168 ,
V_42 -> V_249 . V_172 , V_42 -> V_249 . V_72 ) ;
F_180 ( L_49 ,
L_54 ,
V_42 -> V_250 . V_167 , V_42 -> V_250 . V_168 ,
V_42 -> V_250 . V_172 , V_42 -> V_250 . V_72 ) ;
F_180 ( L_49 ,
L_55 ,
V_42 -> V_251 . V_167 , V_42 -> V_251 . V_168 ,
V_42 -> V_251 . V_172 , V_42 -> V_251 . V_72 ) ;
F_180 ( L_49 ,
L_56 ,
V_42 -> V_254 . V_167 , V_42 -> V_254 . V_168 ,
V_42 -> V_254 . V_172 , V_42 -> V_254 . V_72 ) ;
F_180 ( L_49 ,
L_57 ,
V_42 -> V_256 . V_167 , V_42 -> V_256 . V_168 ,
V_42 -> V_256 . V_172 , V_42 -> V_256 . V_72 ) ;
F_180 ( L_49 ,
L_58 ,
V_42 -> V_255 . V_167 , V_42 -> V_255 . V_168 ,
V_42 -> V_255 . V_172 , V_42 -> V_255 . V_72 ) ;
F_180 ( L_49 ,
L_59 ,
V_42 -> V_258 . V_167 , V_42 -> V_258 . V_168 ,
V_42 -> V_258 . V_172 , V_42 -> V_258 . V_72 ) ;
F_180 ( L_60 ,
V_42 -> V_307 , V_42 -> V_38 ) ;
F_180 ( L_61 ,
L_62 , V_42 -> V_264 , L_63 , V_42 -> V_422 ) ;
F_180 ( L_61 ,
L_64 , V_42 -> V_272 , L_65 , V_42 -> V_268 ) ;
F_180 ( L_61 ,
L_66 , V_42 -> V_260 , L_67 , V_42 -> V_261 ) ;
F_180 ( L_61 ,
L_68 , V_42 -> V_68 , L_69 , V_42 -> V_308 ) ;
F_180 ( L_61 ,
L_70 , V_42 -> V_454 , L_71 , V_42 -> V_455 ) ;
F_180 ( L_61 ,
L_72 , V_42 -> V_466 , L_73 , V_42 -> V_467 ) ;
F_180 ( L_61 ,
L_74 , V_42 -> V_468 , L_75 , V_42 -> V_469 ) ;
F_180 ( L_61 ,
L_76 , V_42 -> V_465 ,
L_77 , V_42 -> V_470 ) ;
F_180 ( L_61 ,
L_78 , V_42 -> V_471 ,
L_79 , V_42 -> V_472 ) ;
F_180 ( L_61 ,
L_80 , V_42 -> V_271 , L_81 , V_42 -> V_528 ) ;
F_180 ( L_61 ,
L_82 , V_42 -> V_529 , L_83 , V_42 -> V_530 ) ;
F_180 ( L_61 ,
L_84 , V_42 -> V_531 ,
L_85 , V_42 -> V_532 ) ;
}
static void F_298 ( struct V_8 * V_9 , T_2 * V_550 , T_2 * V_551 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_550 = V_2 -> V_374 ;
* V_551 = V_2 -> V_372 ;
}
static int F_299 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_379 * V_379 = V_9 -> V_380 ;
T_1 V_410 = V_10 -> V_1 -> V_2 . V_410 ;
if ( ! F_11 ( V_10 , V_195 ) )
V_9 -> V_23 . V_264 = V_10 -> V_1 -> V_42 . V_264 ;
if ( V_39 )
V_9 -> V_23 . V_272 = V_10 -> V_1 -> V_42 . V_272 ;
if ( F_122 ( V_10 -> V_17 . V_424 ) ) {
F_200 ( V_10 ) ;
V_10 -> V_17 . V_424 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_420 ;
F_300 ( V_10 -> V_1 -> V_42 . V_68 , V_410 ,
V_10 -> V_1 -> V_2 . V_374 ,
V_10 -> V_1 -> V_2 . V_372 ,
V_10 -> V_1 -> V_2 . V_450 ,
V_10 -> V_1 -> V_2 . V_451 ,
V_453 ) ;
V_420 = F_222 ( V_10 ) ;
if ( V_420 == V_435 )
V_420 = F_223 ( V_10 ) ;
if ( V_420 == V_423 )
return 1 ;
}
F_301 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_410 == V_443 ) {
V_379 -> V_383 = V_552 ;
V_379 -> V_553 . V_554
= V_10 -> V_1 -> V_2 . V_410 ;
F_180 ( L_86 ) ;
F_297 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_450 ) &&
V_410 != V_421 + V_215 &&
V_410 != V_411 && V_410 != V_555 &&
V_410 != V_427 && V_410 != V_428 )
F_33 ( V_61 L_87
L_88 ,
V_59 , V_10 -> V_1 -> V_2 . V_450 ,
V_410 ) ;
if ( V_410 >= F_302 ( V_556 )
|| ! V_556 [ V_410 ] ) {
V_379 -> V_383 = V_557 ;
V_379 -> V_558 . V_559 = V_410 ;
return 0 ;
}
return V_556 [ V_410 ] ( V_10 ) ;
}
static void F_303 ( struct V_8 * V_9 )
{
int V_125 = F_53 () ;
struct V_98 * V_99 = F_55 ( V_108 , V_125 ) ;
V_99 -> V_114 -> type = 9 ;
F_304 () ;
}
static void F_305 ( struct V_7 * V_10 )
{
int V_125 = F_53 () ;
struct V_98 * V_99 = F_55 ( V_108 , V_125 ) ;
if ( V_10 -> V_109 != V_99 -> V_109 )
F_159 ( V_10 , V_99 ) ;
}
static void F_306 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_74 = V_47 | V_560 ;
V_9 -> V_23 . V_24 |= V_561 ;
F_16 ( V_10 , V_506 ) ;
++ V_9 -> V_302 . V_562 ;
}
static inline void F_307 ( struct V_7 * V_10 , int V_563 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_449 = V_563 ;
V_2 -> V_245 &= ~ V_564 ;
V_2 -> V_245 |= V_475 |
( ( 0xf ) << V_565 ) ;
F_3 ( V_10 -> V_1 , V_476 ) ;
}
static void F_308 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_71 ( ! ( F_20 ( V_10 ) ) ) ;
F_309 ( V_9 -> V_23 . V_566 . V_62 ) ;
++ V_9 -> V_302 . V_567 ;
V_10 -> V_1 -> V_2 . V_74 = V_9 -> V_23 . V_566 . V_62 |
V_47 | V_48 ;
}
static void F_310 ( struct V_8 * V_9 , int V_568 , int V_569 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_425 ) )
return;
if ( V_569 == - 1 )
return;
if ( V_568 >= V_569 )
F_9 ( V_10 , V_198 ) ;
}
static int F_311 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
V_50 = ! ( V_1 -> V_2 . V_51 & V_52 ) &&
! ( V_10 -> V_9 . V_23 . V_24 & V_561 ) ;
V_50 = V_50 && F_20 ( V_10 ) && F_209 ( V_10 ) ;
return V_50 ;
}
static bool F_312 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_561 ) ;
}
static void F_313 ( struct V_8 * V_9 , bool V_570 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_570 ) {
V_10 -> V_9 . V_23 . V_24 |= V_561 ;
F_16 ( V_10 , V_506 ) ;
} else {
V_10 -> V_9 . V_23 . V_24 &= ~ V_561 ;
F_17 ( V_10 , V_506 ) ;
}
}
static int F_314 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_51 & V_52 ) )
return 0 ;
V_50 = ! ! ( F_228 ( V_9 ) & V_462 ) ;
if ( F_7 ( V_9 ) )
return V_50 && ! ( V_10 -> V_9 . V_23 . V_24 & V_425 ) ;
return V_50 ;
}
static void F_315 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_207 ( V_10 ) ) {
F_137 ( V_10 ) ;
F_307 ( V_10 , 0x0 ) ;
}
}
static void F_316 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_23 . V_24 & ( V_561 | V_507 ) )
== V_561 )
return;
V_10 -> V_357 = true ;
V_10 -> V_1 -> V_42 . V_308 |= ( V_381 | V_382 ) ;
F_157 ( V_9 ) ;
}
static int F_317 ( struct V_279 * V_279 , unsigned int V_34 )
{
return 0 ;
}
static void F_155 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_571 ) )
V_10 -> V_1 -> V_2 . V_367 = V_572 ;
else
V_10 -> V_109 -- ;
}
static void F_318 ( struct V_8 * V_9 )
{
}
static inline void F_319 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_425 ) )
return;
if ( ! F_11 ( V_10 , V_198 ) ) {
int V_573 = V_10 -> V_1 -> V_2 . V_245 & V_574 ;
F_271 ( V_9 , V_573 ) ;
}
}
static inline void F_320 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_573 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_425 ) )
return;
V_573 = F_273 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_574 ;
V_10 -> V_1 -> V_2 . V_245 |= V_573 & V_574 ;
}
static void F_301 ( struct V_7 * V_10 )
{
T_4 V_575 ;
int type ;
T_1 V_576 = V_10 -> V_1 -> V_2 . V_450 ;
unsigned V_73 = V_10 -> V_73 ;
V_10 -> V_73 = 0 ;
if ( ( V_10 -> V_9 . V_23 . V_24 & V_507 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_508 ) {
V_10 -> V_9 . V_23 . V_24 &= ~ ( V_561 | V_507 ) ;
F_181 ( V_474 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_23 . V_493 = false ;
F_229 ( & V_10 -> V_9 ) ;
F_230 ( & V_10 -> V_9 ) ;
if ( ! ( V_576 & V_485 ) )
return;
F_181 ( V_474 , & V_10 -> V_9 ) ;
V_575 = V_576 & V_577 ;
type = V_576 & V_481 ;
switch ( type ) {
case V_492 :
V_10 -> V_9 . V_23 . V_493 = true ;
break;
case V_494 :
if ( F_321 ( V_575 ) ) {
if ( V_575 == V_66 && V_73 &&
F_322 ( & V_10 -> V_9 , V_10 -> V_70 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_73 ) ;
break;
}
if ( V_576 & V_578 ) {
T_1 V_80 = V_10 -> V_1 -> V_2 . V_451 ;
F_323 ( & V_10 -> V_9 , V_575 , V_80 ) ;
} else
F_324 ( & V_10 -> V_9 , V_575 ) ;
break;
case V_496 :
F_325 ( & V_10 -> V_9 , V_575 , false ) ;
break;
default:
break;
}
}
static void F_326 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_450 = V_2 -> V_74 ;
V_2 -> V_451 = V_2 -> V_77 ;
V_2 -> V_74 = 0 ;
F_301 ( V_10 ) ;
}
static void F_327 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_455 = V_9 -> V_23 . V_262 [ V_458 ] ;
V_10 -> V_1 -> V_42 . V_454 = V_9 -> V_23 . V_262 [ V_459 ] ;
V_10 -> V_1 -> V_42 . V_68 = V_9 -> V_23 . V_262 [ V_263 ] ;
if ( F_122 ( V_10 -> V_17 . V_424 ) )
return;
F_305 ( V_10 ) ;
F_320 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_422 = V_9 -> V_23 . V_422 ;
F_22 () ;
F_168 () ;
asm volatile (
"push %%"R"bp; \n\t"
"mov %c[rbx](%[svm]), %%"R"bx \n\t"
"mov %c[rcx](%[svm]), %%"R"cx \n\t"
"mov %c[rdx](%[svm]), %%"R"dx \n\t"
"mov %c[rsi](%[svm]), %%"R"si \n\t"
"mov %c[rdi](%[svm]), %%"R"di \n\t"
"mov %c[rbp](%[svm]), %%"R"bp \n\t"
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
"push %%"R"ax \n\t"
"mov %c[vmcb](%[svm]), %%"R"ax \n\t"
__ex(SVM_VMLOAD) "\n\t"
__ex(SVM_VMRUN) "\n\t"
__ex(SVM_VMSAVE) "\n\t"
"pop %%"R"ax \n\t"
"mov %%"R"bx, %c[rbx](%[svm]) \n\t"
"mov %%"R"cx, %c[rcx](%[svm]) \n\t"
"mov %%"R"dx, %c[rdx](%[svm]) \n\t"
"mov %%"R"si, %c[rsi](%[svm]) \n\t"
"mov %%"R"di, %c[rdi](%[svm]) \n\t"
"mov %%"R"bp, %c[rbp](%[svm]) \n\t"
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
"pop %%"R"bp"
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
, R"bx", R"cx", R"dx", R"si", R"di"
#ifdef F_26
, "r8", "r9", "r10", "r11" , "r12", "r13", "r14", "r15"
#endif
);
#ifdef F_26
F_49 ( V_296 , V_10 -> V_188 . V_297 ) ;
#else
F_127 ( V_250 , V_10 -> V_188 . V_250 ) ;
#ifndef F_129
F_127 ( V_251 , V_10 -> V_188 . V_251 ) ;
#endif
#endif
F_303 ( V_9 ) ;
F_166 () ;
V_9 -> V_23 . V_422 = V_10 -> V_1 -> V_42 . V_422 ;
V_9 -> V_23 . V_262 [ V_458 ] = V_10 -> V_1 -> V_42 . V_455 ;
V_9 -> V_23 . V_262 [ V_459 ] = V_10 -> V_1 -> V_42 . V_454 ;
V_9 -> V_23 . V_262 [ V_263 ] = V_10 -> V_1 -> V_42 . V_68 ;
F_328 ( V_10 -> V_1 -> V_2 . V_410 , V_9 , V_453 ) ;
if ( F_122 ( V_10 -> V_1 -> V_2 . V_410 == V_428 ) )
F_329 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_122 ( V_10 -> V_1 -> V_2 . V_410 == V_428 ) )
F_330 ( & V_10 -> V_9 ) ;
F_319 ( V_9 ) ;
V_10 -> V_55 = 0 ;
V_10 -> V_1 -> V_2 . V_367 = V_579 ;
if ( V_10 -> V_1 -> V_2 . V_410 == V_421 + V_215 )
V_10 -> V_373 = F_331 () ;
if ( V_39 ) {
V_9 -> V_23 . V_277 &= ~ ( 1 << V_313 ) ;
V_9 -> V_23 . V_278 &= ~ ( 1 << V_313 ) ;
}
if ( F_122 ( V_10 -> V_1 -> V_2 . V_410 ==
V_421 + V_217 ) )
F_179 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_332 ( struct V_8 * V_9 , unsigned long V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_272 = V_406 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_155 ( V_9 ) ;
}
static void F_333 ( struct V_8 * V_9 , unsigned long V_406 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_404 = V_406 ;
F_3 ( V_10 -> V_1 , V_407 ) ;
V_10 -> V_1 -> V_42 . V_272 = F_136 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_155 ( V_9 ) ;
}
static int F_334 ( void )
{
T_2 V_580 ;
F_54 ( V_534 , V_580 ) ;
if ( V_580 & ( 1 << V_581 ) )
return 1 ;
return 0 ;
}
static void
F_335 ( struct V_8 * V_9 , unsigned char * V_582 )
{
V_582 [ 0 ] = 0x0f ;
V_582 [ 1 ] = 0x01 ;
V_582 [ 2 ] = 0xd9 ;
}
static void F_336 ( void * V_583 )
{
* ( int * ) V_583 = 0 ;
}
static bool F_337 ( void )
{
return false ;
}
static T_2 F_338 ( struct V_8 * V_9 , T_11 V_584 , bool V_585 )
{
return 0 ;
}
static void F_339 ( struct V_8 * V_9 )
{
}
static void F_340 ( T_1 V_586 , struct V_587 * V_588 )
{
switch ( V_586 ) {
case 0x80000001 :
if ( V_17 )
V_588 -> V_517 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_588 -> V_589 = 1 ;
V_588 -> V_590 = 8 ;
V_588 -> V_517 = 0 ;
V_588 -> V_591 = 0 ;
if ( F_83 ( V_67 ) )
V_588 -> V_591 |= V_592 ;
if ( V_39 )
V_588 -> V_591 |= V_593 ;
break;
}
}
static int F_341 ( void )
{
return V_594 ;
}
static bool F_342 ( void )
{
return false ;
}
static bool F_343 ( void )
{
return false ;
}
static bool F_344 ( void )
{
return true ;
}
static void F_345 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_390 ) ;
F_150 ( V_10 ) ;
}
static int F_346 ( struct V_8 * V_9 ,
struct V_595 * V_45 ,
enum V_596 V_597 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_420 , V_50 = V_598 ;
struct V_599 V_600 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_45 -> V_22 >= F_302 ( V_601 ) )
goto V_285;
V_600 = V_601 [ V_45 -> V_22 ] ;
if ( V_597 != V_600 . V_597 )
goto V_285;
switch ( V_600 . V_410 ) {
case V_438 :
if ( V_45 -> V_22 == V_602 )
V_600 . V_410 += V_45 -> V_603 ;
break;
case V_604 : {
unsigned long V_264 , V_81 ;
T_2 V_22 ;
if ( V_45 -> V_22 == V_605 )
V_600 . V_410 += V_45 -> V_603 ;
if ( V_600 . V_410 != V_604 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_221 ) ) )
break;
V_264 = V_9 -> V_23 . V_264 & ~ V_346 ;
V_81 = V_45 -> V_606 & ~ V_346 ;
if ( V_45 -> V_22 == V_607 ) {
V_264 &= 0xfUL ;
V_81 &= 0xfUL ;
if ( V_264 & V_457 )
V_81 |= V_457 ;
}
if ( V_264 ^ V_81 )
V_600 . V_410 = V_510 ;
break;
}
case V_440 :
case V_608 :
V_600 . V_410 += V_45 -> V_603 ;
break;
case V_436 :
if ( V_45 -> V_22 == V_609 )
V_1 -> V_2 . V_374 = 1 ;
else
V_1 -> V_2 . V_374 = 0 ;
break;
case V_610 :
if ( V_45 -> V_611 != V_612 )
goto V_285;
case V_437 : {
T_2 V_613 ;
T_1 V_614 ;
V_613 = ( V_9 -> V_23 . V_262 [ V_537 ] & 0xffff ) << 16 ;
if ( V_45 -> V_22 == V_615 ||
V_45 -> V_22 == V_616 ) {
V_613 |= V_400 ;
V_614 = V_45 -> V_617 ;
} else {
V_614 = V_45 -> V_618 ;
}
if ( V_45 -> V_22 == V_619 ||
V_45 -> V_22 == V_616 )
V_613 |= V_399 ;
if ( V_45 -> V_611 )
V_613 |= V_620 ;
V_614 = F_85 ( V_614 , 4u ) ;
V_613 |= V_614 << V_402 ;
V_613 |= ( T_1 ) V_45 -> V_621 << ( V_622 - 1 ) ;
V_1 -> V_2 . V_374 = V_613 ;
V_1 -> V_2 . V_372 = V_45 -> V_55 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_55 = V_45 -> V_55 ;
V_1 -> V_2 . V_410 = V_600 . V_410 ;
V_420 = F_223 ( V_10 ) ;
V_50 = ( V_420 == V_423 ) ? V_623
: V_598 ;
V_285:
return V_50 ;
}
static int T_5 F_347 ( void )
{
return F_348 ( & V_624 , sizeof( struct V_7 ) ,
F_349 ( struct V_7 ) , V_625 ) ;
}
static void T_6 F_350 ( void )
{
F_351 () ;
}
