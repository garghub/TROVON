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
static bool F_25 ( T_3 * V_23 )
{
int V_24 = F_26 ( V_23 ) ;
if ( V_24 & V_25 ) {
F_27 ( 0 , V_25 ) ;
return true ;
}
if ( V_24 & V_26 ) {
F_27 ( 0 , V_26 ) ;
return true ;
}
if ( V_24 & V_27 ) {
F_27 ( 0 , V_27 ) ;
return true ;
}
if ( V_24 & V_28 ) {
F_27 ( 0 , V_28 ) ;
return true ;
}
return false ;
}
static bool F_28 ( struct V_1 * V_16 )
{
F_29 ( ! F_30 () ) ;
if ( F_25 ( & V_29 ) )
return false ;
if ( F_25 ( & V_16 -> V_29 ) )
return false ;
if ( F_25 ( & V_20 -> V_29 ) )
return false ;
if ( F_25 ( & V_20 -> signal -> V_29 ) )
return false ;
return true ;
}
static void F_31 ( struct V_30 * V_31 )
{
}
static void F_32 ( void )
{
if ( ! F_18 ( F_16 () ) )
return;
F_33 ( F_34 ( & V_32 ) ) ;
}
void F_35 ( int V_2 )
{
if ( ! F_18 ( V_2 ) )
return;
F_36 ( & F_2 ( V_32 , V_2 ) , V_2 ) ;
}
static void F_37 ( void )
{
int V_2 ;
if ( ! V_33 )
return;
F_38 () ;
F_39 (cpu, tick_nohz_full_mask, cpu_online_mask)
F_35 ( V_2 ) ;
F_40 () ;
}
static void F_41 ( T_3 * V_23 ,
enum V_34 V_35 )
{
int V_36 ;
V_36 = F_42 ( F_43 ( V_35 ) , V_23 ) ;
if ( ! V_36 )
F_37 () ;
}
void F_44 ( enum V_34 V_35 )
{
F_41 ( & V_29 , V_35 ) ;
}
void F_45 ( enum V_34 V_35 )
{
F_46 ( F_43 ( V_35 ) , & V_29 ) ;
}
void F_47 ( int V_2 , enum V_34 V_35 )
{
int V_36 ;
struct V_1 * V_16 ;
V_16 = F_48 ( & V_3 , V_2 ) ;
V_36 = F_42 ( F_43 ( V_35 ) , & V_16 -> V_29 ) ;
if ( ! V_36 ) {
F_38 () ;
if ( V_2 == F_16 () ) {
F_32 () ;
} else {
if ( ! F_29 ( F_49 () ) )
F_35 ( V_2 ) ;
}
F_40 () ;
}
}
void F_50 ( int V_2 , enum V_34 V_35 )
{
struct V_1 * V_16 = F_48 ( & V_3 , V_2 ) ;
F_46 ( F_43 ( V_35 ) , & V_16 -> V_29 ) ;
}
void F_51 ( struct V_37 * V_38 , enum V_34 V_35 )
{
F_41 ( & V_38 -> V_29 , V_35 ) ;
}
void F_52 ( struct V_37 * V_38 , enum V_34 V_35 )
{
F_46 ( F_43 ( V_35 ) , & V_38 -> V_29 ) ;
}
void F_53 ( struct V_39 * V_40 , enum V_34 V_35 )
{
F_41 ( & V_40 -> V_29 , V_35 ) ;
}
void F_54 ( struct V_39 * V_40 , enum V_34 V_35 )
{
F_46 ( F_43 ( V_35 ) , & V_40 -> V_29 ) ;
}
void F_55 ( void )
{
unsigned long V_41 ;
struct V_1 * V_16 ;
F_56 ( V_41 ) ;
if ( ! F_18 ( F_16 () ) )
goto V_42;
V_16 = F_34 ( & V_3 ) ;
if ( V_16 -> V_19 ) {
if ( F_26 ( & V_20 -> V_29 ) ||
F_26 ( & V_20 -> signal -> V_29 ) )
F_32 () ;
}
V_42:
F_57 ( V_41 ) ;
}
static int T_4 F_58 ( char * V_43 )
{
F_59 ( & V_44 ) ;
if ( F_60 ( V_43 , V_44 ) < 0 ) {
F_61 ( L_1 ) ;
F_62 ( V_44 ) ;
return 1 ;
}
V_33 = true ;
return 1 ;
}
static int F_63 ( struct V_45 * V_46 ,
unsigned long V_47 ,
void * V_48 )
{
unsigned int V_2 = ( unsigned long ) V_48 ;
switch ( V_47 & ~ V_49 ) {
case V_50 :
if ( V_33 && V_14 == V_2 )
return V_51 ;
break;
}
return V_52 ;
}
static int F_64 ( void )
{
int V_53 = - 1 ;
#ifdef F_65
if ( ! F_66 ( & V_44 , V_54 ) ) {
F_67 ( 1 , L_2 ) ;
return V_53 ;
}
V_53 = 0 ;
F_68 ( V_44 ) ;
V_33 = true ;
#endif
return V_53 ;
}
void T_4 F_69 ( void )
{
int V_2 ;
if ( ! V_33 ) {
if ( F_64 () < 0 )
return;
}
if ( ! F_66 ( & V_55 , V_54 ) ) {
F_67 ( 1 , L_3 ) ;
F_70 ( V_44 ) ;
V_33 = false ;
return;
}
if ( ! F_71 () ) {
F_61 ( L_4 ) ;
F_70 ( V_44 ) ;
F_72 ( V_55 , V_56 ) ;
V_33 = false ;
return;
}
V_2 = F_16 () ;
if ( F_73 ( V_2 , V_44 ) ) {
F_61 ( L_5 ,
V_2 ) ;
F_74 ( V_2 , V_44 ) ;
}
F_75 ( V_55 ,
V_56 , V_44 ) ;
F_76 (cpu, tick_nohz_full_mask)
F_77 ( V_2 ) ;
F_78 ( F_63 , 0 ) ;
F_79 ( L_6 ,
F_80 ( V_44 ) ) ;
F_29 ( F_81 ( V_55 ) ) ;
}
static int T_4 F_82 ( char * V_43 )
{
return ( F_83 ( V_43 , & V_57 ) == 0 ) ;
}
int F_84 ( void )
{
return F_85 ( V_3 . V_19 ) ;
}
static void F_86 ( T_1 V_4 )
{
unsigned long V_41 ;
F_87 ( V_3 . V_58 , V_4 ) ;
F_56 ( V_41 ) ;
F_3 ( V_4 ) ;
F_57 ( V_41 ) ;
F_20 () ;
}
static void
F_88 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_5 * V_59 )
{
T_1 V_6 ;
if ( V_16 -> V_60 ) {
V_6 = F_4 ( V_4 , V_16 -> V_61 ) ;
if ( F_89 ( V_2 ) > 0 )
V_16 -> V_62 = F_6 ( V_16 -> V_62 , V_6 ) ;
else
V_16 -> V_63 = F_6 ( V_16 -> V_63 , V_6 ) ;
V_16 -> V_61 = V_4 ;
}
if ( V_59 )
* V_59 = F_90 ( V_4 ) ;
}
static void F_91 ( struct V_1 * V_16 , T_1 V_4 )
{
F_88 ( F_16 () , V_16 , V_4 , NULL ) ;
V_16 -> V_60 = 0 ;
F_92 ( 0 ) ;
}
static T_1 F_93 ( struct V_1 * V_16 )
{
T_1 V_4 = F_94 () ;
V_16 -> V_61 = V_4 ;
V_16 -> V_60 = 1 ;
F_95 () ;
return V_4 ;
}
T_5 F_96 ( int V_2 , T_5 * V_59 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_64 ;
if ( ! V_65 )
return - 1 ;
V_4 = F_94 () ;
if ( V_59 ) {
F_88 ( V_2 , V_16 , V_4 , V_59 ) ;
V_64 = V_16 -> V_63 ;
} else {
if ( V_16 -> V_60 && ! F_89 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_61 ) ;
V_64 = F_6 ( V_16 -> V_63 , V_6 ) ;
} else {
V_64 = V_16 -> V_63 ;
}
}
return F_90 ( V_64 ) ;
}
T_5 F_97 ( int V_2 , T_5 * V_59 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_66 ;
if ( ! V_65 )
return - 1 ;
V_4 = F_94 () ;
if ( V_59 ) {
F_88 ( V_2 , V_16 , V_4 , V_59 ) ;
V_66 = V_16 -> V_62 ;
} else {
if ( V_16 -> V_60 && F_89 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_61 ) ;
V_66 = F_6 ( V_16 -> V_62 , V_6 ) ;
} else {
V_66 = V_16 -> V_62 ;
}
}
return F_90 ( V_66 ) ;
}
static void F_98 ( struct V_1 * V_16 , T_1 V_4 )
{
F_99 ( & V_16 -> V_67 ) ;
F_100 ( & V_16 -> V_67 , V_16 -> V_68 ) ;
F_101 ( & V_16 -> V_67 , V_4 , V_9 ) ;
if ( V_16 -> V_69 == V_70 )
F_102 ( & V_16 -> V_67 , V_71 ) ;
else
F_103 ( F_104 ( & V_16 -> V_67 ) , 1 ) ;
}
static T_1 F_105 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
struct V_72 * V_73 = F_85 ( V_74 . V_75 ) ;
T_5 V_76 , V_77 , V_78 , V_79 , V_6 , V_80 ;
unsigned long V_81 , V_82 ;
T_1 V_83 ;
do {
V_81 = F_106 ( & V_10 ) ;
V_76 = V_7 . V_8 ;
V_82 = V_84 ;
} while ( F_107 ( & V_10 , V_81 ) );
V_16 -> V_85 = V_82 ;
if ( F_108 ( V_76 , & V_79 ) ||
F_109 () || F_110 () ) {
V_77 = V_76 + V_86 ;
} else {
V_78 = F_111 ( V_82 , V_76 ) ;
V_16 -> V_87 = V_78 ;
V_77 = V_79 < V_78 ? V_79 : V_78 ;
}
V_6 = V_77 - V_76 ;
if ( V_6 <= ( T_5 ) V_86 ) {
V_83 . V_8 = 0 ;
if ( ! V_16 -> V_19 )
goto V_42;
if ( V_6 == 0 ) {
F_98 ( V_16 , V_4 ) ;
goto V_42;
}
}
V_6 = F_112 () ;
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_88 = 1 ;
} else if ( V_14 != V_15 ) {
V_6 = V_89 ;
V_16 -> V_88 = 0 ;
} else if ( ! V_16 -> V_88 ) {
V_6 = V_89 ;
}
#ifdef F_113
if ( ! V_16 -> V_90 )
V_6 = F_114 ( V_6 , F_115 () ) ;
#endif
if ( V_6 < ( V_89 - V_76 ) )
V_80 = V_76 + V_6 ;
else
V_80 = V_89 ;
V_80 = F_116 ( T_5 , V_80 , V_77 ) ;
V_83 . V_8 = V_80 ;
if ( V_16 -> V_19 && ( V_80 == V_73 -> V_91 . V_8 ) )
goto V_42;
if ( ! V_16 -> V_19 ) {
F_117 ( V_2 ) ;
F_118 () ;
F_119 () ;
V_16 -> V_68 = F_104 ( & V_16 -> V_67 ) ;
V_16 -> V_19 = 1 ;
F_27 ( 1 , V_92 ) ;
}
if ( F_7 ( V_80 == V_89 ) ) {
if ( V_16 -> V_69 == V_70 )
F_99 ( & V_16 -> V_67 ) ;
goto V_42;
}
if ( V_16 -> V_69 == V_70 )
F_120 ( & V_16 -> V_67 , V_83 , V_71 ) ;
else
F_103 ( V_83 , 1 ) ;
V_42:
V_16 -> V_93 = F_4 ( V_73 -> V_91 , V_4 ) ;
return V_83 ;
}
static void F_121 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_122 () ;
F_123 () ;
F_20 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_94 = V_4 ;
F_98 ( V_16 , V_4 ) ;
}
static void F_124 ( struct V_1 * V_16 )
{
#ifdef F_113
int V_2 = F_16 () ;
if ( ! F_18 ( V_2 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_69 == V_95 )
return;
if ( F_28 ( V_16 ) )
F_105 ( V_16 , F_94 () , V_2 ) ;
else if ( V_16 -> V_19 )
F_121 ( V_16 , F_94 () ) ;
#endif
}
static bool F_125 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_126 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_69 == V_95 ) ) {
V_16 -> V_93 = ( T_1 ) { . V_8 = V_96 / V_97 } ;
return false ;
}
if ( F_127 () )
return false ;
if ( F_7 ( F_128 () && F_126 ( V_2 ) ) ) {
static int V_98 ;
if ( V_98 < 10 &&
( F_128 () & V_99 ) ) {
F_61 ( L_7 ,
( unsigned int ) F_128 () ) ;
V_98 ++ ;
}
return false ;
}
if ( F_129 () ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_130 ( struct V_1 * V_16 )
{
T_1 V_4 , V_80 ;
int V_2 = F_16 () ;
V_4 = F_93 ( V_16 ) ;
if ( F_125 ( V_2 , V_16 ) ) {
int V_100 = V_16 -> V_19 ;
V_16 -> V_101 ++ ;
V_80 = F_105 ( V_16 , V_4 , V_2 ) ;
if ( V_80 . V_8 > 0LL ) {
V_16 -> V_102 ++ ;
V_16 -> V_103 = V_80 ;
}
if ( ! V_100 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_85 ;
}
}
void F_131 ( void )
{
struct V_1 * V_16 ;
F_29 ( F_30 () ) ;
F_132 () ;
F_133 () ;
V_16 = F_34 ( & V_3 ) ;
V_16 -> V_90 = 1 ;
F_130 ( V_16 ) ;
F_134 () ;
}
void F_135 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
if ( V_16 -> V_90 )
F_130 ( V_16 ) ;
else
F_124 ( V_16 ) ;
}
T_1 F_136 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
return V_16 -> V_93 ;
}
static void F_137 ( struct V_1 * V_16 )
{
#ifndef F_138
unsigned long V_5 ;
if ( F_139 () )
return;
V_5 = V_84 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_104 )
F_140 ( V_5 ) ;
#endif
}
void F_141 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
T_1 V_4 ;
F_133 () ;
F_29 ( ! V_16 -> V_90 ) ;
V_16 -> V_90 = 0 ;
if ( V_16 -> V_60 || V_16 -> V_19 )
V_4 = F_94 () ;
if ( V_16 -> V_60 )
F_91 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_121 ( V_16 , V_4 ) ;
F_137 ( V_16 ) ;
}
F_134 () ;
}
static void F_142 ( struct V_72 * V_73 )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
struct V_17 * V_18 = F_143 () ;
T_1 V_4 = F_94 () ;
V_73 -> V_91 . V_8 = V_89 ;
F_15 ( V_4 ) ;
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return;
F_101 ( & V_16 -> V_67 , V_4 , V_9 ) ;
F_103 ( F_104 ( & V_16 -> V_67 ) , 1 ) ;
}
static inline void F_144 ( struct V_1 * V_16 , int V_105 )
{
if ( ! V_57 )
return;
V_16 -> V_69 = V_105 ;
if ( ! F_145 ( 0 , & V_65 ) )
F_146 ( true ) ;
}
static void F_147 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
T_1 V_106 ;
if ( ! V_57 )
return;
if ( F_148 ( F_142 ) )
return;
F_149 ( & V_16 -> V_67 , V_107 , V_108 ) ;
V_106 = F_14 () ;
F_100 ( & V_16 -> V_67 , V_106 ) ;
F_150 ( & V_16 -> V_67 , V_9 ) ;
F_103 ( F_104 ( & V_16 -> V_67 ) , 1 ) ;
F_144 ( V_16 , V_109 ) ;
}
static void F_151 ( struct V_1 * V_16 , T_1 V_4 )
{
#if 0
ktime_t delta;
delta = ktime_sub(hrtimer_get_expires(&ts->sched_timer), now);
if (delta.tv64 <= tick_period.tv64)
return;
tick_nohz_restart(ts, now);
#endif
}
static inline void F_152 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_60 && ! V_16 -> V_19 )
return;
V_4 = F_94 () ;
if ( V_16 -> V_60 )
F_91 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_86 ( V_4 ) ;
F_151 ( V_16 , V_4 ) ;
}
}
static inline void F_147 ( void ) { }
static inline void F_152 ( void ) { }
static inline void F_144 ( struct V_1 * V_16 , int V_105 ) { }
void F_153 ( void )
{
F_154 () ;
F_152 () ;
}
static enum V_110 F_155 ( struct V_111 * V_112 )
{
struct V_1 * V_16 =
F_156 ( V_112 , struct V_1 , V_67 ) ;
struct V_17 * V_18 = F_143 () ;
T_1 V_4 = F_94 () ;
F_15 ( V_4 ) ;
if ( V_18 )
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return V_113 ;
F_101 ( V_112 , V_4 , V_9 ) ;
return V_114 ;
}
static int T_4 F_157 ( char * V_43 )
{
F_158 ( & V_43 , & V_115 ) ;
return 0 ;
}
void F_159 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
T_1 V_4 = F_94 () ;
F_149 ( & V_16 -> V_67 , V_107 , V_108 ) ;
V_16 -> V_67 . V_116 = F_155 ;
F_100 ( & V_16 -> V_67 , F_14 () ) ;
if ( V_115 ) {
T_5 V_117 = F_8 ( V_9 ) >> 1 ;
F_160 ( V_117 , F_161 () ) ;
V_117 *= F_16 () ;
F_162 ( & V_16 -> V_67 , V_117 ) ;
}
F_101 ( & V_16 -> V_67 , V_4 , V_9 ) ;
F_102 ( & V_16 -> V_67 , V_71 ) ;
F_144 ( V_16 , V_70 ) ;
}
void F_163 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_164
if ( V_16 -> V_67 . V_118 )
F_99 ( & V_16 -> V_67 ) ;
# endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
void F_165 ( void )
{
int V_2 ;
F_166 (cpu)
F_167 ( 0 , & F_2 ( V_3 , V_2 ) . V_119 ) ;
}
void F_168 ( void )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
F_167 ( 0 , & V_16 -> V_119 ) ;
}
int F_169 ( int V_120 )
{
struct V_1 * V_16 = F_34 ( & V_3 ) ;
if ( ! F_170 ( 0 , & V_16 -> V_119 ) )
return 0 ;
if ( V_16 -> V_69 != V_95 )
return 0 ;
if ( ! F_171 () || ! F_172 () )
return 0 ;
if ( ! V_120 )
return 1 ;
F_147 () ;
return 0 ;
}
