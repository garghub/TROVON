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
( void * ) V_2 -> V_54 , V_52 ,
V_36 ) ;
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
void F_67 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_159 ) {
case V_160 :
case V_161 :
F_68 ( & V_2 -> V_34 , 1 ) ;
break;
default:
F_26 ( V_2 ) ;
break;
}
}
int F_69 ( struct V_76 * V_48 )
{
F_8 ( & V_48 -> V_162 ) ;
if ( V_48 -> V_163 != 0 ) {
V_48 -> V_164 = 1 ;
F_6 ( & V_48 -> V_162 ) ;
if ( F_70 () )
return 2 ;
F_71 ( & V_48 -> V_165 ) ;
return 1 ;
}
F_6 ( & V_48 -> V_162 ) ;
return 0 ;
}
void F_72 ( struct V_76 * V_48 )
{
F_8 ( & V_48 -> V_162 ) ;
V_48 -> V_163 -- ;
if ( ! V_48 -> V_163 && V_48 -> V_164 )
F_73 ( & V_48 -> V_165 ) ;
F_6 ( & V_48 -> V_162 ) ;
}
void F_74 ( struct V_76 * V_48 )
{
F_8 ( & V_48 -> V_162 ) ;
V_48 -> V_163 ++ ;
F_6 ( & V_48 -> V_162 ) ;
}
int F_75 ( struct V_21 * V_15 )
{
int V_166 = 0 , V_167 = 0 , V_168 = 0 ;
T_1 V_169 = ( V_15 -> V_170 -> V_169 * 4 ) ;
T_1 V_171 = ( V_15 -> V_170 -> V_171 * 4 ) ;
if ( V_15 -> V_170 -> V_172 ) {
V_15 -> V_173 += V_174 ;
if ( V_15 -> V_173 <= V_171 ) {
V_15 -> V_173 = ( V_171 - V_15 -> V_173 ) ;
} else {
V_167 = ( V_15 -> V_173 / V_171 ) ;
V_168 = ( V_171 * ( V_167 + 1 ) ) +
( V_167 * V_175 ) ;
V_15 -> V_173 = ( V_168 - V_15 -> V_173 ) ;
}
V_15 -> V_176 = 0 ;
F_21 ( L_36
L_37 , V_15 -> V_173 ) ;
}
if ( V_15 -> V_170 -> V_177 ) {
if ( V_15 -> V_178 <= V_169 ) {
V_15 -> V_178 = ( V_169 - V_15 -> V_178 ) ;
} else {
V_166 = ( V_15 -> V_178 / V_169 ) ;
V_168 = ( V_169 * ( V_166 + 1 ) ) +
( V_166 * V_175 ) ;
V_15 -> V_178 = ( V_168 - V_15 -> V_178 ) ;
}
F_21 ( L_38
L_37 , V_15 -> V_178 ) ;
}
return 0 ;
}
struct V_21 * F_76 ( struct V_76 * V_48 , T_4 V_130 )
{
struct V_21 * V_15 ;
F_8 ( & V_48 -> V_179 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_130 == V_130 ) &&
( V_15 -> V_180 == V_181 ) ) {
F_77 ( V_15 ) ;
F_6 ( & V_48 -> V_179 ) ;
return V_15 ;
}
}
F_6 ( & V_48 -> V_179 ) ;
return NULL ;
}
struct V_21 * F_78 ( struct V_76 * V_48 , T_4 V_130 )
{
struct V_21 * V_15 ;
F_8 ( & V_48 -> V_179 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_130 == V_130 ) {
F_77 ( V_15 ) ;
F_50 ( & V_15 -> V_182 ) ;
F_53 ( & V_15 -> V_183 , 1 ) ;
F_51 ( & V_15 -> V_182 ) ;
F_6 ( & V_48 -> V_179 ) ;
return V_15 ;
}
}
F_6 ( & V_48 -> V_179 ) ;
return NULL ;
}
void F_79 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_184 ) ;
if ( V_15 -> V_185 != 0 ) {
V_15 -> V_186 = 1 ;
F_6 ( & V_15 -> V_184 ) ;
F_71 ( & V_15 -> V_187 ) ;
return;
}
F_6 ( & V_15 -> V_184 ) ;
}
void F_80 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_184 ) ;
V_15 -> V_185 -- ;
if ( ! V_15 -> V_185 && V_15 -> V_186 )
F_73 ( & V_15 -> V_187 ) ;
F_6 ( & V_15 -> V_184 ) ;
}
void F_77 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_184 ) ;
V_15 -> V_185 ++ ;
F_6 ( & V_15 -> V_184 ) ;
}
static int F_81 ( struct V_21 * V_15 , int V_188 )
{
T_3 V_139 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_159 = V_189 ;
V_139 = ( V_188 ) ? V_190 :
V_191 ;
V_2 -> V_19 = 0xFFFFFFFF ;
F_8 ( & V_15 -> V_48 -> V_192 ) ;
V_2 -> V_131 = ( V_188 ) ? V_15 -> V_48 -> V_131 ++ :
0xFFFFFFFF ;
if ( V_188 && ( V_2 -> V_131 == 0xFFFFFFFF ) )
V_2 -> V_131 = V_15 -> V_48 -> V_131 ++ ;
F_6 ( & V_15 -> V_48 -> V_192 ) ;
F_8 ( & V_15 -> V_129 ) ;
F_5 ( & V_2 -> V_24 , & V_15 -> V_193 ) ;
F_6 ( & V_15 -> V_129 ) ;
if ( V_188 )
F_82 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_139 ) ;
return 0 ;
}
static void F_83 ( unsigned long V_194 )
{
struct V_21 * V_15 = (struct V_21 * ) V_194 ;
F_77 ( V_15 ) ;
F_8 ( & V_15 -> V_195 ) ;
if ( V_15 -> V_196 & V_197 ) {
F_6 ( & V_15 -> V_195 ) ;
F_80 ( V_15 ) ;
return;
}
F_21 ( L_39
L_40 , V_15 -> V_130 ,
V_15 -> V_48 -> V_198 ) ;
V_15 -> V_196 &= ~ V_199 ;
F_6 ( & V_15 -> V_195 ) ;
{
struct V_200 * V_201 = V_15 -> V_48 -> V_201 ;
struct V_202 * V_203 = V_201 -> V_204 ;
if ( V_203 ) {
F_8 ( & V_203 -> V_205 . V_206 ) ;
strcpy ( V_203 -> V_205 . V_207 ,
( void * ) V_15 -> V_48 -> V_79 -> V_208 ) ;
V_203 -> V_205 . V_209 =
V_210 ;
V_203 -> V_205 . V_211 ++ ;
V_15 -> V_48 -> V_212 ++ ;
F_6 ( & V_203 -> V_205 . V_206 ) ;
}
}
F_84 ( V_15 , 0 ) ;
F_80 ( V_15 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
F_8 ( & V_15 -> V_195 ) ;
if ( ! ( V_15 -> V_196 & V_199 ) ) {
F_6 ( & V_15 -> V_195 ) ;
return;
}
F_86 ( & V_15 -> V_213 ,
( F_87 () + V_78 -> V_214 * V_215 ) ) ;
F_6 ( & V_15 -> V_195 ) ;
}
void F_82 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
F_8 ( & V_15 -> V_195 ) ;
if ( V_15 -> V_196 & V_199 ) {
F_6 ( & V_15 -> V_195 ) ;
return;
}
F_88 ( & V_15 -> V_213 ) ;
V_15 -> V_213 . V_216 =
( F_87 () + V_78 -> V_214 * V_215 ) ;
V_15 -> V_213 . V_194 = ( unsigned long ) V_15 ;
V_15 -> V_213 . V_51 = F_83 ;
V_15 -> V_196 &= ~ V_197 ;
V_15 -> V_196 |= V_199 ;
F_89 ( & V_15 -> V_213 ) ;
F_21 ( L_41
L_42 , V_15 -> V_130 , V_78 -> V_214 ) ;
F_6 ( & V_15 -> V_195 ) ;
}
void F_90 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_195 ) ;
if ( ! ( V_15 -> V_196 & V_199 ) ) {
F_6 ( & V_15 -> V_195 ) ;
return;
}
V_15 -> V_196 |= V_197 ;
F_6 ( & V_15 -> V_195 ) ;
F_91 ( & V_15 -> V_213 ) ;
F_8 ( & V_15 -> V_195 ) ;
V_15 -> V_196 &= ~ V_199 ;
F_6 ( & V_15 -> V_195 ) ;
}
static void F_92 ( unsigned long V_194 )
{
struct V_21 * V_15 = (struct V_21 * ) V_194 ;
F_77 ( V_15 ) ;
F_8 ( & V_15 -> V_195 ) ;
if ( V_15 -> V_217 & V_197 ) {
F_6 ( & V_15 -> V_195 ) ;
F_80 ( V_15 ) ;
return;
}
V_15 -> V_217 &= ~ V_199 ;
F_6 ( & V_15 -> V_195 ) ;
F_81 ( V_15 , 1 ) ;
F_80 ( V_15 ) ;
}
void F_93 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
if ( ! V_78 -> V_218 )
return;
if ( V_15 -> V_217 & V_199 )
return;
F_88 ( & V_15 -> V_219 ) ;
V_15 -> V_219 . V_216 = ( F_87 () + V_78 -> V_218 * V_215 ) ;
V_15 -> V_219 . V_194 = ( unsigned long ) V_15 ;
V_15 -> V_219 . V_51 = F_92 ;
V_15 -> V_217 &= ~ V_197 ;
V_15 -> V_217 |= V_199 ;
F_89 ( & V_15 -> V_219 ) ;
F_21 ( L_43
L_44 , V_15 -> V_130 , V_78 -> V_218 ) ;
}
void F_94 ( struct V_21 * V_15 )
{
struct V_76 * V_48 = V_15 -> V_48 ;
struct V_77 * V_78 = F_28 ( V_48 ) ;
if ( ! V_78 -> V_218 )
return;
F_8 ( & V_15 -> V_195 ) ;
if ( V_15 -> V_217 & V_199 ) {
F_6 ( & V_15 -> V_195 ) ;
return;
}
F_88 ( & V_15 -> V_219 ) ;
V_15 -> V_219 . V_216 = ( F_87 () + V_78 -> V_218 * V_215 ) ;
V_15 -> V_219 . V_194 = ( unsigned long ) V_15 ;
V_15 -> V_219 . V_51 = F_92 ;
V_15 -> V_217 &= ~ V_197 ;
V_15 -> V_217 |= V_199 ;
F_89 ( & V_15 -> V_219 ) ;
F_21 ( L_43
L_44 , V_15 -> V_130 , V_78 -> V_218 ) ;
F_6 ( & V_15 -> V_195 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_195 ) ;
if ( ! ( V_15 -> V_217 & V_199 ) ) {
F_6 ( & V_15 -> V_195 ) ;
return;
}
V_15 -> V_217 |= V_197 ;
F_6 ( & V_15 -> V_195 ) ;
F_91 ( & V_15 -> V_219 ) ;
F_8 ( & V_15 -> V_195 ) ;
V_15 -> V_217 &= ~ V_199 ;
F_6 ( & V_15 -> V_195 ) ;
}
int F_96 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_220 )
{
int V_221 , V_222 ;
T_1 V_223 ;
struct V_224 * V_225 ;
V_226:
V_222 = V_2 -> V_222 ;
if ( ! V_220 ) {
V_225 = & V_2 -> V_156 [ 0 ] ;
V_223 = V_2 -> V_227 ;
} else {
V_225 = & V_2 -> V_228 [ 0 ] ;
V_223 = V_2 -> V_229 ;
}
V_221 = F_97 ( V_15 , & V_225 [ 0 ] , V_223 , V_222 ) ;
if ( V_222 != V_221 ) {
if ( V_221 == - V_230 ) {
F_3 ( L_45 ) ;
goto V_226;
} else
return - 1 ;
}
V_2 -> V_222 = 0 ;
return 0 ;
}
int F_98 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_231 * V_232 = V_2 -> V_233 ;
struct V_224 V_225 ;
T_1 V_234 , V_235 ;
T_1 V_3 = V_2 -> V_236 ;
int V_221 , V_237 ;
V_238:
V_234 = V_174 ;
if ( V_15 -> V_170 -> V_239 )
V_234 += V_240 ;
V_225 . V_241 = V_2 -> V_242 ;
V_225 . V_243 = V_234 ;
V_221 = F_97 ( V_15 , & V_225 , 1 , V_234 ) ;
if ( V_234 != V_221 ) {
if ( V_221 == - V_230 ) {
F_3 ( L_45 ) ;
goto V_238;
}
return - 1 ;
}
V_235 = V_2 -> V_222 - V_234 - V_2 -> V_244 ;
if ( V_15 -> V_170 -> V_245 ) {
V_235 -= V_240 ;
if ( V_2 -> V_244 )
V_237 = ( V_2 -> V_227 - 2 ) ;
else
V_237 = ( V_2 -> V_227 - 1 ) ;
} else {
V_237 = ( V_2 -> V_227 - 1 ) ;
}
while ( V_235 ) {
T_1 V_246 = ( V_232 -> V_17 - V_3 ) ;
T_1 V_247 = F_99 ( T_1 , V_235 , V_246 ) ;
V_248:
V_221 = V_15 -> V_249 -> V_250 -> V_251 ( V_15 -> V_249 ,
F_66 ( V_232 ) , V_232 -> V_3 + V_3 , V_247 , 0 ) ;
if ( V_221 != V_247 ) {
if ( V_221 == - V_230 ) {
F_3 ( L_46
L_47 ) ;
goto V_248;
}
F_3 ( L_48 ,
V_221 ) ;
return - 1 ;
}
V_235 -= V_247 ;
V_3 = 0 ;
V_232 = F_100 ( V_232 ) ;
}
V_252:
if ( V_2 -> V_244 ) {
struct V_224 * V_253 = & V_2 -> V_156 [ V_237 ++ ] ;
V_221 = F_97 ( V_15 , V_253 , 1 , V_2 -> V_244 ) ;
if ( V_2 -> V_244 != V_221 ) {
if ( V_221 == - V_230 ) {
F_3 ( L_45 ) ;
goto V_252;
}
return - 1 ;
}
}
V_254:
if ( V_15 -> V_170 -> V_245 ) {
struct V_224 * V_255 = & V_2 -> V_156 [ V_237 ] ;
V_221 = F_97 ( V_15 , V_255 , 1 , V_240 ) ;
if ( V_240 != V_221 ) {
if ( V_221 == - V_230 ) {
F_3 ( L_45 ) ;
goto V_254;
}
return - 1 ;
}
}
return 0 ;
}
int F_101 ( struct V_21 * V_15 , T_3 V_256 , T_3 V_257 )
{
T_3 V_258 [ V_174 ] ;
int V_259 ;
struct V_224 V_225 ;
struct V_260 * V_119 ;
F_102 ( V_15 , V_256 , V_257 ) ;
memset ( & V_225 , 0 , sizeof( struct V_224 ) ) ;
memset ( & V_258 , 0x0 , V_174 ) ;
V_119 = (struct V_260 * ) & V_258 ;
V_119 -> V_261 = V_262 ;
V_119 -> V_256 = V_256 ;
V_119 -> V_257 = V_257 ;
V_119 -> V_263 = F_103 ( V_15 -> V_264 ) ;
V_225 . V_241 = & V_258 ;
V_225 . V_243 = V_174 ;
F_104 ( V_258 , V_174 ) ;
V_259 = F_97 ( V_15 , & V_225 , 1 , V_174 ) ;
if ( V_259 != V_174 ) {
F_3 ( L_49 ) ;
return - 1 ;
}
return 0 ;
}
void F_105 ( struct V_76 * V_48 )
{
struct V_21 * V_15 ;
F_21 ( L_50
L_51 , V_48 -> V_198 ) ;
F_8 ( & V_48 -> V_179 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_106 ( V_15 -> V_170 ) ;
F_6 ( & V_48 -> V_179 ) ;
F_107 ( V_48 -> V_79 ) ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_265 * V_266 )
{
int V_194 = V_266 -> V_31 , V_267 = 0 , V_268 = 0 , V_243 ;
struct V_224 * V_253 ;
struct V_269 V_270 ;
if ( ! V_15 || ! V_15 -> V_249 || ! V_15 -> V_170 )
return - 1 ;
memset ( & V_270 , 0 , sizeof( struct V_269 ) ) ;
V_253 = V_266 -> V_225 ;
V_243 = V_266 -> V_223 ;
while ( V_268 < V_194 ) {
V_267 = F_109 ( V_15 -> V_249 , & V_270 , V_253 , V_243 ,
( V_194 - V_268 ) , V_271 ) ;
if ( V_267 <= 0 ) {
F_21 ( L_52 ,
V_267 , V_268 ) ;
return V_267 ;
}
V_268 += V_267 ;
F_21 ( L_53 ,
V_267 , V_268 , V_194 ) ;
}
return V_268 ;
}
static int F_110 (
struct V_21 * V_15 ,
struct V_265 * V_266 )
{
int V_194 = V_266 -> V_31 , V_272 = 0 , V_273 = 0 , V_243 ;
struct V_224 * V_253 ;
struct V_269 V_270 ;
if ( ! V_15 || ! V_15 -> V_249 || ! V_15 -> V_170 )
return - 1 ;
if ( V_194 <= 0 ) {
F_3 ( L_54 , V_194 ) ;
return - 1 ;
}
memset ( & V_270 , 0 , sizeof( struct V_269 ) ) ;
V_253 = V_266 -> V_225 ;
V_243 = V_266 -> V_223 ;
while ( V_272 < V_194 ) {
V_273 = F_111 ( V_15 -> V_249 , & V_270 , V_253 , V_243 ,
( V_194 - V_272 ) ) ;
if ( V_273 <= 0 ) {
F_21 ( L_55 ,
V_273 , V_272 ) ;
return V_273 ;
}
V_272 += V_273 ;
F_21 ( L_56 ,
V_273 , V_272 , V_194 ) ;
}
return V_272 ;
}
int F_112 (
struct V_21 * V_15 ,
struct V_224 * V_225 ,
int V_223 ,
int V_194 )
{
struct V_265 V_274 ;
if ( ! V_15 || ! V_15 -> V_249 || ! V_15 -> V_170 )
return - 1 ;
memset ( & V_274 , 0 , sizeof( struct V_265 ) ) ;
V_274 . V_225 = V_225 ;
V_274 . V_223 = V_223 ;
V_274 . V_31 = V_194 ;
V_274 . type = V_275 ;
return F_108 ( V_15 , & V_274 ) ;
}
int F_97 (
struct V_21 * V_15 ,
struct V_224 * V_225 ,
int V_223 ,
int V_194 )
{
struct V_265 V_274 ;
if ( ! V_15 || ! V_15 -> V_249 || ! V_15 -> V_170 )
return - 1 ;
memset ( & V_274 , 0 , sizeof( struct V_265 ) ) ;
V_274 . V_225 = V_225 ;
V_274 . V_223 = V_223 ;
V_274 . V_31 = V_194 ;
V_274 . type = V_276 ;
return F_110 ( V_15 , & V_274 ) ;
}
void F_102 (
struct V_21 * V_15 ,
T_3 V_256 ,
T_3 V_257 )
{
struct V_277 * V_278 = NULL ;
struct V_202 * V_203 ;
struct V_279 * V_280 ;
V_203 = F_113 ( V_15 ) ;
if ( ! V_203 )
return;
V_280 = & V_203 -> V_281 ;
F_50 ( & V_280 -> V_206 ) ;
if ( ! strcmp ( V_15 -> V_282 , V_280 -> V_283 ) &&
( ( F_87 () - V_280 -> V_284 ) < 10 ) ) {
F_51 ( & V_280 -> V_206 ) ;
return;
}
if ( V_256 == V_285 )
V_280 -> V_286 ++ ;
else if ( V_256 == V_287 ) {
V_280 -> V_288 ++ ;
V_280 -> V_289 = V_290 ;
} else if ( ( V_256 == V_291 ) &&
( V_257 == V_292 ) ) {
V_280 -> V_293 ++ ;
V_280 -> V_289 = V_294 ;
} else if ( ( V_256 == V_291 ) &&
( V_257 == V_295 ) ) {
V_280 -> V_296 ++ ;
V_280 -> V_289 = V_297 ;
} else if ( ( V_256 == V_291 ) &&
( V_257 == V_298 ) ) {
V_280 -> V_299 ++ ;
V_280 -> V_289 = V_300 ;
} else {
V_280 -> V_301 ++ ;
V_280 -> V_289 = V_302 ;
}
if ( V_256 != V_285 ) {
if ( V_15 -> V_303 )
V_278 = F_114 ( V_304 ,
V_15 -> V_303 ) ;
strcpy ( V_280 -> V_305 ,
( V_278 ? V_278 -> V_306 : L_57 ) ) ;
V_280 -> V_307 = V_15 -> V_249 -> V_308 -> V_309 ;
snprintf ( V_280 -> V_283 , V_310 ,
L_58 , V_15 -> V_282 ) ;
V_280 -> V_284 = F_87 () ;
}
F_51 ( & V_280 -> V_206 ) ;
}
struct V_202 * F_113 ( struct V_21 * V_15 )
{
struct V_200 * V_201 ;
if ( ! V_15 || ! V_15 -> V_48 )
return NULL ;
V_201 = V_15 -> V_48 -> V_201 ;
if ( ! V_201 )
return NULL ;
if ( ! V_201 -> V_204 )
return NULL ;
return V_201 -> V_204 ;
}
