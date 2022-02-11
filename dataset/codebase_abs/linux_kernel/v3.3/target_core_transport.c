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
static void F_13 ( struct V_33 * V_34 )
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
F_33 ( & V_75 -> V_81 , V_64 ) ;
if ( V_78 -> V_82 ) {
F_28 ( L_32 ,
V_73 -> V_83 -> V_84 ( V_73 ) , V_75 , V_78 ) ;
F_34 ( & V_78 -> V_85 ) ;
F_45 ( & V_73 -> V_86 ) ;
V_78 -> V_82 = false ;
}
F_37 ( & V_75 -> V_81 , V_64 ) ;
}
}
static int F_46 (
struct V_72 * V_73 ,
int V_87 ,
T_3 V_88 )
{
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( F_47 ( & V_73 -> V_90 ) ) {
F_28 ( L_33
L_34 , V_91 , __LINE__ ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_14 ( & V_73 -> V_92 , 0 ) ;
if ( V_87 == 2 )
F_43 ( V_73 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_73 -> V_93 ) ;
return 1 ;
}
if ( F_47 ( & V_73 -> V_94 ) ) {
F_28 ( L_35
L_36 , V_91 , __LINE__ ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
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
if ( V_73 -> V_83 -> V_97 != NULL ) {
F_37 (
& V_73 -> V_89 , V_64 ) ;
return V_73 -> V_83 -> V_97 ( V_73 ) ;
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
return F_46 ( V_73 , 2 , 0 ) ;
}
static void F_50 ( struct V_72 * V_73 )
{
struct V_95 * V_98 = V_73 -> V_95 ;
unsigned long V_64 ;
if ( ! V_98 )
return;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( ! F_47 ( & V_73 -> V_99 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
goto V_100;
}
F_14 ( & V_73 -> V_99 , 0 ) ;
F_43 ( V_73 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
V_100:
F_33 ( & V_98 -> V_101 , V_64 ) ;
if ( F_47 ( & V_73 -> V_102 ) ) {
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
F_45 ( & V_34 -> V_35 ) ;
F_37 ( & V_34 -> V_38 , V_64 ) ;
return V_73 ;
}
static void F_52 ( struct V_72 * V_73 )
{
struct V_33 * V_34 = & V_73 -> V_76 -> V_105 ;
unsigned long V_64 ;
F_33 ( & V_34 -> V_38 , V_64 ) ;
if ( ! F_47 ( & V_73 -> V_107 ) ) {
F_37 ( & V_34 -> V_38 , V_64 ) ;
return;
}
F_14 ( & V_73 -> V_107 , 0 ) ;
F_45 ( & V_34 -> V_35 ) ;
F_60 ( & V_73 -> V_106 ) ;
F_37 ( & V_34 -> V_38 , V_64 ) ;
if ( F_47 ( & V_73 -> V_107 ) ) {
F_4 ( L_37 ,
V_73 -> V_83 -> V_84 ( V_73 ) ,
F_47 ( & V_73 -> V_107 ) ) ;
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
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_78 -> V_79 &= ~ V_80 ;
if ( V_75 && V_75 -> V_123 -> V_124 ) {
if ( V_75 -> V_123 -> V_124 ( V_78 ) != 0 ) {
V_73 -> V_125 |= V_126 ;
V_78 -> V_79 |= V_127 ;
V_122 = 1 ;
}
}
if ( V_78 -> V_79 & V_128 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_78 -> V_129 ) ;
return;
}
if ( ! V_122 )
V_73 -> V_130 = 1 ;
if ( ! F_66 ( & V_73 -> V_131 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return;
}
if ( V_73 -> V_130 ) {
V_73 -> V_118 = V_119 ;
F_67 ( & V_73 -> V_121 , F_64 ) ;
} else {
F_14 ( & V_73 -> V_132 , 1 ) ;
F_67 ( & V_73 -> V_121 , V_133 ) ;
}
V_73 -> V_88 = V_134 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_68 ( V_25 , & V_73 -> V_121 ) ;
}
static inline int F_69 (
struct V_77 * V_78 ,
struct V_77 * V_135 ,
struct V_74 * V_75 )
{
if ( V_75 -> V_136 != V_137 ) {
F_26 ( & V_78 -> V_138 , & V_75 -> V_139 ) ;
return 0 ;
}
if ( V_78 -> V_117 -> V_140 == V_141 ) {
F_56 ( & V_78 -> V_138 ,
( V_135 != NULL ) ?
& V_135 -> V_138 :
& V_75 -> V_139 ) ;
F_28 ( L_38
L_39 ,
V_78 -> V_117 -> V_142 [ 0 ] ) ;
return 1 ;
}
F_26 ( & V_78 -> V_138 , & V_75 -> V_139 ) ;
return 0 ;
}
static void F_70 (
struct V_77 * V_78 ,
struct V_77 * V_135 ,
struct V_74 * V_75 )
{
int V_143 ;
V_143 = F_69 ( V_78 , V_135 , V_75 ) ;
F_55 ( & V_75 -> V_144 ) ;
if ( V_78 -> V_82 )
return;
if ( V_143 )
F_56 ( & V_78 -> V_85 , ( V_135 ) ?
& V_135 -> V_85 :
& V_75 -> V_145 ) ;
else
F_26 ( & V_78 -> V_85 , & V_75 -> V_145 ) ;
V_78 -> V_82 = true ;
F_28 ( L_40 ,
V_78 -> V_117 -> V_83 -> V_84 ( V_78 -> V_117 ) ,
V_78 , V_75 ) ;
}
static void F_71 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 ;
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_44 (task, &cmd->t_task_list, t_list) {
F_11 ( & V_75 -> V_81 ) ;
if ( ! V_78 -> V_82 ) {
F_26 ( & V_78 -> V_85 ,
& V_75 -> V_145 ) ;
V_78 -> V_82 = true ;
F_28 ( L_40 ,
V_78 -> V_117 -> V_83 -> V_84 (
V_78 -> V_117 ) , V_78 , V_75 ) ;
}
F_12 ( & V_75 -> V_81 ) ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
static void F_72 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 , * V_135 = NULL ;
F_44 (task, &cmd->t_task_list, t_list) {
if ( ! F_35 ( & V_78 -> V_138 ) )
continue;
F_70 ( V_78 , V_135 , V_75 ) ;
V_135 = V_78 ;
}
}
static void F_73 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
struct V_74 * V_75 = V_73 -> V_76 ;
F_33 ( & V_75 -> V_81 , V_64 ) ;
F_72 ( V_73 ) ;
F_37 ( & V_75 -> V_81 , V_64 ) ;
}
void F_74 ( struct V_77 * V_78 ,
struct V_74 * V_75 )
{
F_60 ( & V_78 -> V_138 ) ;
F_45 ( & V_75 -> V_144 ) ;
}
static void F_75 (
struct V_77 * V_78 ,
struct V_74 * V_75 )
{
unsigned long V_64 ;
if ( F_76 ( F_35 ( & V_78 -> V_138 ) ) )
return;
F_33 ( & V_75 -> V_81 , V_64 ) ;
F_74 ( V_78 , V_75 ) ;
F_37 ( & V_75 -> V_81 , V_64 ) ;
}
static void F_77 ( struct V_120 * V_121 )
{
struct V_74 * V_75 = F_36 ( V_121 , struct V_74 ,
V_146 ) ;
F_78 ( V_147 ) ;
struct V_72 * V_73 , * V_148 ;
F_25 ( & V_75 -> V_149 ) ;
F_79 ( & V_75 -> V_147 , & V_147 ) ;
F_27 ( & V_75 -> V_149 ) ;
F_80 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_34 ( & V_73 -> V_150 ) ;
F_45 ( & V_75 -> V_151 ) ;
F_81 () ;
F_28 ( L_41
L_42 , V_73 -> V_83 -> V_62 () , V_73 ,
( V_73 -> V_88 == V_152 ) ? L_43 :
( V_73 -> V_88 == V_153 ) ? L_44
: L_45 ) ;
F_54 ( V_73 , V_73 -> V_88 , true ) ;
}
}
unsigned char * F_82 ( struct V_72 * V_73 )
{
switch ( V_73 -> V_154 ) {
case V_155 :
return L_46 ;
case V_156 :
return L_47 ;
case V_157 :
return L_48 ;
case V_158 :
return L_49 ;
default:
break;
}
return L_45 ;
}
void F_83 (
struct V_74 * V_75 ,
char * V_159 ,
int * V_160 )
{
* V_160 += sprintf ( V_159 + * V_160 , L_50 ) ;
switch ( V_75 -> V_161 ) {
case V_162 :
* V_160 += sprintf ( V_159 + * V_160 , L_51 ) ;
break;
case V_163 :
* V_160 += sprintf ( V_159 + * V_160 , L_52 ) ;
break;
case V_164 :
* V_160 += sprintf ( V_159 + * V_160 , L_53 ) ;
break;
case V_165 :
case V_166 :
* V_160 += sprintf ( V_159 + * V_160 , L_54 ) ;
break;
default:
* V_160 += sprintf ( V_159 + * V_160 , L_55 , V_75 -> V_161 ) ;
break;
}
* V_160 += sprintf ( V_159 + * V_160 , L_56 ,
F_47 ( & V_75 -> V_144 ) , V_75 -> V_167 ) ;
* V_160 += sprintf ( V_159 + * V_160 , L_57 ,
V_75 -> V_168 -> V_169 . V_170 , V_75 -> V_168 -> V_169 . V_171 ) ;
* V_160 += sprintf ( V_159 + * V_160 , L_58 ) ;
}
void F_84 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_53 [ V_176 ] ;
int V_177 ;
memset ( V_53 , 0 , V_176 ) ;
V_177 = sprintf ( V_53 , L_59 ) ;
switch ( V_173 -> V_178 ) {
case 0x00 :
sprintf ( V_53 + V_177 , L_60 ) ;
break;
case 0x10 :
sprintf ( V_53 + V_177 , L_61 ) ;
break;
case 0x20 :
sprintf ( V_53 + V_177 , L_62 ) ;
break;
case 0x30 :
sprintf ( V_53 + V_177 , L_63 ) ;
break;
case 0x40 :
sprintf ( V_53 + V_177 , L_64
L_65 ) ;
break;
case 0x50 :
sprintf ( V_53 + V_177 , L_66 ) ;
break;
case 0x60 :
sprintf ( V_53 + V_177 , L_67 ) ;
break;
case 0x70 :
sprintf ( V_53 + V_177 , L_68
L_65 ) ;
break;
case 0x80 :
sprintf ( V_53 + V_177 , L_69 ) ;
break;
default:
sprintf ( V_53 + V_177 , L_70 ,
V_173 -> V_178 ) ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_53 , V_175 ) ;
else
F_28 ( L_71 , V_53 ) ;
}
void
F_85 ( struct V_172 * V_173 , unsigned char * V_179 )
{
if ( V_179 [ 1 ] & 0x80 ) {
V_173 -> V_178 = ( V_179 [ 0 ] & 0xf0 ) ;
V_173 -> V_180 = 1 ;
F_84 ( V_173 , NULL , 0 ) ;
}
}
int F_86 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_53 [ V_176 ] ;
int V_39 = 0 ;
int V_177 ;
memset ( V_53 , 0 , V_176 ) ;
V_177 = sprintf ( V_53 , L_72 ) ;
switch ( V_173 -> V_181 ) {
case 0x00 :
sprintf ( V_53 + V_177 , L_73 ) ;
break;
case 0x10 :
sprintf ( V_53 + V_177 , L_74 ) ;
break;
case 0x20 :
sprintf ( V_53 + V_177 , L_75 ) ;
break;
default:
sprintf ( V_53 + V_177 , L_70 , V_173 -> V_181 ) ;
V_39 = - V_182 ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_53 , V_175 ) ;
else
F_28 ( L_71 , V_53 ) ;
return V_39 ;
}
int F_87 ( struct V_172 * V_173 , unsigned char * V_179 )
{
V_173 -> V_181 = ( V_179 [ 1 ] & 0x30 ) ;
return F_86 ( V_173 , NULL , 0 ) ;
}
int F_88 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_53 [ V_176 ] ;
int V_39 = 0 ;
int V_177 ;
memset ( V_53 , 0 , V_176 ) ;
V_177 = sprintf ( V_53 , L_76 ) ;
switch ( V_173 -> V_183 ) {
case 0x00 :
sprintf ( V_53 + V_177 , L_77 ) ;
break;
case 0x01 :
sprintf ( V_53 + V_177 , L_78 ) ;
break;
case 0x02 :
sprintf ( V_53 + V_177 , L_79 ) ;
break;
case 0x03 :
sprintf ( V_53 + V_177 , L_80 ) ;
break;
case 0x04 :
sprintf ( V_53 + V_177 , L_81 ) ;
break;
case 0x08 :
sprintf ( V_53 + V_177 , L_82 ) ;
break;
default:
sprintf ( V_53 + V_177 , L_83 ,
V_173 -> V_183 ) ;
V_39 = - V_182 ;
break;
}
if ( V_174 ) {
if ( V_175 < strlen ( V_53 ) + 1 )
return - V_182 ;
strncpy ( V_174 , V_53 , V_175 ) ;
} else {
F_28 ( L_71 , V_53 ) ;
}
return V_39 ;
}
int F_89 ( struct V_172 * V_173 , unsigned char * V_179 )
{
V_173 -> V_183 = ( V_179 [ 1 ] & 0x0f ) ;
return F_88 ( V_173 , NULL , 0 ) ;
}
int F_90 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_53 [ V_176 ] ;
int V_39 = 0 ;
memset ( V_53 , 0 , V_176 ) ;
switch ( V_173 -> V_184 ) {
case 0x01 :
sprintf ( V_53 , L_84 ,
& V_173 -> V_185 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_53 , L_85 ,
& V_173 -> V_185 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_53 , L_86 ,
& V_173 -> V_185 [ 0 ] ) ;
break;
default:
sprintf ( V_53 , L_87
L_88 , V_173 -> V_184 ) ;
V_39 = - V_182 ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_53 , V_175 ) ;
else
F_28 ( L_71 , V_53 ) ;
return V_39 ;
}
int
F_91 ( struct V_172 * V_173 , unsigned char * V_179 )
{
static const char V_186 [] = L_89 ;
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
return F_90 ( V_173 , NULL , 0 ) ;
}
static void F_92 ( struct V_74 * V_75 )
{
if ( V_75 -> V_123 -> V_189 == V_190 ) {
V_75 -> V_136 = V_191 ;
return;
}
V_75 -> V_136 = V_137 ;
F_28 ( L_90
L_91 , V_75 -> V_123 -> V_192 ,
V_75 -> V_123 -> V_193 ( V_75 ) ) ;
}
static void F_93 ( struct V_74 * V_75 )
{
struct V_194 * V_195 = & V_75 -> V_168 -> V_194 ;
char V_53 [ 17 ] ;
int V_188 , V_196 ;
for ( V_188 = 0 ; V_188 < 8 ; V_188 ++ )
if ( V_195 -> V_197 [ V_188 ] >= 0x20 )
V_53 [ V_188 ] = V_195 -> V_197 [ V_188 ] ;
else
V_53 [ V_188 ] = ' ' ;
V_53 [ V_188 ] = '\0' ;
F_28 ( L_92 , V_53 ) ;
for ( V_188 = 0 ; V_188 < 16 ; V_188 ++ )
if ( V_195 -> V_198 [ V_188 ] >= 0x20 )
V_53 [ V_188 ] = V_195 -> V_198 [ V_188 ] ;
else
V_53 [ V_188 ] = ' ' ;
V_53 [ V_188 ] = '\0' ;
F_28 ( L_93 , V_53 ) ;
for ( V_188 = 0 ; V_188 < 4 ; V_188 ++ )
if ( V_195 -> V_199 [ V_188 ] >= 0x20 )
V_53 [ V_188 ] = V_195 -> V_199 [ V_188 ] ;
else
V_53 [ V_188 ] = ' ' ;
V_53 [ V_188 ] = '\0' ;
F_28 ( L_94 , V_53 ) ;
V_196 = V_75 -> V_123 -> V_200 ( V_75 ) ;
F_28 ( L_95 , F_94 ( V_196 ) ) ;
F_28 ( L_96 ,
V_75 -> V_123 -> V_193 ( V_75 ) ) ;
}
struct V_74 * F_95 (
struct V_201 * V_202 ,
struct V_203 * V_123 ,
struct V_204 * V_76 ,
T_1 V_205 ,
void * V_206 ,
struct V_207 * V_208 ,
const char * V_209 ,
const char * V_210 )
{
int V_211 ;
struct V_74 * V_75 ;
V_75 = F_96 ( sizeof( struct V_74 ) , V_42 ) ;
if ( ! V_75 ) {
F_4 ( L_97 ) ;
return NULL ;
}
F_13 ( & V_75 -> V_105 ) ;
V_75 -> V_212 = V_205 ;
V_75 -> V_161 |= V_163 ;
V_75 -> V_213 = V_206 ;
V_75 -> V_201 = V_202 ;
V_75 -> V_168 = V_76 ;
V_75 -> V_123 = V_123 ;
F_15 ( & V_75 -> V_214 ) ;
F_15 ( & V_75 -> V_215 ) ;
F_15 ( & V_75 -> V_216 ) ;
F_15 ( & V_75 -> V_139 ) ;
F_15 ( & V_75 -> V_217 ) ;
F_15 ( & V_75 -> V_145 ) ;
F_15 ( & V_75 -> V_147 ) ;
F_17 ( & V_75 -> V_81 ) ;
F_17 ( & V_75 -> V_218 ) ;
F_17 ( & V_75 -> V_219 ) ;
F_17 ( & V_75 -> V_220 ) ;
F_17 ( & V_75 -> V_221 ) ;
F_17 ( & V_75 -> V_222 ) ;
F_17 ( & V_75 -> V_149 ) ;
F_14 ( & V_75 -> V_223 , 0 ) ;
F_97 ( V_75 , V_208 ) ;
V_75 -> V_224 = F_9 ( V_225 ) ;
V_75 -> V_226 = F_98 () ;
F_17 ( & V_75 -> V_227 ) ;
F_11 ( & V_202 -> V_228 ) ;
F_26 ( & V_75 -> V_214 , & V_202 -> V_229 ) ;
V_202 -> V_230 ++ ;
F_12 ( & V_202 -> V_228 ) ;
F_92 ( V_75 ) ;
V_211 = ( V_202 -> V_231 & V_232 ) ;
F_99 ( V_75 , V_211 ) ;
if ( F_100 ( V_75 , V_211 ) < 0 )
goto V_3;
V_75 -> V_233 = F_101 ( V_234 , V_75 ,
L_98 , V_75 -> V_123 -> V_192 ) ;
if ( F_102 ( V_75 -> V_233 ) ) {
F_4 ( L_99 ,
V_75 -> V_123 -> V_192 ) ;
goto V_3;
}
F_67 ( & V_75 -> V_146 , F_77 ) ;
if ( V_75 -> V_123 -> V_189 != V_190 ) {
if ( ! V_209 || ! V_210 ) {
F_4 ( L_100
L_101 ) ;
goto V_3;
}
strncpy ( & V_75 -> V_168 -> V_194 . V_197 [ 0 ] , L_102 , 8 ) ;
strncpy ( & V_75 -> V_168 -> V_194 . V_198 [ 0 ] , V_209 , 16 ) ;
strncpy ( & V_75 -> V_168 -> V_194 . V_199 [ 0 ] , V_210 , 4 ) ;
}
F_93 ( V_75 ) ;
return V_75 ;
V_3:
F_103 ( V_75 -> V_233 ) ;
F_11 ( & V_202 -> V_228 ) ;
F_34 ( & V_75 -> V_214 ) ;
V_202 -> V_230 -- ;
F_12 ( & V_202 -> V_228 ) ;
F_104 ( V_75 ) ;
F_105 ( V_75 ) ;
return NULL ;
}
static inline void F_106 (
unsigned char * V_235 )
{
switch ( V_235 [ 0 ] ) {
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
break;
default:
V_235 [ 1 ] &= 0x1f ;
break;
}
}
static struct V_77 *
F_107 ( struct V_72 * V_73 ,
enum V_244 V_154 )
{
struct V_77 * V_78 ;
struct V_74 * V_75 = V_73 -> V_76 ;
V_78 = V_75 -> V_123 -> V_245 ( V_73 -> V_142 ) ;
if ( ! V_78 ) {
F_4 ( L_103 ) ;
return NULL ;
}
F_15 ( & V_78 -> V_111 ) ;
F_15 ( & V_78 -> V_138 ) ;
F_15 ( & V_78 -> V_85 ) ;
F_108 ( & V_78 -> V_129 ) ;
V_78 -> V_117 = V_73 ;
V_78 -> V_246 = V_154 ;
return V_78 ;
}
void F_109 (
struct V_72 * V_73 ,
struct V_247 * V_248 ,
struct V_5 * V_41 ,
T_1 V_249 ,
int V_154 ,
int V_250 ,
unsigned char * V_251 )
{
F_15 ( & V_73 -> V_103 ) ;
F_15 ( & V_73 -> V_252 ) ;
F_15 ( & V_73 -> V_150 ) ;
F_15 ( & V_73 -> V_106 ) ;
F_15 ( & V_73 -> V_253 ) ;
F_15 ( & V_73 -> V_109 ) ;
F_108 ( & V_73 -> V_254 ) ;
F_108 ( & V_73 -> V_93 ) ;
F_108 ( & V_73 -> V_96 ) ;
F_108 ( & V_73 -> V_255 ) ;
F_17 ( & V_73 -> V_89 ) ;
F_14 ( & V_73 -> V_99 , 1 ) ;
V_73 -> V_83 = V_248 ;
V_73 -> V_41 = V_41 ;
V_73 -> V_249 = V_249 ;
V_73 -> V_154 = V_154 ;
V_73 -> V_140 = V_250 ;
V_73 -> V_251 = V_251 ;
}
static int F_110 ( struct V_72 * V_73 )
{
if ( V_73 -> V_76 -> V_136 != V_137 )
return 0 ;
if ( V_73 -> V_140 == V_256 ) {
F_28 ( L_104
L_105 ) ;
return - V_182 ;
}
V_73 -> V_257 = F_111 ( & V_73 -> V_76 -> V_223 ) ;
F_112 () ;
F_28 ( L_106 ,
V_73 -> V_257 , V_73 -> V_140 ,
V_73 -> V_76 -> V_123 -> V_192 ) ;
return 0 ;
}
int F_113 (
struct V_72 * V_73 ,
unsigned char * V_235 )
{
int V_39 ;
F_106 ( V_235 ) ;
if ( F_114 ( V_235 ) > V_258 ) {
F_4 ( L_107
L_108 ,
F_114 ( V_235 ) , V_258 ) ;
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_260 ;
return - V_182 ;
}
if ( F_114 ( V_235 ) > sizeof( V_73 -> V_261 ) ) {
V_73 -> V_142 = F_96 ( F_114 ( V_235 ) ,
V_42 ) ;
if ( ! V_73 -> V_142 ) {
F_4 ( L_109
L_110 ,
F_114 ( V_235 ) ,
( unsigned long ) sizeof( V_73 -> V_261 ) ) ;
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 =
V_119 ;
return - V_28 ;
}
} else
V_73 -> V_142 = & V_73 -> V_261 [ 0 ] ;
memcpy ( V_73 -> V_142 , V_235 , F_114 ( V_235 ) ) ;
V_39 = F_115 ( V_73 , V_235 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( F_110 ( V_73 ) < 0 ) {
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_260 ;
return - V_182 ;
}
F_11 ( & V_73 -> V_95 -> V_262 ) ;
if ( V_73 -> V_95 -> V_263 )
V_73 -> V_95 -> V_263 -> V_264 . V_265 ++ ;
F_12 ( & V_73 -> V_95 -> V_262 ) ;
return 0 ;
}
int F_116 (
struct V_72 * V_73 )
{
int V_39 ;
if ( ! V_73 -> V_95 ) {
F_117 () ;
F_4 ( L_111 ) ;
return - V_182 ;
}
if ( F_118 () ) {
F_117 () ;
F_4 ( L_112
L_113 ) ;
return - V_182 ;
}
V_73 -> V_88 = V_266 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
V_39 = F_119 ( V_73 ) ;
if ( V_39 < 0 )
F_65 ( V_73 ) ;
return 0 ;
}
void F_120 ( struct V_72 * V_72 , struct V_5 * V_41 ,
unsigned char * V_235 , unsigned char * V_267 , T_1 V_268 ,
T_1 V_249 , int V_250 , int V_269 , int V_64 )
{
struct V_48 * V_49 ;
int V_270 ;
V_49 = V_41 -> V_49 ;
F_10 ( ! V_49 ) ;
F_10 ( V_72 -> V_83 || V_72 -> V_41 ) ;
F_10 ( F_118 () ) ;
F_109 ( V_72 , V_49 -> V_55 , V_41 ,
V_249 , V_269 , V_250 , V_267 ) ;
F_121 ( V_41 , V_72 , ( V_64 & V_271 ) ) ;
if ( V_64 & V_272 )
V_72 -> V_125 |= V_273 ;
if ( F_122 ( V_72 , V_268 ) < 0 ) {
F_123 ( V_72 ,
V_72 -> V_118 , 0 ) ;
F_124 ( V_41 , V_72 ) ;
return;
}
V_270 = F_113 ( V_72 , V_235 ) ;
if ( V_270 != 0 ) {
F_65 ( V_72 ) ;
return;
}
F_116 ( V_72 ) ;
return;
}
int F_125 (
struct V_72 * V_73 )
{
if ( ! V_73 -> V_95 ) {
F_117 () ;
F_4 ( L_111 ) ;
return - V_182 ;
}
F_54 ( V_73 , V_274 , false ) ;
return 0 ;
}
int F_126 (
struct V_72 * V_73 )
{
if ( ! F_118 () && F_127 ( V_275 ) )
return - V_276 ;
if ( F_128 ( V_73 , 1 ) != 0 )
return 0 ;
F_54 ( V_73 , V_277 , false ) ;
return 0 ;
}
int F_129 (
struct V_72 * V_73 )
{
F_54 ( V_73 , V_278 , false ) ;
return 0 ;
}
bool F_130 ( struct V_77 * V_78 , unsigned long * V_64 )
{
struct V_72 * V_73 = V_78 -> V_117 ;
bool V_279 = false ;
if ( V_78 -> V_79 & V_80 ) {
V_78 -> V_79 |= V_128 ;
F_37 ( & V_73 -> V_89 , * V_64 ) ;
F_28 ( L_114 , V_78 ) ;
F_131 ( & V_78 -> V_129 ) ;
F_28 ( L_115 , V_78 ) ;
F_33 ( & V_73 -> V_89 , * V_64 ) ;
F_45 ( & V_73 -> V_131 ) ;
V_78 -> V_79 &= ~ ( V_80 | V_128 ) ;
V_279 = true ;
}
return V_279 ;
}
static int F_132 ( struct V_72 * V_73 )
{
struct V_77 * V_78 , * V_280 ;
unsigned long V_64 ;
int V_39 = 0 ;
F_28 ( L_116 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_80 (task, task_tmp,
&cmd->t_task_list, t_list) {
F_28 ( L_117 , V_78 ) ;
if ( ! ( V_78 -> V_79 & ( V_80 | V_281 ) ) ) {
F_37 ( & V_73 -> V_89 ,
V_64 ) ;
F_75 ( V_78 ,
V_73 -> V_76 ) ;
F_28 ( L_118 , V_78 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
continue;
}
if ( ! F_130 ( V_78 , & V_64 ) ) {
F_28 ( L_119 , V_78 ) ;
V_39 ++ ;
}
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
return V_39 ;
}
static void F_65 ( struct V_72 * V_73 )
{
int V_39 = 0 ;
F_28 ( L_120
L_121 , V_73 , V_73 -> V_83 -> V_84 ( V_73 ) ,
V_73 -> V_142 [ 0 ] ) ;
F_28 ( L_122 ,
V_73 -> V_83 -> V_282 ( V_73 ) ,
V_73 -> V_88 , V_73 -> V_118 ) ;
F_28 ( L_123
L_124
L_125
L_126 , V_73 -> V_283 ,
F_47 ( & V_73 -> V_131 ) ,
F_47 ( & V_73 -> V_284 ) ,
F_47 ( & V_73 -> V_86 ) ,
F_47 ( & V_73 -> V_92 ) ,
F_47 ( & V_73 -> V_94 ) ,
F_47 ( & V_73 -> V_285 ) ) ;
if ( V_73 -> V_76 -> V_136 == V_137 )
F_133 ( V_73 ) ;
switch ( V_73 -> V_118 ) {
case V_286 :
case V_287 :
case V_260 :
case V_288 :
case V_119 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
break;
case V_294 :
V_73 -> V_112 = V_295 ;
if ( V_73 -> V_41 &&
V_73 -> V_76 -> V_168 -> V_169 . V_296 == 2 )
F_134 ( V_73 -> V_41 -> V_50 ,
V_73 -> V_297 , 0x2C ,
V_298 ) ;
V_39 = V_73 -> V_83 -> V_299 ( V_73 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
goto V_302;
default:
F_4 ( L_127 ,
V_73 -> V_142 [ 0 ] , V_73 -> V_118 ) ;
V_73 -> V_118 = V_287 ;
break;
}
V_39 = F_123 ( V_73 ,
V_73 -> V_118 , 0 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
V_302:
F_50 ( V_73 ) ;
if ( ! F_49 ( V_73 ) )
;
return;
V_301:
V_73 -> V_88 = V_152 ;
F_135 ( V_73 , V_73 -> V_76 ) ;
}
static inline T_1 F_136 ( unsigned char * V_235 )
{
return ( ( V_235 [ 1 ] & 0x1f ) << 16 ) | ( V_235 [ 2 ] << 8 ) | V_235 [ 3 ] ;
}
static inline T_1 F_137 ( unsigned char * V_235 )
{
return ( V_235 [ 2 ] << 24 ) | ( V_235 [ 3 ] << 16 ) | ( V_235 [ 4 ] << 8 ) | V_235 [ 5 ] ;
}
static inline unsigned long long F_138 ( unsigned char * V_235 )
{
unsigned int V_303 , V_304 ;
V_303 = ( V_235 [ 2 ] << 24 ) | ( V_235 [ 3 ] << 16 ) | ( V_235 [ 4 ] << 8 ) | V_235 [ 5 ] ;
V_304 = ( V_235 [ 6 ] << 24 ) | ( V_235 [ 7 ] << 16 ) | ( V_235 [ 8 ] << 8 ) | V_235 [ 9 ] ;
return ( ( unsigned long long ) V_304 ) | ( unsigned long long ) V_303 << 32 ;
}
static inline unsigned long long F_139 ( unsigned char * V_235 )
{
unsigned int V_303 , V_304 ;
V_303 = ( V_235 [ 12 ] << 24 ) | ( V_235 [ 13 ] << 16 ) | ( V_235 [ 14 ] << 8 ) | V_235 [ 15 ] ;
V_304 = ( V_235 [ 16 ] << 24 ) | ( V_235 [ 17 ] << 16 ) | ( V_235 [ 18 ] << 8 ) | V_235 [ 19 ] ;
return ( ( unsigned long long ) V_304 ) | ( unsigned long long ) V_303 << 32 ;
}
static void F_140 ( struct V_72 * V_72 )
{
unsigned long V_64 ;
F_33 ( & V_72 -> V_89 , V_64 ) ;
V_72 -> V_125 |= V_305 ;
F_37 ( & V_72 -> V_89 , V_64 ) ;
}
static inline int F_141 ( struct V_72 * V_73 )
{
if ( V_73 -> V_76 -> V_136 != V_137 )
return 1 ;
if ( V_73 -> V_140 == V_141 ) {
F_28 ( L_128
L_129 ,
V_73 -> V_142 [ 0 ] ,
V_73 -> V_257 ) ;
return 1 ;
} else if ( V_73 -> V_140 == V_306 ) {
F_55 ( & V_73 -> V_76 -> V_307 ) ;
F_112 () ;
F_28 ( L_130
L_131 ,
V_73 -> V_142 [ 0 ] ,
V_73 -> V_257 ) ;
if ( ! F_47 ( & V_73 -> V_76 -> V_308 ) )
return 1 ;
} else {
F_55 ( & V_73 -> V_76 -> V_308 ) ;
F_112 () ;
}
if ( F_47 ( & V_73 -> V_76 -> V_307 ) != 0 ) {
F_11 ( & V_73 -> V_76 -> V_218 ) ;
V_73 -> V_125 |= V_309 ;
F_26 ( & V_73 -> V_252 ,
& V_73 -> V_76 -> V_217 ) ;
F_12 ( & V_73 -> V_76 -> V_218 ) ;
F_28 ( L_132
L_133 ,
V_73 -> V_142 [ 0 ] , V_73 -> V_140 ,
V_73 -> V_257 ) ;
return 0 ;
}
return 1 ;
}
static int F_142 ( struct V_72 * V_73 )
{
int V_310 ;
struct V_74 * V_76 = V_73 -> V_76 ;
if ( ! F_46 ( V_73 , 0 , V_311 ) ) {
V_310 = F_141 ( V_73 ) ;
if ( ! V_310 )
goto V_144;
F_143 ( V_76 , V_73 ) ;
return 0 ;
}
V_144:
F_143 ( V_76 , NULL ) ;
return 0 ;
}
static int F_143 ( struct V_74 * V_75 , struct V_72 * V_312 )
{
int error ;
struct V_72 * V_73 = NULL ;
struct V_77 * V_78 = NULL ;
unsigned long V_64 ;
V_313:
F_25 ( & V_75 -> V_81 ) ;
if ( V_312 != NULL )
F_72 ( V_312 ) ;
if ( F_35 ( & V_75 -> V_139 ) ) {
F_27 ( & V_75 -> V_81 ) ;
return 0 ;
}
V_78 = F_59 ( & V_75 -> V_139 ,
struct V_77 , V_138 ) ;
F_74 ( V_78 , V_75 ) ;
F_27 ( & V_75 -> V_81 ) ;
V_73 = V_78 -> V_117 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_78 -> V_79 |= ( V_80 | V_281 ) ;
F_55 ( & V_73 -> V_284 ) ;
if ( F_47 ( & V_73 -> V_284 ) ==
V_73 -> V_283 )
F_14 ( & V_73 -> V_285 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_314 )
error = V_73 -> V_314 ( V_78 ) ;
else
error = V_75 -> V_123 -> V_315 ( V_78 ) ;
if ( error != 0 ) {
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_78 -> V_79 &= ~ V_80 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_14 ( & V_73 -> V_285 , 0 ) ;
F_132 ( V_73 ) ;
F_65 ( V_73 ) ;
}
V_312 = NULL ;
goto V_313;
return 0 ;
}
static inline T_1 F_144 (
unsigned char * V_235 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_316;
if ( V_75 -> V_123 -> V_200 ( V_75 ) == V_317 )
return ( T_1 ) ( V_235 [ 2 ] << 16 ) + ( V_235 [ 3 ] << 8 ) + V_235 [ 4 ] ;
V_316:
return V_235 [ 4 ] ? : 256 ;
}
static inline T_1 F_145 (
unsigned char * V_235 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_316;
if ( V_75 -> V_123 -> V_200 ( V_75 ) == V_317 ) {
* V_39 = - V_182 ;
return 0 ;
}
V_316:
return ( T_1 ) ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
}
static inline T_1 F_146 (
unsigned char * V_235 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_316;
if ( V_75 -> V_123 -> V_200 ( V_75 ) == V_317 ) {
* V_39 = - V_182 ;
return 0 ;
}
V_316:
return ( T_1 ) ( V_235 [ 6 ] << 24 ) + ( V_235 [ 7 ] << 16 ) + ( V_235 [ 8 ] << 8 ) + V_235 [ 9 ] ;
}
static inline T_1 F_147 (
unsigned char * V_235 ,
struct V_72 * V_73 ,
int * V_39 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( ! V_75 )
goto V_316;
if ( V_75 -> V_123 -> V_200 ( V_75 ) == V_317 )
return ( T_1 ) ( V_235 [ 12 ] << 16 ) + ( V_235 [ 13 ] << 8 ) + V_235 [ 14 ] ;
V_316:
return ( T_1 ) ( V_235 [ 10 ] << 24 ) + ( V_235 [ 11 ] << 16 ) +
( V_235 [ 12 ] << 8 ) + V_235 [ 13 ] ;
}
static inline T_1 F_148 (
unsigned char * V_235 ,
struct V_72 * V_73 ,
int * V_39 )
{
return ( T_1 ) ( V_235 [ 28 ] << 24 ) + ( V_235 [ 29 ] << 16 ) +
( V_235 [ 30 ] << 8 ) + V_235 [ 31 ] ;
}
static inline T_1 F_149 (
T_1 V_318 ,
unsigned char * V_235 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
if ( V_75 -> V_123 -> V_200 ( V_75 ) == V_317 ) {
if ( V_235 [ 1 ] & 1 ) {
return V_75 -> V_168 -> V_169 . V_170 * V_318 ;
} else
return V_318 ;
}
#if 0
pr_debug("Returning block_size: %u, sectors: %u == %u for"
" %s object\n", dev->se_sub_dev->se_dev_attrib.block_size, sectors,
dev->se_sub_dev->se_dev_attrib.block_size * sectors,
dev->transport->name);
#endif
return V_75 -> V_168 -> V_169 . V_170 * V_318 ;
}
static void F_150 ( struct V_72 * V_73 )
{
unsigned char * V_53 , * V_319 ;
struct V_320 * V_321 ;
unsigned int V_322 ;
int V_188 ;
int V_323 ;
V_53 = F_151 ( V_73 -> V_249 , V_42 ) ;
if ( ! V_53 ) {
F_4 ( L_134 ) ;
return;
}
F_152 ( V_73 -> V_324 ,
V_73 -> V_325 ,
V_53 ,
V_73 -> V_249 ) ;
V_322 = 0 ;
F_153 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_319 = F_154 ( F_155 ( V_321 ) , V_326 ) ;
if ( ! V_319 )
goto V_3;
for ( V_188 = 0 ; V_188 < V_321 -> V_327 ; V_188 ++ )
* ( V_319 + V_321 -> V_322 + V_188 ) ^= * ( V_53 + V_322 + V_188 ) ;
V_322 += V_321 -> V_327 ;
F_156 ( V_319 , V_326 ) ;
}
V_3:
F_105 ( V_53 ) ;
}
static int F_157 ( struct V_72 * V_73 )
{
unsigned char * V_328 = V_73 -> V_251 , * V_251 = NULL ;
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_77 * V_78 = NULL , * V_280 ;
unsigned long V_64 ;
T_1 V_322 = 0 ;
F_76 ( ! V_73 -> V_95 ) ;
if ( ! V_75 )
return 0 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_125 & V_329 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 0 ;
}
F_80 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! ( V_78 -> V_79 & V_127 ) )
continue;
if ( ! V_75 -> V_123 -> V_330 ) {
F_4 ( L_135
L_136 ) ;
continue;
}
V_251 = V_75 -> V_123 -> V_330 ( V_78 ) ;
if ( ! V_251 ) {
F_4 ( L_137
L_138 ,
V_73 -> V_83 -> V_84 ( V_73 ) , V_78 ) ;
continue;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
V_322 = V_73 -> V_83 -> V_331 ( V_73 ,
V_332 ) ;
memcpy ( & V_328 [ V_322 ] , V_251 ,
V_332 ) ;
V_73 -> V_112 = V_78 -> V_114 ;
V_73 -> V_333 =
( V_332 + V_322 ) ;
F_28 ( L_139
L_140 ,
V_75 -> V_201 -> V_334 , V_75 -> V_123 -> V_192 ,
V_73 -> V_112 ) ;
return 0 ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
return - 1 ;
}
static inline long long F_158 ( struct V_74 * V_75 )
{
return V_75 -> V_123 -> V_335 ( V_75 ) + 1 ;
}
static int F_159 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
T_1 V_318 ;
if ( V_75 -> V_123 -> V_200 ( V_75 ) != V_336 )
return 0 ;
V_318 = ( V_73 -> V_249 / V_75 -> V_168 -> V_169 . V_170 ) ;
if ( ( V_73 -> V_337 + V_318 ) > F_158 ( V_75 ) ) {
F_4 ( L_141
L_142 ,
V_73 -> V_337 , V_318 ,
F_158 ( V_75 ) ) ;
return - V_182 ;
}
return 0 ;
}
static int F_160 ( unsigned char * V_64 , struct V_74 * V_75 )
{
int V_338 = ( V_75 -> V_123 -> V_189 ==
V_190 ) ;
if ( ! V_338 ) {
if ( ( V_64 [ 0 ] & 0x04 ) || ( V_64 [ 0 ] & 0x02 ) ) {
F_4 ( L_143
L_144
L_145 ) ;
return - V_339 ;
}
if ( ! ( V_64 [ 0 ] & 0x08 ) ) {
F_4 ( L_146
L_147 ) ;
return - V_339 ;
}
}
return 0 ;
}
static int F_115 (
struct V_72 * V_73 ,
unsigned char * V_235 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_204 * V_340 = V_75 -> V_168 ;
int V_39 = 0 , V_341 = 0 , V_338 ;
T_1 V_318 = 0 , V_342 = 0 , V_343 = 0 ;
T_4 V_344 ;
T_3 V_345 = 0 ;
if ( F_161 ( V_73 , V_235 ) < 0 ) {
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_292 ;
return - V_182 ;
}
V_39 = V_340 -> V_346 . V_347 ( V_73 , V_235 , & V_345 ) ;
if ( V_39 != 0 ) {
if ( V_39 > 0 ) {
#if 0
pr_debug("[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
#endif
F_162 ( V_73 , 0x04 , V_345 ) ;
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_293 ;
return - V_182 ;
}
goto V_348;
}
if ( V_340 -> V_349 . V_350 . V_351 ( V_73 , & V_343 ) != 0 ) {
if ( V_340 -> V_349 . V_350 . V_352 (
V_73 , V_235 , V_343 ) != 0 ) {
V_73 -> V_125 |= V_259 ;
V_73 -> V_125 |= V_353 ;
V_73 -> V_112 = V_295 ;
V_73 -> V_118 = V_294 ;
return - V_354 ;
}
}
V_338 =
( V_75 -> V_123 -> V_189 == V_190 ) ;
switch ( V_235 [ 0 ] ) {
case V_355 :
V_318 = F_144 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_136 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
break;
case V_236 :
V_318 = F_145 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_137 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
break;
case V_237 :
V_318 = F_146 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_137 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
break;
case V_238 :
V_318 = F_147 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_138 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
break;
case V_358 :
V_318 = F_144 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_136 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
break;
case V_359 :
V_318 = F_145 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_137 ( V_235 ) ;
if ( V_235 [ 1 ] & 0x8 )
V_73 -> V_125 |= V_360 ;
V_73 -> V_125 |= V_357 ;
break;
case V_361 :
V_318 = F_146 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_137 ( V_235 ) ;
if ( V_235 [ 1 ] & 0x8 )
V_73 -> V_125 |= V_360 ;
V_73 -> V_125 |= V_357 ;
break;
case V_362 :
V_318 = F_147 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_138 ( V_235 ) ;
if ( V_235 [ 1 ] & 0x8 )
V_73 -> V_125 |= V_360 ;
V_73 -> V_125 |= V_357 ;
break;
case V_363 :
if ( ( V_73 -> V_154 != V_157 ) ||
! ( V_73 -> V_125 & V_273 ) )
goto V_348;
V_318 = F_145 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_137 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
if ( V_338 )
goto V_356;
V_73 -> V_364 = & F_150 ;
if ( V_235 [ 1 ] & 0x8 )
V_73 -> V_125 |= V_360 ;
break;
case V_365 :
V_344 = F_163 ( & V_235 [ 8 ] ) ;
switch ( V_344 ) {
case V_366 :
V_318 = F_148 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_337 = F_139 ( V_235 ) ;
V_73 -> V_125 |= V_357 ;
if ( V_338 )
goto V_356;
V_73 -> V_364 = & F_150 ;
if ( V_235 [ 1 ] & 0x8 )
V_73 -> V_125 |= V_360 ;
break;
case V_367 :
V_318 = F_148 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
if ( V_318 )
V_342 = F_149 ( 1 , V_235 , V_73 ) ;
else {
F_4 ( L_148
L_149 ) ;
goto V_348;
}
V_73 -> V_337 = F_24 ( & V_235 [ 12 ] ) ;
V_73 -> V_125 |= V_368 ;
if ( F_160 ( & V_235 [ 10 ] , V_75 ) < 0 )
goto V_356;
if ( ! V_338 )
V_73 -> V_314 = V_369 ;
break;
default:
F_4 ( L_150
L_151 , V_344 ) ;
goto V_356;
}
break;
case V_370 :
if ( V_75 -> V_123 -> V_200 ( V_75 ) != V_371 ) {
if ( V_235 [ 1 ] == V_372 &&
V_340 -> V_346 . V_373 == V_374 ) {
V_73 -> V_314 =
V_375 ;
}
V_342 = ( V_235 [ 6 ] << 24 ) | ( V_235 [ 7 ] << 16 ) |
( V_235 [ 8 ] << 8 ) | V_235 [ 9 ] ;
} else {
V_342 = ( V_235 [ 8 ] << 8 ) + V_235 [ 9 ] ;
}
V_73 -> V_125 |= V_368 ;
break;
case V_376 :
V_342 = V_235 [ 4 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_377 :
V_342 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_378 :
V_342 = V_235 [ 4 ] ;
V_73 -> V_125 |= V_368 ;
if ( ! V_338 )
V_73 -> V_314 = V_379 ;
break;
case V_380 :
V_342 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
if ( ! V_338 )
V_73 -> V_314 = V_379 ;
break;
case V_381 :
case V_382 :
case V_383 :
case V_384 :
V_342 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_385 :
V_342 = V_386 ;
V_73 -> V_125 |= V_368 ;
break;
case V_387 :
case V_388 :
case V_389 :
case V_390 :
V_342 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_391 :
if ( V_340 -> V_349 . V_392 == V_393 )
V_73 -> V_314 = V_394 ;
V_342 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_395 :
if ( V_340 -> V_349 . V_392 == V_393 )
V_73 -> V_314 = V_396 ;
V_342 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_397 :
case V_398 :
V_342 = ( V_235 [ 8 ] << 8 ) + V_235 [ 9 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_399 :
V_342 = V_400 ;
V_73 -> V_125 |= V_368 ;
break;
case V_401 :
if ( V_75 -> V_123 -> V_200 ( V_75 ) != V_371 ) {
if ( V_235 [ 1 ] == V_402 &&
V_340 -> V_346 . V_373 == V_374 ) {
V_73 -> V_314 =
V_403 ;
}
V_342 = ( V_235 [ 6 ] << 24 ) | ( V_235 [ 7 ] << 16 ) |
( V_235 [ 8 ] << 8 ) | V_235 [ 9 ] ;
} else {
V_342 = ( V_235 [ 8 ] << 8 ) + V_235 [ 9 ] ;
}
V_73 -> V_125 |= V_368 ;
break;
case V_404 :
V_342 = ( V_235 [ 3 ] << 8 ) + V_235 [ 4 ] ;
if ( V_73 -> V_76 -> V_136 == V_137 )
V_73 -> V_140 = V_141 ;
V_73 -> V_125 |= V_368 ;
if ( ! V_338 )
V_73 -> V_314 = V_405 ;
break;
case V_406 :
V_342 = ( V_235 [ 6 ] << 16 ) + ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_407 :
V_342 = V_408 ;
V_73 -> V_125 |= V_368 ;
if ( ! V_338 )
V_73 -> V_314 = V_409 ;
break;
case V_410 :
case V_411 :
case V_412 :
V_342 = ( V_235 [ 6 ] << 24 ) | ( V_235 [ 7 ] << 16 ) | ( V_235 [ 8 ] << 8 ) | V_235 [ 9 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_413 :
switch ( V_73 -> V_142 [ 1 ] & 0x1f ) {
case V_414 :
if ( ! V_338 )
V_73 -> V_314 =
V_415 ;
break;
default:
if ( V_338 )
break;
F_4 ( L_152 ,
V_73 -> V_142 [ 1 ] & 0x1f ) ;
goto V_356;
}
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
V_342 = ( V_235 [ 10 ] << 24 ) | ( V_235 [ 11 ] << 16 ) |
( V_235 [ 12 ] << 8 ) | V_235 [ 13 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_422 :
case V_239 :
V_342 = ( V_235 [ 3 ] << 8 ) | V_235 [ 4 ] ;
V_73 -> V_125 |= V_368 ;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#endif
case V_423 :
V_342 = V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_424 :
V_342 = V_235 [ 4 ] ;
V_73 -> V_125 |= V_368 ;
if ( ! V_338 )
V_73 -> V_314 = V_425 ;
break;
case V_426 :
V_342 = 65536 * V_235 [ 7 ] + 256 * V_235 [ 8 ] + V_235 [ 9 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_427 :
V_342 = ( V_235 [ 6 ] << 16 ) + ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_73 -> V_125 |= V_368 ;
break;
case V_428 :
case V_429 :
if ( V_235 [ 0 ] == V_429 )
V_342 = ( V_235 [ 7 ] << 8 ) | V_235 [ 8 ] ;
else
V_342 = V_73 -> V_249 ;
if ( V_340 -> V_349 . V_392 != V_430 )
V_73 -> V_314 = V_431 ;
V_73 -> V_125 |= V_432 ;
break;
case V_433 :
case V_434 :
if ( V_235 [ 0 ] == V_434 )
V_342 = ( V_235 [ 7 ] << 8 ) | V_235 [ 8 ] ;
else
V_342 = V_73 -> V_249 ;
if ( V_340 -> V_349 . V_392 != V_430 )
V_73 -> V_314 = V_435 ;
V_73 -> V_125 |= V_432 ;
break;
case V_436 :
case 0x91 :
if ( V_235 [ 0 ] == V_436 ) {
V_318 = F_145 ( V_235 , V_73 , & V_341 ) ;
V_73 -> V_337 = F_137 ( V_235 ) ;
} else {
V_318 = F_147 ( V_235 , V_73 , & V_341 ) ;
V_73 -> V_337 = F_138 ( V_235 ) ;
}
if ( V_341 )
goto V_356;
V_342 = F_149 ( V_318 , V_235 , V_73 ) ;
V_73 -> V_125 |= V_432 ;
if ( V_338 )
break;
if ( ( V_73 -> V_337 != 0 ) || ( V_318 != 0 ) ) {
if ( F_159 ( V_73 ) < 0 )
goto V_348;
}
V_73 -> V_314 = V_437 ;
break;
case V_438 :
V_342 = F_163 ( & V_235 [ 7 ] ) ;
V_73 -> V_125 |= V_368 ;
if ( ! V_338 )
V_73 -> V_314 = V_439 ;
break;
case V_440 :
V_318 = F_147 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
if ( V_318 )
V_342 = F_149 ( 1 , V_235 , V_73 ) ;
else {
F_4 ( L_153 ) ;
goto V_348;
}
V_73 -> V_337 = F_24 ( & V_235 [ 2 ] ) ;
V_73 -> V_125 |= V_368 ;
if ( F_160 ( & V_235 [ 1 ] , V_75 ) < 0 )
goto V_356;
if ( ! V_338 )
V_73 -> V_314 = V_369 ;
break;
case V_441 :
V_318 = F_145 ( V_235 , V_73 , & V_341 ) ;
if ( V_341 )
goto V_356;
if ( V_318 )
V_342 = F_149 ( 1 , V_235 , V_73 ) ;
else {
F_4 ( L_153 ) ;
goto V_348;
}
V_73 -> V_337 = F_164 ( & V_235 [ 2 ] ) ;
V_73 -> V_125 |= V_368 ;
if ( F_160 ( & V_235 [ 1 ] , V_75 ) < 0 )
goto V_356;
if ( ! V_338 )
V_73 -> V_314 = V_369 ;
break;
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
case V_240 :
case V_449 :
V_73 -> V_125 |= V_432 ;
if ( ! V_338 )
V_73 -> V_314 = V_450 ;
break;
case V_451 :
case V_452 :
case V_453 :
case V_454 :
case V_455 :
V_73 -> V_125 |= V_432 ;
break;
case V_456 :
V_73 -> V_314 = V_457 ;
V_342 = ( V_235 [ 6 ] << 24 ) | ( V_235 [ 7 ] << 16 ) | ( V_235 [ 8 ] << 8 ) | V_235 [ 9 ] ;
if ( V_73 -> V_76 -> V_136 == V_137 )
V_73 -> V_140 = V_141 ;
V_73 -> V_125 |= V_368 ;
break;
default:
F_165 ( L_154
L_155 ,
V_73 -> V_83 -> V_62 () , V_235 [ 0 ] ) ;
goto V_356;
}
if ( V_342 != V_73 -> V_249 ) {
F_165 ( L_156
L_157
L_158 , V_73 -> V_83 -> V_62 () ,
V_73 -> V_249 , V_342 , V_235 [ 0 ] ) ;
V_73 -> V_458 = V_342 ;
if ( V_73 -> V_154 == V_157 ) {
F_4 ( L_159
L_160 ) ;
goto V_348;
}
if ( ! V_39 && ( V_75 -> V_168 -> V_169 . V_170 != 512 ) ) {
F_4 ( L_161
L_162
L_163 , V_75 -> V_123 -> V_192 ) ;
goto V_348;
}
if ( V_342 > V_73 -> V_249 ) {
V_73 -> V_125 |= V_459 ;
V_73 -> V_460 = ( V_342 - V_73 -> V_249 ) ;
} else {
V_73 -> V_125 |= V_461 ;
V_73 -> V_460 = ( V_73 -> V_249 - V_342 ) ;
}
V_73 -> V_249 = V_342 ;
}
if ( ! ( V_338 || V_73 -> V_314 ||
( V_73 -> V_125 & V_357 ) ) )
goto V_356;
F_140 ( V_73 ) ;
return V_39 ;
V_356:
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_287 ;
return - V_182 ;
V_348:
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_260 ;
return - V_182 ;
}
static void F_133 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_72 * V_462 , * V_148 ;
int V_463 = 0 ;
if ( V_73 -> V_140 == V_464 ) {
F_45 ( & V_75 -> V_308 ) ;
F_81 () ;
V_75 -> V_465 ++ ;
F_28 ( L_164
L_165 , V_75 -> V_465 ,
V_73 -> V_257 ) ;
} else if ( V_73 -> V_140 == V_141 ) {
V_75 -> V_465 ++ ;
F_28 ( L_166
L_167 , V_75 -> V_465 ,
V_73 -> V_257 ) ;
} else if ( V_73 -> V_140 == V_306 ) {
F_45 ( & V_75 -> V_307 ) ;
F_81 () ;
V_75 -> V_465 ++ ;
F_28 ( L_168
L_169 , V_75 -> V_465 , V_73 -> V_257 ) ;
}
F_11 ( & V_75 -> V_218 ) ;
F_80 (cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_node) {
F_34 ( & V_462 -> V_252 ) ;
F_12 ( & V_75 -> V_218 ) ;
F_28 ( L_170
L_171
L_172 ,
V_462 -> V_142 [ 0 ] ,
V_462 -> V_140 , V_462 -> V_257 ) ;
F_73 ( V_462 ) ;
V_463 ++ ;
F_11 ( & V_75 -> V_218 ) ;
if ( V_462 -> V_140 == V_306 )
break;
}
F_12 ( & V_75 -> V_218 ) ;
if ( V_463 != 0 )
F_57 ( & V_75 -> V_105 . V_37 ) ;
}
static void F_166 ( struct V_72 * V_73 )
{
int V_39 = 0 ;
if ( V_73 -> V_76 -> V_136 == V_137 )
F_133 ( V_73 ) ;
if ( V_73 -> V_125 & V_126 ) {
V_39 = V_73 -> V_83 -> V_299 ( V_73 ) ;
if ( V_39 )
goto V_3;
}
switch ( V_73 -> V_154 ) {
case V_156 :
V_39 = V_73 -> V_83 -> V_466 ( V_73 ) ;
break;
case V_157 :
if ( V_73 -> V_467 ) {
V_39 = V_73 -> V_83 -> V_466 ( V_73 ) ;
if ( V_39 < 0 )
break;
}
case V_155 :
V_39 = V_73 -> V_83 -> V_299 ( V_73 ) ;
break;
default:
break;
}
V_3:
if ( V_39 < 0 ) {
F_135 ( V_73 , V_73 -> V_76 ) ;
return;
}
F_50 ( V_73 ) ;
F_49 ( V_73 ) ;
}
static void F_135 (
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
F_25 ( & V_75 -> V_149 ) ;
F_26 ( & V_73 -> V_150 , & V_73 -> V_76 -> V_147 ) ;
F_55 ( & V_75 -> V_151 ) ;
F_112 () ;
F_27 ( & V_73 -> V_76 -> V_149 ) ;
F_167 ( & V_73 -> V_76 -> V_146 ) ;
}
static void V_133 ( struct V_120 * V_121 )
{
struct V_72 * V_73 = F_36 ( V_121 , struct V_72 , V_121 ) ;
int V_468 = 0 , V_39 ;
if ( V_73 -> V_76 -> V_136 == V_137 )
F_133 ( V_73 ) ;
if ( F_47 ( & V_73 -> V_76 -> V_151 ) != 0 )
F_167 ( & V_73 -> V_76 -> V_146 ) ;
if ( V_73 -> V_125 & V_126 ) {
if ( F_157 ( V_73 ) < 0 )
V_468 = V_286 ;
if ( V_73 -> V_112 ) {
V_39 = F_123 (
V_73 , V_468 , 1 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
F_50 ( V_73 ) ;
F_49 ( V_73 ) ;
return;
}
}
if ( V_73 -> V_364 )
V_73 -> V_364 ( V_73 ) ;
switch ( V_73 -> V_154 ) {
case V_156 :
F_11 ( & V_73 -> V_95 -> V_262 ) ;
if ( V_73 -> V_95 -> V_263 ) {
V_73 -> V_95 -> V_263 -> V_264 . V_469 +=
V_73 -> V_249 ;
}
F_12 ( & V_73 -> V_95 -> V_262 ) ;
V_39 = V_73 -> V_83 -> V_466 ( V_73 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
break;
case V_157 :
F_11 ( & V_73 -> V_95 -> V_262 ) ;
if ( V_73 -> V_95 -> V_263 ) {
V_73 -> V_95 -> V_263 -> V_264 . V_470 +=
V_73 -> V_249 ;
}
F_12 ( & V_73 -> V_95 -> V_262 ) ;
if ( V_73 -> V_467 ) {
F_11 ( & V_73 -> V_95 -> V_262 ) ;
if ( V_73 -> V_95 -> V_263 ) {
V_73 -> V_95 -> V_263 -> V_264 . V_469 +=
V_73 -> V_249 ;
}
F_12 ( & V_73 -> V_95 -> V_262 ) ;
V_39 = V_73 -> V_83 -> V_466 ( V_73 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
break;
}
case V_155 :
V_39 = V_73 -> V_83 -> V_299 ( V_73 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
break;
default:
break;
}
F_50 ( V_73 ) ;
F_49 ( V_73 ) ;
return;
V_301:
F_28 ( L_173
L_174 , V_73 , V_73 -> V_154 ) ;
V_73 -> V_88 = V_152 ;
F_135 ( V_73 , V_73 -> V_76 ) ;
}
static void F_168 ( struct V_72 * V_73 )
{
struct V_77 * V_78 , * V_280 ;
unsigned long V_64 ;
F_78 ( V_471 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_80 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! ( V_78 -> V_79 & V_80 ) )
F_169 ( & V_78 -> V_111 , & V_471 ) ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
while ( ! F_35 ( & V_471 ) ) {
V_78 = F_59 ( & V_471 , struct V_77 , V_111 ) ;
if ( V_78 -> V_472 != V_73 -> V_324 &&
V_78 -> V_472 != V_73 -> V_467 )
F_105 ( V_78 -> V_472 ) ;
F_34 ( & V_78 -> V_111 ) ;
V_73 -> V_76 -> V_123 -> V_473 ( V_78 ) ;
}
}
static inline void F_170 ( struct V_320 * V_474 , int V_475 )
{
struct V_320 * V_321 ;
int V_323 ;
F_153 (sgl, sg, nents, count)
F_171 ( F_155 ( V_321 ) ) ;
F_105 ( V_474 ) ;
}
static inline void F_172 ( struct V_72 * V_73 )
{
if ( V_73 -> V_125 & V_476 )
return;
F_170 ( V_73 -> V_324 , V_73 -> V_325 ) ;
V_73 -> V_324 = NULL ;
V_73 -> V_325 = 0 ;
F_170 ( V_73 -> V_467 , V_73 -> V_477 ) ;
V_73 -> V_467 = NULL ;
V_73 -> V_477 = 0 ;
}
static void F_173 ( struct V_72 * V_73 )
{
F_10 ( ! V_73 -> V_83 ) ;
if ( V_73 -> V_2 )
F_174 ( V_73 -> V_2 ) ;
if ( V_73 -> V_142 != V_73 -> V_261 )
F_105 ( V_73 -> V_142 ) ;
if ( V_73 -> V_478 != 0 ) {
F_124 ( V_73 -> V_41 , V_73 ) ;
return;
}
V_73 -> V_83 -> V_479 ( V_73 ) ;
}
static void F_53 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
int V_480 = 0 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( F_47 ( & V_73 -> V_481 ) ) {
if ( ! F_66 ( & V_73 -> V_481 ) )
goto V_482;
}
if ( F_47 ( & V_73 -> V_483 ) ) {
if ( ! F_66 ( & V_73 -> V_483 ) )
goto V_482;
}
if ( F_47 ( & V_73 -> V_99 ) ) {
F_14 ( & V_73 -> V_99 , 0 ) ;
F_43 ( V_73 ) ;
V_480 = 1 ;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( V_480 != 0 )
F_168 ( V_73 ) ;
F_172 ( V_73 ) ;
F_173 ( V_73 ) ;
return;
V_482:
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
int F_175 (
struct V_72 * V_73 ,
struct V_320 * V_474 ,
T_1 V_484 ,
struct V_320 * V_485 ,
T_1 V_486 )
{
if ( ! V_474 || ! V_484 )
return 0 ;
if ( ( V_73 -> V_125 & V_357 ) ||
( V_73 -> V_125 & V_368 ) ) {
if ( V_73 -> V_125 & V_459 ) {
F_165 ( L_175
L_176 ) ;
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_260 ;
return - V_182 ;
}
V_73 -> V_324 = V_474 ;
V_73 -> V_325 = V_484 ;
if ( V_485 && V_486 ) {
V_73 -> V_467 = V_485 ;
V_73 -> V_477 = V_486 ;
}
V_73 -> V_125 |= V_476 ;
}
return 0 ;
}
void * F_176 ( struct V_72 * V_73 )
{
struct V_320 * V_321 = V_73 -> V_324 ;
struct V_487 * * V_488 ;
int V_188 ;
F_10 ( ! V_321 ) ;
if ( ! V_73 -> V_325 )
return NULL ;
else if ( V_73 -> V_325 == 1 )
return F_177 ( F_155 ( V_321 ) ) + V_321 -> V_322 ;
V_488 = F_151 ( sizeof( * V_488 ) * V_73 -> V_325 , V_42 ) ;
if ( ! V_488 )
return NULL ;
F_153 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_488 [ V_188 ] = F_155 ( V_321 ) ;
}
V_73 -> V_489 = F_178 ( V_488 , V_73 -> V_325 , V_490 , V_491 ) ;
F_105 ( V_488 ) ;
if ( ! V_73 -> V_489 )
return NULL ;
return V_73 -> V_489 + V_73 -> V_324 [ 0 ] . V_322 ;
}
void F_179 ( struct V_72 * V_73 )
{
if ( ! V_73 -> V_325 )
return;
else if ( V_73 -> V_325 == 1 )
F_180 ( F_155 ( V_73 -> V_324 ) ) ;
F_181 ( V_73 -> V_489 ) ;
V_73 -> V_489 = NULL ;
}
static int
F_182 ( struct V_72 * V_73 )
{
T_1 V_327 = V_73 -> V_249 ;
unsigned int V_475 ;
struct V_487 * V_487 ;
T_5 V_492 ;
int V_188 = 0 ;
V_475 = F_183 ( V_327 , V_493 ) ;
V_73 -> V_324 = F_151 ( sizeof( struct V_320 ) * V_475 , V_42 ) ;
if ( ! V_73 -> V_324 )
return - V_28 ;
V_73 -> V_325 = V_475 ;
F_184 ( V_73 -> V_324 , V_475 ) ;
V_492 = V_73 -> V_125 & V_357 ? 0 : V_494 ;
while ( V_327 ) {
T_1 V_495 = F_185 ( T_1 , V_327 , V_493 ) ;
V_487 = F_186 ( V_42 | V_492 ) ;
if ( ! V_487 )
goto V_3;
F_187 ( & V_73 -> V_324 [ V_188 ] , V_487 , V_495 , 0 ) ;
V_327 -= V_495 ;
V_188 ++ ;
}
return 0 ;
V_3:
while ( V_188 >= 0 ) {
F_171 ( F_155 ( & V_73 -> V_324 [ V_188 ] ) ) ;
V_188 -- ;
}
F_105 ( V_73 -> V_324 ) ;
V_73 -> V_324 = NULL ;
return - V_28 ;
}
static inline T_6 F_188 (
struct V_74 * V_75 ,
unsigned long long V_496 ,
T_6 V_318 )
{
V_318 = F_185 ( T_6 , V_318 , V_75 -> V_168 -> V_169 . V_171 ) ;
if ( V_75 -> V_123 -> V_200 ( V_75 ) == V_336 )
if ( ( V_496 + V_318 ) > F_158 ( V_75 ) )
V_318 = ( ( F_158 ( V_75 ) - V_496 ) + 1 ) ;
return V_318 ;
}
void F_189 ( struct V_72 * V_73 )
{
struct V_320 * V_497 = NULL ;
struct V_320 * V_498 = NULL ;
int V_499 = 0 ;
struct V_320 * V_321 ;
struct V_77 * V_78 ;
T_1 V_500 = 0 ;
int V_188 ;
F_10 ( ! V_73 -> V_83 -> V_501 ) ;
F_44 (task, &cmd->t_task_list, t_list) {
if ( ! V_78 -> V_472 )
continue;
if ( ! V_497 ) {
V_497 = V_78 -> V_472 ;
V_500 = V_78 -> V_502 ;
} else {
F_190 ( V_498 , V_499 , V_78 -> V_472 ) ;
V_500 += V_78 -> V_502 ;
}
V_499 = ( V_78 -> V_502 + 1 ) ;
V_498 = V_78 -> V_472 ;
}
V_73 -> V_503 = V_497 ;
V_73 -> V_504 = V_500 ;
F_28 ( L_177
L_178 , V_73 , V_73 -> V_503 ,
V_73 -> V_504 ) ;
F_153 (cmd->t_tasks_sg_chained, sg,
cmd->t_tasks_sg_chained_no, i) {
F_28 ( L_179 ,
V_188 , V_321 , F_155 ( V_321 ) , V_321 -> V_327 , V_321 -> V_322 ) ;
if ( F_191 ( V_321 ) )
F_28 ( L_180 , V_321 ) ;
if ( F_192 ( V_321 ) )
F_28 ( L_181 , V_321 ) ;
}
}
static int
F_193 ( struct V_72 * V_73 ,
enum V_244 V_154 ,
struct V_320 * V_505 , unsigned int V_506 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
int V_507 , V_188 ;
unsigned long long V_496 ;
T_6 V_318 , V_508 ;
T_1 V_509 ;
if ( F_159 ( V_73 ) < 0 )
return - V_182 ;
V_508 = V_75 -> V_168 -> V_169 . V_171 ;
V_509 = V_75 -> V_168 -> V_169 . V_170 ;
F_76 ( V_73 -> V_249 % V_509 ) ;
V_496 = V_73 -> V_337 ;
V_318 = F_183 ( V_73 -> V_249 , V_509 ) ;
V_507 = F_194 ( V_318 , V_508 ) ;
if ( V_507 == 1 ) {
struct V_77 * V_78 ;
unsigned long V_64 ;
V_78 = F_107 ( V_73 , V_154 ) ;
if ( ! V_78 )
return - V_28 ;
V_78 -> V_472 = V_505 ;
V_78 -> V_502 = V_506 ;
V_78 -> V_510 = V_496 ;
V_78 -> V_511 = V_318 ;
V_78 -> V_512 = V_78 -> V_511 * V_509 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_26 ( & V_78 -> V_111 , & V_73 -> V_109 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return V_507 ;
}
for ( V_188 = 0 ; V_188 < V_507 ; V_188 ++ ) {
struct V_77 * V_78 ;
unsigned int V_512 , V_513 ;
struct V_320 * V_321 ;
unsigned long V_64 ;
int V_323 ;
V_78 = F_107 ( V_73 , V_154 ) ;
if ( ! V_78 )
return - V_28 ;
V_78 -> V_510 = V_496 ;
V_78 -> V_511 = F_195 ( V_318 , V_508 ) ;
V_78 -> V_512 = V_78 -> V_511 * V_509 ;
V_78 -> V_502 = F_183 ( V_78 -> V_512 , V_493 ) ;
if ( V_73 -> V_83 -> V_501 && ( V_188 < ( V_507 - 1 ) ) ) {
V_513 = ( V_78 -> V_502 + 1 ) ;
} else
V_513 = V_78 -> V_502 ;
V_78 -> V_472 = F_151 ( sizeof( struct V_320 ) *
V_513 , V_42 ) ;
if ( ! V_78 -> V_472 ) {
V_73 -> V_76 -> V_123 -> V_473 ( V_78 ) ;
return - V_28 ;
}
F_184 ( V_78 -> V_472 , V_513 ) ;
V_512 = V_78 -> V_512 ;
F_153 (task->task_sg, sg, task->task_sg_nents, count) {
if ( V_505 -> V_327 > V_512 )
break;
* V_321 = * V_505 ;
V_512 -= V_505 -> V_327 ;
V_505 = F_196 ( V_505 ) ;
}
V_496 += V_78 -> V_511 ;
V_318 -= V_78 -> V_511 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_26 ( & V_78 -> V_111 , & V_73 -> V_109 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
}
return V_507 ;
}
static int
F_197 ( struct V_72 * V_73 )
{
struct V_77 * V_78 ;
unsigned long V_64 ;
if ( ( V_73 -> V_125 & V_368 ) &&
! V_73 -> V_249 )
return 0 ;
V_78 = F_107 ( V_73 , V_73 -> V_154 ) ;
if ( ! V_78 )
return - V_28 ;
V_78 -> V_472 = V_73 -> V_324 ;
V_78 -> V_512 = V_73 -> V_249 ;
V_78 -> V_502 = V_73 -> V_325 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_26 ( & V_78 -> V_111 , & V_73 -> V_109 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 1 ;
}
int F_119 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
int V_514 , V_515 = 0 ;
int V_516 = 1 ;
int V_39 = 0 ;
if ( ! ( V_73 -> V_125 & V_476 ) &&
V_73 -> V_249 ) {
V_39 = F_182 ( V_73 ) ;
if ( V_39 < 0 )
goto V_517;
}
if ( V_73 -> V_467 &&
V_75 -> V_123 -> V_189 != V_190 ) {
F_10 ( ! ( V_73 -> V_125 & V_357 ) ) ;
V_515 = F_193 ( V_73 ,
V_156 , V_73 -> V_467 ,
V_73 -> V_477 ) ;
if ( V_515 <= 0 )
goto V_517;
F_55 ( & V_73 -> V_481 ) ;
F_55 ( & V_73 -> V_483 ) ;
V_516 = 0 ;
}
if ( V_73 -> V_125 & V_357 ) {
V_514 = F_193 ( V_73 ,
V_73 -> V_154 , V_73 -> V_324 ,
V_73 -> V_325 ) ;
} else {
V_514 = F_197 ( V_73 ) ;
}
if ( V_514 < 0 )
goto V_517;
else if ( ! V_514 && ( V_73 -> V_125 & V_357 ) ) {
V_73 -> V_88 = V_134 ;
F_14 ( & V_73 -> V_92 , 1 ) ;
if ( V_73 -> V_142 [ 0 ] == V_424 ) {
T_3 V_518 = 0 , V_519 = 0 ;
F_198 ( V_73 ,
& V_518 , & V_519 ) ;
}
F_67 ( & V_73 -> V_121 , V_133 ) ;
F_68 ( V_25 , & V_73 -> V_121 ) ;
return 0 ;
}
if ( V_516 ) {
F_55 ( & V_73 -> V_481 ) ;
F_55 ( & V_73 -> V_483 ) ;
}
V_73 -> V_283 = ( V_514 + V_515 ) ;
F_14 ( & V_73 -> V_131 , V_73 -> V_283 ) ;
F_14 ( & V_73 -> V_86 , V_73 -> V_283 ) ;
if ( V_73 -> V_154 == V_157 ) {
F_71 ( V_73 ) ;
return F_199 ( V_73 ) ;
}
F_142 ( V_73 ) ;
return 0 ;
V_517:
V_73 -> V_125 |= V_259 ;
V_73 -> V_118 = V_119 ;
return - V_182 ;
}
void F_200 ( struct V_72 * V_73 )
{
F_142 ( V_73 ) ;
}
static void F_201 ( struct V_72 * V_73 )
{
int V_39 ;
V_39 = V_73 -> V_83 -> V_520 ( V_73 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 ) {
F_28 ( L_182 ,
V_73 ) ;
F_135 ( V_73 , V_73 -> V_76 ) ;
}
}
static int F_199 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
int V_39 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
V_73 -> V_88 = V_521 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_46 ( V_73 , 1 , 0 ) ;
V_39 = V_73 -> V_83 -> V_520 ( V_73 ) ;
if ( V_39 == - V_300 || V_39 == - V_28 )
goto V_301;
else if ( V_39 < 0 )
return V_39 ;
return 1 ;
V_301:
F_28 ( L_182 , V_73 ) ;
V_73 -> V_88 = V_153 ;
F_135 ( V_73 , V_73 -> V_76 ) ;
return 0 ;
}
void F_202 ( struct V_72 * V_73 , int V_522 )
{
if ( ! ( V_73 -> V_125 & V_523 ) ) {
if ( V_522 && V_73 -> V_2 )
F_203 ( V_73 ) ;
F_173 ( V_73 ) ;
} else {
if ( V_522 )
F_203 ( V_73 ) ;
F_204 ( V_73 -> V_41 -> V_50 , V_73 ) ;
if ( V_73 -> V_95 )
F_50 ( V_73 ) ;
F_168 ( V_73 ) ;
F_53 ( V_73 ) ;
}
}
void F_121 ( struct V_5 * V_41 , struct V_72 * V_72 ,
bool V_524 )
{
unsigned long V_64 ;
F_205 ( & V_72 -> V_525 ) ;
if ( V_524 == true )
F_206 ( & V_72 -> V_525 ) ;
F_33 ( & V_41 -> V_47 , V_64 ) ;
F_26 ( & V_72 -> V_253 , & V_41 -> V_45 ) ;
V_72 -> V_478 = 1 ;
F_37 ( & V_41 -> V_47 , V_64 ) ;
}
static void F_207 ( struct V_526 * V_526 )
{
struct V_72 * V_72 = F_36 ( V_526 , struct V_72 , V_525 ) ;
struct V_5 * V_41 = V_72 -> V_41 ;
unsigned long V_64 ;
F_33 ( & V_41 -> V_47 , V_64 ) ;
if ( F_35 ( & V_72 -> V_253 ) ) {
F_37 ( & V_41 -> V_47 , V_64 ) ;
F_76 ( 1 ) ;
return;
}
if ( V_41 -> V_527 && V_72 -> V_528 ) {
F_37 ( & V_41 -> V_47 , V_64 ) ;
F_48 ( & V_72 -> V_255 ) ;
return;
}
F_34 ( & V_72 -> V_253 ) ;
F_37 ( & V_41 -> V_47 , V_64 ) ;
V_72 -> V_83 -> V_479 ( V_72 ) ;
}
int F_124 ( struct V_5 * V_41 , struct V_72 * V_72 )
{
return F_208 ( & V_72 -> V_525 , F_207 ) ;
}
void F_209 ( struct V_5 * V_41 )
{
struct V_72 * V_72 ;
unsigned long V_64 ;
F_76 ( ! F_35 ( & V_41 -> V_46 ) ) ;
F_15 ( & V_41 -> V_46 ) ;
F_33 ( & V_41 -> V_47 , V_64 ) ;
V_41 -> V_527 = 1 ;
F_79 ( & V_41 -> V_45 , & V_41 -> V_46 ) ;
F_44 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_72 -> V_528 = 1 ;
F_37 ( & V_41 -> V_47 , V_64 ) ;
}
void F_210 (
struct V_5 * V_41 ,
int V_522 )
{
struct V_72 * V_72 , * V_529 ;
bool V_270 = false ;
F_80 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_34 ( & V_72 -> V_253 ) ;
F_28 ( L_183
L_184 , V_72 , V_72 -> V_88 ,
V_72 -> V_83 -> V_282 ( V_72 ) ) ;
if ( V_522 ) {
F_28 ( L_185
L_186 , V_72 , V_72 -> V_88 ,
V_72 -> V_83 -> V_282 ( V_72 ) ) ;
V_270 = F_203 ( V_72 ) ;
F_28 ( L_187
L_186 , V_72 , V_72 -> V_88 ,
V_72 -> V_83 -> V_282 ( V_72 ) ) ;
}
if ( ! V_270 ) {
F_131 ( & V_72 -> V_255 ) ;
F_28 ( L_188
L_186 , V_72 , V_72 -> V_88 ,
V_72 -> V_83 -> V_282 ( V_72 ) ) ;
}
V_72 -> V_83 -> V_479 ( V_72 ) ;
}
}
static int F_211 ( struct V_72 * V_73 , struct V_95 * V_98 )
{
unsigned long V_64 ;
int V_39 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( F_47 ( & V_73 -> V_94 ) ) {
F_14 ( & V_73 -> V_90 , 0 ) ;
F_28 ( L_189
L_190 , V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_46 ( V_73 , 1 , 0 ) ;
return - V_276 ;
}
F_14 ( & V_73 -> V_530 , 1 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_57 ( & V_73 -> V_76 -> V_105 . V_37 ) ;
V_39 = F_132 ( V_73 ) ;
F_28 ( L_191
L_184 , V_73 , V_73 -> V_283 , V_39 ) ;
if ( ! V_39 ) {
F_28 ( L_192 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_131 ( & V_73 -> V_93 ) ;
F_28 ( L_193 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
}
F_52 ( V_73 ) ;
return 0 ;
}
static void F_212 ( struct V_95 * V_98 )
{
struct V_72 * V_73 = NULL ;
unsigned long V_531 , V_532 ;
F_33 ( & V_98 -> V_101 , V_531 ) ;
while ( ! F_35 ( & V_98 -> V_533 ) ) {
V_73 = F_59 ( & V_98 -> V_533 ,
struct V_72 , V_103 ) ;
F_34 ( & V_73 -> V_103 ) ;
F_14 ( & V_73 -> V_102 , 0 ) ;
F_11 ( & V_73 -> V_89 ) ;
F_28 ( L_194
L_195 ,
V_73 -> V_95 -> V_268 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_14 ( & V_73 -> V_90 , 1 ) ;
F_12 ( & V_73 -> V_89 ) ;
F_37 ( & V_98 -> V_101 , V_531 ) ;
if ( ! V_73 -> V_95 ) {
F_4 ( L_196 ,
V_73 -> V_83 -> V_84 ( V_73 ) ,
V_73 -> V_83 -> V_282 ( V_73 ) , V_73 -> V_88 ) ;
F_213 () ;
}
F_28 ( L_197
L_198 , V_73 -> V_95 -> V_268 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
if ( F_211 ( V_73 , V_73 -> V_95 ) < 0 ) {
F_33 ( & V_98 -> V_101 , V_531 ) ;
continue;
}
F_28 ( L_199
L_200 ,
V_73 -> V_95 -> V_268 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_33 ( & V_73 -> V_89 , V_532 ) ;
if ( ! F_47 ( & V_73 -> V_99 ) ) {
F_37 ( & V_73 -> V_89 , V_532 ) ;
goto V_534;
}
F_14 ( & V_73 -> V_99 , 0 ) ;
F_43 ( V_73 ) ;
F_37 ( & V_73 -> V_89 , V_532 ) ;
F_168 ( V_73 ) ;
V_534:
F_123 ( V_73 ,
V_286 , 0 ) ;
F_33 ( & V_73 -> V_89 , V_532 ) ;
if ( F_47 ( & V_73 -> V_530 ) ) {
F_28 ( L_201
L_202 ,
V_98 -> V_268 ,
V_73 , V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 ,
V_532 ) ;
F_46 ( V_73 , 1 , 0 ) ;
F_48 ( & V_73 -> V_254 ) ;
F_33 ( & V_98 -> V_101 , V_531 ) ;
continue;
}
F_28 ( L_203 ,
V_98 -> V_268 , V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_532 ) ;
F_33 ( & V_98 -> V_101 , V_531 ) ;
}
F_37 ( & V_98 -> V_101 , V_531 ) ;
}
static int F_214 ( void * V_535 )
{
struct V_95 * V_98 = V_535 ;
F_212 ( V_98 ) ;
F_48 ( & V_98 -> V_536 ) ;
return 0 ;
}
int F_215 ( struct V_95 * V_98 )
{
struct V_537 * V_538 ;
V_538 = F_101 ( F_214 , V_98 ,
L_204 , V_98 -> V_268 ) ;
if ( F_102 ( V_538 ) ) {
F_4 ( L_205 ) ;
return F_216 ( V_538 ) ;
}
F_131 ( & V_98 -> V_536 ) ;
return 0 ;
}
bool F_203 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( ! ( V_73 -> V_125 & V_523 ) && ! ( V_73 -> V_2 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return false ;
}
if ( ! ( V_73 -> V_125 & V_305 ) && ! V_73 -> V_2 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return false ;
}
if ( F_47 ( & V_73 -> V_90 ) ) {
F_28 ( L_206
L_207
L_208 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_48 ( & V_73 -> V_93 ) ;
F_131 ( & V_73 -> V_254 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_43 ( V_73 ) ;
F_28 ( L_209
L_210
L_211 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_14 ( & V_73 -> V_90 , 0 ) ;
}
if ( ! F_47 ( & V_73 -> V_92 ) ||
F_47 ( & V_73 -> V_539 ) ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return false ;
}
F_14 ( & V_73 -> V_94 , 1 ) ;
F_28 ( L_212
L_213 ,
V_73 , V_73 -> V_83 -> V_84 ( V_73 ) ,
V_73 -> V_83 -> V_282 ( V_73 ) , V_73 -> V_88 ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
F_57 ( & V_73 -> V_76 -> V_105 . V_37 ) ;
F_131 ( & V_73 -> V_96 ) ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
F_14 ( & V_73 -> V_92 , 0 ) ;
F_14 ( & V_73 -> V_94 , 0 ) ;
F_28 ( L_214
L_215 ,
V_73 -> V_83 -> V_84 ( V_73 ) ) ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
return true ;
}
static int F_217 (
struct V_72 * V_73 ,
T_3 * V_540 ,
T_3 * V_541 )
{
* V_540 = V_73 -> V_542 ;
* V_541 = V_73 -> V_543 ;
return 0 ;
}
static int F_162 (
struct V_72 * V_73 ,
T_3 V_540 ,
T_3 V_541 )
{
V_73 -> V_542 = V_540 ;
V_73 -> V_543 = V_541 ;
return 0 ;
}
int F_123 (
struct V_72 * V_73 ,
T_3 V_468 ,
int V_544 )
{
unsigned char * V_328 = V_73 -> V_251 ;
unsigned long V_64 ;
int V_322 ;
T_3 V_540 = 0 , V_541 = 0 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_125 & V_329 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return 0 ;
}
V_73 -> V_125 |= V_329 ;
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( ! V_468 && V_544 )
goto V_545;
if ( ! V_544 )
V_73 -> V_125 |= V_546 ;
V_322 = V_73 -> V_83 -> V_331 ( V_73 ,
V_332 ) ;
switch ( V_468 ) {
case V_286 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_549 ;
V_328 [ V_322 + V_550 ] = 0x25 ;
break;
case V_287 :
case V_551 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_549 ;
V_328 [ V_322 + V_550 ] = 0x20 ;
break;
case V_289 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_549 ;
V_328 [ V_322 + V_550 ] = 0x24 ;
break;
case V_291 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_552 ;
V_328 [ V_322 + V_550 ] = 0x29 ;
V_328 [ V_322 + V_553 ] = 0x03 ;
break;
case V_554 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_552 ;
V_328 [ V_322 + V_550 ] = 0x0c ;
V_328 [ V_322 + V_553 ] = 0x0d ;
break;
case V_260 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_549 ;
V_328 [ V_322 + V_550 ] = 0x24 ;
break;
case V_288 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_549 ;
V_328 [ V_322 + V_550 ] = 0x26 ;
break;
case V_555 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_552 ;
V_328 [ V_322 + V_550 ] = 0x0c ;
V_328 [ V_322 + V_553 ] = 0x0c ;
break;
case V_556 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_552 ;
V_328 [ V_322 + V_550 ] = 0x47 ;
V_328 [ V_322 + V_553 ] = 0x05 ;
break;
case V_557 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_552 ;
V_328 [ V_322 + V_550 ] = 0x11 ;
V_328 [ V_322 + V_553 ] = 0x13 ;
break;
case V_290 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_558 ;
V_328 [ V_322 + V_550 ] = 0x27 ;
break;
case V_292 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_559 ;
F_218 ( V_73 , & V_540 , & V_541 ) ;
V_328 [ V_322 + V_550 ] = V_540 ;
V_328 [ V_322 + V_553 ] = V_541 ;
break;
case V_293 :
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_560 ;
F_217 ( V_73 , & V_540 , & V_541 ) ;
V_328 [ V_322 + V_550 ] = V_540 ;
V_328 [ V_322 + V_553 ] = V_541 ;
break;
case V_119 :
default:
V_328 [ V_322 ] = 0x70 ;
V_328 [ V_322 + V_547 ] = 10 ;
V_328 [ V_322 + V_548 ] = V_549 ;
V_328 [ V_322 + V_550 ] = 0x80 ;
break;
}
V_73 -> V_112 = V_116 ;
V_73 -> V_333 = V_332 + V_322 ;
V_545:
return V_73 -> V_83 -> V_299 ( V_73 ) ;
}
int F_128 ( struct V_72 * V_73 , int V_561 )
{
int V_39 = 0 ;
if ( F_47 ( & V_73 -> V_539 ) != 0 ) {
if ( ! V_561 ||
( V_73 -> V_125 & V_562 ) )
return 1 ;
#if 0
pr_debug("Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_73 -> V_125 |= V_562 ;
V_73 -> V_83 -> V_299 ( V_73 ) ;
V_39 = 1 ;
}
return V_39 ;
}
void F_219 ( struct V_72 * V_73 )
{
unsigned long V_64 ;
F_33 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_125 & V_329 ) {
F_37 ( & V_73 -> V_89 , V_64 ) ;
return;
}
F_37 ( & V_73 -> V_89 , V_64 ) ;
if ( V_73 -> V_154 == V_157 ) {
if ( V_73 -> V_83 -> V_563 ( V_73 ) != 0 ) {
F_55 ( & V_73 -> V_539 ) ;
F_112 () ;
}
}
V_73 -> V_112 = V_564 ;
#if 0
pr_debug("Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_73 -> V_83 -> V_299 ( V_73 ) ;
}
static int F_220 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
struct V_2 * V_565 = V_73 -> V_2 ;
int V_39 ;
switch ( V_565 -> V_566 ) {
case V_567 :
V_565 -> V_568 = V_569 ;
break;
case V_570 :
case V_571 :
case V_572 :
V_565 -> V_568 = V_573 ;
break;
case V_574 :
V_39 = F_221 ( V_75 , V_565 , NULL , NULL ) ;
V_565 -> V_568 = ( ! V_39 ) ? V_575 :
V_569 ;
break;
case V_576 :
V_565 -> V_568 = V_569 ;
break;
case V_577 :
V_565 -> V_568 = V_569 ;
break;
default:
F_4 ( L_216 ,
V_565 -> V_566 ) ;
V_565 -> V_568 = V_569 ;
break;
}
V_73 -> V_88 = V_578 ;
V_73 -> V_83 -> V_579 ( V_73 ) ;
F_49 ( V_73 ) ;
return 0 ;
}
static int V_234 ( void * V_580 )
{
int V_39 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = V_580 ;
while ( ! F_222 () ) {
V_39 = F_223 ( V_75 -> V_105 . V_37 ,
F_47 ( & V_75 -> V_105 . V_35 ) ||
F_222 () ) ;
if ( V_39 < 0 )
goto V_3;
V_581:
V_73 = F_58 ( & V_75 -> V_105 ) ;
if ( ! V_73 )
continue;
switch ( V_73 -> V_88 ) {
case V_266 :
F_213 () ;
break;
case V_274 :
if ( ! V_73 -> V_83 -> V_582 ) {
F_4 ( L_217
L_218 ) ;
F_213 () ;
}
V_39 = V_73 -> V_83 -> V_582 ( V_73 ) ;
if ( V_39 < 0 ) {
F_65 ( V_73 ) ;
break;
}
V_39 = F_119 ( V_73 ) ;
if ( V_39 < 0 ) {
F_65 ( V_73 ) ;
break;
}
break;
case V_277 :
F_200 ( V_73 ) ;
break;
case V_278 :
F_220 ( V_73 ) ;
break;
case V_153 :
F_201 ( V_73 ) ;
break;
case V_152 :
F_166 ( V_73 ) ;
break;
default:
F_4 ( L_219
L_220 ,
V_73 -> V_88 ,
V_73 -> V_83 -> V_84 ( V_73 ) ,
V_73 -> V_83 -> V_282 ( V_73 ) ,
V_73 -> V_95 -> V_268 ) ;
F_213 () ;
}
goto V_581;
}
V_3:
F_76 ( ! F_35 ( & V_75 -> V_145 ) ) ;
F_76 ( ! F_35 ( & V_75 -> V_105 . V_36 ) ) ;
V_75 -> V_233 = NULL ;
return 0 ;
}
