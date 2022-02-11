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
static void F_14 ( T_1 V_4 )
{
int V_2 = F_15 () ;
#ifdef F_16
if ( F_7 ( V_14 == V_15 ) )
V_14 = V_2 ;
#endif
if ( V_14 == V_2 )
F_3 ( V_4 ) ;
}
static void F_17 ( struct V_1 * V_16 , struct V_17 * V_18 )
{
#ifdef F_16
if ( V_16 -> V_19 ) {
F_18 () ;
if ( F_19 ( V_20 ) )
V_16 -> V_21 ++ ;
}
#endif
F_20 ( F_21 ( V_18 ) ) ;
F_22 ( V_22 ) ;
}
static int T_3 F_23 ( char * V_23 )
{
if ( ! strcmp ( V_23 , L_1 ) )
V_24 = 0 ;
else if ( ! strcmp ( V_23 , L_2 ) )
V_24 = 1 ;
else
return 0 ;
return 1 ;
}
static void F_24 ( T_1 V_4 )
{
int V_2 = F_15 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
unsigned long V_25 ;
V_16 -> V_26 = V_4 ;
F_25 ( V_25 ) ;
F_3 ( V_4 ) ;
F_26 ( V_25 ) ;
F_18 () ;
}
static void
F_27 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_27 )
{
T_1 V_6 ;
if ( V_16 -> V_28 ) {
V_6 = F_4 ( V_4 , V_16 -> V_29 ) ;
if ( F_28 ( V_2 ) > 0 )
V_16 -> V_30 = F_6 ( V_16 -> V_30 , V_6 ) ;
else
V_16 -> V_31 = F_6 ( V_16 -> V_31 , V_6 ) ;
V_16 -> V_29 = V_4 ;
}
if ( V_27 )
* V_27 = F_29 ( V_4 ) ;
}
static void F_30 ( int V_2 , T_1 V_4 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
F_27 ( V_2 , V_16 , V_4 , NULL ) ;
V_16 -> V_28 = 0 ;
F_31 ( 0 ) ;
}
static T_1 F_32 ( int V_2 , struct V_1 * V_16 )
{
T_1 V_4 = F_33 () ;
V_16 -> V_29 = V_4 ;
V_16 -> V_28 = 1 ;
F_34 () ;
return V_4 ;
}
T_4 F_35 ( int V_2 , T_4 * V_27 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_32 ;
if ( ! V_24 )
return - 1 ;
V_4 = F_33 () ;
if ( V_27 ) {
F_27 ( V_2 , V_16 , V_4 , V_27 ) ;
V_32 = V_16 -> V_31 ;
} else {
if ( V_16 -> V_28 && ! F_28 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_29 ) ;
V_32 = F_6 ( V_16 -> V_31 , V_6 ) ;
} else {
V_32 = V_16 -> V_31 ;
}
}
return F_29 ( V_32 ) ;
}
T_4 F_36 ( int V_2 , T_4 * V_27 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_33 ;
if ( ! V_24 )
return - 1 ;
V_4 = F_33 () ;
if ( V_27 ) {
F_27 ( V_2 , V_16 , V_4 , V_27 ) ;
V_33 = V_16 -> V_30 ;
} else {
if ( V_16 -> V_28 && F_28 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_29 ) ;
V_33 = F_6 ( V_16 -> V_30 , V_6 ) ;
} else {
V_33 = V_16 -> V_30 ;
}
}
return F_29 ( V_33 ) ;
}
static T_1 F_37 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
unsigned long V_34 , V_35 , V_36 , V_37 ;
T_1 V_38 , V_39 , V_40 = { . V_8 = 0 } ;
unsigned long V_41 ;
struct V_42 * V_43 = F_38 ( V_44 ) . V_45 ;
T_4 V_46 ;
do {
V_34 = F_39 ( & V_10 ) ;
V_38 = V_7 ;
V_35 = V_47 ;
V_46 = F_40 () ;
} while ( F_41 ( & V_10 , V_34 ) );
if ( F_42 ( V_2 , & V_41 ) ||
F_43 ( V_2 ) || F_44 () ) {
V_36 = V_35 + 1 ;
V_37 = 1 ;
} else {
V_36 = F_45 ( V_35 ) ;
V_37 = V_36 - V_35 ;
if ( V_41 < V_37 ) {
V_36 = V_35 + V_41 ;
V_37 = V_41 ;
}
}
if ( ! V_16 -> V_19 && V_37 == 1 )
goto V_48;
if ( ( long ) V_37 >= 1 ) {
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_49 = 1 ;
} else if ( V_14 != V_15 ) {
V_46 = V_50 ;
V_16 -> V_49 = 0 ;
} else if ( ! V_16 -> V_49 ) {
V_46 = V_50 ;
}
if ( F_46 ( V_37 < V_51 ) ) {
V_46 = F_47 ( T_4 , V_46 ,
V_9 . V_8 * V_37 ) ;
}
if ( V_46 < V_50 )
V_39 = F_10 ( V_38 , V_46 ) ;
else
V_39 . V_8 = V_50 ;
if ( V_16 -> V_19 && F_48 ( V_39 , V_43 -> V_52 ) )
goto V_48;
V_40 = V_39 ;
if ( ! V_16 -> V_19 ) {
F_49 ( V_2 ) ;
F_50 () ;
V_16 -> V_53 = F_51 ( & V_16 -> V_54 ) ;
V_16 -> V_19 = 1 ;
}
if ( F_7 ( V_39 . V_8 == V_50 ) ) {
if ( V_16 -> V_55 == V_56 )
F_52 ( & V_16 -> V_54 ) ;
goto V_48;
}
if ( V_16 -> V_55 == V_56 ) {
F_53 ( & V_16 -> V_54 , V_39 ,
V_57 ) ;
if ( F_54 ( & V_16 -> V_54 ) )
goto V_48;
} else if ( ! F_55 ( V_39 , 0 ) )
goto V_48;
F_3 ( F_33 () ) ;
}
F_56 ( V_58 ) ;
V_48:
V_16 -> V_36 = V_36 ;
V_16 -> V_35 = V_35 ;
V_16 -> V_59 = F_4 ( V_43 -> V_52 , V_4 ) ;
return V_40 ;
}
static bool F_57 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_58 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
}
if ( F_7 ( V_16 -> V_55 == V_60 ) )
return false ;
if ( F_59 () )
return false ;
if ( F_7 ( F_60 () && F_58 ( V_2 ) ) ) {
static int V_61 ;
if ( V_61 < 10 &&
( F_60 () & V_62 ) ) {
F_61 ( V_63 L_3 ,
( unsigned int ) F_60 () ) ;
V_61 ++ ;
}
return false ;
}
return true ;
}
static void F_62 ( struct V_1 * V_16 )
{
T_1 V_4 , V_39 ;
int V_2 = F_15 () ;
V_4 = F_32 ( V_2 , V_16 ) ;
if ( F_57 ( V_2 , V_16 ) ) {
int V_64 = V_16 -> V_19 ;
V_16 -> V_65 ++ ;
V_39 = F_37 ( V_16 , V_4 , V_2 ) ;
if ( V_39 . V_8 > 0LL ) {
V_16 -> V_66 ++ ;
V_16 -> V_67 = V_39 ;
}
if ( ! V_64 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_35 ;
}
}
void F_63 ( void )
{
struct V_1 * V_16 ;
F_64 ( F_65 () ) ;
F_66 () ;
F_67 () ;
V_16 = & F_38 ( V_3 ) ;
V_16 -> V_68 = 1 ;
F_62 ( V_16 ) ;
F_68 () ;
}
void F_69 ( void )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
if ( ! V_16 -> V_68 )
return;
F_70 () ;
F_62 ( V_16 ) ;
}
T_1 F_71 ( void )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
return V_16 -> V_59 ;
}
static void F_72 ( struct V_1 * V_16 , T_1 V_4 )
{
F_52 ( & V_16 -> V_54 ) ;
F_73 ( & V_16 -> V_54 , V_16 -> V_53 ) ;
while ( 1 ) {
F_74 ( & V_16 -> V_54 , V_4 , V_9 ) ;
if ( V_16 -> V_55 == V_56 ) {
F_75 ( & V_16 -> V_54 ,
V_57 ) ;
if ( F_54 ( & V_16 -> V_54 ) )
break;
} else {
if ( ! F_55 (
F_51 ( & V_16 -> V_54 ) , 0 ) )
break;
}
V_4 = F_33 () ;
F_3 ( V_4 ) ;
}
}
static void F_76 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_77 () ;
F_78 () ;
F_18 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_69 = V_4 ;
F_72 ( V_16 , V_4 ) ;
}
static void F_79 ( struct V_1 * V_16 )
{
#ifndef F_80
unsigned long V_5 ;
if ( F_81 () )
return;
V_5 = V_47 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_70 )
F_82 ( V_5 ) ;
#endif
}
void F_83 ( void )
{
int V_2 = F_15 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
F_67 () ;
F_64 ( ! V_16 -> V_68 ) ;
V_16 -> V_68 = 0 ;
F_70 () ;
if ( V_16 -> V_28 || V_16 -> V_19 )
V_4 = F_33 () ;
if ( V_16 -> V_28 )
F_30 ( V_2 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_76 ( V_16 , V_4 ) ;
F_79 ( V_16 ) ;
}
F_68 () ;
}
static int F_84 ( struct V_1 * V_16 , T_1 V_4 )
{
F_74 ( & V_16 -> V_54 , V_4 , V_9 ) ;
return F_55 ( F_51 ( & V_16 -> V_54 ) , 0 ) ;
}
static void F_85 ( struct V_42 * V_43 )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
struct V_17 * V_18 = F_86 () ;
T_1 V_4 = F_33 () ;
V_43 -> V_52 . V_8 = V_50 ;
F_14 ( V_4 ) ;
F_17 ( V_16 , V_18 ) ;
while ( F_84 ( V_16 , V_4 ) ) {
V_4 = F_33 () ;
F_3 ( V_4 ) ;
}
}
static void F_87 ( void )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
T_1 V_71 ;
if ( ! V_24 )
return;
F_67 () ;
if ( F_88 ( F_85 ) ) {
F_68 () ;
return;
}
V_16 -> V_55 = V_72 ;
F_89 ( & V_16 -> V_54 , V_73 , V_74 ) ;
V_71 = F_13 () ;
for (; ; ) {
F_73 ( & V_16 -> V_54 , V_71 ) ;
if ( ! F_55 ( V_71 , 0 ) )
break;
V_71 = F_6 ( V_71 , V_9 ) ;
}
F_68 () ;
}
static void F_90 ( int V_2 , T_1 V_4 )
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
static inline void F_91 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_28 && ! V_16 -> V_19 )
return;
V_4 = F_33 () ;
if ( V_16 -> V_28 )
F_30 ( V_2 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_24 ( V_4 ) ;
F_90 ( V_2 , V_4 ) ;
}
}
static inline void F_87 ( void ) { }
static inline void F_91 ( int V_2 ) { }
void F_92 ( int V_2 )
{
F_93 ( V_2 ) ;
F_91 ( V_2 ) ;
}
static enum V_75 F_94 ( struct V_76 * V_77 )
{
struct V_1 * V_16 =
F_95 ( V_77 , struct V_1 , V_54 ) ;
struct V_17 * V_18 = F_86 () ;
T_1 V_4 = F_33 () ;
F_14 ( V_4 ) ;
if ( V_18 )
F_17 ( V_16 , V_18 ) ;
F_74 ( V_77 , V_4 , V_9 ) ;
return V_78 ;
}
static int T_3 F_96 ( char * V_23 )
{
F_97 ( & V_23 , & V_79 ) ;
return 0 ;
}
void F_98 ( void )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
T_1 V_4 = F_33 () ;
F_89 ( & V_16 -> V_54 , V_73 , V_74 ) ;
V_16 -> V_54 . V_80 = F_94 ;
F_73 ( & V_16 -> V_54 , F_13 () ) ;
if ( V_79 ) {
T_4 V_81 = F_8 ( V_9 ) >> 1 ;
F_99 ( V_81 , F_100 () ) ;
V_81 *= F_15 () ;
F_101 ( & V_16 -> V_54 , V_81 ) ;
}
for (; ; ) {
F_74 ( & V_16 -> V_54 , V_4 , V_9 ) ;
F_75 ( & V_16 -> V_54 ,
V_57 ) ;
if ( F_54 ( & V_16 -> V_54 ) )
break;
V_4 = F_33 () ;
}
#ifdef F_16
if ( V_24 )
V_16 -> V_55 = V_56 ;
#endif
}
void F_102 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_103
if ( V_16 -> V_54 . V_82 )
F_52 ( & V_16 -> V_54 ) ;
# endif
V_16 -> V_55 = V_60 ;
}
void F_104 ( void )
{
int V_2 ;
F_105 (cpu)
F_106 ( 0 , & F_2 ( V_3 , V_2 ) . V_83 ) ;
}
void F_107 ( void )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
F_106 ( 0 , & V_16 -> V_83 ) ;
}
int F_108 ( int V_84 )
{
struct V_1 * V_16 = & F_38 ( V_3 ) ;
if ( ! F_109 ( 0 , & V_16 -> V_83 ) )
return 0 ;
if ( V_16 -> V_55 != V_60 )
return 0 ;
if ( ! F_110 () || ! F_111 () )
return 0 ;
if ( ! V_84 )
return 1 ;
F_87 () ;
return 0 ;
}
