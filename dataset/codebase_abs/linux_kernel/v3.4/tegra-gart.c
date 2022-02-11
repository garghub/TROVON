static inline void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_7 ) ;
F_3 ( V_2 -> V_8 , L_1 ,
V_4 ? L_2 : L_3 , V_3 , V_4 & V_9 ) ;
}
static inline unsigned long F_4 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_4 ;
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
V_4 = F_5 ( V_2 -> V_5 + V_7 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , const T_1 * V_10 )
{
unsigned long V_11 ;
F_7 (gart, iova)
F_1 ( V_2 , V_11 , V_10 ? * ( V_10 ++ ) : 0 ) ;
F_2 ( 1 , V_2 -> V_5 + V_12 ) ;
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
unsigned long V_13 ;
F_10 ( & V_2 -> V_14 , V_13 ) ;
F_7 (gart, iova) {
unsigned long V_4 ;
V_4 = F_4 ( V_2 , V_11 ) ;
F_3 ( V_2 -> V_8 , L_4 ,
( V_15 & V_4 ) ? L_5 : L_6 ,
V_11 , V_4 & V_9 ) ;
}
F_11 ( & V_2 -> V_14 , V_13 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
}
static inline bool F_12 ( struct V_1 * V_2 ,
unsigned long V_11 , T_2 V_16 )
{
unsigned long V_17 , V_18 , V_19 , V_20 ;
V_17 = V_11 ;
V_18 = V_17 + V_16 - 1 ;
V_19 = V_2 -> V_21 ;
V_20 = V_19 + V_2 -> V_22 * V_23 - 1 ;
if ( V_17 < V_19 )
return false ;
if ( V_18 > V_20 )
return false ;
return true ;
}
static int F_13 ( struct V_24 * V_25 ,
struct V_26 * V_8 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 , * V_29 ;
int V_30 = 0 ;
V_2 = F_14 ( V_8 -> V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_25 -> V_33 = V_2 ;
V_28 = F_15 ( V_2 -> V_8 , sizeof( * V_29 ) , V_34 ) ;
if ( ! V_28 )
return - V_35 ;
V_28 -> V_8 = V_8 ;
F_16 ( & V_2 -> V_36 ) ;
F_17 (c, &gart->client, list) {
if ( V_29 -> V_8 == V_8 ) {
F_18 ( V_2 -> V_8 ,
L_7 , F_19 ( V_8 ) ) ;
V_30 = - V_32 ;
goto V_37;
}
}
F_20 ( & V_28 -> V_38 , & V_2 -> V_28 ) ;
F_21 ( & V_2 -> V_36 ) ;
F_3 ( V_2 -> V_8 , L_8 , F_19 ( V_8 ) ) ;
return 0 ;
V_37:
F_22 ( V_2 -> V_8 , V_28 ) ;
F_21 ( & V_2 -> V_36 ) ;
return V_30 ;
}
static void F_23 ( struct V_24 * V_25 ,
struct V_26 * V_8 )
{
struct V_1 * V_2 = V_25 -> V_33 ;
struct V_27 * V_29 ;
F_16 ( & V_2 -> V_36 ) ;
F_17 (c, &gart->client, list) {
if ( V_29 -> V_8 == V_8 ) {
F_24 ( & V_29 -> V_38 ) ;
F_22 ( V_2 -> V_8 , V_29 ) ;
F_3 ( V_2 -> V_8 , L_9 , F_19 ( V_8 ) ) ;
goto V_39;
}
}
F_18 ( V_2 -> V_8 , L_10 ) ;
V_39:
F_21 ( & V_2 -> V_36 ) ;
}
static int F_25 ( struct V_24 * V_25 )
{
return 0 ;
}
static void F_26 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_33 ;
if ( ! V_2 )
return;
F_16 ( & V_2 -> V_36 ) ;
if ( ! F_27 ( & V_2 -> V_28 ) ) {
struct V_27 * V_29 ;
F_17 (c, &gart->client, list)
F_23 ( V_25 , V_29 -> V_8 ) ;
}
F_21 ( & V_2 -> V_36 ) ;
V_25 -> V_33 = NULL ;
}
static int F_28 ( struct V_24 * V_25 , unsigned long V_11 ,
T_3 V_40 , T_2 V_16 , int V_41 )
{
struct V_1 * V_2 = V_25 -> V_33 ;
unsigned long V_13 ;
unsigned long V_42 ;
if ( ! F_12 ( V_2 , V_11 , V_16 ) )
return - V_32 ;
F_10 ( & V_2 -> V_14 , V_13 ) ;
V_42 = F_29 ( V_40 ) ;
if ( ! F_30 ( V_42 ) ) {
F_18 ( V_2 -> V_8 , L_11 , V_40 ) ;
F_11 ( & V_2 -> V_14 , V_13 ) ;
return - V_32 ;
}
F_1 ( V_2 , V_11 , F_31 ( V_42 ) ) ;
F_8 ( V_2 ) ;
F_11 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_24 * V_25 , unsigned long V_11 ,
T_2 V_16 )
{
struct V_1 * V_2 = V_25 -> V_33 ;
unsigned long V_13 ;
if ( ! F_12 ( V_2 , V_11 , V_16 ) )
return 0 ;
F_10 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_11 , 0 ) ;
F_8 ( V_2 ) ;
F_11 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_24 * V_25 ,
unsigned long V_11 )
{
struct V_1 * V_2 = V_25 -> V_33 ;
unsigned long V_4 ;
T_3 V_40 ;
unsigned long V_13 ;
if ( ! F_12 ( V_2 , V_11 , 0 ) )
return - V_32 ;
F_10 ( & V_2 -> V_14 , V_13 ) ;
V_4 = F_4 ( V_2 , V_11 ) ;
F_11 ( & V_2 -> V_14 , V_13 ) ;
V_40 = ( V_4 & V_9 ) ;
if ( ! F_30 ( F_29 ( V_40 ) ) ) {
F_18 ( V_2 -> V_8 , L_12 , V_11 , V_40 ) ;
F_9 ( V_2 ) ;
return - V_32 ;
}
return V_40 ;
}
static int F_34 ( struct V_24 * V_25 ,
unsigned long V_43 )
{
return 0 ;
}
static int F_35 ( struct V_26 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
unsigned long V_11 ;
T_1 * V_10 = V_2 -> V_44 ;
unsigned long V_13 ;
F_10 ( & V_2 -> V_14 , V_13 ) ;
F_7 ( V_2 , V_11 )
* ( V_10 ++ ) = F_4 ( V_2 , V_11 ) ;
F_11 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
unsigned long V_13 ;
F_10 ( & V_2 -> V_14 , V_13 ) ;
F_6 ( V_2 , V_2 -> V_44 ) ;
F_11 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
static int F_37 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 , * V_49 ;
void T_4 * V_50 ;
int V_30 ;
struct V_26 * V_8 = & V_46 -> V_8 ;
if ( V_51 )
return - V_52 ;
F_38 ( V_53 != V_54 ) ;
V_48 = F_39 ( V_46 , V_55 , 0 ) ;
V_49 = F_39 ( V_46 , V_55 , 1 ) ;
if ( ! V_48 || ! V_49 ) {
F_18 ( V_8 , L_13 ) ;
return - V_56 ;
}
V_2 = F_15 ( V_8 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
F_18 ( V_8 , L_14 ) ;
return - V_35 ;
}
V_50 = F_40 ( V_8 , V_48 -> V_57 , F_41 ( V_48 ) ) ;
if ( ! V_50 ) {
F_18 ( V_8 , L_15 ) ;
V_30 = - V_56 ;
goto V_37;
}
V_2 -> V_8 = & V_46 -> V_8 ;
F_42 ( & V_2 -> V_14 ) ;
F_42 ( & V_2 -> V_36 ) ;
F_43 ( & V_2 -> V_28 ) ;
V_2 -> V_5 = V_50 ;
V_2 -> V_21 = ( V_58 ) V_49 -> V_57 ;
V_2 -> V_22 = ( F_41 ( V_49 ) >> V_54 ) ;
V_2 -> V_44 = F_44 ( sizeof( T_1 ) * V_2 -> V_22 ) ;
if ( ! V_2 -> V_44 ) {
F_18 ( V_8 , L_16 ) ;
V_30 = - V_35 ;
goto V_37;
}
F_45 ( V_46 , V_2 ) ;
F_6 ( V_2 , NULL ) ;
V_51 = V_2 ;
return 0 ;
V_37:
if ( V_50 )
F_46 ( V_8 , V_50 ) ;
if ( V_2 && V_2 -> V_44 )
F_47 ( V_2 -> V_44 ) ;
F_22 ( V_8 , V_2 ) ;
return V_30 ;
}
static int F_48 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_49 ( V_46 ) ;
struct V_26 * V_8 = V_2 -> V_8 ;
F_2 ( 0 , V_2 -> V_5 + V_12 ) ;
if ( V_2 -> V_44 )
F_47 ( V_2 -> V_44 ) ;
if ( V_2 -> V_5 )
F_46 ( V_8 , V_2 -> V_5 ) ;
F_22 ( V_8 , V_2 ) ;
V_51 = NULL ;
return 0 ;
}
static int T_5 F_50 ( void )
{
F_51 ( & V_59 , & V_60 ) ;
return F_52 ( & V_61 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_61 ) ;
}
