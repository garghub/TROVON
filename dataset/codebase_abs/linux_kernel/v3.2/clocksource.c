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
T_2 V_40 , V_41 ;
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
V_42 = F_25 ( ( V_41 - V_26 -> V_50 ) & V_49 -> V_12 ,
V_49 -> V_14 , V_49 -> V_15 ) ;
V_43 = F_25 ( ( V_40 - V_26 -> V_51 ) &
V_26 -> V_12 , V_26 -> V_14 , V_26 -> V_15 ) ;
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
F_26 () ;
}
}
if ( V_45 )
F_27 ( & V_48 ) ;
V_44 = F_28 ( F_29 () , V_54 ) ;
if ( V_44 >= V_55 )
V_44 = F_30 ( V_54 ) ;
V_56 . V_57 += V_58 ;
F_31 ( & V_56 , V_44 ) ;
V_47:
F_32 ( & V_36 ) ;
}
static inline void F_33 ( void )
{
if ( V_46 || ! V_49 || F_16 ( & V_38 ) )
return;
F_34 ( & V_56 ) ;
V_56 . V_59 = F_19 ;
V_56 . V_57 = V_60 + V_58 ;
F_31 ( & V_56 , F_30 ( V_54 ) ) ;
V_46 = 1 ;
}
static inline void F_35 ( void )
{
if ( ! V_46 || ( V_49 && ! F_16 ( & V_38 ) ) )
return;
F_36 ( & V_56 ) ;
V_46 = 0 ;
}
static inline void F_37 ( void )
{
struct V_25 * V_26 ;
F_22 (cs, &watchdog_list, wd_list)
V_26 -> V_27 &= ~ V_29 ;
}
static void F_38 ( void )
{
F_39 ( & V_48 ) ;
}
static void F_40 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( V_26 -> V_27 & V_61 ) {
F_17 ( & V_26 -> V_37 , & V_38 ) ;
V_26 -> V_27 &= ~ V_29 ;
} else {
if ( V_26 -> V_27 & V_53 )
V_26 -> V_27 |= V_28 ;
if ( ! V_49 || V_26 -> V_62 > V_49 -> V_62 ) {
V_49 = V_26 ;
F_37 () ;
}
}
F_33 () ;
F_18 ( & V_36 , V_27 ) ;
}
static void F_41 ( struct V_25 * V_26 )
{
struct V_25 * V_19 ;
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( V_26 -> V_27 & V_61 ) {
F_42 ( & V_26 -> V_37 ) ;
} else if ( V_26 == V_49 ) {
F_37 () ;
V_49 = NULL ;
F_22 (tmp, &clocksource_list, list) {
if ( V_19 == V_26 || V_19 -> V_27 & V_61 )
continue;
if ( ! V_49 || V_19 -> V_62 > V_49 -> V_62 )
V_49 = V_19 ;
}
}
V_26 -> V_27 &= ~ V_29 ;
F_35 () ;
F_18 ( & V_36 , V_27 ) ;
}
static int V_24 ( void * V_39 )
{
struct V_25 * V_26 , * V_19 ;
unsigned long V_27 ;
F_43 ( V_63 ) ;
F_44 ( & V_64 ) ;
F_15 ( & V_36 , V_27 ) ;
F_45 (cs, tmp, &watchdog_list, wd_list)
if ( V_26 -> V_27 & V_30 ) {
F_42 ( & V_26 -> V_37 ) ;
F_17 ( & V_26 -> V_37 , & V_63 ) ;
}
F_35 () ;
F_18 ( & V_36 , V_27 ) ;
F_45 (cs, tmp, &unstable, wd_list) {
F_42 ( & V_26 -> V_37 ) ;
F_46 ( V_26 , 0 ) ;
}
F_47 ( & V_64 ) ;
return 0 ;
}
static void F_40 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 & V_53 )
V_26 -> V_27 |= V_28 ;
}
static inline void F_41 ( struct V_25 * V_26 ) { }
static inline void F_38 ( void ) { }
static inline int V_24 ( void * V_39 ) { return 0 ; }
void F_48 ( void )
{
struct V_25 * V_26 ;
F_49 (cs, &clocksource_list, list)
if ( V_26 -> V_65 )
V_26 -> V_65 ( V_26 ) ;
}
void F_50 ( void )
{
struct V_25 * V_26 ;
F_22 (cs, &clocksource_list, list)
if ( V_26 -> V_66 )
V_26 -> V_66 ( V_26 ) ;
F_38 () ;
}
void F_51 ( void )
{
F_38 () ;
}
static T_3 F_52 ( struct V_25 * V_26 )
{
T_1 V_67 ;
V_67 = ( T_1 ) V_26 -> V_14 * 11 ;
F_7 ( V_67 , 100 ) ;
return ( T_3 ) V_67 ;
}
static T_1 F_53 ( struct V_25 * V_26 )
{
T_1 V_68 , V_69 ;
V_69 = 1ULL << ( 63 - ( F_54 ( V_26 -> V_14 + V_26 -> V_70 ) + 1 ) ) ;
V_69 = F_55 ( T_1 , V_69 , ( T_1 ) V_26 -> V_12 ) ;
V_68 = F_25 ( V_69 , V_26 -> V_14 - V_26 -> V_70 ,
V_26 -> V_15 ) ;
return V_68 - ( V_68 >> 3 ) ;
}
static void F_56 ( void )
{
struct V_25 * V_71 , * V_26 ;
if ( ! V_31 || F_16 ( & V_72 ) )
return;
V_71 = F_57 ( & V_72 , struct V_25 , V_73 ) ;
F_22 (cs, &clocksource_list, list) {
if ( strcmp ( V_26 -> V_35 , V_74 ) != 0 )
continue;
if ( ! ( V_26 -> V_27 & V_28 ) &&
F_58 () ) {
F_13 ( V_34 L_3
L_4
L_5 , V_26 -> V_35 ) ;
V_74 [ 0 ] = 0 ;
} else
V_71 = V_26 ;
break;
}
if ( V_75 != V_71 ) {
F_13 ( V_76 L_6 , V_71 -> V_35 ) ;
V_75 = V_71 ;
F_59 ( V_75 ) ;
}
}
static inline void F_56 ( void ) { }
static int T_5 F_60 ( void )
{
F_44 ( & V_64 ) ;
V_75 = F_61 () ;
F_47 ( & V_64 ) ;
V_31 = 1 ;
V_24 ( NULL ) ;
F_44 ( & V_64 ) ;
F_56 () ;
F_47 ( & V_64 ) ;
return 0 ;
}
static void F_62 ( struct V_25 * V_26 )
{
struct V_77 * V_78 = & V_72 ;
struct V_25 * V_19 ;
F_22 (tmp, &clocksource_list, list)
if ( V_19 -> V_62 >= V_26 -> V_62 )
V_78 = & V_19 -> V_73 ;
F_17 ( & V_26 -> V_73 , V_78 ) ;
}
void F_63 ( struct V_25 * V_26 , T_3 V_79 , T_3 V_80 )
{
T_1 V_81 ;
V_81 = ( V_26 -> V_12 - ( V_26 -> V_12 >> 3 ) ) ;
F_7 ( V_81 , V_80 ) ;
F_7 ( V_81 , V_79 ) ;
if ( ! V_81 )
V_81 = 1 ;
else if ( V_81 > 600 && V_26 -> V_12 > V_82 )
V_81 = 600 ;
F_6 ( & V_26 -> V_14 , & V_26 -> V_15 , V_80 ,
V_83 / V_79 , V_81 * V_79 ) ;
V_26 -> V_70 = F_52 ( V_26 ) ;
while ( ( V_26 -> V_14 + V_26 -> V_70 < V_26 -> V_14 )
|| ( V_26 -> V_14 - V_26 -> V_70 > V_26 -> V_14 ) ) {
V_26 -> V_14 >>= 1 ;
V_26 -> V_15 -- ;
V_26 -> V_70 = F_52 ( V_26 ) ;
}
V_26 -> V_84 = F_53 ( V_26 ) ;
}
int F_64 ( struct V_25 * V_26 , T_3 V_79 , T_3 V_80 )
{
F_63 ( V_26 , V_79 , V_80 ) ;
F_44 ( & V_64 ) ;
F_62 ( V_26 ) ;
F_40 ( V_26 ) ;
F_56 () ;
F_47 ( & V_64 ) ;
return 0 ;
}
int F_65 ( struct V_25 * V_26 )
{
V_26 -> V_70 = F_52 ( V_26 ) ;
F_66 ( V_26 -> V_14 + V_26 -> V_70 < V_26 -> V_14 ,
L_7 ,
V_26 -> V_35 ) ;
V_26 -> V_84 = F_53 ( V_26 ) ;
F_44 ( & V_64 ) ;
F_62 ( V_26 ) ;
F_40 ( V_26 ) ;
F_56 () ;
F_47 ( & V_64 ) ;
return 0 ;
}
static void F_46 ( struct V_25 * V_26 , int V_62 )
{
F_67 ( & V_26 -> V_73 ) ;
V_26 -> V_62 = V_62 ;
F_62 ( V_26 ) ;
F_56 () ;
}
void F_68 ( struct V_25 * V_26 , int V_62 )
{
F_44 ( & V_64 ) ;
F_46 ( V_26 , V_62 ) ;
F_47 ( & V_64 ) ;
}
void F_69 ( struct V_25 * V_26 )
{
F_44 ( & V_64 ) ;
F_41 ( V_26 ) ;
F_67 ( & V_26 -> V_73 ) ;
F_56 () ;
F_47 ( & V_64 ) ;
}
static T_6
F_70 ( struct V_85 * V_86 ,
struct V_87 * V_88 , char * V_89 )
{
T_6 V_90 = 0 ;
F_44 ( & V_64 ) ;
V_90 = snprintf ( V_89 , V_91 , L_8 , V_75 -> V_35 ) ;
F_47 ( & V_64 ) ;
return V_90 ;
}
static T_6 F_71 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
const char * V_89 , T_7 V_90 )
{
T_7 V_67 = V_90 ;
if ( V_90 >= sizeof( V_74 ) )
return - V_92 ;
if ( V_89 [ V_90 - 1 ] == '\n' )
V_90 -- ;
F_44 ( & V_64 ) ;
if ( V_90 > 0 )
memcpy ( V_74 , V_89 , V_90 ) ;
V_74 [ V_90 ] = 0 ;
F_56 () ;
F_47 ( & V_64 ) ;
return V_67 ;
}
static T_6
F_72 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
struct V_25 * V_93 ;
T_6 V_90 = 0 ;
F_44 ( & V_64 ) ;
F_22 (src, &clocksource_list, list) {
if ( ! F_58 () ||
( V_93 -> V_27 & V_28 ) )
V_90 += snprintf ( V_89 + V_90 ,
F_73 ( ( T_6 ) V_91 - V_90 , ( T_6 ) 0 ) ,
L_9 , V_93 -> V_35 ) ;
}
F_47 ( & V_64 ) ;
V_90 += snprintf ( V_89 + V_90 ,
F_73 ( ( T_6 ) V_91 - V_90 , ( T_6 ) 0 ) , L_10 ) ;
return V_90 ;
}
static int T_5 F_74 ( void )
{
int error = F_75 ( & V_94 ) ;
if ( ! error )
error = F_76 ( & V_95 ) ;
if ( ! error )
error = F_77 (
& V_95 ,
& V_96 ) ;
if ( ! error )
error = F_77 (
& V_95 ,
& V_97 ) ;
return error ;
}
static int T_5 F_78 ( char * V_98 )
{
F_44 ( & V_64 ) ;
if ( V_98 )
F_79 ( V_74 , V_98 , sizeof( V_74 ) ) ;
F_47 ( & V_64 ) ;
return 1 ;
}
static int T_5 F_80 ( char * V_98 )
{
if ( ! strcmp ( V_98 , L_11 ) ) {
F_13 ( L_12
L_13 ) ;
return F_78 ( L_14 ) ;
}
F_13 ( L_15
L_16 ) ;
return F_78 ( V_98 ) ;
}
