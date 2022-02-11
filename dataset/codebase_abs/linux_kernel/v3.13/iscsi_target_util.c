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
struct V_23 * V_24 = V_15 -> V_25 -> V_24 ;
int V_26 , V_27 ;
V_27 = F_18 ( & V_24 -> V_28 , V_22 ) ;
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
unsigned char * V_55 , T_3 V_47 )
{
int V_48 , V_56 ;
bool V_57 = false ;
T_4 V_58 = V_59 ;
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
T_5 V_19 )
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
T_5 V_19 ,
T_1 V_17 )
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
F_3 ( L_23
L_24 , V_19 , V_15 -> V_79 ) ;
if ( V_17 )
F_40 ( V_15 , V_17 , 1 ) ;
return NULL ;
}
struct V_1 * F_41 (
struct V_21 * V_15 ,
T_1 V_80 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_15 -> V_78 ) ;
F_10 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_2 -> V_80 == V_80 ) {
F_6 ( & V_15 -> V_78 ) ;
return V_2 ;
}
}
F_6 ( & V_15 -> V_78 ) ;
F_3 ( L_25 ,
V_80 , V_15 -> V_79 ) ;
return NULL ;
}
int F_42 (
struct V_46 * V_25 ,
struct V_1 * * V_81 ,
struct V_82 * * V_83 ,
T_5 V_19 )
{
struct V_1 * V_2 = NULL ;
struct V_82 * V_84 ;
F_43 ( & V_25 -> V_85 ) ;
F_10 (cr, &sess->cr_inactive_list, cr_list) {
F_43 ( & V_84 -> V_86 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_84 -> V_86 ) ;
F_44 ( & V_25 -> V_85 ) ;
* V_83 = V_84 ;
* V_81 = V_2 ;
return - 2 ;
}
}
F_44 ( & V_84 -> V_86 ) ;
}
F_44 ( & V_25 -> V_85 ) ;
F_43 ( & V_25 -> V_87 ) ;
F_10 (cr, &sess->cr_active_list, cr_list) {
F_43 ( & V_84 -> V_86 ) ;
F_10 (cmd, &cr->conn_recovery_cmd_list, i_conn_node) {
if ( V_2 -> V_19 == V_19 ) {
F_44 ( & V_84 -> V_86 ) ;
F_44 ( & V_25 -> V_87 ) ;
* V_83 = V_84 ;
* V_81 = V_2 ;
return 0 ;
}
}
F_44 ( & V_84 -> V_86 ) ;
}
F_44 ( & V_25 -> V_87 ) ;
return - 1 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_4 V_88 )
{
struct V_89 * V_90 ;
V_90 = F_2 ( V_91 , V_10 ) ;
if ( ! V_90 ) {
F_3 ( L_26
L_27 ) ;
return;
}
F_4 ( & V_90 -> V_92 ) ;
V_90 -> V_2 = V_2 ;
V_90 -> V_88 = V_88 ;
F_8 ( & V_15 -> V_93 ) ;
F_5 ( & V_90 -> V_92 , & V_15 -> V_94 ) ;
F_45 ( & V_2 -> V_95 ) ;
F_46 ( & V_15 -> V_96 , 1 ) ;
F_6 ( & V_15 -> V_93 ) ;
F_47 ( & V_15 -> V_97 ) ;
}
struct V_89 * F_48 ( struct V_21 * V_15 )
{
struct V_89 * V_90 ;
F_8 ( & V_15 -> V_93 ) ;
if ( F_30 ( & V_15 -> V_94 ) ) {
F_6 ( & V_15 -> V_93 ) ;
return NULL ;
}
V_90 = F_49 ( & V_15 -> V_94 ,
struct V_89 , V_92 ) ;
F_13 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_2 )
F_50 ( & V_90 -> V_2 -> V_95 ) ;
F_6 ( & V_15 -> V_93 ) ;
return V_90 ;
}
static void F_51 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_89 * V_90 , * V_98 ;
F_8 ( & V_15 -> V_93 ) ;
if ( ! F_52 ( & V_2 -> V_95 ) ) {
F_6 ( & V_15 -> V_93 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
if ( V_90 -> V_2 != V_2 )
continue;
F_50 ( & V_90 -> V_2 -> V_95 ) ;
F_13 ( & V_90 -> V_92 ) ;
F_14 ( V_91 , V_90 ) ;
}
F_6 ( & V_15 -> V_93 ) ;
if ( F_52 ( & V_2 -> V_95 ) ) {
F_3 ( L_28 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_95 ) ) ;
}
}
void F_53 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
T_4 V_88 )
{
struct V_89 * V_90 ;
V_90 = F_2 ( V_91 , V_10 ) ;
if ( ! V_90 ) {
F_3 ( L_26
L_27 ) ;
return;
}
F_4 ( & V_90 -> V_92 ) ;
V_90 -> V_2 = V_2 ;
V_90 -> V_88 = V_88 ;
F_8 ( & V_15 -> V_99 ) ;
F_5 ( & V_90 -> V_92 , & V_15 -> V_100 ) ;
F_45 ( & V_2 -> V_101 ) ;
F_6 ( & V_15 -> V_99 ) ;
F_47 ( & V_15 -> V_97 ) ;
}
struct V_89 * F_54 ( struct V_21 * V_15 )
{
struct V_89 * V_90 ;
F_8 ( & V_15 -> V_99 ) ;
if ( F_30 ( & V_15 -> V_100 ) ) {
F_6 ( & V_15 -> V_99 ) ;
return NULL ;
}
V_90 = F_49 ( & V_15 -> V_100 ,
struct V_89 , V_92 ) ;
F_13 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_2 )
F_50 ( & V_90 -> V_2 -> V_101 ) ;
F_6 ( & V_15 -> V_99 ) ;
return V_90 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_89 * V_90 , * V_98 ;
F_8 ( & V_15 -> V_99 ) ;
if ( ! F_52 ( & V_2 -> V_101 ) ) {
F_6 ( & V_15 -> V_99 ) ;
return;
}
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
if ( V_90 -> V_2 != V_2 )
continue;
F_50 ( & V_90 -> V_2 -> V_101 ) ;
F_13 ( & V_90 -> V_92 ) ;
F_14 ( V_91 , V_90 ) ;
}
F_6 ( & V_15 -> V_99 ) ;
if ( F_52 ( & V_2 -> V_101 ) ) {
F_3 ( L_29 ,
V_2 -> V_19 ,
F_52 ( & V_2 -> V_101 ) ) ;
}
}
bool F_56 ( struct V_21 * V_15 )
{
bool V_102 ;
F_8 ( & V_15 -> V_93 ) ;
V_102 = F_30 ( & V_15 -> V_94 ) ;
F_6 ( & V_15 -> V_93 ) ;
if ( ! V_102 )
return V_102 ;
F_8 ( & V_15 -> V_99 ) ;
V_102 = F_30 ( & V_15 -> V_100 ) ;
F_6 ( & V_15 -> V_99 ) ;
return V_102 ;
}
void F_57 ( struct V_21 * V_15 )
{
struct V_89 * V_90 , * V_98 ;
F_8 ( & V_15 -> V_93 ) ;
F_16 (qr, qr_tmp, &conn->immed_queue_list, qr_list) {
F_13 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_2 )
F_50 ( & V_90 -> V_2 -> V_95 ) ;
F_14 ( V_91 , V_90 ) ;
}
F_6 ( & V_15 -> V_93 ) ;
F_8 ( & V_15 -> V_99 ) ;
F_16 (qr, qr_tmp, &conn->response_queue_list,
qr_list) {
F_13 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_2 )
F_50 ( & V_90 -> V_2 -> V_101 ) ;
F_14 ( V_91 , V_90 ) ;
}
F_6 ( & V_15 -> V_99 ) ;
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
F_60 ( V_2 -> V_103 ) ;
F_60 ( V_2 -> V_104 ) ;
F_60 ( V_2 -> V_44 ) ;
F_60 ( V_2 -> V_105 ) ;
F_60 ( V_2 -> V_106 ) ;
F_60 ( V_2 -> V_107 ) ;
F_61 ( & V_25 -> V_24 -> V_28 , V_32 -> V_33 ) ;
}
static void F_62 ( struct V_1 * V_2 , bool V_108 ,
bool V_109 )
{
struct V_21 * V_15 = V_2 -> V_15 ;
if ( V_108 ) {
if ( V_2 -> V_110 == V_111 ) {
F_63 ( V_2 ) ;
F_15 ( V_2 ) ;
}
if ( V_2 -> V_110 == V_112 )
F_64 ( V_2 ) ;
}
if ( V_15 && V_109 ) {
F_51 ( V_2 , V_15 ) ;
F_55 ( V_2 , V_15 ) ;
}
}
void F_65 ( struct V_1 * V_2 , bool V_113 )
{
struct V_32 * V_32 = NULL ;
int V_114 ;
switch ( V_2 -> V_115 ) {
case V_116 :
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , true , V_113 ) ;
case V_117 :
V_114 = F_66 ( & V_2 -> V_32 , V_113 ) ;
if ( ! V_114 && V_113 && V_32 && V_32 -> V_24 ) {
F_62 ( V_2 , true , V_113 ) ;
F_67 ( V_32 -> V_24 , V_32 ) ;
}
break;
case V_118 :
if ( V_2 -> V_32 . V_119 != NULL ) {
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , true , V_113 ) ;
V_114 = F_66 ( & V_2 -> V_32 , V_113 ) ;
if ( ! V_114 && V_113 && V_32 -> V_24 ) {
F_62 ( V_2 , true , V_113 ) ;
F_67 ( V_32 -> V_24 , V_32 ) ;
}
break;
}
default:
F_62 ( V_2 , false , V_113 ) ;
F_58 ( V_2 ) ;
break;
}
}
int F_68 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_120 ) ;
if ( V_25 -> V_121 != 0 ) {
V_25 -> V_122 = 1 ;
F_6 ( & V_25 -> V_120 ) ;
if ( F_69 () )
return 2 ;
F_70 ( & V_25 -> V_123 ) ;
return 1 ;
}
F_6 ( & V_25 -> V_120 ) ;
return 0 ;
}
void F_71 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_120 ) ;
V_25 -> V_121 -- ;
if ( ! V_25 -> V_121 && V_25 -> V_122 )
F_72 ( & V_25 -> V_123 ) ;
F_6 ( & V_25 -> V_120 ) ;
}
void F_73 ( struct V_46 * V_25 )
{
F_8 ( & V_25 -> V_120 ) ;
V_25 -> V_121 ++ ;
F_6 ( & V_25 -> V_120 ) ;
}
int F_74 ( struct V_21 * V_15 )
{
int V_124 = 0 , V_125 = 0 , V_126 = 0 ;
T_1 V_127 = ( V_15 -> V_128 -> V_127 * 4 ) ;
T_1 V_129 = ( V_15 -> V_128 -> V_129 * 4 ) ;
if ( V_15 -> V_128 -> V_130 ) {
V_15 -> V_131 += V_132 ;
if ( V_15 -> V_131 <= V_129 ) {
V_15 -> V_131 = ( V_129 - V_15 -> V_131 ) ;
} else {
V_125 = ( V_15 -> V_131 / V_129 ) ;
V_126 = ( V_129 * ( V_125 + 1 ) ) +
( V_125 * V_133 ) ;
V_15 -> V_131 = ( V_126 - V_15 -> V_131 ) ;
}
V_15 -> V_134 = 0 ;
F_25 ( L_30
L_31 , V_15 -> V_131 ) ;
}
if ( V_15 -> V_128 -> V_135 ) {
if ( V_15 -> V_136 <= V_127 ) {
V_15 -> V_136 = ( V_127 - V_15 -> V_136 ) ;
} else {
V_124 = ( V_15 -> V_136 / V_127 ) ;
V_126 = ( V_127 * ( V_124 + 1 ) ) +
( V_124 * V_133 ) ;
V_15 -> V_136 = ( V_126 - V_15 -> V_136 ) ;
}
F_25 ( L_32
L_31 , V_15 -> V_136 ) ;
}
return 0 ;
}
struct V_21 * F_75 ( struct V_46 * V_25 , T_6 V_79 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_137 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_79 == V_79 ) &&
( V_15 -> V_138 == V_139 ) ) {
F_76 ( V_15 ) ;
F_6 ( & V_25 -> V_137 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_137 ) ;
return NULL ;
}
struct V_21 * F_77 ( struct V_46 * V_25 , T_6 V_79 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_137 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_79 == V_79 ) {
F_76 ( V_15 ) ;
F_43 ( & V_15 -> V_140 ) ;
F_46 ( & V_15 -> V_141 , 1 ) ;
F_44 ( & V_15 -> V_140 ) ;
F_6 ( & V_25 -> V_137 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_137 ) ;
return NULL ;
}
void F_78 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_142 ) ;
if ( V_15 -> V_143 != 0 ) {
V_15 -> V_144 = 1 ;
F_6 ( & V_15 -> V_142 ) ;
F_70 ( & V_15 -> V_145 ) ;
return;
}
F_6 ( & V_15 -> V_142 ) ;
}
void F_79 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_142 ) ;
V_15 -> V_143 -- ;
if ( ! V_15 -> V_143 && V_15 -> V_144 )
F_72 ( & V_15 -> V_145 ) ;
F_6 ( & V_15 -> V_142 ) ;
}
void F_76 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_142 ) ;
V_15 -> V_143 ++ ;
F_6 ( & V_15 -> V_142 ) ;
}
static int F_80 ( struct V_21 * V_15 , int V_146 )
{
T_4 V_88 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_10 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_115 = V_147 ;
V_88 = ( V_146 ) ? V_148 :
V_149 ;
V_2 -> V_19 = V_150 ;
F_8 ( & V_15 -> V_25 -> V_151 ) ;
V_2 -> V_80 = ( V_146 ) ? V_15 -> V_25 -> V_80 ++ :
0xFFFFFFFF ;
if ( V_146 && ( V_2 -> V_80 == 0xFFFFFFFF ) )
V_2 -> V_80 = V_15 -> V_25 -> V_80 ++ ;
F_6 ( & V_15 -> V_25 -> V_151 ) ;
F_8 ( & V_15 -> V_78 ) ;
F_5 ( & V_2 -> V_34 , & V_15 -> V_152 ) ;
F_6 ( & V_15 -> V_78 ) ;
if ( V_146 )
F_81 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_88 ) ;
return 0 ;
}
static void F_82 ( unsigned long V_153 )
{
struct V_21 * V_15 = (struct V_21 * ) V_153 ;
F_76 ( V_15 ) ;
F_8 ( & V_15 -> V_154 ) ;
if ( V_15 -> V_155 & V_156 ) {
F_6 ( & V_15 -> V_154 ) ;
F_79 ( V_15 ) ;
return;
}
F_25 ( L_33
L_34 , V_15 -> V_79 ,
V_15 -> V_25 -> V_157 ) ;
V_15 -> V_155 &= ~ V_158 ;
F_6 ( & V_15 -> V_154 ) ;
{
struct V_159 * V_160 = V_15 -> V_25 -> V_160 ;
struct V_161 * V_162 = V_160 -> V_163 ;
if ( V_162 ) {
F_8 ( & V_162 -> V_164 . V_165 ) ;
strcpy ( V_162 -> V_164 . V_166 ,
V_15 -> V_25 -> V_69 -> V_167 ) ;
V_162 -> V_164 . V_168 =
V_169 ;
V_162 -> V_164 . V_170 ++ ;
F_83 ( & V_15 -> V_25 -> V_171 ) ;
F_6 ( & V_162 -> V_164 . V_165 ) ;
}
}
F_84 ( V_15 , 0 ) ;
F_79 ( V_15 ) ;
}
void F_85 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_172 * V_173 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_154 ) ;
if ( ! ( V_15 -> V_155 & V_158 ) ) {
F_6 ( & V_15 -> V_154 ) ;
return;
}
F_87 ( & V_15 -> V_174 ,
( F_88 () + V_173 -> V_175 * V_176 ) ) ;
F_6 ( & V_15 -> V_154 ) ;
}
void F_81 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_172 * V_173 = F_86 ( V_25 ) ;
F_8 ( & V_15 -> V_154 ) ;
if ( V_15 -> V_155 & V_158 ) {
F_6 ( & V_15 -> V_154 ) ;
return;
}
F_89 ( & V_15 -> V_174 ) ;
V_15 -> V_174 . V_177 =
( F_88 () + V_173 -> V_175 * V_176 ) ;
V_15 -> V_174 . V_153 = ( unsigned long ) V_15 ;
V_15 -> V_174 . V_178 = F_82 ;
V_15 -> V_155 &= ~ V_156 ;
V_15 -> V_155 |= V_158 ;
F_90 ( & V_15 -> V_174 ) ;
F_25 ( L_35
L_36 , V_15 -> V_79 , V_173 -> V_175 ) ;
F_6 ( & V_15 -> V_154 ) ;
}
void F_91 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_154 ) ;
if ( ! ( V_15 -> V_155 & V_158 ) ) {
F_6 ( & V_15 -> V_154 ) ;
return;
}
V_15 -> V_155 |= V_156 ;
F_6 ( & V_15 -> V_154 ) ;
F_92 ( & V_15 -> V_174 ) ;
F_8 ( & V_15 -> V_154 ) ;
V_15 -> V_155 &= ~ V_158 ;
F_6 ( & V_15 -> V_154 ) ;
}
static void F_93 ( unsigned long V_153 )
{
struct V_21 * V_15 = (struct V_21 * ) V_153 ;
F_76 ( V_15 ) ;
F_8 ( & V_15 -> V_154 ) ;
if ( V_15 -> V_179 & V_156 ) {
F_6 ( & V_15 -> V_154 ) ;
F_79 ( V_15 ) ;
return;
}
V_15 -> V_179 &= ~ V_158 ;
F_6 ( & V_15 -> V_154 ) ;
F_80 ( V_15 , 1 ) ;
F_79 ( V_15 ) ;
}
void F_94 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_172 * V_173 = F_86 ( V_25 ) ;
if ( ! V_173 -> V_180 )
return;
if ( V_15 -> V_179 & V_158 )
return;
F_89 ( & V_15 -> V_181 ) ;
V_15 -> V_181 . V_177 = ( F_88 () + V_173 -> V_180 * V_176 ) ;
V_15 -> V_181 . V_153 = ( unsigned long ) V_15 ;
V_15 -> V_181 . V_178 = F_93 ;
V_15 -> V_179 &= ~ V_156 ;
V_15 -> V_179 |= V_158 ;
F_90 ( & V_15 -> V_181 ) ;
F_25 ( L_37
L_38 , V_15 -> V_79 , V_173 -> V_180 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_172 * V_173 = F_86 ( V_25 ) ;
if ( ! V_173 -> V_180 )
return;
F_8 ( & V_15 -> V_154 ) ;
if ( V_15 -> V_179 & V_158 ) {
F_6 ( & V_15 -> V_154 ) ;
return;
}
F_89 ( & V_15 -> V_181 ) ;
V_15 -> V_181 . V_177 = ( F_88 () + V_173 -> V_180 * V_176 ) ;
V_15 -> V_181 . V_153 = ( unsigned long ) V_15 ;
V_15 -> V_181 . V_178 = F_93 ;
V_15 -> V_179 &= ~ V_156 ;
V_15 -> V_179 |= V_158 ;
F_90 ( & V_15 -> V_181 ) ;
F_25 ( L_37
L_38 , V_15 -> V_79 , V_173 -> V_180 ) ;
F_6 ( & V_15 -> V_154 ) ;
}
void F_96 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_154 ) ;
if ( ! ( V_15 -> V_179 & V_158 ) ) {
F_6 ( & V_15 -> V_154 ) ;
return;
}
V_15 -> V_179 |= V_156 ;
F_6 ( & V_15 -> V_154 ) ;
F_92 ( & V_15 -> V_181 ) ;
F_8 ( & V_15 -> V_154 ) ;
V_15 -> V_179 &= ~ V_158 ;
F_6 ( & V_15 -> V_154 ) ;
}
int F_97 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_182 )
{
int V_183 , V_184 ;
T_1 V_185 ;
struct V_186 * V_187 ;
V_188:
V_184 = V_2 -> V_184 ;
if ( ! V_182 ) {
V_187 = & V_2 -> V_106 [ 0 ] ;
V_185 = V_2 -> V_189 ;
} else {
V_187 = & V_2 -> V_190 [ 0 ] ;
V_185 = V_2 -> V_191 ;
}
V_183 = F_98 ( V_15 , & V_187 [ 0 ] , V_185 , V_184 ) ;
if ( V_184 != V_183 ) {
if ( V_183 == - V_192 ) {
F_3 ( L_39 ) ;
goto V_188;
} else
return - 1 ;
}
V_2 -> V_184 = 0 ;
return 0 ;
}
int F_99 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_193 * V_194 = V_2 -> V_195 ;
struct V_186 V_187 ;
T_1 V_196 , V_197 ;
T_1 V_3 = V_2 -> V_198 ;
int V_183 , V_199 ;
V_200:
V_196 = V_132 ;
if ( V_15 -> V_128 -> V_201 )
V_196 += V_202 ;
V_187 . V_203 = V_2 -> V_204 ;
V_187 . V_205 = V_196 ;
V_183 = F_98 ( V_15 , & V_187 , 1 , V_196 ) ;
if ( V_196 != V_183 ) {
if ( V_183 == - V_192 ) {
F_3 ( L_39 ) ;
goto V_200;
}
return - 1 ;
}
V_197 = V_2 -> V_184 - V_196 - V_2 -> V_206 ;
if ( V_15 -> V_128 -> V_207 ) {
V_197 -= V_202 ;
if ( V_2 -> V_206 )
V_199 = ( V_2 -> V_189 - 2 ) ;
else
V_199 = ( V_2 -> V_189 - 1 ) ;
} else {
V_199 = ( V_2 -> V_189 - 1 ) ;
}
while ( V_197 ) {
T_1 V_208 = ( V_194 -> V_17 - V_3 ) ;
T_1 V_209 = F_100 ( T_1 , V_197 , V_208 ) ;
V_210:
V_183 = V_15 -> V_211 -> V_212 -> V_213 ( V_15 -> V_211 ,
F_101 ( V_194 ) , V_194 -> V_3 + V_3 , V_209 , 0 ) ;
if ( V_183 != V_209 ) {
if ( V_183 == - V_192 ) {
F_3 ( L_40
L_41 ) ;
goto V_210;
}
F_3 ( L_42 ,
V_183 ) ;
return - 1 ;
}
V_197 -= V_209 ;
V_3 = 0 ;
V_194 = F_102 ( V_194 ) ;
}
V_214:
if ( V_2 -> V_206 ) {
struct V_186 * V_215 = & V_2 -> V_106 [ V_199 ++ ] ;
V_183 = F_98 ( V_15 , V_215 , 1 , V_2 -> V_206 ) ;
if ( V_2 -> V_206 != V_183 ) {
if ( V_183 == - V_192 ) {
F_3 ( L_39 ) ;
goto V_214;
}
return - 1 ;
}
}
V_216:
if ( V_15 -> V_128 -> V_207 ) {
struct V_186 * V_217 = & V_2 -> V_106 [ V_199 ] ;
V_183 = F_98 ( V_15 , V_217 , 1 , V_202 ) ;
if ( V_202 != V_183 ) {
if ( V_183 == - V_192 ) {
F_3 ( L_39 ) ;
goto V_216;
}
return - 1 ;
}
}
return 0 ;
}
int F_103 ( struct V_21 * V_15 , T_4 V_218 , T_4 V_219 )
{
struct V_220 * V_66 ;
struct V_221 * V_222 = V_15 -> V_223 ;
V_222 -> V_224 = 1 ;
F_104 ( V_15 , V_218 , V_219 ) ;
V_66 = (struct V_220 * ) & V_222 -> V_225 [ 0 ] ;
V_66 -> V_226 = V_227 ;
V_66 -> V_218 = V_218 ;
V_66 -> V_219 = V_219 ;
V_66 -> V_228 = V_15 -> V_229 ;
return V_15 -> V_29 -> V_230 ( V_15 , V_222 , 0 ) ;
}
void F_105 ( struct V_46 * V_25 )
{
struct V_21 * V_15 ;
F_25 ( L_43
L_44 , V_25 -> V_157 ) ;
F_8 ( & V_25 -> V_137 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_106 ( V_15 -> V_128 ) ;
F_6 ( & V_25 -> V_137 ) ;
F_107 ( V_25 -> V_69 ) ;
}
static int F_108 (
struct V_21 * V_15 ,
struct V_231 * V_232 )
{
int V_153 = V_232 -> V_77 , V_233 = 0 , V_234 = 0 , V_205 ;
struct V_186 * V_215 ;
struct V_235 V_236 ;
if ( ! V_15 || ! V_15 -> V_211 || ! V_15 -> V_128 )
return - 1 ;
memset ( & V_236 , 0 , sizeof( struct V_235 ) ) ;
V_215 = V_232 -> V_187 ;
V_205 = V_232 -> V_185 ;
while ( V_234 < V_153 ) {
V_233 = F_109 ( V_15 -> V_211 , & V_236 , V_215 , V_205 ,
( V_153 - V_234 ) , V_237 ) ;
if ( V_233 <= 0 ) {
F_25 ( L_45 ,
V_233 , V_234 ) ;
return V_233 ;
}
V_234 += V_233 ;
F_25 ( L_46 ,
V_233 , V_234 , V_153 ) ;
}
return V_234 ;
}
static int F_110 (
struct V_21 * V_15 ,
struct V_231 * V_232 )
{
int V_153 = V_232 -> V_77 , V_238 = 0 , V_239 = 0 , V_205 ;
struct V_186 * V_215 ;
struct V_235 V_236 ;
if ( ! V_15 || ! V_15 -> V_211 || ! V_15 -> V_128 )
return - 1 ;
if ( V_153 <= 0 ) {
F_3 ( L_47 , V_153 ) ;
return - 1 ;
}
memset ( & V_236 , 0 , sizeof( struct V_235 ) ) ;
V_215 = V_232 -> V_187 ;
V_205 = V_232 -> V_185 ;
while ( V_238 < V_153 ) {
V_239 = F_111 ( V_15 -> V_211 , & V_236 , V_215 , V_205 ,
( V_153 - V_238 ) ) ;
if ( V_239 <= 0 ) {
F_25 ( L_48 ,
V_239 , V_238 ) ;
return V_239 ;
}
V_238 += V_239 ;
F_25 ( L_49 ,
V_239 , V_238 , V_153 ) ;
}
return V_238 ;
}
int F_112 (
struct V_21 * V_15 ,
struct V_186 * V_187 ,
int V_185 ,
int V_153 )
{
struct V_231 V_240 ;
if ( ! V_15 || ! V_15 -> V_211 || ! V_15 -> V_128 )
return - 1 ;
memset ( & V_240 , 0 , sizeof( struct V_231 ) ) ;
V_240 . V_187 = V_187 ;
V_240 . V_185 = V_185 ;
V_240 . V_77 = V_153 ;
V_240 . type = V_241 ;
return F_108 ( V_15 , & V_240 ) ;
}
int F_98 (
struct V_21 * V_15 ,
struct V_186 * V_187 ,
int V_185 ,
int V_153 )
{
struct V_231 V_240 ;
if ( ! V_15 || ! V_15 -> V_211 || ! V_15 -> V_128 )
return - 1 ;
memset ( & V_240 , 0 , sizeof( struct V_231 ) ) ;
V_240 . V_187 = V_187 ;
V_240 . V_185 = V_185 ;
V_240 . V_77 = V_153 ;
V_240 . type = V_242 ;
return F_110 ( V_15 , & V_240 ) ;
}
void F_104 (
struct V_21 * V_15 ,
T_4 V_218 ,
T_4 V_219 )
{
struct V_243 * V_244 = NULL ;
struct V_161 * V_162 ;
struct V_245 * V_246 ;
V_162 = F_113 ( V_15 ) ;
if ( ! V_162 )
return;
V_246 = & V_162 -> V_247 ;
F_43 ( & V_246 -> V_165 ) ;
if ( ! strcmp ( V_15 -> V_248 , V_246 -> V_249 ) &&
( ( F_88 () - V_246 -> V_250 ) < 10 ) ) {
F_44 ( & V_246 -> V_165 ) ;
return;
}
if ( V_218 == V_251 )
V_246 -> V_252 ++ ;
else if ( V_218 == V_253 ) {
V_246 -> V_254 ++ ;
V_246 -> V_255 = V_256 ;
} else if ( ( V_218 == V_257 ) &&
( V_219 == V_258 ) ) {
V_246 -> V_259 ++ ;
V_246 -> V_255 = V_260 ;
} else if ( ( V_218 == V_257 ) &&
( V_219 == V_261 ) ) {
V_246 -> V_262 ++ ;
V_246 -> V_255 = V_263 ;
} else if ( ( V_218 == V_257 ) &&
( V_219 == V_264 ) ) {
V_246 -> V_265 ++ ;
V_246 -> V_255 = V_266 ;
} else {
V_246 -> V_267 ++ ;
V_246 -> V_255 = V_268 ;
}
if ( V_218 != V_251 ) {
if ( V_15 -> V_269 )
V_244 = F_114 ( V_270 ,
V_15 -> V_269 ) ;
strcpy ( V_246 -> V_271 ,
( V_244 ? V_244 -> V_272 : L_50 ) ) ;
V_246 -> V_273 = V_15 -> V_274 ;
snprintf ( V_246 -> V_249 , V_275 ,
L_51 , V_15 -> V_248 ) ;
V_246 -> V_250 = F_88 () ;
}
F_44 ( & V_246 -> V_165 ) ;
}
struct V_161 * F_113 ( struct V_21 * V_15 )
{
struct V_159 * V_160 ;
if ( ! V_15 || ! V_15 -> V_25 )
return NULL ;
V_160 = V_15 -> V_25 -> V_160 ;
if ( ! V_160 )
return NULL ;
if ( ! V_160 -> V_163 )
return NULL ;
return V_160 -> V_163 ;
}
