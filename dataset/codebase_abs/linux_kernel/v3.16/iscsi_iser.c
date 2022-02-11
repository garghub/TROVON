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
struct V_71 * V_72 ;
struct V_25 * V_26 ;
struct V_73 * V_74 ;
int error ;
error = F_31 ( V_64 , V_66 , V_70 ) ;
if ( error )
return error ;
V_74 = F_32 ( V_69 ) ;
if ( ! V_74 ) {
F_3 ( L_8 ,
( unsigned long long ) V_69 ) ;
return - V_75 ;
}
V_26 = V_74 -> V_19 ;
V_72 = V_2 -> V_72 ;
if ( F_33 ( V_26 , V_72 ) )
return - V_33 ;
F_34 ( L_9 , V_2 , V_26 ) ;
V_2 -> V_19 = V_26 ;
V_26 -> V_1 = V_2 ;
return 0 ;
}
static int
F_35 ( struct V_62 * V_66 )
{
struct V_1 * V_1 ;
struct V_25 * V_26 ;
V_1 = V_66 -> V_19 ;
V_26 = V_1 -> V_19 ;
F_36 ( & V_26 -> V_76 ) ;
return F_37 ( V_66 ) ;
}
static void
F_38 ( struct V_62 * V_66 , int V_77 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
F_4 ( L_10 , V_2 , V_26 ) ;
F_39 ( V_66 , V_77 ) ;
if ( V_26 ) {
V_2 -> V_19 = NULL ;
F_40 ( & V_26 -> V_76 ) ;
}
}
static void F_41 ( struct V_63 * V_64 )
{
struct V_78 * V_79 = F_42 ( V_64 ) ;
F_43 ( V_64 ) ;
F_44 ( V_79 ) ;
F_45 ( V_79 ) ;
}
static inline unsigned int
F_46 ( int V_80 )
{
return ( ( V_80 & V_81 ) ? V_82 |
V_83 : 0 ) |
( ( V_80 & V_84 ) ? V_85 |
V_86 : 0 ) |
( ( V_80 & V_87 ) ? V_88 |
V_89 : 0 ) ;
}
static struct V_63 *
F_47 ( struct V_73 * V_74 ,
T_7 V_90 , T_7 V_91 ,
T_5 V_92 )
{
struct V_63 * V_64 ;
struct V_71 * V_72 ;
struct V_78 * V_79 ;
struct V_25 * V_26 = NULL ;
V_79 = F_48 ( & V_93 , 0 , 0 ) ;
if ( ! V_79 )
return NULL ;
V_79 -> V_94 = V_95 ;
V_79 -> V_96 = V_91 ;
V_79 -> V_97 = V_98 ;
V_79 -> V_99 = 0 ;
V_79 -> V_100 = 0 ;
V_79 -> V_101 = 16 ;
if ( V_74 ) {
V_26 = V_74 -> V_19 ;
if ( V_26 -> V_102 ) {
T_8 V_103 = V_26 -> V_28 -> V_104 . V_105 ;
F_49 ( V_79 , F_46 ( V_103 ) ) ;
if ( V_106 )
F_50 ( V_79 , V_107 ) ;
else
F_50 ( V_79 , V_108 ) ;
}
}
if ( F_51 ( V_79 ,
V_74 ? V_26 -> V_28 -> V_30 -> V_109 : NULL ) )
goto V_110;
if ( V_90 > V_111 ) {
F_34 ( L_11 ,
V_90 , V_111 ) ;
V_90 = V_111 ;
}
V_64 = F_52 ( & V_112 , V_79 ,
V_90 , 0 ,
sizeof( struct V_17 ) ,
V_92 , 0 ) ;
if ( ! V_64 )
goto V_113;
V_72 = V_64 -> V_19 ;
V_79 -> V_114 = V_72 -> V_115 ;
return V_64 ;
V_113:
F_44 ( V_79 ) ;
V_110:
F_45 ( V_79 ) ;
return NULL ;
}
static int
F_53 ( struct V_62 * V_66 ,
enum V_116 V_117 , char * V_118 , int V_119 )
{
int V_120 ;
switch ( V_117 ) {
case V_121 :
break;
case V_122 :
sscanf ( V_118 , L_12 , & V_120 ) ;
if ( V_120 ) {
F_3 ( L_13 ) ;
return - V_123 ;
}
break;
case V_124 :
sscanf ( V_118 , L_12 , & V_120 ) ;
if ( V_120 ) {
F_3 ( L_13 ) ;
return - V_123 ;
}
break;
case V_125 :
sscanf ( V_118 , L_12 , & V_120 ) ;
if ( V_120 ) {
F_3 ( L_14 ) ;
return - V_123 ;
}
break;
case V_126 :
sscanf ( V_118 , L_12 , & V_120 ) ;
if ( V_120 ) {
F_3 ( L_15 ) ;
return - V_123 ;
}
break;
default:
return F_54 ( V_66 , V_117 , V_118 , V_119 ) ;
}
return 0 ;
}
static void
F_55 ( struct V_62 * V_66 , struct V_127 * V_128 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
V_128 -> V_129 = V_2 -> V_129 ;
V_128 -> V_130 = V_2 -> V_130 ;
V_128 -> V_131 = V_2 -> V_132 ;
V_128 -> V_133 = V_2 -> V_134 ;
V_128 -> V_135 = V_2 -> V_136 ;
V_128 -> V_137 = V_2 -> V_138 ;
V_128 -> V_139 = V_2 -> V_140 ;
V_128 -> V_141 = V_2 -> V_142 ;
V_128 -> V_143 = V_2 -> V_144 ;
V_128 -> V_145 = 4 ;
strcpy ( V_128 -> V_146 [ 0 ] . V_20 , L_16 ) ;
V_128 -> V_146 [ 0 ] . V_120 = 0 ;
strcpy ( V_128 -> V_146 [ 1 ] . V_20 , L_17 ) ;
V_128 -> V_146 [ 1 ] . V_120 = 0 ; ;
strcpy ( V_128 -> V_146 [ 2 ] . V_20 , L_18 ) ;
V_128 -> V_146 [ 2 ] . V_120 = V_2 -> V_147 ;
strcpy ( V_128 -> V_146 [ 3 ] . V_20 , L_19 ) ;
V_128 -> V_146 [ 3 ] . V_120 = V_2 -> V_148 ;
}
static int F_56 ( struct V_73 * V_74 ,
enum V_116 V_117 , char * V_118 )
{
struct V_25 * V_26 = V_74 -> V_19 ;
int V_149 ;
switch ( V_117 ) {
case V_150 :
case V_151 :
if ( ! V_26 || ! V_26 -> V_152 )
return - V_153 ;
return F_57 ( (struct V_154 * )
& V_26 -> V_152 -> V_155 . V_35 . V_156 ,
V_117 , V_118 ) ;
break;
default:
return - V_157 ;
}
return V_149 ;
}
static struct V_73 *
F_58 ( struct V_78 * V_79 , struct V_158 * V_156 ,
int V_159 )
{
int V_160 ;
struct V_25 * V_26 ;
struct V_73 * V_74 ;
V_74 = F_59 ( sizeof( * V_26 ) ) ;
if ( ! V_74 )
return F_60 ( - V_33 ) ;
V_26 = V_74 -> V_19 ;
V_26 -> V_74 = V_74 ;
F_61 ( V_26 ) ;
V_160 = F_62 ( V_26 , NULL , (struct V_161 * ) V_156 ,
V_159 ) ;
if ( V_160 )
return F_60 ( V_160 ) ;
return V_74 ;
}
static int
F_63 ( struct V_73 * V_74 , int V_162 )
{
struct V_25 * V_26 ;
int V_7 ;
V_26 = V_74 -> V_19 ;
V_7 = F_64 ( V_26 -> V_163 ,
V_26 -> V_164 == V_165 ,
F_65 ( V_162 ) ) ;
if ( ! V_7 &&
( V_26 -> V_164 == V_166 ||
V_26 -> V_164 == V_167 ) )
V_7 = - 1 ;
F_34 ( L_20 , V_26 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_66 ( struct V_73 * V_74 )
{
struct V_25 * V_26 ;
V_26 = V_74 -> V_19 ;
F_34 ( L_21 , V_74 , V_26 , V_26 -> V_164 ) ;
F_67 ( V_26 ) ;
if ( V_26 -> V_1 ) {
F_68 ( & V_26 -> V_168 , V_169 ) ;
F_69 ( V_170 , & V_26 -> V_168 ) ;
} else {
F_70 ( V_26 ) ;
}
}
static T_9 F_71 ( int V_171 , int V_117 )
{
switch ( V_171 ) {
case V_172 :
switch ( V_117 ) {
case V_173 :
case V_174 :
case V_175 :
return V_176 ;
default:
return 0 ;
}
case V_177 :
switch ( V_117 ) {
case V_121 :
case V_178 :
case V_122 :
case V_124 :
case V_151 :
case V_150 :
case V_179 :
case V_180 :
case V_181 :
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
return V_176 ;
default:
return 0 ;
}
}
return 0 ;
}
static int T_10 F_72 ( void )
{
int V_160 ;
F_4 ( L_22 ) ;
if ( V_98 < 1 ) {
F_3 ( L_23 , V_98 ) ;
return - V_75 ;
}
memset ( & V_204 , 0 , sizeof( struct V_205 ) ) ;
V_204 . V_206 = F_73 ( L_24 ,
sizeof( struct V_23 ) ,
0 , V_207 ,
NULL ) ;
if ( V_204 . V_206 == NULL )
return - V_33 ;
F_74 ( & V_204 . V_208 ) ;
F_75 ( & V_204 . V_209 ) ;
F_74 ( & V_204 . V_210 ) ;
F_75 ( & V_204 . V_211 ) ;
V_170 = F_76 ( L_25 , 0 , 0 ) ;
if ( ! V_170 ) {
F_3 ( L_26 ) ;
return - V_33 ;
}
V_95 = F_77 (
& V_112 ) ;
if ( ! V_95 ) {
F_3 ( L_27 ) ;
V_160 = - V_75 ;
goto V_212;
}
return 0 ;
V_212:
F_78 ( V_204 . V_206 ) ;
return V_160 ;
}
static void T_11 F_79 ( void )
{
struct V_25 * V_26 , * V_213 ;
int V_214 ;
F_4 ( L_28 ) ;
F_80 ( V_170 ) ;
F_81 ( & V_204 . V_210 ) ;
V_214 = F_82 ( & V_204 . V_211 ) ;
F_83 ( & V_204 . V_210 ) ;
if ( ! V_214 ) {
F_3 ( L_29
L_30 ) ;
F_84 (ib_conn, n, &ig.connlist, conn_list) {
F_70 ( V_26 ) ;
}
}
F_85 ( & V_112 ) ;
F_78 ( V_204 . V_206 ) ;
}
