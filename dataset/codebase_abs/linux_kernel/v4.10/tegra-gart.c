static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 ,
unsigned long V_7 , T_1 V_8 )
{
F_4 ( V_7 , V_6 -> V_9 + V_10 ) ;
F_4 ( V_8 , V_6 -> V_9 + V_11 ) ;
F_5 ( V_6 -> V_12 , L_1 ,
V_8 ? L_2 : L_3 , V_7 , V_8 & V_13 ) ;
}
static inline unsigned long F_6 ( struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned long V_8 ;
F_4 ( V_7 , V_6 -> V_9 + V_10 ) ;
V_8 = F_7 ( V_6 -> V_9 + V_11 ) ;
return V_8 ;
}
static void F_8 ( struct V_5 * V_6 , const T_1 * V_14 )
{
unsigned long V_15 ;
F_9 (gart, iova)
F_3 ( V_6 , V_15 , V_14 ? * ( V_14 ++ ) : 0 ) ;
F_4 ( 1 , V_6 -> V_9 + V_16 ) ;
F_10 ( V_6 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
unsigned long V_15 ;
unsigned long V_17 ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
F_9 (gart, iova) {
unsigned long V_8 ;
V_8 = F_6 ( V_6 , V_15 ) ;
F_5 ( V_6 -> V_12 , L_4 ,
( V_19 & V_8 ) ? L_5 : L_6 ,
V_15 , V_8 & V_13 ) ;
}
F_13 ( & V_6 -> V_18 , V_17 ) ;
}
static inline void F_11 ( struct V_5 * V_6 )
{
}
static inline bool F_14 ( struct V_5 * V_6 ,
unsigned long V_15 , T_2 V_20 )
{
unsigned long V_21 , V_22 , V_23 , V_24 ;
V_21 = V_15 ;
V_22 = V_21 + V_20 - 1 ;
V_23 = V_6 -> V_25 ;
V_24 = V_23 + V_6 -> V_26 * V_27 - 1 ;
if ( V_21 < V_23 )
return false ;
if ( V_22 > V_24 )
return false ;
return true ;
}
static int F_15 ( struct V_2 * V_4 ,
struct V_28 * V_12 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_29 * V_30 , * V_31 ;
int V_32 = 0 ;
V_30 = F_16 ( V_6 -> V_12 , sizeof( * V_31 ) , V_33 ) ;
if ( ! V_30 )
return - V_34 ;
V_30 -> V_12 = V_12 ;
F_17 ( & V_6 -> V_35 ) ;
F_18 (c, &gart->client, list) {
if ( V_31 -> V_12 == V_12 ) {
F_19 ( V_6 -> V_12 ,
L_7 , F_20 ( V_12 ) ) ;
V_32 = - V_36 ;
goto V_37;
}
}
F_21 ( & V_30 -> V_38 , & V_6 -> V_30 ) ;
F_22 ( & V_6 -> V_35 ) ;
F_5 ( V_6 -> V_12 , L_8 , F_20 ( V_12 ) ) ;
return 0 ;
V_37:
F_23 ( V_6 -> V_12 , V_30 ) ;
F_22 ( & V_6 -> V_35 ) ;
return V_32 ;
}
static void F_24 ( struct V_2 * V_4 ,
struct V_28 * V_12 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_29 * V_31 ;
F_17 ( & V_6 -> V_35 ) ;
F_18 (c, &gart->client, list) {
if ( V_31 -> V_12 == V_12 ) {
F_25 ( & V_31 -> V_38 ) ;
F_23 ( V_6 -> V_12 , V_31 ) ;
F_5 ( V_6 -> V_12 , L_9 , F_20 ( V_12 ) ) ;
goto V_39;
}
}
F_19 ( V_6 -> V_12 , L_10 ) ;
V_39:
F_22 ( & V_6 -> V_35 ) ;
}
static struct V_2 * F_26 ( unsigned type )
{
struct V_1 * V_1 ;
struct V_5 * V_6 ;
if ( type != V_40 )
return NULL ;
V_6 = V_41 ;
if ( ! V_6 )
return NULL ;
V_1 = F_27 ( sizeof( * V_1 ) , V_33 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_6 = V_6 ;
V_1 -> V_4 . V_42 . V_43 = V_6 -> V_25 ;
V_1 -> V_4 . V_42 . V_44 = V_6 -> V_25 +
V_6 -> V_26 * V_27 - 1 ;
V_1 -> V_4 . V_42 . V_45 = true ;
return & V_1 -> V_4 ;
}
static void F_28 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_1 -> V_6 ;
if ( V_6 ) {
F_17 ( & V_6 -> V_35 ) ;
if ( ! F_29 ( & V_6 -> V_30 ) ) {
struct V_29 * V_31 ;
F_18 (c, &gart->client, list)
F_24 ( V_4 , V_31 -> V_12 ) ;
}
F_22 ( & V_6 -> V_35 ) ;
}
F_30 ( V_1 ) ;
}
static int F_31 ( struct V_2 * V_4 , unsigned long V_15 ,
T_3 V_46 , T_2 V_20 , int V_47 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_1 -> V_6 ;
unsigned long V_17 ;
unsigned long V_48 ;
if ( ! F_14 ( V_6 , V_15 , V_20 ) )
return - V_36 ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
V_48 = F_32 ( V_46 ) ;
if ( ! F_33 ( V_48 ) ) {
F_19 ( V_6 -> V_12 , L_11 , & V_46 ) ;
F_13 ( & V_6 -> V_18 , V_17 ) ;
return - V_36 ;
}
F_3 ( V_6 , V_15 , F_34 ( V_48 ) ) ;
F_10 ( V_6 ) ;
F_13 ( & V_6 -> V_18 , V_17 ) ;
return 0 ;
}
static T_2 F_35 ( struct V_2 * V_4 , unsigned long V_15 ,
T_2 V_20 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_1 -> V_6 ;
unsigned long V_17 ;
if ( ! F_14 ( V_6 , V_15 , V_20 ) )
return 0 ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
F_3 ( V_6 , V_15 , 0 ) ;
F_10 ( V_6 ) ;
F_13 ( & V_6 -> V_18 , V_17 ) ;
return 0 ;
}
static T_3 F_36 ( struct V_2 * V_4 ,
T_4 V_15 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_1 -> V_6 ;
unsigned long V_8 ;
T_3 V_46 ;
unsigned long V_17 ;
if ( ! F_14 ( V_6 , V_15 , 0 ) )
return - V_36 ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
V_8 = F_6 ( V_6 , V_15 ) ;
F_13 ( & V_6 -> V_18 , V_17 ) ;
V_46 = ( V_8 & V_13 ) ;
if ( ! F_33 ( F_32 ( V_46 ) ) ) {
F_19 ( V_6 -> V_12 , L_12 ,
( unsigned long long ) V_15 , & V_46 ) ;
F_11 ( V_6 ) ;
return - V_36 ;
}
return V_46 ;
}
static bool F_37 ( enum V_49 V_50 )
{
return false ;
}
static int F_38 ( struct V_28 * V_12 )
{
struct V_5 * V_6 = F_39 ( V_12 ) ;
unsigned long V_15 ;
T_1 * V_14 = V_6 -> V_51 ;
unsigned long V_17 ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
F_9 ( V_6 , V_15 )
* ( V_14 ++ ) = F_6 ( V_6 , V_15 ) ;
F_13 ( & V_6 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_40 ( struct V_28 * V_12 )
{
struct V_5 * V_6 = F_39 ( V_12 ) ;
unsigned long V_17 ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
F_8 ( V_6 , V_6 -> V_51 ) ;
F_13 ( & V_6 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_53 )
{
struct V_5 * V_6 ;
struct V_54 * V_55 , * V_56 ;
void T_5 * V_57 ;
struct V_28 * V_12 = & V_53 -> V_12 ;
if ( V_41 )
return - V_58 ;
F_42 ( V_59 != V_60 ) ;
V_55 = F_43 ( V_53 , V_61 , 0 ) ;
V_56 = F_43 ( V_53 , V_61 , 1 ) ;
if ( ! V_55 || ! V_56 ) {
F_19 ( V_12 , L_13 ) ;
return - V_62 ;
}
V_6 = F_16 ( V_12 , sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 ) {
F_19 ( V_12 , L_14 ) ;
return - V_34 ;
}
V_57 = F_44 ( V_12 , V_55 -> V_63 , F_45 ( V_55 ) ) ;
if ( ! V_57 ) {
F_19 ( V_12 , L_15 ) ;
return - V_62 ;
}
V_6 -> V_12 = & V_53 -> V_12 ;
F_46 ( & V_6 -> V_18 ) ;
F_46 ( & V_6 -> V_35 ) ;
F_47 ( & V_6 -> V_30 ) ;
V_6 -> V_9 = V_57 ;
V_6 -> V_25 = ( T_4 ) V_56 -> V_63 ;
V_6 -> V_26 = ( F_45 ( V_56 ) >> V_60 ) ;
V_6 -> V_51 = F_48 ( sizeof( T_1 ) * V_6 -> V_26 ) ;
if ( ! V_6 -> V_51 ) {
F_19 ( V_12 , L_16 ) ;
return - V_34 ;
}
F_49 ( V_53 , V_6 ) ;
F_8 ( V_6 , NULL ) ;
V_41 = V_6 ;
return 0 ;
}
static int F_50 ( struct V_52 * V_53 )
{
struct V_5 * V_6 = F_51 ( V_53 ) ;
F_4 ( 0 , V_6 -> V_9 + V_16 ) ;
if ( V_6 -> V_51 )
F_52 ( V_6 -> V_51 ) ;
V_41 = NULL ;
return 0 ;
}
static int F_53 ( void )
{
return F_54 ( & V_64 ) ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_64 ) ;
}
