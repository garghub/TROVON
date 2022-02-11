unsigned long F_1 ( char * V_1 )
{
if ( F_2 ( ! V_2 ) )
F_3 ( L_1 , V_1 ) ;
else
F_4 ( L_1 , V_1 ) ;
return ~ 0ul ;
}
static unsigned long T_1 F_5 ( unsigned long V_3 )
{
unsigned long V_4 , * V_5 ;
V_5 = F_6 ( V_6 | V_3 , sizeof( * V_5 ) ) ;
V_4 = * V_5 ;
F_7 ( V_5 , sizeof( * V_5 ) ) ;
return V_4 ;
}
static inline bool F_8 ( T_2 V_7 , T_2 V_8 )
{
if ( V_9 ) {
T_2 V_10 = V_7 & V_11 ;
T_2 V_12 = V_7 & V_13 ;
T_2 V_14 = V_8 & V_11 ;
T_2 V_15 = V_8 & V_13 ;
return ( V_12 == V_9 && V_15 == V_9 &&
V_10 >= V_16 &&
V_10 <= V_17 &&
V_14 == V_10 ) ;
} else {
return V_7 >= V_18 && V_8 <= V_19 ;
}
}
static bool F_9 ( T_2 V_7 , T_2 V_8 )
{
return F_10 ( V_7 , V_8 ) || F_8 ( V_7 , V_8 ) ;
}
static int T_1 F_11 ( void )
{
union V_20 V_21 ;
union V_22 V_23 ;
int V_24 ;
V_21 . V_25 = F_5 ( V_26 ) ;
V_23 . V_25 = F_5 ( V_27 ) ;
V_28 = V_21 . V_29 . V_30 ;
switch ( V_21 . V_29 . V_31 ) {
case V_32 :
case V_33 :
V_28 += V_34 - 1 ;
break;
case V_35 :
case V_36 :
V_28 += V_37 ;
break;
case V_38 :
V_28 += V_39 - 1 ;
break;
}
V_40 -> V_41 = V_28 ;
V_42 . V_43 = ( 1 << V_23 . V_29 . V_44 ) - 1 ;
V_24 = ( V_21 . V_29 . V_21 >> 1 ) & V_42 . V_43 ;
V_42 . V_45 = 46 ;
F_12 ( L_2 ,
V_21 . V_29 . V_30 , V_21 . V_29 . V_31 , V_21 . V_29 . V_21 ,
V_23 . V_29 . V_44 , V_42 . V_43 , V_24 ) ;
return V_24 ;
}
static void F_13 ( void )
{
unsigned int V_46 , V_47 , V_48 , V_49 , V_50 ;
unsigned int V_51 ;
F_14 ( 0 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( V_46 < 0xb ) {
F_12 ( L_3 ) ;
return;
}
F_15 ( 0xb , V_52 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( V_47 == 0 || ( F_16 ( V_48 ) != V_53 ) ) {
F_12 ( L_4 ) ;
return;
}
V_51 = F_17 ( V_46 ) ;
V_50 = 1 ;
do {
F_15 ( 0xb , V_50 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( F_16 ( V_48 ) == V_54 ) {
V_51 = F_17 ( V_46 ) ;
break;
}
V_50 ++ ;
} while ( F_16 ( V_48 ) != V_55 );
V_42 . V_56 = 0 ;
V_42 . V_57 = ( ~ ( - 1 << V_51 ) ) ;
V_42 . V_58 = V_51 ;
}
static void T_1 F_18 ( void )
{
if ( F_19 () || F_20 () )
V_59 . V_25 = F_5 ( V_60 ) ;
F_13 () ;
F_12 ( L_5 ,
V_42 . V_56 , V_42 . V_57 ) ;
F_12 ( L_6 ,
V_42 . V_58 , V_42 . V_43 ) ;
}
static void T_1 F_21 ( void )
{
union V_61 V_57 ;
if ( F_22 () ) {
V_57 . V_25 =
F_5 ( V_62 ) ;
V_63 =
V_57 . V_64 . V_65 & V_66 ;
}
}
static int T_1 F_23 ( char * V_67 , char * V_68 )
{
int V_69 ;
int V_70 ;
if ( strncmp ( V_67 , L_7 , 3 ) != 0 )
return 0 ;
V_71 -> V_72 = & V_73 ;
V_40 -> V_41 =
! strncmp ( V_67 , L_8 , 4 ) ? V_39 :
! strncmp ( V_67 , L_9 , 4 ) ? V_37 :
! strcmp ( V_67 , L_10 ) ? V_34 :
! strcmp ( V_67 , L_7 ) ? V_74 : 0 ;
if ( V_40 -> V_41 == 0 )
goto V_75;
V_69 = F_11 () ;
F_18 () ;
V_76 . V_77 = F_9 ;
V_76 . V_78 = V_79 ;
if ( ! strcmp ( V_68 , L_11 ) ) {
V_80 = V_81 ;
V_70 = 0 ;
} else if ( ! strcmp ( V_68 , L_12 ) ) {
V_80 = V_82 ;
F_24 ( V_83 ,
V_69 << V_59 . V_29 . V_84 ) ;
F_21 () ;
V_70 = 1 ;
} else if ( ! strcmp ( V_68 , L_13 ) ) {
V_80 = V_85 ;
V_70 = 0 ;
} else {
goto V_75;
}
F_12 ( L_14 ,
V_67 , V_68 , V_80 ,
V_28 , V_70 ) ;
return V_70 ;
V_75:
F_25 ( L_15 , V_67 , V_68 ) ;
F_25 ( L_16 ) ;
F_26 () ;
}
enum V_80 F_27 ( void )
{
return V_80 ;
}
int F_28 ( void )
{
return V_80 != V_86 ;
}
extern int F_29 ( void )
{
return V_87 ;
}
static T_1 void F_30 ( void )
{
struct V_88 * V_89 = V_90 ;
struct V_91 * V_92 ;
unsigned long V_93 = 0 , V_94 = 0 ;
int V_95 , V_96 , V_97 , V_98 = - 1 ;
if ( ! V_89 )
return;
V_95 = V_99 * sizeof( struct V_91 ) ;
V_92 = F_31 ( V_95 , V_100 ) ;
F_32 ( ! V_92 ) ;
V_101 = V_92 ;
for (; V_89 -> type != V_102 ; V_89 ++ ) {
if ( V_89 -> type == V_103 ) {
if ( ! V_94 ) {
V_94 = V_93 ;
V_93 = V_89 -> V_104 ;
V_98 ++ ;
continue;
}
V_93 = V_89 -> V_104 ;
F_12 ( L_17 ,
( int ) ( V_89 - V_90 ) ) ;
continue;
}
if ( V_105 < V_89 -> V_106 ) {
F_25 ( L_18 ,
V_89 -> V_106 , V_105 ,
( int ) ( V_89 - V_90 ) ) ;
continue;
}
V_97 = V_89 -> V_106 - V_107 ;
if ( V_98 < V_97 ) {
V_92 = & V_101 [ V_97 ] ;
V_92 -> V_108 = V_98 ;
V_92 -> V_109 = V_89 -> V_109 ;
V_92 -> V_104 = V_93 = V_89 -> V_104 ;
V_98 = V_97 ;
continue;
}
if ( V_98 == V_97 && ! V_94 ) {
if ( V_92 -> V_104 == V_93 ) {
V_92 -> V_104 = V_93 = V_89 -> V_104 ;
continue;
}
}
if ( ! V_94 ) {
V_92 ++ ;
V_92 -> V_108 = V_97 - 1 ;
V_92 -> V_109 = V_89 -> V_109 ;
V_92 -> V_104 = V_93 = V_89 -> V_104 ;
continue;
}
V_92 ++ ;
V_92 -> V_108 = V_92 - V_101 ;
V_92 -> V_109 = V_89 -> V_109 ;
V_92 -> V_104 = V_93 = V_89 -> V_104 ;
V_98 ++ ;
}
V_92 ++ ;
V_96 = V_92 - V_101 ;
if ( V_96 < V_99 ) {
void * V_110 ;
V_95 = V_96 * sizeof( struct V_91 ) ;
V_110 = F_33 ( V_101 , V_95 , V_100 ) ;
if ( V_110 ) {
V_101 = V_110 ;
V_99 = V_96 ;
}
}
for ( V_96 = 0 , V_92 = V_101 ; V_96 < V_99 ; V_96 ++ , V_92 ++ ) {
int V_111 = V_92 -> V_108 ;
unsigned long V_7 = V_111 < 0 ? 0 :
( unsigned long ) V_101 [ V_111 ] . V_104 << V_112 ;
unsigned long V_8 =
( unsigned long ) V_92 -> V_104 << V_112 ;
F_12 ( L_19 ,
V_96 , V_92 -> V_109 , V_7 , V_8 , V_111 ) ;
}
}
static int F_34 ( int V_113 , unsigned long V_114 )
{
unsigned long V_4 ;
int V_24 ;
V_24 = F_35 ( V_113 ) ;
V_113 |= V_63 ;
V_4 = ( 1UL << V_115 ) |
( V_113 << V_116 ) |
( ( V_114 << V_117 ) >> 12 ) |
V_118 ;
F_36 ( V_24 , V_119 , V_4 ) ;
V_4 = ( 1UL << V_115 ) |
( V_113 << V_116 ) |
( ( V_114 << V_117 ) >> 12 ) |
V_120 ;
F_36 ( V_24 , V_119 , V_4 ) ;
return 0 ;
}
static void F_37 ( int V_121 , int V_122 )
{
unsigned long V_123 ;
int V_24 ;
V_123 = F_38 ( V_124 , V_121 ) ;
V_24 = F_35 ( V_123 ) ;
F_39 ( V_24 , V_123 , V_122 ) ;
}
static void F_40 ( const struct V_125 * V_126 , int V_122 )
{
unsigned int V_121 ;
F_41 (cpu, mask)
F_37 ( V_121 , V_122 ) ;
}
static void F_42 ( const struct V_125 * V_126 , int V_122 )
{
unsigned int V_127 = F_43 () ;
unsigned int V_121 ;
F_41 (cpu, mask) {
if ( V_121 != V_127 )
F_37 ( V_121 , V_122 ) ;
}
}
static void F_44 ( int V_122 )
{
unsigned int V_127 = F_43 () ;
unsigned int V_121 ;
F_45 (cpu) {
if ( V_121 != V_127 )
F_37 ( V_121 , V_122 ) ;
}
}
static void F_46 ( int V_122 )
{
F_40 ( V_128 , V_122 ) ;
}
static int F_47 ( int V_123 )
{
return 1 ;
}
static int F_48 ( void )
{
return 1 ;
}
static void F_49 ( void )
{
}
static int
F_50 ( const struct V_125 * V_125 ,
const struct V_125 * V_129 ,
unsigned int * V_123 )
{
int unsigned V_121 ;
F_51 (cpu, cpumask, andmask) {
if ( F_52 ( V_121 , V_128 ) )
break;
}
if ( F_2 ( V_121 < V_130 ) ) {
* V_123 = F_38 ( V_124 , V_121 ) | V_63 ;
return 0 ;
}
return - V_131 ;
}
static unsigned int F_53 ( unsigned long V_132 )
{
unsigned int V_133 ;
F_54 ( F_55 () && F_56 () > 1 ) ;
V_133 = V_132 | F_57 ( V_83 ) ;
return V_133 ;
}
static unsigned long F_58 ( unsigned int V_133 )
{
unsigned long V_132 ;
V_132 = V_133 ;
return V_132 ;
}
static unsigned int F_59 ( void )
{
return F_53 ( F_60 ( V_134 ) ) ;
}
static int F_61 ( int V_135 , int V_136 )
{
return F_59 () >> V_136 ;
}
static void F_62 ( int V_122 )
{
F_63 ( V_137 , V_122 ) ;
}
static int F_64 ( void )
{
return V_138 == & V_139 ;
}
static void F_65 ( int V_24 )
{
F_24 ( V_83 , V_24 << V_59 . V_29 . V_84 ) ;
}
static T_1 void F_66 ( unsigned long * V_108 , unsigned long * V_140 )
{
union V_141 V_142 ;
union V_143 V_144 ;
unsigned long V_145 ;
unsigned long V_146 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_147 ; V_96 ++ ) {
switch ( V_96 ) {
case 0 :
V_145 = V_148 ;
V_146 = V_149 ;
break;
case 1 :
V_145 = V_150 ;
V_146 = V_151 ;
break;
case 2 :
V_145 = V_152 ;
V_146 = V_153 ;
break;
}
V_142 . V_25 = F_67 ( V_146 ) ;
if ( V_142 . V_29 . V_154 && V_142 . V_29 . V_108 == 0 ) {
* V_140 = ( 1UL << V_142 . V_29 . V_155 ) ;
V_144 . V_25 = F_67 ( V_145 ) ;
* V_108 = ( unsigned long ) V_144 . V_29 . V_156
<< V_157 ;
return;
}
}
* V_108 = * V_140 = 0 ;
}
static T_1 void F_68 ( char * V_133 , unsigned long V_108 , int V_158 ,
int V_159 , int V_160 , enum V_161 V_161 )
{
unsigned long V_95 , V_162 ;
V_162 = V_108 << V_158 ;
V_95 = ( 1UL << V_159 ) * ( V_160 + 1 ) ;
if ( ! V_162 ) {
F_12 ( L_20 , V_133 ) ;
return;
}
F_69 ( L_21 , V_133 , V_162 , V_162 + V_95 ) ;
if ( V_161 == V_163 )
F_70 ( V_162 , V_95 ) ;
else
F_71 ( V_162 , V_95 ) ;
}
static T_1 void F_72 ( unsigned long V_164 )
{
union V_165 V_166 ;
T_2 V_162 ;
unsigned long V_95 ;
int V_167 ;
V_166 . V_25 = V_164 ;
V_9 = V_166 . V_25 & 0x000007fff0000000UL ;
if ( ! V_9 ) {
F_12 ( L_22 ) ;
return;
}
V_95 = 1UL << V_168 ;
V_13 = ( ( 1UL << V_40 -> V_169 ) - 1 ) & ~ ( V_95 - 1 ) ;
V_11 = ~ ( ( 1UL << V_40 -> V_169 ) - 1 ) ;
V_9 &= V_13 ;
F_73 (nid) {
V_162 = ( ( T_2 ) F_74 ( V_167 ) << V_40 -> V_169 ) |
V_9 ;
F_71 ( V_162 , V_95 ) ;
V_16 = F_75 ( V_162 , V_16 ) ;
V_17 = F_76 ( V_162 , V_17 ) ;
}
V_16 &= V_11 ;
V_17 &= V_11 ;
F_69 ( L_23 ,
V_9 , V_16 , V_17 ) ;
}
static T_1 void F_77 ( int V_160 )
{
union V_165 V_166 ;
int V_170 = V_168 ;
unsigned long V_126 = V_171 ;
unsigned long V_108 ;
V_166 . V_25 = F_67 ( V_172 ) ;
if ( ! V_166 . V_29 . V_154 ) {
F_12 ( L_24 ) ;
return;
}
if ( F_20 () && V_166 . V_173 . V_174 ) {
F_72 ( V_166 . V_25 ) ;
return;
}
V_108 = ( V_166 . V_25 & V_126 ) >> V_170 ;
F_68 ( L_25 , V_108 , V_170 , V_170 , V_160 , V_175 ) ;
V_18 = ( ( T_2 ) V_108 << V_170 ) ;
V_19 = V_18 + ( 1UL << V_170 ) * ( V_160 + 1 ) ;
}
static T_1 void F_78 ( int V_160 )
{
union V_176 V_5 ;
int V_170 = V_177 ;
V_5 . V_25 = F_67 ( V_178 ) ;
if ( V_5 . V_29 . V_154 )
F_68 ( L_26 , V_5 . V_29 . V_108 , V_170 , V_170 , V_160 , V_163 ) ;
else
F_12 ( L_27 ) ;
}
static T_1 void F_79 ( int V_179 , int V_180 , int V_160 )
{
union V_181 V_182 ;
unsigned long V_5 ;
unsigned long V_108 ;
int V_96 , V_183 , V_170 , V_184 , V_185 ;
int V_109 , V_186 , V_187 , V_188 ;
char * V_133 ;
V_133 = V_189 [ V_179 ] . V_133 ;
V_182 . V_25 = F_67 ( V_189 [ V_179 ] . V_182 ) ;
F_12 ( L_28 ,
V_133 , V_182 . V_25 , V_182 . V_173 . V_108 , V_182 . V_173 . V_184 ) ;
if ( ! V_182 . V_173 . V_154 ) {
F_12 ( L_29 , V_133 ) ;
return;
}
V_170 = V_190 ;
V_108 = ( unsigned long ) V_182 . V_173 . V_108 ;
V_184 = V_182 . V_173 . V_184 ;
V_5 = V_189 [ V_179 ] . V_144 ;
V_183 = V_191 ;
V_180 *= 2 ;
V_160 *= 2 ;
V_185 = V_186 = V_187 = V_188 = - 1 ;
for ( V_96 = 0 ; V_96 < V_183 ; V_96 ++ ) {
union V_192 V_144 ;
V_144 . V_25 = F_67 ( V_5 + V_96 * 8 ) ;
V_109 = V_144 . V_173 . V_109 ;
if ( V_109 < V_180 || V_160 < V_109 )
V_109 = - 1 ;
if ( V_109 == V_186 ) {
V_188 = V_96 ;
if ( V_96 != V_183 - 1 )
continue;
}
if ( V_186 != - 1 || ( V_96 == V_183 - 1 && V_109 != - 1 ) ) {
unsigned long V_193 , V_194 ;
int V_195 , V_196 ;
if ( V_186 == - 1 ) {
V_195 = V_196 = V_96 ;
V_186 = V_109 ;
} else {
V_195 = V_187 ;
V_196 = V_188 ;
}
V_193 = ( V_108 << V_170 ) +
V_195 * ( unsigned long ) ( 1 << V_184 ) ;
V_194 = ( V_108 << V_170 ) +
( V_196 + 1 ) * ( unsigned long ) ( 1 << V_184 ) ;
F_12 ( L_30 ,
V_133 , V_187 , V_188 , V_186 , V_193 , V_194 ) ;
if ( V_185 < V_196 )
V_185 = V_196 ;
}
V_187 = V_188 = V_96 ;
V_186 = V_109 ;
}
F_12 ( L_31 ,
V_133 , V_108 , V_170 , V_184 , V_185 ) ;
if ( V_185 >= 0 )
F_68 ( V_133 , V_108 , V_170 , V_184 , V_185 , V_163 ) ;
}
static T_1 void F_80 ( int V_180 , int V_160 )
{
union V_197 V_198 ;
unsigned long V_5 , V_108 ;
int V_170 , V_154 , V_184 , V_199 ;
if ( F_20 () || F_81 () ) {
F_79 ( 0 , V_180 , V_160 ) ;
F_79 ( 1 , V_180 , V_160 ) ;
return;
}
if ( F_22 () ) {
V_5 = V_200 ;
V_170 = V_201 ;
V_198 . V_25 = F_67 ( V_5 ) ;
V_154 = ! ! V_198 . V_64 . V_154 ;
V_108 = V_198 . V_64 . V_108 ;
V_184 = V_198 . V_64 . V_184 ;
V_199 = V_198 . V_64 . V_199 ;
} else if ( F_19 () ) {
V_5 = V_202 ;
V_170 = V_203 ;
V_198 . V_25 = F_67 ( V_5 ) ;
V_154 = ! ! V_198 . V_204 . V_154 ;
V_108 = V_198 . V_204 . V_108 ;
V_184 = V_198 . V_204 . V_184 ;
V_199 = V_198 . V_204 . V_199 ;
} else
return;
if ( V_154 ) {
V_160 &= ( 1 << V_199 ) - 1 ;
F_12 (
L_32 ,
V_108 , V_170 , V_184 , V_199 , V_160 ) ;
F_68 ( L_33 , V_108 , V_170 , V_184 , V_160 , V_163 ) ;
} else {
F_12 ( L_34 ) ;
}
}
static T_1 void F_82 ( void )
{
F_70 ( V_205 , V_206 ) ;
F_70 ( V_6 , V_207 ) ;
}
static T_1 void F_83 ( void )
{
long V_208 ;
T_2 V_209 ;
V_208 = F_84 ( V_210 ,
& V_209 ) ;
if ( V_208 != V_211 || V_209 < 100000 ) {
F_85 ( V_212
L_35
L_36 ) ;
V_213 = 1000000000000UL / 30000UL ;
} else
V_213 = V_209 ;
}
static void F_86 ( unsigned long V_214 )
{
struct V_215 * V_216 = & V_217 -> V_216 ;
unsigned char V_218 = V_217 -> V_219 ;
V_218 ^= V_220 ;
if ( F_87 ( F_88 () ) )
V_218 &= ~ V_221 ;
else
V_218 |= V_221 ;
F_89 ( V_218 ) ;
F_90 ( V_216 , V_222 + V_223 ) ;
}
static void F_91 ( int V_121 )
{
while ( ! F_92 ( V_121 ) -> V_224 ) {
struct V_215 * V_216 = & F_92 ( V_121 ) -> V_216 ;
F_93 ( V_121 , V_220 | V_221 ) ;
F_94 ( V_216 , F_86 , V_121 ) ;
V_216 -> V_225 = V_222 + V_223 ;
F_95 ( V_216 , V_121 ) ;
F_92 ( V_121 ) -> V_224 = 1 ;
V_121 = 0 ;
}
}
static void F_96 ( int V_121 )
{
if ( F_92 ( V_121 ) -> V_224 ) {
F_92 ( V_121 ) -> V_224 = 0 ;
F_97 ( & F_92 ( V_121 ) -> V_216 ) ;
}
F_93 ( V_121 , 0xff ) ;
}
static int F_98 ( struct V_226 * V_227 , unsigned long V_228 ,
void * V_229 )
{
long V_121 = ( long ) V_229 ;
switch ( V_228 & ~ V_230 ) {
case V_231 :
case V_232 :
F_91 ( V_121 ) ;
break;
case V_233 :
F_96 ( V_121 ) ;
break;
default:
break;
}
return V_234 ;
}
static T_1 void F_99 ( void )
{
F_100 ( F_98 , 0 ) ;
}
static T_1 void F_99 ( void )
{
}
static T_1 int F_101 ( void )
{
int V_121 ;
if ( F_28 () )
F_45 (cpu)
F_91 ( V_121 ) ;
return 0 ;
}
int F_102 ( struct V_235 * V_236 , bool V_237 ,
unsigned int V_238 , T_3 V_239 )
{
int V_240 , V_241 , V_242 ;
F_103 ( L_37 ,
V_236 -> V_243 , V_237 , V_238 , V_239 ) ;
if ( ! ( V_239 & V_244 ) )
return 0 ;
if ( ( V_238 & V_245 ) == 0 )
return 0 ;
V_240 = F_104 ( V_236 -> V_241 ) ;
V_241 = V_236 -> V_241 -> V_246 ;
V_242 = F_105 ( V_237 , V_240 , V_241 ) ;
F_103 ( L_38 , V_237 , V_240 , V_241 , V_242 ) ;
return V_242 ;
}
void F_106 ( void )
{
if ( F_43 () == 0 )
return;
V_40 -> V_247 ++ ;
if ( F_27 () == V_82 )
F_65 ( V_40 -> V_24 ) ;
}
static void F_107 ( struct V_248 * V_249 )
{
union V_22 V_23 ;
union V_250 V_251 ;
V_23 . V_25 = F_67 ( V_27 ) ;
V_249 -> V_252 = V_23 . V_29 . V_44 ;
if ( F_81 () ) {
V_249 -> V_169 = 0 ;
V_249 -> V_253 = 0 ;
} else if ( F_20 () ) {
V_249 -> V_169 = V_23 . V_173 . V_254 ;
V_251 . V_25 = F_67 ( V_255 ) ;
V_249 -> V_253 = V_251 . V_173 . V_254 ;
} else if ( F_19 () ) {
V_249 -> V_169 = V_23 . V_204 . V_254 ;
V_249 -> V_253 = V_249 -> V_169 == 40 ? 40 : 39 ;
} else if ( F_22 () ) {
V_249 -> V_169 = V_23 . V_64 . V_254 ;
V_249 -> V_253 = V_249 -> V_169 ;
}
V_249 -> V_256 = V_249 -> V_169 ? 64 - V_249 -> V_169 : 0 ;
}
void T_1 F_108 ( struct V_257 * V_258 )
{
struct V_248 V_248 = { 0 } ;
union V_20 V_21 ;
F_107 ( & V_248 ) ;
V_258 -> V_169 = V_248 . V_169 ;
V_258 -> V_252 = V_248 . V_252 ;
V_258 -> V_256 = V_248 . V_256 ;
V_258 -> V_253 = V_248 . V_253 ? V_248 . V_253 : 0 ;
V_258 -> V_41 = V_40 -> V_41 ;
V_258 -> V_43 = V_42 . V_43 ;
V_258 -> V_180 = V_259 ;
V_258 -> V_260 = V_107 ;
V_258 -> V_261 = V_262 ;
V_258 -> V_263 = V_264 ;
V_258 -> V_265 = V_266 ;
V_258 -> V_267 = V_99 ;
V_258 -> V_268 = V_101 ;
V_258 -> V_269 = V_248 . V_169 ?
( 1UL << ( V_248 . V_169 + V_248 . V_252 ) ) - 1 :
( 1UL << V_42 . V_45 ) - 1 ;
V_21 . V_25 = F_67 ( V_26 ) ;
V_258 -> V_270 =
( V_21 . V_29 . V_21 & ~ ( ( 1 << V_248 . V_252 ) - 1 ) ) >> 1 ;
V_258 -> V_271 =
( ( unsigned long ) V_258 -> V_270 << V_248 . V_169 ) ;
if ( V_272 ) {
V_258 -> V_273 = V_272 -> V_274 ;
V_258 -> V_275 = V_272 -> V_276 ;
V_258 -> V_277 = V_272 -> V_278 ;
V_258 -> V_279 = V_272 -> V_280 ;
V_258 -> V_45 = V_272 -> V_45 ;
V_258 -> V_269 = ( 1UL << V_258 -> V_45 ) - 1 ;
} else {
V_258 -> V_273 =
F_67 ( V_178 ) &
~ V_281 ;
V_258 -> V_275 = V_282 ;
}
F_66 (
& V_258 -> V_283 , & V_258 -> V_284 ) ;
V_258 -> V_285 = V_42 . V_58 ;
F_12 ( L_39 ,
V_258 -> V_252 , V_258 -> V_169 ,
V_258 -> V_256 , V_258 -> V_253 ) ;
F_12 ( L_40 ,
V_258 -> V_269 , V_258 -> V_45 ,
V_258 -> V_43 , V_258 -> V_285 ) ;
F_12 ( L_41 ,
V_258 -> V_273 , V_258 -> V_275 ,
V_258 -> V_277 , V_258 -> V_279 ) ;
F_12 ( L_42 ,
V_258 -> V_271 , V_258 -> V_270 ) ;
}
static void T_1 F_109 ( unsigned long V_286 )
{
V_272 = (struct V_287 * ) V_286 ;
F_12 ( L_43 ) ;
F_12 ( L_44 ,
V_272 -> V_274 , V_272 -> V_276 ,
V_272 -> V_278 , V_272 -> V_280 ,
V_272 -> V_45 ) ;
}
static void T_1 F_110 ( unsigned long V_286 )
{
struct V_88 * V_89 = (struct V_88 * ) V_286 ;
unsigned long V_288 = 0 ;
int V_179 = 0 ;
int V_289 = 999999 , V_290 = 99999 ;
int V_291 = - 1 , V_292 = - 1 ;
V_90 = V_89 ;
for (; V_89 -> type != V_102 ; V_89 ++ ) {
if ( ! V_179 ) {
F_12 ( L_45 ) ;
F_12 ( L_46 ,
L_47 , L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 ) ;
}
F_12 (
L_55 ,
V_179 ++ ,
( unsigned long ) V_288 << V_112 ,
( unsigned long ) V_89 -> V_104 << V_112 ,
( ( unsigned long ) ( V_89 -> V_104 - V_288 ) ) >>
( 30 - V_112 ) ,
V_89 -> type , V_89 -> V_109 , V_89 -> V_106 ,
V_89 -> V_24 , V_89 -> V_293 ) ;
V_288 = V_89 -> V_104 ;
if ( V_289 > V_89 -> V_106 )
V_289 = V_89 -> V_106 ;
if ( V_291 < V_89 -> V_106 )
V_291 = V_89 -> V_106 ;
if ( V_290 > V_89 -> V_24 )
V_290 = V_89 -> V_24 ;
if ( V_292 < V_89 -> V_24 )
V_292 = V_89 -> V_24 ;
}
V_107 = V_289 ;
V_105 = V_291 ;
V_259 = V_290 ;
V_294 = V_292 ;
V_99 = V_179 ;
F_12 (
L_56 ,
V_179 , V_107 , V_105 , V_259 , V_294 ) ;
}
static void T_1 F_111 ( void )
{
struct V_295 * V_296 ;
int V_96 ;
V_296 = V_295 ;
if ( ( ! V_296 || V_296 -> V_30 < V_297 ) && ! F_81 () )
return;
if ( V_296 -> V_30 != V_298 ) {
F_4 (
L_57 ,
V_296 -> V_30 , V_298 ) ;
F_26 () ;
}
for ( V_96 = 0 ; V_296 -> V_299 [ V_96 ] . type != V_300 ; V_96 ++ ) {
unsigned long V_286 = V_296 -> V_299 [ V_96 ] . V_301 ;
if ( ! V_286 )
continue;
V_286 = V_286 + ( unsigned long ) V_296 ;
switch ( V_296 -> V_299 [ V_96 ] . type ) {
case V_302 :
F_109 ( V_286 ) ;
break;
case V_303 :
F_110 ( V_286 ) ;
break;
}
}
}
static T_1 void F_112 ( struct V_257 * V_258 )
{
int V_96 , V_304 = 0 ;
F_12 ( L_58 , V_305 ) ;
for ( V_96 = 0 ; V_96 < V_305 ; V_96 ++ ) {
unsigned long V_306 ;
V_306 = F_67 ( V_307 + V_96 * 8 ) ;
if ( V_306 )
F_12 ( L_59 , V_96 , V_306 ) ;
V_304 += F_113 ( V_306 ) ;
}
if ( V_308 != V_304 )
V_308 = V_304 ;
}
static void T_1 F_114 ( void )
{
struct V_88 * V_89 = V_90 ;
int V_309 , V_310 ;
int V_121 , V_96 , V_311 ;
int V_312 = V_107 ;
int V_313 = V_105 ;
int V_314 = V_259 ;
int V_315 = V_294 ;
T_4 V_95 ;
if ( ! V_89 ) {
if ( F_22 () || F_19 () || F_20 () ) {
F_12 ( L_60 ) ;
return;
}
F_4 (
L_61 ) ;
F_26 () ;
}
V_309 = V_313 - V_312 + 1 ;
V_95 = V_309 * sizeof( V_264 [ 0 ] ) ;
V_264 = F_115 ( V_95 , V_100 ) ;
V_266 = F_115 ( V_95 , V_100 ) ;
V_310 = V_315 - V_314 + 1 ;
V_95 = V_310 * sizeof( V_262 [ 0 ] ) ;
V_262 = F_115 ( V_95 , V_100 ) ;
F_32 ( ! V_264 || ! V_266 || ! V_262 ) ;
for ( V_96 = 0 ; V_96 < V_309 ; V_96 ++ )
V_264 [ V_96 ] = V_266 [ V_96 ] = V_316 ;
for ( V_96 = 0 ; V_96 < V_310 ; V_96 ++ )
V_262 [ V_96 ] = V_316 ;
F_12 ( L_62 ) ;
for (; V_89 -> type != V_102 ; V_89 ++ ) {
if ( V_89 -> type == V_103 )
continue;
V_96 = V_89 -> V_106 - V_312 ;
if ( V_266 [ V_96 ] != V_316 )
continue;
V_266 [ V_96 ] = V_89 -> V_24 ;
V_264 [ V_96 ] = V_89 -> V_293 ;
V_96 = V_89 -> V_24 - V_314 ;
V_262 [ V_96 ] = V_89 -> V_106 ;
F_12 (
L_63 ,
V_89 -> V_106 , V_89 -> type , V_89 -> V_109 ,
V_266 [ V_89 -> V_106 - V_312 ] ,
V_264 [ V_89 -> V_106 - V_312 ] ,
V_262 [ V_89 -> V_24 - V_314 ] ) ;
}
V_311 = - 1 ;
F_116 (cpu) {
int V_167 = F_117 ( V_121 ) ;
int V_123 , V_106 ;
if ( V_311 == V_167 )
continue;
V_311 = V_167 ;
V_123 = F_38 ( V_124 , V_121 ) ;
V_106 = V_123 >> V_42 . V_58 ;
V_96 = V_106 - V_312 ;
if ( V_167 != V_264 [ V_96 ] ) {
F_118 (
L_64 ,
V_96 , V_106 , V_89 -> type , V_264 [ V_96 ] , V_167 ) ;
V_264 [ V_96 ] = V_167 ;
}
}
V_95 = F_119 () * sizeof( V_317 [ 0 ] ) ;
V_317 = F_115 ( V_95 , V_100 ) ;
F_32 ( ! V_317 ) ;
for ( V_311 = 0 ; V_311 < F_119 () ; V_311 ++ ) {
unsigned short V_106 ;
for ( V_106 = V_312 ; V_106 <= V_313 ; V_106 ++ ) {
if ( V_311 == V_264 [ V_106 - V_312 ] ) {
V_317 [ V_311 ] =
V_266 [ V_106 - V_312 ] ;
break;
}
}
if ( V_106 > V_313 ) {
F_25 ( L_65 , V_311 ) ;
F_26 () ;
}
}
F_12 ( L_66 ) ;
if ( V_312 == 0 ) {
for ( V_96 = 0 ; V_96 < V_309 ; V_96 ++ )
if ( V_264 [ V_96 ] == V_316 ||
V_96 != V_264 [ V_96 ] )
break;
if ( V_96 >= V_309 ) {
F_120 ( V_264 ) ;
V_264 = NULL ;
F_12 ( L_67 ) ;
}
}
if ( V_312 == V_314 ) {
for ( V_96 = 0 ; V_96 < V_309 ; V_96 ++ )
if ( V_266 [ V_96 ] != V_316 &&
V_266 [ V_96 ] != V_96 + V_314 )
break;
if ( V_96 >= V_309 ) {
F_120 ( V_266 ) ;
V_266 = NULL ;
F_12 ( L_68 ) ;
}
}
}
void T_1 F_121 ( void )
{
struct V_257 V_258 = { 0 } ;
int V_95 , V_121 , V_318 ;
unsigned short V_180 = 9999 , V_160 = 0 ;
char * V_319 = F_81 () ? L_69 :
F_20 () ? L_70 :
F_19 () ? L_71 :
F_22 () ? L_72 : NULL ;
if ( ! V_319 ) {
F_25 ( L_73 ) ;
return;
}
F_12 ( L_74 , V_319 ) ;
F_82 () ;
F_122 () ;
F_111 () ;
F_114 () ;
F_30 () ;
F_108 ( & V_258 ) ;
V_308 = F_119 () ;
if ( ! V_317 )
F_112 ( & V_258 ) ;
F_12 ( L_75 ,
F_123 () ,
F_119 () ,
F_124 () ) ;
F_125 ( 0 , & V_320 , & V_321 , & V_322 ,
& V_323 , & V_324 ) ;
V_258 . V_325 = V_322 ;
F_83 () ;
V_95 = sizeof( void * ) * F_123 () ;
V_326 = F_31 ( V_95 , V_100 ) ;
F_32 ( ! V_326 ) ;
V_95 = sizeof( struct V_257 ) ;
F_126 (nodeid) {
struct V_257 * V_327 ;
if ( V_326 [ V_318 ] ) {
F_25 ( L_76 ,
V_318 ) ;
F_26 () ;
}
V_327 = ( V_318 == 0 ) ?
& V_73 :
F_127 ( V_95 , V_100 , V_318 ) ;
F_32 ( ! V_327 ) ;
V_326 [ V_318 ] = V_327 ;
V_327 = F_128 ( V_318 ) ;
F_32 ( ! V_327 ) ;
* V_327 = V_258 ;
if ( V_317 )
V_327 -> V_24 = V_317 [ V_318 ] ;
else
V_327 -> V_24 = 0xffff ;
V_327 -> V_328 = F_129 ( V_318 ) ;
V_327 -> V_329 = - 1 ;
V_327 -> V_330 = 0 ;
V_327 -> V_247 = 0 ;
}
F_130 (cpu) {
int V_123 = F_38 ( V_124 , V_121 ) ;
int V_331 ;
unsigned short V_24 ;
V_318 = F_117 ( V_121 ) ;
V_331 = F_131 ( V_121 ) ;
V_24 = F_35 ( V_123 ) ;
F_132 ( V_121 ) -> V_72 = F_128 ( V_318 ) ;
F_132 ( V_121 ) -> V_332 =
F_133 ( V_121 ) -> V_330 ++ ;
if ( F_133 ( V_121 ) -> V_329 == - 1 )
F_133 ( V_121 ) -> V_329 = F_117 ( V_121 ) ;
if ( V_318 != V_331 &&
F_128 ( V_331 ) -> V_24 == 0xffff )
F_128 ( V_331 ) -> V_24 = V_24 ;
else if ( F_133 ( V_121 ) -> V_24 == 0xffff )
F_133 ( V_121 ) -> V_24 = V_24 ;
F_92 ( V_121 ) -> V_301 = F_134 ( V_123 ) ;
}
F_126 (nodeid) {
unsigned short V_24 = F_128 ( V_318 ) -> V_24 ;
if ( V_24 == 0xffff ) {
unsigned long V_162 ;
V_162 = F_135 ( V_318 ) << V_333 ;
V_24 = F_136 ( F_137 ( V_162 ) ) ;
F_128 ( V_318 ) -> V_24 = V_24 ;
}
V_180 = F_75 ( V_24 , V_180 ) ;
V_160 = F_76 ( V_24 , V_160 ) ;
F_12 ( L_77 ,
V_318 ,
F_128 ( V_318 ) -> V_24 ,
F_128 ( V_318 ) -> V_330 ) ;
}
F_12 ( L_78 , V_180 , V_160 ) ;
F_77 ( V_160 ) ;
F_78 ( V_160 ) ;
F_80 ( V_180 , V_160 ) ;
F_138 () ;
F_106 () ;
F_99 () ;
F_139 ( L_79 , NULL ) ;
F_140 ( F_102 ) ;
if ( F_141 () )
V_334 = V_335 ;
}
