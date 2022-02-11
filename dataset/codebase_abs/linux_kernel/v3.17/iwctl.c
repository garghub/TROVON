struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
long V_5 ;
V_4 -> V_6 . V_7 = V_4 -> V_8 ;
#ifdef F_3
if ( V_4 -> V_9 . V_10 > 100 )
V_4 -> V_9 . V_10 = 100 ;
V_4 -> V_6 . V_11 . V_11 = ( unsigned char ) V_4 -> V_9 . V_10 ;
#else
V_4 -> V_6 . V_11 . V_11 = V_4 -> V_12 ;
#endif
F_4 ( V_4 , ( unsigned char ) ( V_4 -> V_13 ) , & V_5 ) ;
V_4 -> V_6 . V_11 . V_14 = V_5 ;
V_4 -> V_6 . V_11 . V_15 = 0 ;
V_4 -> V_6 . V_11 . V_16 = 1 ;
V_4 -> V_6 . V_17 . V_18 = 0 ;
V_4 -> V_6 . V_17 . V_19 = 0 ;
V_4 -> V_6 . V_17 . V_20 = 0 ;
V_4 -> V_6 . V_17 . V_21 = ( unsigned long ) V_4 -> V_9 . V_22 ;
V_4 -> V_6 . V_17 . V_23 = 0 ;
V_4 -> V_6 . V_24 . V_25 = 0 ;
return & V_4 -> V_6 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
void * V_28 ,
char * V_29 )
{
F_6 ( V_30 , V_31 L_1 ) ;
return 0 ;
}
int F_7 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
char * V_28 ,
char * V_29 )
{
strcpy ( V_28 , L_2 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
struct V_35 * V_36 = (struct V_35 * ) V_29 ;
unsigned char V_37 [ V_38 + V_39 + 1 ] ;
T_3 V_40 = NULL ;
F_6 ( V_30 , V_31 L_3 ) ;
if ( V_4 -> V_41 > 0 ) {
union V_42 V_43 ;
F_9 ( L_4 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
F_10 ( V_4 -> V_3 , V_44 , & V_43 , NULL ) ;
return 0 ;
}
F_11 ( & V_4 -> V_45 ) ;
F_12 ( ( void * ) V_4 , V_4 -> V_46 ) ;
if ( V_28 -> V_47 == sizeof( struct V_35 ) ) {
if ( V_28 -> V_48 & V_49 ) {
memset ( V_37 , 0 , V_38 + V_39 + 1 ) ;
V_40 = ( T_3 ) V_37 ;
V_40 -> V_50 = V_51 ;
memcpy ( V_40 -> V_52 , V_36 -> V_53 , ( int ) V_36 -> V_54 ) ;
if ( V_40 -> V_52 [ V_36 -> V_54 - 1 ] == '\0' ) {
if ( V_36 -> V_54 > 0 )
V_40 -> V_55 = V_36 -> V_54 - 1 ;
} else
V_40 -> V_55 = V_36 -> V_54 ;
V_33 -> V_56 = V_57 ;
F_9 ( L_5 , ( ( T_3 ) V_37 ) -> V_52 ,
( ( T_3 ) V_37 ) -> V_55 ) ;
F_13 ( ( void * ) V_4 , V_58 , V_37 ) ;
F_14 ( & V_4 -> V_45 ) ;
return 0 ;
} else if ( V_36 -> V_59 == V_60 ) {
V_33 -> V_56 = V_57 ;
}
} else {
V_33 -> V_56 = V_61 ;
}
V_33 -> V_56 = V_57 ;
F_13 ( ( void * ) V_4 , V_58 , NULL ) ;
F_14 ( & V_4 -> V_45 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
int V_62 , V_63 , V_64 ;
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
T_4 V_65 ;
T_3 V_40 ;
T_5 V_66 , V_67 ;
char * V_68 = V_29 ;
char * V_69 = V_29 + V_70 ;
char * V_71 = NULL ;
struct V_72 V_73 ;
long V_5 ;
char V_74 [ V_75 * 2 + 30 ] ;
F_6 ( V_30 , V_31 L_6 ) ;
if ( V_33 -> V_76 == V_77 ) {
return - V_78 ;
}
V_65 = & ( V_33 -> V_79 [ 0 ] ) ;
for ( V_62 = 0 , V_63 = 0 ; V_63 < V_80 ; V_63 ++ ) {
if ( V_68 >= V_69 )
break;
V_65 = & ( V_33 -> V_79 [ V_63 ] ) ;
if ( V_65 -> V_81 ) {
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_83 ;
V_73 . V_84 . V_85 . V_86 = V_87 ;
memcpy ( V_73 . V_84 . V_85 . V_88 , V_65 -> V_89 , V_90 ) ;
V_68 = F_16 ( V_27 , V_68 , V_69 , & V_73 , V_91 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_92 ;
V_40 = ( T_3 ) V_65 -> V_52 ;
V_73 . V_84 . V_93 . V_47 = V_40 -> V_55 ;
V_73 . V_84 . V_93 . V_48 = 1 ;
V_68 = F_17 ( V_27 , V_68 , V_69 , & V_73 , V_40 -> V_52 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_94 ;
if ( F_18 ( V_65 -> V_95 ) )
V_73 . V_84 . V_96 = V_97 ;
else
V_73 . V_84 . V_96 = V_98 ;
V_73 . V_55 = V_99 ;
V_68 = F_16 ( V_27 , V_68 , V_69 , & V_73 , V_99 ) ;
V_66 = ( T_5 ) V_65 -> V_100 ;
V_67 = ( T_5 ) V_65 -> V_101 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_102 ;
V_73 . V_84 . V_103 . V_104 = V_65 -> V_105 ;
V_73 . V_84 . V_103 . V_106 = 0 ;
V_73 . V_84 . V_103 . V_107 = 0 ;
V_68 = F_16 ( V_27 , V_68 , V_69 , & V_73 , V_108 ) ;
{
int V_109 = ( int ) V_65 -> V_105 - 1 ;
if ( V_109 < 0 ) V_109 = 0 ;
V_73 . V_84 . V_103 . V_104 = V_110 [ V_109 ] * 100000 ;
V_73 . V_84 . V_103 . V_106 = 1 ;
}
V_68 = F_16 ( V_27 , V_68 , V_69 , & V_73 , V_108 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_111 ;
F_4 ( V_4 , ( unsigned char ) ( V_65 -> V_112 ) , & V_5 ) ;
V_73 . V_84 . V_11 . V_14 = V_5 ;
V_73 . V_84 . V_11 . V_15 = 0 ;
if ( - V_5 < 50 )
V_73 . V_84 . V_11 . V_11 = 100 ;
else if ( - V_5 > 90 )
V_73 . V_84 . V_11 . V_11 = 0 ;
else
V_73 . V_84 . V_11 . V_11 = ( 40 - ( - V_5 - 50 ) ) * 100 / 40 ;
V_73 . V_84 . V_11 . V_16 = 7 ;
V_68 = F_16 ( V_27 , V_68 , V_69 , & V_73 , V_113 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_114 ;
V_73 . V_84 . V_93 . V_47 = 0 ;
if ( F_19 ( V_65 -> V_95 ) )
V_73 . V_84 . V_93 . V_48 = V_115 | V_116 ;
else
V_73 . V_84 . V_93 . V_48 = V_117 ;
V_68 = F_17 ( V_27 , V_68 , V_69 , & V_73 , V_40 -> V_52 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_118 ;
V_73 . V_84 . V_119 . V_120 = V_73 . V_84 . V_119 . V_121 = 0 ;
V_71 = V_68 + V_122 ;
for ( V_64 = 0 ; V_64 < 12 ; V_64 ++ ) {
if ( V_66 -> V_123 [ V_64 ] == 0 )
break;
V_73 . V_84 . V_119 . V_124 = ( ( V_66 -> V_123 [ V_64 ] & 0x7f ) * 500000 ) ;
V_71 = F_20 ( V_27 , V_68 , V_71 , V_69 , & V_73 , V_125 ) ;
}
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ ) {
if ( V_67 -> V_123 [ V_64 ] == 0 )
break;
V_73 . V_84 . V_119 . V_124 = ( ( V_67 -> V_123 [ V_64 ] & 0x7f ) * 500000 ) ;
V_71 = F_20 ( V_27 , V_68 , V_71 , V_69 , & V_73 , V_125 ) ;
}
if ( ( V_71 - V_68 ) > V_122 )
V_68 = V_71 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_126 ;
sprintf ( V_74 , L_7 , V_65 -> V_127 ) ;
V_73 . V_84 . V_93 . V_47 = strlen ( V_74 ) ;
V_68 = F_17 ( V_27 , V_68 , V_69 , & V_73 , V_74 ) ;
if ( ( V_65 -> V_128 > 0 ) && ( V_65 -> V_128 <= V_75 ) ) {
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_129 ;
V_73 . V_84 . V_93 . V_47 = V_65 -> V_128 ;
V_68 = F_17 ( V_27 , V_68 , V_69 , & V_73 , V_65 -> V_130 ) ;
}
if ( ( V_65 -> V_131 > 0 ) && ( V_65 -> V_131 <= V_75 ) ) {
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_82 = V_129 ;
V_73 . V_84 . V_93 . V_47 = V_65 -> V_131 ;
V_68 = F_17 ( V_27 , V_68 , V_69 , & V_73 , V_65 -> V_132 ) ;
}
}
}
V_28 -> V_47 = V_68 - V_29 ;
return 0 ;
}
int F_21 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_133 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_134 = 0 ;
F_6 ( V_30 , V_31 L_8 ) ;
if ( ( V_28 -> V_106 == 1 ) &&
( V_28 -> V_104 >= ( int ) 2.412e8 ) &&
( V_28 -> V_104 <= ( int ) 2.487e8 ) ) {
int V_109 = V_28 -> V_104 / 100000 ;
int V_135 = 0 ;
while ( ( V_135 < 14 ) && ( V_109 != V_110 [ V_135 ] ) )
V_135 ++ ;
V_28 -> V_106 = 0 ;
V_28 -> V_104 = V_135 + 1 ;
}
if ( ( V_28 -> V_104 > 14 ) || ( V_28 -> V_106 > 0 ) )
V_134 = - V_136 ;
else {
int V_137 = V_28 -> V_104 ;
if ( ( V_137 < 1 ) || ( V_137 > 14 ) ) {
F_6 ( V_30 , V_31 L_9 , V_3 -> V_138 , V_28 -> V_104 ) ;
V_134 = - V_139 ;
} else {
F_6 ( V_30 , V_31 L_10 , V_137 ) ;
V_4 -> V_105 = V_137 ;
V_4 -> V_140 = true ;
}
}
return V_134 ;
}
int F_22 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_133 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
F_6 ( V_30 , V_31 L_11 ) ;
#ifdef F_23
V_28 -> V_104 = ( int ) V_33 -> V_141 ;
V_28 -> V_106 = 0 ;
#else
{
int V_109 = ( int ) V_33 -> V_141 - 1 ;
if ( V_109 < 0 )
V_109 = 0 ;
V_28 -> V_104 = V_110 [ V_109 ] * 100000 ;
V_28 -> V_106 = 1 ;
}
#endif
return 0 ;
}
int F_24 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
T_6 * V_142 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_134 = 0 ;
F_6 ( V_30 , V_31 L_12 ) ;
if ( V_33 -> V_143 == V_144 && V_4 -> V_145 ) {
F_6 ( V_30 , V_31 L_13 ) ;
return V_134 ;
}
switch ( * V_142 ) {
case V_98 :
if ( V_33 -> V_146 != V_147 ) {
V_33 -> V_146 = V_147 ;
if ( V_4 -> V_48 & V_148 )
V_4 -> V_140 = true ;
}
F_6 ( V_30 , V_31 L_14 ) ;
break;
case V_149 :
case V_97 :
if ( V_33 -> V_146 != V_150 ) {
V_33 -> V_146 = V_150 ;
if ( V_4 -> V_48 & V_148 )
V_4 -> V_140 = true ;
}
F_6 ( V_30 , V_31 L_15 ) ;
break;
case V_151 :
V_33 -> V_146 = V_150 ;
V_134 = - V_136 ;
break;
if ( V_33 -> V_146 != V_152 ) {
V_33 -> V_146 = V_152 ;
if ( V_4 -> V_48 & V_148 )
V_4 -> V_140 = true ;
}
F_6 ( V_30 , V_31 L_16 ) ;
break;
case V_153 :
V_33 -> V_146 = V_150 ;
V_134 = - V_136 ;
break;
default:
V_134 = - V_139 ;
}
return V_134 ;
}
int F_25 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
T_6 * V_142 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
F_6 ( V_30 , V_31 L_17 ) ;
switch ( V_33 -> V_146 ) {
case V_150 :
* V_142 = V_97 ;
break;
case V_147 :
* V_142 = V_98 ;
break;
case V_154 :
* V_142 = V_97 ;
break;
case V_152 :
* V_142 = V_151 ;
break;
default:
* V_142 = V_98 ;
}
return 0 ;
}
int F_26 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
struct V_155 * V_156 = (struct V_155 * ) V_29 ;
int V_107 , V_157 ;
unsigned char V_158 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
F_6 ( V_30 , V_31 L_18 ) ;
if ( V_28 -> V_159 ) {
V_28 -> V_47 = sizeof( struct V_155 ) ;
memset ( V_156 , 0 , sizeof( struct V_155 ) ) ;
V_156 -> V_160 = 0x0000 ;
V_156 -> V_161 = 0x0000 ;
V_156 -> V_162 = 14 ;
V_157 = 0 ;
for ( V_107 = 0 ; V_107 < 14 ; V_107 ++ ) {
V_156 -> V_103 [ V_157 ] . V_107 = V_107 + 1 ;
V_156 -> V_103 [ V_157 ] . V_104 = V_110 [ V_107 ] * 100000 ;
V_156 -> V_103 [ V_157 ++ ] . V_106 = 1 ;
}
V_156 -> V_163 = V_157 ;
#ifdef F_3
V_156 -> V_164 . V_11 = 100 ;
#else
V_156 -> V_164 . V_11 = 255 ;
#endif
V_156 -> V_164 . V_14 = 0 ;
V_156 -> V_164 . V_15 = 0 ;
V_156 -> V_165 = 255 ;
for ( V_107 = 0 ; V_107 < 13 ; V_107 ++ ) {
V_156 -> V_119 [ V_107 ] = V_158 [ V_107 ] * 500000 ;
if ( V_156 -> V_119 [ V_107 ] == 0 )
break;
}
V_156 -> V_166 = V_107 ;
if ( V_107 > 2 )
V_156 -> V_167 = 5 * 1000 * 1000 ;
else
V_156 -> V_167 = 1.5 * 1000 * 1000 ;
V_156 -> V_168 = 0 ;
V_156 -> V_169 = 2312 ;
V_156 -> V_170 = 256 ;
V_156 -> V_171 = 2312 ;
V_156 -> V_172 = 3 ;
V_156 -> V_173 [ 0 ] = 5 ;
V_156 -> V_173 [ 1 ] = 13 ;
V_156 -> V_173 [ 2 ] = 32 ;
V_156 -> V_174 = 4 ;
V_156 -> V_175 = V_176 | V_177 |
V_178 | V_179 ;
V_156 -> V_180 = 0 ;
V_156 -> V_181 = 1000000 ;
V_156 -> V_182 = 0 ;
V_156 -> V_183 = 1000000 ;
V_156 -> V_184 = V_185 ;
V_156 -> V_186 = V_187 ;
V_156 -> V_188 = V_185 | V_187 | V_189 ;
V_156 -> V_190 [ 0 ] = 100 ;
V_156 -> V_191 = 1 ;
V_156 -> V_192 = V_193 ;
V_156 -> V_194 = V_195 ;
V_156 -> V_196 = V_197 ;
V_156 -> V_198 = V_199 | V_200 ;
V_156 -> V_201 = V_199 ;
V_156 -> V_202 = V_200 ;
V_156 -> V_203 = 1 ;
V_156 -> V_204 = 65535 ;
V_156 -> V_205 = 1024 ;
V_156 -> V_206 = 65535 * 1024 ;
V_156 -> V_207 . V_11 = 6 ;
V_156 -> V_207 . V_14 = 176 ;
V_156 -> V_207 . V_15 = 0 ;
}
return 0 ;
}
int F_27 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_208 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_134 = 0 ;
unsigned char V_209 [ V_90 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_6 ( V_30 , V_31 L_19 ) ;
if ( V_33 -> V_76 == V_77 ) {
F_28 ( L_20 ) ;
}
if ( V_28 -> V_86 != V_87 )
V_134 = - V_139 ;
else {
memcpy ( V_33 -> V_210 , V_28 -> V_88 , 6 ) ;
if ( ( V_4 -> V_46 == true ) &&
( memcmp ( V_33 -> V_210 , V_33 -> V_211 , 6 ) == 0 ) ) {
return V_134 ;
}
if ( ( F_29 ( V_33 -> V_210 ) ) ||
( memcmp ( V_33 -> V_210 , V_209 , 6 ) == 0 ) ) {
F_9 ( L_21 ) ;
return V_134 ;
}
{
unsigned int V_62 , V_212 = 0 ;
for ( V_62 = 0 ; V_62 < V_80 ; V_62 ++ ) {
if ( V_33 -> V_79 [ V_62 ] . V_81 &&
F_30 ( V_33 -> V_79 [ V_62 ] . V_89 ,
V_33 -> V_210 ) ) {
V_212 ++ ;
}
}
if ( V_212 >= 2 ) {
F_9 ( L_22 ) ;
return V_134 ;
}
}
if ( V_4 -> V_48 & V_148 )
V_4 -> V_140 = true ;
}
return V_134 ;
}
int F_31 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_208 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
F_6 ( V_30 , V_31 L_23 ) ;
memcpy ( V_28 -> V_88 , V_33 -> V_211 , 6 ) ;
if ( ( V_4 -> V_46 == false ) && ( V_33 -> V_143 != V_144 ) )
memset ( V_28 -> V_88 , 0 , 6 ) ;
if ( V_33 -> V_143 == V_144 )
memcpy ( V_28 -> V_88 , V_33 -> V_211 , 6 ) ;
V_28 -> V_86 = V_87 ;
return 0 ;
}
int F_32 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
int V_62 , V_63 , V_134 = 0 ;
struct V_208 * V_213 = NULL ;
struct V_208 * V_214 = NULL ;
struct V_215 * V_11 = NULL ;
struct V_215 * V_216 = NULL ;
T_4 V_65 = NULL ;
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
F_6 ( V_30 , V_31 L_24 ) ;
if ( ! F_33 ( V_217 ) ) {
V_134 = - V_218 ;
goto exit;
}
if ( ! V_28 -> V_159 )
goto exit;
V_213 = F_34 ( V_219 , sizeof( struct V_208 ) , V_220 ) ;
if ( ! V_213 ) {
V_134 = - V_221 ;
goto exit;
}
V_11 = F_34 ( V_219 , sizeof( struct V_215 ) , V_220 ) ;
if ( ! V_11 ) {
V_134 = - V_221 ;
goto exit;
}
for ( V_62 = 0 , V_63 = 0 ; V_62 < V_80 ; V_62 ++ ) {
V_65 = & ( V_33 -> V_79 [ V_62 ] ) ;
if ( ! V_65 -> V_81 )
continue;
if ( V_63 >= V_219 )
break;
V_214 = & V_213 [ V_63 ] ;
V_216 = & V_11 [ V_63 ] ;
memcpy ( V_214 -> V_88 , V_65 -> V_89 , 6 ) ;
V_214 -> V_86 = V_87 ;
V_216 -> V_14 = V_65 -> V_112 ;
V_216 -> V_11 = 0 ;
V_216 -> V_15 = 0 ;
V_216 -> V_16 = 2 ;
V_63 ++ ;
}
V_28 -> V_48 = 1 ;
V_28 -> V_47 = V_63 ;
memcpy ( V_29 , V_213 , sizeof( struct V_208 ) * V_63 ) ;
memcpy ( V_29 + sizeof( struct V_208 ) * V_63 ,
V_11 ,
sizeof( struct V_215 ) * V_63 ) ;
exit:
F_35 ( V_213 ) ;
F_35 ( V_11 ) ;
return V_134 ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
T_3 V_40 ;
unsigned char V_55 ;
F_6 ( V_30 , V_31 L_25 ) ;
V_4 -> V_222 = false ;
if ( V_33 -> V_76 == V_77 ) {
F_28 ( L_26 ) ;
}
if ( V_28 -> V_48 == 0 ) {
memset ( V_33 -> V_223 , 0 , V_38 + V_39 + 1 ) ;
memset ( V_33 -> V_210 , 0xFF , 6 ) ;
F_9 ( L_27 ) ;
#ifdef F_37
return 0 ;
#endif
} else {
memset ( V_33 -> V_223 , 0 , V_38 + V_39 + 1 ) ;
V_40 = ( T_3 ) V_33 -> V_223 ;
V_40 -> V_50 = V_51 ;
memcpy ( V_40 -> V_52 , V_29 , V_28 -> V_47 ) ;
if ( V_40 -> V_52 [ V_28 -> V_47 - 1 ] == '\0' ) {
if ( V_28 -> V_47 > 0 )
V_40 -> V_55 = V_28 -> V_47 - 1 ;
} else
V_40 -> V_55 = V_28 -> V_47 ;
F_28 ( L_28 , V_40 -> V_52 ) ;
V_55 = ( V_40 -> V_55 > ( ( T_3 ) V_33 -> V_224 ) -> V_55 ) ? V_40 -> V_55 : ( ( T_3 ) V_33 -> V_224 ) -> V_55 ;
if ( ( V_4 -> V_46 == true ) &&
( memcmp ( V_40 -> V_52 , ( ( T_3 ) V_33 -> V_224 ) -> V_52 , V_55 ) == 0 ) )
return 0 ;
if ( V_40 -> V_55 == 0 ) {
memset ( V_33 -> V_210 , 0xFF , 6 ) ;
return 0 ;
}
#ifdef F_37
if ( V_4 -> V_225 == true ) {
{
T_4 V_226 = NULL ;
unsigned char V_227 [ V_38 + V_39 + 1 ] ;
unsigned int V_62 , V_212 = 0 ;
memcpy ( V_227 , V_33 -> V_223 , sizeof( V_227 ) ) ;
V_226 = F_38 ( V_4 ,
NULL ,
V_227 ,
V_33 -> V_228
) ;
if ( V_226 == NULL ) {
F_9 ( L_29 ) ;
F_39 ( ( void * ) V_4 ) ;
V_33 -> V_56 = V_61 ;
F_13 ( ( void * ) V_4 , V_58 , V_33 -> V_223 ) ;
F_13 ( ( void * ) V_4 , V_229 , V_33 -> V_223 ) ;
} else {
for ( V_62 = 0 ; V_62 < V_80 ; V_62 ++ ) {
if ( V_33 -> V_79 [ V_62 ] . V_81 &&
F_30 ( V_33 -> V_79 [ V_62 ] . V_89 ,
V_226 -> V_89 ) ) {
V_212 ++ ;
}
}
if ( V_212 >= 2 ) {
F_28 ( L_30 ) ;
F_39 ( ( void * ) V_4 ) ;
V_33 -> V_56 = V_57 ;
F_13 ( ( void * ) V_4 , V_58 , V_33 -> V_223 ) ;
F_13 ( ( void * ) V_4 , V_229 , V_33 -> V_223 ) ;
}
}
}
return 0 ;
}
#endif
F_6 ( V_30 , V_31 L_31 , V_40 -> V_52 ) ;
}
if ( V_4 -> V_48 & V_148 )
V_4 -> V_140 = true ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
T_3 V_40 ;
F_6 ( V_30 , V_31 L_32 ) ;
V_40 = ( T_3 ) V_33 -> V_224 ;
memcpy ( V_29 , V_40 -> V_52 , V_40 -> V_55 ) ;
V_29 [ V_40 -> V_55 ] = '\0' ;
V_28 -> V_47 = V_40 -> V_55 + 1 ;
V_28 -> V_47 = V_40 -> V_55 ;
V_28 -> V_48 = 1 ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_134 = 0 ;
T_7 V_231 = 0 ;
int V_107 ;
unsigned char V_158 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
F_6 ( V_30 , V_31 L_33 ) ;
if ( ! ( V_4 -> V_48 & V_148 ) ) {
V_134 = - V_139 ;
return V_134 ;
}
if ( ( V_28 -> V_124 < 13 ) &&
( V_28 -> V_124 >= 0 ) ) {
V_231 = V_28 -> V_124 ;
} else {
T_7 V_232 = ( T_7 ) ( V_28 -> V_124 / 500000 ) ;
for ( V_107 = 0 ; V_107 < 13 ; V_107 ++ ) {
if ( V_232 == V_158 [ V_107 ] ) {
V_231 = V_107 ;
break;
}
}
}
if ( V_28 -> V_124 == - 1 ) {
for ( V_107 = 0 ; V_107 < 13 ; V_107 ++ ) {
if ( V_158 [ V_107 ] == 0 )
break;
}
if ( V_107 != 0 )
V_231 = V_107 - 1 ;
}
if ( V_231 > 13 ) {
V_134 = - V_139 ;
return V_134 ;
}
if ( V_28 -> V_120 != 0 ) {
F_28 ( L_34 ) ;
V_4 -> V_233 = true ;
if ( ( V_4 -> V_234 == V_235 ) && ( V_231 > 3 ) ) {
V_4 -> V_236 = 3 ;
} else {
V_4 -> V_236 = V_231 ;
F_6 ( V_30 , V_31 L_35 , V_4 -> V_236 ) ;
}
} else {
V_4 -> V_233 = false ;
V_4 -> V_236 = 13 ;
F_28 ( L_36 ) ;
}
return V_134 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_37 ) ;
{
unsigned char V_158 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
int V_231 = 0 ;
if ( V_4 -> V_46 ) {
if ( V_4 -> V_233 == true ) {
if ( V_4 -> V_236 < 13 ) {
V_231 = V_158 [ V_4 -> V_236 ] ;
} else {
if ( V_4 -> V_234 == V_235 )
V_231 = 0x16 ;
if ( V_4 -> V_234 == V_237 )
V_231 = 0x6C ;
if ( V_4 -> V_234 == V_238 )
V_231 = 0x6C ;
}
} else {
V_231 = V_158 [ V_239 ] ;
}
} else V_231 = 0 ;
V_28 -> V_124 = V_231 * 500000 ;
if ( V_4 -> V_233 == true )
V_28 -> V_120 = true ;
}
return 0 ;
}
int F_43 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_134 = 0 ;
F_6 ( V_30 , V_31 L_38 ) ;
{
int V_240 = V_28 -> V_124 ;
if ( V_28 -> V_121 )
V_240 = 2312 ;
if ( ( V_240 < 0 ) || ( V_240 > 2312 ) )
V_134 = - V_139 ;
else
V_4 -> V_241 = V_240 ;
}
return 0 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_39 ) ;
V_28 -> V_124 = V_4 -> V_241 ;
V_28 -> V_121 = ( V_28 -> V_124 >= 2312 ) ;
V_28 -> V_120 = 1 ;
return 0 ;
}
int F_45 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_134 = 0 ;
int V_242 = V_28 -> V_124 ;
F_6 ( V_30 , V_31 L_40 ) ;
if ( V_28 -> V_121 )
V_242 = 2312 ;
if ( ( V_242 < 256 ) || ( V_242 > 2312 ) ) {
V_134 = - V_139 ;
} else {
V_242 &= ~ 0x1 ;
V_4 -> V_243 = ( V_244 ) V_242 ;
}
return V_134 ;
}
int F_46 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_41 ) ;
V_28 -> V_124 = V_4 -> V_243 ;
V_28 -> V_121 = ( V_28 -> V_124 >= 2312 ) ;
V_28 -> V_120 = 1 ;
return 0 ;
}
int F_47 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_134 = 0 ;
F_6 ( V_30 , V_31 L_42 ) ;
if ( V_28 -> V_121 ) {
V_134 = - V_139 ;
return V_134 ;
}
if ( V_28 -> V_48 & V_199 ) {
if ( V_28 -> V_48 & V_245 )
V_4 -> V_246 = V_28 -> V_124 ;
else if ( V_28 -> V_48 & V_247 )
V_4 -> V_248 = V_28 -> V_124 ;
else {
V_4 -> V_248 = V_28 -> V_124 ;
V_4 -> V_246 = V_28 -> V_124 ;
}
}
if ( V_28 -> V_48 & V_200 )
V_4 -> V_249 = V_28 -> V_124 ;
return V_134 ;
}
int F_48 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_43 ) ;
V_28 -> V_121 = 0 ;
if ( ( V_28 -> V_48 & V_250 ) == V_200 ) {
V_28 -> V_48 = V_200 ;
V_28 -> V_124 = ( int ) V_4 -> V_249 ;
} else if ( ( V_28 -> V_48 & V_245 ) ) {
V_28 -> V_48 = V_199 | V_245 ;
V_28 -> V_124 = ( int ) V_4 -> V_246 ;
} else {
V_28 -> V_48 = V_199 ;
V_28 -> V_124 = ( int ) V_4 -> V_248 ;
if ( ( int ) V_4 -> V_248 != ( int ) V_4 -> V_246 )
V_28 -> V_48 |= V_247 ;
}
return 0 ;
}
int F_49 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
unsigned long V_251 = ( unsigned long ) ( V_28 -> V_48 & V_252 ) ;
int V_62 , V_253 , V_134 = 0 ;
int V_254 = ( V_28 -> V_48 & V_252 ) ;
T_8 V_255 ;
F_6 ( V_30 , V_31 L_44 ) ;
if ( ( V_28 -> V_48 & V_117 ) == 0 ) {
if ( V_251 > V_256 ) {
V_134 = - V_139 ;
return V_134 ;
}
if ( V_251 < 1 && ( ( V_28 -> V_48 & V_116 ) == 0 ) ) {
if ( V_4 -> V_257 < V_256 )
V_251 = V_4 -> V_257 ;
else
V_251 = 0 ;
} else {
V_251 -- ;
}
if ( V_28 -> V_47 > V_258 ) {
V_134 = - V_139 ;
return V_134 ;
}
if ( V_28 -> V_47 > 0 ) {
if ( V_28 -> V_47 == V_258 ) {
F_6 ( V_30 , V_31 L_45 ) ;
} else if ( V_28 -> V_47 == V_259 ) {
F_6 ( V_30 , V_31 L_46 ) ;
} else if ( V_28 -> V_47 == V_260 ) {
F_6 ( V_30 , V_31 L_47 , ( int ) V_251 ) ;
} else {
V_134 = - V_139 ;
return V_134 ;
}
memset ( V_4 -> V_261 , 0 , V_258 ) ;
memcpy ( V_4 -> V_261 , V_29 , V_28 -> V_47 ) ;
F_6 ( V_30 , V_31 L_48 ) ;
for ( V_62 = 0 ; V_62 < V_28 -> V_47 ; V_62 ++ )
F_6 ( V_30 , V_31 L_49 , V_4 -> V_261 [ V_62 ] ) ;
if ( V_4 -> V_48 & V_148 ) {
F_11 ( & V_4 -> V_45 ) ;
F_50 ( & ( V_4 -> V_262 ) ,
( unsigned long ) ( V_251 | ( 1 << 31 ) ) ,
V_28 -> V_47 ,
NULL ,
V_4 -> V_261 ,
V_263 ,
V_4 -> V_264 ,
V_4 -> V_265
) ;
F_14 ( & V_4 -> V_45 ) ;
}
V_4 -> V_257 = ( unsigned char ) V_251 ;
V_4 -> V_266 = V_28 -> V_47 ;
V_4 -> V_267 = true ;
V_4 -> V_268 = true ;
V_4 -> V_269 = V_270 ;
} else if ( V_254 > 0 ) {
if ( V_4 -> V_268 == false ) {
V_134 = - V_139 ;
return V_134 ;
}
F_6 ( V_30 , V_31 L_50 ) ;
V_255 = & ( V_4 -> V_262 . V_271 [ V_272 - 1 ] ) ;
if ( V_255 -> V_273 [ ( unsigned char ) V_251 ] . V_266 == 0 ) {
F_6 ( V_30 , V_31 L_51 ) ;
V_134 = - V_139 ;
return V_134 ;
}
V_4 -> V_257 = ( unsigned char ) V_251 ;
V_255 -> V_274 = V_251 | ( 1 << 31 ) ;
V_255 -> V_273 [ ( unsigned char ) V_251 ] . V_251 = V_251 | ( 1 << 31 ) ;
}
} else {
F_6 ( V_30 , V_31 L_52 ) ;
if ( V_4 -> V_268 == false )
return 0 ;
V_33 -> V_275 = false ;
V_4 -> V_268 = false ;
V_4 -> V_269 = V_276 ;
if ( V_4 -> V_48 & V_148 ) {
F_11 ( & V_4 -> V_45 ) ;
for ( V_253 = 0 ; V_253 < V_272 ; V_253 ++ )
F_51 ( V_4 -> V_264 , V_253 ) ;
F_14 ( & V_4 -> V_45 ) ;
}
}
if ( V_28 -> V_48 & V_277 ) {
F_6 ( V_30 , V_31 L_53 ) ;
V_33 -> V_275 = true ;
}
if ( V_28 -> V_48 & V_278 ) {
F_6 ( V_30 , V_31 L_54 ) ;
V_33 -> V_275 = false ;
}
return V_134 ;
}
int F_52 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
char V_261 [ V_258 ] ;
unsigned int V_254 = ( unsigned int ) ( V_28 -> V_48 & V_252 ) ;
T_9 V_279 = NULL ;
F_6 ( V_30 , V_31 L_55 ) ;
if ( V_254 > V_256 )
return - V_139 ;
if ( V_254 < 1 ) {
if ( V_4 -> V_257 < V_256 )
V_254 = V_4 -> V_257 ;
else
V_254 = 0 ;
} else {
V_254 -- ;
}
memset ( V_261 , 0 , V_258 ) ;
V_28 -> V_48 = V_116 ;
if ( V_4 -> V_268 )
V_28 -> V_48 |= V_115 ;
else
V_28 -> V_48 |= V_117 ;
if ( V_33 -> V_275 )
V_28 -> V_48 |= V_277 ;
else
V_28 -> V_48 |= V_278 ;
V_28 -> V_47 = 0 ;
if ( ( V_254 == 0 ) && ( V_4 -> V_269 == V_280 ||
V_4 -> V_269 == V_281 ) ) {
if ( F_53 ( & ( V_4 -> V_262 ) , V_33 -> V_211 , 0xffffffff , & V_279 ) ) {
V_28 -> V_47 = V_279 -> V_266 ;
memcpy ( V_261 , V_279 -> V_261 , V_279 -> V_266 ) ;
memcpy ( V_29 , V_261 , V_258 ) ;
}
} else if ( F_53 ( & ( V_4 -> V_262 ) , V_4 -> V_282 , ( unsigned char ) V_254 , & V_279 ) ) {
V_28 -> V_47 = V_279 -> V_266 ;
memcpy ( V_261 , V_279 -> V_261 , V_279 -> V_266 ) ;
memcpy ( V_29 , V_261 , V_258 ) ;
}
V_28 -> V_48 |= V_254 + 1 ;
return 0 ;
}
int F_54 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_134 = 0 ;
F_6 ( V_30 , V_31 L_56 ) ;
if ( ! ( V_4 -> V_48 & V_148 ) ) {
V_134 = - V_139 ;
return V_134 ;
}
if ( V_28 -> V_121 ) {
V_4 -> V_283 = V_284 ;
F_55 ( V_4 ) ;
return V_134 ;
}
if ( ( V_28 -> V_48 & V_285 ) == V_187 ) {
V_4 -> V_283 = V_286 ;
F_56 ( ( void * ) V_4 , V_33 -> V_287 ) ;
} else if ( ( V_28 -> V_48 & V_285 ) == V_185 ) {
V_4 -> V_283 = V_286 ;
F_56 ( ( void * ) V_4 , V_33 -> V_287 ) ;
}
switch ( V_28 -> V_48 & V_288 ) {
case V_289 :
F_6 ( V_30 , V_31 L_57 ) ;
V_134 = - V_139 ;
break;
case V_189 :
F_6 ( V_30 , V_31 L_58 ) ;
V_134 = - V_139 ;
case V_290 :
F_6 ( V_30 , V_31 L_59 ) ;
break;
default:
V_134 = - V_139 ;
}
return V_134 ;
}
int F_57 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_96 = V_4 -> V_283 ;
F_6 ( V_30 , V_31 L_60 ) ;
V_28 -> V_121 = ( V_96 == V_284 ) ;
if ( V_28 -> V_121 )
return 0 ;
if ( ( V_28 -> V_48 & V_285 ) == V_187 ) {
V_28 -> V_124 = ( int ) ( ( V_33 -> V_287 * V_33 -> V_291 ) << 10 ) ;
V_28 -> V_48 = V_187 ;
} else {
V_28 -> V_124 = ( int ) ( ( V_33 -> V_287 * V_33 -> V_291 ) << 10 ) ;
V_28 -> V_48 = V_185 ;
}
V_28 -> V_48 |= V_189 ;
return 0 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
long V_5 ;
F_6 ( V_30 , V_31 L_61 ) ;
if ( V_4 -> V_46 == true ) {
F_4 ( V_4 , ( unsigned char ) ( V_4 -> V_13 ) , & V_5 ) ;
V_28 -> V_124 = V_5 ;
} else {
V_28 -> V_124 = 0 ;
}
V_28 -> V_121 = ( V_28 -> V_124 == 0 ) ;
V_28 -> V_120 = 1 ;
return 0 ;
}
int F_59 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_292 = 0 ;
static int V_293 = 0 ;
static int V_294 = 0 ;
F_6 ( V_30 , V_31 L_62 ) ;
switch ( V_28 -> V_48 & V_295 ) {
case V_296 :
V_293 = V_28 -> V_124 ;
if ( V_28 -> V_124 == V_297 )
F_9 ( L_63 ) ;
else if ( V_28 -> V_124 == V_298 )
F_9 ( L_64 ) ;
else
F_9 ( L_65 ) ;
break;
case V_299 :
V_294 = V_28 -> V_124 ;
if ( V_294 == V_300 )
V_4 -> V_269 = V_281 ;
else if ( V_294 == V_301 )
V_4 -> V_269 = V_280 ;
else if ( V_294 == V_302 || V_294 == V_303 )
V_4 -> V_269 = V_270 ;
else if ( V_294 == V_304 )
;
else
V_4 -> V_269 = V_276 ;
break;
case V_305 :
if ( V_293 == V_297 )
break;
if ( V_294 == V_304 ) {
if ( V_28 -> V_124 == V_300 )
V_4 -> V_269 = V_281 ;
else
V_4 -> V_269 = V_280 ;
}
break;
case V_306 :
if ( V_293 == V_307 ) {
if ( V_28 -> V_124 == V_308 )
V_33 -> V_309 = V_310 ;
else
V_33 -> V_309 = V_311 ;
} else if ( V_293 == V_298 ) {
if ( V_28 -> V_124 == 0 )
V_33 -> V_309 = V_312 ;
else if ( V_28 -> V_124 == V_308 )
V_33 -> V_309 = V_313 ;
else
V_33 -> V_309 = V_314 ;
}
break;
case V_315 :
break;
case V_316 :
break;
case V_317 :
if ( V_28 -> V_124 == V_318 )
V_33 -> V_275 = false ;
else if ( V_28 -> V_124 == V_319 )
V_33 -> V_275 = true ;
break;
case V_320 :
break;
case V_321 :
break;
case V_322 :
V_292 = - V_136 ;
break;
case V_323 :
V_4 -> V_268 = ! ! V_28 -> V_124 ;
if ( V_4 -> V_268 == false ) {
V_293 = 0 ;
V_294 = 0 ;
V_4 -> V_269 = V_276 ;
V_33 -> V_275 = false ;
V_33 -> V_309 = false ;
}
break;
default:
V_292 = - V_136 ;
break;
}
return V_292 ;
}
int F_60 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_230 * V_28 ,
char * V_29 )
{
return - V_136 ;
}
int F_61 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char T_10 * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_292 = 0 ;
char V_47 ;
if ( V_28 -> V_47 ) {
if ( V_28 -> V_47 < 2 )
return - V_139 ;
V_292 = F_62 ( V_47 , V_29 + 1 ) ;
if ( V_292 )
return V_292 ;
if ( V_47 + 2 != V_28 -> V_47 )
return - V_139 ;
if ( V_28 -> V_47 > V_75 ) {
V_292 = - V_221 ;
goto V_324;
}
memset ( V_33 -> V_325 , 0 , V_75 ) ;
if ( F_63 ( V_33 -> V_325 , V_29 , V_28 -> V_47 ) ) {
V_292 = - V_326 ;
goto V_324;
}
V_33 -> V_327 = V_28 -> V_47 ;
} else {
memset ( V_33 -> V_325 , 0 , V_75 ) ;
V_33 -> V_327 = 0 ;
}
V_324:
return V_292 ;
}
int F_64 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char T_10 * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
int V_292 = 0 ;
int V_328 = V_28 -> V_47 ;
V_28 -> V_47 = 0 ;
if ( V_33 -> V_327 > 0 ) {
V_28 -> V_47 = V_33 -> V_327 ;
if ( V_33 -> V_327 <= V_328 ) {
if ( F_65 ( V_29 , V_33 -> V_325 , V_33 -> V_327 ) )
V_292 = - V_326 ;
} else {
V_292 = - V_329 ;
}
}
return V_292 ;
}
int F_66 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
struct V_330 * V_331 = (struct V_330 * ) V_29 ;
struct V_332 * V_333 = NULL ;
enum V_334 V_335 ;
T_7 V_336 [ 6 ] ;
int V_337 , V_338 = 0 ;
T_7 V_339 [ V_340 ] ;
T_7 V_341 [ 64 ] ;
T_11 V_342 = 0 , V_343 = 0 ;
T_7 V_344 [ 64 ] ;
int V_292 = 0 ;
F_9 ( L_66 ) ;
V_333 = F_67 ( sizeof( * V_333 ) , V_220 ) ;
if ( V_333 == NULL )
return - V_221 ;
switch ( V_331 -> V_345 ) {
case V_346 :
V_335 = V_347 ;
break;
case V_348 :
V_335 = V_349 ;
break;
case V_350 :
V_335 = V_351 ;
break;
case V_352 :
V_335 = V_353 ;
break;
default:
F_9 ( L_67 , V_331 -> V_345 ) ;
V_292 = - V_221 ;
goto error;
}
memcpy ( V_336 , V_331 -> V_336 . V_88 , V_354 ) ;
V_337 = ( V_28 -> V_48 & V_252 ) - 1 ;
if ( V_331 -> V_355 & V_356 )
V_338 = 1 ;
if ( V_331 -> V_355 & V_357 ) {
V_342 = V_340 ;
memcpy ( V_339 , V_331 -> V_358 , V_342 ) ;
}
if ( V_331 -> V_343 ) {
V_343 = V_331 -> V_343 ;
memcpy ( V_341 , & V_331 -> V_341 [ 0 ] , V_343 ) ;
}
memset ( V_344 , 0 , 64 ) ;
if ( V_343 > 0 ) {
memcpy ( V_344 , V_341 , V_343 ) ;
if ( V_343 == 32 ) {
memcpy ( & V_344 [ 16 ] , & V_341 [ 24 ] , 8 ) ;
memcpy ( & V_344 [ 24 ] , & V_341 [ 16 ] , 8 ) ;
}
}
memcpy ( V_333 -> V_336 , V_336 , V_354 ) ;
V_333 -> V_84 . V_359 . V_335 = ( int ) V_335 ;
V_333 -> V_84 . V_359 . V_338 = V_338 ;
V_333 -> V_84 . V_359 . V_360 = V_337 ;
V_333 -> V_84 . V_359 . V_343 = V_343 ;
V_333 -> V_84 . V_359 . V_341 = ( T_7 * ) V_344 ;
V_333 -> V_84 . V_359 . V_339 = ( T_7 * ) V_339 ;
V_333 -> V_84 . V_359 . V_342 = V_342 ;
if ( V_333 -> V_84 . V_359 . V_335 == V_347 ) {
if ( V_333 -> V_84 . V_359 . V_360 == 0 )
V_4 -> V_361 ++ ;
if ( ( V_4 -> V_361 == 1 ) && ( V_333 -> V_84 . V_359 . V_360 == 1 ) )
V_4 -> V_361 ++ ;
if ( ( V_4 -> V_361 == 2 ) && ( V_333 -> V_84 . V_359 . V_360 == 2 ) )
V_4 -> V_361 ++ ;
if ( ( V_4 -> V_361 == 3 ) && ( V_333 -> V_84 . V_359 . V_360 == 3 ) )
V_4 -> V_361 ++ ;
}
if ( V_4 -> V_361 == 4 ) {
F_28 ( L_68 ) ;
V_4 -> V_361 = 0 ;
V_4 -> V_225 = true ;
}
F_11 ( & V_4 -> V_45 ) ;
V_292 = F_68 ( V_4 , V_333 , true ) ;
F_14 ( & V_4 -> V_45 ) ;
error:
F_35 ( V_333 ) ;
return V_292 ;
}
int F_69 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
return - V_136 ;
}
int F_70 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char T_10 * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_33 = & ( V_4 -> V_34 ) ;
struct V_362 V_363 ;
int V_292 = 0 ;
V_292 = F_63 ( & V_363 , V_29 , sizeof( V_363 ) ) ;
if ( V_292 )
return - V_326 ;
if ( memcmp ( V_33 -> V_211 , V_363 . V_336 . V_88 , V_354 ) ) {
V_292 = - V_139 ;
return V_292 ;
}
switch ( V_363 . V_82 ) {
case V_364 :
break;
case V_365 :
if ( V_4 -> V_46 == true ) {
F_28 ( L_69 ) ;
memset ( V_33 -> V_210 , 0xFF , 6 ) ;
F_71 ( & V_4 -> V_262 , V_4 -> V_264 ) ;
F_13 ( ( void * ) V_4 , V_366 , NULL ) ;
}
break;
default:
V_292 = - V_136 ;
}
return V_292 ;
}
