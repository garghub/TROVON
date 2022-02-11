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
if ( F_7 ( V_14 == V_15 )
&& ! F_17 ( V_2 ) )
V_14 = V_2 ;
#endif
if ( V_14 == V_2 )
F_3 ( V_4 ) ;
}
static void F_18 ( struct V_1 * V_16 , struct V_17 * V_18 )
{
#ifdef F_16
if ( V_16 -> V_19 ) {
F_19 () ;
if ( F_20 ( V_20 ) )
V_16 -> V_21 ++ ;
}
#endif
F_21 ( F_22 ( V_18 ) ) ;
F_23 ( V_22 ) ;
}
static bool F_24 ( void )
{
F_25 ( ! F_26 () ) ;
if ( ! F_27 () ) {
F_28 ( 0 , L_1 ) ;
return false ;
}
if ( ! F_29 ( V_20 ) ) {
F_28 ( 0 , L_2 ) ;
return false ;
}
if ( ! F_30 () ) {
F_28 ( 0 , L_3 ) ;
return false ;
}
#ifdef F_31
if ( ! V_23 ) {
F_28 ( 0 , L_4 ) ;
F_32 ( V_24 ,
L_5 ) ;
return false ;
}
#endif
return true ;
}
void F_33 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
if ( F_17 ( F_15 () ) ) {
if ( V_16 -> V_19 && ! F_20 ( V_20 ) ) {
if ( ! F_24 () )
F_35 ( V_16 , F_36 () ) ;
}
}
}
static void F_37 ( struct V_25 * V_26 )
{
F_33 () ;
}
void F_38 ( void )
{
if ( F_17 ( F_15 () ) )
F_39 ( & F_34 ( V_27 ) ) ;
}
static void F_40 ( void * V_28 )
{
F_33 () ;
}
void F_41 ( void )
{
if ( ! V_24 )
return;
F_42 () ;
F_43 ( V_29 ,
F_40 , NULL , false ) ;
F_44 () ;
}
void F_45 ( struct V_30 * V_31 )
{
unsigned long V_32 ;
F_46 ( V_32 ) ;
if ( ! F_17 ( F_15 () ) )
goto V_33;
if ( F_47 () && ! F_24 () )
F_38 () ;
V_33:
F_48 ( V_32 ) ;
}
int F_17 ( int V_2 )
{
if ( ! V_24 )
return 0 ;
return F_49 ( V_2 , V_29 ) ;
}
static int T_3 F_50 ( char * V_34 )
{
int V_2 ;
F_51 ( & V_29 ) ;
if ( F_52 ( V_34 , V_29 ) < 0 ) {
F_53 ( L_6 ) ;
return 1 ;
}
V_2 = F_15 () ;
if ( F_49 ( V_2 , V_29 ) ) {
F_53 ( L_7 , V_2 ) ;
F_54 ( V_2 , V_29 ) ;
}
V_24 = true ;
return 1 ;
}
static int F_55 ( struct V_35 * V_36 ,
unsigned long V_37 ,
void * V_38 )
{
unsigned int V_2 = ( unsigned long ) V_38 ;
switch ( V_37 & ~ V_39 ) {
case V_40 :
if ( V_24 && V_14 == V_2 )
return V_41 ;
break;
}
return V_42 ;
}
static int F_56 ( void )
{
int V_43 = - 1 ;
#ifdef F_57
if ( ! F_58 ( & V_29 , V_44 ) ) {
F_59 ( L_8 ) ;
return V_43 ;
}
V_43 = 0 ;
F_60 ( V_29 ) ;
F_54 ( F_15 () , V_29 ) ;
V_24 = true ;
#endif
return V_43 ;
}
void T_3 F_61 ( void )
{
if ( ! V_24 ) {
if ( F_56 () < 0 )
return;
}
F_62 ( F_55 , 0 ) ;
F_63 ( V_45 , sizeof( V_45 ) , V_29 ) ;
F_64 ( L_9 , V_45 ) ;
}
static int T_3 F_65 ( char * V_34 )
{
if ( ! strcmp ( V_34 , L_10 ) )
V_46 = 0 ;
else if ( ! strcmp ( V_34 , L_11 ) )
V_46 = 1 ;
else
return 0 ;
return 1 ;
}
static void F_66 ( T_1 V_4 )
{
int V_2 = F_15 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
unsigned long V_32 ;
V_16 -> V_47 = V_4 ;
F_46 ( V_32 ) ;
F_3 ( V_4 ) ;
F_48 ( V_32 ) ;
F_19 () ;
}
static void
F_67 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_48 )
{
T_1 V_6 ;
if ( V_16 -> V_49 ) {
V_6 = F_4 ( V_4 , V_16 -> V_50 ) ;
if ( F_68 ( V_2 ) > 0 )
V_16 -> V_51 = F_6 ( V_16 -> V_51 , V_6 ) ;
else
V_16 -> V_52 = F_6 ( V_16 -> V_52 , V_6 ) ;
V_16 -> V_50 = V_4 ;
}
if ( V_48 )
* V_48 = F_69 ( V_4 ) ;
}
static void F_70 ( int V_2 , T_1 V_4 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
F_67 ( V_2 , V_16 , V_4 , NULL ) ;
V_16 -> V_49 = 0 ;
F_71 ( 0 ) ;
}
static T_1 F_72 ( int V_2 , struct V_1 * V_16 )
{
T_1 V_4 = F_36 () ;
V_16 -> V_50 = V_4 ;
V_16 -> V_49 = 1 ;
F_73 () ;
return V_4 ;
}
T_4 F_74 ( int V_2 , T_4 * V_48 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_53 ;
if ( ! V_46 )
return - 1 ;
V_4 = F_36 () ;
if ( V_48 ) {
F_67 ( V_2 , V_16 , V_4 , V_48 ) ;
V_53 = V_16 -> V_52 ;
} else {
if ( V_16 -> V_49 && ! F_68 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_50 ) ;
V_53 = F_6 ( V_16 -> V_52 , V_6 ) ;
} else {
V_53 = V_16 -> V_52 ;
}
}
return F_69 ( V_53 ) ;
}
T_4 F_75 ( int V_2 , T_4 * V_48 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_54 ;
if ( ! V_46 )
return - 1 ;
V_4 = F_36 () ;
if ( V_48 ) {
F_67 ( V_2 , V_16 , V_4 , V_48 ) ;
V_54 = V_16 -> V_51 ;
} else {
if ( V_16 -> V_49 && F_68 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_50 ) ;
V_54 = F_6 ( V_16 -> V_51 , V_6 ) ;
} else {
V_54 = V_16 -> V_51 ;
}
}
return F_69 ( V_54 ) ;
}
static T_1 F_76 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
unsigned long V_55 , V_56 , V_57 , V_58 ;
T_1 V_59 , V_60 , V_61 = { . V_8 = 0 } ;
unsigned long V_62 ;
struct V_63 * V_64 = F_34 ( V_65 ) . V_66 ;
T_4 V_67 ;
do {
V_55 = F_77 ( & V_10 ) ;
V_59 = V_7 ;
V_56 = V_68 ;
V_67 = F_78 () ;
} while ( F_79 ( & V_10 , V_55 ) );
if ( F_80 ( V_2 , & V_62 ) ||
F_81 ( V_2 ) || F_82 () ) {
V_57 = V_56 + 1 ;
V_58 = 1 ;
} else {
V_57 = F_83 ( V_56 ) ;
V_58 = V_57 - V_56 ;
if ( V_62 < V_58 ) {
V_57 = V_56 + V_62 ;
V_58 = V_62 ;
}
}
if ( ! V_16 -> V_19 && V_58 <= 1 )
goto V_33;
if ( ( long ) V_58 >= 1 ) {
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_69 = 1 ;
} else if ( V_14 != V_15 ) {
V_67 = V_70 ;
V_16 -> V_69 = 0 ;
} else if ( ! V_16 -> V_69 ) {
V_67 = V_70 ;
}
#ifdef F_84
if ( ! V_16 -> V_71 ) {
V_67 = F_85 ( V_67 ,
F_86 () ) ;
}
#endif
if ( F_87 ( V_58 < V_72 ) ) {
V_67 = F_88 ( T_4 , V_67 ,
V_9 . V_8 * V_58 ) ;
}
if ( V_67 < V_70 )
V_60 = F_10 ( V_59 , V_67 ) ;
else
V_60 . V_8 = V_70 ;
if ( V_16 -> V_19 && F_89 ( V_60 , V_64 -> V_73 ) )
goto V_33;
V_61 = V_60 ;
if ( ! V_16 -> V_19 ) {
F_90 ( V_2 ) ;
F_91 () ;
V_16 -> V_74 = F_92 ( & V_16 -> V_75 ) ;
V_16 -> V_19 = 1 ;
F_28 ( 1 , L_12 ) ;
}
if ( F_7 ( V_60 . V_8 == V_70 ) ) {
if ( V_16 -> V_76 == V_77 )
F_93 ( & V_16 -> V_75 ) ;
goto V_33;
}
if ( V_16 -> V_76 == V_77 ) {
F_94 ( & V_16 -> V_75 , V_60 ,
V_78 ) ;
if ( F_95 ( & V_16 -> V_75 ) )
goto V_33;
} else if ( ! F_96 ( V_60 , 0 ) )
goto V_33;
F_3 ( F_36 () ) ;
}
F_97 ( V_79 ) ;
V_33:
V_16 -> V_57 = V_57 ;
V_16 -> V_56 = V_56 ;
V_16 -> V_80 = F_4 ( V_64 -> V_73 , V_4 ) ;
return V_61 ;
}
static void F_98 ( struct V_1 * V_16 )
{
#ifdef F_84
int V_2 = F_15 () ;
if ( ! F_17 ( V_2 ) || F_20 ( V_20 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_76 == V_81 )
return;
if ( ! F_24 () )
return;
F_76 ( V_16 , F_36 () , V_2 ) ;
#endif
}
static bool F_99 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_100 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_76 == V_81 ) )
return false ;
if ( F_101 () )
return false ;
if ( F_7 ( F_102 () && F_100 ( V_2 ) ) ) {
static int V_82 ;
if ( V_82 < 10 &&
( F_102 () & V_83 ) ) {
F_103 ( L_13 ,
( unsigned int ) F_102 () ) ;
V_82 ++ ;
}
return false ;
}
if ( V_24 ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_104 ( struct V_1 * V_16 )
{
T_1 V_4 , V_60 ;
int V_2 = F_15 () ;
V_4 = F_72 ( V_2 , V_16 ) ;
if ( F_99 ( V_2 , V_16 ) ) {
int V_84 = V_16 -> V_19 ;
V_16 -> V_85 ++ ;
V_60 = F_76 ( V_16 , V_4 , V_2 ) ;
if ( V_60 . V_8 > 0LL ) {
V_16 -> V_86 ++ ;
V_16 -> V_87 = V_60 ;
}
if ( ! V_84 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_56 ;
}
}
void F_105 ( void )
{
struct V_1 * V_16 ;
F_25 ( F_26 () ) ;
F_106 () ;
F_107 () ;
V_16 = & F_34 ( V_3 ) ;
V_16 -> V_71 = 1 ;
F_104 ( V_16 ) ;
F_108 () ;
}
void F_109 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
if ( V_16 -> V_71 )
F_104 ( V_16 ) ;
else
F_98 ( V_16 ) ;
}
T_1 F_110 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
return V_16 -> V_80 ;
}
static void F_111 ( struct V_1 * V_16 , T_1 V_4 )
{
F_93 ( & V_16 -> V_75 ) ;
F_112 ( & V_16 -> V_75 , V_16 -> V_74 ) ;
while ( 1 ) {
F_113 ( & V_16 -> V_75 , V_4 , V_9 ) ;
if ( V_16 -> V_76 == V_77 ) {
F_114 ( & V_16 -> V_75 ,
V_78 ) ;
if ( F_95 ( & V_16 -> V_75 ) )
break;
} else {
if ( ! F_96 (
F_92 ( & V_16 -> V_75 ) , 0 ) )
break;
}
V_4 = F_36 () ;
F_3 ( V_4 ) ;
}
}
static void F_35 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_115 () ;
F_116 () ;
F_19 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_88 = V_4 ;
F_111 ( V_16 , V_4 ) ;
}
static void F_117 ( struct V_1 * V_16 )
{
#ifndef F_118
unsigned long V_5 ;
if ( F_119 () )
return;
V_5 = V_68 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_89 )
F_120 ( V_5 ) ;
#endif
}
void F_121 ( void )
{
int V_2 = F_15 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
F_107 () ;
F_25 ( ! V_16 -> V_71 ) ;
V_16 -> V_71 = 0 ;
if ( V_16 -> V_49 || V_16 -> V_19 )
V_4 = F_36 () ;
if ( V_16 -> V_49 )
F_70 ( V_2 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_35 ( V_16 , V_4 ) ;
F_117 ( V_16 ) ;
}
F_108 () ;
}
static int F_122 ( struct V_1 * V_16 , T_1 V_4 )
{
F_113 ( & V_16 -> V_75 , V_4 , V_9 ) ;
return F_96 ( F_92 ( & V_16 -> V_75 ) , 0 ) ;
}
static void F_123 ( struct V_63 * V_64 )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
struct V_17 * V_18 = F_124 () ;
T_1 V_4 = F_36 () ;
V_64 -> V_73 . V_8 = V_70 ;
F_14 ( V_4 ) ;
F_18 ( V_16 , V_18 ) ;
while ( F_122 ( V_16 , V_4 ) ) {
V_4 = F_36 () ;
F_3 ( V_4 ) ;
}
}
static void F_125 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
T_1 V_90 ;
if ( ! V_46 )
return;
F_107 () ;
if ( F_126 ( F_123 ) ) {
F_108 () ;
return;
}
V_16 -> V_76 = V_91 ;
F_127 ( & V_16 -> V_75 , V_92 , V_93 ) ;
V_90 = F_13 () ;
for (; ; ) {
F_112 ( & V_16 -> V_75 , V_90 ) ;
if ( ! F_96 ( V_90 , 0 ) )
break;
V_90 = F_6 ( V_90 , V_9 ) ;
}
F_108 () ;
}
static void F_128 ( int V_2 , T_1 V_4 )
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
static inline void F_129 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_49 && ! V_16 -> V_19 )
return;
V_4 = F_36 () ;
if ( V_16 -> V_49 )
F_70 ( V_2 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_66 ( V_4 ) ;
F_128 ( V_2 , V_4 ) ;
}
}
static inline void F_125 ( void ) { }
static inline void F_129 ( int V_2 ) { }
void F_130 ( int V_2 )
{
F_131 ( V_2 ) ;
F_129 ( V_2 ) ;
}
static enum V_94 F_132 ( struct V_95 * V_96 )
{
struct V_1 * V_16 =
F_133 ( V_96 , struct V_1 , V_75 ) ;
struct V_17 * V_18 = F_124 () ;
T_1 V_4 = F_36 () ;
F_14 ( V_4 ) ;
if ( V_18 )
F_18 ( V_16 , V_18 ) ;
F_113 ( V_96 , V_4 , V_9 ) ;
return V_97 ;
}
static int T_3 F_134 ( char * V_34 )
{
F_135 ( & V_34 , & V_98 ) ;
return 0 ;
}
void F_136 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
T_1 V_4 = F_36 () ;
F_127 ( & V_16 -> V_75 , V_92 , V_93 ) ;
V_16 -> V_75 . V_99 = F_132 ;
F_112 ( & V_16 -> V_75 , F_13 () ) ;
if ( V_98 ) {
T_4 V_100 = F_8 ( V_9 ) >> 1 ;
F_137 ( V_100 , F_138 () ) ;
V_100 *= F_15 () ;
F_139 ( & V_16 -> V_75 , V_100 ) ;
}
for (; ; ) {
F_113 ( & V_16 -> V_75 , V_4 , V_9 ) ;
F_114 ( & V_16 -> V_75 ,
V_78 ) ;
if ( F_95 ( & V_16 -> V_75 ) )
break;
V_4 = F_36 () ;
}
#ifdef F_16
if ( V_46 )
V_16 -> V_76 = V_77 ;
#endif
}
void F_140 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_141
if ( V_16 -> V_75 . V_101 )
F_93 ( & V_16 -> V_75 ) ;
# endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
void F_142 ( void )
{
int V_2 ;
F_143 (cpu)
F_144 ( 0 , & F_2 ( V_3 , V_2 ) . V_102 ) ;
}
void F_145 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
F_144 ( 0 , & V_16 -> V_102 ) ;
}
int F_146 ( int V_103 )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
if ( ! F_147 ( 0 , & V_16 -> V_102 ) )
return 0 ;
if ( V_16 -> V_76 != V_81 )
return 0 ;
if ( ! F_148 () || ! F_149 () )
return 0 ;
if ( ! V_103 )
return 1 ;
F_125 () ;
return 0 ;
}
