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
T_1 V_35 ;
V_32 = F_11 ( V_36 , 1 , V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
goto exit;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
V_35 = ( T_1 ) V_34 -> integer . V_39 ;
else
V_35 = 0 ;
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
static int F_14 ( struct V_1 * V_2 , T_1 V_43 , T_1 * V_25 )
{
return F_10 ( V_2 -> V_44 , V_43 , 0 , V_25 ) ;
}
static int F_15 ( T_1 V_43 , T_1 V_45 ,
T_1 * V_25 )
{
return F_10 ( V_46 , V_43 ,
V_45 , V_25 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_43 , T_1 V_47 )
{
T_1 V_25 = 0 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_43 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! ( V_25 & V_48 ) )
return - V_42 ;
if ( V_47 == V_49 ) {
if ( V_25 & V_50 )
return - V_42 ;
}
return V_25 & V_47 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_43 )
{
return F_16 ( V_2 , V_43 ,
V_49 ) ;
}
static void F_18 ( struct V_51 * V_52 )
{
int V_45 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_52 , struct V_1 , V_53 ) ;
V_45 = V_2 -> V_54 ;
F_15 ( V_55 , V_45 , NULL ) ;
}
static void F_20 ( struct V_56 * V_57 ,
enum V_58 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_57 , struct V_1 , V_59 ) ;
V_2 -> V_54 = ! ! V_39 ;
F_21 ( V_2 -> V_60 , & V_2 -> V_53 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_55 ) ;
}
static enum V_58 F_23 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_57 , struct V_1 , V_59 ) ;
return F_22 ( V_2 ) ;
}
static void F_24 ( struct V_51 * V_52 )
{
int V_45 = 0 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_52 , struct V_1 , V_61 ) ;
if ( V_2 -> V_62 > 0 )
V_45 = 0x80 | ( V_2 -> V_62 & 0x7F ) ;
F_15 ( V_63 , V_45 , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 , int * V_64 , int * V_65 )
{
int V_25 ;
V_25 = F_16 ( V_2 , V_63 ,
0xFFFF ) ;
if ( V_25 == 0x8000 )
V_25 = 0 ;
if ( V_25 >= 0 ) {
if ( V_64 )
* V_64 = V_25 & 0x7F ;
if ( V_65 )
* V_65 = ( V_25 >> 8 ) & 0x7F ;
V_25 = 0 ;
}
return V_25 ;
}
static void F_26 ( struct V_56 * V_57 ,
enum V_58 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_57 , struct V_1 , V_66 ) ;
if ( V_39 > V_2 -> V_66 . V_67 )
V_39 = V_2 -> V_66 . V_67 ;
else if ( V_39 < 0 )
V_39 = 0 ;
V_2 -> V_62 = V_39 ;
F_21 ( V_2 -> V_60 , & V_2 -> V_61 ) ;
}
static enum V_58 F_27 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
int V_25 , V_39 ;
V_2 = F_19 ( V_57 , struct V_1 , V_66 ) ;
V_25 = F_25 ( V_2 , & V_39 , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
return V_39 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( ! F_29 ( V_2 -> V_66 . V_14 ) )
F_30 ( & V_2 -> V_66 ) ;
if ( ! F_29 ( V_2 -> V_59 . V_14 ) )
F_30 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_60 )
F_31 ( V_2 -> V_60 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_68 = 0 ;
V_2 -> V_60 = F_33 ( L_1 ) ;
if ( ! V_2 -> V_60 )
return - V_5 ;
if ( F_22 ( V_2 ) >= 0 ) {
F_34 ( & V_2 -> V_53 , F_18 ) ;
V_2 -> V_59 . V_6 = L_2 ;
V_2 -> V_59 . V_69 = F_20 ;
V_2 -> V_59 . V_70 = F_23 ;
V_2 -> V_59 . V_67 = 1 ;
V_68 = F_35 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_59 ) ;
if ( V_68 )
goto error;
}
if ( F_25 ( V_2 , NULL , NULL ) >= 0 ) {
F_34 ( & V_2 -> V_61 , F_24 ) ;
V_2 -> V_66 . V_6 = L_3 ;
V_2 -> V_66 . V_69 = F_26 ;
V_2 -> V_66 . V_70 = F_27 ;
V_2 -> V_66 . V_67 = 3 ;
V_68 = F_35 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_66 ) ;
}
error:
if ( V_68 )
F_28 ( V_2 ) ;
return V_68 ;
}
static bool F_36 ( struct V_1 * V_2 )
{
int V_71 = F_17 ( V_2 , V_72 ) ;
if ( V_71 < 0 )
return false ;
return ! V_71 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_73 * V_14 ;
struct V_74 * V_75 ;
bool V_76 ;
bool V_77 ;
T_1 V_78 ;
F_38 ( & V_2 -> V_79 ) ;
V_76 = F_36 ( V_2 ) ;
F_39 ( & V_2 -> V_79 ) ;
F_38 ( & V_2 -> V_80 ) ;
if ( V_2 -> V_81 . V_82 )
F_40 ( V_2 -> V_81 . V_82 , V_76 ) ;
if ( V_2 -> V_83 ) {
V_75 = F_41 ( 0 , 1 ) ;
if ( ! V_75 ) {
F_42 ( L_4 ) ;
goto V_84;
}
if ( F_43 ( V_75 , 0 , V_85 , & V_78 ) ) {
F_44 ( L_5 ) ;
goto V_84;
}
V_77 = ( V_78 == 0xffffffff ) ;
if ( V_76 != V_77 ) {
F_42 ( L_6
L_7 ,
V_76 ? L_8 : L_9 ,
V_77 ? L_10 : L_11 ) ;
F_42 ( L_12
L_13 ) ;
goto V_84;
}
if ( ! V_76 ) {
V_14 = F_45 ( V_75 , 0 ) ;
if ( V_14 ) {
F_46 ( V_14 ) ;
goto V_84;
}
V_14 = F_47 ( V_75 , 0 ) ;
if ( V_14 ) {
F_48 ( V_75 ) ;
if ( F_49 ( V_14 ) )
F_44 ( L_14 ) ;
}
} else {
V_14 = F_45 ( V_75 , 0 ) ;
if ( V_14 ) {
F_50 ( V_14 ) ;
F_46 ( V_14 ) ;
}
}
}
V_84:
F_39 ( & V_2 -> V_80 ) ;
}
static void F_51 ( T_3 V_86 , T_1 V_87 , void * V_88 )
{
struct V_1 * V_2 = V_88 ;
if ( V_87 != V_89 )
return;
F_21 ( V_2 -> V_90 , & V_2 -> V_91 ) ;
}
static int F_52 ( struct V_1 * V_2 , char * V_92 )
{
T_2 V_32 ;
T_3 V_86 ;
V_32 = F_53 ( NULL , V_92 , & V_86 ) ;
if ( F_54 ( V_32 ) ) {
V_32 = F_55 ( V_86 ,
V_93 ,
F_51 , V_2 ) ;
if ( F_12 ( V_32 ) )
F_42 ( L_15 , V_92 ) ;
} else
return - V_42 ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , char * V_92 )
{
T_2 V_32 = V_94 ;
T_3 V_86 ;
V_32 = F_53 ( NULL , V_92 , & V_86 ) ;
if ( F_54 ( V_32 ) ) {
V_32 = F_57 ( V_86 ,
V_93 ,
F_51 ) ;
if ( F_12 ( V_32 ) )
F_44 ( L_16 ,
V_92 ) ;
}
}
static int F_58 ( struct V_83 * V_83 ,
T_4 * V_39 )
{
struct V_1 * V_2 = V_83 -> V_95 ;
int V_71 = F_17 ( V_2 , V_72 ) ;
if ( V_71 < 0 )
return V_71 ;
* V_39 = ! ! V_71 ;
return 0 ;
}
static void F_59 ( struct V_83 * V_83 )
{
F_13 ( V_83 -> V_96 ) ;
F_13 ( V_83 ) ;
}
static void F_60 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_52 , struct V_1 , V_91 ) ;
F_37 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_97 = - V_5 ;
struct V_74 * V_75 = F_41 ( 0 , 1 ) ;
if ( ! V_75 ) {
F_44 ( L_17 ) ;
return - V_42 ;
}
V_2 -> V_90 =
F_33 ( L_18 ) ;
if ( ! V_2 -> V_90 )
goto V_98;
F_34 ( & V_2 -> V_91 , F_60 ) ;
V_2 -> V_83 = F_62 ( sizeof( struct V_83 ) , V_99 ) ;
if ( ! V_2 -> V_83 )
goto V_100;
V_2 -> V_83 -> V_96 = F_62 ( sizeof( struct V_101 ) ,
V_99 ) ;
if ( ! V_2 -> V_83 -> V_96 )
goto V_102;
V_2 -> V_83 -> V_95 = V_2 ;
V_2 -> V_83 -> V_103 = & F_59 ;
V_2 -> V_83 -> V_104 = & V_105 ;
F_58 ( V_2 -> V_83 ,
& V_2 -> V_83 -> V_96 -> V_106 ) ;
V_97 = F_63 ( V_2 -> V_83 , V_75 , 0 , L_19 ) ;
if ( V_97 ) {
F_44 ( L_20 , V_97 ) ;
goto V_107;
}
return 0 ;
V_107:
F_13 ( V_2 -> V_83 -> V_96 ) ;
V_102:
F_13 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
V_100:
F_31 ( V_2 -> V_90 ) ;
V_98:
return V_97 ;
}
static int F_64 ( void * V_88 , bool V_76 )
{
struct V_108 * V_109 = V_88 ;
T_1 V_45 = ! V_76 ;
return F_15 ( V_109 -> V_43 , V_45 , NULL ) ;
}
static void F_65 ( struct V_82 * V_82 , void * V_88 )
{
struct V_108 * V_109 = V_88 ;
int V_71 ;
V_71 = F_17 ( V_109 -> V_2 , V_109 -> V_43 ) ;
if ( V_71 < 0 )
return;
F_40 ( V_109 -> V_82 , ! V_71 ) ;
}
static int F_66 ( void * V_88 , bool V_76 )
{
struct V_108 * V_109 = V_88 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_97 ;
F_38 ( & V_2 -> V_79 ) ;
V_97 = F_64 ( V_88 , V_76 ) ;
F_39 ( & V_2 -> V_79 ) ;
return V_97 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_108 * V_110 ,
const char * V_6 , enum V_111 type , int V_43 )
{
int V_71 = F_17 ( V_2 , V_43 ) ;
struct V_82 * * V_82 = & V_110 -> V_82 ;
if ( V_71 < 0 )
return V_71 ;
V_110 -> V_43 = V_43 ;
V_110 -> V_2 = V_2 ;
if ( V_43 == V_72 &&
V_2 -> V_7 -> V_112 -> V_113 )
* V_82 = F_68 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_114 , V_110 ) ;
else
* V_82 = F_68 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_115 , V_110 ) ;
if ( ! * V_82 )
return - V_116 ;
F_69 ( * V_82 , ! V_71 ) ;
V_71 = F_70 ( * V_82 ) ;
if ( V_71 ) {
F_71 ( * V_82 ) ;
* V_82 = NULL ;
return V_71 ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_56 ( V_2 , L_21 ) ;
F_56 ( V_2 , L_22 ) ;
F_56 ( V_2 , L_23 ) ;
if ( V_2 -> V_81 . V_82 ) {
F_73 ( V_2 -> V_81 . V_82 ) ;
F_71 ( V_2 -> V_81 . V_82 ) ;
V_2 -> V_81 . V_82 = NULL ;
}
F_37 ( V_2 ) ;
if ( V_2 -> V_83 )
F_74 ( V_2 -> V_83 ) ;
if ( V_2 -> V_90 )
F_31 ( V_2 -> V_90 ) ;
if ( V_2 -> V_117 . V_82 ) {
F_73 ( V_2 -> V_117 . V_82 ) ;
F_71 ( V_2 -> V_117 . V_82 ) ;
V_2 -> V_117 . V_82 = NULL ;
}
if ( V_2 -> V_118 . V_82 ) {
F_73 ( V_2 -> V_118 . V_82 ) ;
F_71 ( V_2 -> V_118 . V_82 ) ;
V_2 -> V_118 . V_82 = NULL ;
}
if ( V_2 -> V_119 . V_82 ) {
F_73 ( V_2 -> V_119 . V_82 ) ;
F_71 ( V_2 -> V_119 . V_82 ) ;
V_2 -> V_119 . V_82 = NULL ;
}
if ( V_2 -> V_120 . V_82 ) {
F_73 ( V_2 -> V_120 . V_82 ) ;
F_71 ( V_2 -> V_120 . V_82 ) ;
V_2 -> V_120 . V_82 = NULL ;
}
if ( V_2 -> V_121 . V_82 ) {
F_73 ( V_2 -> V_121 . V_82 ) ;
F_71 ( V_2 -> V_121 . V_82 ) ;
V_2 -> V_121 . V_82 = NULL ;
}
}
static int F_75 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
F_76 ( & V_2 -> V_80 ) ;
F_76 ( & V_2 -> V_79 ) ;
V_71 = F_67 ( V_2 , & V_2 -> V_81 , L_24 ,
V_122 , V_72 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_117 ,
L_25 , V_123 ,
V_124 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_118 , L_26 ,
V_125 , V_126 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_119 , L_27 ,
V_127 , V_128 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_120 , L_28 ,
V_129 , V_130 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_121 , L_29 ,
V_131 , V_132 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
if ( ! V_2 -> V_7 -> V_112 -> V_113 )
goto exit;
V_71 = F_61 ( V_2 ) ;
if ( V_71 == - V_133 )
V_71 = 0 ;
F_52 ( V_2 , L_21 ) ;
F_52 ( V_2 , L_22 ) ;
F_52 ( V_2 , L_23 ) ;
F_37 ( V_2 ) ;
exit:
if ( V_71 && V_71 != - V_42 )
F_72 ( V_2 ) ;
if ( V_71 == - V_42 )
V_71 = 0 ;
return V_71 ;
}
static T_5 F_77 ( struct V_134 * V_14 ,
struct V_135 * V_136 ,
char * V_137 )
{
struct V_1 * V_2 = F_78 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_138 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 &= 0xFF ;
if ( V_39 == 1 )
V_39 = 85 ;
else if ( V_39 == 2 )
V_39 = 170 ;
else if ( V_39 == 3 )
V_39 = 255 ;
else if ( V_39 != 0 ) {
F_44 ( L_30 , V_39 ) ;
V_39 = - 1 ;
}
return sprintf ( V_137 , L_31 , V_39 ) ;
}
static T_5 F_79 ( struct V_134 * V_14 ,
struct V_135 * V_136 ,
char * V_137 )
{
struct V_1 * V_2 = F_78 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_139 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_80 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_137 , L_31 , V_39 ) ;
}
static T_5
F_81 ( struct V_134 * V_14 , struct V_135 * V_136 , char * V_137 )
{
return sprintf ( V_137 , L_32 ) ;
}
static T_6 F_82 ( struct V_140 * V_141 ,
struct V_142 * V_136 , int V_143 )
{
struct V_134 * V_14 = F_19 ( V_141 , struct V_134 , V_141 ) ;
struct V_16 * V_144 = F_83 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_84 ( V_144 ) ;
bool V_145 = true ;
int V_43 = - 1 ;
T_1 V_39 = V_41 ;
if ( V_136 == & V_146 . V_147 . V_136 )
V_43 = V_138 ;
else if ( V_136 == & V_148 . V_147 . V_136 )
V_43 = V_139 ;
if ( V_43 != - 1 ) {
int V_3 = F_14 ( V_2 , V_43 , & V_39 ) ;
if ( V_3 < 0 )
return 0 ;
}
if ( V_43 == V_138 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_149 && ! ( V_39 & V_48 ) ) )
V_145 = false ;
} else if ( V_43 == V_139 ) {
if ( V_39 == 0 )
V_145 = false ;
}
return V_145 ? V_136 -> V_150 : 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_134 * V_151 ;
V_151 = V_2 -> V_152 ;
if ( ! V_151 )
return;
F_86 ( & V_151 -> V_141 , & V_153 ) ;
F_87 ( V_151 ) ;
V_2 -> V_152 = NULL ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_134 * V_151 ;
int V_71 ;
V_151 = F_89 ( & V_2 -> V_16 -> V_14 ) ;
if ( F_90 ( V_151 ) ) {
F_44 ( L_33 ) ;
return F_91 ( V_151 ) ;
}
F_92 ( V_151 , V_2 ) ;
V_2 -> V_152 = V_151 ;
V_71 = F_93 ( & V_151 -> V_141 , & V_153 ) ;
if ( V_71 )
F_85 ( V_2 ) ;
return V_71 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_97 ;
if ( V_2 -> V_7 -> V_112 -> V_154 )
V_97 = ! V_2 -> V_7 -> V_155 ;
else
V_97 = F_17 ( V_2 ,
V_156 ) ;
if ( V_97 < 0 )
return V_97 ;
return V_97 ? V_157 : V_158 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_159 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_160 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_96 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_97 ( V_162 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_159 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_163 ;
}
static T_1 F_98 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_97 ( V_162 ) ;
T_1 V_45 = 0 ;
if ( ( V_2 -> V_7 -> V_164 < V_162 -> V_165 . V_164 ) ||
V_162 -> V_165 . V_164 == V_162 -> V_165 . V_67 )
V_45 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_164 > V_162 -> V_165 . V_164 ) ||
V_162 -> V_165 . V_164 == 0 )
V_45 = 0x00008000 ;
V_2 -> V_7 -> V_164 = V_162 -> V_165 . V_164 ;
return V_45 ;
}
static int F_99 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_97 ( V_162 ) ;
T_1 V_45 ;
int V_166 , V_3 = 0 ;
V_166 = F_94 ( V_2 ) ;
if ( V_166 != - V_42 && V_162 -> V_165 . V_166 != V_166 ) {
V_45 = ! ! ( V_162 -> V_165 . V_166 == V_157 ) ;
V_3 = F_15 ( V_156 ,
V_45 , NULL ) ;
if ( V_2 -> V_7 -> V_112 -> V_154 )
V_2 -> V_7 -> V_155 = V_162 -> V_165 . V_166 ;
if ( V_2 -> V_7 -> V_112 -> V_167 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_112 -> V_167 )
V_45 = F_98 ( V_162 ) ;
else
V_45 = V_162 -> V_165 . V_164 ;
V_3 = F_15 ( V_159 ,
V_45 , NULL ) ;
return V_3 ;
}
static int F_100 ( struct V_1 * V_2 , int V_168 )
{
struct V_161 * V_162 = V_2 -> V_161 ;
int V_169 = V_162 -> V_165 . V_164 ;
int V_170 = V_169 ;
if ( V_168 >= V_171 && V_168 <= V_172 )
V_170 = V_168 - V_171 + 1 ;
else if ( V_168 >= V_173 && V_168 <= V_174 )
V_170 = V_168 - V_173 ;
V_162 -> V_165 . V_164 = V_170 ;
F_101 ( V_162 ) ;
F_102 ( V_162 , V_175 ) ;
return V_169 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_161 * V_162 ;
struct V_176 V_165 ;
int V_177 ;
int V_166 ;
V_177 = F_95 ( V_2 ) ;
if ( V_177 == - V_42 )
V_177 = 0 ;
else if ( V_177 < 0 )
return V_177 ;
V_166 = F_94 ( V_2 ) ;
if ( V_166 == - V_42 )
V_166 = V_157 ;
else if ( V_166 < 0 )
return V_166 ;
memset ( & V_165 , 0 , sizeof( struct V_176 ) ) ;
V_165 . type = V_178 ;
V_165 . V_67 = V_177 ;
V_162 = F_104 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_179 , & V_165 ) ;
if ( F_90 ( V_162 ) ) {
F_44 ( L_34 ) ;
return F_91 ( V_162 ) ;
}
V_2 -> V_161 = V_162 ;
if ( V_2 -> V_7 -> V_112 -> V_154 )
V_2 -> V_7 -> V_155 = V_166 ;
V_162 -> V_165 . V_164 = F_96 ( V_162 ) ;
V_162 -> V_165 . V_166 = V_166 ;
F_101 ( V_162 ) ;
V_2 -> V_7 -> V_164 = V_162 -> V_165 . V_164 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
if ( V_2 -> V_161 )
F_106 ( V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
}
static void F_107 ( T_1 V_39 , void * V_180 )
{
struct V_1 * V_2 = V_180 ;
struct V_27 V_181 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_168 ;
int V_182 ;
unsigned int V_183 = 1 ;
bool V_184 = 1 ;
V_32 = F_108 ( V_39 , & V_181 ) ;
if ( V_32 != V_94 ) {
F_44 ( L_35 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_181 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_168 = V_34 -> integer . V_39 ;
V_182 = V_168 ;
if ( V_2 -> V_7 -> V_185 ) {
V_2 -> V_7 -> V_185 ( V_2 -> V_7 , & V_168 , & V_183 ,
& V_184 ) ;
if ( V_168 == V_186 )
goto exit;
}
if ( V_168 >= V_171 && V_168 <= V_172 )
V_168 = V_171 ;
else if ( V_168 >= V_173 &&
V_168 <= V_174 )
V_168 = V_173 ;
if ( V_168 == V_171 || V_168 == V_173 ) {
if ( ! F_109 () )
F_100 ( V_2 , V_182 ) ;
} else if ( ! F_110 ( V_2 -> V_4 , V_168 ,
V_183 , V_184 ) )
F_111 ( L_36 , V_168 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_112 ( const char * V_137 , unsigned long V_187 , int * V_188 )
{
if ( ! V_187 )
return 0 ;
if ( sscanf ( V_137 , L_37 , V_188 ) != 1 )
return - V_116 ;
return V_187 ;
}
static T_5 F_113 ( struct V_1 * V_2 , int V_189 ,
const char * V_137 , T_7 V_187 )
{
T_1 V_25 ;
int V_68 , V_3 , V_39 ;
V_39 = F_17 ( V_2 , V_189 ) ;
if ( V_39 == - V_42 )
return V_39 ;
V_68 = F_112 ( V_137 , V_187 , & V_39 ) ;
V_3 = F_15 ( V_189 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_68 ;
}
static T_5 F_114 ( struct V_1 * V_2 , int V_189 , char * V_137 )
{
int V_39 = F_17 ( V_2 , V_189 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_137 , L_31 , V_39 ) ;
}
static T_5 F_115 ( struct V_134 * V_14 , struct V_135 * V_136 ,
const char * V_137 , T_7 V_187 )
{
int V_39 , V_68 ;
if ( ! V_187 || sscanf ( V_137 , L_37 , & V_39 ) != 1 )
return - V_116 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_116 ;
V_68 = F_10 ( V_190 , V_39 , 0 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
return V_187 ;
}
static T_6 F_116 ( struct V_140 * V_141 ,
struct V_142 * V_136 , int V_143 )
{
struct V_134 * V_14 = F_19 ( V_141 , struct V_134 , V_141 ) ;
struct V_16 * V_144 = F_83 ( V_14 ) ;
struct V_1 * V_2 = F_84 ( V_144 ) ;
bool V_145 = true ;
int V_189 = - 1 ;
if ( V_136 == & V_191 . V_136 )
V_189 = V_192 ;
else if ( V_136 == & V_193 . V_136 )
V_189 = V_194 ;
else if ( V_136 == & V_195 . V_136 )
V_189 = V_196 ;
if ( V_189 != - 1 )
V_145 = ! ( F_17 ( V_2 , V_189 ) < 0 ) ;
return V_145 ? V_136 -> V_150 : 0 ;
}
static void F_117 ( struct V_16 * V_134 )
{
F_86 ( & V_134 -> V_14 . V_141 , & V_197 ) ;
}
static int F_118 ( struct V_16 * V_134 )
{
return F_93 ( & V_134 -> V_14 . V_141 , & V_197 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_68 ;
if ( ! F_10 ( V_198 , 0 , 0 , & V_68 ) )
F_111 ( L_38 , V_68 ) ;
if ( ! F_10 ( V_199 , 0 , 0x9 , & V_68 ) ) {
F_111 ( L_39 , V_68 >> 16 , V_68 & 0xFF ) ;
V_2 -> V_200 = V_68 ;
}
if ( ! F_10 ( V_201 , 0 , 0 , & V_68 ) ) {
F_111 ( L_40 , V_68 ) ;
V_2 -> V_149 = V_68 ;
}
if ( ! F_10 ( V_202 , 0 , 0 , NULL ) )
V_2 -> V_44 = V_202 ;
else if ( ! F_10 ( V_203 , 0 , 0 , NULL ) )
V_2 -> V_44 = V_203 ;
if ( ! V_2 -> V_44 ) {
F_44 ( L_41 ) ;
return - V_42 ;
}
if ( V_2 -> V_7 -> V_112 -> V_204 >= 0 )
F_15 ( V_205 ,
V_2 -> V_7 -> V_112 -> V_204 , NULL ) ;
return F_118 ( V_2 -> V_16 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_117 ( V_2 -> V_16 ) ;
}
static int F_121 ( struct V_206 * V_207 , void * V_88 )
{
struct V_1 * V_2 = V_207 -> V_95 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_14 ( V_2 , V_2 -> V_208 . V_43 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_122 ( V_207 , L_42 , V_2 -> V_208 . V_43 , V_25 ) ;
return 0 ;
}
static int F_123 ( struct V_206 * V_207 , void * V_88 )
{
struct V_1 * V_2 = V_207 -> V_95 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_15 ( V_2 -> V_208 . V_43 , V_2 -> V_208 . V_45 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_122 ( V_207 , L_43 , V_2 -> V_208 . V_43 ,
V_2 -> V_208 . V_45 , V_25 ) ;
return 0 ;
}
static int F_124 ( struct V_206 * V_207 , void * V_88 )
{
struct V_1 * V_2 = V_207 -> V_95 ;
struct V_26 args = {
. V_23 = V_2 -> V_208 . V_43 ,
. V_24 = V_2 -> V_208 . V_45 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_208 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_122 ( V_207 , L_44 , V_2 -> V_208 . V_22 ,
V_2 -> V_208 . V_43 , V_2 -> V_208 . V_45 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_122 ( V_207 , L_45 , V_2 -> V_208 . V_22 ,
V_2 -> V_208 . V_43 , V_2 -> V_208 . V_45 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_125 ( struct V_209 * V_209 , struct V_210 * V_210 )
{
struct V_211 * V_92 = V_209 -> V_212 ;
return F_126 ( V_210 , V_92 -> V_213 , V_92 -> V_2 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 ( V_2 -> V_208 . V_214 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_215 * V_216 ;
int V_217 ;
V_2 -> V_208 . V_214 = F_130 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_208 . V_214 ) {
F_44 ( L_46 ) ;
goto V_218;
}
V_216 = F_131 ( L_47 , V_219 | V_220 ,
V_2 -> V_208 . V_214 , & V_2 -> V_208 . V_22 ) ;
if ( ! V_216 )
goto V_218;
V_216 = F_131 ( L_48 , V_219 | V_220 ,
V_2 -> V_208 . V_214 , & V_2 -> V_208 . V_43 ) ;
if ( ! V_216 )
goto V_218;
V_216 = F_131 ( L_49 , V_219 | V_220 ,
V_2 -> V_208 . V_214 , & V_2 -> V_208 . V_45 ) ;
if ( ! V_216 )
goto V_218;
for ( V_217 = 0 ; V_217 < F_132 ( V_221 ) ; V_217 ++ ) {
struct V_211 * V_92 = & V_221 [ V_217 ] ;
V_92 -> V_2 = V_2 ;
V_216 = F_133 ( V_92 -> V_6 , V_222 | V_219 ,
V_2 -> V_208 . V_214 , V_92 ,
& V_223 ) ;
if ( ! V_216 ) {
F_44 ( L_50 , V_92 -> V_6 ) ;
goto V_218;
}
}
return 0 ;
V_218:
F_127 ( V_2 ) ;
return - V_5 ;
}
static int F_134 ( struct V_16 * V_144 )
{
struct V_224 * V_225 = F_135 ( V_144 -> V_14 . V_7 ) ;
struct V_226 * V_227 = F_136 ( V_225 ) ;
struct V_1 * V_2 ;
T_2 V_32 ;
int V_3 ;
V_2 = F_62 ( sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_227 ;
V_2 -> V_16 = V_144 ;
V_227 -> V_16 = V_144 ;
F_137 ( V_2 -> V_16 , V_2 ) ;
if ( V_227 -> V_228 )
V_227 -> V_228 ( V_2 -> V_7 ) ;
V_3 = F_119 ( V_2 ) ;
if ( V_3 )
goto V_229;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_230;
V_3 = F_88 ( V_2 ) ;
if ( V_3 )
goto V_231;
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
goto V_232;
V_3 = F_75 ( V_2 ) ;
if ( V_3 )
goto V_233;
if ( ! F_109 () ) {
V_3 = F_103 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_234;
} else
F_111 ( L_51 ) ;
V_32 = F_138 ( V_2 -> V_7 -> V_235 ,
F_107 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_44 ( L_52 , V_32 ) ;
V_3 = - V_42 ;
goto V_236;
}
V_3 = F_129 ( V_2 ) ;
if ( V_3 )
goto V_237;
return 0 ;
V_237:
F_139 ( V_2 -> V_7 -> V_235 ) ;
V_236:
F_105 ( V_2 ) ;
V_234:
F_72 ( V_2 ) ;
V_233:
F_28 ( V_2 ) ;
V_232:
F_85 ( V_2 ) ;
V_231:
F_8 ( V_2 ) ;
V_230:
F_120 ( V_2 ) ;
V_229:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_140 ( struct V_16 * V_134 )
{
struct V_1 * V_2 ;
V_2 = F_84 ( V_134 ) ;
F_139 ( V_2 -> V_7 -> V_235 ) ;
F_105 ( V_2 ) ;
F_8 ( V_2 ) ;
F_85 ( V_2 ) ;
F_28 ( V_2 ) ;
F_72 ( V_2 ) ;
F_127 ( V_2 ) ;
F_120 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_141 ( struct V_134 * V_134 )
{
struct V_1 * V_2 = F_78 ( V_134 ) ;
if ( V_2 -> V_81 . V_82 ) {
bool V_81 ;
V_81 = F_17 ( V_2 , V_72 ) ;
F_15 ( V_72 , V_81 , NULL ) ;
}
return 0 ;
}
static int F_142 ( struct V_134 * V_134 )
{
struct V_1 * V_2 = F_78 ( V_134 ) ;
int V_238 ;
if ( V_2 -> V_81 . V_82 )
F_37 ( V_2 ) ;
if ( V_2 -> V_117 . V_82 ) {
V_238 = ! F_17 ( V_2 ,
V_124 ) ;
F_40 ( V_2 -> V_117 . V_82 , V_238 ) ;
}
if ( V_2 -> V_118 . V_82 ) {
V_238 = ! F_17 ( V_2 , V_126 ) ;
F_40 ( V_2 -> V_118 . V_82 , V_238 ) ;
}
if ( V_2 -> V_119 . V_82 ) {
V_238 = ! F_17 ( V_2 , V_128 ) ;
F_40 ( V_2 -> V_119 . V_82 , V_238 ) ;
}
if ( V_2 -> V_120 . V_82 ) {
V_238 = ! F_17 ( V_2 , V_130 ) ;
F_40 ( V_2 -> V_120 . V_82 , V_238 ) ;
}
if ( V_2 -> V_121 . V_82 ) {
V_238 = ! F_17 ( V_2 , V_132 ) ;
F_40 ( V_2 -> V_121 . V_82 , V_238 ) ;
}
return 0 ;
}
static int F_143 ( struct V_16 * V_144 )
{
struct V_224 * V_225 = F_135 ( V_144 -> V_14 . V_7 ) ;
struct V_226 * V_227 = F_136 ( V_225 ) ;
int V_97 ;
if ( ! F_144 ( V_36 ) ) {
F_42 ( L_53 ) ;
return - V_42 ;
}
if ( V_227 -> V_235 && ! F_144 ( V_227 -> V_235 ) ) {
F_42 ( L_54 ) ;
return - V_42 ;
}
if ( V_227 -> V_239 ) {
V_97 = V_227 -> V_239 ( V_144 ) ;
if ( V_97 )
return V_97 ;
}
return F_134 ( V_144 ) ;
}
int T_8 F_145 ( struct V_226 * V_7 )
{
struct V_224 * V_224 ;
struct V_16 * V_16 ;
if ( V_240 )
return - V_133 ;
V_224 = & V_7 -> V_224 ;
V_224 -> remove = F_140 ;
V_224 -> V_7 . V_241 = V_7 -> V_241 ;
V_224 -> V_7 . V_6 = V_7 -> V_6 ;
V_224 -> V_7 . V_242 = & V_243 ;
V_16 = F_146 ( V_224 ,
F_143 ,
NULL , 0 , NULL , 0 ) ;
if ( F_90 ( V_16 ) )
return F_91 ( V_16 ) ;
V_240 = true ;
return 0 ;
}
void F_147 ( struct V_226 * V_7 )
{
F_148 ( V_7 -> V_16 ) ;
F_149 ( & V_7 -> V_224 ) ;
V_240 = false ;
}
static int T_9 F_150 ( void )
{
if ( ! F_144 ( V_36 ) ) {
F_111 ( L_55 ) ;
return - V_42 ;
}
F_111 ( L_56 ) ;
return 0 ;
}
static void T_10 F_151 ( void )
{
F_111 ( L_57 ) ;
}
