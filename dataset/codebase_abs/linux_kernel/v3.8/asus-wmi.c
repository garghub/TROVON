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
T_1 V_43 = V_109 -> V_43 ;
if ( ( V_43 == V_72 ) &&
V_109 -> V_2 -> V_7 -> V_110 )
V_43 = V_111 ;
return F_15 ( V_43 , V_45 , NULL ) ;
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
struct V_108 * V_112 ,
const char * V_6 , enum V_113 type , int V_43 )
{
int V_71 = F_17 ( V_2 , V_43 ) ;
struct V_82 * * V_82 = & V_112 -> V_82 ;
if ( V_71 < 0 )
return V_71 ;
V_112 -> V_43 = V_43 ;
V_112 -> V_2 = V_2 ;
if ( V_43 == V_72 &&
V_2 -> V_7 -> V_114 -> V_115 )
* V_82 = F_68 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_116 , V_112 ) ;
else
* V_82 = F_68 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_117 , V_112 ) ;
if ( ! * V_82 )
return - V_118 ;
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
if ( V_2 -> V_122 . V_82 ) {
F_73 ( V_2 -> V_122 . V_82 ) ;
F_71 ( V_2 -> V_122 . V_82 ) ;
V_2 -> V_122 . V_82 = NULL ;
}
if ( V_2 -> V_123 . V_82 ) {
F_73 ( V_2 -> V_123 . V_82 ) ;
F_71 ( V_2 -> V_123 . V_82 ) ;
V_2 -> V_123 . V_82 = NULL ;
}
}
static int F_75 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
F_76 ( & V_2 -> V_80 ) ;
F_76 ( & V_2 -> V_79 ) ;
V_71 = F_67 ( V_2 , & V_2 -> V_81 , L_24 ,
V_124 , V_72 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_119 ,
L_25 , V_125 ,
V_126 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_120 , L_26 ,
V_127 , V_128 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_121 , L_27 ,
V_129 , V_130 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_122 , L_28 ,
V_131 , V_132 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
V_71 = F_67 ( V_2 , & V_2 -> V_123 , L_29 ,
V_133 , V_134 ) ;
if ( V_71 && V_71 != - V_42 )
goto exit;
if ( ! V_2 -> V_7 -> V_114 -> V_115 )
goto exit;
V_71 = F_61 ( V_2 ) ;
if ( V_71 == - V_135 )
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
static T_5 F_77 ( struct V_136 * V_14 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_1 * V_2 = F_78 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_140 , & V_39 ) ;
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
return sprintf ( V_139 , L_31 , V_39 ) ;
}
static T_5 F_79 ( struct V_136 * V_14 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_1 * V_2 = F_78 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_141 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_80 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_139 , L_31 , V_39 ) ;
}
static T_5
F_81 ( struct V_136 * V_14 , struct V_137 * V_138 , char * V_139 )
{
return sprintf ( V_139 , L_32 ) ;
}
static T_6 F_82 ( struct V_142 * V_143 ,
struct V_144 * V_138 , int V_145 )
{
struct V_136 * V_14 = F_19 ( V_143 , struct V_136 , V_143 ) ;
struct V_16 * V_146 = F_83 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_84 ( V_146 ) ;
bool V_147 = true ;
int V_43 = - 1 ;
T_1 V_39 = V_41 ;
if ( V_138 == & V_148 . V_149 . V_138 )
V_43 = V_140 ;
else if ( V_138 == & V_150 . V_149 . V_138 )
V_43 = V_141 ;
if ( V_43 != - 1 ) {
int V_3 = F_14 ( V_2 , V_43 , & V_39 ) ;
if ( V_3 < 0 )
return 0 ;
}
if ( V_43 == V_140 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_151 && ! ( V_39 & V_48 ) ) )
V_147 = false ;
} else if ( V_43 == V_141 ) {
if ( V_39 == 0 )
V_147 = false ;
}
return V_147 ? V_138 -> V_152 : 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_136 * V_153 ;
V_153 = V_2 -> V_154 ;
if ( ! V_153 )
return;
F_86 ( & V_153 -> V_143 , & V_155 ) ;
F_87 ( V_153 ) ;
V_2 -> V_154 = NULL ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_136 * V_153 ;
int V_71 ;
V_153 = F_89 ( & V_2 -> V_16 -> V_14 ) ;
if ( F_90 ( V_153 ) ) {
F_44 ( L_33 ) ;
return F_91 ( V_153 ) ;
}
F_92 ( V_153 , V_2 ) ;
V_2 -> V_154 = V_153 ;
V_71 = F_93 ( & V_153 -> V_143 , & V_155 ) ;
if ( V_71 )
F_85 ( V_2 ) ;
return V_71 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_97 ;
if ( V_2 -> V_7 -> V_114 -> V_156 )
V_97 = ! V_2 -> V_7 -> V_157 ;
else
V_97 = F_17 ( V_2 ,
V_158 ) ;
if ( V_97 < 0 )
return V_97 ;
return V_97 ? V_159 : V_160 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_161 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_162 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_96 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_97 ( V_164 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_161 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_165 ;
}
static T_1 F_98 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_97 ( V_164 ) ;
T_1 V_45 = 0 ;
if ( ( V_2 -> V_7 -> V_166 < V_164 -> V_167 . V_166 ) ||
V_164 -> V_167 . V_166 == V_164 -> V_167 . V_67 )
V_45 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_166 > V_164 -> V_167 . V_166 ) ||
V_164 -> V_167 . V_166 == 0 )
V_45 = 0x00008000 ;
V_2 -> V_7 -> V_166 = V_164 -> V_167 . V_166 ;
return V_45 ;
}
static int F_99 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_97 ( V_164 ) ;
T_1 V_45 ;
int V_168 , V_3 = 0 ;
V_168 = F_94 ( V_2 ) ;
if ( V_168 != - V_42 && V_164 -> V_167 . V_168 != V_168 ) {
V_45 = ! ! ( V_164 -> V_167 . V_168 == V_159 ) ;
V_3 = F_15 ( V_158 ,
V_45 , NULL ) ;
if ( V_2 -> V_7 -> V_114 -> V_156 )
V_2 -> V_7 -> V_157 = V_164 -> V_167 . V_168 ;
if ( V_2 -> V_7 -> V_114 -> V_169 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_114 -> V_169 )
V_45 = F_98 ( V_164 ) ;
else
V_45 = V_164 -> V_167 . V_166 ;
V_3 = F_15 ( V_161 ,
V_45 , NULL ) ;
return V_3 ;
}
static int F_100 ( struct V_1 * V_2 , int V_170 )
{
struct V_163 * V_164 = V_2 -> V_163 ;
int V_171 = V_164 -> V_167 . V_166 ;
int V_172 = V_171 ;
if ( V_170 >= V_173 && V_170 <= V_174 )
V_172 = V_170 - V_173 + 1 ;
else if ( V_170 >= V_175 && V_170 <= V_176 )
V_172 = V_170 - V_175 ;
V_164 -> V_167 . V_166 = V_172 ;
F_101 ( V_164 ) ;
F_102 ( V_164 , V_177 ) ;
return V_171 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_163 * V_164 ;
struct V_178 V_167 ;
int V_179 ;
int V_168 ;
V_179 = F_95 ( V_2 ) ;
if ( V_179 == - V_42 )
V_179 = 0 ;
else if ( V_179 < 0 )
return V_179 ;
V_168 = F_94 ( V_2 ) ;
if ( V_168 == - V_42 )
V_168 = V_159 ;
else if ( V_168 < 0 )
return V_168 ;
memset ( & V_167 , 0 , sizeof( struct V_178 ) ) ;
V_167 . type = V_180 ;
V_167 . V_67 = V_179 ;
V_164 = F_104 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_181 , & V_167 ) ;
if ( F_90 ( V_164 ) ) {
F_44 ( L_34 ) ;
return F_91 ( V_164 ) ;
}
V_2 -> V_163 = V_164 ;
if ( V_2 -> V_7 -> V_114 -> V_156 )
V_2 -> V_7 -> V_157 = V_168 ;
V_164 -> V_167 . V_166 = F_96 ( V_164 ) ;
V_164 -> V_167 . V_168 = V_168 ;
F_101 ( V_164 ) ;
V_2 -> V_7 -> V_166 = V_164 -> V_167 . V_166 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
if ( V_2 -> V_163 )
F_106 ( V_2 -> V_163 ) ;
V_2 -> V_163 = NULL ;
}
static void F_107 ( T_1 V_39 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
struct V_27 V_183 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_170 ;
int V_184 ;
unsigned int V_185 = 1 ;
bool V_186 = 1 ;
V_32 = F_108 ( V_39 , & V_183 ) ;
if ( V_32 != V_94 ) {
F_44 ( L_35 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_183 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_170 = V_34 -> integer . V_39 ;
V_184 = V_170 ;
if ( V_2 -> V_7 -> V_187 ) {
V_2 -> V_7 -> V_187 ( V_2 -> V_7 , & V_170 , & V_185 ,
& V_186 ) ;
if ( V_170 == V_188 )
goto exit;
}
if ( V_170 >= V_173 && V_170 <= V_174 )
V_170 = V_173 ;
else if ( V_170 >= V_175 &&
V_170 <= V_176 )
V_170 = V_175 ;
if ( V_170 == V_173 || V_170 == V_175 ) {
if ( ! F_109 () )
F_100 ( V_2 , V_184 ) ;
} else if ( ! F_110 ( V_2 -> V_4 , V_170 ,
V_185 , V_186 ) )
F_111 ( L_36 , V_170 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_112 ( const char * V_139 , unsigned long V_189 , int * V_190 )
{
if ( ! V_189 )
return 0 ;
if ( sscanf ( V_139 , L_37 , V_190 ) != 1 )
return - V_118 ;
return V_189 ;
}
static T_5 F_113 ( struct V_1 * V_2 , int V_191 ,
const char * V_139 , T_7 V_189 )
{
T_1 V_25 ;
int V_68 , V_3 , V_39 ;
V_39 = F_17 ( V_2 , V_191 ) ;
if ( V_39 == - V_42 )
return V_39 ;
V_68 = F_112 ( V_139 , V_189 , & V_39 ) ;
V_3 = F_15 ( V_191 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_68 ;
}
static T_5 F_114 ( struct V_1 * V_2 , int V_191 , char * V_139 )
{
int V_39 = F_17 ( V_2 , V_191 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_139 , L_31 , V_39 ) ;
}
static T_5 F_115 ( struct V_136 * V_14 , struct V_137 * V_138 ,
const char * V_139 , T_7 V_189 )
{
int V_39 , V_68 ;
if ( ! V_189 || sscanf ( V_139 , L_37 , & V_39 ) != 1 )
return - V_118 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_118 ;
V_68 = F_10 ( V_192 , V_39 , 0 , NULL ) ;
if ( V_68 < 0 )
return V_68 ;
return V_189 ;
}
static T_6 F_116 ( struct V_142 * V_143 ,
struct V_144 * V_138 , int V_145 )
{
struct V_136 * V_14 = F_19 ( V_143 , struct V_136 , V_143 ) ;
struct V_16 * V_146 = F_83 ( V_14 ) ;
struct V_1 * V_2 = F_84 ( V_146 ) ;
bool V_147 = true ;
int V_191 = - 1 ;
if ( V_138 == & V_193 . V_138 )
V_191 = V_194 ;
else if ( V_138 == & V_195 . V_138 )
V_191 = V_196 ;
else if ( V_138 == & V_197 . V_138 )
V_191 = V_198 ;
else if ( V_138 == & V_199 . V_138 )
V_191 = V_200 ;
if ( V_191 != - 1 )
V_147 = ! ( F_17 ( V_2 , V_191 ) < 0 ) ;
return V_147 ? V_138 -> V_152 : 0 ;
}
static void F_117 ( struct V_16 * V_136 )
{
F_86 ( & V_136 -> V_14 . V_143 , & V_201 ) ;
}
static int F_118 ( struct V_16 * V_136 )
{
return F_93 ( & V_136 -> V_14 . V_143 , & V_201 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_68 ;
if ( ! F_10 ( V_202 , 0 , 0 , & V_68 ) )
F_111 ( L_38 , V_68 ) ;
if ( ! F_10 ( V_203 , 0 , 0x9 , & V_68 ) ) {
F_111 ( L_39 , V_68 >> 16 , V_68 & 0xFF ) ;
V_2 -> V_204 = V_68 ;
}
if ( ! F_10 ( V_205 , 0 , 0 , & V_68 ) ) {
F_111 ( L_40 , V_68 ) ;
V_2 -> V_151 = V_68 ;
}
if ( ! F_10 ( V_206 , 0 , 0 , NULL ) )
V_2 -> V_44 = V_206 ;
else
V_2 -> V_44 = V_207 ;
if ( V_2 -> V_7 -> V_114 -> V_208 >= 0 )
F_15 ( V_209 ,
V_2 -> V_7 -> V_114 -> V_208 , NULL ) ;
return F_118 ( V_2 -> V_16 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_117 ( V_2 -> V_16 ) ;
}
static int F_121 ( struct V_210 * V_211 , void * V_88 )
{
struct V_1 * V_2 = V_211 -> V_95 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_14 ( V_2 , V_2 -> V_212 . V_43 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_122 ( V_211 , L_41 , V_2 -> V_212 . V_43 , V_25 ) ;
return 0 ;
}
static int F_123 ( struct V_210 * V_211 , void * V_88 )
{
struct V_1 * V_2 = V_211 -> V_95 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_15 ( V_2 -> V_212 . V_43 , V_2 -> V_212 . V_45 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_122 ( V_211 , L_42 , V_2 -> V_212 . V_43 ,
V_2 -> V_212 . V_45 , V_25 ) ;
return 0 ;
}
static int F_124 ( struct V_210 * V_211 , void * V_88 )
{
struct V_1 * V_2 = V_211 -> V_95 ;
struct V_26 args = {
. V_23 = V_2 -> V_212 . V_43 ,
. V_24 = V_2 -> V_212 . V_45 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_212 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_122 ( V_211 , L_43 , V_2 -> V_212 . V_22 ,
V_2 -> V_212 . V_43 , V_2 -> V_212 . V_45 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_122 ( V_211 , L_44 , V_2 -> V_212 . V_22 ,
V_2 -> V_212 . V_43 , V_2 -> V_212 . V_45 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_125 ( struct V_213 * V_213 , struct V_214 * V_214 )
{
struct V_215 * V_92 = V_213 -> V_216 ;
return F_126 ( V_214 , V_92 -> V_217 , V_92 -> V_2 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 ( V_2 -> V_212 . V_218 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_219 * V_220 ;
int V_221 ;
V_2 -> V_212 . V_218 = F_130 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_212 . V_218 ) {
F_44 ( L_45 ) ;
goto V_222;
}
V_220 = F_131 ( L_46 , V_223 | V_224 ,
V_2 -> V_212 . V_218 , & V_2 -> V_212 . V_22 ) ;
if ( ! V_220 )
goto V_222;
V_220 = F_131 ( L_47 , V_223 | V_224 ,
V_2 -> V_212 . V_218 , & V_2 -> V_212 . V_43 ) ;
if ( ! V_220 )
goto V_222;
V_220 = F_131 ( L_48 , V_223 | V_224 ,
V_2 -> V_212 . V_218 , & V_2 -> V_212 . V_45 ) ;
if ( ! V_220 )
goto V_222;
for ( V_221 = 0 ; V_221 < F_132 ( V_225 ) ; V_221 ++ ) {
struct V_215 * V_92 = & V_225 [ V_221 ] ;
V_92 -> V_2 = V_2 ;
V_220 = F_133 ( V_92 -> V_6 , V_226 | V_223 ,
V_2 -> V_212 . V_218 , V_92 ,
& V_227 ) ;
if ( ! V_220 ) {
F_44 ( L_49 , V_92 -> V_6 ) ;
goto V_222;
}
}
return 0 ;
V_222:
F_127 ( V_2 ) ;
return - V_5 ;
}
static int F_134 ( struct V_16 * V_146 )
{
struct V_228 * V_229 = F_135 ( V_146 -> V_14 . V_7 ) ;
struct V_230 * V_231 = F_136 ( V_229 ) ;
struct V_1 * V_2 ;
T_2 V_32 ;
int V_3 ;
T_1 V_71 ;
V_2 = F_62 ( sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_231 ;
V_2 -> V_16 = V_146 ;
V_231 -> V_16 = V_146 ;
F_137 ( V_2 -> V_16 , V_2 ) ;
if ( V_231 -> V_232 )
V_231 -> V_232 ( V_2 -> V_7 ) ;
V_3 = F_119 ( V_2 ) ;
if ( V_3 )
goto V_233;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_234;
V_3 = F_88 ( V_2 ) ;
if ( V_3 )
goto V_235;
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
goto V_236;
V_3 = F_75 ( V_2 ) ;
if ( V_3 )
goto V_237;
if ( V_2 -> V_7 -> V_114 -> V_238 )
F_138 () ;
if ( ! F_109 () ) {
F_111 ( L_50 ) ;
F_139 () ;
V_3 = F_103 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_239;
} else
F_111 ( L_51 ) ;
V_32 = F_140 ( V_2 -> V_7 -> V_240 ,
F_107 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_44 ( L_52 , V_32 ) ;
V_3 = - V_42 ;
goto V_241;
}
V_3 = F_129 ( V_2 ) ;
if ( V_3 )
goto V_242;
F_14 ( V_2 , V_72 , & V_71 ) ;
if ( V_71 & ( V_48 | V_243 ) )
V_2 -> V_7 -> V_110 = 1 ;
return 0 ;
V_242:
F_141 ( V_2 -> V_7 -> V_240 ) ;
V_241:
F_105 ( V_2 ) ;
V_239:
F_72 ( V_2 ) ;
V_237:
F_28 ( V_2 ) ;
V_236:
F_85 ( V_2 ) ;
V_235:
F_8 ( V_2 ) ;
V_234:
F_120 ( V_2 ) ;
V_233:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_142 ( struct V_16 * V_136 )
{
struct V_1 * V_2 ;
V_2 = F_84 ( V_136 ) ;
F_141 ( V_2 -> V_7 -> V_240 ) ;
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
static int F_143 ( struct V_136 * V_136 )
{
struct V_1 * V_2 = F_78 ( V_136 ) ;
if ( V_2 -> V_81 . V_82 ) {
bool V_81 ;
V_81 = F_17 ( V_2 , V_72 ) ;
F_15 ( V_72 , V_81 , NULL ) ;
}
return 0 ;
}
static int F_144 ( struct V_136 * V_136 )
{
struct V_1 * V_2 = F_78 ( V_136 ) ;
int V_244 ;
if ( V_2 -> V_81 . V_82 )
F_37 ( V_2 ) ;
if ( V_2 -> V_119 . V_82 ) {
V_244 = ! F_17 ( V_2 ,
V_126 ) ;
F_40 ( V_2 -> V_119 . V_82 , V_244 ) ;
}
if ( V_2 -> V_120 . V_82 ) {
V_244 = ! F_17 ( V_2 , V_128 ) ;
F_40 ( V_2 -> V_120 . V_82 , V_244 ) ;
}
if ( V_2 -> V_121 . V_82 ) {
V_244 = ! F_17 ( V_2 , V_130 ) ;
F_40 ( V_2 -> V_121 . V_82 , V_244 ) ;
}
if ( V_2 -> V_122 . V_82 ) {
V_244 = ! F_17 ( V_2 , V_132 ) ;
F_40 ( V_2 -> V_122 . V_82 , V_244 ) ;
}
if ( V_2 -> V_123 . V_82 ) {
V_244 = ! F_17 ( V_2 , V_134 ) ;
F_40 ( V_2 -> V_123 . V_82 , V_244 ) ;
}
return 0 ;
}
static int F_145 ( struct V_16 * V_146 )
{
struct V_228 * V_229 = F_135 ( V_146 -> V_14 . V_7 ) ;
struct V_230 * V_231 = F_136 ( V_229 ) ;
int V_97 ;
if ( ! F_146 ( V_36 ) ) {
F_42 ( L_53 ) ;
return - V_42 ;
}
if ( V_231 -> V_240 && ! F_146 ( V_231 -> V_240 ) ) {
F_42 ( L_54 ) ;
return - V_42 ;
}
if ( V_231 -> V_245 ) {
V_97 = V_231 -> V_245 ( V_146 ) ;
if ( V_97 )
return V_97 ;
}
return F_134 ( V_146 ) ;
}
int T_8 F_147 ( struct V_230 * V_7 )
{
struct V_228 * V_228 ;
struct V_16 * V_16 ;
if ( V_246 )
return - V_135 ;
V_228 = & V_7 -> V_228 ;
V_228 -> remove = F_142 ;
V_228 -> V_7 . V_247 = V_7 -> V_247 ;
V_228 -> V_7 . V_6 = V_7 -> V_6 ;
V_228 -> V_7 . V_248 = & V_249 ;
V_16 = F_148 ( V_228 ,
F_145 ,
NULL , 0 , NULL , 0 ) ;
if ( F_90 ( V_16 ) )
return F_91 ( V_16 ) ;
V_246 = true ;
return 0 ;
}
void F_149 ( struct V_230 * V_7 )
{
F_150 ( V_7 -> V_16 ) ;
F_151 ( & V_7 -> V_228 ) ;
V_246 = false ;
}
static int T_9 F_152 ( void )
{
if ( ! F_146 ( V_36 ) ) {
F_111 ( L_55 ) ;
return - V_42 ;
}
F_111 ( L_56 ) ;
return 0 ;
}
static void T_10 F_153 ( void )
{
F_111 ( L_57 ) ;
}
