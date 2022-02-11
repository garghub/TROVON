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
static void F_14 (
struct V_11 * V_12 ,
struct V_1 * V_6 ,
struct V_22 * V_23 )
{
F_15 ( V_24 ) ;
struct V_1 * V_25 , * V_26 ;
struct V_2 * V_18 ;
unsigned long V_14 ;
F_8 ( & V_12 -> V_15 , V_14 ) ;
F_16 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if ( V_25 == V_6 )
continue;
V_18 = V_25 -> V_9 ;
if ( ! V_18 ) {
F_3 ( L_2 ) ;
continue;
}
if ( V_23 &&
( F_17 (
V_23 , V_18 ) != 0 ) )
continue;
F_18 ( & V_18 -> V_27 ) ;
if ( ! F_19 ( & V_18 -> V_28 ) ) {
F_20 ( & V_18 -> V_27 ) ;
continue;
}
if ( V_18 -> V_29 == V_30 ) {
F_20 ( & V_18 -> V_27 ) ;
continue;
}
F_20 ( & V_18 -> V_27 ) ;
F_21 ( & V_25 -> V_10 , & V_24 ) ;
}
F_10 ( & V_12 -> V_15 , V_14 ) ;
F_16 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_22 ( & V_25 -> V_10 ) ;
V_18 = V_25 -> V_9 ;
F_23 ( L_3
L_4 ,
( V_23 ) ? L_5 : L_6 , V_25 ,
V_25 -> V_4 , V_25 -> V_31 , V_18 -> V_29 ) ;
F_12 ( V_18 , 1 ) ;
}
}
static void F_24 (
struct V_11 * V_12 ,
struct V_2 * V_32 ,
struct V_16 * V_17 ,
int V_19 ,
struct V_22 * V_23 )
{
F_15 ( V_33 ) ;
struct V_2 * V_18 ;
struct V_34 * V_35 , * V_36 ;
unsigned long V_14 ;
int V_20 ;
F_8 ( & V_12 -> V_37 , V_14 ) ;
F_16 (task, task_tmp, &dev->state_task_list,
t_state_list) {
if ( ! V_35 -> V_38 ) {
F_3 ( L_7 ) ;
continue;
}
V_18 = V_35 -> V_38 ;
if ( V_23 &&
( F_17 (
V_23 , V_18 ) != 0 ) )
continue;
if ( V_32 == V_18 )
continue;
F_21 ( & V_35 -> V_39 , & V_33 ) ;
F_25 ( & V_35 -> V_40 , 0 ) ;
if ( ! F_26 ( & V_35 -> V_41 ) )
F_27 ( V_35 , V_12 ) ;
}
F_10 ( & V_12 -> V_37 , V_14 ) ;
while ( ! F_26 ( & V_33 ) ) {
V_35 = F_28 ( V_33 . V_42 , struct V_34 , V_39 ) ;
F_9 ( & V_35 -> V_39 ) ;
V_18 = V_35 -> V_38 ;
F_23 ( L_8
L_9
L_10 ,
( V_23 ) ? L_5 : L_6 , V_18 , V_35 ,
V_18 -> V_43 -> V_44 ( V_18 ) , 0 ,
V_18 -> V_43 -> V_45 ( V_18 ) , V_18 -> V_29 ,
V_18 -> V_46 [ 0 ] ) ;
F_23 ( L_11
L_12
L_13
L_14 ,
V_18 -> V_43 -> V_44 ( V_18 ) , V_18 -> V_47 ,
V_18 -> V_48 ,
F_19 ( & V_18 -> V_49 ) ,
F_19 ( & V_18 -> V_50 ) ,
F_19 ( & V_18 -> V_28 ) ,
F_19 ( & V_18 -> V_51 ) ,
F_19 ( & V_18 -> V_52 ) ) ;
if ( V_18 -> V_29 == V_53 )
F_29 ( & V_18 -> V_54 ) ;
F_8 ( & V_18 -> V_27 , V_14 ) ;
F_30 ( V_35 , & V_14 ) ;
if ( ! F_31 ( & V_18 -> V_55 ) ) {
F_10 ( & V_18 -> V_27 , V_14 ) ;
F_23 ( L_15
L_16 , V_35 , V_12 ,
F_19 ( & V_18 -> V_55 ) ) ;
continue;
}
V_20 = F_19 ( & V_18 -> V_56 ) ;
if ( F_19 ( & V_18 -> V_28 ) ) {
F_23 ( L_17
L_18 , V_35 ,
V_20 , V_12 ) ;
F_25 ( & V_18 -> V_57 , 1 ) ;
F_10 ( & V_18 -> V_27 , V_14 ) ;
F_11 ( V_17 , V_18 , V_19 , V_20 ) ;
continue;
}
F_23 ( L_19
L_20 , V_35 , V_20 , V_12 ) ;
F_25 ( & V_18 -> V_57 , 1 ) ;
F_10 ( & V_18 -> V_27 , V_14 ) ;
F_11 ( V_17 , V_18 , V_19 , V_20 ) ;
}
}
static void F_32 (
struct V_11 * V_12 ,
struct V_2 * V_32 ,
struct V_16 * V_17 ,
int V_19 ,
struct V_22 * V_23 )
{
F_15 ( V_58 ) ;
struct V_59 * V_60 = & V_12 -> V_61 ;
struct V_2 * V_18 , * V_62 ;
unsigned long V_14 ;
F_8 ( & V_60 -> V_63 , V_14 ) ;
F_16 (cmd, tcmd, &qobj->qobj_list, se_queue_node) {
if ( V_23 &&
( F_17 (
V_23 , V_18 ) != 0 ) )
continue;
if ( V_32 == V_18 )
continue;
F_25 ( & V_18 -> V_64 , 0 ) ;
F_33 ( & V_60 -> V_65 ) ;
F_21 ( & V_18 -> V_66 , & V_58 ) ;
}
F_10 ( & V_60 -> V_63 , V_14 ) ;
while ( ! F_26 ( & V_58 ) ) {
V_18 = F_28 ( V_58 . V_42 , struct V_2 , V_66 ) ;
F_22 ( & V_18 -> V_66 ) ;
F_23 ( L_21
L_22 , ( V_23 ) ?
L_5 : L_6 , V_18 , V_18 -> V_29 ,
F_19 ( & V_18 -> V_56 ) ) ;
F_11 ( V_17 , V_18 , V_19 ,
F_19 ( & V_18 -> V_56 ) ) ;
}
}
int F_34 (
struct V_11 * V_12 ,
struct V_1 * V_6 ,
struct V_22 * V_23 ,
struct V_2 * V_32 )
{
struct V_16 * V_17 = NULL ;
struct V_67 * V_68 = NULL ;
int V_19 ;
V_19 = V_12 -> V_69 -> V_70 . V_71 ;
if ( V_6 && V_6 -> V_9 && V_6 -> V_9 -> V_21 ) {
V_17 = V_6 -> V_9 -> V_21 -> V_16 ;
V_68 = V_6 -> V_9 -> V_21 -> V_72 ;
if ( V_17 && V_68 ) {
F_23 ( L_23
L_24 ,
V_68 -> V_73 -> V_74 () ,
V_17 -> V_75 ) ;
}
}
F_23 ( L_25 ,
( V_23 ) ? L_5 : L_26 ,
V_12 -> V_76 -> V_77 , V_19 ) ;
F_14 ( V_12 , V_6 , V_23 ) ;
F_24 ( V_12 , V_32 , V_17 , V_19 ,
V_23 ) ;
F_32 ( V_12 , V_32 , V_17 , V_19 ,
V_23 ) ;
if ( ! V_23 &&
( V_12 -> V_78 & V_79 ) ) {
F_18 ( & V_12 -> V_80 ) ;
V_12 -> V_81 = NULL ;
V_12 -> V_78 &= ~ V_79 ;
F_20 ( & V_12 -> V_80 ) ;
F_23 ( L_27 ) ;
}
F_35 ( & V_12 -> V_82 ) ;
V_12 -> V_83 ++ ;
F_36 ( & V_12 -> V_82 ) ;
F_23 ( L_28 ,
( V_23 ) ? L_5 : L_26 ,
V_12 -> V_76 -> V_77 ) ;
return 0 ;
}
