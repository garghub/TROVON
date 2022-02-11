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
void F_30 ( int V_26 )
{
unsigned long V_27 , V_28 , V_29 , V_30 , V_17 ;
struct V_1 * V_16 ;
T_1 V_31 , V_32 , V_4 ;
struct V_33 * V_34 = F_31 ( V_35 ) . V_36 ;
T_4 V_37 ;
int V_2 ;
F_17 ( V_17 ) ;
V_2 = F_16 () ;
V_16 = & F_2 ( V_3 , V_2 ) ;
if ( ! V_26 && ! V_16 -> V_26 )
goto V_38;
V_16 -> V_26 = 1 ;
V_4 = F_25 ( V_2 , V_16 ) ;
if ( F_7 ( ! F_32 ( V_2 ) ) ) {
if ( V_2 == V_39 )
V_39 = V_40 ;
}
if ( F_7 ( V_16 -> V_41 == V_42 ) )
goto V_38;
if ( F_33 () )
goto V_38;
if ( F_7 ( F_34 () && F_32 ( V_2 ) ) ) {
static int V_43 ;
if ( V_43 < 10 ) {
F_35 ( V_44 L_3 ,
( unsigned int ) F_34 () ) ;
V_43 ++ ;
}
goto V_38;
}
V_16 -> V_45 ++ ;
do {
V_27 = F_36 ( & V_10 ) ;
V_31 = V_7 ;
V_28 = V_46 ;
V_37 = F_37 () ;
} while ( F_38 ( & V_10 , V_27 ) );
if ( F_39 ( V_2 ) || F_40 ( V_2 ) ||
F_41 ( V_2 ) ) {
V_29 = V_28 + 1 ;
V_30 = 1 ;
} else {
V_29 = F_42 ( V_28 ) ;
V_30 = V_29 - V_28 ;
}
if ( ! V_16 -> V_47 && V_30 == 1 )
goto V_48;
if ( ( long ) V_30 >= 1 ) {
if ( V_2 == V_39 ) {
V_39 = V_40 ;
V_16 -> V_49 = 1 ;
} else if ( V_39 != V_40 ) {
V_37 = V_50 ;
V_16 -> V_49 = 0 ;
} else if ( ! V_16 -> V_49 ) {
V_37 = V_50 ;
}
if ( F_43 ( V_30 < V_51 ) ) {
V_37 = F_44 ( T_4 , V_37 ,
V_9 . V_8 * V_30 ) ;
}
if ( V_37 < V_50 )
V_32 = F_10 ( V_31 , V_37 ) ;
else
V_32 . V_8 = V_50 ;
if ( V_16 -> V_47 && F_45 ( V_32 , V_34 -> V_52 ) )
goto V_48;
if ( ! V_16 -> V_47 ) {
F_46 ( 1 ) ;
V_16 -> V_53 = F_47 ( & V_16 -> V_54 ) ;
V_16 -> V_47 = 1 ;
V_16 -> V_55 = V_28 ;
F_48 () ;
}
V_16 -> V_56 ++ ;
V_16 -> V_57 = V_32 ;
if ( F_7 ( V_32 . V_8 == V_50 ) ) {
if ( V_16 -> V_41 == V_58 )
F_49 ( & V_16 -> V_54 ) ;
goto V_48;
}
if ( V_16 -> V_41 == V_58 ) {
F_50 ( & V_16 -> V_54 , V_32 ,
V_59 ) ;
if ( F_51 ( & V_16 -> V_54 ) )
goto V_48;
} else if ( ! F_52 ( V_32 , 0 ) )
goto V_48;
F_3 ( F_26 () ) ;
}
F_53 ( V_60 ) ;
V_48:
V_16 -> V_29 = V_29 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_61 = F_4 ( V_34 -> V_52 , V_4 ) ;
V_38:
F_18 ( V_17 ) ;
}
T_1 F_54 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
return V_16 -> V_61 ;
}
static void F_55 ( struct V_1 * V_16 , T_1 V_4 )
{
F_49 ( & V_16 -> V_54 ) ;
F_56 ( & V_16 -> V_54 , V_16 -> V_53 ) ;
while ( 1 ) {
F_57 ( & V_16 -> V_54 , V_4 , V_9 ) ;
if ( V_16 -> V_41 == V_58 ) {
F_58 ( & V_16 -> V_54 ,
V_59 ) ;
if ( F_51 ( & V_16 -> V_54 ) )
break;
} else {
if ( ! F_52 (
F_47 ( & V_16 -> V_54 ) , 0 ) )
break;
}
F_3 ( V_4 ) ;
V_4 = F_26 () ;
}
}
void F_59 ( void )
{
int V_2 = F_16 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
#ifndef F_60
unsigned long V_5 ;
#endif
T_1 V_4 ;
F_61 () ;
if ( V_16 -> V_20 || ( V_16 -> V_26 && V_16 -> V_47 ) )
V_4 = F_26 () ;
if ( V_16 -> V_20 )
F_23 ( V_2 , V_4 ) ;
if ( ! V_16 -> V_26 || ! V_16 -> V_47 ) {
V_16 -> V_26 = 0 ;
F_62 () ;
return;
}
V_16 -> V_26 = 0 ;
F_63 () ;
F_46 ( 0 ) ;
F_3 ( V_4 ) ;
#ifndef F_60
V_5 = V_46 - V_16 -> V_55 ;
if ( V_5 && V_5 < V_62 )
F_64 ( V_5 ) ;
#endif
F_19 () ;
V_16 -> V_47 = 0 ;
V_16 -> V_63 = V_4 ;
F_55 ( V_16 , V_4 ) ;
F_62 () ;
}
static int F_65 ( struct V_1 * V_16 , T_1 V_4 )
{
F_57 ( & V_16 -> V_54 , V_4 , V_9 ) ;
return F_52 ( F_47 ( & V_16 -> V_54 ) , 0 ) ;
}
static void F_66 ( struct V_33 * V_34 )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
struct V_64 * V_65 = F_67 () ;
int V_2 = F_16 () ;
T_1 V_4 = F_26 () ;
V_34 -> V_52 . V_8 = V_50 ;
if ( F_7 ( V_39 == V_40 ) )
V_39 = V_2 ;
if ( V_39 == V_2 )
F_3 ( V_4 ) ;
if ( V_16 -> V_47 ) {
F_19 () ;
V_16 -> V_55 ++ ;
}
F_68 ( F_69 ( V_65 ) ) ;
F_70 ( V_66 ) ;
while ( F_65 ( V_16 , V_4 ) ) {
V_4 = F_26 () ;
F_3 ( V_4 ) ;
}
}
static void F_71 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
T_1 V_67 ;
if ( ! V_15 )
return;
F_61 () ;
if ( F_72 ( F_66 ) ) {
F_62 () ;
return;
}
V_16 -> V_41 = V_68 ;
F_73 ( & V_16 -> V_54 , V_69 , V_70 ) ;
V_67 = F_13 () ;
for (; ; ) {
F_56 ( & V_16 -> V_54 , V_67 ) ;
if ( ! F_52 ( V_67 , 0 ) )
break;
V_67 = F_6 ( V_67 , V_9 ) ;
}
F_62 () ;
}
static void F_74 ( int V_2 , T_1 V_4 )
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
static inline void F_75 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_20 && ! V_16 -> V_47 )
return;
V_4 = F_26 () ;
if ( V_16 -> V_20 )
F_23 ( V_2 , V_4 ) ;
if ( V_16 -> V_47 ) {
F_15 ( V_4 ) ;
F_74 ( V_2 , V_4 ) ;
}
}
static inline void F_71 ( void ) { }
static inline void F_75 ( int V_2 ) { }
void F_76 ( int V_2 )
{
F_77 ( V_2 ) ;
F_75 ( V_2 ) ;
}
static enum V_71 F_78 ( struct V_72 * V_73 )
{
struct V_1 * V_16 =
F_79 ( V_73 , struct V_1 , V_54 ) ;
struct V_64 * V_65 = F_67 () ;
T_1 V_4 = F_26 () ;
int V_2 = F_16 () ;
#ifdef F_80
if ( F_7 ( V_39 == V_40 ) )
V_39 = V_2 ;
#endif
if ( V_39 == V_2 )
F_3 ( V_4 ) ;
if ( V_65 ) {
if ( V_16 -> V_47 ) {
F_19 () ;
V_16 -> V_55 ++ ;
}
F_68 ( F_69 ( V_65 ) ) ;
F_70 ( V_66 ) ;
}
F_57 ( V_73 , V_4 , V_9 ) ;
return V_74 ;
}
void F_81 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
T_1 V_4 = F_26 () ;
F_73 ( & V_16 -> V_54 , V_69 , V_70 ) ;
V_16 -> V_54 . V_75 = F_78 ;
F_56 ( & V_16 -> V_54 , F_13 () ) ;
for (; ; ) {
F_57 ( & V_16 -> V_54 , V_4 , V_9 ) ;
F_58 ( & V_16 -> V_54 ,
V_59 ) ;
if ( F_51 ( & V_16 -> V_54 ) )
break;
V_4 = F_26 () ;
}
#ifdef F_80
if ( V_15 )
V_16 -> V_41 = V_58 ;
#endif
}
void F_82 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_83
if ( V_16 -> V_54 . V_76 )
F_49 ( & V_16 -> V_54 ) ;
# endif
V_16 -> V_41 = V_42 ;
}
void F_84 ( void )
{
int V_2 ;
F_85 (cpu)
F_86 ( 0 , & F_2 ( V_3 , V_2 ) . V_77 ) ;
}
void F_87 ( void )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
F_86 ( 0 , & V_16 -> V_77 ) ;
}
int F_88 ( int V_78 )
{
struct V_1 * V_16 = & F_31 ( V_3 ) ;
if ( ! F_89 ( 0 , & V_16 -> V_77 ) )
return 0 ;
if ( V_16 -> V_41 != V_42 )
return 0 ;
if ( ! F_90 () || ! F_91 () )
return 0 ;
if ( ! V_78 )
return 1 ;
F_71 () ;
return 0 ;
}
