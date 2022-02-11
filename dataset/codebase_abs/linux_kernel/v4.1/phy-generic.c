struct V_1 * F_1 ( void )
{
return F_2 ( L_1 ,
V_2 , NULL , 0 ) ;
}
void F_3 ( struct V_1 * V_3 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_6 )
{
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_9 )
return;
F_7 ( V_8 -> V_9 , 1 ) ;
F_8 ( 10000 , 20000 ) ;
F_7 ( V_8 -> V_9 , 0 ) ;
}
static void F_9 ( struct V_7 * V_8 , unsigned V_10 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
int V_13 ;
int V_14 ;
if ( ! V_12 )
return;
V_13 = V_8 -> V_15 ;
if ( V_10 ) {
F_10 ( V_12 , 0 , 1000 * V_10 ) ;
if ( ! V_13 ) {
V_14 = F_11 ( V_12 ) ;
if ( V_14 < 0 )
return;
V_8 -> V_15 = 1 ;
}
} else {
if ( V_13 ) {
V_14 = F_12 ( V_12 ) ;
if ( V_14 < 0 )
return;
V_8 -> V_15 = 0 ;
}
}
V_8 -> V_10 = V_10 ;
}
static T_1 F_13 ( int V_16 , void * V_17 )
{
struct V_7 * V_8 = V_17 ;
struct V_18 * V_19 = V_8 -> V_20 . V_19 ;
int V_21 , V_22 ;
V_21 = F_14 ( V_8 -> V_23 ) ;
if ( ( V_21 ^ V_8 -> V_21 ) == 0 )
return V_24 ;
V_8 -> V_21 = V_21 ;
if ( V_21 ) {
V_22 = V_25 ;
V_19 -> V_26 = V_27 ;
V_8 -> V_20 . V_28 = V_22 ;
F_15 ( V_19 -> V_29 ) ;
F_9 ( V_8 , 100 ) ;
F_16 ( & V_8 -> V_20 . V_30 , V_22 ,
V_19 -> V_29 ) ;
} else {
F_9 ( V_8 , 0 ) ;
F_17 ( V_19 -> V_29 ) ;
V_22 = V_31 ;
V_19 -> V_26 = V_32 ;
V_8 -> V_20 . V_28 = V_22 ;
F_16 ( & V_8 -> V_20 . V_30 , V_22 ,
V_19 -> V_29 ) ;
}
return V_24 ;
}
int F_18 ( struct V_4 * V_20 )
{
struct V_7 * V_8 = F_19 ( V_20 -> V_33 ) ;
if ( ! F_20 ( V_8 -> V_34 ) ) {
if ( F_11 ( V_8 -> V_34 ) )
F_21 ( V_20 -> V_33 , L_2 ) ;
}
if ( ! F_20 ( V_8 -> V_35 ) )
F_22 ( V_8 -> V_35 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
void F_23 ( struct V_4 * V_20 )
{
struct V_7 * V_8 = F_19 ( V_20 -> V_33 ) ;
F_7 ( V_8 -> V_9 , 1 ) ;
if ( ! F_20 ( V_8 -> V_35 ) )
F_24 ( V_8 -> V_35 ) ;
if ( ! F_20 ( V_8 -> V_34 ) ) {
if ( F_12 ( V_8 -> V_34 ) )
F_21 ( V_20 -> V_33 , L_3 ) ;
}
}
static int F_25 ( struct V_18 * V_19 , struct V_36 * V_29 )
{
if ( ! V_19 )
return - V_37 ;
if ( ! V_29 ) {
V_19 -> V_29 = NULL ;
return - V_37 ;
}
V_19 -> V_29 = V_29 ;
V_19 -> V_26 = V_32 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , struct V_38 * V_39 )
{
if ( ! V_19 )
return - V_37 ;
if ( ! V_39 ) {
V_19 -> V_39 = NULL ;
return - V_37 ;
}
V_19 -> V_39 = V_39 ;
return 0 ;
}
int F_27 ( struct V_40 * V_33 , struct V_7 * V_8 ,
struct V_41 * V_42 )
{
enum V_43 type = V_44 ;
int V_45 = 0 ;
T_2 V_46 = 0 ;
bool V_47 = false ;
if ( V_33 -> V_48 ) {
struct V_49 * V_50 = V_33 -> V_48 ;
if ( F_28 ( V_50 , L_4 , & V_46 ) )
V_46 = 0 ;
V_47 = F_29 ( V_50 , L_5 ) ;
V_8 -> V_9 = F_30 ( V_33 , L_6 ) ;
V_45 = F_31 ( V_8 -> V_9 ) ;
if ( ! V_45 ) {
V_8 -> V_23 = F_30 ( V_33 ,
L_7 ) ;
V_45 = F_31 ( V_8 -> V_23 ) ;
}
} else if ( V_42 ) {
type = V_42 -> type ;
V_46 = V_42 -> V_46 ;
V_47 = V_42 -> V_47 ;
if ( F_32 ( V_42 -> V_51 ) ) {
V_45 = F_33 ( V_33 , V_42 -> V_51 , 0 ,
F_34 ( V_33 ) ) ;
if ( ! V_45 )
V_8 -> V_9 =
F_35 ( V_42 -> V_51 ) ;
}
V_8 -> V_23 = V_42 -> V_23 ;
}
if ( V_45 == - V_52 )
return - V_52 ;
if ( V_45 ) {
F_21 ( V_33 , L_8 ) ;
return V_45 ;
}
if ( V_8 -> V_9 )
F_36 ( V_8 -> V_9 , 1 ) ;
V_8 -> V_20 . V_19 = F_37 ( V_33 , sizeof( * V_8 -> V_20 . V_19 ) ,
V_53 ) ;
if ( ! V_8 -> V_20 . V_19 )
return - V_54 ;
V_8 -> V_35 = F_38 ( V_33 , L_9 ) ;
if ( F_20 ( V_8 -> V_35 ) ) {
F_39 ( V_33 , L_10 ,
F_40 ( V_8 -> V_35 ) ) ;
}
if ( ! F_20 ( V_8 -> V_35 ) && V_46 ) {
V_45 = F_41 ( V_8 -> V_35 , V_46 ) ;
if ( V_45 ) {
F_21 ( V_33 , L_11 ) ;
return V_45 ;
}
}
V_8 -> V_34 = F_42 ( V_33 , L_12 ) ;
if ( F_20 ( V_8 -> V_34 ) ) {
F_39 ( V_33 , L_13 ,
F_40 ( V_8 -> V_34 ) ) ;
if ( V_47 )
return - V_52 ;
}
V_8 -> V_33 = V_33 ;
V_8 -> V_20 . V_33 = V_8 -> V_33 ;
V_8 -> V_20 . V_55 = L_14 ;
V_8 -> V_20 . V_56 = F_5 ;
V_8 -> V_20 . type = type ;
V_8 -> V_20 . V_19 -> V_26 = V_57 ;
V_8 -> V_20 . V_19 -> V_4 = & V_8 -> V_20 ;
V_8 -> V_20 . V_19 -> V_58 = F_26 ;
V_8 -> V_20 . V_19 -> V_59 = F_25 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_3 )
{
struct V_40 * V_33 = & V_3 -> V_33 ;
struct V_7 * V_8 ;
int V_45 ;
V_8 = F_37 ( V_33 , sizeof( * V_8 ) , V_53 ) ;
if ( ! V_8 )
return - V_54 ;
V_45 = F_27 ( V_33 , V_8 , F_44 ( & V_3 -> V_33 ) ) ;
if ( V_45 )
return V_45 ;
if ( V_8 -> V_23 ) {
V_45 = F_45 ( & V_3 -> V_33 ,
F_46 ( V_8 -> V_23 ) ,
NULL , F_13 ,
V_60 , L_15 ,
V_8 ) ;
if ( V_45 ) {
F_21 ( & V_3 -> V_33 , L_16 ,
F_46 ( V_8 -> V_23 ) , V_45 ) ;
return V_45 ;
}
}
V_8 -> V_20 . V_61 = F_18 ;
V_8 -> V_20 . V_62 = F_23 ;
V_45 = F_47 ( & V_8 -> V_20 ) ;
if ( V_45 ) {
F_21 ( & V_3 -> V_33 , L_17 ,
V_45 ) ;
return V_45 ;
}
F_48 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
F_51 ( & V_8 -> V_20 ) ;
return 0 ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_63 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_63 ) ;
}
