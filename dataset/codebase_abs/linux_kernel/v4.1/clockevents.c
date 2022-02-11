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
return V_9 -> V_21 ( V_9 ) ;
case V_22 :
if ( ! ( V_9 -> V_17 & V_23 ) )
return - V_14 ;
return V_9 -> V_24 ( V_9 ) ;
case V_13 :
if ( ! ( V_9 -> V_17 & V_25 ) )
return - V_14 ;
return V_9 -> V_26 ( V_9 ) ;
default:
return - V_14 ;
}
}
void F_7 ( struct V_2 * V_9 ,
enum V_10 V_11 )
{
if ( V_9 -> V_11 != V_11 ) {
if ( F_6 ( V_9 , V_11 ) )
return;
V_9 -> V_11 = V_11 ;
if ( V_11 == V_13 ) {
if ( F_2 ( ! V_9 -> V_8 ) ) {
V_9 -> V_8 = 1 ;
F_3 ( 1 ) ;
}
}
}
}
void F_8 ( struct V_2 * V_9 )
{
F_7 ( V_9 , V_20 ) ;
V_9 -> V_27 . V_28 = V_29 ;
}
int F_9 ( struct V_2 * V_9 )
{
int V_30 = 0 ;
if ( V_9 -> V_12 ) {
V_9 -> V_12 ( V_31 , V_9 ) ;
V_9 -> V_16 = V_31 ;
} else if ( V_9 -> V_32 ) {
V_30 = V_9 -> V_32 ( V_9 ) ;
}
return V_30 ;
}
static int F_10 ( struct V_2 * V_9 )
{
if ( V_9 -> V_33 >= V_34 ) {
F_11 ( V_35
L_1 ) ;
V_9 -> V_27 . V_28 = V_29 ;
return - V_36 ;
}
if ( V_9 -> V_33 < 5000 )
V_9 -> V_33 = 5000 ;
else
V_9 -> V_33 += V_9 -> V_33 >> 1 ;
if ( V_9 -> V_33 > V_34 )
V_9 -> V_33 = V_34 ;
F_11 ( V_35
L_2 ,
V_9 -> V_37 ? V_9 -> V_37 : L_3 ,
( unsigned long long ) V_9 -> V_33 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_38 ;
int V_39 ;
for ( V_39 = 0 ; ; ) {
V_38 = V_9 -> V_33 ;
V_9 -> V_27 = F_13 ( F_14 () , V_38 ) ;
if ( V_9 -> V_11 == V_20 )
return 0 ;
V_9 -> V_40 ++ ;
V_5 = ( ( unsigned long long ) V_38 * V_9 -> V_8 ) >> V_9 -> V_6 ;
if ( V_9 -> V_41 ( ( unsigned long ) V_5 , V_9 ) == 0 )
return 0 ;
if ( ++ V_39 > 2 ) {
if ( F_10 ( V_9 ) )
return - V_36 ;
V_39 = 0 ;
}
}
}
static int F_12 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_38 ;
V_38 = V_9 -> V_33 ;
V_9 -> V_27 = F_13 ( F_14 () , V_38 ) ;
if ( V_9 -> V_11 == V_20 )
return 0 ;
V_9 -> V_40 ++ ;
V_5 = ( ( unsigned long long ) V_38 * V_9 -> V_8 ) >> V_9 -> V_6 ;
return V_9 -> V_41 ( ( unsigned long ) V_5 , V_9 ) ;
}
int F_15 ( struct V_2 * V_9 , T_3 V_42 ,
bool V_43 )
{
unsigned long long V_5 ;
T_2 V_38 ;
int V_44 ;
if ( F_2 ( V_42 . V_28 < 0 ) ) {
F_16 ( 1 ) ;
return - V_36 ;
}
V_9 -> V_27 = V_42 ;
if ( V_9 -> V_11 == V_20 )
return 0 ;
if ( V_9 -> V_17 & V_45 )
return V_9 -> V_46 ( V_42 , V_9 ) ;
V_38 = F_17 ( F_18 ( V_42 , F_14 () ) ) ;
if ( V_38 <= 0 )
return V_43 ? F_12 ( V_9 ) : - V_36 ;
V_38 = F_19 ( V_38 , ( T_2 ) V_9 -> V_47 ) ;
V_38 = F_20 ( V_38 , ( T_2 ) V_9 -> V_33 ) ;
V_5 = ( ( unsigned long long ) V_38 * V_9 -> V_8 ) >> V_9 -> V_6 ;
V_44 = V_9 -> V_41 ( ( unsigned long ) V_5 , V_9 ) ;
return ( V_44 && V_43 ) ? F_12 ( V_9 ) : V_44 ;
}
static void F_21 ( void )
{
struct V_2 * V_9 ;
while ( ! F_22 ( & V_48 ) ) {
V_9 = F_23 ( V_48 . V_49 ,
struct V_2 , V_50 ) ;
F_24 ( & V_9 -> V_50 ) ;
F_25 ( & V_9 -> V_50 , & V_51 ) ;
F_26 ( V_9 ) ;
}
}
static int F_27 ( struct V_2 * V_52 )
{
struct V_2 * V_9 , * V_53 = NULL ;
F_28 (dev, &clockevent_devices, list) {
if ( V_9 == V_52 || V_9 -> V_11 != V_19 )
continue;
if ( ! F_29 ( V_53 , V_9 ) )
continue;
if ( ! F_30 ( V_9 -> V_54 ) )
continue;
if ( V_53 )
F_31 ( V_53 -> V_54 ) ;
V_53 = V_9 ;
}
if ( V_53 ) {
F_32 ( V_53 ) ;
F_33 ( & V_52 -> V_50 ) ;
}
return V_53 ? 0 : - V_55 ;
}
static int F_34 ( struct V_2 * V_52 , int V_56 )
{
if ( V_52 -> V_11 == V_19 ) {
F_33 ( & V_52 -> V_50 ) ;
return 0 ;
}
return V_52 == F_35 ( V_57 , V_56 ) . V_58 ? - V_59 : - V_55 ;
}
static void F_36 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
int V_63 ;
F_37 ( & V_64 ) ;
V_63 = F_34 ( V_62 -> V_65 , F_38 () ) ;
if ( V_63 == - V_59 )
V_63 = F_27 ( V_62 -> V_65 ) ;
V_62 -> V_63 = V_63 ;
F_39 ( & V_64 ) ;
}
static int F_40 ( struct V_2 * V_52 , int V_56 )
{
struct V_61 V_62 = { . V_65 = V_52 , . V_63 = - V_66 } ;
F_41 ( V_56 , F_36 , & V_62 , 1 ) ;
return V_62 . V_63 ;
}
int F_42 ( struct V_2 * V_52 , int V_56 )
{
int V_30 ;
F_43 ( & V_67 ) ;
V_30 = F_40 ( V_52 , V_56 ) ;
F_44 ( & V_67 ) ;
return V_30 ;
}
static int F_45 ( struct V_2 * V_9 )
{
if ( V_9 -> V_12 ) {
F_3 ( V_9 -> V_24 || V_9 -> V_26 ||
V_9 -> V_21 || V_9 -> V_32 ) ;
F_46 ( V_9 -> V_16 != V_68 ) ;
return 0 ;
}
if ( V_9 -> V_17 & V_18 )
return 0 ;
if ( ! V_9 -> V_21 )
return - V_69 ;
if ( ( V_9 -> V_17 & V_23 ) &&
! V_9 -> V_24 )
return - V_69 ;
if ( ( V_9 -> V_17 & V_25 ) &&
! V_9 -> V_26 )
return - V_69 ;
return 0 ;
}
void F_47 ( struct V_2 * V_9 )
{
unsigned long V_70 ;
F_46 ( F_45 ( V_9 ) ) ;
V_9 -> V_11 = V_19 ;
if ( ! V_9 -> V_71 ) {
F_3 ( F_48 () > 1 ) ;
V_9 -> V_71 = F_49 ( F_38 () ) ;
}
F_50 ( & V_64 , V_70 ) ;
F_25 ( & V_9 -> V_50 , & V_51 ) ;
F_26 ( V_9 ) ;
F_21 () ;
F_51 ( & V_64 , V_70 ) ;
}
void F_52 ( struct V_2 * V_9 , T_4 V_72 )
{
T_1 V_73 ;
if ( ! ( V_9 -> V_17 & V_25 ) )
return;
V_73 = V_9 -> V_74 ;
F_4 ( V_73 , V_72 ) ;
if ( ! V_73 )
V_73 = 1 ;
else if ( V_73 > 600 && V_9 -> V_74 > V_75 )
V_73 = 600 ;
F_53 ( V_9 , V_72 , V_73 ) ;
V_9 -> V_33 = F_1 ( V_9 -> V_76 , V_9 , false ) ;
V_9 -> V_47 = F_1 ( V_9 -> V_74 , V_9 , true ) ;
}
void F_54 ( struct V_2 * V_9 ,
T_4 V_72 , unsigned long V_77 ,
unsigned long V_78 )
{
V_9 -> V_76 = V_77 ;
V_9 -> V_74 = V_78 ;
F_52 ( V_9 , V_72 ) ;
F_47 ( V_9 ) ;
}
int F_55 ( struct V_2 * V_9 , T_4 V_72 )
{
F_52 ( V_9 , V_72 ) ;
if ( V_9 -> V_11 == V_13 )
return F_15 ( V_9 , V_9 -> V_27 , false ) ;
if ( V_9 -> V_11 == V_22 )
return F_6 ( V_9 , V_22 ) ;
return 0 ;
}
int F_56 ( struct V_2 * V_9 , T_4 V_72 )
{
unsigned long V_70 ;
int V_30 ;
F_57 ( V_70 ) ;
V_30 = F_58 ( V_9 , V_72 ) ;
if ( V_30 == - V_66 )
V_30 = F_55 ( V_9 , V_72 ) ;
F_59 ( V_70 ) ;
return V_30 ;
}
void F_60 ( struct V_2 * V_9 )
{
}
void F_61 ( struct V_2 * V_79 ,
struct V_2 * V_80 )
{
if ( V_79 ) {
F_31 ( V_79 -> V_54 ) ;
F_7 ( V_79 , V_19 ) ;
F_24 ( & V_79 -> V_50 ) ;
F_25 ( & V_79 -> V_50 , & V_48 ) ;
}
if ( V_80 ) {
F_46 ( V_80 -> V_11 != V_19 ) ;
F_8 ( V_80 ) ;
}
}
void F_62 ( void )
{
struct V_2 * V_9 ;
F_63 (dev, &clockevent_devices, list)
if ( V_9 -> V_81 )
V_9 -> V_81 ( V_9 ) ;
}
void F_64 ( void )
{
struct V_2 * V_9 ;
F_28 (dev, &clockevent_devices, list)
if ( V_9 -> V_82 )
V_9 -> V_82 ( V_9 ) ;
}
void F_65 ( int V_56 )
{
struct V_2 * V_9 , * V_83 ;
unsigned long V_70 ;
F_50 ( & V_64 , V_70 ) ;
F_66 ( V_56 ) ;
F_67 ( V_56 ) ;
F_68 ( V_56 ) ;
F_69 (dev, tmp, &clockevents_released, list)
F_24 ( & V_9 -> V_50 ) ;
F_69 (dev, tmp, &clockevent_devices, list) {
if ( F_70 ( V_56 , V_9 -> V_71 ) &&
F_71 ( V_9 -> V_71 ) == 1 &&
! F_72 ( V_9 ) ) {
F_46 ( V_9 -> V_11 != V_19 ) ;
F_24 ( & V_9 -> V_50 ) ;
}
}
F_51 ( & V_64 , V_70 ) ;
}
static T_5 F_73 ( struct V_84 * V_9 ,
struct V_85 * V_86 ,
char * V_87 )
{
struct V_88 * V_89 ;
T_5 V_90 = 0 ;
F_74 ( & V_64 ) ;
V_89 = F_75 ( V_9 ) ;
if ( V_89 && V_89 -> V_58 )
V_90 = snprintf ( V_87 , V_91 , L_4 , V_89 -> V_58 -> V_37 ) ;
F_76 ( & V_64 ) ;
return V_90 ;
}
static T_5 F_77 ( struct V_84 * V_9 ,
struct V_85 * V_86 ,
const char * V_87 , T_6 V_90 )
{
char V_37 [ V_92 ] ;
T_5 V_30 = F_78 ( V_87 , V_37 , V_90 ) ;
struct V_2 * V_65 ;
if ( V_30 < 0 )
return V_30 ;
V_30 = - V_66 ;
F_43 ( & V_67 ) ;
F_74 ( & V_64 ) ;
F_28 (ce, &clockevent_devices, list) {
if ( ! strcmp ( V_65 -> V_37 , V_37 ) ) {
V_30 = F_34 ( V_65 , V_9 -> V_93 ) ;
break;
}
}
F_76 ( & V_64 ) ;
if ( V_30 == - V_59 )
V_30 = F_40 ( V_65 , V_9 -> V_93 ) ;
F_44 ( & V_67 ) ;
return V_30 ? V_30 : V_90 ;
}
static struct V_88 * F_75 ( struct V_84 * V_9 )
{
return V_9 == & V_94 ? F_79 () :
& F_35 ( V_57 , V_9 -> V_93 ) ;
}
static T_7 int F_80 ( void )
{
int V_95 = F_81 ( & V_94 ) ;
if ( ! V_95 )
V_95 = F_82 ( & V_94 , & V_96 ) ;
return V_95 ;
}
static struct V_88 * F_75 ( struct V_84 * V_9 )
{
return & F_35 ( V_57 , V_9 -> V_93 ) ;
}
static inline int F_80 ( void ) { return 0 ; }
static int T_7 F_83 ( void )
{
int V_56 ;
F_84 (cpu) {
struct V_84 * V_9 = & F_35 ( V_97 , V_56 ) ;
int V_95 ;
V_9 -> V_93 = V_56 ;
V_9 -> V_98 = & V_99 ;
V_95 = F_81 ( V_9 ) ;
if ( ! V_95 )
V_95 = F_82 ( V_9 , & V_96 ) ;
if ( ! V_95 )
V_95 = F_82 ( V_9 , & V_100 ) ;
if ( V_95 )
return V_95 ;
}
return F_80 () ;
}
static int T_7 F_85 ( void )
{
int V_95 = F_86 ( & V_99 , NULL ) ;
if ( ! V_95 )
V_95 = F_83 () ;
return V_95 ;
}
