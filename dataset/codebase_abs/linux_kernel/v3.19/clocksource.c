void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_4 -> V_7 ( V_4 ) ;
V_2 -> V_8 = V_5 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_2 V_9 , V_10 ;
T_1 V_11 ;
V_9 = V_2 -> V_4 -> V_7 ( V_2 -> V_4 ) ;
V_10 = ( V_9 - V_2 -> V_6 ) & V_2 -> V_4 -> V_12 ;
V_11 = F_3 ( V_2 -> V_4 , V_10 ) ;
V_2 -> V_6 = V_9 ;
return V_11 ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_2 ( V_2 ) ;
V_8 += V_2 -> V_8 ;
V_2 -> V_8 = V_8 ;
return V_8 ;
}
T_1 F_5 ( struct V_1 * V_2 ,
T_2 V_13 )
{
T_1 V_10 = ( V_13 - V_2 -> V_6 ) & V_2 -> V_4 -> V_12 ;
T_1 V_8 ;
if ( V_10 > V_2 -> V_4 -> V_12 / 2 ) {
V_10 = ( V_2 -> V_6 - V_13 ) & V_2 -> V_4 -> V_12 ;
V_8 = V_2 -> V_8 - F_3 ( V_2 -> V_4 , V_10 ) ;
} else {
V_8 = F_3 ( V_2 -> V_4 , V_10 ) + V_2 -> V_8 ;
}
return V_8 ;
}
void
F_6 ( T_3 * V_14 , T_3 * V_15 , T_3 V_16 , T_3 V_17 , T_3 V_18 )
{
T_1 V_19 ;
T_3 V_20 , V_21 = 32 ;
V_19 = ( ( T_1 ) V_18 * V_16 ) >> 32 ;
while ( V_19 ) {
V_19 >>= 1 ;
V_21 -- ;
}
for ( V_20 = 32 ; V_20 > 0 ; V_20 -- ) {
V_19 = ( T_1 ) V_17 << V_20 ;
V_19 += V_16 / 2 ;
F_7 ( V_19 , V_16 ) ;
if ( ( V_19 >> V_21 ) == 0 )
break;
}
* V_14 = V_19 ;
* V_15 = V_20 ;
}
static void F_8 ( struct V_22 * V_23 )
{
F_9 ( V_24 , NULL , L_1 ) ;
}
static void F_10 ( struct V_25 * V_26 )
{
V_26 -> V_27 &= ~ ( V_28 | V_29 ) ;
V_26 -> V_27 |= V_30 ;
if ( V_31 )
F_11 ( & V_32 ) ;
}
static void F_12 ( struct V_25 * V_26 , T_4 V_33 )
{
F_13 ( V_34 L_2 ,
V_26 -> V_35 , V_33 ) ;
F_10 ( V_26 ) ;
}
void F_14 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( ! ( V_26 -> V_27 & V_30 ) ) {
if ( F_16 ( & V_26 -> V_37 ) )
F_17 ( & V_26 -> V_37 , & V_38 ) ;
F_10 ( V_26 ) ;
}
F_18 ( & V_36 , V_27 ) ;
}
static void F_19 ( unsigned long V_39 )
{
struct V_25 * V_26 ;
T_2 V_40 , V_41 , V_33 ;
T_4 V_42 , V_43 ;
int V_44 , V_45 ;
F_20 ( & V_36 ) ;
if ( ! V_46 )
goto V_47;
V_45 = F_21 ( & V_48 ) ;
F_22 (cs, &watchdog_list, wd_list) {
if ( V_26 -> V_27 & V_30 ) {
if ( V_31 )
F_11 ( & V_32 ) ;
continue;
}
F_23 () ;
V_40 = V_26 -> V_7 ( V_26 ) ;
V_41 = V_49 -> V_7 ( V_49 ) ;
F_24 () ;
if ( ! ( V_26 -> V_27 & V_29 ) ||
F_21 ( & V_48 ) ) {
V_26 -> V_27 |= V_29 ;
V_26 -> V_50 = V_41 ;
V_26 -> V_51 = V_40 ;
continue;
}
V_33 = F_25 ( V_41 , V_26 -> V_50 , V_49 -> V_12 ) ;
V_42 = F_26 ( V_33 , V_49 -> V_14 ,
V_49 -> V_15 ) ;
V_33 = F_25 ( V_40 , V_26 -> V_51 , V_26 -> V_12 ) ;
V_43 = F_26 ( V_33 , V_26 -> V_14 , V_26 -> V_15 ) ;
V_26 -> V_51 = V_40 ;
V_26 -> V_50 = V_41 ;
if ( F_21 ( & V_48 ) )
continue;
if ( ( abs ( V_43 - V_42 ) > V_52 ) ) {
F_12 ( V_26 , V_43 - V_42 ) ;
continue;
}
if ( ! ( V_26 -> V_27 & V_28 ) &&
( V_26 -> V_27 & V_53 ) &&
( V_49 -> V_27 & V_53 ) ) {
V_26 -> V_27 |= V_28 ;
if ( ! V_31 )
continue;
if ( V_26 != V_54 ) {
V_26 -> V_27 |= V_55 ;
F_11 ( & V_32 ) ;
} else {
F_27 () ;
}
}
}
if ( V_45 )
F_28 ( & V_48 ) ;
V_44 = F_29 ( F_30 () , V_56 ) ;
if ( V_44 >= V_57 )
V_44 = F_31 ( V_56 ) ;
V_58 . V_59 += V_60 ;
F_32 ( & V_58 , V_44 ) ;
V_47:
F_33 ( & V_36 ) ;
}
static inline void F_34 ( void )
{
if ( V_46 || ! V_49 || F_16 ( & V_38 ) )
return;
F_35 ( & V_58 ) ;
V_58 . V_61 = F_19 ;
V_58 . V_59 = V_62 + V_60 ;
F_32 ( & V_58 , F_31 ( V_56 ) ) ;
V_46 = 1 ;
}
static inline void F_36 ( void )
{
if ( ! V_46 || ( V_49 && ! F_16 ( & V_38 ) ) )
return;
F_37 ( & V_58 ) ;
V_46 = 0 ;
}
static inline void F_38 ( void )
{
struct V_25 * V_26 ;
F_22 (cs, &watchdog_list, wd_list)
V_26 -> V_27 &= ~ V_29 ;
}
static void F_39 ( void )
{
F_40 ( & V_48 ) ;
}
static void F_41 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( V_26 -> V_27 & V_63 ) {
F_17 ( & V_26 -> V_37 , & V_38 ) ;
V_26 -> V_27 &= ~ V_29 ;
} else {
if ( V_26 -> V_27 & V_53 )
V_26 -> V_27 |= V_28 ;
if ( ! V_49 || V_26 -> V_64 > V_49 -> V_64 ) {
V_49 = V_26 ;
F_38 () ;
}
}
F_34 () ;
F_18 ( & V_36 , V_27 ) ;
}
static void F_42 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( V_26 != V_49 ) {
if ( V_26 -> V_27 & V_63 ) {
F_43 ( & V_26 -> V_37 ) ;
F_36 () ;
}
}
F_18 ( & V_36 , V_27 ) ;
}
static int F_44 ( void )
{
struct V_25 * V_26 , * V_19 ;
unsigned long V_27 ;
F_45 ( V_65 ) ;
int V_66 = 0 ;
F_15 ( & V_36 , V_27 ) ;
F_46 (cs, tmp, &watchdog_list, wd_list) {
if ( V_26 -> V_27 & V_30 ) {
F_43 ( & V_26 -> V_37 ) ;
F_17 ( & V_26 -> V_37 , & V_65 ) ;
V_66 = 1 ;
}
if ( V_26 -> V_27 & V_55 ) {
V_26 -> V_27 &= ~ V_55 ;
V_66 = 1 ;
}
}
F_36 () ;
F_18 ( & V_36 , V_27 ) ;
F_46 (cs, tmp, &unstable, wd_list) {
F_43 ( & V_26 -> V_37 ) ;
F_47 ( V_26 , 0 ) ;
}
return V_66 ;
}
static int V_24 ( void * V_39 )
{
F_48 ( & V_67 ) ;
if ( F_44 () )
F_49 () ;
F_50 ( & V_67 ) ;
return 0 ;
}
static bool F_51 ( struct V_25 * V_26 )
{
return V_26 == V_49 ;
}
static void F_41 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 & V_53 )
V_26 -> V_27 |= V_28 ;
}
static inline void F_42 ( struct V_25 * V_26 ) { }
static inline void F_39 ( void ) { }
static inline int F_44 ( void ) { return 0 ; }
static bool F_51 ( struct V_25 * V_26 ) { return false ; }
void F_14 ( struct V_25 * V_26 ) { }
void F_52 ( void )
{
struct V_25 * V_26 ;
F_53 (cs, &clocksource_list, list)
if ( V_26 -> V_68 )
V_26 -> V_68 ( V_26 ) ;
}
void F_54 ( void )
{
struct V_25 * V_26 ;
F_22 (cs, &clocksource_list, list)
if ( V_26 -> V_69 )
V_26 -> V_69 ( V_26 ) ;
F_39 () ;
}
void F_55 ( void )
{
F_39 () ;
}
static T_3 F_56 ( struct V_25 * V_26 )
{
T_1 V_70 ;
V_70 = ( T_1 ) V_26 -> V_14 * 11 ;
F_7 ( V_70 , 100 ) ;
return ( T_3 ) V_70 ;
}
T_1 F_57 ( T_3 V_14 , T_3 V_15 , T_3 V_71 , T_1 V_12 )
{
T_1 V_72 , V_73 ;
V_73 = 1ULL << ( 63 - ( F_58 ( V_14 + V_71 ) + 1 ) ) ;
V_73 = F_59 ( V_73 , V_12 ) ;
V_72 = F_26 ( V_73 , V_14 - V_71 , V_15 ) ;
return V_72 ;
}
static T_1 F_60 ( struct V_25 * V_26 )
{
T_1 V_72 ;
V_72 = F_57 ( V_26 -> V_14 , V_26 -> V_15 , V_26 -> V_71 ,
V_26 -> V_12 ) ;
return V_72 - ( V_72 >> 3 ) ;
}
static struct V_25 * F_61 ( bool V_74 , bool V_75 )
{
struct V_25 * V_26 ;
if ( ! V_31 || F_16 ( & V_76 ) )
return NULL ;
F_22 (cs, &clocksource_list, list) {
if ( V_75 && V_26 == V_54 )
continue;
if ( V_74 && ! ( V_26 -> V_27 & V_28 ) )
continue;
return V_26 ;
}
return NULL ;
}
static void F_62 ( bool V_75 )
{
bool V_74 = F_63 () ;
struct V_25 * V_77 , * V_26 ;
V_77 = F_61 ( V_74 , V_75 ) ;
if ( ! V_77 )
return;
F_22 (cs, &clocksource_list, list) {
if ( V_75 && V_26 == V_54 )
continue;
if ( strcmp ( V_26 -> V_35 , V_78 ) != 0 )
continue;
if ( ! ( V_26 -> V_27 & V_28 ) && V_74 ) {
F_13 ( V_34 L_3
L_4
L_5 , V_26 -> V_35 ) ;
V_78 [ 0 ] = 0 ;
} else
V_77 = V_26 ;
break;
}
if ( V_54 != V_77 && ! F_64 ( V_77 ) ) {
F_65 ( L_6 , V_77 -> V_35 ) ;
V_54 = V_77 ;
}
}
static void F_49 ( void )
{
return F_62 ( false ) ;
}
static void F_66 ( void )
{
return F_62 ( true ) ;
}
static inline void F_49 ( void ) { }
static inline void F_66 ( void ) { }
static int T_5 F_67 ( void )
{
F_48 ( & V_67 ) ;
V_54 = F_68 () ;
V_31 = 1 ;
F_44 () ;
F_49 () ;
F_50 ( & V_67 ) ;
return 0 ;
}
static void F_69 ( struct V_25 * V_26 )
{
struct V_79 * V_80 = & V_76 ;
struct V_25 * V_19 ;
F_22 (tmp, &clocksource_list, list)
if ( V_19 -> V_64 >= V_26 -> V_64 )
V_80 = & V_19 -> V_81 ;
F_17 ( & V_26 -> V_81 , V_80 ) ;
}
void F_70 ( struct V_25 * V_26 , T_3 V_82 , T_3 V_83 )
{
T_1 V_84 ;
V_84 = ( V_26 -> V_12 - ( V_26 -> V_12 >> 3 ) ) ;
F_7 ( V_84 , V_83 ) ;
F_7 ( V_84 , V_82 ) ;
if ( ! V_84 )
V_84 = 1 ;
else if ( V_84 > 600 && V_26 -> V_12 > V_85 )
V_84 = 600 ;
F_6 ( & V_26 -> V_14 , & V_26 -> V_15 , V_83 ,
V_86 / V_82 , V_84 * V_82 ) ;
V_26 -> V_71 = F_56 ( V_26 ) ;
while ( ( V_26 -> V_14 + V_26 -> V_71 < V_26 -> V_14 )
|| ( V_26 -> V_14 - V_26 -> V_71 > V_26 -> V_14 ) ) {
V_26 -> V_14 >>= 1 ;
V_26 -> V_15 -- ;
V_26 -> V_71 = F_56 ( V_26 ) ;
}
V_26 -> V_87 = F_60 ( V_26 ) ;
}
int F_71 ( struct V_25 * V_26 , T_3 V_82 , T_3 V_83 )
{
F_70 ( V_26 , V_82 , V_83 ) ;
F_48 ( & V_67 ) ;
F_69 ( V_26 ) ;
F_41 ( V_26 ) ;
F_49 () ;
F_50 ( & V_67 ) ;
return 0 ;
}
int F_72 ( struct V_25 * V_26 )
{
V_26 -> V_71 = F_56 ( V_26 ) ;
F_73 ( V_26 -> V_14 + V_26 -> V_71 < V_26 -> V_14 ,
L_7 ,
V_26 -> V_35 ) ;
V_26 -> V_87 = F_60 ( V_26 ) ;
F_48 ( & V_67 ) ;
F_69 ( V_26 ) ;
F_41 ( V_26 ) ;
F_49 () ;
F_50 ( & V_67 ) ;
return 0 ;
}
static void F_47 ( struct V_25 * V_26 , int V_64 )
{
F_74 ( & V_26 -> V_81 ) ;
V_26 -> V_64 = V_64 ;
F_69 ( V_26 ) ;
}
void F_75 ( struct V_25 * V_26 , int V_64 )
{
F_48 ( & V_67 ) ;
F_47 ( V_26 , V_64 ) ;
F_49 () ;
F_50 ( & V_67 ) ;
}
static int F_76 ( struct V_25 * V_26 )
{
if ( F_51 ( V_26 ) )
return - V_88 ;
if ( V_26 == V_54 ) {
F_66 () ;
if ( V_54 == V_26 )
return - V_88 ;
}
F_42 ( V_26 ) ;
F_43 ( & V_26 -> V_81 ) ;
return 0 ;
}
int F_77 ( struct V_25 * V_26 )
{
int V_70 = 0 ;
F_48 ( & V_67 ) ;
if ( ! F_16 ( & V_26 -> V_81 ) )
V_70 = F_76 ( V_26 ) ;
F_50 ( & V_67 ) ;
return V_70 ;
}
static T_6
F_78 ( struct V_89 * V_90 ,
struct V_91 * V_92 , char * V_93 )
{
T_6 V_94 = 0 ;
F_48 ( & V_67 ) ;
V_94 = snprintf ( V_93 , V_95 , L_8 , V_54 -> V_35 ) ;
F_50 ( & V_67 ) ;
return V_94 ;
}
T_6 F_79 ( const char * V_93 , char * V_96 , T_7 V_97 )
{
T_7 V_70 = V_97 ;
if ( ! V_97 || V_97 >= V_98 )
return - V_99 ;
if ( V_93 [ V_97 - 1 ] == '\n' )
V_97 -- ;
if ( V_97 > 0 )
memcpy ( V_96 , V_93 , V_97 ) ;
V_96 [ V_97 ] = 0 ;
return V_70 ;
}
static T_6 F_80 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
const char * V_93 , T_7 V_94 )
{
T_6 V_70 ;
F_48 ( & V_67 ) ;
V_70 = F_79 ( V_93 , V_78 , V_94 ) ;
if ( V_70 >= 0 )
F_49 () ;
F_50 ( & V_67 ) ;
return V_70 ;
}
static T_6 F_81 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
const char * V_93 , T_7 V_94 )
{
struct V_25 * V_26 ;
char V_35 [ V_98 ] ;
T_6 V_70 ;
V_70 = F_79 ( V_93 , V_35 , V_94 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = - V_100 ;
F_48 ( & V_67 ) ;
F_22 (cs, &clocksource_list, list) {
if ( strcmp ( V_26 -> V_35 , V_35 ) )
continue;
V_70 = F_76 ( V_26 ) ;
break;
}
F_50 ( & V_67 ) ;
return V_70 ? V_70 : V_94 ;
}
static T_6
F_82 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
char * V_93 )
{
struct V_25 * V_101 ;
T_6 V_94 = 0 ;
F_48 ( & V_67 ) ;
F_22 (src, &clocksource_list, list) {
if ( ! F_63 () ||
( V_101 -> V_27 & V_28 ) )
V_94 += snprintf ( V_93 + V_94 ,
F_83 ( ( T_6 ) V_95 - V_94 , ( T_6 ) 0 ) ,
L_9 , V_101 -> V_35 ) ;
}
F_50 ( & V_67 ) ;
V_94 += snprintf ( V_93 + V_94 ,
F_83 ( ( T_6 ) V_95 - V_94 , ( T_6 ) 0 ) , L_10 ) ;
return V_94 ;
}
static int T_5 F_84 ( void )
{
int error = F_85 ( & V_102 , NULL ) ;
if ( ! error )
error = F_86 ( & V_103 ) ;
if ( ! error )
error = F_87 (
& V_103 ,
& V_104 ) ;
if ( ! error )
error = F_87 ( & V_103 ,
& V_105 ) ;
if ( ! error )
error = F_87 (
& V_103 ,
& V_106 ) ;
return error ;
}
static int T_5 F_88 ( char * V_107 )
{
F_48 ( & V_67 ) ;
if ( V_107 )
F_89 ( V_78 , V_107 , sizeof( V_78 ) ) ;
F_50 ( & V_67 ) ;
return 1 ;
}
static int T_5 F_90 ( char * V_107 )
{
if ( ! strcmp ( V_107 , L_11 ) ) {
F_13 ( L_12
L_13 ) ;
return F_88 ( L_14 ) ;
}
F_13 ( L_15
L_16 ) ;
return F_88 ( V_107 ) ;
}
