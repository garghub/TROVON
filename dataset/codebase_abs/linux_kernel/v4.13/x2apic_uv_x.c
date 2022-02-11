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
F_51 ( const struct V_130 * V_131 , struct V_134 * V_135 ,
unsigned int * V_128 )
{
int V_115 = F_52 ( V_131 , V_135 , V_128 ) ;
if ( ! V_115 )
* V_128 |= V_64 ;
return V_115 ;
}
static unsigned int F_53 ( unsigned long V_136 )
{
unsigned int V_137 ;
F_54 ( F_55 () && F_56 () > 1 ) ;
V_137 = V_136 | F_57 ( V_86 ) ;
return V_137 ;
}
static unsigned long F_58 ( unsigned int V_137 )
{
return V_137 ;
}
static unsigned int F_59 ( void )
{
return F_53 ( F_60 ( V_138 ) ) ;
}
static int F_61 ( int V_139 , int V_140 )
{
return F_59 () >> V_140 ;
}
static void F_62 ( int V_127 )
{
F_63 ( V_141 , V_127 ) ;
}
static int F_64 ( void )
{
return V_142 == & V_143 ;
}
static void F_65 ( int V_24 )
{
F_25 ( V_86 , V_24 << V_60 . V_29 . V_87 ) ;
}
static T_1 void F_66 ( unsigned long * V_113 , unsigned long * V_144 )
{
union V_145 V_146 ;
union V_147 V_148 ;
unsigned long V_149 ;
unsigned long V_150 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_151 ; V_99 ++ ) {
switch ( V_99 ) {
case 0 :
V_149 = V_152 ;
V_150 = V_153 ;
break;
case 1 :
V_149 = V_154 ;
V_150 = V_155 ;
break;
case 2 :
V_149 = V_156 ;
V_150 = V_157 ;
break;
}
V_146 . V_25 = F_67 ( V_150 ) ;
if ( V_146 . V_29 . V_158 && V_146 . V_29 . V_113 == 0 ) {
* V_144 = ( 1UL << V_146 . V_29 . V_159 ) ;
V_148 . V_25 = F_67 ( V_149 ) ;
* V_113 = ( unsigned long ) V_148 . V_29 . V_160 << V_161 ;
return;
}
}
* V_113 = * V_144 = 0 ;
}
static T_1 void F_68 ( char * V_137 , unsigned long V_113 , int V_162 , int V_163 , int V_164 , enum V_165 V_165 )
{
unsigned long V_98 , V_166 ;
V_166 = V_113 << V_162 ;
V_98 = ( 1UL << V_163 ) * ( V_164 + 1 ) ;
if ( ! V_166 ) {
F_12 ( L_23 , V_137 ) ;
return;
}
F_69 ( L_24 , V_137 , V_166 , V_166 + V_98 ) ;
if ( V_165 == V_167 )
F_70 ( V_166 , V_98 ) ;
else
F_71 ( V_166 , V_98 ) ;
}
static T_1 void F_72 ( unsigned long V_168 )
{
union V_169 V_170 ;
T_2 V_166 ;
unsigned long V_98 ;
int V_171 ;
V_170 . V_25 = V_168 ;
V_9 = V_170 . V_25 & 0x000007fff0000000UL ;
if ( ! V_9 ) {
F_12 ( L_25 ) ;
return;
}
V_98 = 1UL << V_172 ;
V_13 = ( ( 1UL << V_42 -> V_173 ) - 1 ) & ~ ( V_98 - 1 ) ;
V_11 = ~ ( ( 1UL << V_42 -> V_173 ) - 1 ) ;
V_9 &= V_13 ;
F_73 (nid) {
V_166 = ( ( T_2 ) F_74 ( V_171 ) << V_42 -> V_173 ) |
V_9 ;
F_71 ( V_166 , V_98 ) ;
V_16 = F_75 ( V_166 , V_16 ) ;
V_17 = F_76 ( V_166 , V_17 ) ;
}
V_16 &= V_11 ;
V_17 &= V_11 ;
F_69 ( L_26 , V_9 , V_16 , V_17 ) ;
}
static T_1 void F_77 ( int V_164 )
{
union V_169 V_170 ;
int V_174 = V_172 ;
unsigned long V_131 = V_175 ;
unsigned long V_113 ;
V_170 . V_25 = F_67 ( V_176 ) ;
if ( ! V_170 . V_29 . V_158 ) {
F_12 ( L_27 ) ;
return;
}
if ( F_20 () && V_170 . V_177 . V_178 ) {
F_72 ( V_170 . V_25 ) ;
return;
}
V_113 = ( V_170 . V_25 & V_131 ) >> V_174 ;
F_68 ( L_28 , V_113 , V_174 , V_174 , V_164 , V_179 ) ;
V_18 = ( ( T_2 ) V_113 << V_174 ) ;
V_19 = V_18 + ( 1UL << V_174 ) * ( V_164 + 1 ) ;
}
static T_1 void F_78 ( int V_164 )
{
union V_180 V_5 ;
int V_174 = V_181 ;
V_5 . V_25 = F_67 ( V_182 ) ;
if ( V_5 . V_29 . V_158 )
F_68 ( L_29 , V_5 . V_29 . V_113 , V_174 , V_174 , V_164 , V_167 ) ;
else
F_12 ( L_30 ) ;
}
static T_1 void F_79 ( int V_183 , int V_184 , int V_164 )
{
union V_185 V_186 ;
unsigned long V_5 ;
unsigned long V_113 ;
int V_99 , V_187 , V_174 , V_188 , V_189 ;
int V_114 , V_190 , V_191 , V_192 ;
char * V_137 ;
V_137 = V_193 [ V_183 ] . V_137 ;
V_186 . V_25 = F_67 ( V_193 [ V_183 ] . V_186 ) ;
F_12 ( L_31 , V_137 , V_186 . V_25 , V_186 . V_177 . V_113 , V_186 . V_177 . V_188 ) ;
if ( ! V_186 . V_177 . V_158 ) {
F_12 ( L_32 , V_137 ) ;
return;
}
V_174 = V_194 ;
V_113 = ( unsigned long ) V_186 . V_177 . V_113 ;
V_188 = V_186 . V_177 . V_188 ;
V_5 = V_193 [ V_183 ] . V_148 ;
V_187 = V_195 ;
V_184 *= 2 ;
V_164 *= 2 ;
V_189 = V_190 = V_191 = V_192 = - 1 ;
for ( V_99 = 0 ; V_99 < V_187 ; V_99 ++ ) {
union V_196 V_148 ;
V_148 . V_25 = F_67 ( V_5 + V_99 * 8 ) ;
V_114 = V_148 . V_177 . V_114 ;
if ( V_114 < V_184 || V_164 < V_114 )
V_114 = - 1 ;
if ( V_114 == V_190 ) {
V_192 = V_99 ;
if ( V_99 != V_187 - 1 )
continue;
}
if ( V_190 != - 1 || ( V_99 == V_187 - 1 && V_114 != - 1 ) ) {
unsigned long V_197 , V_198 ;
int V_199 , V_200 ;
if ( V_190 == - 1 ) {
V_199 = V_200 = V_99 ;
V_190 = V_114 ;
} else {
V_199 = V_191 ;
V_200 = V_192 ;
}
V_197 = ( V_113 << V_174 ) + V_199 * ( 1ULL << V_188 ) ;
V_198 = ( V_113 << V_174 ) + ( V_200 + 1 ) * ( 1ULL << V_188 ) ;
F_12 ( L_33 , V_137 , V_191 , V_192 , V_190 , V_197 , V_198 ) ;
if ( V_189 < V_200 )
V_189 = V_200 ;
}
V_191 = V_192 = V_99 ;
V_190 = V_114 ;
}
F_12 ( L_34 , V_137 , V_113 , V_174 , V_188 , V_189 ) ;
if ( V_189 >= 0 )
F_68 ( V_137 , V_113 , V_174 , V_188 , V_189 , V_167 ) ;
}
static T_1 void F_80 ( int V_184 , int V_164 )
{
union V_201 V_202 ;
unsigned long V_5 , V_113 ;
int V_174 , V_158 , V_188 , V_203 ;
if ( F_20 () || F_81 () ) {
F_79 ( 0 , V_184 , V_164 ) ;
F_79 ( 1 , V_184 , V_164 ) ;
return;
}
if ( F_22 () ) {
V_5 = V_204 ;
V_174 = V_205 ;
V_202 . V_25 = F_67 ( V_5 ) ;
V_158 = ! ! V_202 . V_65 . V_158 ;
V_113 = V_202 . V_65 . V_113 ;
V_188 = V_202 . V_65 . V_188 ;
V_203 = V_202 . V_65 . V_203 ;
} else if ( F_19 () ) {
V_5 = V_206 ;
V_174 = V_207 ;
V_202 . V_25 = F_67 ( V_5 ) ;
V_158 = ! ! V_202 . V_208 . V_158 ;
V_113 = V_202 . V_208 . V_113 ;
V_188 = V_202 . V_208 . V_188 ;
V_203 = V_202 . V_208 . V_203 ;
} else {
return;
}
if ( V_158 ) {
V_164 &= ( 1 << V_203 ) - 1 ;
F_12 ( L_35 , V_113 , V_174 , V_188 , V_203 , V_164 ) ;
F_68 ( L_36 , V_113 , V_174 , V_188 , V_164 , V_167 ) ;
} else {
F_12 ( L_37 ) ;
}
}
static T_1 void F_82 ( void )
{
F_70 ( V_209 , V_210 ) ;
F_70 ( V_6 , V_211 ) ;
}
static T_1 void F_83 ( void )
{
long V_212 ;
T_2 V_213 ;
V_212 = F_84 ( V_214 , & V_213 ) ;
if ( V_212 != V_215 || V_213 < 100000 ) {
F_85 ( L_38 ) ;
V_216 = 1000000000000UL / 30000UL ;
} else {
V_216 = V_213 ;
}
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
static int F_91 ( unsigned int V_126 )
{
while ( ! F_92 ( V_126 ) -> V_227 ) {
struct V_218 * V_219 = & F_92 ( V_126 ) -> V_219 ;
F_93 ( V_126 , V_223 | V_224 ) ;
F_94 ( V_219 , F_86 , V_126 ) ;
V_219 -> V_228 = V_225 + V_226 ;
F_95 ( V_219 , V_126 ) ;
F_92 ( V_126 ) -> V_227 = 1 ;
V_126 = 0 ;
}
return 0 ;
}
static int F_96 ( unsigned int V_126 )
{
if ( F_92 ( V_126 ) -> V_227 ) {
F_92 ( V_126 ) -> V_227 = 0 ;
F_97 ( & F_92 ( V_126 ) -> V_219 ) ;
}
F_93 ( V_126 , 0xff ) ;
return 0 ;
}
static T_1 void F_98 ( void )
{
F_99 ( V_229 , L_39 ,
F_91 , F_96 ) ;
}
static T_1 void F_98 ( void )
{
}
static T_1 int F_100 ( void )
{
int V_126 ;
if ( F_28 () ) {
F_46 (cpu)
F_91 ( V_126 ) ;
}
return 0 ;
}
int F_101 ( struct V_230 * V_231 , bool V_232 , unsigned int V_233 , T_3 V_234 )
{
int V_235 , V_236 , V_237 ;
if ( ! ( V_234 & V_238 ) )
return 0 ;
if ( ( V_233 & V_239 ) == 0 )
return 0 ;
V_235 = F_102 ( V_231 -> V_236 ) ;
V_236 = V_231 -> V_236 -> V_240 ;
V_237 = F_103 ( V_232 , V_235 , V_236 ) ;
return V_237 ;
}
void F_104 ( void )
{
if ( F_44 () == 0 )
return;
V_42 -> V_241 ++ ;
if ( F_27 () == V_85 )
F_65 ( V_42 -> V_24 ) ;
}
static void F_105 ( struct V_242 * V_243 )
{
union V_22 V_23 ;
union V_244 V_245 ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_23 . V_25 = F_67 ( V_27 ) ;
V_243 -> V_246 = V_23 . V_29 . V_45 ;
if ( F_81 () ) {
V_243 -> V_173 = 0 ;
V_243 -> V_247 = 0 ;
} else if ( F_20 () ) {
V_243 -> V_173 = V_23 . V_177 . V_248 ;
V_245 . V_25 = F_67 ( V_249 ) ;
V_243 -> V_247 = V_245 . V_177 . V_248 ;
} else if ( F_19 () ) {
V_243 -> V_173 = V_23 . V_208 . V_248 ;
V_243 -> V_247 = V_243 -> V_173 == 40 ? 40 : 39 ;
} else if ( F_22 () ) {
V_243 -> V_173 = V_23 . V_65 . V_248 ;
V_243 -> V_247 = V_243 -> V_173 ;
}
V_243 -> V_250 = V_243 -> V_173 ? 64 - V_243 -> V_173 : 0 ;
}
void T_1 F_106 ( struct V_251 * V_252 )
{
union V_20 V_21 ;
struct V_242 V_242 ;
F_105 ( & V_242 ) ;
V_252 -> V_253 = V_242 . V_173 ?
( 1UL << ( V_242 . V_173 + V_242 . V_246 ) ) - 1 :
( 1UL << V_40 . V_46 ) - 1 ;
V_252 -> V_173 = V_242 . V_173 ;
V_252 -> V_246 = V_242 . V_246 ;
V_252 -> V_250 = V_242 . V_250 ;
V_252 -> V_247 = V_242 . V_247 ? V_242 . V_247 : 0 ;
V_252 -> V_43 = V_42 -> V_43 ;
V_252 -> V_44 = V_40 . V_44 ;
V_252 -> V_184 = V_254 ;
V_252 -> V_255 = V_112 ;
V_252 -> V_256 = V_257 ;
V_252 -> V_258 = V_259 ;
V_252 -> V_260 = V_261 ;
V_252 -> V_262 = V_104 ;
V_252 -> V_263 = V_106 ;
V_21 . V_25 = F_67 ( V_26 ) ;
V_40 . V_41 = F_107 (unsigned int, uv_cpuid.gnode_shift, mn.n_val) ;
V_252 -> V_264 = ( V_21 . V_29 . V_21 & ~ ( ( 1 << V_40 . V_41 ) - 1 ) ) >> 1 ;
if ( V_242 . V_173 )
V_252 -> V_265 = ( T_2 ) V_252 -> V_264 << V_242 . V_173 ;
if ( V_266 ) {
V_252 -> V_267 = V_266 -> V_268 ;
V_252 -> V_269 = V_266 -> V_270 ;
V_252 -> V_271 = V_266 -> V_272 ;
V_252 -> V_273 = V_266 -> V_274 ;
V_252 -> V_46 = V_266 -> V_46 ;
V_252 -> V_253 = ( 1UL << V_252 -> V_46 ) - 1 ;
} else {
V_252 -> V_267 = F_67 ( V_182 ) & ~ V_275 ;
V_252 -> V_269 = V_276 ;
}
F_66 ( & V_252 -> V_277 , & V_252 -> V_278 ) ;
V_252 -> V_279 = V_40 . V_59 ;
F_12 ( L_40 , V_252 -> V_246 , V_252 -> V_173 , V_252 -> V_250 , V_252 -> V_247 ) ;
F_12 ( L_41 , V_252 -> V_253 , V_252 -> V_46 , V_252 -> V_44 , V_252 -> V_279 ) ;
F_12 ( L_42 , V_252 -> V_267 , V_252 -> V_269 , V_252 -> V_271 , V_252 -> V_273 ) ;
F_12 ( L_43 , V_252 -> V_265 , V_252 -> V_264 ) ;
}
static void T_1 F_108 ( unsigned long V_280 )
{
V_266 = (struct V_281 * ) V_280 ;
F_12 ( L_44 ) ;
F_12 ( L_45 ,
V_266 -> V_268 , V_266 -> V_270 ,
V_266 -> V_272 , V_266 -> V_274 ,
V_266 -> V_46 ) ;
}
static void T_1 F_109 ( unsigned long V_280 )
{
struct V_91 * V_92 = (struct V_91 * ) V_280 ;
unsigned long V_282 = 0 ;
int V_183 = 0 ;
int V_283 = 999999 , V_284 = 99999 ;
int V_285 = - 1 , V_286 = - 1 ;
V_93 = V_92 ;
for (; V_92 -> type != V_107 ; V_92 ++ ) {
if ( ! V_183 ) {
F_12 ( L_46 ) ;
F_12 ( L_47 , L_48 , L_49 , L_50 , L_51 , L_52 , L_53 , L_54 ) ;
}
F_12 ( L_55 ,
V_183 ++ ,
( unsigned long ) V_282 << V_117 ,
( unsigned long ) V_92 -> V_109 << V_117 ,
( ( unsigned long ) ( V_92 -> V_109 - V_282 ) ) >>
( 30 - V_117 ) ,
V_92 -> type , V_92 -> V_114 , V_92 -> V_111 , V_92 -> V_24 ) ;
V_282 = V_92 -> V_109 ;
if ( V_283 > V_92 -> V_111 )
V_283 = V_92 -> V_111 ;
if ( V_285 < V_92 -> V_111 )
V_285 = V_92 -> V_111 ;
if ( V_284 > V_92 -> V_24 )
V_284 = V_92 -> V_24 ;
if ( V_286 < V_92 -> V_24 )
V_286 = V_92 -> V_24 ;
}
V_112 = V_283 ;
V_110 = V_285 ;
V_254 = V_284 ;
V_287 = V_286 ;
V_104 = V_183 ;
F_12 ( L_56 , V_183 , V_112 , V_110 , V_254 , V_287 ) ;
}
static int T_1 F_110 ( void )
{
struct V_288 * V_289 ;
int V_99 ;
if ( V_42 -> V_43 < V_39 )
return 0 ;
V_289 = V_288 ;
if ( ( ! V_289 ) || ( V_289 -> V_30 < V_290 ) ) {
int V_291 = V_289 ? V_289 -> V_30 : 0 ;
F_24 ( L_57 , V_291 , V_290 ) ;
F_24 ( L_58 ) ;
V_83 = V_89 ;
return - V_292 ;
}
for ( V_99 = 0 ; V_289 -> V_293 [ V_99 ] . type != V_294 ; V_99 ++ ) {
unsigned long V_280 = V_289 -> V_293 [ V_99 ] . V_295 ;
if ( ! V_280 )
continue;
V_280 = V_280 + ( unsigned long ) V_289 ;
switch ( V_289 -> V_293 [ V_99 ] . type ) {
case V_296 :
F_108 ( V_280 ) ;
break;
case V_297 :
F_109 ( V_280 ) ;
break;
}
}
return 0 ;
}
static T_1 void F_111 ( struct V_251 * V_298 )
{
int V_99 , V_299 = 0 ;
F_12 ( L_59 , V_300 ) ;
for ( V_99 = 0 ; V_99 < V_300 ; V_99 ++ ) {
unsigned long V_301 ;
V_301 = F_67 ( V_302 + V_99 * 8 ) ;
if ( V_301 )
F_12 ( L_60 , V_99 , V_301 ) ;
V_299 += F_112 ( V_301 ) ;
}
if ( V_303 != V_299 )
V_303 = V_299 ;
}
static void T_1 F_113 ( void )
{
struct V_91 * V_92 = V_93 ;
int V_304 , V_305 ;
int V_126 , V_99 , V_306 ;
int V_307 = V_112 ;
int V_308 = V_110 ;
int V_309 = V_254 ;
int V_310 = V_287 ;
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
V_98 = V_304 * sizeof( V_259 [ 0 ] ) ;
V_259 = F_114 ( V_98 , V_105 ) ;
V_261 = F_114 ( V_98 , V_105 ) ;
V_305 = V_310 - V_309 + 1 ;
V_98 = V_305 * sizeof( V_257 [ 0 ] ) ;
V_257 = F_114 ( V_98 , V_105 ) ;
F_33 ( ! V_259 || ! V_261 || ! V_257 ) ;
for ( V_99 = 0 ; V_99 < V_304 ; V_99 ++ )
V_259 [ V_99 ] = V_261 [ V_99 ] = V_311 ;
for ( V_99 = 0 ; V_99 < V_305 ; V_99 ++ )
V_257 [ V_99 ] = V_311 ;
F_12 ( L_63 ) ;
for (; V_92 -> type != V_107 ; V_92 ++ ) {
if ( V_92 -> type == V_108 )
continue;
V_99 = V_92 -> V_111 - V_307 ;
if ( V_261 [ V_99 ] != V_311 )
continue;
V_261 [ V_99 ] = V_92 -> V_24 ;
V_99 = V_92 -> V_24 - V_309 ;
V_257 [ V_99 ] = V_92 -> V_111 ;
F_12 ( L_64 ,
V_92 -> V_111 , V_92 -> type , V_92 -> V_114 ,
V_261 [ V_92 -> V_111 - V_307 ] ,
V_257 [ V_92 -> V_24 - V_309 ] ) ;
}
V_306 = - 1 ;
F_115 (cpu) {
int V_171 = F_116 ( V_126 ) ;
int V_128 , V_111 ;
if ( V_306 == V_171 )
continue;
V_306 = V_171 ;
V_128 = F_39 ( V_129 , V_126 ) ;
V_111 = V_128 >> V_40 . V_59 ;
V_259 [ V_111 - V_307 ] = V_171 ;
F_12 ( L_65 ,
V_111 , V_128 , V_171 ) ;
}
V_98 = F_117 () * sizeof( V_312 [ 0 ] ) ;
V_312 = F_114 ( V_98 , V_105 ) ;
F_33 ( ! V_312 ) ;
for ( V_306 = 0 ; V_306 < F_117 () ; V_306 ++ ) {
unsigned short V_111 ;
for ( V_111 = V_307 ; V_111 <= V_308 ; V_111 ++ ) {
if ( V_306 == V_259 [ V_111 - V_307 ] ) {
V_312 [ V_306 ] = V_261 [ V_111 - V_307 ] ;
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
if ( V_259 [ V_99 ] == V_311 || V_99 != V_259 [ V_99 ] )
break;
if ( V_99 >= V_304 ) {
F_118 ( V_259 ) ;
V_259 = NULL ;
F_12 ( L_68 ) ;
}
}
if ( V_307 == V_309 ) {
for ( V_99 = 0 ; V_99 < V_304 ; V_99 ++ )
if ( V_261 [ V_99 ] != V_311 &&
V_261 [ V_99 ] != V_99 + V_309 )
break;
if ( V_99 >= V_304 ) {
F_118 ( V_261 ) ;
V_261 = NULL ;
F_12 ( L_69 ) ;
}
}
}
static void T_1 F_119 ( void )
{
struct V_251 V_298 = { 0 } ;
int V_98 , V_126 , V_313 ;
unsigned short V_184 = 9999 , V_164 = 0 ;
char * V_314 = F_81 () ? L_70 :
F_20 () ? L_71 :
F_19 () ? L_72 :
F_22 () ? L_73 : NULL ;
if ( ! V_314 ) {
F_24 ( L_74 ) ;
return;
}
F_12 ( L_75 , V_314 ) ;
F_82 () ;
F_120 () ;
if ( F_110 () < 0 )
return;
F_113 () ;
F_31 () ;
F_106 ( & V_298 ) ;
V_303 = F_117 () ;
if ( ! V_312 )
F_111 ( & V_298 ) ;
F_12 ( L_76 , F_121 () , F_117 () , F_122 () ) ;
F_123 ( 0 , & V_315 , & V_316 , & V_317 , & V_318 , & V_319 ) ;
V_298 . V_320 = V_317 ;
F_83 () ;
V_98 = sizeof( void * ) * F_121 () ;
V_321 = F_32 ( V_98 , V_105 ) ;
F_33 ( ! V_321 ) ;
V_98 = sizeof( struct V_251 ) ;
F_124 (nodeid) {
struct V_251 * V_322 ;
if ( V_321 [ V_313 ] ) {
F_24 ( L_77 , V_313 ) ;
F_26 () ;
}
V_322 = ( V_313 == 0 ) ? & V_76 : F_125 ( V_98 , V_105 , V_313 ) ;
F_33 ( ! V_322 ) ;
V_321 [ V_313 ] = V_322 ;
V_322 = F_126 ( V_313 ) ;
F_33 ( ! V_322 ) ;
* V_322 = V_298 ;
if ( V_312 )
V_322 -> V_24 = V_312 [ V_313 ] ;
else
V_322 -> V_24 = 0xffff ;
V_322 -> V_323 = F_127 ( V_313 ) ;
V_322 -> V_324 = - 1 ;
V_322 -> V_325 = 0 ;
V_322 -> V_241 = 0 ;
}
F_128 (cpu) {
int V_128 = F_39 ( V_129 , V_126 ) ;
int V_326 ;
unsigned short V_24 ;
V_313 = F_116 ( V_126 ) ;
V_326 = F_129 ( V_126 ) ;
V_24 = F_36 ( V_128 ) ;
F_130 ( V_126 ) -> V_75 = F_126 ( V_313 ) ;
F_130 ( V_126 ) -> V_327 = F_131 ( V_126 ) -> V_325 ++ ;
if ( F_131 ( V_126 ) -> V_324 == - 1 )
F_131 ( V_126 ) -> V_324 = F_116 ( V_126 ) ;
if ( V_313 != V_326 &&
F_126 ( V_326 ) -> V_24 == 0xffff )
F_126 ( V_326 ) -> V_24 = V_24 ;
else if ( F_131 ( V_126 ) -> V_24 == 0xffff )
F_131 ( V_126 ) -> V_24 = V_24 ;
F_92 ( V_126 ) -> V_295 = F_132 ( V_128 ) ;
}
F_124 (nodeid) {
unsigned short V_24 = F_126 ( V_313 ) -> V_24 ;
if ( V_24 == 0xffff ) {
unsigned long V_166 ;
V_166 = F_133 ( V_313 ) << V_328 ;
V_24 = F_134 ( F_135 ( V_166 ) ) ;
F_126 ( V_313 ) -> V_24 = V_24 ;
}
V_184 = F_75 ( V_24 , V_184 ) ;
V_164 = F_76 ( V_24 , V_164 ) ;
F_12 ( L_78 ,
V_313 ,
F_126 ( V_313 ) -> V_24 ,
F_126 ( V_313 ) -> V_325 ) ;
}
F_12 ( L_79 , V_184 , V_164 ) ;
F_77 ( V_164 ) ;
F_78 ( V_164 ) ;
F_80 ( V_184 , V_164 ) ;
F_136 () ;
F_104 () ;
F_98 () ;
F_137 ( L_80 , NULL ) ;
F_138 ( F_101 ) ;
if ( F_139 () )
V_329 = V_330 ;
}
void T_1 F_140 ( void )
{
if ( F_2 ( ! F_28 () && ! F_29 () ) )
return;
if ( F_28 () )
F_119 () ;
else
F_141 () ;
}
