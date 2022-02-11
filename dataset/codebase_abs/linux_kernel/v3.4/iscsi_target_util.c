int F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 ,
int V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( V_9 , V_10 ) ;
if ( ! V_8 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
F_4 ( & V_8 -> V_11 ) ;
V_8 -> V_12 = V_5 ;
V_8 -> V_6 = ( ! V_6 ) ? V_2 -> V_6 ++ : V_6 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_4 = V_4 ;
F_5 ( & V_8 -> V_11 , & V_2 -> V_13 ) ;
F_6 ( & V_2 -> V_14 ) ;
F_7 ( V_2 , V_2 -> V_15 , V_16 ) ;
F_8 ( & V_2 -> V_14 ) ;
return 0 ;
}
struct V_7 * F_9 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_17 )
{
struct V_7 * V_8 ;
F_8 ( & V_2 -> V_14 ) ;
F_10 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( ( V_8 -> V_3 <= V_3 ) &&
( V_8 -> V_3 + V_8 -> V_4 ) >= ( V_3 + V_17 ) ) {
F_6 ( & V_2 -> V_14 ) ;
return V_8 ;
}
}
F_6 ( & V_2 -> V_14 ) ;
F_3 ( L_2
L_3 , V_3 , V_17 ) ;
return NULL ;
}
struct V_7 * F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_8 ( & V_2 -> V_14 ) ;
F_10 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( ! V_8 -> V_18 ) {
F_6 ( & V_2 -> V_14 ) ;
return V_8 ;
}
}
F_6 ( & V_2 -> V_14 ) ;
F_3 ( L_4
L_5 , V_2 -> V_19 ) ;
return NULL ;
}
void F_12 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_13 ( & V_8 -> V_11 ) ;
F_14 ( V_9 , V_8 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_20 ;
F_8 ( & V_2 -> V_14 ) ;
F_16 (r2t, r2t_tmp, &cmd->cmd_r2t_list, r2t_list)
F_12 ( V_8 , V_2 ) ;
F_6 ( & V_2 -> V_14 ) ;
}
struct V_1 * F_17 ( struct V_21 * V_15 , T_2 V_22 )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_23 , V_22 ) ;
if ( ! V_2 ) {
F_3 ( L_6 ) ;
return NULL ;
}
V_2 -> V_15 = V_15 ;
F_4 ( & V_2 -> V_24 ) ;
F_4 ( & V_2 -> V_25 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_18 ( & V_2 -> V_26 ) ;
F_19 ( & V_2 -> V_27 ) ;
F_19 ( & V_2 -> V_28 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_19 ( & V_2 -> V_30 ) ;
F_19 ( & V_2 -> V_14 ) ;
return V_2 ;
}
struct V_1 * F_20 (
struct V_21 * V_15 ,
T_1 V_31 ,
int V_32 ,
int V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_34 ;
int V_35 ;
V_2 = F_17 ( V_15 , V_36 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_32 = V_32 ;
V_2 -> V_31 = V_31 ;
if ( ( V_33 == V_37 ) ||
( V_33 == V_38 ) )
V_35 = V_39 ;
else if ( V_33 == V_40 )
V_35 = V_41 ;
else if ( V_33 == V_42 )
V_35 = V_43 ;
else if ( V_33 == V_44 )
V_35 = V_45 ;
else {
F_21 ( L_7
L_8 , V_33 ) ;
V_35 = V_39 ;
}
V_34 = & V_2 -> V_34 ;
F_22 ( V_34 , & V_46 -> V_47 ,
V_15 -> V_48 -> V_49 , V_31 , V_32 ,
V_35 , & V_2 -> V_50 [ 0 ] ) ;
return V_2 ;
}
struct V_1 * F_23 (
struct V_21 * V_15 ,
T_3 V_51 )
{
struct V_1 * V_2 ;
struct V_34 * V_34 ;
int V_52 ;
T_3 V_53 ;
V_2 = F_17 ( V_15 , V_36 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_32 = V_54 ;
V_2 -> V_55 = F_24 ( sizeof( struct V_56 ) , V_36 ) ;
if ( ! V_2 -> V_55 ) {
F_3 ( L_9
L_10 ) ;
goto V_57;
}
if ( V_51 == V_58 )
return V_2 ;
V_34 = & V_2 -> V_34 ;
F_22 ( V_34 , & V_46 -> V_47 ,
V_15 -> V_48 -> V_49 , 0 , V_54 ,
V_39 , & V_2 -> V_50 [ 0 ] ) ;
switch ( V_51 ) {
case V_59 :
V_53 = V_60 ;
break;
case V_61 :
V_53 = V_62 ;
break;
case V_63 :
V_53 = V_64 ;
break;
case V_65 :
V_53 = V_66 ;
break;
case V_67 :
V_53 = V_68 ;
break;
case V_69 :
V_53 = V_70 ;
break;
case V_71 :
V_53 = V_72 ;
break;
default:
F_3 ( L_11
L_12 , V_51 ) ;
goto V_57;
}
V_52 = F_25 ( V_34 , V_2 -> V_55 , V_53 , V_36 ) ;
if ( V_52 < 0 )
goto V_57;
V_2 -> V_55 -> V_73 = V_34 -> V_73 ;
return V_2 ;
V_57:
F_26 ( V_2 ) ;
return NULL ;
}
int F_27 (
struct V_1 * V_2 ,
T_1 V_74 )
{
struct V_75 V_76 ;
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_77 * V_48 = V_15 -> V_48 ;
struct V_78 * V_79 ;
if ( V_48 -> V_80 -> V_81 &&
V_48 -> V_80 -> V_82 )
return 0 ;
if ( V_2 -> V_32 == V_54 )
return 0 ;
V_79 = F_28 ( V_48 ) ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
if ( V_2 -> V_32 == V_83 ) {
V_76 . V_32 = V_84 ;
V_76 . type = V_85 ;
if ( V_79 -> V_86 )
V_76 . V_87 |= V_88 ;
if ( V_79 -> V_89 )
V_76 . V_87 |= V_90 ;
} else {
V_76 . V_32 = V_91 ;
V_76 . V_74 = V_74 ;
if ( V_79 -> V_92 )
V_76 . V_87 |= V_93 ;
if ( ! V_2 -> V_94 && ! V_2 -> V_95 )
V_76 . type = V_85 ;
else if ( V_2 -> V_94 && ! V_2 -> V_95 )
V_76 . type = V_96 ;
else if ( ! V_2 -> V_94 && V_2 -> V_95 )
V_76 . type = V_97 ;
else if ( V_2 -> V_94 && V_2 -> V_95 )
V_76 . type = V_98 ;
}
return F_29 ( V_2 , & V_76 ) ;
}
struct V_99 * F_30 (
struct V_1 * V_2 ,
T_1 V_100 )
{
T_1 V_101 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ )
if ( V_2 -> V_103 [ V_101 ] . V_100 == V_100 )
return & V_2 -> V_103 [ V_101 ] ;
return NULL ;
}
struct V_99 * F_31 ( struct V_1 * V_2 )
{
T_1 V_101 ;
if ( ! V_2 -> V_103 ) {
F_3 ( L_13 ) ;
return NULL ;
}
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
if ( V_2 -> V_103 [ V_101 ] . type != V_104 )
continue;
if ( V_2 -> V_103 [ V_101 ] . V_100 == V_2 -> V_100 ) {
V_2 -> V_100 ++ ;
return & V_2 -> V_103 [ V_101 ] ;
}
}
return NULL ;
}
struct V_7 * F_32 (
struct V_1 * V_2 ,
T_1 V_6 )
{
struct V_7 * V_8 ;
F_8 ( & V_2 -> V_14 ) ;
F_10 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_8 -> V_6 == V_6 ) {
F_6 ( & V_2 -> V_14 ) ;
return V_8 ;
}
}
F_6 ( & V_2 -> V_14 ) ;
return NULL ;
}
static inline int F_33 ( struct V_77 * V_48 , T_1 V_105 )
{
int V_106 ;
if ( F_34 ( V_105 , V_48 -> V_107 ) ) {
F_3 ( L_14
L_15 , V_105 ,
V_48 -> V_107 ) ;
V_106 = V_108 ;
} else if ( V_105 == V_48 -> V_109 ) {
V_48 -> V_109 ++ ;
F_21 ( L_16
L_17 ,
V_48 -> V_109 ) ;
V_106 = V_110 ;
} else if ( F_34 ( V_105 , V_48 -> V_109 ) ) {
F_21 ( L_18
L_19 ,
V_105 , V_48 -> V_109 ) ;
V_106 = V_111 ;
} else {
F_3 ( L_20
L_21 , V_105 ,
V_48 -> V_109 ) ;
V_106 = V_112 ;
}
return V_106 ;
}
int F_35 (
struct V_21 * V_15 ,
struct V_1 * V_2 ,
T_1 V_105 )
{
int V_106 ;
int V_113 ;
F_36 ( & V_15 -> V_48 -> V_114 ) ;
V_113 = F_33 ( V_15 -> V_48 , V_105 ) ;
switch ( V_113 ) {
case V_110 :
V_106 = F_37 ( V_2 , 0 ) ;
if ( ( V_106 >= 0 ) && ! F_38 ( & V_15 -> V_48 -> V_115 ) )
F_39 ( V_15 -> V_48 ) ;
break;
case V_111 :
V_106 = F_40 ( V_15 -> V_48 , V_2 , V_105 ) ;
break;
case V_112 :
V_2 -> V_116 = V_117 ;
F_7 ( V_2 , V_15 , V_2 -> V_116 ) ;
V_106 = V_113 ;
break;
default:
V_106 = V_113 ;
break;
}
F_41 ( & V_15 -> V_48 -> V_114 ) ;
return V_106 ;
}
int F_42 ( struct V_1 * V_2 , unsigned char * V_118 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_34 * V_34 = & V_2 -> V_34 ;
struct V_119 * V_120 = (struct V_119 * ) V_118 ;
T_1 V_121 = F_43 ( V_120 -> V_122 ) ;
if ( V_15 -> V_48 -> V_80 -> V_123 ) {
F_3 ( L_22
L_23 ) ;
F_44 ( V_34 ,
V_124 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_125 + V_121 ) >
V_15 -> V_48 -> V_80 -> V_126 ) {
F_3 ( L_24
L_25 ,
( V_2 -> V_125 + V_121 ) ,
V_15 -> V_48 -> V_80 -> V_126 ) ;
F_44 ( V_34 ,
V_127 , 0 ) ;
return - 1 ;
}
if ( ! ( V_120 -> V_128 & V_129 ) )
return 0 ;
if ( ( ( V_2 -> V_125 + V_121 ) != V_2 -> V_31 ) &&
( ( V_2 -> V_125 + V_121 ) !=
V_15 -> V_48 -> V_80 -> V_126 ) ) {
F_3 ( L_26
L_27
L_28 ,
( V_2 -> V_125 + V_121 ) ,
V_15 -> V_48 -> V_80 -> V_126 , V_2 -> V_31 ) ;
F_44 ( V_34 ,
V_127 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_45 (
struct V_21 * V_15 ,
T_1 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_130 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_130 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_130 ) ;
F_3 ( L_29 ,
V_19 , V_15 -> V_131 ) ;
return NULL ;
}
struct V_1 * F_46 (
struct V_21 * V_15 ,
T_1 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_130 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_130 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_130 ) ;
F_3 ( L_30
L_31 , V_19 , V_15 -> V_131 ) ;
if ( V_17 )
F_47 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_48 (
struct V_21 * V_15 ,
T_1 V_132 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_130 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_2 -> V_132 == V_132 ) {
F_6 ( & V_15 -> V_130 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_130 ) ;
F_3 ( L_32 ,
V_132 , V_15 -> V_131 ) ;
return NULL ;
}
int F_49 (
struct V_77 * V_48 ,
struct V_1 * * V_133 ,
struct V_134 * * V_135 ,
T_1 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_134 * V_136 ;
F_50 ( & V_48 -> V_137 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_50 ( & V_136 -> V_138 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_51 ( & V_136 -> V_138 ) ;
F_51 ( & V_48 -> V_137 ) ;
* V_135 = V_136 ;
* V_133 = V_2 ;
return - 2 ;
}
}
F_51 ( & V_136 -> V_138 ) ;
}
F_51 ( & V_48 -> V_137 ) ;
F_50 ( & V_48 -> V_139 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_50 ( & V_136 -> V_138 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_51 ( & V_136 -> V_138 ) ;
F_51 ( & V_48 -> V_139 ) ;
* V_135 = V_136 ;
* V_133 = V_2 ;
return 0 ;
}
}
F_51 ( & V_136 -> V_138 ) ;
}
F_51 ( & V_48 -> V_139 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_140 )
{
struct V_141 * V_142 ;
V_142 = F_2 ( V_143 , V_10 ) ;
if ( ! V_142 ) {
F_3 ( L_9
L_33 ) ;
return;
}
F_4 ( & V_142 -> V_144 ) ;
V_142 -> V_2 = V_2 ;
V_142 -> V_140 = V_140 ;
F_8 ( & V_15 -> V_145 ) ;
F_5 ( & V_142 -> V_144 , & V_15 -> V_146 ) ;
F_52 ( & V_2 -> V_147 ) ;
F_53 ( & V_15 -> V_148 , 1 ) ;
F_6 ( & V_15 -> V_145 ) ;
F_54 ( V_15 -> V_149 -> V_150 ) ;
}
struct V_141 * F_55 ( struct V_21 * V_15 )
{
struct V_141 * V_142 ;
F_8 ( & V_15 -> V_145 ) ;
if ( F_38 ( & V_15 -> V_146 ) ) {
F_6 ( & V_15 -> V_145 ) ;
return NULL ;
}
F_10 (qr, &conn->immed_queue_list, qr_list)
break;
F_13 ( & V_142 -> V_144 ) ;
if ( V_142 -> V_2 )
F_56 ( & V_142 -> V_2 -> V_147 ) ;
F_6 ( & V_15 -> V_145 ) ;
return V_142 ;
}
static void F_57 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_141 * V_142 , * V_151 ;
F_8 ( & V_15 -> V_145 ) ;
if ( ! F_58 ( & V_2 -> V_147 ) ) {
F_6 ( & V_15 -> V_145 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_142 -> V_2 != V_2 )
continue;
F_56 ( & V_142 -> V_2 -> V_147 ) ;
F_13 ( & V_142 -> V_144 ) ;
F_14 ( V_143 , V_142 ) ;
}
F_6 ( & V_15 -> V_145 ) ;
if ( F_58 ( & V_2 -> V_147 ) ) {
F_3 ( L_34 ,
V_2 -> V_19 ,
F_58 ( & V_2 -> V_147 ) ) ;
}
}
void F_59 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_140 )
{
struct V_141 * V_142 ;
V_142 = F_2 ( V_143 , V_10 ) ;
if ( ! V_142 ) {
F_3 ( L_9
L_33 ) ;
return;
}
F_4 ( & V_142 -> V_144 ) ;
V_142 -> V_2 = V_2 ;
V_142 -> V_140 = V_140 ;
F_8 ( & V_15 -> V_152 ) ;
F_5 ( & V_142 -> V_144 , & V_15 -> V_153 ) ;
F_52 ( & V_2 -> V_154 ) ;
F_6 ( & V_15 -> V_152 ) ;
F_54 ( V_15 -> V_149 -> V_150 ) ;
}
struct V_141 * F_60 ( struct V_21 * V_15 )
{
struct V_141 * V_142 ;
F_8 ( & V_15 -> V_152 ) ;
if ( F_38 ( & V_15 -> V_153 ) ) {
F_6 ( & V_15 -> V_152 ) ;
return NULL ;
}
F_10 (qr, &conn->response_queue_list, qr_list)
break;
F_13 ( & V_142 -> V_144 ) ;
if ( V_142 -> V_2 )
F_56 ( & V_142 -> V_2 -> V_154 ) ;
F_6 ( & V_15 -> V_152 ) ;
return V_142 ;
}
static void F_61 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_141 * V_142 , * V_151 ;
F_8 ( & V_15 -> V_152 ) ;
if ( ! F_58 ( & V_2 -> V_154 ) ) {
F_6 ( & V_15 -> V_152 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_142 -> V_2 != V_2 )
continue;
F_56 ( & V_142 -> V_2 -> V_154 ) ;
F_13 ( & V_142 -> V_144 ) ;
F_14 ( V_143 , V_142 ) ;
}
F_6 ( & V_15 -> V_152 ) ;
if ( F_58 ( & V_2 -> V_154 ) ) {
F_3 ( L_35 ,
V_2 -> V_19 ,
F_58 ( & V_2 -> V_154 ) ) ;
}
}
void F_62 ( struct V_21 * V_15 )
{
struct V_141 * V_142 , * V_151 ;
F_8 ( & V_15 -> V_145 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_142 -> V_144 ) ;
if ( V_142 -> V_2 )
F_56 ( & V_142 -> V_2 -> V_147 ) ;
F_14 ( V_143 , V_142 ) ;
}
F_6 ( & V_15 -> V_145 ) ;
F_8 ( & V_15 -> V_152 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_142 -> V_144 ) ;
if ( V_142 -> V_2 )
F_56 ( & V_142 -> V_2 -> V_154 ) ;
F_14 ( V_143 , V_142 ) ;
}
F_6 ( & V_15 -> V_152 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
int V_101 ;
F_15 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 -> V_155 ) ;
F_64 ( V_2 -> V_156 ) ;
F_64 ( V_2 -> V_103 ) ;
F_64 ( V_2 -> V_55 ) ;
F_64 ( V_2 -> V_157 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_158 ; V_101 ++ )
F_65 ( F_66 ( & V_2 -> V_159 [ V_101 ] ) ) ;
F_64 ( V_2 -> V_159 ) ;
if ( V_15 ) {
F_57 ( V_2 , V_15 ) ;
F_61 ( V_2 , V_15 ) ;
}
F_14 ( V_23 , V_2 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_160 ) {
case V_161 :
case V_162 :
F_68 ( & V_2 -> V_34 , 1 ) ;
break;
case V_163 :
if ( V_2 -> V_34 . V_164 != NULL ) {
F_68 ( & V_2 -> V_34 , 1 ) ;
break;
}
default:
F_26 ( V_2 ) ;
break;
}
}
int F_69 ( struct V_77 * V_48 )
{
F_8 ( & V_48 -> V_165 ) ;
if ( V_48 -> V_166 != 0 ) {
V_48 -> V_167 = 1 ;
F_6 ( & V_48 -> V_165 ) ;
if ( F_70 () )
return 2 ;
F_71 ( & V_48 -> V_168 ) ;
return 1 ;
}
F_6 ( & V_48 -> V_165 ) ;
return 0 ;
}
void F_72 ( struct V_77 * V_48 )
{
F_8 ( & V_48 -> V_165 ) ;
V_48 -> V_166 -- ;
if ( ! V_48 -> V_166 && V_48 -> V_167 )
F_73 ( & V_48 -> V_168 ) ;
F_6 ( & V_48 -> V_165 ) ;
}
void F_74 ( struct V_77 * V_48 )
{
F_8 ( & V_48 -> V_165 ) ;
V_48 -> V_166 ++ ;
F_6 ( & V_48 -> V_165 ) ;
}
int F_75 ( struct V_21 * V_15 )
{
int V_169 = 0 , V_170 = 0 , V_171 = 0 ;
T_1 V_172 = ( V_15 -> V_173 -> V_172 * 4 ) ;
T_1 V_174 = ( V_15 -> V_173 -> V_174 * 4 ) ;
if ( V_15 -> V_173 -> V_175 ) {
V_15 -> V_176 += V_177 ;
if ( V_15 -> V_176 <= V_174 ) {
V_15 -> V_176 = ( V_174 - V_15 -> V_176 ) ;
} else {
V_170 = ( V_15 -> V_176 / V_174 ) ;
V_171 = ( V_174 * ( V_170 + 1 ) ) +
( V_170 * V_178 ) ;
V_15 -> V_176 = ( V_171 - V_15 -> V_176 ) ;
}
V_15 -> V_179 = 0 ;
F_21 ( L_36
L_37 , V_15 -> V_176 ) ;
}
if ( V_15 -> V_173 -> V_180 ) {
if ( V_15 -> V_181 <= V_172 ) {
V_15 -> V_181 = ( V_172 - V_15 -> V_181 ) ;
} else {
V_169 = ( V_15 -> V_181 / V_172 ) ;
V_171 = ( V_172 * ( V_169 + 1 ) ) +
( V_169 * V_178 ) ;
V_15 -> V_181 = ( V_171 - V_15 -> V_181 ) ;
}
F_21 ( L_38
L_37 , V_15 -> V_181 ) ;
}
return 0 ;
}
struct V_21 * F_76 ( struct V_77 * V_48 , T_4 V_131 )
{
struct V_21 * V_15 ;
F_8 ( & V_48 -> V_182 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_131 == V_131 ) &&
( V_15 -> V_183 == V_184 ) ) {
F_77 ( V_15 ) ;
F_6 ( & V_48 -> V_182 ) ;
return V_15 ;
}
}
F_6 ( & V_48 -> V_182 ) ;
return NULL ;
}
struct V_21 * F_78 ( struct V_77 * V_48 , T_4 V_131 )
{
struct V_21 * V_15 ;
F_8 ( & V_48 -> V_182 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_131 == V_131 ) {
F_77 ( V_15 ) ;
F_50 ( & V_15 -> V_185 ) ;
F_53 ( & V_15 -> V_186 , 1 ) ;
F_51 ( & V_15 -> V_185 ) ;
F_6 ( & V_48 -> V_182 ) ;
return V_15 ;
}
}
F_6 ( & V_48 -> V_182 ) ;
return NULL ;
}
void F_79 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_187 ) ;
if ( V_15 -> V_188 != 0 ) {
V_15 -> V_189 = 1 ;
F_6 ( & V_15 -> V_187 ) ;
F_71 ( & V_15 -> V_190 ) ;
return;
}
F_6 ( & V_15 -> V_187 ) ;
}
void F_80 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_187 ) ;
V_15 -> V_188 -- ;
if ( ! V_15 -> V_188 && V_15 -> V_189 )
F_73 ( & V_15 -> V_190 ) ;
F_6 ( & V_15 -> V_187 ) ;
}
void F_77 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_187 ) ;
V_15 -> V_188 ++ ;
F_6 ( & V_15 -> V_187 ) ;
}
static int F_81 ( struct V_21 * V_15 , int V_191 )
{
T_3 V_140 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_160 = V_192 ;
V_140 = ( V_191 ) ? V_193 :
V_194 ;
V_2 -> V_19 = 0xFFFFFFFF ;
F_8 ( & V_15 -> V_48 -> V_195 ) ;
V_2 -> V_132 = ( V_191 ) ? V_15 -> V_48 -> V_132 ++ :
0xFFFFFFFF ;
if ( V_191 && ( V_2 -> V_132 == 0xFFFFFFFF ) )
V_2 -> V_132 = V_15 -> V_48 -> V_132 ++ ;
F_6 ( & V_15 -> V_48 -> V_195 ) ;
F_8 ( & V_15 -> V_130 ) ;
F_5 ( & V_2 -> V_24 , & V_15 -> V_196 ) ;
F_6 ( & V_15 -> V_130 ) ;
if ( V_191 )
F_82 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_140 ) ;
return 0 ;
}
static void F_83 ( unsigned long V_197 )
{
struct V_21 * V_15 = (struct V_21 * ) V_197 ;
F_77 ( V_15 ) ;
F_8 ( & V_15 -> V_198 ) ;
if ( V_15 -> V_199 & V_200 ) {
F_6 ( & V_15 -> V_198 ) ;
F_80 ( V_15 ) ;
return;
}
F_21 ( L_39
L_40 , V_15 -> V_131 ,
V_15 -> V_48 -> V_201 ) ;
V_15 -> V_199 &= ~ V_202 ;
F_6 ( & V_15 -> V_198 ) ;
{
struct V_203 * V_204 = V_15 -> V_48 -> V_204 ;
struct V_205 * V_206 = V_204 -> V_207 ;
if ( V_206 ) {
F_8 ( & V_206 -> V_208 . V_209 ) ;
strcpy ( V_206 -> V_208 . V_210 ,
V_15 -> V_48 -> V_80 -> V_211 ) ;
V_206 -> V_208 . V_212 =
V_213 ;
V_206 -> V_208 . V_214 ++ ;
V_15 -> V_48 -> V_215 ++ ;
F_6 ( & V_206 -> V_208 . V_209 ) ;
}
}
F_84 ( V_15 , 0 ) ;
F_80 ( V_15 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_77 * V_48 = V_15 -> V_48 ;
struct V_78 * V_79 = F_28 ( V_48 ) ;
F_8 ( & V_15 -> V_198 ) ;
if ( ! ( V_15 -> V_199 & V_202 ) ) {
F_6 ( & V_15 -> V_198 ) ;
return;
}
F_86 ( & V_15 -> V_216 ,
( F_87 () + V_79 -> V_217 * V_218 ) ) ;
F_6 ( & V_15 -> V_198 ) ;
}
void F_82 ( struct V_21 * V_15 )
{
struct V_77 * V_48 = V_15 -> V_48 ;
struct V_78 * V_79 = F_28 ( V_48 ) ;
F_8 ( & V_15 -> V_198 ) ;
if ( V_15 -> V_199 & V_202 ) {
F_6 ( & V_15 -> V_198 ) ;
return;
}
F_88 ( & V_15 -> V_216 ) ;
V_15 -> V_216 . V_219 =
( F_87 () + V_79 -> V_217 * V_218 ) ;
V_15 -> V_216 . V_197 = ( unsigned long ) V_15 ;
V_15 -> V_216 . V_51 = F_83 ;
V_15 -> V_199 &= ~ V_200 ;
V_15 -> V_199 |= V_202 ;
F_89 ( & V_15 -> V_216 ) ;
F_21 ( L_41
L_42 , V_15 -> V_131 , V_79 -> V_217 ) ;
F_6 ( & V_15 -> V_198 ) ;
}
void F_90 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_198 ) ;
if ( ! ( V_15 -> V_199 & V_202 ) ) {
F_6 ( & V_15 -> V_198 ) ;
return;
}
V_15 -> V_199 |= V_200 ;
F_6 ( & V_15 -> V_198 ) ;
F_91 ( & V_15 -> V_216 ) ;
F_8 ( & V_15 -> V_198 ) ;
V_15 -> V_199 &= ~ V_202 ;
F_6 ( & V_15 -> V_198 ) ;
}
static void F_92 ( unsigned long V_197 )
{
struct V_21 * V_15 = (struct V_21 * ) V_197 ;
F_77 ( V_15 ) ;
F_8 ( & V_15 -> V_198 ) ;
if ( V_15 -> V_220 & V_200 ) {
F_6 ( & V_15 -> V_198 ) ;
F_80 ( V_15 ) ;
return;
}
V_15 -> V_220 &= ~ V_202 ;
F_6 ( & V_15 -> V_198 ) ;
F_81 ( V_15 , 1 ) ;
F_80 ( V_15 ) ;
}
void F_93 ( struct V_21 * V_15 )
{
struct V_77 * V_48 = V_15 -> V_48 ;
struct V_78 * V_79 = F_28 ( V_48 ) ;
if ( ! V_79 -> V_221 )
return;
if ( V_15 -> V_220 & V_202 )
return;
F_88 ( & V_15 -> V_222 ) ;
V_15 -> V_222 . V_219 = ( F_87 () + V_79 -> V_221 * V_218 ) ;
V_15 -> V_222 . V_197 = ( unsigned long ) V_15 ;
V_15 -> V_222 . V_51 = F_92 ;
V_15 -> V_220 &= ~ V_200 ;
V_15 -> V_220 |= V_202 ;
F_89 ( & V_15 -> V_222 ) ;
F_21 ( L_43
L_44 , V_15 -> V_131 , V_79 -> V_221 ) ;
}
void F_94 ( struct V_21 * V_15 )
{
struct V_77 * V_48 = V_15 -> V_48 ;
struct V_78 * V_79 = F_28 ( V_48 ) ;
if ( ! V_79 -> V_221 )
return;
F_8 ( & V_15 -> V_198 ) ;
if ( V_15 -> V_220 & V_202 ) {
F_6 ( & V_15 -> V_198 ) ;
return;
}
F_88 ( & V_15 -> V_222 ) ;
V_15 -> V_222 . V_219 = ( F_87 () + V_79 -> V_221 * V_218 ) ;
V_15 -> V_222 . V_197 = ( unsigned long ) V_15 ;
V_15 -> V_222 . V_51 = F_92 ;
V_15 -> V_220 &= ~ V_200 ;
V_15 -> V_220 |= V_202 ;
F_89 ( & V_15 -> V_222 ) ;
F_21 ( L_43
L_44 , V_15 -> V_131 , V_79 -> V_221 ) ;
F_6 ( & V_15 -> V_198 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_198 ) ;
if ( ! ( V_15 -> V_220 & V_202 ) ) {
F_6 ( & V_15 -> V_198 ) ;
return;
}
V_15 -> V_220 |= V_200 ;
F_6 ( & V_15 -> V_198 ) ;
F_91 ( & V_15 -> V_222 ) ;
F_8 ( & V_15 -> V_198 ) ;
V_15 -> V_220 &= ~ V_202 ;
F_6 ( & V_15 -> V_198 ) ;
}
int F_96 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_223 )
{
int V_224 , V_225 ;
T_1 V_226 ;
struct V_227 * V_228 ;
V_229:
V_225 = V_2 -> V_225 ;
if ( ! V_223 ) {
V_228 = & V_2 -> V_157 [ 0 ] ;
V_226 = V_2 -> V_230 ;
} else {
V_228 = & V_2 -> V_231 [ 0 ] ;
V_226 = V_2 -> V_232 ;
}
V_224 = F_97 ( V_15 , & V_228 [ 0 ] , V_226 , V_225 ) ;
if ( V_225 != V_224 ) {
if ( V_224 == - V_233 ) {
F_3 ( L_45 ) ;
goto V_229;
} else
return - 1 ;
}
V_2 -> V_225 = 0 ;
return 0 ;
}
int F_98 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_234 * V_235 = V_2 -> V_236 ;
struct V_227 V_228 ;
T_1 V_237 , V_238 ;
T_1 V_3 = V_2 -> V_239 ;
int V_224 , V_240 ;
V_241:
V_237 = V_177 ;
if ( V_15 -> V_173 -> V_242 )
V_237 += V_243 ;
V_228 . V_244 = V_2 -> V_245 ;
V_228 . V_246 = V_237 ;
V_224 = F_97 ( V_15 , & V_228 , 1 , V_237 ) ;
if ( V_237 != V_224 ) {
if ( V_224 == - V_233 ) {
F_3 ( L_45 ) ;
goto V_241;
}
return - 1 ;
}
V_238 = V_2 -> V_225 - V_237 - V_2 -> V_247 ;
if ( V_15 -> V_173 -> V_248 ) {
V_238 -= V_243 ;
if ( V_2 -> V_247 )
V_240 = ( V_2 -> V_230 - 2 ) ;
else
V_240 = ( V_2 -> V_230 - 1 ) ;
} else {
V_240 = ( V_2 -> V_230 - 1 ) ;
}
while ( V_238 ) {
T_1 V_249 = ( V_235 -> V_17 - V_3 ) ;
T_1 V_250 = F_99 ( T_1 , V_238 , V_249 ) ;
V_251:
V_224 = V_15 -> V_252 -> V_253 -> V_254 ( V_15 -> V_252 ,
F_66 ( V_235 ) , V_235 -> V_3 + V_3 , V_250 , 0 ) ;
if ( V_224 != V_250 ) {
if ( V_224 == - V_233 ) {
F_3 ( L_46
L_47 ) ;
goto V_251;
}
F_3 ( L_48 ,
V_224 ) ;
return - 1 ;
}
V_238 -= V_250 ;
V_3 = 0 ;
V_235 = F_100 ( V_235 ) ;
}
V_255:
if ( V_2 -> V_247 ) {
struct V_227 * V_256 = & V_2 -> V_157 [ V_240 ++ ] ;
V_224 = F_97 ( V_15 , V_256 , 1 , V_2 -> V_247 ) ;
if ( V_2 -> V_247 != V_224 ) {
if ( V_224 == - V_233 ) {
F_3 ( L_45 ) ;
goto V_255;
}
return - 1 ;
}
}
V_257:
if ( V_15 -> V_173 -> V_248 ) {
struct V_227 * V_258 = & V_2 -> V_157 [ V_240 ] ;
V_224 = F_97 ( V_15 , V_258 , 1 , V_243 ) ;
if ( V_243 != V_224 ) {
if ( V_224 == - V_233 ) {
F_3 ( L_45 ) ;
goto V_257;
}
return - 1 ;
}
}
return 0 ;
}
int F_101 ( struct V_21 * V_15 , T_3 V_259 , T_3 V_260 )
{
T_3 V_261 [ V_177 ] ;
int V_262 ;
struct V_227 V_228 ;
struct V_263 * V_120 ;
F_102 ( V_15 , V_259 , V_260 ) ;
memset ( & V_228 , 0 , sizeof( struct V_227 ) ) ;
memset ( & V_261 , 0x0 , V_177 ) ;
V_120 = (struct V_263 * ) & V_261 ;
V_120 -> V_264 = V_265 ;
V_120 -> V_259 = V_259 ;
V_120 -> V_260 = V_260 ;
V_120 -> V_266 = F_103 ( V_15 -> V_267 ) ;
V_228 . V_244 = & V_261 ;
V_228 . V_246 = V_177 ;
F_104 ( V_261 , V_177 ) ;
V_262 = F_97 ( V_15 , & V_228 , 1 , V_177 ) ;
if ( V_262 != V_177 ) {
F_3 ( L_49 ) ;
return - 1 ;
}
return 0 ;
}
void F_105 ( struct V_77 * V_48 )
{
struct V_21 * V_15 ;
F_21 ( L_50
L_51 , V_48 -> V_201 ) ;
F_8 ( & V_48 -> V_182 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_106 ( V_15 -> V_173 ) ;
F_6 ( & V_48 -> V_182 ) ;
F_107 ( V_48 -> V_80 ) ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_268 * V_269 )
{
int V_197 = V_269 -> V_31 , V_270 = 0 , V_271 = 0 , V_246 ;
struct V_227 * V_256 ;
struct V_272 V_273 ;
if ( ! V_15 || ! V_15 -> V_252 || ! V_15 -> V_173 )
return - 1 ;
memset ( & V_273 , 0 , sizeof( struct V_272 ) ) ;
V_256 = V_269 -> V_228 ;
V_246 = V_269 -> V_226 ;
while ( V_271 < V_197 ) {
V_270 = F_109 ( V_15 -> V_252 , & V_273 , V_256 , V_246 ,
( V_197 - V_271 ) , V_274 ) ;
if ( V_270 <= 0 ) {
F_21 ( L_52 ,
V_270 , V_271 ) ;
return V_270 ;
}
V_271 += V_270 ;
F_21 ( L_53 ,
V_270 , V_271 , V_197 ) ;
}
return V_271 ;
}
static int F_110 (
struct V_21 * V_15 ,
struct V_268 * V_269 )
{
int V_197 = V_269 -> V_31 , V_275 = 0 , V_276 = 0 , V_246 ;
struct V_227 * V_256 ;
struct V_272 V_273 ;
if ( ! V_15 || ! V_15 -> V_252 || ! V_15 -> V_173 )
return - 1 ;
if ( V_197 <= 0 ) {
F_3 ( L_54 , V_197 ) ;
return - 1 ;
}
memset ( & V_273 , 0 , sizeof( struct V_272 ) ) ;
V_256 = V_269 -> V_228 ;
V_246 = V_269 -> V_226 ;
while ( V_275 < V_197 ) {
V_276 = F_111 ( V_15 -> V_252 , & V_273 , V_256 , V_246 ,
( V_197 - V_275 ) ) ;
if ( V_276 <= 0 ) {
F_21 ( L_55 ,
V_276 , V_275 ) ;
return V_276 ;
}
V_275 += V_276 ;
F_21 ( L_56 ,
V_276 , V_275 , V_197 ) ;
}
return V_275 ;
}
int F_112 (
struct V_21 * V_15 ,
struct V_227 * V_228 ,
int V_226 ,
int V_197 )
{
struct V_268 V_277 ;
if ( ! V_15 || ! V_15 -> V_252 || ! V_15 -> V_173 )
return - 1 ;
memset ( & V_277 , 0 , sizeof( struct V_268 ) ) ;
V_277 . V_228 = V_228 ;
V_277 . V_226 = V_226 ;
V_277 . V_31 = V_197 ;
V_277 . type = V_278 ;
return F_108 ( V_15 , & V_277 ) ;
}
int F_97 (
struct V_21 * V_15 ,
struct V_227 * V_228 ,
int V_226 ,
int V_197 )
{
struct V_268 V_277 ;
if ( ! V_15 || ! V_15 -> V_252 || ! V_15 -> V_173 )
return - 1 ;
memset ( & V_277 , 0 , sizeof( struct V_268 ) ) ;
V_277 . V_228 = V_228 ;
V_277 . V_226 = V_226 ;
V_277 . V_31 = V_197 ;
V_277 . type = V_279 ;
return F_110 ( V_15 , & V_277 ) ;
}
void F_102 (
struct V_21 * V_15 ,
T_3 V_259 ,
T_3 V_260 )
{
struct V_280 * V_281 = NULL ;
struct V_205 * V_206 ;
struct V_282 * V_283 ;
V_206 = F_113 ( V_15 ) ;
if ( ! V_206 )
return;
V_283 = & V_206 -> V_284 ;
F_50 ( & V_283 -> V_209 ) ;
if ( ! strcmp ( V_15 -> V_285 , V_283 -> V_286 ) &&
( ( F_87 () - V_283 -> V_287 ) < 10 ) ) {
F_51 ( & V_283 -> V_209 ) ;
return;
}
if ( V_259 == V_288 )
V_283 -> V_289 ++ ;
else if ( V_259 == V_290 ) {
V_283 -> V_291 ++ ;
V_283 -> V_292 = V_293 ;
} else if ( ( V_259 == V_294 ) &&
( V_260 == V_295 ) ) {
V_283 -> V_296 ++ ;
V_283 -> V_292 = V_297 ;
} else if ( ( V_259 == V_294 ) &&
( V_260 == V_298 ) ) {
V_283 -> V_299 ++ ;
V_283 -> V_292 = V_300 ;
} else if ( ( V_259 == V_294 ) &&
( V_260 == V_301 ) ) {
V_283 -> V_302 ++ ;
V_283 -> V_292 = V_303 ;
} else {
V_283 -> V_304 ++ ;
V_283 -> V_292 = V_305 ;
}
if ( V_259 != V_288 ) {
if ( V_15 -> V_306 )
V_281 = F_114 ( V_307 ,
V_15 -> V_306 ) ;
strcpy ( V_283 -> V_308 ,
( V_281 ? V_281 -> V_309 : L_57 ) ) ;
V_283 -> V_310 = V_15 -> V_252 -> V_311 -> V_312 ;
snprintf ( V_283 -> V_286 , V_313 ,
L_58 , V_15 -> V_285 ) ;
V_283 -> V_287 = F_87 () ;
}
F_51 ( & V_283 -> V_209 ) ;
}
struct V_205 * F_113 ( struct V_21 * V_15 )
{
struct V_203 * V_204 ;
if ( ! V_15 || ! V_15 -> V_48 )
return NULL ;
V_204 = V_15 -> V_48 -> V_204 ;
if ( ! V_204 )
return NULL ;
if ( ! V_204 -> V_207 )
return NULL ;
return V_204 -> V_207 ;
}
