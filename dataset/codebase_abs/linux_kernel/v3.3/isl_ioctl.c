static int
F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 = V_4 ;
T_2 V_5 , V_6 ;
if ( V_2 == V_7 || V_2 == V_8 ) {
F_2 ( V_9
L_1
L_2 , V_10 ) ;
return - V_11 ;
}
V_1 -> V_2 = V_2 ;
switch ( V_2 ) {
case V_12 :
V_5 = V_13 ;
V_6 = V_14 ;
break;
case V_15 :
V_5 = V_13 ;
V_6 = V_16 ;
break;
case V_17 :
V_5 = V_13 ;
V_6 = V_18 ;
break;
case V_19 :
V_5 = V_20 ;
V_6 = V_18 ;
break;
case V_21 :
V_5 = V_22 ;
V_6 = V_14 ;
V_3 |= V_23 ;
break;
default:
return - V_11 ;
}
if ( V_24 )
V_3 |= V_25 ;
F_3 ( V_1 , V_26 , & V_6 ) ;
F_3 ( V_1 , V_27 , & V_3 ) ;
F_3 ( V_1 , V_28 , & V_5 ) ;
return 0 ;
}
void
F_4 ( T_1 * V_1 )
{
T_2 V_29 , V_30 , V_31 , V_32 , V_33 , V_34 , V_35 , V_36 , V_5 ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_1 -> V_42
} ;
V_29 = V_43 ;
V_30 = V_44 ;
V_31 = V_45 ;
V_32 = V_46 ;
V_33 = V_47 ;
V_34 = V_48 ;
V_35 = V_49 ;
V_36 = 127 ;
V_5 = V_50 ;
F_3 ( V_1 , V_51 , & V_29 ) ;
F_3 ( V_1 , V_52 , & V_30 ) ;
F_3 ( V_1 , V_53 , & V_31 ) ;
F_3 ( V_1 , V_54 , & V_38 ) ;
F_3 ( V_1 , V_55 , & V_32 ) ;
F_3 ( V_1 , V_56 , & V_33 ) ;
F_3 ( V_1 , V_57 , & V_34 ) ;
F_3 ( V_1 , V_58 , & V_35 ) ;
F_3 ( V_1 , V_59 , & V_36 ) ;
F_1 ( V_1 , V_5 ) ;
}
void
F_5 ( struct V_60 * V_61 )
{
T_1 * V_1 = F_6 ( V_61 , T_1 , V_62 ) ;
char * V_63 ;
int V_64 ;
struct V_65 V_66 , * V_67 ;
union V_68 V_69 ;
F_7 ( & V_1 -> V_70 ) ;
F_8 ( V_1 , V_71 , 0 , NULL , & V_69 ) ;
V_1 -> V_72 . V_73 . V_74 = V_69 . V_75 ;
F_8 ( V_1 , V_76 , 0 , NULL , & V_69 ) ;
V_63 = V_69 . V_77 ;
memcpy ( V_66 . V_78 , V_63 , 6 ) ;
F_9 ( V_63 ) ;
V_64 = F_8 ( V_1 , V_79 , 0 , ( void * ) & V_66 , & V_69 ) ;
V_67 = V_69 . V_77 ;
V_1 -> V_72 . V_73 . V_80 = V_67 -> V_81 ;
V_1 -> V_72 . V_73 . V_73 =
V_67 -> V_81 - V_1 -> V_82 . V_73 . V_74 ;
F_9 ( V_67 ) ;
V_1 -> V_72 . V_73 . V_83 = 0x7 ;
F_8 ( V_1 , V_84 , 0 , NULL , & V_69 ) ;
V_1 -> V_72 . V_85 . V_86 = V_69 . V_75 ;
F_8 ( V_1 , V_87 , 0 , NULL , & V_69 ) ;
V_1 -> V_72 . V_85 . V_88 = V_69 . V_75 ;
F_10 ( & V_1 -> V_70 ) ;
}
struct V_89 *
F_11 ( struct V_90 * V_91 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
if ( F_13 ( & V_1 -> V_70 ) ) {
memcpy ( & V_1 -> V_82 , & V_1 -> V_72 ,
sizeof ( struct V_89 ) ) ;
V_1 -> V_72 . V_73 . V_83 = 0 ;
F_10 ( & V_1 -> V_70 ) ;
} else
V_1 -> V_82 . V_73 . V_83 = 0 ;
if ( ( V_1 -> V_92 == 0 ) ||
F_14 ( V_93 , V_1 -> V_92 + 1 * V_94 ) ) {
F_15 ( & V_1 -> V_62 ) ;
V_1 -> V_92 = V_93 ;
}
return & V_1 -> V_82 ;
}
static int
F_16 ( struct V_90 * V_91 , struct V_95 * V_96 ,
char * V_97 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
if ( V_1 -> V_2 != V_21 )
return F_17 ( V_1 , V_99 , 0 , NULL ) ;
return 0 ;
}
static int
F_18 ( struct V_90 * V_91 , struct V_95 * V_96 ,
char * V_97 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
char * V_100 ;
union V_68 V_69 ;
int V_101 ;
if ( F_19 ( V_1 ) < V_102 ) {
strncpy ( V_97 , L_3 , V_103 ) ;
return 0 ;
}
V_101 = F_8 ( V_1 , V_104 , 0 , NULL , & V_69 ) ;
switch ( V_69 . V_75 ) {
case V_105 :
V_100 = L_4 ;
break;
case V_106 :
V_100 = L_5 ;
break;
case V_107 :
default:
V_100 = L_6 ;
break;
}
strncpy ( V_97 , V_100 , V_103 ) ;
return V_101 ;
}
static int
F_20 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_108 * V_109 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_101 ;
T_2 V_110 ;
if ( V_109 -> V_111 < 1000 )
V_110 = V_109 -> V_111 ;
else
V_110 = ( V_109 -> V_112 == 1 ) ? F_21 ( V_109 -> V_111 / 100000 ) : 0 ;
V_101 = V_110 ? F_17 ( V_1 , V_51 , 0 , & V_110 ) : - V_11 ;
return ( V_101 ? V_101 : - V_113 ) ;
}
static int
F_22 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_108 * V_109 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_51 , 0 , NULL , & V_69 ) ;
V_109 -> V_114 = V_69 . V_75 ;
V_101 |= F_8 ( V_1 , V_115 , 0 , NULL , & V_69 ) ;
V_109 -> V_111 = V_69 . V_75 ;
V_109 -> V_112 = 3 ;
return V_101 ;
}
static int
F_23 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
T_2 V_117 = V_48 ;
if ( * V_116 > V_21 || * V_116 < V_12 ) {
F_2 ( V_9
L_7 ,
V_1 -> V_91 -> V_118 , V_10 ) ;
return - V_11 ;
}
F_24 ( & V_1 -> V_119 ) ;
if ( F_1 ( V_1 , * V_116 ) ) {
F_25 ( & V_1 -> V_119 ) ;
return - V_120 ;
}
if ( ( * V_116 == V_19 ) && ( V_1 -> V_121 . V_122 != V_123 ) )
V_117 = V_124 ;
if ( V_1 -> V_125 )
V_117 = V_126 ;
F_3 ( V_1 , V_57 , & V_117 ) ;
if ( F_26 ( V_1 ) ) {
F_25 ( & V_1 -> V_119 ) ;
return - V_127 ;
}
V_1 -> V_91 -> type = ( V_1 -> V_2 == V_21 )
? V_1 -> V_128 : V_129 ;
F_25 ( & V_1 -> V_119 ) ;
return 0 ;
}
static int
F_27 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
F_28 ( ( V_1 -> V_2 < V_12 ) || ( V_1 -> V_2 >
V_21 ) ) ;
* V_116 = V_1 -> V_2 ;
return 0 ;
}
static int
F_29 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
T_2 V_132 ;
V_132 = V_131 -> V_133 ? 20 : V_131 -> V_134 ;
return F_17 ( V_1 , V_135 , 0 , & V_132 ) ;
}
static int
F_30 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_135 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = V_69 . V_75 ;
V_131 -> V_133 = ( V_131 -> V_134 == 0 ) ;
V_131 -> V_136 = 1 ;
return V_101 ;
}
static int
F_31 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
struct V_139 * V_140 = (struct V_139 * ) V_98 ;
T_1 * V_1 = F_12 ( V_91 ) ;
T_4 * V_63 ;
int V_114 , V_111 , V_101 ;
struct V_141 * V_142 ;
union V_68 V_69 ;
memset ( V_140 , 0 , sizeof ( struct V_139 ) ) ;
V_138 -> V_143 = sizeof ( struct V_139 ) ;
V_140 -> V_144 = V_145 ;
V_140 -> V_146 = V_147 ;
V_140 -> V_148 = 3 ;
V_140 -> V_149 [ 0 ] = 5 ;
V_140 -> V_149 [ 1 ] = 13 ;
V_140 -> V_149 [ 2 ] = 32 ;
V_140 -> V_150 = 4 ;
V_140 -> V_151 . V_80 = 0 ;
V_140 -> V_151 . V_74 = 0 ;
V_140 -> V_151 . V_73 = 0 ;
V_140 -> V_152 . V_80 = - 80 ;
V_140 -> V_152 . V_74 = 0 ;
V_140 -> V_152 . V_73 = 0 ;
V_140 -> V_153 = 200 ;
V_140 -> V_154 = V_155 | V_156 ;
V_140 -> V_157 = V_155 ;
V_140 -> V_158 = V_156 ;
V_140 -> V_159 = 1 ;
V_140 -> V_160 = 65535 ;
V_140 -> V_161 = 1024 ;
V_140 -> V_162 = 65535 * 1024 ;
V_140 -> V_163 = V_164 ;
V_140 -> V_165 [ 0 ] = ( V_166 |
F_32 ( V_167 ) |
F_32 ( V_168 ) ) ;
V_140 -> V_165 [ 1 ] = V_169 ;
V_140 -> V_165 [ 4 ] = F_32 ( V_170 ) ;
V_140 -> V_171 = V_172 | V_173 |
V_174 ;
if ( F_19 ( V_1 ) < V_102 )
return 0 ;
V_101 =
F_8 ( V_1 , V_175 , 0 , NULL , & V_69 ) ;
V_142 = V_69 . V_77 ;
V_140 -> V_176 = V_142 -> V_177 ;
V_140 -> V_178 = V_142 -> V_177 ;
V_111 = F_33 ( V_179 , ( int ) V_142 -> V_177 ) ;
for ( V_114 = 0 ; V_114 < V_111 ; V_114 ++ ) {
V_140 -> V_142 [ V_114 ] . V_111 = V_142 -> V_180 [ V_114 ] ;
V_140 -> V_142 [ V_114 ] . V_112 = 6 ;
V_140 -> V_142 [ V_114 ] . V_114 = F_21 ( V_142 -> V_180 [ V_114 ] ) ;
}
F_9 ( V_142 ) ;
V_101 |= F_8 ( V_1 , V_181 , 0 , NULL , & V_69 ) ;
V_63 = V_69 . V_77 ;
V_114 = 0 ;
while ( ( V_114 < V_182 ) && ( * V_63 != 0 ) ) {
V_140 -> V_183 [ V_114 ] = * V_63 * 500000 ;
V_114 ++ ;
V_63 ++ ;
}
V_140 -> V_184 = V_114 ;
F_9 ( V_69 . V_77 ) ;
return V_101 ;
}
static int
F_34 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_185 * V_186 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
char V_187 [ 6 ] ;
int V_101 ;
if ( V_186 -> V_188 != V_129 )
return - V_11 ;
memcpy ( & V_187 [ 0 ] , V_186 -> V_189 , 6 ) ;
V_101 = F_17 ( V_1 , V_76 , 0 , & V_187 ) ;
return ( V_101 ? V_101 : - V_113 ) ;
}
static int
F_35 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_185 * V_186 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_76 , 0 , NULL , & V_69 ) ;
memcpy ( V_186 -> V_189 , V_69 . V_77 , 6 ) ;
V_186 -> V_188 = V_129 ;
F_9 ( V_69 . V_77 ) ;
return V_101 ;
}
static int
F_36 ( struct V_90 * V_190 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
return 0 ;
}
static char *
F_37 ( struct V_90 * V_91 , struct V_95 * V_96 ,
char * V_191 , char * V_192 , struct V_65 * V_66 ,
char V_74 )
{
struct V_193 V_194 ;
short V_195 ;
T_1 * V_1 = F_12 ( V_91 ) ;
T_4 V_196 [ V_197 ] ;
T_5 V_198 ;
memcpy ( V_194 . V_75 . V_199 . V_189 , V_66 -> V_78 , 6 ) ;
V_194 . V_75 . V_199 . V_188 = V_129 ;
V_194 . V_200 = V_168 ;
V_191 = F_38 ( V_96 , V_191 , V_192 ,
& V_194 , V_201 ) ;
V_194 . V_75 . V_63 . V_143 = V_66 -> V_202 . V_143 ;
V_194 . V_75 . V_63 . V_203 = 1 ;
V_194 . V_200 = V_204 ;
V_191 = F_39 ( V_96 , V_191 , V_192 ,
& V_194 , V_66 -> V_202 . V_205 ) ;
#define F_40 0x01
#define F_41 0x02
#define F_42 0x10
V_195 = V_66 -> V_206 ;
V_194 . V_75 . V_5 = 0 ;
if ( V_195 & F_40 )
V_194 . V_75 . V_5 = V_19 ;
else if ( V_195 & F_41 )
V_194 . V_75 . V_5 = V_15 ;
V_194 . V_200 = V_207 ;
if ( V_194 . V_75 . V_5 )
V_191 = F_38 ( V_96 , V_191 , V_192 ,
& V_194 , V_208 ) ;
if ( V_195 & F_42 )
V_194 . V_75 . V_63 . V_203 = V_209 | V_210 ;
else
V_194 . V_75 . V_63 . V_203 = V_211 ;
V_194 . V_75 . V_63 . V_143 = 0 ;
V_194 . V_200 = V_212 ;
V_191 = F_39 ( V_96 , V_191 , V_192 ,
& V_194 , NULL ) ;
V_194 . V_75 . V_142 . V_111 = V_66 -> V_29 ;
V_194 . V_75 . V_142 . V_112 = 6 ;
V_194 . V_200 = V_213 ;
V_191 = F_38 ( V_96 , V_191 , V_192 ,
& V_194 , V_214 ) ;
V_194 . V_75 . V_73 . V_80 = V_66 -> V_81 ;
V_194 . V_75 . V_73 . V_74 = V_74 ;
V_194 . V_75 . V_73 . V_73 = V_66 -> V_81 - V_74 ;
V_194 . V_200 = V_215 ;
V_191 = F_38 ( V_96 , V_191 , V_192 ,
& V_194 , V_216 ) ;
V_198 = F_43 ( V_1 , V_66 -> V_78 , V_196 ) ;
if ( V_198 > 0 ) {
V_194 . V_200 = V_217 ;
V_194 . V_75 . V_63 . V_143 = F_33 ( V_198 , ( T_5 ) V_197 ) ;
V_191 = F_39 ( V_96 , V_191 , V_192 ,
& V_194 , V_196 ) ;
}
{
char * V_218 = V_191 + F_44 ( V_96 ) ;
int V_114 ;
int V_219 ;
V_194 . V_200 = V_220 ;
V_194 . V_75 . V_183 . V_136 = V_194 . V_75 . V_183 . V_133 = 0 ;
V_219 = 0x1 ;
for( V_114 = 0 ; V_114 < sizeof( V_221 ) ; V_114 ++ ) {
if( V_66 -> V_222 & V_219 ) {
V_194 . V_75 . V_183 . V_134 = ( V_221 [ V_114 ] * 500000 ) ;
V_218 = F_45 (
V_96 , V_191 , V_218 ,
V_192 , & V_194 , V_223 ) ;
}
V_219 <<= 1 ;
}
if ( ( V_218 - V_191 ) > F_44 ( V_96 ) )
V_191 = V_218 ;
}
return V_191 ;
}
static int
F_46 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_114 , V_101 ;
struct V_224 * V_225 ;
T_2 V_74 = 0 ;
char * V_191 = V_98 ;
union V_68 V_69 ;
if ( F_19 ( V_1 ) < V_102 ) {
V_138 -> V_143 = 0 ;
return 0 ;
}
V_101 = F_8 ( V_1 , V_71 , 0 , NULL , & V_69 ) ;
V_74 = V_69 . V_75 ;
V_101 |= F_8 ( V_1 , V_226 , 0 , NULL , & V_69 ) ;
V_225 = V_69 . V_77 ;
for ( V_114 = 0 ; V_114 < ( int ) V_225 -> V_177 ; V_114 ++ ) {
V_191 = F_37 ( V_91 , V_96 , V_191 ,
V_98 + V_138 -> V_143 ,
& ( V_225 -> V_225 [ V_114 ] ) ,
V_74 ) ;
if( ( V_98 + V_138 -> V_143 - V_191 ) <= V_201 ) {
V_101 = - V_227 ;
break;
}
}
F_9 ( V_225 ) ;
V_138 -> V_143 = ( V_191 - V_98 ) ;
V_138 -> V_203 = 0 ;
return V_101 ;
}
static int
F_47 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_228 V_229 ;
memset ( V_229 . V_205 , 0 , 33 ) ;
if ( V_138 -> V_203 && V_138 -> V_143 ) {
if ( V_138 -> V_143 > 32 )
return - V_227 ;
V_229 . V_143 = V_138 -> V_143 ;
memcpy ( V_229 . V_205 , V_98 , V_138 -> V_143 ) ;
} else
V_229 . V_143 = 0 ;
if ( V_1 -> V_2 != V_21 )
return F_17 ( V_1 , V_99 , 0 , & V_229 ) ;
F_3 ( V_1 , V_99 , & V_229 ) ;
return 0 ;
}
static int
F_48 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_228 * V_229 ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_99 , 0 , NULL , & V_69 ) ;
V_229 = V_69 . V_77 ;
if ( V_229 -> V_143 ) {
V_138 -> V_203 = 1 ;
V_138 -> V_143 = F_33 ( ( T_4 ) V_230 , V_229 -> V_143 ) ;
} else {
V_138 -> V_203 = 0 ;
V_138 -> V_143 = 0 ;
}
V_229 -> V_205 [ V_138 -> V_143 ] = '\0' ;
memcpy ( V_98 , V_229 -> V_205 , V_138 -> V_143 ) ;
F_9 ( V_229 ) ;
return V_101 ;
}
static int
F_49 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
if ( V_138 -> V_143 > V_230 )
return - V_227 ;
F_24 ( & V_1 -> V_119 ) ;
memset ( V_1 -> V_231 , 0 , sizeof ( V_1 -> V_231 ) ) ;
memcpy ( V_1 -> V_231 , V_98 , V_138 -> V_143 ) ;
F_25 ( & V_1 -> V_119 ) ;
return 0 ;
}
static int
F_50 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
V_138 -> V_143 = 0 ;
F_51 ( & V_1 -> V_119 ) ;
V_138 -> V_143 = strlen ( V_1 -> V_231 ) ;
memcpy ( V_98 , V_1 -> V_231 , V_138 -> V_143 ) ;
F_52 ( & V_1 -> V_119 ) ;
return 0 ;
}
static int
F_53 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
T_2 V_232 , V_233 ;
char * V_63 ;
int V_234 , V_114 ;
union V_68 V_69 ;
if ( V_131 -> V_134 == - 1 ) {
V_233 = 1 ;
return F_17 ( V_1 , V_235 , 0 , & V_233 ) ;
}
V_234 = F_8 ( V_1 , V_181 , 0 , NULL , & V_69 ) ;
if ( V_234 ) {
F_9 ( V_69 . V_77 ) ;
return V_234 ;
}
V_232 = ( T_2 ) ( V_131 -> V_134 / 500000 ) ;
V_63 = V_69 . V_77 ;
V_114 = 0 ;
while ( V_63 [ V_114 ] ) {
if ( V_232 && ( V_63 [ V_114 ] == V_232 ) ) {
break;
}
if ( V_131 -> V_134 == V_114 ) {
break;
}
V_63 [ V_114 ] |= 0x80 ;
V_114 ++ ;
}
if ( ! V_63 [ V_114 ] ) {
F_9 ( V_69 . V_77 ) ;
return - V_11 ;
}
V_63 [ V_114 ] |= 0x80 ;
V_63 [ V_114 + 1 ] = 0 ;
if ( V_131 -> V_136 ) {
V_63 [ 0 ] = V_63 [ V_114 ] ;
V_63 [ 1 ] = 0 ;
}
V_233 = - 1 ;
V_234 = F_17 ( V_1 , V_235 , 0 , & V_233 ) ;
V_234 |= F_17 ( V_1 , V_236 , 0 , V_63 ) ;
V_234 |= F_17 ( V_1 , V_237 , 0 , V_63 ) ;
F_9 ( V_69 . V_77 ) ;
return V_234 ;
}
static int
F_54 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_101 ;
char * V_63 ;
union V_68 V_69 ;
if ( ( V_101 = F_8 ( V_1 , V_238 , 0 , NULL , & V_69 ) ) )
return V_101 ;
V_131 -> V_134 = V_69 . V_75 * 500000 ;
V_101 = F_8 ( V_1 , V_237 , 0 , NULL , & V_69 ) ;
if ( V_101 ) {
F_9 ( V_69 . V_77 ) ;
return V_101 ;
}
V_63 = V_69 . V_77 ;
V_131 -> V_136 = ( V_63 [ 0 ] != 0 ) && ( V_63 [ 1 ] == 0 ) ;
F_9 ( V_69 . V_77 ) ;
return 0 ;
}
static int
F_55 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
return F_17 ( V_1 , V_239 , 0 , & V_131 -> V_134 ) ;
}
static int
F_56 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_239 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = V_69 . V_75 ;
return V_101 ;
}
static int
F_57 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
return F_17 ( V_1 , V_240 , 0 , & V_131 -> V_134 ) ;
}
static int
F_58 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_240 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = V_69 . V_75 ;
return V_101 ;
}
static int
F_59 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
T_2 V_241 = 0 , V_242 = 0 ;
T_2 V_243 = 0 ;
int V_101 = 0 ;
if ( V_131 -> V_133 )
return - V_11 ;
if ( V_131 -> V_203 & V_155 ) {
if ( V_131 -> V_203 & V_244 )
V_241 = V_131 -> V_134 ;
else if ( V_131 -> V_203 & V_245 )
V_242 = V_131 -> V_134 ;
else {
V_241 = V_131 -> V_134 ;
V_242 = V_131 -> V_134 ;
}
}
if ( V_131 -> V_203 & V_156 )
V_243 = V_131 -> V_134 / 1024 ;
if ( V_241 )
V_101 =
F_17 ( V_1 , V_246 , 0 , & V_241 ) ;
if ( V_242 )
V_101 |=
F_17 ( V_1 , V_247 , 0 , & V_242 ) ;
if ( V_243 )
V_101 |=
F_17 ( V_1 , V_248 , 0 ,
& V_243 ) ;
return V_101 ;
}
static int
F_60 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 = 0 ;
V_131 -> V_133 = 0 ;
if ( ( V_131 -> V_203 & V_249 ) == V_156 ) {
V_101 =
F_8 ( V_1 , V_248 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = V_69 . V_75 * 1024 ;
V_131 -> V_203 = V_156 ;
} else if ( ( V_131 -> V_203 & V_245 ) ) {
V_101 |=
F_8 ( V_1 , V_247 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = V_69 . V_75 ;
V_131 -> V_203 = V_155 | V_245 ;
} else {
V_101 |=
F_8 ( V_1 , V_246 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = V_69 . V_75 ;
V_131 -> V_203 = V_155 | V_244 ;
}
return V_101 ;
}
static int
F_61 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_101 = 0 , V_250 = 0 ;
int V_30 = V_251 , V_252 = 0 , V_253 = 0 ;
union V_68 V_69 ;
if ( V_138 -> V_143 > 0 ) {
int V_254 = ( V_138 -> V_203 & V_255 ) - 1 ;
int V_256 ;
struct V_257 V_258 = { V_259 , 0 , L_8 } ;
V_101 = F_8 ( V_1 , V_260 , 0 , NULL , & V_69 ) ;
V_256 = V_69 . V_75 ;
if ( ! ( V_138 -> V_203 & V_210 ) ) {
if ( V_138 -> V_143 > V_261 ) {
return - V_11 ;
}
if ( V_138 -> V_143 > V_262 ) {
V_258 . type = V_263 ;
V_258 . V_143 = V_261 ;
} else if ( V_138 -> V_143 > V_264 ) {
V_258 . V_143 = V_262 ;
} else {
V_258 . V_143 = V_264 ;
}
memset ( V_258 . V_258 , 0 , sizeof ( V_258 . V_258 ) ) ;
memcpy ( V_258 . V_258 , V_98 , V_138 -> V_143 ) ;
if ( ( V_254 < 0 ) || ( V_254 > 3 ) )
V_254 = V_256 ;
V_101 |=
F_17 ( V_1 , V_265 , V_254 ,
& V_258 ) ;
}
if ( ( V_254 == V_256 ) && ( V_258 . V_143 > 0 ) )
V_250 = 1 ;
} else {
int V_254 = ( V_138 -> V_203 & V_255 ) - 1 ;
if ( ( V_254 >= 0 ) && ( V_254 <= 3 ) ) {
V_101 |=
F_17 ( V_1 , V_260 , 0 ,
& V_254 ) ;
} else {
if ( ! ( V_138 -> V_203 & V_266 ) ) {
return - V_11 ;
}
}
}
if ( V_138 -> V_203 & V_211 ) {
}
if ( V_138 -> V_203 & V_267 )
V_252 = 1 ;
if ( ( V_138 -> V_203 & V_268 ) || V_250 ) {
V_30 = V_269 ;
V_252 = 1 ;
V_253 = 1 ;
}
if ( ( V_138 -> V_203 & V_266 ) || V_250 ) {
V_101 |=
F_17 ( V_1 , V_52 , 0 , & V_30 ) ;
V_101 |=
F_17 ( V_1 , V_53 , 0 , & V_252 ) ;
V_101 |=
F_17 ( V_1 , V_55 , 0 ,
& V_253 ) ;
}
return V_101 ;
}
static int
F_62 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_257 * V_258 ;
T_2 V_270 , V_254 = ( V_138 -> V_203 & V_255 ) - 1 ;
T_2 V_30 = 0 , V_252 = 0 , V_253 = 0 ;
int V_101 ;
union V_68 V_69 ;
V_101 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
V_30 = V_69 . V_75 ;
V_101 |= F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
V_252 = V_69 . V_75 ;
V_101 |= F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
V_253 = V_69 . V_75 ;
if ( V_252 && ( V_30 == V_269 ) && V_253 )
V_138 -> V_203 = V_268 ;
else if ( ( V_30 == V_251 ) && ! V_253 ) {
if ( V_252 )
V_138 -> V_203 = V_267 ;
else
V_138 -> V_203 = V_211 ;
} else
V_138 -> V_203 = 0 ;
V_101 |= F_8 ( V_1 , V_260 , 0 , NULL , & V_69 ) ;
V_270 = V_69 . V_75 ;
if ( V_254 == - 1 || V_254 > 3 )
V_254 = V_270 ;
V_101 |= F_8 ( V_1 , V_265 , V_254 , NULL , & V_69 ) ;
V_258 = V_69 . V_77 ;
V_138 -> V_143 = V_258 -> V_143 ;
memcpy ( V_98 , V_258 -> V_258 , V_138 -> V_143 ) ;
F_9 ( V_258 ) ;
V_138 -> V_203 |= V_270 + 1 ;
return V_101 ;
}
static int
F_63 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
union V_68 V_69 ;
int V_101 ;
V_101 = F_8 ( V_1 , V_59 , 0 , NULL , & V_69 ) ;
V_131 -> V_134 = ( V_271 ) V_69 . V_75 / 4 ;
V_131 -> V_136 = 1 ;
V_131 -> V_133 = 0 ;
return V_101 ;
}
static int
F_64 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_130 * V_131 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
V_271 V_75 = V_131 -> V_134 ;
V_75 *= 4 ;
if ( V_131 -> V_133 ) {
F_2 ( V_9
L_9 ,
V_1 -> V_91 -> V_118 , V_10 ) ;
return - V_272 ;
} else if ( V_131 -> V_136 )
return F_17 ( V_1 , V_59 , 0 , & V_75 ) ;
else {
F_2 ( V_9
L_10 ,
V_1 -> V_91 -> V_118 , V_10 ) ;
return - V_272 ;
}
}
static int F_65 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
struct V_137 * V_63 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_273 , V_234 = 0 ;
struct V_274 * V_275 ;
if ( V_63 -> V_143 > V_197 ||
( V_63 -> V_143 && V_98 == NULL ) )
return - V_11 ;
memcpy ( V_1 -> V_196 , V_98 , V_63 -> V_143 ) ;
V_1 -> V_198 = V_63 -> V_143 ;
V_273 = sizeof( * V_275 ) + V_1 -> V_198 ;
V_275 = F_66 ( V_273 , V_276 ) ;
if ( V_275 == NULL )
return - V_277 ;
#define F_67 0
#define F_68 0
#define F_69 2
V_275 -> type = ( F_67 << 2 ) |
( F_68 << 4 ) ;
V_275 -> V_278 = - 1 ;
V_275 -> V_39 = V_1 -> V_198 ;
memcpy ( V_275 -> V_63 , V_98 , V_1 -> V_198 ) ;
V_234 = F_70 ( V_1 , V_279 , V_275 ,
V_1 -> V_198 ) ;
if ( V_234 == 0 ) {
V_275 -> type = ( F_67 << 2 ) |
( F_69 << 4 ) ;
V_234 = F_70 ( V_1 , V_279 , V_275 ,
V_1 -> V_198 ) ;
if ( V_234 == 0 )
F_2 ( V_9 L_11 ,
V_91 -> V_118 ) ;
}
F_9 ( V_275 ) ;
return V_234 ;
}
static int F_71 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
struct V_137 * V_63 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_280 = V_1 -> V_198 ;
if ( V_280 <= 0 ) {
V_63 -> V_143 = 0 ;
return 0 ;
}
if ( V_63 -> V_143 < V_280 )
return - V_227 ;
V_63 -> V_143 = V_280 ;
memcpy ( V_98 , V_1 -> V_196 , V_280 ) ;
return 0 ;
}
static int F_72 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
union V_281 * V_282 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_130 * V_283 = & V_282 -> V_283 ;
T_2 V_284 = 0 , V_30 = 0 , V_33 = 0 ;
T_2 V_253 = 0 , V_285 = 0 , V_125 = 0 ;
T_2 V_286 ;
int V_234 = 0 ;
union V_68 V_69 ;
if ( F_19 ( V_1 ) < V_102 )
return 0 ;
F_24 ( & V_1 -> V_119 ) ;
V_125 = V_286 = V_1 -> V_125 ;
F_25 ( & V_1 -> V_119 ) ;
V_234 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
V_30 = V_69 . V_75 ;
V_234 = F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
V_285 = V_69 . V_75 ;
V_234 = F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
V_253 = V_69 . V_75 ;
V_234 = F_8 ( V_1 , V_56 , 0 , NULL , & V_69 ) ;
V_33 = V_69 . V_75 ;
V_234 = F_8 ( V_1 , V_57 , 0 , NULL , & V_69 ) ;
V_284 = V_69 . V_75 ;
if ( V_234 < 0 )
goto V_287;
switch ( V_283 -> V_203 & V_288 ) {
case V_289 :
case V_290 :
case V_291 :
break;
case V_292 :
if ( V_283 -> V_134 ) {
V_125 = 1 ;
V_285 = 1 ;
V_253 = 1 ;
V_33 = 0x01 ;
V_284 = V_126 ;
V_30 = V_251 ;
} else {
V_125 = 0 ;
V_285 = 0 ;
V_253 = 0 ;
V_33 = 0 ;
V_284 = V_293 ;
}
break;
case V_294 :
if ( V_283 -> V_134 & V_295 ) {
V_125 = 0 ;
V_285 = 0 ;
V_253 = 0 ;
V_33 = 0 ;
V_284 = V_293 ;
} else {
if ( V_283 -> V_134 & V_296 )
V_125 = 1 ;
else if ( V_283 -> V_134 & V_297 )
V_125 = 2 ;
V_285 = 1 ;
V_253 = 1 ;
V_33 = 0x01 ;
V_284 = V_126 ;
V_30 = V_251 ;
}
break;
case V_298 :
V_33 = V_283 -> V_134 ? 0 : 0x01 ;
break;
case V_299 :
V_285 = V_283 -> V_134 ? 1 : 0 ;
break;
case V_300 :
V_253 = V_283 -> V_134 ? 1 : 0 ;
break;
case V_301 :
if ( V_283 -> V_134 & V_302 ) {
if ( V_125 > 0 ) {
V_234 = - V_11 ;
goto V_287;
}
V_30 = V_303 ;
} else if ( V_283 -> V_134 & V_304 ) {
V_30 = V_251 ;
} else {
V_234 = - V_11 ;
goto V_287;
}
break;
default:
return - V_120 ;
}
F_24 ( & V_1 -> V_119 ) ;
V_1 -> V_125 = V_125 ;
F_25 ( & V_1 -> V_119 ) ;
F_17 ( V_1 , V_52 , 0 , & V_30 ) ;
F_17 ( V_1 , V_53 , 0 , & V_285 ) ;
F_17 ( V_1 , V_55 , 0 , & V_253 ) ;
F_17 ( V_1 , V_56 , 0 , & V_33 ) ;
F_17 ( V_1 , V_57 , 0 , & V_284 ) ;
V_287:
return V_234 ;
}
static int F_73 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
union V_281 * V_282 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_130 * V_283 = & V_282 -> V_283 ;
T_2 V_125 = 0 ;
int V_234 = 0 ;
union V_68 V_69 ;
if ( F_19 ( V_1 ) < V_102 )
return 0 ;
F_24 ( & V_1 -> V_119 ) ;
V_125 = V_1 -> V_125 ;
F_25 ( & V_1 -> V_119 ) ;
switch ( V_283 -> V_203 & V_288 ) {
case V_289 :
case V_290 :
case V_291 :
V_234 = - V_120 ;
break;
case V_294 :
switch ( V_125 ) {
case 1 :
V_283 -> V_134 = V_296 ;
break;
case 2 :
V_283 -> V_134 = V_297 ;
break;
case 0 :
default:
V_283 -> V_134 = V_295 ;
break;
}
break;
case V_300 :
V_234 = F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
if ( V_234 >= 0 )
V_283 -> V_134 = V_69 . V_75 > 0 ? 1 : 0 ;
break;
case V_301 :
V_234 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
if ( V_234 >= 0 ) {
switch ( V_69 . V_75 ) {
case V_251 :
V_283 -> V_134 = V_304 ;
break;
case V_269 :
case V_303 :
V_283 -> V_134 = V_302 ;
case V_305 :
default:
V_283 -> V_134 = 0 ;
break;
}
}
break;
case V_292 :
V_283 -> V_134 = V_125 > 0 ? 1 : 0 ;
break;
case V_298 :
V_234 = F_8 ( V_1 , V_56 , 0 , NULL , & V_69 ) ;
if ( V_234 >= 0 )
V_283 -> V_134 = V_69 . V_75 > 0 ? 1 : 0 ;
break;
case V_299 :
V_234 = F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
if ( V_234 >= 0 )
V_283 -> V_134 = V_69 . V_75 > 0 ? 1 : 0 ;
break;
default:
return - V_120 ;
}
return V_234 ;
}
static int F_74 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
union V_281 * V_282 ,
char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_137 * V_306 = & V_282 -> V_306 ;
struct V_307 * V_308 = (struct V_307 * ) V_98 ;
int V_309 , V_310 = V_308 -> V_310 , V_311 = 1 ;
union V_68 V_69 ;
int V_30 = V_251 , V_252 = 0 , V_253 = 0 ;
int V_234 = 0 ;
if ( F_19 ( V_1 ) < V_102 )
return 0 ;
V_309 = ( V_306 -> V_203 & V_255 ) - 1 ;
if ( V_309 ) {
if ( V_309 < 0 || V_309 > 3 )
return - V_11 ;
} else {
V_234 = F_8 ( V_1 , V_260 , 0 , NULL , & V_69 ) ;
if ( V_234 < 0 )
goto V_287;
V_309 = V_69 . V_75 ;
}
if ( V_306 -> V_203 & V_211 )
V_310 = V_312 ;
if ( V_308 -> V_313 & V_314 ) {
V_234 = F_17 ( V_1 , V_260 , 0 , & V_309 ) ;
V_311 = V_308 -> V_315 > 0 ? 1 : 0 ;
}
if ( V_311 ) {
struct V_257 V_258 = { V_259 , 0 , L_8 } ;
switch ( V_310 ) {
case V_312 :
break;
case V_316 :
if ( V_308 -> V_315 > V_262 ) {
V_234 = - V_11 ;
goto V_287;
}
if ( V_308 -> V_315 > V_264 )
V_258 . V_143 = V_262 ;
else
V_258 . V_143 = V_264 ;
break;
case V_317 :
if ( V_308 -> V_315 > V_261 ) {
V_234 = - V_11 ;
goto V_287;
}
V_258 . type = V_263 ;
V_258 . V_143 = V_261 ;
break;
default:
return - V_11 ;
}
if ( V_258 . V_143 ) {
memset ( V_258 . V_258 , 0 , sizeof( V_258 . V_258 ) ) ;
memcpy ( V_258 . V_258 , V_308 -> V_258 , V_308 -> V_315 ) ;
V_234 = F_17 ( V_1 , V_265 , V_309 ,
& V_258 ) ;
if ( V_234 < 0 )
goto V_287;
}
}
if ( V_306 -> V_203 & V_211 ) {
}
if ( V_306 -> V_203 & V_267 ) {
V_252 = 1 ;
}
if ( V_306 -> V_203 & V_268 ) {
V_30 = V_269 ;
V_252 = 1 ;
V_253 = 1 ;
}
if ( V_306 -> V_203 & V_266 ) {
V_234 = F_17 ( V_1 , V_52 , 0 ,
& V_30 ) ;
V_234 = F_17 ( V_1 , V_53 , 0 ,
& V_252 ) ;
V_234 = F_17 ( V_1 , V_55 , 0 ,
& V_253 ) ;
}
V_287:
return V_234 ;
}
static int F_75 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
union V_281 * V_282 ,
char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_137 * V_306 = & V_282 -> V_306 ;
struct V_307 * V_308 = (struct V_307 * ) V_98 ;
int V_309 , V_318 ;
union V_68 V_69 ;
int V_30 = V_251 , V_252 = 0 , V_253 = 0 , V_125 = 0 ;
int V_234 = 0 ;
if ( F_19 ( V_1 ) < V_102 )
return 0 ;
V_234 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
V_30 = V_69 . V_75 ;
V_234 = F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
V_252 = V_69 . V_75 ;
V_234 = F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
V_253 = V_69 . V_75 ;
if ( V_234 < 0 )
goto V_287;
V_318 = V_306 -> V_143 - sizeof( * V_308 ) ;
if ( V_318 < 0 )
return - V_11 ;
V_309 = ( V_306 -> V_203 & V_255 ) - 1 ;
if ( V_309 ) {
if ( V_309 < 0 || V_309 > 3 )
return - V_11 ;
} else {
V_234 = F_8 ( V_1 , V_260 , 0 , NULL , & V_69 ) ;
if ( V_234 < 0 )
goto V_287;
V_309 = V_69 . V_75 ;
}
V_306 -> V_203 = V_309 + 1 ;
memset ( V_308 , 0 , sizeof( * V_308 ) ) ;
switch ( V_30 ) {
case V_269 :
case V_303 :
V_282 -> V_306 . V_203 |= V_268 ;
case V_251 :
default:
V_282 -> V_306 . V_203 |= V_267 ;
break;
}
F_24 ( & V_1 -> V_119 ) ;
V_125 = V_1 -> V_125 ;
F_25 ( & V_1 -> V_119 ) ;
if ( V_30 == V_251 && ! V_253 && ! V_252 && ! V_125 ) {
V_308 -> V_310 = V_312 ;
V_308 -> V_315 = 0 ;
V_282 -> V_306 . V_203 |= V_211 ;
} else {
struct V_257 * V_258 ;
V_234 = F_8 ( V_1 , V_265 , V_309 , NULL , & V_69 ) ;
if ( V_234 < 0 )
goto V_287;
V_258 = V_69 . V_77 ;
if ( V_318 < V_258 -> V_143 ) {
V_234 = - V_227 ;
goto V_287;
}
memcpy ( V_308 -> V_258 , V_258 -> V_258 , V_258 -> V_143 ) ;
V_308 -> V_315 = V_258 -> V_143 ;
switch ( V_258 -> type ) {
case V_263 :
V_308 -> V_310 = V_317 ;
break;
default:
case V_259 :
V_308 -> V_310 = V_316 ;
break;
}
V_282 -> V_306 . V_203 |= V_209 ;
}
V_287:
return V_234 ;
}
static int
F_76 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
F_77 ( F_12 ( V_91 ) , 0 ) ;
return 0 ;
}
static int
F_78 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
union V_68 V_69 ;
int V_101 ;
enum V_319 V_320 = V_138 -> V_203 ;
V_101 = F_8 ( F_12 ( V_91 ) , V_320 , 0 , NULL , & V_69 ) ;
V_138 -> V_143 = F_79 ( V_320 , & V_69 , V_98 ) ;
if ( ( V_321 [ V_320 ] . V_203 & V_322 ) != V_323 )
F_9 ( V_69 . V_77 ) ;
return V_101 ;
}
static int
F_80 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_2 V_324 = V_116 [ 0 ] , V_75 = V_116 [ 1 ] ;
return F_17 ( F_12 ( V_91 ) , V_324 , 0 , & V_75 ) ;
}
static int
F_81 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_2 V_324 = V_138 -> V_203 ;
return F_17 ( F_12 ( V_91 ) , V_324 , 0 , V_98 ) ;
}
void
F_82 ( struct V_325 * V_121 )
{
F_83 ( & V_121 -> V_326 ) ;
F_84 ( & V_121 -> V_327 ) ;
V_121 -> V_39 = 0 ;
V_121 -> V_122 = V_123 ;
}
static void
F_85 ( struct V_325 * V_121 )
{
struct V_328 * V_77 , * V_329 ;
struct V_330 * V_331 ;
F_7 ( & V_121 -> V_326 ) ;
if ( V_121 -> V_39 == 0 ) {
F_10 ( & V_121 -> V_326 ) ;
return;
}
for ( V_77 = V_121 -> V_327 . V_329 , V_329 = V_77 -> V_329 ;
V_77 != & V_121 -> V_327 ; V_77 = V_329 , V_329 = V_77 -> V_329 ) {
V_331 = F_86 ( V_77 , struct V_330 , V_332 ) ;
F_87 ( V_77 ) ;
F_9 ( V_331 ) ;
}
V_121 -> V_39 = 0 ;
F_10 ( & V_121 -> V_326 ) ;
}
void
F_88 ( struct V_325 * V_121 )
{
F_85 ( V_121 ) ;
}
static int
F_89 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_185 * V_186 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_325 * V_121 = & V_1 -> V_121 ;
struct V_330 * V_331 ;
struct V_185 * V_41 = (struct V_185 * ) V_98 ;
if ( V_41 -> V_188 != V_129 )
return - V_120 ;
V_331 = F_90 ( sizeof ( struct V_330 ) , V_276 ) ;
if ( V_331 == NULL )
return - V_277 ;
memcpy ( V_331 -> V_41 , V_41 -> V_189 , V_333 ) ;
if ( F_91 ( & V_121 -> V_326 ) ) {
F_9 ( V_331 ) ;
return - V_334 ;
}
F_92 ( & V_331 -> V_332 , & V_121 -> V_327 ) ;
V_121 -> V_39 ++ ;
F_10 ( & V_121 -> V_326 ) ;
return 0 ;
}
static int
F_93 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_185 * V_186 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_325 * V_121 = & V_1 -> V_121 ;
struct V_330 * V_331 ;
struct V_185 * V_41 = (struct V_185 * ) V_98 ;
if ( V_41 -> V_188 != V_129 )
return - V_120 ;
if ( F_91 ( & V_121 -> V_326 ) )
return - V_334 ;
F_94 (entry, &acl->mac_list, _list) {
if ( memcmp ( V_331 -> V_41 , V_41 -> V_189 , V_333 ) == 0 ) {
F_87 ( & V_331 -> V_332 ) ;
V_121 -> V_39 -- ;
F_9 ( V_331 ) ;
F_10 ( & V_121 -> V_326 ) ;
return 0 ;
}
}
F_10 ( & V_121 -> V_326 ) ;
return - V_11 ;
}
static int
F_95 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_325 * V_121 = & V_1 -> V_121 ;
struct V_330 * V_331 ;
struct V_185 * V_335 = (struct V_185 * ) V_98 ;
V_138 -> V_143 = 0 ;
if ( F_91 ( & V_121 -> V_326 ) )
return - V_334 ;
F_94 (entry, &acl->mac_list, _list) {
memcpy ( V_335 -> V_189 , V_331 -> V_41 , V_333 ) ;
V_335 -> V_188 = V_129 ;
V_138 -> V_143 ++ ;
V_335 ++ ;
}
F_10 ( & V_121 -> V_326 ) ;
return 0 ;
}
static int
F_96 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_325 * V_121 = & V_1 -> V_121 ;
T_2 V_117 ;
F_85 ( V_121 ) ;
if ( ( * V_116 < V_123 ) || ( * V_116 > V_336 ) )
return - V_11 ;
F_24 ( & V_1 -> V_119 ) ;
V_121 -> V_122 = * V_116 ;
if ( ( V_1 -> V_2 == V_19 ) &&
( V_121 -> V_122 != V_123 ) )
V_117 = V_124 ;
else
V_117 = V_48 ;
if ( V_1 -> V_125 )
V_117 = V_126 ;
F_3 ( V_1 , V_57 , & V_117 ) ;
if ( F_26 ( V_1 ) ) {
F_25 ( & V_1 -> V_119 ) ;
return - V_127 ;
}
F_25 ( & V_1 -> V_119 ) ;
return 0 ;
}
static int
F_97 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_325 * V_121 = & V_1 -> V_121 ;
* V_116 = V_121 -> V_122 ;
return 0 ;
}
static int
F_98 ( struct V_325 * V_121 , char * V_337 )
{
struct V_330 * V_331 ;
int V_338 = 0 ;
if ( F_91 ( & V_121 -> V_326 ) )
return - V_334 ;
if ( V_121 -> V_122 == V_123 ) {
F_10 ( & V_121 -> V_326 ) ;
return 1 ;
}
F_94 (entry, &acl->mac_list, _list) {
if ( memcmp ( V_331 -> V_41 , V_337 , V_333 ) == 0 ) {
V_338 = 1 ;
break;
}
}
V_338 = ( V_121 -> V_122 == V_339 ) ? ! V_338 : V_338 ;
F_10 ( & V_121 -> V_326 ) ;
return V_338 ;
}
static int
F_99 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_138 , char * V_98 )
{
struct V_340 * V_34 ;
int V_101 ;
V_34 = F_90 ( sizeof ( struct V_340 ) , V_276 ) ;
if ( V_34 == NULL )
return - V_277 ;
V_34 -> V_278 = 0 ;
V_101 =
F_17 ( F_12 ( V_91 ) , V_341 , 0 , V_34 ) ;
F_9 ( V_34 ) ;
return V_101 ;
}
static int
F_100 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_185 * V_186 , char * V_98 )
{
struct V_340 * V_34 ;
struct V_185 * V_41 = (struct V_185 * ) V_98 ;
int V_101 ;
if ( V_41 -> V_188 != V_129 )
return - V_120 ;
V_34 = F_90 ( sizeof ( struct V_340 ) , V_276 ) ;
if ( V_34 == NULL )
return - V_277 ;
memcpy ( V_34 -> V_78 , V_41 -> V_189 , V_333 ) ;
V_34 -> V_278 = - 1 ;
V_101 =
F_17 ( F_12 ( V_91 ) , V_341 , 0 , V_34 ) ;
F_9 ( V_34 ) ;
return V_101 ;
}
static void
F_101 ( T_1 * V_1 , char * V_342 , const char * V_343 ,
const struct V_340 * V_34 , T_6 * V_143 , int error )
{
int V_320 = snprintf ( V_342 , V_344 ,
L_12 ,
V_343 ,
( ( V_1 -> V_2 == V_19 ) ? L_13 : L_14 ) ,
V_34 -> V_78 ,
( error ? ( V_34 -> V_86 ? L_15 : L_16 )
: L_8 ) , V_34 -> V_86 ) ;
F_28 ( V_320 > V_344 ) ;
* V_143 = V_320 ;
}
static void
F_102 ( T_1 * V_1 , const char * V_343 ,
const struct V_340 * V_34 , int error )
{
union V_281 V_282 ;
char * V_345 ;
V_345 = F_90 ( V_344 , V_276 ) ;
if ( ! V_345 )
return;
V_282 . V_63 . V_346 = V_345 ;
V_282 . V_63 . V_143 = 0 ;
F_101 ( V_1 , V_345 , V_343 , V_34 , & V_282 . V_63 . V_143 ,
error ) ;
F_103 ( V_1 -> V_91 , V_170 , & V_282 , V_345 ) ;
F_9 ( V_345 ) ;
}
static void
F_104 ( T_1 * V_1 , const char * V_343 )
{
union V_281 V_282 ;
char * V_345 ;
int V_320 = strlen ( V_343 ) ;
V_345 = F_90 ( V_344 , V_276 ) ;
if ( ! V_345 )
return;
F_28 ( V_320 >= V_344 ) ;
V_282 . V_63 . V_346 = V_345 ;
V_282 . V_63 . V_143 = V_320 ;
strcpy ( V_345 , V_343 ) ;
F_103 ( V_1 -> V_91 , V_170 , & V_282 , V_345 ) ;
F_9 ( V_345 ) ;
}
static void
F_105 ( struct V_90 * V_91 , T_2 V_183 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
if ( V_183 ) {
F_106 ( V_91 ) ;
if ( V_1 -> V_2 == V_17 ) {
union V_281 V_116 ;
F_35 ( V_91 , NULL , (struct V_185 * ) & V_116 ,
NULL ) ;
F_103 ( V_91 , V_168 , & V_116 , NULL ) ;
} else
F_104 ( F_12 ( V_91 ) ,
L_17 ) ;
} else {
F_107 ( V_91 ) ;
F_104 ( F_12 ( V_91 ) , L_18 ) ;
}
}
static void
F_108 ( T_1 * V_1 , T_4 * V_187 ,
T_4 * V_196 , T_5 V_198 )
{
struct V_328 * V_77 ;
struct V_347 * V_66 = NULL ;
if ( V_198 > V_197 )
V_198 = V_197 ;
F_7 ( & V_1 -> V_348 ) ;
F_109 (ptr, &priv->bss_wpa_list) {
V_66 = F_86 ( V_77 , struct V_347 , V_349 ) ;
if ( memcmp ( V_66 -> V_187 , V_187 , V_333 ) == 0 ) {
F_110 ( & V_66 -> V_349 , & V_1 -> V_350 ) ;
break;
}
V_66 = NULL ;
}
if ( V_66 == NULL ) {
if ( V_1 -> V_351 >= V_352 ) {
V_66 = F_86 ( V_1 -> V_350 . V_353 ,
struct V_347 , V_349 ) ;
F_87 ( & V_66 -> V_349 ) ;
} else {
V_66 = F_66 ( sizeof ( * V_66 ) , V_354 ) ;
if ( V_66 != NULL )
V_1 -> V_351 ++ ;
}
if ( V_66 != NULL ) {
memcpy ( V_66 -> V_187 , V_187 , V_333 ) ;
F_111 ( & V_66 -> V_349 , & V_1 -> V_350 ) ;
}
}
if ( V_66 != NULL ) {
memcpy ( V_66 -> V_196 , V_196 , V_198 ) ;
V_66 -> V_198 = V_198 ;
V_66 -> V_355 = V_93 ;
} else {
F_2 ( V_9 L_19
L_20 , V_187 ) ;
}
while ( V_1 -> V_351 > 0 ) {
V_66 = F_86 ( V_1 -> V_350 . V_353 ,
struct V_347 , V_349 ) ;
if ( ! F_14 ( V_93 , V_66 -> V_355 + 60 * V_94 ) )
break;
F_87 ( & V_66 -> V_349 ) ;
V_1 -> V_351 -- ;
F_9 ( V_66 ) ;
}
F_10 ( & V_1 -> V_348 ) ;
}
static T_5
F_43 ( T_1 * V_1 , T_4 * V_187 , T_4 * V_196 )
{
struct V_328 * V_77 ;
struct V_347 * V_66 = NULL ;
T_5 V_280 = 0 ;
F_7 ( & V_1 -> V_348 ) ;
F_109 (ptr, &priv->bss_wpa_list) {
V_66 = F_86 ( V_77 , struct V_347 , V_349 ) ;
if ( memcmp ( V_66 -> V_187 , V_187 , V_333 ) == 0 )
break;
V_66 = NULL ;
}
if ( V_66 ) {
V_280 = V_66 -> V_198 ;
memcpy ( V_196 , V_66 -> V_196 , V_280 ) ;
}
F_10 ( & V_1 -> V_348 ) ;
return V_280 ;
}
void
F_112 ( T_1 * V_1 )
{
F_84 ( & V_1 -> V_350 ) ;
F_83 ( & V_1 -> V_348 ) ;
}
void
F_113 ( T_1 * V_1 )
{
struct V_347 * V_66 , * V_320 ;
F_114 (bss, n, &priv->bss_wpa_list, list) {
F_9 ( V_66 ) ;
}
}
static void
F_115 ( T_1 * V_1 , T_2 V_324 , T_4 * V_41 ,
T_4 * V_356 , T_5 V_280 )
{
struct V_357 * V_358 ;
T_4 * V_359 , * V_360 ;
if ( ! V_1 -> V_125 )
return;
V_358 = (struct V_357 * ) V_356 ;
V_359 = ( T_4 * ) ( V_358 + 1 ) ;
V_360 = V_356 + V_280 ;
while ( V_359 < V_360 ) {
if ( V_359 + 2 + V_359 [ 1 ] > V_360 ) {
F_2 ( V_9 L_21
L_22 , V_41 ) ;
return;
}
if ( V_359 [ 0 ] == V_361 && V_359 [ 1 ] >= 4 &&
memcmp ( V_359 + 2 , V_362 , 4 ) == 0 ) {
F_108 ( V_1 , V_41 , V_359 , V_359 [ 1 ] + 2 ) ;
return;
}
V_359 += 2 + V_359 [ 1 ] ;
}
}
static void
F_116 ( T_1 * V_1 , struct V_340 * V_34 , enum V_319 V_324 )
{
if ( ( ( V_34 -> V_363 == V_364 ) ||
( V_34 -> V_363 == V_365 ) )
&& F_117 ( V_1 ) ) {
V_34 -> V_86 = F_98 ( & V_1 -> V_121 ,
V_34 -> V_78 ) ? 0 : 1 ;
F_17 ( V_1 , V_324 , 0 , V_34 ) ;
}
}
static int
F_118 ( T_1 * V_1 , enum V_319 V_324 ,
char * V_63 )
{
struct V_340 * V_34 = (struct V_340 * ) V_63 ;
struct V_366 * V_367 = (struct V_366 * ) V_63 ;
struct V_366 * V_368 ;
T_4 V_196 [ V_197 ] ;
int V_198 ;
T_5 V_280 = 0 ;
T_4 * V_356 = NULL , * V_359 = NULL ;
int V_234 ;
if ( V_324 >= V_369 ) {
V_280 = V_367 -> V_39 ;
V_356 = V_359 = V_367 -> V_63 ;
}
if ( ( V_324 == V_369 ) || ( V_324 == V_370 ) )
F_115 ( V_1 , V_324 , V_367 -> V_78 ,
V_356 , V_280 ) ;
F_119 ( V_321 [ V_324 ] . V_203 & V_322 , ( void * ) V_34 ) ;
switch ( V_324 ) {
case V_238 :
F_105 ( V_1 -> V_91 , ( T_2 ) * V_63 ) ;
break;
case V_371 :
F_104 ( V_1 , L_23 ) ;
break;
case V_372 :
F_102 ( V_1 , L_24 , V_34 , 0 ) ;
break;
case V_373 :
F_116 ( V_1 , V_34 , V_324 ) ;
F_102 ( V_1 , L_25 , V_34 , 1 ) ;
break;
case V_341 :
F_102 ( V_1 , L_26 , V_34 , 0 ) ;
break;
case V_374 :
F_116 ( V_1 , V_34 , V_324 ) ;
F_102 ( V_1 , L_27 , V_34 , 1 ) ;
break;
case V_375 :
F_116 ( V_1 , V_34 , V_324 ) ;
F_102 ( V_1 , L_28 , V_34 , 1 ) ;
break;
case V_369 :
F_102 ( V_1 ,
L_29 ,
V_34 , 0 ) ;
break;
case V_370 :
F_102 ( V_1 , L_30 , V_34 ,
0 ) ;
break;
case V_376 :
F_102 ( V_1 , L_24 , V_34 , 0 ) ;
break;
case V_377 :
F_116 ( V_1 , V_34 , V_324 ) ;
F_102 ( V_1 , L_31 , V_34 , 1 ) ;
if ( V_1 -> V_2 != V_19
&& V_367 -> V_363 != V_364 )
break;
V_368 = F_90 ( sizeof( struct V_366 ) + 6 , V_354 ) ;
if ( ! V_368 )
break;
memcpy ( & V_368 -> V_78 , V_367 -> V_78 , V_333 ) ;
F_2 ( V_9 L_32 ,
V_367 -> V_78 ) ;
V_368 -> V_278 = - 1 ;
V_368 -> V_363 = 0 ;
V_368 -> V_86 = 0 ;
V_368 -> V_39 = 6 ;
V_368 -> V_63 [ 0 ] = 0x00 ;
V_368 -> V_63 [ 1 ] = 0x00 ;
V_368 -> V_63 [ 2 ] = 0x02 ;
V_368 -> V_63 [ 3 ] = 0x00 ;
V_368 -> V_63 [ 4 ] = 0x00 ;
V_368 -> V_63 [ 5 ] = 0x00 ;
V_234 = F_70 ( V_1 , V_378 , V_368 , 6 ) ;
F_9 ( V_368 ) ;
if ( V_234 )
return V_234 ;
break;
case V_379 :
F_102 ( V_1 , L_33 , V_34 , 0 ) ;
break;
case V_378 :
F_116 ( V_1 , V_34 , V_324 ) ;
F_102 ( V_1 , L_34 , V_34 , 1 ) ;
if ( V_1 -> V_2 != V_19
&& V_367 -> V_363 != V_365 )
break;
V_368 = F_90 ( sizeof( struct V_366 ) , V_354 ) ;
if ( ! V_368 )
break;
memcpy ( & V_368 -> V_78 , V_367 -> V_78 , V_333 ) ;
V_368 -> V_278 = ( (struct V_366 * ) V_34 ) -> V_278 ;
V_368 -> V_363 = 0 ;
V_368 -> V_86 = 0 ;
V_198 = F_43 ( V_1 , V_367 -> V_78 , V_196 ) ;
if ( ! V_198 ) {
F_2 ( V_9 L_35 ,
V_367 -> V_78 ) ;
F_9 ( V_368 ) ;
break;
}
V_368 -> V_39 = V_198 ;
memcpy ( & V_368 -> V_63 , V_196 , V_198 ) ;
F_70 ( V_1 , V_324 , V_368 , V_198 ) ;
F_9 ( V_368 ) ;
break;
case V_380 :
F_116 ( V_1 , V_34 , V_324 ) ;
F_102 ( V_1 , L_36 , V_34 , 1 ) ;
if ( V_1 -> V_2 != V_19
&& V_367 -> V_363 != V_365 )
break;
V_368 = F_90 ( sizeof( struct V_366 ) , V_354 ) ;
if ( ! V_368 )
break;
memcpy ( & V_368 -> V_78 , V_367 -> V_78 , V_333 ) ;
V_368 -> V_278 = V_367 -> V_278 ;
V_368 -> V_363 = 0 ;
V_368 -> V_86 = 0 ;
V_198 = F_43 ( V_1 , V_367 -> V_78 , V_196 ) ;
if ( ! V_198 ) {
F_2 ( V_9 L_35 ,
V_367 -> V_78 ) ;
F_9 ( V_368 ) ;
break;
}
V_368 -> V_39 = V_198 ;
memcpy ( & V_368 -> V_63 , V_196 , V_198 ) ;
F_70 ( V_1 , V_324 , V_368 , V_198 ) ;
F_9 ( V_368 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
void
F_120 ( struct V_60 * V_61 )
{
struct V_381 * V_382 =
F_6 ( V_61 , struct V_381 , V_383 ) ;
struct V_90 * V_91 = V_382 -> V_91 ;
enum V_319 V_320 = F_121 ( V_382 -> V_384 -> V_324 ) ;
if ( V_320 != V_385 )
F_118 ( F_12 ( V_91 ) , V_320 , V_382 -> V_63 ) ;
F_122 ( V_382 ) ;
}
int
F_123 ( struct V_90 * V_91 , void * V_41 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
int V_234 ;
if ( V_91 -> V_386 != 6 )
return - V_11 ;
V_234 = F_17 ( V_1 , V_387 , 0 ,
& ( (struct V_185 * ) V_41 ) -> V_189 ) ;
if ( ! V_234 )
memcpy ( V_1 -> V_91 -> V_388 ,
& ( (struct V_185 * ) V_41 ) -> V_189 , 6 ) ;
return V_234 ;
}
static int
F_124 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
T_2 V_34 , V_30 , V_33 , V_32 , V_31 ;
if ( F_19 ( V_1 ) < V_102 )
return 0 ;
V_31 = 1 ;
V_32 = 1 ;
V_33 = 0x01 ;
V_34 = V_126 ;
V_30 = V_251 ;
F_24 ( & V_1 -> V_119 ) ;
V_1 -> V_125 = * V_116 ;
switch ( V_1 -> V_125 ) {
default:
case 0 :
V_31 = 0 ;
V_32 = 0 ;
V_33 = 0 ;
V_34 = V_293 ;
F_2 ( L_37 , V_91 -> V_118 ) ;
break;
case 2 :
case 1 :
F_2 ( L_38 , V_91 -> V_118 ) ;
break;
}
F_25 ( & V_1 -> V_119 ) ;
F_17 ( V_1 , V_52 , 0 , & V_30 ) ;
F_17 ( V_1 , V_53 , 0 , & V_31 ) ;
F_17 ( V_1 , V_55 , 0 , & V_32 ) ;
F_17 ( V_1 , V_56 , 0 , & V_33 ) ;
F_17 ( V_1 , V_57 , 0 , & V_34 ) ;
return 0 ;
}
static int
F_125 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
* V_116 = V_1 -> V_125 ;
return 0 ;
}
static int
F_126 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
V_1 -> V_128 =
( * V_116 ? V_389 : V_390 ) ;
if ( V_1 -> V_2 == V_21 )
V_1 -> V_91 -> type = V_1 -> V_128 ;
return 0 ;
}
static int
F_127 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
* V_116 = ( V_1 -> V_128 == V_389 ) ;
return 0 ;
}
static int
F_128 ( struct V_90 * V_91 , struct V_95 * V_96 ,
T_3 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
V_1 -> V_391 = * V_116 ;
F_2 ( L_39 , V_91 -> V_118 , * V_116 ) ;
return 0 ;
}
static int
F_129 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_63 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_381 * V_392 ;
int V_234 = - V_127 ;
F_2 ( L_40 , V_91 -> V_118 , V_1 -> V_391 ) ;
V_63 -> V_143 = 0 ;
if ( F_19 ( V_1 ) >= V_102 ) {
V_234 =
F_130 ( V_1 -> V_91 , V_393 ,
V_1 -> V_391 , V_98 , 256 ,
& V_392 ) ;
F_2 ( L_41 , V_91 -> V_118 , V_234 ) ;
if ( V_234 || ! V_392
|| V_392 -> V_384 -> V_394 == V_395 ) {
if ( V_392 ) {
F_122 ( V_392 ) ;
}
F_2 ( L_42 , V_91 -> V_118 ) ;
V_234 = - V_127 ;
}
if ( ! V_234 ) {
V_63 -> V_143 = V_392 -> V_384 -> V_143 ;
memcpy ( V_98 , V_392 -> V_63 , V_63 -> V_143 ) ;
F_122 ( V_392 ) ;
F_2 ( L_43 , V_91 -> V_118 , V_63 -> V_143 ) ;
}
}
return V_234 ;
}
static int
F_131 ( struct V_90 * V_91 , struct V_95 * V_96 ,
struct V_137 * V_63 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
struct V_381 * V_392 ;
int V_234 = 0 , V_396 = V_395 ;
F_2 ( L_44 , V_91 -> V_118 , V_1 -> V_391 ,
V_63 -> V_143 ) ;
if ( F_19 ( V_1 ) >= V_102 ) {
V_234 =
F_130 ( V_1 -> V_91 , V_397 ,
V_1 -> V_391 , V_98 , V_63 -> V_143 ,
& V_392 ) ;
F_2 ( L_41 , V_91 -> V_118 , V_234 ) ;
if ( V_234 || ! V_392
|| V_392 -> V_384 -> V_394 == V_395 ) {
if ( V_392 ) {
F_122 ( V_392 ) ;
}
F_2 ( L_42 , V_91 -> V_118 ) ;
V_234 = - V_127 ;
}
if ( ! V_234 ) {
V_396 = V_392 -> V_384 -> V_394 ;
F_2 ( L_45 , V_91 -> V_118 ,
V_396 ) ;
F_122 ( V_392 ) ;
}
}
return ( V_234 ? V_234 : - V_113 ) ;
}
static int
F_132 ( struct V_90 * V_91 ,
struct V_95 * V_96 ,
union V_281 * V_116 , char * V_98 )
{
T_1 * V_1 = F_12 ( V_91 ) ;
T_2 V_75 ;
enum V_319 V_324 = V_27 ;
F_24 ( & V_1 -> V_119 ) ;
F_133 ( V_1 , V_27 , & V_75 ) ;
if ( ( V_116 -> V_63 . V_143 == 0 ) && ( V_1 -> V_398 . V_399 > 0 ) )
V_75 &= ~ V_23 ;
else if ( ( V_116 -> V_63 . V_143 > 0 ) && ( V_1 -> V_398 . V_399 == 0 ) )
V_75 |= V_23 ;
F_3 ( V_1 , V_27 , & V_75 ) ;
F_134 ( V_1 , & V_324 , 1 ) ;
F_25 ( & V_1 -> V_119 ) ;
return F_135 ( V_91 , V_96 , V_116 , V_98 ) ;
}
