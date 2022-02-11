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
if ( V_39 != 0 )
goto V_153;
F_9 ( V_49 , L_6 , V_123 -> V_139 ) ;
if ( V_123 -> V_154 == F_3 ( V_146 ) )
F_9 ( V_49 , L_7 ) ;
else if ( V_123 -> V_154 == F_3 ( V_155 ) )
F_9 ( V_49 , L_8 ) ;
else if ( V_123 -> V_154 == F_3 ( V_156 ) )
F_9 ( V_49 , L_9 ) ;
else if ( V_123 -> V_154 == F_3 ( V_157 ) )
F_9 ( V_49 , L_10 ) ;
#ifdef F_40
else if ( V_123 -> V_154 == F_3 ( V_150 ) )
F_9 ( V_49 , L_11 ) ;
#endif
else {
F_9 ( V_158 , L_12 ,
F_22 ( V_123 -> V_154 ) ) ;
V_39 = - V_52 ;
goto V_153;
}
V_9 -> V_159 = F_22 ( V_123 -> V_154 ) ;
V_9 -> V_160 = V_161 ;
V_9 -> V_162 = F_5 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_9 -> V_163 = F_41 ( V_123 -> V_164 ) ;
V_9 -> V_165 = F_41 ( V_123 -> V_166 ) ;
V_9 -> V_167 = F_22 ( V_123 -> V_139 ) ;
V_9 -> V_10 = F_41 ( V_123 -> V_144 ) ;
V_9 -> V_10 |= V_168 | V_169 ;
V_130 = F_42 ( & V_128 , & V_129 ,
& V_123 -> V_97 ) ;
if ( V_129 == 0 ) {
F_9 ( V_49 , L_13 ) ;
V_9 -> V_170 = true ;
}
V_39 = F_43 ( V_9 , V_3 -> V_35 ) ;
if ( V_39 )
goto V_153;
if ( V_129 ) {
V_39 = F_44 ( V_130 , V_129 , V_9 ) ;
if ( V_39 == 1 )
V_39 = 0 ;
else if ( V_39 == 0 )
V_39 = - V_52 ;
}
V_153:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int F_46 ( const unsigned int V_121 , struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_171 V_172 ;
struct V_173 * V_174 ;
T_3 V_175 ;
F_9 ( V_49 , L_14 ) ;
if ( V_2 -> V_3 -> V_9 -> V_35 == false )
return 0 ;
V_172 . V_144 =
F_7 ( V_2 -> V_3 -> V_9 -> V_136 -> V_145 ) ;
memcpy ( V_172 . V_176 , V_2 -> V_3 -> V_9 -> V_149 ,
V_148 ) ;
if ( V_2 -> V_3 -> V_35 )
V_172 . V_139 =
F_3 ( V_140 ) ;
else if ( V_141 & V_142 )
V_172 . V_139 =
F_3 ( V_143 ) ;
else
V_172 . V_139 = 0 ;
V_172 . V_138 = F_3 ( 1 ) ;
V_172 . V_135 [ 0 ] =
F_3 ( V_2 -> V_3 -> V_9 -> V_136 -> V_137 ) ;
V_39 = F_47 ( V_121 , V_2 , V_177 , V_177 ,
V_178 , true ,
false ,
( char * ) & V_172 , sizeof( struct V_171 ) ,
( char * * ) & V_174 , & V_175 ) ;
if ( V_39 != 0 ) {
F_9 ( V_158 , L_15 , V_39 ) ;
return - V_52 ;
}
if ( V_175 != sizeof( struct V_173 ) ) {
F_9 ( V_158 , L_16 ,
V_175 ) ;
if ( V_175 > V_179 )
return - V_52 ;
}
if ( V_174 -> V_180 !=
F_3 ( V_2 -> V_3 -> V_9 -> V_136 -> V_137 ) )
goto V_181;
if ( V_174 -> V_139 != F_3 ( V_2 -> V_3 -> V_9 -> V_167 ) )
goto V_181;
if ( ( F_41 ( V_174 -> V_144 ) | V_168 |
V_169 ) != V_2 -> V_3 -> V_9 -> V_10 )
goto V_181;
F_9 ( V_49 , L_17 ) ;
return 0 ;
V_181:
F_9 ( V_158 , L_18 ) ;
return - V_52 ;
}
enum V_182
F_48 ( struct V_19 * V_9 , enum V_182 V_183 )
{
switch ( V_183 ) {
case V_184 :
case V_185 :
return V_183 ;
case V_186 :
return V_185 ;
case V_187 :
if ( V_9 -> V_170 &&
( V_141 & V_188 ) )
return V_185 ;
if ( ( V_9 -> V_189 || V_9 -> V_190 ) &&
( V_141 & V_191 ) )
return V_184 ;
default:
return V_187 ;
}
}
static int
F_49 ( struct V_192 * V_193 )
{
int V_39 ;
struct V_42 * V_3 = V_193 -> V_3 ;
struct V_194 * V_117 ;
struct V_19 * V_9 = V_3 -> V_9 ;
V_39 = F_27 ( V_195 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_33 = 0 ;
V_117 -> V_196 = V_193 -> V_197 ;
V_117 -> V_36 = 0 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 3 ) ;
if ( V_9 -> V_35 )
V_117 -> V_139 = V_140 ;
else if ( V_141 & V_142 )
V_117 -> V_139 = V_143 ;
else
V_117 -> V_139 = 0 ;
V_117 -> V_144 = 0 ;
V_117 -> V_198 = 0 ;
V_193 -> V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_193 -> V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
V_193 -> V_199 = V_200 ;
return 0 ;
}
static void
F_50 ( struct V_192 * V_193 )
{
F_45 ( V_193 -> V_199 , V_193 -> V_125 [ 0 ] . V_151 ) ;
V_193 -> V_199 = V_201 ;
}
static int
F_51 ( struct V_192 * V_193 )
{
int V_39 ;
struct V_194 * V_117 = V_193 -> V_125 [ 0 ] . V_151 ;
struct V_124 V_126 = { NULL , 0 } ;
V_117 -> V_202 =
F_3 ( sizeof( struct V_194 ) -
1 - 4 ) ;
V_117 -> V_203 = F_3 ( V_193 -> V_125 [ 1 ] . V_152 ) ;
F_34 ( V_117 , V_193 -> V_125 [ 1 ] . V_152 - 1 ) ;
V_39 = F_38 ( V_193 -> V_121 , V_193 -> V_3 ,
V_193 -> V_125 , 2 ,
& V_193 -> V_199 ,
V_204 | V_132 , & V_126 ) ;
F_39 ( V_193 -> V_125 [ 0 ] . V_151 ) ;
memcpy ( & V_193 -> V_125 [ 0 ] , & V_126 , sizeof( struct V_124 ) ) ;
return V_39 ;
}
static int
F_52 ( struct V_192 * V_193 )
{
int V_39 = 0 ;
struct V_42 * V_3 = V_193 -> V_3 ;
F_12 ( & V_3 -> V_9 -> V_205 ) ;
if ( V_3 -> V_9 -> V_206 -> V_207 ) {
V_39 = V_3 -> V_9 -> V_206 -> V_207 ( V_3 ) ;
if ( V_39 ) {
F_9 ( V_49 ,
L_19 ) ;
F_15 ( & V_3 -> V_9 -> V_205 ) ;
return V_39 ;
}
}
if ( ! V_3 -> V_9 -> V_208 ) {
V_3 -> V_9 -> V_209 = 0x2 ;
V_3 -> V_9 -> V_208 = true ;
}
F_15 ( & V_3 -> V_9 -> V_205 ) ;
F_9 ( V_49 , L_20 ) ;
F_4 ( & V_210 ) ;
V_3 -> V_51 = V_211 ;
V_3 -> V_63 = false ;
F_6 ( & V_210 ) ;
return V_39 ;
}
static void
F_53 ( struct V_192 * V_193 )
{
int V_39 ;
struct V_42 * V_3 = V_193 -> V_3 ;
struct V_212 * V_213 ;
struct V_214 * V_215 = NULL ;
struct V_216 * V_123 = NULL ;
V_39 = F_49 ( V_193 ) ;
if ( V_39 )
goto V_28;
V_215 = F_54 ( V_3 ) ;
if ( F_55 ( V_215 ) ) {
V_39 = F_56 ( V_215 ) ;
V_215 = NULL ;
goto V_28;
}
V_213 = V_215 -> V_217 . V_218 [ 0 ] ;
if ( V_213 -> V_219 != V_220 ) {
F_9 ( V_158 ,
L_21 ,
V_220 , V_213 -> V_219 ) ;
V_39 = - V_221 ;
goto V_222;
}
V_3 -> V_223 . V_224 = F_57 ( V_213 -> V_218 , V_213 -> V_225 ,
V_226 ) ;
if ( ! V_3 -> V_223 . V_224 ) {
F_9 ( V_158 ,
L_22 ,
V_213 -> V_225 ) ;
V_39 = - V_89 ;
goto V_222;
}
V_3 -> V_223 . V_227 = V_213 -> V_225 ;
V_193 -> V_125 [ 1 ] . V_151 = V_213 -> V_218 + V_213 -> V_225 ;
V_193 -> V_125 [ 1 ] . V_152 = V_213 -> V_228 ;
V_39 = F_51 ( V_193 ) ;
if ( V_39 )
goto V_222;
V_123 = (struct V_216 * ) V_193 -> V_125 [ 0 ] . V_151 ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_229 ) ;
V_39 = F_52 ( V_193 ) ;
V_222:
F_58 ( V_215 ) ;
F_59 ( V_215 ) ;
V_28:
V_193 -> V_230 = V_39 ;
V_193 -> V_231 = NULL ;
F_50 ( V_193 ) ;
}
static void
F_53 ( struct V_192 * V_193 )
{
F_9 ( V_158 , L_23 ) ;
V_193 -> V_230 = - V_232 ;
V_193 -> V_231 = NULL ;
}
static void
F_60 ( struct V_192 * V_193 )
{
int V_39 ;
struct V_42 * V_3 = V_193 -> V_3 ;
struct V_216 * V_123 = NULL ;
char * V_233 = NULL ;
bool V_234 = false ;
T_4 V_129 = 0 ;
V_3 -> V_235 = F_61 ( sizeof( struct V_236 ) , V_226 ) ;
if ( ! V_3 -> V_235 ) {
V_39 = - V_89 ;
goto V_237;
}
V_3 -> V_235 -> V_238 = true ;
V_39 = F_49 ( V_193 ) ;
if ( V_39 )
goto V_237;
V_233 = F_61 ( sizeof( struct V_239 ) ,
V_226 ) ;
if ( V_233 == NULL ) {
V_39 = - V_89 ;
goto V_28;
}
F_62 ( V_233 , V_3 ) ;
if ( V_234 ) {
F_9 ( V_158 , L_24 ) ;
V_39 = - V_232 ;
goto V_28;
} else {
V_129 = sizeof( struct V_239 ) ;
}
V_193 -> V_125 [ 1 ] . V_151 = V_233 ;
V_193 -> V_125 [ 1 ] . V_152 = V_129 ;
V_39 = F_51 ( V_193 ) ;
V_123 = (struct V_216 * ) V_193 -> V_125 [ 0 ] . V_151 ;
if ( V_193 -> V_199 != V_201 &&
V_123 -> V_97 . V_86 . V_240 == V_241 )
V_39 = 0 ;
if ( V_39 )
goto V_28;
if ( F_63 ( struct V_216 , V_242 ) - 4 !=
F_22 ( V_123 -> V_202 ) ) {
F_9 ( V_158 , L_25 ,
F_22 ( V_123 -> V_202 ) ) ;
V_39 = - V_52 ;
goto V_28;
}
V_39 = F_64 ( V_123 -> V_242 ,
F_22 ( V_123 -> V_203 ) , V_3 ) ;
if ( V_39 )
goto V_28;
F_9 ( V_49 , L_26 ) ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_229 ) ;
V_28:
F_65 ( V_233 ) ;
F_50 ( V_193 ) ;
if ( ! V_39 ) {
V_193 -> V_230 = 0 ;
V_193 -> V_231 = V_243 ;
return;
}
V_237:
F_65 ( V_3 -> V_235 ) ;
V_3 -> V_235 = NULL ;
V_193 -> V_230 = V_39 ;
V_193 -> V_231 = NULL ;
}
static void
V_243 ( struct V_192 * V_193 )
{
int V_39 ;
struct V_42 * V_3 = V_193 -> V_3 ;
struct V_194 * V_117 ;
struct V_216 * V_123 = NULL ;
unsigned char * V_233 = NULL ;
bool V_234 = false ;
T_4 V_129 = 0 ;
V_39 = F_49 ( V_193 ) ;
if ( V_39 )
goto V_28;
V_117 = (struct V_194 * ) V_193 -> V_125 [ 0 ] . V_151 ;
V_117 -> V_97 . V_86 . V_33 = V_3 -> V_34 ;
V_39 = F_66 ( & V_233 , & V_129 , V_3 ,
V_193 -> V_244 ) ;
if ( V_39 ) {
F_9 ( V_49 , L_27 , V_39 ) ;
goto V_28;
}
if ( V_234 ) {
F_9 ( V_158 , L_24 ) ;
V_39 = - V_232 ;
goto V_28;
}
V_193 -> V_125 [ 1 ] . V_151 = V_233 ;
V_193 -> V_125 [ 1 ] . V_152 = V_129 ;
V_39 = F_51 ( V_193 ) ;
if ( V_39 )
goto V_28;
V_123 = (struct V_216 * ) V_193 -> V_125 [ 0 ] . V_151 ;
V_3 -> V_34 = V_123 -> V_97 . V_86 . V_33 ;
V_3 -> V_4 = F_22 ( V_123 -> V_229 ) ;
V_39 = F_52 ( V_193 ) ;
V_28:
F_65 ( V_233 ) ;
F_50 ( V_193 ) ;
F_65 ( V_3 -> V_235 ) ;
V_3 -> V_235 = NULL ;
V_193 -> V_230 = V_39 ;
V_193 -> V_231 = NULL ;
}
static int
F_67 ( struct V_42 * V_3 , struct V_192 * V_193 )
{
int type ;
type = F_48 ( V_3 -> V_9 , V_3 -> V_245 ) ;
F_9 ( V_49 , L_28 , type ) ;
if ( type == V_187 ) {
F_9 ( V_158 ,
L_29 ) ;
return - V_246 ;
}
switch ( type ) {
case V_184 :
V_193 -> V_231 = F_53 ;
break;
case V_185 :
V_193 -> V_231 = F_60 ;
break;
default:
F_9 ( V_158 , L_30 , type ) ;
return - V_232 ;
}
return 0 ;
}
int
F_68 ( const unsigned int V_121 , struct V_42 * V_3 ,
const struct V_40 * V_244 )
{
int V_39 = 0 ;
struct V_19 * V_9 = V_3 -> V_9 ;
struct V_192 * V_193 ;
F_9 ( V_49 , L_31 ) ;
if ( ! V_9 ) {
F_36 ( 1 , L_5 , V_133 ) ;
return - V_52 ;
}
V_193 = F_69 ( sizeof( struct V_192 ) , V_226 ) ;
if ( ! V_193 )
return - V_89 ;
V_39 = F_67 ( V_3 , V_193 ) ;
if ( V_39 )
goto V_28;
V_193 -> V_121 = V_121 ;
V_193 -> V_3 = V_3 ;
V_193 -> V_199 = V_201 ;
V_193 -> V_244 = (struct V_40 * ) V_244 ;
while ( V_193 -> V_231 )
V_193 -> V_231 ( V_193 ) ;
V_39 = V_193 -> V_230 ;
V_28:
F_65 ( V_193 ) ;
return V_39 ;
}
int
F_70 ( const unsigned int V_121 , struct V_42 * V_3 )
{
struct V_247 * V_117 ;
int V_39 = 0 ;
struct V_19 * V_9 ;
int V_131 = 0 ;
F_9 ( V_49 , L_32 , V_3 ) ;
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
struct V_19 * V_9 ;
T_1 * V_261 = NULL ;
int V_131 = 0 ;
F_9 ( V_49 , L_33 ) ;
if ( ( V_3 -> V_9 ) && V_256 )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_261 = F_61 ( V_262 * 2 , V_226 ) ;
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
F_9 ( V_49 , L_34 ) ;
break;
case V_271 :
V_2 -> V_272 = true ;
F_9 ( V_49 , L_35 ) ;
break;
case V_273 :
V_2 -> V_272 = true ;
F_9 ( V_49 , L_36 ) ;
break;
default:
F_9 ( V_158 , L_37 , V_123 -> V_269 ) ;
V_39 = - V_232 ;
goto V_266;
}
V_2 -> V_6 = F_41 ( V_123 -> V_274 ) ;
V_2 -> V_10 = V_123 -> V_144 ;
V_2 -> V_275 = F_41 ( V_123 -> V_276 ) ;
V_2 -> V_44 = V_211 ;
V_2 -> V_63 = false ;
V_2 -> V_32 = V_123 -> V_97 . V_86 . V_31 ;
F_75 ( V_2 -> V_67 , V_256 , sizeof( V_2 -> V_67 ) ) ;
if ( ( V_123 -> V_144 & V_277 ) &&
( ( V_2 -> V_6 & V_278 ) == 0 ) )
F_9 ( V_158 , L_38 ) ;
if ( V_2 -> V_8 &&
! ( V_2 -> V_3 -> V_9 -> V_10 & V_11 ) )
F_9 ( V_158 , L_39 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_3 -> V_9 -> V_206 -> V_279 )
V_39 = V_2 -> V_3 -> V_9 -> V_206 -> V_279 ( V_121 , V_2 ) ;
V_268:
F_45 ( V_127 , V_123 ) ;
F_65 ( V_261 ) ;
return V_39 ;
V_266:
if ( V_123 -> V_97 . V_86 . V_240 == V_280 ) {
F_9 ( V_158 , L_40 , V_256 ) ;
}
goto V_268;
}
int
F_76 ( const unsigned int V_121 , struct V_1 * V_2 )
{
struct V_281 * V_117 ;
int V_39 = 0 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
F_9 ( V_49 , L_41 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
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
V_80 = F_69 ( sizeof( struct V_283 ) , V_226 ) ;
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
V_80 = F_69 ( sizeof( struct V_283 ) , V_226 ) ;
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
strncmp ( V_304 , L_42 , 4 ) == 0 )
return V_9 -> V_206 -> V_307 ( V_301 , V_298 ) ;
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
V_125 [ V_312 ] . V_151 = V_9 -> V_206 -> V_313 ( V_310 + 1 , * V_310 ) ;
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
V_80 = F_69 ( sizeof( struct V_317 ) , V_226 ) ;
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
V_226 ) ;
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
* V_329 = F_69 ( * V_330 , V_226 ) ;
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
F_9 ( V_49 , L_43 ) ;
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
V_343 = F_69 ( V_344 , V_226 ) ;
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
V_226 ) ;
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
struct V_19 * V_9 ;
struct V_42 * V_3 ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_345 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_44 ) ;
if ( V_386 != NULL )
* V_386 = NULL ;
if ( V_387 )
* V_387 = 0 ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
else
return - V_52 ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_39 = F_27 ( V_75 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( V_383 ) {
if ( V_3 -> V_267 == 0 ) {
F_39 ( V_117 ) ;
return - V_390 ;
}
F_9 ( V_49 , L_45 ,
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
V_117 -> V_396 = F_7 ( V_179 ) ;
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
F_9 ( V_158 , L_46 , * V_387 ) ;
* V_387 = 0 ;
V_39 = - V_52 ;
goto V_399;
}
if ( F_37 ( V_123 ) < F_41 ( V_123 -> V_394 ) + * V_387 ) {
F_9 ( V_158 , L_47 , * V_387 ,
F_41 ( V_123 -> V_394 ) ) ;
* V_387 = 0 ;
V_39 = - V_52 ;
goto V_399;
}
* V_386 = F_61 ( * V_387 , V_226 ) ;
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
F_9 ( V_49 , L_48 , V_39 ) ;
return V_39 ;
}
int
F_94 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 )
{
struct V_408 * V_117 ;
struct V_409 * V_123 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_49 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
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
F_9 ( V_158 , L_50 ,
V_413 , V_415 ) ;
return - V_246 ;
}
if ( ( V_416 > 0x7FFFFF ) || ( V_413 > 0x7FFFFF ) ) {
F_9 ( V_158 , L_51 ,
V_413 , V_416 ) ;
return - V_246 ;
}
if ( ( V_418 > V_417 ) || ( V_419 > V_417 ) ) {
F_9 ( V_158 , L_52 ) ;
return - V_246 ;
}
return 0 ;
}
static int
F_97 ( unsigned int V_412 , unsigned int V_413 ,
struct V_414 * V_97 , unsigned int V_420 ,
char * V_218 )
{
char * V_418 = 4 + V_412 + ( char * ) V_97 ;
int V_39 ;
if ( ! V_218 )
return - V_246 ;
V_39 = F_95 ( V_412 , V_413 , V_97 , V_420 ) ;
if ( V_39 )
return V_39 ;
memcpy ( V_218 , V_418 , V_413 ) ;
return 0 ;
}
static int
F_98 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_8 V_421 ,
T_9 V_422 , T_9 V_423 , void * V_218 )
{
struct V_424 * V_117 ;
struct V_425 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
F_9 ( V_49 , L_53 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
V_39 = F_27 ( V_78 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_426 = V_427 ;
V_117 -> V_428 = V_421 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_117 -> V_429 =
F_3 ( sizeof( struct V_424 ) - 1 - 4 ) ;
V_117 -> V_430 = F_7 ( V_422 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_425 * ) V_126 . V_151 ;
if ( V_39 ) {
F_72 ( V_2 , V_431 ) ;
goto V_432;
}
V_39 = F_97 ( F_22 ( V_123 -> V_433 ) ,
F_41 ( V_123 -> V_430 ) ,
& V_123 -> V_97 , V_423 , V_218 ) ;
V_432:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
int
F_99 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 ,
struct V_339 * V_218 )
{
return F_98 ( V_121 , V_2 , V_294 , V_296 ,
V_434 ,
sizeof( struct V_339 ) + V_338 * 2 ,
sizeof( struct V_339 ) , V_218 ) ;
}
int
F_100 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_10 * V_435 )
{
return F_98 ( V_121 , V_2 , V_294 , V_296 ,
V_436 ,
sizeof( struct V_437 ) ,
sizeof( struct V_437 ) , V_435 ) ;
}
static void
F_101 ( struct V_438 * V_439 )
{
struct V_19 * V_9 = V_439 -> V_440 ;
struct V_441 * V_123 = (struct V_441 * ) V_439 -> V_442 ;
unsigned int V_443 = 1 ;
if ( V_439 -> V_444 == V_445 )
V_443 = F_22 ( V_123 -> V_97 . V_86 . V_23 ) ;
F_102 ( V_439 ) ;
F_103 ( V_9 , V_443 , V_446 ) ;
}
void F_104 ( struct V_447 * V_448 )
{
struct V_19 * V_9 = F_105 ( V_448 ,
struct V_19 , V_70 . V_448 ) ;
struct V_42 * V_3 ;
struct V_1 * V_2 , * V_449 ;
struct V_450 V_451 ;
int V_452 = false ;
int V_39 ;
int V_453 = false ;
F_12 ( & V_9 -> V_454 ) ;
F_106 ( & V_451 ) ;
F_9 ( V_49 , L_54 ) ;
F_4 ( & V_455 ) ;
F_107 (ses, &server->smb_ses_list, smb_ses_list) {
F_107 (tcon, &ses->tcon_list, tcon_list) {
if ( V_2 -> V_63 || V_2 -> V_66 ) {
V_2 -> V_456 ++ ;
F_108 ( & V_2 -> V_457 , & V_451 ) ;
V_452 = true ;
}
}
}
if ( V_452 )
V_9 -> V_458 ++ ;
F_6 ( & V_455 ) ;
F_109 (tcon, tcon2, &tmp_list, rlist) {
V_39 = F_8 ( V_68 , V_2 ) ;
if ( ! V_39 )
F_110 ( V_2 ) ;
else
V_453 = true ;
F_111 ( & V_2 -> V_457 ) ;
F_112 ( V_2 ) ;
}
F_9 ( V_49 , L_55 ) ;
if ( V_453 )
F_18 ( V_69 , & V_9 -> V_70 , 2 * V_60 ) ;
F_15 ( & V_9 -> V_454 ) ;
if ( V_452 )
F_113 ( V_9 , 1 ) ;
}
int
F_114 ( struct V_19 * V_9 )
{
struct V_459 * V_117 ;
int V_39 = 0 ;
struct V_124 V_125 [ 2 ] ;
struct V_460 V_461 = { . V_462 = V_125 ,
. V_463 = 2 } ;
F_9 ( V_49 , L_56 ) ;
if ( V_9 -> V_53 == V_464 ) {
F_18 ( V_69 , & V_9 -> V_70 , 0 ) ;
return V_39 ;
}
V_39 = F_27 ( V_465 , NULL , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_125 [ 0 ] . V_152 = 4 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 1 ] . V_152 = F_37 ( V_117 ) ;
V_125 [ 1 ] . V_151 = ( char * ) V_117 + 4 ;
V_39 = F_115 ( V_9 , & V_461 , NULL , F_101 , NULL ,
V_9 , V_446 ) ;
if ( V_39 )
F_9 ( V_49 , L_57 , V_39 ) ;
F_39 ( V_117 ) ;
return V_39 ;
}
int
F_116 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_294 ,
T_7 V_296 )
{
struct V_466 * V_117 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_124 V_125 [ 1 ] ;
struct V_124 V_126 ;
int V_127 ;
int V_39 = 0 ;
int V_131 = 0 ;
F_9 ( V_49 , L_58 ) ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
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
F_72 ( V_2 , V_467 ) ;
F_45 ( V_127 , V_126 . V_151 ) ;
return V_39 ;
}
static int
F_117 ( void * * V_80 , unsigned int * V_81 ,
struct V_468 * V_469 , unsigned int V_470 ,
int V_471 )
{
int V_39 = - V_472 ;
struct V_473 * V_117 = NULL ;
struct V_12 * V_13 ;
V_39 = F_23 ( V_73 , V_469 -> V_2 , ( void * * ) & V_117 ,
V_81 ) ;
if ( V_39 )
return V_39 ;
if ( V_469 -> V_2 -> V_3 -> V_9 == NULL )
return - V_474 ;
V_13 = & V_117 -> V_86 ;
V_13 -> V_24 = F_7 ( V_469 -> V_475 ) ;
V_117 -> V_293 = V_469 -> V_294 ;
V_117 -> V_295 = V_469 -> V_296 ;
V_117 -> V_476 = 0 ;
V_117 -> V_477 = 0 ;
V_117 -> V_198 = 0 ;
V_117 -> V_478 = 0 ;
V_117 -> V_479 = F_7 ( V_469 -> V_480 ) ;
V_117 -> V_481 = F_118 ( V_469 -> V_412 ) ;
if ( V_471 & V_482 ) {
if ( ! ( V_471 & V_483 ) ) {
* V_81 = F_119 ( * V_81 , 8 ) * 8 ;
V_13 -> V_484 = F_7 ( * V_81 ) ;
} else
V_13 -> V_484 = 0 ;
if ( V_471 & V_485 ) {
V_13 -> V_36 |= V_486 ;
V_13 -> V_33 = 0xFFFFFFFF ;
V_13 -> V_31 = 0xFFFFFFFF ;
V_117 -> V_293 = 0xFFFFFFFF ;
V_117 -> V_295 = 0xFFFFFFFF ;
}
}
if ( V_470 > V_469 -> V_480 )
V_117 -> V_487 = F_7 ( V_470 ) ;
else
V_117 -> V_487 = 0 ;
* V_80 = V_117 ;
return V_39 ;
}
static void
F_120 ( struct V_438 * V_439 )
{
struct V_488 * V_489 = V_439 -> V_440 ;
struct V_1 * V_2 = F_121 ( V_489 -> V_490 -> V_491 ) ;
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
struct V_12 * V_13 =
(struct V_12 * ) V_489 -> V_125 [ 1 ] . V_151 ;
unsigned int V_443 = 1 ;
struct V_460 V_461 = { . V_462 = V_489 -> V_125 ,
. V_463 = 2 ,
. V_492 = V_489 -> V_493 ,
. V_494 = V_489 -> V_495 ,
. V_496 = V_489 -> V_497 ,
. V_498 = V_489 -> V_499 } ;
F_9 ( V_49 , L_59 ,
V_133 , V_439 -> V_439 , V_439 -> V_444 , V_489 -> V_230 ,
V_489 -> V_500 ) ;
switch ( V_439 -> V_444 ) {
case V_445 :
V_443 = F_22 ( V_13 -> V_23 ) ;
if ( V_9 -> V_35 && ! V_439 -> V_501 ) {
int V_39 ;
V_39 = F_122 ( & V_461 , V_9 ) ;
if ( V_39 )
F_9 ( V_158 , L_60 ,
V_39 ) ;
}
F_123 ( V_489 -> V_502 ) ;
F_124 ( V_2 , V_489 -> V_502 ) ;
break;
case V_503 :
case V_504 :
V_489 -> V_230 = - V_58 ;
if ( V_9 -> V_35 && V_489 -> V_502 )
V_489 -> V_502 = 0 ;
F_123 ( V_489 -> V_502 ) ;
F_124 ( V_2 , V_489 -> V_502 ) ;
break;
default:
if ( V_489 -> V_230 != - V_505 )
V_489 -> V_230 = - V_52 ;
}
if ( V_489 -> V_230 )
F_72 ( V_2 , V_506 ) ;
F_125 ( V_69 , & V_489 -> V_448 ) ;
F_102 ( V_439 ) ;
F_103 ( V_9 , V_443 , 0 ) ;
}
int
F_126 ( struct V_488 * V_489 )
{
int V_39 , V_131 = 0 ;
char * V_80 ;
struct V_12 * V_13 ;
struct V_468 V_469 ;
struct V_460 V_461 = { . V_462 = V_489 -> V_125 ,
. V_463 = 2 } ;
struct V_19 * V_9 ;
unsigned int V_81 ;
T_11 V_507 ;
F_9 ( V_49 , L_61 ,
V_133 , V_489 -> V_412 , V_489 -> V_500 ) ;
V_469 . V_2 = F_121 ( V_489 -> V_490 -> V_491 ) ;
V_469 . V_412 = V_489 -> V_412 ;
V_469 . V_480 = V_489 -> V_500 ;
V_469 . V_294 = V_489 -> V_490 -> V_291 . V_294 ;
V_469 . V_296 = V_489 -> V_490 -> V_291 . V_296 ;
V_469 . V_475 = V_489 -> V_475 ;
V_9 = V_469 . V_2 -> V_3 -> V_9 ;
V_39 = F_117 ( ( void * * ) & V_80 , & V_81 , & V_469 , 0 , 0 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_489 -> V_21 ) {
V_489 -> V_21 = 0 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_508 -- ;
F_6 ( & V_9 -> V_20 ) ;
}
return V_39 ;
}
if ( F_1 ( V_469 . V_2 ) )
V_131 |= V_250 ;
V_507 = F_29 ( V_81 ) ;
V_489 -> V_125 [ 0 ] . V_151 = & V_507 ;
V_489 -> V_125 [ 0 ] . V_152 = sizeof( T_11 ) ;
V_489 -> V_125 [ 1 ] . V_151 = V_80 ;
V_489 -> V_125 [ 1 ] . V_152 = V_81 ;
V_13 = (struct V_12 * ) V_80 ;
if ( V_489 -> V_21 ) {
V_13 -> V_30 = F_3 ( F_119 ( V_489 -> V_500 ,
V_509 ) ) ;
V_13 -> V_23 = V_13 -> V_30 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_21 += V_489 -> V_21 -
F_22 ( V_13 -> V_30 ) ;
F_6 ( & V_9 -> V_20 ) ;
F_127 ( & V_9 -> V_510 ) ;
V_131 |= V_511 ;
}
F_128 ( & V_489 -> V_512 ) ;
V_39 = F_115 ( V_469 . V_2 -> V_3 -> V_9 , & V_461 ,
V_513 , F_120 ,
V_514 , V_489 , V_131 ) ;
if ( V_39 ) {
F_129 ( & V_489 -> V_512 , V_515 ) ;
F_72 ( V_469 . V_2 , V_506 ) ;
}
F_39 ( V_80 ) ;
return V_39 ;
}
int
F_130 ( const unsigned int V_121 , struct V_468 * V_469 ,
unsigned int * V_516 , char * * V_80 , int * V_517 )
{
int V_127 , V_39 = - V_472 ;
struct V_473 * V_117 = NULL ;
struct V_518 * V_123 = NULL ;
struct V_12 * V_13 ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
unsigned int V_81 ;
T_11 V_507 ;
struct V_460 V_461 = { . V_462 = V_125 ,
. V_463 = 2 } ;
int V_131 = V_204 ;
struct V_42 * V_3 = V_469 -> V_2 -> V_3 ;
* V_516 = 0 ;
V_39 = F_117 ( ( void * * ) & V_117 , & V_81 , V_469 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_469 -> V_2 ) )
V_131 |= V_250 ;
V_507 = F_29 ( V_81 ) ;
V_125 [ 0 ] . V_151 = & V_507 ;
V_125 [ 0 ] . V_152 = sizeof( T_11 ) ;
V_125 [ 1 ] . V_151 = V_117 ;
V_125 [ 1 ] . V_152 = V_81 ;
V_39 = F_131 ( V_121 , V_3 , & V_461 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_518 * ) V_126 . V_151 ;
V_13 = F_28 ( V_123 ) ;
if ( V_13 -> V_240 == V_519 ) {
F_45 ( V_127 , V_126 . V_151 ) ;
return 0 ;
}
if ( V_39 ) {
F_72 ( V_469 -> V_2 , V_506 ) ;
F_9 ( V_158 , L_62 , V_39 ) ;
} else {
* V_516 = F_41 ( V_123 -> V_103 ) ;
if ( ( * V_516 > V_520 ) ||
( * V_516 > V_469 -> V_480 ) ) {
F_9 ( V_49 , L_63 ,
* V_516 , V_469 -> V_480 ) ;
V_39 = - V_52 ;
* V_516 = 0 ;
}
}
if ( * V_80 ) {
memcpy ( * V_80 , ( char * ) V_13 + V_123 -> V_285 , * V_516 ) ;
F_45 ( V_127 , V_126 . V_151 ) ;
} else if ( V_127 != V_201 ) {
* V_80 = V_126 . V_151 ;
if ( V_127 == V_200 )
* V_517 = V_200 ;
else if ( V_127 == V_521 )
* V_517 = V_521 ;
}
return V_39 ;
}
static void
F_132 ( struct V_438 * V_439 )
{
struct V_522 * V_523 = V_439 -> V_440 ;
struct V_1 * V_2 = F_121 ( V_523 -> V_490 -> V_491 ) ;
unsigned int V_524 ;
struct V_525 * V_123 = (struct V_525 * ) V_439 -> V_442 ;
unsigned int V_443 = 1 ;
switch ( V_439 -> V_444 ) {
case V_445 :
V_443 = F_22 ( V_123 -> V_97 . V_86 . V_23 ) ;
V_523 -> V_230 = F_133 ( V_439 , V_2 -> V_3 -> V_9 , 0 ) ;
if ( V_523 -> V_230 != 0 )
break;
V_524 = F_41 ( V_123 -> V_103 ) ;
if ( V_524 > V_523 -> V_500 )
V_524 &= 0xFFFF ;
if ( V_524 < V_523 -> V_500 )
V_523 -> V_230 = - V_526 ;
else
V_523 -> V_500 = V_524 ;
break;
case V_503 :
case V_504 :
V_523 -> V_230 = - V_58 ;
break;
default:
V_523 -> V_230 = - V_52 ;
break;
}
if ( V_523 -> V_230 )
F_72 ( V_2 , V_527 ) ;
F_125 ( V_69 , & V_523 -> V_448 ) ;
F_102 ( V_439 ) ;
F_103 ( V_2 -> V_3 -> V_9 , V_443 , 0 ) ;
}
int
F_134 ( struct V_522 * V_523 ,
void (* F_135)( struct V_528 * V_528 ) )
{
int V_39 = - V_472 , V_131 = 0 ;
struct V_529 * V_117 = NULL ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_121 ( V_523 -> V_490 -> V_491 ) ;
struct V_19 * V_9 = V_2 -> V_3 -> V_9 ;
struct V_124 V_125 [ 2 ] ;
struct V_460 V_461 = { } ;
V_39 = F_27 ( V_46 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
if ( V_39 == - V_58 && V_523 -> V_21 ) {
V_523 -> V_21 = 0 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_508 -- ;
F_6 ( & V_9 -> V_20 ) ;
}
goto V_530;
}
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_13 = F_28 ( V_117 ) ;
V_13 -> V_24 = F_7 ( V_523 -> V_490 -> V_475 ) ;
V_117 -> V_293 = V_523 -> V_490 -> V_291 . V_294 ;
V_117 -> V_295 = V_523 -> V_490 -> V_291 . V_296 ;
V_117 -> V_531 = 0 ;
V_117 -> V_532 = 0 ;
V_117 -> V_198 = 0 ;
V_117 -> V_481 = F_118 ( V_523 -> V_412 ) ;
V_117 -> V_285 = F_3 (
F_63 ( struct V_529 , V_242 ) - 4 ) ;
V_117 -> V_487 = 0 ;
V_125 [ 0 ] . V_152 = 4 ;
V_125 [ 0 ] . V_151 = V_117 ;
V_125 [ 1 ] . V_152 = F_37 ( V_117 ) - 1 ;
V_125 [ 1 ] . V_151 = ( char * ) V_117 + 4 ;
V_461 . V_462 = V_125 ;
V_461 . V_463 = 2 ;
V_461 . V_492 = V_523 -> V_493 ;
V_461 . V_494 = V_523 -> V_495 ;
V_461 . V_496 = V_523 -> V_497 ;
V_461 . V_498 = V_523 -> V_499 ;
F_9 ( V_49 , L_64 ,
V_523 -> V_412 , V_523 -> V_500 ) ;
V_117 -> V_479 = F_7 ( V_523 -> V_500 ) ;
F_34 ( & V_117 -> V_97 , V_523 -> V_500 - 1 ) ;
if ( V_523 -> V_21 ) {
V_13 -> V_30 = F_3 ( F_119 ( V_523 -> V_500 ,
V_509 ) ) ;
V_13 -> V_23 = V_13 -> V_30 ;
F_4 ( & V_9 -> V_20 ) ;
V_9 -> V_21 += V_523 -> V_21 -
F_22 ( V_13 -> V_30 ) ;
F_6 ( & V_9 -> V_20 ) ;
F_127 ( & V_9 -> V_510 ) ;
V_131 |= V_511 ;
}
F_128 ( & V_523 -> V_512 ) ;
V_39 = F_115 ( V_9 , & V_461 , NULL , F_132 , NULL ,
V_523 , V_131 ) ;
if ( V_39 ) {
F_129 ( & V_523 -> V_512 , F_135 ) ;
F_72 ( V_2 , V_527 ) ;
}
V_530:
F_39 ( V_117 ) ;
return V_39 ;
}
int
F_136 ( const unsigned int V_121 , struct V_468 * V_469 ,
unsigned int * V_516 , struct V_124 * V_125 , int V_533 )
{
int V_39 = 0 ;
struct V_529 * V_117 = NULL ;
struct V_525 * V_123 = NULL ;
int V_127 ;
struct V_124 V_126 ;
int V_131 = 0 ;
* V_516 = 0 ;
if ( V_533 < 1 )
return V_39 ;
V_39 = F_27 ( V_46 , V_469 -> V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( V_469 -> V_2 -> V_3 -> V_9 == NULL )
return - V_474 ;
if ( F_1 ( V_469 -> V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_469 -> V_475 ) ;
V_117 -> V_293 = V_469 -> V_294 ;
V_117 -> V_295 = V_469 -> V_296 ;
V_117 -> V_531 = 0 ;
V_117 -> V_532 = 0 ;
V_117 -> V_198 = 0 ;
V_117 -> V_479 = F_7 ( V_469 -> V_480 ) ;
V_117 -> V_481 = F_118 ( V_469 -> V_412 ) ;
V_117 -> V_285 = F_3 (
F_63 ( struct V_529 , V_242 ) - 4 ) ;
V_117 -> V_487 = 0 ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
F_34 ( V_117 , V_469 -> V_480 - 1 ) ;
V_39 = F_38 ( V_121 , V_469 -> V_2 -> V_3 , V_125 , V_533 + 1 ,
& V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_525 * ) V_126 . V_151 ;
if ( V_39 ) {
F_72 ( V_469 -> V_2 , V_527 ) ;
F_9 ( V_158 , L_65 , V_39 ) ;
} else
* V_516 = F_41 ( V_123 -> V_103 ) ;
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static unsigned int
F_137 ( char * V_534 , char * V_419 , char * * V_535 , T_9 V_536 )
{
int V_227 ;
unsigned int V_537 = 0 ;
unsigned int V_538 = 0 ;
T_12 * V_539 ;
if ( V_534 == NULL )
return 0 ;
V_539 = ( T_12 * ) V_534 ;
while ( 1 ) {
V_539 = ( T_12 * )
( ( char * ) V_539 + V_538 ) ;
if ( ( char * ) V_539 + V_536 > V_419 ) {
F_9 ( V_158 , L_66 ) ;
break;
}
V_227 = F_41 ( V_539 -> V_540 ) ;
if ( ( char * ) V_539 + V_227 + V_536 > V_419 ) {
F_9 ( V_158 , L_67 ,
V_419 ) ;
break;
}
* V_535 = ( char * ) V_539 ;
V_537 ++ ;
V_538 = F_41 ( V_539 -> V_541 ) ;
if ( ! V_538 )
break;
}
return V_537 ;
}
int
F_138 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , int V_542 ,
struct V_543 * V_544 )
{
struct V_545 * V_117 ;
struct V_546 * V_123 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_227 ;
int V_127 = V_201 ;
unsigned char * V_547 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
T_1 V_548 = F_3 ( '*' ) ;
char * V_417 ;
unsigned int V_549 = V_179 ;
T_9 V_550 ;
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
switch ( V_544 -> V_551 ) {
case V_552 :
V_117 -> V_553 = V_554 ;
V_550 = sizeof( T_12 ) - 1 ;
break;
case V_555 :
V_117 -> V_553 = V_556 ;
V_550 = sizeof( V_557 ) - 1 ;
break;
default:
F_9 ( V_158 , L_68 ,
V_544 -> V_551 ) ;
V_39 = - V_246 ;
goto V_558;
}
V_117 -> V_559 = F_7 ( V_542 ) ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_227 = 0x2 ;
V_547 = V_117 -> V_242 ;
memcpy ( V_547 , & V_548 , V_227 ) ;
V_117 -> V_560 =
F_3 ( sizeof( struct V_545 ) - 1 - 4 ) ;
V_117 -> V_540 = F_3 ( V_227 ) ;
V_549 = F_5 (unsigned int, output_size, server->maxBuf) ;
V_549 = F_5 (unsigned int, output_size, 2 << 15 ) ;
V_117 -> V_430 = F_7 ( V_549 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - 1 ;
V_125 [ 1 ] . V_151 = ( char * ) ( V_117 -> V_242 ) ;
V_125 [ 1 ] . V_152 = V_227 ;
F_34 ( V_117 , V_227 - 1 ) ;
V_39 = F_38 ( V_121 , V_3 , V_125 , 2 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_546 * ) V_126 . V_151 ;
if ( V_39 ) {
if ( V_39 == - V_505 &&
V_123 -> V_97 . V_86 . V_240 == V_561 ) {
V_544 -> V_562 = true ;
V_39 = 0 ;
}
F_72 ( V_2 , V_563 ) ;
goto V_558;
}
V_39 = F_95 ( F_22 ( V_123 -> V_433 ) ,
F_41 ( V_123 -> V_430 ) , & V_123 -> V_97 ,
V_550 ) ;
if ( V_39 )
goto V_558;
V_544 -> V_564 = true ;
if ( V_544 -> V_565 ) {
if ( V_544 -> V_566 )
F_39 ( V_544 -> V_565 ) ;
else
F_139 ( V_544 -> V_565 ) ;
}
V_544 -> V_565 = ( char * ) V_123 ;
V_544 -> V_567 = V_544 -> V_568 = 4 +
( char * ) & V_123 -> V_97 + F_22 ( V_123 -> V_433 ) ;
V_417 = F_37 ( V_123 ) + 4 + ( char * ) & V_123 -> V_97 ;
V_544 -> V_569 =
F_137 ( V_544 -> V_567 , V_417 ,
& V_544 -> V_568 , V_550 ) ;
V_544 -> V_570 += V_544 -> V_569 ;
F_9 ( V_49 , L_69 ,
V_544 -> V_569 , V_544 -> V_570 ,
V_544 -> V_567 , V_544 -> V_568 ) ;
if ( V_127 == V_521 )
V_544 -> V_566 = false ;
else if ( V_127 == V_200 )
V_544 -> V_566 = true ;
else
F_9 ( V_158 , L_70 ) ;
return V_39 ;
V_558:
F_45 ( V_127 , V_123 ) ;
return V_39 ;
}
static int
F_140 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_3 V_475 , int V_421 ,
unsigned int V_312 , void * * V_218 , unsigned int * V_536 )
{
struct V_571 * V_117 ;
struct V_572 * V_123 = NULL ;
struct V_124 * V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
unsigned int V_573 ;
struct V_19 * V_9 ;
struct V_42 * V_3 = V_2 -> V_3 ;
int V_131 = 0 ;
if ( V_3 && ( V_3 -> V_9 ) )
V_9 = V_3 -> V_9 ;
else
return - V_52 ;
if ( ! V_312 )
return - V_246 ;
V_125 = F_61 ( sizeof( struct V_124 ) * V_312 , V_226 ) ;
if ( ! V_125 )
return - V_89 ;
V_39 = F_27 ( V_79 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 ) {
F_65 ( V_125 ) ;
return V_39 ;
}
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_475 ) ;
V_117 -> V_426 = V_427 ;
V_117 -> V_428 = V_421 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_117 -> V_574 =
F_3 ( sizeof( struct V_571 ) - 1 - 4 ) ;
V_117 -> V_575 = F_7 ( * V_536 ) ;
F_34 ( V_117 , * V_536 - 1 ) ;
memcpy ( V_117 -> V_242 , * V_218 , * V_536 ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 ;
for ( V_573 = 1 ; V_573 < V_312 ; V_573 ++ ) {
F_34 ( V_117 , V_536 [ V_573 ] ) ;
F_81 ( & V_117 -> V_575 , V_536 [ V_573 ] ) ;
V_125 [ V_573 ] . V_151 = ( char * ) V_218 [ V_573 ] ;
V_125 [ V_573 ] . V_152 = V_536 [ V_573 ] ;
}
V_39 = F_38 ( V_121 , V_3 , V_125 , V_312 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_117 ) ;
V_123 = (struct V_572 * ) V_126 . V_151 ;
if ( V_39 != 0 )
F_72 ( V_2 , V_576 ) ;
F_45 ( V_127 , V_123 ) ;
F_65 ( V_125 ) ;
return V_39 ;
}
int
F_141 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_1 * V_577 )
{
struct V_578 V_579 ;
void * * V_218 ;
unsigned int V_536 [ 2 ] ;
int V_39 ;
int V_227 = ( 2 * F_89 ( ( V_337 * ) V_577 , V_338 ) ) ;
V_218 = F_61 ( sizeof( void * ) * 2 , V_226 ) ;
if ( ! V_218 )
return - V_89 ;
V_579 . V_580 = 1 ;
V_579 . V_581 = 0 ;
V_579 . V_540 = F_7 ( V_227 ) ;
V_218 [ 0 ] = & V_579 ;
V_536 [ 0 ] = sizeof( struct V_578 ) ;
V_218 [ 1 ] = V_577 ;
V_536 [ 1 ] = V_227 + 2 ;
V_39 = F_140 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_582 , 2 , V_218 ,
V_536 ) ;
F_65 ( V_218 ) ;
return V_39 ;
}
int
F_142 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 )
{
T_5 V_583 = 1 ;
void * V_218 ;
unsigned int V_536 ;
V_218 = & V_583 ;
V_536 = 1 ;
return F_140 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_584 , 1 , & V_218 ,
& V_536 ) ;
}
int
F_143 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_1 * V_577 )
{
struct V_585 V_579 ;
void * * V_218 ;
unsigned int V_536 [ 2 ] ;
int V_39 ;
int V_227 = ( 2 * F_89 ( ( V_337 * ) V_577 , V_338 ) ) ;
V_218 = F_61 ( sizeof( void * ) * 2 , V_226 ) ;
if ( ! V_218 )
return - V_89 ;
V_579 . V_580 = 0 ;
V_579 . V_581 = 0 ;
V_579 . V_540 = F_7 ( V_227 ) ;
V_218 [ 0 ] = & V_579 ;
V_536 [ 0 ] = sizeof( struct V_585 ) ;
V_218 [ 1 ] = V_577 ;
V_536 [ 1 ] = V_227 + 2 ;
V_39 = F_140 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_586 , 2 , V_218 , V_536 ) ;
F_65 ( V_218 ) ;
return V_39 ;
}
int
F_144 ( const unsigned int V_121 , struct V_1 * V_2 , T_7 V_294 ,
T_7 V_296 , T_3 V_475 , T_10 * V_587 , bool V_588 )
{
struct V_589 V_579 ;
void * V_218 ;
unsigned int V_536 ;
V_579 . V_375 = * V_587 ;
V_218 = & V_579 ;
V_536 = sizeof( struct V_589 ) ;
if ( V_588 )
return F_140 ( V_121 , V_2 , V_294 , V_296 ,
V_475 , V_590 , 1 , & V_218 , & V_536 ) ;
else
return F_140 ( V_121 , V_2 , V_294 , V_296 ,
V_475 , V_591 , 1 , & V_218 , & V_536 ) ;
}
int
F_145 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , T_13 * V_80 )
{
unsigned int V_536 ;
V_536 = sizeof( T_13 ) ;
return F_140 ( V_121 , V_2 , V_294 , V_296 ,
V_26 -> V_27 , V_592 , 1 ,
( void * * ) & V_80 , & V_536 ) ;
}
int
F_146 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_7 V_294 , const T_7 V_296 ,
T_5 V_593 )
{
int V_39 ;
struct V_594 * V_117 = NULL ;
int V_131 = V_595 ;
F_9 ( V_49 , L_71 ) ;
V_39 = F_27 ( V_57 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_596 = V_296 ;
V_117 -> V_597 = V_294 ;
V_117 -> V_380 = V_593 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_39 = F_71 ( V_121 , V_2 -> V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_598 ) ;
F_9 ( V_49 , L_72 , V_39 ) ;
}
return V_39 ;
}
static void
F_147 ( struct V_599 * V_600 ,
struct V_601 * V_602 )
{
V_602 -> V_603 = F_41 ( V_600 -> V_604 ) *
F_41 ( V_600 -> V_605 ) ;
V_602 -> V_606 = F_148 ( V_600 -> V_607 ) ;
V_602 -> V_608 = F_148 ( V_600 -> V_609 ) ;
V_602 -> V_610 = F_148 ( V_600 -> V_611 ) ;
return;
}
static int
F_149 ( struct V_124 * V_125 , struct V_1 * V_2 , int V_612 ,
int V_613 , T_7 V_294 , T_7 V_296 )
{
int V_39 ;
struct V_424 * V_117 ;
F_9 ( V_49 , L_73 , V_612 ) ;
if ( ( V_2 -> V_3 == NULL ) || ( V_2 -> V_3 -> V_9 == NULL ) )
return - V_52 ;
V_39 = F_27 ( V_78 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
V_117 -> V_426 = V_614 ;
V_117 -> V_428 = V_612 ;
V_117 -> V_293 = V_294 ;
V_117 -> V_295 = V_296 ;
V_117 -> V_429 =
F_3 ( sizeof( struct V_424 ) - 1 - 4 ) ;
V_117 -> V_430 = F_7 (
V_613 + sizeof( struct V_425 ) - 1 - 4 ) ;
V_125 -> V_151 = ( char * ) V_117 ;
V_125 -> V_152 = F_37 ( V_117 ) + 4 ;
return 0 ;
}
int
F_150 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , struct V_601 * V_615 )
{
struct V_425 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 ;
struct V_42 * V_3 = V_2 -> V_3 ;
struct V_599 * V_579 = NULL ;
int V_131 = 0 ;
V_39 = F_149 ( & V_125 , V_2 , V_616 ,
sizeof( struct V_599 ) ,
V_294 , V_296 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_39 = F_38 ( V_121 , V_3 , & V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_125 . V_151 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_431 ) ;
goto V_617;
}
V_123 = (struct V_425 * ) V_126 . V_151 ;
V_579 = (struct V_599 * ) ( 4 +
F_22 ( V_123 -> V_433 ) + ( char * ) & V_123 -> V_97 ) ;
V_39 = F_95 ( F_22 ( V_123 -> V_433 ) ,
F_41 ( V_123 -> V_430 ) , & V_123 -> V_97 ,
sizeof( struct V_599 ) ) ;
if ( ! V_39 )
F_147 ( V_579 , V_615 ) ;
V_617:
F_45 ( V_127 , V_126 . V_151 ) ;
return V_39 ;
}
int
F_151 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_7 V_294 , T_7 V_296 , int V_612 )
{
struct V_425 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_124 V_126 ;
int V_39 = 0 ;
int V_127 , V_618 , V_423 ;
struct V_42 * V_3 = V_2 -> V_3 ;
unsigned int V_619 , V_412 ;
int V_131 = 0 ;
if ( V_612 == V_620 ) {
V_618 = sizeof( V_621 ) ;
V_423 = sizeof( V_621 ) ;
} else if ( V_612 == V_622 ) {
V_618 = sizeof( V_623 ) ;
V_423 = V_624 ;
} else if ( V_612 == V_625 ) {
V_618 = sizeof( struct V_626 ) ;
V_423 = sizeof( struct V_626 ) ;
} else {
F_9 ( V_49 , L_74 , V_612 ) ;
return - V_246 ;
}
V_39 = F_149 ( & V_125 , V_2 , V_612 , V_618 ,
V_294 , V_296 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_39 = F_38 ( V_121 , V_3 , & V_125 , 1 , & V_127 , V_131 , & V_126 ) ;
F_39 ( V_125 . V_151 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_431 ) ;
goto V_627;
}
V_123 = (struct V_425 * ) V_126 . V_151 ;
V_619 = F_41 ( V_123 -> V_430 ) ;
V_412 = F_22 ( V_123 -> V_433 ) ;
V_39 = F_95 ( V_412 , V_619 , & V_123 -> V_97 , V_423 ) ;
if ( V_39 )
goto V_627;
if ( V_612 == V_622 )
memcpy ( & V_2 -> V_628 , 4 + V_412
+ ( char * ) & V_123 -> V_97 , F_5 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_612 == V_620 )
memcpy ( & V_2 -> V_629 , 4 + V_412
+ ( char * ) & V_123 -> V_97 , sizeof( V_621 ) ) ;
else if ( V_612 == V_625 ) {
struct V_626 * V_630 = (struct V_626 * )
( 4 + V_412 + ( char * ) & V_123 -> V_97 ) ;
V_2 -> V_631 = F_41 ( V_630 -> V_36 ) ;
V_2 -> V_632 =
F_41 ( V_630 -> V_633 ) ;
}
V_627:
F_45 ( V_127 , V_126 . V_151 ) ;
return V_39 ;
}
int
F_152 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_14 V_634 , const T_14 V_296 , const T_6 V_475 ,
const T_6 V_635 , struct V_636 * V_80 )
{
int V_39 = 0 ;
struct V_637 * V_117 = NULL ;
struct V_124 V_125 [ 2 ] ;
struct V_124 V_126 ;
int V_638 ;
unsigned int V_639 ;
int V_131 = V_640 ;
F_9 ( V_49 , L_75 , V_635 ) ;
V_39 = F_27 ( V_74 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_24 = F_7 ( V_475 ) ;
V_117 -> V_641 = F_3 ( V_635 ) ;
V_117 -> V_293 = V_634 ;
V_117 -> V_295 = V_296 ;
V_639 = V_635 * sizeof( struct V_636 ) ;
F_34 ( V_117 , V_639 - sizeof( struct V_636 ) ) ;
V_125 [ 0 ] . V_151 = ( char * ) V_117 ;
V_125 [ 0 ] . V_152 = F_37 ( V_117 ) + 4 - V_639 ;
V_125 [ 1 ] . V_151 = ( char * ) V_80 ;
V_125 [ 1 ] . V_152 = V_639 ;
F_26 ( & V_2 -> V_91 . V_642 . V_643 ) ;
V_39 = F_38 ( V_121 , V_2 -> V_3 , V_125 , 2 , & V_638 , V_131 ,
& V_126 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_9 ( V_49 , L_76 , V_39 ) ;
F_72 ( V_2 , V_644 ) ;
}
return V_39 ;
}
int
F_153 ( const unsigned int V_121 , struct V_1 * V_2 ,
const T_14 V_634 , const T_14 V_296 , const T_6 V_475 ,
const T_14 V_480 , const T_14 V_412 , const T_6 V_645 ,
const bool V_646 )
{
struct V_636 V_647 ;
V_647 . V_481 = F_118 ( V_412 ) ;
V_647 . V_479 = F_118 ( V_480 ) ;
V_647 . V_36 = F_7 ( V_645 ) ;
if ( ! V_646 && V_645 != V_648 )
V_647 . V_36 |= F_7 ( V_649 ) ;
return F_152 ( V_121 , V_2 , V_634 , V_296 , V_475 , 1 , & V_647 ) ;
}
int
F_154 ( const unsigned int V_121 , struct V_1 * V_2 ,
T_5 * V_650 , const T_15 V_651 )
{
int V_39 ;
struct V_652 * V_117 = NULL ;
int V_131 = V_595 ;
F_9 ( V_49 , L_77 ) ;
V_39 = F_27 ( V_57 , V_2 , ( void * * ) & V_117 ) ;
if ( V_39 )
return V_39 ;
if ( F_1 ( V_2 ) )
V_131 |= V_250 ;
V_117 -> V_97 . V_86 . V_23 = F_3 ( 1 ) ;
V_117 -> V_17 = F_3 ( 36 ) ;
F_34 ( V_117 , 12 ) ;
memcpy ( V_117 -> V_653 , V_650 , 16 ) ;
V_117 -> V_654 = V_651 ;
V_39 = F_71 ( V_121 , V_2 -> V_3 , ( char * ) V_117 , V_131 ) ;
F_39 ( V_117 ) ;
if ( V_39 ) {
F_72 ( V_2 , V_598 ) ;
F_9 ( V_49 , L_78 , V_39 ) ;
}
return V_39 ;
}
