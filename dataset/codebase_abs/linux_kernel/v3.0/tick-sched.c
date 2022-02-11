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
F_17 ( V_2 , V_18 ) ;
V_16 -> V_19 = V_4 ;
F_18 ( V_17 ) ;
F_3 ( V_4 ) ;
F_19 ( V_17 ) ;
F_20 () ;
}
static void
F_21 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_20 )
{
T_1 V_6 ;
if ( V_16 -> V_21 ) {
V_6 = F_4 ( V_4 , V_16 -> V_22 ) ;
V_16 -> V_23 = F_6 ( V_16 -> V_23 , V_6 ) ;
if ( F_22 ( V_2 ) > 0 )
V_16 -> V_24 = F_6 ( V_16 -> V_24 , V_6 ) ;
V_16 -> V_22 = V_4 ;
}
if ( V_20 )
* V_20 = F_23 ( V_4 ) ;
}
static void F_24 ( int V_2 , T_1 V_4 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
F_21 ( V_2 , V_16 , V_4 , NULL ) ;
V_16 -> V_21 = 0 ;
F_25 ( 0 ) ;
}
static T_1 F_26 ( int V_2 , struct V_1 * V_16 )
{
T_1 V_4 ;
V_4 = F_27 () ;
F_21 ( V_2 , V_16 , V_4 , NULL ) ;
V_16 -> V_22 = V_4 ;
V_16 -> V_21 = 1 ;
F_28 () ;
return V_4 ;
}
T_4 F_29 ( int V_2 , T_4 * V_20 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
if ( ! V_15 )
return - 1 ;
F_21 ( V_2 , V_16 , F_27 () , V_20 ) ;
return F_23 ( V_16 -> V_23 ) ;
}
T_4 F_30 ( int V_2 , T_4 * V_20 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
if ( ! V_15 )
return - 1 ;
F_21 ( V_2 , V_16 , F_27 () , V_20 ) ;
return F_23 ( V_16 -> V_24 ) ;
}
void F_31 ( int V_25 )
{
unsigned long V_26 , V_27 , V_28 , V_29 , V_17 ;
struct V_1 * V_16 ;
T_1 V_30 , V_31 , V_4 ;
struct V_32 * V_33 = F_32 ( V_34 ) . V_35 ;
T_4 V_36 ;
int V_2 ;
F_18 ( V_17 ) ;
V_2 = F_16 () ;
V_16 = & F_2 ( V_3 , V_2 ) ;
if ( ! V_25 && ! V_16 -> V_25 )
goto V_37;
V_16 -> V_25 = 1 ;
V_4 = F_26 ( V_2 , V_16 ) ;
if ( F_7 ( ! F_33 ( V_2 ) ) ) {
if ( V_2 == V_38 )
V_38 = V_39 ;
}
if ( F_7 ( V_16 -> V_40 == V_41 ) )
goto V_37;
if ( F_34 () )
goto V_37;
if ( F_7 ( F_35 () && F_33 ( V_2 ) ) ) {
static int V_42 ;
if ( V_42 < 10 ) {
F_36 ( V_43 L_3 ,
( unsigned int ) F_35 () ) ;
V_42 ++ ;
}
goto V_37;
}
V_16 -> V_44 ++ ;
do {
V_26 = F_37 ( & V_10 ) ;
V_30 = V_7 ;
V_27 = V_45 ;
V_36 = F_38 () ;
} while ( F_39 ( & V_10 , V_26 ) );
if ( F_40 ( V_2 ) || F_41 ( V_2 ) ||
F_42 ( V_2 ) ) {
V_28 = V_27 + 1 ;
V_29 = 1 ;
} else {
V_28 = F_43 ( V_27 ) ;
V_29 = V_28 - V_27 ;
}
if ( ! V_16 -> V_46 && V_29 == 1 )
goto V_47;
if ( ( long ) V_29 >= 1 ) {
if ( V_2 == V_38 ) {
V_38 = V_39 ;
V_16 -> V_48 = 1 ;
} else if ( V_38 != V_39 ) {
V_36 = V_49 ;
V_16 -> V_48 = 0 ;
} else if ( ! V_16 -> V_48 ) {
V_36 = V_49 ;
}
if ( F_44 ( V_29 < V_50 ) ) {
V_36 = F_45 ( T_4 , V_36 ,
V_9 . V_8 * V_29 ) ;
}
if ( V_36 < V_49 )
V_31 = F_10 ( V_30 , V_36 ) ;
else
V_31 . V_8 = V_49 ;
if ( V_29 > 1 )
F_46 ( V_2 , V_18 ) ;
if ( V_16 -> V_46 && F_47 ( V_31 , V_33 -> V_51 ) )
goto V_47;
if ( ! V_16 -> V_46 ) {
F_48 ( 1 ) ;
V_16 -> V_52 = F_49 ( & V_16 -> V_53 ) ;
V_16 -> V_46 = 1 ;
V_16 -> V_54 = V_27 ;
F_50 () ;
}
V_16 -> V_55 ++ ;
V_16 -> V_56 = V_31 ;
if ( F_7 ( V_31 . V_8 == V_49 ) ) {
if ( V_16 -> V_40 == V_57 )
F_51 ( & V_16 -> V_53 ) ;
goto V_47;
}
if ( V_16 -> V_40 == V_57 ) {
F_52 ( & V_16 -> V_53 , V_31 ,
V_58 ) ;
if ( F_53 ( & V_16 -> V_53 ) )
goto V_47;
} else if ( ! F_54 ( V_31 , 0 ) )
goto V_47;
F_3 ( F_27 () ) ;
F_17 ( V_2 , V_18 ) ;
}
F_55 ( V_59 ) ;
V_47:
V_16 -> V_28 = V_28 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_60 = F_4 ( V_33 -> V_51 , V_4 ) ;
V_37:
F_19 ( V_17 ) ;
}
T_1 F_56 ( void )
{
struct V_1 * V_16 = & F_32 ( V_3 ) ;
return V_16 -> V_60 ;
}
static void F_57 ( struct V_1 * V_16 , T_1 V_4 )
{
F_51 ( & V_16 -> V_53 ) ;
F_58 ( & V_16 -> V_53 , V_16 -> V_52 ) ;
while ( 1 ) {
F_59 ( & V_16 -> V_53 , V_4 , V_9 ) ;
if ( V_16 -> V_40 == V_57 ) {
F_60 ( & V_16 -> V_53 ,
V_58 ) ;
if ( F_53 ( & V_16 -> V_53 ) )
break;
} else {
if ( ! F_54 (
F_49 ( & V_16 -> V_53 ) , 0 ) )
break;
}
F_3 ( V_4 ) ;
V_4 = F_27 () ;
}
}
void F_61 ( void )
{
int V_2 = F_16 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
#ifndef F_62
unsigned long V_5 ;
#endif
T_1 V_4 ;
F_63 () ;
if ( V_16 -> V_21 || ( V_16 -> V_25 && V_16 -> V_46 ) )
V_4 = F_27 () ;
if ( V_16 -> V_21 )
F_24 ( V_2 , V_4 ) ;
if ( ! V_16 -> V_25 || ! V_16 -> V_46 ) {
V_16 -> V_25 = 0 ;
F_64 () ;
return;
}
V_16 -> V_25 = 0 ;
F_65 () ;
F_48 ( 0 ) ;
F_3 ( V_4 ) ;
F_17 ( V_2 , V_18 ) ;
#ifndef F_62
V_5 = V_45 - V_16 -> V_54 ;
if ( V_5 && V_5 < V_61 )
F_66 ( V_5 ) ;
#endif
F_20 () ;
V_16 -> V_46 = 0 ;
V_16 -> V_62 = V_4 ;
F_57 ( V_16 , V_4 ) ;
F_64 () ;
}
static int F_67 ( struct V_1 * V_16 , T_1 V_4 )
{
F_59 ( & V_16 -> V_53 , V_4 , V_9 ) ;
return F_54 ( F_49 ( & V_16 -> V_53 ) , 0 ) ;
}
static void F_68 ( struct V_32 * V_33 )
{
struct V_1 * V_16 = & F_32 ( V_3 ) ;
struct V_63 * V_64 = F_69 () ;
int V_2 = F_16 () ;
T_1 V_4 = F_27 () ;
V_33 -> V_51 . V_8 = V_49 ;
if ( F_7 ( V_38 == V_39 ) )
V_38 = V_2 ;
if ( V_38 == V_2 )
F_3 ( V_4 ) ;
if ( V_16 -> V_46 ) {
F_20 () ;
V_16 -> V_54 ++ ;
}
F_70 ( F_71 ( V_64 ) ) ;
F_72 ( V_65 ) ;
while ( F_67 ( V_16 , V_4 ) ) {
V_4 = F_27 () ;
F_3 ( V_4 ) ;
}
}
static void F_73 ( void )
{
struct V_1 * V_16 = & F_32 ( V_3 ) ;
T_1 V_66 ;
if ( ! V_15 )
return;
F_63 () ;
if ( F_74 ( F_68 ) ) {
F_64 () ;
return;
}
V_16 -> V_40 = V_67 ;
F_75 ( & V_16 -> V_53 , V_68 , V_69 ) ;
V_66 = F_13 () ;
for (; ; ) {
F_58 ( & V_16 -> V_53 , V_66 ) ;
if ( ! F_54 ( V_66 , 0 ) )
break;
V_66 = F_6 ( V_66 , V_9 ) ;
}
F_64 () ;
F_36 ( V_70 L_4 , F_16 () ) ;
}
static void F_76 ( int V_2 , T_1 V_4 )
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
static inline void F_77 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_21 && ! V_16 -> V_46 )
return;
V_4 = F_27 () ;
if ( V_16 -> V_21 )
F_24 ( V_2 , V_4 ) ;
if ( V_16 -> V_46 ) {
F_15 ( V_4 ) ;
F_76 ( V_2 , V_4 ) ;
}
}
static inline void F_73 ( void ) { }
static inline void F_77 ( int V_2 ) { }
void F_78 ( int V_2 )
{
F_79 ( V_2 ) ;
F_77 ( V_2 ) ;
}
static enum V_71 F_80 ( struct V_72 * V_73 )
{
struct V_1 * V_16 =
F_81 ( V_73 , struct V_1 , V_53 ) ;
struct V_63 * V_64 = F_69 () ;
T_1 V_4 = F_27 () ;
int V_2 = F_16 () ;
#ifdef F_82
if ( F_7 ( V_38 == V_39 ) )
V_38 = V_2 ;
#endif
if ( V_38 == V_2 )
F_3 ( V_4 ) ;
if ( V_64 ) {
if ( V_16 -> V_46 ) {
F_20 () ;
V_16 -> V_54 ++ ;
}
F_70 ( F_71 ( V_64 ) ) ;
F_72 ( V_65 ) ;
}
F_59 ( V_73 , V_4 , V_9 ) ;
return V_74 ;
}
void F_83 ( void )
{
struct V_1 * V_16 = & F_32 ( V_3 ) ;
T_1 V_4 = F_27 () ;
F_75 ( & V_16 -> V_53 , V_68 , V_69 ) ;
V_16 -> V_53 . V_75 = F_80 ;
F_58 ( & V_16 -> V_53 , F_13 () ) ;
for (; ; ) {
F_59 ( & V_16 -> V_53 , V_4 , V_9 ) ;
F_60 ( & V_16 -> V_53 ,
V_58 ) ;
if ( F_53 ( & V_16 -> V_53 ) )
break;
V_4 = F_27 () ;
}
#ifdef F_82
if ( V_15 ) {
V_16 -> V_40 = V_57 ;
F_36 ( V_70 L_4 , F_16 () ) ;
}
#endif
}
void F_84 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_85
if ( V_16 -> V_53 . V_76 )
F_51 ( & V_16 -> V_53 ) ;
# endif
V_16 -> V_40 = V_41 ;
}
void F_86 ( void )
{
int V_2 ;
F_87 (cpu)
F_88 ( 0 , & F_2 ( V_3 , V_2 ) . V_77 ) ;
}
void F_89 ( void )
{
struct V_1 * V_16 = & F_32 ( V_3 ) ;
F_88 ( 0 , & V_16 -> V_77 ) ;
}
int F_90 ( int V_78 )
{
struct V_1 * V_16 = & F_32 ( V_3 ) ;
if ( ! F_91 ( 0 , & V_16 -> V_77 ) )
return 0 ;
if ( V_16 -> V_40 != V_41 )
return 0 ;
if ( ! F_92 () || ! F_93 () )
return 0 ;
if ( ! V_78 )
return 1 ;
F_73 () ;
return 0 ;
}
