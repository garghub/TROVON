void F_1 ( void )
{
if ( V_1 )
return;
V_1 = F_2 ( L_1 , - 1 , NULL , 0 ) ;
if ( ! V_1 ) {
F_3 ( V_2 L_2 ) ;
return;
}
}
void F_4 ( void )
{
F_5 ( V_1 ) ;
V_1 = NULL ;
}
static int F_6 ( struct V_3 * V_4 , int V_5 )
{
return 0 ;
}
static int F_7 ( struct V_3 * V_6 )
{
struct V_7 * V_8 = F_8 ( V_6 -> V_9 ) ;
if ( ! F_9 ( V_8 -> V_10 ) ) {
if ( F_10 ( V_8 -> V_10 ) )
F_11 ( V_6 -> V_9 , L_3 ) ;
}
if ( ! F_9 ( V_8 -> V_11 ) )
F_12 ( V_8 -> V_11 ) ;
if ( ! F_9 ( V_8 -> V_12 ) ) {
if ( F_10 ( V_8 -> V_12 ) )
F_11 ( V_6 -> V_9 , L_4 ) ;
}
return 0 ;
}
static void F_13 ( struct V_3 * V_6 )
{
struct V_7 * V_8 = F_8 ( V_6 -> V_9 ) ;
if ( ! F_9 ( V_8 -> V_12 ) ) {
if ( F_14 ( V_8 -> V_12 ) )
F_11 ( V_6 -> V_9 , L_5 ) ;
}
if ( ! F_9 ( V_8 -> V_11 ) )
F_15 ( V_8 -> V_11 ) ;
if ( ! F_9 ( V_8 -> V_10 ) ) {
if ( F_14 ( V_8 -> V_10 ) )
F_11 ( V_6 -> V_9 , L_6 ) ;
}
}
static int F_16 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
if ( ! V_14 )
return - V_17 ;
if ( ! V_16 ) {
V_14 -> V_16 = NULL ;
return - V_17 ;
}
V_14 -> V_16 = V_16 ;
V_14 -> V_6 -> V_18 = V_19 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 , struct V_20 * V_21 )
{
if ( ! V_14 )
return - V_17 ;
if ( ! V_21 ) {
V_14 -> V_21 = NULL ;
return - V_17 ;
}
V_14 -> V_21 = V_21 ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_9 = & V_23 -> V_9 ;
struct V_25 * V_26 = V_23 -> V_9 . V_27 ;
struct V_7 * V_8 ;
enum V_28 type = V_29 ;
int V_30 ;
T_1 V_31 = 0 ;
bool V_32 = false ;
bool V_33 = false ;
V_8 = F_19 ( & V_23 -> V_9 , sizeof( * V_8 ) , V_34 ) ;
if ( ! V_8 )
return - V_35 ;
V_8 -> V_6 . V_14 = F_19 ( & V_23 -> V_9 , sizeof( * V_8 -> V_6 . V_14 ) ,
V_34 ) ;
if ( ! V_8 -> V_6 . V_14 )
return - V_35 ;
if ( V_9 -> V_36 ) {
struct V_37 * V_38 = V_9 -> V_36 ;
if ( F_20 ( V_38 , L_7 , & V_31 ) )
V_31 = 0 ;
V_32 = F_21 ( V_38 , L_8 ) ;
V_33 = F_21 ( V_38 , L_9 ) ;
} else if ( V_26 ) {
type = V_26 -> type ;
V_31 = V_26 -> V_31 ;
V_32 = V_26 -> V_32 ;
V_33 = V_26 -> V_33 ;
}
V_8 -> V_11 = F_22 ( & V_23 -> V_9 , L_10 ) ;
if ( F_9 ( V_8 -> V_11 ) ) {
F_23 ( & V_23 -> V_9 , L_11 ,
F_24 ( V_8 -> V_11 ) ) ;
}
if ( ! F_9 ( V_8 -> V_11 ) && V_31 ) {
V_30 = F_25 ( V_8 -> V_11 , V_31 ) ;
if ( V_30 ) {
F_11 ( & V_23 -> V_9 , L_12 ) ;
return V_30 ;
}
}
if ( ! F_9 ( V_8 -> V_11 ) ) {
V_30 = F_26 ( V_8 -> V_11 ) ;
if ( V_30 ) {
F_11 ( & V_23 -> V_9 , L_13 ) ;
return V_30 ;
}
}
V_8 -> V_10 = F_27 ( & V_23 -> V_9 , L_14 ) ;
if ( F_9 ( V_8 -> V_10 ) ) {
F_23 ( & V_23 -> V_9 , L_15 ,
F_24 ( V_8 -> V_10 ) ) ;
if ( V_32 )
return - V_39 ;
}
V_8 -> V_12 = F_27 ( & V_23 -> V_9 , L_16 ) ;
if ( F_9 ( V_8 -> V_12 ) ) {
F_23 ( & V_23 -> V_9 , L_17 ,
F_24 ( V_8 -> V_12 ) ) ;
if ( V_33 )
return - V_39 ;
}
V_8 -> V_9 = & V_23 -> V_9 ;
V_8 -> V_6 . V_9 = V_8 -> V_9 ;
V_8 -> V_6 . V_40 = L_18 ;
V_8 -> V_6 . V_41 = F_6 ;
V_8 -> V_6 . V_42 = F_7 ;
V_8 -> V_6 . V_43 = F_13 ;
V_8 -> V_6 . V_18 = V_44 ;
V_8 -> V_6 . type = type ;
V_8 -> V_6 . V_14 -> V_6 = & V_8 -> V_6 ;
V_8 -> V_6 . V_14 -> V_45 = F_17 ;
V_8 -> V_6 . V_14 -> V_46 = F_16 ;
V_30 = F_28 ( & V_8 -> V_6 ) ;
if ( V_30 ) {
F_11 ( & V_23 -> V_9 , L_19 ,
V_30 ) ;
goto V_47;
}
F_29 ( V_23 , V_8 ) ;
F_30 ( & V_8 -> V_6 . V_48 ) ;
return 0 ;
V_47:
if ( ! F_9 ( V_8 -> V_11 ) )
F_31 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_32 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_33 ( V_23 ) ;
if ( ! F_9 ( V_8 -> V_11 ) )
F_31 ( V_8 -> V_11 ) ;
F_34 ( & V_8 -> V_6 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_49 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_49 ) ;
}
