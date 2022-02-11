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
static int F_10 ( struct V_1 * V_17 , int V_18 )
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
return F_12 ( V_17 , remove ) ;
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
if ( ! F_15 ( V_1 , V_31 , 0 ) )
continue;
F_7 ( & V_1 -> V_45 ) ;
F_8 ( & V_31 -> V_32 , V_15 ) ;
F_25 ( & V_1 -> V_46 ) ;
F_26 ( V_1 ) ;
if ( ! F_12 ( V_1 , true ) )
F_27 ( V_1 ) ;
F_24 ( L_7
L_8 , V_40 ) ;
V_6 -> V_47 = V_48 ;
F_28 ( & V_13 -> V_49 ) ;
return;
}
F_8 ( & V_31 -> V_32 , V_15 ) ;
F_24 ( L_9 ,
V_6 -> V_42 ) ;
V_6 -> V_47 = V_50 ;
F_28 ( & V_13 -> V_51 ) ;
}
static void F_29 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_23 * V_52 )
{
F_30 ( V_53 ) ;
struct V_28 * V_30 ;
struct V_5 * V_54 , * V_55 ;
struct V_1 * V_17 ;
unsigned long V_15 ;
bool V_56 ;
F_6 ( & V_13 -> V_16 , V_15 ) ;
F_7 ( & V_6 -> V_11 ) ;
F_31 (tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
V_17 = V_54 -> V_10 ;
if ( ! V_17 ) {
F_3 ( L_10 ) ;
continue;
}
if ( F_13 ( V_52 , V_17 ) )
continue;
V_30 = V_17 -> V_31 ;
if ( F_17 ( ! V_30 ) )
continue;
F_19 ( & V_30 -> V_32 ) ;
F_19 ( & V_17 -> V_20 ) ;
if ( ! ( V_17 -> V_21 & V_57 ) ||
( V_17 -> V_21 & V_34 ) ) {
F_21 ( & V_17 -> V_20 ) ;
F_21 ( & V_30 -> V_32 ) ;
continue;
}
if ( V_17 -> V_58 == V_59 ) {
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
V_56 = F_22 ( & V_17 -> V_39 ) ;
if ( ! V_56 ) {
F_24 ( L_11 ) ;
F_21 ( & V_30 -> V_32 ) ;
continue;
}
F_21 ( & V_30 -> V_32 ) ;
F_32 ( & V_54 -> V_11 , & V_53 ) ;
}
F_8 ( & V_13 -> V_16 , V_15 ) ;
F_31 (tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
F_7 ( & V_54 -> V_11 ) ;
V_17 = V_54 -> V_10 ;
F_20 ( L_12
L_13 ,
( V_52 ) ? L_14 : L_15 , V_54 ,
V_54 -> V_3 , V_54 -> V_47 , V_17 -> V_58 ) ;
F_25 ( & V_17 -> V_46 ) ;
F_26 ( V_17 ) ;
if ( ! F_12 ( V_17 , 1 ) )
F_27 ( V_17 ) ;
}
}
static void F_33 (
struct V_12 * V_13 ,
struct V_1 * V_60 ,
struct V_28 * V_29 ,
int V_18 ,
struct V_23 * V_52 )
{
F_30 ( V_61 ) ;
struct V_28 * V_30 ;
struct V_1 * V_17 , * V_62 ;
unsigned long V_15 ;
int V_56 ;
F_6 ( & V_13 -> V_63 , V_15 ) ;
F_31 (cmd, next, &dev->state_list, state_list) {
if ( F_13 ( V_52 , V_17 ) )
continue;
if ( V_60 == V_17 )
continue;
V_30 = V_17 -> V_31 ;
if ( F_17 ( ! V_30 ) )
continue;
F_19 ( & V_30 -> V_32 ) ;
V_56 = F_15 ( V_17 , V_29 , V_18 ) ;
F_21 ( & V_30 -> V_32 ) ;
if ( ! V_56 )
continue;
F_32 ( & V_17 -> V_64 , & V_61 ) ;
V_17 -> V_65 = false ;
}
F_8 ( & V_13 -> V_63 , V_15 ) ;
while ( ! F_34 ( & V_61 ) ) {
V_17 = F_35 ( V_61 . V_62 , struct V_1 , V_64 ) ;
F_7 ( & V_17 -> V_64 ) ;
F_36 ( L_16 , V_17 ) ;
F_20 ( L_17 ,
V_17 -> V_35 , ( V_52 ) ? L_18 : L_15 ,
V_17 -> V_27 ) ;
F_25 ( & V_17 -> V_46 ) ;
F_26 ( V_17 ) ;
if ( ! F_10 ( V_17 , V_18 ) )
F_27 ( V_17 ) ;
}
}
int F_37 (
struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_23 * V_52 ,
struct V_1 * V_60 )
{
struct V_66 * V_67 = NULL ;
struct V_68 * V_69 = NULL ;
struct V_28 * V_29 = NULL ;
int V_18 ;
V_18 = V_13 -> V_70 . V_71 ;
if ( V_6 && V_6 -> V_10 && V_6 -> V_10 -> V_31 ) {
V_29 = V_6 -> V_10 -> V_31 ;
V_67 = V_29 -> V_66 ;
V_69 = V_29 -> V_72 ;
if ( V_67 && V_69 ) {
F_20 ( L_19
L_20 ,
V_69 -> V_73 -> V_44 () ,
V_67 -> V_74 ) ;
}
}
F_20 ( L_21 ,
( V_52 ) ? L_14 : L_22 ,
V_13 -> V_75 -> V_76 , V_18 ) ;
F_29 ( V_13 , V_6 , V_52 ) ;
F_33 ( V_13 , V_60 , V_29 , V_18 ,
V_52 ) ;
if ( ! V_52 &&
( V_13 -> V_77 & V_78 ) ) {
F_19 ( & V_13 -> V_79 ) ;
V_13 -> V_80 = NULL ;
V_13 -> V_77 &= ~ V_78 ;
F_21 ( & V_13 -> V_79 ) ;
F_20 ( L_23 ) ;
}
F_28 ( & V_13 -> V_81 ) ;
F_20 ( L_24 ,
( V_52 ) ? L_14 : L_22 ,
V_13 -> V_75 -> V_76 ) ;
return 0 ;
}
