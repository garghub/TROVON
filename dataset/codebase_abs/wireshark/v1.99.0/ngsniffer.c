int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_3 type ;
struct V_7 V_8 ;
T_3 V_9 ;
T_3 V_10 ;
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
T_4 V_20 ;
T_5 * V_21 ;
V_22 = V_23 ;
if ( ! F_4 ( V_1 -> V_24 , V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_25 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) ) {
return 0 ;
}
V_22 = V_23 ;
if ( ! F_4 ( V_1 -> V_24 , V_5 , 2 , V_2 , V_3 ) )
return - 1 ;
if ( ! F_4 ( V_1 -> V_24 , V_6 , 4 , V_2 , V_3 ) )
return - 1 ;
type = F_5 ( V_5 ) ;
if ( type != V_26 ) {
* V_2 = V_27 ;
* V_3 = F_6 ( L_1 ) ;
return - 1 ;
}
V_22 = V_23 ;
if ( ! F_4 ( V_1 -> V_24 , & V_8 , sizeof V_8 , V_2 , V_3 ) )
return - 1 ;
if ( V_8 . V_28 >= F_3
|| V_11 [ V_8 . V_28 ] == V_15 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_2 ,
V_8 . V_28 ) ;
return - 1 ;
}
if ( V_8 . V_30 >= V_31 ) {
* V_2 = V_32 ;
* V_3 = F_6 ( L_3 , V_8 . V_30 ) ;
return - 1 ;
}
if ( V_8 . V_33 != 1 ) {
V_1 -> V_34 = V_35 ;
} else {
V_1 -> V_34 = V_36 ;
}
V_1 -> V_37 = V_11 [ V_8 . V_28 ] ;
V_9 = F_5 ( & V_8 . V_9 ) ;
if ( F_7 ( V_1 , V_2 , V_3 , V_9 ,
V_8 . V_28 ) < 0 )
return - 1 ;
if ( ( V_8 . V_28 == V_38 ||
V_8 . V_28 == V_39 ) &&
V_1 -> V_37 == V_16 ) {
switch ( V_9 ) {
case 1 :
switch ( F_5 ( & V_8 . V_40 [ 0 ] ) ) {
case 1 :
case 2 :
V_1 -> V_37 = V_41 ;
break;
}
break;
case 3 :
V_1 -> V_37 = V_42 ;
break;
}
}
V_20 = F_8 ( V_1 -> V_24 ) ;
if ( V_1 -> V_43 != NULL ) {
if ( F_9 ( V_1 -> V_43 , V_20 , V_44 , V_2 ) == - 1 )
return - 1 ;
}
V_21 = ( T_5 * ) F_10 ( sizeof( T_5 ) ) ;
V_1 -> V_45 = ( void * ) V_21 ;
V_21 -> V_9 = V_9 ;
V_21 -> V_46 = F_5 ( & V_8 . V_46 ) ;
V_21 -> V_47 . V_48 = NULL ;
V_21 -> V_47 . V_49 = 0 ;
V_21 -> V_47 . V_50 = 0 ;
V_21 -> rand . V_48 = NULL ;
V_21 -> rand . V_49 = 0 ;
V_21 -> rand . V_50 = 0 ;
V_21 -> V_47 . V_51 = V_20 ;
V_21 -> V_47 . V_52 = V_20 ;
V_21 -> rand . V_51 = V_20 ;
V_21 -> rand . V_52 = V_20 ;
V_21 -> V_53 = NULL ;
V_21 -> V_54 = NULL ;
V_21 -> V_55 = NULL ;
V_1 -> V_56 = V_57 ;
V_1 -> V_58 = V_59 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_62 = V_63 ;
V_1 -> V_64 = 0 ;
V_21 -> V_30 = V_65 [ V_8 . V_30 ] ;
V_21 -> V_28 = V_8 . V_28 ;
V_10 = F_5 ( & V_8 . V_66 ) ;
V_19 . V_67 = ( ( V_10 & V_68 ) >> V_69 ) + V_70 ;
V_19 . V_71 = ( ( V_10 & V_72 ) >> V_73 ) + V_74 ;
V_19 . V_75 = ( ( V_10 & V_76 ) >> V_77 ) ;
#if 0
start_time = pletoh16(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
V_19 . V_78 = 0 ;
V_19 . V_79 = 0 ;
V_19 . V_80 = 0 ;
V_19 . V_81 = - 1 ;
V_21 -> V_82 = mktime ( & V_19 ) ;
V_1 -> V_83 = V_84 ;
return 1 ;
}
static int
F_7 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 V_9 ,
T_7 V_28 )
{
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_3 type , V_85 ;
int V_86 ;
unsigned char V_87 [ 256 ] ;
for (; ; ) {
V_22 = V_23 ;
if ( ! F_11 ( V_1 -> V_24 , V_5 , 2 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
return 0 ;
return - 1 ;
}
type = F_5 ( V_5 ) ;
if ( ( type != V_88 ) && ( type != V_89 )
&& ( type != V_90 ) && ( type != V_91 )
&& ( type != V_92 ) && ( type != V_93 )
&& ( type != V_94 )
&& ( ( type != V_95 ) || ( V_9 > 2 ) ) ) {
if ( F_9 ( V_1 -> V_24 , - 2 , V_96 , V_2 ) == - 1 )
return - 1 ;
return 0 ;
}
V_22 = V_23 ;
if ( ! F_4 ( V_1 -> V_24 , V_6 , 4 ,
V_2 , V_3 ) )
return - 1 ;
V_85 = F_5 ( V_6 ) ;
if ( ( V_28 == V_38 || V_28 == V_39 ) &&
type == V_89 ) {
V_86 = F_12 ( V_85 , ( int ) sizeof V_87 ) ;
if ( ! F_4 ( V_1 -> V_24 , V_87 ,
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
if ( F_9 ( V_1 -> V_24 , V_85 - sizeof V_87 ,
V_96 , V_2 ) == - 1 )
return - 1 ;
}
} else {
if ( F_9 ( V_1 -> V_24 , V_85 , V_96 , V_2 ) == - 1 )
return - 1 ;
}
}
}
static int
F_13 ( T_1 * V_1 , unsigned char * V_87 , T_3 V_85 ,
int * V_2 , T_2 * * V_3 )
{
static const char V_97 [] = L_4 ;
if ( V_85 < sizeof V_97 - 1 ) {
* V_2 = V_29 ;
* V_3 = F_6 ( L_5 ) ;
return - 1 ;
}
if ( strncmp ( ( char * ) V_87 , V_97 , sizeof V_97 - 1 ) == 0 ) {
V_1 -> V_37 = V_98 ;
} else {
* V_2 = V_29 ;
* V_3 = F_6 ( L_6 ,
V_85 , V_87 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_14 ( T_1 * V_1 , unsigned char * V_87 , T_3 V_85 ,
T_6 V_9 , int * V_2 , T_2 * * V_3 )
{
if ( V_85 < 5 ) {
* V_2 = V_29 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
switch ( V_87 [ 4 ] ) {
case V_99 :
V_1 -> V_37 = V_100 ;
break;
case V_101 :
V_1 -> V_37 = V_16 ;
break;
case V_102 :
V_1 -> V_37 = V_42 ;
break;
case V_103 :
V_1 -> V_37 = V_16 ;
switch ( V_9 ) {
case 4 :
if ( V_87 [ 1 ] == 0xfa )
V_1 -> V_37 = V_41 ;
break;
case 5 :
if ( V_85 < 7 ) {
* V_2 = V_29 ;
* V_3 = F_15 ( L_8 ) ;
return - 1 ;
}
if ( V_87 [ 6 ] == 0x01 )
V_1 -> V_37 = V_41 ;
break;
}
break;
case V_104 :
V_1 -> V_37 = V_105 ;
break;
default:
* V_2 = V_29 ;
* V_3 = F_6 ( L_9 ,
V_87 [ 4 ] ) ;
return - 1 ;
}
return 0 ;
}
static T_8
V_57 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_4 * V_106 )
{
T_5 * V_21 ;
int V_107 ;
T_9 V_108 ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
for (; ; ) {
* V_106 = V_21 -> V_47 . V_51 ;
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
static T_8
V_59 ( T_1 * V_1 , T_4 V_115 ,
struct V_116 * V_109 , T_10 * V_48 , int * V_2 , T_2 * * V_3 )
{
int V_107 ;
if ( ! F_18 ( V_1 , V_115 , V_2 , V_3 ) )
return FALSE ;
V_107 = F_16 ( V_1 , TRUE , NULL , V_109 , V_48 , V_2 , V_3 ) ;
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
F_16 ( T_1 * V_1 , T_8 V_117 , T_9 * V_108 ,
struct V_116 * V_109 , T_10 * V_48 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_21 ;
T_4 V_118 ;
char V_5 [ 2 ] ;
char V_6 [ 4 ] ;
T_3 type , V_85 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_123 V_124 ;
T_3 V_125 , V_126 , V_127 , V_128 ;
T_7 V_129 , V_130 ;
T_11 V_131 , V_132 , V_133 ;
V_118 = F_20 ( V_5 , 2 , V_1 , V_117 , V_2 ,
V_3 ) ;
if ( V_118 != 2 ) {
if ( * V_2 != 0 )
return - 1 ;
if ( V_118 != 0 ) {
* V_2 = V_25 ;
return - 1 ;
}
return V_114 ;
}
V_118 = F_20 ( V_6 , 4 , V_1 , V_117 , V_2 ,
V_3 ) ;
if ( V_118 != 4 ) {
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
type = F_5 ( V_5 ) ;
V_85 = F_5 ( V_6 ) ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
switch ( type ) {
case V_111 :
if ( V_21 -> V_28 == V_134 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_10 ) ;
return - 1 ;
}
V_118 = F_20 ( & V_120 , ( unsigned int ) sizeof V_120 ,
V_1 , V_117 , V_2 , V_3 ) ;
if ( V_118 != sizeof V_120 ) {
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
V_125 = F_5 ( & V_120 . V_125 ) ;
V_126 = F_5 ( & V_120 . V_126 ) ;
V_129 = V_120 . V_129 ;
V_130 = V_120 . V_130 ;
V_128 = F_5 ( & V_120 . V_128 ) ;
V_127 = F_5 ( & V_120 . V_127 ) ;
V_85 -= sizeof V_120 ;
F_21 ( V_1 , & V_109 -> V_135 , & V_120 ) ;
break;
case V_112 :
if ( V_21 -> V_28 != V_134 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_11 ) ;
return - 1 ;
}
V_118 = F_20 ( & V_122 , ( unsigned int ) sizeof V_122 ,
V_1 , V_117 , V_2 , V_3 ) ;
if ( V_118 != sizeof V_122 ) {
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
V_125 = F_5 ( & V_122 . V_125 ) ;
V_126 = F_5 ( & V_122 . V_126 ) ;
V_129 = V_122 . V_129 ;
V_130 = V_122 . V_130 ;
V_128 = F_5 ( & V_122 . V_128 ) ;
V_127 = F_5 ( & V_122 . V_127 ) ;
if ( V_21 -> V_9 >= 5 )
V_85 -= sizeof V_122 ;
else {
if ( V_21 -> V_46 >= 95 )
V_85 -= sizeof V_120 ;
else
V_85 -= sizeof V_122 ;
}
F_22 ( & V_109 -> V_135 , & V_122 ) ;
break;
case V_113 :
V_118 = F_20 ( & V_124 , ( unsigned int ) sizeof V_124 ,
V_1 , V_117 , V_2 , V_3 ) ;
if ( V_118 != sizeof V_124 ) {
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
V_125 = F_5 ( & V_124 . V_125 ) ;
V_126 = F_5 ( & V_124 . V_126 ) ;
V_129 = V_124 . V_129 ;
V_130 = V_124 . V_130 ;
V_128 = F_5 ( & V_124 . V_128 ) ;
V_127 = F_5 ( & V_124 . V_127 ) ;
V_85 -= sizeof V_124 ;
F_23 ( V_1 , & V_109 -> V_135 , & V_124 ) ;
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
if ( V_128 > V_85 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_12 ) ;
return - 1 ;
}
if ( V_108 != NULL ) {
* V_108 = V_85 - V_128 ;
}
V_109 -> V_136 = V_137 ;
V_109 -> V_138 = V_127 ? V_139 | V_140 : V_139 ;
V_109 -> V_141 = V_127 ? V_127 : V_128 ;
V_109 -> V_142 = V_128 ;
F_24 ( V_48 , V_128 ) ;
V_118 = F_20 ( F_25 ( V_48 ) , V_128 , V_1 ,
V_117 , V_2 , V_3 ) ;
if ( V_118 != ( T_4 ) V_128 ) {
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
V_109 -> V_143 = F_26 ( V_1 -> V_37 ,
V_48 , V_85 , & V_109 -> V_135 ) ;
V_131 = ( ( ( T_11 ) V_129 ) << 32 ) | ( ( ( T_11 ) V_126 ) << 16 ) | V_125 ;
V_131 *= V_21 -> V_30 ;
V_132 = V_131 / F_27 ( 1000000000000 ) ;
V_133 = V_131 - V_132 * F_27 ( 1000000000000 ) ;
V_132 += V_130 * 86400 ;
V_132 += V_21 -> V_82 ;
V_109 -> V_144 . V_145 = ( V_146 ) V_132 ;
V_109 -> V_144 . V_147 = ( int ) ( V_133 / 1000 ) ;
return type ;
}
static void
F_21 ( T_1 * V_1 , union V_148 * V_135 ,
struct V_119 * V_120 )
{
switch ( V_1 -> V_37 ) {
case V_13 :
V_135 -> V_149 . V_150 = 0 ;
break;
case V_105 :
case V_100 :
V_135 -> V_151 . V_152 = ( V_120 -> V_153 & V_154 ) ? TRUE : FALSE ;
break;
case V_98 :
case V_42 :
case V_16 :
V_135 -> V_155 . V_156 = ( V_120 -> V_153 & V_154 ) ? 0x00 : V_157 ;
break;
case V_41 :
V_135 -> V_158 . V_159 = ( V_120 -> V_153 & V_154 ) ? FALSE : TRUE ;
switch ( V_120 -> V_153 & V_160 ) {
case V_161 :
V_135 -> V_158 . V_162 = 0 ;
break;
case V_163 :
V_135 -> V_158 . V_162 = 1 ;
break;
case V_164 :
V_135 -> V_158 . V_162 = 2 ;
break;
default:
V_135 -> V_158 . V_162 = 30 ;
break;
}
}
}
static void
F_22 ( union V_148 * V_135 ,
struct V_121 * V_122 )
{
T_12 V_165 ;
T_7 V_166 , V_167 ;
T_3 V_168 , V_169 ;
V_135 -> V_170 . V_156 = 0 ;
V_165 = F_28 ( & V_122 -> V_171 . V_165 ) ;
if ( V_165 & V_172 )
V_135 -> V_170 . V_156 |= V_173 ;
V_166 = V_122 -> V_171 . V_174 & V_175 ;
V_167 = V_122 -> V_171 . V_174 & V_176 ;
V_168 = F_5 ( & V_122 -> V_171 . V_177 ) ;
V_169 = F_5 ( & V_122 -> V_171 . V_178 ) ;
switch ( V_166 ) {
case V_179 :
if ( V_168 == 0 && V_169 == 5 )
V_135 -> V_170 . V_180 = V_181 ;
else
V_135 -> V_170 . V_180 = V_182 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_186 :
V_135 -> V_170 . V_180 = V_187 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_188 :
V_135 -> V_170 . V_180 = V_189 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_190 :
V_135 -> V_170 . V_180 = V_191 ;
switch ( V_167 ) {
case V_192 :
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_193 :
V_135 -> V_170 . type = V_194 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_195 :
V_135 -> V_170 . type = V_196 ;
switch ( V_122 -> V_171 . V_197 ) {
case V_198 :
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_199 :
V_135 -> V_170 . V_184 =
V_200 ;
break;
case V_201 :
V_135 -> V_170 . V_184 =
V_202 ;
break;
case V_203 :
V_135 -> V_170 . V_184 =
V_204 ;
break;
case V_205 :
V_135 -> V_170 . V_184 =
V_206 ;
break;
case V_207 :
V_135 -> V_170 . V_184 =
V_208 ;
break;
case V_209 :
V_135 -> V_170 . V_184 = V_210 ;
break;
case V_211 :
V_135 -> V_170 . V_184 = V_212 ;
break;
case V_213 :
V_135 -> V_170 . V_184 = V_214 ;
break;
case V_215 :
V_135 -> V_170 . V_184 = V_216 ;
break;
case V_217 :
V_135 -> V_170 . V_184 = V_218 ;
break;
case V_219 :
V_135 -> V_170 . V_184 =
V_220 ;
break;
case V_221 :
V_135 -> V_170 . V_184 = V_222 ;
break;
default:
V_135 -> V_170 . V_184 = V_185 ;
break;
}
break;
case V_223 :
V_135 -> V_170 . type = V_224 ;
switch ( V_122 -> V_171 . V_197 ) {
case V_198 :
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_225 :
V_135 -> V_170 . V_184 =
V_226 ;
break;
case V_227 :
V_135 -> V_170 . V_184 = V_228 ;
break;
case V_229 :
V_135 -> V_170 . V_184 = V_230 ;
break;
case V_231 :
V_135 -> V_170 . V_184 =
V_232 ;
break;
case V_233 :
V_135 -> V_170 . V_184 =
V_234 ;
break;
default:
V_135 -> V_170 . V_184 = V_185 ;
break;
}
break;
case V_235 :
V_135 -> V_170 . type = V_236 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_237 :
V_135 -> V_170 . type = V_238 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_239 :
V_135 -> V_170 . type = V_240 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_241 :
V_135 -> V_170 . type = V_242 ;
switch ( V_122 -> V_171 . V_197 ) {
case V_198 :
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_243 :
V_135 -> V_170 . V_184 =
V_244 ;
break;
case V_245 :
V_135 -> V_170 . V_184 =
V_246 ;
break;
case V_247 :
V_135 -> V_170 . V_184 =
V_248 ;
break;
default:
V_135 -> V_170 . V_184 = V_185 ;
break;
}
break;
default:
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
}
break;
case V_249 :
V_135 -> V_170 . V_180 = V_250 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_251 :
V_135 -> V_170 . V_180 = V_181 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
case V_252 :
V_135 -> V_170 . V_180 = V_253 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
default:
V_135 -> V_170 . V_180 = V_182 ;
V_135 -> V_170 . type = V_183 ;
V_135 -> V_170 . V_184 = V_185 ;
break;
}
V_135 -> V_170 . V_168 = V_168 ;
V_135 -> V_170 . V_169 = V_169 ;
V_135 -> V_170 . V_162 = F_5 ( & V_122 -> V_171 . V_162 ) ;
V_135 -> V_170 . V_254 = F_5 ( & V_122 -> V_171 . V_254 ) ;
V_135 -> V_170 . V_255 = F_5 ( & V_122 -> V_171 . V_256 . V_255 ) ;
V_135 -> V_170 . V_257 = F_5 ( & V_122 -> V_171 . V_256 . V_257 ) ;
V_135 -> V_170 . V_258 = F_29 ( & V_122 -> V_171 . V_256 . V_258 ) ;
}
static void
F_23 ( T_1 * V_1 , union V_148 * V_135 ,
struct V_123 * V_124 V_259 )
{
switch ( V_1 -> V_37 ) {
case V_13 :
V_135 -> V_149 . V_150 = - 1 ;
break;
}
}
static int
F_30 ( const T_7 * V_260 , int V_141 )
{
int V_261 ;
if ( V_141 <= 0 ) {
return V_105 ;
}
if ( V_260 [ 0 ] == 0xFF ) {
return V_105 ;
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
return V_98 ;
}
if ( V_260 [ V_261 ] == 0x03 )
return V_42 ;
}
return V_98 ;
}
static int
F_26 ( int V_264 , T_10 * V_48 , int V_141 ,
union V_148 * V_135 )
{
const T_7 * V_260 ;
V_260 = F_25 ( V_48 ) ;
switch ( V_264 ) {
case V_16 :
V_264 = F_30 ( V_260 , V_141 ) ;
switch ( V_264 ) {
case V_262 :
case V_263 :
case V_105 :
if ( V_135 -> V_155 . V_156 == 0 )
V_135 -> V_151 . V_152 = TRUE ;
else
V_135 -> V_151 . V_152 = FALSE ;
break;
case V_41 :
if ( V_135 -> V_155 . V_156 == 0x00 )
V_135 -> V_158 . V_159 = FALSE ;
else
V_135 -> V_158 . V_159 = TRUE ;
V_135 -> V_158 . V_162 = 0 ;
break;
}
break;
case V_18 :
if ( V_135 -> V_170 . type == V_224 && V_141 >= 2 ) {
if ( V_260 [ 0 ] == 0xff && V_260 [ 1 ] == 0x00 ) {
V_135 -> V_170 . V_184 =
V_226 ;
} else {
if ( V_135 -> V_170 . V_184 ==
V_226 ) {
V_135 -> V_170 . V_184 =
V_228 ;
}
}
}
break;
}
return V_264 ;
}
static void
V_61 ( T_1 * V_1 )
{
T_5 * V_21 ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
if ( V_21 -> V_47 . V_48 != NULL ) {
F_31 ( V_21 -> V_47 . V_48 ) ;
V_21 -> V_47 . V_48 = NULL ;
}
}
static void
F_32 ( T_13 V_265 , T_13 T_14 V_259 )
{
F_31 ( V_265 ) ;
}
static void
V_63 ( T_1 * V_1 )
{
T_5 * V_21 ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
if ( V_21 -> rand . V_48 != NULL )
F_31 ( V_21 -> rand . V_48 ) ;
if ( V_21 -> V_53 != NULL ) {
F_33 ( V_21 -> V_53 , F_32 , NULL ) ;
F_34 ( V_21 -> V_53 ) ;
}
}
int
F_35 ( int V_264 )
{
if ( V_264 == V_16 )
return V_266 ;
if ( V_264 < 0 || ( unsigned ) V_264 >= V_267 || V_268 [ V_264 ] == - 1 )
return V_29 ;
return 0 ;
}
T_8
F_36 ( T_15 * V_269 , int * V_2 )
{
T_16 * V_21 ;
char V_48 [ 6 ] = { V_26 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 } ;
V_269 -> V_270 = V_271 ;
V_269 -> V_62 = V_272 ;
V_21 = ( T_16 * ) F_10 ( sizeof( T_16 ) ) ;
V_269 -> V_45 = ( void * ) V_21 ;
V_21 -> V_273 = TRUE ;
V_21 -> V_82 = 0 ;
if ( ! F_37 ( V_269 , F_2 , sizeof F_2 ,
V_2 ) )
return FALSE ;
if ( ! F_37 ( V_269 , V_48 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_271 ( T_15 * V_269 , const struct V_116 * V_109 ,
const T_7 * V_260 , int * V_2 )
{
const union V_148 * V_135 = & V_109 -> V_135 ;
T_16 * V_21 = ( T_16 * ) V_269 -> V_45 ;
struct V_119 V_274 ;
char V_48 [ 6 ] ;
V_146 V_132 ;
T_11 V_131 ;
T_3 V_275 , V_276 ;
T_7 V_277 ;
struct V_7 V_8 ;
T_6 V_9 , V_46 ;
T_3 V_10 ;
struct V_19 * V_19 ;
if ( V_109 -> V_136 != V_137 ) {
* V_2 = V_278 ;
return FALSE ;
}
if ( V_109 -> V_142 > 65535 ) {
* V_2 = V_279 ;
return FALSE ;
}
if ( V_21 -> V_273 ) {
V_21 -> V_273 = FALSE ;
V_19 = localtime ( & V_109 -> V_144 . V_145 ) ;
if ( V_19 != NULL && V_19 -> V_67 >= V_70 ) {
V_10 = ( V_19 -> V_67 - V_70 ) << V_69 ;
V_10 |= ( V_19 -> V_71 - V_74 ) << V_73 ;
V_10 |= V_19 -> V_75 << V_77 ;
V_21 -> V_82 = V_109 -> V_144 . V_145 - ( 3600 * V_19 -> V_78 + 60 * V_19 -> V_79 + V_19 -> V_80 ) ;
} else {
V_10 = 0 ;
V_21 -> V_82 = 0 ;
}
V_9 = 4 ;
V_46 = 0 ;
V_8 . V_9 = F_38 ( V_9 ) ;
V_8 . V_46 = F_38 ( V_46 ) ;
V_8 . time = 0 ;
V_8 . V_66 = F_38 ( V_10 ) ;
V_8 . type = 4 ;
V_8 . V_28 = V_268 [ V_269 -> V_264 ] ;
V_8 . V_33 = 1 ;
V_8 . V_30 = 1 ;
V_8 . V_280 = 0 ;
V_8 . V_281 = 0 ;
V_8 . V_40 [ 0 ] = 0 ;
V_8 . V_40 [ 1 ] = 0 ;
if ( ! F_37 ( V_269 , & V_8 , sizeof V_8 , V_2 ) )
return FALSE ;
}
V_48 [ 0 ] = V_111 ;
V_48 [ 1 ] = 0x00 ;
V_48 [ 2 ] = ( char ) ( ( V_109 -> V_142 + sizeof( struct V_119 ) ) % 256 ) ;
V_48 [ 3 ] = ( char ) ( ( V_109 -> V_142 + sizeof( struct V_119 ) ) / 256 ) ;
V_48 [ 4 ] = 0x00 ;
V_48 [ 5 ] = 0x00 ;
if ( ! F_37 ( V_269 , V_48 , 6 , V_2 ) )
return FALSE ;
V_132 = V_109 -> V_144 . V_145 - V_21 -> V_82 ;
V_274 . V_130 = ( T_7 ) ( V_132 / 86400 ) ;
V_132 -= V_274 . V_130 * 86400 ;
V_131 = V_132 * F_27 ( 1000000000000 ) +
V_109 -> V_144 . V_147 * F_27 ( 1000 ) ;
V_131 /= V_65 [ 1 ] ;
V_275 = ( T_3 ) ( ( V_131 >> 0 ) & 0xFFFF ) ;
V_276 = ( T_3 ) ( ( V_131 >> 16 ) & 0xFFFF ) ;
V_277 = ( T_7 ) ( ( V_131 >> 32 ) & 0xFF ) ;
V_274 . V_125 = F_38 ( V_275 ) ;
V_274 . V_126 = F_38 ( V_276 ) ;
V_274 . V_129 = V_277 ;
V_274 . V_128 = F_38 ( V_109 -> V_142 ) ;
switch ( V_269 -> V_264 ) {
case V_98 :
case V_42 :
V_274 . V_153 = ( V_135 -> V_155 . V_156 & V_157 ) ? 0x00 : V_154 ;
break;
case V_105 :
case V_100 :
V_274 . V_153 = V_135 -> V_151 . V_152 ? 0x00 : V_154 ;
break;
case V_41 :
V_274 . V_153 = V_135 -> V_158 . V_159 ? V_154 : 0x00 ;
switch ( V_135 -> V_158 . V_162 ) {
case 0 :
V_274 . V_153 |= V_161 ;
break;
case 1 :
V_274 . V_153 |= V_163 ;
break;
case 2 :
V_274 . V_153 |= V_164 ;
break;
}
break;
default:
V_274 . V_153 = 0 ;
break;
}
V_274 . V_156 = 0 ;
V_274 . V_127 = V_109 -> V_141 != V_109 -> V_142 ? F_38 ( V_109 -> V_141 ) : 0 ;
V_274 . V_40 = 0 ;
if ( ! F_37 ( V_269 , & V_274 , sizeof V_274 , V_2 ) )
return FALSE ;
if ( ! F_37 ( V_269 , V_260 , V_109 -> V_142 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_272 ( T_15 * V_269 , int * V_2 )
{
char V_48 [ 6 ] = { V_114 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( ! F_37 ( V_269 , V_48 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_39 ( unsigned char * V_282 , T_17 V_283 , unsigned char * V_284 ,
T_17 V_285 , int * V_2 )
{
unsigned char * V_286 = V_282 ;
unsigned char * V_287 = V_284 ;
unsigned char * V_288 = V_286 + V_283 ;
unsigned char * V_289 = V_287 + V_285 ;
unsigned int V_290 ;
unsigned int V_291 = 0 ;
unsigned int V_292 ;
unsigned int V_293 ;
int V_85 ;
int V_294 ;
if ( V_283 > V_295 ) {
return ( - 1 ) ;
}
V_290 = 0 ;
while ( V_286 < V_288 )
{
V_290 = V_290 >> 1 ;
if ( 0 == V_290 )
{
F_40 ( 3 ) ;
V_290 = 0x8000 ;
V_291 = F_5 ( V_286 ) ;
V_286 += 2 ;
}
if ( ! ( V_290 & V_291 ) )
{
F_41 ( 1 ) ;
* ( V_287 ++ ) = * ( V_286 ++ ) ;
}
else
{
V_292 = ( unsigned int ) ( ( * V_286 ) >> 4 ) & 0xF ;
V_293 = ( unsigned int ) ( ( * V_286 ) & 0xF ) ;
V_286 ++ ;
switch ( V_292 )
{
case 0 :
V_85 = V_293 + 3 ;
F_42 ( V_85 ) ;
break;
case 1 :
F_40 ( 1 ) ;
V_85 = V_293 + ( ( unsigned int ) ( * V_286 ++ ) << 4 ) + 19 ;
F_42 ( V_85 ) ;
break;
case 2 :
V_296 ;
F_40 ( 1 ) ;
V_85 = ( unsigned int ) ( * V_286 ++ ) + 16 ;
F_43 ( V_294 , V_85 ) ;
break;
default :
V_296 ;
V_85 = V_292 ;
F_43 ( V_294 , V_85 ) ;
break;
}
}
}
return ( int ) ( V_287 - V_284 ) ;
}
static T_4
F_20 ( void * V_87 , unsigned int V_49 , T_1 * V_1 , T_8 V_117 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_21 ;
T_18 V_297 ;
T_19 * V_298 ;
unsigned int V_299 = V_49 ;
T_4 V_300 = 0 ;
unsigned char * V_301 = ( unsigned char * ) V_87 ;
T_20 * V_302 ;
unsigned int V_303 ;
unsigned int V_304 ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
if ( V_117 ) {
V_297 = V_1 -> V_43 ;
V_298 = & V_21 -> rand ;
} else {
V_297 = V_1 -> V_24 ;
V_298 = & V_21 -> V_47 ;
}
if ( V_1 -> V_34 == V_36 ) {
V_22 = V_23 ;
V_300 = F_44 ( V_87 , V_299 , V_297 ) ;
if ( ( unsigned int ) V_300 != V_299 )
* V_2 = F_45 ( V_297 , V_3 ) ;
if ( V_300 != - 1 ) {
V_298 -> V_51 += V_300 ;
V_298 -> V_52 += V_300 ;
}
return V_300 ;
}
if ( V_298 -> V_48 == NULL ) {
V_298 -> V_48 = ( unsigned char * ) F_10 ( V_305 ) ;
if ( V_117 ) {
V_21 -> V_55 = V_21 -> V_53 ;
} else {
if ( V_1 -> V_43 != NULL ) {
F_46 ( V_21 -> V_53 == NULL ) ;
V_302 = F_47 ( T_20 , 1 ) ;
V_302 -> V_306 = V_298 -> V_52 ;
V_302 -> V_307 = V_298 -> V_51 ;
V_21 -> V_53 = F_48 ( V_21 -> V_53 ,
V_302 ) ;
V_21 -> V_54 = V_21 -> V_53 ;
}
}
if ( F_49 ( V_297 , V_298 , V_2 , V_3 ) < 0 )
return - 1 ;
}
while ( V_299 > 0 ) {
V_304 = V_298 -> V_49 - V_298 -> V_50 ;
if ( V_304 == 0 ) {
if ( V_117 ) {
V_21 -> V_55 = F_50 ( V_21 -> V_55 ) ;
if ( ! V_21 -> V_55 ) {
* V_2 = V_308 ;
return - 1 ;
}
} else {
if ( V_1 -> V_43 != NULL ) {
V_302 = F_47 ( T_20 , 1 ) ;
V_302 -> V_306 = V_298 -> V_52 ;
V_302 -> V_307 = V_298 -> V_51 ;
V_21 -> V_54 = F_48 ( V_21 -> V_54 ,
V_302 ) ;
}
}
if ( F_49 ( V_297 , V_298 , V_2 , V_3 ) < 0 )
return - 1 ;
V_304 = V_298 -> V_49 - V_298 -> V_50 ;
}
V_303 = V_299 ;
if ( V_303 > V_304 )
V_303 = V_304 ;
memcpy ( V_301 , & V_298 -> V_48 [ V_298 -> V_50 ] ,
V_303 ) ;
V_299 -= V_303 ;
V_300 += V_303 ;
V_301 += V_303 ;
V_298 -> V_50 += V_303 ;
V_298 -> V_51 += V_303 ;
}
return V_300 ;
}
static int
F_49 ( T_18 V_297 , T_19 * V_298 , int * V_2 ,
T_2 * * V_3 )
{
int V_309 ;
T_17 V_310 ;
unsigned short V_311 ;
T_6 V_312 ;
T_8 V_313 ;
unsigned char * V_314 ;
int V_315 ;
V_22 = V_23 ;
V_310 = F_44 ( & V_311 , 2 , V_297 ) ;
if ( 2 != V_310 ) {
* V_2 = F_45 ( V_297 , V_3 ) ;
return - 1 ;
}
V_298 -> V_52 += 2 ;
V_312 = F_5 ( & V_311 ) ;
if ( V_312 < 0 ) {
V_309 = - V_312 ;
V_313 = TRUE ;
} else {
V_309 = V_312 ;
V_313 = FALSE ;
}
V_314 = ( unsigned char * ) F_10 ( V_316 ) ;
V_22 = V_23 ;
V_310 = F_44 ( V_314 , V_309 , V_297 ) ;
if ( ( T_17 ) V_309 != V_310 ) {
* V_2 = F_45 ( V_297 , V_3 ) ;
F_31 ( V_314 ) ;
return - 1 ;
}
V_298 -> V_52 += V_309 ;
if ( V_313 ) {
memcpy ( V_298 -> V_48 , V_314 , V_309 ) ;
V_315 = V_309 ;
} else {
V_315 = F_39 ( V_314 , V_309 ,
V_298 -> V_48 , V_305 , V_2 ) ;
if ( V_315 < 0 ) {
F_31 ( V_314 ) ;
return - 1 ;
}
}
F_31 ( V_314 ) ;
V_298 -> V_50 = 0 ;
V_298 -> V_49 = V_315 ;
return 0 ;
}
static T_8
F_17 ( T_1 * V_1 , T_4 V_317 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_21 ;
char * V_48 ;
unsigned int V_318 ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
if ( V_1 -> V_34 == V_36 ) {
V_21 -> V_47 . V_51 += V_317 ;
return F_51 ( V_1 -> V_24 , V_317 , V_2 ) ;
}
F_46 ( V_317 >= 0 ) ;
V_48 = ( char * ) F_10 ( V_316 ) ;
while ( V_317 != 0 ) {
if ( V_317 > V_316 )
V_318 = V_316 ;
else
V_318 = ( unsigned int ) V_317 ;
if ( F_20 ( V_48 , V_318 , V_1 , FALSE , V_2 , V_3 ) < 0 ) {
F_31 ( V_48 ) ;
return FALSE ;
}
V_317 -= V_318 ;
}
F_31 ( V_48 ) ;
return TRUE ;
}
static T_8
F_18 ( T_1 * V_1 , T_4 V_294 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_21 ;
T_4 V_317 ;
T_21 * V_319 , * V_320 ;
T_20 * V_321 , * V_322 ;
V_21 = ( T_5 * ) V_1 -> V_45 ;
if ( V_1 -> V_34 == V_36 ) {
if ( F_9 ( V_1 -> V_43 , V_294 , V_44 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
V_317 = V_294 - V_21 -> rand . V_51 ;
V_319 = NULL ;
if ( V_317 > 0 ) {
if ( ( T_17 ) ( V_21 -> rand . V_50 + V_317 ) >= V_21 -> rand . V_49 ) {
if ( V_21 -> V_55 == NULL ) {
V_319 = V_21 -> V_53 ;
} else {
V_319 = F_50 ( V_21 -> V_55 ) ;
}
while ( V_319 ) {
V_320 = F_50 ( V_319 ) ;
if ( V_320 == NULL ) {
break;
}
V_321 = ( T_20 * ) V_320 -> V_265 ;
if ( V_321 -> V_307 > V_294 )
break;
V_319 = V_320 ;
}
if ( V_319 == NULL ) {
* V_2 = V_308 ;
return FALSE ;
}
}
} else if ( V_317 < 0 ) {
if ( V_21 -> rand . V_50 + V_317 < 0 ) {
if ( V_21 -> V_55 == NULL ) {
V_319 = V_21 -> V_54 ;
} else {
V_319 = F_52 ( V_21 -> V_55 ) ;
}
while ( V_319 ) {
V_322 = ( T_20 * ) V_319 -> V_265 ;
if ( V_322 -> V_307 <= V_294 )
break;
V_319 = F_52 ( V_319 ) ;
}
if ( V_319 == NULL ) {
* V_2 = V_308 ;
return FALSE ;
}
}
}
if ( V_319 != NULL ) {
V_322 = ( T_20 * ) V_319 -> V_265 ;
if ( F_9 ( V_1 -> V_43 , V_322 -> V_306 , V_44 , V_2 ) == - 1 )
return FALSE ;
if ( V_21 -> rand . V_48 == NULL ) {
V_21 -> rand . V_48 = ( unsigned char * ) F_10 ( V_305 ) ;
}
V_21 -> V_55 = V_319 ;
V_21 -> rand . V_51 = V_322 -> V_307 ;
V_21 -> rand . V_52 = V_322 -> V_306 ;
if ( F_49 ( V_1 -> V_43 , & V_21 -> rand , V_2 , V_3 ) < 0 )
return FALSE ;
V_317 = V_294 - V_21 -> rand . V_51 ;
F_46 ( V_317 >= 0 && ( unsigned long ) V_317 < V_21 -> rand . V_49 ) ;
}
V_21 -> rand . V_50 += ( int ) V_317 ;
V_21 -> rand . V_51 += V_317 ;
return TRUE ;
}
