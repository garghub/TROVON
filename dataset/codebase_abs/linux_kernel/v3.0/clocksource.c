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
int V_44 ;
F_20 ( & V_36 ) ;
if ( ! V_45 )
goto V_46;
F_21 (cs, &watchdog_list, wd_list) {
if ( V_26 -> V_27 & V_30 ) {
if ( V_31 )
F_11 ( & V_32 ) ;
continue;
}
F_22 () ;
V_40 = V_26 -> V_7 ( V_26 ) ;
V_41 = V_47 -> V_7 ( V_47 ) ;
F_23 () ;
if ( ! ( V_26 -> V_27 & V_29 ) ) {
V_26 -> V_27 |= V_29 ;
V_26 -> V_48 = V_41 ;
V_26 -> V_49 = V_40 ;
continue;
}
V_42 = F_24 ( ( V_41 - V_26 -> V_48 ) & V_47 -> V_12 ,
V_47 -> V_14 , V_47 -> V_15 ) ;
V_43 = F_24 ( ( V_40 - V_26 -> V_49 ) &
V_26 -> V_12 , V_26 -> V_14 , V_26 -> V_15 ) ;
V_26 -> V_49 = V_40 ;
V_26 -> V_48 = V_41 ;
if ( abs ( V_43 - V_42 ) > V_50 ) {
F_12 ( V_26 , V_43 - V_42 ) ;
continue;
}
if ( ! ( V_26 -> V_27 & V_28 ) &&
( V_26 -> V_27 & V_51 ) &&
( V_47 -> V_27 & V_51 ) ) {
V_26 -> V_27 |= V_28 ;
F_25 () ;
}
}
V_44 = F_26 ( F_27 () , V_52 ) ;
if ( V_44 >= V_53 )
V_44 = F_28 ( V_52 ) ;
V_54 . V_55 += V_56 ;
F_29 ( & V_54 , V_44 ) ;
V_46:
F_30 ( & V_36 ) ;
}
static inline void F_31 ( void )
{
if ( V_45 || ! V_47 || F_16 ( & V_38 ) )
return;
F_32 ( & V_54 ) ;
V_54 . V_57 = F_19 ;
V_54 . V_55 = V_58 + V_56 ;
F_29 ( & V_54 , F_28 ( V_52 ) ) ;
V_45 = 1 ;
}
static inline void F_33 ( void )
{
if ( ! V_45 || ( V_47 && ! F_16 ( & V_38 ) ) )
return;
F_34 ( & V_54 ) ;
V_45 = 0 ;
}
static inline void F_35 ( void )
{
struct V_25 * V_26 ;
F_21 (cs, &watchdog_list, wd_list)
V_26 -> V_27 &= ~ V_29 ;
}
static void F_36 ( void )
{
unsigned long V_27 ;
if ( ! F_37 ( & V_36 , V_27 ) )
return;
F_35 () ;
F_18 ( & V_36 , V_27 ) ;
}
static void F_38 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( V_26 -> V_27 & V_59 ) {
F_17 ( & V_26 -> V_37 , & V_38 ) ;
V_26 -> V_27 &= ~ V_29 ;
} else {
if ( V_26 -> V_27 & V_51 )
V_26 -> V_27 |= V_28 ;
if ( ! V_47 || V_26 -> V_60 > V_47 -> V_60 ) {
V_47 = V_26 ;
F_35 () ;
}
}
F_31 () ;
F_18 ( & V_36 , V_27 ) ;
}
static void F_39 ( struct V_25 * V_26 )
{
struct V_25 * V_19 ;
unsigned long V_27 ;
F_15 ( & V_36 , V_27 ) ;
if ( V_26 -> V_27 & V_59 ) {
F_40 ( & V_26 -> V_37 ) ;
} else if ( V_26 == V_47 ) {
F_35 () ;
V_47 = NULL ;
F_21 (tmp, &clocksource_list, list) {
if ( V_19 == V_26 || V_19 -> V_27 & V_59 )
continue;
if ( ! V_47 || V_19 -> V_60 > V_47 -> V_60 )
V_47 = V_19 ;
}
}
V_26 -> V_27 &= ~ V_29 ;
F_33 () ;
F_18 ( & V_36 , V_27 ) ;
}
static int V_24 ( void * V_39 )
{
struct V_25 * V_26 , * V_19 ;
unsigned long V_27 ;
F_41 ( V_61 ) ;
F_42 ( & V_62 ) ;
F_15 ( & V_36 , V_27 ) ;
F_43 (cs, tmp, &watchdog_list, wd_list)
if ( V_26 -> V_27 & V_30 ) {
F_40 ( & V_26 -> V_37 ) ;
F_17 ( & V_26 -> V_37 , & V_61 ) ;
}
F_33 () ;
F_18 ( & V_36 , V_27 ) ;
F_43 (cs, tmp, &unstable, wd_list) {
F_40 ( & V_26 -> V_37 ) ;
F_44 ( V_26 , 0 ) ;
}
F_45 ( & V_62 ) ;
return 0 ;
}
static void F_38 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 & V_51 )
V_26 -> V_27 |= V_28 ;
}
static inline void F_39 ( struct V_25 * V_26 ) { }
static inline void F_36 ( void ) { }
static inline int V_24 ( void * V_39 ) { return 0 ; }
void F_46 ( void )
{
struct V_25 * V_26 ;
F_47 (cs, &clocksource_list, list)
if ( V_26 -> V_63 )
V_26 -> V_63 ( V_26 ) ;
}
void F_48 ( void )
{
struct V_25 * V_26 ;
F_21 (cs, &clocksource_list, list)
if ( V_26 -> V_64 )
V_26 -> V_64 ( V_26 ) ;
F_36 () ;
}
void F_49 ( void )
{
F_36 () ;
}
static T_1 F_50 ( struct V_25 * V_26 )
{
T_1 V_65 , V_66 ;
V_66 = 1ULL << ( 63 - ( F_51 ( V_26 -> V_14 ) + 1 ) ) ;
V_66 = F_52 ( T_1 , V_66 , ( T_1 ) V_26 -> V_12 ) ;
V_65 = F_24 ( V_66 , V_26 -> V_14 , V_26 -> V_15 ) ;
return V_65 - ( V_65 >> 5 ) ;
}
static void F_53 ( void )
{
struct V_25 * V_67 , * V_26 ;
if ( ! V_31 || F_16 ( & V_68 ) )
return;
V_67 = F_54 ( & V_68 , struct V_25 , V_69 ) ;
F_21 (cs, &clocksource_list, list) {
if ( strcmp ( V_26 -> V_35 , V_70 ) != 0 )
continue;
if ( ! ( V_26 -> V_27 & V_28 ) &&
F_55 () ) {
F_13 ( V_34 L_3
L_4
L_5 , V_26 -> V_35 ) ;
V_70 [ 0 ] = 0 ;
} else
V_67 = V_26 ;
break;
}
if ( V_71 != V_67 ) {
F_13 ( V_72 L_6 , V_67 -> V_35 ) ;
V_71 = V_67 ;
F_56 ( V_71 ) ;
}
}
static inline void F_53 ( void ) { }
static int T_5 F_57 ( void )
{
F_42 ( & V_62 ) ;
V_71 = F_58 () ;
F_45 ( & V_62 ) ;
V_31 = 1 ;
V_24 ( NULL ) ;
F_42 ( & V_62 ) ;
F_53 () ;
F_45 ( & V_62 ) ;
return 0 ;
}
static void F_59 ( struct V_25 * V_26 )
{
struct V_73 * V_74 = & V_68 ;
struct V_25 * V_19 ;
F_21 (tmp, &clocksource_list, list)
if ( V_19 -> V_60 >= V_26 -> V_60 )
V_74 = & V_19 -> V_69 ;
F_17 ( & V_26 -> V_69 , V_74 ) ;
}
void F_60 ( struct V_25 * V_26 , T_3 V_75 , T_3 V_76 )
{
T_1 V_77 ;
V_77 = ( V_26 -> V_12 - ( V_26 -> V_12 >> 5 ) ) ;
F_7 ( V_77 , V_76 ) ;
F_7 ( V_77 , V_75 ) ;
if ( ! V_77 )
V_77 = 1 ;
else if ( V_77 > 600 && V_26 -> V_12 > V_78 )
V_77 = 600 ;
F_6 ( & V_26 -> V_14 , & V_26 -> V_15 , V_76 ,
V_79 / V_75 , V_77 * V_75 ) ;
V_26 -> V_80 = F_50 ( V_26 ) ;
}
int F_61 ( struct V_25 * V_26 , T_3 V_75 , T_3 V_76 )
{
F_60 ( V_26 , V_75 , V_76 ) ;
F_42 ( & V_62 ) ;
F_59 ( V_26 ) ;
F_38 ( V_26 ) ;
F_53 () ;
F_45 ( & V_62 ) ;
return 0 ;
}
int F_62 ( struct V_25 * V_26 )
{
V_26 -> V_80 = F_50 ( V_26 ) ;
F_42 ( & V_62 ) ;
F_59 ( V_26 ) ;
F_38 ( V_26 ) ;
F_53 () ;
F_45 ( & V_62 ) ;
return 0 ;
}
static void F_44 ( struct V_25 * V_26 , int V_60 )
{
F_63 ( & V_26 -> V_69 ) ;
V_26 -> V_60 = V_60 ;
F_59 ( V_26 ) ;
F_53 () ;
}
void F_64 ( struct V_25 * V_26 , int V_60 )
{
F_42 ( & V_62 ) ;
F_44 ( V_26 , V_60 ) ;
F_45 ( & V_62 ) ;
}
void F_65 ( struct V_25 * V_26 )
{
F_42 ( & V_62 ) ;
F_39 ( V_26 ) ;
F_63 ( & V_26 -> V_69 ) ;
F_53 () ;
F_45 ( & V_62 ) ;
}
static T_6
F_66 ( struct V_81 * V_82 ,
struct V_83 * V_84 , char * V_85 )
{
T_6 V_86 = 0 ;
F_42 ( & V_62 ) ;
V_86 = snprintf ( V_85 , V_87 , L_7 , V_71 -> V_35 ) ;
F_45 ( & V_62 ) ;
return V_86 ;
}
static T_6 F_67 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
const char * V_85 , T_7 V_86 )
{
T_7 V_88 = V_86 ;
if ( V_86 >= sizeof( V_70 ) )
return - V_89 ;
if ( V_85 [ V_86 - 1 ] == '\n' )
V_86 -- ;
F_42 ( & V_62 ) ;
if ( V_86 > 0 )
memcpy ( V_70 , V_85 , V_86 ) ;
V_70 [ V_86 ] = 0 ;
F_53 () ;
F_45 ( & V_62 ) ;
return V_88 ;
}
static T_6
F_68 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
struct V_25 * V_90 ;
T_6 V_86 = 0 ;
F_42 ( & V_62 ) ;
F_21 (src, &clocksource_list, list) {
if ( ! F_55 () ||
( V_90 -> V_27 & V_28 ) )
V_86 += snprintf ( V_85 + V_86 ,
F_69 ( ( T_6 ) V_87 - V_86 , ( T_6 ) 0 ) ,
L_8 , V_90 -> V_35 ) ;
}
F_45 ( & V_62 ) ;
V_86 += snprintf ( V_85 + V_86 ,
F_69 ( ( T_6 ) V_87 - V_86 , ( T_6 ) 0 ) , L_9 ) ;
return V_86 ;
}
static int T_5 F_70 ( void )
{
int error = F_71 ( & V_91 ) ;
if ( ! error )
error = F_72 ( & V_92 ) ;
if ( ! error )
error = F_73 (
& V_92 ,
& V_93 ) ;
if ( ! error )
error = F_73 (
& V_92 ,
& V_94 ) ;
return error ;
}
static int T_5 F_74 ( char * V_95 )
{
F_42 ( & V_62 ) ;
if ( V_95 )
F_75 ( V_70 , V_95 , sizeof( V_70 ) ) ;
F_45 ( & V_62 ) ;
return 1 ;
}
static int T_5 F_76 ( char * V_95 )
{
if ( ! strcmp ( V_95 , L_10 ) ) {
F_13 ( L_11
L_12 ) ;
return F_74 ( L_13 ) ;
}
F_13 ( L_14
L_15 ) ;
return F_74 ( V_95 ) ;
}
