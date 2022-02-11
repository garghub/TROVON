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
struct V_1 * V_16 = F_36 ( & V_3 ) ;
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
F_41 ( F_36 ( & V_26 ) ) ;
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
F_54 ( & V_28 ) ;
if ( F_55 ( V_33 , V_28 ) < 0 ) {
F_56 ( L_6 ) ;
F_57 ( V_28 ) ;
return 1 ;
}
V_23 = true ;
return 1 ;
}
static int F_58 ( struct V_34 * V_35 ,
unsigned long V_36 ,
void * V_37 )
{
unsigned int V_2 = ( unsigned long ) V_37 ;
switch ( V_36 & ~ V_38 ) {
case V_39 :
if ( V_23 && V_14 == V_2 )
return V_40 ;
break;
}
return V_41 ;
}
static int F_59 ( void )
{
int V_42 = - 1 ;
#ifdef F_60
if ( ! F_61 ( & V_28 , V_43 ) ) {
F_62 ( 1 , L_7 ) ;
return V_42 ;
}
V_42 = 0 ;
F_63 ( V_28 ) ;
V_23 = true ;
#endif
return V_42 ;
}
void T_3 F_64 ( void )
{
int V_2 ;
if ( ! V_23 ) {
if ( F_59 () < 0 )
return;
}
if ( ! F_61 ( & V_44 , V_43 ) ) {
F_62 ( 1 , L_8 ) ;
F_65 ( V_28 ) ;
V_23 = false ;
return;
}
if ( ! F_66 () ) {
F_56 ( L_9
L_10 ) ;
F_65 ( V_28 ) ;
F_67 ( V_44 , V_45 ) ;
V_23 = false ;
return;
}
V_2 = F_16 () ;
if ( F_68 ( V_2 , V_28 ) ) {
F_56 ( L_11 , V_2 ) ;
F_69 ( V_2 , V_28 ) ;
}
F_70 ( V_44 ,
V_45 , V_28 ) ;
F_71 (cpu, tick_nohz_full_mask)
F_72 ( V_2 ) ;
F_73 ( F_58 , 0 ) ;
F_74 ( V_46 , sizeof( V_46 ) , V_28 ) ;
F_75 ( L_12 , V_46 ) ;
}
static int T_3 F_76 ( char * V_33 )
{
if ( ! strcmp ( V_33 , L_13 ) )
V_47 = 0 ;
else if ( ! strcmp ( V_33 , L_14 ) )
V_47 = 1 ;
else
return 0 ;
return 1 ;
}
static void F_77 ( T_1 V_4 )
{
unsigned long V_31 ;
F_78 ( V_3 . V_48 , V_4 ) ;
F_50 ( V_31 ) ;
F_3 ( V_4 ) ;
F_52 ( V_31 ) ;
F_20 () ;
}
static void
F_79 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_49 )
{
T_1 V_6 ;
if ( V_16 -> V_50 ) {
V_6 = F_4 ( V_4 , V_16 -> V_51 ) ;
if ( F_80 ( V_2 ) > 0 )
V_16 -> V_52 = F_6 ( V_16 -> V_52 , V_6 ) ;
else
V_16 -> V_53 = F_6 ( V_16 -> V_53 , V_6 ) ;
V_16 -> V_51 = V_4 ;
}
if ( V_49 )
* V_49 = F_81 ( V_4 ) ;
}
static void F_82 ( struct V_1 * V_16 , T_1 V_4 )
{
F_79 ( F_16 () , V_16 , V_4 , NULL ) ;
V_16 -> V_50 = 0 ;
F_83 ( 0 ) ;
}
static T_1 F_84 ( struct V_1 * V_16 )
{
T_1 V_4 = F_38 () ;
V_16 -> V_51 = V_4 ;
V_16 -> V_50 = 1 ;
F_85 () ;
return V_4 ;
}
T_4 F_86 ( int V_2 , T_4 * V_49 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_54 ;
if ( ! V_55 )
return - 1 ;
V_4 = F_38 () ;
if ( V_49 ) {
F_79 ( V_2 , V_16 , V_4 , V_49 ) ;
V_54 = V_16 -> V_53 ;
} else {
if ( V_16 -> V_50 && ! F_80 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_51 ) ;
V_54 = F_6 ( V_16 -> V_53 , V_6 ) ;
} else {
V_54 = V_16 -> V_53 ;
}
}
return F_81 ( V_54 ) ;
}
T_4 F_87 ( int V_2 , T_4 * V_49 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_56 ;
if ( ! V_55 )
return - 1 ;
V_4 = F_38 () ;
if ( V_49 ) {
F_79 ( V_2 , V_16 , V_4 , V_49 ) ;
V_56 = V_16 -> V_52 ;
} else {
if ( V_16 -> V_50 && F_80 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_51 ) ;
V_56 = F_6 ( V_16 -> V_52 , V_6 ) ;
} else {
V_56 = V_16 -> V_52 ;
}
}
return F_81 ( V_56 ) ;
}
static T_1 F_88 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
unsigned long V_57 , V_58 , V_59 , V_60 ;
T_1 V_61 , V_62 , V_63 = { . V_8 = 0 } ;
unsigned long V_64 ;
struct V_65 * V_66 = F_89 ( V_67 . V_68 ) ;
T_4 V_69 ;
V_69 = F_90 () ;
do {
V_57 = F_91 ( & V_10 ) ;
V_61 = V_7 ;
V_58 = V_70 ;
} while ( F_92 ( & V_10 , V_57 ) );
if ( F_93 ( & V_64 ) ||
F_94 () || F_95 () ) {
V_59 = V_58 + 1 ;
V_60 = 1 ;
} else {
V_59 = F_96 ( V_58 ) ;
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
#ifdef F_97
if ( ! V_16 -> V_73 ) {
V_69 = F_98 ( V_69 ,
F_99 () ) ;
}
#endif
if ( F_100 ( V_60 < V_74 ) ) {
V_69 = F_101 ( T_4 , V_69 ,
V_9 . V_8 * V_60 ) ;
}
if ( V_69 < V_72 )
V_62 = F_10 ( V_61 , V_69 ) ;
else
V_62 . V_8 = V_72 ;
if ( V_16 -> V_19 && F_102 ( V_62 , V_66 -> V_75 ) )
goto V_32;
V_63 = V_62 ;
if ( ! V_16 -> V_19 ) {
F_103 ( V_2 ) ;
F_104 () ;
V_16 -> V_76 = F_105 ( & V_16 -> V_77 ) ;
V_16 -> V_19 = 1 ;
F_29 ( 1 , L_15 ) ;
}
if ( F_7 ( V_62 . V_8 == V_72 ) ) {
if ( V_16 -> V_78 == V_79 )
F_106 ( & V_16 -> V_77 ) ;
goto V_32;
}
if ( V_16 -> V_78 == V_79 ) {
F_107 ( & V_16 -> V_77 , V_62 ,
V_80 ) ;
if ( F_108 ( & V_16 -> V_77 ) )
goto V_32;
} else if ( ! F_109 ( V_62 , 0 ) )
goto V_32;
F_3 ( F_38 () ) ;
}
F_110 ( V_81 ) ;
V_32:
V_16 -> V_59 = V_59 ;
V_16 -> V_58 = V_58 ;
V_16 -> V_82 = F_4 ( V_66 -> V_75 , V_4 ) ;
return V_63 ;
}
static void F_111 ( struct V_1 * V_16 )
{
#ifdef F_97
int V_2 = F_16 () ;
if ( ! F_18 ( V_2 ) || F_21 ( V_20 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_78 == V_83 )
return;
if ( ! F_25 () )
return;
F_88 ( V_16 , F_38 () , V_2 ) ;
#endif
}
static bool F_112 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_113 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_78 == V_83 ) ) {
V_16 -> V_82 = ( T_1 ) { . V_8 = V_84 / V_85 } ;
return false ;
}
if ( F_114 () )
return false ;
if ( F_7 ( F_115 () && F_113 ( V_2 ) ) ) {
static int V_86 ;
if ( V_86 < 10 &&
( F_115 () & V_87 ) ) {
F_116 ( L_16 ,
( unsigned int ) F_115 () ) ;
V_86 ++ ;
}
return false ;
}
if ( F_117 () ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_118 ( struct V_1 * V_16 )
{
T_1 V_4 , V_62 ;
int V_2 = F_16 () ;
V_4 = F_84 ( V_16 ) ;
if ( F_112 ( V_2 , V_16 ) ) {
int V_88 = V_16 -> V_19 ;
V_16 -> V_89 ++ ;
V_62 = F_88 ( V_16 , V_4 , V_2 ) ;
if ( V_62 . V_8 > 0LL ) {
V_16 -> V_90 ++ ;
V_16 -> V_91 = V_62 ;
}
if ( ! V_88 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_58 ;
}
}
void F_119 ( void )
{
struct V_1 * V_16 ;
F_26 ( F_27 () ) ;
F_120 () ;
F_121 () ;
V_16 = F_36 ( & V_3 ) ;
V_16 -> V_73 = 1 ;
F_118 ( V_16 ) ;
F_122 () ;
}
void F_123 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
if ( V_16 -> V_73 )
F_118 ( V_16 ) ;
else
F_111 ( V_16 ) ;
}
T_1 F_124 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
return V_16 -> V_82 ;
}
static void F_125 ( struct V_1 * V_16 , T_1 V_4 )
{
F_106 ( & V_16 -> V_77 ) ;
F_126 ( & V_16 -> V_77 , V_16 -> V_76 ) ;
while ( 1 ) {
F_127 ( & V_16 -> V_77 , V_4 , V_9 ) ;
if ( V_16 -> V_78 == V_79 ) {
F_128 ( & V_16 -> V_77 ,
V_80 ) ;
if ( F_108 ( & V_16 -> V_77 ) )
break;
} else {
if ( ! F_109 (
F_105 ( & V_16 -> V_77 ) , 0 ) )
break;
}
V_4 = F_38 () ;
F_3 ( V_4 ) ;
}
}
static void F_37 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_129 () ;
F_130 () ;
F_20 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_92 = V_4 ;
F_125 ( V_16 , V_4 ) ;
}
static void F_131 ( struct V_1 * V_16 )
{
#ifndef F_132
unsigned long V_5 ;
if ( F_133 () )
return;
V_5 = V_70 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_93 )
F_134 ( V_5 ) ;
#endif
}
void F_135 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
T_1 V_4 ;
F_121 () ;
F_26 ( ! V_16 -> V_73 ) ;
V_16 -> V_73 = 0 ;
if ( V_16 -> V_50 || V_16 -> V_19 )
V_4 = F_38 () ;
if ( V_16 -> V_50 )
F_82 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_37 ( V_16 , V_4 ) ;
F_131 ( V_16 ) ;
}
F_122 () ;
}
static int F_136 ( struct V_1 * V_16 , T_1 V_4 )
{
F_127 ( & V_16 -> V_77 , V_4 , V_9 ) ;
return F_109 ( F_105 ( & V_16 -> V_77 ) , 0 ) ;
}
static void F_137 ( struct V_65 * V_66 )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
struct V_17 * V_18 = F_138 () ;
T_1 V_4 = F_38 () ;
V_66 -> V_75 . V_8 = V_72 ;
F_15 ( V_4 ) ;
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return;
while ( F_136 ( V_16 , V_4 ) ) {
V_4 = F_38 () ;
F_3 ( V_4 ) ;
}
}
static void F_139 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
T_1 V_94 ;
if ( ! V_47 )
return;
F_121 () ;
if ( F_140 ( F_137 ) ) {
F_122 () ;
return;
}
V_55 = 1 ;
V_16 -> V_78 = V_95 ;
F_141 ( & V_16 -> V_77 , V_96 , V_97 ) ;
V_94 = F_14 () ;
for (; ; ) {
F_126 ( & V_16 -> V_77 , V_94 ) ;
if ( ! F_109 ( V_94 , 0 ) )
break;
V_94 = F_6 ( V_94 , V_9 ) ;
}
F_122 () ;
}
static void F_142 ( struct V_1 * V_16 , T_1 V_4 )
{
#if 0
ktime_t delta;
delta = ktime_sub(hrtimer_get_expires(&ts->sched_timer), now);
if (delta.tv64 <= tick_period.tv64)
return;
tick_nohz_restart(ts, now);
#endif
}
static inline void F_143 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_50 && ! V_16 -> V_19 )
return;
V_4 = F_38 () ;
if ( V_16 -> V_50 )
F_82 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_77 ( V_4 ) ;
F_142 ( V_16 , V_4 ) ;
}
}
static inline void F_139 ( void ) { }
static inline void F_143 ( void ) { }
void F_144 ( void )
{
F_145 () ;
F_143 () ;
}
static enum V_98 F_146 ( struct V_99 * V_100 )
{
struct V_1 * V_16 =
F_147 ( V_100 , struct V_1 , V_77 ) ;
struct V_17 * V_18 = F_138 () ;
T_1 V_4 = F_38 () ;
F_15 ( V_4 ) ;
if ( V_18 )
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return V_101 ;
F_127 ( V_100 , V_4 , V_9 ) ;
return V_102 ;
}
static int T_3 F_148 ( char * V_33 )
{
F_149 ( & V_33 , & V_103 ) ;
return 0 ;
}
void F_150 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
T_1 V_4 = F_38 () ;
F_141 ( & V_16 -> V_77 , V_96 , V_97 ) ;
V_16 -> V_77 . V_104 = F_146 ;
F_126 ( & V_16 -> V_77 , F_14 () ) ;
if ( V_103 ) {
T_4 V_105 = F_8 ( V_9 ) >> 1 ;
F_151 ( V_105 , F_152 () ) ;
V_105 *= F_16 () ;
F_153 ( & V_16 -> V_77 , V_105 ) ;
}
for (; ; ) {
F_127 ( & V_16 -> V_77 , V_4 , V_9 ) ;
F_128 ( & V_16 -> V_77 ,
V_80 ) ;
if ( F_108 ( & V_16 -> V_77 ) )
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
void F_154 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_155
if ( V_16 -> V_77 . V_106 )
F_106 ( & V_16 -> V_77 ) ;
# endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
void F_156 ( void )
{
int V_2 ;
F_157 (cpu)
F_158 ( 0 , & F_2 ( V_3 , V_2 ) . V_107 ) ;
}
void F_159 ( void )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
F_158 ( 0 , & V_16 -> V_107 ) ;
}
int F_160 ( int V_108 )
{
struct V_1 * V_16 = F_36 ( & V_3 ) ;
if ( ! F_161 ( 0 , & V_16 -> V_107 ) )
return 0 ;
if ( V_16 -> V_78 != V_83 )
return 0 ;
if ( ! F_162 () || ! F_163 () )
return 0 ;
if ( ! V_108 )
return 1 ;
F_139 () ;
return 0 ;
}
