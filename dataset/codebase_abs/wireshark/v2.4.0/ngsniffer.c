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
* V_3 = F_7 ( L_2 ,
V_8 . V_28 ) ;
return V_24 ;
}
if ( V_8 . V_30 >= V_31 ) {
* V_2 = V_29 ;
* V_3 = F_7 ( L_3 , V_8 . V_30 ) ;
return V_24 ;
}
if ( V_8 . V_32 != 1 ) {
V_1 -> V_33 = V_34 ;
} else {
V_1 -> V_33 = V_35 ;
}
V_1 -> V_36 = V_11 [ V_8 . V_28 ] ;
V_9 = F_5 ( & V_8 . V_9 ) ;
if ( F_8 ( V_1 , V_2 , V_3 , V_9 ,
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
V_20 = F_9 ( V_1 -> V_22 ) ;
if ( V_1 -> V_42 != NULL ) {
if ( F_10 ( V_1 -> V_42 , V_20 , V_43 , V_2 ) == - 1 )
return V_24 ;
}
V_21 = ( T_6 * ) F_11 ( sizeof( T_6 ) ) ;
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
start_time = pletoh16(&version.time_dos);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#else
V_19 . V_77 = 0 ;
V_19 . V_78 = 0 ;
V_19 . V_79 = 0 ;
#endif
V_19 . V_80 = - 1 ;
V_21 -> V_81 = mktime ( & V_19 ) ;
V_1 -> V_82 = V_83 ;
return V_84 ;
}
static int
F_8 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_7 V_9 ,
T_8 V_28 )
{
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_4 V_85 , V_86 ;
int V_87 ;
unsigned char V_88 [ 256 ] ;
for (; ; ) {
if ( ! F_12 ( V_1 -> V_22 , V_5 , 2 , V_2 , V_3 ) ) {
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_85 = F_5 ( V_5 ) ;
if ( ( V_85 != V_89 ) && ( V_85 != V_90 )
&& ( V_85 != V_91 ) && ( V_85 != V_92 )
&& ( V_85 != V_93 ) && ( V_85 != V_94 )
&& ( V_85 != V_95 )
&& ( ( V_85 != V_96 ) || ( V_9 > 2 ) ) ) {
if ( F_10 ( V_1 -> V_22 , - 2 , V_97 , V_2 ) == - 1 )
return - 1 ;
return 0 ;
}
if ( ! F_4 ( V_1 -> V_22 , V_6 , 4 ,
V_2 , V_3 ) )
return - 1 ;
V_86 = F_5 ( V_6 ) ;
if ( ( V_28 == V_37 || V_28 == V_38 ) &&
V_85 == V_90 ) {
V_87 = F_13 ( V_86 , ( int ) sizeof V_88 ) ;
if ( ! F_4 ( V_1 -> V_22 , V_88 ,
V_87 , V_2 , V_3 ) )
return - 1 ;
switch ( V_9 ) {
case 2 :
if ( F_14 ( V_1 , V_88 ,
V_86 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
case 1 :
case 4 :
case 5 :
if ( F_15 ( V_1 , V_88 ,
V_86 , V_9 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
}
if ( V_86 > sizeof V_88 ) {
if ( F_10 ( V_1 -> V_22 , V_86 - sizeof V_88 ,
V_97 , V_2 ) == - 1 )
return - 1 ;
}
} else {
if ( F_10 ( V_1 -> V_22 , V_86 , V_97 , V_2 ) == - 1 )
return - 1 ;
}
}
}
static int
F_14 ( T_2 * V_1 , unsigned char * V_88 , T_4 V_98 ,
int * V_2 , T_3 * * V_3 )
{
static const char V_99 [] = L_4 ;
if ( V_98 < sizeof V_99 - 1 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_5 ) ;
return - 1 ;
}
if ( strncmp ( ( char * ) V_88 , V_99 , sizeof V_99 - 1 ) == 0 ) {
V_1 -> V_36 = V_100 ;
} else {
* V_2 = V_29 ;
* V_3 = F_7 ( L_6 ,
V_98 , V_88 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_15 ( T_2 * V_1 , unsigned char * V_88 , T_4 V_98 ,
T_7 V_9 , int * V_2 , T_3 * * V_3 )
{
if ( V_98 < 5 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_7 ) ;
return - 1 ;
}
switch ( V_88 [ 4 ] ) {
case V_101 :
V_1 -> V_36 = V_102 ;
break;
case V_103 :
V_1 -> V_36 = V_16 ;
break;
case V_104 :
V_1 -> V_36 = V_41 ;
break;
case V_105 :
V_1 -> V_36 = V_16 ;
switch ( V_9 ) {
case 4 :
if ( V_88 [ 1 ] == 0xfa )
V_1 -> V_36 = V_40 ;
break;
case 5 :
if ( V_98 < 7 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_8 ) ;
return - 1 ;
}
if ( V_88 [ 6 ] == 0x01 )
V_1 -> V_36 = V_40 ;
break;
}
break;
case V_106 :
V_1 -> V_36 = V_107 ;
break;
default:
* V_2 = V_29 ;
* V_3 = F_7 ( L_9 ,
V_88 [ 4 ] ) ;
return - 1 ;
}
return 0 ;
}
static T_9
V_56 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_5 * V_108 )
{
T_6 * V_21 ;
int V_109 ;
T_10 V_110 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
for (; ; ) {
* V_108 = V_21 -> V_46 . V_50 ;
V_109 = F_16 ( V_1 , FALSE , & V_110 ,
& V_1 -> V_111 , V_1 -> V_112 , V_2 , V_3 ) ;
if ( V_109 < 0 ) {
return FALSE ;
}
switch ( V_109 ) {
case V_113 :
case V_114 :
case V_115 :
if ( V_110 != 0 ) {
if ( ! F_17 ( V_1 , V_110 , V_2 ,
V_3 ) )
return FALSE ;
}
return TRUE ;
case V_116 :
* V_2 = 0 ;
return FALSE ;
default:
if ( V_110 != 0 ) {
if ( ! F_17 ( V_1 , V_110 , V_2 ,
V_3 ) )
return FALSE ;
}
break;
}
}
}
static T_9
V_58 ( T_2 * V_1 , T_5 V_117 ,
struct V_118 * V_111 , T_11 * V_47 , int * V_2 , T_3 * * V_3 )
{
int V_109 ;
if ( ! F_18 ( V_1 , V_117 , V_2 , V_3 ) )
return FALSE ;
V_109 = F_16 ( V_1 , TRUE , NULL , V_111 , V_47 , V_2 , V_3 ) ;
if ( V_109 < 0 ) {
return FALSE ;
}
switch ( V_109 ) {
case V_113 :
case V_114 :
case V_115 :
break;
default:
F_19 () ;
return FALSE ;
}
return TRUE ;
}
static int
F_16 ( T_2 * V_1 , T_9 V_119 , T_10 * V_110 ,
struct V_118 * V_111 , T_11 * V_47 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_10 V_85 , V_86 ;
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
T_4 V_126 , V_127 , V_128 , V_129 ;
T_8 V_130 , V_131 ;
T_12 V_132 , V_133 , V_134 ;
if ( ! F_20 ( V_1 , V_5 , 2 , V_119 , V_2 , V_3 ) ) {
if ( * V_2 != 0 )
return - 1 ;
return V_116 ;
}
if ( ! F_21 ( V_1 , V_6 , 4 , V_119 , V_2 , V_3 ) )
return - 1 ;
V_85 = F_5 ( V_5 ) ;
V_86 = F_5 ( V_6 ) ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
switch ( V_85 ) {
case V_113 :
if ( V_21 -> V_28 == V_135 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_10 ) ;
return - 1 ;
}
if ( V_86 < sizeof V_121 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_11 ) ;
return - 1 ;
}
if ( ! F_21 ( V_1 , & V_121 , ( unsigned int ) sizeof V_121 ,
V_119 , V_2 , V_3 ) )
return - 1 ;
V_126 = F_5 ( & V_121 . V_126 ) ;
V_127 = F_5 ( & V_121 . V_127 ) ;
V_130 = V_121 . V_130 ;
V_131 = V_121 . V_131 ;
V_129 = F_5 ( & V_121 . V_129 ) ;
V_128 = F_5 ( & V_121 . V_128 ) ;
V_86 -= ( T_10 ) sizeof V_121 ;
F_22 ( V_1 , & V_111 -> V_136 , & V_121 ) ;
break;
case V_114 :
if ( V_21 -> V_28 != V_135 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_12 ) ;
return - 1 ;
}
if ( V_21 -> V_9 < 5 && V_21 -> V_45 >= 95 )
V_86 += ( T_10 ) ( sizeof V_123 - sizeof V_121 ) ;
if ( V_86 < sizeof V_123 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_13 ) ;
return - 1 ;
}
if ( ! F_21 ( V_1 , & V_123 , ( unsigned int ) sizeof V_123 ,
V_119 , V_2 , V_3 ) )
return - 1 ;
V_126 = F_5 ( & V_123 . V_126 ) ;
V_127 = F_5 ( & V_123 . V_127 ) ;
V_130 = V_123 . V_130 ;
V_131 = V_123 . V_131 ;
V_129 = F_5 ( & V_123 . V_129 ) ;
V_128 = F_5 ( & V_123 . V_128 ) ;
V_86 -= ( T_10 ) sizeof V_123 ;
F_23 ( & V_111 -> V_136 , & V_123 ) ;
break;
case V_115 :
if ( V_86 < sizeof V_125 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_14 ) ;
return - 1 ;
}
if ( ! F_21 ( V_1 , & V_125 , ( unsigned int ) sizeof V_125 ,
V_119 , V_2 , V_3 ) )
return - 1 ;
V_126 = F_5 ( & V_125 . V_126 ) ;
V_127 = F_5 ( & V_125 . V_127 ) ;
V_130 = V_125 . V_130 ;
V_131 = V_125 . V_131 ;
V_129 = F_5 ( & V_125 . V_129 ) ;
V_128 = F_5 ( & V_125 . V_128 ) ;
V_86 -= ( T_10 ) sizeof V_125 ;
F_24 ( V_1 , & V_111 -> V_136 , & V_125 ) ;
break;
case V_116 :
* V_2 = 0 ;
return V_116 ;
default:
if ( V_110 != NULL ) {
* V_110 = V_86 ;
}
return V_85 ;
}
if ( V_129 > V_86 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_15 ) ;
return - 1 ;
}
if ( V_110 != NULL ) {
* V_110 = V_86 - V_129 ;
}
V_111 -> V_85 = V_137 ;
V_111 -> V_138 = V_128 ? V_139 | V_140 : V_139 ;
V_111 -> V_141 = V_128 ? V_128 : V_129 ;
V_111 -> V_142 = V_129 ;
F_25 ( V_47 , V_129 ) ;
if ( ! F_21 ( V_1 , F_26 ( V_47 ) , V_129 , V_119 ,
V_2 , V_3 ) )
return - 1 ;
V_111 -> V_143 = F_27 ( V_1 -> V_36 ,
V_47 , V_129 , & V_111 -> V_136 ) ;
V_132 = ( ( ( T_12 ) V_130 ) << 32 ) | ( ( ( T_12 ) V_127 ) << 16 ) | V_126 ;
V_132 *= V_21 -> V_30 ;
V_133 = V_132 / F_28 ( 1000000000000 ) ;
V_134 = V_132 - V_133 * F_28 ( 1000000000000 ) ;
V_133 += V_131 * 86400 ;
V_133 += V_21 -> V_81 ;
V_111 -> V_144 . V_145 = ( V_146 ) V_133 ;
V_111 -> V_144 . V_147 = ( int ) ( V_134 / 1000 ) ;
return V_85 ;
}
static void
F_22 ( T_2 * V_1 , union V_148 * V_136 ,
struct V_120 * V_121 )
{
switch ( V_1 -> V_36 ) {
case V_13 :
V_136 -> V_149 . V_150 = 0 ;
break;
case V_107 :
case V_102 :
V_136 -> V_151 . V_152 = ( V_121 -> V_153 & V_154 ) ? TRUE : FALSE ;
break;
case V_100 :
case V_41 :
case V_16 :
V_136 -> V_155 . V_156 = ( V_121 -> V_153 & V_154 ) ? 0x00 : V_157 ;
break;
case V_40 :
V_136 -> V_158 . V_159 = ( V_121 -> V_153 & V_154 ) ? FALSE : TRUE ;
switch ( V_121 -> V_153 & V_160 ) {
case V_161 :
V_136 -> V_158 . V_162 = 0 ;
break;
case V_163 :
V_136 -> V_158 . V_162 = 1 ;
break;
case V_164 :
V_136 -> V_158 . V_162 = 2 ;
break;
default:
V_136 -> V_158 . V_162 = 30 ;
break;
}
}
}
static void
F_23 ( union V_148 * V_136 ,
struct V_122 * V_123 )
{
T_13 V_165 ;
T_8 V_166 , V_167 ;
T_4 V_168 , V_169 ;
V_136 -> V_170 . V_156 = 0 ;
V_165 = F_29 ( & V_123 -> V_171 . V_165 ) ;
if ( V_165 & V_172 )
V_136 -> V_170 . V_156 |= V_173 ;
V_166 = V_123 -> V_171 . V_174 & V_175 ;
V_167 = V_123 -> V_171 . V_174 & V_176 ;
V_168 = F_5 ( & V_123 -> V_171 . V_177 ) ;
V_169 = F_5 ( & V_123 -> V_171 . V_178 ) ;
switch ( V_166 ) {
case V_179 :
if ( V_168 == 0 && V_169 == 5 )
V_136 -> V_170 . V_180 = V_181 ;
else
V_136 -> V_170 . V_180 = V_182 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_186 :
V_136 -> V_170 . V_180 = V_187 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_188 :
V_136 -> V_170 . V_180 = V_189 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_190 :
V_136 -> V_170 . V_180 = V_191 ;
switch ( V_167 ) {
case V_192 :
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_193 :
V_136 -> V_170 . type = V_194 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_195 :
V_136 -> V_170 . type = V_196 ;
switch ( V_123 -> V_171 . V_197 ) {
case V_198 :
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_199 :
V_136 -> V_170 . V_184 =
V_200 ;
break;
case V_201 :
V_136 -> V_170 . V_184 =
V_202 ;
break;
case V_203 :
V_136 -> V_170 . V_184 =
V_204 ;
break;
case V_205 :
V_136 -> V_170 . V_184 =
V_206 ;
break;
case V_207 :
V_136 -> V_170 . V_184 =
V_208 ;
break;
case V_209 :
V_136 -> V_170 . V_184 = V_210 ;
break;
case V_211 :
V_136 -> V_170 . V_184 = V_212 ;
break;
case V_213 :
V_136 -> V_170 . V_184 = V_214 ;
break;
case V_215 :
V_136 -> V_170 . V_184 = V_216 ;
break;
case V_217 :
V_136 -> V_170 . V_184 = V_218 ;
break;
case V_219 :
V_136 -> V_170 . V_184 =
V_220 ;
break;
case V_221 :
V_136 -> V_170 . V_184 = V_222 ;
break;
default:
V_136 -> V_170 . V_184 = V_185 ;
break;
}
break;
case V_223 :
V_136 -> V_170 . type = V_224 ;
switch ( V_123 -> V_171 . V_197 ) {
case V_198 :
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_225 :
V_136 -> V_170 . V_184 =
V_226 ;
break;
case V_227 :
V_136 -> V_170 . V_184 = V_228 ;
break;
case V_229 :
V_136 -> V_170 . V_184 = V_230 ;
break;
case V_231 :
V_136 -> V_170 . V_184 =
V_232 ;
break;
case V_233 :
V_136 -> V_170 . V_184 =
V_234 ;
break;
default:
V_136 -> V_170 . V_184 = V_185 ;
break;
}
break;
case V_235 :
V_136 -> V_170 . type = V_236 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_237 :
V_136 -> V_170 . type = V_238 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_239 :
V_136 -> V_170 . type = V_240 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_241 :
V_136 -> V_170 . type = V_242 ;
switch ( V_123 -> V_171 . V_197 ) {
case V_198 :
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_243 :
V_136 -> V_170 . V_184 =
V_244 ;
break;
case V_245 :
V_136 -> V_170 . V_184 =
V_246 ;
break;
case V_247 :
V_136 -> V_170 . V_184 =
V_248 ;
break;
default:
V_136 -> V_170 . V_184 = V_185 ;
break;
}
break;
default:
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
}
break;
case V_249 :
V_136 -> V_170 . V_180 = V_250 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_251 :
V_136 -> V_170 . V_180 = V_181 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
case V_252 :
V_136 -> V_170 . V_180 = V_253 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
default:
V_136 -> V_170 . V_180 = V_182 ;
V_136 -> V_170 . type = V_183 ;
V_136 -> V_170 . V_184 = V_185 ;
break;
}
V_136 -> V_170 . V_168 = V_168 ;
V_136 -> V_170 . V_169 = V_169 ;
V_136 -> V_170 . V_162 = F_5 ( & V_123 -> V_171 . V_162 ) ;
V_136 -> V_170 . V_254 = F_5 ( & V_123 -> V_171 . V_254 ) ;
V_136 -> V_170 . V_255 = F_5 ( & V_123 -> V_171 . V_256 . V_255 ) ;
V_136 -> V_170 . V_257 = F_5 ( & V_123 -> V_171 . V_256 . V_257 ) ;
V_136 -> V_170 . V_258 = F_30 ( & V_123 -> V_171 . V_256 . V_258 ) ;
}
static void
F_24 ( T_2 * V_1 , union V_148 * V_136 ,
struct V_124 * V_125 V_259 )
{
switch ( V_1 -> V_36 ) {
case V_13 :
V_136 -> V_149 . V_150 = - 1 ;
break;
}
}
static int
F_31 ( const T_8 * V_260 , int V_141 )
{
int V_261 ;
if ( V_141 <= 0 ) {
return V_107 ;
}
if ( V_260 [ 0 ] == 0xFF ) {
return V_107 ;
}
if ( V_141 >= 2 ) {
if ( V_260 [ 0 ] == 0x07 && V_260 [ 1 ] == 0x03 ) {
return V_262 ;
} else if ( ( V_260 [ 0 ] == 0x0F && V_260 [ 1 ] == 0x00 ) ||
( V_260 [ 0 ] == 0x8F && V_260 [ 1 ] == 0x00 ) ) {
return V_263 ;
}
for ( V_261 = 0 ; V_261 < V_141 && ( V_260 [ V_261 ] & 0x01 ) == 0 ; V_261 ++ )
;
V_261 ++ ;
if ( V_261 == V_141 ) {
return V_100 ;
}
if ( V_260 [ V_261 ] == 0x03 )
return V_41 ;
}
return V_100 ;
}
static int
F_27 ( int V_264 , T_11 * V_47 , int V_141 ,
union V_148 * V_136 )
{
const T_8 * V_260 ;
V_260 = F_26 ( V_47 ) ;
switch ( V_264 ) {
case V_16 :
V_264 = F_31 ( V_260 , V_141 ) ;
switch ( V_264 ) {
case V_262 :
case V_263 :
case V_107 :
if ( V_136 -> V_155 . V_156 == 0 )
V_136 -> V_151 . V_152 = TRUE ;
else
V_136 -> V_151 . V_152 = FALSE ;
break;
case V_40 :
if ( V_136 -> V_155 . V_156 == 0x00 )
V_136 -> V_158 . V_159 = FALSE ;
else
V_136 -> V_158 . V_159 = TRUE ;
V_136 -> V_158 . V_162 = 0 ;
break;
}
break;
case V_18 :
if ( V_136 -> V_170 . type == V_224 && V_141 >= 2 ) {
if ( V_260 [ 0 ] == 0xff && V_260 [ 1 ] == 0x00 ) {
V_136 -> V_170 . V_184 =
V_226 ;
} else {
if ( V_136 -> V_170 . V_184 ==
V_226 ) {
V_136 -> V_170 . V_184 =
V_228 ;
}
}
}
break;
}
return V_264 ;
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
F_33 ( T_14 V_265 , T_14 T_15 V_259 )
{
F_32 ( V_265 ) ;
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
F_36 ( int V_264 )
{
if ( V_264 == V_16 )
return V_266 ;
if ( V_264 < 0 || ( unsigned ) V_264 >= V_267 || V_268 [ V_264 ] == - 1 )
return V_269 ;
return 0 ;
}
T_9
F_37 ( T_16 * V_270 , int * V_2 )
{
T_17 * V_21 ;
char V_47 [ 6 ] = { V_26 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 } ;
V_270 -> V_271 = V_272 ;
V_270 -> V_273 = V_274 ;
V_21 = ( T_17 * ) F_11 ( sizeof( T_17 ) ) ;
V_270 -> V_44 = ( void * ) V_21 ;
V_21 -> V_275 = TRUE ;
V_21 -> V_81 = 0 ;
if ( ! F_38 ( V_270 , F_2 , sizeof F_2 ,
V_2 ) )
return FALSE ;
if ( ! F_38 ( V_270 , V_47 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_9
V_272 ( T_16 * V_270 , const struct V_118 * V_111 ,
const T_8 * V_260 , int * V_2 , T_3 * * V_3 V_259 )
{
const union V_148 * V_136 = & V_111 -> V_136 ;
T_17 * V_21 = ( T_17 * ) V_270 -> V_44 ;
struct V_120 V_276 ;
char V_47 [ 6 ] ;
V_146 V_133 ;
T_12 V_132 ;
T_4 V_277 , V_278 ;
T_8 V_279 ;
struct V_7 V_8 ;
T_7 V_9 , V_45 ;
T_4 V_10 ;
struct V_19 * V_19 ;
if ( V_111 -> V_85 != V_137 ) {
* V_2 = V_280 ;
return FALSE ;
}
if ( V_111 -> V_142 > 65535 ) {
* V_2 = V_281 ;
return FALSE ;
}
if ( V_21 -> V_275 ) {
V_21 -> V_275 = FALSE ;
V_19 = localtime ( & V_111 -> V_144 . V_145 ) ;
if ( V_19 != NULL && V_19 -> V_66 >= V_69 ) {
V_10 = ( V_19 -> V_66 - V_69 ) << V_68 ;
V_10 |= ( V_19 -> V_70 - V_73 ) << V_72 ;
V_10 |= V_19 -> V_74 << V_76 ;
V_21 -> V_81 = V_111 -> V_144 . V_145 - ( 3600 * V_19 -> V_77 + 60 * V_19 -> V_78 + V_19 -> V_79 ) ;
} else {
V_10 = 0 ;
V_21 -> V_81 = 0 ;
}
V_9 = 4 ;
V_45 = 0 ;
V_8 . V_9 = F_39 ( V_9 ) ;
V_8 . V_45 = F_39 ( V_45 ) ;
V_8 . V_282 = 0 ;
V_8 . V_65 = F_39 ( V_10 ) ;
V_8 . type = 4 ;
V_8 . V_28 = V_268 [ V_270 -> V_264 ] ;
V_8 . V_32 = 1 ;
V_8 . V_30 = 1 ;
V_8 . V_283 = 0 ;
V_8 . V_284 = 0 ;
V_8 . V_39 [ 0 ] = 0 ;
V_8 . V_39 [ 1 ] = 0 ;
if ( ! F_38 ( V_270 , & V_8 , sizeof V_8 , V_2 ) )
return FALSE ;
}
V_47 [ 0 ] = V_113 ;
V_47 [ 1 ] = 0x00 ;
V_47 [ 2 ] = ( char ) ( ( V_111 -> V_142 + sizeof( struct V_120 ) ) % 256 ) ;
V_47 [ 3 ] = ( char ) ( ( V_111 -> V_142 + sizeof( struct V_120 ) ) / 256 ) ;
V_47 [ 4 ] = 0x00 ;
V_47 [ 5 ] = 0x00 ;
if ( ! F_38 ( V_270 , V_47 , 6 , V_2 ) )
return FALSE ;
V_133 = V_111 -> V_144 . V_145 - V_21 -> V_81 ;
V_276 . V_131 = ( T_8 ) ( V_133 / 86400 ) ;
V_133 -= V_276 . V_131 * 86400 ;
V_132 = V_133 * F_28 ( 1000000000000 ) +
V_111 -> V_144 . V_147 * F_28 ( 1000 ) ;
V_132 /= V_64 [ 1 ] ;
V_277 = ( T_4 ) ( ( V_132 >> 0 ) & 0xFFFF ) ;
V_278 = ( T_4 ) ( ( V_132 >> 16 ) & 0xFFFF ) ;
V_279 = ( T_8 ) ( ( V_132 >> 32 ) & 0xFF ) ;
V_276 . V_126 = F_39 ( V_277 ) ;
V_276 . V_127 = F_39 ( V_278 ) ;
V_276 . V_130 = V_279 ;
V_276 . V_129 = F_39 ( V_111 -> V_142 ) ;
switch ( V_270 -> V_264 ) {
case V_100 :
case V_41 :
V_276 . V_153 = ( V_136 -> V_155 . V_156 & V_157 ) ? 0x00 : V_154 ;
break;
case V_107 :
case V_102 :
V_276 . V_153 = V_136 -> V_151 . V_152 ? 0x00 : V_154 ;
break;
case V_40 :
V_276 . V_153 = V_136 -> V_158 . V_159 ? V_154 : 0x00 ;
switch ( V_136 -> V_158 . V_162 ) {
case 0 :
V_276 . V_153 |= V_161 ;
break;
case 1 :
V_276 . V_153 |= V_163 ;
break;
case 2 :
V_276 . V_153 |= V_164 ;
break;
}
break;
default:
V_276 . V_153 = 0 ;
break;
}
V_276 . V_156 = 0 ;
V_276 . V_128 = V_111 -> V_141 != V_111 -> V_142 ? F_39 ( V_111 -> V_141 ) : 0 ;
V_276 . V_39 = 0 ;
if ( ! F_38 ( V_270 , & V_276 , sizeof V_276 , V_2 ) )
return FALSE ;
if ( ! F_38 ( V_270 , V_260 , V_111 -> V_142 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_9
V_274 ( T_16 * V_270 , int * V_2 )
{
char V_47 [ 6 ] = { V_116 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( ! F_38 ( V_270 , V_47 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_40 ( unsigned char * V_285 , T_18 V_286 , unsigned char * V_287 ,
T_18 V_288 , int * V_2 , T_3 * * V_3 )
{
unsigned char * V_289 = V_285 ;
unsigned char * V_290 = V_287 ;
unsigned char * V_291 = V_289 + V_286 ;
unsigned char * V_292 = V_290 + V_288 ;
unsigned int V_293 ;
unsigned int V_294 = 0 ;
unsigned int V_295 ;
unsigned int V_296 ;
int V_98 ;
int V_297 ;
if ( V_286 > V_298 ) {
return ( - 1 ) ;
}
V_293 = 0 ;
while ( V_289 < V_291 )
{
V_293 = V_293 >> 1 ;
if ( 0 == V_293 )
{
F_41 ( 3 ) ;
V_293 = 0x8000 ;
V_294 = F_5 ( V_289 ) ;
V_289 += 2 ;
}
if ( ! ( V_293 & V_294 ) )
{
F_42 ( 1 ) ;
* ( V_290 ++ ) = * ( V_289 ++ ) ;
}
else
{
V_295 = ( unsigned int ) ( ( * V_289 ) >> 4 ) & 0xF ;
V_296 = ( unsigned int ) ( ( * V_289 ) & 0xF ) ;
V_289 ++ ;
switch ( V_295 )
{
case 0 :
V_98 = V_296 + 3 ;
F_43 ( V_98 ) ;
break;
case 1 :
F_41 ( 1 ) ;
V_98 = V_296 + ( ( unsigned int ) ( * V_289 ++ ) << 4 ) + 19 ;
F_43 ( V_98 ) ;
break;
case 2 :
V_299 ;
F_41 ( 1 ) ;
V_98 = ( unsigned int ) ( * V_289 ++ ) + 16 ;
F_44 ( V_297 , V_98 ) ;
break;
default :
V_299 ;
V_98 = V_295 ;
F_44 ( V_297 , V_98 ) ;
break;
}
}
}
return ( int ) ( V_290 - V_287 ) ;
}
static T_9
F_20 ( T_2 * V_1 , void * V_88 , unsigned int V_48 , T_9 V_119 ,
int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
T_19 V_300 ;
T_20 * V_301 ;
unsigned char * V_302 = ( unsigned char * ) V_88 ;
T_21 * V_303 ;
unsigned int V_304 ;
unsigned int V_305 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_119 ) {
V_300 = V_1 -> V_42 ;
V_301 = & V_21 -> rand ;
} else {
V_300 = V_1 -> V_22 ;
V_301 = & V_21 -> V_46 ;
}
if ( V_1 -> V_33 == V_35 ) {
if ( ! F_12 ( V_300 , V_88 , V_48 , V_2 , V_3 ) )
return FALSE ;
V_301 -> V_50 += V_48 ;
V_301 -> V_51 += V_48 ;
return TRUE ;
}
if ( V_301 -> V_47 == NULL ) {
V_301 -> V_47 = ( unsigned char * ) F_11 ( V_306 ) ;
if ( V_119 ) {
V_21 -> V_54 = V_21 -> V_52 ;
} else {
if ( V_1 -> V_42 != NULL ) {
F_45 ( V_21 -> V_52 == NULL ) ;
V_303 = F_46 ( T_21 , 1 ) ;
V_303 -> V_307 = V_301 -> V_51 ;
V_303 -> V_308 = V_301 -> V_50 ;
V_21 -> V_52 = F_47 ( V_21 -> V_52 ,
V_303 ) ;
V_21 -> V_53 = V_21 -> V_52 ;
}
}
if ( ! F_48 ( V_300 , V_301 , V_2 , V_3 ) )
return FALSE ;
}
while ( V_48 > 0 ) {
V_305 = V_301 -> V_48 - V_301 -> V_49 ;
if ( V_305 == 0 ) {
if ( V_119 ) {
V_21 -> V_54 = F_49 ( V_21 -> V_54 ) ;
if ( ! V_21 -> V_54 ) {
* V_2 = V_309 ;
return FALSE ;
}
} else {
if ( V_1 -> V_42 != NULL ) {
V_303 = F_46 ( T_21 , 1 ) ;
V_303 -> V_307 = V_301 -> V_51 ;
V_303 -> V_308 = V_301 -> V_50 ;
V_21 -> V_53 = F_47 ( V_21 -> V_53 ,
V_303 ) ;
}
}
if ( ! F_48 ( V_300 , V_301 , V_2 , V_3 ) )
return FALSE ;
V_305 = V_301 -> V_48 - V_301 -> V_49 ;
}
V_304 = V_48 ;
if ( V_304 > V_305 )
V_304 = V_305 ;
memcpy ( V_302 , & V_301 -> V_47 [ V_301 -> V_49 ] ,
V_304 ) ;
V_48 -= V_304 ;
V_302 += V_304 ;
V_301 -> V_49 += V_304 ;
V_301 -> V_50 += V_304 ;
}
return TRUE ;
}
static T_9
F_21 ( T_2 * V_1 , void * V_88 , unsigned int V_48 , T_9 V_119 ,
int * V_2 , T_3 * * V_3 )
{
if ( ! F_20 ( V_1 , V_88 , V_48 , V_119 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_23 ;
return FALSE ;
}
return TRUE ;
}
static T_9
F_48 ( T_19 V_300 , T_20 * V_301 , int * V_2 ,
T_3 * * V_3 )
{
int V_310 ;
unsigned short V_311 ;
T_7 V_312 ;
T_9 V_313 ;
unsigned char * V_314 ;
int V_315 ;
if ( ! F_12 ( V_300 , & V_311 , 2 , V_2 , V_3 ) )
return FALSE ;
V_301 -> V_51 += 2 ;
V_312 = F_5 ( & V_311 ) ;
if ( V_312 < 0 ) {
V_310 = - V_312 ;
V_313 = TRUE ;
} else {
V_310 = V_312 ;
V_313 = FALSE ;
}
V_314 = ( unsigned char * ) F_11 ( V_316 ) ;
if ( ! F_4 ( V_300 , V_314 , V_310 , V_2 , V_3 ) ) {
F_32 ( V_314 ) ;
return FALSE ;
}
V_301 -> V_51 += V_310 ;
if ( V_313 ) {
memcpy ( V_301 -> V_47 , V_314 , V_310 ) ;
V_315 = V_310 ;
} else {
V_315 = F_40 ( V_314 , V_310 ,
V_301 -> V_47 , V_306 , V_2 ,
V_3 ) ;
if ( V_315 < 0 ) {
F_32 ( V_314 ) ;
return FALSE ;
}
}
F_32 ( V_314 ) ;
V_301 -> V_49 = 0 ;
V_301 -> V_48 = V_315 ;
return TRUE ;
}
static T_9
F_17 ( T_2 * V_1 , unsigned int V_317 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
char * V_47 ;
unsigned int V_318 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_1 -> V_33 == V_35 ) {
V_21 -> V_46 . V_50 += V_317 ;
return F_4 ( V_1 -> V_22 , NULL , V_317 , V_2 , V_3 ) ;
}
V_47 = ( char * ) F_11 ( V_316 ) ;
while ( V_317 != 0 ) {
if ( V_317 > V_316 )
V_318 = V_316 ;
else
V_318 = V_317 ;
if ( ! F_21 ( V_1 , V_47 , V_318 , FALSE , V_2 , V_3 ) ) {
F_32 ( V_47 ) ;
return FALSE ;
}
V_317 -= V_318 ;
}
F_32 ( V_47 ) ;
return TRUE ;
}
static T_9
F_18 ( T_2 * V_1 , T_5 V_297 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_21 ;
T_5 V_319 ;
T_22 * V_320 , * V_321 ;
T_21 * V_322 , * V_323 ;
V_21 = ( T_6 * ) V_1 -> V_44 ;
if ( V_1 -> V_33 == V_35 ) {
if ( F_10 ( V_1 -> V_42 , V_297 , V_43 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
V_319 = V_297 - V_21 -> rand . V_50 ;
V_320 = NULL ;
if ( V_319 > 0 ) {
if ( ( T_18 ) ( V_21 -> rand . V_49 + V_319 ) >= V_21 -> rand . V_48 ) {
if ( V_21 -> V_54 == NULL ) {
V_320 = V_21 -> V_52 ;
} else {
V_320 = F_49 ( V_21 -> V_54 ) ;
}
while ( V_320 ) {
V_321 = F_49 ( V_320 ) ;
if ( V_321 == NULL ) {
break;
}
V_322 = ( T_21 * ) V_321 -> V_265 ;
if ( V_322 -> V_308 > V_297 )
break;
V_320 = V_321 ;
}
if ( V_320 == NULL ) {
* V_2 = V_309 ;
return FALSE ;
}
}
} else if ( V_319 < 0 ) {
if ( V_21 -> rand . V_49 + V_319 < 0 ) {
if ( V_21 -> V_54 == NULL ) {
V_320 = V_21 -> V_53 ;
} else {
V_320 = F_50 ( V_21 -> V_54 ) ;
}
while ( V_320 ) {
V_323 = ( T_21 * ) V_320 -> V_265 ;
if ( V_323 -> V_308 <= V_297 )
break;
V_320 = F_50 ( V_320 ) ;
}
if ( V_320 == NULL ) {
* V_2 = V_309 ;
return FALSE ;
}
}
}
if ( V_320 != NULL ) {
V_323 = ( T_21 * ) V_320 -> V_265 ;
if ( F_10 ( V_1 -> V_42 , V_323 -> V_307 , V_43 , V_2 ) == - 1 )
return FALSE ;
if ( V_21 -> rand . V_47 == NULL ) {
V_21 -> rand . V_47 = ( unsigned char * ) F_11 ( V_306 ) ;
}
V_21 -> V_54 = V_320 ;
V_21 -> rand . V_50 = V_323 -> V_308 ;
V_21 -> rand . V_51 = V_323 -> V_307 ;
if ( ! F_48 ( V_1 -> V_42 , & V_21 -> rand , V_2 , V_3 ) )
return FALSE ;
V_319 = V_297 - V_21 -> rand . V_50 ;
F_45 ( V_319 >= 0 && ( unsigned long ) V_319 < V_21 -> rand . V_48 ) ;
}
V_21 -> rand . V_49 += ( int ) V_319 ;
V_21 -> rand . V_50 += V_319 ;
return TRUE ;
}
