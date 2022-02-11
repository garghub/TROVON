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
if ( V_84 + V_85 * V_83 <= F_26 () ) {
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
F_56 ( 0 , 0 , V_123 , 0 , 2 , 0 , 0 ) ;
V_122 = F_57 ( V_124 ) ;
V_122 &= ~ V_125 ;
F_58 ( V_124 , V_122 ) ;
asm volatile("isync": : :"memory");
while ( ( F_57 ( V_124 ) & V_125 ) )
F_59 () ;
}
static void T_1 F_60 ( T_4 V_126 ,
unsigned long V_127 )
{
F_61 () ;
V_127 = F_45 ( V_127 ) - 18 ;
F_62 ( 0 , V_126 | V_127 , 0 ) ;
F_21 ( L_24 , V_128 ) ;
if ( F_32 ( V_129 ) )
F_54 () ;
}
static void T_1 F_63 ( void )
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
#ifdef F_64
if ( F_65 () && V_42 . V_142 )
V_42 . V_142 () ;
#endif
} else {
unsigned long V_143 = V_144 ;
#ifdef F_66
if ( F_67 ( V_145 , 0 , L_27 ) > 0 ) {
V_143 = 0x80000000 ;
F_21 ( L_28 ) ;
}
#endif
V_130 = F_68 ( V_137 , V_137 ,
V_143 ) ;
F_4 ( L_29 , V_130 ,
V_137 ) ;
V_140 = F_69 ( V_130 ) ;
V_141 = V_130 + F_45 ( V_137 ) - 18 ;
memset ( ( void * ) V_130 , 0 , V_137 ) ;
if ( ! F_32 ( V_146 ) )
F_58 ( V_147 , V_141 ) ;
else
F_60 ( V_130 , V_137 ) ;
}
V_24 = F_51 ( V_119 ) ;
#ifdef F_12
if ( F_13 () ) {
V_46 = F_26 () >> V_45 ;
V_47 = F_69 ( F_68 (
V_46 , 1 , V_148 ) ) ;
memset ( V_47 , 0 , V_46 ) ;
}
#endif
F_70 (memory, reg) {
V_132 = ( unsigned long ) F_69 ( V_134 -> V_132 ) ;
V_59 = V_134 -> V_59 ;
F_4 ( L_30 ,
V_132 , V_59 , V_24 ) ;
F_11 ( F_3 ( V_132 , V_132 + V_59 , F_50 ( V_132 ) ,
V_24 , V_100 , V_120 ) ) ;
}
F_71 ( V_144 ) ;
if ( V_149 ) {
V_149 = ( unsigned long ) F_69 ( V_149 ) ;
V_150 = ( unsigned long ) F_69 ( V_150 ) ;
if ( V_132 + V_59 >= V_149 )
V_149 = V_132 + V_59 + 1 ;
F_11 ( F_3 ( V_149 , V_150 ,
F_50 ( V_149 ) , V_24 ,
V_100 , V_120 ) ) ;
}
F_4 ( L_31 ) ;
}
void T_1 F_72 ( void )
{
F_35 ( F_16 , NULL ) ;
F_34 () ;
}
void T_1 F_73 ( void )
{
F_74 ( V_151 != ( 1ul << ( V_152 + 3 ) ) ) ;
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
V_186 = V_187 ;
V_188 = (struct V_189 * ) V_190 ;
V_191 = V_192 ;
#ifdef F_75
V_193 = V_194 ;
#endif
if ( F_33 ( V_139 ) )
F_76 () ;
else if ( F_33 ( V_138 ) )
F_77 () ;
else if ( F_78 ( V_195 ) )
F_79 () ;
if ( ! V_42 . V_43 )
F_80 ( L_32 ) ;
F_63 () ;
F_21 ( L_33 ) ;
F_81 () ;
}
void F_82 ( void )
{
if ( ! F_33 ( V_138 ) ) {
if ( F_32 ( V_129 ) )
F_54 () ;
if ( ! F_32 ( V_146 ) )
F_58 ( V_147 , V_141 ) ;
else
F_58 ( V_196 ,
F_50 ( V_128 ) | ( V_197 - 12 ) ) ;
}
F_81 () ;
}
unsigned int F_83 ( unsigned int V_198 , T_5 V_199 , int V_200 )
{
struct V_189 * V_189 ;
if ( ! F_84 ( F_85 ( V_199 ) ) )
return V_198 ;
V_189 = F_86 ( V_199 ) ;
if ( ! F_87 ( V_201 , & V_189 -> V_202 ) && ! F_88 ( V_189 ) ) {
if ( V_200 == 0x400 ) {
F_89 ( V_189 ) ;
F_90 ( V_201 , & V_189 -> V_202 ) ;
} else
V_198 |= V_4 ;
}
return V_198 ;
}
static unsigned int F_91 ( unsigned long V_203 )
{
T_6 V_204 ;
unsigned char * V_205 ;
unsigned long V_206 , V_207 ;
if ( V_203 < V_208 ) {
V_204 = F_92 () -> V_209 ;
V_206 = F_93 ( V_203 ) ;
return ( V_204 >> ( V_206 * 4 ) ) & 0xF ;
}
V_205 = F_92 () -> V_210 ;
V_206 = F_94 ( V_203 ) ;
V_207 = V_206 & 0x1 ;
return ( V_205 [ V_206 >> 1 ] >> ( V_207 * 4 ) ) & 0xF ;
}
unsigned int F_91 ( unsigned long V_203 )
{
return F_92 () -> V_211 ;
}
void F_95 ( struct V_212 * V_213 , unsigned long V_203 )
{
if ( F_96 ( V_213 , V_203 ) == V_65 )
return;
F_97 ( V_213 , V_203 , 1 , V_65 ) ;
F_98 ( V_213 ) ;
if ( ( F_91 ( V_203 ) != V_65 ) && ( V_214 -> V_213 == V_213 ) ) {
F_99 ( V_213 ) ;
F_100 () ;
}
}
static int F_101 ( struct V_212 * V_213 , unsigned long V_215 )
{
struct V_216 * V_217 = & V_213 -> V_218 . V_217 ;
T_7 V_219 = 0 ;
T_7 * * V_220 , * V_221 ;
if ( V_215 >= V_217 -> V_222 )
return 0 ;
if ( V_215 < 0x100000000UL ) {
V_220 = V_217 -> V_223 ;
} else {
V_220 = V_217 -> V_224 [ V_215 >> V_225 ] ;
if ( ! V_220 )
return 0 ;
}
V_221 = V_220 [ ( V_215 >> V_226 ) & ( V_227 - 1 ) ] ;
if ( ! V_221 )
return 0 ;
V_219 = V_221 [ ( V_215 >> V_45 ) & ( V_228 - 1 ) ] ;
V_219 >>= 30 - 2 * ( ( V_215 >> 12 ) & 0xf ) ;
V_219 = ( ( V_219 & 2 ) ? V_9 : 0 ) | ( ( V_219 & 1 ) ? V_6 : 0 ) ;
return V_219 ;
}
static inline int F_101 ( struct V_212 * V_213 , unsigned long V_215 )
{
return 0 ;
}
void F_102 ( unsigned long V_215 , unsigned long V_229 ,
unsigned long V_35 , unsigned long V_200 ,
int V_26 , int V_25 , int V_230 , unsigned long V_199 )
{
if ( ! F_103 () )
return;
F_21 ( L_34 ,
V_215 , V_229 , V_214 -> V_231 ) ;
F_21 ( L_35 ,
V_200 , V_35 , V_26 , V_25 , V_230 , V_199 ) ;
}
static void F_104 ( unsigned long V_215 , struct V_212 * V_213 ,
int V_25 , bool V_232 )
{
if ( V_232 ) {
if ( V_25 != F_91 ( V_215 ) ) {
F_99 ( V_213 ) ;
F_100 () ;
}
} else if ( F_92 () -> V_233 !=
V_32 [ V_102 ] . V_78 ) {
F_92 () -> V_233 =
V_32 [ V_102 ] . V_78 ;
F_105 () ;
}
}
int F_106 ( struct V_212 * V_213 , unsigned long V_215 ,
unsigned long V_229 , unsigned long V_200 ,
unsigned long V_202 )
{
bool V_234 ;
enum V_235 V_236 = F_107 () ;
T_8 * V_237 ;
unsigned long V_35 ;
T_5 * V_238 ;
unsigned V_239 ;
int V_48 , V_232 = 0 ;
int V_25 , V_26 ;
F_108 ( L_36 ,
V_215 , V_229 , V_200 ) ;
F_109 ( V_215 , V_229 , V_200 ) ;
switch ( F_110 ( V_215 ) ) {
case V_240 :
V_232 = 1 ;
if ( ! V_213 ) {
F_108 ( L_37 ) ;
V_48 = 1 ;
goto V_241;
}
V_25 = F_96 ( V_213 , V_215 ) ;
V_26 = F_111 ( V_215 ) ;
V_35 = F_112 ( V_213 -> V_218 . V_242 , V_215 , V_26 ) ;
break;
case V_243 :
V_35 = F_5 ( V_215 , V_120 ) ;
if ( V_215 < V_244 )
V_25 = V_102 ;
else
V_25 = V_104 ;
V_26 = V_120 ;
break;
default:
V_48 = 1 ;
goto V_241;
}
F_108 ( L_38 , V_213 , V_213 -> V_245 , V_35 ) ;
if ( ! V_35 ) {
F_108 ( L_39 ) ;
V_48 = 1 ;
goto V_241;
}
V_237 = V_213 -> V_245 ;
if ( V_237 == NULL ) {
V_48 = 1 ;
goto V_241;
}
if ( V_232 && F_113 ( V_213 ) )
V_202 |= V_246 ;
#ifndef F_40
if ( V_25 != V_65 )
V_215 &= ~ ( ( 1ul << V_32 [ V_25 ] . V_30 ) - 1 ) ;
#endif
V_238 = F_114 ( V_237 , V_215 , & V_234 , & V_239 ) ;
if ( V_238 == NULL || ! F_115 ( * V_238 ) ) {
F_108 ( L_40 ) ;
V_48 = 1 ;
goto V_241;
}
V_229 |= V_247 ;
if ( ! F_116 ( V_229 , F_117 ( * V_238 ) ) ) {
F_108 ( L_41 ) ;
V_48 = 1 ;
goto V_241;
}
if ( V_239 ) {
if ( V_234 )
V_48 = F_118 ( V_215 , V_229 , V_35 , ( V_248 * ) V_238 ,
V_200 , V_202 , V_26 , V_25 ) ;
#ifdef F_37
else
V_48 = F_119 ( V_215 , V_229 , V_35 , V_238 , V_200 ,
V_202 , V_26 , V_239 , V_25 ) ;
#else
else {
V_48 = 1 ;
F_53 ( 1 ) ;
}
#endif
if ( V_214 -> V_213 == V_213 )
F_104 ( V_215 , V_213 , V_25 , V_232 ) ;
goto V_241;
}
#ifndef F_40
F_108 ( L_42 , F_117 ( * V_238 ) ) ;
#else
F_108 ( L_43 , F_117 ( * V_238 ) ,
F_117 ( * ( V_238 + V_249 ) ) ) ;
#endif
#ifdef F_40
if ( ( F_117 ( * V_238 ) & V_250 ) && V_25 == V_66 ) {
F_95 ( V_213 , V_215 ) ;
V_25 = V_65 ;
}
if ( V_105 && V_25 == V_66 && F_120 ( * V_238 ) ) {
if ( V_232 ) {
F_95 ( V_213 , V_215 ) ;
V_25 = V_65 ;
} else if ( V_215 < V_244 ) {
F_25 ( V_251 L_44
L_45
L_46 ) ;
V_25 = V_102 = V_65 ;
F_98 ( V_213 ) ;
}
}
#endif
if ( V_214 -> V_213 == V_213 )
F_104 ( V_215 , V_213 , V_25 , V_232 ) ;
#ifdef F_40
if ( V_25 == V_66 )
V_48 = F_121 ( V_215 , V_229 , V_35 , V_238 , V_200 ,
V_202 , V_26 ) ;
else
#endif
{
int V_219 = F_101 ( V_213 , V_215 ) ;
if ( V_229 & V_219 )
V_48 = - 2 ;
else
V_48 = F_122 ( V_215 , V_229 , V_35 , V_238 , V_200 ,
V_202 , V_26 , V_219 ) ;
}
if ( V_48 == - 1 )
F_102 ( V_215 , V_229 , V_35 , V_200 , V_26 , V_25 ,
V_25 , F_117 ( * V_238 ) ) ;
#ifndef F_40
F_108 ( L_47 , F_117 ( * V_238 ) ) ;
#else
F_108 ( L_48 , F_117 ( * V_238 ) ,
F_117 ( * ( V_238 + V_249 ) ) ) ;
#endif
F_108 ( L_49 , V_48 ) ;
V_241:
F_123 ( V_236 ) ;
return V_48 ;
}
int F_124 ( unsigned long V_215 , unsigned long V_229 , unsigned long V_200 ,
unsigned long V_252 )
{
unsigned long V_202 = 0 ;
struct V_212 * V_213 = V_214 -> V_213 ;
if ( F_110 ( V_215 ) == V_243 )
V_213 = & V_253 ;
if ( V_252 & V_254 )
V_202 |= V_255 ;
return F_106 ( V_213 , V_215 , V_229 , V_200 , V_202 ) ;
}
int F_125 ( unsigned long V_215 , unsigned long V_256 , unsigned long V_200 ,
unsigned long V_252 )
{
unsigned long V_229 = V_247 | V_257 ;
unsigned long V_202 = 0 ;
struct V_212 * V_213 = V_214 -> V_213 ;
if ( F_110 ( V_215 ) == V_243 )
V_213 = & V_253 ;
if ( V_252 & V_254 )
V_202 |= V_255 ;
if ( V_252 & V_258 )
V_229 |= V_6 ;
V_229 |= V_5 ;
if ( ( V_256 & V_259 ) || ( F_110 ( V_215 ) == V_240 ) )
V_229 &= ~ V_5 ;
if ( V_200 == 0x400 )
V_229 |= V_3 ;
return F_106 ( V_213 , V_215 , V_229 , V_200 , V_202 ) ;
}
static bool F_126 ( struct V_212 * V_213 , unsigned long V_215 )
{
int V_25 = F_96 ( V_213 , V_215 ) ;
if ( F_127 ( V_25 != V_213 -> V_218 . V_260 ) )
return false ;
if ( F_127 ( ( V_25 == V_65 ) && F_101 ( V_213 , V_215 ) ) )
return false ;
return true ;
}
static bool F_126 ( struct V_212 * V_213 , unsigned long V_215 )
{
return true ;
}
void F_128 ( struct V_212 * V_213 , unsigned long V_215 ,
unsigned long V_229 , unsigned long V_200 )
{
int V_261 ;
unsigned long V_35 ;
T_8 * V_237 ;
T_5 * V_238 ;
unsigned long V_202 ;
int V_48 , V_26 , V_262 = 0 ;
F_11 ( F_110 ( V_215 ) != V_240 ) ;
if ( ! F_126 ( V_213 , V_215 ) )
return;
F_108 ( L_50
L_51 , V_213 , V_213 -> V_245 , V_215 , V_229 , V_200 ) ;
V_237 = V_213 -> V_245 ;
if ( V_237 == NULL )
return;
V_26 = F_111 ( V_215 ) ;
V_35 = F_112 ( V_213 -> V_218 . V_242 , V_215 , V_26 ) ;
if ( ! V_35 )
return;
F_129 ( V_202 ) ;
V_238 = F_130 ( V_237 , V_215 , NULL , & V_261 ) ;
if ( ! V_238 )
goto V_263;
F_53 ( V_261 ) ;
#ifdef F_40
if ( ( F_117 ( * V_238 ) & V_250 ) || F_120 ( * V_238 ) )
goto V_263;
#endif
if ( F_113 ( V_213 ) )
V_262 |= V_246 ;
#ifdef F_40
if ( V_213 -> V_218 . V_260 == V_66 )
V_48 = F_121 ( V_215 , V_229 , V_35 , V_238 , V_200 ,
V_262 , V_26 ) ;
else
#endif
V_48 = F_122 ( V_215 , V_229 , V_35 , V_238 , V_200 , V_262 ,
V_26 , F_101 ( V_213 , V_215 ) ) ;
if ( V_48 == - 1 )
F_102 ( V_215 , V_229 , V_35 , V_200 , V_26 ,
V_213 -> V_218 . V_260 ,
V_213 -> V_218 . V_260 ,
F_117 ( * V_238 ) ) ;
V_263:
F_131 ( V_202 ) ;
}
static inline void F_132 ( int V_264 )
{
if ( V_264 && F_32 ( V_265 ) && V_214 -> V_266 . V_267 &&
F_133 ( V_214 -> V_266 . V_267 -> V_256 ) ) {
F_134 () ;
F_135 ( V_268 ) ;
}
}
static inline void F_132 ( int V_264 )
{
}
void F_136 ( unsigned long V_36 , T_9 V_199 , int V_25 , int V_26 ,
unsigned long V_202 )
{
unsigned long V_33 , V_206 , V_30 , V_269 , V_270 ;
int V_264 = V_202 & V_246 ;
F_108 ( L_52 , V_36 ) ;
F_137 (pte, psize, vpn, index, shift) {
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
V_269 = F_138 ( V_199 , V_206 ) ;
if ( V_269 & V_271 )
V_33 = ~ V_33 ;
V_270 = ( V_33 & V_40 ) * V_41 ;
V_270 += V_269 & V_272 ;
F_108 ( L_53 , V_206 , V_270 , V_269 ) ;
V_42 . V_273 ( V_270 , V_36 , V_25 , V_25 ,
V_26 , V_264 ) ;
} F_139 () ;
F_132 ( V_264 ) ;
}
void F_140 ( unsigned long V_35 , unsigned long V_203 ,
V_248 * V_274 , unsigned int V_25 , int V_26 ,
unsigned long V_202 )
{
int V_275 , V_276 , V_277 ;
unsigned long V_278 ;
unsigned char * V_279 ;
unsigned long V_269 , V_30 , V_36 , V_33 , V_270 ;
int V_264 = V_202 & V_246 ;
V_278 = V_203 & V_280 ;
V_279 = F_141 ( V_274 ) ;
if ( ! V_279 )
return;
if ( V_42 . V_281 ) {
V_42 . V_281 ( V_35 , V_278 , V_279 ,
V_25 , V_26 , V_264 ) ;
goto F_135;
}
V_30 = V_32 [ V_25 ] . V_30 ;
V_276 = V_282 >> V_30 ;
for ( V_275 = 0 ; V_275 < V_276 ; V_275 ++ ) {
V_277 = F_142 ( V_279 , V_275 ) ;
if ( ! V_277 )
continue;
V_269 = F_143 ( V_279 , V_275 ) ;
V_203 = V_278 + ( V_275 * ( 1ul << V_30 ) ) ;
V_36 = F_6 ( V_203 , V_35 , V_26 ) ;
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
if ( V_269 & V_271 )
V_33 = ~ V_33 ;
V_270 = ( V_33 & V_40 ) * V_41 ;
V_270 += V_269 & V_272 ;
V_42 . V_273 ( V_270 , V_36 , V_25 ,
V_68 , V_26 , V_264 ) ;
}
F_135:
F_132 ( V_264 ) ;
}
void F_144 ( unsigned long V_283 , int V_264 )
{
if ( V_42 . F_144 )
V_42 . F_144 ( V_283 , V_264 ) ;
else {
int V_275 ;
struct V_284 * V_285 =
F_145 ( & V_284 ) ;
for ( V_275 = 0 ; V_275 < V_283 ; V_275 ++ )
F_136 ( V_285 -> V_36 [ V_275 ] , V_285 -> V_199 [ V_275 ] ,
V_285 -> V_25 , V_285 -> V_26 , V_264 ) ;
}
}
void F_146 ( struct V_286 * V_267 , unsigned long V_287 , int V_48 )
{
enum V_235 V_236 = F_107 () ;
if ( F_147 ( V_267 ) ) {
#ifdef F_148
if ( V_48 == - 2 )
F_149 ( V_288 , V_267 , V_289 , V_287 ) ;
else
#endif
F_149 ( V_290 , V_267 , V_291 , V_287 ) ;
} else
F_150 ( V_267 , V_287 , V_290 ) ;
F_123 ( V_236 ) ;
}
long F_151 ( unsigned long V_33 , unsigned long V_36 ,
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
if ( F_127 ( V_270 == - 1 ) ) {
V_294 = ( ( ~ V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_270 = V_42 . V_43 ( V_294 , V_36 , V_292 , V_2 ,
V_293 | V_296 ,
V_25 , V_25 , V_26 ) ;
if ( V_270 == - 1 ) {
if ( F_152 () & 0x1 )
V_294 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_42 . V_297 ( V_294 ) ;
goto V_295;
}
}
return V_270 ;
}
static void F_153 ( unsigned long V_27 , unsigned long V_298 )
{
unsigned long V_33 ;
unsigned long V_35 = F_5 ( V_27 , V_120 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_120 ) ;
unsigned long V_299 = F_1 ( F_51 ( V_119 ) ) ;
long V_31 ;
V_33 = F_10 ( V_36 , V_45 , V_120 ) ;
if ( ! V_35 )
return;
V_31 = F_151 ( V_33 , V_36 , F_50 ( V_27 ) , V_299 ,
V_44 ,
V_100 , V_120 ) ;
F_11 ( V_31 < 0 ) ;
F_154 ( & V_300 ) ;
F_11 ( V_47 [ V_298 ] & 0x80 ) ;
V_47 [ V_298 ] = V_31 | 0x80 ;
F_155 ( & V_300 ) ;
}
static void F_156 ( unsigned long V_27 , unsigned long V_298 )
{
unsigned long V_33 , V_269 , V_270 ;
unsigned long V_35 = F_5 ( V_27 , V_120 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_120 ) ;
V_33 = F_10 ( V_36 , V_45 , V_120 ) ;
F_154 ( & V_300 ) ;
F_11 ( ! ( V_47 [ V_298 ] & 0x80 ) ) ;
V_269 = V_47 [ V_298 ] & 0x7f ;
V_47 [ V_298 ] = 0 ;
F_155 ( & V_300 ) ;
if ( V_269 & V_271 )
V_33 = ~ V_33 ;
V_270 = ( V_33 & V_40 ) * V_41 ;
V_270 += V_269 & V_272 ;
V_42 . V_273 ( V_270 , V_36 , V_100 ,
V_100 ,
V_120 , 0 ) ;
}
void F_157 ( struct V_189 * V_189 , int V_301 , int V_302 )
{
unsigned long V_202 , V_27 , V_298 ;
int V_275 ;
F_129 ( V_202 ) ;
for ( V_275 = 0 ; V_275 < V_301 ; V_275 ++ , V_189 ++ ) {
V_27 = ( unsigned long ) F_158 ( V_189 ) ;
V_298 = F_50 ( V_27 ) >> V_45 ;
if ( V_298 >= V_46 )
continue;
if ( V_302 )
F_153 ( V_27 , V_298 ) ;
else
F_156 ( V_27 , V_298 ) ;
}
F_131 ( V_202 ) ;
}
void F_159 ( T_4 V_303 ,
T_4 V_304 )
{
F_11 ( V_303 != 0 ) ;
V_148 = F_160 ( T_6 , V_304 , 0x40000000 ) ;
F_71 ( V_148 ) ;
}
static int F_161 ( void * V_57 , T_6 * V_305 )
{
* V_305 = V_108 ;
return 0 ;
}
static int F_162 ( void * V_57 , T_6 V_305 )
{
if ( ! V_42 . V_115 )
return - V_50 ;
return V_42 . V_115 ( V_305 ) ;
}
static int T_1 F_163 ( void )
{
if ( ! F_164 ( L_54 , 0600 , V_306 ,
NULL , & V_307 ) ) {
F_22 ( L_55 ) ;
}
return 0 ;
}
