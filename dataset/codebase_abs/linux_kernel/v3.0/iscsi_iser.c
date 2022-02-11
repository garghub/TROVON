void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 , int V_6 )
{
int V_7 = 0 ;
int V_8 ;
int V_9 ;
V_8 = F_2 ( V_4 -> V_10 ) ;
if ( V_8 != V_6 ) {
F_3 ( V_11 L_1 ,
V_8 , V_6 ) ;
V_7 = V_12 ;
goto error;
}
V_9 = V_4 -> V_13 * 4 ;
V_7 = F_4 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( V_7 && V_7 != V_14 )
goto error;
return;
error:
F_5 ( V_2 , V_7 ) ;
}
static int F_6 ( struct V_15 * V_16 , T_1 V_17 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
V_16 -> V_4 = (struct V_3 * ) & V_19 -> V_21 . V_22 ;
V_16 -> V_23 = sizeof( V_19 -> V_21 . V_22 ) ;
return 0 ;
}
int F_7 ( struct V_15 * V_16 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_16 -> V_2 -> V_20 ;
struct V_28 * V_29 = V_27 -> V_30 -> V_29 ;
struct V_18 * V_19 = V_16 -> V_20 ;
T_2 V_31 ;
V_31 = F_8 ( V_29 -> V_32 , ( void * ) V_25 ,
V_33 , V_34 ) ;
if ( F_9 ( V_29 -> V_32 , V_31 ) )
return - V_35 ;
V_25 -> V_31 = V_31 ;
V_25 -> V_36 [ 0 ] . V_37 = V_25 -> V_31 ;
V_25 -> V_36 [ 0 ] . V_38 = V_33 ;
V_25 -> V_36 [ 0 ] . V_39 = V_29 -> V_40 -> V_39 ;
V_19 -> V_41 = 1 ;
V_19 -> V_27 = V_27 ;
return 0 ;
}
static int
F_10 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
if ( ! V_19 -> V_41 )
if ( F_7 ( V_16 , & V_19 -> V_21 ) )
return - V_35 ;
if ( ! V_16 -> V_42 )
return 0 ;
V_19 -> V_43 = 0 ;
F_11 ( V_19 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int error = 0 ;
F_13 ( L_2 , V_2 -> V_44 , V_16 -> V_45 ) ;
error = F_14 ( V_2 , V_16 ) ;
return error ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_46 * V_47 = & V_16 -> V_48 ;
struct V_49 V_4 ;
int error = 0 ;
while ( F_16 ( V_16 ) ) {
F_17 ( V_16 , V_47 , & V_4 ) ;
F_13 ( L_3 ,
V_4 . V_45 , V_47 -> V_50 ) ;
error = F_18 ( V_2 , V_16 , & V_4 ) ;
if ( error ) {
V_47 -> V_51 -- ;
goto V_52;
}
V_47 -> V_53 += V_47 -> V_50 ;
F_13 ( L_4 ,
V_47 -> V_54 - V_47 -> V_53 ) ;
}
V_52:
return error ;
}
static int
F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_18 * V_19 = V_16 -> V_20 ;
int error = 0 ;
if ( ! V_16 -> V_42 )
return F_12 ( V_2 , V_16 ) ;
if ( V_16 -> V_42 -> V_55 == V_34 ) {
F_20 ( F_21 ( V_16 -> V_42 ) == 0 ) ;
F_13 ( L_5 ,
V_16 -> V_45 , F_21 ( V_16 -> V_42 ) ,
V_16 -> V_56 , V_16 -> V_48 . V_54 ) ;
}
F_13 ( L_6 ,
V_2 -> V_44 , V_16 -> V_45 ) ;
if ( ! V_19 -> V_43 ) {
error = F_22 ( V_2 , V_16 ) ;
if ( error )
goto V_57;
V_19 -> V_43 = 1 ;
}
if ( F_16 ( V_16 ) )
error = F_15 ( V_2 , V_16 ) ;
V_57:
return error ;
}
static void F_23 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
if ( ! V_16 -> V_42 )
return;
if ( V_19 -> V_58 == V_59 ) {
V_19 -> V_58 = V_60 ;
F_24 ( V_19 ) ;
}
}
static struct V_61 *
F_25 ( struct V_62 * V_63 , T_3 V_64 )
{
struct V_1 * V_2 ;
struct V_61 * V_65 ;
struct V_26 * V_27 ;
V_65 = F_26 ( V_63 , sizeof( * V_27 ) , V_64 ) ;
if ( ! V_65 )
return NULL ;
V_2 = V_65 -> V_20 ;
V_2 -> V_66 = V_67 ;
V_27 = V_2 -> V_20 ;
V_2 -> V_20 = V_27 ;
V_27 -> V_1 = V_2 ;
return V_65 ;
}
static void
F_27 ( struct V_61 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_20 ;
struct V_26 * V_27 = V_2 -> V_20 ;
struct V_27 * V_30 = V_27 -> V_30 ;
F_28 ( V_65 ) ;
if ( V_30 ) {
V_30 -> V_27 = NULL ;
F_29 ( V_30 , 1 ) ;
}
}
static int
F_30 ( struct V_62 * V_63 ,
struct V_61 * V_65 , T_4 V_68 ,
int V_69 )
{
struct V_1 * V_2 = V_65 -> V_20 ;
struct V_26 * V_27 ;
struct V_27 * V_30 ;
struct V_70 * V_71 ;
int error ;
error = F_31 ( V_63 , V_65 , V_69 ) ;
if ( error )
return error ;
V_71 = F_32 ( V_68 ) ;
if ( ! V_71 ) {
F_33 ( L_7 ,
( unsigned long long ) V_68 ) ;
return - V_72 ;
}
V_30 = V_71 -> V_20 ;
F_33 ( L_8 ,
V_2 , V_2 -> V_20 , V_30 ) ;
V_27 = V_2 -> V_20 ;
V_30 -> V_27 = V_27 ;
V_27 -> V_30 = V_30 ;
F_34 ( V_30 ) ;
return 0 ;
}
static void
F_35 ( struct V_61 * V_65 , int V_73 )
{
struct V_1 * V_2 = V_65 -> V_20 ;
struct V_26 * V_27 = V_2 -> V_20 ;
struct V_27 * V_30 = V_27 -> V_30 ;
if ( V_30 ) {
F_36 ( V_65 , V_73 ) ;
F_29 ( V_30 , 1 ) ;
}
V_27 -> V_30 = NULL ;
}
static int
F_37 ( struct V_61 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_20 ;
int V_74 ;
V_74 = F_38 ( V_2 ) ;
if ( V_74 )
return V_74 ;
return F_39 ( V_65 ) ;
}
static void F_40 ( struct V_62 * V_63 )
{
struct V_75 * V_76 = F_41 ( V_63 ) ;
F_42 ( V_63 ) ;
F_43 ( V_76 ) ;
F_44 ( V_76 ) ;
}
static struct V_62 *
F_45 ( struct V_70 * V_71 ,
T_5 V_77 , T_5 V_78 ,
T_3 V_79 )
{
struct V_62 * V_63 ;
struct V_80 * V_81 ;
struct V_75 * V_76 ;
struct V_27 * V_30 ;
V_76 = F_46 ( & V_82 , 0 , 0 ) ;
if ( ! V_76 )
return NULL ;
V_76 -> V_83 = V_84 ;
V_76 -> V_85 = V_86 ;
V_76 -> V_87 = 0 ;
V_76 -> V_88 = 0 ;
V_76 -> V_89 = 16 ;
if ( V_71 )
V_30 = V_71 -> V_20 ;
if ( F_47 ( V_76 ,
V_71 ? V_30 -> V_29 -> V_32 -> V_90 : NULL ) )
goto V_91;
V_63 = F_48 ( & V_92 , V_76 ,
V_93 , 0 ,
sizeof( struct V_18 ) ,
V_79 , 0 ) ;
if ( ! V_63 )
goto V_94;
V_81 = V_63 -> V_20 ;
V_76 -> V_95 = V_81 -> V_96 ;
return V_63 ;
V_94:
F_43 ( V_76 ) ;
V_91:
F_44 ( V_76 ) ;
return NULL ;
}
static int
F_49 ( struct V_61 * V_65 ,
enum V_97 V_98 , char * V_99 , int V_100 )
{
int V_101 ;
switch ( V_98 ) {
case V_102 :
break;
case V_103 :
sscanf ( V_99 , L_9 , & V_101 ) ;
if ( V_101 ) {
F_3 ( V_11 L_10 ) ;
return - V_104 ;
}
break;
case V_105 :
sscanf ( V_99 , L_9 , & V_101 ) ;
if ( V_101 ) {
F_3 ( V_11 L_10 ) ;
return - V_104 ;
}
break;
case V_106 :
sscanf ( V_99 , L_9 , & V_101 ) ;
if ( V_101 ) {
F_3 ( V_11 L_11 ) ;
return - V_104 ;
}
break;
case V_107 :
sscanf ( V_99 , L_9 , & V_101 ) ;
if ( V_101 ) {
F_3 ( V_11 L_12 ) ;
return - V_104 ;
}
break;
default:
return F_50 ( V_65 , V_98 , V_99 , V_100 ) ;
}
return 0 ;
}
static void
F_51 ( struct V_61 * V_65 , struct V_108 * V_109 )
{
struct V_1 * V_2 = V_65 -> V_20 ;
V_109 -> V_110 = V_2 -> V_110 ;
V_109 -> V_111 = V_2 -> V_111 ;
V_109 -> V_112 = V_2 -> V_113 ;
V_109 -> V_114 = V_2 -> V_115 ;
V_109 -> V_116 = V_2 -> V_117 ;
V_109 -> V_118 = V_2 -> V_119 ;
V_109 -> V_120 = V_2 -> V_121 ;
V_109 -> V_122 = V_2 -> V_123 ;
V_109 -> V_124 = V_2 -> V_125 ;
V_109 -> V_126 = 4 ;
strcpy ( V_109 -> V_127 [ 0 ] . V_21 , L_13 ) ;
V_109 -> V_127 [ 0 ] . V_101 = 0 ;
strcpy ( V_109 -> V_127 [ 1 ] . V_21 , L_14 ) ;
V_109 -> V_127 [ 1 ] . V_101 = 0 ; ;
strcpy ( V_109 -> V_127 [ 2 ] . V_21 , L_15 ) ;
V_109 -> V_127 [ 2 ] . V_101 = V_2 -> V_128 ;
strcpy ( V_109 -> V_127 [ 3 ] . V_21 , L_16 ) ;
V_109 -> V_127 [ 3 ] . V_101 = V_2 -> V_129 ;
}
static int F_52 ( struct V_70 * V_71 ,
enum V_97 V_98 , char * V_99 )
{
struct V_27 * V_30 = V_71 -> V_20 ;
int V_130 ;
switch ( V_98 ) {
case V_131 :
case V_132 :
if ( ! V_30 || ! V_30 -> V_133 )
return - V_134 ;
return F_53 ( (struct V_135 * )
& V_30 -> V_133 -> V_136 . V_37 . V_137 ,
V_98 , V_99 ) ;
break;
default:
return - V_138 ;
}
return V_130 ;
}
static struct V_70 *
F_54 ( struct V_75 * V_76 , struct V_139 * V_137 ,
int V_140 )
{
int V_74 ;
struct V_27 * V_30 ;
struct V_70 * V_71 ;
V_71 = F_55 ( sizeof( * V_30 ) ) ;
if ( ! V_71 )
return F_56 ( - V_35 ) ;
V_30 = V_71 -> V_20 ;
V_30 -> V_71 = V_71 ;
F_57 ( V_30 ) ;
V_74 = F_58 ( V_30 , NULL , (struct V_141 * ) V_137 ,
V_140 ) ;
if ( V_74 ) {
F_59 ( V_71 ) ;
return F_56 ( V_74 ) ;
}
return V_71 ;
}
static int
F_60 ( struct V_70 * V_71 , int V_142 )
{
struct V_27 * V_30 ;
int V_7 ;
V_30 = V_71 -> V_20 ;
V_7 = F_61 ( V_30 -> V_143 ,
V_30 -> V_144 == V_145 ,
F_62 ( V_142 ) ) ;
if ( ! V_7 &&
( V_30 -> V_144 == V_146 ||
V_30 -> V_144 == V_147 ) )
V_7 = - 1 ;
F_33 ( L_17 , V_30 , V_7 ) ;
if ( V_7 > 0 )
return 1 ;
else if ( ! V_7 )
return 0 ;
else
return V_7 ;
}
static void
F_63 ( struct V_70 * V_71 )
{
struct V_27 * V_30 ;
V_30 = V_71 -> V_20 ;
if ( V_30 -> V_27 )
F_64 ( V_30 -> V_27 -> V_1 ) ;
F_33 ( L_18 , V_30 , V_30 -> V_144 ) ;
F_65 ( V_30 ) ;
}
static int T_6 F_66 ( void )
{
int V_74 ;
F_13 ( L_19 ) ;
if ( V_86 < 1 ) {
F_3 ( V_11 L_20 , V_86 ) ;
return - V_72 ;
}
memset ( & V_148 , 0 , sizeof( struct V_149 ) ) ;
V_148 . V_150 = F_67 ( L_21 ,
sizeof( struct V_24 ) ,
0 , V_151 ,
NULL ) ;
if ( V_148 . V_150 == NULL )
return - V_35 ;
F_68 ( & V_148 . V_152 ) ;
F_69 ( & V_148 . V_153 ) ;
F_68 ( & V_148 . V_154 ) ;
F_69 ( & V_148 . V_155 ) ;
V_84 = F_70 (
& V_92 ) ;
if ( ! V_84 ) {
F_33 ( L_22 ) ;
V_74 = - V_72 ;
goto V_156;
}
return 0 ;
V_156:
F_71 ( V_148 . V_150 ) ;
return V_74 ;
}
static void T_7 F_72 ( void )
{
F_13 ( L_23 ) ;
F_73 ( & V_92 ) ;
F_71 ( V_148 . V_150 ) ;
}
