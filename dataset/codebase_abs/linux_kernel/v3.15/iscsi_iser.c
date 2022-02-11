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
static void
F_30 ( struct V_62 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
F_31 ( V_66 ) ;
if ( V_26 ) {
V_26 -> V_1 = NULL ;
F_32 ( V_26 , 1 ) ;
}
}
static int
F_33 ( struct V_63 * V_64 ,
struct V_62 * V_66 , T_6 V_69 ,
int V_70 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
struct V_71 * V_72 ;
struct V_25 * V_26 ;
struct V_73 * V_74 ;
int error ;
error = F_34 ( V_64 , V_66 , V_70 ) ;
if ( error )
return error ;
V_74 = F_35 ( V_69 ) ;
if ( ! V_74 ) {
F_3 ( L_8 ,
( unsigned long long ) V_69 ) ;
return - V_75 ;
}
V_26 = V_74 -> V_19 ;
V_72 = V_2 -> V_72 ;
if ( F_36 ( V_26 , V_72 ) )
return - V_33 ;
F_37 ( L_9 , V_2 , V_26 ) ;
V_2 -> V_19 = V_26 ;
V_26 -> V_1 = V_2 ;
F_38 ( V_26 ) ;
return 0 ;
}
static void
F_39 ( struct V_62 * V_66 , int V_76 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
if ( V_26 ) {
F_40 ( V_66 , V_76 ) ;
F_32 ( V_26 , 1 ) ;
}
V_2 -> V_19 = NULL ;
}
static void F_41 ( struct V_63 * V_64 )
{
struct V_77 * V_78 = F_42 ( V_64 ) ;
F_43 ( V_64 ) ;
F_44 ( V_78 ) ;
F_45 ( V_78 ) ;
}
static inline unsigned int
F_46 ( int V_79 )
{
return ( ( V_79 & V_80 ) ? V_81 |
V_82 : 0 ) |
( ( V_79 & V_83 ) ? V_84 |
V_85 : 0 ) |
( ( V_79 & V_86 ) ? V_87 |
V_88 : 0 ) ;
}
static struct V_63 *
F_47 ( struct V_73 * V_74 ,
T_7 V_89 , T_7 V_90 ,
T_5 V_91 )
{
struct V_63 * V_64 ;
struct V_71 * V_72 ;
struct V_77 * V_78 ;
struct V_25 * V_26 = NULL ;
V_78 = F_48 ( & V_92 , 0 , 0 ) ;
if ( ! V_78 )
return NULL ;
V_78 -> V_93 = V_94 ;
V_78 -> V_95 = V_90 ;
V_78 -> V_96 = V_97 ;
V_78 -> V_98 = 0 ;
V_78 -> V_99 = 0 ;
V_78 -> V_100 = 16 ;
if ( V_74 ) {
V_26 = V_74 -> V_19 ;
if ( V_26 -> V_101 ) {
T_8 V_102 = V_26 -> V_28 -> V_103 . V_104 ;
F_49 ( V_78 , F_46 ( V_102 ) ) ;
if ( V_105 )
F_50 ( V_78 , V_106 ) ;
else
F_50 ( V_78 , V_107 ) ;
}
}
if ( F_51 ( V_78 ,
V_74 ? V_26 -> V_28 -> V_30 -> V_108 : NULL ) )
goto V_109;
if ( V_89 > V_110 ) {
F_37 ( L_10 ,
V_89 , V_110 ) ;
V_89 = V_110 ;
}
V_64 = F_52 ( & V_111 , V_78 ,
V_89 , 0 ,
sizeof( struct V_17 ) ,
V_91 , 0 ) ;
if ( ! V_64 )
goto V_112;
V_72 = V_64 -> V_19 ;
V_78 -> V_113 = V_72 -> V_114 ;
return V_64 ;
V_112:
F_44 ( V_78 ) ;
V_109:
F_45 ( V_78 ) ;
return NULL ;
}
static int
F_53 ( struct V_62 * V_66 ,
enum V_115 V_116 , char * V_117 , int V_118 )
{
int V_119 ;
switch ( V_116 ) {
case V_120 :
break;
case V_121 :
sscanf ( V_117 , L_11 , & V_119 ) ;
if ( V_119 ) {
F_3 ( L_12 ) ;
return - V_122 ;
}
break;
case V_123 :
sscanf ( V_117 , L_11 , & V_119 ) ;
if ( V_119 ) {
F_3 ( L_12 ) ;
return - V_122 ;
}
break;
case V_124 :
sscanf ( V_117 , L_11 , & V_119 ) ;
if ( V_119 ) {
F_3 ( L_13 ) ;
return - V_122 ;
}
break;
case V_125 :
sscanf ( V_117 , L_11 , & V_119 ) ;
if ( V_119 ) {
F_3 ( L_14 ) ;
return - V_122 ;
}
break;
default:
return F_54 ( V_66 , V_116 , V_117 , V_118 ) ;
}
return 0 ;
}
static void
F_55 ( struct V_62 * V_66 , struct V_126 * V_127 )
{
struct V_1 * V_2 = V_66 -> V_19 ;
V_127 -> V_128 = V_2 -> V_128 ;
V_127 -> V_129 = V_2 -> V_129 ;
V_127 -> V_130 = V_2 -> V_131 ;
V_127 -> V_132 = V_2 -> V_133 ;
V_127 -> V_134 = V_2 -> V_135 ;
V_127 -> V_136 = V_2 -> V_137 ;
V_127 -> V_138 = V_2 -> V_139 ;
V_127 -> V_140 = V_2 -> V_141 ;
V_127 -> V_142 = V_2 -> V_143 ;
V_127 -> V_144 = 4 ;
strcpy ( V_127 -> V_145 [ 0 ] . V_20 , L_15 ) ;
V_127 -> V_145 [ 0 ] . V_119 = 0 ;
strcpy ( V_127 -> V_145 [ 1 ] . V_20 , L_16 ) ;
V_127 -> V_145 [ 1 ] . V_119 = 0 ; ;
strcpy ( V_127 -> V_145 [ 2 ] . V_20 , L_17 ) ;
V_127 -> V_145 [ 2 ] . V_119 = V_2 -> V_146 ;
strcpy ( V_127 -> V_145 [ 3 ] . V_20 , L_18 ) ;
V_127 -> V_145 [ 3 ] . V_119 = V_2 -> V_147 ;
}
static int F_56 ( struct V_73 * V_74 ,
enum V_115 V_116 , char * V_117 )
{
struct V_25 * V_26 = V_74 -> V_19 ;
int V_148 ;
switch ( V_116 ) {
case V_149 :
case V_150 :
if ( ! V_26 || ! V_26 -> V_151 )
return - V_152 ;
return F_57 ( (struct V_153 * )
& V_26 -> V_151 -> V_154 . V_35 . V_155 ,
V_116 , V_117 ) ;
break;
default:
return - V_156 ;
}
return V_148 ;
}
static struct V_73 *
F_58 ( struct V_77 * V_78 , struct V_157 * V_155 ,
int V_158 )
{
int V_159 ;
struct V_25 * V_26 ;
struct V_73 * V_74 ;
V_74 = F_59 ( sizeof( * V_26 ) ) ;
if ( ! V_74 )
return F_60 ( - V_33 ) ;
V_26 = V_74 -> V_19 ;
V_26 -> V_74 = V_74 ;
F_61 ( V_26 ) ;
V_159 = F_62 ( V_26 , NULL , (struct V_160 * ) V_155 ,
V_158 ) ;
if ( V_159 )
return F_60 ( V_159 ) ;
return V_74 ;
}
static int
F_63 ( struct V_73 * V_74 , int V_161 )
{
struct V_25 * V_26 ;
int V_7 ;
V_26 = V_74 -> V_19 ;
V_7 = F_64 ( V_26 -> V_162 ,
V_26 -> V_163 == V_164 ,
F_65 ( V_161 ) ) ;
if ( ! V_7 &&
( V_26 -> V_163 == V_165 ||
V_26 -> V_163 == V_166 ) )
V_7 = - 1 ;
F_37 ( L_19 , V_26 , V_7 ) ;
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
if ( V_26 -> V_1 )
F_67 ( V_26 -> V_1 ) ;
F_37 ( L_20 , V_26 , V_26 -> V_163 ) ;
F_68 ( V_26 ) ;
}
static T_9 F_69 ( int V_167 , int V_116 )
{
switch ( V_167 ) {
case V_168 :
switch ( V_116 ) {
case V_169 :
case V_170 :
case V_171 :
return V_172 ;
default:
return 0 ;
}
case V_173 :
switch ( V_116 ) {
case V_120 :
case V_174 :
case V_121 :
case V_123 :
case V_150 :
case V_149 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
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
return V_172 ;
default:
return 0 ;
}
}
return 0 ;
}
static int T_10 F_70 ( void )
{
int V_159 ;
F_4 ( L_21 ) ;
if ( V_97 < 1 ) {
F_3 ( L_22 , V_97 ) ;
return - V_75 ;
}
memset ( & V_200 , 0 , sizeof( struct V_201 ) ) ;
V_200 . V_202 = F_71 ( L_23 ,
sizeof( struct V_23 ) ,
0 , V_203 ,
NULL ) ;
if ( V_200 . V_202 == NULL )
return - V_33 ;
F_72 ( & V_200 . V_204 ) ;
F_73 ( & V_200 . V_205 ) ;
F_72 ( & V_200 . V_206 ) ;
F_73 ( & V_200 . V_207 ) ;
V_94 = F_74 (
& V_111 ) ;
if ( ! V_94 ) {
F_3 ( L_24 ) ;
V_159 = - V_75 ;
goto V_208;
}
return 0 ;
V_208:
F_75 ( V_200 . V_202 ) ;
return V_159 ;
}
static void T_11 F_76 ( void )
{
F_4 ( L_25 ) ;
F_77 ( & V_111 ) ;
F_75 ( V_200 . V_202 ) ;
}
