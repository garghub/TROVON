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
T_3 V_39 )
{
int V_40 ;
int V_47 ;
F_27 ( & V_15 -> V_38 -> V_48 ) ;
V_47 = F_23 ( V_15 -> V_38 , F_28 ( V_39 ) ) ;
switch ( V_47 ) {
case V_44 :
V_40 = F_29 ( V_2 , 0 ) ;
if ( ( V_40 >= 0 ) && ! F_30 ( & V_15 -> V_38 -> V_49 ) )
F_31 ( V_15 -> V_38 ) ;
break;
case V_45 :
V_40 = F_32 ( V_15 -> V_38 , V_2 , F_28 ( V_39 ) ) ;
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
F_33 ( & V_15 -> V_38 -> V_48 ) ;
return V_40 ;
}
int F_34 ( struct V_1 * V_2 , unsigned char * V_52 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_53 * V_53 = & V_2 -> V_53 ;
struct V_54 * V_55 = (struct V_54 * ) V_52 ;
T_1 V_56 = F_35 ( V_55 -> V_57 ) ;
if ( V_15 -> V_38 -> V_58 -> V_59 ) {
F_3 ( L_16
L_17 ) ;
F_36 ( V_53 ,
V_60 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_61 + V_56 ) >
V_15 -> V_38 -> V_58 -> V_62 ) {
F_3 ( L_18
L_19 ,
( V_2 -> V_61 + V_56 ) ,
V_15 -> V_38 -> V_58 -> V_62 ) ;
F_36 ( V_53 ,
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
F_36 ( V_53 ,
V_63 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_37 (
struct V_21 * V_15 ,
T_4 V_19 )
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
struct V_1 * F_38 (
struct V_21 * V_15 ,
T_4 V_19 ,
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
F_39 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_40 (
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
int F_41 (
struct V_37 * V_38 ,
struct V_1 * * V_70 ,
struct V_71 * * V_72 ,
T_4 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_71 * V_73 ;
F_42 ( & V_38 -> V_74 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_42 ( & V_73 -> V_75 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_43 ( & V_73 -> V_75 ) ;
F_43 ( & V_38 -> V_74 ) ;
* V_72 = V_73 ;
* V_70 = V_2 ;
return - 2 ;
}
}
F_43 ( & V_73 -> V_75 ) ;
}
F_43 ( & V_38 -> V_74 ) ;
F_42 ( & V_38 -> V_76 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_42 ( & V_73 -> V_75 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_43 ( & V_73 -> V_75 ) ;
F_43 ( & V_38 -> V_76 ) ;
* V_72 = V_73 ;
* V_70 = V_2 ;
return 0 ;
}
}
F_43 ( & V_73 -> V_75 ) ;
}
F_43 ( & V_38 -> V_76 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_5 V_77 )
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
F_44 ( & V_2 -> V_84 ) ;
F_45 ( & V_15 -> V_85 , 1 ) ;
F_6 ( & V_15 -> V_82 ) ;
F_46 ( & V_15 -> V_86 ) ;
}
struct V_78 * F_47 ( struct V_21 * V_15 )
{
struct V_78 * V_79 ;
F_8 ( & V_15 -> V_82 ) ;
if ( F_30 ( & V_15 -> V_83 ) ) {
F_6 ( & V_15 -> V_82 ) ;
return NULL ;
}
V_79 = F_48 ( & V_15 -> V_83 ,
struct V_78 , V_81 ) ;
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_49 ( & V_79 -> V_2 -> V_84 ) ;
F_6 ( & V_15 -> V_82 ) ;
return V_79 ;
}
static void F_50 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_78 * V_79 , * V_87 ;
F_8 ( & V_15 -> V_82 ) ;
if ( ! F_51 ( & V_2 -> V_84 ) ) {
F_6 ( & V_15 -> V_82 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_79 -> V_2 != V_2 )
continue;
F_49 ( & V_79 -> V_2 -> V_84 ) ;
F_13 ( & V_79 -> V_81 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_82 ) ;
if ( F_51 ( & V_2 -> V_84 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_51 ( & V_2 -> V_84 ) ) ;
}
}
void F_52 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_5 V_77 )
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
F_8 ( & V_15 -> V_88 ) ;
F_5 ( & V_79 -> V_81 , & V_15 -> V_89 ) ;
F_44 ( & V_2 -> V_90 ) ;
F_6 ( & V_15 -> V_88 ) ;
F_46 ( & V_15 -> V_86 ) ;
}
struct V_78 * F_53 ( struct V_21 * V_15 )
{
struct V_78 * V_79 ;
F_8 ( & V_15 -> V_88 ) ;
if ( F_30 ( & V_15 -> V_89 ) ) {
F_6 ( & V_15 -> V_88 ) ;
return NULL ;
}
V_79 = F_48 ( & V_15 -> V_89 ,
struct V_78 , V_81 ) ;
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_49 ( & V_79 -> V_2 -> V_90 ) ;
F_6 ( & V_15 -> V_88 ) ;
return V_79 ;
}
static void F_54 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_78 * V_79 , * V_87 ;
F_8 ( & V_15 -> V_88 ) ;
if ( ! F_51 ( & V_2 -> V_90 ) ) {
F_6 ( & V_15 -> V_88 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_79 -> V_2 != V_2 )
continue;
F_49 ( & V_79 -> V_2 -> V_90 ) ;
F_13 ( & V_79 -> V_81 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_88 ) ;
if ( F_51 ( & V_2 -> V_90 ) ) {
F_3 ( L_30 ,
V_2 -> V_19 ,
F_51 ( & V_2 -> V_90 ) ) ;
}
}
bool F_55 ( struct V_21 * V_15 )
{
bool V_91 ;
F_8 ( & V_15 -> V_82 ) ;
V_91 = F_30 ( & V_15 -> V_83 ) ;
F_6 ( & V_15 -> V_82 ) ;
if ( ! V_91 )
return V_91 ;
F_8 ( & V_15 -> V_88 ) ;
V_91 = F_30 ( & V_15 -> V_89 ) ;
F_6 ( & V_15 -> V_88 ) ;
return V_91 ;
}
void F_56 ( struct V_21 * V_15 )
{
struct V_78 * V_79 , * V_87 ;
F_8 ( & V_15 -> V_82 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_49 ( & V_79 -> V_2 -> V_84 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_82 ) ;
F_8 ( & V_15 -> V_88 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_79 -> V_81 ) ;
if ( V_79 -> V_2 )
F_49 ( & V_79 -> V_2 -> V_90 ) ;
F_14 ( V_80 , V_79 ) ;
}
F_6 ( & V_15 -> V_88 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
F_15 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 -> V_92 ) ;
F_59 ( V_2 -> V_93 ) ;
F_59 ( V_2 -> V_35 ) ;
F_59 ( V_2 -> V_94 ) ;
F_59 ( V_2 -> V_95 ) ;
if ( V_15 ) {
F_50 ( V_2 , V_15 ) ;
F_54 ( V_2 , V_15 ) ;
}
F_14 ( V_23 , V_2 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_96 ) {
case V_97 :
case V_98 :
F_61 ( & V_2 -> V_53 , 1 ) ;
break;
case V_99 :
if ( V_2 -> V_53 . V_100 != NULL ) {
F_61 ( & V_2 -> V_53 , 1 ) ;
break;
}
default:
F_57 ( V_2 ) ;
break;
}
}
int F_62 ( struct V_37 * V_38 )
{
F_8 ( & V_38 -> V_101 ) ;
if ( V_38 -> V_102 != 0 ) {
V_38 -> V_103 = 1 ;
F_6 ( & V_38 -> V_101 ) ;
if ( F_63 () )
return 2 ;
F_64 ( & V_38 -> V_104 ) ;
return 1 ;
}
F_6 ( & V_38 -> V_101 ) ;
return 0 ;
}
void F_65 ( struct V_37 * V_38 )
{
F_8 ( & V_38 -> V_101 ) ;
V_38 -> V_102 -- ;
if ( ! V_38 -> V_102 && V_38 -> V_103 )
F_66 ( & V_38 -> V_104 ) ;
F_6 ( & V_38 -> V_101 ) ;
}
void F_67 ( struct V_37 * V_38 )
{
F_8 ( & V_38 -> V_101 ) ;
V_38 -> V_102 ++ ;
F_6 ( & V_38 -> V_101 ) ;
}
int F_68 ( struct V_21 * V_15 )
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
struct V_21 * F_69 ( struct V_37 * V_38 , T_6 V_68 )
{
struct V_21 * V_15 ;
F_8 ( & V_38 -> V_118 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_68 == V_68 ) &&
( V_15 -> V_119 == V_120 ) ) {
F_70 ( V_15 ) ;
F_6 ( & V_38 -> V_118 ) ;
return V_15 ;
}
}
F_6 ( & V_38 -> V_118 ) ;
return NULL ;
}
struct V_21 * F_71 ( struct V_37 * V_38 , T_6 V_68 )
{
struct V_21 * V_15 ;
F_8 ( & V_38 -> V_118 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_68 == V_68 ) {
F_70 ( V_15 ) ;
F_42 ( & V_15 -> V_121 ) ;
F_45 ( & V_15 -> V_122 , 1 ) ;
F_43 ( & V_15 -> V_121 ) ;
F_6 ( & V_38 -> V_118 ) ;
return V_15 ;
}
}
F_6 ( & V_38 -> V_118 ) ;
return NULL ;
}
void F_72 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_123 ) ;
if ( V_15 -> V_124 != 0 ) {
V_15 -> V_125 = 1 ;
F_6 ( & V_15 -> V_123 ) ;
F_64 ( & V_15 -> V_126 ) ;
return;
}
F_6 ( & V_15 -> V_123 ) ;
}
void F_73 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_123 ) ;
V_15 -> V_124 -- ;
if ( ! V_15 -> V_124 && V_15 -> V_125 )
F_66 ( & V_15 -> V_126 ) ;
F_6 ( & V_15 -> V_123 ) ;
}
void F_70 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_123 ) ;
V_15 -> V_124 ++ ;
F_6 ( & V_15 -> V_123 ) ;
}
static int F_74 ( struct V_21 * V_15 , int V_127 )
{
T_5 V_77 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_96 = V_128 ;
V_77 = ( V_127 ) ? V_129 :
V_130 ;
V_2 -> V_19 = V_131 ;
F_8 ( & V_15 -> V_38 -> V_132 ) ;
V_2 -> V_69 = ( V_127 ) ? V_15 -> V_38 -> V_69 ++ :
0xFFFFFFFF ;
if ( V_127 && ( V_2 -> V_69 == 0xFFFFFFFF ) )
V_2 -> V_69 = V_15 -> V_38 -> V_69 ++ ;
F_6 ( & V_15 -> V_38 -> V_132 ) ;
F_8 ( & V_15 -> V_67 ) ;
F_5 ( & V_2 -> V_24 , & V_15 -> V_133 ) ;
F_6 ( & V_15 -> V_67 ) ;
if ( V_127 )
F_75 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_77 ) ;
return 0 ;
}
static void F_76 ( unsigned long V_134 )
{
struct V_21 * V_15 = (struct V_21 * ) V_134 ;
F_70 ( V_15 ) ;
F_8 ( & V_15 -> V_135 ) ;
if ( V_15 -> V_136 & V_137 ) {
F_6 ( & V_15 -> V_135 ) ;
F_73 ( V_15 ) ;
return;
}
F_25 ( L_34
L_35 , V_15 -> V_68 ,
V_15 -> V_38 -> V_138 ) ;
V_15 -> V_136 &= ~ V_139 ;
F_6 ( & V_15 -> V_135 ) ;
{
struct V_140 * V_141 = V_15 -> V_38 -> V_141 ;
struct V_142 * V_143 = V_141 -> V_144 ;
if ( V_143 ) {
F_8 ( & V_143 -> V_145 . V_146 ) ;
strcpy ( V_143 -> V_145 . V_147 ,
V_15 -> V_38 -> V_58 -> V_148 ) ;
V_143 -> V_145 . V_149 =
V_150 ;
V_143 -> V_145 . V_151 ++ ;
V_15 -> V_38 -> V_152 ++ ;
F_6 ( & V_143 -> V_145 . V_146 ) ;
}
}
F_77 ( V_15 , 0 ) ;
F_73 ( V_15 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_153 * V_154 = F_79 ( V_38 ) ;
F_8 ( & V_15 -> V_135 ) ;
if ( ! ( V_15 -> V_136 & V_139 ) ) {
F_6 ( & V_15 -> V_135 ) ;
return;
}
F_80 ( & V_15 -> V_155 ,
( F_81 () + V_154 -> V_156 * V_157 ) ) ;
F_6 ( & V_15 -> V_135 ) ;
}
void F_75 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_153 * V_154 = F_79 ( V_38 ) ;
F_8 ( & V_15 -> V_135 ) ;
if ( V_15 -> V_136 & V_139 ) {
F_6 ( & V_15 -> V_135 ) ;
return;
}
F_82 ( & V_15 -> V_155 ) ;
V_15 -> V_155 . V_158 =
( F_81 () + V_154 -> V_156 * V_157 ) ;
V_15 -> V_155 . V_134 = ( unsigned long ) V_15 ;
V_15 -> V_155 . V_159 = F_76 ;
V_15 -> V_136 &= ~ V_137 ;
V_15 -> V_136 |= V_139 ;
F_83 ( & V_15 -> V_155 ) ;
F_25 ( L_36
L_37 , V_15 -> V_68 , V_154 -> V_156 ) ;
F_6 ( & V_15 -> V_135 ) ;
}
void F_84 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_135 ) ;
if ( ! ( V_15 -> V_136 & V_139 ) ) {
F_6 ( & V_15 -> V_135 ) ;
return;
}
V_15 -> V_136 |= V_137 ;
F_6 ( & V_15 -> V_135 ) ;
F_85 ( & V_15 -> V_155 ) ;
F_8 ( & V_15 -> V_135 ) ;
V_15 -> V_136 &= ~ V_139 ;
F_6 ( & V_15 -> V_135 ) ;
}
static void F_86 ( unsigned long V_134 )
{
struct V_21 * V_15 = (struct V_21 * ) V_134 ;
F_70 ( V_15 ) ;
F_8 ( & V_15 -> V_135 ) ;
if ( V_15 -> V_160 & V_137 ) {
F_6 ( & V_15 -> V_135 ) ;
F_73 ( V_15 ) ;
return;
}
V_15 -> V_160 &= ~ V_139 ;
F_6 ( & V_15 -> V_135 ) ;
F_74 ( V_15 , 1 ) ;
F_73 ( V_15 ) ;
}
void F_87 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_153 * V_154 = F_79 ( V_38 ) ;
if ( ! V_154 -> V_161 )
return;
if ( V_15 -> V_160 & V_139 )
return;
F_82 ( & V_15 -> V_162 ) ;
V_15 -> V_162 . V_158 = ( F_81 () + V_154 -> V_161 * V_157 ) ;
V_15 -> V_162 . V_134 = ( unsigned long ) V_15 ;
V_15 -> V_162 . V_159 = F_86 ;
V_15 -> V_160 &= ~ V_137 ;
V_15 -> V_160 |= V_139 ;
F_83 ( & V_15 -> V_162 ) ;
F_25 ( L_38
L_39 , V_15 -> V_68 , V_154 -> V_161 ) ;
}
void F_88 ( struct V_21 * V_15 )
{
struct V_37 * V_38 = V_15 -> V_38 ;
struct V_153 * V_154 = F_79 ( V_38 ) ;
if ( ! V_154 -> V_161 )
return;
F_8 ( & V_15 -> V_135 ) ;
if ( V_15 -> V_160 & V_139 ) {
F_6 ( & V_15 -> V_135 ) ;
return;
}
F_82 ( & V_15 -> V_162 ) ;
V_15 -> V_162 . V_158 = ( F_81 () + V_154 -> V_161 * V_157 ) ;
V_15 -> V_162 . V_134 = ( unsigned long ) V_15 ;
V_15 -> V_162 . V_159 = F_86 ;
V_15 -> V_160 &= ~ V_137 ;
V_15 -> V_160 |= V_139 ;
F_83 ( & V_15 -> V_162 ) ;
F_25 ( L_38
L_39 , V_15 -> V_68 , V_154 -> V_161 ) ;
F_6 ( & V_15 -> V_135 ) ;
}
void F_89 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_135 ) ;
if ( ! ( V_15 -> V_160 & V_139 ) ) {
F_6 ( & V_15 -> V_135 ) ;
return;
}
V_15 -> V_160 |= V_137 ;
F_6 ( & V_15 -> V_135 ) ;
F_85 ( & V_15 -> V_162 ) ;
F_8 ( & V_15 -> V_135 ) ;
V_15 -> V_160 &= ~ V_139 ;
F_6 ( & V_15 -> V_135 ) ;
}
int F_90 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_163 )
{
int V_164 , V_165 ;
T_1 V_166 ;
struct V_167 * V_168 ;
V_169:
V_165 = V_2 -> V_165 ;
if ( ! V_163 ) {
V_168 = & V_2 -> V_95 [ 0 ] ;
V_166 = V_2 -> V_170 ;
} else {
V_168 = & V_2 -> V_171 [ 0 ] ;
V_166 = V_2 -> V_172 ;
}
V_164 = F_91 ( V_15 , & V_168 [ 0 ] , V_166 , V_165 ) ;
if ( V_165 != V_164 ) {
if ( V_164 == - V_173 ) {
F_3 ( L_40 ) ;
goto V_169;
} else
return - 1 ;
}
V_2 -> V_165 = 0 ;
return 0 ;
}
int F_92 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_174 * V_175 = V_2 -> V_176 ;
struct V_167 V_168 ;
T_1 V_177 , V_178 ;
T_1 V_3 = V_2 -> V_179 ;
int V_164 , V_180 ;
V_181:
V_177 = V_113 ;
if ( V_15 -> V_109 -> V_182 )
V_177 += V_183 ;
V_168 . V_184 = V_2 -> V_185 ;
V_168 . V_186 = V_177 ;
V_164 = F_91 ( V_15 , & V_168 , 1 , V_177 ) ;
if ( V_177 != V_164 ) {
if ( V_164 == - V_173 ) {
F_3 ( L_40 ) ;
goto V_181;
}
return - 1 ;
}
V_178 = V_2 -> V_165 - V_177 - V_2 -> V_187 ;
if ( V_15 -> V_109 -> V_188 ) {
V_178 -= V_183 ;
if ( V_2 -> V_187 )
V_180 = ( V_2 -> V_170 - 2 ) ;
else
V_180 = ( V_2 -> V_170 - 1 ) ;
} else {
V_180 = ( V_2 -> V_170 - 1 ) ;
}
while ( V_178 ) {
T_1 V_189 = ( V_175 -> V_17 - V_3 ) ;
T_1 V_190 = F_93 ( T_1 , V_178 , V_189 ) ;
V_191:
V_164 = V_15 -> V_192 -> V_193 -> V_194 ( V_15 -> V_192 ,
F_94 ( V_175 ) , V_175 -> V_3 + V_3 , V_190 , 0 ) ;
if ( V_164 != V_190 ) {
if ( V_164 == - V_173 ) {
F_3 ( L_41
L_42 ) ;
goto V_191;
}
F_3 ( L_43 ,
V_164 ) ;
return - 1 ;
}
V_178 -= V_190 ;
V_3 = 0 ;
V_175 = F_95 ( V_175 ) ;
}
V_195:
if ( V_2 -> V_187 ) {
struct V_167 * V_196 = & V_2 -> V_95 [ V_180 ++ ] ;
V_164 = F_91 ( V_15 , V_196 , 1 , V_2 -> V_187 ) ;
if ( V_2 -> V_187 != V_164 ) {
if ( V_164 == - V_173 ) {
F_3 ( L_40 ) ;
goto V_195;
}
return - 1 ;
}
}
V_197:
if ( V_15 -> V_109 -> V_188 ) {
struct V_167 * V_198 = & V_2 -> V_95 [ V_180 ] ;
V_164 = F_91 ( V_15 , V_198 , 1 , V_183 ) ;
if ( V_183 != V_164 ) {
if ( V_164 == - V_173 ) {
F_3 ( L_40 ) ;
goto V_197;
}
return - 1 ;
}
}
return 0 ;
}
int F_96 ( struct V_21 * V_15 , T_5 V_199 , T_5 V_200 )
{
T_5 V_201 [ V_113 ] ;
int V_202 ;
struct V_167 V_168 ;
struct V_203 * V_55 ;
F_97 ( V_15 , V_199 , V_200 ) ;
memset ( & V_168 , 0 , sizeof( struct V_167 ) ) ;
memset ( & V_201 , 0x0 , V_113 ) ;
V_55 = (struct V_203 * ) & V_201 ;
V_55 -> V_204 = V_205 ;
V_55 -> V_199 = V_199 ;
V_55 -> V_200 = V_200 ;
V_55 -> V_206 = V_15 -> V_207 ;
V_168 . V_184 = & V_201 ;
V_168 . V_186 = V_113 ;
F_98 ( V_201 , V_113 ) ;
V_202 = F_91 ( V_15 , & V_168 , 1 , V_113 ) ;
if ( V_202 != V_113 ) {
F_3 ( L_44 ) ;
return - 1 ;
}
return 0 ;
}
void F_99 ( struct V_37 * V_38 )
{
struct V_21 * V_15 ;
F_25 ( L_45
L_46 , V_38 -> V_138 ) ;
F_8 ( & V_38 -> V_118 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_100 ( V_15 -> V_109 ) ;
F_6 ( & V_38 -> V_118 ) ;
F_101 ( V_38 -> V_58 ) ;
}
static int F_102 (
struct V_21 * V_15 ,
struct V_208 * V_209 )
{
int V_134 = V_209 -> V_66 , V_210 = 0 , V_211 = 0 , V_186 ;
struct V_167 * V_196 ;
struct V_212 V_213 ;
if ( ! V_15 || ! V_15 -> V_192 || ! V_15 -> V_109 )
return - 1 ;
memset ( & V_213 , 0 , sizeof( struct V_212 ) ) ;
V_196 = V_209 -> V_168 ;
V_186 = V_209 -> V_166 ;
while ( V_211 < V_134 ) {
V_210 = F_103 ( V_15 -> V_192 , & V_213 , V_196 , V_186 ,
( V_134 - V_211 ) , V_214 ) ;
if ( V_210 <= 0 ) {
F_25 ( L_47 ,
V_210 , V_211 ) ;
return V_210 ;
}
V_211 += V_210 ;
F_25 ( L_48 ,
V_210 , V_211 , V_134 ) ;
}
return V_211 ;
}
static int F_104 (
struct V_21 * V_15 ,
struct V_208 * V_209 )
{
int V_134 = V_209 -> V_66 , V_215 = 0 , V_216 = 0 , V_186 ;
struct V_167 * V_196 ;
struct V_212 V_213 ;
if ( ! V_15 || ! V_15 -> V_192 || ! V_15 -> V_109 )
return - 1 ;
if ( V_134 <= 0 ) {
F_3 ( L_49 , V_134 ) ;
return - 1 ;
}
memset ( & V_213 , 0 , sizeof( struct V_212 ) ) ;
V_196 = V_209 -> V_168 ;
V_186 = V_209 -> V_166 ;
while ( V_215 < V_134 ) {
V_216 = F_105 ( V_15 -> V_192 , & V_213 , V_196 , V_186 ,
( V_134 - V_215 ) ) ;
if ( V_216 <= 0 ) {
F_25 ( L_50 ,
V_216 , V_215 ) ;
return V_216 ;
}
V_215 += V_216 ;
F_25 ( L_51 ,
V_216 , V_215 , V_134 ) ;
}
return V_215 ;
}
int F_106 (
struct V_21 * V_15 ,
struct V_167 * V_168 ,
int V_166 ,
int V_134 )
{
struct V_208 V_217 ;
if ( ! V_15 || ! V_15 -> V_192 || ! V_15 -> V_109 )
return - 1 ;
memset ( & V_217 , 0 , sizeof( struct V_208 ) ) ;
V_217 . V_168 = V_168 ;
V_217 . V_166 = V_166 ;
V_217 . V_66 = V_134 ;
V_217 . type = V_218 ;
return F_102 ( V_15 , & V_217 ) ;
}
int F_91 (
struct V_21 * V_15 ,
struct V_167 * V_168 ,
int V_166 ,
int V_134 )
{
struct V_208 V_217 ;
if ( ! V_15 || ! V_15 -> V_192 || ! V_15 -> V_109 )
return - 1 ;
memset ( & V_217 , 0 , sizeof( struct V_208 ) ) ;
V_217 . V_168 = V_168 ;
V_217 . V_166 = V_166 ;
V_217 . V_66 = V_134 ;
V_217 . type = V_219 ;
return F_104 ( V_15 , & V_217 ) ;
}
void F_97 (
struct V_21 * V_15 ,
T_5 V_199 ,
T_5 V_200 )
{
struct V_220 * V_221 = NULL ;
struct V_142 * V_143 ;
struct V_222 * V_223 ;
V_143 = F_107 ( V_15 ) ;
if ( ! V_143 )
return;
V_223 = & V_143 -> V_224 ;
F_42 ( & V_223 -> V_146 ) ;
if ( ! strcmp ( V_15 -> V_225 , V_223 -> V_226 ) &&
( ( F_81 () - V_223 -> V_227 ) < 10 ) ) {
F_43 ( & V_223 -> V_146 ) ;
return;
}
if ( V_199 == V_228 )
V_223 -> V_229 ++ ;
else if ( V_199 == V_230 ) {
V_223 -> V_231 ++ ;
V_223 -> V_232 = V_233 ;
} else if ( ( V_199 == V_234 ) &&
( V_200 == V_235 ) ) {
V_223 -> V_236 ++ ;
V_223 -> V_232 = V_237 ;
} else if ( ( V_199 == V_234 ) &&
( V_200 == V_238 ) ) {
V_223 -> V_239 ++ ;
V_223 -> V_232 = V_240 ;
} else if ( ( V_199 == V_234 ) &&
( V_200 == V_241 ) ) {
V_223 -> V_242 ++ ;
V_223 -> V_232 = V_243 ;
} else {
V_223 -> V_244 ++ ;
V_223 -> V_232 = V_245 ;
}
if ( V_199 != V_228 ) {
if ( V_15 -> V_246 )
V_221 = F_108 ( V_247 ,
V_15 -> V_246 ) ;
strcpy ( V_223 -> V_248 ,
( V_221 ? V_221 -> V_249 : L_52 ) ) ;
V_223 -> V_250 = V_15 -> V_192 -> V_251 -> V_252 ;
snprintf ( V_223 -> V_226 , V_253 ,
L_53 , V_15 -> V_225 ) ;
V_223 -> V_227 = F_81 () ;
}
F_43 ( & V_223 -> V_146 ) ;
}
struct V_142 * F_107 ( struct V_21 * V_15 )
{
struct V_140 * V_141 ;
if ( ! V_15 || ! V_15 -> V_38 )
return NULL ;
V_141 = V_15 -> V_38 -> V_141 ;
if ( ! V_141 )
return NULL ;
if ( ! V_141 -> V_144 )
return NULL ;
return V_141 -> V_144 ;
}
