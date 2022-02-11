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
int V_10 ;
if ( ! F_7 ( V_8 -> V_11 ) )
return;
V_10 = V_9 ;
if ( V_8 -> V_12 )
V_10 = ! V_10 ;
F_8 ( V_8 -> V_11 , V_10 ) ;
if ( ! V_9 )
F_9 ( 10000 , 20000 ) ;
}
int F_10 ( struct V_4 * V_13 )
{
struct V_7 * V_8 = F_11 ( V_13 -> V_14 ) ;
if ( ! F_12 ( V_8 -> V_15 ) ) {
if ( F_13 ( V_8 -> V_15 ) )
F_14 ( V_13 -> V_14 , L_2 ) ;
}
if ( ! F_12 ( V_8 -> V_16 ) )
F_15 ( V_8 -> V_16 ) ;
F_6 ( V_8 , 0 ) ;
return 0 ;
}
void F_16 ( struct V_4 * V_13 )
{
struct V_7 * V_8 = F_11 ( V_13 -> V_14 ) ;
F_6 ( V_8 , 1 ) ;
if ( ! F_12 ( V_8 -> V_16 ) )
F_17 ( V_8 -> V_16 ) ;
if ( ! F_12 ( V_8 -> V_15 ) ) {
if ( F_18 ( V_8 -> V_15 ) )
F_14 ( V_13 -> V_14 , L_3 ) ;
}
}
static int F_19 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
if ( ! V_18 )
return - V_21 ;
if ( ! V_20 ) {
V_18 -> V_20 = NULL ;
return - V_21 ;
}
V_18 -> V_20 = V_20 ;
V_18 -> V_13 -> V_22 = V_23 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 , struct V_24 * V_25 )
{
if ( ! V_18 )
return - V_21 ;
if ( ! V_25 ) {
V_18 -> V_25 = NULL ;
return - V_21 ;
}
V_18 -> V_25 = V_25 ;
return 0 ;
}
int F_21 ( struct V_26 * V_14 , struct V_7 * V_8 ,
struct V_27 * V_28 )
{
enum V_29 type = V_30 ;
int V_31 ;
T_1 V_32 = 0 ;
bool V_33 = false ;
V_8 -> V_12 = true ;
if ( V_14 -> V_34 ) {
struct V_35 * V_36 = V_14 -> V_34 ;
enum V_37 V_38 = 0 ;
if ( F_22 ( V_36 , L_4 , & V_32 ) )
V_32 = 0 ;
V_33 = F_23 ( V_36 , L_5 ) ;
V_8 -> V_11 = F_24 ( V_36 , L_6 ,
0 , & V_38 ) ;
if ( V_8 -> V_11 == - V_39 )
return - V_39 ;
V_8 -> V_12 = V_38 & V_40 ;
} else if ( V_28 ) {
type = V_28 -> type ;
V_32 = V_28 -> V_32 ;
V_33 = V_28 -> V_33 ;
V_8 -> V_11 = V_28 -> V_11 ;
} else {
V_8 -> V_11 = - 1 ;
}
V_8 -> V_13 . V_18 = F_25 ( V_14 , sizeof( * V_8 -> V_13 . V_18 ) ,
V_41 ) ;
if ( ! V_8 -> V_13 . V_18 )
return - V_42 ;
V_8 -> V_16 = F_26 ( V_14 , L_7 ) ;
if ( F_12 ( V_8 -> V_16 ) ) {
F_27 ( V_14 , L_8 ,
F_28 ( V_8 -> V_16 ) ) ;
}
if ( ! F_12 ( V_8 -> V_16 ) && V_32 ) {
V_31 = F_29 ( V_8 -> V_16 , V_32 ) ;
if ( V_31 ) {
F_14 ( V_14 , L_9 ) ;
return V_31 ;
}
}
V_8 -> V_15 = F_30 ( V_14 , L_10 ) ;
if ( F_12 ( V_8 -> V_15 ) ) {
F_27 ( V_14 , L_11 ,
F_28 ( V_8 -> V_15 ) ) ;
if ( V_33 )
return - V_39 ;
}
if ( F_7 ( V_8 -> V_11 ) ) {
unsigned long V_43 ;
if ( V_8 -> V_12 )
V_43 = V_44 ;
else
V_43 = V_45 ;
V_31 = F_31 ( V_14 , V_8 -> V_11 ,
V_43 , F_32 ( V_14 ) ) ;
if ( V_31 ) {
F_14 ( V_14 , L_12 ,
V_8 -> V_11 ) ;
return V_31 ;
}
}
V_8 -> V_14 = V_14 ;
V_8 -> V_13 . V_14 = V_8 -> V_14 ;
V_8 -> V_13 . V_46 = L_13 ;
V_8 -> V_13 . V_47 = F_5 ;
V_8 -> V_13 . V_22 = V_48 ;
V_8 -> V_13 . type = type ;
V_8 -> V_13 . V_18 -> V_13 = & V_8 -> V_13 ;
V_8 -> V_13 . V_18 -> V_49 = F_20 ;
V_8 -> V_13 . V_18 -> V_50 = F_19 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_3 )
{
struct V_26 * V_14 = & V_3 -> V_14 ;
struct V_7 * V_8 ;
int V_31 ;
V_8 = F_25 ( V_14 , sizeof( * V_8 ) , V_41 ) ;
if ( ! V_8 )
return - V_42 ;
V_31 = F_21 ( V_14 , V_8 , F_34 ( & V_3 -> V_14 ) ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_13 . V_51 = F_10 ;
V_8 -> V_13 . V_52 = F_16 ;
V_31 = F_35 ( & V_8 -> V_13 ) ;
if ( V_31 ) {
F_14 ( & V_3 -> V_14 , L_14 ,
V_31 ) ;
return V_31 ;
}
F_36 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = F_38 ( V_3 ) ;
F_39 ( & V_8 -> V_13 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_53 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_53 ) ;
}
