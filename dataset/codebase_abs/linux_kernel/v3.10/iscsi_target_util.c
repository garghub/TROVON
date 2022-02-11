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
F_20 ( & V_2 -> V_30 ) ;
F_20 ( & V_2 -> V_31 ) ;
F_20 ( & V_2 -> V_32 ) ;
F_20 ( & V_2 -> V_33 ) ;
F_20 ( & V_2 -> V_14 ) ;
return V_2 ;
}
struct V_34 * F_21 (
struct V_1 * V_2 ,
T_1 V_35 )
{
T_1 V_36 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_37 ; V_36 ++ )
if ( V_2 -> V_38 [ V_36 ] . V_35 == V_35 )
return & V_2 -> V_38 [ V_36 ] ;
return NULL ;
}
struct V_34 * F_22 ( struct V_1 * V_2 )
{
T_1 V_36 ;
if ( ! V_2 -> V_38 ) {
F_3 ( L_7 ) ;
return NULL ;
}
for ( V_36 = 0 ; V_36 < V_2 -> V_37 ; V_36 ++ ) {
if ( V_2 -> V_38 [ V_36 ] . type != V_39 )
continue;
if ( V_2 -> V_38 [ V_36 ] . V_35 == V_2 -> V_35 ) {
V_2 -> V_35 ++ ;
return & V_2 -> V_38 [ V_36 ] ;
}
}
return NULL ;
}
struct V_7 * F_23 (
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
static inline int F_24 ( struct V_40 * V_41 , T_1 V_42 )
{
int V_43 ;
if ( F_25 ( V_42 , V_41 -> V_44 ) ) {
F_3 ( L_8
L_9 , V_42 ,
V_41 -> V_44 ) ;
V_43 = V_45 ;
} else if ( V_42 == V_41 -> V_46 ) {
V_41 -> V_46 ++ ;
F_26 ( L_10
L_11 ,
V_41 -> V_46 ) ;
V_43 = V_47 ;
} else if ( F_25 ( V_42 , V_41 -> V_46 ) ) {
F_26 ( L_12
L_13 ,
V_42 , V_41 -> V_46 ) ;
V_43 = V_48 ;
} else {
F_3 ( L_14
L_15 , V_42 ,
V_41 -> V_46 ) ;
V_43 = V_49 ;
}
return V_43 ;
}
int F_27 (
struct V_21 * V_15 ,
struct V_1 * V_2 ,
T_3 V_42 )
{
int V_43 ;
int V_50 ;
F_28 ( & V_15 -> V_41 -> V_51 ) ;
V_50 = F_24 ( V_15 -> V_41 , F_29 ( V_42 ) ) ;
switch ( V_50 ) {
case V_47 :
V_43 = F_30 ( V_2 , 0 ) ;
if ( ( V_43 >= 0 ) && ! F_31 ( & V_15 -> V_41 -> V_52 ) )
F_32 ( V_15 -> V_41 ) ;
break;
case V_48 :
V_43 = F_33 ( V_15 -> V_41 , V_2 , F_29 ( V_42 ) ) ;
break;
case V_49 :
V_2 -> V_53 = V_54 ;
F_7 ( V_2 , V_15 , V_2 -> V_53 ) ;
V_43 = V_50 ;
break;
default:
V_43 = V_50 ;
break;
}
F_34 ( & V_15 -> V_41 -> V_51 ) ;
return V_43 ;
}
int F_35 ( struct V_1 * V_2 , unsigned char * V_55 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_56 * V_56 = & V_2 -> V_56 ;
struct V_57 * V_58 = (struct V_57 * ) V_55 ;
T_1 V_59 = F_36 ( V_58 -> V_60 ) ;
if ( V_15 -> V_41 -> V_61 -> V_62 ) {
F_3 ( L_16
L_17 ) ;
F_37 ( V_56 ,
V_63 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_64 + V_59 ) >
V_15 -> V_41 -> V_61 -> V_65 ) {
F_3 ( L_18
L_19 ,
( V_2 -> V_64 + V_59 ) ,
V_15 -> V_41 -> V_61 -> V_65 ) ;
F_37 ( V_56 ,
V_66 , 0 ) ;
return - 1 ;
}
if ( ! ( V_58 -> V_67 & V_68 ) )
return 0 ;
if ( ( ( V_2 -> V_64 + V_59 ) != V_2 -> V_56 . V_69 ) &&
( ( V_2 -> V_64 + V_59 ) !=
V_15 -> V_41 -> V_61 -> V_65 ) ) {
F_3 ( L_20
L_21
L_22 ,
( V_2 -> V_64 + V_59 ) ,
V_15 -> V_41 -> V_61 -> V_65 , V_2 -> V_56 . V_69 ) ;
F_37 ( V_56 ,
V_66 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_38 (
struct V_21 * V_15 ,
T_4 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_70 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_70 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_70 ) ;
F_3 ( L_23 ,
V_19 , V_15 -> V_71 ) ;
return NULL ;
}
struct V_1 * F_39 (
struct V_21 * V_15 ,
T_4 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_70 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_70 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_70 ) ;
F_3 ( L_24
L_25 , V_19 , V_15 -> V_71 ) ;
if ( V_17 )
F_40 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_41 (
struct V_21 * V_15 ,
T_1 V_72 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_70 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_72 == V_72 ) {
F_6 ( & V_15 -> V_70 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_70 ) ;
F_3 ( L_26 ,
V_72 , V_15 -> V_71 ) ;
return NULL ;
}
int F_42 (
struct V_40 * V_41 ,
struct V_1 * * V_73 ,
struct V_74 * * V_75 ,
T_4 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_74 * V_76 ;
F_43 ( & V_41 -> V_77 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_43 ( & V_76 -> V_78 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_76 -> V_78 ) ;
F_44 ( & V_41 -> V_77 ) ;
* V_75 = V_76 ;
* V_73 = V_2 ;
return - 2 ;
}
}
F_44 ( & V_76 -> V_78 ) ;
}
F_44 ( & V_41 -> V_77 ) ;
F_43 ( & V_41 -> V_79 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_43 ( & V_76 -> V_78 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_76 -> V_78 ) ;
F_44 ( & V_41 -> V_79 ) ;
* V_75 = V_76 ;
* V_73 = V_2 ;
return 0 ;
}
}
F_44 ( & V_76 -> V_78 ) ;
}
F_44 ( & V_41 -> V_79 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_5 V_80 )
{
struct V_81 * V_82 ;
V_82 = F_2 ( V_83 , V_10 ) ;
if ( ! V_82 ) {
F_3 ( L_27
L_28 ) ;
return;
}
F_4 ( & V_82 -> V_84 ) ;
V_82 -> V_2 = V_2 ;
V_82 -> V_80 = V_80 ;
F_8 ( & V_15 -> V_85 ) ;
F_5 ( & V_82 -> V_84 , & V_15 -> V_86 ) ;
F_45 ( & V_2 -> V_87 ) ;
F_46 ( & V_15 -> V_88 , 1 ) ;
F_6 ( & V_15 -> V_85 ) ;
F_47 ( & V_15 -> V_89 ) ;
}
struct V_81 * F_48 ( struct V_21 * V_15 )
{
struct V_81 * V_82 ;
F_8 ( & V_15 -> V_85 ) ;
if ( F_31 ( & V_15 -> V_86 ) ) {
F_6 ( & V_15 -> V_85 ) ;
return NULL ;
}
V_82 = F_49 ( & V_15 -> V_86 ,
struct V_81 , V_84 ) ;
F_13 ( & V_82 -> V_84 ) ;
if ( V_82 -> V_2 )
F_50 ( & V_82 -> V_2 -> V_87 ) ;
F_6 ( & V_15 -> V_85 ) ;
return V_82 ;
}
static void F_51 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_81 * V_82 , * V_90 ;
F_8 ( & V_15 -> V_85 ) ;
if ( ! F_52 ( & V_2 -> V_87 ) ) {
F_6 ( & V_15 -> V_85 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_82 -> V_2 != V_2 )
continue;
F_50 ( & V_82 -> V_2 -> V_87 ) ;
F_13 ( & V_82 -> V_84 ) ;
F_14 ( V_83 , V_82 ) ;
}
F_6 ( & V_15 -> V_85 ) ;
if ( F_52 ( & V_2 -> V_87 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_87 ) ) ;
}
}
void F_53 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_5 V_80 )
{
struct V_81 * V_82 ;
V_82 = F_2 ( V_83 , V_10 ) ;
if ( ! V_82 ) {
F_3 ( L_27
L_28 ) ;
return;
}
F_4 ( & V_82 -> V_84 ) ;
V_82 -> V_2 = V_2 ;
V_82 -> V_80 = V_80 ;
F_8 ( & V_15 -> V_91 ) ;
F_5 ( & V_82 -> V_84 , & V_15 -> V_92 ) ;
F_45 ( & V_2 -> V_93 ) ;
F_6 ( & V_15 -> V_91 ) ;
F_47 ( & V_15 -> V_89 ) ;
}
struct V_81 * F_54 ( struct V_21 * V_15 )
{
struct V_81 * V_82 ;
F_8 ( & V_15 -> V_91 ) ;
if ( F_31 ( & V_15 -> V_92 ) ) {
F_6 ( & V_15 -> V_91 ) ;
return NULL ;
}
V_82 = F_49 ( & V_15 -> V_92 ,
struct V_81 , V_84 ) ;
F_13 ( & V_82 -> V_84 ) ;
if ( V_82 -> V_2 )
F_50 ( & V_82 -> V_2 -> V_93 ) ;
F_6 ( & V_15 -> V_91 ) ;
return V_82 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_81 * V_82 , * V_90 ;
F_8 ( & V_15 -> V_91 ) ;
if ( ! F_52 ( & V_2 -> V_93 ) ) {
F_6 ( & V_15 -> V_91 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_82 -> V_2 != V_2 )
continue;
F_50 ( & V_82 -> V_2 -> V_93 ) ;
F_13 ( & V_82 -> V_84 ) ;
F_14 ( V_83 , V_82 ) ;
}
F_6 ( & V_15 -> V_91 ) ;
if ( F_52 ( & V_2 -> V_93 ) ) {
F_3 ( L_30 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_93 ) ) ;
}
}
bool F_56 ( struct V_21 * V_15 )
{
bool V_94 ;
F_8 ( & V_15 -> V_85 ) ;
V_94 = F_31 ( & V_15 -> V_86 ) ;
F_6 ( & V_15 -> V_85 ) ;
if ( ! V_94 )
return V_94 ;
F_8 ( & V_15 -> V_91 ) ;
V_94 = F_31 ( & V_15 -> V_92 ) ;
F_6 ( & V_15 -> V_91 ) ;
return V_94 ;
}
void F_57 ( struct V_21 * V_15 )
{
struct V_81 * V_82 , * V_90 ;
F_8 ( & V_15 -> V_85 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_82 -> V_84 ) ;
if ( V_82 -> V_2 )
F_50 ( & V_82 -> V_2 -> V_87 ) ;
F_14 ( V_83 , V_82 ) ;
}
F_6 ( & V_15 -> V_85 ) ;
F_8 ( & V_15 -> V_91 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_82 -> V_84 ) ;
if ( V_82 -> V_2 )
F_50 ( & V_82 -> V_2 -> V_93 ) ;
F_14 ( V_83 , V_82 ) ;
}
F_6 ( & V_15 -> V_91 ) ;
}
void V_25 ( struct V_1 * V_2 )
{
F_58 ( V_2 -> V_95 ) ;
F_58 ( V_2 -> V_96 ) ;
F_58 ( V_2 -> V_38 ) ;
F_58 ( V_2 -> V_97 ) ;
F_58 ( V_2 -> V_98 ) ;
F_14 ( V_23 , V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , bool V_99 ,
bool V_100 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
if ( V_99 ) {
if ( V_2 -> V_101 == V_102 ) {
F_60 ( V_2 ) ;
F_15 ( V_2 ) ;
}
if ( V_2 -> V_101 == V_103 )
F_61 ( V_2 ) ;
}
if ( V_15 && V_100 ) {
F_51 ( V_2 , V_15 ) ;
F_55 ( V_2 , V_15 ) ;
}
}
void F_62 ( struct V_1 * V_2 , bool V_104 )
{
struct V_56 * V_56 = NULL ;
int V_105 ;
switch ( V_2 -> V_106 ) {
case V_107 :
V_56 = & V_2 -> V_56 ;
F_59 ( V_2 , true , V_104 ) ;
case V_108 :
V_105 = F_63 ( & V_2 -> V_56 , 1 ) ;
if ( ! V_105 && V_104 && V_56 && V_56 -> V_109 ) {
F_59 ( V_2 , true , V_104 ) ;
F_64 ( V_56 -> V_109 , V_56 ) ;
}
break;
case V_110 :
if ( V_2 -> V_56 . V_111 != NULL ) {
V_56 = & V_2 -> V_56 ;
F_59 ( V_2 , true , V_104 ) ;
V_105 = F_63 ( & V_2 -> V_56 , 1 ) ;
if ( ! V_105 && V_104 && V_56 -> V_109 ) {
F_59 ( V_2 , true , V_104 ) ;
F_64 ( V_56 -> V_109 , V_56 ) ;
}
break;
}
default:
F_59 ( V_2 , false , V_104 ) ;
V_2 -> V_24 ( V_2 ) ;
break;
}
}
int F_65 ( struct V_40 * V_41 )
{
F_8 ( & V_41 -> V_112 ) ;
if ( V_41 -> V_113 != 0 ) {
V_41 -> V_114 = 1 ;
F_6 ( & V_41 -> V_112 ) ;
if ( F_66 () )
return 2 ;
F_67 ( & V_41 -> V_115 ) ;
return 1 ;
}
F_6 ( & V_41 -> V_112 ) ;
return 0 ;
}
void F_68 ( struct V_40 * V_41 )
{
F_8 ( & V_41 -> V_112 ) ;
V_41 -> V_113 -- ;
if ( ! V_41 -> V_113 && V_41 -> V_114 )
F_69 ( & V_41 -> V_115 ) ;
F_6 ( & V_41 -> V_112 ) ;
}
void F_70 ( struct V_40 * V_41 )
{
F_8 ( & V_41 -> V_112 ) ;
V_41 -> V_113 ++ ;
F_6 ( & V_41 -> V_112 ) ;
}
int F_71 ( struct V_21 * V_15 )
{
int V_116 = 0 , V_117 = 0 , V_118 = 0 ;
T_1 V_119 = ( V_15 -> V_120 -> V_119 * 4 ) ;
T_1 V_121 = ( V_15 -> V_120 -> V_121 * 4 ) ;
if ( V_15 -> V_120 -> V_122 ) {
V_15 -> V_123 += V_124 ;
if ( V_15 -> V_123 <= V_121 ) {
V_15 -> V_123 = ( V_121 - V_15 -> V_123 ) ;
} else {
V_117 = ( V_15 -> V_123 / V_121 ) ;
V_118 = ( V_121 * ( V_117 + 1 ) ) +
( V_117 * V_125 ) ;
V_15 -> V_123 = ( V_118 - V_15 -> V_123 ) ;
}
V_15 -> V_126 = 0 ;
F_26 ( L_31
L_32 , V_15 -> V_123 ) ;
}
if ( V_15 -> V_120 -> V_127 ) {
if ( V_15 -> V_128 <= V_119 ) {
V_15 -> V_128 = ( V_119 - V_15 -> V_128 ) ;
} else {
V_116 = ( V_15 -> V_128 / V_119 ) ;
V_118 = ( V_119 * ( V_116 + 1 ) ) +
( V_116 * V_125 ) ;
V_15 -> V_128 = ( V_118 - V_15 -> V_128 ) ;
}
F_26 ( L_33
L_32 , V_15 -> V_128 ) ;
}
return 0 ;
}
struct V_21 * F_72 ( struct V_40 * V_41 , T_6 V_71 )
{
struct V_21 * V_15 ;
F_8 ( & V_41 -> V_129 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_71 == V_71 ) &&
( V_15 -> V_130 == V_131 ) ) {
F_73 ( V_15 ) ;
F_6 ( & V_41 -> V_129 ) ;
return V_15 ;
}
}
F_6 ( & V_41 -> V_129 ) ;
return NULL ;
}
struct V_21 * F_74 ( struct V_40 * V_41 , T_6 V_71 )
{
struct V_21 * V_15 ;
F_8 ( & V_41 -> V_129 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_71 == V_71 ) {
F_73 ( V_15 ) ;
F_43 ( & V_15 -> V_132 ) ;
F_46 ( & V_15 -> V_133 , 1 ) ;
F_44 ( & V_15 -> V_132 ) ;
F_6 ( & V_41 -> V_129 ) ;
return V_15 ;
}
}
F_6 ( & V_41 -> V_129 ) ;
return NULL ;
}
void F_75 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_134 ) ;
if ( V_15 -> V_135 != 0 ) {
V_15 -> V_136 = 1 ;
F_6 ( & V_15 -> V_134 ) ;
F_67 ( & V_15 -> V_137 ) ;
return;
}
F_6 ( & V_15 -> V_134 ) ;
}
void F_76 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_134 ) ;
V_15 -> V_135 -- ;
if ( ! V_15 -> V_135 && V_15 -> V_136 )
F_69 ( & V_15 -> V_137 ) ;
F_6 ( & V_15 -> V_134 ) ;
}
void F_73 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_134 ) ;
V_15 -> V_135 ++ ;
F_6 ( & V_15 -> V_134 ) ;
}
static int F_77 ( struct V_21 * V_15 , int V_138 )
{
T_5 V_80 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_106 = V_139 ;
V_80 = ( V_138 ) ? V_140 :
V_141 ;
V_2 -> V_19 = V_142 ;
F_8 ( & V_15 -> V_41 -> V_143 ) ;
V_2 -> V_72 = ( V_138 ) ? V_15 -> V_41 -> V_72 ++ :
0xFFFFFFFF ;
if ( V_138 && ( V_2 -> V_72 == 0xFFFFFFFF ) )
V_2 -> V_72 = V_15 -> V_41 -> V_72 ++ ;
F_6 ( & V_15 -> V_41 -> V_143 ) ;
F_8 ( & V_15 -> V_70 ) ;
F_5 ( & V_2 -> V_27 , & V_15 -> V_144 ) ;
F_6 ( & V_15 -> V_70 ) ;
if ( V_138 )
F_78 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_80 ) ;
return 0 ;
}
static void F_79 ( unsigned long V_145 )
{
struct V_21 * V_15 = (struct V_21 * ) V_145 ;
F_73 ( V_15 ) ;
F_8 ( & V_15 -> V_146 ) ;
if ( V_15 -> V_147 & V_148 ) {
F_6 ( & V_15 -> V_146 ) ;
F_76 ( V_15 ) ;
return;
}
F_26 ( L_34
L_35 , V_15 -> V_71 ,
V_15 -> V_41 -> V_149 ) ;
V_15 -> V_147 &= ~ V_150 ;
F_6 ( & V_15 -> V_146 ) ;
{
struct V_151 * V_152 = V_15 -> V_41 -> V_152 ;
struct V_153 * V_154 = V_152 -> V_155 ;
if ( V_154 ) {
F_8 ( & V_154 -> V_156 . V_157 ) ;
strcpy ( V_154 -> V_156 . V_158 ,
V_15 -> V_41 -> V_61 -> V_159 ) ;
V_154 -> V_156 . V_160 =
V_161 ;
V_154 -> V_156 . V_162 ++ ;
V_15 -> V_41 -> V_163 ++ ;
F_6 ( & V_154 -> V_156 . V_157 ) ;
}
}
F_80 ( V_15 , 0 ) ;
F_76 ( V_15 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
struct V_40 * V_41 = V_15 -> V_41 ;
struct V_164 * V_165 = F_82 ( V_41 ) ;
F_8 ( & V_15 -> V_146 ) ;
if ( ! ( V_15 -> V_147 & V_150 ) ) {
F_6 ( & V_15 -> V_146 ) ;
return;
}
F_83 ( & V_15 -> V_166 ,
( F_84 () + V_165 -> V_167 * V_168 ) ) ;
F_6 ( & V_15 -> V_146 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
struct V_40 * V_41 = V_15 -> V_41 ;
struct V_164 * V_165 = F_82 ( V_41 ) ;
F_8 ( & V_15 -> V_146 ) ;
if ( V_15 -> V_147 & V_150 ) {
F_6 ( & V_15 -> V_146 ) ;
return;
}
F_85 ( & V_15 -> V_166 ) ;
V_15 -> V_166 . V_169 =
( F_84 () + V_165 -> V_167 * V_168 ) ;
V_15 -> V_166 . V_145 = ( unsigned long ) V_15 ;
V_15 -> V_166 . V_170 = F_79 ;
V_15 -> V_147 &= ~ V_148 ;
V_15 -> V_147 |= V_150 ;
F_86 ( & V_15 -> V_166 ) ;
F_26 ( L_36
L_37 , V_15 -> V_71 , V_165 -> V_167 ) ;
F_6 ( & V_15 -> V_146 ) ;
}
void F_87 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_146 ) ;
if ( ! ( V_15 -> V_147 & V_150 ) ) {
F_6 ( & V_15 -> V_146 ) ;
return;
}
V_15 -> V_147 |= V_148 ;
F_6 ( & V_15 -> V_146 ) ;
F_88 ( & V_15 -> V_166 ) ;
F_8 ( & V_15 -> V_146 ) ;
V_15 -> V_147 &= ~ V_150 ;
F_6 ( & V_15 -> V_146 ) ;
}
static void F_89 ( unsigned long V_145 )
{
struct V_21 * V_15 = (struct V_21 * ) V_145 ;
F_73 ( V_15 ) ;
F_8 ( & V_15 -> V_146 ) ;
if ( V_15 -> V_171 & V_148 ) {
F_6 ( & V_15 -> V_146 ) ;
F_76 ( V_15 ) ;
return;
}
V_15 -> V_171 &= ~ V_150 ;
F_6 ( & V_15 -> V_146 ) ;
F_77 ( V_15 , 1 ) ;
F_76 ( V_15 ) ;
}
void F_90 ( struct V_21 * V_15 )
{
struct V_40 * V_41 = V_15 -> V_41 ;
struct V_164 * V_165 = F_82 ( V_41 ) ;
if ( ! V_165 -> V_172 )
return;
if ( V_15 -> V_171 & V_150 )
return;
F_85 ( & V_15 -> V_173 ) ;
V_15 -> V_173 . V_169 = ( F_84 () + V_165 -> V_172 * V_168 ) ;
V_15 -> V_173 . V_145 = ( unsigned long ) V_15 ;
V_15 -> V_173 . V_170 = F_89 ;
V_15 -> V_171 &= ~ V_148 ;
V_15 -> V_171 |= V_150 ;
F_86 ( & V_15 -> V_173 ) ;
F_26 ( L_38
L_39 , V_15 -> V_71 , V_165 -> V_172 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
struct V_40 * V_41 = V_15 -> V_41 ;
struct V_164 * V_165 = F_82 ( V_41 ) ;
if ( ! V_165 -> V_172 )
return;
F_8 ( & V_15 -> V_146 ) ;
if ( V_15 -> V_171 & V_150 ) {
F_6 ( & V_15 -> V_146 ) ;
return;
}
F_85 ( & V_15 -> V_173 ) ;
V_15 -> V_173 . V_169 = ( F_84 () + V_165 -> V_172 * V_168 ) ;
V_15 -> V_173 . V_145 = ( unsigned long ) V_15 ;
V_15 -> V_173 . V_170 = F_89 ;
V_15 -> V_171 &= ~ V_148 ;
V_15 -> V_171 |= V_150 ;
F_86 ( & V_15 -> V_173 ) ;
F_26 ( L_38
L_39 , V_15 -> V_71 , V_165 -> V_172 ) ;
F_6 ( & V_15 -> V_146 ) ;
}
void F_92 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_146 ) ;
if ( ! ( V_15 -> V_171 & V_150 ) ) {
F_6 ( & V_15 -> V_146 ) ;
return;
}
V_15 -> V_171 |= V_148 ;
F_6 ( & V_15 -> V_146 ) ;
F_88 ( & V_15 -> V_173 ) ;
F_8 ( & V_15 -> V_146 ) ;
V_15 -> V_171 &= ~ V_150 ;
F_6 ( & V_15 -> V_146 ) ;
}
int F_93 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_174 )
{
int V_175 , V_176 ;
T_1 V_177 ;
struct V_178 * V_179 ;
V_180:
V_176 = V_2 -> V_176 ;
if ( ! V_174 ) {
V_179 = & V_2 -> V_98 [ 0 ] ;
V_177 = V_2 -> V_181 ;
} else {
V_179 = & V_2 -> V_182 [ 0 ] ;
V_177 = V_2 -> V_183 ;
}
V_175 = F_94 ( V_15 , & V_179 [ 0 ] , V_177 , V_176 ) ;
if ( V_176 != V_175 ) {
if ( V_175 == - V_184 ) {
F_3 ( L_40 ) ;
goto V_180;
} else
return - 1 ;
}
V_2 -> V_176 = 0 ;
return 0 ;
}
int F_95 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_185 * V_186 = V_2 -> V_187 ;
struct V_178 V_179 ;
T_1 V_188 , V_189 ;
T_1 V_3 = V_2 -> V_190 ;
int V_175 , V_191 ;
V_192:
V_188 = V_124 ;
if ( V_15 -> V_120 -> V_193 )
V_188 += V_194 ;
V_179 . V_195 = V_2 -> V_196 ;
V_179 . V_197 = V_188 ;
V_175 = F_94 ( V_15 , & V_179 , 1 , V_188 ) ;
if ( V_188 != V_175 ) {
if ( V_175 == - V_184 ) {
F_3 ( L_40 ) ;
goto V_192;
}
return - 1 ;
}
V_189 = V_2 -> V_176 - V_188 - V_2 -> V_198 ;
if ( V_15 -> V_120 -> V_199 ) {
V_189 -= V_194 ;
if ( V_2 -> V_198 )
V_191 = ( V_2 -> V_181 - 2 ) ;
else
V_191 = ( V_2 -> V_181 - 1 ) ;
} else {
V_191 = ( V_2 -> V_181 - 1 ) ;
}
while ( V_189 ) {
T_1 V_200 = ( V_186 -> V_17 - V_3 ) ;
T_1 V_201 = F_96 ( T_1 , V_189 , V_200 ) ;
V_202:
V_175 = V_15 -> V_203 -> V_204 -> V_205 ( V_15 -> V_203 ,
F_97 ( V_186 ) , V_186 -> V_3 + V_3 , V_201 , 0 ) ;
if ( V_175 != V_201 ) {
if ( V_175 == - V_184 ) {
F_3 ( L_41
L_42 ) ;
goto V_202;
}
F_3 ( L_43 ,
V_175 ) ;
return - 1 ;
}
V_189 -= V_201 ;
V_3 = 0 ;
V_186 = F_98 ( V_186 ) ;
}
V_206:
if ( V_2 -> V_198 ) {
struct V_178 * V_207 = & V_2 -> V_98 [ V_191 ++ ] ;
V_175 = F_94 ( V_15 , V_207 , 1 , V_2 -> V_198 ) ;
if ( V_2 -> V_198 != V_175 ) {
if ( V_175 == - V_184 ) {
F_3 ( L_40 ) ;
goto V_206;
}
return - 1 ;
}
}
V_208:
if ( V_15 -> V_120 -> V_199 ) {
struct V_178 * V_209 = & V_2 -> V_98 [ V_191 ] ;
V_175 = F_94 ( V_15 , V_209 , 1 , V_194 ) ;
if ( V_194 != V_175 ) {
if ( V_175 == - V_184 ) {
F_3 ( L_40 ) ;
goto V_208;
}
return - 1 ;
}
}
return 0 ;
}
int F_99 ( struct V_21 * V_15 , T_5 V_210 , T_5 V_211 )
{
struct V_212 * V_58 ;
struct V_213 * V_214 = V_15 -> V_215 ;
V_214 -> V_216 = 1 ;
F_100 ( V_15 , V_210 , V_211 ) ;
V_58 = (struct V_212 * ) & V_214 -> V_217 [ 0 ] ;
V_58 -> V_218 = V_219 ;
V_58 -> V_210 = V_210 ;
V_58 -> V_211 = V_211 ;
V_58 -> V_220 = V_15 -> V_221 ;
return V_15 -> V_26 -> V_222 ( V_15 , V_214 , 0 ) ;
}
void F_101 ( struct V_40 * V_41 )
{
struct V_21 * V_15 ;
F_26 ( L_44
L_45 , V_41 -> V_149 ) ;
F_8 ( & V_41 -> V_129 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_102 ( V_15 -> V_120 ) ;
F_6 ( & V_41 -> V_129 ) ;
F_103 ( V_41 -> V_61 ) ;
}
static int F_104 (
struct V_21 * V_15 ,
struct V_223 * V_224 )
{
int V_145 = V_224 -> V_69 , V_225 = 0 , V_226 = 0 , V_197 ;
struct V_178 * V_207 ;
struct V_227 V_228 ;
if ( ! V_15 || ! V_15 -> V_203 || ! V_15 -> V_120 )
return - 1 ;
memset ( & V_228 , 0 , sizeof( struct V_227 ) ) ;
V_207 = V_224 -> V_179 ;
V_197 = V_224 -> V_177 ;
while ( V_226 < V_145 ) {
V_225 = F_105 ( V_15 -> V_203 , & V_228 , V_207 , V_197 ,
( V_145 - V_226 ) , V_229 ) ;
if ( V_225 <= 0 ) {
F_26 ( L_46 ,
V_225 , V_226 ) ;
return V_225 ;
}
V_226 += V_225 ;
F_26 ( L_47 ,
V_225 , V_226 , V_145 ) ;
}
return V_226 ;
}
static int F_106 (
struct V_21 * V_15 ,
struct V_223 * V_224 )
{
int V_145 = V_224 -> V_69 , V_230 = 0 , V_231 = 0 , V_197 ;
struct V_178 * V_207 ;
struct V_227 V_228 ;
if ( ! V_15 || ! V_15 -> V_203 || ! V_15 -> V_120 )
return - 1 ;
if ( V_145 <= 0 ) {
F_3 ( L_48 , V_145 ) ;
return - 1 ;
}
memset ( & V_228 , 0 , sizeof( struct V_227 ) ) ;
V_207 = V_224 -> V_179 ;
V_197 = V_224 -> V_177 ;
while ( V_230 < V_145 ) {
V_231 = F_107 ( V_15 -> V_203 , & V_228 , V_207 , V_197 ,
( V_145 - V_230 ) ) ;
if ( V_231 <= 0 ) {
F_26 ( L_49 ,
V_231 , V_230 ) ;
return V_231 ;
}
V_230 += V_231 ;
F_26 ( L_50 ,
V_231 , V_230 , V_145 ) ;
}
return V_230 ;
}
int F_108 (
struct V_21 * V_15 ,
struct V_178 * V_179 ,
int V_177 ,
int V_145 )
{
struct V_223 V_232 ;
if ( ! V_15 || ! V_15 -> V_203 || ! V_15 -> V_120 )
return - 1 ;
memset ( & V_232 , 0 , sizeof( struct V_223 ) ) ;
V_232 . V_179 = V_179 ;
V_232 . V_177 = V_177 ;
V_232 . V_69 = V_145 ;
V_232 . type = V_233 ;
return F_104 ( V_15 , & V_232 ) ;
}
int F_94 (
struct V_21 * V_15 ,
struct V_178 * V_179 ,
int V_177 ,
int V_145 )
{
struct V_223 V_232 ;
if ( ! V_15 || ! V_15 -> V_203 || ! V_15 -> V_120 )
return - 1 ;
memset ( & V_232 , 0 , sizeof( struct V_223 ) ) ;
V_232 . V_179 = V_179 ;
V_232 . V_177 = V_177 ;
V_232 . V_69 = V_145 ;
V_232 . type = V_234 ;
return F_106 ( V_15 , & V_232 ) ;
}
void F_100 (
struct V_21 * V_15 ,
T_5 V_210 ,
T_5 V_211 )
{
struct V_235 * V_236 = NULL ;
struct V_153 * V_154 ;
struct V_237 * V_238 ;
V_154 = F_109 ( V_15 ) ;
if ( ! V_154 )
return;
V_238 = & V_154 -> V_239 ;
F_43 ( & V_238 -> V_157 ) ;
if ( ! strcmp ( V_15 -> V_240 , V_238 -> V_241 ) &&
( ( F_84 () - V_238 -> V_242 ) < 10 ) ) {
F_44 ( & V_238 -> V_157 ) ;
return;
}
if ( V_210 == V_243 )
V_238 -> V_244 ++ ;
else if ( V_210 == V_245 ) {
V_238 -> V_246 ++ ;
V_238 -> V_247 = V_248 ;
} else if ( ( V_210 == V_249 ) &&
( V_211 == V_250 ) ) {
V_238 -> V_251 ++ ;
V_238 -> V_247 = V_252 ;
} else if ( ( V_210 == V_249 ) &&
( V_211 == V_253 ) ) {
V_238 -> V_254 ++ ;
V_238 -> V_247 = V_255 ;
} else if ( ( V_210 == V_249 ) &&
( V_211 == V_256 ) ) {
V_238 -> V_257 ++ ;
V_238 -> V_247 = V_258 ;
} else {
V_238 -> V_259 ++ ;
V_238 -> V_247 = V_260 ;
}
if ( V_210 != V_243 ) {
if ( V_15 -> V_261 )
V_236 = F_110 ( V_262 ,
V_15 -> V_261 ) ;
strcpy ( V_238 -> V_263 ,
( V_236 ? V_236 -> V_264 : L_51 ) ) ;
V_238 -> V_265 = V_15 -> V_266 ;
snprintf ( V_238 -> V_241 , V_267 ,
L_52 , V_15 -> V_240 ) ;
V_238 -> V_242 = F_84 () ;
}
F_44 ( & V_238 -> V_157 ) ;
}
struct V_153 * F_109 ( struct V_21 * V_15 )
{
struct V_151 * V_152 ;
if ( ! V_15 || ! V_15 -> V_41 )
return NULL ;
V_152 = V_15 -> V_41 -> V_152 ;
if ( ! V_152 )
return NULL ;
if ( ! V_152 -> V_155 )
return NULL ;
return V_152 -> V_155 ;
}
