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
( ! V_4 || V_3 -> V_8 <= ( 1U << V_3 -> V_6 ) ) )
V_5 += V_7 ;
F_4 ( V_5 , V_3 -> V_8 ) ;
return V_5 > 1000 ? V_5 : 1000 ;
}
T_1 F_5 ( unsigned long V_1 , struct V_2 * V_3 )
{
return F_1 ( V_1 , V_3 , false ) ;
}
void F_6 ( struct V_2 * V_9 ,
enum V_10 V_11 )
{
if ( V_9 -> V_11 != V_11 ) {
V_9 -> V_12 ( V_11 , V_9 ) ;
V_9 -> V_11 = V_11 ;
if ( V_11 == V_13 ) {
if ( F_2 ( ! V_9 -> V_8 ) ) {
V_9 -> V_8 = 1 ;
F_3 ( 1 ) ;
}
}
}
}
void F_7 ( struct V_2 * V_9 )
{
F_6 ( V_9 , V_14 ) ;
V_9 -> V_15 . V_16 = V_17 ;
}
static int F_8 ( struct V_2 * V_9 )
{
if ( V_9 -> V_18 >= V_19 ) {
F_9 ( V_20 L_1 ) ;
V_9 -> V_15 . V_16 = V_17 ;
return - V_21 ;
}
if ( V_9 -> V_18 < 5000 )
V_9 -> V_18 = 5000 ;
else
V_9 -> V_18 += V_9 -> V_18 >> 1 ;
if ( V_9 -> V_18 > V_19 )
V_9 -> V_18 = V_19 ;
F_9 ( V_20 L_2 ,
V_9 -> V_22 ? V_9 -> V_22 : L_3 ,
( unsigned long long ) V_9 -> V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_23 ;
int V_24 ;
for ( V_24 = 0 ; ; ) {
V_23 = V_9 -> V_18 ;
V_9 -> V_15 = F_11 ( F_12 () , V_23 ) ;
if ( V_9 -> V_11 == V_14 )
return 0 ;
V_9 -> V_25 ++ ;
V_5 = ( ( unsigned long long ) V_23 * V_9 -> V_8 ) >> V_9 -> V_6 ;
if ( V_9 -> V_26 ( ( unsigned long ) V_5 , V_9 ) == 0 )
return 0 ;
if ( ++ V_24 > 2 ) {
if ( F_8 ( V_9 ) )
return - V_21 ;
V_24 = 0 ;
}
}
}
static int F_10 ( struct V_2 * V_9 )
{
unsigned long long V_5 ;
T_2 V_23 ;
V_23 = V_9 -> V_18 ;
V_9 -> V_15 = F_11 ( F_12 () , V_23 ) ;
if ( V_9 -> V_11 == V_14 )
return 0 ;
V_9 -> V_25 ++ ;
V_5 = ( ( unsigned long long ) V_23 * V_9 -> V_8 ) >> V_9 -> V_6 ;
return V_9 -> V_26 ( ( unsigned long ) V_5 , V_9 ) ;
}
int F_13 ( struct V_2 * V_9 , T_3 V_27 ,
bool V_28 )
{
unsigned long long V_5 ;
T_2 V_23 ;
int V_29 ;
if ( F_2 ( V_27 . V_16 < 0 ) ) {
F_14 ( 1 ) ;
return - V_21 ;
}
V_9 -> V_15 = V_27 ;
if ( V_9 -> V_11 == V_14 )
return 0 ;
if ( V_9 -> V_30 & V_31 )
return V_9 -> V_32 ( V_27 , V_9 ) ;
V_23 = F_15 ( F_16 ( V_27 , F_12 () ) ) ;
if ( V_23 <= 0 )
return V_28 ? F_10 ( V_9 ) : - V_21 ;
V_23 = F_17 ( V_23 , ( T_2 ) V_9 -> V_33 ) ;
V_23 = F_18 ( V_23 , ( T_2 ) V_9 -> V_18 ) ;
V_5 = ( ( unsigned long long ) V_23 * V_9 -> V_8 ) >> V_9 -> V_6 ;
V_29 = V_9 -> V_26 ( ( unsigned long ) V_5 , V_9 ) ;
return ( V_29 && V_28 ) ? F_10 ( V_9 ) : V_29 ;
}
static void F_19 ( void )
{
struct V_2 * V_9 ;
while ( ! F_20 ( & V_34 ) ) {
V_9 = F_21 ( V_34 . V_35 ,
struct V_2 , V_36 ) ;
F_22 ( & V_9 -> V_36 ) ;
F_23 ( & V_9 -> V_36 , & V_37 ) ;
F_24 ( V_9 ) ;
}
}
static int F_25 ( struct V_2 * V_38 )
{
struct V_2 * V_9 , * V_39 = NULL ;
F_26 (dev, &clockevent_devices, list) {
if ( V_9 == V_38 || V_9 -> V_11 != V_40 )
continue;
if ( ! F_27 ( V_39 , V_9 ) )
continue;
if ( ! F_28 ( V_9 -> V_41 ) )
continue;
if ( V_39 )
F_29 ( V_39 -> V_41 ) ;
V_39 = V_9 ;
}
if ( V_39 ) {
F_30 ( V_39 ) ;
F_31 ( & V_38 -> V_36 ) ;
}
return V_39 ? 0 : - V_42 ;
}
static int F_32 ( struct V_2 * V_38 , int V_43 )
{
if ( V_38 -> V_11 == V_40 ) {
F_31 ( & V_38 -> V_36 ) ;
return 0 ;
}
return V_38 == F_33 ( V_44 , V_43 ) . V_45 ? - V_46 : - V_42 ;
}
static void F_34 ( void * V_47 )
{
struct V_48 * V_49 = V_47 ;
int V_50 ;
F_35 ( & V_51 ) ;
V_50 = F_32 ( V_49 -> V_52 , F_36 () ) ;
if ( V_50 == - V_46 )
V_50 = F_25 ( V_49 -> V_52 ) ;
V_49 -> V_50 = V_50 ;
F_37 ( & V_51 ) ;
}
static int F_38 ( struct V_2 * V_38 , int V_43 )
{
struct V_48 V_49 = { . V_52 = V_38 , . V_50 = - V_53 } ;
F_39 ( V_43 , F_34 , & V_49 , 1 ) ;
return V_49 . V_50 ;
}
int F_40 ( struct V_2 * V_38 , int V_43 )
{
int V_54 ;
F_41 ( & V_55 ) ;
V_54 = F_38 ( V_38 , V_43 ) ;
F_42 ( & V_55 ) ;
return V_54 ;
}
void F_43 ( struct V_2 * V_9 )
{
unsigned long V_56 ;
F_44 ( V_9 -> V_11 != V_40 ) ;
if ( ! V_9 -> V_57 ) {
F_3 ( F_45 () > 1 ) ;
V_9 -> V_57 = F_46 ( F_36 () ) ;
}
F_47 ( & V_51 , V_56 ) ;
F_23 ( & V_9 -> V_36 , & V_37 ) ;
F_24 ( V_9 ) ;
F_19 () ;
F_48 ( & V_51 , V_56 ) ;
}
void F_49 ( struct V_2 * V_9 , T_4 V_58 )
{
T_1 V_59 ;
if ( ! ( V_9 -> V_30 & V_60 ) )
return;
V_59 = V_9 -> V_61 ;
F_4 ( V_59 , V_58 ) ;
if ( ! V_59 )
V_59 = 1 ;
else if ( V_59 > 600 && V_9 -> V_61 > V_62 )
V_59 = 600 ;
F_50 ( V_9 , V_58 , V_59 ) ;
V_9 -> V_18 = F_1 ( V_9 -> V_63 , V_9 , false ) ;
V_9 -> V_33 = F_1 ( V_9 -> V_61 , V_9 , true ) ;
}
void F_51 ( struct V_2 * V_9 ,
T_4 V_58 , unsigned long V_64 ,
unsigned long V_65 )
{
V_9 -> V_63 = V_64 ;
V_9 -> V_61 = V_65 ;
F_49 ( V_9 , V_58 ) ;
F_43 ( V_9 ) ;
}
int F_52 ( struct V_2 * V_9 , T_4 V_58 )
{
F_49 ( V_9 , V_58 ) ;
if ( V_9 -> V_11 == V_13 )
return F_13 ( V_9 , V_9 -> V_15 , false ) ;
if ( V_9 -> V_11 == V_66 )
V_9 -> V_12 ( V_66 , V_9 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_9 , T_4 V_58 )
{
unsigned long V_56 ;
int V_54 ;
F_54 ( V_56 ) ;
V_54 = F_55 ( V_9 , V_58 ) ;
if ( V_54 == - V_53 )
V_54 = F_52 ( V_9 , V_58 ) ;
F_56 ( V_56 ) ;
return V_54 ;
}
void F_57 ( struct V_2 * V_9 )
{
}
void F_58 ( struct V_2 * V_67 ,
struct V_2 * V_68 )
{
unsigned long V_56 ;
F_54 ( V_56 ) ;
if ( V_67 ) {
F_29 ( V_67 -> V_41 ) ;
F_6 ( V_67 , V_40 ) ;
F_22 ( & V_67 -> V_36 ) ;
F_23 ( & V_67 -> V_36 , & V_34 ) ;
}
if ( V_68 ) {
F_44 ( V_68 -> V_11 != V_40 ) ;
F_7 ( V_68 ) ;
}
F_56 ( V_56 ) ;
}
void F_59 ( void )
{
struct V_2 * V_9 ;
F_60 (dev, &clockevent_devices, list)
if ( V_9 -> V_69 )
V_9 -> V_69 ( V_9 ) ;
}
void F_61 ( void )
{
struct V_2 * V_9 ;
F_26 (dev, &clockevent_devices, list)
if ( V_9 -> V_70 )
V_9 -> V_70 ( V_9 ) ;
}
int F_62 ( unsigned long V_71 , void * V_47 )
{
struct V_2 * V_9 , * V_72 ;
unsigned long V_56 ;
int V_43 , V_54 = 0 ;
F_47 ( & V_51 , V_56 ) ;
switch ( V_71 ) {
case V_73 :
case V_74 :
case V_75 :
F_63 ( V_71 , V_47 ) ;
break;
case V_76 :
case V_77 :
V_54 = F_64 ( V_71 ) ;
break;
case V_78 :
F_65 ( V_47 ) ;
break;
case V_79 :
F_66 () ;
F_67 () ;
break;
case V_80 :
F_68 () ;
break;
case V_81 :
F_69 ( V_47 ) ;
F_70 ( V_47 ) ;
F_71 ( V_47 ) ;
F_72 (dev, tmp, &clockevents_released, list)
F_22 ( & V_9 -> V_36 ) ;
V_43 = * ( ( int * ) V_47 ) ;
F_72 (dev, tmp, &clockevent_devices, list) {
if ( F_73 ( V_43 , V_9 -> V_57 ) &&
F_74 ( V_9 -> V_57 ) == 1 &&
! F_75 ( V_9 ) ) {
F_44 ( V_9 -> V_11 != V_40 ) ;
F_22 ( & V_9 -> V_36 ) ;
}
}
break;
default:
break;
}
F_48 ( & V_51 , V_56 ) ;
return V_54 ;
}
static T_5 F_76 ( struct V_82 * V_9 ,
struct V_83 * V_84 ,
char * V_85 )
{
struct V_86 * V_87 ;
T_5 V_88 = 0 ;
F_77 ( & V_51 ) ;
V_87 = F_78 ( V_9 ) ;
if ( V_87 && V_87 -> V_45 )
V_88 = snprintf ( V_85 , V_89 , L_4 , V_87 -> V_45 -> V_22 ) ;
F_79 ( & V_51 ) ;
return V_88 ;
}
static T_5 F_80 ( struct V_82 * V_9 ,
struct V_83 * V_84 ,
const char * V_85 , T_6 V_88 )
{
char V_22 [ V_90 ] ;
T_5 V_54 = F_81 ( V_85 , V_22 , V_88 ) ;
struct V_2 * V_52 ;
if ( V_54 < 0 )
return V_54 ;
V_54 = - V_53 ;
F_41 ( & V_55 ) ;
F_77 ( & V_51 ) ;
F_26 (ce, &clockevent_devices, list) {
if ( ! strcmp ( V_52 -> V_22 , V_22 ) ) {
V_54 = F_32 ( V_52 , V_9 -> V_91 ) ;
break;
}
}
F_79 ( & V_51 ) ;
if ( V_54 == - V_46 )
V_54 = F_38 ( V_52 , V_9 -> V_91 ) ;
F_42 ( & V_55 ) ;
return V_54 ? V_54 : V_88 ;
}
static struct V_86 * F_78 ( struct V_82 * V_9 )
{
return V_9 == & V_92 ? F_82 () :
& F_33 ( V_44 , V_9 -> V_91 ) ;
}
static T_7 int F_83 ( void )
{
int V_93 = F_84 ( & V_92 ) ;
if ( ! V_93 )
V_93 = F_85 ( & V_92 , & V_94 ) ;
return V_93 ;
}
static struct V_86 * F_78 ( struct V_82 * V_9 )
{
return & F_33 ( V_44 , V_9 -> V_91 ) ;
}
static inline int F_83 ( void ) { return 0 ; }
static int T_7 F_86 ( void )
{
int V_43 ;
F_87 (cpu) {
struct V_82 * V_9 = & F_33 ( V_95 , V_43 ) ;
int V_93 ;
V_9 -> V_91 = V_43 ;
V_9 -> V_96 = & V_97 ;
V_93 = F_84 ( V_9 ) ;
if ( ! V_93 )
V_93 = F_85 ( V_9 , & V_94 ) ;
if ( ! V_93 )
V_93 = F_85 ( V_9 , & V_98 ) ;
if ( V_93 )
return V_93 ;
}
return F_83 () ;
}
static int T_7 F_88 ( void )
{
int V_93 = F_89 ( & V_97 , NULL ) ;
if ( ! V_93 )
V_93 = F_86 () ;
return V_93 ;
}
