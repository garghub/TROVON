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
void F_48 ( unsigned long V_113 )
{
unsigned V_114 ;
if ( ! V_42 . V_115 )
return;
V_114 = F_44 ( V_113 ) ;
if ( ( V_114 > V_108 )
|| ( V_114 < ( V_108 - 1 ) ) ) {
int V_48 ;
V_48 = V_42 . V_115 ( V_114 ) ;
if ( V_48 )
F_25 ( V_116
L_23 ,
V_114 , V_48 ) ;
}
}
int F_49 ( unsigned long V_117 , unsigned long V_118 )
{
int V_48 = F_3 ( V_117 , V_118 , F_50 ( V_117 ) ,
F_51 ( V_119 ) , V_100 ,
V_120 ) ;
if ( V_48 < 0 ) {
int V_121 = F_14 ( V_117 , V_118 , V_100 ,
V_120 ) ;
F_11 ( V_121 && ( V_121 != - V_51 ) ) ;
}
return V_48 ;
}
int F_52 ( unsigned long V_117 , unsigned long V_118 )
{
int V_48 = F_14 ( V_117 , V_118 , V_100 ,
V_120 ) ;
F_53 ( V_48 < 0 ) ;
return V_48 ;
}
static void F_54 ( void )
{
unsigned long V_122 ;
unsigned long V_123 = 3UL << F_55 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(0), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
V_122 = F_56 ( V_124 ) ;
V_122 &= ~ V_125 ;
F_57 ( V_124 , V_122 ) ;
asm volatile("isync": : :"memory");
while ( ( F_56 ( V_124 ) & V_125 ) )
F_58 () ;
}
static void T_1 F_59 ( T_4 V_126 ,
unsigned long V_127 )
{
F_60 () ;
V_127 = F_45 ( V_127 ) - 18 ;
F_61 ( 0 , V_126 | V_127 , 0 ) ;
F_21 ( L_24 , V_128 ) ;
if ( F_32 ( V_129 ) )
F_54 () ;
}
static void T_1 F_62 ( void )
{
unsigned long V_130 ;
unsigned long V_131 ;
unsigned long V_24 ;
unsigned long V_132 = 0 , V_59 = 0 ;
struct V_133 * V_134 ;
F_4 ( L_25 ) ;
if ( F_2 ( V_62 ) ) {
V_120 = V_135 ;
V_136 = V_135 ;
F_25 ( V_87 L_26 ) ;
}
V_137 = F_47 () ;
V_131 = V_137 >> 7 ;
V_40 = V_131 - 1 ;
if ( F_33 ( V_138 ) ||
F_33 ( V_139 ) ) {
V_140 = NULL ;
V_141 = 0 ;
#ifdef F_63
if ( F_64 () && V_42 . V_142 )
V_42 . V_142 () ;
#endif
} else {
unsigned long V_143 = V_144 ;
#ifdef F_65
if ( F_66 ( V_145 , 0 , L_27 ) > 0 ) {
V_143 = 0x80000000 ;
F_21 ( L_28 ) ;
}
#endif
V_130 = F_67 ( V_137 , V_137 ,
V_143 ) ;
F_4 ( L_29 , V_130 ,
V_137 ) ;
V_140 = F_68 ( V_130 ) ;
V_141 = V_130 + F_45 ( V_137 ) - 18 ;
memset ( ( void * ) V_130 , 0 , V_137 ) ;
if ( ! F_32 ( V_146 ) )
F_57 ( V_147 , V_141 ) ;
else
F_59 ( V_130 , V_137 ) ;
}
V_24 = F_51 ( V_119 ) ;
#ifdef F_12
if ( F_13 () ) {
V_46 = F_26 () >> V_45 ;
V_47 = F_68 ( F_67 (
V_46 , 1 , V_148 ) ) ;
memset ( V_47 , 0 , V_46 ) ;
}
#endif
F_69 (memory, reg) {
V_132 = ( unsigned long ) F_68 ( V_134 -> V_132 ) ;
V_59 = V_134 -> V_59 ;
F_4 ( L_30 ,
V_132 , V_59 , V_24 ) ;
F_11 ( F_3 ( V_132 , V_132 + V_59 , F_50 ( V_132 ) ,
V_24 , V_100 , V_120 ) ) ;
}
F_70 ( V_144 ) ;
if ( V_149 ) {
V_149 = ( unsigned long ) F_68 ( V_149 ) ;
V_150 = ( unsigned long ) F_68 ( V_150 ) ;
if ( V_132 + V_59 >= V_149 )
V_149 = V_132 + V_59 + 1 ;
F_11 ( F_3 ( V_149 , V_150 ,
F_50 ( V_149 ) , V_24 ,
V_100 , V_120 ) ) ;
}
F_4 ( L_31 ) ;
}
void T_1 F_71 ( void )
{
F_35 ( F_16 , NULL ) ;
F_34 () ;
}
void T_1 F_72 ( void )
{
F_73 ( V_151 != ( 1ul << ( V_152 + 3 ) ) ) ;
F_39 () ;
V_153 = V_154 ;
V_155 = V_156 ;
V_157 = V_158 ;
V_159 = V_160 ;
V_161 = V_162 ;
V_163 = V_164 ;
V_165 = V_166 ;
V_167 = V_168 ;
V_169 = V_170 ;
V_171 = V_172 ;
V_173 = V_174 ;
V_175 = 0 ;
V_176 = 0 ;
V_177 = 0 ;
V_178 = V_179 ;
V_180 = V_181 ;
V_182 = V_183 ;
V_184 = V_185 ;
V_186 = (struct V_187 * ) V_188 ;
V_189 = V_190 ;
#ifdef F_74
V_191 = V_192 ;
#endif
if ( F_33 ( V_139 ) )
F_75 () ;
else if ( F_33 ( V_138 ) )
F_76 () ;
else if ( F_77 ( V_193 ) )
F_78 () ;
if ( ! V_42 . V_43 )
F_79 ( L_32 ) ;
F_62 () ;
F_21 ( L_33 ) ;
F_80 () ;
}
void F_81 ( void )
{
if ( ! F_33 ( V_138 ) ) {
if ( F_32 ( V_129 ) )
F_54 () ;
if ( ! F_32 ( V_146 ) )
F_57 ( V_147 , V_141 ) ;
else
F_57 ( V_194 ,
F_50 ( V_128 ) | ( V_195 - 12 ) ) ;
}
F_80 () ;
}
unsigned int F_82 ( unsigned int V_196 , T_5 V_197 , int V_198 )
{
struct V_187 * V_187 ;
if ( ! F_83 ( F_84 ( V_197 ) ) )
return V_196 ;
V_187 = F_85 ( V_197 ) ;
if ( ! F_86 ( V_199 , & V_187 -> V_200 ) && ! F_87 ( V_187 ) ) {
if ( V_198 == 0x400 ) {
F_88 ( V_187 ) ;
F_89 ( V_199 , & V_187 -> V_200 ) ;
} else
V_196 |= V_4 ;
}
return V_196 ;
}
static unsigned int F_90 ( unsigned long V_201 )
{
T_6 V_202 ;
unsigned char * V_203 ;
unsigned long V_204 , V_205 ;
if ( V_201 < V_206 ) {
V_202 = F_91 () -> V_207 ;
V_204 = F_92 ( V_201 ) ;
return ( V_202 >> ( V_204 * 4 ) ) & 0xF ;
}
V_203 = F_91 () -> V_208 ;
V_204 = F_93 ( V_201 ) ;
V_205 = V_204 & 0x1 ;
return ( V_203 [ V_204 >> 1 ] >> ( V_205 * 4 ) ) & 0xF ;
}
unsigned int F_90 ( unsigned long V_201 )
{
return F_91 () -> V_209 ;
}
void F_94 ( struct V_210 * V_211 , unsigned long V_201 )
{
if ( F_95 ( V_211 , V_201 ) == V_65 )
return;
F_96 ( V_211 , V_201 , 1 , V_65 ) ;
F_97 ( V_211 ) ;
if ( ( F_90 ( V_201 ) != V_65 ) && ( V_212 -> V_211 == V_211 ) ) {
F_98 ( V_211 ) ;
F_99 () ;
}
}
static int F_100 ( struct V_210 * V_211 , unsigned long V_213 )
{
struct V_214 * V_215 = & V_211 -> V_216 . V_215 ;
T_7 V_217 = 0 ;
T_7 * * V_218 , * V_219 ;
if ( V_213 >= V_215 -> V_220 )
return 0 ;
if ( V_213 < 0x100000000UL ) {
V_218 = V_215 -> V_221 ;
} else {
V_218 = V_215 -> V_222 [ V_213 >> V_223 ] ;
if ( ! V_218 )
return 0 ;
}
V_219 = V_218 [ ( V_213 >> V_224 ) & ( V_225 - 1 ) ] ;
if ( ! V_219 )
return 0 ;
V_217 = V_219 [ ( V_213 >> V_45 ) & ( V_226 - 1 ) ] ;
V_217 >>= 30 - 2 * ( ( V_213 >> 12 ) & 0xf ) ;
V_217 = ( ( V_217 & 2 ) ? V_9 : 0 ) | ( ( V_217 & 1 ) ? V_6 : 0 ) ;
return V_217 ;
}
static inline int F_100 ( struct V_210 * V_211 , unsigned long V_213 )
{
return 0 ;
}
void F_101 ( unsigned long V_213 , unsigned long V_227 ,
unsigned long V_35 , unsigned long V_198 ,
int V_26 , int V_25 , int V_228 , unsigned long V_197 )
{
if ( ! F_102 () )
return;
F_21 ( L_34 ,
V_213 , V_227 , V_212 -> V_229 ) ;
F_21 ( L_35 ,
V_198 , V_35 , V_26 , V_25 , V_228 , V_197 ) ;
}
static void F_103 ( unsigned long V_213 , struct V_210 * V_211 ,
int V_25 , bool V_230 )
{
if ( V_230 ) {
if ( V_25 != F_90 ( V_213 ) ) {
F_98 ( V_211 ) ;
F_99 () ;
}
} else if ( F_91 () -> V_231 !=
V_32 [ V_102 ] . V_78 ) {
F_91 () -> V_231 =
V_32 [ V_102 ] . V_78 ;
F_104 () ;
}
}
int F_105 ( struct V_210 * V_211 , unsigned long V_213 ,
unsigned long V_227 , unsigned long V_198 ,
unsigned long V_200 )
{
bool V_232 ;
enum V_233 V_234 = F_106 () ;
T_8 * V_235 ;
unsigned long V_35 ;
T_5 * V_236 ;
unsigned V_237 ;
const struct V_238 * V_239 ;
int V_48 , V_230 = 0 ;
int V_25 , V_26 ;
F_107 ( L_36 ,
V_213 , V_227 , V_198 ) ;
F_108 ( V_213 , V_227 , V_198 ) ;
switch ( F_109 ( V_213 ) ) {
case V_240 :
V_230 = 1 ;
if ( ! V_211 ) {
F_107 ( L_37 ) ;
V_48 = 1 ;
goto V_241;
}
V_25 = F_95 ( V_211 , V_213 ) ;
V_26 = F_110 ( V_213 ) ;
V_35 = F_111 ( V_211 -> V_216 . V_242 , V_213 , V_26 ) ;
break;
case V_243 :
V_35 = F_5 ( V_213 , V_120 ) ;
if ( V_213 < V_244 )
V_25 = V_102 ;
else
V_25 = V_104 ;
V_26 = V_120 ;
break;
default:
V_48 = 1 ;
goto V_241;
}
F_107 ( L_38 , V_211 , V_211 -> V_245 , V_35 ) ;
if ( ! V_35 ) {
F_107 ( L_39 ) ;
V_48 = 1 ;
goto V_241;
}
V_235 = V_211 -> V_245 ;
if ( V_235 == NULL ) {
V_48 = 1 ;
goto V_241;
}
V_239 = F_112 ( F_113 () ) ;
if ( V_230 && F_114 ( F_115 ( V_211 ) , V_239 ) )
V_200 |= V_246 ;
#ifndef F_40
if ( V_25 != V_65 )
V_213 &= ~ ( ( 1ul << V_32 [ V_25 ] . V_30 ) - 1 ) ;
#endif
V_236 = F_116 ( V_235 , V_213 , & V_232 , & V_237 ) ;
if ( V_236 == NULL || ! F_117 ( * V_236 ) ) {
F_107 ( L_40 ) ;
V_48 = 1 ;
goto V_241;
}
V_227 |= V_247 ;
if ( ! F_118 ( V_227 , F_119 ( * V_236 ) ) ) {
F_107 ( L_41 ) ;
V_48 = 1 ;
goto V_241;
}
if ( V_237 ) {
if ( V_232 )
V_48 = F_120 ( V_213 , V_227 , V_35 , ( V_248 * ) V_236 ,
V_198 , V_200 , V_26 , V_25 ) ;
#ifdef F_37
else
V_48 = F_121 ( V_213 , V_227 , V_35 , V_236 , V_198 ,
V_200 , V_26 , V_237 , V_25 ) ;
#else
else {
V_48 = 1 ;
F_53 ( 1 ) ;
}
#endif
if ( V_212 -> V_211 == V_211 )
F_103 ( V_213 , V_211 , V_25 , V_230 ) ;
goto V_241;
}
#ifndef F_40
F_107 ( L_42 , F_119 ( * V_236 ) ) ;
#else
F_107 ( L_43 , F_119 ( * V_236 ) ,
F_119 ( * ( V_236 + V_249 ) ) ) ;
#endif
#ifdef F_40
if ( ( F_119 ( * V_236 ) & V_250 ) && V_25 == V_66 ) {
F_94 ( V_211 , V_213 ) ;
V_25 = V_65 ;
}
if ( V_105 && V_25 == V_66 && F_122 ( * V_236 ) ) {
if ( V_230 ) {
F_94 ( V_211 , V_213 ) ;
V_25 = V_65 ;
} else if ( V_213 < V_244 ) {
F_25 ( V_251 L_44
L_45
L_46 ) ;
V_25 = V_102 = V_65 ;
F_97 ( V_211 ) ;
}
}
#endif
if ( V_212 -> V_211 == V_211 )
F_103 ( V_213 , V_211 , V_25 , V_230 ) ;
#ifdef F_40
if ( V_25 == V_66 )
V_48 = F_123 ( V_213 , V_227 , V_35 , V_236 , V_198 ,
V_200 , V_26 ) ;
else
#endif
{
int V_217 = F_100 ( V_211 , V_213 ) ;
if ( V_227 & V_217 )
V_48 = - 2 ;
else
V_48 = F_124 ( V_213 , V_227 , V_35 , V_236 , V_198 ,
V_200 , V_26 , V_217 ) ;
}
if ( V_48 == - 1 )
F_101 ( V_213 , V_227 , V_35 , V_198 , V_26 , V_25 ,
V_25 , F_119 ( * V_236 ) ) ;
#ifndef F_40
F_107 ( L_47 , F_119 ( * V_236 ) ) ;
#else
F_107 ( L_48 , F_119 ( * V_236 ) ,
F_119 ( * ( V_236 + V_249 ) ) ) ;
#endif
F_107 ( L_49 , V_48 ) ;
V_241:
F_125 ( V_234 ) ;
return V_48 ;
}
int F_126 ( unsigned long V_213 , unsigned long V_227 , unsigned long V_198 ,
unsigned long V_252 )
{
unsigned long V_200 = 0 ;
struct V_210 * V_211 = V_212 -> V_211 ;
if ( F_109 ( V_213 ) == V_243 )
V_211 = & V_253 ;
if ( V_252 & V_254 )
V_200 |= V_255 ;
return F_105 ( V_211 , V_213 , V_227 , V_198 , V_200 ) ;
}
int F_127 ( unsigned long V_213 , unsigned long V_256 , unsigned long V_198 ,
unsigned long V_252 )
{
unsigned long V_227 = V_247 | V_257 ;
unsigned long V_200 = 0 ;
struct V_210 * V_211 = V_212 -> V_211 ;
if ( F_109 ( V_213 ) == V_243 )
V_211 = & V_253 ;
if ( V_252 & V_254 )
V_200 |= V_255 ;
if ( V_252 & V_258 )
V_227 |= V_6 ;
V_227 |= V_5 ;
if ( ( V_256 & V_259 ) || ( F_109 ( V_213 ) == V_240 ) )
V_227 &= ~ V_5 ;
if ( V_198 == 0x400 )
V_227 |= V_3 ;
return F_105 ( V_211 , V_213 , V_227 , V_198 , V_200 ) ;
}
static bool F_128 ( struct V_210 * V_211 , unsigned long V_213 )
{
int V_25 = F_95 ( V_211 , V_213 ) ;
if ( F_129 ( V_25 != V_211 -> V_216 . V_260 ) )
return false ;
if ( F_129 ( ( V_25 == V_65 ) && F_100 ( V_211 , V_213 ) ) )
return false ;
return true ;
}
static bool F_128 ( struct V_210 * V_211 , unsigned long V_213 )
{
return true ;
}
void F_130 ( struct V_210 * V_211 , unsigned long V_213 ,
unsigned long V_227 , unsigned long V_198 )
{
int V_261 ;
unsigned long V_35 ;
T_8 * V_235 ;
T_5 * V_236 ;
unsigned long V_200 ;
int V_48 , V_26 , V_262 = 0 ;
F_11 ( F_109 ( V_213 ) != V_240 ) ;
if ( ! F_128 ( V_211 , V_213 ) )
return;
F_107 ( L_50
L_51 , V_211 , V_211 -> V_245 , V_213 , V_227 , V_198 ) ;
V_235 = V_211 -> V_245 ;
if ( V_235 == NULL )
return;
V_26 = F_110 ( V_213 ) ;
V_35 = F_111 ( V_211 -> V_216 . V_242 , V_213 , V_26 ) ;
if ( ! V_35 )
return;
F_131 ( V_200 ) ;
V_236 = F_132 ( V_235 , V_213 , NULL , & V_261 ) ;
if ( ! V_236 )
goto V_263;
F_53 ( V_261 ) ;
#ifdef F_40
if ( ( F_119 ( * V_236 ) & V_250 ) || F_122 ( * V_236 ) )
goto V_263;
#endif
if ( F_114 ( F_115 ( V_211 ) , F_112 ( F_113 () ) ) )
V_262 |= V_246 ;
#ifdef F_40
if ( V_211 -> V_216 . V_260 == V_66 )
V_48 = F_123 ( V_213 , V_227 , V_35 , V_236 , V_198 ,
V_262 , V_26 ) ;
else
#endif
V_48 = F_124 ( V_213 , V_227 , V_35 , V_236 , V_198 , V_262 ,
V_26 , F_100 ( V_211 , V_213 ) ) ;
if ( V_48 == - 1 )
F_101 ( V_213 , V_227 , V_35 , V_198 , V_26 ,
V_211 -> V_216 . V_260 ,
V_211 -> V_216 . V_260 ,
F_119 ( * V_236 ) ) ;
V_263:
F_133 ( V_200 ) ;
}
static inline void F_134 ( int V_264 )
{
if ( V_264 && F_32 ( V_265 ) && V_212 -> V_266 . V_267 &&
F_135 ( V_212 -> V_266 . V_267 -> V_256 ) ) {
F_136 () ;
F_137 ( V_268 ) ;
}
}
static inline void F_134 ( int V_264 )
{
}
void F_138 ( unsigned long V_36 , T_9 V_197 , int V_25 , int V_26 ,
unsigned long V_200 )
{
unsigned long V_33 , V_204 , V_30 , V_269 , V_270 ;
int V_264 = V_200 & V_246 ;
F_107 ( L_52 , V_36 ) ;
F_139 (pte, psize, vpn, index, shift) {
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
V_269 = F_140 ( V_197 , V_204 ) ;
if ( V_269 & V_271 )
V_33 = ~ V_33 ;
V_270 = ( V_33 & V_40 ) * V_41 ;
V_270 += V_269 & V_272 ;
F_107 ( L_53 , V_204 , V_270 , V_269 ) ;
V_42 . V_273 ( V_270 , V_36 , V_25 , V_25 ,
V_26 , V_264 ) ;
} F_141 () ;
F_134 ( V_264 ) ;
}
void F_142 ( unsigned long V_35 , unsigned long V_201 ,
V_248 * V_274 , unsigned int V_25 , int V_26 ,
unsigned long V_200 )
{
int V_275 , V_276 , V_277 ;
unsigned long V_278 ;
unsigned char * V_279 ;
unsigned long V_269 , V_30 , V_36 , V_33 , V_270 ;
int V_264 = V_200 & V_246 ;
V_278 = V_201 & V_280 ;
V_279 = F_143 ( V_274 ) ;
if ( ! V_279 )
return;
if ( V_42 . V_281 ) {
V_42 . V_281 ( V_35 , V_278 , V_279 ,
V_25 , V_26 , V_264 ) ;
goto F_137;
}
V_30 = V_32 [ V_25 ] . V_30 ;
V_276 = V_282 >> V_30 ;
for ( V_275 = 0 ; V_275 < V_276 ; V_275 ++ ) {
V_277 = F_144 ( V_279 , V_275 ) ;
if ( ! V_277 )
continue;
V_269 = F_145 ( V_279 , V_275 ) ;
V_201 = V_278 + ( V_275 * ( 1ul << V_30 ) ) ;
V_36 = F_6 ( V_201 , V_35 , V_26 ) ;
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
if ( V_269 & V_271 )
V_33 = ~ V_33 ;
V_270 = ( V_33 & V_40 ) * V_41 ;
V_270 += V_269 & V_272 ;
V_42 . V_273 ( V_270 , V_36 , V_25 ,
V_68 , V_26 , V_264 ) ;
}
F_137:
F_134 ( V_264 ) ;
}
void F_146 ( unsigned long V_283 , int V_264 )
{
if ( V_42 . F_146 )
V_42 . F_146 ( V_283 , V_264 ) ;
else {
int V_275 ;
struct V_284 * V_285 =
F_147 ( & V_284 ) ;
for ( V_275 = 0 ; V_275 < V_283 ; V_275 ++ )
F_138 ( V_285 -> V_36 [ V_275 ] , V_285 -> V_197 [ V_275 ] ,
V_285 -> V_25 , V_285 -> V_26 , V_264 ) ;
}
}
void F_148 ( struct V_286 * V_267 , unsigned long V_287 , int V_48 )
{
enum V_233 V_234 = F_106 () ;
if ( F_149 ( V_267 ) ) {
#ifdef F_150
if ( V_48 == - 2 )
F_151 ( V_288 , V_267 , V_289 , V_287 ) ;
else
#endif
F_151 ( V_290 , V_267 , V_291 , V_287 ) ;
} else
F_152 ( V_267 , V_287 , V_290 ) ;
F_125 ( V_234 ) ;
}
long F_153 ( unsigned long V_33 , unsigned long V_36 ,
unsigned long V_292 , unsigned long V_2 ,
unsigned long V_293 , int V_25 , int V_26 )
{
unsigned long V_294 ;
long V_270 ;
V_295:
V_294 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_270 = V_42 . V_43 ( V_294 , V_36 , V_292 , V_2 , V_293 ,
V_25 , V_25 , V_26 ) ;
if ( F_129 ( V_270 == - 1 ) ) {
V_294 = ( ( ~ V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_270 = V_42 . V_43 ( V_294 , V_36 , V_292 , V_2 ,
V_293 | V_296 ,
V_25 , V_25 , V_26 ) ;
if ( V_270 == - 1 ) {
if ( F_154 () & 0x1 )
V_294 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_42 . V_297 ( V_294 ) ;
goto V_295;
}
}
return V_270 ;
}
static void F_155 ( unsigned long V_27 , unsigned long V_298 )
{
unsigned long V_33 ;
unsigned long V_35 = F_5 ( V_27 , V_120 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_120 ) ;
unsigned long V_299 = F_1 ( F_51 ( V_119 ) ) ;
long V_31 ;
V_33 = F_10 ( V_36 , V_45 , V_120 ) ;
if ( ! V_35 )
return;
V_31 = F_153 ( V_33 , V_36 , F_50 ( V_27 ) , V_299 ,
V_44 ,
V_100 , V_120 ) ;
F_11 ( V_31 < 0 ) ;
F_156 ( & V_300 ) ;
F_11 ( V_47 [ V_298 ] & 0x80 ) ;
V_47 [ V_298 ] = V_31 | 0x80 ;
F_157 ( & V_300 ) ;
}
static void F_158 ( unsigned long V_27 , unsigned long V_298 )
{
unsigned long V_33 , V_269 , V_270 ;
unsigned long V_35 = F_5 ( V_27 , V_120 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_120 ) ;
V_33 = F_10 ( V_36 , V_45 , V_120 ) ;
F_156 ( & V_300 ) ;
F_11 ( ! ( V_47 [ V_298 ] & 0x80 ) ) ;
V_269 = V_47 [ V_298 ] & 0x7f ;
V_47 [ V_298 ] = 0 ;
F_157 ( & V_300 ) ;
if ( V_269 & V_271 )
V_33 = ~ V_33 ;
V_270 = ( V_33 & V_40 ) * V_41 ;
V_270 += V_269 & V_272 ;
V_42 . V_273 ( V_270 , V_36 , V_100 ,
V_100 ,
V_120 , 0 ) ;
}
void F_159 ( struct V_187 * V_187 , int V_301 , int V_302 )
{
unsigned long V_200 , V_27 , V_298 ;
int V_275 ;
F_131 ( V_200 ) ;
for ( V_275 = 0 ; V_275 < V_301 ; V_275 ++ , V_187 ++ ) {
V_27 = ( unsigned long ) F_160 ( V_187 ) ;
V_298 = F_50 ( V_27 ) >> V_45 ;
if ( V_298 >= V_46 )
continue;
if ( V_302 )
F_155 ( V_27 , V_298 ) ;
else
F_158 ( V_27 , V_298 ) ;
}
F_133 ( V_200 ) ;
}
void F_161 ( T_4 V_303 ,
T_4 V_304 )
{
F_11 ( V_303 != 0 ) ;
V_148 = F_162 ( T_6 , V_304 , 0x40000000 ) ;
F_70 ( V_148 ) ;
}
static int F_163 ( void * V_57 , T_6 * V_305 )
{
* V_305 = V_108 ;
return 0 ;
}
static int F_164 ( void * V_57 , T_6 V_305 )
{
if ( ! V_42 . V_115 )
return - V_50 ;
return V_42 . V_115 ( V_305 ) ;
}
static int T_1 F_165 ( void )
{
if ( ! F_166 ( L_54 , 0600 , V_306 ,
NULL , & V_307 ) ) {
F_22 ( L_55 ) ;
}
return 0 ;
}
