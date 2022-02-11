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
if ( ! V_37 || V_13 -> V_54 > V_37 -> V_54 ) {
V_37 = V_13 ;
F_33 () ;
}
}
F_29 () ;
F_11 ( & V_20 , V_14 ) ;
}
static void F_37 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_20 , V_14 ) ;
if ( V_13 != V_37 ) {
if ( V_13 -> V_14 & V_53 ) {
F_38 ( & V_13 -> V_21 ) ;
F_31 () ;
}
}
F_11 ( & V_20 , V_14 ) ;
}
static int F_39 ( void )
{
struct V_12 * V_13 , * V_6 ;
unsigned long V_14 ;
F_40 ( V_55 ) ;
int V_56 = 0 ;
F_8 ( & V_20 , V_14 ) ;
F_41 (cs, tmp, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
F_38 ( & V_13 -> V_21 ) ;
F_10 ( & V_13 -> V_21 , & V_55 ) ;
V_56 = 1 ;
}
if ( V_13 -> V_14 & V_45 ) {
V_13 -> V_14 &= ~ V_45 ;
V_56 = 1 ;
}
}
F_31 () ;
F_11 ( & V_20 , V_14 ) ;
F_41 (cs, tmp, &unstable, wd_list) {
F_38 ( & V_13 -> V_21 ) ;
F_42 ( V_13 , 0 ) ;
}
return V_56 ;
}
static int V_11 ( void * V_23 )
{
F_43 ( & V_57 ) ;
if ( F_39 () )
F_44 () ;
F_45 ( & V_57 ) ;
return 0 ;
}
static bool F_46 ( struct V_12 * V_13 )
{
return V_13 == V_37 ;
}
static void F_36 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 & V_43 )
V_13 -> V_14 |= V_15 ;
}
static inline void F_37 ( struct V_12 * V_13 ) { }
static inline void F_34 ( void ) { }
static inline int F_39 ( void ) { return 0 ; }
static bool F_46 ( struct V_12 * V_13 ) { return false ; }
void F_7 ( struct V_12 * V_13 ) { }
void F_47 ( void )
{
struct V_12 * V_13 ;
F_48 (cs, &clocksource_list, list)
if ( V_13 -> V_58 )
V_13 -> V_58 ( V_13 ) ;
}
void F_49 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &clocksource_list, list)
if ( V_13 -> V_59 )
V_13 -> V_59 ( V_13 ) ;
F_34 () ;
}
void F_50 ( void )
{
F_34 () ;
}
static T_1 F_51 ( struct V_12 * V_13 )
{
T_2 V_60 ;
V_60 = ( T_2 ) V_13 -> V_1 * 11 ;
F_2 ( V_60 , 100 ) ;
return ( T_1 ) V_60 ;
}
T_2 F_52 ( T_1 V_1 , T_1 V_2 , T_1 V_61 , T_2 V_40 , T_2 * V_62 )
{
T_2 V_63 , V_64 ;
V_64 = V_65 ;
F_2 ( V_64 , V_1 + V_61 ) ;
V_64 = F_53 ( V_64 , V_40 ) ;
V_63 = F_19 ( V_64 , V_1 - V_61 , V_2 ) ;
if ( V_62 )
* V_62 = V_64 ;
V_63 >>= 1 ;
return V_63 ;
}
static inline void F_54 ( struct V_12 * V_13 )
{
V_13 -> V_66 = F_52 ( V_13 -> V_1 , V_13 -> V_2 ,
V_13 -> V_61 , V_13 -> V_40 ,
& V_13 -> V_64 ) ;
}
static struct V_12 * F_55 ( bool V_67 , bool V_68 )
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
static void F_56 ( bool V_68 )
{
bool V_67 = F_57 () ;
struct V_12 * V_70 , * V_13 ;
V_70 = F_55 ( V_67 , V_68 ) ;
if ( ! V_70 )
return;
F_15 (cs, &clocksource_list, list) {
if ( V_68 && V_13 == V_44 )
continue;
if ( strcmp ( V_13 -> V_42 , V_71 ) != 0 )
continue;
if ( ! ( V_13 -> V_14 & V_15 ) && V_67 ) {
F_20 ( L_5 ,
V_13 -> V_42 ) ;
V_71 [ 0 ] = 0 ;
} else
V_70 = V_13 ;
break;
}
if ( V_44 != V_70 && ! F_58 ( V_70 ) ) {
F_59 ( L_6 , V_70 -> V_42 ) ;
V_44 = V_70 ;
}
}
static void F_44 ( void )
{
F_56 ( false ) ;
}
static void F_60 ( void )
{
F_56 ( true ) ;
}
static inline void F_44 ( void ) { }
static inline void F_60 ( void ) { }
static int T_5 F_61 ( void )
{
F_43 ( & V_57 ) ;
V_44 = F_62 () ;
V_18 = 1 ;
F_39 () ;
F_44 () ;
F_45 ( & V_57 ) ;
return 0 ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_72 * V_73 = & V_69 ;
struct V_12 * V_6 ;
F_15 (tmp, &clocksource_list, list)
if ( V_6 -> V_54 >= V_13 -> V_54 )
V_73 = & V_6 -> V_74 ;
F_10 ( & V_13 -> V_74 , V_73 ) ;
}
void F_64 ( struct V_12 * V_13 , T_1 V_75 , T_1 V_76 )
{
T_2 V_77 ;
if ( V_76 ) {
V_77 = V_13 -> V_40 ;
F_2 ( V_77 , V_76 ) ;
F_2 ( V_77 , V_75 ) ;
if ( ! V_77 )
V_77 = 1 ;
else if ( V_77 > 600 && V_13 -> V_40 > V_78 )
V_77 = 600 ;
F_1 ( & V_13 -> V_1 , & V_13 -> V_2 , V_76 ,
V_79 / V_75 , V_77 * V_75 ) ;
}
V_13 -> V_61 = F_51 ( V_13 ) ;
while ( V_76 && ( ( V_13 -> V_1 + V_13 -> V_61 < V_13 -> V_1 )
|| ( V_13 -> V_1 - V_13 -> V_61 > V_13 -> V_1 ) ) ) {
V_13 -> V_1 >>= 1 ;
V_13 -> V_2 -- ;
V_13 -> V_61 = F_51 ( V_13 ) ;
}
F_65 ( V_13 -> V_1 + V_13 -> V_61 < V_13 -> V_1 ,
L_7 ,
V_13 -> V_42 ) ;
F_54 ( V_13 ) ;
F_59 ( L_8 ,
V_13 -> V_42 , V_13 -> V_40 , V_13 -> V_64 , V_13 -> V_66 ) ;
}
int F_66 ( struct V_12 * V_13 , T_1 V_75 , T_1 V_76 )
{
F_64 ( V_13 , V_75 , V_76 ) ;
F_43 ( & V_57 ) ;
F_63 ( V_13 ) ;
F_36 ( V_13 ) ;
F_44 () ;
F_45 ( & V_57 ) ;
return 0 ;
}
static void F_42 ( struct V_12 * V_13 , int V_54 )
{
F_67 ( & V_13 -> V_74 ) ;
V_13 -> V_54 = V_54 ;
F_63 ( V_13 ) ;
}
void F_68 ( struct V_12 * V_13 , int V_54 )
{
F_43 ( & V_57 ) ;
F_42 ( V_13 , V_54 ) ;
F_44 () ;
F_45 ( & V_57 ) ;
}
static int F_69 ( struct V_12 * V_13 )
{
if ( F_46 ( V_13 ) )
return - V_80 ;
if ( V_13 == V_44 ) {
F_60 () ;
if ( V_44 == V_13 )
return - V_80 ;
}
F_37 ( V_13 ) ;
F_38 ( & V_13 -> V_74 ) ;
return 0 ;
}
int F_70 ( struct V_12 * V_13 )
{
int V_60 = 0 ;
F_43 ( & V_57 ) ;
if ( ! F_9 ( & V_13 -> V_74 ) )
V_60 = F_69 ( V_13 ) ;
F_45 ( & V_57 ) ;
return V_60 ;
}
static T_6
F_71 ( struct V_81 * V_82 ,
struct V_83 * V_84 , char * V_85 )
{
T_6 V_86 = 0 ;
F_43 ( & V_57 ) ;
V_86 = snprintf ( V_85 , V_87 , L_9 , V_44 -> V_42 ) ;
F_45 ( & V_57 ) ;
return V_86 ;
}
T_6 F_72 ( const char * V_85 , char * V_88 , T_7 V_89 )
{
T_7 V_60 = V_89 ;
if ( ! V_89 || V_89 >= V_90 )
return - V_91 ;
if ( V_85 [ V_89 - 1 ] == '\n' )
V_89 -- ;
if ( V_89 > 0 )
memcpy ( V_88 , V_85 , V_89 ) ;
V_88 [ V_89 ] = 0 ;
return V_60 ;
}
static T_6 F_73 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
const char * V_85 , T_7 V_86 )
{
T_6 V_60 ;
F_43 ( & V_57 ) ;
V_60 = F_72 ( V_85 , V_71 , V_86 ) ;
if ( V_60 >= 0 )
F_44 () ;
F_45 ( & V_57 ) ;
return V_60 ;
}
static T_6 F_74 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
const char * V_85 , T_7 V_86 )
{
struct V_12 * V_13 ;
char V_42 [ V_90 ] ;
T_6 V_60 ;
V_60 = F_72 ( V_85 , V_42 , V_86 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = - V_92 ;
F_43 ( & V_57 ) ;
F_15 (cs, &clocksource_list, list) {
if ( strcmp ( V_13 -> V_42 , V_42 ) )
continue;
V_60 = F_69 ( V_13 ) ;
break;
}
F_45 ( & V_57 ) ;
return V_60 ? V_60 : V_86 ;
}
static T_6
F_75 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
struct V_12 * V_93 ;
T_6 V_86 = 0 ;
F_43 ( & V_57 ) ;
F_15 (src, &clocksource_list, list) {
if ( ! F_57 () ||
( V_93 -> V_14 & V_15 ) )
V_86 += snprintf ( V_85 + V_86 ,
F_76 ( ( T_6 ) V_87 - V_86 , ( T_6 ) 0 ) ,
L_10 , V_93 -> V_42 ) ;
}
F_45 ( & V_57 ) ;
V_86 += snprintf ( V_85 + V_86 ,
F_76 ( ( T_6 ) V_87 - V_86 , ( T_6 ) 0 ) , L_11 ) ;
return V_86 ;
}
static int T_5 F_77 ( void )
{
int error = F_78 ( & V_94 , NULL ) ;
if ( ! error )
error = F_79 ( & V_95 ) ;
if ( ! error )
error = F_80 (
& V_95 ,
& V_96 ) ;
if ( ! error )
error = F_80 ( & V_95 ,
& V_97 ) ;
if ( ! error )
error = F_80 (
& V_95 ,
& V_98 ) ;
return error ;
}
static int T_5 F_81 ( char * V_99 )
{
F_43 ( & V_57 ) ;
if ( V_99 )
F_82 ( V_71 , V_99 , sizeof( V_71 ) ) ;
F_45 ( & V_57 ) ;
return 1 ;
}
static int T_5 F_83 ( char * V_99 )
{
if ( ! strcmp ( V_99 , L_12 ) ) {
F_20 ( L_13 ) ;
return F_81 ( L_14 ) ;
}
F_20 ( L_15 ) ;
return F_81 ( V_99 ) ;
}
