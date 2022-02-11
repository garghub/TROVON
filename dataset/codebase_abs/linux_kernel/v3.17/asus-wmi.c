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
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_68 ;
F_14 ( V_2 , V_69 , & V_68 ) ;
return V_68 & V_50 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_68 ;
F_14 ( V_2 , V_69 , & V_68 ) ;
return V_68 & V_48 ;
}
static void F_30 ( struct V_51 * V_52 )
{
int V_45 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_52 , struct V_1 , V_70 ) ;
V_45 = V_2 -> V_71 ;
F_15 ( V_69 , V_45 , NULL ) ;
}
static void F_31 ( struct V_56 * V_57 ,
enum V_58 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_57 , struct V_1 , V_72 ) ;
V_2 -> V_71 = ! ! V_39 ;
F_21 ( V_2 -> V_60 , & V_2 -> V_70 ) ;
}
static enum V_58 F_32 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
T_1 V_68 ;
V_2 = F_19 ( V_57 , struct V_1 , V_72 ) ;
F_14 ( V_2 , V_69 , & V_68 ) ;
return V_68 & V_73 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( ! F_34 ( V_2 -> V_66 . V_14 ) )
F_35 ( & V_2 -> V_66 ) ;
if ( ! F_34 ( V_2 -> V_59 . V_14 ) )
F_35 ( & V_2 -> V_59 ) ;
if ( ! F_34 ( V_2 -> V_72 . V_14 ) )
F_35 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_60 )
F_36 ( V_2 -> V_60 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_74 = 0 ;
V_2 -> V_60 = F_38 ( L_1 ) ;
if ( ! V_2 -> V_60 )
return - V_5 ;
if ( F_22 ( V_2 ) >= 0 ) {
F_39 ( & V_2 -> V_53 , F_18 ) ;
V_2 -> V_59 . V_6 = L_2 ;
V_2 -> V_59 . V_75 = F_20 ;
V_2 -> V_59 . V_76 = F_23 ;
V_2 -> V_59 . V_67 = 1 ;
V_74 = F_40 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_59 ) ;
if ( V_74 )
goto error;
}
if ( F_25 ( V_2 , NULL , NULL ) >= 0 ) {
F_39 ( & V_2 -> V_61 , F_24 ) ;
V_2 -> V_66 . V_6 = L_3 ;
V_2 -> V_66 . V_75 = F_26 ;
V_2 -> V_66 . V_76 = F_27 ;
V_2 -> V_66 . V_67 = 3 ;
V_74 = F_40 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_66 ) ;
if ( V_74 )
goto error;
}
if ( F_29 ( V_2 ) && ( V_2 -> V_7 -> V_77 -> V_78 > 0 ) ) {
F_39 ( & V_2 -> V_70 , F_30 ) ;
V_2 -> V_72 . V_6 = L_4 ;
V_2 -> V_72 . V_75 = F_31 ;
if ( ! F_28 ( V_2 ) )
V_2 -> V_72 . V_76 = F_32 ;
V_2 -> V_72 . V_79 = V_80 ;
V_2 -> V_72 . V_67 = 1 ;
V_2 -> V_72 . V_81 = L_5 ;
V_74 = F_40 ( & V_2 -> V_16 -> V_14 ,
& V_2 -> V_72 ) ;
}
error:
if ( V_74 )
F_33 ( V_2 ) ;
return V_74 ;
}
static bool F_41 ( struct V_1 * V_2 )
{
int V_68 = F_17 ( V_2 , V_82 ) ;
if ( V_68 < 0 )
return false ;
return ! V_68 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_83 * V_14 ;
struct V_84 * V_85 ;
bool V_86 ;
bool V_87 ;
T_1 V_88 ;
F_43 ( & V_2 -> V_89 ) ;
V_86 = F_41 ( V_2 ) ;
F_44 ( & V_2 -> V_89 ) ;
F_43 ( & V_2 -> V_90 ) ;
F_45 () ;
if ( V_2 -> V_91 . V_92 )
F_46 ( V_2 -> V_91 . V_92 , V_86 ) ;
if ( V_2 -> V_93 ) {
V_85 = F_47 ( 0 , 1 ) ;
if ( ! V_85 ) {
F_48 ( L_6 ) ;
goto V_94;
}
if ( F_49 ( V_85 , 0 , V_95 , & V_88 ) ) {
F_50 ( L_7 ) ;
goto V_94;
}
V_87 = ( V_88 == 0xffffffff ) ;
if ( V_86 != V_87 ) {
F_48 ( L_8
L_9 ,
V_86 ? L_10 : L_11 ,
V_87 ? L_12 : L_13 ) ;
F_48 ( L_14
L_15 ) ;
goto V_94;
}
if ( ! V_86 ) {
V_14 = F_51 ( V_85 , 0 ) ;
if ( V_14 ) {
F_52 ( V_14 ) ;
goto V_94;
}
V_14 = F_53 ( V_85 , 0 ) ;
if ( V_14 ) {
F_54 ( V_85 ) ;
F_55 ( V_14 ) ;
}
} else {
V_14 = F_51 ( V_85 , 0 ) ;
if ( V_14 ) {
F_56 ( V_14 ) ;
F_52 ( V_14 ) ;
}
}
}
V_94:
F_57 () ;
F_44 ( & V_2 -> V_90 ) ;
}
static void F_58 ( T_3 V_96 , T_1 V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
if ( V_97 != V_99 )
return;
F_21 ( V_2 -> V_100 , & V_2 -> V_101 ) ;
}
static int F_59 ( struct V_1 * V_2 , char * V_102 )
{
T_2 V_32 ;
T_3 V_96 ;
V_32 = F_60 ( NULL , V_102 , & V_96 ) ;
if ( F_61 ( V_32 ) ) {
V_32 = F_62 ( V_96 ,
V_103 ,
F_58 , V_2 ) ;
if ( F_12 ( V_32 ) )
F_48 ( L_16 , V_102 ) ;
} else
return - V_42 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , char * V_102 )
{
T_2 V_32 = V_104 ;
T_3 V_96 ;
V_32 = F_60 ( NULL , V_102 , & V_96 ) ;
if ( F_61 ( V_32 ) ) {
V_32 = F_64 ( V_96 ,
V_103 ,
F_58 ) ;
if ( F_12 ( V_32 ) )
F_50 ( L_17 ,
V_102 ) ;
}
}
static int F_65 ( struct V_93 * V_93 ,
T_4 * V_39 )
{
struct V_1 * V_2 = V_93 -> V_105 ;
int V_68 = F_17 ( V_2 , V_82 ) ;
if ( V_68 < 0 )
return V_68 ;
* V_39 = ! ! V_68 ;
return 0 ;
}
static void F_66 ( struct V_93 * V_93 )
{
F_13 ( V_93 -> V_106 ) ;
F_13 ( V_93 ) ;
}
static void F_67 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_52 , struct V_1 , V_101 ) ;
F_42 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_107 = - V_5 ;
struct V_84 * V_85 = F_47 ( 0 , 1 ) ;
if ( ! V_85 ) {
F_50 ( L_18 ) ;
return - V_42 ;
}
V_2 -> V_100 =
F_38 ( L_19 ) ;
if ( ! V_2 -> V_100 )
goto V_108;
F_39 ( & V_2 -> V_101 , F_67 ) ;
V_2 -> V_93 = F_69 ( sizeof( struct V_93 ) , V_109 ) ;
if ( ! V_2 -> V_93 )
goto V_110;
V_2 -> V_93 -> V_106 = F_69 ( sizeof( struct V_111 ) ,
V_109 ) ;
if ( ! V_2 -> V_93 -> V_106 )
goto V_112;
V_2 -> V_93 -> V_105 = V_2 ;
V_2 -> V_93 -> V_113 = & F_66 ;
V_2 -> V_93 -> V_114 = & V_115 ;
F_65 ( V_2 -> V_93 ,
& V_2 -> V_93 -> V_106 -> V_116 ) ;
V_107 = F_70 ( V_2 -> V_93 , V_85 , 0 , L_20 ) ;
if ( V_107 ) {
F_50 ( L_21 , V_107 ) ;
goto V_117;
}
return 0 ;
V_117:
F_13 ( V_2 -> V_93 -> V_106 ) ;
V_112:
F_13 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
V_110:
F_36 ( V_2 -> V_100 ) ;
V_108:
return V_107 ;
}
static int F_71 ( void * V_98 , bool V_86 )
{
struct V_118 * V_119 = V_98 ;
T_1 V_45 = ! V_86 ;
T_1 V_43 = V_119 -> V_43 ;
if ( ( V_43 == V_82 ) &&
V_119 -> V_2 -> V_7 -> V_120 )
V_43 = V_121 ;
return F_15 ( V_43 , V_45 , NULL ) ;
}
static void F_72 ( struct V_92 * V_92 , void * V_98 )
{
struct V_118 * V_119 = V_98 ;
int V_68 ;
V_68 = F_17 ( V_119 -> V_2 , V_119 -> V_43 ) ;
if ( V_68 < 0 )
return;
F_46 ( V_119 -> V_92 , ! V_68 ) ;
}
static int F_73 ( void * V_98 , bool V_86 )
{
struct V_118 * V_119 = V_98 ;
struct V_1 * V_2 = V_119 -> V_2 ;
int V_107 ;
F_43 ( & V_2 -> V_89 ) ;
V_107 = F_71 ( V_98 , V_86 ) ;
F_44 ( & V_2 -> V_89 ) ;
return V_107 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_118 * V_122 ,
const char * V_6 , enum V_123 type , int V_43 )
{
int V_68 = F_17 ( V_2 , V_43 ) ;
struct V_92 * * V_92 = & V_122 -> V_92 ;
if ( V_68 < 0 )
return V_68 ;
V_122 -> V_43 = V_43 ;
V_122 -> V_2 = V_2 ;
if ( V_43 == V_82 &&
V_2 -> V_7 -> V_77 -> V_124 )
* V_92 = F_75 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_125 , V_122 ) ;
else
* V_92 = F_75 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_126 , V_122 ) ;
if ( ! * V_92 )
return - V_127 ;
if ( ( V_43 == V_82 ) &&
( V_2 -> V_7 -> V_77 -> V_78 > 0 ) )
F_76 ( * V_92 , L_5 ) ;
F_77 ( * V_92 , ! V_68 ) ;
V_68 = F_78 ( * V_92 ) ;
if ( V_68 ) {
F_79 ( * V_92 ) ;
* V_92 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_63 ( V_2 , L_22 ) ;
F_63 ( V_2 , L_23 ) ;
F_63 ( V_2 , L_24 ) ;
if ( V_2 -> V_91 . V_92 ) {
F_81 ( V_2 -> V_91 . V_92 ) ;
F_79 ( V_2 -> V_91 . V_92 ) ;
V_2 -> V_91 . V_92 = NULL ;
}
F_42 ( V_2 ) ;
if ( V_2 -> V_93 )
F_82 ( V_2 -> V_93 ) ;
if ( V_2 -> V_100 )
F_36 ( V_2 -> V_100 ) ;
if ( V_2 -> V_128 . V_92 ) {
F_81 ( V_2 -> V_128 . V_92 ) ;
F_79 ( V_2 -> V_128 . V_92 ) ;
V_2 -> V_128 . V_92 = NULL ;
}
if ( V_2 -> V_129 . V_92 ) {
F_81 ( V_2 -> V_129 . V_92 ) ;
F_79 ( V_2 -> V_129 . V_92 ) ;
V_2 -> V_129 . V_92 = NULL ;
}
if ( V_2 -> V_130 . V_92 ) {
F_81 ( V_2 -> V_130 . V_92 ) ;
F_79 ( V_2 -> V_130 . V_92 ) ;
V_2 -> V_130 . V_92 = NULL ;
}
if ( V_2 -> V_131 . V_92 ) {
F_81 ( V_2 -> V_131 . V_92 ) ;
F_79 ( V_2 -> V_131 . V_92 ) ;
V_2 -> V_131 . V_92 = NULL ;
}
if ( V_2 -> V_132 . V_92 ) {
F_81 ( V_2 -> V_132 . V_92 ) ;
F_79 ( V_2 -> V_132 . V_92 ) ;
V_2 -> V_132 . V_92 = NULL ;
}
}
static int F_83 ( struct V_1 * V_2 )
{
int V_68 = 0 ;
F_84 ( & V_2 -> V_90 ) ;
F_84 ( & V_2 -> V_89 ) ;
V_68 = F_74 ( V_2 , & V_2 -> V_91 , L_5 ,
V_133 , V_82 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_74 ( V_2 , & V_2 -> V_128 ,
L_25 , V_134 ,
V_135 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_74 ( V_2 , & V_2 -> V_129 , L_26 ,
V_136 , V_137 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_74 ( V_2 , & V_2 -> V_130 , L_27 ,
V_138 , V_139 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_74 ( V_2 , & V_2 -> V_131 , L_28 ,
V_140 , V_141 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_74 ( V_2 , & V_2 -> V_132 , L_29 ,
V_142 , V_143 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
if ( ! V_2 -> V_7 -> V_77 -> V_124 )
goto exit;
V_68 = F_68 ( V_2 ) ;
if ( V_68 == - V_144 )
V_68 = 0 ;
F_59 ( V_2 , L_22 ) ;
F_59 ( V_2 , L_23 ) ;
F_59 ( V_2 , L_24 ) ;
F_42 ( V_2 ) ;
exit:
if ( V_68 && V_68 != - V_42 )
F_80 ( V_2 ) ;
if ( V_68 == - V_42 )
V_68 = 0 ;
return V_68 ;
}
static T_5 F_85 ( struct V_145 * V_14 ,
struct V_146 * V_147 ,
char * V_148 )
{
struct V_1 * V_2 = F_86 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_149 , & V_39 ) ;
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
F_50 ( L_30 , V_39 ) ;
V_39 = - 1 ;
}
return sprintf ( V_148 , L_31 , V_39 ) ;
}
static T_5 F_87 ( struct V_145 * V_14 ,
struct V_146 * V_147 ,
char * V_148 )
{
struct V_1 * V_2 = F_86 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_150 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_88 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_148 , L_31 , V_39 ) ;
}
static T_6 F_89 ( struct V_151 * V_152 ,
struct V_153 * V_147 , int V_154 )
{
struct V_145 * V_14 = F_19 ( V_152 , struct V_145 , V_152 ) ;
struct V_16 * V_155 = F_90 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_91 ( V_155 ) ;
bool V_156 = true ;
int V_43 = - 1 ;
T_1 V_39 = V_41 ;
if ( V_147 == & V_157 . V_147 )
V_43 = V_149 ;
else if ( V_147 == & V_158 . V_147 )
V_43 = V_150 ;
if ( V_43 != - 1 ) {
int V_3 = F_14 ( V_2 , V_43 , & V_39 ) ;
if ( V_3 < 0 )
return 0 ;
}
if ( V_43 == V_149 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_159 && ! ( V_39 & V_48 ) ) )
V_156 = false ;
} else if ( V_43 == V_150 ) {
if ( V_39 == 0 )
V_156 = false ;
}
return V_156 ? V_147 -> V_160 : 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_145 * V_161 ;
V_161 = F_93 ( & V_2 -> V_16 -> V_14 ,
L_32 , V_2 ,
V_162 ) ;
if ( F_94 ( V_161 ) ) {
F_50 ( L_33 ) ;
return F_95 ( V_161 ) ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_107 ;
if ( V_2 -> V_7 -> V_77 -> V_163 )
V_107 = ! V_2 -> V_7 -> V_164 ;
else
V_107 = F_17 ( V_2 ,
V_165 ) ;
if ( V_107 < 0 )
return V_107 ;
return V_107 ? V_166 : V_167 ;
}
static int F_97 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_168 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_169 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_98 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_99 ( V_171 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_168 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_73 ;
}
static T_1 F_100 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_99 ( V_171 ) ;
T_1 V_45 = 0 ;
if ( ( V_2 -> V_7 -> V_172 < V_171 -> V_173 . V_172 ) ||
V_171 -> V_173 . V_172 == V_171 -> V_173 . V_67 )
V_45 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_172 > V_171 -> V_173 . V_172 ) ||
V_171 -> V_173 . V_172 == 0 )
V_45 = 0x00008000 ;
V_2 -> V_7 -> V_172 = V_171 -> V_173 . V_172 ;
return V_45 ;
}
static int F_101 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_99 ( V_171 ) ;
T_1 V_45 ;
int V_174 , V_3 = 0 ;
V_174 = F_96 ( V_2 ) ;
if ( V_174 != - V_42 && V_171 -> V_173 . V_174 != V_174 ) {
V_45 = ! ! ( V_171 -> V_173 . V_174 == V_166 ) ;
V_3 = F_15 ( V_165 ,
V_45 , NULL ) ;
if ( V_2 -> V_7 -> V_77 -> V_163 )
V_2 -> V_7 -> V_164 = V_171 -> V_173 . V_174 ;
if ( V_2 -> V_7 -> V_77 -> V_175 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_77 -> V_175 )
V_45 = F_100 ( V_171 ) ;
else
V_45 = V_171 -> V_173 . V_172 ;
V_3 = F_15 ( V_168 ,
V_45 , NULL ) ;
return V_3 ;
}
static int F_102 ( struct V_1 * V_2 , int V_176 )
{
struct V_170 * V_171 = V_2 -> V_170 ;
int V_177 = V_171 -> V_173 . V_172 ;
int V_178 = V_177 ;
if ( V_176 >= V_179 && V_176 <= V_180 )
V_178 = V_176 - V_179 + 1 ;
else if ( V_176 >= V_181 && V_176 <= V_182 )
V_178 = V_176 - V_181 ;
V_171 -> V_173 . V_172 = V_178 ;
F_103 ( V_171 ) ;
F_104 ( V_171 , V_183 ) ;
return V_177 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_170 * V_171 ;
struct V_184 V_173 ;
int V_185 ;
int V_174 ;
V_185 = F_97 ( V_2 ) ;
if ( V_185 < 0 )
return V_185 ;
V_174 = F_96 ( V_2 ) ;
if ( V_174 == - V_42 )
V_174 = V_166 ;
else if ( V_174 < 0 )
return V_174 ;
memset ( & V_173 , 0 , sizeof( struct V_184 ) ) ;
V_173 . type = V_186 ;
V_173 . V_67 = V_185 ;
V_171 = F_106 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_187 , & V_173 ) ;
if ( F_94 ( V_171 ) ) {
F_50 ( L_34 ) ;
return F_95 ( V_171 ) ;
}
V_2 -> V_170 = V_171 ;
if ( V_2 -> V_7 -> V_77 -> V_163 )
V_2 -> V_7 -> V_164 = V_174 ;
V_171 -> V_173 . V_172 = F_98 ( V_171 ) ;
V_171 -> V_173 . V_174 = V_174 ;
F_103 ( V_171 ) ;
V_2 -> V_7 -> V_172 = V_171 -> V_173 . V_172 ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
if ( V_2 -> V_170 )
F_108 ( V_2 -> V_170 ) ;
V_2 -> V_170 = NULL ;
}
static int F_109 ( int V_176 )
{
if ( ( V_176 >= 0x61 && V_176 <= 0x67 ) ||
( V_176 >= 0x8c && V_176 <= 0x93 ) ||
( V_176 >= 0xa0 && V_176 <= 0xa7 ) ||
( V_176 >= 0xd0 && V_176 <= 0xd5 ) )
return 1 ;
return 0 ;
}
static void F_110 ( T_1 V_39 , void * V_188 )
{
struct V_1 * V_2 = V_188 ;
struct V_27 V_189 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_176 ;
int V_190 ;
unsigned int V_191 = 1 ;
bool V_192 = 1 ;
V_32 = F_111 ( V_39 , & V_189 ) ;
if ( V_32 != V_104 ) {
F_50 ( L_35 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_189 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_176 = V_34 -> integer . V_39 ;
V_190 = V_176 ;
if ( V_2 -> V_7 -> V_193 ) {
V_2 -> V_7 -> V_193 ( V_2 -> V_7 , & V_176 , & V_191 ,
& V_192 ) ;
if ( V_176 == V_194 )
goto exit;
}
if ( V_176 >= V_179 && V_176 <= V_180 )
V_176 = V_195 ;
else if ( V_176 >= V_181 &&
V_176 <= V_182 )
V_176 = V_196 ;
if ( V_176 == V_196 || V_176 == V_195 ) {
if ( ! F_112 () ) {
F_102 ( V_2 , V_190 ) ;
goto exit;
}
}
if ( F_109 ( V_176 ) &&
V_2 -> V_7 -> V_77 -> V_197 )
goto exit;
if ( ! F_113 ( V_2 -> V_4 , V_176 ,
V_191 , V_192 ) )
F_114 ( L_36 , V_176 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_115 ( const char * V_148 , unsigned long V_198 , int * V_199 )
{
if ( ! V_198 )
return 0 ;
if ( sscanf ( V_148 , L_37 , V_199 ) != 1 )
return - V_127 ;
return V_198 ;
}
static T_5 F_116 ( struct V_1 * V_2 , int V_200 ,
const char * V_148 , T_7 V_198 )
{
T_1 V_25 ;
int V_74 , V_3 , V_39 ;
V_39 = F_17 ( V_2 , V_200 ) ;
if ( V_39 == - V_42 )
return V_39 ;
V_74 = F_115 ( V_148 , V_198 , & V_39 ) ;
V_3 = F_15 ( V_200 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_74 ;
}
static T_5 F_117 ( struct V_1 * V_2 , int V_200 , char * V_148 )
{
int V_39 = F_17 ( V_2 , V_200 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_148 , L_31 , V_39 ) ;
}
static T_5 F_118 ( struct V_145 * V_14 , struct V_146 * V_147 ,
const char * V_148 , T_7 V_198 )
{
int V_39 , V_74 ;
if ( ! V_198 || sscanf ( V_148 , L_37 , & V_39 ) != 1 )
return - V_127 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_127 ;
V_74 = F_10 ( V_201 , V_39 , 0 , NULL ) ;
if ( V_74 < 0 )
return V_74 ;
return V_198 ;
}
static T_6 F_119 ( struct V_151 * V_152 ,
struct V_153 * V_147 , int V_154 )
{
struct V_145 * V_14 = F_19 ( V_152 , struct V_145 , V_152 ) ;
struct V_16 * V_155 = F_90 ( V_14 ) ;
struct V_1 * V_2 = F_91 ( V_155 ) ;
bool V_156 = true ;
int V_200 = - 1 ;
if ( V_147 == & V_202 . V_147 )
V_200 = V_203 ;
else if ( V_147 == & V_204 . V_147 )
V_200 = V_205 ;
else if ( V_147 == & V_206 . V_147 )
V_200 = V_207 ;
else if ( V_147 == & V_208 . V_147 )
V_200 = V_209 ;
if ( V_200 != - 1 )
V_156 = ! ( F_17 ( V_2 , V_200 ) < 0 ) ;
return V_156 ? V_147 -> V_160 : 0 ;
}
static void F_120 ( struct V_16 * V_145 )
{
F_121 ( & V_145 -> V_14 . V_152 , & V_210 ) ;
}
static int F_122 ( struct V_16 * V_145 )
{
return F_123 ( & V_145 -> V_14 . V_152 , & V_210 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! F_10 ( V_211 , 0 , 0 , & V_74 ) )
F_114 ( L_38 , V_74 ) ;
if ( ! F_10 ( V_212 , 0 , 0x9 , & V_74 ) ) {
F_114 ( L_39 , V_74 >> 16 , V_74 & 0xFF ) ;
V_2 -> V_213 = V_74 ;
}
if ( ! F_10 ( V_214 , 0 , 0 , & V_74 ) ) {
F_114 ( L_40 , V_74 ) ;
V_2 -> V_159 = V_74 ;
}
if ( ! F_10 ( V_215 , 0 , 0 , NULL ) )
V_2 -> V_44 = V_215 ;
else
V_2 -> V_44 = V_216 ;
if ( V_2 -> V_7 -> V_77 -> V_78 >= 0 )
F_15 ( V_217 ,
V_2 -> V_7 -> V_77 -> V_78 , NULL ) ;
return F_122 ( V_2 -> V_16 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_120 ( V_2 -> V_16 ) ;
}
static int F_126 ( struct V_218 * V_219 , void * V_98 )
{
struct V_1 * V_2 = V_219 -> V_105 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_14 ( V_2 , V_2 -> V_220 . V_43 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_127 ( V_219 , L_41 , V_2 -> V_220 . V_43 , V_25 ) ;
return 0 ;
}
static int F_128 ( struct V_218 * V_219 , void * V_98 )
{
struct V_1 * V_2 = V_219 -> V_105 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_15 ( V_2 -> V_220 . V_43 , V_2 -> V_220 . V_45 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_127 ( V_219 , L_42 , V_2 -> V_220 . V_43 ,
V_2 -> V_220 . V_45 , V_25 ) ;
return 0 ;
}
static int F_129 ( struct V_218 * V_219 , void * V_98 )
{
struct V_1 * V_2 = V_219 -> V_105 ;
struct V_26 args = {
. V_23 = V_2 -> V_220 . V_43 ,
. V_24 = V_2 -> V_220 . V_45 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_220 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_127 ( V_219 , L_43 , V_2 -> V_220 . V_22 ,
V_2 -> V_220 . V_43 , V_2 -> V_220 . V_45 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_127 ( V_219 , L_44 , V_2 -> V_220 . V_22 ,
V_2 -> V_220 . V_43 , V_2 -> V_220 . V_45 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_130 ( struct V_221 * V_221 , struct V_222 * V_222 )
{
struct V_223 * V_102 = V_221 -> V_224 ;
return F_131 ( V_222 , V_102 -> V_225 , V_102 -> V_2 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( V_2 -> V_220 . V_226 ) ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_227 * V_228 ;
int V_229 ;
V_2 -> V_220 . V_226 = F_135 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_220 . V_226 ) {
F_50 ( L_45 ) ;
goto V_230;
}
V_228 = F_136 ( L_46 , V_231 | V_232 ,
V_2 -> V_220 . V_226 , & V_2 -> V_220 . V_22 ) ;
if ( ! V_228 )
goto V_230;
V_228 = F_136 ( L_47 , V_231 | V_232 ,
V_2 -> V_220 . V_226 , & V_2 -> V_220 . V_43 ) ;
if ( ! V_228 )
goto V_230;
V_228 = F_136 ( L_48 , V_231 | V_232 ,
V_2 -> V_220 . V_226 , & V_2 -> V_220 . V_45 ) ;
if ( ! V_228 )
goto V_230;
for ( V_229 = 0 ; V_229 < F_137 ( V_233 ) ; V_229 ++ ) {
struct V_223 * V_102 = & V_233 [ V_229 ] ;
V_102 -> V_2 = V_2 ;
V_228 = F_138 ( V_102 -> V_6 , V_234 | V_231 ,
V_2 -> V_220 . V_226 , V_102 ,
& V_235 ) ;
if ( ! V_228 ) {
F_50 ( L_49 , V_102 -> V_6 ) ;
goto V_230;
}
}
return 0 ;
V_230:
F_132 ( V_2 ) ;
return - V_5 ;
}
static int F_139 ( struct V_16 * V_155 )
{
struct V_236 * V_237 = F_140 ( V_155 -> V_14 . V_7 ) ;
struct V_238 * V_239 = F_141 ( V_237 ) ;
struct V_1 * V_2 ;
const char * V_240 ;
T_2 V_32 ;
int V_3 ;
T_1 V_68 ;
V_2 = F_69 ( sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_239 ;
V_2 -> V_16 = V_155 ;
V_239 -> V_16 = V_155 ;
F_142 ( V_2 -> V_16 , V_2 ) ;
if ( V_239 -> V_241 )
V_239 -> V_241 ( V_2 -> V_7 ) ;
V_3 = F_124 ( V_2 ) ;
if ( V_3 )
goto V_242;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_243;
V_3 = F_92 ( V_2 ) ;
if ( V_3 )
goto V_244;
V_3 = F_37 ( V_2 ) ;
if ( V_3 )
goto V_245;
V_3 = F_83 ( V_2 ) ;
if ( V_3 )
goto V_246;
V_240 = F_143 ( V_247 ) ;
if ( V_240 && ! strcmp ( V_240 , L_50 ) )
F_144 () ;
if ( V_2 -> V_7 -> V_77 -> V_248 )
F_144 () ;
if ( ! F_112 () ) {
F_114 ( L_51 ) ;
F_145 () ;
V_3 = F_105 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_249;
} else
F_114 ( L_52 ) ;
V_32 = F_146 ( V_2 -> V_7 -> V_250 ,
F_110 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_50 ( L_53 , V_32 ) ;
V_3 = - V_42 ;
goto V_251;
}
V_3 = F_134 ( V_2 ) ;
if ( V_3 )
goto V_252;
F_14 ( V_2 , V_82 , & V_68 ) ;
if ( V_68 & ( V_48 | V_253 ) )
V_2 -> V_7 -> V_120 = 1 ;
return 0 ;
V_252:
F_147 ( V_2 -> V_7 -> V_250 ) ;
V_251:
F_107 ( V_2 ) ;
V_249:
F_80 ( V_2 ) ;
V_246:
F_33 ( V_2 ) ;
V_245:
V_244:
F_8 ( V_2 ) ;
V_243:
F_125 ( V_2 ) ;
V_242:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_148 ( struct V_16 * V_145 )
{
struct V_1 * V_2 ;
V_2 = F_91 ( V_145 ) ;
F_147 ( V_2 -> V_7 -> V_250 ) ;
F_107 ( V_2 ) ;
F_8 ( V_2 ) ;
F_33 ( V_2 ) ;
F_80 ( V_2 ) ;
F_132 ( V_2 ) ;
F_125 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_149 ( struct V_145 * V_145 )
{
struct V_1 * V_2 = F_86 ( V_145 ) ;
if ( V_2 -> V_91 . V_92 ) {
bool V_91 ;
V_91 = F_17 ( V_2 , V_82 ) ;
F_15 ( V_82 , V_91 , NULL ) ;
}
return 0 ;
}
static int F_150 ( struct V_145 * V_145 )
{
struct V_1 * V_2 = F_86 ( V_145 ) ;
int V_254 ;
if ( V_2 -> V_91 . V_92 )
F_42 ( V_2 ) ;
if ( V_2 -> V_128 . V_92 ) {
V_254 = ! F_17 ( V_2 ,
V_135 ) ;
F_46 ( V_2 -> V_128 . V_92 , V_254 ) ;
}
if ( V_2 -> V_129 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_137 ) ;
F_46 ( V_2 -> V_129 . V_92 , V_254 ) ;
}
if ( V_2 -> V_130 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_139 ) ;
F_46 ( V_2 -> V_130 . V_92 , V_254 ) ;
}
if ( V_2 -> V_131 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_141 ) ;
F_46 ( V_2 -> V_131 . V_92 , V_254 ) ;
}
if ( V_2 -> V_132 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_143 ) ;
F_46 ( V_2 -> V_132 . V_92 , V_254 ) ;
}
return 0 ;
}
static int F_151 ( struct V_16 * V_155 )
{
struct V_236 * V_237 = F_140 ( V_155 -> V_14 . V_7 ) ;
struct V_238 * V_239 = F_141 ( V_237 ) ;
int V_107 ;
if ( ! F_152 ( V_36 ) ) {
F_48 ( L_54 ) ;
return - V_42 ;
}
if ( V_239 -> V_250 && ! F_152 ( V_239 -> V_250 ) ) {
F_48 ( L_55 ) ;
return - V_42 ;
}
if ( V_239 -> V_255 ) {
V_107 = V_239 -> V_255 ( V_155 ) ;
if ( V_107 )
return V_107 ;
}
return F_139 ( V_155 ) ;
}
int T_8 F_153 ( struct V_238 * V_7 )
{
struct V_236 * V_236 ;
struct V_16 * V_16 ;
if ( V_256 )
return - V_144 ;
V_236 = & V_7 -> V_236 ;
V_236 -> remove = F_148 ;
V_236 -> V_7 . V_257 = V_7 -> V_257 ;
V_236 -> V_7 . V_6 = V_7 -> V_6 ;
V_236 -> V_7 . V_258 = & V_259 ;
V_16 = F_154 ( V_236 ,
F_151 ,
NULL , 0 , NULL , 0 ) ;
if ( F_94 ( V_16 ) )
return F_95 ( V_16 ) ;
V_256 = true ;
return 0 ;
}
void F_155 ( struct V_238 * V_7 )
{
F_156 ( V_7 -> V_16 ) ;
F_157 ( & V_7 -> V_236 ) ;
V_256 = false ;
}
static int T_9 F_158 ( void )
{
if ( ! F_152 ( V_36 ) ) {
F_114 ( L_56 ) ;
return - V_42 ;
}
F_114 ( L_57 ) ;
return 0 ;
}
static void T_10 F_159 ( void )
{
F_114 ( L_58 ) ;
}
