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
if ( ( abs ( V_30 - V_29 ) > V_41 ) ) {
F_20 ( L_2 , V_13 -> V_42 ) ;
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
F_21 () ;
}
}
}
if ( V_32 )
F_22 ( & V_35 ) ;
V_31 = F_23 ( F_24 () , V_46 ) ;
if ( V_31 >= V_47 )
V_31 = F_25 ( V_46 ) ;
V_48 . V_49 += V_50 ;
F_26 ( & V_48 , V_31 ) ;
V_34:
F_27 ( & V_20 ) ;
}
static inline void F_28 ( void )
{
if ( V_33 || ! V_37 || F_9 ( & V_22 ) )
return;
F_29 ( & V_48 ) ;
V_48 . V_51 = F_12 ;
V_48 . V_49 = V_52 + V_50 ;
F_26 ( & V_48 , F_25 ( V_46 ) ) ;
V_33 = 1 ;
}
static inline void F_30 ( void )
{
if ( ! V_33 || ( V_37 && ! F_9 ( & V_22 ) ) )
return;
F_31 ( & V_48 ) ;
V_33 = 0 ;
}
static inline void F_32 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &watchdog_list, wd_list)
V_13 -> V_14 &= ~ V_16 ;
}
static void F_33 ( void )
{
F_34 ( & V_35 ) ;
}
static void F_35 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
if ( V_13 -> V_14 & V_53 ) {
F_10 ( & V_13 -> V_21 , & V_22 ) ;
V_13 -> V_14 &= ~ V_16 ;
} else {
if ( V_13 -> V_14 & V_43 )
V_13 -> V_14 |= V_15 ;
if ( ! V_37 || V_13 -> V_54 > V_37 -> V_54 ) {
V_37 = V_13 ;
F_32 () ;
}
}
F_28 () ;
F_11 ( & V_20 , V_14 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
if ( V_13 != V_37 ) {
if ( V_13 -> V_14 & V_53 ) {
F_37 ( & V_13 -> V_21 ) ;
F_30 () ;
}
}
F_11 ( & V_20 , V_14 ) ;
}
static int F_38 ( void )
{
struct V_12 * V_13 , * V_6 ;
unsigned long V_14 ;
F_39 ( V_55 ) ;
int V_56 = 0 ;
F_8 ( & V_20 , V_14 ) ;
F_40 (cs, tmp, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
F_37 ( & V_13 -> V_21 ) ;
F_10 ( & V_13 -> V_21 , & V_55 ) ;
V_56 = 1 ;
}
if ( V_13 -> V_14 & V_45 ) {
V_13 -> V_14 &= ~ V_45 ;
V_56 = 1 ;
}
}
F_30 () ;
F_11 ( & V_20 , V_14 ) ;
F_40 (cs, tmp, &unstable, wd_list) {
F_37 ( & V_13 -> V_21 ) ;
F_41 ( V_13 , 0 ) ;
}
return V_56 ;
}
static int V_11 ( void * V_23 )
{
F_42 ( & V_57 ) ;
if ( F_38 () )
F_43 () ;
F_44 ( & V_57 ) ;
return 0 ;
}
static bool F_45 ( struct V_12 * V_13 )
{
return V_13 == V_37 ;
}
static void F_35 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 & V_43 )
V_13 -> V_14 |= V_15 ;
}
static inline void F_36 ( struct V_12 * V_13 ) { }
static inline void F_33 ( void ) { }
static inline int F_38 ( void ) { return 0 ; }
static bool F_45 ( struct V_12 * V_13 ) { return false ; }
void F_7 ( struct V_12 * V_13 ) { }
void F_46 ( void )
{
struct V_12 * V_13 ;
F_47 (cs, &clocksource_list, list)
if ( V_13 -> V_58 )
V_13 -> V_58 ( V_13 ) ;
}
void F_48 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &clocksource_list, list)
if ( V_13 -> V_59 )
V_13 -> V_59 ( V_13 ) ;
F_33 () ;
}
void F_49 ( void )
{
F_33 () ;
}
static T_1 F_50 ( struct V_12 * V_13 )
{
T_2 V_60 ;
V_60 = ( T_2 ) V_13 -> V_1 * 11 ;
F_2 ( V_60 , 100 ) ;
return ( T_1 ) V_60 ;
}
T_2 F_51 ( T_1 V_1 , T_1 V_2 , T_1 V_61 , T_2 V_40 , T_2 * V_62 )
{
T_2 V_63 , V_64 ;
V_64 = V_65 ;
F_2 ( V_64 , V_1 + V_61 ) ;
V_64 = F_52 ( V_64 , V_40 ) ;
V_63 = F_19 ( V_64 , V_1 - V_61 , V_2 ) ;
if ( V_62 )
* V_62 = V_64 ;
V_63 >>= 1 ;
return V_63 ;
}
static inline void F_53 ( struct V_12 * V_13 )
{
V_13 -> V_66 = F_51 ( V_13 -> V_1 , V_13 -> V_2 ,
V_13 -> V_61 , V_13 -> V_40 ,
& V_13 -> V_64 ) ;
}
static struct V_12 * F_54 ( bool V_67 , bool V_68 )
{
struct V_12 * V_13 ;
if ( ! V_18 || F_9 ( & V_69 ) )
return NULL ;
F_15 (cs, &clocksource_list, list) {
if ( V_68 && V_13 == V_44 )
continue;
if ( V_67 && ! ( V_13 -> V_14 & V_15 ) )
continue;
return V_13 ;
}
return NULL ;
}
static void F_55 ( bool V_68 )
{
bool V_67 = F_56 () ;
struct V_12 * V_70 , * V_13 ;
V_70 = F_54 ( V_67 , V_68 ) ;
if ( ! V_70 )
return;
F_15 (cs, &clocksource_list, list) {
if ( V_68 && V_13 == V_44 )
continue;
if ( strcmp ( V_13 -> V_42 , V_71 ) != 0 )
continue;
if ( ! ( V_13 -> V_14 & V_15 ) && V_67 ) {
F_57 ( V_72 L_5
L_6
L_7 , V_13 -> V_42 ) ;
V_71 [ 0 ] = 0 ;
} else
V_70 = V_13 ;
break;
}
if ( V_44 != V_70 && ! F_58 ( V_70 ) ) {
F_59 ( L_8 , V_70 -> V_42 ) ;
V_44 = V_70 ;
}
}
static void F_43 ( void )
{
return F_55 ( false ) ;
}
static void F_60 ( void )
{
return F_55 ( true ) ;
}
static inline void F_43 ( void ) { }
static inline void F_60 ( void ) { }
static int T_5 F_61 ( void )
{
F_42 ( & V_57 ) ;
V_44 = F_62 () ;
V_18 = 1 ;
F_38 () ;
F_43 () ;
F_44 ( & V_57 ) ;
return 0 ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_73 * V_74 = & V_69 ;
struct V_12 * V_6 ;
F_15 (tmp, &clocksource_list, list)
if ( V_6 -> V_54 >= V_13 -> V_54 )
V_74 = & V_6 -> V_75 ;
F_10 ( & V_13 -> V_75 , V_74 ) ;
}
void F_64 ( struct V_12 * V_13 , T_1 V_76 , T_1 V_77 )
{
T_2 V_78 ;
if ( V_77 ) {
V_78 = V_13 -> V_40 ;
F_2 ( V_78 , V_77 ) ;
F_2 ( V_78 , V_76 ) ;
if ( ! V_78 )
V_78 = 1 ;
else if ( V_78 > 600 && V_13 -> V_40 > V_79 )
V_78 = 600 ;
F_1 ( & V_13 -> V_1 , & V_13 -> V_2 , V_77 ,
V_80 / V_76 , V_78 * V_76 ) ;
}
V_13 -> V_61 = F_50 ( V_13 ) ;
while ( V_77 && ( ( V_13 -> V_1 + V_13 -> V_61 < V_13 -> V_1 )
|| ( V_13 -> V_1 - V_13 -> V_61 > V_13 -> V_1 ) ) ) {
V_13 -> V_1 >>= 1 ;
V_13 -> V_2 -- ;
V_13 -> V_61 = F_50 ( V_13 ) ;
}
F_65 ( V_13 -> V_1 + V_13 -> V_61 < V_13 -> V_1 ,
L_9 ,
V_13 -> V_42 ) ;
F_53 ( V_13 ) ;
F_59 ( L_10 ,
V_13 -> V_42 , V_13 -> V_40 , V_13 -> V_64 , V_13 -> V_66 ) ;
}
int F_66 ( struct V_12 * V_13 , T_1 V_76 , T_1 V_77 )
{
F_64 ( V_13 , V_76 , V_77 ) ;
F_42 ( & V_57 ) ;
F_63 ( V_13 ) ;
F_35 ( V_13 ) ;
F_43 () ;
F_44 ( & V_57 ) ;
return 0 ;
}
static void F_41 ( struct V_12 * V_13 , int V_54 )
{
F_67 ( & V_13 -> V_75 ) ;
V_13 -> V_54 = V_54 ;
F_63 ( V_13 ) ;
}
void F_68 ( struct V_12 * V_13 , int V_54 )
{
F_42 ( & V_57 ) ;
F_41 ( V_13 , V_54 ) ;
F_43 () ;
F_44 ( & V_57 ) ;
}
static int F_69 ( struct V_12 * V_13 )
{
if ( F_45 ( V_13 ) )
return - V_81 ;
if ( V_13 == V_44 ) {
F_60 () ;
if ( V_44 == V_13 )
return - V_81 ;
}
F_36 ( V_13 ) ;
F_37 ( & V_13 -> V_75 ) ;
return 0 ;
}
int F_70 ( struct V_12 * V_13 )
{
int V_60 = 0 ;
F_42 ( & V_57 ) ;
if ( ! F_9 ( & V_13 -> V_75 ) )
V_60 = F_69 ( V_13 ) ;
F_44 ( & V_57 ) ;
return V_60 ;
}
static T_6
F_71 ( struct V_82 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
T_6 V_87 = 0 ;
F_42 ( & V_57 ) ;
V_87 = snprintf ( V_86 , V_88 , L_11 , V_44 -> V_42 ) ;
F_44 ( & V_57 ) ;
return V_87 ;
}
T_6 F_72 ( const char * V_86 , char * V_89 , T_7 V_90 )
{
T_7 V_60 = V_90 ;
if ( ! V_90 || V_90 >= V_91 )
return - V_92 ;
if ( V_86 [ V_90 - 1 ] == '\n' )
V_90 -- ;
if ( V_90 > 0 )
memcpy ( V_89 , V_86 , V_90 ) ;
V_89 [ V_90 ] = 0 ;
return V_60 ;
}
static T_6 F_73 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
const char * V_86 , T_7 V_87 )
{
T_6 V_60 ;
F_42 ( & V_57 ) ;
V_60 = F_72 ( V_86 , V_71 , V_87 ) ;
if ( V_60 >= 0 )
F_43 () ;
F_44 ( & V_57 ) ;
return V_60 ;
}
static T_6 F_74 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
const char * V_86 , T_7 V_87 )
{
struct V_12 * V_13 ;
char V_42 [ V_91 ] ;
T_6 V_60 ;
V_60 = F_72 ( V_86 , V_42 , V_87 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = - V_93 ;
F_42 ( & V_57 ) ;
F_15 (cs, &clocksource_list, list) {
if ( strcmp ( V_13 -> V_42 , V_42 ) )
continue;
V_60 = F_69 ( V_13 ) ;
break;
}
F_44 ( & V_57 ) ;
return V_60 ? V_60 : V_87 ;
}
static T_6
F_75 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
struct V_12 * V_94 ;
T_6 V_87 = 0 ;
F_42 ( & V_57 ) ;
F_15 (src, &clocksource_list, list) {
if ( ! F_56 () ||
( V_94 -> V_14 & V_15 ) )
V_87 += snprintf ( V_86 + V_87 ,
F_76 ( ( T_6 ) V_88 - V_87 , ( T_6 ) 0 ) ,
L_12 , V_94 -> V_42 ) ;
}
F_44 ( & V_57 ) ;
V_87 += snprintf ( V_86 + V_87 ,
F_76 ( ( T_6 ) V_88 - V_87 , ( T_6 ) 0 ) , L_13 ) ;
return V_87 ;
}
static int T_5 F_77 ( void )
{
int error = F_78 ( & V_95 , NULL ) ;
if ( ! error )
error = F_79 ( & V_96 ) ;
if ( ! error )
error = F_80 (
& V_96 ,
& V_97 ) ;
if ( ! error )
error = F_80 ( & V_96 ,
& V_98 ) ;
if ( ! error )
error = F_80 (
& V_96 ,
& V_99 ) ;
return error ;
}
static int T_5 F_81 ( char * V_100 )
{
F_42 ( & V_57 ) ;
if ( V_100 )
F_82 ( V_71 , V_100 , sizeof( V_71 ) ) ;
F_44 ( & V_57 ) ;
return 1 ;
}
static int T_5 F_83 ( char * V_100 )
{
if ( ! strcmp ( V_100 , L_14 ) ) {
F_57 ( L_15
L_16 ) ;
return F_81 ( L_17 ) ;
}
F_57 ( L_18
L_19 ) ;
return F_81 ( V_100 ) ;
}
