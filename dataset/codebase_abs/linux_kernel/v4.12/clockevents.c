static T_1 F_1 ( unsigned long V_1 , struct V_2 * V_3 ,
bool V_4 )
{
T_1 V_5 = ( T_1 ) V_1 << V_3 -> V_6 ;
T_1 V_7 ;
if ( F_2 ( ! V_3 -> V_8 ) ) {
V_3 -> V_8 = 1 ;
F_3 ( 1 ) ;
}
V_7 = ( T_1 ) V_3 -> V_8 - 1 ;
if ( ( V_5 >> V_3 -> V_6 ) != ( T_1 ) V_1 )
V_5 = ~ 0ULL ;
if ( ( ~ 0ULL - V_5 > V_7 ) &&
( ! V_4 || V_3 -> V_8 <= ( 1ULL << V_3 -> V_6 ) ) )
V_5 += V_7 ;
F_4 ( V_5 , V_3 -> V_8 ) ;
return V_5 > 1000 ? V_5 : 1000 ;
}
T_1 F_5 ( unsigned long V_1 , struct V_2 * V_3 )
{
return F_1 ( V_1 , V_3 , false ) ;
}
static int F_6 ( struct V_2 * V_9 ,
enum V_10 V_11 )
{
if ( V_9 -> V_12 & V_13 )
return 0 ;
switch ( V_11 ) {
case V_14 :
case V_15 :
if ( V_9 -> V_16 )
return V_9 -> V_16 ( V_9 ) ;
return 0 ;
case V_17 :
if ( ! ( V_9 -> V_12 & V_18 ) )
return - V_19 ;
if ( V_9 -> V_20 )
return V_9 -> V_20 ( V_9 ) ;
return 0 ;
case V_21 :
if ( ! ( V_9 -> V_12 & V_22 ) )
return - V_19 ;
if ( V_9 -> V_23 )
return V_9 -> V_23 ( V_9 ) ;
return 0 ;
case V_24 :
if ( F_7 ( ! F_8 ( V_9 ) ,
L_1 ,
F_9 ( V_9 ) ) )
return - V_25 ;
if ( V_9 -> V_26 )
return V_9 -> V_26 ( V_9 ) ;
else
return - V_19 ;
default:
return - V_19 ;
}
}
void F_10 ( struct V_2 * V_9 ,
enum V_10 V_11 )
{
if ( F_9 ( V_9 ) != V_11 ) {
if ( F_6 ( V_9 , V_11 ) )
return;
F_11 ( V_9 , V_11 ) ;
if ( F_8 ( V_9 ) ) {
if ( F_2 ( ! V_9 -> V_8 ) ) {
V_9 -> V_8 = 1 ;
F_3 ( 1 ) ;
}
}
}
}
void F_12 ( struct V_2 * V_9 )
{
F_10 ( V_9 , V_15 ) ;
V_9 -> V_27 = V_28 ;
}
int F_13 ( struct V_2 * V_9 )
{
int V_29 = 0 ;
if ( V_9 -> V_30 )
V_29 = V_9 -> V_30 ( V_9 ) ;
return V_29 ;
}
static int F_14 ( struct V_2 * V_9 )
{
if ( V_9 -> V_31 >= V_32 ) {
F_15 ( V_33
L_2 ) ;
V_9 -> V_27 = V_28 ;
return - V_34 ;
}
if ( V_9 -> V_31 < 5000 )
V_9 -> V_31 = 5000 ;
else
V_9 -> V_31 += V_9 -> V_31 >> 1 ;
if ( V_9 -> V_31 > V_32 )
V_9 -> V_31 = V_32 ;
F_15 ( V_33
L_3 ,
V_9 -> V_35 ? V_9 -> V_35 : L_4 ,
( unsigned long long ) V_9 -> V_31 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_36 ;
int V_37 ;
for ( V_37 = 0 ; ; ) {
V_36 = V_9 -> V_31 ;
V_9 -> V_27 = F_17 ( F_18 () , V_36 ) ;
if ( F_19 ( V_9 ) )
return 0 ;
V_9 -> V_38 ++ ;
V_5 = ( ( unsigned long long ) V_36 * V_9 -> V_8 ) >> V_9 -> V_6 ;
if ( V_9 -> V_39 ( ( unsigned long ) V_5 , V_9 ) == 0 )
return 0 ;
if ( ++ V_37 > 2 ) {
if ( F_14 ( V_9 ) )
return - V_34 ;
V_37 = 0 ;
}
}
}
static int F_16 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_36 ;
V_36 = V_9 -> V_31 ;
V_9 -> V_27 = F_17 ( F_18 () , V_36 ) ;
if ( F_19 ( V_9 ) )
return 0 ;
V_9 -> V_38 ++ ;
V_5 = ( ( unsigned long long ) V_36 * V_9 -> V_8 ) >> V_9 -> V_6 ;
return V_9 -> V_39 ( ( unsigned long ) V_5 , V_9 ) ;
}
int F_20 ( struct V_2 * V_9 , T_3 V_40 ,
bool V_41 )
{
unsigned long long V_5 ;
T_2 V_36 ;
int V_42 ;
if ( F_2 ( V_40 < 0 ) ) {
F_21 ( 1 ) ;
return - V_34 ;
}
V_9 -> V_27 = V_40 ;
if ( F_19 ( V_9 ) )
return 0 ;
F_7 ( ! F_8 ( V_9 ) , L_1 ,
F_9 ( V_9 ) ) ;
if ( V_9 -> V_12 & V_43 )
return V_9 -> V_44 ( V_40 , V_9 ) ;
V_36 = F_22 ( F_23 ( V_40 , F_18 () ) ) ;
if ( V_36 <= 0 )
return V_41 ? F_16 ( V_9 ) : - V_34 ;
V_36 = F_24 ( V_36 , ( T_2 ) V_9 -> V_45 ) ;
V_36 = F_25 ( V_36 , ( T_2 ) V_9 -> V_31 ) ;
V_5 = ( ( unsigned long long ) V_36 * V_9 -> V_8 ) >> V_9 -> V_6 ;
V_42 = V_9 -> V_39 ( ( unsigned long ) V_5 , V_9 ) ;
return ( V_42 && V_41 ) ? F_16 ( V_9 ) : V_42 ;
}
static void F_26 ( void )
{
struct V_2 * V_9 ;
while ( ! F_27 ( & V_46 ) ) {
V_9 = F_28 ( V_46 . V_47 ,
struct V_2 , V_48 ) ;
F_29 ( & V_9 -> V_48 ) ;
F_30 ( & V_9 -> V_48 , & V_49 ) ;
F_31 ( V_9 ) ;
}
}
static int F_32 ( struct V_2 * V_50 )
{
struct V_2 * V_9 , * V_51 = NULL ;
F_33 (dev, &clockevent_devices, list) {
if ( V_9 == V_50 || ! F_34 ( V_9 ) )
continue;
if ( ! F_35 ( V_51 , V_9 ) )
continue;
if ( ! F_36 ( V_9 -> V_52 ) )
continue;
if ( V_51 )
F_37 ( V_51 -> V_52 ) ;
V_51 = V_9 ;
}
if ( V_51 ) {
F_38 ( V_51 ) ;
F_39 ( & V_50 -> V_48 ) ;
}
return V_51 ? 0 : - V_53 ;
}
static int F_40 ( struct V_2 * V_50 , int V_54 )
{
if ( F_34 ( V_50 ) ) {
F_39 ( & V_50 -> V_48 ) ;
return 0 ;
}
return V_50 == F_41 ( V_55 , V_54 ) . V_56 ? - V_57 : - V_53 ;
}
static void F_42 ( void * V_58 )
{
struct V_59 * V_60 = V_58 ;
int V_61 ;
F_43 ( & V_62 ) ;
V_61 = F_40 ( V_60 -> V_63 , F_44 () ) ;
if ( V_61 == - V_57 )
V_61 = F_32 ( V_60 -> V_63 ) ;
V_60 -> V_61 = V_61 ;
F_45 ( & V_62 ) ;
}
static int F_46 ( struct V_2 * V_50 , int V_54 )
{
struct V_59 V_60 = { . V_63 = V_50 , . V_61 = - V_64 } ;
F_47 ( V_54 , F_42 , & V_60 , 1 ) ;
return V_60 . V_61 ;
}
int F_48 ( struct V_2 * V_50 , int V_54 )
{
int V_29 ;
F_49 ( & V_65 ) ;
V_29 = F_46 ( V_50 , V_54 ) ;
F_50 ( & V_65 ) ;
return V_29 ;
}
void F_51 ( struct V_2 * V_9 )
{
unsigned long V_66 ;
F_11 ( V_9 , V_14 ) ;
if ( ! V_9 -> V_67 ) {
F_3 ( F_52 () > 1 ) ;
V_9 -> V_67 = F_53 ( F_44 () ) ;
}
F_54 ( & V_62 , V_66 ) ;
F_30 ( & V_9 -> V_48 , & V_49 ) ;
F_31 ( V_9 ) ;
F_26 () ;
F_55 ( & V_62 , V_66 ) ;
}
static void F_56 ( struct V_2 * V_9 , T_4 V_68 )
{
T_1 V_69 ;
if ( ! ( V_9 -> V_12 & V_22 ) )
return;
V_69 = V_9 -> V_70 ;
F_4 ( V_69 , V_68 ) ;
if ( ! V_69 )
V_69 = 1 ;
else if ( V_69 > 600 && V_9 -> V_70 > V_71 )
V_69 = 600 ;
F_57 ( V_9 , V_68 , V_69 ) ;
V_9 -> V_31 = F_1 ( V_9 -> V_72 , V_9 , false ) ;
V_9 -> V_45 = F_1 ( V_9 -> V_70 , V_9 , true ) ;
}
void F_58 ( struct V_2 * V_9 ,
T_4 V_68 , unsigned long V_73 ,
unsigned long V_74 )
{
V_9 -> V_72 = V_73 ;
V_9 -> V_70 = V_74 ;
F_56 ( V_9 , V_68 ) ;
F_51 ( V_9 ) ;
}
int F_59 ( struct V_2 * V_9 , T_4 V_68 )
{
F_56 ( V_9 , V_68 ) ;
if ( F_8 ( V_9 ) )
return F_20 ( V_9 , V_9 -> V_27 , false ) ;
if ( F_60 ( V_9 ) )
return F_6 ( V_9 , V_17 ) ;
return 0 ;
}
int F_61 ( struct V_2 * V_9 , T_4 V_68 )
{
unsigned long V_66 ;
int V_29 ;
F_62 ( V_66 ) ;
V_29 = F_63 ( V_9 , V_68 ) ;
if ( V_29 == - V_64 )
V_29 = F_59 ( V_9 , V_68 ) ;
F_64 ( V_66 ) ;
return V_29 ;
}
void F_65 ( struct V_2 * V_9 )
{
}
void F_66 ( struct V_2 * V_75 ,
struct V_2 * V_76 )
{
if ( V_75 ) {
F_37 ( V_75 -> V_52 ) ;
F_10 ( V_75 , V_14 ) ;
F_29 ( & V_75 -> V_48 ) ;
F_30 ( & V_75 -> V_48 , & V_46 ) ;
}
if ( V_76 ) {
F_67 ( ! F_34 ( V_76 ) ) ;
F_12 ( V_76 ) ;
}
}
void F_68 ( void )
{
struct V_2 * V_9 ;
F_69 (dev, &clockevent_devices, list)
if ( V_9 -> V_77 && ! F_34 ( V_9 ) )
V_9 -> V_77 ( V_9 ) ;
}
void F_70 ( void )
{
struct V_2 * V_9 ;
F_33 (dev, &clockevent_devices, list)
if ( V_9 -> V_78 && ! F_34 ( V_9 ) )
V_9 -> V_78 ( V_9 ) ;
}
void F_71 ( int V_54 )
{
struct V_2 * V_9 , * V_79 ;
unsigned long V_66 ;
F_54 ( & V_62 , V_66 ) ;
F_72 ( V_54 ) ;
F_73 ( V_54 ) ;
F_74 ( V_54 ) ;
F_75 (dev, tmp, &clockevents_released, list)
F_29 ( & V_9 -> V_48 ) ;
F_75 (dev, tmp, &clockevent_devices, list) {
if ( F_76 ( V_54 , V_9 -> V_67 ) &&
F_77 ( V_9 -> V_67 ) == 1 &&
! F_78 ( V_9 ) ) {
F_67 ( ! F_34 ( V_9 ) ) ;
F_29 ( & V_9 -> V_48 ) ;
}
}
F_55 ( & V_62 , V_66 ) ;
}
static T_5 F_79 ( struct V_80 * V_9 ,
struct V_81 * V_82 ,
char * V_83 )
{
struct V_84 * V_85 ;
T_5 V_86 = 0 ;
F_80 ( & V_62 ) ;
V_85 = F_81 ( V_9 ) ;
if ( V_85 && V_85 -> V_56 )
V_86 = snprintf ( V_83 , V_87 , L_5 , V_85 -> V_56 -> V_35 ) ;
F_82 ( & V_62 ) ;
return V_86 ;
}
static T_5 F_83 ( struct V_80 * V_9 ,
struct V_81 * V_82 ,
const char * V_83 , T_6 V_86 )
{
char V_35 [ V_88 ] ;
T_5 V_29 = F_84 ( V_83 , V_35 , V_86 ) ;
struct V_2 * V_63 ;
if ( V_29 < 0 )
return V_29 ;
V_29 = - V_64 ;
F_49 ( & V_65 ) ;
F_80 ( & V_62 ) ;
F_33 (ce, &clockevent_devices, list) {
if ( ! strcmp ( V_63 -> V_35 , V_35 ) ) {
V_29 = F_40 ( V_63 , V_9 -> V_89 ) ;
break;
}
}
F_82 ( & V_62 ) ;
if ( V_29 == - V_57 )
V_29 = F_46 ( V_63 , V_9 -> V_89 ) ;
F_50 ( & V_65 ) ;
return V_29 ? V_29 : V_86 ;
}
static struct V_84 * F_81 ( struct V_80 * V_9 )
{
return V_9 == & V_90 ? F_85 () :
& F_41 ( V_55 , V_9 -> V_89 ) ;
}
static T_7 int F_86 ( void )
{
int V_91 = F_87 ( & V_90 ) ;
if ( ! V_91 )
V_91 = F_88 ( & V_90 , & V_92 ) ;
return V_91 ;
}
static struct V_84 * F_81 ( struct V_80 * V_9 )
{
return & F_41 ( V_55 , V_9 -> V_89 ) ;
}
static inline int F_86 ( void ) { return 0 ; }
static int T_7 F_89 ( void )
{
int V_54 ;
F_90 (cpu) {
struct V_80 * V_9 = & F_41 ( V_93 , V_54 ) ;
int V_91 ;
V_9 -> V_89 = V_54 ;
V_9 -> V_94 = & V_95 ;
V_91 = F_87 ( V_9 ) ;
if ( ! V_91 )
V_91 = F_88 ( V_9 , & V_92 ) ;
if ( ! V_91 )
V_91 = F_88 ( V_9 , & V_96 ) ;
if ( V_91 )
return V_91 ;
}
return F_86 () ;
}
static int T_7 F_91 ( void )
{
int V_91 = F_92 ( & V_95 , NULL ) ;
if ( ! V_91 )
V_91 = F_89 () ;
return V_91 ;
}
