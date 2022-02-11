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
V_24 -> V_29 = V_29 ;
V_24 -> V_42 [ 0 ] . V_43 = V_24 -> V_29 ;
V_24 -> V_42 [ 0 ] . V_44 = V_39 ;
V_24 -> V_42 [ 0 ] . V_45 = V_27 -> V_46 -> V_45 ;
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
V_18 -> V_47 = 0 ;
F_16 ( V_18 ) ;
V_18 -> V_31 = V_15 -> V_31 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int error = 0 ;
F_4 ( L_4 , V_2 -> V_48 , V_15 -> V_49 ) ;
error = F_18 ( V_2 , V_15 ) ;
return error ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_50 * V_51 = & V_15 -> V_52 ;
struct V_53 V_4 ;
int error = 0 ;
while ( F_20 ( V_15 ) ) {
F_21 ( V_15 , V_51 , & V_4 ) ;
F_4 ( L_5 ,
V_4 . V_49 , V_51 -> V_54 ) ;
error = F_22 ( V_2 , V_15 , & V_4 ) ;
if ( error ) {
V_51 -> V_55 -- ;
goto V_56;
}
V_51 -> V_57 += V_51 -> V_54 ;
F_4 ( L_6 ,
V_51 -> V_58 - V_51 -> V_57 ) ;
}
V_56:
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
if ( V_15 -> V_31 -> V_59 == V_40 ) {
F_24 ( F_25 ( V_15 -> V_31 ) == 0 ) ;
F_4 ( L_7 ,
V_15 -> V_49 , F_25 ( V_15 -> V_31 ) ,
V_15 -> V_60 , V_15 -> V_52 . V_58 ) ;
}
F_4 ( L_8 ,
V_2 -> V_48 , V_15 -> V_49 ) ;
if ( ! V_18 -> V_47 ) {
error = F_26 ( V_2 , V_15 ) ;
if ( error )
goto V_61;
V_18 -> V_47 = 1 ;
}
if ( F_20 ( V_15 ) )
error = F_19 ( V_2 , V_15 ) ;
V_61:
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
F_28 ( V_27 -> V_38 ,
V_24 -> V_29 , V_39 , V_40 ) ;
if ( ! V_15 -> V_31 )
return;
if ( V_18 -> V_62 == V_63 ) {
V_18 -> V_62 = V_64 ;
F_29 ( V_18 ) ;
}
}
static T_3
F_30 ( struct V_14 * V_15 , T_4 * V_65 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( V_18 -> V_66 [ V_67 ] )
return F_31 ( V_18 , V_67 ,
V_65 ) ;
else
return F_31 ( V_18 , V_68 ,
V_65 ) ;
}
static struct V_69 *
F_32 ( struct V_70 * V_71 ,
T_5 V_72 )
{
struct V_1 * V_2 ;
struct V_69 * V_73 ;
V_73 = F_33 ( V_71 , 0 , V_72 ) ;
if ( ! V_73 )
return NULL ;
V_2 = V_73 -> V_19 ;
V_2 -> V_74 = V_75 ;
return V_73 ;
}
static int
F_34 ( struct V_70 * V_71 ,
struct V_69 * V_73 ,
T_6 V_76 ,
int V_77 )
{
struct V_1 * V_2 = V_73 -> V_19 ;
struct V_25 * V_25 ;
struct V_78 * V_79 ;
int error ;
error = F_35 ( V_71 , V_73 , V_77 ) ;
if ( error )
return error ;
V_79 = F_36 ( V_76 ) ;
if ( ! V_79 ) {
F_3 ( L_9 ,
( unsigned long long ) V_76 ) ;
return - V_80 ;
}
V_25 = V_79 -> V_19 ;
F_11 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_34 != V_35 ) {
error = - V_80 ;
F_3 ( L_10 ,
V_25 , V_25 -> V_34 ) ;
goto V_37;
}
error = F_37 ( V_25 , V_2 -> V_81 ) ;
if ( error )
goto V_37;
F_38 ( L_11 , V_2 , V_25 ) ;
V_2 -> V_19 = V_25 ;
V_25 -> V_1 = V_2 ;
V_37:
F_14 ( & V_25 -> V_33 ) ;
return error ;
}
static int
F_39 ( struct V_69 * V_73 )
{
struct V_1 * V_1 ;
struct V_25 * V_25 ;
V_1 = V_73 -> V_19 ;
V_25 = V_1 -> V_19 ;
F_40 ( & V_25 -> V_82 ) ;
return F_41 ( V_73 ) ;
}
static void
F_42 ( struct V_69 * V_73 , int V_83 )
{
struct V_1 * V_2 = V_73 -> V_19 ;
struct V_25 * V_25 = V_2 -> V_19 ;
F_38 ( L_12 , V_2 , V_25 ) ;
if ( V_25 ) {
F_11 ( & V_25 -> V_33 ) ;
F_43 ( V_25 ) ;
F_44 ( V_73 , V_83 ) ;
V_25 -> V_1 = NULL ;
V_2 -> V_19 = NULL ;
F_45 ( & V_25 -> V_82 ) ;
F_14 ( & V_25 -> V_33 ) ;
} else {
F_44 ( V_73 , V_83 ) ;
}
}
static void
F_46 ( struct V_70 * V_71 )
{
struct V_84 * V_85 = F_47 ( V_71 ) ;
F_48 ( V_71 ) ;
F_49 ( V_85 ) ;
F_50 ( V_85 ) ;
}
static inline unsigned int
F_51 ( int V_86 )
{
return ( ( V_86 & V_87 ) ?
V_88 | V_89 |
V_90 : 0 ) |
( ( V_86 & V_91 ) ?
V_92 | V_93 : 0 ) |
( ( V_86 & V_94 ) ?
V_95 | V_96 : 0 ) ;
}
static struct V_70 *
F_52 ( struct V_78 * V_79 ,
T_7 V_97 , T_7 V_98 ,
T_5 V_99 )
{
struct V_70 * V_71 ;
struct V_100 * V_81 ;
struct V_84 * V_85 ;
struct V_25 * V_25 = NULL ;
struct V_28 * V_28 ;
T_8 V_101 ;
V_85 = F_53 ( & V_102 , 0 , 0 ) ;
if ( ! V_85 )
return NULL ;
V_85 -> V_103 = V_104 ;
V_85 -> V_105 = V_98 ;
V_85 -> V_106 = V_107 ;
V_85 -> V_108 = 0 ;
V_85 -> V_109 = 0 ;
V_85 -> V_110 = 16 ;
if ( V_79 ) {
V_25 = V_79 -> V_19 ;
V_101 = V_25 -> V_101 ;
F_11 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_34 != V_35 ) {
F_3 ( L_13 ,
V_25 ) ;
F_14 ( & V_25 -> V_33 ) ;
goto V_111;
}
V_28 = & V_25 -> V_28 ;
if ( V_28 -> V_112 ) {
T_9 V_113 = V_28 -> V_27 -> V_114 . V_115 ;
F_54 ( V_85 , F_51 ( V_113 ) ) ;
F_55 ( V_85 , V_116 |
V_117 ) ;
}
if ( F_56 ( V_85 ,
V_28 -> V_27 -> V_38 -> V_118 ) ) {
F_14 ( & V_25 -> V_33 ) ;
goto V_111;
}
F_14 ( & V_25 -> V_33 ) ;
} else {
V_101 = V_119 ;
if ( F_56 ( V_85 , NULL ) )
goto V_111;
}
if ( V_97 > V_101 ) {
F_38 ( L_14 ,
V_97 , V_101 ) ;
V_97 = V_101 ;
}
V_71 = F_57 ( & V_120 , V_85 ,
V_97 , 0 ,
sizeof( struct V_17 ) ,
V_99 , 0 ) ;
if ( ! V_71 )
goto V_121;
V_81 = V_71 -> V_19 ;
V_85 -> V_122 = V_81 -> V_123 ;
return V_71 ;
V_121:
F_49 ( V_85 ) ;
V_111:
F_50 ( V_85 ) ;
return NULL ;
}
static int
F_58 ( struct V_69 * V_73 ,
enum V_124 V_125 , char * V_126 , int V_127 )
{
int V_128 ;
switch ( V_125 ) {
case V_129 :
break;
case V_130 :
sscanf ( V_126 , L_15 , & V_128 ) ;
if ( V_128 ) {
F_3 ( L_16 ) ;
return - V_131 ;
}
break;
case V_132 :
sscanf ( V_126 , L_15 , & V_128 ) ;
if ( V_128 ) {
F_3 ( L_16 ) ;
return - V_131 ;
}
break;
case V_133 :
sscanf ( V_126 , L_15 , & V_128 ) ;
if ( V_128 ) {
F_3 ( L_17 ) ;
return - V_131 ;
}
break;
case V_134 :
sscanf ( V_126 , L_15 , & V_128 ) ;
if ( V_128 ) {
F_3 ( L_18 ) ;
return - V_131 ;
}
break;
default:
return F_59 ( V_73 , V_125 , V_126 , V_127 ) ;
}
return 0 ;
}
static void
F_60 ( struct V_69 * V_73 , struct V_135 * V_136 )
{
struct V_1 * V_2 = V_73 -> V_19 ;
V_136 -> V_137 = V_2 -> V_137 ;
V_136 -> V_138 = V_2 -> V_138 ;
V_136 -> V_139 = V_2 -> V_140 ;
V_136 -> V_141 = V_2 -> V_142 ;
V_136 -> V_143 = V_2 -> V_144 ;
V_136 -> V_145 = V_2 -> V_146 ;
V_136 -> V_147 = V_2 -> V_148 ;
V_136 -> V_149 = V_2 -> V_150 ;
V_136 -> V_151 = V_2 -> V_152 ;
V_136 -> V_153 = 4 ;
strcpy ( V_136 -> V_154 [ 0 ] . V_20 , L_19 ) ;
V_136 -> V_154 [ 0 ] . V_128 = 0 ;
strcpy ( V_136 -> V_154 [ 1 ] . V_20 , L_20 ) ;
V_136 -> V_154 [ 1 ] . V_128 = 0 ; ;
strcpy ( V_136 -> V_154 [ 2 ] . V_20 , L_21 ) ;
V_136 -> V_154 [ 2 ] . V_128 = V_2 -> V_155 ;
strcpy ( V_136 -> V_154 [ 3 ] . V_20 , L_22 ) ;
V_136 -> V_154 [ 3 ] . V_128 = V_2 -> V_156 ;
}
static int F_61 ( struct V_78 * V_79 ,
enum V_124 V_125 , char * V_126 )
{
struct V_25 * V_25 = V_79 -> V_19 ;
int V_157 ;
switch ( V_125 ) {
case V_158 :
case V_159 :
if ( ! V_25 || ! V_25 -> V_28 . V_160 )
return - V_161 ;
return F_62 ( (struct V_162 * )
& V_25 -> V_28 . V_160 -> V_163 . V_43 . V_164 ,
V_125 , V_126 ) ;
break;
default:
return - V_165 ;
}
return V_157 ;
}
static struct V_78 *
F_63 ( struct V_84 * V_85 , struct V_166 * V_164 ,
int V_167 )
{
int V_168 ;
struct V_25 * V_25 ;
struct V_78 * V_79 ;
V_79 = F_64 ( 0 ) ;
if ( ! V_79 )
return F_65 ( - V_41 ) ;
V_25 = F_66 ( sizeof( * V_25 ) , V_169 ) ;
if ( ! V_25 ) {
V_168 = - V_41 ;
goto V_170;
}
V_79 -> V_19 = V_25 ;
V_25 -> V_79 = V_79 ;
F_67 ( V_25 ) ;
V_168 = F_68 ( V_25 , NULL , V_164 , V_167 ) ;
if ( V_168 )
goto V_170;
return V_79 ;
V_170:
F_69 ( V_79 ) ;
return F_65 ( V_168 ) ;
}
static int
F_70 ( struct V_78 * V_79 , int V_171 )
{
struct V_25 * V_25 ;
int V_7 ;
V_25 = V_79 -> V_19 ;
V_7 = F_71 ( & V_25 -> V_172 ,
F_72 ( V_171 ) ) ;
if ( V_7 == 0 ) {
F_11 ( & V_25 -> V_33 ) ;
if ( V_25 -> V_34 == V_173 ||
V_25 -> V_34 == V_174 )
V_7 = - 1 ;
F_14 ( & V_25 -> V_33 ) ;
}
F_38 ( L_23 , V_25 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_73 ( struct V_78 * V_79 )
{
struct V_25 * V_25 ;
V_25 = V_79 -> V_19 ;
F_38 ( L_24 ,
V_79 , V_25 , V_25 -> V_34 ) ;
F_11 ( & V_25 -> V_33 ) ;
F_43 ( V_25 ) ;
if ( V_25 -> V_1 ) {
F_74 ( & V_25 -> V_175 , V_176 ) ;
F_75 ( V_177 , & V_25 -> V_175 ) ;
F_14 ( & V_25 -> V_33 ) ;
} else {
V_25 -> V_34 = V_174 ;
F_14 ( & V_25 -> V_33 ) ;
F_76 ( V_25 ) ;
}
F_69 ( V_79 ) ;
}
static T_10 F_77 ( int V_178 , int V_125 )
{
switch ( V_178 ) {
case V_179 :
switch ( V_125 ) {
case V_180 :
case V_181 :
case V_182 :
return V_183 ;
default:
return 0 ;
}
case V_184 :
switch ( V_125 ) {
case V_129 :
case V_185 :
case V_130 :
case V_132 :
case V_159 :
case V_158 :
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
case V_207 :
case V_208 :
case V_209 :
case V_210 :
return V_183 ;
default:
return 0 ;
}
}
return 0 ;
}
static int T_11 F_78 ( void )
{
int V_168 ;
F_4 ( L_25 ) ;
if ( V_107 < 1 ) {
F_3 ( L_26 , V_107 ) ;
return - V_80 ;
}
memset ( & V_211 , 0 , sizeof( struct V_212 ) ) ;
V_211 . V_213 = F_79 ( L_27 ,
sizeof( struct V_23 ) ,
0 , V_214 ,
NULL ) ;
if ( V_211 . V_213 == NULL )
return - V_41 ;
F_80 ( & V_211 . V_215 ) ;
F_81 ( & V_211 . V_216 ) ;
F_80 ( & V_211 . V_217 ) ;
F_81 ( & V_211 . V_218 ) ;
V_177 = F_82 ( L_28 , 0 , 0 ) ;
if ( ! V_177 ) {
F_3 ( L_29 ) ;
return - V_41 ;
}
V_104 = F_83 (
& V_120 ) ;
if ( ! V_104 ) {
F_3 ( L_30 ) ;
V_168 = - V_80 ;
goto V_219;
}
return 0 ;
V_219:
F_84 ( V_211 . V_213 ) ;
return V_168 ;
}
static void T_12 F_85 ( void )
{
struct V_25 * V_25 , * V_220 ;
int V_221 ;
F_4 ( L_31 ) ;
F_86 ( V_177 ) ;
F_11 ( & V_211 . V_217 ) ;
V_221 = F_87 ( & V_211 . V_218 ) ;
F_14 ( & V_211 . V_217 ) ;
if ( ! V_221 ) {
F_3 ( L_32
L_33 ) ;
F_88 (iser_conn, n, &ig.connlist,
conn_list) {
F_76 ( V_25 ) ;
}
}
F_89 ( & V_120 ) ;
F_84 ( V_211 . V_213 ) ;
}
