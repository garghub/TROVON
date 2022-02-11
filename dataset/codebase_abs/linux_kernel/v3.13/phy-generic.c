void F_1 ( void )
{
if ( V_1 )
return;
V_1 = F_2 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_1 ) ) {
F_4 ( L_2 ) ;
V_1 = NULL ;
return;
}
}
void F_5 ( void )
{
F_6 ( V_1 ) ;
V_1 = NULL ;
}
static int F_7 ( struct V_2 * V_3 , int V_4 )
{
return 0 ;
}
static void F_8 ( struct V_5 * V_6 , int V_7 )
{
int V_8 ;
if ( ! F_9 ( V_6 -> V_9 ) )
return;
V_8 = V_7 ;
if ( V_6 -> V_10 )
V_8 = ! V_8 ;
F_10 ( V_6 -> V_9 , V_8 ) ;
if ( ! V_7 )
F_11 ( 10000 , 20000 ) ;
}
int F_12 ( struct V_2 * V_11 )
{
struct V_5 * V_6 = F_13 ( V_11 -> V_12 ) ;
if ( ! F_3 ( V_6 -> V_13 ) ) {
if ( F_14 ( V_6 -> V_13 ) )
F_15 ( V_11 -> V_12 , L_3 ) ;
}
if ( ! F_3 ( V_6 -> V_14 ) )
F_16 ( V_6 -> V_14 ) ;
F_8 ( V_6 , 0 ) ;
return 0 ;
}
void F_17 ( struct V_2 * V_11 )
{
struct V_5 * V_6 = F_13 ( V_11 -> V_12 ) ;
F_8 ( V_6 , 1 ) ;
if ( ! F_3 ( V_6 -> V_14 ) )
F_18 ( V_6 -> V_14 ) ;
if ( ! F_3 ( V_6 -> V_13 ) ) {
if ( F_19 ( V_6 -> V_13 ) )
F_15 ( V_11 -> V_12 , L_4 ) ;
}
}
static int F_20 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( ! V_16 )
return - V_19 ;
if ( ! V_18 ) {
V_16 -> V_18 = NULL ;
return - V_19 ;
}
V_16 -> V_18 = V_18 ;
V_16 -> V_11 -> V_20 = V_21 ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 , struct V_22 * V_23 )
{
if ( ! V_16 )
return - V_19 ;
if ( ! V_23 ) {
V_16 -> V_23 = NULL ;
return - V_19 ;
}
V_16 -> V_23 = V_23 ;
return 0 ;
}
int F_22 ( struct V_24 * V_12 , struct V_5 * V_6 ,
struct V_25 * V_26 )
{
enum V_27 type = V_28 ;
int V_29 ;
T_1 V_30 = 0 ;
bool V_31 = false ;
V_6 -> V_10 = true ;
if ( V_12 -> V_32 ) {
struct V_33 * V_34 = V_12 -> V_32 ;
enum V_35 V_36 = 0 ;
if ( F_23 ( V_34 , L_5 , & V_30 ) )
V_30 = 0 ;
V_31 = F_24 ( V_34 , L_6 ) ;
V_6 -> V_9 = F_25 ( V_34 , L_7 ,
0 , & V_36 ) ;
if ( V_6 -> V_9 == - V_37 )
return - V_37 ;
V_6 -> V_10 = V_36 & V_38 ;
} else if ( V_26 ) {
type = V_26 -> type ;
V_30 = V_26 -> V_30 ;
V_31 = V_26 -> V_31 ;
V_6 -> V_9 = V_26 -> V_9 ;
} else {
V_6 -> V_9 = - 1 ;
}
V_6 -> V_11 . V_16 = F_26 ( V_12 , sizeof( * V_6 -> V_11 . V_16 ) ,
V_39 ) ;
if ( ! V_6 -> V_11 . V_16 )
return - V_40 ;
V_6 -> V_14 = F_27 ( V_12 , L_8 ) ;
if ( F_3 ( V_6 -> V_14 ) ) {
F_28 ( V_12 , L_9 ,
F_29 ( V_6 -> V_14 ) ) ;
}
if ( ! F_3 ( V_6 -> V_14 ) && V_30 ) {
V_29 = F_30 ( V_6 -> V_14 , V_30 ) ;
if ( V_29 ) {
F_15 ( V_12 , L_10 ) ;
return V_29 ;
}
}
V_6 -> V_13 = F_31 ( V_12 , L_11 ) ;
if ( F_3 ( V_6 -> V_13 ) ) {
F_28 ( V_12 , L_12 ,
F_29 ( V_6 -> V_13 ) ) ;
if ( V_31 )
return - V_37 ;
}
if ( F_9 ( V_6 -> V_9 ) ) {
unsigned long V_41 ;
if ( V_6 -> V_10 )
V_41 = V_42 ;
else
V_41 = V_43 ;
V_29 = F_32 ( V_12 , V_6 -> V_9 ,
V_41 , F_33 ( V_12 ) ) ;
if ( V_29 ) {
F_15 ( V_12 , L_13 ,
V_6 -> V_9 ) ;
return V_29 ;
}
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 . V_12 = V_6 -> V_12 ;
V_6 -> V_11 . V_44 = L_14 ;
V_6 -> V_11 . V_45 = F_7 ;
V_6 -> V_11 . V_20 = V_46 ;
V_6 -> V_11 . type = type ;
V_6 -> V_11 . V_16 -> V_11 = & V_6 -> V_11 ;
V_6 -> V_11 . V_16 -> V_47 = F_21 ;
V_6 -> V_11 . V_16 -> V_48 = F_20 ;
F_34 ( & V_6 -> V_11 . V_49 ) ;
return 0 ;
}
static int F_35 ( struct V_50 * V_51 )
{
struct V_24 * V_12 = & V_51 -> V_12 ;
struct V_5 * V_6 ;
int V_29 ;
V_6 = F_26 ( V_12 , sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
V_29 = F_22 ( V_12 , V_6 , F_36 ( & V_51 -> V_12 ) ) ;
if ( V_29 )
return V_29 ;
V_6 -> V_11 . V_52 = F_12 ;
V_6 -> V_11 . V_53 = F_17 ;
V_29 = F_37 ( & V_6 -> V_11 ) ;
if ( V_29 ) {
F_15 ( & V_51 -> V_12 , L_15 ,
V_29 ) ;
return V_29 ;
}
F_38 ( V_51 , V_6 ) ;
return 0 ;
}
static int F_39 ( struct V_50 * V_51 )
{
struct V_5 * V_6 = F_40 ( V_51 ) ;
F_41 ( & V_6 -> V_11 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_54 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_54 ) ;
}
