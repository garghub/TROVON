static unsigned long T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 , * V_3 ;
V_3 = F_2 ( V_4 | V_1 , sizeof( * V_3 ) ) ;
V_2 = * V_3 ;
F_3 ( V_3 , sizeof( * V_3 ) ) ;
return V_2 ;
}
static inline bool F_4 ( T_2 V_5 , T_2 V_6 )
{
return V_5 >= V_7 && V_6 <= V_8 ;
}
static bool F_5 ( T_2 V_5 , T_2 V_6 )
{
return F_6 ( V_5 , V_6 ) || F_4 ( V_5 , V_6 ) ;
}
static int T_1 F_7 ( void )
{
union V_9 V_10 ;
union V_11 V_12 ;
int V_13 ;
V_10 . V_14 = F_1 ( V_15 ) ;
V_12 . V_14 = F_1 ( V_16 ) ;
V_17 = V_10 . V_18 . V_19 ;
switch ( V_10 . V_18 . V_20 ) {
case V_21 :
case V_22 :
V_17 += V_23 - 1 ;
break;
case V_24 :
case V_25 :
V_17 += V_26 - 1 ;
break;
}
V_27 -> V_28 = V_17 ;
V_13 = ( V_10 . V_18 . V_10 >> 1 ) & ( ( 1 << V_12 . V_18 . V_29 ) - 1 ) ;
return V_13 ;
}
static void T_1 F_8 ( void )
{
V_30 . V_14 = F_1 ( V_31 ) ;
if ( ! V_30 . V_14 )
V_30 . V_18 . V_32 = V_33 ;
}
static void T_1 F_9 ( void )
{
union V_34 V_35 ;
if ( F_10 () ) {
V_35 . V_14 =
F_1 ( V_36 ) ;
V_37 =
V_35 . V_38 . V_39 & V_40 ;
}
}
static int T_1 F_11 ( char * V_41 , char * V_42 )
{
int V_43 , V_44 , V_45 , V_46 ;
V_44 = ! strcmp ( V_41 , L_1 ) ;
V_45 = ! strcmp ( V_41 , L_2 ) ;
V_46 = ! strncmp ( V_41 , L_3 , 4 ) ;
if ( V_44 || V_45 || V_46 ) {
V_27 -> V_28 =
( V_44 ? V_47 :
( V_45 ? V_23 :
V_26 ) ) ;
V_43 = F_7 () ;
F_8 () ;
V_48 . V_49 = F_5 ;
V_48 . V_50 = V_51 ;
if ( ! strcmp ( V_42 , L_4 ) )
V_52 = V_53 ;
else if ( ! strcmp ( V_42 , L_5 ) )
V_52 = V_54 ;
else if ( ! strcmp ( V_42 , L_6 ) ) {
F_12 ( V_55 ,
V_43 << V_30 . V_18 . V_32 ) ;
V_52 = V_56 ;
F_9 () ;
return 1 ;
}
}
return 0 ;
}
enum V_52 F_13 ( void )
{
return V_52 ;
}
int F_14 ( void )
{
return V_52 != V_57 ;
}
static int T_3 F_15 ( int V_58 , unsigned long V_59 )
{
#ifdef F_16
unsigned long V_2 ;
int V_13 ;
V_13 = F_17 ( V_58 ) ;
V_58 |= V_37 ;
V_2 = ( 1UL << V_60 ) |
( V_58 << V_61 ) |
( ( V_59 << V_62 ) >> 12 ) |
V_63 ;
F_18 ( V_13 , V_64 , V_2 ) ;
V_2 = ( 1UL << V_60 ) |
( V_58 << V_61 ) |
( ( V_59 << V_62 ) >> 12 ) |
V_65 ;
F_18 ( V_13 , V_64 , V_2 ) ;
F_19 ( & V_66 , 1 ) ;
#endif
return 0 ;
}
static void F_20 ( int V_67 , int V_68 )
{
unsigned long V_69 ;
int V_13 ;
V_69 = F_21 ( V_70 , V_67 ) ;
V_13 = F_17 ( V_69 ) ;
F_22 ( V_13 , V_69 , V_68 ) ;
}
static void F_23 ( const struct V_71 * V_72 , int V_68 )
{
unsigned int V_67 ;
F_24 (cpu, mask)
F_20 ( V_67 , V_68 ) ;
}
static void F_25 ( const struct V_71 * V_72 , int V_68 )
{
unsigned int V_73 = F_26 () ;
unsigned int V_67 ;
F_24 (cpu, mask) {
if ( V_67 != V_73 )
F_20 ( V_67 , V_68 ) ;
}
}
static void F_27 ( int V_68 )
{
unsigned int V_73 = F_26 () ;
unsigned int V_67 ;
F_28 (cpu) {
if ( V_67 != V_73 )
F_20 ( V_67 , V_68 ) ;
}
}
static void F_29 ( int V_68 )
{
F_23 ( V_74 , V_68 ) ;
}
static int F_30 ( int V_69 )
{
return 1 ;
}
static int F_31 ( void )
{
return 1 ;
}
static void F_32 ( void )
{
}
static int
F_33 ( const struct V_71 * V_71 ,
const struct V_71 * V_75 ,
unsigned int * V_69 )
{
int unsigned V_67 ;
F_34 (cpu, cpumask, andmask) {
if ( F_35 ( V_67 , V_74 ) )
break;
}
if ( F_36 ( V_67 < V_76 ) ) {
* V_69 = F_21 ( V_70 , V_67 ) | V_37 ;
return 0 ;
}
return - V_77 ;
}
static unsigned int F_37 ( unsigned long V_78 )
{
unsigned int V_79 ;
F_38 ( F_39 () && F_40 () > 1 ) ;
V_79 = V_78 | F_41 ( V_55 ) ;
return V_79 ;
}
static unsigned long F_42 ( unsigned int V_79 )
{
unsigned long V_78 ;
V_78 = V_79 ;
return V_78 ;
}
static unsigned int F_43 ( void )
{
return F_37 ( F_44 ( V_80 ) ) ;
}
static int F_45 ( int V_81 , int V_82 )
{
return F_43 () >> V_82 ;
}
static void F_46 ( int V_68 )
{
F_47 ( V_83 , V_68 ) ;
}
static int F_48 ( void )
{
return V_84 == & V_85 ;
}
static T_3 void F_49 ( int V_13 )
{
F_12 ( V_55 , V_13 << V_30 . V_18 . V_32 ) ;
}
static T_1 int F_50 ( int V_13 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < F_51 () ; V_86 ++ )
if ( V_13 == V_87 [ V_86 ] . V_13 )
return V_86 ;
F_52 () ;
}
static T_1 void F_53 ( unsigned long * V_88 , unsigned long * V_89 )
{
union V_90 V_91 ;
union V_92 V_93 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < F_54 ( V_95 ) ; V_94 ++ ) {
V_91 . V_14 = F_55 ( V_95 [ V_94 ] . V_91 ) ;
if ( V_91 . V_18 . V_96 && V_91 . V_18 . V_88 == 0 ) {
* V_89 = ( 1UL << V_91 . V_18 . V_97 ) ;
V_93 . V_14 = F_55 ( V_95 [ V_94 ] . V_93 ) ;
* V_88 = ( unsigned long ) V_93 . V_18 . V_98 << V_99 ;
return;
}
}
* V_88 = * V_89 = 0 ;
}
static T_1 void F_56 ( char * V_79 , unsigned long V_88 , int V_100 ,
int V_101 , int V_102 , enum V_103 V_103 )
{
unsigned long V_104 , V_105 ;
V_105 = V_88 << V_100 ;
V_104 = ( 1UL << V_101 ) * ( V_102 + 1 ) ;
if ( ! V_105 ) {
F_57 ( L_7 , V_79 ) ;
return;
}
F_57 ( L_8 , V_79 , V_105 , V_105 + V_104 ) ;
if ( V_103 == V_106 )
F_58 ( V_105 , V_104 ) ;
else
F_59 ( V_105 , V_104 ) ;
}
static T_1 void F_60 ( int V_102 )
{
union V_107 V_108 ;
int V_109 = V_110 ;
V_108 . V_14 = F_55 ( V_111 ) ;
if ( V_108 . V_18 . V_96 ) {
F_56 ( L_9 , V_108 . V_18 . V_88 , V_109 , V_109 , V_102 , V_112 ) ;
V_7 = ( ( T_2 ) V_108 . V_18 . V_88 << V_109 ) ;
V_8 = V_7 + ( 1UL << V_109 ) * ( V_102 + 1 ) ;
} else {
F_57 ( L_10 ) ;
}
}
static T_1 void F_61 ( int V_102 )
{
union V_113 V_3 ;
int V_109 = V_114 ;
V_3 . V_14 = F_55 ( V_115 ) ;
if ( V_3 . V_18 . V_96 )
F_56 ( L_11 , V_3 . V_18 . V_88 , V_109 , V_109 , V_102 , V_106 ) ;
else
F_57 ( L_12 ) ;
}
static T_1 void F_62 ( int V_116 , int V_117 , int V_102 )
{
union V_118 V_119 ;
unsigned long V_3 ;
unsigned long V_88 ;
int V_94 , V_120 , V_109 , V_121 , V_122 ;
int V_123 , V_124 , V_125 , V_126 ;
char * V_79 ;
V_79 = V_127 [ V_116 ] . V_79 ;
V_119 . V_14 = F_55 ( V_127 [ V_116 ] . V_119 ) ;
F_57 ( L_13 ,
V_79 , V_119 . V_14 , V_119 . V_128 . V_88 , V_119 . V_128 . V_121 ) ;
if ( ! V_119 . V_128 . V_96 ) {
F_57 ( L_14 , V_79 ) ;
return;
}
V_109 = V_129 ;
V_88 = ( unsigned long ) V_119 . V_128 . V_88 ;
V_121 = V_119 . V_128 . V_121 ;
V_3 = V_127 [ V_116 ] . V_93 ;
V_120 = V_130 ;
V_117 *= 2 ;
V_102 *= 2 ;
V_122 = V_124 = V_125 = V_126 = - 1 ;
for ( V_94 = 0 ; V_94 < V_120 ; V_94 ++ ) {
union V_131 V_93 ;
V_93 . V_14 = F_55 ( V_3 + V_94 * 8 ) ;
V_123 = V_93 . V_128 . V_123 ;
if ( V_123 < V_117 || V_102 < V_123 )
V_123 = - 1 ;
if ( V_123 == V_124 ) {
V_126 = V_94 ;
if ( V_94 != V_120 - 1 )
continue;
}
if ( V_124 != - 1 || ( V_94 == V_120 - 1 && V_123 != - 1 ) ) {
unsigned long V_132 , V_133 ;
int V_134 , V_135 ;
if ( V_124 == - 1 ) {
V_134 = V_135 = V_94 ;
V_124 = V_123 ;
} else {
V_134 = V_125 ;
V_135 = V_126 ;
}
V_132 = ( V_88 << V_109 ) +
V_134 * ( unsigned long ) ( 1 << V_121 ) ;
V_133 = ( V_88 << V_109 ) +
( V_135 + 1 ) * ( unsigned long ) ( 1 << V_121 ) ;
F_57 ( L_15 ,
V_79 , V_125 , V_126 , V_124 , V_132 , V_133 ) ;
if ( V_122 < V_135 )
V_122 = V_135 ;
}
V_125 = V_126 = V_94 ;
V_124 = V_123 ;
}
F_57 ( L_16 ,
V_79 , V_88 , V_109 , V_121 , V_122 ) ;
if ( V_122 >= 0 )
F_56 ( V_79 , V_88 , V_109 , V_121 , V_122 , V_106 ) ;
}
static T_1 void F_63 ( int V_117 , int V_102 )
{
union V_136 V_137 ;
unsigned long V_3 , V_88 ;
int V_109 , V_96 , V_121 , V_138 ;
if ( F_64 () ) {
F_62 ( 0 , V_117 , V_102 ) ;
F_62 ( 1 , V_117 , V_102 ) ;
return;
}
if ( F_10 () ) {
V_3 = V_139 ;
V_109 = V_140 ;
V_137 . V_14 = F_55 ( V_3 ) ;
V_96 = ! ! V_137 . V_38 . V_96 ;
V_88 = V_137 . V_38 . V_88 ;
V_121 = V_137 . V_38 . V_121 ;
V_138 = V_137 . V_38 . V_138 ;
} else if ( F_65 () ) {
V_3 = V_141 ;
V_109 = V_142 ;
V_137 . V_14 = F_55 ( V_3 ) ;
V_96 = ! ! V_137 . V_143 . V_96 ;
V_88 = V_137 . V_143 . V_88 ;
V_121 = V_137 . V_143 . V_121 ;
V_138 = V_137 . V_143 . V_138 ;
} else
return;
if ( V_96 ) {
V_102 &= ( 1 << V_138 ) - 1 ;
F_57 (
L_17 ,
V_88 , V_109 , V_121 , V_138 , V_102 ) ;
F_56 ( L_18 , V_88 , V_109 , V_121 , V_102 , V_106 ) ;
} else {
F_57 ( L_19 ) ;
}
}
static T_1 void F_66 ( void )
{
F_58 ( V_144 , V_145 ) ;
F_58 ( V_4 , V_146 ) ;
}
static T_1 void F_67 ( void )
{
long V_147 ;
T_2 V_148 ;
V_147 = F_68 ( V_149 ,
& V_148 ) ;
if ( V_147 != V_150 || V_148 < 100000 ) {
F_69 ( V_151
L_20
L_21 ) ;
V_152 = 1000000000000UL / 30000UL ;
} else
V_152 = V_148 ;
}
static void F_70 ( unsigned long V_153 )
{
struct V_154 * V_155 = & V_27 -> V_156 . V_155 ;
unsigned char V_157 = V_27 -> V_156 . V_158 ;
V_157 ^= V_159 ;
if ( F_71 ( F_72 () ) )
V_157 &= ~ V_160 ;
else
V_157 |= V_160 ;
F_73 ( V_157 ) ;
F_74 ( V_155 , V_161 + V_162 ) ;
}
static void T_3 F_75 ( int V_67 )
{
while ( ! F_76 ( V_67 ) -> V_156 . V_163 ) {
struct V_154 * V_155 = & F_76 ( V_67 ) -> V_156 . V_155 ;
F_77 ( V_67 , V_159 | V_160 ) ;
F_78 ( V_155 , F_70 , V_67 ) ;
V_155 -> V_164 = V_161 + V_162 ;
F_79 ( V_155 , V_67 ) ;
F_76 ( V_67 ) -> V_156 . V_163 = 1 ;
V_67 = 0 ;
}
}
static void T_3 F_80 ( int V_67 )
{
if ( F_76 ( V_67 ) -> V_156 . V_163 ) {
F_76 ( V_67 ) -> V_156 . V_163 = 0 ;
F_81 ( & F_76 ( V_67 ) -> V_156 . V_155 ) ;
}
F_77 ( V_67 , 0xff ) ;
}
static T_3 int F_82 ( struct V_165 * V_166 ,
unsigned long V_167 , void * V_168 )
{
long V_67 = ( long ) V_168 ;
switch ( V_167 ) {
case V_169 :
F_75 ( V_67 ) ;
break;
case V_170 :
F_80 ( V_67 ) ;
break;
default:
break;
}
return V_171 ;
}
static T_1 void F_83 ( void )
{
F_84 ( F_82 , 0 ) ;
}
static T_1 void F_83 ( void )
{
}
static T_1 int F_85 ( void )
{
int V_67 ;
if ( F_14 () )
F_28 (cpu)
F_75 ( V_67 ) ;
return 0 ;
}
int F_86 ( struct V_172 * V_173 , bool V_174 ,
unsigned int V_175 , T_4 V_176 )
{
int V_177 , V_178 , V_179 ;
F_87 ( L_22 ,
V_173 -> V_180 , V_174 , V_175 , V_176 ) ;
if ( ! ( V_176 & V_181 ) )
return 0 ;
if ( ( V_175 & V_182 ) == 0 )
return 0 ;
V_177 = F_88 ( V_173 -> V_178 ) ;
V_178 = V_173 -> V_178 -> V_183 ;
V_179 = F_89 ( V_174 , V_177 , V_178 ) ;
F_87 ( L_23 , V_174 , V_177 , V_178 , V_179 ) ;
return V_179 ;
}
void T_3 F_90 ( void )
{
if ( ! V_87 )
return;
V_87 [ F_91 () ] . V_184 ++ ;
if ( F_13 () == V_56 )
F_49 ( V_27 -> V_13 ) ;
}
int F_92 ( unsigned int V_185 , struct V_186 * V_187 )
{
unsigned long V_188 ;
int V_189 ;
V_189 = F_91 () ;
V_188 = ( F_55 ( V_190 ) & V_191 ) ;
if ( F_93 ( V_188 ) ) {
F_94 ( & V_87 [ V_189 ] . V_192 ) ;
V_188 = ( F_55 ( V_190 ) & V_191 ) ;
if ( V_188 ) {
V_87 [ V_189 ] . V_193 ++ ;
F_95 ( V_194 , V_191 ) ;
}
F_96 ( & V_87 [ V_189 ] . V_192 ) ;
}
if ( F_36 ( F_97 ( V_195 ) == V_87 [ V_189 ] . V_193 ) )
return V_196 ;
F_97 ( V_195 ) = V_87 [ V_189 ] . V_193 ;
F_94 ( & V_197 ) ;
F_57 ( L_24 , F_26 () ) ;
F_98 () ;
F_96 ( & V_197 ) ;
return V_198 ;
}
void F_99 ( void )
{
if ( F_100 ( V_199 , F_92 , 0 , L_25 ) )
F_69 ( V_151 L_26 ) ;
}
void V_51 ( void )
{
unsigned int V_200 ;
V_200 = F_44 ( V_201 ) | V_202 ;
V_200 &= ~ V_203 ;
F_47 ( V_201 , V_200 ) ;
}
void T_1 F_101 ( void )
{
union V_11 V_12 ;
union V_9 V_10 ;
unsigned long V_204 , V_205 , V_206 ;
int V_104 , V_207 , V_67 , V_208 , V_13 , V_86 , V_94 , V_209 , V_210 , V_211 ;
int V_212 , V_117 = 999999 , V_102 = - 1 ;
unsigned long V_213 , V_214 , V_105 ;
unsigned short V_215 ;
char * V_216 = ( F_10 () ? L_27 :
( F_65 () ? L_28 :
L_29 ) ) ;
F_57 ( L_30 , V_216 ) ;
F_66 () ;
V_12 . V_14 = F_55 ( V_16 ) ;
V_210 = V_12 . V_18 . V_217 ;
V_211 = V_12 . V_18 . V_29 ;
V_215 = ( 1 << V_211 ) - 1 ;
V_213 =
F_55 ( V_115 ) &
~ V_218 ;
V_10 . V_14 = F_55 ( V_15 ) ;
V_212 = ( V_10 . V_18 . V_10 & ~ ( ( 1 << V_211 ) - 1 ) ) >> 1 ;
V_204 = ( ( unsigned long ) V_212 << V_210 ) ;
F_57 ( L_31 ,
V_211 , V_210 , V_215 , V_204 , V_212 ) ;
F_57 ( L_32 , V_213 ) ;
for( V_94 = 0 ; V_94 < V_219 ; V_94 ++ )
V_220 +=
F_102 ( F_55 ( V_221 + V_94 * 8 ) ) ;
F_57 ( L_33 ,
F_10 () ? F_51 () :
( F_51 () + 1 ) / 2 ,
F_51 () ) ;
V_104 = sizeof( struct V_87 ) * F_51 () ;
V_87 = F_103 ( V_104 , V_222 ) ;
F_104 ( ! V_87 ) ;
for ( V_86 = 0 ; V_86 < F_51 () ; V_86 ++ )
V_87 [ V_86 ] . V_223 = - 1 ;
F_53 ( & V_205 , & V_206 ) ;
V_104 = sizeof( V_224 [ 0 ] ) * F_105 () ;
V_224 = F_106 ( V_104 , V_222 ) ;
F_104 ( ! V_224 ) ;
memset ( V_224 , 255 , V_104 ) ;
V_104 = sizeof( V_225 [ 0 ] ) * F_107 () ;
V_225 = F_106 ( V_104 , V_222 ) ;
F_104 ( ! V_225 ) ;
memset ( V_225 , 255 , V_104 ) ;
V_86 = 0 ;
for ( V_94 = 0 ; V_94 < V_219 ; V_94 ++ ) {
V_214 = F_55 ( V_221 + V_94 * 8 ) ;
for ( V_209 = 0 ; V_209 < 64 ; V_209 ++ ) {
if ( ! F_108 ( V_209 , & V_214 ) )
continue;
V_13 = ( V_94 * 64 + V_209 ) & V_215 ;
V_87 [ V_86 ] . V_13 = V_13 ;
V_87 [ V_86 ] . V_226 = 0 ;
V_87 [ V_86 ] . V_184 = 0 ;
F_109 ( & V_87 [ V_86 ] . V_192 ) ;
V_117 = F_110 ( V_13 , V_117 ) ;
V_102 = F_111 ( V_13 , V_102 ) ;
V_86 ++ ;
}
}
F_112 () ;
F_113 ( 0 , & V_227 , & V_228 , & V_229 ,
& V_230 , & V_231 ) ;
F_67 () ;
F_114 (cpu) {
int V_69 = F_21 ( V_70 , V_67 ) ;
V_207 = F_115 ( V_67 ) ;
F_76 ( V_67 ) -> V_215 = V_215 ;
F_76 ( V_67 ) -> V_232 = V_30 . V_18 . V_32 ;
F_76 ( V_67 ) -> V_28 = V_27 -> V_28 ;
F_76 ( V_67 ) -> V_233 = 64 - V_210 ;
F_76 ( V_67 ) -> V_234 = F_116 () ?
( V_210 == 40 ? 40 : 39 ) : V_210 ;
V_13 = F_17 ( V_69 ) ;
V_86 = F_50 ( V_13 ) ;
V_208 = V_87 [ V_86 ] . V_226 ;
V_87 [ V_86 ] . V_226 ++ ;
V_87 [ V_86 ] . V_223 = V_207 ;
F_76 ( V_67 ) -> V_235 = V_205 ;
F_76 ( V_67 ) -> V_236 = V_206 ;
F_76 ( V_67 ) -> V_210 = V_210 ;
F_76 ( V_67 ) -> V_211 = V_211 ;
F_76 ( V_67 ) -> V_237 = V_86 ;
F_76 ( V_67 ) -> V_238 = V_208 ;
F_76 ( V_67 ) -> V_13 = V_13 ;
F_76 ( V_67 ) -> V_239 = ( 1UL << ( V_210 + V_211 ) ) - 1 ;
F_76 ( V_67 ) -> V_204 = V_204 ;
F_76 ( V_67 ) -> V_212 = V_212 ;
F_76 ( V_67 ) -> V_240 = V_213 ;
F_76 ( V_67 ) -> V_241 = V_229 ;
F_76 ( V_67 ) -> V_156 . V_242 = F_117 ( V_69 ) ;
V_224 [ V_207 ] = V_86 ;
V_225 [ V_67 ] = V_86 ;
}
F_118 (nid) {
if ( V_224 [ V_207 ] >= 0 )
continue;
V_105 = F_119 ( V_207 ) << V_243 ;
V_13 = F_120 ( F_121 ( V_105 ) ) ;
V_86 = F_50 ( V_13 ) ;
V_224 [ V_207 ] = V_86 ;
}
F_60 ( V_102 ) ;
F_61 ( V_102 ) ;
F_63 ( V_117 , V_102 ) ;
F_90 () ;
F_83 () ;
F_99 () ;
F_122 ( L_34 , NULL ) ;
F_123 ( F_86 ) ;
if ( F_124 () )
V_244 = V_245 ;
}
