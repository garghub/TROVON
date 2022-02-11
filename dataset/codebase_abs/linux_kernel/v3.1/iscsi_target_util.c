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
T_3 V_52 ;
V_2 = F_17 ( V_15 , V_36 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_32 = V_53 ;
V_2 -> V_54 = F_24 ( sizeof( struct V_55 ) , V_36 ) ;
if ( ! V_2 -> V_54 ) {
F_3 ( L_9
L_10 ) ;
goto V_56;
}
if ( V_51 == V_57 )
return V_2 ;
V_34 = & V_2 -> V_34 ;
F_22 ( V_34 , & V_46 -> V_47 ,
V_15 -> V_48 -> V_49 , 0 , V_53 ,
V_39 , & V_2 -> V_50 [ 0 ] ) ;
switch ( V_51 ) {
case V_58 :
V_52 = V_59 ;
break;
case V_60 :
V_52 = V_61 ;
break;
case V_62 :
V_52 = V_63 ;
break;
case V_64 :
V_52 = V_65 ;
break;
case V_66 :
V_52 = V_67 ;
break;
case V_68 :
V_52 = V_69 ;
break;
case V_70 :
V_52 = V_71 ;
break;
default:
F_3 ( L_11
L_12 , V_51 ) ;
goto V_56;
}
V_34 -> V_72 = F_25 ( V_34 ,
( void * ) V_2 -> V_54 , V_52 ) ;
if ( ! V_34 -> V_72 )
goto V_56;
V_2 -> V_54 -> V_72 = V_34 -> V_72 ;
return V_2 ;
V_56:
F_26 ( V_2 ) ;
return NULL ;
}
int F_27 (
struct V_1 * V_2 ,
T_1 V_73 )
{
struct V_74 V_75 ;
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 ;
if ( V_48 -> V_79 -> V_80 &&
V_48 -> V_79 -> V_81 )
return 0 ;
if ( V_2 -> V_32 == V_53 )
return 0 ;
V_78 = F_28 ( V_48 ) ;
memset ( & V_75 , 0 , sizeof( struct V_74 ) ) ;
if ( V_2 -> V_32 == V_82 ) {
V_75 . V_32 = V_83 ;
V_75 . type = V_84 ;
if ( V_78 -> V_85 )
V_75 . V_86 |= V_87 ;
if ( V_78 -> V_88 )
V_75 . V_86 |= V_89 ;
} else {
V_75 . V_32 = V_90 ;
V_75 . V_73 = V_73 ;
if ( V_78 -> V_91 )
V_75 . V_86 |= V_92 ;
if ( ! V_2 -> V_93 && ! V_2 -> V_94 )
V_75 . type = V_84 ;
else if ( V_2 -> V_93 && ! V_2 -> V_94 )
V_75 . type = V_95 ;
else if ( ! V_2 -> V_93 && V_2 -> V_94 )
V_75 . type = V_96 ;
else if ( V_2 -> V_93 && V_2 -> V_94 )
V_75 . type = V_97 ;
}
return F_29 ( V_2 , & V_75 ) ;
}
struct V_98 * F_30 (
struct V_1 * V_2 ,
T_1 V_99 )
{
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_101 ; V_100 ++ )
if ( V_2 -> V_102 [ V_100 ] . V_99 == V_99 )
return & V_2 -> V_102 [ V_100 ] ;
return NULL ;
}
struct V_98 * F_31 ( struct V_1 * V_2 )
{
T_1 V_100 ;
if ( ! V_2 -> V_102 ) {
F_3 ( L_13 ) ;
return NULL ;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_101 ; V_100 ++ ) {
if ( V_2 -> V_102 [ V_100 ] . type != V_103 )
continue;
if ( V_2 -> V_102 [ V_100 ] . V_99 == V_2 -> V_99 ) {
V_2 -> V_99 ++ ;
return & V_2 -> V_102 [ V_100 ] ;
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
static inline int F_33 ( struct V_76 * V_48 , T_1 V_104 )
{
int V_105 ;
if ( F_34 ( V_104 , V_48 -> V_106 ) ) {
F_3 ( L_14
L_15 , V_104 ,
V_48 -> V_106 ) ;
V_105 = V_107 ;
} else if ( V_104 == V_48 -> V_108 ) {
V_48 -> V_108 ++ ;
F_21 ( L_16
L_17 ,
V_48 -> V_108 ) ;
V_105 = V_109 ;
} else if ( F_34 ( V_104 , V_48 -> V_108 ) ) {
F_21 ( L_18
L_19 ,
V_104 , V_48 -> V_108 ) ;
V_105 = V_110 ;
} else {
F_3 ( L_20
L_21 , V_104 ,
V_48 -> V_108 ) ;
V_105 = V_111 ;
}
return V_105 ;
}
int F_35 (
struct V_21 * V_15 ,
struct V_1 * V_2 ,
T_1 V_104 )
{
int V_105 ;
int V_112 ;
F_36 ( & V_15 -> V_48 -> V_113 ) ;
V_112 = F_33 ( V_15 -> V_48 , V_104 ) ;
switch ( V_112 ) {
case V_109 :
V_105 = F_37 ( V_2 , 0 ) ;
if ( ( V_105 >= 0 ) && ! F_38 ( & V_15 -> V_48 -> V_114 ) )
F_39 ( V_15 -> V_48 ) ;
break;
case V_110 :
V_105 = F_40 ( V_15 -> V_48 , V_2 , V_104 ) ;
break;
case V_111 :
V_2 -> V_115 = V_116 ;
F_7 ( V_2 , V_15 , V_2 -> V_115 ) ;
V_105 = V_112 ;
break;
default:
V_105 = V_112 ;
break;
}
F_41 ( & V_15 -> V_48 -> V_113 ) ;
return V_105 ;
}
int F_42 ( struct V_1 * V_2 , unsigned char * V_117 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_34 * V_34 = & V_2 -> V_34 ;
struct V_118 * V_119 = (struct V_118 * ) V_117 ;
T_1 V_120 = F_43 ( V_119 -> V_121 ) ;
if ( V_15 -> V_48 -> V_79 -> V_122 ) {
F_3 ( L_22
L_23 ) ;
F_44 ( V_34 ,
V_123 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_124 + V_120 ) >
V_15 -> V_48 -> V_79 -> V_125 ) {
F_3 ( L_24
L_25 ,
( V_2 -> V_124 + V_120 ) ,
V_15 -> V_48 -> V_79 -> V_125 ) ;
F_44 ( V_34 ,
V_126 , 0 ) ;
return - 1 ;
}
if ( ! ( V_119 -> V_127 & V_128 ) )
return 0 ;
if ( ( ( V_2 -> V_124 + V_120 ) != V_2 -> V_31 ) &&
( ( V_2 -> V_124 + V_120 ) !=
V_15 -> V_48 -> V_79 -> V_125 ) ) {
F_3 ( L_26
L_27
L_28 ,
( V_2 -> V_124 + V_120 ) ,
V_15 -> V_48 -> V_79 -> V_125 , V_2 -> V_31 ) ;
F_44 ( V_34 ,
V_126 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_45 (
struct V_21 * V_15 ,
T_1 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_129 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_129 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_129 ) ;
F_3 ( L_29 ,
V_19 , V_15 -> V_130 ) ;
return NULL ;
}
struct V_1 * F_46 (
struct V_21 * V_15 ,
T_1 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_129 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_129 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_129 ) ;
F_3 ( L_30
L_31 , V_19 , V_15 -> V_130 ) ;
if ( V_17 )
F_47 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_48 (
struct V_21 * V_15 ,
T_1 V_131 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_129 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_2 -> V_131 == V_131 ) {
F_6 ( & V_15 -> V_129 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_129 ) ;
F_3 ( L_32 ,
V_131 , V_15 -> V_130 ) ;
return NULL ;
}
int F_49 (
struct V_76 * V_48 ,
struct V_1 * * V_132 ,
struct V_133 * * V_134 ,
T_1 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_133 * V_135 ;
F_50 ( & V_48 -> V_136 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_50 ( & V_135 -> V_137 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_51 ( & V_135 -> V_137 ) ;
F_51 ( & V_48 -> V_136 ) ;
* V_134 = V_135 ;
* V_132 = V_2 ;
return - 2 ;
}
}
F_51 ( & V_135 -> V_137 ) ;
}
F_51 ( & V_48 -> V_136 ) ;
F_50 ( & V_48 -> V_138 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_50 ( & V_135 -> V_137 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_list) {
if ( V_2 -> V_19 == V_19 ) {
F_51 ( & V_135 -> V_137 ) ;
F_51 ( & V_48 -> V_138 ) ;
* V_134 = V_135 ;
* V_132 = V_2 ;
return 0 ;
}
}
F_51 ( & V_135 -> V_137 ) ;
}
F_51 ( & V_48 -> V_138 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_139 )
{
struct V_140 * V_141 ;
V_141 = F_2 ( V_142 , V_10 ) ;
if ( ! V_141 ) {
F_3 ( L_9
L_33 ) ;
return;
}
F_4 ( & V_141 -> V_143 ) ;
V_141 -> V_2 = V_2 ;
V_141 -> V_139 = V_139 ;
F_8 ( & V_15 -> V_144 ) ;
F_5 ( & V_141 -> V_143 , & V_15 -> V_145 ) ;
F_52 ( & V_2 -> V_146 ) ;
F_53 ( & V_15 -> V_147 , 1 ) ;
F_6 ( & V_15 -> V_144 ) ;
F_54 ( V_15 -> V_148 -> V_149 ) ;
}
struct V_140 * F_55 ( struct V_21 * V_15 )
{
struct V_140 * V_141 ;
F_8 ( & V_15 -> V_144 ) ;
if ( F_38 ( & V_15 -> V_145 ) ) {
F_6 ( & V_15 -> V_144 ) ;
return NULL ;
}
F_10 (qr, &conn->immed_queue_list, qr_list)
break;
F_13 ( & V_141 -> V_143 ) ;
if ( V_141 -> V_2 )
F_56 ( & V_141 -> V_2 -> V_146 ) ;
F_6 ( & V_15 -> V_144 ) ;
return V_141 ;
}
static void F_57 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_140 * V_141 , * V_150 ;
F_8 ( & V_15 -> V_144 ) ;
if ( ! F_58 ( & V_2 -> V_146 ) ) {
F_6 ( & V_15 -> V_144 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_141 -> V_2 != V_2 )
continue;
F_56 ( & V_141 -> V_2 -> V_146 ) ;
F_13 ( & V_141 -> V_143 ) ;
F_14 ( V_142 , V_141 ) ;
}
F_6 ( & V_15 -> V_144 ) ;
if ( F_58 ( & V_2 -> V_146 ) ) {
F_3 ( L_34 ,
V_2 -> V_19 ,
F_58 ( & V_2 -> V_146 ) ) ;
}
}
void F_59 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_139 )
{
struct V_140 * V_141 ;
V_141 = F_2 ( V_142 , V_10 ) ;
if ( ! V_141 ) {
F_3 ( L_9
L_33 ) ;
return;
}
F_4 ( & V_141 -> V_143 ) ;
V_141 -> V_2 = V_2 ;
V_141 -> V_139 = V_139 ;
F_8 ( & V_15 -> V_151 ) ;
F_5 ( & V_141 -> V_143 , & V_15 -> V_152 ) ;
F_52 ( & V_2 -> V_153 ) ;
F_6 ( & V_15 -> V_151 ) ;
F_54 ( V_15 -> V_148 -> V_149 ) ;
}
struct V_140 * F_60 ( struct V_21 * V_15 )
{
struct V_140 * V_141 ;
F_8 ( & V_15 -> V_151 ) ;
if ( F_38 ( & V_15 -> V_152 ) ) {
F_6 ( & V_15 -> V_151 ) ;
return NULL ;
}
F_10 (qr, &conn->response_queue_list, qr_list)
break;
F_13 ( & V_141 -> V_143 ) ;
if ( V_141 -> V_2 )
F_56 ( & V_141 -> V_2 -> V_153 ) ;
F_6 ( & V_15 -> V_151 ) ;
return V_141 ;
}
static void F_61 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_140 * V_141 , * V_150 ;
F_8 ( & V_15 -> V_151 ) ;
if ( ! F_58 ( & V_2 -> V_153 ) ) {
F_6 ( & V_15 -> V_151 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_141 -> V_2 != V_2 )
continue;
F_56 ( & V_141 -> V_2 -> V_153 ) ;
F_13 ( & V_141 -> V_143 ) ;
F_14 ( V_142 , V_141 ) ;
}
F_6 ( & V_15 -> V_151 ) ;
if ( F_58 ( & V_2 -> V_153 ) ) {
F_3 ( L_35 ,
V_2 -> V_19 ,
F_58 ( & V_2 -> V_153 ) ) ;
}
}
void F_62 ( struct V_21 * V_15 )
{
struct V_140 * V_141 , * V_150 ;
F_8 ( & V_15 -> V_144 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_141 -> V_143 ) ;
if ( V_141 -> V_2 )
F_56 ( & V_141 -> V_2 -> V_146 ) ;
F_14 ( V_142 , V_141 ) ;
}
F_6 ( & V_15 -> V_144 ) ;
F_8 ( & V_15 -> V_151 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_141 -> V_143 ) ;
if ( V_141 -> V_2 )
F_56 ( & V_141 -> V_2 -> V_153 ) ;
F_14 ( V_142 , V_141 ) ;
}
F_6 ( & V_15 -> V_151 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
int V_100 ;
F_15 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 -> V_154 ) ;
F_64 ( V_2 -> V_155 ) ;
F_64 ( V_2 -> V_102 ) ;
F_64 ( V_2 -> V_54 ) ;
F_64 ( V_2 -> V_156 ) ;
for ( V_100 = 0 ; V_100 < V_2 -> V_157 ; V_100 ++ )
F_65 ( F_66 ( & V_2 -> V_158 [ V_100 ] ) ) ;
F_64 ( V_2 -> V_158 ) ;
if ( V_15 ) {
F_57 ( V_2 , V_15 ) ;
F_61 ( V_2 , V_15 ) ;
}
F_14 ( V_23 , V_2 ) ;
}
int F_67 ( struct V_76 * V_48 )
{
F_8 ( & V_48 -> V_159 ) ;
if ( V_48 -> V_160 != 0 ) {
V_48 -> V_161 = 1 ;
F_6 ( & V_48 -> V_159 ) ;
if ( F_68 () )
return 2 ;
F_69 ( & V_48 -> V_162 ) ;
return 1 ;
}
F_6 ( & V_48 -> V_159 ) ;
return 0 ;
}
void F_70 ( struct V_76 * V_48 )
{
F_8 ( & V_48 -> V_159 ) ;
V_48 -> V_160 -- ;
if ( ! V_48 -> V_160 && V_48 -> V_161 )
F_71 ( & V_48 -> V_162 ) ;
F_6 ( & V_48 -> V_159 ) ;
}
void F_72 ( struct V_76 * V_48 )
{
F_8 ( & V_48 -> V_159 ) ;
V_48 -> V_160 ++ ;
F_6 ( & V_48 -> V_159 ) ;
}
int F_73 ( struct V_21 * V_15 )
{
int V_163 = 0 , V_164 = 0 , V_165 = 0 ;
T_1 V_166 = ( V_15 -> V_167 -> V_166 * 4 ) ;
T_1 V_168 = ( V_15 -> V_167 -> V_168 * 4 ) ;
if ( V_15 -> V_167 -> V_169 ) {
V_15 -> V_170 += V_171 ;
if ( V_15 -> V_170 <= V_168 ) {
V_15 -> V_170 = ( V_168 - V_15 -> V_170 ) ;
} else {
V_164 = ( V_15 -> V_170 / V_168 ) ;
V_165 = ( V_168 * ( V_164 + 1 ) ) +
( V_164 * V_172 ) ;
V_15 -> V_170 = ( V_165 - V_15 -> V_170 ) ;
}
V_15 -> V_173 = 0 ;
F_21 ( L_36
L_37 , V_15 -> V_170 ) ;
}
if ( V_15 -> V_167 -> V_174 ) {
if ( V_15 -> V_175 <= V_166 ) {
V_15 -> V_175 = ( V_166 - V_15 -> V_175 ) ;
} else {
V_163 = ( V_15 -> V_175 / V_166 ) ;
V_165 = ( V_166 * ( V_163 + 1 ) ) +
( V_163 * V_172 ) ;
V_15 -> V_175 = ( V_165 - V_15 -> V_175 ) ;
}
F_21 ( L_38
L_37 , V_15 -> V_175 ) ;
}
return 0 ;
}
struct V_21 * F_74 ( struct V_76 * V_48 , T_4 V_130 )
{
struct V_21 * V_15 ;
F_8 ( & V_48 -> V_176 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_130 == V_130 ) &&
( V_15 -> V_177 == V_178 ) ) {
F_75 ( V_15 ) ;
F_6 ( & V_48 -> V_176 ) ;
return V_15 ;
}
}
F_6 ( & V_48 -> V_176 ) ;
return NULL ;
}
struct V_21 * F_76 ( struct V_76 * V_48 , T_4 V_130 )
{
struct V_21 * V_15 ;
F_8 ( & V_48 -> V_176 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_130 == V_130 ) {
F_75 ( V_15 ) ;
F_50 ( & V_15 -> V_179 ) ;
F_53 ( & V_15 -> V_180 , 1 ) ;
F_51 ( & V_15 -> V_179 ) ;
F_6 ( & V_48 -> V_176 ) ;
return V_15 ;
}
}
F_6 ( & V_48 -> V_176 ) ;
return NULL ;
}
void F_77 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_181 ) ;
if ( V_15 -> V_182 != 0 ) {
V_15 -> V_183 = 1 ;
F_6 ( & V_15 -> V_181 ) ;
F_69 ( & V_15 -> V_184 ) ;
return;
}
F_6 ( & V_15 -> V_181 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_181 ) ;
V_15 -> V_182 -- ;
if ( ! V_15 -> V_182 && V_15 -> V_183 )
F_71 ( & V_15 -> V_184 ) ;
F_6 ( & V_15 -> V_181 ) ;
}
void F_75 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_181 ) ;
V_15 -> V_182 ++ ;
F_6 ( & V_15 -> V_181 ) ;
}
static int F_79 ( struct V_21 * V_15 , int V_185 )
{
T_3 V_139 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_186 = V_187 ;
V_139 = ( V_185 ) ? V_188 :
V_189 ;
V_2 -> V_19 = 0xFFFFFFFF ;
F_8 ( & V_15 -> V_48 -> V_190 ) ;
V_2 -> V_131 = ( V_185 ) ? V_15 -> V_48 -> V_131 ++ :
0xFFFFFFFF ;
if ( V_185 && ( V_2 -> V_131 == 0xFFFFFFFF ) )
V_2 -> V_131 = V_15 -> V_48 -> V_131 ++ ;
F_6 ( & V_15 -> V_48 -> V_190 ) ;
F_8 ( & V_15 -> V_129 ) ;
F_5 ( & V_2 -> V_24 , & V_15 -> V_191 ) ;
F_6 ( & V_15 -> V_129 ) ;
if ( V_185 )
F_80 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_139 ) ;
return 0 ;
}
static void F_81 ( unsigned long V_192 )
{
struct V_21 * V_15 = (struct V_21 * ) V_192 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_193 ) ;
if ( V_15 -> V_194 & V_195 ) {
F_6 ( & V_15 -> V_193 ) ;
F_78 ( V_15 ) ;
return;
}
F_21 ( L_39
L_40 , V_15 -> V_130 ,
V_15 -> V_48 -> V_196 ) ;
V_15 -> V_194 &= ~ V_197 ;
F_6 ( & V_15 -> V_193 ) ;
{
struct V_198 * V_199 = V_15 -> V_48 -> V_199 ;
struct V_200 * V_201 = V_199 -> V_202 ;
if ( V_201 ) {
F_8 ( & V_201 -> V_203 . V_204 ) ;
strcpy ( V_201 -> V_203 . V_205 ,
( void * ) V_15 -> V_48 -> V_79 -> V_206 ) ;
V_201 -> V_203 . V_207 =
V_208 ;
V_201 -> V_203 . V_209 ++ ;
V_15 -> V_48 -> V_210 ++ ;
F_6 ( & V_201 -> V_203 . V_204 ) ;
}
}
F_82 ( V_15 , 0 ) ;
F_78 ( V_15 ) ;
}
void F_83 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
F_8 ( & V_15 -> V_193 ) ;
if ( ! ( V_15 -> V_194 & V_197 ) ) {
F_6 ( & V_15 -> V_193 ) ;
return;
}
F_84 ( & V_15 -> V_211 ,
( F_85 () + V_78 -> V_212 * V_213 ) ) ;
F_6 ( & V_15 -> V_193 ) ;
}
void F_80 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
F_8 ( & V_15 -> V_193 ) ;
if ( V_15 -> V_194 & V_197 ) {
F_6 ( & V_15 -> V_193 ) ;
return;
}
F_86 ( & V_15 -> V_211 ) ;
V_15 -> V_211 . V_214 =
( F_85 () + V_78 -> V_212 * V_213 ) ;
V_15 -> V_211 . V_192 = ( unsigned long ) V_15 ;
V_15 -> V_211 . V_51 = F_81 ;
V_15 -> V_194 &= ~ V_195 ;
V_15 -> V_194 |= V_197 ;
F_87 ( & V_15 -> V_211 ) ;
F_21 ( L_41
L_42 , V_15 -> V_130 , V_78 -> V_212 ) ;
F_6 ( & V_15 -> V_193 ) ;
}
void F_88 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_193 ) ;
if ( ! ( V_15 -> V_194 & V_197 ) ) {
F_6 ( & V_15 -> V_193 ) ;
return;
}
V_15 -> V_194 |= V_195 ;
F_6 ( & V_15 -> V_193 ) ;
F_89 ( & V_15 -> V_211 ) ;
F_8 ( & V_15 -> V_193 ) ;
V_15 -> V_194 &= ~ V_197 ;
F_6 ( & V_15 -> V_193 ) ;
}
static void F_90 ( unsigned long V_192 )
{
struct V_21 * V_15 = (struct V_21 * ) V_192 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_193 ) ;
if ( V_15 -> V_215 & V_195 ) {
F_6 ( & V_15 -> V_193 ) ;
F_78 ( V_15 ) ;
return;
}
V_15 -> V_215 &= ~ V_197 ;
F_6 ( & V_15 -> V_193 ) ;
F_79 ( V_15 , 1 ) ;
F_78 ( V_15 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
if ( ! V_78 -> V_216 )
return;
if ( V_15 -> V_215 & V_197 )
return;
F_86 ( & V_15 -> V_217 ) ;
V_15 -> V_217 . V_214 = ( F_85 () + V_78 -> V_216 * V_213 ) ;
V_15 -> V_217 . V_192 = ( unsigned long ) V_15 ;
V_15 -> V_217 . V_51 = F_90 ;
V_15 -> V_215 &= ~ V_195 ;
V_15 -> V_215 |= V_197 ;
F_87 ( & V_15 -> V_217 ) ;
F_21 ( L_43
L_44 , V_15 -> V_130 , V_78 -> V_216 ) ;
}
void F_92 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
if ( ! V_78 -> V_216 )
return;
F_8 ( & V_15 -> V_193 ) ;
if ( V_15 -> V_215 & V_197 ) {
F_6 ( & V_15 -> V_193 ) ;
return;
}
F_86 ( & V_15 -> V_217 ) ;
V_15 -> V_217 . V_214 = ( F_85 () + V_78 -> V_216 * V_213 ) ;
V_15 -> V_217 . V_192 = ( unsigned long ) V_15 ;
V_15 -> V_217 . V_51 = F_90 ;
V_15 -> V_215 &= ~ V_195 ;
V_15 -> V_215 |= V_197 ;
F_87 ( & V_15 -> V_217 ) ;
F_21 ( L_43
L_44 , V_15 -> V_130 , V_78 -> V_216 ) ;
F_6 ( & V_15 -> V_193 ) ;
}
void F_93 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_193 ) ;
if ( ! ( V_15 -> V_215 & V_197 ) ) {
F_6 ( & V_15 -> V_193 ) ;
return;
}
V_15 -> V_215 |= V_195 ;
F_6 ( & V_15 -> V_193 ) ;
F_89 ( & V_15 -> V_217 ) ;
F_8 ( & V_15 -> V_193 ) ;
V_15 -> V_215 &= ~ V_197 ;
F_6 ( & V_15 -> V_193 ) ;
}
int F_94 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_218 )
{
int V_219 , V_220 ;
T_1 V_221 ;
struct V_222 * V_223 ;
V_224:
V_220 = V_2 -> V_220 ;
if ( ! V_218 ) {
V_223 = & V_2 -> V_156 [ 0 ] ;
V_221 = V_2 -> V_225 ;
} else {
V_223 = & V_2 -> V_226 [ 0 ] ;
V_221 = V_2 -> V_227 ;
}
V_219 = F_95 ( V_15 , & V_223 [ 0 ] , V_221 , V_220 ) ;
if ( V_220 != V_219 ) {
if ( V_219 == - V_228 ) {
F_3 ( L_45 ) ;
goto V_224;
} else
return - 1 ;
}
V_2 -> V_220 = 0 ;
return 0 ;
}
int F_96 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_229 * V_230 = V_2 -> V_231 ;
struct V_222 V_223 ;
T_1 V_232 , V_233 ;
T_1 V_3 = V_2 -> V_234 ;
int V_219 , V_235 ;
V_236:
V_232 = V_171 ;
if ( V_15 -> V_167 -> V_237 )
V_232 += V_238 ;
V_223 . V_239 = V_2 -> V_240 ;
V_223 . V_241 = V_232 ;
V_219 = F_95 ( V_15 , & V_223 , 1 , V_232 ) ;
if ( V_232 != V_219 ) {
if ( V_219 == - V_228 ) {
F_3 ( L_45 ) ;
goto V_236;
}
return - 1 ;
}
V_233 = V_2 -> V_220 - V_232 - V_2 -> V_242 ;
if ( V_15 -> V_167 -> V_243 ) {
V_233 -= V_238 ;
if ( V_2 -> V_242 )
V_235 = ( V_2 -> V_225 - 2 ) ;
else
V_235 = ( V_2 -> V_225 - 1 ) ;
} else {
V_235 = ( V_2 -> V_225 - 1 ) ;
}
while ( V_233 ) {
T_1 V_244 = ( V_230 -> V_17 - V_3 ) ;
T_1 V_245 = F_97 ( T_1 , V_233 , V_244 ) ;
V_246:
V_219 = V_15 -> V_247 -> V_248 -> V_249 ( V_15 -> V_247 ,
F_66 ( V_230 ) , V_230 -> V_3 + V_3 , V_245 , 0 ) ;
if ( V_219 != V_245 ) {
if ( V_219 == - V_228 ) {
F_3 ( L_46
L_47 ) ;
goto V_246;
}
F_3 ( L_48 ,
V_219 ) ;
return - 1 ;
}
V_233 -= V_245 ;
V_3 = 0 ;
V_230 = F_98 ( V_230 ) ;
}
V_250:
if ( V_2 -> V_242 ) {
struct V_222 * V_251 = & V_2 -> V_156 [ V_235 ++ ] ;
V_219 = F_95 ( V_15 , V_251 , 1 , V_2 -> V_242 ) ;
if ( V_2 -> V_242 != V_219 ) {
if ( V_219 == - V_228 ) {
F_3 ( L_45 ) ;
goto V_250;
}
return - 1 ;
}
}
V_252:
if ( V_15 -> V_167 -> V_243 ) {
struct V_222 * V_253 = & V_2 -> V_156 [ V_235 ] ;
V_219 = F_95 ( V_15 , V_253 , 1 , V_238 ) ;
if ( V_238 != V_219 ) {
if ( V_219 == - V_228 ) {
F_3 ( L_45 ) ;
goto V_252;
}
return - 1 ;
}
}
return 0 ;
}
int F_99 ( struct V_21 * V_15 , T_3 V_254 , T_3 V_255 )
{
T_3 V_256 [ V_171 ] ;
int V_257 ;
struct V_222 V_223 ;
struct V_258 * V_119 ;
F_100 ( V_15 , V_254 , V_255 ) ;
memset ( & V_223 , 0 , sizeof( struct V_222 ) ) ;
memset ( & V_256 , 0x0 , V_171 ) ;
V_119 = (struct V_258 * ) & V_256 ;
V_119 -> V_259 = V_260 ;
V_119 -> V_254 = V_254 ;
V_119 -> V_255 = V_255 ;
V_119 -> V_261 = F_101 ( V_15 -> V_262 ) ;
V_223 . V_239 = & V_256 ;
V_223 . V_241 = V_171 ;
F_102 ( V_256 , V_171 ) ;
V_257 = F_95 ( V_15 , & V_223 , 1 , V_171 ) ;
if ( V_257 != V_171 ) {
F_3 ( L_49 ) ;
return - 1 ;
}
return 0 ;
}
void F_103 ( struct V_76 * V_48 )
{
struct V_21 * V_15 ;
F_21 ( L_50
L_51 , V_48 -> V_196 ) ;
F_8 ( & V_48 -> V_176 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_104 ( V_15 -> V_167 ) ;
F_6 ( & V_48 -> V_176 ) ;
F_105 ( V_48 -> V_79 ) ;
}
static int F_106 (
struct V_21 * V_15 ,
struct V_263 * V_264 )
{
int V_192 = V_264 -> V_31 , V_265 = 0 , V_266 = 0 , V_241 ;
struct V_222 * V_251 ;
struct V_267 V_268 ;
if ( ! V_15 || ! V_15 -> V_247 || ! V_15 -> V_167 )
return - 1 ;
memset ( & V_268 , 0 , sizeof( struct V_267 ) ) ;
V_251 = V_264 -> V_223 ;
V_241 = V_264 -> V_221 ;
while ( V_266 < V_192 ) {
V_265 = F_107 ( V_15 -> V_247 , & V_268 , V_251 , V_241 ,
( V_192 - V_266 ) , V_269 ) ;
if ( V_265 <= 0 ) {
F_21 ( L_52 ,
V_265 , V_266 ) ;
return V_265 ;
}
V_266 += V_265 ;
F_21 ( L_53 ,
V_265 , V_266 , V_192 ) ;
}
return V_266 ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_263 * V_264 )
{
int V_192 = V_264 -> V_31 , V_270 = 0 , V_271 = 0 , V_241 ;
struct V_222 * V_251 ;
struct V_267 V_268 ;
if ( ! V_15 || ! V_15 -> V_247 || ! V_15 -> V_167 )
return - 1 ;
if ( V_192 <= 0 ) {
F_3 ( L_54 , V_192 ) ;
return - 1 ;
}
memset ( & V_268 , 0 , sizeof( struct V_267 ) ) ;
V_251 = V_264 -> V_223 ;
V_241 = V_264 -> V_221 ;
while ( V_270 < V_192 ) {
V_271 = F_109 ( V_15 -> V_247 , & V_268 , V_251 , V_241 ,
( V_192 - V_270 ) ) ;
if ( V_271 <= 0 ) {
F_21 ( L_55 ,
V_271 , V_270 ) ;
return V_271 ;
}
V_270 += V_271 ;
F_21 ( L_56 ,
V_271 , V_270 , V_192 ) ;
}
return V_270 ;
}
int F_110 (
struct V_21 * V_15 ,
struct V_222 * V_223 ,
int V_221 ,
int V_192 )
{
struct V_263 V_272 ;
if ( ! V_15 || ! V_15 -> V_247 || ! V_15 -> V_167 )
return - 1 ;
memset ( & V_272 , 0 , sizeof( struct V_263 ) ) ;
V_272 . V_223 = V_223 ;
V_272 . V_221 = V_221 ;
V_272 . V_31 = V_192 ;
V_272 . type = V_273 ;
return F_106 ( V_15 , & V_272 ) ;
}
int F_95 (
struct V_21 * V_15 ,
struct V_222 * V_223 ,
int V_221 ,
int V_192 )
{
struct V_263 V_272 ;
if ( ! V_15 || ! V_15 -> V_247 || ! V_15 -> V_167 )
return - 1 ;
memset ( & V_272 , 0 , sizeof( struct V_263 ) ) ;
V_272 . V_223 = V_223 ;
V_272 . V_221 = V_221 ;
V_272 . V_31 = V_192 ;
V_272 . type = V_274 ;
return F_108 ( V_15 , & V_272 ) ;
}
void F_100 (
struct V_21 * V_15 ,
T_3 V_254 ,
T_3 V_255 )
{
struct V_275 * V_276 = NULL ;
struct V_200 * V_201 ;
struct V_277 * V_278 ;
V_201 = F_111 ( V_15 ) ;
if ( ! V_201 )
return;
V_278 = & V_201 -> V_279 ;
F_50 ( & V_278 -> V_204 ) ;
if ( ! strcmp ( V_15 -> V_280 , V_278 -> V_281 ) &&
( ( F_85 () - V_278 -> V_282 ) < 10 ) ) {
F_51 ( & V_278 -> V_204 ) ;
return;
}
if ( V_254 == V_283 )
V_278 -> V_284 ++ ;
else if ( V_254 == V_285 ) {
V_278 -> V_286 ++ ;
V_278 -> V_287 = V_288 ;
} else if ( ( V_254 == V_289 ) &&
( V_255 == V_290 ) ) {
V_278 -> V_291 ++ ;
V_278 -> V_287 = V_292 ;
} else if ( ( V_254 == V_289 ) &&
( V_255 == V_293 ) ) {
V_278 -> V_294 ++ ;
V_278 -> V_287 = V_295 ;
} else if ( ( V_254 == V_289 ) &&
( V_255 == V_296 ) ) {
V_278 -> V_297 ++ ;
V_278 -> V_287 = V_298 ;
} else {
V_278 -> V_299 ++ ;
V_278 -> V_287 = V_300 ;
}
if ( V_254 != V_283 ) {
if ( V_15 -> V_301 )
V_276 = F_112 ( V_302 ,
V_15 -> V_301 ) ;
strcpy ( V_278 -> V_303 ,
( V_276 ? V_276 -> V_304 : L_57 ) ) ;
V_278 -> V_305 = V_15 -> V_247 -> V_306 -> V_307 ;
snprintf ( V_278 -> V_281 , V_308 ,
L_58 , V_15 -> V_280 ) ;
V_278 -> V_282 = F_85 () ;
}
F_51 ( & V_278 -> V_204 ) ;
}
struct V_200 * F_111 ( struct V_21 * V_15 )
{
struct V_198 * V_199 ;
if ( ! V_15 || ! V_15 -> V_48 )
return NULL ;
V_199 = V_15 -> V_48 -> V_199 ;
if ( ! V_199 )
return NULL ;
if ( ! V_199 -> V_202 )
return NULL ;
return V_199 -> V_202 ;
}
