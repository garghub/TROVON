struct V_1 * F_1 (
struct V_2 * V_2 ,
void * V_3 ,
T_1 V_4 ,
T_2 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_7 , V_5 ) ;
if ( ! V_6 ) {
F_3 ( L_1 ) ;
return F_4 ( - V_8 ) ;
}
V_6 -> V_9 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
F_5 ( & V_6 -> V_10 ) ;
return V_6 ;
}
void F_6 (
struct V_1 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
unsigned long V_14 ;
if ( ! V_12 ) {
F_7 ( V_7 , V_6 ) ;
return;
}
F_8 ( & V_12 -> V_15 , V_14 ) ;
F_9 ( & V_6 -> V_10 ) ;
F_10 ( & V_12 -> V_15 , V_14 ) ;
F_7 ( V_7 , V_6 ) ;
}
static void F_11 (
struct V_16 * V_17 ,
struct V_2 * V_18 ,
int V_19 ,
int V_20 )
{
if ( ! V_20 ) {
F_12 ( V_18 , 1 ) ;
return;
}
if ( ( V_17 &&
( V_17 == V_18 -> V_21 -> V_16 ) ) || V_19 )
F_13 ( V_18 ) ;
F_12 ( V_18 , 0 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
struct V_2 * V_18 )
{
struct V_24 * V_25 ;
if ( ! V_23 )
return 0 ;
F_15 (reg, list, pr_reg_abort_list) {
if ( V_25 -> V_26 == V_18 -> V_26 )
return 0 ;
}
return 1 ;
}
static void F_16 (
struct V_11 * V_12 ,
struct V_1 * V_6 ,
struct V_22 * V_27 )
{
F_17 ( V_28 ) ;
struct V_1 * V_29 , * V_30 ;
struct V_2 * V_18 ;
unsigned long V_14 ;
F_8 ( & V_12 -> V_15 , V_14 ) ;
F_18 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if ( V_29 == V_6 )
continue;
V_18 = V_29 -> V_9 ;
if ( ! V_18 ) {
F_3 ( L_2 ) ;
continue;
}
if ( F_14 ( V_27 , V_18 ) )
continue;
F_19 ( & V_18 -> V_31 ) ;
if ( ! F_20 ( & V_18 -> V_32 ) ) {
F_21 ( & V_18 -> V_31 ) ;
continue;
}
if ( V_18 -> V_33 == V_34 ) {
F_21 ( & V_18 -> V_31 ) ;
continue;
}
F_21 ( & V_18 -> V_31 ) ;
F_22 ( & V_29 -> V_10 , & V_28 ) ;
}
F_10 ( & V_12 -> V_15 , V_14 ) ;
F_18 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_23 ( & V_29 -> V_10 ) ;
V_18 = V_29 -> V_9 ;
F_24 ( L_3
L_4 ,
( V_27 ) ? L_5 : L_6 , V_29 ,
V_29 -> V_4 , V_29 -> V_35 , V_18 -> V_33 ) ;
F_12 ( V_18 , 1 ) ;
}
}
static void F_25 (
struct V_11 * V_12 ,
struct V_2 * V_36 ,
struct V_16 * V_17 ,
int V_19 ,
struct V_22 * V_27 )
{
F_17 ( V_37 ) ;
struct V_2 * V_18 ;
struct V_38 * V_39 , * V_40 ;
unsigned long V_14 ;
int V_20 ;
F_8 ( & V_12 -> V_41 , V_14 ) ;
F_18 (task, task_tmp, &dev->state_task_list,
t_state_list) {
if ( ! V_39 -> V_42 ) {
F_3 ( L_7 ) ;
continue;
}
V_18 = V_39 -> V_42 ;
if ( F_14 ( V_27 , V_18 ) )
continue;
if ( V_36 == V_18 )
continue;
F_22 ( & V_39 -> V_43 , & V_37 ) ;
V_39 -> V_44 = false ;
if ( ! F_26 ( & V_39 -> V_45 ) )
F_27 ( V_39 , V_12 ) ;
}
F_10 ( & V_12 -> V_41 , V_14 ) ;
while ( ! F_26 ( & V_37 ) ) {
V_39 = F_28 ( V_37 . V_46 , struct V_38 , V_43 ) ;
F_9 ( & V_39 -> V_43 ) ;
V_18 = V_39 -> V_42 ;
F_24 ( L_8
L_9
L_10 ,
( V_27 ) ? L_5 : L_6 , V_18 , V_39 ,
V_18 -> V_47 -> V_48 ( V_18 ) , 0 ,
V_18 -> V_47 -> V_49 ( V_18 ) , V_18 -> V_33 ,
V_18 -> V_50 [ 0 ] ) ;
F_24 ( L_11
L_12
L_13
L_14 ,
V_18 -> V_47 -> V_48 ( V_18 ) , V_18 -> V_26 ,
V_18 -> V_51 ,
F_20 ( & V_18 -> V_52 ) ,
F_20 ( & V_18 -> V_53 ) ,
F_20 ( & V_18 -> V_32 ) ,
F_20 ( & V_18 -> V_54 ) ,
F_20 ( & V_18 -> V_55 ) ) ;
if ( V_18 -> V_33 == V_56 )
F_29 ( & V_18 -> V_57 ) ;
F_8 ( & V_18 -> V_31 , V_14 ) ;
F_30 ( V_39 , & V_14 ) ;
if ( ! F_31 ( & V_18 -> V_58 ) ) {
F_10 ( & V_18 -> V_31 , V_14 ) ;
F_24 ( L_15
L_16 , V_39 , V_12 ,
F_20 ( & V_18 -> V_58 ) ) ;
continue;
}
V_20 = F_20 ( & V_18 -> V_59 ) ;
if ( F_20 ( & V_18 -> V_32 ) ) {
F_24 ( L_17
L_18 , V_39 ,
V_20 , V_12 ) ;
F_32 ( & V_18 -> V_60 , 1 ) ;
F_10 ( & V_18 -> V_31 , V_14 ) ;
F_11 ( V_17 , V_18 , V_19 , V_20 ) ;
continue;
}
F_24 ( L_19
L_20 , V_39 , V_20 , V_12 ) ;
F_32 ( & V_18 -> V_60 , 1 ) ;
F_10 ( & V_18 -> V_31 , V_14 ) ;
F_11 ( V_17 , V_18 , V_19 , V_20 ) ;
}
}
static void F_33 (
struct V_11 * V_12 ,
struct V_2 * V_36 ,
struct V_16 * V_17 ,
int V_19 ,
struct V_22 * V_27 )
{
F_17 ( V_61 ) ;
struct V_62 * V_63 = & V_12 -> V_64 ;
struct V_2 * V_18 , * V_65 ;
unsigned long V_14 ;
F_8 ( & V_63 -> V_66 , V_14 ) ;
F_18 (cmd, tcmd, &qobj->qobj_list, se_queue_node) {
if ( F_14 ( V_27 , V_18 ) )
continue;
if ( V_36 == V_18 )
continue;
F_32 ( & V_18 -> V_67 , 0 ) ;
F_34 ( & V_63 -> V_68 ) ;
F_22 ( & V_18 -> V_69 , & V_61 ) ;
}
F_10 ( & V_63 -> V_66 , V_14 ) ;
while ( ! F_26 ( & V_61 ) ) {
V_18 = F_28 ( V_61 . V_46 , struct V_2 , V_69 ) ;
F_23 ( & V_18 -> V_69 ) ;
F_24 ( L_21
L_22 , ( V_27 ) ?
L_5 : L_6 , V_18 , V_18 -> V_33 ,
F_20 ( & V_18 -> V_59 ) ) ;
F_11 ( V_17 , V_18 , V_19 ,
F_20 ( & V_18 -> V_59 ) ) ;
}
}
int F_35 (
struct V_11 * V_12 ,
struct V_1 * V_6 ,
struct V_22 * V_27 ,
struct V_2 * V_36 )
{
struct V_16 * V_17 = NULL ;
struct V_70 * V_71 = NULL ;
int V_19 ;
V_19 = V_12 -> V_72 -> V_73 . V_74 ;
if ( V_6 && V_6 -> V_9 && V_6 -> V_9 -> V_21 ) {
V_17 = V_6 -> V_9 -> V_21 -> V_16 ;
V_71 = V_6 -> V_9 -> V_21 -> V_75 ;
if ( V_17 && V_71 ) {
F_24 ( L_23
L_24 ,
V_71 -> V_76 -> V_77 () ,
V_17 -> V_78 ) ;
}
}
F_24 ( L_25 ,
( V_27 ) ? L_5 : L_26 ,
V_12 -> V_79 -> V_80 , V_19 ) ;
F_16 ( V_12 , V_6 , V_27 ) ;
F_25 ( V_12 , V_36 , V_17 , V_19 ,
V_27 ) ;
F_33 ( V_12 , V_36 , V_17 , V_19 ,
V_27 ) ;
if ( ! V_27 &&
( V_12 -> V_81 & V_82 ) ) {
F_19 ( & V_12 -> V_83 ) ;
V_12 -> V_84 = NULL ;
V_12 -> V_81 &= ~ V_82 ;
F_21 ( & V_12 -> V_83 ) ;
F_24 ( L_27 ) ;
}
F_36 ( & V_12 -> V_85 ) ;
V_12 -> V_86 ++ ;
F_37 ( & V_12 -> V_85 ) ;
F_24 ( L_28 ,
( V_27 ) ? L_5 : L_26 ,
V_12 -> V_79 -> V_80 ) ;
return 0 ;
}
