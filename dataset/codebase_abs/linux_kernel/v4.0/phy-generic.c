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
static void F_6 ( struct V_7 * V_8 , int V_9 )
{
if ( ! V_8 -> V_10 )
return;
F_7 ( V_8 -> V_10 , ! V_9 ) ;
F_8 ( 10000 , 20000 ) ;
F_9 ( V_8 -> V_10 , V_9 ) ;
}
static void F_10 ( struct V_7 * V_8 , unsigned V_11 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
int V_14 ;
int V_15 ;
if ( ! V_13 )
return;
V_14 = V_8 -> V_16 ;
if ( V_11 ) {
F_11 ( V_13 , 0 , 1000 * V_11 ) ;
if ( ! V_14 ) {
V_15 = F_12 ( V_13 ) ;
if ( V_15 < 0 )
return;
V_8 -> V_16 = 1 ;
}
} else {
if ( V_14 ) {
V_15 = F_13 ( V_13 ) ;
if ( V_15 < 0 )
return;
V_8 -> V_16 = 0 ;
}
}
V_8 -> V_11 = V_11 ;
}
static T_1 F_14 ( int V_17 , void * V_18 )
{
struct V_7 * V_8 = V_18 ;
struct V_19 * V_20 = V_8 -> V_21 . V_20 ;
int V_22 , V_23 ;
V_22 = F_15 ( V_8 -> V_24 ) ;
if ( ( V_22 ^ V_8 -> V_22 ) == 0 )
return V_25 ;
V_8 -> V_22 = V_22 ;
if ( V_22 ) {
V_23 = V_26 ;
V_20 -> V_27 = V_28 ;
V_8 -> V_21 . V_29 = V_23 ;
F_16 ( V_20 -> V_30 ) ;
F_10 ( V_8 , 100 ) ;
F_17 ( & V_8 -> V_21 . V_31 , V_23 ,
V_20 -> V_30 ) ;
} else {
F_10 ( V_8 , 0 ) ;
F_18 ( V_20 -> V_30 ) ;
V_23 = V_32 ;
V_20 -> V_27 = V_33 ;
V_8 -> V_21 . V_29 = V_23 ;
F_17 ( & V_8 -> V_21 . V_31 , V_23 ,
V_20 -> V_30 ) ;
}
return V_25 ;
}
int F_19 ( struct V_4 * V_21 )
{
struct V_7 * V_8 = F_20 ( V_21 -> V_34 ) ;
if ( ! F_21 ( V_8 -> V_35 ) ) {
if ( F_12 ( V_8 -> V_35 ) )
F_22 ( V_21 -> V_34 , L_2 ) ;
}
if ( ! F_21 ( V_8 -> V_36 ) )
F_23 ( V_8 -> V_36 ) ;
F_6 ( V_8 , 0 ) ;
return 0 ;
}
void F_24 ( struct V_4 * V_21 )
{
struct V_7 * V_8 = F_20 ( V_21 -> V_34 ) ;
F_6 ( V_8 , 1 ) ;
if ( ! F_21 ( V_8 -> V_36 ) )
F_25 ( V_8 -> V_36 ) ;
if ( ! F_21 ( V_8 -> V_35 ) ) {
if ( F_13 ( V_8 -> V_35 ) )
F_22 ( V_21 -> V_34 , L_3 ) ;
}
}
static int F_26 ( struct V_19 * V_20 , struct V_37 * V_30 )
{
if ( ! V_20 )
return - V_38 ;
if ( ! V_30 ) {
V_20 -> V_30 = NULL ;
return - V_38 ;
}
V_20 -> V_30 = V_30 ;
V_20 -> V_27 = V_33 ;
return 0 ;
}
static int F_27 ( struct V_19 * V_20 , struct V_39 * V_40 )
{
if ( ! V_20 )
return - V_38 ;
if ( ! V_40 ) {
V_20 -> V_40 = NULL ;
return - V_38 ;
}
V_20 -> V_40 = V_40 ;
return 0 ;
}
int F_28 ( struct V_41 * V_34 , struct V_7 * V_8 ,
struct V_42 * V_43 )
{
enum V_44 type = V_45 ;
int V_46 = 0 ;
T_2 V_47 = 0 ;
bool V_48 = false ;
if ( V_34 -> V_49 ) {
struct V_50 * V_51 = V_34 -> V_49 ;
if ( F_29 ( V_51 , L_4 , & V_47 ) )
V_47 = 0 ;
V_48 = F_30 ( V_51 , L_5 ) ;
V_8 -> V_10 = F_31 ( V_34 , L_6 ) ;
V_46 = F_32 ( V_8 -> V_10 ) ;
if ( ! V_46 ) {
V_8 -> V_24 = F_31 ( V_34 ,
L_7 ) ;
V_46 = F_32 ( V_8 -> V_24 ) ;
}
} else if ( V_43 ) {
type = V_43 -> type ;
V_47 = V_43 -> V_47 ;
V_48 = V_43 -> V_48 ;
if ( F_33 ( V_43 -> V_52 ) ) {
V_46 = F_34 ( V_34 , V_43 -> V_52 , 0 ,
F_35 ( V_34 ) ) ;
if ( ! V_46 )
V_8 -> V_10 =
F_36 ( V_43 -> V_52 ) ;
}
V_8 -> V_24 = V_43 -> V_24 ;
}
if ( V_46 == - V_53 )
return - V_53 ;
if ( V_46 ) {
F_22 ( V_34 , L_8 ) ;
return V_46 ;
}
if ( V_8 -> V_10 )
F_7 ( V_8 -> V_10 , 1 ) ;
V_8 -> V_21 . V_20 = F_37 ( V_34 , sizeof( * V_8 -> V_21 . V_20 ) ,
V_54 ) ;
if ( ! V_8 -> V_21 . V_20 )
return - V_55 ;
V_8 -> V_36 = F_38 ( V_34 , L_9 ) ;
if ( F_21 ( V_8 -> V_36 ) ) {
F_39 ( V_34 , L_10 ,
F_40 ( V_8 -> V_36 ) ) ;
}
if ( ! F_21 ( V_8 -> V_36 ) && V_47 ) {
V_46 = F_41 ( V_8 -> V_36 , V_47 ) ;
if ( V_46 ) {
F_22 ( V_34 , L_11 ) ;
return V_46 ;
}
}
V_8 -> V_35 = F_42 ( V_34 , L_12 ) ;
if ( F_21 ( V_8 -> V_35 ) ) {
F_39 ( V_34 , L_13 ,
F_40 ( V_8 -> V_35 ) ) ;
if ( V_48 )
return - V_53 ;
}
V_8 -> V_34 = V_34 ;
V_8 -> V_21 . V_34 = V_8 -> V_34 ;
V_8 -> V_21 . V_56 = L_14 ;
V_8 -> V_21 . V_57 = F_5 ;
V_8 -> V_21 . type = type ;
V_8 -> V_21 . V_20 -> V_27 = V_58 ;
V_8 -> V_21 . V_20 -> V_4 = & V_8 -> V_21 ;
V_8 -> V_21 . V_20 -> V_59 = F_27 ;
V_8 -> V_21 . V_20 -> V_60 = F_26 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_3 )
{
struct V_41 * V_34 = & V_3 -> V_34 ;
struct V_7 * V_8 ;
int V_46 ;
V_8 = F_37 ( V_34 , sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
return - V_55 ;
V_46 = F_28 ( V_34 , V_8 , F_44 ( & V_3 -> V_34 ) ) ;
if ( V_46 )
return V_46 ;
if ( V_8 -> V_24 ) {
V_46 = F_45 ( & V_3 -> V_34 ,
F_46 ( V_8 -> V_24 ) ,
NULL , F_14 ,
V_61 , L_15 ,
V_8 ) ;
if ( V_46 ) {
F_22 ( & V_3 -> V_34 , L_16 ,
F_46 ( V_8 -> V_24 ) , V_46 ) ;
return V_46 ;
}
}
V_8 -> V_21 . V_62 = F_19 ;
V_8 -> V_21 . V_63 = F_24 ;
V_46 = F_47 ( & V_8 -> V_21 ) ;
if ( V_46 ) {
F_22 ( & V_3 -> V_34 , L_17 ,
V_46 ) ;
return V_46 ;
}
F_48 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
F_51 ( & V_8 -> V_21 ) ;
return 0 ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_64 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_64 ) ;
}
