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
} else {
F_12 ( & V_10 ) ;
return;
}
F_12 ( & V_10 ) ;
F_13 () ;
}
static T_1 F_14 ( void )
{
T_1 V_13 ;
F_5 ( & V_10 ) ;
if ( V_7 . V_8 == 0 )
V_7 = V_12 ;
V_13 = V_7 ;
F_12 ( & V_10 ) ;
return V_13 ;
}
static void F_15 ( T_1 V_4 )
{
int V_2 = F_16 () ;
#ifdef F_17
if ( F_7 ( V_14 == V_15 )
&& ! F_18 ( V_2 ) )
V_14 = V_2 ;
#endif
if ( V_14 == V_2 )
F_3 ( V_4 ) ;
}
static void F_19 ( struct V_1 * V_16 , struct V_17 * V_18 )
{
#ifdef F_17
if ( V_16 -> V_19 ) {
F_20 () ;
if ( F_21 ( V_20 ) )
V_16 -> V_21 ++ ;
}
#endif
F_22 ( F_23 ( V_18 ) ) ;
F_24 ( V_22 ) ;
}
static bool F_25 ( void )
{
F_26 ( ! F_27 () ) ;
if ( ! F_28 () ) {
F_29 ( 0 , L_1 ) ;
return false ;
}
if ( ! F_30 ( V_20 ) ) {
F_29 ( 0 , L_2 ) ;
return false ;
}
if ( ! F_31 () ) {
F_29 ( 0 , L_3 ) ;
return false ;
}
#ifdef F_32
if ( ! F_33 () ) {
F_29 ( 0 , L_4 ) ;
F_34 ( V_23 ,
L_5 ) ;
return false ;
}
#endif
return true ;
}
void F_35 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
if ( F_18 ( F_16 () ) ) {
if ( V_16 -> V_19 && ! F_21 ( V_20 ) ) {
if ( ! F_25 () )
F_37 ( V_16 , F_38 () ) ;
}
}
}
static void F_39 ( struct V_24 * V_25 )
{
F_35 () ;
}
void F_40 ( void )
{
if ( ! F_18 ( F_16 () ) )
return;
F_41 ( & F_36 ( V_26 ) ) ;
}
void F_42 ( int V_2 )
{
if ( ! F_18 ( V_2 ) )
return;
F_43 ( & F_2 ( V_26 , V_2 ) , V_2 ) ;
}
static void F_44 ( void * V_27 )
{
F_35 () ;
}
void F_45 ( void )
{
if ( ! V_23 )
return;
F_46 () ;
F_47 ( V_28 ,
F_44 , NULL , false ) ;
F_40 () ;
F_48 () ;
}
void F_49 ( struct V_29 * V_30 )
{
unsigned long V_31 ;
F_50 ( V_31 ) ;
if ( ! F_18 ( F_16 () ) )
goto V_32;
if ( F_51 () && ! F_25 () )
F_40 () ;
V_32:
F_52 ( V_31 ) ;
}
static int T_3 F_53 ( char * V_33 )
{
int V_2 ;
F_54 ( & V_28 ) ;
F_54 ( & V_34 ) ;
if ( F_55 ( V_33 , V_28 ) < 0 ) {
F_56 ( L_6 ) ;
return 1 ;
}
V_2 = F_16 () ;
if ( F_57 ( V_2 , V_28 ) ) {
F_56 ( L_7 , V_2 ) ;
F_58 ( V_2 , V_28 ) ;
}
F_59 ( V_34 ,
V_35 , V_28 ) ;
V_23 = true ;
return 1 ;
}
static int F_60 ( struct V_36 * V_37 ,
unsigned long V_38 ,
void * V_39 )
{
unsigned int V_2 = ( unsigned long ) V_39 ;
switch ( V_38 & ~ V_40 ) {
case V_41 :
if ( V_23 && V_14 == V_2 )
return V_42 ;
break;
}
return V_43 ;
}
static int F_61 ( void )
{
int V_44 = - 1 ;
#ifdef F_62
if ( ! F_63 ( & V_28 , V_45 ) ) {
F_64 ( L_8 ) ;
return V_44 ;
}
if ( ! F_63 ( & V_34 , V_45 ) ) {
F_64 ( L_9 ) ;
return V_44 ;
}
V_44 = 0 ;
F_65 ( V_28 ) ;
F_58 ( F_16 () , V_28 ) ;
F_66 ( V_34 ) ;
F_67 ( F_16 () , V_34 ) ;
V_23 = true ;
#endif
return V_44 ;
}
void T_3 F_68 ( void )
{
int V_2 ;
if ( ! V_23 ) {
if ( F_61 () < 0 )
return;
}
F_69 (cpu, tick_nohz_full_mask)
F_70 ( V_2 ) ;
F_71 ( F_60 , 0 ) ;
F_72 ( V_46 , sizeof( V_46 ) , V_28 ) ;
F_73 ( L_10 , V_46 ) ;
}
static int T_3 F_74 ( char * V_33 )
{
if ( ! strcmp ( V_33 , L_11 ) )
V_47 = 0 ;
else if ( ! strcmp ( V_33 , L_12 ) )
V_47 = 1 ;
else
return 0 ;
return 1 ;
}
static void F_75 ( T_1 V_4 )
{
unsigned long V_31 ;
F_76 ( V_3 . V_48 , V_4 ) ;
F_50 ( V_31 ) ;
F_3 ( V_4 ) ;
F_52 ( V_31 ) ;
F_20 () ;
}
static void
F_77 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_49 )
{
T_1 V_6 ;
if ( V_16 -> V_50 ) {
V_6 = F_4 ( V_4 , V_16 -> V_51 ) ;
if ( F_78 ( V_2 ) > 0 )
V_16 -> V_52 = F_6 ( V_16 -> V_52 , V_6 ) ;
else
V_16 -> V_53 = F_6 ( V_16 -> V_53 , V_6 ) ;
V_16 -> V_51 = V_4 ;
}
if ( V_49 )
* V_49 = F_79 ( V_4 ) ;
}
static void F_80 ( struct V_1 * V_16 , T_1 V_4 )
{
F_77 ( F_16 () , V_16 , V_4 , NULL ) ;
V_16 -> V_50 = 0 ;
F_81 ( 0 ) ;
}
static T_1 F_82 ( struct V_1 * V_16 )
{
T_1 V_4 = F_38 () ;
V_16 -> V_51 = V_4 ;
V_16 -> V_50 = 1 ;
F_83 () ;
return V_4 ;
}
T_4 F_84 ( int V_2 , T_4 * V_49 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_54 ;
if ( ! V_55 )
return - 1 ;
V_4 = F_38 () ;
if ( V_49 ) {
F_77 ( V_2 , V_16 , V_4 , V_49 ) ;
V_54 = V_16 -> V_53 ;
} else {
if ( V_16 -> V_50 && ! F_78 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_51 ) ;
V_54 = F_6 ( V_16 -> V_53 , V_6 ) ;
} else {
V_54 = V_16 -> V_53 ;
}
}
return F_79 ( V_54 ) ;
}
T_4 F_85 ( int V_2 , T_4 * V_49 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_56 ;
if ( ! V_55 )
return - 1 ;
V_4 = F_38 () ;
if ( V_49 ) {
F_77 ( V_2 , V_16 , V_4 , V_49 ) ;
V_56 = V_16 -> V_52 ;
} else {
if ( V_16 -> V_50 && F_78 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_51 ) ;
V_56 = F_6 ( V_16 -> V_52 , V_6 ) ;
} else {
V_56 = V_16 -> V_52 ;
}
}
return F_79 ( V_56 ) ;
}
static T_1 F_86 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
unsigned long V_57 , V_58 , V_59 , V_60 ;
T_1 V_61 , V_62 , V_63 = { . V_8 = 0 } ;
unsigned long V_64 ;
struct V_65 * V_66 = F_36 ( V_67 ) . V_68 ;
T_4 V_69 ;
V_69 = F_87 () ;
do {
V_57 = F_88 ( & V_10 ) ;
V_61 = V_7 ;
V_58 = V_70 ;
} while ( F_89 ( & V_10 , V_57 ) );
if ( F_90 ( V_2 , & V_64 ) ||
F_91 ( V_2 ) || F_92 () ) {
V_59 = V_58 + 1 ;
V_60 = 1 ;
} else {
V_59 = F_93 ( V_58 ) ;
V_60 = V_59 - V_58 ;
if ( V_64 < V_60 ) {
V_59 = V_58 + V_64 ;
V_60 = V_64 ;
}
}
if ( ! V_16 -> V_19 && V_60 <= 1 )
goto V_32;
if ( ( long ) V_60 >= 1 ) {
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_71 = 1 ;
} else if ( V_14 != V_15 ) {
V_69 = V_72 ;
V_16 -> V_71 = 0 ;
} else if ( ! V_16 -> V_71 ) {
V_69 = V_72 ;
}
#ifdef F_94
if ( ! V_16 -> V_73 ) {
V_69 = F_95 ( V_69 ,
F_96 () ) ;
}
#endif
if ( F_97 ( V_60 < V_74 ) ) {
V_69 = F_98 ( T_4 , V_69 ,
V_9 . V_8 * V_60 ) ;
}
if ( V_69 < V_72 )
V_62 = F_10 ( V_61 , V_69 ) ;
else
V_62 . V_8 = V_72 ;
if ( V_16 -> V_19 && F_99 ( V_62 , V_66 -> V_75 ) )
goto V_32;
V_63 = V_62 ;
if ( ! V_16 -> V_19 ) {
F_100 ( V_2 ) ;
F_101 () ;
V_16 -> V_76 = F_102 ( & V_16 -> V_77 ) ;
V_16 -> V_19 = 1 ;
F_29 ( 1 , L_13 ) ;
}
if ( F_7 ( V_62 . V_8 == V_72 ) ) {
if ( V_16 -> V_78 == V_79 )
F_103 ( & V_16 -> V_77 ) ;
goto V_32;
}
if ( V_16 -> V_78 == V_79 ) {
F_104 ( & V_16 -> V_77 , V_62 ,
V_80 ) ;
if ( F_105 ( & V_16 -> V_77 ) )
goto V_32;
} else if ( ! F_106 ( V_62 , 0 ) )
goto V_32;
F_3 ( F_38 () ) ;
}
F_107 ( V_81 ) ;
V_32:
V_16 -> V_59 = V_59 ;
V_16 -> V_58 = V_58 ;
V_16 -> V_82 = F_4 ( V_66 -> V_75 , V_4 ) ;
return V_63 ;
}
static void F_108 ( struct V_1 * V_16 )
{
#ifdef F_94
int V_2 = F_16 () ;
if ( ! F_18 ( V_2 ) || F_21 ( V_20 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_78 == V_83 )
return;
if ( ! F_25 () )
return;
F_86 ( V_16 , F_38 () , V_2 ) ;
#endif
}
static bool F_109 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_110 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_78 == V_83 ) ) {
V_16 -> V_82 = ( T_1 ) { . V_8 = V_84 / V_85 } ;
return false ;
}
if ( F_111 () )
return false ;
if ( F_7 ( F_112 () && F_110 ( V_2 ) ) ) {
static int V_86 ;
if ( V_86 < 10 &&
( F_112 () & V_87 ) ) {
F_113 ( L_14 ,
( unsigned int ) F_112 () ) ;
V_86 ++ ;
}
return false ;
}
if ( F_114 () ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_115 ( struct V_1 * V_16 )
{
T_1 V_4 , V_62 ;
int V_2 = F_16 () ;
V_4 = F_82 ( V_16 ) ;
if ( F_109 ( V_2 , V_16 ) ) {
int V_88 = V_16 -> V_19 ;
V_16 -> V_89 ++ ;
V_62 = F_86 ( V_16 , V_4 , V_2 ) ;
if ( V_62 . V_8 > 0LL ) {
V_16 -> V_90 ++ ;
V_16 -> V_91 = V_62 ;
}
if ( ! V_88 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_58 ;
}
}
void F_116 ( void )
{
struct V_1 * V_16 ;
F_26 ( F_27 () ) ;
F_117 () ;
F_118 () ;
V_16 = & F_36 ( V_3 ) ;
V_16 -> V_73 = 1 ;
F_115 ( V_16 ) ;
F_119 () ;
}
void F_120 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
if ( V_16 -> V_73 )
F_115 ( V_16 ) ;
else
F_108 ( V_16 ) ;
}
T_1 F_121 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
return V_16 -> V_82 ;
}
static void F_122 ( struct V_1 * V_16 , T_1 V_4 )
{
F_103 ( & V_16 -> V_77 ) ;
F_123 ( & V_16 -> V_77 , V_16 -> V_76 ) ;
while ( 1 ) {
F_124 ( & V_16 -> V_77 , V_4 , V_9 ) ;
if ( V_16 -> V_78 == V_79 ) {
F_125 ( & V_16 -> V_77 ,
V_80 ) ;
if ( F_105 ( & V_16 -> V_77 ) )
break;
} else {
if ( ! F_106 (
F_102 ( & V_16 -> V_77 ) , 0 ) )
break;
}
V_4 = F_38 () ;
F_3 ( V_4 ) ;
}
}
static void F_37 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_126 () ;
F_127 () ;
F_20 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_92 = V_4 ;
F_122 ( V_16 , V_4 ) ;
}
static void F_128 ( struct V_1 * V_16 )
{
#ifndef F_129
unsigned long V_5 ;
if ( F_130 () )
return;
V_5 = V_70 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_93 )
F_131 ( V_5 ) ;
#endif
}
void F_132 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
T_1 V_4 ;
F_118 () ;
F_26 ( ! V_16 -> V_73 ) ;
V_16 -> V_73 = 0 ;
if ( V_16 -> V_50 || V_16 -> V_19 )
V_4 = F_38 () ;
if ( V_16 -> V_50 )
F_80 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_37 ( V_16 , V_4 ) ;
F_128 ( V_16 ) ;
}
F_119 () ;
}
static int F_133 ( struct V_1 * V_16 , T_1 V_4 )
{
F_124 ( & V_16 -> V_77 , V_4 , V_9 ) ;
return F_106 ( F_102 ( & V_16 -> V_77 ) , 0 ) ;
}
static void F_134 ( struct V_65 * V_66 )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
struct V_17 * V_18 = F_135 () ;
T_1 V_4 = F_38 () ;
V_66 -> V_75 . V_8 = V_72 ;
F_15 ( V_4 ) ;
F_19 ( V_16 , V_18 ) ;
while ( F_133 ( V_16 , V_4 ) ) {
V_4 = F_38 () ;
F_3 ( V_4 ) ;
}
}
static void F_136 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
T_1 V_94 ;
if ( ! V_47 )
return;
F_118 () ;
if ( F_137 ( F_134 ) ) {
F_119 () ;
return;
}
V_55 = 1 ;
V_16 -> V_78 = V_95 ;
F_138 ( & V_16 -> V_77 , V_96 , V_97 ) ;
V_94 = F_14 () ;
for (; ; ) {
F_123 ( & V_16 -> V_77 , V_94 ) ;
if ( ! F_106 ( V_94 , 0 ) )
break;
V_94 = F_6 ( V_94 , V_9 ) ;
}
F_119 () ;
}
static void F_139 ( struct V_1 * V_16 , T_1 V_4 )
{
#if 0
ktime_t delta;
delta = ktime_sub(hrtimer_get_expires(&ts->sched_timer), now);
if (delta.tv64 <= tick_period.tv64)
return;
tick_nohz_restart(ts, now);
#endif
}
static inline void F_140 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_50 && ! V_16 -> V_19 )
return;
V_4 = F_38 () ;
if ( V_16 -> V_50 )
F_80 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_75 ( V_4 ) ;
F_139 ( V_16 , V_4 ) ;
}
}
static inline void F_136 ( void ) { }
static inline void F_140 ( void ) { }
void F_141 ( void )
{
F_142 () ;
F_140 () ;
}
static enum V_98 F_143 ( struct V_99 * V_100 )
{
struct V_1 * V_16 =
F_144 ( V_100 , struct V_1 , V_77 ) ;
struct V_17 * V_18 = F_135 () ;
T_1 V_4 = F_38 () ;
F_15 ( V_4 ) ;
if ( V_18 )
F_19 ( V_16 , V_18 ) ;
F_124 ( V_100 , V_4 , V_9 ) ;
return V_101 ;
}
static int T_3 F_145 ( char * V_33 )
{
F_146 ( & V_33 , & V_102 ) ;
return 0 ;
}
void F_147 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
T_1 V_4 = F_38 () ;
F_138 ( & V_16 -> V_77 , V_96 , V_97 ) ;
V_16 -> V_77 . V_103 = F_143 ;
F_123 ( & V_16 -> V_77 , F_14 () ) ;
if ( V_102 ) {
T_4 V_104 = F_8 ( V_9 ) >> 1 ;
F_148 ( V_104 , F_149 () ) ;
V_104 *= F_16 () ;
F_150 ( & V_16 -> V_77 , V_104 ) ;
}
for (; ; ) {
F_124 ( & V_16 -> V_77 , V_4 , V_9 ) ;
F_125 ( & V_16 -> V_77 ,
V_80 ) ;
if ( F_105 ( & V_16 -> V_77 ) )
break;
V_4 = F_38 () ;
}
#ifdef F_17
if ( V_47 ) {
V_16 -> V_78 = V_79 ;
V_55 = 1 ;
}
#endif
}
void F_151 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_152
if ( V_16 -> V_77 . V_105 )
F_103 ( & V_16 -> V_77 ) ;
# endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
void F_153 ( void )
{
int V_2 ;
F_154 (cpu)
F_155 ( 0 , & F_2 ( V_3 , V_2 ) . V_106 ) ;
}
void F_156 ( void )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
F_155 ( 0 , & V_16 -> V_106 ) ;
}
int F_157 ( int V_107 )
{
struct V_1 * V_16 = & F_36 ( V_3 ) ;
if ( ! F_158 ( 0 , & V_16 -> V_106 ) )
return 0 ;
if ( V_16 -> V_78 != V_83 )
return 0 ;
if ( ! F_159 () || ! F_160 () )
return 0 ;
if ( ! V_107 )
return 1 ;
F_136 () ;
return 0 ;
}
