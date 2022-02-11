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
V_18 -> V_40 = 1 ;
V_18 -> V_26 = V_26 ;
return 0 ;
}
static int
F_11 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( ! V_18 -> V_40 )
if ( F_8 ( V_15 , & V_18 -> V_20 ) )
return - V_34 ;
if ( ! V_15 -> V_41 )
return 0 ;
V_18 -> V_42 = 0 ;
F_12 ( V_18 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int error = 0 ;
F_4 ( L_3 , V_2 -> V_43 , V_15 -> V_44 ) ;
error = F_14 ( V_2 , V_15 ) ;
return error ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_45 * V_46 = & V_15 -> V_47 ;
struct V_48 V_4 ;
int error = 0 ;
while ( F_16 ( V_15 ) ) {
F_17 ( V_15 , V_46 , & V_4 ) ;
F_4 ( L_4 ,
V_4 . V_44 , V_46 -> V_49 ) ;
error = F_18 ( V_2 , V_15 , & V_4 ) ;
if ( error ) {
V_46 -> V_50 -- ;
goto V_51;
}
V_46 -> V_52 += V_46 -> V_49 ;
F_4 ( L_5 ,
V_46 -> V_53 - V_46 -> V_52 ) ;
}
V_51:
return error ;
}
static int
F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_18 = V_15 -> V_19 ;
int error = 0 ;
if ( ! V_15 -> V_41 )
return F_13 ( V_2 , V_15 ) ;
if ( V_15 -> V_41 -> V_54 == V_33 ) {
F_20 ( F_21 ( V_15 -> V_41 ) == 0 ) ;
F_4 ( L_6 ,
V_15 -> V_44 , F_21 ( V_15 -> V_41 ) ,
V_15 -> V_55 , V_15 -> V_47 . V_53 ) ;
}
F_4 ( L_7 ,
V_2 -> V_43 , V_15 -> V_44 ) ;
if ( ! V_18 -> V_42 ) {
error = F_22 ( V_2 , V_15 ) ;
if ( error )
goto V_56;
V_18 -> V_42 = 1 ;
}
if ( F_16 ( V_15 ) )
error = F_15 ( V_2 , V_15 ) ;
V_56:
return error ;
}
static void F_23 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
if ( ! V_15 -> V_41 )
return;
if ( V_18 -> V_57 == V_58 ) {
V_18 -> V_57 = V_59 ;
F_24 ( V_18 ) ;
}
}
static struct V_60 *
F_25 ( struct V_61 * V_62 , T_3 V_63 )
{
struct V_1 * V_2 ;
struct V_60 * V_64 ;
struct V_25 * V_26 ;
V_64 = F_26 ( V_62 , sizeof( * V_26 ) , V_63 ) ;
if ( ! V_64 )
return NULL ;
V_2 = V_64 -> V_19 ;
V_2 -> V_65 = V_66 ;
V_26 = V_2 -> V_19 ;
V_2 -> V_19 = V_26 ;
V_26 -> V_1 = V_2 ;
return V_64 ;
}
static void
F_27 ( struct V_60 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
struct V_26 * V_29 = V_26 -> V_29 ;
F_28 ( V_64 ) ;
if ( V_29 ) {
V_29 -> V_26 = NULL ;
F_29 ( V_29 , 1 ) ;
}
}
static int
F_30 ( struct V_61 * V_62 ,
struct V_60 * V_64 , T_4 V_67 ,
int V_68 )
{
struct V_1 * V_2 = V_64 -> V_19 ;
struct V_25 * V_26 ;
struct V_26 * V_29 ;
struct V_69 * V_70 ;
int error ;
error = F_31 ( V_62 , V_64 , V_68 ) ;
if ( error )
return error ;
V_70 = F_32 ( V_67 ) ;
if ( ! V_70 ) {
F_3 ( L_8 ,
( unsigned long long ) V_67 ) ;
return - V_71 ;
}
V_29 = V_70 -> V_19 ;
F_3 ( L_9 ,
V_2 , V_2 -> V_19 , V_29 ) ;
V_26 = V_2 -> V_19 ;
V_29 -> V_26 = V_26 ;
V_26 -> V_29 = V_29 ;
F_33 ( V_29 ) ;
return 0 ;
}
static void
F_34 ( struct V_60 * V_64 , int V_72 )
{
struct V_1 * V_2 = V_64 -> V_19 ;
struct V_25 * V_26 = V_2 -> V_19 ;
struct V_26 * V_29 = V_26 -> V_29 ;
if ( V_29 ) {
F_35 ( V_64 , V_72 ) ;
F_29 ( V_29 , 1 ) ;
}
V_26 -> V_29 = NULL ;
}
static int
F_36 ( struct V_60 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_19 ;
int V_73 ;
V_73 = F_37 ( V_2 ) ;
if ( V_73 )
return V_73 ;
return F_38 ( V_64 ) ;
}
static void F_39 ( struct V_61 * V_62 )
{
struct V_74 * V_75 = F_40 ( V_62 ) ;
F_41 ( V_62 ) ;
F_42 ( V_75 ) ;
F_43 ( V_75 ) ;
}
static struct V_61 *
F_44 ( struct V_69 * V_70 ,
T_5 V_76 , T_5 V_77 ,
T_3 V_78 )
{
struct V_61 * V_62 ;
struct V_79 * V_80 ;
struct V_74 * V_75 ;
struct V_26 * V_29 ;
V_75 = F_45 ( & V_81 , 0 , 0 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_82 = V_83 ;
V_75 -> V_84 = V_85 ;
V_75 -> V_86 = 0 ;
V_75 -> V_87 = 0 ;
V_75 -> V_88 = 16 ;
if ( V_70 )
V_29 = V_70 -> V_19 ;
if ( F_46 ( V_75 ,
V_70 ? V_29 -> V_28 -> V_31 -> V_89 : NULL ) )
goto V_90;
V_62 = F_47 ( & V_91 , V_75 ,
V_92 , 0 ,
sizeof( struct V_17 ) ,
V_78 , 0 ) ;
if ( ! V_62 )
goto V_93;
V_80 = V_62 -> V_19 ;
V_75 -> V_94 = V_80 -> V_95 ;
return V_62 ;
V_93:
F_42 ( V_75 ) ;
V_90:
F_43 ( V_75 ) ;
return NULL ;
}
static int
F_48 ( struct V_60 * V_64 ,
enum V_96 V_97 , char * V_98 , int V_99 )
{
int V_100 ;
switch ( V_97 ) {
case V_101 :
break;
case V_102 :
sscanf ( V_98 , L_10 , & V_100 ) ;
if ( V_100 ) {
F_49 ( V_103 L_11 ) ;
return - V_104 ;
}
break;
case V_105 :
sscanf ( V_98 , L_10 , & V_100 ) ;
if ( V_100 ) {
F_49 ( V_103 L_11 ) ;
return - V_104 ;
}
break;
case V_106 :
sscanf ( V_98 , L_10 , & V_100 ) ;
if ( V_100 ) {
F_49 ( V_103 L_12 ) ;
return - V_104 ;
}
break;
case V_107 :
sscanf ( V_98 , L_10 , & V_100 ) ;
if ( V_100 ) {
F_49 ( V_103 L_13 ) ;
return - V_104 ;
}
break;
default:
return F_50 ( V_64 , V_97 , V_98 , V_99 ) ;
}
return 0 ;
}
static void
F_51 ( struct V_60 * V_64 , struct V_108 * V_109 )
{
struct V_1 * V_2 = V_64 -> V_19 ;
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
strcpy ( V_109 -> V_127 [ 0 ] . V_20 , L_14 ) ;
V_109 -> V_127 [ 0 ] . V_100 = 0 ;
strcpy ( V_109 -> V_127 [ 1 ] . V_20 , L_15 ) ;
V_109 -> V_127 [ 1 ] . V_100 = 0 ; ;
strcpy ( V_109 -> V_127 [ 2 ] . V_20 , L_16 ) ;
V_109 -> V_127 [ 2 ] . V_100 = V_2 -> V_128 ;
strcpy ( V_109 -> V_127 [ 3 ] . V_20 , L_17 ) ;
V_109 -> V_127 [ 3 ] . V_100 = V_2 -> V_129 ;
}
static int F_52 ( struct V_69 * V_70 ,
enum V_96 V_97 , char * V_98 )
{
struct V_26 * V_29 = V_70 -> V_19 ;
int V_130 ;
switch ( V_97 ) {
case V_131 :
case V_132 :
if ( ! V_29 || ! V_29 -> V_133 )
return - V_134 ;
return F_53 ( (struct V_135 * )
& V_29 -> V_133 -> V_136 . V_36 . V_137 ,
V_97 , V_98 ) ;
break;
default:
return - V_138 ;
}
return V_130 ;
}
static struct V_69 *
F_54 ( struct V_74 * V_75 , struct V_139 * V_137 ,
int V_140 )
{
int V_73 ;
struct V_26 * V_29 ;
struct V_69 * V_70 ;
V_70 = F_55 ( sizeof( * V_29 ) ) ;
if ( ! V_70 )
return F_56 ( - V_34 ) ;
V_29 = V_70 -> V_19 ;
V_29 -> V_70 = V_70 ;
F_57 ( V_29 ) ;
V_73 = F_58 ( V_29 , NULL , (struct V_141 * ) V_137 ,
V_140 ) ;
if ( V_73 ) {
F_59 ( V_70 ) ;
return F_56 ( V_73 ) ;
}
return V_70 ;
}
static int
F_60 ( struct V_69 * V_70 , int V_142 )
{
struct V_26 * V_29 ;
int V_7 ;
V_29 = V_70 -> V_19 ;
V_7 = F_61 ( V_29 -> V_143 ,
V_29 -> V_144 == V_145 ,
F_62 ( V_142 ) ) ;
if ( ! V_7 &&
( V_29 -> V_144 == V_146 ||
V_29 -> V_144 == V_147 ) )
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
F_63 ( struct V_69 * V_70 )
{
struct V_26 * V_29 ;
V_29 = V_70 -> V_19 ;
if ( V_29 -> V_26 )
F_64 ( V_29 -> V_26 -> V_1 ) ;
F_3 ( L_19 , V_29 , V_29 -> V_144 ) ;
F_65 ( V_29 ) ;
}
static int T_6 F_66 ( void )
{
int V_73 ;
F_4 ( L_20 ) ;
if ( V_85 < 1 ) {
F_49 ( V_103 L_21 , V_85 ) ;
return - V_71 ;
}
memset ( & V_148 , 0 , sizeof( struct V_149 ) ) ;
V_148 . V_150 = F_67 ( L_22 ,
sizeof( struct V_23 ) ,
0 , V_151 ,
NULL ) ;
if ( V_148 . V_150 == NULL )
return - V_34 ;
F_68 ( & V_148 . V_152 ) ;
F_69 ( & V_148 . V_153 ) ;
F_68 ( & V_148 . V_154 ) ;
F_69 ( & V_148 . V_155 ) ;
V_83 = F_70 (
& V_91 ) ;
if ( ! V_83 ) {
F_3 ( L_23 ) ;
V_73 = - V_71 ;
goto V_156;
}
return 0 ;
V_156:
F_71 ( V_148 . V_150 ) ;
return V_73 ;
}
static void T_7 F_72 ( void )
{
F_4 ( L_24 ) ;
F_73 ( & V_91 ) ;
F_71 ( V_148 . V_150 ) ;
}
