void
F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_2 V_6 ;
T_1 V_7 , V_8 = 32 ;
V_6 = ( ( T_2 ) V_5 * V_3 ) >> 32 ;
while ( V_6 ) {
V_6 >>= 1 ;
V_8 -- ;
}
for ( V_7 = 32 ; V_7 > 0 ; V_7 -- ) {
V_6 = ( T_2 ) V_4 << V_7 ;
V_6 += V_3 / 2 ;
F_2 ( V_6 , V_3 ) ;
if ( ( V_6 >> V_8 ) == 0 )
break;
}
* V_1 = V_6 ;
* V_2 = V_7 ;
}
static void F_3 ( struct V_9 * V_10 )
{
F_4 ( V_11 , NULL , L_1 ) ;
}
static void F_5 ( struct V_12 * V_13 )
{
V_13 -> V_14 &= ~ ( V_15 | V_16 ) ;
V_13 -> V_14 |= V_17 ;
if ( V_18 )
F_6 ( & V_19 ) ;
}
void F_7 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
if ( ! ( V_13 -> V_14 & V_17 ) ) {
if ( F_9 ( & V_13 -> V_21 ) )
F_10 ( & V_13 -> V_21 , & V_22 ) ;
F_5 ( V_13 ) ;
}
F_11 ( & V_20 , V_14 ) ;
}
static void F_12 ( unsigned long V_23 )
{
struct V_12 * V_13 ;
T_3 V_24 , V_25 , V_26 , V_27 , V_28 ;
T_4 V_29 , V_30 ;
int V_31 , V_32 ;
F_13 ( & V_20 ) ;
if ( ! V_33 )
goto V_34;
V_32 = F_14 ( & V_35 ) ;
F_15 (cs, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
if ( V_18 )
F_6 ( & V_19 ) ;
continue;
}
F_16 () ;
V_24 = V_13 -> V_36 ( V_13 ) ;
V_25 = V_37 -> V_36 ( V_37 ) ;
F_17 () ;
if ( ! ( V_13 -> V_14 & V_16 ) ||
F_14 ( & V_35 ) ) {
V_13 -> V_14 |= V_16 ;
V_13 -> V_38 = V_25 ;
V_13 -> V_39 = V_24 ;
continue;
}
V_28 = F_18 ( V_25 , V_13 -> V_38 , V_37 -> V_40 ) ;
V_29 = F_19 ( V_28 , V_37 -> V_1 ,
V_37 -> V_2 ) ;
V_28 = F_18 ( V_24 , V_13 -> V_39 , V_13 -> V_40 ) ;
V_30 = F_19 ( V_28 , V_13 -> V_1 , V_13 -> V_2 ) ;
V_27 = V_13 -> V_38 ;
V_26 = V_13 -> V_39 ;
V_13 -> V_39 = V_24 ;
V_13 -> V_38 = V_25 ;
if ( F_14 ( & V_35 ) )
continue;
if ( abs ( V_30 - V_29 ) > V_41 ) {
F_20 ( L_2 ,
F_21 () , V_13 -> V_42 ) ;
F_20 ( L_3 ,
V_37 -> V_42 , V_25 , V_27 , V_37 -> V_40 ) ;
F_20 ( L_4 ,
V_13 -> V_42 , V_24 , V_26 , V_13 -> V_40 ) ;
F_5 ( V_13 ) ;
continue;
}
if ( ! ( V_13 -> V_14 & V_15 ) &&
( V_13 -> V_14 & V_43 ) &&
( V_37 -> V_14 & V_43 ) ) {
V_13 -> V_14 |= V_15 ;
if ( ! V_18 )
continue;
if ( V_13 != V_44 ) {
V_13 -> V_14 |= V_45 ;
F_6 ( & V_19 ) ;
} else {
F_22 () ;
}
}
}
if ( V_32 )
F_23 ( & V_35 ) ;
V_31 = F_24 ( F_25 () , V_46 ) ;
if ( V_31 >= V_47 )
V_31 = F_26 ( V_46 ) ;
V_48 . V_49 += V_50 ;
F_27 ( & V_48 , V_31 ) ;
V_34:
F_28 ( & V_20 ) ;
}
static inline void F_29 ( void )
{
if ( V_33 || ! V_37 || F_9 ( & V_22 ) )
return;
F_30 ( & V_48 ) ;
V_48 . V_51 = F_12 ;
V_48 . V_49 = V_52 + V_50 ;
F_27 ( & V_48 , F_26 ( V_46 ) ) ;
V_33 = 1 ;
}
static inline void F_31 ( void )
{
if ( ! V_33 || ( V_37 && ! F_9 ( & V_22 ) ) )
return;
F_32 ( & V_48 ) ;
V_33 = 0 ;
}
static inline void F_33 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &watchdog_list, wd_list)
V_13 -> V_14 &= ~ V_16 ;
}
static void F_34 ( void )
{
F_35 ( & V_35 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
if ( V_13 -> V_14 & V_53 ) {
F_10 ( & V_13 -> V_21 , & V_22 ) ;
V_13 -> V_14 &= ~ V_16 ;
} else {
if ( V_13 -> V_14 & V_43 )
V_13 -> V_14 |= V_15 ;
}
F_11 ( & V_20 , V_14 ) ;
}
static void F_37 ( bool V_54 )
{
struct V_12 * V_13 , * V_55 ;
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
V_55 = V_37 ;
if ( V_54 )
V_37 = NULL ;
F_15 (cs, &clocksource_list, list) {
if ( V_13 -> V_14 & V_53 )
continue;
if ( V_54 && V_13 == V_55 )
continue;
if ( ! V_37 || V_13 -> V_56 > V_37 -> V_56 )
V_37 = V_13 ;
}
if ( ! V_37 )
V_37 = V_55 ;
if ( V_37 != V_55 )
F_33 () ;
F_29 () ;
F_11 ( & V_20 , V_14 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
if ( V_13 != V_37 ) {
if ( V_13 -> V_14 & V_53 ) {
F_39 ( & V_13 -> V_21 ) ;
F_31 () ;
}
}
F_11 ( & V_20 , V_14 ) ;
}
static int F_40 ( void )
{
struct V_12 * V_13 , * V_6 ;
unsigned long V_14 ;
F_41 ( V_57 ) ;
int V_58 = 0 ;
F_8 ( & V_20 , V_14 ) ;
F_42 (cs, tmp, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
F_39 ( & V_13 -> V_21 ) ;
F_10 ( & V_13 -> V_21 , & V_57 ) ;
V_58 = 1 ;
}
if ( V_13 -> V_14 & V_45 ) {
V_13 -> V_14 &= ~ V_45 ;
V_58 = 1 ;
}
}
F_31 () ;
F_11 ( & V_20 , V_14 ) ;
F_42 (cs, tmp, &unstable, wd_list) {
F_39 ( & V_13 -> V_21 ) ;
F_43 ( V_13 , 0 ) ;
}
return V_58 ;
}
static int V_11 ( void * V_23 )
{
F_44 ( & V_59 ) ;
if ( F_40 () )
F_45 () ;
F_46 ( & V_59 ) ;
return 0 ;
}
static bool F_47 ( struct V_12 * V_13 )
{
return V_13 == V_37 ;
}
static void F_36 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 & V_43 )
V_13 -> V_14 |= V_15 ;
}
static void F_37 ( bool V_54 ) { }
static inline void F_38 ( struct V_12 * V_13 ) { }
static inline void F_34 ( void ) { }
static inline int F_40 ( void ) { return 0 ; }
static bool F_47 ( struct V_12 * V_13 ) { return false ; }
void F_7 ( struct V_12 * V_13 ) { }
void F_48 ( void )
{
struct V_12 * V_13 ;
F_49 (cs, &clocksource_list, list)
if ( V_13 -> V_60 )
V_13 -> V_60 ( V_13 ) ;
}
void F_50 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &clocksource_list, list)
if ( V_13 -> V_61 )
V_13 -> V_61 ( V_13 ) ;
F_34 () ;
}
void F_51 ( void )
{
F_34 () ;
}
static T_1 F_52 ( struct V_12 * V_13 )
{
T_2 V_62 ;
V_62 = ( T_2 ) V_13 -> V_1 * 11 ;
F_2 ( V_62 , 100 ) ;
return ( T_1 ) V_62 ;
}
T_2 F_53 ( T_1 V_1 , T_1 V_2 , T_1 V_63 , T_2 V_40 , T_2 * V_64 )
{
T_2 V_65 , V_66 ;
V_66 = V_67 ;
F_2 ( V_66 , V_1 + V_63 ) ;
V_66 = F_54 ( V_66 , V_40 ) ;
V_65 = F_19 ( V_66 , V_1 - V_63 , V_2 ) ;
if ( V_64 )
* V_64 = V_66 ;
V_65 >>= 1 ;
return V_65 ;
}
static inline void F_55 ( struct V_12 * V_13 )
{
V_13 -> V_68 = F_53 ( V_13 -> V_1 , V_13 -> V_2 ,
V_13 -> V_63 , V_13 -> V_40 ,
& V_13 -> V_66 ) ;
}
static struct V_12 * F_56 ( bool V_69 , bool V_70 )
{
struct V_12 * V_13 ;
if ( ! V_18 || F_9 ( & V_71 ) )
return NULL ;
F_15 (cs, &clocksource_list, list) {
if ( V_70 && V_13 == V_44 )
continue;
if ( V_69 && ! ( V_13 -> V_14 & V_15 ) )
continue;
return V_13 ;
}
return NULL ;
}
static void F_57 ( bool V_70 )
{
bool V_69 = F_58 () ;
struct V_12 * V_72 , * V_13 ;
V_72 = F_56 ( V_69 , V_70 ) ;
if ( ! V_72 )
return;
F_15 (cs, &clocksource_list, list) {
if ( V_70 && V_13 == V_44 )
continue;
if ( strcmp ( V_13 -> V_42 , V_73 ) != 0 )
continue;
if ( ! ( V_13 -> V_14 & V_15 ) && V_69 ) {
if ( V_13 -> V_14 & V_17 ) {
F_20 ( L_5 ,
V_13 -> V_42 ) ;
V_73 [ 0 ] = 0 ;
} else {
F_59 ( L_6 ,
V_13 -> V_42 ) ;
}
} else
V_72 = V_13 ;
break;
}
if ( V_44 != V_72 && ! F_60 ( V_72 ) ) {
F_59 ( L_7 , V_72 -> V_42 ) ;
V_44 = V_72 ;
}
}
static void F_45 ( void )
{
F_57 ( false ) ;
}
static void F_61 ( void )
{
F_57 ( true ) ;
}
static inline void F_45 ( void ) { }
static inline void F_61 ( void ) { }
static int T_5 F_62 ( void )
{
F_44 ( & V_59 ) ;
V_44 = F_63 () ;
V_18 = 1 ;
F_40 () ;
F_45 () ;
F_46 ( & V_59 ) ;
return 0 ;
}
static void F_64 ( struct V_12 * V_13 )
{
struct V_74 * V_75 = & V_71 ;
struct V_12 * V_6 ;
F_15 (tmp, &clocksource_list, list) {
if ( V_6 -> V_56 < V_13 -> V_56 )
break;
V_75 = & V_6 -> V_76 ;
}
F_10 ( & V_13 -> V_76 , V_75 ) ;
}
void F_65 ( struct V_12 * V_13 , T_1 V_77 , T_1 V_78 )
{
T_2 V_79 ;
if ( V_78 ) {
V_79 = V_13 -> V_40 ;
F_2 ( V_79 , V_78 ) ;
F_2 ( V_79 , V_77 ) ;
if ( ! V_79 )
V_79 = 1 ;
else if ( V_79 > 600 && V_13 -> V_40 > V_80 )
V_79 = 600 ;
F_1 ( & V_13 -> V_1 , & V_13 -> V_2 , V_78 ,
V_81 / V_77 , V_79 * V_77 ) ;
}
V_13 -> V_63 = F_52 ( V_13 ) ;
while ( V_78 && ( ( V_13 -> V_1 + V_13 -> V_63 < V_13 -> V_1 )
|| ( V_13 -> V_1 - V_13 -> V_63 > V_13 -> V_1 ) ) ) {
V_13 -> V_1 >>= 1 ;
V_13 -> V_2 -- ;
V_13 -> V_63 = F_52 ( V_13 ) ;
}
F_66 ( V_13 -> V_1 + V_13 -> V_63 < V_13 -> V_1 ,
L_8 ,
V_13 -> V_42 ) ;
F_55 ( V_13 ) ;
F_59 ( L_9 ,
V_13 -> V_42 , V_13 -> V_40 , V_13 -> V_66 , V_13 -> V_68 ) ;
}
int F_67 ( struct V_12 * V_13 , T_1 V_77 , T_1 V_78 )
{
F_65 ( V_13 , V_77 , V_78 ) ;
F_44 ( & V_59 ) ;
F_64 ( V_13 ) ;
F_36 ( V_13 ) ;
F_45 () ;
F_37 ( false ) ;
F_46 ( & V_59 ) ;
return 0 ;
}
static void F_43 ( struct V_12 * V_13 , int V_56 )
{
F_68 ( & V_13 -> V_76 ) ;
V_13 -> V_56 = V_56 ;
F_64 ( V_13 ) ;
}
void F_69 ( struct V_12 * V_13 , int V_56 )
{
F_44 ( & V_59 ) ;
F_43 ( V_13 , V_56 ) ;
F_45 () ;
F_37 ( false ) ;
F_46 ( & V_59 ) ;
}
static int F_70 ( struct V_12 * V_13 )
{
if ( F_47 ( V_13 ) ) {
F_37 ( true ) ;
if ( F_47 ( V_13 ) )
return - V_82 ;
}
if ( V_13 == V_44 ) {
F_61 () ;
if ( V_44 == V_13 )
return - V_82 ;
}
F_38 ( V_13 ) ;
F_39 ( & V_13 -> V_76 ) ;
return 0 ;
}
int F_71 ( struct V_12 * V_13 )
{
int V_62 = 0 ;
F_44 ( & V_59 ) ;
if ( ! F_9 ( & V_13 -> V_76 ) )
V_62 = F_70 ( V_13 ) ;
F_46 ( & V_59 ) ;
return V_62 ;
}
static T_6
F_72 ( struct V_83 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
T_6 V_88 = 0 ;
F_44 ( & V_59 ) ;
V_88 = snprintf ( V_87 , V_89 , L_10 , V_44 -> V_42 ) ;
F_46 ( & V_59 ) ;
return V_88 ;
}
T_6 F_73 ( const char * V_87 , char * V_90 , T_7 V_91 )
{
T_7 V_62 = V_91 ;
if ( ! V_91 || V_91 >= V_92 )
return - V_93 ;
if ( V_87 [ V_91 - 1 ] == '\n' )
V_91 -- ;
if ( V_91 > 0 )
memcpy ( V_90 , V_87 , V_91 ) ;
V_90 [ V_91 ] = 0 ;
return V_62 ;
}
static T_6 F_74 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
const char * V_87 , T_7 V_88 )
{
T_6 V_62 ;
F_44 ( & V_59 ) ;
V_62 = F_73 ( V_87 , V_73 , V_88 ) ;
if ( V_62 >= 0 )
F_45 () ;
F_46 ( & V_59 ) ;
return V_62 ;
}
static T_6 F_75 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
const char * V_87 , T_7 V_88 )
{
struct V_12 * V_13 ;
char V_42 [ V_92 ] ;
T_6 V_62 ;
V_62 = F_73 ( V_87 , V_42 , V_88 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = - V_94 ;
F_44 ( & V_59 ) ;
F_15 (cs, &clocksource_list, list) {
if ( strcmp ( V_13 -> V_42 , V_42 ) )
continue;
V_62 = F_70 ( V_13 ) ;
break;
}
F_46 ( & V_59 ) ;
return V_62 ? V_62 : V_88 ;
}
static T_6
F_76 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 )
{
struct V_12 * V_95 ;
T_6 V_88 = 0 ;
F_44 ( & V_59 ) ;
F_15 (src, &clocksource_list, list) {
if ( ! F_58 () ||
( V_95 -> V_14 & V_15 ) )
V_88 += snprintf ( V_87 + V_88 ,
F_77 ( ( T_6 ) V_89 - V_88 , ( T_6 ) 0 ) ,
L_11 , V_95 -> V_42 ) ;
}
F_46 ( & V_59 ) ;
V_88 += snprintf ( V_87 + V_88 ,
F_77 ( ( T_6 ) V_89 - V_88 , ( T_6 ) 0 ) , L_12 ) ;
return V_88 ;
}
static int T_5 F_78 ( void )
{
int error = F_79 ( & V_96 , NULL ) ;
if ( ! error )
error = F_80 ( & V_97 ) ;
if ( ! error )
error = F_81 (
& V_97 ,
& V_98 ) ;
if ( ! error )
error = F_81 ( & V_97 ,
& V_99 ) ;
if ( ! error )
error = F_81 (
& V_97 ,
& V_100 ) ;
return error ;
}
static int T_5 F_82 ( char * V_101 )
{
F_44 ( & V_59 ) ;
if ( V_101 )
F_83 ( V_73 , V_101 , sizeof( V_73 ) ) ;
F_46 ( & V_59 ) ;
return 1 ;
}
static int T_5 F_84 ( char * V_101 )
{
if ( ! strcmp ( V_101 , L_13 ) ) {
F_20 ( L_14 ) ;
return F_82 ( L_15 ) ;
}
F_20 ( L_16 ) ;
return F_82 ( V_101 ) ;
}
