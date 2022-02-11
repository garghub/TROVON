static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_4 != V_3 -> V_5 )
return NULL ;
return (struct V_1 * ) V_3 ;
}
static const struct V_1 * F_2 (
const struct V_2 * V_3 )
{
if ( V_4 != V_3 -> V_5 )
return NULL ;
return (struct V_1 * ) V_3 ;
}
static int F_3 ( struct V_6 * V_7 )
{
T_1 V_8 , V_9 ;
struct V_10 * V_11 ;
T_1 V_12 = F_4 ( V_13 ) ;
if ( V_7 -> V_14 . V_15 != NULL )
return 0 ;
V_8 = sizeof( struct V_10 ) +
sizeof( struct V_16 ) * ( V_12 - 1 ) ;
V_11 = F_5 ( V_8 , V_17 ) ;
if ( NULL == V_11 )
return - V_18 ;
V_11 -> V_19 = ( V_20 ) V_12 ;
for ( V_9 = 0 ; V_9 < V_11 -> V_19 ; V_9 ++ ) {
V_11 -> V_21 [ V_9 ] . V_22 = V_13 [ V_9 ] . V_22 ;
V_11 -> V_21 [ V_9 ] . V_23 = V_13 [ V_9 ] . V_23 ;
V_11 -> V_21 [ V_9 ] . V_24 = V_13 [ V_9 ] . V_24 ;
V_11 -> V_21 [ V_9 ] . V_25 = V_13 [ V_9 ] . V_25 ;
V_11 -> V_21 [ V_9 ] . V_26 = V_13 [ V_9 ] . V_26 ;
V_11 -> V_21 [ V_9 ] . V_27 = V_13 [ V_9 ] . V_27 ;
V_11 -> V_21 [ V_9 ] . V_28 = V_13 [ V_9 ] . V_28 ;
V_11 -> V_21 [ V_9 ] . V_29 = V_13 [ V_9 ] . V_29 ;
V_11 -> V_21 [ V_9 ] . V_30 = V_13 [ V_9 ] . V_30 ;
V_11 -> V_21 [ V_9 ] . V_31 = V_13 [ V_9 ] . V_31 ;
}
V_7 -> V_14 . V_15 = V_11 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_32 * V_32 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_34 V_35 = { 0 } ;
int V_36 ;
V_32 -> V_37 = 0 ;
V_32 -> V_38 = 1 ;
V_32 -> V_39 = 30000 ;
V_32 -> V_40 = 1 ;
V_32 -> V_41 = 0 ;
V_32 -> V_42 = 1 ;
V_32 -> V_43 = 1 ;
V_32 -> V_44 = 1 ;
V_32 -> V_45 = 0 ;
V_32 -> V_46 = false ;
F_7 ( V_7 -> V_47 . V_48 ,
V_49 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_50 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_51 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_52 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_53 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_54 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_55 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_56 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_57 ) ;
F_7 ( V_7 -> V_47 . V_48 ,
V_58 ) ;
F_8 ( V_7 -> V_47 . V_48 ,
V_59 ) ;
V_35 . V_60 = sizeof( struct V_34 ) ;
V_35 . V_61 = V_62 ;
V_36 = F_9 ( V_7 -> V_63 , & V_35 ) ;
if ( ! V_36 ) {
if ( V_35 . V_64 & V_65 )
F_8 ( V_7 -> V_47 . V_48 ,
V_56 ) ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_66 * V_67 )
{
return 0 ;
}
static int F_11 (
struct V_6 * V_7 )
{
T_1 V_8 =
sizeof( struct V_68 ) +
( 7 * sizeof( struct V_69 ) ) ;
struct V_68 * V_70 =
F_5 ( V_8 , V_17 ) ;
if ( NULL == V_70 ) {
F_12 ( L_1 ) ;
return - V_18 ;
}
V_70 -> V_71 = 8 ;
V_70 -> V_21 [ 0 ] . V_72 = V_73 ;
V_70 -> V_21 [ 0 ] . V_74 = 0 ;
V_70 -> V_21 [ 1 ] . V_72 = V_75 ;
V_70 -> V_21 [ 1 ] . V_74 = 1 ;
V_70 -> V_21 [ 2 ] . V_72 = V_76 ;
V_70 -> V_21 [ 2 ] . V_74 = 2 ;
V_70 -> V_21 [ 3 ] . V_72 = V_77 ;
V_70 -> V_21 [ 3 ] . V_74 = 3 ;
V_70 -> V_21 [ 4 ] . V_72 = V_78 ;
V_70 -> V_21 [ 4 ] . V_74 = 4 ;
V_70 -> V_21 [ 5 ] . V_72 = V_79 ;
V_70 -> V_21 [ 5 ] . V_74 = 5 ;
V_70 -> V_21 [ 6 ] . V_72 = V_80 ;
V_70 -> V_21 [ 6 ] . V_74 = 6 ;
V_70 -> V_21 [ 7 ] . V_72 = V_81 ;
V_70 -> V_21 [ 7 ] . V_74 = 7 ;
V_7 -> V_14 . V_82 = V_70 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_32 * V_83 = (struct V_32 * ) V_7 -> V_33 ;
V_83 -> V_35 . V_84 = 5 ;
V_83 -> V_35 . V_85 = 203 ;
if ( V_83 -> V_41 == 0 )
V_83 -> V_41 = 203 ;
F_10 ( V_7 ,
& V_7 -> V_14 . V_86 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , void * V_87 ,
void * V_88 , void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_90 V_91 = { 0 } ;
struct V_92 V_93 ;
V_91 . V_94 = V_7 -> V_95 . V_96 ;
V_91 . V_97 = V_7 -> V_95 . V_98 ;
V_93 . V_99 = V_100 ;
V_93 . V_101 = V_91 . V_94 * 10 ;
if ( V_91 . V_94 == 0 && V_91 . V_97 == 0 )
V_93 . V_101 = V_83 -> V_102 ;
F_16 (!rv_display_clock_voltage_request(hwmgr, &clock_req),
L_2 , return -EINVAL) ;
if( V_83 -> V_103 && 0 != V_91 . V_97 )
F_17 ( V_7 -> V_104 ,
V_105 ,
V_91 . V_97 / 100 ) ;
if ( ( ( V_7 -> V_106 . V_107 / 100 ) != V_83 -> V_107 ) ||
( ( V_7 -> V_106 . V_108 / 100 ) != V_83 -> V_108 ) ) {
V_83 -> V_107 = V_7 -> V_106 . V_107 / 100 ;
V_83 -> V_108 = V_7 -> V_106 . V_108 / 100 ;
F_17 ( V_7 -> V_104 ,
V_109 ,
( V_83 -> V_107 << 16 ) | V_83 -> V_107 ) ;
}
if( ( V_7 -> V_110 . V_111 != 0 ) &&
( ( V_7 -> V_110 . V_111 / 100 ) != V_83 -> V_112 ) ) {
F_17 ( V_7 -> V_104 ,
V_113 ,
V_7 -> V_110 . V_111 / 100 ) ;
F_18 ( V_7 -> V_104 , & V_83 -> V_112 ) ;
}
if ( ( V_7 -> V_110 . V_114 != 0 ) &&
( V_83 -> V_115 != ( V_7 -> V_110 . V_114 ) ) ) {
F_17 ( V_7 -> V_104 ,
V_116 ,
V_7 -> V_110 . V_114 / 100 ) ;
F_18 ( V_7 -> V_104 , & V_83 -> V_115 ) ;
}
if ( ( V_7 -> V_110 . V_117 != 0 ) &&
( V_83 -> V_118 != ( V_7 -> V_110 . V_117 / 100 ) ) ) {
F_17 ( V_7 -> V_104 ,
V_119 ,
V_7 -> V_110 . V_117 / 100 ) ;
F_18 ( V_7 -> V_104 , & V_83 -> V_118 ) ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , void * V_87 ,
void * V_88 , void * V_89 , int V_36 )
{
T_1 V_120 = 0 ;
struct V_121 V_122 = { 0 } ;
F_20 ( V_7 -> V_63 , & V_122 ) ;
V_120 = V_122 . V_123 ;
F_17 ( V_7 -> V_104 ,
V_124 ,
V_120 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 , void * V_87 ,
void * V_88 , void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
V_83 -> V_125 = true ;
V_83 -> V_126 = true ;
V_83 -> V_127 = true ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 ,
void * V_87 , void * V_88 ,
void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
V_83 -> V_128 = 0 ;
V_83 -> V_129 = false ;
V_83 -> V_130 = false ;
V_83 -> V_131 = false ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
void * V_87 , void * V_88 ,
void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
if ( V_83 -> V_46 )
F_24 ( V_7 -> V_104 ,
V_132 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
void * V_87 , void * V_88 ,
void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
if ( V_83 -> V_46 )
F_24 ( V_7 -> V_104 ,
V_133 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
struct V_134 * V_135 ,
const struct V_134 * V_136 )
{
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_137 * * V_138 ,
T_1 V_139 , T_2 * V_140 )
{
T_1 V_8 , V_9 ;
struct V_137 * V_11 ;
V_8 = sizeof( T_1 ) + sizeof( struct V_137 ) * V_139 ;
V_11 = F_5 ( V_8 , V_17 ) ;
if ( NULL == V_11 )
return - V_18 ;
V_11 -> V_71 = V_139 ;
for ( V_9 = 0 ; V_9 < V_11 -> V_71 ; V_9 ++ ) {
V_11 -> V_21 [ V_9 ] . V_72 = V_140 -> V_141 * 100 ;
V_11 -> V_21 [ V_9 ] . V_142 = V_140 -> V_143 ;
V_140 ++ ;
}
* V_138 = V_11 ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
int V_36 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
T_3 * V_67 = & ( V_83 -> V_144 ) ;
struct V_145 * V_146 = & ( V_83 -> V_147 ) ;
V_36 = F_29 ( V_7 -> V_104 , ( V_20 * ) V_67 , V_148 ) ;
F_16 ((0 == result),
L_3 ,
return result) ;
if ( 0 == V_36 && V_67 -> V_149 [ 0 ] . V_141 != 0 ) {
F_27 ( V_7 , & V_146 -> V_150 ,
V_151 ,
& V_83 -> V_144 . V_149 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_152 ,
V_153 ,
& V_83 -> V_144 . V_154 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_155 ,
V_156 ,
& V_83 -> V_144 . V_157 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_158 ,
V_159 ,
& V_83 -> V_144 . V_160 [ 0 ] ) ;
} else {
F_27 ( V_7 , & V_146 -> V_150 ,
F_4 ( V_161 ) ,
& V_161 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_152 ,
F_4 ( V_162 ) ,
& V_162 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_155 ,
F_4 ( V_163 ) ,
& V_163 [ 0 ] ) ;
}
F_27 ( V_7 , & V_146 -> V_164 ,
F_4 ( V_165 ) ,
& V_165 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_166 ,
F_4 ( V_167 ) , & V_167 [ 0 ] ) ;
F_27 ( V_7 , & V_146 -> V_168 ,
F_4 ( V_169 ) , & V_169 [ 0 ] ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_36 = 0 ;
struct V_32 * V_170 ;
V_170 = F_5 ( sizeof( struct V_32 ) , V_17 ) ;
if ( V_170 == NULL )
return - V_18 ;
V_7 -> V_33 = V_170 ;
V_36 = F_6 ( V_7 ) ;
if ( V_36 != 0 ) {
F_12 ( L_4 ) ;
return V_36 ;
}
F_8 ( V_7 -> V_47 . V_48 ,
V_171 ) ;
F_28 ( V_7 ) ;
V_36 = F_13 ( V_7 ) ;
if ( V_36 != 0 ) {
F_12 ( L_5 ) ;
return V_36 ;
}
F_14 ( V_7 ) ;
V_36 = F_31 ( V_7 , & V_172 ,
& ( V_7 -> V_173 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_6 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_174 ,
& ( V_7 -> V_175 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_7 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_176 ,
& ( V_7 -> V_177 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_8 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_178 ,
& ( V_7 -> V_179 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_9 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_180 ,
& ( V_7 -> V_181 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_10 ) ;
return V_36 ;
}
V_7 -> V_47 . V_182 =
V_183 ;
V_7 -> V_47 . V_184 =
V_183 ;
V_7 -> V_47 . V_185 = 0 ;
V_7 -> V_47 . V_186 . V_187 = 500 ;
V_7 -> V_47 . V_186 . V_188 = 500 ;
V_7 -> V_47 . V_189 = 50 ;
F_3 ( V_7 ) ;
return V_36 ;
}
static int F_32 ( struct V_6 * V_7 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_145 * V_146 = & ( V_83 -> V_147 ) ;
F_33 ( V_7 , & ( V_7 -> V_177 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_181 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_179 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_175 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_173 ) ) ;
if ( V_146 -> V_150 ) {
F_34 ( V_146 -> V_150 ) ;
V_146 -> V_150 = NULL ;
}
if ( V_146 -> V_152 ) {
F_34 ( V_146 -> V_152 ) ;
V_146 -> V_152 = NULL ;
}
if ( V_146 -> V_155 ) {
F_34 ( V_146 -> V_155 ) ;
V_146 -> V_155 = NULL ;
}
if ( V_146 -> V_164 ) {
F_34 ( V_146 -> V_164 ) ;
V_146 -> V_164 = NULL ;
}
if ( V_146 -> V_166 ) {
F_34 ( V_146 -> V_166 ) ;
V_146 -> V_166 = NULL ;
}
if ( V_146 -> V_168 ) {
F_34 ( V_146 -> V_168 ) ;
V_146 -> V_168 = NULL ;
}
if ( NULL != V_7 -> V_14 . V_82 ) {
F_34 ( V_7 -> V_14 . V_82 ) ;
V_7 -> V_14 . V_82 = NULL ;
}
if ( NULL != V_7 -> V_14 . V_15 ) {
F_34 ( V_7 -> V_14 . V_15 ) ;
V_7 -> V_14 . V_15 = NULL ;
}
F_34 ( V_7 -> V_33 ) ;
V_7 -> V_33 = NULL ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 ,
enum V_190 V_191 )
{
return 0 ;
}
static int F_36 ( struct V_6 * V_7 , bool V_192 )
{
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , bool V_192 )
{
return 0 ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
return 0 ;
}
static int F_39 (
struct V_6 * V_7 ,
struct V_2 * V_3 ,
unsigned int V_193 ,
const void * V_194 )
{
struct V_1 * V_195 = F_1 ( V_3 ) ;
const T_4 * V_196 = V_194 ;
struct V_68 * V_67 =
V_7 -> V_14 . V_197 ;
V_20 V_198 = V_196 -> V_193 ;
if ( V_198 > ( V_20 ) ( V_7 -> V_47 . V_182 - 1 ) )
V_198 = ( V_20 ) ( V_7 -> V_47 . V_182 - 1 ) ;
V_195 -> V_199 [ V_193 ] . V_200 = V_67 -> V_21 [ V_198 ] . V_72 ;
V_195 -> V_199 [ V_193 ] . V_201 = ( V_20 ) V_67 -> V_21 [ V_198 ] . V_74 ;
V_195 -> V_191 = V_193 + 1 ;
if ( F_40 ( V_7 -> V_47 . V_48 , V_55 ) ) {
V_195 -> V_199 [ V_193 ] . V_202 = 5 ;
V_195 -> V_199 [ V_193 ] . V_203 = 5 ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
int V_36 ;
unsigned long V_204 = 0 ;
V_36 = F_42 ( V_7 , & V_204 ) ;
return V_36 ? 0 : V_204 ;
}
static int F_43 ( struct V_6 * V_7 ,
unsigned long V_205 , struct V_134 * V_206 )
{
int V_36 ;
struct V_1 * V_195 ;
V_206 -> V_207 . V_5 = V_4 ;
V_195 = F_1 ( & ( V_206 -> V_207 ) ) ;
V_36 = F_44 ( V_7 , V_205 , V_206 ,
F_39 ) ;
V_195 -> V_208 . V_209 = V_206 -> V_208 . V_210 ;
V_195 -> V_208 . V_211 = V_206 -> V_208 . V_212 ;
return V_36 ;
}
static int F_45 ( struct V_6 * V_7 )
{
return sizeof( struct V_1 ) ;
}
static int F_46 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_47 ( struct V_6 * V_7 , T_1 V_128 ,
bool V_129 , bool V_130 , bool V_213 )
{
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_214 * V_122 )
{
return - V_215 ;
}
static int F_49 ( struct V_6 * V_7 ,
enum V_216 type , T_1 V_217 )
{
return 0 ;
}
static int F_50 ( struct V_6 * V_7 ,
enum V_216 type , char * V_218 )
{
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , const struct V_2 * V_219 ,
T_5 V_220 , T_1 V_193 ,
T_6 * V_191 )
{
const struct V_1 * V_206 ;
struct V_32 * V_170 ;
T_1 V_221 ;
T_1 V_9 ;
T_1 V_222 = 0 ;
if ( V_191 == NULL || V_7 == NULL || V_219 == NULL )
return - V_215 ;
V_170 = (struct V_32 * ) ( V_7 -> V_33 ) ;
V_206 = F_2 ( V_219 ) ;
V_221 = V_193 > V_206 -> V_191 - 1 ? V_206 -> V_191 - 1 : V_193 ;
V_191 -> V_223 = V_206 -> V_199 [ V_221 ] . V_200 ;
if ( V_220 == V_224 ) {
for ( V_9 = 1 ; V_9 < V_206 -> V_191 ; V_9 ++ ) {
if ( V_206 -> V_199 [ V_9 ] . V_200 > V_170 -> V_39 ) {
V_191 -> V_223 = V_206 -> V_199 [ V_9 ] . V_200 ;
break;
}
}
}
if ( V_221 == 0 ) {
V_222 = V_170 -> V_147 . V_155 -> V_71 - 1 ;
V_191 -> V_225 =
V_170 -> V_147 . V_155 -> V_21 [ V_222 ] . V_72 ;
} else
V_191 -> V_225 = V_170 -> V_147 . V_155 -> V_21 [ 0 ] . V_72 ;
V_191 -> V_226 = 0 ;
V_191 -> V_227 = 0 ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 ,
const struct V_2 * V_219 , struct V_228 * V_194 )
{
const struct V_1 * V_206 = F_2 ( V_219 ) ;
V_194 -> V_229 = V_206 -> V_199 [ 0 ] . V_200 / ( 1 << ( V_206 -> V_199 [ 0 ] . V_203 ) ) ;
V_194 -> V_230 = V_206 -> V_199 [ V_206 -> V_191 - 1 ] . V_200 / ( 1 << ( V_206 -> V_199 [ V_206 -> V_191 - 1 ] . V_203 ) ) ;
return 0 ;
}
static T_1 F_53 ( struct V_6 * V_7 ,
T_1 clock )
{
if ( clock >= V_231 &&
clock < V_232 )
return V_233 ;
else if ( clock >= V_232 )
return V_234 ;
else
return V_235 ;
}
static int F_54 ( struct V_6 * V_7 ,
enum V_236 type ,
struct V_237 * V_91 )
{
T_1 V_9 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_145 * V_146 = & ( V_83 -> V_147 ) ;
struct V_137 * V_238 ;
bool V_239 = false ;
if ( V_146 == NULL )
return - V_215 ;
switch ( type ) {
case V_240 :
V_238 = V_146 -> V_158 ;
V_239 = true ;
break;
case V_241 :
V_238 = V_146 -> V_155 ;
V_239 = true ;
break;
case V_100 :
V_238 = V_146 -> V_150 ;
break;
case V_242 :
V_238 = V_146 -> V_164 ;
break;
case V_243 :
V_238 = V_146 -> V_168 ;
break;
case V_244 :
V_238 = V_146 -> V_166 ;
default:
return - V_215 ;
}
if ( V_238 == NULL || V_238 -> V_71 == 0 )
return - V_215 ;
V_91 -> V_245 = 0 ;
for ( V_9 = 0 ; V_9 < V_238 -> V_71 ; V_9 ++ ) {
V_91 -> V_170 [ V_9 ] . V_246 = V_238 -> V_21 [ V_9 ] . V_72 ;
V_91 -> V_170 [ V_9 ] . V_247 = V_239 ?
F_53 ( V_7 ,
V_238 -> V_21 [ V_9 ] . V_72 ) :
0 ;
V_91 -> V_245 ++ ;
}
return 0 ;
}
static int F_55 ( struct V_6 * V_7 ,
enum V_236 type ,
struct V_248 * V_91 )
{
T_1 V_9 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_145 * V_146 = & ( V_83 -> V_147 ) ;
struct V_137 * V_238 = NULL ;
if ( V_146 == NULL )
return - V_215 ;
switch ( type ) {
case V_240 :
V_238 = V_146 -> V_158 ;
break;
case V_241 :
V_238 = V_146 -> V_155 ;
break;
case V_100 :
V_238 = V_146 -> V_150 ;
break;
case V_249 :
V_238 = V_146 -> V_152 ;
break;
default:
return - V_215 ;
}
if ( V_238 == NULL || V_238 -> V_71 == 0 )
return - V_215 ;
V_91 -> V_245 = 0 ;
for ( V_9 = 0 ; V_9 < V_238 -> V_71 ; V_9 ++ ) {
V_91 -> V_170 [ V_9 ] . V_246 = V_238 -> V_21 [ V_9 ] . V_72 ;
V_91 -> V_170 [ V_9 ] . V_250 = V_238 -> V_21 [ V_9 ] . V_142 ;
V_91 -> V_245 ++ ;
}
return 0 ;
}
int F_56 ( struct V_6 * V_7 ,
struct V_92 * V_93 )
{
int V_36 = 0 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
enum V_236 V_251 = V_93 -> V_99 ;
T_1 V_252 = V_93 -> V_101 / 1000 ;
T_7 V_253 ;
switch ( V_251 ) {
case V_100 :
if ( V_252 == V_83 -> V_102 )
return 0 ;
V_253 = V_254 ;
V_83 -> V_102 = V_252 ;
break;
case V_249 :
V_253 = V_113 ;
break;
case V_241 :
if ( V_252 == V_83 -> V_255 )
return 0 ;
V_83 -> V_255 = V_252 ;
V_253 = V_256 ;
break;
default:
F_57 ( L_11 ) ;
return - V_215 ;
}
V_36 = F_17 ( V_7 -> V_104 , V_253 ,
V_252 ) ;
return V_36 ;
}
static int F_58 ( struct V_6 * V_7 , struct V_214 * V_91 )
{
return - V_215 ;
}
static int F_59 ( struct V_6 * V_7 )
{
T_1 V_257 = F_60 ( V_258 , 0 ,
V_259 , V_260 ) ;
T_1 V_261 = F_61 ( V_7 -> V_63 , V_257 ) ;
int V_262 =
( V_261 & V_263 ) >> V_264 ;
if ( V_262 & V_265 )
V_262 = ( ( V_262 / 8 ) - 49 ) * V_266 ;
else
V_262 = ( V_262 / 8 ) * V_266 ;
return V_262 ;
}
static int F_62 ( struct V_6 * V_7 , int V_267 ,
void * V_64 , int * V_60 )
{
switch ( V_267 ) {
case V_268 :
* ( ( T_1 * ) V_64 ) = F_59 ( V_7 ) ;
return 0 ;
default:
return - V_215 ;
}
}
int F_63 ( struct V_6 * V_7 )
{
V_7 -> V_269 = & V_270 ;
V_7 -> V_271 = & V_272 ;
return 0 ;
}
