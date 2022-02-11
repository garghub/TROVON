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
V_22 -> rand . V_49 = NULL ;
V_22 -> V_48 . V_50 = V_21 ;
V_22 -> V_48 . V_51 = V_21 ;
V_22 -> rand . V_50 = V_21 ;
V_22 -> rand . V_51 = V_21 ;
V_22 -> V_52 = NULL ;
V_22 -> V_53 = NULL ;
V_22 -> V_54 = NULL ;
V_1 -> V_55 = V_56 ;
V_1 -> V_57 = V_58 ;
V_1 -> V_59 = V_60 ;
V_1 -> V_61 = V_62 ;
V_1 -> V_63 = 0 ;
V_22 -> V_31 = V_64 [ V_9 . V_31 ] ;
V_22 -> V_29 = V_9 . V_29 ;
V_11 = F_6 ( & V_9 . V_65 ) ;
V_20 . V_66 = ( ( V_11 & V_67 ) >> V_68 ) + V_69 ;
V_20 . V_70 = ( ( V_11 & V_71 ) >> V_72 ) + V_73 ;
V_20 . V_74 = ( ( V_11 & V_75 ) >> V_76 ) ;
#if 0
start_time = pletohs(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
V_20 . V_77 = 0 ;
V_20 . V_78 = 0 ;
V_20 . V_79 = 0 ;
V_20 . V_80 = - 1 ;
V_22 -> V_81 = mktime ( & V_20 ) ;
V_1 -> V_82 = V_83 ;
return 1 ;
}
static int
F_8 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 V_10 ,
T_7 V_29 )
{
int V_4 ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
T_3 type , V_84 ;
int V_85 ;
unsigned char V_86 [ 256 ] ;
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
if ( ( type != V_87 ) && ( type != V_88 )
&& ( type != V_89 ) && ( type != V_90 )
&& ( type != V_91 ) && ( type != V_92 )
&& ( type != V_93 )
&& ( ( type != V_94 ) || ( V_10 > 2 ) ) ) {
if ( F_10 ( V_1 -> V_25 , - 2 , V_95 , V_2 ) == - 1 )
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
V_84 = F_6 ( V_7 ) ;
if ( ( V_29 == V_39 || V_29 == V_40 ) &&
type == V_88 ) {
V_85 = F_12 ( V_84 , ( int ) sizeof V_86 ) ;
V_4 = F_4 ( V_86 , V_85 ,
V_1 -> V_25 ) ;
if ( V_4 != V_85 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_26 ;
return - 1 ;
}
}
switch ( V_10 ) {
case 2 :
if ( F_13 ( V_1 , V_86 ,
V_84 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
case 1 :
case 4 :
case 5 :
if ( F_14 ( V_1 , V_86 ,
V_84 , V_10 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
}
if ( V_84 > sizeof V_86 ) {
if ( F_10 ( V_1 -> V_25 , V_84 - sizeof V_86 ,
V_95 , V_2 ) == - 1 )
return - 1 ;
}
} else {
if ( F_10 ( V_1 -> V_25 , V_84 , V_95 , V_2 ) == - 1 )
return - 1 ;
}
}
}
static int
F_13 ( T_1 * V_1 , unsigned char * V_86 , T_3 V_84 ,
int * V_2 , T_2 * * V_3 )
{
static const char V_96 [] = L_4 ;
if ( V_84 < sizeof V_96 - 1 ) {
* V_2 = V_30 ;
* V_3 = F_7 ( L_5 ) ;
return - 1 ;
}
if ( strncmp ( ( char * ) V_86 , V_96 , sizeof V_96 - 1 ) == 0 ) {
V_1 -> V_38 = V_97 ;
} else {
* V_2 = V_30 ;
* V_3 = F_7 ( L_6 ,
V_84 , V_86 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_14 ( T_1 * V_1 , unsigned char * V_86 , T_3 V_84 ,
T_6 V_10 , int * V_2 , T_2 * * V_3 )
{
if ( V_84 < 5 ) {
* V_2 = V_30 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
switch ( V_86 [ 4 ] ) {
case V_98 :
V_1 -> V_38 = V_99 ;
break;
case V_100 :
V_1 -> V_38 = V_17 ;
break;
case V_101 :
V_1 -> V_38 = V_43 ;
break;
case V_102 :
V_1 -> V_38 = V_17 ;
switch ( V_10 ) {
case 4 :
if ( V_86 [ 1 ] == 0xfa )
V_1 -> V_38 = V_42 ;
break;
case 5 :
if ( V_84 < 7 ) {
* V_2 = V_30 ;
* V_3 = F_15 ( L_8 ) ;
return - 1 ;
}
if ( V_86 [ 6 ] == 0x01 )
V_1 -> V_38 = V_42 ;
break;
}
break;
case V_103 :
V_1 -> V_38 = V_104 ;
break;
default:
* V_2 = V_30 ;
* V_3 = F_7 ( L_9 ,
V_86 [ 4 ] ) ;
return - 1 ;
}
return 0 ;
}
static T_8
V_56 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_4 * V_105 )
{
T_5 * V_22 ;
int V_106 ;
T_3 type , V_84 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
struct V_111 V_112 ;
T_3 V_113 , V_114 , V_115 , V_116 ;
T_7 V_117 , V_118 ;
T_9 V_119 , V_120 , V_121 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
for (; ; ) {
* V_105 = V_22 -> V_48 . V_50 ;
V_106 = F_16 ( V_1 , FALSE , & type , & V_84 ,
V_2 , V_3 ) ;
if ( V_106 <= 0 ) {
return FALSE ;
}
switch ( type ) {
case V_122 :
if ( V_22 -> V_29 == V_123 ) {
* V_2 = V_28 ;
* V_3 = F_15 ( L_10 ) ;
return FALSE ;
}
if ( ! F_17 ( V_1 , FALSE , & V_108 , V_2 ,
V_3 ) ) {
return FALSE ;
}
V_113 = F_6 ( & V_108 . V_113 ) ;
V_114 = F_6 ( & V_108 . V_114 ) ;
V_117 = V_108 . V_117 ;
V_118 = V_108 . V_118 ;
V_116 = F_6 ( & V_108 . V_116 ) ;
V_115 = F_6 ( & V_108 . V_115 ) ;
V_84 -= sizeof V_108 ;
F_18 ( V_1 , & V_1 -> V_124 . V_125 ,
& V_108 ) ;
goto V_126;
case V_127 :
if ( V_22 -> V_29 != V_123 ) {
* V_2 = V_28 ;
* V_3 = F_15 ( L_11 ) ;
return FALSE ;
}
if ( ! F_19 ( V_1 , FALSE , & V_110 , V_2 ,
V_3 ) ) {
return FALSE ;
}
V_113 = F_6 ( & V_110 . V_113 ) ;
V_114 = F_6 ( & V_110 . V_114 ) ;
V_117 = V_110 . V_117 ;
V_118 = V_110 . V_118 ;
V_116 = F_6 ( & V_110 . V_116 ) ;
V_115 = F_6 ( & V_110 . V_115 ) ;
if ( V_22 -> V_10 >= 5 )
V_84 -= sizeof V_110 ;
else {
if ( V_22 -> V_47 >= 95 )
V_84 -= sizeof V_108 ;
else
V_84 -= sizeof V_110 ;
}
F_20 ( & V_1 -> V_124 . V_125 , & V_110 ) ;
goto V_126;
case V_128 :
if ( ! F_21 ( V_1 , FALSE , & V_112 , V_2 ,
V_3 ) ) {
return FALSE ;
}
V_113 = F_6 ( & V_112 . V_113 ) ;
V_114 = F_6 ( & V_112 . V_114 ) ;
V_117 = V_112 . V_117 ;
V_118 = V_112 . V_118 ;
V_116 = F_6 ( & V_112 . V_116 ) ;
V_115 = F_6 ( & V_112 . V_115 ) ;
V_84 -= sizeof V_112 ;
F_22 ( V_1 , & V_1 -> V_124 . V_125 ,
& V_112 ) ;
goto V_126;
case V_129 :
* V_2 = 0 ;
return FALSE ;
default:
break;
}
if ( ! F_23 ( V_1 , V_84 , V_2 , V_3 ) )
return FALSE ;
}
V_126:
if ( V_116 > V_84 ) {
* V_2 = V_28 ;
* V_3 = F_15 ( L_12 ) ;
return FALSE ;
}
V_1 -> V_124 . V_130 = V_115 ? V_131 | V_132 : V_131 ;
V_1 -> V_124 . V_133 = V_115 ? V_115 : V_116 ;
V_1 -> V_124 . V_134 = V_116 ;
if ( ! F_24 ( V_1 , FALSE , V_1 -> V_135 , V_84 ,
V_2 , V_3 ) )
return FALSE ;
V_1 -> V_124 . V_136 = F_25 ( V_1 -> V_38 , V_1 -> V_135 , V_84 ,
& V_1 -> V_124 . V_125 ) ;
V_119 = ( ( ( T_9 ) V_117 ) << 32 ) | ( ( ( T_9 ) V_114 ) << 16 ) | V_113 ;
V_119 *= V_22 -> V_31 ;
V_120 = V_119 / F_26 ( 1000000000000U ) ;
V_121 = V_119 - V_120 * F_26 ( 1000000000000U ) ;
V_120 += V_118 * 86400 ;
V_120 += V_22 -> V_81 ;
V_1 -> V_124 . V_137 . V_138 = ( V_139 ) V_120 ;
V_1 -> V_124 . V_137 . V_140 = ( int ) ( V_121 / 1000 ) ;
return TRUE ;
}
static T_8
V_58 ( T_1 * V_1 , T_4 V_141 ,
struct V_142 * V_124 , T_10 * V_49 , int V_143 ,
int * V_2 , T_2 * * V_3 )
{
union V_144 * V_125 = & V_124 -> V_125 ;
int V_106 ;
T_3 type , V_84 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
struct V_111 V_112 ;
if ( ! F_27 ( V_1 , V_141 , V_2 , V_3 ) )
return FALSE ;
V_106 = F_16 ( V_1 , TRUE , & type , & V_84 , V_2 ,
V_3 ) ;
if ( V_106 <= 0 ) {
if ( V_106 == 0 ) {
* V_2 = V_26 ;
}
return FALSE ;
}
switch ( type ) {
case V_122 :
if ( ! F_17 ( V_1 , TRUE , & V_108 , V_2 , V_3 ) ) {
return FALSE ;
}
V_84 -= sizeof V_108 ;
F_18 ( V_1 , V_125 , & V_108 ) ;
break;
case V_127 :
if ( ! F_19 ( V_1 , TRUE , & V_110 , V_2 , V_3 ) ) {
return FALSE ;
}
V_84 -= sizeof V_110 ;
F_20 ( V_125 , & V_110 ) ;
break;
case V_128 :
if ( ! F_21 ( V_1 , TRUE , & V_112 , V_2 , V_3 ) ) {
return FALSE ;
}
V_84 -= sizeof V_112 ;
F_22 ( V_1 , V_125 , & V_112 ) ;
break;
default:
F_28 () ;
return FALSE ;
}
if ( ! F_24 ( V_1 , TRUE , V_49 , V_143 , V_2 , V_3 ) )
return FALSE ;
F_25 ( V_1 -> V_38 , V_49 , V_143 , V_125 ) ;
return TRUE ;
}
static int
F_16 ( T_1 * V_1 , T_8 V_145 , T_3 * V_146 ,
T_3 * V_147 , int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
V_4 = F_29 ( V_6 , 2 , V_1 , V_145 , V_2 ,
V_3 ) ;
if ( V_4 != 2 ) {
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_26 ;
return - 1 ;
}
return 0 ;
}
V_4 = F_29 ( V_7 , 4 , V_1 , V_145 , V_2 ,
V_3 ) ;
if ( V_4 != 4 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return - 1 ;
}
* V_146 = F_6 ( V_6 ) ;
* V_147 = F_6 ( V_7 ) ;
return 1 ;
}
static T_8
F_17 ( T_1 * V_1 , T_8 V_145 , struct V_107 * V_108 ,
int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_29 ( V_108 , ( unsigned int ) sizeof *V_108 , V_1 ,
V_145 , V_2 , V_3 ) ;
if ( V_4 != sizeof *V_108 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return FALSE ;
}
return TRUE ;
}
static void
F_18 ( T_1 * V_1 , union V_144 * V_125 ,
struct V_107 * V_108 )
{
switch ( V_1 -> V_38 ) {
case V_14 :
V_125 -> V_148 . V_149 = 0 ;
break;
case V_104 :
case V_99 :
V_125 -> V_150 . V_151 = ( V_108 -> V_152 & V_153 ) ? TRUE : FALSE ;
break;
case V_97 :
case V_43 :
case V_17 :
V_125 -> V_154 . V_155 = ( V_108 -> V_152 & V_153 ) ? 0x00 : V_156 ;
break;
case V_42 :
V_125 -> V_157 . V_158 = ( V_108 -> V_152 & V_153 ) ? FALSE : TRUE ;
switch ( V_108 -> V_152 & V_159 ) {
case V_160 :
V_125 -> V_157 . V_161 = 0 ;
break;
case V_162 :
V_125 -> V_157 . V_161 = 1 ;
break;
case V_163 :
V_125 -> V_157 . V_161 = 2 ;
break;
default:
V_125 -> V_157 . V_161 = 30 ;
break;
}
}
}
static T_8
F_19 ( T_1 * V_1 , T_8 V_145 , struct V_109 * V_110 ,
int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_29 ( V_110 , ( unsigned int ) sizeof *V_110 , V_1 ,
V_145 , V_2 , V_3 ) ;
if ( V_4 != sizeof *V_110 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return FALSE ;
}
return TRUE ;
}
static void
F_20 ( union V_144 * V_125 ,
struct V_109 * V_110 )
{
T_11 V_164 ;
T_7 V_165 , V_166 ;
T_3 V_167 , V_168 ;
V_125 -> V_169 . V_155 = 0 ;
V_164 = F_30 ( & V_110 -> V_170 . V_164 ) ;
if ( V_164 & V_171 )
V_125 -> V_169 . V_155 |= V_172 ;
V_165 = V_110 -> V_170 . V_173 & V_174 ;
V_166 = V_110 -> V_170 . V_173 & V_175 ;
V_167 = F_6 ( & V_110 -> V_170 . V_176 ) ;
V_168 = F_6 ( & V_110 -> V_170 . V_177 ) ;
switch ( V_165 ) {
case V_178 :
if ( V_167 == 0 && V_168 == 5 )
V_125 -> V_169 . V_179 = V_180 ;
else
V_125 -> V_169 . V_179 = V_181 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_185 :
V_125 -> V_169 . V_179 = V_186 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_187 :
V_125 -> V_169 . V_179 = V_188 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_189 :
V_125 -> V_169 . V_179 = V_190 ;
switch ( V_166 ) {
case V_191 :
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_192 :
V_125 -> V_169 . type = V_193 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_194 :
V_125 -> V_169 . type = V_195 ;
switch ( V_110 -> V_170 . V_196 ) {
case V_197 :
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_198 :
V_125 -> V_169 . V_183 =
V_199 ;
break;
case V_200 :
V_125 -> V_169 . V_183 =
V_201 ;
break;
case V_202 :
V_125 -> V_169 . V_183 =
V_203 ;
break;
case V_204 :
V_125 -> V_169 . V_183 =
V_205 ;
break;
case V_206 :
V_125 -> V_169 . V_183 =
V_207 ;
break;
case V_208 :
V_125 -> V_169 . V_183 = V_209 ;
break;
case V_210 :
V_125 -> V_169 . V_183 = V_211 ;
break;
case V_212 :
V_125 -> V_169 . V_183 = V_213 ;
break;
case V_214 :
V_125 -> V_169 . V_183 = V_215 ;
break;
case V_216 :
V_125 -> V_169 . V_183 = V_217 ;
break;
case V_218 :
V_125 -> V_169 . V_183 =
V_219 ;
break;
case V_220 :
V_125 -> V_169 . V_183 = V_221 ;
break;
default:
V_125 -> V_169 . V_183 = V_184 ;
break;
}
break;
case V_222 :
V_125 -> V_169 . type = V_223 ;
switch ( V_110 -> V_170 . V_196 ) {
case V_197 :
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_224 :
V_125 -> V_169 . V_183 =
V_225 ;
break;
case V_226 :
V_125 -> V_169 . V_183 = V_227 ;
break;
case V_228 :
V_125 -> V_169 . V_183 = V_229 ;
break;
case V_230 :
V_125 -> V_169 . V_183 =
V_231 ;
break;
case V_232 :
V_125 -> V_169 . V_183 =
V_233 ;
break;
default:
V_125 -> V_169 . V_183 = V_184 ;
break;
}
break;
case V_234 :
V_125 -> V_169 . type = V_235 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_236 :
V_125 -> V_169 . type = V_237 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_238 :
V_125 -> V_169 . type = V_239 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_240 :
V_125 -> V_169 . type = V_241 ;
switch ( V_110 -> V_170 . V_196 ) {
case V_197 :
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_242 :
V_125 -> V_169 . V_183 =
V_243 ;
break;
case V_244 :
V_125 -> V_169 . V_183 =
V_245 ;
break;
case V_246 :
V_125 -> V_169 . V_183 =
V_247 ;
break;
default:
V_125 -> V_169 . V_183 = V_184 ;
break;
}
break;
default:
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
}
break;
case V_248 :
V_125 -> V_169 . V_179 = V_249 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_250 :
V_125 -> V_169 . V_179 = V_180 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
case V_251 :
V_125 -> V_169 . V_179 = V_252 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
default:
V_125 -> V_169 . V_179 = V_181 ;
V_125 -> V_169 . type = V_182 ;
V_125 -> V_169 . V_183 = V_184 ;
break;
}
V_125 -> V_169 . V_167 = V_167 ;
V_125 -> V_169 . V_168 = V_168 ;
V_125 -> V_169 . V_161 = F_6 ( & V_110 -> V_170 . V_161 ) ;
V_125 -> V_169 . V_253 = F_6 ( & V_110 -> V_170 . V_253 ) ;
V_125 -> V_169 . V_254 = F_6 ( & V_110 -> V_170 . V_255 . V_254 ) ;
V_125 -> V_169 . V_256 = F_6 ( & V_110 -> V_170 . V_255 . V_256 ) ;
V_125 -> V_169 . V_257 = F_31 ( & V_110 -> V_170 . V_255 . V_257 ) ;
}
static T_8
F_21 ( T_1 * V_1 , T_8 V_145 , struct V_111 * V_112 ,
int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_29 ( V_112 , ( unsigned int ) sizeof *V_112 , V_1 ,
V_145 , V_2 , V_3 ) ;
if ( V_4 != sizeof *V_112 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return FALSE ;
}
return TRUE ;
}
static void
F_22 ( T_1 * V_1 , union V_144 * V_125 ,
struct V_111 * V_112 V_258 )
{
switch ( V_1 -> V_38 ) {
case V_14 :
V_125 -> V_148 . V_149 = - 1 ;
break;
}
}
static T_8
F_24 ( T_1 * V_1 , T_8 V_145 , T_10 * V_49 ,
unsigned int V_84 , int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
F_32 ( V_49 , V_84 ) ;
V_4 = F_29 ( F_33 ( V_49 ) , V_84 , V_1 ,
V_145 , V_2 , V_3 ) ;
if ( V_4 != ( T_4 ) V_84 ) {
if ( * V_2 == 0 )
* V_2 = V_26 ;
return FALSE ;
}
return TRUE ;
}
static int
F_34 ( const T_7 * V_259 , int V_133 )
{
int V_260 ;
if ( V_133 <= 0 ) {
return V_104 ;
}
if ( V_259 [ 0 ] == 0xFF ) {
return V_104 ;
}
if ( V_133 >= 2 ) {
if ( V_259 [ 0 ] == 0x07 && V_259 [ 1 ] == 0x03 ) {
return V_261 ;
} else if ( ( V_259 [ 0 ] == 0x0F && V_259 [ 1 ] == 0x00 ) ||
( V_259 [ 0 ] == 0x8F && V_259 [ 1 ] == 0x00 ) ) {
return V_262 ;
}
for ( V_260 = 0 ; V_260 < V_133 && ( V_259 [ V_260 ] & 0x01 ) == 0 ; V_260 ++ )
;
V_260 ++ ;
if ( V_260 == V_133 ) {
return V_97 ;
}
if ( V_259 [ V_260 ] == 0x03 )
return V_43 ;
}
return V_97 ;
}
static int
F_25 ( int V_263 , T_10 * V_49 , int V_133 ,
union V_144 * V_125 )
{
const T_7 * V_259 ;
V_259 = F_33 ( V_49 ) ;
switch ( V_263 ) {
case V_17 :
V_263 = F_34 ( V_259 , V_133 ) ;
switch ( V_263 ) {
case V_261 :
case V_262 :
case V_104 :
if ( V_125 -> V_154 . V_155 == 0 )
V_125 -> V_150 . V_151 = TRUE ;
else
V_125 -> V_150 . V_151 = FALSE ;
break;
case V_42 :
if ( V_125 -> V_154 . V_155 == 0x00 )
V_125 -> V_157 . V_158 = FALSE ;
else
V_125 -> V_157 . V_158 = TRUE ;
V_125 -> V_157 . V_161 = 0 ;
break;
}
break;
case V_19 :
if ( V_125 -> V_169 . type == V_223 && V_133 >= 2 ) {
if ( V_259 [ 0 ] == 0xff && V_259 [ 1 ] == 0x00 ) {
V_125 -> V_169 . V_183 =
V_225 ;
} else {
if ( V_125 -> V_169 . V_183 ==
V_225 ) {
V_125 -> V_169 . V_183 =
V_227 ;
}
}
}
break;
}
return V_263 ;
}
static void
V_60 ( T_1 * V_1 )
{
T_5 * V_22 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_22 -> V_48 . V_49 != NULL ) {
F_35 ( V_22 -> V_48 . V_49 ) ;
V_22 -> V_48 . V_49 = NULL ;
}
}
static void
F_36 ( T_12 V_264 , T_12 T_13 V_258 )
{
F_35 ( V_264 ) ;
}
static void
V_62 ( T_1 * V_1 )
{
T_5 * V_22 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_22 -> rand . V_49 != NULL )
F_35 ( V_22 -> rand . V_49 ) ;
if ( V_22 -> V_52 != NULL ) {
F_37 ( V_22 -> V_52 , F_36 , NULL ) ;
F_38 ( V_22 -> V_52 ) ;
}
}
int
F_39 ( int V_263 )
{
if ( V_263 == V_17 )
return V_265 ;
if ( V_263 < 0 || ( unsigned ) V_263 >= V_266 || V_267 [ V_263 ] == - 1 )
return V_30 ;
return 0 ;
}
T_8
F_40 ( T_14 * V_268 , int * V_2 )
{
T_15 * V_22 ;
char V_49 [ 6 ] = { V_27 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 } ;
V_268 -> V_269 = V_270 ;
V_268 -> V_61 = V_271 ;
V_22 = ( T_15 * ) F_11 ( sizeof( T_15 ) ) ;
V_268 -> V_46 = ( void * ) V_22 ;
V_22 -> V_272 = TRUE ;
V_22 -> V_81 = 0 ;
if ( ! F_41 ( V_268 , F_2 , sizeof F_2 ,
V_2 ) )
return FALSE ;
if ( ! F_41 ( V_268 , V_49 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_270 ( T_14 * V_268 , const struct V_142 * V_124 ,
const T_7 * V_259 , int * V_2 )
{
const union V_144 * V_125 = & V_124 -> V_125 ;
T_15 * V_22 = ( T_15 * ) V_268 -> V_46 ;
struct V_107 V_273 ;
char V_49 [ 6 ] ;
V_139 V_120 ;
T_9 V_119 ;
T_3 V_274 , V_275 ;
T_7 V_276 ;
struct V_8 V_9 ;
T_6 V_10 , V_47 ;
T_3 V_11 ;
struct V_20 * V_20 ;
if ( V_22 -> V_272 ) {
V_22 -> V_272 = FALSE ;
#if ( V_277 V_278 ) && ( V_279 < 1500 )
if ( V_124 -> V_137 . V_138 > 2000000000 )
V_20 = NULL ;
else
#endif
V_20 = localtime ( & V_124 -> V_137 . V_138 ) ;
if ( V_20 != NULL && V_20 -> V_66 >= V_69 ) {
V_11 = ( V_20 -> V_66 - V_69 ) << V_68 ;
V_11 |= ( V_20 -> V_70 - V_73 ) << V_72 ;
V_11 |= V_20 -> V_74 << V_76 ;
V_22 -> V_81 = V_124 -> V_137 . V_138 - ( 3600 * V_20 -> V_77 + 60 * V_20 -> V_78 + V_20 -> V_79 ) ;
} else {
V_11 = 0 ;
V_22 -> V_81 = 0 ;
}
V_10 = 4 ;
V_47 = 0 ;
V_9 . V_10 = F_42 ( V_10 ) ;
V_9 . V_47 = F_42 ( V_47 ) ;
V_9 . time = 0 ;
V_9 . V_65 = F_42 ( V_11 ) ;
V_9 . type = 4 ;
V_9 . V_29 = V_267 [ V_268 -> V_263 ] ;
V_9 . V_34 = 1 ;
V_9 . V_31 = 1 ;
V_9 . V_280 = 0 ;
V_9 . V_281 = 0 ;
V_9 . V_41 [ 0 ] = 0 ;
V_9 . V_41 [ 1 ] = 0 ;
if ( ! F_41 ( V_268 , & V_9 , sizeof V_9 , V_2 ) )
return FALSE ;
}
V_49 [ 0 ] = V_122 ;
V_49 [ 1 ] = 0x00 ;
V_49 [ 2 ] = ( char ) ( ( V_124 -> V_134 + sizeof( struct V_107 ) ) % 256 ) ;
V_49 [ 3 ] = ( char ) ( ( V_124 -> V_134 + sizeof( struct V_107 ) ) / 256 ) ;
V_49 [ 4 ] = 0x00 ;
V_49 [ 5 ] = 0x00 ;
if ( ! F_41 ( V_268 , V_49 , 6 , V_2 ) )
return FALSE ;
V_120 = V_124 -> V_137 . V_138 - V_22 -> V_81 ;
V_273 . V_118 = ( T_7 ) ( V_120 / 86400 ) ;
V_120 -= V_273 . V_118 * 86400 ;
V_119 = V_120 * F_26 ( 1000000000000U ) +
V_124 -> V_137 . V_140 * F_26 ( 1000U ) ;
V_119 /= V_64 [ 1 ] ;
V_274 = ( T_3 ) ( ( V_119 >> 0 ) & 0xFFFF ) ;
V_275 = ( T_3 ) ( ( V_119 >> 16 ) & 0xFFFF ) ;
V_276 = ( T_7 ) ( ( V_119 >> 32 ) & 0xFF ) ;
V_273 . V_113 = F_42 ( V_274 ) ;
V_273 . V_114 = F_42 ( V_275 ) ;
V_273 . V_117 = V_276 ;
V_273 . V_116 = F_42 ( V_124 -> V_134 ) ;
switch ( V_268 -> V_263 ) {
case V_97 :
case V_43 :
V_273 . V_152 = ( V_125 -> V_154 . V_155 & V_156 ) ? 0x00 : V_153 ;
break;
case V_104 :
case V_99 :
V_273 . V_152 = V_125 -> V_150 . V_151 ? 0x00 : V_153 ;
break;
case V_42 :
V_273 . V_152 = V_125 -> V_157 . V_158 ? V_153 : 0x00 ;
switch ( V_125 -> V_157 . V_161 ) {
case 0 :
V_273 . V_152 |= V_160 ;
break;
case 1 :
V_273 . V_152 |= V_162 ;
break;
case 2 :
V_273 . V_152 |= V_163 ;
break;
}
break;
default:
V_273 . V_152 = 0 ;
break;
}
V_273 . V_155 = 0 ;
V_273 . V_115 = V_124 -> V_133 != V_124 -> V_134 ? F_42 ( V_124 -> V_133 ) : 0 ;
V_273 . V_41 = 0 ;
if ( ! F_41 ( V_268 , & V_273 , sizeof V_273 , V_2 ) )
return FALSE ;
if ( ! F_41 ( V_268 , V_259 , V_124 -> V_134 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_271 ( T_14 * V_268 , int * V_2 )
{
char V_49 [ 6 ] = { V_129 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( ! F_41 ( V_268 , V_49 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_43 ( unsigned char * V_282 , T_16 V_283 , unsigned char * V_284 ,
T_16 V_285 , int * V_2 )
{
unsigned char * V_286 = V_282 ;
unsigned char * V_287 = V_284 ;
unsigned char * V_288 = V_286 + V_283 ;
unsigned char * V_289 = V_287 + V_285 ;
unsigned int V_290 ;
unsigned int V_291 = 0 ;
unsigned int V_292 ;
unsigned int V_293 ;
int V_84 ;
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
V_84 = V_293 + 3 ;
if ( V_287 + V_84 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memset ( V_287 , * V_286 ++ , V_84 ) ;
V_287 += V_84 ;
break;
case 1 :
V_84 = V_293 + ( ( unsigned int ) ( * V_286 ++ ) << 4 ) + 19 ;
if ( V_286 >= V_288 )
{
* V_2 = V_296 ;
return ( - 1 ) ;
}
if ( V_287 + V_84 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memset ( V_287 , * V_286 ++ , V_84 ) ;
V_287 += V_84 ;
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
V_84 = ( unsigned int ) ( * V_286 ++ ) + 16 ;
if ( V_287 + V_84 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memcpy ( V_287 , V_287 - V_294 , V_84 ) ;
V_287 += V_84 ;
break;
default :
V_294 = V_293 + ( ( unsigned int ) ( * V_286 ++ ) << 4 ) + 3 ;
if ( V_287 - V_294 < V_284 )
{
* V_2 = V_298 ;
return ( - 1 ) ;
}
V_84 = V_292 ;
if ( V_287 + V_84 > V_289 )
{
* V_2 = V_297 ;
return ( - 1 ) ;
}
memcpy ( V_287 , V_287 - V_294 , V_84 ) ;
V_287 += V_84 ;
break;
}
}
if ( V_286 >= V_288 )
break;
}
return ( int ) ( V_287 - V_284 ) ;
}
static T_4
F_29 ( void * V_86 , unsigned int V_299 , T_1 * V_1 , T_8 V_145 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_17 V_300 ;
T_18 * V_301 ;
unsigned int V_302 = V_299 ;
T_4 V_303 = 0 ;
unsigned char * V_304 = ( unsigned char * ) V_86 ;
T_19 * V_305 ;
unsigned int V_306 ;
unsigned int V_307 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_145 ) {
V_300 = V_1 -> V_44 ;
V_301 = & V_22 -> rand ;
} else {
V_300 = V_1 -> V_25 ;
V_301 = & V_22 -> V_48 ;
}
if ( V_1 -> V_35 == V_37 ) {
V_23 = V_24 ;
V_303 = F_4 ( V_86 , V_302 , V_300 ) ;
if ( ( unsigned int ) V_303 != V_302 )
* V_2 = F_5 ( V_300 , V_3 ) ;
if ( V_303 != - 1 ) {
V_301 -> V_50 += V_303 ;
V_301 -> V_51 += V_303 ;
}
return V_303 ;
}
if ( V_301 -> V_49 == NULL ) {
V_301 -> V_49 = ( unsigned char * ) F_11 ( V_308 ) ;
if ( V_145 ) {
V_22 -> V_54 = V_22 -> V_52 ;
} else {
if ( V_1 -> V_44 != NULL ) {
F_44 ( V_22 -> V_52 == NULL ) ;
V_305 = F_45 ( T_19 , 1 ) ;
V_305 -> V_309 = V_301 -> V_51 ;
V_305 -> V_310 = V_301 -> V_50 ;
V_22 -> V_52 = F_46 ( V_22 -> V_52 ,
V_305 ) ;
V_22 -> V_53 = V_22 -> V_52 ;
}
}
if ( F_47 ( V_300 , V_301 , V_2 , V_3 ) < 0 )
return - 1 ;
}
while ( V_302 > 0 ) {
V_307 = V_301 -> V_299 - V_301 -> V_311 ;
if ( V_307 == 0 ) {
if ( V_145 ) {
V_22 -> V_54 = F_48 ( V_22 -> V_54 ) ;
if ( ! V_22 -> V_54 ) {
* V_2 = V_312 ;
return - 1 ;
}
} else {
if ( V_1 -> V_44 != NULL ) {
V_305 = F_45 ( T_19 , 1 ) ;
V_305 -> V_309 = V_301 -> V_51 ;
V_305 -> V_310 = V_301 -> V_50 ;
V_22 -> V_53 = F_46 ( V_22 -> V_53 ,
V_305 ) ;
}
}
if ( F_47 ( V_300 , V_301 , V_2 , V_3 ) < 0 )
return - 1 ;
V_307 = V_301 -> V_299 - V_301 -> V_311 ;
}
V_306 = V_302 ;
if ( V_306 > V_307 )
V_306 = V_307 ;
memcpy ( V_304 , & V_301 -> V_49 [ V_301 -> V_311 ] ,
V_306 ) ;
V_302 -= V_306 ;
V_303 += V_306 ;
V_304 += V_306 ;
V_301 -> V_311 += V_306 ;
V_301 -> V_50 += V_306 ;
}
return V_303 ;
}
static int
F_47 ( T_17 V_300 , T_18 * V_301 , int * V_2 ,
T_2 * * V_3 )
{
int V_313 ;
T_16 V_314 ;
unsigned short V_315 ;
T_6 V_316 ;
T_8 V_317 ;
unsigned char * V_318 ;
int V_319 ;
V_23 = V_24 ;
V_314 = F_4 ( & V_315 , 2 , V_300 ) ;
if ( 2 != V_314 ) {
* V_2 = F_5 ( V_300 , V_3 ) ;
return - 1 ;
}
V_301 -> V_51 += 2 ;
V_316 = F_6 ( & V_315 ) ;
if ( V_316 < 0 ) {
V_313 = - V_316 ;
V_317 = TRUE ;
} else {
V_313 = V_316 ;
V_317 = FALSE ;
}
V_318 = ( unsigned char * ) F_11 ( V_320 ) ;
V_23 = V_24 ;
V_314 = F_4 ( V_318 , V_313 , V_300 ) ;
if ( ( T_16 ) V_313 != V_314 ) {
* V_2 = F_5 ( V_300 , V_3 ) ;
F_35 ( V_318 ) ;
return - 1 ;
}
V_301 -> V_51 += V_313 ;
if ( V_317 ) {
memcpy ( V_301 -> V_49 , V_318 , V_313 ) ;
V_319 = V_313 ;
} else {
V_319 = F_43 ( V_318 , V_313 ,
V_301 -> V_49 , V_308 , V_2 ) ;
if ( V_319 < 0 ) {
F_35 ( V_318 ) ;
return - 1 ;
}
}
F_35 ( V_318 ) ;
V_301 -> V_311 = 0 ;
V_301 -> V_299 = V_319 ;
return 0 ;
}
static T_8
F_23 ( T_1 * V_1 , T_4 V_321 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
char * V_49 ;
unsigned int V_322 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_1 -> V_35 == V_37 ) {
V_22 -> V_48 . V_50 += V_321 ;
return F_49 ( V_1 -> V_25 , V_321 , V_2 ) ;
}
F_44 ( V_321 >= 0 ) ;
V_49 = ( char * ) F_11 ( V_320 ) ;
while ( V_321 != 0 ) {
if ( V_321 > V_320 )
V_322 = V_320 ;
else
V_322 = ( unsigned int ) V_321 ;
if ( F_29 ( V_49 , V_322 , V_1 , FALSE , V_2 , V_3 ) < 0 ) {
F_35 ( V_49 ) ;
return FALSE ;
}
V_321 -= V_322 ;
}
F_35 ( V_49 ) ;
return TRUE ;
}
static T_8
F_27 ( T_1 * V_1 , T_4 V_294 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_4 V_321 ;
T_20 * V_323 , * V_324 ;
T_19 * V_325 , * V_326 ;
V_22 = ( T_5 * ) V_1 -> V_46 ;
if ( V_1 -> V_35 == V_37 ) {
if ( F_10 ( V_1 -> V_44 , V_294 , V_45 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
V_321 = V_294 - V_22 -> rand . V_50 ;
V_323 = NULL ;
if ( V_321 > 0 ) {
if ( ( T_16 ) ( V_22 -> rand . V_311 + V_321 ) >= V_22 -> rand . V_299 ) {
if ( V_22 -> V_54 == NULL ) {
V_323 = V_22 -> V_52 ;
} else {
V_323 = F_48 ( V_22 -> V_54 ) ;
}
while ( V_323 ) {
V_324 = F_48 ( V_323 ) ;
if ( V_324 == NULL ) {
break;
}
V_325 = ( T_19 * ) V_324 -> V_264 ;
if ( V_325 -> V_310 > V_294 )
break;
V_323 = V_324 ;
}
if ( V_323 == NULL ) {
* V_2 = V_312 ;
return FALSE ;
}
}
} else if ( V_321 < 0 ) {
if ( V_22 -> rand . V_311 + V_321 < 0 ) {
if ( V_22 -> V_54 == NULL ) {
V_323 = V_22 -> V_53 ;
} else {
V_323 = F_50 ( V_22 -> V_54 ) ;
}
while ( V_323 ) {
V_326 = ( T_19 * ) V_323 -> V_264 ;
if ( V_326 -> V_310 <= V_294 )
break;
V_323 = F_50 ( V_323 ) ;
}
if ( V_323 == NULL ) {
* V_2 = V_312 ;
return FALSE ;
}
}
}
if ( V_323 != NULL ) {
V_326 = ( T_19 * ) V_323 -> V_264 ;
if ( F_10 ( V_1 -> V_44 , V_326 -> V_309 , V_45 , V_2 ) == - 1 )
return FALSE ;
if ( V_22 -> rand . V_49 == NULL ) {
V_22 -> rand . V_49 = ( unsigned char * ) F_11 ( V_308 ) ;
}
V_22 -> V_54 = V_323 ;
V_22 -> rand . V_50 = V_326 -> V_310 ;
V_22 -> rand . V_51 = V_326 -> V_309 ;
if ( F_47 ( V_1 -> V_44 , & V_22 -> rand , V_2 , V_3 ) < 0 )
return FALSE ;
V_321 = V_294 - V_22 -> rand . V_50 ;
F_44 ( V_321 >= 0 && ( unsigned long ) V_321 < V_22 -> rand . V_299 ) ;
}
V_22 -> rand . V_311 += ( int ) V_321 ;
V_22 -> rand . V_50 += V_321 ;
return TRUE ;
}
