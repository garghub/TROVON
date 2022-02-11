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
V_43 , V_24 , V_24 , V_25 ) ;
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
static int T_1 F_14 ( unsigned long V_51 ,
const char * V_52 , int V_53 ,
void * V_54 )
{
const char * type = F_15 ( V_51 , L_2 , NULL ) ;
const T_2 * V_55 ;
int V_56 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_55 = F_15 ( V_51 , L_4 , & V_56 ) ;
if ( V_55 == NULL )
return 0 ;
for (; V_56 >= 4 ; V_56 -= 4 , ++ V_55 ) {
if ( F_16 ( V_55 [ 0 ] ) == 40 ) {
F_3 ( L_5 ) ;
V_57 -> V_58 |= V_59 ;
return 1 ;
}
}
V_57 -> V_58 &= ~ V_60 ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 ( F_14 , NULL ) ;
}
static int T_1 F_19 ( unsigned int V_29 )
{
int V_61 = - 1 ;
switch ( V_29 ) {
case 0xc :
V_61 = V_62 ;
break;
case 0x10 :
V_61 = V_63 ;
break;
case 0x14 :
V_61 = V_64 ;
break;
case 0x18 :
V_61 = V_65 ;
break;
case 0x22 :
V_61 = V_66 ;
break;
}
return V_61 ;
}
static int T_1 F_20 ( unsigned long V_51 ,
const char * V_52 , int V_53 ,
void * V_54 )
{
const char * type = F_15 ( V_51 , L_2 , NULL ) ;
const T_2 * V_55 ;
int V_56 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_55 = F_15 ( V_51 , L_6 , & V_56 ) ;
if ( ! V_55 )
return 0 ;
F_21 ( L_7 ) ;
V_56 /= 4 ;
V_57 -> V_58 &= ~ ( V_67 ) ;
while( V_56 > 0 ) {
unsigned int V_68 = F_16 ( V_55 [ 0 ] ) ;
unsigned int V_69 = F_16 ( V_55 [ 1 ] ) ;
unsigned int V_70 = F_16 ( V_55 [ 2 ] ) ;
struct V_71 * V_72 ;
int V_61 , V_73 ;
V_56 -= 3 ; V_55 += 3 ;
V_73 = F_19 ( V_68 ) ;
if ( V_73 < 0 ) {
V_55 += V_70 * 2 ; V_56 -= V_70 * 2 ;
continue;
}
V_72 = & V_31 [ V_73 ] ;
if ( V_73 == V_65 )
V_57 -> V_58 |= V_67 ;
V_72 -> V_29 = V_68 ;
if ( V_68 <= 23 )
V_72 -> V_74 = 0 ;
else
V_72 -> V_74 = ( 1 << ( V_68 - 23 ) ) - 1 ;
V_72 -> V_75 = V_69 ;
if ( V_73 == V_62 || V_73 == V_63 )
V_72 -> V_76 = 1 ;
else
V_72 -> V_76 = 0 ;
while ( V_56 > 0 && V_70 ) {
unsigned int V_29 = F_16 ( V_55 [ 0 ] ) ;
int V_77 = F_16 ( V_55 [ 1 ] ) ;
V_55 += 2 ; V_56 -= 2 ;
V_70 -- ;
V_61 = F_19 ( V_29 ) ;
if ( V_61 < 0 )
continue;
if ( V_77 == - 1 )
F_22 ( L_8
L_9 , V_68 , V_29 ) ;
V_72 -> V_77 [ V_61 ] = V_77 ;
F_21 ( L_10
L_11 ,
V_68 , V_29 , V_72 -> V_75 ,
V_72 -> V_74 , V_72 -> V_76 , V_72 -> V_77 [ V_61 ] ) ;
}
}
return 1 ;
}
static int T_1 F_23 ( unsigned long V_51 ,
const char * V_52 , int V_53 ,
void * V_54 ) {
const char * type = F_15 ( V_51 , L_2 , NULL ) ;
const T_3 * V_78 ;
const T_2 * V_79 ;
unsigned int V_80 ;
long unsigned int V_81 ;
long unsigned int V_82 ;
if ( type == NULL || strcmp ( type , L_12 ) != 0 )
return 0 ;
V_79 = F_15 ( V_51 , L_13 , NULL ) ;
if ( V_79 == NULL )
return 0 ;
V_80 = ( 1 << F_16 ( V_79 [ 0 ] ) ) ;
V_78 = F_15 ( V_51 , L_14 , NULL ) ;
if ( V_78 == NULL )
return 0 ;
V_81 = F_24 ( V_78 [ 0 ] ) ;
V_82 = F_24 ( V_78 [ 1 ] ) ;
if ( V_82 != ( 16 * V_83 ) )
return 0 ;
F_25 ( V_84 L_15
L_16 ,
V_81 , V_82 , V_80 ) ;
if ( V_81 + ( 16 * V_83 ) <= F_26 () ) {
F_27 ( V_81 , V_82 * V_80 ) ;
F_28 ( V_81 , V_82 , V_80 ) ;
}
return 0 ;
}
static void F_29 ( void )
{
int V_85 , V_86 ;
for ( V_85 = 0 ; V_85 < V_87 ; V_85 ++ )
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
V_31 [ V_85 ] . V_77 [ V_86 ] = - 1 ;
}
static bool F_30 ( void )
{
#ifdef F_31
return ! F_32 ( V_88 ) ;
#else
return false ;
#endif
}
static void T_1 F_33 ( void )
{
int V_47 ;
F_29 () ;
memcpy ( V_31 , V_89 ,
sizeof( V_89 ) ) ;
V_47 = F_18 ( F_20 , NULL ) ;
if ( V_47 != 0 )
goto V_90;
if ( F_34 ( V_67 ) )
memcpy ( V_31 , V_91 ,
sizeof( V_91 ) ) ;
V_90:
if ( ! F_12 () ) {
if ( V_31 [ V_65 ] . V_29 )
V_92 = V_65 ;
else if ( V_31 [ V_64 ] . V_29 )
V_92 = V_64 ;
}
#ifdef F_35
if ( V_31 [ V_63 ] . V_29 ) {
V_93 = V_63 ;
V_94 = V_63 ;
if ( V_92 == V_62 )
V_92 = V_63 ;
if ( F_34 ( V_95 ) ) {
if ( ! F_30 () || ! F_36 ( V_96 ) )
V_97 = V_63 ;
} else
V_98 = 1 ;
}
#endif
#ifdef F_37
if ( V_31 [ V_65 ] . V_29 &&
F_38 () >= 0x40000000 )
V_99 = V_65 ;
else if ( V_31 [ V_63 ] . V_29 )
V_99 = V_63 ;
else
V_99 = V_62 ;
#endif
F_25 ( V_100 L_17
L_18
#ifdef F_37
L_19
#endif
L_20 ,
V_31 [ V_92 ] . V_29 ,
V_31 [ V_93 ] . V_29 ,
V_31 [ V_97 ] . V_29
#ifdef F_37
, V_31 [ V_99 ] . V_29
#endif
) ;
#ifdef F_39
F_18 ( F_23 , NULL ) ;
#endif
}
static int T_1 F_40 ( unsigned long V_51 ,
const char * V_52 , int V_53 ,
void * V_54 )
{
const char * type = F_15 ( V_51 , L_2 , NULL ) ;
const T_2 * V_55 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_55 = F_15 ( V_51 , L_21 , NULL ) ;
if ( V_55 != NULL ) {
V_101 = F_16 ( V_55 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
unsigned F_41 ( unsigned long V_102 )
{
unsigned V_103 = F_42 ( V_102 ) ;
unsigned V_104 = V_31 [ V_93 ] . V_29 ;
unsigned V_105 ;
if ( ( 1UL << V_103 ) < V_102 )
V_103 += 1 ;
V_105 = V_103 - ( V_104 + 1 ) ;
return F_43 ( V_105 + 7 , 18U ) ;
}
static unsigned long T_1 F_44 ( void )
{
if ( V_101 == 0 )
F_18 ( F_40 , NULL ) ;
if ( V_101 )
return 1UL << V_101 ;
return 1UL << F_41 ( F_38 () ) ;
}
int F_45 ( unsigned long V_106 , unsigned long V_107 )
{
int V_47 = F_2 ( V_106 , V_107 , F_46 ( V_106 ) ,
F_47 ( V_108 ) , V_92 ,
V_109 ) ;
if ( V_47 < 0 ) {
int V_110 = F_13 ( V_106 , V_107 , V_92 ,
V_109 ) ;
F_10 ( V_110 && ( V_110 != - V_50 ) ) ;
}
return V_47 ;
}
int F_48 ( unsigned long V_106 , unsigned long V_107 )
{
int V_47 = F_13 ( V_106 , V_107 , V_92 ,
V_109 ) ;
F_49 ( V_47 < 0 ) ;
return V_47 ;
}
static void T_1 F_50 ( T_4 V_111 ,
unsigned long V_112 )
{
unsigned long V_113 ;
unsigned long V_114 ;
unsigned long V_115 = 1UL << V_116 ;
V_113 = 0 ;
V_114 = F_42 ( V_112 ) - 11 ;
F_51 ( ( V_116 > 24 ) , L_22 ) ;
V_117 = F_52 ( F_53 ( V_115 , V_115 ,
V_118 ) ) ;
memset ( ( void * ) V_117 , 0 , V_115 ) ;
V_117 -> V_119 = F_54 ( V_113 | V_111 | V_114 ) ;
V_117 -> V_120 = 0 ;
F_3 ( L_23 , V_117 ) ;
F_55 ( V_121 , F_46 ( V_117 ) | ( V_116 - 12 ) ) ;
}
static void T_1 F_56 ( void )
{
unsigned long V_122 ;
unsigned long V_112 ;
unsigned long V_23 ;
unsigned long V_123 = 0 , V_56 = 0 , V_124 ;
struct V_125 * V_126 ;
F_3 ( L_24 ) ;
F_17 () ;
F_33 () ;
if ( F_34 ( V_59 ) ) {
V_109 = V_127 ;
V_128 = V_127 ;
F_25 ( V_84 L_25 ) ;
}
V_129 = F_44 () ;
V_112 = V_129 >> 7 ;
V_39 = V_112 - 1 ;
if ( F_57 ( V_130 ) ) {
V_131 = NULL ;
V_132 = 0 ;
#ifdef F_58
if ( F_59 () && V_41 . V_133 )
V_41 . V_133 () ;
#endif
} else {
if ( F_36 ( V_134 ) )
V_124 = 0x80000000 ;
else
V_124 = V_118 ;
V_122 = F_53 ( V_129 , V_129 , V_124 ) ;
F_3 ( L_26 , V_122 ,
V_129 ) ;
V_131 = F_52 ( V_122 ) ;
V_132 = V_122 + F_42 ( V_112 ) - 11 ;
memset ( ( void * ) V_122 , 0 , V_129 ) ;
if ( ! F_32 ( V_135 ) )
F_55 ( V_136 , V_132 ) ;
else
F_50 ( V_122 , V_112 ) ;
}
V_23 = F_47 ( V_108 ) ;
#ifdef F_11
if ( F_12 () ) {
V_45 = F_26 () >> V_44 ;
V_46 = F_52 ( F_53 (
V_45 , 1 , V_137 ) ) ;
memset ( V_46 , 0 , V_45 ) ;
}
#endif
F_60 (memory, reg) {
V_123 = ( unsigned long ) F_52 ( V_126 -> V_123 ) ;
V_56 = V_126 -> V_56 ;
F_3 ( L_27 ,
V_123 , V_56 , V_23 ) ;
#ifdef F_61
F_3 ( L_28 , V_138 ) ;
if ( V_138 != 0 && V_138 >= V_123
&& V_138 < ( V_123 + V_56 ) ) {
unsigned long V_139 = V_138 + 16 * V_140 ;
if ( V_123 != V_138 )
F_10 ( F_2 ( V_123 , V_138 ,
F_46 ( V_123 ) , V_23 ,
V_92 ,
V_109 ) ) ;
if ( ( V_123 + V_56 ) > V_139 )
F_10 ( F_2 ( V_138 + 16 * V_140 ,
V_123 + V_56 ,
F_46 ( V_139 ) ,
V_23 ,
V_92 ,
V_109 ) ) ;
continue;
}
#endif
F_10 ( F_2 ( V_123 , V_123 + V_56 , F_46 ( V_123 ) ,
V_23 , V_92 , V_109 ) ) ;
}
F_62 ( V_118 ) ;
if ( V_141 ) {
V_141 = ( unsigned long ) F_52 ( V_141 ) ;
V_142 = ( unsigned long ) F_52 ( V_142 ) ;
if ( V_123 + V_56 >= V_141 )
V_141 = V_123 + V_56 + 1 ;
F_10 ( F_2 ( V_141 , V_142 ,
F_46 ( V_141 ) , V_23 ,
V_92 , V_109 ) ) ;
}
F_3 ( L_29 ) ;
}
void T_1 F_63 ( void )
{
V_143 = V_144 ;
V_145 = V_146 ;
V_147 = V_148 ;
V_149 = V_150 ;
V_151 = V_152 ;
V_153 = V_154 ;
V_155 = V_156 ;
V_157 = V_158 ;
V_159 = V_160 ;
V_161 = V_162 ;
V_163 = V_164 ;
V_165 = 0 ;
V_166 = 0 ;
V_167 = 0 ;
V_168 = V_169 ;
V_170 = V_171 ;
V_172 = V_173 ;
V_174 = V_175 ;
V_176 = (struct V_177 * ) V_178 ;
V_179 = V_180 ;
#ifdef F_64
V_181 = V_182 ;
#endif
F_56 () ;
F_65 () ;
}
void F_66 ( void )
{
if ( ! F_57 ( V_130 ) ) {
if ( ! F_32 ( V_135 ) )
F_55 ( V_136 , V_132 ) ;
else
F_55 ( V_121 ,
F_46 ( V_117 ) | ( V_116 - 12 ) ) ;
}
F_65 () ;
}
unsigned int F_67 ( unsigned int V_183 , T_5 V_184 , int V_185 )
{
struct V_177 * V_177 ;
if ( ! F_68 ( F_69 ( V_184 ) ) )
return V_183 ;
V_177 = F_70 ( V_184 ) ;
if ( ! F_71 ( V_186 , & V_177 -> V_187 ) && ! F_72 ( V_177 ) ) {
if ( V_185 == 0x400 ) {
F_73 ( V_177 ) ;
F_74 ( V_186 , & V_177 -> V_187 ) ;
} else
V_183 |= V_4 ;
}
return V_183 ;
}
static unsigned int F_75 ( unsigned long V_188 )
{
T_6 V_189 ;
unsigned char * V_190 ;
unsigned long V_191 , V_192 ;
if ( V_188 < V_193 ) {
V_189 = F_76 () -> V_194 ;
V_191 = F_77 ( V_188 ) ;
return ( V_189 >> ( V_191 * 4 ) ) & 0xF ;
}
V_190 = F_76 () -> V_195 ;
V_191 = F_78 ( V_188 ) ;
V_192 = V_191 & 0x1 ;
return ( V_190 [ V_191 >> 1 ] >> ( V_192 * 4 ) ) & 0xF ;
}
unsigned int F_75 ( unsigned long V_188 )
{
return F_76 () -> V_196 ;
}
void F_79 ( struct V_197 * V_198 , unsigned long V_188 )
{
if ( F_80 ( V_198 , V_188 ) == V_62 )
return;
F_81 ( V_198 , V_188 , 1 , V_62 ) ;
F_82 ( V_198 ) ;
if ( ( F_75 ( V_188 ) != V_62 ) && ( V_199 -> V_198 == V_198 ) ) {
F_83 ( & V_198 -> V_200 ) ;
F_84 () ;
}
}
static int F_85 ( struct V_197 * V_198 , unsigned long V_201 )
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
static inline int F_85 ( struct V_197 * V_198 , unsigned long V_201 )
{
return 0 ;
}
void F_86 ( unsigned long V_201 , unsigned long V_214 ,
unsigned long V_34 , unsigned long V_185 ,
int V_25 , int V_24 , int V_215 , unsigned long V_184 )
{
if ( ! F_87 () )
return;
F_21 ( L_30 ,
V_201 , V_214 , V_199 -> V_216 ) ;
F_21 ( L_31 ,
V_185 , V_34 , V_25 , V_24 , V_215 , V_184 ) ;
}
static void F_88 ( unsigned long V_201 , struct V_197 * V_198 ,
int V_24 , bool V_217 )
{
if ( V_217 ) {
if ( V_24 != F_75 ( V_201 ) ) {
F_83 ( & V_198 -> V_200 ) ;
F_84 () ;
}
} else if ( F_76 () -> V_218 !=
V_31 [ V_94 ] . V_75 ) {
F_76 () -> V_218 =
V_31 [ V_94 ] . V_75 ;
F_89 () ;
}
}
int F_90 ( struct V_197 * V_198 , unsigned long V_201 ,
unsigned long V_214 , unsigned long V_185 ,
unsigned long V_187 )
{
bool V_219 ;
enum V_220 V_221 = F_91 () ;
T_8 * V_222 ;
unsigned long V_34 ;
T_5 * V_223 ;
unsigned V_224 ;
const struct V_225 * V_226 ;
int V_47 , V_217 = 0 ;
int V_24 , V_25 ;
F_92 ( L_32 ,
V_201 , V_214 , V_185 ) ;
F_93 ( V_201 , V_214 , V_185 ) ;
switch ( F_94 ( V_201 ) ) {
case V_227 :
V_217 = 1 ;
if ( ! V_198 ) {
F_92 ( L_33 ) ;
V_47 = 1 ;
goto V_228;
}
V_24 = F_80 ( V_198 , V_201 ) ;
V_25 = F_95 ( V_201 ) ;
V_34 = F_96 ( V_198 -> V_200 . V_229 , V_201 , V_25 ) ;
break;
case V_230 :
V_34 = F_4 ( V_201 , V_109 ) ;
if ( V_201 < V_231 )
V_24 = V_94 ;
else
V_24 = V_97 ;
V_25 = V_109 ;
break;
default:
V_47 = 1 ;
goto V_228;
}
F_92 ( L_34 , V_198 , V_198 -> V_232 , V_34 ) ;
if ( ! V_34 ) {
F_92 ( L_35 ) ;
V_47 = 1 ;
goto V_228;
}
V_222 = V_198 -> V_232 ;
if ( V_222 == NULL ) {
V_47 = 1 ;
goto V_228;
}
V_226 = F_97 ( F_98 () ) ;
if ( V_217 && F_99 ( F_100 ( V_198 ) , V_226 ) )
V_187 |= V_233 ;
#ifndef F_35
if ( V_24 != V_62 )
V_201 &= ~ ( ( 1ul << V_31 [ V_24 ] . V_29 ) - 1 ) ;
#endif
V_223 = F_101 ( V_222 , V_201 , & V_219 , & V_224 ) ;
if ( V_223 == NULL || ! F_102 ( * V_223 ) ) {
F_92 ( L_36 ) ;
V_47 = 1 ;
goto V_228;
}
V_214 |= V_234 ;
if ( ! F_103 ( V_214 , F_104 ( * V_223 ) ) ) {
F_92 ( L_37 ) ;
V_47 = 1 ;
goto V_228;
}
if ( V_224 ) {
if ( V_219 )
V_47 = F_105 ( V_201 , V_214 , V_34 , ( V_235 * ) V_223 ,
V_185 , V_187 , V_25 , V_24 ) ;
#ifdef F_39
else
V_47 = F_106 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_187 , V_25 , V_224 , V_24 ) ;
#else
else {
V_47 = 1 ;
F_49 ( 1 ) ;
}
#endif
if ( V_199 -> V_198 == V_198 )
F_88 ( V_201 , V_198 , V_24 , V_217 ) ;
goto V_228;
}
#ifndef F_35
F_92 ( L_38 , F_104 ( * V_223 ) ) ;
#else
F_92 ( L_39 , F_104 ( * V_223 ) ,
F_104 ( * ( V_223 + V_236 ) ) ) ;
#endif
#ifdef F_35
if ( ( F_104 ( * V_223 ) & V_237 ) && V_24 == V_63 ) {
F_79 ( V_198 , V_201 ) ;
V_24 = V_62 ;
}
if ( V_98 && V_24 == V_63 && F_107 ( * V_223 ) ) {
if ( V_217 ) {
F_79 ( V_198 , V_201 ) ;
V_24 = V_62 ;
} else if ( V_201 < V_231 ) {
F_25 ( V_238 L_40
L_41
L_42 ) ;
V_24 = V_94 = V_62 ;
F_82 ( V_198 ) ;
}
}
#endif
if ( V_199 -> V_198 == V_198 )
F_88 ( V_201 , V_198 , V_24 , V_217 ) ;
#ifdef F_35
if ( V_24 == V_63 )
V_47 = F_108 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_187 , V_25 ) ;
else
#endif
{
int V_204 = F_85 ( V_198 , V_201 ) ;
if ( V_214 & V_204 )
V_47 = - 2 ;
else
V_47 = F_109 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_187 , V_25 , V_204 ) ;
}
if ( V_47 == - 1 )
F_86 ( V_201 , V_214 , V_34 , V_185 , V_25 , V_24 ,
V_24 , F_104 ( * V_223 ) ) ;
#ifndef F_35
F_92 ( L_43 , F_104 ( * V_223 ) ) ;
#else
F_92 ( L_44 , F_104 ( * V_223 ) ,
F_104 ( * ( V_223 + V_236 ) ) ) ;
#endif
F_92 ( L_45 , V_47 ) ;
V_228:
F_110 ( V_221 ) ;
return V_47 ;
}
int F_111 ( unsigned long V_201 , unsigned long V_214 , unsigned long V_185 ,
unsigned long V_239 )
{
unsigned long V_187 = 0 ;
struct V_197 * V_198 = V_199 -> V_198 ;
if ( F_94 ( V_201 ) == V_230 )
V_198 = & V_240 ;
if ( V_239 & V_241 )
V_187 |= V_242 ;
return F_90 ( V_198 , V_201 , V_214 , V_185 , V_187 ) ;
}
int F_112 ( unsigned long V_201 , unsigned long V_243 , unsigned long V_185 ,
unsigned long V_239 )
{
unsigned long V_214 = V_234 | V_244 ;
unsigned long V_187 = 0 ;
struct V_197 * V_198 = V_199 -> V_198 ;
if ( F_94 ( V_201 ) == V_230 )
V_198 = & V_240 ;
if ( V_239 & V_241 )
V_187 |= V_242 ;
if ( V_239 & V_245 )
V_214 |= V_6 ;
V_214 |= V_5 ;
if ( ( V_243 & V_246 ) || ( F_94 ( V_201 ) == V_227 ) )
V_214 &= ~ V_5 ;
if ( V_185 == 0x400 )
V_214 |= V_3 ;
return F_90 ( V_198 , V_201 , V_214 , V_185 , V_187 ) ;
}
static bool F_113 ( struct V_197 * V_198 , unsigned long V_201 )
{
int V_24 = F_80 ( V_198 , V_201 ) ;
if ( F_114 ( V_24 != V_198 -> V_200 . V_247 ) )
return false ;
if ( F_114 ( ( V_24 == V_62 ) && F_85 ( V_198 , V_201 ) ) )
return false ;
return true ;
}
static bool F_113 ( struct V_197 * V_198 , unsigned long V_201 )
{
return true ;
}
void F_115 ( struct V_197 * V_198 , unsigned long V_201 ,
unsigned long V_214 , unsigned long V_185 )
{
int V_248 ;
unsigned long V_34 ;
T_8 * V_222 ;
T_5 * V_223 ;
unsigned long V_187 ;
int V_47 , V_25 , V_249 = 0 ;
F_10 ( F_94 ( V_201 ) != V_227 ) ;
if ( ! F_113 ( V_198 , V_201 ) )
return;
F_92 ( L_46
L_47 , V_198 , V_198 -> V_232 , V_201 , V_214 , V_185 ) ;
V_222 = V_198 -> V_232 ;
if ( V_222 == NULL )
return;
V_25 = F_95 ( V_201 ) ;
V_34 = F_96 ( V_198 -> V_200 . V_229 , V_201 , V_25 ) ;
if ( ! V_34 )
return;
F_116 ( V_187 ) ;
V_223 = F_117 ( V_222 , V_201 , NULL , & V_248 ) ;
if ( ! V_223 )
goto V_250;
F_49 ( V_248 ) ;
#ifdef F_35
if ( ( F_104 ( * V_223 ) & V_237 ) || F_107 ( * V_223 ) )
goto V_250;
#endif
if ( F_99 ( F_100 ( V_198 ) , F_97 ( F_98 () ) ) )
V_249 |= V_233 ;
#ifdef F_35
if ( V_198 -> V_200 . V_247 == V_63 )
V_47 = F_108 ( V_201 , V_214 , V_34 , V_223 , V_185 ,
V_249 , V_25 ) ;
else
#endif
V_47 = F_109 ( V_201 , V_214 , V_34 , V_223 , V_185 , V_249 ,
V_25 , F_85 ( V_198 , V_201 ) ) ;
if ( V_47 == - 1 )
F_86 ( V_201 , V_214 , V_34 , V_185 , V_25 ,
V_198 -> V_200 . V_247 ,
V_198 -> V_200 . V_247 ,
F_104 ( * V_223 ) ) ;
V_250:
F_118 ( V_187 ) ;
}
void F_119 ( unsigned long V_35 , T_9 V_184 , int V_24 , int V_25 ,
unsigned long V_187 )
{
unsigned long V_32 , V_191 , V_29 , V_251 , V_252 ;
int V_253 = V_187 & V_233 ;
F_92 ( L_48 , V_35 ) ;
F_120 (pte, psize, vpn, index, shift) {
V_32 = F_9 ( V_35 , V_29 , V_25 ) ;
V_251 = F_121 ( V_184 , V_191 ) ;
if ( V_251 & V_254 )
V_32 = ~ V_32 ;
V_252 = ( V_32 & V_39 ) * V_40 ;
V_252 += V_251 & V_255 ;
F_92 ( L_49 , V_191 , V_252 , V_251 ) ;
V_41 . V_256 ( V_252 , V_35 , V_24 , V_24 , V_25 , V_253 ) ;
} F_122 () ;
#ifdef F_123
if ( V_253 && F_32 ( V_257 ) &&
V_199 -> V_258 . V_259 &&
F_124 ( V_199 -> V_258 . V_259 -> V_243 ) ) {
F_125 () ;
F_126 ( V_260 ) ;
}
#endif
}
void F_127 ( unsigned long V_34 , unsigned long V_188 ,
V_235 * V_261 , unsigned int V_24 , int V_25 ,
unsigned long V_187 )
{
int V_262 , V_263 , V_264 ;
unsigned long V_265 ;
unsigned char * V_266 ;
unsigned long V_251 , V_29 , V_35 , V_32 , V_252 ;
int V_253 = V_187 & V_233 ;
V_265 = V_188 & V_267 ;
V_266 = F_128 ( V_261 ) ;
if ( ! V_266 )
return;
if ( V_41 . V_268 ) {
V_41 . V_268 ( V_34 , V_265 , V_266 ,
V_24 , V_25 , V_253 ) ;
goto F_126;
}
V_29 = V_31 [ V_24 ] . V_29 ;
V_263 = V_269 >> V_29 ;
for ( V_262 = 0 ; V_262 < V_263 ; V_262 ++ ) {
V_264 = F_129 ( V_266 , V_262 ) ;
if ( ! V_264 )
continue;
V_251 = F_130 ( V_266 , V_262 ) ;
V_188 = V_265 + ( V_262 * ( 1ul << V_29 ) ) ;
V_35 = F_5 ( V_188 , V_34 , V_25 ) ;
V_32 = F_9 ( V_35 , V_29 , V_25 ) ;
if ( V_251 & V_254 )
V_32 = ~ V_32 ;
V_252 = ( V_32 & V_39 ) * V_40 ;
V_252 += V_251 & V_255 ;
V_41 . V_256 ( V_252 , V_35 , V_24 ,
V_65 , V_25 , V_253 ) ;
}
F_126:
#ifdef F_123
if ( V_253 && F_32 ( V_257 ) &&
V_199 -> V_258 . V_259 &&
F_124 ( V_199 -> V_258 . V_259 -> V_243 ) ) {
F_125 () ;
F_126 ( V_260 ) ;
}
#endif
return;
}
void F_131 ( unsigned long V_270 , int V_253 )
{
if ( V_41 . F_131 )
V_41 . F_131 ( V_270 , V_253 ) ;
else {
int V_262 ;
struct V_271 * V_272 =
F_132 ( & V_271 ) ;
for ( V_262 = 0 ; V_262 < V_270 ; V_262 ++ )
F_119 ( V_272 -> V_35 [ V_262 ] , V_272 -> V_184 [ V_262 ] ,
V_272 -> V_24 , V_272 -> V_25 , V_253 ) ;
}
}
void F_133 ( struct V_273 * V_259 , unsigned long V_274 , int V_47 )
{
enum V_220 V_221 = F_91 () ;
if ( F_134 ( V_259 ) ) {
#ifdef F_135
if ( V_47 == - 2 )
F_136 ( V_275 , V_259 , V_276 , V_274 ) ;
else
#endif
F_136 ( V_277 , V_259 , V_278 , V_274 ) ;
} else
F_137 ( V_259 , V_274 , V_277 ) ;
F_110 ( V_221 ) ;
}
long F_138 ( unsigned long V_32 , unsigned long V_35 ,
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
if ( F_114 ( V_252 == - 1 ) ) {
V_281 = ( ( ~ V_32 & V_39 ) *
V_40 ) & ~ 0x7UL ;
V_252 = V_41 . V_42 ( V_281 , V_35 , V_279 , V_2 ,
V_280 | V_283 ,
V_24 , V_24 , V_25 ) ;
if ( V_252 == - 1 ) {
if ( F_139 () & 0x1 )
V_281 = ( ( V_32 & V_39 ) *
V_40 ) & ~ 0x7UL ;
V_41 . V_284 ( V_281 ) ;
goto V_282;
}
}
return V_252 ;
}
static void F_140 ( unsigned long V_26 , unsigned long V_285 )
{
unsigned long V_32 ;
unsigned long V_34 = F_4 ( V_26 , V_109 ) ;
unsigned long V_35 = F_5 ( V_26 , V_34 , V_109 ) ;
unsigned long V_286 = F_1 ( F_47 ( V_108 ) ) ;
long V_30 ;
V_32 = F_9 ( V_35 , V_44 , V_109 ) ;
if ( ! V_34 )
return;
V_30 = F_138 ( V_32 , V_35 , F_46 ( V_26 ) , V_286 ,
V_43 ,
V_92 , V_109 ) ;
F_10 ( V_30 < 0 ) ;
F_141 ( & V_287 ) ;
F_10 ( V_46 [ V_285 ] & 0x80 ) ;
V_46 [ V_285 ] = V_30 | 0x80 ;
F_142 ( & V_287 ) ;
}
static void F_143 ( unsigned long V_26 , unsigned long V_285 )
{
unsigned long V_32 , V_251 , V_252 ;
unsigned long V_34 = F_4 ( V_26 , V_109 ) ;
unsigned long V_35 = F_5 ( V_26 , V_34 , V_109 ) ;
V_32 = F_9 ( V_35 , V_44 , V_109 ) ;
F_141 ( & V_287 ) ;
F_10 ( ! ( V_46 [ V_285 ] & 0x80 ) ) ;
V_251 = V_46 [ V_285 ] & 0x7f ;
V_46 [ V_285 ] = 0 ;
F_142 ( & V_287 ) ;
if ( V_251 & V_254 )
V_32 = ~ V_32 ;
V_252 = ( V_32 & V_39 ) * V_40 ;
V_252 += V_251 & V_255 ;
V_41 . V_256 ( V_252 , V_35 , V_92 , V_92 ,
V_109 , 0 ) ;
}
void F_144 ( struct V_177 * V_177 , int V_288 , int V_289 )
{
unsigned long V_187 , V_26 , V_285 ;
int V_262 ;
F_116 ( V_187 ) ;
for ( V_262 = 0 ; V_262 < V_288 ; V_262 ++ , V_177 ++ ) {
V_26 = ( unsigned long ) F_145 ( V_177 ) ;
V_285 = F_46 ( V_26 ) >> V_44 ;
if ( V_285 >= V_45 )
continue;
if ( V_289 )
F_140 ( V_26 , V_285 ) ;
else
F_143 ( V_26 , V_285 ) ;
}
F_118 ( V_187 ) ;
}
void F_146 ( T_4 V_290 ,
T_4 V_291 )
{
F_10 ( V_290 != 0 ) ;
V_137 = F_147 ( T_6 , V_291 , 0x40000000 ) ;
F_62 ( V_137 ) ;
}
