void F_1 (
struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
while ( F_2 ( V_3 ) > V_4 ) {
if ( ( V_2 -> V_7 +
V_6 -> V_9 -> V_10 ) <
V_6 -> V_11 -> V_12 -> V_13 ) {
V_2 -> V_8 +=
V_6 -> V_9 -> V_10 ;
V_2 -> V_7 +=
V_6 -> V_9 -> V_10 ;
} else {
V_2 -> V_8 +=
( V_6 -> V_11 -> V_12 -> V_13 -
V_2 -> V_7 ) ;
V_2 -> V_7 = 0 ;
}
V_4 ++ ;
}
}
void F_3 (
struct V_1 * V_2 )
{
T_2 V_14 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_4 = 0 ;
V_2 -> V_7 = 0 ;
while ( V_2 -> V_14 > V_14 ) {
if ( ( V_14 + V_6 -> V_11 -> V_12 -> V_13 ) <=
V_2 -> V_14 )
V_14 += V_6 -> V_11 -> V_12 -> V_13 ;
else
break;
}
V_2 -> V_14 = V_14 ;
}
static int F_4 (
struct V_15 * V_11 ,
struct V_16 * V_17 )
{
F_5 ( & V_11 -> V_18 ) ;
F_6 ( & V_17 -> V_19 , & V_11 -> V_20 ) ;
F_7 ( & V_11 -> V_18 ) ;
return 0 ;
}
static int F_8 (
struct V_15 * V_11 ,
struct V_16 * V_17 )
{
F_5 ( & V_11 -> V_21 ) ;
F_6 ( & V_17 -> V_19 , & V_11 -> V_22 ) ;
V_11 -> V_23 ++ ;
F_9 ( L_1
L_2 , V_11 -> V_23 , V_11 -> V_24 ) ;
F_7 ( & V_11 -> V_21 ) ;
return 0 ;
}
struct V_16 * F_10 (
struct V_15 * V_11 ,
T_3 V_25 )
{
struct V_16 * V_17 ;
F_5 ( & V_11 -> V_21 ) ;
F_11 (cr, &sess->cr_inactive_list, cr_list) {
if ( V_17 -> V_25 == V_25 ) {
F_7 ( & V_11 -> V_21 ) ;
return V_17 ;
}
}
F_7 ( & V_11 -> V_21 ) ;
return NULL ;
}
void F_12 ( struct V_15 * V_11 )
{
struct V_1 * V_2 , * V_26 ;
struct V_16 * V_17 , * V_27 ;
F_5 ( & V_11 -> V_18 ) ;
F_13 (cr, cr_tmp, &sess->cr_active_list, cr_list) {
F_14 ( & V_17 -> V_19 ) ;
F_7 ( & V_11 -> V_18 ) ;
F_5 ( & V_17 -> V_28 ) ;
F_13 (cmd, cmd_tmp,
&cr->conn_recovery_cmd_list, i_conn_node) {
F_14 ( & V_2 -> V_29 ) ;
V_2 -> V_6 = NULL ;
F_7 ( & V_17 -> V_28 ) ;
F_15 ( V_2 , true ) ;
F_5 ( & V_17 -> V_28 ) ;
}
F_7 ( & V_17 -> V_28 ) ;
F_5 ( & V_11 -> V_18 ) ;
F_16 ( V_17 ) ;
}
F_7 ( & V_11 -> V_18 ) ;
F_5 ( & V_11 -> V_21 ) ;
F_13 (cr, cr_tmp, &sess->cr_inactive_list, cr_list) {
F_14 ( & V_17 -> V_19 ) ;
F_7 ( & V_11 -> V_21 ) ;
F_5 ( & V_17 -> V_28 ) ;
F_13 (cmd, cmd_tmp,
&cr->conn_recovery_cmd_list, i_conn_node) {
F_14 ( & V_2 -> V_29 ) ;
V_2 -> V_6 = NULL ;
F_7 ( & V_17 -> V_28 ) ;
F_15 ( V_2 , true ) ;
F_5 ( & V_17 -> V_28 ) ;
}
F_7 ( & V_17 -> V_28 ) ;
F_5 ( & V_11 -> V_21 ) ;
F_16 ( V_17 ) ;
}
F_7 ( & V_11 -> V_21 ) ;
}
int F_17 (
struct V_16 * V_17 ,
struct V_15 * V_11 )
{
F_5 ( & V_11 -> V_18 ) ;
F_14 ( & V_17 -> V_19 ) ;
V_11 -> V_23 -- ;
F_9 ( L_3
L_2 , V_11 -> V_23 , V_11 -> V_24 ) ;
F_7 ( & V_11 -> V_18 ) ;
F_16 ( V_17 ) ;
return 0 ;
}
static void F_18 (
struct V_16 * V_17 ,
struct V_15 * V_11 )
{
F_5 ( & V_11 -> V_21 ) ;
F_14 ( & V_17 -> V_19 ) ;
F_7 ( & V_11 -> V_21 ) ;
}
int F_19 (
struct V_1 * V_2 ,
struct V_15 * V_11 )
{
struct V_16 * V_17 ;
if ( ! V_2 -> V_17 ) {
F_20 ( L_4
L_5 , V_2 -> V_30 ) ;
F_21 () ;
}
V_17 = V_2 -> V_17 ;
F_14 ( & V_2 -> V_29 ) ;
return -- V_17 -> V_31 ;
}
void F_22 (
struct V_16 * V_17 ,
T_2 V_32 )
{
T_2 V_33 = 0 ;
struct V_1 * V_2 , * V_26 ;
struct V_15 * V_11 = V_17 -> V_11 ;
F_5 ( & V_17 -> V_28 ) ;
F_13 (cmd, cmd_tmp,
&cr->conn_recovery_cmd_list, i_conn_node) {
if ( ( ( V_2 -> V_34 != V_35 ) &&
( V_2 -> V_34 != V_36 ) ) ||
( V_2 -> V_37 >= V_32 ) ) {
continue;
}
V_33 ++ ;
F_9 ( L_6
L_7 , V_2 -> V_30 ,
V_2 -> V_37 , V_17 -> V_25 ) ;
F_19 ( V_2 , V_11 ) ;
F_7 ( & V_17 -> V_28 ) ;
F_15 ( V_2 , true ) ;
F_5 ( & V_17 -> V_28 ) ;
}
F_7 ( & V_17 -> V_28 ) ;
F_9 ( L_8
L_9 ,
V_33 , V_17 -> V_25 , V_32 ) ;
if ( ! V_17 -> V_31 ) {
F_9 ( L_10
L_11 ,
V_17 -> V_25 , V_11 -> V_24 ) ;
F_18 ( V_17 , V_11 ) ;
F_4 ( V_11 , V_17 ) ;
F_9 ( L_12
L_13 , V_17 -> V_25 , V_11 -> V_24 ) ;
F_17 ( V_17 , V_11 ) ;
} else {
F_18 ( V_17 , V_11 ) ;
F_4 ( V_11 , V_17 ) ;
}
}
int F_23 ( struct V_5 * V_6 )
{
T_2 V_33 = 0 ;
struct V_1 * V_2 , * V_26 ;
struct V_38 * V_39 , * V_40 ;
struct V_15 * V_11 = V_6 -> V_11 ;
F_24 ( & V_11 -> V_41 ) ;
F_13 (ooo_cmdsn, ooo_cmdsn_tmp,
&sess->sess_ooo_cmdsn_list, ooo_list) {
if ( V_39 -> V_25 != V_6 -> V_25 )
continue;
V_33 ++ ;
F_9 ( L_14
L_15 ,
V_39 -> V_42 , V_6 -> V_25 ) ;
F_25 ( V_11 , V_39 ) ;
}
F_26 ( & V_11 -> V_41 ) ;
F_27 ( & V_6 -> V_43 ) ;
F_13 (cmd, cmd_tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ! ( V_2 -> V_44 & V_45 ) )
continue;
F_14 ( & V_2 -> V_29 ) ;
F_28 ( & V_6 -> V_43 ) ;
F_15 ( V_2 , true ) ;
F_27 ( & V_6 -> V_43 ) ;
}
F_28 ( & V_6 -> V_43 ) ;
F_9 ( L_16
L_17 , V_33 , V_6 -> V_25 ,
V_11 -> V_46 ) ;
return 0 ;
}
int F_29 ( struct V_5 * V_6 )
{
T_2 V_31 = 0 ;
struct V_1 * V_2 , * V_26 ;
struct V_16 * V_17 ;
V_17 = F_30 ( sizeof( struct V_16 ) , V_47 ) ;
if ( ! V_17 ) {
F_20 ( L_18
L_19 ) ;
return - 1 ;
}
F_31 ( & V_17 -> V_19 ) ;
F_31 ( & V_17 -> V_48 ) ;
F_32 ( & V_17 -> V_28 ) ;
F_27 ( & V_6 -> V_43 ) ;
F_13 (cmd, cmd_tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_2 -> V_49 != V_50 ) &&
( V_2 -> V_49 != V_51 ) ) {
F_9 ( L_20
L_21
L_22 , V_2 -> V_49 ,
V_2 -> V_30 , V_2 -> V_52 , V_6 -> V_25 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_28 ( & V_6 -> V_43 ) ;
F_15 ( V_2 , true ) ;
F_27 ( & V_6 -> V_43 ) ;
continue;
}
if ( ! ( V_2 -> V_44 & V_45 ) && ! V_2 -> V_53 &&
F_33 ( V_2 -> V_52 , V_6 -> V_11 -> V_46 ) ) {
F_14 ( & V_2 -> V_29 ) ;
F_28 ( & V_6 -> V_43 ) ;
F_15 ( V_2 , true ) ;
F_27 ( & V_6 -> V_43 ) ;
continue;
}
V_31 ++ ;
F_9 ( L_23
L_24
L_25 , V_2 -> V_49 ,
V_2 -> V_30 , V_2 -> V_52 , V_2 -> V_37 ,
V_6 -> V_25 ) ;
V_2 -> V_34 = V_2 -> V_54 ;
V_2 -> V_54 = V_55 ;
if ( V_2 -> V_56 == V_57 )
F_34 ( V_2 ) ;
V_2 -> V_11 = V_6 -> V_11 ;
F_14 ( & V_2 -> V_29 ) ;
F_28 ( & V_6 -> V_43 ) ;
F_35 ( V_2 ) ;
F_36 ( & V_2 -> V_58 ) ;
F_5 ( & V_17 -> V_28 ) ;
F_6 ( & V_2 -> V_29 , & V_17 -> V_48 ) ;
F_7 ( & V_17 -> V_28 ) ;
F_27 ( & V_6 -> V_43 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_6 = NULL ;
}
F_28 ( & V_6 -> V_43 ) ;
V_17 -> V_25 = V_6 -> V_25 ;
V_17 -> V_31 = V_31 ;
V_17 -> V_59 = V_6 -> V_9 -> V_10 ;
V_17 -> V_60 = V_6 -> V_9 -> V_61 ;
V_17 -> V_11 = V_6 -> V_11 ;
F_8 ( V_6 -> V_11 , V_17 ) ;
return 0 ;
}
int F_37 ( struct V_5 * V_6 )
{
F_38 ( & V_6 -> V_62 , 1 ) ;
if ( F_39 ( V_6 ) < 0 )
return - 1 ;
return 0 ;
}
