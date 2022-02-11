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
V_9 -> V_27 . V_28 = V_29 ;
}
int F_13 ( struct V_2 * V_9 )
{
int V_30 = 0 ;
if ( V_9 -> V_31 )
V_30 = V_9 -> V_31 ( V_9 ) ;
return V_30 ;
}
static int F_14 ( struct V_2 * V_9 )
{
if ( V_9 -> V_32 >= V_33 ) {
F_15 ( V_34
L_2 ) ;
V_9 -> V_27 . V_28 = V_29 ;
return - V_35 ;
}
if ( V_9 -> V_32 < 5000 )
V_9 -> V_32 = 5000 ;
else
V_9 -> V_32 += V_9 -> V_32 >> 1 ;
if ( V_9 -> V_32 > V_33 )
V_9 -> V_32 = V_33 ;
F_15 ( V_34
L_3 ,
V_9 -> V_36 ? V_9 -> V_36 : L_4 ,
( unsigned long long ) V_9 -> V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_37 ;
int V_38 ;
for ( V_38 = 0 ; ; ) {
V_37 = V_9 -> V_32 ;
V_9 -> V_27 = F_17 ( F_18 () , V_37 ) ;
if ( F_19 ( V_9 ) )
return 0 ;
V_9 -> V_39 ++ ;
V_5 = ( ( unsigned long long ) V_37 * V_9 -> V_8 ) >> V_9 -> V_6 ;
if ( V_9 -> V_40 ( ( unsigned long ) V_5 , V_9 ) == 0 )
return 0 ;
if ( ++ V_38 > 2 ) {
if ( F_14 ( V_9 ) )
return - V_35 ;
V_38 = 0 ;
}
}
}
static int F_16 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_37 ;
V_37 = V_9 -> V_32 ;
V_9 -> V_27 = F_17 ( F_18 () , V_37 ) ;
if ( F_19 ( V_9 ) )
return 0 ;
V_9 -> V_39 ++ ;
V_5 = ( ( unsigned long long ) V_37 * V_9 -> V_8 ) >> V_9 -> V_6 ;
return V_9 -> V_40 ( ( unsigned long ) V_5 , V_9 ) ;
}
int F_20 ( struct V_2 * V_9 , T_3 V_41 ,
bool V_42 )
{
unsigned long long V_5 ;
T_2 V_37 ;
int V_43 ;
if ( F_2 ( V_41 . V_28 < 0 ) ) {
F_21 ( 1 ) ;
return - V_35 ;
}
V_9 -> V_27 = V_41 ;
if ( F_19 ( V_9 ) )
return 0 ;
F_7 ( ! F_8 ( V_9 ) , L_1 ,
F_9 ( V_9 ) ) ;
if ( V_9 -> V_12 & V_44 )
return V_9 -> V_45 ( V_41 , V_9 ) ;
V_37 = F_22 ( F_23 ( V_41 , F_18 () ) ) ;
if ( V_37 <= 0 )
return V_42 ? F_16 ( V_9 ) : - V_35 ;
V_37 = F_24 ( V_37 , ( T_2 ) V_9 -> V_46 ) ;
V_37 = F_25 ( V_37 , ( T_2 ) V_9 -> V_32 ) ;
V_5 = ( ( unsigned long long ) V_37 * V_9 -> V_8 ) >> V_9 -> V_6 ;
V_43 = V_9 -> V_40 ( ( unsigned long ) V_5 , V_9 ) ;
return ( V_43 && V_42 ) ? F_16 ( V_9 ) : V_43 ;
}
static void F_26 ( void )
{
struct V_2 * V_9 ;
while ( ! F_27 ( & V_47 ) ) {
V_9 = F_28 ( V_47 . V_48 ,
struct V_2 , V_49 ) ;
F_29 ( & V_9 -> V_49 ) ;
F_30 ( & V_9 -> V_49 , & V_50 ) ;
F_31 ( V_9 ) ;
}
}
static int F_32 ( struct V_2 * V_51 )
{
struct V_2 * V_9 , * V_52 = NULL ;
F_33 (dev, &clockevent_devices, list) {
if ( V_9 == V_51 || ! F_34 ( V_9 ) )
continue;
if ( ! F_35 ( V_52 , V_9 ) )
continue;
if ( ! F_36 ( V_9 -> V_53 ) )
continue;
if ( V_52 )
F_37 ( V_52 -> V_53 ) ;
V_52 = V_9 ;
}
if ( V_52 ) {
F_38 ( V_52 ) ;
F_39 ( & V_51 -> V_49 ) ;
}
return V_52 ? 0 : - V_54 ;
}
static int F_40 ( struct V_2 * V_51 , int V_55 )
{
if ( F_34 ( V_51 ) ) {
F_39 ( & V_51 -> V_49 ) ;
return 0 ;
}
return V_51 == F_41 ( V_56 , V_55 ) . V_57 ? - V_58 : - V_54 ;
}
static void F_42 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
int V_62 ;
F_43 ( & V_63 ) ;
V_62 = F_40 ( V_61 -> V_64 , F_44 () ) ;
if ( V_62 == - V_58 )
V_62 = F_32 ( V_61 -> V_64 ) ;
V_61 -> V_62 = V_62 ;
F_45 ( & V_63 ) ;
}
static int F_46 ( struct V_2 * V_51 , int V_55 )
{
struct V_60 V_61 = { . V_64 = V_51 , . V_62 = - V_65 } ;
F_47 ( V_55 , F_42 , & V_61 , 1 ) ;
return V_61 . V_62 ;
}
int F_48 ( struct V_2 * V_51 , int V_55 )
{
int V_30 ;
F_49 ( & V_66 ) ;
V_30 = F_46 ( V_51 , V_55 ) ;
F_50 ( & V_66 ) ;
return V_30 ;
}
void F_51 ( struct V_2 * V_9 )
{
unsigned long V_67 ;
F_11 ( V_9 , V_14 ) ;
if ( ! V_9 -> V_68 ) {
F_3 ( F_52 () > 1 ) ;
V_9 -> V_68 = F_53 ( F_44 () ) ;
}
F_54 ( & V_63 , V_67 ) ;
F_30 ( & V_9 -> V_49 , & V_50 ) ;
F_31 ( V_9 ) ;
F_26 () ;
F_55 ( & V_63 , V_67 ) ;
}
void F_56 ( struct V_2 * V_9 , T_4 V_69 )
{
T_1 V_70 ;
if ( ! ( V_9 -> V_12 & V_22 ) )
return;
V_70 = V_9 -> V_71 ;
F_4 ( V_70 , V_69 ) ;
if ( ! V_70 )
V_70 = 1 ;
else if ( V_70 > 600 && V_9 -> V_71 > V_72 )
V_70 = 600 ;
F_57 ( V_9 , V_69 , V_70 ) ;
V_9 -> V_32 = F_1 ( V_9 -> V_73 , V_9 , false ) ;
V_9 -> V_46 = F_1 ( V_9 -> V_71 , V_9 , true ) ;
}
void F_58 ( struct V_2 * V_9 ,
T_4 V_69 , unsigned long V_74 ,
unsigned long V_75 )
{
V_9 -> V_73 = V_74 ;
V_9 -> V_71 = V_75 ;
F_56 ( V_9 , V_69 ) ;
F_51 ( V_9 ) ;
}
int F_59 ( struct V_2 * V_9 , T_4 V_69 )
{
F_56 ( V_9 , V_69 ) ;
if ( F_8 ( V_9 ) )
return F_20 ( V_9 , V_9 -> V_27 , false ) ;
if ( F_60 ( V_9 ) )
return F_6 ( V_9 , V_17 ) ;
return 0 ;
}
int F_61 ( struct V_2 * V_9 , T_4 V_69 )
{
unsigned long V_67 ;
int V_30 ;
F_62 ( V_67 ) ;
V_30 = F_63 ( V_9 , V_69 ) ;
if ( V_30 == - V_65 )
V_30 = F_59 ( V_9 , V_69 ) ;
F_64 ( V_67 ) ;
return V_30 ;
}
void F_65 ( struct V_2 * V_9 )
{
}
void F_66 ( struct V_2 * V_76 ,
struct V_2 * V_77 )
{
if ( V_76 ) {
F_37 ( V_76 -> V_53 ) ;
F_10 ( V_76 , V_14 ) ;
F_29 ( & V_76 -> V_49 ) ;
F_30 ( & V_76 -> V_49 , & V_47 ) ;
}
if ( V_77 ) {
F_67 ( ! F_34 ( V_77 ) ) ;
F_12 ( V_77 ) ;
}
}
void F_68 ( void )
{
struct V_2 * V_9 ;
F_69 (dev, &clockevent_devices, list)
if ( V_9 -> V_78 && ! F_34 ( V_9 ) )
V_9 -> V_78 ( V_9 ) ;
}
void F_70 ( void )
{
struct V_2 * V_9 ;
F_33 (dev, &clockevent_devices, list)
if ( V_9 -> V_79 && ! F_34 ( V_9 ) )
V_9 -> V_79 ( V_9 ) ;
}
void F_71 ( int V_55 )
{
struct V_2 * V_9 , * V_80 ;
unsigned long V_67 ;
F_54 ( & V_63 , V_67 ) ;
F_72 ( V_55 ) ;
F_73 ( V_55 ) ;
F_74 ( V_55 ) ;
F_75 (dev, tmp, &clockevents_released, list)
F_29 ( & V_9 -> V_49 ) ;
F_75 (dev, tmp, &clockevent_devices, list) {
if ( F_76 ( V_55 , V_9 -> V_68 ) &&
F_77 ( V_9 -> V_68 ) == 1 &&
! F_78 ( V_9 ) ) {
F_67 ( ! F_34 ( V_9 ) ) ;
F_29 ( & V_9 -> V_49 ) ;
}
}
F_55 ( & V_63 , V_67 ) ;
}
static T_5 F_79 ( struct V_81 * V_9 ,
struct V_82 * V_83 ,
char * V_84 )
{
struct V_85 * V_86 ;
T_5 V_87 = 0 ;
F_80 ( & V_63 ) ;
V_86 = F_81 ( V_9 ) ;
if ( V_86 && V_86 -> V_57 )
V_87 = snprintf ( V_84 , V_88 , L_5 , V_86 -> V_57 -> V_36 ) ;
F_82 ( & V_63 ) ;
return V_87 ;
}
static T_5 F_83 ( struct V_81 * V_9 ,
struct V_82 * V_83 ,
const char * V_84 , T_6 V_87 )
{
char V_36 [ V_89 ] ;
T_5 V_30 = F_84 ( V_84 , V_36 , V_87 ) ;
struct V_2 * V_64 ;
if ( V_30 < 0 )
return V_30 ;
V_30 = - V_65 ;
F_49 ( & V_66 ) ;
F_80 ( & V_63 ) ;
F_33 (ce, &clockevent_devices, list) {
if ( ! strcmp ( V_64 -> V_36 , V_36 ) ) {
V_30 = F_40 ( V_64 , V_9 -> V_90 ) ;
break;
}
}
F_82 ( & V_63 ) ;
if ( V_30 == - V_58 )
V_30 = F_46 ( V_64 , V_9 -> V_90 ) ;
F_50 ( & V_66 ) ;
return V_30 ? V_30 : V_87 ;
}
static struct V_85 * F_81 ( struct V_81 * V_9 )
{
return V_9 == & V_91 ? F_85 () :
& F_41 ( V_56 , V_9 -> V_90 ) ;
}
static T_7 int F_86 ( void )
{
int V_92 = F_87 ( & V_91 ) ;
if ( ! V_92 )
V_92 = F_88 ( & V_91 , & V_93 ) ;
return V_92 ;
}
static struct V_85 * F_81 ( struct V_81 * V_9 )
{
return & F_41 ( V_56 , V_9 -> V_90 ) ;
}
static inline int F_86 ( void ) { return 0 ; }
static int T_7 F_89 ( void )
{
int V_55 ;
F_90 (cpu) {
struct V_81 * V_9 = & F_41 ( V_94 , V_55 ) ;
int V_92 ;
V_9 -> V_90 = V_55 ;
V_9 -> V_95 = & V_96 ;
V_92 = F_87 ( V_9 ) ;
if ( ! V_92 )
V_92 = F_88 ( V_9 , & V_93 ) ;
if ( ! V_92 )
V_92 = F_88 ( V_9 , & V_97 ) ;
if ( V_92 )
return V_92 ;
}
return F_86 () ;
}
static int T_7 F_91 ( void )
{
int V_92 = F_92 ( & V_96 , NULL ) ;
if ( ! V_92 )
V_92 = F_89 () ;
return V_92 ;
}
