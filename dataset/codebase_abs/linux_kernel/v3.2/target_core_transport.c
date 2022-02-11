int F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) , F_3 ( struct V_2 ) ,
0 , NULL ) ;
if ( ! V_1 ) {
F_4 ( L_2
L_3 ) ;
goto V_3;
}
V_4 = F_2 ( L_4 ,
sizeof( struct V_5 ) , F_3 ( struct V_5 ) ,
0 , NULL ) ;
if ( ! V_4 ) {
F_4 ( L_5
L_3 ) ;
goto V_6;
}
V_7 = F_2 ( L_6 ,
sizeof( struct V_8 ) , F_3 ( struct V_8 ) ,
0 , NULL ) ;
if ( ! V_7 ) {
F_4 ( L_7 ) ;
goto V_9;
}
V_10 = F_2 ( L_8 ,
sizeof( struct V_11 ) ,
F_3 ( struct V_11 ) , 0 , NULL ) ;
if ( ! V_10 ) {
F_4 ( L_9
L_3 ) ;
goto V_12;
}
V_13 = F_2 ( L_10 ,
sizeof( struct V_14 ) , F_3 ( struct V_14 ) ,
0 , NULL ) ;
if ( ! V_13 ) {
F_4 ( L_11
L_3 ) ;
goto V_15;
}
V_16 = F_2 ( L_12 ,
sizeof( struct V_17 ) ,
F_3 ( struct V_17 ) , 0 , NULL ) ;
if ( ! V_16 ) {
F_4 ( L_13
L_14 ) ;
goto V_18;
}
V_19 = F_2 ( L_15 ,
sizeof( struct V_20 ) ,
F_3 ( struct V_20 ) , 0 , NULL ) ;
if ( ! V_19 ) {
F_4 ( L_16
L_14 ) ;
goto V_21;
}
V_22 = F_2 (
L_17 ,
sizeof( struct V_23 ) ,
F_3 ( struct V_23 ) ,
0 , NULL ) ;
if ( ! V_22 ) {
F_4 ( L_16
L_18 ) ;
goto V_24;
}
V_25 = F_5 ( L_19 ,
V_26 , 0 ) ;
if ( ! V_25 )
goto V_27;
return 0 ;
V_27:
F_6 ( V_22 ) ;
V_24:
F_6 ( V_19 ) ;
V_21:
F_6 ( V_16 ) ;
V_18:
F_6 ( V_13 ) ;
V_15:
F_6 ( V_10 ) ;
V_12:
F_6 ( V_7 ) ;
V_9:
F_6 ( V_4 ) ;
V_6:
F_6 ( V_1 ) ;
V_3:
return - V_28 ;
}
void F_7 ( void )
{
F_8 ( V_25 ) ;
F_6 ( V_1 ) ;
F_6 ( V_4 ) ;
F_6 ( V_7 ) ;
F_6 ( V_10 ) ;
F_6 ( V_13 ) ;
F_6 ( V_16 ) ;
F_6 ( V_19 ) ;
F_6 ( V_22 ) ;
}
T_1 F_9 ( T_2 type )
{
T_1 V_29 ;
F_10 ( ( type < 0 ) || ( type >= V_30 ) ) ;
F_11 ( & V_31 ) ;
V_29 = ++ V_32 [ type ] ;
F_12 ( & V_31 ) ;
return V_29 ;
}
void F_13 ( struct V_33 * V_34 )
{
F_14 ( & V_34 -> V_35 , 0 ) ;
F_15 ( & V_34 -> V_36 ) ;
F_16 ( & V_34 -> V_37 ) ;
F_17 ( & V_34 -> V_38 ) ;
}
void F_18 ( void )
{
int V_39 ;
if ( V_40 )
return;
V_39 = F_19 ( L_20 ) ;
if ( V_39 != 0 )
F_4 ( L_21 ) ;
V_39 = F_19 ( L_22 ) ;
if ( V_39 != 0 )
F_4 ( L_23 ) ;
V_39 = F_19 ( L_24 ) ;
if ( V_39 != 0 )
F_4 ( L_25 ) ;
V_39 = F_19 ( L_26 ) ;
if ( V_39 != 0 )
F_4 ( L_27 ) ;
V_40 = 1 ;
return;
}
struct V_5 * F_20 ( void )
{
struct V_5 * V_41 ;
V_41 = F_21 ( V_4 , V_42 ) ;
if ( ! V_41 ) {
F_4 ( L_28
L_29 ) ;
return F_22 ( - V_28 ) ;
}
F_15 ( & V_41 -> V_43 ) ;
F_15 ( & V_41 -> V_44 ) ;
F_15 ( & V_41 -> V_45 ) ;
F_15 ( & V_41 -> V_46 ) ;
F_17 ( & V_41 -> V_47 ) ;
return V_41 ;
}
void F_23 (
struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_5 * V_41 ,
void * V_52 )
{
unsigned char V_53 [ V_54 ] ;
V_41 -> V_49 = V_49 ;
V_41 -> V_52 = V_52 ;
if ( V_51 ) {
if ( V_49 -> V_55 -> V_56 != NULL ) {
memset ( & V_53 [ 0 ] , 0 , V_54 ) ;
V_49 -> V_55 -> V_56 ( V_41 ,
& V_53 [ 0 ] , V_54 ) ;
V_41 -> V_57 = F_24 ( & V_53 [ 0 ] ) ;
}
F_25 ( & V_51 -> V_58 ) ;
V_51 -> V_59 = V_41 ;
F_26 ( & V_41 -> V_44 ,
& V_51 -> V_60 ) ;
F_27 ( & V_51 -> V_58 ) ;
}
F_26 ( & V_41 -> V_43 , & V_49 -> V_61 ) ;
F_28 ( L_30 ,
V_49 -> V_55 -> V_62 () , V_41 -> V_52 ) ;
}
void F_29 (
struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_5 * V_41 ,
void * V_52 )
{
F_30 ( & V_49 -> V_63 ) ;
F_23 ( V_49 , V_51 , V_41 , V_52 ) ;
F_31 ( & V_49 -> V_63 ) ;
}
void F_32 ( struct V_5 * V_41 )
{
struct V_50 * V_51 ;
unsigned long V_64 ;
V_51 = V_41 -> V_50 ;
if ( V_51 ) {
F_33 ( & V_51 -> V_58 , V_64 ) ;
F_34 ( & V_41 -> V_44 ) ;
if ( F_35 ( & V_51 -> V_60 ) )
V_51 -> V_59 = NULL ;
else {
V_51 -> V_59 = F_36 (
V_51 -> V_60 . V_65 ,
struct V_5 , V_44 ) ;
}
F_37 ( & V_51 -> V_58 , V_64 ) ;
}
}
void F_38 ( struct V_5 * V_41 )
{
F_39 ( V_4 , V_41 ) ;
}
void F_40 ( struct V_5 * V_41 )
{
struct V_48 * V_49 = V_41 -> V_49 ;
struct V_50 * V_51 ;
unsigned long V_64 ;
if ( ! V_49 ) {
F_38 ( V_41 ) ;
return;
}
F_33 ( & V_49 -> V_63 , V_64 ) ;
F_34 ( & V_41 -> V_43 ) ;
V_41 -> V_49 = NULL ;
V_41 -> V_52 = NULL ;
F_37 ( & V_49 -> V_63 , V_64 ) ;
V_51 = V_41 -> V_50 ;
if ( V_51 ) {
F_33 ( & V_49 -> V_66 , V_64 ) ;
if ( V_51 -> V_67 ) {
if ( ! V_49 -> V_55 -> V_68 (
V_49 ) ) {
F_34 ( & V_51 -> V_69 ) ;
V_49 -> V_70 -- ;
F_37 ( & V_49 -> V_66 , V_64 ) ;
F_41 ( V_51 ) ;
F_42 ( V_51 , V_49 ) ;
V_49 -> V_55 -> V_71 ( V_49 ,
V_51 ) ;
F_33 ( & V_49 -> V_66 , V_64 ) ;
}
}
F_37 ( & V_49 -> V_66 , V_64 ) ;
}
F_38 ( V_41 ) ;
F_28 ( L_31 ,
V_49 -> V_55 -> V_62 () ) ;
}
static void F_43 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 ;
unsigned long V_64 ;
if ( ! V_75 )
return;
F_44 (task, &cmd->t_task_list, t_list) {
if ( V_78 -> V_79 & V_80 )
continue;
if ( ! F_45 ( & V_78 -> V_81 ) )
continue;
F_33 ( & V_75 -> V_82 , V_64 ) ;
F_34 ( & V_78 -> V_83 ) ;
F_28 ( L_32 ,
V_73 -> V_84 -> V_85 ( V_73 ) , V_75 , V_78 ) ;
F_37 ( & V_75 -> V_82 , V_64 ) ;
F_14 ( & V_78 -> V_81 , 0 ) ;
F_46 ( & V_73 -> V_86 ) ;
}
}
static int F_47 (
struct V_72 * V_73 ,
int V_87 ,
T_3 V_88 )
{
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( F_45 ( & V_73 -> V_90 ) ) {
F_28 ( L_33
L_34 , V_91 , __LINE__ ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_14 ( & V_73 -> V_92 , 0 ) ;
if ( V_87 == 2 )
F_43 ( V_73 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_73 -> V_93 ) ;
return 1 ;
}
if ( F_45 ( & V_73 -> V_94 ) ) {
F_28 ( L_35
L_36 , V_91 , __LINE__ ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
if ( V_87 == 2 )
F_43 ( V_73 ) ;
if ( V_87 == 2 )
V_73 -> V_95 = NULL ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_73 -> V_96 ) ;
return 1 ;
}
if ( V_87 ) {
F_14 ( & V_73 -> V_92 , 0 ) ;
if ( V_87 == 2 ) {
F_43 ( V_73 ) ;
V_73 -> V_95 = NULL ;
if ( V_73 -> V_84 -> V_97 != NULL ) {
F_37 (
& V_73 -> V_89 , V_64 ) ;
return V_73 -> V_84 -> V_97 ( V_73 ) ;
}
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 0 ;
} else if ( V_88 )
V_73 -> V_88 = V_88 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 0 ;
}
static int F_49 ( struct V_72 * V_73 )
{
return F_47 ( V_73 , 2 , 0 ) ;
}
static void F_50 ( struct V_72 * V_73 )
{
struct V_95 * V_98 = V_73 -> V_95 ;
unsigned long V_64 ;
if ( ! V_98 )
return;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( ! F_45 ( & V_73 -> V_99 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
goto V_100;
}
F_14 ( & V_73 -> V_99 , 0 ) ;
F_43 ( V_73 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
V_100:
F_33 ( & V_98 -> V_101 , V_64 ) ;
if ( F_45 ( & V_73 -> V_102 ) ) {
F_34 ( & V_73 -> V_103 ) ;
F_14 ( & V_73 -> V_102 , 0 ) ;
#if 0
pr_debug("Removed ITT: 0x%08x from LUN LIST[%d]\n"
cmd->se_tfo->get_task_tag(cmd), lun->unpacked_lun);
#endif
}
F_37 ( & V_98 -> V_101 , V_64 ) ;
}
void F_51 ( struct V_72 * V_73 , int remove )
{
if ( ! V_73 -> V_2 )
F_50 ( V_73 ) ;
if ( F_49 ( V_73 ) )
return;
if ( remove ) {
F_52 ( V_73 ) ;
F_53 ( V_73 ) ;
}
}
static void F_54 ( struct V_72 * V_73 , int V_88 ,
bool V_104 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_33 * V_34 = & V_75 -> V_105 ;
unsigned long V_64 ;
if ( V_88 ) {
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_73 -> V_88 = V_88 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
F_33 ( & V_34 -> V_38 , V_64 ) ;
if ( ! F_35 ( & V_73 -> V_106 ) )
F_34 ( & V_73 -> V_106 ) ;
else
F_55 ( & V_34 -> V_35 ) ;
if ( V_104 )
F_56 ( & V_73 -> V_106 , & V_34 -> V_36 ) ;
else
F_26 ( & V_73 -> V_106 , & V_34 -> V_36 ) ;
F_14 ( & V_73 -> V_107 , 1 ) ;
F_37 ( & V_34 -> V_38 , V_64 ) ;
F_57 ( & V_34 -> V_37 ) ;
}
static struct V_72 *
F_58 ( struct V_33 * V_34 )
{
struct V_72 * V_73 ;
unsigned long V_64 ;
F_33 ( & V_34 -> V_38 , V_64 ) ;
if ( F_35 ( & V_34 -> V_36 ) ) {
F_37 ( & V_34 -> V_38 , V_64 ) ;
return NULL ;
}
V_73 = F_59 ( & V_34 -> V_36 , struct V_72 , V_106 ) ;
F_14 ( & V_73 -> V_107 , 0 ) ;
F_60 ( & V_73 -> V_106 ) ;
F_46 ( & V_34 -> V_35 ) ;
F_37 ( & V_34 -> V_38 , V_64 ) ;
return V_73 ;
}
static void F_52 ( struct V_72 * V_73 )
{
struct V_33 * V_34 = & V_73 -> V_76 -> V_105 ;
unsigned long V_64 ;
F_33 ( & V_34 -> V_38 , V_64 ) ;
if ( ! F_45 ( & V_73 -> V_107 ) ) {
F_37 ( & V_34 -> V_38 , V_64 ) ;
return;
}
F_14 ( & V_73 -> V_107 , 0 ) ;
F_46 ( & V_34 -> V_35 ) ;
F_60 ( & V_73 -> V_106 ) ;
F_37 ( & V_34 -> V_38 , V_64 ) ;
if ( F_45 ( & V_73 -> V_107 ) ) {
F_4 ( L_37 ,
V_73 -> V_84 -> V_85 ( V_73 ) ,
F_45 ( & V_73 -> V_107 ) ) ;
}
}
void F_61 ( struct V_72 * V_73 , int V_108 )
{
struct V_77 * V_78 = F_62 ( V_73 -> V_109 . V_110 ,
struct V_77 , V_111 ) ;
if ( V_108 ) {
V_73 -> V_112 = V_113 ;
V_78 -> V_114 = V_115 ;
} else {
V_78 -> V_114 = V_116 ;
V_78 -> V_117 -> V_118 =
V_119 ;
}
F_63 ( V_78 , V_108 ) ;
}
static void F_64 ( struct V_120 * V_121 )
{
struct V_72 * V_73 = F_36 ( V_121 , struct V_72 , V_121 ) ;
F_65 ( V_73 ) ;
}
void F_63 ( struct V_77 * V_78 , int V_122 )
{
struct V_72 * V_73 = V_78 -> V_117 ;
struct V_74 * V_75 = V_73 -> V_76 ;
unsigned long V_64 ;
#if 0
pr_debug("task: %p CDB: 0x%02x obj_ptr: %p\n", task,
cmd->t_task_cdb[0], dev);
#endif
if ( V_75 )
F_55 ( & V_75 -> V_123 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_78 -> V_79 &= ~ V_80 ;
if ( V_75 && V_75 -> V_124 -> V_125 ) {
if ( V_75 -> V_124 -> V_125 ( V_78 ) != 0 ) {
V_73 -> V_126 |= V_127 ;
V_78 -> V_128 = 1 ;
V_122 = 1 ;
}
}
if ( V_78 -> V_79 & V_129 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_78 -> V_130 ) ;
return;
}
if ( ! V_122 )
V_73 -> V_131 = 1 ;
if ( ! F_66 ( & V_73 -> V_132 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return;
}
if ( V_73 -> V_131 ) {
if ( ! V_78 -> V_133 ) {
V_78 -> V_133 =
V_119 ;
V_73 -> V_118 =
V_119 ;
}
F_67 ( & V_73 -> V_121 , F_64 ) ;
} else {
F_14 ( & V_73 -> V_134 , 1 ) ;
F_67 ( & V_73 -> V_121 , V_135 ) ;
}
V_73 -> V_88 = V_136 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_68 ( V_25 , & V_73 -> V_121 ) ;
}
static inline int F_69 (
struct V_77 * V_78 ,
struct V_77 * V_137 ,
struct V_74 * V_75 )
{
if ( V_75 -> V_138 != V_139 ) {
F_26 ( & V_78 -> V_140 , & V_75 -> V_141 ) ;
return 0 ;
}
if ( V_78 -> V_117 -> V_142 == V_143 ) {
F_56 ( & V_78 -> V_140 ,
( V_137 != NULL ) ?
& V_137 -> V_140 :
& V_75 -> V_141 ) ;
F_28 ( L_38
L_39 ,
V_78 -> V_117 -> V_144 [ 0 ] ) ;
return 1 ;
}
F_26 ( & V_78 -> V_140 , & V_75 -> V_141 ) ;
return 0 ;
}
static void F_70 (
struct V_77 * V_78 ,
struct V_77 * V_137 ,
struct V_74 * V_75 )
{
int V_145 ;
V_145 = F_69 ( V_78 , V_137 , V_75 ) ;
F_55 ( & V_75 -> V_146 ) ;
if ( F_45 ( & V_78 -> V_81 ) )
return;
if ( V_145 )
F_56 ( & V_78 -> V_83 , ( V_137 ) ?
& V_137 -> V_83 :
& V_75 -> V_147 ) ;
else
F_26 ( & V_78 -> V_83 , & V_75 -> V_147 ) ;
F_14 ( & V_78 -> V_81 , 1 ) ;
F_28 ( L_40 ,
V_78 -> V_117 -> V_84 -> V_85 ( V_78 -> V_117 ) ,
V_78 , V_75 ) ;
}
static void F_71 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 ;
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_44 (task, &cmd->t_task_list, t_list) {
if ( F_45 ( & V_78 -> V_81 ) )
continue;
F_11 ( & V_75 -> V_82 ) ;
F_26 ( & V_78 -> V_83 , & V_75 -> V_147 ) ;
F_14 ( & V_78 -> V_81 , 1 ) ;
F_28 ( L_40 ,
V_78 -> V_117 -> V_84 -> V_85 (
V_78 -> V_117 ) , V_78 , V_75 ) ;
F_12 ( & V_75 -> V_82 ) ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
static void F_72 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 , * V_137 = NULL ;
unsigned long V_64 ;
F_33 ( & V_75 -> V_82 , V_64 ) ;
F_44 (task, &cmd->t_task_list, t_list) {
if ( ! F_35 ( & V_78 -> V_140 ) )
continue;
F_70 ( V_78 , V_137 , V_75 ) ;
V_137 = V_78 ;
}
F_37 ( & V_75 -> V_82 , V_64 ) ;
}
void F_73 ( struct V_77 * V_78 ,
struct V_74 * V_75 )
{
F_60 ( & V_78 -> V_140 ) ;
F_46 ( & V_75 -> V_146 ) ;
}
void F_74 (
struct V_77 * V_78 ,
struct V_74 * V_75 )
{
unsigned long V_64 ;
if ( F_75 ( F_35 ( & V_78 -> V_140 ) ) )
return;
F_33 ( & V_75 -> V_82 , V_64 ) ;
F_73 ( V_78 , V_75 ) ;
F_37 ( & V_75 -> V_82 , V_64 ) ;
}
static void F_76 ( struct V_120 * V_121 )
{
struct V_74 * V_75 = F_36 ( V_121 , struct V_74 ,
V_148 ) ;
F_77 ( V_149 ) ;
struct V_72 * V_73 , * V_150 ;
F_25 ( & V_75 -> V_151 ) ;
F_78 ( & V_75 -> V_149 , & V_149 ) ;
F_27 ( & V_75 -> V_151 ) ;
F_79 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_34 ( & V_73 -> V_152 ) ;
F_46 ( & V_75 -> V_153 ) ;
F_80 () ;
F_28 ( L_41
L_42 , V_73 -> V_84 -> V_62 () , V_73 ,
( V_73 -> V_88 == V_154 ) ? L_43 :
( V_73 -> V_88 == V_155 ) ? L_44
: L_45 ) ;
F_54 ( V_73 , V_73 -> V_88 , true ) ;
}
}
unsigned char * F_81 ( struct V_72 * V_73 )
{
switch ( V_73 -> V_156 ) {
case V_157 :
return L_46 ;
case V_158 :
return L_47 ;
case V_159 :
return L_48 ;
case V_160 :
return L_49 ;
default:
break;
}
return L_45 ;
}
void F_82 (
struct V_74 * V_75 ,
char * V_161 ,
int * V_162 )
{
* V_162 += sprintf ( V_161 + * V_162 , L_50 ) ;
switch ( V_75 -> V_163 ) {
case V_164 :
* V_162 += sprintf ( V_161 + * V_162 , L_51 ) ;
break;
case V_165 :
* V_162 += sprintf ( V_161 + * V_162 , L_52 ) ;
break;
case V_166 :
* V_162 += sprintf ( V_161 + * V_162 , L_53 ) ;
break;
case V_167 :
case V_168 :
* V_162 += sprintf ( V_161 + * V_162 , L_54 ) ;
break;
default:
* V_162 += sprintf ( V_161 + * V_162 , L_55 , V_75 -> V_163 ) ;
break;
}
* V_162 += sprintf ( V_161 + * V_162 , L_56 ,
F_45 ( & V_75 -> V_146 ) , F_45 ( & V_75 -> V_123 ) ,
V_75 -> V_169 ) ;
* V_162 += sprintf ( V_161 + * V_162 , L_57 ,
V_75 -> V_170 -> V_171 . V_172 , V_75 -> V_170 -> V_171 . V_173 ) ;
* V_162 += sprintf ( V_161 + * V_162 , L_58 ) ;
}
void F_83 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_53 [ V_178 ] ;
int V_179 ;
memset ( V_53 , 0 , V_178 ) ;
V_179 = sprintf ( V_53 , L_59 ) ;
switch ( V_175 -> V_180 ) {
case 0x00 :
sprintf ( V_53 + V_179 , L_60 ) ;
break;
case 0x10 :
sprintf ( V_53 + V_179 , L_61 ) ;
break;
case 0x20 :
sprintf ( V_53 + V_179 , L_62 ) ;
break;
case 0x30 :
sprintf ( V_53 + V_179 , L_63 ) ;
break;
case 0x40 :
sprintf ( V_53 + V_179 , L_64
L_65 ) ;
break;
case 0x50 :
sprintf ( V_53 + V_179 , L_66 ) ;
break;
case 0x60 :
sprintf ( V_53 + V_179 , L_67 ) ;
break;
case 0x70 :
sprintf ( V_53 + V_179 , L_68
L_65 ) ;
break;
case 0x80 :
sprintf ( V_53 + V_179 , L_69 ) ;
break;
default:
sprintf ( V_53 + V_179 , L_70 ,
V_175 -> V_180 ) ;
break;
}
if ( V_176 )
strncpy ( V_176 , V_53 , V_177 ) ;
else
F_28 ( L_71 , V_53 ) ;
}
void
F_84 ( struct V_174 * V_175 , unsigned char * V_181 )
{
if ( V_181 [ 1 ] & 0x80 ) {
V_175 -> V_180 = ( V_181 [ 0 ] & 0xf0 ) ;
V_175 -> V_182 = 1 ;
F_83 ( V_175 , NULL , 0 ) ;
}
}
int F_85 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_53 [ V_178 ] ;
int V_39 = 0 ;
int V_179 ;
memset ( V_53 , 0 , V_178 ) ;
V_179 = sprintf ( V_53 , L_72 ) ;
switch ( V_175 -> V_183 ) {
case 0x00 :
sprintf ( V_53 + V_179 , L_73 ) ;
break;
case 0x10 :
sprintf ( V_53 + V_179 , L_74 ) ;
break;
case 0x20 :
sprintf ( V_53 + V_179 , L_75 ) ;
break;
default:
sprintf ( V_53 + V_179 , L_70 , V_175 -> V_183 ) ;
V_39 = - V_184 ;
break;
}
if ( V_176 )
strncpy ( V_176 , V_53 , V_177 ) ;
else
F_28 ( L_71 , V_53 ) ;
return V_39 ;
}
int F_86 ( struct V_174 * V_175 , unsigned char * V_181 )
{
V_175 -> V_183 = ( V_181 [ 1 ] & 0x30 ) ;
return F_85 ( V_175 , NULL , 0 ) ;
}
int F_87 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_53 [ V_178 ] ;
int V_39 = 0 ;
int V_179 ;
memset ( V_53 , 0 , V_178 ) ;
V_179 = sprintf ( V_53 , L_76 ) ;
switch ( V_175 -> V_185 ) {
case 0x00 :
sprintf ( V_53 + V_179 , L_77 ) ;
break;
case 0x01 :
sprintf ( V_53 + V_179 , L_78 ) ;
break;
case 0x02 :
sprintf ( V_53 + V_179 , L_79 ) ;
break;
case 0x03 :
sprintf ( V_53 + V_179 , L_80 ) ;
break;
case 0x04 :
sprintf ( V_53 + V_179 , L_81 ) ;
break;
case 0x08 :
sprintf ( V_53 + V_179 , L_82 ) ;
break;
default:
sprintf ( V_53 + V_179 , L_83 ,
V_175 -> V_185 ) ;
V_39 = - V_184 ;
break;
}
if ( V_176 ) {
if ( V_177 < strlen ( V_53 ) + 1 )
return - V_184 ;
strncpy ( V_176 , V_53 , V_177 ) ;
} else {
F_28 ( L_71 , V_53 ) ;
}
return V_39 ;
}
int F_88 ( struct V_174 * V_175 , unsigned char * V_181 )
{
V_175 -> V_185 = ( V_181 [ 1 ] & 0x0f ) ;
return F_87 ( V_175 , NULL , 0 ) ;
}
int F_89 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_53 [ V_178 ] ;
int V_39 = 0 ;
memset ( V_53 , 0 , V_178 ) ;
switch ( V_175 -> V_186 ) {
case 0x01 :
sprintf ( V_53 , L_84 ,
& V_175 -> V_187 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_53 , L_85 ,
& V_175 -> V_187 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_53 , L_86 ,
& V_175 -> V_187 [ 0 ] ) ;
break;
default:
sprintf ( V_53 , L_87
L_88 , V_175 -> V_186 ) ;
V_39 = - V_184 ;
break;
}
if ( V_176 )
strncpy ( V_176 , V_53 , V_177 ) ;
else
F_28 ( L_71 , V_53 ) ;
return V_39 ;
}
int
F_90 ( struct V_174 * V_175 , unsigned char * V_181 )
{
static const char V_188 [] = L_89 ;
int V_189 = 0 , V_190 = 4 ;
V_175 -> V_186 = ( V_181 [ 0 ] & 0x0f ) ;
switch ( V_175 -> V_186 ) {
case 0x01 :
V_175 -> V_187 [ V_189 ++ ] =
V_188 [ V_175 -> V_185 ] ;
while ( V_190 < ( 4 + V_181 [ 3 ] ) ) {
V_175 -> V_187 [ V_189 ++ ] =
V_188 [ ( V_181 [ V_190 ] & 0xf0 ) >> 4 ] ;
V_175 -> V_187 [ V_189 ++ ] =
V_188 [ V_181 [ V_190 ] & 0x0f ] ;
V_190 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_190 < ( 4 + V_181 [ 3 ] ) )
V_175 -> V_187 [ V_189 ++ ] = V_181 [ V_190 ++ ] ;
break;
default:
break;
}
return F_89 ( V_175 , NULL , 0 ) ;
}
static void F_91 ( struct V_74 * V_75 )
{
if ( V_75 -> V_124 -> V_191 == V_192 ) {
V_75 -> V_138 = V_193 ;
return;
}
V_75 -> V_138 = V_139 ;
F_28 ( L_90
L_91 , V_75 -> V_124 -> V_194 ,
V_75 -> V_124 -> V_195 ( V_75 ) ) ;
}
static void F_92 ( struct V_74 * V_75 )
{
struct V_196 * V_197 = & V_75 -> V_170 -> V_196 ;
int V_190 , V_198 ;
F_28 ( L_92 ) ;
for ( V_190 = 0 ; V_190 < 8 ; V_190 ++ )
if ( V_197 -> V_199 [ V_190 ] >= 0x20 )
F_28 ( L_93 , V_197 -> V_199 [ V_190 ] ) ;
else
F_28 ( L_94 ) ;
F_28 ( L_95 ) ;
for ( V_190 = 0 ; V_190 < 16 ; V_190 ++ )
if ( V_197 -> V_200 [ V_190 ] >= 0x20 )
F_28 ( L_93 , V_197 -> V_200 [ V_190 ] ) ;
else
F_28 ( L_94 ) ;
F_28 ( L_96 ) ;
for ( V_190 = 0 ; V_190 < 4 ; V_190 ++ )
if ( V_197 -> V_201 [ V_190 ] >= 0x20 )
F_28 ( L_93 , V_197 -> V_201 [ V_190 ] ) ;
else
F_28 ( L_94 ) ;
F_28 ( L_97 ) ;
V_198 = V_75 -> V_124 -> V_202 ( V_75 ) ;
F_28 ( L_98 , F_93 ( V_198 ) ) ;
F_28 ( L_99 ,
V_75 -> V_124 -> V_195 ( V_75 ) ) ;
}
struct V_74 * F_94 (
struct V_203 * V_204 ,
struct V_205 * V_124 ,
struct V_206 * V_76 ,
T_1 V_207 ,
void * V_208 ,
struct V_209 * V_210 ,
const char * V_211 ,
const char * V_212 )
{
int V_213 ;
struct V_74 * V_75 ;
V_75 = F_95 ( sizeof( struct V_74 ) , V_42 ) ;
if ( ! V_75 ) {
F_4 ( L_100 ) ;
return NULL ;
}
F_13 ( & V_75 -> V_105 ) ;
V_75 -> V_214 = V_207 ;
V_75 -> V_163 |= V_165 ;
V_75 -> V_215 = V_208 ;
V_75 -> V_203 = V_204 ;
V_75 -> V_170 = V_76 ;
V_75 -> V_124 = V_124 ;
F_15 ( & V_75 -> V_216 ) ;
F_15 ( & V_75 -> V_217 ) ;
F_15 ( & V_75 -> V_218 ) ;
F_15 ( & V_75 -> V_141 ) ;
F_15 ( & V_75 -> V_219 ) ;
F_15 ( & V_75 -> V_147 ) ;
F_15 ( & V_75 -> V_149 ) ;
F_17 ( & V_75 -> V_82 ) ;
F_17 ( & V_75 -> V_220 ) ;
F_17 ( & V_75 -> V_221 ) ;
F_17 ( & V_75 -> V_222 ) ;
F_17 ( & V_75 -> V_223 ) ;
F_17 ( & V_75 -> V_224 ) ;
F_17 ( & V_75 -> V_151 ) ;
V_75 -> V_169 = V_210 -> V_169 ;
F_14 ( & V_75 -> V_123 , V_75 -> V_169 ) ;
F_14 ( & V_75 -> V_225 , 0 ) ;
F_96 ( V_75 , V_210 ) ;
V_75 -> V_226 = F_9 ( V_227 ) ;
V_75 -> V_228 = F_97 () ;
F_17 ( & V_75 -> V_229 ) ;
F_11 ( & V_204 -> V_230 ) ;
F_26 ( & V_75 -> V_216 , & V_204 -> V_231 ) ;
V_204 -> V_232 ++ ;
F_12 ( & V_204 -> V_230 ) ;
F_91 ( V_75 ) ;
V_213 = ( V_204 -> V_233 & V_234 ) ;
F_98 ( V_75 , V_213 ) ;
if ( F_99 ( V_75 , V_213 ) < 0 )
goto V_3;
V_75 -> V_235 = F_100 ( V_236 , V_75 ,
L_101 , V_75 -> V_124 -> V_194 ) ;
if ( F_101 ( V_75 -> V_235 ) ) {
F_4 ( L_102 ,
V_75 -> V_124 -> V_194 ) ;
goto V_3;
}
F_67 ( & V_75 -> V_148 , F_76 ) ;
if ( V_75 -> V_124 -> V_191 != V_192 ) {
if ( ! V_211 || ! V_212 ) {
F_4 ( L_103
L_104 ) ;
goto V_3;
}
strncpy ( & V_75 -> V_170 -> V_196 . V_199 [ 0 ] , L_105 , 8 ) ;
strncpy ( & V_75 -> V_170 -> V_196 . V_200 [ 0 ] , V_211 , 16 ) ;
strncpy ( & V_75 -> V_170 -> V_196 . V_201 [ 0 ] , V_212 , 4 ) ;
}
F_92 ( V_75 ) ;
return V_75 ;
V_3:
F_102 ( V_75 -> V_235 ) ;
F_11 ( & V_204 -> V_230 ) ;
F_34 ( & V_75 -> V_216 ) ;
V_204 -> V_232 -- ;
F_12 ( & V_204 -> V_230 ) ;
F_103 ( V_75 ) ;
F_104 ( V_75 ) ;
return NULL ;
}
static inline void F_105 (
unsigned char * V_237 )
{
switch ( V_237 [ 0 ] ) {
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
break;
default:
V_237 [ 1 ] &= 0x1f ;
break;
}
}
static struct V_77 *
F_106 ( struct V_72 * V_73 ,
enum V_246 V_156 )
{
struct V_77 * V_78 ;
struct V_74 * V_75 = V_73 -> V_76 ;
V_78 = V_75 -> V_124 -> V_247 ( V_73 -> V_144 ) ;
if ( ! V_78 ) {
F_4 ( L_106 ) ;
return NULL ;
}
F_15 ( & V_78 -> V_111 ) ;
F_15 ( & V_78 -> V_140 ) ;
F_15 ( & V_78 -> V_83 ) ;
F_107 ( & V_78 -> V_130 ) ;
V_78 -> V_117 = V_73 ;
V_78 -> V_248 = V_156 ;
return V_78 ;
}
void F_108 (
struct V_72 * V_73 ,
struct V_249 * V_250 ,
struct V_5 * V_41 ,
T_1 V_251 ,
int V_156 ,
int V_252 ,
unsigned char * V_253 )
{
F_15 ( & V_73 -> V_103 ) ;
F_15 ( & V_73 -> V_254 ) ;
F_15 ( & V_73 -> V_152 ) ;
F_15 ( & V_73 -> V_106 ) ;
F_15 ( & V_73 -> V_255 ) ;
F_15 ( & V_73 -> V_109 ) ;
F_107 ( & V_73 -> V_256 ) ;
F_107 ( & V_73 -> V_93 ) ;
F_107 ( & V_73 -> V_96 ) ;
F_107 ( & V_73 -> V_257 ) ;
F_17 ( & V_73 -> V_89 ) ;
F_14 ( & V_73 -> V_99 , 1 ) ;
V_73 -> V_84 = V_250 ;
V_73 -> V_41 = V_41 ;
V_73 -> V_251 = V_251 ;
V_73 -> V_156 = V_156 ;
V_73 -> V_142 = V_252 ;
V_73 -> V_253 = V_253 ;
}
static int F_109 ( struct V_72 * V_73 )
{
if ( V_73 -> V_76 -> V_138 != V_139 )
return 0 ;
if ( V_73 -> V_142 == V_258 ) {
F_28 ( L_107
L_108 ) ;
return - V_184 ;
}
V_73 -> V_259 = F_110 ( & V_73 -> V_76 -> V_225 ) ;
F_111 () ;
F_28 ( L_109 ,
V_73 -> V_259 , V_73 -> V_142 ,
V_73 -> V_76 -> V_124 -> V_194 ) ;
return 0 ;
}
int F_112 (
struct V_72 * V_73 ,
unsigned char * V_237 )
{
int V_39 ;
F_105 ( V_237 ) ;
if ( F_113 ( V_237 ) > V_260 ) {
F_4 ( L_110
L_111 ,
F_113 ( V_237 ) , V_260 ) ;
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_262 ;
return - V_184 ;
}
if ( F_113 ( V_237 ) > sizeof( V_73 -> V_263 ) ) {
V_73 -> V_144 = F_95 ( F_113 ( V_237 ) ,
V_42 ) ;
if ( ! V_73 -> V_144 ) {
F_4 ( L_112
L_113 ,
F_113 ( V_237 ) ,
( unsigned long ) sizeof( V_73 -> V_263 ) ) ;
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 =
V_119 ;
return - V_28 ;
}
} else
V_73 -> V_144 = & V_73 -> V_263 [ 0 ] ;
memcpy ( V_73 -> V_144 , V_237 , F_113 ( V_237 ) ) ;
V_39 = F_114 ( V_73 , V_237 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( F_109 ( V_73 ) < 0 ) {
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_262 ;
return - V_184 ;
}
F_11 ( & V_73 -> V_95 -> V_264 ) ;
if ( V_73 -> V_95 -> V_265 )
V_73 -> V_95 -> V_265 -> V_266 . V_267 ++ ;
F_12 ( & V_73 -> V_95 -> V_264 ) ;
return 0 ;
}
int F_115 (
struct V_72 * V_73 )
{
int V_39 ;
if ( ! V_73 -> V_95 ) {
F_116 () ;
F_4 ( L_114 ) ;
return - V_184 ;
}
if ( F_117 () ) {
F_116 () ;
F_4 ( L_115
L_116 ) ;
return - V_184 ;
}
V_73 -> V_88 = V_268 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
V_39 = F_118 ( V_73 ) ;
if ( V_39 < 0 )
F_65 ( V_73 ) ;
return 0 ;
}
int F_119 (
struct V_72 * V_73 )
{
if ( ! V_73 -> V_95 ) {
F_116 () ;
F_4 ( L_114 ) ;
return - V_184 ;
}
F_54 ( V_73 , V_269 , false ) ;
return 0 ;
}
int F_120 (
struct V_72 * V_73 )
{
if ( ! F_117 () && F_121 ( V_270 ) )
return - V_271 ;
if ( F_122 ( V_73 , 1 ) != 0 )
return 0 ;
F_54 ( V_73 , V_272 , false ) ;
return 0 ;
}
int F_123 (
struct V_72 * V_73 )
{
F_54 ( V_73 , V_273 , false ) ;
return 0 ;
}
bool F_124 ( struct V_77 * V_78 , unsigned long * V_64 )
{
struct V_72 * V_73 = V_78 -> V_117 ;
bool V_274 = false ;
if ( V_78 -> V_79 & V_80 ) {
V_78 -> V_79 |= V_129 ;
F_37 ( & V_73 -> V_89 , * V_64 ) ;
F_28 ( L_117 , V_78 ) ;
F_125 ( & V_78 -> V_130 ) ;
F_28 ( L_118 , V_78 ) ;
F_33 ( & V_73 -> V_89 , * V_64 ) ;
F_46 ( & V_73 -> V_132 ) ;
V_78 -> V_79 &= ~ ( V_80 | V_129 ) ;
V_274 = true ;
}
return V_274 ;
}
static int F_126 ( struct V_72 * V_73 )
{
struct V_77 * V_78 , * V_275 ;
unsigned long V_64 ;
int V_39 = 0 ;
F_28 ( L_119 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_79 (task, task_tmp,
&cmd->t_task_list, t_list) {
F_28 ( L_120 , V_78 ) ;
if ( ! ( V_78 -> V_79 & ( V_80 | V_276 ) ) ) {
F_37 ( & V_73 -> V_89 ,
V_64 ) ;
F_74 ( V_78 ,
V_73 -> V_76 ) ;
F_28 ( L_121 , V_78 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
continue;
}
if ( ! F_124 ( V_78 , & V_64 ) ) {
F_28 ( L_122 , V_78 ) ;
V_39 ++ ;
}
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
return V_39 ;
}
static void F_65 ( struct V_72 * V_73 )
{
int V_39 = 0 ;
F_28 ( L_123
L_124 , V_73 , V_73 -> V_84 -> V_85 ( V_73 ) ,
V_73 -> V_144 [ 0 ] ) ;
F_28 ( L_125 ,
V_73 -> V_84 -> V_277 ( V_73 ) ,
V_73 -> V_88 , V_73 -> V_118 ) ;
F_28 ( L_126
L_127
L_128
L_129 , V_73 -> V_278 ,
F_45 ( & V_73 -> V_132 ) ,
F_45 ( & V_73 -> V_279 ) ,
F_45 ( & V_73 -> V_86 ) ,
F_45 ( & V_73 -> V_92 ) ,
F_45 ( & V_73 -> V_94 ) ,
F_45 ( & V_73 -> V_280 ) ) ;
if ( V_73 -> V_76 -> V_138 == V_139 )
F_127 ( V_73 ) ;
switch ( V_73 -> V_118 ) {
case V_281 :
case V_282 :
case V_262 :
case V_283 :
case V_119 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
break;
case V_289 :
V_73 -> V_112 = V_290 ;
if ( V_73 -> V_41 &&
V_73 -> V_76 -> V_170 -> V_171 . V_291 == 2 )
F_128 ( V_73 -> V_41 -> V_50 ,
V_73 -> V_292 , 0x2C ,
V_293 ) ;
V_39 = V_73 -> V_84 -> V_294 ( V_73 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
goto V_297;
default:
F_4 ( L_130 ,
V_73 -> V_144 [ 0 ] , V_73 -> V_118 ) ;
V_73 -> V_118 = V_282 ;
break;
}
V_39 = F_129 ( V_73 ,
V_73 -> V_118 , 0 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
V_297:
F_50 ( V_73 ) ;
if ( ! F_49 ( V_73 ) )
;
return;
V_296:
V_73 -> V_88 = V_154 ;
F_130 ( V_73 , V_73 -> V_76 ) ;
}
static inline T_1 F_131 ( unsigned char * V_237 )
{
return ( ( V_237 [ 1 ] & 0x1f ) << 16 ) | ( V_237 [ 2 ] << 8 ) | V_237 [ 3 ] ;
}
static inline T_1 F_132 ( unsigned char * V_237 )
{
return ( V_237 [ 2 ] << 24 ) | ( V_237 [ 3 ] << 16 ) | ( V_237 [ 4 ] << 8 ) | V_237 [ 5 ] ;
}
static inline unsigned long long F_133 ( unsigned char * V_237 )
{
unsigned int V_298 , V_299 ;
V_298 = ( V_237 [ 2 ] << 24 ) | ( V_237 [ 3 ] << 16 ) | ( V_237 [ 4 ] << 8 ) | V_237 [ 5 ] ;
V_299 = ( V_237 [ 6 ] << 24 ) | ( V_237 [ 7 ] << 16 ) | ( V_237 [ 8 ] << 8 ) | V_237 [ 9 ] ;
return ( ( unsigned long long ) V_299 ) | ( unsigned long long ) V_298 << 32 ;
}
static inline unsigned long long F_134 ( unsigned char * V_237 )
{
unsigned int V_298 , V_299 ;
V_298 = ( V_237 [ 12 ] << 24 ) | ( V_237 [ 13 ] << 16 ) | ( V_237 [ 14 ] << 8 ) | V_237 [ 15 ] ;
V_299 = ( V_237 [ 16 ] << 24 ) | ( V_237 [ 17 ] << 16 ) | ( V_237 [ 18 ] << 8 ) | V_237 [ 19 ] ;
return ( ( unsigned long long ) V_299 ) | ( unsigned long long ) V_298 << 32 ;
}
static void F_135 ( struct V_72 * V_72 )
{
unsigned long V_64 ;
F_33 ( & V_72 -> V_89 , V_64 ) ;
V_72 -> V_126 |= V_300 ;
F_37 ( & V_72 -> V_89 , V_64 ) ;
}
static inline int F_136 ( struct V_74 * V_75 )
{
if ( V_75 -> V_301 ++ <
V_302 ) {
F_137 ( V_303 ) ;
} else
F_137 ( V_304 ) ;
F_57 ( & V_75 -> V_105 . V_37 ) ;
return 0 ;
}
static inline int F_138 ( struct V_72 * V_73 )
{
if ( V_73 -> V_76 -> V_138 != V_139 )
return 1 ;
if ( V_73 -> V_142 == V_143 ) {
F_28 ( L_131
L_132 ,
V_73 -> V_144 [ 0 ] ,
V_73 -> V_259 ) ;
return 1 ;
} else if ( V_73 -> V_142 == V_305 ) {
F_55 ( & V_73 -> V_76 -> V_306 ) ;
F_111 () ;
F_28 ( L_133
L_134 ,
V_73 -> V_144 [ 0 ] ,
V_73 -> V_259 ) ;
if ( ! F_45 ( & V_73 -> V_76 -> V_307 ) )
return 1 ;
} else {
F_55 ( & V_73 -> V_76 -> V_307 ) ;
F_111 () ;
}
if ( F_45 ( & V_73 -> V_76 -> V_306 ) != 0 ) {
F_11 ( & V_73 -> V_76 -> V_220 ) ;
V_73 -> V_126 |= V_308 ;
F_26 ( & V_73 -> V_254 ,
& V_73 -> V_76 -> V_219 ) ;
F_12 ( & V_73 -> V_76 -> V_220 ) ;
F_28 ( L_135
L_136 ,
V_73 -> V_144 [ 0 ] , V_73 -> V_142 ,
V_73 -> V_259 ) ;
return 0 ;
}
return 1 ;
}
static int F_139 ( struct V_72 * V_73 )
{
int V_309 ;
if ( F_140 ( V_73 -> V_76 ) != 0 ) {
V_73 -> V_118 = V_119 ;
F_65 ( V_73 ) ;
return 0 ;
}
if ( ! F_47 ( V_73 , 0 , V_310 ) ) {
V_309 = F_138 ( V_73 ) ;
if ( ! V_309 )
goto V_146;
F_72 ( V_73 ) ;
}
V_146:
F_141 ( V_73 -> V_76 ) ;
return 0 ;
}
static int F_141 ( struct V_74 * V_75 )
{
int error ;
struct V_72 * V_73 = NULL ;
struct V_77 * V_78 = NULL ;
unsigned long V_64 ;
V_311:
if ( ! F_45 ( & V_75 -> V_123 ) )
return F_136 ( V_75 ) ;
V_75 -> V_301 = 0 ;
F_25 ( & V_75 -> V_82 ) ;
if ( F_35 ( & V_75 -> V_141 ) ) {
F_27 ( & V_75 -> V_82 ) ;
return 0 ;
}
V_78 = F_59 ( & V_75 -> V_141 ,
struct V_77 , V_140 ) ;
F_73 ( V_78 , V_75 ) ;
F_27 ( & V_75 -> V_82 ) ;
F_46 ( & V_75 -> V_123 ) ;
V_73 = V_78 -> V_117 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_78 -> V_79 |= ( V_80 | V_276 ) ;
F_55 ( & V_73 -> V_279 ) ;
if ( F_45 ( & V_73 -> V_279 ) ==
V_73 -> V_278 )
F_14 ( & V_73 -> V_280 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_312 )
error = V_73 -> V_312 ( V_78 ) ;
else
error = V_75 -> V_124 -> V_313 ( V_78 ) ;
if ( error != 0 ) {
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_78 -> V_79 &= ~ V_80 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_14 ( & V_73 -> V_280 , 0 ) ;
F_126 ( V_73 ) ;
F_55 ( & V_75 -> V_123 ) ;
F_65 ( V_73 ) ;
}
goto V_311;
return 0 ;
}
static inline T_1 F_142 (
unsigned char * V_237 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_314;
if ( V_75 -> V_124 -> V_202 ( V_75 ) == V_315 )
return ( T_1 ) ( V_237 [ 2 ] << 16 ) + ( V_237 [ 3 ] << 8 ) + V_237 [ 4 ] ;
V_314:
return V_237 [ 4 ] ? : 256 ;
}
static inline T_1 F_143 (
unsigned char * V_237 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_314;
if ( V_75 -> V_124 -> V_202 ( V_75 ) == V_315 ) {
* V_39 = - V_184 ;
return 0 ;
}
V_314:
return ( T_1 ) ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
}
static inline T_1 F_144 (
unsigned char * V_237 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_314;
if ( V_75 -> V_124 -> V_202 ( V_75 ) == V_315 ) {
* V_39 = - V_184 ;
return 0 ;
}
V_314:
return ( T_1 ) ( V_237 [ 6 ] << 24 ) + ( V_237 [ 7 ] << 16 ) + ( V_237 [ 8 ] << 8 ) + V_237 [ 9 ] ;
}
static inline T_1 F_145 (
unsigned char * V_237 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_314;
if ( V_75 -> V_124 -> V_202 ( V_75 ) == V_315 )
return ( T_1 ) ( V_237 [ 12 ] << 16 ) + ( V_237 [ 13 ] << 8 ) + V_237 [ 14 ] ;
V_314:
return ( T_1 ) ( V_237 [ 10 ] << 24 ) + ( V_237 [ 11 ] << 16 ) +
( V_237 [ 12 ] << 8 ) + V_237 [ 13 ] ;
}
static inline T_1 F_146 (
unsigned char * V_237 ,
struct V_72 * V_73 ,
int * V_39 )
{
return ( T_1 ) ( V_237 [ 28 ] << 24 ) + ( V_237 [ 29 ] << 16 ) +
( V_237 [ 30 ] << 8 ) + V_237 [ 31 ] ;
}
static inline T_1 F_147 (
T_1 V_316 ,
unsigned char * V_237 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( V_75 -> V_124 -> V_202 ( V_75 ) == V_315 ) {
if ( V_237 [ 1 ] & 1 ) {
return V_75 -> V_170 -> V_171 . V_172 * V_316 ;
} else
return V_316 ;
}
#if 0
pr_debug("Returning block_size: %u, sectors: %u == %u for"
" %s object\n", dev->se_sub_dev->se_dev_attrib.block_size, sectors,
dev->se_sub_dev->se_dev_attrib.block_size * sectors,
dev->transport->name);
#endif
return V_75 -> V_170 -> V_171 . V_172 * V_316 ;
}
static void F_148 ( struct V_72 * V_73 )
{
unsigned char * V_53 , * V_317 ;
struct V_318 * V_319 ;
unsigned int V_320 ;
int V_190 ;
int V_321 ;
V_53 = F_149 ( V_73 -> V_251 , V_42 ) ;
if ( ! V_53 ) {
F_4 ( L_137 ) ;
return;
}
F_150 ( V_73 -> V_322 ,
V_73 -> V_323 ,
V_53 ,
V_73 -> V_251 ) ;
V_320 = 0 ;
F_151 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_317 = F_152 ( F_153 ( V_319 ) , V_324 ) ;
if ( ! V_317 )
goto V_3;
for ( V_190 = 0 ; V_190 < V_319 -> V_325 ; V_190 ++ )
* ( V_317 + V_319 -> V_320 + V_190 ) ^= * ( V_53 + V_320 + V_190 ) ;
V_320 += V_319 -> V_325 ;
F_154 ( V_317 , V_324 ) ;
}
V_3:
F_104 ( V_53 ) ;
}
static int F_155 ( struct V_72 * V_73 )
{
unsigned char * V_326 = V_73 -> V_253 , * V_253 = NULL ;
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 = NULL , * V_275 ;
unsigned long V_64 ;
T_1 V_320 = 0 ;
F_75 ( ! V_73 -> V_95 ) ;
if ( ! V_75 )
return 0 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_126 & V_327 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 0 ;
}
F_79 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! V_78 -> V_128 )
continue;
if ( ! V_75 -> V_124 -> V_328 ) {
F_4 ( L_138
L_139 ) ;
continue;
}
V_253 = V_75 -> V_124 -> V_328 ( V_78 ) ;
if ( ! V_253 ) {
F_4 ( L_140
L_141 ,
V_73 -> V_84 -> V_85 ( V_73 ) , V_78 ) ;
continue;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
V_320 = V_73 -> V_84 -> V_329 ( V_73 ,
V_330 ) ;
memcpy ( & V_326 [ V_320 ] , V_253 ,
V_330 ) ;
V_73 -> V_112 = V_78 -> V_114 ;
V_73 -> V_331 =
( V_330 + V_320 ) ;
F_28 ( L_142
L_143 ,
V_75 -> V_203 -> V_332 , V_75 -> V_124 -> V_194 ,
V_73 -> V_112 ) ;
return 0 ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
return - 1 ;
}
static inline long long F_156 ( struct V_74 * V_75 )
{
return V_75 -> V_124 -> V_333 ( V_75 ) + 1 ;
}
static int F_157 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
T_1 V_316 ;
if ( V_75 -> V_124 -> V_202 ( V_75 ) != V_334 )
return 0 ;
V_316 = ( V_73 -> V_251 / V_75 -> V_170 -> V_171 . V_172 ) ;
if ( ( V_73 -> V_335 + V_316 ) > F_156 ( V_75 ) ) {
F_4 ( L_144
L_145 ,
V_73 -> V_335 , V_316 ,
F_156 ( V_75 ) ) ;
return - V_184 ;
}
return 0 ;
}
static int F_158 ( unsigned char * V_64 , struct V_74 * V_75 )
{
int V_336 = ( V_75 -> V_124 -> V_191 ==
V_192 ) ;
if ( ! V_336 ) {
if ( ( V_64 [ 0 ] & 0x04 ) || ( V_64 [ 0 ] & 0x02 ) ) {
F_4 ( L_146
L_147
L_148 ) ;
return - V_337 ;
}
if ( ! ( V_64 [ 0 ] & 0x08 ) ) {
F_4 ( L_149
L_150 ) ;
return - V_337 ;
}
}
return 0 ;
}
static int F_114 (
struct V_72 * V_73 ,
unsigned char * V_237 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_206 * V_338 = V_75 -> V_170 ;
int V_39 = 0 , V_339 = 0 , V_336 ;
T_1 V_316 = 0 , V_340 = 0 , V_341 = 0 ;
T_4 V_342 ;
T_3 V_343 = 0 ;
if ( F_159 ( V_73 , V_237 ) < 0 ) {
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_287 ;
return - V_184 ;
}
V_39 = V_338 -> V_344 . V_345 ( V_73 , V_237 , & V_343 ) ;
if ( V_39 != 0 ) {
if ( V_39 > 0 ) {
#if 0
pr_debug("[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
#endif
F_160 ( V_73 , 0x04 , V_343 ) ;
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_288 ;
return - V_184 ;
}
goto V_346;
}
if ( V_338 -> V_347 . V_348 . V_349 ( V_73 , & V_341 ) != 0 ) {
if ( V_338 -> V_347 . V_348 . V_350 (
V_73 , V_237 , V_341 ) != 0 ) {
V_73 -> V_126 |= V_261 ;
V_73 -> V_126 |= V_351 ;
V_73 -> V_118 = V_289 ;
return - V_352 ;
}
}
V_336 =
( V_75 -> V_124 -> V_191 == V_192 ) ;
switch ( V_237 [ 0 ] ) {
case V_353 :
V_316 = F_142 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_131 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
break;
case V_238 :
V_316 = F_143 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_132 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
break;
case V_239 :
V_316 = F_144 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_132 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
break;
case V_240 :
V_316 = F_145 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_133 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
break;
case V_356 :
V_316 = F_142 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_131 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
break;
case V_357 :
V_316 = F_143 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_132 ( V_237 ) ;
if ( V_237 [ 1 ] & 0x8 )
V_73 -> V_126 |= V_358 ;
V_73 -> V_126 |= V_355 ;
break;
case V_359 :
V_316 = F_144 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_132 ( V_237 ) ;
if ( V_237 [ 1 ] & 0x8 )
V_73 -> V_126 |= V_358 ;
V_73 -> V_126 |= V_355 ;
break;
case V_360 :
V_316 = F_145 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_133 ( V_237 ) ;
if ( V_237 [ 1 ] & 0x8 )
V_73 -> V_126 |= V_358 ;
V_73 -> V_126 |= V_355 ;
break;
case V_361 :
if ( ( V_73 -> V_156 != V_159 ) ||
! ( V_73 -> V_126 & V_362 ) )
goto V_346;
V_316 = F_143 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_132 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
if ( V_336 )
goto V_354;
V_73 -> V_363 = & F_148 ;
if ( V_237 [ 1 ] & 0x8 )
V_73 -> V_126 |= V_358 ;
break;
case V_364 :
V_342 = F_161 ( & V_237 [ 8 ] ) ;
switch ( V_342 ) {
case V_365 :
V_316 = F_146 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_335 = F_134 ( V_237 ) ;
V_73 -> V_126 |= V_355 ;
if ( V_336 )
goto V_354;
V_73 -> V_363 = & F_148 ;
if ( V_237 [ 1 ] & 0x8 )
V_73 -> V_126 |= V_358 ;
break;
case V_366 :
V_316 = F_146 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
if ( V_316 )
V_340 = F_147 ( 1 , V_237 , V_73 ) ;
else {
F_4 ( L_151
L_152 ) ;
goto V_346;
}
V_73 -> V_335 = F_24 ( & V_237 [ 12 ] ) ;
V_73 -> V_126 |= V_367 ;
if ( F_158 ( & V_237 [ 10 ] , V_75 ) < 0 )
goto V_346;
if ( ! V_336 )
V_73 -> V_312 = V_368 ;
break;
default:
F_4 ( L_153
L_154 , V_342 ) ;
goto V_354;
}
break;
case V_369 :
if ( V_75 -> V_124 -> V_202 ( V_75 ) != V_370 ) {
if ( V_237 [ 1 ] == V_371 &&
V_338 -> V_344 . V_372 == V_373 ) {
V_73 -> V_312 =
V_374 ;
}
V_340 = ( V_237 [ 6 ] << 24 ) | ( V_237 [ 7 ] << 16 ) |
( V_237 [ 8 ] << 8 ) | V_237 [ 9 ] ;
} else {
V_340 = ( V_237 [ 8 ] << 8 ) + V_237 [ 9 ] ;
}
V_73 -> V_126 |= V_367 ;
break;
case V_375 :
V_340 = V_237 [ 4 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_376 :
V_340 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_377 :
V_340 = V_237 [ 4 ] ;
V_73 -> V_126 |= V_367 ;
if ( ! V_336 )
V_73 -> V_312 = V_378 ;
break;
case V_379 :
V_340 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
if ( ! V_336 )
V_73 -> V_312 = V_378 ;
break;
case V_380 :
case V_381 :
case V_382 :
case V_383 :
V_340 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_384 :
V_340 = V_385 ;
V_73 -> V_126 |= V_367 ;
break;
case V_386 :
case V_387 :
case V_388 :
case V_389 :
V_340 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_390 :
if ( V_338 -> V_347 . V_391 == V_392 )
V_73 -> V_312 = V_393 ;
V_340 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_394 :
if ( V_338 -> V_347 . V_391 == V_392 )
V_73 -> V_312 = V_395 ;
V_340 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_396 :
case V_397 :
V_340 = ( V_237 [ 8 ] << 8 ) + V_237 [ 9 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_398 :
V_340 = V_399 ;
V_73 -> V_126 |= V_367 ;
break;
case V_400 :
if ( V_75 -> V_124 -> V_202 ( V_75 ) != V_370 ) {
if ( V_237 [ 1 ] == V_401 &&
V_338 -> V_344 . V_372 == V_373 ) {
V_73 -> V_312 =
V_402 ;
}
V_340 = ( V_237 [ 6 ] << 24 ) | ( V_237 [ 7 ] << 16 ) |
( V_237 [ 8 ] << 8 ) | V_237 [ 9 ] ;
} else {
V_340 = ( V_237 [ 8 ] << 8 ) + V_237 [ 9 ] ;
}
V_73 -> V_126 |= V_367 ;
break;
case V_403 :
V_340 = ( V_237 [ 3 ] << 8 ) + V_237 [ 4 ] ;
if ( V_73 -> V_76 -> V_138 == V_139 )
V_73 -> V_142 = V_143 ;
V_73 -> V_126 |= V_367 ;
if ( ! V_336 )
V_73 -> V_312 = V_404 ;
break;
case V_405 :
V_340 = ( V_237 [ 6 ] << 16 ) + ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_406 :
V_340 = V_407 ;
V_73 -> V_126 |= V_367 ;
if ( ! V_336 )
V_73 -> V_312 = V_408 ;
break;
case V_409 :
case V_410 :
case V_411 :
V_340 = ( V_237 [ 6 ] << 24 ) | ( V_237 [ 7 ] << 16 ) | ( V_237 [ 8 ] << 8 ) | V_237 [ 9 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_412 :
switch ( V_73 -> V_144 [ 1 ] & 0x1f ) {
case V_413 :
if ( ! V_336 )
V_73 -> V_312 =
V_414 ;
break;
default:
if ( V_336 )
break;
F_4 ( L_155 ,
V_73 -> V_144 [ 1 ] & 0x1f ) ;
goto V_354;
}
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
V_340 = ( V_237 [ 10 ] << 24 ) | ( V_237 [ 11 ] << 16 ) |
( V_237 [ 12 ] << 8 ) | V_237 [ 13 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_421 :
case V_241 :
V_340 = ( V_237 [ 3 ] << 8 ) | V_237 [ 4 ] ;
V_73 -> V_126 |= V_367 ;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#endif
case V_422 :
V_340 = V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_423 :
V_340 = V_237 [ 4 ] ;
V_73 -> V_126 |= V_367 ;
if ( ! V_336 )
V_73 -> V_312 = V_424 ;
break;
case V_425 :
V_340 = 65536 * V_237 [ 7 ] + 256 * V_237 [ 8 ] + V_237 [ 9 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_426 :
V_340 = ( V_237 [ 6 ] << 16 ) + ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_73 -> V_126 |= V_367 ;
break;
case V_427 :
case V_428 :
if ( V_237 [ 0 ] == V_428 )
V_340 = ( V_237 [ 7 ] << 8 ) | V_237 [ 8 ] ;
else
V_340 = V_73 -> V_251 ;
if ( V_338 -> V_347 . V_391 != V_429 )
V_73 -> V_312 = V_430 ;
V_73 -> V_126 |= V_431 ;
break;
case V_432 :
case V_433 :
if ( V_237 [ 0 ] == V_433 )
V_340 = ( V_237 [ 7 ] << 8 ) | V_237 [ 8 ] ;
else
V_340 = V_73 -> V_251 ;
if ( V_338 -> V_347 . V_391 != V_429 )
V_73 -> V_312 = V_434 ;
V_73 -> V_126 |= V_431 ;
break;
case V_435 :
case 0x91 :
if ( V_237 [ 0 ] == V_435 ) {
V_316 = F_143 ( V_237 , V_73 , & V_339 ) ;
V_73 -> V_335 = F_132 ( V_237 ) ;
} else {
V_316 = F_145 ( V_237 , V_73 , & V_339 ) ;
V_73 -> V_335 = F_133 ( V_237 ) ;
}
if ( V_339 )
goto V_354;
V_340 = F_147 ( V_316 , V_237 , V_73 ) ;
V_73 -> V_126 |= V_431 ;
if ( V_336 )
break;
if ( ( V_73 -> V_335 != 0 ) || ( V_316 != 0 ) ) {
if ( F_157 ( V_73 ) < 0 )
goto V_346;
}
V_73 -> V_312 = V_436 ;
break;
case V_437 :
V_340 = F_161 ( & V_237 [ 7 ] ) ;
V_73 -> V_126 |= V_367 ;
if ( ! V_336 )
V_73 -> V_312 = V_438 ;
break;
case V_439 :
V_316 = F_145 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
if ( V_316 )
V_340 = F_147 ( 1 , V_237 , V_73 ) ;
else {
F_4 ( L_156 ) ;
goto V_346;
}
V_73 -> V_335 = F_24 ( & V_237 [ 2 ] ) ;
V_73 -> V_126 |= V_367 ;
if ( F_158 ( & V_237 [ 1 ] , V_75 ) < 0 )
goto V_346;
if ( ! V_336 )
V_73 -> V_312 = V_368 ;
break;
case V_440 :
V_316 = F_143 ( V_237 , V_73 , & V_339 ) ;
if ( V_339 )
goto V_354;
if ( V_316 )
V_340 = F_147 ( 1 , V_237 , V_73 ) ;
else {
F_4 ( L_156 ) ;
goto V_346;
}
V_73 -> V_335 = F_162 ( & V_237 [ 2 ] ) ;
V_73 -> V_126 |= V_367 ;
if ( F_158 ( & V_237 [ 1 ] , V_75 ) < 0 )
goto V_346;
if ( ! V_336 )
V_73 -> V_312 = V_368 ;
break;
case V_441 :
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_242 :
case V_448 :
V_73 -> V_126 |= V_431 ;
if ( ! V_336 )
V_73 -> V_312 = V_449 ;
break;
case V_450 :
case V_451 :
case V_452 :
case V_453 :
case V_454 :
V_73 -> V_126 |= V_431 ;
break;
case V_455 :
V_73 -> V_312 = V_456 ;
V_340 = ( V_237 [ 6 ] << 24 ) | ( V_237 [ 7 ] << 16 ) | ( V_237 [ 8 ] << 8 ) | V_237 [ 9 ] ;
if ( V_73 -> V_76 -> V_138 == V_139 )
V_73 -> V_142 = V_143 ;
V_73 -> V_126 |= V_367 ;
break;
default:
F_163 ( L_157
L_158 ,
V_73 -> V_84 -> V_62 () , V_237 [ 0 ] ) ;
goto V_354;
}
if ( V_340 != V_73 -> V_251 ) {
F_163 ( L_159
L_160
L_161 , V_73 -> V_84 -> V_62 () ,
V_73 -> V_251 , V_340 , V_237 [ 0 ] ) ;
V_73 -> V_457 = V_340 ;
if ( V_73 -> V_156 == V_159 ) {
F_4 ( L_162
L_163 ) ;
goto V_346;
}
if ( ! V_39 && ( V_75 -> V_170 -> V_171 . V_172 != 512 ) ) {
F_4 ( L_164
L_165
L_166 , V_75 -> V_124 -> V_194 ) ;
goto V_346;
}
if ( V_340 > V_73 -> V_251 ) {
V_73 -> V_126 |= V_458 ;
V_73 -> V_459 = ( V_340 - V_73 -> V_251 ) ;
} else {
V_73 -> V_126 |= V_460 ;
V_73 -> V_459 = ( V_73 -> V_251 - V_340 ) ;
}
V_73 -> V_251 = V_340 ;
}
if ( ! ( V_336 || V_73 -> V_312 ||
( V_73 -> V_126 & V_355 ) ) )
goto V_354;
if ( ( V_73 -> V_126 & V_367 ) &&
V_340 > V_461 )
goto V_346;
F_135 ( V_73 ) ;
return V_39 ;
V_354:
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_282 ;
return - V_184 ;
V_346:
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_262 ;
return - V_184 ;
}
static void F_127 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_72 * V_462 , * V_150 ;
int V_463 = 0 ;
if ( V_73 -> V_142 == V_464 ) {
F_46 ( & V_75 -> V_307 ) ;
F_80 () ;
V_75 -> V_465 ++ ;
F_28 ( L_167
L_168 , V_75 -> V_465 ,
V_73 -> V_259 ) ;
} else if ( V_73 -> V_142 == V_143 ) {
V_75 -> V_465 ++ ;
F_28 ( L_169
L_170 , V_75 -> V_465 ,
V_73 -> V_259 ) ;
} else if ( V_73 -> V_142 == V_305 ) {
F_46 ( & V_75 -> V_306 ) ;
F_80 () ;
V_75 -> V_465 ++ ;
F_28 ( L_171
L_172 , V_75 -> V_465 , V_73 -> V_259 ) ;
}
F_11 ( & V_75 -> V_220 ) ;
F_79 (cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_node) {
F_34 ( & V_462 -> V_254 ) ;
F_12 ( & V_75 -> V_220 ) ;
F_28 ( L_173
L_174
L_175 ,
V_462 -> V_144 [ 0 ] ,
V_462 -> V_142 , V_462 -> V_259 ) ;
F_72 ( V_462 ) ;
V_463 ++ ;
F_11 ( & V_75 -> V_220 ) ;
if ( V_462 -> V_142 == V_305 )
break;
}
F_12 ( & V_75 -> V_220 ) ;
if ( V_463 != 0 )
F_57 ( & V_75 -> V_105 . V_37 ) ;
}
static void F_164 ( struct V_72 * V_73 )
{
int V_39 = 0 ;
if ( V_73 -> V_76 -> V_138 == V_139 )
F_127 ( V_73 ) ;
if ( V_73 -> V_126 & V_127 ) {
V_39 = V_73 -> V_84 -> V_294 ( V_73 ) ;
if ( V_39 )
goto V_3;
}
switch ( V_73 -> V_156 ) {
case V_158 :
V_39 = V_73 -> V_84 -> V_466 ( V_73 ) ;
break;
case V_159 :
if ( V_73 -> V_467 ) {
V_39 = V_73 -> V_84 -> V_466 ( V_73 ) ;
if ( V_39 < 0 )
break;
}
case V_157 :
V_39 = V_73 -> V_84 -> V_294 ( V_73 ) ;
break;
default:
break;
}
V_3:
if ( V_39 < 0 ) {
F_130 ( V_73 , V_73 -> V_76 ) ;
return;
}
F_50 ( V_73 ) ;
F_49 ( V_73 ) ;
}
static void F_130 (
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
F_25 ( & V_75 -> V_151 ) ;
F_26 ( & V_73 -> V_152 , & V_73 -> V_76 -> V_149 ) ;
F_55 ( & V_75 -> V_153 ) ;
F_111 () ;
F_27 ( & V_73 -> V_76 -> V_151 ) ;
F_165 ( & V_73 -> V_76 -> V_148 ) ;
}
static void V_135 ( struct V_120 * V_121 )
{
struct V_72 * V_73 = F_36 ( V_121 , struct V_72 , V_121 ) ;
int V_468 = 0 , V_39 ;
if ( V_73 -> V_76 -> V_138 == V_139 )
F_127 ( V_73 ) ;
if ( F_45 ( & V_73 -> V_76 -> V_153 ) != 0 )
F_165 ( & V_73 -> V_76 -> V_148 ) ;
if ( V_73 -> V_126 & V_127 ) {
if ( F_155 ( V_73 ) < 0 )
V_468 = V_281 ;
if ( V_73 -> V_112 ) {
V_39 = F_129 (
V_73 , V_468 , 1 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
F_50 ( V_73 ) ;
F_49 ( V_73 ) ;
return;
}
}
if ( V_73 -> V_363 )
V_73 -> V_363 ( V_73 ) ;
switch ( V_73 -> V_156 ) {
case V_158 :
F_11 ( & V_73 -> V_95 -> V_264 ) ;
if ( V_73 -> V_95 -> V_265 ) {
V_73 -> V_95 -> V_265 -> V_266 . V_469 +=
V_73 -> V_251 ;
}
F_12 ( & V_73 -> V_95 -> V_264 ) ;
V_39 = V_73 -> V_84 -> V_466 ( V_73 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
break;
case V_159 :
F_11 ( & V_73 -> V_95 -> V_264 ) ;
if ( V_73 -> V_95 -> V_265 ) {
V_73 -> V_95 -> V_265 -> V_266 . V_470 +=
V_73 -> V_251 ;
}
F_12 ( & V_73 -> V_95 -> V_264 ) ;
if ( V_73 -> V_467 ) {
F_11 ( & V_73 -> V_95 -> V_264 ) ;
if ( V_73 -> V_95 -> V_265 ) {
V_73 -> V_95 -> V_265 -> V_266 . V_469 +=
V_73 -> V_251 ;
}
F_12 ( & V_73 -> V_95 -> V_264 ) ;
V_39 = V_73 -> V_84 -> V_466 ( V_73 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
break;
}
case V_157 :
V_39 = V_73 -> V_84 -> V_294 ( V_73 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
break;
default:
break;
}
F_50 ( V_73 ) ;
F_49 ( V_73 ) ;
return;
V_296:
F_28 ( L_176
L_177 , V_73 , V_73 -> V_156 ) ;
V_73 -> V_88 = V_154 ;
F_130 ( V_73 , V_73 -> V_76 ) ;
}
static void F_166 ( struct V_72 * V_73 )
{
struct V_77 * V_78 , * V_275 ;
unsigned long V_64 ;
F_77 ( V_471 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_79 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! ( V_78 -> V_79 & V_80 ) )
F_167 ( & V_78 -> V_111 , & V_471 ) ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
while ( ! F_35 ( & V_471 ) ) {
V_78 = F_59 ( & V_471 , struct V_77 , V_111 ) ;
if ( V_78 -> V_472 != V_73 -> V_322 &&
V_78 -> V_472 != V_73 -> V_467 )
F_104 ( V_78 -> V_472 ) ;
F_34 ( & V_78 -> V_111 ) ;
V_73 -> V_76 -> V_124 -> V_473 ( V_78 ) ;
}
}
static inline void F_168 ( struct V_318 * V_474 , int V_475 )
{
struct V_318 * V_319 ;
int V_321 ;
F_151 (sgl, sg, nents, count)
F_169 ( F_153 ( V_319 ) ) ;
F_104 ( V_474 ) ;
}
static inline void F_170 ( struct V_72 * V_73 )
{
if ( V_73 -> V_126 & V_476 )
return;
F_168 ( V_73 -> V_322 , V_73 -> V_323 ) ;
V_73 -> V_322 = NULL ;
V_73 -> V_323 = 0 ;
F_168 ( V_73 -> V_467 , V_73 -> V_477 ) ;
V_73 -> V_467 = NULL ;
V_73 -> V_477 = 0 ;
}
static void F_53 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
int V_478 = 0 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( F_45 ( & V_73 -> V_479 ) ) {
if ( ! F_66 ( & V_73 -> V_479 ) )
goto V_480;
}
if ( F_45 ( & V_73 -> V_481 ) ) {
if ( ! F_66 ( & V_73 -> V_481 ) )
goto V_480;
}
if ( F_45 ( & V_73 -> V_99 ) ) {
F_14 ( & V_73 -> V_99 , 0 ) ;
F_43 ( V_73 ) ;
V_478 = 1 ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( V_478 != 0 )
F_166 ( V_73 ) ;
F_170 ( V_73 ) ;
F_171 ( V_73 ) ;
return;
V_480:
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
int F_172 (
struct V_72 * V_73 ,
struct V_318 * V_474 ,
T_1 V_482 ,
struct V_318 * V_483 ,
T_1 V_484 )
{
if ( ! V_474 || ! V_482 )
return 0 ;
if ( ( V_73 -> V_126 & V_355 ) ||
( V_73 -> V_126 & V_367 ) ) {
if ( V_73 -> V_126 & V_458 ) {
F_163 ( L_178
L_179 ) ;
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_262 ;
return - V_184 ;
}
V_73 -> V_322 = V_474 ;
V_73 -> V_323 = V_482 ;
if ( V_483 && V_484 ) {
V_73 -> V_467 = V_483 ;
V_73 -> V_477 = V_484 ;
}
V_73 -> V_126 |= V_476 ;
}
return 0 ;
}
void * F_173 ( struct V_72 * V_73 )
{
struct V_318 * V_319 = V_73 -> V_322 ;
F_10 ( ! V_319 ) ;
return F_174 ( F_153 ( V_319 ) ) + V_319 -> V_320 ;
}
void F_175 ( struct V_72 * V_73 )
{
F_176 ( F_153 ( V_73 -> V_322 ) ) ;
}
static int
F_177 ( struct V_72 * V_73 )
{
T_1 V_325 = V_73 -> V_251 ;
unsigned int V_475 ;
struct V_485 * V_485 ;
int V_190 = 0 ;
V_475 = F_178 ( V_325 , V_461 ) ;
V_73 -> V_322 = F_149 ( sizeof( struct V_318 ) * V_475 , V_42 ) ;
if ( ! V_73 -> V_322 )
return - V_28 ;
V_73 -> V_323 = V_475 ;
F_179 ( V_73 -> V_322 , V_475 ) ;
while ( V_325 ) {
T_1 V_486 = F_180 ( T_1 , V_325 , V_461 ) ;
V_485 = F_181 ( V_42 | V_487 ) ;
if ( ! V_485 )
goto V_3;
F_182 ( & V_73 -> V_322 [ V_190 ] , V_485 , V_486 , 0 ) ;
V_325 -= V_486 ;
V_190 ++ ;
}
return 0 ;
V_3:
while ( V_190 >= 0 ) {
F_169 ( F_153 ( & V_73 -> V_322 [ V_190 ] ) ) ;
V_190 -- ;
}
F_104 ( V_73 -> V_322 ) ;
V_73 -> V_322 = NULL ;
return - V_28 ;
}
static inline T_5 F_183 (
struct V_74 * V_75 ,
unsigned long long V_488 ,
T_5 V_316 )
{
V_316 = F_180 ( T_5 , V_316 , V_75 -> V_170 -> V_171 . V_173 ) ;
if ( V_75 -> V_124 -> V_202 ( V_75 ) == V_334 )
if ( ( V_488 + V_316 ) > F_156 ( V_75 ) )
V_316 = ( ( F_156 ( V_75 ) - V_488 ) + 1 ) ;
return V_316 ;
}
void F_184 ( struct V_72 * V_73 )
{
struct V_318 * V_489 = NULL ;
struct V_318 * V_490 = NULL ;
int V_491 = 0 ;
struct V_318 * V_319 ;
struct V_77 * V_78 ;
T_1 V_492 = 0 ;
int V_190 ;
F_10 ( ! V_73 -> V_84 -> V_493 ) ;
F_44 (task, &cmd->t_task_list, t_list) {
if ( ! V_78 -> V_472 )
continue;
if ( ! V_489 ) {
V_489 = V_78 -> V_472 ;
V_492 = V_78 -> V_494 ;
} else {
F_185 ( V_490 , V_491 , V_78 -> V_472 ) ;
V_492 += V_78 -> V_494 ;
}
V_491 = ( V_78 -> V_494 + 1 ) ;
V_490 = V_78 -> V_472 ;
}
V_73 -> V_495 = V_489 ;
V_73 -> V_496 = V_492 ;
F_28 ( L_180
L_181 , V_73 , V_73 -> V_495 ,
V_73 -> V_496 ) ;
F_151 (cmd->t_tasks_sg_chained, sg,
cmd->t_tasks_sg_chained_no, i) {
F_28 ( L_182 ,
V_190 , V_319 , F_153 ( V_319 ) , V_319 -> V_325 , V_319 -> V_320 ) ;
if ( F_186 ( V_319 ) )
F_28 ( L_183 , V_319 ) ;
if ( F_187 ( V_319 ) )
F_28 ( L_184 , V_319 ) ;
}
}
static int
F_188 ( struct V_72 * V_73 ,
enum V_246 V_156 ,
struct V_318 * V_497 , unsigned int V_498 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
int V_499 , V_190 ;
unsigned long long V_488 ;
T_5 V_316 , V_500 ;
T_1 V_501 ;
if ( F_157 ( V_73 ) < 0 )
return - V_184 ;
V_500 = V_75 -> V_170 -> V_171 . V_173 ;
V_501 = V_75 -> V_170 -> V_171 . V_172 ;
F_75 ( V_73 -> V_251 % V_501 ) ;
V_488 = V_73 -> V_335 ;
V_316 = F_178 ( V_73 -> V_251 , V_501 ) ;
V_499 = F_189 ( V_316 , V_500 ) ;
if ( V_499 == 1 ) {
struct V_77 * V_78 ;
unsigned long V_64 ;
V_78 = F_106 ( V_73 , V_156 ) ;
if ( ! V_78 )
return - V_28 ;
V_78 -> V_472 = V_497 ;
V_78 -> V_494 = V_498 ;
V_78 -> V_502 = V_488 ;
V_78 -> V_503 = V_316 ;
V_78 -> V_504 = V_78 -> V_503 * V_501 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_26 ( & V_78 -> V_111 , & V_73 -> V_109 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return V_499 ;
}
for ( V_190 = 0 ; V_190 < V_499 ; V_190 ++ ) {
struct V_77 * V_78 ;
unsigned int V_504 , V_505 ;
struct V_318 * V_319 ;
unsigned long V_64 ;
int V_321 ;
V_78 = F_106 ( V_73 , V_156 ) ;
if ( ! V_78 )
return - V_28 ;
V_78 -> V_502 = V_488 ;
V_78 -> V_503 = F_190 ( V_316 , V_500 ) ;
V_78 -> V_504 = V_78 -> V_503 * V_501 ;
V_78 -> V_494 = F_178 ( V_78 -> V_504 , V_461 ) ;
if ( V_73 -> V_84 -> V_493 && ( V_190 < ( V_499 - 1 ) ) ) {
V_505 = ( V_78 -> V_494 + 1 ) ;
} else
V_505 = V_78 -> V_494 ;
V_78 -> V_472 = F_149 ( sizeof( struct V_318 ) *
V_505 , V_42 ) ;
if ( ! V_78 -> V_472 ) {
V_73 -> V_76 -> V_124 -> V_473 ( V_78 ) ;
return - V_28 ;
}
F_179 ( V_78 -> V_472 , V_505 ) ;
V_504 = V_78 -> V_504 ;
F_151 (task->task_sg, sg, task->task_sg_nents, count) {
if ( V_497 -> V_325 > V_504 )
break;
* V_319 = * V_497 ;
V_504 -= V_497 -> V_325 ;
V_497 = F_191 ( V_497 ) ;
}
V_488 += V_78 -> V_503 ;
V_316 -= V_78 -> V_503 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_26 ( & V_78 -> V_111 , & V_73 -> V_109 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
return V_499 ;
}
static int
F_192 ( struct V_72 * V_73 )
{
struct V_77 * V_78 ;
unsigned long V_64 ;
V_78 = F_106 ( V_73 , V_73 -> V_156 ) ;
if ( ! V_78 )
return - V_28 ;
V_78 -> V_472 = V_73 -> V_322 ;
V_78 -> V_504 = V_73 -> V_251 ;
V_78 -> V_494 = V_73 -> V_323 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_26 ( & V_78 -> V_111 , & V_73 -> V_109 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 1 ;
}
int F_118 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
int V_506 , V_507 = 0 ;
int V_508 = 1 ;
int V_39 = 0 ;
if ( ! ( V_73 -> V_126 & V_476 ) &&
V_73 -> V_251 ) {
V_39 = F_177 ( V_73 ) ;
if ( V_39 < 0 )
goto V_509;
}
if ( V_73 -> V_467 &&
V_75 -> V_124 -> V_191 != V_192 ) {
F_10 ( ! ( V_73 -> V_126 & V_355 ) ) ;
V_507 = F_188 ( V_73 ,
V_158 , V_73 -> V_467 ,
V_73 -> V_477 ) ;
if ( V_507 <= 0 )
goto V_509;
F_55 ( & V_73 -> V_479 ) ;
F_55 ( & V_73 -> V_481 ) ;
V_508 = 0 ;
}
if ( V_73 -> V_126 & V_355 ) {
V_506 = F_188 ( V_73 ,
V_73 -> V_156 , V_73 -> V_322 ,
V_73 -> V_323 ) ;
} else {
V_506 = F_192 ( V_73 ) ;
}
if ( V_506 < 0 )
goto V_509;
else if ( ! V_506 && ( V_73 -> V_126 & V_355 ) ) {
V_73 -> V_88 = V_136 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
F_67 ( & V_73 -> V_121 , V_135 ) ;
F_68 ( V_25 , & V_73 -> V_121 ) ;
return 0 ;
}
if ( V_508 ) {
F_55 ( & V_73 -> V_479 ) ;
F_55 ( & V_73 -> V_481 ) ;
}
V_73 -> V_278 = ( V_506 + V_507 ) ;
F_14 ( & V_73 -> V_132 , V_73 -> V_278 ) ;
F_14 ( & V_73 -> V_86 , V_73 -> V_278 ) ;
if ( V_73 -> V_156 == V_159 ) {
F_71 ( V_73 ) ;
return F_193 ( V_73 ) ;
}
F_139 ( V_73 ) ;
return 0 ;
V_509:
V_73 -> V_126 |= V_261 ;
V_73 -> V_118 = V_119 ;
return - V_184 ;
}
void F_194 ( struct V_72 * V_73 )
{
F_139 ( V_73 ) ;
}
static void F_195 ( struct V_72 * V_73 )
{
int V_39 ;
V_39 = V_73 -> V_84 -> V_510 ( V_73 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 ) {
F_28 ( L_185 ,
V_73 ) ;
F_130 ( V_73 , V_73 -> V_76 ) ;
}
}
static int F_193 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
int V_39 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_73 -> V_88 = V_511 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_47 ( V_73 , 1 , 0 ) ;
V_39 = V_73 -> V_84 -> V_510 ( V_73 ) ;
if ( V_39 == - V_295 || V_39 == - V_28 )
goto V_296;
else if ( V_39 < 0 )
return V_39 ;
return 1 ;
V_296:
F_28 ( L_185 , V_73 ) ;
V_73 -> V_88 = V_155 ;
F_130 ( V_73 , V_73 -> V_76 ) ;
return 0 ;
}
void F_171 ( struct V_72 * V_73 )
{
F_10 ( ! V_73 -> V_84 ) ;
if ( V_73 -> V_2 )
F_196 ( V_73 -> V_2 ) ;
if ( V_73 -> V_144 != V_73 -> V_263 )
F_104 ( V_73 -> V_144 ) ;
if ( V_73 -> V_512 != 0 && V_73 -> V_84 -> V_513 )
if ( V_73 -> V_84 -> V_513 ( V_73 ) != 0 )
return;
V_73 -> V_84 -> V_514 ( V_73 ) ;
}
void F_197 ( struct V_72 * V_73 , int V_515 )
{
if ( ! ( V_73 -> V_126 & V_516 ) ) {
if ( V_515 && V_73 -> V_2 )
F_198 ( V_73 ) ;
F_171 ( V_73 ) ;
} else {
if ( V_515 )
F_198 ( V_73 ) ;
F_199 ( V_73 -> V_41 -> V_50 , V_73 ) ;
if ( V_73 -> V_95 )
F_50 ( V_73 ) ;
F_166 ( V_73 ) ;
F_53 ( V_73 ) ;
}
}
void F_200 ( struct V_5 * V_41 , struct V_72 * V_72 )
{
unsigned long V_64 ;
F_33 ( & V_41 -> V_47 , V_64 ) ;
F_26 ( & V_72 -> V_255 , & V_41 -> V_45 ) ;
V_72 -> V_512 = 1 ;
F_37 ( & V_41 -> V_47 , V_64 ) ;
}
int F_201 ( struct V_5 * V_41 , struct V_72 * V_72 )
{
unsigned long V_64 ;
F_33 ( & V_41 -> V_47 , V_64 ) ;
if ( F_35 ( & V_72 -> V_255 ) ) {
F_37 ( & V_41 -> V_47 , V_64 ) ;
F_75 ( 1 ) ;
return 0 ;
}
if ( V_41 -> V_517 && V_72 -> V_518 ) {
F_37 ( & V_41 -> V_47 , V_64 ) ;
F_48 ( & V_72 -> V_257 ) ;
return 1 ;
}
F_34 ( & V_72 -> V_255 ) ;
F_37 ( & V_41 -> V_47 , V_64 ) ;
return 0 ;
}
void F_202 ( struct V_5 * V_41 )
{
struct V_72 * V_72 ;
unsigned long V_64 ;
F_75 ( ! F_35 ( & V_41 -> V_46 ) ) ;
F_15 ( & V_41 -> V_46 ) ;
F_33 ( & V_41 -> V_47 , V_64 ) ;
V_41 -> V_517 = 1 ;
F_78 ( & V_41 -> V_45 , & V_41 -> V_46 ) ;
F_44 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_72 -> V_518 = 1 ;
F_37 ( & V_41 -> V_47 , V_64 ) ;
}
void F_203 (
struct V_5 * V_41 ,
int V_515 )
{
struct V_72 * V_72 , * V_519 ;
bool V_520 = false ;
F_79 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_34 ( & V_72 -> V_255 ) ;
F_28 ( L_186
L_187 , V_72 , V_72 -> V_88 ,
V_72 -> V_84 -> V_277 ( V_72 ) ) ;
if ( V_515 ) {
F_28 ( L_188
L_189 , V_72 , V_72 -> V_88 ,
V_72 -> V_84 -> V_277 ( V_72 ) ) ;
V_520 = F_198 ( V_72 ) ;
F_28 ( L_190
L_189 , V_72 , V_72 -> V_88 ,
V_72 -> V_84 -> V_277 ( V_72 ) ) ;
}
if ( ! V_520 ) {
F_125 ( & V_72 -> V_257 ) ;
F_28 ( L_191
L_189 , V_72 , V_72 -> V_88 ,
V_72 -> V_84 -> V_277 ( V_72 ) ) ;
}
V_72 -> V_84 -> V_514 ( V_72 ) ;
}
}
static int F_204 ( struct V_72 * V_73 , struct V_95 * V_98 )
{
unsigned long V_64 ;
int V_39 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( F_45 ( & V_73 -> V_94 ) ) {
F_14 ( & V_73 -> V_90 , 0 ) ;
F_28 ( L_192
L_193 , V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_47 ( V_73 , 1 , 0 ) ;
return - V_271 ;
}
F_14 ( & V_73 -> V_521 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_57 ( & V_73 -> V_76 -> V_105 . V_37 ) ;
V_39 = F_126 ( V_73 ) ;
F_28 ( L_194
L_187 , V_73 , V_73 -> V_278 , V_39 ) ;
if ( ! V_39 ) {
F_28 ( L_195 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_125 ( & V_73 -> V_93 ) ;
F_28 ( L_196 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
}
F_52 ( V_73 ) ;
return 0 ;
}
static void F_205 ( struct V_95 * V_98 )
{
struct V_72 * V_73 = NULL ;
unsigned long V_522 , V_523 ;
F_33 ( & V_98 -> V_101 , V_522 ) ;
while ( ! F_35 ( & V_98 -> V_524 ) ) {
V_73 = F_59 ( & V_98 -> V_524 ,
struct V_72 , V_103 ) ;
F_34 ( & V_73 -> V_103 ) ;
F_14 ( & V_73 -> V_102 , 0 ) ;
F_11 ( & V_73 -> V_89 ) ;
F_28 ( L_197
L_198 ,
V_73 -> V_95 -> V_525 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_14 ( & V_73 -> V_90 , 1 ) ;
F_12 ( & V_73 -> V_89 ) ;
F_37 ( & V_98 -> V_101 , V_522 ) ;
if ( ! V_73 -> V_95 ) {
F_4 ( L_199 ,
V_73 -> V_84 -> V_85 ( V_73 ) ,
V_73 -> V_84 -> V_277 ( V_73 ) , V_73 -> V_88 ) ;
F_206 () ;
}
F_28 ( L_200
L_201 , V_73 -> V_95 -> V_525 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
if ( F_204 ( V_73 , V_73 -> V_95 ) < 0 ) {
F_33 ( & V_98 -> V_101 , V_522 ) ;
continue;
}
F_28 ( L_202
L_203 ,
V_73 -> V_95 -> V_525 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_33 ( & V_73 -> V_89 , V_523 ) ;
if ( ! F_45 ( & V_73 -> V_99 ) ) {
F_37 ( & V_73 -> V_89 , V_523 ) ;
goto V_526;
}
F_14 ( & V_73 -> V_99 , 0 ) ;
F_43 ( V_73 ) ;
F_37 ( & V_73 -> V_89 , V_523 ) ;
F_166 ( V_73 ) ;
V_526:
F_129 ( V_73 ,
V_281 , 0 ) ;
F_33 ( & V_73 -> V_89 , V_523 ) ;
if ( F_45 ( & V_73 -> V_521 ) ) {
F_28 ( L_204
L_205 ,
V_98 -> V_525 ,
V_73 , V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 ,
V_523 ) ;
F_47 ( V_73 , 1 , 0 ) ;
F_48 ( & V_73 -> V_256 ) ;
F_33 ( & V_98 -> V_101 , V_522 ) ;
continue;
}
F_28 ( L_206 ,
V_98 -> V_525 , V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_523 ) ;
F_33 ( & V_98 -> V_101 , V_522 ) ;
}
F_37 ( & V_98 -> V_101 , V_522 ) ;
}
static int F_207 ( void * V_527 )
{
struct V_95 * V_98 = (struct V_95 * ) V_527 ;
F_205 ( V_98 ) ;
F_48 ( & V_98 -> V_528 ) ;
return 0 ;
}
int F_208 ( struct V_95 * V_98 )
{
struct V_529 * V_530 ;
V_530 = F_100 ( F_207 , V_98 ,
L_207 , V_98 -> V_525 ) ;
if ( F_101 ( V_530 ) ) {
F_4 ( L_208 ) ;
return F_209 ( V_530 ) ;
}
F_125 ( & V_98 -> V_528 ) ;
return 0 ;
}
bool F_198 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( ! ( V_73 -> V_126 & V_516 ) && ! ( V_73 -> V_2 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return false ;
}
if ( ! ( V_73 -> V_126 & V_300 ) && ! V_73 -> V_2 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return false ;
}
if ( F_45 ( & V_73 -> V_90 ) ) {
F_28 ( L_209
L_210
L_211 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_73 -> V_93 ) ;
F_125 ( & V_73 -> V_256 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_43 ( V_73 ) ;
F_28 ( L_212
L_213
L_214 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_14 ( & V_73 -> V_90 , 0 ) ;
}
if ( ! F_45 ( & V_73 -> V_92 ) ||
F_45 ( & V_73 -> V_531 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return false ;
}
F_14 ( & V_73 -> V_94 , 1 ) ;
F_28 ( L_215
L_216 ,
V_73 , V_73 -> V_84 -> V_85 ( V_73 ) ,
V_73 -> V_84 -> V_277 ( V_73 ) , V_73 -> V_88 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_57 ( & V_73 -> V_76 -> V_105 . V_37 ) ;
F_125 ( & V_73 -> V_96 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_14 ( & V_73 -> V_92 , 0 ) ;
F_14 ( & V_73 -> V_94 , 0 ) ;
F_28 ( L_217
L_218 ,
V_73 -> V_84 -> V_85 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return true ;
}
static int F_210 (
struct V_72 * V_73 ,
T_3 * V_532 ,
T_3 * V_533 )
{
* V_532 = V_73 -> V_534 ;
* V_533 = V_73 -> V_535 ;
return 0 ;
}
static int F_160 (
struct V_72 * V_73 ,
T_3 V_532 ,
T_3 V_533 )
{
V_73 -> V_534 = V_532 ;
V_73 -> V_535 = V_533 ;
return 0 ;
}
int F_129 (
struct V_72 * V_73 ,
T_3 V_468 ,
int V_536 )
{
unsigned char * V_326 = V_73 -> V_253 ;
unsigned long V_64 ;
int V_320 ;
T_3 V_532 = 0 , V_533 = 0 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_126 & V_327 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 0 ;
}
V_73 -> V_126 |= V_327 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( ! V_468 && V_536 )
goto V_537;
if ( ! V_536 )
V_73 -> V_126 |= V_538 ;
V_320 = V_73 -> V_84 -> V_329 ( V_73 ,
V_330 ) ;
switch ( V_468 ) {
case V_281 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_540 ;
V_326 [ V_320 + V_541 ] = 0x25 ;
break;
case V_282 :
case V_542 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_540 ;
V_326 [ V_320 + V_541 ] = 0x20 ;
break;
case V_284 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_540 ;
V_326 [ V_320 + V_541 ] = 0x24 ;
break;
case V_286 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x29 ;
V_326 [ V_320 + V_544 ] = 0x03 ;
break;
case V_545 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x0c ;
V_326 [ V_320 + V_544 ] = 0x0d ;
break;
case V_262 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x24 ;
break;
case V_283 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x26 ;
break;
case V_546 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x0c ;
V_326 [ V_320 + V_544 ] = 0x0c ;
break;
case V_547 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x47 ;
V_326 [ V_320 + V_544 ] = 0x05 ;
break;
case V_548 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_543 ;
V_326 [ V_320 + V_541 ] = 0x11 ;
V_326 [ V_320 + V_544 ] = 0x13 ;
break;
case V_285 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_549 ;
V_326 [ V_320 + V_541 ] = 0x27 ;
break;
case V_287 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_550 ;
F_211 ( V_73 , & V_532 , & V_533 ) ;
V_326 [ V_320 + V_541 ] = V_532 ;
V_326 [ V_320 + V_544 ] = V_533 ;
break;
case V_288 :
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_551 ;
F_210 ( V_73 , & V_532 , & V_533 ) ;
V_326 [ V_320 + V_541 ] = V_532 ;
V_326 [ V_320 + V_544 ] = V_533 ;
break;
case V_119 :
default:
V_326 [ V_320 ] = 0x70 ;
V_326 [ V_320 + V_539 ] = V_540 ;
V_326 [ V_320 + V_541 ] = 0x80 ;
break;
}
V_73 -> V_112 = V_116 ;
V_73 -> V_331 = V_330 + V_320 ;
V_537:
return V_73 -> V_84 -> V_294 ( V_73 ) ;
}
int F_122 ( struct V_72 * V_73 , int V_552 )
{
int V_39 = 0 ;
if ( F_45 ( & V_73 -> V_531 ) != 0 ) {
if ( ! V_552 ||
( V_73 -> V_126 & V_553 ) )
return 1 ;
#if 0
pr_debug("Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_73 -> V_126 |= V_553 ;
V_73 -> V_84 -> V_294 ( V_73 ) ;
V_39 = 1 ;
}
return V_39 ;
}
void F_212 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_126 & V_327 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_156 == V_159 ) {
if ( V_73 -> V_84 -> V_554 ( V_73 ) != 0 ) {
F_55 ( & V_73 -> V_531 ) ;
F_111 () ;
}
}
V_73 -> V_112 = V_555 ;
#if 0
pr_debug("Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_73 -> V_84 -> V_294 ( V_73 ) ;
}
int F_213 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_2 * V_556 = V_73 -> V_2 ;
int V_39 ;
switch ( V_556 -> V_557 ) {
case V_558 :
V_556 -> V_559 = V_560 ;
break;
case V_561 :
case V_562 :
case V_563 :
V_556 -> V_559 = V_564 ;
break;
case V_565 :
V_39 = F_214 ( V_75 , V_556 , NULL , NULL ) ;
V_556 -> V_559 = ( ! V_39 ) ? V_566 :
V_560 ;
break;
case V_567 :
V_556 -> V_559 = V_560 ;
break;
case V_568 :
V_556 -> V_559 = V_560 ;
break;
default:
F_4 ( L_219 ,
V_556 -> V_557 ) ;
V_556 -> V_559 = V_560 ;
break;
}
V_73 -> V_88 = V_569 ;
V_73 -> V_84 -> V_570 ( V_73 ) ;
F_49 ( V_73 ) ;
return 0 ;
}
static int V_236 ( void * V_571 )
{
int V_39 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = (struct V_74 * ) V_571 ;
while ( ! F_215 () ) {
V_39 = F_216 ( V_75 -> V_105 . V_37 ,
F_45 ( & V_75 -> V_105 . V_35 ) ||
F_215 () ) ;
if ( V_39 < 0 )
goto V_3;
V_572:
F_141 ( V_75 ) ;
V_73 = F_58 ( & V_75 -> V_105 ) ;
if ( ! V_73 )
continue;
switch ( V_73 -> V_88 ) {
case V_268 :
F_206 () ;
break;
case V_269 :
if ( ! V_73 -> V_84 -> V_573 ) {
F_4 ( L_220
L_221 ) ;
F_206 () ;
}
V_39 = V_73 -> V_84 -> V_573 ( V_73 ) ;
if ( V_39 < 0 ) {
F_65 ( V_73 ) ;
break;
}
V_39 = F_118 ( V_73 ) ;
if ( V_39 < 0 ) {
F_65 ( V_73 ) ;
break;
}
break;
case V_272 :
F_194 ( V_73 ) ;
break;
case V_273 :
F_213 ( V_73 ) ;
break;
case V_155 :
F_195 ( V_73 ) ;
break;
case V_154 :
F_164 ( V_73 ) ;
break;
default:
F_4 ( L_222
L_223 ,
V_73 -> V_88 ,
V_73 -> V_84 -> V_85 ( V_73 ) ,
V_73 -> V_84 -> V_277 ( V_73 ) ,
V_73 -> V_95 -> V_525 ) ;
F_206 () ;
}
goto V_572;
}
V_3:
F_75 ( ! F_35 ( & V_75 -> V_147 ) ) ;
F_75 ( ! F_35 ( & V_75 -> V_105 . V_36 ) ) ;
V_75 -> V_235 = NULL ;
return 0 ;
}
