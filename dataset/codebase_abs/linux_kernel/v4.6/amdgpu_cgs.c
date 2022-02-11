static int F_1 ( void * V_1 , enum V_2 type ,
T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 )
{
V_6 ;
switch( type ) {
case V_7 :
case V_8 :
* V_3 = 0 ;
* V_4 = V_9 -> V_10 . V_11 ;
* V_5 = V_9 -> V_10 . V_11 - V_9 -> V_12 ;
break;
case V_13 :
case V_14 :
* V_3 = V_9 -> V_10 . V_11 ;
* V_4 = V_9 -> V_10 . V_15 - V_9 -> V_10 . V_11 ;
* V_5 = * V_4 ;
break;
case V_16 :
case V_17 :
* V_3 = V_9 -> V_10 . V_18 ;
* V_4 = V_9 -> V_10 . V_19 ;
* V_5 = V_9 -> V_10 . V_19 - V_9 -> V_20 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_2 ( void * V_1 , void * V_22 ,
T_1 V_23 ,
T_1 V_24 , T_1 V_25 ,
T_2 * V_26 , T_1 * V_27 )
{
V_6 ;
int V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = F_3 ( V_22 ) ;
int V_33 = F_4 ( V_23 , V_34 ) >> V_35 ;
struct V_36 * V_37 = F_5 ( & V_32 , V_33 ) ;
V_28 = F_6 ( V_9 , V_23 , V_34 , false ,
V_38 , 0 , V_37 , NULL , & V_30 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_30 , false ) ;
if ( F_8 ( V_28 != 0 ) )
return V_28 ;
V_28 = F_9 ( V_30 , V_38 ,
V_24 , V_25 , V_27 ) ;
F_10 ( V_30 ) ;
* V_26 = ( T_2 ) V_30 ;
return V_28 ;
}
static int F_11 ( void * V_1 , T_2 V_26 )
{
struct V_29 * V_39 = (struct V_29 * ) V_26 ;
if ( V_39 ) {
int V_40 = F_7 ( V_39 , false ) ;
if ( F_12 ( V_40 == 0 ) ) {
F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
}
F_14 ( & V_39 ) ;
}
return 0 ;
}
static int F_15 ( void * V_1 ,
enum V_2 type ,
T_1 V_23 , T_1 V_41 ,
T_1 V_24 , T_1 V_25 ,
T_2 * V_42 )
{
V_6 ;
T_3 V_43 = 0 ;
int V_28 = 0 ;
T_4 V_44 = 0 ;
struct V_29 * V_39 ;
struct V_45 V_46 ;
struct V_47 V_48 ;
if ( V_24 > V_25 ) {
F_16 ( 1 ) ;
return - V_21 ;
}
if ( ( ( V_41 != 1 ) && ( V_41 & ( V_41 - 1 ) ) )
|| V_23 == 0 || V_41 == 0 )
return - V_21 ;
switch( type ) {
case V_7 :
case V_8 :
V_43 = V_49 ;
V_44 = V_50 ;
if ( V_25 > V_9 -> V_10 . V_15 )
return - V_21 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_53 | V_54 |
V_55 ;
break;
case V_13 :
case V_14 :
V_43 = V_56 ;
V_44 = V_50 ;
if ( V_9 -> V_10 . V_11 < V_9 -> V_10 . V_15 ) {
V_48 . V_51 =
F_17 ( V_24 , V_9 -> V_10 . V_11 ) >> V_35 ;
V_48 . V_52 =
F_18 ( V_25 , V_9 -> V_10 . V_15 ) >> V_35 ;
V_48 . V_43 = V_53 | V_54 |
V_55 ;
}
break;
case V_16 :
V_44 = V_38 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_57 | V_58 ;
break;
case V_17 :
V_43 = V_59 ;
V_44 = V_38 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_53 | V_58 |
V_54 ;
break;
default:
return - V_21 ;
}
* V_42 = 0 ;
V_46 . V_46 = & V_48 ;
V_46 . V_60 = 1 ;
V_46 . V_61 = & V_48 ;
V_46 . V_62 = 1 ;
V_28 = F_19 ( V_9 , V_23 , V_34 ,
true , V_44 , V_43 ,
NULL , & V_46 , NULL ,
& V_39 ) ;
if ( V_28 ) {
F_20 ( L_1 , V_28 ) ;
return V_28 ;
}
* V_42 = ( T_2 ) V_39 ;
return V_28 ;
}
static int F_21 ( void * V_1 , T_2 V_42 )
{
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
if ( V_39 ) {
int V_40 = F_7 ( V_39 , false ) ;
if ( F_12 ( V_40 == 0 ) ) {
F_22 ( V_39 ) ;
F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
}
F_14 ( & V_39 ) ;
}
return 0 ;
}
static int F_23 ( void * V_1 , T_2 V_42 ,
T_1 * V_27 )
{
int V_40 ;
T_5 V_24 , V_25 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
F_24 ( V_39 -> V_46 . V_60 > 1 ) ;
V_24 = V_39 -> V_63 [ 0 ] . V_51 << V_35 ;
V_25 = V_39 -> V_63 [ 0 ] . V_52 << V_35 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_9 ( V_39 , V_38 ,
V_24 , V_25 , V_27 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_25 ( void * V_1 , T_2 V_42 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_26 ( void * V_1 , T_2 V_42 ,
void * * V_64 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_27 ( V_39 , V_64 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_28 ( void * V_1 , T_2 V_42 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
F_22 ( V_39 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static T_4 F_29 ( void * V_1 , unsigned V_65 )
{
V_6 ;
return F_30 ( V_65 ) ;
}
static void F_31 ( void * V_1 , unsigned V_65 ,
T_4 V_66 )
{
V_6 ;
F_32 ( V_65 , V_66 ) ;
}
static T_4 F_33 ( void * V_1 ,
enum V_67 V_68 ,
unsigned V_69 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_34 ( V_69 ) ;
case V_71 :
return F_35 ( V_69 ) ;
case V_72 :
return F_36 ( V_69 ) ;
case V_73 :
return F_37 ( V_69 ) ;
case V_74 :
return F_38 ( V_69 ) ;
case V_75 :
F_20 ( L_2 ) ;
return 0 ;
}
F_39 ( 1 , L_3 ) ;
return 0 ;
}
static void F_40 ( void * V_1 ,
enum V_67 V_68 ,
unsigned V_69 , T_4 V_66 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_41 ( V_69 , V_66 ) ;
case V_71 :
return F_42 ( V_69 , V_66 ) ;
case V_72 :
return F_43 ( V_69 , V_66 ) ;
case V_73 :
return F_44 ( V_69 , V_66 ) ;
case V_74 :
return F_45 ( V_69 , V_66 ) ;
case V_75 :
F_20 ( L_2 ) ;
return;
}
F_39 ( 1 , L_3 ) ;
}
static T_6 F_46 ( void * V_1 , unsigned V_76 )
{
V_6 ;
T_6 V_77 ;
int V_28 = F_47 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_4 ) )
return 0 ;
return V_77 ;
}
static T_3 F_48 ( void * V_1 , unsigned V_76 )
{
V_6 ;
T_3 V_77 ;
int V_28 = F_49 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_5 ) )
return 0 ;
return V_77 ;
}
static T_4 F_50 ( void * V_1 ,
unsigned V_76 )
{
V_6 ;
T_4 V_77 ;
int V_28 = F_51 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_6 ) )
return 0 ;
return V_77 ;
}
static void F_52 ( void * V_1 , unsigned V_76 ,
T_6 V_66 )
{
V_6 ;
int V_28 = F_53 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_7 ) ;
}
static void F_54 ( void * V_1 , unsigned V_76 ,
T_3 V_66 )
{
V_6 ;
int V_28 = F_55 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_8 ) ;
}
static void F_56 ( void * V_1 , unsigned V_76 ,
T_4 V_66 )
{
V_6 ;
int V_28 = F_57 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_9 ) ;
}
static int F_58 ( void * V_1 ,
enum V_79 V_80 ,
T_1 V_23 ,
T_1 V_65 ,
T_1 * V_81 )
{
V_6 ;
if ( V_81 == NULL )
return - V_21 ;
switch ( V_80 ) {
case V_82 :
if ( V_9 -> V_83 == 0 )
return - V_84 ;
if ( ( V_65 + V_23 ) > V_9 -> V_83 )
return - V_21 ;
* V_81 = V_9 -> V_85 ;
return 0 ;
case V_86 :
if ( V_9 -> V_87 . V_23 == 0 )
return - V_84 ;
if ( ( V_65 + V_23 ) > V_9 -> V_87 . V_23 )
return - V_21 ;
* V_81 = V_9 -> V_87 . V_88 ;
return 0 ;
case V_89 :
case V_90 :
case V_91 :
default:
return - V_21 ;
}
}
static const void * F_59 ( void * V_1 ,
unsigned V_92 , T_3 * V_23 ,
T_6 * V_93 , T_6 * V_94 )
{
V_6 ;
T_3 V_95 ;
if ( F_60 (
V_9 -> V_96 . V_97 , V_92 , V_23 ,
V_93 , V_94 , & V_95 ) )
return ( T_6 * ) V_9 -> V_96 . V_97 -> V_98 +
V_95 ;
return NULL ;
}
static int F_61 ( void * V_1 , unsigned V_92 ,
T_6 * V_93 , T_6 * V_94 )
{
V_6 ;
if ( F_62 (
V_9 -> V_96 . V_97 , V_92 ,
V_93 , V_94 ) )
return 0 ;
return - V_21 ;
}
static int F_63 ( void * V_1 , unsigned V_92 ,
void * args )
{
V_6 ;
return F_64 (
V_9 -> V_96 . V_97 , V_92 , args ) ;
}
static int F_65 ( void * V_1 , T_2 * V_99 )
{
return 0 ;
}
static int F_66 ( void * V_1 , T_2 V_99 )
{
return 0 ;
}
static int F_67 ( void * V_1 , T_2 V_99 ,
int V_100 )
{
return 0 ;
}
static int F_68 ( void * V_1 , T_2 V_99 ,
enum V_101 clock , unsigned V_102 )
{
return 0 ;
}
static int F_69 ( void * V_1 , T_2 V_99 ,
enum V_103 V_104 , int V_105 )
{
return 0 ;
}
static int F_70 ( void * V_1 ,
enum V_101 clock ,
struct V_106 * V_107 )
{
return 0 ;
}
static int F_71 ( void * V_1 , T_4 V_108 ,
const T_4 * V_109 )
{
F_20 ( L_10 ) ;
return - V_110 ;
}
static int F_72 ( struct V_111 * V_9 ,
struct V_112 * V_113 ,
unsigned type ,
enum V_114 V_115 )
{
struct V_116 * V_117 =
(struct V_116 * ) V_113 -> V_118 ;
if ( ! V_117 )
return - V_21 ;
if ( ! V_117 -> V_119 )
return - V_21 ;
return V_117 -> V_119 ( V_117 -> V_120 ,
V_117 -> V_121 ,
type ,
( int ) V_115 ) ;
}
static int F_73 ( struct V_111 * V_9 ,
struct V_112 * V_122 ,
struct V_123 * V_124 )
{
struct V_116 * V_117 =
(struct V_116 * ) V_122 -> V_118 ;
if ( ! V_117 )
return - V_21 ;
if ( ! V_117 -> V_125 )
return - V_21 ;
return V_117 -> V_125 ( V_117 -> V_120 ,
V_117 -> V_121 ,
V_124 -> V_126 ) ;
}
static int F_74 ( void * V_1 , unsigned V_121 ,
unsigned V_127 ,
T_7 V_119 ,
T_8 V_125 ,
void * V_120 )
{
V_6 ;
int V_28 = 0 ;
struct V_116 * V_117 ;
struct V_112 * V_122 =
F_75 ( sizeof( struct V_112 ) , V_128 ) ;
if ( ! V_122 )
return - V_129 ;
V_117 =
F_75 ( sizeof( struct V_116 ) , V_128 ) ;
if ( ! V_117 ) {
F_76 ( V_122 ) ;
return - V_129 ;
}
V_122 -> V_127 = V_127 ;
V_122 -> V_130 = & V_131 ;
V_117 -> V_121 = V_121 ;
V_117 -> V_119 = V_119 ;
V_117 -> V_125 = V_125 ;
V_117 -> V_120 = V_120 ;
V_122 -> V_118 = ( void * ) V_117 ;
V_28 = F_77 ( V_9 , V_121 , V_122 ) ;
if ( V_28 ) {
F_76 ( V_117 ) ;
F_76 ( V_122 ) ;
}
return V_28 ;
}
static int F_78 ( void * V_1 , unsigned V_121 , unsigned type )
{
V_6 ;
return F_79 ( V_9 , V_9 -> V_132 . V_133 [ V_121 ] , type ) ;
}
static int F_80 ( void * V_1 , unsigned V_121 , unsigned type )
{
V_6 ;
return F_81 ( V_9 , V_9 -> V_132 . V_133 [ V_121 ] , type ) ;
}
int F_82 ( void * V_1 ,
enum V_134 V_135 ,
enum V_136 V_115 )
{
V_6 ;
int V_137 , V_40 = - 1 ;
for ( V_137 = 0 ; V_137 < V_9 -> V_138 ; V_137 ++ ) {
if ( ! V_9 -> V_139 [ V_137 ] . V_140 )
continue;
if ( V_9 -> V_141 [ V_137 ] . type == V_135 ) {
V_40 = V_9 -> V_141 [ V_137 ] . V_130 -> V_142 (
( void * ) V_9 ,
V_115 ) ;
break;
}
}
return V_40 ;
}
int F_83 ( void * V_1 ,
enum V_134 V_135 ,
enum V_143 V_115 )
{
V_6 ;
int V_137 , V_40 = - 1 ;
for ( V_137 = 0 ; V_137 < V_9 -> V_138 ; V_137 ++ ) {
if ( ! V_9 -> V_139 [ V_137 ] . V_140 )
continue;
if ( V_9 -> V_141 [ V_137 ] . type == V_135 ) {
V_40 = V_9 -> V_141 [ V_137 ] . V_130 -> V_144 (
( void * ) V_9 ,
V_115 ) ;
break;
}
}
return V_40 ;
}
static T_4 F_84 ( void * V_1 , T_4 V_145 )
{
V_6 ;
enum V_146 V_147 = V_148 ;
switch ( V_145 ) {
case V_149 :
V_147 = V_150 ;
break;
case V_151 :
V_147 = V_152 ;
break;
case V_153 :
V_147 = V_154 ;
break;
case V_155 :
V_147 = V_156 ;
break;
case V_157 :
V_147 = V_158 ;
break;
case V_159 :
case V_160 :
V_147 = V_161 ;
break;
case V_162 :
if ( V_9 -> V_163 == V_164 )
V_147 = V_165 ;
else if ( V_9 -> V_163 == V_166 )
V_147 = V_161 ;
break;
case V_167 :
V_147 = V_168 ;
break;
default:
F_20 ( L_11 ) ;
}
return V_147 ;
}
static int F_85 ( void * V_1 ,
enum V_169 type ,
struct V_170 * V_171 )
{
V_6 ;
if ( V_172 != type ) {
T_1 V_173 ;
T_4 V_174 ;
const struct V_175 * V_176 ;
enum V_146 V_177 ;
struct V_178 * V_179 ;
V_177 = F_84 ( V_1 , type ) ;
V_179 = & V_9 -> V_180 . V_179 [ V_177 ] ;
if ( V_179 -> V_181 == NULL )
return - V_21 ;
V_173 = V_179 -> V_182 ;
V_176 = ( const struct V_175 * ) V_179 -> V_181 -> V_118 ;
V_174 = F_86 ( V_176 -> V_176 . V_183 ) ;
if ( ( type == V_160 ) ||
( type == V_162 ) ) {
V_173 += F_86 ( V_176 -> V_184 ) << 2 ;
V_174 = F_86 ( V_176 -> V_185 ) << 2 ;
}
V_171 -> V_182 = V_173 ;
V_171 -> V_186 = V_174 ;
V_171 -> V_187 = ( T_3 ) F_86 ( V_176 -> V_176 . V_188 ) ;
V_171 -> V_189 = ( T_3 ) F_86 ( V_176 -> V_190 ) ;
} else {
char V_191 [ 30 ] = { 0 } ;
int V_192 = 0 ;
T_4 V_193 ;
T_4 V_194 ;
const T_6 * V_113 ;
const struct V_195 * V_196 ;
switch ( V_9 -> V_163 ) {
case V_164 :
strcpy ( V_191 , L_12 ) ;
break;
case V_197 :
strcpy ( V_191 , L_13 ) ;
break;
default:
F_20 ( L_14 ) ;
return - V_21 ;
}
V_192 = F_87 ( & V_9 -> V_198 . V_181 , V_191 , V_9 -> V_199 ) ;
if ( V_192 ) {
F_20 ( L_15 ) ;
return V_192 ;
}
V_192 = F_88 ( V_9 -> V_198 . V_181 ) ;
if ( V_192 ) {
F_20 ( L_16 , V_191 ) ;
F_89 ( V_9 -> V_198 . V_181 ) ;
V_9 -> V_198 . V_181 = NULL ;
return V_192 ;
}
V_196 = ( const struct V_195 * ) V_9 -> V_198 . V_181 -> V_118 ;
V_9 -> V_198 . V_200 = F_86 ( V_196 -> V_176 . V_188 ) ;
V_193 = F_86 ( V_196 -> V_176 . V_183 ) ;
V_194 = F_86 ( V_196 -> V_201 ) ;
V_113 = ( const T_6 * ) ( V_9 -> V_198 . V_181 -> V_118 +
F_86 ( V_196 -> V_176 . V_202 ) ) ;
V_171 -> V_187 = V_9 -> V_198 . V_200 ;
V_171 -> V_186 = V_193 ;
V_171 -> V_203 = ( void * ) V_113 ;
}
return 0 ;
}
static int F_90 ( void * V_1 ,
struct V_204 * V_205 )
{
V_6 ;
if ( NULL == V_205 )
return - V_206 ;
if ( sizeof( struct V_204 ) != V_205 -> V_23 )
return - V_206 ;
switch ( V_205 -> V_207 ) {
case V_208 :
V_205 -> V_66 = V_9 -> V_78 -> V_209 | ( V_9 -> V_78 -> V_210 -> V_211 << 8 ) ;
break;
case V_212 :
V_205 -> V_66 = V_9 -> V_198 . V_213 ;
break;
case V_214 :
V_205 -> V_66 = V_9 -> V_198 . V_215 ;
break;
case V_216 :
V_205 -> V_66 = V_9 -> V_217 ;
break;
case V_218 :
V_205 -> V_66 = V_9 -> V_219 ;
break;
default:
return - V_206 ;
}
return 0 ;
}
static int F_91 ( void * V_1 ,
struct V_220 * V_171 )
{
V_6 ;
struct V_221 * V_221 ;
struct V_222 * V_223 = V_9 -> V_223 ;
struct V_224 * V_225 ;
T_4 V_226 , V_227 ;
struct V_228 * V_96 ;
if ( V_171 == NULL )
return - V_21 ;
V_96 = V_171 -> V_96 ;
if ( V_9 -> V_96 . V_229 && V_9 -> V_96 . V_230 ) {
F_92 (crtc,
&ddev->mode_config.crtc_list, head) {
V_221 = F_93 ( V_225 ) ;
if ( V_225 -> V_231 ) {
V_171 -> V_232 |= ( 1 << V_221 -> V_233 ) ;
V_171 -> V_234 ++ ;
}
if ( V_96 != NULL &&
V_225 -> V_231 && V_221 -> V_231 &&
V_221 -> V_235 . clock ) {
V_226 = ( V_221 -> V_235 . V_236 * 1000 ) /
V_221 -> V_235 . clock ;
V_227 = V_221 -> V_235 . V_237 -
V_221 -> V_235 . V_238 +
( V_221 -> V_239 * 2 ) ;
V_96 -> V_240 = V_227 * V_226 ;
V_96 -> V_241 = F_94 ( & V_221 -> V_235 ) ;
V_96 -> V_242 = V_9 -> clock . V_243 . V_244 ;
V_96 = NULL ;
}
}
}
return 0 ;
}
static int F_95 ( void * V_1 , bool V_231 )
{
V_6 ;
V_9 -> V_198 . V_245 = V_231 ;
return 0 ;
}
static int F_96 ( void * V_1 ,
struct V_246 * V_171 )
{
V_6 ;
T_9 V_42 ;
struct V_247 V_248 ;
struct V_249 V_250 = { V_251 , NULL } ;
union V_252 * V_253 = NULL ;
union V_252 * V_39 = NULL ;
T_6 V_254 [ 5 ] = { '\0' } ;
struct V_255 * V_256 = NULL ;
T_4 V_137 , V_257 ;
T_10 V_258 ;
int V_147 ;
T_4 V_259 = 0xFFFFFFFF ;
V_42 = F_97 ( & V_9 -> V_78 -> V_199 ) ;
if ( ! V_42 )
return - V_206 ;
memset ( & V_248 , 0 , sizeof( struct V_247 ) ) ;
if ( V_171 -> V_23 != sizeof( struct V_246 ) )
return - V_21 ;
V_248 . V_257 = V_171 -> V_260 ;
if ( V_171 -> V_260 > 0 ) {
if ( V_171 -> V_261 == NULL )
return - V_21 ;
V_256 = V_171 -> V_261 ;
V_259 = V_256 -> V_66 ;
for ( V_137 = 0 ; V_137 < V_171 -> V_260 ; V_137 ++ ) {
if ( ( ( V_256 -> type == V_262 ) ||
( V_256 -> type == V_263 ) ) &&
( V_256 -> V_264 == NULL ) )
return - V_21 ;
V_256 ++ ;
}
}
if ( V_171 -> V_265 > 0 ) {
if ( V_171 -> V_266 == NULL )
return - V_21 ;
V_256 = V_171 -> V_266 ;
for ( V_137 = 0 ; V_137 < V_171 -> V_265 ; V_137 ++ ) {
if ( ( ( V_256 -> type == V_262 ) ||
( V_256 -> type == V_263 ) )
&& ( V_256 -> V_264 == NULL ) )
return - V_21 ;
V_256 ++ ;
}
}
if ( ( V_171 -> V_267 & V_268 ) != 0 ) {
strncpy ( V_254 , ( char * ) & ( V_171 -> V_254 ) , sizeof( T_4 ) ) ;
V_254 [ 4 ] = '\0' ;
}
if ( V_248 . V_257 > 0 ) {
V_248 . V_264 = V_253 =
F_75 ( sizeof( union V_252 ) * V_248 . V_257 , V_128 ) ;
if ( V_253 == NULL )
return - V_21 ;
V_256 = V_171 -> V_261 ;
for ( V_137 = 0 ; V_137 < V_248 . V_257 ; V_137 ++ ) {
V_253 -> type = V_256 -> type ;
switch ( V_253 -> type ) {
case V_269 :
V_253 -> integer . V_66 = V_256 -> V_66 ;
break;
case V_262 :
V_253 -> string . V_270 = V_256 -> V_271 ;
V_253 -> string . V_264 = V_256 -> V_264 ;
break;
case V_263 :
V_253 -> V_272 . V_270 = V_256 -> V_271 ;
V_253 -> V_272 . V_264 = V_256 -> V_264 ;
break;
default:
break;
}
V_253 ++ ;
V_256 ++ ;
}
}
V_257 = V_171 -> V_265 ;
V_256 = V_171 -> V_266 ;
V_258 = F_98 ( V_42 , V_254 , & V_248 , & V_250 ) ;
if ( F_99 ( V_258 ) ) {
V_147 = - V_273 ;
goto error;
}
V_39 = V_250 . V_264 ;
if ( V_257 > 1 ) {
if ( ( V_39 -> type != V_274 ) ||
( V_39 -> V_275 . V_257 != V_257 ) ) {
V_147 = - V_273 ;
goto error;
}
V_253 = V_39 -> V_275 . V_276 ;
} else
V_253 = V_39 ;
if ( V_253 == NULL ) {
V_147 = - V_273 ;
goto error;
}
for ( V_137 = 0 ; V_137 < V_257 ; V_137 ++ ) {
if ( V_256 -> type != V_253 -> type ) {
V_147 = - V_273 ;
goto error;
}
switch ( V_253 -> type ) {
case V_269 :
V_256 -> V_66 = V_253 -> integer . V_66 ;
break;
case V_262 :
if ( ( V_253 -> string . V_270 != V_256 -> V_277 ) ||
( V_253 -> string . V_264 == NULL ) ) {
V_147 = - V_273 ;
goto error;
}
strncpy ( V_256 -> V_264 ,
V_253 -> string . V_264 ,
V_253 -> string . V_270 ) ;
break;
case V_263 :
if ( V_253 -> V_272 . V_264 == NULL ) {
V_147 = - V_273 ;
goto error;
}
memcpy ( V_256 -> V_264 ,
V_253 -> V_272 . V_264 ,
V_256 -> V_277 ) ;
break;
default:
break;
}
V_256 ++ ;
V_253 ++ ;
}
error:
if ( V_39 != NULL )
F_76 ( V_39 ) ;
F_76 ( ( void * ) V_248 . V_264 ) ;
return V_147 ;
}
static int F_96 ( void * V_1 ,
struct V_246 * V_171 )
{
return - V_273 ;
}
int F_100 ( void * V_1 ,
T_4 V_278 ,
T_4 V_279 ,
void * V_280 , void * V_281 ,
T_4 V_265 ,
T_4 V_282 ,
T_4 V_283 )
{
struct V_255 V_284 [ 2 ] = { { 0 } , { 0 } } ;
struct V_255 V_285 = { 0 } ;
struct V_246 V_171 = { 0 } ;
V_284 [ 0 ] . type = V_286 ;
V_284 [ 0 ] . V_271 = sizeof( T_4 ) ;
V_284 [ 0 ] . V_277 = sizeof( T_4 ) ;
V_284 [ 0 ] . V_66 = V_279 ;
V_284 [ 1 ] . type = V_287 ;
V_284 [ 1 ] . V_271 = V_288 ;
V_284 [ 1 ] . V_277 = V_282 ;
V_284 [ 1 ] . V_264 = V_280 ;
V_285 . type = V_287 ;
V_285 . V_271 = V_288 ;
V_285 . V_277 = V_283 ;
V_285 . V_264 = V_281 ;
V_171 . V_23 = sizeof( struct V_246 ) ;
V_171 . V_267 = V_268 | V_289 ;
V_171 . V_260 = 2 ;
V_171 . V_254 = V_278 ;
V_171 . V_261 = V_284 ;
V_171 . V_265 = V_265 ;
V_171 . V_266 = & V_285 ;
return F_96 ( V_1 , & V_171 ) ;
}
void * F_101 ( struct V_111 * V_9 )
{
struct V_290 * V_1 =
F_102 ( sizeof( * V_1 ) , V_128 ) ;
if ( ! V_1 ) {
F_20 ( L_17 ) ;
return NULL ;
}
V_1 -> V_88 . V_291 = & V_292 ;
V_1 -> V_88 . V_293 = & V_294 ;
V_1 -> V_9 = V_9 ;
return V_1 ;
}
void F_103 ( void * V_1 )
{
F_76 ( V_1 ) ;
}
