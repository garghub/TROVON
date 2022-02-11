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
F_67 ( V_32 -> V_24 , V_32 ) ;
}
break;
case V_119 :
if ( V_2 -> V_32 . V_120 != NULL ) {
V_32 = & V_2 -> V_32 ;
F_62 ( V_2 , true , V_114 ) ;
V_115 = F_66 ( & V_2 -> V_32 , V_114 ) ;
if ( ! V_115 && V_114 && V_32 -> V_24 ) {
F_62 ( V_2 , true , V_114 ) ;
F_67 ( V_32 -> V_24 , V_32 ) ;
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
int F_74 ( struct V_21 * V_15 )
{
int V_125 = 0 , V_126 = 0 , V_127 = 0 ;
T_1 V_128 = ( V_15 -> V_129 -> V_128 * 4 ) ;
T_1 V_130 = ( V_15 -> V_129 -> V_130 * 4 ) ;
if ( V_15 -> V_129 -> V_131 ) {
V_15 -> V_132 += V_133 ;
if ( V_15 -> V_132 <= V_130 ) {
V_15 -> V_132 = ( V_130 - V_15 -> V_132 ) ;
} else {
V_126 = ( V_15 -> V_132 / V_130 ) ;
V_127 = ( V_130 * ( V_126 + 1 ) ) +
( V_126 * V_134 ) ;
V_15 -> V_132 = ( V_127 - V_15 -> V_132 ) ;
}
V_15 -> V_135 = 0 ;
F_25 ( L_30
L_31 , V_15 -> V_132 ) ;
}
if ( V_15 -> V_129 -> V_136 ) {
if ( V_15 -> V_137 <= V_128 ) {
V_15 -> V_137 = ( V_128 - V_15 -> V_137 ) ;
} else {
V_125 = ( V_15 -> V_137 / V_128 ) ;
V_127 = ( V_128 * ( V_125 + 1 ) ) +
( V_125 * V_134 ) ;
V_15 -> V_137 = ( V_127 - V_15 -> V_137 ) ;
}
F_25 ( L_32
L_31 , V_15 -> V_137 ) ;
}
return 0 ;
}
struct V_21 * F_75 ( struct V_46 * V_25 , T_5 V_79 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_138 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( ( V_15 -> V_79 == V_79 ) &&
( V_15 -> V_139 == V_140 ) ) {
F_76 ( V_15 ) ;
F_6 ( & V_25 -> V_138 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_138 ) ;
return NULL ;
}
struct V_21 * F_77 ( struct V_46 * V_25 , T_5 V_79 )
{
struct V_21 * V_15 ;
F_8 ( & V_25 -> V_138 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list) {
if ( V_15 -> V_79 == V_79 ) {
F_76 ( V_15 ) ;
F_43 ( & V_15 -> V_141 ) ;
F_46 ( & V_15 -> V_142 , 1 ) ;
F_44 ( & V_15 -> V_141 ) ;
F_6 ( & V_25 -> V_138 ) ;
return V_15 ;
}
}
F_6 ( & V_25 -> V_138 ) ;
return NULL ;
}
void F_78 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_143 ) ;
if ( V_15 -> V_144 != 0 ) {
V_15 -> V_145 = 1 ;
F_6 ( & V_15 -> V_143 ) ;
F_70 ( & V_15 -> V_146 ) ;
return;
}
F_6 ( & V_15 -> V_143 ) ;
}
void F_79 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_143 ) ;
V_15 -> V_144 -- ;
if ( ! V_15 -> V_144 && V_15 -> V_145 )
F_72 ( & V_15 -> V_146 ) ;
F_6 ( & V_15 -> V_143 ) ;
}
void F_76 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_143 ) ;
V_15 -> V_144 ++ ;
F_6 ( & V_15 -> V_143 ) ;
}
static int F_80 ( struct V_21 * V_15 , int V_147 )
{
T_3 V_22 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_15 , V_148 ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_116 = V_149 ;
V_22 = ( V_147 ) ? V_150 :
V_151 ;
V_2 -> V_19 = V_152 ;
V_2 -> V_82 = ( V_147 ) ?
F_81 ( V_15 -> V_25 ) : 0xFFFFFFFF ;
F_8 ( & V_15 -> V_78 ) ;
F_5 ( & V_2 -> V_34 , & V_15 -> V_153 ) ;
F_6 ( & V_15 -> V_78 ) ;
if ( V_147 )
F_82 ( V_15 ) ;
F_7 ( V_2 , V_15 , V_22 ) ;
return 0 ;
}
static void F_83 ( unsigned long V_154 )
{
struct V_21 * V_15 = (struct V_21 * ) V_154 ;
F_76 ( V_15 ) ;
F_8 ( & V_15 -> V_155 ) ;
if ( V_15 -> V_156 & V_157 ) {
F_6 ( & V_15 -> V_155 ) ;
F_79 ( V_15 ) ;
return;
}
F_25 ( L_33
L_34 , V_15 -> V_79 ,
V_15 -> V_25 -> V_158 ) ;
V_15 -> V_156 &= ~ V_159 ;
F_6 ( & V_15 -> V_155 ) ;
{
struct V_160 * V_161 = V_15 -> V_25 -> V_161 ;
struct V_162 * V_163 = V_161 -> V_164 ;
if ( V_163 ) {
F_8 ( & V_163 -> V_165 . V_166 ) ;
strcpy ( V_163 -> V_165 . V_167 ,
V_15 -> V_25 -> V_69 -> V_168 ) ;
V_163 -> V_165 . V_169 =
V_170 ;
V_163 -> V_165 . V_171 ++ ;
F_84 ( & V_15 -> V_25 -> V_172 ) ;
F_6 ( & V_163 -> V_165 . V_166 ) ;
}
}
F_85 ( V_15 , 0 ) ;
F_79 ( V_15 ) ;
}
void F_86 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_173 * V_174 = F_87 ( V_25 ) ;
F_8 ( & V_15 -> V_155 ) ;
if ( ! ( V_15 -> V_156 & V_159 ) ) {
F_6 ( & V_15 -> V_155 ) ;
return;
}
F_88 ( & V_15 -> V_175 ,
( F_89 () + V_174 -> V_176 * V_177 ) ) ;
F_6 ( & V_15 -> V_155 ) ;
}
void F_82 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_173 * V_174 = F_87 ( V_25 ) ;
F_8 ( & V_15 -> V_155 ) ;
if ( V_15 -> V_156 & V_159 ) {
F_6 ( & V_15 -> V_155 ) ;
return;
}
F_90 ( & V_15 -> V_175 ) ;
V_15 -> V_175 . V_178 =
( F_89 () + V_174 -> V_176 * V_177 ) ;
V_15 -> V_175 . V_154 = ( unsigned long ) V_15 ;
V_15 -> V_175 . V_179 = F_83 ;
V_15 -> V_156 &= ~ V_157 ;
V_15 -> V_156 |= V_159 ;
F_91 ( & V_15 -> V_175 ) ;
F_25 ( L_35
L_36 , V_15 -> V_79 , V_174 -> V_176 ) ;
F_6 ( & V_15 -> V_155 ) ;
}
void F_92 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_155 ) ;
if ( ! ( V_15 -> V_156 & V_159 ) ) {
F_6 ( & V_15 -> V_155 ) ;
return;
}
V_15 -> V_156 |= V_157 ;
F_6 ( & V_15 -> V_155 ) ;
F_93 ( & V_15 -> V_175 ) ;
F_8 ( & V_15 -> V_155 ) ;
V_15 -> V_156 &= ~ V_159 ;
F_6 ( & V_15 -> V_155 ) ;
}
static void F_94 ( unsigned long V_154 )
{
struct V_21 * V_15 = (struct V_21 * ) V_154 ;
F_76 ( V_15 ) ;
F_8 ( & V_15 -> V_155 ) ;
if ( V_15 -> V_180 & V_157 ) {
F_6 ( & V_15 -> V_155 ) ;
F_79 ( V_15 ) ;
return;
}
V_15 -> V_180 &= ~ V_159 ;
F_6 ( & V_15 -> V_155 ) ;
F_80 ( V_15 , 1 ) ;
F_79 ( V_15 ) ;
}
void F_95 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_173 * V_174 = F_87 ( V_25 ) ;
if ( ! V_174 -> V_181 )
return;
if ( V_15 -> V_180 & V_159 )
return;
F_90 ( & V_15 -> V_182 ) ;
V_15 -> V_182 . V_178 = ( F_89 () + V_174 -> V_181 * V_177 ) ;
V_15 -> V_182 . V_154 = ( unsigned long ) V_15 ;
V_15 -> V_182 . V_179 = F_94 ;
V_15 -> V_180 &= ~ V_157 ;
V_15 -> V_180 |= V_159 ;
F_91 ( & V_15 -> V_182 ) ;
F_25 ( L_37
L_38 , V_15 -> V_79 , V_174 -> V_181 ) ;
}
void F_96 ( struct V_21 * V_15 )
{
struct V_46 * V_25 = V_15 -> V_25 ;
struct V_173 * V_174 = F_87 ( V_25 ) ;
if ( ! V_174 -> V_181 )
return;
F_8 ( & V_15 -> V_155 ) ;
if ( V_15 -> V_180 & V_159 ) {
F_6 ( & V_15 -> V_155 ) ;
return;
}
F_90 ( & V_15 -> V_182 ) ;
V_15 -> V_182 . V_178 = ( F_89 () + V_174 -> V_181 * V_177 ) ;
V_15 -> V_182 . V_154 = ( unsigned long ) V_15 ;
V_15 -> V_182 . V_179 = F_94 ;
V_15 -> V_180 &= ~ V_157 ;
V_15 -> V_180 |= V_159 ;
F_91 ( & V_15 -> V_182 ) ;
F_25 ( L_37
L_38 , V_15 -> V_79 , V_174 -> V_181 ) ;
F_6 ( & V_15 -> V_155 ) ;
}
void F_97 ( struct V_21 * V_15 )
{
F_8 ( & V_15 -> V_155 ) ;
if ( ! ( V_15 -> V_180 & V_159 ) ) {
F_6 ( & V_15 -> V_155 ) ;
return;
}
V_15 -> V_180 |= V_157 ;
F_6 ( & V_15 -> V_155 ) ;
F_93 ( & V_15 -> V_182 ) ;
F_8 ( & V_15 -> V_155 ) ;
V_15 -> V_180 &= ~ V_159 ;
F_6 ( & V_15 -> V_155 ) ;
}
int F_98 (
struct V_1 * V_2 ,
struct V_21 * V_15 ,
int V_183 )
{
int V_184 , V_185 ;
T_1 V_186 ;
struct V_187 * V_188 ;
V_189:
V_185 = V_2 -> V_185 ;
if ( ! V_183 ) {
V_188 = & V_2 -> V_107 [ 0 ] ;
V_186 = V_2 -> V_190 ;
} else {
V_188 = & V_2 -> V_191 [ 0 ] ;
V_186 = V_2 -> V_192 ;
}
V_184 = F_99 ( V_15 , & V_188 [ 0 ] , V_186 , V_185 ) ;
if ( V_185 != V_184 ) {
if ( V_184 == - V_193 ) {
F_3 ( L_39 ) ;
goto V_189;
} else
return - 1 ;
}
V_2 -> V_185 = 0 ;
return 0 ;
}
int F_100 (
struct V_1 * V_2 ,
struct V_21 * V_15 )
{
struct V_194 * V_195 = V_2 -> V_196 ;
struct V_187 V_188 ;
T_1 V_197 , V_198 ;
T_1 V_3 = V_2 -> V_199 ;
int V_184 , V_200 ;
V_201:
V_197 = V_133 ;
if ( V_15 -> V_129 -> V_202 )
V_197 += V_203 ;
V_188 . V_204 = V_2 -> V_205 ;
V_188 . V_206 = V_197 ;
V_184 = F_99 ( V_15 , & V_188 , 1 , V_197 ) ;
if ( V_197 != V_184 ) {
if ( V_184 == - V_193 ) {
F_3 ( L_39 ) ;
goto V_201;
}
return - 1 ;
}
V_198 = V_2 -> V_185 - V_197 - V_2 -> V_207 ;
if ( V_15 -> V_129 -> V_208 ) {
V_198 -= V_203 ;
if ( V_2 -> V_207 )
V_200 = ( V_2 -> V_190 - 2 ) ;
else
V_200 = ( V_2 -> V_190 - 1 ) ;
} else {
V_200 = ( V_2 -> V_190 - 1 ) ;
}
while ( V_198 ) {
T_1 V_209 = ( V_195 -> V_17 - V_3 ) ;
T_1 V_210 = F_101 ( T_1 , V_198 , V_209 ) ;
V_211:
V_184 = V_15 -> V_212 -> V_213 -> V_214 ( V_15 -> V_212 ,
F_102 ( V_195 ) , V_195 -> V_3 + V_3 , V_210 , 0 ) ;
if ( V_184 != V_210 ) {
if ( V_184 == - V_193 ) {
F_3 ( L_40
L_41 ) ;
goto V_211;
}
F_3 ( L_42 ,
V_184 ) ;
return - 1 ;
}
V_198 -= V_210 ;
V_3 = 0 ;
V_195 = F_103 ( V_195 ) ;
}
V_215:
if ( V_2 -> V_207 ) {
struct V_187 * V_216 = & V_2 -> V_107 [ V_200 ++ ] ;
V_184 = F_99 ( V_15 , V_216 , 1 , V_2 -> V_207 ) ;
if ( V_2 -> V_207 != V_184 ) {
if ( V_184 == - V_193 ) {
F_3 ( L_39 ) ;
goto V_215;
}
return - 1 ;
}
}
V_217:
if ( V_15 -> V_129 -> V_208 ) {
struct V_187 * V_218 = & V_2 -> V_107 [ V_200 ] ;
V_184 = F_99 ( V_15 , V_218 , 1 , V_203 ) ;
if ( V_203 != V_184 ) {
if ( V_184 == - V_193 ) {
F_3 ( L_39 ) ;
goto V_217;
}
return - 1 ;
}
}
return 0 ;
}
int F_104 ( struct V_21 * V_15 , T_3 V_219 , T_3 V_220 )
{
struct V_221 * V_66 ;
struct V_222 * V_223 = V_15 -> V_224 ;
V_223 -> V_225 = 1 ;
F_105 ( V_15 , V_219 , V_220 ) ;
memset ( & V_223 -> V_226 [ 0 ] , 0 , V_133 ) ;
V_66 = (struct V_221 * ) & V_223 -> V_226 [ 0 ] ;
V_66 -> V_227 = V_228 ;
V_66 -> V_219 = V_219 ;
V_66 -> V_220 = V_220 ;
V_66 -> V_229 = V_15 -> V_230 ;
return V_15 -> V_29 -> V_231 ( V_15 , V_223 , 0 ) ;
}
void F_106 ( struct V_46 * V_25 )
{
struct V_21 * V_15 ;
F_25 ( L_43
L_44 , V_25 -> V_158 ) ;
F_8 ( & V_25 -> V_138 ) ;
F_10 (conn, &sess->sess_conn_list, conn_list)
F_107 ( V_15 -> V_129 ) ;
F_6 ( & V_25 -> V_138 ) ;
F_108 ( V_25 -> V_69 ) ;
}
static int F_109 (
struct V_21 * V_15 ,
struct V_232 * V_233 )
{
int V_154 = V_233 -> V_77 , V_234 = 0 , V_235 = 0 ;
struct V_236 V_237 ;
if ( ! V_15 || ! V_15 -> V_212 || ! V_15 -> V_129 )
return - 1 ;
memset ( & V_237 , 0 , sizeof( struct V_236 ) ) ;
F_110 ( & V_237 . V_238 , V_239 | V_240 ,
V_233 -> V_188 , V_233 -> V_186 , V_154 ) ;
while ( V_235 < V_154 ) {
V_234 = F_111 ( V_15 -> V_212 , & V_237 ,
( V_154 - V_235 ) , V_241 ) ;
if ( V_234 <= 0 ) {
F_25 ( L_45 ,
V_234 , V_235 ) ;
return V_234 ;
}
V_235 += V_234 ;
F_25 ( L_46 ,
V_234 , V_235 , V_154 ) ;
}
return V_235 ;
}
static int F_112 (
struct V_21 * V_15 ,
struct V_232 * V_233 )
{
int V_48 , V_206 ;
struct V_187 * V_216 ;
struct V_236 V_237 ;
if ( ! V_15 || ! V_15 -> V_212 || ! V_15 -> V_129 )
return - 1 ;
if ( V_233 -> V_77 <= 0 ) {
F_3 ( L_47 , V_233 -> V_77 ) ;
return - 1 ;
}
memset ( & V_237 , 0 , sizeof( struct V_236 ) ) ;
V_216 = V_233 -> V_188 ;
V_206 = V_233 -> V_186 ;
V_48 = F_113 ( V_15 -> V_212 , & V_237 , V_216 , V_206 ,
V_233 -> V_77 ) ;
if ( V_48 != V_233 -> V_77 ) {
F_3 ( L_48 ,
V_48 , V_233 -> V_77 ) ;
return - V_242 ;
}
F_25 ( L_49 , V_48 , V_233 -> V_77 ) ;
return V_48 ;
}
int F_114 (
struct V_21 * V_15 ,
struct V_187 * V_188 ,
int V_186 ,
int V_154 )
{
struct V_232 V_243 ;
if ( ! V_15 || ! V_15 -> V_212 || ! V_15 -> V_129 )
return - 1 ;
memset ( & V_243 , 0 , sizeof( struct V_232 ) ) ;
V_243 . V_188 = V_188 ;
V_243 . V_186 = V_186 ;
V_243 . V_77 = V_154 ;
V_243 . type = V_244 ;
return F_109 ( V_15 , & V_243 ) ;
}
int F_99 (
struct V_21 * V_15 ,
struct V_187 * V_188 ,
int V_186 ,
int V_154 )
{
struct V_232 V_243 ;
if ( ! V_15 || ! V_15 -> V_212 || ! V_15 -> V_129 )
return - 1 ;
memset ( & V_243 , 0 , sizeof( struct V_232 ) ) ;
V_243 . V_188 = V_188 ;
V_243 . V_186 = V_186 ;
V_243 . V_77 = V_154 ;
V_243 . type = V_245 ;
return F_112 ( V_15 , & V_243 ) ;
}
void F_105 (
struct V_21 * V_15 ,
T_3 V_219 ,
T_3 V_220 )
{
struct V_246 * V_247 = NULL ;
struct V_162 * V_163 ;
struct V_248 * V_249 ;
V_163 = F_115 ( V_15 ) ;
if ( ! V_163 )
return;
V_249 = & V_163 -> V_250 ;
F_43 ( & V_249 -> V_166 ) ;
if ( ! strcmp ( V_15 -> V_251 , V_249 -> V_252 ) &&
( ( F_89 () - V_249 -> V_253 ) < 10 ) ) {
F_44 ( & V_249 -> V_166 ) ;
return;
}
if ( V_219 == V_254 )
V_249 -> V_255 ++ ;
else if ( V_219 == V_256 ) {
V_249 -> V_257 ++ ;
V_249 -> V_258 = V_259 ;
} else if ( ( V_219 == V_260 ) &&
( V_220 == V_261 ) ) {
V_249 -> V_262 ++ ;
V_249 -> V_258 = V_263 ;
} else if ( ( V_219 == V_260 ) &&
( V_220 == V_264 ) ) {
V_249 -> V_265 ++ ;
V_249 -> V_258 = V_266 ;
} else if ( ( V_219 == V_260 ) &&
( V_220 == V_267 ) ) {
V_249 -> V_268 ++ ;
V_249 -> V_258 = V_269 ;
} else {
V_249 -> V_270 ++ ;
V_249 -> V_258 = V_271 ;
}
if ( V_219 != V_254 ) {
if ( V_15 -> V_272 )
V_247 = F_116 ( V_273 ,
V_15 -> V_272 ) ;
F_117 ( V_249 -> V_274 ,
( V_247 ? V_247 -> V_275 : L_50 ) ,
sizeof( V_249 -> V_274 ) ) ;
V_249 -> V_276 = V_15 -> V_277 ;
snprintf ( V_249 -> V_252 , V_278 ,
L_51 , V_15 -> V_251 ) ;
V_249 -> V_253 = F_89 () ;
}
F_44 ( & V_249 -> V_166 ) ;
}
struct V_162 * F_115 ( struct V_21 * V_15 )
{
struct V_160 * V_161 ;
if ( ! V_15 || ! V_15 -> V_25 )
return NULL ;
V_161 = V_15 -> V_25 -> V_161 ;
if ( ! V_161 )
return NULL ;
if ( ! V_161 -> V_164 )
return NULL ;
return V_161 -> V_164 ;
}
