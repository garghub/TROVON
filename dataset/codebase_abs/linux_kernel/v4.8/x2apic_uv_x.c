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
if ( V_71 ) {
F_24 ( L_8 ) ;
return 0 ;
}
V_72 -> V_73 = & V_74 ;
V_40 -> V_41 =
! strncmp ( V_67 , L_9 , 4 ) ? V_39 :
! strncmp ( V_67 , L_10 , 4 ) ? V_37 :
! strcmp ( V_67 , L_11 ) ? V_34 :
! strcmp ( V_67 , L_7 ) ? V_75 : 0 ;
if ( V_40 -> V_41 == 0 )
goto V_76;
V_69 = F_11 () ;
F_18 () ;
V_77 . V_78 = F_9 ;
V_77 . V_79 = V_80 ;
if ( ! strcmp ( V_68 , L_12 ) ) {
V_81 = V_82 ;
V_70 = 0 ;
} else if ( ! strcmp ( V_68 , L_13 ) ) {
V_81 = V_83 ;
F_25 ( V_84 ,
V_69 << V_59 . V_29 . V_85 ) ;
F_21 () ;
V_70 = 1 ;
} else if ( ! strcmp ( V_68 , L_14 ) ) {
V_81 = V_86 ;
V_70 = 0 ;
} else {
goto V_76;
}
F_12 ( L_15 ,
V_67 , V_68 , V_81 ,
V_28 , V_70 ) ;
return V_70 ;
V_76:
F_24 ( L_16 , V_67 , V_68 ) ;
F_24 ( L_17 ) ;
F_26 () ;
}
enum V_81 F_27 ( void )
{
return V_81 ;
}
int F_28 ( void )
{
return V_81 != V_87 ;
}
extern int F_29 ( void )
{
return V_88 ;
}
static T_1 void F_30 ( void )
{
struct V_89 * V_90 = V_91 ;
struct V_92 * V_93 ;
unsigned long V_94 = 0 , V_95 = 0 ;
int V_96 , V_97 , V_98 , V_99 = - 1 , V_100 = 0 , V_101 = - 1 ;
if ( ! V_90 )
return;
V_96 = V_102 * sizeof( struct V_92 ) ;
V_93 = F_31 ( V_96 , V_103 ) ;
F_32 ( ! V_93 ) ;
V_104 = V_93 ;
for (; V_90 -> type != V_105 ; V_90 ++ ) {
if ( V_90 -> type == V_106 ) {
if ( ! V_95 ) {
V_95 = V_94 ;
V_94 = V_90 -> V_107 ;
V_99 ++ ;
continue;
}
V_94 = V_90 -> V_107 ;
F_12 ( L_18 ,
( int ) ( V_90 - V_91 ) ) ;
continue;
}
if ( V_108 < V_90 -> V_109 ) {
F_24 ( L_19 ,
V_90 -> V_109 , V_108 ,
( int ) ( V_90 - V_91 ) ) ;
continue;
}
V_98 = V_90 -> V_109 - V_110 ;
if ( V_99 < V_98 ) {
V_93 = & V_104 [ V_100 ] ;
V_93 -> V_111 = V_101 ;
V_93 -> V_112 = V_90 -> V_112 ;
V_93 -> V_107 = V_94 = V_90 -> V_107 ;
V_99 = V_98 ;
V_101 = V_100 ++ ;
continue;
}
if ( V_99 == V_98 && ! V_95 ) {
if ( V_93 -> V_107 == V_94 ) {
V_93 -> V_107 = V_94 = V_90 -> V_107 ;
continue;
}
}
if ( ! V_95 ) {
V_93 ++ ;
V_93 -> V_111 = V_101 ;
V_93 -> V_112 = V_90 -> V_112 ;
V_93 -> V_107 = V_94 = V_90 -> V_107 ;
continue;
}
V_93 ++ ;
V_93 -> V_111 = V_93 - V_104 ;
V_93 -> V_112 = V_90 -> V_112 ;
V_93 -> V_107 = V_94 = V_90 -> V_107 ;
V_99 ++ ;
}
V_93 ++ ;
V_97 = V_93 - V_104 ;
if ( V_97 < V_102 ) {
void * V_113 ;
V_96 = V_97 * sizeof( struct V_92 ) ;
V_113 = F_33 ( V_104 , V_96 , V_103 ) ;
if ( V_113 ) {
V_104 = V_113 ;
V_102 = V_97 ;
}
}
for ( V_97 = 0 , V_93 = V_104 ; V_97 < V_102 ; V_97 ++ , V_93 ++ ) {
int V_114 = V_93 -> V_111 ;
unsigned long V_7 = V_114 < 0 ? 0 :
( unsigned long ) V_104 [ V_114 ] . V_107 << V_115 ;
unsigned long V_8 =
( unsigned long ) V_93 -> V_107 << V_115 ;
F_12 ( L_20 ,
V_97 , V_93 -> V_112 , V_7 , V_8 , V_114 ) ;
}
}
static int F_34 ( int V_116 , unsigned long V_117 )
{
unsigned long V_4 ;
int V_24 ;
V_24 = F_35 ( V_116 ) ;
V_116 |= V_63 ;
V_4 = ( 1UL << V_118 ) |
( V_116 << V_119 ) |
( ( V_117 << V_120 ) >> 12 ) |
V_121 ;
F_36 ( V_24 , V_122 , V_4 ) ;
V_4 = ( 1UL << V_118 ) |
( V_116 << V_119 ) |
( ( V_117 << V_120 ) >> 12 ) |
V_123 ;
F_36 ( V_24 , V_122 , V_4 ) ;
return 0 ;
}
static void F_37 ( int V_124 , int V_125 )
{
unsigned long V_126 ;
int V_24 ;
V_126 = F_38 ( V_127 , V_124 ) ;
V_24 = F_35 ( V_126 ) ;
F_39 ( V_24 , V_126 , V_125 ) ;
}
static void F_40 ( const struct V_128 * V_129 , int V_125 )
{
unsigned int V_124 ;
F_41 (cpu, mask)
F_37 ( V_124 , V_125 ) ;
}
static void F_42 ( const struct V_128 * V_129 , int V_125 )
{
unsigned int V_130 = F_43 () ;
unsigned int V_124 ;
F_41 (cpu, mask) {
if ( V_124 != V_130 )
F_37 ( V_124 , V_125 ) ;
}
}
static void F_44 ( int V_125 )
{
unsigned int V_130 = F_43 () ;
unsigned int V_124 ;
F_45 (cpu) {
if ( V_124 != V_130 )
F_37 ( V_124 , V_125 ) ;
}
}
static void F_46 ( int V_125 )
{
F_40 ( V_131 , V_125 ) ;
}
static int F_47 ( int V_126 )
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
F_50 ( const struct V_128 * V_128 ,
const struct V_128 * V_132 ,
unsigned int * V_126 )
{
int unsigned V_124 ;
F_51 (cpu, cpumask, andmask) {
if ( F_52 ( V_124 , V_131 ) )
break;
}
if ( F_2 ( V_124 < V_133 ) ) {
* V_126 = F_38 ( V_127 , V_124 ) | V_63 ;
return 0 ;
}
return - V_134 ;
}
static unsigned int F_53 ( unsigned long V_135 )
{
unsigned int V_136 ;
F_54 ( F_55 () && F_56 () > 1 ) ;
V_136 = V_135 | F_57 ( V_84 ) ;
return V_136 ;
}
static unsigned long F_58 ( unsigned int V_136 )
{
unsigned long V_135 ;
V_135 = V_136 ;
return V_135 ;
}
static unsigned int F_59 ( void )
{
return F_53 ( F_60 ( V_137 ) ) ;
}
static int F_61 ( int V_138 , int V_139 )
{
return F_59 () >> V_139 ;
}
static void F_62 ( int V_125 )
{
F_63 ( V_140 , V_125 ) ;
}
static int F_64 ( void )
{
return V_141 == & V_142 ;
}
static void F_65 ( int V_24 )
{
F_25 ( V_84 , V_24 << V_59 . V_29 . V_85 ) ;
}
static T_1 void F_66 ( unsigned long * V_111 , unsigned long * V_143 )
{
union V_144 V_145 ;
union V_146 V_147 ;
unsigned long V_148 ;
unsigned long V_149 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_150 ; V_97 ++ ) {
switch ( V_97 ) {
case 0 :
V_148 = V_151 ;
V_149 = V_152 ;
break;
case 1 :
V_148 = V_153 ;
V_149 = V_154 ;
break;
case 2 :
V_148 = V_155 ;
V_149 = V_156 ;
break;
}
V_145 . V_25 = F_67 ( V_149 ) ;
if ( V_145 . V_29 . V_157 && V_145 . V_29 . V_111 == 0 ) {
* V_143 = ( 1UL << V_145 . V_29 . V_158 ) ;
V_147 . V_25 = F_67 ( V_148 ) ;
* V_111 = ( unsigned long ) V_147 . V_29 . V_159
<< V_160 ;
return;
}
}
* V_111 = * V_143 = 0 ;
}
static T_1 void F_68 ( char * V_136 , unsigned long V_111 , int V_161 ,
int V_162 , int V_163 , enum V_164 V_164 )
{
unsigned long V_96 , V_165 ;
V_165 = V_111 << V_161 ;
V_96 = ( 1UL << V_162 ) * ( V_163 + 1 ) ;
if ( ! V_165 ) {
F_12 ( L_21 , V_136 ) ;
return;
}
F_69 ( L_22 , V_136 , V_165 , V_165 + V_96 ) ;
if ( V_164 == V_166 )
F_70 ( V_165 , V_96 ) ;
else
F_71 ( V_165 , V_96 ) ;
}
static T_1 void F_72 ( unsigned long V_167 )
{
union V_168 V_169 ;
T_2 V_165 ;
unsigned long V_96 ;
int V_170 ;
V_169 . V_25 = V_167 ;
V_9 = V_169 . V_25 & 0x000007fff0000000UL ;
if ( ! V_9 ) {
F_12 ( L_23 ) ;
return;
}
V_96 = 1UL << V_171 ;
V_13 = ( ( 1UL << V_40 -> V_172 ) - 1 ) & ~ ( V_96 - 1 ) ;
V_11 = ~ ( ( 1UL << V_40 -> V_172 ) - 1 ) ;
V_9 &= V_13 ;
F_73 (nid) {
V_165 = ( ( T_2 ) F_74 ( V_170 ) << V_40 -> V_172 ) |
V_9 ;
F_71 ( V_165 , V_96 ) ;
V_16 = F_75 ( V_165 , V_16 ) ;
V_17 = F_76 ( V_165 , V_17 ) ;
}
V_16 &= V_11 ;
V_17 &= V_11 ;
F_69 ( L_24 ,
V_9 , V_16 , V_17 ) ;
}
static T_1 void F_77 ( int V_163 )
{
union V_168 V_169 ;
int V_173 = V_171 ;
unsigned long V_129 = V_174 ;
unsigned long V_111 ;
V_169 . V_25 = F_67 ( V_175 ) ;
if ( ! V_169 . V_29 . V_157 ) {
F_12 ( L_25 ) ;
return;
}
if ( F_20 () && V_169 . V_176 . V_177 ) {
F_72 ( V_169 . V_25 ) ;
return;
}
V_111 = ( V_169 . V_25 & V_129 ) >> V_173 ;
F_68 ( L_26 , V_111 , V_173 , V_173 , V_163 , V_178 ) ;
V_18 = ( ( T_2 ) V_111 << V_173 ) ;
V_19 = V_18 + ( 1UL << V_173 ) * ( V_163 + 1 ) ;
}
static T_1 void F_78 ( int V_163 )
{
union V_179 V_5 ;
int V_173 = V_180 ;
V_5 . V_25 = F_67 ( V_181 ) ;
if ( V_5 . V_29 . V_157 )
F_68 ( L_27 , V_5 . V_29 . V_111 , V_173 , V_173 , V_163 , V_166 ) ;
else
F_12 ( L_28 ) ;
}
static T_1 void F_79 ( int V_182 , int V_183 , int V_163 )
{
union V_184 V_185 ;
unsigned long V_5 ;
unsigned long V_111 ;
int V_97 , V_186 , V_173 , V_187 , V_188 ;
int V_112 , V_189 , V_190 , V_191 ;
char * V_136 ;
V_136 = V_192 [ V_182 ] . V_136 ;
V_185 . V_25 = F_67 ( V_192 [ V_182 ] . V_185 ) ;
F_12 ( L_29 ,
V_136 , V_185 . V_25 , V_185 . V_176 . V_111 , V_185 . V_176 . V_187 ) ;
if ( ! V_185 . V_176 . V_157 ) {
F_12 ( L_30 , V_136 ) ;
return;
}
V_173 = V_193 ;
V_111 = ( unsigned long ) V_185 . V_176 . V_111 ;
V_187 = V_185 . V_176 . V_187 ;
V_5 = V_192 [ V_182 ] . V_147 ;
V_186 = V_194 ;
V_183 *= 2 ;
V_163 *= 2 ;
V_188 = V_189 = V_190 = V_191 = - 1 ;
for ( V_97 = 0 ; V_97 < V_186 ; V_97 ++ ) {
union V_195 V_147 ;
V_147 . V_25 = F_67 ( V_5 + V_97 * 8 ) ;
V_112 = V_147 . V_176 . V_112 ;
if ( V_112 < V_183 || V_163 < V_112 )
V_112 = - 1 ;
if ( V_112 == V_189 ) {
V_191 = V_97 ;
if ( V_97 != V_186 - 1 )
continue;
}
if ( V_189 != - 1 || ( V_97 == V_186 - 1 && V_112 != - 1 ) ) {
unsigned long V_196 , V_197 ;
int V_198 , V_199 ;
if ( V_189 == - 1 ) {
V_198 = V_199 = V_97 ;
V_189 = V_112 ;
} else {
V_198 = V_190 ;
V_199 = V_191 ;
}
V_196 = ( V_111 << V_173 ) +
V_198 * ( unsigned long ) ( 1 << V_187 ) ;
V_197 = ( V_111 << V_173 ) +
( V_199 + 1 ) * ( unsigned long ) ( 1 << V_187 ) ;
F_12 ( L_31 ,
V_136 , V_190 , V_191 , V_189 , V_196 , V_197 ) ;
if ( V_188 < V_199 )
V_188 = V_199 ;
}
V_190 = V_191 = V_97 ;
V_189 = V_112 ;
}
F_12 ( L_32 ,
V_136 , V_111 , V_173 , V_187 , V_188 ) ;
if ( V_188 >= 0 )
F_68 ( V_136 , V_111 , V_173 , V_187 , V_188 , V_166 ) ;
}
static T_1 void F_80 ( int V_183 , int V_163 )
{
union V_200 V_201 ;
unsigned long V_5 , V_111 ;
int V_173 , V_157 , V_187 , V_202 ;
if ( F_20 () || F_81 () ) {
F_79 ( 0 , V_183 , V_163 ) ;
F_79 ( 1 , V_183 , V_163 ) ;
return;
}
if ( F_22 () ) {
V_5 = V_203 ;
V_173 = V_204 ;
V_201 . V_25 = F_67 ( V_5 ) ;
V_157 = ! ! V_201 . V_64 . V_157 ;
V_111 = V_201 . V_64 . V_111 ;
V_187 = V_201 . V_64 . V_187 ;
V_202 = V_201 . V_64 . V_202 ;
} else if ( F_19 () ) {
V_5 = V_205 ;
V_173 = V_206 ;
V_201 . V_25 = F_67 ( V_5 ) ;
V_157 = ! ! V_201 . V_207 . V_157 ;
V_111 = V_201 . V_207 . V_111 ;
V_187 = V_201 . V_207 . V_187 ;
V_202 = V_201 . V_207 . V_202 ;
} else
return;
if ( V_157 ) {
V_163 &= ( 1 << V_202 ) - 1 ;
F_12 (
L_33 ,
V_111 , V_173 , V_187 , V_202 , V_163 ) ;
F_68 ( L_34 , V_111 , V_173 , V_187 , V_163 , V_166 ) ;
} else {
F_12 ( L_35 ) ;
}
}
static T_1 void F_82 ( void )
{
F_70 ( V_208 , V_209 ) ;
F_70 ( V_6 , V_210 ) ;
}
static T_1 void F_83 ( void )
{
long V_211 ;
T_2 V_212 ;
V_211 = F_84 ( V_213 ,
& V_212 ) ;
if ( V_211 != V_214 || V_212 < 100000 ) {
F_85 ( V_215
L_36
L_37 ) ;
V_216 = 1000000000000UL / 30000UL ;
} else
V_216 = V_212 ;
}
static void F_86 ( unsigned long V_217 )
{
struct V_218 * V_219 = & V_220 -> V_219 ;
unsigned char V_221 = V_220 -> V_222 ;
V_221 ^= V_223 ;
if ( F_87 ( F_88 () ) )
V_221 &= ~ V_224 ;
else
V_221 |= V_224 ;
F_89 ( V_221 ) ;
F_90 ( V_219 , V_225 + V_226 ) ;
}
static void F_91 ( int V_124 )
{
while ( ! F_92 ( V_124 ) -> V_227 ) {
struct V_218 * V_219 = & F_92 ( V_124 ) -> V_219 ;
F_93 ( V_124 , V_223 | V_224 ) ;
F_94 ( V_219 , F_86 , V_124 ) ;
V_219 -> V_228 = V_225 + V_226 ;
F_95 ( V_219 , V_124 ) ;
F_92 ( V_124 ) -> V_227 = 1 ;
V_124 = 0 ;
}
}
static void F_96 ( int V_124 )
{
if ( F_92 ( V_124 ) -> V_227 ) {
F_92 ( V_124 ) -> V_227 = 0 ;
F_97 ( & F_92 ( V_124 ) -> V_219 ) ;
}
F_93 ( V_124 , 0xff ) ;
}
static int F_98 ( struct V_229 * V_230 , unsigned long V_231 ,
void * V_232 )
{
long V_124 = ( long ) V_232 ;
switch ( V_231 & ~ V_233 ) {
case V_234 :
case V_235 :
F_91 ( V_124 ) ;
break;
case V_236 :
F_96 ( V_124 ) ;
break;
default:
break;
}
return V_237 ;
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
int V_124 ;
if ( F_28 () )
F_45 (cpu)
F_91 ( V_124 ) ;
return 0 ;
}
int F_102 ( struct V_238 * V_239 , bool V_240 ,
unsigned int V_241 , T_3 V_242 )
{
int V_243 , V_244 , V_245 ;
F_103 ( L_38 ,
V_239 -> V_246 , V_240 , V_241 , V_242 ) ;
if ( ! ( V_242 & V_247 ) )
return 0 ;
if ( ( V_241 & V_248 ) == 0 )
return 0 ;
V_243 = F_104 ( V_239 -> V_244 ) ;
V_244 = V_239 -> V_244 -> V_249 ;
V_245 = F_105 ( V_240 , V_243 , V_244 ) ;
F_103 ( L_39 , V_240 , V_243 , V_244 , V_245 ) ;
return V_245 ;
}
void F_106 ( void )
{
if ( F_43 () == 0 )
return;
V_40 -> V_250 ++ ;
if ( F_27 () == V_83 )
F_65 ( V_40 -> V_24 ) ;
}
static void F_107 ( struct V_251 * V_252 )
{
union V_22 V_23 ;
union V_253 V_254 ;
V_23 . V_25 = F_67 ( V_27 ) ;
V_252 -> V_255 = V_23 . V_29 . V_44 ;
if ( F_81 () ) {
V_252 -> V_172 = 0 ;
V_252 -> V_256 = 0 ;
} else if ( F_20 () ) {
V_252 -> V_172 = V_23 . V_176 . V_257 ;
V_254 . V_25 = F_67 ( V_258 ) ;
V_252 -> V_256 = V_254 . V_176 . V_257 ;
} else if ( F_19 () ) {
V_252 -> V_172 = V_23 . V_207 . V_257 ;
V_252 -> V_256 = V_252 -> V_172 == 40 ? 40 : 39 ;
} else if ( F_22 () ) {
V_252 -> V_172 = V_23 . V_64 . V_257 ;
V_252 -> V_256 = V_252 -> V_172 ;
}
V_252 -> V_259 = V_252 -> V_172 ? 64 - V_252 -> V_172 : 0 ;
}
void T_1 F_108 ( struct V_260 * V_261 )
{
struct V_251 V_251 = { 0 } ;
union V_20 V_21 ;
F_107 ( & V_251 ) ;
V_261 -> V_172 = V_251 . V_172 ;
V_261 -> V_255 = V_251 . V_255 ;
V_261 -> V_259 = V_251 . V_259 ;
V_261 -> V_256 = V_251 . V_256 ? V_251 . V_256 : 0 ;
V_261 -> V_41 = V_40 -> V_41 ;
V_261 -> V_43 = V_42 . V_43 ;
V_261 -> V_183 = V_262 ;
V_261 -> V_263 = V_110 ;
V_261 -> V_264 = V_265 ;
V_261 -> V_266 = V_267 ;
V_261 -> V_268 = V_269 ;
V_261 -> V_270 = V_102 ;
V_261 -> V_271 = V_104 ;
V_261 -> V_272 = V_251 . V_172 ?
( 1UL << ( V_251 . V_172 + V_251 . V_255 ) ) - 1 :
( 1UL << V_42 . V_45 ) - 1 ;
V_21 . V_25 = F_67 ( V_26 ) ;
V_261 -> V_273 =
( V_21 . V_29 . V_21 & ~ ( ( 1 << V_251 . V_255 ) - 1 ) ) >> 1 ;
V_261 -> V_274 =
( ( unsigned long ) V_261 -> V_273 << V_251 . V_172 ) ;
if ( V_275 ) {
V_261 -> V_276 = V_275 -> V_277 ;
V_261 -> V_278 = V_275 -> V_279 ;
V_261 -> V_280 = V_275 -> V_281 ;
V_261 -> V_282 = V_275 -> V_283 ;
V_261 -> V_45 = V_275 -> V_45 ;
V_261 -> V_272 = ( 1UL << V_261 -> V_45 ) - 1 ;
} else {
V_261 -> V_276 =
F_67 ( V_181 ) &
~ V_284 ;
V_261 -> V_278 = V_285 ;
}
F_66 (
& V_261 -> V_286 , & V_261 -> V_287 ) ;
V_261 -> V_288 = V_42 . V_58 ;
F_12 ( L_40 ,
V_261 -> V_255 , V_261 -> V_172 ,
V_261 -> V_259 , V_261 -> V_256 ) ;
F_12 ( L_41 ,
V_261 -> V_272 , V_261 -> V_45 ,
V_261 -> V_43 , V_261 -> V_288 ) ;
F_12 ( L_42 ,
V_261 -> V_276 , V_261 -> V_278 ,
V_261 -> V_280 , V_261 -> V_282 ) ;
F_12 ( L_43 ,
V_261 -> V_274 , V_261 -> V_273 ) ;
}
static void T_1 F_109 ( unsigned long V_289 )
{
V_275 = (struct V_290 * ) V_289 ;
F_12 ( L_44 ) ;
F_12 ( L_45 ,
V_275 -> V_277 , V_275 -> V_279 ,
V_275 -> V_281 , V_275 -> V_283 ,
V_275 -> V_45 ) ;
}
static void T_1 F_110 ( unsigned long V_289 )
{
struct V_89 * V_90 = (struct V_89 * ) V_289 ;
unsigned long V_291 = 0 ;
int V_182 = 0 ;
int V_292 = 999999 , V_293 = 99999 ;
int V_294 = - 1 , V_295 = - 1 ;
V_91 = V_90 ;
for (; V_90 -> type != V_105 ; V_90 ++ ) {
if ( ! V_182 ) {
F_12 ( L_46 ) ;
F_12 ( L_47 ,
L_48 , L_49 , L_50 , L_51 , L_52 ,
L_53 , L_54 ) ;
}
F_12 (
L_55 ,
V_182 ++ ,
( unsigned long ) V_291 << V_115 ,
( unsigned long ) V_90 -> V_107 << V_115 ,
( ( unsigned long ) ( V_90 -> V_107 - V_291 ) ) >>
( 30 - V_115 ) ,
V_90 -> type , V_90 -> V_112 , V_90 -> V_109 , V_90 -> V_24 ) ;
V_291 = V_90 -> V_107 ;
if ( V_292 > V_90 -> V_109 )
V_292 = V_90 -> V_109 ;
if ( V_294 < V_90 -> V_109 )
V_294 = V_90 -> V_109 ;
if ( V_293 > V_90 -> V_24 )
V_293 = V_90 -> V_24 ;
if ( V_295 < V_90 -> V_24 )
V_295 = V_90 -> V_24 ;
}
V_110 = V_292 ;
V_108 = V_294 ;
V_262 = V_293 ;
V_296 = V_295 ;
V_102 = V_182 ;
F_12 (
L_56 ,
V_182 , V_110 , V_108 , V_262 , V_296 ) ;
}
static void T_1 F_111 ( void )
{
struct V_297 * V_298 ;
int V_97 ;
V_298 = V_297 ;
if ( ( ! V_298 || V_298 -> V_30 < V_299 ) && ! F_81 () )
return;
if ( V_298 -> V_30 != V_300 ) {
F_4 (
L_57 ,
V_298 -> V_30 , V_300 ) ;
F_26 () ;
}
for ( V_97 = 0 ; V_298 -> V_301 [ V_97 ] . type != V_302 ; V_97 ++ ) {
unsigned long V_289 = V_298 -> V_301 [ V_97 ] . V_303 ;
if ( ! V_289 )
continue;
V_289 = V_289 + ( unsigned long ) V_298 ;
switch ( V_298 -> V_301 [ V_97 ] . type ) {
case V_304 :
F_109 ( V_289 ) ;
break;
case V_305 :
F_110 ( V_289 ) ;
break;
}
}
}
static T_1 void F_112 ( struct V_260 * V_261 )
{
int V_97 , V_306 = 0 ;
F_12 ( L_58 , V_307 ) ;
for ( V_97 = 0 ; V_97 < V_307 ; V_97 ++ ) {
unsigned long V_308 ;
V_308 = F_67 ( V_309 + V_97 * 8 ) ;
if ( V_308 )
F_12 ( L_59 , V_97 , V_308 ) ;
V_306 += F_113 ( V_308 ) ;
}
if ( V_310 != V_306 )
V_310 = V_306 ;
}
static void T_1 F_114 ( void )
{
struct V_89 * V_90 = V_91 ;
int V_311 , V_312 ;
int V_124 , V_97 , V_313 ;
int V_314 = V_110 ;
int V_315 = V_108 ;
int V_316 = V_262 ;
int V_317 = V_296 ;
T_4 V_96 ;
if ( ! V_90 ) {
if ( F_22 () || F_19 () || F_20 () ) {
F_12 ( L_60 ) ;
return;
}
F_4 (
L_61 ) ;
F_26 () ;
}
V_311 = V_315 - V_314 + 1 ;
V_96 = V_311 * sizeof( V_267 [ 0 ] ) ;
V_267 = F_115 ( V_96 , V_103 ) ;
V_269 = F_115 ( V_96 , V_103 ) ;
V_312 = V_317 - V_316 + 1 ;
V_96 = V_312 * sizeof( V_265 [ 0 ] ) ;
V_265 = F_115 ( V_96 , V_103 ) ;
F_32 ( ! V_267 || ! V_269 || ! V_265 ) ;
for ( V_97 = 0 ; V_97 < V_311 ; V_97 ++ )
V_267 [ V_97 ] = V_269 [ V_97 ] = V_318 ;
for ( V_97 = 0 ; V_97 < V_312 ; V_97 ++ )
V_265 [ V_97 ] = V_318 ;
F_12 ( L_62 ) ;
for (; V_90 -> type != V_105 ; V_90 ++ ) {
if ( V_90 -> type == V_106 )
continue;
V_97 = V_90 -> V_109 - V_314 ;
if ( V_269 [ V_97 ] != V_318 )
continue;
V_269 [ V_97 ] = V_90 -> V_24 ;
V_97 = V_90 -> V_24 - V_316 ;
V_265 [ V_97 ] = V_90 -> V_109 ;
F_12 (
L_63 ,
V_90 -> V_109 , V_90 -> type , V_90 -> V_112 ,
V_269 [ V_90 -> V_109 - V_314 ] ,
V_265 [ V_90 -> V_24 - V_316 ] ) ;
}
V_313 = - 1 ;
F_116 (cpu) {
int V_170 = F_117 ( V_124 ) ;
int V_126 , V_109 ;
if ( V_313 == V_170 )
continue;
V_313 = V_170 ;
V_126 = F_38 ( V_127 , V_124 ) ;
V_109 = V_126 >> V_42 . V_58 ;
V_267 [ V_109 - V_314 ] = V_170 ;
F_12 ( L_64 ,
V_109 , V_126 , V_170 ) ;
}
V_96 = F_118 () * sizeof( V_319 [ 0 ] ) ;
V_319 = F_115 ( V_96 , V_103 ) ;
F_32 ( ! V_319 ) ;
for ( V_313 = 0 ; V_313 < F_118 () ; V_313 ++ ) {
unsigned short V_109 ;
for ( V_109 = V_314 ; V_109 <= V_315 ; V_109 ++ ) {
if ( V_313 == V_267 [ V_109 - V_314 ] ) {
V_319 [ V_313 ] =
V_269 [ V_109 - V_314 ] ;
break;
}
}
if ( V_109 > V_315 ) {
F_24 ( L_65 , V_313 ) ;
F_26 () ;
}
}
F_12 ( L_66 ) ;
if ( V_314 == 0 ) {
for ( V_97 = 0 ; V_97 < V_311 ; V_97 ++ )
if ( V_267 [ V_97 ] == V_318 ||
V_97 != V_267 [ V_97 ] )
break;
if ( V_97 >= V_311 ) {
F_119 ( V_267 ) ;
V_267 = NULL ;
F_12 ( L_67 ) ;
}
}
if ( V_314 == V_316 ) {
for ( V_97 = 0 ; V_97 < V_311 ; V_97 ++ )
if ( V_269 [ V_97 ] != V_318 &&
V_269 [ V_97 ] != V_97 + V_316 )
break;
if ( V_97 >= V_311 ) {
F_119 ( V_269 ) ;
V_269 = NULL ;
F_12 ( L_68 ) ;
}
}
}
void T_1 F_120 ( void )
{
struct V_260 V_261 = { 0 } ;
int V_96 , V_124 , V_320 ;
unsigned short V_183 = 9999 , V_163 = 0 ;
char * V_321 = F_81 () ? L_69 :
F_20 () ? L_70 :
F_19 () ? L_71 :
F_22 () ? L_72 : NULL ;
if ( ! V_321 ) {
F_24 ( L_73 ) ;
return;
}
F_12 ( L_74 , V_321 ) ;
F_82 () ;
F_121 () ;
F_111 () ;
F_114 () ;
F_30 () ;
F_108 ( & V_261 ) ;
V_310 = F_118 () ;
if ( ! V_319 )
F_112 ( & V_261 ) ;
F_12 ( L_75 ,
F_122 () ,
F_118 () ,
F_123 () ) ;
F_124 ( 0 , & V_322 , & V_323 , & V_324 ,
& V_325 , & V_326 ) ;
V_261 . V_327 = V_324 ;
F_83 () ;
V_96 = sizeof( void * ) * F_122 () ;
V_328 = F_31 ( V_96 , V_103 ) ;
F_32 ( ! V_328 ) ;
V_96 = sizeof( struct V_260 ) ;
F_125 (nodeid) {
struct V_260 * V_329 ;
if ( V_328 [ V_320 ] ) {
F_24 ( L_76 ,
V_320 ) ;
F_26 () ;
}
V_329 = ( V_320 == 0 ) ?
& V_74 :
F_126 ( V_96 , V_103 , V_320 ) ;
F_32 ( ! V_329 ) ;
V_328 [ V_320 ] = V_329 ;
V_329 = F_127 ( V_320 ) ;
F_32 ( ! V_329 ) ;
* V_329 = V_261 ;
if ( V_319 )
V_329 -> V_24 = V_319 [ V_320 ] ;
else
V_329 -> V_24 = 0xffff ;
V_329 -> V_330 = F_128 ( V_320 ) ;
V_329 -> V_331 = - 1 ;
V_329 -> V_332 = 0 ;
V_329 -> V_250 = 0 ;
}
F_129 (cpu) {
int V_126 = F_38 ( V_127 , V_124 ) ;
int V_333 ;
unsigned short V_24 ;
V_320 = F_117 ( V_124 ) ;
V_333 = F_130 ( V_124 ) ;
V_24 = F_35 ( V_126 ) ;
F_131 ( V_124 ) -> V_73 = F_127 ( V_320 ) ;
F_131 ( V_124 ) -> V_334 =
F_132 ( V_124 ) -> V_332 ++ ;
if ( F_132 ( V_124 ) -> V_331 == - 1 )
F_132 ( V_124 ) -> V_331 = F_117 ( V_124 ) ;
if ( V_320 != V_333 &&
F_127 ( V_333 ) -> V_24 == 0xffff )
F_127 ( V_333 ) -> V_24 = V_24 ;
else if ( F_132 ( V_124 ) -> V_24 == 0xffff )
F_132 ( V_124 ) -> V_24 = V_24 ;
F_92 ( V_124 ) -> V_303 = F_133 ( V_126 ) ;
}
F_125 (nodeid) {
unsigned short V_24 = F_127 ( V_320 ) -> V_24 ;
if ( V_24 == 0xffff ) {
unsigned long V_165 ;
V_165 = F_134 ( V_320 ) << V_335 ;
V_24 = F_135 ( F_136 ( V_165 ) ) ;
F_127 ( V_320 ) -> V_24 = V_24 ;
}
V_183 = F_75 ( V_24 , V_183 ) ;
V_163 = F_76 ( V_24 , V_163 ) ;
F_12 ( L_77 ,
V_320 ,
F_127 ( V_320 ) -> V_24 ,
F_127 ( V_320 ) -> V_332 ) ;
}
F_12 ( L_78 , V_183 , V_163 ) ;
F_77 ( V_163 ) ;
F_78 ( V_163 ) ;
F_80 ( V_183 , V_163 ) ;
F_137 () ;
F_106 () ;
F_99 () ;
F_138 ( L_79 , NULL ) ;
F_139 ( F_102 ) ;
if ( F_140 () )
V_336 = V_337 ;
}
