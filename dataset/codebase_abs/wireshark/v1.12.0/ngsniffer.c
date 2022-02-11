int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ sizeof F_2 ] ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
T_3 type ;
struct V_8 V_9 ;
T_3 V_10 ;
T_3 V_11 ;
#if 0
guint16 start_time;
#endif
static const int V_12 [] = {
V_13 ,
V_14 ,
V_15 ,
V_16 ,
V_16 ,
V_16 ,
V_16 ,
V_17 ,
V_17 ,
V_18 ,
V_19
} ;
#define F_3 (sizeof sniffer_encap / sizeof sniffer_encap[0])
struct V_20 V_20 ;
T_4 V_21 ;
T_5 * V_22 ;
V_23 = V_24 ;
V_4 = F_4 ( V_5 , sizeof V_5 , V_1 -> V_25 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_26 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , F_2 , sizeof F_2 ) ) {
return 0 ;
}
V_23 = V_24 ;
V_4 = F_4 ( V_6 , 2 , V_1 -> V_25 ) ;
if ( V_4 != 2 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
V_4 = F_4 ( V_7 , 4 , V_1 -> V_25 ) ;
if ( V_4 != 4 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
type = F_6 ( V_6 ) ;
if ( type != V_27 ) {
* V_2 = V_28 ;
* V_3 = F_7 ( L_1 ) ;
return - 1 ;
}
V_23 = V_24 ;
V_4 = F_4 ( & V_9 , sizeof V_9 , V_1 -> V_25 ) ;
if ( V_4 != sizeof V_9 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
if ( V_9 . V_29 >= F_3
|| V_12 [ V_9 . V_29 ] == V_16 ) {
* V_2 = V_30 ;
* V_3 = F_7 ( L_2 ,
V_9 . V_29 ) ;
return - 1 ;
}
if ( V_9 . V_31 >= V_32 ) {
* V_2 = V_33 ;
* V_3 = F_7 ( L_3 , V_9 . V_31 ) ;
return - 1 ;
}
if ( V_9 . V_34 != 1 ) {
V_1 -> V_35 = V_36 ;
} else {
V_1 -> V_35 = V_37 ;
}
V_1 -> V_38 = V_12 [ V_9 . V_29 ] ;
V_10 = F_6 ( & V_9 . V_10 ) ;
if ( F_8 ( V_1 , V_2 , V_3 , V_10 ,
V_9 . V_29 ) < 0 )
return - 1 ;
if ( ( V_9 . V_29 == V_39 ||
V_9 . V_29 == V_40 ) &&
V_1 -> V_38 == V_17 ) {
switch ( V_10 ) {
case 1 :
switch ( F_6 ( & V_9 . V_41 [ 0 ] ) ) {
case 1 :
case 2 :
V_1 -> V_38 = V_42 ;
break;
}
break;
case 3 :
V_1 -> V_38 = V_43 ;
break;
}
}
V_21 = F_9 ( V_1 -> V_25 ) ;
if ( V_1 -> V_44 != NULL ) {
if ( F_10 ( V_1 -> V_44 , V_21 , V_45 , V_2 ) == - 1 )
return - 1 ;
}
V_22 = ( T_5 * ) F_11 ( sizeof( T_5 ) ) ;
V_1 -> V_46 = ( void * ) V_22 ;
V_22 -> V_10 = V_10 ;
V_22 -> V_47 = F_6 ( & V_9 . V_47 ) ;
V_22 -> V_48 . V_49 = NULL ;
V_22 -> V_48 . V_50 = 0 ;
V_22 -> V_48 . V_51 = 0 ;
V_22 -> rand . V_49 = NULL ;
V_22 -> rand . V_50 = 0 ;
V_22 -> rand . V_51 = 0 ;
V_22 -> V_48 . V_52 = V_21 ;
V_22 -> V_48 . V_53 = V_21 ;
V_22 -> rand . V_52 = V_21 ;
V_22 -> rand . V_53 = V_21 ;
V_22 -> V_54 = NULL ;
V_22 -> V_55 = NULL ;
V_22 -> V_56 = NULL ;
V_1 -> V_57 = V_58 ;
V_1 -> V_59 = V_60 ;
V_1 -> V_61 = V_62 ;
V_1 -> V_63 = V_64 ;
V_1 -> V_65 = 0 ;
V_22 -> V_31 = V_66 [ V_9 . V_31 ] ;
V_22 -> V_29 = V_9 . V_29 ;
V_11 = F_6 ( & V_9 . V_67 ) ;
V_20 . V_68 = ( ( V_11 & V_69 ) >> V_70 ) + V_71 ;
V_20 . V_72 = ( ( V_11 & V_73 ) >> V_74 ) + V_75 ;
V_20 . V_76 = ( ( V_11 & V_77 ) >> V_78 ) ;
#if 0
start_time = pletoh16(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
V_20 . V_79 = 0 ;
V_20 . V_80 = 0 ;
V_20 . V_81 = 0 ;
V_20 . V_82 = - 1 ;
V_22 -> V_83 = mktime ( & V_20 ) ;
V_1 -> V_84 = V_85 ;
return 1 ;
}
static int
F_8 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 V_10 ,
T_7 V_29 )
{
int V_4 ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
T_3 type , V_86 ;
int V_87 ;
unsigned char V_88 [ 256 ] ;
for (; ; ) {
V_23 = V_24 ;
V_4 = F_4 ( V_6 , 2 , V_1 -> V_25 ) ;
if ( V_4 != 2 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_26 ;
return - 1 ;
}
return 0 ;
}
type = F_6 ( V_6 ) ;
if ( ( type != V_89 ) && ( type != V_90 )
&& ( type != V_91 ) && ( type != V_92 )
&& ( type != V_93 ) && ( type != V_94 )
&& ( type != V_95 )
&& ( ( type != V_96 ) || ( V_10 > 2 ) ) ) {
if ( F_10 ( V_1 -> V_25 , - 2 , V_97 , V_2 ) == - 1 )
return - 1 ;
return 0 ;
}
V_23 = V_24 ;
V_4 = F_4 ( V_7 , 4 , V_1 -> V_25 ) ;
if ( V_4 != 4 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
V_86 = F_6 ( V_7 ) ;
if ( ( V_29 == V_39 || V_29 == V_40 ) &&
type == V_90 ) {
V_87 = F_12 ( V_86 , ( int ) sizeof V_88 ) ;
V_4 = F_4 ( V_88 , V_87 ,
V_1 -> V_25 ) ;
if ( V_4 != V_87 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_26 ;
return - 1 ;
}
}
switch ( V_10 ) {
case 2 :
if ( F_13 ( V_1 , V_88 ,
V_86 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
case 1 :
case 4 :
case 5 :
if ( F_14 ( V_1 , V_88 ,
V_86 , V_10 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
}
if ( V_86 > sizeof V_88 ) {
if ( F_10 ( V_1 -> V_25 , V_86 - sizeof V_88 ,
V_97 , V_2 ) == - 1 )
return - 1 ;
}
} else {
if ( F_10 ( V_1 -> V_25 , V_86 , V_97 , V_2 ) == - 1 )
return - 1 ;
}
}
}
static int
F_13 ( T_1 * V_1 , unsigned char * V_88 , T_3 V_86 ,
int * V_2 , T_2 * * V_3 )
{
static const char V_98 [] = L_4 ;
if ( V_86 < sizeof V_98 - 1 ) {
* V_2 = V_30 ;
* V_3 = F_7 ( L_5 ) ;
return - 1 ;
}
if ( strncmp ( ( char * ) V_88 , V_98 , sizeof V_98 - 1 ) == 0 ) {
V_1 -> V_38 = V_99 ;
} else {
* V_2 = V_30 ;
* V_3 = F_7 ( L_6 ,
V_86 , V_88 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_14 ( T_1 * V_1 , unsigned char * V_88 , T_3 V_86 ,
T_6 V_10 , int * V_2 , T_2 * * V_3 )
{
if ( V_86 < 5 ) {
* V_2 = V_30 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
switch ( V_88 [ 4 ] ) {
case V_100 :
V_1 -> V_38 = V_101 ;
break;
case V_102 :
V_1 -> V_38 = V_17 ;
break;
case V_103 :
V_1 -> V_38 = V_43 ;
break;
case V_104 :
V_1 -> V_38 = V_17 ;
switch ( V_10 ) {
case 4 :
if ( V_88 [ 1 ] == 0xfa )
V_1 -> V_38 = V_42 ;
break;
case 5 :
if ( V_86 < 7 ) {
* V_2 = V_30 ;
* V_3 = F_15 ( L_8 ) ;
return - 1 ;
}
if ( V_88 [ 6 ] == 0x01 )
V_1 -> V_38 = V_42 ;
break;
}
break;
case V_105 :
V_1 -> V_38 = V_106 ;
break;
default:
* V_2 = V_30 ;
* V_3 = F_7 ( L_9 ,
V_88 [ 4 ] ) ;
return - 1 ;
}
return 0 ;
}
static T_8
V_58 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_4 * V_107 )
{
T_5 * V_22 ;
int V_108 ;
T_9 V_109 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
for (; ; ) {
* V_107 = V_22 -> V_48 . V_52 ;
V_108 = F_16 ( V_1 , FALSE , & V_109 ,
& V_1 -> V_110 , V_1 -> V_111 , V_2 , V_3 ) ;
if ( V_108 < 0 ) {
return FALSE ;
}
switch ( V_108 ) {
case V_112 :
case V_113 :
case V_114 :
if ( V_109 != 0 ) {
if ( ! F_17 ( V_1 , V_109 , V_2 ,
V_3 ) )
return FALSE ;
}
return TRUE ;
case V_115 :
* V_2 = 0 ;
return FALSE ;
default:
if ( V_109 != 0 ) {
if ( ! F_17 ( V_1 , V_109 , V_2 ,
V_3 ) )
return FALSE ;
}
break;
}
}
}
static T_8
V_60 ( T_1 * V_1 , T_4 V_116 ,
struct V_117 * V_110 , T_10 * V_49 , int * V_2 , T_2 * * V_3 )
{
int V_108 ;
if ( ! F_18 ( V_1 , V_116 , V_2 , V_3 ) )
return FALSE ;
V_108 = F_16 ( V_1 , TRUE , NULL , V_110 , V_49 , V_2 , V_3 ) ;
if ( V_108 < 0 ) {
return FALSE ;
}
switch ( V_108 ) {
case V_112 :
case V_113 :
case V_114 :
break;
default:
F_19 () ;
return FALSE ;
}
return TRUE ;
}
static int
F_16 ( T_1 * V_1 , T_8 V_118 , T_9 * V_109 ,
struct V_117 * V_110 , T_10 * V_49 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_4 V_4 ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
T_3 type , V_86 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_123 V_124 ;
T_3 V_125 , V_126 , V_127 , V_128 ;
T_7 V_129 , V_130 ;
T_11 V_131 , V_132 , V_133 ;
V_4 = F_20 ( V_6 , 2 , V_1 , V_118 , V_2 ,
V_3 ) ;
if ( V_4 != 2 ) {
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_26 ;
return - 1 ;
}
return V_115 ;
}
V_4 = F_20 ( V_7 , 4 , V_1 , V_118 , V_2 ,
V_3 ) ;
if ( V_4 != 4 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
type = F_6 ( V_6 ) ;
V_86 = F_6 ( V_7 ) ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
switch ( type ) {
case V_112 :
if ( V_22 -> V_29 == V_134 ) {
* V_2 = V_28 ;
* V_3 = F_15 ( L_10 ) ;
return - 1 ;
}
V_4 = F_20 ( & V_120 , ( unsigned int ) sizeof V_120 ,
V_1 , V_118 , V_2 , V_3 ) ;
if ( V_4 != sizeof V_120 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
V_125 = F_6 ( & V_120 . V_125 ) ;
V_126 = F_6 ( & V_120 . V_126 ) ;
V_129 = V_120 . V_129 ;
V_130 = V_120 . V_130 ;
V_128 = F_6 ( & V_120 . V_128 ) ;
V_127 = F_6 ( & V_120 . V_127 ) ;
V_86 -= sizeof V_120 ;
F_21 ( V_1 , & V_110 -> V_135 , & V_120 ) ;
break;
case V_113 :
if ( V_22 -> V_29 != V_134 ) {
* V_2 = V_28 ;
* V_3 = F_15 ( L_11 ) ;
return - 1 ;
}
V_4 = F_20 ( & V_122 , ( unsigned int ) sizeof V_122 ,
V_1 , V_118 , V_2 , V_3 ) ;
if ( V_4 != sizeof V_122 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
V_125 = F_6 ( & V_122 . V_125 ) ;
V_126 = F_6 ( & V_122 . V_126 ) ;
V_129 = V_122 . V_129 ;
V_130 = V_122 . V_130 ;
V_128 = F_6 ( & V_122 . V_128 ) ;
V_127 = F_6 ( & V_122 . V_127 ) ;
if ( V_22 -> V_10 >= 5 )
V_86 -= sizeof V_122 ;
else {
if ( V_22 -> V_47 >= 95 )
V_86 -= sizeof V_120 ;
else
V_86 -= sizeof V_122 ;
}
F_22 ( & V_110 -> V_135 , & V_122 ) ;
break;
case V_114 :
V_4 = F_20 ( & V_124 , ( unsigned int ) sizeof V_124 ,
V_1 , V_118 , V_2 , V_3 ) ;
if ( V_4 != sizeof V_124 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
V_125 = F_6 ( & V_124 . V_125 ) ;
V_126 = F_6 ( & V_124 . V_126 ) ;
V_129 = V_124 . V_129 ;
V_130 = V_124 . V_130 ;
V_128 = F_6 ( & V_124 . V_128 ) ;
V_127 = F_6 ( & V_124 . V_127 ) ;
V_86 -= sizeof V_124 ;
F_23 ( V_1 , & V_110 -> V_135 , & V_124 ) ;
break;
case V_115 :
* V_2 = 0 ;
return V_115 ;
default:
if ( V_109 != NULL ) {
* V_109 = V_86 ;
}
return type ;
}
if ( V_128 > V_86 ) {
* V_2 = V_28 ;
* V_3 = F_15 ( L_12 ) ;
return - 1 ;
}
if ( V_109 != NULL ) {
* V_109 = V_86 - V_128 ;
}
V_110 -> V_136 = V_137 ;
V_110 -> V_138 = V_127 ? V_139 | V_140 : V_139 ;
V_110 -> V_141 = V_127 ? V_127 : V_128 ;
V_110 -> V_142 = V_128 ;
F_24 ( V_49 , V_128 ) ;
V_4 = F_20 ( F_25 ( V_49 ) , V_128 , V_1 ,
V_118 , V_2 , V_3 ) ;
if ( V_4 != ( T_4 ) V_128 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
V_110 -> V_143 = F_26 ( V_1 -> V_38 ,
V_49 , V_86 , & V_110 -> V_135 ) ;
V_131 = ( ( ( T_11 ) V_129 ) << 32 ) | ( ( ( T_11 ) V_126 ) << 16 ) | V_125 ;
V_131 *= V_22 -> V_31 ;
V_132 = V_131 / F_27 ( 1000000000000 ) ;
V_133 = V_131 - V_132 * F_27 ( 1000000000000 ) ;
V_132 += V_130 * 86400 ;
V_132 += V_22 -> V_83 ;
V_110 -> V_144 . V_145 = ( V_146 ) V_132 ;
V_110 -> V_144 . V_147 = ( int ) ( V_133 / 1000 ) ;
return type ;
}
static void
F_21 ( T_1 * V_1 , union V_148 * V_135 ,
struct V_119 * V_120 )
{
switch ( V_1 -> V_38 ) {
case V_14 :
V_135 -> V_149 . V_150 = 0 ;
break;
case V_106 :
case V_101 :
V_135 -> V_151 . V_152 = ( V_120 -> V_153 & V_154 ) ? TRUE : FALSE ;
break;
case V_99 :
case V_43 :
case V_17 :
V_135 -> V_155 . V_156 = ( V_120 -> V_153 & V_154 ) ? 0x00 : V_157 ;
break;
case V_42 :
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
V_168 = F_6 ( & V_122 -> V_171 . V_177 ) ;
V_169 = F_6 ( & V_122 -> V_171 . V_178 ) ;
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
V_135 -> V_170 . V_162 = F_6 ( & V_122 -> V_171 . V_162 ) ;
V_135 -> V_170 . V_254 = F_6 ( & V_122 -> V_171 . V_254 ) ;
V_135 -> V_170 . V_255 = F_6 ( & V_122 -> V_171 . V_256 . V_255 ) ;
V_135 -> V_170 . V_257 = F_6 ( & V_122 -> V_171 . V_256 . V_257 ) ;
V_135 -> V_170 . V_258 = F_29 ( & V_122 -> V_171 . V_256 . V_258 ) ;
}
static void
F_23 ( T_1 * V_1 , union V_148 * V_135 ,
struct V_123 * V_124 V_259 )
{
switch ( V_1 -> V_38 ) {
case V_14 :
V_135 -> V_149 . V_150 = - 1 ;
break;
}
}
static int
F_30 ( const T_7 * V_260 , int V_141 )
{
int V_261 ;
if ( V_141 <= 0 ) {
return V_106 ;
}
if ( V_260 [ 0 ] == 0xFF ) {
return V_106 ;
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
return V_99 ;
}
if ( V_260 [ V_261 ] == 0x03 )
return V_43 ;
}
return V_99 ;
}
static int
F_26 ( int V_264 , T_10 * V_49 , int V_141 ,
union V_148 * V_135 )
{
const T_7 * V_260 ;
V_260 = F_25 ( V_49 ) ;
switch ( V_264 ) {
case V_17 :
V_264 = F_30 ( V_260 , V_141 ) ;
switch ( V_264 ) {
case V_262 :
case V_263 :
case V_106 :
if ( V_135 -> V_155 . V_156 == 0 )
V_135 -> V_151 . V_152 = TRUE ;
else
V_135 -> V_151 . V_152 = FALSE ;
break;
case V_42 :
if ( V_135 -> V_155 . V_156 == 0x00 )
V_135 -> V_158 . V_159 = FALSE ;
else
V_135 -> V_158 . V_159 = TRUE ;
V_135 -> V_158 . V_162 = 0 ;
break;
}
break;
case V_19 :
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
V_62 ( T_1 * V_1 )
{
T_5 * V_22 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_22 -> V_48 . V_49 != NULL ) {
F_31 ( V_22 -> V_48 . V_49 ) ;
V_22 -> V_48 . V_49 = NULL ;
}
}
static void
F_32 ( T_13 V_265 , T_13 T_14 V_259 )
{
F_31 ( V_265 ) ;
}
static void
V_64 ( T_1 * V_1 )
{
T_5 * V_22 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_22 -> rand . V_49 != NULL )
F_31 ( V_22 -> rand . V_49 ) ;
if ( V_22 -> V_54 != NULL ) {
F_33 ( V_22 -> V_54 , F_32 , NULL ) ;
F_34 ( V_22 -> V_54 ) ;
}
}
int
F_35 ( int V_264 )
{
if ( V_264 == V_17 )
return V_266 ;
if ( V_264 < 0 || ( unsigned ) V_264 >= V_267 || V_268 [ V_264 ] == - 1 )
return V_30 ;
return 0 ;
}
T_8
F_36 ( T_15 * V_269 , int * V_2 )
{
T_16 * V_22 ;
char V_49 [ 6 ] = { V_27 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 } ;
V_269 -> V_270 = V_271 ;
V_269 -> V_63 = V_272 ;
V_22 = ( T_16 * ) F_11 ( sizeof( T_16 ) ) ;
V_269 -> V_46 = ( void * ) V_22 ;
V_22 -> V_273 = TRUE ;
V_22 -> V_83 = 0 ;
if ( ! F_37 ( V_269 , F_2 , sizeof F_2 ,
V_2 ) )
return FALSE ;
if ( ! F_37 ( V_269 , V_49 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_271 ( T_15 * V_269 , const struct V_117 * V_110 ,
const T_7 * V_260 , int * V_2 )
{
const union V_148 * V_135 = & V_110 -> V_135 ;
T_16 * V_22 = ( T_16 * ) V_269 -> V_46 ;
struct V_119 V_274 ;
char V_49 [ 6 ] ;
V_146 V_132 ;
T_11 V_131 ;
T_3 V_275 , V_276 ;
T_7 V_277 ;
struct V_8 V_9 ;
T_6 V_10 , V_47 ;
T_3 V_11 ;
struct V_20 * V_20 ;
if ( V_110 -> V_136 != V_137 ) {
* V_2 = V_278 ;
return FALSE ;
}
if ( V_110 -> V_142 > 65535 ) {
* V_2 = V_279 ;
return FALSE ;
}
if ( V_22 -> V_273 ) {
V_22 -> V_273 = FALSE ;
V_20 = localtime ( & V_110 -> V_144 . V_145 ) ;
if ( V_20 != NULL && V_20 -> V_68 >= V_71 ) {
V_11 = ( V_20 -> V_68 - V_71 ) << V_70 ;
V_11 |= ( V_20 -> V_72 - V_75 ) << V_74 ;
V_11 |= V_20 -> V_76 << V_78 ;
V_22 -> V_83 = V_110 -> V_144 . V_145 - ( 3600 * V_20 -> V_79 + 60 * V_20 -> V_80 + V_20 -> V_81 ) ;
} else {
V_11 = 0 ;
V_22 -> V_83 = 0 ;
}
V_10 = 4 ;
V_47 = 0 ;
V_9 . V_10 = F_38 ( V_10 ) ;
V_9 . V_47 = F_38 ( V_47 ) ;
V_9 . time = 0 ;
V_9 . V_67 = F_38 ( V_11 ) ;
V_9 . type = 4 ;
V_9 . V_29 = V_268 [ V_269 -> V_264 ] ;
V_9 . V_34 = 1 ;
V_9 . V_31 = 1 ;
V_9 . V_280 = 0 ;
V_9 . V_281 = 0 ;
V_9 . V_41 [ 0 ] = 0 ;
V_9 . V_41 [ 1 ] = 0 ;
if ( ! F_37 ( V_269 , & V_9 , sizeof V_9 , V_2 ) )
return FALSE ;
}
V_49 [ 0 ] = V_112 ;
V_49 [ 1 ] = 0x00 ;
V_49 [ 2 ] = ( char ) ( ( V_110 -> V_142 + sizeof( struct V_119 ) ) % 256 ) ;
V_49 [ 3 ] = ( char ) ( ( V_110 -> V_142 + sizeof( struct V_119 ) ) / 256 ) ;
V_49 [ 4 ] = 0x00 ;
V_49 [ 5 ] = 0x00 ;
if ( ! F_37 ( V_269 , V_49 , 6 , V_2 ) )
return FALSE ;
V_132 = V_110 -> V_144 . V_145 - V_22 -> V_83 ;
V_274 . V_130 = ( T_7 ) ( V_132 / 86400 ) ;
V_132 -= V_274 . V_130 * 86400 ;
V_131 = V_132 * F_27 ( 1000000000000 ) +
V_110 -> V_144 . V_147 * F_27 ( 1000 ) ;
V_131 /= V_66 [ 1 ] ;
V_275 = ( T_3 ) ( ( V_131 >> 0 ) & 0xFFFF ) ;
V_276 = ( T_3 ) ( ( V_131 >> 16 ) & 0xFFFF ) ;
V_277 = ( T_7 ) ( ( V_131 >> 32 ) & 0xFF ) ;
V_274 . V_125 = F_38 ( V_275 ) ;
V_274 . V_126 = F_38 ( V_276 ) ;
V_274 . V_129 = V_277 ;
V_274 . V_128 = F_38 ( V_110 -> V_142 ) ;
switch ( V_269 -> V_264 ) {
case V_99 :
case V_43 :
V_274 . V_153 = ( V_135 -> V_155 . V_156 & V_157 ) ? 0x00 : V_154 ;
break;
case V_106 :
case V_101 :
V_274 . V_153 = V_135 -> V_151 . V_152 ? 0x00 : V_154 ;
break;
case V_42 :
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
V_274 . V_127 = V_110 -> V_141 != V_110 -> V_142 ? F_38 ( V_110 -> V_141 ) : 0 ;
V_274 . V_41 = 0 ;
if ( ! F_37 ( V_269 , & V_274 , sizeof V_274 , V_2 ) )
return FALSE ;
if ( ! F_37 ( V_269 , V_260 , V_110 -> V_142 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_272 ( T_15 * V_269 , int * V_2 )
{
char V_49 [ 6 ] = { V_115 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( ! F_37 ( V_269 , V_49 , 6 , V_2 ) )
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
int V_86 ;
int V_294 ;
if ( V_283 > V_295 ) {
return ( - 1 ) ;
}
V_290 = 0 ;
while ( 1 )
{
V_290 = V_290 >> 1 ;
if ( 0 == V_290 )
{
V_290 = 0x8000 ;
V_291 = F_6 ( V_286 ) ;
V_286 += 2 ;
if ( V_286 >= V_288 )
{
* V_2 = V_296 ;
return ( - 1 ) ;
}
}
if ( ! ( V_290 & V_291 ) )
{
* ( V_287 ++ ) = * ( V_286 ++ ) ;
}
else
{
V_292 = ( unsigned int ) ( ( * V_286 ) >> 4 ) & 0xF ;
V_293 = ( unsigned int ) ( ( * V_286 ) & 0xF ) ;
V_286 ++ ;
if ( V_286 >= V_288 )
{
* V_2 = V_296 ;
return ( - 1 ) ;
}
switch ( V_292 )
{
case 0 :
V_86 = V_293 + 3 ;
if ( V_287 + V_86 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memset ( V_287 , * V_286 ++ , V_86 ) ;
V_287 += V_86 ;
break;
case 1 :
V_86 = V_293 + ( ( unsigned int ) ( * V_286 ++ ) << 4 ) + 19 ;
if ( V_286 >= V_288 )
{
* V_2 = V_296 ;
return ( - 1 ) ;
}
if ( V_287 + V_86 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memset ( V_287 , * V_286 ++ , V_86 ) ;
V_287 += V_86 ;
break;
case 2 :
V_294 = V_293 + ( ( unsigned int ) ( * V_286 ++ ) << 4 ) + 3 ;
if ( V_286 >= V_288 )
{
* V_2 = V_296 ;
return ( - 1 ) ;
}
if ( V_287 - V_294 < V_284 )
{
* V_2 = V_298 ;
return ( - 1 ) ;
}
V_86 = ( unsigned int ) ( * V_286 ++ ) + 16 ;
if ( V_287 + V_86 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memcpy ( V_287 , V_287 - V_294 , V_86 ) ;
V_287 += V_86 ;
break;
default :
V_294 = V_293 + ( ( unsigned int ) ( * V_286 ++ ) << 4 ) + 3 ;
if ( V_287 - V_294 < V_284 )
{
* V_2 = V_298 ;
return ( - 1 ) ;
}
V_86 = V_292 ;
if ( V_287 + V_86 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memcpy ( V_287 , V_287 - V_294 , V_86 ) ;
V_287 += V_86 ;
break;
}
}
if ( V_286 >= V_288 )
break;
}
return ( int ) ( V_287 - V_284 ) ;
}
static T_4
F_20 ( void * V_88 , unsigned int V_50 , T_1 * V_1 , T_8 V_118 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_18 V_299 ;
T_19 * V_300 ;
unsigned int V_301 = V_50 ;
T_4 V_302 = 0 ;
unsigned char * V_303 = ( unsigned char * ) V_88 ;
T_20 * V_304 ;
unsigned int V_305 ;
unsigned int V_306 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_118 ) {
V_299 = V_1 -> V_44 ;
V_300 = & V_22 -> rand ;
} else {
V_299 = V_1 -> V_25 ;
V_300 = & V_22 -> V_48 ;
}
if ( V_1 -> V_35 == V_37 ) {
V_23 = V_24 ;
V_302 = F_4 ( V_88 , V_301 , V_299 ) ;
if ( ( unsigned int ) V_302 != V_301 )
* V_2 = F_5 ( V_299 , V_3 ) ;
if ( V_302 != - 1 ) {
V_300 -> V_52 += V_302 ;
V_300 -> V_53 += V_302 ;
}
return V_302 ;
}
if ( V_300 -> V_49 == NULL ) {
V_300 -> V_49 = ( unsigned char * ) F_11 ( V_307 ) ;
if ( V_118 ) {
V_22 -> V_56 = V_22 -> V_54 ;
} else {
if ( V_1 -> V_44 != NULL ) {
F_40 ( V_22 -> V_54 == NULL ) ;
V_304 = F_41 ( T_20 , 1 ) ;
V_304 -> V_308 = V_300 -> V_53 ;
V_304 -> V_309 = V_300 -> V_52 ;
V_22 -> V_54 = F_42 ( V_22 -> V_54 ,
V_304 ) ;
V_22 -> V_55 = V_22 -> V_54 ;
}
}
if ( F_43 ( V_299 , V_300 , V_2 , V_3 ) < 0 )
return - 1 ;
}
while ( V_301 > 0 ) {
V_306 = V_300 -> V_50 - V_300 -> V_51 ;
if ( V_306 == 0 ) {
if ( V_118 ) {
V_22 -> V_56 = F_44 ( V_22 -> V_56 ) ;
if ( ! V_22 -> V_56 ) {
* V_2 = V_310 ;
return - 1 ;
}
} else {
if ( V_1 -> V_44 != NULL ) {
V_304 = F_41 ( T_20 , 1 ) ;
V_304 -> V_308 = V_300 -> V_53 ;
V_304 -> V_309 = V_300 -> V_52 ;
V_22 -> V_55 = F_42 ( V_22 -> V_55 ,
V_304 ) ;
}
}
if ( F_43 ( V_299 , V_300 , V_2 , V_3 ) < 0 )
return - 1 ;
V_306 = V_300 -> V_50 - V_300 -> V_51 ;
}
V_305 = V_301 ;
if ( V_305 > V_306 )
V_305 = V_306 ;
memcpy ( V_303 , & V_300 -> V_49 [ V_300 -> V_51 ] ,
V_305 ) ;
V_301 -= V_305 ;
V_302 += V_305 ;
V_303 += V_305 ;
V_300 -> V_51 += V_305 ;
V_300 -> V_52 += V_305 ;
}
return V_302 ;
}
static int
F_43 ( T_18 V_299 , T_19 * V_300 , int * V_2 ,
T_2 * * V_3 )
{
int V_311 ;
T_17 V_312 ;
unsigned short V_313 ;
T_6 V_314 ;
T_8 V_315 ;
unsigned char * V_316 ;
int V_317 ;
V_23 = V_24 ;
V_312 = F_4 ( & V_313 , 2 , V_299 ) ;
if ( 2 != V_312 ) {
* V_2 = F_5 ( V_299 , V_3 ) ;
return - 1 ;
}
V_300 -> V_53 += 2 ;
V_314 = F_6 ( & V_313 ) ;
if ( V_314 < 0 ) {
V_311 = - V_314 ;
V_315 = TRUE ;
} else {
V_311 = V_314 ;
V_315 = FALSE ;
}
V_316 = ( unsigned char * ) F_11 ( V_318 ) ;
V_23 = V_24 ;
V_312 = F_4 ( V_316 , V_311 , V_299 ) ;
if ( ( T_17 ) V_311 != V_312 ) {
* V_2 = F_5 ( V_299 , V_3 ) ;
F_31 ( V_316 ) ;
return - 1 ;
}
V_300 -> V_53 += V_311 ;
if ( V_315 ) {
memcpy ( V_300 -> V_49 , V_316 , V_311 ) ;
V_317 = V_311 ;
} else {
V_317 = F_39 ( V_316 , V_311 ,
V_300 -> V_49 , V_307 , V_2 ) ;
if ( V_317 < 0 ) {
F_31 ( V_316 ) ;
return - 1 ;
}
}
F_31 ( V_316 ) ;
V_300 -> V_51 = 0 ;
V_300 -> V_50 = V_317 ;
return 0 ;
}
static T_8
F_17 ( T_1 * V_1 , T_4 V_319 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
char * V_49 ;
unsigned int V_320 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_1 -> V_35 == V_37 ) {
V_22 -> V_48 . V_52 += V_319 ;
return F_45 ( V_1 -> V_25 , V_319 , V_2 ) ;
}
F_40 ( V_319 >= 0 ) ;
V_49 = ( char * ) F_11 ( V_318 ) ;
while ( V_319 != 0 ) {
if ( V_319 > V_318 )
V_320 = V_318 ;
else
V_320 = ( unsigned int ) V_319 ;
if ( F_20 ( V_49 , V_320 , V_1 , FALSE , V_2 , V_3 ) < 0 ) {
F_31 ( V_49 ) ;
return FALSE ;
}
V_319 -= V_320 ;
}
F_31 ( V_49 ) ;
return TRUE ;
}
static T_8
F_18 ( T_1 * V_1 , T_4 V_294 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_4 V_319 ;
T_21 * V_321 , * V_322 ;
T_20 * V_323 , * V_324 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_1 -> V_35 == V_37 ) {
if ( F_10 ( V_1 -> V_44 , V_294 , V_45 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
V_319 = V_294 - V_22 -> rand . V_52 ;
V_321 = NULL ;
if ( V_319 > 0 ) {
if ( ( T_17 ) ( V_22 -> rand . V_51 + V_319 ) >= V_22 -> rand . V_50 ) {
if ( V_22 -> V_56 == NULL ) {
V_321 = V_22 -> V_54 ;
} else {
V_321 = F_44 ( V_22 -> V_56 ) ;
}
while ( V_321 ) {
V_322 = F_44 ( V_321 ) ;
if ( V_322 == NULL ) {
break;
}
V_323 = ( T_20 * ) V_322 -> V_265 ;
if ( V_323 -> V_309 > V_294 )
break;
V_321 = V_322 ;
}
if ( V_321 == NULL ) {
* V_2 = V_310 ;
return FALSE ;
}
}
} else if ( V_319 < 0 ) {
if ( V_22 -> rand . V_51 + V_319 < 0 ) {
if ( V_22 -> V_56 == NULL ) {
V_321 = V_22 -> V_55 ;
} else {
V_321 = F_46 ( V_22 -> V_56 ) ;
}
while ( V_321 ) {
V_324 = ( T_20 * ) V_321 -> V_265 ;
if ( V_324 -> V_309 <= V_294 )
break;
V_321 = F_46 ( V_321 ) ;
}
if ( V_321 == NULL ) {
* V_2 = V_310 ;
return FALSE ;
}
}
}
if ( V_321 != NULL ) {
V_324 = ( T_20 * ) V_321 -> V_265 ;
if ( F_10 ( V_1 -> V_44 , V_324 -> V_308 , V_45 , V_2 ) == - 1 )
return FALSE ;
if ( V_22 -> rand . V_49 == NULL ) {
V_22 -> rand . V_49 = ( unsigned char * ) F_11 ( V_307 ) ;
}
V_22 -> V_56 = V_321 ;
V_22 -> rand . V_52 = V_324 -> V_309 ;
V_22 -> rand . V_53 = V_324 -> V_308 ;
if ( F_43 ( V_1 -> V_44 , & V_22 -> rand , V_2 , V_3 ) < 0 )
return FALSE ;
V_319 = V_294 - V_22 -> rand . V_52 ;
F_40 ( V_319 >= 0 && ( unsigned long ) V_319 < V_22 -> rand . V_50 ) ;
}
V_22 -> rand . V_51 += ( int ) V_319 ;
V_22 -> rand . V_52 += V_319 ;
return TRUE ;
}
