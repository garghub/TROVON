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
V_3 = F_3 ( V_2 -> V_4 , V_2 -> V_7 -> V_17 , NULL ) ;
if ( V_3 )
goto V_18;
V_3 = F_4 ( V_2 -> V_4 ) ;
if ( V_3 )
goto V_19;
return 0 ;
V_19:
F_5 ( V_2 -> V_4 ) ;
V_18:
F_6 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_5 ( V_2 -> V_4 ) ;
F_8 ( V_2 -> V_4 ) ;
}
V_2 -> V_4 = NULL ;
}
static int F_9 ( T_1 V_20 , T_1 V_21 , T_1 V_22 ,
T_1 * V_23 )
{
struct V_24 args = {
. V_21 = V_21 ,
. V_22 = V_22 ,
} ;
struct V_25 V_26 = { ( V_27 ) sizeof( args ) , & args } ;
struct V_25 V_28 = { V_29 , NULL } ;
T_2 V_30 ;
union V_31 * V_32 ;
T_1 V_33 ;
V_30 = F_10 ( V_34 , 1 , V_20 ,
& V_26 , & V_28 ) ;
if ( F_11 ( V_30 ) )
goto exit;
V_32 = (union V_31 * ) V_28 . V_35 ;
if ( V_32 && V_32 -> type == V_36 )
V_33 = ( T_1 ) V_32 -> integer . V_37 ;
else
V_33 = 0 ;
if ( V_23 )
* V_23 = V_33 ;
F_12 ( V_32 ) ;
exit:
if ( F_11 ( V_30 ) )
return - V_38 ;
if ( V_33 == V_39 )
return - V_40 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_41 , T_1 * V_23 )
{
return F_9 ( V_2 -> V_42 , V_41 , 0 , V_23 ) ;
}
static int F_14 ( T_1 V_41 , T_1 V_43 ,
T_1 * V_23 )
{
return F_9 ( V_44 , V_41 ,
V_43 , V_23 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_45 )
{
T_1 V_23 = 0 ;
int V_3 ;
V_3 = F_13 ( V_2 , V_41 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! ( V_23 & V_46 ) )
return - V_40 ;
if ( V_45 == V_47 ) {
if ( V_23 & V_48 )
return - V_40 ;
}
return V_23 & V_45 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_41 )
{
return F_15 ( V_2 , V_41 ,
V_47 ) ;
}
static void F_17 ( struct V_49 * V_50 )
{
int V_43 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_50 , struct V_1 , V_51 ) ;
V_43 = V_2 -> V_52 ;
F_14 ( V_53 , V_43 , NULL ) ;
}
static void F_19 ( struct V_54 * V_55 ,
enum V_56 V_37 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_55 , struct V_1 , V_57 ) ;
V_2 -> V_52 = ! ! V_37 ;
F_20 ( V_2 -> V_58 , & V_2 -> V_51 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , V_53 ) ;
}
static enum V_56 F_22 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_55 , struct V_1 , V_57 ) ;
return F_21 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_59 ;
if ( F_21 ( V_2 ) < 0 )
return 0 ;
V_2 -> V_58 = F_24 ( L_1 ) ;
if ( ! V_2 -> V_58 )
return - V_5 ;
F_25 ( & V_2 -> V_51 , F_17 ) ;
V_2 -> V_57 . V_6 = L_2 ;
V_2 -> V_57 . V_60 = F_19 ;
V_2 -> V_57 . V_61 = F_22 ;
V_2 -> V_57 . V_62 = 1 ;
V_59 = F_26 ( & V_2 -> V_16 -> V_14 , & V_2 -> V_57 ) ;
if ( V_59 ) {
F_27 ( V_2 -> V_58 ) ;
return V_59 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 . V_14 )
F_29 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_58 )
F_27 ( V_2 -> V_58 ) ;
}
static bool F_30 ( struct V_1 * V_2 )
{
int V_63 = F_16 ( V_2 , V_64 ) ;
if ( V_63 < 0 )
return false ;
return ! V_63 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_65 * V_14 ;
struct V_66 * V_67 ;
bool V_68 ;
bool V_69 ;
T_1 V_70 ;
F_32 ( & V_2 -> V_71 ) ;
V_68 = F_30 ( V_2 ) ;
F_33 ( & V_2 -> V_71 ) ;
F_32 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_73 . V_74 )
F_34 ( V_2 -> V_73 . V_74 , V_68 ) ;
if ( V_2 -> V_75 ) {
V_67 = F_35 ( 0 , 1 ) ;
if ( ! V_67 ) {
F_36 ( L_3 ) ;
goto V_76;
}
if ( F_37 ( V_67 , 0 , V_77 , & V_70 ) ) {
F_38 ( L_4 ) ;
goto V_76;
}
V_69 = ( V_70 == 0xffffffff ) ;
if ( V_68 != V_69 ) {
F_36 ( L_5
L_6 ,
V_68 ? L_7 : L_8 ,
V_69 ? L_9 : L_10 ) ;
F_36 ( L_11
L_12 ) ;
goto V_76;
}
if ( ! V_68 ) {
V_14 = F_39 ( V_67 , 0 ) ;
if ( V_14 ) {
F_40 ( V_14 ) ;
goto V_76;
}
V_14 = F_41 ( V_67 , 0 ) ;
if ( V_14 ) {
F_42 ( V_67 ) ;
if ( F_43 ( V_14 ) )
F_38 ( L_13 ) ;
}
} else {
V_14 = F_39 ( V_67 , 0 ) ;
if ( V_14 ) {
F_44 ( V_14 ) ;
F_40 ( V_14 ) ;
}
}
}
V_76:
F_33 ( & V_2 -> V_72 ) ;
}
static void F_45 ( T_3 V_78 , T_1 V_79 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
if ( V_79 != V_81 )
return;
F_20 ( V_2 -> V_82 , & V_2 -> V_83 ) ;
}
static int F_46 ( struct V_1 * V_2 , char * V_84 )
{
T_2 V_30 ;
T_3 V_78 ;
V_30 = F_47 ( NULL , V_84 , & V_78 ) ;
if ( F_48 ( V_30 ) ) {
V_30 = F_49 ( V_78 ,
V_85 ,
F_45 , V_2 ) ;
if ( F_11 ( V_30 ) )
F_36 ( L_14 , V_84 ) ;
} else
return - V_40 ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , char * V_84 )
{
T_2 V_30 = V_86 ;
T_3 V_78 ;
V_30 = F_47 ( NULL , V_84 , & V_78 ) ;
if ( F_48 ( V_30 ) ) {
V_30 = F_51 ( V_78 ,
V_85 ,
F_45 ) ;
if ( F_11 ( V_30 ) )
F_38 ( L_15 ,
V_84 ) ;
}
}
static int F_52 ( struct V_75 * V_75 ,
T_4 * V_37 )
{
struct V_1 * V_2 = V_75 -> V_87 ;
int V_63 = F_16 ( V_2 , V_64 ) ;
if ( V_63 < 0 )
return V_63 ;
* V_37 = ! ! V_63 ;
return 0 ;
}
static void F_53 ( struct V_75 * V_75 )
{
F_12 ( V_75 -> V_88 ) ;
F_12 ( V_75 ) ;
}
static void F_54 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_50 , struct V_1 , V_83 ) ;
F_31 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_89 = - V_5 ;
struct V_66 * V_67 = F_35 ( 0 , 1 ) ;
if ( ! V_67 ) {
F_38 ( L_16 ) ;
return - V_40 ;
}
V_2 -> V_82 =
F_24 ( L_17 ) ;
if ( ! V_2 -> V_82 )
goto V_90;
F_25 ( & V_2 -> V_83 , F_54 ) ;
V_2 -> V_75 = F_56 ( sizeof( struct V_75 ) , V_91 ) ;
if ( ! V_2 -> V_75 )
goto V_92;
V_2 -> V_75 -> V_88 = F_56 ( sizeof( struct V_93 ) ,
V_91 ) ;
if ( ! V_2 -> V_75 -> V_88 )
goto V_94;
V_2 -> V_75 -> V_87 = V_2 ;
V_2 -> V_75 -> V_95 = & F_53 ;
V_2 -> V_75 -> V_96 = & V_97 ;
F_52 ( V_2 -> V_75 ,
& V_2 -> V_75 -> V_88 -> V_98 ) ;
V_89 = F_57 ( V_2 -> V_75 , V_67 , 0 , L_18 ) ;
if ( V_89 ) {
F_38 ( L_19 , V_89 ) ;
goto V_99;
}
return 0 ;
V_99:
F_12 ( V_2 -> V_75 -> V_88 ) ;
V_94:
F_12 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
V_92:
F_27 ( V_2 -> V_82 ) ;
V_90:
return V_89 ;
}
static int F_58 ( void * V_80 , bool V_68 )
{
struct V_100 * V_101 = V_80 ;
T_1 V_43 = ! V_68 ;
return F_14 ( V_101 -> V_41 , V_43 , NULL ) ;
}
static void F_59 ( struct V_74 * V_74 , void * V_80 )
{
struct V_100 * V_101 = V_80 ;
int V_63 ;
V_63 = F_16 ( V_101 -> V_2 , V_101 -> V_41 ) ;
if ( V_63 < 0 )
return;
F_34 ( V_101 -> V_74 , ! V_63 ) ;
}
static int F_60 ( void * V_80 , bool V_68 )
{
struct V_100 * V_101 = V_80 ;
struct V_1 * V_2 = V_101 -> V_2 ;
int V_89 ;
F_32 ( & V_2 -> V_71 ) ;
V_89 = F_58 ( V_80 , V_68 ) ;
F_33 ( & V_2 -> V_71 ) ;
return V_89 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_100 * V_102 ,
const char * V_6 , enum V_103 type , int V_41 )
{
int V_63 = F_16 ( V_2 , V_41 ) ;
struct V_74 * * V_74 = & V_102 -> V_74 ;
if ( V_63 < 0 )
return V_63 ;
V_102 -> V_41 = V_41 ;
V_102 -> V_2 = V_2 ;
if ( V_41 == V_64 && V_2 -> V_7 -> V_104 )
* V_74 = F_62 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_105 , V_102 ) ;
else
* V_74 = F_62 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_106 , V_102 ) ;
if ( ! * V_74 )
return - V_107 ;
F_63 ( * V_74 , ! V_63 ) ;
V_63 = F_64 ( * V_74 ) ;
if ( V_63 ) {
F_65 ( * V_74 ) ;
* V_74 = NULL ;
return V_63 ;
}
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_50 ( V_2 , L_20 ) ;
F_50 ( V_2 , L_21 ) ;
F_50 ( V_2 , L_22 ) ;
if ( V_2 -> V_73 . V_74 ) {
F_67 ( V_2 -> V_73 . V_74 ) ;
F_65 ( V_2 -> V_73 . V_74 ) ;
V_2 -> V_73 . V_74 = NULL ;
}
F_31 ( V_2 ) ;
if ( V_2 -> V_75 )
F_68 ( V_2 -> V_75 ) ;
if ( V_2 -> V_82 )
F_27 ( V_2 -> V_82 ) ;
if ( V_2 -> V_108 . V_74 ) {
F_67 ( V_2 -> V_108 . V_74 ) ;
F_65 ( V_2 -> V_108 . V_74 ) ;
V_2 -> V_108 . V_74 = NULL ;
}
if ( V_2 -> V_109 . V_74 ) {
F_67 ( V_2 -> V_109 . V_74 ) ;
F_65 ( V_2 -> V_109 . V_74 ) ;
V_2 -> V_109 . V_74 = NULL ;
}
if ( V_2 -> V_110 . V_74 ) {
F_67 ( V_2 -> V_110 . V_74 ) ;
F_65 ( V_2 -> V_110 . V_74 ) ;
V_2 -> V_110 . V_74 = NULL ;
}
}
static int F_69 ( struct V_1 * V_2 )
{
int V_63 = 0 ;
F_70 ( & V_2 -> V_72 ) ;
F_70 ( & V_2 -> V_71 ) ;
V_63 = F_61 ( V_2 , & V_2 -> V_73 , L_23 ,
V_111 , V_64 ) ;
if ( V_63 && V_63 != - V_40 )
goto exit;
V_63 = F_61 ( V_2 , & V_2 -> V_108 ,
L_24 , V_112 ,
V_113 ) ;
if ( V_63 && V_63 != - V_40 )
goto exit;
V_63 = F_61 ( V_2 , & V_2 -> V_109 , L_25 ,
V_114 , V_115 ) ;
if ( V_63 && V_63 != - V_40 )
goto exit;
V_63 = F_61 ( V_2 , & V_2 -> V_110 , L_26 ,
V_116 , V_117 ) ;
if ( V_63 && V_63 != - V_40 )
goto exit;
if ( ! V_2 -> V_7 -> V_104 )
goto exit;
V_63 = F_55 ( V_2 ) ;
if ( V_63 == - V_118 )
V_63 = 0 ;
F_46 ( V_2 , L_20 ) ;
F_46 ( V_2 , L_21 ) ;
F_46 ( V_2 , L_22 ) ;
F_31 ( V_2 ) ;
exit:
if ( V_63 && V_63 != - V_40 )
F_66 ( V_2 ) ;
if ( V_63 == - V_40 )
V_63 = 0 ;
return V_63 ;
}
static T_5 F_71 ( struct V_119 * V_14 ,
struct V_120 * V_121 ,
char * V_122 )
{
struct V_1 * V_2 = F_72 ( V_14 ) ;
T_1 V_37 ;
int V_3 ;
V_3 = F_13 ( V_2 , V_123 , & V_37 ) ;
if ( V_3 < 0 )
return V_3 ;
V_37 |= 0xFF ;
if ( V_37 == 1 )
V_37 = 85 ;
else if ( V_37 == 2 )
V_37 = 170 ;
else if ( V_37 == 3 )
V_37 = 255 ;
else if ( V_37 != 0 ) {
F_38 ( L_27 , V_37 ) ;
V_37 = - 1 ;
}
return sprintf ( V_122 , L_28 , V_37 ) ;
}
static T_5
F_73 ( struct V_119 * V_14 , struct V_120 * V_121 , char * V_122 )
{
return sprintf ( V_122 , L_29 ) ;
}
static T_6 F_74 ( struct V_124 * V_125 ,
struct V_126 * V_121 , int V_127 )
{
struct V_119 * V_14 = F_18 ( V_125 , struct V_119 , V_125 ) ;
struct V_16 * V_128 = F_75 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_76 ( V_128 ) ;
bool V_129 = true ;
int V_41 = - 1 ;
T_1 V_37 = V_39 ;
if ( V_121 == & V_130 . V_131 . V_121 )
V_41 = V_123 ;
if ( V_41 != - 1 ) {
int V_3 = F_13 ( V_2 , V_41 , & V_37 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_41 == V_123 ) {
if ( V_37 != V_39 || V_37 & 0xFFF80000
|| ( ! V_2 -> V_132 && ! ( V_37 & V_46 ) ) )
V_129 = false ;
}
return V_129 ? V_121 -> V_133 : 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_119 * V_134 ;
V_134 = V_2 -> V_135 ;
if ( ! V_134 )
return;
F_78 ( & V_134 -> V_125 , & V_136 ) ;
F_79 ( V_134 ) ;
V_2 -> V_135 = NULL ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_119 * V_134 ;
int V_63 ;
V_134 = F_81 ( & V_2 -> V_16 -> V_14 ) ;
if ( F_82 ( V_134 ) ) {
F_38 ( L_30 ) ;
return F_83 ( V_134 ) ;
}
V_2 -> V_135 = V_134 ;
V_63 = F_84 ( & V_134 -> V_125 , & V_136 ) ;
if ( V_63 )
F_77 ( V_2 ) ;
return V_63 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_89 = F_16 ( V_2 , V_137 ) ;
if ( V_89 < 0 )
return V_89 ;
return V_89 ? V_138 : V_139 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_1 V_23 ;
int V_3 ;
V_3 = F_13 ( V_2 , V_140 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
V_23 = V_23 & V_141 ;
V_23 >>= 8 ;
if ( ! V_23 )
return - V_40 ;
return V_23 ;
}
static int F_87 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_88 ( V_143 ) ;
T_1 V_23 ;
int V_3 ;
V_3 = F_13 ( V_2 , V_140 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_23 & V_144 ;
}
static int F_89 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_88 ( V_143 ) ;
T_1 V_43 ;
int V_145 , V_3 ;
V_43 = V_143 -> V_146 . V_147 ;
V_3 = F_14 ( V_140 ,
V_43 , NULL ) ;
if ( V_3 < 0 )
return V_3 ;
V_145 = F_85 ( V_2 ) ;
if ( V_145 != - V_40 && V_143 -> V_146 . V_145 != V_145 ) {
V_43 = ! ! ( V_143 -> V_146 . V_145 == V_138 ) ;
V_3 = F_14 ( V_137 ,
V_43 , NULL ) ;
}
return V_3 ;
}
static int F_90 ( struct V_1 * V_2 , int V_148 )
{
struct V_142 * V_143 = V_2 -> V_142 ;
int V_149 = V_143 -> V_146 . V_147 ;
int V_150 = V_149 ;
if ( V_148 >= V_151 && V_148 <= V_152 )
V_150 = V_148 - V_151 + 1 ;
else if ( V_148 >= V_153 && V_148 <= V_154 )
V_150 = V_148 - V_153 ;
V_143 -> V_146 . V_147 = V_150 ;
F_91 ( V_143 ) ;
F_92 ( V_143 , V_155 ) ;
return V_149 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_142 * V_143 ;
struct V_156 V_146 ;
int V_157 ;
int V_145 ;
V_157 = F_86 ( V_2 ) ;
if ( V_157 == - V_40 )
V_157 = 0 ;
else if ( V_157 < 0 )
return V_157 ;
V_145 = F_85 ( V_2 ) ;
if ( V_145 == - V_40 )
V_145 = V_138 ;
else if ( V_145 < 0 )
return V_145 ;
memset ( & V_146 , 0 , sizeof( struct V_156 ) ) ;
V_146 . type = V_158 ;
V_146 . V_62 = V_157 ;
V_143 = F_94 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_159 , & V_146 ) ;
if ( F_82 ( V_143 ) ) {
F_38 ( L_31 ) ;
return F_83 ( V_143 ) ;
}
V_2 -> V_142 = V_143 ;
V_143 -> V_146 . V_147 = F_87 ( V_143 ) ;
V_143 -> V_146 . V_145 = V_145 ;
F_91 ( V_143 ) ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( V_2 -> V_142 )
F_96 ( V_2 -> V_142 ) ;
V_2 -> V_142 = NULL ;
}
static void F_97 ( T_1 V_37 , void * V_160 )
{
struct V_1 * V_2 = V_160 ;
struct V_25 V_161 = { V_29 , NULL } ;
union V_31 * V_32 ;
T_2 V_30 ;
int V_148 ;
int V_162 ;
V_30 = F_98 ( V_37 , & V_161 ) ;
if ( V_30 != V_86 ) {
F_38 ( L_32 , V_30 ) ;
return;
}
V_32 = (union V_31 * ) V_161 . V_35 ;
if ( ! V_32 || V_32 -> type != V_36 )
goto exit;
V_148 = V_32 -> integer . V_37 ;
V_162 = V_148 ;
if ( V_148 >= V_151 && V_148 <= V_152 )
V_148 = V_151 ;
else if ( V_148 >= V_153 &&
V_148 <= V_154 )
V_148 = V_153 ;
if ( V_148 == V_151 || V_148 == V_153 ) {
if ( ! F_99 () )
F_90 ( V_2 , V_162 ) ;
} else if ( ! F_100 ( V_2 -> V_4 , V_148 , 1 , true ) )
F_101 ( L_33 , V_148 ) ;
exit:
F_12 ( V_32 ) ;
}
static int F_102 ( const char * V_122 , unsigned long V_163 , int * V_164 )
{
if ( ! V_163 )
return 0 ;
if ( sscanf ( V_122 , L_34 , V_164 ) != 1 )
return - V_107 ;
return V_163 ;
}
static T_5 F_103 ( struct V_1 * V_2 , int V_165 ,
const char * V_122 , T_7 V_163 )
{
T_1 V_23 ;
int V_59 , V_3 , V_37 ;
V_37 = F_16 ( V_2 , V_165 ) ;
if ( V_37 == - V_40 )
return V_37 ;
V_59 = F_102 ( V_122 , V_163 , & V_37 ) ;
V_3 = F_14 ( V_165 , V_37 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_59 ;
}
static T_5 F_104 ( struct V_1 * V_2 , int V_165 , char * V_122 )
{
int V_37 = F_16 ( V_2 , V_165 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_122 , L_28 , V_37 ) ;
}
static T_5 F_105 ( struct V_119 * V_14 , struct V_120 * V_121 ,
const char * V_122 , T_7 V_163 )
{
int V_37 ;
if ( ! V_163 || sscanf ( V_122 , L_34 , & V_37 ) != 1 )
return - V_107 ;
if ( V_37 < 0 || V_37 > 2 )
return - V_107 ;
return F_9 ( V_166 , V_37 , 0 , NULL ) ;
}
static T_6 F_106 ( struct V_124 * V_125 ,
struct V_126 * V_121 , int V_127 )
{
struct V_119 * V_14 = F_18 ( V_125 , struct V_119 , V_125 ) ;
struct V_16 * V_128 = F_75 ( V_14 ) ;
struct V_1 * V_2 = F_76 ( V_128 ) ;
bool V_129 = true ;
int V_165 = - 1 ;
if ( V_121 == & V_167 . V_121 )
V_165 = V_168 ;
else if ( V_121 == & V_169 . V_121 )
V_165 = V_170 ;
else if ( V_121 == & V_171 . V_121 )
V_165 = V_172 ;
if ( V_165 != - 1 )
V_129 = ! ( F_16 ( V_2 , V_165 ) < 0 ) ;
return V_129 ? V_121 -> V_133 : 0 ;
}
static void F_107 ( struct V_16 * V_119 )
{
F_78 ( & V_119 -> V_14 . V_125 , & V_173 ) ;
}
static int F_108 ( struct V_16 * V_119 )
{
return F_84 ( & V_119 -> V_14 . V_125 , & V_173 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_59 ;
if ( ! F_9 ( V_174 , 0 , 0 , & V_59 ) )
F_101 ( L_35 , V_59 ) ;
if ( ! F_9 ( V_175 , 0 , 0x9 , & V_59 ) ) {
F_101 ( L_36 , V_59 >> 8 , V_59 & 0xFF ) ;
V_2 -> V_176 = V_59 ;
}
if ( ! F_9 ( V_177 , 0 , 0 , & V_59 ) ) {
F_101 ( L_37 , V_59 ) ;
V_2 -> V_132 = V_59 ;
}
if ( ! F_9 ( V_178 , 0 , 0 , NULL ) )
V_2 -> V_42 = V_178 ;
else if ( ! F_9 ( V_179 , 0 , 0 , NULL ) )
V_2 -> V_42 = V_179 ;
if ( ! V_2 -> V_42 ) {
F_38 ( L_38 ) ;
return - V_40 ;
}
return F_108 ( V_2 -> V_16 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_107 ( V_2 -> V_16 ) ;
}
static int F_111 ( struct V_180 * V_181 , void * V_80 )
{
struct V_1 * V_2 = V_181 -> V_87 ;
int V_3 ;
T_1 V_23 = - 1 ;
V_3 = F_13 ( V_2 , V_2 -> V_182 . V_41 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
F_112 ( V_181 , L_39 , V_2 -> V_182 . V_41 , V_23 ) ;
return 0 ;
}
static int F_113 ( struct V_180 * V_181 , void * V_80 )
{
struct V_1 * V_2 = V_181 -> V_87 ;
int V_3 ;
T_1 V_23 = - 1 ;
V_3 = F_14 ( V_2 -> V_182 . V_41 , V_2 -> V_182 . V_43 ,
& V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
F_112 ( V_181 , L_40 , V_2 -> V_182 . V_41 ,
V_2 -> V_182 . V_43 , V_23 ) ;
return 0 ;
}
static int F_114 ( struct V_180 * V_181 , void * V_80 )
{
struct V_1 * V_2 = V_181 -> V_87 ;
struct V_24 args = {
. V_21 = V_2 -> V_182 . V_41 ,
. V_22 = V_2 -> V_182 . V_43 ,
} ;
struct V_25 V_26 = { ( V_27 ) sizeof( args ) , & args } ;
struct V_25 V_28 = { V_29 , NULL } ;
union V_31 * V_32 ;
T_2 V_30 ;
V_30 = F_10 ( V_34 ,
1 , V_2 -> V_182 . V_20 ,
& V_26 , & V_28 ) ;
if ( F_11 ( V_30 ) )
return - V_38 ;
V_32 = (union V_31 * ) V_28 . V_35 ;
if ( V_32 && V_32 -> type == V_36 )
F_112 ( V_181 , L_41 , V_2 -> V_182 . V_20 ,
V_2 -> V_182 . V_41 , V_2 -> V_182 . V_43 ,
( T_1 ) V_32 -> integer . V_37 ) ;
else
F_112 ( V_181 , L_42 , V_2 -> V_182 . V_20 ,
V_2 -> V_182 . V_41 , V_2 -> V_182 . V_43 ,
V_32 ? V_32 -> type : - 1 ) ;
F_12 ( V_32 ) ;
return 0 ;
}
static int F_115 ( struct V_183 * V_183 , struct V_184 * V_184 )
{
struct V_185 * V_84 = V_183 -> V_186 ;
return F_116 ( V_184 , V_84 -> V_187 , V_84 -> V_2 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_118 ( V_2 -> V_182 . V_188 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_189 * V_190 ;
int V_191 ;
V_2 -> V_182 . V_188 = F_120 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_182 . V_188 ) {
F_38 ( L_43 ) ;
goto V_192;
}
V_190 = F_121 ( L_44 , V_193 | V_194 ,
V_2 -> V_182 . V_188 , & V_2 -> V_182 . V_20 ) ;
if ( ! V_190 )
goto V_192;
V_190 = F_121 ( L_45 , V_193 | V_194 ,
V_2 -> V_182 . V_188 , & V_2 -> V_182 . V_41 ) ;
if ( ! V_190 )
goto V_192;
V_190 = F_121 ( L_46 , V_193 | V_194 ,
V_2 -> V_182 . V_188 , & V_2 -> V_182 . V_43 ) ;
if ( ! V_190 )
goto V_192;
for ( V_191 = 0 ; V_191 < F_122 ( V_195 ) ; V_191 ++ ) {
struct V_185 * V_84 = & V_195 [ V_191 ] ;
V_84 -> V_2 = V_2 ;
V_190 = F_123 ( V_84 -> V_6 , V_196 | V_193 ,
V_2 -> V_182 . V_188 , V_84 ,
& V_197 ) ;
if ( ! V_190 ) {
F_38 ( L_47 , V_84 -> V_6 ) ;
goto V_192;
}
}
return 0 ;
V_192:
F_117 ( V_2 ) ;
return - V_5 ;
}
static int F_124 ( struct V_16 * V_128 )
{
struct V_198 * V_199 = F_125 ( V_128 -> V_14 . V_7 ) ;
struct V_200 * V_201 = F_126 ( V_199 ) ;
struct V_1 * V_2 ;
T_2 V_30 ;
int V_3 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_91 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_201 ;
V_2 -> V_16 = V_128 ;
V_201 -> V_16 = V_128 ;
F_127 ( V_2 -> V_16 , V_2 ) ;
if ( V_201 -> V_202 )
V_201 -> V_202 ( V_2 -> V_7 ) ;
V_3 = F_109 ( V_2 ) ;
if ( V_3 )
goto V_203;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_204;
V_3 = F_80 ( V_2 ) ;
if ( V_3 )
goto V_205;
V_3 = F_23 ( V_2 ) ;
if ( V_3 )
goto V_206;
V_3 = F_69 ( V_2 ) ;
if ( V_3 )
goto V_207;
if ( ! F_99 () ) {
V_3 = F_93 ( V_2 ) ;
if ( V_3 && V_3 != - V_40 )
goto V_208;
} else
F_101 ( L_48 ) ;
V_30 = F_128 ( V_2 -> V_7 -> V_209 ,
F_97 , V_2 ) ;
if ( F_11 ( V_30 ) ) {
F_38 ( L_49 , V_30 ) ;
V_3 = - V_40 ;
goto V_210;
}
V_3 = F_119 ( V_2 ) ;
if ( V_3 )
goto V_211;
return 0 ;
V_211:
F_129 ( V_2 -> V_7 -> V_209 ) ;
V_210:
F_95 ( V_2 ) ;
V_208:
F_66 ( V_2 ) ;
V_207:
F_28 ( V_2 ) ;
V_206:
F_77 ( V_2 ) ;
V_205:
F_7 ( V_2 ) ;
V_204:
F_110 ( V_2 ) ;
V_203:
F_12 ( V_2 ) ;
return V_3 ;
}
static int F_130 ( struct V_16 * V_119 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_119 ) ;
F_129 ( V_2 -> V_7 -> V_209 ) ;
F_95 ( V_2 ) ;
F_7 ( V_2 ) ;
F_77 ( V_2 ) ;
F_28 ( V_2 ) ;
F_66 ( V_2 ) ;
F_117 ( V_2 ) ;
F_110 ( V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_131 ( struct V_119 * V_119 )
{
struct V_1 * V_2 = F_72 ( V_119 ) ;
if ( V_2 -> V_73 . V_74 ) {
bool V_73 ;
V_73 = F_16 ( V_2 , V_64 ) ;
F_14 ( V_64 , V_73 , NULL ) ;
}
return 0 ;
}
static int F_132 ( struct V_119 * V_119 )
{
struct V_1 * V_2 = F_72 ( V_119 ) ;
int V_212 ;
if ( V_2 -> V_73 . V_74 )
F_31 ( V_2 ) ;
if ( V_2 -> V_108 . V_74 ) {
V_212 = ! F_16 ( V_2 ,
V_113 ) ;
F_34 ( V_2 -> V_108 . V_74 , V_212 ) ;
}
if ( V_2 -> V_109 . V_74 ) {
V_212 = ! F_16 ( V_2 , V_115 ) ;
F_34 ( V_2 -> V_109 . V_74 , V_212 ) ;
}
if ( V_2 -> V_110 . V_74 ) {
V_212 = ! F_16 ( V_2 , V_117 ) ;
F_34 ( V_2 -> V_110 . V_74 , V_212 ) ;
}
return 0 ;
}
static int F_133 ( struct V_16 * V_128 )
{
struct V_198 * V_199 = F_125 ( V_128 -> V_14 . V_7 ) ;
struct V_200 * V_201 = F_126 ( V_199 ) ;
int V_89 ;
if ( ! F_134 ( V_34 ) ) {
F_36 ( L_50 ) ;
return - V_40 ;
}
if ( V_201 -> V_209 && ! F_134 ( V_201 -> V_209 ) ) {
F_36 ( L_51 ) ;
return - V_40 ;
}
if ( V_201 -> V_213 ) {
V_89 = V_201 -> V_213 ( V_128 ) ;
if ( V_89 )
return V_89 ;
}
return F_124 ( V_128 ) ;
}
int F_135 ( struct V_200 * V_7 )
{
struct V_198 * V_198 ;
struct V_16 * V_16 ;
if ( V_214 )
return - V_118 ;
V_198 = & V_7 -> V_198 ;
V_198 -> remove = F_130 ;
V_198 -> V_7 . V_215 = V_7 -> V_215 ;
V_198 -> V_7 . V_6 = V_7 -> V_6 ;
V_198 -> V_7 . V_216 = & V_217 ;
V_16 = F_136 ( V_198 ,
F_133 ,
NULL , 0 , NULL , 0 ) ;
if ( F_82 ( V_16 ) )
return F_83 ( V_16 ) ;
V_214 = true ;
return 0 ;
}
void F_137 ( struct V_200 * V_7 )
{
F_138 ( V_7 -> V_16 ) ;
F_139 ( & V_7 -> V_198 ) ;
V_214 = false ;
}
static int T_8 F_140 ( void )
{
if ( ! F_134 ( V_34 ) ) {
F_101 ( L_52 ) ;
return - V_40 ;
}
F_101 ( L_53 ) ;
return 0 ;
}
static void T_9 F_141 ( void )
{
F_101 ( L_54 ) ;
}
