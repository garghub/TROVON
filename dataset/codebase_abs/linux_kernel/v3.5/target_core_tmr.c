int F_1 (
struct V_1 * V_1 ,
void * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_4 ) ;
if ( ! V_6 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
V_1 -> V_8 |= V_9 ;
V_1 -> V_5 = V_6 ;
V_6 -> V_10 = V_1 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
F_4 ( & V_6 -> V_11 ) ;
return 0 ;
}
void F_5 (
struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_14 ;
unsigned long V_15 ;
if ( ! V_13 ) {
F_6 ( V_6 ) ;
return;
}
F_7 ( & V_13 -> V_16 , V_15 ) ;
F_8 ( & V_6 -> V_11 ) ;
F_9 ( & V_13 -> V_16 , V_15 ) ;
F_6 ( V_6 ) ;
}
static void F_10 (
struct V_17 * V_18 ,
struct V_1 * V_19 ,
int V_20 ,
int V_21 )
{
if ( ! V_21 ) {
F_11 ( V_19 , 1 ) ;
return;
}
if ( ( V_18 &&
( V_18 == V_19 -> V_22 -> V_17 ) ) || V_20 )
F_12 ( V_19 ) ;
F_11 ( V_19 , 0 ) ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_1 * V_19 )
{
struct V_25 * V_26 ;
if ( ! V_24 )
return 0 ;
F_14 (reg, list, pr_reg_abort_list) {
if ( V_26 -> V_27 == V_19 -> V_27 )
return 0 ;
}
return 1 ;
}
void F_15 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_28 * V_22 )
{
struct V_1 * V_1 , * V_29 ;
unsigned long V_15 ;
int V_30 ;
F_7 ( & V_22 -> V_31 , V_15 ) ;
F_16 (se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
if ( V_13 != V_1 -> V_32 )
continue;
V_30 = V_1 -> V_33 -> V_34 ( V_1 ) ;
if ( V_6 -> V_35 != V_30 )
continue;
F_17 ( L_2 ,
V_1 -> V_33 -> V_36 () , V_30 ) ;
F_18 ( & V_1 -> V_37 ) ;
if ( V_1 -> V_38 & V_39 ) {
F_17 ( L_3 , V_30 ) ;
F_19 ( & V_1 -> V_37 ) ;
F_9 ( & V_22 -> V_31 , V_15 ) ;
goto V_40;
}
V_1 -> V_38 |= V_41 ;
F_19 ( & V_1 -> V_37 ) ;
F_20 ( & V_1 -> V_42 ) ;
F_21 ( & V_1 -> V_43 ) ;
F_9 ( & V_22 -> V_31 , V_15 ) ;
F_22 ( & V_1 -> V_44 ) ;
F_23 ( V_1 ) ;
F_12 ( V_1 ) ;
if ( V_1 -> V_8 & V_45 )
F_24 ( V_22 , V_1 ) ;
F_24 ( V_22 , V_1 ) ;
F_17 ( L_4
L_5 , V_30 ) ;
V_6 -> V_46 = V_47 ;
return;
}
F_9 ( & V_22 -> V_31 , V_15 ) ;
V_40:
F_17 ( L_6 ,
V_6 -> V_35 ) ;
V_6 -> V_46 = V_48 ;
}
static void F_25 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_23 * V_49 )
{
F_26 ( V_50 ) ;
struct V_5 * V_51 , * V_52 ;
struct V_1 * V_19 ;
unsigned long V_15 ;
F_7 ( & V_13 -> V_16 , V_15 ) ;
F_16 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if ( V_51 == V_6 )
continue;
V_19 = V_51 -> V_10 ;
if ( ! V_19 ) {
F_3 ( L_7 ) ;
continue;
}
if ( F_13 ( V_49 , V_19 ) )
continue;
F_27 ( & V_19 -> V_37 ) ;
if ( ! ( V_19 -> V_38 & V_53 ) ) {
F_28 ( & V_19 -> V_37 ) ;
continue;
}
if ( V_19 -> V_54 == V_55 ) {
F_28 ( & V_19 -> V_37 ) ;
continue;
}
F_28 ( & V_19 -> V_37 ) ;
F_29 ( & V_51 -> V_11 , & V_50 ) ;
}
F_9 ( & V_13 -> V_16 , V_15 ) ;
F_16 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_20 ( & V_51 -> V_11 ) ;
V_19 = V_51 -> V_10 ;
F_30 ( L_8
L_9 ,
( V_49 ) ? L_10 : L_11 , V_51 ,
V_51 -> V_3 , V_51 -> V_46 , V_19 -> V_54 ) ;
F_11 ( V_19 , 1 ) ;
}
}
static void F_31 (
struct V_12 * V_13 ,
struct V_1 * V_56 ,
struct V_17 * V_18 ,
int V_20 ,
struct V_23 * V_49 )
{
F_26 ( V_57 ) ;
struct V_1 * V_19 , * V_58 ;
unsigned long V_15 ;
int V_21 ;
F_7 ( & V_13 -> V_59 , V_15 ) ;
F_16 (cmd, next, &dev->state_list, state_list) {
if ( F_13 ( V_49 , V_19 ) )
continue;
if ( V_56 == V_19 )
continue;
F_29 ( & V_19 -> V_60 , & V_57 ) ;
V_19 -> V_61 = false ;
if ( ! F_32 ( & V_19 -> V_62 ) )
F_33 ( V_19 ) ;
}
F_9 ( & V_13 -> V_59 , V_15 ) ;
while ( ! F_32 ( & V_57 ) ) {
V_19 = F_34 ( V_57 . V_58 , struct V_1 , V_60 ) ;
F_8 ( & V_19 -> V_60 ) ;
F_30 ( L_12
L_13
L_14 ,
( V_49 ) ? L_10 : L_11 , V_19 ,
V_19 -> V_33 -> V_34 ( V_19 ) , 0 ,
V_19 -> V_33 -> V_63 ( V_19 ) , V_19 -> V_54 ,
V_19 -> V_64 [ 0 ] ) ;
F_30 ( L_15
L_16
L_17 ,
V_19 -> V_33 -> V_34 ( V_19 ) , V_19 -> V_27 ,
( V_19 -> V_38 & V_53 ) != 0 ,
( V_19 -> V_38 & V_65 ) != 0 ,
( V_19 -> V_38 & V_66 ) != 0 ) ;
if ( V_19 -> V_54 == V_67 )
F_22 ( & V_19 -> V_44 ) ;
F_7 ( & V_19 -> V_37 , V_15 ) ;
F_35 ( V_19 , & V_15 ) ;
V_21 = F_36 ( & V_19 -> V_68 ) ;
if ( ! ( V_19 -> V_38 & V_53 ) ) {
F_30 ( L_18
L_19 , V_19 ,
V_21 , V_13 ) ;
V_19 -> V_38 |= V_41 ;
F_9 ( & V_19 -> V_37 , V_15 ) ;
F_10 ( V_18 , V_19 , V_20 , V_21 ) ;
continue;
}
F_30 ( L_20
L_21 , V_19 , V_21 , V_13 ) ;
V_19 -> V_38 |= V_41 ;
F_9 ( & V_19 -> V_37 , V_15 ) ;
F_10 ( V_18 , V_19 , V_20 , V_21 ) ;
}
}
static void F_37 (
struct V_12 * V_13 ,
struct V_1 * V_56 ,
struct V_17 * V_18 ,
int V_20 ,
struct V_23 * V_49 )
{
F_26 ( V_69 ) ;
struct V_70 * V_71 = & V_13 -> V_72 ;
struct V_1 * V_19 , * V_73 ;
unsigned long V_15 ;
F_7 ( & V_71 -> V_74 , V_15 ) ;
F_16 (cmd, tcmd, &qobj->qobj_list, se_queue_node) {
if ( F_13 ( V_49 , V_19 ) )
continue;
if ( V_56 == V_19 )
continue;
V_19 -> V_38 &= ~ V_75 ;
F_38 ( & V_71 -> V_76 ) ;
F_29 ( & V_19 -> V_77 , & V_69 ) ;
}
F_9 ( & V_71 -> V_74 , V_15 ) ;
while ( ! F_32 ( & V_69 ) ) {
V_19 = F_34 ( V_69 . V_58 , struct V_1 , V_77 ) ;
F_20 ( & V_19 -> V_77 ) ;
F_30 ( L_22
L_23 , ( V_49 ) ?
L_10 : L_11 , V_19 , V_19 -> V_54 ,
F_36 ( & V_19 -> V_68 ) ) ;
F_10 ( V_18 , V_19 , V_20 ,
F_36 ( & V_19 -> V_68 ) ) ;
}
}
int F_39 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_23 * V_49 ,
struct V_1 * V_56 )
{
struct V_17 * V_18 = NULL ;
struct V_78 * V_79 = NULL ;
int V_20 ;
V_20 = V_13 -> V_80 -> V_81 . V_82 ;
if ( V_6 && V_6 -> V_10 && V_6 -> V_10 -> V_22 ) {
V_18 = V_6 -> V_10 -> V_22 -> V_17 ;
V_79 = V_6 -> V_10 -> V_22 -> V_83 ;
if ( V_18 && V_79 ) {
F_30 ( L_24
L_25 ,
V_79 -> V_84 -> V_36 () ,
V_18 -> V_85 ) ;
}
}
F_30 ( L_26 ,
( V_49 ) ? L_10 : L_27 ,
V_13 -> V_86 -> V_87 , V_20 ) ;
F_25 ( V_13 , V_6 , V_49 ) ;
F_31 ( V_13 , V_56 , V_18 , V_20 ,
V_49 ) ;
F_37 ( V_13 , V_56 , V_18 , V_20 ,
V_49 ) ;
if ( ! V_49 &&
( V_13 -> V_88 & V_89 ) ) {
F_27 ( & V_13 -> V_90 ) ;
V_13 -> V_91 = NULL ;
V_13 -> V_88 &= ~ V_89 ;
F_28 ( & V_13 -> V_90 ) ;
F_30 ( L_28 ) ;
}
F_18 ( & V_13 -> V_92 ) ;
V_13 -> V_93 ++ ;
F_19 ( & V_13 -> V_92 ) ;
F_30 ( L_29 ,
( V_49 ) ? L_10 : L_27 ,
V_13 -> V_86 -> V_87 ) ;
return 0 ;
}
