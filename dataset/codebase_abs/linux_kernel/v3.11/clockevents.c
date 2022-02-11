T_1 F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 = ( T_1 ) V_1 << V_3 -> V_5 ;
if ( F_2 ( ! V_3 -> V_6 ) ) {
V_3 -> V_6 = 1 ;
F_3 ( 1 ) ;
}
F_4 ( V_4 , V_3 -> V_6 ) ;
if ( V_4 < 1000 )
V_4 = 1000 ;
if ( V_4 > V_7 )
V_4 = V_7 ;
return V_4 ;
}
void F_5 ( struct V_2 * V_8 ,
enum V_9 V_10 )
{
if ( V_8 -> V_10 != V_10 ) {
V_8 -> V_11 ( V_10 , V_8 ) ;
V_8 -> V_10 = V_10 ;
if ( V_10 == V_12 ) {
if ( F_2 ( ! V_8 -> V_6 ) ) {
V_8 -> V_6 = 1 ;
F_3 ( 1 ) ;
}
}
}
}
void F_6 ( struct V_2 * V_8 )
{
F_5 ( V_8 , V_13 ) ;
V_8 -> V_14 . V_15 = V_7 ;
}
static int F_7 ( struct V_2 * V_8 )
{
if ( V_8 -> V_16 >= V_17 ) {
F_8 ( V_18 L_1 ) ;
V_8 -> V_14 . V_15 = V_7 ;
return - V_19 ;
}
if ( V_8 -> V_16 < 5000 )
V_8 -> V_16 = 5000 ;
else
V_8 -> V_16 += V_8 -> V_16 >> 1 ;
if ( V_8 -> V_16 > V_17 )
V_8 -> V_16 = V_17 ;
F_8 ( V_18 L_2 ,
V_8 -> V_20 ? V_8 -> V_20 : L_3 ,
( unsigned long long ) V_8 -> V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_8 )
{
unsigned long long V_4 ;
T_2 V_21 ;
int V_22 ;
for ( V_22 = 0 ; ; ) {
V_21 = V_8 -> V_16 ;
V_8 -> V_14 = F_10 ( F_11 () , V_21 ) ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
V_8 -> V_23 ++ ;
V_4 = ( ( unsigned long long ) V_21 * V_8 -> V_6 ) >> V_8 -> V_5 ;
if ( V_8 -> V_24 ( ( unsigned long ) V_4 , V_8 ) == 0 )
return 0 ;
if ( ++ V_22 > 2 ) {
if ( F_7 ( V_8 ) )
return - V_19 ;
V_22 = 0 ;
}
}
}
static int F_9 ( struct V_2 * V_8 )
{
unsigned long long V_4 ;
T_2 V_21 ;
V_21 = V_8 -> V_16 ;
V_8 -> V_14 = F_10 ( F_11 () , V_21 ) ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
V_8 -> V_23 ++ ;
V_4 = ( ( unsigned long long ) V_21 * V_8 -> V_6 ) >> V_8 -> V_5 ;
return V_8 -> V_24 ( ( unsigned long ) V_4 , V_8 ) ;
}
int F_12 ( struct V_2 * V_8 , T_3 V_25 ,
bool V_26 )
{
unsigned long long V_4 ;
T_2 V_21 ;
int V_27 ;
if ( F_2 ( V_25 . V_15 < 0 ) ) {
F_13 ( 1 ) ;
return - V_19 ;
}
V_8 -> V_14 = V_25 ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
if ( V_8 -> V_28 & V_29 )
return V_8 -> V_30 ( V_25 , V_8 ) ;
V_21 = F_14 ( F_15 ( V_25 , F_11 () ) ) ;
if ( V_21 <= 0 )
return V_26 ? F_9 ( V_8 ) : - V_19 ;
V_21 = F_16 ( V_21 , ( T_2 ) V_8 -> V_31 ) ;
V_21 = F_17 ( V_21 , ( T_2 ) V_8 -> V_16 ) ;
V_4 = ( ( unsigned long long ) V_21 * V_8 -> V_6 ) >> V_8 -> V_5 ;
V_27 = V_8 -> V_24 ( ( unsigned long ) V_4 , V_8 ) ;
return ( V_27 && V_26 ) ? F_9 ( V_8 ) : V_27 ;
}
static void F_18 ( void )
{
struct V_2 * V_8 ;
while ( ! F_19 ( & V_32 ) ) {
V_8 = F_20 ( V_32 . V_33 ,
struct V_2 , V_34 ) ;
F_21 ( & V_8 -> V_34 ) ;
F_22 ( & V_8 -> V_34 , & V_35 ) ;
F_23 ( V_8 ) ;
}
}
static int F_24 ( struct V_2 * V_36 )
{
struct V_2 * V_8 , * V_37 = NULL ;
F_25 (dev, &clockevent_devices, list) {
if ( V_8 == V_36 || V_8 -> V_10 != V_38 )
continue;
if ( ! F_26 ( V_37 , V_8 ) )
continue;
if ( ! F_27 ( V_8 -> V_39 ) )
continue;
if ( V_37 )
F_28 ( V_37 -> V_39 ) ;
V_37 = V_8 ;
}
if ( V_37 ) {
F_29 ( V_37 ) ;
F_30 ( & V_36 -> V_34 ) ;
}
return V_37 ? 0 : - V_40 ;
}
static int F_31 ( struct V_2 * V_36 , int V_41 )
{
if ( V_36 -> V_10 == V_38 ) {
F_30 ( & V_36 -> V_34 ) ;
return 0 ;
}
return V_36 == F_32 ( V_42 , V_41 ) . V_43 ? - V_44 : - V_40 ;
}
static void F_33 ( void * V_45 )
{
struct V_46 * V_47 = V_45 ;
int V_48 ;
F_34 ( & V_49 ) ;
V_48 = F_31 ( V_47 -> V_50 , F_35 () ) ;
if ( V_48 == - V_44 )
V_48 = F_24 ( V_47 -> V_50 ) ;
V_47 -> V_48 = V_48 ;
F_36 ( & V_49 ) ;
}
static int F_37 ( struct V_2 * V_36 , int V_41 )
{
struct V_46 V_47 = { . V_50 = V_36 , . V_48 = - V_51 } ;
F_38 ( V_41 , F_33 , & V_47 , 1 ) ;
return V_47 . V_48 ;
}
int F_39 ( struct V_2 * V_36 , int V_41 )
{
int V_52 ;
F_40 ( & V_53 ) ;
V_52 = F_37 ( V_36 , V_41 ) ;
F_41 ( & V_53 ) ;
return V_52 ;
}
void F_42 ( struct V_2 * V_8 )
{
unsigned long V_54 ;
F_43 ( V_8 -> V_10 != V_38 ) ;
if ( ! V_8 -> V_55 ) {
F_3 ( F_44 () > 1 ) ;
V_8 -> V_55 = F_45 ( F_35 () ) ;
}
F_46 ( & V_49 , V_54 ) ;
F_22 ( & V_8 -> V_34 , & V_35 ) ;
F_23 ( V_8 ) ;
F_18 () ;
F_47 ( & V_49 , V_54 ) ;
}
void F_48 ( struct V_2 * V_8 , T_4 V_56 )
{
T_1 V_57 ;
if ( ! ( V_8 -> V_28 & V_58 ) )
return;
V_57 = V_8 -> V_59 ;
F_4 ( V_57 , V_56 ) ;
if ( ! V_57 )
V_57 = 1 ;
else if ( V_57 > 600 && V_8 -> V_59 > V_60 )
V_57 = 600 ;
F_49 ( V_8 , V_56 , V_57 ) ;
V_8 -> V_16 = F_1 ( V_8 -> V_61 , V_8 ) ;
V_8 -> V_31 = F_1 ( V_8 -> V_59 , V_8 ) ;
}
void F_50 ( struct V_2 * V_8 ,
T_4 V_56 , unsigned long V_62 ,
unsigned long V_63 )
{
V_8 -> V_61 = V_62 ;
V_8 -> V_59 = V_63 ;
F_48 ( V_8 , V_56 ) ;
F_42 ( V_8 ) ;
}
int F_51 ( struct V_2 * V_8 , T_4 V_56 )
{
F_48 ( V_8 , V_56 ) ;
if ( V_8 -> V_10 != V_12 )
return 0 ;
return F_12 ( V_8 , V_8 -> V_14 , false ) ;
}
void F_52 ( struct V_2 * V_8 )
{
}
void F_53 ( struct V_2 * V_64 ,
struct V_2 * V_65 )
{
unsigned long V_54 ;
F_54 ( V_54 ) ;
if ( V_64 ) {
F_28 ( V_64 -> V_39 ) ;
F_5 ( V_64 , V_38 ) ;
F_21 ( & V_64 -> V_34 ) ;
F_22 ( & V_64 -> V_34 , & V_32 ) ;
}
if ( V_65 ) {
F_43 ( V_65 -> V_10 != V_38 ) ;
F_6 ( V_65 ) ;
}
F_55 ( V_54 ) ;
}
void F_56 ( void )
{
struct V_2 * V_8 ;
F_57 (dev, &clockevent_devices, list)
if ( V_8 -> V_66 )
V_8 -> V_66 ( V_8 ) ;
}
void F_58 ( void )
{
struct V_2 * V_8 ;
F_25 (dev, &clockevent_devices, list)
if ( V_8 -> V_67 )
V_8 -> V_67 ( V_8 ) ;
}
void F_59 ( unsigned long V_68 , void * V_45 )
{
struct V_2 * V_8 , * V_69 ;
unsigned long V_54 ;
int V_41 ;
F_46 ( & V_49 , V_54 ) ;
switch ( V_68 ) {
case V_70 :
case V_71 :
case V_72 :
F_60 ( V_68 , V_45 ) ;
break;
case V_73 :
case V_74 :
F_61 ( V_68 ) ;
break;
case V_75 :
F_62 ( V_45 ) ;
break;
case V_76 :
F_63 () ;
F_64 () ;
break;
case V_77 :
F_65 () ;
break;
case V_78 :
F_66 ( V_45 ) ;
F_67 ( V_45 ) ;
F_68 ( V_45 ) ;
F_69 (dev, tmp, &clockevents_released, list)
F_21 ( & V_8 -> V_34 ) ;
V_41 = * ( ( int * ) V_45 ) ;
F_69 (dev, tmp, &clockevent_devices, list) {
if ( F_70 ( V_41 , V_8 -> V_55 ) &&
F_71 ( V_8 -> V_55 ) == 1 &&
! F_72 ( V_8 ) ) {
F_43 ( V_8 -> V_10 != V_38 ) ;
F_21 ( & V_8 -> V_34 ) ;
}
}
break;
default:
break;
}
F_47 ( & V_49 , V_54 ) ;
}
static T_5 F_73 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
char * V_82 )
{
struct V_83 * V_84 ;
T_5 V_85 = 0 ;
F_74 ( & V_49 ) ;
V_84 = F_75 ( V_8 ) ;
if ( V_84 && V_84 -> V_43 )
V_85 = snprintf ( V_82 , V_86 , L_4 , V_84 -> V_43 -> V_20 ) ;
F_76 ( & V_49 ) ;
return V_85 ;
}
static T_5 F_77 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_6 V_85 )
{
char V_20 [ V_87 ] ;
T_6 V_52 = F_78 ( V_82 , V_20 , V_85 ) ;
struct V_2 * V_50 ;
if ( V_52 < 0 )
return V_52 ;
V_52 = - V_51 ;
F_40 ( & V_53 ) ;
F_74 ( & V_49 ) ;
F_25 (ce, &clockevent_devices, list) {
if ( ! strcmp ( V_50 -> V_20 , V_20 ) ) {
V_52 = F_31 ( V_50 , V_8 -> V_88 ) ;
break;
}
}
F_76 ( & V_49 ) ;
if ( V_52 == - V_44 )
V_52 = F_37 ( V_50 , V_8 -> V_88 ) ;
F_41 ( & V_53 ) ;
return V_52 ? V_52 : V_85 ;
}
static struct V_83 * F_75 ( struct V_79 * V_8 )
{
return V_8 == & V_89 ? F_79 () :
& F_32 ( V_42 , V_8 -> V_88 ) ;
}
static T_7 int F_80 ( void )
{
int V_90 = F_81 ( & V_89 ) ;
if ( ! V_90 )
V_90 = F_82 ( & V_89 , & V_91 ) ;
return V_90 ;
}
static struct V_83 * F_75 ( struct V_79 * V_8 )
{
return & F_32 ( V_42 , V_8 -> V_88 ) ;
}
static inline int F_80 ( void ) { return 0 ; }
static int T_7 F_83 ( void )
{
int V_41 ;
F_84 (cpu) {
struct V_79 * V_8 = & F_32 ( V_92 , V_41 ) ;
int V_90 ;
V_8 -> V_88 = V_41 ;
V_8 -> V_93 = & V_94 ;
V_90 = F_81 ( V_8 ) ;
if ( ! V_90 )
V_90 = F_82 ( V_8 , & V_91 ) ;
if ( ! V_90 )
V_90 = F_82 ( V_8 , & V_95 ) ;
if ( V_90 )
return V_90 ;
}
return F_80 () ;
}
static int T_7 F_85 ( void )
{
int V_90 = F_86 ( & V_94 , NULL ) ;
if ( ! V_90 )
V_90 = F_83 () ;
return V_90 ;
}
