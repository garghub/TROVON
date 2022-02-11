void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , int V_6 )
{
int V_7 = 0 ;
int V_8 ;
int V_9 ;
V_8 = F_2 ( V_4 -> V_10 ) ;
if ( V_8 > V_6 || ( V_8 + 4 ) < V_6 ) {
F_3 ( L_1 ,
V_8 , V_6 ) ;
V_7 = V_11 ;
goto error;
}
if ( V_8 != V_6 )
F_4 ( L_2 ,
V_8 , V_6 ) ;
V_9 = V_4 -> V_12 * 4 ;
V_7 = F_5 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( V_7 && V_7 != V_13 )
goto error;
return;
error:
F_6 ( V_2 , V_7 ) ;
}
static int
F_7 ( struct V_14 * V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
V_15 -> V_4 = (struct V_3 * ) & V_18 -> V_20 . V_21 ;
V_15 -> V_22 = sizeof( V_18 -> V_20 . V_21 ) ;
return 0 ;
}
int
F_8 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
struct V_25 * V_25 = V_15 -> V_2 -> V_19 ;
struct V_26 * V_27 = V_25 -> V_28 . V_27 ;
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_29 ;
const bool V_30 = ! V_15 -> V_31 && ! F_9 () ;
int V_32 = 0 ;
if ( F_10 ( V_30 ) )
F_11 ( & V_25 -> V_33 ) ;
if ( F_10 ( V_25 -> V_34 != V_35 ) ) {
V_32 = - V_36 ;
goto V_37;
}
V_29 = F_12 ( V_27 -> V_38 , ( void * ) V_24 ,
V_39 , V_40 ) ;
if ( F_13 ( V_27 -> V_38 , V_29 ) ) {
V_32 = - V_41 ;
goto V_37;
}
V_24 -> V_42 = 0 ;
V_24 -> V_43 = true ;
V_24 -> V_29 = V_29 ;
V_24 -> V_44 [ 0 ] . V_45 = V_24 -> V_29 ;
V_24 -> V_44 [ 0 ] . V_46 = V_39 ;
V_24 -> V_44 [ 0 ] . V_47 = V_27 -> V_48 -> V_49 ;
V_18 -> V_25 = V_25 ;
V_37:
if ( F_10 ( V_30 ) )
F_14 ( & V_25 -> V_33 ) ;
return V_32 ;
}
static int
F_15 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
int V_32 ;
V_32 = F_8 ( V_15 , & V_18 -> V_20 ) ;
if ( V_32 ) {
F_3 ( L_3 ,
V_18 , V_32 ) ;
return V_32 ;
}
if ( ! V_15 -> V_31 )
return 0 ;
V_18 -> V_50 = 0 ;
F_16 ( V_18 ) ;
V_18 -> V_31 = V_15 -> V_31 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int error = 0 ;
F_4 ( L_4 , V_2 -> V_51 , V_15 -> V_52 ) ;
error = F_18 ( V_2 , V_15 ) ;
return error ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_53 * V_54 = & V_15 -> V_55 ;
struct V_56 V_4 ;
int error = 0 ;
while ( F_20 ( V_15 ) ) {
F_21 ( V_15 , V_54 , & V_4 ) ;
F_4 ( L_5 ,
V_4 . V_52 , V_54 -> V_57 ) ;
error = F_22 ( V_2 , V_15 , & V_4 ) ;
if ( error ) {
V_54 -> V_58 -- ;
goto V_59;
}
V_54 -> V_60 += V_54 -> V_57 ;
F_4 ( L_6 ,
V_54 -> V_61 - V_54 -> V_60 ) ;
}
V_59:
return error ;
}
static int
F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_18 = V_15 -> V_19 ;
int error = 0 ;
if ( ! V_15 -> V_31 )
return F_17 ( V_2 , V_15 ) ;
if ( V_15 -> V_31 -> V_62 == V_40 ) {
F_24 ( F_25 ( V_15 -> V_31 ) == 0 ) ;
F_4 ( L_7 ,
V_15 -> V_52 , F_25 ( V_15 -> V_31 ) ,
V_15 -> V_63 , V_15 -> V_55 . V_61 ) ;
}
F_4 ( L_8 ,
V_2 -> V_51 , V_15 -> V_52 ) ;
if ( ! V_18 -> V_50 ) {
error = F_26 ( V_2 , V_15 ) ;
if ( error )
goto V_64;
V_18 -> V_50 = 1 ;
}
if ( F_20 ( V_15 ) )
error = F_19 ( V_2 , V_15 ) ;
V_64:
return error ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_23 * V_24 = & V_18 -> V_20 ;
struct V_25 * V_25 = V_15 -> V_2 -> V_19 ;
struct V_26 * V_27 = V_25 -> V_28 . V_27 ;
if ( ! V_27 )
return;
if ( F_28 ( V_24 -> V_43 ) ) {
F_29 ( V_27 -> V_38 , V_24 -> V_29 ,
V_39 , V_40 ) ;
V_24 -> V_43 = false ;
}
if ( ! V_15 -> V_31 )
return;
if ( V_18 -> V_65 == V_66 ) {
V_18 -> V_65 = V_67 ;
F_30 ( V_18 ) ;
}
}
static T_3
F_31 ( struct V_14 * V_15 , T_4 * V_68 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( V_18 -> V_69 [ V_70 ] )
return F_32 ( V_18 , V_70 ,
V_68 ) ;
else
return F_32 ( V_18 , V_71 ,
V_68 ) ;
}
static struct V_72 *
F_33 ( struct V_73 * V_74 ,
T_5 V_75 )
{
struct V_1 * V_2 ;
struct V_72 * V_76 ;
V_76 = F_34 ( V_74 , 0 , V_75 ) ;
if ( ! V_76 )
return NULL ;
V_2 = V_76 -> V_19 ;
V_2 -> V_77 = V_78 ;
return V_76 ;
}
static int
F_35 ( struct V_73 * V_74 ,
struct V_72 * V_76 ,
T_6 V_79 ,
int V_80 )
{
struct V_1 * V_2 = V_76 -> V_19 ;
struct V_25 * V_25 ;
struct V_81 * V_82 ;
int error ;
error = F_36 ( V_74 , V_76 , V_80 ) ;
if ( error )
return error ;
V_82 = F_37 ( V_79 ) ;
if ( ! V_82 ) {
F_3 ( L_9 ,
( unsigned long long ) V_79 ) ;
return - V_83 ;
}
V_25 = V_82 -> V_19 ;
F_11 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_34 != V_35 ) {
error = - V_83 ;
F_3 ( L_10 ,
V_25 , V_25 -> V_34 ) ;
goto V_37;
}
error = F_38 ( V_25 , V_2 -> V_84 ) ;
if ( error )
goto V_37;
F_39 ( L_11 , V_2 , V_25 ) ;
V_2 -> V_19 = V_25 ;
V_25 -> V_1 = V_2 ;
V_37:
F_14 ( & V_25 -> V_33 ) ;
return error ;
}
static int
F_40 ( struct V_72 * V_76 )
{
struct V_1 * V_1 ;
struct V_25 * V_25 ;
V_1 = V_76 -> V_19 ;
V_25 = V_1 -> V_19 ;
F_41 ( & V_25 -> V_85 ) ;
return F_42 ( V_76 ) ;
}
static void
F_43 ( struct V_72 * V_76 , int V_86 )
{
struct V_1 * V_2 = V_76 -> V_19 ;
struct V_25 * V_25 = V_2 -> V_19 ;
F_39 ( L_12 , V_2 , V_25 ) ;
if ( V_25 ) {
F_11 ( & V_25 -> V_33 ) ;
F_44 ( V_25 ) ;
F_45 ( V_76 , V_86 ) ;
V_25 -> V_1 = NULL ;
V_2 -> V_19 = NULL ;
F_46 ( & V_25 -> V_85 ) ;
F_14 ( & V_25 -> V_33 ) ;
} else {
F_45 ( V_76 , V_86 ) ;
}
}
static void
F_47 ( struct V_73 * V_74 )
{
struct V_87 * V_88 = F_48 ( V_74 ) ;
F_49 ( V_74 ) ;
F_50 ( V_88 ) ;
F_51 ( V_88 ) ;
}
static inline unsigned int
F_52 ( int V_89 )
{
return ( ( V_89 & V_90 ) ?
V_91 | V_92 |
V_93 : 0 ) |
( ( V_89 & V_94 ) ?
V_95 | V_96 : 0 ) |
( ( V_89 & V_97 ) ?
V_98 | V_99 : 0 ) ;
}
static struct V_73 *
F_53 ( struct V_81 * V_82 ,
T_7 V_100 , T_7 V_101 ,
T_5 V_102 )
{
struct V_73 * V_74 ;
struct V_103 * V_84 ;
struct V_87 * V_88 ;
struct V_25 * V_25 = NULL ;
struct V_28 * V_28 ;
T_8 V_104 ;
V_88 = F_54 ( & V_105 , 0 , 0 ) ;
if ( ! V_88 )
return NULL ;
V_88 -> V_106 = V_107 ;
V_88 -> V_108 = V_101 ;
V_88 -> V_109 = V_110 ;
V_88 -> V_111 = 0 ;
V_88 -> V_112 = 0 ;
V_88 -> V_113 = 16 ;
if ( V_82 ) {
V_25 = V_82 -> V_19 ;
V_104 = V_25 -> V_104 ;
V_88 -> V_114 = V_25 -> V_115 ;
V_88 -> V_116 = V_25 -> V_117 ;
F_11 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_34 != V_35 ) {
F_3 ( L_13 ,
V_25 ) ;
F_14 ( & V_25 -> V_33 ) ;
goto V_118;
}
V_28 = & V_25 -> V_28 ;
if ( V_28 -> V_119 ) {
T_9 V_120 = V_28 -> V_27 -> V_121 . V_122 ;
F_55 ( V_88 , F_52 ( V_120 ) ) ;
F_56 ( V_88 , V_123 |
V_124 ) ;
}
V_88 -> V_114 = F_57 (unsigned short, shost->sg_tablesize,
ib_conn->device->dev_attr.max_fast_reg_page_list_len) ;
V_88 -> V_116 = F_57 (unsigned int,
1024 , (shost->sg_tablesize * PAGE_SIZE) >> 9 ) ;
if ( F_58 ( V_88 ,
V_28 -> V_27 -> V_38 -> V_125 ) ) {
F_14 ( & V_25 -> V_33 ) ;
goto V_118;
}
F_14 ( & V_25 -> V_33 ) ;
} else {
V_104 = V_126 ;
if ( F_58 ( V_88 , NULL ) )
goto V_118;
}
if ( V_100 > V_104 ) {
F_39 ( L_14 ,
V_100 , V_104 ) ;
V_100 = V_104 ;
}
V_74 = F_59 ( & V_127 , V_88 ,
V_100 , 0 ,
sizeof( struct V_17 ) ,
V_102 , 0 ) ;
if ( ! V_74 )
goto V_128;
V_84 = V_74 -> V_19 ;
V_88 -> V_129 = V_84 -> V_130 ;
return V_74 ;
V_128:
F_50 ( V_88 ) ;
V_118:
F_51 ( V_88 ) ;
return NULL ;
}
static int
F_60 ( struct V_72 * V_76 ,
enum V_131 V_132 , char * V_133 , int V_134 )
{
int V_135 ;
switch ( V_132 ) {
case V_136 :
break;
case V_137 :
sscanf ( V_133 , L_15 , & V_135 ) ;
if ( V_135 ) {
F_3 ( L_16 ) ;
return - V_138 ;
}
break;
case V_139 :
sscanf ( V_133 , L_15 , & V_135 ) ;
if ( V_135 ) {
F_3 ( L_16 ) ;
return - V_138 ;
}
break;
case V_140 :
sscanf ( V_133 , L_15 , & V_135 ) ;
if ( V_135 ) {
F_3 ( L_17 ) ;
return - V_138 ;
}
break;
case V_141 :
sscanf ( V_133 , L_15 , & V_135 ) ;
if ( V_135 ) {
F_3 ( L_18 ) ;
return - V_138 ;
}
break;
default:
return F_61 ( V_76 , V_132 , V_133 , V_134 ) ;
}
return 0 ;
}
static void
F_62 ( struct V_72 * V_76 , struct V_142 * V_143 )
{
struct V_1 * V_2 = V_76 -> V_19 ;
V_143 -> V_144 = V_2 -> V_144 ;
V_143 -> V_145 = V_2 -> V_145 ;
V_143 -> V_146 = V_2 -> V_147 ;
V_143 -> V_148 = V_2 -> V_149 ;
V_143 -> V_150 = V_2 -> V_151 ;
V_143 -> V_152 = V_2 -> V_153 ;
V_143 -> V_154 = V_2 -> V_155 ;
V_143 -> V_156 = V_2 -> V_157 ;
V_143 -> V_158 = V_2 -> V_159 ;
V_143 -> V_160 = 1 ;
strcpy ( V_143 -> V_161 [ 0 ] . V_20 , L_19 ) ;
V_143 -> V_161 [ 0 ] . V_135 = V_2 -> V_162 ;
}
static int F_63 ( struct V_81 * V_82 ,
enum V_131 V_132 , char * V_133 )
{
struct V_25 * V_25 = V_82 -> V_19 ;
int V_163 ;
switch ( V_132 ) {
case V_164 :
case V_165 :
if ( ! V_25 || ! V_25 -> V_28 . V_166 )
return - V_167 ;
return F_64 ( (struct V_168 * )
& V_25 -> V_28 . V_166 -> V_169 . V_45 . V_170 ,
V_132 , V_133 ) ;
break;
default:
return - V_171 ;
}
return V_163 ;
}
static struct V_81 *
F_65 ( struct V_87 * V_88 , struct V_172 * V_170 ,
int V_173 )
{
int V_174 ;
struct V_25 * V_25 ;
struct V_81 * V_82 ;
V_82 = F_66 ( 0 ) ;
if ( ! V_82 )
return F_67 ( - V_41 ) ;
V_25 = F_68 ( sizeof( * V_25 ) , V_175 ) ;
if ( ! V_25 ) {
V_174 = - V_41 ;
goto V_176;
}
V_82 -> V_19 = V_25 ;
V_25 -> V_82 = V_82 ;
F_69 ( V_25 ) ;
V_174 = F_70 ( V_25 , NULL , V_170 , V_173 ) ;
if ( V_174 )
goto V_176;
return V_82 ;
V_176:
F_71 ( V_82 ) ;
return F_67 ( V_174 ) ;
}
static int
F_72 ( struct V_81 * V_82 , int V_177 )
{
struct V_25 * V_25 = V_82 -> V_19 ;
int V_7 ;
V_7 = F_73 ( & V_25 -> V_178 ,
F_74 ( V_177 ) ) ;
if ( V_7 == 0 ) {
F_11 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_34 == V_179 ||
V_25 -> V_34 == V_180 )
V_7 = - 1 ;
F_14 ( & V_25 -> V_33 ) ;
}
F_39 ( L_20 , V_25 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_75 ( struct V_81 * V_82 )
{
struct V_25 * V_25 = V_82 -> V_19 ;
F_39 ( L_21 , V_82 , V_25 ) ;
F_11 ( & V_25 -> V_33 ) ;
F_44 ( V_25 ) ;
if ( V_25 -> V_1 ) {
F_76 ( & V_25 -> V_181 , V_182 ) ;
F_77 ( V_183 , & V_25 -> V_181 ) ;
F_14 ( & V_25 -> V_33 ) ;
} else {
V_25 -> V_34 = V_180 ;
F_14 ( & V_25 -> V_33 ) ;
F_78 ( V_25 ) ;
}
F_71 ( V_82 ) ;
}
static T_10 F_79 ( int V_184 , int V_132 )
{
switch ( V_184 ) {
case V_185 :
switch ( V_132 ) {
case V_186 :
case V_187 :
case V_188 :
return V_189 ;
default:
return 0 ;
}
case V_190 :
switch ( V_132 ) {
case V_136 :
case V_191 :
case V_137 :
case V_139 :
case V_165 :
case V_164 :
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
case V_213 :
case V_214 :
case V_215 :
case V_216 :
return V_189 ;
default:
return 0 ;
}
}
return 0 ;
}
static int T_11 F_80 ( void )
{
int V_174 ;
F_4 ( L_22 ) ;
if ( V_110 < 1 ) {
F_3 ( L_23 , V_110 ) ;
return - V_83 ;
}
memset ( & V_217 , 0 , sizeof( struct V_218 ) ) ;
V_217 . V_219 = F_81 ( L_24 ,
sizeof( struct V_23 ) ,
0 , V_220 ,
NULL ) ;
if ( V_217 . V_219 == NULL )
return - V_41 ;
F_82 ( & V_217 . V_221 ) ;
F_83 ( & V_217 . V_222 ) ;
F_82 ( & V_217 . V_223 ) ;
F_83 ( & V_217 . V_224 ) ;
V_183 = F_84 ( L_25 , 0 , 0 ) ;
if ( ! V_183 ) {
F_3 ( L_26 ) ;
return - V_41 ;
}
V_107 = F_85 (
& V_127 ) ;
if ( ! V_107 ) {
F_3 ( L_27 ) ;
V_174 = - V_83 ;
goto V_225;
}
return 0 ;
V_225:
F_86 ( V_217 . V_219 ) ;
return V_174 ;
}
static void T_12 F_87 ( void )
{
struct V_25 * V_25 , * V_226 ;
int V_227 ;
F_4 ( L_28 ) ;
F_88 ( V_183 ) ;
F_11 ( & V_217 . V_223 ) ;
V_227 = F_89 ( & V_217 . V_224 ) ;
F_14 ( & V_217 . V_223 ) ;
if ( ! V_227 ) {
F_3 ( L_29
L_30 ) ;
F_90 (iser_conn, n, &ig.connlist,
conn_list) {
F_78 ( V_25 ) ;
}
}
F_91 ( & V_127 ) ;
F_86 ( V_217 . V_219 ) ;
}
