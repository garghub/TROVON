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
static void F_7 ( struct V_12 * V_13 , T_3 V_20 )
{
F_8 ( V_21 L_2 ,
V_13 -> V_22 , V_20 ) ;
F_5 ( V_13 ) ;
}
void F_9 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( & V_23 , V_14 ) ;
if ( ! ( V_13 -> V_14 & V_17 ) ) {
if ( F_11 ( & V_13 -> V_24 ) )
F_12 ( & V_13 -> V_24 , & V_25 ) ;
F_5 ( V_13 ) ;
}
F_13 ( & V_23 , V_14 ) ;
}
static void F_14 ( unsigned long V_26 )
{
struct V_12 * V_13 ;
T_4 V_27 , V_28 , V_20 ;
T_3 V_29 , V_30 ;
int V_31 , V_32 ;
F_15 ( & V_23 ) ;
if ( ! V_33 )
goto V_34;
V_32 = F_16 ( & V_35 ) ;
F_17 (cs, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
if ( V_18 )
F_6 ( & V_19 ) ;
continue;
}
F_18 () ;
V_27 = V_13 -> V_36 ( V_13 ) ;
V_28 = V_37 -> V_36 ( V_37 ) ;
F_19 () ;
if ( ! ( V_13 -> V_14 & V_16 ) ||
F_16 ( & V_35 ) ) {
V_13 -> V_14 |= V_16 ;
V_13 -> V_38 = V_28 ;
V_13 -> V_39 = V_27 ;
continue;
}
V_20 = F_20 ( V_28 , V_13 -> V_38 , V_37 -> V_40 ) ;
V_29 = F_21 ( V_20 , V_37 -> V_1 ,
V_37 -> V_2 ) ;
V_20 = F_20 ( V_27 , V_13 -> V_39 , V_13 -> V_40 ) ;
V_30 = F_21 ( V_20 , V_13 -> V_1 , V_13 -> V_2 ) ;
V_13 -> V_39 = V_27 ;
V_13 -> V_38 = V_28 ;
if ( F_16 ( & V_35 ) )
continue;
if ( ( abs ( V_30 - V_29 ) > V_41 ) ) {
F_7 ( V_13 , V_30 - V_29 ) ;
continue;
}
if ( ! ( V_13 -> V_14 & V_15 ) &&
( V_13 -> V_14 & V_42 ) &&
( V_37 -> V_14 & V_42 ) ) {
V_13 -> V_14 |= V_15 ;
if ( ! V_18 )
continue;
if ( V_13 != V_43 ) {
V_13 -> V_14 |= V_44 ;
F_6 ( & V_19 ) ;
} else {
F_22 () ;
}
}
}
if ( V_32 )
F_23 ( & V_35 ) ;
V_31 = F_24 ( F_25 () , V_45 ) ;
if ( V_31 >= V_46 )
V_31 = F_26 ( V_45 ) ;
V_47 . V_48 += V_49 ;
F_27 ( & V_47 , V_31 ) ;
V_34:
F_28 ( & V_23 ) ;
}
static inline void F_29 ( void )
{
if ( V_33 || ! V_37 || F_11 ( & V_25 ) )
return;
F_30 ( & V_47 ) ;
V_47 . V_50 = F_14 ;
V_47 . V_48 = V_51 + V_49 ;
F_27 ( & V_47 , F_26 ( V_45 ) ) ;
V_33 = 1 ;
}
static inline void F_31 ( void )
{
if ( ! V_33 || ( V_37 && ! F_11 ( & V_25 ) ) )
return;
F_32 ( & V_47 ) ;
V_33 = 0 ;
}
static inline void F_33 ( void )
{
struct V_12 * V_13 ;
F_17 (cs, &watchdog_list, wd_list)
V_13 -> V_14 &= ~ V_16 ;
}
static void F_34 ( void )
{
F_35 ( & V_35 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( & V_23 , V_14 ) ;
if ( V_13 -> V_14 & V_52 ) {
F_12 ( & V_13 -> V_24 , & V_25 ) ;
V_13 -> V_14 &= ~ V_16 ;
} else {
if ( V_13 -> V_14 & V_42 )
V_13 -> V_14 |= V_15 ;
if ( ! V_37 || V_13 -> V_53 > V_37 -> V_53 ) {
V_37 = V_13 ;
F_33 () ;
}
}
F_29 () ;
F_13 ( & V_23 , V_14 ) ;
}
static void F_37 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( & V_23 , V_14 ) ;
if ( V_13 != V_37 ) {
if ( V_13 -> V_14 & V_52 ) {
F_38 ( & V_13 -> V_24 ) ;
F_31 () ;
}
}
F_13 ( & V_23 , V_14 ) ;
}
static int F_39 ( void )
{
struct V_12 * V_13 , * V_6 ;
unsigned long V_14 ;
F_40 ( V_54 ) ;
int V_55 = 0 ;
F_10 ( & V_23 , V_14 ) ;
F_41 (cs, tmp, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
F_38 ( & V_13 -> V_24 ) ;
F_12 ( & V_13 -> V_24 , & V_54 ) ;
V_55 = 1 ;
}
if ( V_13 -> V_14 & V_44 ) {
V_13 -> V_14 &= ~ V_44 ;
V_55 = 1 ;
}
}
F_31 () ;
F_13 ( & V_23 , V_14 ) ;
F_41 (cs, tmp, &unstable, wd_list) {
F_38 ( & V_13 -> V_24 ) ;
F_42 ( V_13 , 0 ) ;
}
return V_55 ;
}
static int V_11 ( void * V_26 )
{
F_43 ( & V_56 ) ;
if ( F_39 () )
F_44 () ;
F_45 ( & V_56 ) ;
return 0 ;
}
static bool F_46 ( struct V_12 * V_13 )
{
return V_13 == V_37 ;
}
static void F_36 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 & V_42 )
V_13 -> V_14 |= V_15 ;
}
static inline void F_37 ( struct V_12 * V_13 ) { }
static inline void F_34 ( void ) { }
static inline int F_39 ( void ) { return 0 ; }
static bool F_46 ( struct V_12 * V_13 ) { return false ; }
void F_9 ( struct V_12 * V_13 ) { }
void F_47 ( void )
{
struct V_12 * V_13 ;
F_48 (cs, &clocksource_list, list)
if ( V_13 -> V_57 )
V_13 -> V_57 ( V_13 ) ;
}
void F_49 ( void )
{
struct V_12 * V_13 ;
F_17 (cs, &clocksource_list, list)
if ( V_13 -> V_58 )
V_13 -> V_58 ( V_13 ) ;
F_34 () ;
}
void F_50 ( void )
{
F_34 () ;
}
static T_1 F_51 ( struct V_12 * V_13 )
{
T_2 V_59 ;
V_59 = ( T_2 ) V_13 -> V_1 * 11 ;
F_2 ( V_59 , 100 ) ;
return ( T_1 ) V_59 ;
}
T_2 F_52 ( T_1 V_1 , T_1 V_2 , T_1 V_60 , T_2 V_40 )
{
T_2 V_61 , V_62 ;
V_62 = 1ULL << ( 63 - ( F_53 ( V_1 + V_60 ) + 1 ) ) ;
V_62 = F_54 ( V_62 , V_40 ) ;
V_61 = F_21 ( V_62 , V_1 - V_60 , V_2 ) ;
return V_61 ;
}
static T_2 F_55 ( struct V_12 * V_13 )
{
T_2 V_61 ;
V_61 = F_52 ( V_13 -> V_1 , V_13 -> V_2 , V_13 -> V_60 ,
V_13 -> V_40 ) ;
return V_61 - ( V_61 >> 3 ) ;
}
static struct V_12 * F_56 ( bool V_63 , bool V_64 )
{
struct V_12 * V_13 ;
if ( ! V_18 || F_11 ( & V_65 ) )
return NULL ;
F_17 (cs, &clocksource_list, list) {
if ( V_64 && V_13 == V_43 )
continue;
if ( V_63 && ! ( V_13 -> V_14 & V_15 ) )
continue;
return V_13 ;
}
return NULL ;
}
static void F_57 ( bool V_64 )
{
bool V_63 = F_58 () ;
struct V_12 * V_66 , * V_13 ;
V_66 = F_56 ( V_63 , V_64 ) ;
if ( ! V_66 )
return;
F_17 (cs, &clocksource_list, list) {
if ( V_64 && V_13 == V_43 )
continue;
if ( strcmp ( V_13 -> V_22 , V_67 ) != 0 )
continue;
if ( ! ( V_13 -> V_14 & V_15 ) && V_63 ) {
F_8 ( V_21 L_3
L_4
L_5 , V_13 -> V_22 ) ;
V_67 [ 0 ] = 0 ;
} else
V_66 = V_13 ;
break;
}
if ( V_43 != V_66 && ! F_59 ( V_66 ) ) {
F_60 ( L_6 , V_66 -> V_22 ) ;
V_43 = V_66 ;
}
}
static void F_44 ( void )
{
return F_57 ( false ) ;
}
static void F_61 ( void )
{
return F_57 ( true ) ;
}
static inline void F_44 ( void ) { }
static inline void F_61 ( void ) { }
static int T_5 F_62 ( void )
{
F_43 ( & V_56 ) ;
V_43 = F_63 () ;
V_18 = 1 ;
F_39 () ;
F_44 () ;
F_45 ( & V_56 ) ;
return 0 ;
}
static void F_64 ( struct V_12 * V_13 )
{
struct V_68 * V_69 = & V_65 ;
struct V_12 * V_6 ;
F_17 (tmp, &clocksource_list, list)
if ( V_6 -> V_53 >= V_13 -> V_53 )
V_69 = & V_6 -> V_70 ;
F_12 ( & V_13 -> V_70 , V_69 ) ;
}
void F_65 ( struct V_12 * V_13 , T_1 V_71 , T_1 V_72 )
{
T_2 V_73 ;
V_73 = ( V_13 -> V_40 - ( V_13 -> V_40 >> 3 ) ) ;
F_2 ( V_73 , V_72 ) ;
F_2 ( V_73 , V_71 ) ;
if ( ! V_73 )
V_73 = 1 ;
else if ( V_73 > 600 && V_13 -> V_40 > V_74 )
V_73 = 600 ;
F_1 ( & V_13 -> V_1 , & V_13 -> V_2 , V_72 ,
V_75 / V_71 , V_73 * V_71 ) ;
V_13 -> V_60 = F_51 ( V_13 ) ;
while ( ( V_13 -> V_1 + V_13 -> V_60 < V_13 -> V_1 )
|| ( V_13 -> V_1 - V_13 -> V_60 > V_13 -> V_1 ) ) {
V_13 -> V_1 >>= 1 ;
V_13 -> V_2 -- ;
V_13 -> V_60 = F_51 ( V_13 ) ;
}
V_13 -> V_76 = F_55 ( V_13 ) ;
}
int F_66 ( struct V_12 * V_13 , T_1 V_71 , T_1 V_72 )
{
F_65 ( V_13 , V_71 , V_72 ) ;
F_43 ( & V_56 ) ;
F_64 ( V_13 ) ;
F_36 ( V_13 ) ;
F_44 () ;
F_45 ( & V_56 ) ;
return 0 ;
}
int F_67 ( struct V_12 * V_13 )
{
V_13 -> V_60 = F_51 ( V_13 ) ;
F_68 ( V_13 -> V_1 + V_13 -> V_60 < V_13 -> V_1 ,
L_7 ,
V_13 -> V_22 ) ;
V_13 -> V_76 = F_55 ( V_13 ) ;
F_43 ( & V_56 ) ;
F_64 ( V_13 ) ;
F_36 ( V_13 ) ;
F_44 () ;
F_45 ( & V_56 ) ;
return 0 ;
}
static void F_42 ( struct V_12 * V_13 , int V_53 )
{
F_69 ( & V_13 -> V_70 ) ;
V_13 -> V_53 = V_53 ;
F_64 ( V_13 ) ;
}
void F_70 ( struct V_12 * V_13 , int V_53 )
{
F_43 ( & V_56 ) ;
F_42 ( V_13 , V_53 ) ;
F_44 () ;
F_45 ( & V_56 ) ;
}
static int F_71 ( struct V_12 * V_13 )
{
if ( F_46 ( V_13 ) )
return - V_77 ;
if ( V_13 == V_43 ) {
F_61 () ;
if ( V_43 == V_13 )
return - V_77 ;
}
F_37 ( V_13 ) ;
F_38 ( & V_13 -> V_70 ) ;
return 0 ;
}
int F_72 ( struct V_12 * V_13 )
{
int V_59 = 0 ;
F_43 ( & V_56 ) ;
if ( ! F_11 ( & V_13 -> V_70 ) )
V_59 = F_71 ( V_13 ) ;
F_45 ( & V_56 ) ;
return V_59 ;
}
static T_6
F_73 ( struct V_78 * V_79 ,
struct V_80 * V_81 , char * V_82 )
{
T_6 V_83 = 0 ;
F_43 ( & V_56 ) ;
V_83 = snprintf ( V_82 , V_84 , L_8 , V_43 -> V_22 ) ;
F_45 ( & V_56 ) ;
return V_83 ;
}
T_6 F_74 ( const char * V_82 , char * V_85 , T_7 V_86 )
{
T_7 V_59 = V_86 ;
if ( ! V_86 || V_86 >= V_87 )
return - V_88 ;
if ( V_82 [ V_86 - 1 ] == '\n' )
V_86 -- ;
if ( V_86 > 0 )
memcpy ( V_85 , V_82 , V_86 ) ;
V_85 [ V_86 ] = 0 ;
return V_59 ;
}
static T_6 F_75 ( struct V_78 * V_79 ,
struct V_80 * V_81 ,
const char * V_82 , T_7 V_83 )
{
T_6 V_59 ;
F_43 ( & V_56 ) ;
V_59 = F_74 ( V_82 , V_67 , V_83 ) ;
if ( V_59 >= 0 )
F_44 () ;
F_45 ( & V_56 ) ;
return V_59 ;
}
static T_6 F_76 ( struct V_78 * V_79 ,
struct V_80 * V_81 ,
const char * V_82 , T_7 V_83 )
{
struct V_12 * V_13 ;
char V_22 [ V_87 ] ;
T_6 V_59 ;
V_59 = F_74 ( V_82 , V_22 , V_83 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = - V_89 ;
F_43 ( & V_56 ) ;
F_17 (cs, &clocksource_list, list) {
if ( strcmp ( V_13 -> V_22 , V_22 ) )
continue;
V_59 = F_71 ( V_13 ) ;
break;
}
F_45 ( & V_56 ) ;
return V_59 ? V_59 : V_83 ;
}
static T_6
F_77 ( struct V_78 * V_79 ,
struct V_80 * V_81 ,
char * V_82 )
{
struct V_12 * V_90 ;
T_6 V_83 = 0 ;
F_43 ( & V_56 ) ;
F_17 (src, &clocksource_list, list) {
if ( ! F_58 () ||
( V_90 -> V_14 & V_15 ) )
V_83 += snprintf ( V_82 + V_83 ,
F_78 ( ( T_6 ) V_84 - V_83 , ( T_6 ) 0 ) ,
L_9 , V_90 -> V_22 ) ;
}
F_45 ( & V_56 ) ;
V_83 += snprintf ( V_82 + V_83 ,
F_78 ( ( T_6 ) V_84 - V_83 , ( T_6 ) 0 ) , L_10 ) ;
return V_83 ;
}
static int T_5 F_79 ( void )
{
int error = F_80 ( & V_91 , NULL ) ;
if ( ! error )
error = F_81 ( & V_92 ) ;
if ( ! error )
error = F_82 (
& V_92 ,
& V_93 ) ;
if ( ! error )
error = F_82 ( & V_92 ,
& V_94 ) ;
if ( ! error )
error = F_82 (
& V_92 ,
& V_95 ) ;
return error ;
}
static int T_5 F_83 ( char * V_96 )
{
F_43 ( & V_56 ) ;
if ( V_96 )
F_84 ( V_67 , V_96 , sizeof( V_67 ) ) ;
F_45 ( & V_56 ) ;
return 1 ;
}
static int T_5 F_85 ( char * V_96 )
{
if ( ! strcmp ( V_96 , L_11 ) ) {
F_8 ( L_12
L_13 ) ;
return F_83 ( L_14 ) ;
}
F_8 ( L_15
L_16 ) ;
return F_83 ( V_96 ) ;
}
