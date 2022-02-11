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
if ( V_9 -> V_12 ) {
if ( V_11 > V_13 )
return - V_14 ;
V_9 -> V_12 ( (enum V_15 ) V_11 , V_9 ) ;
V_9 -> V_16 = (enum V_15 ) V_11 ;
return 0 ;
}
if ( V_9 -> V_17 & V_18 )
return 0 ;
switch ( V_11 ) {
case V_19 :
case V_20 :
if ( V_9 -> V_21 )
return V_9 -> V_21 ( V_9 ) ;
return 0 ;
case V_22 :
if ( ! ( V_9 -> V_17 & V_23 ) )
return - V_14 ;
if ( V_9 -> V_24 )
return V_9 -> V_24 ( V_9 ) ;
return 0 ;
case V_13 :
if ( ! ( V_9 -> V_17 & V_25 ) )
return - V_14 ;
if ( V_9 -> V_26 )
return V_9 -> V_26 ( V_9 ) ;
return 0 ;
case V_27 :
if ( F_7 ( ! F_8 ( V_9 ) ,
L_1 ,
F_9 ( V_9 ) ) )
return - V_28 ;
if ( V_9 -> V_29 )
return V_9 -> V_29 ( V_9 ) ;
else
return - V_14 ;
default:
return - V_14 ;
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
F_10 ( V_9 , V_20 ) ;
V_9 -> V_30 . V_31 = V_32 ;
}
int F_13 ( struct V_2 * V_9 )
{
int V_33 = 0 ;
if ( V_9 -> V_12 ) {
V_9 -> V_12 ( V_34 , V_9 ) ;
V_9 -> V_16 = V_34 ;
} else if ( V_9 -> V_35 ) {
V_33 = V_9 -> V_35 ( V_9 ) ;
}
return V_33 ;
}
static int F_14 ( struct V_2 * V_9 )
{
if ( V_9 -> V_36 >= V_37 ) {
F_15 ( V_38
L_2 ) ;
V_9 -> V_30 . V_31 = V_32 ;
return - V_39 ;
}
if ( V_9 -> V_36 < 5000 )
V_9 -> V_36 = 5000 ;
else
V_9 -> V_36 += V_9 -> V_36 >> 1 ;
if ( V_9 -> V_36 > V_37 )
V_9 -> V_36 = V_37 ;
F_15 ( V_38
L_3 ,
V_9 -> V_40 ? V_9 -> V_40 : L_4 ,
( unsigned long long ) V_9 -> V_36 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_41 ;
int V_42 ;
for ( V_42 = 0 ; ; ) {
V_41 = V_9 -> V_36 ;
V_9 -> V_30 = F_17 ( F_18 () , V_41 ) ;
if ( F_19 ( V_9 ) )
return 0 ;
V_9 -> V_43 ++ ;
V_5 = ( ( unsigned long long ) V_41 * V_9 -> V_8 ) >> V_9 -> V_6 ;
if ( V_9 -> V_44 ( ( unsigned long ) V_5 , V_9 ) == 0 )
return 0 ;
if ( ++ V_42 > 2 ) {
if ( F_14 ( V_9 ) )
return - V_39 ;
V_42 = 0 ;
}
}
}
static int F_16 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_41 ;
V_41 = V_9 -> V_36 ;
V_9 -> V_30 = F_17 ( F_18 () , V_41 ) ;
if ( F_19 ( V_9 ) )
return 0 ;
V_9 -> V_43 ++ ;
V_5 = ( ( unsigned long long ) V_41 * V_9 -> V_8 ) >> V_9 -> V_6 ;
return V_9 -> V_44 ( ( unsigned long ) V_5 , V_9 ) ;
}
int F_20 ( struct V_2 * V_9 , T_3 V_45 ,
bool V_46 )
{
unsigned long long V_5 ;
T_2 V_41 ;
int V_47 ;
if ( F_2 ( V_45 . V_31 < 0 ) ) {
F_21 ( 1 ) ;
return - V_39 ;
}
V_9 -> V_30 = V_45 ;
if ( F_19 ( V_9 ) )
return 0 ;
F_7 ( ! F_8 ( V_9 ) , L_1 ,
F_9 ( V_9 ) ) ;
if ( V_9 -> V_17 & V_48 )
return V_9 -> V_49 ( V_45 , V_9 ) ;
V_41 = F_22 ( F_23 ( V_45 , F_18 () ) ) ;
if ( V_41 <= 0 )
return V_46 ? F_16 ( V_9 ) : - V_39 ;
V_41 = F_24 ( V_41 , ( T_2 ) V_9 -> V_50 ) ;
V_41 = F_25 ( V_41 , ( T_2 ) V_9 -> V_36 ) ;
V_5 = ( ( unsigned long long ) V_41 * V_9 -> V_8 ) >> V_9 -> V_6 ;
V_47 = V_9 -> V_44 ( ( unsigned long ) V_5 , V_9 ) ;
return ( V_47 && V_46 ) ? F_16 ( V_9 ) : V_47 ;
}
static void F_26 ( void )
{
struct V_2 * V_9 ;
while ( ! F_27 ( & V_51 ) ) {
V_9 = F_28 ( V_51 . V_52 ,
struct V_2 , V_53 ) ;
F_29 ( & V_9 -> V_53 ) ;
F_30 ( & V_9 -> V_53 , & V_54 ) ;
F_31 ( V_9 ) ;
}
}
static int F_32 ( struct V_2 * V_55 )
{
struct V_2 * V_9 , * V_56 = NULL ;
F_33 (dev, &clockevent_devices, list) {
if ( V_9 == V_55 || ! F_34 ( V_9 ) )
continue;
if ( ! F_35 ( V_56 , V_9 ) )
continue;
if ( ! F_36 ( V_9 -> V_57 ) )
continue;
if ( V_56 )
F_37 ( V_56 -> V_57 ) ;
V_56 = V_9 ;
}
if ( V_56 ) {
F_38 ( V_56 ) ;
F_39 ( & V_55 -> V_53 ) ;
}
return V_56 ? 0 : - V_58 ;
}
static int F_40 ( struct V_2 * V_55 , int V_59 )
{
if ( F_34 ( V_55 ) ) {
F_39 ( & V_55 -> V_53 ) ;
return 0 ;
}
return V_55 == F_41 ( V_60 , V_59 ) . V_61 ? - V_62 : - V_58 ;
}
static void F_42 ( void * V_63 )
{
struct V_64 * V_65 = V_63 ;
int V_66 ;
F_43 ( & V_67 ) ;
V_66 = F_40 ( V_65 -> V_68 , F_44 () ) ;
if ( V_66 == - V_62 )
V_66 = F_32 ( V_65 -> V_68 ) ;
V_65 -> V_66 = V_66 ;
F_45 ( & V_67 ) ;
}
static int F_46 ( struct V_2 * V_55 , int V_59 )
{
struct V_64 V_65 = { . V_68 = V_55 , . V_66 = - V_69 } ;
F_47 ( V_59 , F_42 , & V_65 , 1 ) ;
return V_65 . V_66 ;
}
int F_48 ( struct V_2 * V_55 , int V_59 )
{
int V_33 ;
F_49 ( & V_70 ) ;
V_33 = F_46 ( V_55 , V_59 ) ;
F_50 ( & V_70 ) ;
return V_33 ;
}
static int F_51 ( struct V_2 * V_9 )
{
if ( V_9 -> V_12 ) {
F_3 ( V_9 -> V_24 || V_9 -> V_26 ||
V_9 -> V_21 || V_9 -> V_35 ||
V_9 -> V_29 ) ;
F_52 ( V_9 -> V_16 != V_71 ) ;
return 0 ;
}
if ( V_9 -> V_17 & V_18 )
return 0 ;
return 0 ;
}
void F_53 ( struct V_2 * V_9 )
{
unsigned long V_72 ;
F_52 ( F_51 ( V_9 ) ) ;
F_11 ( V_9 , V_19 ) ;
if ( ! V_9 -> V_73 ) {
F_3 ( F_54 () > 1 ) ;
V_9 -> V_73 = F_55 ( F_44 () ) ;
}
F_56 ( & V_67 , V_72 ) ;
F_30 ( & V_9 -> V_53 , & V_54 ) ;
F_31 ( V_9 ) ;
F_26 () ;
F_57 ( & V_67 , V_72 ) ;
}
void F_58 ( struct V_2 * V_9 , T_4 V_74 )
{
T_1 V_75 ;
if ( ! ( V_9 -> V_17 & V_25 ) )
return;
V_75 = V_9 -> V_76 ;
F_4 ( V_75 , V_74 ) ;
if ( ! V_75 )
V_75 = 1 ;
else if ( V_75 > 600 && V_9 -> V_76 > V_77 )
V_75 = 600 ;
F_59 ( V_9 , V_74 , V_75 ) ;
V_9 -> V_36 = F_1 ( V_9 -> V_78 , V_9 , false ) ;
V_9 -> V_50 = F_1 ( V_9 -> V_76 , V_9 , true ) ;
}
void F_60 ( struct V_2 * V_9 ,
T_4 V_74 , unsigned long V_79 ,
unsigned long V_80 )
{
V_9 -> V_78 = V_79 ;
V_9 -> V_76 = V_80 ;
F_58 ( V_9 , V_74 ) ;
F_53 ( V_9 ) ;
}
int F_61 ( struct V_2 * V_9 , T_4 V_74 )
{
F_58 ( V_9 , V_74 ) ;
if ( F_8 ( V_9 ) )
return F_20 ( V_9 , V_9 -> V_30 , false ) ;
if ( F_62 ( V_9 ) )
return F_6 ( V_9 , V_22 ) ;
return 0 ;
}
int F_63 ( struct V_2 * V_9 , T_4 V_74 )
{
unsigned long V_72 ;
int V_33 ;
F_64 ( V_72 ) ;
V_33 = F_65 ( V_9 , V_74 ) ;
if ( V_33 == - V_69 )
V_33 = F_61 ( V_9 , V_74 ) ;
F_66 ( V_72 ) ;
return V_33 ;
}
void F_67 ( struct V_2 * V_9 )
{
}
void F_68 ( struct V_2 * V_81 ,
struct V_2 * V_82 )
{
if ( V_81 ) {
F_37 ( V_81 -> V_57 ) ;
F_10 ( V_81 , V_19 ) ;
F_29 ( & V_81 -> V_53 ) ;
F_30 ( & V_81 -> V_53 , & V_51 ) ;
}
if ( V_82 ) {
F_52 ( ! F_34 ( V_82 ) ) ;
F_12 ( V_82 ) ;
}
}
void F_69 ( void )
{
struct V_2 * V_9 ;
F_70 (dev, &clockevent_devices, list)
if ( V_9 -> V_83 && ! F_34 ( V_9 ) )
V_9 -> V_83 ( V_9 ) ;
}
void F_71 ( void )
{
struct V_2 * V_9 ;
F_33 (dev, &clockevent_devices, list)
if ( V_9 -> V_84 && ! F_34 ( V_9 ) )
V_9 -> V_84 ( V_9 ) ;
}
void F_72 ( int V_59 )
{
struct V_2 * V_9 , * V_85 ;
unsigned long V_72 ;
F_56 ( & V_67 , V_72 ) ;
F_73 ( V_59 ) ;
F_74 ( V_59 ) ;
F_75 ( V_59 ) ;
F_76 (dev, tmp, &clockevents_released, list)
F_29 ( & V_9 -> V_53 ) ;
F_76 (dev, tmp, &clockevent_devices, list) {
if ( F_77 ( V_59 , V_9 -> V_73 ) &&
F_78 ( V_9 -> V_73 ) == 1 &&
! F_79 ( V_9 ) ) {
F_52 ( ! F_34 ( V_9 ) ) ;
F_29 ( & V_9 -> V_53 ) ;
}
}
F_57 ( & V_67 , V_72 ) ;
}
static T_5 F_80 ( struct V_86 * V_9 ,
struct V_87 * V_88 ,
char * V_89 )
{
struct V_90 * V_91 ;
T_5 V_92 = 0 ;
F_81 ( & V_67 ) ;
V_91 = F_82 ( V_9 ) ;
if ( V_91 && V_91 -> V_61 )
V_92 = snprintf ( V_89 , V_93 , L_5 , V_91 -> V_61 -> V_40 ) ;
F_83 ( & V_67 ) ;
return V_92 ;
}
static T_5 F_84 ( struct V_86 * V_9 ,
struct V_87 * V_88 ,
const char * V_89 , T_6 V_92 )
{
char V_40 [ V_94 ] ;
T_5 V_33 = F_85 ( V_89 , V_40 , V_92 ) ;
struct V_2 * V_68 ;
if ( V_33 < 0 )
return V_33 ;
V_33 = - V_69 ;
F_49 ( & V_70 ) ;
F_81 ( & V_67 ) ;
F_33 (ce, &clockevent_devices, list) {
if ( ! strcmp ( V_68 -> V_40 , V_40 ) ) {
V_33 = F_40 ( V_68 , V_9 -> V_95 ) ;
break;
}
}
F_83 ( & V_67 ) ;
if ( V_33 == - V_62 )
V_33 = F_46 ( V_68 , V_9 -> V_95 ) ;
F_50 ( & V_70 ) ;
return V_33 ? V_33 : V_92 ;
}
static struct V_90 * F_82 ( struct V_86 * V_9 )
{
return V_9 == & V_96 ? F_86 () :
& F_41 ( V_60 , V_9 -> V_95 ) ;
}
static T_7 int F_87 ( void )
{
int V_97 = F_88 ( & V_96 ) ;
if ( ! V_97 )
V_97 = F_89 ( & V_96 , & V_98 ) ;
return V_97 ;
}
static struct V_90 * F_82 ( struct V_86 * V_9 )
{
return & F_41 ( V_60 , V_9 -> V_95 ) ;
}
static inline int F_87 ( void ) { return 0 ; }
static int T_7 F_90 ( void )
{
int V_59 ;
F_91 (cpu) {
struct V_86 * V_9 = & F_41 ( V_99 , V_59 ) ;
int V_97 ;
V_9 -> V_95 = V_59 ;
V_9 -> V_100 = & V_101 ;
V_97 = F_88 ( V_9 ) ;
if ( ! V_97 )
V_97 = F_89 ( V_9 , & V_98 ) ;
if ( ! V_97 )
V_97 = F_89 ( V_9 , & V_102 ) ;
if ( V_97 )
return V_97 ;
}
return F_87 () ;
}
static int T_7 F_92 ( void )
{
int V_97 = F_93 ( & V_101 , NULL ) ;
if ( ! V_97 )
V_97 = F_90 () ;
return V_97 ;
}
