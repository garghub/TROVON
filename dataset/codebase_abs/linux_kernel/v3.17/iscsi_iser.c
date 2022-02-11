void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 , int V_6 )
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
static int F_7 ( struct V_14 * V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
V_15 -> V_4 = (struct V_3 * ) & V_18 -> V_20 . V_21 ;
V_15 -> V_22 = sizeof( V_18 -> V_20 . V_21 ) ;
return 0 ;
}
int F_8 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_15 -> V_2 -> V_19 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_29 ;
V_29 = F_9 ( V_28 -> V_30 , ( void * ) V_24 ,
V_31 , V_32 ) ;
if ( F_10 ( V_28 -> V_30 , V_29 ) )
return - V_33 ;
V_24 -> V_29 = V_29 ;
V_24 -> V_34 [ 0 ] . V_35 = V_24 -> V_29 ;
V_24 -> V_34 [ 0 ] . V_36 = V_31 ;
V_24 -> V_34 [ 0 ] . V_37 = V_28 -> V_38 -> V_37 ;
V_18 -> V_26 = V_26 ;
return 0 ;
}
static int
F_11 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( F_8 ( V_15 , & V_18 -> V_20 ) )
return - V_33 ;
if ( ! V_15 -> V_39 )
return 0 ;
V_18 -> V_40 = 0 ;
F_12 ( V_18 ) ;
V_18 -> V_39 = V_15 -> V_39 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int error = 0 ;
F_4 ( L_3 , V_2 -> V_41 , V_15 -> V_42 ) ;
error = F_14 ( V_2 , V_15 ) ;
return error ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_43 * V_44 = & V_15 -> V_45 ;
struct V_46 V_4 ;
int error = 0 ;
while ( F_16 ( V_15 ) ) {
F_17 ( V_15 , V_44 , & V_4 ) ;
F_4 ( L_4 ,
V_4 . V_42 , V_44 -> V_47 ) ;
error = F_18 ( V_2 , V_15 , & V_4 ) ;
if ( error ) {
V_44 -> V_48 -- ;
goto V_49;
}
V_44 -> V_50 += V_44 -> V_47 ;
F_4 ( L_5 ,
V_44 -> V_51 - V_44 -> V_50 ) ;
}
V_49:
return error ;
}
static int
F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_18 = V_15 -> V_19 ;
int error = 0 ;
if ( ! V_15 -> V_39 )
return F_13 ( V_2 , V_15 ) ;
if ( V_15 -> V_39 -> V_52 == V_32 ) {
F_20 ( F_21 ( V_15 -> V_39 ) == 0 ) ;
F_4 ( L_6 ,
V_15 -> V_42 , F_21 ( V_15 -> V_39 ) ,
V_15 -> V_53 , V_15 -> V_45 . V_51 ) ;
}
F_4 ( L_7 ,
V_2 -> V_41 , V_15 -> V_42 ) ;
if ( ! V_18 -> V_40 ) {
error = F_22 ( V_2 , V_15 ) ;
if ( error )
goto V_54;
V_18 -> V_40 = 1 ;
}
if ( F_16 ( V_15 ) )
error = F_15 ( V_2 , V_15 ) ;
V_54:
return error ;
}
static void F_23 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_23 * V_24 = & V_18 -> V_20 ;
struct V_25 * V_26 = V_15 -> V_2 -> V_19 ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_24 ( V_28 -> V_30 ,
V_24 -> V_29 , V_31 , V_32 ) ;
if ( ! V_15 -> V_39 )
return;
if ( V_18 -> V_55 == V_56 ) {
V_18 -> V_55 = V_57 ;
F_25 ( V_18 ) ;
}
}
static T_3 F_26 ( struct V_14 * V_15 , T_4 * V_58 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( V_18 -> V_59 [ V_60 ] )
return F_27 ( V_18 , V_60 ,
V_58 ) ;
else
return F_27 ( V_18 , V_61 ,
V_58 ) ;
}
static struct V_62 *
F_28 ( struct V_63 * V_64 , T_5 V_65 )
{
struct V_1 * V_2 ;
struct V_62 * V_66 ;
V_66 = F_29 ( V_64 , 0 , V_65 ) ;
if ( ! V_66 )
return NULL ;
V_2 = V_66 -> V_19 ;
V_2 -> V_67 = V_68 ;
return V_66 ;
}
static int
F_30 ( struct V_63 * V_64 ,
struct V_62 * V_66 , T_6 V_69 ,
int V_70 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
struct V_25 * V_26 ;
struct V_71 * V_72 ;
int error ;
error = F_31 ( V_64 , V_66 , V_70 ) ;
if ( error )
return error ;
V_72 = F_32 ( V_69 ) ;
if ( ! V_72 ) {
F_3 ( L_8 ,
( unsigned long long ) V_69 ) ;
return - V_73 ;
}
V_26 = V_72 -> V_19 ;
F_33 ( & V_26 -> V_74 ) ;
if ( V_26 -> V_75 != V_76 ) {
error = - V_73 ;
F_3 ( L_9 ,
V_26 , V_26 -> V_75 ) ;
goto V_77;
}
error = F_34 ( V_26 , V_2 -> V_78 ) ;
if ( error )
goto V_77;
F_35 ( L_10 , V_2 , V_26 ) ;
V_2 -> V_19 = V_26 ;
V_26 -> V_1 = V_2 ;
V_77:
F_36 ( & V_26 -> V_74 ) ;
return error ;
}
static int
F_37 ( struct V_62 * V_66 )
{
struct V_1 * V_1 ;
struct V_25 * V_26 ;
V_1 = V_66 -> V_19 ;
V_26 = V_1 -> V_19 ;
F_38 ( & V_26 -> V_79 ) ;
return F_39 ( V_66 ) ;
}
static void
F_40 ( struct V_62 * V_66 , int V_80 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
F_4 ( L_11 , V_2 , V_26 ) ;
F_41 ( V_66 , V_80 ) ;
if ( V_26 ) {
V_2 -> V_19 = NULL ;
F_42 ( & V_26 -> V_79 ) ;
}
}
static void F_43 ( struct V_63 * V_64 )
{
struct V_81 * V_82 = F_44 ( V_64 ) ;
F_45 ( V_64 ) ;
F_46 ( V_82 ) ;
F_47 ( V_82 ) ;
}
static inline unsigned int
F_48 ( int V_83 )
{
return ( ( V_83 & V_84 ) ? V_85 |
V_86 : 0 ) |
( ( V_83 & V_87 ) ? V_88 |
V_89 : 0 ) |
( ( V_83 & V_90 ) ? V_91 |
V_92 : 0 ) ;
}
static struct V_63 *
F_49 ( struct V_71 * V_72 ,
T_7 V_93 , T_7 V_94 ,
T_5 V_95 )
{
struct V_63 * V_64 ;
struct V_96 * V_78 ;
struct V_81 * V_82 ;
struct V_25 * V_26 = NULL ;
V_82 = F_50 ( & V_97 , 0 , 0 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_98 = V_99 ;
V_82 -> V_100 = V_94 ;
V_82 -> V_101 = V_102 ;
V_82 -> V_103 = 0 ;
V_82 -> V_104 = 0 ;
V_82 -> V_105 = 16 ;
if ( V_72 ) {
V_26 = V_72 -> V_19 ;
if ( V_26 -> V_106 ) {
T_8 V_107 = V_26 -> V_28 -> V_108 . V_109 ;
F_51 ( V_82 , F_48 ( V_107 ) ) ;
if ( V_110 )
F_52 ( V_82 , V_111 ) ;
else
F_52 ( V_82 , V_112 ) ;
}
}
if ( F_53 ( V_82 ,
V_72 ? V_26 -> V_28 -> V_30 -> V_113 : NULL ) )
goto V_114;
if ( V_93 > V_115 ) {
F_35 ( L_12 ,
V_93 , V_115 ) ;
V_93 = V_115 ;
}
V_64 = F_54 ( & V_116 , V_82 ,
V_93 , 0 ,
sizeof( struct V_17 ) ,
V_95 , 0 ) ;
if ( ! V_64 )
goto V_117;
V_78 = V_64 -> V_19 ;
V_82 -> V_118 = V_78 -> V_119 ;
return V_64 ;
V_117:
F_46 ( V_82 ) ;
V_114:
F_47 ( V_82 ) ;
return NULL ;
}
static int
F_55 ( struct V_62 * V_66 ,
enum V_120 V_121 , char * V_122 , int V_123 )
{
int V_124 ;
switch ( V_121 ) {
case V_125 :
break;
case V_126 :
sscanf ( V_122 , L_13 , & V_124 ) ;
if ( V_124 ) {
F_3 ( L_14 ) ;
return - V_127 ;
}
break;
case V_128 :
sscanf ( V_122 , L_13 , & V_124 ) ;
if ( V_124 ) {
F_3 ( L_14 ) ;
return - V_127 ;
}
break;
case V_129 :
sscanf ( V_122 , L_13 , & V_124 ) ;
if ( V_124 ) {
F_3 ( L_15 ) ;
return - V_127 ;
}
break;
case V_130 :
sscanf ( V_122 , L_13 , & V_124 ) ;
if ( V_124 ) {
F_3 ( L_16 ) ;
return - V_127 ;
}
break;
default:
return F_56 ( V_66 , V_121 , V_122 , V_123 ) ;
}
return 0 ;
}
static void
F_57 ( struct V_62 * V_66 , struct V_131 * V_132 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
V_132 -> V_133 = V_2 -> V_133 ;
V_132 -> V_134 = V_2 -> V_134 ;
V_132 -> V_135 = V_2 -> V_136 ;
V_132 -> V_137 = V_2 -> V_138 ;
V_132 -> V_139 = V_2 -> V_140 ;
V_132 -> V_141 = V_2 -> V_142 ;
V_132 -> V_143 = V_2 -> V_144 ;
V_132 -> V_145 = V_2 -> V_146 ;
V_132 -> V_147 = V_2 -> V_148 ;
V_132 -> V_149 = 4 ;
strcpy ( V_132 -> V_150 [ 0 ] . V_20 , L_17 ) ;
V_132 -> V_150 [ 0 ] . V_124 = 0 ;
strcpy ( V_132 -> V_150 [ 1 ] . V_20 , L_18 ) ;
V_132 -> V_150 [ 1 ] . V_124 = 0 ; ;
strcpy ( V_132 -> V_150 [ 2 ] . V_20 , L_19 ) ;
V_132 -> V_150 [ 2 ] . V_124 = V_2 -> V_151 ;
strcpy ( V_132 -> V_150 [ 3 ] . V_20 , L_20 ) ;
V_132 -> V_150 [ 3 ] . V_124 = V_2 -> V_152 ;
}
static int F_58 ( struct V_71 * V_72 ,
enum V_120 V_121 , char * V_122 )
{
struct V_25 * V_26 = V_72 -> V_19 ;
int V_153 ;
switch ( V_121 ) {
case V_154 :
case V_155 :
if ( ! V_26 || ! V_26 -> V_156 )
return - V_157 ;
return F_59 ( (struct V_158 * )
& V_26 -> V_156 -> V_159 . V_35 . V_160 ,
V_121 , V_122 ) ;
break;
default:
return - V_161 ;
}
return V_153 ;
}
static struct V_71 *
F_60 ( struct V_81 * V_82 , struct V_162 * V_160 ,
int V_163 )
{
int V_164 ;
struct V_25 * V_26 ;
struct V_71 * V_72 ;
V_72 = F_61 ( 0 ) ;
if ( ! V_72 )
return F_62 ( - V_33 ) ;
V_26 = F_63 ( sizeof( * V_26 ) , V_165 ) ;
if ( ! V_26 ) {
V_164 = - V_33 ;
goto V_166;
}
V_72 -> V_19 = V_26 ;
V_26 -> V_72 = V_72 ;
F_64 ( V_26 ) ;
V_164 = F_65 ( V_26 , NULL , V_160 , V_163 ) ;
if ( V_164 )
goto V_166;
return V_72 ;
V_166:
F_66 ( V_72 ) ;
return F_62 ( V_164 ) ;
}
static int
F_67 ( struct V_71 * V_72 , int V_167 )
{
struct V_25 * V_26 ;
int V_7 ;
V_26 = V_72 -> V_19 ;
V_7 = F_68 ( & V_26 -> V_168 ,
F_69 ( V_167 ) ) ;
if ( V_7 == 0 ) {
F_33 ( & V_26 -> V_74 ) ;
if ( V_26 -> V_75 == V_169 ||
V_26 -> V_75 == V_170 )
V_7 = - 1 ;
F_36 ( & V_26 -> V_74 ) ;
}
F_35 ( L_21 , V_26 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_70 ( struct V_71 * V_72 )
{
struct V_25 * V_26 ;
V_26 = V_72 -> V_19 ;
F_35 ( L_22 , V_72 , V_26 , V_26 -> V_75 ) ;
F_33 ( & V_26 -> V_74 ) ;
F_71 ( V_26 ) ;
if ( V_26 -> V_1 ) {
F_72 ( & V_26 -> V_171 , V_172 ) ;
F_73 ( V_173 , & V_26 -> V_171 ) ;
F_36 ( & V_26 -> V_74 ) ;
} else {
V_26 -> V_75 = V_170 ;
F_36 ( & V_26 -> V_74 ) ;
F_74 ( V_26 ) ;
}
F_66 ( V_72 ) ;
}
static T_9 F_75 ( int V_174 , int V_121 )
{
switch ( V_174 ) {
case V_175 :
switch ( V_121 ) {
case V_176 :
case V_177 :
case V_178 :
return V_179 ;
default:
return 0 ;
}
case V_180 :
switch ( V_121 ) {
case V_125 :
case V_181 :
case V_126 :
case V_128 :
case V_155 :
case V_154 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
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
return V_179 ;
default:
return 0 ;
}
}
return 0 ;
}
static int T_10 F_76 ( void )
{
int V_164 ;
F_4 ( L_23 ) ;
if ( V_102 < 1 ) {
F_3 ( L_24 , V_102 ) ;
return - V_73 ;
}
memset ( & V_207 , 0 , sizeof( struct V_208 ) ) ;
V_207 . V_209 = F_77 ( L_25 ,
sizeof( struct V_23 ) ,
0 , V_210 ,
NULL ) ;
if ( V_207 . V_209 == NULL )
return - V_33 ;
F_78 ( & V_207 . V_211 ) ;
F_79 ( & V_207 . V_212 ) ;
F_78 ( & V_207 . V_213 ) ;
F_79 ( & V_207 . V_214 ) ;
V_173 = F_80 ( L_26 , 0 , 0 ) ;
if ( ! V_173 ) {
F_3 ( L_27 ) ;
return - V_33 ;
}
V_99 = F_81 (
& V_116 ) ;
if ( ! V_99 ) {
F_3 ( L_28 ) ;
V_164 = - V_73 ;
goto V_215;
}
return 0 ;
V_215:
F_82 ( V_207 . V_209 ) ;
return V_164 ;
}
static void T_11 F_83 ( void )
{
struct V_25 * V_26 , * V_216 ;
int V_217 ;
F_4 ( L_29 ) ;
F_84 ( V_173 ) ;
F_33 ( & V_207 . V_213 ) ;
V_217 = F_85 ( & V_207 . V_214 ) ;
F_36 ( & V_207 . V_213 ) ;
if ( ! V_217 ) {
F_3 ( L_30
L_31 ) ;
F_86 (ib_conn, n, &ig.connlist, conn_list) {
F_74 ( V_26 ) ;
}
}
F_87 ( & V_116 ) ;
F_82 ( V_207 . V_209 ) ;
}
