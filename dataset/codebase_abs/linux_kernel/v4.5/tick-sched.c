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
static void F_35 ( struct V_24 * V_25 )
{
}
void F_36 ( void )
{
if ( ! F_18 ( F_16 () ) )
return;
F_37 ( F_38 ( & V_26 ) ) ;
}
void F_39 ( int V_2 )
{
if ( ! F_18 ( V_2 ) )
return;
F_40 ( & F_2 ( V_26 , V_2 ) , V_2 ) ;
}
static void F_41 ( void * V_27 )
{
}
void F_42 ( void )
{
if ( ! V_23 )
return;
F_43 () ;
F_44 ( V_28 ,
F_41 , NULL , false ) ;
F_36 () ;
F_45 () ;
}
void F_46 ( void )
{
unsigned long V_29 ;
F_47 ( V_29 ) ;
if ( ! F_18 ( F_16 () ) )
goto V_30;
if ( F_48 () && ! F_25 () )
F_36 () ;
V_30:
F_49 ( V_29 ) ;
}
static int T_3 F_50 ( char * V_31 )
{
F_51 ( & V_28 ) ;
if ( F_52 ( V_31 , V_28 ) < 0 ) {
F_53 ( L_6 ) ;
F_54 ( V_28 ) ;
return 1 ;
}
V_23 = true ;
return 1 ;
}
static int F_55 ( struct V_32 * V_33 ,
unsigned long V_34 ,
void * V_35 )
{
unsigned int V_2 = ( unsigned long ) V_35 ;
switch ( V_34 & ~ V_36 ) {
case V_37 :
if ( V_23 && V_14 == V_2 )
return V_38 ;
break;
}
return V_39 ;
}
static int F_56 ( void )
{
int V_40 = - 1 ;
#ifdef F_57
if ( ! F_58 ( & V_28 , V_41 ) ) {
F_59 ( 1 , L_7 ) ;
return V_40 ;
}
V_40 = 0 ;
F_60 ( V_28 ) ;
V_23 = true ;
#endif
return V_40 ;
}
void T_3 F_61 ( void )
{
int V_2 ;
if ( ! V_23 ) {
if ( F_56 () < 0 )
return;
}
if ( ! F_58 ( & V_42 , V_41 ) ) {
F_59 ( 1 , L_8 ) ;
F_62 ( V_28 ) ;
V_23 = false ;
return;
}
if ( ! F_63 () ) {
F_53 ( L_9
L_10 ) ;
F_62 ( V_28 ) ;
F_64 ( V_42 , V_43 ) ;
V_23 = false ;
return;
}
V_2 = F_16 () ;
if ( F_65 ( V_2 , V_28 ) ) {
F_53 ( L_11 , V_2 ) ;
F_66 ( V_2 , V_28 ) ;
}
F_67 ( V_42 ,
V_43 , V_28 ) ;
F_68 (cpu, tick_nohz_full_mask)
F_69 ( V_2 ) ;
F_70 ( F_55 , 0 ) ;
F_71 ( L_12 ,
F_72 ( V_28 ) ) ;
F_26 ( F_73 ( V_42 ) ) ;
}
static int T_3 F_74 ( char * V_31 )
{
if ( ! strcmp ( V_31 , L_13 ) )
V_44 = 0 ;
else if ( ! strcmp ( V_31 , L_14 ) )
V_44 = 1 ;
else
return 0 ;
return 1 ;
}
int F_48 ( void )
{
return F_75 ( V_3 . V_19 ) ;
}
static void F_76 ( T_1 V_4 )
{
unsigned long V_29 ;
F_77 ( V_3 . V_45 , V_4 ) ;
F_47 ( V_29 ) ;
F_3 ( V_4 ) ;
F_49 ( V_29 ) ;
F_20 () ;
}
static void
F_78 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_4 * V_46 )
{
T_1 V_6 ;
if ( V_16 -> V_47 ) {
V_6 = F_4 ( V_4 , V_16 -> V_48 ) ;
if ( F_79 ( V_2 ) > 0 )
V_16 -> V_49 = F_6 ( V_16 -> V_49 , V_6 ) ;
else
V_16 -> V_50 = F_6 ( V_16 -> V_50 , V_6 ) ;
V_16 -> V_48 = V_4 ;
}
if ( V_46 )
* V_46 = F_80 ( V_4 ) ;
}
static void F_81 ( struct V_1 * V_16 , T_1 V_4 )
{
F_78 ( F_16 () , V_16 , V_4 , NULL ) ;
V_16 -> V_47 = 0 ;
F_82 ( 0 ) ;
}
static T_1 F_83 ( struct V_1 * V_16 )
{
T_1 V_4 = F_84 () ;
V_16 -> V_48 = V_4 ;
V_16 -> V_47 = 1 ;
F_85 () ;
return V_4 ;
}
T_4 F_86 ( int V_2 , T_4 * V_46 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_51 ;
if ( ! V_52 )
return - 1 ;
V_4 = F_84 () ;
if ( V_46 ) {
F_78 ( V_2 , V_16 , V_4 , V_46 ) ;
V_51 = V_16 -> V_50 ;
} else {
if ( V_16 -> V_47 && ! F_79 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_48 ) ;
V_51 = F_6 ( V_16 -> V_50 , V_6 ) ;
} else {
V_51 = V_16 -> V_50 ;
}
}
return F_80 ( V_51 ) ;
}
T_4 F_87 ( int V_2 , T_4 * V_46 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_53 ;
if ( ! V_52 )
return - 1 ;
V_4 = F_84 () ;
if ( V_46 ) {
F_78 ( V_2 , V_16 , V_4 , V_46 ) ;
V_53 = V_16 -> V_49 ;
} else {
if ( V_16 -> V_47 && F_79 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_48 ) ;
V_53 = F_6 ( V_16 -> V_49 , V_6 ) ;
} else {
V_53 = V_16 -> V_49 ;
}
}
return F_80 ( V_53 ) ;
}
static void F_88 ( struct V_1 * V_16 , T_1 V_4 )
{
F_89 ( & V_16 -> V_54 ) ;
F_90 ( & V_16 -> V_54 , V_16 -> V_55 ) ;
F_91 ( & V_16 -> V_54 , V_4 , V_9 ) ;
if ( V_16 -> V_56 == V_57 )
F_92 ( & V_16 -> V_54 , V_58 ) ;
else
F_93 ( F_94 ( & V_16 -> V_54 ) , 1 ) ;
}
static T_1 F_95 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
struct V_59 * V_60 = F_75 ( V_61 . V_62 ) ;
T_4 V_63 , V_64 , V_65 , V_66 , V_6 , V_67 ;
unsigned long V_68 , V_69 ;
T_1 V_70 ;
do {
V_68 = F_96 ( & V_10 ) ;
V_63 = V_7 . V_8 ;
V_69 = V_71 ;
} while ( F_97 ( & V_10 , V_68 ) );
V_16 -> V_72 = V_69 ;
if ( F_98 ( V_63 , & V_66 ) ||
F_99 () || F_100 () ) {
V_64 = V_63 + V_73 ;
} else {
V_65 = F_101 ( V_69 , V_63 ) ;
V_16 -> V_74 = V_65 ;
V_64 = V_66 < V_65 ? V_66 : V_65 ;
}
V_6 = V_64 - V_63 ;
if ( V_6 <= ( T_4 ) V_73 ) {
V_70 . V_8 = 0 ;
if ( ! V_16 -> V_19 )
goto V_30;
if ( V_6 == 0 ) {
F_88 ( V_16 , V_4 ) ;
goto V_30;
}
}
V_6 = F_102 () ;
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_75 = 1 ;
} else if ( V_14 != V_15 ) {
V_6 = V_76 ;
V_16 -> V_75 = 0 ;
} else if ( ! V_16 -> V_75 ) {
V_6 = V_76 ;
}
#ifdef F_103
if ( ! V_16 -> V_77 )
V_6 = F_104 ( V_6 , F_105 () ) ;
#endif
if ( V_6 < ( V_76 - V_63 ) )
V_67 = V_63 + V_6 ;
else
V_67 = V_76 ;
V_67 = F_106 ( T_4 , V_67 , V_64 ) ;
V_70 . V_8 = V_67 ;
if ( V_16 -> V_19 && ( V_67 == V_60 -> V_78 . V_8 ) )
goto V_30;
if ( ! V_16 -> V_19 ) {
F_107 ( V_2 ) ;
F_108 () ;
V_16 -> V_55 = F_94 ( & V_16 -> V_54 ) ;
V_16 -> V_19 = 1 ;
F_29 ( 1 , L_15 ) ;
}
if ( F_7 ( V_67 == V_76 ) ) {
if ( V_16 -> V_56 == V_57 )
F_89 ( & V_16 -> V_54 ) ;
goto V_30;
}
if ( V_16 -> V_56 == V_57 )
F_109 ( & V_16 -> V_54 , V_70 , V_58 ) ;
else
F_93 ( V_70 , 1 ) ;
V_30:
V_16 -> V_79 = F_4 ( V_60 -> V_78 , V_4 ) ;
return V_70 ;
}
static void F_110 ( struct V_1 * V_16 , T_1 V_4 , int V_80 )
{
F_3 ( V_4 ) ;
F_111 ( V_80 ) ;
F_112 () ;
F_20 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_81 = V_4 ;
F_88 ( V_16 , V_4 ) ;
}
static void F_113 ( struct V_1 * V_16 )
{
#ifdef F_103
int V_2 = F_16 () ;
if ( ! F_18 ( V_2 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_56 == V_82 )
return;
if ( F_25 () )
F_95 ( V_16 , F_84 () , V_2 ) ;
else if ( V_16 -> V_19 )
F_110 ( V_16 , F_84 () , 1 ) ;
#endif
}
static bool F_114 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_115 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_56 == V_82 ) ) {
V_16 -> V_79 = ( T_1 ) { . V_8 = V_83 / V_84 } ;
return false ;
}
if ( F_116 () )
return false ;
if ( F_7 ( F_117 () && F_115 ( V_2 ) ) ) {
static int V_85 ;
if ( V_85 < 10 &&
( F_117 () & V_86 ) ) {
F_118 ( L_16 ,
( unsigned int ) F_117 () ) ;
V_85 ++ ;
}
return false ;
}
if ( F_119 () ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_120 ( struct V_1 * V_16 )
{
T_1 V_4 , V_67 ;
int V_2 = F_16 () ;
V_4 = F_83 ( V_16 ) ;
if ( F_114 ( V_2 , V_16 ) ) {
int V_87 = V_16 -> V_19 ;
V_16 -> V_88 ++ ;
V_67 = F_95 ( V_16 , V_4 , V_2 ) ;
if ( V_67 . V_8 > 0LL ) {
V_16 -> V_89 ++ ;
V_16 -> V_90 = V_67 ;
}
if ( ! V_87 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_72 ;
}
}
void F_121 ( void )
{
struct V_1 * V_16 ;
F_26 ( F_27 () ) ;
F_122 () ;
F_123 () ;
V_16 = F_38 ( & V_3 ) ;
V_16 -> V_77 = 1 ;
F_120 ( V_16 ) ;
F_124 () ;
}
void F_125 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
if ( V_16 -> V_77 )
F_120 ( V_16 ) ;
else
F_113 ( V_16 ) ;
}
T_1 F_126 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
return V_16 -> V_79 ;
}
static void F_127 ( struct V_1 * V_16 )
{
#ifndef F_128
unsigned long V_5 ;
if ( F_129 () )
return;
V_5 = V_71 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_91 )
F_130 ( V_5 ) ;
#endif
}
void F_131 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
T_1 V_4 ;
F_123 () ;
F_26 ( ! V_16 -> V_77 ) ;
V_16 -> V_77 = 0 ;
if ( V_16 -> V_47 || V_16 -> V_19 )
V_4 = F_84 () ;
if ( V_16 -> V_47 )
F_81 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_110 ( V_16 , V_4 , 0 ) ;
F_127 ( V_16 ) ;
}
F_124 () ;
}
static void F_132 ( struct V_59 * V_60 )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
struct V_17 * V_18 = F_133 () ;
T_1 V_4 = F_84 () ;
V_60 -> V_78 . V_8 = V_76 ;
F_15 ( V_4 ) ;
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return;
F_91 ( & V_16 -> V_54 , V_4 , V_9 ) ;
F_93 ( F_94 ( & V_16 -> V_54 ) , 1 ) ;
}
static inline void F_134 ( struct V_1 * V_16 , int V_92 )
{
if ( ! V_44 )
return;
V_16 -> V_56 = V_92 ;
if ( ! F_135 ( 0 , & V_52 ) )
F_136 ( true ) ;
}
static void F_137 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
T_1 V_93 ;
if ( ! V_44 )
return;
if ( F_138 ( F_132 ) )
return;
F_139 ( & V_16 -> V_54 , V_94 , V_95 ) ;
V_93 = F_14 () ;
F_90 ( & V_16 -> V_54 , V_93 ) ;
F_140 ( & V_16 -> V_54 , V_9 ) ;
F_93 ( F_94 ( & V_16 -> V_54 ) , 1 ) ;
F_134 ( V_16 , V_96 ) ;
}
static void F_141 ( struct V_1 * V_16 , T_1 V_4 )
{
#if 0
ktime_t delta;
delta = ktime_sub(hrtimer_get_expires(&ts->sched_timer), now);
if (delta.tv64 <= tick_period.tv64)
return;
tick_nohz_restart(ts, now);
#endif
}
static inline void F_142 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_47 && ! V_16 -> V_19 )
return;
V_4 = F_84 () ;
if ( V_16 -> V_47 )
F_81 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_76 ( V_4 ) ;
F_141 ( V_16 , V_4 ) ;
}
}
static inline void F_137 ( void ) { }
static inline void F_142 ( void ) { }
static inline void F_134 ( struct V_1 * V_16 , int V_92 ) { }
void F_143 ( void )
{
F_144 () ;
F_142 () ;
}
static enum V_97 F_145 ( struct V_98 * V_99 )
{
struct V_1 * V_16 =
F_146 ( V_99 , struct V_1 , V_54 ) ;
struct V_17 * V_18 = F_133 () ;
T_1 V_4 = F_84 () ;
F_15 ( V_4 ) ;
if ( V_18 )
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return V_100 ;
F_91 ( V_99 , V_4 , V_9 ) ;
return V_101 ;
}
static int T_3 F_147 ( char * V_31 )
{
F_148 ( & V_31 , & V_102 ) ;
return 0 ;
}
void F_149 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
T_1 V_4 = F_84 () ;
F_139 ( & V_16 -> V_54 , V_94 , V_95 ) ;
V_16 -> V_54 . V_103 = F_145 ;
F_90 ( & V_16 -> V_54 , F_14 () ) ;
if ( V_102 ) {
T_4 V_104 = F_8 ( V_9 ) >> 1 ;
F_150 ( V_104 , F_151 () ) ;
V_104 *= F_16 () ;
F_152 ( & V_16 -> V_54 , V_104 ) ;
}
F_91 ( & V_16 -> V_54 , V_4 , V_9 ) ;
F_92 ( & V_16 -> V_54 , V_58 ) ;
F_134 ( V_16 , V_57 ) ;
}
void F_153 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_154
if ( V_16 -> V_54 . V_105 )
F_89 ( & V_16 -> V_54 ) ;
# endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
void F_155 ( void )
{
int V_2 ;
F_156 (cpu)
F_157 ( 0 , & F_2 ( V_3 , V_2 ) . V_106 ) ;
}
void F_158 ( void )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
F_157 ( 0 , & V_16 -> V_106 ) ;
}
int F_159 ( int V_107 )
{
struct V_1 * V_16 = F_38 ( & V_3 ) ;
if ( ! F_160 ( 0 , & V_16 -> V_106 ) )
return 0 ;
if ( V_16 -> V_56 != V_82 )
return 0 ;
if ( ! F_161 () || ! F_162 () )
return 0 ;
if ( ! V_107 )
return 1 ;
F_137 () ;
return 0 ;
}
