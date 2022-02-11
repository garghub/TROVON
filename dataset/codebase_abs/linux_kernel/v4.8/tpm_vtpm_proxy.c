static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
T_3 V_8 ;
int V_9 , V_10 ;
V_9 = F_2 ( V_6 -> V_11 ,
V_6 -> V_12 != 0 ||
! ( V_6 -> V_13 & V_14 ) ) ;
if ( V_9 )
return - V_15 ;
F_3 ( & V_6 -> V_16 ) ;
if ( ! ( V_6 -> V_13 & V_14 ) ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_17 ;
}
V_8 = V_6 -> V_12 ;
if ( V_4 < V_8 ) {
F_4 ( & V_6 -> V_16 ) ;
F_5 ( L_1 ,
V_4 , V_8 ) ;
return - V_18 ;
}
V_10 = F_6 ( V_3 , V_6 -> V_19 , V_8 ) ;
memset ( V_6 -> V_19 , 0 , V_8 ) ;
V_6 -> V_12 = 0 ;
if ( ! V_10 )
V_6 -> V_13 |= V_20 ;
F_4 ( & V_6 -> V_16 ) ;
if ( V_10 )
return - V_21 ;
return V_8 ;
}
static T_1 F_7 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_16 ) ;
if ( ! ( V_6 -> V_13 & V_14 ) ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_17 ;
}
if ( V_4 > sizeof( V_6 -> V_19 ) ||
! ( V_6 -> V_13 & V_20 ) ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_18 ;
}
V_6 -> V_13 &= ~ V_20 ;
V_6 -> V_12 = 0 ;
if ( F_8 ( V_6 -> V_19 , V_3 , V_4 ) ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_21 ;
}
V_6 -> V_22 = V_4 ;
F_4 ( & V_6 -> V_16 ) ;
F_9 ( & V_6 -> V_11 ) ;
return V_4 ;
}
static unsigned int F_10 ( struct V_1 * V_2 , T_5 * V_23 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
unsigned V_24 ;
F_11 ( V_2 , & V_6 -> V_11 , V_23 ) ;
V_24 = V_25 ;
F_3 ( & V_6 -> V_16 ) ;
if ( V_6 -> V_12 )
V_24 |= V_26 | V_27 ;
if ( ! ( V_6 -> V_13 & V_14 ) )
V_24 |= V_28 ;
F_4 ( & V_6 -> V_16 ) ;
return V_24 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
V_6 -> V_13 |= V_14 ;
}
static void F_13 ( struct V_6 * V_6 )
{
F_3 ( & V_6 -> V_16 ) ;
V_6 -> V_13 &= ~ V_14 ;
F_4 ( & V_6 -> V_16 ) ;
F_9 ( & V_6 -> V_11 ) ;
}
static int F_14 ( struct V_29 * V_29 , struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
V_2 -> V_7 = NULL ;
F_15 ( V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 , T_6 * V_3 , T_3 V_4 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
T_3 V_8 ;
F_3 ( & V_6 -> V_16 ) ;
if ( ! ( V_6 -> V_13 & V_14 ) ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_17 ;
}
V_8 = V_6 -> V_22 ;
if ( V_4 < V_8 ) {
F_18 ( & V_31 -> V_32 ,
L_2 ,
V_4 , V_8 ) ;
V_8 = - V_18 ;
goto V_33;
}
memcpy ( V_3 , V_6 -> V_19 , V_8 ) ;
V_6 -> V_22 = 0 ;
V_33:
F_4 ( & V_6 -> V_16 ) ;
return V_8 ;
}
static int F_19 ( struct V_30 * V_31 , T_6 * V_3 , T_3 V_4 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
int V_10 = 0 ;
if ( V_4 > sizeof( V_6 -> V_19 ) ) {
F_18 ( & V_31 -> V_32 ,
L_3 ,
V_4 , sizeof( V_6 -> V_19 ) ) ;
return - V_18 ;
}
F_3 ( & V_6 -> V_16 ) ;
if ( ! ( V_6 -> V_13 & V_14 ) ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_17 ;
}
V_6 -> V_22 = 0 ;
V_6 -> V_12 = V_4 ;
memcpy ( V_6 -> V_19 , V_3 , V_4 ) ;
V_6 -> V_13 &= ~ V_20 ;
F_4 ( & V_6 -> V_16 ) ;
F_9 ( & V_6 -> V_11 ) ;
return V_10 ;
}
static void F_20 ( struct V_30 * V_31 )
{
}
static T_6 F_21 ( struct V_30 * V_31 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
if ( V_6 -> V_22 )
return V_34 ;
return 0 ;
}
static bool F_22 ( struct V_30 * V_31 , T_6 V_35 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
bool V_24 ;
F_3 ( & V_6 -> V_16 ) ;
V_24 = ! ( V_6 -> V_13 & V_14 ) ;
F_4 ( & V_6 -> V_16 ) ;
return V_24 ;
}
static void F_23 ( struct V_36 * V_37 )
{
struct V_6 * V_6 = F_24 ( V_37 , struct V_6 ,
V_37 ) ;
int V_10 ;
V_10 = F_25 ( V_6 -> V_31 ) ;
if ( V_10 )
goto V_38;
return;
V_38:
F_13 ( V_6 ) ;
}
static void F_26 ( struct V_6 * V_6 )
{
F_13 ( V_6 ) ;
F_27 ( & V_6 -> V_37 ) ;
}
static inline void F_28 ( struct V_6 * V_6 )
{
F_29 ( V_39 , & V_6 -> V_37 ) ;
}
static struct V_6 * F_30 ( void )
{
struct V_6 * V_6 ;
struct V_30 * V_31 ;
int V_38 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_40 ) ;
if ( V_6 == NULL )
return F_32 ( - V_41 ) ;
F_33 ( & V_6 -> V_11 ) ;
F_34 ( & V_6 -> V_16 ) ;
F_35 ( & V_6 -> V_37 , F_23 ) ;
V_31 = F_36 ( NULL , & V_42 ) ;
if ( F_37 ( V_31 ) ) {
V_38 = F_38 ( V_31 ) ;
goto V_43;
}
F_39 ( & V_31 -> V_32 , V_6 ) ;
V_6 -> V_31 = V_31 ;
return V_6 ;
V_43:
F_40 ( V_6 ) ;
return F_32 ( V_38 ) ;
}
static inline void F_41 ( struct V_6 * V_6 )
{
F_42 ( & V_6 -> V_31 -> V_32 ) ;
F_40 ( V_6 ) ;
}
static struct V_1 * F_43 (
struct V_44 * V_45 )
{
struct V_6 * V_6 ;
int V_10 , V_46 ;
struct V_1 * V_1 ;
if ( V_45 -> V_47 & ~ V_48 )
return F_32 ( - V_49 ) ;
V_6 = F_30 () ;
if ( F_37 ( V_6 ) )
return F_44 ( V_6 ) ;
V_6 -> V_47 = V_45 -> V_47 ;
V_46 = F_45 ( V_50 ) ;
if ( V_46 < 0 ) {
V_10 = V_46 ;
goto V_51;
}
V_1 = F_46 ( L_4 , & V_52 , V_6 ,
V_50 ) ;
if ( F_37 ( V_1 ) ) {
V_10 = F_38 ( V_1 ) ;
goto V_53;
}
F_12 ( V_1 ) ;
if ( V_6 -> V_47 & V_54 )
V_6 -> V_31 -> V_47 |= V_55 ;
F_28 ( V_6 ) ;
V_45 -> V_46 = V_46 ;
V_45 -> V_56 = F_47 ( V_6 -> V_31 -> V_32 . V_57 ) ;
V_45 -> V_58 = F_48 ( V_6 -> V_31 -> V_32 . V_57 ) ;
V_45 -> V_59 = V_6 -> V_31 -> V_60 ;
return V_1 ;
V_53:
F_49 ( V_46 ) ;
V_51:
F_41 ( V_6 ) ;
return F_32 ( V_10 ) ;
}
static void F_15 ( struct V_6 * V_6 )
{
F_26 ( V_6 ) ;
F_13 ( V_6 ) ;
F_50 ( V_6 -> V_31 ) ;
F_41 ( V_6 ) ;
}
static long F_51 ( struct V_1 * V_61 , unsigned int V_62 ,
unsigned long V_63 )
{
void T_2 * V_64 = ( void T_2 * ) V_63 ;
struct V_44 T_2 * V_65 ;
struct V_44 V_45 ;
struct V_1 * V_1 ;
switch ( V_62 ) {
case V_66 :
if ( ! F_52 ( V_67 ) )
return - V_68 ;
V_65 = V_64 ;
if ( F_8 ( & V_45 , V_65 ,
sizeof( V_45 ) ) )
return - V_21 ;
V_1 = F_43 ( & V_45 ) ;
if ( F_37 ( V_1 ) )
return F_38 ( V_1 ) ;
if ( F_6 ( V_65 , & V_45 ,
sizeof( V_45 ) ) ) {
F_49 ( V_45 . V_46 ) ;
F_53 ( V_1 ) ;
return - V_21 ;
}
F_54 ( V_45 . V_46 , V_1 ) ;
return 0 ;
default:
return - V_69 ;
}
}
static long F_55 ( struct V_1 * V_61 , unsigned int V_62 ,
unsigned long V_63 )
{
return F_51 ( V_61 , V_62 , ( unsigned long ) F_56 ( V_63 ) ) ;
}
static int F_57 ( void )
{
return F_58 ( & V_70 ) ;
}
static void F_59 ( void )
{
F_60 ( & V_70 ) ;
}
static int T_7 F_61 ( void )
{
int V_10 ;
V_10 = F_57 () ;
if ( V_10 ) {
F_62 ( L_5 ) ;
return V_10 ;
}
V_39 = F_63 ( L_6 ) ;
if ( ! V_39 ) {
F_62 ( L_7 ) ;
V_10 = - V_41 ;
goto V_71;
}
return 0 ;
V_71:
F_59 () ;
return V_10 ;
}
static void T_8 F_64 ( void )
{
F_65 ( V_39 ) ;
F_59 () ;
}
