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
if ( * V_2 != 0 )
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
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_4 = F_4 ( V_7 , 4 , V_1 -> V_25 ) ;
if ( V_4 != 4 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
type = F_6 ( V_6 ) ;
if ( type != V_26 ) {
* V_2 = V_27 ;
* V_3 = F_7 ( L_1 ) ;
return - 1 ;
}
V_23 = V_24 ;
V_4 = F_4 ( & V_9 , sizeof V_9 , V_1 -> V_25 ) ;
if ( V_4 != sizeof V_9 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( V_9 . V_28 >= F_3
|| V_12 [ V_9 . V_28 ] == V_16 ) {
* V_2 = V_29 ;
* V_3 = F_7 ( L_2 ,
V_9 . V_28 ) ;
return - 1 ;
}
if ( V_9 . V_30 >= V_31 ) {
* V_2 = V_32 ;
* V_3 = F_7 ( L_3 , V_9 . V_30 ) ;
return - 1 ;
}
if ( V_9 . V_33 != 1 ) {
V_1 -> V_34 = V_35 ;
} else {
V_1 -> V_34 = V_36 ;
}
V_1 -> V_37 = V_12 [ V_9 . V_28 ] ;
V_10 = F_6 ( & V_9 . V_10 ) ;
if ( F_8 ( V_1 , V_2 , V_3 , V_10 ,
V_9 . V_28 ) < 0 )
return - 1 ;
if ( ( V_9 . V_28 == V_38 ||
V_9 . V_28 == V_39 ) &&
V_1 -> V_37 == V_17 ) {
switch ( V_10 ) {
case 1 :
switch ( F_6 ( & V_9 . V_40 [ 0 ] ) ) {
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
V_21 = F_9 ( V_1 -> V_25 ) ;
if ( V_1 -> V_43 != NULL ) {
if ( F_10 ( V_1 -> V_43 , V_21 , V_44 , V_2 ) == - 1 )
return - 1 ;
}
V_22 = ( T_5 * ) F_11 ( sizeof( T_5 ) ) ;
V_1 -> V_45 = ( void * ) V_22 ;
V_22 -> V_10 = V_10 ;
V_22 -> V_46 = F_6 ( & V_9 . V_46 ) ;
V_22 -> V_47 . V_48 = NULL ;
V_22 -> rand . V_48 = NULL ;
V_22 -> V_47 . V_49 = V_21 ;
V_22 -> V_47 . V_50 = V_21 ;
V_22 -> rand . V_49 = V_21 ;
V_22 -> rand . V_50 = V_21 ;
V_22 -> V_51 = NULL ;
V_22 -> V_52 = NULL ;
V_22 -> V_53 = NULL ;
V_1 -> V_54 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_58 = V_59 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_62 = 0 ;
V_22 -> V_30 = V_63 [ V_9 . V_30 ] ;
V_22 -> V_28 = V_9 . V_28 ;
V_11 = F_6 ( & V_9 . V_64 ) ;
V_20 . V_65 = ( ( V_11 & 0xfe00 ) >> 9 ) + 1980 - 1900 ;
V_20 . V_66 = ( ( V_11 & 0x1e0 ) >> 5 ) - 1 ;
V_20 . V_67 = ( V_11 & 0x1f ) ;
#if 0
start_time = pletohs(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
V_20 . V_68 = 0 ;
V_20 . V_69 = 0 ;
V_20 . V_70 = 0 ;
V_20 . V_71 = - 1 ;
V_22 -> V_72 = mktime ( & V_20 ) ;
V_1 -> V_73 = V_74 ;
return 1 ;
}
static int
F_8 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 V_10 ,
T_7 V_28 )
{
int V_4 ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
T_3 type , V_75 ;
int V_76 ;
unsigned char V_77 [ 256 ] ;
for (; ; ) {
V_23 = V_24 ;
V_4 = F_4 ( V_6 , 2 , V_1 -> V_25 ) ;
if ( V_4 != 2 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_78 ;
return - 1 ;
}
return 0 ;
}
type = F_6 ( V_6 ) ;
if ( ( type != V_79 ) && ( type != V_80 )
&& ( type != V_81 ) && ( type != V_82 )
&& ( type != V_83 ) && ( type != V_84 )
&& ( type != V_85 )
&& ( ( type != V_86 ) || ( V_10 > 2 ) ) ) {
if ( F_10 ( V_1 -> V_25 , - 2 , V_87 , V_2 ) == - 1 )
return - 1 ;
return 0 ;
}
V_23 = V_24 ;
V_4 = F_4 ( V_7 , 4 , V_1 -> V_25 ) ;
if ( V_4 != 4 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_78 ;
return - 1 ;
}
V_75 = F_6 ( V_7 ) ;
if ( ( V_28 == V_38 || V_28 == V_39 ) &&
type == V_80 ) {
V_76 = F_12 ( V_75 , ( int ) sizeof V_77 ) ;
V_4 = F_4 ( V_77 , V_76 ,
V_1 -> V_25 ) ;
if ( V_4 != V_76 ) {
* V_2 = F_5 ( V_1 -> V_25 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_78 ;
return - 1 ;
}
}
switch ( V_10 ) {
case 2 :
if ( F_13 ( V_1 , V_77 ,
V_75 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
case 1 :
case 4 :
case 5 :
if ( F_14 ( V_1 , V_77 ,
V_75 , V_10 , V_2 , V_3 ) < 0 )
return - 1 ;
break;
}
if ( V_75 > sizeof V_77 ) {
if ( F_10 ( V_1 -> V_25 , V_75 - sizeof V_77 ,
V_87 , V_2 ) == - 1 )
return - 1 ;
}
} else {
if ( F_10 ( V_1 -> V_25 , V_75 , V_87 , V_2 ) == - 1 )
return - 1 ;
}
}
}
static int
F_13 ( T_1 * V_1 , unsigned char * V_77 , T_3 V_75 ,
int * V_2 , T_2 * * V_3 )
{
static const char V_88 [] = L_4 ;
if ( V_75 < sizeof V_88 - 1 ) {
* V_2 = V_29 ;
* V_3 = F_7 ( L_5 ) ;
return - 1 ;
}
if ( strncmp ( ( char * ) V_77 , V_88 , sizeof V_88 - 1 ) == 0 ) {
V_1 -> V_37 = V_89 ;
} else {
* V_2 = V_29 ;
* V_3 = F_7 ( L_6 ,
V_75 , V_77 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_14 ( T_1 * V_1 , unsigned char * V_77 , T_3 V_75 ,
T_6 V_10 , int * V_2 , T_2 * * V_3 )
{
if ( V_75 < 5 ) {
* V_2 = V_29 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
switch ( V_77 [ 4 ] ) {
case V_90 :
V_1 -> V_37 = V_91 ;
break;
case V_92 :
V_1 -> V_37 = V_17 ;
break;
case V_93 :
V_1 -> V_37 = V_42 ;
break;
case V_94 :
V_1 -> V_37 = V_17 ;
switch ( V_10 ) {
case 4 :
if ( V_77 [ 1 ] == 0xfa )
V_1 -> V_37 = V_41 ;
break;
case 5 :
if ( V_75 < 7 ) {
* V_2 = V_29 ;
* V_3 = F_15 ( L_8 ) ;
return - 1 ;
}
if ( V_77 [ 6 ] == 0x01 )
V_1 -> V_37 = V_41 ;
break;
}
break;
case V_95 :
V_1 -> V_37 = V_96 ;
break;
default:
* V_2 = V_29 ;
* V_3 = F_7 ( L_9 ,
V_77 [ 4 ] ) ;
return - 1 ;
}
return 0 ;
}
static T_8
V_55 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_4 * V_97 )
{
T_5 * V_22 ;
int V_98 ;
T_3 type , V_75 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
struct V_103 V_104 ;
T_3 V_105 , V_106 , V_107 , V_108 ;
T_7 V_109 , V_110 ;
T_9 V_111 , V_112 , V_113 ;
T_7 * V_114 ;
V_22 = ( T_5 * ) V_1 -> V_45 ;
for (; ; ) {
* V_97 = V_22 -> V_47 . V_49 ;
V_98 = F_16 ( V_1 , FALSE , & type , & V_75 ,
V_2 , V_3 ) ;
if ( V_98 <= 0 ) {
return FALSE ;
}
switch ( type ) {
case V_115 :
if ( V_22 -> V_28 == V_116 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_10 ) ;
return FALSE ;
}
if ( ! F_17 ( V_1 , FALSE , & V_100 , V_2 ,
V_3 ) ) {
return FALSE ;
}
V_105 = F_6 ( & V_100 . V_105 ) ;
V_106 = F_6 ( & V_100 . V_106 ) ;
V_109 = V_100 . V_109 ;
V_110 = V_100 . V_110 ;
V_108 = F_6 ( & V_100 . V_108 ) ;
V_107 = F_6 ( & V_100 . V_107 ) ;
V_75 -= sizeof V_100 ;
F_18 ( V_1 , & V_1 -> V_117 ,
& V_100 ) ;
goto V_118;
case V_119 :
if ( V_22 -> V_28 != V_116 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_11 ) ;
return FALSE ;
}
if ( ! F_19 ( V_1 , FALSE , & V_102 , V_2 ,
V_3 ) ) {
return FALSE ;
}
V_105 = F_6 ( & V_102 . V_105 ) ;
V_106 = F_6 ( & V_102 . V_106 ) ;
V_109 = V_102 . V_109 ;
V_110 = V_102 . V_110 ;
V_108 = F_6 ( & V_102 . V_108 ) ;
V_107 = F_6 ( & V_102 . V_107 ) ;
if ( V_22 -> V_10 >= 5 )
V_75 -= sizeof V_102 ;
else {
if ( V_22 -> V_46 >= 95 )
V_75 -= sizeof V_100 ;
else
V_75 -= sizeof V_102 ;
}
F_20 ( & V_1 -> V_117 , & V_102 ) ;
goto V_118;
case V_120 :
if ( ! F_21 ( V_1 , FALSE , & V_104 , V_2 ,
V_3 ) ) {
return FALSE ;
}
V_105 = F_6 ( & V_104 . V_105 ) ;
V_106 = F_6 ( & V_104 . V_106 ) ;
V_109 = V_104 . V_109 ;
V_110 = V_104 . V_110 ;
V_108 = F_6 ( & V_104 . V_108 ) ;
V_107 = F_6 ( & V_104 . V_107 ) ;
V_75 -= sizeof V_104 ;
F_22 ( V_1 , & V_1 -> V_117 ,
& V_104 ) ;
goto V_118;
case V_121 :
* V_2 = 0 ;
return FALSE ;
default:
break;
}
if ( ! F_23 ( V_1 , V_75 , V_2 , V_3 ) )
return FALSE ;
}
V_118:
if ( V_108 > V_75 ) {
* V_2 = V_27 ;
* V_3 = F_15 ( L_12 ) ;
return FALSE ;
}
V_1 -> V_122 . V_123 = V_107 ? V_124 | V_125 : V_124 ;
V_1 -> V_122 . V_126 = V_107 ? V_107 : V_108 ;
V_1 -> V_122 . V_127 = V_108 ;
F_24 ( V_1 -> V_128 , V_75 ) ;
V_114 = F_25 ( V_1 -> V_128 ) ;
if ( ! F_26 ( V_1 , FALSE , V_114 , V_75 , V_2 , V_3 ) )
return FALSE ;
V_1 -> V_122 . V_129 = F_27 ( V_1 -> V_37 , V_114 , V_75 ,
& V_1 -> V_117 ) ;
V_111 = ( ( ( T_9 ) V_109 ) << 32 ) | ( ( ( T_9 ) V_106 ) << 16 ) | V_105 ;
V_111 *= V_22 -> V_30 ;
V_112 = V_111 / F_28 ( 1000000000000U ) ;
V_113 = V_111 - V_112 * F_28 ( 1000000000000U ) ;
V_112 += V_110 * 86400 ;
V_112 += V_22 -> V_72 ;
V_1 -> V_122 . V_130 . V_131 = ( V_132 ) V_112 ;
V_1 -> V_122 . V_130 . V_133 = ( int ) ( V_113 / 1000 ) ;
return TRUE ;
}
static T_8
V_57 ( T_1 * V_1 , T_4 V_134 ,
union V_135 * V_117 , T_7 * V_114 , int V_136 ,
int * V_2 , T_2 * * V_3 )
{
int V_98 ;
T_3 type , V_75 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
struct V_103 V_104 ;
if ( ! F_29 ( V_1 , V_134 , V_2 , V_3 ) )
return FALSE ;
V_98 = F_16 ( V_1 , TRUE , & type , & V_75 , V_2 ,
V_3 ) ;
if ( V_98 <= 0 ) {
if ( V_98 == 0 ) {
* V_2 = V_78 ;
}
return FALSE ;
}
switch ( type ) {
case V_115 :
if ( ! F_17 ( V_1 , TRUE , & V_100 , V_2 , V_3 ) ) {
return FALSE ;
}
V_75 -= sizeof V_100 ;
F_18 ( V_1 , V_117 , & V_100 ) ;
break;
case V_119 :
if ( ! F_19 ( V_1 , TRUE , & V_102 , V_2 , V_3 ) ) {
return FALSE ;
}
V_75 -= sizeof V_102 ;
F_20 ( V_117 , & V_102 ) ;
break;
case V_120 :
if ( ! F_21 ( V_1 , TRUE , & V_104 , V_2 , V_3 ) ) {
return FALSE ;
}
V_75 -= sizeof V_104 ;
F_22 ( V_1 , V_117 , & V_104 ) ;
break;
default:
F_30 () ;
return FALSE ;
}
if ( ! F_26 ( V_1 , TRUE , V_114 , V_136 , V_2 , V_3 ) )
return FALSE ;
F_27 ( V_1 -> V_37 , V_114 , V_136 , V_117 ) ;
return TRUE ;
}
static int
F_16 ( T_1 * V_1 , T_8 V_137 , T_3 * V_138 ,
T_3 * V_139 , int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
char V_6 [ 2 ] ;
char V_7 [ 4 ] ;
V_4 = F_31 ( V_6 , 2 , V_1 , V_137 , V_2 ,
V_3 ) ;
if ( V_4 != 2 ) {
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_78 ;
return - 1 ;
}
return 0 ;
}
V_4 = F_31 ( V_7 , 4 , V_1 , V_137 , V_2 ,
V_3 ) ;
if ( V_4 != 4 ) {
if ( * V_2 == 0 )
* V_2 = V_78 ;
return - 1 ;
}
* V_138 = F_6 ( V_6 ) ;
* V_139 = F_6 ( V_7 ) ;
return 1 ;
}
static T_8
F_17 ( T_1 * V_1 , T_8 V_137 , struct V_99 * V_100 ,
int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_31 ( V_100 , ( unsigned int ) sizeof *V_100 , V_1 ,
V_137 , V_2 , V_3 ) ;
if ( V_4 != sizeof *V_100 ) {
if ( * V_2 == 0 )
* V_2 = V_78 ;
return FALSE ;
}
return TRUE ;
}
static void
F_18 ( T_1 * V_1 , union V_135 * V_117 ,
struct V_99 * V_100 )
{
switch ( V_1 -> V_37 ) {
case V_14 :
V_117 -> V_140 . V_141 = 0 ;
break;
case V_96 :
case V_91 :
V_117 -> V_142 . V_143 = ( V_100 -> V_144 & V_145 ) ? TRUE : FALSE ;
break;
case V_89 :
case V_42 :
case V_17 :
V_117 -> V_146 . V_147 = ( V_100 -> V_144 & V_145 ) ? 0x00 : V_148 ;
break;
case V_41 :
V_117 -> V_149 . V_150 = ( V_100 -> V_144 & V_145 ) ? FALSE : TRUE ;
switch ( V_100 -> V_144 & V_151 ) {
case V_152 :
V_117 -> V_149 . V_153 = 0 ;
break;
case V_154 :
V_117 -> V_149 . V_153 = 1 ;
break;
case V_155 :
V_117 -> V_149 . V_153 = 2 ;
break;
default:
V_117 -> V_149 . V_153 = 30 ;
break;
}
}
}
static T_8
F_19 ( T_1 * V_1 , T_8 V_137 , struct V_101 * V_102 ,
int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_31 ( V_102 , ( unsigned int ) sizeof *V_102 , V_1 ,
V_137 , V_2 , V_3 ) ;
if ( V_4 != sizeof *V_102 ) {
if ( * V_2 == 0 )
* V_2 = V_78 ;
return FALSE ;
}
return TRUE ;
}
static void
F_20 ( union V_135 * V_117 ,
struct V_101 * V_102 )
{
T_10 V_156 ;
T_7 V_157 , V_158 ;
T_3 V_159 , V_160 ;
V_117 -> V_161 . V_147 = 0 ;
V_156 = F_32 ( & V_102 -> V_162 . V_156 ) ;
if ( V_156 & V_163 )
V_117 -> V_161 . V_147 |= V_164 ;
V_157 = V_102 -> V_162 . V_165 & V_166 ;
V_158 = V_102 -> V_162 . V_165 & V_167 ;
V_159 = F_6 ( & V_102 -> V_162 . V_168 ) ;
V_160 = F_6 ( & V_102 -> V_162 . V_169 ) ;
switch ( V_157 ) {
case V_170 :
if ( V_159 == 0 && V_160 == 5 )
V_117 -> V_161 . V_171 = V_172 ;
else
V_117 -> V_161 . V_171 = V_173 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_177 :
V_117 -> V_161 . V_171 = V_178 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_179 :
V_117 -> V_161 . V_171 = V_180 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_181 :
V_117 -> V_161 . V_171 = V_182 ;
switch ( V_158 ) {
case V_183 :
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_184 :
V_117 -> V_161 . type = V_185 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_186 :
V_117 -> V_161 . type = V_187 ;
switch ( V_102 -> V_162 . V_188 ) {
case V_189 :
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_190 :
V_117 -> V_161 . V_175 =
V_191 ;
break;
case V_192 :
V_117 -> V_161 . V_175 =
V_193 ;
break;
case V_194 :
V_117 -> V_161 . V_175 =
V_195 ;
break;
case V_196 :
V_117 -> V_161 . V_175 =
V_197 ;
break;
case V_198 :
V_117 -> V_161 . V_175 =
V_199 ;
break;
case V_200 :
V_117 -> V_161 . V_175 = V_201 ;
break;
case V_202 :
V_117 -> V_161 . V_175 = V_203 ;
break;
case V_204 :
V_117 -> V_161 . V_175 = V_205 ;
break;
case V_206 :
V_117 -> V_161 . V_175 = V_207 ;
break;
case V_208 :
V_117 -> V_161 . V_175 = V_209 ;
break;
case V_210 :
V_117 -> V_161 . V_175 =
V_211 ;
break;
case V_212 :
V_117 -> V_161 . V_175 = V_213 ;
break;
default:
V_117 -> V_161 . V_175 = V_176 ;
break;
}
break;
case V_214 :
V_117 -> V_161 . type = V_215 ;
switch ( V_102 -> V_162 . V_188 ) {
case V_189 :
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_216 :
V_117 -> V_161 . V_175 =
V_217 ;
break;
case V_218 :
V_117 -> V_161 . V_175 = V_219 ;
break;
case V_220 :
V_117 -> V_161 . V_175 = V_221 ;
break;
case V_222 :
V_117 -> V_161 . V_175 =
V_223 ;
break;
case V_224 :
V_117 -> V_161 . V_175 =
V_225 ;
break;
default:
V_117 -> V_161 . V_175 = V_176 ;
break;
}
break;
case V_226 :
V_117 -> V_161 . type = V_227 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_228 :
V_117 -> V_161 . type = V_229 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_230 :
V_117 -> V_161 . type = V_231 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_232 :
V_117 -> V_161 . type = V_233 ;
switch ( V_102 -> V_162 . V_188 ) {
case V_189 :
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_234 :
V_117 -> V_161 . V_175 =
V_235 ;
break;
case V_236 :
V_117 -> V_161 . V_175 =
V_237 ;
break;
case V_238 :
V_117 -> V_161 . V_175 =
V_239 ;
break;
default:
V_117 -> V_161 . V_175 = V_176 ;
break;
}
break;
default:
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
}
break;
case V_240 :
V_117 -> V_161 . V_171 = V_241 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_242 :
V_117 -> V_161 . V_171 = V_172 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
case V_243 :
V_117 -> V_161 . V_171 = V_244 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
default:
V_117 -> V_161 . V_171 = V_173 ;
V_117 -> V_161 . type = V_174 ;
V_117 -> V_161 . V_175 = V_176 ;
break;
}
V_117 -> V_161 . V_159 = V_159 ;
V_117 -> V_161 . V_160 = V_160 ;
V_117 -> V_161 . V_153 = F_6 ( & V_102 -> V_162 . V_153 ) ;
V_117 -> V_161 . V_245 = F_6 ( & V_102 -> V_162 . V_245 ) ;
V_117 -> V_161 . V_246 = F_6 ( & V_102 -> V_162 . V_247 . V_246 ) ;
V_117 -> V_161 . V_248 = F_6 ( & V_102 -> V_162 . V_247 . V_248 ) ;
V_117 -> V_161 . V_249 = F_33 ( & V_102 -> V_162 . V_247 . V_249 ) ;
}
static T_8
F_21 ( T_1 * V_1 , T_8 V_137 , struct V_103 * V_104 ,
int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_31 ( V_104 , ( unsigned int ) sizeof *V_104 , V_1 ,
V_137 , V_2 , V_3 ) ;
if ( V_4 != sizeof *V_104 ) {
if ( * V_2 == 0 )
* V_2 = V_78 ;
return FALSE ;
}
return TRUE ;
}
static void
F_22 ( T_1 * V_1 , union V_135 * V_117 ,
struct V_103 * V_104 V_250 )
{
switch ( V_1 -> V_37 ) {
case V_14 :
V_117 -> V_140 . V_141 = - 1 ;
break;
}
}
static T_8
F_26 ( T_1 * V_1 , T_8 V_137 , T_7 * V_114 ,
unsigned int V_75 , int * V_2 , T_2 * * V_3 )
{
T_4 V_4 ;
V_4 = F_31 ( V_114 , V_75 , V_1 , V_137 , V_2 , V_3 ) ;
if ( V_4 != ( T_4 ) V_75 ) {
if ( * V_2 == 0 )
* V_2 = V_78 ;
return FALSE ;
}
return TRUE ;
}
static int
F_34 ( const T_7 * V_114 , int V_126 )
{
int V_251 ;
if ( V_126 <= 0 ) {
return V_96 ;
}
if ( V_114 [ 0 ] == 0xFF ) {
return V_96 ;
}
if ( V_126 >= 2 ) {
if ( V_114 [ 0 ] == 0x07 && V_114 [ 1 ] == 0x03 ) {
return V_252 ;
} else if ( ( V_114 [ 0 ] == 0x0F && V_114 [ 1 ] == 0x00 ) ||
( V_114 [ 0 ] == 0x8F && V_114 [ 1 ] == 0x00 ) ) {
return V_253 ;
}
for ( V_251 = 0 ; V_251 < V_126 && ( V_114 [ V_251 ] & 0x01 ) == 0 ; V_251 ++ )
;
V_251 ++ ;
if ( V_251 == V_126 ) {
return V_89 ;
}
if ( V_114 [ V_251 ] == 0x03 )
return V_42 ;
}
return V_89 ;
}
static int
F_27 ( int V_254 , const T_7 * V_114 , int V_126 ,
union V_135 * V_117 )
{
switch ( V_254 ) {
case V_17 :
V_254 = F_34 ( V_114 , V_126 ) ;
switch ( V_254 ) {
case V_252 :
case V_253 :
case V_96 :
if ( V_117 -> V_146 . V_147 == 0 )
V_117 -> V_142 . V_143 = TRUE ;
else
V_117 -> V_142 . V_143 = FALSE ;
break;
case V_41 :
if ( V_117 -> V_146 . V_147 == 0x00 )
V_117 -> V_149 . V_150 = FALSE ;
else
V_117 -> V_149 . V_150 = TRUE ;
V_117 -> V_149 . V_153 = 0 ;
break;
}
break;
case V_19 :
if ( V_117 -> V_161 . type == V_215 && V_126 >= 2 ) {
if ( V_114 [ 0 ] == 0xff && V_114 [ 1 ] == 0x00 ) {
V_117 -> V_161 . V_175 =
V_217 ;
} else {
if ( V_117 -> V_161 . V_175 ==
V_217 ) {
V_117 -> V_161 . V_175 =
V_219 ;
}
}
}
break;
}
return V_254 ;
}
static void
V_59 ( T_1 * V_1 )
{
T_5 * V_22 ;
V_22 = ( T_5 * ) V_1 -> V_45 ;
if ( V_22 -> V_47 . V_48 != NULL ) {
F_35 ( V_22 -> V_47 . V_48 ) ;
V_22 -> V_47 . V_48 = NULL ;
}
}
static void
F_36 ( T_11 V_255 , T_11 T_12 V_250 )
{
F_35 ( V_255 ) ;
}
static void
V_61 ( T_1 * V_1 )
{
T_5 * V_22 ;
V_22 = ( T_5 * ) V_1 -> V_45 ;
if ( V_22 -> rand . V_48 != NULL )
F_35 ( V_22 -> rand . V_48 ) ;
if ( V_22 -> V_51 != NULL ) {
F_37 ( V_22 -> V_51 , F_36 , NULL ) ;
F_38 ( V_22 -> V_51 ) ;
}
}
int
F_39 ( int V_254 )
{
if ( V_254 == V_17 )
return V_256 ;
if ( V_254 < 0 || ( unsigned ) V_254 >= V_257 || V_258 [ V_254 ] == - 1 )
return V_29 ;
return 0 ;
}
T_8
F_40 ( T_13 * V_259 , int * V_2 )
{
T_14 * V_22 ;
char V_48 [ 6 ] = { V_26 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 } ;
V_259 -> V_260 = V_261 ;
V_259 -> V_60 = V_262 ;
V_22 = ( T_14 * ) F_11 ( sizeof( T_14 ) ) ;
V_259 -> V_45 = ( void * ) V_22 ;
V_22 -> V_263 = TRUE ;
V_22 -> V_72 = 0 ;
if ( ! F_41 ( V_259 , F_2 , sizeof F_2 ,
V_2 ) )
return FALSE ;
if ( ! F_41 ( V_259 , V_48 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_261 ( T_13 * V_259 , const struct V_264 * V_122 ,
const union V_135 * V_117 , const T_7 * V_114 , int * V_2 )
{
T_14 * V_22 = ( T_14 * ) V_259 -> V_45 ;
struct V_99 V_265 ;
char V_48 [ 6 ] ;
V_132 V_112 ;
T_9 V_111 ;
T_3 V_266 , V_267 ;
T_7 V_268 ;
struct V_8 V_9 ;
T_6 V_10 , V_46 ;
T_3 V_11 ;
struct V_20 * V_20 ;
if ( V_22 -> V_263 ) {
V_22 -> V_263 = FALSE ;
#ifdef F_42
if ( V_122 -> V_130 . V_131 > 2000000000 )
V_20 = NULL ;
else
#endif
V_20 = localtime ( & V_122 -> V_130 . V_131 ) ;
if ( V_20 != NULL && V_20 -> V_65 >= 1980 ) {
V_11 = ( V_20 -> V_65 - ( 1980 - 1900 ) ) << 9 ;
V_11 |= ( V_20 -> V_66 + 1 ) << 5 ;
V_11 |= V_20 -> V_67 ;
V_22 -> V_72 = V_122 -> V_130 . V_131 - ( 3600 * V_20 -> V_68 + 60 * V_20 -> V_69 + V_20 -> V_70 ) ;
} else {
V_11 = 0 ;
V_22 -> V_72 = 0 ;
}
V_10 = 4 ;
V_46 = 0 ;
V_9 . V_10 = F_43 ( V_10 ) ;
V_9 . V_46 = F_43 ( V_46 ) ;
V_9 . time = 0 ;
V_9 . V_64 = F_43 ( V_11 ) ;
V_9 . type = 4 ;
V_9 . V_28 = V_258 [ V_259 -> V_254 ] ;
V_9 . V_33 = 1 ;
V_9 . V_30 = 1 ;
V_9 . V_269 = 0 ;
V_9 . V_270 = 0 ;
V_9 . V_40 [ 0 ] = 0 ;
V_9 . V_40 [ 1 ] = 0 ;
if ( ! F_41 ( V_259 , & V_9 , sizeof V_9 , V_2 ) )
return FALSE ;
}
V_48 [ 0 ] = V_115 ;
V_48 [ 1 ] = 0x00 ;
V_48 [ 2 ] = ( char ) ( ( V_122 -> V_127 + sizeof( struct V_99 ) ) % 256 ) ;
V_48 [ 3 ] = ( char ) ( ( V_122 -> V_127 + sizeof( struct V_99 ) ) / 256 ) ;
V_48 [ 4 ] = 0x00 ;
V_48 [ 5 ] = 0x00 ;
if ( ! F_41 ( V_259 , V_48 , 6 , V_2 ) )
return FALSE ;
V_112 = V_122 -> V_130 . V_131 - V_22 -> V_72 ;
V_265 . V_110 = ( T_7 ) ( V_112 / 86400 ) ;
V_112 -= V_265 . V_110 * 86400 ;
V_111 = V_112 * F_28 ( 1000000000000U ) +
V_122 -> V_130 . V_133 * F_28 ( 1000U ) ;
V_111 /= V_63 [ 1 ] ;
V_266 = ( T_3 ) ( ( V_111 >> 0 ) & 0xFFFF ) ;
V_267 = ( T_3 ) ( ( V_111 >> 16 ) & 0xFFFF ) ;
V_268 = ( T_7 ) ( ( V_111 >> 32 ) & 0xFF ) ;
V_265 . V_105 = F_43 ( V_266 ) ;
V_265 . V_106 = F_43 ( V_267 ) ;
V_265 . V_109 = V_268 ;
V_265 . V_108 = F_43 ( V_122 -> V_127 ) ;
switch ( V_259 -> V_254 ) {
case V_89 :
case V_42 :
V_265 . V_144 = ( V_117 -> V_146 . V_147 & V_148 ) ? 0x00 : V_145 ;
break;
case V_96 :
case V_91 :
V_265 . V_144 = V_117 -> V_142 . V_143 ? 0x00 : V_145 ;
break;
case V_41 :
V_265 . V_144 = V_117 -> V_149 . V_150 ? V_145 : 0x00 ;
switch ( V_117 -> V_149 . V_153 ) {
case 0 :
V_265 . V_144 |= V_152 ;
break;
case 1 :
V_265 . V_144 |= V_154 ;
break;
case 2 :
V_265 . V_144 |= V_155 ;
break;
}
break;
default:
V_265 . V_144 = 0 ;
break;
}
V_265 . V_147 = 0 ;
V_265 . V_107 = V_122 -> V_126 != V_122 -> V_127 ? F_43 ( V_122 -> V_126 ) : 0 ;
V_265 . V_40 = 0 ;
if ( ! F_41 ( V_259 , & V_265 , sizeof V_265 , V_2 ) )
return FALSE ;
if ( ! F_41 ( V_259 , V_114 , V_122 -> V_127 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8
V_262 ( T_13 * V_259 , int * V_2 )
{
char V_48 [ 6 ] = { V_121 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( ! F_41 ( V_259 , V_48 , 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_44 ( unsigned char * V_271 , T_15 V_272 , unsigned char * V_273 ,
T_15 V_274 , int * V_2 )
{
unsigned char * V_275 = V_271 ;
unsigned char * V_276 = V_273 ;
unsigned char * V_277 = V_275 + V_272 ;
unsigned char * V_278 = V_276 + V_274 ;
unsigned int V_279 ;
unsigned int V_280 = 0 ;
unsigned int V_281 ;
unsigned int V_282 ;
int V_75 ;
int V_283 ;
if ( V_272 > V_284 ) {
return ( - 1 ) ;
}
V_279 = 0 ;
while ( 1 )
{
V_279 = V_279 >> 1 ;
if ( 0 == V_279 )
{
V_279 = 0x8000 ;
V_280 = F_6 ( V_275 ) ;
V_275 += 2 ;
if ( V_275 >= V_277 )
{
* V_2 = V_285 ;
return ( - 1 ) ;
}
}
if ( ! ( V_279 & V_280 ) )
{
* ( V_276 ++ ) = * ( V_275 ++ ) ;
}
else
{
V_281 = ( unsigned int ) ( ( * V_275 ) >> 4 ) & 0xF ;
V_282 = ( unsigned int ) ( ( * V_275 ) & 0xF ) ;
V_275 ++ ;
if ( V_275 >= V_277 )
{
* V_2 = V_285 ;
return ( - 1 ) ;
}
switch ( V_281 )
{
case 0 :
V_75 = V_282 + 3 ;
if ( V_276 + V_75 > V_278 )
{
* V_2 = V_286 ;
return ( - 1 ) ;
}
memset ( V_276 , * V_275 ++ , V_75 ) ;
V_276 += V_75 ;
break;
case 1 :
V_75 = V_282 + ( ( unsigned int ) ( * V_275 ++ ) << 4 ) + 19 ;
if ( V_275 >= V_277 )
{
* V_2 = V_285 ;
return ( - 1 ) ;
}
if ( V_276 + V_75 > V_278 )
{
* V_2 = V_286 ;
return ( - 1 ) ;
}
memset ( V_276 , * V_275 ++ , V_75 ) ;
V_276 += V_75 ;
break;
case 2 :
V_283 = V_282 + ( ( unsigned int ) ( * V_275 ++ ) << 4 ) + 3 ;
if ( V_275 >= V_277 )
{
* V_2 = V_285 ;
return ( - 1 ) ;
}
if ( V_276 - V_283 < V_273 )
{
* V_2 = V_287 ;
return ( - 1 ) ;
}
V_75 = ( unsigned int ) ( * V_275 ++ ) + 16 ;
if ( V_276 + V_75 > V_278 )
{
* V_2 = V_286 ;
return ( - 1 ) ;
}
memcpy ( V_276 , V_276 - V_283 , V_75 ) ;
V_276 += V_75 ;
break;
default :
V_283 = V_282 + ( ( unsigned int ) ( * V_275 ++ ) << 4 ) + 3 ;
if ( V_276 - V_283 < V_273 )
{
* V_2 = V_287 ;
return ( - 1 ) ;
}
V_75 = V_281 ;
if ( V_276 + V_75 > V_278 )
{
* V_2 = V_286 ;
return ( - 1 ) ;
}
memcpy ( V_276 , V_276 - V_283 , V_75 ) ;
V_276 += V_75 ;
break;
}
}
if ( V_275 >= V_277 )
break;
}
return ( int ) ( V_276 - V_273 ) ;
}
static T_4
F_31 ( void * V_77 , unsigned int V_288 , T_1 * V_1 , T_8 V_137 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_16 V_289 ;
T_17 * V_290 ;
unsigned int V_291 = V_288 ;
T_4 V_292 = 0 ;
unsigned char * V_293 = ( unsigned char * ) V_77 ;
T_18 * V_294 ;
unsigned int V_295 ;
unsigned int V_296 ;
V_22 = ( T_5 * ) V_1 -> V_45 ;
if ( V_137 ) {
V_289 = V_1 -> V_43 ;
V_290 = & V_22 -> rand ;
} else {
V_289 = V_1 -> V_25 ;
V_290 = & V_22 -> V_47 ;
}
if ( V_1 -> V_34 == V_36 ) {
V_23 = V_24 ;
V_292 = F_4 ( V_77 , V_291 , V_289 ) ;
if ( ( unsigned int ) V_292 != V_291 )
* V_2 = F_5 ( V_289 , V_3 ) ;
if ( V_292 != - 1 ) {
V_290 -> V_49 += V_292 ;
V_290 -> V_50 += V_292 ;
}
return V_292 ;
}
if ( V_290 -> V_48 == NULL ) {
V_290 -> V_48 = ( unsigned char * ) F_11 ( V_297 ) ;
if ( V_137 ) {
V_22 -> V_53 = V_22 -> V_51 ;
} else {
if ( V_1 -> V_43 != NULL ) {
F_45 ( V_22 -> V_51 == NULL ) ;
V_294 = F_46 ( T_18 , 1 ) ;
V_294 -> V_298 = V_290 -> V_50 ;
V_294 -> V_299 = V_290 -> V_49 ;
V_22 -> V_51 = F_47 ( V_22 -> V_51 ,
V_294 ) ;
V_22 -> V_52 = V_22 -> V_51 ;
}
}
if ( F_48 ( V_289 , V_290 , V_2 , V_3 ) < 0 )
return - 1 ;
}
while ( V_291 > 0 ) {
V_296 = V_290 -> V_288 - V_290 -> V_300 ;
if ( V_296 == 0 ) {
if ( V_137 ) {
V_22 -> V_53 = F_49 ( V_22 -> V_53 ) ;
if ( ! V_22 -> V_53 ) {
* V_2 = V_301 ;
return - 1 ;
}
V_294 = ( T_18 * ) V_22 -> V_53 -> V_255 ;
} else {
if ( V_1 -> V_43 != NULL ) {
V_294 = F_46 ( T_18 , 1 ) ;
V_294 -> V_298 = V_290 -> V_50 ;
V_294 -> V_299 = V_290 -> V_49 ;
V_22 -> V_52 = F_47 ( V_22 -> V_52 ,
V_294 ) ;
}
}
if ( F_48 ( V_289 , V_290 , V_2 , V_3 ) < 0 )
return - 1 ;
V_296 = V_290 -> V_288 - V_290 -> V_300 ;
}
V_295 = V_291 ;
if ( V_295 > V_296 )
V_295 = V_296 ;
memcpy ( V_293 , & V_290 -> V_48 [ V_290 -> V_300 ] ,
V_295 ) ;
V_291 -= V_295 ;
V_292 += V_295 ;
V_293 += V_295 ;
V_290 -> V_300 += V_295 ;
V_290 -> V_49 += V_295 ;
}
return V_292 ;
}
static int
F_48 ( T_16 V_289 , T_17 * V_290 , int * V_2 ,
T_2 * * V_3 )
{
int V_302 ;
T_15 V_303 ;
unsigned short V_304 ;
T_6 V_305 ;
T_8 V_306 ;
unsigned char * V_307 ;
int V_308 ;
V_23 = V_24 ;
V_303 = F_4 ( & V_304 , 2 , V_289 ) ;
if ( 2 != V_303 ) {
* V_2 = F_5 ( V_289 , V_3 ) ;
return - 1 ;
}
V_290 -> V_50 += 2 ;
V_305 = F_6 ( & V_304 ) ;
if ( V_305 < 0 ) {
V_302 = - V_305 ;
V_306 = TRUE ;
} else {
V_302 = V_305 ;
V_306 = FALSE ;
}
V_307 = ( unsigned char * ) F_11 ( V_309 ) ;
V_23 = V_24 ;
V_303 = F_4 ( V_307 , V_302 , V_289 ) ;
if ( ( T_15 ) V_302 != V_303 ) {
* V_2 = F_5 ( V_289 , V_3 ) ;
F_35 ( V_307 ) ;
return - 1 ;
}
V_290 -> V_50 += V_302 ;
if ( V_306 ) {
memcpy ( V_290 -> V_48 , V_307 , V_302 ) ;
V_308 = V_302 ;
} else {
V_308 = F_44 ( V_307 , V_302 ,
V_290 -> V_48 , V_297 , V_2 ) ;
if ( V_308 < 0 ) {
F_35 ( V_307 ) ;
return - 1 ;
}
}
F_35 ( V_307 ) ;
V_290 -> V_300 = 0 ;
V_290 -> V_288 = V_308 ;
return 0 ;
}
static T_8
F_23 ( T_1 * V_1 , T_4 V_310 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
char * V_48 ;
unsigned int V_311 ;
V_22 = ( T_5 * ) V_1 -> V_45 ;
if ( V_1 -> V_34 == V_36 ) {
V_22 -> V_47 . V_49 += V_310 ;
if ( F_50 ( V_1 -> V_25 , V_310 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
F_45 ( V_310 >= 0 ) ;
V_48 = ( char * ) F_11 ( V_309 ) ;
while ( V_310 != 0 ) {
if ( V_310 > V_309 )
V_311 = V_309 ;
else
V_311 = ( unsigned int ) V_310 ;
if ( F_31 ( V_48 , V_311 , V_1 , FALSE , V_2 , V_3 ) < 0 ) {
F_35 ( V_48 ) ;
return FALSE ;
}
V_310 -= V_311 ;
}
F_35 ( V_48 ) ;
return TRUE ;
}
static T_8
F_29 ( T_1 * V_1 , T_4 V_283 , int * V_2 , T_2 * * V_3 )
{
T_5 * V_22 ;
T_4 V_310 ;
T_19 * V_312 , * V_313 ;
T_18 * V_314 , * V_315 ;
V_22 = ( T_5 * ) V_1 -> V_45 ;
if ( V_1 -> V_34 == V_36 ) {
if ( F_10 ( V_1 -> V_43 , V_283 , V_44 , V_2 ) == - 1 )
return FALSE ;
return TRUE ;
}
V_310 = V_283 - V_22 -> rand . V_49 ;
V_312 = NULL ;
if ( V_310 > 0 ) {
if ( ( T_15 ) ( V_22 -> rand . V_300 + V_310 ) >= V_22 -> rand . V_288 ) {
V_312 = F_49 ( V_22 -> V_53 ) ;
while ( V_312 ) {
V_313 = F_49 ( V_312 ) ;
if ( V_313 == NULL ) {
break;
}
V_314 = ( T_18 * ) V_313 -> V_255 ;
if ( V_314 -> V_299 > V_283 )
break;
V_312 = V_313 ;
}
}
} else if ( V_310 < 0 ) {
if ( V_22 -> rand . V_300 + V_310 < 0 ) {
V_312 = F_51 ( V_22 -> V_53 ) ;
while ( V_312 ) {
V_315 = ( T_18 * ) V_312 -> V_255 ;
if ( V_315 -> V_299 <= V_283 )
break;
V_312 = F_51 ( V_312 ) ;
}
}
}
if ( V_312 != NULL ) {
V_315 = ( T_18 * ) V_312 -> V_255 ;
if ( F_10 ( V_1 -> V_43 , V_315 -> V_298 , V_44 , V_2 ) == - 1 )
return FALSE ;
V_22 -> V_53 = V_312 ;
V_22 -> rand . V_49 = V_315 -> V_299 ;
V_22 -> rand . V_50 = V_315 -> V_298 ;
if ( F_48 ( V_1 -> V_43 , & V_22 -> rand , V_2 , V_3 ) < 0 )
return FALSE ;
V_310 = V_283 - V_22 -> rand . V_49 ;
F_45 ( V_310 >= 0 && ( unsigned long ) V_310 < V_22 -> rand . V_288 ) ;
}
V_22 -> rand . V_300 += ( int ) V_310 ;
V_22 -> rand . V_49 += V_310 ;
return TRUE ;
}
