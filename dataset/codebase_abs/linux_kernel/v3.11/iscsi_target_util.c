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
if ( ! V_2 )
return NULL ;
V_2 -> V_24 = & V_25 ;
return V_2 ;
}
struct V_1 * F_18 ( struct V_21 * V_15 , T_2 V_22 )
{
struct V_1 * V_2 ;
V_2 = V_15 -> V_26 -> F_17 ( V_15 , V_22 ) ;
if ( ! V_2 ) {
F_3 ( L_6 ) ;
return NULL ;
}
V_2 -> V_15 = V_15 ;
F_4 ( & V_2 -> V_27 ) ;
F_4 ( & V_2 -> V_28 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_19 ( & V_2 -> V_30 ) ;
F_19 ( & V_2 -> V_31 ) ;
F_19 ( & V_2 -> V_32 ) ;
F_19 ( & V_2 -> V_14 ) ;
return V_2 ;
}
struct V_33 * F_20 (
struct V_1 * V_2 ,
T_1 V_34 )
{
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_36 ; V_35 ++ )
if ( V_2 -> V_37 [ V_35 ] . V_34 == V_34 )
return & V_2 -> V_37 [ V_35 ] ;
return NULL ;
}
struct V_33 * F_21 ( struct V_1 * V_2 )
{
T_1 V_35 ;
if ( ! V_2 -> V_37 ) {
F_3 ( L_7 ) ;
return NULL ;
}
for ( V_35 = 0 ; V_35 < V_2 -> V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] . type != V_38 )
continue;
if ( V_2 -> V_37 [ V_35 ] . V_34 == V_2 -> V_34 ) {
V_2 -> V_34 ++ ;
return & V_2 -> V_37 [ V_35 ] ;
}
}
return NULL ;
}
struct V_7 * F_22 (
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
static inline int F_23 ( struct V_39 * V_40 , T_1 V_41 )
{
int V_42 ;
if ( F_24 ( V_41 , V_40 -> V_43 ) ) {
F_3 ( L_8
L_9 , V_41 ,
V_40 -> V_43 ) ;
V_42 = V_44 ;
} else if ( V_41 == V_40 -> V_45 ) {
V_40 -> V_45 ++ ;
F_25 ( L_10
L_11 ,
V_40 -> V_45 ) ;
V_42 = V_46 ;
} else if ( F_24 ( V_41 , V_40 -> V_45 ) ) {
F_25 ( L_12
L_13 ,
V_41 , V_40 -> V_45 ) ;
V_42 = V_47 ;
} else {
F_3 ( L_14
L_15 , V_41 ,
V_40 -> V_45 ) ;
V_42 = V_48 ;
}
return V_42 ;
}
int F_26 ( struct V_21 * V_15 , struct V_1 * V_2 ,
unsigned char * V_49 , T_3 V_41 )
{
int V_42 , V_50 ;
bool V_51 = false ;
T_4 V_52 = V_53 ;
F_27 ( & V_15 -> V_40 -> V_54 ) ;
V_50 = F_23 ( V_15 -> V_40 , F_28 ( V_41 ) ) ;
switch ( V_50 ) {
case V_46 :
V_42 = F_29 ( V_2 , 0 ) ;
if ( ( V_42 >= 0 ) && ! F_30 ( & V_15 -> V_40 -> V_55 ) )
F_31 ( V_15 -> V_40 ) ;
else if ( V_42 < 0 ) {
V_51 = true ;
V_42 = V_44 ;
}
break;
case V_47 :
V_42 = F_32 ( V_15 -> V_40 , V_2 , F_28 ( V_41 ) ) ;
if ( V_42 < 0 ) {
V_51 = true ;
V_42 = V_44 ;
break;
}
V_42 = V_47 ;
break;
case V_48 :
V_2 -> V_56 = V_57 ;
F_7 ( V_2 , V_15 , V_2 -> V_56 ) ;
V_42 = V_50 ;
break;
default:
V_52 = V_58 ;
V_51 = true ;
V_42 = V_50 ;
break;
}
F_33 ( & V_15 -> V_40 -> V_54 ) ;
if ( V_51 )
F_34 ( V_2 , V_52 , V_49 ) ;
return V_42 ;
}
int F_35 ( struct V_1 * V_2 , unsigned char * V_49 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_59 * V_59 = & V_2 -> V_59 ;
struct V_60 * V_61 = (struct V_60 * ) V_49 ;
T_1 V_62 = F_36 ( V_61 -> V_63 ) ;
if ( V_15 -> V_40 -> V_64 -> V_65 ) {
F_3 ( L_16
L_17 ) ;
F_37 ( V_59 ,
V_66 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_67 + V_62 ) >
V_15 -> V_40 -> V_64 -> V_68 ) {
F_3 ( L_18
L_19 ,
( V_2 -> V_67 + V_62 ) ,
V_15 -> V_40 -> V_64 -> V_68 ) ;
F_37 ( V_59 ,
V_69 , 0 ) ;
return - 1 ;
}
if ( ! ( V_61 -> V_70 & V_71 ) )
return 0 ;
if ( ( ( V_2 -> V_67 + V_62 ) != V_2 -> V_59 . V_72 ) &&
( ( V_2 -> V_67 + V_62 ) !=
V_15 -> V_40 -> V_64 -> V_68 ) ) {
F_3 ( L_20
L_21
L_22 ,
( V_2 -> V_67 + V_62 ) ,
V_15 -> V_40 -> V_64 -> V_68 , V_2 -> V_59 . V_72 ) ;
F_37 ( V_59 ,
V_69 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_38 (
struct V_21 * V_15 ,
T_5 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_73 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_73 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_73 ) ;
F_3 ( L_23 ,
V_19 , V_15 -> V_74 ) ;
return NULL ;
}
struct V_1 * F_39 (
struct V_21 * V_15 ,
T_5 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_73 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_73 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_73 ) ;
F_3 ( L_24
L_25 , V_19 , V_15 -> V_74 ) ;
if ( V_17 )
F_40 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_41 (
struct V_21 * V_15 ,
T_1 V_75 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_73 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_75 == V_75 ) {
F_6 ( & V_15 -> V_73 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_73 ) ;
F_3 ( L_26 ,
V_75 , V_15 -> V_74 ) ;
return NULL ;
}
int F_42 (
struct V_39 * V_40 ,
struct V_1 * * V_76 ,
struct V_77 * * V_78 ,
T_5 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_77 * V_79 ;
F_43 ( & V_40 -> V_80 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_43 ( & V_79 -> V_81 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_79 -> V_81 ) ;
F_44 ( & V_40 -> V_80 ) ;
* V_78 = V_79 ;
* V_76 = V_2 ;
return - 2 ;
}
}
F_44 ( & V_79 -> V_81 ) ;
}
F_44 ( & V_40 -> V_80 ) ;
F_43 ( & V_40 -> V_82 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_43 ( & V_79 -> V_81 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_79 -> V_81 ) ;
F_44 ( & V_40 -> V_82 ) ;
* V_78 = V_79 ;
* V_76 = V_2 ;
return 0 ;
}
}
F_44 ( & V_79 -> V_81 ) ;
}
F_44 ( & V_40 -> V_82 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_4 V_83 )
{
struct V_84 * V_85 ;
V_85 = F_2 ( V_86 , V_10 ) ;
if ( ! V_85 ) {
F_3 ( L_27
L_28 ) ;
return;
}
F_4 ( & V_85 -> V_87 ) ;
V_85 -> V_2 = V_2 ;
V_85 -> V_83 = V_83 ;
F_8 ( & V_15 -> V_88 ) ;
F_5 ( & V_85 -> V_87 , & V_15 -> V_89 ) ;
F_45 ( & V_2 -> V_90 ) ;
F_46 ( & V_15 -> V_91 , 1 ) ;
F_6 ( & V_15 -> V_88 ) ;
F_47 ( & V_15 -> V_92 ) ;
}
struct V_84 * F_48 ( struct V_21 * V_15 )
{
struct V_84 * V_85 ;
F_8 ( & V_15 -> V_88 ) ;
if ( F_30 ( & V_15 -> V_89 ) ) {
F_6 ( & V_15 -> V_88 ) ;
return NULL ;
}
V_85 = F_49 ( & V_15 -> V_89 ,
struct V_84 , V_87 ) ;
F_13 ( & V_85 -> V_87 ) ;
if ( V_85 -> V_2 )
F_50 ( & V_85 -> V_2 -> V_90 ) ;
F_6 ( & V_15 -> V_88 ) ;
return V_85 ;
}
static void F_51 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_84 * V_85 , * V_93 ;
F_8 ( & V_15 -> V_88 ) ;
if ( ! F_52 ( & V_2 -> V_90 ) ) {
F_6 ( & V_15 -> V_88 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_85 -> V_2 != V_2 )
continue;
F_50 ( & V_85 -> V_2 -> V_90 ) ;
F_13 ( & V_85 -> V_87 ) ;
F_14 ( V_86 , V_85 ) ;
}
F_6 ( & V_15 -> V_88 ) ;
if ( F_52 ( & V_2 -> V_90 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_90 ) ) ;
}
}
void F_53 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_4 V_83 )
{
struct V_84 * V_85 ;
V_85 = F_2 ( V_86 , V_10 ) ;
if ( ! V_85 ) {
F_3 ( L_27
L_28 ) ;
return;
}
F_4 ( & V_85 -> V_87 ) ;
V_85 -> V_2 = V_2 ;
V_85 -> V_83 = V_83 ;
F_8 ( & V_15 -> V_94 ) ;
F_5 ( & V_85 -> V_87 , & V_15 -> V_95 ) ;
F_45 ( & V_2 -> V_96 ) ;
F_6 ( & V_15 -> V_94 ) ;
F_47 ( & V_15 -> V_92 ) ;
}
struct V_84 * F_54 ( struct V_21 * V_15 )
{
struct V_84 * V_85 ;
F_8 ( & V_15 -> V_94 ) ;
if ( F_30 ( & V_15 -> V_95 ) ) {
F_6 ( & V_15 -> V_94 ) ;
return NULL ;
}
V_85 = F_49 ( & V_15 -> V_95 ,
struct V_84 , V_87 ) ;
F_13 ( & V_85 -> V_87 ) ;
if ( V_85 -> V_2 )
F_50 ( & V_85 -> V_2 -> V_96 ) ;
F_6 ( & V_15 -> V_94 ) ;
return V_85 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_84 * V_85 , * V_93 ;
F_8 ( & V_15 -> V_94 ) ;
if ( ! F_52 ( & V_2 -> V_96 ) ) {
F_6 ( & V_15 -> V_94 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_85 -> V_2 != V_2 )
continue;
F_50 ( & V_85 -> V_2 -> V_96 ) ;
F_13 ( & V_85 -> V_87 ) ;
F_14 ( V_86 , V_85 ) ;
}
F_6 ( & V_15 -> V_94 ) ;
if ( F_52 ( & V_2 -> V_96 ) ) {
F_3 ( L_30 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_96 ) ) ;
}
}
bool F_56 ( struct V_21 * V_15 )
{
bool V_97 ;
F_8 ( & V_15 -> V_88 ) ;
V_97 = F_30 ( & V_15 -> V_89 ) ;
F_6 ( & V_15 -> V_88 ) ;
if ( ! V_97 )
return V_97 ;
F_8 ( & V_15 -> V_94 ) ;
V_97 = F_30 ( & V_15 -> V_95 ) ;
F_6 ( & V_15 -> V_94 ) ;
return V_97 ;
}
void F_57 ( struct V_21 * V_15 )
{
struct V_84 * V_85 , * V_93 ;
F_8 ( & V_15 -> V_88 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_85 -> V_87 ) ;
if ( V_85 -> V_2 )
F_50 ( & V_85 -> V_2 -> V_90 ) ;
F_14 ( V_86 , V_85 ) ;
}
F_6 ( & V_15 -> V_88 ) ;
F_8 ( & V_15 -> V_94 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_85 -> V_87 ) ;
if ( V_85 -> V_2 )
F_50 ( & V_85 -> V_2 -> V_96 ) ;
F_14 ( V_86 , V_85 ) ;
}
F_6 ( & V_15 -> V_94 ) ;
}
void V_25 ( struct V_1 * V_2 )
{
F_58 ( V_2 -> V_98 ) ;
F_58 ( V_2 -> V_99 ) ;
F_58 ( V_2 -> V_37 ) ;
F_58 ( V_2 -> V_100 ) ;
F_58 ( V_2 -> V_101 ) ;
F_58 ( V_2 -> V_102 ) ;
F_14 ( V_23 , V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , bool V_103 ,
bool V_104 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
if ( V_103 ) {
if ( V_2 -> V_105 == V_106 ) {
F_60 ( V_2 ) ;
F_15 ( V_2 ) ;
}
if ( V_2 -> V_105 == V_107 )
F_61 ( V_2 ) ;
}
if ( V_15 && V_104 ) {
F_51 ( V_2 , V_15 ) ;
F_55 ( V_2 , V_15 ) ;
}
}
void F_62 ( struct V_1 * V_2 , bool V_108 )
{
struct V_59 * V_59 = NULL ;
int V_109 ;
switch ( V_2 -> V_110 ) {
case V_111 :
V_59 = & V_2 -> V_59 ;
F_59 ( V_2 , true , V_108 ) ;
case V_112 :
V_109 = F_63 ( & V_2 -> V_59 , 1 ) ;
if ( ! V_109 && V_108 && V_59 && V_59 -> V_113 ) {
F_59 ( V_2 , true , V_108 ) ;
F_64 ( V_59 -> V_113 , V_59 ) ;
}
break;
case V_114 :
if ( V_2 -> V_59 . V_115 != NULL ) {
V_59 = & V_2 -> V_59 ;
F_59 ( V_2 , true , V_108 ) ;
V_109 = F_63 ( & V_2 -> V_59 , 1 ) ;
if ( ! V_109 && V_108 && V_59 -> V_113 ) {
F_59 ( V_2 , true , V_108 ) ;
F_64 ( V_59 -> V_113 , V_59 ) ;
}
break;
}
default:
F_59 ( V_2 , false , V_108 ) ;
V_2 -> V_24 ( V_2 ) ;
break;
}
}
int F_65 ( struct V_39 * V_40 )
{
F_8 ( & V_40 -> V_116 ) ;
if ( V_40 -> V_117 != 0 ) {
V_40 -> V_118 = 1 ;
F_6 ( & V_40 -> V_116 ) ;
if ( F_66 () )
return 2 ;
F_67 ( & V_40 -> V_119 ) ;
return 1 ;
}
F_6 ( & V_40 -> V_116 ) ;
return 0 ;
}
void F_68 ( struct V_39 * V_40 )
{
F_8 ( & V_40 -> V_116 ) ;
V_40 -> V_117 -- ;
if ( ! V_40 -> V_117 && V_40 -> V_118 )
F_69 ( & V_40 -> V_119 ) ;
F_6 ( & V_40 -> V_116 ) ;
}
void F_70 ( struct V_39 * V_40 )
{
F_8 ( & V_40 -> V_116 ) ;
V_40 -> V_117 ++ ;
F_6 ( & V_40 -> V_116 ) ;
}
int F_71 ( struct V_21 * V_15 )
{
int V_120 = 0 , V_121 = 0 , V_122 = 0 ;
T_1 V_123 = ( V_15 -> V_124 -> V_123 * 4 ) ;
T_1 V_125 = ( V_15 -> V_124 -> V_125 * 4 ) ;
if ( V_15 -> V_124 -> V_126 ) {
V_15 -> V_127 += V_128 ;
if ( V_15 -> V_127 <= V_125 ) {
V_15 -> V_127 = ( V_125 - V_15 -> V_127 ) ;
} else {
V_121 = ( V_15 -> V_127 / V_125 ) ;
V_122 = ( V_125 * ( V_121 + 1 ) ) +
( V_121 * V_129 ) ;
V_15 -> V_127 = ( V_122 - V_15 -> V_127 ) ;
}
V_15 -> V_130 = 0 ;
F_25 ( L_31
L_32 , V_15 -> V_127 ) ;
}
if ( V_15 -> V_124 -> V_131 ) {
if ( V_15 -> V_132 <= V_123 ) {
V_15 -> V_132 = ( V_123 - V_15 -> V_132 ) ;
} else {
V_120 = ( V_15 -> V_132 / V_123 ) ;
V_122 = ( V_123 * ( V_120 + 1 ) ) +
( V_120 * V_129 ) ;
V_15 -> V_132 = ( V_122 - V_15 -> V_132 ) ;
}
F_25 ( L_33
L_32 , V_15 -> V_132 ) ;
}
return 0 ;
}
struct V_21 * F_72 ( struct V_39 * V_40 , T_6 V_74 )
{
struct V_21 * V_15 ;
F_8 ( & V_40 -> V_133 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_74 == V_74 ) &&
( V_15 -> V_134 == V_135 ) ) {
F_73 ( V_15 ) ;
F_6 ( & V_40 -> V_133 ) ;
return V_15 ;
}
}
F_6 ( & V_40 -> V_133 ) ;
return NULL ;
}
struct V_21 * F_74 ( struct V_39 * V_40 , T_6 V_74 )
{
struct V_21 * V_15 ;
F_8 ( & V_40 -> V_133 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_74 == V_74 ) {
F_73 ( V_15 ) ;
F_43 ( & V_15 -> V_136 ) ;
F_46 ( & V_15 -> V_137 , 1 ) ;
F_44 ( & V_15 -> V_136 ) ;
F_6 ( & V_40 -> V_133 ) ;
return V_15 ;
}
}
F_6 ( & V_40 -> V_133 ) ;
return NULL ;
}
void F_75 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_138 ) ;
if ( V_15 -> V_139 != 0 ) {
V_15 -> V_140 = 1 ;
F_6 ( & V_15 -> V_138 ) ;
F_67 ( & V_15 -> V_141 ) ;
return;
}
F_6 ( & V_15 -> V_138 ) ;
}
void F_76 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_138 ) ;
V_15 -> V_139 -- ;
if ( ! V_15 -> V_139 && V_15 -> V_140 )
F_69 ( & V_15 -> V_141 ) ;
F_6 ( & V_15 -> V_138 ) ;
}
void F_73 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_138 ) ;
V_15 -> V_139 ++ ;
F_6 ( & V_15 -> V_138 ) ;
}
static int F_77 ( struct V_21 * V_15 , int V_142 )
{
T_4 V_83 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_110 = V_143 ;
V_83 = ( V_142 ) ? V_144 :
V_145 ;
V_2 -> V_19 = V_146 ;
F_8 ( & V_15 -> V_40 -> V_147 ) ;
V_2 -> V_75 = ( V_142 ) ? V_15 -> V_40 -> V_75 ++ :
0xFFFFFFFF ;
if ( V_142 && ( V_2 -> V_75 == 0xFFFFFFFF ) )
V_2 -> V_75 = V_15 -> V_40 -> V_75 ++ ;
F_6 ( & V_15 -> V_40 -> V_147 ) ;
F_8 ( & V_15 -> V_73 ) ;
F_5 ( & V_2 -> V_27 , & V_15 -> V_148 ) ;
F_6 ( & V_15 -> V_73 ) ;
if ( V_142 )
F_78 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_83 ) ;
return 0 ;
}
static void F_79 ( unsigned long V_149 )
{
struct V_21 * V_15 = (struct V_21 * ) V_149 ;
F_73 ( V_15 ) ;
F_8 ( & V_15 -> V_150 ) ;
if ( V_15 -> V_151 & V_152 ) {
F_6 ( & V_15 -> V_150 ) ;
F_76 ( V_15 ) ;
return;
}
F_25 ( L_34
L_35 , V_15 -> V_74 ,
V_15 -> V_40 -> V_153 ) ;
V_15 -> V_151 &= ~ V_154 ;
F_6 ( & V_15 -> V_150 ) ;
{
struct V_155 * V_156 = V_15 -> V_40 -> V_156 ;
struct V_157 * V_158 = V_156 -> V_159 ;
if ( V_158 ) {
F_8 ( & V_158 -> V_160 . V_161 ) ;
strcpy ( V_158 -> V_160 . V_162 ,
V_15 -> V_40 -> V_64 -> V_163 ) ;
V_158 -> V_160 . V_164 =
V_165 ;
V_158 -> V_160 . V_166 ++ ;
V_15 -> V_40 -> V_167 ++ ;
F_6 ( & V_158 -> V_160 . V_161 ) ;
}
}
F_80 ( V_15 , 0 ) ;
F_76 ( V_15 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
struct V_39 * V_40 = V_15 -> V_40 ;
struct V_168 * V_169 = F_82 ( V_40 ) ;
F_8 ( & V_15 -> V_150 ) ;
if ( ! ( V_15 -> V_151 & V_154 ) ) {
F_6 ( & V_15 -> V_150 ) ;
return;
}
F_83 ( & V_15 -> V_170 ,
( F_84 () + V_169 -> V_171 * V_172 ) ) ;
F_6 ( & V_15 -> V_150 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
struct V_39 * V_40 = V_15 -> V_40 ;
struct V_168 * V_169 = F_82 ( V_40 ) ;
F_8 ( & V_15 -> V_150 ) ;
if ( V_15 -> V_151 & V_154 ) {
F_6 ( & V_15 -> V_150 ) ;
return;
}
F_85 ( & V_15 -> V_170 ) ;
V_15 -> V_170 . V_173 =
( F_84 () + V_169 -> V_171 * V_172 ) ;
V_15 -> V_170 . V_149 = ( unsigned long ) V_15 ;
V_15 -> V_170 . V_174 = F_79 ;
V_15 -> V_151 &= ~ V_152 ;
V_15 -> V_151 |= V_154 ;
F_86 ( & V_15 -> V_170 ) ;
F_25 ( L_36
L_37 , V_15 -> V_74 , V_169 -> V_171 ) ;
F_6 ( & V_15 -> V_150 ) ;
}
void F_87 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_150 ) ;
if ( ! ( V_15 -> V_151 & V_154 ) ) {
F_6 ( & V_15 -> V_150 ) ;
return;
}
V_15 -> V_151 |= V_152 ;
F_6 ( & V_15 -> V_150 ) ;
F_88 ( & V_15 -> V_170 ) ;
F_8 ( & V_15 -> V_150 ) ;
V_15 -> V_151 &= ~ V_154 ;
F_6 ( & V_15 -> V_150 ) ;
}
static void F_89 ( unsigned long V_149 )
{
struct V_21 * V_15 = (struct V_21 * ) V_149 ;
F_73 ( V_15 ) ;
F_8 ( & V_15 -> V_150 ) ;
if ( V_15 -> V_175 & V_152 ) {
F_6 ( & V_15 -> V_150 ) ;
F_76 ( V_15 ) ;
return;
}
V_15 -> V_175 &= ~ V_154 ;
F_6 ( & V_15 -> V_150 ) ;
F_77 ( V_15 , 1 ) ;
F_76 ( V_15 ) ;
}
void F_90 ( struct V_21 * V_15 )
{
struct V_39 * V_40 = V_15 -> V_40 ;
struct V_168 * V_169 = F_82 ( V_40 ) ;
if ( ! V_169 -> V_176 )
return;
if ( V_15 -> V_175 & V_154 )
return;
F_85 ( & V_15 -> V_177 ) ;
V_15 -> V_177 . V_173 = ( F_84 () + V_169 -> V_176 * V_172 ) ;
V_15 -> V_177 . V_149 = ( unsigned long ) V_15 ;
V_15 -> V_177 . V_174 = F_89 ;
V_15 -> V_175 &= ~ V_152 ;
V_15 -> V_175 |= V_154 ;
F_86 ( & V_15 -> V_177 ) ;
F_25 ( L_38
L_39 , V_15 -> V_74 , V_169 -> V_176 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
struct V_39 * V_40 = V_15 -> V_40 ;
struct V_168 * V_169 = F_82 ( V_40 ) ;
if ( ! V_169 -> V_176 )
return;
F_8 ( & V_15 -> V_150 ) ;
if ( V_15 -> V_175 & V_154 ) {
F_6 ( & V_15 -> V_150 ) ;
return;
}
F_85 ( & V_15 -> V_177 ) ;
V_15 -> V_177 . V_173 = ( F_84 () + V_169 -> V_176 * V_172 ) ;
V_15 -> V_177 . V_149 = ( unsigned long ) V_15 ;
V_15 -> V_177 . V_174 = F_89 ;
V_15 -> V_175 &= ~ V_152 ;
V_15 -> V_175 |= V_154 ;
F_86 ( & V_15 -> V_177 ) ;
F_25 ( L_38
L_39 , V_15 -> V_74 , V_169 -> V_176 ) ;
F_6 ( & V_15 -> V_150 ) ;
}
void F_92 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_150 ) ;
if ( ! ( V_15 -> V_175 & V_154 ) ) {
F_6 ( & V_15 -> V_150 ) ;
return;
}
V_15 -> V_175 |= V_152 ;
F_6 ( & V_15 -> V_150 ) ;
F_88 ( & V_15 -> V_177 ) ;
F_8 ( & V_15 -> V_150 ) ;
V_15 -> V_175 &= ~ V_154 ;
F_6 ( & V_15 -> V_150 ) ;
}
int F_93 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_178 )
{
int V_179 , V_180 ;
T_1 V_181 ;
struct V_182 * V_183 ;
V_184:
V_180 = V_2 -> V_180 ;
if ( ! V_178 ) {
V_183 = & V_2 -> V_101 [ 0 ] ;
V_181 = V_2 -> V_185 ;
} else {
V_183 = & V_2 -> V_186 [ 0 ] ;
V_181 = V_2 -> V_187 ;
}
V_179 = F_94 ( V_15 , & V_183 [ 0 ] , V_181 , V_180 ) ;
if ( V_180 != V_179 ) {
if ( V_179 == - V_188 ) {
F_3 ( L_40 ) ;
goto V_184;
} else
return - 1 ;
}
V_2 -> V_180 = 0 ;
return 0 ;
}
int F_95 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_189 * V_190 = V_2 -> V_191 ;
struct V_182 V_183 ;
T_1 V_192 , V_193 ;
T_1 V_3 = V_2 -> V_194 ;
int V_179 , V_195 ;
V_196:
V_192 = V_128 ;
if ( V_15 -> V_124 -> V_197 )
V_192 += V_198 ;
V_183 . V_199 = V_2 -> V_200 ;
V_183 . V_201 = V_192 ;
V_179 = F_94 ( V_15 , & V_183 , 1 , V_192 ) ;
if ( V_192 != V_179 ) {
if ( V_179 == - V_188 ) {
F_3 ( L_40 ) ;
goto V_196;
}
return - 1 ;
}
V_193 = V_2 -> V_180 - V_192 - V_2 -> V_202 ;
if ( V_15 -> V_124 -> V_203 ) {
V_193 -= V_198 ;
if ( V_2 -> V_202 )
V_195 = ( V_2 -> V_185 - 2 ) ;
else
V_195 = ( V_2 -> V_185 - 1 ) ;
} else {
V_195 = ( V_2 -> V_185 - 1 ) ;
}
while ( V_193 ) {
T_1 V_204 = ( V_190 -> V_17 - V_3 ) ;
T_1 V_205 = F_96 ( T_1 , V_193 , V_204 ) ;
V_206:
V_179 = V_15 -> V_207 -> V_208 -> V_209 ( V_15 -> V_207 ,
F_97 ( V_190 ) , V_190 -> V_3 + V_3 , V_205 , 0 ) ;
if ( V_179 != V_205 ) {
if ( V_179 == - V_188 ) {
F_3 ( L_41
L_42 ) ;
goto V_206;
}
F_3 ( L_43 ,
V_179 ) ;
return - 1 ;
}
V_193 -= V_205 ;
V_3 = 0 ;
V_190 = F_98 ( V_190 ) ;
}
V_210:
if ( V_2 -> V_202 ) {
struct V_182 * V_211 = & V_2 -> V_101 [ V_195 ++ ] ;
V_179 = F_94 ( V_15 , V_211 , 1 , V_2 -> V_202 ) ;
if ( V_2 -> V_202 != V_179 ) {
if ( V_179 == - V_188 ) {
F_3 ( L_40 ) ;
goto V_210;
}
return - 1 ;
}
}
V_212:
if ( V_15 -> V_124 -> V_203 ) {
struct V_182 * V_213 = & V_2 -> V_101 [ V_195 ] ;
V_179 = F_94 ( V_15 , V_213 , 1 , V_198 ) ;
if ( V_198 != V_179 ) {
if ( V_179 == - V_188 ) {
F_3 ( L_40 ) ;
goto V_212;
}
return - 1 ;
}
}
return 0 ;
}
int F_99 ( struct V_21 * V_15 , T_4 V_214 , T_4 V_215 )
{
struct V_216 * V_61 ;
struct V_217 * V_218 = V_15 -> V_219 ;
V_218 -> V_220 = 1 ;
F_100 ( V_15 , V_214 , V_215 ) ;
V_61 = (struct V_216 * ) & V_218 -> V_221 [ 0 ] ;
V_61 -> V_222 = V_223 ;
V_61 -> V_214 = V_214 ;
V_61 -> V_215 = V_215 ;
V_61 -> V_224 = V_15 -> V_225 ;
return V_15 -> V_26 -> V_226 ( V_15 , V_218 , 0 ) ;
}
void F_101 ( struct V_39 * V_40 )
{
struct V_21 * V_15 ;
F_25 ( L_44
L_45 , V_40 -> V_153 ) ;
F_8 ( & V_40 -> V_133 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_102 ( V_15 -> V_124 ) ;
F_6 ( & V_40 -> V_133 ) ;
F_103 ( V_40 -> V_64 ) ;
}
static int F_104 (
struct V_21 * V_15 ,
struct V_227 * V_228 )
{
int V_149 = V_228 -> V_72 , V_229 = 0 , V_230 = 0 , V_201 ;
struct V_182 * V_211 ;
struct V_231 V_232 ;
if ( ! V_15 || ! V_15 -> V_207 || ! V_15 -> V_124 )
return - 1 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_211 = V_228 -> V_183 ;
V_201 = V_228 -> V_181 ;
while ( V_230 < V_149 ) {
V_229 = F_105 ( V_15 -> V_207 , & V_232 , V_211 , V_201 ,
( V_149 - V_230 ) , V_233 ) ;
if ( V_229 <= 0 ) {
F_25 ( L_46 ,
V_229 , V_230 ) ;
return V_229 ;
}
V_230 += V_229 ;
F_25 ( L_47 ,
V_229 , V_230 , V_149 ) ;
}
return V_230 ;
}
static int F_106 (
struct V_21 * V_15 ,
struct V_227 * V_228 )
{
int V_149 = V_228 -> V_72 , V_234 = 0 , V_235 = 0 , V_201 ;
struct V_182 * V_211 ;
struct V_231 V_232 ;
if ( ! V_15 || ! V_15 -> V_207 || ! V_15 -> V_124 )
return - 1 ;
if ( V_149 <= 0 ) {
F_3 ( L_48 , V_149 ) ;
return - 1 ;
}
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_211 = V_228 -> V_183 ;
V_201 = V_228 -> V_181 ;
while ( V_234 < V_149 ) {
V_235 = F_107 ( V_15 -> V_207 , & V_232 , V_211 , V_201 ,
( V_149 - V_234 ) ) ;
if ( V_235 <= 0 ) {
F_25 ( L_49 ,
V_235 , V_234 ) ;
return V_235 ;
}
V_234 += V_235 ;
F_25 ( L_50 ,
V_235 , V_234 , V_149 ) ;
}
return V_234 ;
}
int F_108 (
struct V_21 * V_15 ,
struct V_182 * V_183 ,
int V_181 ,
int V_149 )
{
struct V_227 V_236 ;
if ( ! V_15 || ! V_15 -> V_207 || ! V_15 -> V_124 )
return - 1 ;
memset ( & V_236 , 0 , sizeof( struct V_227 ) ) ;
V_236 . V_183 = V_183 ;
V_236 . V_181 = V_181 ;
V_236 . V_72 = V_149 ;
V_236 . type = V_237 ;
return F_104 ( V_15 , & V_236 ) ;
}
int F_94 (
struct V_21 * V_15 ,
struct V_182 * V_183 ,
int V_181 ,
int V_149 )
{
struct V_227 V_236 ;
if ( ! V_15 || ! V_15 -> V_207 || ! V_15 -> V_124 )
return - 1 ;
memset ( & V_236 , 0 , sizeof( struct V_227 ) ) ;
V_236 . V_183 = V_183 ;
V_236 . V_181 = V_181 ;
V_236 . V_72 = V_149 ;
V_236 . type = V_238 ;
return F_106 ( V_15 , & V_236 ) ;
}
void F_100 (
struct V_21 * V_15 ,
T_4 V_214 ,
T_4 V_215 )
{
struct V_239 * V_240 = NULL ;
struct V_157 * V_158 ;
struct V_241 * V_242 ;
V_158 = F_109 ( V_15 ) ;
if ( ! V_158 )
return;
V_242 = & V_158 -> V_243 ;
F_43 ( & V_242 -> V_161 ) ;
if ( ! strcmp ( V_15 -> V_244 , V_242 -> V_245 ) &&
( ( F_84 () - V_242 -> V_246 ) < 10 ) ) {
F_44 ( & V_242 -> V_161 ) ;
return;
}
if ( V_214 == V_247 )
V_242 -> V_248 ++ ;
else if ( V_214 == V_249 ) {
V_242 -> V_250 ++ ;
V_242 -> V_251 = V_252 ;
} else if ( ( V_214 == V_253 ) &&
( V_215 == V_254 ) ) {
V_242 -> V_255 ++ ;
V_242 -> V_251 = V_256 ;
} else if ( ( V_214 == V_253 ) &&
( V_215 == V_257 ) ) {
V_242 -> V_258 ++ ;
V_242 -> V_251 = V_259 ;
} else if ( ( V_214 == V_253 ) &&
( V_215 == V_260 ) ) {
V_242 -> V_261 ++ ;
V_242 -> V_251 = V_262 ;
} else {
V_242 -> V_263 ++ ;
V_242 -> V_251 = V_264 ;
}
if ( V_214 != V_247 ) {
if ( V_15 -> V_265 )
V_240 = F_110 ( V_266 ,
V_15 -> V_265 ) ;
strcpy ( V_242 -> V_267 ,
( V_240 ? V_240 -> V_268 : L_51 ) ) ;
V_242 -> V_269 = V_15 -> V_270 ;
snprintf ( V_242 -> V_245 , V_271 ,
L_52 , V_15 -> V_244 ) ;
V_242 -> V_246 = F_84 () ;
}
F_44 ( & V_242 -> V_161 ) ;
}
struct V_157 * F_109 ( struct V_21 * V_15 )
{
struct V_155 * V_156 ;
if ( ! V_15 || ! V_15 -> V_40 )
return NULL ;
V_156 = V_15 -> V_40 -> V_156 ;
if ( ! V_156 )
return NULL ;
if ( ! V_156 -> V_159 )
return NULL ;
return V_156 -> V_159 ;
}
