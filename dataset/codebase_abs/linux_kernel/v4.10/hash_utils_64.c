unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = 0 ;
if ( ( V_1 & V_3 ) == 0 )
V_2 |= V_4 ;
if ( V_1 & V_5 ) {
if ( ! ( V_1 & V_6 ) ) {
if ( F_2 ( V_7 ) )
V_2 |= ( V_8 | 0x2 ) ;
else
V_2 |= 0x3 ;
}
} else {
if ( V_1 & V_9 )
V_2 |= 0x2 ;
if ( ! ( ( V_1 & V_6 ) && ( V_1 & V_10 ) ) )
V_2 |= 0x1 ;
}
V_2 |= V_11 ;
if ( V_1 & V_10 )
V_2 |= V_12 ;
if ( ( V_1 & V_13 ) == V_14 )
V_2 |= V_15 ;
else if ( ( V_1 & V_13 ) == V_16 )
V_2 |= ( V_15 | V_17 ) ;
else if ( ( V_1 & V_13 ) == V_18 )
V_2 |= ( V_19 | V_15 | V_20 ) ;
else
V_2 |= V_20 ;
return V_2 ;
}
int F_3 ( unsigned long V_21 , unsigned long V_22 ,
unsigned long V_23 , unsigned long V_24 ,
int V_25 , int V_26 )
{
unsigned long V_27 , V_28 ;
unsigned int V_29 , V_30 ;
int V_31 = 0 ;
V_30 = V_32 [ V_25 ] . V_30 ;
V_29 = 1 << V_30 ;
V_24 = F_1 ( V_24 ) ;
F_4 ( L_1 ,
V_21 , V_22 , V_23 , V_24 , V_25 , V_26 ) ;
for ( V_27 = V_21 , V_28 = V_23 ; V_27 < V_22 ;
V_27 += V_29 , V_28 += V_29 ) {
unsigned long V_33 , V_34 ;
unsigned long V_35 = F_5 ( V_27 , V_26 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_26 ) ;
unsigned long V_37 = V_24 ;
if ( ! V_35 )
return - 1 ;
if ( F_7 ( V_27 , V_27 + V_29 ) )
V_37 &= ~ V_4 ;
if ( F_8 ( V_27 , V_27 + V_29 ) )
V_37 &= ~ V_4 ;
if ( ( V_38 > V_39 ) &&
F_9 ( V_27 , V_27 + V_29 ) )
V_37 &= ~ V_4 ;
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
V_34 = ( ( V_33 & V_40 ) * V_41 ) ;
F_11 ( ! V_42 . V_43 ) ;
V_31 = V_42 . V_43 ( V_34 , V_36 , V_28 , V_37 ,
V_44 , V_25 , V_25 ,
V_26 ) ;
if ( V_31 < 0 )
break;
#ifdef F_12
if ( F_13 () &&
( V_28 >> V_45 ) < V_46 )
V_47 [ V_28 >> V_45 ] = V_31 | 0x80 ;
#endif
}
return V_31 < 0 ? V_31 : 0 ;
}
int F_14 ( unsigned long V_21 , unsigned long V_22 ,
int V_25 , int V_26 )
{
unsigned long V_27 ;
unsigned int V_29 , V_30 ;
int V_48 ;
int V_31 = 0 ;
V_30 = V_32 [ V_25 ] . V_30 ;
V_29 = 1 << V_30 ;
if ( ! V_42 . V_49 )
return - V_50 ;
for ( V_27 = V_21 ; V_27 < V_22 ; V_27 += V_29 ) {
V_48 = V_42 . V_49 ( V_27 , V_25 , V_26 ) ;
if ( V_48 == - V_51 ) {
V_31 = - V_51 ;
continue;
}
if ( V_48 < 0 )
return V_48 ;
}
return V_31 ;
}
static int T_1 F_15 ( char * V_52 )
{
V_53 = true ;
return 0 ;
}
static int T_1 F_16 ( unsigned long V_54 ,
const char * V_55 , int V_56 ,
void * V_57 )
{
const char * type = F_17 ( V_54 , L_2 , NULL ) ;
const T_2 * V_58 ;
int V_59 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_58 = F_17 ( V_54 , L_4 , & V_59 ) ;
if ( V_58 == NULL )
return 0 ;
for (; V_59 >= 4 ; V_59 -= 4 , ++ V_58 ) {
if ( F_18 ( V_58 [ 0 ] ) == 40 ) {
F_4 ( L_5 ) ;
if ( V_53 ) {
F_4 ( L_6 ) ;
break;
}
V_60 -> V_61 |= V_62 ;
return 1 ;
}
}
V_60 -> V_61 &= ~ V_63 ;
return 0 ;
}
static int T_1 F_19 ( unsigned int V_30 )
{
int V_64 = - 1 ;
switch ( V_30 ) {
case 0xc :
V_64 = V_65 ;
break;
case 0x10 :
V_64 = V_66 ;
break;
case 0x14 :
V_64 = V_67 ;
break;
case 0x18 :
V_64 = V_68 ;
break;
case 0x22 :
V_64 = V_69 ;
break;
}
return V_64 ;
}
static int T_1 F_20 ( unsigned long V_54 ,
const char * V_55 , int V_56 ,
void * V_57 )
{
const char * type = F_17 ( V_54 , L_2 , NULL ) ;
const T_2 * V_58 ;
int V_59 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_58 = F_17 ( V_54 , L_7 , & V_59 ) ;
if ( ! V_58 )
return 0 ;
F_21 ( L_8 ) ;
V_59 /= 4 ;
V_60 -> V_61 &= ~ ( V_70 ) ;
while( V_59 > 0 ) {
unsigned int V_71 = F_18 ( V_58 [ 0 ] ) ;
unsigned int V_72 = F_18 ( V_58 [ 1 ] ) ;
unsigned int V_73 = F_18 ( V_58 [ 2 ] ) ;
struct V_74 * V_75 ;
int V_64 , V_76 ;
V_59 -= 3 ; V_58 += 3 ;
V_76 = F_19 ( V_71 ) ;
if ( V_76 < 0 ) {
V_58 += V_73 * 2 ; V_59 -= V_73 * 2 ;
continue;
}
V_75 = & V_32 [ V_76 ] ;
if ( V_76 == V_68 )
V_60 -> V_61 |= V_70 ;
V_75 -> V_30 = V_71 ;
if ( V_71 <= 23 )
V_75 -> V_77 = 0 ;
else
V_75 -> V_77 = ( 1 << ( V_71 - 23 ) ) - 1 ;
V_75 -> V_78 = V_72 ;
if ( V_76 == V_65 || V_76 == V_66 )
V_75 -> V_79 = 1 ;
else
V_75 -> V_79 = 0 ;
while ( V_59 > 0 && V_73 ) {
unsigned int V_30 = F_18 ( V_58 [ 0 ] ) ;
int V_80 = F_18 ( V_58 [ 1 ] ) ;
V_58 += 2 ; V_59 -= 2 ;
V_73 -- ;
V_64 = F_19 ( V_30 ) ;
if ( V_64 < 0 )
continue;
if ( V_80 == - 1 )
F_22 ( L_9
L_10 , V_71 , V_30 ) ;
V_75 -> V_80 [ V_64 ] = V_80 ;
F_21 ( L_11
L_12 ,
V_71 , V_30 , V_75 -> V_78 ,
V_75 -> V_77 , V_75 -> V_79 , V_75 -> V_80 [ V_64 ] ) ;
}
}
return 1 ;
}
static int T_1 F_23 ( unsigned long V_54 ,
const char * V_55 , int V_56 ,
void * V_57 ) {
const char * type = F_17 ( V_54 , L_2 , NULL ) ;
const T_3 * V_81 ;
const T_2 * V_82 ;
unsigned int V_83 ;
long unsigned int V_84 ;
long unsigned int V_85 ;
if ( type == NULL || strcmp ( type , L_13 ) != 0 )
return 0 ;
V_82 = F_17 ( V_54 , L_14 , NULL ) ;
if ( V_82 == NULL )
return 0 ;
V_83 = ( 1 << F_18 ( V_82 [ 0 ] ) ) ;
V_81 = F_17 ( V_54 , L_15 , NULL ) ;
if ( V_81 == NULL )
return 0 ;
V_84 = F_24 ( V_81 [ 0 ] ) ;
V_85 = F_24 ( V_81 [ 1 ] ) ;
if ( V_85 != ( 16 * V_86 ) )
return 0 ;
F_25 ( V_87 L_16
L_17 ,
V_84 , V_85 , V_83 ) ;
if ( V_84 + ( 16 * V_86 ) <= F_26 () ) {
F_27 ( V_84 , V_85 * V_83 ) ;
F_28 ( V_84 , V_85 , V_83 ) ;
}
return 0 ;
}
static void F_29 ( void )
{
int V_88 , V_89 ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ )
V_32 [ V_88 ] . V_80 [ V_89 ] = - 1 ;
}
static bool F_30 ( void )
{
#ifdef F_31
return ! F_32 ( V_91 ) &&
F_33 ( V_92 ) ;
#else
return false ;
#endif
}
static void T_1 F_34 ( void )
{
int V_48 ;
F_29 () ;
memcpy ( V_32 , V_93 ,
sizeof( V_93 ) ) ;
V_48 = F_35 ( F_20 , NULL ) ;
if ( V_48 == 0 && F_36 ( V_70 ) ) {
memcpy ( V_32 , V_94 ,
sizeof( V_94 ) ) ;
}
#ifdef F_37
F_35 ( F_23 , NULL ) ;
#endif
}
static void F_38 ( void )
{
long int V_95 , V_96 ;
long int V_30 , V_80 ;
for ( V_96 = 0 ; V_96 < V_90 ; ++ V_96 ) {
if ( ! V_32 [ V_96 ] . V_30 )
continue;
for ( V_95 = V_96 ; V_95 < V_90 ; ++ V_95 ) {
V_80 = V_32 [ V_96 ] . V_80 [ V_95 ] ;
if ( V_80 == - 1 )
continue;
V_30 = V_32 [ V_95 ] . V_30 - V_97 ;
if ( V_30 <= 0 )
continue;
while ( V_80 < ( 1 << V_98 ) ) {
V_99 [ V_80 ] = ( V_95 << 4 ) | V_96 ;
V_80 += 1 << V_30 ;
}
}
}
}
static void T_1 F_39 ( void )
{
F_38 () ;
if ( ! F_13 () ) {
if ( V_32 [ V_68 ] . V_30 )
V_100 = V_68 ;
else if ( V_32 [ V_67 ] . V_30 )
V_100 = V_67 ;
}
#ifdef F_40
if ( V_32 [ V_66 ] . V_30 ) {
V_101 = V_66 ;
V_102 = V_66 ;
if ( V_100 == V_65 )
V_100 = V_66 ;
if ( F_2 ( V_103 ) ) {
if ( ! F_30 () )
V_104 = V_66 ;
} else
V_105 = 1 ;
}
#endif
#ifdef F_41
if ( V_32 [ V_68 ] . V_30 &&
F_42 () >= 0x40000000 )
V_106 = V_68 ;
else if ( V_32 [ V_66 ] . V_30 )
V_106 = V_66 ;
else
V_106 = V_65 ;
#endif
F_25 ( V_107 L_18
L_19
#ifdef F_41
L_20
#endif
L_21 ,
V_32 [ V_100 ] . V_30 ,
V_32 [ V_101 ] . V_30 ,
V_32 [ V_104 ] . V_30
#ifdef F_41
, V_32 [ V_106 ] . V_30
#endif
) ;
}
static int T_1 F_43 ( unsigned long V_54 ,
const char * V_55 , int V_56 ,
void * V_57 )
{
const char * type = F_17 ( V_54 , L_2 , NULL ) ;
const T_2 * V_58 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_58 = F_17 ( V_54 , L_22 , NULL ) ;
if ( V_58 != NULL ) {
V_108 = F_18 ( V_58 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
unsigned F_44 ( unsigned long V_109 )
{
unsigned V_110 = F_45 ( V_109 ) ;
unsigned V_111 = V_32 [ V_101 ] . V_30 ;
unsigned V_112 ;
if ( ( 1UL << V_110 ) < V_109 )
V_110 += 1 ;
V_112 = V_110 - ( V_111 + 1 ) ;
return F_46 ( V_112 + 7 , 18U ) ;
}
static unsigned long T_1 F_47 ( void )
{
if ( V_108 == 0 )
F_35 ( F_43 , NULL ) ;
if ( V_108 )
return 1UL << V_108 ;
return 1UL << F_44 ( F_42 () ) ;
}
int F_48 ( unsigned long V_113 , unsigned long V_114 )
{
int V_48 = F_3 ( V_113 , V_114 , F_49 ( V_113 ) ,
F_50 ( V_115 ) , V_100 ,
V_116 ) ;
if ( V_48 < 0 ) {
int V_117 = F_14 ( V_113 , V_114 , V_100 ,
V_116 ) ;
F_11 ( V_117 && ( V_117 != - V_51 ) ) ;
}
return V_48 ;
}
int F_51 ( unsigned long V_113 , unsigned long V_114 )
{
int V_48 = F_14 ( V_113 , V_114 , V_100 ,
V_116 ) ;
F_52 ( V_48 < 0 ) ;
return V_48 ;
}
static void F_53 ( void )
{
unsigned long V_118 ;
unsigned long V_119 = 3UL << F_54 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(0), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
V_118 = F_55 ( V_120 ) ;
V_118 &= ~ V_121 ;
F_56 ( V_120 , V_118 ) ;
asm volatile("isync": : :"memory");
while ( ( F_55 ( V_120 ) & V_121 ) )
F_57 () ;
}
static void T_1 F_58 ( T_4 V_122 ,
unsigned long V_123 )
{
F_59 () ;
V_123 = F_45 ( V_123 ) - 18 ;
F_60 ( 0 , V_122 | V_123 , 0 ) ;
F_21 ( L_23 , V_124 ) ;
if ( F_32 ( V_125 ) )
F_53 () ;
}
static void T_1 F_61 ( void )
{
unsigned long V_126 ;
unsigned long V_127 ;
unsigned long V_24 ;
unsigned long V_128 = 0 , V_59 = 0 ;
struct V_129 * V_130 ;
F_4 ( L_24 ) ;
if ( F_2 ( V_62 ) ) {
V_116 = V_131 ;
V_132 = V_131 ;
F_25 ( V_87 L_25 ) ;
}
V_133 = F_47 () ;
V_127 = V_133 >> 7 ;
V_40 = V_127 - 1 ;
if ( F_33 ( V_134 ) ||
F_33 ( V_135 ) ) {
V_136 = NULL ;
V_137 = 0 ;
#ifdef F_62
if ( F_63 () && V_42 . V_138 )
V_42 . V_138 () ;
#endif
} else {
unsigned long V_139 = V_140 ;
#ifdef F_64
if ( F_65 ( V_141 , 0 , L_26 ) > 0 ) {
V_139 = 0x80000000 ;
F_21 ( L_27 ) ;
}
#endif
V_126 = F_66 ( V_133 , V_133 ,
V_139 ) ;
F_4 ( L_28 , V_126 ,
V_133 ) ;
V_136 = F_67 ( V_126 ) ;
V_137 = V_126 + F_45 ( V_133 ) - 18 ;
memset ( ( void * ) V_126 , 0 , V_133 ) ;
if ( ! F_32 ( V_142 ) )
F_56 ( V_143 , V_137 ) ;
else
F_58 ( V_126 , V_133 ) ;
}
V_24 = F_50 ( V_115 ) ;
#ifdef F_12
if ( F_13 () ) {
V_46 = F_26 () >> V_45 ;
V_47 = F_67 ( F_66 (
V_46 , 1 , V_144 ) ) ;
memset ( V_47 , 0 , V_46 ) ;
}
#endif
F_68 (memory, reg) {
V_128 = ( unsigned long ) F_67 ( V_130 -> V_128 ) ;
V_59 = V_130 -> V_59 ;
F_4 ( L_29 ,
V_128 , V_59 , V_24 ) ;
F_11 ( F_3 ( V_128 , V_128 + V_59 , F_49 ( V_128 ) ,
V_24 , V_100 , V_116 ) ) ;
}
F_69 ( V_140 ) ;
if ( V_145 ) {
V_145 = ( unsigned long ) F_67 ( V_145 ) ;
V_146 = ( unsigned long ) F_67 ( V_146 ) ;
if ( V_128 + V_59 >= V_145 )
V_145 = V_128 + V_59 + 1 ;
F_11 ( F_3 ( V_145 , V_146 ,
F_49 ( V_145 ) , V_24 ,
V_100 , V_116 ) ) ;
}
F_4 ( L_30 ) ;
}
void T_1 F_70 ( void )
{
F_35 ( F_16 , NULL ) ;
F_34 () ;
}
void T_1 F_71 ( void )
{
F_39 () ;
V_147 = V_148 ;
V_149 = V_150 ;
V_151 = V_152 ;
V_153 = V_154 ;
V_155 = V_156 ;
V_157 = V_158 ;
V_159 = V_160 ;
V_161 = V_162 ;
V_163 = V_164 ;
V_165 = V_166 ;
V_167 = V_168 ;
V_169 = 0 ;
V_170 = 0 ;
V_171 = 0 ;
V_172 = V_173 ;
V_174 = V_175 ;
V_176 = V_177 ;
V_178 = V_179 ;
V_180 = (struct V_181 * ) V_182 ;
V_183 = V_184 ;
#ifdef F_72
V_185 = V_186 ;
#endif
if ( F_33 ( V_135 ) )
F_73 () ;
else if ( F_33 ( V_134 ) )
F_74 () ;
else if ( F_75 ( V_187 ) )
F_76 () ;
if ( ! V_42 . V_43 )
F_77 ( L_31 ) ;
F_61 () ;
F_21 ( L_32 ) ;
F_78 () ;
}
void F_79 ( void )
{
if ( ! F_33 ( V_134 ) ) {
if ( F_32 ( V_125 ) )
F_53 () ;
if ( ! F_32 ( V_142 ) )
F_56 ( V_143 , V_137 ) ;
else
F_56 ( V_188 ,
F_49 ( V_124 ) | ( V_189 - 12 ) ) ;
}
F_78 () ;
}
unsigned int F_80 ( unsigned int V_190 , T_5 V_191 , int V_192 )
{
struct V_181 * V_181 ;
if ( ! F_81 ( F_82 ( V_191 ) ) )
return V_190 ;
V_181 = F_83 ( V_191 ) ;
if ( ! F_84 ( V_193 , & V_181 -> V_194 ) && ! F_85 ( V_181 ) ) {
if ( V_192 == 0x400 ) {
F_86 ( V_181 ) ;
F_87 ( V_193 , & V_181 -> V_194 ) ;
} else
V_190 |= V_4 ;
}
return V_190 ;
}
static unsigned int F_88 ( unsigned long V_195 )
{
T_6 V_196 ;
unsigned char * V_197 ;
unsigned long V_198 , V_199 ;
if ( V_195 < V_200 ) {
V_196 = F_89 () -> V_201 ;
V_198 = F_90 ( V_195 ) ;
return ( V_196 >> ( V_198 * 4 ) ) & 0xF ;
}
V_197 = F_89 () -> V_202 ;
V_198 = F_91 ( V_195 ) ;
V_199 = V_198 & 0x1 ;
return ( V_197 [ V_198 >> 1 ] >> ( V_199 * 4 ) ) & 0xF ;
}
unsigned int F_88 ( unsigned long V_195 )
{
return F_89 () -> V_203 ;
}
void F_92 ( struct V_204 * V_205 , unsigned long V_195 )
{
if ( F_93 ( V_205 , V_195 ) == V_65 )
return;
F_94 ( V_205 , V_195 , 1 , V_65 ) ;
F_95 ( V_205 ) ;
if ( ( F_88 ( V_195 ) != V_65 ) && ( V_206 -> V_205 == V_205 ) ) {
F_96 ( & V_205 -> V_207 ) ;
F_97 () ;
}
}
static int F_98 ( struct V_204 * V_205 , unsigned long V_208 )
{
struct V_209 * V_210 = & V_205 -> V_207 . V_210 ;
T_7 V_211 = 0 ;
T_7 * * V_212 , * V_213 ;
if ( V_208 >= V_210 -> V_214 )
return 0 ;
if ( V_208 < 0x100000000UL ) {
V_212 = V_210 -> V_215 ;
} else {
V_212 = V_210 -> V_216 [ V_208 >> V_217 ] ;
if ( ! V_212 )
return 0 ;
}
V_213 = V_212 [ ( V_208 >> V_218 ) & ( V_219 - 1 ) ] ;
if ( ! V_213 )
return 0 ;
V_211 = V_213 [ ( V_208 >> V_45 ) & ( V_220 - 1 ) ] ;
V_211 >>= 30 - 2 * ( ( V_208 >> 12 ) & 0xf ) ;
V_211 = ( ( V_211 & 2 ) ? V_9 : 0 ) | ( ( V_211 & 1 ) ? V_6 : 0 ) ;
return V_211 ;
}
static inline int F_98 ( struct V_204 * V_205 , unsigned long V_208 )
{
return 0 ;
}
void F_99 ( unsigned long V_208 , unsigned long V_221 ,
unsigned long V_35 , unsigned long V_192 ,
int V_26 , int V_25 , int V_222 , unsigned long V_191 )
{
if ( ! F_100 () )
return;
F_21 ( L_33 ,
V_208 , V_221 , V_206 -> V_223 ) ;
F_21 ( L_34 ,
V_192 , V_35 , V_26 , V_25 , V_222 , V_191 ) ;
}
static void F_101 ( unsigned long V_208 , struct V_204 * V_205 ,
int V_25 , bool V_224 )
{
if ( V_224 ) {
if ( V_25 != F_88 ( V_208 ) ) {
F_96 ( & V_205 -> V_207 ) ;
F_97 () ;
}
} else if ( F_89 () -> V_225 !=
V_32 [ V_102 ] . V_78 ) {
F_89 () -> V_225 =
V_32 [ V_102 ] . V_78 ;
F_102 () ;
}
}
int F_103 ( struct V_204 * V_205 , unsigned long V_208 ,
unsigned long V_221 , unsigned long V_192 ,
unsigned long V_194 )
{
bool V_226 ;
enum V_227 V_228 = F_104 () ;
T_8 * V_229 ;
unsigned long V_35 ;
T_5 * V_230 ;
unsigned V_231 ;
const struct V_232 * V_233 ;
int V_48 , V_224 = 0 ;
int V_25 , V_26 ;
F_105 ( L_35 ,
V_208 , V_221 , V_192 ) ;
F_106 ( V_208 , V_221 , V_192 ) ;
switch ( F_107 ( V_208 ) ) {
case V_234 :
V_224 = 1 ;
if ( ! V_205 ) {
F_105 ( L_36 ) ;
V_48 = 1 ;
goto V_235;
}
V_25 = F_93 ( V_205 , V_208 ) ;
V_26 = F_108 ( V_208 ) ;
V_35 = F_109 ( V_205 -> V_207 . V_236 , V_208 , V_26 ) ;
break;
case V_237 :
V_35 = F_5 ( V_208 , V_116 ) ;
if ( V_208 < V_238 )
V_25 = V_102 ;
else
V_25 = V_104 ;
V_26 = V_116 ;
break;
default:
V_48 = 1 ;
goto V_235;
}
F_105 ( L_37 , V_205 , V_205 -> V_239 , V_35 ) ;
if ( ! V_35 ) {
F_105 ( L_38 ) ;
V_48 = 1 ;
goto V_235;
}
V_229 = V_205 -> V_239 ;
if ( V_229 == NULL ) {
V_48 = 1 ;
goto V_235;
}
V_233 = F_110 ( F_111 () ) ;
if ( V_224 && F_112 ( F_113 ( V_205 ) , V_233 ) )
V_194 |= V_240 ;
#ifndef F_40
if ( V_25 != V_65 )
V_208 &= ~ ( ( 1ul << V_32 [ V_25 ] . V_30 ) - 1 ) ;
#endif
V_230 = F_114 ( V_229 , V_208 , & V_226 , & V_231 ) ;
if ( V_230 == NULL || ! F_115 ( * V_230 ) ) {
F_105 ( L_39 ) ;
V_48 = 1 ;
goto V_235;
}
V_221 |= V_241 ;
if ( ! F_116 ( V_221 , F_117 ( * V_230 ) ) ) {
F_105 ( L_40 ) ;
V_48 = 1 ;
goto V_235;
}
if ( V_231 ) {
if ( V_226 )
V_48 = F_118 ( V_208 , V_221 , V_35 , ( V_242 * ) V_230 ,
V_192 , V_194 , V_26 , V_25 ) ;
#ifdef F_37
else
V_48 = F_119 ( V_208 , V_221 , V_35 , V_230 , V_192 ,
V_194 , V_26 , V_231 , V_25 ) ;
#else
else {
V_48 = 1 ;
F_52 ( 1 ) ;
}
#endif
if ( V_206 -> V_205 == V_205 )
F_101 ( V_208 , V_205 , V_25 , V_224 ) ;
goto V_235;
}
#ifndef F_40
F_105 ( L_41 , F_117 ( * V_230 ) ) ;
#else
F_105 ( L_42 , F_117 ( * V_230 ) ,
F_117 ( * ( V_230 + V_243 ) ) ) ;
#endif
#ifdef F_40
if ( ( F_117 ( * V_230 ) & V_244 ) && V_25 == V_66 ) {
F_92 ( V_205 , V_208 ) ;
V_25 = V_65 ;
}
if ( V_105 && V_25 == V_66 && F_120 ( * V_230 ) ) {
if ( V_224 ) {
F_92 ( V_205 , V_208 ) ;
V_25 = V_65 ;
} else if ( V_208 < V_238 ) {
F_25 ( V_245 L_43
L_44
L_45 ) ;
V_25 = V_102 = V_65 ;
F_95 ( V_205 ) ;
}
}
#endif
if ( V_206 -> V_205 == V_205 )
F_101 ( V_208 , V_205 , V_25 , V_224 ) ;
#ifdef F_40
if ( V_25 == V_66 )
V_48 = F_121 ( V_208 , V_221 , V_35 , V_230 , V_192 ,
V_194 , V_26 ) ;
else
#endif
{
int V_211 = F_98 ( V_205 , V_208 ) ;
if ( V_221 & V_211 )
V_48 = - 2 ;
else
V_48 = F_122 ( V_208 , V_221 , V_35 , V_230 , V_192 ,
V_194 , V_26 , V_211 ) ;
}
if ( V_48 == - 1 )
F_99 ( V_208 , V_221 , V_35 , V_192 , V_26 , V_25 ,
V_25 , F_117 ( * V_230 ) ) ;
#ifndef F_40
F_105 ( L_46 , F_117 ( * V_230 ) ) ;
#else
F_105 ( L_47 , F_117 ( * V_230 ) ,
F_117 ( * ( V_230 + V_243 ) ) ) ;
#endif
F_105 ( L_48 , V_48 ) ;
V_235:
F_123 ( V_228 ) ;
return V_48 ;
}
int F_124 ( unsigned long V_208 , unsigned long V_221 , unsigned long V_192 ,
unsigned long V_246 )
{
unsigned long V_194 = 0 ;
struct V_204 * V_205 = V_206 -> V_205 ;
if ( F_107 ( V_208 ) == V_237 )
V_205 = & V_247 ;
if ( V_246 & V_248 )
V_194 |= V_249 ;
return F_103 ( V_205 , V_208 , V_221 , V_192 , V_194 ) ;
}
int F_125 ( unsigned long V_208 , unsigned long V_250 , unsigned long V_192 ,
unsigned long V_246 )
{
unsigned long V_221 = V_241 | V_251 ;
unsigned long V_194 = 0 ;
struct V_204 * V_205 = V_206 -> V_205 ;
if ( F_107 ( V_208 ) == V_237 )
V_205 = & V_247 ;
if ( V_246 & V_248 )
V_194 |= V_249 ;
if ( V_246 & V_252 )
V_221 |= V_6 ;
V_221 |= V_5 ;
if ( ( V_250 & V_253 ) || ( F_107 ( V_208 ) == V_234 ) )
V_221 &= ~ V_5 ;
if ( V_192 == 0x400 )
V_221 |= V_3 ;
return F_103 ( V_205 , V_208 , V_221 , V_192 , V_194 ) ;
}
static bool F_126 ( struct V_204 * V_205 , unsigned long V_208 )
{
int V_25 = F_93 ( V_205 , V_208 ) ;
if ( F_127 ( V_25 != V_205 -> V_207 . V_254 ) )
return false ;
if ( F_127 ( ( V_25 == V_65 ) && F_98 ( V_205 , V_208 ) ) )
return false ;
return true ;
}
static bool F_126 ( struct V_204 * V_205 , unsigned long V_208 )
{
return true ;
}
void F_128 ( struct V_204 * V_205 , unsigned long V_208 ,
unsigned long V_221 , unsigned long V_192 )
{
int V_255 ;
unsigned long V_35 ;
T_8 * V_229 ;
T_5 * V_230 ;
unsigned long V_194 ;
int V_48 , V_26 , V_256 = 0 ;
F_11 ( F_107 ( V_208 ) != V_234 ) ;
if ( ! F_126 ( V_205 , V_208 ) )
return;
F_105 ( L_49
L_50 , V_205 , V_205 -> V_239 , V_208 , V_221 , V_192 ) ;
V_229 = V_205 -> V_239 ;
if ( V_229 == NULL )
return;
V_26 = F_108 ( V_208 ) ;
V_35 = F_109 ( V_205 -> V_207 . V_236 , V_208 , V_26 ) ;
if ( ! V_35 )
return;
F_129 ( V_194 ) ;
V_230 = F_130 ( V_229 , V_208 , NULL , & V_255 ) ;
if ( ! V_230 )
goto V_257;
F_52 ( V_255 ) ;
#ifdef F_40
if ( ( F_117 ( * V_230 ) & V_244 ) || F_120 ( * V_230 ) )
goto V_257;
#endif
if ( F_112 ( F_113 ( V_205 ) , F_110 ( F_111 () ) ) )
V_256 |= V_240 ;
#ifdef F_40
if ( V_205 -> V_207 . V_254 == V_66 )
V_48 = F_121 ( V_208 , V_221 , V_35 , V_230 , V_192 ,
V_256 , V_26 ) ;
else
#endif
V_48 = F_122 ( V_208 , V_221 , V_35 , V_230 , V_192 , V_256 ,
V_26 , F_98 ( V_205 , V_208 ) ) ;
if ( V_48 == - 1 )
F_99 ( V_208 , V_221 , V_35 , V_192 , V_26 ,
V_205 -> V_207 . V_254 ,
V_205 -> V_207 . V_254 ,
F_117 ( * V_230 ) ) ;
V_257:
F_131 ( V_194 ) ;
}
static inline void F_132 ( int V_258 )
{
if ( V_258 && F_32 ( V_259 ) && V_206 -> V_260 . V_261 &&
F_133 ( V_206 -> V_260 . V_261 -> V_250 ) ) {
F_134 () ;
F_135 ( V_262 ) ;
}
}
static inline void F_132 ( int V_258 )
{
}
void F_136 ( unsigned long V_36 , T_9 V_191 , int V_25 , int V_26 ,
unsigned long V_194 )
{
unsigned long V_33 , V_198 , V_30 , V_263 , V_264 ;
int V_258 = V_194 & V_240 ;
F_105 ( L_51 , V_36 ) ;
F_137 (pte, psize, vpn, index, shift) {
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
V_263 = F_138 ( V_191 , V_198 ) ;
if ( V_263 & V_265 )
V_33 = ~ V_33 ;
V_264 = ( V_33 & V_40 ) * V_41 ;
V_264 += V_263 & V_266 ;
F_105 ( L_52 , V_198 , V_264 , V_263 ) ;
V_42 . V_267 ( V_264 , V_36 , V_25 , V_25 ,
V_26 , V_258 ) ;
} F_139 () ;
F_132 ( V_258 ) ;
}
void F_140 ( unsigned long V_35 , unsigned long V_195 ,
V_242 * V_268 , unsigned int V_25 , int V_26 ,
unsigned long V_194 )
{
int V_269 , V_270 , V_271 ;
unsigned long V_272 ;
unsigned char * V_273 ;
unsigned long V_263 , V_30 , V_36 , V_33 , V_264 ;
int V_258 = V_194 & V_240 ;
V_272 = V_195 & V_274 ;
V_273 = F_141 ( V_268 ) ;
if ( ! V_273 )
return;
if ( V_42 . V_275 ) {
V_42 . V_275 ( V_35 , V_272 , V_273 ,
V_25 , V_26 , V_258 ) ;
goto F_135;
}
V_30 = V_32 [ V_25 ] . V_30 ;
V_270 = V_276 >> V_30 ;
for ( V_269 = 0 ; V_269 < V_270 ; V_269 ++ ) {
V_271 = F_142 ( V_273 , V_269 ) ;
if ( ! V_271 )
continue;
V_263 = F_143 ( V_273 , V_269 ) ;
V_195 = V_272 + ( V_269 * ( 1ul << V_30 ) ) ;
V_36 = F_6 ( V_195 , V_35 , V_26 ) ;
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
if ( V_263 & V_265 )
V_33 = ~ V_33 ;
V_264 = ( V_33 & V_40 ) * V_41 ;
V_264 += V_263 & V_266 ;
V_42 . V_267 ( V_264 , V_36 , V_25 ,
V_68 , V_26 , V_258 ) ;
}
F_135:
F_132 ( V_258 ) ;
}
void F_144 ( unsigned long V_277 , int V_258 )
{
if ( V_42 . F_144 )
V_42 . F_144 ( V_277 , V_258 ) ;
else {
int V_269 ;
struct V_278 * V_279 =
F_145 ( & V_278 ) ;
for ( V_269 = 0 ; V_269 < V_277 ; V_269 ++ )
F_136 ( V_279 -> V_36 [ V_269 ] , V_279 -> V_191 [ V_269 ] ,
V_279 -> V_25 , V_279 -> V_26 , V_258 ) ;
}
}
void F_146 ( struct V_280 * V_261 , unsigned long V_281 , int V_48 )
{
enum V_227 V_228 = F_104 () ;
if ( F_147 ( V_261 ) ) {
#ifdef F_148
if ( V_48 == - 2 )
F_149 ( V_282 , V_261 , V_283 , V_281 ) ;
else
#endif
F_149 ( V_284 , V_261 , V_285 , V_281 ) ;
} else
F_150 ( V_261 , V_281 , V_284 ) ;
F_123 ( V_228 ) ;
}
long F_151 ( unsigned long V_33 , unsigned long V_36 ,
unsigned long V_286 , unsigned long V_2 ,
unsigned long V_287 , int V_25 , int V_26 )
{
unsigned long V_288 ;
long V_264 ;
V_289:
V_288 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_264 = V_42 . V_43 ( V_288 , V_36 , V_286 , V_2 , V_287 ,
V_25 , V_25 , V_26 ) ;
if ( F_127 ( V_264 == - 1 ) ) {
V_288 = ( ( ~ V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_264 = V_42 . V_43 ( V_288 , V_36 , V_286 , V_2 ,
V_287 | V_290 ,
V_25 , V_25 , V_26 ) ;
if ( V_264 == - 1 ) {
if ( F_152 () & 0x1 )
V_288 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_42 . V_291 ( V_288 ) ;
goto V_289;
}
}
return V_264 ;
}
static void F_153 ( unsigned long V_27 , unsigned long V_292 )
{
unsigned long V_33 ;
unsigned long V_35 = F_5 ( V_27 , V_116 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_116 ) ;
unsigned long V_293 = F_1 ( F_50 ( V_115 ) ) ;
long V_31 ;
V_33 = F_10 ( V_36 , V_45 , V_116 ) ;
if ( ! V_35 )
return;
V_31 = F_151 ( V_33 , V_36 , F_49 ( V_27 ) , V_293 ,
V_44 ,
V_100 , V_116 ) ;
F_11 ( V_31 < 0 ) ;
F_154 ( & V_294 ) ;
F_11 ( V_47 [ V_292 ] & 0x80 ) ;
V_47 [ V_292 ] = V_31 | 0x80 ;
F_155 ( & V_294 ) ;
}
static void F_156 ( unsigned long V_27 , unsigned long V_292 )
{
unsigned long V_33 , V_263 , V_264 ;
unsigned long V_35 = F_5 ( V_27 , V_116 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_116 ) ;
V_33 = F_10 ( V_36 , V_45 , V_116 ) ;
F_154 ( & V_294 ) ;
F_11 ( ! ( V_47 [ V_292 ] & 0x80 ) ) ;
V_263 = V_47 [ V_292 ] & 0x7f ;
V_47 [ V_292 ] = 0 ;
F_155 ( & V_294 ) ;
if ( V_263 & V_265 )
V_33 = ~ V_33 ;
V_264 = ( V_33 & V_40 ) * V_41 ;
V_264 += V_263 & V_266 ;
V_42 . V_267 ( V_264 , V_36 , V_100 ,
V_100 ,
V_116 , 0 ) ;
}
void F_157 ( struct V_181 * V_181 , int V_295 , int V_296 )
{
unsigned long V_194 , V_27 , V_292 ;
int V_269 ;
F_129 ( V_194 ) ;
for ( V_269 = 0 ; V_269 < V_295 ; V_269 ++ , V_181 ++ ) {
V_27 = ( unsigned long ) F_158 ( V_181 ) ;
V_292 = F_49 ( V_27 ) >> V_45 ;
if ( V_292 >= V_46 )
continue;
if ( V_296 )
F_153 ( V_27 , V_292 ) ;
else
F_156 ( V_27 , V_292 ) ;
}
F_131 ( V_194 ) ;
}
void F_159 ( T_4 V_297 ,
T_4 V_298 )
{
F_11 ( V_297 != 0 ) ;
V_144 = F_160 ( T_6 , V_298 , 0x40000000 ) ;
F_69 ( V_144 ) ;
}
