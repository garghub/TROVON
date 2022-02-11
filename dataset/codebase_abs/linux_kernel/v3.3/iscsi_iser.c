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
struct V_27 * V_28 = V_26 -> V_29 -> V_28 ;
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_30 ;
V_30 = F_9 ( V_28 -> V_31 , ( void * ) V_24 ,
V_32 , V_33 ) ;
if ( F_10 ( V_28 -> V_31 , V_30 ) )
return - V_34 ;
V_24 -> V_30 = V_30 ;
V_24 -> V_35 [ 0 ] . V_36 = V_24 -> V_30 ;
V_24 -> V_35 [ 0 ] . V_37 = V_32 ;
V_24 -> V_35 [ 0 ] . V_38 = V_28 -> V_39 -> V_38 ;
V_18 -> V_26 = V_26 ;
return 0 ;
}
static int
F_11 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( F_8 ( V_15 , & V_18 -> V_20 ) )
return - V_34 ;
if ( ! V_15 -> V_40 )
return 0 ;
V_18 -> V_41 = 0 ;
F_12 ( V_18 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int error = 0 ;
F_4 ( L_3 , V_2 -> V_42 , V_15 -> V_43 ) ;
error = F_14 ( V_2 , V_15 ) ;
return error ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_44 * V_45 = & V_15 -> V_46 ;
struct V_47 V_4 ;
int error = 0 ;
while ( F_16 ( V_15 ) ) {
F_17 ( V_15 , V_45 , & V_4 ) ;
F_4 ( L_4 ,
V_4 . V_43 , V_45 -> V_48 ) ;
error = F_18 ( V_2 , V_15 , & V_4 ) ;
if ( error ) {
V_45 -> V_49 -- ;
goto V_50;
}
V_45 -> V_51 += V_45 -> V_48 ;
F_4 ( L_5 ,
V_45 -> V_52 - V_45 -> V_51 ) ;
}
V_50:
return error ;
}
static int
F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_18 = V_15 -> V_19 ;
int error = 0 ;
if ( ! V_15 -> V_40 )
return F_13 ( V_2 , V_15 ) ;
if ( V_15 -> V_40 -> V_53 == V_33 ) {
F_20 ( F_21 ( V_15 -> V_40 ) == 0 ) ;
F_4 ( L_6 ,
V_15 -> V_43 , F_21 ( V_15 -> V_40 ) ,
V_15 -> V_54 , V_15 -> V_46 . V_52 ) ;
}
F_4 ( L_7 ,
V_2 -> V_42 , V_15 -> V_43 ) ;
if ( ! V_18 -> V_41 ) {
error = F_22 ( V_2 , V_15 ) ;
if ( error )
goto V_55;
V_18 -> V_41 = 1 ;
}
if ( F_16 ( V_15 ) )
error = F_15 ( V_2 , V_15 ) ;
V_55:
return error ;
}
static void F_23 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_23 * V_24 = & V_18 -> V_20 ;
struct V_25 * V_26 = V_15 -> V_2 -> V_19 ;
struct V_27 * V_28 = V_26 -> V_29 -> V_28 ;
F_24 ( V_28 -> V_31 ,
V_24 -> V_30 , V_32 , V_33 ) ;
if ( ! V_15 -> V_40 )
return;
if ( V_18 -> V_56 == V_57 ) {
V_18 -> V_56 = V_58 ;
F_25 ( V_18 ) ;
}
}
static struct V_59 *
F_26 ( struct V_60 * V_61 , T_3 V_62 )
{
struct V_1 * V_2 ;
struct V_59 * V_63 ;
struct V_25 * V_26 ;
V_63 = F_27 ( V_61 , sizeof( * V_26 ) , V_62 ) ;
if ( ! V_63 )
return NULL ;
V_2 = V_63 -> V_19 ;
V_2 -> V_64 = V_65 ;
V_26 = V_2 -> V_19 ;
V_2 -> V_19 = V_26 ;
V_26 -> V_1 = V_2 ;
return V_63 ;
}
static void
F_28 ( struct V_59 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
struct V_26 * V_29 = V_26 -> V_29 ;
F_29 ( V_63 ) ;
if ( V_29 ) {
V_29 -> V_26 = NULL ;
F_30 ( V_29 , 1 ) ;
}
}
static int
F_31 ( struct V_60 * V_61 ,
struct V_59 * V_63 , T_4 V_66 ,
int V_67 )
{
struct V_1 * V_2 = V_63 -> V_19 ;
struct V_25 * V_26 ;
struct V_26 * V_29 ;
struct V_68 * V_69 ;
int error ;
error = F_32 ( V_61 , V_63 , V_67 ) ;
if ( error )
return error ;
V_69 = F_33 ( V_66 ) ;
if ( ! V_69 ) {
F_3 ( L_8 ,
( unsigned long long ) V_66 ) ;
return - V_70 ;
}
V_29 = V_69 -> V_19 ;
F_3 ( L_9 ,
V_2 , V_2 -> V_19 , V_29 ) ;
V_26 = V_2 -> V_19 ;
V_29 -> V_26 = V_26 ;
V_26 -> V_29 = V_29 ;
F_34 ( V_29 ) ;
return 0 ;
}
static void
F_35 ( struct V_59 * V_63 , int V_71 )
{
struct V_1 * V_2 = V_63 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
struct V_26 * V_29 = V_26 -> V_29 ;
if ( V_29 ) {
F_36 ( V_63 , V_71 ) ;
F_30 ( V_29 , 1 ) ;
}
V_26 -> V_29 = NULL ;
}
static int
F_37 ( struct V_59 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_19 ;
int V_72 ;
V_72 = F_38 ( V_2 ) ;
if ( V_72 )
return V_72 ;
return F_39 ( V_63 ) ;
}
static void F_40 ( struct V_60 * V_61 )
{
struct V_73 * V_74 = F_41 ( V_61 ) ;
F_42 ( V_61 ) ;
F_43 ( V_74 ) ;
F_44 ( V_74 ) ;
}
static struct V_60 *
F_45 ( struct V_68 * V_69 ,
T_5 V_75 , T_5 V_76 ,
T_3 V_77 )
{
struct V_60 * V_61 ;
struct V_78 * V_79 ;
struct V_73 * V_74 ;
struct V_26 * V_29 ;
V_74 = F_46 ( & V_80 , 0 , 0 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_81 = V_82 ;
V_74 -> V_83 = V_84 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 0 ;
V_74 -> V_87 = 16 ;
if ( V_69 )
V_29 = V_69 -> V_19 ;
if ( F_47 ( V_74 ,
V_69 ? V_29 -> V_28 -> V_31 -> V_88 : NULL ) )
goto V_89;
V_61 = F_48 ( & V_90 , V_74 ,
V_91 , 0 ,
sizeof( struct V_17 ) ,
V_77 , 0 ) ;
if ( ! V_61 )
goto V_92;
V_79 = V_61 -> V_19 ;
V_74 -> V_93 = V_79 -> V_94 ;
return V_61 ;
V_92:
F_43 ( V_74 ) ;
V_89:
F_44 ( V_74 ) ;
return NULL ;
}
static int
F_49 ( struct V_59 * V_63 ,
enum V_95 V_96 , char * V_97 , int V_98 )
{
int V_99 ;
switch ( V_96 ) {
case V_100 :
break;
case V_101 :
sscanf ( V_97 , L_10 , & V_99 ) ;
if ( V_99 ) {
F_50 ( V_102 L_11 ) ;
return - V_103 ;
}
break;
case V_104 :
sscanf ( V_97 , L_10 , & V_99 ) ;
if ( V_99 ) {
F_50 ( V_102 L_11 ) ;
return - V_103 ;
}
break;
case V_105 :
sscanf ( V_97 , L_10 , & V_99 ) ;
if ( V_99 ) {
F_50 ( V_102 L_12 ) ;
return - V_103 ;
}
break;
case V_106 :
sscanf ( V_97 , L_10 , & V_99 ) ;
if ( V_99 ) {
F_50 ( V_102 L_13 ) ;
return - V_103 ;
}
break;
default:
return F_51 ( V_63 , V_96 , V_97 , V_98 ) ;
}
return 0 ;
}
static void
F_52 ( struct V_59 * V_63 , struct V_107 * V_108 )
{
struct V_1 * V_2 = V_63 -> V_19 ;
V_108 -> V_109 = V_2 -> V_109 ;
V_108 -> V_110 = V_2 -> V_110 ;
V_108 -> V_111 = V_2 -> V_112 ;
V_108 -> V_113 = V_2 -> V_114 ;
V_108 -> V_115 = V_2 -> V_116 ;
V_108 -> V_117 = V_2 -> V_118 ;
V_108 -> V_119 = V_2 -> V_120 ;
V_108 -> V_121 = V_2 -> V_122 ;
V_108 -> V_123 = V_2 -> V_124 ;
V_108 -> V_125 = 4 ;
strcpy ( V_108 -> V_126 [ 0 ] . V_20 , L_14 ) ;
V_108 -> V_126 [ 0 ] . V_99 = 0 ;
strcpy ( V_108 -> V_126 [ 1 ] . V_20 , L_15 ) ;
V_108 -> V_126 [ 1 ] . V_99 = 0 ; ;
strcpy ( V_108 -> V_126 [ 2 ] . V_20 , L_16 ) ;
V_108 -> V_126 [ 2 ] . V_99 = V_2 -> V_127 ;
strcpy ( V_108 -> V_126 [ 3 ] . V_20 , L_17 ) ;
V_108 -> V_126 [ 3 ] . V_99 = V_2 -> V_128 ;
}
static int F_53 ( struct V_68 * V_69 ,
enum V_95 V_96 , char * V_97 )
{
struct V_26 * V_29 = V_69 -> V_19 ;
int V_129 ;
switch ( V_96 ) {
case V_130 :
case V_131 :
if ( ! V_29 || ! V_29 -> V_132 )
return - V_133 ;
return F_54 ( (struct V_134 * )
& V_29 -> V_132 -> V_135 . V_36 . V_136 ,
V_96 , V_97 ) ;
break;
default:
return - V_137 ;
}
return V_129 ;
}
static struct V_68 *
F_55 ( struct V_73 * V_74 , struct V_138 * V_136 ,
int V_139 )
{
int V_72 ;
struct V_26 * V_29 ;
struct V_68 * V_69 ;
V_69 = F_56 ( sizeof( * V_29 ) ) ;
if ( ! V_69 )
return F_57 ( - V_34 ) ;
V_29 = V_69 -> V_19 ;
V_29 -> V_69 = V_69 ;
F_58 ( V_29 ) ;
V_72 = F_59 ( V_29 , NULL , (struct V_140 * ) V_136 ,
V_139 ) ;
if ( V_72 ) {
F_60 ( V_69 ) ;
return F_57 ( V_72 ) ;
}
return V_69 ;
}
static int
F_61 ( struct V_68 * V_69 , int V_141 )
{
struct V_26 * V_29 ;
int V_7 ;
V_29 = V_69 -> V_19 ;
V_7 = F_62 ( V_29 -> V_142 ,
V_29 -> V_143 == V_144 ,
F_63 ( V_141 ) ) ;
if ( ! V_7 &&
( V_29 -> V_143 == V_145 ||
V_29 -> V_143 == V_146 ) )
V_7 = - 1 ;
F_3 ( L_18 , V_29 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_64 ( struct V_68 * V_69 )
{
struct V_26 * V_29 ;
V_29 = V_69 -> V_19 ;
if ( V_29 -> V_26 )
F_65 ( V_29 -> V_26 -> V_1 ) ;
F_3 ( L_19 , V_29 , V_29 -> V_143 ) ;
F_66 ( V_29 ) ;
}
static T_6 F_67 ( int V_147 , int V_96 )
{
switch ( V_147 ) {
case V_148 :
switch ( V_96 ) {
case V_149 :
case V_150 :
case V_151 :
return V_152 ;
default:
return 0 ;
}
case V_153 :
switch ( V_96 ) {
case V_100 :
case V_154 :
case V_101 :
case V_104 :
case V_131 :
case V_130 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
return V_152 ;
default:
return 0 ;
}
}
return 0 ;
}
static int T_7 F_68 ( void )
{
int V_72 ;
F_4 ( L_20 ) ;
if ( V_84 < 1 ) {
F_50 ( V_102 L_21 , V_84 ) ;
return - V_70 ;
}
memset ( & V_179 , 0 , sizeof( struct V_180 ) ) ;
V_179 . V_181 = F_69 ( L_22 ,
sizeof( struct V_23 ) ,
0 , V_182 ,
NULL ) ;
if ( V_179 . V_181 == NULL )
return - V_34 ;
F_70 ( & V_179 . V_183 ) ;
F_71 ( & V_179 . V_184 ) ;
F_70 ( & V_179 . V_185 ) ;
F_71 ( & V_179 . V_186 ) ;
V_82 = F_72 (
& V_90 ) ;
if ( ! V_82 ) {
F_3 ( L_23 ) ;
V_72 = - V_70 ;
goto V_187;
}
return 0 ;
V_187:
F_73 ( V_179 . V_181 ) ;
return V_72 ;
}
static void T_8 F_74 ( void )
{
F_4 ( L_24 ) ;
F_75 ( & V_90 ) ;
F_73 ( V_179 . V_181 ) ;
}
