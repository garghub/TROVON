static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 () ;
if ( ! V_2 -> V_4 )
return - V_5 ;
V_2 -> V_4 -> V_6 = V_2 -> V_7 -> V_8 ;
V_2 -> V_4 -> V_9 = V_2 -> V_7 -> V_10 ;
V_2 -> V_4 -> V_11 . V_12 = V_13 ;
V_2 -> V_4 -> V_14 . V_15 = & V_2 -> V_16 -> V_14 ;
F_3 ( V_17 , V_2 -> V_4 -> V_18 ) ;
V_3 = F_4 ( V_2 -> V_4 , V_2 -> V_7 -> V_19 , NULL ) ;
if ( V_3 )
goto V_20;
V_3 = F_5 ( V_2 -> V_4 ) ;
if ( V_3 )
goto V_20;
return 0 ;
V_20:
F_6 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_8 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
static int F_9 ( T_1 V_21 , T_1 V_22 , T_1 V_23 ,
T_1 * V_24 )
{
struct V_25 args = {
. V_22 = V_22 ,
. V_23 = V_23 ,
} ;
struct V_26 V_27 = { ( V_28 ) sizeof( args ) , & args } ;
struct V_26 V_29 = { V_30 , NULL } ;
T_2 V_31 ;
union V_32 * V_33 ;
T_1 V_34 = 0 ;
V_31 = F_10 ( V_35 , 0 , V_21 ,
& V_27 , & V_29 ) ;
if ( F_11 ( V_31 ) )
goto exit;
V_33 = (union V_32 * ) V_29 . V_36 ;
if ( V_33 && V_33 -> type == V_37 )
V_34 = ( T_1 ) V_33 -> integer . V_38 ;
if ( V_24 )
* V_24 = V_34 ;
F_12 ( V_33 ) ;
exit:
if ( F_11 ( V_31 ) )
return - V_39 ;
if ( V_34 == V_40 )
return - V_41 ;
return 0 ;
}
static int F_13 ( const struct V_26 args )
{
struct V_26 V_27 ;
T_3 V_42 ;
T_1 V_24 ;
T_1 V_31 = - 1 ;
V_27 . V_36 = F_14 ( args . V_43 , V_44 | V_45 ) ;
V_27 . V_43 = args . V_43 ;
if ( ! V_27 . V_36 )
return - V_5 ;
V_42 = F_15 ( V_27 . V_36 ) ;
memcpy ( V_27 . V_36 , args . V_36 , args . V_43 ) ;
V_31 = F_9 ( V_46 ,
V_42 , 0 , & V_24 ) ;
if ( ! V_31 )
memcpy ( args . V_36 , V_27 . V_36 , args . V_43 ) ;
F_12 ( V_27 . V_36 ) ;
if ( V_31 )
return - V_47 ;
return V_24 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_48 , T_1 * V_24 )
{
return F_9 ( V_2 -> V_49 , V_48 , 0 , V_24 ) ;
}
static int F_17 ( T_1 V_48 , T_1 V_50 ,
T_1 * V_24 )
{
return F_9 ( V_51 , V_48 ,
V_50 , V_24 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_48 , T_1 V_52 )
{
T_1 V_24 = 0 ;
int V_3 ;
V_3 = F_16 ( V_2 , V_48 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! ( V_24 & V_53 ) )
return - V_41 ;
if ( V_52 == V_54 ) {
if ( V_24 & V_55 )
return - V_41 ;
}
return V_24 & V_52 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_48 )
{
return F_18 ( V_2 , V_48 ,
V_54 ) ;
}
static void F_20 ( struct V_56 * V_57 )
{
int V_50 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_57 , struct V_1 , V_58 ) ;
V_50 = V_2 -> V_59 ;
F_17 ( V_60 , V_50 , NULL ) ;
}
static void F_22 ( struct V_61 * V_62 ,
enum V_63 V_38 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_62 , struct V_1 , V_64 ) ;
V_2 -> V_59 = ! ! V_38 ;
F_23 ( V_2 -> V_65 , & V_2 -> V_58 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_19 ( V_2 , V_60 ) ;
}
static enum V_63 F_25 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_62 , struct V_1 , V_64 ) ;
return F_24 ( V_2 ) ;
}
static void F_26 ( struct V_56 * V_57 )
{
int V_50 = 0 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_57 , struct V_1 , V_66 ) ;
if ( V_2 -> V_67 > 0 )
V_50 = 0x80 | ( V_2 -> V_67 & 0x7F ) ;
F_17 ( V_68 , V_50 , NULL ) ;
}
static int F_27 ( struct V_1 * V_2 , int * V_69 , int * V_70 )
{
int V_24 ;
V_24 = F_18 ( V_2 , V_68 ,
0xFFFF ) ;
if ( V_24 == 0x8000 )
V_24 = 0 ;
if ( V_24 >= 0 ) {
if ( V_69 )
* V_69 = V_24 & 0x7F ;
if ( V_70 )
* V_70 = ( V_24 >> 8 ) & 0x7F ;
V_24 = 0 ;
}
return V_24 ;
}
static void F_28 ( struct V_61 * V_62 ,
enum V_63 V_38 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_62 , struct V_1 , V_71 ) ;
if ( V_38 > V_2 -> V_71 . V_72 )
V_38 = V_2 -> V_71 . V_72 ;
else if ( V_38 < 0 )
V_38 = 0 ;
V_2 -> V_67 = V_38 ;
F_23 ( V_2 -> V_65 , & V_2 -> V_66 ) ;
}
static enum V_63 F_29 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
int V_24 , V_38 ;
V_2 = F_21 ( V_62 , struct V_1 , V_71 ) ;
V_24 = F_27 ( V_2 , & V_38 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
return V_38 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_73 ;
F_16 ( V_2 , V_74 , & V_73 ) ;
return V_73 & V_55 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_73 ;
F_16 ( V_2 , V_74 , & V_73 ) ;
return V_73 & V_53 ;
}
static void F_32 ( struct V_56 * V_57 )
{
int V_50 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_57 , struct V_1 , V_75 ) ;
V_50 = V_2 -> V_76 ;
F_17 ( V_74 , V_50 , NULL ) ;
}
static void F_33 ( struct V_61 * V_62 ,
enum V_63 V_38 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_62 , struct V_1 , V_77 ) ;
V_2 -> V_76 = ! ! V_38 ;
F_23 ( V_2 -> V_65 , & V_2 -> V_75 ) ;
}
static enum V_63 F_34 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
T_1 V_73 ;
V_2 = F_21 ( V_62 , struct V_1 , V_77 ) ;
F_16 ( V_2 , V_74 , & V_73 ) ;
return V_73 & V_78 ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( ! F_36 ( V_2 -> V_71 . V_14 ) )
F_37 ( & V_2 -> V_71 ) ;
if ( ! F_36 ( V_2 -> V_64 . V_14 ) )
F_37 ( & V_2 -> V_64 ) ;
if ( ! F_36 ( V_2 -> V_77 . V_14 ) )
F_37 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_65 )
F_38 ( V_2 -> V_65 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_79 = 0 , V_80 ;
V_2 -> V_65 = F_40 ( L_1 ) ;
if ( ! V_2 -> V_65 )
return - V_5 ;
if ( F_24 ( V_2 ) >= 0 ) {
F_41 ( & V_2 -> V_58 , F_20 ) ;
V_2 -> V_64 . V_6 = L_2 ;
V_2 -> V_64 . V_81 = F_22 ;
V_2 -> V_64 . V_82 = F_25 ;
V_2 -> V_64 . V_72 = 1 ;
V_79 = F_42 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_64 ) ;
if ( V_79 )
goto error;
}
V_80 = F_27 ( V_2 , NULL , NULL ) ;
if ( V_80 >= 0 ) {
F_41 ( & V_2 -> V_66 , F_26 ) ;
V_2 -> V_67 = V_80 ;
V_2 -> V_71 . V_6 = L_3 ;
V_2 -> V_71 . V_81 = F_28 ;
V_2 -> V_71 . V_82 = F_29 ;
V_2 -> V_71 . V_72 = 3 ;
V_79 = F_42 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_71 ) ;
if ( V_79 )
goto error;
}
if ( F_31 ( V_2 ) && ( V_2 -> V_7 -> V_83 -> V_84 > 0 ) ) {
F_41 ( & V_2 -> V_75 , F_32 ) ;
V_2 -> V_77 . V_6 = L_4 ;
V_2 -> V_77 . V_81 = F_33 ;
if ( ! F_30 ( V_2 ) )
V_2 -> V_77 . V_82 = F_34 ;
V_2 -> V_77 . V_85 = V_86 ;
V_2 -> V_77 . V_72 = 1 ;
V_2 -> V_77 . V_87 = L_5 ;
V_79 = F_42 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_77 ) ;
}
error:
if ( V_79 )
F_35 ( V_2 ) ;
return V_79 ;
}
static bool F_43 ( struct V_1 * V_2 )
{
int V_73 = F_19 ( V_2 , V_88 ) ;
if ( V_73 < 0 )
return false ;
return ! V_73 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_89 * V_14 ;
struct V_90 * V_91 ;
bool V_92 ;
bool V_93 ;
T_1 V_94 ;
F_45 ( & V_2 -> V_95 ) ;
V_92 = F_43 ( V_2 ) ;
F_46 ( & V_2 -> V_95 ) ;
F_45 ( & V_2 -> V_96 ) ;
F_47 () ;
if ( V_2 -> V_97 . V_98 )
F_48 ( V_2 -> V_97 . V_98 , V_92 ) ;
if ( V_2 -> V_99 ) {
V_91 = F_49 ( 0 , 1 ) ;
if ( ! V_91 ) {
F_50 ( L_6 ) ;
goto V_100;
}
if ( F_51 ( V_91 , 0 , V_101 , & V_94 ) ) {
F_52 ( L_7 ) ;
goto V_100;
}
V_93 = ( V_94 == 0xffffffff ) ;
if ( V_92 != V_93 ) {
F_50 ( L_8
L_9 ,
V_92 ? L_10 : L_11 ,
V_93 ? L_12 : L_13 ) ;
F_50 ( L_14
L_15 ) ;
goto V_100;
}
if ( ! V_92 ) {
V_14 = F_53 ( V_91 , 0 ) ;
if ( V_14 ) {
F_54 ( V_14 ) ;
goto V_100;
}
V_14 = F_55 ( V_91 , 0 ) ;
if ( V_14 ) {
F_56 ( V_91 ) ;
F_57 ( V_14 ) ;
}
} else {
V_14 = F_53 ( V_91 , 0 ) ;
if ( V_14 ) {
F_58 ( V_14 ) ;
F_54 ( V_14 ) ;
}
}
}
V_100:
F_59 () ;
F_46 ( & V_2 -> V_96 ) ;
}
static void F_60 ( T_4 V_102 , T_1 V_103 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
if ( V_103 != V_105 )
return;
F_23 ( V_2 -> V_106 , & V_2 -> V_107 ) ;
}
static int F_61 ( struct V_1 * V_2 , char * V_108 )
{
T_2 V_31 ;
T_4 V_102 ;
V_31 = F_62 ( NULL , V_108 , & V_102 ) ;
if ( F_63 ( V_31 ) ) {
V_31 = F_64 ( V_102 ,
V_109 ,
F_60 , V_2 ) ;
if ( F_11 ( V_31 ) )
F_50 ( L_16 , V_108 ) ;
} else
return - V_41 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , char * V_108 )
{
T_2 V_31 = V_110 ;
T_4 V_102 ;
V_31 = F_62 ( NULL , V_108 , & V_102 ) ;
if ( F_63 ( V_31 ) ) {
V_31 = F_66 ( V_102 ,
V_109 ,
F_60 ) ;
if ( F_11 ( V_31 ) )
F_52 ( L_17 ,
V_108 ) ;
}
}
static int F_67 ( struct V_99 * V_99 ,
T_5 * V_38 )
{
struct V_1 * V_2 = V_99 -> V_111 ;
int V_73 = F_19 ( V_2 , V_88 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_38 = ! ! V_73 ;
return 0 ;
}
static void F_68 ( struct V_99 * V_99 )
{
F_12 ( V_99 -> V_112 ) ;
F_12 ( V_99 ) ;
}
static void F_69 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_57 , struct V_1 , V_107 ) ;
F_44 ( V_2 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_113 = - V_5 ;
struct V_90 * V_91 = F_49 ( 0 , 1 ) ;
if ( ! V_91 ) {
F_52 ( L_18 ) ;
return - V_41 ;
}
V_2 -> V_106 =
F_40 ( L_19 ) ;
if ( ! V_2 -> V_106 )
goto V_114;
F_41 ( & V_2 -> V_107 , F_69 ) ;
V_2 -> V_99 = F_14 ( sizeof( struct V_99 ) , V_45 ) ;
if ( ! V_2 -> V_99 )
goto V_115;
V_2 -> V_99 -> V_112 = F_14 ( sizeof( struct V_116 ) ,
V_45 ) ;
if ( ! V_2 -> V_99 -> V_112 )
goto V_117;
V_2 -> V_99 -> V_111 = V_2 ;
V_2 -> V_99 -> V_118 = & F_68 ;
V_2 -> V_99 -> V_119 = & V_120 ;
F_67 ( V_2 -> V_99 ,
& V_2 -> V_99 -> V_112 -> V_121 ) ;
V_113 = F_71 ( V_2 -> V_99 , V_91 , 0 , L_20 ) ;
if ( V_113 ) {
F_52 ( L_21 , V_113 ) ;
goto V_122;
}
return 0 ;
V_122:
F_12 ( V_2 -> V_99 -> V_112 ) ;
V_117:
F_12 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
V_115:
F_38 ( V_2 -> V_106 ) ;
V_114:
return V_113 ;
}
static int F_72 ( void * V_104 , bool V_92 )
{
struct V_123 * V_124 = V_104 ;
T_1 V_50 = ! V_92 ;
T_1 V_48 = V_124 -> V_48 ;
if ( ( V_48 == V_88 ) &&
V_124 -> V_2 -> V_7 -> V_125 )
V_48 = V_126 ;
return F_17 ( V_48 , V_50 , NULL ) ;
}
static void F_73 ( struct V_98 * V_98 , void * V_104 )
{
struct V_123 * V_124 = V_104 ;
int V_73 ;
V_73 = F_19 ( V_124 -> V_2 , V_124 -> V_48 ) ;
if ( V_73 < 0 )
return;
F_48 ( V_124 -> V_98 , ! V_73 ) ;
}
static int F_74 ( void * V_104 , bool V_92 )
{
struct V_123 * V_124 = V_104 ;
struct V_1 * V_2 = V_124 -> V_2 ;
int V_113 ;
F_45 ( & V_2 -> V_95 ) ;
V_113 = F_72 ( V_104 , V_92 ) ;
F_46 ( & V_2 -> V_95 ) ;
return V_113 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_123 * V_127 ,
const char * V_6 , enum V_128 type , int V_48 )
{
int V_73 = F_19 ( V_2 , V_48 ) ;
struct V_98 * * V_98 = & V_127 -> V_98 ;
if ( V_73 < 0 )
return V_73 ;
V_127 -> V_48 = V_48 ;
V_127 -> V_2 = V_2 ;
if ( V_48 == V_88 &&
V_2 -> V_7 -> V_83 -> V_129 )
* V_98 = F_76 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_130 , V_127 ) ;
else
* V_98 = F_76 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_131 , V_127 ) ;
if ( ! * V_98 )
return - V_132 ;
if ( ( V_48 == V_88 ) &&
( V_2 -> V_7 -> V_83 -> V_84 > 0 ) )
F_77 ( * V_98 , L_5 ) ;
F_78 ( * V_98 , ! V_73 ) ;
V_73 = F_79 ( * V_98 ) ;
if ( V_73 ) {
F_80 ( * V_98 ) ;
* V_98 = NULL ;
return V_73 ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_65 ( V_2 , L_22 ) ;
F_65 ( V_2 , L_23 ) ;
F_65 ( V_2 , L_24 ) ;
if ( V_2 -> V_97 . V_98 ) {
F_82 ( V_2 -> V_97 . V_98 ) ;
F_80 ( V_2 -> V_97 . V_98 ) ;
V_2 -> V_97 . V_98 = NULL ;
}
F_44 ( V_2 ) ;
if ( V_2 -> V_99 )
F_83 ( V_2 -> V_99 ) ;
if ( V_2 -> V_106 )
F_38 ( V_2 -> V_106 ) ;
if ( V_2 -> V_133 . V_98 ) {
F_82 ( V_2 -> V_133 . V_98 ) ;
F_80 ( V_2 -> V_133 . V_98 ) ;
V_2 -> V_133 . V_98 = NULL ;
}
if ( V_2 -> V_134 . V_98 ) {
F_82 ( V_2 -> V_134 . V_98 ) ;
F_80 ( V_2 -> V_134 . V_98 ) ;
V_2 -> V_134 . V_98 = NULL ;
}
if ( V_2 -> V_135 . V_98 ) {
F_82 ( V_2 -> V_135 . V_98 ) ;
F_80 ( V_2 -> V_135 . V_98 ) ;
V_2 -> V_135 . V_98 = NULL ;
}
if ( V_2 -> V_136 . V_98 ) {
F_82 ( V_2 -> V_136 . V_98 ) ;
F_80 ( V_2 -> V_136 . V_98 ) ;
V_2 -> V_136 . V_98 = NULL ;
}
if ( V_2 -> V_137 . V_98 ) {
F_82 ( V_2 -> V_137 . V_98 ) ;
F_80 ( V_2 -> V_137 . V_98 ) ;
V_2 -> V_137 . V_98 = NULL ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
int V_73 = 0 ;
F_85 ( & V_2 -> V_96 ) ;
F_85 ( & V_2 -> V_95 ) ;
V_73 = F_75 ( V_2 , & V_2 -> V_97 , L_5 ,
V_138 , V_88 ) ;
if ( V_73 && V_73 != - V_41 )
goto exit;
V_73 = F_75 ( V_2 , & V_2 -> V_133 ,
L_25 , V_139 ,
V_140 ) ;
if ( V_73 && V_73 != - V_41 )
goto exit;
V_73 = F_75 ( V_2 , & V_2 -> V_134 , L_26 ,
V_141 , V_142 ) ;
if ( V_73 && V_73 != - V_41 )
goto exit;
V_73 = F_75 ( V_2 , & V_2 -> V_135 , L_27 ,
V_143 , V_144 ) ;
if ( V_73 && V_73 != - V_41 )
goto exit;
V_73 = F_75 ( V_2 , & V_2 -> V_136 , L_28 ,
V_145 , V_146 ) ;
if ( V_73 && V_73 != - V_41 )
goto exit;
V_73 = F_75 ( V_2 , & V_2 -> V_137 , L_29 ,
V_147 , V_148 ) ;
if ( V_73 && V_73 != - V_41 )
goto exit;
if ( ! V_2 -> V_7 -> V_83 -> V_129 )
goto exit;
V_73 = F_70 ( V_2 ) ;
if ( V_73 == - V_149 )
V_73 = 0 ;
F_61 ( V_2 , L_22 ) ;
F_61 ( V_2 , L_23 ) ;
F_61 ( V_2 , L_24 ) ;
F_44 ( V_2 ) ;
exit:
if ( V_73 && V_73 != - V_41 )
F_81 ( V_2 ) ;
if ( V_73 == - V_41 )
V_73 = 0 ;
return V_73 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_89 * V_150 ;
T_1 V_151 ;
T_1 V_152 = V_2 -> V_7 -> V_83 -> V_153 ;
V_150 = F_87 ( V_154 ,
V_155 ,
NULL ) ;
if ( ! V_150 )
return;
F_88 ( V_150 , V_156 ,
& V_151 ) ;
F_89 ( V_150 , V_156 ,
F_90 ( V_152 ) ) ;
F_91 ( L_30 ,
V_151 , V_152 ) ;
}
static void F_92 ( void )
{
F_17 ( V_157 , 1 , NULL ) ;
}
static int F_93 ( struct V_1 * V_2 , int V_158 ,
int * V_159 )
{
struct V_160 args = {
. V_161 . V_162 = sizeof( args ) ,
. V_161 . V_163 = V_164 ,
. V_161 . V_165 = V_166 ,
. V_158 = V_158 ,
. V_159 = 0 ,
} ;
struct V_26 V_27 = { ( V_28 ) sizeof( args ) , & args } ;
int V_31 ;
if ( V_158 != 1 )
return - V_132 ;
V_31 = F_13 ( V_27 ) ;
if ( V_31 || args . V_161 . V_3 )
return - V_47 ;
if ( V_159 )
* V_159 = args . V_159 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , int V_158 ,
int * V_159 )
{
struct V_160 args = {
. V_161 . V_162 = sizeof( args ) ,
. V_161 . V_163 = V_164 ,
. V_161 . V_165 = V_167 ,
. V_158 = V_158 ,
. V_159 = V_159 ? * V_159 : 0 ,
} ;
struct V_26 V_27 = { ( V_28 ) sizeof( args ) , & args } ;
int V_31 ;
if ( V_158 != 1 && V_158 != 0 )
return - V_132 ;
V_31 = F_13 ( V_27 ) ;
if ( V_31 || args . V_161 . V_3 )
return - V_47 ;
if ( V_159 && V_158 == 1 )
V_2 -> V_168 = * V_159 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , int * V_169 )
{
int V_31 ;
int V_159 = 0 ;
* V_169 = 0 ;
V_31 = F_93 ( V_2 , 1 , & V_159 ) ;
if ( ! V_31 )
* V_169 = 1 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_94 ( V_2 , 0 , NULL ) ;
if ( V_31 )
return - V_47 ;
V_2 -> V_170 = false ;
return 0 ;
}
static int F_97 ( struct V_171 * V_14 , int V_158 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_38 ;
int V_113 ;
if ( V_2 -> V_170 )
return - V_47 ;
V_113 = F_93 ( V_2 , V_158 + 1 , & V_38 ) ;
if ( V_113 ) {
F_50 ( L_31 , V_113 ) ;
return - V_47 ;
}
return V_38 ;
}
static void F_99 ( struct V_1 * V_2 , int V_158 , int * V_38 )
{
int V_3 ;
if ( V_2 -> V_168 >= 0 ) {
* V_38 = V_2 -> V_168 ;
return;
}
V_3 = F_16 ( V_2 , V_172 , V_38 ) ;
if ( V_3 < 0 )
return;
* V_38 &= 0xFF ;
if ( * V_38 == 1 )
* V_38 = 85 ;
else if ( * V_38 == 2 )
* V_38 = 170 ;
else if ( * V_38 == 3 )
* V_38 = 255 ;
else if ( * V_38 ) {
F_52 ( L_32 , * V_38 ) ;
* V_38 = - 1 ;
}
}
static T_6 F_100 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_38 ;
F_99 ( V_2 , 0 , & V_38 ) ;
return sprintf ( V_175 , L_33 , V_38 ) ;
}
static T_6 F_101 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 ) {
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_38 ;
int V_177 ;
int V_113 ;
V_113 = F_102 ( V_175 , 10 , & V_38 ) ;
if ( V_113 )
return V_113 ;
V_38 = F_103 ( V_38 , 0 , 255 ) ;
V_177 = F_94 ( V_2 , 1 , & V_38 ) ;
if ( V_177 )
F_50 ( L_34 , V_177 ) ;
else
V_2 -> V_170 = true ;
return V_176 ;
}
static T_6 F_104 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
int V_38 = F_97 ( V_14 , 0 ) ;
return sprintf ( V_175 , L_33 , V_38 < 0 ? - 1 : V_38 * 100 ) ;
}
static T_6 F_105 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
if ( V_2 -> V_170 )
return sprintf ( V_175 , L_33 , V_178 ) ;
return sprintf ( V_175 , L_33 , V_179 ) ;
}
static T_6 F_106 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_31 = 0 ;
int V_177 ;
int V_113 ;
V_113 = F_102 ( V_175 , 10 , & V_177 ) ;
if ( V_113 )
return V_113 ;
if ( V_177 == V_178 )
V_2 -> V_170 = true ;
else
V_31 = F_96 ( V_2 ) ;
if ( V_31 )
return V_31 ;
return V_176 ;
}
static T_6 F_107 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
return sprintf ( V_175 , L_35 , V_180 ) ;
}
static T_6 F_108 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
T_1 V_38 ;
int V_3 ;
V_3 = F_16 ( V_2 , V_181 , & V_38 ) ;
if ( V_3 < 0 )
return V_3 ;
V_38 = F_109 ( ( V_38 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_175 , L_33 , V_38 ) ;
}
static T_8 F_110 ( struct V_182 * V_183 ,
struct V_184 * V_174 , int V_185 )
{
struct V_171 * V_14 = F_21 ( V_183 , struct V_171 , V_183 ) ;
struct V_16 * V_186 = F_111 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_112 ( V_186 ) ;
int V_48 = - 1 ;
int V_187 = - 1 ;
T_1 V_38 = V_40 ;
bool V_188 = true ;
if ( V_174 == & V_189 . V_174 )
V_48 = V_172 ;
else if ( V_174 == & V_190 . V_174 )
V_48 = V_181 ;
if ( V_174 == & V_191 . V_174
|| V_174 == & V_192 . V_174
|| V_174 == & V_189 . V_174
|| V_174 == & V_193 . V_174 ) {
V_187 = 1 ;
}
if ( V_48 != - 1 ) {
int V_3 = F_16 ( V_2 , V_48 , & V_38 ) ;
if ( V_3 < 0 && V_187 == - 1 )
return 0 ;
}
if ( V_48 == V_172 ) {
if ( V_38 == V_40 || V_38 & 0xFFF80000
|| ( ! V_2 -> V_165 && ! ( V_38 & V_53 ) ) )
V_188 = false ;
else
V_188 = V_187 <= V_2 -> V_194 ;
} else if ( V_48 == V_181 ) {
if ( ! V_38 )
V_188 = false ;
} else if ( V_187 <= V_2 -> V_194 && V_187 != - 1 ) {
V_188 = true ;
} else {
V_188 = false ;
}
return V_188 ? V_174 -> V_195 : 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_171 * V_196 ;
V_196 = F_114 ( & V_2 -> V_16 -> V_14 ,
L_36 , V_2 ,
V_197 ) ;
if ( F_115 ( V_196 ) ) {
F_52 ( L_37 ) ;
return F_116 ( V_196 ) ;
}
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_113 ;
if ( V_2 -> V_7 -> V_83 -> V_198 )
V_113 = ! V_2 -> V_7 -> V_199 ;
else
V_113 = F_19 ( V_2 ,
V_200 ) ;
if ( V_113 < 0 )
return V_113 ;
return V_113 ? V_201 : V_202 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_1 V_24 ;
int V_3 ;
V_3 = F_16 ( V_2 , V_203 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_24 = V_24 & V_204 ;
V_24 >>= 8 ;
if ( ! V_24 )
return - V_41 ;
return V_24 ;
}
static int F_119 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_120 ( V_206 ) ;
T_1 V_24 ;
int V_3 ;
V_3 = F_16 ( V_2 , V_203 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_24 & V_78 ;
}
static T_1 F_121 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_120 ( V_206 ) ;
T_1 V_50 = 0 ;
if ( ( V_2 -> V_7 -> V_207 < V_206 -> V_208 . V_207 ) ||
V_206 -> V_208 . V_207 == V_206 -> V_208 . V_72 )
V_50 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_207 > V_206 -> V_208 . V_207 ) ||
V_206 -> V_208 . V_207 == 0 )
V_50 = 0x00008000 ;
V_2 -> V_7 -> V_207 = V_206 -> V_208 . V_207 ;
return V_50 ;
}
static int F_122 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_120 ( V_206 ) ;
T_1 V_50 ;
int V_209 , V_3 = 0 ;
V_209 = F_117 ( V_2 ) ;
if ( V_209 != - V_41 && V_206 -> V_208 . V_209 != V_209 ) {
V_50 = ! ! ( V_206 -> V_208 . V_209 == V_201 ) ;
V_3 = F_17 ( V_200 ,
V_50 , NULL ) ;
if ( V_2 -> V_7 -> V_83 -> V_198 )
V_2 -> V_7 -> V_199 = V_206 -> V_208 . V_209 ;
if ( V_2 -> V_7 -> V_83 -> V_210 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_83 -> V_210 )
V_50 = F_121 ( V_206 ) ;
else
V_50 = V_206 -> V_208 . V_207 ;
V_3 = F_17 ( V_203 ,
V_50 , NULL ) ;
return V_3 ;
}
static int F_123 ( struct V_1 * V_2 , int V_211 )
{
struct V_205 * V_206 = V_2 -> V_205 ;
int V_212 = V_206 -> V_208 . V_207 ;
int V_213 = V_212 ;
if ( V_211 >= V_214 && V_211 <= V_215 )
V_213 = V_211 - V_214 + 1 ;
else if ( V_211 >= V_216 && V_211 <= V_217 )
V_213 = V_211 - V_216 ;
V_206 -> V_208 . V_207 = V_213 ;
F_124 ( V_206 ) ;
F_125 ( V_206 , V_218 ) ;
return V_212 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_205 * V_206 ;
struct V_219 V_208 ;
int V_220 ;
int V_209 ;
V_220 = F_118 ( V_2 ) ;
if ( V_220 < 0 )
return V_220 ;
V_209 = F_117 ( V_2 ) ;
if ( V_209 == - V_41 )
V_209 = V_201 ;
else if ( V_209 < 0 )
return V_209 ;
memset ( & V_208 , 0 , sizeof( struct V_219 ) ) ;
V_208 . type = V_221 ;
V_208 . V_72 = V_220 ;
V_206 = F_127 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_222 , & V_208 ) ;
if ( F_115 ( V_206 ) ) {
F_52 ( L_38 ) ;
return F_116 ( V_206 ) ;
}
V_2 -> V_205 = V_206 ;
if ( V_2 -> V_7 -> V_83 -> V_198 )
V_2 -> V_7 -> V_199 = V_209 ;
V_206 -> V_208 . V_207 = F_119 ( V_206 ) ;
V_206 -> V_208 . V_209 = V_209 ;
F_124 ( V_206 ) ;
V_2 -> V_7 -> V_207 = V_206 -> V_208 . V_207 ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_129 ( V_2 -> V_205 ) ;
V_2 -> V_205 = NULL ;
}
static int F_130 ( int V_211 )
{
if ( ( V_211 >= 0x61 && V_211 <= 0x67 ) ||
( V_211 >= 0x8c && V_211 <= 0x93 ) ||
( V_211 >= 0xa0 && V_211 <= 0xa7 ) ||
( V_211 >= 0xd0 && V_211 <= 0xd5 ) )
return 1 ;
return 0 ;
}
static void F_131 ( T_1 V_38 , void * V_223 )
{
struct V_1 * V_2 = V_223 ;
struct V_26 V_224 = { V_30 , NULL } ;
union V_32 * V_33 ;
T_2 V_31 ;
int V_211 ;
int V_225 ;
unsigned int V_226 = 1 ;
bool V_227 = 1 ;
V_31 = F_132 ( V_38 , & V_224 ) ;
if ( V_31 != V_110 ) {
F_52 ( L_39 , V_31 ) ;
return;
}
V_33 = (union V_32 * ) V_224 . V_36 ;
if ( ! V_33 || V_33 -> type != V_37 )
goto exit;
V_211 = V_33 -> integer . V_38 ;
V_225 = V_211 ;
if ( V_2 -> V_7 -> V_228 ) {
V_2 -> V_7 -> V_228 ( V_2 -> V_7 , & V_211 , & V_226 ,
& V_227 ) ;
if ( V_211 == V_229 )
goto exit;
}
if ( V_211 >= V_214 && V_211 <= V_215 )
V_211 = V_230 ;
else if ( V_211 >= V_216 &&
V_211 <= V_217 )
V_211 = V_231 ;
if ( V_211 == V_231 || V_211 == V_230 ) {
if ( F_133 () == V_232 ) {
F_123 ( V_2 , V_225 ) ;
goto exit;
}
}
if ( F_130 ( V_211 ) &&
V_2 -> V_7 -> V_83 -> V_233 )
goto exit;
if ( ! F_134 ( V_2 -> V_4 , V_211 ,
V_226 , V_227 ) )
F_91 ( L_40 , V_211 ) ;
exit:
F_12 ( V_33 ) ;
}
static int F_135 ( const char * V_175 , unsigned long V_176 , int * V_234 )
{
if ( ! V_176 )
return 0 ;
if ( sscanf ( V_175 , L_41 , V_234 ) != 1 )
return - V_132 ;
return V_176 ;
}
static T_6 F_136 ( struct V_1 * V_2 , int V_235 ,
const char * V_175 , T_7 V_176 )
{
T_1 V_24 ;
int V_79 , V_3 , V_38 ;
V_38 = F_19 ( V_2 , V_235 ) ;
if ( V_38 < 0 )
return V_38 ;
V_79 = F_135 ( V_175 , V_176 , & V_38 ) ;
V_3 = F_17 ( V_235 , V_38 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_79 ;
}
static T_6 F_137 ( struct V_1 * V_2 , int V_235 , char * V_175 )
{
int V_38 = F_19 ( V_2 , V_235 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_175 , L_33 , V_38 ) ;
}
static T_6 F_138 ( struct V_171 * V_14 , struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
int V_38 , V_79 ;
if ( ! V_176 || sscanf ( V_175 , L_41 , & V_38 ) != 1 )
return - V_132 ;
if ( V_38 < 0 || V_38 > 2 )
return - V_132 ;
V_79 = F_9 ( V_236 , V_38 , 0 , NULL ) ;
if ( V_79 < 0 )
return V_79 ;
return V_176 ;
}
static T_8 F_139 ( struct V_182 * V_183 ,
struct V_184 * V_174 , int V_185 )
{
struct V_171 * V_14 = F_21 ( V_183 , struct V_171 , V_183 ) ;
struct V_16 * V_186 = F_111 ( V_14 ) ;
struct V_1 * V_2 = F_112 ( V_186 ) ;
bool V_188 = true ;
int V_235 = - 1 ;
if ( V_174 == & V_237 . V_174 )
V_235 = V_238 ;
else if ( V_174 == & V_239 . V_174 )
V_235 = V_240 ;
else if ( V_174 == & V_241 . V_174 )
V_235 = V_242 ;
else if ( V_174 == & V_243 . V_174 )
V_235 = V_244 ;
else if ( V_174 == & V_245 . V_174 )
V_235 = V_157 ;
if ( V_235 != - 1 )
V_188 = ! ( F_19 ( V_2 , V_235 ) < 0 ) ;
return V_188 ? V_174 -> V_195 : 0 ;
}
static void F_140 ( struct V_16 * V_171 )
{
F_141 ( & V_171 -> V_14 . V_183 , & V_246 ) ;
}
static int F_142 ( struct V_16 * V_171 )
{
return F_143 ( & V_171 -> V_14 . V_183 , & V_246 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_79 ;
if ( ! F_9 ( V_247 , 0 , 0 , & V_79 ) )
F_91 ( L_42 , V_79 ) ;
if ( ! F_9 ( V_248 , 0 , 0x9 , & V_79 ) ) {
F_91 ( L_43 , V_79 >> 16 , V_79 & 0xFF ) ;
V_2 -> V_249 = V_79 ;
}
if ( ! F_9 ( V_250 , 0 , 0 , & V_79 ) ) {
F_91 ( L_44 , V_79 ) ;
V_2 -> V_165 = V_79 ;
}
if ( ! F_9 ( V_251 , 0 , 0 , NULL ) )
V_2 -> V_49 = V_251 ;
else
V_2 -> V_49 = V_252 ;
if ( V_2 -> V_7 -> V_83 -> V_84 >= 0 )
F_17 ( V_253 ,
V_2 -> V_7 -> V_83 -> V_84 , NULL ) ;
return F_142 ( V_2 -> V_16 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_140 ( V_2 -> V_16 ) ;
}
static int F_146 ( struct V_254 * V_255 , void * V_104 )
{
struct V_1 * V_2 = V_255 -> V_111 ;
int V_3 ;
T_1 V_24 = - 1 ;
V_3 = F_16 ( V_2 , V_2 -> V_256 . V_48 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
F_147 ( V_255 , L_45 , V_2 -> V_256 . V_48 , V_24 ) ;
return 0 ;
}
static int F_148 ( struct V_254 * V_255 , void * V_104 )
{
struct V_1 * V_2 = V_255 -> V_111 ;
int V_3 ;
T_1 V_24 = - 1 ;
V_3 = F_17 ( V_2 -> V_256 . V_48 , V_2 -> V_256 . V_50 ,
& V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
F_147 ( V_255 , L_46 , V_2 -> V_256 . V_48 ,
V_2 -> V_256 . V_50 , V_24 ) ;
return 0 ;
}
static int F_149 ( struct V_254 * V_255 , void * V_104 )
{
struct V_1 * V_2 = V_255 -> V_111 ;
struct V_25 args = {
. V_22 = V_2 -> V_256 . V_48 ,
. V_23 = V_2 -> V_256 . V_50 ,
} ;
struct V_26 V_27 = { ( V_28 ) sizeof( args ) , & args } ;
struct V_26 V_29 = { V_30 , NULL } ;
union V_32 * V_33 ;
T_2 V_31 ;
V_31 = F_10 ( V_35 ,
0 , V_2 -> V_256 . V_21 ,
& V_27 , & V_29 ) ;
if ( F_11 ( V_31 ) )
return - V_39 ;
V_33 = (union V_32 * ) V_29 . V_36 ;
if ( V_33 && V_33 -> type == V_37 )
F_147 ( V_255 , L_47 , V_2 -> V_256 . V_21 ,
V_2 -> V_256 . V_48 , V_2 -> V_256 . V_50 ,
( T_1 ) V_33 -> integer . V_38 ) ;
else
F_147 ( V_255 , L_48 , V_2 -> V_256 . V_21 ,
V_2 -> V_256 . V_48 , V_2 -> V_256 . V_50 ,
V_33 ? V_33 -> type : - 1 ) ;
F_12 ( V_33 ) ;
return 0 ;
}
static int F_150 ( struct V_257 * V_257 , struct V_258 * V_258 )
{
struct V_259 * V_108 = V_257 -> V_260 ;
return F_151 ( V_258 , V_108 -> V_261 , V_108 -> V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_153 ( V_2 -> V_256 . V_262 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_263 * V_264 ;
int V_265 ;
V_2 -> V_256 . V_262 = F_155 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_256 . V_262 ) {
F_52 ( L_49 ) ;
goto V_266;
}
V_264 = F_156 ( L_50 , V_267 | V_268 ,
V_2 -> V_256 . V_262 , & V_2 -> V_256 . V_21 ) ;
if ( ! V_264 )
goto V_266;
V_264 = F_156 ( L_51 , V_267 | V_268 ,
V_2 -> V_256 . V_262 , & V_2 -> V_256 . V_48 ) ;
if ( ! V_264 )
goto V_266;
V_264 = F_156 ( L_52 , V_267 | V_268 ,
V_2 -> V_256 . V_262 , & V_2 -> V_256 . V_50 ) ;
if ( ! V_264 )
goto V_266;
for ( V_265 = 0 ; V_265 < F_157 ( V_269 ) ; V_265 ++ ) {
struct V_259 * V_108 = & V_269 [ V_265 ] ;
V_108 -> V_2 = V_2 ;
V_264 = F_158 ( V_108 -> V_6 , V_270 | V_267 ,
V_2 -> V_256 . V_262 , V_108 ,
& V_271 ) ;
if ( ! V_264 ) {
F_52 ( L_53 , V_108 -> V_6 ) ;
goto V_266;
}
}
return 0 ;
V_266:
F_152 ( V_2 ) ;
return - V_5 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_31 ;
V_2 -> V_168 = - 1 ;
V_2 -> V_194 = - 1 ;
V_2 -> V_170 = false ;
V_31 = F_95 ( V_2 , & V_2 -> V_194 ) ;
if ( V_31 ) {
V_2 -> V_194 = 0 ;
F_50 ( L_54 , V_31 ) ;
return - V_47 ;
}
F_91 ( L_55 , V_2 -> V_194 ) ;
return 0 ;
}
static bool F_160 ( void )
{
int V_265 = 0 ;
while ( V_272 [ V_265 ] ) {
if ( F_161 ( V_272 [ V_265 ++ ] ) )
return true ;
}
return false ;
}
static int F_162 ( struct V_16 * V_186 )
{
struct V_273 * V_274 = F_163 ( V_186 -> V_14 . V_7 ) ;
struct V_275 * V_276 = F_164 ( V_274 ) ;
struct V_1 * V_2 ;
const char * V_277 ;
T_2 V_31 ;
int V_3 ;
T_1 V_73 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_276 ;
V_2 -> V_16 = V_186 ;
V_276 -> V_16 = V_186 ;
F_165 ( V_2 -> V_16 , V_2 ) ;
if ( V_276 -> V_278 )
V_276 -> V_278 ( V_2 -> V_7 ) ;
V_3 = F_144 ( V_2 ) ;
if ( V_3 )
goto V_279;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_280;
V_3 = F_159 ( V_2 ) ;
F_96 ( V_2 ) ;
V_3 = F_113 ( V_2 ) ;
if ( V_3 )
goto V_281;
V_3 = F_39 ( V_2 ) ;
if ( V_3 )
goto V_282;
F_16 ( V_2 , V_88 , & V_73 ) ;
if ( V_73 & ( V_53 | V_283 ) )
V_2 -> V_7 -> V_125 = 1 ;
if ( ! ( V_2 -> V_7 -> V_125 && F_160 () ) ) {
V_3 = F_84 ( V_2 ) ;
if ( V_3 )
goto V_284;
}
if ( V_2 -> V_7 -> V_83 -> V_285 )
F_92 () ;
V_277 = F_166 ( V_286 ) ;
if ( V_277 && ! strcmp ( V_277 , L_56 ) )
F_167 ( V_232 ) ;
if ( V_2 -> V_7 -> V_83 -> V_287 )
F_167 ( V_232 ) ;
if ( V_2 -> V_7 -> V_83 -> V_288 )
F_167 ( V_289 ) ;
if ( V_2 -> V_7 -> V_83 -> V_153 )
F_86 ( V_2 ) ;
if ( F_133 () == V_232 ) {
V_3 = F_126 ( V_2 ) ;
if ( V_3 && V_3 != - V_41 )
goto V_290;
}
V_31 = F_168 ( V_2 -> V_7 -> V_291 ,
F_131 , V_2 ) ;
if ( F_11 ( V_31 ) ) {
F_52 ( L_57 , V_31 ) ;
V_3 = - V_41 ;
goto V_292;
}
V_3 = F_154 ( V_2 ) ;
if ( V_3 )
goto V_293;
return 0 ;
V_293:
F_169 ( V_2 -> V_7 -> V_291 ) ;
V_292:
F_128 ( V_2 ) ;
V_290:
F_81 ( V_2 ) ;
V_284:
F_35 ( V_2 ) ;
V_282:
V_281:
F_7 ( V_2 ) ;
V_280:
F_145 ( V_2 ) ;
V_279:
F_12 ( V_2 ) ;
return V_3 ;
}
static int F_170 ( struct V_16 * V_171 )
{
struct V_1 * V_2 ;
V_2 = F_112 ( V_171 ) ;
F_169 ( V_2 -> V_7 -> V_291 ) ;
F_128 ( V_2 ) ;
F_7 ( V_2 ) ;
F_35 ( V_2 ) ;
F_81 ( V_2 ) ;
F_152 ( V_2 ) ;
F_145 ( V_2 ) ;
F_96 ( V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_171 ( struct V_171 * V_171 )
{
struct V_1 * V_2 = F_98 ( V_171 ) ;
if ( V_2 -> V_97 . V_98 ) {
bool V_97 ;
V_97 = F_19 ( V_2 , V_88 ) ;
F_17 ( V_88 , V_97 , NULL ) ;
}
return 0 ;
}
static int F_172 ( struct V_171 * V_171 )
{
struct V_1 * V_2 = F_98 ( V_171 ) ;
if ( ! F_36 ( V_2 -> V_71 . V_14 ) )
F_23 ( V_2 -> V_65 , & V_2 -> V_66 ) ;
return 0 ;
}
static int F_173 ( struct V_171 * V_171 )
{
struct V_1 * V_2 = F_98 ( V_171 ) ;
int V_294 ;
if ( V_2 -> V_97 . V_98 )
F_44 ( V_2 ) ;
if ( V_2 -> V_133 . V_98 ) {
V_294 = ! F_19 ( V_2 ,
V_140 ) ;
F_48 ( V_2 -> V_133 . V_98 , V_294 ) ;
}
if ( V_2 -> V_134 . V_98 ) {
V_294 = ! F_19 ( V_2 , V_142 ) ;
F_48 ( V_2 -> V_134 . V_98 , V_294 ) ;
}
if ( V_2 -> V_135 . V_98 ) {
V_294 = ! F_19 ( V_2 , V_144 ) ;
F_48 ( V_2 -> V_135 . V_98 , V_294 ) ;
}
if ( V_2 -> V_136 . V_98 ) {
V_294 = ! F_19 ( V_2 , V_146 ) ;
F_48 ( V_2 -> V_136 . V_98 , V_294 ) ;
}
if ( V_2 -> V_137 . V_98 ) {
V_294 = ! F_19 ( V_2 , V_148 ) ;
F_48 ( V_2 -> V_137 . V_98 , V_294 ) ;
}
if ( ! F_36 ( V_2 -> V_71 . V_14 ) )
F_23 ( V_2 -> V_65 , & V_2 -> V_66 ) ;
return 0 ;
}
static int F_174 ( struct V_16 * V_186 )
{
struct V_273 * V_274 = F_163 ( V_186 -> V_14 . V_7 ) ;
struct V_275 * V_276 = F_164 ( V_274 ) ;
int V_113 ;
if ( ! F_175 ( V_35 ) ) {
F_50 ( L_58 ) ;
return - V_41 ;
}
if ( V_276 -> V_291 && ! F_175 ( V_276 -> V_291 ) ) {
F_50 ( L_59 ) ;
return - V_41 ;
}
if ( V_276 -> V_295 ) {
V_113 = V_276 -> V_295 ( V_186 ) ;
if ( V_113 )
return V_113 ;
}
return F_162 ( V_186 ) ;
}
int T_9 F_176 ( struct V_275 * V_7 )
{
struct V_273 * V_273 ;
struct V_16 * V_16 ;
if ( V_296 )
return - V_149 ;
V_273 = & V_7 -> V_273 ;
V_273 -> remove = F_170 ;
V_273 -> V_7 . V_297 = V_7 -> V_297 ;
V_273 -> V_7 . V_6 = V_7 -> V_6 ;
V_273 -> V_7 . V_298 = & V_299 ;
V_16 = F_177 ( V_273 ,
F_174 ,
NULL , 0 , NULL , 0 ) ;
if ( F_115 ( V_16 ) )
return F_116 ( V_16 ) ;
V_296 = true ;
return 0 ;
}
void F_178 ( struct V_275 * V_7 )
{
F_179 ( V_7 -> V_16 ) ;
F_180 ( & V_7 -> V_273 ) ;
V_296 = false ;
}
static int T_10 F_181 ( void )
{
if ( ! F_175 ( V_35 ) ) {
F_91 ( L_60 ) ;
return - V_41 ;
}
F_91 ( L_61 ) ;
return 0 ;
}
static void T_11 F_182 ( void )
{
F_91 ( L_62 ) ;
}
