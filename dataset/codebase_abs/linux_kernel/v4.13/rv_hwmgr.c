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
if( ( V_7 -> V_106 . V_107 != 0 ) &&
( ( V_7 -> V_106 . V_107 / 100 ) != V_83 -> V_108 ) ) {
F_17 ( V_7 -> V_104 ,
V_109 ,
V_7 -> V_106 . V_107 / 100 ) ;
F_18 ( V_7 -> V_104 , & V_83 -> V_108 ) ;
}
if ( ( V_7 -> V_106 . V_110 != 0 ) &&
( V_83 -> V_111 != ( V_7 -> V_106 . V_110 ) ) ) {
F_17 ( V_7 -> V_104 ,
V_112 ,
V_7 -> V_106 . V_110 / 100 ) ;
F_18 ( V_7 -> V_104 , & V_83 -> V_111 ) ;
}
if ( ( V_7 -> V_106 . V_113 != 0 ) &&
( V_83 -> V_114 != ( V_7 -> V_106 . V_113 / 100 ) ) ) {
F_17 ( V_7 -> V_104 ,
V_115 ,
V_7 -> V_106 . V_113 / 100 ) ;
F_18 ( V_7 -> V_104 , & V_83 -> V_114 ) ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , void * V_87 ,
void * V_88 , void * V_89 , int V_36 )
{
T_1 V_116 = 0 ;
struct V_117 V_118 = { 0 } ;
F_20 ( V_7 -> V_63 , & V_118 ) ;
V_116 = V_118 . V_119 ;
F_17 ( V_7 -> V_104 ,
V_120 ,
V_116 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 , void * V_87 ,
void * V_88 , void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
V_83 -> V_121 = true ;
V_83 -> V_122 = true ;
V_83 -> V_123 = true ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 ,
void * V_87 , void * V_88 ,
void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
V_83 -> V_124 = 0 ;
V_83 -> V_125 = false ;
V_83 -> V_126 = false ;
V_83 -> V_127 = false ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
void * V_87 , void * V_88 ,
void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
if ( V_83 -> V_46 )
F_24 ( V_7 -> V_104 ,
V_128 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
void * V_87 , void * V_88 ,
void * V_89 , int V_36 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
if ( V_83 -> V_46 )
F_24 ( V_7 -> V_104 ,
V_129 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
struct V_130 * V_131 ,
const struct V_130 * V_132 )
{
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_133 * * V_134 ,
T_1 V_135 , T_2 * V_136 )
{
T_1 V_8 , V_9 ;
struct V_133 * V_11 ;
V_8 = sizeof( T_1 ) + sizeof( struct V_133 ) * V_135 ;
V_11 = F_5 ( V_8 , V_17 ) ;
if ( NULL == V_11 )
return - V_18 ;
V_11 -> V_71 = V_135 ;
for ( V_9 = 0 ; V_9 < V_11 -> V_71 ; V_9 ++ ) {
V_11 -> V_21 [ V_9 ] . V_72 = V_136 -> V_137 * 100 ;
V_11 -> V_21 [ V_9 ] . V_138 = V_136 -> V_139 ;
V_136 ++ ;
}
* V_134 = V_11 ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
int V_36 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
T_3 * V_67 = & ( V_83 -> V_140 ) ;
struct V_141 * V_142 = & ( V_83 -> V_143 ) ;
V_36 = F_29 ( V_7 -> V_104 , ( V_20 * ) V_67 , V_144 ) ;
F_16 ((0 == result),
L_3 ,
return result) ;
if ( 0 == V_36 && V_67 -> V_145 [ 0 ] . V_137 != 0 ) {
F_27 ( V_7 , & V_142 -> V_146 ,
V_147 ,
& V_83 -> V_140 . V_145 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_148 ,
V_149 ,
& V_83 -> V_140 . V_150 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_151 ,
V_152 ,
& V_83 -> V_140 . V_153 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_154 ,
V_155 ,
& V_83 -> V_140 . V_156 [ 0 ] ) ;
} else {
F_27 ( V_7 , & V_142 -> V_146 ,
F_4 ( V_157 ) ,
& V_157 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_148 ,
F_4 ( V_158 ) ,
& V_158 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_151 ,
F_4 ( V_159 ) ,
& V_159 [ 0 ] ) ;
}
F_27 ( V_7 , & V_142 -> V_160 ,
F_4 ( V_161 ) ,
& V_161 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_162 ,
F_4 ( V_163 ) , & V_163 [ 0 ] ) ;
F_27 ( V_7 , & V_142 -> V_164 ,
F_4 ( V_165 ) , & V_165 [ 0 ] ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_36 = 0 ;
struct V_32 * V_166 ;
V_166 = F_5 ( sizeof( struct V_32 ) , V_17 ) ;
if ( V_166 == NULL )
return - V_18 ;
V_7 -> V_33 = V_166 ;
V_36 = F_6 ( V_7 ) ;
if ( V_36 != 0 ) {
F_12 ( L_4 ) ;
return V_36 ;
}
F_8 ( V_7 -> V_47 . V_48 ,
V_167 ) ;
F_28 ( V_7 ) ;
V_36 = F_13 ( V_7 ) ;
if ( V_36 != 0 ) {
F_12 ( L_5 ) ;
return V_36 ;
}
F_14 ( V_7 ) ;
V_36 = F_31 ( V_7 , & V_168 ,
& ( V_7 -> V_169 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_6 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_170 ,
& ( V_7 -> V_171 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_7 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_172 ,
& ( V_7 -> V_173 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_8 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_174 ,
& ( V_7 -> V_175 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_9 ) ;
return V_36 ;
}
V_36 = F_31 ( V_7 , & V_176 ,
& ( V_7 -> V_177 ) ) ;
if ( V_36 != 0 ) {
F_12 ( L_10 ) ;
return V_36 ;
}
V_7 -> V_47 . V_178 =
V_179 ;
V_7 -> V_47 . V_180 =
V_179 ;
V_7 -> V_47 . V_181 = 0 ;
V_7 -> V_47 . V_182 . V_183 = 500 ;
V_7 -> V_47 . V_182 . V_184 = 500 ;
V_7 -> V_47 . V_185 = 50 ;
F_3 ( V_7 ) ;
return V_36 ;
}
static int F_32 ( struct V_6 * V_7 )
{
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_141 * V_142 = & ( V_83 -> V_143 ) ;
F_33 ( V_7 , & ( V_7 -> V_173 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_177 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_175 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_171 ) ) ;
F_33 ( V_7 , & ( V_7 -> V_169 ) ) ;
if ( V_142 -> V_146 ) {
F_34 ( V_142 -> V_146 ) ;
V_142 -> V_146 = NULL ;
}
if ( V_142 -> V_148 ) {
F_34 ( V_142 -> V_148 ) ;
V_142 -> V_148 = NULL ;
}
if ( V_142 -> V_151 ) {
F_34 ( V_142 -> V_151 ) ;
V_142 -> V_151 = NULL ;
}
if ( V_142 -> V_160 ) {
F_34 ( V_142 -> V_160 ) ;
V_142 -> V_160 = NULL ;
}
if ( V_142 -> V_162 ) {
F_34 ( V_142 -> V_162 ) ;
V_142 -> V_162 = NULL ;
}
if ( V_142 -> V_164 ) {
F_34 ( V_142 -> V_164 ) ;
V_142 -> V_164 = NULL ;
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
enum V_186 V_187 )
{
return 0 ;
}
static int F_36 ( struct V_6 * V_7 , bool V_188 )
{
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , bool V_188 )
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
unsigned int V_189 ,
const void * V_190 )
{
struct V_1 * V_191 = F_1 ( V_3 ) ;
const T_4 * V_192 = V_190 ;
struct V_68 * V_67 =
V_7 -> V_14 . V_193 ;
V_20 V_194 = V_192 -> V_189 ;
if ( V_194 > ( V_20 ) ( V_7 -> V_47 . V_178 - 1 ) )
V_194 = ( V_20 ) ( V_7 -> V_47 . V_178 - 1 ) ;
V_191 -> V_195 [ V_189 ] . V_196 = V_67 -> V_21 [ V_194 ] . V_72 ;
V_191 -> V_195 [ V_189 ] . V_197 = ( V_20 ) V_67 -> V_21 [ V_194 ] . V_74 ;
V_191 -> V_187 = V_189 + 1 ;
if ( F_40 ( V_7 -> V_47 . V_48 , V_55 ) ) {
V_191 -> V_195 [ V_189 ] . V_198 = 5 ;
V_191 -> V_195 [ V_189 ] . V_199 = 5 ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
int V_36 ;
unsigned long V_200 = 0 ;
V_36 = F_42 ( V_7 , & V_200 ) ;
return V_36 ? 0 : V_200 ;
}
static int F_43 ( struct V_6 * V_7 ,
unsigned long V_201 , struct V_130 * V_202 )
{
int V_36 ;
struct V_1 * V_191 ;
V_202 -> V_203 . V_5 = V_4 ;
V_191 = F_1 ( & ( V_202 -> V_203 ) ) ;
V_36 = F_44 ( V_7 , V_201 , V_202 ,
F_39 ) ;
V_191 -> V_204 . V_205 = V_202 -> V_204 . V_206 ;
V_191 -> V_204 . V_207 = V_202 -> V_204 . V_208 ;
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
static int F_47 ( struct V_6 * V_7 , T_1 V_124 ,
bool V_125 , bool V_126 , bool V_209 )
{
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_210 * V_118 )
{
return - V_211 ;
}
static int F_49 ( struct V_6 * V_7 ,
enum V_212 type , T_1 V_213 )
{
return 0 ;
}
static int F_50 ( struct V_6 * V_7 ,
enum V_212 type , char * V_214 )
{
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , const struct V_2 * V_215 ,
T_5 V_216 , T_1 V_189 ,
T_6 * V_187 )
{
const struct V_1 * V_202 ;
struct V_32 * V_166 ;
T_1 V_217 ;
T_1 V_9 ;
T_1 V_218 = 0 ;
if ( V_187 == NULL || V_7 == NULL || V_215 == NULL )
return - V_211 ;
V_166 = (struct V_32 * ) ( V_7 -> V_33 ) ;
V_202 = F_2 ( V_215 ) ;
V_217 = V_189 > V_202 -> V_187 - 1 ? V_202 -> V_187 - 1 : V_189 ;
V_187 -> V_219 = V_202 -> V_195 [ V_217 ] . V_196 ;
if ( V_216 == V_220 ) {
for ( V_9 = 1 ; V_9 < V_202 -> V_187 ; V_9 ++ ) {
if ( V_202 -> V_195 [ V_9 ] . V_196 > V_166 -> V_39 ) {
V_187 -> V_219 = V_202 -> V_195 [ V_9 ] . V_196 ;
break;
}
}
}
if ( V_217 == 0 ) {
V_218 = V_166 -> V_143 . V_151 -> V_71 - 1 ;
V_187 -> V_221 =
V_166 -> V_143 . V_151 -> V_21 [ V_218 ] . V_72 ;
} else
V_187 -> V_221 = V_166 -> V_143 . V_151 -> V_21 [ 0 ] . V_72 ;
V_187 -> V_222 = 0 ;
V_187 -> V_223 = 0 ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 ,
const struct V_2 * V_215 , struct V_224 * V_190 )
{
const struct V_1 * V_202 = F_2 ( V_215 ) ;
V_190 -> V_225 = V_202 -> V_195 [ 0 ] . V_196 / ( 1 << ( V_202 -> V_195 [ 0 ] . V_199 ) ) ;
V_190 -> V_226 = V_202 -> V_195 [ V_202 -> V_187 - 1 ] . V_196 / ( 1 << ( V_202 -> V_195 [ V_202 -> V_187 - 1 ] . V_199 ) ) ;
return 0 ;
}
static T_1 F_53 ( struct V_6 * V_7 ,
T_1 clock )
{
if ( clock >= V_227 &&
clock < V_228 )
return V_229 ;
else if ( clock >= V_228 )
return V_230 ;
else
return V_231 ;
}
static int F_54 ( struct V_6 * V_7 ,
enum V_232 type ,
struct V_233 * V_91 )
{
T_1 V_9 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_141 * V_142 = & ( V_83 -> V_143 ) ;
struct V_133 * V_234 ;
bool V_235 = false ;
if ( V_142 == NULL )
return - V_211 ;
switch ( type ) {
case V_236 :
V_234 = V_142 -> V_154 ;
V_235 = true ;
break;
case V_237 :
V_234 = V_142 -> V_151 ;
V_235 = true ;
break;
case V_100 :
V_234 = V_142 -> V_146 ;
break;
case V_238 :
V_234 = V_142 -> V_160 ;
break;
case V_239 :
V_234 = V_142 -> V_164 ;
break;
case V_240 :
V_234 = V_142 -> V_162 ;
default:
return - V_211 ;
}
if ( V_234 == NULL || V_234 -> V_71 == 0 )
return - V_211 ;
V_91 -> V_241 = 0 ;
for ( V_9 = 0 ; V_9 < V_234 -> V_71 ; V_9 ++ ) {
V_91 -> V_166 [ V_9 ] . V_242 = V_234 -> V_21 [ V_9 ] . V_72 ;
V_91 -> V_166 [ V_9 ] . V_243 = V_235 ?
F_53 ( V_7 ,
V_234 -> V_21 [ V_9 ] . V_72 ) :
0 ;
V_91 -> V_241 ++ ;
}
return 0 ;
}
static int F_55 ( struct V_6 * V_7 ,
enum V_232 type ,
struct V_244 * V_91 )
{
T_1 V_9 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
struct V_141 * V_142 = & ( V_83 -> V_143 ) ;
struct V_133 * V_234 = NULL ;
if ( V_142 == NULL )
return - V_211 ;
switch ( type ) {
case V_236 :
V_234 = V_142 -> V_154 ;
break;
case V_237 :
V_234 = V_142 -> V_151 ;
break;
case V_100 :
V_234 = V_142 -> V_146 ;
break;
case V_245 :
V_234 = V_142 -> V_148 ;
break;
default:
return - V_211 ;
}
if ( V_234 == NULL || V_234 -> V_71 == 0 )
return - V_211 ;
V_91 -> V_241 = 0 ;
for ( V_9 = 0 ; V_9 < V_234 -> V_71 ; V_9 ++ ) {
V_91 -> V_166 [ V_9 ] . V_242 = V_234 -> V_21 [ V_9 ] . V_72 ;
V_91 -> V_166 [ V_9 ] . V_246 = V_234 -> V_21 [ V_9 ] . V_138 ;
V_91 -> V_241 ++ ;
}
return 0 ;
}
int F_56 ( struct V_6 * V_7 ,
struct V_92 * V_93 )
{
int V_36 = 0 ;
struct V_32 * V_83 = (struct V_32 * ) ( V_7 -> V_33 ) ;
enum V_232 V_247 = V_93 -> V_99 ;
T_1 V_248 = V_93 -> V_101 / 1000 ;
T_7 V_249 ;
switch ( V_247 ) {
case V_100 :
if ( V_248 == V_83 -> V_102 )
return 0 ;
V_249 = V_250 ;
V_83 -> V_102 = V_248 ;
break;
case V_245 :
V_249 = V_109 ;
break;
case V_237 :
if ( V_248 == V_83 -> V_251 )
return 0 ;
V_83 -> V_251 = V_248 ;
V_249 = V_252 ;
break;
default:
F_57 ( L_11 ) ;
return - V_211 ;
}
V_36 = F_17 ( V_7 -> V_104 , V_249 ,
V_248 ) ;
return V_36 ;
}
static int F_58 ( struct V_6 * V_7 , struct V_210 * V_91 )
{
return - V_211 ;
}
static int F_59 ( struct V_6 * V_7 )
{
T_1 V_253 = F_60 ( V_254 , 0 ,
V_255 , V_256 ) ;
T_1 V_257 = F_61 ( V_7 -> V_63 , V_253 ) ;
int V_258 =
( V_257 & V_259 ) >> V_260 ;
if ( V_258 & V_261 )
V_258 = ( ( V_258 / 8 ) - 49 ) * V_262 ;
else
V_258 = ( V_258 / 8 ) * V_262 ;
return V_258 ;
}
static int F_62 ( struct V_6 * V_7 , int V_263 ,
void * V_64 , int * V_60 )
{
switch ( V_263 ) {
case V_264 :
* ( ( T_1 * ) V_64 ) = F_59 ( V_7 ) ;
return 0 ;
default:
return - V_211 ;
}
}
int F_63 ( struct V_6 * V_7 )
{
V_7 -> V_265 = & V_266 ;
V_7 -> V_267 = & V_268 ;
return 0 ;
}
