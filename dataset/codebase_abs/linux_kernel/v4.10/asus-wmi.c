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
static void F_87 ( struct V_1 * V_2 )
{
struct V_90 * V_151 ;
T_1 V_152 ;
T_1 V_153 = V_2 -> V_7 -> V_84 -> V_154 ;
V_151 = F_88 ( V_155 ,
V_156 ,
NULL ) ;
if ( ! V_151 )
return;
F_89 ( V_151 , V_157 ,
& V_152 ) ;
F_90 ( V_151 , V_157 ,
F_91 ( V_153 ) ) ;
F_92 ( L_30 ,
V_152 , V_153 ) ;
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
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
int V_32 ;
if ( V_158 != 1 )
return - V_133 ;
V_32 = F_14 ( V_28 ) ;
if ( V_32 || args . V_161 . V_3 )
return - V_48 ;
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
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
int V_32 ;
if ( V_158 != 1 && V_158 != 0 )
return - V_133 ;
V_32 = F_14 ( V_28 ) ;
if ( V_32 || args . V_161 . V_3 )
return - V_48 ;
if ( V_159 && V_158 == 1 )
V_2 -> V_168 = * V_159 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , int * V_169 )
{
int V_32 ;
int V_159 = 0 ;
* V_169 = 0 ;
V_32 = F_93 ( V_2 , 1 , & V_159 ) ;
if ( ! V_32 )
* V_169 = 1 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_94 ( V_2 , 0 , NULL ) ;
if ( V_32 )
return - V_48 ;
V_2 -> V_170 = false ;
return 0 ;
}
static int F_97 ( struct V_171 * V_14 , int V_158 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_39 ;
int V_114 ;
if ( V_2 -> V_170 )
return - V_48 ;
V_114 = F_93 ( V_2 , V_158 + 1 , & V_39 ) ;
if ( V_114 ) {
F_51 ( L_31 , V_114 ) ;
return - V_48 ;
}
return V_39 ;
}
static void F_99 ( struct V_1 * V_2 , int V_158 , int * V_39 )
{
int V_3 ;
if ( V_2 -> V_168 >= 0 ) {
* V_39 = V_2 -> V_168 ;
return;
}
V_3 = F_17 ( V_2 , V_172 , V_39 ) ;
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
F_53 ( L_32 , * V_39 ) ;
* V_39 = - 1 ;
}
}
static T_6 F_100 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_39 ;
F_99 ( V_2 , 0 , & V_39 ) ;
return sprintf ( V_175 , L_33 , V_39 ) ;
}
static T_6 F_101 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 ) {
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_39 ;
int V_177 ;
int V_114 ;
V_114 = F_102 ( V_175 , 10 , & V_39 ) ;
if ( V_114 )
return V_114 ;
V_39 = F_103 ( V_39 , 0 , 255 ) ;
V_177 = F_94 ( V_2 , 1 , & V_39 ) ;
if ( V_177 )
F_51 ( L_34 , V_177 ) ;
else
V_2 -> V_170 = true ;
return V_176 ;
}
static T_6 F_104 ( struct V_171 * V_14 ,
struct V_173 * V_174 ,
char * V_175 )
{
int V_39 = F_97 ( V_14 , 0 ) ;
return sprintf ( V_175 , L_33 , V_39 < 0 ? - 1 : V_39 * 100 ) ;
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
int V_32 = 0 ;
int V_177 ;
int V_114 ;
V_114 = F_102 ( V_175 , 10 , & V_177 ) ;
if ( V_114 )
return V_114 ;
if ( V_177 == V_178 )
V_2 -> V_170 = true ;
else
V_32 = F_96 ( V_2 ) ;
if ( V_32 )
return V_32 ;
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
T_1 V_39 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_181 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_109 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_175 , L_33 , V_39 ) ;
}
static T_8 F_110 ( struct V_182 * V_183 ,
struct V_184 * V_174 , int V_185 )
{
struct V_171 * V_14 = F_22 ( V_183 , struct V_171 , V_183 ) ;
struct V_16 * V_186 = F_111 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_112 ( V_186 ) ;
int V_49 = - 1 ;
int V_187 = - 1 ;
T_1 V_39 = V_41 ;
bool V_188 = true ;
if ( V_174 == & V_189 . V_174 )
V_49 = V_172 ;
else if ( V_174 == & V_190 . V_174 )
V_49 = V_181 ;
if ( V_174 == & V_191 . V_174
|| V_174 == & V_192 . V_174
|| V_174 == & V_189 . V_174
|| V_174 == & V_193 . V_174 ) {
V_187 = 1 ;
}
if ( V_49 != - 1 ) {
int V_3 = F_17 ( V_2 , V_49 , & V_39 ) ;
if ( V_3 < 0 && V_187 == - 1 )
return 0 ;
}
if ( V_49 == V_172 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_165 && ! ( V_39 & V_54 ) ) )
V_188 = false ;
else
V_188 = V_187 <= V_2 -> V_194 ;
} else if ( V_49 == V_181 ) {
if ( ! V_39 )
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
F_53 ( L_37 ) ;
return F_116 ( V_196 ) ;
}
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_114 ;
if ( V_2 -> V_7 -> V_84 -> V_198 )
V_114 = ! V_2 -> V_7 -> V_199 ;
else
V_114 = F_20 ( V_2 ,
V_200 ) ;
if ( V_114 < 0 )
return V_114 ;
return V_114 ? V_201 : V_202 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_203 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_204 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_119 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_120 ( V_206 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_17 ( V_2 , V_203 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_79 ;
}
static T_1 F_121 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_120 ( V_206 ) ;
T_1 V_51 = 0 ;
if ( ( V_2 -> V_7 -> V_207 < V_206 -> V_208 . V_207 ) ||
V_206 -> V_208 . V_207 == V_206 -> V_208 . V_73 )
V_51 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_207 > V_206 -> V_208 . V_207 ) ||
V_206 -> V_208 . V_207 == 0 )
V_51 = 0x00008000 ;
V_2 -> V_7 -> V_207 = V_206 -> V_208 . V_207 ;
return V_51 ;
}
static int F_122 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_120 ( V_206 ) ;
T_1 V_51 ;
int V_209 , V_3 = 0 ;
V_209 = F_117 ( V_2 ) ;
if ( V_209 != - V_42 && V_206 -> V_208 . V_209 != V_209 ) {
V_51 = ! ! ( V_206 -> V_208 . V_209 == V_201 ) ;
V_3 = F_18 ( V_200 ,
V_51 , NULL ) ;
if ( V_2 -> V_7 -> V_84 -> V_198 )
V_2 -> V_7 -> V_199 = V_206 -> V_208 . V_209 ;
if ( V_2 -> V_7 -> V_84 -> V_210 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_84 -> V_210 )
V_51 = F_121 ( V_206 ) ;
else
V_51 = V_206 -> V_208 . V_207 ;
V_3 = F_18 ( V_203 ,
V_51 , NULL ) ;
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
if ( V_209 == - V_42 )
V_209 = V_201 ;
else if ( V_209 < 0 )
return V_209 ;
memset ( & V_208 , 0 , sizeof( struct V_219 ) ) ;
V_208 . type = V_221 ;
V_208 . V_73 = V_220 ;
V_206 = F_127 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_222 , & V_208 ) ;
if ( F_115 ( V_206 ) ) {
F_53 ( L_38 ) ;
return F_116 ( V_206 ) ;
}
V_2 -> V_205 = V_206 ;
if ( V_2 -> V_7 -> V_84 -> V_198 )
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
static void F_131 ( T_1 V_39 , void * V_223 )
{
struct V_1 * V_2 = V_223 ;
struct V_27 V_224 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_211 ;
int V_225 ;
unsigned int V_226 = 1 ;
bool V_227 = 1 ;
V_32 = F_132 ( V_39 , & V_224 ) ;
if ( V_32 != V_111 ) {
F_53 ( L_39 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_224 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_211 = V_34 -> integer . V_39 ;
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
V_2 -> V_7 -> V_84 -> V_233 )
goto exit;
if ( ! F_134 ( V_2 -> V_4 , V_211 ,
V_226 , V_227 ) )
F_92 ( L_40 , V_211 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_135 ( const char * V_175 , unsigned long V_176 , int * V_234 )
{
if ( ! V_176 )
return 0 ;
if ( sscanf ( V_175 , L_41 , V_234 ) != 1 )
return - V_133 ;
return V_176 ;
}
static T_6 F_136 ( struct V_1 * V_2 , int V_235 ,
const char * V_175 , T_7 V_176 )
{
T_1 V_25 ;
int V_80 , V_3 , V_39 ;
V_39 = F_20 ( V_2 , V_235 ) ;
if ( V_39 < 0 )
return V_39 ;
V_80 = F_135 ( V_175 , V_176 , & V_39 ) ;
V_3 = F_18 ( V_235 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_80 ;
}
static T_6 F_137 ( struct V_1 * V_2 , int V_235 , char * V_175 )
{
int V_39 = F_20 ( V_2 , V_235 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_175 , L_33 , V_39 ) ;
}
static T_6 F_138 ( struct V_171 * V_14 , struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
int V_39 , V_80 ;
if ( ! V_176 || sscanf ( V_175 , L_41 , & V_39 ) != 1 )
return - V_133 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_133 ;
V_80 = F_10 ( V_236 , V_39 , 0 , NULL ) ;
if ( V_80 < 0 )
return V_80 ;
return V_176 ;
}
static T_8 F_139 ( struct V_182 * V_183 ,
struct V_184 * V_174 , int V_185 )
{
struct V_171 * V_14 = F_22 ( V_183 , struct V_171 , V_183 ) ;
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
V_235 = V_246 ;
if ( V_235 != - 1 )
V_188 = ! ( F_20 ( V_2 , V_235 ) < 0 ) ;
return V_188 ? V_174 -> V_195 : 0 ;
}
static void F_140 ( struct V_16 * V_171 )
{
F_141 ( & V_171 -> V_14 . V_183 , & V_247 ) ;
}
static int F_142 ( struct V_16 * V_171 )
{
return F_143 ( & V_171 -> V_14 . V_183 , & V_247 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_80 ;
if ( ! F_10 ( V_248 , 0 , 0 , & V_80 ) )
F_92 ( L_42 , V_80 ) ;
if ( ! F_10 ( V_249 , 0 , 0x9 , & V_80 ) ) {
F_92 ( L_43 , V_80 >> 16 , V_80 & 0xFF ) ;
V_2 -> V_250 = V_80 ;
}
if ( ! F_10 ( V_251 , 0 , 0 , & V_80 ) ) {
F_92 ( L_44 , V_80 ) ;
V_2 -> V_165 = V_80 ;
}
if ( ! F_10 ( V_252 , 0 , 0 , NULL ) )
V_2 -> V_50 = V_252 ;
else
V_2 -> V_50 = V_253 ;
if ( V_2 -> V_7 -> V_84 -> V_85 >= 0 )
F_18 ( V_254 ,
V_2 -> V_7 -> V_84 -> V_85 , NULL ) ;
return F_142 ( V_2 -> V_16 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_140 ( V_2 -> V_16 ) ;
}
static int F_146 ( struct V_255 * V_256 , void * V_105 )
{
struct V_1 * V_2 = V_256 -> V_112 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_17 ( V_2 , V_2 -> V_257 . V_49 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_147 ( V_256 , L_45 , V_2 -> V_257 . V_49 , V_25 ) ;
return 0 ;
}
static int F_148 ( struct V_255 * V_256 , void * V_105 )
{
struct V_1 * V_2 = V_256 -> V_112 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_18 ( V_2 -> V_257 . V_49 , V_2 -> V_257 . V_51 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_147 ( V_256 , L_46 , V_2 -> V_257 . V_49 ,
V_2 -> V_257 . V_51 , V_25 ) ;
return 0 ;
}
static int F_149 ( struct V_255 * V_256 , void * V_105 )
{
struct V_1 * V_2 = V_256 -> V_112 ;
struct V_26 args = {
. V_23 = V_2 -> V_257 . V_49 ,
. V_24 = V_2 -> V_257 . V_51 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_257 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_147 ( V_256 , L_47 , V_2 -> V_257 . V_22 ,
V_2 -> V_257 . V_49 , V_2 -> V_257 . V_51 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_147 ( V_256 , L_48 , V_2 -> V_257 . V_22 ,
V_2 -> V_257 . V_49 , V_2 -> V_257 . V_51 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_150 ( struct V_258 * V_258 , struct V_259 * V_259 )
{
struct V_260 * V_109 = V_258 -> V_261 ;
return F_151 ( V_259 , V_109 -> V_262 , V_109 -> V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_153 ( V_2 -> V_257 . V_263 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_264 * V_265 ;
int V_266 ;
V_2 -> V_257 . V_263 = F_155 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_257 . V_263 ) {
F_53 ( L_49 ) ;
goto V_267;
}
V_265 = F_156 ( L_50 , V_268 | V_269 ,
V_2 -> V_257 . V_263 , & V_2 -> V_257 . V_22 ) ;
if ( ! V_265 )
goto V_267;
V_265 = F_156 ( L_51 , V_268 | V_269 ,
V_2 -> V_257 . V_263 , & V_2 -> V_257 . V_49 ) ;
if ( ! V_265 )
goto V_267;
V_265 = F_156 ( L_52 , V_268 | V_269 ,
V_2 -> V_257 . V_263 , & V_2 -> V_257 . V_51 ) ;
if ( ! V_265 )
goto V_267;
for ( V_266 = 0 ; V_266 < F_157 ( V_270 ) ; V_266 ++ ) {
struct V_260 * V_109 = & V_270 [ V_266 ] ;
V_109 -> V_2 = V_2 ;
V_265 = F_158 ( V_109 -> V_6 , V_271 | V_268 ,
V_2 -> V_257 . V_263 , V_109 ,
& V_272 ) ;
if ( ! V_265 ) {
F_53 ( L_53 , V_109 -> V_6 ) ;
goto V_267;
}
}
return 0 ;
V_267:
F_152 ( V_2 ) ;
return - V_5 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_32 ;
V_2 -> V_168 = - 1 ;
V_2 -> V_194 = - 1 ;
V_2 -> V_170 = false ;
V_32 = F_95 ( V_2 , & V_2 -> V_194 ) ;
if ( V_32 ) {
V_2 -> V_194 = 0 ;
F_51 ( L_54 , V_32 ) ;
return - V_48 ;
}
F_92 ( L_55 , V_2 -> V_194 ) ;
return 0 ;
}
static int F_160 ( struct V_16 * V_186 )
{
struct V_273 * V_274 = F_161 ( V_186 -> V_14 . V_7 ) ;
struct V_275 * V_276 = F_162 ( V_274 ) ;
struct V_1 * V_2 ;
const char * V_277 ;
T_2 V_32 ;
int V_3 ;
T_1 V_74 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_276 ;
V_2 -> V_16 = V_186 ;
V_276 -> V_16 = V_186 ;
F_163 ( V_2 -> V_16 , V_2 ) ;
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
V_3 = F_40 ( V_2 ) ;
if ( V_3 )
goto V_282;
if ( ! V_2 -> V_7 -> V_84 -> V_283 ) {
V_3 = F_85 ( V_2 ) ;
if ( V_3 )
goto V_284;
}
V_277 = F_164 ( V_285 ) ;
if ( V_277 && ! strcmp ( V_277 , L_56 ) )
F_165 ( V_232 ) ;
if ( V_2 -> V_7 -> V_84 -> V_286 )
F_165 ( V_232 ) ;
if ( V_2 -> V_7 -> V_84 -> V_287 )
F_165 ( V_288 ) ;
if ( V_2 -> V_7 -> V_84 -> V_154 )
F_87 ( V_2 ) ;
if ( F_133 () == V_232 ) {
V_3 = F_126 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_289;
}
V_32 = F_166 ( V_2 -> V_7 -> V_290 ,
F_131 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_53 ( L_57 , V_32 ) ;
V_3 = - V_42 ;
goto V_291;
}
V_3 = F_154 ( V_2 ) ;
if ( V_3 )
goto V_292;
F_17 ( V_2 , V_89 , & V_74 ) ;
if ( V_74 & ( V_54 | V_293 ) )
V_2 -> V_7 -> V_126 = 1 ;
return 0 ;
V_292:
F_167 ( V_2 -> V_7 -> V_290 ) ;
V_291:
F_128 ( V_2 ) ;
V_289:
F_82 ( V_2 ) ;
V_284:
F_36 ( V_2 ) ;
V_282:
V_281:
F_8 ( V_2 ) ;
V_280:
F_145 ( V_2 ) ;
V_279:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_168 ( struct V_16 * V_171 )
{
struct V_1 * V_2 ;
V_2 = F_112 ( V_171 ) ;
F_167 ( V_2 -> V_7 -> V_290 ) ;
F_128 ( V_2 ) ;
F_8 ( V_2 ) ;
F_36 ( V_2 ) ;
F_82 ( V_2 ) ;
F_152 ( V_2 ) ;
F_145 ( V_2 ) ;
F_96 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_169 ( struct V_171 * V_171 )
{
struct V_1 * V_2 = F_98 ( V_171 ) ;
if ( V_2 -> V_98 . V_99 ) {
bool V_98 ;
V_98 = F_20 ( V_2 , V_89 ) ;
F_18 ( V_89 , V_98 , NULL ) ;
}
return 0 ;
}
static int F_170 ( struct V_171 * V_171 )
{
struct V_1 * V_2 = F_98 ( V_171 ) ;
if ( ! F_37 ( V_2 -> V_72 . V_14 ) )
F_24 ( V_2 -> V_66 , & V_2 -> V_67 ) ;
return 0 ;
}
static int F_171 ( struct V_171 * V_171 )
{
struct V_1 * V_2 = F_98 ( V_171 ) ;
int V_294 ;
if ( V_2 -> V_98 . V_99 )
F_45 ( V_2 ) ;
if ( V_2 -> V_134 . V_99 ) {
V_294 = ! F_20 ( V_2 ,
V_141 ) ;
F_49 ( V_2 -> V_134 . V_99 , V_294 ) ;
}
if ( V_2 -> V_135 . V_99 ) {
V_294 = ! F_20 ( V_2 , V_143 ) ;
F_49 ( V_2 -> V_135 . V_99 , V_294 ) ;
}
if ( V_2 -> V_136 . V_99 ) {
V_294 = ! F_20 ( V_2 , V_145 ) ;
F_49 ( V_2 -> V_136 . V_99 , V_294 ) ;
}
if ( V_2 -> V_137 . V_99 ) {
V_294 = ! F_20 ( V_2 , V_147 ) ;
F_49 ( V_2 -> V_137 . V_99 , V_294 ) ;
}
if ( V_2 -> V_138 . V_99 ) {
V_294 = ! F_20 ( V_2 , V_149 ) ;
F_49 ( V_2 -> V_138 . V_99 , V_294 ) ;
}
if ( ! F_37 ( V_2 -> V_72 . V_14 ) )
F_24 ( V_2 -> V_66 , & V_2 -> V_67 ) ;
return 0 ;
}
static int F_172 ( struct V_16 * V_186 )
{
struct V_273 * V_274 = F_161 ( V_186 -> V_14 . V_7 ) ;
struct V_275 * V_276 = F_162 ( V_274 ) ;
int V_114 ;
if ( ! F_173 ( V_36 ) ) {
F_51 ( L_58 ) ;
return - V_42 ;
}
if ( V_276 -> V_290 && ! F_173 ( V_276 -> V_290 ) ) {
F_51 ( L_59 ) ;
return - V_42 ;
}
if ( V_276 -> V_295 ) {
V_114 = V_276 -> V_295 ( V_186 ) ;
if ( V_114 )
return V_114 ;
}
return F_160 ( V_186 ) ;
}
int T_9 F_174 ( struct V_275 * V_7 )
{
struct V_273 * V_273 ;
struct V_16 * V_16 ;
if ( V_296 )
return - V_150 ;
V_273 = & V_7 -> V_273 ;
V_273 -> remove = F_168 ;
V_273 -> V_7 . V_297 = V_7 -> V_297 ;
V_273 -> V_7 . V_6 = V_7 -> V_6 ;
V_273 -> V_7 . V_298 = & V_299 ;
V_16 = F_175 ( V_273 ,
F_172 ,
NULL , 0 , NULL , 0 ) ;
if ( F_115 ( V_16 ) )
return F_116 ( V_16 ) ;
V_296 = true ;
return 0 ;
}
void F_176 ( struct V_275 * V_7 )
{
F_177 ( V_7 -> V_16 ) ;
F_178 ( & V_7 -> V_273 ) ;
V_296 = false ;
}
static int T_10 F_179 ( void )
{
if ( ! F_173 ( V_36 ) ) {
F_92 ( L_60 ) ;
return - V_42 ;
}
F_92 ( L_61 ) ;
return 0 ;
}
static void T_11 F_180 ( void )
{
F_92 ( L_62 ) ;
}
