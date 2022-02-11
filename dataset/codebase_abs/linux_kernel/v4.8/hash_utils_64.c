unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = 0 ;
if ( ( V_1 & V_3 ) == 0 )
V_2 |= V_4 ;
if ( V_1 & V_5 ) {
if ( ! ( V_1 & V_6 ) )
V_2 |= ( V_7 | 0x2 ) ;
} else {
if ( V_1 & V_8 )
V_2 |= 0x2 ;
if ( ! ( ( V_1 & V_6 ) && ( V_1 & V_9 ) ) )
V_2 |= 0x1 ;
}
V_2 |= V_10 ;
if ( V_1 & V_9 )
V_2 |= V_11 ;
if ( ( V_1 & V_12 ) == V_13 )
V_2 |= V_14 ;
else if ( ( V_1 & V_12 ) == V_15 )
V_2 |= ( V_14 | V_16 ) ;
else if ( ( V_1 & V_12 ) == V_17 )
V_2 |= ( V_18 | V_14 | V_19 ) ;
else
V_2 |= V_19 ;
return V_2 ;
}
int F_2 ( unsigned long V_20 , unsigned long V_21 ,
unsigned long V_22 , unsigned long V_23 ,
int V_24 , int V_25 )
{
unsigned long V_26 , V_27 ;
unsigned int V_28 , V_29 ;
int V_30 = 0 ;
V_29 = V_31 [ V_24 ] . V_29 ;
V_28 = 1 << V_29 ;
V_23 = F_1 ( V_23 ) ;
F_3 ( L_1 ,
V_20 , V_21 , V_22 , V_23 , V_24 , V_25 ) ;
for ( V_26 = V_20 , V_27 = V_22 ; V_26 < V_21 ;
V_26 += V_28 , V_27 += V_28 ) {
unsigned long V_32 , V_33 ;
unsigned long V_34 = F_4 ( V_26 , V_25 ) ;
unsigned long V_35 = F_5 ( V_26 , V_34 , V_25 ) ;
unsigned long V_36 = V_23 ;
if ( ! V_34 )
return - 1 ;
if ( F_6 ( V_26 , V_26 + V_28 ) )
V_36 &= ~ V_4 ;
if ( F_7 ( V_26 , V_26 + V_28 ) )
V_36 &= ~ V_4 ;
if ( ( V_37 > V_38 ) &&
F_8 ( V_26 , V_26 + V_28 ) )
V_36 &= ~ V_4 ;
V_32 = F_9 ( V_35 , V_29 , V_25 ) ;
V_33 = ( ( V_32 & V_39 ) * V_40 ) ;
F_10 ( ! V_41 . V_42 ) ;
V_30 = V_41 . V_42 ( V_33 , V_35 , V_27 , V_36 ,
V_43 , V_24 , V_24 ,
V_25 ) ;
if ( V_30 < 0 )
break;
#ifdef F_11
if ( F_12 () &&
( V_27 >> V_44 ) < V_45 )
V_46 [ V_27 >> V_44 ] = V_30 | 0x80 ;
#endif
}
return V_30 < 0 ? V_30 : 0 ;
}
int F_13 ( unsigned long V_20 , unsigned long V_21 ,
int V_24 , int V_25 )
{
unsigned long V_26 ;
unsigned int V_28 , V_29 ;
int V_47 ;
int V_30 = 0 ;
V_29 = V_31 [ V_24 ] . V_29 ;
V_28 = 1 << V_29 ;
if ( ! V_41 . V_48 )
return - V_49 ;
for ( V_26 = V_20 ; V_26 < V_21 ; V_26 += V_28 ) {
V_47 = V_41 . V_48 ( V_26 , V_24 , V_25 ) ;
if ( V_47 == - V_50 ) {
V_30 = - V_50 ;
continue;
}
if ( V_47 < 0 )
return V_47 ;
}
return V_30 ;
}
static int T_1 F_14 ( char * V_51 )
{
V_52 = true ;
return 0 ;
}
static int T_1 F_15 ( unsigned long V_53 ,
const char * V_54 , int V_55 ,
void * V_56 )
{
const char * type = F_16 ( V_53 , L_2 , NULL ) ;
const T_2 * V_57 ;
int V_58 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_57 = F_16 ( V_53 , L_4 , & V_58 ) ;
if ( V_57 == NULL )
return 0 ;
for (; V_58 >= 4 ; V_58 -= 4 , ++ V_57 ) {
if ( F_17 ( V_57 [ 0 ] ) == 40 ) {
F_3 ( L_5 ) ;
if ( V_52 ) {
F_3 ( L_6 ) ;
break;
}
V_59 -> V_60 |= V_61 ;
return 1 ;
}
}
V_59 -> V_60 &= ~ V_62 ;
return 0 ;
}
static int T_1 F_18 ( unsigned int V_29 )
{
int V_63 = - 1 ;
switch ( V_29 ) {
case 0xc :
V_63 = V_64 ;
break;
case 0x10 :
V_63 = V_65 ;
break;
case 0x14 :
V_63 = V_66 ;
break;
case 0x18 :
V_63 = V_67 ;
break;
case 0x22 :
V_63 = V_68 ;
break;
}
return V_63 ;
}
static int T_1 F_19 ( unsigned long V_53 ,
const char * V_54 , int V_55 ,
void * V_56 )
{
const char * type = F_16 ( V_53 , L_2 , NULL ) ;
const T_2 * V_57 ;
int V_58 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_57 = F_16 ( V_53 , L_7 , & V_58 ) ;
if ( ! V_57 )
return 0 ;
F_20 ( L_8 ) ;
V_58 /= 4 ;
V_59 -> V_60 &= ~ ( V_69 ) ;
while( V_58 > 0 ) {
unsigned int V_70 = F_17 ( V_57 [ 0 ] ) ;
unsigned int V_71 = F_17 ( V_57 [ 1 ] ) ;
unsigned int V_72 = F_17 ( V_57 [ 2 ] ) ;
struct V_73 * V_74 ;
int V_63 , V_75 ;
V_58 -= 3 ; V_57 += 3 ;
V_75 = F_18 ( V_70 ) ;
if ( V_75 < 0 ) {
V_57 += V_72 * 2 ; V_58 -= V_72 * 2 ;
continue;
}
V_74 = & V_31 [ V_75 ] ;
if ( V_75 == V_67 )
V_59 -> V_60 |= V_69 ;
V_74 -> V_29 = V_70 ;
if ( V_70 <= 23 )
V_74 -> V_76 = 0 ;
else
V_74 -> V_76 = ( 1 << ( V_70 - 23 ) ) - 1 ;
V_74 -> V_77 = V_71 ;
if ( V_75 == V_64 || V_75 == V_65 )
V_74 -> V_78 = 1 ;
else
V_74 -> V_78 = 0 ;
while ( V_58 > 0 && V_72 ) {
unsigned int V_29 = F_17 ( V_57 [ 0 ] ) ;
int V_79 = F_17 ( V_57 [ 1 ] ) ;
V_57 += 2 ; V_58 -= 2 ;
V_72 -- ;
V_63 = F_18 ( V_29 ) ;
if ( V_63 < 0 )
continue;
if ( V_79 == - 1 )
F_21 ( L_9
L_10 , V_70 , V_29 ) ;
V_74 -> V_79 [ V_63 ] = V_79 ;
F_20 ( L_11
L_12 ,
V_70 , V_29 , V_74 -> V_77 ,
V_74 -> V_76 , V_74 -> V_78 , V_74 -> V_79 [ V_63 ] ) ;
}
}
return 1 ;
}
static int T_1 F_22 ( unsigned long V_53 ,
const char * V_54 , int V_55 ,
void * V_56 ) {
const char * type = F_16 ( V_53 , L_2 , NULL ) ;
const T_3 * V_80 ;
const T_2 * V_81 ;
unsigned int V_82 ;
long unsigned int V_83 ;
long unsigned int V_84 ;
if ( type == NULL || strcmp ( type , L_13 ) != 0 )
return 0 ;
V_81 = F_16 ( V_53 , L_14 , NULL ) ;
if ( V_81 == NULL )
return 0 ;
V_82 = ( 1 << F_17 ( V_81 [ 0 ] ) ) ;
V_80 = F_16 ( V_53 , L_15 , NULL ) ;
if ( V_80 == NULL )
return 0 ;
V_83 = F_23 ( V_80 [ 0 ] ) ;
V_84 = F_23 ( V_80 [ 1 ] ) ;
if ( V_84 != ( 16 * V_85 ) )
return 0 ;
F_24 ( V_86 L_16
L_17 ,
V_83 , V_84 , V_82 ) ;
if ( V_83 + ( 16 * V_85 ) <= F_25 () ) {
F_26 ( V_83 , V_84 * V_82 ) ;
F_27 ( V_83 , V_84 , V_82 ) ;
}
return 0 ;
}
static void F_28 ( void )
{
int V_87 , V_88 ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ )
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ )
V_31 [ V_87 ] . V_79 [ V_88 ] = - 1 ;
}
static bool F_29 ( void )
{
#ifdef F_30
return ! F_31 ( V_90 ) &&
! F_32 ( V_91 ) ;
#else
return false ;
#endif
}
static void T_1 F_33 ( void )
{
int V_47 ;
F_28 () ;
memcpy ( V_31 , V_92 ,
sizeof( V_92 ) ) ;
V_47 = F_34 ( F_19 , NULL ) ;
if ( V_47 == 0 && F_35 ( V_69 ) ) {
memcpy ( V_31 , V_93 ,
sizeof( V_93 ) ) ;
}
#ifdef F_36
F_34 ( F_22 , NULL ) ;
#endif
}
static void T_1 F_37 ( void )
{
if ( ! F_12 () ) {
if ( V_31 [ V_67 ] . V_29 )
V_94 = V_67 ;
else if ( V_31 [ V_66 ] . V_29 )
V_94 = V_66 ;
}
#ifdef F_38
if ( V_31 [ V_65 ] . V_29 ) {
V_95 = V_65 ;
V_96 = V_65 ;
if ( V_94 == V_64 )
V_94 = V_65 ;
if ( F_39 ( V_97 ) ) {
if ( ! F_29 () )
V_98 = V_65 ;
} else
V_99 = 1 ;
}
#endif
#ifdef F_40
if ( V_31 [ V_67 ] . V_29 &&
F_41 () >= 0x40000000 )
V_100 = V_67 ;
else if ( V_31 [ V_65 ] . V_29 )
V_100 = V_65 ;
else
V_100 = V_64 ;
#endif
F_24 ( V_101 L_18
L_19
#ifdef F_40
L_20
#endif
L_21 ,
V_31 [ V_94 ] . V_29 ,
V_31 [ V_95 ] . V_29 ,
V_31 [ V_98 ] . V_29
#ifdef F_40
, V_31 [ V_100 ] . V_29
#endif
) ;
}
static int T_1 F_42 ( unsigned long V_53 ,
const char * V_54 , int V_55 ,
void * V_56 )
{
const char * type = F_16 ( V_53 , L_2 , NULL ) ;
const T_2 * V_57 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_57 = F_16 ( V_53 , L_22 , NULL ) ;
if ( V_57 != NULL ) {
V_102 = F_17 ( V_57 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
unsigned F_43 ( unsigned long V_103 )
{
unsigned V_104 = F_44 ( V_103 ) ;
unsigned V_105 = V_31 [ V_95 ] . V_29 ;
unsigned V_106 ;
if ( ( 1UL << V_104 ) < V_103 )
V_104 += 1 ;
V_106 = V_104 - ( V_105 + 1 ) ;
return F_45 ( V_106 + 7 , 18U ) ;
}
static unsigned long T_1 F_46 ( void )
{
if ( V_102 == 0 )
F_34 ( F_42 , NULL ) ;
if ( V_102 )
return 1UL << V_102 ;
return 1UL << F_43 ( F_41 () ) ;
}
int F_47 ( unsigned long V_107 , unsigned long V_108 )
{
int V_47 = F_2 ( V_107 , V_108 , F_48 ( V_107 ) ,
F_49 ( V_109 ) , V_94 ,
V_110 ) ;
if ( V_47 < 0 ) {
int V_111 = F_13 ( V_107 , V_108 , V_94 ,
V_110 ) ;
F_10 ( V_111 && ( V_111 != - V_50 ) ) ;
}
return V_47 ;
}
int F_50 ( unsigned long V_107 , unsigned long V_108 )
{
int V_47 = F_13 ( V_107 , V_108 , V_94 ,
V_110 ) ;
F_51 ( V_47 < 0 ) ;
return V_47 ;
}
static void T_1 F_52 ( T_4 V_112 ,
unsigned long V_113 )
{
unsigned long V_114 ;
unsigned long V_115 = 1UL << V_116 ;
V_114 = 0 ;
V_113 = F_44 ( V_113 ) - 18 ;
F_53 ( ( V_116 > 24 ) , L_23 ) ;
V_117 = F_54 ( F_55 ( V_115 , V_115 ,
V_118 ) ) ;
memset ( ( void * ) V_117 , 0 , V_115 ) ;
V_117 -> V_119 = F_56 ( V_114 | V_112 | V_113 ) ;
V_117 -> V_120 = 0 ;
F_20 ( L_24 , V_117 ) ;
F_57 ( V_121 , F_48 ( V_117 ) | ( V_116 - 12 ) ) ;
}
static void T_1 F_58 ( void )
{
unsigned long V_122 ;
unsigned long V_123 ;
unsigned long V_23 ;
unsigned long V_124 = 0 , V_58 = 0 ;
struct V_125 * V_126 ;
F_3 ( L_25 ) ;
if ( F_39 ( V_61 ) ) {
V_110 = V_127 ;
V_128 = V_127 ;
F_24 ( V_86 L_26 ) ;
}
V_129 = F_46 () ;
V_123 = V_129 >> 7 ;
V_39 = V_123 - 1 ;
if ( F_32 ( V_130 ) ||
F_32 ( V_131 ) ) {
V_132 = NULL ;
V_133 = 0 ;
#ifdef F_59
if ( F_60 () && V_41 . V_134 )
V_41 . V_134 () ;
#endif
} else {
unsigned long V_135 = V_118 ;
#ifdef F_61
if ( F_62 ( V_136 , 0 , L_27 ) > 0 ) {
V_135 = 0x80000000 ;
F_20 ( L_28 ) ;
}
#endif
V_122 = F_55 ( V_129 , V_129 ,
V_135 ) ;
F_3 ( L_29 , V_122 ,
V_129 ) ;
V_132 = F_54 ( V_122 ) ;
V_133 = V_122 + F_44 ( V_129 ) - 18 ;
memset ( ( void * ) V_122 , 0 , V_129 ) ;
if ( ! F_31 ( V_137 ) )
F_57 ( V_138 , V_133 ) ;
else
F_52 ( V_122 , V_129 ) ;
}
V_23 = F_49 ( V_109 ) ;
#ifdef F_11
if ( F_12 () ) {
V_45 = F_25 () >> V_44 ;
V_46 = F_54 ( F_55 (
V_45 , 1 , V_139 ) ) ;
memset ( V_46 , 0 , V_45 ) ;
}
#endif
F_63 (memory, reg) {
V_124 = ( unsigned long ) F_54 ( V_126 -> V_124 ) ;
V_58 = V_126 -> V_58 ;
F_3 ( L_30 ,
V_124 , V_58 , V_23 ) ;
F_10 ( F_2 ( V_124 , V_124 + V_58 , F_48 ( V_124 ) ,
V_23 , V_94 , V_110 ) ) ;
}
F_64 ( V_118 ) ;
if ( V_140 ) {
V_140 = ( unsigned long ) F_54 ( V_140 ) ;
V_141 = ( unsigned long ) F_54 ( V_141 ) ;
if ( V_124 + V_58 >= V_140 )
V_140 = V_124 + V_58 + 1 ;
F_10 ( F_2 ( V_140 , V_141 ,
F_48 ( V_140 ) , V_23 ,
V_94 , V_110 ) ) ;
}
F_3 ( L_31 ) ;
}
void T_1 F_65 ( void )
{
F_34 ( F_15 , NULL ) ;
F_33 () ;
}
void T_1 F_66 ( void )
{
F_37 () ;
V_142 = V_143 ;
V_144 = V_145 ;
V_146 = V_147 ;
V_148 = V_149 ;
V_150 = V_151 ;
V_152 = V_153 ;
V_154 = V_155 ;
V_156 = V_157 ;
V_158 = V_159 ;
V_160 = V_161 ;
V_162 = V_163 ;
V_164 = 0 ;
V_165 = 0 ;
V_166 = 0 ;
V_167 = V_168 ;
V_169 = V_170 ;
V_171 = V_172 ;
V_173 = V_174 ;
V_175 = (struct V_176 * ) V_177 ;
V_178 = V_179 ;
#ifdef F_67
V_180 = V_181 ;
#endif
if ( F_32 ( V_131 ) )
F_68 () ;
else if ( F_32 ( V_130 ) )
F_69 () ;
else if ( F_70 ( V_182 ) )
F_71 () ;
if ( ! V_41 . V_42 )
F_72 ( L_32 ) ;
F_58 () ;
F_20 ( L_33 ) ;
F_73 () ;
}
void F_74 ( void )
{
if ( ! F_32 ( V_130 ) ) {
if ( ! F_31 ( V_137 ) )
F_57 ( V_138 , V_133 ) ;
else
F_57 ( V_121 ,
F_48 ( V_117 ) | ( V_116 - 12 ) ) ;
}
F_73 () ;
}
unsigned int F_75 ( unsigned int V_183 , T_5 V_184 , int V_185 )
{
struct V_176 * V_176 ;
if ( ! F_76 ( F_77 ( V_184 ) ) )
return V_183 ;
V_176 = F_78 ( V_184 ) ;
if ( ! F_79 ( V_186 , & V_176 -> V_187 ) && ! F_80 ( V_176 ) ) {
if ( V_185 == 0x400 ) {
F_81 ( V_176 ) ;
F_82 ( V_186 , & V_176 -> V_187 ) ;
} else
V_183 |= V_4 ;
}
return V_183 ;
}
static unsigned int F_83 ( unsigned long V_188 )
{
T_6 V_189 ;
unsigned char * V_190 ;
unsigned long V_191 , V_192 ;
if ( V_188 < V_193 ) {
V_189 = F_84 () -> V_194 ;
V_191 = F_85 ( V_188 ) ;
return ( V_189 >> ( V_191 * 4 ) ) & 0xF ;
}
V_190 = F_84 () -> V_195 ;
V_191 = F_86 ( V_188 ) ;
V_192 = V_191 & 0x1 ;
return ( V_190 [ V_191 >> 1 ] >> ( V_192 * 4 ) ) & 0xF ;
}
unsigned int F_83 ( unsigned long V_188 )
{
return F_84 () -> V_196 ;
}
void F_87 ( struct V_197 * V_198 , unsigned long V_188 )
{
if ( F_88 ( V_198 , V_188 ) == V_64 )
return;
F_89 ( V_198 , V_188 , 1 , V_64 ) ;
F_90 ( V_198 ) ;
if ( ( F_83 ( V_188 ) != V_64 ) && ( V_199 -> V_198 == V_198 ) ) {
F_91 ( & V_198 -> V_200 ) ;
F_92 () ;
}
}
static int F_93 ( struct V_197 * V_198 , unsigned long V_201 )
{
struct V_202 * V_203 = & V_198 -> V_200 . V_203 ;
T_7 V_204 = 0 ;
T_7 * * V_205 , * V_206 ;
if ( V_201 >= V_203 -> V_207 )
return 0 ;
if ( V_201 < 0x100000000UL ) {
V_205 = V_203 -> V_208 ;
} else {
V_205 = V_203 -> V_209 [ V_201 >> V_210 ] ;
if ( ! V_205 )
return 0 ;
}
V_206 = V_205 [ ( V_201 >> V_211 ) & ( V_212 - 1 ) ] ;
if ( ! V_206 )
return 0 ;
V_204 = V_206 [ ( V_201 >> V_44 ) & ( V_213 - 1 ) ] ;
V_204 >>= 30 - 2 * ( ( V_201 >> 12 ) & 0xf ) ;
V_204 = ( ( V_204 & 2 ) ? V_8 : 0 ) | ( ( V_204 & 1 ) ? V_6 : 0 ) ;
return V_204 ;
}
static inline int F_93 ( struct V_197 * V_198 , unsigned long V_201 )
{
return 0 ;
}
void F_94 ( unsigned long V_201 , unsigned long V_214 ,
unsigned long V_34 , unsigned long V_185 ,
int V_25 , int V_24 , int V_215 , unsigned long V_184 )
{
if ( ! F_95 () )
return;
F_20 ( L_34 ,
V_201 , V_214 , V_199 -> V_216 ) ;
F_20 ( L_35 ,
V_185 , V_34 , V_25 , V_24 , V_215 , V_184 ) ;
}
static void F_96 ( unsigned long V_201 , struct V_197 * V_198 ,
int V_24 , bool V_217 )
{
if ( V_217 ) {
if ( V_24 != F_83 ( V_201 ) ) {
F_91 ( & V_198 -> V_200 ) ;
F_92 () ;
}
} else if ( F_84 () -> V_218 !=
V_31 [ V_96 ] . V_77 ) {
F_84 () -> V_218 =
V_31 [ V_96 ] . V_77 ;
F_97 () ;
}
}
int F_98 ( struct V_197 * V_198 , unsigned long V_201 ,
unsigned long V_214 , unsigned long V_185 ,
unsigned long V_187 )
{
bool V_219 ;
enum V_220 V_221 = F_99 () ;
T_8 * V_222 ;
unsigned long V_34 ;
T_5 * V_223 ;
unsigned V_224 ;
const struct V_225 * V_226 ;
int V_47 , V_217 = 0 ;
int V_24 , V_25 ;
F_100 ( L_36 ,
V_201 , V_214 , V_185 ) ;
F_101 ( V_201 , V_214 , V_185 ) ;
switch ( F_102 ( V_201 ) ) {
case V_227 :
V_217 = 1 ;
if ( ! V_198 ) {
F_100 ( L_37 ) ;
V_47 = 1 ;
goto V_228;
}
V_24 = F_88 ( V_198 , V_201 ) ;
V_25 = F_103 ( V_201 ) ;
V_34 = F_104 ( V_198 -> V_200 . V_229 , V_201 , V_25 ) ;
break;
case V_230 :
V_34 = F_4 ( V_201 , V_110 ) ;
if ( V_201 < V_231 )
V_24 = V_96 ;
else
V_24 = V_98 ;
V_25 = V_110 ;
break;
default:
V_47 = 1 ;
goto V_228;
}
F_100 ( L_38 , V_198 , V_198 -> V_232 , V_34 ) ;
if ( ! V_34 ) {
F_100 ( L_39 ) ;
V_47 = 1 ;
goto V_228;
}
V_222 = V_198 -> V_232 ;
if ( V_222 == NULL ) {
V_47 = 1 ;
goto V_228;
}
V_226 = F_105 ( F_106 () ) ;
if ( V_217 && F_107 ( F_108 ( V_198 ) , V_226 ) )
V_187 |= V_233 ;
#ifndef F_38
if ( V_24 != V_64 )
V_201 &= ~ ( ( 1ul << V_31 [ V_24 ] . V_29 ) - 1 ) ;
#endif
V_223 = F_109 ( V_222 , V_201 , & V_219 , & V_224 ) ;
if ( V_223 == NULL || ! F_110 ( * V_223 ) ) {
F_100 ( L_40 ) ;
V_47 = 1 ;
goto V_228;
}
V_214 |= V_234 ;
if ( ! F_111 ( V_214 , F_112 ( * V_223 ) ) ) {
F_100 ( L_41 ) ;
V_47 = 1 ;
goto V_228;
}
if ( V_224 ) {
if ( V_219 )
V_47 = F_113 ( V_201 , V_214 , V_34 , ( V_235 * ) V_223 ,
V_185 , V_187 , V_25 , V_24 ) ;
#ifdef F_36
else
V_47 = F_114 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_187 , V_25 , V_224 , V_24 ) ;
#else
else {
V_47 = 1 ;
F_51 ( 1 ) ;
}
#endif
if ( V_199 -> V_198 == V_198 )
F_96 ( V_201 , V_198 , V_24 , V_217 ) ;
goto V_228;
}
#ifndef F_38
F_100 ( L_42 , F_112 ( * V_223 ) ) ;
#else
F_100 ( L_43 , F_112 ( * V_223 ) ,
F_112 ( * ( V_223 + V_236 ) ) ) ;
#endif
#ifdef F_38
if ( ( F_112 ( * V_223 ) & V_237 ) && V_24 == V_65 ) {
F_87 ( V_198 , V_201 ) ;
V_24 = V_64 ;
}
if ( V_99 && V_24 == V_65 && F_115 ( * V_223 ) ) {
if ( V_217 ) {
F_87 ( V_198 , V_201 ) ;
V_24 = V_64 ;
} else if ( V_201 < V_231 ) {
F_24 ( V_238 L_44
L_45
L_46 ) ;
V_24 = V_96 = V_64 ;
F_90 ( V_198 ) ;
}
}
#endif
if ( V_199 -> V_198 == V_198 )
F_96 ( V_201 , V_198 , V_24 , V_217 ) ;
#ifdef F_38
if ( V_24 == V_65 )
V_47 = F_116 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_187 , V_25 ) ;
else
#endif
{
int V_204 = F_93 ( V_198 , V_201 ) ;
if ( V_214 & V_204 )
V_47 = - 2 ;
else
V_47 = F_117 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_187 , V_25 , V_204 ) ;
}
if ( V_47 == - 1 )
F_94 ( V_201 , V_214 , V_34 , V_185 , V_25 , V_24 ,
V_24 , F_112 ( * V_223 ) ) ;
#ifndef F_38
F_100 ( L_47 , F_112 ( * V_223 ) ) ;
#else
F_100 ( L_48 , F_112 ( * V_223 ) ,
F_112 ( * ( V_223 + V_236 ) ) ) ;
#endif
F_100 ( L_49 , V_47 ) ;
V_228:
F_118 ( V_221 ) ;
return V_47 ;
}
int F_119 ( unsigned long V_201 , unsigned long V_214 , unsigned long V_185 ,
unsigned long V_239 )
{
unsigned long V_187 = 0 ;
struct V_197 * V_198 = V_199 -> V_198 ;
if ( F_102 ( V_201 ) == V_230 )
V_198 = & V_240 ;
if ( V_239 & V_241 )
V_187 |= V_242 ;
return F_98 ( V_198 , V_201 , V_214 , V_185 , V_187 ) ;
}
int F_120 ( unsigned long V_201 , unsigned long V_243 , unsigned long V_185 ,
unsigned long V_239 )
{
unsigned long V_214 = V_234 | V_244 ;
unsigned long V_187 = 0 ;
struct V_197 * V_198 = V_199 -> V_198 ;
if ( F_102 ( V_201 ) == V_230 )
V_198 = & V_240 ;
if ( V_239 & V_241 )
V_187 |= V_242 ;
if ( V_239 & V_245 )
V_214 |= V_6 ;
V_214 |= V_5 ;
if ( ( V_243 & V_246 ) || ( F_102 ( V_201 ) == V_227 ) )
V_214 &= ~ V_5 ;
if ( V_185 == 0x400 )
V_214 |= V_3 ;
return F_98 ( V_198 , V_201 , V_214 , V_185 , V_187 ) ;
}
static bool F_121 ( struct V_197 * V_198 , unsigned long V_201 )
{
int V_24 = F_88 ( V_198 , V_201 ) ;
if ( F_122 ( V_24 != V_198 -> V_200 . V_247 ) )
return false ;
if ( F_122 ( ( V_24 == V_64 ) && F_93 ( V_198 , V_201 ) ) )
return false ;
return true ;
}
static bool F_121 ( struct V_197 * V_198 , unsigned long V_201 )
{
return true ;
}
void F_123 ( struct V_197 * V_198 , unsigned long V_201 ,
unsigned long V_214 , unsigned long V_185 )
{
int V_248 ;
unsigned long V_34 ;
T_8 * V_222 ;
T_5 * V_223 ;
unsigned long V_187 ;
int V_47 , V_25 , V_249 = 0 ;
F_10 ( F_102 ( V_201 ) != V_227 ) ;
if ( ! F_121 ( V_198 , V_201 ) )
return;
F_100 ( L_50
L_51 , V_198 , V_198 -> V_232 , V_201 , V_214 , V_185 ) ;
V_222 = V_198 -> V_232 ;
if ( V_222 == NULL )
return;
V_25 = F_103 ( V_201 ) ;
V_34 = F_104 ( V_198 -> V_200 . V_229 , V_201 , V_25 ) ;
if ( ! V_34 )
return;
F_124 ( V_187 ) ;
V_223 = F_125 ( V_222 , V_201 , NULL , & V_248 ) ;
if ( ! V_223 )
goto V_250;
F_51 ( V_248 ) ;
#ifdef F_38
if ( ( F_112 ( * V_223 ) & V_237 ) || F_115 ( * V_223 ) )
goto V_250;
#endif
if ( F_107 ( F_108 ( V_198 ) , F_105 ( F_106 () ) ) )
V_249 |= V_233 ;
#ifdef F_38
if ( V_198 -> V_200 . V_247 == V_65 )
V_47 = F_116 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_249 , V_25 ) ;
else
#endif
V_47 = F_117 ( V_201 , V_214 , V_34 , V_223 , V_185 , V_249 ,
V_25 , F_93 ( V_198 , V_201 ) ) ;
if ( V_47 == - 1 )
F_94 ( V_201 , V_214 , V_34 , V_185 , V_25 ,
V_198 -> V_200 . V_247 ,
V_198 -> V_200 . V_247 ,
F_112 ( * V_223 ) ) ;
V_250:
F_126 ( V_187 ) ;
}
void F_127 ( unsigned long V_35 , T_9 V_184 , int V_24 , int V_25 ,
unsigned long V_187 )
{
unsigned long V_32 , V_191 , V_29 , V_251 , V_252 ;
int V_253 = V_187 & V_233 ;
F_100 ( L_52 , V_35 ) ;
F_128 (pte, psize, vpn, index, shift) {
V_32 = F_9 ( V_35 , V_29 , V_25 ) ;
V_251 = F_129 ( V_184 , V_191 ) ;
if ( V_251 & V_254 )
V_32 = ~ V_32 ;
V_252 = ( V_32 & V_39 ) * V_40 ;
V_252 += V_251 & V_255 ;
F_100 ( L_53 , V_191 , V_252 , V_251 ) ;
V_41 . V_256 ( V_252 , V_35 , V_24 , V_24 ,
V_25 , V_253 ) ;
} F_130 () ;
#ifdef F_131
if ( V_253 && F_31 ( V_257 ) &&
V_199 -> V_258 . V_259 &&
F_132 ( V_199 -> V_258 . V_259 -> V_243 ) ) {
F_133 () ;
F_134 ( V_260 ) ;
}
#endif
}
void F_135 ( unsigned long V_34 , unsigned long V_188 ,
V_235 * V_261 , unsigned int V_24 , int V_25 ,
unsigned long V_187 )
{
int V_262 , V_263 , V_264 ;
unsigned long V_265 ;
unsigned char * V_266 ;
unsigned long V_251 , V_29 , V_35 , V_32 , V_252 ;
int V_253 = V_187 & V_233 ;
V_265 = V_188 & V_267 ;
V_266 = F_136 ( V_261 ) ;
if ( ! V_266 )
return;
if ( V_41 . V_268 ) {
V_41 . V_268 ( V_34 , V_265 , V_266 ,
V_24 , V_25 , V_253 ) ;
goto F_134;
}
V_29 = V_31 [ V_24 ] . V_29 ;
V_263 = V_269 >> V_29 ;
for ( V_262 = 0 ; V_262 < V_263 ; V_262 ++ ) {
V_264 = F_137 ( V_266 , V_262 ) ;
if ( ! V_264 )
continue;
V_251 = F_138 ( V_266 , V_262 ) ;
V_188 = V_265 + ( V_262 * ( 1ul << V_29 ) ) ;
V_35 = F_5 ( V_188 , V_34 , V_25 ) ;
V_32 = F_9 ( V_35 , V_29 , V_25 ) ;
if ( V_251 & V_254 )
V_32 = ~ V_32 ;
V_252 = ( V_32 & V_39 ) * V_40 ;
V_252 += V_251 & V_255 ;
V_41 . V_256 ( V_252 , V_35 , V_24 ,
V_67 , V_25 , V_253 ) ;
}
F_134:
#ifdef F_131
if ( V_253 && F_31 ( V_257 ) &&
V_199 -> V_258 . V_259 &&
F_132 ( V_199 -> V_258 . V_259 -> V_243 ) ) {
F_133 () ;
F_134 ( V_260 ) ;
}
#endif
return;
}
void F_139 ( unsigned long V_270 , int V_253 )
{
if ( V_41 . F_139 )
V_41 . F_139 ( V_270 , V_253 ) ;
else {
int V_262 ;
struct V_271 * V_272 =
F_140 ( & V_271 ) ;
for ( V_262 = 0 ; V_262 < V_270 ; V_262 ++ )
F_127 ( V_272 -> V_35 [ V_262 ] , V_272 -> V_184 [ V_262 ] ,
V_272 -> V_24 , V_272 -> V_25 , V_253 ) ;
}
}
void F_141 ( struct V_273 * V_259 , unsigned long V_274 , int V_47 )
{
enum V_220 V_221 = F_99 () ;
if ( F_142 ( V_259 ) ) {
#ifdef F_143
if ( V_47 == - 2 )
F_144 ( V_275 , V_259 , V_276 , V_274 ) ;
else
#endif
F_144 ( V_277 , V_259 , V_278 , V_274 ) ;
} else
F_145 ( V_259 , V_274 , V_277 ) ;
F_118 ( V_221 ) ;
}
long F_146 ( unsigned long V_32 , unsigned long V_35 ,
unsigned long V_279 , unsigned long V_2 ,
unsigned long V_280 , int V_24 , int V_25 )
{
unsigned long V_281 ;
long V_252 ;
V_282:
V_281 = ( ( V_32 & V_39 ) *
V_40 ) & ~ 0x7UL ;
V_252 = V_41 . V_42 ( V_281 , V_35 , V_279 , V_2 , V_280 ,
V_24 , V_24 , V_25 ) ;
if ( F_122 ( V_252 == - 1 ) ) {
V_281 = ( ( ~ V_32 & V_39 ) *
V_40 ) & ~ 0x7UL ;
V_252 = V_41 . V_42 ( V_281 , V_35 , V_279 , V_2 ,
V_280 | V_283 ,
V_24 , V_24 , V_25 ) ;
if ( V_252 == - 1 ) {
if ( F_147 () & 0x1 )
V_281 = ( ( V_32 & V_39 ) *
V_40 ) & ~ 0x7UL ;
V_41 . V_284 ( V_281 ) ;
goto V_282;
}
}
return V_252 ;
}
static void F_148 ( unsigned long V_26 , unsigned long V_285 )
{
unsigned long V_32 ;
unsigned long V_34 = F_4 ( V_26 , V_110 ) ;
unsigned long V_35 = F_5 ( V_26 , V_34 , V_110 ) ;
unsigned long V_286 = F_1 ( F_49 ( V_109 ) ) ;
long V_30 ;
V_32 = F_9 ( V_35 , V_44 , V_110 ) ;
if ( ! V_34 )
return;
V_30 = F_146 ( V_32 , V_35 , F_48 ( V_26 ) , V_286 ,
V_43 ,
V_94 , V_110 ) ;
F_10 ( V_30 < 0 ) ;
F_149 ( & V_287 ) ;
F_10 ( V_46 [ V_285 ] & 0x80 ) ;
V_46 [ V_285 ] = V_30 | 0x80 ;
F_150 ( & V_287 ) ;
}
static void F_151 ( unsigned long V_26 , unsigned long V_285 )
{
unsigned long V_32 , V_251 , V_252 ;
unsigned long V_34 = F_4 ( V_26 , V_110 ) ;
unsigned long V_35 = F_5 ( V_26 , V_34 , V_110 ) ;
V_32 = F_9 ( V_35 , V_44 , V_110 ) ;
F_149 ( & V_287 ) ;
F_10 ( ! ( V_46 [ V_285 ] & 0x80 ) ) ;
V_251 = V_46 [ V_285 ] & 0x7f ;
V_46 [ V_285 ] = 0 ;
F_150 ( & V_287 ) ;
if ( V_251 & V_254 )
V_32 = ~ V_32 ;
V_252 = ( V_32 & V_39 ) * V_40 ;
V_252 += V_251 & V_255 ;
V_41 . V_256 ( V_252 , V_35 , V_94 ,
V_94 ,
V_110 , 0 ) ;
}
void F_152 ( struct V_176 * V_176 , int V_288 , int V_289 )
{
unsigned long V_187 , V_26 , V_285 ;
int V_262 ;
F_124 ( V_187 ) ;
for ( V_262 = 0 ; V_262 < V_288 ; V_262 ++ , V_176 ++ ) {
V_26 = ( unsigned long ) F_153 ( V_176 ) ;
V_285 = F_48 ( V_26 ) >> V_44 ;
if ( V_285 >= V_45 )
continue;
if ( V_289 )
F_148 ( V_26 , V_285 ) ;
else
F_151 ( V_26 , V_285 ) ;
}
F_126 ( V_187 ) ;
}
void F_154 ( T_4 V_290 ,
T_4 V_291 )
{
F_10 ( V_290 != 0 ) ;
V_139 = F_155 ( T_6 , V_291 , 0x40000000 ) ;
F_64 ( V_139 ) ;
}
