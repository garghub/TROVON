T_1
F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_4 type ;
struct V_7 V_8 ;
T_4 V_9 ;
T_4 V_10 ;
#if 0
guint16 start_time;
#endif
static const int V_11 [] = {
V_12 ,
V_13 ,
V_14 ,
V_15 ,
V_15 ,
V_15 ,
V_15 ,
V_16 ,
V_16 ,
V_17 ,
V_18
} ;
#define F_3 (sizeof sniffer_encap / sizeof sniffer_encap[0])
struct V_19 V_19 ;
T_5 V_20 ;
T_6 * V_21 ;
if ( ! F_4 ( V_1 -> V_22 , V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_23 )
return V_24 ;
return V_25 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) ) {
return V_25 ;
}
if ( ! F_4 ( V_1 -> V_22 , V_5 , 2 , V_2 , V_3 ) )
return V_24 ;
if ( ! F_4 ( V_1 -> V_22 , V_6 , 4 , V_2 , V_3 ) )
return V_24 ;
type = F_5 ( V_5 ) ;
if ( type != V_26 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_1 ) ;
return V_24 ;
}
if ( ! F_4 ( V_1 -> V_22 , & V_8 , sizeof V_8 , V_2 , V_3 ) )
return V_24 ;
if ( V_8 . V_28 >= F_3
|| V_11 [ V_8 . V_28 ] == V_15 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_2 ,
V_8 . V_28 ) ;
return V_24 ;
}
if ( V_8 . V_30 >= V_31 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_3 , V_8 . V_30 ) ;
return V_24 ;
}
if ( V_8 . V_32 != 1 ) {
V_1 -> V_33 = V_34 ;
} else {
V_1 -> V_33 = V_35 ;
}
V_1 -> V_36 = V_11 [ V_8 . V_28 ] ;
V_9 = F_5 ( & V_8 . V_9 ) ;
if ( F_7 ( V_1 , V_2 , V_3 , V_9 ,
V_8 . V_28 ) < 0 )
return V_24 ;
if ( ( V_8 . V_28 == V_37 ||
V_8 . V_28 == V_38 ) &&
V_1 -> V_36 == V_16 ) {
switch ( V_9 ) {
case 1 :
switch ( F_5 ( & V_8 . V_39 [ 0 ] ) ) {
case 1 :
case 2 :
V_1 -> V_36 = V_40 ;
break;
}
break;
case 3 :
V_1 -> V_36 = V_41 ;
break;
}
}
V_20 = F_8 ( V_1 -> V_22 ) ;
if ( V_1 -> V_42 != NULL ) {
if ( F_9 ( V_1 -> V_42 , V_20 , V_43 , V_2 ) == - 1 )
return V_24 ;
}
V_21 = ( T_6 * ) F_10 ( sizeof( T_6 ) ) ;
V_1 -> V_44 = ( void * ) V_21 ;
V_21 -> V_9 = V_9 ;
V_21 -> V_45 = F_5 ( & V_8 . V_45 ) ;
V_21 -> V_46 . V_47 = NULL ;
V_21 -> V_46 . V_48 = 0 ;
V_21 -> V_46 . V_49 = 0 ;
V_21 -> rand . V_47 = NULL ;
V_21 -> rand . V_48 = 0 ;
V_21 -> rand . V_49 = 0 ;
V_21 -> V_46 . V_50 = V_20 ;
V_21 -> V_46 . V_51 = V_20 ;
V_21 -> rand . V_50 = V_20 ;
V_21 -> rand . V_51 = V_20 ;
V_21 -> V_52 = NULL ;
V_21 -> V_53 = NULL ;
V_21 -> V_54 = NULL ;
V_1 -> V_55 = V_56 ;
V_1 -> V_57 = V_58 ;
V_1 -> V_59 = V_60 ;
V_1 -> V_61 = V_62 ;
V_1 -> V_63 = 0 ;
V_21 -> V_30 = V_64 [ V_8 . V_30 ] ;
V_21 -> V_28 = V_8 . V_28 ;
V_10 = F_5 ( & V_8 . V_65 ) ;
V_19 . V_66 = ( ( V_10 & V_67 ) >> V_68 ) + V_69 ;
V_19 . V_70 = ( ( V_10 & V_71 ) >> V_72 ) + V_73 ;
V_19 . V_74 = ( ( V_10 & V_75 ) >> V_76 ) ;
#if 0
start_time = pletoh16(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
V_19 . V_77 = 0 ;
V_19 . V_78 = 0 ;
V_19 . V_79 = 0 ;
V_19 . V_80 = - 1 ;
V_21 -> V_81 = mktime ( & V_19 ) ;
V_1 -> V_82 = V_83 ;
return V_84 ;
}
static int
F_7 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_7 V_9 ,
T_8 V_28 )
{
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_4 type , V_85 ;
int V_86 ;
unsigned char V_87 [ 256 ] ;
for (; ; ) {
if ( ! F_11 ( V_1 -> V_22 , V_5 , 2 , V_2 , V_3 ) ) {
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
type = F_5 ( V_5 ) ;
if ( ( type != V_88 ) && ( type != V_89 )
&& ( type != V_90 ) && ( type != V_91 )
&& ( type != V_92 ) && ( type != V_93 )
&& ( type != V_94 )
&& ( ( type != V_95 ) || ( V_9 > 2 ) ) ) {
if ( F_9 ( V_1 -> V_22 , - 2 , V_96 , V_2 ) == - 1 )
return - 1 ;
return 0 ;
}
if ( ! F_4 ( V_1 -> V_22 , V_6 , 4 ,
V_2 , V_3 ) )
return - 1 ;
V_85 = F_5 ( V_6 ) ;
if ( ( V_28 == V_37 || V_28 == V_38 ) &&
type == V_89 ) {
V_86 = F_12 ( V_85 , ( int ) sizeof V_87 ) ;
if ( ! F_4 ( V_1 -> V_22 , V_87 ,
V_86 , V_2 , V_3 ) )
return - 1 ;
switch ( V_9 ) {
case 2 :
if ( F_13 ( V_1 , V_87 ,
V_85 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
case 1 :
case 4 :
case 5 :
if ( F_14 ( V_1 , V_87 ,
V_85 , V_9 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
}
if ( V_85 > sizeof V_87 ) {
if ( F_9 ( V_1 -> V_22 , V_85 - sizeof V_87 ,
V_96 , V_2 ) == - 1 )
return - 1 ;
}
} else {
if ( F_9 ( V_1 -> V_22 , V_85 , V_96 , V_2 ) == - 1 )
return - 1 ;
}
}
}
static int
F_13 ( T_2 * V_1 , unsigned char * V_87 , T_4 V_85 ,
int * V_2 , T_3 * * V_3 )
{
static const char V_97 [] = L_4 ;
if ( V_85 < sizeof V_97 - 1 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_5 ) ;
return - 1 ;
}
if ( strncmp ( ( char * ) V_87 , V_97 , sizeof V_97 - 1 ) == 0 ) {
V_1 -> V_36 = V_98 ;
} else {
* V_2 = V_29 ;
* V_3 = F_6 ( L_6 ,
V_85 , V_87 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_14 ( T_2 * V_1 , unsigned char * V_87 , T_4 V_85 ,
T_7 V_9 , int * V_2 , T_3 * * V_3 )
{
if ( V_85 < 5 ) {
* V_2 = V_29 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
switch ( V_87 [ 4 ] ) {
case V_99 :
V_1 -> V_36 = V_100 ;
break;
case V_101 :
V_1 -> V_36 = V_16 ;
break;
case V_102 :
V_1 -> V_36 = V_41 ;
break;
case V_103 :
V_1 -> V_36 = V_16 ;
switch ( V_9 ) {
case 4 :
if ( V_87 [ 1 ] == 0xfa )
V_1 -> V_36 = V_40 ;
break;
case 5 :
if ( V_85 < 7 ) {
* V_2 = V_29 ;
* V_3 = F_15 ( L_8 ) ;
return - 1 ;
}
if ( V_87 [ 6 ] == 0x01 )
V_1 -> V_36 = V_40 ;
break;
}
break;
case V_104 :
V_1 -> V_36 = V_105 ;
break;
default:
* V_2 = V_29 ;
* V_3 = F_6 ( L_9 ,
V_87 [ 4 ] ) ;
return - 1 ;
}
return 0 ;
}
static T_9
V_56 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_5 * V_106 )
{
T_6 * V_21 ;
int V_107 ;
T_10 V_108 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
for (; ; ) {
* V_106 = V_21 -> V_46 . V_50 ;
V_107 = F_16 ( V_1 , FALSE , & V_108 ,
& V_1 -> V_109 , V_1 -> V_110 , V_2 , V_3 ) ;
if ( V_107 < 0 ) {
return FALSE ;
}
switch ( V_107 ) {
case V_111 :
case V_112 :
case V_113 :
if ( V_108 != 0 ) {
if ( ! F_17 ( V_1 , V_108 , V_2 ,
V_3 ) )
return FALSE ;
}
return TRUE ;
case V_114 :
* V_2 = 0 ;
return FALSE ;
default:
if ( V_108 != 0 ) {
if ( ! F_17 ( V_1 , V_108 , V_2 ,
V_3 ) )
return FALSE ;
}
break;
}
}
}
static T_9
V_58 ( T_2 * V_1 , T_5 V_115 ,
struct V_116 * V_109 , T_11 * V_47 , int * V_2 , T_3 * * V_3 )
{
int V_107 ;
if ( ! F_18 ( V_1 , V_115 , V_2 , V_3 ) )
return FALSE ;
V_107 = F_16 ( V_1 , TRUE , NULL , V_109 , V_47 , V_2 , V_3 ) ;
if ( V_107 < 0 ) {
return FALSE ;
}
switch ( V_107 ) {
case V_111 :
case V_112 :
case V_113 :
break;
default:
F_19 () ;
return FALSE ;
}
return TRUE ;
}
static int
F_16 ( T_2 * V_1 , T_9 V_117 , T_10 * V_108 ,
struct V_116 * V_109 , T_11 * V_47 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_4 type , V_85 ;
struct V_118 V_119 ;
struct V_120 V_121 ;
struct V_122 V_123 ;
T_4 V_124 , V_125 , V_126 , V_127 ;
T_8 V_128 , V_129 ;
T_12 V_130 , V_131 , V_132 ;
if ( ! F_20 ( V_1 , V_5 , 2 , V_117 , V_2 , V_3 ) ) {
if ( * V_2 != 0 )
return - 1 ;
return V_114 ;
}
if ( ! F_21 ( V_1 , V_6 , 4 , V_117 , V_2 , V_3 ) )
return - 1 ;
type = F_5 ( V_5 ) ;
V_85 = F_5 ( V_6 ) ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
switch ( type ) {
case V_111 :
if ( V_21 -> V_28 == V_133 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_10 ) ;
return - 1 ;
}
if ( ! F_21 ( V_1 , & V_119 , ( unsigned int ) sizeof V_119 ,
V_117 , V_2 , V_3 ) )
return - 1 ;
V_124 = F_5 ( & V_119 . V_124 ) ;
V_125 = F_5 ( & V_119 . V_125 ) ;
V_128 = V_119 . V_128 ;
V_129 = V_119 . V_129 ;
V_127 = F_5 ( & V_119 . V_127 ) ;
V_126 = F_5 ( & V_119 . V_126 ) ;
V_85 -= sizeof V_119 ;
F_22 ( V_1 , & V_109 -> V_134 , & V_119 ) ;
break;
case V_112 :
if ( V_21 -> V_28 != V_133 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_11 ) ;
return - 1 ;
}
if ( ! F_21 ( V_1 , & V_121 , ( unsigned int ) sizeof V_121 ,
V_117 , V_2 , V_3 ) )
return - 1 ;
V_124 = F_5 ( & V_121 . V_124 ) ;
V_125 = F_5 ( & V_121 . V_125 ) ;
V_128 = V_121 . V_128 ;
V_129 = V_121 . V_129 ;
V_127 = F_5 ( & V_121 . V_127 ) ;
V_126 = F_5 ( & V_121 . V_126 ) ;
if ( V_21 -> V_9 >= 5 )
V_85 -= sizeof V_121 ;
else {
if ( V_21 -> V_45 >= 95 )
V_85 -= sizeof V_119 ;
else
V_85 -= sizeof V_121 ;
}
F_23 ( & V_109 -> V_134 , & V_121 ) ;
break;
case V_113 :
if ( ! F_21 ( V_1 , & V_123 , ( unsigned int ) sizeof V_123 ,
V_117 , V_2 , V_3 ) )
return - 1 ;
V_124 = F_5 ( & V_123 . V_124 ) ;
V_125 = F_5 ( & V_123 . V_125 ) ;
V_128 = V_123 . V_128 ;
V_129 = V_123 . V_129 ;
V_127 = F_5 ( & V_123 . V_127 ) ;
V_126 = F_5 ( & V_123 . V_126 ) ;
V_85 -= sizeof V_123 ;
F_24 ( V_1 , & V_109 -> V_134 , & V_123 ) ;
break;
case V_114 :
* V_2 = 0 ;
return V_114 ;
default:
if ( V_108 != NULL ) {
* V_108 = V_85 ;
}
return type ;
}
if ( V_127 > V_85 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_12 ) ;
return - 1 ;
}
if ( V_108 != NULL ) {
* V_108 = V_85 - V_127 ;
}
V_109 -> V_135 = V_136 ;
V_109 -> V_137 = V_126 ? V_138 | V_139 : V_138 ;
V_109 -> V_140 = V_126 ? V_126 : V_127 ;
V_109 -> V_141 = V_127 ;
F_25 ( V_47 , V_127 ) ;
if ( ! F_21 ( V_1 , F_26 ( V_47 ) , V_127 , V_117 ,
V_2 , V_3 ) )
return - 1 ;
V_109 -> V_142 = F_27 ( V_1 -> V_36 ,
V_47 , V_85 , & V_109 -> V_134 ) ;
V_130 = ( ( ( T_12 ) V_128 ) << 32 ) | ( ( ( T_12 ) V_125 ) << 16 ) | V_124 ;
V_130 *= V_21 -> V_30 ;
V_131 = V_130 / F_28 ( 1000000000000 ) ;
V_132 = V_130 - V_131 * F_28 ( 1000000000000 ) ;
V_131 += V_129 * 86400 ;
V_131 += V_21 -> V_81 ;
V_109 -> V_143 . V_144 = ( V_145 ) V_131 ;
V_109 -> V_143 . V_146 = ( int ) ( V_132 / 1000 ) ;
return type ;
}
static void
F_22 ( T_2 * V_1 , union V_147 * V_134 ,
struct V_118 * V_119 )
{
switch ( V_1 -> V_36 ) {
case V_13 :
V_134 -> V_148 . V_149 = 0 ;
break;
case V_105 :
case V_100 :
V_134 -> V_150 . V_151 = ( V_119 -> V_152 & V_153 ) ? TRUE : FALSE ;
break;
case V_98 :
case V_41 :
case V_16 :
V_134 -> V_154 . V_155 = ( V_119 -> V_152 & V_153 ) ? 0x00 : V_156 ;
break;
case V_40 :
V_134 -> V_157 . V_158 = ( V_119 -> V_152 & V_153 ) ? FALSE : TRUE ;
switch ( V_119 -> V_152 & V_159 ) {
case V_160 :
V_134 -> V_157 . V_161 = 0 ;
break;
case V_162 :
V_134 -> V_157 . V_161 = 1 ;
break;
case V_163 :
V_134 -> V_157 . V_161 = 2 ;
break;
default:
V_134 -> V_157 . V_161 = 30 ;
break;
}
}
}
static void
F_23 ( union V_147 * V_134 ,
struct V_120 * V_121 )
{
T_13 V_164 ;
T_8 V_165 , V_166 ;
T_4 V_167 , V_168 ;
V_134 -> V_169 . V_155 = 0 ;
V_164 = F_29 ( & V_121 -> V_170 . V_164 ) ;
if ( V_164 & V_171 )
V_134 -> V_169 . V_155 |= V_172 ;
V_165 = V_121 -> V_170 . V_173 & V_174 ;
V_166 = V_121 -> V_170 . V_173 & V_175 ;
V_167 = F_5 ( & V_121 -> V_170 . V_176 ) ;
V_168 = F_5 ( & V_121 -> V_170 . V_177 ) ;
switch ( V_165 ) {
case V_178 :
if ( V_167 == 0 && V_168 == 5 )
V_134 -> V_169 . V_179 = V_180 ;
else
V_134 -> V_169 . V_179 = V_181 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_185 :
V_134 -> V_169 . V_179 = V_186 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_187 :
V_134 -> V_169 . V_179 = V_188 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_189 :
V_134 -> V_169 . V_179 = V_190 ;
switch ( V_166 ) {
case V_191 :
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_192 :
V_134 -> V_169 . type = V_193 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_194 :
V_134 -> V_169 . type = V_195 ;
switch ( V_121 -> V_170 . V_196 ) {
case V_197 :
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_198 :
V_134 -> V_169 . V_183 =
V_199 ;
break;
case V_200 :
V_134 -> V_169 . V_183 =
V_201 ;
break;
case V_202 :
V_134 -> V_169 . V_183 =
V_203 ;
break;
case V_204 :
V_134 -> V_169 . V_183 =
V_205 ;
break;
case V_206 :
V_134 -> V_169 . V_183 =
V_207 ;
break;
case V_208 :
V_134 -> V_169 . V_183 = V_209 ;
break;
case V_210 :
V_134 -> V_169 . V_183 = V_211 ;
break;
case V_212 :
V_134 -> V_169 . V_183 = V_213 ;
break;
case V_214 :
V_134 -> V_169 . V_183 = V_215 ;
break;
case V_216 :
V_134 -> V_169 . V_183 = V_217 ;
break;
case V_218 :
V_134 -> V_169 . V_183 =
V_219 ;
break;
case V_220 :
V_134 -> V_169 . V_183 = V_221 ;
break;
default:
V_134 -> V_169 . V_183 = V_184 ;
break;
}
break;
case V_222 :
V_134 -> V_169 . type = V_223 ;
switch ( V_121 -> V_170 . V_196 ) {
case V_197 :
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_224 :
V_134 -> V_169 . V_183 =
V_225 ;
break;
case V_226 :
V_134 -> V_169 . V_183 = V_227 ;
break;
case V_228 :
V_134 -> V_169 . V_183 = V_229 ;
break;
case V_230 :
V_134 -> V_169 . V_183 =
V_231 ;
break;
case V_232 :
V_134 -> V_169 . V_183 =
V_233 ;
break;
default:
V_134 -> V_169 . V_183 = V_184 ;
break;
}
break;
case V_234 :
V_134 -> V_169 . type = V_235 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_236 :
V_134 -> V_169 . type = V_237 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_238 :
V_134 -> V_169 . type = V_239 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_240 :
V_134 -> V_169 . type = V_241 ;
switch ( V_121 -> V_170 . V_196 ) {
case V_197 :
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_242 :
V_134 -> V_169 . V_183 =
V_243 ;
break;
case V_244 :
V_134 -> V_169 . V_183 =
V_245 ;
break;
case V_246 :
V_134 -> V_169 . V_183 =
V_247 ;
break;
default:
V_134 -> V_169 . V_183 = V_184 ;
break;
}
break;
default:
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
}
break;
case V_248 :
V_134 -> V_169 . V_179 = V_249 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_250 :
V_134 -> V_169 . V_179 = V_180 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
case V_251 :
V_134 -> V_169 . V_179 = V_252 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
default:
V_134 -> V_169 . V_179 = V_181 ;
V_134 -> V_169 . type = V_182 ;
V_134 -> V_169 . V_183 = V_184 ;
break;
}
V_134 -> V_169 . V_167 = V_167 ;
V_134 -> V_169 . V_168 = V_168 ;
V_134 -> V_169 . V_161 = F_5 ( & V_121 -> V_170 . V_161 ) ;
V_134 -> V_169 . V_253 = F_5 ( & V_121 -> V_170 . V_253 ) ;
V_134 -> V_169 . V_254 = F_5 ( & V_121 -> V_170 . V_255 . V_254 ) ;
V_134 -> V_169 . V_256 = F_5 ( & V_121 -> V_170 . V_255 . V_256 ) ;
V_134 -> V_169 . V_257 = F_30 ( & V_121 -> V_170 . V_255 . V_257 ) ;
}
static void
F_24 ( T_2 * V_1 , union V_147 * V_134 ,
struct V_122 * V_123 V_258 )
{
switch ( V_1 -> V_36 ) {
case V_13 :
V_134 -> V_148 . V_149 = - 1 ;
break;
}
}
static int
F_31 ( const T_8 * V_259 , int V_140 )
{
int V_260 ;
if ( V_140 <= 0 ) {
return V_105 ;
}
if ( V_259 [ 0 ] == 0xFF ) {
return V_105 ;
}
if ( V_140 >= 2 ) {
if ( V_259 [ 0 ] == 0x07 && V_259 [ 1 ] == 0x03 ) {
return V_261 ;
} else if ( ( V_259 [ 0 ] == 0x0F && V_259 [ 1 ] == 0x00 ) ||
( V_259 [ 0 ] == 0x8F && V_259 [ 1 ] == 0x00 ) ) {
return V_262 ;
}
for ( V_260 = 0 ; V_260 < V_140 && ( V_259 [ V_260 ] & 0x01 ) == 0 ; V_260 ++ )
;
V_260 ++ ;
if ( V_260 == V_140 ) {
return V_98 ;
}
if ( V_259 [ V_260 ] == 0x03 )
return V_41 ;
}
return V_98 ;
}
static int
F_27 ( int V_263 , T_11 * V_47 , int V_140 ,
union V_147 * V_134 )
{
const T_8 * V_259 ;
V_259 = F_26 ( V_47 ) ;
switch ( V_263 ) {
case V_16 :
V_263 = F_31 ( V_259 , V_140 ) ;
switch ( V_263 ) {
case V_261 :
case V_262 :
case V_105 :
if ( V_134 -> V_154 . V_155 == 0 )
V_134 -> V_150 . V_151 = TRUE ;
else
V_134 -> V_150 . V_151 = FALSE ;
break;
case V_40 :
if ( V_134 -> V_154 . V_155 == 0x00 )
V_134 -> V_157 . V_158 = FALSE ;
else
V_134 -> V_157 . V_158 = TRUE ;
V_134 -> V_157 . V_161 = 0 ;
break;
}
break;
case V_18 :
if ( V_134 -> V_169 . type == V_223 && V_140 >= 2 ) {
if ( V_259 [ 0 ] == 0xff && V_259 [ 1 ] == 0x00 ) {
V_134 -> V_169 . V_183 =
V_225 ;
} else {
if ( V_134 -> V_169 . V_183 ==
V_225 ) {
V_134 -> V_169 . V_183 =
V_227 ;
}
}
}
break;
}
return V_263 ;
}
static void
V_60 ( T_2 * V_1 )
{
T_6 * V_21 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_21 -> V_46 . V_47 != NULL ) {
F_32 ( V_21 -> V_46 . V_47 ) ;
V_21 -> V_46 . V_47 = NULL ;
}
}
static void
F_33 ( T_14 V_264 , T_14 T_15 V_258 )
{
F_32 ( V_264 ) ;
}
static void
V_62 ( T_2 * V_1 )
{
T_6 * V_21 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_21 -> rand . V_47 != NULL )
F_32 ( V_21 -> rand . V_47 ) ;
if ( V_21 -> V_52 != NULL ) {
F_34 ( V_21 -> V_52 , F_33 , NULL ) ;
F_35 ( V_21 -> V_52 ) ;
}
}
int
F_36 ( int V_263 )
{
if ( V_263 == V_16 )
return V_265 ;
if ( V_263 < 0 || ( unsigned ) V_263 >= V_266 || V_267 [ V_263 ] == - 1 )
return V_268 ;
return 0 ;
}
T_9
F_37 ( T_16 * V_269 , int * V_2 )
{
T_17 * V_21 ;
char V_47 [ 6 ] = { V_26 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 } ;
V_269 -> V_270 = V_271 ;
V_269 -> V_272 = V_273 ;
V_21 = ( T_17 * ) F_10 ( sizeof( T_17 ) ) ;
V_269 -> V_44 = ( void * ) V_21 ;
V_21 -> V_274 = TRUE ;
V_21 -> V_81 = 0 ;
if ( ! F_38 ( V_269 , F_2 , sizeof F_2 ,
V_2 ) )
return FALSE ;
if ( ! F_38 ( V_269 , V_47 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_9
V_271 ( T_16 * V_269 , const struct V_116 * V_109 ,
const T_8 * V_259 , int * V_2 , T_3 * * V_3 V_258 )
{
const union V_147 * V_134 = & V_109 -> V_134 ;
T_17 * V_21 = ( T_17 * ) V_269 -> V_44 ;
struct V_118 V_275 ;
char V_47 [ 6 ] ;
V_145 V_131 ;
T_12 V_130 ;
T_4 V_276 , V_277 ;
T_8 V_278 ;
struct V_7 V_8 ;
T_7 V_9 , V_45 ;
T_4 V_10 ;
struct V_19 * V_19 ;
if ( V_109 -> V_135 != V_136 ) {
* V_2 = V_279 ;
return FALSE ;
}
if ( V_109 -> V_141 > 65535 ) {
* V_2 = V_280 ;
return FALSE ;
}
if ( V_21 -> V_274 ) {
V_21 -> V_274 = FALSE ;
V_19 = localtime ( & V_109 -> V_143 . V_144 ) ;
if ( V_19 != NULL && V_19 -> V_66 >= V_69 ) {
V_10 = ( V_19 -> V_66 - V_69 ) << V_68 ;
V_10 |= ( V_19 -> V_70 - V_73 ) << V_72 ;
V_10 |= V_19 -> V_74 << V_76 ;
V_21 -> V_81 = V_109 -> V_143 . V_144 - ( 3600 * V_19 -> V_77 + 60 * V_19 -> V_78 + V_19 -> V_79 ) ;
} else {
V_10 = 0 ;
V_21 -> V_81 = 0 ;
}
V_9 = 4 ;
V_45 = 0 ;
V_8 . V_9 = F_39 ( V_9 ) ;
V_8 . V_45 = F_39 ( V_45 ) ;
V_8 . time = 0 ;
V_8 . V_65 = F_39 ( V_10 ) ;
V_8 . type = 4 ;
V_8 . V_28 = V_267 [ V_269 -> V_263 ] ;
V_8 . V_32 = 1 ;
V_8 . V_30 = 1 ;
V_8 . V_281 = 0 ;
V_8 . V_282 = 0 ;
V_8 . V_39 [ 0 ] = 0 ;
V_8 . V_39 [ 1 ] = 0 ;
if ( ! F_38 ( V_269 , & V_8 , sizeof V_8 , V_2 ) )
return FALSE ;
}
V_47 [ 0 ] = V_111 ;
V_47 [ 1 ] = 0x00 ;
V_47 [ 2 ] = ( char ) ( ( V_109 -> V_141 + sizeof( struct V_118 ) ) % 256 ) ;
V_47 [ 3 ] = ( char ) ( ( V_109 -> V_141 + sizeof( struct V_118 ) ) / 256 ) ;
V_47 [ 4 ] = 0x00 ;
V_47 [ 5 ] = 0x00 ;
if ( ! F_38 ( V_269 , V_47 , 6 , V_2 ) )
return FALSE ;
V_131 = V_109 -> V_143 . V_144 - V_21 -> V_81 ;
V_275 . V_129 = ( T_8 ) ( V_131 / 86400 ) ;
V_131 -= V_275 . V_129 * 86400 ;
V_130 = V_131 * F_28 ( 1000000000000 ) +
V_109 -> V_143 . V_146 * F_28 ( 1000 ) ;
V_130 /= V_64 [ 1 ] ;
V_276 = ( T_4 ) ( ( V_130 >> 0 ) & 0xFFFF ) ;
V_277 = ( T_4 ) ( ( V_130 >> 16 ) & 0xFFFF ) ;
V_278 = ( T_8 ) ( ( V_130 >> 32 ) & 0xFF ) ;
V_275 . V_124 = F_39 ( V_276 ) ;
V_275 . V_125 = F_39 ( V_277 ) ;
V_275 . V_128 = V_278 ;
V_275 . V_127 = F_39 ( V_109 -> V_141 ) ;
switch ( V_269 -> V_263 ) {
case V_98 :
case V_41 :
V_275 . V_152 = ( V_134 -> V_154 . V_155 & V_156 ) ? 0x00 : V_153 ;
break;
case V_105 :
case V_100 :
V_275 . V_152 = V_134 -> V_150 . V_151 ? 0x00 : V_153 ;
break;
case V_40 :
V_275 . V_152 = V_134 -> V_157 . V_158 ? V_153 : 0x00 ;
switch ( V_134 -> V_157 . V_161 ) {
case 0 :
V_275 . V_152 |= V_160 ;
break;
case 1 :
V_275 . V_152 |= V_162 ;
break;
case 2 :
V_275 . V_152 |= V_163 ;
break;
}
break;
default:
V_275 . V_152 = 0 ;
break;
}
V_275 . V_155 = 0 ;
V_275 . V_126 = V_109 -> V_140 != V_109 -> V_141 ? F_39 ( V_109 -> V_140 ) : 0 ;
V_275 . V_39 = 0 ;
if ( ! F_38 ( V_269 , & V_275 , sizeof V_275 , V_2 ) )
return FALSE ;
if ( ! F_38 ( V_269 , V_259 , V_109 -> V_141 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_9
V_273 ( T_16 * V_269 , int * V_2 )
{
char V_47 [ 6 ] = { V_114 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( ! F_38 ( V_269 , V_47 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_40 ( unsigned char * V_283 , T_18 V_284 , unsigned char * V_285 ,
T_18 V_286 , int * V_2 , T_3 * * V_3 )
{
unsigned char * V_287 = V_283 ;
unsigned char * V_288 = V_285 ;
unsigned char * V_289 = V_287 + V_284 ;
unsigned char * V_290 = V_288 + V_286 ;
unsigned int V_291 ;
unsigned int V_292 = 0 ;
unsigned int V_293 ;
unsigned int V_294 ;
int V_85 ;
int V_295 ;
if ( V_284 > V_296 ) {
return ( - 1 ) ;
}
V_291 = 0 ;
while ( V_287 < V_289 )
{
V_291 = V_291 >> 1 ;
if ( 0 == V_291 )
{
F_41 ( 3 ) ;
V_291 = 0x8000 ;
V_292 = F_5 ( V_287 ) ;
V_287 += 2 ;
}
if ( ! ( V_291 & V_292 ) )
{
F_42 ( 1 ) ;
* ( V_288 ++ ) = * ( V_287 ++ ) ;
}
else
{
V_293 = ( unsigned int ) ( ( * V_287 ) >> 4 ) & 0xF ;
V_294 = ( unsigned int ) ( ( * V_287 ) & 0xF ) ;
V_287 ++ ;
switch ( V_293 )
{
case 0 :
V_85 = V_294 + 3 ;
F_43 ( V_85 ) ;
break;
case 1 :
F_41 ( 1 ) ;
V_85 = V_294 + ( ( unsigned int ) ( * V_287 ++ ) << 4 ) + 19 ;
F_43 ( V_85 ) ;
break;
case 2 :
V_297 ;
F_41 ( 1 ) ;
V_85 = ( unsigned int ) ( * V_287 ++ ) + 16 ;
F_44 ( V_295 , V_85 ) ;
break;
default :
V_297 ;
V_85 = V_293 ;
F_44 ( V_295 , V_85 ) ;
break;
}
}
}
return ( int ) ( V_288 - V_285 ) ;
}
static T_9
F_20 ( T_2 * V_1 , void * V_87 , unsigned int V_48 , T_9 V_117 ,
int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
T_19 V_298 ;
T_20 * V_299 ;
T_5 V_300 = 0 ;
unsigned char * V_301 = ( unsigned char * ) V_87 ;
T_21 * V_302 ;
unsigned int V_303 ;
unsigned int V_304 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_117 ) {
V_298 = V_1 -> V_42 ;
V_299 = & V_21 -> rand ;
} else {
V_298 = V_1 -> V_22 ;
V_299 = & V_21 -> V_46 ;
}
if ( V_1 -> V_33 == V_35 ) {
if ( ! F_11 ( V_298 , V_87 , V_48 , V_2 , V_3 ) )
return FALSE ;
V_299 -> V_50 += V_48 ;
V_299 -> V_51 += V_48 ;
return TRUE ;
}
if ( V_299 -> V_47 == NULL ) {
V_299 -> V_47 = ( unsigned char * ) F_10 ( V_305 ) ;
if ( V_117 ) {
V_21 -> V_54 = V_21 -> V_52 ;
} else {
if ( V_1 -> V_42 != NULL ) {
F_45 ( V_21 -> V_52 == NULL ) ;
V_302 = F_46 ( T_21 , 1 ) ;
V_302 -> V_306 = V_299 -> V_51 ;
V_302 -> V_307 = V_299 -> V_50 ;
V_21 -> V_52 = F_47 ( V_21 -> V_52 ,
V_302 ) ;
V_21 -> V_53 = V_21 -> V_52 ;
}
}
if ( ! F_48 ( V_298 , V_299 , V_2 , V_3 ) )
return FALSE ;
}
while ( V_48 > 0 ) {
V_304 = V_299 -> V_48 - V_299 -> V_49 ;
if ( V_304 == 0 ) {
if ( V_117 ) {
V_21 -> V_54 = F_49 ( V_21 -> V_54 ) ;
if ( ! V_21 -> V_54 ) {
* V_2 = V_308 ;
return FALSE ;
}
} else {
if ( V_1 -> V_42 != NULL ) {
V_302 = F_46 ( T_21 , 1 ) ;
V_302 -> V_306 = V_299 -> V_51 ;
V_302 -> V_307 = V_299 -> V_50 ;
V_21 -> V_53 = F_47 ( V_21 -> V_53 ,
V_302 ) ;
}
}
if ( ! F_48 ( V_298 , V_299 , V_2 , V_3 ) )
return FALSE ;
V_304 = V_299 -> V_48 - V_299 -> V_49 ;
}
V_303 = V_48 ;
if ( V_303 > V_304 )
V_303 = V_304 ;
memcpy ( V_301 , & V_299 -> V_47 [ V_299 -> V_49 ] ,
V_303 ) ;
V_48 -= V_303 ;
V_300 += V_303 ;
V_301 += V_303 ;
V_299 -> V_49 += V_303 ;
V_299 -> V_50 += V_303 ;
}
return TRUE ;
}
static T_9
F_21 ( T_2 * V_1 , void * V_87 , unsigned int V_48 , T_9 V_117 ,
int * V_2 , T_3 * * V_3 )
{
if ( ! F_20 ( V_1 , V_87 , V_48 , V_117 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_23 ;
return FALSE ;
}
return TRUE ;
}
static T_9
F_48 ( T_19 V_298 , T_20 * V_299 , int * V_2 ,
T_3 * * V_3 )
{
int V_309 ;
unsigned short V_310 ;
T_7 V_311 ;
T_9 V_312 ;
unsigned char * V_313 ;
int V_314 ;
if ( ! F_11 ( V_298 , & V_310 , 2 , V_2 , V_3 ) )
return FALSE ;
V_299 -> V_51 += 2 ;
V_311 = F_5 ( & V_310 ) ;
if ( V_311 < 0 ) {
V_309 = - V_311 ;
V_312 = TRUE ;
} else {
V_309 = V_311 ;
V_312 = FALSE ;
}
V_313 = ( unsigned char * ) F_10 ( V_315 ) ;
if ( ! F_4 ( V_298 , V_313 , V_309 , V_2 , V_3 ) ) {
F_32 ( V_313 ) ;
return FALSE ;
}
V_299 -> V_51 += V_309 ;
if ( V_312 ) {
memcpy ( V_299 -> V_47 , V_313 , V_309 ) ;
V_314 = V_309 ;
} else {
V_314 = F_40 ( V_313 , V_309 ,
V_299 -> V_47 , V_305 , V_2 ,
V_3 ) ;
if ( V_314 < 0 ) {
F_32 ( V_313 ) ;
return FALSE ;
}
}
F_32 ( V_313 ) ;
V_299 -> V_49 = 0 ;
V_299 -> V_48 = V_314 ;
return TRUE ;
}
static T_9
F_17 ( T_2 * V_1 , T_5 V_316 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
char * V_47 ;
unsigned int V_317 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_1 -> V_33 == V_35 ) {
V_21 -> V_46 . V_50 += V_316 ;
return F_50 ( V_1 -> V_22 , V_316 , V_2 ) ;
}
F_45 ( V_316 >= 0 ) ;
V_47 = ( char * ) F_10 ( V_315 ) ;
while ( V_316 != 0 ) {
if ( V_316 > V_315 )
V_317 = V_315 ;
else
V_317 = ( unsigned int ) V_316 ;
if ( ! F_21 ( V_1 , V_47 , V_317 , FALSE , V_2 , V_3 ) ) {
F_32 ( V_47 ) ;
return FALSE ;
}
V_316 -= V_317 ;
}
F_32 ( V_47 ) ;
return TRUE ;
}
static T_9
F_18 ( T_2 * V_1 , T_5 V_295 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
T_5 V_316 ;
T_22 * V_318 , * V_319 ;
T_21 * V_320 , * V_321 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_1 -> V_33 == V_35 ) {
if ( F_9 ( V_1 -> V_42 , V_295 , V_43 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
V_316 = V_295 - V_21 -> rand . V_50 ;
V_318 = NULL ;
if ( V_316 > 0 ) {
if ( ( T_18 ) ( V_21 -> rand . V_49 + V_316 ) >= V_21 -> rand . V_48 ) {
if ( V_21 -> V_54 == NULL ) {
V_318 = V_21 -> V_52 ;
} else {
V_318 = F_49 ( V_21 -> V_54 ) ;
}
while ( V_318 ) {
V_319 = F_49 ( V_318 ) ;
if ( V_319 == NULL ) {
break;
}
V_320 = ( T_21 * ) V_319 -> V_264 ;
if ( V_320 -> V_307 > V_295 )
break;
V_318 = V_319 ;
}
if ( V_318 == NULL ) {
* V_2 = V_308 ;
return FALSE ;
}
}
} else if ( V_316 < 0 ) {
if ( V_21 -> rand . V_49 + V_316 < 0 ) {
if ( V_21 -> V_54 == NULL ) {
V_318 = V_21 -> V_53 ;
} else {
V_318 = F_51 ( V_21 -> V_54 ) ;
}
while ( V_318 ) {
V_321 = ( T_21 * ) V_318 -> V_264 ;
if ( V_321 -> V_307 <= V_295 )
break;
V_318 = F_51 ( V_318 ) ;
}
if ( V_318 == NULL ) {
* V_2 = V_308 ;
return FALSE ;
}
}
}
if ( V_318 != NULL ) {
V_321 = ( T_21 * ) V_318 -> V_264 ;
if ( F_9 ( V_1 -> V_42 , V_321 -> V_306 , V_43 , V_2 ) == - 1 )
return FALSE ;
if ( V_21 -> rand . V_47 == NULL ) {
V_21 -> rand . V_47 = ( unsigned char * ) F_10 ( V_305 ) ;
}
V_21 -> V_54 = V_318 ;
V_21 -> rand . V_50 = V_321 -> V_307 ;
V_21 -> rand . V_51 = V_321 -> V_306 ;
if ( ! F_48 ( V_1 -> V_42 , & V_21 -> rand , V_2 , V_3 ) )
return FALSE ;
V_316 = V_295 - V_21 -> rand . V_50 ;
F_45 ( V_316 >= 0 && ( unsigned long ) V_316 < V_21 -> rand . V_48 ) ;
}
V_21 -> rand . V_49 += ( int ) V_316 ;
V_21 -> rand . V_50 += V_316 ;
return TRUE ;
}
