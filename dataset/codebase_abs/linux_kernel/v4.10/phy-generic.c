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
struct V_7 * V_8 = F_6 ( V_5 -> V_9 ) ;
if ( ! F_7 ( V_8 -> V_10 ) ) {
if ( V_6 )
F_8 ( V_8 -> V_10 ) ;
else
F_9 ( V_8 -> V_10 ) ;
}
return 0 ;
}
static void F_10 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_11 )
return;
F_11 ( V_8 -> V_11 , 1 ) ;
F_12 ( 10000 , 20000 ) ;
F_11 ( V_8 -> V_11 , 0 ) ;
}
static void F_13 ( struct V_7 * V_8 , unsigned V_12 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
int V_15 ;
int V_16 ;
if ( ! V_14 )
return;
V_15 = V_8 -> V_17 ;
if ( V_12 ) {
F_14 ( V_14 , 0 , 1000 * V_12 ) ;
if ( ! V_15 ) {
V_16 = F_15 ( V_14 ) ;
if ( V_16 < 0 )
return;
V_8 -> V_17 = 1 ;
}
} else {
if ( V_15 ) {
V_16 = F_16 ( V_14 ) ;
if ( V_16 < 0 )
return;
V_8 -> V_17 = 0 ;
}
}
V_8 -> V_12 = V_12 ;
}
static T_1 F_17 ( int V_18 , void * V_19 )
{
struct V_7 * V_8 = V_19 ;
struct V_20 * V_21 = V_8 -> V_22 . V_21 ;
int V_23 , V_24 ;
V_23 = F_18 ( V_8 -> V_25 ) ;
if ( ( V_23 ^ V_8 -> V_23 ) == 0 )
return V_26 ;
V_8 -> V_23 = V_23 ;
if ( V_23 ) {
V_24 = V_27 ;
V_21 -> V_28 = V_29 ;
V_8 -> V_22 . V_30 = V_24 ;
F_13 ( V_8 , 100 ) ;
F_19 ( & V_8 -> V_22 . V_31 , V_24 ,
V_21 -> V_32 ) ;
} else {
F_13 ( V_8 , 0 ) ;
V_24 = V_33 ;
V_21 -> V_28 = V_34 ;
V_8 -> V_22 . V_30 = V_24 ;
F_19 ( & V_8 -> V_22 . V_31 , V_24 ,
V_21 -> V_32 ) ;
}
return V_26 ;
}
int F_20 ( struct V_4 * V_22 )
{
struct V_7 * V_8 = F_6 ( V_22 -> V_9 ) ;
int V_16 ;
if ( ! F_7 ( V_8 -> V_35 ) ) {
if ( F_15 ( V_8 -> V_35 ) )
F_21 ( V_22 -> V_9 , L_2 ) ;
}
if ( ! F_7 ( V_8 -> V_10 ) ) {
V_16 = F_9 ( V_8 -> V_10 ) ;
if ( V_16 )
return V_16 ;
}
F_10 ( V_8 ) ;
return 0 ;
}
void F_22 ( struct V_4 * V_22 )
{
struct V_7 * V_8 = F_6 ( V_22 -> V_9 ) ;
F_11 ( V_8 -> V_11 , 1 ) ;
if ( ! F_7 ( V_8 -> V_10 ) )
F_8 ( V_8 -> V_10 ) ;
if ( ! F_7 ( V_8 -> V_35 ) ) {
if ( F_16 ( V_8 -> V_35 ) )
F_21 ( V_22 -> V_9 , L_3 ) ;
}
}
static int F_23 ( struct V_20 * V_21 , struct V_36 * V_32 )
{
if ( ! V_21 )
return - V_37 ;
if ( ! V_32 ) {
V_21 -> V_32 = NULL ;
return - V_37 ;
}
V_21 -> V_32 = V_32 ;
if ( V_21 -> V_28 == V_29 )
F_19 ( & V_21 -> V_4 -> V_31 ,
V_27 , V_21 -> V_32 ) ;
else
V_21 -> V_28 = V_34 ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 , struct V_38 * V_39 )
{
if ( ! V_21 )
return - V_37 ;
if ( ! V_39 ) {
V_21 -> V_39 = NULL ;
return - V_37 ;
}
V_21 -> V_39 = V_39 ;
return 0 ;
}
int F_25 ( struct V_40 * V_9 , struct V_7 * V_8 ,
struct V_41 * V_42 )
{
enum V_43 type = V_44 ;
int V_45 = 0 ;
T_2 V_46 = 0 ;
bool V_47 = false ;
if ( V_9 -> V_48 ) {
struct V_49 * V_50 = V_9 -> V_48 ;
if ( F_26 ( V_50 , L_4 , & V_46 ) )
V_46 = 0 ;
V_47 = F_27 ( V_50 , L_5 ) ;
V_8 -> V_11 = F_28 ( V_9 , L_6 ,
V_51 ) ;
V_45 = F_29 ( V_8 -> V_11 ) ;
if ( ! V_45 ) {
V_8 -> V_25 = F_28 ( V_9 ,
L_7 ,
V_51 ) ;
V_45 = F_29 ( V_8 -> V_25 ) ;
}
} else if ( V_42 ) {
type = V_42 -> type ;
V_46 = V_42 -> V_46 ;
V_47 = V_42 -> V_47 ;
if ( F_30 ( V_42 -> V_52 ) ) {
V_45 = F_31 ( V_9 , V_42 -> V_52 ,
V_53 ,
F_32 ( V_9 ) ) ;
if ( ! V_45 )
V_8 -> V_11 =
F_33 ( V_42 -> V_52 ) ;
}
V_8 -> V_25 = V_42 -> V_25 ;
}
if ( V_45 == - V_54 )
return - V_54 ;
if ( V_45 ) {
F_21 ( V_9 , L_8 ) ;
return V_45 ;
}
if ( V_8 -> V_11 )
F_34 ( V_8 -> V_11 , 1 ) ;
V_8 -> V_22 . V_21 = F_35 ( V_9 , sizeof( * V_8 -> V_22 . V_21 ) ,
V_55 ) ;
if ( ! V_8 -> V_22 . V_21 )
return - V_56 ;
V_8 -> V_10 = F_36 ( V_9 , L_9 ) ;
if ( F_7 ( V_8 -> V_10 ) ) {
F_37 ( V_9 , L_10 ,
F_38 ( V_8 -> V_10 ) ) ;
}
if ( ! F_7 ( V_8 -> V_10 ) && V_46 ) {
V_45 = F_39 ( V_8 -> V_10 , V_46 ) ;
if ( V_45 ) {
F_21 ( V_9 , L_11 ) ;
return V_45 ;
}
}
V_8 -> V_35 = F_40 ( V_9 , L_12 ) ;
if ( F_7 ( V_8 -> V_35 ) ) {
F_37 ( V_9 , L_13 ,
F_38 ( V_8 -> V_35 ) ) ;
if ( V_47 )
return - V_54 ;
}
V_8 -> V_9 = V_9 ;
V_8 -> V_22 . V_9 = V_8 -> V_9 ;
V_8 -> V_22 . V_57 = L_14 ;
V_8 -> V_22 . V_58 = F_5 ;
V_8 -> V_22 . type = type ;
V_8 -> V_22 . V_21 -> V_28 = V_59 ;
V_8 -> V_22 . V_21 -> V_4 = & V_8 -> V_22 ;
V_8 -> V_22 . V_21 -> V_60 = F_24 ;
V_8 -> V_22 . V_21 -> V_61 = F_23 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_3 )
{
struct V_40 * V_9 = & V_3 -> V_9 ;
struct V_7 * V_8 ;
int V_45 ;
V_8 = F_35 ( V_9 , sizeof( * V_8 ) , V_55 ) ;
if ( ! V_8 )
return - V_56 ;
V_45 = F_25 ( V_9 , V_8 , F_42 ( & V_3 -> V_9 ) ) ;
if ( V_45 )
return V_45 ;
if ( V_8 -> V_25 ) {
V_45 = F_43 ( & V_3 -> V_9 ,
F_44 ( V_8 -> V_25 ) ,
NULL , F_17 ,
V_62 , L_15 ,
V_8 ) ;
if ( V_45 ) {
F_21 ( & V_3 -> V_9 , L_16 ,
F_44 ( V_8 -> V_25 ) , V_45 ) ;
return V_45 ;
}
V_8 -> V_22 . V_21 -> V_28 = F_18 ( V_8 -> V_25 ) ?
V_29 : V_34 ;
}
V_8 -> V_22 . V_63 = F_20 ;
V_8 -> V_22 . V_64 = F_22 ;
V_45 = F_45 ( & V_8 -> V_22 ) ;
if ( V_45 ) {
F_21 ( & V_3 -> V_9 , L_17 ,
V_45 ) ;
return V_45 ;
}
F_46 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = F_48 ( V_3 ) ;
F_49 ( & V_8 -> V_22 ) ;
return 0 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_65 ) ;
}
static void T_4 F_52 ( void )
{
F_53 ( & V_65 ) ;
}
