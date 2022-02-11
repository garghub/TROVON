struct V_1 * F_1 ( int V_2 )
{
return & F_2 ( V_3 , V_2 ) ;
}
static void F_3 ( T_1 V_4 )
{
unsigned long V_5 = 0 ;
T_1 V_6 ;
V_6 = F_4 ( V_4 , V_7 ) ;
if ( V_6 < V_8 )
return;
F_5 ( & V_9 ) ;
V_6 = F_4 ( V_4 , V_7 ) ;
if ( V_6 >= V_8 ) {
V_6 = F_4 ( V_6 , V_8 ) ;
V_7 = F_6 ( V_7 ,
V_8 ) ;
if ( F_7 ( V_6 >= V_8 ) ) {
T_2 V_10 = F_8 ( V_8 ) ;
V_5 = F_9 ( V_6 , V_10 ) ;
V_7 = F_10 ( V_7 ,
V_10 * V_5 ) ;
}
F_11 ( ++ V_5 ) ;
V_11 = F_6 ( V_7 , V_8 ) ;
} else {
F_12 ( & V_9 ) ;
return;
}
F_12 ( & V_9 ) ;
F_13 () ;
}
static T_1 F_14 ( void )
{
T_1 V_12 ;
F_5 ( & V_9 ) ;
if ( V_7 == 0 )
V_7 = V_11 ;
V_12 = V_7 ;
F_12 ( & V_9 ) ;
return V_12 ;
}
static void F_15 ( T_1 V_4 )
{
int V_2 = F_16 () ;
#ifdef F_17
if ( F_7 ( V_13 == V_14 )
&& ! F_18 ( V_2 ) )
V_13 = V_2 ;
#endif
if ( V_13 == V_2 )
F_3 ( V_4 ) ;
}
static void F_19 ( struct V_1 * V_15 , struct V_16 * V_17 )
{
#ifdef F_17
if ( V_15 -> V_18 ) {
F_20 () ;
if ( F_21 ( V_19 ) )
V_15 -> V_20 ++ ;
V_15 -> V_21 = 0 ;
}
#endif
F_22 ( F_23 ( V_17 ) ) ;
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
static bool F_28 ( int V_2 , struct V_1 * V_15 )
{
F_29 ( ! F_30 () ) ;
if ( F_7 ( ! F_31 ( V_2 ) ) )
return false ;
if ( F_25 ( & V_29 ) )
return false ;
if ( F_25 ( & V_15 -> V_29 ) )
return false ;
if ( F_25 ( & V_19 -> V_29 ) )
return false ;
if ( F_25 ( & V_19 -> signal -> V_29 ) )
return false ;
return true ;
}
static void F_32 ( struct V_30 * V_31 )
{
}
static void F_33 ( void )
{
if ( ! F_18 ( F_16 () ) )
return;
F_34 ( F_35 ( & V_32 ) ) ;
}
void F_36 ( int V_2 )
{
if ( ! F_18 ( V_2 ) )
return;
F_37 ( & F_2 ( V_32 , V_2 ) , V_2 ) ;
}
static void F_38 ( void )
{
int V_2 ;
if ( ! V_33 )
return;
F_39 () ;
F_40 (cpu, tick_nohz_full_mask, cpu_online_mask)
F_36 ( V_2 ) ;
F_41 () ;
}
static void F_42 ( T_3 * V_23 ,
enum V_34 V_35 )
{
int V_36 ;
V_36 = F_43 ( F_44 ( V_35 ) , V_23 ) ;
if ( ! V_36 )
F_38 () ;
}
void F_45 ( enum V_34 V_35 )
{
F_42 ( & V_29 , V_35 ) ;
}
void F_46 ( enum V_34 V_35 )
{
F_47 ( F_44 ( V_35 ) , & V_29 ) ;
}
void F_48 ( int V_2 , enum V_34 V_35 )
{
int V_36 ;
struct V_1 * V_15 ;
V_15 = F_49 ( & V_3 , V_2 ) ;
V_36 = F_43 ( F_44 ( V_35 ) , & V_15 -> V_29 ) ;
if ( ! V_36 ) {
F_39 () ;
if ( V_2 == F_16 () ) {
F_33 () ;
} else {
if ( ! F_29 ( F_50 () ) )
F_36 ( V_2 ) ;
}
F_41 () ;
}
}
void F_51 ( int V_2 , enum V_34 V_35 )
{
struct V_1 * V_15 = F_49 ( & V_3 , V_2 ) ;
F_47 ( F_44 ( V_35 ) , & V_15 -> V_29 ) ;
}
void F_52 ( struct V_37 * V_38 , enum V_34 V_35 )
{
F_42 ( & V_38 -> V_29 , V_35 ) ;
}
void F_53 ( struct V_37 * V_38 , enum V_34 V_35 )
{
F_47 ( F_44 ( V_35 ) , & V_38 -> V_29 ) ;
}
void F_54 ( struct V_39 * V_40 , enum V_34 V_35 )
{
F_42 ( & V_40 -> V_29 , V_35 ) ;
}
void F_55 ( struct V_39 * V_40 , enum V_34 V_35 )
{
F_47 ( F_44 ( V_35 ) , & V_40 -> V_29 ) ;
}
void F_56 ( void )
{
unsigned long V_41 ;
struct V_1 * V_15 ;
F_57 ( V_41 ) ;
if ( ! F_18 ( F_16 () ) )
goto V_42;
V_15 = F_35 ( & V_3 ) ;
if ( V_15 -> V_18 ) {
if ( F_26 ( & V_19 -> V_29 ) ||
F_26 ( & V_19 -> signal -> V_29 ) )
F_33 () ;
}
V_42:
F_58 ( V_41 ) ;
}
static int T_4 F_59 ( char * V_43 )
{
F_60 ( & V_44 ) ;
if ( F_61 ( V_43 , V_44 ) < 0 ) {
F_62 ( L_1 ) ;
F_63 ( V_44 ) ;
return 1 ;
}
V_33 = true ;
return 1 ;
}
static int F_64 ( unsigned int V_2 )
{
if ( V_33 && V_13 == V_2 )
return - V_45 ;
return 0 ;
}
static int F_65 ( void )
{
int V_46 = - 1 ;
#ifdef F_66
if ( ! F_67 ( & V_44 , V_47 ) ) {
F_68 ( 1 , L_2 ) ;
return V_46 ;
}
V_46 = 0 ;
F_69 ( V_44 ) ;
V_33 = true ;
#endif
return V_46 ;
}
void T_4 F_70 ( void )
{
int V_2 , V_48 ;
if ( ! V_33 ) {
if ( F_65 () < 0 )
return;
}
if ( ! F_67 ( & V_49 , V_47 ) ) {
F_68 ( 1 , L_3 ) ;
F_71 ( V_44 ) ;
V_33 = false ;
return;
}
if ( ! F_72 () ) {
F_62 ( L_4 ) ;
F_71 ( V_44 ) ;
F_73 ( V_49 , V_50 ) ;
V_33 = false ;
return;
}
V_2 = F_16 () ;
if ( F_74 ( V_2 , V_44 ) ) {
F_62 ( L_5 ,
V_2 ) ;
F_75 ( V_2 , V_44 ) ;
}
F_76 ( V_49 ,
V_50 , V_44 ) ;
F_77 (cpu, tick_nohz_full_mask)
F_78 ( V_2 ) ;
V_48 = F_79 ( V_51 ,
L_6 , NULL ,
F_64 ) ;
F_80 ( V_48 < 0 ) ;
F_81 ( L_7 ,
F_82 ( V_44 ) ) ;
F_29 ( F_83 ( V_49 ) ) ;
}
static int T_4 F_84 ( char * V_43 )
{
return ( F_85 ( V_43 , & V_52 ) == 0 ) ;
}
int F_86 ( void )
{
return F_87 ( V_3 . V_18 ) ;
}
static void F_88 ( T_1 V_4 )
{
unsigned long V_41 ;
F_89 ( V_3 . V_53 , V_4 ) ;
F_57 ( V_41 ) ;
F_3 ( V_4 ) ;
F_58 ( V_41 ) ;
F_20 () ;
}
static void
F_90 ( int V_2 , struct V_1 * V_15 , T_1 V_4 , T_5 * V_54 )
{
T_1 V_6 ;
if ( V_15 -> V_55 ) {
V_6 = F_4 ( V_4 , V_15 -> V_56 ) ;
if ( F_91 ( V_2 ) > 0 )
V_15 -> V_57 = F_6 ( V_15 -> V_57 , V_6 ) ;
else
V_15 -> V_58 = F_6 ( V_15 -> V_58 , V_6 ) ;
V_15 -> V_56 = V_4 ;
}
if ( V_54 )
* V_54 = F_92 ( V_4 ) ;
}
static void F_93 ( struct V_1 * V_15 , T_1 V_4 )
{
F_90 ( F_16 () , V_15 , V_4 , NULL ) ;
V_15 -> V_55 = 0 ;
F_94 () ;
}
static T_1 F_95 ( struct V_1 * V_15 )
{
T_1 V_4 = F_96 () ;
V_15 -> V_56 = V_4 ;
V_15 -> V_55 = 1 ;
F_97 () ;
return V_4 ;
}
T_5 F_98 ( int V_2 , T_5 * V_54 )
{
struct V_1 * V_15 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_59 ;
if ( ! V_60 )
return - 1 ;
V_4 = F_96 () ;
if ( V_54 ) {
F_90 ( V_2 , V_15 , V_4 , V_54 ) ;
V_59 = V_15 -> V_58 ;
} else {
if ( V_15 -> V_55 && ! F_91 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_15 -> V_56 ) ;
V_59 = F_6 ( V_15 -> V_58 , V_6 ) ;
} else {
V_59 = V_15 -> V_58 ;
}
}
return F_92 ( V_59 ) ;
}
T_5 F_99 ( int V_2 , T_5 * V_54 )
{
struct V_1 * V_15 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_61 ;
if ( ! V_60 )
return - 1 ;
V_4 = F_96 () ;
if ( V_54 ) {
F_90 ( V_2 , V_15 , V_4 , V_54 ) ;
V_61 = V_15 -> V_57 ;
} else {
if ( V_15 -> V_55 && F_91 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_15 -> V_56 ) ;
V_61 = F_6 ( V_15 -> V_57 , V_6 ) ;
} else {
V_61 = V_15 -> V_57 ;
}
}
return F_92 ( V_61 ) ;
}
static void F_100 ( struct V_1 * V_15 , T_1 V_4 )
{
F_101 ( & V_15 -> V_62 ) ;
F_102 ( & V_15 -> V_62 , V_15 -> V_63 ) ;
F_103 ( & V_15 -> V_62 , V_4 , V_8 ) ;
if ( V_15 -> V_64 == V_65 )
F_104 ( & V_15 -> V_62 , V_66 ) ;
else
F_105 ( F_106 ( & V_15 -> V_62 ) , 1 ) ;
V_15 -> V_21 = 0 ;
}
static T_1 F_107 ( struct V_1 * V_15 ,
T_1 V_4 , int V_2 )
{
struct V_67 * V_68 = F_87 ( V_69 . V_70 ) ;
T_5 V_71 , V_21 , V_72 , V_73 , V_6 , V_74 ;
unsigned long V_75 , V_76 ;
T_1 V_77 ;
do {
V_75 = F_108 ( & V_9 ) ;
V_71 = V_7 ;
V_76 = V_78 ;
} while ( F_109 ( & V_9 , V_75 ) );
V_15 -> V_79 = V_76 ;
if ( F_110 ( V_71 , & V_73 ) ||
F_111 () || F_112 () ) {
V_21 = V_71 + V_80 ;
} else {
V_72 = F_113 ( V_76 , V_71 ) ;
V_15 -> V_81 = V_72 ;
V_21 = V_73 < V_72 ? V_73 : V_72 ;
}
V_6 = V_21 - V_71 ;
if ( V_6 <= ( T_5 ) V_80 ) {
F_114 () ;
if ( ! V_15 -> V_18 ) {
V_77 = 0 ;
goto V_42;
}
}
V_6 = F_115 () ;
if ( V_2 == V_13 ) {
V_13 = V_14 ;
V_15 -> V_82 = 1 ;
} else if ( V_13 != V_14 ) {
V_6 = V_83 ;
V_15 -> V_82 = 0 ;
} else if ( ! V_15 -> V_82 ) {
V_6 = V_83 ;
}
#ifdef F_116
if ( ! V_15 -> V_84 )
V_6 = F_117 ( V_6 , F_118 () ) ;
#endif
if ( V_6 < ( V_83 - V_71 ) )
V_74 = V_71 + V_6 ;
else
V_74 = V_83 ;
V_74 = F_119 ( T_5 , V_74 , V_21 ) ;
V_77 = V_74 ;
if ( V_15 -> V_18 && ( V_74 == V_15 -> V_21 ) ) {
if ( V_77 == V_83 || V_15 -> V_21 == F_106 ( & V_15 -> V_62 ) )
goto V_42;
F_29 ( 1 ) ;
F_120 ( L_8 ,
V_71 , V_15 -> V_21 , V_68 -> V_85 ,
F_121 ( & V_15 -> V_62 ) , F_106 ( & V_15 -> V_62 ) ) ;
}
if ( ! V_15 -> V_18 ) {
F_122 () ;
F_123 () ;
V_15 -> V_63 = F_106 ( & V_15 -> V_62 ) ;
V_15 -> V_18 = 1 ;
F_27 ( 1 , V_86 ) ;
}
V_15 -> V_21 = V_77 ;
if ( F_7 ( V_74 == V_83 ) ) {
if ( V_15 -> V_64 == V_65 )
F_101 ( & V_15 -> V_62 ) ;
goto V_42;
}
F_102 ( & V_15 -> V_62 , V_77 ) ;
if ( V_15 -> V_64 == V_65 )
F_104 ( & V_15 -> V_62 , V_66 ) ;
else
F_105 ( V_77 , 1 ) ;
V_42:
V_15 -> V_87 = F_4 ( V_68 -> V_85 , V_4 ) ;
return V_77 ;
}
static void F_124 ( struct V_1 * V_15 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_125 () ;
F_114 () ;
F_126 () ;
F_20 () ;
V_15 -> V_18 = 0 ;
V_15 -> V_88 = V_4 ;
F_100 ( V_15 , V_4 ) ;
}
static void F_127 ( struct V_1 * V_15 )
{
#ifdef F_116
int V_2 = F_16 () ;
if ( ! F_18 ( V_2 ) )
return;
if ( ! V_15 -> V_18 && V_15 -> V_64 == V_89 )
return;
if ( F_28 ( V_2 , V_15 ) )
F_107 ( V_15 , F_96 () , V_2 ) ;
else if ( V_15 -> V_18 )
F_124 ( V_15 , F_96 () ) ;
#endif
}
static bool F_128 ( int V_2 , struct V_1 * V_15 )
{
if ( F_7 ( ! F_31 ( V_2 ) ) ) {
if ( V_2 == V_13 )
V_13 = V_14 ;
V_15 -> V_21 = 0 ;
return false ;
}
if ( F_7 ( V_15 -> V_64 == V_89 ) ) {
V_15 -> V_87 = V_90 / V_91 ;
return false ;
}
if ( F_129 () )
return false ;
if ( F_7 ( F_130 () && F_31 ( V_2 ) ) ) {
static int V_92 ;
if ( V_92 < 10 &&
( F_130 () & V_93 ) ) {
F_62 ( L_9 ,
( unsigned int ) F_130 () ) ;
V_92 ++ ;
}
return false ;
}
if ( F_131 () ) {
if ( V_13 == V_2 )
return false ;
if ( V_13 == V_14 )
return false ;
}
return true ;
}
static void F_132 ( struct V_1 * V_15 )
{
T_1 V_4 , V_74 ;
int V_2 = F_16 () ;
V_4 = F_95 ( V_15 ) ;
if ( F_128 ( V_2 , V_15 ) ) {
int V_94 = V_15 -> V_18 ;
V_15 -> V_95 ++ ;
V_74 = F_107 ( V_15 , V_4 , V_2 ) ;
if ( V_74 > 0LL ) {
V_15 -> V_96 ++ ;
V_15 -> V_97 = V_74 ;
}
if ( ! V_94 && V_15 -> V_18 ) {
V_15 -> V_20 = V_15 -> V_79 ;
F_133 ( V_2 ) ;
}
}
}
void F_134 ( void )
{
struct V_1 * V_15 ;
F_29 ( F_30 () ) ;
F_135 () ;
F_136 () ;
V_15 = F_35 ( & V_3 ) ;
V_15 -> V_84 = 1 ;
F_132 ( V_15 ) ;
F_137 () ;
}
void F_138 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
if ( V_15 -> V_84 )
F_132 ( V_15 ) ;
else
F_127 ( V_15 ) ;
}
T_1 F_139 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
return V_15 -> V_87 ;
}
unsigned long F_140 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
return V_15 -> V_95 ;
}
static void F_141 ( struct V_1 * V_15 )
{
#ifndef F_142
unsigned long V_5 ;
if ( F_143 () )
return;
V_5 = V_78 - V_15 -> V_20 ;
if ( V_5 && V_5 < V_98 )
F_144 ( V_5 ) ;
#endif
}
void F_145 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
T_1 V_4 ;
F_136 () ;
F_29 ( ! V_15 -> V_84 ) ;
V_15 -> V_84 = 0 ;
if ( V_15 -> V_55 || V_15 -> V_18 )
V_4 = F_96 () ;
if ( V_15 -> V_55 )
F_93 ( V_15 , V_4 ) ;
if ( V_15 -> V_18 ) {
F_124 ( V_15 , V_4 ) ;
F_141 ( V_15 ) ;
}
F_137 () ;
}
static void F_146 ( struct V_67 * V_68 )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
struct V_16 * V_17 = F_147 () ;
T_1 V_4 = F_96 () ;
V_68 -> V_85 = V_83 ;
F_15 ( V_4 ) ;
F_19 ( V_15 , V_17 ) ;
if ( F_7 ( V_15 -> V_18 ) )
return;
F_103 ( & V_15 -> V_62 , V_4 , V_8 ) ;
F_105 ( F_106 ( & V_15 -> V_62 ) , 1 ) ;
}
static inline void F_148 ( struct V_1 * V_15 , int V_99 )
{
if ( ! V_52 )
return;
V_15 -> V_64 = V_99 ;
if ( ! F_149 ( 0 , & V_60 ) )
F_150 ( true ) ;
}
static void F_151 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
T_1 V_100 ;
if ( ! V_52 )
return;
if ( F_152 ( F_146 ) )
return;
F_153 ( & V_15 -> V_62 , V_101 , V_102 ) ;
V_100 = F_14 () ;
F_102 ( & V_15 -> V_62 , V_100 ) ;
F_154 ( & V_15 -> V_62 , V_8 ) ;
F_105 ( F_106 ( & V_15 -> V_62 ) , 1 ) ;
F_148 ( V_15 , V_103 ) ;
}
static inline void F_155 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
T_1 V_4 ;
if ( ! V_15 -> V_55 && ! V_15 -> V_18 )
return;
V_4 = F_96 () ;
if ( V_15 -> V_55 )
F_93 ( V_15 , V_4 ) ;
if ( V_15 -> V_18 )
F_88 ( V_4 ) ;
}
static inline void F_151 ( void ) { }
static inline void F_155 ( void ) { }
static inline void F_148 ( struct V_1 * V_15 , int V_99 ) { }
void F_156 ( void )
{
F_157 () ;
F_155 () ;
}
static enum V_104 F_158 ( struct V_105 * V_106 )
{
struct V_1 * V_15 =
F_159 ( V_106 , struct V_1 , V_62 ) ;
struct V_16 * V_17 = F_147 () ;
T_1 V_4 = F_96 () ;
F_15 ( V_4 ) ;
if ( V_17 )
F_19 ( V_15 , V_17 ) ;
else
V_15 -> V_21 = 0 ;
if ( F_7 ( V_15 -> V_18 ) )
return V_107 ;
F_103 ( V_106 , V_4 , V_8 ) ;
return V_108 ;
}
static int T_4 F_160 ( char * V_43 )
{
F_161 ( & V_43 , & V_109 ) ;
return 0 ;
}
void F_162 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
T_1 V_4 = F_96 () ;
F_153 ( & V_15 -> V_62 , V_101 , V_102 ) ;
V_15 -> V_62 . V_110 = F_158 ;
F_102 ( & V_15 -> V_62 , F_14 () ) ;
if ( V_109 ) {
T_5 V_111 = F_8 ( V_8 ) >> 1 ;
F_163 ( V_111 , F_164 () ) ;
V_111 *= F_16 () ;
F_165 ( & V_15 -> V_62 , V_111 ) ;
}
F_103 ( & V_15 -> V_62 , V_4 , V_8 ) ;
F_104 ( & V_15 -> V_62 , V_66 ) ;
F_148 ( V_15 , V_65 ) ;
}
void F_166 ( int V_2 )
{
struct V_1 * V_15 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_167
if ( V_15 -> V_62 . V_112 )
F_101 ( & V_15 -> V_62 ) ;
# endif
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
}
void F_168 ( void )
{
int V_2 ;
F_169 (cpu)
F_170 ( 0 , & F_2 ( V_3 , V_2 ) . V_113 ) ;
}
void F_171 ( void )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
F_170 ( 0 , & V_15 -> V_113 ) ;
}
int F_172 ( int V_114 )
{
struct V_1 * V_15 = F_35 ( & V_3 ) ;
if ( ! F_173 ( 0 , & V_15 -> V_113 ) )
return 0 ;
if ( V_15 -> V_64 != V_89 )
return 0 ;
if ( ! F_174 () || ! F_175 () )
return 0 ;
if ( ! V_114 )
return 1 ;
F_151 () ;
return 0 ;
}
