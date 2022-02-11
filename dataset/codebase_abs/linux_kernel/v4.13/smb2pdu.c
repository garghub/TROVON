static int F_1 ( const struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_3 -> V_4 & V_5 ) ||
( V_2 -> V_6 & V_7 ) )
return 1 ;
if ( V_2 -> V_8 &&
( V_2 -> V_3 -> V_9 -> V_10 & V_11 ) )
return 1 ;
return 0 ;
}
static void
F_2 ( struct V_12 * V_13 , T_1 V_14 ,
const struct V_1 * V_2 )
{
V_13 -> V_15 = V_16 ;
V_13 -> V_17 = F_3 ( 64 ) ;
V_13 -> V_18 = V_14 ;
if ( V_2 && V_2 -> V_3 && V_2 -> V_3 -> V_9 ) {
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
F_4 ( & V_9 -> V_20 ) ;
if ( V_9 -> V_21 >= V_9 -> V_22 )
V_13 -> V_23 = F_3 ( 0 ) ;
else
V_13 -> V_23 = F_3 (
F_5 ( int , V_9 -> V_22 -
V_9 -> V_21 , 2 ) ) ;
F_6 ( & V_9 -> V_20 ) ;
} else {
V_13 -> V_23 = F_3 ( 2 ) ;
}
V_13 -> V_24 = F_7 ( ( V_25 ) V_26 -> V_27 ) ;
if ( ! V_2 )
goto V_28;
if ( ( V_2 -> V_3 ) && ( V_2 -> V_3 -> V_9 ) &&
( V_2 -> V_3 -> V_9 -> V_10 & V_29 ) )
V_13 -> V_30 = F_3 ( 1 ) ;
V_13 -> V_31 = V_2 -> V_32 ;
if ( V_2 -> V_3 )
V_13 -> V_33 = V_2 -> V_3 -> V_34 ;
if ( V_2 -> V_3 && V_2 -> V_3 -> V_9 && V_2 -> V_3 -> V_9 -> V_35 &&
! F_1 ( V_2 ) )
V_13 -> V_36 |= V_37 ;
V_28:
return;
}
static int
F_8 ( T_1 V_38 , struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_40 * V_41 ;
struct V_42 * V_3 ;
struct V_19 * V_9 ;
if ( V_2 == NULL )
return V_39 ;
if ( V_38 == V_43 )
return V_39 ;
if ( V_2 -> V_44 == V_45 ) {
if ( ( V_38 != V_46 ) &&
( V_38 != V_47 ) &&
( V_38 != V_48 ) ) {
F_9 ( V_49 , L_1 ,
V_38 ) ;
return - V_50 ;
}
}
if ( ( ! V_2 -> V_3 ) || ( V_2 -> V_3 -> V_51 == V_45 ) ||
( ! V_2 -> V_3 -> V_9 ) )
return - V_52 ;
V_3 = V_2 -> V_3 ;
V_9 = V_3 -> V_9 ;
while ( V_9 -> V_53 == V_54 ) {
switch ( V_38 ) {
case V_48 :
case V_55 :
case V_56 :
case V_57 :
return - V_58 ;
}
F_10 ( V_9 -> V_59 ,
( V_9 -> V_53 != V_54 ) , 10 * V_60 ) ;
if ( V_9 -> V_53 != V_54 )
break;
if ( ! V_2 -> V_61 ) {
F_9 ( V_49 , L_2 ) ;
return - V_62 ;
}
}
if ( ! V_2 -> V_3 -> V_63 && ! V_2 -> V_63 )
return V_39 ;
V_41 = F_11 () ;
F_12 ( & V_2 -> V_3 -> V_64 ) ;
V_39 = F_13 ( 0 , V_2 -> V_3 ) ;
if ( ! V_39 && V_2 -> V_3 -> V_63 )
V_39 = F_14 ( 0 , V_2 -> V_3 , V_41 ) ;
if ( V_39 || ! V_2 -> V_63 ) {
F_15 ( & V_2 -> V_3 -> V_64 ) ;
goto V_28;
}
F_16 ( V_2 ) ;
if ( V_2 -> V_65 )
V_2 -> V_66 = true ;
V_39 = F_17 ( 0 , V_2 -> V_3 , V_2 -> V_67 , V_2 , V_41 ) ;
F_15 ( & V_2 -> V_3 -> V_64 ) ;
F_9 ( V_49 , L_3 , V_39 ) ;
if ( V_39 )
goto V_28;
if ( V_38 != V_68 )
F_18 ( V_69 , & V_9 -> V_70 , 0 ) ;
F_19 ( & V_71 ) ;
V_28:
switch ( V_38 ) {
case V_72 :
case V_73 :
case V_46 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_39 = - V_58 ;
}
F_20 ( V_41 ) ;
return V_39 ;
}
static void
F_21 ( T_1 V_38 , struct V_1 * V_2 , void * V_80 ,
unsigned int * V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_80 ;
V_25 V_84 = V_85 [ F_22 ( V_38 ) ] ;
memset ( V_80 , 0 , 256 ) ;
F_2 ( & V_83 -> V_86 , V_38 , V_2 ) ;
V_83 -> V_87 = F_3 ( V_84 ) ;
* V_81 = V_84 + sizeof( struct V_12 ) ;
}
static int
F_23 ( T_1 V_38 , struct V_1 * V_2 ,
void * * V_88 , unsigned int * V_81 )
{
int V_39 ;
struct V_12 * V_13 ;
V_39 = F_8 ( V_38 , V_2 ) ;
if ( V_39 )
return V_39 ;
* V_88 = F_24 () ;
if ( * V_88 == NULL ) {
return - V_89 ;
}
V_13 = (struct V_12 * ) ( * V_88 ) ;
F_21 ( V_38 , V_2 , V_13 , V_81 ) ;
if ( V_2 != NULL ) {
#ifdef F_25
T_2 V_90 = F_22 ( V_38 ) ;
F_26 ( & V_2 -> V_91 . V_92 . V_93 [ V_90 ] ) ;
#endif
F_26 ( & V_2 -> V_94 ) ;
}
return V_39 ;
}
static int
F_27 ( T_1 V_38 , struct V_1 * V_2 ,
void * * V_88 )
{
int V_39 ;
unsigned int V_81 ;
struct V_95 * V_96 ;
V_39 = F_8 ( V_38 , V_2 ) ;
if ( V_39 )
return V_39 ;
* V_88 = F_24 () ;
if ( * V_88 == NULL ) {
return - V_89 ;
}
V_96 = (struct V_95 * ) ( * V_88 ) ;
F_21 ( V_38 , V_2 , F_28 ( V_96 ) , & V_81 ) ;
V_96 -> V_97 . V_98 = F_29 ( V_81 ) ;
if ( V_2 != NULL ) {
#ifdef F_25
T_2 V_90 = F_22 ( V_38 ) ;
F_26 ( & V_2 -> V_91 . V_92 . V_93 [ V_90 ] ) ;
#endif
F_26 ( & V_2 -> V_94 ) ;
}
return V_39 ;
}
static void
F_30 ( struct V_99 * V_100 )
{
V_100 -> V_101 = V_102 ;
V_100 -> V_103 = F_3 ( 38 ) ;
V_100 -> V_104 = F_3 ( 1 ) ;
V_100 -> V_105 = F_3 ( V_106 ) ;
F_31 ( V_100 -> V_107 , V_106 ) ;
V_100 -> V_108 = V_109 ;
}
static void
F_32 ( struct V_110 * V_100 )
{
V_100 -> V_101 = V_111 ;
V_100 -> V_103 = F_3 ( 6 ) ;
V_100 -> V_112 = F_3 ( 2 ) ;
V_100 -> V_113 [ 0 ] = V_114 ;
V_100 -> V_113 [ 1 ] = V_115 ;
}
static void
F_33 ( struct V_116 * V_117 )
{
char * V_100 = ( char * ) V_117 + V_118 + 4 ;
F_30 ( (struct V_99 * ) V_100 ) ;
V_100 += 2 + sizeof( struct V_99 ) ;
F_32 ( (struct V_110 * ) V_100 ) ;
V_117 -> V_119 = F_7 ( V_118 ) ;
V_117 -> V_120 = F_3 ( 2 ) ;
F_34 ( V_117 , 4 + sizeof( struct V_99 ) + 2
+ sizeof( struct V_110 ) ) ;
}
static void F_33 ( struct V_116 * V_117 )
{
return;
}
int
F_35 ( const unsigned int V_121 , struct V_42 * V_3 )
{
struct V_116 * V_117 ;
struct V_122 * V_123 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_19 * V_9 = V_3 -> V_9 ;
int V_128 , V_129 ;
char * V_130 ;
int V_131 = V_132 ;
F_9 ( V_49 , L_4 ) ;
if ( ! V_9 ) {
F_36 ( 1 , L_5 , V_133 ) ;
return - V_52 ;
}
V_39 = F_27 ( V_134 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = 0 ;
V_117 -> V_135 [ 0 ] = F_3 ( V_3 -> V_9 -> V_136 -> V_137 ) ;
V_117 -> V_138 = F_3 ( 1 ) ;
F_34 ( V_117 , 2 ) ;
if ( V_3 -> V_35 )
V_117 -> V_139 = F_3 ( V_140 ) ;
else if ( V_141 & V_142 )
V_117 -> V_139 = F_3 ( V_143 ) ;
else
V_117 -> V_139 = 0 ;
V_117 -> V_144 = F_7 ( V_3 -> V_9 -> V_136 -> V_145 ) ;
if ( V_3 -> V_9 -> V_136 -> V_137 == V_146 )
memset ( V_117 -> V_147 , 0 , V_148 ) ;
else {
memcpy ( V_117 -> V_147 , V_9 -> V_149 ,
V_148 ) ;
if ( V_3 -> V_9 -> V_136 -> V_137 == V_150 )
F_33 ( V_117 ) ;
}
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_122 * ) V_126 . V_151 ;
if ( V_39 == - V_153 ) {
F_9 ( V_154 , L_6
L_7
L_8 ) ;
goto V_155;
} else if ( V_39 != 0 )
goto V_155;
F_9 ( V_49 , L_9 , V_123 -> V_139 ) ;
if ( V_123 -> V_156 == F_3 ( V_146 ) )
F_9 ( V_49 , L_10 ) ;
else if ( V_123 -> V_156 == F_3 ( V_157 ) )
F_9 ( V_49 , L_11 ) ;
else if ( V_123 -> V_156 == F_3 ( V_158 ) )
F_9 ( V_49 , L_12 ) ;
else if ( V_123 -> V_156 == F_3 ( V_159 ) )
F_9 ( V_49 , L_13 ) ;
#ifdef F_40
else if ( V_123 -> V_156 == F_3 ( V_150 ) )
F_9 ( V_49 , L_14 ) ;
#endif
else {
F_9 ( V_154 , L_15 ,
F_22 ( V_123 -> V_156 ) ) ;
V_39 = - V_52 ;
goto V_155;
}
V_9 -> V_160 = F_22 ( V_123 -> V_156 ) ;
V_9 -> V_161 = V_162 ;
V_9 -> V_163 = F_5 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_9 -> V_164 = F_41 ( V_123 -> V_165 ) ;
V_9 -> V_166 = F_41 ( V_123 -> V_167 ) ;
V_9 -> V_168 = F_22 ( V_123 -> V_139 ) ;
V_9 -> V_10 = F_41 ( V_123 -> V_144 ) ;
V_9 -> V_10 |= V_169 | V_170 ;
V_130 = F_42 ( & V_128 , & V_129 ,
& V_123 -> V_97 ) ;
if ( V_129 == 0 ) {
F_9 ( V_49 , L_16 ) ;
V_9 -> V_171 = true ;
}
V_39 = F_43 ( V_9 , V_3 -> V_35 ) ;
if ( V_39 )
goto V_155;
if ( V_129 ) {
V_39 = F_44 ( V_130 , V_129 , V_9 ) ;
if ( V_39 == 1 )
V_39 = 0 ;
else if ( V_39 == 0 )
V_39 = - V_52 ;
}
V_155:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int F_46 ( const unsigned int V_121 , struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_172 V_173 ;
struct V_174 * V_175 ;
T_3 V_176 ;
F_9 ( V_49 , L_17 ) ;
if ( V_2 -> V_3 -> V_9 -> V_35 == false )
return 0 ;
V_173 . V_144 =
F_7 ( V_2 -> V_3 -> V_9 -> V_136 -> V_145 ) ;
memcpy ( V_173 . V_177 , V_2 -> V_3 -> V_9 -> V_149 ,
V_148 ) ;
if ( V_2 -> V_3 -> V_35 )
V_173 . V_139 =
F_3 ( V_140 ) ;
else if ( V_141 & V_142 )
V_173 . V_139 =
F_3 ( V_143 ) ;
else
V_173 . V_139 = 0 ;
V_173 . V_138 = F_3 ( 1 ) ;
V_173 . V_135 [ 0 ] =
F_3 ( V_2 -> V_3 -> V_9 -> V_136 -> V_137 ) ;
V_39 = F_47 ( V_121 , V_2 , V_178 , V_178 ,
V_179 , true ,
false ,
( char * ) & V_173 , sizeof( struct V_172 ) ,
( char * * ) & V_175 , & V_176 ) ;
if ( V_39 != 0 ) {
F_9 ( V_154 , L_18 , V_39 ) ;
return - V_52 ;
}
if ( V_176 != sizeof( struct V_174 ) ) {
F_9 ( V_154 , L_19 ,
V_176 ) ;
if ( V_176 > V_180 )
return - V_52 ;
}
if ( V_175 -> V_181 !=
F_3 ( V_2 -> V_3 -> V_9 -> V_136 -> V_137 ) )
goto V_182;
if ( V_175 -> V_139 != F_3 ( V_2 -> V_3 -> V_9 -> V_168 ) )
goto V_182;
if ( ( F_41 ( V_175 -> V_144 ) | V_169 |
V_170 ) != V_2 -> V_3 -> V_9 -> V_10 )
goto V_182;
F_9 ( V_49 , L_20 ) ;
return 0 ;
V_182:
F_9 ( V_154 , L_21 ) ;
return - V_52 ;
}
enum V_183
F_48 ( struct V_19 * V_9 , enum V_183 V_184 )
{
switch ( V_184 ) {
case V_185 :
case V_186 :
return V_184 ;
case V_187 :
return V_186 ;
case V_188 :
if ( V_9 -> V_171 &&
( V_141 & V_189 ) )
return V_186 ;
if ( ( V_9 -> V_190 || V_9 -> V_191 ) &&
( V_141 & V_192 ) )
return V_185 ;
default:
return V_188 ;
}
}
static int
F_49 ( struct V_193 * V_194 )
{
int V_39 ;
struct V_42 * V_3 = V_194 -> V_3 ;
struct V_195 * V_117 ;
struct V_19 * V_9 = V_3 -> V_9 ;
V_39 = F_27 ( V_196 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = 0 ;
V_117 -> V_197 = V_194 -> V_198 ;
V_117 -> V_36 = 0 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 3 ) ;
if ( V_9 -> V_35 )
V_117 -> V_139 = V_140 ;
else if ( V_141 & V_142 )
V_117 -> V_139 = V_143 ;
else
V_117 -> V_139 = 0 ;
V_117 -> V_144 = 0 ;
V_117 -> V_199 = 0 ;
V_194 -> V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_194 -> V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
V_194 -> V_200 = V_201 ;
return 0 ;
}
static void
F_50 ( struct V_193 * V_194 )
{
F_45 ( V_194 -> V_200 , V_194 -> V_125 [ 0 ] . V_151 ) ;
V_194 -> V_200 = V_202 ;
}
static int
F_51 ( struct V_193 * V_194 )
{
int V_39 ;
struct V_195 * V_117 = V_194 -> V_125 [ 0 ] . V_151 ;
struct V_124 V_126 = { NULL , 0 } ;
V_117 -> V_203 =
F_3 ( sizeof( struct V_195 ) -
1 - 4 ) ;
V_117 -> V_204 = F_3 ( V_194 -> V_125 [ 1 ] . V_152 ) ;
F_34 ( V_117 , V_194 -> V_125 [ 1 ] . V_152 - 1 ) ;
V_39 = F_38 ( V_194 -> V_121 , V_194 -> V_3 ,
V_194 -> V_125 , 2 ,
& V_194 -> V_200 ,
V_205 | V_132 , & V_126 ) ;
F_39 ( V_194 -> V_125 [ 0 ] . V_151 ) ;
memcpy ( & V_194 -> V_125 [ 0 ] , & V_126 , sizeof( struct V_124 ) ) ;
return V_39 ;
}
static int
F_52 ( struct V_193 * V_194 )
{
int V_39 = 0 ;
struct V_42 * V_3 = V_194 -> V_3 ;
F_12 ( & V_3 -> V_9 -> V_206 ) ;
if ( V_3 -> V_9 -> V_207 -> V_208 ) {
V_39 = V_3 -> V_9 -> V_207 -> V_208 ( V_3 ) ;
if ( V_39 ) {
F_9 ( V_49 ,
L_22 ) ;
F_15 ( & V_3 -> V_9 -> V_206 ) ;
return V_39 ;
}
}
if ( ! V_3 -> V_9 -> V_209 ) {
V_3 -> V_9 -> V_210 = 0x2 ;
V_3 -> V_9 -> V_209 = true ;
}
F_15 ( & V_3 -> V_9 -> V_206 ) ;
F_9 ( V_49 , L_23 ) ;
F_4 ( & V_211 ) ;
V_3 -> V_51 = V_212 ;
V_3 -> V_63 = false ;
F_6 ( & V_211 ) ;
return V_39 ;
}
static void
F_53 ( struct V_193 * V_194 )
{
int V_39 ;
struct V_42 * V_3 = V_194 -> V_3 ;
struct V_213 * V_214 ;
struct V_215 * V_216 = NULL ;
struct V_217 * V_123 = NULL ;
V_39 = F_49 ( V_194 ) ;
if ( V_39 )
goto V_28;
V_216 = F_54 ( V_3 ) ;
if ( F_55 ( V_216 ) ) {
V_39 = F_56 ( V_216 ) ;
V_216 = NULL ;
goto V_28;
}
V_214 = V_216 -> V_218 . V_219 [ 0 ] ;
if ( V_214 -> V_220 != V_221 ) {
F_9 ( V_154 ,
L_24 ,
V_221 , V_214 -> V_220 ) ;
V_39 = - V_222 ;
goto V_223;
}
V_3 -> V_224 . V_225 = F_57 ( V_214 -> V_219 , V_214 -> V_226 ,
V_227 ) ;
if ( ! V_3 -> V_224 . V_225 ) {
F_9 ( V_154 ,
L_25 ,
V_214 -> V_226 ) ;
V_39 = - V_89 ;
goto V_223;
}
V_3 -> V_224 . V_228 = V_214 -> V_226 ;
V_194 -> V_125 [ 1 ] . V_151 = V_214 -> V_219 + V_214 -> V_226 ;
V_194 -> V_125 [ 1 ] . V_152 = V_214 -> V_229 ;
V_39 = F_51 ( V_194 ) ;
if ( V_39 )
goto V_223;
V_123 = (struct V_217 * ) V_194 -> V_125 [ 0 ] . V_151 ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_230 ) ;
V_39 = F_52 ( V_194 ) ;
V_223:
F_58 ( V_216 ) ;
F_59 ( V_216 ) ;
V_28:
V_194 -> V_231 = V_39 ;
V_194 -> V_232 = NULL ;
F_50 ( V_194 ) ;
}
static void
F_53 ( struct V_193 * V_194 )
{
F_9 ( V_154 , L_26 ) ;
V_194 -> V_231 = - V_153 ;
V_194 -> V_232 = NULL ;
}
static void
F_60 ( struct V_193 * V_194 )
{
int V_39 ;
struct V_42 * V_3 = V_194 -> V_3 ;
struct V_217 * V_123 = NULL ;
char * V_233 = NULL ;
bool V_234 = false ;
T_4 V_129 = 0 ;
V_3 -> V_235 = F_61 ( sizeof( struct V_236 ) , V_227 ) ;
if ( ! V_3 -> V_235 ) {
V_39 = - V_89 ;
goto V_237;
}
V_3 -> V_235 -> V_238 = true ;
V_39 = F_49 ( V_194 ) ;
if ( V_39 )
goto V_237;
V_233 = F_61 ( sizeof( struct V_239 ) ,
V_227 ) ;
if ( V_233 == NULL ) {
V_39 = - V_89 ;
goto V_28;
}
F_62 ( V_233 , V_3 ) ;
if ( V_234 ) {
F_9 ( V_154 , L_27 ) ;
V_39 = - V_153 ;
goto V_28;
} else {
V_129 = sizeof( struct V_239 ) ;
}
V_194 -> V_125 [ 1 ] . V_151 = V_233 ;
V_194 -> V_125 [ 1 ] . V_152 = V_129 ;
V_39 = F_51 ( V_194 ) ;
V_123 = (struct V_217 * ) V_194 -> V_125 [ 0 ] . V_151 ;
if ( V_194 -> V_200 != V_202 &&
V_123 -> V_97 . V_86 . V_240 == V_241 )
V_39 = 0 ;
if ( V_39 )
goto V_28;
if ( F_63 ( struct V_217 , V_242 ) - 4 !=
F_22 ( V_123 -> V_203 ) ) {
F_9 ( V_154 , L_28 ,
F_22 ( V_123 -> V_203 ) ) ;
V_39 = - V_52 ;
goto V_28;
}
V_39 = F_64 ( V_123 -> V_242 ,
F_22 ( V_123 -> V_204 ) , V_3 ) ;
if ( V_39 )
goto V_28;
F_9 ( V_49 , L_29 ) ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_230 ) ;
V_28:
F_65 ( V_233 ) ;
F_50 ( V_194 ) ;
if ( ! V_39 ) {
V_194 -> V_231 = 0 ;
V_194 -> V_232 = V_243 ;
return;
}
V_237:
F_65 ( V_3 -> V_235 ) ;
V_3 -> V_235 = NULL ;
V_194 -> V_231 = V_39 ;
V_194 -> V_232 = NULL ;
}
static void
V_243 ( struct V_193 * V_194 )
{
int V_39 ;
struct V_42 * V_3 = V_194 -> V_3 ;
struct V_195 * V_117 ;
struct V_217 * V_123 = NULL ;
unsigned char * V_233 = NULL ;
bool V_234 = false ;
T_4 V_129 = 0 ;
V_39 = F_49 ( V_194 ) ;
if ( V_39 )
goto V_28;
V_117 = (struct V_195 * ) V_194 -> V_125 [ 0 ] . V_151 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
V_39 = F_66 ( & V_233 , & V_129 , V_3 ,
V_194 -> V_244 ) ;
if ( V_39 ) {
F_9 ( V_49 , L_30 , V_39 ) ;
goto V_28;
}
if ( V_234 ) {
F_9 ( V_154 , L_27 ) ;
V_39 = - V_153 ;
goto V_28;
}
V_194 -> V_125 [ 1 ] . V_151 = V_233 ;
V_194 -> V_125 [ 1 ] . V_152 = V_129 ;
V_39 = F_51 ( V_194 ) ;
if ( V_39 )
goto V_28;
V_123 = (struct V_217 * ) V_194 -> V_125 [ 0 ] . V_151 ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_230 ) ;
V_39 = F_52 ( V_194 ) ;
V_28:
F_65 ( V_233 ) ;
F_50 ( V_194 ) ;
F_65 ( V_3 -> V_235 ) ;
V_3 -> V_235 = NULL ;
V_194 -> V_231 = V_39 ;
V_194 -> V_232 = NULL ;
}
static int
F_67 ( struct V_42 * V_3 , struct V_193 * V_194 )
{
int type ;
type = F_48 ( V_3 -> V_9 , V_3 -> V_245 ) ;
F_9 ( V_49 , L_31 , type ) ;
if ( type == V_188 ) {
F_9 ( V_154 ,
L_32 ) ;
return - V_246 ;
}
switch ( type ) {
case V_185 :
V_194 -> V_232 = F_53 ;
break;
case V_186 :
V_194 -> V_232 = F_60 ;
break;
default:
F_9 ( V_154 , L_33 , type ) ;
return - V_153 ;
}
return 0 ;
}
int
F_68 ( const unsigned int V_121 , struct V_42 * V_3 ,
const struct V_40 * V_244 )
{
int V_39 = 0 ;
struct V_19 * V_9 = V_3 -> V_9 ;
struct V_193 * V_194 ;
F_9 ( V_49 , L_34 ) ;
if ( ! V_9 ) {
F_36 ( 1 , L_5 , V_133 ) ;
return - V_52 ;
}
V_194 = F_69 ( sizeof( struct V_193 ) , V_227 ) ;
if ( ! V_194 )
return - V_89 ;
V_39 = F_67 ( V_3 , V_194 ) ;
if ( V_39 )
goto V_28;
V_194 -> V_121 = V_121 ;
V_194 -> V_3 = V_3 ;
V_194 -> V_200 = V_202 ;
V_194 -> V_244 = (struct V_40 * ) V_244 ;
while ( V_194 -> V_232 )
V_194 -> V_232 ( V_194 ) ;
V_39 = V_194 -> V_231 ;
V_28:
F_65 ( V_194 ) ;
return V_39 ;
}
int
F_70 ( const unsigned int V_121 , struct V_42 * V_3 )
{
struct V_247 * V_117 ;
int V_39 = 0 ;
struct V_19 * V_9 ;
int V_131 = 0 ;
F_9 ( V_49 , L_35 , V_3 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
if ( V_3 -> V_63 )
goto V_248;
V_39 = F_27 ( V_249 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
if ( V_3 -> V_4 & V_5 )
V_131 |= V_250 ;
else if ( V_9 -> V_35 )
V_117 -> V_97 . V_86 . V_36 |= V_37 ;
V_39 = F_71 ( V_121 , V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
V_248:
return V_39 ;
}
static inline void F_72 ( struct V_1 * V_2 , T_2 V_251 )
{
F_26 ( & V_2 -> V_91 . V_92 . V_252 [ V_251 ] ) ;
}
static inline void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_253 = 256 ;
V_2 -> V_254 = 1048576 ;
V_2 -> V_255 = 16777216 ;
}
int
F_17 ( const unsigned int V_121 , struct V_42 * V_3 , const char * V_256 ,
struct V_1 * V_2 , const struct V_40 * V_257 )
{
struct V_258 * V_117 ;
struct V_259 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
int V_260 ;
T_1 * V_261 = NULL ;
int V_131 = 0 ;
F_9 ( V_49 , L_36 ) ;
if ( ! ( V_3 -> V_9 ) || ! V_256 )
return - V_52 ;
V_261 = F_61 ( V_262 * 2 , V_227 ) ;
if ( V_261 == NULL )
return - V_89 ;
V_260 = F_74 ( V_261 , V_256 , strlen ( V_256 ) , V_257 ) + 1 ;
V_260 *= 2 ;
if ( V_260 < 2 ) {
F_65 ( V_261 ) ;
return - V_246 ;
}
if ( V_2 )
V_2 -> V_32 = 0 ;
V_39 = F_27 ( V_43 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
F_65 ( V_261 ) ;
return V_39 ;
}
if ( V_2 == NULL ) {
if ( ( V_3 -> V_4 & V_5 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
if ( V_3 -> V_9 -> V_35 )
V_117 -> V_97 . V_86 . V_36 |= V_37 ;
} else if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
V_117 -> V_263 = F_3 ( sizeof( struct V_258 )
- 1 - 4 ) ;
V_117 -> V_264 = F_3 ( V_260 - 2 ) ;
V_125 [ 1 ] . V_151 = V_261 ;
V_125 [ 1 ] . V_152 = V_260 ;
F_34 ( V_117 , V_260 - 1 ) ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 2 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_259 * ) V_126 . V_151 ;
if ( V_39 != 0 ) {
if ( V_2 ) {
F_72 ( V_2 , V_265 ) ;
V_2 -> V_63 = true ;
}
goto V_266;
}
if ( V_2 == NULL ) {
V_3 -> V_267 = V_123 -> V_97 . V_86 . V_31 ;
goto V_268;
}
switch ( V_123 -> V_269 ) {
case V_270 :
F_9 ( V_49 , L_37 ) ;
break;
case V_271 :
V_2 -> V_272 = true ;
F_9 ( V_49 , L_38 ) ;
break;
case V_273 :
V_2 -> V_272 = true ;
F_9 ( V_49 , L_39 ) ;
break;
default:
F_9 ( V_154 , L_40 , V_123 -> V_269 ) ;
V_39 = - V_153 ;
goto V_266;
}
V_2 -> V_6 = F_41 ( V_123 -> V_274 ) ;
V_2 -> V_10 = V_123 -> V_144 ;
V_2 -> V_275 = F_41 ( V_123 -> V_276 ) ;
V_2 -> V_44 = V_212 ;
V_2 -> V_63 = false ;
V_2 -> V_32 = V_123 -> V_97 . V_86 . V_31 ;
F_75 ( V_2 -> V_67 , V_256 , sizeof( V_2 -> V_67 ) ) ;
if ( ( V_123 -> V_144 & V_277 ) &&
( ( V_2 -> V_6 & V_278 ) == 0 ) )
F_9 ( V_154 , L_41 ) ;
if ( V_2 -> V_8 &&
! ( V_2 -> V_3 -> V_9 -> V_10 & V_11 ) )
F_9 ( V_154 , L_42 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_3 -> V_9 -> V_207 -> V_279 )
V_39 = V_2 -> V_3 -> V_9 -> V_207 -> V_279 ( V_121 , V_2 ) ;
V_268:
F_45 ( V_127 , V_123 ) ;
F_65 ( V_261 ) ;
return V_39 ;
V_266:
if ( V_123 -> V_97 . V_86 . V_240 == V_280 ) {
F_9 ( V_154 , L_43 , V_256 ) ;
}
goto V_268;
}
int
F_76 ( const unsigned int V_121 , struct V_1 * V_2 )
{
struct V_281 * V_117 ;
int V_39 = 0 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
F_9 ( V_49 , L_44 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
if ( ( V_2 -> V_63 ) || ( V_2 -> V_3 -> V_63 ) )
return 0 ;
V_39 = F_27 ( V_48 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_39 = F_71 ( V_121 , V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 )
F_72 ( V_2 , V_282 ) ;
return V_39 ;
}
static struct V_283 *
F_77 ( void )
{
struct V_283 * V_80 ;
V_80 = F_69 ( sizeof( struct V_283 ) , V_227 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_284 . V_285 = F_3 ( F_63
( struct V_283 , V_286 ) ) ;
V_80 -> V_284 . V_103 = F_7 ( 16 ) ;
V_80 -> V_284 . V_287 = F_3 ( F_63
( struct V_283 , V_288 ) ) ;
V_80 -> V_284 . V_289 = F_3 ( 4 ) ;
V_80 -> V_288 [ 0 ] = 'D' ;
V_80 -> V_288 [ 1 ] = 'H' ;
V_80 -> V_288 [ 2 ] = 'n' ;
V_80 -> V_288 [ 3 ] = 'Q' ;
return V_80 ;
}
static struct V_283 *
F_78 ( struct V_290 * V_291 )
{
struct V_283 * V_80 ;
V_80 = F_69 ( sizeof( struct V_283 ) , V_227 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_284 . V_285 = F_3 ( F_63
( struct V_283 , V_286 ) ) ;
V_80 -> V_284 . V_103 = F_7 ( 16 ) ;
V_80 -> V_284 . V_287 = F_3 ( F_63
( struct V_283 , V_288 ) ) ;
V_80 -> V_284 . V_289 = F_3 ( 4 ) ;
V_80 -> V_286 . V_292 . V_293 = V_291 -> V_294 ;
V_80 -> V_286 . V_292 . V_295 = V_291 -> V_296 ;
V_80 -> V_288 [ 0 ] = 'D' ;
V_80 -> V_288 [ 1 ] = 'H' ;
V_80 -> V_288 [ 2 ] = 'n' ;
V_80 -> V_288 [ 3 ] = 'C' ;
return V_80 ;
}
static T_5
F_79 ( struct V_19 * V_9 , struct V_297 * V_123 ,
unsigned int * V_298 )
{
char * V_299 ;
struct V_300 * V_301 ;
unsigned int V_302 ;
unsigned int V_303 ;
char * V_304 ;
V_299 = ( char * ) V_123 + 4 + F_41 ( V_123 -> V_305 ) ;
V_303 = F_41 ( V_123 -> V_306 ) ;
V_301 = (struct V_300 * ) V_299 ;
while ( V_303 >= sizeof( struct V_300 ) ) {
V_304 = F_22 ( V_301 -> V_287 ) + ( char * ) V_301 ;
if ( F_22 ( V_301 -> V_289 ) == 4 &&
strncmp ( V_304 , L_45 , 4 ) == 0 )
return V_9 -> V_207 -> V_307 ( V_301 , V_298 ) ;
V_302 = F_41 ( V_301 -> V_308 ) ;
if ( ! V_302 )
break;
V_303 -= V_302 ;
V_301 = (struct V_300 * ) ( ( char * ) V_301 + V_302 ) ;
}
return 0 ;
}
static int
F_80 ( struct V_19 * V_9 , struct V_124 * V_125 ,
unsigned int * V_309 , T_5 * V_310 )
{
struct V_311 * V_117 = V_125 [ 0 ] . V_151 ;
unsigned int V_312 = * V_309 ;
V_125 [ V_312 ] . V_151 = V_9 -> V_207 -> V_313 ( V_310 + 1 , * V_310 ) ;
if ( V_125 [ V_312 ] . V_151 == NULL )
return - V_89 ;
V_125 [ V_312 ] . V_152 = V_9 -> V_136 -> V_314 ;
V_117 -> V_315 = V_316 ;
if ( ! V_117 -> V_305 )
V_117 -> V_305 = F_7 (
sizeof( struct V_311 ) - 4 +
V_125 [ V_312 - 1 ] . V_152 ) ;
F_81 ( & V_117 -> V_306 ,
V_9 -> V_136 -> V_314 ) ;
F_34 ( & V_117 -> V_97 , V_9 -> V_136 -> V_314 ) ;
* V_309 = V_312 + 1 ;
return 0 ;
}
static struct V_317 *
F_82 ( struct V_290 * V_318 )
{
struct V_317 * V_80 ;
V_80 = F_69 ( sizeof( struct V_317 ) , V_227 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_284 . V_285 = F_3 ( F_63
( struct V_317 , V_319 ) ) ;
V_80 -> V_284 . V_103 = F_7 ( sizeof( struct V_320 ) ) ;
V_80 -> V_284 . V_287 = F_3 ( F_63
( struct V_317 , V_288 ) ) ;
V_80 -> V_284 . V_289 = F_3 ( 4 ) ;
V_80 -> V_319 . V_321 = 0 ;
V_80 -> V_319 . V_36 = F_7 ( V_322 ) ;
F_83 ( V_80 -> V_319 . V_323 ) ;
memcpy ( V_318 -> V_324 , V_80 -> V_319 . V_323 , 16 ) ;
V_80 -> V_288 [ 0 ] = 'D' ;
V_80 -> V_288 [ 1 ] = 'H' ;
V_80 -> V_288 [ 2 ] = '2' ;
V_80 -> V_288 [ 3 ] = 'Q' ;
return V_80 ;
}
static struct V_325 *
F_84 ( struct V_290 * V_291 )
{
struct V_325 * V_80 ;
V_80 = F_69 ( sizeof( struct V_325 ) ,
V_227 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_284 . V_285 =
F_3 ( F_63 ( struct V_325 ,
V_319 ) ) ;
V_80 -> V_284 . V_103 =
F_7 ( sizeof( struct V_326 ) ) ;
V_80 -> V_284 . V_287 =
F_3 ( F_63 ( struct V_325 ,
V_288 ) ) ;
V_80 -> V_284 . V_289 = F_3 ( 4 ) ;
V_80 -> V_319 . V_292 . V_293 = V_291 -> V_294 ;
V_80 -> V_319 . V_292 . V_295 = V_291 -> V_296 ;
V_80 -> V_319 . V_36 = F_7 ( V_322 ) ;
memcpy ( V_80 -> V_319 . V_323 , V_291 -> V_324 , 16 ) ;
V_80 -> V_288 [ 0 ] = 'D' ;
V_80 -> V_288 [ 1 ] = 'H' ;
V_80 -> V_288 [ 2 ] = '2' ;
V_80 -> V_288 [ 3 ] = 'C' ;
return V_80 ;
}
static int
F_85 ( struct V_124 * V_125 , unsigned int * V_309 ,
struct V_327 * V_328 )
{
struct V_311 * V_117 = V_125 [ 0 ] . V_151 ;
unsigned int V_312 = * V_309 ;
V_125 [ V_312 ] . V_151 = F_82 ( V_328 -> V_291 ) ;
if ( V_125 [ V_312 ] . V_151 == NULL )
return - V_89 ;
V_125 [ V_312 ] . V_152 = sizeof( struct V_317 ) ;
if ( ! V_117 -> V_305 )
V_117 -> V_305 =
F_7 ( sizeof( struct V_311 ) - 4 +
V_125 [ 1 ] . V_152 ) ;
F_81 ( & V_117 -> V_306 , sizeof( struct V_317 ) ) ;
F_34 ( & V_117 -> V_97 , sizeof( struct V_317 ) ) ;
* V_309 = V_312 + 1 ;
return 0 ;
}
static int
F_86 ( struct V_124 * V_125 , unsigned int * V_309 ,
struct V_327 * V_328 )
{
struct V_311 * V_117 = V_125 [ 0 ] . V_151 ;
unsigned int V_312 = * V_309 ;
V_328 -> V_70 = false ;
V_125 [ V_312 ] . V_151 = F_84 ( V_328 -> V_291 ) ;
if ( V_125 [ V_312 ] . V_151 == NULL )
return - V_89 ;
V_125 [ V_312 ] . V_152 = sizeof( struct V_325 ) ;
if ( ! V_117 -> V_305 )
V_117 -> V_305 =
F_7 ( sizeof( struct V_311 ) - 4 +
V_125 [ 1 ] . V_152 ) ;
F_81 ( & V_117 -> V_306 ,
sizeof( struct V_325 ) ) ;
F_34 ( & V_117 -> V_97 ,
sizeof( struct V_325 ) ) ;
* V_309 = V_312 + 1 ;
return 0 ;
}
static int
F_87 ( struct V_124 * V_125 , unsigned int * V_309 ,
struct V_327 * V_328 , bool V_65 )
{
struct V_311 * V_117 = V_125 [ 0 ] . V_151 ;
unsigned int V_312 = * V_309 ;
if ( V_65 ) {
if ( V_328 -> V_70 )
return F_86 ( V_125 , V_309 ,
V_328 ) ;
else
return F_85 ( V_125 , V_309 , V_328 ) ;
}
if ( V_328 -> V_70 ) {
V_125 [ V_312 ] . V_151 = F_78 ( V_328 -> V_291 ) ;
V_328 -> V_70 = false ;
} else
V_125 [ V_312 ] . V_151 = F_77 () ;
if ( V_125 [ V_312 ] . V_151 == NULL )
return - V_89 ;
V_125 [ V_312 ] . V_152 = sizeof( struct V_283 ) ;
if ( ! V_117 -> V_305 )
V_117 -> V_305 =
F_7 ( sizeof( struct V_311 ) - 4 +
V_125 [ 1 ] . V_152 ) ;
F_81 ( & V_117 -> V_306 , sizeof( struct V_283 ) ) ;
F_34 ( & V_117 -> V_97 , sizeof( struct V_283 ) ) ;
* V_309 = V_312 + 1 ;
return 0 ;
}
static int
F_88 ( T_1 * * V_329 , int * V_330 , int * V_331 ,
const char * V_332 , const T_1 * V_333 )
{
int V_334 , V_335 ;
struct V_40 * V_257 ;
const T_1 V_336 [] = { F_3 ( '\\' ) , F_3 ( 0x0000 ) } ;
V_334 = strlen ( V_332 ) ;
if ( V_334 < 2 || ! ( V_332 [ 0 ] == '\\' && V_332 [ 1 ] == '\\' ) )
return - V_246 ;
V_332 += 2 ;
V_334 -= 2 ;
V_335 = F_89 ( ( V_337 * ) V_333 , V_338 ) ;
* V_331 = V_334 + 1 + V_335 ;
* V_330 = F_90 ( ( * V_331 + 1 ) * 2 , 8 ) ;
* V_329 = F_69 ( * V_330 , V_227 ) ;
if ( ! * V_329 )
return - V_89 ;
V_257 = F_11 () ;
F_74 ( * V_329 , V_332 , V_334 , V_257 ) ;
F_91 ( * V_329 , V_336 ) ;
F_91 ( * V_329 , V_333 ) ;
F_20 ( V_257 ) ;
return 0 ;
}
int
F_92 ( const unsigned int V_121 , struct V_327 * V_328 , T_1 * V_333 ,
T_5 * V_310 , struct V_339 * V_80 ,
struct V_340 * * V_341 )
{
struct V_311 * V_117 ;
struct V_297 * V_123 ;
struct V_19 * V_9 ;
struct V_1 * V_2 = V_328 -> V_2 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 4 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_342 ;
T_1 * V_343 = NULL ;
int V_344 ;
int V_39 = 0 ;
unsigned int V_345 = 2 ;
T_6 V_346 = 0 ;
char * V_347 = NULL , * V_348 = NULL ;
int V_131 = 0 ;
F_9 ( V_49 , L_46 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_39 = F_27 ( V_47 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
if ( V_328 -> V_349 & V_350 )
V_346 |= V_351 ;
if ( V_328 -> V_349 & V_352 )
V_346 |= V_353 ;
V_117 -> V_354 = V_355 ;
V_117 -> V_356 = F_7 ( V_328 -> V_357 ) ;
V_117 -> V_358 = F_7 ( V_346 ) ;
V_117 -> V_359 = V_360 ;
V_117 -> V_361 = F_7 ( V_328 -> V_362 ) ;
V_117 -> V_363 = F_7 ( V_328 -> V_349 & V_364 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_125 [ 0 ] . V_152 -- ;
V_117 -> V_287 = F_3 ( sizeof( struct V_311 ) - 4 ) ;
if ( V_2 -> V_6 & V_278 ) {
int V_365 ;
V_117 -> V_97 . V_86 . V_36 |= V_366 ;
V_39 = F_88 ( & V_343 , & V_344 ,
& V_365 ,
V_2 -> V_67 , V_333 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_289 = F_3 ( V_365 * 2 ) ;
V_342 = V_344 ;
V_333 = V_343 ;
} else {
V_342 = ( 2 * F_89 ( ( V_337 * ) V_333 , V_338 ) ) + 2 ;
V_117 -> V_289 = F_3 ( V_342 - 2 ) ;
if ( V_342 % 8 != 0 ) {
V_344 = F_90 ( V_342 , 8 ) ;
V_343 = F_69 ( V_344 , V_227 ) ;
if ( ! V_343 )
return - V_89 ;
memcpy ( ( char * ) V_343 , ( const char * ) V_333 ,
V_342 ) ;
V_342 = V_344 ;
V_333 = V_343 ;
}
}
V_125 [ 1 ] . V_152 = V_342 ;
V_125 [ 1 ] . V_151 = V_333 ;
F_34 ( V_117 , V_342 - 1 ) ;
if ( ! V_9 -> V_367 )
* V_310 = V_368 ;
if ( ! ( V_9 -> V_10 & V_369 ) ||
* V_310 == V_368 )
V_117 -> V_315 = * V_310 ;
else {
V_39 = F_80 ( V_9 , V_125 , & V_345 , V_310 ) ;
if ( V_39 ) {
F_39 ( V_117 ) ;
F_65 ( V_343 ) ;
return V_39 ;
}
V_348 = V_125 [ V_345 - 1 ] . V_151 ;
}
if ( * V_310 == V_370 ) {
if ( V_9 -> V_10 & V_369 ) {
struct V_300 * V_284 =
(struct V_300 * ) V_125 [ V_345 - 1 ] . V_151 ;
V_284 -> V_308 =
F_7 ( V_9 -> V_136 -> V_314 ) ;
}
V_39 = F_87 ( V_125 , & V_345 , V_328 ,
V_2 -> V_65 ) ;
if ( V_39 ) {
F_39 ( V_117 ) ;
F_65 ( V_343 ) ;
F_65 ( V_348 ) ;
return V_39 ;
}
V_347 = V_125 [ V_345 - 1 ] . V_151 ;
}
V_39 = F_38 ( V_121 , V_3 , V_125 , V_345 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_297 * ) V_126 . V_151 ;
if ( V_39 != 0 ) {
F_72 ( V_2 , V_371 ) ;
if ( V_341 )
* V_341 = F_57 ( V_123 , F_37 ( V_123 ) + 4 ,
V_227 ) ;
goto V_372;
}
V_328 -> V_291 -> V_294 = V_123 -> V_293 ;
V_328 -> V_291 -> V_296 = V_123 -> V_295 ;
if ( V_80 ) {
memcpy ( V_80 , & V_123 -> V_373 , 32 ) ;
V_80 -> V_374 = V_123 -> V_374 ;
V_80 -> V_375 = V_123 -> V_376 ;
V_80 -> V_377 = V_123 -> V_358 ;
V_80 -> V_378 = F_7 ( 1 ) ;
V_80 -> V_379 = 0 ;
}
if ( V_123 -> V_380 == V_316 )
* V_310 = F_79 ( V_9 , V_123 , & V_328 -> V_291 -> V_298 ) ;
else
* V_310 = V_123 -> V_380 ;
V_372:
F_65 ( V_343 ) ;
F_65 ( V_348 ) ;
F_65 ( V_347 ) ;
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int
F_47 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_294 ,
T_7 V_296 , T_3 V_381 , bool V_382 , bool V_383 ,
char * V_384 , T_3 V_385 ,
char * * V_386 , T_3 * V_387 )
{
struct V_388 * V_117 ;
struct V_389 * V_123 ;
struct V_12 * V_13 ;
struct V_42 * V_3 ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_345 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_47 ) ;
if ( V_386 != NULL )
* V_386 = NULL ;
if ( V_387 )
* V_387 = 0 ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
else
return - V_52 ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_75 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( V_383 ) {
if ( V_3 -> V_267 == 0 ) {
F_39 ( V_117 ) ;
return - V_390 ;
}
F_9 ( V_49 , L_48 ,
V_117 -> V_97 . V_86 . V_31 , V_3 -> V_267 ) ;
V_117 -> V_97 . V_86 . V_31 = V_3 -> V_267 ;
}
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_391 = F_7 ( V_381 ) ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
if ( V_385 ) {
V_117 -> V_392 = F_7 ( V_385 ) ;
V_117 -> V_393 =
F_7 ( F_63 ( struct V_388 , V_242 ) - 4 ) ;
V_125 [ 1 ] . V_151 = V_384 ;
V_125 [ 1 ] . V_152 = V_385 ;
V_345 = 2 ;
} else
V_345 = 1 ;
V_117 -> V_394 = 0 ;
V_117 -> V_395 = 0 ;
V_117 -> V_396 = F_7 ( V_180 ) ;
if ( V_382 )
V_117 -> V_36 = F_7 ( V_397 ) ;
else
V_117 -> V_36 = 0 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
if ( V_385 ) {
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
F_34 ( V_117 , V_385 - 1 ) ;
} else
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , V_345 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_389 * ) V_126 . V_151 ;
if ( ( V_39 != 0 ) && ( V_39 != - V_246 ) ) {
F_72 ( V_2 , V_398 ) ;
goto V_399;
} else if ( V_39 == - V_246 ) {
if ( ( V_381 != V_400 ) &&
( V_381 != V_401 ) ) {
F_72 ( V_2 , V_398 ) ;
goto V_399;
}
}
if ( ( V_387 == NULL ) || ( V_386 == NULL ) )
goto V_399;
* V_387 = F_41 ( V_123 -> V_395 ) ;
if ( * V_387 == 0 )
goto V_399;
else if ( * V_387 > 0xFF00 ) {
F_9 ( V_154 , L_49 , * V_387 ) ;
* V_387 = 0 ;
V_39 = - V_52 ;
goto V_399;
}
if ( F_37 ( V_123 ) < F_41 ( V_123 -> V_394 ) + * V_387 ) {
F_9 ( V_154 , L_50 , * V_387 ,
F_41 ( V_123 -> V_394 ) ) ;
* V_387 = 0 ;
V_39 = - V_52 ;
goto V_399;
}
* V_386 = F_61 ( * V_387 , V_227 ) ;
if ( * V_386 == NULL ) {
V_39 = - V_89 ;
goto V_399;
}
V_13 = F_28 ( V_123 ) ;
memcpy ( * V_386 , ( char * ) V_13 + F_41 ( V_123 -> V_394 ) , * V_387 ) ;
V_399:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int
F_93 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 )
{
int V_39 ;
struct V_402 V_403 ;
char * V_404 = NULL ;
V_403 . V_405 =
F_3 ( V_406 ) ;
V_39 = F_47 ( V_121 , V_2 , V_294 , V_296 ,
V_407 , true ,
false ,
( char * ) & V_403 ,
2 , & V_404 , NULL ) ;
F_9 ( V_49 , L_51 , V_39 ) ;
return V_39 ;
}
int
F_94 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 )
{
struct V_408 * V_117 ;
struct V_409 * V_123 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_52 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_56 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_409 * ) V_126 . V_151 ;
if ( V_39 != 0 ) {
F_72 ( V_2 , V_410 ) ;
goto V_411;
}
V_411:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static int
F_95 ( unsigned int V_412 , unsigned int V_413 ,
struct V_414 * V_97 , unsigned int V_415 )
{
unsigned int V_416 = F_96 ( V_97 -> V_98 ) ;
char * V_417 = V_416 + 4 + ( char * ) V_97 ;
char * V_418 = 4 + V_412 + ( char * ) V_97 ;
char * V_419 = V_418 + V_413 ;
if ( V_413 < V_415 ) {
F_9 ( V_154 , L_53 ,
V_413 , V_415 ) ;
return - V_246 ;
}
if ( ( V_416 > 0x7FFFFF ) || ( V_413 > 0x7FFFFF ) ) {
F_9 ( V_154 , L_54 ,
V_413 , V_416 ) ;
return - V_246 ;
}
if ( ( V_418 > V_417 ) || ( V_419 > V_417 ) ) {
F_9 ( V_154 , L_55 ) ;
return - V_246 ;
}
return 0 ;
}
static int
F_97 ( unsigned int V_412 , unsigned int V_413 ,
struct V_414 * V_97 , unsigned int V_420 ,
char * V_219 )
{
char * V_418 = 4 + V_412 + ( char * ) V_97 ;
int V_39 ;
if ( ! V_219 )
return - V_246 ;
V_39 = F_95 ( V_412 , V_413 , V_97 , V_420 ) ;
if ( V_39 )
return V_39 ;
memcpy ( V_219 , V_418 , V_413 ) ;
return 0 ;
}
static int
F_98 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_8 V_421 , T_8 V_422 ,
T_3 V_423 , T_9 V_424 , T_9 V_425 , void * * V_219 ,
T_3 * V_426 )
{
struct V_427 * V_117 ;
struct V_428 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
F_9 ( V_49 , L_56 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_78 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_429 = V_422 ;
V_117 -> V_430 = V_421 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_117 -> V_431 = F_7 ( V_423 ) ;
V_117 -> V_432 =
F_3 ( sizeof( struct V_427 ) - 1 - 4 ) ;
V_117 -> V_433 = F_7 ( V_424 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_428 * ) V_126 . V_151 ;
if ( V_39 ) {
F_72 ( V_2 , V_434 ) ;
goto V_435;
}
if ( V_426 ) {
* V_426 = F_41 ( V_123 -> V_433 ) ;
if ( ! * V_219 ) {
* V_219 = F_61 ( * V_426 , V_227 ) ;
if ( ! * V_219 ) {
F_9 ( V_154 ,
L_57 ,
V_39 ) ;
* V_426 = 0 ;
goto V_435;
}
}
}
V_39 = F_97 ( F_22 ( V_123 -> V_436 ) ,
F_41 ( V_123 -> V_433 ) ,
& V_123 -> V_97 , V_425 , * V_219 ) ;
V_435:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int F_99 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , struct V_339 * V_219 )
{
return F_98 ( V_121 , V_2 , V_294 , V_296 ,
V_437 , V_438 , 0 ,
sizeof( struct V_339 ) + V_338 * 2 ,
sizeof( struct V_339 ) , ( void * * ) & V_219 ,
NULL ) ;
}
int
F_100 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 ,
void * * V_219 , T_3 * V_387 )
{
T_6 V_423 = V_439 | V_440 | V_441 ;
* V_387 = 0 ;
return F_98 ( V_121 , V_2 , V_294 , V_296 ,
0 , V_442 , V_423 ,
V_443 ,
sizeof( struct V_339 ) , V_219 , V_387 ) ;
}
int
F_101 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_10 * V_444 )
{
return F_98 ( V_121 , V_2 , V_294 , V_296 ,
V_445 , V_438 , 0 ,
sizeof( struct V_446 ) ,
sizeof( struct V_446 ) ,
( void * * ) & V_444 , NULL ) ;
}
static void
F_102 ( struct V_447 * V_448 )
{
struct V_19 * V_9 = V_448 -> V_449 ;
struct V_450 * V_123 = (struct V_450 * ) V_448 -> V_451 ;
unsigned int V_452 = 1 ;
if ( V_448 -> V_453 == V_454 )
V_452 = F_22 ( V_123 -> V_97 . V_86 . V_23 ) ;
F_103 ( V_448 ) ;
F_104 ( V_9 , V_452 , V_455 ) ;
}
void F_105 ( struct V_456 * V_457 )
{
struct V_19 * V_9 = F_106 ( V_457 ,
struct V_19 , V_70 . V_457 ) ;
struct V_42 * V_3 ;
struct V_1 * V_2 , * V_458 ;
struct V_459 V_460 ;
int V_461 = false ;
int V_39 ;
int V_462 = false ;
F_12 ( & V_9 -> V_463 ) ;
F_107 ( & V_460 ) ;
F_9 ( V_49 , L_58 ) ;
F_4 ( & V_464 ) ;
F_108 (ses, &server->smb_ses_list, smb_ses_list) {
F_108 (tcon, &ses->tcon_list, tcon_list) {
if ( V_2 -> V_63 || V_2 -> V_66 ) {
V_2 -> V_465 ++ ;
F_109 ( & V_2 -> V_466 , & V_460 ) ;
V_461 = true ;
}
}
}
if ( V_461 )
V_9 -> V_467 ++ ;
F_6 ( & V_464 ) ;
F_110 (tcon, tcon2, &tmp_list, rlist) {
V_39 = F_8 ( V_68 , V_2 ) ;
if ( ! V_39 )
F_111 ( V_2 ) ;
else
V_462 = true ;
F_112 ( & V_2 -> V_466 ) ;
F_113 ( V_2 ) ;
}
F_9 ( V_49 , L_59 ) ;
if ( V_462 )
F_18 ( V_69 , & V_9 -> V_70 , 2 * V_60 ) ;
F_15 ( & V_9 -> V_463 ) ;
if ( V_461 )
F_114 ( V_9 , 1 ) ;
}
int
F_115 ( struct V_19 * V_9 )
{
struct V_468 * V_117 ;
int V_39 = 0 ;
struct V_124 V_125 [ 2 ] ;
struct V_469 V_470 = { . V_471 = V_125 ,
. V_472 = 2 } ;
F_9 ( V_49 , L_60 ) ;
if ( V_9 -> V_53 == V_473 ) {
F_18 ( V_69 , & V_9 -> V_70 , 0 ) ;
return V_39 ;
}
V_39 = F_27 ( V_474 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_125 [ 0 ] . V_152 = 4 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 1 ] . V_152 = F_37 ( V_117 ) ;
V_125 [ 1 ] . V_151 = ( char * ) V_117 + 4 ;
V_39 = F_116 ( V_9 , & V_470 , NULL , F_102 , NULL ,
V_9 , V_455 ) ;
if ( V_39 )
F_9 ( V_49 , L_61 , V_39 ) ;
F_39 ( V_117 ) ;
return V_39 ;
}
int
F_117 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_294 ,
T_7 V_296 )
{
struct V_475 * V_117 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_62 ) ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
V_39 = F_27 ( V_72 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
if ( V_39 != 0 )
F_72 ( V_2 , V_476 ) ;
F_45 ( V_127 , V_126 . V_151 ) ;
return V_39 ;
}
static int
F_118 ( void * * V_80 , unsigned int * V_81 ,
struct V_477 * V_478 , unsigned int V_479 ,
int V_480 )
{
int V_39 = - V_481 ;
struct V_482 * V_117 = NULL ;
struct V_12 * V_13 ;
V_39 = F_23 ( V_73 , V_478 -> V_2 , ( void * * ) & V_117 ,
V_81 ) ;
if ( V_39 )
return V_39 ;
if ( V_478 -> V_2 -> V_3 -> V_9 == NULL )
return - V_483 ;
V_13 = & V_117 -> V_86 ;
V_13 -> V_24 = F_7 ( V_478 -> V_484 ) ;
V_117 -> V_293 = V_478 -> V_294 ;
V_117 -> V_295 = V_478 -> V_296 ;
V_117 -> V_485 = 0 ;
V_117 -> V_486 = 0 ;
V_117 -> V_199 = 0 ;
V_117 -> V_487 = 0 ;
V_117 -> V_488 = F_7 ( V_478 -> V_489 ) ;
V_117 -> V_490 = F_119 ( V_478 -> V_412 ) ;
if ( V_480 & V_491 ) {
if ( ! ( V_480 & V_492 ) ) {
* V_81 = F_120 ( * V_81 , 8 ) * 8 ;
V_13 -> V_493 = F_7 ( * V_81 ) ;
} else
V_13 -> V_493 = 0 ;
if ( V_480 & V_494 ) {
V_13 -> V_36 |= V_495 ;
V_13 -> V_33 = 0xFFFFFFFF ;
V_13 -> V_31 = 0xFFFFFFFF ;
V_117 -> V_293 = 0xFFFFFFFF ;
V_117 -> V_295 = 0xFFFFFFFF ;
}
}
if ( V_479 > V_478 -> V_489 )
V_117 -> V_496 = F_7 ( V_479 ) ;
else
V_117 -> V_496 = 0 ;
* V_80 = V_117 ;
return V_39 ;
}
static void
F_121 ( struct V_447 * V_448 )
{
struct V_497 * V_498 = V_448 -> V_449 ;
struct V_1 * V_2 = F_122 ( V_498 -> V_499 -> V_500 ) ;
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
struct V_12 * V_13 =
(struct V_12 * ) V_498 -> V_125 [ 1 ] . V_151 ;
unsigned int V_452 = 1 ;
struct V_469 V_470 = { . V_471 = V_498 -> V_125 ,
. V_472 = 2 ,
. V_501 = V_498 -> V_502 ,
. V_503 = V_498 -> V_504 ,
. V_505 = V_498 -> V_506 ,
. V_507 = V_498 -> V_508 } ;
F_9 ( V_49 , L_63 ,
V_133 , V_448 -> V_448 , V_448 -> V_453 , V_498 -> V_231 ,
V_498 -> V_509 ) ;
switch ( V_448 -> V_453 ) {
case V_454 :
V_452 = F_22 ( V_13 -> V_23 ) ;
if ( V_9 -> V_35 && ! V_448 -> V_510 ) {
int V_39 ;
V_39 = F_123 ( & V_470 , V_9 ) ;
if ( V_39 )
F_9 ( V_154 , L_64 ,
V_39 ) ;
}
F_124 ( V_498 -> V_511 ) ;
F_125 ( V_2 , V_498 -> V_511 ) ;
break;
case V_512 :
case V_513 :
V_498 -> V_231 = - V_58 ;
if ( V_9 -> V_35 && V_498 -> V_511 )
V_498 -> V_511 = 0 ;
F_124 ( V_498 -> V_511 ) ;
F_125 ( V_2 , V_498 -> V_511 ) ;
break;
default:
if ( V_498 -> V_231 != - V_514 )
V_498 -> V_231 = - V_52 ;
}
if ( V_498 -> V_231 )
F_72 ( V_2 , V_515 ) ;
F_126 ( V_69 , & V_498 -> V_457 ) ;
F_103 ( V_448 ) ;
F_104 ( V_9 , V_452 , 0 ) ;
}
int
F_127 ( struct V_497 * V_498 )
{
int V_39 , V_131 = 0 ;
char * V_80 ;
struct V_12 * V_13 ;
struct V_477 V_478 ;
struct V_469 V_470 = { . V_471 = V_498 -> V_125 ,
. V_472 = 2 } ;
struct V_19 * V_9 ;
unsigned int V_81 ;
T_11 V_516 ;
F_9 ( V_49 , L_65 ,
V_133 , V_498 -> V_412 , V_498 -> V_509 ) ;
V_478 . V_2 = F_122 ( V_498 -> V_499 -> V_500 ) ;
V_478 . V_412 = V_498 -> V_412 ;
V_478 . V_489 = V_498 -> V_509 ;
V_478 . V_294 = V_498 -> V_499 -> V_291 . V_294 ;
V_478 . V_296 = V_498 -> V_499 -> V_291 . V_296 ;
V_478 . V_484 = V_498 -> V_484 ;
V_9 = V_478 . V_2 -> V_3 -> V_9 ;
V_39 = F_118 ( ( void * * ) & V_80 , & V_81 , & V_478 , 0 , 0 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_498 -> V_21 ) {
V_498 -> V_21 = 0 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_517 -- ;
F_6 ( & V_9 -> V_20 ) ;
}
return V_39 ;
}
if ( F_1 ( V_478 . V_2 ) )
V_131 |= V_250 ;
V_516 = F_29 ( V_81 ) ;
V_498 -> V_125 [ 0 ] . V_151 = & V_516 ;
V_498 -> V_125 [ 0 ] . V_152 = sizeof( T_11 ) ;
V_498 -> V_125 [ 1 ] . V_151 = V_80 ;
V_498 -> V_125 [ 1 ] . V_152 = V_81 ;
V_13 = (struct V_12 * ) V_80 ;
if ( V_498 -> V_21 ) {
V_13 -> V_30 = F_3 ( F_120 ( V_498 -> V_509 ,
V_443 ) ) ;
V_13 -> V_23 = V_13 -> V_30 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_21 += V_498 -> V_21 -
F_22 ( V_13 -> V_30 ) ;
F_6 ( & V_9 -> V_20 ) ;
F_128 ( & V_9 -> V_518 ) ;
V_131 |= V_519 ;
}
F_129 ( & V_498 -> V_520 ) ;
V_39 = F_116 ( V_478 . V_2 -> V_3 -> V_9 , & V_470 ,
V_521 , F_121 ,
V_522 , V_498 , V_131 ) ;
if ( V_39 ) {
F_130 ( & V_498 -> V_520 , V_523 ) ;
F_72 ( V_478 . V_2 , V_515 ) ;
}
F_39 ( V_80 ) ;
return V_39 ;
}
int
F_131 ( const unsigned int V_121 , struct V_477 * V_478 ,
unsigned int * V_524 , char * * V_80 , int * V_525 )
{
int V_127 , V_39 = - V_481 ;
struct V_482 * V_117 = NULL ;
struct V_526 * V_123 = NULL ;
struct V_12 * V_13 ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
unsigned int V_81 ;
T_11 V_516 ;
struct V_469 V_470 = { . V_471 = V_125 ,
. V_472 = 2 } ;
int V_131 = V_205 ;
struct V_42 * V_3 = V_478 -> V_2 -> V_3 ;
* V_524 = 0 ;
V_39 = F_118 ( ( void * * ) & V_117 , & V_81 , V_478 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_478 -> V_2 ) )
V_131 |= V_250 ;
V_516 = F_29 ( V_81 ) ;
V_125 [ 0 ] . V_151 = & V_516 ;
V_125 [ 0 ] . V_152 = sizeof( T_11 ) ;
V_125 [ 1 ] . V_151 = V_117 ;
V_125 [ 1 ] . V_152 = V_81 ;
V_39 = F_132 ( V_121 , V_3 , & V_470 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_526 * ) V_126 . V_151 ;
V_13 = F_28 ( V_123 ) ;
if ( V_13 -> V_240 == V_527 ) {
F_45 ( V_127 , V_126 . V_151 ) ;
return 0 ;
}
if ( V_39 ) {
F_72 ( V_478 -> V_2 , V_515 ) ;
F_9 ( V_154 , L_66 , V_39 ) ;
} else {
* V_524 = F_41 ( V_123 -> V_103 ) ;
if ( ( * V_524 > V_528 ) ||
( * V_524 > V_478 -> V_489 ) ) {
F_9 ( V_49 , L_67 ,
* V_524 , V_478 -> V_489 ) ;
V_39 = - V_52 ;
* V_524 = 0 ;
}
}
if ( * V_80 ) {
memcpy ( * V_80 , ( char * ) V_13 + V_123 -> V_285 , * V_524 ) ;
F_45 ( V_127 , V_126 . V_151 ) ;
} else if ( V_127 != V_202 ) {
* V_80 = V_126 . V_151 ;
if ( V_127 == V_201 )
* V_525 = V_201 ;
else if ( V_127 == V_529 )
* V_525 = V_529 ;
}
return V_39 ;
}
static void
F_133 ( struct V_447 * V_448 )
{
struct V_530 * V_531 = V_448 -> V_449 ;
struct V_1 * V_2 = F_122 ( V_531 -> V_499 -> V_500 ) ;
unsigned int V_532 ;
struct V_533 * V_123 = (struct V_533 * ) V_448 -> V_451 ;
unsigned int V_452 = 1 ;
switch ( V_448 -> V_453 ) {
case V_454 :
V_452 = F_22 ( V_123 -> V_97 . V_86 . V_23 ) ;
V_531 -> V_231 = F_134 ( V_448 , V_2 -> V_3 -> V_9 , 0 ) ;
if ( V_531 -> V_231 != 0 )
break;
V_532 = F_41 ( V_123 -> V_103 ) ;
if ( V_532 > V_531 -> V_509 )
V_532 &= 0xFFFF ;
if ( V_532 < V_531 -> V_509 )
V_531 -> V_231 = - V_534 ;
else
V_531 -> V_509 = V_532 ;
break;
case V_512 :
case V_513 :
V_531 -> V_231 = - V_58 ;
break;
default:
V_531 -> V_231 = - V_52 ;
break;
}
if ( V_531 -> V_231 )
F_72 ( V_2 , V_535 ) ;
F_126 ( V_69 , & V_531 -> V_457 ) ;
F_103 ( V_448 ) ;
F_104 ( V_2 -> V_3 -> V_9 , V_452 , 0 ) ;
}
int
F_135 ( struct V_530 * V_531 ,
void (* F_136)( struct V_536 * V_536 ) )
{
int V_39 = - V_481 , V_131 = 0 ;
struct V_537 * V_117 = NULL ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_122 ( V_531 -> V_499 -> V_500 ) ;
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
struct V_124 V_125 [ 2 ] ;
struct V_469 V_470 = { } ;
V_39 = F_27 ( V_46 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_531 -> V_21 ) {
V_531 -> V_21 = 0 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_517 -- ;
F_6 ( & V_9 -> V_20 ) ;
}
goto V_538;
}
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_13 = F_28 ( V_117 ) ;
V_13 -> V_24 = F_7 ( V_531 -> V_499 -> V_484 ) ;
V_117 -> V_293 = V_531 -> V_499 -> V_291 . V_294 ;
V_117 -> V_295 = V_531 -> V_499 -> V_291 . V_296 ;
V_117 -> V_539 = 0 ;
V_117 -> V_540 = 0 ;
V_117 -> V_199 = 0 ;
V_117 -> V_490 = F_119 ( V_531 -> V_412 ) ;
V_117 -> V_285 = F_3 (
F_63 ( struct V_537 , V_242 ) - 4 ) ;
V_117 -> V_496 = 0 ;
V_125 [ 0 ] . V_152 = 4 ;
V_125 [ 0 ] . V_151 = V_117 ;
V_125 [ 1 ] . V_152 = F_37 ( V_117 ) - 1 ;
V_125 [ 1 ] . V_151 = ( char * ) V_117 + 4 ;
V_470 . V_471 = V_125 ;
V_470 . V_472 = 2 ;
V_470 . V_501 = V_531 -> V_502 ;
V_470 . V_503 = V_531 -> V_504 ;
V_470 . V_505 = V_531 -> V_506 ;
V_470 . V_507 = V_531 -> V_508 ;
F_9 ( V_49 , L_68 ,
V_531 -> V_412 , V_531 -> V_509 ) ;
V_117 -> V_488 = F_7 ( V_531 -> V_509 ) ;
F_34 ( & V_117 -> V_97 , V_531 -> V_509 - 1 ) ;
if ( V_531 -> V_21 ) {
V_13 -> V_30 = F_3 ( F_120 ( V_531 -> V_509 ,
V_443 ) ) ;
V_13 -> V_23 = V_13 -> V_30 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_21 += V_531 -> V_21 -
F_22 ( V_13 -> V_30 ) ;
F_6 ( & V_9 -> V_20 ) ;
F_128 ( & V_9 -> V_518 ) ;
V_131 |= V_519 ;
}
F_129 ( & V_531 -> V_520 ) ;
V_39 = F_116 ( V_9 , & V_470 , NULL , F_133 , NULL ,
V_531 , V_131 ) ;
if ( V_39 ) {
F_130 ( & V_531 -> V_520 , F_136 ) ;
F_72 ( V_2 , V_535 ) ;
}
V_538:
F_39 ( V_117 ) ;
return V_39 ;
}
int
F_137 ( const unsigned int V_121 , struct V_477 * V_478 ,
unsigned int * V_524 , struct V_124 * V_125 , int V_541 )
{
int V_39 = 0 ;
struct V_537 * V_117 = NULL ;
struct V_533 * V_123 = NULL ;
int V_127 ;
struct V_124 V_126 ;
int V_131 = 0 ;
* V_524 = 0 ;
if ( V_541 < 1 )
return V_39 ;
V_39 = F_27 ( V_46 , V_478 -> V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( V_478 -> V_2 -> V_3 -> V_9 == NULL )
return - V_483 ;
if ( F_1 ( V_478 -> V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_478 -> V_484 ) ;
V_117 -> V_293 = V_478 -> V_294 ;
V_117 -> V_295 = V_478 -> V_296 ;
V_117 -> V_539 = 0 ;
V_117 -> V_540 = 0 ;
V_117 -> V_199 = 0 ;
V_117 -> V_488 = F_7 ( V_478 -> V_489 ) ;
V_117 -> V_490 = F_119 ( V_478 -> V_412 ) ;
V_117 -> V_285 = F_3 (
F_63 ( struct V_537 , V_242 ) - 4 ) ;
V_117 -> V_496 = 0 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
F_34 ( V_117 , V_478 -> V_489 - 1 ) ;
V_39 = F_38 ( V_121 , V_478 -> V_2 -> V_3 , V_125 , V_541 + 1 ,
& V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_533 * ) V_126 . V_151 ;
if ( V_39 ) {
F_72 ( V_478 -> V_2 , V_535 ) ;
F_9 ( V_154 , L_69 , V_39 ) ;
} else
* V_524 = F_41 ( V_123 -> V_103 ) ;
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static unsigned int
F_138 ( char * V_542 , char * V_419 , char * * V_543 , T_9 V_544 )
{
int V_228 ;
unsigned int V_545 = 0 ;
unsigned int V_546 = 0 ;
T_12 * V_547 ;
if ( V_542 == NULL )
return 0 ;
V_547 = ( T_12 * ) V_542 ;
while ( 1 ) {
V_547 = ( T_12 * )
( ( char * ) V_547 + V_546 ) ;
if ( ( char * ) V_547 + V_544 > V_419 ) {
F_9 ( V_154 , L_70 ) ;
break;
}
V_228 = F_41 ( V_547 -> V_548 ) ;
if ( ( char * ) V_547 + V_228 + V_544 > V_419 ) {
F_9 ( V_154 , L_71 ,
V_419 ) ;
break;
}
* V_543 = ( char * ) V_547 ;
V_545 ++ ;
V_546 = F_41 ( V_547 -> V_549 ) ;
if ( ! V_546 )
break;
}
return V_545 ;
}
int
F_139 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , int V_550 ,
struct V_551 * V_552 )
{
struct V_553 * V_117 ;
struct V_554 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_228 ;
int V_127 = V_202 ;
unsigned char * V_555 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
T_1 V_556 = F_3 ( '*' ) ;
char * V_417 ;
unsigned int V_557 = V_180 ;
T_9 V_558 ;
int V_131 = 0 ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_39 = F_27 ( V_76 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
switch ( V_552 -> V_559 ) {
case V_560 :
V_117 -> V_561 = V_562 ;
V_558 = sizeof( T_12 ) - 1 ;
break;
case V_563 :
V_117 -> V_561 = V_564 ;
V_558 = sizeof( V_565 ) - 1 ;
break;
default:
F_9 ( V_154 , L_72 ,
V_552 -> V_559 ) ;
V_39 = - V_246 ;
goto V_566;
}
V_117 -> V_567 = F_7 ( V_550 ) ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_228 = 0x2 ;
V_555 = V_117 -> V_242 ;
memcpy ( V_555 , & V_556 , V_228 ) ;
V_117 -> V_568 =
F_3 ( sizeof( struct V_553 ) - 1 - 4 ) ;
V_117 -> V_548 = F_3 ( V_228 ) ;
V_557 = F_5 (unsigned int, output_size, server->maxBuf) ;
V_557 = F_5 (unsigned int, output_size, 2 << 15 ) ;
V_117 -> V_433 = F_7 ( V_557 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
V_125 [ 1 ] . V_151 = ( char * ) ( V_117 -> V_242 ) ;
V_125 [ 1 ] . V_152 = V_228 ;
F_34 ( V_117 , V_228 - 1 ) ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 2 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_554 * ) V_126 . V_151 ;
if ( V_39 ) {
if ( V_39 == - V_514 &&
V_123 -> V_97 . V_86 . V_240 == V_569 ) {
V_552 -> V_570 = true ;
V_39 = 0 ;
}
F_72 ( V_2 , V_571 ) ;
goto V_566;
}
V_39 = F_95 ( F_22 ( V_123 -> V_436 ) ,
F_41 ( V_123 -> V_433 ) , & V_123 -> V_97 ,
V_558 ) ;
if ( V_39 )
goto V_566;
V_552 -> V_572 = true ;
if ( V_552 -> V_573 ) {
if ( V_552 -> V_574 )
F_39 ( V_552 -> V_573 ) ;
else
F_140 ( V_552 -> V_573 ) ;
}
V_552 -> V_573 = ( char * ) V_123 ;
V_552 -> V_575 = V_552 -> V_576 = 4 +
( char * ) & V_123 -> V_97 + F_22 ( V_123 -> V_436 ) ;
V_417 = F_37 ( V_123 ) + 4 + ( char * ) & V_123 -> V_97 ;
V_552 -> V_577 =
F_138 ( V_552 -> V_575 , V_417 ,
& V_552 -> V_576 , V_558 ) ;
V_552 -> V_578 += V_552 -> V_577 ;
F_9 ( V_49 , L_73 ,
V_552 -> V_577 , V_552 -> V_578 ,
V_552 -> V_575 , V_552 -> V_576 ) ;
if ( V_127 == V_529 )
V_552 -> V_574 = false ;
else if ( V_127 == V_201 )
V_552 -> V_574 = true ;
else
F_9 ( V_154 , L_74 ) ;
return V_39 ;
V_566:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static int
F_141 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_3 V_484 , T_8 V_421 ,
T_8 V_422 , T_3 V_423 , unsigned int V_312 ,
void * * V_219 , unsigned int * V_544 )
{
struct V_579 * V_117 ;
struct V_580 * V_123 = NULL ;
struct V_124 * V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
unsigned int V_581 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
if ( ! V_3 || ! ( V_3 -> V_9 ) )
return - V_52 ;
if ( ! V_312 )
return - V_246 ;
V_125 = F_61 ( sizeof( struct V_124 ) * V_312 , V_227 ) ;
if ( ! V_125 )
return - V_89 ;
V_39 = F_27 ( V_79 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
F_65 ( V_125 ) ;
return V_39 ;
}
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_484 ) ;
V_117 -> V_429 = V_422 ;
V_117 -> V_430 = V_421 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_117 -> V_431 = F_7 ( V_423 ) ;
V_117 -> V_582 =
F_3 ( sizeof( struct V_579 ) - 1 - 4 ) ;
V_117 -> V_583 = F_7 ( * V_544 ) ;
F_34 ( V_117 , * V_544 - 1 ) ;
memcpy ( V_117 -> V_242 , * V_219 , * V_544 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
for ( V_581 = 1 ; V_581 < V_312 ; V_581 ++ ) {
F_34 ( V_117 , V_544 [ V_581 ] ) ;
F_81 ( & V_117 -> V_583 , V_544 [ V_581 ] ) ;
V_125 [ V_581 ] . V_151 = ( char * ) V_219 [ V_581 ] ;
V_125 [ V_581 ] . V_152 = V_544 [ V_581 ] ;
}
V_39 = F_38 ( V_121 , V_3 , V_125 , V_312 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_580 * ) V_126 . V_151 ;
if ( V_39 != 0 )
F_72 ( V_2 , V_584 ) ;
F_45 ( V_127 , V_123 ) ;
F_65 ( V_125 ) ;
return V_39 ;
}
int
F_142 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_1 * V_585 )
{
struct V_586 V_587 ;
void * * V_219 ;
unsigned int V_544 [ 2 ] ;
int V_39 ;
int V_228 = ( 2 * F_89 ( ( V_337 * ) V_585 , V_338 ) ) ;
V_219 = F_61 ( sizeof( void * ) * 2 , V_227 ) ;
if ( ! V_219 )
return - V_89 ;
V_587 . V_588 = 1 ;
V_587 . V_589 = 0 ;
V_587 . V_548 = F_7 ( V_228 ) ;
V_219 [ 0 ] = & V_587 ;
V_544 [ 0 ] = sizeof( struct V_586 ) ;
V_219 [ 1 ] = V_585 ;
V_544 [ 1 ] = V_228 + 2 ;
V_39 = F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_590 , V_438 ,
0 , 2 , V_219 , V_544 ) ;
F_65 ( V_219 ) ;
return V_39 ;
}
int
F_143 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 )
{
T_5 V_591 = 1 ;
void * V_219 ;
unsigned int V_544 ;
V_219 = & V_591 ;
V_544 = 1 ;
return F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_592 , V_438 ,
0 , 1 , & V_219 , & V_544 ) ;
}
int
F_144 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_1 * V_585 )
{
struct V_593 V_587 ;
void * * V_219 ;
unsigned int V_544 [ 2 ] ;
int V_39 ;
int V_228 = ( 2 * F_89 ( ( V_337 * ) V_585 , V_338 ) ) ;
V_219 = F_61 ( sizeof( void * ) * 2 , V_227 ) ;
if ( ! V_219 )
return - V_89 ;
V_587 . V_588 = 0 ;
V_587 . V_589 = 0 ;
V_587 . V_548 = F_7 ( V_228 ) ;
V_219 [ 0 ] = & V_587 ;
V_544 [ 0 ] = sizeof( struct V_593 ) ;
V_219 [ 1 ] = V_585 ;
V_544 [ 1 ] = V_228 + 2 ;
V_39 = F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_594 , V_438 ,
0 , 2 , V_219 , V_544 ) ;
F_65 ( V_219 ) ;
return V_39 ;
}
int
F_145 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_294 ,
T_7 V_296 , T_3 V_484 , T_10 * V_595 , bool V_596 )
{
struct V_597 V_587 ;
void * V_219 ;
unsigned int V_544 ;
V_587 . V_375 = * V_595 ;
V_219 = & V_587 ;
V_544 = sizeof( struct V_597 ) ;
if ( V_596 )
return F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_484 , V_598 , V_438 ,
0 , 1 , & V_219 , & V_544 ) ;
else
return F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_484 , V_599 , V_438 ,
0 , 1 , & V_219 , & V_544 ) ;
}
int
F_146 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_13 * V_80 )
{
unsigned int V_544 ;
V_544 = sizeof( T_13 ) ;
return F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_600 , V_438 ,
0 , 1 , ( void * * ) & V_80 , & V_544 ) ;
}
int
F_147 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 ,
struct V_601 * V_602 , int V_603 , int V_604 )
{
return F_141 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , 0 , V_442 , V_604 ,
1 , ( void * * ) & V_602 , & V_603 ) ;
}
int
F_148 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_7 V_294 , const T_7 V_296 ,
T_5 V_605 )
{
int V_39 ;
struct V_606 * V_117 = NULL ;
int V_131 = V_607 ;
F_9 ( V_49 , L_75 ) ;
V_39 = F_27 ( V_57 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_608 = V_296 ;
V_117 -> V_609 = V_294 ;
V_117 -> V_380 = V_605 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_39 = F_71 ( V_121 , V_2 -> V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_610 ) ;
F_9 ( V_49 , L_76 , V_39 ) ;
}
return V_39 ;
}
static void
F_149 ( struct V_611 * V_612 ,
struct V_613 * V_614 )
{
V_614 -> V_615 = F_41 ( V_612 -> V_616 ) *
F_41 ( V_612 -> V_617 ) ;
V_614 -> V_618 = F_150 ( V_612 -> V_619 ) ;
V_614 -> V_620 = V_614 -> V_621 =
F_150 ( V_612 -> V_622 ) ;
return;
}
static int
F_151 ( struct V_124 * V_125 , struct V_1 * V_2 , int V_623 ,
int V_624 , T_7 V_294 , T_7 V_296 )
{
int V_39 ;
struct V_427 * V_117 ;
F_9 ( V_49 , L_77 , V_623 ) ;
if ( ( V_2 -> V_3 == NULL ) || ( V_2 -> V_3 -> V_9 == NULL ) )
return - V_52 ;
V_39 = F_27 ( V_78 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_429 = V_625 ;
V_117 -> V_430 = V_623 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_117 -> V_432 =
F_3 ( sizeof( struct V_427 ) - 1 - 4 ) ;
V_117 -> V_433 = F_7 (
V_624 + sizeof( struct V_428 ) - 1 - 4 ) ;
V_125 -> V_151 = ( char * ) V_117 ;
V_125 -> V_152 = F_37 ( V_117 ) + 4 ;
return 0 ;
}
int
F_152 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , struct V_613 * V_626 )
{
struct V_428 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_611 * V_587 = NULL ;
int V_131 = 0 ;
V_39 = F_151 ( & V_125 , V_2 , V_627 ,
sizeof( struct V_611 ) ,
V_294 , V_296 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_39 = F_38 ( V_121 , V_3 , & V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_125 . V_151 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_434 ) ;
goto V_628;
}
V_123 = (struct V_428 * ) V_126 . V_151 ;
V_587 = (struct V_611 * ) ( 4 +
F_22 ( V_123 -> V_436 ) + ( char * ) & V_123 -> V_97 ) ;
V_39 = F_95 ( F_22 ( V_123 -> V_436 ) ,
F_41 ( V_123 -> V_433 ) , & V_123 -> V_97 ,
sizeof( struct V_611 ) ) ;
if ( ! V_39 )
F_149 ( V_587 , V_626 ) ;
V_628:
F_45 ( V_127 , V_126 . V_151 ) ;
return V_39 ;
}
int
F_153 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , int V_623 )
{
struct V_428 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 , V_629 , V_425 ;
struct V_42 * V_3 = V_2 -> V_3 ;
unsigned int V_630 , V_412 ;
int V_131 = 0 ;
if ( V_623 == V_631 ) {
V_629 = sizeof( V_632 ) ;
V_425 = sizeof( V_632 ) ;
} else if ( V_623 == V_633 ) {
V_629 = sizeof( V_634 ) ;
V_425 = V_635 ;
} else if ( V_623 == V_636 ) {
V_629 = sizeof( struct V_637 ) ;
V_425 = sizeof( struct V_637 ) ;
} else {
F_9 ( V_49 , L_78 , V_623 ) ;
return - V_246 ;
}
V_39 = F_151 ( & V_125 , V_2 , V_623 , V_629 ,
V_294 , V_296 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_39 = F_38 ( V_121 , V_3 , & V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_125 . V_151 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_434 ) ;
goto V_638;
}
V_123 = (struct V_428 * ) V_126 . V_151 ;
V_630 = F_41 ( V_123 -> V_433 ) ;
V_412 = F_22 ( V_123 -> V_436 ) ;
V_39 = F_95 ( V_412 , V_630 , & V_123 -> V_97 , V_425 ) ;
if ( V_39 )
goto V_638;
if ( V_623 == V_633 )
memcpy ( & V_2 -> V_639 , 4 + V_412
+ ( char * ) & V_123 -> V_97 , F_5 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_623 == V_631 )
memcpy ( & V_2 -> V_640 , 4 + V_412
+ ( char * ) & V_123 -> V_97 , sizeof( V_632 ) ) ;
else if ( V_623 == V_636 ) {
struct V_637 * V_641 = (struct V_637 * )
( 4 + V_412 + ( char * ) & V_123 -> V_97 ) ;
V_2 -> V_642 = F_41 ( V_641 -> V_36 ) ;
V_2 -> V_643 =
F_41 ( V_641 -> V_644 ) ;
}
V_638:
F_45 ( V_127 , V_126 . V_151 ) ;
return V_39 ;
}
int
F_154 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_14 V_645 , const T_14 V_296 , const T_6 V_484 ,
const T_6 V_646 , struct V_647 * V_80 )
{
int V_39 = 0 ;
struct V_648 * V_117 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_649 ;
unsigned int V_650 ;
int V_131 = V_651 ;
F_9 ( V_49 , L_79 , V_646 ) ;
V_39 = F_27 ( V_74 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_484 ) ;
V_117 -> V_652 = F_3 ( V_646 ) ;
V_117 -> V_293 = V_645 ;
V_117 -> V_295 = V_296 ;
V_650 = V_646 * sizeof( struct V_647 ) ;
F_34 ( V_117 , V_650 - sizeof( struct V_647 ) ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - V_650 ;
V_125 [ 1 ] . V_151 = ( char * ) V_80 ;
V_125 [ 1 ] . V_152 = V_650 ;
F_26 ( & V_2 -> V_91 . V_653 . V_654 ) ;
V_39 = F_38 ( V_121 , V_2 -> V_3 , V_125 , 2 , & V_649 , V_131 ,
& V_126 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_9 ( V_49 , L_80 , V_39 ) ;
F_72 ( V_2 , V_655 ) ;
}
return V_39 ;
}
int
F_155 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_14 V_645 , const T_14 V_296 , const T_6 V_484 ,
const T_14 V_489 , const T_14 V_412 , const T_6 V_656 ,
const bool V_657 )
{
struct V_647 V_658 ;
V_658 . V_490 = F_119 ( V_412 ) ;
V_658 . V_488 = F_119 ( V_489 ) ;
V_658 . V_36 = F_7 ( V_656 ) ;
if ( ! V_657 && V_656 != V_659 )
V_658 . V_36 |= F_7 ( V_660 ) ;
return F_154 ( V_121 , V_2 , V_645 , V_296 , V_484 , 1 , & V_658 ) ;
}
int
F_156 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_5 * V_661 , const T_15 V_662 )
{
int V_39 ;
struct V_663 * V_117 = NULL ;
int V_131 = V_607 ;
F_9 ( V_49 , L_81 ) ;
V_39 = F_27 ( V_57 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_117 -> V_17 = F_3 ( 36 ) ;
F_34 ( V_117 , 12 ) ;
memcpy ( V_117 -> V_664 , V_661 , 16 ) ;
V_117 -> V_665 = V_662 ;
V_39 = F_71 ( V_121 , V_2 -> V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_610 ) ;
F_9 ( V_49 , L_82 , V_39 ) ;
}
return V_39 ;
}
