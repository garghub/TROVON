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
void F_5 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_14 ;
unsigned long V_15 ;
if ( V_13 ) {
F_6 ( & V_13 -> V_16 , V_15 ) ;
F_7 ( & V_6 -> V_11 ) ;
F_8 ( & V_13 -> V_16 , V_15 ) ;
}
F_9 ( V_6 ) ;
}
static void F_10 (
struct V_17 * V_18 ,
struct V_1 * V_19 ,
int V_20 )
{
bool remove = true ;
if ( ( V_18 && ( V_18 != V_19 -> V_21 -> V_17 ) ) && V_20 ) {
remove = false ;
F_11 ( V_19 ) ;
}
F_12 ( V_19 , remove ) ;
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
struct V_1 * V_1 ;
unsigned long V_15 ;
T_3 V_28 ;
F_6 ( & V_21 -> V_29 , V_15 ) ;
F_14 (se_cmd, &se_sess->sess_cmd_list, se_cmd_list) {
if ( V_13 != V_1 -> V_30 )
continue;
if ( V_1 -> V_8 & V_9 )
continue;
V_28 = V_1 -> V_31 ;
if ( V_6 -> V_32 != V_28 )
continue;
if ( ! F_16 ( & V_1 -> V_33 ) )
continue;
F_17 ( L_2 ,
V_1 -> V_34 -> V_35 () , V_28 ) ;
F_18 ( & V_1 -> V_36 ) ;
if ( V_1 -> V_37 & V_38 ) {
F_17 ( L_3
L_4 , V_28 ) ;
F_19 ( & V_1 -> V_36 ) ;
F_8 ( & V_21 -> V_29 , V_15 ) ;
F_20 ( V_1 ) ;
goto V_39;
}
V_1 -> V_37 |= V_40 ;
F_19 ( & V_1 -> V_36 ) ;
F_21 ( & V_1 -> V_41 ) ;
F_8 ( & V_21 -> V_29 , V_15 ) ;
F_22 ( & V_1 -> V_42 ) ;
F_23 ( V_1 ) ;
F_20 ( V_1 ) ;
F_12 ( V_1 , true ) ;
F_17 ( L_5
L_6 , V_28 ) ;
V_6 -> V_43 = V_44 ;
return;
}
F_8 ( & V_21 -> V_29 , V_15 ) ;
V_39:
F_17 ( L_7 ,
V_6 -> V_32 ) ;
V_6 -> V_43 = V_45 ;
}
static void F_24 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_22 * V_46 )
{
F_25 ( V_47 ) ;
struct V_5 * V_48 , * V_49 ;
struct V_1 * V_19 ;
unsigned long V_15 ;
F_6 ( & V_13 -> V_16 , V_15 ) ;
F_26 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if ( V_48 == V_6 )
continue;
V_19 = V_48 -> V_10 ;
if ( ! V_19 ) {
F_3 ( L_8 ) ;
continue;
}
if ( F_13 ( V_46 , V_19 ) )
continue;
F_18 ( & V_19 -> V_36 ) ;
if ( ! ( V_19 -> V_37 & V_50 ) ) {
F_19 ( & V_19 -> V_36 ) ;
continue;
}
if ( V_19 -> V_51 == V_52 ) {
F_19 ( & V_19 -> V_36 ) ;
continue;
}
F_19 ( & V_19 -> V_36 ) ;
F_27 ( & V_48 -> V_11 , & V_47 ) ;
}
F_8 ( & V_13 -> V_16 , V_15 ) ;
F_26 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_21 ( & V_48 -> V_11 ) ;
V_19 = V_48 -> V_10 ;
F_28 ( L_9
L_10 ,
( V_46 ) ? L_11 : L_12 , V_48 ,
V_48 -> V_3 , V_48 -> V_43 , V_19 -> V_51 ) ;
F_12 ( V_19 , 1 ) ;
}
}
static void F_29 (
struct V_12 * V_13 ,
struct V_1 * V_53 ,
struct V_17 * V_18 ,
int V_20 ,
struct V_22 * V_46 )
{
F_25 ( V_54 ) ;
struct V_1 * V_19 , * V_55 ;
unsigned long V_15 ;
F_6 ( & V_13 -> V_56 , V_15 ) ;
F_26 (cmd, next, &dev->state_list, state_list) {
if ( F_13 ( V_46 , V_19 ) )
continue;
if ( V_53 == V_19 )
continue;
F_27 ( & V_19 -> V_57 , & V_54 ) ;
V_19 -> V_58 = false ;
}
F_8 ( & V_13 -> V_56 , V_15 ) ;
while ( ! F_30 ( & V_54 ) ) {
V_19 = F_31 ( V_54 . V_55 , struct V_1 , V_57 ) ;
F_7 ( & V_19 -> V_57 ) ;
F_28 ( L_13
L_14
L_15 ,
( V_46 ) ? L_11 : L_12 , V_19 ,
V_19 -> V_31 , 0 ,
V_19 -> V_34 -> V_59 ( V_19 ) , V_19 -> V_51 ,
V_19 -> V_60 [ 0 ] ) ;
F_28 ( L_16
L_17
L_18 ,
V_19 -> V_31 , V_19 -> V_26 ,
( V_19 -> V_37 & V_50 ) != 0 ,
( V_19 -> V_37 & V_61 ) != 0 ,
( V_19 -> V_37 & V_62 ) != 0 ) ;
if ( V_19 -> V_51 == V_63 )
F_22 ( & V_19 -> V_42 ) ;
F_6 ( & V_19 -> V_36 , V_15 ) ;
F_32 ( V_19 , & V_15 ) ;
V_19 -> V_37 |= V_40 ;
F_8 ( & V_19 -> V_36 , V_15 ) ;
F_10 ( V_18 , V_19 , V_20 ) ;
}
}
int F_33 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_22 * V_46 ,
struct V_1 * V_53 )
{
struct V_17 * V_18 = NULL ;
struct V_64 * V_65 = NULL ;
int V_20 ;
V_20 = V_13 -> V_66 . V_67 ;
if ( V_6 && V_6 -> V_10 && V_6 -> V_10 -> V_21 ) {
V_18 = V_6 -> V_10 -> V_21 -> V_17 ;
V_65 = V_6 -> V_10 -> V_21 -> V_68 ;
if ( V_18 && V_65 ) {
F_28 ( L_19
L_20 ,
V_65 -> V_69 -> V_35 () ,
V_18 -> V_70 ) ;
}
}
F_28 ( L_21 ,
( V_46 ) ? L_11 : L_22 ,
V_13 -> V_71 -> V_72 , V_20 ) ;
F_24 ( V_13 , V_6 , V_46 ) ;
F_29 ( V_13 , V_53 , V_18 , V_20 ,
V_46 ) ;
if ( ! V_46 &&
( V_13 -> V_73 & V_74 ) ) {
F_18 ( & V_13 -> V_75 ) ;
V_13 -> V_76 = NULL ;
V_13 -> V_73 &= ~ V_74 ;
F_19 ( & V_13 -> V_75 ) ;
F_28 ( L_23 ) ;
}
F_34 ( & V_13 -> V_77 ) ;
F_28 ( L_24 ,
( V_46 ) ? L_11 : L_22 ,
V_13 -> V_71 -> V_72 ) ;
return 0 ;
}
