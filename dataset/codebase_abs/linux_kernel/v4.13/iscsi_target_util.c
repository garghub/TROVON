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
struct V_1 * F_17 ( struct V_21 * V_15 , int V_22 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 = V_15 -> V_25 -> V_24 ;
int V_26 , V_27 ;
V_27 = F_18 ( & V_24 -> V_28 , V_22 ) ;
if ( V_27 < 0 )
return NULL ;
V_26 = sizeof( struct V_1 ) + V_15 -> V_29 -> V_30 ;
V_2 = (struct V_1 * ) ( V_24 -> V_31 + ( V_27 * V_26 ) ) ;
memset ( V_2 , 0 , V_26 ) ;
V_2 -> V_32 . V_33 = V_27 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_34 = V_35 ;
F_4 ( & V_2 -> V_36 ) ;
F_4 ( & V_2 -> V_37 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_19 ( & V_2 -> V_38 ) ;
F_19 ( & V_2 -> V_39 ) ;
F_19 ( & V_2 -> V_40 ) ;
F_19 ( & V_2 -> V_41 ) ;
F_19 ( & V_2 -> V_14 ) ;
return V_2 ;
}
struct V_42 * F_20 (
struct V_1 * V_2 ,
T_1 V_43 )
{
T_1 V_44 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_45 ; V_44 ++ )
if ( V_2 -> V_46 [ V_44 ] . V_43 == V_43 )
return & V_2 -> V_46 [ V_44 ] ;
return NULL ;
}
struct V_42 * F_21 ( struct V_1 * V_2 )
{
T_1 V_44 ;
if ( ! V_2 -> V_46 ) {
F_3 ( L_6 ) ;
return NULL ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_45 ; V_44 ++ ) {
if ( V_2 -> V_46 [ V_44 ] . type != V_47 )
continue;
if ( V_2 -> V_46 [ V_44 ] . V_43 == V_2 -> V_43 ) {
V_2 -> V_43 ++ ;
return & V_2 -> V_46 [ V_44 ] ;
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
static inline int F_23 ( struct V_48 * V_25 , T_1 V_49 )
{
T_1 V_50 ;
int V_51 ;
V_50 = F_24 ( & V_25 -> V_52 ) ;
if ( F_25 ( V_49 , V_50 ) ) {
F_3 ( L_7
L_8 , V_49 , V_50 ) ;
V_51 = V_53 ;
} else if ( V_49 == V_25 -> V_54 ) {
V_25 -> V_54 ++ ;
F_26 ( L_9
L_10 ,
V_25 -> V_54 ) ;
V_51 = V_55 ;
} else if ( F_25 ( V_49 , V_25 -> V_54 ) ) {
F_26 ( L_11
L_12 ,
V_49 , V_25 -> V_54 ) ;
V_51 = V_56 ;
} else {
F_3 ( L_13
L_14 , V_49 ,
V_25 -> V_54 ) ;
V_51 = V_57 ;
}
return V_51 ;
}
int F_27 ( struct V_21 * V_15 , struct V_1 * V_2 ,
unsigned char * V_58 , T_2 V_49 )
{
int V_51 , V_59 ;
bool V_60 = false ;
T_3 V_61 = V_62 ;
F_28 ( & V_15 -> V_25 -> V_63 ) ;
V_59 = F_23 ( V_15 -> V_25 , F_29 ( V_49 ) ) ;
switch ( V_59 ) {
case V_55 :
V_51 = F_30 ( V_2 , 0 ) ;
if ( ( V_51 >= 0 ) && ! F_31 ( & V_15 -> V_25 -> V_64 ) )
F_32 ( V_15 -> V_25 ) ;
else if ( V_51 < 0 ) {
V_60 = true ;
V_51 = V_65 ;
}
break;
case V_56 :
V_51 = F_33 ( V_15 -> V_25 , V_2 , F_29 ( V_49 ) ) ;
if ( V_51 < 0 ) {
V_60 = true ;
V_51 = V_65 ;
break;
}
V_51 = V_56 ;
break;
case V_57 :
case V_53 :
default:
V_2 -> V_66 = V_67 ;
F_7 ( V_2 , V_15 , V_2 -> V_66 ) ;
V_51 = V_57 ;
break;
}
F_34 ( & V_15 -> V_25 -> V_63 ) ;
if ( V_60 )
F_35 ( V_2 , V_61 , V_58 ) ;
return V_51 ;
}
int F_36 ( struct V_1 * V_2 , unsigned char * V_58 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_32 * V_32 = & V_2 -> V_32 ;
struct V_68 * V_69 = (struct V_68 * ) V_58 ;
T_1 V_70 = F_37 ( V_69 -> V_71 ) ;
if ( V_15 -> V_25 -> V_72 -> V_73 ) {
F_3 ( L_15
L_16 ) ;
F_38 ( V_32 ,
V_74 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_75 + V_70 ) >
V_15 -> V_25 -> V_72 -> V_76 ) {
F_3 ( L_17
L_18 ,
( V_2 -> V_75 + V_70 ) ,
V_15 -> V_25 -> V_72 -> V_76 ) ;
F_38 ( V_32 ,
V_77 , 0 ) ;
return - 1 ;
}
if ( ! ( V_69 -> V_78 & V_79 ) )
return 0 ;
if ( ( ( V_2 -> V_75 + V_70 ) != V_2 -> V_32 . V_80 ) &&
( ( V_2 -> V_75 + V_70 ) !=
V_15 -> V_25 -> V_72 -> V_76 ) ) {
F_3 ( L_19
L_20
L_21 ,
( V_2 -> V_75 + V_70 ) ,
V_15 -> V_25 -> V_72 -> V_76 , V_2 -> V_32 . V_80 ) ;
F_38 ( V_32 ,
V_77 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_39 (
struct V_21 * V_15 ,
T_4 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_81 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_81 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_81 ) ;
F_3 ( L_22 ,
V_19 , V_15 -> V_82 ) ;
return NULL ;
}
struct V_1 * F_40 (
struct V_21 * V_15 ,
T_4 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_81 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_83 & V_84 )
continue;
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_81 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_81 ) ;
F_3 ( L_23
L_24 , V_19 , V_15 -> V_82 ) ;
if ( V_17 )
F_41 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_42 (
struct V_21 * V_15 ,
T_1 V_85 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_81 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_85 == V_85 ) {
F_6 ( & V_15 -> V_81 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_81 ) ;
F_3 ( L_25 ,
V_85 , V_15 -> V_82 ) ;
return NULL ;
}
int F_43 (
struct V_48 * V_25 ,
struct V_1 * * V_86 ,
struct V_87 * * V_88 ,
T_4 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_87 * V_89 ;
F_44 ( & V_25 -> V_90 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_44 ( & V_89 -> V_91 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_45 ( & V_89 -> V_91 ) ;
F_45 ( & V_25 -> V_90 ) ;
* V_88 = V_89 ;
* V_86 = V_2 ;
return - 2 ;
}
}
F_45 ( & V_89 -> V_91 ) ;
}
F_45 ( & V_25 -> V_90 ) ;
F_44 ( & V_25 -> V_92 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_44 ( & V_89 -> V_91 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_45 ( & V_89 -> V_91 ) ;
F_45 ( & V_25 -> V_92 ) ;
* V_88 = V_89 ;
* V_86 = V_2 ;
return 0 ;
}
}
F_45 ( & V_89 -> V_91 ) ;
}
F_45 ( & V_25 -> V_92 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_22 )
{
struct V_93 * V_94 ;
V_94 = F_2 ( V_95 , V_10 ) ;
if ( ! V_94 ) {
F_3 ( L_26
L_27 ) ;
return;
}
F_4 ( & V_94 -> V_96 ) ;
V_94 -> V_2 = V_2 ;
V_94 -> V_22 = V_22 ;
F_8 ( & V_15 -> V_97 ) ;
F_5 ( & V_94 -> V_96 , & V_15 -> V_98 ) ;
F_46 ( & V_2 -> V_99 ) ;
F_47 ( & V_15 -> V_100 , 1 ) ;
F_6 ( & V_15 -> V_97 ) ;
F_48 ( & V_15 -> V_101 ) ;
}
struct V_93 * F_49 ( struct V_21 * V_15 )
{
struct V_93 * V_94 ;
F_8 ( & V_15 -> V_97 ) ;
if ( F_31 ( & V_15 -> V_98 ) ) {
F_6 ( & V_15 -> V_97 ) ;
return NULL ;
}
V_94 = F_50 ( & V_15 -> V_98 ,
struct V_93 , V_96 ) ;
F_13 ( & V_94 -> V_96 ) ;
if ( V_94 -> V_2 )
F_51 ( & V_94 -> V_2 -> V_99 ) ;
F_6 ( & V_15 -> V_97 ) ;
return V_94 ;
}
static void F_52 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_93 * V_94 , * V_102 ;
F_8 ( & V_15 -> V_97 ) ;
if ( ! F_24 ( & V_2 -> V_99 ) ) {
F_6 ( & V_15 -> V_97 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_94 -> V_2 != V_2 )
continue;
F_51 ( & V_94 -> V_2 -> V_99 ) ;
F_13 ( & V_94 -> V_96 ) ;
F_14 ( V_95 , V_94 ) ;
}
F_6 ( & V_15 -> V_97 ) ;
if ( F_24 ( & V_2 -> V_99 ) ) {
F_3 ( L_28 ,
V_2 -> V_19 ,
F_24 ( & V_2 -> V_99 ) ) ;
}
}
int F_53 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_22 )
{
struct V_93 * V_94 ;
V_94 = F_2 ( V_95 , V_10 ) ;
if ( ! V_94 ) {
F_3 ( L_26
L_27 ) ;
return - V_103 ;
}
F_4 ( & V_94 -> V_96 ) ;
V_94 -> V_2 = V_2 ;
V_94 -> V_22 = V_22 ;
F_8 ( & V_15 -> V_104 ) ;
F_5 ( & V_94 -> V_96 , & V_15 -> V_105 ) ;
F_46 ( & V_2 -> V_106 ) ;
F_6 ( & V_15 -> V_104 ) ;
F_48 ( & V_15 -> V_101 ) ;
return 0 ;
}
struct V_93 * F_54 ( struct V_21 * V_15 )
{
struct V_93 * V_94 ;
F_8 ( & V_15 -> V_104 ) ;
if ( F_31 ( & V_15 -> V_105 ) ) {
F_6 ( & V_15 -> V_104 ) ;
return NULL ;
}
V_94 = F_50 ( & V_15 -> V_105 ,
struct V_93 , V_96 ) ;
F_13 ( & V_94 -> V_96 ) ;
if ( V_94 -> V_2 )
F_51 ( & V_94 -> V_2 -> V_106 ) ;
F_6 ( & V_15 -> V_104 ) ;
return V_94 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_93 * V_94 , * V_102 ;
F_8 ( & V_15 -> V_104 ) ;
if ( ! F_24 ( & V_2 -> V_106 ) ) {
F_6 ( & V_15 -> V_104 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_94 -> V_2 != V_2 )
continue;
F_51 ( & V_94 -> V_2 -> V_106 ) ;
F_13 ( & V_94 -> V_96 ) ;
F_14 ( V_95 , V_94 ) ;
}
F_6 ( & V_15 -> V_104 ) ;
if ( F_24 ( & V_2 -> V_106 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_24 ( & V_2 -> V_106 ) ) ;
}
}
bool F_56 ( struct V_21 * V_15 )
{
bool V_107 ;
F_8 ( & V_15 -> V_97 ) ;
V_107 = F_31 ( & V_15 -> V_98 ) ;
F_6 ( & V_15 -> V_97 ) ;
if ( ! V_107 )
return V_107 ;
F_8 ( & V_15 -> V_104 ) ;
V_107 = F_31 ( & V_15 -> V_105 ) ;
F_6 ( & V_15 -> V_104 ) ;
return V_107 ;
}
void F_57 ( struct V_21 * V_15 )
{
struct V_93 * V_94 , * V_102 ;
F_8 ( & V_15 -> V_97 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_94 -> V_96 ) ;
if ( V_94 -> V_2 )
F_51 ( & V_94 -> V_2 -> V_99 ) ;
F_14 ( V_95 , V_94 ) ;
}
F_6 ( & V_15 -> V_97 ) ;
F_8 ( & V_15 -> V_104 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_94 -> V_96 ) ;
if ( V_94 -> V_2 )
F_51 ( & V_94 -> V_2 -> V_106 ) ;
F_14 ( V_95 , V_94 ) ;
}
F_6 ( & V_15 -> V_104 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_48 * V_25 ;
struct V_32 * V_32 = & V_2 -> V_32 ;
if ( V_2 -> V_15 )
V_25 = V_2 -> V_15 -> V_25 ;
else
V_25 = V_2 -> V_25 ;
F_59 ( ! V_25 || ! V_25 -> V_24 ) ;
F_60 ( V_2 -> V_108 ) ;
F_60 ( V_2 -> V_109 ) ;
F_60 ( V_2 -> V_46 ) ;
F_60 ( V_2 -> V_110 ) ;
F_60 ( V_2 -> V_111 ) ;
F_60 ( V_2 -> V_112 ) ;
F_61 ( & V_25 -> V_24 -> V_28 , V_32 -> V_33 ) ;
}
void F_62 ( struct V_1 * V_2 , bool V_113 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_34 == V_114 ) {
F_63 ( V_2 ) ;
F_15 ( V_2 ) ;
}
if ( V_2 -> V_34 == V_115 )
F_64 ( V_2 ) ;
if ( V_15 && V_113 ) {
F_52 ( V_2 , V_15 ) ;
F_55 ( V_2 , V_15 ) ;
}
if ( V_15 && V_15 -> V_29 -> F_58 )
V_15 -> V_29 -> F_58 ( V_15 , V_2 ) ;
}
void F_65 ( struct V_1 * V_2 , bool V_116 )
{
struct V_32 * V_32 = V_2 -> V_32 . V_117 ? & V_2 -> V_32 : NULL ;
int V_118 ;
F_62 ( V_2 , V_116 ) ;
if ( V_32 ) {
V_118 = F_66 ( V_32 , V_116 ) ;
if ( ! V_118 && V_116 && V_32 -> V_24 ) {
F_62 ( V_2 , V_116 ) ;
F_67 ( V_32 ) ;
}
} else {
F_58 ( V_2 ) ;
}
}
int F_68 ( struct V_48 * V_25 )
{
F_8 ( & V_25 -> V_119 ) ;
if ( V_25 -> V_120 != 0 ) {
V_25 -> V_121 = 1 ;
F_6 ( & V_25 -> V_119 ) ;
if ( F_69 () )
return 2 ;
F_70 ( & V_25 -> V_122 ) ;
return 1 ;
}
F_6 ( & V_25 -> V_119 ) ;
return 0 ;
}
void F_71 ( struct V_48 * V_25 )
{
F_8 ( & V_25 -> V_119 ) ;
V_25 -> V_120 -- ;
if ( ! V_25 -> V_120 && V_25 -> V_121 )
F_72 ( & V_25 -> V_122 ) ;
F_6 ( & V_25 -> V_119 ) ;
}
void F_73 ( struct V_48 * V_25 )
{
F_8 ( & V_25 -> V_119 ) ;
V_25 -> V_120 ++ ;
F_6 ( & V_25 -> V_119 ) ;
}
struct V_21 * F_74 ( struct V_48 * V_25 , T_5 V_82 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_123 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_82 == V_82 ) &&
( V_15 -> V_124 == V_125 ) ) {
F_75 ( V_15 ) ;
F_6 ( & V_25 -> V_123 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_123 ) ;
return NULL ;
}
struct V_21 * F_76 ( struct V_48 * V_25 , T_5 V_82 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_123 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_82 == V_82 ) {
F_75 ( V_15 ) ;
F_44 ( & V_15 -> V_126 ) ;
F_47 ( & V_15 -> V_127 , 1 ) ;
F_45 ( & V_15 -> V_126 ) ;
F_6 ( & V_25 -> V_123 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_123 ) ;
return NULL ;
}
void F_77 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_128 ) ;
if ( V_15 -> V_129 != 0 ) {
V_15 -> V_130 = 1 ;
F_6 ( & V_15 -> V_128 ) ;
F_70 ( & V_15 -> V_131 ) ;
return;
}
F_6 ( & V_15 -> V_128 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_128 ) ;
V_15 -> V_129 -- ;
if ( ! V_15 -> V_129 && V_15 -> V_130 )
F_72 ( & V_15 -> V_131 ) ;
F_6 ( & V_15 -> V_128 ) ;
}
void F_75 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_128 ) ;
V_15 -> V_129 ++ ;
F_6 ( & V_15 -> V_128 ) ;
}
static int F_79 ( struct V_21 * V_15 , int V_132 )
{
T_3 V_22 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_133 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_134 = V_135 ;
V_22 = ( V_132 ) ? V_136 :
V_137 ;
V_2 -> V_19 = V_138 ;
V_2 -> V_85 = ( V_132 ) ?
F_80 ( V_15 -> V_25 ) : 0xFFFFFFFF ;
F_8 ( & V_15 -> V_81 ) ;
F_5 ( & V_2 -> V_36 , & V_15 -> V_139 ) ;
F_6 ( & V_15 -> V_81 ) ;
if ( V_132 )
F_81 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_22 ) ;
return 0 ;
}
static void F_82 ( unsigned long V_140 )
{
struct V_21 * V_15 = (struct V_21 * ) V_140 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_141 ) ;
if ( V_15 -> V_142 & V_143 ) {
F_6 ( & V_15 -> V_141 ) ;
F_78 ( V_15 ) ;
return;
}
F_26 ( L_30
L_31 , V_15 -> V_82 ,
V_15 -> V_25 -> V_144 ) ;
V_15 -> V_142 &= ~ V_145 ;
F_6 ( & V_15 -> V_141 ) ;
{
struct V_146 * V_147 = V_15 -> V_25 -> V_147 ;
struct V_148 * V_149 = V_147 -> V_150 ;
if ( V_149 ) {
F_8 ( & V_149 -> V_151 . V_152 ) ;
strcpy ( V_149 -> V_151 . V_153 ,
V_15 -> V_25 -> V_72 -> V_154 ) ;
V_149 -> V_151 . V_155 =
V_156 ;
V_149 -> V_151 . V_157 ++ ;
F_83 ( & V_15 -> V_25 -> V_158 ) ;
F_6 ( & V_149 -> V_151 . V_152 ) ;
}
}
F_84 ( V_15 , 0 ) ;
F_78 ( V_15 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_48 * V_25 = V_15 -> V_25 ;
struct V_159 * V_160 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_141 ) ;
if ( ! ( V_15 -> V_142 & V_145 ) ) {
F_6 ( & V_15 -> V_141 ) ;
return;
}
F_87 ( & V_15 -> V_161 ,
( F_88 () + V_160 -> V_162 * V_163 ) ) ;
F_6 ( & V_15 -> V_141 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
struct V_48 * V_25 = V_15 -> V_25 ;
struct V_159 * V_160 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_141 ) ;
if ( V_15 -> V_142 & V_145 ) {
F_6 ( & V_15 -> V_141 ) ;
return;
}
F_89 ( & V_15 -> V_161 ) ;
V_15 -> V_161 . V_164 =
( F_88 () + V_160 -> V_162 * V_163 ) ;
V_15 -> V_161 . V_140 = ( unsigned long ) V_15 ;
V_15 -> V_161 . V_165 = F_82 ;
V_15 -> V_142 &= ~ V_143 ;
V_15 -> V_142 |= V_145 ;
F_90 ( & V_15 -> V_161 ) ;
F_26 ( L_32
L_33 , V_15 -> V_82 , V_160 -> V_162 ) ;
F_6 ( & V_15 -> V_141 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_141 ) ;
if ( ! ( V_15 -> V_142 & V_145 ) ) {
F_6 ( & V_15 -> V_141 ) ;
return;
}
V_15 -> V_142 |= V_143 ;
F_6 ( & V_15 -> V_141 ) ;
F_92 ( & V_15 -> V_161 ) ;
F_8 ( & V_15 -> V_141 ) ;
V_15 -> V_142 &= ~ V_145 ;
F_6 ( & V_15 -> V_141 ) ;
}
static void F_93 ( unsigned long V_140 )
{
struct V_21 * V_15 = (struct V_21 * ) V_140 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_141 ) ;
if ( V_15 -> V_166 & V_143 ) {
F_6 ( & V_15 -> V_141 ) ;
F_78 ( V_15 ) ;
return;
}
V_15 -> V_166 &= ~ V_145 ;
F_6 ( & V_15 -> V_141 ) ;
F_79 ( V_15 , 1 ) ;
F_78 ( V_15 ) ;
}
void F_94 ( struct V_21 * V_15 )
{
struct V_48 * V_25 = V_15 -> V_25 ;
struct V_159 * V_160 = F_86 ( V_25 ) ;
if ( ! V_160 -> V_167 )
return;
if ( V_15 -> V_166 & V_145 )
return;
F_89 ( & V_15 -> V_168 ) ;
V_15 -> V_168 . V_164 = ( F_88 () + V_160 -> V_167 * V_163 ) ;
V_15 -> V_168 . V_140 = ( unsigned long ) V_15 ;
V_15 -> V_168 . V_165 = F_93 ;
V_15 -> V_166 &= ~ V_143 ;
V_15 -> V_166 |= V_145 ;
F_90 ( & V_15 -> V_168 ) ;
F_26 ( L_34
L_35 , V_15 -> V_82 , V_160 -> V_167 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
struct V_48 * V_25 = V_15 -> V_25 ;
struct V_159 * V_160 = F_86 ( V_25 ) ;
if ( ! V_160 -> V_167 )
return;
F_8 ( & V_15 -> V_141 ) ;
if ( V_15 -> V_166 & V_145 ) {
F_6 ( & V_15 -> V_141 ) ;
return;
}
F_89 ( & V_15 -> V_168 ) ;
V_15 -> V_168 . V_164 = ( F_88 () + V_160 -> V_167 * V_163 ) ;
V_15 -> V_168 . V_140 = ( unsigned long ) V_15 ;
V_15 -> V_168 . V_165 = F_93 ;
V_15 -> V_166 &= ~ V_143 ;
V_15 -> V_166 |= V_145 ;
F_90 ( & V_15 -> V_168 ) ;
F_26 ( L_34
L_35 , V_15 -> V_82 , V_160 -> V_167 ) ;
F_6 ( & V_15 -> V_141 ) ;
}
void F_96 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_141 ) ;
if ( ! ( V_15 -> V_166 & V_145 ) ) {
F_6 ( & V_15 -> V_141 ) ;
return;
}
V_15 -> V_166 |= V_143 ;
F_6 ( & V_15 -> V_141 ) ;
F_92 ( & V_15 -> V_168 ) ;
F_8 ( & V_15 -> V_141 ) ;
V_15 -> V_166 &= ~ V_145 ;
F_6 ( & V_15 -> V_141 ) ;
}
int F_97 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_169 )
{
int V_170 , V_171 ;
T_1 V_172 ;
struct V_173 * V_174 ;
V_175:
V_171 = V_2 -> V_171 ;
if ( ! V_169 ) {
V_174 = & V_2 -> V_111 [ 0 ] ;
V_172 = V_2 -> V_176 ;
} else {
V_174 = & V_2 -> V_177 [ 0 ] ;
V_172 = V_2 -> V_178 ;
}
V_170 = F_98 ( V_15 , & V_174 [ 0 ] , V_172 , V_171 ) ;
if ( V_171 != V_170 ) {
if ( V_170 == - V_179 ) {
F_3 ( L_36 ) ;
goto V_175;
} else
return - 1 ;
}
V_2 -> V_171 = 0 ;
return 0 ;
}
int F_99 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_180 * V_181 = V_2 -> V_182 ;
struct V_173 V_174 ;
T_1 V_183 , V_184 ;
T_1 V_3 = V_2 -> V_185 ;
int V_170 , V_186 ;
V_187:
V_183 = V_188 ;
if ( V_15 -> V_189 -> V_190 )
V_183 += V_191 ;
V_174 . V_192 = V_2 -> V_193 ;
V_174 . V_194 = V_183 ;
V_170 = F_98 ( V_15 , & V_174 , 1 , V_183 ) ;
if ( V_183 != V_170 ) {
if ( V_170 == - V_179 ) {
F_3 ( L_36 ) ;
goto V_187;
}
return - 1 ;
}
V_184 = V_2 -> V_171 - V_183 - V_2 -> V_195 ;
if ( V_15 -> V_189 -> V_196 ) {
V_184 -= V_191 ;
if ( V_2 -> V_195 )
V_186 = ( V_2 -> V_176 - 2 ) ;
else
V_186 = ( V_2 -> V_176 - 1 ) ;
} else {
V_186 = ( V_2 -> V_176 - 1 ) ;
}
while ( V_184 ) {
T_1 V_197 = ( V_181 -> V_17 - V_3 ) ;
T_1 V_198 = F_100 ( T_1 , V_184 , V_197 ) ;
V_199:
V_170 = V_15 -> V_200 -> V_201 -> V_202 ( V_15 -> V_200 ,
F_101 ( V_181 ) , V_181 -> V_3 + V_3 , V_198 , 0 ) ;
if ( V_170 != V_198 ) {
if ( V_170 == - V_179 ) {
F_3 ( L_37
L_38 ) ;
goto V_199;
}
F_3 ( L_39 ,
V_170 ) ;
return - 1 ;
}
V_184 -= V_198 ;
V_3 = 0 ;
V_181 = F_102 ( V_181 ) ;
}
V_203:
if ( V_2 -> V_195 ) {
struct V_173 * V_204 = & V_2 -> V_111 [ V_186 ++ ] ;
V_170 = F_98 ( V_15 , V_204 , 1 , V_2 -> V_195 ) ;
if ( V_2 -> V_195 != V_170 ) {
if ( V_170 == - V_179 ) {
F_3 ( L_36 ) ;
goto V_203;
}
return - 1 ;
}
}
V_205:
if ( V_15 -> V_189 -> V_196 ) {
struct V_173 * V_206 = & V_2 -> V_111 [ V_186 ] ;
V_170 = F_98 ( V_15 , V_206 , 1 , V_191 ) ;
if ( V_191 != V_170 ) {
if ( V_170 == - V_179 ) {
F_3 ( L_36 ) ;
goto V_205;
}
return - 1 ;
}
}
return 0 ;
}
int F_103 ( struct V_21 * V_15 , T_3 V_207 , T_3 V_208 )
{
struct V_209 * V_69 ;
struct V_210 * V_211 = V_15 -> V_212 ;
V_211 -> V_213 = 1 ;
F_104 ( V_15 , V_207 , V_208 ) ;
memset ( & V_211 -> V_214 [ 0 ] , 0 , V_188 ) ;
V_69 = (struct V_209 * ) & V_211 -> V_214 [ 0 ] ;
V_69 -> V_215 = V_216 ;
V_69 -> V_207 = V_207 ;
V_69 -> V_208 = V_208 ;
V_69 -> V_217 = V_15 -> V_218 ;
return V_15 -> V_29 -> V_219 ( V_15 , V_211 , 0 ) ;
}
void F_105 ( struct V_48 * V_25 )
{
struct V_21 * V_15 ;
F_26 ( L_40
L_41 , V_25 -> V_144 ) ;
F_8 ( & V_25 -> V_123 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_106 ( V_15 -> V_189 ) ;
F_6 ( & V_25 -> V_123 ) ;
F_107 ( V_25 -> V_72 ) ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_220 * V_221 )
{
int V_140 = V_221 -> V_80 , V_222 = 0 , V_223 = 0 ;
struct V_224 V_225 ;
if ( ! V_15 || ! V_15 -> V_200 || ! V_15 -> V_189 )
return - 1 ;
memset ( & V_225 , 0 , sizeof( struct V_224 ) ) ;
F_109 ( & V_225 . V_226 , V_227 | V_228 ,
V_221 -> V_174 , V_221 -> V_172 , V_140 ) ;
while ( F_110 ( & V_225 ) ) {
V_222 = F_111 ( V_15 -> V_200 , & V_225 , V_229 ) ;
if ( V_222 <= 0 ) {
F_26 ( L_42 ,
V_222 , V_223 ) ;
return V_222 ;
}
V_223 += V_222 ;
F_26 ( L_43 ,
V_222 , V_223 , V_140 ) ;
}
return V_223 ;
}
int F_112 (
struct V_21 * V_15 ,
struct V_173 * V_174 ,
int V_172 ,
int V_140 )
{
struct V_220 V_230 ;
if ( ! V_15 || ! V_15 -> V_200 || ! V_15 -> V_189 )
return - 1 ;
memset ( & V_230 , 0 , sizeof( struct V_220 ) ) ;
V_230 . V_174 = V_174 ;
V_230 . V_172 = V_172 ;
V_230 . V_80 = V_140 ;
V_230 . type = V_231 ;
return F_108 ( V_15 , & V_230 ) ;
}
int F_98 (
struct V_21 * V_15 ,
struct V_173 * V_174 ,
int V_172 ,
int V_140 )
{
struct V_224 V_225 ;
int V_232 = 0 ;
if ( ! V_15 || ! V_15 -> V_200 || ! V_15 -> V_189 )
return - 1 ;
if ( V_140 <= 0 ) {
F_3 ( L_44 , V_140 ) ;
return - 1 ;
}
memset ( & V_225 , 0 , sizeof( struct V_224 ) ) ;
F_109 ( & V_225 . V_226 , V_233 | V_228 ,
V_174 , V_172 , V_140 ) ;
while ( F_110 ( & V_225 ) ) {
int V_234 = F_113 ( V_15 -> V_200 , & V_225 ) ;
if ( V_234 <= 0 ) {
F_26 ( L_45 ,
V_234 , V_232 ) ;
return V_234 ;
}
V_232 += V_234 ;
F_26 ( L_46 ,
V_234 , V_232 , V_140 ) ;
}
return V_232 ;
}
void F_104 (
struct V_21 * V_15 ,
T_3 V_207 ,
T_3 V_208 )
{
struct V_235 * V_236 = NULL ;
struct V_148 * V_149 ;
struct V_237 * V_238 ;
V_149 = F_114 ( V_15 ) ;
if ( ! V_149 )
return;
V_238 = & V_149 -> V_239 ;
F_44 ( & V_238 -> V_152 ) ;
if ( V_207 == V_240 )
V_238 -> V_241 ++ ;
else if ( V_207 == V_242 ) {
V_238 -> V_243 ++ ;
V_238 -> V_244 = V_245 ;
} else if ( ( V_207 == V_246 ) &&
( V_208 == V_247 ) ) {
V_238 -> V_248 ++ ;
V_238 -> V_244 = V_249 ;
} else if ( ( V_207 == V_246 ) &&
( V_208 == V_250 ) ) {
V_238 -> V_251 ++ ;
V_238 -> V_244 = V_252 ;
} else if ( ( V_207 == V_246 ) &&
( V_208 == V_253 ) ) {
V_238 -> V_254 ++ ;
V_238 -> V_244 = V_255 ;
} else {
V_238 -> V_256 ++ ;
V_238 -> V_244 = V_257 ;
}
if ( V_207 != V_240 ) {
if ( V_15 -> V_258 )
V_236 = F_115 ( V_259 ,
V_15 -> V_258 ) ;
F_116 ( V_238 -> V_260 ,
( V_236 ? V_236 -> V_261 : L_47 ) ,
sizeof( V_238 -> V_260 ) ) ;
V_238 -> V_262 = V_15 -> V_263 ;
V_238 -> V_264 = V_15 -> V_265 ;
V_238 -> V_266 = F_88 () ;
}
F_45 ( & V_238 -> V_152 ) ;
}
struct V_148 * F_114 ( struct V_21 * V_15 )
{
struct V_146 * V_147 ;
if ( ! V_15 )
return NULL ;
V_147 = V_15 -> V_147 ;
if ( ! V_147 )
return NULL ;
if ( ! V_147 -> V_150 )
return NULL ;
return V_147 -> V_150 ;
}
