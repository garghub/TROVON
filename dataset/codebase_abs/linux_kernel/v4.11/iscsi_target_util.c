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
T_1 V_48 ;
int V_49 ;
V_48 = F_24 ( & V_25 -> V_50 ) ;
if ( F_25 ( V_47 , V_48 ) ) {
F_3 ( L_7
L_8 , V_47 , V_48 ) ;
V_49 = V_51 ;
} else if ( V_47 == V_25 -> V_52 ) {
V_25 -> V_52 ++ ;
F_26 ( L_9
L_10 ,
V_25 -> V_52 ) ;
V_49 = V_53 ;
} else if ( F_25 ( V_47 , V_25 -> V_52 ) ) {
F_26 ( L_11
L_12 ,
V_47 , V_25 -> V_52 ) ;
V_49 = V_54 ;
} else {
F_3 ( L_13
L_14 , V_47 ,
V_25 -> V_52 ) ;
V_49 = V_55 ;
}
return V_49 ;
}
int F_27 ( struct V_21 * V_15 , struct V_1 * V_2 ,
unsigned char * V_56 , T_2 V_47 )
{
int V_49 , V_57 ;
bool V_58 = false ;
T_3 V_59 = V_60 ;
F_28 ( & V_15 -> V_25 -> V_61 ) ;
V_57 = F_23 ( V_15 -> V_25 , F_29 ( V_47 ) ) ;
switch ( V_57 ) {
case V_53 :
V_49 = F_30 ( V_2 , 0 ) ;
if ( ( V_49 >= 0 ) && ! F_31 ( & V_15 -> V_25 -> V_62 ) )
F_32 ( V_15 -> V_25 ) ;
else if ( V_49 < 0 ) {
V_58 = true ;
V_49 = V_63 ;
}
break;
case V_54 :
V_49 = F_33 ( V_15 -> V_25 , V_2 , F_29 ( V_47 ) ) ;
if ( V_49 < 0 ) {
V_58 = true ;
V_49 = V_63 ;
break;
}
V_49 = V_54 ;
break;
case V_55 :
case V_51 :
default:
V_2 -> V_64 = V_65 ;
F_7 ( V_2 , V_15 , V_2 -> V_64 ) ;
V_49 = V_55 ;
break;
}
F_34 ( & V_15 -> V_25 -> V_61 ) ;
if ( V_58 )
F_35 ( V_2 , V_59 , V_56 ) ;
return V_49 ;
}
int F_36 ( struct V_1 * V_2 , unsigned char * V_56 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
struct V_32 * V_32 = & V_2 -> V_32 ;
struct V_66 * V_67 = (struct V_66 * ) V_56 ;
T_1 V_68 = F_37 ( V_67 -> V_69 ) ;
if ( V_15 -> V_25 -> V_70 -> V_71 ) {
F_3 ( L_15
L_16 ) ;
F_38 ( V_32 ,
V_72 , 0 ) ;
return - 1 ;
}
if ( ( V_2 -> V_73 + V_68 ) >
V_15 -> V_25 -> V_70 -> V_74 ) {
F_3 ( L_17
L_18 ,
( V_2 -> V_73 + V_68 ) ,
V_15 -> V_25 -> V_70 -> V_74 ) ;
F_38 ( V_32 ,
V_75 , 0 ) ;
return - 1 ;
}
if ( ! ( V_67 -> V_76 & V_77 ) )
return 0 ;
if ( ( ( V_2 -> V_73 + V_68 ) != V_2 -> V_32 . V_78 ) &&
( ( V_2 -> V_73 + V_68 ) !=
V_15 -> V_25 -> V_70 -> V_74 ) ) {
F_3 ( L_19
L_20
L_21 ,
( V_2 -> V_73 + V_68 ) ,
V_15 -> V_25 -> V_70 -> V_74 , V_2 -> V_32 . V_78 ) ;
F_38 ( V_32 ,
V_75 , 0 ) ;
return - 1 ;
}
return 0 ;
}
struct V_1 * F_39 (
struct V_21 * V_15 ,
T_4 V_19 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_79 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_79 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_79 ) ;
F_3 ( L_22 ,
V_19 , V_15 -> V_80 ) ;
return NULL ;
}
struct V_1 * F_40 (
struct V_21 * V_15 ,
T_4 V_19 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
F_8 ( & V_15 -> V_79 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_81 & V_82 )
continue;
if ( V_2 -> V_19 == V_19 ) {
F_6 ( & V_15 -> V_79 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_79 ) ;
F_3 ( L_23
L_24 , V_19 , V_15 -> V_80 ) ;
if ( V_17 )
F_41 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_42 (
struct V_21 * V_15 ,
T_1 V_83 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_79 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_83 == V_83 ) {
F_6 ( & V_15 -> V_79 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_79 ) ;
F_3 ( L_25 ,
V_83 , V_15 -> V_80 ) ;
return NULL ;
}
int F_43 (
struct V_46 * V_25 ,
struct V_1 * * V_84 ,
struct V_85 * * V_86 ,
T_4 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_85 * V_87 ;
F_44 ( & V_25 -> V_88 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_44 ( & V_87 -> V_89 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_45 ( & V_87 -> V_89 ) ;
F_45 ( & V_25 -> V_88 ) ;
* V_86 = V_87 ;
* V_84 = V_2 ;
return - 2 ;
}
}
F_45 ( & V_87 -> V_89 ) ;
}
F_45 ( & V_25 -> V_88 ) ;
F_44 ( & V_25 -> V_90 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_44 ( & V_87 -> V_89 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_45 ( & V_87 -> V_89 ) ;
F_45 ( & V_25 -> V_90 ) ;
* V_86 = V_87 ;
* V_84 = V_2 ;
return 0 ;
}
}
F_45 ( & V_87 -> V_89 ) ;
}
F_45 ( & V_25 -> V_90 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_22 )
{
struct V_91 * V_92 ;
V_92 = F_2 ( V_93 , V_10 ) ;
if ( ! V_92 ) {
F_3 ( L_26
L_27 ) ;
return;
}
F_4 ( & V_92 -> V_94 ) ;
V_92 -> V_2 = V_2 ;
V_92 -> V_22 = V_22 ;
F_8 ( & V_15 -> V_95 ) ;
F_5 ( & V_92 -> V_94 , & V_15 -> V_96 ) ;
F_46 ( & V_2 -> V_97 ) ;
F_47 ( & V_15 -> V_98 , 1 ) ;
F_6 ( & V_15 -> V_95 ) ;
F_48 ( & V_15 -> V_99 ) ;
}
struct V_91 * F_49 ( struct V_21 * V_15 )
{
struct V_91 * V_92 ;
F_8 ( & V_15 -> V_95 ) ;
if ( F_31 ( & V_15 -> V_96 ) ) {
F_6 ( & V_15 -> V_95 ) ;
return NULL ;
}
V_92 = F_50 ( & V_15 -> V_96 ,
struct V_91 , V_94 ) ;
F_13 ( & V_92 -> V_94 ) ;
if ( V_92 -> V_2 )
F_51 ( & V_92 -> V_2 -> V_97 ) ;
F_6 ( & V_15 -> V_95 ) ;
return V_92 ;
}
static void F_52 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_91 * V_92 , * V_100 ;
F_8 ( & V_15 -> V_95 ) ;
if ( ! F_24 ( & V_2 -> V_97 ) ) {
F_6 ( & V_15 -> V_95 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_92 -> V_2 != V_2 )
continue;
F_51 ( & V_92 -> V_2 -> V_97 ) ;
F_13 ( & V_92 -> V_94 ) ;
F_14 ( V_93 , V_92 ) ;
}
F_6 ( & V_15 -> V_95 ) ;
if ( F_24 ( & V_2 -> V_97 ) ) {
F_3 ( L_28 ,
V_2 -> V_19 ,
F_24 ( & V_2 -> V_97 ) ) ;
}
}
int F_53 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_3 V_22 )
{
struct V_91 * V_92 ;
V_92 = F_2 ( V_93 , V_10 ) ;
if ( ! V_92 ) {
F_3 ( L_26
L_27 ) ;
return - V_101 ;
}
F_4 ( & V_92 -> V_94 ) ;
V_92 -> V_2 = V_2 ;
V_92 -> V_22 = V_22 ;
F_8 ( & V_15 -> V_102 ) ;
F_5 ( & V_92 -> V_94 , & V_15 -> V_103 ) ;
F_46 ( & V_2 -> V_104 ) ;
F_6 ( & V_15 -> V_102 ) ;
F_48 ( & V_15 -> V_99 ) ;
return 0 ;
}
struct V_91 * F_54 ( struct V_21 * V_15 )
{
struct V_91 * V_92 ;
F_8 ( & V_15 -> V_102 ) ;
if ( F_31 ( & V_15 -> V_103 ) ) {
F_6 ( & V_15 -> V_102 ) ;
return NULL ;
}
V_92 = F_50 ( & V_15 -> V_103 ,
struct V_91 , V_94 ) ;
F_13 ( & V_92 -> V_94 ) ;
if ( V_92 -> V_2 )
F_51 ( & V_92 -> V_2 -> V_104 ) ;
F_6 ( & V_15 -> V_102 ) ;
return V_92 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_91 * V_92 , * V_100 ;
F_8 ( & V_15 -> V_102 ) ;
if ( ! F_24 ( & V_2 -> V_104 ) ) {
F_6 ( & V_15 -> V_102 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_92 -> V_2 != V_2 )
continue;
F_51 ( & V_92 -> V_2 -> V_104 ) ;
F_13 ( & V_92 -> V_94 ) ;
F_14 ( V_93 , V_92 ) ;
}
F_6 ( & V_15 -> V_102 ) ;
if ( F_24 ( & V_2 -> V_104 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_24 ( & V_2 -> V_104 ) ) ;
}
}
bool F_56 ( struct V_21 * V_15 )
{
bool V_105 ;
F_8 ( & V_15 -> V_95 ) ;
V_105 = F_31 ( & V_15 -> V_96 ) ;
F_6 ( & V_15 -> V_95 ) ;
if ( ! V_105 )
return V_105 ;
F_8 ( & V_15 -> V_102 ) ;
V_105 = F_31 ( & V_15 -> V_103 ) ;
F_6 ( & V_15 -> V_102 ) ;
return V_105 ;
}
void F_57 ( struct V_21 * V_15 )
{
struct V_91 * V_92 , * V_100 ;
F_8 ( & V_15 -> V_95 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_92 -> V_94 ) ;
if ( V_92 -> V_2 )
F_51 ( & V_92 -> V_2 -> V_97 ) ;
F_14 ( V_93 , V_92 ) ;
}
F_6 ( & V_15 -> V_95 ) ;
F_8 ( & V_15 -> V_102 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_92 -> V_94 ) ;
if ( V_92 -> V_2 )
F_51 ( & V_92 -> V_2 -> V_104 ) ;
F_14 ( V_93 , V_92 ) ;
}
F_6 ( & V_15 -> V_102 ) ;
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
F_60 ( V_2 -> V_106 ) ;
F_60 ( V_2 -> V_107 ) ;
F_60 ( V_2 -> V_44 ) ;
F_60 ( V_2 -> V_108 ) ;
F_60 ( V_2 -> V_109 ) ;
F_60 ( V_2 -> V_110 ) ;
F_61 ( & V_25 -> V_24 -> V_28 , V_32 -> V_33 ) ;
}
void F_62 ( struct V_1 * V_2 , bool V_111 ,
bool V_112 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
if ( V_111 ) {
if ( V_2 -> V_113 == V_114 ) {
F_63 ( V_2 ) ;
F_15 ( V_2 ) ;
}
if ( V_2 -> V_113 == V_115 )
F_64 ( V_2 ) ;
}
if ( V_15 && V_112 ) {
F_52 ( V_2 , V_15 ) ;
F_55 ( V_2 , V_15 ) ;
}
if ( V_15 && V_15 -> V_29 -> F_58 )
V_15 -> V_29 -> F_58 ( V_15 , V_2 ) ;
}
void F_65 ( struct V_1 * V_2 , bool V_116 )
{
struct V_32 * V_32 = NULL ;
int V_117 ;
bool V_118 = false ;
switch ( V_2 -> V_119 ) {
case V_120 :
V_118 = true ;
case V_121 :
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , V_118 , V_116 ) ;
V_117 = F_66 ( V_32 , V_116 ) ;
if ( ! V_117 && V_116 && V_32 -> V_24 ) {
F_62 ( V_2 , V_118 , V_116 ) ;
F_67 ( V_32 ) ;
}
break;
case V_122 :
if ( V_2 -> V_32 . V_123 != NULL ) {
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , true , V_116 ) ;
V_117 = F_66 ( & V_2 -> V_32 , V_116 ) ;
if ( ! V_117 && V_116 && V_32 -> V_24 ) {
F_62 ( V_2 , true , V_116 ) ;
F_67 ( V_32 ) ;
}
break;
}
default:
F_62 ( V_2 , false , V_116 ) ;
F_58 ( V_2 ) ;
break;
}
}
int F_68 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_124 ) ;
if ( V_25 -> V_125 != 0 ) {
V_25 -> V_126 = 1 ;
F_6 ( & V_25 -> V_124 ) ;
if ( F_69 () )
return 2 ;
F_70 ( & V_25 -> V_127 ) ;
return 1 ;
}
F_6 ( & V_25 -> V_124 ) ;
return 0 ;
}
void F_71 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_124 ) ;
V_25 -> V_125 -- ;
if ( ! V_25 -> V_125 && V_25 -> V_126 )
F_72 ( & V_25 -> V_127 ) ;
F_6 ( & V_25 -> V_124 ) ;
}
void F_73 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_124 ) ;
V_25 -> V_125 ++ ;
F_6 ( & V_25 -> V_124 ) ;
}
struct V_21 * F_74 ( struct V_46 * V_25 , T_5 V_80 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_128 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_80 == V_80 ) &&
( V_15 -> V_129 == V_130 ) ) {
F_75 ( V_15 ) ;
F_6 ( & V_25 -> V_128 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_128 ) ;
return NULL ;
}
struct V_21 * F_76 ( struct V_46 * V_25 , T_5 V_80 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_128 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_80 == V_80 ) {
F_75 ( V_15 ) ;
F_44 ( & V_15 -> V_131 ) ;
F_47 ( & V_15 -> V_132 , 1 ) ;
F_45 ( & V_15 -> V_131 ) ;
F_6 ( & V_25 -> V_128 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_128 ) ;
return NULL ;
}
void F_77 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_133 ) ;
if ( V_15 -> V_134 != 0 ) {
V_15 -> V_135 = 1 ;
F_6 ( & V_15 -> V_133 ) ;
F_70 ( & V_15 -> V_136 ) ;
return;
}
F_6 ( & V_15 -> V_133 ) ;
}
void F_78 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_133 ) ;
V_15 -> V_134 -- ;
if ( ! V_15 -> V_134 && V_15 -> V_135 )
F_72 ( & V_15 -> V_136 ) ;
F_6 ( & V_15 -> V_133 ) ;
}
void F_75 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_133 ) ;
V_15 -> V_134 ++ ;
F_6 ( & V_15 -> V_133 ) ;
}
static int F_79 ( struct V_21 * V_15 , int V_137 )
{
T_3 V_22 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_138 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_119 = V_139 ;
V_22 = ( V_137 ) ? V_140 :
V_141 ;
V_2 -> V_19 = V_142 ;
V_2 -> V_83 = ( V_137 ) ?
F_80 ( V_15 -> V_25 ) : 0xFFFFFFFF ;
F_8 ( & V_15 -> V_79 ) ;
F_5 ( & V_2 -> V_34 , & V_15 -> V_143 ) ;
F_6 ( & V_15 -> V_79 ) ;
if ( V_137 )
F_81 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_22 ) ;
return 0 ;
}
static void F_82 ( unsigned long V_144 )
{
struct V_21 * V_15 = (struct V_21 * ) V_144 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_145 ) ;
if ( V_15 -> V_146 & V_147 ) {
F_6 ( & V_15 -> V_145 ) ;
F_78 ( V_15 ) ;
return;
}
F_26 ( L_30
L_31 , V_15 -> V_80 ,
V_15 -> V_25 -> V_148 ) ;
V_15 -> V_146 &= ~ V_149 ;
F_6 ( & V_15 -> V_145 ) ;
{
struct V_150 * V_151 = V_15 -> V_25 -> V_151 ;
struct V_152 * V_153 = V_151 -> V_154 ;
if ( V_153 ) {
F_8 ( & V_153 -> V_155 . V_156 ) ;
strcpy ( V_153 -> V_155 . V_157 ,
V_15 -> V_25 -> V_70 -> V_158 ) ;
V_153 -> V_155 . V_159 =
V_160 ;
V_153 -> V_155 . V_161 ++ ;
F_83 ( & V_15 -> V_25 -> V_162 ) ;
F_6 ( & V_153 -> V_155 . V_156 ) ;
}
}
F_84 ( V_15 , 0 ) ;
F_78 ( V_15 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_163 * V_164 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_145 ) ;
if ( ! ( V_15 -> V_146 & V_149 ) ) {
F_6 ( & V_15 -> V_145 ) ;
return;
}
F_87 ( & V_15 -> V_165 ,
( F_88 () + V_164 -> V_166 * V_167 ) ) ;
F_6 ( & V_15 -> V_145 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_163 * V_164 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_145 ) ;
if ( V_15 -> V_146 & V_149 ) {
F_6 ( & V_15 -> V_145 ) ;
return;
}
F_89 ( & V_15 -> V_165 ) ;
V_15 -> V_165 . V_168 =
( F_88 () + V_164 -> V_166 * V_167 ) ;
V_15 -> V_165 . V_144 = ( unsigned long ) V_15 ;
V_15 -> V_165 . V_169 = F_82 ;
V_15 -> V_146 &= ~ V_147 ;
V_15 -> V_146 |= V_149 ;
F_90 ( & V_15 -> V_165 ) ;
F_26 ( L_32
L_33 , V_15 -> V_80 , V_164 -> V_166 ) ;
F_6 ( & V_15 -> V_145 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_145 ) ;
if ( ! ( V_15 -> V_146 & V_149 ) ) {
F_6 ( & V_15 -> V_145 ) ;
return;
}
V_15 -> V_146 |= V_147 ;
F_6 ( & V_15 -> V_145 ) ;
F_92 ( & V_15 -> V_165 ) ;
F_8 ( & V_15 -> V_145 ) ;
V_15 -> V_146 &= ~ V_149 ;
F_6 ( & V_15 -> V_145 ) ;
}
static void F_93 ( unsigned long V_144 )
{
struct V_21 * V_15 = (struct V_21 * ) V_144 ;
F_75 ( V_15 ) ;
F_8 ( & V_15 -> V_145 ) ;
if ( V_15 -> V_170 & V_147 ) {
F_6 ( & V_15 -> V_145 ) ;
F_78 ( V_15 ) ;
return;
}
V_15 -> V_170 &= ~ V_149 ;
F_6 ( & V_15 -> V_145 ) ;
F_79 ( V_15 , 1 ) ;
F_78 ( V_15 ) ;
}
void F_94 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_163 * V_164 = F_86 ( V_25 ) ;
if ( ! V_164 -> V_171 )
return;
if ( V_15 -> V_170 & V_149 )
return;
F_89 ( & V_15 -> V_172 ) ;
V_15 -> V_172 . V_168 = ( F_88 () + V_164 -> V_171 * V_167 ) ;
V_15 -> V_172 . V_144 = ( unsigned long ) V_15 ;
V_15 -> V_172 . V_169 = F_93 ;
V_15 -> V_170 &= ~ V_147 ;
V_15 -> V_170 |= V_149 ;
F_90 ( & V_15 -> V_172 ) ;
F_26 ( L_34
L_35 , V_15 -> V_80 , V_164 -> V_171 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_163 * V_164 = F_86 ( V_25 ) ;
if ( ! V_164 -> V_171 )
return;
F_8 ( & V_15 -> V_145 ) ;
if ( V_15 -> V_170 & V_149 ) {
F_6 ( & V_15 -> V_145 ) ;
return;
}
F_89 ( & V_15 -> V_172 ) ;
V_15 -> V_172 . V_168 = ( F_88 () + V_164 -> V_171 * V_167 ) ;
V_15 -> V_172 . V_144 = ( unsigned long ) V_15 ;
V_15 -> V_172 . V_169 = F_93 ;
V_15 -> V_170 &= ~ V_147 ;
V_15 -> V_170 |= V_149 ;
F_90 ( & V_15 -> V_172 ) ;
F_26 ( L_34
L_35 , V_15 -> V_80 , V_164 -> V_171 ) ;
F_6 ( & V_15 -> V_145 ) ;
}
void F_96 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_145 ) ;
if ( ! ( V_15 -> V_170 & V_149 ) ) {
F_6 ( & V_15 -> V_145 ) ;
return;
}
V_15 -> V_170 |= V_147 ;
F_6 ( & V_15 -> V_145 ) ;
F_92 ( & V_15 -> V_172 ) ;
F_8 ( & V_15 -> V_145 ) ;
V_15 -> V_170 &= ~ V_149 ;
F_6 ( & V_15 -> V_145 ) ;
}
int F_97 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_173 )
{
int V_174 , V_175 ;
T_1 V_176 ;
struct V_177 * V_178 ;
V_179:
V_175 = V_2 -> V_175 ;
if ( ! V_173 ) {
V_178 = & V_2 -> V_109 [ 0 ] ;
V_176 = V_2 -> V_180 ;
} else {
V_178 = & V_2 -> V_181 [ 0 ] ;
V_176 = V_2 -> V_182 ;
}
V_174 = F_98 ( V_15 , & V_178 [ 0 ] , V_176 , V_175 ) ;
if ( V_175 != V_174 ) {
if ( V_174 == - V_183 ) {
F_3 ( L_36 ) ;
goto V_179;
} else
return - 1 ;
}
V_2 -> V_175 = 0 ;
return 0 ;
}
int F_99 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_184 * V_185 = V_2 -> V_186 ;
struct V_177 V_178 ;
T_1 V_187 , V_188 ;
T_1 V_3 = V_2 -> V_189 ;
int V_174 , V_190 ;
V_191:
V_187 = V_192 ;
if ( V_15 -> V_193 -> V_194 )
V_187 += V_195 ;
V_178 . V_196 = V_2 -> V_197 ;
V_178 . V_198 = V_187 ;
V_174 = F_98 ( V_15 , & V_178 , 1 , V_187 ) ;
if ( V_187 != V_174 ) {
if ( V_174 == - V_183 ) {
F_3 ( L_36 ) ;
goto V_191;
}
return - 1 ;
}
V_188 = V_2 -> V_175 - V_187 - V_2 -> V_199 ;
if ( V_15 -> V_193 -> V_200 ) {
V_188 -= V_195 ;
if ( V_2 -> V_199 )
V_190 = ( V_2 -> V_180 - 2 ) ;
else
V_190 = ( V_2 -> V_180 - 1 ) ;
} else {
V_190 = ( V_2 -> V_180 - 1 ) ;
}
while ( V_188 ) {
T_1 V_201 = ( V_185 -> V_17 - V_3 ) ;
T_1 V_202 = F_100 ( T_1 , V_188 , V_201 ) ;
V_203:
V_174 = V_15 -> V_204 -> V_205 -> V_206 ( V_15 -> V_204 ,
F_101 ( V_185 ) , V_185 -> V_3 + V_3 , V_202 , 0 ) ;
if ( V_174 != V_202 ) {
if ( V_174 == - V_183 ) {
F_3 ( L_37
L_38 ) ;
goto V_203;
}
F_3 ( L_39 ,
V_174 ) ;
return - 1 ;
}
V_188 -= V_202 ;
V_3 = 0 ;
V_185 = F_102 ( V_185 ) ;
}
V_207:
if ( V_2 -> V_199 ) {
struct V_177 * V_208 = & V_2 -> V_109 [ V_190 ++ ] ;
V_174 = F_98 ( V_15 , V_208 , 1 , V_2 -> V_199 ) ;
if ( V_2 -> V_199 != V_174 ) {
if ( V_174 == - V_183 ) {
F_3 ( L_36 ) ;
goto V_207;
}
return - 1 ;
}
}
V_209:
if ( V_15 -> V_193 -> V_200 ) {
struct V_177 * V_210 = & V_2 -> V_109 [ V_190 ] ;
V_174 = F_98 ( V_15 , V_210 , 1 , V_195 ) ;
if ( V_195 != V_174 ) {
if ( V_174 == - V_183 ) {
F_3 ( L_36 ) ;
goto V_209;
}
return - 1 ;
}
}
return 0 ;
}
int F_103 ( struct V_21 * V_15 , T_3 V_211 , T_3 V_212 )
{
struct V_213 * V_67 ;
struct V_214 * V_215 = V_15 -> V_216 ;
V_215 -> V_217 = 1 ;
F_104 ( V_15 , V_211 , V_212 ) ;
memset ( & V_215 -> V_218 [ 0 ] , 0 , V_192 ) ;
V_67 = (struct V_213 * ) & V_215 -> V_218 [ 0 ] ;
V_67 -> V_219 = V_220 ;
V_67 -> V_211 = V_211 ;
V_67 -> V_212 = V_212 ;
V_67 -> V_221 = V_15 -> V_222 ;
return V_15 -> V_29 -> V_223 ( V_15 , V_215 , 0 ) ;
}
void F_105 ( struct V_46 * V_25 )
{
struct V_21 * V_15 ;
F_26 ( L_40
L_41 , V_25 -> V_148 ) ;
F_8 ( & V_25 -> V_128 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_106 ( V_15 -> V_193 ) ;
F_6 ( & V_25 -> V_128 ) ;
F_107 ( V_25 -> V_70 ) ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_224 * V_225 )
{
int V_144 = V_225 -> V_78 , V_226 = 0 , V_227 = 0 ;
struct V_228 V_229 ;
if ( ! V_15 || ! V_15 -> V_204 || ! V_15 -> V_193 )
return - 1 ;
memset ( & V_229 , 0 , sizeof( struct V_228 ) ) ;
F_109 ( & V_229 . V_230 , V_231 | V_232 ,
V_225 -> V_178 , V_225 -> V_176 , V_144 ) ;
while ( F_110 ( & V_229 ) ) {
V_226 = F_111 ( V_15 -> V_204 , & V_229 , V_233 ) ;
if ( V_226 <= 0 ) {
F_26 ( L_42 ,
V_226 , V_227 ) ;
return V_226 ;
}
V_227 += V_226 ;
F_26 ( L_43 ,
V_226 , V_227 , V_144 ) ;
}
return V_227 ;
}
int F_112 (
struct V_21 * V_15 ,
struct V_177 * V_178 ,
int V_176 ,
int V_144 )
{
struct V_224 V_234 ;
if ( ! V_15 || ! V_15 -> V_204 || ! V_15 -> V_193 )
return - 1 ;
memset ( & V_234 , 0 , sizeof( struct V_224 ) ) ;
V_234 . V_178 = V_178 ;
V_234 . V_176 = V_176 ;
V_234 . V_78 = V_144 ;
V_234 . type = V_235 ;
return F_108 ( V_15 , & V_234 ) ;
}
int F_98 (
struct V_21 * V_15 ,
struct V_177 * V_178 ,
int V_176 ,
int V_144 )
{
struct V_228 V_229 ;
int V_236 = 0 ;
if ( ! V_15 || ! V_15 -> V_204 || ! V_15 -> V_193 )
return - 1 ;
if ( V_144 <= 0 ) {
F_3 ( L_44 , V_144 ) ;
return - 1 ;
}
memset ( & V_229 , 0 , sizeof( struct V_228 ) ) ;
F_109 ( & V_229 . V_230 , V_237 | V_232 ,
V_178 , V_176 , V_144 ) ;
while ( F_110 ( & V_229 ) ) {
int V_238 = F_113 ( V_15 -> V_204 , & V_229 ) ;
if ( V_238 <= 0 ) {
F_26 ( L_45 ,
V_238 , V_236 ) ;
return V_238 ;
}
V_236 += V_238 ;
F_26 ( L_46 ,
V_238 , V_236 , V_144 ) ;
}
return V_236 ;
}
void F_104 (
struct V_21 * V_15 ,
T_3 V_211 ,
T_3 V_212 )
{
struct V_239 * V_240 = NULL ;
struct V_152 * V_153 ;
struct V_241 * V_242 ;
V_153 = F_114 ( V_15 ) ;
if ( ! V_153 )
return;
V_242 = & V_153 -> V_243 ;
F_44 ( & V_242 -> V_156 ) ;
if ( V_211 == V_244 )
V_242 -> V_245 ++ ;
else if ( V_211 == V_246 ) {
V_242 -> V_247 ++ ;
V_242 -> V_248 = V_249 ;
} else if ( ( V_211 == V_250 ) &&
( V_212 == V_251 ) ) {
V_242 -> V_252 ++ ;
V_242 -> V_248 = V_253 ;
} else if ( ( V_211 == V_250 ) &&
( V_212 == V_254 ) ) {
V_242 -> V_255 ++ ;
V_242 -> V_248 = V_256 ;
} else if ( ( V_211 == V_250 ) &&
( V_212 == V_257 ) ) {
V_242 -> V_258 ++ ;
V_242 -> V_248 = V_259 ;
} else {
V_242 -> V_260 ++ ;
V_242 -> V_248 = V_261 ;
}
if ( V_211 != V_244 ) {
if ( V_15 -> V_262 )
V_240 = F_115 ( V_263 ,
V_15 -> V_262 ) ;
F_116 ( V_242 -> V_264 ,
( V_240 ? V_240 -> V_265 : L_47 ) ,
sizeof( V_242 -> V_264 ) ) ;
V_242 -> V_266 = V_15 -> V_267 ;
V_242 -> V_268 = V_15 -> V_269 ;
V_242 -> V_270 = F_88 () ;
}
F_45 ( & V_242 -> V_156 ) ;
}
struct V_152 * F_114 ( struct V_21 * V_15 )
{
struct V_150 * V_151 ;
if ( ! V_15 )
return NULL ;
V_151 = V_15 -> V_151 ;
if ( ! V_151 )
return NULL ;
if ( ! V_151 -> V_154 )
return NULL ;
return V_151 -> V_154 ;
}
