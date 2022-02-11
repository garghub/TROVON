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
int V_80 = 0 ;
V_2 -> V_66 = F_41 ( L_1 ) ;
if ( ! V_2 -> V_66 )
return - V_5 ;
if ( F_25 ( V_2 ) >= 0 ) {
F_42 ( & V_2 -> V_59 , F_21 ) ;
V_2 -> V_65 . V_6 = L_2 ;
V_2 -> V_65 . V_81 = F_23 ;
V_2 -> V_65 . V_82 = F_26 ;
V_2 -> V_65 . V_73 = 1 ;
V_80 = F_43 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_65 ) ;
if ( V_80 )
goto error;
}
if ( F_28 ( V_2 , NULL , NULL ) >= 0 ) {
F_42 ( & V_2 -> V_67 , F_27 ) ;
V_2 -> V_72 . V_6 = L_3 ;
V_2 -> V_72 . V_81 = F_29 ;
V_2 -> V_72 . V_82 = F_30 ;
V_2 -> V_72 . V_73 = 3 ;
V_80 = F_43 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_72 ) ;
if ( V_80 )
goto error;
}
if ( F_32 ( V_2 ) && ( V_2 -> V_7 -> V_83 -> V_84 > 0 ) ) {
F_42 ( & V_2 -> V_76 , F_33 ) ;
V_2 -> V_78 . V_6 = L_4 ;
V_2 -> V_78 . V_81 = F_34 ;
if ( ! F_31 ( V_2 ) )
V_2 -> V_78 . V_82 = F_35 ;
V_2 -> V_78 . V_85 = V_86 ;
V_2 -> V_78 . V_73 = 1 ;
V_2 -> V_78 . V_87 = L_5 ;
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
int V_74 = F_20 ( V_2 , V_88 ) ;
if ( V_74 < 0 )
return false ;
return ! V_74 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_89 * V_14 ;
struct V_90 * V_91 ;
bool V_92 ;
bool V_93 ;
T_1 V_94 ;
F_46 ( & V_2 -> V_95 ) ;
V_92 = F_44 ( V_2 ) ;
F_47 ( & V_2 -> V_95 ) ;
F_46 ( & V_2 -> V_96 ) ;
F_48 () ;
if ( V_2 -> V_97 . V_98 )
F_49 ( V_2 -> V_97 . V_98 , V_92 ) ;
if ( V_2 -> V_99 ) {
V_91 = F_50 ( 0 , 1 ) ;
if ( ! V_91 ) {
F_51 ( L_6 ) ;
goto V_100;
}
if ( F_52 ( V_91 , 0 , V_101 , & V_94 ) ) {
F_53 ( L_7 ) ;
goto V_100;
}
V_93 = ( V_94 == 0xffffffff ) ;
if ( V_92 != V_93 ) {
F_51 ( L_8
L_9 ,
V_92 ? L_10 : L_11 ,
V_93 ? L_12 : L_13 ) ;
F_51 ( L_14
L_15 ) ;
goto V_100;
}
if ( ! V_92 ) {
V_14 = F_54 ( V_91 , 0 ) ;
if ( V_14 ) {
F_55 ( V_14 ) ;
goto V_100;
}
V_14 = F_56 ( V_91 , 0 ) ;
if ( V_14 ) {
F_57 ( V_91 ) ;
F_58 ( V_14 ) ;
}
} else {
V_14 = F_54 ( V_91 , 0 ) ;
if ( V_14 ) {
F_59 ( V_14 ) ;
F_55 ( V_14 ) ;
}
}
}
V_100:
F_60 () ;
F_47 ( & V_2 -> V_96 ) ;
}
static void F_61 ( T_4 V_102 , T_1 V_103 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
if ( V_103 != V_105 )
return;
F_24 ( V_2 -> V_106 , & V_2 -> V_107 ) ;
}
static int F_62 ( struct V_1 * V_2 , char * V_108 )
{
T_2 V_32 ;
T_4 V_102 ;
V_32 = F_63 ( NULL , V_108 , & V_102 ) ;
if ( F_64 ( V_32 ) ) {
V_32 = F_65 ( V_102 ,
V_109 ,
F_61 , V_2 ) ;
if ( F_12 ( V_32 ) )
F_51 ( L_16 , V_108 ) ;
} else
return - V_42 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , char * V_108 )
{
T_2 V_32 = V_110 ;
T_4 V_102 ;
V_32 = F_63 ( NULL , V_108 , & V_102 ) ;
if ( F_64 ( V_32 ) ) {
V_32 = F_67 ( V_102 ,
V_109 ,
F_61 ) ;
if ( F_12 ( V_32 ) )
F_53 ( L_17 ,
V_108 ) ;
}
}
static int F_68 ( struct V_99 * V_99 ,
T_5 * V_39 )
{
struct V_1 * V_2 = V_99 -> V_111 ;
int V_74 = F_20 ( V_2 , V_88 ) ;
if ( V_74 < 0 )
return V_74 ;
* V_39 = ! ! V_74 ;
return 0 ;
}
static void F_69 ( struct V_99 * V_99 )
{
F_13 ( V_99 -> V_112 ) ;
F_13 ( V_99 ) ;
}
static void F_70 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_58 , struct V_1 , V_107 ) ;
F_45 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_113 = - V_5 ;
struct V_90 * V_91 = F_50 ( 0 , 1 ) ;
if ( ! V_91 ) {
F_53 ( L_18 ) ;
return - V_42 ;
}
V_2 -> V_106 =
F_41 ( L_19 ) ;
if ( ! V_2 -> V_106 )
goto V_114;
F_42 ( & V_2 -> V_107 , F_70 ) ;
V_2 -> V_99 = F_15 ( sizeof( struct V_99 ) , V_46 ) ;
if ( ! V_2 -> V_99 )
goto V_115;
V_2 -> V_99 -> V_112 = F_15 ( sizeof( struct V_116 ) ,
V_46 ) ;
if ( ! V_2 -> V_99 -> V_112 )
goto V_117;
V_2 -> V_99 -> V_111 = V_2 ;
V_2 -> V_99 -> V_118 = & F_69 ;
V_2 -> V_99 -> V_119 = & V_120 ;
F_68 ( V_2 -> V_99 ,
& V_2 -> V_99 -> V_112 -> V_121 ) ;
V_113 = F_72 ( V_2 -> V_99 , V_91 , 0 , L_20 ) ;
if ( V_113 ) {
F_53 ( L_21 , V_113 ) ;
goto V_122;
}
return 0 ;
V_122:
F_13 ( V_2 -> V_99 -> V_112 ) ;
V_117:
F_13 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
V_115:
F_39 ( V_2 -> V_106 ) ;
V_114:
return V_113 ;
}
static int F_73 ( void * V_104 , bool V_92 )
{
struct V_123 * V_124 = V_104 ;
T_1 V_51 = ! V_92 ;
T_1 V_49 = V_124 -> V_49 ;
if ( ( V_49 == V_88 ) &&
V_124 -> V_2 -> V_7 -> V_125 )
V_49 = V_126 ;
return F_18 ( V_49 , V_51 , NULL ) ;
}
static void F_74 ( struct V_98 * V_98 , void * V_104 )
{
struct V_123 * V_124 = V_104 ;
int V_74 ;
V_74 = F_20 ( V_124 -> V_2 , V_124 -> V_49 ) ;
if ( V_74 < 0 )
return;
F_49 ( V_124 -> V_98 , ! V_74 ) ;
}
static int F_75 ( void * V_104 , bool V_92 )
{
struct V_123 * V_124 = V_104 ;
struct V_1 * V_2 = V_124 -> V_2 ;
int V_113 ;
F_46 ( & V_2 -> V_95 ) ;
V_113 = F_73 ( V_104 , V_92 ) ;
F_47 ( & V_2 -> V_95 ) ;
return V_113 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_123 * V_127 ,
const char * V_6 , enum V_128 type , int V_49 )
{
int V_74 = F_20 ( V_2 , V_49 ) ;
struct V_98 * * V_98 = & V_127 -> V_98 ;
if ( V_74 < 0 )
return V_74 ;
V_127 -> V_49 = V_49 ;
V_127 -> V_2 = V_2 ;
if ( V_49 == V_88 &&
V_2 -> V_7 -> V_83 -> V_129 )
* V_98 = F_77 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_130 , V_127 ) ;
else
* V_98 = F_77 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_131 , V_127 ) ;
if ( ! * V_98 )
return - V_132 ;
if ( ( V_49 == V_88 ) &&
( V_2 -> V_7 -> V_83 -> V_84 > 0 ) )
F_78 ( * V_98 , L_5 ) ;
F_79 ( * V_98 , ! V_74 ) ;
V_74 = F_80 ( * V_98 ) ;
if ( V_74 ) {
F_81 ( * V_98 ) ;
* V_98 = NULL ;
return V_74 ;
}
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_66 ( V_2 , L_22 ) ;
F_66 ( V_2 , L_23 ) ;
F_66 ( V_2 , L_24 ) ;
if ( V_2 -> V_97 . V_98 ) {
F_83 ( V_2 -> V_97 . V_98 ) ;
F_81 ( V_2 -> V_97 . V_98 ) ;
V_2 -> V_97 . V_98 = NULL ;
}
F_45 ( V_2 ) ;
if ( V_2 -> V_99 )
F_84 ( V_2 -> V_99 ) ;
if ( V_2 -> V_106 )
F_39 ( V_2 -> V_106 ) ;
if ( V_2 -> V_133 . V_98 ) {
F_83 ( V_2 -> V_133 . V_98 ) ;
F_81 ( V_2 -> V_133 . V_98 ) ;
V_2 -> V_133 . V_98 = NULL ;
}
if ( V_2 -> V_134 . V_98 ) {
F_83 ( V_2 -> V_134 . V_98 ) ;
F_81 ( V_2 -> V_134 . V_98 ) ;
V_2 -> V_134 . V_98 = NULL ;
}
if ( V_2 -> V_135 . V_98 ) {
F_83 ( V_2 -> V_135 . V_98 ) ;
F_81 ( V_2 -> V_135 . V_98 ) ;
V_2 -> V_135 . V_98 = NULL ;
}
if ( V_2 -> V_136 . V_98 ) {
F_83 ( V_2 -> V_136 . V_98 ) ;
F_81 ( V_2 -> V_136 . V_98 ) ;
V_2 -> V_136 . V_98 = NULL ;
}
if ( V_2 -> V_137 . V_98 ) {
F_83 ( V_2 -> V_137 . V_98 ) ;
F_81 ( V_2 -> V_137 . V_98 ) ;
V_2 -> V_137 . V_98 = NULL ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
int V_74 = 0 ;
F_86 ( & V_2 -> V_96 ) ;
F_86 ( & V_2 -> V_95 ) ;
V_74 = F_76 ( V_2 , & V_2 -> V_97 , L_5 ,
V_138 , V_88 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_133 ,
L_25 , V_139 ,
V_140 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_134 , L_26 ,
V_141 , V_142 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_135 , L_27 ,
V_143 , V_144 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_136 , L_28 ,
V_145 , V_146 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
V_74 = F_76 ( V_2 , & V_2 -> V_137 , L_29 ,
V_147 , V_148 ) ;
if ( V_74 && V_74 != - V_42 )
goto exit;
if ( ! V_2 -> V_7 -> V_83 -> V_129 )
goto exit;
V_74 = F_71 ( V_2 ) ;
if ( V_74 == - V_149 )
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
static int F_87 ( struct V_1 * V_2 , int V_150 ,
int * V_151 )
{
struct V_152 args = {
. V_153 . V_154 = sizeof( args ) ,
. V_153 . V_155 = V_156 ,
. V_153 . V_157 = V_158 ,
. V_150 = V_150 ,
. V_151 = 0 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
int V_32 ;
if ( V_150 != 1 )
return - V_132 ;
V_32 = F_14 ( V_28 ) ;
if ( V_32 || args . V_153 . V_3 )
return - V_48 ;
if ( V_151 )
* V_151 = args . V_151 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , int V_150 ,
int * V_151 )
{
struct V_152 args = {
. V_153 . V_154 = sizeof( args ) ,
. V_153 . V_155 = V_156 ,
. V_153 . V_157 = V_159 ,
. V_150 = V_150 ,
. V_151 = V_151 ? * V_151 : 0 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
int V_32 ;
if ( V_150 != 1 && V_150 != 0 )
return - V_132 ;
V_32 = F_14 ( V_28 ) ;
if ( V_32 || args . V_153 . V_3 )
return - V_48 ;
if ( V_151 && V_150 == 1 )
V_2 -> V_160 = * V_151 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int * V_161 )
{
int V_32 ;
int V_151 = 0 ;
* V_161 = 0 ;
V_32 = F_87 ( V_2 , 1 , & V_151 ) ;
if ( ! V_32 )
* V_161 = 1 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_88 ( V_2 , 0 , NULL ) ;
if ( V_32 )
return - V_48 ;
V_2 -> V_162 = false ;
return 0 ;
}
static int F_91 ( struct V_163 * V_14 , int V_150 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_39 ;
int V_113 ;
if ( V_2 -> V_162 )
return - V_48 ;
V_113 = F_87 ( V_2 , V_150 + 1 , & V_39 ) ;
if ( V_113 ) {
F_51 ( L_30 , V_113 ) ;
return - V_48 ;
}
return V_39 ;
}
static void F_93 ( struct V_1 * V_2 , int V_150 , int * V_39 )
{
int V_3 ;
if ( V_2 -> V_160 >= 0 ) {
* V_39 = V_2 -> V_160 ;
return;
}
V_3 = F_17 ( V_2 , V_164 , V_39 ) ;
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
static T_6 F_94 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
char * V_167 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_39 ;
F_93 ( V_2 , 0 , & V_39 ) ;
return sprintf ( V_167 , L_32 , V_39 ) ;
}
static T_6 F_95 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
const char * V_167 , T_7 V_168 ) {
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_39 ;
int V_169 ;
int V_113 ;
V_113 = F_96 ( V_167 , 10 , & V_39 ) ;
if ( V_113 )
return V_113 ;
V_39 = F_97 ( V_39 , 0 , 255 ) ;
V_169 = F_88 ( V_2 , 1 , & V_39 ) ;
if ( V_169 )
F_51 ( L_33 , V_169 ) ;
else
V_2 -> V_162 = true ;
return V_168 ;
}
static T_6 F_98 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
char * V_167 )
{
int V_39 = F_91 ( V_14 , 0 ) ;
return sprintf ( V_167 , L_32 , V_39 < 0 ? - 1 : V_39 * 100 ) ;
}
static T_6 F_99 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
char * V_167 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
if ( V_2 -> V_162 )
return sprintf ( V_167 , L_32 , V_170 ) ;
return sprintf ( V_167 , L_32 , V_171 ) ;
}
static T_6 F_100 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
const char * V_167 , T_7 V_168 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_32 = 0 ;
int V_169 ;
int V_113 ;
V_113 = F_96 ( V_167 , 10 , & V_169 ) ;
if ( V_113 )
return V_113 ;
if ( V_169 == V_170 )
V_2 -> V_162 = true ;
else
V_32 = F_90 ( V_2 ) ;
if ( V_32 )
return V_32 ;
return V_168 ;
}
static T_6 F_101 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
char * V_167 )
{
return sprintf ( V_167 , L_34 , V_172 ) ;
}
static T_6 F_102 ( struct V_163 * V_14 ,
struct V_165 * V_166 ,
char * V_167 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_173 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_103 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_167 , L_32 , V_39 ) ;
}
static T_8 F_104 ( struct V_174 * V_175 ,
struct V_176 * V_166 , int V_177 )
{
struct V_163 * V_14 = F_22 ( V_175 , struct V_163 , V_175 ) ;
struct V_16 * V_178 = F_105 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_106 ( V_178 ) ;
int V_49 = - 1 ;
int V_179 = - 1 ;
T_1 V_39 = V_41 ;
bool V_180 = true ;
if ( V_166 == & V_181 . V_166 )
V_49 = V_164 ;
else if ( V_166 == & V_182 . V_166 )
V_49 = V_173 ;
if ( V_166 == & V_183 . V_166
|| V_166 == & V_184 . V_166
|| V_166 == & V_181 . V_166
|| V_166 == & V_185 . V_166 ) {
V_179 = 1 ;
}
if ( V_49 != - 1 ) {
int V_3 = F_17 ( V_2 , V_49 , & V_39 ) ;
if ( V_3 < 0 && V_179 == - 1 )
return 0 ;
}
if ( V_49 == V_164 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_157 && ! ( V_39 & V_54 ) ) )
V_180 = false ;
else
V_180 = V_179 <= V_2 -> V_186 ;
} else if ( V_49 == V_173 ) {
if ( ! V_39 )
V_180 = false ;
} else if ( V_179 <= V_2 -> V_186 && V_179 != - 1 ) {
V_180 = true ;
} else {
V_180 = false ;
}
return V_180 ? V_166 -> V_187 : 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_163 * V_188 ;
V_188 = F_108 ( & V_2 -> V_16 -> V_14 ,
L_35 , V_2 ,
V_189 ) ;
if ( F_109 ( V_188 ) ) {
F_53 ( L_36 ) ;
return F_110 ( V_188 ) ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_113 ;
if ( V_2 -> V_7 -> V_83 -> V_190 )
V_113 = ! V_2 -> V_7 -> V_191 ;
else
V_113 = F_20 ( V_2 ,
V_192 ) ;
if ( V_113 < 0 )
return V_113 ;
return V_113 ? V_193 : V_194 ;
}
static int F_112 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_195 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_196 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_113 ( struct V_197 * V_198 )
{
struct V_1 * V_2 = F_114 ( V_198 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_195 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_79 ;
}
static T_1 F_115 ( struct V_197 * V_198 )
{
struct V_1 * V_2 = F_114 ( V_198 ) ;
T_1 V_51 = 0 ;
if ( ( V_2 -> V_7 -> V_199 < V_198 -> V_200 . V_199 ) ||
V_198 -> V_200 . V_199 == V_198 -> V_200 . V_73 )
V_51 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_199 > V_198 -> V_200 . V_199 ) ||
V_198 -> V_200 . V_199 == 0 )
V_51 = 0x00008000 ;
V_2 -> V_7 -> V_199 = V_198 -> V_200 . V_199 ;
return V_51 ;
}
static int F_116 ( struct V_197 * V_198 )
{
struct V_1 * V_2 = F_114 ( V_198 ) ;
T_1 V_51 ;
int V_201 , V_3 = 0 ;
V_201 = F_111 ( V_2 ) ;
if ( V_201 != - V_42 && V_198 -> V_200 . V_201 != V_201 ) {
V_51 = ! ! ( V_198 -> V_200 . V_201 == V_193 ) ;
V_3 = F_18 ( V_192 ,
V_51 , NULL ) ;
if ( V_2 -> V_7 -> V_83 -> V_190 )
V_2 -> V_7 -> V_191 = V_198 -> V_200 . V_201 ;
if ( V_2 -> V_7 -> V_83 -> V_202 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_83 -> V_202 )
V_51 = F_115 ( V_198 ) ;
else
V_51 = V_198 -> V_200 . V_199 ;
V_3 = F_18 ( V_195 ,
V_51 , NULL ) ;
return V_3 ;
}
static int F_117 ( struct V_1 * V_2 , int V_203 )
{
struct V_197 * V_198 = V_2 -> V_197 ;
int V_204 = V_198 -> V_200 . V_199 ;
int V_205 = V_204 ;
if ( V_203 >= V_206 && V_203 <= V_207 )
V_205 = V_203 - V_206 + 1 ;
else if ( V_203 >= V_208 && V_203 <= V_209 )
V_205 = V_203 - V_208 ;
V_198 -> V_200 . V_199 = V_205 ;
F_118 ( V_198 ) ;
F_119 ( V_198 , V_210 ) ;
return V_204 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_197 * V_198 ;
struct V_211 V_200 ;
int V_212 ;
int V_201 ;
V_212 = F_112 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_201 = F_111 ( V_2 ) ;
if ( V_201 == - V_42 )
V_201 = V_193 ;
else if ( V_201 < 0 )
return V_201 ;
memset ( & V_200 , 0 , sizeof( struct V_211 ) ) ;
V_200 . type = V_213 ;
V_200 . V_73 = V_212 ;
V_198 = F_121 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_214 , & V_200 ) ;
if ( F_109 ( V_198 ) ) {
F_53 ( L_37 ) ;
return F_110 ( V_198 ) ;
}
V_2 -> V_197 = V_198 ;
if ( V_2 -> V_7 -> V_83 -> V_190 )
V_2 -> V_7 -> V_191 = V_201 ;
V_198 -> V_200 . V_199 = F_113 ( V_198 ) ;
V_198 -> V_200 . V_201 = V_201 ;
F_118 ( V_198 ) ;
V_2 -> V_7 -> V_199 = V_198 -> V_200 . V_199 ;
return 0 ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_123 ( V_2 -> V_197 ) ;
V_2 -> V_197 = NULL ;
}
static int F_124 ( int V_203 )
{
if ( ( V_203 >= 0x61 && V_203 <= 0x67 ) ||
( V_203 >= 0x8c && V_203 <= 0x93 ) ||
( V_203 >= 0xa0 && V_203 <= 0xa7 ) ||
( V_203 >= 0xd0 && V_203 <= 0xd5 ) )
return 1 ;
return 0 ;
}
static void F_125 ( T_1 V_39 , void * V_215 )
{
struct V_1 * V_2 = V_215 ;
struct V_27 V_216 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_203 ;
int V_217 ;
unsigned int V_218 = 1 ;
bool V_219 = 1 ;
V_32 = F_126 ( V_39 , & V_216 ) ;
if ( V_32 != V_110 ) {
F_53 ( L_38 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_216 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_203 = V_34 -> integer . V_39 ;
V_217 = V_203 ;
if ( V_2 -> V_7 -> V_220 ) {
V_2 -> V_7 -> V_220 ( V_2 -> V_7 , & V_203 , & V_218 ,
& V_219 ) ;
if ( V_203 == V_221 )
goto exit;
}
if ( V_203 >= V_206 && V_203 <= V_207 )
V_203 = V_222 ;
else if ( V_203 >= V_208 &&
V_203 <= V_209 )
V_203 = V_223 ;
if ( V_203 == V_223 || V_203 == V_222 ) {
if ( F_127 () == V_224 ) {
F_117 ( V_2 , V_217 ) ;
goto exit;
}
}
if ( F_124 ( V_203 ) &&
V_2 -> V_7 -> V_83 -> V_225 )
goto exit;
if ( ! F_128 ( V_2 -> V_4 , V_203 ,
V_218 , V_219 ) )
F_129 ( L_39 , V_203 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_130 ( const char * V_167 , unsigned long V_168 , int * V_226 )
{
if ( ! V_168 )
return 0 ;
if ( sscanf ( V_167 , L_40 , V_226 ) != 1 )
return - V_132 ;
return V_168 ;
}
static T_6 F_131 ( struct V_1 * V_2 , int V_227 ,
const char * V_167 , T_7 V_168 )
{
T_1 V_25 ;
int V_80 , V_3 , V_39 ;
V_39 = F_20 ( V_2 , V_227 ) ;
if ( V_39 == - V_42 )
return V_39 ;
V_80 = F_130 ( V_167 , V_168 , & V_39 ) ;
V_3 = F_18 ( V_227 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_80 ;
}
static T_6 F_132 ( struct V_1 * V_2 , int V_227 , char * V_167 )
{
int V_39 = F_20 ( V_2 , V_227 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_167 , L_32 , V_39 ) ;
}
static T_6 F_133 ( struct V_163 * V_14 , struct V_165 * V_166 ,
const char * V_167 , T_7 V_168 )
{
int V_39 , V_80 ;
if ( ! V_168 || sscanf ( V_167 , L_40 , & V_39 ) != 1 )
return - V_132 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_132 ;
V_80 = F_10 ( V_228 , V_39 , 0 , NULL ) ;
if ( V_80 < 0 )
return V_80 ;
return V_168 ;
}
static T_8 F_134 ( struct V_174 * V_175 ,
struct V_176 * V_166 , int V_177 )
{
struct V_163 * V_14 = F_22 ( V_175 , struct V_163 , V_175 ) ;
struct V_16 * V_178 = F_105 ( V_14 ) ;
struct V_1 * V_2 = F_106 ( V_178 ) ;
bool V_180 = true ;
int V_227 = - 1 ;
if ( V_166 == & V_229 . V_166 )
V_227 = V_230 ;
else if ( V_166 == & V_231 . V_166 )
V_227 = V_232 ;
else if ( V_166 == & V_233 . V_166 )
V_227 = V_234 ;
else if ( V_166 == & V_235 . V_166 )
V_227 = V_236 ;
if ( V_227 != - 1 )
V_180 = ! ( F_20 ( V_2 , V_227 ) < 0 ) ;
return V_180 ? V_166 -> V_187 : 0 ;
}
static void F_135 ( struct V_16 * V_163 )
{
F_136 ( & V_163 -> V_14 . V_175 , & V_237 ) ;
}
static int F_137 ( struct V_16 * V_163 )
{
return F_138 ( & V_163 -> V_14 . V_175 , & V_237 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
int V_80 ;
if ( ! F_10 ( V_238 , 0 , 0 , & V_80 ) )
F_129 ( L_41 , V_80 ) ;
if ( ! F_10 ( V_239 , 0 , 0x9 , & V_80 ) ) {
F_129 ( L_42 , V_80 >> 16 , V_80 & 0xFF ) ;
V_2 -> V_240 = V_80 ;
}
if ( ! F_10 ( V_241 , 0 , 0 , & V_80 ) ) {
F_129 ( L_43 , V_80 ) ;
V_2 -> V_157 = V_80 ;
}
if ( ! F_10 ( V_242 , 0 , 0 , NULL ) )
V_2 -> V_50 = V_242 ;
else
V_2 -> V_50 = V_243 ;
if ( V_2 -> V_7 -> V_83 -> V_84 >= 0 )
F_18 ( V_244 ,
V_2 -> V_7 -> V_83 -> V_84 , NULL ) ;
return F_137 ( V_2 -> V_16 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
F_135 ( V_2 -> V_16 ) ;
}
static int F_141 ( struct V_245 * V_246 , void * V_104 )
{
struct V_1 * V_2 = V_246 -> V_111 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_17 ( V_2 , V_2 -> V_247 . V_49 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_142 ( V_246 , L_44 , V_2 -> V_247 . V_49 , V_25 ) ;
return 0 ;
}
static int F_143 ( struct V_245 * V_246 , void * V_104 )
{
struct V_1 * V_2 = V_246 -> V_111 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_18 ( V_2 -> V_247 . V_49 , V_2 -> V_247 . V_51 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_142 ( V_246 , L_45 , V_2 -> V_247 . V_49 ,
V_2 -> V_247 . V_51 , V_25 ) ;
return 0 ;
}
static int F_144 ( struct V_245 * V_246 , void * V_104 )
{
struct V_1 * V_2 = V_246 -> V_111 ;
struct V_26 args = {
. V_23 = V_2 -> V_247 . V_49 ,
. V_24 = V_2 -> V_247 . V_51 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_247 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_142 ( V_246 , L_46 , V_2 -> V_247 . V_22 ,
V_2 -> V_247 . V_49 , V_2 -> V_247 . V_51 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_142 ( V_246 , L_47 , V_2 -> V_247 . V_22 ,
V_2 -> V_247 . V_49 , V_2 -> V_247 . V_51 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_145 ( struct V_248 * V_248 , struct V_249 * V_249 )
{
struct V_250 * V_108 = V_248 -> V_251 ;
return F_146 ( V_249 , V_108 -> V_252 , V_108 -> V_2 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
F_148 ( V_2 -> V_247 . V_253 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_254 * V_255 ;
int V_256 ;
V_2 -> V_247 . V_253 = F_150 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_247 . V_253 ) {
F_53 ( L_48 ) ;
goto V_257;
}
V_255 = F_151 ( L_49 , V_258 | V_259 ,
V_2 -> V_247 . V_253 , & V_2 -> V_247 . V_22 ) ;
if ( ! V_255 )
goto V_257;
V_255 = F_151 ( L_50 , V_258 | V_259 ,
V_2 -> V_247 . V_253 , & V_2 -> V_247 . V_49 ) ;
if ( ! V_255 )
goto V_257;
V_255 = F_151 ( L_51 , V_258 | V_259 ,
V_2 -> V_247 . V_253 , & V_2 -> V_247 . V_51 ) ;
if ( ! V_255 )
goto V_257;
for ( V_256 = 0 ; V_256 < F_152 ( V_260 ) ; V_256 ++ ) {
struct V_250 * V_108 = & V_260 [ V_256 ] ;
V_108 -> V_2 = V_2 ;
V_255 = F_153 ( V_108 -> V_6 , V_261 | V_258 ,
V_2 -> V_247 . V_253 , V_108 ,
& V_262 ) ;
if ( ! V_255 ) {
F_53 ( L_52 , V_108 -> V_6 ) ;
goto V_257;
}
}
return 0 ;
V_257:
F_147 ( V_2 ) ;
return - V_5 ;
}
static int F_154 ( struct V_1 * V_2 )
{
int V_32 ;
V_2 -> V_160 = - 1 ;
V_2 -> V_186 = - 1 ;
V_2 -> V_162 = false ;
V_32 = F_89 ( V_2 , & V_2 -> V_186 ) ;
if ( V_32 ) {
V_2 -> V_186 = 0 ;
F_51 ( L_53 , V_32 ) ;
return - V_48 ;
}
F_129 ( L_54 , V_2 -> V_186 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_178 )
{
struct V_263 * V_264 = F_156 ( V_178 -> V_14 . V_7 ) ;
struct V_265 * V_266 = F_157 ( V_264 ) ;
struct V_1 * V_2 ;
const char * V_267 ;
T_2 V_32 ;
int V_3 ;
T_1 V_74 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_266 ;
V_2 -> V_16 = V_178 ;
V_266 -> V_16 = V_178 ;
F_158 ( V_2 -> V_16 , V_2 ) ;
if ( V_266 -> V_268 )
V_266 -> V_268 ( V_2 -> V_7 ) ;
V_3 = F_139 ( V_2 ) ;
if ( V_3 )
goto V_269;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_270;
V_3 = F_154 ( V_2 ) ;
F_90 ( V_2 ) ;
V_3 = F_107 ( V_2 ) ;
if ( V_3 )
goto V_271;
V_3 = F_40 ( V_2 ) ;
if ( V_3 )
goto V_272;
V_3 = F_85 ( V_2 ) ;
if ( V_3 )
goto V_273;
V_267 = F_159 ( V_274 ) ;
if ( V_267 && ! strcmp ( V_267 , L_55 ) )
F_160 ( V_224 ) ;
if ( V_2 -> V_7 -> V_83 -> V_275 )
F_160 ( V_224 ) ;
if ( F_127 () == V_224 ) {
V_3 = F_120 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_276;
}
V_32 = F_161 ( V_2 -> V_7 -> V_277 ,
F_125 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_53 ( L_56 , V_32 ) ;
V_3 = - V_42 ;
goto V_278;
}
V_3 = F_149 ( V_2 ) ;
if ( V_3 )
goto V_279;
F_17 ( V_2 , V_88 , & V_74 ) ;
if ( V_74 & ( V_54 | V_280 ) )
V_2 -> V_7 -> V_125 = 1 ;
return 0 ;
V_279:
F_162 ( V_2 -> V_7 -> V_277 ) ;
V_278:
F_122 ( V_2 ) ;
V_276:
F_82 ( V_2 ) ;
V_273:
F_36 ( V_2 ) ;
V_272:
V_271:
F_8 ( V_2 ) ;
V_270:
F_140 ( V_2 ) ;
V_269:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_163 ( struct V_16 * V_163 )
{
struct V_1 * V_2 ;
V_2 = F_106 ( V_163 ) ;
F_162 ( V_2 -> V_7 -> V_277 ) ;
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
static int F_164 ( struct V_163 * V_163 )
{
struct V_1 * V_2 = F_92 ( V_163 ) ;
if ( V_2 -> V_97 . V_98 ) {
bool V_97 ;
V_97 = F_20 ( V_2 , V_88 ) ;
F_18 ( V_88 , V_97 , NULL ) ;
}
return 0 ;
}
static int F_165 ( struct V_163 * V_163 )
{
struct V_1 * V_2 = F_92 ( V_163 ) ;
int V_281 ;
if ( V_2 -> V_97 . V_98 )
F_45 ( V_2 ) ;
if ( V_2 -> V_133 . V_98 ) {
V_281 = ! F_20 ( V_2 ,
V_140 ) ;
F_49 ( V_2 -> V_133 . V_98 , V_281 ) ;
}
if ( V_2 -> V_134 . V_98 ) {
V_281 = ! F_20 ( V_2 , V_142 ) ;
F_49 ( V_2 -> V_134 . V_98 , V_281 ) ;
}
if ( V_2 -> V_135 . V_98 ) {
V_281 = ! F_20 ( V_2 , V_144 ) ;
F_49 ( V_2 -> V_135 . V_98 , V_281 ) ;
}
if ( V_2 -> V_136 . V_98 ) {
V_281 = ! F_20 ( V_2 , V_146 ) ;
F_49 ( V_2 -> V_136 . V_98 , V_281 ) ;
}
if ( V_2 -> V_137 . V_98 ) {
V_281 = ! F_20 ( V_2 , V_148 ) ;
F_49 ( V_2 -> V_137 . V_98 , V_281 ) ;
}
return 0 ;
}
static int F_166 ( struct V_16 * V_178 )
{
struct V_263 * V_264 = F_156 ( V_178 -> V_14 . V_7 ) ;
struct V_265 * V_266 = F_157 ( V_264 ) ;
int V_113 ;
if ( ! F_167 ( V_36 ) ) {
F_51 ( L_57 ) ;
return - V_42 ;
}
if ( V_266 -> V_277 && ! F_167 ( V_266 -> V_277 ) ) {
F_51 ( L_58 ) ;
return - V_42 ;
}
if ( V_266 -> V_282 ) {
V_113 = V_266 -> V_282 ( V_178 ) ;
if ( V_113 )
return V_113 ;
}
return F_155 ( V_178 ) ;
}
int T_9 F_168 ( struct V_265 * V_7 )
{
struct V_263 * V_263 ;
struct V_16 * V_16 ;
if ( V_283 )
return - V_149 ;
V_263 = & V_7 -> V_263 ;
V_263 -> remove = F_163 ;
V_263 -> V_7 . V_284 = V_7 -> V_284 ;
V_263 -> V_7 . V_6 = V_7 -> V_6 ;
V_263 -> V_7 . V_285 = & V_286 ;
V_16 = F_169 ( V_263 ,
F_166 ,
NULL , 0 , NULL , 0 ) ;
if ( F_109 ( V_16 ) )
return F_110 ( V_16 ) ;
V_283 = true ;
return 0 ;
}
void F_170 ( struct V_265 * V_7 )
{
F_171 ( V_7 -> V_16 ) ;
F_172 ( & V_7 -> V_263 ) ;
V_283 = false ;
}
static int T_10 F_173 ( void )
{
if ( ! F_167 ( V_36 ) ) {
F_129 ( L_59 ) ;
return - V_42 ;
}
F_129 ( L_60 ) ;
return 0 ;
}
static void T_11 F_174 ( void )
{
F_129 ( L_61 ) ;
}
