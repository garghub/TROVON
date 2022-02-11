struct V_1 * F_1 ( int V_2 )
{
return & F_2 ( V_3 , V_2 ) ;
}
static void F_3 ( T_1 V_4 )
{
unsigned long V_5 = 0 ;
T_1 V_6 ;
V_6 = F_4 ( V_4 , V_7 ) ;
if ( V_6 . V_8 < V_9 . V_8 )
return;
F_5 ( & V_10 ) ;
V_6 = F_4 ( V_4 , V_7 ) ;
if ( V_6 . V_8 >= V_9 . V_8 ) {
V_6 = F_4 ( V_6 , V_9 ) ;
V_7 = F_6 ( V_7 ,
V_9 ) ;
if ( F_7 ( V_6 . V_8 >= V_9 . V_8 ) ) {
T_2 V_11 = F_8 ( V_9 ) ;
V_5 = F_9 ( V_6 , V_11 ) ;
V_7 = F_10 ( V_7 ,
V_11 * V_5 ) ;
}
F_11 ( ++ V_5 ) ;
V_12 = F_6 ( V_7 , V_9 ) ;
}
F_12 ( & V_10 ) ;
}
static T_1 F_13 ( void )
{
T_1 V_13 ;
F_5 ( & V_10 ) ;
if ( V_7 . V_8 == 0 )
V_7 = V_12 ;
V_13 = V_7 ;
F_12 ( & V_10 ) ;
return V_13 ;
}
static int T_3 F_14 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_1 ) )
V_15 = 0 ;
else if ( ! strcmp ( V_14 , L_2 ) )
V_15 = 1 ;
else
return 0 ;
return 1 ;
}
static void F_15 ( T_1 V_4 )
{
int V_2 = F_16 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
unsigned long V_17 ;
V_16 -> V_18 = V_4 ;
F_17 ( V_17 ) ;
F_3 ( V_4 ) ;
F_18 ( V_17 ) ;
F_19 () ;
}
static void
F_20 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_19 )
{
T_1 V_6 ;
if ( V_16 -> V_20 ) {
V_6 = F_4 ( V_4 , V_16 -> V_21 ) ;
if ( F_21 ( V_2 ) > 0 )
V_16 -> V_22 = F_6 ( V_16 -> V_22 , V_6 ) ;
else
V_16 -> V_23 = F_6 ( V_16 -> V_23 , V_6 ) ;
V_16 -> V_21 = V_4 ;
}
if ( V_19 )
* V_19 = F_22 ( V_4 ) ;
}
static void F_23 ( int V_2 , T_1 V_4 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
F_20 ( V_2 , V_16 , V_4 , NULL ) ;
V_16 -> V_20 = 0 ;
F_24 ( 0 ) ;
}
static T_1 F_25 ( int V_2 , struct V_1 * V_16 )
{
T_1 V_4 = F_26 () ;
V_16 -> V_21 = V_4 ;
V_16 -> V_20 = 1 ;
F_27 () ;
return V_4 ;
}
T_4 F_28 ( int V_2 , T_4 * V_19 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_24 ;
if ( ! V_15 )
return - 1 ;
V_4 = F_26 () ;
if ( V_19 ) {
F_20 ( V_2 , V_16 , V_4 , V_19 ) ;
V_24 = V_16 -> V_23 ;
} else {
if ( V_16 -> V_20 && ! F_21 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_21 ) ;
V_24 = F_6 ( V_16 -> V_23 , V_6 ) ;
} else {
V_24 = V_16 -> V_23 ;
}
}
return F_22 ( V_24 ) ;
}
T_4 F_29 ( int V_2 , T_4 * V_19 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_25 ;
if ( ! V_15 )
return - 1 ;
V_4 = F_26 () ;
if ( V_19 ) {
F_20 ( V_2 , V_16 , V_4 , V_19 ) ;
V_25 = V_16 -> V_22 ;
} else {
if ( V_16 -> V_20 && F_21 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_21 ) ;
V_25 = F_6 ( V_16 -> V_22 , V_6 ) ;
} else {
V_25 = V_16 -> V_22 ;
}
}
return F_22 ( V_25 ) ;
}
static T_1 F_30 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
unsigned long V_26 , V_27 , V_28 , V_29 ;
T_1 V_30 , V_31 , V_32 = { . V_8 = 0 } ;
unsigned long V_33 ;
struct V_34 * V_35 = F_31 ( V_36 ) . V_37 ;
T_4 V_38 ;
do {
V_26 = F_32 ( & V_10 ) ;
V_30 = V_7 ;
V_27 = V_39 ;
V_38 = F_33 () ;
} while ( F_34 ( & V_10 , V_26 ) );
if ( F_35 ( V_2 , & V_33 ) || F_36 ( V_2 ) ||
F_37 ( V_2 ) ) {
V_28 = V_27 + 1 ;
V_29 = 1 ;
} else {
V_28 = F_38 ( V_27 ) ;
V_29 = V_28 - V_27 ;
if ( V_33 < V_29 ) {
V_28 = V_27 + V_33 ;
V_29 = V_33 ;
}
}
if ( ! V_16 -> V_40 && V_29 == 1 )
goto V_41;
if ( ( long ) V_29 >= 1 ) {
if ( V_2 == V_42 ) {
V_42 = V_43 ;
V_16 -> V_44 = 1 ;
} else if ( V_42 != V_43 ) {
V_38 = V_45 ;
V_16 -> V_44 = 0 ;
} else if ( ! V_16 -> V_44 ) {
V_38 = V_45 ;
}
if ( F_39 ( V_29 < V_46 ) ) {
V_38 = F_40 ( T_4 , V_38 ,
V_9 . V_8 * V_29 ) ;
}
if ( V_38 < V_45 )
V_31 = F_10 ( V_30 , V_38 ) ;
else
V_31 . V_8 = V_45 ;
if ( V_16 -> V_40 && F_41 ( V_31 , V_35 -> V_47 ) )
goto V_41;
V_32 = V_31 ;
if ( ! V_16 -> V_40 ) {
F_42 ( 1 ) ;
F_43 () ;
V_16 -> V_48 = F_44 ( & V_16 -> V_49 ) ;
V_16 -> V_40 = 1 ;
}
if ( F_7 ( V_31 . V_8 == V_45 ) ) {
if ( V_16 -> V_50 == V_51 )
F_45 ( & V_16 -> V_49 ) ;
goto V_41;
}
if ( V_16 -> V_50 == V_51 ) {
F_46 ( & V_16 -> V_49 , V_31 ,
V_52 ) ;
if ( F_47 ( & V_16 -> V_49 ) )
goto V_41;
} else if ( ! F_48 ( V_31 , 0 ) )
goto V_41;
F_3 ( F_26 () ) ;
}
F_49 ( V_53 ) ;
V_41:
V_16 -> V_28 = V_28 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_54 = F_4 ( V_35 -> V_47 , V_4 ) ;
return V_32 ;
}
static bool F_50 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_51 ( V_2 ) ) ) {
if ( V_2 == V_42 )
V_42 = V_43 ;
}
if ( F_7 ( V_16 -> V_50 == V_55 ) )
return false ;
if ( F_52 () )
return false ;
if ( F_7 ( F_53 () && F_51 ( V_2 ) ) ) {
static int V_56 ;
if ( V_56 < 10 ) {
F_54 ( V_57 L_3 ,
( unsigned int ) F_53 () ) ;
V_56 ++ ;
}
return false ;
}
return true ;
}
static void F_55 ( struct V_1 * V_16 )
{
T_1 V_4 , V_31 ;
int V_2 = F_16 () ;
V_4 = F_25 ( V_2 , V_16 ) ;
if ( F_50 ( V_2 , V_16 ) ) {
int V_58 = V_16 -> V_40 ;
V_16 -> V_59 ++ ;
V_31 = F_30 ( V_16 , V_4 , V_2 ) ;
if ( V_31 . V_8 > 0LL ) {
V_16 -> V_60 ++ ;
V_16 -> V_61 = V_31 ;
}
if ( ! V_58 && V_16 -> V_40 )
V_16 -> V_62 = V_16 -> V_27 ;
}
}
void F_56 ( void )
{
struct V_1 * V_16 ;
F_57 ( F_58 () ) ;
F_59 () ;
F_60 () ;
V_16 = & F_31 ( V_3 ) ;
V_16 -> V_63 = 1 ;
F_55 ( V_16 ) ;
F_61 () ;
}
void F_62 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
if ( ! V_16 -> V_63 )
return;
F_55 ( V_16 ) ;
}
T_1 F_63 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
return V_16 -> V_54 ;
}
static void F_64 ( struct V_1 * V_16 , T_1 V_4 )
{
F_45 ( & V_16 -> V_49 ) ;
F_65 ( & V_16 -> V_49 , V_16 -> V_48 ) ;
while ( 1 ) {
F_66 ( & V_16 -> V_49 , V_4 , V_9 ) ;
if ( V_16 -> V_50 == V_51 ) {
F_67 ( & V_16 -> V_49 ,
V_52 ) ;
if ( F_47 ( & V_16 -> V_49 ) )
break;
} else {
if ( ! F_48 (
F_44 ( & V_16 -> V_49 ) , 0 ) )
break;
}
V_4 = F_26 () ;
F_3 ( V_4 ) ;
}
}
static void F_68 ( struct V_1 * V_16 , T_1 V_4 )
{
F_42 ( 0 ) ;
F_3 ( V_4 ) ;
F_69 () ;
F_70 () ;
F_19 () ;
V_16 -> V_40 = 0 ;
V_16 -> V_64 = V_4 ;
F_64 ( V_16 , V_4 ) ;
}
static void F_71 ( struct V_1 * V_16 )
{
#ifndef F_72
unsigned long V_5 ;
V_5 = V_39 - V_16 -> V_62 ;
if ( V_5 && V_5 < V_65 )
F_73 ( V_5 ) ;
#endif
}
void F_74 ( void )
{
int V_2 = F_16 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
F_60 () ;
F_57 ( ! V_16 -> V_63 ) ;
V_16 -> V_63 = 0 ;
if ( V_16 -> V_20 || V_16 -> V_40 )
V_4 = F_26 () ;
if ( V_16 -> V_20 )
F_23 ( V_2 , V_4 ) ;
if ( V_16 -> V_40 ) {
F_68 ( V_16 , V_4 ) ;
F_71 ( V_16 ) ;
}
F_61 () ;
}
static int F_75 ( struct V_1 * V_16 , T_1 V_4 )
{
F_66 ( & V_16 -> V_49 , V_4 , V_9 ) ;
return F_48 ( F_44 ( & V_16 -> V_49 ) , 0 ) ;
}
static void F_76 ( struct V_34 * V_35 )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
struct V_66 * V_67 = F_77 () ;
int V_2 = F_16 () ;
T_1 V_4 = F_26 () ;
V_35 -> V_47 . V_8 = V_45 ;
if ( F_7 ( V_42 == V_43 ) )
V_42 = V_2 ;
if ( V_42 == V_2 )
F_3 ( V_4 ) ;
if ( V_16 -> V_40 ) {
F_19 () ;
V_16 -> V_62 ++ ;
}
F_78 ( F_79 ( V_67 ) ) ;
F_80 ( V_68 ) ;
while ( F_75 ( V_16 , V_4 ) ) {
V_4 = F_26 () ;
F_3 ( V_4 ) ;
}
}
static void F_81 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
T_1 V_69 ;
if ( ! V_15 )
return;
F_60 () ;
if ( F_82 ( F_76 ) ) {
F_61 () ;
return;
}
V_16 -> V_50 = V_70 ;
F_83 ( & V_16 -> V_49 , V_71 , V_72 ) ;
V_69 = F_13 () ;
for (; ; ) {
F_65 ( & V_16 -> V_49 , V_69 ) ;
if ( ! F_48 ( V_69 , 0 ) )
break;
V_69 = F_6 ( V_69 , V_9 ) ;
}
F_61 () ;
}
static void F_84 ( int V_2 , T_1 V_4 )
{
#if 0
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
ktime_t delta;
delta = ktime_sub(hrtimer_get_expires(&ts->sched_timer), now);
if (delta.tv64 <= tick_period.tv64)
return;
tick_nohz_restart(ts, now);
#endif
}
static inline void F_85 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_20 && ! V_16 -> V_40 )
return;
V_4 = F_26 () ;
if ( V_16 -> V_20 )
F_23 ( V_2 , V_4 ) ;
if ( V_16 -> V_40 ) {
F_15 ( V_4 ) ;
F_84 ( V_2 , V_4 ) ;
}
}
static inline void F_81 ( void ) { }
static inline void F_85 ( int V_2 ) { }
void F_86 ( int V_2 )
{
F_87 ( V_2 ) ;
F_85 ( V_2 ) ;
}
static enum V_73 F_88 ( struct V_74 * V_75 )
{
struct V_1 * V_16 =
F_89 ( V_75 , struct V_1 , V_49 ) ;
struct V_66 * V_67 = F_77 () ;
T_1 V_4 = F_26 () ;
int V_2 = F_16 () ;
#ifdef F_90
if ( F_7 ( V_42 == V_43 ) )
V_42 = V_2 ;
#endif
if ( V_42 == V_2 )
F_3 ( V_4 ) ;
if ( V_67 ) {
if ( V_16 -> V_40 ) {
F_19 () ;
if ( F_91 ( V_2 ) )
V_16 -> V_62 ++ ;
}
F_78 ( F_79 ( V_67 ) ) ;
F_80 ( V_68 ) ;
}
F_66 ( V_75 , V_4 , V_9 ) ;
return V_76 ;
}
static int T_3 F_92 ( char * V_14 )
{
F_93 ( & V_14 , & V_77 ) ;
return 0 ;
}
void F_94 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
T_1 V_4 = F_26 () ;
F_83 ( & V_16 -> V_49 , V_71 , V_72 ) ;
V_16 -> V_49 . V_78 = F_88 ;
F_65 ( & V_16 -> V_49 , F_13 () ) ;
if ( V_77 ) {
T_4 V_79 = F_8 ( V_9 ) >> 1 ;
F_95 ( V_79 , F_96 () ) ;
V_79 *= F_16 () ;
F_97 ( & V_16 -> V_49 , V_79 ) ;
}
for (; ; ) {
F_66 ( & V_16 -> V_49 , V_4 , V_9 ) ;
F_67 ( & V_16 -> V_49 ,
V_52 ) ;
if ( F_47 ( & V_16 -> V_49 ) )
break;
V_4 = F_26 () ;
}
#ifdef F_90
if ( V_15 )
V_16 -> V_50 = V_51 ;
#endif
}
void F_98 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_99
if ( V_16 -> V_49 . V_80 )
F_45 ( & V_16 -> V_49 ) ;
# endif
V_16 -> V_50 = V_55 ;
}
void F_100 ( void )
{
int V_2 ;
F_101 (cpu)
F_102 ( 0 , & F_2 ( V_3 , V_2 ) . V_81 ) ;
}
void F_103 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
F_102 ( 0 , & V_16 -> V_81 ) ;
}
int F_104 ( int V_82 )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
if ( ! F_105 ( 0 , & V_16 -> V_81 ) )
return 0 ;
if ( V_16 -> V_50 != V_55 )
return 0 ;
if ( ! F_106 () || ! F_107 () )
return 0 ;
if ( ! V_82 )
return 1 ;
F_81 () ;
return 0 ;
}
