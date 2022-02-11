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
F_55 ( L_4 , V_59 , V_104 ) ;
return - V_107 ;
}
V_99 = F_56 ( V_108 , V_104 ) ;
if ( ! V_99 ) {
F_55 ( L_5 , V_59 , V_104 ) ;
return - V_107 ;
}
V_99 -> V_109 = 1 ;
V_99 -> V_110 = F_57 ( V_111 ) - 1 ;
V_99 -> V_112 = V_99 -> V_110 + 1 ;
F_58 ( & V_101 ) ;
V_103 = (struct V_102 * ) V_101 . V_113 ;
V_99 -> V_114 = (struct V_115 * ) ( V_103 + V_116 ) ;
F_49 ( V_105 , V_38 | V_43 ) ;
F_49 ( V_117 , F_59 ( V_99 -> V_118 ) << V_119 ) ;
if ( F_38 ( V_95 ) ) {
F_49 ( V_96 , V_97 ) ;
F_60 ( V_120 ) = V_97 ;
}
if ( F_61 ( & V_90 , V_121 ) ) {
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
F_62 () ;
return 0 ;
}
static void F_63 ( int V_125 )
{
struct V_98 * V_99 = F_56 ( V_108 , F_53 () ) ;
if ( ! V_99 )
return;
F_56 ( V_108 , F_53 () ) = NULL ;
F_64 ( V_99 -> V_118 ) ;
F_65 ( V_99 ) ;
}
static int F_66 ( int V_125 )
{
struct V_98 * V_99 ;
int V_126 ;
V_99 = F_67 ( sizeof( struct V_98 ) , V_127 ) ;
if ( ! V_99 )
return - V_128 ;
V_99 -> V_125 = V_125 ;
V_99 -> V_118 = F_68 ( V_127 ) ;
V_126 = - V_128 ;
if ( ! V_99 -> V_118 )
goto V_129;
F_56 ( V_108 , V_125 ) = V_99 ;
return 0 ;
V_129:
F_65 ( V_99 ) ;
return V_126 ;
}
static bool F_69 ( T_1 V_130 )
{
int V_28 ;
for ( V_28 = 0 ; V_131 [ V_28 ] . V_130 != V_33 ; V_28 ++ )
if ( V_131 [ V_28 ] . V_130 == V_130 )
return true ;
return false ;
}
static void F_70 ( T_1 * V_132 , unsigned V_26 ,
int V_133 , int V_134 )
{
T_4 V_135 , V_136 ;
unsigned long V_137 ;
T_1 V_27 ;
F_71 ( ! F_69 ( V_26 ) ) ;
V_27 = F_21 ( V_26 ) ;
V_135 = 2 * ( V_26 & 0x0f ) ;
V_136 = 2 * ( V_26 & 0x0f ) + 1 ;
V_137 = V_132 [ V_27 ] ;
F_72 ( V_27 == V_33 ) ;
V_133 ? F_73 ( V_135 , & V_137 ) : F_74 ( V_135 , & V_137 ) ;
V_134 ? F_73 ( V_136 , & V_137 ) : F_74 ( V_136 , & V_137 ) ;
V_132 [ V_27 ] = V_137 ;
}
static void F_75 ( T_1 * V_132 )
{
int V_28 ;
memset ( V_132 , 0xff , V_138 * ( 1 << V_139 ) ) ;
for ( V_28 = 0 ; V_131 [ V_28 ] . V_130 != V_33 ; V_28 ++ ) {
if ( ! V_131 [ V_28 ] . V_140 )
continue;
F_70 ( V_132 , V_131 [ V_28 ] . V_130 , 1 , 1 ) ;
}
}
static void F_76 ( T_1 V_27 )
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
F_77 () ;
}
static void F_78 ( void )
{
int V_28 ;
memset ( V_142 , 0xff , sizeof( V_142 ) ) ;
for ( V_28 = 0 ; V_131 [ V_28 ] . V_130 != V_33 ; V_28 ++ ) {
T_1 V_27 ;
V_27 = F_21 ( V_131 [ V_28 ] . V_130 ) ;
F_72 ( V_27 == V_33 ) ;
F_76 ( V_27 ) ;
}
}
static void F_79 ( struct V_7 * V_10 )
{
T_1 * V_132 = V_10 -> V_132 ;
V_10 -> V_1 -> V_2 . V_143 = 1 ;
F_70 ( V_132 , V_144 , 1 , 1 ) ;
F_70 ( V_132 , V_145 , 1 , 1 ) ;
F_70 ( V_132 , V_146 , 1 , 1 ) ;
F_70 ( V_132 , V_147 , 1 , 1 ) ;
}
static void F_80 ( struct V_7 * V_10 )
{
T_1 * V_132 = V_10 -> V_132 ;
V_10 -> V_1 -> V_2 . V_143 = 0 ;
F_70 ( V_132 , V_144 , 0 , 0 ) ;
F_70 ( V_132 , V_145 , 0 , 0 ) ;
F_70 ( V_132 , V_146 , 0 , 0 ) ;
F_70 ( V_132 , V_147 , 0 , 0 ) ;
}
static T_5 int F_81 ( void )
{
int V_125 ;
struct V_148 * V_149 ;
void * V_150 ;
int V_126 ;
V_149 = F_82 ( V_127 , V_151 ) ;
if ( ! V_149 )
return - V_128 ;
V_150 = F_83 ( V_149 ) ;
memset ( V_150 , 0xff , V_138 * ( 1 << V_151 ) ) ;
V_152 = F_59 ( V_149 ) << V_119 ;
F_78 () ;
if ( F_84 ( V_153 ) )
F_85 ( V_154 ) ;
if ( F_84 ( V_155 ) )
F_85 ( V_156 ) ;
if ( F_84 ( V_95 ) ) {
T_2 V_157 ;
V_158 = true ;
V_157 = F_86 ( 0x7fffffffULL , F_87 ( V_159 , V_160 ) ) ;
V_161 = V_157 ;
}
if ( V_17 ) {
F_33 ( V_93 L_6 ) ;
F_85 ( V_43 | V_162 ) ;
}
F_88 (cpu) {
V_126 = F_66 ( V_125 ) ;
if ( V_126 )
goto V_80;
}
if ( ! F_84 ( V_163 ) )
V_39 = false ;
if ( V_39 && ! V_164 ) {
F_33 ( V_93 L_7 ) ;
V_39 = false ;
}
if ( V_39 ) {
F_33 ( V_93 L_8 ) ;
F_89 () ;
} else
F_90 () ;
return 0 ;
V_80:
F_91 ( V_149 , V_151 ) ;
V_152 = 0 ;
return V_126 ;
}
static T_6 void F_92 ( void )
{
int V_125 ;
F_88 (cpu)
F_63 ( V_125 ) ;
F_91 ( F_93 ( V_152 >> V_119 ) , V_151 ) ;
V_152 = 0 ;
}
static void F_94 ( struct V_165 * V_166 )
{
V_166 -> V_167 = 0 ;
V_166 -> V_168 = V_169 | V_170 |
V_171 ;
V_166 -> V_172 = 0xffff ;
V_166 -> V_72 = 0 ;
}
static void F_95 ( struct V_165 * V_166 , T_7 type )
{
V_166 -> V_167 = 0 ;
V_166 -> V_168 = V_169 | type ;
V_166 -> V_172 = 0xffff ;
V_166 -> V_72 = 0 ;
}
static T_2 F_87 ( T_2 V_173 , T_2 V_174 )
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
static T_2 F_96 ( struct V_8 * V_9 , T_2 V_174 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_177 = V_174 ;
if ( V_10 -> V_178 != V_97 )
V_177 = F_87 ( V_10 -> V_178 , V_174 ) ;
return V_177 ;
}
static void F_97 ( struct V_8 * V_9 , T_1 V_179 , bool V_180 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_173 ;
T_2 V_181 ;
if ( ! V_180 ) {
V_10 -> V_178 = V_97 ;
return;
}
if ( ! F_84 ( V_95 ) ) {
if ( V_179 > V_159 ) {
V_9 -> V_23 . V_182 = 1 ;
V_9 -> V_23 . V_183 = 1 ;
} else
F_98 ( 1 , L_9 ) ;
return;
}
V_181 = V_179 ;
V_173 = V_181 << 32 ;
F_99 ( V_173 , V_159 ) ;
if ( V_173 == 0 || V_173 & V_184 ) {
F_100 ( 1 , L_10 ,
V_179 ) ;
return;
}
V_10 -> V_178 = V_173 ;
}
static T_2 F_101 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_1 -> V_2 . V_185 ;
}
static void F_102 ( struct V_8 * V_9 , T_2 V_27 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_186 = 0 ;
if ( F_7 ( V_9 ) ) {
V_186 = V_10 -> V_1 -> V_2 . V_185 -
V_10 -> V_17 . V_18 -> V_2 . V_185 ;
V_10 -> V_17 . V_18 -> V_2 . V_185 = V_27 ;
}
V_10 -> V_1 -> V_2 . V_185 = V_27 + V_186 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static void F_103 ( struct V_8 * V_9 , T_8 V_187 , bool V_188 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_71 ( V_187 < 0 ) ;
if ( V_188 )
V_187 = F_96 ( V_9 , V_187 ) ;
V_10 -> V_1 -> V_2 . V_185 += V_187 ;
if ( F_7 ( V_9 ) )
V_10 -> V_17 . V_18 -> V_2 . V_185 += V_187 ;
F_3 ( V_10 -> V_1 , V_16 ) ;
}
static T_2 F_104 ( struct V_8 * V_9 , T_2 V_189 )
{
T_2 V_174 ;
V_174 = F_96 ( V_9 , F_105 () ) ;
return V_189 - V_174 ;
}
static void F_106 ( struct V_7 * V_10 )
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
V_2 -> V_244 = F_107 ( V_10 -> V_132 ) ;
V_2 -> V_245 = V_246 ;
F_94 ( & V_42 -> V_247 ) ;
F_94 ( & V_42 -> V_248 ) ;
F_94 ( & V_42 -> V_249 ) ;
F_94 ( & V_42 -> V_250 ) ;
F_94 ( & V_42 -> V_251 ) ;
V_42 -> V_71 . V_167 = 0xf000 ;
V_42 -> V_71 . V_72 = 0xffff0000 ;
V_42 -> V_71 . V_168 = V_252 | V_169 |
V_170 | V_253 ;
V_42 -> V_71 . V_172 = 0xffff ;
V_42 -> V_254 . V_172 = 0xffff ;
V_42 -> V_255 . V_172 = 0xffff ;
F_95 ( & V_42 -> V_256 , V_257 ) ;
F_95 ( & V_42 -> V_258 , V_259 ) ;
F_27 ( & V_10 -> V_9 , 0 ) ;
V_42 -> V_260 = 0xffff0ff0 ;
F_108 ( & V_10 -> V_9 , 2 ) ;
V_42 -> V_68 = 0x0000fff0 ;
V_10 -> V_9 . V_23 . V_261 [ V_262 ] = V_42 -> V_68 ;
V_10 -> V_9 . V_23 . V_263 = 0 ;
( void ) F_109 ( & V_10 -> V_9 , V_264 | V_265 | V_266 ) ;
V_42 -> V_267 = V_268 ;
if ( V_39 ) {
V_2 -> V_269 = 1 ;
F_17 ( V_10 , V_226 ) ;
F_15 ( V_10 , V_215 ) ;
F_10 ( V_10 , V_193 ) ;
F_10 ( V_10 , V_196 ) ;
V_42 -> V_270 = 0x0007040600070406ULL ;
V_42 -> V_271 = 0 ;
V_42 -> V_267 = 0 ;
}
V_10 -> V_109 = 0 ;
V_10 -> V_17 . V_1 = 0 ;
V_10 -> V_9 . V_23 . V_24 = 0 ;
if ( F_84 ( V_272 ) ) {
V_2 -> V_273 = 3000 ;
F_16 ( V_10 , V_274 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_18 ( V_10 ) ;
}
static void F_110 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_275 ;
T_1 V_276 = 1 ;
F_106 ( V_10 ) ;
F_111 ( V_9 , & V_276 , & V_275 , & V_275 , & V_275 ) ;
F_112 ( V_9 , V_277 , V_276 ) ;
}
static struct V_8 * F_113 ( struct V_278 * V_278 , unsigned int V_279 )
{
struct V_7 * V_10 ;
struct V_148 * V_148 ;
struct V_148 * V_280 ;
struct V_148 * V_281 ;
struct V_148 * V_282 ;
int V_80 ;
V_10 = F_114 ( V_283 , V_127 ) ;
if ( ! V_10 ) {
V_80 = - V_128 ;
goto V_284;
}
V_10 -> V_178 = V_97 ;
V_80 = F_115 ( & V_10 -> V_9 , V_278 , V_279 ) ;
if ( V_80 )
goto V_285;
V_80 = - V_128 ;
V_148 = F_68 ( V_127 ) ;
if ( ! V_148 )
goto V_286;
V_280 = F_82 ( V_127 , V_139 ) ;
if ( ! V_280 )
goto V_287;
V_282 = F_82 ( V_127 , V_139 ) ;
if ( ! V_282 )
goto V_288;
V_281 = F_68 ( V_127 ) ;
if ( ! V_281 )
goto V_289;
V_10 -> V_17 . V_18 = F_83 ( V_281 ) ;
V_10 -> V_132 = F_83 ( V_280 ) ;
F_75 ( V_10 -> V_132 ) ;
V_10 -> V_17 . V_132 = F_83 ( V_282 ) ;
F_75 ( V_10 -> V_17 . V_132 ) ;
V_10 -> V_1 = F_83 ( V_148 ) ;
F_116 ( V_10 -> V_1 ) ;
V_10 -> V_290 = F_59 ( V_148 ) << V_119 ;
V_10 -> V_109 = 0 ;
F_106 ( V_10 ) ;
V_10 -> V_9 . V_23 . V_291 = 0xfee00000 | V_292 ;
if ( F_117 ( & V_10 -> V_9 ) )
V_10 -> V_9 . V_23 . V_291 |= V_293 ;
F_45 ( & V_10 -> V_9 ) ;
return & V_10 -> V_9 ;
V_289:
F_91 ( V_282 , V_139 ) ;
V_288:
F_91 ( V_280 , V_139 ) ;
V_287:
F_64 ( V_148 ) ;
V_286:
F_118 ( & V_10 -> V_9 ) ;
V_285:
F_119 ( V_283 , V_10 ) ;
V_284:
return F_120 ( V_80 ) ;
}
static void F_121 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_64 ( F_93 ( V_10 -> V_290 >> V_119 ) ) ;
F_91 ( F_122 ( V_10 -> V_132 ) , V_139 ) ;
F_64 ( F_122 ( V_10 -> V_17 . V_18 ) ) ;
F_91 ( F_122 ( V_10 -> V_17 . V_132 ) , V_139 ) ;
F_118 ( V_9 ) ;
F_119 ( V_283 , V_10 ) ;
}
static void F_123 ( struct V_8 * V_9 , int V_125 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
if ( F_124 ( V_125 != V_9 -> V_125 ) ) {
V_10 -> V_109 = 0 ;
F_1 ( V_10 -> V_1 ) ;
}
#ifdef F_26
F_54 ( V_294 , F_4 ( V_9 ) -> V_188 . V_295 ) ;
#endif
F_125 ( V_250 , V_10 -> V_188 . V_250 ) ;
F_125 ( V_251 , V_10 -> V_188 . V_251 ) ;
V_10 -> V_188 . V_296 = F_126 () ;
for ( V_28 = 0 ; V_28 < V_297 ; V_28 ++ )
F_54 ( V_298 [ V_28 ] , V_10 -> V_299 [ V_28 ] ) ;
if ( F_38 ( V_95 ) &&
V_10 -> V_178 != F_60 ( V_120 ) ) {
F_60 ( V_120 ) = V_10 -> V_178 ;
F_49 ( V_96 , V_10 -> V_178 ) ;
}
}
static void F_127 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_28 ;
++ V_9 -> V_300 . V_301 ;
F_128 ( V_10 -> V_188 . V_296 ) ;
#ifdef F_26
F_129 ( V_250 , V_10 -> V_188 . V_250 ) ;
F_49 ( V_302 , V_303 -> V_304 . V_251 ) ;
F_130 ( V_10 -> V_188 . V_251 ) ;
#else
#ifdef F_131
F_129 ( V_251 , V_10 -> V_188 . V_251 ) ;
#endif
#endif
for ( V_28 = 0 ; V_28 < V_297 ; V_28 ++ )
F_49 ( V_298 [ V_28 ] , V_10 -> V_299 [ V_28 ] ) ;
}
static void F_132 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_305 ;
if ( ! F_133 ( V_9 ) )
V_305 = 0 ;
else if ( V_10 -> V_1 -> V_42 . V_306 & V_307 )
V_305 = 3 ;
else
V_305 = V_10 -> V_1 -> V_42 . V_71 . V_167 & 0x3 ;
V_10 -> V_1 -> V_42 . V_305 = V_305 ;
}
static unsigned long F_134 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_1 -> V_42 . V_306 ;
}
static void F_135 ( struct V_8 * V_9 , unsigned long V_306 )
{
unsigned long V_308 = F_4 ( V_9 ) -> V_1 -> V_42 . V_306 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_306 = V_306 ;
if ( ( V_308 ^ V_306 ) & V_307 )
F_132 ( V_9 ) ;
}
static void F_136 ( struct V_8 * V_9 , enum V_309 V_310 )
{
switch ( V_310 ) {
case V_311 :
F_72 ( ! V_39 ) ;
F_137 ( V_9 , V_9 -> V_23 . V_312 , F_138 ( V_9 ) ) ;
break;
default:
F_77 () ;
}
}
static void F_139 ( struct V_7 * V_10 )
{
F_16 ( V_10 , V_313 ) ;
}
static void F_140 ( struct V_7 * V_10 )
{
F_17 ( V_10 , V_313 ) ;
}
static struct V_165 * F_141 ( struct V_8 * V_9 , int V_166 )
{
struct V_190 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
switch ( V_166 ) {
case V_314 : return & V_42 -> V_71 ;
case V_315 : return & V_42 -> V_249 ;
case V_316 : return & V_42 -> V_247 ;
case V_317 : return & V_42 -> V_250 ;
case V_318 : return & V_42 -> V_251 ;
case V_319 : return & V_42 -> V_248 ;
case V_320 : return & V_42 -> V_258 ;
case V_321 : return & V_42 -> V_256 ;
}
F_77 () ;
return NULL ;
}
static T_2 F_142 ( struct V_8 * V_9 , int V_166 )
{
struct V_165 * V_322 = F_141 ( V_9 , V_166 ) ;
return V_322 -> V_72 ;
}
static void F_143 ( struct V_8 * V_9 ,
struct V_323 * V_324 , int V_166 )
{
struct V_165 * V_322 = F_141 ( V_9 , V_166 ) ;
V_324 -> V_72 = V_322 -> V_72 ;
V_324 -> V_172 = V_322 -> V_172 ;
V_324 -> V_167 = V_322 -> V_167 ;
V_324 -> type = V_322 -> V_168 & V_325 ;
V_324 -> V_322 = ( V_322 -> V_168 >> V_326 ) & 1 ;
V_324 -> V_327 = ( V_322 -> V_168 >> V_328 ) & 3 ;
V_324 -> V_329 = ( V_322 -> V_168 >> V_330 ) & 1 ;
V_324 -> V_331 = ( V_322 -> V_168 >> V_332 ) & 1 ;
V_324 -> V_333 = ( V_322 -> V_168 >> V_334 ) & 1 ;
V_324 -> V_335 = ( V_322 -> V_168 >> V_336 ) & 1 ;
V_324 -> V_15 = ( V_322 -> V_168 >> V_337 ) & 1 ;
V_324 -> V_338 = ! V_324 -> V_329 || ( V_324 -> type == 0 ) ;
switch ( V_166 ) {
case V_314 :
V_324 -> V_15 = V_322 -> V_172 > 0xfffff ;
break;
case V_320 :
V_324 -> type |= 0x2 ;
break;
case V_315 :
case V_316 :
case V_317 :
case V_318 :
if ( ! V_324 -> V_338 )
V_324 -> type |= 0x1 ;
break;
case V_319 :
if ( V_324 -> V_338 )
V_324 -> V_335 = 0 ;
break;
}
}
static int F_144 ( struct V_8 * V_9 )
{
struct V_190 * V_42 = & F_4 ( V_9 ) -> V_1 -> V_42 ;
return V_42 -> V_305 ;
}
static void F_145 ( struct V_8 * V_9 , struct V_100 * V_339 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_339 -> V_340 = V_10 -> V_1 -> V_42 . V_255 . V_172 ;
V_339 -> V_113 = V_10 -> V_1 -> V_42 . V_255 . V_72 ;
}
static void F_146 ( struct V_8 * V_9 , struct V_100 * V_339 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_255 . V_172 = V_339 -> V_340 ;
V_10 -> V_1 -> V_42 . V_255 . V_72 = V_339 -> V_113 ;
F_3 ( V_10 -> V_1 , V_341 ) ;
}
static void F_147 ( struct V_8 * V_9 , struct V_100 * V_339 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_339 -> V_340 = V_10 -> V_1 -> V_42 . V_254 . V_172 ;
V_339 -> V_113 = V_10 -> V_1 -> V_42 . V_254 . V_72 ;
}
static void F_148 ( struct V_8 * V_9 , struct V_100 * V_339 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_254 . V_172 = V_339 -> V_340 ;
V_10 -> V_1 -> V_42 . V_254 . V_72 = V_339 -> V_113 ;
F_3 ( V_10 -> V_1 , V_341 ) ;
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
T_9 V_342 = V_10 -> V_9 . V_23 . V_263 ;
T_2 * V_343 = & V_10 -> V_1 -> V_42 . V_263 ;
if ( ! V_10 -> V_9 . V_191 )
* V_343 |= V_344 ;
else
* V_343 = ( * V_343 & ~ V_344 )
| ( V_342 & V_344 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
if ( V_342 == * V_343 && V_10 -> V_9 . V_191 ) {
F_10 ( V_10 , V_192 ) ;
F_10 ( V_10 , V_195 ) ;
} else {
F_9 ( V_10 , V_192 ) ;
F_9 ( V_10 , V_195 ) ;
}
}
static void F_153 ( struct V_8 * V_9 , unsigned long V_263 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
#ifdef F_26
if ( V_9 -> V_23 . V_38 & V_41 ) {
if ( ! F_154 ( V_9 ) && ( V_263 & V_345 ) ) {
V_9 -> V_23 . V_38 |= V_40 ;
V_10 -> V_1 -> V_42 . V_38 |= V_40 | V_41 ;
}
if ( F_154 ( V_9 ) && ! ( V_263 & V_345 ) ) {
V_9 -> V_23 . V_38 &= ~ V_40 ;
V_10 -> V_1 -> V_42 . V_38 &= ~ ( V_40 | V_41 ) ;
}
}
#endif
V_9 -> V_23 . V_263 = V_263 ;
if ( ! V_39 )
V_263 |= V_345 | V_346 ;
if ( ! V_9 -> V_191 )
V_263 |= V_347 ;
V_263 &= ~ ( V_265 | V_264 ) ;
V_10 -> V_1 -> V_42 . V_263 = V_263 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_152 ( V_10 ) ;
}
static int F_155 ( struct V_8 * V_9 , unsigned long V_267 )
{
unsigned long V_348 = F_156 () & V_349 ;
unsigned long V_350 = F_4 ( V_9 ) -> V_1 -> V_42 . V_267 ;
if ( V_267 & V_351 )
return 1 ;
if ( V_39 && ( ( V_350 ^ V_267 ) & V_352 ) )
F_157 ( V_9 ) ;
V_9 -> V_23 . V_267 = V_267 ;
if ( ! V_39 )
V_267 |= V_268 ;
V_267 |= V_348 ;
F_4 ( V_9 ) -> V_1 -> V_42 . V_267 = V_267 ;
F_3 ( F_4 ( V_9 ) -> V_1 , V_44 ) ;
return 0 ;
}
static void F_158 ( struct V_8 * V_9 ,
struct V_323 * V_324 , int V_166 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_165 * V_322 = F_141 ( V_9 , V_166 ) ;
V_322 -> V_72 = V_324 -> V_72 ;
V_322 -> V_172 = V_324 -> V_172 ;
V_322 -> V_167 = V_324 -> V_167 ;
if ( V_324 -> V_338 )
V_322 -> V_168 = 0 ;
else {
V_322 -> V_168 = ( V_324 -> type & V_325 ) ;
V_322 -> V_168 |= ( V_324 -> V_322 & 1 ) << V_326 ;
V_322 -> V_168 |= ( V_324 -> V_327 & 3 ) << V_328 ;
V_322 -> V_168 |= ( V_324 -> V_329 & 1 ) << V_330 ;
V_322 -> V_168 |= ( V_324 -> V_331 & 1 ) << V_332 ;
V_322 -> V_168 |= ( V_324 -> V_333 & 1 ) << V_334 ;
V_322 -> V_168 |= ( V_324 -> V_335 & 1 ) << V_336 ;
V_322 -> V_168 |= ( V_324 -> V_15 & 1 ) << V_337 ;
}
if ( V_166 == V_314 )
F_132 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_353 ) ;
}
static void F_159 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_354 ) ;
F_15 ( V_10 , V_66 ) ;
if ( V_10 -> V_355 )
F_14 ( V_10 , V_354 ) ;
if ( V_9 -> V_356 & V_357 ) {
if ( V_9 -> V_356 &
( V_358 | V_359 ) )
F_14 ( V_10 , V_354 ) ;
if ( V_9 -> V_356 & V_360 )
F_14 ( V_10 , V_66 ) ;
} else
V_9 -> V_356 = 0 ;
}
static void F_160 ( struct V_7 * V_10 , struct V_98 * V_99 )
{
if ( V_99 -> V_112 > V_99 -> V_110 ) {
++ V_99 -> V_109 ;
V_99 -> V_112 = 1 ;
V_10 -> V_1 -> V_2 . V_361 = V_362 ;
}
V_10 -> V_109 = V_99 -> V_109 ;
V_10 -> V_1 -> V_2 . V_35 = V_99 -> V_112 ++ ;
F_3 ( V_10 -> V_1 , V_363 ) ;
}
static void F_161 ( struct V_8 * V_9 , unsigned long V_364 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_365 = V_364 ;
F_3 ( V_10 -> V_1 , V_366 ) ;
}
static int F_162 ( struct V_7 * V_10 )
{
T_2 V_367 = V_10 -> V_1 -> V_2 . V_368 ;
T_1 V_64 ;
int V_126 = 1 ;
switch ( V_10 -> V_369 ) {
default:
V_64 = V_10 -> V_1 -> V_2 . V_370 ;
F_163 ( V_367 , V_64 ) ;
if ( ! V_39 && F_164 ( & V_10 -> V_9 ) )
F_165 ( & V_10 -> V_9 , V_367 ) ;
V_126 = F_166 ( & V_10 -> V_9 , V_367 , V_64 ,
V_10 -> V_1 -> V_2 . V_371 ,
V_10 -> V_1 -> V_2 . V_372 ) ;
break;
case V_373 :
V_10 -> V_369 = 0 ;
F_167 () ;
F_168 ( V_367 ) ;
F_169 () ;
break;
case V_374 :
V_10 -> V_369 = 0 ;
F_167 () ;
F_170 ( V_367 ) ;
F_169 () ;
break;
}
return V_126 ;
}
static int F_171 ( struct V_7 * V_10 )
{
struct V_375 * V_375 = V_10 -> V_9 . V_376 ;
if ( ! ( V_10 -> V_9 . V_356 &
( V_358 | V_359 ) ) &&
! V_10 -> V_355 ) {
F_172 ( & V_10 -> V_9 , V_354 ) ;
return 1 ;
}
if ( V_10 -> V_355 ) {
V_10 -> V_355 = false ;
if ( ! ( V_10 -> V_9 . V_356 & V_358 ) )
V_10 -> V_1 -> V_42 . V_306 &=
~ ( V_377 | V_378 ) ;
F_159 ( & V_10 -> V_9 ) ;
}
if ( V_10 -> V_9 . V_356 &
( V_358 | V_359 ) ) {
V_375 -> V_379 = V_380 ;
V_375 -> V_381 . V_23 . V_382 =
V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_375 -> V_381 . V_23 . V_383 = V_354 ;
return 0 ;
}
return 1 ;
}
static int F_173 ( struct V_7 * V_10 )
{
struct V_375 * V_375 = V_10 -> V_9 . V_376 ;
V_375 -> V_379 = V_380 ;
V_375 -> V_381 . V_23 . V_382 = V_10 -> V_1 -> V_42 . V_71 . V_72 + V_10 -> V_1 -> V_42 . V_68 ;
V_375 -> V_381 . V_23 . V_383 = V_66 ;
return 0 ;
}
static int F_174 ( struct V_7 * V_10 )
{
int V_384 ;
V_384 = F_32 ( & V_10 -> V_9 , V_385 ) ;
if ( V_384 != V_57 )
F_172 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static void F_175 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_15 ( V_10 , V_386 ) ;
V_10 -> V_9 . V_191 = 1 ;
F_152 ( V_10 ) ;
}
static int F_176 ( struct V_7 * V_10 )
{
F_175 ( & V_10 -> V_9 ) ;
return 1 ;
}
static bool F_177 ( void )
{
int V_80 , V_28 ;
T_2 V_364 ;
if ( ! V_84 )
return false ;
V_364 = F_41 ( V_387 , & V_80 ) ;
if ( V_80 )
return false ;
V_364 &= ~ ( 1ULL << 62 ) ;
if ( V_364 != 0xb600000000010015ULL )
return false ;
for ( V_28 = 0 ; V_28 < 6 ; ++ V_28 )
F_44 ( F_178 ( V_28 ) , 0 , 0 ) ;
V_364 = F_41 ( V_388 , & V_80 ) ;
if ( ! V_80 ) {
T_1 V_78 , V_79 ;
V_364 &= ~ ( 1ULL << 2 ) ;
V_78 = F_42 ( V_364 ) ;
V_79 = F_43 ( V_364 ) ;
F_44 ( V_388 , V_78 , V_79 ) ;
}
F_179 () ;
return true ;
}
static void F_180 ( struct V_7 * V_10 )
{
if ( F_177 () ) {
F_55 ( L_11 ) ;
F_181 ( V_389 , & V_10 -> V_9 ) ;
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
struct V_375 * V_375 = V_10 -> V_9 . V_376 ;
F_116 ( V_10 -> V_1 ) ;
F_106 ( V_10 ) ;
V_375 -> V_379 = V_390 ;
return 0 ;
}
static int F_184 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
T_1 V_391 = V_10 -> V_1 -> V_2 . V_370 ;
int V_340 , V_392 , string ;
unsigned V_393 ;
++ V_10 -> V_9 . V_300 . V_394 ;
string = ( V_391 & V_395 ) != 0 ;
V_392 = ( V_391 & V_396 ) != 0 ;
if ( string || V_392 )
return F_32 ( V_9 , 0 ) == V_57 ;
V_393 = V_391 >> 16 ;
V_340 = ( V_391 & V_397 ) >> V_398 ;
V_10 -> V_55 = V_10 -> V_1 -> V_2 . V_368 ;
F_31 ( & V_10 -> V_9 ) ;
return F_185 ( V_9 , V_340 , V_393 ) ;
}
static int F_186 ( struct V_7 * V_10 )
{
return 1 ;
}
static int F_187 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_300 . V_399 ;
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
return V_10 -> V_17 . V_400 ;
}
static T_2 F_194 ( struct V_8 * V_9 , int V_130 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_271 = V_10 -> V_17 . V_400 ;
T_2 V_401 ;
int V_50 ;
V_50 = F_195 ( V_9 -> V_278 , F_196 ( V_271 ) , & V_401 ,
F_197 ( V_271 ) + V_130 * 8 , 8 ) ;
if ( V_50 )
return 0 ;
return V_401 ;
}
static void F_198 ( struct V_8 * V_9 ,
unsigned long V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_400 = V_402 ;
F_3 ( V_10 -> V_1 , V_403 ) ;
F_157 ( V_9 ) ;
}
static void F_199 ( struct V_8 * V_9 ,
struct V_404 * V_405 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_406 = V_407 ;
V_10 -> V_1 -> V_2 . V_408 = 0 ;
V_10 -> V_1 -> V_2 . V_370 = V_405 -> V_64 ;
V_10 -> V_1 -> V_2 . V_368 = V_405 -> V_113 ;
F_200 ( V_10 ) ;
}
static int F_201 ( struct V_8 * V_9 )
{
int V_126 ;
V_126 = F_202 ( V_9 , & V_9 -> V_23 . V_409 ) ;
V_9 -> V_23 . V_409 . V_410 = F_198 ;
V_9 -> V_23 . V_409 . V_411 = F_193 ;
V_9 -> V_23 . V_409 . V_412 = F_194 ;
V_9 -> V_23 . V_409 . V_413 = F_199 ;
V_9 -> V_23 . V_409 . V_414 = F_25 () ;
V_9 -> V_23 . V_312 = & V_9 -> V_23 . V_415 ;
return V_126 ;
}
static void F_203 ( struct V_8 * V_9 )
{
V_9 -> V_23 . V_312 = & V_9 -> V_23 . V_409 ;
}
static int F_204 ( struct V_7 * V_10 )
{
if ( ! ( V_10 -> V_9 . V_23 . V_38 & V_43 )
|| ! F_154 ( & V_10 -> V_9 ) ) {
F_172 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
if ( V_10 -> V_1 -> V_42 . V_305 ) {
F_205 ( & V_10 -> V_9 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_10 , unsigned V_62 ,
bool V_63 , T_1 V_64 )
{
int V_416 ;
if ( ! F_7 ( & V_10 -> V_9 ) )
return 0 ;
V_10 -> V_1 -> V_2 . V_406 = V_417 + V_62 ;
V_10 -> V_1 -> V_2 . V_408 = 0 ;
V_10 -> V_1 -> V_2 . V_370 = V_64 ;
V_10 -> V_1 -> V_2 . V_368 = V_10 -> V_9 . V_23 . V_418 ;
V_416 = F_206 ( V_10 ) ;
if ( V_416 == V_419 )
V_10 -> V_17 . V_420 = true ;
return V_416 ;
}
static inline bool F_207 ( struct V_7 * V_10 )
{
if ( ! F_7 ( & V_10 -> V_9 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_421 ) )
return true ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_422 ) )
return false ;
if ( V_10 -> V_17 . V_420 )
return false ;
V_10 -> V_1 -> V_2 . V_406 = V_423 ;
V_10 -> V_1 -> V_2 . V_370 = 0 ;
V_10 -> V_1 -> V_2 . V_368 = 0 ;
if ( V_10 -> V_17 . V_22 & 1ULL ) {
V_10 -> V_17 . V_420 = true ;
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
V_10 -> V_1 -> V_2 . V_406 = V_424 ;
V_10 -> V_17 . V_420 = true ;
return false ;
}
static void * F_210 ( struct V_7 * V_10 , T_2 V_425 , struct V_148 * * V_426 )
{
struct V_148 * V_148 ;
F_211 () ;
V_148 = F_212 ( V_10 -> V_9 . V_278 , V_425 >> V_119 ) ;
if ( F_213 ( V_148 ) )
goto error;
* V_426 = V_148 ;
return F_214 ( V_148 ) ;
error:
F_205 ( & V_10 -> V_9 , 0 ) ;
return NULL ;
}
static void F_215 ( struct V_148 * V_148 )
{
F_216 ( V_148 ) ;
F_217 ( V_148 ) ;
}
static int F_218 ( struct V_7 * V_10 )
{
unsigned V_393 ;
T_4 V_81 , V_6 ;
T_2 V_425 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_228 ) ) )
return V_427 ;
V_393 = V_10 -> V_1 -> V_2 . V_370 >> 16 ;
V_425 = V_10 -> V_17 . V_428 + ( V_393 / 8 ) ;
V_6 = V_393 % 8 ;
V_81 = 0 ;
if ( F_219 ( V_10 -> V_9 . V_278 , V_425 , & V_81 , 1 ) )
V_81 &= ( 1 << V_6 ) ;
return V_81 ? V_419 : V_427 ;
}
static int F_220 ( struct V_7 * V_10 )
{
T_1 V_27 , V_26 , V_364 ;
int V_134 , V_49 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return V_427 ;
V_26 = V_10 -> V_9 . V_23 . V_261 [ V_429 ] ;
V_27 = F_21 ( V_26 ) ;
V_134 = V_10 -> V_1 -> V_2 . V_370 & 1 ;
V_49 = 1 << ( ( 2 * ( V_26 & 0xf ) ) + V_134 ) ;
if ( V_27 == V_33 )
return V_419 ;
V_27 *= 4 ;
if ( F_219 ( V_10 -> V_9 . V_278 , V_10 -> V_17 . V_430 + V_27 , & V_364 , 4 ) )
return V_419 ;
return ( V_364 & V_49 ) ? V_419 : V_427 ;
}
static int F_221 ( struct V_7 * V_10 )
{
T_1 V_406 = V_10 -> V_1 -> V_2 . V_406 ;
switch ( V_406 ) {
case V_423 :
case V_424 :
case V_417 + V_217 :
return V_427 ;
case V_407 :
if ( V_39 )
return V_427 ;
break;
case V_417 + V_215 :
if ( ! V_39 && V_10 -> V_369 == 0 )
return V_427 ;
break;
case V_417 + V_386 :
F_176 ( V_10 ) ;
break;
default:
break;
}
return V_431 ;
}
static int F_206 ( struct V_7 * V_10 )
{
T_1 V_406 = V_10 -> V_1 -> V_2 . V_406 ;
int V_416 = V_427 ;
switch ( V_406 ) {
case V_432 :
V_416 = F_220 ( V_10 ) ;
break;
case V_433 :
V_416 = F_218 ( V_10 ) ;
break;
case V_434 ... V_435 : {
T_1 V_6 = 1U << ( V_406 - V_434 ) ;
if ( V_10 -> V_17 . V_19 & V_6 )
V_416 = V_419 ;
break;
}
case V_436 ... V_437 : {
T_1 V_6 = 1U << ( V_406 - V_436 ) ;
if ( V_10 -> V_17 . V_20 & V_6 )
V_416 = V_419 ;
break;
}
case V_417 ... V_417 + 0x1f : {
T_1 V_438 = 1 << ( V_406 - V_417 ) ;
if ( V_10 -> V_17 . V_21 & V_438 )
V_416 = V_419 ;
else if ( ( V_406 == V_417 + V_215 ) &&
V_10 -> V_369 != 0 )
V_416 = V_419 ;
break;
}
case V_439 : {
V_416 = V_419 ;
break;
}
default: {
T_2 V_440 = 1ULL << ( V_406 - V_423 ) ;
if ( V_10 -> V_17 . V_22 & V_440 )
V_416 = V_419 ;
}
}
return V_416 ;
}
static int F_222 ( struct V_7 * V_10 )
{
int V_416 ;
V_416 = F_206 ( V_10 ) ;
if ( V_416 == V_419 )
F_200 ( V_10 ) ;
return V_416 ;
}
static inline void F_223 ( struct V_1 * V_441 , struct V_1 * V_442 )
{
struct V_11 * V_443 = & V_441 -> V_2 ;
struct V_11 * V_444 = & V_442 -> V_2 ;
V_443 -> V_19 = V_444 -> V_19 ;
V_443 -> V_20 = V_444 -> V_20 ;
V_443 -> V_21 = V_444 -> V_21 ;
V_443 -> V_22 = V_444 -> V_22 ;
V_443 -> V_243 = V_444 -> V_243 ;
V_443 -> V_244 = V_444 -> V_244 ;
V_443 -> V_185 = V_444 -> V_185 ;
V_443 -> V_35 = V_444 -> V_35 ;
V_443 -> V_361 = V_444 -> V_361 ;
V_443 -> V_245 = V_444 -> V_245 ;
V_443 -> V_445 = V_444 -> V_445 ;
V_443 -> V_51 = V_444 -> V_51 ;
V_443 -> V_406 = V_444 -> V_406 ;
V_443 -> V_408 = V_444 -> V_408 ;
V_443 -> V_370 = V_444 -> V_370 ;
V_443 -> V_368 = V_444 -> V_368 ;
V_443 -> V_446 = V_444 -> V_446 ;
V_443 -> V_447 = V_444 -> V_447 ;
V_443 -> V_269 = V_444 -> V_269 ;
V_443 -> V_74 = V_444 -> V_74 ;
V_443 -> V_77 = V_444 -> V_77 ;
V_443 -> V_400 = V_444 -> V_400 ;
V_443 -> V_143 = V_444 -> V_143 ;
}
static int F_200 ( struct V_7 * V_10 )
{
struct V_1 * V_448 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_148 * V_148 ;
F_224 ( V_1 -> V_2 . V_406 ,
V_1 -> V_2 . V_370 ,
V_1 -> V_2 . V_368 ,
V_1 -> V_2 . V_446 ,
V_1 -> V_2 . V_447 ,
V_449 ) ;
V_448 = F_210 ( V_10 , V_10 -> V_17 . V_1 , & V_148 ) ;
if ( ! V_448 )
return 1 ;
F_225 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_1 = 0 ;
F_19 ( V_10 ) ;
V_448 -> V_42 . V_247 = V_1 -> V_42 . V_247 ;
V_448 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_448 -> V_42 . V_248 = V_1 -> V_42 . V_248 ;
V_448 -> V_42 . V_249 = V_1 -> V_42 . V_249 ;
V_448 -> V_42 . V_254 = V_1 -> V_42 . V_254 ;
V_448 -> V_42 . V_255 = V_1 -> V_42 . V_255 ;
V_448 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_448 -> V_42 . V_263 = F_226 ( & V_10 -> V_9 ) ;
V_448 -> V_42 . V_271 = F_138 ( & V_10 -> V_9 ) ;
V_448 -> V_42 . V_418 = V_1 -> V_42 . V_418 ;
V_448 -> V_42 . V_267 = V_10 -> V_9 . V_23 . V_267 ;
V_448 -> V_42 . V_306 = F_227 ( & V_10 -> V_9 ) ;
V_448 -> V_42 . V_68 = V_1 -> V_42 . V_68 ;
V_448 -> V_42 . V_450 = V_1 -> V_42 . V_450 ;
V_448 -> V_42 . V_451 = V_1 -> V_42 . V_451 ;
V_448 -> V_42 . V_365 = V_1 -> V_42 . V_365 ;
V_448 -> V_42 . V_260 = V_1 -> V_42 . V_260 ;
V_448 -> V_42 . V_305 = V_1 -> V_42 . V_305 ;
V_448 -> V_2 . V_245 = V_1 -> V_2 . V_245 ;
V_448 -> V_2 . V_445 = V_1 -> V_2 . V_445 ;
V_448 -> V_2 . V_51 = V_1 -> V_2 . V_51 ;
V_448 -> V_2 . V_406 = V_1 -> V_2 . V_406 ;
V_448 -> V_2 . V_408 = V_1 -> V_2 . V_408 ;
V_448 -> V_2 . V_370 = V_1 -> V_2 . V_370 ;
V_448 -> V_2 . V_368 = V_1 -> V_2 . V_368 ;
V_448 -> V_2 . V_446 = V_1 -> V_2 . V_446 ;
V_448 -> V_2 . V_447 = V_1 -> V_2 . V_447 ;
V_448 -> V_2 . V_55 = V_1 -> V_2 . V_55 ;
if ( V_1 -> V_2 . V_74 & V_47 ) {
struct V_11 * V_452 = & V_448 -> V_2 ;
V_452 -> V_446 = V_1 -> V_2 . V_74 ;
V_452 -> V_447 = V_1 -> V_2 . V_77 ;
}
V_448 -> V_2 . V_361 = 0 ;
V_448 -> V_2 . V_74 = 0 ;
V_448 -> V_2 . V_77 = 0 ;
if ( ! ( V_10 -> V_9 . V_23 . V_24 & V_421 ) )
V_448 -> V_2 . V_245 &= ~ V_246 ;
F_223 ( V_1 , V_18 ) ;
F_228 ( & V_10 -> V_9 ) ;
F_229 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_400 = 0 ;
V_10 -> V_1 -> V_42 . V_247 = V_18 -> V_42 . V_247 ;
V_10 -> V_1 -> V_42 . V_71 = V_18 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_248 = V_18 -> V_42 . V_248 ;
V_10 -> V_1 -> V_42 . V_249 = V_18 -> V_42 . V_249 ;
V_10 -> V_1 -> V_42 . V_254 = V_18 -> V_42 . V_254 ;
V_10 -> V_1 -> V_42 . V_255 = V_18 -> V_42 . V_255 ;
F_108 ( & V_10 -> V_9 , V_18 -> V_42 . V_306 ) ;
F_27 ( & V_10 -> V_9 , V_18 -> V_42 . V_38 ) ;
F_153 ( & V_10 -> V_9 , V_18 -> V_42 . V_263 | V_453 ) ;
F_155 ( & V_10 -> V_9 , V_18 -> V_42 . V_267 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_271 = V_18 -> V_42 . V_271 ;
V_10 -> V_9 . V_23 . V_271 = V_18 -> V_42 . V_271 ;
} else {
( void ) F_230 ( & V_10 -> V_9 , V_18 -> V_42 . V_271 ) ;
}
F_112 ( & V_10 -> V_9 , V_454 , V_18 -> V_42 . V_451 ) ;
F_112 ( & V_10 -> V_9 , V_455 , V_18 -> V_42 . V_450 ) ;
F_112 ( & V_10 -> V_9 , V_262 , V_18 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_365 = 0 ;
V_10 -> V_1 -> V_42 . V_305 = 0 ;
V_10 -> V_1 -> V_2 . V_446 = 0 ;
F_1 ( V_10 -> V_1 ) ;
F_215 ( V_148 ) ;
F_203 ( & V_10 -> V_9 ) ;
F_231 ( & V_10 -> V_9 ) ;
F_232 ( & V_10 -> V_9 ) ;
return 0 ;
}
static bool F_233 ( struct V_7 * V_10 )
{
int V_28 ;
if ( ! ( V_10 -> V_17 . V_22 & ( 1ULL << V_229 ) ) )
return true ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
T_1 V_364 , V_456 ;
T_2 V_27 ;
if ( V_142 [ V_28 ] == 0xffffffff )
break;
V_456 = V_142 [ V_28 ] ;
V_27 = V_10 -> V_17 . V_430 + ( V_456 * 4 ) ;
if ( F_219 ( V_10 -> V_9 . V_278 , V_27 , & V_364 , 4 ) )
return false ;
V_10 -> V_17 . V_132 [ V_456 ] = V_10 -> V_132 [ V_456 ] | V_364 ;
}
V_10 -> V_1 -> V_2 . V_244 = F_107 ( V_10 -> V_17 . V_132 ) ;
return true ;
}
static bool F_234 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_22 & ( 1ULL << V_232 ) ) == 0 )
return false ;
if ( V_1 -> V_2 . V_35 == 0 )
return false ;
if ( V_1 -> V_2 . V_269 && ! V_39 )
return false ;
return true ;
}
static bool F_235 ( struct V_7 * V_10 )
{
struct V_1 * V_448 ;
struct V_1 * V_18 = V_10 -> V_17 . V_18 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_148 * V_148 ;
T_2 V_457 ;
V_457 = V_10 -> V_1 -> V_42 . V_451 ;
V_448 = F_210 ( V_10 , V_10 -> V_1 -> V_42 . V_451 , & V_148 ) ;
if ( ! V_448 )
return false ;
if ( ! F_234 ( V_448 ) ) {
V_448 -> V_2 . V_406 = V_439 ;
V_448 -> V_2 . V_408 = 0 ;
V_448 -> V_2 . V_370 = 0 ;
V_448 -> V_2 . V_368 = 0 ;
F_215 ( V_148 ) ;
return false ;
}
F_236 ( V_10 -> V_1 -> V_42 . V_68 , V_457 ,
V_448 -> V_42 . V_68 ,
V_448 -> V_2 . V_245 ,
V_448 -> V_2 . V_74 ,
V_448 -> V_2 . V_269 ) ;
F_237 ( V_448 -> V_2 . V_19 & 0xffff ,
V_448 -> V_2 . V_19 >> 16 ,
V_448 -> V_2 . V_21 ,
V_448 -> V_2 . V_22 ) ;
F_228 ( & V_10 -> V_9 ) ;
F_229 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_247 = V_1 -> V_42 . V_247 ;
V_18 -> V_42 . V_71 = V_1 -> V_42 . V_71 ;
V_18 -> V_42 . V_248 = V_1 -> V_42 . V_248 ;
V_18 -> V_42 . V_249 = V_1 -> V_42 . V_249 ;
V_18 -> V_42 . V_254 = V_1 -> V_42 . V_254 ;
V_18 -> V_42 . V_255 = V_1 -> V_42 . V_255 ;
V_18 -> V_42 . V_38 = V_10 -> V_9 . V_23 . V_38 ;
V_18 -> V_42 . V_263 = F_226 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_267 = V_10 -> V_9 . V_23 . V_267 ;
V_18 -> V_42 . V_306 = F_227 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_68 = F_34 ( & V_10 -> V_9 ) ;
V_18 -> V_42 . V_450 = V_1 -> V_42 . V_450 ;
V_18 -> V_42 . V_451 = V_1 -> V_42 . V_451 ;
if ( V_39 )
V_18 -> V_42 . V_271 = V_1 -> V_42 . V_271 ;
else
V_18 -> V_42 . V_271 = F_138 ( & V_10 -> V_9 ) ;
F_223 ( V_18 , V_1 ) ;
if ( F_227 ( & V_10 -> V_9 ) & V_458 )
V_10 -> V_9 . V_23 . V_24 |= V_422 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_422 ;
if ( V_448 -> V_2 . V_269 ) {
F_238 ( & V_10 -> V_9 ) ;
V_10 -> V_17 . V_400 = V_448 -> V_2 . V_400 ;
F_201 ( & V_10 -> V_9 ) ;
}
V_10 -> V_1 -> V_42 . V_247 = V_448 -> V_42 . V_247 ;
V_10 -> V_1 -> V_42 . V_71 = V_448 -> V_42 . V_71 ;
V_10 -> V_1 -> V_42 . V_248 = V_448 -> V_42 . V_248 ;
V_10 -> V_1 -> V_42 . V_249 = V_448 -> V_42 . V_249 ;
V_10 -> V_1 -> V_42 . V_254 = V_448 -> V_42 . V_254 ;
V_10 -> V_1 -> V_42 . V_255 = V_448 -> V_42 . V_255 ;
F_108 ( & V_10 -> V_9 , V_448 -> V_42 . V_306 ) ;
F_27 ( & V_10 -> V_9 , V_448 -> V_42 . V_38 ) ;
F_153 ( & V_10 -> V_9 , V_448 -> V_42 . V_263 ) ;
F_155 ( & V_10 -> V_9 , V_448 -> V_42 . V_267 ) ;
if ( V_39 ) {
V_10 -> V_1 -> V_42 . V_271 = V_448 -> V_42 . V_271 ;
V_10 -> V_9 . V_23 . V_271 = V_448 -> V_42 . V_271 ;
} else
( void ) F_230 ( & V_10 -> V_9 , V_448 -> V_42 . V_271 ) ;
F_231 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_42 . V_418 = V_10 -> V_9 . V_23 . V_418 = V_448 -> V_42 . V_418 ;
F_112 ( & V_10 -> V_9 , V_454 , V_448 -> V_42 . V_451 ) ;
F_112 ( & V_10 -> V_9 , V_455 , V_448 -> V_42 . V_450 ) ;
F_112 ( & V_10 -> V_9 , V_262 , V_448 -> V_42 . V_68 ) ;
V_10 -> V_1 -> V_42 . V_451 = V_448 -> V_42 . V_451 ;
V_10 -> V_1 -> V_42 . V_450 = V_448 -> V_42 . V_450 ;
V_10 -> V_1 -> V_42 . V_68 = V_448 -> V_42 . V_68 ;
V_10 -> V_1 -> V_42 . V_365 = V_448 -> V_42 . V_365 ;
V_10 -> V_1 -> V_42 . V_260 = V_448 -> V_42 . V_260 ;
V_10 -> V_1 -> V_42 . V_305 = V_448 -> V_42 . V_305 ;
V_10 -> V_17 . V_430 = V_448 -> V_2 . V_244 & ~ 0x0fffULL ;
V_10 -> V_17 . V_428 = V_448 -> V_2 . V_243 & ~ 0x0fffULL ;
V_10 -> V_17 . V_19 = V_448 -> V_2 . V_19 ;
V_10 -> V_17 . V_20 = V_448 -> V_2 . V_20 ;
V_10 -> V_17 . V_21 = V_448 -> V_2 . V_21 ;
V_10 -> V_17 . V_22 = V_448 -> V_2 . V_22 ;
F_157 ( & V_10 -> V_9 ) ;
V_10 -> V_1 -> V_2 . V_245 = V_448 -> V_2 . V_245 | V_246 ;
if ( V_448 -> V_2 . V_245 & V_246 )
V_10 -> V_9 . V_23 . V_24 |= V_421 ;
else
V_10 -> V_9 . V_23 . V_24 &= ~ V_421 ;
if ( V_10 -> V_9 . V_23 . V_24 & V_421 ) {
F_10 ( V_10 , V_459 ) ;
F_10 ( V_10 , V_198 ) ;
}
F_17 ( V_10 , V_233 ) ;
V_10 -> V_1 -> V_2 . V_143 = V_448 -> V_2 . V_143 ;
V_10 -> V_1 -> V_2 . V_445 = V_448 -> V_2 . V_445 ;
V_10 -> V_1 -> V_2 . V_51 = V_448 -> V_2 . V_51 ;
V_10 -> V_1 -> V_2 . V_185 += V_448 -> V_2 . V_185 ;
V_10 -> V_1 -> V_2 . V_74 = V_448 -> V_2 . V_74 ;
V_10 -> V_1 -> V_2 . V_77 = V_448 -> V_2 . V_77 ;
F_215 ( V_148 ) ;
F_239 ( & V_10 -> V_9 ) ;
F_6 ( V_10 ) ;
V_10 -> V_17 . V_1 = V_457 ;
F_18 ( V_10 ) ;
F_1 ( V_10 -> V_1 ) ;
return true ;
}
static void F_240 ( struct V_1 * V_442 , struct V_1 * V_460 )
{
V_460 -> V_42 . V_250 = V_442 -> V_42 . V_250 ;
V_460 -> V_42 . V_251 = V_442 -> V_42 . V_251 ;
V_460 -> V_42 . V_258 = V_442 -> V_42 . V_258 ;
V_460 -> V_42 . V_256 = V_442 -> V_42 . V_256 ;
V_460 -> V_42 . V_461 = V_442 -> V_42 . V_461 ;
V_460 -> V_42 . V_462 = V_442 -> V_42 . V_462 ;
V_460 -> V_42 . V_463 = V_442 -> V_42 . V_463 ;
V_460 -> V_42 . V_464 = V_442 -> V_42 . V_464 ;
V_460 -> V_42 . V_465 = V_442 -> V_42 . V_465 ;
V_460 -> V_42 . V_466 = V_442 -> V_42 . V_466 ;
V_460 -> V_42 . V_467 = V_442 -> V_42 . V_467 ;
V_460 -> V_42 . V_468 = V_442 -> V_42 . V_468 ;
}
static int F_241 ( struct V_7 * V_10 )
{
struct V_1 * V_448 ;
struct V_148 * V_148 ;
if ( F_204 ( V_10 ) )
return 1 ;
V_448 = F_210 ( V_10 , V_10 -> V_1 -> V_42 . V_451 , & V_148 ) ;
if ( ! V_448 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_240 ( V_448 , V_10 -> V_1 ) ;
F_215 ( V_148 ) ;
return 1 ;
}
static int F_242 ( struct V_7 * V_10 )
{
struct V_1 * V_448 ;
struct V_148 * V_148 ;
if ( F_204 ( V_10 ) )
return 1 ;
V_448 = F_210 ( V_10 , V_10 -> V_1 -> V_42 . V_451 , & V_148 ) ;
if ( ! V_448 )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_240 ( V_10 -> V_1 , V_448 ) ;
F_215 ( V_148 ) ;
return 1 ;
}
static int F_243 ( struct V_7 * V_10 )
{
if ( F_204 ( V_10 ) )
return 1 ;
F_35 ( & V_10 -> V_9 , F_34 ( & V_10 -> V_9 ) + 3 ) ;
if ( ! F_235 ( V_10 ) )
return 1 ;
if ( ! F_233 ( V_10 ) )
goto V_469;
return 1 ;
V_469:
V_10 -> V_1 -> V_2 . V_406 = V_439 ;
V_10 -> V_1 -> V_2 . V_408 = 0 ;
V_10 -> V_1 -> V_2 . V_370 = 0 ;
V_10 -> V_1 -> V_2 . V_368 = 0 ;
F_200 ( V_10 ) ;
return 1 ;
}
static int F_244 ( struct V_7 * V_10 )
{
if ( F_204 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_181 ( V_470 , & V_10 -> V_9 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
static int F_245 ( struct V_7 * V_10 )
{
if ( F_204 ( V_10 ) )
return 1 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
F_19 ( V_10 ) ;
F_140 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_471 ;
F_3 ( V_10 -> V_1 , V_472 ) ;
return 1 ;
}
static int F_246 ( struct V_7 * V_10 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
F_247 ( V_10 -> V_1 -> V_42 . V_68 , V_9 -> V_23 . V_261 [ V_429 ] ,
V_9 -> V_23 . V_261 [ V_454 ] ) ;
F_248 ( V_9 , V_9 -> V_23 . V_261 [ V_454 ] ) ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_249 ( struct V_7 * V_10 )
{
F_250 ( V_10 -> V_1 -> V_42 . V_68 , V_10 -> V_9 . V_23 . V_261 [ V_454 ] ) ;
F_172 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static int F_251 ( struct V_7 * V_10 )
{
T_2 V_473 = F_252 ( & V_10 -> V_9 ) ;
T_1 V_130 = F_253 ( & V_10 -> V_9 , V_429 ) ;
if ( F_254 ( & V_10 -> V_9 , V_130 , V_473 ) == 0 ) {
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 3 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_255 ( struct V_7 * V_10 )
{
F_172 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
static int F_256 ( struct V_7 * V_10 )
{
T_10 V_474 ;
int V_475 ;
int V_476 = V_10 -> V_1 -> V_2 . V_446 &
V_477 ;
int V_478 = V_10 -> V_1 -> V_2 . V_446 & V_479 ;
T_7 type =
V_10 -> V_1 -> V_2 . V_446 & V_477 ;
T_7 V_480 =
V_10 -> V_1 -> V_2 . V_446 & V_481 ;
bool V_63 = false ;
T_1 V_64 = 0 ;
V_474 = ( T_10 ) V_10 -> V_1 -> V_2 . V_370 ;
if ( V_10 -> V_1 -> V_2 . V_368 &
( 1ULL << V_482 ) )
V_475 = V_483 ;
else if ( V_10 -> V_1 -> V_2 . V_368 &
( 1ULL << V_484 ) )
V_475 = V_485 ;
else if ( V_480 )
V_475 = V_486 ;
else
V_475 = V_487 ;
if ( V_475 == V_486 ) {
switch ( type ) {
case V_488 :
V_10 -> V_9 . V_23 . V_489 = false ;
break;
case V_490 :
if ( V_10 -> V_1 -> V_2 . V_368 &
( 1ULL << V_491 ) ) {
V_63 = true ;
V_64 =
( T_1 ) V_10 -> V_1 -> V_2 . V_368 ;
}
F_228 ( & V_10 -> V_9 ) ;
break;
case V_492 :
F_229 ( & V_10 -> V_9 ) ;
break;
default:
break;
}
}
if ( V_475 != V_486 ||
V_476 == V_493 ||
( V_476 == V_490 &&
( V_478 == V_494 || V_478 == V_66 ) ) )
F_31 ( & V_10 -> V_9 ) ;
if ( V_476 != V_493 )
V_478 = - 1 ;
if ( F_257 ( & V_10 -> V_9 , V_474 , V_478 , V_475 ,
V_63 , V_64 ) == V_495 ) {
V_10 -> V_9 . V_376 -> V_379 = V_496 ;
V_10 -> V_9 . V_376 -> V_497 . V_498 = V_499 ;
V_10 -> V_9 . V_376 -> V_497 . V_500 = 0 ;
return 0 ;
}
return 1 ;
}
static int F_258 ( struct V_7 * V_10 )
{
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_259 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_260 ( struct V_7 * V_10 )
{
++ V_10 -> V_9 . V_300 . V_501 ;
F_17 ( V_10 , V_502 ) ;
V_10 -> V_9 . V_23 . V_24 |= V_503 ;
V_10 -> V_504 = F_34 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_261 ( struct V_7 * V_10 )
{
if ( ! F_38 ( V_505 ) )
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
F_248 ( & V_10 -> V_9 , V_10 -> V_1 -> V_2 . V_370 ) ;
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_262 ( struct V_7 * V_10 )
{
return F_32 ( & V_10 -> V_9 , 0 ) == V_57 ;
}
static int F_263 ( struct V_7 * V_10 )
{
int V_80 ;
if ( ! F_38 ( V_67 ) )
return F_262 ( V_10 ) ;
V_80 = F_264 ( & V_10 -> V_9 ) ;
F_265 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
bool F_266 ( struct V_7 * V_10 , unsigned long V_81 )
{
unsigned long V_263 = V_10 -> V_9 . V_23 . V_263 ;
bool V_50 = false ;
T_2 V_22 ;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! F_7 ( & V_10 -> V_9 ) ||
( ! ( V_22 & ( 1ULL << V_221 ) ) ) )
return false ;
V_263 &= ~ V_344 ;
V_81 &= ~ V_344 ;
if ( V_263 ^ V_81 ) {
V_10 -> V_1 -> V_2 . V_406 = V_506 ;
V_50 = ( F_222 ( V_10 ) == V_419 ) ;
}
return V_50 ;
}
static int F_267 ( struct V_7 * V_10 )
{
int V_310 , V_507 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_38 ( V_505 ) )
return F_262 ( V_10 ) ;
if ( F_124 ( ( V_10 -> V_1 -> V_2 . V_370 & V_508 ) == 0 ) )
return F_262 ( V_10 ) ;
V_310 = V_10 -> V_1 -> V_2 . V_370 & V_509 ;
V_507 = V_10 -> V_1 -> V_2 . V_406 - V_434 ;
V_80 = 0 ;
if ( V_507 >= 16 ) {
V_507 -= 16 ;
V_81 = F_253 ( & V_10 -> V_9 , V_310 ) ;
switch ( V_507 ) {
case 0 :
if ( ! F_266 ( V_10 , V_81 ) )
V_80 = F_109 ( & V_10 -> V_9 , V_81 ) ;
else
return 1 ;
break;
case 3 :
V_80 = F_230 ( & V_10 -> V_9 , V_81 ) ;
break;
case 4 :
V_80 = F_268 ( & V_10 -> V_9 , V_81 ) ;
break;
case 8 :
V_80 = F_269 ( & V_10 -> V_9 , V_81 ) ;
break;
default:
F_98 ( 1 , L_12 , V_507 ) ;
F_172 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
} else {
switch ( V_507 ) {
case 0 :
V_81 = F_226 ( & V_10 -> V_9 ) ;
break;
case 2 :
V_81 = V_10 -> V_9 . V_23 . V_418 ;
break;
case 3 :
V_81 = F_138 ( & V_10 -> V_9 ) ;
break;
case 4 :
V_81 = F_270 ( & V_10 -> V_9 ) ;
break;
case 8 :
V_81 = F_271 ( & V_10 -> V_9 ) ;
break;
default:
F_98 ( 1 , L_13 , V_507 ) ;
F_172 ( & V_10 -> V_9 , V_216 ) ;
return 1 ;
}
F_112 ( & V_10 -> V_9 , V_310 , V_81 ) ;
}
F_265 ( & V_10 -> V_9 , V_80 ) ;
return 1 ;
}
static int F_272 ( struct V_7 * V_10 )
{
int V_310 , V_510 ;
unsigned long V_81 ;
int V_80 ;
if ( ! F_84 ( V_505 ) )
return F_262 ( V_10 ) ;
V_310 = V_10 -> V_1 -> V_2 . V_370 & V_509 ;
V_510 = V_10 -> V_1 -> V_2 . V_406 - V_436 ;
if ( V_510 >= 16 ) {
V_81 = F_253 ( & V_10 -> V_9 , V_310 ) ;
F_273 ( & V_10 -> V_9 , V_510 - 16 , V_81 ) ;
} else {
V_80 = F_274 ( & V_10 -> V_9 , V_510 , & V_81 ) ;
if ( ! V_80 )
F_112 ( & V_10 -> V_9 , V_310 , V_81 ) ;
}
F_31 ( & V_10 -> V_9 ) ;
return 1 ;
}
static int F_275 ( struct V_7 * V_10 )
{
struct V_375 * V_375 = V_10 -> V_9 . V_376 ;
int V_126 ;
T_4 V_511 = F_271 ( & V_10 -> V_9 ) ;
V_126 = F_267 ( V_10 ) ;
if ( F_276 ( V_10 -> V_9 . V_278 ) ) {
F_10 ( V_10 , V_198 ) ;
return V_126 ;
}
if ( V_511 <= F_271 ( & V_10 -> V_9 ) )
return V_126 ;
V_375 -> V_379 = V_512 ;
return 0 ;
}
T_2 F_277 ( struct V_8 * V_9 , T_2 V_513 )
{
struct V_1 * V_1 = F_8 ( F_4 ( V_9 ) ) ;
return V_1 -> V_2 . V_185 +
F_96 ( V_9 , V_513 ) ;
}
static int F_278 ( struct V_8 * V_9 , unsigned V_514 , T_2 * V_515 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
switch ( V_514 ) {
case V_516 : {
* V_515 = V_10 -> V_1 -> V_2 . V_185 +
F_96 ( V_9 , F_105 () ) ;
break;
}
case V_517 :
* V_515 = V_10 -> V_1 -> V_42 . V_462 ;
break;
#ifdef F_26
case V_518 :
* V_515 = V_10 -> V_1 -> V_42 . V_463 ;
break;
case V_519 :
* V_515 = V_10 -> V_1 -> V_42 . V_464 ;
break;
case V_302 :
* V_515 = V_10 -> V_1 -> V_42 . V_461 ;
break;
case V_520 :
* V_515 = V_10 -> V_1 -> V_42 . V_465 ;
break;
#endif
case V_521 :
* V_515 = V_10 -> V_1 -> V_42 . V_466 ;
break;
case V_522 :
* V_515 = V_10 -> V_468 ;
break;
case V_523 :
* V_515 = V_10 -> V_467 ;
break;
case V_524 :
* V_515 = V_10 -> V_1 -> V_42 . V_525 ;
break;
case V_144 :
* V_515 = V_10 -> V_1 -> V_42 . V_526 ;
break;
case V_145 :
* V_515 = V_10 -> V_1 -> V_42 . V_527 ;
break;
case V_146 :
* V_515 = V_10 -> V_1 -> V_42 . V_528 ;
break;
case V_147 :
* V_515 = V_10 -> V_1 -> V_42 . V_529 ;
break;
case V_117 :
* V_515 = V_10 -> V_17 . V_530 ;
break;
case V_531 :
* V_515 = V_10 -> V_17 . V_532 ;
break;
case V_533 :
* V_515 = 0x01000065 ;
break;
default:
return F_279 ( V_9 , V_514 , V_515 ) ;
}
return 0 ;
}
static int F_280 ( struct V_7 * V_10 )
{
T_1 V_514 = V_10 -> V_9 . V_23 . V_261 [ V_429 ] ;
T_2 V_515 ;
if ( F_278 ( & V_10 -> V_9 , V_514 , & V_515 ) ) {
F_281 ( V_514 ) ;
F_205 ( & V_10 -> V_9 , 0 ) ;
} else {
F_282 ( V_514 , V_515 ) ;
V_10 -> V_9 . V_23 . V_261 [ V_454 ] = V_515 & 0xffffffff ;
V_10 -> V_9 . V_23 . V_261 [ V_277 ] = V_515 >> 32 ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_283 ( struct V_8 * V_9 , T_2 V_515 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_534 , V_535 ;
if ( V_515 & ~ V_536 )
return 1 ;
V_535 = V_536 ;
if ( V_10 -> V_17 . V_532 & V_537 )
V_535 &= ~ ( V_538 | V_537 ) ;
V_10 -> V_17 . V_532 &= ~ V_535 ;
V_10 -> V_17 . V_532 |= ( V_515 & V_535 ) ;
V_534 = V_10 -> V_17 . V_532 & V_537 ;
if ( V_534 && ( V_9 -> V_23 . V_38 & V_43 ) )
return 1 ;
return 0 ;
}
static int F_284 ( struct V_8 * V_9 , struct V_539 * V_26 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_1 V_514 = V_26 -> V_130 ;
T_2 V_515 = V_26 -> V_515 ;
switch ( V_514 ) {
case V_516 :
F_285 ( V_9 , V_26 ) ;
break;
case V_517 :
V_10 -> V_1 -> V_42 . V_462 = V_515 ;
break;
#ifdef F_26
case V_518 :
V_10 -> V_1 -> V_42 . V_463 = V_515 ;
break;
case V_519 :
V_10 -> V_1 -> V_42 . V_464 = V_515 ;
break;
case V_302 :
V_10 -> V_1 -> V_42 . V_461 = V_515 ;
break;
case V_520 :
V_10 -> V_1 -> V_42 . V_465 = V_515 ;
break;
#endif
case V_521 :
V_10 -> V_1 -> V_42 . V_466 = V_515 ;
break;
case V_522 :
V_10 -> V_468 = V_515 ;
V_10 -> V_1 -> V_42 . V_468 = V_515 ;
break;
case V_523 :
V_10 -> V_467 = V_515 ;
V_10 -> V_1 -> V_42 . V_467 = V_515 ;
break;
case V_524 :
if ( ! F_84 ( V_540 ) ) {
F_286 ( V_9 , L_14 ,
V_59 , V_515 ) ;
break;
}
if ( V_515 & V_541 )
return 1 ;
V_10 -> V_1 -> V_42 . V_525 = V_515 ;
F_3 ( V_10 -> V_1 , V_542 ) ;
if ( V_515 & ( 1ULL << 0 ) )
F_79 ( V_10 ) ;
else
F_80 ( V_10 ) ;
break;
case V_117 :
V_10 -> V_17 . V_530 = V_515 ;
break;
case V_531 :
return F_283 ( V_9 , V_515 ) ;
case V_543 :
F_286 ( V_9 , L_15 , V_514 , V_515 ) ;
break;
default:
return F_287 ( V_9 , V_26 ) ;
}
return 0 ;
}
static int F_288 ( struct V_7 * V_10 )
{
struct V_539 V_26 ;
T_1 V_514 = V_10 -> V_9 . V_23 . V_261 [ V_429 ] ;
T_2 V_515 = ( V_10 -> V_9 . V_23 . V_261 [ V_454 ] & - 1u )
| ( ( T_2 ) ( V_10 -> V_9 . V_23 . V_261 [ V_277 ] & - 1u ) << 32 ) ;
V_26 . V_515 = V_515 ;
V_26 . V_130 = V_514 ;
V_26 . V_544 = false ;
V_10 -> V_55 = F_34 ( & V_10 -> V_9 ) + 2 ;
if ( F_284 ( & V_10 -> V_9 , & V_26 ) ) {
F_289 ( V_514 , V_515 ) ;
F_205 ( & V_10 -> V_9 , 0 ) ;
} else {
F_290 ( V_514 , V_515 ) ;
F_31 ( & V_10 -> V_9 ) ;
}
return 1 ;
}
static int F_291 ( struct V_7 * V_10 )
{
if ( V_10 -> V_1 -> V_2 . V_370 )
return F_288 ( V_10 ) ;
else
return F_280 ( V_10 ) ;
}
static int F_292 ( struct V_7 * V_10 )
{
struct V_375 * V_375 = V_10 -> V_9 . V_376 ;
F_181 ( V_470 , & V_10 -> V_9 ) ;
F_140 ( V_10 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_471 ;
F_3 ( V_10 -> V_1 , V_472 ) ;
++ V_10 -> V_9 . V_300 . V_545 ;
if ( ! F_276 ( V_10 -> V_9 . V_278 ) &&
V_375 -> V_546 &&
! F_293 ( & V_10 -> V_9 ) ) {
V_375 -> V_379 = V_547 ;
return 0 ;
}
return 1 ;
}
static int F_294 ( struct V_7 * V_10 )
{
F_295 ( & ( V_10 -> V_9 ) ) ;
return 1 ;
}
static void F_296 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
struct V_190 * V_42 = & V_10 -> V_1 -> V_42 ;
F_55 ( L_16 ) ;
F_55 ( L_17 , L_18 , V_2 -> V_19 & 0xffff ) ;
F_55 ( L_17 , L_19 , V_2 -> V_19 >> 16 ) ;
F_55 ( L_17 , L_20 , V_2 -> V_20 & 0xffff ) ;
F_55 ( L_17 , L_21 , V_2 -> V_20 >> 16 ) ;
F_55 ( L_22 , L_23 , V_2 -> V_21 ) ;
F_55 ( L_24 , L_25 , V_2 -> V_22 ) ;
F_55 ( L_26 , L_27 , V_2 -> V_273 ) ;
F_55 ( L_24 , L_28 , V_2 -> V_243 ) ;
F_55 ( L_24 , L_29 , V_2 -> V_244 ) ;
F_55 ( L_24 , L_30 , V_2 -> V_185 ) ;
F_55 ( L_26 , L_31 , V_2 -> V_35 ) ;
F_55 ( L_26 , L_32 , V_2 -> V_361 ) ;
F_55 ( L_22 , L_33 , V_2 -> V_245 ) ;
F_55 ( L_22 , L_34 , V_2 -> V_445 ) ;
F_55 ( L_22 , L_35 , V_2 -> V_51 ) ;
F_55 ( L_22 , L_36 , V_2 -> V_406 ) ;
F_55 ( L_24 , L_37 , V_2 -> V_370 ) ;
F_55 ( L_24 , L_38 , V_2 -> V_368 ) ;
F_55 ( L_22 , L_39 , V_2 -> V_446 ) ;
F_55 ( L_22 , L_40 , V_2 -> V_447 ) ;
F_55 ( L_41 , L_42 , V_2 -> V_269 ) ;
F_55 ( L_24 , L_43 , V_2 -> V_400 ) ;
F_55 ( L_22 , L_44 , V_2 -> V_74 ) ;
F_55 ( L_22 , L_45 , V_2 -> V_77 ) ;
F_55 ( L_41 , L_46 , V_2 -> V_143 ) ;
F_55 ( L_24 , L_47 , V_2 -> V_55 ) ;
F_55 ( L_48 ) ;
F_55 ( L_49 ,
L_50 ,
V_42 -> V_247 . V_167 , V_42 -> V_247 . V_168 ,
V_42 -> V_247 . V_172 , V_42 -> V_247 . V_72 ) ;
F_55 ( L_49 ,
L_51 ,
V_42 -> V_71 . V_167 , V_42 -> V_71 . V_168 ,
V_42 -> V_71 . V_172 , V_42 -> V_71 . V_72 ) ;
F_55 ( L_49 ,
L_52 ,
V_42 -> V_248 . V_167 , V_42 -> V_248 . V_168 ,
V_42 -> V_248 . V_172 , V_42 -> V_248 . V_72 ) ;
F_55 ( L_49 ,
L_53 ,
V_42 -> V_249 . V_167 , V_42 -> V_249 . V_168 ,
V_42 -> V_249 . V_172 , V_42 -> V_249 . V_72 ) ;
F_55 ( L_49 ,
L_54 ,
V_42 -> V_250 . V_167 , V_42 -> V_250 . V_168 ,
V_42 -> V_250 . V_172 , V_42 -> V_250 . V_72 ) ;
F_55 ( L_49 ,
L_55 ,
V_42 -> V_251 . V_167 , V_42 -> V_251 . V_168 ,
V_42 -> V_251 . V_172 , V_42 -> V_251 . V_72 ) ;
F_55 ( L_49 ,
L_56 ,
V_42 -> V_254 . V_167 , V_42 -> V_254 . V_168 ,
V_42 -> V_254 . V_172 , V_42 -> V_254 . V_72 ) ;
F_55 ( L_49 ,
L_57 ,
V_42 -> V_256 . V_167 , V_42 -> V_256 . V_168 ,
V_42 -> V_256 . V_172 , V_42 -> V_256 . V_72 ) ;
F_55 ( L_49 ,
L_58 ,
V_42 -> V_255 . V_167 , V_42 -> V_255 . V_168 ,
V_42 -> V_255 . V_172 , V_42 -> V_255 . V_72 ) ;
F_55 ( L_49 ,
L_59 ,
V_42 -> V_258 . V_167 , V_42 -> V_258 . V_168 ,
V_42 -> V_258 . V_172 , V_42 -> V_258 . V_72 ) ;
F_55 ( L_60 ,
V_42 -> V_305 , V_42 -> V_38 ) ;
F_55 ( L_61 ,
L_62 , V_42 -> V_263 , L_63 , V_42 -> V_418 ) ;
F_55 ( L_61 ,
L_64 , V_42 -> V_271 , L_65 , V_42 -> V_267 ) ;
F_55 ( L_61 ,
L_66 , V_42 -> V_260 , L_67 , V_42 -> V_365 ) ;
F_55 ( L_61 ,
L_68 , V_42 -> V_68 , L_69 , V_42 -> V_306 ) ;
F_55 ( L_61 ,
L_70 , V_42 -> V_450 , L_71 , V_42 -> V_451 ) ;
F_55 ( L_61 ,
L_72 , V_42 -> V_462 , L_73 , V_42 -> V_463 ) ;
F_55 ( L_61 ,
L_74 , V_42 -> V_464 , L_75 , V_42 -> V_465 ) ;
F_55 ( L_61 ,
L_76 , V_42 -> V_461 ,
L_77 , V_42 -> V_466 ) ;
F_55 ( L_61 ,
L_78 , V_42 -> V_467 ,
L_79 , V_42 -> V_468 ) ;
F_55 ( L_61 ,
L_80 , V_42 -> V_270 , L_81 , V_42 -> V_525 ) ;
F_55 ( L_61 ,
L_82 , V_42 -> V_526 , L_83 , V_42 -> V_527 ) ;
F_55 ( L_61 ,
L_84 , V_42 -> V_528 ,
L_85 , V_42 -> V_529 ) ;
}
static void F_297 ( struct V_8 * V_9 , T_2 * V_548 , T_2 * V_549 )
{
struct V_11 * V_2 = & F_4 ( V_9 ) -> V_1 -> V_2 ;
* V_548 = V_2 -> V_370 ;
* V_549 = V_2 -> V_368 ;
}
static int F_298 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_375 * V_375 = V_9 -> V_376 ;
T_1 V_406 = V_10 -> V_1 -> V_2 . V_406 ;
if ( ! F_11 ( V_10 , V_195 ) )
V_9 -> V_23 . V_263 = V_10 -> V_1 -> V_42 . V_263 ;
if ( V_39 )
V_9 -> V_23 . V_271 = V_10 -> V_1 -> V_42 . V_271 ;
if ( F_124 ( V_10 -> V_17 . V_420 ) ) {
F_200 ( V_10 ) ;
V_10 -> V_17 . V_420 = false ;
return 1 ;
}
if ( F_7 ( V_9 ) ) {
int V_416 ;
F_299 ( V_10 -> V_1 -> V_42 . V_68 , V_406 ,
V_10 -> V_1 -> V_2 . V_370 ,
V_10 -> V_1 -> V_2 . V_368 ,
V_10 -> V_1 -> V_2 . V_446 ,
V_10 -> V_1 -> V_2 . V_447 ,
V_449 ) ;
V_416 = F_221 ( V_10 ) ;
if ( V_416 == V_431 )
V_416 = F_222 ( V_10 ) ;
if ( V_416 == V_419 )
return 1 ;
}
F_300 ( V_10 ) ;
if ( V_10 -> V_1 -> V_2 . V_406 == V_439 ) {
V_375 -> V_379 = V_550 ;
V_375 -> V_551 . V_552
= V_10 -> V_1 -> V_2 . V_406 ;
F_55 ( L_86 ) ;
F_296 ( V_9 ) ;
return 0 ;
}
if ( F_28 ( V_10 -> V_1 -> V_2 . V_446 ) &&
V_406 != V_417 + V_215 &&
V_406 != V_407 && V_406 != V_553 &&
V_406 != V_423 && V_406 != V_424 )
F_33 ( V_61 L_87
L_88 ,
V_59 , V_10 -> V_1 -> V_2 . V_446 ,
V_406 ) ;
if ( V_406 >= F_301 ( V_554 )
|| ! V_554 [ V_406 ] ) {
V_375 -> V_379 = V_555 ;
V_375 -> V_556 . V_557 = V_406 ;
return 0 ;
}
return V_554 [ V_406 ] ( V_10 ) ;
}
static void F_302 ( struct V_8 * V_9 )
{
int V_125 = F_53 () ;
struct V_98 * V_99 = F_56 ( V_108 , V_125 ) ;
V_99 -> V_114 -> type = 9 ;
F_303 () ;
}
static void F_304 ( struct V_7 * V_10 )
{
int V_125 = F_53 () ;
struct V_98 * V_99 = F_56 ( V_108 , V_125 ) ;
if ( V_10 -> V_109 != V_99 -> V_109 )
F_160 ( V_10 , V_99 ) ;
}
static void F_305 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_74 = V_47 | V_558 ;
V_9 -> V_23 . V_24 |= V_559 ;
F_16 ( V_10 , V_502 ) ;
++ V_9 -> V_300 . V_560 ;
}
static inline void F_306 ( struct V_7 * V_10 , int V_561 )
{
struct V_11 * V_2 ;
V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_445 = V_561 ;
V_2 -> V_245 &= ~ V_562 ;
V_2 -> V_245 |= V_471 |
( ( 0xf ) << V_563 ) ;
F_3 ( V_10 -> V_1 , V_472 ) ;
}
static void F_307 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_72 ( ! ( F_20 ( V_10 ) ) ) ;
F_308 ( V_9 -> V_23 . V_564 . V_62 ) ;
++ V_9 -> V_300 . V_565 ;
V_10 -> V_1 -> V_2 . V_74 = V_9 -> V_23 . V_564 . V_62 |
V_47 | V_48 ;
}
static void F_309 ( struct V_8 * V_9 , int V_566 , int V_567 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_421 ) )
return;
if ( V_567 == - 1 )
return;
if ( V_566 >= V_567 )
F_9 ( V_10 , V_198 ) ;
}
static void F_310 ( struct V_8 * V_9 , bool V_568 )
{
return;
}
static int F_311 ( struct V_278 * V_278 )
{
return 0 ;
}
static void F_312 ( struct V_8 * V_9 , T_2 * V_569 )
{
return;
}
static void F_313 ( struct V_278 * V_278 , int V_570 )
{
return;
}
static void F_314 ( struct V_8 * V_9 )
{
return;
}
static int F_315 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
V_50 = ! ( V_1 -> V_2 . V_51 & V_52 ) &&
! ( V_10 -> V_9 . V_23 . V_24 & V_559 ) ;
V_50 = V_50 && F_20 ( V_10 ) && F_209 ( V_10 ) ;
return V_50 ;
}
static bool F_316 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
return ! ! ( V_10 -> V_9 . V_23 . V_24 & V_559 ) ;
}
static void F_317 ( struct V_8 * V_9 , bool V_571 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( V_571 ) {
V_10 -> V_9 . V_23 . V_24 |= V_559 ;
F_16 ( V_10 , V_502 ) ;
} else {
V_10 -> V_9 . V_23 . V_24 &= ~ V_559 ;
F_17 ( V_10 , V_502 ) ;
}
}
static int F_318 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_50 ;
if ( ! F_20 ( V_10 ) ||
( V_1 -> V_2 . V_51 & V_52 ) )
return 0 ;
V_50 = ! ! ( F_227 ( V_9 ) & V_458 ) ;
if ( F_7 ( V_9 ) )
return V_50 && ! ( V_10 -> V_9 . V_23 . V_24 & V_421 ) ;
return V_50 ;
}
static int F_319 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_20 ( V_10 ) && F_207 ( V_10 ) ) {
F_139 ( V_10 ) ;
F_306 ( V_10 , 0x0 ) ;
}
return 0 ;
}
static int F_320 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( ( V_10 -> V_9 . V_23 . V_24 & ( V_559 | V_503 ) )
== V_559 )
return 0 ;
V_10 -> V_355 = true ;
V_10 -> V_1 -> V_42 . V_306 |= ( V_377 | V_378 ) ;
F_159 ( V_9 ) ;
return 0 ;
}
static int F_321 ( struct V_278 * V_278 , unsigned int V_34 )
{
return 0 ;
}
static void F_157 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_38 ( V_572 ) )
V_10 -> V_1 -> V_2 . V_361 = V_573 ;
else
V_10 -> V_109 -- ;
}
static void F_322 ( struct V_8 * V_9 )
{
}
static inline void F_323 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_421 ) )
return;
if ( ! F_11 ( V_10 , V_198 ) ) {
int V_574 = V_10 -> V_1 -> V_2 . V_245 & V_575 ;
F_269 ( V_9 , V_574 ) ;
}
}
static inline void F_324 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
T_2 V_574 ;
if ( F_7 ( V_9 ) && ( V_9 -> V_23 . V_24 & V_421 ) )
return;
V_574 = F_271 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_245 &= ~ V_575 ;
V_10 -> V_1 -> V_2 . V_245 |= V_574 & V_575 ;
}
static void F_300 ( struct V_7 * V_10 )
{
T_4 V_576 ;
int type ;
T_1 V_577 = V_10 -> V_1 -> V_2 . V_446 ;
unsigned V_73 = V_10 -> V_73 ;
V_10 -> V_73 = 0 ;
if ( ( V_10 -> V_9 . V_23 . V_24 & V_503 )
&& F_34 ( & V_10 -> V_9 ) != V_10 -> V_504 ) {
V_10 -> V_9 . V_23 . V_24 &= ~ ( V_559 | V_503 ) ;
F_181 ( V_470 , & V_10 -> V_9 ) ;
}
V_10 -> V_9 . V_23 . V_489 = false ;
F_228 ( & V_10 -> V_9 ) ;
F_229 ( & V_10 -> V_9 ) ;
if ( ! ( V_577 & V_481 ) )
return;
F_181 ( V_470 , & V_10 -> V_9 ) ;
V_576 = V_577 & V_578 ;
type = V_577 & V_477 ;
switch ( type ) {
case V_488 :
V_10 -> V_9 . V_23 . V_489 = true ;
break;
case V_490 :
if ( F_325 ( V_576 ) ) {
if ( V_576 == V_66 && V_73 &&
F_326 ( & V_10 -> V_9 , V_10 -> V_70 ) )
F_35 ( & V_10 -> V_9 ,
F_34 ( & V_10 -> V_9 ) -
V_73 ) ;
break;
}
if ( V_577 & V_579 ) {
T_1 V_80 = V_10 -> V_1 -> V_2 . V_447 ;
F_327 ( & V_10 -> V_9 , V_576 , V_80 ) ;
} else
F_328 ( & V_10 -> V_9 , V_576 ) ;
break;
case V_492 :
F_329 ( & V_10 -> V_9 , V_576 , false ) ;
break;
default:
break;
}
}
static void F_330 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_11 * V_2 = & V_10 -> V_1 -> V_2 ;
V_2 -> V_446 = V_2 -> V_74 ;
V_2 -> V_447 = V_2 -> V_77 ;
V_2 -> V_74 = 0 ;
F_300 ( V_10 ) ;
}
static void F_331 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_451 = V_9 -> V_23 . V_261 [ V_454 ] ;
V_10 -> V_1 -> V_42 . V_450 = V_9 -> V_23 . V_261 [ V_455 ] ;
V_10 -> V_1 -> V_42 . V_68 = V_9 -> V_23 . V_261 [ V_262 ] ;
if ( F_124 ( V_10 -> V_17 . V_420 ) )
return;
F_304 ( V_10 ) ;
F_324 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_418 = V_9 -> V_23 . V_418 ;
F_22 () ;
F_169 () ;
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
F_49 ( V_294 , V_10 -> V_188 . V_295 ) ;
#else
F_129 ( V_250 , V_10 -> V_188 . V_250 ) ;
#ifndef F_131
F_129 ( V_251 , V_10 -> V_188 . V_251 ) ;
#endif
#endif
F_302 ( V_9 ) ;
F_167 () ;
V_9 -> V_23 . V_418 = V_10 -> V_1 -> V_42 . V_418 ;
V_9 -> V_23 . V_261 [ V_454 ] = V_10 -> V_1 -> V_42 . V_451 ;
V_9 -> V_23 . V_261 [ V_455 ] = V_10 -> V_1 -> V_42 . V_450 ;
V_9 -> V_23 . V_261 [ V_262 ] = V_10 -> V_1 -> V_42 . V_68 ;
F_332 ( V_10 -> V_1 -> V_2 . V_406 , V_9 , V_449 ) ;
if ( F_124 ( V_10 -> V_1 -> V_2 . V_406 == V_424 ) )
F_333 ( & V_10 -> V_9 ) ;
F_23 () ;
if ( F_124 ( V_10 -> V_1 -> V_2 . V_406 == V_424 ) )
F_334 ( & V_10 -> V_9 ) ;
F_323 ( V_9 ) ;
V_10 -> V_55 = 0 ;
V_10 -> V_1 -> V_2 . V_361 = V_580 ;
if ( V_10 -> V_1 -> V_2 . V_406 == V_417 + V_215 )
V_10 -> V_369 = F_335 () ;
if ( V_39 ) {
V_9 -> V_23 . V_581 &= ~ ( 1 << V_311 ) ;
V_9 -> V_23 . V_582 &= ~ ( 1 << V_311 ) ;
}
if ( F_124 ( V_10 -> V_1 -> V_2 . V_406 ==
V_417 + V_217 ) )
F_180 ( V_10 ) ;
F_2 ( V_10 -> V_1 ) ;
}
static void F_336 ( struct V_8 * V_9 , unsigned long V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_42 . V_271 = V_402 ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_157 ( V_9 ) ;
}
static void F_337 ( struct V_8 * V_9 , unsigned long V_402 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
V_10 -> V_1 -> V_2 . V_400 = V_402 ;
F_3 ( V_10 -> V_1 , V_403 ) ;
V_10 -> V_1 -> V_42 . V_271 = F_138 ( V_9 ) ;
F_3 ( V_10 -> V_1 , V_44 ) ;
F_157 ( V_9 ) ;
}
static int F_338 ( void )
{
T_2 V_583 ;
F_54 ( V_531 , V_583 ) ;
if ( V_583 & ( 1 << V_584 ) )
return 1 ;
return 0 ;
}
static void
F_339 ( struct V_8 * V_9 , unsigned char * V_585 )
{
V_585 [ 0 ] = 0x0f ;
V_585 [ 1 ] = 0x01 ;
V_585 [ 2 ] = 0xd9 ;
}
static void F_340 ( void * V_586 )
{
* ( int * ) V_586 = 0 ;
}
static bool F_341 ( void )
{
return false ;
}
static T_2 F_342 ( struct V_8 * V_9 , T_11 V_587 , bool V_588 )
{
return 0 ;
}
static void F_343 ( struct V_8 * V_9 )
{
}
static void F_344 ( T_1 V_589 , struct V_590 * V_591 )
{
switch ( V_589 ) {
case 0x80000001 :
if ( V_17 )
V_591 -> V_514 |= ( 1 << 2 ) ;
break;
case 0x8000000A :
V_591 -> V_276 = 1 ;
V_591 -> V_592 = 8 ;
V_591 -> V_514 = 0 ;
V_591 -> V_593 = 0 ;
if ( F_84 ( V_67 ) )
V_591 -> V_593 |= V_594 ;
if ( V_39 )
V_591 -> V_593 |= V_595 ;
break;
}
}
static int F_345 ( void )
{
return V_596 ;
}
static bool F_346 ( void )
{
return false ;
}
static bool F_347 ( void )
{
return false ;
}
static bool F_348 ( void )
{
return true ;
}
static void F_349 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
F_14 ( V_10 , V_386 ) ;
F_152 ( V_10 ) ;
}
static int F_350 ( struct V_8 * V_9 ,
struct V_597 * V_45 ,
enum V_598 V_599 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
int V_416 , V_50 = V_600 ;
struct V_601 V_602 ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_45 -> V_22 >= F_301 ( V_603 ) )
goto V_284;
V_602 = V_603 [ V_45 -> V_22 ] ;
if ( V_599 != V_602 . V_599 )
goto V_284;
switch ( V_602 . V_406 ) {
case V_434 :
if ( V_45 -> V_22 == V_604 )
V_602 . V_406 += V_45 -> V_605 ;
break;
case V_606 : {
unsigned long V_263 , V_81 ;
T_2 V_22 ;
if ( V_45 -> V_22 == V_607 )
V_602 . V_406 += V_45 -> V_605 ;
if ( V_602 . V_406 != V_606 )
break;
V_22 = V_10 -> V_17 . V_22 ;
if ( ! ( V_22 & ( 1ULL << V_221 ) ) )
break;
V_263 = V_9 -> V_23 . V_263 & ~ V_344 ;
V_81 = V_45 -> V_608 & ~ V_344 ;
if ( V_45 -> V_22 == V_609 ) {
V_263 &= 0xfUL ;
V_81 &= 0xfUL ;
if ( V_263 & V_453 )
V_81 |= V_453 ;
}
if ( V_263 ^ V_81 )
V_602 . V_406 = V_506 ;
break;
}
case V_436 :
case V_610 :
V_602 . V_406 += V_45 -> V_605 ;
break;
case V_432 :
if ( V_45 -> V_22 == V_611 )
V_1 -> V_2 . V_370 = 1 ;
else
V_1 -> V_2 . V_370 = 0 ;
break;
case V_612 :
if ( V_45 -> V_613 != V_614 )
goto V_284;
case V_433 : {
T_2 V_615 ;
T_1 V_616 ;
V_615 = ( V_9 -> V_23 . V_261 [ V_277 ] & 0xffff ) << 16 ;
if ( V_45 -> V_22 == V_617 ||
V_45 -> V_22 == V_618 ) {
V_615 |= V_396 ;
V_616 = V_45 -> V_619 ;
} else {
V_616 = V_45 -> V_620 ;
}
if ( V_45 -> V_22 == V_621 ||
V_45 -> V_22 == V_618 )
V_615 |= V_395 ;
if ( V_45 -> V_613 )
V_615 |= V_622 ;
V_616 = F_86 ( V_616 , 4u ) ;
V_615 |= V_616 << V_398 ;
V_615 |= ( T_1 ) V_45 -> V_623 << ( V_624 - 1 ) ;
V_1 -> V_2 . V_370 = V_615 ;
V_1 -> V_2 . V_368 = V_45 -> V_55 ;
break;
}
default:
break;
}
V_1 -> V_2 . V_55 = V_45 -> V_55 ;
V_1 -> V_2 . V_406 = V_602 . V_406 ;
V_416 = F_222 ( V_10 ) ;
V_50 = ( V_416 == V_419 ) ? V_625
: V_600 ;
V_284:
return V_50 ;
}
static void F_351 ( struct V_8 * V_9 )
{
F_169 () ;
}
static int T_5 F_352 ( void )
{
return F_353 ( & V_626 , sizeof( struct V_7 ) ,
F_354 ( struct V_7 ) , V_627 ) ;
}
static void T_6 F_355 ( void )
{
F_356 () ;
}
