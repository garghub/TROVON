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
int V_20 )
{
if ( ( V_18 &&
( V_18 == V_19 -> V_21 -> V_17 ) ) || V_20 )
F_11 ( V_19 ) ;
F_12 ( V_19 , 0 ) ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_1 * V_19 )
{
struct V_24 * V_25 ;
if ( ! V_23 )
return 0 ;
F_14 (reg, list, pr_reg_abort_list) {
if ( V_25 -> V_26 == V_19 -> V_26 )
return 0 ;
}
return 1 ;
}
void F_15 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_27 * V_21 )
{
struct V_1 * V_1 , * V_28 ;
unsigned long V_15 ;
int V_29 ;
F_7 ( & V_21 -> V_30 , V_15 ) ;
F_16 (se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
if ( V_13 != V_1 -> V_31 )
continue;
V_29 = V_1 -> V_32 -> V_33 ( V_1 ) ;
if ( V_6 -> V_34 != V_29 )
continue;
F_17 ( L_2 ,
V_1 -> V_32 -> V_35 () , V_29 ) ;
F_18 ( & V_1 -> V_36 ) ;
if ( V_1 -> V_37 & V_38 ) {
F_17 ( L_3 , V_29 ) ;
F_19 ( & V_1 -> V_36 ) ;
F_9 ( & V_21 -> V_30 , V_15 ) ;
goto V_39;
}
V_1 -> V_37 |= V_40 ;
F_19 ( & V_1 -> V_36 ) ;
F_20 ( & V_1 -> V_41 ) ;
F_21 ( & V_1 -> V_42 ) ;
F_9 ( & V_21 -> V_30 , V_15 ) ;
F_22 ( & V_1 -> V_43 ) ;
F_23 ( V_1 ) ;
F_11 ( V_1 ) ;
if ( V_1 -> V_8 & V_44 )
F_24 ( V_21 , V_1 ) ;
F_24 ( V_21 , V_1 ) ;
F_17 ( L_4
L_5 , V_29 ) ;
V_6 -> V_45 = V_46 ;
return;
}
F_9 ( & V_21 -> V_30 , V_15 ) ;
V_39:
F_17 ( L_6 ,
V_6 -> V_34 ) ;
V_6 -> V_45 = V_47 ;
}
static void F_25 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_22 * V_48 )
{
F_26 ( V_49 ) ;
struct V_5 * V_50 , * V_51 ;
struct V_1 * V_19 ;
unsigned long V_15 ;
F_7 ( & V_13 -> V_16 , V_15 ) ;
F_16 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if ( V_50 == V_6 )
continue;
V_19 = V_50 -> V_10 ;
if ( ! V_19 ) {
F_3 ( L_7 ) ;
continue;
}
if ( F_13 ( V_48 , V_19 ) )
continue;
F_18 ( & V_19 -> V_36 ) ;
if ( ! ( V_19 -> V_37 & V_52 ) ) {
F_19 ( & V_19 -> V_36 ) ;
continue;
}
if ( V_19 -> V_53 == V_54 ) {
F_19 ( & V_19 -> V_36 ) ;
continue;
}
F_19 ( & V_19 -> V_36 ) ;
F_27 ( & V_50 -> V_11 , & V_49 ) ;
}
F_9 ( & V_13 -> V_16 , V_15 ) ;
F_16 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_20 ( & V_50 -> V_11 ) ;
V_19 = V_50 -> V_10 ;
F_28 ( L_8
L_9 ,
( V_48 ) ? L_10 : L_11 , V_50 ,
V_50 -> V_3 , V_50 -> V_45 , V_19 -> V_53 ) ;
F_12 ( V_19 , 1 ) ;
}
}
static void F_29 (
struct V_12 * V_13 ,
struct V_1 * V_55 ,
struct V_17 * V_18 ,
int V_20 ,
struct V_22 * V_48 )
{
F_26 ( V_56 ) ;
struct V_1 * V_19 , * V_57 ;
unsigned long V_15 ;
F_7 ( & V_13 -> V_58 , V_15 ) ;
F_16 (cmd, next, &dev->state_list, state_list) {
if ( F_13 ( V_48 , V_19 ) )
continue;
if ( V_55 == V_19 )
continue;
F_27 ( & V_19 -> V_59 , & V_56 ) ;
V_19 -> V_60 = false ;
}
F_9 ( & V_13 -> V_58 , V_15 ) ;
while ( ! F_30 ( & V_56 ) ) {
V_19 = F_31 ( V_56 . V_57 , struct V_1 , V_59 ) ;
F_8 ( & V_19 -> V_59 ) ;
F_28 ( L_12
L_13
L_14 ,
( V_48 ) ? L_10 : L_11 , V_19 ,
V_19 -> V_32 -> V_33 ( V_19 ) , 0 ,
V_19 -> V_32 -> V_61 ( V_19 ) , V_19 -> V_53 ,
V_19 -> V_62 [ 0 ] ) ;
F_28 ( L_15
L_16
L_17 ,
V_19 -> V_32 -> V_33 ( V_19 ) , V_19 -> V_26 ,
( V_19 -> V_37 & V_52 ) != 0 ,
( V_19 -> V_37 & V_63 ) != 0 ,
( V_19 -> V_37 & V_64 ) != 0 ) ;
if ( V_19 -> V_53 == V_65 )
F_22 ( & V_19 -> V_43 ) ;
F_7 ( & V_19 -> V_36 , V_15 ) ;
F_32 ( V_19 , & V_15 ) ;
V_19 -> V_37 |= V_40 ;
F_9 ( & V_19 -> V_36 , V_15 ) ;
F_10 ( V_18 , V_19 , V_20 ) ;
}
}
int F_33 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_22 * V_48 ,
struct V_1 * V_55 )
{
struct V_17 * V_18 = NULL ;
struct V_66 * V_67 = NULL ;
int V_20 ;
V_20 = V_13 -> V_68 . V_69 ;
if ( V_6 && V_6 -> V_10 && V_6 -> V_10 -> V_21 ) {
V_18 = V_6 -> V_10 -> V_21 -> V_17 ;
V_67 = V_6 -> V_10 -> V_21 -> V_70 ;
if ( V_18 && V_67 ) {
F_28 ( L_18
L_19 ,
V_67 -> V_71 -> V_35 () ,
V_18 -> V_72 ) ;
}
}
F_28 ( L_20 ,
( V_48 ) ? L_10 : L_21 ,
V_13 -> V_73 -> V_74 , V_20 ) ;
F_25 ( V_13 , V_6 , V_48 ) ;
F_29 ( V_13 , V_55 , V_18 , V_20 ,
V_48 ) ;
if ( ! V_48 &&
( V_13 -> V_75 & V_76 ) ) {
F_18 ( & V_13 -> V_77 ) ;
V_13 -> V_78 = NULL ;
V_13 -> V_75 &= ~ V_76 ;
F_19 ( & V_13 -> V_77 ) ;
F_28 ( L_22 ) ;
}
F_34 ( & V_13 -> V_79 ) ;
V_13 -> V_80 ++ ;
F_35 ( & V_13 -> V_79 ) ;
F_28 ( L_23 ,
( V_48 ) ? L_10 : L_21 ,
V_13 -> V_73 -> V_74 ) ;
return 0 ;
}
