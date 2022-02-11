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
F_4 ( L_5 ) ;
goto V_6;
}
V_7 = F_2 ( L_6 ,
sizeof( struct V_8 ) ,
F_3 ( struct V_8 ) , 0 , NULL ) ;
if ( ! V_7 ) {
F_4 ( L_7
L_3 ) ;
goto V_9;
}
V_10 = F_2 ( L_8 ,
sizeof( struct V_11 ) , F_3 ( struct V_11 ) ,
0 , NULL ) ;
if ( ! V_10 ) {
F_4 ( L_9
L_3 ) ;
goto V_12;
}
V_13 = F_2 ( L_10 ,
sizeof( struct V_14 ) ,
F_3 ( struct V_14 ) , 0 , NULL ) ;
if ( ! V_13 ) {
F_4 ( L_11
L_12 ) ;
goto V_15;
}
V_16 = F_2 ( L_13 ,
sizeof( struct V_17 ) ,
F_3 ( struct V_17 ) , 0 , NULL ) ;
if ( ! V_16 ) {
F_4 ( L_14
L_12 ) ;
goto V_18;
}
V_19 = F_2 (
L_15 ,
sizeof( struct V_20 ) ,
F_3 ( struct V_20 ) ,
0 , NULL ) ;
if ( ! V_19 ) {
F_4 ( L_14
L_16 ) ;
goto V_21;
}
V_22 = F_5 ( L_17 ,
V_23 , 0 ) ;
if ( ! V_22 )
goto V_24;
return 0 ;
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
return - V_25 ;
}
void F_7 ( void )
{
F_8 ( V_22 ) ;
F_6 ( V_1 ) ;
F_6 ( V_4 ) ;
F_6 ( V_7 ) ;
F_6 ( V_10 ) ;
F_6 ( V_13 ) ;
F_6 ( V_16 ) ;
F_6 ( V_19 ) ;
}
T_1 F_9 ( T_2 type )
{
T_1 V_26 ;
F_10 ( ( type < 0 ) || ( type >= V_27 ) ) ;
F_11 ( & V_28 ) ;
V_26 = ++ V_29 [ type ] ;
F_12 ( & V_28 ) ;
return V_26 ;
}
static void F_13 ( struct V_30 * V_31 )
{
F_14 ( & V_31 -> V_32 , 0 ) ;
F_15 ( & V_31 -> V_33 ) ;
F_16 ( & V_31 -> V_34 ) ;
F_17 ( & V_31 -> V_35 ) ;
}
void F_18 ( void )
{
int V_36 ;
if ( V_37 )
return;
V_36 = F_19 ( L_18 ) ;
if ( V_36 != 0 )
F_4 ( L_19 ) ;
V_36 = F_19 ( L_20 ) ;
if ( V_36 != 0 )
F_4 ( L_21 ) ;
V_36 = F_19 ( L_22 ) ;
if ( V_36 != 0 )
F_4 ( L_23 ) ;
V_36 = F_19 ( L_24 ) ;
if ( V_36 != 0 )
F_4 ( L_25 ) ;
V_37 = 1 ;
return;
}
struct V_2 * F_20 ( void )
{
struct V_2 * V_38 ;
V_38 = F_21 ( V_1 , V_39 ) ;
if ( ! V_38 ) {
F_4 ( L_26
L_27 ) ;
return F_22 ( - V_25 ) ;
}
F_15 ( & V_38 -> V_40 ) ;
F_15 ( & V_38 -> V_41 ) ;
F_15 ( & V_38 -> V_42 ) ;
F_15 ( & V_38 -> V_43 ) ;
F_17 ( & V_38 -> V_44 ) ;
F_23 ( & V_38 -> V_45 ) ;
return V_38 ;
}
void F_24 (
struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_2 * V_38 ,
void * V_50 )
{
unsigned char V_51 [ V_52 ] ;
V_38 -> V_47 = V_47 ;
V_38 -> V_50 = V_50 ;
if ( V_49 ) {
if ( V_47 -> V_53 -> V_54 != NULL ) {
memset ( & V_51 [ 0 ] , 0 , V_52 ) ;
V_47 -> V_53 -> V_54 ( V_38 ,
& V_51 [ 0 ] , V_52 ) ;
V_38 -> V_55 = F_25 ( & V_51 [ 0 ] ) ;
}
F_26 ( & V_49 -> V_56 ) ;
F_27 ( & V_49 -> V_57 ) ;
V_49 -> V_58 = V_38 ;
F_28 ( & V_38 -> V_41 ,
& V_49 -> V_59 ) ;
F_29 ( & V_49 -> V_57 ) ;
}
F_28 ( & V_38 -> V_40 , & V_47 -> V_60 ) ;
F_30 ( L_28 ,
V_47 -> V_53 -> V_61 () , V_38 -> V_50 ) ;
}
void F_31 (
struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_2 * V_38 ,
void * V_50 )
{
unsigned long V_62 ;
F_32 ( & V_47 -> V_63 , V_62 ) ;
F_24 ( V_47 , V_49 , V_38 , V_50 ) ;
F_33 ( & V_47 -> V_63 , V_62 ) ;
}
static void F_34 ( struct V_64 * V_64 )
{
struct V_2 * V_38 = F_35 ( V_64 ,
struct V_2 , V_45 ) ;
struct V_46 * V_47 = V_38 -> V_47 ;
V_47 -> V_53 -> V_65 ( V_38 ) ;
}
void F_36 ( struct V_2 * V_38 )
{
F_26 ( & V_38 -> V_45 ) ;
}
int F_37 ( struct V_2 * V_38 )
{
return F_38 ( & V_38 -> V_45 , F_34 ) ;
}
static void F_39 ( struct V_64 * V_64 )
{
struct V_48 * V_66 = F_35 ( V_64 ,
struct V_48 , V_56 ) ;
F_40 ( & V_66 -> V_67 ) ;
}
void F_41 ( struct V_48 * V_66 )
{
F_38 ( & V_66 -> V_56 , F_39 ) ;
}
void F_42 ( struct V_2 * V_38 )
{
struct V_48 * V_49 ;
unsigned long V_62 ;
V_49 = V_38 -> V_48 ;
if ( V_49 ) {
F_32 ( & V_49 -> V_57 , V_62 ) ;
if ( V_49 -> V_68 == 0 )
F_43 ( & V_38 -> V_41 ) ;
if ( F_44 ( & V_49 -> V_59 ) )
V_49 -> V_58 = NULL ;
else {
V_49 -> V_58 = F_35 (
V_49 -> V_59 . V_69 ,
struct V_2 , V_41 ) ;
}
F_33 ( & V_49 -> V_57 , V_62 ) ;
}
}
void F_45 ( struct V_2 * V_38 )
{
F_46 ( V_1 , V_38 ) ;
}
void F_47 ( struct V_2 * V_38 )
{
struct V_46 * V_47 = V_38 -> V_47 ;
struct V_70 * V_71 ;
struct V_48 * V_49 ;
unsigned long V_62 ;
bool V_72 = true ;
if ( ! V_47 ) {
F_45 ( V_38 ) ;
return;
}
V_71 = V_47 -> V_53 ;
F_32 ( & V_47 -> V_63 , V_62 ) ;
F_43 ( & V_38 -> V_40 ) ;
V_38 -> V_47 = NULL ;
V_38 -> V_50 = NULL ;
F_33 ( & V_47 -> V_63 , V_62 ) ;
V_49 = V_38 -> V_48 ;
F_32 ( & V_47 -> V_73 , V_62 ) ;
if ( V_49 && V_49 -> V_74 ) {
if ( ! V_71 -> V_75 ( V_47 ) ) {
F_43 ( & V_49 -> V_76 ) ;
V_47 -> V_77 -- ;
F_33 ( & V_47 -> V_73 , V_62 ) ;
F_48 ( V_49 ) ;
F_49 ( V_49 , V_47 ) ;
V_71 -> V_78 ( V_47 , V_49 ) ;
V_72 = false ;
F_32 ( & V_47 -> V_73 , V_62 ) ;
}
}
F_33 ( & V_47 -> V_73 , V_62 ) ;
F_30 ( L_29 ,
V_47 -> V_53 -> V_61 () ) ;
if ( V_49 && V_72 == true )
F_41 ( V_49 ) ;
F_45 ( V_38 ) ;
}
static void F_50 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_84 * V_85 ;
unsigned long V_62 ;
if ( ! V_82 )
return;
F_51 (task, &cmd->t_task_list, t_list) {
if ( V_85 -> V_86 & V_87 )
continue;
F_32 ( & V_82 -> V_88 , V_62 ) ;
if ( V_85 -> V_89 ) {
F_30 ( L_30 ,
V_80 -> V_71 -> V_90 ( V_80 ) , V_82 , V_85 ) ;
F_43 ( & V_85 -> V_91 ) ;
F_52 ( & V_80 -> V_92 ) ;
V_85 -> V_89 = false ;
}
F_33 ( & V_82 -> V_88 , V_62 ) ;
}
}
static int F_53 (
struct V_79 * V_80 ,
int V_93 ,
T_3 V_94 )
{
unsigned long V_62 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_96 & V_97 ) {
F_30 ( L_31 ,
V_98 , __LINE__ , V_80 -> V_71 -> V_90 ( V_80 ) ) ;
V_80 -> V_96 &= ~ V_99 ;
if ( V_93 == 2 )
F_50 ( V_80 ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_40 ( & V_80 -> V_100 ) ;
return 1 ;
}
if ( V_80 -> V_96 & V_101 ) {
F_30 ( L_32 ,
V_98 , __LINE__ ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
if ( V_93 == 2 )
F_50 ( V_80 ) ;
if ( V_93 == 2 )
V_80 -> V_102 = NULL ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_40 ( & V_80 -> V_103 ) ;
return 1 ;
}
if ( V_93 ) {
V_80 -> V_96 &= ~ V_99 ;
if ( V_93 == 2 ) {
F_50 ( V_80 ) ;
V_80 -> V_102 = NULL ;
if ( V_80 -> V_71 -> V_104 != NULL ) {
F_33 (
& V_80 -> V_95 , V_62 ) ;
return V_80 -> V_71 -> V_104 ( V_80 ) ;
}
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
return 0 ;
} else if ( V_94 )
V_80 -> V_94 = V_94 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
return 0 ;
}
static int F_54 ( struct V_79 * V_80 )
{
return F_53 ( V_80 , 2 , 0 ) ;
}
static void F_55 ( struct V_79 * V_80 )
{
struct V_102 * V_105 = V_80 -> V_102 ;
unsigned long V_62 ;
if ( ! V_105 )
return;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_96 & V_106 ) {
V_80 -> V_96 &= ~ V_106 ;
F_50 ( V_80 ) ;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_32 ( & V_105 -> V_107 , V_62 ) ;
if ( ! F_44 ( & V_80 -> V_108 ) )
F_56 ( & V_80 -> V_108 ) ;
F_33 ( & V_105 -> V_107 , V_62 ) ;
}
void F_57 ( struct V_79 * V_80 , int remove )
{
if ( ! ( V_80 -> V_109 & V_110 ) )
F_55 ( V_80 ) ;
if ( F_54 ( V_80 ) )
return;
if ( remove ) {
F_58 ( V_80 ) ;
F_59 ( V_80 ) ;
}
}
static void F_60 ( struct V_79 * V_80 , int V_94 ,
bool V_111 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_30 * V_31 = & V_82 -> V_112 ;
unsigned long V_62 ;
if ( V_94 ) {
F_32 ( & V_80 -> V_95 , V_62 ) ;
V_80 -> V_94 = V_94 ;
V_80 -> V_96 |= V_99 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
}
F_32 ( & V_31 -> V_35 , V_62 ) ;
if ( ! F_44 ( & V_80 -> V_113 ) )
F_43 ( & V_80 -> V_113 ) ;
else
F_61 ( & V_31 -> V_32 ) ;
if ( V_111 )
F_62 ( & V_80 -> V_113 , & V_31 -> V_33 ) ;
else
F_28 ( & V_80 -> V_113 , & V_31 -> V_33 ) ;
V_80 -> V_96 |= V_114 ;
F_33 ( & V_31 -> V_35 , V_62 ) ;
F_63 ( & V_31 -> V_34 ) ;
}
static struct V_79 *
F_64 ( struct V_30 * V_31 )
{
struct V_79 * V_80 ;
unsigned long V_62 ;
F_32 ( & V_31 -> V_35 , V_62 ) ;
if ( F_44 ( & V_31 -> V_33 ) ) {
F_33 ( & V_31 -> V_35 , V_62 ) ;
return NULL ;
}
V_80 = F_65 ( & V_31 -> V_33 , struct V_79 , V_113 ) ;
V_80 -> V_96 &= ~ V_114 ;
F_56 ( & V_80 -> V_113 ) ;
F_52 ( & V_31 -> V_32 ) ;
F_33 ( & V_31 -> V_35 , V_62 ) ;
return V_80 ;
}
static void F_58 ( struct V_79 * V_80 )
{
struct V_30 * V_31 = & V_80 -> V_83 -> V_112 ;
unsigned long V_62 ;
F_32 ( & V_31 -> V_35 , V_62 ) ;
if ( ! ( V_80 -> V_96 & V_114 ) ) {
F_33 ( & V_31 -> V_35 , V_62 ) ;
return;
}
V_80 -> V_96 &= ~ V_114 ;
F_52 ( & V_31 -> V_32 ) ;
F_56 ( & V_80 -> V_113 ) ;
F_33 ( & V_31 -> V_35 , V_62 ) ;
}
void F_66 ( struct V_79 * V_80 , int V_115 )
{
struct V_84 * V_85 = F_67 ( V_80 -> V_116 . V_117 ,
struct V_84 , V_118 ) ;
if ( V_115 ) {
V_80 -> V_119 = V_120 ;
V_85 -> V_121 = V_122 ;
} else {
V_85 -> V_121 = V_123 ;
V_85 -> V_124 -> V_125 =
V_126 ;
}
F_68 ( V_85 , V_115 ) ;
}
static void F_69 ( struct V_127 * V_128 )
{
struct V_79 * V_80 = F_35 ( V_128 , struct V_79 , V_128 ) ;
F_70 ( V_80 ) ;
}
void F_68 ( struct V_84 * V_85 , int V_129 )
{
struct V_79 * V_80 = V_85 -> V_124 ;
struct V_81 * V_82 = V_80 -> V_83 ;
unsigned long V_62 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
V_85 -> V_86 &= ~ V_87 ;
if ( V_82 && V_82 -> V_130 -> V_131 ) {
if ( V_82 -> V_130 -> V_131 ( V_85 ) != 0 ) {
V_80 -> V_109 |= V_132 ;
V_85 -> V_86 |= V_133 ;
V_129 = 1 ;
}
}
if ( V_85 -> V_86 & V_134 ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_40 ( & V_85 -> V_135 ) ;
return;
}
if ( ! V_129 )
V_80 -> V_96 |= V_136 ;
if ( ! F_71 ( & V_80 -> V_137 ) ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return;
}
if ( V_80 -> V_96 & V_138 &&
V_80 -> V_96 & V_101 ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_40 ( & V_80 -> V_103 ) ;
return;
} else if ( V_80 -> V_96 & V_136 ) {
V_80 -> V_125 = V_126 ;
F_72 ( & V_80 -> V_128 , F_69 ) ;
} else {
F_72 ( & V_80 -> V_128 , V_139 ) ;
}
V_80 -> V_94 = V_140 ;
V_80 -> V_96 |= ( V_141 | V_99 ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_73 ( V_22 , & V_80 -> V_128 ) ;
}
static inline int F_74 (
struct V_84 * V_85 ,
struct V_84 * V_142 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_143 != V_144 ) {
F_28 ( & V_85 -> V_145 , & V_82 -> V_146 ) ;
return 0 ;
}
if ( V_85 -> V_124 -> V_147 == V_148 ) {
F_62 ( & V_85 -> V_145 ,
( V_142 != NULL ) ?
& V_142 -> V_145 :
& V_82 -> V_146 ) ;
F_30 ( L_33
L_34 ,
V_85 -> V_124 -> V_149 [ 0 ] ) ;
return 1 ;
}
F_28 ( & V_85 -> V_145 , & V_82 -> V_146 ) ;
return 0 ;
}
static void F_75 (
struct V_84 * V_85 ,
struct V_84 * V_142 ,
struct V_81 * V_82 )
{
int V_150 ;
V_150 = F_74 ( V_85 , V_142 , V_82 ) ;
F_61 ( & V_82 -> V_151 ) ;
if ( V_85 -> V_89 )
return;
if ( V_150 )
F_62 ( & V_85 -> V_91 , ( V_142 ) ?
& V_142 -> V_91 :
& V_82 -> V_152 ) ;
else
F_28 ( & V_85 -> V_91 , & V_82 -> V_152 ) ;
V_85 -> V_89 = true ;
F_30 ( L_35 ,
V_85 -> V_124 -> V_71 -> V_90 ( V_85 -> V_124 ) ,
V_85 , V_82 ) ;
}
static void F_76 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_84 * V_85 ;
unsigned long V_62 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_51 (task, &cmd->t_task_list, t_list) {
F_11 ( & V_82 -> V_88 ) ;
if ( ! V_85 -> V_89 ) {
F_28 ( & V_85 -> V_91 ,
& V_82 -> V_152 ) ;
V_85 -> V_89 = true ;
F_30 ( L_35 ,
V_85 -> V_124 -> V_71 -> V_90 (
V_85 -> V_124 ) , V_85 , V_82 ) ;
}
F_12 ( & V_82 -> V_88 ) ;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
}
static void F_77 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_84 * V_85 , * V_142 = NULL ;
F_51 (task, &cmd->t_task_list, t_list) {
if ( ! F_44 ( & V_85 -> V_145 ) )
continue;
F_75 ( V_85 , V_142 , V_82 ) ;
V_142 = V_85 ;
}
}
static void F_78 ( struct V_79 * V_80 )
{
unsigned long V_62 ;
struct V_81 * V_82 = V_80 -> V_83 ;
F_32 ( & V_82 -> V_88 , V_62 ) ;
F_77 ( V_80 ) ;
F_33 ( & V_82 -> V_88 , V_62 ) ;
}
void F_79 ( struct V_84 * V_85 ,
struct V_81 * V_82 )
{
F_56 ( & V_85 -> V_145 ) ;
F_52 ( & V_82 -> V_151 ) ;
}
static void F_80 (
struct V_84 * V_85 ,
struct V_81 * V_82 )
{
unsigned long V_62 ;
if ( F_81 ( F_44 ( & V_85 -> V_145 ) ) )
return;
F_32 ( & V_82 -> V_88 , V_62 ) ;
F_79 ( V_85 , V_82 ) ;
F_33 ( & V_82 -> V_88 , V_62 ) ;
}
static void F_82 ( struct V_127 * V_128 )
{
struct V_81 * V_82 = F_35 ( V_128 , struct V_81 ,
V_153 ) ;
F_83 ( V_154 ) ;
struct V_79 * V_80 , * V_155 ;
F_27 ( & V_82 -> V_156 ) ;
F_84 ( & V_82 -> V_154 , & V_154 ) ;
F_29 ( & V_82 -> V_156 ) ;
F_85 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_43 ( & V_80 -> V_157 ) ;
F_52 ( & V_82 -> V_158 ) ;
F_86 () ;
F_30 ( L_36
L_37 , V_80 -> V_71 -> V_61 () , V_80 ,
( V_80 -> V_94 == V_159 ) ? L_38 :
( V_80 -> V_94 == V_160 ) ? L_39
: L_40 ) ;
F_60 ( V_80 , V_80 -> V_94 , true ) ;
}
}
unsigned char * F_87 ( struct V_79 * V_80 )
{
switch ( V_80 -> V_161 ) {
case V_162 :
return L_41 ;
case V_163 :
return L_42 ;
case V_164 :
return L_43 ;
case V_165 :
return L_44 ;
default:
break;
}
return L_40 ;
}
void F_88 (
struct V_81 * V_82 ,
char * V_166 ,
int * V_167 )
{
* V_167 += sprintf ( V_166 + * V_167 , L_45 ) ;
switch ( V_82 -> V_168 ) {
case V_169 :
* V_167 += sprintf ( V_166 + * V_167 , L_46 ) ;
break;
case V_170 :
* V_167 += sprintf ( V_166 + * V_167 , L_47 ) ;
break;
case V_171 :
* V_167 += sprintf ( V_166 + * V_167 , L_48 ) ;
break;
case V_172 :
case V_173 :
* V_167 += sprintf ( V_166 + * V_167 , L_49 ) ;
break;
default:
* V_167 += sprintf ( V_166 + * V_167 , L_50 , V_82 -> V_168 ) ;
break;
}
* V_167 += sprintf ( V_166 + * V_167 , L_51 ,
F_89 ( & V_82 -> V_151 ) , V_82 -> V_174 ) ;
* V_167 += sprintf ( V_166 + * V_167 , L_52 ,
V_82 -> V_175 -> V_176 . V_177 , V_82 -> V_175 -> V_176 . V_178 ) ;
* V_167 += sprintf ( V_166 + * V_167 , L_53 ) ;
}
void F_90 (
struct V_179 * V_180 ,
unsigned char * V_181 ,
int V_182 )
{
unsigned char V_51 [ V_183 ] ;
int V_184 ;
memset ( V_51 , 0 , V_183 ) ;
V_184 = sprintf ( V_51 , L_54 ) ;
switch ( V_180 -> V_185 ) {
case 0x00 :
sprintf ( V_51 + V_184 , L_55 ) ;
break;
case 0x10 :
sprintf ( V_51 + V_184 , L_56 ) ;
break;
case 0x20 :
sprintf ( V_51 + V_184 , L_57 ) ;
break;
case 0x30 :
sprintf ( V_51 + V_184 , L_58 ) ;
break;
case 0x40 :
sprintf ( V_51 + V_184 , L_59
L_60 ) ;
break;
case 0x50 :
sprintf ( V_51 + V_184 , L_61 ) ;
break;
case 0x60 :
sprintf ( V_51 + V_184 , L_62 ) ;
break;
case 0x70 :
sprintf ( V_51 + V_184 , L_63
L_60 ) ;
break;
case 0x80 :
sprintf ( V_51 + V_184 , L_64 ) ;
break;
default:
sprintf ( V_51 + V_184 , L_65 ,
V_180 -> V_185 ) ;
break;
}
if ( V_181 )
strncpy ( V_181 , V_51 , V_182 ) ;
else
F_30 ( L_66 , V_51 ) ;
}
void
F_91 ( struct V_179 * V_180 , unsigned char * V_186 )
{
if ( V_186 [ 1 ] & 0x80 ) {
V_180 -> V_185 = ( V_186 [ 0 ] & 0xf0 ) ;
V_180 -> V_187 = 1 ;
F_90 ( V_180 , NULL , 0 ) ;
}
}
int F_92 (
struct V_179 * V_180 ,
unsigned char * V_181 ,
int V_182 )
{
unsigned char V_51 [ V_183 ] ;
int V_36 = 0 ;
int V_184 ;
memset ( V_51 , 0 , V_183 ) ;
V_184 = sprintf ( V_51 , L_67 ) ;
switch ( V_180 -> V_188 ) {
case 0x00 :
sprintf ( V_51 + V_184 , L_68 ) ;
break;
case 0x10 :
sprintf ( V_51 + V_184 , L_69 ) ;
break;
case 0x20 :
sprintf ( V_51 + V_184 , L_70 ) ;
break;
default:
sprintf ( V_51 + V_184 , L_65 , V_180 -> V_188 ) ;
V_36 = - V_189 ;
break;
}
if ( V_181 )
strncpy ( V_181 , V_51 , V_182 ) ;
else
F_30 ( L_66 , V_51 ) ;
return V_36 ;
}
int F_93 ( struct V_179 * V_180 , unsigned char * V_186 )
{
V_180 -> V_188 = ( V_186 [ 1 ] & 0x30 ) ;
return F_92 ( V_180 , NULL , 0 ) ;
}
int F_94 (
struct V_179 * V_180 ,
unsigned char * V_181 ,
int V_182 )
{
unsigned char V_51 [ V_183 ] ;
int V_36 = 0 ;
int V_184 ;
memset ( V_51 , 0 , V_183 ) ;
V_184 = sprintf ( V_51 , L_71 ) ;
switch ( V_180 -> V_190 ) {
case 0x00 :
sprintf ( V_51 + V_184 , L_72 ) ;
break;
case 0x01 :
sprintf ( V_51 + V_184 , L_73 ) ;
break;
case 0x02 :
sprintf ( V_51 + V_184 , L_74 ) ;
break;
case 0x03 :
sprintf ( V_51 + V_184 , L_75 ) ;
break;
case 0x04 :
sprintf ( V_51 + V_184 , L_76 ) ;
break;
case 0x08 :
sprintf ( V_51 + V_184 , L_77 ) ;
break;
default:
sprintf ( V_51 + V_184 , L_78 ,
V_180 -> V_190 ) ;
V_36 = - V_189 ;
break;
}
if ( V_181 ) {
if ( V_182 < strlen ( V_51 ) + 1 )
return - V_189 ;
strncpy ( V_181 , V_51 , V_182 ) ;
} else {
F_30 ( L_66 , V_51 ) ;
}
return V_36 ;
}
int F_95 ( struct V_179 * V_180 , unsigned char * V_186 )
{
V_180 -> V_190 = ( V_186 [ 1 ] & 0x0f ) ;
return F_94 ( V_180 , NULL , 0 ) ;
}
int F_96 (
struct V_179 * V_180 ,
unsigned char * V_181 ,
int V_182 )
{
unsigned char V_51 [ V_183 ] ;
int V_36 = 0 ;
memset ( V_51 , 0 , V_183 ) ;
switch ( V_180 -> V_191 ) {
case 0x01 :
sprintf ( V_51 , L_79 ,
& V_180 -> V_192 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_51 , L_80 ,
& V_180 -> V_192 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_51 , L_81 ,
& V_180 -> V_192 [ 0 ] ) ;
break;
default:
sprintf ( V_51 , L_82
L_83 , V_180 -> V_191 ) ;
V_36 = - V_189 ;
break;
}
if ( V_181 )
strncpy ( V_181 , V_51 , V_182 ) ;
else
F_30 ( L_66 , V_51 ) ;
return V_36 ;
}
int
F_97 ( struct V_179 * V_180 , unsigned char * V_186 )
{
static const char V_193 [] = L_84 ;
int V_194 = 0 , V_195 = 4 ;
V_180 -> V_191 = ( V_186 [ 0 ] & 0x0f ) ;
switch ( V_180 -> V_191 ) {
case 0x01 :
V_180 -> V_192 [ V_194 ++ ] =
V_193 [ V_180 -> V_190 ] ;
while ( V_195 < ( 4 + V_186 [ 3 ] ) ) {
V_180 -> V_192 [ V_194 ++ ] =
V_193 [ ( V_186 [ V_195 ] & 0xf0 ) >> 4 ] ;
V_180 -> V_192 [ V_194 ++ ] =
V_193 [ V_186 [ V_195 ] & 0x0f ] ;
V_195 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_195 < ( 4 + V_186 [ 3 ] ) )
V_180 -> V_192 [ V_194 ++ ] = V_186 [ V_195 ++ ] ;
break;
default:
break;
}
return F_96 ( V_180 , NULL , 0 ) ;
}
static void F_98 ( struct V_81 * V_82 )
{
if ( V_82 -> V_130 -> V_196 == V_197 ) {
V_82 -> V_143 = V_198 ;
return;
}
V_82 -> V_143 = V_144 ;
F_30 ( L_85
L_86 , V_82 -> V_130 -> V_199 ,
V_82 -> V_130 -> V_200 ( V_82 ) ) ;
}
static void F_99 ( struct V_81 * V_82 )
{
struct V_201 * V_202 = & V_82 -> V_175 -> V_201 ;
char V_51 [ 17 ] ;
int V_195 , V_203 ;
for ( V_195 = 0 ; V_195 < 8 ; V_195 ++ )
if ( V_202 -> V_204 [ V_195 ] >= 0x20 )
V_51 [ V_195 ] = V_202 -> V_204 [ V_195 ] ;
else
V_51 [ V_195 ] = ' ' ;
V_51 [ V_195 ] = '\0' ;
F_30 ( L_87 , V_51 ) ;
for ( V_195 = 0 ; V_195 < 16 ; V_195 ++ )
if ( V_202 -> V_205 [ V_195 ] >= 0x20 )
V_51 [ V_195 ] = V_202 -> V_205 [ V_195 ] ;
else
V_51 [ V_195 ] = ' ' ;
V_51 [ V_195 ] = '\0' ;
F_30 ( L_88 , V_51 ) ;
for ( V_195 = 0 ; V_195 < 4 ; V_195 ++ )
if ( V_202 -> V_206 [ V_195 ] >= 0x20 )
V_51 [ V_195 ] = V_202 -> V_206 [ V_195 ] ;
else
V_51 [ V_195 ] = ' ' ;
V_51 [ V_195 ] = '\0' ;
F_30 ( L_89 , V_51 ) ;
V_203 = V_82 -> V_130 -> V_207 ( V_82 ) ;
F_30 ( L_90 , F_100 ( V_203 ) ) ;
F_30 ( L_91 ,
V_82 -> V_130 -> V_200 ( V_82 ) ) ;
}
struct V_81 * F_101 (
struct V_208 * V_209 ,
struct V_210 * V_130 ,
struct V_211 * V_83 ,
T_1 V_212 ,
void * V_213 ,
struct V_214 * V_215 ,
const char * V_216 ,
const char * V_217 )
{
int V_218 ;
struct V_81 * V_82 ;
V_82 = F_102 ( sizeof( struct V_81 ) , V_39 ) ;
if ( ! V_82 ) {
F_4 ( L_92 ) ;
return NULL ;
}
F_13 ( & V_82 -> V_112 ) ;
V_82 -> V_219 = V_212 ;
V_82 -> V_168 |= V_170 ;
V_82 -> V_220 = V_213 ;
V_82 -> V_208 = V_209 ;
V_82 -> V_175 = V_83 ;
V_82 -> V_130 = V_130 ;
F_15 ( & V_82 -> V_221 ) ;
F_15 ( & V_82 -> V_222 ) ;
F_15 ( & V_82 -> V_223 ) ;
F_15 ( & V_82 -> V_146 ) ;
F_15 ( & V_82 -> V_224 ) ;
F_15 ( & V_82 -> V_152 ) ;
F_15 ( & V_82 -> V_154 ) ;
F_17 ( & V_82 -> V_88 ) ;
F_17 ( & V_82 -> V_225 ) ;
F_17 ( & V_82 -> V_226 ) ;
F_17 ( & V_82 -> V_227 ) ;
F_17 ( & V_82 -> V_228 ) ;
F_17 ( & V_82 -> V_229 ) ;
F_17 ( & V_82 -> V_156 ) ;
F_14 ( & V_82 -> V_230 , 0 ) ;
F_103 ( V_82 , V_215 ) ;
V_82 -> V_231 = F_9 ( V_232 ) ;
V_82 -> V_233 = F_104 () ;
F_17 ( & V_82 -> V_234 ) ;
F_11 ( & V_209 -> V_235 ) ;
F_28 ( & V_82 -> V_221 , & V_209 -> V_236 ) ;
V_209 -> V_237 ++ ;
F_12 ( & V_209 -> V_235 ) ;
F_98 ( V_82 ) ;
V_218 = ( V_209 -> V_238 & V_239 ) ;
F_105 ( V_82 , V_218 ) ;
if ( F_106 ( V_82 , V_218 ) < 0 )
goto V_3;
V_82 -> V_240 = F_107 ( V_241 , V_82 ,
L_93 , V_82 -> V_130 -> V_199 ) ;
if ( F_108 ( V_82 -> V_240 ) ) {
F_4 ( L_94 ,
V_82 -> V_130 -> V_199 ) ;
goto V_3;
}
F_72 ( & V_82 -> V_153 , F_82 ) ;
if ( V_82 -> V_130 -> V_196 != V_197 ) {
if ( ! V_216 || ! V_217 ) {
F_4 ( L_95
L_96 ) ;
goto V_3;
}
strncpy ( & V_82 -> V_175 -> V_201 . V_204 [ 0 ] , L_97 , 8 ) ;
strncpy ( & V_82 -> V_175 -> V_201 . V_205 [ 0 ] , V_216 , 16 ) ;
strncpy ( & V_82 -> V_175 -> V_201 . V_206 [ 0 ] , V_217 , 4 ) ;
}
F_99 ( V_82 ) ;
return V_82 ;
V_3:
F_109 ( V_82 -> V_240 ) ;
F_11 ( & V_209 -> V_235 ) ;
F_43 ( & V_82 -> V_221 ) ;
V_209 -> V_237 -- ;
F_12 ( & V_209 -> V_235 ) ;
F_110 ( V_82 ) ;
F_111 ( V_82 ) ;
return NULL ;
}
static inline void F_112 (
unsigned char * V_242 )
{
switch ( V_242 [ 0 ] ) {
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
break;
default:
V_242 [ 1 ] &= 0x1f ;
break;
}
}
static struct V_84 *
F_113 ( struct V_79 * V_80 ,
enum V_251 V_161 )
{
struct V_84 * V_85 ;
struct V_81 * V_82 = V_80 -> V_83 ;
V_85 = V_82 -> V_130 -> V_252 ( V_80 -> V_149 ) ;
if ( ! V_85 ) {
F_4 ( L_98 ) ;
return NULL ;
}
F_15 ( & V_85 -> V_118 ) ;
F_15 ( & V_85 -> V_145 ) ;
F_15 ( & V_85 -> V_91 ) ;
F_114 ( & V_85 -> V_135 ) ;
V_85 -> V_124 = V_80 ;
V_85 -> V_253 = V_161 ;
return V_85 ;
}
void F_115 (
struct V_79 * V_80 ,
struct V_70 * V_254 ,
struct V_2 * V_38 ,
T_1 V_255 ,
int V_161 ,
int V_256 ,
unsigned char * V_257 )
{
F_15 ( & V_80 -> V_108 ) ;
F_15 ( & V_80 -> V_258 ) ;
F_15 ( & V_80 -> V_157 ) ;
F_15 ( & V_80 -> V_113 ) ;
F_15 ( & V_80 -> V_259 ) ;
F_15 ( & V_80 -> V_116 ) ;
F_114 ( & V_80 -> V_260 ) ;
F_114 ( & V_80 -> V_100 ) ;
F_114 ( & V_80 -> V_103 ) ;
F_114 ( & V_80 -> V_261 ) ;
F_17 ( & V_80 -> V_95 ) ;
V_80 -> V_96 = V_106 ;
V_80 -> V_71 = V_254 ;
V_80 -> V_38 = V_38 ;
V_80 -> V_255 = V_255 ;
V_80 -> V_161 = V_161 ;
V_80 -> V_147 = V_256 ;
V_80 -> V_257 = V_257 ;
}
static int F_116 ( struct V_79 * V_80 )
{
if ( V_80 -> V_83 -> V_143 != V_144 )
return 0 ;
if ( V_80 -> V_147 == V_262 ) {
F_30 ( L_99
L_100 ) ;
return - V_189 ;
}
V_80 -> V_263 = F_117 ( & V_80 -> V_83 -> V_230 ) ;
F_118 () ;
F_30 ( L_101 ,
V_80 -> V_263 , V_80 -> V_147 ,
V_80 -> V_83 -> V_130 -> V_199 ) ;
return 0 ;
}
int F_119 (
struct V_79 * V_80 ,
unsigned char * V_242 )
{
int V_36 ;
F_112 ( V_242 ) ;
if ( F_120 ( V_242 ) > V_264 ) {
F_4 ( L_102
L_103 ,
F_120 ( V_242 ) , V_264 ) ;
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_266 ;
return - V_189 ;
}
if ( F_120 ( V_242 ) > sizeof( V_80 -> V_267 ) ) {
V_80 -> V_149 = F_102 ( F_120 ( V_242 ) ,
V_39 ) ;
if ( ! V_80 -> V_149 ) {
F_4 ( L_104
L_105 ,
F_120 ( V_242 ) ,
( unsigned long ) sizeof( V_80 -> V_267 ) ) ;
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 =
V_126 ;
return - V_25 ;
}
} else
V_80 -> V_149 = & V_80 -> V_267 [ 0 ] ;
memcpy ( V_80 -> V_149 , V_242 , F_120 ( V_242 ) ) ;
V_36 = F_121 ( V_80 , V_242 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( F_116 ( V_80 ) < 0 ) {
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_266 ;
return - V_189 ;
}
F_11 ( & V_80 -> V_102 -> V_268 ) ;
if ( V_80 -> V_102 -> V_269 )
V_80 -> V_102 -> V_269 -> V_270 . V_271 ++ ;
F_12 ( & V_80 -> V_102 -> V_268 ) ;
return 0 ;
}
int F_122 (
struct V_79 * V_80 )
{
int V_36 ;
if ( ! V_80 -> V_102 ) {
F_123 () ;
F_4 ( L_106 ) ;
return - V_189 ;
}
if ( F_124 () ) {
F_123 () ;
F_4 ( L_107
L_108 ) ;
return - V_189 ;
}
V_80 -> V_94 = V_272 ;
V_80 -> V_96 |= V_99 ;
V_36 = F_125 ( V_80 ) ;
if ( V_36 < 0 )
F_70 ( V_80 ) ;
return 0 ;
}
void F_126 ( struct V_79 * V_79 , struct V_2 * V_38 ,
unsigned char * V_242 , unsigned char * V_273 , T_1 V_274 ,
T_1 V_255 , int V_256 , int V_275 , int V_62 )
{
struct V_46 * V_47 ;
int V_276 ;
V_47 = V_38 -> V_47 ;
F_10 ( ! V_47 ) ;
F_10 ( V_79 -> V_71 || V_79 -> V_38 ) ;
F_10 ( F_124 () ) ;
F_115 ( V_79 , V_47 -> V_53 , V_38 ,
V_255 , V_275 , V_256 , V_273 ) ;
F_127 ( V_38 , V_79 , ( V_62 & V_277 ) ) ;
if ( V_62 & V_278 )
V_79 -> V_109 |= V_279 ;
if ( F_128 ( V_79 , V_274 ) < 0 ) {
F_129 ( V_79 ,
V_79 -> V_125 , 0 ) ;
F_130 ( V_38 , V_79 ) ;
return;
}
V_276 = F_119 ( V_79 , V_242 ) ;
if ( V_276 != 0 ) {
F_70 ( V_79 ) ;
return;
}
F_122 ( V_79 ) ;
return;
}
static void F_131 ( struct V_127 * V_128 )
{
struct V_79 * V_79 = F_35 ( V_128 , struct V_79 , V_128 ) ;
V_79 -> V_280 -> V_281 = V_282 ;
V_79 -> V_71 -> V_283 ( V_79 ) ;
F_132 ( V_79 , 0 ) ;
}
int F_133 ( struct V_79 * V_79 , struct V_2 * V_38 ,
unsigned char * V_273 , T_1 V_274 ,
void * V_284 , unsigned char V_285 ,
T_4 V_286 , unsigned int V_287 , int V_62 )
{
struct V_46 * V_47 ;
int V_36 ;
V_47 = V_38 -> V_47 ;
F_10 ( ! V_47 ) ;
F_115 ( V_79 , V_47 -> V_53 , V_38 ,
0 , V_162 , V_288 , V_273 ) ;
V_36 = F_134 ( V_79 , V_284 , V_285 , V_286 ) ;
if ( V_36 < 0 )
return - V_25 ;
if ( V_285 == V_289 )
V_79 -> V_280 -> V_290 = V_287 ;
F_127 ( V_38 , V_79 , ( V_62 & V_277 ) ) ;
V_36 = F_135 ( V_79 , V_274 ) ;
if ( V_36 ) {
F_72 ( & V_79 -> V_128 , F_131 ) ;
F_136 ( & V_79 -> V_128 ) ;
return 0 ;
}
F_137 ( V_79 ) ;
return 0 ;
}
int F_138 (
struct V_79 * V_80 )
{
if ( ! V_80 -> V_102 ) {
F_123 () ;
F_4 ( L_106 ) ;
return - V_189 ;
}
F_60 ( V_80 , V_291 , false ) ;
return 0 ;
}
int F_139 (
struct V_79 * V_80 )
{
if ( ! F_124 () && F_140 ( V_292 ) )
return - V_293 ;
if ( F_141 ( V_80 , 1 ) != 0 )
return 0 ;
F_60 ( V_80 , V_294 , false ) ;
return 0 ;
}
int F_137 (
struct V_79 * V_80 )
{
F_60 ( V_80 , V_295 , false ) ;
return 0 ;
}
bool F_142 ( struct V_84 * V_85 , unsigned long * V_62 )
{
struct V_79 * V_80 = V_85 -> V_124 ;
bool V_296 = false ;
if ( V_85 -> V_86 & V_87 ) {
V_85 -> V_86 |= V_134 ;
F_33 ( & V_80 -> V_95 , * V_62 ) ;
F_30 ( L_109 , V_85 ) ;
F_143 ( & V_85 -> V_135 ) ;
F_30 ( L_110 , V_85 ) ;
F_32 ( & V_80 -> V_95 , * V_62 ) ;
F_52 ( & V_80 -> V_137 ) ;
V_85 -> V_86 &= ~ ( V_87 | V_134 ) ;
V_296 = true ;
}
return V_296 ;
}
static int F_144 ( struct V_79 * V_80 )
{
struct V_84 * V_85 , * V_297 ;
unsigned long V_62 ;
int V_36 = 0 ;
F_30 ( L_111 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_85 (task, task_tmp,
&cmd->t_task_list, t_list) {
F_30 ( L_112 , V_85 ) ;
if ( ! ( V_85 -> V_86 & ( V_87 | V_298 ) ) ) {
F_33 ( & V_80 -> V_95 ,
V_62 ) ;
F_80 ( V_85 ,
V_80 -> V_83 ) ;
F_30 ( L_113 , V_85 ) ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
continue;
}
if ( ! F_142 ( V_85 , & V_62 ) ) {
F_30 ( L_114 , V_85 ) ;
V_36 ++ ;
}
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
return V_36 ;
}
void F_70 ( struct V_79 * V_80 )
{
int V_36 = 0 ;
F_30 ( L_115
L_116 , V_80 , V_80 -> V_71 -> V_90 ( V_80 ) ,
V_80 -> V_149 [ 0 ] ) ;
F_30 ( L_117 ,
V_80 -> V_71 -> V_299 ( V_80 ) ,
V_80 -> V_94 , V_80 -> V_125 ) ;
F_30 ( L_118
L_119
L_120 ,
V_80 -> V_300 ,
F_89 ( & V_80 -> V_137 ) ,
F_89 ( & V_80 -> V_301 ) ,
F_89 ( & V_80 -> V_92 ) ,
( V_80 -> V_96 & V_99 ) != 0 ,
( V_80 -> V_96 & V_101 ) != 0 ,
( V_80 -> V_96 & V_302 ) != 0 ) ;
if ( V_80 -> V_83 -> V_143 == V_144 )
F_145 ( V_80 ) ;
switch ( V_80 -> V_125 ) {
case V_303 :
case V_304 :
case V_266 :
case V_305 :
case V_126 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
break;
case V_311 :
V_80 -> V_119 = V_312 ;
if ( V_80 -> V_38 &&
V_80 -> V_83 -> V_175 -> V_176 . V_313 == 2 )
F_146 ( V_80 -> V_38 -> V_48 ,
V_80 -> V_314 , 0x2C ,
V_315 ) ;
V_36 = V_80 -> V_71 -> V_316 ( V_80 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
goto V_319;
default:
F_4 ( L_121 ,
V_80 -> V_149 [ 0 ] , V_80 -> V_125 ) ;
V_80 -> V_125 = V_304 ;
break;
}
V_36 = F_129 ( V_80 ,
V_80 -> V_125 , 0 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
V_319:
F_55 ( V_80 ) ;
if ( ! F_54 ( V_80 ) )
;
return;
V_318:
V_80 -> V_94 = V_159 ;
F_147 ( V_80 , V_80 -> V_83 ) ;
}
static inline T_1 F_148 ( unsigned char * V_242 )
{
return ( ( V_242 [ 1 ] & 0x1f ) << 16 ) | ( V_242 [ 2 ] << 8 ) | V_242 [ 3 ] ;
}
static inline T_1 F_149 ( unsigned char * V_242 )
{
return ( V_242 [ 2 ] << 24 ) | ( V_242 [ 3 ] << 16 ) | ( V_242 [ 4 ] << 8 ) | V_242 [ 5 ] ;
}
static inline unsigned long long F_150 ( unsigned char * V_242 )
{
unsigned int V_320 , V_321 ;
V_320 = ( V_242 [ 2 ] << 24 ) | ( V_242 [ 3 ] << 16 ) | ( V_242 [ 4 ] << 8 ) | V_242 [ 5 ] ;
V_321 = ( V_242 [ 6 ] << 24 ) | ( V_242 [ 7 ] << 16 ) | ( V_242 [ 8 ] << 8 ) | V_242 [ 9 ] ;
return ( ( unsigned long long ) V_321 ) | ( unsigned long long ) V_320 << 32 ;
}
static inline unsigned long long F_151 ( unsigned char * V_242 )
{
unsigned int V_320 , V_321 ;
V_320 = ( V_242 [ 12 ] << 24 ) | ( V_242 [ 13 ] << 16 ) | ( V_242 [ 14 ] << 8 ) | V_242 [ 15 ] ;
V_321 = ( V_242 [ 16 ] << 24 ) | ( V_242 [ 17 ] << 16 ) | ( V_242 [ 18 ] << 8 ) | V_242 [ 19 ] ;
return ( ( unsigned long long ) V_321 ) | ( unsigned long long ) V_320 << 32 ;
}
static void F_152 ( struct V_79 * V_79 )
{
unsigned long V_62 ;
F_32 ( & V_79 -> V_95 , V_62 ) ;
V_79 -> V_109 |= V_322 ;
F_33 ( & V_79 -> V_95 , V_62 ) ;
}
static inline int F_153 ( struct V_79 * V_80 )
{
if ( V_80 -> V_83 -> V_143 != V_144 )
return 1 ;
if ( V_80 -> V_147 == V_148 ) {
F_30 ( L_122
L_123 ,
V_80 -> V_149 [ 0 ] ,
V_80 -> V_263 ) ;
return 1 ;
} else if ( V_80 -> V_147 == V_323 ) {
F_61 ( & V_80 -> V_83 -> V_324 ) ;
F_118 () ;
F_30 ( L_124
L_125 ,
V_80 -> V_149 [ 0 ] ,
V_80 -> V_263 ) ;
if ( ! F_89 ( & V_80 -> V_83 -> V_325 ) )
return 1 ;
} else {
F_61 ( & V_80 -> V_83 -> V_325 ) ;
F_118 () ;
}
if ( F_89 ( & V_80 -> V_83 -> V_324 ) != 0 ) {
F_11 ( & V_80 -> V_83 -> V_225 ) ;
V_80 -> V_109 |= V_326 ;
F_28 ( & V_80 -> V_258 ,
& V_80 -> V_83 -> V_224 ) ;
F_12 ( & V_80 -> V_83 -> V_225 ) ;
F_30 ( L_126
L_127 ,
V_80 -> V_149 [ 0 ] , V_80 -> V_147 ,
V_80 -> V_263 ) ;
return 0 ;
}
return 1 ;
}
static int F_154 ( struct V_79 * V_80 )
{
int V_327 ;
struct V_81 * V_83 = V_80 -> V_83 ;
if ( ! F_53 ( V_80 , 0 , V_328 ) ) {
V_327 = F_153 ( V_80 ) ;
if ( ! V_327 )
goto V_151;
F_155 ( V_83 , V_80 ) ;
return 0 ;
}
V_151:
F_155 ( V_83 , NULL ) ;
return 0 ;
}
static int F_155 ( struct V_81 * V_82 , struct V_79 * V_329 )
{
int error ;
struct V_79 * V_80 = NULL ;
struct V_84 * V_85 = NULL ;
unsigned long V_62 ;
V_330:
F_27 ( & V_82 -> V_88 ) ;
if ( V_329 != NULL )
F_77 ( V_329 ) ;
if ( F_44 ( & V_82 -> V_146 ) ) {
F_29 ( & V_82 -> V_88 ) ;
return 0 ;
}
V_85 = F_65 ( & V_82 -> V_146 ,
struct V_84 , V_145 ) ;
F_79 ( V_85 , V_82 ) ;
F_29 ( & V_82 -> V_88 ) ;
V_80 = V_85 -> V_124 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
V_85 -> V_86 |= ( V_87 | V_298 ) ;
F_61 ( & V_80 -> V_301 ) ;
if ( F_89 ( & V_80 -> V_301 ) ==
V_80 -> V_300 )
V_80 -> V_96 |= V_302 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_331 )
error = V_80 -> V_331 ( V_85 ) ;
else
error = V_82 -> V_130 -> V_332 ( V_85 ) ;
if ( error != 0 ) {
F_32 ( & V_80 -> V_95 , V_62 ) ;
V_85 -> V_86 &= ~ V_87 ;
V_80 -> V_96 &= ~ V_302 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_144 ( V_80 ) ;
F_70 ( V_80 ) ;
}
V_329 = NULL ;
goto V_330;
return 0 ;
}
static inline T_1 F_156 (
unsigned char * V_242 ,
struct V_79 * V_80 ,
int * V_36 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
if ( ! V_82 )
goto V_333;
if ( V_82 -> V_130 -> V_207 ( V_82 ) == V_334 )
return ( T_1 ) ( V_242 [ 2 ] << 16 ) + ( V_242 [ 3 ] << 8 ) + V_242 [ 4 ] ;
V_333:
return V_242 [ 4 ] ? : 256 ;
}
static inline T_1 F_157 (
unsigned char * V_242 ,
struct V_79 * V_80 ,
int * V_36 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
if ( ! V_82 )
goto V_333;
if ( V_82 -> V_130 -> V_207 ( V_82 ) == V_334 ) {
* V_36 = - V_189 ;
return 0 ;
}
V_333:
return ( T_1 ) ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
}
static inline T_1 F_158 (
unsigned char * V_242 ,
struct V_79 * V_80 ,
int * V_36 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
if ( ! V_82 )
goto V_333;
if ( V_82 -> V_130 -> V_207 ( V_82 ) == V_334 ) {
* V_36 = - V_189 ;
return 0 ;
}
V_333:
return ( T_1 ) ( V_242 [ 6 ] << 24 ) + ( V_242 [ 7 ] << 16 ) + ( V_242 [ 8 ] << 8 ) + V_242 [ 9 ] ;
}
static inline T_1 F_159 (
unsigned char * V_242 ,
struct V_79 * V_80 ,
int * V_36 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
if ( ! V_82 )
goto V_333;
if ( V_82 -> V_130 -> V_207 ( V_82 ) == V_334 )
return ( T_1 ) ( V_242 [ 12 ] << 16 ) + ( V_242 [ 13 ] << 8 ) + V_242 [ 14 ] ;
V_333:
return ( T_1 ) ( V_242 [ 10 ] << 24 ) + ( V_242 [ 11 ] << 16 ) +
( V_242 [ 12 ] << 8 ) + V_242 [ 13 ] ;
}
static inline T_1 F_160 (
unsigned char * V_242 ,
struct V_79 * V_80 ,
int * V_36 )
{
return ( T_1 ) ( V_242 [ 28 ] << 24 ) + ( V_242 [ 29 ] << 16 ) +
( V_242 [ 30 ] << 8 ) + V_242 [ 31 ] ;
}
static inline T_1 F_161 (
T_1 V_335 ,
unsigned char * V_242 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
if ( V_82 -> V_130 -> V_207 ( V_82 ) == V_334 ) {
if ( V_242 [ 1 ] & 1 ) {
return V_82 -> V_175 -> V_176 . V_177 * V_335 ;
} else
return V_335 ;
}
#if 0
pr_debug("Returning block_size: %u, sectors: %u == %u for"
" %s object\n", dev->se_sub_dev->se_dev_attrib.block_size, sectors,
dev->se_sub_dev->se_dev_attrib.block_size * sectors,
dev->transport->name);
#endif
return V_82 -> V_175 -> V_176 . V_177 * V_335 ;
}
static void F_162 ( struct V_79 * V_80 )
{
unsigned char * V_51 , * V_336 ;
struct V_337 * V_338 ;
unsigned int V_339 ;
int V_195 ;
int V_340 ;
V_51 = F_163 ( V_80 -> V_255 , V_39 ) ;
if ( ! V_51 ) {
F_4 ( L_128 ) ;
return;
}
F_164 ( V_80 -> V_341 ,
V_80 -> V_342 ,
V_51 ,
V_80 -> V_255 ) ;
V_339 = 0 ;
F_165 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_336 = F_166 ( F_167 ( V_338 ) ) ;
if ( ! V_336 )
goto V_3;
for ( V_195 = 0 ; V_195 < V_338 -> V_343 ; V_195 ++ )
* ( V_336 + V_338 -> V_339 + V_195 ) ^= * ( V_51 + V_339 + V_195 ) ;
V_339 += V_338 -> V_343 ;
F_168 ( V_336 ) ;
}
V_3:
F_111 ( V_51 ) ;
}
static int F_169 ( struct V_79 * V_80 )
{
unsigned char * V_344 = V_80 -> V_257 , * V_257 = NULL ;
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_84 * V_85 = NULL , * V_297 ;
unsigned long V_62 ;
T_1 V_339 = 0 ;
F_81 ( ! V_80 -> V_102 ) ;
if ( ! V_82 )
return 0 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_109 & V_345 ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return 0 ;
}
F_85 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! ( V_85 -> V_86 & V_133 ) )
continue;
if ( ! V_82 -> V_130 -> V_346 ) {
F_4 ( L_129
L_130 ) ;
continue;
}
V_257 = V_82 -> V_130 -> V_346 ( V_85 ) ;
if ( ! V_257 ) {
F_4 ( L_131
L_132 ,
V_80 -> V_71 -> V_90 ( V_80 ) , V_85 ) ;
continue;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
V_339 = V_80 -> V_71 -> V_347 ( V_80 ,
V_348 ) ;
memcpy ( & V_344 [ V_339 ] , V_257 ,
V_348 ) ;
V_80 -> V_119 = V_85 -> V_121 ;
V_80 -> V_349 =
( V_348 + V_339 ) ;
F_30 ( L_133
L_134 ,
V_82 -> V_208 -> V_350 , V_82 -> V_130 -> V_199 ,
V_80 -> V_119 ) ;
return 0 ;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
return - 1 ;
}
static inline long long F_170 ( struct V_81 * V_82 )
{
return V_82 -> V_130 -> V_351 ( V_82 ) + 1 ;
}
static int F_171 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
T_1 V_335 ;
if ( V_82 -> V_130 -> V_207 ( V_82 ) != V_352 )
return 0 ;
V_335 = ( V_80 -> V_255 / V_82 -> V_175 -> V_176 . V_177 ) ;
if ( ( V_80 -> V_353 + V_335 ) > F_170 ( V_82 ) ) {
F_4 ( L_135
L_136 ,
V_80 -> V_353 , V_335 ,
F_170 ( V_82 ) ) ;
return - V_189 ;
}
return 0 ;
}
static int F_172 ( unsigned char * V_62 , struct V_81 * V_82 )
{
int V_354 = ( V_82 -> V_130 -> V_196 ==
V_197 ) ;
if ( ! V_354 ) {
if ( ( V_62 [ 0 ] & 0x04 ) || ( V_62 [ 0 ] & 0x02 ) ) {
F_4 ( L_137
L_138
L_139 ) ;
return - V_355 ;
}
if ( ! ( V_62 [ 0 ] & 0x08 ) ) {
F_4 ( L_140
L_141 ) ;
return - V_355 ;
}
}
return 0 ;
}
static int F_121 (
struct V_79 * V_80 ,
unsigned char * V_242 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_211 * V_356 = V_82 -> V_175 ;
int V_36 = 0 , V_357 = 0 , V_354 ;
T_1 V_335 = 0 , V_358 = 0 , V_359 = 0 ;
T_5 V_360 ;
T_3 V_361 = 0 ;
if ( F_173 ( V_80 , V_242 ) < 0 ) {
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_309 ;
return - V_189 ;
}
V_36 = V_356 -> V_362 . V_363 ( V_80 , V_242 , & V_361 ) ;
if ( V_36 != 0 ) {
if ( V_36 > 0 ) {
#if 0
pr_debug("[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
#endif
F_174 ( V_80 , 0x04 , V_361 ) ;
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_310 ;
return - V_189 ;
}
goto V_364;
}
if ( V_356 -> V_365 . V_366 . V_367 ( V_80 , & V_359 ) != 0 ) {
if ( V_356 -> V_365 . V_366 . V_368 (
V_80 , V_242 , V_359 ) != 0 ) {
V_80 -> V_109 |= V_265 ;
V_80 -> V_109 |= V_369 ;
V_80 -> V_119 = V_312 ;
V_80 -> V_125 = V_311 ;
return - V_370 ;
}
}
V_354 =
( V_82 -> V_130 -> V_196 == V_197 ) ;
switch ( V_242 [ 0 ] ) {
case V_371 :
V_335 = F_156 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_148 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
break;
case V_243 :
V_335 = F_157 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_149 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
break;
case V_244 :
V_335 = F_158 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_149 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
break;
case V_245 :
V_335 = F_159 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_150 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
break;
case V_374 :
V_335 = F_156 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_148 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
break;
case V_375 :
V_335 = F_157 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_149 ( V_242 ) ;
if ( V_242 [ 1 ] & 0x8 )
V_80 -> V_109 |= V_376 ;
V_80 -> V_109 |= V_373 ;
break;
case V_377 :
V_335 = F_158 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_149 ( V_242 ) ;
if ( V_242 [ 1 ] & 0x8 )
V_80 -> V_109 |= V_376 ;
V_80 -> V_109 |= V_373 ;
break;
case V_378 :
V_335 = F_159 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_150 ( V_242 ) ;
if ( V_242 [ 1 ] & 0x8 )
V_80 -> V_109 |= V_376 ;
V_80 -> V_109 |= V_373 ;
break;
case V_379 :
if ( ( V_80 -> V_161 != V_164 ) ||
! ( V_80 -> V_109 & V_279 ) )
goto V_364;
V_335 = F_157 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_149 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
if ( V_354 )
goto V_372;
V_80 -> V_380 = & F_162 ;
if ( V_242 [ 1 ] & 0x8 )
V_80 -> V_109 |= V_376 ;
break;
case V_381 :
V_360 = F_175 ( & V_242 [ 8 ] ) ;
switch ( V_360 ) {
case V_382 :
V_335 = F_160 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_353 = F_151 ( V_242 ) ;
V_80 -> V_109 |= V_373 ;
if ( V_354 )
goto V_372;
V_80 -> V_380 = & F_162 ;
if ( V_242 [ 1 ] & 0x8 )
V_80 -> V_109 |= V_376 ;
break;
case V_383 :
V_335 = F_160 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
if ( V_335 )
V_358 = F_161 ( 1 , V_242 , V_80 ) ;
else {
F_4 ( L_142
L_143 ) ;
goto V_364;
}
V_80 -> V_353 = F_25 ( & V_242 [ 12 ] ) ;
V_80 -> V_109 |= V_384 ;
if ( F_172 ( & V_242 [ 10 ] , V_82 ) < 0 )
goto V_372;
if ( ! V_354 )
V_80 -> V_331 = V_385 ;
break;
default:
F_4 ( L_144
L_145 , V_360 ) ;
goto V_372;
}
break;
case V_386 :
if ( V_82 -> V_130 -> V_207 ( V_82 ) != V_387 ) {
if ( V_242 [ 1 ] == V_388 &&
V_356 -> V_362 . V_389 == V_390 ) {
V_80 -> V_331 =
V_391 ;
}
V_358 = ( V_242 [ 6 ] << 24 ) | ( V_242 [ 7 ] << 16 ) |
( V_242 [ 8 ] << 8 ) | V_242 [ 9 ] ;
} else {
V_358 = ( V_242 [ 8 ] << 8 ) + V_242 [ 9 ] ;
}
V_80 -> V_109 |= V_384 ;
break;
case V_392 :
V_358 = V_242 [ 4 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_393 :
V_358 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_394 :
V_358 = V_242 [ 4 ] ;
V_80 -> V_109 |= V_384 ;
if ( ! V_354 )
V_80 -> V_331 = V_395 ;
break;
case V_396 :
V_358 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
if ( ! V_354 )
V_80 -> V_331 = V_395 ;
break;
case V_397 :
case V_398 :
case V_399 :
case V_400 :
V_358 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_401 :
V_358 = V_402 ;
V_80 -> V_109 |= V_384 ;
break;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
V_358 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_407 :
if ( V_356 -> V_365 . V_408 == V_409 )
V_80 -> V_331 = V_410 ;
V_358 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_411 :
if ( V_356 -> V_365 . V_408 == V_409 )
V_80 -> V_331 = V_412 ;
V_358 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_413 :
case V_414 :
V_358 = ( V_242 [ 8 ] << 8 ) + V_242 [ 9 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_415 :
V_358 = V_416 ;
V_80 -> V_109 |= V_384 ;
break;
case V_417 :
if ( V_82 -> V_130 -> V_207 ( V_82 ) != V_387 ) {
if ( V_242 [ 1 ] == V_418 &&
V_356 -> V_362 . V_389 == V_390 ) {
V_80 -> V_331 =
V_419 ;
}
V_358 = ( V_242 [ 6 ] << 24 ) | ( V_242 [ 7 ] << 16 ) |
( V_242 [ 8 ] << 8 ) | V_242 [ 9 ] ;
} else {
V_358 = ( V_242 [ 8 ] << 8 ) + V_242 [ 9 ] ;
}
V_80 -> V_109 |= V_384 ;
break;
case V_420 :
V_358 = ( V_242 [ 3 ] << 8 ) + V_242 [ 4 ] ;
if ( V_80 -> V_83 -> V_143 == V_144 )
V_80 -> V_147 = V_148 ;
V_80 -> V_109 |= V_384 ;
if ( ! V_354 )
V_80 -> V_331 = V_421 ;
break;
case V_422 :
V_358 = ( V_242 [ 6 ] << 16 ) + ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_423 :
V_358 = V_424 ;
V_80 -> V_109 |= V_384 ;
if ( ! V_354 )
V_80 -> V_331 = V_425 ;
break;
case V_426 :
case V_427 :
case V_428 :
V_358 = ( V_242 [ 6 ] << 24 ) | ( V_242 [ 7 ] << 16 ) | ( V_242 [ 8 ] << 8 ) | V_242 [ 9 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_429 :
switch ( V_80 -> V_149 [ 1 ] & 0x1f ) {
case V_430 :
if ( ! V_354 )
V_80 -> V_331 =
V_431 ;
break;
default:
if ( V_354 )
break;
F_4 ( L_146 ,
V_80 -> V_149 [ 1 ] & 0x1f ) ;
goto V_364;
}
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
case V_437 :
V_358 = ( V_242 [ 10 ] << 24 ) | ( V_242 [ 11 ] << 16 ) |
( V_242 [ 12 ] << 8 ) | V_242 [ 13 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_438 :
case V_246 :
V_358 = ( V_242 [ 3 ] << 8 ) | V_242 [ 4 ] ;
V_80 -> V_109 |= V_384 ;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#endif
case V_439 :
V_358 = V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_440 :
V_358 = V_242 [ 4 ] ;
V_80 -> V_109 |= V_384 ;
if ( ! V_354 )
V_80 -> V_331 = V_441 ;
break;
case V_442 :
V_358 = 65536 * V_242 [ 7 ] + 256 * V_242 [ 8 ] + V_242 [ 9 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_443 :
V_358 = ( V_242 [ 6 ] << 16 ) + ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_80 -> V_109 |= V_384 ;
break;
case V_444 :
case V_445 :
if ( V_242 [ 0 ] == V_445 )
V_358 = ( V_242 [ 7 ] << 8 ) | V_242 [ 8 ] ;
else
V_358 = V_80 -> V_255 ;
if ( V_356 -> V_365 . V_408 != V_446 )
V_80 -> V_331 = V_447 ;
V_80 -> V_109 |= V_448 ;
break;
case V_449 :
case V_450 :
if ( V_242 [ 0 ] == V_450 )
V_358 = ( V_242 [ 7 ] << 8 ) | V_242 [ 8 ] ;
else
V_358 = V_80 -> V_255 ;
if ( V_356 -> V_365 . V_408 != V_446 )
V_80 -> V_331 = V_451 ;
V_80 -> V_109 |= V_448 ;
break;
case V_452 :
case V_453 :
if ( V_242 [ 0 ] == V_452 ) {
V_335 = F_157 ( V_242 , V_80 , & V_357 ) ;
V_80 -> V_353 = F_149 ( V_242 ) ;
} else {
V_335 = F_159 ( V_242 , V_80 , & V_357 ) ;
V_80 -> V_353 = F_150 ( V_242 ) ;
}
if ( V_357 )
goto V_372;
V_358 = F_161 ( V_335 , V_242 , V_80 ) ;
V_80 -> V_109 |= V_448 ;
if ( V_354 )
break;
if ( ( V_80 -> V_353 != 0 ) || ( V_335 != 0 ) ) {
if ( F_171 ( V_80 ) < 0 )
goto V_364;
}
V_80 -> V_331 = V_454 ;
break;
case V_455 :
V_358 = F_175 ( & V_242 [ 7 ] ) ;
V_80 -> V_109 |= V_384 ;
if ( ! V_354 )
V_80 -> V_331 = V_456 ;
break;
case V_457 :
V_335 = F_159 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
if ( V_335 )
V_358 = F_161 ( 1 , V_242 , V_80 ) ;
else {
F_4 ( L_147 ) ;
goto V_364;
}
V_80 -> V_353 = F_25 ( & V_242 [ 2 ] ) ;
V_80 -> V_109 |= V_384 ;
if ( F_172 ( & V_242 [ 1 ] , V_82 ) < 0 )
goto V_372;
if ( ! V_354 )
V_80 -> V_331 = V_385 ;
break;
case V_458 :
V_335 = F_157 ( V_242 , V_80 , & V_357 ) ;
if ( V_357 )
goto V_372;
if ( V_335 )
V_358 = F_161 ( 1 , V_242 , V_80 ) ;
else {
F_4 ( L_147 ) ;
goto V_364;
}
V_80 -> V_353 = F_176 ( & V_242 [ 2 ] ) ;
V_80 -> V_109 |= V_384 ;
if ( F_172 ( & V_242 [ 1 ] , V_82 ) < 0 )
goto V_372;
if ( ! V_354 )
V_80 -> V_331 = V_385 ;
break;
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_465 :
case V_247 :
case V_466 :
V_80 -> V_109 |= V_448 ;
if ( ! V_354 )
V_80 -> V_331 = V_467 ;
break;
case V_468 :
case V_469 :
case V_470 :
case V_471 :
case V_472 :
V_80 -> V_109 |= V_448 ;
break;
case V_473 :
V_80 -> V_331 = V_474 ;
V_358 = ( V_242 [ 6 ] << 24 ) | ( V_242 [ 7 ] << 16 ) | ( V_242 [ 8 ] << 8 ) | V_242 [ 9 ] ;
if ( V_80 -> V_83 -> V_143 == V_144 )
V_80 -> V_147 = V_148 ;
V_80 -> V_109 |= V_384 ;
break;
default:
F_177 ( L_148
L_149 ,
V_80 -> V_71 -> V_61 () , V_242 [ 0 ] ) ;
goto V_372;
}
if ( V_358 != V_80 -> V_255 ) {
F_177 ( L_150
L_151
L_152 , V_80 -> V_71 -> V_61 () ,
V_80 -> V_255 , V_358 , V_242 [ 0 ] ) ;
V_80 -> V_475 = V_358 ;
if ( V_80 -> V_161 == V_164 ) {
F_4 ( L_153
L_154 ) ;
goto V_364;
}
if ( ! V_36 && ( V_82 -> V_175 -> V_176 . V_177 != 512 ) ) {
F_4 ( L_155
L_156
L_157 , V_82 -> V_130 -> V_199 ) ;
goto V_364;
}
if ( V_358 > V_80 -> V_255 ) {
V_80 -> V_109 |= V_476 ;
V_80 -> V_477 = ( V_358 - V_80 -> V_255 ) ;
} else {
V_80 -> V_109 |= V_478 ;
V_80 -> V_477 = ( V_80 -> V_255 - V_358 ) ;
}
V_80 -> V_255 = V_358 ;
}
if ( V_80 -> V_109 & V_373 &&
V_335 > V_82 -> V_175 -> V_176 . V_479 ) {
F_178 ( V_480 L_158 ,
V_242 [ 0 ] , V_335 ) ;
goto V_364;
}
if ( ! ( V_354 || V_80 -> V_331 ||
( V_80 -> V_109 & V_373 ) ) )
goto V_372;
F_152 ( V_80 ) ;
return V_36 ;
V_372:
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_304 ;
return - V_189 ;
V_364:
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_266 ;
return - V_189 ;
}
static void F_145 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_79 * V_481 , * V_155 ;
int V_482 = 0 ;
if ( V_80 -> V_147 == V_288 ) {
F_52 ( & V_82 -> V_325 ) ;
F_86 () ;
V_82 -> V_483 ++ ;
F_30 ( L_159
L_160 , V_82 -> V_483 ,
V_80 -> V_263 ) ;
} else if ( V_80 -> V_147 == V_148 ) {
V_82 -> V_483 ++ ;
F_30 ( L_161
L_162 , V_82 -> V_483 ,
V_80 -> V_263 ) ;
} else if ( V_80 -> V_147 == V_323 ) {
F_52 ( & V_82 -> V_324 ) ;
F_86 () ;
V_82 -> V_483 ++ ;
F_30 ( L_163
L_164 , V_82 -> V_483 , V_80 -> V_263 ) ;
}
F_11 ( & V_82 -> V_225 ) ;
F_85 (cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_node) {
F_43 ( & V_481 -> V_258 ) ;
F_12 ( & V_82 -> V_225 ) ;
F_30 ( L_165
L_166
L_167 ,
V_481 -> V_149 [ 0 ] ,
V_481 -> V_147 , V_481 -> V_263 ) ;
F_78 ( V_481 ) ;
V_482 ++ ;
F_11 ( & V_82 -> V_225 ) ;
if ( V_481 -> V_147 == V_323 )
break;
}
F_12 ( & V_82 -> V_225 ) ;
if ( V_482 != 0 )
F_63 ( & V_82 -> V_112 . V_34 ) ;
}
static void F_179 ( struct V_79 * V_80 )
{
int V_36 = 0 ;
if ( V_80 -> V_83 -> V_143 == V_144 )
F_145 ( V_80 ) ;
if ( V_80 -> V_109 & V_132 ) {
V_36 = V_80 -> V_71 -> V_316 ( V_80 ) ;
if ( V_36 )
goto V_3;
}
switch ( V_80 -> V_161 ) {
case V_163 :
V_36 = V_80 -> V_71 -> V_484 ( V_80 ) ;
break;
case V_164 :
if ( V_80 -> V_485 ) {
V_36 = V_80 -> V_71 -> V_484 ( V_80 ) ;
if ( V_36 < 0 )
break;
}
case V_162 :
V_36 = V_80 -> V_71 -> V_316 ( V_80 ) ;
break;
default:
break;
}
V_3:
if ( V_36 < 0 ) {
F_147 ( V_80 , V_80 -> V_83 ) ;
return;
}
F_55 ( V_80 ) ;
F_54 ( V_80 ) ;
}
static void F_147 (
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
F_27 ( & V_82 -> V_156 ) ;
F_28 ( & V_80 -> V_157 , & V_80 -> V_83 -> V_154 ) ;
F_61 ( & V_82 -> V_158 ) ;
F_118 () ;
F_29 ( & V_80 -> V_83 -> V_156 ) ;
F_136 ( & V_80 -> V_83 -> V_153 ) ;
}
static void V_139 ( struct V_127 * V_128 )
{
struct V_79 * V_80 = F_35 ( V_128 , struct V_79 , V_128 ) ;
int V_486 = 0 , V_36 ;
if ( V_80 -> V_83 -> V_143 == V_144 )
F_145 ( V_80 ) ;
if ( F_89 ( & V_80 -> V_83 -> V_158 ) != 0 )
F_136 ( & V_80 -> V_83 -> V_153 ) ;
if ( V_80 -> V_109 & V_132 ) {
if ( F_169 ( V_80 ) < 0 )
V_486 = V_303 ;
if ( V_80 -> V_119 ) {
V_36 = F_129 (
V_80 , V_486 , 1 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
F_55 ( V_80 ) ;
F_54 ( V_80 ) ;
return;
}
}
if ( V_80 -> V_380 )
V_80 -> V_380 ( V_80 ) ;
switch ( V_80 -> V_161 ) {
case V_163 :
F_11 ( & V_80 -> V_102 -> V_268 ) ;
if ( V_80 -> V_102 -> V_269 ) {
V_80 -> V_102 -> V_269 -> V_270 . V_487 +=
V_80 -> V_255 ;
}
F_12 ( & V_80 -> V_102 -> V_268 ) ;
V_36 = V_80 -> V_71 -> V_484 ( V_80 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
break;
case V_164 :
F_11 ( & V_80 -> V_102 -> V_268 ) ;
if ( V_80 -> V_102 -> V_269 ) {
V_80 -> V_102 -> V_269 -> V_270 . V_488 +=
V_80 -> V_255 ;
}
F_12 ( & V_80 -> V_102 -> V_268 ) ;
if ( V_80 -> V_485 ) {
F_11 ( & V_80 -> V_102 -> V_268 ) ;
if ( V_80 -> V_102 -> V_269 ) {
V_80 -> V_102 -> V_269 -> V_270 . V_487 +=
V_80 -> V_255 ;
}
F_12 ( & V_80 -> V_102 -> V_268 ) ;
V_36 = V_80 -> V_71 -> V_484 ( V_80 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
break;
}
case V_162 :
V_36 = V_80 -> V_71 -> V_316 ( V_80 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
break;
default:
break;
}
F_55 ( V_80 ) ;
F_54 ( V_80 ) ;
return;
V_318:
F_30 ( L_168
L_169 , V_80 , V_80 -> V_161 ) ;
V_80 -> V_94 = V_159 ;
F_147 ( V_80 , V_80 -> V_83 ) ;
}
static void F_180 ( struct V_79 * V_80 )
{
struct V_84 * V_85 , * V_297 ;
unsigned long V_62 ;
F_83 ( V_489 ) ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_85 (task, task_tmp,
&cmd->t_task_list, t_list) {
if ( ! ( V_85 -> V_86 & V_87 ) )
F_181 ( & V_85 -> V_118 , & V_489 ) ;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
while ( ! F_44 ( & V_489 ) ) {
V_85 = F_65 ( & V_489 , struct V_84 , V_118 ) ;
if ( V_85 -> V_490 != V_80 -> V_341 &&
V_85 -> V_490 != V_80 -> V_485 )
F_111 ( V_85 -> V_490 ) ;
F_43 ( & V_85 -> V_118 ) ;
V_80 -> V_83 -> V_130 -> V_491 ( V_85 ) ;
}
}
static inline void F_182 ( struct V_337 * V_492 , int V_493 )
{
struct V_337 * V_338 ;
int V_340 ;
F_165 (sgl, sg, nents, count)
F_183 ( F_167 ( V_338 ) ) ;
F_111 ( V_492 ) ;
}
static inline void F_184 ( struct V_79 * V_80 )
{
if ( V_80 -> V_109 & V_494 )
return;
F_182 ( V_80 -> V_341 , V_80 -> V_342 ) ;
V_80 -> V_341 = NULL ;
V_80 -> V_342 = 0 ;
F_182 ( V_80 -> V_485 , V_80 -> V_495 ) ;
V_80 -> V_485 = NULL ;
V_80 -> V_495 = 0 ;
}
static void F_185 ( struct V_79 * V_80 )
{
F_10 ( ! V_80 -> V_71 ) ;
if ( V_80 -> V_109 & V_110 )
F_186 ( V_80 -> V_280 ) ;
if ( V_80 -> V_149 != V_80 -> V_267 )
F_111 ( V_80 -> V_149 ) ;
if ( V_80 -> V_496 != 0 ) {
F_130 ( V_80 -> V_38 , V_80 ) ;
return;
}
V_80 -> V_71 -> V_497 ( V_80 ) ;
}
static void F_59 ( struct V_79 * V_80 )
{
unsigned long V_62 ;
int V_498 = 0 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( F_89 ( & V_80 -> V_499 ) ) {
if ( ! F_71 ( & V_80 -> V_499 ) )
goto V_500;
}
if ( F_89 ( & V_80 -> V_501 ) ) {
if ( ! F_71 ( & V_80 -> V_501 ) )
goto V_500;
}
if ( V_80 -> V_96 & V_106 ) {
V_80 -> V_96 &= ~ V_106 ;
F_50 ( V_80 ) ;
V_498 = 1 ;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
if ( V_498 != 0 )
F_180 ( V_80 ) ;
F_184 ( V_80 ) ;
F_185 ( V_80 ) ;
return;
V_500:
F_33 ( & V_80 -> V_95 , V_62 ) ;
}
int F_187 (
struct V_79 * V_80 ,
struct V_337 * V_492 ,
T_1 V_502 ,
struct V_337 * V_503 ,
T_1 V_504 )
{
if ( ! V_492 || ! V_502 )
return 0 ;
if ( ( V_80 -> V_109 & V_373 ) ||
( V_80 -> V_109 & V_384 ) ) {
if ( V_80 -> V_109 & V_476 ) {
F_177 ( L_170
L_171 ) ;
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_266 ;
return - V_189 ;
}
V_80 -> V_341 = V_492 ;
V_80 -> V_342 = V_502 ;
if ( V_503 && V_504 ) {
V_80 -> V_485 = V_503 ;
V_80 -> V_495 = V_504 ;
}
V_80 -> V_109 |= V_494 ;
}
return 0 ;
}
void * F_188 ( struct V_79 * V_80 )
{
struct V_337 * V_338 = V_80 -> V_341 ;
struct V_505 * * V_506 ;
int V_195 ;
F_10 ( ! V_338 ) ;
if ( ! V_80 -> V_342 )
return NULL ;
else if ( V_80 -> V_342 == 1 )
return F_189 ( F_167 ( V_338 ) ) + V_338 -> V_339 ;
V_506 = F_163 ( sizeof( * V_506 ) * V_80 -> V_342 , V_39 ) ;
if ( ! V_506 )
return NULL ;
F_165 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_506 [ V_195 ] = F_167 ( V_338 ) ;
}
V_80 -> V_507 = F_190 ( V_506 , V_80 -> V_342 , V_508 , V_509 ) ;
F_111 ( V_506 ) ;
if ( ! V_80 -> V_507 )
return NULL ;
return V_80 -> V_507 + V_80 -> V_341 [ 0 ] . V_339 ;
}
void F_191 ( struct V_79 * V_80 )
{
if ( ! V_80 -> V_342 ) {
return;
} else if ( V_80 -> V_342 == 1 ) {
F_192 ( F_167 ( V_80 -> V_341 ) ) ;
return;
}
F_193 ( V_80 -> V_507 ) ;
V_80 -> V_507 = NULL ;
}
static int
F_194 ( struct V_79 * V_80 )
{
T_1 V_343 = V_80 -> V_255 ;
unsigned int V_493 ;
struct V_505 * V_505 ;
T_4 V_510 ;
int V_195 = 0 ;
V_493 = F_195 ( V_343 , V_511 ) ;
V_80 -> V_341 = F_163 ( sizeof( struct V_337 ) * V_493 , V_39 ) ;
if ( ! V_80 -> V_341 )
return - V_25 ;
V_80 -> V_342 = V_493 ;
F_196 ( V_80 -> V_341 , V_493 ) ;
V_510 = V_80 -> V_109 & V_373 ? 0 : V_512 ;
while ( V_343 ) {
T_1 V_513 = F_197 ( T_1 , V_343 , V_511 ) ;
V_505 = F_198 ( V_39 | V_510 ) ;
if ( ! V_505 )
goto V_3;
F_199 ( & V_80 -> V_341 [ V_195 ] , V_505 , V_513 , 0 ) ;
V_343 -= V_513 ;
V_195 ++ ;
}
return 0 ;
V_3:
while ( V_195 >= 0 ) {
F_183 ( F_167 ( & V_80 -> V_341 [ V_195 ] ) ) ;
V_195 -- ;
}
F_111 ( V_80 -> V_341 ) ;
V_80 -> V_341 = NULL ;
return - V_25 ;
}
static inline T_6 F_200 (
struct V_81 * V_82 ,
unsigned long long V_514 ,
T_6 V_335 )
{
V_335 = F_197 ( T_6 , V_335 , V_82 -> V_175 -> V_176 . V_178 ) ;
if ( V_82 -> V_130 -> V_207 ( V_82 ) == V_352 )
if ( ( V_514 + V_335 ) > F_170 ( V_82 ) )
V_335 = ( ( F_170 ( V_82 ) - V_514 ) + 1 ) ;
return V_335 ;
}
void F_201 ( struct V_79 * V_80 )
{
struct V_337 * V_515 = NULL ;
struct V_337 * V_516 = NULL ;
int V_517 = 0 ;
struct V_337 * V_338 ;
struct V_84 * V_85 ;
T_1 V_518 = 0 ;
int V_195 ;
F_10 ( ! V_80 -> V_71 -> V_519 ) ;
F_51 (task, &cmd->t_task_list, t_list) {
if ( ! V_85 -> V_490 )
continue;
if ( ! V_515 ) {
V_515 = V_85 -> V_490 ;
V_518 = V_85 -> V_520 ;
} else {
F_202 ( V_516 , V_517 , V_85 -> V_490 ) ;
V_518 += V_85 -> V_520 ;
}
V_517 = ( V_85 -> V_520 + 1 ) ;
V_516 = V_85 -> V_490 ;
}
V_80 -> V_521 = V_515 ;
V_80 -> V_522 = V_518 ;
F_30 ( L_172
L_173 , V_80 , V_80 -> V_521 ,
V_80 -> V_522 ) ;
F_165 (cmd->t_tasks_sg_chained, sg,
cmd->t_tasks_sg_chained_no, i) {
F_30 ( L_174 ,
V_195 , V_338 , F_167 ( V_338 ) , V_338 -> V_343 , V_338 -> V_339 ) ;
if ( F_203 ( V_338 ) )
F_30 ( L_175 , V_338 ) ;
if ( F_204 ( V_338 ) )
F_30 ( L_176 , V_338 ) ;
}
}
static int
F_205 ( struct V_79 * V_80 ,
enum V_251 V_161 ,
struct V_337 * V_523 , unsigned int V_524 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
int V_525 , V_195 ;
unsigned long long V_514 ;
T_6 V_335 , V_526 ;
T_1 V_527 ;
if ( F_171 ( V_80 ) < 0 )
return - V_189 ;
V_526 = V_82 -> V_175 -> V_176 . V_178 ;
V_527 = V_82 -> V_175 -> V_176 . V_177 ;
F_81 ( V_80 -> V_255 % V_527 ) ;
V_514 = V_80 -> V_353 ;
V_335 = F_195 ( V_80 -> V_255 , V_527 ) ;
V_525 = F_206 ( V_335 , V_526 ) ;
if ( V_525 == 1 ) {
struct V_84 * V_85 ;
unsigned long V_62 ;
V_85 = F_113 ( V_80 , V_161 ) ;
if ( ! V_85 )
return - V_25 ;
V_85 -> V_490 = V_523 ;
V_85 -> V_520 = V_524 ;
V_85 -> V_528 = V_514 ;
V_85 -> V_529 = V_335 ;
V_85 -> V_530 = V_85 -> V_529 * V_527 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_28 ( & V_85 -> V_118 , & V_80 -> V_116 ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
return V_525 ;
}
for ( V_195 = 0 ; V_195 < V_525 ; V_195 ++ ) {
struct V_84 * V_85 ;
unsigned int V_530 , V_531 ;
struct V_337 * V_338 ;
unsigned long V_62 ;
int V_340 ;
V_85 = F_113 ( V_80 , V_161 ) ;
if ( ! V_85 )
return - V_25 ;
V_85 -> V_528 = V_514 ;
V_85 -> V_529 = F_207 ( V_335 , V_526 ) ;
V_85 -> V_530 = V_85 -> V_529 * V_527 ;
V_85 -> V_520 = F_195 ( V_85 -> V_530 , V_511 ) ;
if ( V_80 -> V_71 -> V_519 && ( V_195 < ( V_525 - 1 ) ) ) {
V_531 = ( V_85 -> V_520 + 1 ) ;
} else
V_531 = V_85 -> V_520 ;
V_85 -> V_490 = F_163 ( sizeof( struct V_337 ) *
V_531 , V_39 ) ;
if ( ! V_85 -> V_490 ) {
V_80 -> V_83 -> V_130 -> V_491 ( V_85 ) ;
return - V_25 ;
}
F_196 ( V_85 -> V_490 , V_531 ) ;
V_530 = V_85 -> V_530 ;
F_165 (task->task_sg, sg, task->task_sg_nents, count) {
if ( V_523 -> V_343 > V_530 )
break;
* V_338 = * V_523 ;
V_530 -= V_523 -> V_343 ;
V_523 = F_208 ( V_523 ) ;
}
V_514 += V_85 -> V_529 ;
V_335 -= V_85 -> V_529 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_28 ( & V_85 -> V_118 , & V_80 -> V_116 ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
}
return V_525 ;
}
static int
F_209 ( struct V_79 * V_80 )
{
struct V_84 * V_85 ;
unsigned long V_62 ;
if ( ( V_80 -> V_109 & V_384 ) &&
! V_80 -> V_255 )
return 0 ;
V_85 = F_113 ( V_80 , V_80 -> V_161 ) ;
if ( ! V_85 )
return - V_25 ;
V_85 -> V_490 = V_80 -> V_341 ;
V_85 -> V_530 = V_80 -> V_255 ;
V_85 -> V_520 = V_80 -> V_342 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_28 ( & V_85 -> V_118 , & V_80 -> V_116 ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
return 1 ;
}
int F_125 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
int V_532 , V_533 = 0 ;
int V_534 = 1 ;
int V_36 = 0 ;
if ( ! ( V_80 -> V_109 & V_494 ) &&
V_80 -> V_255 ) {
V_36 = F_194 ( V_80 ) ;
if ( V_36 < 0 )
goto V_535;
}
if ( V_80 -> V_485 &&
V_82 -> V_130 -> V_196 != V_197 ) {
F_10 ( ! ( V_80 -> V_109 & V_373 ) ) ;
V_533 = F_205 ( V_80 ,
V_163 , V_80 -> V_485 ,
V_80 -> V_495 ) ;
if ( V_533 <= 0 )
goto V_535;
F_61 ( & V_80 -> V_499 ) ;
F_61 ( & V_80 -> V_501 ) ;
V_534 = 0 ;
}
if ( V_80 -> V_109 & V_373 ) {
V_532 = F_205 ( V_80 ,
V_80 -> V_161 , V_80 -> V_341 ,
V_80 -> V_342 ) ;
} else {
V_532 = F_209 ( V_80 ) ;
}
if ( V_532 < 0 )
goto V_535;
else if ( ! V_532 && ( V_80 -> V_109 & V_373 ) ) {
F_27 ( & V_80 -> V_95 ) ;
V_80 -> V_94 = V_140 ;
V_80 -> V_96 |= V_99 ;
F_29 ( & V_80 -> V_95 ) ;
if ( V_80 -> V_149 [ 0 ] == V_440 ) {
T_3 V_536 = 0 , V_537 = 0 ;
F_210 ( V_80 ,
& V_536 , & V_537 ) ;
}
F_72 ( & V_80 -> V_128 , V_139 ) ;
F_73 ( V_22 , & V_80 -> V_128 ) ;
return 0 ;
}
if ( V_534 ) {
F_61 ( & V_80 -> V_499 ) ;
F_61 ( & V_80 -> V_501 ) ;
}
V_80 -> V_300 = ( V_532 + V_533 ) ;
F_14 ( & V_80 -> V_137 , V_80 -> V_300 ) ;
F_14 ( & V_80 -> V_92 , V_80 -> V_300 ) ;
if ( V_80 -> V_161 == V_164 ) {
F_76 ( V_80 ) ;
return F_211 ( V_80 ) ;
}
F_154 ( V_80 ) ;
return 0 ;
V_535:
V_80 -> V_109 |= V_265 ;
V_80 -> V_125 = V_126 ;
return - V_189 ;
}
void F_212 ( struct V_79 * V_80 )
{
F_154 ( V_80 ) ;
}
static void F_213 ( struct V_79 * V_80 )
{
int V_36 ;
V_36 = V_80 -> V_71 -> V_538 ( V_80 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 ) {
F_30 ( L_177 ,
V_80 ) ;
F_147 ( V_80 , V_80 -> V_83 ) ;
}
}
static int F_211 ( struct V_79 * V_80 )
{
unsigned long V_62 ;
int V_36 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
V_80 -> V_94 = V_539 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_53 ( V_80 , 1 , 0 ) ;
V_36 = V_80 -> V_71 -> V_538 ( V_80 ) ;
if ( V_36 == - V_317 || V_36 == - V_25 )
goto V_318;
else if ( V_36 < 0 )
return V_36 ;
return 1 ;
V_318:
F_30 ( L_177 , V_80 ) ;
V_80 -> V_94 = V_160 ;
F_147 ( V_80 , V_80 -> V_83 ) ;
return 0 ;
}
void F_132 ( struct V_79 * V_80 , int V_540 )
{
if ( ! ( V_80 -> V_109 & V_541 ) ) {
if ( V_540 && ( V_80 -> V_109 & V_110 ) )
F_214 ( V_80 ) ;
F_185 ( V_80 ) ;
} else {
if ( V_540 )
F_214 ( V_80 ) ;
F_215 ( V_80 -> V_38 -> V_48 , V_80 ) ;
if ( V_80 -> V_102 )
F_55 ( V_80 ) ;
F_180 ( V_80 ) ;
F_59 ( V_80 ) ;
}
}
void F_127 ( struct V_2 * V_38 , struct V_79 * V_79 ,
bool V_542 )
{
unsigned long V_62 ;
F_23 ( & V_79 -> V_543 ) ;
if ( V_542 == true ) {
F_26 ( & V_79 -> V_543 ) ;
V_79 -> V_109 |= V_544 ;
}
F_32 ( & V_38 -> V_44 , V_62 ) ;
F_28 ( & V_79 -> V_259 , & V_38 -> V_42 ) ;
V_79 -> V_496 = 1 ;
F_33 ( & V_38 -> V_44 , V_62 ) ;
}
static void F_216 ( struct V_64 * V_64 )
{
struct V_79 * V_79 = F_35 ( V_64 , struct V_79 , V_543 ) ;
struct V_2 * V_38 = V_79 -> V_38 ;
unsigned long V_62 ;
F_32 ( & V_38 -> V_44 , V_62 ) ;
if ( F_44 ( & V_79 -> V_259 ) ) {
F_33 ( & V_38 -> V_44 , V_62 ) ;
V_79 -> V_71 -> V_497 ( V_79 ) ;
return;
}
if ( V_38 -> V_545 && V_79 -> V_546 ) {
F_33 ( & V_38 -> V_44 , V_62 ) ;
F_40 ( & V_79 -> V_261 ) ;
return;
}
F_43 ( & V_79 -> V_259 ) ;
F_33 ( & V_38 -> V_44 , V_62 ) ;
V_79 -> V_71 -> V_497 ( V_79 ) ;
}
int F_130 ( struct V_2 * V_38 , struct V_79 * V_79 )
{
return F_38 ( & V_79 -> V_543 , F_216 ) ;
}
void F_217 ( struct V_2 * V_38 )
{
struct V_79 * V_79 ;
unsigned long V_62 ;
F_81 ( ! F_44 ( & V_38 -> V_43 ) ) ;
F_15 ( & V_38 -> V_43 ) ;
F_32 ( & V_38 -> V_44 , V_62 ) ;
V_38 -> V_545 = 1 ;
F_84 ( & V_38 -> V_42 , & V_38 -> V_43 ) ;
F_51 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_79 -> V_546 = 1 ;
F_33 ( & V_38 -> V_44 , V_62 ) ;
}
void F_218 (
struct V_2 * V_38 ,
int V_540 )
{
struct V_79 * V_79 , * V_547 ;
bool V_276 = false ;
F_85 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_43 ( & V_79 -> V_259 ) ;
F_30 ( L_178
L_179 , V_79 , V_79 -> V_94 ,
V_79 -> V_71 -> V_299 ( V_79 ) ) ;
if ( V_540 ) {
F_30 ( L_180
L_181 , V_79 , V_79 -> V_94 ,
V_79 -> V_71 -> V_299 ( V_79 ) ) ;
V_276 = F_214 ( V_79 ) ;
F_30 ( L_182
L_181 , V_79 , V_79 -> V_94 ,
V_79 -> V_71 -> V_299 ( V_79 ) ) ;
}
if ( ! V_276 ) {
F_143 ( & V_79 -> V_261 ) ;
F_30 ( L_183
L_181 , V_79 , V_79 -> V_94 ,
V_79 -> V_71 -> V_299 ( V_79 ) ) ;
}
V_79 -> V_71 -> V_497 ( V_79 ) ;
}
}
static int F_219 ( struct V_79 * V_80 , struct V_102 * V_105 )
{
unsigned long V_62 ;
int V_36 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_96 & V_101 ) {
V_80 -> V_96 &= ~ V_97 ;
F_30 ( L_184 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_53 ( V_80 , 1 , 0 ) ;
return - V_293 ;
}
V_80 -> V_96 |= V_548 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_63 ( & V_80 -> V_83 -> V_112 . V_34 ) ;
V_36 = F_144 ( V_80 ) ;
F_30 ( L_185
L_179 , V_80 , V_80 -> V_300 , V_36 ) ;
if ( ! V_36 ) {
F_30 ( L_186 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_143 ( & V_80 -> V_100 ) ;
F_30 ( L_187 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
}
F_58 ( V_80 ) ;
return 0 ;
}
static void F_220 ( struct V_102 * V_105 )
{
struct V_79 * V_80 = NULL ;
unsigned long V_549 , V_550 ;
F_32 ( & V_105 -> V_107 , V_549 ) ;
while ( ! F_44 ( & V_105 -> V_551 ) ) {
V_80 = F_65 ( & V_105 -> V_551 ,
struct V_79 , V_108 ) ;
F_56 ( & V_80 -> V_108 ) ;
F_11 ( & V_80 -> V_95 ) ;
F_30 ( L_188
L_189 ,
V_80 -> V_102 -> V_274 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
V_80 -> V_96 |= V_97 ;
F_12 ( & V_80 -> V_95 ) ;
F_33 ( & V_105 -> V_107 , V_549 ) ;
if ( ! V_80 -> V_102 ) {
F_4 ( L_190 ,
V_80 -> V_71 -> V_90 ( V_80 ) ,
V_80 -> V_71 -> V_299 ( V_80 ) , V_80 -> V_94 ) ;
F_221 () ;
}
F_30 ( L_191
L_192 , V_80 -> V_102 -> V_274 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
if ( F_219 ( V_80 , V_80 -> V_102 ) < 0 ) {
F_32 ( & V_105 -> V_107 , V_549 ) ;
continue;
}
F_30 ( L_193
L_194 ,
V_80 -> V_102 -> V_274 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_32 ( & V_80 -> V_95 , V_550 ) ;
if ( ! ( V_80 -> V_96 & V_106 ) ) {
F_33 ( & V_80 -> V_95 , V_550 ) ;
goto V_552;
}
V_80 -> V_96 &= ~ V_106 ;
F_50 ( V_80 ) ;
F_33 ( & V_80 -> V_95 , V_550 ) ;
F_180 ( V_80 ) ;
V_552:
F_129 ( V_80 ,
V_303 , 0 ) ;
F_32 ( & V_80 -> V_95 , V_550 ) ;
if ( V_80 -> V_96 & V_548 ) {
F_30 ( L_195
L_196 ,
V_105 -> V_274 ,
V_80 , V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_33 ( & V_80 -> V_95 ,
V_550 ) ;
F_53 ( V_80 , 1 , 0 ) ;
F_40 ( & V_80 -> V_260 ) ;
F_32 ( & V_105 -> V_107 , V_549 ) ;
continue;
}
F_30 ( L_197 ,
V_105 -> V_274 , V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_33 ( & V_80 -> V_95 , V_550 ) ;
F_32 ( & V_105 -> V_107 , V_549 ) ;
}
F_33 ( & V_105 -> V_107 , V_549 ) ;
}
static int F_222 ( void * V_553 )
{
struct V_102 * V_105 = V_553 ;
F_220 ( V_105 ) ;
F_40 ( & V_105 -> V_554 ) ;
return 0 ;
}
int F_223 ( struct V_102 * V_105 )
{
struct V_555 * V_556 ;
V_556 = F_107 ( F_222 , V_105 ,
L_198 , V_105 -> V_274 ) ;
if ( F_108 ( V_556 ) ) {
F_4 ( L_199 ) ;
return F_224 ( V_556 ) ;
}
F_143 ( & V_105 -> V_554 ) ;
return 0 ;
}
bool F_214 ( struct V_79 * V_80 )
{
unsigned long V_62 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( ! ( V_80 -> V_109 & V_541 ) &&
! ( V_80 -> V_109 & V_110 ) ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return false ;
}
if ( ! ( V_80 -> V_109 & V_322 ) &&
! ( V_80 -> V_109 & V_110 ) ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return false ;
}
if ( V_80 -> V_96 & V_97 ) {
F_30 ( L_200
L_201
L_202 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_40 ( & V_80 -> V_100 ) ;
F_143 ( & V_80 -> V_260 ) ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
F_50 ( V_80 ) ;
F_30 ( L_203
L_204
L_205 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
V_80 -> V_96 &= ~ V_97 ;
}
if ( ! ( V_80 -> V_96 & V_99 ) ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return false ;
}
V_80 -> V_96 |= V_101 ;
F_30 ( L_206
L_207 ,
V_80 , V_80 -> V_71 -> V_90 ( V_80 ) ,
V_80 -> V_71 -> V_299 ( V_80 ) , V_80 -> V_94 ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
F_63 ( & V_80 -> V_83 -> V_112 . V_34 ) ;
F_143 ( & V_80 -> V_103 ) ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
V_80 -> V_96 &= ~ ( V_99 | V_101 ) ;
F_30 ( L_208
L_209 ,
V_80 -> V_71 -> V_90 ( V_80 ) ) ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
return true ;
}
static int F_225 (
struct V_79 * V_80 ,
T_3 * V_557 ,
T_3 * V_558 )
{
* V_557 = V_80 -> V_559 ;
* V_558 = V_80 -> V_560 ;
return 0 ;
}
static int F_174 (
struct V_79 * V_80 ,
T_3 V_557 ,
T_3 V_558 )
{
V_80 -> V_559 = V_557 ;
V_80 -> V_560 = V_558 ;
return 0 ;
}
int F_129 (
struct V_79 * V_80 ,
T_3 V_486 ,
int V_561 )
{
unsigned char * V_344 = V_80 -> V_257 ;
unsigned long V_62 ;
int V_339 ;
T_3 V_557 = 0 , V_558 = 0 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_109 & V_345 ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return 0 ;
}
V_80 -> V_109 |= V_345 ;
F_33 ( & V_80 -> V_95 , V_62 ) ;
if ( ! V_486 && V_561 )
goto V_562;
if ( ! V_561 )
V_80 -> V_109 |= V_563 ;
V_339 = V_80 -> V_71 -> V_347 ( V_80 ,
V_348 ) ;
switch ( V_486 ) {
case V_303 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_566 ;
V_344 [ V_339 + V_567 ] = 0x25 ;
break;
case V_304 :
case V_568 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_566 ;
V_344 [ V_339 + V_567 ] = 0x20 ;
break;
case V_306 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_566 ;
V_344 [ V_339 + V_567 ] = 0x24 ;
break;
case V_308 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_569 ;
V_344 [ V_339 + V_567 ] = 0x29 ;
V_344 [ V_339 + V_570 ] = 0x03 ;
break;
case V_571 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_569 ;
V_344 [ V_339 + V_567 ] = 0x0c ;
V_344 [ V_339 + V_570 ] = 0x0d ;
break;
case V_266 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_566 ;
V_344 [ V_339 + V_567 ] = 0x24 ;
break;
case V_305 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_566 ;
V_344 [ V_339 + V_567 ] = 0x26 ;
break;
case V_572 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_569 ;
V_344 [ V_339 + V_567 ] = 0x0c ;
V_344 [ V_339 + V_570 ] = 0x0c ;
break;
case V_573 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_569 ;
V_344 [ V_339 + V_567 ] = 0x47 ;
V_344 [ V_339 + V_570 ] = 0x05 ;
break;
case V_574 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_569 ;
V_344 [ V_339 + V_567 ] = 0x11 ;
V_344 [ V_339 + V_570 ] = 0x13 ;
break;
case V_307 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_575 ;
V_344 [ V_339 + V_567 ] = 0x27 ;
break;
case V_309 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_576 ;
F_226 ( V_80 , & V_557 , & V_558 ) ;
V_344 [ V_339 + V_567 ] = V_557 ;
V_344 [ V_339 + V_570 ] = V_558 ;
break;
case V_310 :
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_577 ;
F_225 ( V_80 , & V_557 , & V_558 ) ;
V_344 [ V_339 + V_567 ] = V_557 ;
V_344 [ V_339 + V_570 ] = V_558 ;
break;
case V_126 :
default:
V_344 [ V_339 ] = 0x70 ;
V_344 [ V_339 + V_564 ] = 10 ;
V_344 [ V_339 + V_565 ] = V_566 ;
V_344 [ V_339 + V_567 ] = 0x80 ;
break;
}
V_80 -> V_119 = V_123 ;
V_80 -> V_349 = V_348 + V_339 ;
V_562:
return V_80 -> V_71 -> V_316 ( V_80 ) ;
}
int F_141 ( struct V_79 * V_80 , int V_578 )
{
int V_36 = 0 ;
if ( V_80 -> V_96 & V_138 ) {
if ( ! V_578 ||
( V_80 -> V_109 & V_579 ) )
return 1 ;
#if 0
pr_debug("Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_80 -> V_109 |= V_579 ;
V_80 -> V_71 -> V_316 ( V_80 ) ;
V_36 = 1 ;
}
return V_36 ;
}
void F_227 ( struct V_79 * V_80 )
{
unsigned long V_62 ;
F_32 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_109 & V_345 ) {
F_33 ( & V_80 -> V_95 , V_62 ) ;
return;
}
F_33 ( & V_80 -> V_95 , V_62 ) ;
if ( V_80 -> V_161 == V_164 ) {
if ( V_80 -> V_71 -> V_580 ( V_80 ) != 0 ) {
V_80 -> V_96 |= V_138 ;
F_118 () ;
}
}
V_80 -> V_119 = V_581 ;
#if 0
pr_debug("Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
V_80 -> V_71 -> V_316 ( V_80 ) ;
}
static int F_228 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_280 * V_582 = V_80 -> V_280 ;
int V_36 ;
switch ( V_582 -> V_583 ) {
case V_289 :
F_229 ( V_82 , V_582 , V_80 -> V_38 ) ;
break;
case V_584 :
case V_585 :
case V_586 :
V_582 -> V_281 = V_587 ;
break;
case V_588 :
V_36 = F_230 ( V_82 , V_582 , NULL , NULL ) ;
V_582 -> V_281 = ( ! V_36 ) ? V_589 :
V_590 ;
break;
case V_591 :
V_582 -> V_281 = V_590 ;
break;
case V_592 :
V_582 -> V_281 = V_590 ;
break;
default:
F_4 ( L_210 ,
V_582 -> V_583 ) ;
V_582 -> V_281 = V_590 ;
break;
}
V_80 -> V_94 = V_593 ;
V_80 -> V_71 -> V_283 ( V_80 ) ;
F_54 ( V_80 ) ;
return 0 ;
}
static int V_241 ( void * V_594 )
{
int V_36 ;
struct V_79 * V_80 ;
struct V_81 * V_82 = V_594 ;
while ( ! F_231 () ) {
V_36 = F_232 ( V_82 -> V_112 . V_34 ,
F_89 ( & V_82 -> V_112 . V_32 ) ||
F_231 () ) ;
if ( V_36 < 0 )
goto V_3;
V_595:
V_80 = F_64 ( & V_82 -> V_112 ) ;
if ( ! V_80 )
continue;
switch ( V_80 -> V_94 ) {
case V_272 :
F_221 () ;
break;
case V_291 :
if ( ! V_80 -> V_71 -> V_596 ) {
F_4 ( L_211
L_212 ) ;
F_221 () ;
}
V_36 = V_80 -> V_71 -> V_596 ( V_80 ) ;
if ( V_36 < 0 ) {
F_70 ( V_80 ) ;
break;
}
V_36 = F_125 ( V_80 ) ;
if ( V_36 < 0 ) {
F_70 ( V_80 ) ;
break;
}
break;
case V_294 :
F_212 ( V_80 ) ;
break;
case V_295 :
F_228 ( V_80 ) ;
break;
case V_160 :
F_213 ( V_80 ) ;
break;
case V_159 :
F_179 ( V_80 ) ;
break;
default:
F_4 ( L_213
L_214 ,
V_80 -> V_94 ,
V_80 -> V_71 -> V_90 ( V_80 ) ,
V_80 -> V_71 -> V_299 ( V_80 ) ,
V_80 -> V_102 -> V_274 ) ;
F_221 () ;
}
goto V_595;
}
V_3:
F_81 ( ! F_44 ( & V_82 -> V_152 ) ) ;
F_81 ( ! F_44 ( & V_82 -> V_112 . V_33 ) ) ;
V_82 -> V_240 = NULL ;
return 0 ;
}
