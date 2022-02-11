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
F_39 () ;
V_151 = V_152 ;
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
V_173 = 0 ;
V_174 = 0 ;
V_175 = 0 ;
V_176 = V_177 ;
V_178 = V_179 ;
V_180 = V_181 ;
V_182 = V_183 ;
V_184 = (struct V_185 * ) V_186 ;
V_187 = V_188 ;
#ifdef F_73
V_189 = V_190 ;
#endif
if ( F_33 ( V_139 ) )
F_74 () ;
else if ( F_33 ( V_138 ) )
F_75 () ;
else if ( F_76 ( V_191 ) )
F_77 () ;
if ( ! V_42 . V_43 )
F_78 ( L_32 ) ;
F_62 () ;
F_21 ( L_33 ) ;
F_79 () ;
}
void F_80 ( void )
{
if ( ! F_33 ( V_138 ) ) {
if ( F_32 ( V_129 ) )
F_54 () ;
if ( ! F_32 ( V_146 ) )
F_57 ( V_147 , V_141 ) ;
else
F_57 ( V_192 ,
F_50 ( V_128 ) | ( V_193 - 12 ) ) ;
}
F_79 () ;
}
unsigned int F_81 ( unsigned int V_194 , T_5 V_195 , int V_196 )
{
struct V_185 * V_185 ;
if ( ! F_82 ( F_83 ( V_195 ) ) )
return V_194 ;
V_185 = F_84 ( V_195 ) ;
if ( ! F_85 ( V_197 , & V_185 -> V_198 ) && ! F_86 ( V_185 ) ) {
if ( V_196 == 0x400 ) {
F_87 ( V_185 ) ;
F_88 ( V_197 , & V_185 -> V_198 ) ;
} else
V_194 |= V_4 ;
}
return V_194 ;
}
static unsigned int F_89 ( unsigned long V_199 )
{
T_6 V_200 ;
unsigned char * V_201 ;
unsigned long V_202 , V_203 ;
if ( V_199 < V_204 ) {
V_200 = F_90 () -> V_205 ;
V_202 = F_91 ( V_199 ) ;
return ( V_200 >> ( V_202 * 4 ) ) & 0xF ;
}
V_201 = F_90 () -> V_206 ;
V_202 = F_92 ( V_199 ) ;
V_203 = V_202 & 0x1 ;
return ( V_201 [ V_202 >> 1 ] >> ( V_203 * 4 ) ) & 0xF ;
}
unsigned int F_89 ( unsigned long V_199 )
{
return F_90 () -> V_207 ;
}
void F_93 ( struct V_208 * V_209 , unsigned long V_199 )
{
if ( F_94 ( V_209 , V_199 ) == V_65 )
return;
F_95 ( V_209 , V_199 , 1 , V_65 ) ;
F_96 ( V_209 ) ;
if ( ( F_89 ( V_199 ) != V_65 ) && ( V_210 -> V_209 == V_209 ) ) {
F_97 ( & V_209 -> V_211 ) ;
F_98 () ;
}
}
static int F_99 ( struct V_208 * V_209 , unsigned long V_212 )
{
struct V_213 * V_214 = & V_209 -> V_211 . V_214 ;
T_7 V_215 = 0 ;
T_7 * * V_216 , * V_217 ;
if ( V_212 >= V_214 -> V_218 )
return 0 ;
if ( V_212 < 0x100000000UL ) {
V_216 = V_214 -> V_219 ;
} else {
V_216 = V_214 -> V_220 [ V_212 >> V_221 ] ;
if ( ! V_216 )
return 0 ;
}
V_217 = V_216 [ ( V_212 >> V_222 ) & ( V_223 - 1 ) ] ;
if ( ! V_217 )
return 0 ;
V_215 = V_217 [ ( V_212 >> V_45 ) & ( V_224 - 1 ) ] ;
V_215 >>= 30 - 2 * ( ( V_212 >> 12 ) & 0xf ) ;
V_215 = ( ( V_215 & 2 ) ? V_9 : 0 ) | ( ( V_215 & 1 ) ? V_6 : 0 ) ;
return V_215 ;
}
static inline int F_99 ( struct V_208 * V_209 , unsigned long V_212 )
{
return 0 ;
}
void F_100 ( unsigned long V_212 , unsigned long V_225 ,
unsigned long V_35 , unsigned long V_196 ,
int V_26 , int V_25 , int V_226 , unsigned long V_195 )
{
if ( ! F_101 () )
return;
F_21 ( L_34 ,
V_212 , V_225 , V_210 -> V_227 ) ;
F_21 ( L_35 ,
V_196 , V_35 , V_26 , V_25 , V_226 , V_195 ) ;
}
static void F_102 ( unsigned long V_212 , struct V_208 * V_209 ,
int V_25 , bool V_228 )
{
if ( V_228 ) {
if ( V_25 != F_89 ( V_212 ) ) {
F_97 ( & V_209 -> V_211 ) ;
F_98 () ;
}
} else if ( F_90 () -> V_229 !=
V_32 [ V_102 ] . V_78 ) {
F_90 () -> V_229 =
V_32 [ V_102 ] . V_78 ;
F_103 () ;
}
}
int F_104 ( struct V_208 * V_209 , unsigned long V_212 ,
unsigned long V_225 , unsigned long V_196 ,
unsigned long V_198 )
{
bool V_230 ;
enum V_231 V_232 = F_105 () ;
T_8 * V_233 ;
unsigned long V_35 ;
T_5 * V_234 ;
unsigned V_235 ;
const struct V_236 * V_237 ;
int V_48 , V_228 = 0 ;
int V_25 , V_26 ;
F_106 ( L_36 ,
V_212 , V_225 , V_196 ) ;
F_107 ( V_212 , V_225 , V_196 ) ;
switch ( F_108 ( V_212 ) ) {
case V_238 :
V_228 = 1 ;
if ( ! V_209 ) {
F_106 ( L_37 ) ;
V_48 = 1 ;
goto V_239;
}
V_25 = F_94 ( V_209 , V_212 ) ;
V_26 = F_109 ( V_212 ) ;
V_35 = F_110 ( V_209 -> V_211 . V_240 , V_212 , V_26 ) ;
break;
case V_241 :
V_35 = F_5 ( V_212 , V_120 ) ;
if ( V_212 < V_242 )
V_25 = V_102 ;
else
V_25 = V_104 ;
V_26 = V_120 ;
break;
default:
V_48 = 1 ;
goto V_239;
}
F_106 ( L_38 , V_209 , V_209 -> V_243 , V_35 ) ;
if ( ! V_35 ) {
F_106 ( L_39 ) ;
V_48 = 1 ;
goto V_239;
}
V_233 = V_209 -> V_243 ;
if ( V_233 == NULL ) {
V_48 = 1 ;
goto V_239;
}
V_237 = F_111 ( F_112 () ) ;
if ( V_228 && F_113 ( F_114 ( V_209 ) , V_237 ) )
V_198 |= V_244 ;
#ifndef F_40
if ( V_25 != V_65 )
V_212 &= ~ ( ( 1ul << V_32 [ V_25 ] . V_30 ) - 1 ) ;
#endif
V_234 = F_115 ( V_233 , V_212 , & V_230 , & V_235 ) ;
if ( V_234 == NULL || ! F_116 ( * V_234 ) ) {
F_106 ( L_40 ) ;
V_48 = 1 ;
goto V_239;
}
V_225 |= V_245 ;
if ( ! F_117 ( V_225 , F_118 ( * V_234 ) ) ) {
F_106 ( L_41 ) ;
V_48 = 1 ;
goto V_239;
}
if ( V_235 ) {
if ( V_230 )
V_48 = F_119 ( V_212 , V_225 , V_35 , ( V_246 * ) V_234 ,
V_196 , V_198 , V_26 , V_25 ) ;
#ifdef F_37
else
V_48 = F_120 ( V_212 , V_225 , V_35 , V_234 , V_196 ,
V_198 , V_26 , V_235 , V_25 ) ;
#else
else {
V_48 = 1 ;
F_53 ( 1 ) ;
}
#endif
if ( V_210 -> V_209 == V_209 )
F_102 ( V_212 , V_209 , V_25 , V_228 ) ;
goto V_239;
}
#ifndef F_40
F_106 ( L_42 , F_118 ( * V_234 ) ) ;
#else
F_106 ( L_43 , F_118 ( * V_234 ) ,
F_118 ( * ( V_234 + V_247 ) ) ) ;
#endif
#ifdef F_40
if ( ( F_118 ( * V_234 ) & V_248 ) && V_25 == V_66 ) {
F_93 ( V_209 , V_212 ) ;
V_25 = V_65 ;
}
if ( V_105 && V_25 == V_66 && F_121 ( * V_234 ) ) {
if ( V_228 ) {
F_93 ( V_209 , V_212 ) ;
V_25 = V_65 ;
} else if ( V_212 < V_242 ) {
F_25 ( V_249 L_44
L_45
L_46 ) ;
V_25 = V_102 = V_65 ;
F_96 ( V_209 ) ;
}
}
#endif
if ( V_210 -> V_209 == V_209 )
F_102 ( V_212 , V_209 , V_25 , V_228 ) ;
#ifdef F_40
if ( V_25 == V_66 )
V_48 = F_122 ( V_212 , V_225 , V_35 , V_234 , V_196 ,
V_198 , V_26 ) ;
else
#endif
{
int V_215 = F_99 ( V_209 , V_212 ) ;
if ( V_225 & V_215 )
V_48 = - 2 ;
else
V_48 = F_123 ( V_212 , V_225 , V_35 , V_234 , V_196 ,
V_198 , V_26 , V_215 ) ;
}
if ( V_48 == - 1 )
F_100 ( V_212 , V_225 , V_35 , V_196 , V_26 , V_25 ,
V_25 , F_118 ( * V_234 ) ) ;
#ifndef F_40
F_106 ( L_47 , F_118 ( * V_234 ) ) ;
#else
F_106 ( L_48 , F_118 ( * V_234 ) ,
F_118 ( * ( V_234 + V_247 ) ) ) ;
#endif
F_106 ( L_49 , V_48 ) ;
V_239:
F_124 ( V_232 ) ;
return V_48 ;
}
int F_125 ( unsigned long V_212 , unsigned long V_225 , unsigned long V_196 ,
unsigned long V_250 )
{
unsigned long V_198 = 0 ;
struct V_208 * V_209 = V_210 -> V_209 ;
if ( F_108 ( V_212 ) == V_241 )
V_209 = & V_251 ;
if ( V_250 & V_252 )
V_198 |= V_253 ;
return F_104 ( V_209 , V_212 , V_225 , V_196 , V_198 ) ;
}
int F_126 ( unsigned long V_212 , unsigned long V_254 , unsigned long V_196 ,
unsigned long V_250 )
{
unsigned long V_225 = V_245 | V_255 ;
unsigned long V_198 = 0 ;
struct V_208 * V_209 = V_210 -> V_209 ;
if ( F_108 ( V_212 ) == V_241 )
V_209 = & V_251 ;
if ( V_250 & V_252 )
V_198 |= V_253 ;
if ( V_250 & V_256 )
V_225 |= V_6 ;
V_225 |= V_5 ;
if ( ( V_254 & V_257 ) || ( F_108 ( V_212 ) == V_238 ) )
V_225 &= ~ V_5 ;
if ( V_196 == 0x400 )
V_225 |= V_3 ;
return F_104 ( V_209 , V_212 , V_225 , V_196 , V_198 ) ;
}
static bool F_127 ( struct V_208 * V_209 , unsigned long V_212 )
{
int V_25 = F_94 ( V_209 , V_212 ) ;
if ( F_128 ( V_25 != V_209 -> V_211 . V_258 ) )
return false ;
if ( F_128 ( ( V_25 == V_65 ) && F_99 ( V_209 , V_212 ) ) )
return false ;
return true ;
}
static bool F_127 ( struct V_208 * V_209 , unsigned long V_212 )
{
return true ;
}
void F_129 ( struct V_208 * V_209 , unsigned long V_212 ,
unsigned long V_225 , unsigned long V_196 )
{
int V_259 ;
unsigned long V_35 ;
T_8 * V_233 ;
T_5 * V_234 ;
unsigned long V_198 ;
int V_48 , V_26 , V_260 = 0 ;
F_11 ( F_108 ( V_212 ) != V_238 ) ;
if ( ! F_127 ( V_209 , V_212 ) )
return;
F_106 ( L_50
L_51 , V_209 , V_209 -> V_243 , V_212 , V_225 , V_196 ) ;
V_233 = V_209 -> V_243 ;
if ( V_233 == NULL )
return;
V_26 = F_109 ( V_212 ) ;
V_35 = F_110 ( V_209 -> V_211 . V_240 , V_212 , V_26 ) ;
if ( ! V_35 )
return;
F_130 ( V_198 ) ;
V_234 = F_131 ( V_233 , V_212 , NULL , & V_259 ) ;
if ( ! V_234 )
goto V_261;
F_53 ( V_259 ) ;
#ifdef F_40
if ( ( F_118 ( * V_234 ) & V_248 ) || F_121 ( * V_234 ) )
goto V_261;
#endif
if ( F_113 ( F_114 ( V_209 ) , F_111 ( F_112 () ) ) )
V_260 |= V_244 ;
#ifdef F_40
if ( V_209 -> V_211 . V_258 == V_66 )
V_48 = F_122 ( V_212 , V_225 , V_35 , V_234 , V_196 ,
V_260 , V_26 ) ;
else
#endif
V_48 = F_123 ( V_212 , V_225 , V_35 , V_234 , V_196 , V_260 ,
V_26 , F_99 ( V_209 , V_212 ) ) ;
if ( V_48 == - 1 )
F_100 ( V_212 , V_225 , V_35 , V_196 , V_26 ,
V_209 -> V_211 . V_258 ,
V_209 -> V_211 . V_258 ,
F_118 ( * V_234 ) ) ;
V_261:
F_132 ( V_198 ) ;
}
static inline void F_133 ( int V_262 )
{
if ( V_262 && F_32 ( V_263 ) && V_210 -> V_264 . V_265 &&
F_134 ( V_210 -> V_264 . V_265 -> V_254 ) ) {
F_135 () ;
F_136 ( V_266 ) ;
}
}
static inline void F_133 ( int V_262 )
{
}
void F_137 ( unsigned long V_36 , T_9 V_195 , int V_25 , int V_26 ,
unsigned long V_198 )
{
unsigned long V_33 , V_202 , V_30 , V_267 , V_268 ;
int V_262 = V_198 & V_244 ;
F_106 ( L_52 , V_36 ) ;
F_138 (pte, psize, vpn, index, shift) {
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
V_267 = F_139 ( V_195 , V_202 ) ;
if ( V_267 & V_269 )
V_33 = ~ V_33 ;
V_268 = ( V_33 & V_40 ) * V_41 ;
V_268 += V_267 & V_270 ;
F_106 ( L_53 , V_202 , V_268 , V_267 ) ;
V_42 . V_271 ( V_268 , V_36 , V_25 , V_25 ,
V_26 , V_262 ) ;
} F_140 () ;
F_133 ( V_262 ) ;
}
void F_141 ( unsigned long V_35 , unsigned long V_199 ,
V_246 * V_272 , unsigned int V_25 , int V_26 ,
unsigned long V_198 )
{
int V_273 , V_274 , V_275 ;
unsigned long V_276 ;
unsigned char * V_277 ;
unsigned long V_267 , V_30 , V_36 , V_33 , V_268 ;
int V_262 = V_198 & V_244 ;
V_276 = V_199 & V_278 ;
V_277 = F_142 ( V_272 ) ;
if ( ! V_277 )
return;
if ( V_42 . V_279 ) {
V_42 . V_279 ( V_35 , V_276 , V_277 ,
V_25 , V_26 , V_262 ) ;
goto F_136;
}
V_30 = V_32 [ V_25 ] . V_30 ;
V_274 = V_280 >> V_30 ;
for ( V_273 = 0 ; V_273 < V_274 ; V_273 ++ ) {
V_275 = F_143 ( V_277 , V_273 ) ;
if ( ! V_275 )
continue;
V_267 = F_144 ( V_277 , V_273 ) ;
V_199 = V_276 + ( V_273 * ( 1ul << V_30 ) ) ;
V_36 = F_6 ( V_199 , V_35 , V_26 ) ;
V_33 = F_10 ( V_36 , V_30 , V_26 ) ;
if ( V_267 & V_269 )
V_33 = ~ V_33 ;
V_268 = ( V_33 & V_40 ) * V_41 ;
V_268 += V_267 & V_270 ;
V_42 . V_271 ( V_268 , V_36 , V_25 ,
V_68 , V_26 , V_262 ) ;
}
F_136:
F_133 ( V_262 ) ;
}
void F_145 ( unsigned long V_281 , int V_262 )
{
if ( V_42 . F_145 )
V_42 . F_145 ( V_281 , V_262 ) ;
else {
int V_273 ;
struct V_282 * V_283 =
F_146 ( & V_282 ) ;
for ( V_273 = 0 ; V_273 < V_281 ; V_273 ++ )
F_137 ( V_283 -> V_36 [ V_273 ] , V_283 -> V_195 [ V_273 ] ,
V_283 -> V_25 , V_283 -> V_26 , V_262 ) ;
}
}
void F_147 ( struct V_284 * V_265 , unsigned long V_285 , int V_48 )
{
enum V_231 V_232 = F_105 () ;
if ( F_148 ( V_265 ) ) {
#ifdef F_149
if ( V_48 == - 2 )
F_150 ( V_286 , V_265 , V_287 , V_285 ) ;
else
#endif
F_150 ( V_288 , V_265 , V_289 , V_285 ) ;
} else
F_151 ( V_265 , V_285 , V_288 ) ;
F_124 ( V_232 ) ;
}
long F_152 ( unsigned long V_33 , unsigned long V_36 ,
unsigned long V_290 , unsigned long V_2 ,
unsigned long V_291 , int V_25 , int V_26 )
{
unsigned long V_292 ;
long V_268 ;
V_293:
V_292 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_268 = V_42 . V_43 ( V_292 , V_36 , V_290 , V_2 , V_291 ,
V_25 , V_25 , V_26 ) ;
if ( F_128 ( V_268 == - 1 ) ) {
V_292 = ( ( ~ V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_268 = V_42 . V_43 ( V_292 , V_36 , V_290 , V_2 ,
V_291 | V_294 ,
V_25 , V_25 , V_26 ) ;
if ( V_268 == - 1 ) {
if ( F_153 () & 0x1 )
V_292 = ( ( V_33 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_42 . V_295 ( V_292 ) ;
goto V_293;
}
}
return V_268 ;
}
static void F_154 ( unsigned long V_27 , unsigned long V_296 )
{
unsigned long V_33 ;
unsigned long V_35 = F_5 ( V_27 , V_120 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_120 ) ;
unsigned long V_297 = F_1 ( F_51 ( V_119 ) ) ;
long V_31 ;
V_33 = F_10 ( V_36 , V_45 , V_120 ) ;
if ( ! V_35 )
return;
V_31 = F_152 ( V_33 , V_36 , F_50 ( V_27 ) , V_297 ,
V_44 ,
V_100 , V_120 ) ;
F_11 ( V_31 < 0 ) ;
F_155 ( & V_298 ) ;
F_11 ( V_47 [ V_296 ] & 0x80 ) ;
V_47 [ V_296 ] = V_31 | 0x80 ;
F_156 ( & V_298 ) ;
}
static void F_157 ( unsigned long V_27 , unsigned long V_296 )
{
unsigned long V_33 , V_267 , V_268 ;
unsigned long V_35 = F_5 ( V_27 , V_120 ) ;
unsigned long V_36 = F_6 ( V_27 , V_35 , V_120 ) ;
V_33 = F_10 ( V_36 , V_45 , V_120 ) ;
F_155 ( & V_298 ) ;
F_11 ( ! ( V_47 [ V_296 ] & 0x80 ) ) ;
V_267 = V_47 [ V_296 ] & 0x7f ;
V_47 [ V_296 ] = 0 ;
F_156 ( & V_298 ) ;
if ( V_267 & V_269 )
V_33 = ~ V_33 ;
V_268 = ( V_33 & V_40 ) * V_41 ;
V_268 += V_267 & V_270 ;
V_42 . V_271 ( V_268 , V_36 , V_100 ,
V_100 ,
V_120 , 0 ) ;
}
void F_158 ( struct V_185 * V_185 , int V_299 , int V_300 )
{
unsigned long V_198 , V_27 , V_296 ;
int V_273 ;
F_130 ( V_198 ) ;
for ( V_273 = 0 ; V_273 < V_299 ; V_273 ++ , V_185 ++ ) {
V_27 = ( unsigned long ) F_159 ( V_185 ) ;
V_296 = F_50 ( V_27 ) >> V_45 ;
if ( V_296 >= V_46 )
continue;
if ( V_300 )
F_154 ( V_27 , V_296 ) ;
else
F_157 ( V_27 , V_296 ) ;
}
F_132 ( V_198 ) ;
}
void F_160 ( T_4 V_301 ,
T_4 V_302 )
{
F_11 ( V_301 != 0 ) ;
V_148 = F_161 ( T_6 , V_302 , 0x40000000 ) ;
F_70 ( V_148 ) ;
}
static int F_162 ( void * V_57 , T_6 * V_303 )
{
* V_303 = V_108 ;
return 0 ;
}
static int F_163 ( void * V_57 , T_6 V_303 )
{
if ( ! V_42 . V_115 )
return - V_50 ;
return V_42 . V_115 ( V_303 ) ;
}
static int T_1 F_164 ( void )
{
if ( ! F_165 ( L_54 , 0600 , V_304 ,
NULL , & V_305 ) ) {
F_22 ( L_55 ) ;
}
return 0 ;
}
