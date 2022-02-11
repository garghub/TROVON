int F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) , F_3 ( struct V_2 ) , 0 , NULL ) ;
if ( ! V_1 ) {
F_4 ( L_2 ) ;
goto V_3;
}
V_4 = F_2 ( L_3 ,
sizeof( struct V_5 ) , F_3 ( struct V_5 ) ,
0 , NULL ) ;
if ( ! V_4 ) {
F_4 ( L_4
L_5 ) ;
goto V_3;
}
V_6 = F_2 ( L_6 ,
sizeof( struct V_7 ) , F_3 ( struct V_7 ) ,
0 , NULL ) ;
if ( ! V_6 ) {
F_4 ( L_7
L_5 ) ;
goto V_3;
}
V_8 = F_2 ( L_8 ,
sizeof( struct V_9 ) , F_3 ( struct V_9 ) ,
0 , NULL ) ;
if ( ! V_8 ) {
F_4 ( L_9 ) ;
goto V_3;
}
V_10 = F_2 ( L_10 ,
sizeof( struct V_11 ) ,
F_3 ( struct V_11 ) , 0 , NULL ) ;
if ( ! V_10 ) {
F_4 ( L_11
L_5 ) ;
goto V_3;
}
V_12 = F_2 ( L_12 ,
sizeof( struct V_13 ) , F_3 ( struct V_13 ) ,
0 , NULL ) ;
if ( ! V_12 ) {
F_4 ( L_13
L_5 ) ;
goto V_3;
}
V_14 = F_2 ( L_14 ,
sizeof( struct V_15 ) ,
F_3 ( struct V_15 ) , 0 , NULL ) ;
if ( ! V_14 ) {
F_4 ( L_15
L_16 ) ;
goto V_3;
}
V_16 = F_2 ( L_17 ,
sizeof( struct V_17 ) ,
F_3 ( struct V_17 ) , 0 , NULL ) ;
if ( ! V_16 ) {
F_4 ( L_18
L_16 ) ;
goto V_3;
}
V_18 = F_2 (
L_19 ,
sizeof( struct V_19 ) ,
F_3 ( struct V_19 ) ,
0 , NULL ) ;
if ( ! V_18 ) {
F_4 ( L_18
L_20 ) ;
goto V_3;
}
return 0 ;
V_3:
if ( V_1 )
F_5 ( V_1 ) ;
if ( V_4 )
F_5 ( V_4 ) ;
if ( V_6 )
F_5 ( V_6 ) ;
if ( V_8 )
F_5 ( V_8 ) ;
if ( V_10 )
F_5 ( V_10 ) ;
if ( V_12 )
F_5 ( V_12 ) ;
if ( V_14 )
F_5 ( V_14 ) ;
if ( V_16 )
F_5 ( V_16 ) ;
if ( V_18 )
F_5 ( V_18 ) ;
return - V_20 ;
}
void F_6 ( void )
{
F_5 ( V_1 ) ;
F_5 ( V_4 ) ;
F_5 ( V_6 ) ;
F_5 ( V_8 ) ;
F_5 ( V_10 ) ;
F_5 ( V_12 ) ;
F_5 ( V_14 ) ;
F_5 ( V_16 ) ;
F_5 ( V_18 ) ;
}
T_1 F_7 ( T_2 type )
{
T_1 V_21 ;
F_8 ( ( type < 0 ) || ( type >= V_22 ) ) ;
F_9 ( & V_23 ) ;
V_21 = ++ V_24 [ type ] ;
F_10 ( & V_23 ) ;
return V_21 ;
}
void F_11 ( struct V_25 * V_26 )
{
F_12 ( & V_26 -> V_27 , 0 ) ;
F_13 ( & V_26 -> V_28 ) ;
F_14 ( & V_26 -> V_29 ) ;
F_15 ( & V_26 -> V_30 ) ;
}
static int F_16 ( void )
{
int V_31 ;
V_31 = F_17 ( L_21 ) ;
if ( V_31 != 0 )
F_4 ( L_22 ) ;
V_31 = F_17 ( L_23 ) ;
if ( V_31 != 0 )
F_4 ( L_24 ) ;
V_31 = F_17 ( L_25 ) ;
if ( V_31 != 0 )
F_4 ( L_26 ) ;
V_31 = F_17 ( L_27 ) ;
if ( V_31 != 0 )
F_4 ( L_28 ) ;
return 0 ;
}
int F_18 ( void )
{
int V_31 ;
if ( V_32 )
return 0 ;
V_31 = F_16 () ;
if ( V_31 < 0 )
return V_31 ;
V_32 = 1 ;
return 0 ;
}
struct V_7 * F_19 ( void )
{
struct V_7 * V_33 ;
V_33 = F_20 ( V_6 , V_34 ) ;
if ( ! V_33 ) {
F_4 ( L_29
L_30 ) ;
return F_21 ( - V_20 ) ;
}
F_13 ( & V_33 -> V_35 ) ;
F_13 ( & V_33 -> V_36 ) ;
return V_33 ;
}
void F_22 (
struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_7 * V_33 ,
void * V_41 )
{
unsigned char V_42 [ V_43 ] ;
V_33 -> V_38 = V_38 ;
V_33 -> V_41 = V_41 ;
if ( V_40 ) {
if ( V_38 -> V_44 -> V_45 != NULL ) {
memset ( & V_42 [ 0 ] , 0 , V_43 ) ;
V_38 -> V_44 -> V_45 ( V_33 ,
& V_42 [ 0 ] , V_43 ) ;
V_33 -> V_46 = F_23 ( & V_42 [ 0 ] ) ;
}
F_24 ( & V_40 -> V_47 ) ;
V_40 -> V_48 = V_33 ;
F_25 ( & V_33 -> V_36 ,
& V_40 -> V_49 ) ;
F_26 ( & V_40 -> V_47 ) ;
}
F_25 ( & V_33 -> V_35 , & V_38 -> V_50 ) ;
F_27 ( L_31 ,
V_38 -> V_44 -> V_51 () , V_33 -> V_41 ) ;
}
void F_28 (
struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_7 * V_33 ,
void * V_41 )
{
F_29 ( & V_38 -> V_52 ) ;
F_22 ( V_38 , V_40 , V_33 , V_41 ) ;
F_30 ( & V_38 -> V_52 ) ;
}
void F_31 ( struct V_7 * V_33 )
{
struct V_39 * V_40 ;
unsigned long V_53 ;
V_40 = V_33 -> V_39 ;
if ( V_40 ) {
F_32 ( & V_40 -> V_47 , V_53 ) ;
F_33 ( & V_33 -> V_36 ) ;
if ( F_34 ( & V_40 -> V_49 ) )
V_40 -> V_48 = NULL ;
else {
V_40 -> V_48 = F_35 (
V_40 -> V_49 . V_54 ,
struct V_7 , V_36 ) ;
}
F_36 ( & V_40 -> V_47 , V_53 ) ;
}
}
void F_37 ( struct V_7 * V_33 )
{
F_38 ( V_6 , V_33 ) ;
}
void F_39 ( struct V_7 * V_33 )
{
struct V_37 * V_38 = V_33 -> V_38 ;
struct V_39 * V_40 ;
unsigned long V_53 ;
if ( ! V_38 ) {
F_37 ( V_33 ) ;
return;
}
F_32 ( & V_38 -> V_52 , V_53 ) ;
F_33 ( & V_33 -> V_35 ) ;
V_33 -> V_38 = NULL ;
V_33 -> V_41 = NULL ;
F_36 ( & V_38 -> V_52 , V_53 ) ;
V_40 = V_33 -> V_39 ;
if ( V_40 ) {
F_32 ( & V_38 -> V_55 , V_53 ) ;
if ( V_40 -> V_56 ) {
if ( ! V_38 -> V_44 -> V_57 (
V_38 ) ) {
F_33 ( & V_40 -> V_58 ) ;
V_38 -> V_59 -- ;
F_36 ( & V_38 -> V_55 , V_53 ) ;
F_40 ( V_40 ) ;
F_41 ( V_40 , V_38 ) ;
V_38 -> V_44 -> V_60 ( V_38 ,
V_40 ) ;
F_32 ( & V_38 -> V_55 , V_53 ) ;
}
}
F_36 ( & V_38 -> V_55 , V_53 ) ;
}
F_37 ( V_33 ) ;
F_27 ( L_32 ,
V_38 -> V_44 -> V_51 () ) ;
}
static void F_42 ( struct V_2 * V_61 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
unsigned long V_53 ;
F_43 (task, &cmd->t_task_list, t_list) {
V_63 = V_65 -> V_66 ;
if ( ! V_63 )
continue;
if ( F_44 ( & V_65 -> V_67 ) )
continue;
if ( ! F_44 ( & V_65 -> V_68 ) )
continue;
F_32 ( & V_63 -> V_69 , V_53 ) ;
F_33 ( & V_65 -> V_70 ) ;
F_27 ( L_33 ,
V_61 -> V_71 -> V_72 ( V_61 ) , V_63 , V_65 ) ;
F_36 ( & V_63 -> V_69 , V_53 ) ;
F_12 ( & V_65 -> V_68 , 0 ) ;
F_45 ( & V_61 -> V_73 ) ;
}
}
static int F_46 (
struct V_2 * V_61 ,
int V_74 ,
T_3 V_75 )
{
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( F_44 ( & V_61 -> V_77 ) ) {
F_27 ( L_34
L_35 , V_78 , __LINE__ ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
V_61 -> V_79 = V_61 -> V_75 ;
V_61 -> V_75 = V_80 ;
F_12 ( & V_61 -> V_81 , 0 ) ;
if ( V_74 == 2 )
F_42 ( V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_47 ( & V_61 -> V_82 ) ;
return 1 ;
}
if ( F_44 ( & V_61 -> V_83 ) ) {
F_27 ( L_36
L_37 , V_78 , __LINE__ ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
V_61 -> V_79 = V_61 -> V_75 ;
V_61 -> V_75 = V_80 ;
if ( V_74 == 2 )
F_42 ( V_61 ) ;
if ( V_74 == 2 )
V_61 -> V_84 = NULL ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_47 ( & V_61 -> V_85 ) ;
return 1 ;
}
if ( V_74 ) {
F_12 ( & V_61 -> V_81 , 0 ) ;
if ( V_74 == 2 ) {
F_42 ( V_61 ) ;
V_61 -> V_84 = NULL ;
if ( V_61 -> V_71 -> V_86 != NULL ) {
F_36 (
& V_61 -> V_76 , V_53 ) ;
V_61 -> V_71 -> V_86 ( V_61 ) ;
return 1 ;
}
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
return 0 ;
} else if ( V_75 )
V_61 -> V_75 = V_75 ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_61 )
{
return F_46 ( V_61 , 2 , 0 ) ;
}
static void F_49 ( struct V_2 * V_61 )
{
struct V_84 * V_87 = V_61 -> V_84 ;
unsigned long V_53 ;
if ( ! V_87 )
return;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( ! F_44 ( & V_61 -> V_88 ) ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
goto V_89;
}
F_12 ( & V_61 -> V_88 , 0 ) ;
F_42 ( V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
V_89:
F_32 ( & V_87 -> V_90 , V_53 ) ;
if ( F_44 ( & V_61 -> V_91 ) ) {
F_33 ( & V_61 -> V_92 ) ;
F_12 ( & V_61 -> V_91 , 0 ) ;
#if 0
pr_debug("Removed ITT: 0x%08x from LUN LIST[%d]\n"
cmd->se_tfo->get_task_tag(cmd), lun->unpacked_lun);
#endif
}
F_36 ( & V_87 -> V_90 , V_53 ) ;
}
void F_50 ( struct V_2 * V_61 , int remove )
{
F_51 ( V_61 , & V_61 -> V_66 -> V_93 ) ;
F_49 ( V_61 ) ;
if ( F_48 ( V_61 ) )
return;
if ( remove )
F_52 ( V_61 , 0 ) ;
}
void F_53 ( struct V_2 * V_61 )
{
F_51 ( V_61 , & V_61 -> V_66 -> V_93 ) ;
if ( F_48 ( V_61 ) )
return;
F_52 ( V_61 , 0 ) ;
}
static void F_54 (
struct V_2 * V_61 ,
int V_75 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
struct V_25 * V_26 = & V_63 -> V_93 ;
unsigned long V_53 ;
F_13 ( & V_61 -> V_94 ) ;
if ( V_75 ) {
F_32 ( & V_61 -> V_76 , V_53 ) ;
V_61 -> V_75 = V_75 ;
F_12 ( & V_61 -> V_81 , 1 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
}
F_32 ( & V_26 -> V_30 , V_53 ) ;
if ( V_61 -> V_95 & V_96 ) {
V_61 -> V_95 &= ~ V_96 ;
F_55 ( & V_61 -> V_94 , & V_26 -> V_28 ) ;
} else
F_25 ( & V_61 -> V_94 , & V_26 -> V_28 ) ;
F_56 ( & V_61 -> V_97 ) ;
F_36 ( & V_26 -> V_30 , V_53 ) ;
F_56 ( & V_26 -> V_27 ) ;
F_57 ( & V_26 -> V_29 ) ;
}
static struct V_2 *
F_58 ( struct V_25 * V_26 )
{
struct V_2 * V_61 ;
unsigned long V_53 ;
F_32 ( & V_26 -> V_30 , V_53 ) ;
if ( F_34 ( & V_26 -> V_28 ) ) {
F_36 ( & V_26 -> V_30 , V_53 ) ;
return NULL ;
}
V_61 = F_59 ( & V_26 -> V_28 , struct V_2 , V_94 ) ;
F_45 ( & V_61 -> V_97 ) ;
F_33 ( & V_61 -> V_94 ) ;
F_45 ( & V_26 -> V_27 ) ;
F_36 ( & V_26 -> V_30 , V_53 ) ;
return V_61 ;
}
static void F_51 ( struct V_2 * V_61 ,
struct V_25 * V_26 )
{
struct V_2 * V_98 ;
unsigned long V_53 ;
F_32 ( & V_26 -> V_30 , V_53 ) ;
if ( ! F_44 ( & V_61 -> V_97 ) ) {
F_36 ( & V_26 -> V_30 , V_53 ) ;
return;
}
F_43 (t, &qobj->qobj_list, se_queue_node)
if ( V_98 == V_61 ) {
F_45 ( & V_61 -> V_97 ) ;
F_45 ( & V_26 -> V_27 ) ;
F_33 ( & V_61 -> V_94 ) ;
break;
}
F_36 ( & V_26 -> V_30 , V_53 ) ;
if ( F_44 ( & V_61 -> V_97 ) ) {
F_4 ( L_38 ,
V_61 -> V_71 -> V_72 ( V_61 ) ,
F_44 ( & V_61 -> V_97 ) ) ;
}
}
void F_60 ( struct V_2 * V_61 , int V_99 )
{
struct V_64 * V_65 = F_61 ( V_61 -> V_100 . V_101 ,
struct V_64 , V_102 ) ;
if ( V_99 ) {
V_61 -> V_103 = V_104 ;
V_65 -> V_105 = V_106 ;
} else {
V_65 -> V_105 = V_107 ;
V_65 -> V_108 = V_109 ;
V_65 -> V_110 -> V_111 =
V_109 ;
}
F_62 ( V_65 , V_99 ) ;
}
void F_62 ( struct V_64 * V_65 , int V_112 )
{
struct V_2 * V_61 = V_65 -> V_110 ;
struct V_62 * V_63 = V_65 -> V_66 ;
int V_75 ;
unsigned long V_53 ;
#if 0
pr_debug("task: %p CDB: 0x%02x obj_ptr: %p\n", task,
cmd->t_task_cdb[0], dev);
#endif
if ( V_63 )
F_56 ( & V_63 -> V_113 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_12 ( & V_65 -> V_67 , 0 ) ;
if ( V_63 && V_63 -> V_114 -> V_115 ) {
if ( V_63 -> V_114 -> V_115 ( V_65 ) != 0 ) {
V_61 -> V_95 |= V_116 ;
V_65 -> V_117 = 1 ;
V_112 = 1 ;
}
}
if ( F_44 ( & V_65 -> V_118 ) ) {
if ( F_44 ( & V_65 -> V_119 ) ) {
F_45 ( & V_61 -> V_120 ) ;
F_12 ( & V_65 -> V_119 , 0 ) ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_47 ( & V_65 -> V_121 ) ;
return;
}
if ( F_44 ( & V_65 -> V_119 ) ) {
if ( ! F_63 (
& V_61 -> V_122 ) ) {
F_36 ( & V_61 -> V_76 ,
V_53 ) ;
return;
}
V_75 = V_123 ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_54 ( V_61 , V_75 ) ;
return;
}
F_45 ( & V_61 -> V_122 ) ;
if ( ! F_63 ( & V_61 -> V_124 ) ) {
if ( ! V_112 )
V_61 -> V_125 = 1 ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
return;
}
if ( ! V_112 || V_61 -> V_125 ) {
V_75 = V_126 ;
if ( ! V_65 -> V_108 ) {
V_65 -> V_108 =
V_127 ;
V_61 -> V_111 =
V_127 ;
}
} else {
F_12 ( & V_61 -> V_128 , 1 ) ;
V_75 = V_129 ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_54 ( V_61 , V_75 ) ;
}
static inline int F_64 (
struct V_64 * V_65 ,
struct V_64 * V_130 ,
struct V_62 * V_63 )
{
if ( V_63 -> V_131 != V_132 ) {
F_25 ( & V_65 -> V_133 , & V_63 -> V_134 ) ;
return 0 ;
}
if ( V_65 -> V_110 -> V_135 == V_136 ) {
F_55 ( & V_65 -> V_133 ,
( V_130 != NULL ) ?
& V_130 -> V_133 :
& V_63 -> V_134 ) ;
F_27 ( L_39
L_40 ,
V_65 -> V_110 -> V_137 [ 0 ] ) ;
return 1 ;
}
F_25 ( & V_65 -> V_133 , & V_63 -> V_134 ) ;
return 0 ;
}
static void F_65 (
struct V_64 * V_65 ,
struct V_64 * V_130 ,
struct V_62 * V_63 )
{
int V_138 ;
V_138 = F_64 ( V_65 , V_130 , V_63 ) ;
F_56 ( & V_63 -> V_139 ) ;
if ( F_44 ( & V_65 -> V_68 ) )
return;
if ( V_138 )
F_55 ( & V_65 -> V_70 , ( V_130 ) ?
& V_130 -> V_70 :
& V_63 -> V_140 ) ;
else
F_25 ( & V_65 -> V_70 , & V_63 -> V_140 ) ;
F_12 ( & V_65 -> V_68 , 1 ) ;
F_27 ( L_41 ,
V_65 -> V_110 -> V_71 -> V_72 ( V_65 -> V_110 ) ,
V_65 , V_63 ) ;
}
static void F_66 ( struct V_2 * V_61 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_43 (task, &cmd->t_task_list, t_list) {
V_63 = V_65 -> V_66 ;
if ( F_44 ( & V_65 -> V_68 ) )
continue;
F_9 ( & V_63 -> V_69 ) ;
F_25 ( & V_65 -> V_70 , & V_63 -> V_140 ) ;
F_12 ( & V_65 -> V_68 , 1 ) ;
F_27 ( L_41 ,
V_65 -> V_110 -> V_71 -> V_72 (
V_65 -> V_110 ) , V_65 , V_63 ) ;
F_10 ( & V_63 -> V_69 ) ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
}
static void F_67 ( struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
struct V_64 * V_65 , * V_130 = NULL ;
unsigned long V_53 ;
F_32 ( & V_63 -> V_69 , V_53 ) ;
F_43 (task, &cmd->t_task_list, t_list) {
if ( F_44 ( & V_65 -> V_141 ) )
continue;
F_65 ( V_65 , V_130 , V_63 ) ;
F_12 ( & V_65 -> V_141 , 1 ) ;
V_130 = V_65 ;
}
F_36 ( & V_63 -> V_69 , V_53 ) ;
}
void F_68 (
struct V_64 * V_65 ,
struct V_62 * V_63 )
{
unsigned long V_53 ;
if ( F_44 ( & V_65 -> V_141 ) == 0 ) {
F_69 () ;
return;
}
F_32 ( & V_63 -> V_69 , V_53 ) ;
F_33 ( & V_65 -> V_133 ) ;
F_12 ( & V_65 -> V_141 , 0 ) ;
F_45 ( & V_63 -> V_139 ) ;
F_36 ( & V_63 -> V_69 , V_53 ) ;
}
static void F_70 ( struct V_142 * V_143 )
{
struct V_62 * V_63 = F_35 ( V_143 , struct V_62 ,
V_144 ) ;
F_71 ( V_145 ) ;
struct V_2 * V_61 , * V_146 ;
F_24 ( & V_63 -> V_147 ) ;
F_72 ( & V_63 -> V_145 , & V_145 ) ;
F_26 ( & V_63 -> V_147 ) ;
F_73 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_33 ( & V_61 -> V_148 ) ;
F_45 ( & V_63 -> V_149 ) ;
F_74 () ;
F_27 ( L_42
L_43 , V_61 -> V_71 -> V_51 () , V_61 ,
( V_61 -> V_75 == V_129 ) ? L_44 :
( V_61 -> V_75 == V_150 ) ? L_45
: L_46 ) ;
F_54 ( V_61 , V_61 -> V_75 ) ;
}
}
unsigned char * F_75 ( struct V_2 * V_61 )
{
switch ( V_61 -> V_151 ) {
case V_152 :
return L_47 ;
case V_153 :
return L_48 ;
case V_154 :
return L_49 ;
case V_155 :
return L_50 ;
default:
break;
}
return L_46 ;
}
void F_76 (
struct V_62 * V_63 ,
char * V_156 ,
int * V_157 )
{
* V_157 += sprintf ( V_156 + * V_157 , L_51 ) ;
switch ( V_63 -> V_158 ) {
case V_159 :
* V_157 += sprintf ( V_156 + * V_157 , L_52 ) ;
break;
case V_160 :
* V_157 += sprintf ( V_156 + * V_157 , L_53 ) ;
break;
case V_161 :
* V_157 += sprintf ( V_156 + * V_157 , L_54 ) ;
break;
case V_162 :
case V_163 :
* V_157 += sprintf ( V_156 + * V_157 , L_55 ) ;
break;
default:
* V_157 += sprintf ( V_156 + * V_157 , L_56 , V_63 -> V_158 ) ;
break;
}
* V_157 += sprintf ( V_156 + * V_157 , L_57 ,
F_44 ( & V_63 -> V_139 ) , F_44 ( & V_63 -> V_113 ) ,
V_63 -> V_164 ) ;
* V_157 += sprintf ( V_156 + * V_157 , L_58 ,
V_63 -> V_165 -> V_166 . V_167 , V_63 -> V_165 -> V_166 . V_168 ) ;
* V_157 += sprintf ( V_156 + * V_157 , L_59 ) ;
}
static void F_77 ( struct V_62 * V_63 )
{
struct V_2 * V_61 , * V_169 ;
int V_170 = 0 , V_75 ;
unsigned long V_53 ;
F_32 ( & V_63 -> V_93 . V_30 , V_53 ) ;
F_73 (cmd, tcmd, &dev->dev_queue_obj.qobj_list,
se_queue_node) {
V_75 = V_61 -> V_75 ;
F_33 ( & V_61 -> V_94 ) ;
F_36 ( & V_63 -> V_93 . V_30 ,
V_53 ) ;
F_4 ( L_60
L_61 ,
V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_71 -> V_171 ( V_61 ) , V_75 ) ;
F_78 ( V_61 ) ;
V_170 = 1 ;
F_32 ( & V_63 -> V_93 . V_30 , V_53 ) ;
}
F_36 ( & V_63 -> V_93 . V_30 , V_53 ) ;
#if 0
if (bug_out)
BUG();
#endif
}
void F_79 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_42 [ V_176 ] ;
int V_177 ;
memset ( V_42 , 0 , V_176 ) ;
V_177 = sprintf ( V_42 , L_62 ) ;
switch ( V_173 -> V_178 ) {
case 0x00 :
sprintf ( V_42 + V_177 , L_63 ) ;
break;
case 0x10 :
sprintf ( V_42 + V_177 , L_64 ) ;
break;
case 0x20 :
sprintf ( V_42 + V_177 , L_65 ) ;
break;
case 0x30 :
sprintf ( V_42 + V_177 , L_66 ) ;
break;
case 0x40 :
sprintf ( V_42 + V_177 , L_67
L_68 ) ;
break;
case 0x50 :
sprintf ( V_42 + V_177 , L_69 ) ;
break;
case 0x60 :
sprintf ( V_42 + V_177 , L_70 ) ;
break;
case 0x70 :
sprintf ( V_42 + V_177 , L_71
L_68 ) ;
break;
case 0x80 :
sprintf ( V_42 + V_177 , L_72 ) ;
break;
default:
sprintf ( V_42 + V_177 , L_73 ,
V_173 -> V_178 ) ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_42 , V_175 ) ;
else
F_27 ( L_74 , V_42 ) ;
}
void
F_80 ( struct V_172 * V_173 , unsigned char * V_179 )
{
if ( V_179 [ 1 ] & 0x80 ) {
V_173 -> V_178 = ( V_179 [ 0 ] & 0xf0 ) ;
V_173 -> V_180 = 1 ;
F_79 ( V_173 , NULL , 0 ) ;
}
}
int F_81 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_42 [ V_176 ] ;
int V_31 = 0 ;
int V_177 ;
memset ( V_42 , 0 , V_176 ) ;
V_177 = sprintf ( V_42 , L_75 ) ;
switch ( V_173 -> V_181 ) {
case 0x00 :
sprintf ( V_42 + V_177 , L_76 ) ;
break;
case 0x10 :
sprintf ( V_42 + V_177 , L_77 ) ;
break;
case 0x20 :
sprintf ( V_42 + V_177 , L_78 ) ;
break;
default:
sprintf ( V_42 + V_177 , L_73 , V_173 -> V_181 ) ;
V_31 = - V_182 ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_42 , V_175 ) ;
else
F_27 ( L_74 , V_42 ) ;
return V_31 ;
}
int F_82 ( struct V_172 * V_173 , unsigned char * V_179 )
{
V_173 -> V_181 = ( V_179 [ 1 ] & 0x30 ) ;
return F_81 ( V_173 , NULL , 0 ) ;
}
int F_83 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_42 [ V_176 ] ;
int V_31 = 0 ;
int V_177 ;
memset ( V_42 , 0 , V_176 ) ;
V_177 = sprintf ( V_42 , L_79 ) ;
switch ( V_173 -> V_183 ) {
case 0x00 :
sprintf ( V_42 + V_177 , L_80 ) ;
break;
case 0x01 :
sprintf ( V_42 + V_177 , L_81 ) ;
break;
case 0x02 :
sprintf ( V_42 + V_177 , L_82 ) ;
break;
case 0x03 :
sprintf ( V_42 + V_177 , L_83 ) ;
break;
case 0x04 :
sprintf ( V_42 + V_177 , L_84 ) ;
break;
case 0x08 :
sprintf ( V_42 + V_177 , L_85 ) ;
break;
default:
sprintf ( V_42 + V_177 , L_86 ,
V_173 -> V_183 ) ;
V_31 = - V_182 ;
break;
}
if ( V_174 ) {
if ( V_175 < strlen ( V_42 ) + 1 )
return - V_182 ;
strncpy ( V_174 , V_42 , V_175 ) ;
} else {
F_27 ( L_74 , V_42 ) ;
}
return V_31 ;
}
int F_84 ( struct V_172 * V_173 , unsigned char * V_179 )
{
V_173 -> V_183 = ( V_179 [ 1 ] & 0x0f ) ;
return F_83 ( V_173 , NULL , 0 ) ;
}
int F_85 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_42 [ V_176 ] ;
int V_31 = 0 ;
memset ( V_42 , 0 , V_176 ) ;
switch ( V_173 -> V_184 ) {
case 0x01 :
sprintf ( V_42 , L_87 ,
& V_173 -> V_185 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_42 , L_88 ,
& V_173 -> V_185 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_42 , L_89 ,
& V_173 -> V_185 [ 0 ] ) ;
break;
default:
sprintf ( V_42 , L_90
L_91 , V_173 -> V_184 ) ;
V_31 = - V_182 ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_42 , V_175 ) ;
else
F_27 ( L_74 , V_42 ) ;
return V_31 ;
}
int
F_86 ( struct V_172 * V_173 , unsigned char * V_179 )
{
static const char V_186 [] = L_92 ;
int V_187 = 0 , V_188 = 4 ;
V_173 -> V_184 = ( V_179 [ 0 ] & 0x0f ) ;
switch ( V_173 -> V_184 ) {
case 0x01 :
V_173 -> V_185 [ V_187 ++ ] =
V_186 [ V_173 -> V_183 ] ;
while ( V_188 < ( 4 + V_179 [ 3 ] ) ) {
V_173 -> V_185 [ V_187 ++ ] =
V_186 [ ( V_179 [ V_188 ] & 0xf0 ) >> 4 ] ;
V_173 -> V_185 [ V_187 ++ ] =
V_186 [ V_179 [ V_188 ] & 0x0f ] ;
V_188 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_188 < ( 4 + V_179 [ 3 ] ) )
V_173 -> V_185 [ V_187 ++ ] = V_179 [ V_188 ++ ] ;
break;
default:
break;
}
return F_85 ( V_173 , NULL , 0 ) ;
}
static void F_87 ( struct V_62 * V_63 )
{
if ( V_63 -> V_114 -> V_189 == V_190 ) {
V_63 -> V_131 = V_191 ;
return;
}
V_63 -> V_131 = V_132 ;
F_27 ( L_93
L_94 , V_63 -> V_114 -> V_192 ,
V_63 -> V_114 -> V_193 ( V_63 ) ) ;
}
static void F_88 ( struct V_62 * V_63 )
{
struct V_194 * V_195 = & V_63 -> V_165 -> V_194 ;
int V_188 , V_196 ;
F_27 ( L_95 ) ;
for ( V_188 = 0 ; V_188 < 8 ; V_188 ++ )
if ( V_195 -> V_197 [ V_188 ] >= 0x20 )
F_27 ( L_96 , V_195 -> V_197 [ V_188 ] ) ;
else
F_27 ( L_97 ) ;
F_27 ( L_98 ) ;
for ( V_188 = 0 ; V_188 < 16 ; V_188 ++ )
if ( V_195 -> V_198 [ V_188 ] >= 0x20 )
F_27 ( L_96 , V_195 -> V_198 [ V_188 ] ) ;
else
F_27 ( L_97 ) ;
F_27 ( L_99 ) ;
for ( V_188 = 0 ; V_188 < 4 ; V_188 ++ )
if ( V_195 -> V_199 [ V_188 ] >= 0x20 )
F_27 ( L_96 , V_195 -> V_199 [ V_188 ] ) ;
else
F_27 ( L_97 ) ;
F_27 ( L_100 ) ;
V_196 = V_63 -> V_114 -> V_200 ( V_63 ) ;
F_27 ( L_101 , F_89 ( V_196 ) ) ;
F_27 ( L_102 ,
V_63 -> V_114 -> V_193 ( V_63 ) ) ;
}
struct V_62 * F_90 (
struct V_201 * V_202 ,
struct V_203 * V_114 ,
struct V_204 * V_66 ,
T_1 V_205 ,
void * V_206 ,
struct V_207 * V_208 ,
const char * V_209 ,
const char * V_210 )
{
int V_211 ;
struct V_62 * V_63 ;
V_63 = F_91 ( sizeof( struct V_62 ) , V_34 ) ;
if ( ! V_63 ) {
F_4 ( L_103 ) ;
return NULL ;
}
F_11 ( & V_63 -> V_93 ) ;
V_63 -> V_212 = V_205 ;
V_63 -> V_158 |= V_160 ;
V_63 -> V_213 = V_206 ;
V_63 -> V_201 = V_202 ;
V_63 -> V_165 = V_66 ;
V_63 -> V_114 = V_114 ;
F_12 ( & V_63 -> V_214 , 0 ) ;
F_13 ( & V_63 -> V_215 ) ;
F_13 ( & V_63 -> V_216 ) ;
F_13 ( & V_63 -> V_217 ) ;
F_13 ( & V_63 -> V_134 ) ;
F_13 ( & V_63 -> V_218 ) ;
F_13 ( & V_63 -> V_219 ) ;
F_13 ( & V_63 -> V_140 ) ;
F_13 ( & V_63 -> V_145 ) ;
F_15 ( & V_63 -> V_69 ) ;
F_15 ( & V_63 -> V_220 ) ;
F_15 ( & V_63 -> V_221 ) ;
F_15 ( & V_63 -> V_222 ) ;
F_15 ( & V_63 -> V_223 ) ;
F_15 ( & V_63 -> V_224 ) ;
F_15 ( & V_63 -> V_225 ) ;
F_15 ( & V_63 -> V_226 ) ;
F_15 ( & V_63 -> V_227 ) ;
F_15 ( & V_63 -> V_228 ) ;
F_15 ( & V_63 -> V_147 ) ;
V_63 -> V_164 = V_208 -> V_164 ;
F_12 ( & V_63 -> V_113 , V_63 -> V_164 ) ;
F_12 ( & V_63 -> V_229 , 0 ) ;
F_92 ( V_63 , V_208 ) ;
V_63 -> V_230 = F_7 ( V_231 ) ;
V_63 -> V_232 = F_93 () ;
F_15 ( & V_63 -> V_233 ) ;
F_9 ( & V_202 -> V_234 ) ;
F_25 ( & V_63 -> V_215 , & V_202 -> V_235 ) ;
V_202 -> V_236 ++ ;
F_10 ( & V_202 -> V_234 ) ;
F_87 ( V_63 ) ;
V_211 = ( V_202 -> V_237 & V_238 ) ;
F_94 ( V_63 , V_211 ) ;
if ( F_95 ( V_63 , V_211 ) < 0 )
goto V_3;
V_63 -> V_239 = F_96 ( V_240 , V_63 ,
L_104 , V_63 -> V_114 -> V_192 ) ;
if ( F_97 ( V_63 -> V_239 ) ) {
F_4 ( L_105 ,
V_63 -> V_114 -> V_192 ) ;
goto V_3;
}
F_98 ( & V_63 -> V_144 , F_70 ) ;
if ( V_63 -> V_114 -> V_189 != V_190 ) {
if ( ! V_209 || ! V_210 ) {
F_4 ( L_106
L_107 ) ;
goto V_3;
}
strncpy ( & V_63 -> V_165 -> V_194 . V_197 [ 0 ] , L_108 , 8 ) ;
strncpy ( & V_63 -> V_165 -> V_194 . V_198 [ 0 ] , V_209 , 16 ) ;
strncpy ( & V_63 -> V_165 -> V_194 . V_199 [ 0 ] , V_210 , 4 ) ;
}
F_88 ( V_63 ) ;
return V_63 ;
V_3:
F_99 ( V_63 -> V_239 ) ;
F_9 ( & V_202 -> V_234 ) ;
F_33 ( & V_63 -> V_215 ) ;
V_202 -> V_236 -- ;
F_10 ( & V_202 -> V_234 ) ;
F_100 ( V_63 ) ;
F_101 ( V_63 ) ;
return NULL ;
}
static inline void F_102 (
unsigned char * V_241 )
{
switch ( V_241 [ 0 ] ) {
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
break;
default:
V_241 [ 1 ] &= 0x1f ;
break;
}
}
static struct V_64 *
F_103 ( struct V_2 * V_61 ,
enum V_250 V_151 )
{
struct V_64 * V_65 ;
struct V_62 * V_63 = V_61 -> V_66 ;
V_65 = V_63 -> V_114 -> V_251 ( V_61 -> V_137 ) ;
if ( ! V_65 ) {
F_4 ( L_109 ) ;
return NULL ;
}
F_13 ( & V_65 -> V_102 ) ;
F_13 ( & V_65 -> V_133 ) ;
F_13 ( & V_65 -> V_70 ) ;
F_104 ( & V_65 -> V_121 ) ;
V_65 -> V_110 = V_61 ;
V_65 -> V_66 = V_63 ;
V_65 -> V_252 = V_151 ;
return V_65 ;
}
void F_105 (
struct V_2 * V_61 ,
struct V_253 * V_254 ,
struct V_7 * V_33 ,
T_1 V_255 ,
int V_151 ,
int V_256 ,
unsigned char * V_257 )
{
F_13 ( & V_61 -> V_92 ) ;
F_13 ( & V_61 -> V_258 ) ;
F_13 ( & V_61 -> V_259 ) ;
F_13 ( & V_61 -> V_148 ) ;
F_13 ( & V_61 -> V_100 ) ;
F_104 ( & V_61 -> V_260 ) ;
F_104 ( & V_61 -> V_82 ) ;
F_104 ( & V_61 -> V_85 ) ;
F_15 ( & V_61 -> V_76 ) ;
F_12 ( & V_61 -> V_88 , 1 ) ;
V_61 -> V_71 = V_254 ;
V_61 -> V_33 = V_33 ;
V_61 -> V_255 = V_255 ;
V_61 -> V_151 = V_151 ;
V_61 -> V_135 = V_256 ;
V_61 -> V_257 = V_257 ;
}
static int F_106 ( struct V_2 * V_61 )
{
if ( V_61 -> V_66 -> V_131 != V_132 )
return 0 ;
if ( V_61 -> V_135 == V_261 ) {
F_27 ( L_110
L_111 ) ;
return - V_182 ;
}
V_61 -> V_262 = F_107 ( & V_61 -> V_66 -> V_229 ) ;
F_108 () ;
F_27 ( L_112 ,
V_61 -> V_262 , V_61 -> V_135 ,
V_61 -> V_66 -> V_114 -> V_192 ) ;
return 0 ;
}
void F_109 (
struct V_2 * V_2 )
{
if ( V_2 -> V_5 )
F_110 ( V_2 -> V_5 ) ;
if ( V_2 -> V_137 != V_2 -> V_263 )
F_101 ( V_2 -> V_137 ) ;
}
int F_111 (
struct V_2 * V_61 ,
unsigned char * V_241 )
{
int V_31 ;
F_102 ( V_241 ) ;
V_61 -> V_264 = & V_265 ;
if ( F_112 ( V_241 ) > V_266 ) {
F_4 ( L_113
L_114 ,
F_112 ( V_241 ) , V_266 ) ;
return - V_182 ;
}
if ( F_112 ( V_241 ) > sizeof( V_61 -> V_263 ) ) {
V_61 -> V_137 = F_91 ( F_112 ( V_241 ) ,
V_34 ) ;
if ( ! V_61 -> V_137 ) {
F_4 ( L_115
L_116 ,
F_112 ( V_241 ) ,
( unsigned long ) sizeof( V_61 -> V_263 ) ) ;
return - V_20 ;
}
} else
V_61 -> V_137 = & V_61 -> V_263 [ 0 ] ;
memcpy ( V_61 -> V_137 , V_241 , F_112 ( V_241 ) ) ;
V_31 = F_113 ( V_61 , V_241 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( F_106 ( V_61 ) < 0 ) {
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 = V_269 ;
return - V_182 ;
}
F_9 ( & V_61 -> V_84 -> V_270 ) ;
if ( V_61 -> V_84 -> V_271 )
V_61 -> V_84 -> V_271 -> V_272 . V_273 ++ ;
F_10 ( & V_61 -> V_84 -> V_270 ) ;
return 0 ;
}
int F_114 (
struct V_2 * V_61 )
{
if ( ! V_61 -> V_84 ) {
F_69 () ;
F_4 ( L_117 ) ;
return - V_182 ;
}
F_54 ( V_61 , V_274 ) ;
return 0 ;
}
int F_115 (
struct V_2 * V_61 )
{
int V_31 ;
if ( ! V_61 -> V_84 ) {
F_69 () ;
F_4 ( L_117 ) ;
return - V_182 ;
}
if ( F_116 () ) {
F_69 () ;
F_4 ( L_118
L_119 ) ;
return - V_182 ;
}
V_61 -> V_75 = V_274 ;
F_12 ( & V_61 -> V_81 , 1 ) ;
V_31 = F_117 ( V_61 ) ;
if ( V_31 == - V_275 )
return 0 ;
else if ( V_31 < 0 ) {
V_61 -> V_111 = V_31 ;
F_118 ( V_61 , NULL , 0 ,
( V_61 -> V_151 != V_154 ) ) ;
}
return 0 ;
}
int F_119 (
struct V_2 * V_61 )
{
if ( ! V_61 -> V_84 ) {
F_69 () ;
F_4 ( L_117 ) ;
return - V_182 ;
}
F_54 ( V_61 , V_276 ) ;
return 0 ;
}
int F_120 (
struct V_2 * V_61 )
{
if ( ! F_116 () && F_121 ( V_277 ) )
return - V_278 ;
if ( F_122 ( V_61 , 1 ) != 0 )
return 0 ;
F_54 ( V_61 , V_279 ) ;
return 0 ;
}
int F_123 (
struct V_2 * V_61 )
{
V_61 -> V_264 = & V_265 ;
F_54 ( V_61 , V_280 ) ;
return 0 ;
}
void F_124 (
struct V_2 * V_61 )
{
F_54 ( V_61 , V_281 ) ;
}
static int F_125 ( struct V_2 * V_61 )
{
struct V_64 * V_65 , * V_282 ;
unsigned long V_53 ;
int V_31 = 0 ;
F_27 ( L_120 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_73 (task, task_tmp,
&cmd->t_task_list, t_list) {
F_27 ( L_121 ,
V_65 -> V_283 , V_65 ) ;
if ( ! F_44 ( & V_65 -> V_284 ) &&
! F_44 ( & V_65 -> V_67 ) ) {
F_36 ( & V_61 -> V_76 ,
V_53 ) ;
F_68 ( V_65 ,
V_65 -> V_66 ) ;
F_27 ( L_122 ,
V_65 -> V_283 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
continue;
}
if ( F_44 ( & V_65 -> V_67 ) ) {
F_12 ( & V_65 -> V_118 , 1 ) ;
F_36 ( & V_61 -> V_76 ,
V_53 ) ;
F_27 ( L_123 ,
V_65 -> V_283 ) ;
F_126 ( & V_65 -> V_121 ) ;
F_27 ( L_124 ,
V_65 -> V_283 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_45 ( & V_61 -> V_124 ) ;
F_12 ( & V_65 -> V_67 , 0 ) ;
F_12 ( & V_65 -> V_118 , 0 ) ;
} else {
F_27 ( L_125 , V_65 -> V_283 ) ;
V_31 ++ ;
}
F_127 ( V_65 , & V_53 ) ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
return V_31 ;
}
static void F_118 (
struct V_2 * V_61 ,
struct V_62 * V_63 ,
int F_47 ,
int V_285 )
{
int V_31 = 0 ;
F_27 ( L_126
L_127 , V_61 , V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_137 [ 0 ] ) ;
F_27 ( L_128
L_129 ,
V_61 -> V_71 -> V_171 ( V_61 ) ,
V_61 -> V_75 , V_61 -> V_79 ,
V_61 -> V_111 ) ;
F_27 ( L_130
L_131
L_132
L_133 , V_61 -> V_286 ,
F_44 ( & V_61 -> V_124 ) ,
F_44 ( & V_61 -> V_287 ) ,
F_44 ( & V_61 -> V_73 ) ,
F_44 ( & V_61 -> V_81 ) ,
F_44 ( & V_61 -> V_83 ) ,
F_44 ( & V_61 -> V_288 ) ) ;
F_128 ( V_61 ) ;
if ( V_63 )
F_56 ( & V_63 -> V_113 ) ;
if ( V_61 -> V_66 -> V_131 == V_132 )
F_129 ( V_61 ) ;
if ( F_47 ) {
F_130 ( V_61 ) ;
V_61 -> V_111 = V_289 ;
}
switch ( V_61 -> V_111 ) {
case V_127 :
V_61 -> V_268 = V_290 ;
break;
case V_291 :
V_61 -> V_268 = V_292 ;
break;
case V_293 :
V_61 -> V_268 = V_269 ;
break;
case V_294 :
V_61 -> V_268 = V_295 ;
break;
case V_296 :
if ( ! V_285 )
F_131 ( V_61 ) ;
V_61 -> V_71 -> V_297 ( V_61 -> V_33 ) ;
V_61 -> V_71 -> V_298 ( V_61 -> V_33 , 0 , 0 ) ;
goto V_299;
case V_289 :
case V_109 :
V_61 -> V_268 = V_300 ;
break;
case V_301 :
V_61 -> V_268 = V_302 ;
break;
case V_303 :
V_61 -> V_268 = V_304 ;
break;
case V_305 :
V_61 -> V_103 = V_306 ;
if ( V_61 -> V_33 &&
V_61 -> V_66 -> V_165 -> V_166 . V_307 == 2 )
F_132 ( V_61 -> V_33 -> V_39 ,
V_61 -> V_308 , 0x2C ,
V_309 ) ;
V_31 = V_61 -> V_71 -> V_310 ( V_61 ) ;
if ( V_31 == - V_275 )
goto V_311;
goto V_299;
case V_312 :
break;
default:
F_4 ( L_134 ,
V_61 -> V_137 [ 0 ] ,
V_61 -> V_111 ) ;
V_61 -> V_268 = V_290 ;
break;
}
if ( ! V_285 && ! V_61 -> V_71 -> V_313 )
F_131 ( V_61 ) ;
else {
V_31 = F_133 ( V_61 ,
V_61 -> V_268 , 0 ) ;
if ( V_31 == - V_275 )
goto V_311;
}
V_299:
F_49 ( V_61 ) ;
if ( ! F_48 ( V_61 ) )
;
return;
V_311:
V_61 -> V_75 = V_129 ;
F_134 ( V_61 , V_61 -> V_66 , V_314 ) ;
}
static void F_130 ( struct V_2 * V_61 )
{
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( ! F_44 ( & V_61 -> V_315 ) ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
return;
}
if ( F_44 ( & V_61 -> V_122 ) ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
return;
}
F_135 ( F_44 ( & V_61 -> V_315 ) ,
& V_61 -> V_120 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
}
static void F_136 ( struct V_2 * V_61 )
{
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( F_44 ( & V_61 -> V_315 ) > 1 ) {
int V_316 = ( F_44 ( & V_61 -> V_315 ) - 1 ) ;
F_135 ( V_316 , & V_61 -> V_120 ) ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_52 ( V_61 , 0 ) ;
}
static inline T_1 F_137 ( unsigned char * V_241 )
{
return ( ( V_241 [ 1 ] & 0x1f ) << 16 ) | ( V_241 [ 2 ] << 8 ) | V_241 [ 3 ] ;
}
static inline T_1 F_138 ( unsigned char * V_241 )
{
return ( V_241 [ 2 ] << 24 ) | ( V_241 [ 3 ] << 16 ) | ( V_241 [ 4 ] << 8 ) | V_241 [ 5 ] ;
}
static inline unsigned long long F_139 ( unsigned char * V_241 )
{
unsigned int V_317 , V_318 ;
V_317 = ( V_241 [ 2 ] << 24 ) | ( V_241 [ 3 ] << 16 ) | ( V_241 [ 4 ] << 8 ) | V_241 [ 5 ] ;
V_318 = ( V_241 [ 6 ] << 24 ) | ( V_241 [ 7 ] << 16 ) | ( V_241 [ 8 ] << 8 ) | V_241 [ 9 ] ;
return ( ( unsigned long long ) V_318 ) | ( unsigned long long ) V_317 << 32 ;
}
static inline unsigned long long F_140 ( unsigned char * V_241 )
{
unsigned int V_317 , V_318 ;
V_317 = ( V_241 [ 12 ] << 24 ) | ( V_241 [ 13 ] << 16 ) | ( V_241 [ 14 ] << 8 ) | V_241 [ 15 ] ;
V_318 = ( V_241 [ 16 ] << 24 ) | ( V_241 [ 17 ] << 16 ) | ( V_241 [ 18 ] << 8 ) | V_241 [ 19 ] ;
return ( ( unsigned long long ) V_318 ) | ( unsigned long long ) V_317 << 32 ;
}
static void F_141 ( struct V_2 * V_2 )
{
unsigned long V_53 ;
F_32 ( & V_2 -> V_76 , V_53 ) ;
V_2 -> V_95 |= V_319 ;
F_36 ( & V_2 -> V_76 , V_53 ) ;
}
static void F_142 ( unsigned long V_320 )
{
struct V_64 * V_65 = (struct V_64 * ) V_320 ;
struct V_2 * V_61 = V_65 -> V_110 ;
unsigned long V_53 ;
F_27 ( L_135 , V_65 , V_61 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( V_65 -> V_321 & V_322 ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
return;
}
V_65 -> V_321 &= ~ V_323 ;
if ( ! F_44 ( & V_65 -> V_67 ) ) {
F_27 ( L_136
L_137 , V_65 , V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
return;
}
F_56 ( & V_61 -> V_120 ) ;
F_56 ( & V_61 -> V_315 ) ;
V_61 -> V_125 = 1 ;
F_12 ( & V_65 -> V_119 , 1 ) ;
V_65 -> V_108 = V_324 ;
V_65 -> V_105 = 1 ;
if ( F_44 ( & V_65 -> V_118 ) ) {
F_27 ( L_138
L_139 , V_65 , V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_47 ( & V_65 -> V_121 ) ;
return;
}
if ( ! F_63 ( & V_61 -> V_124 ) ) {
F_27 ( L_140
L_141 , V_65 , V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
return;
}
F_27 ( L_142 ,
V_65 , V_61 ) ;
V_61 -> V_75 = V_126 ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_54 ( V_61 , V_126 ) ;
}
static void F_143 ( struct V_64 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_66 ;
int V_325 ;
if ( V_65 -> V_321 & V_323 )
return;
V_325 = V_63 -> V_165 -> V_166 . V_119 ;
if ( ! V_325 )
return;
F_144 ( & V_65 -> V_326 ) ;
V_65 -> V_326 . V_327 = ( F_93 () + V_325 * V_328 ) ;
V_65 -> V_326 . V_320 = ( unsigned long ) V_65 ;
V_65 -> V_326 . V_329 = F_142 ;
V_65 -> V_321 |= V_323 ;
F_145 ( & V_65 -> V_326 ) ;
#if 0
pr_debug("Starting task timer for cmd: %p task: %p seconds:"
" %d\n", task->task_se_cmd, task, timeout);
#endif
}
void F_127 ( struct V_64 * V_65 , unsigned long * V_53 )
{
struct V_2 * V_61 = V_65 -> V_110 ;
if ( ! V_65 -> V_321 & V_323 )
return;
V_65 -> V_321 |= V_322 ;
F_36 ( & V_61 -> V_76 , * V_53 ) ;
F_146 ( & V_65 -> V_326 ) ;
F_32 ( & V_61 -> V_76 , * V_53 ) ;
V_65 -> V_321 &= ~ V_323 ;
V_65 -> V_321 &= ~ V_322 ;
}
static void F_128 ( struct V_2 * V_61 )
{
struct V_64 * V_65 = NULL , * V_282 ;
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_73 (task, task_tmp,
&cmd->t_task_list, t_list)
F_127 ( V_65 , & V_53 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
}
static inline int F_147 ( struct V_62 * V_63 )
{
if ( V_63 -> V_330 ++ <
V_331 ) {
F_148 ( V_332 ) ;
} else
F_148 ( V_333 ) ;
F_57 ( & V_63 -> V_93 . V_29 ) ;
return 0 ;
}
static inline int F_149 ( struct V_2 * V_61 )
{
if ( V_61 -> V_66 -> V_131 != V_132 )
return 1 ;
if ( V_61 -> V_135 == V_136 ) {
F_56 ( & V_61 -> V_66 -> V_334 ) ;
F_108 () ;
F_27 ( L_143
L_144 ,
V_61 -> V_137 [ 0 ] ,
V_61 -> V_262 ) ;
return 1 ;
} else if ( V_61 -> V_135 == V_335 ) {
F_9 ( & V_61 -> V_66 -> V_221 ) ;
F_25 ( & V_61 -> V_259 ,
& V_61 -> V_66 -> V_219 ) ;
F_10 ( & V_61 -> V_66 -> V_221 ) ;
F_56 ( & V_61 -> V_66 -> V_336 ) ;
F_108 () ;
F_27 ( L_145
L_146 ,
V_61 -> V_137 [ 0 ] ,
V_61 -> V_262 ) ;
if ( ! F_44 ( & V_61 -> V_66 -> V_337 ) )
return 1 ;
} else {
F_56 ( & V_61 -> V_66 -> V_337 ) ;
F_108 () ;
}
if ( F_44 ( & V_61 -> V_66 -> V_336 ) != 0 ) {
F_9 ( & V_61 -> V_66 -> V_220 ) ;
V_61 -> V_95 |= V_338 ;
F_25 ( & V_61 -> V_258 ,
& V_61 -> V_66 -> V_218 ) ;
F_10 ( & V_61 -> V_66 -> V_220 ) ;
F_27 ( L_147
L_148 ,
V_61 -> V_137 [ 0 ] , V_61 -> V_135 ,
V_61 -> V_262 ) ;
return 0 ;
}
return 1 ;
}
static int F_150 ( struct V_2 * V_61 )
{
int V_339 ;
if ( F_151 ( V_61 -> V_340 ) != 0 ) {
V_61 -> V_111 = V_289 ;
F_118 ( V_61 , NULL , 0 , 1 ) ;
return 0 ;
}
if ( ! F_46 ( V_61 , 0 , V_341 ) ) {
V_339 = F_149 ( V_61 ) ;
if ( ! V_339 )
goto V_139;
F_67 ( V_61 ) ;
}
V_139:
F_152 ( V_61 -> V_66 ) ;
return 0 ;
}
static int F_152 ( struct V_62 * V_63 )
{
int error ;
struct V_2 * V_61 = NULL ;
struct V_64 * V_65 = NULL ;
unsigned long V_53 ;
V_342:
if ( ! F_44 ( & V_63 -> V_113 ) )
return F_147 ( V_63 ) ;
V_63 -> V_330 = 0 ;
F_24 ( & V_63 -> V_69 ) ;
if ( F_34 ( & V_63 -> V_134 ) ) {
F_26 ( & V_63 -> V_69 ) ;
return 0 ;
}
V_65 = F_59 ( & V_63 -> V_134 ,
struct V_64 , V_133 ) ;
F_33 ( & V_65 -> V_133 ) ;
F_12 ( & V_65 -> V_141 , 0 ) ;
F_45 ( & V_63 -> V_139 ) ;
F_26 ( & V_63 -> V_69 ) ;
F_45 ( & V_63 -> V_113 ) ;
V_61 = V_65 -> V_110 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_12 ( & V_65 -> V_67 , 1 ) ;
F_12 ( & V_65 -> V_284 , 1 ) ;
F_56 ( & V_61 -> V_287 ) ;
if ( F_44 ( & V_61 -> V_287 ) ==
V_61 -> V_286 )
F_12 ( & V_61 -> V_343 , 1 ) ;
F_143 ( V_65 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
if ( V_61 -> V_344 ) {
error = V_61 -> V_344 ( V_61 ) ;
if ( error != 0 ) {
V_61 -> V_111 = error ;
F_12 ( & V_65 -> V_67 , 0 ) ;
F_12 ( & V_61 -> V_343 , 0 ) ;
F_125 ( V_61 ) ;
F_118 ( V_61 , V_63 , 0 , 1 ) ;
goto V_342;
}
if ( ! ( V_61 -> V_95 & V_345 ) ) {
V_61 -> V_103 = V_104 ;
V_65 -> V_105 = V_106 ;
F_62 ( V_65 , 1 ) ;
}
} else {
if ( ( V_63 -> V_114 -> V_189 != V_190 ) &&
( ! ( V_65 -> V_110 -> V_95 & V_346 ) ) )
error = F_153 ( V_65 ) ;
else
error = V_63 -> V_114 -> V_347 ( V_65 ) ;
if ( error != 0 ) {
V_61 -> V_111 = error ;
F_12 ( & V_65 -> V_67 , 0 ) ;
F_12 ( & V_61 -> V_343 , 0 ) ;
F_125 ( V_61 ) ;
F_118 ( V_61 , V_63 , 0 , 1 ) ;
}
}
goto V_342;
return 0 ;
}
void F_131 ( struct V_2 * V_2 )
{
unsigned long V_53 ;
F_32 ( & V_2 -> V_76 , V_53 ) ;
V_2 -> V_95 |= V_348 ;
V_2 -> V_95 |= V_267 ;
F_36 ( & V_2 -> V_76 , V_53 ) ;
}
static inline T_1 F_154 (
unsigned char * V_241 ,
struct V_2 * V_61 ,
int * V_31 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
if ( ! V_63 )
goto V_349;
if ( V_63 -> V_114 -> V_200 ( V_63 ) == V_350 )
return ( T_1 ) ( V_241 [ 2 ] << 16 ) + ( V_241 [ 3 ] << 8 ) + V_241 [ 4 ] ;
V_349:
return ( T_1 ) V_241 [ 4 ] ;
}
static inline T_1 F_155 (
unsigned char * V_241 ,
struct V_2 * V_61 ,
int * V_31 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
if ( ! V_63 )
goto V_349;
if ( V_63 -> V_114 -> V_200 ( V_63 ) == V_350 ) {
* V_31 = - V_182 ;
return 0 ;
}
V_349:
return ( T_1 ) ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
}
static inline T_1 F_156 (
unsigned char * V_241 ,
struct V_2 * V_61 ,
int * V_31 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
if ( ! V_63 )
goto V_349;
if ( V_63 -> V_114 -> V_200 ( V_63 ) == V_350 ) {
* V_31 = - V_182 ;
return 0 ;
}
V_349:
return ( T_1 ) ( V_241 [ 6 ] << 24 ) + ( V_241 [ 7 ] << 16 ) + ( V_241 [ 8 ] << 8 ) + V_241 [ 9 ] ;
}
static inline T_1 F_157 (
unsigned char * V_241 ,
struct V_2 * V_61 ,
int * V_31 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
if ( ! V_63 )
goto V_349;
if ( V_63 -> V_114 -> V_200 ( V_63 ) == V_350 )
return ( T_1 ) ( V_241 [ 12 ] << 16 ) + ( V_241 [ 13 ] << 8 ) + V_241 [ 14 ] ;
V_349:
return ( T_1 ) ( V_241 [ 10 ] << 24 ) + ( V_241 [ 11 ] << 16 ) +
( V_241 [ 12 ] << 8 ) + V_241 [ 13 ] ;
}
static inline T_1 F_158 (
unsigned char * V_241 ,
struct V_2 * V_61 ,
int * V_31 )
{
return ( T_1 ) ( V_241 [ 28 ] << 24 ) + ( V_241 [ 29 ] << 16 ) +
( V_241 [ 30 ] << 8 ) + V_241 [ 31 ] ;
}
static inline T_1 F_159 (
T_1 V_351 ,
unsigned char * V_241 ,
struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
if ( V_63 -> V_114 -> V_200 ( V_63 ) == V_350 ) {
if ( V_241 [ 1 ] & 1 ) {
return V_63 -> V_165 -> V_166 . V_167 * V_351 ;
} else
return V_351 ;
}
#if 0
pr_debug("Returning block_size: %u, sectors: %u == %u for"
" %s object\n", dev->se_sub_dev->se_dev_attrib.block_size, sectors,
dev->se_sub_dev->se_dev_attrib.block_size * sectors,
dev->transport->name);
#endif
return V_63 -> V_165 -> V_166 . V_167 * V_351 ;
}
static void F_160 ( struct V_2 * V_61 )
{
unsigned char * V_42 , * V_352 ;
struct V_353 * V_354 ;
unsigned int V_355 ;
int V_188 ;
int V_356 ;
V_42 = F_161 ( V_61 -> V_255 , V_34 ) ;
if ( ! V_42 ) {
F_4 ( L_149 ) ;
return;
}
F_162 ( V_61 -> V_357 ,
V_61 -> V_358 ,
V_42 ,
V_61 -> V_255 ) ;
V_355 = 0 ;
F_163 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_352 = F_164 ( F_165 ( V_354 ) , V_359 ) ;
if ( ! V_352 )
goto V_3;
for ( V_188 = 0 ; V_188 < V_354 -> V_360 ; V_188 ++ )
* ( V_352 + V_354 -> V_355 + V_188 ) ^= * ( V_42 + V_355 + V_188 ) ;
V_355 += V_354 -> V_360 ;
F_166 ( V_352 , V_359 ) ;
}
V_3:
F_101 ( V_42 ) ;
}
static int F_167 ( struct V_2 * V_61 )
{
unsigned char * V_361 = V_61 -> V_257 , * V_257 = NULL ;
struct V_62 * V_63 ;
struct V_64 * V_65 = NULL , * V_282 ;
unsigned long V_53 ;
T_1 V_355 = 0 ;
F_168 ( ! V_61 -> V_84 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( V_61 -> V_95 & V_362 ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
return 0 ;
}
F_73 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! V_65 -> V_117 )
continue;
V_63 = V_65 -> V_66 ;
if ( ! V_63 )
continue;
if ( ! V_63 -> V_114 -> V_363 ) {
F_4 ( L_150
L_151 ) ;
continue;
}
V_257 = V_63 -> V_114 -> V_363 ( V_65 ) ;
if ( ! V_257 ) {
F_4 ( L_152
L_153 ,
V_61 -> V_71 -> V_72 ( V_61 ) , V_65 -> V_283 ) ;
continue;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
V_355 = V_61 -> V_71 -> V_364 ( V_61 ,
V_365 ) ;
memcpy ( & V_361 [ V_355 ] , V_257 ,
V_365 ) ;
V_61 -> V_103 = V_65 -> V_105 ;
V_61 -> V_366 =
( V_365 + V_355 ) ;
F_27 ( L_154
L_155 ,
V_63 -> V_201 -> V_367 , V_63 -> V_114 -> V_192 ,
V_61 -> V_103 ) ;
return 0 ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
return - 1 ;
}
static int
F_169 ( struct V_2 * V_61 )
{
V_61 -> V_264 = & V_368 ;
V_61 -> V_95 |= V_267 ;
V_61 -> V_95 |= V_369 ;
V_61 -> V_103 = V_306 ;
if ( V_61 -> V_33 &&
V_61 -> V_66 -> V_165 -> V_166 . V_307 == 2 )
F_132 ( V_61 -> V_33 -> V_39 ,
V_61 -> V_308 , 0x2C ,
V_309 ) ;
return - V_182 ;
}
static inline long long F_170 ( struct V_62 * V_63 )
{
return V_63 -> V_114 -> V_370 ( V_63 ) + 1 ;
}
static int F_171 ( struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
T_1 V_351 ;
if ( V_63 -> V_114 -> V_200 ( V_63 ) != V_371 )
return 0 ;
V_351 = ( V_61 -> V_255 / V_63 -> V_165 -> V_166 . V_167 ) ;
if ( ( V_61 -> V_372 + V_351 ) > F_170 ( V_63 ) ) {
F_4 ( L_156
L_157 ,
V_61 -> V_372 , V_351 ,
F_170 ( V_63 ) ) ;
return - V_182 ;
}
return 0 ;
}
static int F_172 ( unsigned char * V_53 , struct V_62 * V_63 )
{
int V_373 = ( V_63 -> V_114 -> V_189 ==
V_190 ) ;
if ( ! V_373 ) {
if ( ( V_53 [ 0 ] & 0x04 ) || ( V_53 [ 0 ] & 0x02 ) ) {
F_4 ( L_158
L_159
L_160 ) ;
return - V_374 ;
}
if ( ! ( V_53 [ 0 ] & 0x08 ) ) {
F_4 ( L_161
L_162 ) ;
return - V_374 ;
}
}
return 0 ;
}
static int F_113 (
struct V_2 * V_61 ,
unsigned char * V_241 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
struct V_204 * V_375 = V_63 -> V_165 ;
int V_31 = 0 , V_376 = 0 , V_373 ;
T_1 V_351 = 0 , V_377 = 0 , V_378 = 0 ;
T_4 V_379 ;
T_3 V_380 = 0 ;
if ( F_173 ( V_61 , V_241 ) < 0 ) {
V_61 -> V_264 =
& V_368 ;
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 = V_381 ;
return - V_182 ;
}
V_31 = V_375 -> V_382 . V_383 ( V_61 , V_241 , & V_380 ) ;
if ( V_31 != 0 ) {
V_61 -> V_264 = & V_368 ;
if ( V_31 > 0 ) {
#if 0
pr_debug("[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
#endif
F_174 ( V_61 , 0x04 , V_380 ) ;
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 = V_384 ;
return - V_182 ;
}
goto V_385;
}
if ( V_375 -> V_386 . V_387 . V_388 ( V_61 , & V_378 ) != 0 ) {
if ( V_375 -> V_386 . V_387 . V_389 (
V_61 , V_241 , V_378 ) != 0 )
return F_169 ( V_61 ) ;
}
switch ( V_241 [ 0 ] ) {
case V_390 :
V_351 = F_154 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_393 ;
V_61 -> V_372 = F_137 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_242 :
V_351 = F_155 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_394 ;
V_61 -> V_372 = F_138 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_243 :
V_351 = F_156 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_395 ;
V_61 -> V_372 = F_138 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_244 :
V_351 = F_157 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_396 ;
V_61 -> V_372 = F_139 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_397 :
V_351 = F_154 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_393 ;
V_61 -> V_372 = F_137 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_398 :
V_351 = F_155 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_394 ;
V_61 -> V_372 = F_138 ( V_241 ) ;
V_61 -> V_399 = ( V_241 [ 1 ] & 0x8 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_400 :
V_351 = F_156 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_395 ;
V_61 -> V_372 = F_138 ( V_241 ) ;
V_61 -> V_399 = ( V_241 [ 1 ] & 0x8 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_401 :
V_351 = F_157 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_396 ;
V_61 -> V_372 = F_139 ( V_241 ) ;
V_61 -> V_399 = ( V_241 [ 1 ] & 0x8 ) ;
V_61 -> V_95 |= V_346 ;
break;
case V_402 :
if ( ( V_61 -> V_151 != V_154 ) ||
! ( V_61 -> V_403 ) )
goto V_385;
V_351 = F_155 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_394 ;
V_61 -> V_372 = F_138 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
V_373 = ( V_63 -> V_114 -> V_189 ==
V_190 ) ;
if ( V_373 )
break;
V_61 -> V_404 = & F_160 ;
V_61 -> V_399 = ( V_241 [ 1 ] & 0x8 ) ;
break;
case V_405 :
V_379 = F_175 ( & V_241 [ 8 ] ) ;
V_373 = ( V_63 -> V_114 -> V_189 ==
V_190 ) ;
switch ( V_379 ) {
case V_406 :
V_351 = F_158 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_392 = & V_407 ;
V_61 -> V_372 = F_140 ( V_241 ) ;
V_61 -> V_95 |= V_346 ;
if ( V_373 )
break;
V_61 -> V_404 = & F_160 ;
V_61 -> V_399 = ( V_241 [ 10 ] & 0x8 ) ;
break;
case V_408 :
V_351 = F_158 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
if ( V_351 )
V_377 = F_159 ( 1 , V_241 , V_61 ) ;
else {
F_4 ( L_163
L_164 ) ;
goto V_385;
}
V_61 -> V_372 = F_23 ( & V_241 [ 12 ] ) ;
V_61 -> V_95 |= V_409 ;
if ( F_172 ( & V_241 [ 10 ] , V_63 ) < 0 )
goto V_385;
break;
default:
F_4 ( L_165
L_166 , V_379 ) ;
goto V_391;
}
break;
case V_410 :
if ( V_63 -> V_114 -> V_200 ( V_63 ) != V_411 ) {
if ( V_241 [ 1 ] == V_412 ) {
V_61 -> V_344 =
( V_375 -> V_382 . V_413 ==
V_414 ) ?
V_415 :
NULL ;
}
V_377 = ( V_241 [ 6 ] << 24 ) | ( V_241 [ 7 ] << 16 ) |
( V_241 [ 8 ] << 8 ) | V_241 [ 9 ] ;
} else {
V_377 = ( V_241 [ 8 ] << 8 ) + V_241 [ 9 ] ;
}
V_61 -> V_95 |= V_409 ;
break;
case V_416 :
V_377 = V_241 [ 4 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_417 :
V_377 = ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_418 :
V_377 = V_241 [ 4 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
V_377 = ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_424 :
V_377 = V_425 ;
V_61 -> V_95 |= V_409 ;
break;
case V_426 :
case V_427 :
case V_428 :
case V_429 :
V_377 = ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_430 :
case V_431 :
V_61 -> V_344 =
( V_375 -> V_386 . V_432 ==
V_433 ) ?
V_434 : NULL ;
V_377 = ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_435 :
case V_436 :
V_377 = ( V_241 [ 8 ] << 8 ) + V_241 [ 9 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_437 :
V_377 = V_438 ;
V_61 -> V_95 |= V_409 ;
break;
case V_439 :
if ( V_63 -> V_114 -> V_200 ( V_63 ) != V_411 ) {
if ( V_241 [ 1 ] == V_440 ) {
V_61 -> V_344 =
( V_375 -> V_382 . V_413 ==
V_414 ) ?
V_441 :
NULL ;
}
V_377 = ( V_241 [ 6 ] << 24 ) | ( V_241 [ 7 ] << 16 ) |
( V_241 [ 8 ] << 8 ) | V_241 [ 9 ] ;
} else {
V_377 = ( V_241 [ 8 ] << 8 ) + V_241 [ 9 ] ;
}
V_61 -> V_95 |= V_409 ;
break;
case V_442 :
V_377 = ( V_241 [ 3 ] << 8 ) + V_241 [ 4 ] ;
if ( V_61 -> V_66 -> V_131 == V_132 )
V_61 -> V_135 = V_136 ;
V_61 -> V_95 |= V_409 ;
break;
case V_443 :
V_377 = ( V_241 [ 6 ] << 16 ) + ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_444 :
V_377 = V_445 ;
V_61 -> V_95 |= V_409 ;
break;
case V_446 :
case V_447 :
case V_448 :
V_377 = ( V_241 [ 6 ] << 24 ) | ( V_241 [ 7 ] << 16 ) | ( V_241 [ 8 ] << 8 ) | V_241 [ 9 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_449 :
case V_450 :
case V_451 :
case V_452 :
case V_453 :
case V_454 :
case V_455 :
V_377 = ( V_241 [ 10 ] << 24 ) | ( V_241 [ 11 ] << 16 ) |
( V_241 [ 12 ] << 8 ) | V_241 [ 13 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_456 :
case V_245 :
V_377 = ( V_241 [ 3 ] << 8 ) | V_241 [ 4 ] ;
V_61 -> V_95 |= V_409 ;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#endif
case V_457 :
V_377 = V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_458 :
V_377 = V_241 [ 4 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_459 :
V_377 = 65536 * V_241 [ 7 ] + 256 * V_241 [ 8 ] + V_241 [ 9 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_460 :
V_377 = ( V_241 [ 6 ] << 16 ) + ( V_241 [ 7 ] << 8 ) + V_241 [ 8 ] ;
V_61 -> V_95 |= V_409 ;
break;
case V_461 :
case V_462 :
if ( V_241 [ 0 ] == V_462 )
V_377 = ( V_241 [ 7 ] << 8 ) | V_241 [ 8 ] ;
else
V_377 = V_61 -> V_255 ;
V_61 -> V_344 =
( V_375 -> V_386 . V_432 !=
V_463 ) ?
V_464 : NULL ;
V_61 -> V_95 |= V_465 ;
break;
case V_466 :
case V_467 :
if ( V_241 [ 0 ] == V_467 )
V_377 = ( V_241 [ 7 ] << 8 ) | V_241 [ 8 ] ;
else
V_377 = V_61 -> V_255 ;
V_61 -> V_344 =
( V_375 -> V_386 . V_432 !=
V_463 ) ?
V_464 : NULL ;
V_61 -> V_95 |= V_465 ;
break;
case V_468 :
case 0x91 :
if ( V_241 [ 0 ] == V_468 ) {
V_351 = F_155 ( V_241 , V_61 , & V_376 ) ;
V_61 -> V_372 = F_138 ( V_241 ) ;
} else {
V_351 = F_157 ( V_241 , V_61 , & V_376 ) ;
V_61 -> V_372 = F_139 ( V_241 ) ;
}
if ( V_376 )
goto V_391;
V_377 = F_159 ( V_351 , V_241 , V_61 ) ;
V_61 -> V_95 |= V_465 ;
if ( V_63 -> V_114 -> V_189 == V_190 )
break;
V_61 -> V_95 |= V_345 ;
if ( ( V_61 -> V_372 != 0 ) || ( V_351 != 0 ) ) {
if ( F_171 ( V_61 ) < 0 )
goto V_385;
}
break;
case V_469 :
V_377 = F_175 ( & V_241 [ 7 ] ) ;
V_61 -> V_95 |= V_409 ;
break;
case V_470 :
V_351 = F_157 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
if ( V_351 )
V_377 = F_159 ( 1 , V_241 , V_61 ) ;
else {
F_4 ( L_167 ) ;
goto V_385;
}
V_61 -> V_372 = F_23 ( & V_241 [ 2 ] ) ;
V_61 -> V_95 |= V_409 ;
if ( F_172 ( & V_241 [ 1 ] , V_63 ) < 0 )
goto V_385;
break;
case V_471 :
V_351 = F_155 ( V_241 , V_61 , & V_376 ) ;
if ( V_376 )
goto V_391;
if ( V_351 )
V_377 = F_159 ( 1 , V_241 , V_61 ) ;
else {
F_4 ( L_167 ) ;
goto V_385;
}
V_61 -> V_372 = F_176 ( & V_241 [ 2 ] ) ;
V_61 -> V_95 |= V_409 ;
if ( F_172 ( & V_241 [ 1 ] , V_63 ) < 0 )
goto V_385;
break;
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_246 :
case V_483 :
case V_484 :
V_61 -> V_95 |= V_465 ;
break;
case V_485 :
V_61 -> V_344 =
V_486 ;
V_377 = ( V_241 [ 6 ] << 24 ) | ( V_241 [ 7 ] << 16 ) | ( V_241 [ 8 ] << 8 ) | V_241 [ 9 ] ;
if ( V_61 -> V_66 -> V_131 == V_132 )
V_61 -> V_135 = V_136 ;
V_61 -> V_95 |= V_409 ;
break;
default:
F_177 ( L_168
L_169 ,
V_61 -> V_71 -> V_51 () , V_241 [ 0 ] ) ;
V_61 -> V_264 = & V_368 ;
goto V_391;
}
if ( V_377 != V_61 -> V_255 ) {
F_177 ( L_170
L_171
L_172 , V_61 -> V_71 -> V_51 () ,
V_61 -> V_255 , V_377 , V_241 [ 0 ] ) ;
V_61 -> V_487 = V_377 ;
if ( V_61 -> V_151 == V_154 ) {
F_4 ( L_173
L_174 ) ;
goto V_385;
}
if ( ! V_31 && ( V_63 -> V_165 -> V_166 . V_167 != 512 ) ) {
F_4 ( L_175
L_176
L_177 , V_63 -> V_114 -> V_192 ) ;
goto V_385;
}
if ( V_377 > V_61 -> V_255 ) {
V_61 -> V_95 |= V_488 ;
V_61 -> V_489 = ( V_377 - V_61 -> V_255 ) ;
} else {
V_61 -> V_95 |= V_490 ;
V_61 -> V_489 = ( V_61 -> V_255 - V_377 ) ;
}
V_61 -> V_255 = V_377 ;
}
if ( ( V_61 -> V_95 & V_409 ) &&
V_377 > V_491 )
goto V_385;
F_141 ( V_61 ) ;
return V_31 ;
V_391:
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 = V_290 ;
return - V_182 ;
V_385:
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 = V_269 ;
return - V_182 ;
}
static void F_129 ( struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
struct V_2 * V_492 , * V_146 ;
int V_493 = 0 ;
if ( V_61 -> V_135 == V_494 ) {
F_45 ( & V_63 -> V_337 ) ;
F_74 () ;
V_63 -> V_495 ++ ;
F_27 ( L_178
L_179 , V_63 -> V_495 ,
V_61 -> V_262 ) ;
} else if ( V_61 -> V_135 == V_136 ) {
F_45 ( & V_63 -> V_334 ) ;
F_74 () ;
V_63 -> V_495 ++ ;
F_27 ( L_180
L_181 , V_63 -> V_495 ,
V_61 -> V_262 ) ;
} else if ( V_61 -> V_135 == V_335 ) {
F_9 ( & V_63 -> V_221 ) ;
F_33 ( & V_61 -> V_259 ) ;
F_45 ( & V_63 -> V_336 ) ;
F_74 () ;
F_10 ( & V_63 -> V_221 ) ;
V_63 -> V_495 ++ ;
F_27 ( L_182
L_183 , V_63 -> V_495 , V_61 -> V_262 ) ;
}
F_9 ( & V_63 -> V_220 ) ;
F_73 (cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_node) {
F_33 ( & V_492 -> V_258 ) ;
F_10 ( & V_63 -> V_220 ) ;
F_27 ( L_184
L_185
L_186 ,
V_492 -> V_137 [ 0 ] ,
V_492 -> V_135 , V_492 -> V_262 ) ;
F_67 ( V_492 ) ;
V_493 ++ ;
F_9 ( & V_63 -> V_220 ) ;
if ( V_492 -> V_135 == V_335 )
break;
}
F_10 ( & V_63 -> V_220 ) ;
if ( V_493 != 0 )
F_57 ( & V_63 -> V_93 . V_29 ) ;
}
static int V_314 ( struct V_2 * V_61 )
{
int V_31 = 0 ;
if ( V_61 -> V_95 & V_116 )
return V_61 -> V_71 -> V_310 ( V_61 ) ;
switch ( V_61 -> V_151 ) {
case V_153 :
V_31 = V_61 -> V_71 -> V_496 ( V_61 ) ;
break;
case V_154 :
if ( V_61 -> V_497 ) {
V_31 = V_61 -> V_71 -> V_496 ( V_61 ) ;
if ( V_31 < 0 )
return V_31 ;
}
case V_152 :
V_31 = V_61 -> V_71 -> V_310 ( V_61 ) ;
break;
default:
break;
}
return V_31 ;
}
static void F_134 (
struct V_2 * V_61 ,
struct V_62 * V_63 ,
int (* F_178)( struct V_2 * ) )
{
F_24 ( & V_63 -> V_147 ) ;
V_61 -> V_95 |= V_96 ;
V_61 -> V_498 = F_178 ;
F_25 ( & V_61 -> V_148 , & V_61 -> V_66 -> V_145 ) ;
F_56 ( & V_63 -> V_149 ) ;
F_108 () ;
F_26 ( & V_61 -> V_66 -> V_147 ) ;
F_179 ( & V_61 -> V_66 -> V_144 ) ;
}
static void F_180 ( struct V_2 * V_61 )
{
int V_499 = 0 , V_31 ;
if ( V_61 -> V_66 -> V_131 == V_132 )
F_129 ( V_61 ) ;
if ( F_44 ( & V_61 -> V_66 -> V_149 ) != 0 )
F_179 ( & V_61 -> V_66 -> V_144 ) ;
if ( V_61 -> V_498 ) {
V_31 = V_61 -> V_498 ( V_61 ) ;
if ( V_31 < 0 )
goto V_311;
V_61 -> V_498 = NULL ;
goto V_500;
}
if ( V_61 -> V_95 & V_116 ) {
if ( F_167 ( V_61 ) < 0 )
V_499 = V_501 ;
if ( V_61 -> V_103 ) {
V_31 = F_133 (
V_61 , V_499 , 1 ) ;
if ( V_31 == - V_275 )
goto V_311;
F_49 ( V_61 ) ;
F_48 ( V_61 ) ;
return;
}
}
if ( V_61 -> V_404 )
V_61 -> V_404 ( V_61 ) ;
switch ( V_61 -> V_151 ) {
case V_153 :
F_9 ( & V_61 -> V_84 -> V_270 ) ;
if ( V_61 -> V_84 -> V_271 ) {
V_61 -> V_84 -> V_271 -> V_272 . V_502 +=
V_61 -> V_255 ;
}
F_10 ( & V_61 -> V_84 -> V_270 ) ;
V_31 = V_61 -> V_71 -> V_496 ( V_61 ) ;
if ( V_31 == - V_275 )
goto V_311;
break;
case V_154 :
F_9 ( & V_61 -> V_84 -> V_270 ) ;
if ( V_61 -> V_84 -> V_271 ) {
V_61 -> V_84 -> V_271 -> V_272 . V_503 +=
V_61 -> V_255 ;
}
F_10 ( & V_61 -> V_84 -> V_270 ) ;
if ( V_61 -> V_497 ) {
F_9 ( & V_61 -> V_84 -> V_270 ) ;
if ( V_61 -> V_84 -> V_271 ) {
V_61 -> V_84 -> V_271 -> V_272 . V_502 +=
V_61 -> V_255 ;
}
F_10 ( & V_61 -> V_84 -> V_270 ) ;
V_31 = V_61 -> V_71 -> V_496 ( V_61 ) ;
if ( V_31 == - V_275 )
goto V_311;
break;
}
case V_152 :
V_31 = V_61 -> V_71 -> V_310 ( V_61 ) ;
if ( V_31 == - V_275 )
goto V_311;
break;
default:
break;
}
V_500:
F_49 ( V_61 ) ;
F_48 ( V_61 ) ;
return;
V_311:
F_27 ( L_187
L_188 , V_61 , V_61 -> V_151 ) ;
F_134 ( V_61 , V_61 -> V_66 , V_314 ) ;
}
static void F_181 ( struct V_2 * V_61 )
{
struct V_64 * V_65 , * V_282 ;
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_73 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( F_44 ( & V_65 -> V_67 ) )
continue;
F_101 ( V_65 -> V_504 ) ;
F_101 ( V_65 -> V_505 ) ;
F_33 ( & V_65 -> V_102 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
if ( V_65 -> V_66 )
V_65 -> V_66 -> V_114 -> V_506 ( V_65 ) ;
else
F_4 ( L_189 ,
V_65 -> V_283 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
}
static inline void F_182 ( struct V_353 * V_507 , int V_508 )
{
struct V_353 * V_354 ;
int V_356 ;
F_163 (sgl, sg, nents, count)
F_183 ( F_165 ( V_354 ) ) ;
F_101 ( V_507 ) ;
}
static inline void F_184 ( struct V_2 * V_61 )
{
if ( V_61 -> V_95 & V_509 )
return;
F_182 ( V_61 -> V_357 , V_61 -> V_358 ) ;
V_61 -> V_357 = NULL ;
V_61 -> V_358 = 0 ;
F_182 ( V_61 -> V_497 , V_61 -> V_510 ) ;
V_61 -> V_497 = NULL ;
V_61 -> V_510 = 0 ;
}
static inline void F_185 ( struct V_2 * V_61 )
{
F_181 ( V_61 ) ;
}
static inline int F_186 ( struct V_2 * V_61 )
{
unsigned long V_53 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( F_44 ( & V_61 -> V_511 ) ) {
if ( ! F_63 ( & V_61 -> V_511 ) ) {
F_36 ( & V_61 -> V_76 ,
V_53 ) ;
return 1 ;
}
}
if ( F_44 ( & V_61 -> V_120 ) ) {
if ( ! F_63 ( & V_61 -> V_120 ) ) {
F_36 ( & V_61 -> V_76 ,
V_53 ) ;
return 1 ;
}
}
F_36 ( & V_61 -> V_76 , V_53 ) ;
return 0 ;
}
static void F_78 ( struct V_2 * V_61 )
{
unsigned long V_53 ;
if ( F_186 ( V_61 ) )
return;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( ! F_44 ( & V_61 -> V_88 ) ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
goto V_512;
}
F_12 ( & V_61 -> V_88 , 0 ) ;
F_42 ( V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_185 ( V_61 ) ;
V_512:
F_184 ( V_61 ) ;
F_109 ( V_61 ) ;
V_61 -> V_71 -> V_513 ( V_61 ) ;
}
static int
F_52 ( struct V_2 * V_61 , int V_514 )
{
unsigned long V_53 ;
if ( F_186 ( V_61 ) ) {
if ( V_514 ) {
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_42 ( V_61 ) ;
F_36 ( & V_61 -> V_76 ,
V_53 ) ;
}
return 1 ;
}
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( ! F_44 ( & V_61 -> V_88 ) ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
goto V_512;
}
F_12 ( & V_61 -> V_88 , 0 ) ;
F_42 ( V_61 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_185 ( V_61 ) ;
V_512:
F_184 ( V_61 ) ;
F_187 ( V_61 ) ;
return 0 ;
}
int F_188 (
struct V_2 * V_61 ,
struct V_353 * V_507 ,
T_1 V_515 ,
struct V_353 * V_516 ,
T_1 V_517 )
{
if ( ! V_507 || ! V_515 )
return 0 ;
if ( ( V_61 -> V_95 & V_346 ) ||
( V_61 -> V_95 & V_409 ) ) {
V_61 -> V_357 = V_507 ;
V_61 -> V_358 = V_515 ;
if ( V_516 && V_517 ) {
V_61 -> V_497 = V_516 ;
V_61 -> V_510 = V_517 ;
}
V_61 -> V_95 |= V_509 ;
}
return 0 ;
}
static int F_189 ( struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
int V_518 = 1 , V_519 , V_520 ;
if ( V_61 -> V_497 &&
( V_63 -> V_114 -> V_189 != V_190 ) ) {
V_519 = F_190 ( V_61 ,
V_61 -> V_372 ,
V_153 ,
V_61 -> V_497 ,
V_61 -> V_510 ) ;
if ( V_519 <= 0 ) {
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 =
V_300 ;
return - V_182 ;
}
F_56 ( & V_61 -> V_511 ) ;
F_56 ( & V_61 -> V_120 ) ;
V_518 = 0 ;
}
V_520 = F_190 ( V_61 ,
V_61 -> V_372 ,
V_61 -> V_151 ,
V_61 -> V_357 ,
V_61 -> V_358 ) ;
if ( V_520 <= 0 ) {
V_61 -> V_95 |= V_267 ;
V_61 -> V_268 =
V_300 ;
return - V_182 ;
}
if ( V_518 ) {
F_56 ( & V_61 -> V_511 ) ;
F_56 ( & V_61 -> V_120 ) ;
}
V_61 -> V_286 = V_520 ;
F_12 ( & V_61 -> V_124 , V_520 ) ;
F_12 ( & V_61 -> V_73 , V_520 ) ;
F_12 ( & V_61 -> V_122 , V_520 ) ;
return 0 ;
}
void * F_191 ( struct V_2 * V_61 )
{
struct V_353 * V_354 = V_61 -> V_357 ;
F_8 ( ! V_354 ) ;
return F_192 ( F_165 ( V_354 ) ) + V_354 -> V_355 ;
}
void F_193 ( struct V_2 * V_61 )
{
F_194 ( F_165 ( V_61 -> V_357 ) ) ;
}
static int
F_195 ( struct V_2 * V_61 )
{
T_1 V_360 = V_61 -> V_255 ;
unsigned int V_508 ;
struct V_521 * V_521 ;
int V_188 = 0 ;
V_508 = F_196 ( V_360 , V_491 ) ;
V_61 -> V_357 = F_161 ( sizeof( struct V_353 ) * V_508 , V_34 ) ;
if ( ! V_61 -> V_357 )
return - V_20 ;
V_61 -> V_358 = V_508 ;
F_197 ( V_61 -> V_357 , V_508 ) ;
while ( V_360 ) {
T_1 V_522 = F_198 ( T_1 , V_360 , V_491 ) ;
V_521 = F_199 ( V_34 | V_523 ) ;
if ( ! V_521 )
goto V_3;
F_200 ( & V_61 -> V_357 [ V_188 ] , V_521 , V_522 , 0 ) ;
V_360 -= V_522 ;
V_188 ++ ;
}
return 0 ;
V_3:
while ( V_188 >= 0 ) {
F_183 ( F_165 ( & V_61 -> V_357 [ V_188 ] ) ) ;
V_188 -- ;
}
F_101 ( V_61 -> V_357 ) ;
V_61 -> V_357 = NULL ;
return - V_20 ;
}
static inline T_5 F_201 (
struct V_62 * V_63 ,
unsigned long long V_524 ,
T_5 V_351 )
{
V_351 = F_198 ( T_5 , V_351 , V_63 -> V_165 -> V_166 . V_168 ) ;
if ( V_63 -> V_114 -> V_200 ( V_63 ) == V_371 )
if ( ( V_524 + V_351 ) > F_170 ( V_63 ) )
V_351 = ( ( F_170 ( V_63 ) - V_524 ) + 1 ) ;
return V_351 ;
}
void F_202 ( struct V_2 * V_61 )
{
struct V_353 * V_525 = NULL ;
struct V_353 * V_526 = NULL ;
int V_527 = 0 ;
struct V_353 * V_354 ;
struct V_64 * V_65 ;
T_1 V_528 = 0 ;
int V_188 ;
F_8 ( ! V_61 -> V_71 -> V_529 ) ;
F_43 (task, &cmd->t_task_list, t_list) {
if ( ! V_65 -> V_505 )
continue;
if ( ! V_525 ) {
V_525 = V_65 -> V_505 ;
V_528 = V_65 -> V_530 ;
} else {
F_203 ( V_526 , V_527 , V_65 -> V_505 ) ;
V_528 += V_65 -> V_530 ;
}
if ( V_65 -> V_531 )
V_527 = ( V_65 -> V_530 + 1 ) ;
else
V_527 = V_65 -> V_530 ;
V_526 = V_65 -> V_505 ;
}
V_61 -> V_532 = V_525 ;
V_61 -> V_533 = V_528 ;
F_27 ( L_190
L_191 , V_61 , V_61 -> V_532 ,
V_61 -> V_533 ) ;
F_163 (cmd->t_tasks_sg_chained, sg,
cmd->t_tasks_sg_chained_no, i) {
F_27 ( L_192 ,
V_188 , V_354 , F_165 ( V_354 ) , V_354 -> V_360 , V_354 -> V_355 ) ;
if ( F_204 ( V_354 ) )
F_27 ( L_193 , V_354 ) ;
if ( F_205 ( V_354 ) )
F_27 ( L_194 , V_354 ) ;
}
}
static int F_206 (
struct V_2 * V_61 ,
unsigned long long V_524 ,
enum V_250 V_151 ,
struct V_353 * V_507 ,
unsigned int V_534 )
{
unsigned char * V_241 = NULL ;
struct V_64 * V_65 ;
struct V_62 * V_63 = V_61 -> V_66 ;
unsigned long V_53 ;
int V_535 , V_188 , V_31 ;
T_5 V_351 , V_536 = V_63 -> V_165 -> V_166 . V_168 ;
T_1 V_537 = V_63 -> V_165 -> V_166 . V_167 ;
struct V_353 * V_354 ;
struct V_353 * V_538 ;
F_168 ( V_61 -> V_255 % V_537 ) ;
V_351 = F_196 ( V_61 -> V_255 , V_537 ) ;
V_535 = F_207 ( V_351 , V_536 ) ;
V_538 = V_507 ;
for ( V_188 = 0 ; V_188 < V_535 ; V_188 ++ ) {
unsigned int V_539 , V_540 ;
int V_356 ;
V_65 = F_103 ( V_61 , V_151 ) ;
if ( ! V_65 )
return - V_20 ;
V_65 -> V_541 = V_524 ;
V_65 -> V_542 = F_208 ( V_351 , V_536 ) ;
V_65 -> V_539 = V_65 -> V_542 * V_537 ;
V_241 = V_63 -> V_114 -> V_543 ( V_65 ) ;
F_8 ( ! V_241 ) ;
memcpy ( V_241 , V_61 -> V_137 ,
F_112 ( V_61 -> V_137 ) ) ;
V_61 -> V_392 ( V_65 -> V_541 , V_65 -> V_542 , V_241 ) ;
V_65 -> V_530 = F_196 ( V_65 -> V_539 , V_491 ) ;
if ( V_61 -> V_71 -> V_529 && ( V_188 < ( V_535 - 1 ) ) ) {
V_540 = ( V_65 -> V_530 + 1 ) ;
V_65 -> V_531 = 1 ;
} else
V_540 = V_65 -> V_530 ;
V_65 -> V_505 = F_161 ( sizeof( struct V_353 ) *
V_540 , V_34 ) ;
if ( ! V_65 -> V_505 ) {
V_61 -> V_66 -> V_114 -> V_506 ( V_65 ) ;
return - V_20 ;
}
F_197 ( V_65 -> V_505 , V_540 ) ;
V_539 = V_65 -> V_539 ;
F_163 (task->task_sg, sg, task->task_sg_nents, count) {
if ( V_538 -> V_360 > V_539 )
break;
* V_354 = * V_538 ;
V_539 -= V_538 -> V_360 ;
V_538 = F_209 ( V_538 ) ;
}
V_524 += V_65 -> V_542 ;
V_351 -= V_65 -> V_542 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_25 ( & V_65 -> V_102 , & V_61 -> V_100 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
}
F_43 (task, &cmd->t_task_list, t_list) {
if ( F_44 ( & V_65 -> V_284 ) )
continue;
if ( ! V_63 -> V_114 -> V_544 )
continue;
V_31 = V_63 -> V_114 -> V_544 ( V_65 ) ;
if ( V_31 < 0 )
return 0 ;
}
return V_535 ;
}
static int
F_210 ( struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
unsigned char * V_241 ;
struct V_64 * V_65 ;
unsigned long V_53 ;
int V_31 = 0 ;
V_65 = F_103 ( V_61 , V_61 -> V_151 ) ;
if ( ! V_65 )
return - V_20 ;
V_241 = V_63 -> V_114 -> V_543 ( V_65 ) ;
F_8 ( ! V_241 ) ;
memcpy ( V_241 , V_61 -> V_137 ,
F_112 ( V_61 -> V_137 ) ) ;
V_65 -> V_505 = F_161 ( sizeof( struct V_353 ) * V_61 -> V_358 ,
V_34 ) ;
if ( ! V_65 -> V_505 ) {
V_61 -> V_66 -> V_114 -> V_506 ( V_65 ) ;
return - V_20 ;
}
memcpy ( V_65 -> V_505 , V_61 -> V_357 ,
sizeof( struct V_353 ) * V_61 -> V_358 ) ;
V_65 -> V_539 = V_61 -> V_255 ;
V_65 -> V_530 = V_61 -> V_358 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_25 ( & V_65 -> V_102 , & V_61 -> V_100 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
if ( V_61 -> V_95 & V_409 ) {
if ( V_63 -> V_114 -> V_545 )
V_31 = V_63 -> V_114 -> V_545 ( V_65 ) ;
} else if ( V_61 -> V_95 & V_465 ) {
if ( V_63 -> V_114 -> V_546 )
V_31 = V_63 -> V_114 -> V_546 ( V_65 ) ;
} else {
F_4 ( L_195 ) ;
F_211 () ;
}
if ( V_31 == 0 )
return 1 ;
return V_31 ;
}
static T_1 F_190 (
struct V_2 * V_61 ,
unsigned long long V_524 ,
enum V_250 V_151 ,
struct V_353 * V_507 ,
unsigned int V_534 )
{
if ( V_61 -> V_95 & V_346 ) {
if ( F_171 ( V_61 ) < 0 )
return - V_182 ;
return F_206 ( V_61 , V_524 , V_151 ,
V_507 , V_534 ) ;
} else
return F_210 ( V_61 ) ;
}
int F_117 ( struct V_2 * V_61 )
{
int V_31 = 0 ;
if ( ! ( V_61 -> V_95 & V_509 ) &&
V_61 -> V_255 ) {
V_31 = F_195 ( V_61 ) ;
if ( V_31 < 0 )
return V_31 ;
}
V_31 = F_189 ( V_61 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_61 -> V_151 == V_154 ) {
F_66 ( V_61 ) ;
return F_212 ( V_61 ) ;
}
F_150 ( V_61 ) ;
return 0 ;
}
void F_213 ( struct V_2 * V_61 )
{
F_150 ( V_61 ) ;
}
static int F_214 ( struct V_2 * V_61 )
{
return V_61 -> V_71 -> V_547 ( V_61 ) ;
}
static int F_212 ( struct V_2 * V_61 )
{
unsigned long V_53 ;
int V_31 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
V_61 -> V_75 = V_548 ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
if ( V_61 -> V_498 ) {
V_31 = V_61 -> V_498 ( V_61 ) ;
if ( V_31 == - V_275 )
goto V_311;
else if ( V_31 < 0 )
return V_31 ;
V_61 -> V_498 = NULL ;
return 0 ;
}
F_46 ( V_61 , 1 , 0 ) ;
V_31 = V_61 -> V_71 -> V_547 ( V_61 ) ;
if ( V_31 == - V_275 )
goto V_311;
else if ( V_31 < 0 )
return V_31 ;
return V_549 ;
V_311:
F_27 ( L_196 , V_61 ) ;
V_61 -> V_75 = V_150 ;
F_134 ( V_61 , V_61 -> V_66 ,
F_214 ) ;
return V_31 ;
}
void F_187 ( struct V_2 * V_61 )
{
F_8 ( ! V_61 -> V_71 ) ;
F_109 ( V_61 ) ;
V_61 -> V_71 -> V_513 ( V_61 ) ;
}
void F_215 (
struct V_2 * V_61 ,
int V_550 ,
int V_514 )
{
if ( ! ( V_61 -> V_95 & V_551 ) )
F_187 ( V_61 ) ;
else {
F_216 ( V_61 -> V_33 -> V_39 , V_61 ) ;
if ( V_61 -> V_84 ) {
#if 0
pr_debug("cmd: %p ITT: 0x%08x contains"
" cmd->se_lun\n", cmd,
cmd->se_tfo->get_task_tag(cmd));
#endif
F_49 ( V_61 ) ;
}
if ( V_550 && V_61 -> V_264 )
V_61 -> V_264 ( V_61 , 0 , 0 ) ;
F_181 ( V_61 ) ;
F_52 ( V_61 , V_514 ) ;
}
}
static void V_368 (
struct V_2 * V_61 ,
int V_552 ,
int V_514 )
{
return;
}
static int F_217 ( struct V_2 * V_61 , struct V_84 * V_87 )
{
unsigned long V_53 ;
int V_31 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( F_44 ( & V_61 -> V_83 ) ) {
F_12 ( & V_61 -> V_77 , 0 ) ;
F_27 ( L_197
L_198 , V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_46 ( V_61 , 1 , 0 ) ;
return - V_278 ;
}
F_12 ( & V_61 -> V_553 , 1 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_57 ( & V_61 -> V_66 -> V_93 . V_29 ) ;
V_31 = F_125 ( V_61 ) ;
F_27 ( L_199
L_200 , V_61 , V_61 -> V_286 , V_31 ) ;
if ( ! V_31 ) {
F_27 ( L_201 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_126 ( & V_61 -> V_82 ) ;
F_27 ( L_202 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
}
F_51 ( V_61 , & V_61 -> V_66 -> V_93 ) ;
return 0 ;
}
static void F_218 ( struct V_84 * V_87 )
{
struct V_2 * V_61 = NULL ;
unsigned long V_554 , V_555 ;
F_32 ( & V_87 -> V_90 , V_554 ) ;
while ( ! F_34 ( & V_87 -> V_556 ) ) {
V_61 = F_59 ( & V_87 -> V_556 ,
struct V_2 , V_92 ) ;
F_33 ( & V_61 -> V_92 ) ;
F_12 ( & V_61 -> V_91 , 0 ) ;
F_9 ( & V_61 -> V_76 ) ;
F_27 ( L_203
L_204 ,
V_61 -> V_84 -> V_557 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_12 ( & V_61 -> V_77 , 1 ) ;
F_10 ( & V_61 -> V_76 ) ;
F_36 ( & V_87 -> V_90 , V_554 ) ;
if ( ! V_61 -> V_84 ) {
F_4 ( L_205 ,
V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_71 -> V_171 ( V_61 ) , V_61 -> V_75 ) ;
F_211 () ;
}
F_27 ( L_206
L_207 , V_61 -> V_84 -> V_557 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
if ( F_217 ( V_61 , V_61 -> V_84 ) < 0 ) {
F_32 ( & V_87 -> V_90 , V_554 ) ;
continue;
}
F_27 ( L_208
L_209 ,
V_61 -> V_84 -> V_557 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_32 ( & V_61 -> V_76 , V_555 ) ;
if ( ! F_44 ( & V_61 -> V_88 ) ) {
F_36 ( & V_61 -> V_76 , V_555 ) ;
goto V_558;
}
F_12 ( & V_61 -> V_88 , 0 ) ;
F_42 ( V_61 ) ;
F_36 ( & V_61 -> V_76 , V_555 ) ;
F_181 ( V_61 ) ;
V_558:
F_133 ( V_61 ,
V_501 , 0 ) ;
F_32 ( & V_61 -> V_76 , V_555 ) ;
if ( F_44 ( & V_61 -> V_553 ) ) {
F_27 ( L_210
L_211 ,
V_87 -> V_557 ,
V_61 , V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_36 ( & V_61 -> V_76 ,
V_555 ) ;
F_46 ( V_61 , 1 , 0 ) ;
F_47 ( & V_61 -> V_260 ) ;
F_32 ( & V_87 -> V_90 , V_554 ) ;
continue;
}
F_27 ( L_212 ,
V_87 -> V_557 , V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_36 ( & V_61 -> V_76 , V_555 ) ;
F_32 ( & V_87 -> V_90 , V_554 ) ;
}
F_36 ( & V_87 -> V_90 , V_554 ) ;
}
static int F_219 ( void * V_559 )
{
struct V_84 * V_87 = (struct V_84 * ) V_559 ;
F_218 ( V_87 ) ;
F_47 ( & V_87 -> V_560 ) ;
return 0 ;
}
int F_220 ( struct V_84 * V_87 )
{
struct V_561 * V_562 ;
V_562 = F_96 ( F_219 , V_87 ,
L_213 , V_87 -> V_557 ) ;
if ( F_97 ( V_562 ) ) {
F_4 ( L_214 ) ;
return F_221 ( V_562 ) ;
}
F_126 ( & V_87 -> V_560 ) ;
return 0 ;
}
static void V_265 (
struct V_2 * V_61 ,
int V_552 ,
int V_514 )
{
unsigned long V_53 ;
if ( ! ( V_61 -> V_95 & V_551 ) && ! ( V_61 -> V_5 ) )
return;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( F_44 ( & V_61 -> V_77 ) ) {
F_27 ( L_215
L_216
L_217 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_47 ( & V_61 -> V_82 ) ;
F_126 ( & V_61 -> V_260 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_42 ( V_61 ) ;
F_27 ( L_218
L_219
L_220 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
F_12 ( & V_61 -> V_77 , 0 ) ;
}
if ( ! F_44 ( & V_61 -> V_81 ) ||
F_44 ( & V_61 -> V_563 ) )
goto remove;
F_12 ( & V_61 -> V_83 , 1 ) ;
F_27 ( L_221
L_222
L_223 , V_61 , V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_71 -> V_171 ( V_61 ) , V_61 -> V_75 ,
V_61 -> V_79 ) ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
F_57 ( & V_61 -> V_66 -> V_93 . V_29 ) ;
F_126 ( & V_61 -> V_85 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_12 ( & V_61 -> V_81 , 0 ) ;
F_12 ( & V_61 -> V_83 , 0 ) ;
F_27 ( L_224
L_225 ,
V_61 -> V_71 -> V_72 ( V_61 ) ) ;
remove:
F_36 ( & V_61 -> V_76 , V_53 ) ;
if ( ! V_552 )
return;
F_215 ( V_61 , 0 , V_514 ) ;
}
static int F_222 (
struct V_2 * V_61 ,
T_3 * V_564 ,
T_3 * V_565 )
{
* V_564 = V_61 -> V_566 ;
* V_565 = V_61 -> V_567 ;
return 0 ;
}
static int F_174 (
struct V_2 * V_61 ,
T_3 V_564 ,
T_3 V_565 )
{
V_61 -> V_566 = V_564 ;
V_61 -> V_567 = V_565 ;
return 0 ;
}
int F_133 (
struct V_2 * V_61 ,
T_3 V_499 ,
int V_568 )
{
unsigned char * V_361 = V_61 -> V_257 ;
unsigned long V_53 ;
int V_355 ;
T_3 V_564 = 0 , V_565 = 0 ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
if ( V_61 -> V_95 & V_362 ) {
F_36 ( & V_61 -> V_76 , V_53 ) ;
return 0 ;
}
V_61 -> V_95 |= V_362 ;
F_36 ( & V_61 -> V_76 , V_53 ) ;
if ( ! V_499 && V_568 )
goto V_569;
if ( ! V_568 )
V_61 -> V_95 |= V_570 ;
V_355 = V_61 -> V_71 -> V_364 ( V_61 ,
V_365 ) ;
switch ( V_499 ) {
case V_501 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_572 ;
V_361 [ V_355 + V_573 ] = 0x25 ;
break;
case V_290 :
case V_292 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_572 ;
V_361 [ V_355 + V_573 ] = 0x20 ;
break;
case V_302 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_572 ;
V_361 [ V_355 + V_573 ] = 0x24 ;
break;
case V_574 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x29 ;
V_361 [ V_355 + V_576 ] = 0x03 ;
break;
case V_577 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x0c ;
V_361 [ V_355 + V_576 ] = 0x0d ;
break;
case V_269 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x24 ;
break;
case V_295 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x26 ;
break;
case V_578 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x0c ;
V_361 [ V_355 + V_576 ] = 0x0c ;
break;
case V_579 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x47 ;
V_361 [ V_355 + V_576 ] = 0x05 ;
break;
case V_580 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_575 ;
V_361 [ V_355 + V_573 ] = 0x11 ;
V_361 [ V_355 + V_576 ] = 0x13 ;
break;
case V_304 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_581 ;
V_361 [ V_355 + V_573 ] = 0x27 ;
break;
case V_381 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_582 ;
F_223 ( V_61 , & V_564 , & V_565 ) ;
V_361 [ V_355 + V_573 ] = V_564 ;
V_361 [ V_355 + V_576 ] = V_565 ;
break;
case V_384 :
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_583 ;
F_222 ( V_61 , & V_564 , & V_565 ) ;
V_361 [ V_355 + V_573 ] = V_564 ;
V_361 [ V_355 + V_576 ] = V_565 ;
break;
case V_300 :
default:
V_361 [ V_355 ] = 0x70 ;
V_361 [ V_355 + V_571 ] = V_572 ;
V_361 [ V_355 + V_573 ] = 0x80 ;
break;
}
V_61 -> V_103 = V_107 ;
V_61 -> V_366 = V_365 + V_355 ;
V_569:
return V_61 -> V_71 -> V_310 ( V_61 ) ;
}
int F_122 ( struct V_2 * V_61 , int V_584 )
{
int V_31 = 0 ;
if ( F_44 ( & V_61 -> V_563 ) != 0 ) {
if ( ! V_584 ||
( V_61 -> V_95 & V_585 ) )
return 1 ;
#if 0
pr_debug("Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_61 -> V_95 |= V_585 ;
V_61 -> V_71 -> V_310 ( V_61 ) ;
V_31 = 1 ;
}
return V_31 ;
}
void F_224 ( struct V_2 * V_61 )
{
if ( V_61 -> V_151 == V_154 ) {
if ( V_61 -> V_71 -> V_586 ( V_61 ) != 0 ) {
F_56 ( & V_61 -> V_563 ) ;
F_108 () ;
V_61 -> V_103 = V_587 ;
F_131 ( V_61 ) ;
return;
}
}
V_61 -> V_103 = V_587 ;
#if 0
pr_debug("Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_61 -> V_71 -> V_310 ( V_61 ) ;
}
int F_225 ( struct V_2 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_66 ;
struct V_5 * V_588 = V_61 -> V_5 ;
int V_31 ;
switch ( V_588 -> V_329 ) {
case V_589 :
V_588 -> V_590 = V_591 ;
break;
case V_592 :
case V_593 :
case V_594 :
V_588 -> V_590 = V_595 ;
break;
case V_596 :
V_31 = F_226 ( V_63 , V_588 , NULL , NULL ) ;
V_588 -> V_590 = ( ! V_31 ) ? V_597 :
V_591 ;
break;
case V_598 :
V_588 -> V_590 = V_591 ;
break;
case V_599 :
V_588 -> V_590 = V_591 ;
break;
default:
F_4 ( L_226 ,
V_588 -> V_329 ) ;
V_588 -> V_590 = V_591 ;
break;
}
V_61 -> V_75 = V_600 ;
V_61 -> V_71 -> V_601 ( V_61 ) ;
F_46 ( V_61 , 2 , 0 ) ;
return 0 ;
}
static struct V_64 *
F_227 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
if ( F_34 ( & V_63 -> V_140 ) )
return NULL ;
F_43 (task, &dev->state_task_list, t_state_list)
break;
F_33 ( & V_65 -> V_70 ) ;
F_12 ( & V_65 -> V_68 , 0 ) ;
return V_65 ;
}
static void F_228 ( struct V_62 * V_63 )
{
struct V_2 * V_61 ;
struct V_64 * V_65 ;
unsigned long V_53 ;
F_32 ( & V_63 -> V_69 , V_53 ) ;
while ( ( V_65 = F_227 ( V_63 ) ) ) {
if ( ! V_65 -> V_110 ) {
F_4 ( L_227 ) ;
continue;
}
V_61 = V_65 -> V_110 ;
F_36 ( & V_63 -> V_69 , V_53 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_27 ( L_228
L_229
L_230 , V_61 , V_65 ,
V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_71 -> V_171 ( V_61 ) ,
V_61 -> V_75 , V_61 -> V_79 ,
V_61 -> V_137 [ 0 ] ) ;
F_27 ( L_231
L_232
L_233 ,
V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_286 ,
F_44 ( & V_61 -> V_124 ) ,
F_44 ( & V_61 -> V_287 ) ,
F_44 ( & V_61 -> V_81 ) ,
F_44 ( & V_61 -> V_83 ) ,
F_44 ( & V_61 -> V_288 ) ) ;
if ( F_44 ( & V_65 -> V_67 ) ) {
F_12 ( & V_65 -> V_118 , 1 ) ;
F_36 (
& V_61 -> V_76 , V_53 ) ;
F_27 ( L_234
L_235 , V_65 , V_63 ) ;
F_126 ( & V_65 -> V_121 ) ;
F_27 ( L_236 ,
V_65 , V_63 ) ;
F_32 ( & V_61 -> V_76 , V_53 ) ;
F_45 ( & V_61 -> V_124 ) ;
F_12 ( & V_65 -> V_67 , 0 ) ;
F_12 ( & V_65 -> V_118 , 0 ) ;
} else {
if ( F_44 ( & V_65 -> V_141 ) != 0 )
F_68 ( V_65 , V_63 ) ;
}
F_127 ( V_65 , & V_53 ) ;
if ( ! F_63 ( & V_61 -> V_73 ) ) {
F_36 (
& V_61 -> V_76 , V_53 ) ;
F_27 ( L_237
L_238 , V_65 , V_63 ,
F_44 ( & V_61 -> V_73 ) ) ;
F_32 ( & V_63 -> V_69 , V_53 ) ;
continue;
}
if ( F_44 ( & V_61 -> V_81 ) ) {
F_27 ( L_239
L_235 , V_65 , V_63 ) ;
if ( F_44 ( & V_61 -> V_511 ) ) {
F_36 (
& V_61 -> V_76 , V_53 ) ;
F_133 (
V_61 , V_300 ,
0 ) ;
F_51 ( V_61 ,
& V_61 -> V_66 -> V_93 ) ;
F_49 ( V_61 ) ;
F_46 ( V_61 , 1 , 0 ) ;
} else {
F_36 (
& V_61 -> V_76 , V_53 ) ;
F_51 ( V_61 ,
& V_61 -> V_66 -> V_93 ) ;
F_49 ( V_61 ) ;
if ( F_46 ( V_61 , 1 , 0 ) )
F_52 ( V_61 , 0 ) ;
}
F_32 ( & V_63 -> V_69 , V_53 ) ;
continue;
}
F_27 ( L_240 ,
V_65 , V_63 ) ;
if ( F_44 ( & V_61 -> V_511 ) ) {
F_36 (
& V_61 -> V_76 , V_53 ) ;
F_133 ( V_61 ,
V_300 , 0 ) ;
F_51 ( V_61 ,
& V_61 -> V_66 -> V_93 ) ;
F_49 ( V_61 ) ;
F_46 ( V_61 , 1 , 0 ) ;
} else {
F_36 (
& V_61 -> V_76 , V_53 ) ;
F_51 ( V_61 ,
& V_61 -> V_66 -> V_93 ) ;
F_49 ( V_61 ) ;
if ( F_46 ( V_61 , 1 , 0 ) )
F_52 ( V_61 , 0 ) ;
}
F_32 ( & V_63 -> V_69 , V_53 ) ;
}
F_36 ( & V_63 -> V_69 , V_53 ) ;
while ( ( V_61 = F_58 ( & V_63 -> V_93 ) ) ) {
F_27 ( L_241 ,
V_61 , V_61 -> V_75 ) ;
if ( F_44 ( & V_61 -> V_511 ) ) {
F_133 ( V_61 ,
V_300 , 0 ) ;
F_49 ( V_61 ) ;
F_46 ( V_61 , 1 , 0 ) ;
} else {
F_49 ( V_61 ) ;
if ( F_46 ( V_61 , 1 , 0 ) )
F_52 ( V_61 , 0 ) ;
}
}
}
static int V_240 ( void * V_602 )
{
int V_31 ;
struct V_2 * V_61 ;
struct V_62 * V_63 = (struct V_62 * ) V_602 ;
F_229 ( V_277 , - 20 ) ;
while ( ! F_230 () ) {
V_31 = F_231 ( V_63 -> V_93 . V_29 ,
F_44 ( & V_63 -> V_93 . V_27 ) ||
F_230 () ) ;
if ( V_31 < 0 )
goto V_3;
F_24 ( & V_63 -> V_225 ) ;
if ( V_63 -> V_158 & V_161 ) {
F_26 ( & V_63 -> V_225 ) ;
F_228 ( V_63 ) ;
continue;
}
F_26 ( & V_63 -> V_225 ) ;
V_603:
F_152 ( V_63 ) ;
V_61 = F_58 ( & V_63 -> V_93 ) ;
if ( ! V_61 )
continue;
switch ( V_61 -> V_75 ) {
case V_276 :
if ( ! V_61 -> V_71 -> V_313 ) {
F_4 ( L_242
L_243 ) ;
F_211 () ;
}
V_31 = V_61 -> V_71 -> V_313 ( V_61 ) ;
if ( V_31 < 0 ) {
V_61 -> V_111 = V_31 ;
F_118 ( V_61 , NULL ,
0 , ( V_61 -> V_151 !=
V_154 ) ) ;
break;
}
case V_274 :
V_31 = F_117 ( V_61 ) ;
if ( V_31 == - V_275 )
break;
else if ( V_31 < 0 ) {
V_61 -> V_111 = V_31 ;
F_118 ( V_61 , NULL ,
0 , ( V_61 -> V_151 !=
V_154 ) ) ;
}
break;
case V_279 :
F_213 ( V_61 ) ;
break;
case V_129 :
F_128 ( V_61 ) ;
F_180 ( V_61 ) ;
break;
case V_604 :
F_52 ( V_61 , 0 ) ;
break;
case V_281 :
F_215 ( V_61 , 0 , 0 ) ;
break;
case V_280 :
F_225 ( V_61 ) ;
break;
case V_126 :
F_118 ( V_61 , NULL , 1 , 1 ) ;
break;
case V_123 :
F_128 ( V_61 ) ;
F_136 ( V_61 ) ;
break;
case V_150 :
F_212 ( V_61 ) ;
break;
default:
F_4 ( L_244
L_245
L_183 , V_61 -> V_75 , V_61 -> V_79 ,
V_61 -> V_71 -> V_72 ( V_61 ) ,
V_61 -> V_71 -> V_171 ( V_61 ) ,
V_61 -> V_84 -> V_557 ) ;
F_211 () ;
}
goto V_603;
}
V_3:
F_77 ( V_63 ) ;
V_63 -> V_239 = NULL ;
return 0 ;
}
