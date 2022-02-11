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
memcpy ( V_66 . V_78 , V_63 , V_79 ) ;
F_9 ( V_63 ) ;
V_64 = F_8 ( V_1 , V_80 , 0 , ( void * ) & V_66 , & V_69 ) ;
V_67 = V_69 . V_77 ;
V_1 -> V_72 . V_73 . V_81 = V_67 -> V_82 ;
V_1 -> V_72 . V_73 . V_73 =
V_67 -> V_82 - V_1 -> V_83 . V_73 . V_74 ;
F_9 ( V_67 ) ;
V_1 -> V_72 . V_73 . V_84 = 0x7 ;
F_8 ( V_1 , V_85 , 0 , NULL , & V_69 ) ;
V_1 -> V_72 . V_86 . V_87 = V_69 . V_75 ;
F_8 ( V_1 , V_88 , 0 , NULL , & V_69 ) ;
V_1 -> V_72 . V_86 . V_89 = V_69 . V_75 ;
F_10 ( & V_1 -> V_70 ) ;
}
struct V_90 *
F_11 ( struct V_91 * V_92 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
if ( F_13 ( & V_1 -> V_70 ) ) {
memcpy ( & V_1 -> V_83 , & V_1 -> V_72 ,
sizeof ( struct V_90 ) ) ;
V_1 -> V_72 . V_73 . V_84 = 0 ;
F_10 ( & V_1 -> V_70 ) ;
} else
V_1 -> V_83 . V_73 . V_84 = 0 ;
if ( ( V_1 -> V_93 == 0 ) ||
F_14 ( V_94 , V_1 -> V_93 + 1 * V_95 ) ) {
F_15 ( & V_1 -> V_62 ) ;
V_1 -> V_93 = V_94 ;
}
return & V_1 -> V_83 ;
}
static int
F_16 ( struct V_91 * V_92 , struct V_96 * V_97 ,
char * V_98 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
if ( V_1 -> V_2 != V_21 )
return F_17 ( V_1 , V_100 , 0 , NULL ) ;
return 0 ;
}
static int
F_18 ( struct V_91 * V_92 , struct V_96 * V_97 ,
char * V_98 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
char * V_101 ;
union V_68 V_69 ;
int V_102 ;
if ( F_19 ( V_1 ) < V_103 ) {
strncpy ( V_98 , L_3 , V_104 ) ;
return 0 ;
}
V_102 = F_8 ( V_1 , V_105 , 0 , NULL , & V_69 ) ;
switch ( V_69 . V_75 ) {
case V_106 :
V_101 = L_4 ;
break;
case V_107 :
V_101 = L_5 ;
break;
case V_108 :
default:
V_101 = L_6 ;
break;
}
strncpy ( V_98 , V_101 , V_104 ) ;
return V_102 ;
}
static int
F_20 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_109 * V_110 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_102 ;
T_2 V_111 ;
if ( V_110 -> V_112 < 1000 )
V_111 = V_110 -> V_112 ;
else
V_111 = ( V_110 -> V_113 == 1 ) ? F_21 ( V_110 -> V_112 / 100000 ) : 0 ;
V_102 = V_111 ? F_17 ( V_1 , V_51 , 0 , & V_111 ) : - V_11 ;
return ( V_102 ? V_102 : - V_114 ) ;
}
static int
F_22 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_109 * V_110 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_51 , 0 , NULL , & V_69 ) ;
V_110 -> V_115 = V_69 . V_75 ;
V_102 |= F_8 ( V_1 , V_116 , 0 , NULL , & V_69 ) ;
V_110 -> V_112 = V_69 . V_75 ;
V_110 -> V_113 = 3 ;
return V_102 ;
}
static int
F_23 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
T_2 V_118 = V_48 ;
if ( * V_117 > V_21 || * V_117 < V_12 ) {
F_2 ( V_9
L_7 ,
V_1 -> V_92 -> V_119 , V_10 ) ;
return - V_11 ;
}
F_24 ( & V_1 -> V_120 ) ;
if ( F_1 ( V_1 , * V_117 ) ) {
F_25 ( & V_1 -> V_120 ) ;
return - V_121 ;
}
if ( ( * V_117 == V_19 ) && ( V_1 -> V_122 . V_123 != V_124 ) )
V_118 = V_125 ;
if ( V_1 -> V_126 )
V_118 = V_127 ;
F_3 ( V_1 , V_57 , & V_118 ) ;
if ( F_26 ( V_1 ) ) {
F_25 ( & V_1 -> V_120 ) ;
return - V_128 ;
}
V_1 -> V_92 -> type = ( V_1 -> V_2 == V_21 )
? V_1 -> V_129 : V_130 ;
F_25 ( & V_1 -> V_120 ) ;
return 0 ;
}
static int
F_27 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
F_28 ( ( V_1 -> V_2 < V_12 ) || ( V_1 -> V_2 >
V_21 ) ) ;
* V_117 = V_1 -> V_2 ;
return 0 ;
}
static int
F_29 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
T_2 V_133 ;
V_133 = V_132 -> V_134 ? 20 : V_132 -> V_135 ;
return F_17 ( V_1 , V_136 , 0 , & V_133 ) ;
}
static int
F_30 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_136 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = V_69 . V_75 ;
V_132 -> V_134 = ( V_132 -> V_135 == 0 ) ;
V_132 -> V_137 = 1 ;
return V_102 ;
}
static int
F_31 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
struct V_140 * V_141 = (struct V_140 * ) V_99 ;
T_1 * V_1 = F_12 ( V_92 ) ;
T_4 * V_63 ;
int V_115 , V_112 , V_102 ;
struct V_142 * V_143 ;
union V_68 V_69 ;
memset ( V_141 , 0 , sizeof ( struct V_140 ) ) ;
V_139 -> V_144 = sizeof ( struct V_140 ) ;
V_141 -> V_145 = V_146 ;
V_141 -> V_147 = V_148 ;
V_141 -> V_149 = 3 ;
V_141 -> V_150 [ 0 ] = 5 ;
V_141 -> V_150 [ 1 ] = 13 ;
V_141 -> V_150 [ 2 ] = 32 ;
V_141 -> V_151 = 4 ;
V_141 -> V_152 . V_81 = 0 ;
V_141 -> V_152 . V_74 = 0 ;
V_141 -> V_152 . V_73 = 0 ;
V_141 -> V_153 . V_81 = - 80 ;
V_141 -> V_153 . V_74 = 0 ;
V_141 -> V_153 . V_73 = 0 ;
V_141 -> V_154 = 200 ;
V_141 -> V_155 = V_156 | V_157 ;
V_141 -> V_158 = V_156 ;
V_141 -> V_159 = V_157 ;
V_141 -> V_160 = 1 ;
V_141 -> V_161 = 65535 ;
V_141 -> V_162 = 1024 ;
V_141 -> V_163 = 65535 * 1024 ;
V_141 -> V_164 = V_165 ;
V_141 -> V_166 [ 0 ] = ( V_167 |
F_32 ( V_168 ) |
F_32 ( V_169 ) ) ;
V_141 -> V_166 [ 1 ] = V_170 ;
V_141 -> V_166 [ 4 ] = F_32 ( V_171 ) ;
V_141 -> V_172 = V_173 | V_174 |
V_175 ;
if ( F_19 ( V_1 ) < V_103 )
return 0 ;
V_102 =
F_8 ( V_1 , V_176 , 0 , NULL , & V_69 ) ;
V_143 = V_69 . V_77 ;
V_141 -> V_177 = V_143 -> V_178 ;
V_141 -> V_179 = V_143 -> V_178 ;
V_112 = F_33 ( V_180 , ( int ) V_143 -> V_178 ) ;
for ( V_115 = 0 ; V_115 < V_112 ; V_115 ++ ) {
V_141 -> V_143 [ V_115 ] . V_112 = V_143 -> V_181 [ V_115 ] ;
V_141 -> V_143 [ V_115 ] . V_113 = 6 ;
V_141 -> V_143 [ V_115 ] . V_115 = F_21 ( V_143 -> V_181 [ V_115 ] ) ;
}
F_9 ( V_143 ) ;
V_102 |= F_8 ( V_1 , V_182 , 0 , NULL , & V_69 ) ;
V_63 = V_69 . V_77 ;
V_115 = 0 ;
while ( ( V_115 < V_183 ) && ( * V_63 != 0 ) ) {
V_141 -> V_184 [ V_115 ] = * V_63 * 500000 ;
V_115 ++ ;
V_63 ++ ;
}
V_141 -> V_185 = V_115 ;
F_9 ( V_69 . V_77 ) ;
return V_102 ;
}
static int
F_34 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_186 * V_187 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
char V_188 [ 6 ] ;
int V_102 ;
if ( V_187 -> V_189 != V_130 )
return - V_11 ;
memcpy ( & V_188 [ 0 ] , V_187 -> V_190 , V_79 ) ;
V_102 = F_17 ( V_1 , V_76 , 0 , & V_188 ) ;
return ( V_102 ? V_102 : - V_114 ) ;
}
static int
F_35 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_186 * V_187 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_76 , 0 , NULL , & V_69 ) ;
memcpy ( V_187 -> V_190 , V_69 . V_77 , V_79 ) ;
V_187 -> V_189 = V_130 ;
F_9 ( V_69 . V_77 ) ;
return V_102 ;
}
static int
F_36 ( struct V_91 * V_191 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
return 0 ;
}
static char *
F_37 ( struct V_91 * V_92 , struct V_96 * V_97 ,
char * V_192 , char * V_193 , struct V_65 * V_66 ,
char V_74 )
{
struct V_194 V_195 ;
short V_196 ;
T_1 * V_1 = F_12 ( V_92 ) ;
T_4 V_197 [ V_198 ] ;
T_5 V_199 ;
memcpy ( V_195 . V_75 . V_200 . V_190 , V_66 -> V_78 , V_79 ) ;
V_195 . V_75 . V_200 . V_189 = V_130 ;
V_195 . V_201 = V_169 ;
V_192 = F_38 ( V_97 , V_192 , V_193 ,
& V_195 , V_202 ) ;
V_195 . V_75 . V_63 . V_144 = V_66 -> V_203 . V_144 ;
V_195 . V_75 . V_63 . V_204 = 1 ;
V_195 . V_201 = V_205 ;
V_192 = F_39 ( V_97 , V_192 , V_193 ,
& V_195 , V_66 -> V_203 . V_206 ) ;
#define F_40 0x01
#define F_41 0x02
#define F_42 0x10
V_196 = V_66 -> V_207 ;
V_195 . V_75 . V_5 = 0 ;
if ( V_196 & F_40 )
V_195 . V_75 . V_5 = V_19 ;
else if ( V_196 & F_41 )
V_195 . V_75 . V_5 = V_15 ;
V_195 . V_201 = V_208 ;
if ( V_195 . V_75 . V_5 )
V_192 = F_38 ( V_97 , V_192 , V_193 ,
& V_195 , V_209 ) ;
if ( V_196 & F_42 )
V_195 . V_75 . V_63 . V_204 = V_210 | V_211 ;
else
V_195 . V_75 . V_63 . V_204 = V_212 ;
V_195 . V_75 . V_63 . V_144 = 0 ;
V_195 . V_201 = V_213 ;
V_192 = F_39 ( V_97 , V_192 , V_193 ,
& V_195 , NULL ) ;
V_195 . V_75 . V_143 . V_112 = V_66 -> V_29 ;
V_195 . V_75 . V_143 . V_113 = 6 ;
V_195 . V_201 = V_214 ;
V_192 = F_38 ( V_97 , V_192 , V_193 ,
& V_195 , V_215 ) ;
V_195 . V_75 . V_73 . V_81 = V_66 -> V_82 ;
V_195 . V_75 . V_73 . V_74 = V_74 ;
V_195 . V_75 . V_73 . V_73 = V_66 -> V_82 - V_74 ;
V_195 . V_201 = V_216 ;
V_192 = F_38 ( V_97 , V_192 , V_193 ,
& V_195 , V_217 ) ;
V_199 = F_43 ( V_1 , V_66 -> V_78 , V_197 ) ;
if ( V_199 > 0 ) {
V_195 . V_201 = V_218 ;
V_195 . V_75 . V_63 . V_144 = F_44 ( T_5 , V_199 , V_198 ) ;
V_192 = F_39 ( V_97 , V_192 , V_193 ,
& V_195 , V_197 ) ;
}
{
char * V_219 = V_192 + F_45 ( V_97 ) ;
int V_115 ;
int V_220 ;
V_195 . V_201 = V_221 ;
V_195 . V_75 . V_184 . V_137 = V_195 . V_75 . V_184 . V_134 = 0 ;
V_220 = 0x1 ;
for( V_115 = 0 ; V_115 < sizeof( V_222 ) ; V_115 ++ ) {
if( V_66 -> V_223 & V_220 ) {
V_195 . V_75 . V_184 . V_135 = ( V_222 [ V_115 ] * 500000 ) ;
V_219 = F_46 (
V_97 , V_192 , V_219 ,
V_193 , & V_195 , V_224 ) ;
}
V_220 <<= 1 ;
}
if ( ( V_219 - V_192 ) > F_45 ( V_97 ) )
V_192 = V_219 ;
}
return V_192 ;
}
static int
F_47 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_115 , V_102 ;
struct V_225 * V_226 ;
T_2 V_74 = 0 ;
char * V_192 = V_99 ;
union V_68 V_69 ;
if ( F_19 ( V_1 ) < V_103 ) {
V_139 -> V_144 = 0 ;
return 0 ;
}
V_102 = F_8 ( V_1 , V_71 , 0 , NULL , & V_69 ) ;
V_74 = V_69 . V_75 ;
V_102 |= F_8 ( V_1 , V_227 , 0 , NULL , & V_69 ) ;
V_226 = V_69 . V_77 ;
for ( V_115 = 0 ; V_115 < ( int ) V_226 -> V_178 ; V_115 ++ ) {
V_192 = F_37 ( V_92 , V_97 , V_192 ,
V_99 + V_139 -> V_144 ,
& ( V_226 -> V_226 [ V_115 ] ) ,
V_74 ) ;
if( ( V_99 + V_139 -> V_144 - V_192 ) <= V_202 ) {
V_102 = - V_228 ;
break;
}
}
F_9 ( V_226 ) ;
V_139 -> V_144 = ( V_192 - V_99 ) ;
V_139 -> V_204 = 0 ;
return V_102 ;
}
static int
F_48 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_229 V_230 ;
memset ( V_230 . V_206 , 0 , 33 ) ;
if ( V_139 -> V_204 && V_139 -> V_144 ) {
if ( V_139 -> V_144 > 32 )
return - V_228 ;
V_230 . V_144 = V_139 -> V_144 ;
memcpy ( V_230 . V_206 , V_99 , V_139 -> V_144 ) ;
} else
V_230 . V_144 = 0 ;
if ( V_1 -> V_2 != V_21 )
return F_17 ( V_1 , V_100 , 0 , & V_230 ) ;
F_3 ( V_1 , V_100 , & V_230 ) ;
return 0 ;
}
static int
F_49 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_229 * V_230 ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_100 , 0 , NULL , & V_69 ) ;
V_230 = V_69 . V_77 ;
if ( V_230 -> V_144 ) {
V_139 -> V_204 = 1 ;
V_139 -> V_144 = F_33 ( ( T_4 ) V_231 , V_230 -> V_144 ) ;
} else {
V_139 -> V_204 = 0 ;
V_139 -> V_144 = 0 ;
}
V_230 -> V_206 [ V_139 -> V_144 ] = '\0' ;
memcpy ( V_99 , V_230 -> V_206 , V_139 -> V_144 ) ;
F_9 ( V_230 ) ;
return V_102 ;
}
static int
F_50 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
if ( V_139 -> V_144 > V_231 )
return - V_228 ;
F_24 ( & V_1 -> V_120 ) ;
memset ( V_1 -> V_232 , 0 , sizeof ( V_1 -> V_232 ) ) ;
memcpy ( V_1 -> V_232 , V_99 , V_139 -> V_144 ) ;
F_25 ( & V_1 -> V_120 ) ;
return 0 ;
}
static int
F_51 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
V_139 -> V_144 = 0 ;
F_52 ( & V_1 -> V_120 ) ;
V_139 -> V_144 = strlen ( V_1 -> V_232 ) ;
memcpy ( V_99 , V_1 -> V_232 , V_139 -> V_144 ) ;
F_53 ( & V_1 -> V_120 ) ;
return 0 ;
}
static int
F_54 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
T_2 V_233 , V_234 ;
char * V_63 ;
int V_235 , V_115 ;
union V_68 V_69 ;
if ( V_132 -> V_135 == - 1 ) {
V_234 = 1 ;
return F_17 ( V_1 , V_236 , 0 , & V_234 ) ;
}
V_235 = F_8 ( V_1 , V_182 , 0 , NULL , & V_69 ) ;
if ( V_235 ) {
F_9 ( V_69 . V_77 ) ;
return V_235 ;
}
V_233 = ( T_2 ) ( V_132 -> V_135 / 500000 ) ;
V_63 = V_69 . V_77 ;
V_115 = 0 ;
while ( V_63 [ V_115 ] ) {
if ( V_233 && ( V_63 [ V_115 ] == V_233 ) ) {
break;
}
if ( V_132 -> V_135 == V_115 ) {
break;
}
V_63 [ V_115 ] |= 0x80 ;
V_115 ++ ;
}
if ( ! V_63 [ V_115 ] ) {
F_9 ( V_69 . V_77 ) ;
return - V_11 ;
}
V_63 [ V_115 ] |= 0x80 ;
V_63 [ V_115 + 1 ] = 0 ;
if ( V_132 -> V_137 ) {
V_63 [ 0 ] = V_63 [ V_115 ] ;
V_63 [ 1 ] = 0 ;
}
V_234 = - 1 ;
V_235 = F_17 ( V_1 , V_236 , 0 , & V_234 ) ;
V_235 |= F_17 ( V_1 , V_237 , 0 , V_63 ) ;
V_235 |= F_17 ( V_1 , V_238 , 0 , V_63 ) ;
F_9 ( V_69 . V_77 ) ;
return V_235 ;
}
static int
F_55 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_102 ;
char * V_63 ;
union V_68 V_69 ;
if ( ( V_102 = F_8 ( V_1 , V_239 , 0 , NULL , & V_69 ) ) )
return V_102 ;
V_132 -> V_135 = V_69 . V_75 * 500000 ;
V_102 = F_8 ( V_1 , V_238 , 0 , NULL , & V_69 ) ;
if ( V_102 ) {
F_9 ( V_69 . V_77 ) ;
return V_102 ;
}
V_63 = V_69 . V_77 ;
V_132 -> V_137 = ( V_63 [ 0 ] != 0 ) && ( V_63 [ 1 ] == 0 ) ;
F_9 ( V_69 . V_77 ) ;
return 0 ;
}
static int
F_56 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
return F_17 ( V_1 , V_240 , 0 , & V_132 -> V_135 ) ;
}
static int
F_57 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_240 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = V_69 . V_75 ;
return V_102 ;
}
static int
F_58 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
return F_17 ( V_1 , V_241 , 0 , & V_132 -> V_135 ) ;
}
static int
F_59 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_241 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = V_69 . V_75 ;
return V_102 ;
}
static int
F_60 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
T_2 V_242 = 0 , V_243 = 0 ;
T_2 V_244 = 0 ;
int V_102 = 0 ;
if ( V_132 -> V_134 )
return - V_11 ;
if ( V_132 -> V_204 & V_156 ) {
if ( V_132 -> V_204 & V_245 )
V_242 = V_132 -> V_135 ;
else if ( V_132 -> V_204 & V_246 )
V_243 = V_132 -> V_135 ;
else {
V_242 = V_132 -> V_135 ;
V_243 = V_132 -> V_135 ;
}
}
if ( V_132 -> V_204 & V_157 )
V_244 = V_132 -> V_135 / 1024 ;
if ( V_242 )
V_102 =
F_17 ( V_1 , V_247 , 0 , & V_242 ) ;
if ( V_243 )
V_102 |=
F_17 ( V_1 , V_248 , 0 , & V_243 ) ;
if ( V_244 )
V_102 |=
F_17 ( V_1 , V_249 , 0 ,
& V_244 ) ;
return V_102 ;
}
static int
F_61 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 = 0 ;
V_132 -> V_134 = 0 ;
if ( ( V_132 -> V_204 & V_250 ) == V_157 ) {
V_102 =
F_8 ( V_1 , V_249 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = V_69 . V_75 * 1024 ;
V_132 -> V_204 = V_157 ;
} else if ( ( V_132 -> V_204 & V_246 ) ) {
V_102 |=
F_8 ( V_1 , V_248 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = V_69 . V_75 ;
V_132 -> V_204 = V_156 | V_246 ;
} else {
V_102 |=
F_8 ( V_1 , V_247 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = V_69 . V_75 ;
V_132 -> V_204 = V_156 | V_245 ;
}
return V_102 ;
}
static int
F_62 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_102 = 0 , V_251 = 0 ;
int V_30 = V_252 , V_253 = 0 , V_254 = 0 ;
union V_68 V_69 ;
if ( V_139 -> V_144 > 0 ) {
int V_255 = ( V_139 -> V_204 & V_256 ) - 1 ;
int V_257 ;
struct V_258 V_259 = { V_260 , 0 , L_8 } ;
V_102 = F_8 ( V_1 , V_261 , 0 , NULL , & V_69 ) ;
V_257 = V_69 . V_75 ;
if ( ! ( V_139 -> V_204 & V_211 ) ) {
if ( V_139 -> V_144 > V_262 ) {
return - V_11 ;
}
if ( V_139 -> V_144 > V_263 ) {
V_259 . type = V_264 ;
V_259 . V_144 = V_262 ;
} else if ( V_139 -> V_144 > V_265 ) {
V_259 . V_144 = V_263 ;
} else {
V_259 . V_144 = V_265 ;
}
memset ( V_259 . V_259 , 0 , sizeof ( V_259 . V_259 ) ) ;
memcpy ( V_259 . V_259 , V_99 , V_139 -> V_144 ) ;
if ( ( V_255 < 0 ) || ( V_255 > 3 ) )
V_255 = V_257 ;
V_102 |=
F_17 ( V_1 , V_266 , V_255 ,
& V_259 ) ;
}
if ( ( V_255 == V_257 ) && ( V_259 . V_144 > 0 ) )
V_251 = 1 ;
} else {
int V_255 = ( V_139 -> V_204 & V_256 ) - 1 ;
if ( ( V_255 >= 0 ) && ( V_255 <= 3 ) ) {
V_102 |=
F_17 ( V_1 , V_261 , 0 ,
& V_255 ) ;
} else {
if ( ! ( V_139 -> V_204 & V_267 ) ) {
return - V_11 ;
}
}
}
if ( V_139 -> V_204 & V_212 ) {
}
if ( V_139 -> V_204 & V_268 )
V_253 = 1 ;
if ( ( V_139 -> V_204 & V_269 ) || V_251 ) {
V_30 = V_270 ;
V_253 = 1 ;
V_254 = 1 ;
}
if ( ( V_139 -> V_204 & V_267 ) || V_251 ) {
V_102 |=
F_17 ( V_1 , V_52 , 0 , & V_30 ) ;
V_102 |=
F_17 ( V_1 , V_53 , 0 , & V_253 ) ;
V_102 |=
F_17 ( V_1 , V_55 , 0 ,
& V_254 ) ;
}
return V_102 ;
}
static int
F_63 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_258 * V_259 ;
T_2 V_271 , V_255 = ( V_139 -> V_204 & V_256 ) - 1 ;
T_2 V_30 = 0 , V_253 = 0 , V_254 = 0 ;
int V_102 ;
union V_68 V_69 ;
V_102 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
V_30 = V_69 . V_75 ;
V_102 |= F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
V_253 = V_69 . V_75 ;
V_102 |= F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
V_254 = V_69 . V_75 ;
if ( V_253 && ( V_30 == V_270 ) && V_254 )
V_139 -> V_204 = V_269 ;
else if ( ( V_30 == V_252 ) && ! V_254 ) {
if ( V_253 )
V_139 -> V_204 = V_268 ;
else
V_139 -> V_204 = V_212 ;
} else
V_139 -> V_204 = 0 ;
V_102 |= F_8 ( V_1 , V_261 , 0 , NULL , & V_69 ) ;
V_271 = V_69 . V_75 ;
if ( V_255 == - 1 || V_255 > 3 )
V_255 = V_271 ;
V_102 |= F_8 ( V_1 , V_266 , V_255 , NULL , & V_69 ) ;
V_259 = V_69 . V_77 ;
V_139 -> V_144 = V_259 -> V_144 ;
memcpy ( V_99 , V_259 -> V_259 , V_139 -> V_144 ) ;
F_9 ( V_259 ) ;
V_139 -> V_204 |= V_271 + 1 ;
return V_102 ;
}
static int
F_64 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
union V_68 V_69 ;
int V_102 ;
V_102 = F_8 ( V_1 , V_59 , 0 , NULL , & V_69 ) ;
V_132 -> V_135 = ( V_272 ) V_69 . V_75 / 4 ;
V_132 -> V_137 = 1 ;
V_132 -> V_134 = 0 ;
return V_102 ;
}
static int
F_65 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_131 * V_132 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
V_272 V_75 = V_132 -> V_135 ;
V_75 *= 4 ;
if ( V_132 -> V_134 ) {
F_2 ( V_9
L_9 ,
V_1 -> V_92 -> V_119 , V_10 ) ;
return - V_273 ;
} else if ( V_132 -> V_137 )
return F_17 ( V_1 , V_59 , 0 , & V_75 ) ;
else {
F_2 ( V_9
L_10 ,
V_1 -> V_92 -> V_119 , V_10 ) ;
return - V_273 ;
}
}
static int F_66 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
struct V_138 * V_63 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_274 , V_235 = 0 ;
struct V_275 * V_276 ;
if ( V_63 -> V_144 > V_198 ||
( V_63 -> V_144 && V_99 == NULL ) )
return - V_11 ;
memcpy ( V_1 -> V_197 , V_99 , V_63 -> V_144 ) ;
V_1 -> V_199 = V_63 -> V_144 ;
V_274 = sizeof( * V_276 ) + V_1 -> V_199 ;
V_276 = F_67 ( V_274 , V_277 ) ;
if ( V_276 == NULL )
return - V_278 ;
#define F_68 0
#define F_69 0
#define F_70 2
V_276 -> type = ( F_68 << 2 ) |
( F_69 << 4 ) ;
V_276 -> V_279 = - 1 ;
V_276 -> V_39 = V_1 -> V_199 ;
memcpy ( V_276 -> V_63 , V_99 , V_1 -> V_199 ) ;
V_235 = F_71 ( V_1 , V_280 , V_276 ,
V_1 -> V_199 ) ;
if ( V_235 == 0 ) {
V_276 -> type = ( F_68 << 2 ) |
( F_70 << 4 ) ;
V_235 = F_71 ( V_1 , V_280 , V_276 ,
V_1 -> V_199 ) ;
if ( V_235 == 0 )
F_2 ( V_9 L_11 ,
V_92 -> V_119 ) ;
}
F_9 ( V_276 ) ;
return V_235 ;
}
static int F_72 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
struct V_138 * V_63 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_281 = V_1 -> V_199 ;
if ( V_281 <= 0 ) {
V_63 -> V_144 = 0 ;
return 0 ;
}
if ( V_63 -> V_144 < V_281 )
return - V_228 ;
V_63 -> V_144 = V_281 ;
memcpy ( V_99 , V_1 -> V_197 , V_281 ) ;
return 0 ;
}
static int F_73 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
union V_282 * V_283 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_131 * V_284 = & V_283 -> V_284 ;
T_2 V_285 = 0 , V_30 = 0 , V_33 = 0 ;
T_2 V_254 = 0 , V_286 = 0 , V_126 = 0 ;
T_2 V_287 ;
int V_235 = 0 ;
union V_68 V_69 ;
if ( F_19 ( V_1 ) < V_103 )
return 0 ;
F_24 ( & V_1 -> V_120 ) ;
V_126 = V_287 = V_1 -> V_126 ;
F_25 ( & V_1 -> V_120 ) ;
V_235 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
V_30 = V_69 . V_75 ;
V_235 = F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
V_286 = V_69 . V_75 ;
V_235 = F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
V_254 = V_69 . V_75 ;
V_235 = F_8 ( V_1 , V_56 , 0 , NULL , & V_69 ) ;
V_33 = V_69 . V_75 ;
V_235 = F_8 ( V_1 , V_57 , 0 , NULL , & V_69 ) ;
V_285 = V_69 . V_75 ;
if ( V_235 < 0 )
goto V_288;
switch ( V_284 -> V_204 & V_289 ) {
case V_290 :
case V_291 :
case V_292 :
break;
case V_293 :
if ( V_284 -> V_135 ) {
V_126 = 1 ;
V_286 = 1 ;
V_254 = 1 ;
V_33 = 0x01 ;
V_285 = V_127 ;
V_30 = V_252 ;
} else {
V_126 = 0 ;
V_286 = 0 ;
V_254 = 0 ;
V_33 = 0 ;
V_285 = V_294 ;
}
break;
case V_295 :
if ( V_284 -> V_135 & V_296 ) {
V_126 = 0 ;
V_286 = 0 ;
V_254 = 0 ;
V_33 = 0 ;
V_285 = V_294 ;
} else {
if ( V_284 -> V_135 & V_297 )
V_126 = 1 ;
else if ( V_284 -> V_135 & V_298 )
V_126 = 2 ;
V_286 = 1 ;
V_254 = 1 ;
V_33 = 0x01 ;
V_285 = V_127 ;
V_30 = V_252 ;
}
break;
case V_299 :
V_33 = V_284 -> V_135 ? 0 : 0x01 ;
break;
case V_300 :
V_286 = V_284 -> V_135 ? 1 : 0 ;
break;
case V_301 :
V_254 = V_284 -> V_135 ? 1 : 0 ;
break;
case V_302 :
if ( V_284 -> V_135 & V_303 ) {
if ( V_126 > 0 ) {
V_235 = - V_11 ;
goto V_288;
}
V_30 = V_304 ;
} else if ( V_284 -> V_135 & V_305 ) {
V_30 = V_252 ;
} else {
V_235 = - V_11 ;
goto V_288;
}
break;
default:
return - V_121 ;
}
F_24 ( & V_1 -> V_120 ) ;
V_1 -> V_126 = V_126 ;
F_25 ( & V_1 -> V_120 ) ;
F_17 ( V_1 , V_52 , 0 , & V_30 ) ;
F_17 ( V_1 , V_53 , 0 , & V_286 ) ;
F_17 ( V_1 , V_55 , 0 , & V_254 ) ;
F_17 ( V_1 , V_56 , 0 , & V_33 ) ;
F_17 ( V_1 , V_57 , 0 , & V_285 ) ;
V_288:
return V_235 ;
}
static int F_74 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
union V_282 * V_283 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_131 * V_284 = & V_283 -> V_284 ;
T_2 V_126 = 0 ;
int V_235 = 0 ;
union V_68 V_69 ;
if ( F_19 ( V_1 ) < V_103 )
return 0 ;
F_24 ( & V_1 -> V_120 ) ;
V_126 = V_1 -> V_126 ;
F_25 ( & V_1 -> V_120 ) ;
switch ( V_284 -> V_204 & V_289 ) {
case V_290 :
case V_291 :
case V_292 :
V_235 = - V_121 ;
break;
case V_295 :
switch ( V_126 ) {
case 1 :
V_284 -> V_135 = V_297 ;
break;
case 2 :
V_284 -> V_135 = V_298 ;
break;
case 0 :
default:
V_284 -> V_135 = V_296 ;
break;
}
break;
case V_301 :
V_235 = F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
if ( V_235 >= 0 )
V_284 -> V_135 = V_69 . V_75 > 0 ? 1 : 0 ;
break;
case V_302 :
V_235 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
if ( V_235 >= 0 ) {
switch ( V_69 . V_75 ) {
case V_252 :
V_284 -> V_135 = V_305 ;
break;
case V_270 :
case V_304 :
V_284 -> V_135 = V_303 ;
break;
case V_306 :
default:
V_284 -> V_135 = 0 ;
break;
}
}
break;
case V_293 :
V_284 -> V_135 = V_126 > 0 ? 1 : 0 ;
break;
case V_299 :
V_235 = F_8 ( V_1 , V_56 , 0 , NULL , & V_69 ) ;
if ( V_235 >= 0 )
V_284 -> V_135 = V_69 . V_75 > 0 ? 1 : 0 ;
break;
case V_300 :
V_235 = F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
if ( V_235 >= 0 )
V_284 -> V_135 = V_69 . V_75 > 0 ? 1 : 0 ;
break;
default:
return - V_121 ;
}
return V_235 ;
}
static int F_75 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
union V_282 * V_283 ,
char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_138 * V_307 = & V_283 -> V_307 ;
struct V_308 * V_309 = (struct V_308 * ) V_99 ;
int V_310 , V_311 = V_309 -> V_311 , V_312 = 1 ;
union V_68 V_69 ;
int V_30 = V_252 , V_253 = 0 , V_254 = 0 ;
int V_235 = 0 ;
if ( F_19 ( V_1 ) < V_103 )
return 0 ;
V_310 = ( V_307 -> V_204 & V_256 ) - 1 ;
if ( V_310 ) {
if ( V_310 < 0 || V_310 > 3 )
return - V_11 ;
} else {
V_235 = F_8 ( V_1 , V_261 , 0 , NULL , & V_69 ) ;
if ( V_235 < 0 )
goto V_288;
V_310 = V_69 . V_75 ;
}
if ( V_307 -> V_204 & V_212 )
V_311 = V_313 ;
if ( V_309 -> V_314 & V_315 ) {
V_235 = F_17 ( V_1 , V_261 , 0 , & V_310 ) ;
V_312 = V_309 -> V_316 > 0 ? 1 : 0 ;
}
if ( V_312 ) {
struct V_258 V_259 = { V_260 , 0 , L_8 } ;
switch ( V_311 ) {
case V_313 :
break;
case V_317 :
if ( V_309 -> V_316 > V_263 ) {
V_235 = - V_11 ;
goto V_288;
}
if ( V_309 -> V_316 > V_265 )
V_259 . V_144 = V_263 ;
else
V_259 . V_144 = V_265 ;
break;
case V_318 :
if ( V_309 -> V_316 > V_262 ) {
V_235 = - V_11 ;
goto V_288;
}
V_259 . type = V_264 ;
V_259 . V_144 = V_262 ;
break;
default:
return - V_11 ;
}
if ( V_259 . V_144 ) {
memset ( V_259 . V_259 , 0 , sizeof( V_259 . V_259 ) ) ;
memcpy ( V_259 . V_259 , V_309 -> V_259 , V_309 -> V_316 ) ;
V_235 = F_17 ( V_1 , V_266 , V_310 ,
& V_259 ) ;
if ( V_235 < 0 )
goto V_288;
}
}
if ( V_307 -> V_204 & V_212 ) {
}
if ( V_307 -> V_204 & V_268 ) {
V_253 = 1 ;
}
if ( V_307 -> V_204 & V_269 ) {
V_30 = V_270 ;
V_253 = 1 ;
V_254 = 1 ;
}
if ( V_307 -> V_204 & V_267 ) {
V_235 = F_17 ( V_1 , V_52 , 0 ,
& V_30 ) ;
V_235 = F_17 ( V_1 , V_53 , 0 ,
& V_253 ) ;
V_235 = F_17 ( V_1 , V_55 , 0 ,
& V_254 ) ;
}
V_288:
return V_235 ;
}
static int F_76 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
union V_282 * V_283 ,
char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_138 * V_307 = & V_283 -> V_307 ;
struct V_308 * V_309 = (struct V_308 * ) V_99 ;
int V_310 , V_319 ;
union V_68 V_69 ;
int V_30 = V_252 , V_253 = 0 , V_254 = 0 , V_126 = 0 ;
int V_235 = 0 ;
if ( F_19 ( V_1 ) < V_103 )
return 0 ;
V_235 = F_8 ( V_1 , V_52 , 0 , NULL , & V_69 ) ;
V_30 = V_69 . V_75 ;
V_235 = F_8 ( V_1 , V_53 , 0 , NULL , & V_69 ) ;
V_253 = V_69 . V_75 ;
V_235 = F_8 ( V_1 , V_55 , 0 , NULL , & V_69 ) ;
V_254 = V_69 . V_75 ;
if ( V_235 < 0 )
goto V_288;
V_319 = V_307 -> V_144 - sizeof( * V_309 ) ;
if ( V_319 < 0 )
return - V_11 ;
V_310 = ( V_307 -> V_204 & V_256 ) - 1 ;
if ( V_310 ) {
if ( V_310 < 0 || V_310 > 3 )
return - V_11 ;
} else {
V_235 = F_8 ( V_1 , V_261 , 0 , NULL , & V_69 ) ;
if ( V_235 < 0 )
goto V_288;
V_310 = V_69 . V_75 ;
}
V_307 -> V_204 = V_310 + 1 ;
memset ( V_309 , 0 , sizeof( * V_309 ) ) ;
switch ( V_30 ) {
case V_270 :
case V_304 :
V_283 -> V_307 . V_204 |= V_269 ;
case V_252 :
default:
V_283 -> V_307 . V_204 |= V_268 ;
break;
}
F_24 ( & V_1 -> V_120 ) ;
V_126 = V_1 -> V_126 ;
F_25 ( & V_1 -> V_120 ) ;
if ( V_30 == V_252 && ! V_254 && ! V_253 && ! V_126 ) {
V_309 -> V_311 = V_313 ;
V_309 -> V_316 = 0 ;
V_283 -> V_307 . V_204 |= V_212 ;
} else {
struct V_258 * V_259 ;
V_235 = F_8 ( V_1 , V_266 , V_310 , NULL , & V_69 ) ;
if ( V_235 < 0 )
goto V_288;
V_259 = V_69 . V_77 ;
if ( V_319 < V_259 -> V_144 ) {
V_235 = - V_228 ;
goto V_288;
}
memcpy ( V_309 -> V_259 , V_259 -> V_259 , V_259 -> V_144 ) ;
V_309 -> V_316 = V_259 -> V_144 ;
switch ( V_259 -> type ) {
case V_264 :
V_309 -> V_311 = V_318 ;
break;
default:
case V_260 :
V_309 -> V_311 = V_317 ;
break;
}
V_283 -> V_307 . V_204 |= V_210 ;
}
V_288:
return V_235 ;
}
static int
F_77 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
F_78 ( F_12 ( V_92 ) , 0 ) ;
return 0 ;
}
static int
F_79 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
union V_68 V_69 ;
int V_102 ;
enum V_320 V_321 = V_139 -> V_204 ;
V_102 = F_8 ( F_12 ( V_92 ) , V_321 , 0 , NULL , & V_69 ) ;
V_139 -> V_144 = F_80 ( V_321 , & V_69 , V_99 ) ;
if ( ( V_322 [ V_321 ] . V_204 & V_323 ) != V_324 )
F_9 ( V_69 . V_77 ) ;
return V_102 ;
}
static int
F_81 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_2 V_325 = V_117 [ 0 ] , V_75 = V_117 [ 1 ] ;
return F_17 ( F_12 ( V_92 ) , V_325 , 0 , & V_75 ) ;
}
static int
F_82 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_2 V_325 = V_139 -> V_204 ;
return F_17 ( F_12 ( V_92 ) , V_325 , 0 , V_99 ) ;
}
void
F_83 ( struct V_326 * V_122 )
{
F_84 ( & V_122 -> V_327 ) ;
F_85 ( & V_122 -> V_328 ) ;
V_122 -> V_39 = 0 ;
V_122 -> V_123 = V_124 ;
}
static void
F_86 ( struct V_326 * V_122 )
{
struct V_329 * V_77 , * V_330 ;
struct V_331 * V_332 ;
F_7 ( & V_122 -> V_327 ) ;
if ( V_122 -> V_39 == 0 ) {
F_10 ( & V_122 -> V_327 ) ;
return;
}
for ( V_77 = V_122 -> V_328 . V_330 , V_330 = V_77 -> V_330 ;
V_77 != & V_122 -> V_328 ; V_77 = V_330 , V_330 = V_77 -> V_330 ) {
V_332 = F_87 ( V_77 , struct V_331 , V_333 ) ;
F_88 ( V_77 ) ;
F_9 ( V_332 ) ;
}
V_122 -> V_39 = 0 ;
F_10 ( & V_122 -> V_327 ) ;
}
void
F_89 ( struct V_326 * V_122 )
{
F_86 ( V_122 ) ;
}
static int
F_90 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_186 * V_187 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_326 * V_122 = & V_1 -> V_122 ;
struct V_331 * V_332 ;
struct V_186 * V_41 = (struct V_186 * ) V_99 ;
if ( V_41 -> V_189 != V_130 )
return - V_121 ;
V_332 = F_91 ( sizeof ( struct V_331 ) , V_277 ) ;
if ( V_332 == NULL )
return - V_278 ;
memcpy ( V_332 -> V_41 , V_41 -> V_190 , V_79 ) ;
if ( F_92 ( & V_122 -> V_327 ) ) {
F_9 ( V_332 ) ;
return - V_334 ;
}
F_93 ( & V_332 -> V_333 , & V_122 -> V_328 ) ;
V_122 -> V_39 ++ ;
F_10 ( & V_122 -> V_327 ) ;
return 0 ;
}
static int
F_94 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_186 * V_187 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_326 * V_122 = & V_1 -> V_122 ;
struct V_331 * V_332 ;
struct V_186 * V_41 = (struct V_186 * ) V_99 ;
if ( V_41 -> V_189 != V_130 )
return - V_121 ;
if ( F_92 ( & V_122 -> V_327 ) )
return - V_334 ;
F_95 (entry, &acl->mac_list, _list) {
if ( F_96 ( V_332 -> V_41 , V_41 -> V_190 ) ) {
F_88 ( & V_332 -> V_333 ) ;
V_122 -> V_39 -- ;
F_9 ( V_332 ) ;
F_10 ( & V_122 -> V_327 ) ;
return 0 ;
}
}
F_10 ( & V_122 -> V_327 ) ;
return - V_11 ;
}
static int
F_97 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_326 * V_122 = & V_1 -> V_122 ;
struct V_331 * V_332 ;
struct V_186 * V_335 = (struct V_186 * ) V_99 ;
V_139 -> V_144 = 0 ;
if ( F_92 ( & V_122 -> V_327 ) )
return - V_334 ;
F_95 (entry, &acl->mac_list, _list) {
memcpy ( V_335 -> V_190 , V_332 -> V_41 , V_79 ) ;
V_335 -> V_189 = V_130 ;
V_139 -> V_144 ++ ;
V_335 ++ ;
}
F_10 ( & V_122 -> V_327 ) ;
return 0 ;
}
static int
F_98 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_326 * V_122 = & V_1 -> V_122 ;
T_2 V_118 ;
F_86 ( V_122 ) ;
if ( ( * V_117 < V_124 ) || ( * V_117 > V_336 ) )
return - V_11 ;
F_24 ( & V_1 -> V_120 ) ;
V_122 -> V_123 = * V_117 ;
if ( ( V_1 -> V_2 == V_19 ) &&
( V_122 -> V_123 != V_124 ) )
V_118 = V_125 ;
else
V_118 = V_48 ;
if ( V_1 -> V_126 )
V_118 = V_127 ;
F_3 ( V_1 , V_57 , & V_118 ) ;
if ( F_26 ( V_1 ) ) {
F_25 ( & V_1 -> V_120 ) ;
return - V_128 ;
}
F_25 ( & V_1 -> V_120 ) ;
return 0 ;
}
static int
F_99 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_326 * V_122 = & V_1 -> V_122 ;
* V_117 = V_122 -> V_123 ;
return 0 ;
}
static int
F_100 ( struct V_326 * V_122 , char * V_337 )
{
struct V_331 * V_332 ;
int V_338 = 0 ;
if ( F_92 ( & V_122 -> V_327 ) )
return - V_334 ;
if ( V_122 -> V_123 == V_124 ) {
F_10 ( & V_122 -> V_327 ) ;
return 1 ;
}
F_95 (entry, &acl->mac_list, _list) {
if ( memcmp ( V_332 -> V_41 , V_337 , V_79 ) == 0 ) {
V_338 = 1 ;
break;
}
}
V_338 = ( V_122 -> V_123 == V_339 ) ? ! V_338 : V_338 ;
F_10 ( & V_122 -> V_327 ) ;
return V_338 ;
}
static int
F_101 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_139 , char * V_99 )
{
struct V_340 * V_34 ;
int V_102 ;
V_34 = F_91 ( sizeof ( struct V_340 ) , V_277 ) ;
if ( V_34 == NULL )
return - V_278 ;
V_34 -> V_279 = 0 ;
V_102 =
F_17 ( F_12 ( V_92 ) , V_341 , 0 , V_34 ) ;
F_9 ( V_34 ) ;
return V_102 ;
}
static int
F_102 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_186 * V_187 , char * V_99 )
{
struct V_340 * V_34 ;
struct V_186 * V_41 = (struct V_186 * ) V_99 ;
int V_102 ;
if ( V_41 -> V_189 != V_130 )
return - V_121 ;
V_34 = F_91 ( sizeof ( struct V_340 ) , V_277 ) ;
if ( V_34 == NULL )
return - V_278 ;
memcpy ( V_34 -> V_78 , V_41 -> V_190 , V_79 ) ;
V_34 -> V_279 = - 1 ;
V_102 =
F_17 ( F_12 ( V_92 ) , V_341 , 0 , V_34 ) ;
F_9 ( V_34 ) ;
return V_102 ;
}
static void
F_103 ( T_1 * V_1 , char * V_342 , const char * V_343 ,
const struct V_340 * V_34 , T_6 * V_144 , int error )
{
int V_321 = snprintf ( V_342 , V_344 ,
L_12 ,
V_343 ,
( ( V_1 -> V_2 == V_19 ) ? L_13 : L_14 ) ,
V_34 -> V_78 ,
( error ? ( V_34 -> V_87 ? L_15 : L_16 )
: L_8 ) , V_34 -> V_87 ) ;
F_104 ( V_321 >= V_344 ) ;
* V_144 = V_321 ;
}
static void
F_105 ( T_1 * V_1 , const char * V_343 ,
const struct V_340 * V_34 , int error )
{
union V_282 V_283 ;
char * V_345 ;
V_345 = F_91 ( V_344 , V_277 ) ;
if ( ! V_345 )
return;
V_283 . V_63 . V_346 = V_345 ;
V_283 . V_63 . V_144 = 0 ;
F_103 ( V_1 , V_345 , V_343 , V_34 , & V_283 . V_63 . V_144 ,
error ) ;
F_106 ( V_1 -> V_92 , V_171 , & V_283 , V_345 ) ;
F_9 ( V_345 ) ;
}
static void
F_107 ( T_1 * V_1 , const char * V_343 )
{
union V_282 V_283 ;
char * V_345 ;
int V_321 = strlen ( V_343 ) ;
V_345 = F_91 ( V_344 , V_277 ) ;
if ( ! V_345 )
return;
F_28 ( V_321 >= V_344 ) ;
V_283 . V_63 . V_346 = V_345 ;
V_283 . V_63 . V_144 = V_321 ;
strcpy ( V_345 , V_343 ) ;
F_106 ( V_1 -> V_92 , V_171 , & V_283 , V_345 ) ;
F_9 ( V_345 ) ;
}
static void
F_108 ( struct V_91 * V_92 , T_2 V_184 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
if ( V_184 ) {
F_109 ( V_92 ) ;
if ( V_1 -> V_2 == V_17 ) {
union V_282 V_117 ;
F_35 ( V_92 , NULL , (struct V_186 * ) & V_117 ,
NULL ) ;
F_106 ( V_92 , V_169 , & V_117 , NULL ) ;
} else
F_107 ( F_12 ( V_92 ) ,
L_17 ) ;
} else {
F_110 ( V_92 ) ;
F_107 ( F_12 ( V_92 ) , L_18 ) ;
}
}
static void
F_111 ( T_1 * V_1 , T_4 * V_188 ,
T_4 * V_197 , T_5 V_199 )
{
struct V_329 * V_77 ;
struct V_347 * V_66 = NULL ;
if ( V_199 > V_198 )
V_199 = V_198 ;
F_7 ( & V_1 -> V_348 ) ;
F_112 (ptr, &priv->bss_wpa_list) {
V_66 = F_87 ( V_77 , struct V_347 , V_349 ) ;
if ( memcmp ( V_66 -> V_188 , V_188 , V_79 ) == 0 ) {
F_113 ( & V_66 -> V_349 , & V_1 -> V_350 ) ;
break;
}
V_66 = NULL ;
}
if ( V_66 == NULL ) {
if ( V_1 -> V_351 >= V_352 ) {
V_66 = F_87 ( V_1 -> V_350 . V_353 ,
struct V_347 , V_349 ) ;
F_88 ( & V_66 -> V_349 ) ;
} else {
V_66 = F_67 ( sizeof ( * V_66 ) , V_354 ) ;
if ( V_66 != NULL )
V_1 -> V_351 ++ ;
}
if ( V_66 != NULL ) {
memcpy ( V_66 -> V_188 , V_188 , V_79 ) ;
F_114 ( & V_66 -> V_349 , & V_1 -> V_350 ) ;
}
}
if ( V_66 != NULL ) {
memcpy ( V_66 -> V_197 , V_197 , V_199 ) ;
V_66 -> V_199 = V_199 ;
V_66 -> V_355 = V_94 ;
} else {
F_2 ( V_9 L_19
L_20 , V_188 ) ;
}
while ( V_1 -> V_351 > 0 ) {
V_66 = F_87 ( V_1 -> V_350 . V_353 ,
struct V_347 , V_349 ) ;
if ( ! F_14 ( V_94 , V_66 -> V_355 + 60 * V_95 ) )
break;
F_88 ( & V_66 -> V_349 ) ;
V_1 -> V_351 -- ;
F_9 ( V_66 ) ;
}
F_10 ( & V_1 -> V_348 ) ;
}
static T_5
F_43 ( T_1 * V_1 , T_4 * V_188 , T_4 * V_197 )
{
struct V_329 * V_77 ;
struct V_347 * V_66 = NULL ;
T_5 V_281 = 0 ;
F_7 ( & V_1 -> V_348 ) ;
F_112 (ptr, &priv->bss_wpa_list) {
V_66 = F_87 ( V_77 , struct V_347 , V_349 ) ;
if ( memcmp ( V_66 -> V_188 , V_188 , V_79 ) == 0 )
break;
V_66 = NULL ;
}
if ( V_66 ) {
V_281 = V_66 -> V_199 ;
memcpy ( V_197 , V_66 -> V_197 , V_281 ) ;
}
F_10 ( & V_1 -> V_348 ) ;
return V_281 ;
}
void
F_115 ( T_1 * V_1 )
{
F_85 ( & V_1 -> V_350 ) ;
F_84 ( & V_1 -> V_348 ) ;
}
void
F_116 ( T_1 * V_1 )
{
struct V_347 * V_66 , * V_321 ;
F_117 (bss, n, &priv->bss_wpa_list, list) {
F_9 ( V_66 ) ;
}
}
static void
F_118 ( T_1 * V_1 , T_2 V_325 , T_4 * V_41 ,
T_4 * V_356 , T_5 V_281 )
{
struct V_357 * V_358 ;
T_4 * V_359 , * V_360 ;
if ( ! V_1 -> V_126 )
return;
V_358 = (struct V_357 * ) V_356 ;
V_359 = ( T_4 * ) ( V_358 + 1 ) ;
V_360 = V_356 + V_281 ;
while ( V_359 < V_360 ) {
if ( V_359 + 2 + V_359 [ 1 ] > V_360 ) {
F_2 ( V_9 L_21
L_22 , V_41 ) ;
return;
}
if ( V_359 [ 0 ] == V_361 && V_359 [ 1 ] >= 4 &&
memcmp ( V_359 + 2 , V_362 , 4 ) == 0 ) {
F_111 ( V_1 , V_41 , V_359 , V_359 [ 1 ] + 2 ) ;
return;
}
V_359 += 2 + V_359 [ 1 ] ;
}
}
static void
F_119 ( T_1 * V_1 , struct V_340 * V_34 , enum V_320 V_325 )
{
if ( ( ( V_34 -> V_363 == V_364 ) ||
( V_34 -> V_363 == V_365 ) )
&& F_120 ( V_1 ) ) {
V_34 -> V_87 = F_100 ( & V_1 -> V_122 ,
V_34 -> V_78 ) ? 0 : 1 ;
F_17 ( V_1 , V_325 , 0 , V_34 ) ;
}
}
static int
F_121 ( T_1 * V_1 , enum V_320 V_325 ,
char * V_63 )
{
struct V_340 * V_34 = (struct V_340 * ) V_63 ;
struct V_366 * V_367 = (struct V_366 * ) V_63 ;
struct V_366 * V_368 ;
T_4 V_197 [ V_198 ] ;
int V_199 ;
T_5 V_281 = 0 ;
T_4 * V_356 = NULL , * V_359 = NULL ;
int V_235 ;
if ( V_325 >= V_369 ) {
V_281 = V_367 -> V_39 ;
V_356 = V_359 = V_367 -> V_63 ;
}
if ( ( V_325 == V_369 ) || ( V_325 == V_370 ) )
F_118 ( V_1 , V_325 , V_367 -> V_78 ,
V_356 , V_281 ) ;
F_122 ( V_322 [ V_325 ] . V_204 & V_323 , ( void * ) V_34 ) ;
switch ( V_325 ) {
case V_239 :
F_108 ( V_1 -> V_92 , ( T_2 ) * V_63 ) ;
break;
case V_371 :
F_107 ( V_1 , L_23 ) ;
break;
case V_372 :
F_105 ( V_1 , L_24 , V_34 , 0 ) ;
break;
case V_373 :
F_119 ( V_1 , V_34 , V_325 ) ;
F_105 ( V_1 , L_25 , V_34 , 1 ) ;
break;
case V_341 :
F_105 ( V_1 , L_26 , V_34 , 0 ) ;
break;
case V_374 :
F_119 ( V_1 , V_34 , V_325 ) ;
F_105 ( V_1 , L_27 , V_34 , 1 ) ;
break;
case V_375 :
F_119 ( V_1 , V_34 , V_325 ) ;
F_105 ( V_1 , L_28 , V_34 , 1 ) ;
break;
case V_369 :
F_105 ( V_1 ,
L_29 ,
V_34 , 0 ) ;
break;
case V_370 :
F_105 ( V_1 , L_30 , V_34 ,
0 ) ;
break;
case V_376 :
F_105 ( V_1 , L_24 , V_34 , 0 ) ;
break;
case V_377 :
F_119 ( V_1 , V_34 , V_325 ) ;
F_105 ( V_1 , L_31 , V_34 , 1 ) ;
if ( V_1 -> V_2 != V_19
&& V_367 -> V_363 != V_364 )
break;
V_368 = F_91 ( sizeof( struct V_366 ) + 6 , V_354 ) ;
if ( ! V_368 )
break;
memcpy ( & V_368 -> V_78 , V_367 -> V_78 , V_79 ) ;
F_2 ( V_9 L_32 ,
V_367 -> V_78 ) ;
V_368 -> V_279 = - 1 ;
V_368 -> V_363 = 0 ;
V_368 -> V_87 = 0 ;
V_368 -> V_39 = 6 ;
V_368 -> V_63 [ 0 ] = 0x00 ;
V_368 -> V_63 [ 1 ] = 0x00 ;
V_368 -> V_63 [ 2 ] = 0x02 ;
V_368 -> V_63 [ 3 ] = 0x00 ;
V_368 -> V_63 [ 4 ] = 0x00 ;
V_368 -> V_63 [ 5 ] = 0x00 ;
V_235 = F_71 ( V_1 , V_378 , V_368 , 6 ) ;
F_9 ( V_368 ) ;
if ( V_235 )
return V_235 ;
break;
case V_379 :
F_105 ( V_1 , L_33 , V_34 , 0 ) ;
break;
case V_378 :
F_119 ( V_1 , V_34 , V_325 ) ;
F_105 ( V_1 , L_34 , V_34 , 1 ) ;
if ( V_1 -> V_2 != V_19
&& V_367 -> V_363 != V_365 )
break;
V_368 = F_91 ( sizeof( struct V_366 ) , V_354 ) ;
if ( ! V_368 )
break;
memcpy ( & V_368 -> V_78 , V_367 -> V_78 , V_79 ) ;
V_368 -> V_279 = ( (struct V_366 * ) V_34 ) -> V_279 ;
V_368 -> V_363 = 0 ;
V_368 -> V_87 = 0 ;
V_199 = F_43 ( V_1 , V_367 -> V_78 , V_197 ) ;
if ( ! V_199 ) {
F_2 ( V_9 L_35 ,
V_367 -> V_78 ) ;
F_9 ( V_368 ) ;
break;
}
V_368 -> V_39 = V_199 ;
memcpy ( & V_368 -> V_63 , V_197 , V_199 ) ;
F_71 ( V_1 , V_325 , V_368 , V_199 ) ;
F_9 ( V_368 ) ;
break;
case V_380 :
F_119 ( V_1 , V_34 , V_325 ) ;
F_105 ( V_1 , L_36 , V_34 , 1 ) ;
if ( V_1 -> V_2 != V_19
&& V_367 -> V_363 != V_365 )
break;
V_368 = F_91 ( sizeof( struct V_366 ) , V_354 ) ;
if ( ! V_368 )
break;
memcpy ( & V_368 -> V_78 , V_367 -> V_78 , V_79 ) ;
V_368 -> V_279 = V_367 -> V_279 ;
V_368 -> V_363 = 0 ;
V_368 -> V_87 = 0 ;
V_199 = F_43 ( V_1 , V_367 -> V_78 , V_197 ) ;
if ( ! V_199 ) {
F_2 ( V_9 L_35 ,
V_367 -> V_78 ) ;
F_9 ( V_368 ) ;
break;
}
V_368 -> V_39 = V_199 ;
memcpy ( & V_368 -> V_63 , V_197 , V_199 ) ;
F_71 ( V_1 , V_325 , V_368 , V_199 ) ;
F_9 ( V_368 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
void
F_123 ( struct V_60 * V_61 )
{
struct V_381 * V_382 =
F_6 ( V_61 , struct V_381 , V_383 ) ;
struct V_91 * V_92 = V_382 -> V_92 ;
enum V_320 V_321 = F_124 ( V_382 -> V_384 -> V_325 ) ;
if ( V_321 != V_385 )
F_121 ( F_12 ( V_92 ) , V_321 , V_382 -> V_63 ) ;
F_125 ( V_382 ) ;
}
int
F_126 ( struct V_91 * V_92 , void * V_41 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
int V_235 ;
if ( V_92 -> V_386 != 6 )
return - V_11 ;
V_235 = F_17 ( V_1 , V_387 , 0 ,
& ( (struct V_186 * ) V_41 ) -> V_190 ) ;
if ( ! V_235 )
memcpy ( V_1 -> V_92 -> V_388 ,
& ( (struct V_186 * ) V_41 ) -> V_190 , V_79 ) ;
return V_235 ;
}
static int
F_127 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
T_2 V_34 , V_30 , V_33 , V_32 , V_31 ;
if ( F_19 ( V_1 ) < V_103 )
return 0 ;
V_31 = 1 ;
V_32 = 1 ;
V_33 = 0x01 ;
V_34 = V_127 ;
V_30 = V_252 ;
F_24 ( & V_1 -> V_120 ) ;
V_1 -> V_126 = * V_117 ;
switch ( V_1 -> V_126 ) {
default:
case 0 :
V_31 = 0 ;
V_32 = 0 ;
V_33 = 0 ;
V_34 = V_294 ;
F_2 ( L_37 , V_92 -> V_119 ) ;
break;
case 2 :
case 1 :
F_2 ( L_38 , V_92 -> V_119 ) ;
break;
}
F_25 ( & V_1 -> V_120 ) ;
F_17 ( V_1 , V_52 , 0 , & V_30 ) ;
F_17 ( V_1 , V_53 , 0 , & V_31 ) ;
F_17 ( V_1 , V_55 , 0 , & V_32 ) ;
F_17 ( V_1 , V_56 , 0 , & V_33 ) ;
F_17 ( V_1 , V_57 , 0 , & V_34 ) ;
return 0 ;
}
static int
F_128 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
* V_117 = V_1 -> V_126 ;
return 0 ;
}
static int
F_129 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
V_1 -> V_129 =
( * V_117 ? V_389 : V_390 ) ;
if ( V_1 -> V_2 == V_21 )
V_1 -> V_92 -> type = V_1 -> V_129 ;
return 0 ;
}
static int
F_130 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
* V_117 = ( V_1 -> V_129 == V_389 ) ;
return 0 ;
}
static int
F_131 ( struct V_91 * V_92 , struct V_96 * V_97 ,
T_3 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
V_1 -> V_391 = * V_117 ;
F_2 ( L_39 , V_92 -> V_119 , * V_117 ) ;
return 0 ;
}
static int
F_132 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_63 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_381 * V_392 ;
int V_235 = - V_128 ;
F_2 ( L_40 , V_92 -> V_119 , V_1 -> V_391 ) ;
V_63 -> V_144 = 0 ;
if ( F_19 ( V_1 ) >= V_103 ) {
V_235 =
F_133 ( V_1 -> V_92 , V_393 ,
V_1 -> V_391 , V_99 , 256 ,
& V_392 ) ;
F_2 ( L_41 , V_92 -> V_119 , V_235 ) ;
if ( V_235 || ! V_392
|| V_392 -> V_384 -> V_394 == V_395 ) {
if ( V_392 ) {
F_125 ( V_392 ) ;
}
F_2 ( L_42 , V_92 -> V_119 ) ;
V_235 = - V_128 ;
}
if ( ! V_235 ) {
V_63 -> V_144 = V_392 -> V_384 -> V_144 ;
memcpy ( V_99 , V_392 -> V_63 , V_63 -> V_144 ) ;
F_125 ( V_392 ) ;
F_2 ( L_43 , V_92 -> V_119 , V_63 -> V_144 ) ;
}
}
return V_235 ;
}
static int
F_134 ( struct V_91 * V_92 , struct V_96 * V_97 ,
struct V_138 * V_63 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
struct V_381 * V_392 ;
int V_235 = 0 , V_396 = V_395 ;
F_2 ( L_44 , V_92 -> V_119 , V_1 -> V_391 ,
V_63 -> V_144 ) ;
if ( F_19 ( V_1 ) >= V_103 ) {
V_235 =
F_133 ( V_1 -> V_92 , V_397 ,
V_1 -> V_391 , V_99 , V_63 -> V_144 ,
& V_392 ) ;
F_2 ( L_41 , V_92 -> V_119 , V_235 ) ;
if ( V_235 || ! V_392
|| V_392 -> V_384 -> V_394 == V_395 ) {
if ( V_392 ) {
F_125 ( V_392 ) ;
}
F_2 ( L_42 , V_92 -> V_119 ) ;
V_235 = - V_128 ;
}
if ( ! V_235 ) {
V_396 = V_392 -> V_384 -> V_394 ;
F_2 ( L_45 , V_92 -> V_119 ,
V_396 ) ;
F_125 ( V_392 ) ;
}
}
return ( V_235 ? V_235 : - V_114 ) ;
}
static int
F_135 ( struct V_91 * V_92 ,
struct V_96 * V_97 ,
union V_282 * V_117 , char * V_99 )
{
T_1 * V_1 = F_12 ( V_92 ) ;
T_2 V_75 ;
enum V_320 V_325 = V_27 ;
F_24 ( & V_1 -> V_120 ) ;
F_136 ( V_1 , V_27 , & V_75 ) ;
if ( ( V_117 -> V_63 . V_144 == 0 ) && ( V_1 -> V_398 . V_399 > 0 ) )
V_75 &= ~ V_23 ;
else if ( ( V_117 -> V_63 . V_144 > 0 ) && ( V_1 -> V_398 . V_399 == 0 ) )
V_75 |= V_23 ;
F_3 ( V_1 , V_27 , & V_75 ) ;
F_137 ( V_1 , & V_325 , 1 ) ;
F_25 ( & V_1 -> V_120 ) ;
return F_138 ( V_92 , V_97 , V_117 , V_99 ) ;
}
