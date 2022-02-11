void F_1 ( void )
{
if ( V_1 )
return;
V_1 = F_2 ( L_1 , - 1 , NULL , 0 ) ;
if ( ! V_1 ) {
F_3 ( L_2 ) ;
return;
}
}
void F_4 ( void )
{
F_5 ( V_1 ) ;
V_1 = NULL ;
}
static int F_6 ( struct V_2 * V_3 , int V_4 )
{
return 0 ;
}
int F_7 ( struct V_2 * V_5 )
{
struct V_6 * V_7 = F_8 ( V_5 -> V_8 ) ;
if ( ! F_9 ( V_7 -> V_9 ) ) {
if ( F_10 ( V_7 -> V_9 ) )
F_11 ( V_5 -> V_8 , L_3 ) ;
}
if ( ! F_9 ( V_7 -> V_10 ) )
F_12 ( V_7 -> V_10 ) ;
if ( ! F_9 ( V_7 -> V_11 ) ) {
if ( F_10 ( V_7 -> V_11 ) )
F_11 ( V_5 -> V_8 , L_4 ) ;
}
return 0 ;
}
void F_13 ( struct V_2 * V_5 )
{
struct V_6 * V_7 = F_8 ( V_5 -> V_8 ) ;
if ( ! F_9 ( V_7 -> V_11 ) ) {
if ( F_14 ( V_7 -> V_11 ) )
F_11 ( V_5 -> V_8 , L_5 ) ;
}
if ( ! F_9 ( V_7 -> V_10 ) )
F_15 ( V_7 -> V_10 ) ;
if ( ! F_9 ( V_7 -> V_9 ) ) {
if ( F_14 ( V_7 -> V_9 ) )
F_11 ( V_5 -> V_8 , L_6 ) ;
}
}
static int F_16 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
if ( ! V_13 )
return - V_16 ;
if ( ! V_15 ) {
V_13 -> V_15 = NULL ;
return - V_16 ;
}
V_13 -> V_15 = V_15 ;
V_13 -> V_5 -> V_17 = V_18 ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 , struct V_19 * V_20 )
{
if ( ! V_13 )
return - V_16 ;
if ( ! V_20 ) {
V_13 -> V_20 = NULL ;
return - V_16 ;
}
V_13 -> V_20 = V_20 ;
return 0 ;
}
int F_18 ( struct V_21 * V_8 , struct V_6 * V_7 ,
enum V_22 type , T_1 V_23 , bool V_24 ,
bool V_25 )
{
int V_26 ;
V_7 -> V_5 . V_13 = F_19 ( V_8 , sizeof( * V_7 -> V_5 . V_13 ) ,
V_27 ) ;
if ( ! V_7 -> V_5 . V_13 )
return - V_28 ;
V_7 -> V_10 = F_20 ( V_8 , L_7 ) ;
if ( F_9 ( V_7 -> V_10 ) ) {
F_21 ( V_8 , L_8 ,
F_22 ( V_7 -> V_10 ) ) ;
}
if ( ! F_9 ( V_7 -> V_10 ) && V_23 ) {
V_26 = F_23 ( V_7 -> V_10 , V_23 ) ;
if ( V_26 ) {
F_11 ( V_8 , L_9 ) ;
return V_26 ;
}
}
if ( ! F_9 ( V_7 -> V_10 ) ) {
V_26 = F_24 ( V_7 -> V_10 ) ;
if ( V_26 ) {
F_11 ( V_8 , L_10 ) ;
return V_26 ;
}
}
V_7 -> V_9 = F_25 ( V_8 , L_11 ) ;
if ( F_9 ( V_7 -> V_9 ) ) {
F_21 ( V_8 , L_12 ,
F_22 ( V_7 -> V_9 ) ) ;
if ( V_24 )
return - V_29 ;
}
V_7 -> V_11 = F_25 ( V_8 , L_13 ) ;
if ( F_9 ( V_7 -> V_11 ) ) {
F_21 ( V_8 , L_14 ,
F_22 ( V_7 -> V_11 ) ) ;
if ( V_25 )
return - V_29 ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_5 . V_8 = V_7 -> V_8 ;
V_7 -> V_5 . V_30 = L_15 ;
V_7 -> V_5 . V_31 = F_6 ;
V_7 -> V_5 . V_17 = V_32 ;
V_7 -> V_5 . type = type ;
V_7 -> V_5 . V_13 -> V_5 = & V_7 -> V_5 ;
V_7 -> V_5 . V_13 -> V_33 = F_17 ;
V_7 -> V_5 . V_13 -> V_34 = F_16 ;
F_26 ( & V_7 -> V_5 . V_35 ) ;
return 0 ;
}
void F_27 ( struct V_6 * V_7 )
{
if ( ! F_9 ( V_7 -> V_10 ) )
F_28 ( V_7 -> V_10 ) ;
}
static int F_29 ( struct V_36 * V_37 )
{
struct V_21 * V_8 = & V_37 -> V_8 ;
struct V_38 * V_39 =
F_30 ( & V_37 -> V_8 ) ;
struct V_6 * V_7 ;
enum V_22 type = V_40 ;
int V_26 ;
T_1 V_23 = 0 ;
bool V_24 = false ;
bool V_25 = false ;
if ( V_8 -> V_41 ) {
struct V_42 * V_43 = V_8 -> V_41 ;
if ( F_31 ( V_43 , L_16 , & V_23 ) )
V_23 = 0 ;
V_24 = F_32 ( V_43 , L_17 ) ;
V_25 = F_32 ( V_43 , L_18 ) ;
} else if ( V_39 ) {
type = V_39 -> type ;
V_23 = V_39 -> V_23 ;
V_24 = V_39 -> V_24 ;
V_25 = V_39 -> V_25 ;
}
V_7 = F_19 ( V_8 , sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return - V_28 ;
V_26 = F_18 ( V_8 , V_7 , type , V_23 , V_24 ,
V_25 ) ;
if ( V_26 )
return V_26 ;
V_7 -> V_5 . V_44 = F_7 ;
V_7 -> V_5 . V_45 = F_13 ;
V_26 = F_33 ( & V_7 -> V_5 ) ;
if ( V_26 ) {
F_11 ( & V_37 -> V_8 , L_19 ,
V_26 ) ;
goto V_46;
}
F_34 ( V_37 , V_7 ) ;
return 0 ;
V_46:
F_27 ( V_7 ) ;
return V_26 ;
}
static int F_35 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_36 ( V_37 ) ;
F_27 ( V_7 ) ;
F_37 ( & V_7 -> V_5 ) ;
return 0 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_47 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_47 ) ;
}
