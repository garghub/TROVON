struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
long V_6 ;
V_5 -> V_7 . V_8 = V_5 -> V_9 ;
#ifdef F_3
if ( V_5 -> V_10 . V_11 > 100 )
V_5 -> V_10 . V_11 = 100 ;
V_5 -> V_7 . V_12 . V_12 = ( unsigned char ) V_5 -> V_10 . V_11 ;
#else
V_5 -> V_7 . V_12 . V_12 = V_5 -> V_13 ;
#endif
F_4 ( V_5 , ( unsigned char ) ( V_5 -> V_14 ) , & V_6 ) ;
V_5 -> V_7 . V_12 . V_15 = V_6 ;
V_5 -> V_7 . V_12 . V_16 = 0 ;
V_5 -> V_7 . V_12 . V_17 = 1 ;
V_5 -> V_7 . V_18 . V_19 = 0 ;
V_5 -> V_7 . V_18 . V_20 = 0 ;
V_5 -> V_7 . V_18 . V_21 = 0 ;
V_5 -> V_7 . V_18 . V_22 = ( unsigned long ) V_5 -> V_10 . V_23 ;
V_5 -> V_7 . V_18 . V_24 = 0 ;
V_5 -> V_7 . V_25 . V_26 = 0 ;
return & V_5 -> V_7 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
void * V_29 ,
char * V_30 )
{
F_6 ( L_1 ) ;
return 0 ;
}
int F_7 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
char * V_29 ,
char * V_30 )
{
strcpy ( V_29 , L_2 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
struct V_34 * V_35 = (struct V_34 * ) V_30 ;
unsigned char V_36 [ V_37 + V_38 + 1 ] ;
T_2 V_39 = NULL ;
F_6 ( L_3 ) ;
if ( V_5 -> V_40 > 0 ) {
union V_41 V_42 ;
F_9 ( L_4 ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
F_10 ( V_5 -> V_3 , V_43 , & V_42 , NULL ) ;
return 0 ;
}
F_11 ( & V_5 -> V_44 ) ;
F_12 ( ( void * ) V_5 , V_5 -> V_45 ) ;
if ( V_29 -> V_46 == sizeof( struct V_34 ) ) {
if ( V_29 -> V_47 & V_48 ) {
memset ( V_36 , 0 , V_37 + V_38 + 1 ) ;
V_39 = ( T_2 ) V_36 ;
V_39 -> V_49 = V_50 ;
memcpy ( V_39 -> V_51 , V_35 -> V_52 , ( int ) V_35 -> V_53 ) ;
if ( V_39 -> V_51 [ V_35 -> V_53 - 1 ] == '\0' ) {
if ( V_35 -> V_53 > 0 )
V_39 -> V_54 = V_35 -> V_53 - 1 ;
} else
V_39 -> V_54 = V_35 -> V_53 ;
V_32 -> V_55 = V_56 ;
F_9 ( L_5 , ( ( T_2 ) V_36 ) -> V_51 ,
( ( T_2 ) V_36 ) -> V_54 ) ;
F_13 ( ( void * ) V_5 , V_57 , V_36 ) ;
F_14 ( & V_5 -> V_44 ) ;
return 0 ;
} else if ( V_35 -> V_58 == V_59 ) {
V_32 -> V_55 = V_56 ;
}
} else {
V_32 -> V_55 = V_60 ;
}
V_32 -> V_55 = V_56 ;
F_13 ( ( void * ) V_5 , V_57 , NULL ) ;
F_14 ( & V_5 -> V_44 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
int V_61 , V_62 , V_63 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
T_3 V_64 ;
T_2 V_39 ;
T_4 V_65 , V_66 ;
char * V_67 = V_30 ;
char * V_68 = V_30 + V_69 ;
char * V_70 = NULL ;
struct V_71 V_72 ;
long V_6 ;
char V_73 [ V_74 * 2 + 30 ] ;
F_6 ( L_6 ) ;
if ( V_32 -> V_75 == V_76 ) {
return - V_77 ;
}
V_64 = & ( V_32 -> V_78 [ 0 ] ) ;
for ( V_61 = 0 , V_62 = 0 ; V_62 < V_79 ; V_62 ++ ) {
if ( V_67 >= V_68 )
break;
V_64 = & ( V_32 -> V_78 [ V_62 ] ) ;
if ( V_64 -> V_80 ) {
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_82 ;
V_72 . V_83 . V_84 . V_85 = V_86 ;
memcpy ( V_72 . V_83 . V_84 . V_87 , V_64 -> V_88 , V_89 ) ;
V_67 = F_16 ( V_28 , V_67 , V_68 , & V_72 , V_90 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_91 ;
V_39 = ( T_2 ) V_64 -> V_51 ;
V_72 . V_83 . V_92 . V_46 = V_39 -> V_54 ;
V_72 . V_83 . V_92 . V_47 = 1 ;
V_67 = F_17 ( V_28 , V_67 , V_68 , & V_72 , V_39 -> V_51 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_93 ;
if ( F_18 ( V_64 -> V_94 ) )
V_72 . V_83 . V_95 = V_96 ;
else
V_72 . V_83 . V_95 = V_97 ;
V_72 . V_54 = V_98 ;
V_67 = F_16 ( V_28 , V_67 , V_68 , & V_72 , V_98 ) ;
V_65 = ( T_4 ) V_64 -> V_99 ;
V_66 = ( T_4 ) V_64 -> V_100 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_101 ;
V_72 . V_83 . V_102 . V_103 = V_64 -> V_104 ;
V_72 . V_83 . V_102 . V_105 = 0 ;
V_72 . V_83 . V_102 . V_106 = 0 ;
V_67 = F_16 ( V_28 , V_67 , V_68 , & V_72 , V_107 ) ;
{
int V_108 = ( int ) V_64 -> V_104 - 1 ;
if ( V_108 < 0 ) V_108 = 0 ;
V_72 . V_83 . V_102 . V_103 = V_109 [ V_108 ] * 100000 ;
V_72 . V_83 . V_102 . V_105 = 1 ;
}
V_67 = F_16 ( V_28 , V_67 , V_68 , & V_72 , V_107 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_110 ;
F_4 ( V_5 , ( unsigned char ) ( V_64 -> V_111 ) , & V_6 ) ;
V_72 . V_83 . V_12 . V_15 = V_6 ;
V_72 . V_83 . V_12 . V_16 = 0 ;
if ( - V_6 < 50 )
V_72 . V_83 . V_12 . V_12 = 100 ;
else if ( - V_6 > 90 )
V_72 . V_83 . V_12 . V_12 = 0 ;
else
V_72 . V_83 . V_12 . V_12 = ( 40 - ( - V_6 - 50 ) ) * 100 / 40 ;
V_72 . V_83 . V_12 . V_17 = 7 ;
V_67 = F_16 ( V_28 , V_67 , V_68 , & V_72 , V_112 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_113 ;
V_72 . V_83 . V_92 . V_46 = 0 ;
if ( F_19 ( V_64 -> V_94 ) )
V_72 . V_83 . V_92 . V_47 = V_114 | V_115 ;
else
V_72 . V_83 . V_92 . V_47 = V_116 ;
V_67 = F_17 ( V_28 , V_67 , V_68 , & V_72 , V_39 -> V_51 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_117 ;
V_72 . V_83 . V_118 . V_119 = V_72 . V_83 . V_118 . V_120 = 0 ;
V_70 = V_67 + V_121 ;
for ( V_63 = 0 ; V_63 < 12 ; V_63 ++ ) {
if ( V_65 -> V_122 [ V_63 ] == 0 )
break;
V_72 . V_83 . V_118 . V_123 = ( ( V_65 -> V_122 [ V_63 ] & 0x7f ) * 500000 ) ;
V_70 = F_20 ( V_28 , V_67 , V_70 , V_68 , & V_72 , V_124 ) ;
}
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ ) {
if ( V_66 -> V_122 [ V_63 ] == 0 )
break;
V_72 . V_83 . V_118 . V_123 = ( ( V_66 -> V_122 [ V_63 ] & 0x7f ) * 500000 ) ;
V_70 = F_20 ( V_28 , V_67 , V_70 , V_68 , & V_72 , V_124 ) ;
}
if ( ( V_70 - V_67 ) > V_121 )
V_67 = V_70 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_125 ;
sprintf ( V_73 , L_7 , V_64 -> V_126 ) ;
V_72 . V_83 . V_92 . V_46 = strlen ( V_73 ) ;
V_67 = F_17 ( V_28 , V_67 , V_68 , & V_72 , V_73 ) ;
if ( ( V_64 -> V_127 > 0 ) && ( V_64 -> V_127 <= V_74 ) ) {
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_128 ;
V_72 . V_83 . V_92 . V_46 = V_64 -> V_127 ;
V_67 = F_17 ( V_28 , V_67 , V_68 , & V_72 , V_64 -> V_129 ) ;
}
if ( ( V_64 -> V_130 > 0 ) && ( V_64 -> V_130 <= V_74 ) ) {
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_128 ;
V_72 . V_83 . V_92 . V_46 = V_64 -> V_130 ;
V_67 = F_17 ( V_28 , V_67 , V_68 , & V_72 , V_64 -> V_131 ) ;
}
}
}
V_29 -> V_46 = V_67 - V_30 ;
return 0 ;
}
int F_21 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_132 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_133 = 0 ;
F_6 ( L_8 ) ;
if ( ( V_29 -> V_105 == 1 ) &&
( V_29 -> V_103 >= ( int ) 2.412e8 ) &&
( V_29 -> V_103 <= ( int ) 2.487e8 ) ) {
int V_108 = V_29 -> V_103 / 100000 ;
int V_134 = 0 ;
while ( ( V_134 < 14 ) && ( V_108 != V_109 [ V_134 ] ) )
V_134 ++ ;
V_29 -> V_105 = 0 ;
V_29 -> V_103 = V_134 + 1 ;
}
if ( ( V_29 -> V_103 > 14 ) || ( V_29 -> V_105 > 0 ) )
V_133 = - V_135 ;
else {
int V_136 = V_29 -> V_103 ;
if ( ( V_136 < 1 ) || ( V_136 > 14 ) ) {
F_6 ( L_9 ,
V_3 -> V_137 , V_29 -> V_103 ) ;
V_133 = - V_138 ;
} else {
F_6 ( L_10 , V_136 ) ;
V_5 -> V_104 = V_136 ;
V_5 -> V_139 = true ;
}
}
return V_133 ;
}
int F_22 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_132 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
F_6 ( L_11 ) ;
#ifdef F_23
V_29 -> V_103 = ( int ) V_32 -> V_140 ;
V_29 -> V_105 = 0 ;
#else
{
int V_108 = ( int ) V_32 -> V_140 - 1 ;
if ( V_108 < 0 )
V_108 = 0 ;
V_29 -> V_103 = V_109 [ V_108 ] * 100000 ;
V_29 -> V_105 = 1 ;
}
#endif
return 0 ;
}
int F_24 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
T_5 * V_141 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_133 = 0 ;
F_6 ( L_12 ) ;
if ( V_32 -> V_142 == V_143 && V_5 -> V_144 ) {
F_6 ( L_13 ) ;
return V_133 ;
}
switch ( * V_141 ) {
case V_97 :
if ( V_32 -> V_145 != V_146 ) {
V_32 -> V_145 = V_146 ;
if ( V_5 -> V_47 & V_147 )
V_5 -> V_139 = true ;
}
F_6 ( L_14 ) ;
break;
case V_148 :
case V_96 :
if ( V_32 -> V_145 != V_149 ) {
V_32 -> V_145 = V_149 ;
if ( V_5 -> V_47 & V_147 )
V_5 -> V_139 = true ;
}
F_6 ( L_15 ) ;
break;
case V_150 :
V_32 -> V_145 = V_149 ;
V_133 = - V_135 ;
break;
if ( V_32 -> V_145 != V_151 ) {
V_32 -> V_145 = V_151 ;
if ( V_5 -> V_47 & V_147 )
V_5 -> V_139 = true ;
}
F_6 ( L_16 ) ;
break;
case V_152 :
V_32 -> V_145 = V_149 ;
V_133 = - V_135 ;
break;
default:
V_133 = - V_138 ;
}
return V_133 ;
}
int F_25 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
T_5 * V_141 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
F_6 ( L_17 ) ;
switch ( V_32 -> V_145 ) {
case V_149 :
* V_141 = V_96 ;
break;
case V_146 :
* V_141 = V_97 ;
break;
case V_153 :
* V_141 = V_96 ;
break;
case V_151 :
* V_141 = V_150 ;
break;
default:
* V_141 = V_97 ;
}
return 0 ;
}
int F_26 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_154 * V_155 = (struct V_154 * ) V_30 ;
int V_106 , V_156 ;
unsigned char V_157 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
F_6 ( L_18 ) ;
if ( V_29 -> V_158 ) {
V_29 -> V_46 = sizeof( struct V_154 ) ;
memset ( V_155 , 0 , sizeof( struct V_154 ) ) ;
V_155 -> V_159 = 0x0000 ;
V_155 -> V_160 = 0x0000 ;
V_155 -> V_161 = 14 ;
V_156 = 0 ;
for ( V_106 = 0 ; V_106 < 14 ; V_106 ++ ) {
V_155 -> V_102 [ V_156 ] . V_106 = V_106 + 1 ;
V_155 -> V_102 [ V_156 ] . V_103 = V_109 [ V_106 ] * 100000 ;
V_155 -> V_102 [ V_156 ++ ] . V_105 = 1 ;
}
V_155 -> V_162 = V_156 ;
#ifdef F_3
V_155 -> V_163 . V_12 = 100 ;
#else
V_155 -> V_163 . V_12 = 255 ;
#endif
V_155 -> V_163 . V_15 = 0 ;
V_155 -> V_163 . V_16 = 0 ;
V_155 -> V_164 = 255 ;
for ( V_106 = 0 ; V_106 < 13 ; V_106 ++ ) {
V_155 -> V_118 [ V_106 ] = V_157 [ V_106 ] * 500000 ;
if ( V_155 -> V_118 [ V_106 ] == 0 )
break;
}
V_155 -> V_165 = V_106 ;
if ( V_106 > 2 )
V_155 -> V_166 = 5 * 1000 * 1000 ;
else
V_155 -> V_166 = 1.5 * 1000 * 1000 ;
V_155 -> V_167 = 0 ;
V_155 -> V_168 = 2312 ;
V_155 -> V_169 = 256 ;
V_155 -> V_170 = 2312 ;
V_155 -> V_171 = 3 ;
V_155 -> V_172 [ 0 ] = 5 ;
V_155 -> V_172 [ 1 ] = 13 ;
V_155 -> V_172 [ 2 ] = 32 ;
V_155 -> V_173 = 4 ;
V_155 -> V_174 = V_175 | V_176 |
V_177 | V_178 ;
V_155 -> V_179 = 0 ;
V_155 -> V_180 = 1000000 ;
V_155 -> V_181 = 0 ;
V_155 -> V_182 = 1000000 ;
V_155 -> V_183 = V_184 ;
V_155 -> V_185 = V_186 ;
V_155 -> V_187 = V_184 | V_186 | V_188 ;
V_155 -> V_189 [ 0 ] = 100 ;
V_155 -> V_190 = 1 ;
V_155 -> V_191 = V_192 ;
V_155 -> V_193 = V_194 ;
V_155 -> V_195 = V_196 ;
V_155 -> V_197 = V_198 | V_199 ;
V_155 -> V_200 = V_198 ;
V_155 -> V_201 = V_199 ;
V_155 -> V_202 = 1 ;
V_155 -> V_203 = 65535 ;
V_155 -> V_204 = 1024 ;
V_155 -> V_205 = 65535 * 1024 ;
V_155 -> V_206 . V_12 = 6 ;
V_155 -> V_206 . V_15 = 176 ;
V_155 -> V_206 . V_16 = 0 ;
}
return 0 ;
}
int F_27 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_207 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_133 = 0 ;
unsigned char V_208 [ V_89 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_6 ( L_19 ) ;
if ( V_32 -> V_75 == V_76 ) {
F_6 ( L_20 ) ;
}
if ( V_29 -> V_85 != V_86 )
V_133 = - V_138 ;
else {
memcpy ( V_32 -> V_209 , V_29 -> V_87 , 6 ) ;
if ( ( V_5 -> V_45 == true ) &&
( memcmp ( V_32 -> V_209 , V_32 -> V_210 , 6 ) == 0 ) ) {
return V_133 ;
}
if ( ( F_28 ( V_32 -> V_209 ) ) ||
( memcmp ( V_32 -> V_209 , V_208 , 6 ) == 0 ) ) {
F_9 ( L_21 ) ;
return V_133 ;
}
{
unsigned int V_61 , V_211 = 0 ;
for ( V_61 = 0 ; V_61 < V_79 ; V_61 ++ ) {
if ( V_32 -> V_78 [ V_61 ] . V_80 &&
F_29 ( V_32 -> V_78 [ V_61 ] . V_88 ,
V_32 -> V_209 ) ) {
V_211 ++ ;
}
}
if ( V_211 >= 2 ) {
F_9 ( L_22 ) ;
return V_133 ;
}
}
if ( V_5 -> V_47 & V_147 )
V_5 -> V_139 = true ;
}
return V_133 ;
}
int F_30 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_207 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
F_6 ( L_23 ) ;
memcpy ( V_29 -> V_87 , V_32 -> V_210 , 6 ) ;
if ( ( V_5 -> V_45 == false ) && ( V_32 -> V_142 != V_143 ) )
memset ( V_29 -> V_87 , 0 , 6 ) ;
if ( V_32 -> V_142 == V_143 )
memcpy ( V_29 -> V_87 , V_32 -> V_210 , 6 ) ;
V_29 -> V_85 = V_86 ;
return 0 ;
}
int F_31 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
int V_61 , V_62 , V_133 = 0 ;
struct V_207 * V_212 = NULL ;
struct V_207 * V_213 = NULL ;
struct V_214 * V_12 = NULL ;
struct V_214 * V_215 = NULL ;
T_3 V_64 = NULL ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
F_6 ( L_24 ) ;
if ( ! F_32 ( V_216 ) ) {
V_133 = - V_217 ;
goto exit;
}
if ( ! V_29 -> V_158 )
goto exit;
V_212 = F_33 ( V_218 , sizeof( struct V_207 ) , V_219 ) ;
if ( ! V_212 ) {
V_133 = - V_220 ;
goto exit;
}
V_12 = F_33 ( V_218 , sizeof( struct V_214 ) , V_219 ) ;
if ( ! V_12 ) {
V_133 = - V_220 ;
goto exit;
}
for ( V_61 = 0 , V_62 = 0 ; V_61 < V_79 ; V_61 ++ ) {
V_64 = & ( V_32 -> V_78 [ V_61 ] ) ;
if ( ! V_64 -> V_80 )
continue;
if ( V_62 >= V_218 )
break;
V_213 = & V_212 [ V_62 ] ;
V_215 = & V_12 [ V_62 ] ;
memcpy ( V_213 -> V_87 , V_64 -> V_88 , 6 ) ;
V_213 -> V_85 = V_86 ;
V_215 -> V_15 = V_64 -> V_111 ;
V_215 -> V_12 = 0 ;
V_215 -> V_16 = 0 ;
V_215 -> V_17 = 2 ;
V_62 ++ ;
}
V_29 -> V_47 = 1 ;
V_29 -> V_46 = V_62 ;
memcpy ( V_30 , V_212 , sizeof( struct V_207 ) * V_62 ) ;
memcpy ( V_30 + sizeof( struct V_207 ) * V_62 ,
V_12 ,
sizeof( struct V_214 ) * V_62 ) ;
exit:
F_34 ( V_212 ) ;
F_34 ( V_12 ) ;
return V_133 ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
T_2 V_39 ;
unsigned char V_54 ;
F_6 ( L_25 ) ;
V_5 -> V_221 = false ;
if ( V_32 -> V_75 == V_76 ) {
F_6 ( L_26 ) ;
}
if ( V_29 -> V_47 == 0 ) {
memset ( V_32 -> V_222 , 0 , V_37 + V_38 + 1 ) ;
memset ( V_32 -> V_209 , 0xFF , 6 ) ;
F_9 ( L_27 ) ;
#ifdef F_36
return 0 ;
#endif
} else {
memset ( V_32 -> V_222 , 0 , V_37 + V_38 + 1 ) ;
V_39 = ( T_2 ) V_32 -> V_222 ;
V_39 -> V_49 = V_50 ;
memcpy ( V_39 -> V_51 , V_30 , V_29 -> V_46 ) ;
if ( V_39 -> V_51 [ V_29 -> V_46 - 1 ] == '\0' ) {
if ( V_29 -> V_46 > 0 )
V_39 -> V_54 = V_29 -> V_46 - 1 ;
} else
V_39 -> V_54 = V_29 -> V_46 ;
F_6 ( L_28 , V_39 -> V_51 ) ;
V_54 = ( V_39 -> V_54 > ( ( T_2 ) V_32 -> V_223 ) -> V_54 ) ? V_39 -> V_54 : ( ( T_2 ) V_32 -> V_223 ) -> V_54 ;
if ( ( V_5 -> V_45 == true ) &&
( memcmp ( V_39 -> V_51 , ( ( T_2 ) V_32 -> V_223 ) -> V_51 , V_54 ) == 0 ) )
return 0 ;
if ( V_39 -> V_54 == 0 ) {
memset ( V_32 -> V_209 , 0xFF , 6 ) ;
return 0 ;
}
#ifdef F_36
if ( V_5 -> V_224 == true ) {
{
T_3 V_225 = NULL ;
unsigned char V_226 [ V_37 + V_38 + 1 ] ;
unsigned int V_61 , V_211 = 0 ;
memcpy ( V_226 , V_32 -> V_222 , sizeof( V_226 ) ) ;
V_225 = F_37 ( V_5 ,
NULL ,
V_226 ,
V_32 -> V_227
) ;
if ( V_225 == NULL ) {
F_9 ( L_29 ) ;
F_38 ( ( void * ) V_5 ) ;
V_32 -> V_55 = V_60 ;
F_13 ( ( void * ) V_5 , V_57 , V_32 -> V_222 ) ;
F_13 ( ( void * ) V_5 , V_228 , V_32 -> V_222 ) ;
} else {
for ( V_61 = 0 ; V_61 < V_79 ; V_61 ++ ) {
if ( V_32 -> V_78 [ V_61 ] . V_80 &&
F_29 ( V_32 -> V_78 [ V_61 ] . V_88 ,
V_225 -> V_88 ) ) {
V_211 ++ ;
}
}
if ( V_211 >= 2 ) {
F_6 ( L_30 ) ;
F_38 ( ( void * ) V_5 ) ;
V_32 -> V_55 = V_56 ;
F_13 ( ( void * ) V_5 , V_57 , V_32 -> V_222 ) ;
F_13 ( ( void * ) V_5 , V_228 , V_32 -> V_222 ) ;
}
}
}
return 0 ;
}
#endif
F_6 ( L_31 , V_39 -> V_51 ) ;
}
if ( V_5 -> V_47 & V_147 )
V_5 -> V_139 = true ;
return 0 ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
T_2 V_39 ;
F_6 ( L_32 ) ;
V_39 = ( T_2 ) V_32 -> V_223 ;
memcpy ( V_30 , V_39 -> V_51 , V_39 -> V_54 ) ;
V_30 [ V_39 -> V_54 ] = '\0' ;
V_29 -> V_46 = V_39 -> V_54 + 1 ;
V_29 -> V_46 = V_39 -> V_54 ;
V_29 -> V_47 = 1 ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_133 = 0 ;
T_6 V_230 = 0 ;
int V_106 ;
unsigned char V_157 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
F_6 ( L_33 ) ;
if ( ! ( V_5 -> V_47 & V_147 ) ) {
V_133 = - V_138 ;
return V_133 ;
}
if ( ( V_29 -> V_123 < 13 ) &&
( V_29 -> V_123 >= 0 ) ) {
V_230 = V_29 -> V_123 ;
} else {
T_6 V_231 = ( T_6 ) ( V_29 -> V_123 / 500000 ) ;
for ( V_106 = 0 ; V_106 < 13 ; V_106 ++ ) {
if ( V_231 == V_157 [ V_106 ] ) {
V_230 = V_106 ;
break;
}
}
}
if ( V_29 -> V_123 == - 1 ) {
for ( V_106 = 0 ; V_106 < 13 ; V_106 ++ ) {
if ( V_157 [ V_106 ] == 0 )
break;
}
if ( V_106 != 0 )
V_230 = V_106 - 1 ;
}
if ( V_230 > 13 ) {
V_133 = - V_138 ;
return V_133 ;
}
if ( V_29 -> V_119 != 0 ) {
F_6 ( L_34 ) ;
V_5 -> V_232 = true ;
if ( ( V_5 -> V_233 == V_234 ) && ( V_230 > 3 ) ) {
V_5 -> V_235 = 3 ;
} else {
V_5 -> V_235 = V_230 ;
F_6 ( L_35 ,
V_5 -> V_235 ) ;
}
} else {
V_5 -> V_232 = false ;
V_5 -> V_235 = 13 ;
F_6 ( L_36 ) ;
}
return V_133 ;
}
int F_41 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_6 ( L_37 ) ;
{
unsigned char V_157 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
int V_230 = 0 ;
if ( V_5 -> V_45 ) {
if ( V_5 -> V_232 == true ) {
if ( V_5 -> V_235 < 13 ) {
V_230 = V_157 [ V_5 -> V_235 ] ;
} else {
if ( V_5 -> V_233 == V_234 )
V_230 = 0x16 ;
if ( V_5 -> V_233 == V_236 )
V_230 = 0x6C ;
if ( V_5 -> V_233 == V_237 )
V_230 = 0x6C ;
}
} else {
V_230 = V_157 [ V_238 ] ;
}
} else V_230 = 0 ;
V_29 -> V_123 = V_230 * 500000 ;
if ( V_5 -> V_232 == true )
V_29 -> V_119 = true ;
}
return 0 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_133 = 0 ;
F_6 ( L_38 ) ;
{
int V_239 = V_29 -> V_123 ;
if ( V_29 -> V_120 )
V_239 = 2312 ;
if ( ( V_239 < 0 ) || ( V_239 > 2312 ) )
V_133 = - V_138 ;
else
V_5 -> V_240 = V_239 ;
}
return 0 ;
}
int F_43 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_6 ( L_39 ) ;
V_29 -> V_123 = V_5 -> V_240 ;
V_29 -> V_120 = ( V_29 -> V_123 >= 2312 ) ;
V_29 -> V_119 = 1 ;
return 0 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_133 = 0 ;
int V_241 = V_29 -> V_123 ;
F_6 ( L_40 ) ;
if ( V_29 -> V_120 )
V_241 = 2312 ;
if ( ( V_241 < 256 ) || ( V_241 > 2312 ) ) {
V_133 = - V_138 ;
} else {
V_241 &= ~ 0x1 ;
V_5 -> V_242 = ( V_243 ) V_241 ;
}
return V_133 ;
}
int F_45 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_6 ( L_41 ) ;
V_29 -> V_123 = V_5 -> V_242 ;
V_29 -> V_120 = ( V_29 -> V_123 >= 2312 ) ;
V_29 -> V_119 = 1 ;
return 0 ;
}
int F_46 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_133 = 0 ;
F_6 ( L_42 ) ;
if ( V_29 -> V_120 ) {
V_133 = - V_138 ;
return V_133 ;
}
if ( V_29 -> V_47 & V_198 ) {
if ( V_29 -> V_47 & V_244 )
V_5 -> V_245 = V_29 -> V_123 ;
else if ( V_29 -> V_47 & V_246 )
V_5 -> V_247 = V_29 -> V_123 ;
else {
V_5 -> V_247 = V_29 -> V_123 ;
V_5 -> V_245 = V_29 -> V_123 ;
}
}
if ( V_29 -> V_47 & V_199 )
V_5 -> V_248 = V_29 -> V_123 ;
return V_133 ;
}
int F_47 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_6 ( L_43 ) ;
V_29 -> V_120 = 0 ;
if ( ( V_29 -> V_47 & V_249 ) == V_199 ) {
V_29 -> V_47 = V_199 ;
V_29 -> V_123 = ( int ) V_5 -> V_248 ;
} else if ( ( V_29 -> V_47 & V_244 ) ) {
V_29 -> V_47 = V_198 | V_244 ;
V_29 -> V_123 = ( int ) V_5 -> V_245 ;
} else {
V_29 -> V_47 = V_198 ;
V_29 -> V_123 = ( int ) V_5 -> V_247 ;
if ( ( int ) V_5 -> V_247 != ( int ) V_5 -> V_245 )
V_29 -> V_47 |= V_246 ;
}
return 0 ;
}
int F_48 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
unsigned long V_250 = ( unsigned long ) ( V_29 -> V_47 & V_251 ) ;
int V_61 , V_252 , V_133 = 0 ;
int V_253 = ( V_29 -> V_47 & V_251 ) ;
T_7 V_254 ;
F_6 ( L_44 ) ;
if ( ( V_29 -> V_47 & V_116 ) == 0 ) {
if ( V_250 > V_255 ) {
V_133 = - V_138 ;
return V_133 ;
}
if ( V_250 < 1 && ( ( V_29 -> V_47 & V_115 ) == 0 ) ) {
if ( V_5 -> V_256 < V_255 )
V_250 = V_5 -> V_256 ;
else
V_250 = 0 ;
} else {
V_250 -- ;
}
if ( V_29 -> V_46 > V_257 ) {
V_133 = - V_138 ;
return V_133 ;
}
if ( V_29 -> V_46 > 0 ) {
if ( V_29 -> V_46 == V_257 ) {
F_6 ( L_45 ) ;
} else if ( V_29 -> V_46 == V_258 ) {
F_6 ( L_46 ) ;
} else if ( V_29 -> V_46 == V_259 ) {
F_6 ( L_47 ,
( int ) V_250 ) ;
} else {
V_133 = - V_138 ;
return V_133 ;
}
memset ( V_5 -> V_260 , 0 , V_257 ) ;
memcpy ( V_5 -> V_260 , V_30 , V_29 -> V_46 ) ;
F_6 ( L_48 ) ;
for ( V_61 = 0 ; V_61 < V_29 -> V_46 ; V_61 ++ )
F_6 ( L_49 , V_5 -> V_260 [ V_61 ] ) ;
if ( V_5 -> V_47 & V_147 ) {
F_11 ( & V_5 -> V_44 ) ;
F_49 ( & ( V_5 -> V_261 ) ,
( unsigned long ) ( V_250 | ( 1 << 31 ) ) ,
V_29 -> V_46 ,
NULL ,
V_5 -> V_260 ,
V_262 ,
V_5 -> V_263 ,
V_5 -> V_264
) ;
F_14 ( & V_5 -> V_44 ) ;
}
V_5 -> V_256 = ( unsigned char ) V_250 ;
V_5 -> V_265 = V_29 -> V_46 ;
V_5 -> V_266 = true ;
V_5 -> V_267 = true ;
V_5 -> V_268 = V_269 ;
} else if ( V_253 > 0 ) {
if ( V_5 -> V_267 == false ) {
V_133 = - V_138 ;
return V_133 ;
}
F_6 ( L_50 ) ;
V_254 = & ( V_5 -> V_261 . V_270 [ V_271 - 1 ] ) ;
if ( V_254 -> V_272 [ ( unsigned char ) V_250 ] . V_265 == 0 ) {
F_6 ( L_51 ) ;
V_133 = - V_138 ;
return V_133 ;
}
V_5 -> V_256 = ( unsigned char ) V_250 ;
V_254 -> V_273 = V_250 | ( 1 << 31 ) ;
V_254 -> V_272 [ ( unsigned char ) V_250 ] . V_250 = V_250 | ( 1 << 31 ) ;
}
} else {
F_6 ( L_52 ) ;
if ( V_5 -> V_267 == false )
return 0 ;
V_32 -> V_274 = false ;
V_5 -> V_267 = false ;
V_5 -> V_268 = V_275 ;
if ( V_5 -> V_47 & V_147 ) {
F_11 ( & V_5 -> V_44 ) ;
for ( V_252 = 0 ; V_252 < V_271 ; V_252 ++ )
F_50 ( V_5 -> V_263 , V_252 ) ;
F_14 ( & V_5 -> V_44 ) ;
}
}
if ( V_29 -> V_47 & V_276 ) {
F_6 ( L_53 ) ;
V_32 -> V_274 = true ;
}
if ( V_29 -> V_47 & V_277 ) {
F_6 ( L_54 ) ;
V_32 -> V_274 = false ;
}
return V_133 ;
}
int F_51 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
char V_260 [ V_257 ] ;
unsigned int V_253 = ( unsigned int ) ( V_29 -> V_47 & V_251 ) ;
T_8 V_278 = NULL ;
F_6 ( L_55 ) ;
if ( V_253 > V_255 )
return - V_138 ;
if ( V_253 < 1 ) {
if ( V_5 -> V_256 < V_255 )
V_253 = V_5 -> V_256 ;
else
V_253 = 0 ;
} else {
V_253 -- ;
}
memset ( V_260 , 0 , V_257 ) ;
V_29 -> V_47 = V_115 ;
if ( V_5 -> V_267 )
V_29 -> V_47 |= V_114 ;
else
V_29 -> V_47 |= V_116 ;
if ( V_32 -> V_274 )
V_29 -> V_47 |= V_276 ;
else
V_29 -> V_47 |= V_277 ;
V_29 -> V_46 = 0 ;
if ( ( V_253 == 0 ) && ( V_5 -> V_268 == V_279 ||
V_5 -> V_268 == V_280 ) ) {
if ( F_52 ( & ( V_5 -> V_261 ) , V_32 -> V_210 , 0xffffffff , & V_278 ) ) {
V_29 -> V_46 = V_278 -> V_265 ;
memcpy ( V_260 , V_278 -> V_260 , V_278 -> V_265 ) ;
memcpy ( V_30 , V_260 , V_257 ) ;
}
} else if ( F_52 ( & ( V_5 -> V_261 ) , V_5 -> V_281 , ( unsigned char ) V_253 , & V_278 ) ) {
V_29 -> V_46 = V_278 -> V_265 ;
memcpy ( V_260 , V_278 -> V_260 , V_278 -> V_265 ) ;
memcpy ( V_30 , V_260 , V_257 ) ;
}
V_29 -> V_47 |= V_253 + 1 ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_133 = 0 ;
F_6 ( L_56 ) ;
if ( ! ( V_5 -> V_47 & V_147 ) ) {
V_133 = - V_138 ;
return V_133 ;
}
if ( V_29 -> V_120 ) {
V_5 -> V_282 = V_283 ;
F_54 ( V_5 ) ;
return V_133 ;
}
if ( ( V_29 -> V_47 & V_284 ) == V_186 ) {
V_5 -> V_282 = V_285 ;
F_55 ( ( void * ) V_5 , V_32 -> V_286 ) ;
} else if ( ( V_29 -> V_47 & V_284 ) == V_184 ) {
V_5 -> V_282 = V_285 ;
F_55 ( ( void * ) V_5 , V_32 -> V_286 ) ;
}
switch ( V_29 -> V_47 & V_287 ) {
case V_288 :
F_6 ( L_57 ) ;
V_133 = - V_138 ;
break;
case V_188 :
F_6 ( L_58 ) ;
V_133 = - V_138 ;
case V_289 :
F_6 ( L_59 ) ;
break;
default:
V_133 = - V_138 ;
}
return V_133 ;
}
int F_56 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_95 = V_5 -> V_282 ;
F_6 ( L_60 ) ;
V_29 -> V_120 = ( V_95 == V_283 ) ;
if ( V_29 -> V_120 )
return 0 ;
if ( ( V_29 -> V_47 & V_284 ) == V_186 ) {
V_29 -> V_123 = ( int ) ( ( V_32 -> V_286 * V_32 -> V_290 ) << 10 ) ;
V_29 -> V_47 = V_186 ;
} else {
V_29 -> V_123 = ( int ) ( ( V_32 -> V_286 * V_32 -> V_290 ) << 10 ) ;
V_29 -> V_47 = V_184 ;
}
V_29 -> V_47 |= V_188 ;
return 0 ;
}
int F_57 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
long V_6 ;
F_6 ( L_61 ) ;
if ( V_5 -> V_45 == true ) {
F_4 ( V_5 , ( unsigned char ) ( V_5 -> V_14 ) , & V_6 ) ;
V_29 -> V_123 = V_6 ;
} else {
V_29 -> V_123 = 0 ;
}
V_29 -> V_120 = ( V_29 -> V_123 == 0 ) ;
V_29 -> V_119 = 1 ;
return 0 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_291 = 0 ;
static int V_292 = 0 ;
static int V_293 = 0 ;
F_6 ( L_62 ) ;
switch ( V_29 -> V_47 & V_294 ) {
case V_295 :
V_292 = V_29 -> V_123 ;
if ( V_29 -> V_123 == V_296 )
F_9 ( L_63 ) ;
else if ( V_29 -> V_123 == V_297 )
F_9 ( L_64 ) ;
else
F_9 ( L_65 ) ;
break;
case V_298 :
V_293 = V_29 -> V_123 ;
if ( V_293 == V_299 )
V_5 -> V_268 = V_280 ;
else if ( V_293 == V_300 )
V_5 -> V_268 = V_279 ;
else if ( V_293 == V_301 || V_293 == V_302 )
V_5 -> V_268 = V_269 ;
else if ( V_293 == V_303 )
;
else
V_5 -> V_268 = V_275 ;
break;
case V_304 :
if ( V_292 == V_296 )
break;
if ( V_293 == V_303 ) {
if ( V_29 -> V_123 == V_299 )
V_5 -> V_268 = V_280 ;
else
V_5 -> V_268 = V_279 ;
}
break;
case V_305 :
if ( V_292 == V_306 ) {
if ( V_29 -> V_123 == V_307 )
V_32 -> V_308 = V_309 ;
else
V_32 -> V_308 = V_310 ;
} else if ( V_292 == V_297 ) {
if ( V_29 -> V_123 == 0 )
V_32 -> V_308 = V_311 ;
else if ( V_29 -> V_123 == V_307 )
V_32 -> V_308 = V_312 ;
else
V_32 -> V_308 = V_313 ;
}
break;
case V_314 :
break;
case V_315 :
break;
case V_316 :
if ( V_29 -> V_123 == V_317 )
V_32 -> V_274 = false ;
else if ( V_29 -> V_123 == V_318 )
V_32 -> V_274 = true ;
break;
case V_319 :
break;
case V_320 :
break;
case V_321 :
V_291 = - V_135 ;
break;
case V_322 :
V_5 -> V_267 = ! ! V_29 -> V_123 ;
if ( V_5 -> V_267 == false ) {
V_292 = 0 ;
V_293 = 0 ;
V_5 -> V_268 = V_275 ;
V_32 -> V_274 = false ;
V_32 -> V_308 = false ;
}
break;
default:
V_291 = - V_135 ;
break;
}
return V_291 ;
}
int F_59 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_229 * V_29 ,
char * V_30 )
{
return - V_135 ;
}
int F_60 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char T_9 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_291 = 0 ;
char V_46 ;
if ( V_29 -> V_46 ) {
if ( V_29 -> V_46 < 2 )
return - V_138 ;
V_291 = F_61 ( V_46 , V_30 + 1 ) ;
if ( V_291 )
return V_291 ;
if ( V_46 + 2 != V_29 -> V_46 )
return - V_138 ;
if ( V_29 -> V_46 > V_74 ) {
V_291 = - V_220 ;
goto V_323;
}
memset ( V_32 -> V_324 , 0 , V_74 ) ;
if ( F_62 ( V_32 -> V_324 , V_30 , V_29 -> V_46 ) ) {
V_291 = - V_325 ;
goto V_323;
}
V_32 -> V_326 = V_29 -> V_46 ;
} else {
memset ( V_32 -> V_324 , 0 , V_74 ) ;
V_32 -> V_326 = 0 ;
}
V_323:
return V_291 ;
}
int F_63 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char T_9 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
int V_291 = 0 ;
int V_327 = V_29 -> V_46 ;
V_29 -> V_46 = 0 ;
if ( V_32 -> V_326 > 0 ) {
V_29 -> V_46 = V_32 -> V_326 ;
if ( V_32 -> V_326 <= V_327 ) {
if ( F_64 ( V_30 , V_32 -> V_324 , V_32 -> V_326 ) )
V_291 = - V_325 ;
} else {
V_291 = - V_328 ;
}
}
return V_291 ;
}
int F_65 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_329 * V_330 = (struct V_329 * ) V_30 ;
struct V_331 * V_332 = NULL ;
enum V_333 V_334 ;
T_6 V_335 [ 6 ] ;
int V_336 , V_337 = 0 ;
T_6 V_338 [ V_339 ] ;
T_6 V_340 [ 64 ] ;
T_10 V_341 = 0 , V_342 = 0 ;
T_6 V_343 [ 64 ] ;
int V_291 = 0 ;
F_9 ( L_66 ) ;
V_332 = F_66 ( sizeof( * V_332 ) , V_219 ) ;
if ( V_332 == NULL )
return - V_220 ;
switch ( V_330 -> V_344 ) {
case V_345 :
V_334 = V_346 ;
break;
case V_347 :
V_334 = V_348 ;
break;
case V_349 :
V_334 = V_350 ;
break;
case V_351 :
V_334 = V_352 ;
break;
default:
F_9 ( L_67 , V_330 -> V_344 ) ;
V_291 = - V_220 ;
goto error;
}
memcpy ( V_335 , V_330 -> V_335 . V_87 , V_353 ) ;
V_336 = ( V_29 -> V_47 & V_251 ) - 1 ;
if ( V_330 -> V_354 & V_355 )
V_337 = 1 ;
if ( V_330 -> V_354 & V_356 ) {
V_341 = V_339 ;
memcpy ( V_338 , V_330 -> V_357 , V_341 ) ;
}
if ( V_330 -> V_342 ) {
V_342 = V_330 -> V_342 ;
memcpy ( V_340 , & V_330 -> V_340 [ 0 ] , V_342 ) ;
}
memset ( V_343 , 0 , 64 ) ;
if ( V_342 > 0 ) {
memcpy ( V_343 , V_340 , V_342 ) ;
if ( V_342 == 32 ) {
memcpy ( & V_343 [ 16 ] , & V_340 [ 24 ] , 8 ) ;
memcpy ( & V_343 [ 24 ] , & V_340 [ 16 ] , 8 ) ;
}
}
memcpy ( V_332 -> V_335 , V_335 , V_353 ) ;
V_332 -> V_83 . V_358 . V_334 = ( int ) V_334 ;
V_332 -> V_83 . V_358 . V_337 = V_337 ;
V_332 -> V_83 . V_358 . V_359 = V_336 ;
V_332 -> V_83 . V_358 . V_342 = V_342 ;
V_332 -> V_83 . V_358 . V_340 = ( T_6 * ) V_343 ;
V_332 -> V_83 . V_358 . V_338 = ( T_6 * ) V_338 ;
V_332 -> V_83 . V_358 . V_341 = V_341 ;
if ( V_332 -> V_83 . V_358 . V_334 == V_346 ) {
if ( V_332 -> V_83 . V_358 . V_359 == 0 )
V_5 -> V_360 ++ ;
if ( ( V_5 -> V_360 == 1 ) && ( V_332 -> V_83 . V_358 . V_359 == 1 ) )
V_5 -> V_360 ++ ;
if ( ( V_5 -> V_360 == 2 ) && ( V_332 -> V_83 . V_358 . V_359 == 2 ) )
V_5 -> V_360 ++ ;
if ( ( V_5 -> V_360 == 3 ) && ( V_332 -> V_83 . V_358 . V_359 == 3 ) )
V_5 -> V_360 ++ ;
}
if ( V_5 -> V_360 == 4 ) {
F_6 ( L_68 ) ;
V_5 -> V_360 = 0 ;
V_5 -> V_224 = true ;
}
F_11 ( & V_5 -> V_44 ) ;
V_291 = F_67 ( V_5 , V_332 , true ) ;
F_14 ( & V_5 -> V_44 ) ;
error:
F_34 ( V_332 ) ;
return V_291 ;
}
int F_68 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char * V_30 )
{
return - V_135 ;
}
int F_69 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_31 * V_29 ,
char T_9 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_32 = & ( V_5 -> V_33 ) ;
struct V_361 V_362 ;
int V_291 = 0 ;
V_291 = F_62 ( & V_362 , V_30 , sizeof( V_362 ) ) ;
if ( V_291 )
return - V_325 ;
if ( memcmp ( V_32 -> V_210 , V_362 . V_335 . V_87 , V_353 ) ) {
V_291 = - V_138 ;
return V_291 ;
}
switch ( V_362 . V_81 ) {
case V_363 :
break;
case V_364 :
if ( V_5 -> V_45 == true ) {
F_6 ( L_69 ) ;
memset ( V_32 -> V_209 , 0xFF , 6 ) ;
F_70 ( & V_5 -> V_261 , V_5 -> V_263 ) ;
F_13 ( ( void * ) V_5 , V_365 , NULL ) ;
}
break;
default:
V_291 = - V_135 ;
}
return V_291 ;
}
