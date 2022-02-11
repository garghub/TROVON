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
goto V_21;
return 0 ;
V_21:
F_6 ( V_2 -> V_4 ) ;
V_20:
F_7 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_6 ( V_2 -> V_4 ) ;
F_9 ( V_2 -> V_4 ) ;
}
V_2 -> V_4 = NULL ;
}
static int F_10 ( T_1 V_22 , T_1 V_23 , T_1 V_24 ,
T_1 * V_25 )
{
struct V_26 args = {
. V_23 = V_23 ,
. V_24 = V_24 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
T_2 V_32 ;
union V_33 * V_34 ;
T_1 V_35 = 0 ;
V_32 = F_11 ( V_36 , 1 , V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
goto exit;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
V_35 = ( T_1 ) V_34 -> integer . V_39 ;
if ( V_25 )
* V_25 = V_35 ;
F_13 ( V_34 ) ;
exit:
if ( F_12 ( V_32 ) )
return - V_40 ;
if ( V_35 == V_41 )
return - V_42 ;
return 0 ;
}
static int F_14 ( const struct V_27 args )
{
struct V_27 V_28 ;
T_3 V_43 ;
T_1 V_25 ;
T_1 V_32 = - 1 ;
V_28 . V_37 = F_15 ( args . V_44 , V_45 | V_46 ) ;
V_28 . V_44 = args . V_44 ;
if ( ! V_28 . V_37 )
return - V_5 ;
V_43 = F_16 ( V_28 . V_37 ) ;
memcpy ( V_28 . V_37 , args . V_37 , args . V_44 ) ;
V_32 = F_10 ( V_47 ,
V_43 , 0 , & V_25 ) ;
if ( ! V_32 )
memcpy ( args . V_37 , V_28 . V_37 , args . V_44 ) ;
F_13 ( V_28 . V_37 ) ;
if ( V_32 )
return - V_48 ;
return V_25 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_49 , T_1 * V_25 )
{
return F_10 ( V_2 -> V_50 , V_49 , 0 , V_25 ) ;
}
static int F_18 ( T_1 V_49 , T_1 V_51 ,
T_1 * V_25 )
{
return F_10 ( V_52 , V_49 ,
V_51 , V_25 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 V_49 , T_1 V_53 )
{
T_1 V_25 = 0 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_49 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! ( V_25 & V_54 ) )
return - V_42 ;
if ( V_53 == V_55 ) {
if ( V_25 & V_56 )
return - V_42 ;
}
return V_25 & V_53 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_49 )
{
return F_19 ( V_2 , V_49 ,
V_55 ) ;
}
static void F_21 ( struct V_57 * V_58 )
{
int V_51 ;
struct V_1 * V_2 ;
V_2 = F_22 ( V_58 , struct V_1 , V_59 ) ;
V_51 = V_2 -> V_60 ;
F_18 ( V_61 , V_51 , NULL ) ;
}
static void F_23 ( struct V_62 * V_63 ,
enum V_64 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_63 , struct V_1 , V_65 ) ;
V_2 -> V_60 = ! ! V_39 ;
F_24 ( V_2 -> V_66 , & V_2 -> V_59 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , V_61 ) ;
}
static enum V_64 F_26 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_63 , struct V_1 , V_65 ) ;
return F_25 ( V_2 ) ;
}
static void F_27 ( struct V_57 * V_58 )
{
int V_51 = 0 ;
struct V_1 * V_2 ;
V_2 = F_22 ( V_58 , struct V_1 , V_67 ) ;
if ( V_2 -> V_68 > 0 )
V_51 = 0x80 | ( V_2 -> V_68 & 0x7F ) ;
F_18 ( V_69 , V_51 , NULL ) ;
}
static int F_28 ( struct V_1 * V_2 , int * V_70 , int * V_71 )
{
int V_25 ;
V_25 = F_19 ( V_2 , V_69 ,
0xFFFF ) ;
if ( V_25 == 0x8000 )
V_25 = 0 ;
if ( V_25 >= 0 ) {
if ( V_70 )
* V_70 = V_25 & 0x7F ;
if ( V_71 )
* V_71 = ( V_25 >> 8 ) & 0x7F ;
V_25 = 0 ;
}
return V_25 ;
}
static void F_29 ( struct V_62 * V_63 ,
enum V_64 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_63 , struct V_1 , V_72 ) ;
if ( V_39 > V_2 -> V_72 . V_73 )
V_39 = V_2 -> V_72 . V_73 ;
else if ( V_39 < 0 )
V_39 = 0 ;
V_2 -> V_68 = V_39 ;
F_24 ( V_2 -> V_66 , & V_2 -> V_67 ) ;
}
static enum V_64 F_30 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
int V_25 , V_39 ;
V_2 = F_22 ( V_63 , struct V_1 , V_72 ) ;
V_25 = F_28 ( V_2 , & V_39 , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
return V_39 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_74 ;
F_17 ( V_2 , V_75 , & V_74 ) ;
return V_74 & V_56 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_74 ;
F_17 ( V_2 , V_75 , & V_74 ) ;
return V_74 & V_54 ;
}
static void F_33 ( struct V_57 * V_58 )
{
int V_51 ;
struct V_1 * V_2 ;
V_2 = F_22 ( V_58 , struct V_1 , V_76 ) ;
V_51 = V_2 -> V_77 ;
F_18 ( V_75 , V_51 , NULL ) ;
}
static void F_34 ( struct V_62 * V_63 ,
enum V_64 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_63 , struct V_1 , V_78 ) ;
V_2 -> V_77 = ! ! V_39 ;
F_24 ( V_2 -> V_66 , & V_2 -> V_76 ) ;
}
static enum V_64 F_35 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
T_1 V_74 ;
V_2 = F_22 ( V_63 , struct V_1 , V_78 ) ;
F_17 ( V_2 , V_75 , & V_74 ) ;
return V_74 & V_79 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( ! F_37 ( V_2 -> V_72 . V_14 ) )
F_38 ( & V_2 -> V_72 ) ;
if ( ! F_37 ( V_2 -> V_65 . V_14 ) )
F_38 ( & V_2 -> V_65 ) ;
if ( ! F_37 ( V_2 -> V_78 . V_14 ) )
F_38 ( & V_2 -> V_78 ) ;
if ( V_2 -> V_66 )
F_39 ( V_2 -> V_66 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_80 = 0 , V_81 ;
V_2 -> V_66 = F_41 ( L_1 ) ;
if ( ! V_2 -> V_66 )
return - V_5 ;
if ( F_25 ( V_2 ) >= 0 ) {
F_42 ( & V_2 -> V_59 , F_21 ) ;
V_2 -> V_65 . V_6 = L_2 ;
V_2 -> V_65 . V_82 = F_23 ;
V_2 -> V_65 . V_83 = F_26 ;
V_2 -> V_65 . V_73 = 1 ;
V_80 = F_43 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_65 ) ;
if ( V_80 )
goto error;
}
V_81 = F_28 ( V_2 , NULL , NULL ) ;
if ( V_81 >= 0 ) {
F_42 ( & V_2 -> V_67 , F_27 ) ;
V_2 -> V_68 = V_81 ;
V_2 -> V_72 . V_6 = L_3 ;
V_2 -> V_72 . V_82 = F_29 ;
V_2 -> V_72 . V_83 = F_30 ;
V_2 -> V_72 . V_73 = 3 ;
V_80 = F_43 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_72 ) ;
if ( V_80 )
goto error;
}
if ( F_32 ( V_2 ) && ( V_2 -> V_7 -> V_84 -> V_85 > 0 ) ) {
F_42 ( & V_2 -> V_76 , F_33 ) ;
V_2 -> V_78 . V_6 = L_4 ;
V_2 -> V_78 . V_82 = F_34 ;
if ( ! F_31 ( V_2 ) )
V_2 -> V_78 . V_83 = F_35 ;
V_2 -> V_78 . V_86 = V_87 ;
V_2 -> V_78 . V_73 = 1 ;
V_2 -> V_78 . V_88 = L_5 ;
V_80 = F_43 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_78 ) ;
}
error:
if ( V_80 )
F_36 ( V_2 ) ;
return V_80 ;
}
static bool F_44 ( struct V_1 * V_2 )
{
int V_74 = F_20 ( V_2 , V_89 ) ;
if ( V_74 < 0 )
return false ;
return ! V_74 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_90 * V_14 ;
struct V_91 * V_92 ;
bool V_93 ;
bool V_94 ;
T_1 V_95 ;
F_46 ( & V_2 -> V_96 ) ;
V_93 = F_44 ( V_2 ) ;
F_47 ( & V_2 -> V_96 ) ;
F_46 ( & V_2 -> V_97 ) ;
F_48 () ;
if ( V_2 -> V_98 . V_99 )
F_49 ( V_2 -> V_98 . V_99 , V_93 ) ;
if ( V_2 -> V_100 ) {
V_92 = F_50 ( 0 , 1 ) ;
if ( ! V_92 ) {
F_51 ( L_6 ) ;
goto V_101;
}
if ( F_52 ( V_92 , 0 , V_102 , & V_95 ) ) {
F_53 ( L_7 ) ;
goto V_101;
}
V_94 = ( V_95 == 0xffffffff ) ;
if ( V_93 != V_94 ) {
F_51 ( L_8
L_9 ,
V_93 ? L_10 : L_11 ,
V_94 ? L_12 : L_13 ) ;
F_51 ( L_14
L_15 ) ;
goto V_101;
}
if ( ! V_93 ) {
V_14 = F_54 ( V_92 , 0 ) ;
if ( V_14 ) {
F_55 ( V_14 ) ;
goto V_101;
}
V_14 = F_56 ( V_92 , 0 ) ;
if ( V_14 ) {
F_57 ( V_92 ) ;
F_58 ( V_14 ) ;
}
} else {
V_14 = F_54 ( V_92 , 0 ) ;
if ( V_14 ) {
F_59 ( V_14 ) ;
F_55 ( V_14 ) ;
}
}
}
V_101:
F_60 () ;
F_47 ( & V_2 -> V_97 ) ;
}
static void F_61 ( T_4 V_103 , T_1 V_104 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
if ( V_104 != V_106 )
return;
F_24 ( V_2 -> V_107 , & V_2 -> V_108 ) ;
}
static int F_62 ( struct V_1 * V_2 , char * V_109 )
{
T_2 V_32 ;
T_4 V_103 ;
V_32 = F_63 ( NULL , V_109 , & V_103 ) ;
if ( F_64 ( V_32 ) ) {
V_32 = F_65 ( V_103 ,
V_110 ,
F_61 , V_2 ) ;
if ( F_12 ( V_32 ) )
F_51 ( L_16 , V_109 ) ;
} else
return - V_42 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , char * V_109 )
{
T_2 V_32 = V_111 ;
T_4 V_103 ;
V_32 = F_63 ( NULL , V_109 , & V_103 ) ;
if ( F_64 ( V_32 ) ) {
V_32 = F_67 ( V_103 ,
V_110 ,
F_61 ) ;
if ( F_12 ( V_32 ) )
F_53 ( L_17 ,
V_109 ) ;
}
}
static int F_68 ( struct V_100 * V_100 ,
T_5 * V_39 )
{
struct V_1 * V_2 = V_100 -> V_112 ;
int V_74 = F_20 ( V_2 , V_89 ) ;
if ( V_74 < 0 )
return V_74 ;
* V_39 = ! ! V_74 ;
return 0 ;
}
static void F_69 ( struct V_100 * V_100 )
{
F_13 ( V_100 -> V_113 ) ;
F_13 ( V_100 ) ;
}
static void F_70 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_58 , struct V_1 , V_108 ) ;
F_45 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_114 = - V_5 ;
struct V_91 * V_92 = F_50 ( 0 , 1 ) ;
if ( ! V_92 ) {
F_53 ( L_18 ) ;
return - V_42 ;
}
V_2 -> V_107 =
F_41 ( L_19 ) ;
if ( ! V_2 -> V_107 )
goto V_115;
F_42 ( & V_2 -> V_108 , F_70 ) ;
V_2 -> V_100 = F_15 ( sizeof( struct V_100 ) , V_46 ) ;
if ( ! V_2 -> V_100 )
goto V_116;
V_2 -> V_100 -> V_113 = F_15 ( sizeof( struct V_117 ) ,
V_46 ) ;
if ( ! V_2 -> V_100 -> V_113 )
goto V_118;
V_2 -> V_100 -> V_112 = V_2 ;
V_2 -> V_100 -> V_119 = & F_69 ;
V_2 -> V_100 -> V_120 = & V_121 ;
F_68 ( V_2 -> V_100 ,
& V_2 -> V_100 -> V_113 -> V_122 ) ;
V_114 = F_72 ( V_2 -> V_100 , V_92 , 0 , L_20 ) ;
if ( V_114 ) {
F_53 ( L_21 , V_114 ) ;
goto V_123;
}
return 0 ;
V_123:
F_13 ( V_2 -> V_100 -> V_113 ) ;
V_118:
F_13 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
V_116:
F_39 ( V_2 -> V_107 ) ;
V_115:
return V_114 ;
}
static int F_73 ( void * V_105 , bool V_93 )
{
struct V_124 * V_125 = V_105 ;
T_1 V_51 = ! V_93 ;
T_1 V_49 = V_125 -> V_49 ;
if ( ( V_49 == V_89 ) &&
V_125 -> V_2 -> V_7 -> V_126 )
V_49 = V_127 ;
return F_18 ( V_49 , V_51 , NULL ) ;
}
static void F_74 ( struct V_99 * V_99 , void * V_105 )
{
struct V_124 * V_125 = V_105 ;
int V_74 ;
V_74 = F_20 ( V_125 -> V_2 , V_125 -> V_49 ) ;
if ( V_74 < 0 )
return;
F_49 ( V_125 -> V_99 , ! V_74 ) ;
}
static int F_75 ( void * V_105 , bool V_93 )
{
struct V_124 * V_125 = V_105 ;
struct V_1 * V_2 = V_125 -> V_2 ;
int V_114 ;
F_46 ( & V_2 -> V_96 ) ;
V_114 = F_73 ( V_105 , V_93 ) ;
F_47 ( & V_2 -> V_96 ) ;
return V_114 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_124 * V_128 ,
const char * V_6 , enum V_129 type , int V_49 )
{
int V_74 = F_20 ( V_2 , V_49 ) ;
struct V_99 * * V_99 = & V_128 -> V_99 ;
if ( V_74 < 0 )
return V_74 ;
V_128 -> V_49 = V_49 ;
V_128 -> V_2 = V_2 ;
if ( V_49 == V_89 &&
V_2 -> V_7 -> V_84 -> V_130 )
* V_99 = F_77 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_131 , V_128 ) ;
else
* V_99 = F_77 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_132 , V_128 ) ;
if ( ! * V_99 )
return - V_133 ;
if ( ( V_49 == V_89 ) &&
( V_2 -> V_7 -> V_84 -> V_85 > 0 ) )
F_78 ( * V_99 , L_5 ) ;
F_79 ( * V_99 , ! V_74 ) ;
V_74 = F_80 ( * V_99 ) ;
if ( V_74 ) {
F_81 ( * V_99 ) ;
* V_99 = NULL ;
return V_74 ;
}
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_66 ( V_2 , L_22 ) ;
F_66 ( V_2 , L_23 ) ;
F_66 ( V_2 , L_24 ) ;
if ( V_2 -> V_98 . V_99 ) {
F_83 ( V_2 -> V_98 . V_99 ) ;
F_81 ( V_2 -> V_98 . V_99 ) ;
V_2 -> V_98 . V_99 = NULL ;
}
F_45 ( V_2 ) ;
if ( V_2 -> V_100 )
F_84 ( V_2 -> V_100 ) ;
if ( V_2 -> V_107 )
F_39 ( V_2 -> V_107 ) ;
if ( V_2 -> V_134 . V_99 ) {
F_83 ( V_2 -> V_134 . V_99 ) ;
F_81 ( V_2 -> V_134 . V_99 ) ;
V_2 -> V_134 . V_99 = NULL ;
}
if ( V_2 -> V_135 . V_99 ) {
F_83 ( V_2 -> V_135 . V_99 ) ;
F_81 ( V_2 -> V_135 . V_99 ) ;
V_2 -> V_135 . V_99 = NULL ;
}
if ( V_2 -> V_136 . V_99 ) {
F_83 ( V_2 -> V_136 . V_99 ) ;
F_81 ( V_2 -> V_136 . V_99 ) ;
V_2 -> V_136 . V_99 = NULL ;
}
if ( V_2 -> V_137 . V_99 ) {
F_83 ( V_2 -> V_137 . V_99 ) ;
F_81 ( V_2 -> V_137 . V_99 ) ;
V_2 -> V_137 . V_99 = NULL ;
}
if ( V_2 -> V_138 . V_99 ) {
F_83 ( V_2 -> V_138 . V_99 ) ;
F_81 ( V_2 -> V_138 . V_99 ) ;
V_2 -> V_138 . V_99 = NULL ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
int V_74 = 0 ;
F_86 ( & V_2 -> V_97 ) ;
F_86 ( & V_2 -> V_96 ) ;
V_74 = F_76 ( V_2 , & V_2 -> V_98 , L_5 ,
V_139 , V_89 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_134 ,
L_25 , V_140 ,
V_141 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_135 , L_26 ,
V_142 , V_143 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_136 , L_27 ,
V_144 , V_145 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_137 , L_28 ,
V_146 , V_147 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_138 , L_29 ,
V_148 , V_149 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
if ( ! V_2 -> V_7 -> V_84 -> V_130 )
goto exit;
V_74 = F_71 ( V_2 ) ;
if ( V_74 == - V_150 )
V_74 = 0 ;
F_62 ( V_2 , L_22 ) ;
F_62 ( V_2 , L_23 ) ;
F_62 ( V_2 , L_24 ) ;
F_45 ( V_2 ) ;
exit:
if ( V_74 && V_74 != - V_42 )
F_82 ( V_2 ) ;
if ( V_74 == - V_42 )
V_74 = 0 ;
return V_74 ;
}
static int F_87 ( struct V_1 * V_2 , int V_151 ,
int * V_152 )
{
struct V_153 args = {
. V_154 . V_155 = sizeof( args ) ,
. V_154 . V_156 = V_157 ,
. V_154 . V_158 = V_159 ,
. V_151 = V_151 ,
. V_152 = 0 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
int V_32 ;
if ( V_151 != 1 )
return - V_133 ;
V_32 = F_14 ( V_28 ) ;
if ( V_32 || args . V_154 . V_3 )
return - V_48 ;
if ( V_152 )
* V_152 = args . V_152 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , int V_151 ,
int * V_152 )
{
struct V_153 args = {
. V_154 . V_155 = sizeof( args ) ,
. V_154 . V_156 = V_157 ,
. V_154 . V_158 = V_160 ,
. V_151 = V_151 ,
. V_152 = V_152 ? * V_152 : 0 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
int V_32 ;
if ( V_151 != 1 && V_151 != 0 )
return - V_133 ;
V_32 = F_14 ( V_28 ) ;
if ( V_32 || args . V_154 . V_3 )
return - V_48 ;
if ( V_152 && V_151 == 1 )
V_2 -> V_161 = * V_152 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int * V_162 )
{
int V_32 ;
int V_152 = 0 ;
* V_162 = 0 ;
V_32 = F_87 ( V_2 , 1 , & V_152 ) ;
if ( ! V_32 )
* V_162 = 1 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_88 ( V_2 , 0 , NULL ) ;
if ( V_32 )
return - V_48 ;
V_2 -> V_163 = false ;
return 0 ;
}
static int F_91 ( struct V_164 * V_14 , int V_151 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_39 ;
int V_114 ;
if ( V_2 -> V_163 )
return - V_48 ;
V_114 = F_87 ( V_2 , V_151 + 1 , & V_39 ) ;
if ( V_114 ) {
F_51 ( L_30 , V_114 ) ;
return - V_48 ;
}
return V_39 ;
}
static void F_93 ( struct V_1 * V_2 , int V_151 , int * V_39 )
{
int V_3 ;
if ( V_2 -> V_161 >= 0 ) {
* V_39 = V_2 -> V_161 ;
return;
}
V_3 = F_17 ( V_2 , V_165 , V_39 ) ;
if ( V_3 < 0 )
return;
* V_39 &= 0xFF ;
if ( * V_39 == 1 )
* V_39 = 85 ;
else if ( * V_39 == 2 )
* V_39 = 170 ;
else if ( * V_39 == 3 )
* V_39 = 255 ;
else if ( * V_39 ) {
F_53 ( L_31 , * V_39 ) ;
* V_39 = - 1 ;
}
}
static T_6 F_94 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
char * V_168 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_39 ;
F_93 ( V_2 , 0 , & V_39 ) ;
return sprintf ( V_168 , L_32 , V_39 ) ;
}
static T_6 F_95 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
const char * V_168 , T_7 V_169 ) {
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_39 ;
int V_170 ;
int V_114 ;
V_114 = F_96 ( V_168 , 10 , & V_39 ) ;
if ( V_114 )
return V_114 ;
V_39 = F_97 ( V_39 , 0 , 255 ) ;
V_170 = F_88 ( V_2 , 1 , & V_39 ) ;
if ( V_170 )
F_51 ( L_33 , V_170 ) ;
else
V_2 -> V_163 = true ;
return V_169 ;
}
static T_6 F_98 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
char * V_168 )
{
int V_39 = F_91 ( V_14 , 0 ) ;
return sprintf ( V_168 , L_32 , V_39 < 0 ? - 1 : V_39 * 100 ) ;
}
static T_6 F_99 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
char * V_168 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
if ( V_2 -> V_163 )
return sprintf ( V_168 , L_32 , V_171 ) ;
return sprintf ( V_168 , L_32 , V_172 ) ;
}
static T_6 F_100 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
const char * V_168 , T_7 V_169 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_32 = 0 ;
int V_170 ;
int V_114 ;
V_114 = F_96 ( V_168 , 10 , & V_170 ) ;
if ( V_114 )
return V_114 ;
if ( V_170 == V_171 )
V_2 -> V_163 = true ;
else
V_32 = F_90 ( V_2 ) ;
if ( V_32 )
return V_32 ;
return V_169 ;
}
static T_6 F_101 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
char * V_168 )
{
return sprintf ( V_168 , L_34 , V_173 ) ;
}
static T_6 F_102 ( struct V_164 * V_14 ,
struct V_166 * V_167 ,
char * V_168 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_174 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_103 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_168 , L_32 , V_39 ) ;
}
static T_8 F_104 ( struct V_175 * V_176 ,
struct V_177 * V_167 , int V_178 )
{
struct V_164 * V_14 = F_22 ( V_176 , struct V_164 , V_176 ) ;
struct V_16 * V_179 = F_105 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_106 ( V_179 ) ;
int V_49 = - 1 ;
int V_180 = - 1 ;
T_1 V_39 = V_41 ;
bool V_181 = true ;
if ( V_167 == & V_182 . V_167 )
V_49 = V_165 ;
else if ( V_167 == & V_183 . V_167 )
V_49 = V_174 ;
if ( V_167 == & V_184 . V_167
|| V_167 == & V_185 . V_167
|| V_167 == & V_182 . V_167
|| V_167 == & V_186 . V_167 ) {
V_180 = 1 ;
}
if ( V_49 != - 1 ) {
int V_3 = F_17 ( V_2 , V_49 , & V_39 ) ;
if ( V_3 < 0 && V_180 == - 1 )
return 0 ;
}
if ( V_49 == V_165 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_158 && ! ( V_39 & V_54 ) ) )
V_181 = false ;
else
V_181 = V_180 <= V_2 -> V_187 ;
} else if ( V_49 == V_174 ) {
if ( ! V_39 )
V_181 = false ;
} else if ( V_180 <= V_2 -> V_187 && V_180 != - 1 ) {
V_181 = true ;
} else {
V_181 = false ;
}
return V_181 ? V_167 -> V_188 : 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_164 * V_189 ;
V_189 = F_108 ( & V_2 -> V_16 -> V_14 ,
L_35 , V_2 ,
V_190 ) ;
if ( F_109 ( V_189 ) ) {
F_53 ( L_36 ) ;
return F_110 ( V_189 ) ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_114 ;
if ( V_2 -> V_7 -> V_84 -> V_191 )
V_114 = ! V_2 -> V_7 -> V_192 ;
else
V_114 = F_20 ( V_2 ,
V_193 ) ;
if ( V_114 < 0 )
return V_114 ;
return V_114 ? V_194 : V_195 ;
}
static int F_112 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_196 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_197 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_113 ( struct V_198 * V_199 )
{
struct V_1 * V_2 = F_114 ( V_199 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_196 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_79 ;
}
static T_1 F_115 ( struct V_198 * V_199 )
{
struct V_1 * V_2 = F_114 ( V_199 ) ;
T_1 V_51 = 0 ;
if ( ( V_2 -> V_7 -> V_200 < V_199 -> V_201 . V_200 ) ||
V_199 -> V_201 . V_200 == V_199 -> V_201 . V_73 )
V_51 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_200 > V_199 -> V_201 . V_200 ) ||
V_199 -> V_201 . V_200 == 0 )
V_51 = 0x00008000 ;
V_2 -> V_7 -> V_200 = V_199 -> V_201 . V_200 ;
return V_51 ;
}
static int F_116 ( struct V_198 * V_199 )
{
struct V_1 * V_2 = F_114 ( V_199 ) ;
T_1 V_51 ;
int V_202 , V_3 = 0 ;
V_202 = F_111 ( V_2 ) ;
if ( V_202 != - V_42 && V_199 -> V_201 . V_202 != V_202 ) {
V_51 = ! ! ( V_199 -> V_201 . V_202 == V_194 ) ;
V_3 = F_18 ( V_193 ,
V_51 , NULL ) ;
if ( V_2 -> V_7 -> V_84 -> V_191 )
V_2 -> V_7 -> V_192 = V_199 -> V_201 . V_202 ;
if ( V_2 -> V_7 -> V_84 -> V_203 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_84 -> V_203 )
V_51 = F_115 ( V_199 ) ;
else
V_51 = V_199 -> V_201 . V_200 ;
V_3 = F_18 ( V_196 ,
V_51 , NULL ) ;
return V_3 ;
}
static int F_117 ( struct V_1 * V_2 , int V_204 )
{
struct V_198 * V_199 = V_2 -> V_198 ;
int V_205 = V_199 -> V_201 . V_200 ;
int V_206 = V_205 ;
if ( V_204 >= V_207 && V_204 <= V_208 )
V_206 = V_204 - V_207 + 1 ;
else if ( V_204 >= V_209 && V_204 <= V_210 )
V_206 = V_204 - V_209 ;
V_199 -> V_201 . V_200 = V_206 ;
F_118 ( V_199 ) ;
F_119 ( V_199 , V_211 ) ;
return V_205 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_198 * V_199 ;
struct V_212 V_201 ;
int V_213 ;
int V_202 ;
V_213 = F_112 ( V_2 ) ;
if ( V_213 < 0 )
return V_213 ;
V_202 = F_111 ( V_2 ) ;
if ( V_202 == - V_42 )
V_202 = V_194 ;
else if ( V_202 < 0 )
return V_202 ;
memset ( & V_201 , 0 , sizeof( struct V_212 ) ) ;
V_201 . type = V_214 ;
V_201 . V_73 = V_213 ;
V_199 = F_121 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_215 , & V_201 ) ;
if ( F_109 ( V_199 ) ) {
F_53 ( L_37 ) ;
return F_110 ( V_199 ) ;
}
V_2 -> V_198 = V_199 ;
if ( V_2 -> V_7 -> V_84 -> V_191 )
V_2 -> V_7 -> V_192 = V_202 ;
V_199 -> V_201 . V_200 = F_113 ( V_199 ) ;
V_199 -> V_201 . V_202 = V_202 ;
F_118 ( V_199 ) ;
V_2 -> V_7 -> V_200 = V_199 -> V_201 . V_200 ;
return 0 ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_123 ( V_2 -> V_198 ) ;
V_2 -> V_198 = NULL ;
}
static int F_124 ( int V_204 )
{
if ( ( V_204 >= 0x61 && V_204 <= 0x67 ) ||
( V_204 >= 0x8c && V_204 <= 0x93 ) ||
( V_204 >= 0xa0 && V_204 <= 0xa7 ) ||
( V_204 >= 0xd0 && V_204 <= 0xd5 ) )
return 1 ;
return 0 ;
}
static void F_125 ( T_1 V_39 , void * V_216 )
{
struct V_1 * V_2 = V_216 ;
struct V_27 V_217 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_204 ;
int V_218 ;
unsigned int V_219 = 1 ;
bool V_220 = 1 ;
V_32 = F_126 ( V_39 , & V_217 ) ;
if ( V_32 != V_111 ) {
F_53 ( L_38 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_217 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_204 = V_34 -> integer . V_39 ;
V_218 = V_204 ;
if ( V_2 -> V_7 -> V_221 ) {
V_2 -> V_7 -> V_221 ( V_2 -> V_7 , & V_204 , & V_219 ,
& V_220 ) ;
if ( V_204 == V_222 )
goto exit;
}
if ( V_204 >= V_207 && V_204 <= V_208 )
V_204 = V_223 ;
else if ( V_204 >= V_209 &&
V_204 <= V_210 )
V_204 = V_224 ;
if ( V_204 == V_224 || V_204 == V_223 ) {
if ( F_127 () == V_225 ) {
F_117 ( V_2 , V_218 ) ;
goto exit;
}
}
if ( F_124 ( V_204 ) &&
V_2 -> V_7 -> V_84 -> V_226 )
goto exit;
if ( ! F_128 ( V_2 -> V_4 , V_204 ,
V_219 , V_220 ) )
F_129 ( L_39 , V_204 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_130 ( const char * V_168 , unsigned long V_169 , int * V_227 )
{
if ( ! V_169 )
return 0 ;
if ( sscanf ( V_168 , L_40 , V_227 ) != 1 )
return - V_133 ;
return V_169 ;
}
static T_6 F_131 ( struct V_1 * V_2 , int V_228 ,
const char * V_168 , T_7 V_169 )
{
T_1 V_25 ;
int V_80 , V_3 , V_39 ;
V_39 = F_20 ( V_2 , V_228 ) ;
if ( V_39 < 0 )
return V_39 ;
V_80 = F_130 ( V_168 , V_169 , & V_39 ) ;
V_3 = F_18 ( V_228 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_80 ;
}
static T_6 F_132 ( struct V_1 * V_2 , int V_228 , char * V_168 )
{
int V_39 = F_20 ( V_2 , V_228 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_168 , L_32 , V_39 ) ;
}
static T_6 F_133 ( struct V_164 * V_14 , struct V_166 * V_167 ,
const char * V_168 , T_7 V_169 )
{
int V_39 , V_80 ;
if ( ! V_169 || sscanf ( V_168 , L_40 , & V_39 ) != 1 )
return - V_133 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_133 ;
V_80 = F_10 ( V_229 , V_39 , 0 , NULL ) ;
if ( V_80 < 0 )
return V_80 ;
return V_169 ;
}
static T_8 F_134 ( struct V_175 * V_176 ,
struct V_177 * V_167 , int V_178 )
{
struct V_164 * V_14 = F_22 ( V_176 , struct V_164 , V_176 ) ;
struct V_16 * V_179 = F_105 ( V_14 ) ;
struct V_1 * V_2 = F_106 ( V_179 ) ;
bool V_181 = true ;
int V_228 = - 1 ;
if ( V_167 == & V_230 . V_167 )
V_228 = V_231 ;
else if ( V_167 == & V_232 . V_167 )
V_228 = V_233 ;
else if ( V_167 == & V_234 . V_167 )
V_228 = V_235 ;
else if ( V_167 == & V_236 . V_167 )
V_228 = V_237 ;
else if ( V_167 == & V_238 . V_167 )
V_228 = V_239 ;
if ( V_228 != - 1 )
V_181 = ! ( F_20 ( V_2 , V_228 ) < 0 ) ;
return V_181 ? V_167 -> V_188 : 0 ;
}
static void F_135 ( struct V_16 * V_164 )
{
F_136 ( & V_164 -> V_14 . V_176 , & V_240 ) ;
}
static int F_137 ( struct V_16 * V_164 )
{
return F_138 ( & V_164 -> V_14 . V_176 , & V_240 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
int V_80 ;
if ( ! F_10 ( V_241 , 0 , 0 , & V_80 ) )
F_129 ( L_41 , V_80 ) ;
if ( ! F_10 ( V_242 , 0 , 0x9 , & V_80 ) ) {
F_129 ( L_42 , V_80 >> 16 , V_80 & 0xFF ) ;
V_2 -> V_243 = V_80 ;
}
if ( ! F_10 ( V_244 , 0 , 0 , & V_80 ) ) {
F_129 ( L_43 , V_80 ) ;
V_2 -> V_158 = V_80 ;
}
if ( ! F_10 ( V_245 , 0 , 0 , NULL ) )
V_2 -> V_50 = V_245 ;
else
V_2 -> V_50 = V_246 ;
if ( V_2 -> V_7 -> V_84 -> V_85 >= 0 )
F_18 ( V_247 ,
V_2 -> V_7 -> V_84 -> V_85 , NULL ) ;
return F_137 ( V_2 -> V_16 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
F_135 ( V_2 -> V_16 ) ;
}
static int F_141 ( struct V_248 * V_249 , void * V_105 )
{
struct V_1 * V_2 = V_249 -> V_112 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_17 ( V_2 , V_2 -> V_250 . V_49 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_142 ( V_249 , L_44 , V_2 -> V_250 . V_49 , V_25 ) ;
return 0 ;
}
static int F_143 ( struct V_248 * V_249 , void * V_105 )
{
struct V_1 * V_2 = V_249 -> V_112 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_18 ( V_2 -> V_250 . V_49 , V_2 -> V_250 . V_51 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_142 ( V_249 , L_45 , V_2 -> V_250 . V_49 ,
V_2 -> V_250 . V_51 , V_25 ) ;
return 0 ;
}
static int F_144 ( struct V_248 * V_249 , void * V_105 )
{
struct V_1 * V_2 = V_249 -> V_112 ;
struct V_26 args = {
. V_23 = V_2 -> V_250 . V_49 ,
. V_24 = V_2 -> V_250 . V_51 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_250 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_142 ( V_249 , L_46 , V_2 -> V_250 . V_22 ,
V_2 -> V_250 . V_49 , V_2 -> V_250 . V_51 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_142 ( V_249 , L_47 , V_2 -> V_250 . V_22 ,
V_2 -> V_250 . V_49 , V_2 -> V_250 . V_51 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_145 ( struct V_251 * V_251 , struct V_252 * V_252 )
{
struct V_253 * V_109 = V_251 -> V_254 ;
return F_146 ( V_252 , V_109 -> V_255 , V_109 -> V_2 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
F_148 ( V_2 -> V_250 . V_256 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_257 * V_258 ;
int V_259 ;
V_2 -> V_250 . V_256 = F_150 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_250 . V_256 ) {
F_53 ( L_48 ) ;
goto V_260;
}
V_258 = F_151 ( L_49 , V_261 | V_262 ,
V_2 -> V_250 . V_256 , & V_2 -> V_250 . V_22 ) ;
if ( ! V_258 )
goto V_260;
V_258 = F_151 ( L_50 , V_261 | V_262 ,
V_2 -> V_250 . V_256 , & V_2 -> V_250 . V_49 ) ;
if ( ! V_258 )
goto V_260;
V_258 = F_151 ( L_51 , V_261 | V_262 ,
V_2 -> V_250 . V_256 , & V_2 -> V_250 . V_51 ) ;
if ( ! V_258 )
goto V_260;
for ( V_259 = 0 ; V_259 < F_152 ( V_263 ) ; V_259 ++ ) {
struct V_253 * V_109 = & V_263 [ V_259 ] ;
V_109 -> V_2 = V_2 ;
V_258 = F_153 ( V_109 -> V_6 , V_264 | V_261 ,
V_2 -> V_250 . V_256 , V_109 ,
& V_265 ) ;
if ( ! V_258 ) {
F_53 ( L_52 , V_109 -> V_6 ) ;
goto V_260;
}
}
return 0 ;
V_260:
F_147 ( V_2 ) ;
return - V_5 ;
}
static int F_154 ( struct V_1 * V_2 )
{
int V_32 ;
V_2 -> V_161 = - 1 ;
V_2 -> V_187 = - 1 ;
V_2 -> V_163 = false ;
V_32 = F_89 ( V_2 , & V_2 -> V_187 ) ;
if ( V_32 ) {
V_2 -> V_187 = 0 ;
F_51 ( L_53 , V_32 ) ;
return - V_48 ;
}
F_129 ( L_54 , V_2 -> V_187 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_179 )
{
struct V_266 * V_267 = F_156 ( V_179 -> V_14 . V_7 ) ;
struct V_268 * V_269 = F_157 ( V_267 ) ;
struct V_1 * V_2 ;
const char * V_270 ;
T_2 V_32 ;
int V_3 ;
T_1 V_74 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_269 ;
V_2 -> V_16 = V_179 ;
V_269 -> V_16 = V_179 ;
F_158 ( V_2 -> V_16 , V_2 ) ;
if ( V_269 -> V_271 )
V_269 -> V_271 ( V_2 -> V_7 ) ;
V_3 = F_139 ( V_2 ) ;
if ( V_3 )
goto V_272;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_273;
V_3 = F_154 ( V_2 ) ;
F_90 ( V_2 ) ;
V_3 = F_107 ( V_2 ) ;
if ( V_3 )
goto V_274;
V_3 = F_40 ( V_2 ) ;
if ( V_3 )
goto V_275;
if ( ! V_2 -> V_7 -> V_84 -> V_276 ) {
V_3 = F_85 ( V_2 ) ;
if ( V_3 )
goto V_277;
}
V_270 = F_159 ( V_278 ) ;
if ( V_270 && ! strcmp ( V_270 , L_55 ) )
F_160 ( V_225 ) ;
if ( V_2 -> V_7 -> V_84 -> V_279 )
F_160 ( V_225 ) ;
if ( V_2 -> V_7 -> V_84 -> V_280 )
F_160 ( V_281 ) ;
if ( F_127 () == V_225 ) {
V_3 = F_120 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_282;
}
V_32 = F_161 ( V_2 -> V_7 -> V_283 ,
F_125 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_53 ( L_56 , V_32 ) ;
V_3 = - V_42 ;
goto V_284;
}
V_3 = F_149 ( V_2 ) ;
if ( V_3 )
goto V_285;
F_17 ( V_2 , V_89 , & V_74 ) ;
if ( V_74 & ( V_54 | V_286 ) )
V_2 -> V_7 -> V_126 = 1 ;
return 0 ;
V_285:
F_162 ( V_2 -> V_7 -> V_283 ) ;
V_284:
F_122 ( V_2 ) ;
V_282:
F_82 ( V_2 ) ;
V_277:
F_36 ( V_2 ) ;
V_275:
V_274:
F_8 ( V_2 ) ;
V_273:
F_140 ( V_2 ) ;
V_272:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_163 ( struct V_16 * V_164 )
{
struct V_1 * V_2 ;
V_2 = F_106 ( V_164 ) ;
F_162 ( V_2 -> V_7 -> V_283 ) ;
F_122 ( V_2 ) ;
F_8 ( V_2 ) ;
F_36 ( V_2 ) ;
F_82 ( V_2 ) ;
F_147 ( V_2 ) ;
F_140 ( V_2 ) ;
F_90 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_164 ( struct V_164 * V_164 )
{
struct V_1 * V_2 = F_92 ( V_164 ) ;
if ( V_2 -> V_98 . V_99 ) {
bool V_98 ;
V_98 = F_20 ( V_2 , V_89 ) ;
F_18 ( V_89 , V_98 , NULL ) ;
}
return 0 ;
}
static int F_165 ( struct V_164 * V_164 )
{
struct V_1 * V_2 = F_92 ( V_164 ) ;
if ( ! F_37 ( V_2 -> V_72 . V_14 ) )
F_24 ( V_2 -> V_66 , & V_2 -> V_67 ) ;
return 0 ;
}
static int F_166 ( struct V_164 * V_164 )
{
struct V_1 * V_2 = F_92 ( V_164 ) ;
int V_287 ;
if ( V_2 -> V_98 . V_99 )
F_45 ( V_2 ) ;
if ( V_2 -> V_134 . V_99 ) {
V_287 = ! F_20 ( V_2 ,
V_141 ) ;
F_49 ( V_2 -> V_134 . V_99 , V_287 ) ;
}
if ( V_2 -> V_135 . V_99 ) {
V_287 = ! F_20 ( V_2 , V_143 ) ;
F_49 ( V_2 -> V_135 . V_99 , V_287 ) ;
}
if ( V_2 -> V_136 . V_99 ) {
V_287 = ! F_20 ( V_2 , V_145 ) ;
F_49 ( V_2 -> V_136 . V_99 , V_287 ) ;
}
if ( V_2 -> V_137 . V_99 ) {
V_287 = ! F_20 ( V_2 , V_147 ) ;
F_49 ( V_2 -> V_137 . V_99 , V_287 ) ;
}
if ( V_2 -> V_138 . V_99 ) {
V_287 = ! F_20 ( V_2 , V_149 ) ;
F_49 ( V_2 -> V_138 . V_99 , V_287 ) ;
}
if ( ! F_37 ( V_2 -> V_72 . V_14 ) )
F_24 ( V_2 -> V_66 , & V_2 -> V_67 ) ;
return 0 ;
}
static int F_167 ( struct V_16 * V_179 )
{
struct V_266 * V_267 = F_156 ( V_179 -> V_14 . V_7 ) ;
struct V_268 * V_269 = F_157 ( V_267 ) ;
int V_114 ;
if ( ! F_168 ( V_36 ) ) {
F_51 ( L_57 ) ;
return - V_42 ;
}
if ( V_269 -> V_283 && ! F_168 ( V_269 -> V_283 ) ) {
F_51 ( L_58 ) ;
return - V_42 ;
}
if ( V_269 -> V_288 ) {
V_114 = V_269 -> V_288 ( V_179 ) ;
if ( V_114 )
return V_114 ;
}
return F_155 ( V_179 ) ;
}
int T_9 F_169 ( struct V_268 * V_7 )
{
struct V_266 * V_266 ;
struct V_16 * V_16 ;
if ( V_289 )
return - V_150 ;
V_266 = & V_7 -> V_266 ;
V_266 -> remove = F_163 ;
V_266 -> V_7 . V_290 = V_7 -> V_290 ;
V_266 -> V_7 . V_6 = V_7 -> V_6 ;
V_266 -> V_7 . V_291 = & V_292 ;
V_16 = F_170 ( V_266 ,
F_167 ,
NULL , 0 , NULL , 0 ) ;
if ( F_109 ( V_16 ) )
return F_110 ( V_16 ) ;
V_289 = true ;
return 0 ;
}
void F_171 ( struct V_268 * V_7 )
{
F_172 ( V_7 -> V_16 ) ;
F_173 ( & V_7 -> V_266 ) ;
V_289 = false ;
}
static int T_10 F_174 ( void )
{
if ( ! F_168 ( V_36 ) ) {
F_129 ( L_59 ) ;
return - V_42 ;
}
F_129 ( L_60 ) ;
return 0 ;
}
static void T_11 F_175 ( void )
{
F_129 ( L_61 ) ;
}
