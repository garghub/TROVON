struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
void * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_6 ;
}
void F_3 ( struct V_2 * V_3 , void * V_7 )
{
V_3 -> V_6 = V_7 ;
}
struct V_1 * F_4 ( struct V_2 * V_3 )
{
return & V_3 -> V_5 ;
}
struct V_2 * F_5 ( struct V_1 * V_5 )
{
return F_6 ( V_5 ) ? F_7 ( V_5 ) : NULL ;
}
T_1 F_8 ( struct V_2 * V_3 )
{
return V_3 -> V_8 ;
}
static int F_9 ( struct V_1 * V_5 , void * V_7 )
{
struct V_2 * V_3 ;
if ( ! F_6 ( V_5 ) )
return 0 ;
V_3 = F_7 ( V_5 ) ;
if ( F_10 ( V_3 -> V_8 , * ( T_1 * ) V_7 ) == 0 )
return 1 ;
return 0 ;
}
static bool F_11 ( struct V_9 * V_4 , T_1 V_8 )
{
struct V_1 * V_5 ;
V_5 = F_12 ( V_4 -> V_5 , & V_8 , F_9 ) ;
if ( V_5 ) {
F_13 ( V_5 ) ;
return true ;
}
return false ;
}
static struct V_9 * F_14 ( struct V_1 * V_5 )
{
struct V_9 * V_4 ;
F_15 (parent, &parent_list, next) {
if ( V_4 -> V_5 == V_5 )
return V_4 ;
}
return NULL ;
}
static void F_16 ( struct V_10 * V_10 )
{
struct V_9 * V_4 = F_17 ( V_10 , struct V_9 ,
V_11 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_18 ( V_4 ) ;
F_13 ( V_5 ) ;
}
static
inline struct V_9 * F_19 ( struct V_9 * V_4 )
{
if ( V_4 )
F_20 ( & V_4 -> V_11 ) ;
return V_4 ;
}
static inline void F_21 ( struct V_9 * V_4 )
{
if ( V_4 )
F_22 ( & V_4 -> V_11 , F_16 ) ;
}
static int F_23 ( struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_9 * V_4 = V_3 -> V_4 ;
int V_14 ;
V_14 = V_4 -> V_15 -> V_16 ( V_13 , V_3 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_24 ( & V_3 -> V_5 . V_13 ,
V_4 -> V_15 -> V_17 ) ;
if ( V_14 )
V_4 -> V_15 -> remove ( V_3 ) ;
return V_14 ;
}
static int F_25 ( struct V_2 * V_3 , bool V_18 )
{
struct V_9 * V_4 = V_3 -> V_4 ;
int V_14 ;
V_14 = V_4 -> V_15 -> remove ( V_3 ) ;
if ( V_14 && ! V_18 )
return - V_19 ;
F_26 ( & V_3 -> V_5 . V_13 , V_4 -> V_15 -> V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_5 , void * V_7 )
{
if ( ! F_6 ( V_5 ) )
return 0 ;
return F_28 ( V_5 , V_7 ? * ( bool * ) V_7 : true ) ;
}
int F_29 ( struct V_1 * V_5 , const struct V_20 * V_15 )
{
int V_14 ;
struct V_9 * V_4 ;
if ( ! V_15 || ! V_15 -> V_16 || ! V_15 -> remove || ! V_15 -> V_21 )
return - V_22 ;
V_5 = F_30 ( V_5 ) ;
if ( ! V_5 )
return - V_22 ;
F_31 ( & V_23 ) ;
V_4 = F_14 ( V_5 ) ;
if ( V_4 ) {
V_14 = - V_24 ;
goto V_25;
}
V_4 = F_32 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 ) {
V_14 = - V_27 ;
goto V_25;
}
F_33 ( & V_4 -> V_11 ) ;
F_34 ( & V_4 -> V_28 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_15 = V_15 ;
if ( ! V_29 ) {
V_29 = F_35 ( L_1 ) ;
if ( ! V_29 ) {
V_14 = - V_27 ;
goto V_25;
}
}
V_14 = F_36 ( V_4 ) ;
if ( V_14 )
goto V_25;
V_14 = F_37 ( V_29 , V_5 , NULL ) ;
if ( V_14 )
F_38 ( V_5 , L_2 ) ;
F_39 ( & V_4 -> V_30 , & V_31 ) ;
F_40 ( & V_23 ) ;
F_41 ( V_5 , L_3 ) ;
return 0 ;
V_25:
F_40 ( & V_23 ) ;
if ( V_4 )
F_21 ( V_4 ) ;
else
F_13 ( V_5 ) ;
return V_14 ;
}
void F_42 ( struct V_1 * V_5 )
{
struct V_9 * V_4 ;
bool V_18 = true ;
F_31 ( & V_23 ) ;
V_4 = F_14 ( V_5 ) ;
if ( ! V_4 ) {
F_40 ( & V_23 ) ;
return;
}
F_41 ( V_5 , L_4 ) ;
F_43 ( & V_4 -> V_30 ) ;
F_44 ( V_29 , V_5 , NULL ) ;
F_45 ( V_5 , ( void * ) & V_18 ,
F_27 ) ;
F_46 ( V_4 ) ;
F_40 ( & V_23 ) ;
F_21 ( V_4 ) ;
}
static void F_47 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_7 ( V_5 ) ;
F_48 ( & V_3 -> V_5 , L_5 ) ;
F_18 ( V_3 ) ;
}
int F_49 ( struct V_12 * V_13 , struct V_1 * V_5 , T_1 V_8 )
{
int V_14 ;
struct V_2 * V_3 ;
struct V_9 * V_4 ;
struct V_32 * type = F_50 ( V_13 ) ;
V_4 = F_19 ( type -> V_4 ) ;
if ( ! V_4 )
return - V_22 ;
F_31 ( & V_4 -> V_28 ) ;
if ( F_11 ( V_4 , V_8 ) ) {
V_14 = - V_24 ;
goto V_33;
}
V_3 = F_32 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 ) {
V_14 = - V_27 ;
goto V_33;
}
memcpy ( & V_3 -> V_8 , & V_8 , sizeof( T_1 ) ) ;
V_3 -> V_4 = V_4 ;
F_33 ( & V_3 -> V_11 ) ;
V_3 -> V_5 . V_4 = V_5 ;
V_3 -> V_5 . V_34 = & V_35 ;
V_3 -> V_5 . V_36 = F_47 ;
F_51 ( & V_3 -> V_5 , L_6 , V_8 . V_37 ) ;
V_14 = F_52 ( & V_3 -> V_5 ) ;
if ( V_14 ) {
F_13 ( & V_3 -> V_5 ) ;
goto V_33;
}
V_14 = F_23 ( V_13 , V_3 ) ;
if ( V_14 )
goto V_38;
V_14 = F_53 ( & V_3 -> V_5 , type ) ;
if ( V_14 ) {
F_25 ( V_3 , true ) ;
goto V_38;
}
V_3 -> V_39 = V_13 ;
F_48 ( & V_3 -> V_5 , L_7 ) ;
F_40 ( & V_4 -> V_28 ) ;
F_31 ( & V_40 ) ;
F_39 ( & V_3 -> V_30 , & V_41 ) ;
F_40 ( & V_40 ) ;
return V_14 ;
V_38:
F_54 ( & V_3 -> V_5 ) ;
V_33:
F_40 ( & V_4 -> V_28 ) ;
F_21 ( V_4 ) ;
return V_14 ;
}
int F_28 ( struct V_1 * V_5 , bool V_18 )
{
struct V_2 * V_3 , * V_42 ;
struct V_9 * V_4 ;
struct V_32 * type ;
int V_14 ;
bool V_43 = false ;
V_3 = F_7 ( V_5 ) ;
F_31 ( & V_40 ) ;
F_15 (tmp, &mdev_list, next) {
if ( V_42 == V_3 ) {
V_43 = true ;
break;
}
}
if ( V_43 )
F_43 ( & V_3 -> V_30 ) ;
F_40 ( & V_40 ) ;
if ( ! V_43 )
return - V_44 ;
type = F_50 ( V_3 -> V_39 ) ;
V_4 = V_3 -> V_4 ;
F_31 ( & V_4 -> V_28 ) ;
V_14 = F_25 ( V_3 , V_18 ) ;
if ( V_14 ) {
F_40 ( & V_4 -> V_28 ) ;
F_31 ( & V_40 ) ;
F_39 ( & V_3 -> V_30 , & V_41 ) ;
F_40 ( & V_40 ) ;
return V_14 ;
}
F_55 ( V_5 , type ) ;
F_54 ( V_5 ) ;
F_40 ( & V_4 -> V_28 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
static int T_2 F_56 ( void )
{
int V_14 ;
V_14 = F_57 () ;
if ( ! V_14 )
F_58 ( L_8 ) ;
return V_14 ;
}
static void T_3 F_59 ( void )
{
if ( V_29 )
F_60 ( V_29 ) ;
F_61 () ;
}
