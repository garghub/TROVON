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
static void F_10 ( struct V_1 * V_17 , int V_18 )
{
unsigned long V_15 ;
bool remove = true , V_19 ;
F_6 ( & V_17 -> V_20 , V_15 ) ;
V_19 = ( V_17 -> V_21 & V_22 ) ;
F_8 ( & V_17 -> V_20 , V_15 ) ;
if ( V_19 ) {
remove = false ;
F_11 ( V_17 ) ;
}
F_12 ( V_17 , remove ) ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_1 * V_17 )
{
struct V_25 * V_26 ;
if ( ! V_24 )
return 0 ;
F_14 (reg, list, pr_reg_abort_list) {
if ( V_26 -> V_27 == V_17 -> V_27 )
return 0 ;
}
return 1 ;
}
static bool F_15 ( struct V_1 * V_1 ,
struct V_28 * V_29 , int V_18 )
{
struct V_28 * V_30 = V_1 -> V_31 ;
F_16 ( & V_30 -> V_32 ) ;
F_17 ( ! F_18 () ) ;
F_19 ( & V_1 -> V_20 ) ;
if ( V_1 -> V_21 & ( V_33 | V_34 ) ) {
F_20 ( L_2
L_3 , V_1 -> V_35 ) ;
F_21 ( & V_1 -> V_20 ) ;
return false ;
}
if ( V_30 -> V_36 || V_1 -> V_37 ) {
F_20 ( L_4
L_5 , V_1 -> V_35 ) ;
F_21 ( & V_1 -> V_20 ) ;
return false ;
}
V_1 -> V_21 |= V_38 ;
if ( ( V_29 != V_1 -> V_31 ) && V_18 )
V_1 -> V_21 |= V_22 ;
F_21 ( & V_1 -> V_20 ) ;
return F_22 ( & V_1 -> V_39 ) ;
}
void F_23 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_28 * V_31 )
{
struct V_1 * V_1 ;
unsigned long V_15 ;
T_3 V_40 ;
F_6 ( & V_31 -> V_32 , V_15 ) ;
F_14 (se_cmd, &se_sess->sess_cmd_list, se_cmd_list) {
if ( V_13 != V_1 -> V_41 )
continue;
if ( V_1 -> V_8 & V_9 )
continue;
V_40 = V_1 -> V_35 ;
if ( V_6 -> V_42 != V_40 )
continue;
F_24 ( L_6 ,
V_1 -> V_43 -> V_44 () , V_40 ) ;
if ( ! F_15 ( V_1 , V_31 , 0 ) ) {
F_8 ( & V_31 -> V_32 , V_15 ) ;
goto V_45;
}
F_7 ( & V_1 -> V_46 ) ;
F_8 ( & V_31 -> V_32 , V_15 ) ;
F_25 ( & V_1 -> V_47 ) ;
F_26 ( V_1 ) ;
F_12 ( V_1 , true ) ;
F_27 ( V_1 ) ;
F_24 ( L_7
L_8 , V_40 ) ;
V_6 -> V_48 = V_49 ;
return;
}
F_8 ( & V_31 -> V_32 , V_15 ) ;
V_45:
F_24 ( L_9 ,
V_6 -> V_42 ) ;
V_6 -> V_48 = V_50 ;
}
static void F_28 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_23 * V_51 )
{
F_29 ( V_52 ) ;
struct V_28 * V_30 ;
struct V_5 * V_53 , * V_54 ;
struct V_1 * V_17 ;
unsigned long V_15 ;
bool V_55 ;
F_6 ( & V_13 -> V_16 , V_15 ) ;
F_30 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if ( V_53 == V_6 )
continue;
V_17 = V_53 -> V_10 ;
if ( ! V_17 ) {
F_3 ( L_10 ) ;
continue;
}
if ( F_13 ( V_51 , V_17 ) )
continue;
V_30 = V_17 -> V_31 ;
if ( F_17 ( ! V_30 ) )
continue;
F_19 ( & V_30 -> V_32 ) ;
F_19 ( & V_17 -> V_20 ) ;
if ( ! ( V_17 -> V_21 & V_56 ) ||
( V_17 -> V_21 & V_34 ) ) {
F_21 ( & V_17 -> V_20 ) ;
F_21 ( & V_30 -> V_32 ) ;
continue;
}
if ( V_17 -> V_57 == V_58 ) {
F_21 ( & V_17 -> V_20 ) ;
F_21 ( & V_30 -> V_32 ) ;
continue;
}
if ( V_30 -> V_36 || V_17 -> V_37 ) {
F_21 ( & V_17 -> V_20 ) ;
F_21 ( & V_30 -> V_32 ) ;
continue;
}
V_17 -> V_21 |= V_38 ;
F_21 ( & V_17 -> V_20 ) ;
V_55 = F_22 ( & V_17 -> V_39 ) ;
if ( ! V_55 ) {
F_24 ( L_11 ) ;
F_21 ( & V_30 -> V_32 ) ;
continue;
}
F_21 ( & V_30 -> V_32 ) ;
F_31 ( & V_53 -> V_11 , & V_52 ) ;
}
F_8 ( & V_13 -> V_16 , V_15 ) ;
F_30 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_7 ( & V_53 -> V_11 ) ;
V_17 = V_53 -> V_10 ;
F_20 ( L_12
L_13 ,
( V_51 ) ? L_14 : L_15 , V_53 ,
V_53 -> V_3 , V_53 -> V_48 , V_17 -> V_57 ) ;
F_25 ( & V_17 -> V_47 ) ;
F_26 ( V_17 ) ;
F_12 ( V_17 , 1 ) ;
F_27 ( V_17 ) ;
}
}
static void F_32 (
struct V_12 * V_13 ,
struct V_1 * V_59 ,
struct V_28 * V_29 ,
int V_18 ,
struct V_23 * V_51 )
{
F_29 ( V_60 ) ;
struct V_28 * V_30 ;
struct V_1 * V_17 , * V_61 ;
unsigned long V_15 ;
int V_55 ;
F_6 ( & V_13 -> V_62 , V_15 ) ;
F_30 (cmd, next, &dev->state_list, state_list) {
if ( F_13 ( V_51 , V_17 ) )
continue;
if ( V_59 == V_17 )
continue;
V_30 = V_17 -> V_31 ;
if ( F_17 ( ! V_30 ) )
continue;
F_19 ( & V_30 -> V_32 ) ;
V_55 = F_15 ( V_17 , V_29 , V_18 ) ;
F_21 ( & V_30 -> V_32 ) ;
if ( ! V_55 )
continue;
F_31 ( & V_17 -> V_63 , & V_60 ) ;
V_17 -> V_64 = false ;
}
F_8 ( & V_13 -> V_62 , V_15 ) ;
while ( ! F_33 ( & V_60 ) ) {
V_17 = F_34 ( V_60 . V_61 , struct V_1 , V_63 ) ;
F_7 ( & V_17 -> V_63 ) ;
F_20 ( L_16
L_17
L_18 ,
( V_51 ) ? L_14 : L_15 , V_17 ,
V_17 -> V_35 , 0 ,
V_17 -> V_43 -> V_65 ( V_17 ) , V_17 -> V_57 ,
V_17 -> V_66 [ 0 ] ) ;
F_20 ( L_19
L_20
L_21 ,
V_17 -> V_35 , V_17 -> V_27 ,
( V_17 -> V_21 & V_56 ) != 0 ,
( V_17 -> V_21 & V_67 ) != 0 ,
( V_17 -> V_21 & V_68 ) != 0 ) ;
F_25 ( & V_17 -> V_47 ) ;
F_26 ( V_17 ) ;
F_10 ( V_17 , V_18 ) ;
F_27 ( V_17 ) ;
}
}
int F_35 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_23 * V_51 ,
struct V_1 * V_59 )
{
struct V_69 * V_70 = NULL ;
struct V_71 * V_72 = NULL ;
struct V_28 * V_29 = NULL ;
int V_18 ;
V_18 = V_13 -> V_73 . V_74 ;
if ( V_6 && V_6 -> V_10 && V_6 -> V_10 -> V_31 ) {
V_29 = V_6 -> V_10 -> V_31 ;
V_70 = V_29 -> V_69 ;
V_72 = V_29 -> V_75 ;
if ( V_70 && V_72 ) {
F_20 ( L_22
L_23 ,
V_72 -> V_76 -> V_44 () ,
V_70 -> V_77 ) ;
}
}
F_20 ( L_24 ,
( V_51 ) ? L_14 : L_25 ,
V_13 -> V_78 -> V_79 , V_18 ) ;
F_28 ( V_13 , V_6 , V_51 ) ;
F_32 ( V_13 , V_59 , V_29 , V_18 ,
V_51 ) ;
if ( ! V_51 &&
( V_13 -> V_80 & V_81 ) ) {
F_19 ( & V_13 -> V_82 ) ;
V_13 -> V_83 = NULL ;
V_13 -> V_80 &= ~ V_81 ;
F_21 ( & V_13 -> V_82 ) ;
F_20 ( L_26 ) ;
}
F_36 ( & V_13 -> V_84 ) ;
F_20 ( L_27 ,
( V_51 ) ? L_14 : L_25 ,
V_13 -> V_78 -> V_79 ) ;
return 0 ;
}
