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
F_4 ( & V_2 -> V_34 ) ;
F_4 ( & V_2 -> V_35 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_19 ( & V_2 -> V_36 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_19 ( & V_2 -> V_38 ) ;
F_19 ( & V_2 -> V_39 ) ;
F_19 ( & V_2 -> V_14 ) ;
return V_2 ;
}
struct V_40 * F_20 (
struct V_1 * V_2 ,
T_1 V_41 )
{
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_43 ; V_42 ++ )
if ( V_2 -> V_44 [ V_42 ] . V_41 == V_41 )
return & V_2 -> V_44 [ V_42 ] ;
return NULL ;
}
struct V_40 * F_21 ( struct V_1 * V_2 )
{
T_1 V_42 ;
if ( ! V_2 -> V_44 ) {
F_3 ( L_6 ) ;
return NULL ;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_43 ; V_42 ++ ) {
if ( V_2 -> V_44 [ V_42 ] . type != V_45 )
continue;
if ( V_2 -> V_44 [ V_42 ] . V_41 == V_2 -> V_41 ) {
V_2 -> V_41 ++ ;
return & V_2 -> V_44 [ V_42 ] ;
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
static inline int F_23 ( struct V_46 * V_25 , T_1 V_47 )
{
int V_48 ;
if ( F_24 ( V_47 , V_25 -> V_49 ) ) {
F_3 ( L_7
L_8 , V_47 ,
V_25 -> V_49 ) ;
V_48 = V_50 ;
} else if ( V_47 == V_25 -> V_51 ) {
V_25 -> V_51 ++ ;
F_25 ( L_9
L_10 ,
V_25 -> V_51 ) ;
V_48 = V_52 ;
} else if ( F_24 ( V_47 , V_25 -> V_51 ) ) {
F_25 ( L_11
L_12 ,
V_47 , V_25 -> V_51 ) ;
V_48 = V_53 ;
} else {
F_3 ( L_13
L_14 , V_47 ,
V_25 -> V_51 ) ;
V_48 = V_54 ;
}
return V_48 ;
}
int F_26 ( struct V_21 * V_15 , struct V_1 * V_2 ,
unsigned char * V_55 , T_2 V_47 )
{
int V_48 , V_56 ;
bool V_57 = false ;
T_3 V_58 = V_59 ;
F_27 ( & V_15 -> V_25 -> V_60 ) ;
V_56 = F_23 ( V_15 -> V_25 , F_28 ( V_47 ) ) ;
switch ( V_56 ) {
case V_52 :
V_48 = F_29 ( V_2 , 0 ) ;
if ( ( V_48 >= 0 ) && ! F_30 ( & V_15 -> V_25 -> V_61 ) )
F_31 ( V_15 -> V_25 ) ;
else if ( V_48 < 0 ) {
V_57 = true ;
V_48 = V_62 ;
}
break;
case V_53 :
V_48 = F_32 ( V_15 -> V_25 , V_2 , F_28 ( V_47 ) ) ;
if ( V_48 < 0 ) {
V_57 = true ;
V_48 = V_62 ;
break;
}
V_48 = V_53 ;
break;
case V_54 :
case V_50 :
default:
V_2 -> V_63 = V_64 ;
F_7 ( V_2 , V_15 , V_2 -> V_63 ) ;
V_48 = V_54 ;
break;
}
F_33 ( & V_15 -> V_25 -> V_60 ) ;
if ( V_57 )
F_34 ( V_2 , V_58 , V_55 ) ;
return V_48 ;
}
int F_35 ( struct V_1 * V_2 , unsigned char * V_55 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_32 * V_32 = & V_2 -> V_32 ;
struct V_65 * V_66 = (struct V_65 * ) V_55 ;
T_1 V_67 = F_36 ( V_66 -> V_68 ) ;
if ( V_15 -> V_25 -> V_69 -> V_70 ) {
F_3 ( L_15
L_16 ) ;
F_37 ( V_32 ,
V_71 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_72 + V_67 ) >
V_15 -> V_25 -> V_69 -> V_73 ) {
F_3 ( L_17
L_18 ,
( V_2 -> V_72 + V_67 ) ,
V_15 -> V_25 -> V_69 -> V_73 ) ;
F_37 ( V_32 ,
V_74 , 0 ) ;
return - 1 ;
}
if ( ! ( V_66 -> V_75 & V_76 ) )
return 0 ;
if ( ( ( V_2 -> V_72 + V_67 ) != V_2 -> V_32 . V_77 ) &&
( ( V_2 -> V_72 + V_67 ) !=
V_15 -> V_25 -> V_69 -> V_73 ) ) {
F_3 ( L_19
L_20
L_21 ,
( V_2 -> V_72 + V_67 ) ,
V_15 -> V_25 -> V_69 -> V_73 , V_2 -> V_32 . V_77 ) ;
F_37 ( V_32 ,
V_74 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_38 (
struct V_21 * V_15 ,
T_4 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_78 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_78 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_78 ) ;
F_3 ( L_22 ,
V_19 , V_15 -> V_79 ) ;
return NULL ;
}
struct V_1 * F_39 (
struct V_21 * V_15 ,
T_4 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_78 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_80 & V_81 )
continue;
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_78 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_78 ) ;
F_3 ( L_23
L_24 , V_19 , V_15 -> V_79 ) ;
if ( V_17 )
F_40 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_41 (
struct V_21 * V_15 ,
T_1 V_82 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_78 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_82 == V_82 ) {
F_6 ( & V_15 -> V_78 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_78 ) ;
F_3 ( L_25 ,
V_82 , V_15 -> V_79 ) ;
return NULL ;
}
int F_42 (
struct V_46 * V_25 ,
struct V_1 * * V_83 ,
struct V_84 * * V_85 ,
T_4 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_84 * V_86 ;
F_43 ( & V_25 -> V_87 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_43 ( & V_86 -> V_88 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_86 -> V_88 ) ;
F_44 ( & V_25 -> V_87 ) ;
* V_85 = V_86 ;
* V_83 = V_2 ;
return - 2 ;
}
}
F_44 ( & V_86 -> V_88 ) ;
}
F_44 ( & V_25 -> V_87 ) ;
F_43 ( & V_25 -> V_89 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_43 ( & V_86 -> V_88 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_86 -> V_88 ) ;
F_44 ( & V_25 -> V_89 ) ;
* V_85 = V_86 ;
* V_83 = V_2 ;
return 0 ;
}
}
F_44 ( & V_86 -> V_88 ) ;
}
F_44 ( & V_25 -> V_89 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_22 )
{
struct V_90 * V_91 ;
V_91 = F_2 ( V_92 , V_10 ) ;
if ( ! V_91 ) {
F_3 ( L_26
L_27 ) ;
return;
}
F_4 ( & V_91 -> V_93 ) ;
V_91 -> V_2 = V_2 ;
V_91 -> V_22 = V_22 ;
F_8 ( & V_15 -> V_94 ) ;
F_5 ( & V_91 -> V_93 , & V_15 -> V_95 ) ;
F_45 ( & V_2 -> V_96 ) ;
F_46 ( & V_15 -> V_97 , 1 ) ;
F_6 ( & V_15 -> V_94 ) ;
F_47 ( & V_15 -> V_98 ) ;
}
struct V_90 * F_48 ( struct V_21 * V_15 )
{
struct V_90 * V_91 ;
F_8 ( & V_15 -> V_94 ) ;
if ( F_30 ( & V_15 -> V_95 ) ) {
F_6 ( & V_15 -> V_94 ) ;
return NULL ;
}
V_91 = F_49 ( & V_15 -> V_95 ,
struct V_90 , V_93 ) ;
F_13 ( & V_91 -> V_93 ) ;
if ( V_91 -> V_2 )
F_50 ( & V_91 -> V_2 -> V_96 ) ;
F_6 ( & V_15 -> V_94 ) ;
return V_91 ;
}
static void F_51 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_90 * V_91 , * V_99 ;
F_8 ( & V_15 -> V_94 ) ;
if ( ! F_52 ( & V_2 -> V_96 ) ) {
F_6 ( & V_15 -> V_94 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_91 -> V_2 != V_2 )
continue;
F_50 ( & V_91 -> V_2 -> V_96 ) ;
F_13 ( & V_91 -> V_93 ) ;
F_14 ( V_92 , V_91 ) ;
}
F_6 ( & V_15 -> V_94 ) ;
if ( F_52 ( & V_2 -> V_96 ) ) {
F_3 ( L_28 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_96 ) ) ;
}
}
void F_53 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_22 )
{
struct V_90 * V_91 ;
V_91 = F_2 ( V_92 , V_10 ) ;
if ( ! V_91 ) {
F_3 ( L_26
L_27 ) ;
return;
}
F_4 ( & V_91 -> V_93 ) ;
V_91 -> V_2 = V_2 ;
V_91 -> V_22 = V_22 ;
F_8 ( & V_15 -> V_100 ) ;
F_5 ( & V_91 -> V_93 , & V_15 -> V_101 ) ;
F_45 ( & V_2 -> V_102 ) ;
F_6 ( & V_15 -> V_100 ) ;
F_47 ( & V_15 -> V_98 ) ;
}
struct V_90 * F_54 ( struct V_21 * V_15 )
{
struct V_90 * V_91 ;
F_8 ( & V_15 -> V_100 ) ;
if ( F_30 ( & V_15 -> V_101 ) ) {
F_6 ( & V_15 -> V_100 ) ;
return NULL ;
}
V_91 = F_49 ( & V_15 -> V_101 ,
struct V_90 , V_93 ) ;
F_13 ( & V_91 -> V_93 ) ;
if ( V_91 -> V_2 )
F_50 ( & V_91 -> V_2 -> V_102 ) ;
F_6 ( & V_15 -> V_100 ) ;
return V_91 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_90 * V_91 , * V_99 ;
F_8 ( & V_15 -> V_100 ) ;
if ( ! F_52 ( & V_2 -> V_102 ) ) {
F_6 ( & V_15 -> V_100 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_91 -> V_2 != V_2 )
continue;
F_50 ( & V_91 -> V_2 -> V_102 ) ;
F_13 ( & V_91 -> V_93 ) ;
F_14 ( V_92 , V_91 ) ;
}
F_6 ( & V_15 -> V_100 ) ;
if ( F_52 ( & V_2 -> V_102 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_102 ) ) ;
}
}
bool F_56 ( struct V_21 * V_15 )
{
bool V_103 ;
F_8 ( & V_15 -> V_94 ) ;
V_103 = F_30 ( & V_15 -> V_95 ) ;
F_6 ( & V_15 -> V_94 ) ;
if ( ! V_103 )
return V_103 ;
F_8 ( & V_15 -> V_100 ) ;
V_103 = F_30 ( & V_15 -> V_101 ) ;
F_6 ( & V_15 -> V_100 ) ;
return V_103 ;
}
void F_57 ( struct V_21 * V_15 )
{
struct V_90 * V_91 , * V_99 ;
F_8 ( & V_15 -> V_94 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_91 -> V_93 ) ;
if ( V_91 -> V_2 )
F_50 ( & V_91 -> V_2 -> V_96 ) ;
F_14 ( V_92 , V_91 ) ;
}
F_6 ( & V_15 -> V_94 ) ;
F_8 ( & V_15 -> V_100 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_91 -> V_93 ) ;
if ( V_91 -> V_2 )
F_50 ( & V_91 -> V_2 -> V_102 ) ;
F_14 ( V_92 , V_91 ) ;
}
F_6 ( & V_15 -> V_100 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_46 * V_25 ;
struct V_32 * V_32 = & V_2 -> V_32 ;
if ( V_2 -> V_15 )
V_25 = V_2 -> V_15 -> V_25 ;
else
V_25 = V_2 -> V_25 ;
F_59 ( ! V_25 || ! V_25 -> V_24 ) ;
F_60 ( V_2 -> V_104 ) ;
F_60 ( V_2 -> V_105 ) ;
F_60 ( V_2 -> V_44 ) ;
F_60 ( V_2 -> V_106 ) ;
F_60 ( V_2 -> V_107 ) ;
F_60 ( V_2 -> V_108 ) ;
F_61 ( & V_25 -> V_24 -> V_28 , V_32 -> V_33 ) ;
}
void F_62 ( struct V_1 * V_2 , bool V_109 ,
bool V_110 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
if ( V_109 ) {
if ( V_2 -> V_111 == V_112 ) {
F_63 ( V_2 ) ;
F_15 ( V_2 ) ;
}
if ( V_2 -> V_111 == V_113 )
F_64 ( V_2 ) ;
}
if ( V_15 && V_110 ) {
F_51 ( V_2 , V_15 ) ;
F_55 ( V_2 , V_15 ) ;
}
}
void F_65 ( struct V_1 * V_2 , bool V_114 )
{
struct V_32 * V_32 = NULL ;
int V_115 ;
switch ( V_2 -> V_116 ) {
case V_117 :
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , true , V_114 ) ;
case V_118 :
V_115 = F_66 ( & V_2 -> V_32 , V_114 ) ;
if ( ! V_115 && V_114 && V_32 && V_32 -> V_24 ) {
F_62 ( V_2 , true , V_114 ) ;
F_67 ( V_32 ) ;
}
break;
case V_119 :
if ( V_2 -> V_32 . V_120 != NULL ) {
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , true , V_114 ) ;
V_115 = F_66 ( & V_2 -> V_32 , V_114 ) ;
if ( ! V_115 && V_114 && V_32 -> V_24 ) {
F_62 ( V_2 , true , V_114 ) ;
F_67 ( V_32 ) ;
}
break;
}
default:
F_62 ( V_2 , false , V_114 ) ;
F_58 ( V_2 ) ;
break;
}
}
int F_68 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_121 ) ;
if ( V_25 -> V_122 != 0 ) {
V_25 -> V_123 = 1 ;
F_6 ( & V_25 -> V_121 ) ;
if ( F_69 () )
return 2 ;
F_70 ( & V_25 -> V_124 ) ;
return 1 ;
}
F_6 ( & V_25 -> V_121 ) ;
return 0 ;
}
void F_71 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_121 ) ;
V_25 -> V_122 -- ;
if ( ! V_25 -> V_122 && V_25 -> V_123 )
F_72 ( & V_25 -> V_124 ) ;
F_6 ( & V_25 -> V_121 ) ;
}
void F_73 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_121 ) ;
V_25 -> V_122 ++ ;
F_6 ( & V_25 -> V_121 ) ;
}
struct V_21 * F_74 ( struct V_46 * V_25 , T_5 V_79 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_125 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_79 == V_79 ) &&
( V_15 -> V_126 == V_127 ) ) {
F_75 ( V_15 ) ;
F_6 ( & V_25 -> V_125 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_125 ) ;
return NULL ;
}
struct V_21 * F_76 ( struct V_46 * V_25 , T_5 V_79 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_125 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_79 == V_79 ) {
F_75 ( V_15 ) ;
F_43 ( & V_15 -> V_128 ) ;
F_46 ( & V_15 -> V_129 , 1 ) ;
F_44 ( & V_15 -> V_128 ) ;
F_6 ( & V_25 -> V_125 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_125 ) ;
return NULL ;
}
void F_77 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_130 ) ;
if ( V_15 -> V_131 != 0 ) {
V_15 -> V_132 = 1 ;
F_6 ( & V_15 -> V_130 ) ;
F_70 ( & V_15 -> V_133 ) ;
return;
}
F_6 ( & V_15 -> V_130 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_130 ) ;
V_15 -> V_131 -- ;
if ( ! V_15 -> V_131 && V_15 -> V_132 )
F_72 ( & V_15 -> V_133 ) ;
F_6 ( & V_15 -> V_130 ) ;
}
void F_75 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_130 ) ;
V_15 -> V_131 ++ ;
F_6 ( & V_15 -> V_130 ) ;
}
static int F_79 ( struct V_21 * V_15 , int V_134 )
{
T_3 V_22 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_135 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_116 = V_136 ;
V_22 = ( V_134 ) ? V_137 :
V_138 ;
V_2 -> V_19 = V_139 ;
V_2 -> V_82 = ( V_134 ) ?
F_80 ( V_15 -> V_25 ) : 0xFFFFFFFF ;
F_8 ( & V_15 -> V_78 ) ;
F_5 ( & V_2 -> V_34 , & V_15 -> V_140 ) ;
F_6 ( & V_15 -> V_78 ) ;
if ( V_134 )
F_81 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_22 ) ;
return 0 ;
}
static void F_82 ( unsigned long V_141 )
{
struct V_21 * V_15 = (struct V_21 * ) V_141 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_142 ) ;
if ( V_15 -> V_143 & V_144 ) {
F_6 ( & V_15 -> V_142 ) ;
F_78 ( V_15 ) ;
return;
}
F_25 ( L_30
L_31 , V_15 -> V_79 ,
V_15 -> V_25 -> V_145 ) ;
V_15 -> V_143 &= ~ V_146 ;
F_6 ( & V_15 -> V_142 ) ;
{
struct V_147 * V_148 = V_15 -> V_25 -> V_148 ;
struct V_149 * V_150 = V_148 -> V_151 ;
if ( V_150 ) {
F_8 ( & V_150 -> V_152 . V_153 ) ;
strcpy ( V_150 -> V_152 . V_154 ,
V_15 -> V_25 -> V_69 -> V_155 ) ;
V_150 -> V_152 . V_156 =
V_157 ;
V_150 -> V_152 . V_158 ++ ;
F_83 ( & V_15 -> V_25 -> V_159 ) ;
F_6 ( & V_150 -> V_152 . V_153 ) ;
}
}
F_84 ( V_15 , 0 ) ;
F_78 ( V_15 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_160 * V_161 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_142 ) ;
if ( ! ( V_15 -> V_143 & V_146 ) ) {
F_6 ( & V_15 -> V_142 ) ;
return;
}
F_87 ( & V_15 -> V_162 ,
( F_88 () + V_161 -> V_163 * V_164 ) ) ;
F_6 ( & V_15 -> V_142 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_160 * V_161 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_142 ) ;
if ( V_15 -> V_143 & V_146 ) {
F_6 ( & V_15 -> V_142 ) ;
return;
}
F_89 ( & V_15 -> V_162 ) ;
V_15 -> V_162 . V_165 =
( F_88 () + V_161 -> V_163 * V_164 ) ;
V_15 -> V_162 . V_141 = ( unsigned long ) V_15 ;
V_15 -> V_162 . V_166 = F_82 ;
V_15 -> V_143 &= ~ V_144 ;
V_15 -> V_143 |= V_146 ;
F_90 ( & V_15 -> V_162 ) ;
F_25 ( L_32
L_33 , V_15 -> V_79 , V_161 -> V_163 ) ;
F_6 ( & V_15 -> V_142 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_142 ) ;
if ( ! ( V_15 -> V_143 & V_146 ) ) {
F_6 ( & V_15 -> V_142 ) ;
return;
}
V_15 -> V_143 |= V_144 ;
F_6 ( & V_15 -> V_142 ) ;
F_92 ( & V_15 -> V_162 ) ;
F_8 ( & V_15 -> V_142 ) ;
V_15 -> V_143 &= ~ V_146 ;
F_6 ( & V_15 -> V_142 ) ;
}
static void F_93 ( unsigned long V_141 )
{
struct V_21 * V_15 = (struct V_21 * ) V_141 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_142 ) ;
if ( V_15 -> V_167 & V_144 ) {
F_6 ( & V_15 -> V_142 ) ;
F_78 ( V_15 ) ;
return;
}
V_15 -> V_167 &= ~ V_146 ;
F_6 ( & V_15 -> V_142 ) ;
F_79 ( V_15 , 1 ) ;
F_78 ( V_15 ) ;
}
void F_94 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_160 * V_161 = F_86 ( V_25 ) ;
if ( ! V_161 -> V_168 )
return;
if ( V_15 -> V_167 & V_146 )
return;
F_89 ( & V_15 -> V_169 ) ;
V_15 -> V_169 . V_165 = ( F_88 () + V_161 -> V_168 * V_164 ) ;
V_15 -> V_169 . V_141 = ( unsigned long ) V_15 ;
V_15 -> V_169 . V_166 = F_93 ;
V_15 -> V_167 &= ~ V_144 ;
V_15 -> V_167 |= V_146 ;
F_90 ( & V_15 -> V_169 ) ;
F_25 ( L_34
L_35 , V_15 -> V_79 , V_161 -> V_168 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_160 * V_161 = F_86 ( V_25 ) ;
if ( ! V_161 -> V_168 )
return;
F_8 ( & V_15 -> V_142 ) ;
if ( V_15 -> V_167 & V_146 ) {
F_6 ( & V_15 -> V_142 ) ;
return;
}
F_89 ( & V_15 -> V_169 ) ;
V_15 -> V_169 . V_165 = ( F_88 () + V_161 -> V_168 * V_164 ) ;
V_15 -> V_169 . V_141 = ( unsigned long ) V_15 ;
V_15 -> V_169 . V_166 = F_93 ;
V_15 -> V_167 &= ~ V_144 ;
V_15 -> V_167 |= V_146 ;
F_90 ( & V_15 -> V_169 ) ;
F_25 ( L_34
L_35 , V_15 -> V_79 , V_161 -> V_168 ) ;
F_6 ( & V_15 -> V_142 ) ;
}
void F_96 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_142 ) ;
if ( ! ( V_15 -> V_167 & V_146 ) ) {
F_6 ( & V_15 -> V_142 ) ;
return;
}
V_15 -> V_167 |= V_144 ;
F_6 ( & V_15 -> V_142 ) ;
F_92 ( & V_15 -> V_169 ) ;
F_8 ( & V_15 -> V_142 ) ;
V_15 -> V_167 &= ~ V_146 ;
F_6 ( & V_15 -> V_142 ) ;
}
int F_97 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_170 )
{
int V_171 , V_172 ;
T_1 V_173 ;
struct V_174 * V_175 ;
V_176:
V_172 = V_2 -> V_172 ;
if ( ! V_170 ) {
V_175 = & V_2 -> V_107 [ 0 ] ;
V_173 = V_2 -> V_177 ;
} else {
V_175 = & V_2 -> V_178 [ 0 ] ;
V_173 = V_2 -> V_179 ;
}
V_171 = F_98 ( V_15 , & V_175 [ 0 ] , V_173 , V_172 ) ;
if ( V_172 != V_171 ) {
if ( V_171 == - V_180 ) {
F_3 ( L_36 ) ;
goto V_176;
} else
return - 1 ;
}
V_2 -> V_172 = 0 ;
return 0 ;
}
int F_99 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_181 * V_182 = V_2 -> V_183 ;
struct V_174 V_175 ;
T_1 V_184 , V_185 ;
T_1 V_3 = V_2 -> V_186 ;
int V_171 , V_187 ;
V_188:
V_184 = V_189 ;
if ( V_15 -> V_190 -> V_191 )
V_184 += V_192 ;
V_175 . V_193 = V_2 -> V_194 ;
V_175 . V_195 = V_184 ;
V_171 = F_98 ( V_15 , & V_175 , 1 , V_184 ) ;
if ( V_184 != V_171 ) {
if ( V_171 == - V_180 ) {
F_3 ( L_36 ) ;
goto V_188;
}
return - 1 ;
}
V_185 = V_2 -> V_172 - V_184 - V_2 -> V_196 ;
if ( V_15 -> V_190 -> V_197 ) {
V_185 -= V_192 ;
if ( V_2 -> V_196 )
V_187 = ( V_2 -> V_177 - 2 ) ;
else
V_187 = ( V_2 -> V_177 - 1 ) ;
} else {
V_187 = ( V_2 -> V_177 - 1 ) ;
}
while ( V_185 ) {
T_1 V_198 = ( V_182 -> V_17 - V_3 ) ;
T_1 V_199 = F_100 ( T_1 , V_185 , V_198 ) ;
V_200:
V_171 = V_15 -> V_201 -> V_202 -> V_203 ( V_15 -> V_201 ,
F_101 ( V_182 ) , V_182 -> V_3 + V_3 , V_199 , 0 ) ;
if ( V_171 != V_199 ) {
if ( V_171 == - V_180 ) {
F_3 ( L_37
L_38 ) ;
goto V_200;
}
F_3 ( L_39 ,
V_171 ) ;
return - 1 ;
}
V_185 -= V_199 ;
V_3 = 0 ;
V_182 = F_102 ( V_182 ) ;
}
V_204:
if ( V_2 -> V_196 ) {
struct V_174 * V_205 = & V_2 -> V_107 [ V_187 ++ ] ;
V_171 = F_98 ( V_15 , V_205 , 1 , V_2 -> V_196 ) ;
if ( V_2 -> V_196 != V_171 ) {
if ( V_171 == - V_180 ) {
F_3 ( L_36 ) ;
goto V_204;
}
return - 1 ;
}
}
V_206:
if ( V_15 -> V_190 -> V_197 ) {
struct V_174 * V_207 = & V_2 -> V_107 [ V_187 ] ;
V_171 = F_98 ( V_15 , V_207 , 1 , V_192 ) ;
if ( V_192 != V_171 ) {
if ( V_171 == - V_180 ) {
F_3 ( L_36 ) ;
goto V_206;
}
return - 1 ;
}
}
return 0 ;
}
int F_103 ( struct V_21 * V_15 , T_3 V_208 , T_3 V_209 )
{
struct V_210 * V_66 ;
struct V_211 * V_212 = V_15 -> V_213 ;
V_212 -> V_214 = 1 ;
F_104 ( V_15 , V_208 , V_209 ) ;
memset ( & V_212 -> V_215 [ 0 ] , 0 , V_189 ) ;
V_66 = (struct V_210 * ) & V_212 -> V_215 [ 0 ] ;
V_66 -> V_216 = V_217 ;
V_66 -> V_208 = V_208 ;
V_66 -> V_209 = V_209 ;
V_66 -> V_218 = V_15 -> V_219 ;
return V_15 -> V_29 -> V_220 ( V_15 , V_212 , 0 ) ;
}
void F_105 ( struct V_46 * V_25 )
{
struct V_21 * V_15 ;
F_25 ( L_40
L_41 , V_25 -> V_145 ) ;
F_8 ( & V_25 -> V_125 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_106 ( V_15 -> V_190 ) ;
F_6 ( & V_25 -> V_125 ) ;
F_107 ( V_25 -> V_69 ) ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_221 * V_222 )
{
int V_141 = V_222 -> V_77 , V_223 = 0 , V_224 = 0 ;
struct V_225 V_226 ;
if ( ! V_15 || ! V_15 -> V_201 || ! V_15 -> V_190 )
return - 1 ;
memset ( & V_226 , 0 , sizeof( struct V_225 ) ) ;
F_109 ( & V_226 . V_227 , V_228 | V_229 ,
V_222 -> V_175 , V_222 -> V_173 , V_141 ) ;
while ( V_224 < V_141 ) {
V_223 = F_110 ( V_15 -> V_201 , & V_226 ,
( V_141 - V_224 ) , V_230 ) ;
if ( V_223 <= 0 ) {
F_25 ( L_42 ,
V_223 , V_224 ) ;
return V_223 ;
}
V_224 += V_223 ;
F_25 ( L_43 ,
V_223 , V_224 , V_141 ) ;
}
return V_224 ;
}
static int F_111 (
struct V_21 * V_15 ,
struct V_221 * V_222 )
{
int V_48 , V_195 ;
struct V_174 * V_205 ;
struct V_225 V_226 ;
if ( ! V_15 || ! V_15 -> V_201 || ! V_15 -> V_190 )
return - 1 ;
if ( V_222 -> V_77 <= 0 ) {
F_3 ( L_44 , V_222 -> V_77 ) ;
return - 1 ;
}
memset ( & V_226 , 0 , sizeof( struct V_225 ) ) ;
V_205 = V_222 -> V_175 ;
V_195 = V_222 -> V_173 ;
V_48 = F_112 ( V_15 -> V_201 , & V_226 , V_205 , V_195 ,
V_222 -> V_77 ) ;
if ( V_48 != V_222 -> V_77 ) {
F_3 ( L_45 ,
V_48 , V_222 -> V_77 ) ;
return - V_231 ;
}
F_25 ( L_46 , V_48 , V_222 -> V_77 ) ;
return V_48 ;
}
int F_113 (
struct V_21 * V_15 ,
struct V_174 * V_175 ,
int V_173 ,
int V_141 )
{
struct V_221 V_232 ;
if ( ! V_15 || ! V_15 -> V_201 || ! V_15 -> V_190 )
return - 1 ;
memset ( & V_232 , 0 , sizeof( struct V_221 ) ) ;
V_232 . V_175 = V_175 ;
V_232 . V_173 = V_173 ;
V_232 . V_77 = V_141 ;
V_232 . type = V_233 ;
return F_108 ( V_15 , & V_232 ) ;
}
int F_98 (
struct V_21 * V_15 ,
struct V_174 * V_175 ,
int V_173 ,
int V_141 )
{
struct V_221 V_232 ;
if ( ! V_15 || ! V_15 -> V_201 || ! V_15 -> V_190 )
return - 1 ;
memset ( & V_232 , 0 , sizeof( struct V_221 ) ) ;
V_232 . V_175 = V_175 ;
V_232 . V_173 = V_173 ;
V_232 . V_77 = V_141 ;
V_232 . type = V_234 ;
return F_111 ( V_15 , & V_232 ) ;
}
void F_104 (
struct V_21 * V_15 ,
T_3 V_208 ,
T_3 V_209 )
{
struct V_235 * V_236 = NULL ;
struct V_149 * V_150 ;
struct V_237 * V_238 ;
V_150 = F_114 ( V_15 ) ;
if ( ! V_150 )
return;
V_238 = & V_150 -> V_239 ;
F_43 ( & V_238 -> V_153 ) ;
if ( ! strcmp ( V_15 -> V_240 , V_238 -> V_241 ) &&
( ( F_88 () - V_238 -> V_242 ) < 10 ) ) {
F_44 ( & V_238 -> V_153 ) ;
return;
}
if ( V_208 == V_243 )
V_238 -> V_244 ++ ;
else if ( V_208 == V_245 ) {
V_238 -> V_246 ++ ;
V_238 -> V_247 = V_248 ;
} else if ( ( V_208 == V_249 ) &&
( V_209 == V_250 ) ) {
V_238 -> V_251 ++ ;
V_238 -> V_247 = V_252 ;
} else if ( ( V_208 == V_249 ) &&
( V_209 == V_253 ) ) {
V_238 -> V_254 ++ ;
V_238 -> V_247 = V_255 ;
} else if ( ( V_208 == V_249 ) &&
( V_209 == V_256 ) ) {
V_238 -> V_257 ++ ;
V_238 -> V_247 = V_258 ;
} else {
V_238 -> V_259 ++ ;
V_238 -> V_247 = V_260 ;
}
if ( V_208 != V_243 ) {
if ( V_15 -> V_261 )
V_236 = F_115 ( V_262 ,
V_15 -> V_261 ) ;
F_116 ( V_238 -> V_263 ,
( V_236 ? V_236 -> V_264 : L_47 ) ,
sizeof( V_238 -> V_263 ) ) ;
V_238 -> V_265 = V_15 -> V_266 ;
snprintf ( V_238 -> V_241 , V_267 ,
L_48 , V_15 -> V_240 ) ;
V_238 -> V_242 = F_88 () ;
}
F_44 ( & V_238 -> V_153 ) ;
}
struct V_149 * F_114 ( struct V_21 * V_15 )
{
struct V_147 * V_148 ;
if ( ! V_15 || ! V_15 -> V_25 )
return NULL ;
V_148 = V_15 -> V_25 -> V_148 ;
if ( ! V_148 )
return NULL ;
if ( ! V_148 -> V_151 )
return NULL ;
return V_148 -> V_151 ;
}
