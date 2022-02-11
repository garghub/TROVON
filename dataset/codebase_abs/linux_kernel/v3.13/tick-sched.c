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
F_38 () ;
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
static int T_3 F_49 ( char * V_34 )
{
int V_2 ;
F_50 ( & V_29 ) ;
if ( F_51 ( V_34 , V_29 ) < 0 ) {
F_52 ( L_6 ) ;
return 1 ;
}
V_2 = F_15 () ;
if ( F_53 ( V_2 , V_29 ) ) {
F_52 ( L_7 , V_2 ) ;
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
int V_2 ;
if ( ! V_24 ) {
if ( F_56 () < 0 )
return;
}
F_62 (cpu, tick_nohz_full_mask)
F_63 ( V_2 ) ;
F_64 ( F_55 , 0 ) ;
F_65 ( V_45 , sizeof( V_45 ) , V_29 ) ;
F_66 ( L_9 , V_45 ) ;
}
static int T_3 F_67 ( char * V_34 )
{
if ( ! strcmp ( V_34 , L_10 ) )
V_46 = 0 ;
else if ( ! strcmp ( V_34 , L_11 ) )
V_46 = 1 ;
else
return 0 ;
return 1 ;
}
static void F_68 ( T_1 V_4 )
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
F_69 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_48 )
{
T_1 V_6 ;
if ( V_16 -> V_49 ) {
V_6 = F_4 ( V_4 , V_16 -> V_50 ) ;
if ( F_70 ( V_2 ) > 0 )
V_16 -> V_51 = F_6 ( V_16 -> V_51 , V_6 ) ;
else
V_16 -> V_52 = F_6 ( V_16 -> V_52 , V_6 ) ;
V_16 -> V_50 = V_4 ;
}
if ( V_48 )
* V_48 = F_71 ( V_4 ) ;
}
static void F_72 ( int V_2 , T_1 V_4 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
F_69 ( V_2 , V_16 , V_4 , NULL ) ;
V_16 -> V_49 = 0 ;
F_73 ( 0 ) ;
}
static T_1 F_74 ( int V_2 , struct V_1 * V_16 )
{
T_1 V_4 = F_36 () ;
V_16 -> V_50 = V_4 ;
V_16 -> V_49 = 1 ;
F_75 () ;
return V_4 ;
}
T_4 F_76 ( int V_2 , T_4 * V_48 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_53 ;
if ( ! V_54 )
return - 1 ;
V_4 = F_36 () ;
if ( V_48 ) {
F_69 ( V_2 , V_16 , V_4 , V_48 ) ;
V_53 = V_16 -> V_52 ;
} else {
if ( V_16 -> V_49 && ! F_70 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_50 ) ;
V_53 = F_6 ( V_16 -> V_52 , V_6 ) ;
} else {
V_53 = V_16 -> V_52 ;
}
}
return F_71 ( V_53 ) ;
}
T_4 F_77 ( int V_2 , T_4 * V_48 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_55 ;
if ( ! V_54 )
return - 1 ;
V_4 = F_36 () ;
if ( V_48 ) {
F_69 ( V_2 , V_16 , V_4 , V_48 ) ;
V_55 = V_16 -> V_51 ;
} else {
if ( V_16 -> V_49 && F_70 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_50 ) ;
V_55 = F_6 ( V_16 -> V_51 , V_6 ) ;
} else {
V_55 = V_16 -> V_51 ;
}
}
return F_71 ( V_55 ) ;
}
static T_1 F_78 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
unsigned long V_56 , V_57 , V_58 , V_59 ;
T_1 V_60 , V_61 , V_62 = { . V_8 = 0 } ;
unsigned long V_63 ;
struct V_64 * V_65 = F_34 ( V_66 ) . V_67 ;
T_4 V_68 ;
do {
V_56 = F_79 ( & V_10 ) ;
V_60 = V_7 ;
V_57 = V_69 ;
V_68 = F_80 () ;
} while ( F_81 ( & V_10 , V_56 ) );
if ( F_82 ( V_2 , & V_63 ) ||
F_83 ( V_2 ) || F_84 () ) {
V_58 = V_57 + 1 ;
V_59 = 1 ;
} else {
V_58 = F_85 ( V_57 ) ;
V_59 = V_58 - V_57 ;
if ( V_63 < V_59 ) {
V_58 = V_57 + V_63 ;
V_59 = V_63 ;
}
}
if ( ! V_16 -> V_19 && V_59 <= 1 )
goto V_33;
if ( ( long ) V_59 >= 1 ) {
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_70 = 1 ;
} else if ( V_14 != V_15 ) {
V_68 = V_71 ;
V_16 -> V_70 = 0 ;
} else if ( ! V_16 -> V_70 ) {
V_68 = V_71 ;
}
#ifdef F_86
if ( ! V_16 -> V_72 ) {
V_68 = F_87 ( V_68 ,
F_88 () ) ;
}
#endif
if ( F_89 ( V_59 < V_73 ) ) {
V_68 = F_90 ( T_4 , V_68 ,
V_9 . V_8 * V_59 ) ;
}
if ( V_68 < V_71 )
V_61 = F_10 ( V_60 , V_68 ) ;
else
V_61 . V_8 = V_71 ;
if ( V_16 -> V_19 && F_91 ( V_61 , V_65 -> V_74 ) )
goto V_33;
V_62 = V_61 ;
if ( ! V_16 -> V_19 ) {
F_92 ( V_2 ) ;
F_93 () ;
V_16 -> V_75 = F_94 ( & V_16 -> V_76 ) ;
V_16 -> V_19 = 1 ;
F_28 ( 1 , L_12 ) ;
}
if ( F_7 ( V_61 . V_8 == V_71 ) ) {
if ( V_16 -> V_77 == V_78 )
F_95 ( & V_16 -> V_76 ) ;
goto V_33;
}
if ( V_16 -> V_77 == V_78 ) {
F_96 ( & V_16 -> V_76 , V_61 ,
V_79 ) ;
if ( F_97 ( & V_16 -> V_76 ) )
goto V_33;
} else if ( ! F_98 ( V_61 , 0 ) )
goto V_33;
F_3 ( F_36 () ) ;
}
F_99 ( V_80 ) ;
V_33:
V_16 -> V_58 = V_58 ;
V_16 -> V_57 = V_57 ;
V_16 -> V_81 = F_4 ( V_65 -> V_74 , V_4 ) ;
return V_62 ;
}
static void F_100 ( struct V_1 * V_16 )
{
#ifdef F_86
int V_2 = F_15 () ;
if ( ! F_17 ( V_2 ) || F_20 ( V_20 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_77 == V_82 )
return;
if ( ! F_24 () )
return;
F_78 ( V_16 , F_36 () , V_2 ) ;
#endif
}
static bool F_101 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_102 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_77 == V_82 ) ) {
V_16 -> V_81 = ( T_1 ) { . V_8 = V_83 / V_84 } ;
return false ;
}
if ( F_103 () )
return false ;
if ( F_7 ( F_104 () && F_102 ( V_2 ) ) ) {
static int V_85 ;
if ( V_85 < 10 &&
( F_104 () & V_86 ) ) {
F_105 ( L_13 ,
( unsigned int ) F_104 () ) ;
V_85 ++ ;
}
return false ;
}
if ( F_106 () ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_107 ( struct V_1 * V_16 )
{
T_1 V_4 , V_61 ;
int V_2 = F_15 () ;
V_4 = F_74 ( V_2 , V_16 ) ;
if ( F_101 ( V_2 , V_16 ) ) {
int V_87 = V_16 -> V_19 ;
V_16 -> V_88 ++ ;
V_61 = F_78 ( V_16 , V_4 , V_2 ) ;
if ( V_61 . V_8 > 0LL ) {
V_16 -> V_89 ++ ;
V_16 -> V_90 = V_61 ;
}
if ( ! V_87 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_57 ;
}
}
void F_108 ( void )
{
struct V_1 * V_16 ;
F_25 ( F_26 () ) ;
F_109 () ;
F_110 () ;
V_16 = & F_34 ( V_3 ) ;
V_16 -> V_72 = 1 ;
F_107 ( V_16 ) ;
F_111 () ;
}
void F_112 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
if ( V_16 -> V_72 )
F_107 ( V_16 ) ;
else
F_100 ( V_16 ) ;
}
T_1 F_113 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
return V_16 -> V_81 ;
}
static void F_114 ( struct V_1 * V_16 , T_1 V_4 )
{
F_95 ( & V_16 -> V_76 ) ;
F_115 ( & V_16 -> V_76 , V_16 -> V_75 ) ;
while ( 1 ) {
F_116 ( & V_16 -> V_76 , V_4 , V_9 ) ;
if ( V_16 -> V_77 == V_78 ) {
F_117 ( & V_16 -> V_76 ,
V_79 ) ;
if ( F_97 ( & V_16 -> V_76 ) )
break;
} else {
if ( ! F_98 (
F_94 ( & V_16 -> V_76 ) , 0 ) )
break;
}
V_4 = F_36 () ;
F_3 ( V_4 ) ;
}
}
static void F_35 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_118 () ;
F_119 () ;
F_19 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_91 = V_4 ;
F_114 ( V_16 , V_4 ) ;
}
static void F_120 ( struct V_1 * V_16 )
{
#ifndef F_121
unsigned long V_5 ;
if ( F_122 () )
return;
V_5 = V_69 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_92 )
F_123 ( V_5 ) ;
#endif
}
void F_124 ( void )
{
int V_2 = F_15 () ;
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
F_110 () ;
F_25 ( ! V_16 -> V_72 ) ;
V_16 -> V_72 = 0 ;
if ( V_16 -> V_49 || V_16 -> V_19 )
V_4 = F_36 () ;
if ( V_16 -> V_49 )
F_72 ( V_2 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_35 ( V_16 , V_4 ) ;
F_120 ( V_16 ) ;
}
F_111 () ;
}
static int F_125 ( struct V_1 * V_16 , T_1 V_4 )
{
F_116 ( & V_16 -> V_76 , V_4 , V_9 ) ;
return F_98 ( F_94 ( & V_16 -> V_76 ) , 0 ) ;
}
static void F_126 ( struct V_64 * V_65 )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
struct V_17 * V_18 = F_127 () ;
T_1 V_4 = F_36 () ;
V_65 -> V_74 . V_8 = V_71 ;
F_14 ( V_4 ) ;
F_18 ( V_16 , V_18 ) ;
while ( F_125 ( V_16 , V_4 ) ) {
V_4 = F_36 () ;
F_3 ( V_4 ) ;
}
}
static void F_128 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
T_1 V_93 ;
if ( ! V_54 )
return;
F_110 () ;
if ( F_129 ( F_126 ) ) {
F_111 () ;
return;
}
V_54 = 1 ;
V_16 -> V_77 = V_94 ;
F_130 ( & V_16 -> V_76 , V_95 , V_96 ) ;
V_93 = F_13 () ;
for (; ; ) {
F_115 ( & V_16 -> V_76 , V_93 ) ;
if ( ! F_98 ( V_93 , 0 ) )
break;
V_93 = F_6 ( V_93 , V_9 ) ;
}
F_111 () ;
}
static void F_131 ( int V_2 , T_1 V_4 )
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
static inline void F_132 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_49 && ! V_16 -> V_19 )
return;
V_4 = F_36 () ;
if ( V_16 -> V_49 )
F_72 ( V_2 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_68 ( V_4 ) ;
F_131 ( V_2 , V_4 ) ;
}
}
static inline void F_128 ( void ) { }
static inline void F_132 ( int V_2 ) { }
void F_133 ( int V_2 )
{
F_134 ( V_2 ) ;
F_132 ( V_2 ) ;
}
static enum V_97 F_135 ( struct V_98 * V_99 )
{
struct V_1 * V_16 =
F_136 ( V_99 , struct V_1 , V_76 ) ;
struct V_17 * V_18 = F_127 () ;
T_1 V_4 = F_36 () ;
F_14 ( V_4 ) ;
if ( V_18 )
F_18 ( V_16 , V_18 ) ;
F_116 ( V_99 , V_4 , V_9 ) ;
return V_100 ;
}
static int T_3 F_137 ( char * V_34 )
{
F_138 ( & V_34 , & V_101 ) ;
return 0 ;
}
void F_139 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
T_1 V_4 = F_36 () ;
F_130 ( & V_16 -> V_76 , V_95 , V_96 ) ;
V_16 -> V_76 . V_102 = F_135 ;
F_115 ( & V_16 -> V_76 , F_13 () ) ;
if ( V_101 ) {
T_4 V_103 = F_8 ( V_9 ) >> 1 ;
F_140 ( V_103 , F_141 () ) ;
V_103 *= F_15 () ;
F_142 ( & V_16 -> V_76 , V_103 ) ;
}
for (; ; ) {
F_116 ( & V_16 -> V_76 , V_4 , V_9 ) ;
F_117 ( & V_16 -> V_76 ,
V_79 ) ;
if ( F_97 ( & V_16 -> V_76 ) )
break;
V_4 = F_36 () ;
}
#ifdef F_16
if ( V_46 ) {
V_16 -> V_77 = V_78 ;
V_54 = 1 ;
}
#endif
}
void F_143 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_144
if ( V_16 -> V_76 . V_104 )
F_95 ( & V_16 -> V_76 ) ;
# endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
void F_145 ( void )
{
int V_2 ;
F_146 (cpu)
F_147 ( 0 , & F_2 ( V_3 , V_2 ) . V_105 ) ;
}
void F_148 ( void )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
F_147 ( 0 , & V_16 -> V_105 ) ;
}
int F_149 ( int V_106 )
{
struct V_1 * V_16 = & F_34 ( V_3 ) ;
if ( ! F_150 ( 0 , & V_16 -> V_105 ) )
return 0 ;
if ( V_16 -> V_77 != V_82 )
return 0 ;
if ( ! F_151 () || ! F_152 () )
return 0 ;
if ( ! V_106 )
return 1 ;
F_128 () ;
return 0 ;
}
