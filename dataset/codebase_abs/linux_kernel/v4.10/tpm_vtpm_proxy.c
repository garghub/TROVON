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
F_13 ( V_6 ) ;
else
V_6 -> V_13 |= V_38 ;
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
int V_40 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_41 ) ;
if ( V_6 == NULL )
return F_32 ( - V_42 ) ;
F_33 ( & V_6 -> V_11 ) ;
F_34 ( & V_6 -> V_16 ) ;
F_35 ( & V_6 -> V_37 , F_23 ) ;
V_31 = F_36 ( NULL , & V_43 ) ;
if ( F_37 ( V_31 ) ) {
V_40 = F_38 ( V_31 ) ;
goto V_44;
}
F_39 ( & V_31 -> V_32 , V_6 ) ;
V_6 -> V_31 = V_31 ;
return V_6 ;
V_44:
F_40 ( V_6 ) ;
return F_32 ( V_40 ) ;
}
static inline void F_41 ( struct V_6 * V_6 )
{
F_42 ( & V_6 -> V_31 -> V_32 ) ;
F_40 ( V_6 ) ;
}
static struct V_1 * F_43 (
struct V_45 * V_46 )
{
struct V_6 * V_6 ;
int V_10 , V_47 ;
struct V_1 * V_1 ;
if ( V_46 -> V_48 & ~ V_49 )
return F_32 ( - V_50 ) ;
V_6 = F_30 () ;
if ( F_37 ( V_6 ) )
return F_44 ( V_6 ) ;
V_6 -> V_48 = V_46 -> V_48 ;
V_47 = F_45 ( V_51 ) ;
if ( V_47 < 0 ) {
V_10 = V_47 ;
goto V_52;
}
V_1 = F_46 ( L_4 , & V_53 , V_6 ,
V_51 ) ;
if ( F_37 ( V_1 ) ) {
V_10 = F_38 ( V_1 ) ;
goto V_54;
}
F_12 ( V_1 ) ;
if ( V_6 -> V_48 & V_55 )
V_6 -> V_31 -> V_48 |= V_56 ;
F_28 ( V_6 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_57 = F_47 ( V_6 -> V_31 -> V_32 . V_58 ) ;
V_46 -> V_59 = F_48 ( V_6 -> V_31 -> V_32 . V_58 ) ;
V_46 -> V_60 = V_6 -> V_31 -> V_61 ;
return V_1 ;
V_54:
F_49 ( V_47 ) ;
V_52:
F_41 ( V_6 ) ;
return F_32 ( V_10 ) ;
}
static void F_15 ( struct V_6 * V_6 )
{
F_26 ( V_6 ) ;
F_13 ( V_6 ) ;
if ( V_6 -> V_13 & V_38 )
F_50 ( V_6 -> V_31 ) ;
F_41 ( V_6 ) ;
}
static long F_51 ( struct V_1 * V_1 , unsigned int V_62 ,
unsigned long V_63 )
{
void T_2 * V_64 = ( void T_2 * ) V_63 ;
struct V_45 T_2 * V_65 ;
struct V_45 V_46 ;
struct V_1 * V_66 ;
if ( ! F_52 ( V_67 ) )
return - V_68 ;
V_65 = V_64 ;
if ( F_8 ( & V_46 , V_65 ,
sizeof( V_46 ) ) )
return - V_21 ;
V_66 = F_43 ( & V_46 ) ;
if ( F_37 ( V_66 ) )
return F_38 ( V_66 ) ;
if ( F_6 ( V_65 , & V_46 ,
sizeof( V_46 ) ) ) {
F_49 ( V_46 . V_47 ) ;
F_53 ( V_66 ) ;
return - V_21 ;
}
F_54 ( V_46 . V_47 , V_66 ) ;
return 0 ;
}
static long F_55 ( struct V_1 * V_69 , unsigned int V_62 ,
unsigned long V_63 )
{
switch ( V_62 ) {
case V_70 :
return F_51 ( V_69 , V_62 , V_63 ) ;
default:
return - V_71 ;
}
}
static long F_56 ( struct V_1 * V_69 , unsigned int V_62 ,
unsigned long V_63 )
{
return F_55 ( V_69 , V_62 , ( unsigned long ) F_57 ( V_63 ) ) ;
}
static int F_58 ( void )
{
return F_59 ( & V_72 ) ;
}
static void F_60 ( void )
{
F_61 ( & V_72 ) ;
}
static int T_7 F_62 ( void )
{
int V_10 ;
V_10 = F_58 () ;
if ( V_10 ) {
F_63 ( L_5 ) ;
return V_10 ;
}
V_39 = F_64 ( L_6 ) ;
if ( ! V_39 ) {
F_63 ( L_7 ) ;
V_10 = - V_42 ;
goto V_73;
}
return 0 ;
V_73:
F_60 () ;
return V_10 ;
}
static void T_8 F_65 ( void )
{
F_66 ( V_39 ) ;
F_60 () ;
}
