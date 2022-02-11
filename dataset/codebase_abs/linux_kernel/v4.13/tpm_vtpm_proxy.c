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
static int F_19 ( struct V_30 * V_31 ,
T_6 * V_3 , T_3 V_4 )
{
struct V_34 * V_35 = (struct V_34 * ) V_3 ;
if ( V_4 < sizeof( struct V_34 ) )
return 0 ;
if ( V_31 -> V_36 & V_37 ) {
switch ( F_20 ( V_35 -> V_38 ) ) {
case V_39 :
return 1 ;
}
} else {
switch ( F_20 ( V_35 -> V_38 ) ) {
case V_40 :
return 1 ;
}
}
return 0 ;
}
static int F_21 ( struct V_30 * V_31 , T_6 * V_3 , T_3 V_4 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
int V_10 = 0 ;
if ( V_4 > sizeof( V_6 -> V_19 ) ) {
F_18 ( & V_31 -> V_32 ,
L_3 ,
V_4 , sizeof( V_6 -> V_19 ) ) ;
return - V_18 ;
}
if ( ! ( V_6 -> V_13 & V_41 ) &&
F_19 ( V_31 , V_3 , V_4 ) )
return - V_21 ;
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
static void F_22 ( struct V_30 * V_31 )
{
}
static T_6 F_23 ( struct V_30 * V_31 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
if ( V_6 -> V_22 )
return V_42 ;
return 0 ;
}
static bool F_24 ( struct V_30 * V_31 , T_6 V_43 )
{
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
bool V_24 ;
F_3 ( & V_6 -> V_16 ) ;
V_24 = ! ( V_6 -> V_13 & V_14 ) ;
F_4 ( & V_6 -> V_16 ) ;
return V_24 ;
}
static int F_25 ( struct V_30 * V_31 , int V_44 )
{
struct V_45 V_3 ;
int V_10 ;
const struct V_46 * V_47 ;
struct V_6 * V_6 = F_17 ( & V_31 -> V_32 ) ;
if ( V_31 -> V_36 & V_37 )
V_10 = F_26 ( & V_3 , V_48 ,
V_39 ) ;
else
V_10 = F_26 ( & V_3 , V_49 ,
V_40 ) ;
if ( V_10 )
return V_10 ;
F_27 ( & V_3 , V_44 ) ;
V_6 -> V_13 |= V_41 ;
V_10 = F_28 ( V_31 , NULL , V_3 . V_50 , F_29 ( & V_3 ) , 0 ,
V_51 | V_52 ,
L_4 ) ;
V_6 -> V_13 &= ~ V_41 ;
if ( V_10 < 0 ) {
V_44 = V_10 ;
goto V_33;
}
V_47 = ( const struct V_46 * ) V_3 . V_50 ;
V_10 = F_20 ( V_47 -> V_53 ) ;
if ( V_10 )
V_44 = - 1 ;
V_33:
F_30 ( & V_3 ) ;
return V_44 ;
}
static void F_31 ( struct V_54 * V_55 )
{
struct V_6 * V_6 = F_32 ( V_55 , struct V_6 ,
V_55 ) ;
int V_10 ;
V_10 = F_33 ( V_6 -> V_31 ) ;
if ( V_10 )
F_13 ( V_6 ) ;
else
V_6 -> V_13 |= V_56 ;
}
static void F_34 ( struct V_6 * V_6 )
{
F_13 ( V_6 ) ;
F_35 ( & V_6 -> V_55 ) ;
}
static inline void F_36 ( struct V_6 * V_6 )
{
F_37 ( V_57 , & V_6 -> V_55 ) ;
}
static struct V_6 * F_38 ( void )
{
struct V_6 * V_6 ;
struct V_30 * V_31 ;
int V_58 ;
V_6 = F_39 ( sizeof( * V_6 ) , V_59 ) ;
if ( V_6 == NULL )
return F_40 ( - V_60 ) ;
F_41 ( & V_6 -> V_11 ) ;
F_42 ( & V_6 -> V_16 ) ;
F_43 ( & V_6 -> V_55 , F_31 ) ;
V_31 = F_44 ( NULL , & V_61 ) ;
if ( F_45 ( V_31 ) ) {
V_58 = F_46 ( V_31 ) ;
goto V_62;
}
F_47 ( & V_31 -> V_32 , V_6 ) ;
V_6 -> V_31 = V_31 ;
return V_6 ;
V_62:
F_48 ( V_6 ) ;
return F_40 ( V_58 ) ;
}
static inline void F_49 ( struct V_6 * V_6 )
{
F_50 ( & V_6 -> V_31 -> V_32 ) ;
F_48 ( V_6 ) ;
}
static struct V_1 * F_51 (
struct V_63 * V_64 )
{
struct V_6 * V_6 ;
int V_10 , V_65 ;
struct V_1 * V_1 ;
if ( V_64 -> V_36 & ~ V_66 )
return F_40 ( - V_67 ) ;
V_6 = F_38 () ;
if ( F_45 ( V_6 ) )
return F_52 ( V_6 ) ;
V_6 -> V_36 = V_64 -> V_36 ;
V_65 = F_53 ( V_68 ) ;
if ( V_65 < 0 ) {
V_10 = V_65 ;
goto V_69;
}
V_1 = F_54 ( L_5 , & V_70 , V_6 ,
V_68 ) ;
if ( F_45 ( V_1 ) ) {
V_10 = F_46 ( V_1 ) ;
goto V_71;
}
F_12 ( V_1 ) ;
if ( V_6 -> V_36 & V_72 )
V_6 -> V_31 -> V_36 |= V_37 ;
F_36 ( V_6 ) ;
V_64 -> V_65 = V_65 ;
V_64 -> V_73 = F_55 ( V_6 -> V_31 -> V_32 . V_74 ) ;
V_64 -> V_75 = F_56 ( V_6 -> V_31 -> V_32 . V_74 ) ;
V_64 -> V_76 = V_6 -> V_31 -> V_77 ;
return V_1 ;
V_71:
F_57 ( V_65 ) ;
V_69:
F_49 ( V_6 ) ;
return F_40 ( V_10 ) ;
}
static void F_15 ( struct V_6 * V_6 )
{
F_34 ( V_6 ) ;
F_13 ( V_6 ) ;
if ( V_6 -> V_13 & V_56 )
F_58 ( V_6 -> V_31 ) ;
F_49 ( V_6 ) ;
}
static long F_59 ( struct V_1 * V_1 , unsigned int V_78 ,
unsigned long V_79 )
{
void T_2 * V_80 = ( void T_2 * ) V_79 ;
struct V_63 T_2 * V_81 ;
struct V_63 V_64 ;
struct V_1 * V_82 ;
if ( ! F_60 ( V_83 ) )
return - V_84 ;
V_81 = V_80 ;
if ( F_8 ( & V_64 , V_81 ,
sizeof( V_64 ) ) )
return - V_21 ;
V_82 = F_51 ( & V_64 ) ;
if ( F_45 ( V_82 ) )
return F_46 ( V_82 ) ;
if ( F_6 ( V_81 , & V_64 ,
sizeof( V_64 ) ) ) {
F_57 ( V_64 . V_65 ) ;
F_61 ( V_82 ) ;
return - V_21 ;
}
F_62 ( V_64 . V_65 , V_82 ) ;
return 0 ;
}
static long F_63 ( struct V_1 * V_85 , unsigned int V_78 ,
unsigned long V_79 )
{
switch ( V_78 ) {
case V_86 :
return F_59 ( V_85 , V_78 , V_79 ) ;
default:
return - V_87 ;
}
}
static long F_64 ( struct V_1 * V_85 , unsigned int V_78 ,
unsigned long V_79 )
{
return F_63 ( V_85 , V_78 , ( unsigned long ) F_65 ( V_79 ) ) ;
}
static int F_66 ( void )
{
return F_67 ( & V_88 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_88 ) ;
}
static int T_7 F_70 ( void )
{
int V_10 ;
V_10 = F_66 () ;
if ( V_10 ) {
F_71 ( L_6 ) ;
return V_10 ;
}
V_57 = F_72 ( L_7 ) ;
if ( ! V_57 ) {
F_71 ( L_8 ) ;
V_10 = - V_60 ;
goto V_89;
}
return 0 ;
V_89:
F_68 () ;
return V_10 ;
}
static void T_8 F_73 ( void )
{
F_74 ( V_57 ) ;
F_68 () ;
}
