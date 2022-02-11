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
static bool F_28 ( int V_2 , struct V_1 * V_16 )
{
F_29 ( ! F_30 () ) ;
if ( F_7 ( ! F_31 ( V_2 ) ) )
return false ;
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
struct V_1 * V_16 ;
V_16 = F_49 ( & V_3 , V_2 ) ;
V_36 = F_43 ( F_44 ( V_35 ) , & V_16 -> V_29 ) ;
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
struct V_1 * V_16 = F_49 ( & V_3 , V_2 ) ;
F_47 ( F_44 ( V_35 ) , & V_16 -> V_29 ) ;
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
struct V_1 * V_16 ;
F_57 ( V_41 ) ;
if ( ! F_18 ( F_16 () ) )
goto V_42;
V_16 = F_35 ( & V_3 ) ;
if ( V_16 -> V_19 ) {
if ( F_26 ( & V_20 -> V_29 ) ||
F_26 ( & V_20 -> signal -> V_29 ) )
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
static int F_64 ( struct V_45 * V_46 ,
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
static int F_65 ( void )
{
int V_53 = - 1 ;
#ifdef F_66
if ( ! F_67 ( & V_44 , V_54 ) ) {
F_68 ( 1 , L_2 ) ;
return V_53 ;
}
V_53 = 0 ;
F_69 ( V_44 ) ;
V_33 = true ;
#endif
return V_53 ;
}
void T_4 F_70 ( void )
{
int V_2 ;
if ( ! V_33 ) {
if ( F_65 () < 0 )
return;
}
if ( ! F_67 ( & V_55 , V_54 ) ) {
F_68 ( 1 , L_3 ) ;
F_71 ( V_44 ) ;
V_33 = false ;
return;
}
if ( ! F_72 () ) {
F_62 ( L_4 ) ;
F_71 ( V_44 ) ;
F_73 ( V_55 , V_56 ) ;
V_33 = false ;
return;
}
V_2 = F_16 () ;
if ( F_74 ( V_2 , V_44 ) ) {
F_62 ( L_5 ,
V_2 ) ;
F_75 ( V_2 , V_44 ) ;
}
F_76 ( V_55 ,
V_56 , V_44 ) ;
F_77 (cpu, tick_nohz_full_mask)
F_78 ( V_2 ) ;
F_79 ( F_64 , 0 ) ;
F_80 ( L_6 ,
F_81 ( V_44 ) ) ;
F_29 ( F_82 ( V_55 ) ) ;
}
static int T_4 F_83 ( char * V_43 )
{
return ( F_84 ( V_43 , & V_57 ) == 0 ) ;
}
int F_85 ( void )
{
return F_86 ( V_3 . V_19 ) ;
}
static void F_87 ( T_1 V_4 )
{
unsigned long V_41 ;
F_88 ( V_3 . V_58 , V_4 ) ;
F_57 ( V_41 ) ;
F_3 ( V_4 ) ;
F_58 ( V_41 ) ;
F_20 () ;
}
static void
F_89 ( int V_2 , struct V_1 * V_16 , T_1 V_4 , T_5 * V_59 )
{
T_1 V_6 ;
if ( V_16 -> V_60 ) {
V_6 = F_4 ( V_4 , V_16 -> V_61 ) ;
if ( F_90 ( V_2 ) > 0 )
V_16 -> V_62 = F_6 ( V_16 -> V_62 , V_6 ) ;
else
V_16 -> V_63 = F_6 ( V_16 -> V_63 , V_6 ) ;
V_16 -> V_61 = V_4 ;
}
if ( V_59 )
* V_59 = F_91 ( V_4 ) ;
}
static void F_92 ( struct V_1 * V_16 , T_1 V_4 )
{
F_89 ( F_16 () , V_16 , V_4 , NULL ) ;
V_16 -> V_60 = 0 ;
F_93 ( 0 ) ;
}
static T_1 F_94 ( struct V_1 * V_16 )
{
T_1 V_4 = F_95 () ;
V_16 -> V_61 = V_4 ;
V_16 -> V_60 = 1 ;
F_96 () ;
return V_4 ;
}
T_5 F_97 ( int V_2 , T_5 * V_59 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_64 ;
if ( ! V_65 )
return - 1 ;
V_4 = F_95 () ;
if ( V_59 ) {
F_89 ( V_2 , V_16 , V_4 , V_59 ) ;
V_64 = V_16 -> V_63 ;
} else {
if ( V_16 -> V_60 && ! F_90 ( V_2 ) ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_61 ) ;
V_64 = F_6 ( V_16 -> V_63 , V_6 ) ;
} else {
V_64 = V_16 -> V_63 ;
}
}
return F_91 ( V_64 ) ;
}
T_5 F_98 ( int V_2 , T_5 * V_59 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
T_1 V_4 , V_66 ;
if ( ! V_65 )
return - 1 ;
V_4 = F_95 () ;
if ( V_59 ) {
F_89 ( V_2 , V_16 , V_4 , V_59 ) ;
V_66 = V_16 -> V_62 ;
} else {
if ( V_16 -> V_60 && F_90 ( V_2 ) > 0 ) {
T_1 V_6 = F_4 ( V_4 , V_16 -> V_61 ) ;
V_66 = F_6 ( V_16 -> V_62 , V_6 ) ;
} else {
V_66 = V_16 -> V_62 ;
}
}
return F_91 ( V_66 ) ;
}
static void F_99 ( struct V_1 * V_16 , T_1 V_4 )
{
F_100 ( & V_16 -> V_67 ) ;
F_101 ( & V_16 -> V_67 , V_16 -> V_68 ) ;
F_102 ( & V_16 -> V_67 , V_4 , V_9 ) ;
if ( V_16 -> V_69 == V_70 )
F_103 ( & V_16 -> V_67 , V_71 ) ;
else
F_104 ( F_105 ( & V_16 -> V_67 ) , 1 ) ;
}
static T_1 F_106 ( struct V_1 * V_16 ,
T_1 V_4 , int V_2 )
{
struct V_72 * V_73 = F_86 ( V_74 . V_75 ) ;
T_5 V_76 , V_77 , V_78 , V_79 , V_6 , V_80 ;
unsigned long V_81 , V_82 ;
T_1 V_83 ;
do {
V_81 = F_107 ( & V_10 ) ;
V_76 = V_7 . V_8 ;
V_82 = V_84 ;
} while ( F_108 ( & V_10 , V_81 ) );
V_16 -> V_85 = V_82 ;
if ( F_109 ( V_76 , & V_79 ) ||
F_110 () || F_111 () ) {
V_77 = V_76 + V_86 ;
} else {
V_78 = F_112 ( V_82 , V_76 ) ;
V_16 -> V_87 = V_78 ;
V_77 = V_79 < V_78 ? V_79 : V_78 ;
}
V_6 = V_77 - V_76 ;
if ( V_6 <= ( T_5 ) V_86 ) {
V_83 . V_8 = 0 ;
F_113 () ;
if ( ! V_16 -> V_19 )
goto V_42;
if ( V_6 == 0 ) {
F_99 ( V_16 , V_4 ) ;
goto V_42;
}
}
V_6 = F_114 () ;
if ( V_2 == V_14 ) {
V_14 = V_15 ;
V_16 -> V_88 = 1 ;
} else if ( V_14 != V_15 ) {
V_6 = V_89 ;
V_16 -> V_88 = 0 ;
} else if ( ! V_16 -> V_88 ) {
V_6 = V_89 ;
}
#ifdef F_115
if ( ! V_16 -> V_90 )
V_6 = F_116 ( V_6 , F_117 () ) ;
#endif
if ( V_6 < ( V_89 - V_76 ) )
V_80 = V_76 + V_6 ;
else
V_80 = V_89 ;
V_80 = F_118 ( T_5 , V_80 , V_77 ) ;
V_83 . V_8 = V_80 ;
if ( V_16 -> V_19 && ( V_80 == V_73 -> V_91 . V_8 ) )
goto V_42;
if ( ! V_16 -> V_19 ) {
F_119 ( V_2 ) ;
F_120 () ;
F_121 () ;
V_16 -> V_68 = F_105 ( & V_16 -> V_67 ) ;
V_16 -> V_19 = 1 ;
F_27 ( 1 , V_92 ) ;
}
if ( F_7 ( V_80 == V_89 ) ) {
if ( V_16 -> V_69 == V_70 )
F_100 ( & V_16 -> V_67 ) ;
goto V_42;
}
if ( V_16 -> V_69 == V_70 )
F_122 ( & V_16 -> V_67 , V_83 , V_71 ) ;
else
F_104 ( V_83 , 1 ) ;
V_42:
V_16 -> V_93 = F_4 ( V_73 -> V_91 , V_4 ) ;
return V_83 ;
}
static void F_123 ( struct V_1 * V_16 , T_1 V_4 )
{
F_3 ( V_4 ) ;
F_124 () ;
F_113 () ;
F_125 () ;
F_20 () ;
V_16 -> V_19 = 0 ;
V_16 -> V_94 = V_4 ;
F_99 ( V_16 , V_4 ) ;
}
static void F_126 ( struct V_1 * V_16 )
{
#ifdef F_115
int V_2 = F_16 () ;
if ( ! F_18 ( V_2 ) )
return;
if ( ! V_16 -> V_19 && V_16 -> V_69 == V_95 )
return;
if ( F_28 ( V_2 , V_16 ) )
F_106 ( V_16 , F_95 () , V_2 ) ;
else if ( V_16 -> V_19 )
F_123 ( V_16 , F_95 () ) ;
#endif
}
static bool F_127 ( int V_2 , struct V_1 * V_16 )
{
if ( F_7 ( ! F_31 ( V_2 ) ) ) {
if ( V_2 == V_14 )
V_14 = V_15 ;
return false ;
}
if ( F_7 ( V_16 -> V_69 == V_95 ) ) {
V_16 -> V_93 = ( T_1 ) { . V_8 = V_96 / V_97 } ;
return false ;
}
if ( F_128 () )
return false ;
if ( F_7 ( F_129 () && F_31 ( V_2 ) ) ) {
static int V_98 ;
if ( V_98 < 10 &&
( F_129 () & V_99 ) ) {
F_62 ( L_7 ,
( unsigned int ) F_129 () ) ;
V_98 ++ ;
}
return false ;
}
if ( F_130 () ) {
if ( V_14 == V_2 )
return false ;
if ( V_14 == V_15 )
return false ;
}
return true ;
}
static void F_131 ( struct V_1 * V_16 )
{
T_1 V_4 , V_80 ;
int V_2 = F_16 () ;
V_4 = F_94 ( V_16 ) ;
if ( F_127 ( V_2 , V_16 ) ) {
int V_100 = V_16 -> V_19 ;
V_16 -> V_101 ++ ;
V_80 = F_106 ( V_16 , V_4 , V_2 ) ;
if ( V_80 . V_8 > 0LL ) {
V_16 -> V_102 ++ ;
V_16 -> V_103 = V_80 ;
}
if ( ! V_100 && V_16 -> V_19 )
V_16 -> V_21 = V_16 -> V_85 ;
}
}
void F_132 ( void )
{
struct V_1 * V_16 ;
F_29 ( F_30 () ) ;
F_133 () ;
F_134 () ;
V_16 = F_35 ( & V_3 ) ;
V_16 -> V_90 = 1 ;
F_131 ( V_16 ) ;
F_135 () ;
}
void F_136 ( void )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
if ( V_16 -> V_90 )
F_131 ( V_16 ) ;
else
F_126 ( V_16 ) ;
}
T_1 F_137 ( void )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
return V_16 -> V_93 ;
}
static void F_138 ( struct V_1 * V_16 )
{
#ifndef F_139
unsigned long V_5 ;
if ( F_140 () )
return;
V_5 = V_84 - V_16 -> V_21 ;
if ( V_5 && V_5 < V_104 )
F_141 ( V_5 ) ;
#endif
}
void F_142 ( void )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
T_1 V_4 ;
F_134 () ;
F_29 ( ! V_16 -> V_90 ) ;
V_16 -> V_90 = 0 ;
if ( V_16 -> V_60 || V_16 -> V_19 )
V_4 = F_95 () ;
if ( V_16 -> V_60 )
F_92 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 ) {
F_123 ( V_16 , V_4 ) ;
F_138 ( V_16 ) ;
}
F_135 () ;
}
static void F_143 ( struct V_72 * V_73 )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
struct V_17 * V_18 = F_144 () ;
T_1 V_4 = F_95 () ;
V_73 -> V_91 . V_8 = V_89 ;
F_15 ( V_4 ) ;
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return;
F_102 ( & V_16 -> V_67 , V_4 , V_9 ) ;
F_104 ( F_105 ( & V_16 -> V_67 ) , 1 ) ;
}
static inline void F_145 ( struct V_1 * V_16 , int V_105 )
{
if ( ! V_57 )
return;
V_16 -> V_69 = V_105 ;
if ( ! F_146 ( 0 , & V_65 ) )
F_147 ( true ) ;
}
static void F_148 ( void )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
T_1 V_106 ;
if ( ! V_57 )
return;
if ( F_149 ( F_143 ) )
return;
F_150 ( & V_16 -> V_67 , V_107 , V_108 ) ;
V_106 = F_14 () ;
F_101 ( & V_16 -> V_67 , V_106 ) ;
F_151 ( & V_16 -> V_67 , V_9 ) ;
F_104 ( F_105 ( & V_16 -> V_67 ) , 1 ) ;
F_145 ( V_16 , V_109 ) ;
}
static inline void F_152 ( void )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
T_1 V_4 ;
if ( ! V_16 -> V_60 && ! V_16 -> V_19 )
return;
V_4 = F_95 () ;
if ( V_16 -> V_60 )
F_92 ( V_16 , V_4 ) ;
if ( V_16 -> V_19 )
F_87 ( V_4 ) ;
}
static inline void F_148 ( void ) { }
static inline void F_152 ( void ) { }
static inline void F_145 ( struct V_1 * V_16 , int V_105 ) { }
void F_153 ( void )
{
F_154 () ;
F_152 () ;
}
static enum V_110 F_155 ( struct V_111 * V_112 )
{
struct V_1 * V_16 =
F_156 ( V_112 , struct V_1 , V_67 ) ;
struct V_17 * V_18 = F_144 () ;
T_1 V_4 = F_95 () ;
F_15 ( V_4 ) ;
if ( V_18 )
F_19 ( V_16 , V_18 ) ;
if ( F_7 ( V_16 -> V_19 ) )
return V_113 ;
F_102 ( V_112 , V_4 , V_9 ) ;
return V_114 ;
}
static int T_4 F_157 ( char * V_43 )
{
F_158 ( & V_43 , & V_115 ) ;
return 0 ;
}
void F_159 ( void )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
T_1 V_4 = F_95 () ;
F_150 ( & V_16 -> V_67 , V_107 , V_108 ) ;
V_16 -> V_67 . V_116 = F_155 ;
F_101 ( & V_16 -> V_67 , F_14 () ) ;
if ( V_115 ) {
T_5 V_117 = F_8 ( V_9 ) >> 1 ;
F_160 ( V_117 , F_161 () ) ;
V_117 *= F_16 () ;
F_162 ( & V_16 -> V_67 , V_117 ) ;
}
F_102 ( & V_16 -> V_67 , V_4 , V_9 ) ;
F_103 ( & V_16 -> V_67 , V_71 ) ;
F_145 ( V_16 , V_70 ) ;
}
void F_163 ( int V_2 )
{
struct V_1 * V_16 = & F_2 ( V_3 , V_2 ) ;
# ifdef F_164
if ( V_16 -> V_67 . V_118 )
F_100 ( & V_16 -> V_67 ) ;
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
struct V_1 * V_16 = F_35 ( & V_3 ) ;
F_167 ( 0 , & V_16 -> V_119 ) ;
}
int F_169 ( int V_120 )
{
struct V_1 * V_16 = F_35 ( & V_3 ) ;
if ( ! F_170 ( 0 , & V_16 -> V_119 ) )
return 0 ;
if ( V_16 -> V_69 != V_95 )
return 0 ;
if ( ! F_171 () || ! F_172 () )
return 0 ;
if ( ! V_120 )
return 1 ;
F_148 () ;
return 0 ;
}
