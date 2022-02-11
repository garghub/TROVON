void F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
V_6 = F_2 ( V_3 , struct V_5 * ) ;
F_3 ( L_1 , V_6 , V_3 -> V_8 ) ;
#ifdef F_4
F_5 ( V_2 , V_6 , L_2 ) ;
#endif
F_6 ( V_2 ) ;
if ( V_6 -> V_9 == V_10 ||
V_6 -> V_9 == V_11 ) {
V_7 = F_7 ( V_2 , V_6 ,
V_6 -> V_9 == V_11 , V_4 ) ;
if ( V_7 ) {
V_6 = F_2 ( V_7 , struct V_5 * ) ;
#ifdef F_4
F_5 ( V_2 , V_6 , L_3 ) ;
#endif
F_8 ( V_2 , V_7 , V_12 , V_4 ) ;
}
}
}
static T_1 * F_7 ( struct V_1 * V_2 , struct V_5 * V_13 ,
int V_14 , int V_4 )
{
T_1 * V_3 ;
struct V_5 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
const struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
int V_24 ;
int error ;
int V_25 ;
F_9 ( struct V_26 , V_27 ) ;
F_9 ( struct V_26 , V_28 ) ;
if ( ! ( V_3 = F_10 ( V_2 ) ) )
return V_3 ;
V_15 = F_2 ( V_3 , struct V_5 * ) ;
V_15 -> V_29 = V_13 -> V_30 ;
V_15 -> V_9 = V_13 -> V_9 ;
V_15 -> V_31 = V_32 ;
V_15 -> V_33 = V_34 ;
V_15 -> V_35 = V_13 -> V_35 ;
V_15 -> V_36 = 0 ;
V_15 -> V_37 = 0 ;
V_27 . V_38 = V_39 ;
V_27 . V_40 = 0 ;
V_27 . V_41 = 0 ;
V_27 . V_42 = ( void * ) ( V_15 + 1 ) ;
error = 0 ;
if ( V_14 ) {
if ( ! V_4 && F_11 ( V_2 , V_13 ) )
error = V_43 ;
else if ( F_12 ( V_2 , V_13 ) )
V_27 . V_41 = V_44 ;
}
V_19 = (struct V_18 * ) V_27 . V_42 ;
F_13 ( V_2 , & V_27 , ( V_45 ) V_46 , 0 , 0 ) ;
F_13 ( V_2 , & V_27 , ( V_45 ) V_47 , 0 , 0 ) ;
V_28 = V_27 ;
F_13 ( V_2 , & V_27 , ( V_45 ) V_48 , 0 , 0 ) ;
F_13 ( V_2 , & V_27 , ( V_45 ) V_49 , 0 , 0 ) ;
V_27 . V_40 = error ;
V_22 = V_13 -> V_37 ;
V_17 = (struct V_16 * ) ( V_13 + 1 ) ;
while ( ! V_27 . V_40 && V_22 > 0 ) {
if ( ( ( V_45 ) V_22 < V_17 -> V_50 + V_51 ) || ( V_17 -> V_50 & 3 ) ) {
V_27 . V_40 = V_52 ;
break ;
}
if ( ( ( V_25 = ( V_17 -> V_53 & 0xf000 ) ) == 0x2000 ) ||
V_25 == 0x3000 || V_25 == 0x4000 ) {
V_23 = * ( ( V_54 * ) V_17 + V_51 + 3 ) ;
V_24 = V_23 ;
if ( ! V_14 && ( V_17 -> V_50 != 4 ) ) {
V_27 . V_40 = V_52 ;
break ;
}
if ( ! V_23 && ! V_14 ) {
switch ( V_25 ) {
case 0x2000 :
V_23 = V_55 ;
V_24 = V_23 - 1 + V_56 ;
break ;
case 0x3000 :
V_23 = V_57 ;
V_24 = V_23 - 1 + V_58 ;
break ;
case 0x4000 :
V_23 = V_59 ;
V_24 = V_23 - 1 + V_60 ;
#ifndef F_14
if ( V_2 -> V_61 . V_62 == V_63 )
V_24 = V_59 ;
#endif
break ;
}
}
}
else {
if ( ! V_14 && ( V_17 -> V_50 != 0 ) ) {
V_27 . V_40 = V_52 ;
break ;
}
V_23 = 0 ;
V_24 = 0 ;
}
while ( V_23 <= V_24 ) {
V_21 = F_15 ( V_17 -> V_53 ) ;
if ( V_21 && V_21 -> V_64 == V_65 && ! V_14 ) {
V_21 ++ ;
while ( V_21 -> V_64 == V_66 ||
V_21 -> V_64 == V_67 ) {
F_13 ( V_2 , & V_27 , V_21 -> V_68 ,
V_23 , V_4 ) ;
V_21 ++ ;
}
}
else if ( V_17 -> V_53 != V_69 &&
( ! V_14 || ( V_17 -> V_53 != V_48 ) ) ) {
int V_70 ;
if ( V_27 . V_41 ) {
F_13 ( V_2 , & V_27 , V_17 -> V_53 ,
V_23 , V_4 ) ;
}
else if ( V_14 ) {
V_70 = F_16 ( V_2 , V_17 , V_23 , V_4 , 1 ) ;
F_13 ( V_2 , & V_27 , V_17 -> V_53 ,
V_23 , V_4 ) ;
V_27 . V_40 = V_70 ;
}
else {
if ( V_21 && V_21 -> V_64 == V_71 ) {
V_27 . V_40 =
V_72 ;
}
F_13 ( V_2 , & V_27 , V_17 -> V_53 ,
V_23 , V_4 ) ;
}
}
if ( V_27 . V_40 )
break ;
V_23 ++ ;
}
V_22 -= V_17 -> V_50 + V_51 ;
V_17 = (struct V_16 * ) ( ( char * ) V_17 + V_17 -> V_50 + V_51 ) ;
}
V_15 -> V_37 = V_39 - V_27 . V_38 ;
V_3 -> V_8 = V_15 -> V_37 + sizeof( struct V_5 ) ;
V_19 -> V_73 = V_27 . V_41 ? V_27 . V_41 :
V_27 . V_40 ? V_27 . V_40 : V_74 ;
if ( V_14 && ( V_19 -> V_73 == V_74 ) ) {
V_2 -> V_75 . V_76 . V_77 ++ ;
F_17 ( V_2 , V_2 -> V_75 . V_76 . V_78 ) ;
V_2 -> V_75 . V_79 = V_13 -> V_80 ;
F_13 ( V_2 , & V_28 , ( V_45 ) V_48 , 0 , 0 ) ;
F_13 ( V_2 , & V_28 , ( V_45 ) V_49 , 0 , 0 ) ;
}
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_16 * V_17 ;
int V_81 ;
char * V_82 ;
V_82 = ( char * ) & V_2 -> V_75 . V_83 ;
for ( V_81 = 0 ; V_81 < 8 && ! V_82 [ V_81 ] ; V_81 ++ )
;
if ( V_81 != 8 ) {
if ( memcmp ( ( char * ) & V_6 -> V_80 ,
( char * ) & V_2 -> V_75 . V_83 , 8 ) )
return 1 ;
}
V_82 = ( char * ) V_2 -> V_75 . V_84 ;
for ( V_81 = 0 ; V_81 < 8 && ! V_82 [ V_81 ] ; V_81 ++ )
;
if ( V_81 != 8 ) {
V_17 = (struct V_16 * ) F_18 ( V_2 , V_6 , V_69 ) ;
if ( ! V_17 )
return 1 ;
if ( V_17 -> V_50 != 8 )
return 1 ;
if ( memcmp ( ( char * ) ( V_17 + 1 ) , ( char * ) V_2 -> V_75 . V_84 , 8 ) )
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_16 * V_17 ;
struct V_85 * V_86 ;
V_17 = (struct V_16 * ) F_18 ( V_2 , V_6 , V_48 ) ;
if ( V_17 ) {
V_86 = (struct V_85 * ) V_17 ;
if ( ( V_2 -> V_75 . V_76 . V_77 != V_86 -> V_77 ) ||
memcmp ( ( char * ) V_2 -> V_75 . V_76 . V_78 ,
( char * ) V_86 -> V_78 , 8 ) )
return 1 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 , struct V_26 * V_27 , V_45 V_87 ,
int V_23 , int V_4 )
{
struct V_16 * V_17 ;
const struct V_20 * V_21 ;
struct V_88 * V_89 = NULL ;
struct V_90 * V_91 = NULL ;
int V_22 ;
int V_92 ;
char * V_93 ;
char * V_94 ;
const char * V_95 ;
char V_96 ;
int V_25 ;
char * V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
if ( V_27 -> V_40 )
return ;
V_21 = F_15 ( V_87 ) ;
if ( V_21 && V_21 -> V_64 == V_71 )
return ;
V_94 = ( char * ) ( V_27 -> V_42 ) ;
V_22 = V_27 -> V_38 ;
V_92 = V_22 ;
V_17 = (struct V_16 * ) V_94 ;
V_94 += V_51 ;
V_22 -= V_51 ;
if ( ( ( V_25 = ( V_87 & 0xf000 ) ) == 0x2000 ) ||
V_25 == 0x3000 || V_25 == 0x4000 ) {
if ( V_22 < 4 )
goto V_102 ;
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
V_94 [ 2 ] = 0 ;
V_94 [ 3 ] = V_23 ;
V_22 -= 4 ;
V_94 += 4 ;
}
V_98 = V_23 - V_55 ;
V_99 = V_23 - V_57 ;
V_100 = V_23 - V_59 ;
switch ( V_25 ) {
case 0x1000 :
default :
V_97 = ( char * ) ( & V_2 -> V_75 ) ;
break ;
case 0x2000 :
if ( V_98 < 0 || V_98 >= V_56 ) {
V_27 -> V_40 = V_103 ;
return ;
}
V_97 = ( char * ) ( & V_2 -> V_75 . V_104 [ V_98 ] ) ;
V_89 = (struct V_88 * ) V_97 ;
break ;
case 0x3000 :
if ( V_99 < 0 || V_99 >= V_58 ) {
V_27 -> V_40 = V_103 ;
return ;
}
V_97 = ( char * ) ( & V_2 -> V_75 . V_105 [ V_99 ] ) ;
break ;
case 0x4000 :
if ( V_100 < 0 || V_100 >= F_19 ( V_2 ) ) {
V_27 -> V_40 = V_103 ;
return ;
}
V_97 = ( char * ) ( & V_2 -> V_75 . V_82 [ F_20 ( V_2 , V_100 ) ] ) ;
V_91 = (struct V_90 * ) V_97 ;
break ;
}
V_95 = NULL ;
switch ( V_87 ) {
case V_106 :
case V_107 :
#ifdef F_21
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
#endif
#ifdef F_22
case V_114 :
case V_115 :
#endif
case V_116 :
if ( ! V_4 ) {
V_27 -> V_40 = V_103 ;
return ;
}
break ;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
F_23 ( V_2 ) ;
break ;
case V_123 :
V_91 -> V_124 = F_24 (
F_25 ( V_2 , F_20 ( V_2 , V_100 ) ) ) ;
break ;
case V_46 :
* ( V_125 * ) V_94 = 0 ;
V_101 = 4 ;
goto V_126 ;
case V_47 :
F_17 ( V_2 , V_2 -> V_75 . V_127 ) ;
break ;
case V_128 :
#if V_60 == 12
V_95 = L_4 ;
#else
#if V_60 == 2
if ( V_2 -> V_61 . V_62 == V_63 )
V_95 = L_5 ;
else
V_95 = L_6 ;
#else
#if V_60 == 24
V_95 = L_7 ;
#else
????
#endif
#endif
#endif
break ;
case V_129 :
{
V_101 = F_26 ( V_2 , V_94 , V_99 ) ;
goto V_126 ;
}
case V_130 :
{
struct V_131 * V_132 ;
V_132 = (struct V_131 * ) V_94 ;
V_132 -> V_133 = V_2 -> V_75 . V_134 ;
V_132 -> V_135 = V_2 -> V_75 . V_136 ;
V_101 = sizeof( struct V_131 ) ;
goto V_126 ;
}
case V_137 :
{
struct V_138 * V_132 ;
V_132 = (struct V_138 * ) V_94 ;
V_132 -> V_139 =
V_2 -> V_75 . V_104 [ V_140 ] . V_141 ;
V_132 -> V_142 =
( V_89 -> V_143 ? V_144 : 0 ) |
( V_89 -> V_145 ? V_146 : 0 ) ;
V_132 -> V_147 =
V_89 -> V_148 ;
V_132 -> V_149 =
V_89 -> V_150 ;
V_132 -> V_151 = 0 ;
V_101 = sizeof( struct V_138 ) ;
goto V_126 ;
}
case V_152 :
{
struct V_153 * V_132 ;
V_132 = (struct V_153 * ) V_94 ;
V_132 -> V_154 =
V_89 -> V_155 ;
V_132 -> V_156 =
V_89 -> V_157 ;
V_132 -> V_158 =
V_89 -> V_159 ;
V_132 -> V_160 =
V_89 -> V_161 ;
V_132 -> V_162 =
V_89 -> V_163 ;
V_101 = sizeof( struct V_153 ) ;
goto V_126 ;
}
case V_164 :
{
struct V_165 * V_132 ;
V_132 = (struct V_165 * ) V_94 ;
V_132 -> V_166 =
V_89 -> V_167 ;
V_132 -> V_168 =
V_89 -> V_169 ;
V_132 -> V_170 =
V_89 -> V_171 ;
V_132 -> V_172 =
V_89 -> V_173 ;
V_101 = sizeof( struct V_165 ) ;
goto V_126 ;
}
case V_174 :
{
struct V_175 * V_132 ;
V_132 = (struct V_175 * ) V_94 ;
V_132 -> V_176 =
V_89 -> V_177 ;
V_132 -> V_178 =
V_89 -> V_141 ;
V_132 -> V_179 =
V_89 -> V_180 ;
V_132 -> V_181 =
V_89 -> V_150 ;
V_132 -> V_182 =
V_89 -> V_183 ;
V_132 -> V_184 =
V_89 -> V_185 ;
V_132 -> V_186 =
V_89 -> V_187 ;
V_132 -> V_188 =
V_89 -> V_148 ;
V_101 = sizeof( struct V_175 ) ;
goto V_126 ;
}
case V_189 :
{
struct V_190 * V_132 ;
V_132 = (struct V_190 * ) V_94 ;
V_132 -> V_191 =
V_89 -> V_192 ;
V_132 -> V_193 =
V_89 -> V_194 ;
V_132 -> V_195 =
V_89 -> V_187 ;
V_132 -> V_196 =
V_89 -> V_197 ;
V_101 = sizeof( struct V_190 ) ;
goto V_126 ;
}
case V_198 :
{
struct V_199 * V_132 ;
V_132 = (struct V_199 * ) V_94 ;
V_132 -> V_200 =
V_91 -> V_201 ;
V_132 -> V_202 = 0 ;
V_132 -> V_203 =
V_91 -> V_204 ;
V_132 -> V_205 =
V_91 -> V_206 ;
V_132 -> V_207 =
V_91 -> V_208 ;
V_132 -> V_209 =
V_91 -> V_210 ;
V_132 -> V_211 =
V_91 -> V_212 ;
V_101 = sizeof( struct V_199 ) ;
goto V_126 ;
}
case V_213 :
{
struct V_214 * V_132 ;
V_132 = (struct V_214 * ) V_94 ;
V_132 -> V_215 =
V_91 -> V_216 ;
V_132 -> V_217 =
V_91 -> V_218 ;
V_132 -> V_219 =
V_91 -> V_220 ;
V_132 -> V_221 =
V_91 -> V_222 ;
V_132 -> V_223 =
V_91 -> V_224 ;
V_101 = sizeof( struct V_214 ) ;
goto V_126 ;
}
case V_225 :
{
struct V_226 * V_132 ;
V_132 = (struct V_226 * ) V_94 ;
V_132 -> V_227 =
V_91 -> V_228 ;
V_132 -> V_229 =
V_91 -> V_230 ;
V_101 = sizeof( struct V_226 ) ;
goto V_126 ;
}
case V_231 :
{
struct V_232 * V_132 ;
V_132 = (struct V_232 * ) V_94 ;
V_132 -> V_233 =
V_91 -> V_234 ;
V_132 -> V_235 =
V_91 -> V_236 ;
V_132 -> V_237 =
V_91 -> V_238 ;
memcpy ( ( char * ) & V_132 -> V_239 ,
( char * ) V_91 -> V_240 , 4 ) ;
V_132 -> V_241 =
V_91 -> V_218 ;
V_132 -> V_242 =
V_91 -> V_222 ;
V_101 = sizeof( struct V_232 ) ;
goto V_126 ;
}
default :
break ;
}
if ( ! V_21 ) {
V_27 -> V_40 = ( V_87 & 0xff00 ) ? V_103 :
V_72 ;
return ;
}
switch ( V_21 -> V_64 ) {
case V_66 :
case V_67 :
break ;
default :
V_27 -> V_40 = V_72 ;
return ;
}
V_93 = V_97 + V_21 -> V_243 ;
if ( ! V_95 )
V_95 = V_21 -> V_244 ;
while ( ( V_96 = * V_95 ++ ) ) {
switch( V_96 ) {
case 'b' :
case 'w' :
case 'l' :
break ;
case 'S' :
case 'E' :
case 'R' :
case 'r' :
if ( V_22 < 4 )
goto V_245 ;
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
#ifdef F_27
if ( V_96 == 'r' ) {
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
}
else {
V_94 [ 3 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
}
#else
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
#endif
V_94 += 4 ;
V_22 -= 4 ;
break ;
case 'I' :
if ( V_22 < 2 )
goto V_245 ;
#ifdef F_27
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 0 ] = * V_93 ++ ;
#else
V_94 [ 0 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
#endif
V_94 += 2 ;
V_22 -= 2 ;
break ;
case 'F' :
case 'B' :
if ( V_22 < 4 )
goto V_245 ;
V_22 -= 4 ;
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
V_94 [ 2 ] = 0 ;
V_94 [ 3 ] = * V_93 ++ ;
V_94 += 4 ;
break ;
case 'C' :
case 'T' :
case 'L' :
if ( V_22 < 4 )
goto V_245 ;
#ifdef F_27
V_94 [ 3 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 0 ] = * V_93 ++ ;
#else
V_94 [ 0 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
#endif
V_22 -= 4 ;
V_94 += 4 ;
break ;
case '2' :
if ( V_22 < 4 )
goto V_245 ;
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
V_22 -= 4 ;
V_94 += 4 ;
break ;
case '4' :
if ( V_22 < 4 )
goto V_245 ;
V_94 [ 0 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
V_22 -= 4 ;
V_94 += 4 ;
break ;
case 'A' :
if ( V_22 < 8 )
goto V_245 ;
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
memcpy ( ( char * ) V_94 + 2 , ( char * ) V_93 , 6 ) ;
V_94 += 8 ;
V_93 += 8 ;
V_22 -= 8 ;
break ;
case '8' :
if ( V_22 < 8 )
goto V_245 ;
memcpy ( ( char * ) V_94 , ( char * ) V_93 , 8 ) ;
V_94 += 8 ;
V_93 += 8 ;
V_22 -= 8 ;
break ;
case 'D' :
if ( V_22 < 32 )
goto V_245 ;
memcpy ( ( char * ) V_94 , ( char * ) V_93 , 32 ) ;
V_94 += 32 ;
V_93 += 32 ;
V_22 -= 32 ;
break ;
case 'P' :
if ( V_22 < 8 )
goto V_245 ;
V_94 [ 0 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
V_94 [ 4 ] = * V_93 ++ ;
V_94 [ 5 ] = * V_93 ++ ;
V_94 [ 6 ] = * V_93 ++ ;
V_94 [ 7 ] = * V_93 ++ ;
V_94 += 8 ;
V_22 -= 8 ;
break ;
default :
F_28 ( V_2 , V_246 , V_247 ) ;
break ;
}
}
V_248:
if ( V_22 & 3 ) {
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
V_94 += 4 - ( V_22 & 3 ) ;
V_22 = V_22 & ~ 3 ;
}
V_17 -> V_53 = V_87 ;
V_17 -> V_50 = V_92 - V_22 - V_51 ;
V_27 -> V_42 = ( void * ) V_94 ;
V_27 -> V_38 = V_22 ;
return ;
V_126:
V_22 -= V_101 ;
V_94 += V_101 ;
goto V_248 ;
V_245:
V_27 -> V_40 = V_249 ;
return ;
V_102:
V_27 -> V_40 = V_52 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_23 ,
int V_4 , int V_14 )
{
#define F_29 ( T_2 ) if (set) (x)
const struct V_20 * V_21 ;
int V_22 ;
char * V_93 ;
char * V_94 ;
const char * V_95 ;
char V_96 ;
char * V_97 ;
struct V_250 * V_75 ;
struct V_88 * V_89 = NULL ;
struct V_251 * V_252 = NULL ;
struct V_90 * V_91 = NULL ;
int V_98 ;
int V_99 ;
int V_100 ;
F_9 ( V_54 , V_253 ) ;
F_9 ( V_45 , V_254 ) ;
F_9 ( V_255 , V_256 ) ;
V_98 = V_23 - V_55 ;
V_99 = V_23 - V_57 ;
V_100 = V_23 - V_59 ;
V_22 = V_17 -> V_50 ;
V_93 = ( char * ) ( V_17 + 1 ) ;
V_75 = & V_2 -> V_75 ;
switch ( V_17 -> V_53 & 0xf000 ) {
case 0x1000 :
default :
V_97 = ( char * ) V_75 ;
break ;
case 0x2000 :
if ( V_98 < 0 || V_98 >= V_56 ) {
return V_103 ;
}
V_89 = & V_2 -> V_75 . V_104 [ V_98 ] ;
V_97 = ( char * ) V_89 ;
V_93 += 4 ;
V_22 -= 4 ;
break ;
case 0x3000 :
if ( V_99 < 0 || V_99 >= V_58 ) {
return V_103 ;
}
V_252 = & V_2 -> V_75 . V_105 [ V_99 ] ;
V_97 = ( char * ) V_252 ;
V_93 += 4 ;
V_22 -= 4 ;
break ;
case 0x4000 :
if ( V_100 < 0 || V_100 >= F_19 ( V_2 ) ) {
return V_103 ;
}
V_91 = & V_2 -> V_75 . V_82 [ F_20 ( V_2 , V_100 ) ] ;
V_97 = ( char * ) V_91 ;
V_93 += 4 ;
V_22 -= 4 ;
break ;
}
switch ( V_17 -> V_53 ) {
case V_106 :
case V_107 :
#ifdef F_21
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
#endif
#ifdef F_22
case V_114 :
case V_115 :
#endif
case V_116 :
if ( ! V_4 )
return V_103 ;
break ;
}
V_21 = F_15 ( V_17 -> V_53 ) ;
if ( ! V_21 )
return ( V_17 -> V_53 & 0xff00 ) ? V_103 :
V_72 ;
switch ( V_21 -> V_64 ) {
case V_67 :
case V_71 :
break ;
default :
return V_72 ;
}
V_94 = V_97 + V_21 -> V_243 ;
V_95 = V_21 -> V_244 ;
while ( V_95 && ( V_96 = * V_95 ++ ) ) {
switch( V_96 ) {
case 'b' :
V_94 = ( char * ) & V_253 ;
break ;
case 'w' :
V_94 = ( char * ) & V_254 ;
break ;
case 'l' :
V_94 = ( char * ) & V_256 ;
break ;
case 'S' :
case 'E' :
case 'R' :
case 'r' :
if ( V_22 < 4 ) {
goto V_245 ;
}
if ( V_93 [ 0 ] | V_93 [ 1 ] )
goto V_257 ;
#ifdef F_27
if ( V_96 == 'r' ) {
V_94 [ 0 ] = V_93 [ 2 ] ;
V_94 [ 1 ] = V_93 [ 3 ] ;
}
else {
V_94 [ 1 ] = V_93 [ 2 ] ;
V_94 [ 0 ] = V_93 [ 3 ] ;
}
#else
V_94 [ 0 ] = V_93 [ 2 ] ;
V_94 [ 1 ] = V_93 [ 3 ] ;
#endif
V_93 += 4 ;
V_94 += 2 ;
V_22 -= 4 ;
break ;
case 'F' :
case 'B' :
if ( V_22 < 4 ) {
goto V_245 ;
}
if ( V_93 [ 0 ] | V_93 [ 1 ] | V_93 [ 2 ] )
goto V_257 ;
V_94 [ 0 ] = V_93 [ 3 ] ;
V_22 -= 4 ;
V_93 += 4 ;
V_94 += 4 ;
break ;
case 'C' :
case 'T' :
case 'L' :
if ( V_22 < 4 ) {
goto V_245 ;
}
#ifdef F_27
V_94 [ 3 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 0 ] = * V_93 ++ ;
#else
V_94 [ 0 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
#endif
V_22 -= 4 ;
V_94 += 4 ;
break ;
case 'A' :
if ( V_22 < 8 )
goto V_245 ;
if ( V_14 )
memcpy ( V_94 , V_93 + 2 , 6 ) ;
V_94 += 8 ;
V_93 += 8 ;
V_22 -= 8 ;
break ;
case '4' :
if ( V_22 < 4 )
goto V_245 ;
if ( V_14 )
memcpy ( V_94 , V_93 , 4 ) ;
V_94 += 4 ;
V_93 += 4 ;
V_22 -= 4 ;
break ;
case '8' :
if ( V_22 < 8 )
goto V_245 ;
if ( V_14 )
memcpy ( V_94 , V_93 , 8 ) ;
V_94 += 8 ;
V_93 += 8 ;
V_22 -= 8 ;
break ;
case 'D' :
if ( V_22 < 32 )
goto V_245 ;
if ( V_14 )
memcpy ( V_94 , V_93 , 32 ) ;
V_94 += 32 ;
V_93 += 32 ;
V_22 -= 32 ;
break ;
case 'P' :
if ( V_14 ) {
V_94 [ 0 ] = * V_93 ++ ;
V_94 [ 1 ] = * V_93 ++ ;
V_94 [ 2 ] = * V_93 ++ ;
V_94 [ 3 ] = * V_93 ++ ;
V_94 [ 4 ] = * V_93 ++ ;
V_94 [ 5 ] = * V_93 ++ ;
V_94 [ 6 ] = * V_93 ++ ;
V_94 [ 7 ] = * V_93 ++ ;
}
V_94 += 8 ;
V_22 -= 8 ;
break ;
default :
F_28 ( V_2 , V_258 , V_259 ) ;
return V_72 ;
}
}
switch ( V_17 -> V_53 ) {
case V_260 :
if ( V_254 & ~ 1 )
goto V_257 ;
F_29 ( V_75 -> V_261 = V_254 ) ;
break ;
case V_262 :
if ( ! ( V_254 & V_263 ) )
goto V_257 ;
F_29 ( V_75 -> V_264 = V_254 ) ;
break ;
case V_265 :
if ( V_254 < 2 || V_254 > 30 )
goto V_257 ;
F_29 ( V_75 -> V_266 = V_254 ) ;
break ;
case V_267 :
if ( V_253 & ~ 1 )
goto V_257 ;
F_29 ( V_75 -> V_268 = V_253 ) ;
break ;
case V_269 :
if ( V_256 < ( long ) 0x478bf51L )
goto V_257 ;
F_29 ( V_75 -> V_270 = V_256 ) ;
break ;
#ifdef F_21
case V_108 :
if ( V_256 > 1562 )
goto V_257 ;
if ( V_14 && V_2 -> V_75 . V_271 != V_256 ) {
V_2 -> V_272 . V_273 = TRUE ;
V_2 -> V_75 . V_271 = V_256 ;
}
break ;
case V_109 :
if ( V_256 < 50 || V_256 > 5000 )
goto V_257 ;
if ( V_14 && V_2 -> V_75 . V_271 &&
V_2 -> V_75 . V_274 != V_256 ) {
V_2 -> V_272 . V_273 = TRUE ;
V_2 -> V_75 . V_274 = V_256 ;
}
break ;
case V_110 :
if ( V_256 > - F_30 ( 5 ) || V_256 < - F_30 ( 165 ) )
goto V_257 ;
F_29 ( V_75 -> V_275 = V_256 ) ;
break ;
case V_111 :
if ( V_256 < 1 || V_256 > 4478 )
goto V_257 ;
F_29 ( V_75 -> V_276 = V_256 ) ;
break ;
case V_112 :
if ( ( V_256 & 0xffff ) != 1 )
goto V_257 ;
F_29 ( V_75 -> V_277 = V_256 ) ;
break ;
case V_113 :
if ( V_254 > 1 )
goto V_257 ;
F_29 ( V_75 -> V_278 = V_254 ) ;
break ;
#endif
#ifdef F_22
case V_114 :
if ( V_253 != V_279 && V_253 != V_280 )
goto V_257 ;
F_29 ( V_75 -> V_281 = V_253 ) ;
break ;
case V_115 :
if ( V_253 > 100 )
goto V_257 ;
F_29 ( V_75 -> V_282 = V_253 ) ;
break ;
#endif
case V_283 :
if ( ( V_254 & ( V_284 |
V_285 ) ) == 0 )
goto V_257 ;
F_29 ( V_89 -> V_197 = V_254 ) ;
break ;
case V_286 :
F_29 ( V_89 -> V_287 = V_254 ) ;
break ;
case V_288 :
F_29 ( V_89 -> V_289 = V_254 ) ;
break ;
case V_290 :
if ( V_253 & ~ 1 )
goto V_257 ;
if ( V_14 ) {
V_89 -> V_291 = V_253 ;
F_31 ( V_2 , V_292 , V_293 ) ;
}
break ;
case V_116 :
F_29 ( V_89 -> V_294 = V_256 ) ;
break ;
case V_295 :
if ( V_256 > 1562 )
goto V_257 ;
F_29 ( V_252 -> V_296 = V_256 ) ;
#ifdef F_21
if ( V_14 )
F_32 ( V_2 ) ;
#endif
break ;
case V_297 :
if ( V_256 > 5000 )
goto V_257 ;
if ( V_256 != 0 && V_252 -> V_296 == 0 )
goto V_257 ;
F_29 ( V_252 -> V_298 = V_256 ) ;
#ifdef F_21
if ( V_14 )
F_32 ( V_2 ) ;
#endif
break ;
case V_299 :
if ( V_14 ) {
V_252 -> V_300 = V_256 ;
F_33 ( V_2 ) ;
}
break ;
case V_301 :
if ( V_256 > 0x00BEBC20L )
goto V_257 ;
#ifdef F_22
if ( V_14 && V_75 -> V_281 == V_279 )
goto V_257 ;
#endif
F_29 ( V_252 -> V_302 = V_256 ) ;
break ;
case V_303 :
F_29 ( V_252 -> V_304 = V_256 ) ;
goto V_305 ;
case V_306 :
F_29 ( V_252 -> V_307 = V_256 ) ;
goto V_305 ;
case V_308 :
F_29 ( V_252 -> V_309 = V_256 ) ;
V_305:
if ( V_14 && F_34 ( V_2 ) ) {
F_35 ( V_2 , V_310 ) ;
V_2 -> V_6 . V_311 = 1 ;
F_31 ( V_2 , V_312 , V_313 ) ;
}
break ;
case V_314 :
if ( V_253 > 1 )
goto V_257 ;
F_29 ( V_91 -> V_315 = V_253 ) ;
break ;
case V_316 :
F_29 ( memcpy ( ( char * ) V_91 -> V_240 ,
( char * ) & V_256 , 4 ) ) ;
break ;
case V_317 :
if ( V_254 > 4 )
goto V_257 ;
F_29 ( V_91 -> V_318 = V_254 ) ;
break ;
case V_319 :
if ( V_253 < 4 || V_253 > 15 )
goto V_257 ;
F_29 ( V_91 -> V_204 = V_253 ) ;
break ;
case V_320 :
if ( V_253 < 4 || V_253 > 15 )
goto V_257 ;
F_29 ( V_91 -> V_206 = V_253 ) ;
break ;
case V_321 :
if ( F_36 ( V_2 , V_322 , ( int ) V_254 , 0 ) )
goto V_257 ;
break ;
case V_323 :
if ( F_36 ( V_2 , V_324 , ( int ) V_254 ,
F_20 ( V_2 , V_100 ) ) )
goto V_257 ;
break ;
default :
break ;
}
return 0 ;
V_257:
return V_325 ;
V_245:
return V_52 ;
#if 0
no_author_error:
return SMT_RDF_AUTHOR;
#endif
}
static const struct V_20 * F_15 ( V_45 V_87 )
{
const struct V_20 * V_21 ;
for ( V_21 = V_326 ; V_21 -> V_68 && V_21 -> V_68 != V_87 ; V_21 ++ )
;
return V_21 -> V_68 ? V_21 : NULL ;
}
static int F_19 ( struct V_1 * V_2 )
{
#ifdef F_14
F_37 ( V_2 ) ;
return V_60 ;
#else
if ( V_2 -> V_61 . V_62 == V_63 )
return 1 ;
return V_60 ;
#endif
}
static int F_20 ( struct V_1 * V_2 , int V_82 )
{
#ifdef F_14
F_37 ( V_2 ) ;
return V_82 ;
#else
if ( V_2 -> V_61 . V_62 == V_63 )
return V_327 ;
return V_82 ;
#endif
}
void F_5 ( struct V_1 * V_2 , struct V_5 * V_6 , char * V_328 )
{
int V_22 ;
struct V_16 * V_17 ;
char * V_96 ;
int V_329 ;
int V_330 ;
#ifdef F_27
int V_331 ;
#endif
F_37 ( V_2 ) ;
#ifdef F_38
if ( V_2 -> V_332 . V_333 < 2 )
#else
if ( V_332 . V_333 < 2 )
#endif
return ;
#ifdef F_27
V_331 = V_6 -> V_37 + sizeof( struct V_5 ) ;
#endif
printf ( L_8 , V_328 ) ;
F_39 ( ( char * ) & V_6 -> V_29 , 6 ) ;
printf ( L_9 ) ;
F_39 ( ( char * ) & V_6 -> V_30 , 6 ) ;
printf ( L_10 ,
V_6 -> V_9 , V_6 -> V_31 , V_6 -> V_33 ) ;
printf ( L_11 , V_6 -> V_35 ) ;
F_39 ( ( char * ) & V_6 -> V_80 , 8 ) ;
printf ( L_12 , V_6 -> V_37 ) ;
V_22 = V_6 -> V_37 ;
V_17 = (struct V_16 * ) ( V_6 + 1 ) ;
while ( V_22 > 0 ) {
int V_92 ;
#ifdef F_40
printf ( L_13 , V_17 -> V_53 , V_17 -> V_50 ) ;
#else
printf ( L_14 , V_17 -> V_53 , V_17 -> V_50 ) ;
#endif
V_329 = V_17 -> V_50 ;
if ( ( V_329 < 0 ) || ( V_329 > ( int ) ( V_22 - V_51 ) ) ) {
V_329 = V_22 - V_51 ;
printf ( L_15 ) ;
break ;
}
#ifdef F_27
F_41 ( V_6 , V_331 , 0 ) ;
#endif
if ( V_329 < 24 ) {
F_39 ( ( char * ) ( V_17 + 1 ) , ( int ) V_329 ) ;
printf ( L_16 ) ;
}
else {
int V_334 = 0 ;
V_96 = ( char * ) ( V_17 + 1 ) ;
F_39 ( V_96 , 16 ) ;
printf ( L_16 ) ;
V_329 -= 16 ;
V_96 += 16 ;
while ( V_329 > 0 ) {
V_330 = ( V_329 > 16 ) ? 16 : V_329 ;
if ( V_329 > 64 ) {
if ( V_334 == 0 )
printf ( L_17 ) ;
V_334 = 1 ;
}
else {
printf ( L_18 ) ;
F_39 ( V_96 , V_330 ) ;
printf ( L_16 ) ;
}
V_329 -= V_330 ;
V_96 += 16 ;
}
}
#ifdef F_27
F_41 ( V_6 , V_331 , 1 ) ;
#endif
V_92 = ( V_17 -> V_50 + V_51 + 3 ) & ~ 3 ;
V_22 -= V_92 ;
V_17 = (struct V_16 * ) ( ( char * ) V_17 + V_92 ) ;
}
printf ( L_19 ) ;
}
void F_39 ( char * V_82 , int V_22 )
{
int V_329 = 0 ;
while ( V_22 -- ) {
V_329 ++ ;
#ifdef F_40
printf ( L_20 , * V_82 ++ & 0xff , V_22 ? ( ( V_329 & 7 ) ? L_21 : L_22 ) : L_23 ) ;
#else
printf ( L_24 , * V_82 ++ & 0xff , V_22 ? ( ( V_329 & 7 ) ? L_21 : L_22 ) : L_23 ) ;
#endif
}
}
