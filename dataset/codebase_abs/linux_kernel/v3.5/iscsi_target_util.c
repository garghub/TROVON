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
struct V_31 * F_20 (
struct V_1 * V_2 ,
T_1 V_32 )
{
T_1 V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( V_2 -> V_35 [ V_33 ] . V_32 == V_32 )
return & V_2 -> V_35 [ V_33 ] ;
return NULL ;
}
struct V_31 * F_21 ( struct V_1 * V_2 )
{
T_1 V_33 ;
if ( ! V_2 -> V_35 ) {
F_3 ( L_7 ) ;
return NULL ;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
if ( V_2 -> V_35 [ V_33 ] . type != V_36 )
continue;
if ( V_2 -> V_35 [ V_33 ] . V_32 == V_2 -> V_32 ) {
V_2 -> V_32 ++ ;
return & V_2 -> V_35 [ V_33 ] ;
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
static inline int F_23 ( struct V_37 * V_38 , T_1 V_39 )
{
int V_40 ;
if ( F_24 ( V_39 , V_38 -> V_41 ) ) {
F_3 ( L_8
L_9 , V_39 ,
V_38 -> V_41 ) ;
V_40 = V_42 ;
} else if ( V_39 == V_38 -> V_43 ) {
V_38 -> V_43 ++ ;
F_25 ( L_10
L_11 ,
V_38 -> V_43 ) ;
V_40 = V_44 ;
} else if ( F_24 ( V_39 , V_38 -> V_43 ) ) {
F_25 ( L_12
L_13 ,
V_39 , V_38 -> V_43 ) ;
V_40 = V_45 ;
} else {
F_3 ( L_14
L_15 , V_39 ,
V_38 -> V_43 ) ;
V_40 = V_46 ;
}
return V_40 ;
}
int F_26 (
struct V_21 * V_15 ,
struct V_1 * V_2 ,
T_1 V_39 )
{
int V_40 ;
int V_47 ;
F_27 ( & V_15 -> V_38 -> V_48 ) ;
V_47 = F_23 ( V_15 -> V_38 , V_39 ) ;
switch ( V_47 ) {
case V_44 :
V_40 = F_28 ( V_2 , 0 ) ;
if ( ( V_40 >= 0 ) && ! F_29 ( & V_15 -> V_38 -> V_49 ) )
F_30 ( V_15 -> V_38 ) ;
break;
case V_45 :
V_40 = F_31 ( V_15 -> V_38 , V_2 , V_39 ) ;
break;
case V_46 :
V_2 -> V_50 = V_51 ;
F_7 ( V_2 , V_15 , V_2 -> V_50 ) ;
V_40 = V_47 ;
break;
default:
V_40 = V_47 ;
break;
}
F_32 ( & V_15 -> V_38 -> V_48 ) ;
return V_40 ;
}
int F_33 ( struct V_1 * V_2 , unsigned char * V_52 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_53 * V_53 = & V_2 -> V_53 ;
struct V_54 * V_55 = (struct V_54 * ) V_52 ;
T_1 V_56 = F_34 ( V_55 -> V_57 ) ;
if ( V_15 -> V_38 -> V_58 -> V_59 ) {
F_3 ( L_16
L_17 ) ;
F_35 ( V_53 ,
V_60 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_61 + V_56 ) >
V_15 -> V_38 -> V_58 -> V_62 ) {
F_3 ( L_18
L_19 ,
( V_2 -> V_61 + V_56 ) ,
V_15 -> V_38 -> V_58 -> V_62 ) ;
F_35 ( V_53 ,
V_63 , 0 ) ;
return - 1 ;
}
if ( ! ( V_55 -> V_64 & V_65 ) )
return 0 ;
if ( ( ( V_2 -> V_61 + V_56 ) != V_2 -> V_53 . V_66 ) &&
( ( V_2 -> V_61 + V_56 ) !=
V_15 -> V_38 -> V_58 -> V_62 ) ) {
F_3 ( L_20
L_21
L_22 ,
( V_2 -> V_61 + V_56 ) ,
V_15 -> V_38 -> V_58 -> V_62 , V_2 -> V_53 . V_66 ) ;
F_35 ( V_53 ,
V_63 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_36 (
struct V_21 * V_15 ,
T_1 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_67 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_67 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_67 ) ;
F_3 ( L_23 ,
V_19 , V_15 -> V_68 ) ;
return NULL ;
}
struct V_1 * F_37 (
struct V_21 * V_15 ,
T_1 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_67 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_67 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_67 ) ;
F_3 ( L_24
L_25 , V_19 , V_15 -> V_68 ) ;
if ( V_17 )
F_38 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_39 (
struct V_21 * V_15 ,
T_1 V_69 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_67 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_69 == V_69 ) {
F_6 ( & V_15 -> V_67 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_67 ) ;
F_3 ( L_26 ,
V_69 , V_15 -> V_68 ) ;
return NULL ;
}
int F_40 (
struct V_37 * V_38 ,
struct V_1 * * V_70 ,
struct V_71 * * V_72 ,
T_1 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_71 * V_73 ;
F_41 ( & V_38 -> V_74 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_41 ( & V_73 -> V_75 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_42 ( & V_73 -> V_75 ) ;
F_42 ( & V_38 -> V_74 ) ;
* V_72 = V_73 ;
* V_70 = V_2 ;
return - 2 ;
}
}
F_42 ( & V_73 -> V_75 ) ;
}
F_42 ( & V_38 -> V_74 ) ;
F_41 ( & V_38 -> V_76 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_41 ( & V_73 -> V_75 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_42 ( & V_73 -> V_75 ) ;
F_42 ( & V_38 -> V_76 ) ;
* V_72 = V_73 ;
* V_70 = V_2 ;
return 0 ;
}
}
F_42 ( & V_73 -> V_75 ) ;
}
F_42 ( & V_38 -> V_76 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_77 )
{
struct V_78 * V_79 ;
V_79 = F_2 ( V_80 , V_10 ) ;
if ( ! V_79 ) {
F_3 ( L_27
L_28 ) ;
return;
}
F_4 ( & V_79 -> V_81 ) ;
V_79 -> V_2 = V_2 ;
V_79 -> V_77 = V_77 ;
F_8 ( & V_15 -> V_82 ) ;
F_5 ( & V_79 -> V_81 , & V_15 -> V_83 ) ;
F_43 ( & V_2 -> V_84 ) ;
F_44 ( & V_15 -> V_85 , 1 ) ;
F_6 ( & V_15 -> V_82 ) ;
F_45 ( V_15 -> V_86 -> V_87 ) ;
}
struct V_78 * F_46 ( struct V_21 * V_15 )
{
struct V_78 * V_79 ;
F_8 ( & V_15 -> V_82 ) ;
if ( F_29 ( & V_15 -> V_83 ) ) {
F_6 ( & V_15 -> V_82 ) ;
return NULL ;
}
F_10 (qr, &conn->immed_queue_list, qr_list)
break;
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_47 ( & V_79 -> V_2 -> V_84 ) ;
F_6 ( & V_15 -> V_82 ) ;
return V_79 ;
}
static void F_48 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_78 * V_79 , * V_88 ;
F_8 ( & V_15 -> V_82 ) ;
if ( ! F_49 ( & V_2 -> V_84 ) ) {
F_6 ( & V_15 -> V_82 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_79 -> V_2 != V_2 )
continue;
F_47 ( & V_79 -> V_2 -> V_84 ) ;
F_13 ( & V_79 -> V_81 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_82 ) ;
if ( F_49 ( & V_2 -> V_84 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_49 ( & V_2 -> V_84 ) ) ;
}
}
void F_50 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_77 )
{
struct V_78 * V_79 ;
V_79 = F_2 ( V_80 , V_10 ) ;
if ( ! V_79 ) {
F_3 ( L_27
L_28 ) ;
return;
}
F_4 ( & V_79 -> V_81 ) ;
V_79 -> V_2 = V_2 ;
V_79 -> V_77 = V_77 ;
F_8 ( & V_15 -> V_89 ) ;
F_5 ( & V_79 -> V_81 , & V_15 -> V_90 ) ;
F_43 ( & V_2 -> V_91 ) ;
F_6 ( & V_15 -> V_89 ) ;
F_45 ( V_15 -> V_86 -> V_87 ) ;
}
struct V_78 * F_51 ( struct V_21 * V_15 )
{
struct V_78 * V_79 ;
F_8 ( & V_15 -> V_89 ) ;
if ( F_29 ( & V_15 -> V_90 ) ) {
F_6 ( & V_15 -> V_89 ) ;
return NULL ;
}
F_10 (qr, &conn->response_queue_list, qr_list)
break;
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_47 ( & V_79 -> V_2 -> V_91 ) ;
F_6 ( & V_15 -> V_89 ) ;
return V_79 ;
}
static void F_52 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_78 * V_79 , * V_88 ;
F_8 ( & V_15 -> V_89 ) ;
if ( ! F_49 ( & V_2 -> V_91 ) ) {
F_6 ( & V_15 -> V_89 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_79 -> V_2 != V_2 )
continue;
F_47 ( & V_79 -> V_2 -> V_91 ) ;
F_13 ( & V_79 -> V_81 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_89 ) ;
if ( F_49 ( & V_2 -> V_91 ) ) {
F_3 ( L_30 ,
V_2 -> V_19 ,
F_49 ( & V_2 -> V_91 ) ) ;
}
}
void F_53 ( struct V_21 * V_15 )
{
struct V_78 * V_79 , * V_88 ;
F_8 ( & V_15 -> V_82 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_47 ( & V_79 -> V_2 -> V_84 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_82 ) ;
F_8 ( & V_15 -> V_89 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_47 ( & V_79 -> V_2 -> V_91 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_89 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
F_15 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 -> V_92 ) ;
F_56 ( V_2 -> V_93 ) ;
F_56 ( V_2 -> V_35 ) ;
F_56 ( V_2 -> V_94 ) ;
F_56 ( V_2 -> V_95 ) ;
if ( V_15 ) {
F_48 ( V_2 , V_15 ) ;
F_52 ( V_2 , V_15 ) ;
}
F_14 ( V_23 , V_2 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_96 ) {
case V_97 :
case V_98 :
F_58 ( & V_2 -> V_53 , 1 ) ;
break;
case V_99 :
if ( V_2 -> V_53 . V_100 != NULL ) {
F_58 ( & V_2 -> V_53 , 1 ) ;
break;
}
default:
F_54 ( V_2 ) ;
break;
}
}
int F_59 ( struct V_37 * V_38 )
{
F_8 ( & V_38 -> V_101 ) ;
if ( V_38 -> V_102 != 0 ) {
V_38 -> V_103 = 1 ;
F_6 ( & V_38 -> V_101 ) ;
if ( F_60 () )
return 2 ;
F_61 ( & V_38 -> V_104 ) ;
return 1 ;
}
F_6 ( & V_38 -> V_101 ) ;
return 0 ;
}
void F_62 ( struct V_37 * V_38 )
{
F_8 ( & V_38 -> V_101 ) ;
V_38 -> V_102 -- ;
if ( ! V_38 -> V_102 && V_38 -> V_103 )
F_63 ( & V_38 -> V_104 ) ;
F_6 ( & V_38 -> V_101 ) ;
}
void F_64 ( struct V_37 * V_38 )
{
F_8 ( & V_38 -> V_101 ) ;
V_38 -> V_102 ++ ;
F_6 ( & V_38 -> V_101 ) ;
}
int F_65 ( struct V_21 * V_15 )
{
int V_105 = 0 , V_106 = 0 , V_107 = 0 ;
T_1 V_108 = ( V_15 -> V_109 -> V_108 * 4 ) ;
T_1 V_110 = ( V_15 -> V_109 -> V_110 * 4 ) ;
if ( V_15 -> V_109 -> V_111 ) {
V_15 -> V_112 += V_113 ;
if ( V_15 -> V_112 <= V_110 ) {
V_15 -> V_112 = ( V_110 - V_15 -> V_112 ) ;
} else {
V_106 = ( V_15 -> V_112 / V_110 ) ;
V_107 = ( V_110 * ( V_106 + 1 ) ) +
( V_106 * V_114 ) ;
V_15 -> V_112 = ( V_107 - V_15 -> V_112 ) ;
}
V_15 -> V_115 = 0 ;
F_25 ( L_31
L_32 , V_15 -> V_112 ) ;
}
if ( V_15 -> V_109 -> V_116 ) {
if ( V_15 -> V_117 <= V_108 ) {
V_15 -> V_117 = ( V_108 - V_15 -> V_117 ) ;
} else {
V_105 = ( V_15 -> V_117 / V_108 ) ;
V_107 = ( V_108 * ( V_105 + 1 ) ) +
( V_105 * V_114 ) ;
V_15 -> V_117 = ( V_107 - V_15 -> V_117 ) ;
}
F_25 ( L_33
L_32 , V_15 -> V_117 ) ;
}
return 0 ;
}
struct V_21 * F_66 ( struct V_37 * V_38 , T_4 V_68 )
{
struct V_21 * V_15 ;
F_8 ( & V_38 -> V_118 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_68 == V_68 ) &&
( V_15 -> V_119 == V_120 ) ) {
F_67 ( V_15 ) ;
F_6 ( & V_38 -> V_118 ) ;
return V_15 ;
}
}
F_6 ( & V_38 -> V_118 ) ;
return NULL ;
}
struct V_21 * F_68 ( struct V_37 * V_38 , T_4 V_68 )
{
struct V_21 * V_15 ;
F_8 ( & V_38 -> V_118 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_68 == V_68 ) {
F_67 ( V_15 ) ;
F_41 ( & V_15 -> V_121 ) ;
F_44 ( & V_15 -> V_122 , 1 ) ;
F_42 ( & V_15 -> V_121 ) ;
F_6 ( & V_38 -> V_118 ) ;
return V_15 ;
}
}
F_6 ( & V_38 -> V_118 ) ;
return NULL ;
}
void F_69 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_123 ) ;
if ( V_15 -> V_124 != 0 ) {
V_15 -> V_125 = 1 ;
F_6 ( & V_15 -> V_123 ) ;
F_61 ( & V_15 -> V_126 ) ;
return;
}
F_6 ( & V_15 -> V_123 ) ;
}
void F_70 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_123 ) ;
V_15 -> V_124 -- ;
if ( ! V_15 -> V_124 && V_15 -> V_125 )
F_63 ( & V_15 -> V_126 ) ;
F_6 ( & V_15 -> V_123 ) ;
}
void F_67 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_123 ) ;
V_15 -> V_124 ++ ;
F_6 ( & V_15 -> V_123 ) ;
}
static int F_71 ( struct V_21 * V_15 , int V_127 )
{
T_3 V_77 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_96 = V_128 ;
V_77 = ( V_127 ) ? V_129 :
V_130 ;
V_2 -> V_19 = 0xFFFFFFFF ;
F_8 ( & V_15 -> V_38 -> V_131 ) ;
V_2 -> V_69 = ( V_127 ) ? V_15 -> V_38 -> V_69 ++ :
0xFFFFFFFF ;
if ( V_127 && ( V_2 -> V_69 == 0xFFFFFFFF ) )
V_2 -> V_69 = V_15 -> V_38 -> V_69 ++ ;
F_6 ( & V_15 -> V_38 -> V_131 ) ;
F_8 ( & V_15 -> V_67 ) ;
F_5 ( & V_2 -> V_24 , & V_15 -> V_132 ) ;
F_6 ( & V_15 -> V_67 ) ;
if ( V_127 )
F_72 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_77 ) ;
return 0 ;
}
static void F_73 ( unsigned long V_133 )
{
struct V_21 * V_15 = (struct V_21 * ) V_133 ;
F_67 ( V_15 ) ;
F_8 ( & V_15 -> V_134 ) ;
if ( V_15 -> V_135 & V_136 ) {
F_6 ( & V_15 -> V_134 ) ;
F_70 ( V_15 ) ;
return;
}
F_25 ( L_34
L_35 , V_15 -> V_68 ,
V_15 -> V_38 -> V_137 ) ;
V_15 -> V_135 &= ~ V_138 ;
F_6 ( & V_15 -> V_134 ) ;
{
struct V_139 * V_140 = V_15 -> V_38 -> V_140 ;
struct V_141 * V_142 = V_140 -> V_143 ;
if ( V_142 ) {
F_8 ( & V_142 -> V_144 . V_145 ) ;
strcpy ( V_142 -> V_144 . V_146 ,
V_15 -> V_38 -> V_58 -> V_147 ) ;
V_142 -> V_144 . V_148 =
V_149 ;
V_142 -> V_144 . V_150 ++ ;
V_15 -> V_38 -> V_151 ++ ;
F_6 ( & V_142 -> V_144 . V_145 ) ;
}
}
F_74 ( V_15 , 0 ) ;
F_70 ( V_15 ) ;
}
void F_75 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_152 * V_153 = F_76 ( V_38 ) ;
F_8 ( & V_15 -> V_134 ) ;
if ( ! ( V_15 -> V_135 & V_138 ) ) {
F_6 ( & V_15 -> V_134 ) ;
return;
}
F_77 ( & V_15 -> V_154 ,
( F_78 () + V_153 -> V_155 * V_156 ) ) ;
F_6 ( & V_15 -> V_134 ) ;
}
void F_72 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_152 * V_153 = F_76 ( V_38 ) ;
F_8 ( & V_15 -> V_134 ) ;
if ( V_15 -> V_135 & V_138 ) {
F_6 ( & V_15 -> V_134 ) ;
return;
}
F_79 ( & V_15 -> V_154 ) ;
V_15 -> V_154 . V_157 =
( F_78 () + V_153 -> V_155 * V_156 ) ;
V_15 -> V_154 . V_133 = ( unsigned long ) V_15 ;
V_15 -> V_154 . V_158 = F_73 ;
V_15 -> V_135 &= ~ V_136 ;
V_15 -> V_135 |= V_138 ;
F_80 ( & V_15 -> V_154 ) ;
F_25 ( L_36
L_37 , V_15 -> V_68 , V_153 -> V_155 ) ;
F_6 ( & V_15 -> V_134 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_134 ) ;
if ( ! ( V_15 -> V_135 & V_138 ) ) {
F_6 ( & V_15 -> V_134 ) ;
return;
}
V_15 -> V_135 |= V_136 ;
F_6 ( & V_15 -> V_134 ) ;
F_82 ( & V_15 -> V_154 ) ;
F_8 ( & V_15 -> V_134 ) ;
V_15 -> V_135 &= ~ V_138 ;
F_6 ( & V_15 -> V_134 ) ;
}
static void F_83 ( unsigned long V_133 )
{
struct V_21 * V_15 = (struct V_21 * ) V_133 ;
F_67 ( V_15 ) ;
F_8 ( & V_15 -> V_134 ) ;
if ( V_15 -> V_159 & V_136 ) {
F_6 ( & V_15 -> V_134 ) ;
F_70 ( V_15 ) ;
return;
}
V_15 -> V_159 &= ~ V_138 ;
F_6 ( & V_15 -> V_134 ) ;
F_71 ( V_15 , 1 ) ;
F_70 ( V_15 ) ;
}
void F_84 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_152 * V_153 = F_76 ( V_38 ) ;
if ( ! V_153 -> V_160 )
return;
if ( V_15 -> V_159 & V_138 )
return;
F_79 ( & V_15 -> V_161 ) ;
V_15 -> V_161 . V_157 = ( F_78 () + V_153 -> V_160 * V_156 ) ;
V_15 -> V_161 . V_133 = ( unsigned long ) V_15 ;
V_15 -> V_161 . V_158 = F_83 ;
V_15 -> V_159 &= ~ V_136 ;
V_15 -> V_159 |= V_138 ;
F_80 ( & V_15 -> V_161 ) ;
F_25 ( L_38
L_39 , V_15 -> V_68 , V_153 -> V_160 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_152 * V_153 = F_76 ( V_38 ) ;
if ( ! V_153 -> V_160 )
return;
F_8 ( & V_15 -> V_134 ) ;
if ( V_15 -> V_159 & V_138 ) {
F_6 ( & V_15 -> V_134 ) ;
return;
}
F_79 ( & V_15 -> V_161 ) ;
V_15 -> V_161 . V_157 = ( F_78 () + V_153 -> V_160 * V_156 ) ;
V_15 -> V_161 . V_133 = ( unsigned long ) V_15 ;
V_15 -> V_161 . V_158 = F_83 ;
V_15 -> V_159 &= ~ V_136 ;
V_15 -> V_159 |= V_138 ;
F_80 ( & V_15 -> V_161 ) ;
F_25 ( L_38
L_39 , V_15 -> V_68 , V_153 -> V_160 ) ;
F_6 ( & V_15 -> V_134 ) ;
}
void F_86 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_134 ) ;
if ( ! ( V_15 -> V_159 & V_138 ) ) {
F_6 ( & V_15 -> V_134 ) ;
return;
}
V_15 -> V_159 |= V_136 ;
F_6 ( & V_15 -> V_134 ) ;
F_82 ( & V_15 -> V_161 ) ;
F_8 ( & V_15 -> V_134 ) ;
V_15 -> V_159 &= ~ V_138 ;
F_6 ( & V_15 -> V_134 ) ;
}
int F_87 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_162 )
{
int V_163 , V_164 ;
T_1 V_165 ;
struct V_166 * V_167 ;
V_168:
V_164 = V_2 -> V_164 ;
if ( ! V_162 ) {
V_167 = & V_2 -> V_95 [ 0 ] ;
V_165 = V_2 -> V_169 ;
} else {
V_167 = & V_2 -> V_170 [ 0 ] ;
V_165 = V_2 -> V_171 ;
}
V_163 = F_88 ( V_15 , & V_167 [ 0 ] , V_165 , V_164 ) ;
if ( V_164 != V_163 ) {
if ( V_163 == - V_172 ) {
F_3 ( L_40 ) ;
goto V_168;
} else
return - 1 ;
}
V_2 -> V_164 = 0 ;
return 0 ;
}
int F_89 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_173 * V_174 = V_2 -> V_175 ;
struct V_166 V_167 ;
T_1 V_176 , V_177 ;
T_1 V_3 = V_2 -> V_178 ;
int V_163 , V_179 ;
V_180:
V_176 = V_113 ;
if ( V_15 -> V_109 -> V_181 )
V_176 += V_182 ;
V_167 . V_183 = V_2 -> V_184 ;
V_167 . V_185 = V_176 ;
V_163 = F_88 ( V_15 , & V_167 , 1 , V_176 ) ;
if ( V_176 != V_163 ) {
if ( V_163 == - V_172 ) {
F_3 ( L_40 ) ;
goto V_180;
}
return - 1 ;
}
V_177 = V_2 -> V_164 - V_176 - V_2 -> V_186 ;
if ( V_15 -> V_109 -> V_187 ) {
V_177 -= V_182 ;
if ( V_2 -> V_186 )
V_179 = ( V_2 -> V_169 - 2 ) ;
else
V_179 = ( V_2 -> V_169 - 1 ) ;
} else {
V_179 = ( V_2 -> V_169 - 1 ) ;
}
while ( V_177 ) {
T_1 V_188 = ( V_174 -> V_17 - V_3 ) ;
T_1 V_189 = F_90 ( T_1 , V_177 , V_188 ) ;
V_190:
V_163 = V_15 -> V_191 -> V_192 -> V_193 ( V_15 -> V_191 ,
F_91 ( V_174 ) , V_174 -> V_3 + V_3 , V_189 , 0 ) ;
if ( V_163 != V_189 ) {
if ( V_163 == - V_172 ) {
F_3 ( L_41
L_42 ) ;
goto V_190;
}
F_3 ( L_43 ,
V_163 ) ;
return - 1 ;
}
V_177 -= V_189 ;
V_3 = 0 ;
V_174 = F_92 ( V_174 ) ;
}
V_194:
if ( V_2 -> V_186 ) {
struct V_166 * V_195 = & V_2 -> V_95 [ V_179 ++ ] ;
V_163 = F_88 ( V_15 , V_195 , 1 , V_2 -> V_186 ) ;
if ( V_2 -> V_186 != V_163 ) {
if ( V_163 == - V_172 ) {
F_3 ( L_40 ) ;
goto V_194;
}
return - 1 ;
}
}
V_196:
if ( V_15 -> V_109 -> V_187 ) {
struct V_166 * V_197 = & V_2 -> V_95 [ V_179 ] ;
V_163 = F_88 ( V_15 , V_197 , 1 , V_182 ) ;
if ( V_182 != V_163 ) {
if ( V_163 == - V_172 ) {
F_3 ( L_40 ) ;
goto V_196;
}
return - 1 ;
}
}
return 0 ;
}
int F_93 ( struct V_21 * V_15 , T_3 V_198 , T_3 V_199 )
{
T_3 V_200 [ V_113 ] ;
int V_201 ;
struct V_166 V_167 ;
struct V_202 * V_55 ;
F_94 ( V_15 , V_198 , V_199 ) ;
memset ( & V_167 , 0 , sizeof( struct V_166 ) ) ;
memset ( & V_200 , 0x0 , V_113 ) ;
V_55 = (struct V_202 * ) & V_200 ;
V_55 -> V_203 = V_204 ;
V_55 -> V_198 = V_198 ;
V_55 -> V_199 = V_199 ;
V_55 -> V_205 = F_95 ( V_15 -> V_206 ) ;
V_167 . V_183 = & V_200 ;
V_167 . V_185 = V_113 ;
F_96 ( V_200 , V_113 ) ;
V_201 = F_88 ( V_15 , & V_167 , 1 , V_113 ) ;
if ( V_201 != V_113 ) {
F_3 ( L_44 ) ;
return - 1 ;
}
return 0 ;
}
void F_97 ( struct V_37 * V_38 )
{
struct V_21 * V_15 ;
F_25 ( L_45
L_46 , V_38 -> V_137 ) ;
F_8 ( & V_38 -> V_118 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_98 ( V_15 -> V_109 ) ;
F_6 ( & V_38 -> V_118 ) ;
F_99 ( V_38 -> V_58 ) ;
}
static int F_100 (
struct V_21 * V_15 ,
struct V_207 * V_208 )
{
int V_133 = V_208 -> V_66 , V_209 = 0 , V_210 = 0 , V_185 ;
struct V_166 * V_195 ;
struct V_211 V_212 ;
if ( ! V_15 || ! V_15 -> V_191 || ! V_15 -> V_109 )
return - 1 ;
memset ( & V_212 , 0 , sizeof( struct V_211 ) ) ;
V_195 = V_208 -> V_167 ;
V_185 = V_208 -> V_165 ;
while ( V_210 < V_133 ) {
V_209 = F_101 ( V_15 -> V_191 , & V_212 , V_195 , V_185 ,
( V_133 - V_210 ) , V_213 ) ;
if ( V_209 <= 0 ) {
F_25 ( L_47 ,
V_209 , V_210 ) ;
return V_209 ;
}
V_210 += V_209 ;
F_25 ( L_48 ,
V_209 , V_210 , V_133 ) ;
}
return V_210 ;
}
static int F_102 (
struct V_21 * V_15 ,
struct V_207 * V_208 )
{
int V_133 = V_208 -> V_66 , V_214 = 0 , V_215 = 0 , V_185 ;
struct V_166 * V_195 ;
struct V_211 V_212 ;
if ( ! V_15 || ! V_15 -> V_191 || ! V_15 -> V_109 )
return - 1 ;
if ( V_133 <= 0 ) {
F_3 ( L_49 , V_133 ) ;
return - 1 ;
}
memset ( & V_212 , 0 , sizeof( struct V_211 ) ) ;
V_195 = V_208 -> V_167 ;
V_185 = V_208 -> V_165 ;
while ( V_214 < V_133 ) {
V_215 = F_103 ( V_15 -> V_191 , & V_212 , V_195 , V_185 ,
( V_133 - V_214 ) ) ;
if ( V_215 <= 0 ) {
F_25 ( L_50 ,
V_215 , V_214 ) ;
return V_215 ;
}
V_214 += V_215 ;
F_25 ( L_51 ,
V_215 , V_214 , V_133 ) ;
}
return V_214 ;
}
int F_104 (
struct V_21 * V_15 ,
struct V_166 * V_167 ,
int V_165 ,
int V_133 )
{
struct V_207 V_216 ;
if ( ! V_15 || ! V_15 -> V_191 || ! V_15 -> V_109 )
return - 1 ;
memset ( & V_216 , 0 , sizeof( struct V_207 ) ) ;
V_216 . V_167 = V_167 ;
V_216 . V_165 = V_165 ;
V_216 . V_66 = V_133 ;
V_216 . type = V_217 ;
return F_100 ( V_15 , & V_216 ) ;
}
int F_88 (
struct V_21 * V_15 ,
struct V_166 * V_167 ,
int V_165 ,
int V_133 )
{
struct V_207 V_216 ;
if ( ! V_15 || ! V_15 -> V_191 || ! V_15 -> V_109 )
return - 1 ;
memset ( & V_216 , 0 , sizeof( struct V_207 ) ) ;
V_216 . V_167 = V_167 ;
V_216 . V_165 = V_165 ;
V_216 . V_66 = V_133 ;
V_216 . type = V_218 ;
return F_102 ( V_15 , & V_216 ) ;
}
void F_94 (
struct V_21 * V_15 ,
T_3 V_198 ,
T_3 V_199 )
{
struct V_219 * V_220 = NULL ;
struct V_141 * V_142 ;
struct V_221 * V_222 ;
V_142 = F_105 ( V_15 ) ;
if ( ! V_142 )
return;
V_222 = & V_142 -> V_223 ;
F_41 ( & V_222 -> V_145 ) ;
if ( ! strcmp ( V_15 -> V_224 , V_222 -> V_225 ) &&
( ( F_78 () - V_222 -> V_226 ) < 10 ) ) {
F_42 ( & V_222 -> V_145 ) ;
return;
}
if ( V_198 == V_227 )
V_222 -> V_228 ++ ;
else if ( V_198 == V_229 ) {
V_222 -> V_230 ++ ;
V_222 -> V_231 = V_232 ;
} else if ( ( V_198 == V_233 ) &&
( V_199 == V_234 ) ) {
V_222 -> V_235 ++ ;
V_222 -> V_231 = V_236 ;
} else if ( ( V_198 == V_233 ) &&
( V_199 == V_237 ) ) {
V_222 -> V_238 ++ ;
V_222 -> V_231 = V_239 ;
} else if ( ( V_198 == V_233 ) &&
( V_199 == V_240 ) ) {
V_222 -> V_241 ++ ;
V_222 -> V_231 = V_242 ;
} else {
V_222 -> V_243 ++ ;
V_222 -> V_231 = V_244 ;
}
if ( V_198 != V_227 ) {
if ( V_15 -> V_245 )
V_220 = F_106 ( V_246 ,
V_15 -> V_245 ) ;
strcpy ( V_222 -> V_247 ,
( V_220 ? V_220 -> V_248 : L_52 ) ) ;
V_222 -> V_249 = V_15 -> V_191 -> V_250 -> V_251 ;
snprintf ( V_222 -> V_225 , V_252 ,
L_53 , V_15 -> V_224 ) ;
V_222 -> V_226 = F_78 () ;
}
F_42 ( & V_222 -> V_145 ) ;
}
struct V_141 * F_105 ( struct V_21 * V_15 )
{
struct V_139 * V_140 ;
if ( ! V_15 || ! V_15 -> V_38 )
return NULL ;
V_140 = V_15 -> V_38 -> V_140 ;
if ( ! V_140 )
return NULL ;
if ( ! V_140 -> V_143 )
return NULL ;
return V_140 -> V_143 ;
}
