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
if ( F_29 ( V_2 ) && ( V_2 -> V_7 -> V_77 -> V_78 == 4 ) ) {
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
if ( V_2 -> V_91 . V_92 )
F_45 ( V_2 -> V_91 . V_92 , V_86 ) ;
if ( V_2 -> V_93 ) {
V_85 = F_46 ( 0 , 1 ) ;
if ( ! V_85 ) {
F_47 ( L_6 ) ;
goto V_94;
}
if ( F_48 ( V_85 , 0 , V_95 , & V_88 ) ) {
F_49 ( L_7 ) ;
goto V_94;
}
V_87 = ( V_88 == 0xffffffff ) ;
if ( V_86 != V_87 ) {
F_47 ( L_8
L_9 ,
V_86 ? L_10 : L_11 ,
V_87 ? L_12 : L_13 ) ;
F_47 ( L_14
L_15 ) ;
goto V_94;
}
if ( ! V_86 ) {
V_14 = F_50 ( V_85 , 0 ) ;
if ( V_14 ) {
F_51 ( V_14 ) ;
goto V_94;
}
V_14 = F_52 ( V_85 , 0 ) ;
if ( V_14 ) {
F_53 ( V_85 ) ;
if ( F_54 ( V_14 ) )
F_49 ( L_16 ) ;
}
} else {
V_14 = F_50 ( V_85 , 0 ) ;
if ( V_14 ) {
F_55 ( V_14 ) ;
F_51 ( V_14 ) ;
}
}
}
V_94:
F_44 ( & V_2 -> V_90 ) ;
}
static void F_56 ( T_3 V_96 , T_1 V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
if ( V_97 != V_99 )
return;
F_21 ( V_2 -> V_100 , & V_2 -> V_101 ) ;
}
static int F_57 ( struct V_1 * V_2 , char * V_102 )
{
T_2 V_32 ;
T_3 V_96 ;
V_32 = F_58 ( NULL , V_102 , & V_96 ) ;
if ( F_59 ( V_32 ) ) {
V_32 = F_60 ( V_96 ,
V_103 ,
F_56 , V_2 ) ;
if ( F_12 ( V_32 ) )
F_47 ( L_17 , V_102 ) ;
} else
return - V_42 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , char * V_102 )
{
T_2 V_32 = V_104 ;
T_3 V_96 ;
V_32 = F_58 ( NULL , V_102 , & V_96 ) ;
if ( F_59 ( V_32 ) ) {
V_32 = F_62 ( V_96 ,
V_103 ,
F_56 ) ;
if ( F_12 ( V_32 ) )
F_49 ( L_18 ,
V_102 ) ;
}
}
static int F_63 ( struct V_93 * V_93 ,
T_4 * V_39 )
{
struct V_1 * V_2 = V_93 -> V_105 ;
int V_68 = F_17 ( V_2 , V_82 ) ;
if ( V_68 < 0 )
return V_68 ;
* V_39 = ! ! V_68 ;
return 0 ;
}
static void F_64 ( struct V_93 * V_93 )
{
F_13 ( V_93 -> V_106 ) ;
F_13 ( V_93 ) ;
}
static void F_65 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_52 , struct V_1 , V_101 ) ;
F_42 ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_107 = - V_5 ;
struct V_84 * V_85 = F_46 ( 0 , 1 ) ;
if ( ! V_85 ) {
F_49 ( L_19 ) ;
return - V_42 ;
}
V_2 -> V_100 =
F_38 ( L_20 ) ;
if ( ! V_2 -> V_100 )
goto V_108;
F_39 ( & V_2 -> V_101 , F_65 ) ;
V_2 -> V_93 = F_67 ( sizeof( struct V_93 ) , V_109 ) ;
if ( ! V_2 -> V_93 )
goto V_110;
V_2 -> V_93 -> V_106 = F_67 ( sizeof( struct V_111 ) ,
V_109 ) ;
if ( ! V_2 -> V_93 -> V_106 )
goto V_112;
V_2 -> V_93 -> V_105 = V_2 ;
V_2 -> V_93 -> V_113 = & F_64 ;
V_2 -> V_93 -> V_114 = & V_115 ;
F_63 ( V_2 -> V_93 ,
& V_2 -> V_93 -> V_106 -> V_116 ) ;
V_107 = F_68 ( V_2 -> V_93 , V_85 , 0 , L_21 ) ;
if ( V_107 ) {
F_49 ( L_22 , V_107 ) ;
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
static int F_69 ( void * V_98 , bool V_86 )
{
struct V_118 * V_119 = V_98 ;
T_1 V_45 = ! V_86 ;
T_1 V_43 = V_119 -> V_43 ;
if ( ( V_43 == V_82 ) &&
V_119 -> V_2 -> V_7 -> V_120 )
V_43 = V_121 ;
return F_15 ( V_43 , V_45 , NULL ) ;
}
static void F_70 ( struct V_92 * V_92 , void * V_98 )
{
struct V_118 * V_119 = V_98 ;
int V_68 ;
V_68 = F_17 ( V_119 -> V_2 , V_119 -> V_43 ) ;
if ( V_68 < 0 )
return;
F_45 ( V_119 -> V_92 , ! V_68 ) ;
}
static int F_71 ( void * V_98 , bool V_86 )
{
struct V_118 * V_119 = V_98 ;
struct V_1 * V_2 = V_119 -> V_2 ;
int V_107 ;
F_43 ( & V_2 -> V_89 ) ;
V_107 = F_69 ( V_98 , V_86 ) ;
F_44 ( & V_2 -> V_89 ) ;
return V_107 ;
}
static int F_72 ( struct V_1 * V_2 ,
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
* V_92 = F_73 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_125 , V_122 ) ;
else
* V_92 = F_73 ( V_6 , & V_2 -> V_16 -> V_14 , type ,
& V_126 , V_122 ) ;
if ( ! * V_92 )
return - V_127 ;
if ( ( V_43 == V_82 ) &&
( V_2 -> V_7 -> V_77 -> V_78 == 4 ) )
F_74 ( * V_92 , L_5 ) ;
F_75 ( * V_92 , ! V_68 ) ;
V_68 = F_76 ( * V_92 ) ;
if ( V_68 ) {
F_77 ( * V_92 ) ;
* V_92 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_61 ( V_2 , L_23 ) ;
F_61 ( V_2 , L_24 ) ;
F_61 ( V_2 , L_25 ) ;
if ( V_2 -> V_91 . V_92 ) {
F_79 ( V_2 -> V_91 . V_92 ) ;
F_77 ( V_2 -> V_91 . V_92 ) ;
V_2 -> V_91 . V_92 = NULL ;
}
F_42 ( V_2 ) ;
if ( V_2 -> V_93 )
F_80 ( V_2 -> V_93 ) ;
if ( V_2 -> V_100 )
F_36 ( V_2 -> V_100 ) ;
if ( V_2 -> V_128 . V_92 ) {
F_79 ( V_2 -> V_128 . V_92 ) ;
F_77 ( V_2 -> V_128 . V_92 ) ;
V_2 -> V_128 . V_92 = NULL ;
}
if ( V_2 -> V_129 . V_92 ) {
F_79 ( V_2 -> V_129 . V_92 ) ;
F_77 ( V_2 -> V_129 . V_92 ) ;
V_2 -> V_129 . V_92 = NULL ;
}
if ( V_2 -> V_130 . V_92 ) {
F_79 ( V_2 -> V_130 . V_92 ) ;
F_77 ( V_2 -> V_130 . V_92 ) ;
V_2 -> V_130 . V_92 = NULL ;
}
if ( V_2 -> V_131 . V_92 ) {
F_79 ( V_2 -> V_131 . V_92 ) ;
F_77 ( V_2 -> V_131 . V_92 ) ;
V_2 -> V_131 . V_92 = NULL ;
}
if ( V_2 -> V_132 . V_92 ) {
F_79 ( V_2 -> V_132 . V_92 ) ;
F_77 ( V_2 -> V_132 . V_92 ) ;
V_2 -> V_132 . V_92 = NULL ;
}
}
static int F_81 ( struct V_1 * V_2 )
{
int V_68 = 0 ;
F_82 ( & V_2 -> V_90 ) ;
F_82 ( & V_2 -> V_89 ) ;
V_68 = F_72 ( V_2 , & V_2 -> V_91 , L_5 ,
V_133 , V_82 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_72 ( V_2 , & V_2 -> V_128 ,
L_26 , V_134 ,
V_135 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_72 ( V_2 , & V_2 -> V_129 , L_27 ,
V_136 , V_137 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_72 ( V_2 , & V_2 -> V_130 , L_28 ,
V_138 , V_139 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_72 ( V_2 , & V_2 -> V_131 , L_29 ,
V_140 , V_141 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
V_68 = F_72 ( V_2 , & V_2 -> V_132 , L_30 ,
V_142 , V_143 ) ;
if ( V_68 && V_68 != - V_42 )
goto exit;
if ( ! V_2 -> V_7 -> V_77 -> V_124 )
goto exit;
V_68 = F_66 ( V_2 ) ;
if ( V_68 == - V_144 )
V_68 = 0 ;
F_57 ( V_2 , L_23 ) ;
F_57 ( V_2 , L_24 ) ;
F_57 ( V_2 , L_25 ) ;
F_42 ( V_2 ) ;
exit:
if ( V_68 && V_68 != - V_42 )
F_78 ( V_2 ) ;
if ( V_68 == - V_42 )
V_68 = 0 ;
return V_68 ;
}
static T_5 F_83 ( struct V_145 * V_14 ,
struct V_146 * V_147 ,
char * V_148 )
{
struct V_1 * V_2 = F_84 ( V_14 ) ;
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
F_49 ( L_31 , V_39 ) ;
V_39 = - 1 ;
}
return sprintf ( V_148 , L_32 , V_39 ) ;
}
static T_5 F_85 ( struct V_145 * V_14 ,
struct V_146 * V_147 ,
char * V_148 )
{
struct V_1 * V_2 = F_84 ( V_14 ) ;
T_1 V_39 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_150 , & V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
V_39 = F_86 ( ( V_39 & 0xFFFF ) ) * 1000 ;
return sprintf ( V_148 , L_32 , V_39 ) ;
}
static T_5
F_87 ( struct V_145 * V_14 , struct V_146 * V_147 , char * V_148 )
{
return sprintf ( V_148 , L_33 ) ;
}
static T_6 F_88 ( struct V_151 * V_152 ,
struct V_153 * V_147 , int V_154 )
{
struct V_145 * V_14 = F_19 ( V_152 , struct V_145 , V_152 ) ;
struct V_16 * V_155 = F_89 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = F_90 ( V_155 ) ;
bool V_156 = true ;
int V_43 = - 1 ;
T_1 V_39 = V_41 ;
if ( V_147 == & V_157 . V_158 . V_147 )
V_43 = V_149 ;
else if ( V_147 == & V_159 . V_158 . V_147 )
V_43 = V_150 ;
if ( V_43 != - 1 ) {
int V_3 = F_14 ( V_2 , V_43 , & V_39 ) ;
if ( V_3 < 0 )
return 0 ;
}
if ( V_43 == V_149 ) {
if ( V_39 == V_41 || V_39 & 0xFFF80000
|| ( ! V_2 -> V_160 && ! ( V_39 & V_48 ) ) )
V_156 = false ;
} else if ( V_43 == V_150 ) {
if ( V_39 == 0 )
V_156 = false ;
}
return V_156 ? V_147 -> V_161 : 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_145 * V_162 ;
V_162 = V_2 -> V_163 ;
if ( ! V_162 )
return;
F_92 ( & V_162 -> V_152 , & V_164 ) ;
F_93 ( V_162 ) ;
V_2 -> V_163 = NULL ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_145 * V_162 ;
int V_68 ;
V_162 = F_95 ( & V_2 -> V_16 -> V_14 ) ;
if ( F_96 ( V_162 ) ) {
F_49 ( L_34 ) ;
return F_97 ( V_162 ) ;
}
F_98 ( V_162 , V_2 ) ;
V_2 -> V_163 = V_162 ;
V_68 = F_99 ( & V_162 -> V_152 , & V_164 ) ;
if ( V_68 )
F_91 ( V_2 ) ;
return V_68 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_107 ;
if ( V_2 -> V_7 -> V_77 -> V_165 )
V_107 = ! V_2 -> V_7 -> V_166 ;
else
V_107 = F_17 ( V_2 ,
V_167 ) ;
if ( V_107 < 0 )
return V_107 ;
return V_107 ? V_168 : V_169 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_170 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = V_25 & V_171 ;
V_25 >>= 8 ;
if ( ! V_25 )
return - V_42 ;
return V_25 ;
}
static int F_102 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_103 ( V_173 ) ;
T_1 V_25 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_170 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_25 & V_73 ;
}
static T_1 F_104 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_103 ( V_173 ) ;
T_1 V_45 = 0 ;
if ( ( V_2 -> V_7 -> V_174 < V_173 -> V_175 . V_174 ) ||
V_173 -> V_175 . V_174 == V_173 -> V_175 . V_67 )
V_45 = 0x00008001 ;
else if ( ( V_2 -> V_7 -> V_174 > V_173 -> V_175 . V_174 ) ||
V_173 -> V_175 . V_174 == 0 )
V_45 = 0x00008000 ;
V_2 -> V_7 -> V_174 = V_173 -> V_175 . V_174 ;
return V_45 ;
}
static int F_105 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_103 ( V_173 ) ;
T_1 V_45 ;
int V_176 , V_3 = 0 ;
V_176 = F_100 ( V_2 ) ;
if ( V_176 != - V_42 && V_173 -> V_175 . V_176 != V_176 ) {
V_45 = ! ! ( V_173 -> V_175 . V_176 == V_168 ) ;
V_3 = F_15 ( V_167 ,
V_45 , NULL ) ;
if ( V_2 -> V_7 -> V_77 -> V_165 )
V_2 -> V_7 -> V_166 = V_173 -> V_175 . V_176 ;
if ( V_2 -> V_7 -> V_77 -> V_177 )
return V_3 ;
}
if ( V_2 -> V_7 -> V_77 -> V_177 )
V_45 = F_104 ( V_173 ) ;
else
V_45 = V_173 -> V_175 . V_174 ;
V_3 = F_15 ( V_170 ,
V_45 , NULL ) ;
return V_3 ;
}
static int F_106 ( struct V_1 * V_2 , int V_178 )
{
struct V_172 * V_173 = V_2 -> V_172 ;
int V_179 = V_173 -> V_175 . V_174 ;
int V_180 = V_179 ;
if ( V_178 >= V_181 && V_178 <= V_182 )
V_180 = V_178 - V_181 + 1 ;
else if ( V_178 >= V_183 && V_178 <= V_184 )
V_180 = V_178 - V_183 ;
V_173 -> V_175 . V_174 = V_180 ;
F_107 ( V_173 ) ;
F_108 ( V_173 , V_185 ) ;
return V_179 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_172 * V_173 ;
struct V_186 V_175 ;
int V_187 ;
int V_176 ;
V_187 = F_101 ( V_2 ) ;
if ( V_187 == - V_42 )
V_187 = 0 ;
else if ( V_187 < 0 )
return V_187 ;
V_176 = F_100 ( V_2 ) ;
if ( V_176 == - V_42 )
V_176 = V_168 ;
else if ( V_176 < 0 )
return V_176 ;
memset ( & V_175 , 0 , sizeof( struct V_186 ) ) ;
V_175 . type = V_188 ;
V_175 . V_67 = V_187 ;
V_173 = F_110 ( V_2 -> V_7 -> V_6 ,
& V_2 -> V_16 -> V_14 , V_2 ,
& V_189 , & V_175 ) ;
if ( F_96 ( V_173 ) ) {
F_49 ( L_35 ) ;
return F_97 ( V_173 ) ;
}
V_2 -> V_172 = V_173 ;
if ( V_2 -> V_7 -> V_77 -> V_165 )
V_2 -> V_7 -> V_166 = V_176 ;
V_173 -> V_175 . V_174 = F_102 ( V_173 ) ;
V_173 -> V_175 . V_176 = V_176 ;
F_107 ( V_173 ) ;
V_2 -> V_7 -> V_174 = V_173 -> V_175 . V_174 ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( V_2 -> V_172 )
F_112 ( V_2 -> V_172 ) ;
V_2 -> V_172 = NULL ;
}
static int F_113 ( int V_178 )
{
if ( ( V_178 >= 0x61 && V_178 <= 0x67 ) ||
( V_178 >= 0x8c && V_178 <= 0x93 ) ||
( V_178 >= 0xa0 && V_178 <= 0xa7 ) ||
( V_178 >= 0xd0 && V_178 <= 0xd5 ) )
return 1 ;
return 0 ;
}
static void F_114 ( T_1 V_39 , void * V_190 )
{
struct V_1 * V_2 = V_190 ;
struct V_27 V_191 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
int V_178 ;
int V_192 ;
unsigned int V_193 = 1 ;
bool V_194 = 1 ;
V_32 = F_115 ( V_39 , & V_191 ) ;
if ( V_32 != V_104 ) {
F_49 ( L_36 , V_32 ) ;
return;
}
V_34 = (union V_33 * ) V_191 . V_37 ;
if ( ! V_34 || V_34 -> type != V_38 )
goto exit;
V_178 = V_34 -> integer . V_39 ;
V_192 = V_178 ;
if ( V_2 -> V_7 -> V_195 ) {
V_2 -> V_7 -> V_195 ( V_2 -> V_7 , & V_178 , & V_193 ,
& V_194 ) ;
if ( V_178 == V_196 )
goto exit;
}
if ( V_178 >= V_181 && V_178 <= V_182 )
V_178 = V_197 ;
else if ( V_178 >= V_183 &&
V_178 <= V_184 )
V_178 = V_198 ;
if ( V_178 == V_198 || V_178 == V_197 ) {
if ( ! F_116 () ) {
F_106 ( V_2 , V_192 ) ;
goto exit;
}
}
if ( F_113 ( V_178 ) &&
V_2 -> V_7 -> V_77 -> V_199 )
goto exit;
if ( ! F_117 ( V_2 -> V_4 , V_178 ,
V_193 , V_194 ) )
F_118 ( L_37 , V_178 ) ;
exit:
F_13 ( V_34 ) ;
}
static int F_119 ( const char * V_148 , unsigned long V_200 , int * V_201 )
{
if ( ! V_200 )
return 0 ;
if ( sscanf ( V_148 , L_38 , V_201 ) != 1 )
return - V_127 ;
return V_200 ;
}
static T_5 F_120 ( struct V_1 * V_2 , int V_202 ,
const char * V_148 , T_7 V_200 )
{
T_1 V_25 ;
int V_74 , V_3 , V_39 ;
V_39 = F_17 ( V_2 , V_202 ) ;
if ( V_39 == - V_42 )
return V_39 ;
V_74 = F_119 ( V_148 , V_200 , & V_39 ) ;
V_3 = F_15 ( V_202 , V_39 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_74 ;
}
static T_5 F_121 ( struct V_1 * V_2 , int V_202 , char * V_148 )
{
int V_39 = F_17 ( V_2 , V_202 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_148 , L_32 , V_39 ) ;
}
static T_5 F_122 ( struct V_145 * V_14 , struct V_146 * V_147 ,
const char * V_148 , T_7 V_200 )
{
int V_39 , V_74 ;
if ( ! V_200 || sscanf ( V_148 , L_38 , & V_39 ) != 1 )
return - V_127 ;
if ( V_39 < 0 || V_39 > 2 )
return - V_127 ;
V_74 = F_10 ( V_203 , V_39 , 0 , NULL ) ;
if ( V_74 < 0 )
return V_74 ;
return V_200 ;
}
static T_6 F_123 ( struct V_151 * V_152 ,
struct V_153 * V_147 , int V_154 )
{
struct V_145 * V_14 = F_19 ( V_152 , struct V_145 , V_152 ) ;
struct V_16 * V_155 = F_89 ( V_14 ) ;
struct V_1 * V_2 = F_90 ( V_155 ) ;
bool V_156 = true ;
int V_202 = - 1 ;
if ( V_147 == & V_204 . V_147 )
V_202 = V_205 ;
else if ( V_147 == & V_206 . V_147 )
V_202 = V_207 ;
else if ( V_147 == & V_208 . V_147 )
V_202 = V_209 ;
else if ( V_147 == & V_210 . V_147 )
V_202 = V_211 ;
if ( V_202 != - 1 )
V_156 = ! ( F_17 ( V_2 , V_202 ) < 0 ) ;
return V_156 ? V_147 -> V_161 : 0 ;
}
static void F_124 ( struct V_16 * V_145 )
{
F_92 ( & V_145 -> V_14 . V_152 , & V_212 ) ;
}
static int F_125 ( struct V_16 * V_145 )
{
return F_99 ( & V_145 -> V_14 . V_152 , & V_212 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! F_10 ( V_213 , 0 , 0 , & V_74 ) )
F_118 ( L_39 , V_74 ) ;
if ( ! F_10 ( V_214 , 0 , 0x9 , & V_74 ) ) {
F_118 ( L_40 , V_74 >> 16 , V_74 & 0xFF ) ;
V_2 -> V_215 = V_74 ;
}
if ( ! F_10 ( V_216 , 0 , 0 , & V_74 ) ) {
F_118 ( L_41 , V_74 ) ;
V_2 -> V_160 = V_74 ;
}
if ( ! F_10 ( V_217 , 0 , 0 , NULL ) )
V_2 -> V_44 = V_217 ;
else
V_2 -> V_44 = V_218 ;
if ( V_2 -> V_7 -> V_77 -> V_78 >= 0 )
F_15 ( V_219 ,
V_2 -> V_7 -> V_77 -> V_78 , NULL ) ;
return F_125 ( V_2 -> V_16 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_124 ( V_2 -> V_16 ) ;
}
static int F_128 ( struct V_220 * V_221 , void * V_98 )
{
struct V_1 * V_2 = V_221 -> V_105 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_14 ( V_2 , V_2 -> V_222 . V_43 , & V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_129 ( V_221 , L_42 , V_2 -> V_222 . V_43 , V_25 ) ;
return 0 ;
}
static int F_130 ( struct V_220 * V_221 , void * V_98 )
{
struct V_1 * V_2 = V_221 -> V_105 ;
int V_3 ;
T_1 V_25 = - 1 ;
V_3 = F_15 ( V_2 -> V_222 . V_43 , V_2 -> V_222 . V_45 ,
& V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
F_129 ( V_221 , L_43 , V_2 -> V_222 . V_43 ,
V_2 -> V_222 . V_45 , V_25 ) ;
return 0 ;
}
static int F_131 ( struct V_220 * V_221 , void * V_98 )
{
struct V_1 * V_2 = V_221 -> V_105 ;
struct V_26 args = {
. V_23 = V_2 -> V_222 . V_43 ,
. V_24 = V_2 -> V_222 . V_45 ,
} ;
struct V_27 V_28 = { ( V_29 ) sizeof( args ) , & args } ;
struct V_27 V_30 = { V_31 , NULL } ;
union V_33 * V_34 ;
T_2 V_32 ;
V_32 = F_11 ( V_36 ,
1 , V_2 -> V_222 . V_22 ,
& V_28 , & V_30 ) ;
if ( F_12 ( V_32 ) )
return - V_40 ;
V_34 = (union V_33 * ) V_30 . V_37 ;
if ( V_34 && V_34 -> type == V_38 )
F_129 ( V_221 , L_44 , V_2 -> V_222 . V_22 ,
V_2 -> V_222 . V_43 , V_2 -> V_222 . V_45 ,
( T_1 ) V_34 -> integer . V_39 ) ;
else
F_129 ( V_221 , L_45 , V_2 -> V_222 . V_22 ,
V_2 -> V_222 . V_43 , V_2 -> V_222 . V_45 ,
V_34 ? V_34 -> type : - 1 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static int F_132 ( struct V_223 * V_223 , struct V_224 * V_224 )
{
struct V_225 * V_102 = V_223 -> V_226 ;
return F_133 ( V_224 , V_102 -> V_227 , V_102 -> V_2 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
F_135 ( V_2 -> V_222 . V_228 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_229 * V_230 ;
int V_231 ;
V_2 -> V_222 . V_228 = F_137 ( V_2 -> V_7 -> V_6 , NULL ) ;
if ( ! V_2 -> V_222 . V_228 ) {
F_49 ( L_46 ) ;
goto V_232;
}
V_230 = F_138 ( L_47 , V_233 | V_234 ,
V_2 -> V_222 . V_228 , & V_2 -> V_222 . V_22 ) ;
if ( ! V_230 )
goto V_232;
V_230 = F_138 ( L_48 , V_233 | V_234 ,
V_2 -> V_222 . V_228 , & V_2 -> V_222 . V_43 ) ;
if ( ! V_230 )
goto V_232;
V_230 = F_138 ( L_49 , V_233 | V_234 ,
V_2 -> V_222 . V_228 , & V_2 -> V_222 . V_45 ) ;
if ( ! V_230 )
goto V_232;
for ( V_231 = 0 ; V_231 < F_139 ( V_235 ) ; V_231 ++ ) {
struct V_225 * V_102 = & V_235 [ V_231 ] ;
V_102 -> V_2 = V_2 ;
V_230 = F_140 ( V_102 -> V_6 , V_236 | V_233 ,
V_2 -> V_222 . V_228 , V_102 ,
& V_237 ) ;
if ( ! V_230 ) {
F_49 ( L_50 , V_102 -> V_6 ) ;
goto V_232;
}
}
return 0 ;
V_232:
F_134 ( V_2 ) ;
return - V_5 ;
}
static int F_141 ( struct V_16 * V_155 )
{
struct V_238 * V_239 = F_142 ( V_155 -> V_14 . V_7 ) ;
struct V_240 * V_241 = F_143 ( V_239 ) ;
struct V_1 * V_2 ;
T_2 V_32 ;
int V_3 ;
T_1 V_68 ;
V_2 = F_67 ( sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_2 )
return - V_5 ;
V_2 -> V_7 = V_241 ;
V_2 -> V_16 = V_155 ;
V_241 -> V_16 = V_155 ;
F_144 ( V_2 -> V_16 , V_2 ) ;
if ( V_241 -> V_242 )
V_241 -> V_242 ( V_2 -> V_7 ) ;
V_3 = F_126 ( V_2 ) ;
if ( V_3 )
goto V_243;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_244;
V_3 = F_94 ( V_2 ) ;
if ( V_3 )
goto V_245;
V_3 = F_37 ( V_2 ) ;
if ( V_3 )
goto V_246;
V_3 = F_81 ( V_2 ) ;
if ( V_3 )
goto V_247;
if ( V_2 -> V_7 -> V_77 -> V_248 )
F_145 () ;
if ( ! F_116 () ) {
F_118 ( L_51 ) ;
F_146 () ;
V_3 = F_109 ( V_2 ) ;
if ( V_3 && V_3 != - V_42 )
goto V_249;
} else
F_118 ( L_52 ) ;
V_32 = F_147 ( V_2 -> V_7 -> V_250 ,
F_114 , V_2 ) ;
if ( F_12 ( V_32 ) ) {
F_49 ( L_53 , V_32 ) ;
V_3 = - V_42 ;
goto V_251;
}
V_3 = F_136 ( V_2 ) ;
if ( V_3 )
goto V_252;
F_14 ( V_2 , V_82 , & V_68 ) ;
if ( V_68 & ( V_48 | V_253 ) )
V_2 -> V_7 -> V_120 = 1 ;
return 0 ;
V_252:
F_148 ( V_2 -> V_7 -> V_250 ) ;
V_251:
F_111 ( V_2 ) ;
V_249:
F_78 ( V_2 ) ;
V_247:
F_33 ( V_2 ) ;
V_246:
F_91 ( V_2 ) ;
V_245:
F_8 ( V_2 ) ;
V_244:
F_127 ( V_2 ) ;
V_243:
F_13 ( V_2 ) ;
return V_3 ;
}
static int F_149 ( struct V_16 * V_145 )
{
struct V_1 * V_2 ;
V_2 = F_90 ( V_145 ) ;
F_148 ( V_2 -> V_7 -> V_250 ) ;
F_111 ( V_2 ) ;
F_8 ( V_2 ) ;
F_91 ( V_2 ) ;
F_33 ( V_2 ) ;
F_78 ( V_2 ) ;
F_134 ( V_2 ) ;
F_127 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_145 * V_145 )
{
struct V_1 * V_2 = F_84 ( V_145 ) ;
if ( V_2 -> V_91 . V_92 ) {
bool V_91 ;
V_91 = F_17 ( V_2 , V_82 ) ;
F_15 ( V_82 , V_91 , NULL ) ;
}
return 0 ;
}
static int F_151 ( struct V_145 * V_145 )
{
struct V_1 * V_2 = F_84 ( V_145 ) ;
int V_254 ;
if ( V_2 -> V_91 . V_92 )
F_42 ( V_2 ) ;
if ( V_2 -> V_128 . V_92 ) {
V_254 = ! F_17 ( V_2 ,
V_135 ) ;
F_45 ( V_2 -> V_128 . V_92 , V_254 ) ;
}
if ( V_2 -> V_129 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_137 ) ;
F_45 ( V_2 -> V_129 . V_92 , V_254 ) ;
}
if ( V_2 -> V_130 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_139 ) ;
F_45 ( V_2 -> V_130 . V_92 , V_254 ) ;
}
if ( V_2 -> V_131 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_141 ) ;
F_45 ( V_2 -> V_131 . V_92 , V_254 ) ;
}
if ( V_2 -> V_132 . V_92 ) {
V_254 = ! F_17 ( V_2 , V_143 ) ;
F_45 ( V_2 -> V_132 . V_92 , V_254 ) ;
}
return 0 ;
}
static int F_152 ( struct V_16 * V_155 )
{
struct V_238 * V_239 = F_142 ( V_155 -> V_14 . V_7 ) ;
struct V_240 * V_241 = F_143 ( V_239 ) ;
int V_107 ;
if ( ! F_153 ( V_36 ) ) {
F_47 ( L_54 ) ;
return - V_42 ;
}
if ( V_241 -> V_250 && ! F_153 ( V_241 -> V_250 ) ) {
F_47 ( L_55 ) ;
return - V_42 ;
}
if ( V_241 -> V_255 ) {
V_107 = V_241 -> V_255 ( V_155 ) ;
if ( V_107 )
return V_107 ;
}
return F_141 ( V_155 ) ;
}
int T_8 F_154 ( struct V_240 * V_7 )
{
struct V_238 * V_238 ;
struct V_16 * V_16 ;
if ( V_256 )
return - V_144 ;
V_238 = & V_7 -> V_238 ;
V_238 -> remove = F_149 ;
V_238 -> V_7 . V_257 = V_7 -> V_257 ;
V_238 -> V_7 . V_6 = V_7 -> V_6 ;
V_238 -> V_7 . V_258 = & V_259 ;
V_16 = F_155 ( V_238 ,
F_152 ,
NULL , 0 , NULL , 0 ) ;
if ( F_96 ( V_16 ) )
return F_97 ( V_16 ) ;
V_256 = true ;
return 0 ;
}
void F_156 ( struct V_240 * V_7 )
{
F_157 ( V_7 -> V_16 ) ;
F_158 ( & V_7 -> V_238 ) ;
V_256 = false ;
}
static int T_9 F_159 ( void )
{
if ( ! F_153 ( V_36 ) ) {
F_118 ( L_56 ) ;
return - V_42 ;
}
F_118 ( L_57 ) ;
return 0 ;
}
static void T_10 F_160 ( void )
{
F_118 ( L_58 ) ;
}
