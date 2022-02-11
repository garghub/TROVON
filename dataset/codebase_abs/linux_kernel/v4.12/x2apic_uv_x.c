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
V_40 . V_41 = 2 ;
break;
}
V_42 -> V_43 = V_28 ;
V_40 . V_44 = ( 1 << V_23 . V_29 . V_45 ) - 1 ;
V_24 = ( V_21 . V_29 . V_21 >> 1 ) & V_40 . V_44 ;
V_40 . V_46 = 46 ;
F_12 ( L_2 ,
V_21 . V_29 . V_30 , V_21 . V_29 . V_31 , V_21 . V_29 . V_21 ,
V_23 . V_29 . V_45 , V_40 . V_44 , V_24 ) ;
return V_24 ;
}
static void F_13 ( void )
{
unsigned int V_47 , V_48 , V_49 , V_50 , V_51 ;
unsigned int V_52 ;
F_14 ( 0 , & V_47 , & V_48 , & V_49 , & V_50 ) ;
if ( V_47 < 0xb ) {
F_12 ( L_3 ) ;
return;
}
F_15 ( 0xb , V_53 , & V_47 , & V_48 , & V_49 , & V_50 ) ;
if ( V_48 == 0 || ( F_16 ( V_49 ) != V_54 ) ) {
F_12 ( L_4 ) ;
return;
}
V_52 = F_17 ( V_47 ) ;
V_51 = 1 ;
do {
F_15 ( 0xb , V_51 , & V_47 , & V_48 , & V_49 , & V_50 ) ;
if ( F_16 ( V_49 ) == V_55 ) {
V_52 = F_17 ( V_47 ) ;
break;
}
V_51 ++ ;
} while ( F_16 ( V_49 ) != V_56 );
V_40 . V_57 = 0 ;
V_40 . V_58 = ( ~ ( - 1 << V_52 ) ) ;
V_40 . V_59 = V_52 ;
}
static void T_1 F_18 ( void )
{
if ( F_19 () || F_20 () )
V_60 . V_25 = F_5 ( V_61 ) ;
F_13 () ;
F_12 ( L_5 , V_40 . V_57 , V_40 . V_58 ) ;
F_12 ( L_6 , V_40 . V_59 , V_40 . V_44 ) ;
}
static void T_1 F_21 ( void )
{
union V_62 V_58 ;
if ( F_22 () ) {
V_58 . V_25 = F_5 ( V_63 ) ;
V_64 = V_58 . V_65 . V_66 & V_67 ;
}
}
static int T_1 F_23 ( char * V_68 , char * V_69 )
{
int V_70 ;
int V_71 ;
if ( strncmp ( V_68 , L_7 , 3 ) != 0 ) {
if ( strncmp ( V_68 , L_8 , 4 ) == 0 ) {
V_72 = true ;
F_12 ( L_9 ,
V_68 , V_69 ) ;
}
return 0 ;
}
if ( V_73 ) {
F_24 ( L_10 ) ;
return 0 ;
}
V_74 -> V_75 = & V_76 ;
V_42 -> V_43 =
! strncmp ( V_68 , L_11 , 4 ) ? V_39 :
! strncmp ( V_68 , L_12 , 4 ) ? V_37 :
! strcmp ( V_68 , L_13 ) ? V_34 :
! strcmp ( V_68 , L_7 ) ? V_77 : 0 ;
if ( V_42 -> V_43 == 0 )
goto V_78;
V_70 = F_11 () ;
F_18 () ;
V_79 . V_80 = F_9 ;
V_79 . V_81 = V_82 ;
if ( ! strcmp ( V_69 , L_14 ) ) {
V_83 = V_84 ;
V_71 = 0 ;
} else if ( ! strcmp ( V_69 , L_15 ) ) {
V_83 = V_85 ;
F_25 ( V_86 , V_70 << V_60 . V_29 . V_87 ) ;
F_21 () ;
V_71 = 1 ;
} else if ( ! strcmp ( V_69 , L_16 ) ) {
V_83 = V_88 ;
V_71 = 0 ;
} else {
goto V_78;
}
F_12 ( L_17 , V_68 , V_69 , V_83 , V_28 , V_71 ) ;
return V_71 ;
V_78:
F_24 ( L_18 , V_68 , V_69 ) ;
F_24 ( L_19 ) ;
F_26 () ;
}
enum V_83 F_27 ( void )
{
return V_83 ;
}
int F_28 ( void )
{
return V_83 != V_89 ;
}
int F_29 ( void )
{
return V_72 ;
}
extern int F_30 ( void )
{
return V_90 ;
}
static T_1 void F_31 ( void )
{
struct V_91 * V_92 = V_93 ;
struct V_94 * V_95 ;
unsigned long V_96 = 0 , V_97 = 0 ;
int V_98 , V_99 , V_100 , V_101 = - 1 , V_102 = 0 , V_103 = - 1 ;
if ( ! V_92 )
return;
V_98 = V_104 * sizeof( struct V_94 ) ;
V_95 = F_32 ( V_98 , V_105 ) ;
F_33 ( ! V_95 ) ;
V_106 = V_95 ;
for (; V_92 -> type != V_107 ; V_92 ++ ) {
if ( V_92 -> type == V_108 ) {
if ( ! V_97 ) {
V_97 = V_96 ;
V_96 = V_92 -> V_109 ;
V_101 ++ ;
continue;
}
V_96 = V_92 -> V_109 ;
F_12 ( L_20 , ( int ) ( V_92 - V_93 ) ) ;
continue;
}
if ( V_110 < V_92 -> V_111 ) {
F_24 ( L_21 , V_92 -> V_111 , V_110 , ( int ) ( V_92 - V_93 ) ) ;
continue;
}
V_100 = V_92 -> V_111 - V_112 ;
if ( V_101 < V_100 ) {
V_95 = & V_106 [ V_102 ] ;
V_95 -> V_113 = V_103 ;
V_95 -> V_114 = V_92 -> V_114 ;
V_95 -> V_109 = V_96 = V_92 -> V_109 ;
V_101 = V_100 ;
V_103 = V_102 ++ ;
continue;
}
if ( V_101 == V_100 && ! V_97 ) {
if ( V_95 -> V_109 == V_96 ) {
V_95 -> V_109 = V_96 = V_92 -> V_109 ;
continue;
}
}
if ( ! V_97 ) {
V_95 ++ ;
V_95 -> V_113 = V_103 ;
V_95 -> V_114 = V_92 -> V_114 ;
V_95 -> V_109 = V_96 = V_92 -> V_109 ;
continue;
}
V_95 ++ ;
V_95 -> V_113 = V_95 - V_106 ;
V_95 -> V_114 = V_92 -> V_114 ;
V_95 -> V_109 = V_96 = V_92 -> V_109 ;
V_101 ++ ;
}
V_95 ++ ;
V_99 = V_95 - V_106 ;
if ( V_99 < V_104 ) {
void * V_115 ;
V_98 = V_99 * sizeof( struct V_94 ) ;
V_115 = F_34 ( V_106 , V_98 , V_105 ) ;
if ( V_115 ) {
V_106 = V_115 ;
V_104 = V_99 ;
}
}
for ( V_99 = 0 , V_95 = V_106 ; V_99 < V_104 ; V_99 ++ , V_95 ++ ) {
unsigned long V_7 , V_8 ;
int V_116 = V_95 -> V_113 ;
V_7 = V_116 < 0 ? 0 : ( unsigned long ) V_106 [ V_116 ] . V_109 << V_117 ;
V_8 = ( unsigned long ) V_95 -> V_109 << V_117 ;
F_12 ( L_22 , V_99 , V_95 -> V_114 , V_7 , V_8 , V_116 ) ;
}
}
static int F_35 ( int V_118 , unsigned long V_119 )
{
unsigned long V_4 ;
int V_24 ;
V_24 = F_36 ( V_118 ) ;
V_118 |= V_64 ;
V_4 = ( 1UL << V_120 ) |
( V_118 << V_121 ) |
( ( V_119 << V_122 ) >> 12 ) |
V_123 ;
F_37 ( V_24 , V_124 , V_4 ) ;
V_4 = ( 1UL << V_120 ) |
( V_118 << V_121 ) |
( ( V_119 << V_122 ) >> 12 ) |
V_125 ;
F_37 ( V_24 , V_124 , V_4 ) ;
return 0 ;
}
static void F_38 ( int V_126 , int V_127 )
{
unsigned long V_128 ;
int V_24 ;
V_128 = F_39 ( V_129 , V_126 ) ;
V_24 = F_36 ( V_128 ) ;
F_40 ( V_24 , V_128 , V_127 ) ;
}
static void F_41 ( const struct V_130 * V_131 , int V_127 )
{
unsigned int V_126 ;
F_42 (cpu, mask)
F_38 ( V_126 , V_127 ) ;
}
static void F_43 ( const struct V_130 * V_131 , int V_127 )
{
unsigned int V_132 = F_44 () ;
unsigned int V_126 ;
F_42 (cpu, mask) {
if ( V_126 != V_132 )
F_38 ( V_126 , V_127 ) ;
}
}
static void F_45 ( int V_127 )
{
unsigned int V_132 = F_44 () ;
unsigned int V_126 ;
F_46 (cpu) {
if ( V_126 != V_132 )
F_38 ( V_126 , V_127 ) ;
}
}
static void F_47 ( int V_127 )
{
F_41 ( V_133 , V_127 ) ;
}
static int F_48 ( int V_128 )
{
return 1 ;
}
static int F_49 ( void )
{
return 1 ;
}
static void F_50 ( void )
{
}
static int
F_51 ( const struct V_130 * V_130 ,
const struct V_130 * V_134 ,
unsigned int * V_128 )
{
int unsigned V_126 ;
F_52 (cpu, cpumask, andmask) {
if ( F_53 ( V_126 , V_133 ) )
break;
}
if ( F_2 ( V_126 < V_135 ) ) {
* V_128 = F_39 ( V_129 , V_126 ) | V_64 ;
return 0 ;
}
return - V_136 ;
}
static unsigned int F_54 ( unsigned long V_137 )
{
unsigned int V_138 ;
F_55 ( F_56 () && F_57 () > 1 ) ;
V_138 = V_137 | F_58 ( V_86 ) ;
return V_138 ;
}
static unsigned long F_59 ( unsigned int V_138 )
{
return V_138 ;
}
static unsigned int F_60 ( void )
{
return F_54 ( F_61 ( V_139 ) ) ;
}
static int F_62 ( int V_140 , int V_141 )
{
return F_60 () >> V_141 ;
}
static void F_63 ( int V_127 )
{
F_64 ( V_142 , V_127 ) ;
}
static int F_65 ( void )
{
return V_143 == & V_144 ;
}
static void F_66 ( int V_24 )
{
F_25 ( V_86 , V_24 << V_60 . V_29 . V_87 ) ;
}
static T_1 void F_67 ( unsigned long * V_113 , unsigned long * V_145 )
{
union V_146 V_147 ;
union V_148 V_149 ;
unsigned long V_150 ;
unsigned long V_151 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_152 ; V_99 ++ ) {
switch ( V_99 ) {
case 0 :
V_150 = V_153 ;
V_151 = V_154 ;
break;
case 1 :
V_150 = V_155 ;
V_151 = V_156 ;
break;
case 2 :
V_150 = V_157 ;
V_151 = V_158 ;
break;
}
V_147 . V_25 = F_68 ( V_151 ) ;
if ( V_147 . V_29 . V_159 && V_147 . V_29 . V_113 == 0 ) {
* V_145 = ( 1UL << V_147 . V_29 . V_160 ) ;
V_149 . V_25 = F_68 ( V_150 ) ;
* V_113 = ( unsigned long ) V_149 . V_29 . V_161 << V_162 ;
return;
}
}
* V_113 = * V_145 = 0 ;
}
static T_1 void F_69 ( char * V_138 , unsigned long V_113 , int V_163 , int V_164 , int V_165 , enum V_166 V_166 )
{
unsigned long V_98 , V_167 ;
V_167 = V_113 << V_163 ;
V_98 = ( 1UL << V_164 ) * ( V_165 + 1 ) ;
if ( ! V_167 ) {
F_12 ( L_23 , V_138 ) ;
return;
}
F_70 ( L_24 , V_138 , V_167 , V_167 + V_98 ) ;
if ( V_166 == V_168 )
F_71 ( V_167 , V_98 ) ;
else
F_72 ( V_167 , V_98 ) ;
}
static T_1 void F_73 ( unsigned long V_169 )
{
union V_170 V_171 ;
T_2 V_167 ;
unsigned long V_98 ;
int V_172 ;
V_171 . V_25 = V_169 ;
V_9 = V_171 . V_25 & 0x000007fff0000000UL ;
if ( ! V_9 ) {
F_12 ( L_25 ) ;
return;
}
V_98 = 1UL << V_173 ;
V_13 = ( ( 1UL << V_42 -> V_174 ) - 1 ) & ~ ( V_98 - 1 ) ;
V_11 = ~ ( ( 1UL << V_42 -> V_174 ) - 1 ) ;
V_9 &= V_13 ;
F_74 (nid) {
V_167 = ( ( T_2 ) F_75 ( V_172 ) << V_42 -> V_174 ) |
V_9 ;
F_72 ( V_167 , V_98 ) ;
V_16 = F_76 ( V_167 , V_16 ) ;
V_17 = F_77 ( V_167 , V_17 ) ;
}
V_16 &= V_11 ;
V_17 &= V_11 ;
F_70 ( L_26 , V_9 , V_16 , V_17 ) ;
}
static T_1 void F_78 ( int V_165 )
{
union V_170 V_171 ;
int V_175 = V_173 ;
unsigned long V_131 = V_176 ;
unsigned long V_113 ;
V_171 . V_25 = F_68 ( V_177 ) ;
if ( ! V_171 . V_29 . V_159 ) {
F_12 ( L_27 ) ;
return;
}
if ( F_20 () && V_171 . V_178 . V_179 ) {
F_73 ( V_171 . V_25 ) ;
return;
}
V_113 = ( V_171 . V_25 & V_131 ) >> V_175 ;
F_69 ( L_28 , V_113 , V_175 , V_175 , V_165 , V_180 ) ;
V_18 = ( ( T_2 ) V_113 << V_175 ) ;
V_19 = V_18 + ( 1UL << V_175 ) * ( V_165 + 1 ) ;
}
static T_1 void F_79 ( int V_165 )
{
union V_181 V_5 ;
int V_175 = V_182 ;
V_5 . V_25 = F_68 ( V_183 ) ;
if ( V_5 . V_29 . V_159 )
F_69 ( L_29 , V_5 . V_29 . V_113 , V_175 , V_175 , V_165 , V_168 ) ;
else
F_12 ( L_30 ) ;
}
static T_1 void F_80 ( int V_184 , int V_185 , int V_165 )
{
union V_186 V_187 ;
unsigned long V_5 ;
unsigned long V_113 ;
int V_99 , V_188 , V_175 , V_189 , V_190 ;
int V_114 , V_191 , V_192 , V_193 ;
char * V_138 ;
V_138 = V_194 [ V_184 ] . V_138 ;
V_187 . V_25 = F_68 ( V_194 [ V_184 ] . V_187 ) ;
F_12 ( L_31 , V_138 , V_187 . V_25 , V_187 . V_178 . V_113 , V_187 . V_178 . V_189 ) ;
if ( ! V_187 . V_178 . V_159 ) {
F_12 ( L_32 , V_138 ) ;
return;
}
V_175 = V_195 ;
V_113 = ( unsigned long ) V_187 . V_178 . V_113 ;
V_189 = V_187 . V_178 . V_189 ;
V_5 = V_194 [ V_184 ] . V_149 ;
V_188 = V_196 ;
V_185 *= 2 ;
V_165 *= 2 ;
V_190 = V_191 = V_192 = V_193 = - 1 ;
for ( V_99 = 0 ; V_99 < V_188 ; V_99 ++ ) {
union V_197 V_149 ;
V_149 . V_25 = F_68 ( V_5 + V_99 * 8 ) ;
V_114 = V_149 . V_178 . V_114 ;
if ( V_114 < V_185 || V_165 < V_114 )
V_114 = - 1 ;
if ( V_114 == V_191 ) {
V_193 = V_99 ;
if ( V_99 != V_188 - 1 )
continue;
}
if ( V_191 != - 1 || ( V_99 == V_188 - 1 && V_114 != - 1 ) ) {
unsigned long V_198 , V_199 ;
int V_200 , V_201 ;
if ( V_191 == - 1 ) {
V_200 = V_201 = V_99 ;
V_191 = V_114 ;
} else {
V_200 = V_192 ;
V_201 = V_193 ;
}
V_198 = ( V_113 << V_175 ) + V_200 * ( 1ULL << V_189 ) ;
V_199 = ( V_113 << V_175 ) + ( V_201 + 1 ) * ( 1ULL << V_189 ) ;
F_12 ( L_33 , V_138 , V_192 , V_193 , V_191 , V_198 , V_199 ) ;
if ( V_190 < V_201 )
V_190 = V_201 ;
}
V_192 = V_193 = V_99 ;
V_191 = V_114 ;
}
F_12 ( L_34 , V_138 , V_113 , V_175 , V_189 , V_190 ) ;
if ( V_190 >= 0 )
F_69 ( V_138 , V_113 , V_175 , V_189 , V_190 , V_168 ) ;
}
static T_1 void F_81 ( int V_185 , int V_165 )
{
union V_202 V_203 ;
unsigned long V_5 , V_113 ;
int V_175 , V_159 , V_189 , V_204 ;
if ( F_20 () || F_82 () ) {
F_80 ( 0 , V_185 , V_165 ) ;
F_80 ( 1 , V_185 , V_165 ) ;
return;
}
if ( F_22 () ) {
V_5 = V_205 ;
V_175 = V_206 ;
V_203 . V_25 = F_68 ( V_5 ) ;
V_159 = ! ! V_203 . V_65 . V_159 ;
V_113 = V_203 . V_65 . V_113 ;
V_189 = V_203 . V_65 . V_189 ;
V_204 = V_203 . V_65 . V_204 ;
} else if ( F_19 () ) {
V_5 = V_207 ;
V_175 = V_208 ;
V_203 . V_25 = F_68 ( V_5 ) ;
V_159 = ! ! V_203 . V_209 . V_159 ;
V_113 = V_203 . V_209 . V_113 ;
V_189 = V_203 . V_209 . V_189 ;
V_204 = V_203 . V_209 . V_204 ;
} else {
return;
}
if ( V_159 ) {
V_165 &= ( 1 << V_204 ) - 1 ;
F_12 ( L_35 , V_113 , V_175 , V_189 , V_204 , V_165 ) ;
F_69 ( L_36 , V_113 , V_175 , V_189 , V_165 , V_168 ) ;
} else {
F_12 ( L_37 ) ;
}
}
static T_1 void F_83 ( void )
{
F_71 ( V_210 , V_211 ) ;
F_71 ( V_6 , V_212 ) ;
}
static T_1 void F_84 ( void )
{
long V_213 ;
T_2 V_214 ;
V_213 = F_85 ( V_215 , & V_214 ) ;
if ( V_213 != V_216 || V_214 < 100000 ) {
F_86 ( L_38 ) ;
V_217 = 1000000000000UL / 30000UL ;
} else {
V_217 = V_214 ;
}
}
static void F_87 ( unsigned long V_218 )
{
struct V_219 * V_220 = & V_221 -> V_220 ;
unsigned char V_222 = V_221 -> V_223 ;
V_222 ^= V_224 ;
if ( F_88 ( F_89 () ) )
V_222 &= ~ V_225 ;
else
V_222 |= V_225 ;
F_90 ( V_222 ) ;
F_91 ( V_220 , V_226 + V_227 ) ;
}
static int F_92 ( unsigned int V_126 )
{
while ( ! F_93 ( V_126 ) -> V_228 ) {
struct V_219 * V_220 = & F_93 ( V_126 ) -> V_220 ;
F_94 ( V_126 , V_224 | V_225 ) ;
F_95 ( V_220 , F_87 , V_126 ) ;
V_220 -> V_229 = V_226 + V_227 ;
F_96 ( V_220 , V_126 ) ;
F_93 ( V_126 ) -> V_228 = 1 ;
V_126 = 0 ;
}
return 0 ;
}
static int F_97 ( unsigned int V_126 )
{
if ( F_93 ( V_126 ) -> V_228 ) {
F_93 ( V_126 ) -> V_228 = 0 ;
F_98 ( & F_93 ( V_126 ) -> V_220 ) ;
}
F_94 ( V_126 , 0xff ) ;
return 0 ;
}
static T_1 void F_99 ( void )
{
F_100 ( V_230 , L_39 ,
F_92 , F_97 ) ;
}
static T_1 void F_99 ( void )
{
}
static T_1 int F_101 ( void )
{
int V_126 ;
if ( F_28 () ) {
F_46 (cpu)
F_92 ( V_126 ) ;
}
return 0 ;
}
int F_102 ( struct V_231 * V_232 , bool V_233 , unsigned int V_234 , T_3 V_235 )
{
int V_236 , V_237 , V_238 ;
if ( ! ( V_235 & V_239 ) )
return 0 ;
if ( ( V_234 & V_240 ) == 0 )
return 0 ;
V_236 = F_103 ( V_232 -> V_237 ) ;
V_237 = V_232 -> V_237 -> V_241 ;
V_238 = F_104 ( V_233 , V_236 , V_237 ) ;
return V_238 ;
}
void F_105 ( void )
{
if ( F_44 () == 0 )
return;
V_42 -> V_242 ++ ;
if ( F_27 () == V_85 )
F_66 ( V_42 -> V_24 ) ;
}
static void F_106 ( struct V_243 * V_244 )
{
union V_22 V_23 ;
union V_245 V_246 ;
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
V_23 . V_25 = F_68 ( V_27 ) ;
V_244 -> V_247 = V_23 . V_29 . V_45 ;
if ( F_82 () ) {
V_244 -> V_174 = 0 ;
V_244 -> V_248 = 0 ;
} else if ( F_20 () ) {
V_244 -> V_174 = V_23 . V_178 . V_249 ;
V_246 . V_25 = F_68 ( V_250 ) ;
V_244 -> V_248 = V_246 . V_178 . V_249 ;
} else if ( F_19 () ) {
V_244 -> V_174 = V_23 . V_209 . V_249 ;
V_244 -> V_248 = V_244 -> V_174 == 40 ? 40 : 39 ;
} else if ( F_22 () ) {
V_244 -> V_174 = V_23 . V_65 . V_249 ;
V_244 -> V_248 = V_244 -> V_174 ;
}
V_244 -> V_251 = V_244 -> V_174 ? 64 - V_244 -> V_174 : 0 ;
}
void T_1 F_107 ( struct V_252 * V_253 )
{
union V_20 V_21 ;
struct V_243 V_243 ;
F_106 ( & V_243 ) ;
V_253 -> V_254 = V_243 . V_174 ?
( 1UL << ( V_243 . V_174 + V_243 . V_247 ) ) - 1 :
( 1UL << V_40 . V_46 ) - 1 ;
V_253 -> V_174 = V_243 . V_174 ;
V_253 -> V_247 = V_243 . V_247 ;
V_253 -> V_251 = V_243 . V_251 ;
V_253 -> V_248 = V_243 . V_248 ? V_243 . V_248 : 0 ;
V_253 -> V_43 = V_42 -> V_43 ;
V_253 -> V_44 = V_40 . V_44 ;
V_253 -> V_185 = V_255 ;
V_253 -> V_256 = V_112 ;
V_253 -> V_257 = V_258 ;
V_253 -> V_259 = V_260 ;
V_253 -> V_261 = V_262 ;
V_253 -> V_263 = V_104 ;
V_253 -> V_264 = V_106 ;
V_21 . V_25 = F_68 ( V_26 ) ;
V_40 . V_41 = F_108 (unsigned int, uv_cpuid.gnode_shift, mn.n_val) ;
V_253 -> V_265 = ( V_21 . V_29 . V_21 & ~ ( ( 1 << V_40 . V_41 ) - 1 ) ) >> 1 ;
if ( V_243 . V_174 )
V_253 -> V_266 = ( T_2 ) V_253 -> V_265 << V_243 . V_174 ;
if ( V_267 ) {
V_253 -> V_268 = V_267 -> V_269 ;
V_253 -> V_270 = V_267 -> V_271 ;
V_253 -> V_272 = V_267 -> V_273 ;
V_253 -> V_274 = V_267 -> V_275 ;
V_253 -> V_46 = V_267 -> V_46 ;
V_253 -> V_254 = ( 1UL << V_253 -> V_46 ) - 1 ;
} else {
V_253 -> V_268 = F_68 ( V_183 ) & ~ V_276 ;
V_253 -> V_270 = V_277 ;
}
F_67 ( & V_253 -> V_278 , & V_253 -> V_279 ) ;
V_253 -> V_280 = V_40 . V_59 ;
F_12 ( L_40 , V_253 -> V_247 , V_253 -> V_174 , V_253 -> V_251 , V_253 -> V_248 ) ;
F_12 ( L_41 , V_253 -> V_254 , V_253 -> V_46 , V_253 -> V_44 , V_253 -> V_280 ) ;
F_12 ( L_42 , V_253 -> V_268 , V_253 -> V_270 , V_253 -> V_272 , V_253 -> V_274 ) ;
F_12 ( L_43 , V_253 -> V_266 , V_253 -> V_265 ) ;
}
static void T_1 F_109 ( unsigned long V_281 )
{
V_267 = (struct V_282 * ) V_281 ;
F_12 ( L_44 ) ;
F_12 ( L_45 ,
V_267 -> V_269 , V_267 -> V_271 ,
V_267 -> V_273 , V_267 -> V_275 ,
V_267 -> V_46 ) ;
}
static void T_1 F_110 ( unsigned long V_281 )
{
struct V_91 * V_92 = (struct V_91 * ) V_281 ;
unsigned long V_283 = 0 ;
int V_184 = 0 ;
int V_284 = 999999 , V_285 = 99999 ;
int V_286 = - 1 , V_287 = - 1 ;
V_93 = V_92 ;
for (; V_92 -> type != V_107 ; V_92 ++ ) {
if ( ! V_184 ) {
F_12 ( L_46 ) ;
F_12 ( L_47 , L_48 , L_49 , L_50 , L_51 , L_52 , L_53 , L_54 ) ;
}
F_12 ( L_55 ,
V_184 ++ ,
( unsigned long ) V_283 << V_117 ,
( unsigned long ) V_92 -> V_109 << V_117 ,
( ( unsigned long ) ( V_92 -> V_109 - V_283 ) ) >>
( 30 - V_117 ) ,
V_92 -> type , V_92 -> V_114 , V_92 -> V_111 , V_92 -> V_24 ) ;
V_283 = V_92 -> V_109 ;
if ( V_284 > V_92 -> V_111 )
V_284 = V_92 -> V_111 ;
if ( V_286 < V_92 -> V_111 )
V_286 = V_92 -> V_111 ;
if ( V_285 > V_92 -> V_24 )
V_285 = V_92 -> V_24 ;
if ( V_287 < V_92 -> V_24 )
V_287 = V_92 -> V_24 ;
}
V_112 = V_284 ;
V_110 = V_286 ;
V_255 = V_285 ;
V_288 = V_287 ;
V_104 = V_184 ;
F_12 ( L_56 , V_184 , V_112 , V_110 , V_255 , V_288 ) ;
}
static int T_1 F_111 ( void )
{
struct V_289 * V_290 ;
int V_99 ;
if ( V_42 -> V_43 < V_39 )
return 0 ;
V_290 = V_289 ;
if ( ( ! V_290 ) || ( V_290 -> V_30 < V_291 ) ) {
int V_292 = V_290 ? V_290 -> V_30 : 0 ;
F_24 ( L_57 , V_292 , V_291 ) ;
F_24 ( L_58 ) ;
V_83 = V_89 ;
return - V_136 ;
}
for ( V_99 = 0 ; V_290 -> V_293 [ V_99 ] . type != V_294 ; V_99 ++ ) {
unsigned long V_281 = V_290 -> V_293 [ V_99 ] . V_295 ;
if ( ! V_281 )
continue;
V_281 = V_281 + ( unsigned long ) V_290 ;
switch ( V_290 -> V_293 [ V_99 ] . type ) {
case V_296 :
F_109 ( V_281 ) ;
break;
case V_297 :
F_110 ( V_281 ) ;
break;
}
}
return 0 ;
}
static T_1 void F_112 ( struct V_252 * V_298 )
{
int V_99 , V_299 = 0 ;
F_12 ( L_59 , V_300 ) ;
for ( V_99 = 0 ; V_99 < V_300 ; V_99 ++ ) {
unsigned long V_301 ;
V_301 = F_68 ( V_302 + V_99 * 8 ) ;
if ( V_301 )
F_12 ( L_60 , V_99 , V_301 ) ;
V_299 += F_113 ( V_301 ) ;
}
if ( V_303 != V_299 )
V_303 = V_299 ;
}
static void T_1 F_114 ( void )
{
struct V_91 * V_92 = V_93 ;
int V_304 , V_305 ;
int V_126 , V_99 , V_306 ;
int V_307 = V_112 ;
int V_308 = V_110 ;
int V_309 = V_255 ;
int V_310 = V_288 ;
T_4 V_98 ;
if ( ! V_92 ) {
if ( F_22 () || F_19 () || F_20 () ) {
F_12 ( L_61 ) ;
return;
}
F_4 ( L_62 ) ;
F_26 () ;
}
V_304 = V_308 - V_307 + 1 ;
V_98 = V_304 * sizeof( V_260 [ 0 ] ) ;
V_260 = F_115 ( V_98 , V_105 ) ;
V_262 = F_115 ( V_98 , V_105 ) ;
V_305 = V_310 - V_309 + 1 ;
V_98 = V_305 * sizeof( V_258 [ 0 ] ) ;
V_258 = F_115 ( V_98 , V_105 ) ;
F_33 ( ! V_260 || ! V_262 || ! V_258 ) ;
for ( V_99 = 0 ; V_99 < V_304 ; V_99 ++ )
V_260 [ V_99 ] = V_262 [ V_99 ] = V_311 ;
for ( V_99 = 0 ; V_99 < V_305 ; V_99 ++ )
V_258 [ V_99 ] = V_311 ;
F_12 ( L_63 ) ;
for (; V_92 -> type != V_107 ; V_92 ++ ) {
if ( V_92 -> type == V_108 )
continue;
V_99 = V_92 -> V_111 - V_307 ;
if ( V_262 [ V_99 ] != V_311 )
continue;
V_262 [ V_99 ] = V_92 -> V_24 ;
V_99 = V_92 -> V_24 - V_309 ;
V_258 [ V_99 ] = V_92 -> V_111 ;
F_12 ( L_64 ,
V_92 -> V_111 , V_92 -> type , V_92 -> V_114 ,
V_262 [ V_92 -> V_111 - V_307 ] ,
V_258 [ V_92 -> V_24 - V_309 ] ) ;
}
V_306 = - 1 ;
F_116 (cpu) {
int V_172 = F_117 ( V_126 ) ;
int V_128 , V_111 ;
if ( V_306 == V_172 )
continue;
V_306 = V_172 ;
V_128 = F_39 ( V_129 , V_126 ) ;
V_111 = V_128 >> V_40 . V_59 ;
V_260 [ V_111 - V_307 ] = V_172 ;
F_12 ( L_65 ,
V_111 , V_128 , V_172 ) ;
}
V_98 = F_118 () * sizeof( V_312 [ 0 ] ) ;
V_312 = F_115 ( V_98 , V_105 ) ;
F_33 ( ! V_312 ) ;
for ( V_306 = 0 ; V_306 < F_118 () ; V_306 ++ ) {
unsigned short V_111 ;
for ( V_111 = V_307 ; V_111 <= V_308 ; V_111 ++ ) {
if ( V_306 == V_260 [ V_111 - V_307 ] ) {
V_312 [ V_306 ] = V_262 [ V_111 - V_307 ] ;
break;
}
}
if ( V_111 > V_308 ) {
F_24 ( L_66 , V_306 ) ;
F_26 () ;
}
}
F_12 ( L_67 ) ;
if ( V_307 == 0 ) {
for ( V_99 = 0 ; V_99 < V_304 ; V_99 ++ )
if ( V_260 [ V_99 ] == V_311 || V_99 != V_260 [ V_99 ] )
break;
if ( V_99 >= V_304 ) {
F_119 ( V_260 ) ;
V_260 = NULL ;
F_12 ( L_68 ) ;
}
}
if ( V_307 == V_309 ) {
for ( V_99 = 0 ; V_99 < V_304 ; V_99 ++ )
if ( V_262 [ V_99 ] != V_311 &&
V_262 [ V_99 ] != V_99 + V_309 )
break;
if ( V_99 >= V_304 ) {
F_119 ( V_262 ) ;
V_262 = NULL ;
F_12 ( L_69 ) ;
}
}
}
static void T_1 F_120 ( void )
{
struct V_252 V_298 = { 0 } ;
int V_98 , V_126 , V_313 ;
unsigned short V_185 = 9999 , V_165 = 0 ;
char * V_314 = F_82 () ? L_70 :
F_20 () ? L_71 :
F_19 () ? L_72 :
F_22 () ? L_73 : NULL ;
if ( ! V_314 ) {
F_24 ( L_74 ) ;
return;
}
F_12 ( L_75 , V_314 ) ;
F_83 () ;
F_121 () ;
if ( F_111 () < 0 )
return;
F_114 () ;
F_31 () ;
F_107 ( & V_298 ) ;
V_303 = F_118 () ;
if ( ! V_312 )
F_112 ( & V_298 ) ;
F_12 ( L_76 , F_122 () , F_118 () , F_123 () ) ;
F_124 ( 0 , & V_315 , & V_316 , & V_317 , & V_318 , & V_319 ) ;
V_298 . V_320 = V_317 ;
F_84 () ;
V_98 = sizeof( void * ) * F_122 () ;
V_321 = F_32 ( V_98 , V_105 ) ;
F_33 ( ! V_321 ) ;
V_98 = sizeof( struct V_252 ) ;
F_125 (nodeid) {
struct V_252 * V_322 ;
if ( V_321 [ V_313 ] ) {
F_24 ( L_77 , V_313 ) ;
F_26 () ;
}
V_322 = ( V_313 == 0 ) ? & V_76 : F_126 ( V_98 , V_105 , V_313 ) ;
F_33 ( ! V_322 ) ;
V_321 [ V_313 ] = V_322 ;
V_322 = F_127 ( V_313 ) ;
F_33 ( ! V_322 ) ;
* V_322 = V_298 ;
if ( V_312 )
V_322 -> V_24 = V_312 [ V_313 ] ;
else
V_322 -> V_24 = 0xffff ;
V_322 -> V_323 = F_128 ( V_313 ) ;
V_322 -> V_324 = - 1 ;
V_322 -> V_325 = 0 ;
V_322 -> V_242 = 0 ;
}
F_129 (cpu) {
int V_128 = F_39 ( V_129 , V_126 ) ;
int V_326 ;
unsigned short V_24 ;
V_313 = F_117 ( V_126 ) ;
V_326 = F_130 ( V_126 ) ;
V_24 = F_36 ( V_128 ) ;
F_131 ( V_126 ) -> V_75 = F_127 ( V_313 ) ;
F_131 ( V_126 ) -> V_327 = F_132 ( V_126 ) -> V_325 ++ ;
if ( F_132 ( V_126 ) -> V_324 == - 1 )
F_132 ( V_126 ) -> V_324 = F_117 ( V_126 ) ;
if ( V_313 != V_326 &&
F_127 ( V_326 ) -> V_24 == 0xffff )
F_127 ( V_326 ) -> V_24 = V_24 ;
else if ( F_132 ( V_126 ) -> V_24 == 0xffff )
F_132 ( V_126 ) -> V_24 = V_24 ;
F_93 ( V_126 ) -> V_295 = F_133 ( V_128 ) ;
}
F_125 (nodeid) {
unsigned short V_24 = F_127 ( V_313 ) -> V_24 ;
if ( V_24 == 0xffff ) {
unsigned long V_167 ;
V_167 = F_134 ( V_313 ) << V_328 ;
V_24 = F_135 ( F_136 ( V_167 ) ) ;
F_127 ( V_313 ) -> V_24 = V_24 ;
}
V_185 = F_76 ( V_24 , V_185 ) ;
V_165 = F_77 ( V_24 , V_165 ) ;
F_12 ( L_78 ,
V_313 ,
F_127 ( V_313 ) -> V_24 ,
F_127 ( V_313 ) -> V_325 ) ;
}
F_12 ( L_79 , V_185 , V_165 ) ;
F_78 ( V_165 ) ;
F_79 ( V_165 ) ;
F_81 ( V_185 , V_165 ) ;
F_137 () ;
F_105 () ;
F_99 () ;
F_138 ( L_80 , NULL ) ;
F_139 ( F_102 ) ;
if ( F_140 () )
V_329 = V_330 ;
}
void T_1 F_141 ( void )
{
if ( F_2 ( ! F_28 () && ! F_29 () ) )
return;
if ( F_28 () )
F_120 () ;
else
F_142 () ;
}
