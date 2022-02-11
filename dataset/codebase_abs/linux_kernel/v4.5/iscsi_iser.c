void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , int V_6 )
{
int V_7 = 0 ;
int V_8 ;
V_8 = F_2 ( V_4 -> V_9 ) ;
if ( V_8 > V_6 || ( V_8 + 4 ) < V_6 ) {
F_3 ( L_1 ,
V_8 , V_6 ) ;
V_7 = V_10 ;
goto error;
}
if ( V_8 != V_6 )
F_4 ( L_2 ,
V_8 , V_6 ) ;
V_7 = F_5 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( V_7 && V_7 != V_11 )
goto error;
return;
error:
F_6 ( V_2 , V_7 ) ;
}
static int
F_7 ( struct V_12 * V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
V_13 -> V_4 = (struct V_3 * ) & V_16 -> V_18 . V_19 ;
V_13 -> V_20 = sizeof( V_16 -> V_18 . V_19 ) ;
return 0 ;
}
int
F_8 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_23 * V_23 = V_13 -> V_2 -> V_17 ;
struct V_24 * V_25 = V_23 -> V_26 . V_25 ;
struct V_15 * V_16 = V_13 -> V_17 ;
T_2 V_27 ;
const bool V_28 = ! V_13 -> V_29 && ! F_9 () ;
int V_30 = 0 ;
if ( F_10 ( V_28 ) )
F_11 ( & V_23 -> V_31 ) ;
if ( F_10 ( V_23 -> V_32 != V_33 ) ) {
V_30 = - V_34 ;
goto V_35;
}
V_27 = F_12 ( V_25 -> V_36 , ( void * ) V_22 ,
V_37 , V_38 ) ;
if ( F_13 ( V_25 -> V_36 , V_27 ) ) {
V_30 = - V_39 ;
goto V_35;
}
V_22 -> V_40 = 0 ;
V_22 -> V_41 = true ;
V_22 -> V_27 = V_27 ;
V_22 -> V_42 [ 0 ] . V_43 = V_22 -> V_27 ;
V_22 -> V_42 [ 0 ] . V_44 = V_37 ;
V_22 -> V_42 [ 0 ] . V_45 = V_25 -> V_46 -> V_47 ;
V_16 -> V_23 = V_23 ;
V_35:
if ( F_10 ( V_28 ) )
F_14 ( & V_23 -> V_31 ) ;
return V_30 ;
}
static int
F_15 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_30 ;
V_30 = F_8 ( V_13 , & V_16 -> V_18 ) ;
if ( V_30 ) {
F_3 ( L_3 ,
V_16 , V_30 ) ;
return V_30 ;
}
if ( ! V_13 -> V_29 )
return 0 ;
V_16 -> V_48 = 0 ;
F_16 ( V_16 ) ;
V_16 -> V_29 = V_13 -> V_29 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int error = 0 ;
F_4 ( L_4 , V_2 -> V_49 , V_13 -> V_50 ) ;
error = F_18 ( V_2 , V_13 ) ;
return error ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_51 * V_52 = & V_13 -> V_53 ;
struct V_54 V_4 ;
int error = 0 ;
while ( F_20 ( V_13 ) ) {
F_21 ( V_13 , V_52 , & V_4 ) ;
F_4 ( L_5 ,
V_4 . V_50 , V_52 -> V_55 ) ;
error = F_22 ( V_2 , V_13 , & V_4 ) ;
if ( error ) {
V_52 -> V_56 -- ;
goto V_57;
}
V_52 -> V_58 += V_52 -> V_55 ;
F_4 ( L_6 ,
V_52 -> V_59 - V_52 -> V_58 ) ;
}
V_57:
return error ;
}
static int
F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_15 * V_16 = V_13 -> V_17 ;
int error = 0 ;
if ( ! V_13 -> V_29 )
return F_17 ( V_2 , V_13 ) ;
if ( V_13 -> V_29 -> V_60 == V_38 ) {
F_24 ( F_25 ( V_13 -> V_29 ) == 0 ) ;
F_4 ( L_7 ,
V_13 -> V_50 , F_25 ( V_13 -> V_29 ) ,
V_13 -> V_61 , V_13 -> V_53 . V_59 ) ;
}
F_4 ( L_8 ,
V_2 -> V_49 , V_13 -> V_50 ) ;
if ( ! V_16 -> V_48 ) {
error = F_26 ( V_2 , V_13 ) ;
if ( error )
goto V_62;
V_16 -> V_48 = 1 ;
}
if ( F_20 ( V_13 ) )
error = F_19 ( V_2 , V_13 ) ;
V_62:
return error ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_21 * V_22 = & V_16 -> V_18 ;
struct V_23 * V_23 = V_13 -> V_2 -> V_17 ;
struct V_24 * V_25 = V_23 -> V_26 . V_25 ;
if ( ! V_25 )
return;
if ( F_28 ( V_22 -> V_41 ) ) {
F_29 ( V_25 -> V_36 , V_22 -> V_27 ,
V_37 , V_38 ) ;
V_22 -> V_41 = false ;
}
if ( ! V_13 -> V_29 )
return;
if ( V_16 -> V_63 == V_64 ) {
V_16 -> V_63 = V_65 ;
F_30 ( V_16 ) ;
}
}
static T_3
F_31 ( struct V_12 * V_13 , T_4 * V_66 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_16 -> V_67 [ V_68 ] )
return F_32 ( V_16 , V_68 ,
V_66 ) ;
else
return F_32 ( V_16 , V_69 ,
V_66 ) ;
}
static struct V_70 *
F_33 ( struct V_71 * V_72 ,
T_5 V_73 )
{
struct V_1 * V_2 ;
struct V_70 * V_74 ;
V_74 = F_34 ( V_72 , 0 , V_73 ) ;
if ( ! V_74 )
return NULL ;
V_2 = V_74 -> V_17 ;
V_2 -> V_75 = V_76 ;
return V_74 ;
}
static int
F_35 ( struct V_71 * V_72 ,
struct V_70 * V_74 ,
T_6 V_77 ,
int V_78 )
{
struct V_1 * V_2 = V_74 -> V_17 ;
struct V_23 * V_23 ;
struct V_79 * V_80 ;
int error ;
error = F_36 ( V_72 , V_74 , V_78 ) ;
if ( error )
return error ;
V_80 = F_37 ( V_77 ) ;
if ( ! V_80 ) {
F_3 ( L_9 ,
( unsigned long long ) V_77 ) ;
return - V_81 ;
}
V_23 = V_80 -> V_17 ;
F_11 ( & V_23 -> V_31 ) ;
if ( V_23 -> V_32 != V_33 ) {
error = - V_81 ;
F_3 ( L_10 ,
V_23 , V_23 -> V_32 ) ;
goto V_35;
}
error = F_38 ( V_23 , V_2 -> V_82 ) ;
if ( error )
goto V_35;
F_39 ( L_11 , V_2 , V_23 ) ;
V_2 -> V_17 = V_23 ;
V_23 -> V_1 = V_2 ;
V_35:
F_14 ( & V_23 -> V_31 ) ;
return error ;
}
static int
F_40 ( struct V_70 * V_74 )
{
struct V_1 * V_1 ;
struct V_23 * V_23 ;
V_1 = V_74 -> V_17 ;
V_23 = V_1 -> V_17 ;
F_41 ( & V_23 -> V_83 ) ;
return F_42 ( V_74 ) ;
}
static void
F_43 ( struct V_70 * V_74 , int V_84 )
{
struct V_1 * V_2 = V_74 -> V_17 ;
struct V_23 * V_23 = V_2 -> V_17 ;
F_39 ( L_12 , V_2 , V_23 ) ;
if ( V_23 ) {
F_11 ( & V_23 -> V_31 ) ;
F_44 ( V_23 ) ;
F_45 ( V_74 , V_84 ) ;
V_23 -> V_1 = NULL ;
V_2 -> V_17 = NULL ;
F_46 ( & V_23 -> V_83 ) ;
F_14 ( & V_23 -> V_31 ) ;
} else {
F_45 ( V_74 , V_84 ) ;
}
}
static void
F_47 ( struct V_71 * V_72 )
{
struct V_85 * V_86 = F_48 ( V_72 ) ;
F_49 ( V_72 ) ;
F_50 ( V_86 ) ;
F_51 ( V_86 ) ;
}
static inline unsigned int
F_52 ( int V_87 )
{
return ( ( V_87 & V_88 ) ?
V_89 | V_90 |
V_91 : 0 ) |
( ( V_87 & V_92 ) ?
V_93 | V_94 : 0 ) |
( ( V_87 & V_95 ) ?
V_96 | V_97 : 0 ) ;
}
static struct V_71 *
F_53 ( struct V_79 * V_80 ,
T_7 V_98 , T_7 V_99 ,
T_5 V_100 )
{
struct V_71 * V_72 ;
struct V_101 * V_82 ;
struct V_85 * V_86 ;
struct V_23 * V_23 = NULL ;
struct V_26 * V_26 ;
T_8 V_102 ;
V_86 = F_54 ( & V_103 , 0 , 0 ) ;
if ( ! V_86 )
return NULL ;
V_86 -> V_104 = V_105 ;
V_86 -> V_106 = V_99 ;
V_86 -> V_107 = V_108 ;
V_86 -> V_109 = 0 ;
V_86 -> V_110 = 0 ;
V_86 -> V_111 = 16 ;
if ( V_80 ) {
V_23 = V_80 -> V_17 ;
V_102 = V_23 -> V_102 ;
V_86 -> V_112 = V_23 -> V_113 ;
V_86 -> V_114 = V_23 -> V_115 ;
F_11 ( & V_23 -> V_31 ) ;
if ( V_23 -> V_32 != V_33 ) {
F_3 ( L_13 ,
V_23 ) ;
F_14 ( & V_23 -> V_31 ) ;
goto V_116;
}
V_26 = & V_23 -> V_26 ;
if ( V_26 -> V_117 ) {
T_9 V_118 = V_26 -> V_25 -> V_36 -> V_119 . V_120 ;
F_55 ( V_86 , F_52 ( V_118 ) ) ;
F_56 ( V_86 , V_121 |
V_122 ) ;
}
V_86 -> V_112 = F_57 (unsigned short, shost->sg_tablesize,
ib_conn->device->ib_device->attrs.max_fast_reg_page_list_len) ;
V_86 -> V_114 = F_57 (unsigned int,
1024 , (shost->sg_tablesize * PAGE_SIZE) >> 9 ) ;
if ( F_58 ( V_86 ,
V_26 -> V_25 -> V_36 -> V_123 ) ) {
F_14 ( & V_23 -> V_31 ) ;
goto V_116;
}
F_14 ( & V_23 -> V_31 ) ;
} else {
V_102 = V_124 ;
if ( F_58 ( V_86 , NULL ) )
goto V_116;
}
if ( V_98 > V_102 ) {
F_39 ( L_14 ,
V_98 , V_102 ) ;
V_98 = V_102 ;
}
V_72 = F_59 ( & V_125 , V_86 ,
V_98 , 0 ,
sizeof( struct V_15 ) ,
V_100 , 0 ) ;
if ( ! V_72 )
goto V_126;
V_82 = V_72 -> V_17 ;
V_86 -> V_127 = V_82 -> V_128 ;
return V_72 ;
V_126:
F_50 ( V_86 ) ;
V_116:
F_51 ( V_86 ) ;
return NULL ;
}
static int
F_60 ( struct V_70 * V_74 ,
enum V_129 V_130 , char * V_131 , int V_132 )
{
int V_133 ;
switch ( V_130 ) {
case V_134 :
break;
case V_135 :
sscanf ( V_131 , L_15 , & V_133 ) ;
if ( V_133 ) {
F_3 ( L_16 ) ;
return - V_136 ;
}
break;
case V_137 :
sscanf ( V_131 , L_15 , & V_133 ) ;
if ( V_133 ) {
F_3 ( L_16 ) ;
return - V_136 ;
}
break;
case V_138 :
sscanf ( V_131 , L_15 , & V_133 ) ;
if ( V_133 ) {
F_3 ( L_17 ) ;
return - V_136 ;
}
break;
case V_139 :
sscanf ( V_131 , L_15 , & V_133 ) ;
if ( V_133 ) {
F_3 ( L_18 ) ;
return - V_136 ;
}
break;
default:
return F_61 ( V_74 , V_130 , V_131 , V_132 ) ;
}
return 0 ;
}
static void
F_62 ( struct V_70 * V_74 , struct V_140 * V_141 )
{
struct V_1 * V_2 = V_74 -> V_17 ;
V_141 -> V_142 = V_2 -> V_142 ;
V_141 -> V_143 = V_2 -> V_143 ;
V_141 -> V_144 = V_2 -> V_145 ;
V_141 -> V_146 = V_2 -> V_147 ;
V_141 -> V_148 = V_2 -> V_149 ;
V_141 -> V_150 = V_2 -> V_151 ;
V_141 -> V_152 = V_2 -> V_153 ;
V_141 -> V_154 = V_2 -> V_155 ;
V_141 -> V_156 = V_2 -> V_157 ;
V_141 -> V_158 = 0 ;
}
static int F_63 ( struct V_79 * V_80 ,
enum V_129 V_130 , char * V_131 )
{
struct V_23 * V_23 = V_80 -> V_17 ;
int V_159 ;
switch ( V_130 ) {
case V_160 :
case V_161 :
if ( ! V_23 || ! V_23 -> V_26 . V_162 )
return - V_163 ;
return F_64 ( (struct V_164 * )
& V_23 -> V_26 . V_162 -> V_165 . V_43 . V_166 ,
V_130 , V_131 ) ;
break;
default:
return - V_167 ;
}
return V_159 ;
}
static struct V_79 *
F_65 ( struct V_85 * V_86 , struct V_168 * V_166 ,
int V_169 )
{
int V_170 ;
struct V_23 * V_23 ;
struct V_79 * V_80 ;
V_80 = F_66 ( 0 ) ;
if ( ! V_80 )
return F_67 ( - V_39 ) ;
V_23 = F_68 ( sizeof( * V_23 ) , V_171 ) ;
if ( ! V_23 ) {
V_170 = - V_39 ;
goto V_172;
}
V_80 -> V_17 = V_23 ;
V_23 -> V_80 = V_80 ;
F_69 ( V_23 ) ;
V_170 = F_70 ( V_23 , NULL , V_166 , V_169 ) ;
if ( V_170 )
goto V_172;
return V_80 ;
V_172:
F_71 ( V_80 ) ;
return F_67 ( V_170 ) ;
}
static int
F_72 ( struct V_79 * V_80 , int V_173 )
{
struct V_23 * V_23 = V_80 -> V_17 ;
int V_7 ;
V_7 = F_73 ( & V_23 -> V_174 ,
F_74 ( V_173 ) ) ;
if ( V_7 == 0 ) {
F_11 ( & V_23 -> V_31 ) ;
if ( V_23 -> V_32 == V_175 ||
V_23 -> V_32 == V_176 )
V_7 = - 1 ;
F_14 ( & V_23 -> V_31 ) ;
}
F_39 ( L_19 , V_23 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_75 ( struct V_79 * V_80 )
{
struct V_23 * V_23 = V_80 -> V_17 ;
F_39 ( L_20 , V_80 , V_23 ) ;
F_11 ( & V_23 -> V_31 ) ;
F_44 ( V_23 ) ;
if ( V_23 -> V_1 ) {
F_76 ( & V_23 -> V_177 , V_178 ) ;
F_77 ( V_179 , & V_23 -> V_177 ) ;
F_14 ( & V_23 -> V_31 ) ;
} else {
V_23 -> V_32 = V_176 ;
F_14 ( & V_23 -> V_31 ) ;
F_78 ( V_23 ) ;
}
F_71 ( V_80 ) ;
}
static T_10 F_79 ( int V_180 , int V_130 )
{
switch ( V_180 ) {
case V_181 :
switch ( V_130 ) {
case V_182 :
case V_183 :
case V_184 :
return V_185 ;
default:
return 0 ;
}
case V_186 :
switch ( V_130 ) {
case V_134 :
case V_187 :
case V_135 :
case V_137 :
case V_161 :
case V_160 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
return V_185 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_80 ( struct V_213 * V_214 )
{
F_81 ( V_214 -> V_215 , ~ V_216 ) ;
return 0 ;
}
static int T_11 F_82 ( void )
{
int V_170 ;
F_4 ( L_21 ) ;
if ( V_108 < 1 ) {
F_3 ( L_22 , V_108 ) ;
return - V_81 ;
}
memset ( & V_217 , 0 , sizeof( struct V_218 ) ) ;
V_217 . V_219 = F_83 ( L_23 ,
sizeof( struct V_21 ) ,
0 , V_220 ,
NULL ) ;
if ( V_217 . V_219 == NULL )
return - V_39 ;
F_84 ( & V_217 . V_221 ) ;
F_85 ( & V_217 . V_222 ) ;
F_84 ( & V_217 . V_223 ) ;
F_85 ( & V_217 . V_224 ) ;
V_179 = F_86 ( L_24 , 0 , 0 ) ;
if ( ! V_179 ) {
F_3 ( L_25 ) ;
V_170 = - V_39 ;
goto V_225;
}
V_105 = F_87 (
& V_125 ) ;
if ( ! V_105 ) {
F_3 ( L_26 ) ;
V_170 = - V_81 ;
goto V_226;
}
return 0 ;
V_226:
F_88 ( V_179 ) ;
V_225:
F_89 ( V_217 . V_219 ) ;
return V_170 ;
}
static void T_12 F_90 ( void )
{
struct V_23 * V_23 , * V_227 ;
int V_228 ;
F_4 ( L_27 ) ;
F_88 ( V_179 ) ;
F_11 ( & V_217 . V_223 ) ;
V_228 = F_91 ( & V_217 . V_224 ) ;
F_14 ( & V_217 . V_223 ) ;
if ( ! V_228 ) {
F_3 ( L_28
L_29 ) ;
F_92 (iser_conn, n, &ig.connlist,
conn_list) {
F_78 ( V_23 ) ;
}
}
F_93 ( & V_125 ) ;
F_89 ( V_217 . V_219 ) ;
}
