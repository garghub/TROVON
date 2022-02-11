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
T_1 V_4 ;
V_4 = F_26 () ;
F_20 ( V_2 , V_16 , V_4 , NULL ) ;
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
static void F_30 ( struct V_1 * V_16 )
{
unsigned long V_26 , V_27 , V_28 , V_29 ;
T_1 V_30 , V_31 , V_4 ;
struct V_32 * V_33 = F_31 ( V_34 ) . V_35 ;
T_4 V_36 ;
int V_2 ;
V_2 = F_16 () ;
V_16 = & F_2 ( V_3 , V_2 ) ;
V_4 = F_25 ( V_2 , V_16 ) ;
if ( F_7 ( ! F_32 ( V_2 ) ) ) {
if ( V_2 == V_37 )
V_37 = V_38 ;
}
if ( F_7 ( V_16 -> V_39 == V_40 ) )
return;
if ( F_33 () )
return;
if ( F_7 ( F_34 () && F_32 ( V_2 ) ) ) {
static int V_41 ;
if ( V_41 < 10 ) {
F_35 ( V_42 L_3 ,
( unsigned int ) F_34 () ) ;
V_41 ++ ;
}
return;
}
V_16 -> V_43 ++ ;
do {
V_26 = F_36 ( & V_10 ) ;
V_30 = V_7 ;
V_27 = V_44 ;
V_36 = F_37 () ;
} while ( F_38 ( & V_10 , V_26 ) );
if ( F_39 ( V_2 ) || F_40 ( V_2 ) ||
F_41 ( V_2 ) ) {
V_28 = V_27 + 1 ;
V_29 = 1 ;
} else {
V_28 = F_42 ( V_27 ) ;
V_29 = V_28 - V_27 ;
}
if ( ! V_16 -> V_45 && V_29 == 1 )
goto V_46;
if ( ( long ) V_29 >= 1 ) {
if ( V_2 == V_37 ) {
V_37 = V_38 ;
V_16 -> V_47 = 1 ;
} else if ( V_37 != V_38 ) {
V_36 = V_48 ;
V_16 -> V_47 = 0 ;
} else if ( ! V_16 -> V_47 ) {
V_36 = V_48 ;
}
if ( F_43 ( V_29 < V_49 ) ) {
V_36 = F_44 ( T_4 , V_36 ,
V_9 . V_8 * V_29 ) ;
}
if ( V_36 < V_48 )
V_31 = F_10 ( V_30 , V_36 ) ;
else
V_31 . V_8 = V_48 ;
if ( V_16 -> V_45 && F_45 ( V_31 , V_33 -> V_50 ) )
goto V_46;
if ( ! V_16 -> V_45 ) {
F_46 ( 1 ) ;
V_16 -> V_51 = F_47 ( & V_16 -> V_52 ) ;
V_16 -> V_45 = 1 ;
V_16 -> V_53 = V_27 ;
}
V_16 -> V_54 ++ ;
V_16 -> V_55 = V_31 ;
if ( F_7 ( V_31 . V_8 == V_48 ) ) {
if ( V_16 -> V_39 == V_56 )
F_48 ( & V_16 -> V_52 ) ;
goto V_46;
}
if ( V_16 -> V_39 == V_56 ) {
F_49 ( & V_16 -> V_52 , V_31 ,
V_57 ) ;
if ( F_50 ( & V_16 -> V_52 ) )
goto V_46;
} else if ( ! F_51 ( V_31 , 0 ) )
goto V_46;
F_3 ( F_26 () ) ;
}
F_52 ( V_58 ) ;
V_46:
V_16 -> V_28 = V_28 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_59 = F_4 ( V_33 -> V_50 , V_4 ) ;
}
void F_53 ( void )
{
struct V_1 * V_16 ;
F_54 ( F_55 () ) ;
F_56 () ;
F_57 () ;
V_16 = & F_31 ( V_3 ) ;
V_16 -> V_60 = 1 ;
F_30 ( V_16 ) ;
F_58 () ;
}
void F_59 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
if ( ! V_16 -> V_60 )
return;
F_30 ( V_16 ) ;
}
T_1 F_60 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
return V_16 -> V_59 ;
}
static void F_61 ( struct V_1 * V_16 , T_1 V_4 )
{
F_48 ( & V_16 -> V_52 ) ;
F_62 ( & V_16 -> V_52 , V_16 -> V_51 ) ;
while ( 1 ) {
F_63 ( & V_16 -> V_52 , V_4 , V_9 ) ;
if ( V_16 -> V_39 == V_56 ) {
F_64 ( & V_16 -> V_52 ,
V_57 ) ;
if ( F_50 ( & V_16 -> V_52 ) )
break;
} else {
if ( ! F_51 (
F_47 ( & V_16 -> V_52 ) , 0 ) )
break;
}
F_3 ( V_4 ) ;
V_4 = F_26 () ;
}
}
void F_65 ( void )
{
int V_2 = F_16 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
#ifndef F_66
unsigned long V_5 ;
#endif
T_1 V_4 ;
F_57 () ;
if ( V_16 -> V_20 || ( V_16 -> V_60 && V_16 -> V_45 ) )
V_4 = F_26 () ;
if ( V_16 -> V_20 )
F_23 ( V_2 , V_4 ) ;
if ( ! V_16 -> V_60 || ! V_16 -> V_45 ) {
V_16 -> V_60 = 0 ;
F_58 () ;
return;
}
V_16 -> V_60 = 0 ;
F_46 ( 0 ) ;
F_3 ( V_4 ) ;
#ifndef F_66
V_5 = V_44 - V_16 -> V_53 ;
if ( V_5 && V_5 < V_61 )
F_67 ( V_5 ) ;
#endif
F_19 () ;
V_16 -> V_45 = 0 ;
V_16 -> V_62 = V_4 ;
F_61 ( V_16 , V_4 ) ;
F_58 () ;
}
static int F_68 ( struct V_1 * V_16 , T_1 V_4 )
{
F_63 ( & V_16 -> V_52 , V_4 , V_9 ) ;
return F_51 ( F_47 ( & V_16 -> V_52 ) , 0 ) ;
}
static void F_69 ( struct V_32 * V_33 )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
struct V_63 * V_64 = F_70 () ;
int V_2 = F_16 () ;
T_1 V_4 = F_26 () ;
V_33 -> V_50 . V_8 = V_48 ;
if ( F_7 ( V_37 == V_38 ) )
V_37 = V_2 ;
if ( V_37 == V_2 )
F_3 ( V_4 ) ;
if ( V_16 -> V_45 ) {
F_19 () ;
V_16 -> V_53 ++ ;
}
F_71 ( F_72 ( V_64 ) ) ;
F_73 ( V_65 ) ;
while ( F_68 ( V_16 , V_4 ) ) {
V_4 = F_26 () ;
F_3 ( V_4 ) ;
}
}
static void F_74 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
T_1 V_66 ;
if ( ! V_15 )
return;
F_57 () ;
if ( F_75 ( F_69 ) ) {
F_58 () ;
return;
}
V_16 -> V_39 = V_67 ;
F_76 ( & V_16 -> V_52 , V_68 , V_69 ) ;
V_66 = F_13 () ;
for (; ; ) {
F_62 ( & V_16 -> V_52 , V_66 ) ;
if ( ! F_51 ( V_66 , 0 ) )
break;
V_66 = F_6 ( V_66 , V_9 ) ;
}
F_58 () ;
}
static void F_77 ( int V_2 , T_1 V_4 )
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
static inline void F_78 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_20 && ! V_16 -> V_45 )
return;
V_4 = F_26 () ;
if ( V_16 -> V_20 )
F_23 ( V_2 , V_4 ) ;
if ( V_16 -> V_45 ) {
F_15 ( V_4 ) ;
F_77 ( V_2 , V_4 ) ;
}
}
static inline void F_74 ( void ) { }
static inline void F_78 ( int V_2 ) { }
void F_79 ( int V_2 )
{
F_80 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static enum V_70 F_81 ( struct V_71 * V_72 )
{
struct V_1 * V_16 =
F_82 ( V_72 , struct V_1 , V_52 ) ;
struct V_63 * V_64 = F_70 () ;
T_1 V_4 = F_26 () ;
int V_2 = F_16 () ;
#ifdef F_83
if ( F_7 ( V_37 == V_38 ) )
V_37 = V_2 ;
#endif
if ( V_37 == V_2 )
F_3 ( V_4 ) ;
if ( V_64 ) {
if ( V_16 -> V_45 ) {
F_19 () ;
V_16 -> V_53 ++ ;
}
F_71 ( F_72 ( V_64 ) ) ;
F_73 ( V_65 ) ;
}
F_63 ( V_72 , V_4 , V_9 ) ;
return V_73 ;
}
void F_84 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
T_1 V_4 = F_26 () ;
F_76 ( & V_16 -> V_52 , V_68 , V_69 ) ;
V_16 -> V_52 . V_74 = F_81 ;
F_62 ( & V_16 -> V_52 , F_13 () ) ;
for (; ; ) {
F_63 ( & V_16 -> V_52 , V_4 , V_9 ) ;
F_64 ( & V_16 -> V_52 ,
V_57 ) ;
if ( F_50 ( & V_16 -> V_52 ) )
break;
V_4 = F_26 () ;
}
#ifdef F_83
if ( V_15 )
V_16 -> V_39 = V_56 ;
#endif
}
void F_85 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_86
if ( V_16 -> V_52 . V_75 )
F_48 ( & V_16 -> V_52 ) ;
# endif
V_16 -> V_39 = V_40 ;
}
void F_87 ( void )
{
int V_2 ;
F_88 (cpu)
F_89 ( 0 , & F_2 ( V_3 , V_2 ) . V_76 ) ;
}
void F_90 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
F_89 ( 0 , & V_16 -> V_76 ) ;
}
int F_91 ( int V_77 )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
if ( ! F_92 ( 0 , & V_16 -> V_76 ) )
return 0 ;
if ( V_16 -> V_39 != V_40 )
return 0 ;
if ( ! F_93 () || ! F_94 () )
return 0 ;
if ( ! V_77 )
return 1 ;
F_74 () ;
return 0 ;
}
