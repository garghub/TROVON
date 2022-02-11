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
if ( V_13 -> V_18 )
V_13 -> V_18 ( V_13 ) ;
if ( V_19 )
F_6 ( & V_20 ) ;
}
void F_7 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_21 , V_14 ) ;
if ( ! ( V_13 -> V_14 & V_17 ) ) {
if ( F_9 ( & V_13 -> V_22 ) )
F_10 ( & V_13 -> V_22 , & V_23 ) ;
F_5 ( V_13 ) ;
}
F_11 ( & V_21 , V_14 ) ;
}
static void F_12 ( unsigned long V_24 )
{
struct V_12 * V_13 ;
T_2 V_25 , V_26 , V_27 , V_28 , V_29 ;
T_3 V_30 , V_31 ;
int V_32 , V_33 ;
F_13 ( & V_21 ) ;
if ( ! V_34 )
goto V_35;
V_33 = F_14 ( & V_36 ) ;
F_15 (cs, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
if ( V_19 )
F_6 ( & V_20 ) ;
continue;
}
F_16 () ;
V_25 = V_13 -> V_37 ( V_13 ) ;
V_26 = V_38 -> V_37 ( V_38 ) ;
F_17 () ;
if ( ! ( V_13 -> V_14 & V_16 ) ||
F_14 ( & V_36 ) ) {
V_13 -> V_14 |= V_16 ;
V_13 -> V_39 = V_26 ;
V_13 -> V_40 = V_25 ;
continue;
}
V_29 = F_18 ( V_26 , V_13 -> V_39 , V_38 -> V_41 ) ;
V_30 = F_19 ( V_29 , V_38 -> V_1 ,
V_38 -> V_2 ) ;
V_29 = F_18 ( V_25 , V_13 -> V_40 , V_13 -> V_41 ) ;
V_31 = F_19 ( V_29 , V_13 -> V_1 , V_13 -> V_2 ) ;
V_28 = V_13 -> V_39 ;
V_27 = V_13 -> V_40 ;
V_13 -> V_40 = V_25 ;
V_13 -> V_39 = V_26 ;
if ( F_14 ( & V_36 ) )
continue;
if ( abs ( V_31 - V_30 ) > V_42 ) {
F_20 ( L_2 ,
F_21 () , V_13 -> V_43 ) ;
F_20 ( L_3 ,
V_38 -> V_43 , V_26 , V_28 , V_38 -> V_41 ) ;
F_20 ( L_4 ,
V_13 -> V_43 , V_25 , V_27 , V_13 -> V_41 ) ;
F_5 ( V_13 ) ;
continue;
}
if ( V_13 == V_44 && V_13 -> V_45 )
V_13 -> V_45 ( V_13 ) ;
if ( ! ( V_13 -> V_14 & V_15 ) &&
( V_13 -> V_14 & V_46 ) &&
( V_38 -> V_14 & V_46 ) ) {
V_13 -> V_14 |= V_15 ;
if ( ! V_19 )
continue;
if ( V_13 != V_44 ) {
V_13 -> V_14 |= V_47 ;
F_6 ( & V_20 ) ;
} else {
F_22 () ;
}
}
}
if ( V_33 )
F_23 ( & V_36 ) ;
V_32 = F_24 ( F_25 () , V_48 ) ;
if ( V_32 >= V_49 )
V_32 = F_26 ( V_48 ) ;
V_50 . V_51 += V_52 ;
F_27 ( & V_50 , V_32 ) ;
V_35:
F_28 ( & V_21 ) ;
}
static inline void F_29 ( void )
{
if ( V_34 || ! V_38 || F_9 ( & V_23 ) )
return;
F_30 ( & V_50 ) ;
V_50 . V_53 = F_12 ;
V_50 . V_51 = V_54 + V_52 ;
F_27 ( & V_50 , F_26 ( V_48 ) ) ;
V_34 = 1 ;
}
static inline void F_31 ( void )
{
if ( ! V_34 || ( V_38 && ! F_9 ( & V_23 ) ) )
return;
F_32 ( & V_50 ) ;
V_34 = 0 ;
}
static inline void F_33 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &watchdog_list, wd_list)
V_13 -> V_14 &= ~ V_16 ;
}
static void F_34 ( void )
{
F_35 ( & V_36 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_21 , V_14 ) ;
if ( V_13 -> V_14 & V_55 ) {
F_10 ( & V_13 -> V_22 , & V_23 ) ;
V_13 -> V_14 &= ~ V_16 ;
} else {
if ( V_13 -> V_14 & V_46 )
V_13 -> V_14 |= V_15 ;
}
F_11 ( & V_21 , V_14 ) ;
}
static void F_37 ( bool V_56 )
{
struct V_12 * V_13 , * V_57 ;
unsigned long V_14 ;
F_8 ( & V_21 , V_14 ) ;
V_57 = V_38 ;
if ( V_56 )
V_38 = NULL ;
F_15 (cs, &clocksource_list, list) {
if ( V_13 -> V_14 & V_55 )
continue;
if ( V_56 && V_13 == V_57 )
continue;
if ( ! V_38 || V_13 -> V_58 > V_38 -> V_58 )
V_38 = V_13 ;
}
if ( ! V_38 )
V_38 = V_57 ;
if ( V_38 != V_57 )
F_33 () ;
F_29 () ;
F_11 ( & V_21 , V_14 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_8 ( & V_21 , V_14 ) ;
if ( V_13 != V_38 ) {
if ( V_13 -> V_14 & V_55 ) {
F_39 ( & V_13 -> V_22 ) ;
F_31 () ;
}
}
F_11 ( & V_21 , V_14 ) ;
}
static int F_40 ( void )
{
struct V_12 * V_13 , * V_6 ;
unsigned long V_14 ;
F_41 ( V_59 ) ;
int V_60 = 0 ;
F_8 ( & V_21 , V_14 ) ;
F_42 (cs, tmp, &watchdog_list, wd_list) {
if ( V_13 -> V_14 & V_17 ) {
F_39 ( & V_13 -> V_22 ) ;
F_10 ( & V_13 -> V_22 , & V_59 ) ;
V_60 = 1 ;
}
if ( V_13 -> V_14 & V_47 ) {
V_13 -> V_14 &= ~ V_47 ;
V_60 = 1 ;
}
}
F_31 () ;
F_11 ( & V_21 , V_14 ) ;
F_42 (cs, tmp, &unstable, wd_list) {
F_39 ( & V_13 -> V_22 ) ;
F_43 ( V_13 , 0 ) ;
}
return V_60 ;
}
static int V_11 ( void * V_24 )
{
F_44 ( & V_61 ) ;
if ( F_40 () )
F_45 () ;
F_46 ( & V_61 ) ;
return 0 ;
}
static bool F_47 ( struct V_12 * V_13 )
{
return V_13 == V_38 ;
}
static void F_36 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 & V_46 )
V_13 -> V_14 |= V_15 ;
}
static void F_37 ( bool V_56 ) { }
static inline void F_38 ( struct V_12 * V_13 ) { }
static inline void F_34 ( void ) { }
static inline int F_40 ( void ) { return 0 ; }
static bool F_47 ( struct V_12 * V_13 ) { return false ; }
void F_7 ( struct V_12 * V_13 ) { }
void F_48 ( void )
{
struct V_12 * V_13 ;
F_49 (cs, &clocksource_list, list)
if ( V_13 -> V_62 )
V_13 -> V_62 ( V_13 ) ;
}
void F_50 ( void )
{
struct V_12 * V_13 ;
F_15 (cs, &clocksource_list, list)
if ( V_13 -> V_63 )
V_13 -> V_63 ( V_13 ) ;
F_34 () ;
}
void F_51 ( void )
{
F_34 () ;
}
static T_1 F_52 ( struct V_12 * V_13 )
{
T_2 V_64 ;
V_64 = ( T_2 ) V_13 -> V_1 * 11 ;
F_2 ( V_64 , 100 ) ;
return ( T_1 ) V_64 ;
}
T_2 F_53 ( T_1 V_1 , T_1 V_2 , T_1 V_65 , T_2 V_41 , T_2 * V_66 )
{
T_2 V_67 , V_68 ;
V_68 = V_69 ;
F_2 ( V_68 , V_1 + V_65 ) ;
V_68 = F_54 ( V_68 , V_41 ) ;
V_67 = F_19 ( V_68 , V_1 - V_65 , V_2 ) ;
if ( V_66 )
* V_66 = V_68 ;
V_67 >>= 1 ;
return V_67 ;
}
static inline void F_55 ( struct V_12 * V_13 )
{
V_13 -> V_70 = F_53 ( V_13 -> V_1 , V_13 -> V_2 ,
V_13 -> V_65 , V_13 -> V_41 ,
& V_13 -> V_68 ) ;
}
static struct V_12 * F_56 ( bool V_71 , bool V_72 )
{
struct V_12 * V_13 ;
if ( ! V_19 || F_9 ( & V_73 ) )
return NULL ;
F_15 (cs, &clocksource_list, list) {
if ( V_72 && V_13 == V_44 )
continue;
if ( V_71 && ! ( V_13 -> V_14 & V_15 ) )
continue;
return V_13 ;
}
return NULL ;
}
static void F_57 ( bool V_72 )
{
bool V_71 = F_58 () ;
struct V_12 * V_74 , * V_13 ;
V_74 = F_56 ( V_71 , V_72 ) ;
if ( ! V_74 )
return;
F_15 (cs, &clocksource_list, list) {
if ( V_72 && V_13 == V_44 )
continue;
if ( strcmp ( V_13 -> V_43 , V_75 ) != 0 )
continue;
if ( ! ( V_13 -> V_14 & V_15 ) && V_71 ) {
if ( V_13 -> V_14 & V_17 ) {
F_20 ( L_5 ,
V_13 -> V_43 ) ;
V_75 [ 0 ] = 0 ;
} else {
F_59 ( L_6 ,
V_13 -> V_43 ) ;
}
} else
V_74 = V_13 ;
break;
}
if ( V_44 != V_74 && ! F_60 ( V_74 ) ) {
F_59 ( L_7 , V_74 -> V_43 ) ;
V_44 = V_74 ;
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
static int T_4 F_62 ( void )
{
F_44 ( & V_61 ) ;
V_44 = F_63 () ;
V_19 = 1 ;
F_40 () ;
F_45 () ;
F_46 ( & V_61 ) ;
return 0 ;
}
static void F_64 ( struct V_12 * V_13 )
{
struct V_76 * V_77 = & V_73 ;
struct V_12 * V_6 ;
F_15 (tmp, &clocksource_list, list) {
if ( V_6 -> V_58 < V_13 -> V_58 )
break;
V_77 = & V_6 -> V_78 ;
}
F_10 ( & V_13 -> V_78 , V_77 ) ;
}
void F_65 ( struct V_12 * V_13 , T_1 V_79 , T_1 V_80 )
{
T_2 V_81 ;
if ( V_80 ) {
V_81 = V_13 -> V_41 ;
F_2 ( V_81 , V_80 ) ;
F_2 ( V_81 , V_79 ) ;
if ( ! V_81 )
V_81 = 1 ;
else if ( V_81 > 600 && V_13 -> V_41 > V_82 )
V_81 = 600 ;
F_1 ( & V_13 -> V_1 , & V_13 -> V_2 , V_80 ,
V_83 / V_79 , V_81 * V_79 ) ;
}
V_13 -> V_65 = F_52 ( V_13 ) ;
while ( V_80 && ( ( V_13 -> V_1 + V_13 -> V_65 < V_13 -> V_1 )
|| ( V_13 -> V_1 - V_13 -> V_65 > V_13 -> V_1 ) ) ) {
V_13 -> V_1 >>= 1 ;
V_13 -> V_2 -- ;
V_13 -> V_65 = F_52 ( V_13 ) ;
}
F_66 ( V_13 -> V_1 + V_13 -> V_65 < V_13 -> V_1 ,
L_8 ,
V_13 -> V_43 ) ;
F_55 ( V_13 ) ;
F_59 ( L_9 ,
V_13 -> V_43 , V_13 -> V_41 , V_13 -> V_68 , V_13 -> V_70 ) ;
}
int F_67 ( struct V_12 * V_13 , T_1 V_79 , T_1 V_80 )
{
F_65 ( V_13 , V_79 , V_80 ) ;
F_44 ( & V_61 ) ;
F_64 ( V_13 ) ;
F_36 ( V_13 ) ;
F_45 () ;
F_37 ( false ) ;
F_46 ( & V_61 ) ;
return 0 ;
}
static void F_43 ( struct V_12 * V_13 , int V_58 )
{
F_68 ( & V_13 -> V_78 ) ;
V_13 -> V_58 = V_58 ;
F_64 ( V_13 ) ;
}
void F_69 ( struct V_12 * V_13 , int V_58 )
{
F_44 ( & V_61 ) ;
F_43 ( V_13 , V_58 ) ;
F_45 () ;
F_37 ( false ) ;
F_46 ( & V_61 ) ;
}
static int F_70 ( struct V_12 * V_13 )
{
if ( F_47 ( V_13 ) ) {
F_37 ( true ) ;
if ( F_47 ( V_13 ) )
return - V_84 ;
}
if ( V_13 == V_44 ) {
F_61 () ;
if ( V_44 == V_13 )
return - V_84 ;
}
F_38 ( V_13 ) ;
F_39 ( & V_13 -> V_78 ) ;
return 0 ;
}
int F_71 ( struct V_12 * V_13 )
{
int V_64 = 0 ;
F_44 ( & V_61 ) ;
if ( ! F_9 ( & V_13 -> V_78 ) )
V_64 = F_70 ( V_13 ) ;
F_46 ( & V_61 ) ;
return V_64 ;
}
static T_5
F_72 ( struct V_85 * V_86 ,
struct V_87 * V_88 , char * V_89 )
{
T_5 V_90 = 0 ;
F_44 ( & V_61 ) ;
V_90 = snprintf ( V_89 , V_91 , L_10 , V_44 -> V_43 ) ;
F_46 ( & V_61 ) ;
return V_90 ;
}
T_5 F_73 ( const char * V_89 , char * V_92 , T_6 V_93 )
{
T_6 V_64 = V_93 ;
if ( ! V_93 || V_93 >= V_94 )
return - V_95 ;
if ( V_89 [ V_93 - 1 ] == '\n' )
V_93 -- ;
if ( V_93 > 0 )
memcpy ( V_92 , V_89 , V_93 ) ;
V_92 [ V_93 ] = 0 ;
return V_64 ;
}
static T_5 F_74 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
const char * V_89 , T_6 V_90 )
{
T_5 V_64 ;
F_44 ( & V_61 ) ;
V_64 = F_73 ( V_89 , V_75 , V_90 ) ;
if ( V_64 >= 0 )
F_45 () ;
F_46 ( & V_61 ) ;
return V_64 ;
}
static T_5 F_75 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
const char * V_89 , T_6 V_90 )
{
struct V_12 * V_13 ;
char V_43 [ V_94 ] ;
T_5 V_64 ;
V_64 = F_73 ( V_89 , V_43 , V_90 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = - V_96 ;
F_44 ( & V_61 ) ;
F_15 (cs, &clocksource_list, list) {
if ( strcmp ( V_13 -> V_43 , V_43 ) )
continue;
V_64 = F_70 ( V_13 ) ;
break;
}
F_46 ( & V_61 ) ;
return V_64 ? V_64 : V_90 ;
}
static T_5
F_76 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
struct V_12 * V_97 ;
T_5 V_90 = 0 ;
F_44 ( & V_61 ) ;
F_15 (src, &clocksource_list, list) {
if ( ! F_58 () ||
( V_97 -> V_14 & V_15 ) )
V_90 += snprintf ( V_89 + V_90 ,
F_77 ( ( T_5 ) V_91 - V_90 , ( T_5 ) 0 ) ,
L_11 , V_97 -> V_43 ) ;
}
F_46 ( & V_61 ) ;
V_90 += snprintf ( V_89 + V_90 ,
F_77 ( ( T_5 ) V_91 - V_90 , ( T_5 ) 0 ) , L_12 ) ;
return V_90 ;
}
static int T_4 F_78 ( void )
{
int error = F_79 ( & V_98 , NULL ) ;
if ( ! error )
error = F_80 ( & V_99 ) ;
if ( ! error )
error = F_81 (
& V_99 ,
& V_100 ) ;
if ( ! error )
error = F_81 ( & V_99 ,
& V_101 ) ;
if ( ! error )
error = F_81 (
& V_99 ,
& V_102 ) ;
return error ;
}
static int T_4 F_82 ( char * V_103 )
{
F_44 ( & V_61 ) ;
if ( V_103 )
F_83 ( V_75 , V_103 , sizeof( V_75 ) ) ;
F_46 ( & V_61 ) ;
return 1 ;
}
static int T_4 F_84 ( char * V_103 )
{
if ( ! strcmp ( V_103 , L_13 ) ) {
F_20 ( L_14 ) ;
return F_82 ( L_15 ) ;
}
F_20 ( L_16 ) ;
return F_82 ( V_103 ) ;
}
