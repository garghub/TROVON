static const char * F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
if ( V_1 >= F_3 ( V_3 ) )
return L_1 ;
return V_3 [ V_1 ] ;
}
static T_1 T_2 F_4 ( void )
{
T_1 V_4 = F_5 () ;
unsigned long T_3 V_5 = F_6 ( V_4 , V_6 ) ;
return V_4 ;
}
static T_1 T_2 F_4 ( void )
{
return 0ULL ;
}
static struct V_7 *
F_7 ( void )
{
struct V_8 * V_9 ;
F_8 ( & V_10 ) ;
if ( F_9 ( & V_11 ) ) {
F_10 ( & V_12 ) ;
F_11 ( & V_10 ) ;
return NULL ;
}
F_10 ( & V_13 ) ;
V_9 = V_11 . V_14 ;
F_12 ( V_9 ) ;
F_11 ( & V_10 ) ;
return F_13 ( V_9 , struct V_7 , V_15 ) ;
}
static void
F_14 ( struct V_7 * V_9 )
{
F_10 ( & V_16 ) ;
F_8 ( & V_10 ) ;
F_15 ( & V_9 -> V_15 , & V_11 ) ;
F_11 ( & V_10 ) ;
}
static int F_16 ( void ) __acquires( T_4 )
{
F_17 () ;
return 0 ;
}
static void F_18 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
unsigned long V_20 ;
const unsigned long V_21 = 200 ;
const unsigned long V_22 = 50 ;
unsigned long long V_4 ;
if ( ! ( F_19 ( V_18 ) % ( V_23 * 2000 * V_22 ) ) ) {
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
F_20 ( V_22 ) ;
V_20 = V_24 -> V_20 () ;
F_21 ( V_24 -> V_25 , NULL , V_4 ,
V_19 , V_20 ) ;
}
if ( ! ( F_19 ( V_18 ) % ( V_23 * 2 * V_21 ) ) )
F_22 ( V_21 ) ;
#ifdef F_23
if ( ! F_24 () &&
! ( F_19 ( V_18 ) % ( V_23 * 20000 ) ) )
F_25 () ;
#endif
}
static void F_26 ( int V_26 ) __releases( T_4 )
{
F_27 () ;
}
static bool
F_28 ( struct V_7 * V_27 )
{
int V_1 ;
V_1 = V_27 -> V_28 ;
if ( V_1 > V_29 )
V_1 = V_29 ;
F_10 ( & V_30 [ V_1 ] ) ;
if ( ++ V_27 -> V_28 >= V_29 ) {
V_27 -> V_31 = 0 ;
return true ;
}
return false ;
}
static void
F_29 ( struct V_7 * V_32 )
{
struct V_7 * V_27 ;
struct V_7 * V_33 ;
if ( V_32 )
F_30 ( & V_32 -> V_15 , & V_34 ) ;
F_31 (rp, rp1, &rcu_torture_removed, rtort_free) {
if ( F_28 ( V_27 ) ) {
F_32 ( & V_27 -> V_15 ) ;
F_14 ( V_27 ) ;
}
}
}
static void
F_33 ( struct V_35 * V_9 )
{
struct V_7 * V_27 = F_13 ( V_9 , struct V_7 , V_36 ) ;
if ( F_34 () ) {
return;
}
if ( F_28 ( V_27 ) )
F_14 ( V_27 ) ;
else
V_24 -> V_37 ( V_27 ) ;
}
static unsigned long F_35 ( void )
{
return 0 ;
}
static void F_36 ( struct V_7 * V_9 )
{
F_37 ( & V_9 -> V_36 , F_33 ) ;
}
static void F_38 ( void )
{
F_39 ( & V_34 ) ;
}
static int F_40 ( void ) __acquires( T_5 )
{
F_41 () ;
return 0 ;
}
static void F_42 ( int V_26 ) __releases( T_5 )
{
F_43 () ;
}
static void F_44 ( struct V_7 * V_9 )
{
F_45 ( & V_9 -> V_36 , F_33 ) ;
}
static void F_46 ( struct V_7 * V_9 )
{
F_33 ( & V_9 -> V_36 ) ;
}
static void F_47 ( void )
{
}
static void
F_48 ( struct V_35 * V_38 , T_6 V_39 )
{
V_39 ( V_38 ) ;
}
static int F_49 ( void ) __acquires( T_7 )
{
return F_50 ( T_7 ) ;
}
static void F_51 ( struct V_17 * V_18 )
{
long V_40 ;
const long V_41 = 1000000 / V_42 ;
const long V_43 = 10 ;
V_40 = F_19 ( V_18 ) %
( V_23 * 2 * V_43 * V_41 ) ;
if ( ! V_40 )
F_52 ( V_43 ) ;
else
F_18 ( V_18 ) ;
}
static void F_53 ( int V_26 ) __releases( T_7 )
{
F_54 ( T_7 , V_26 ) ;
}
static unsigned long F_55 ( void )
{
return F_56 ( T_7 ) ;
}
static void F_57 ( struct V_7 * V_27 )
{
F_58 ( T_7 , & V_27 -> V_36 , F_33 ) ;
}
static void F_59 ( void )
{
F_60 ( T_7 ) ;
}
static void F_61 ( struct V_35 * V_38 ,
T_6 V_39 )
{
F_58 ( T_7 , V_38 , V_39 ) ;
}
static void F_62 ( void )
{
F_63 ( T_7 ) ;
}
static void F_64 ( void )
{
int T_3 V_44 ;
int V_26 ;
#if F_65 ( V_45 ) || F_65 ( V_46 )
#ifdef V_45
V_26 = T_7 -> V_47 & 0x1 ;
#else
V_26 = T_7 -> V_20 & 0x1 ;
#endif
F_66 ( L_2 ,
V_48 , V_49 , V_26 ) ;
F_67 (cpu) {
unsigned long V_50 , V_51 ;
unsigned long V_52 , V_53 ;
long V_54 , V_55 ;
#ifdef V_45
struct V_56 * V_57 ;
V_57 = F_68 ( T_7 -> V_58 , V_44 ) ;
V_52 = V_57 -> V_59 [ ! V_26 ] ;
V_53 = V_57 -> V_59 [ V_26 ] ;
#else
struct V_60 * V_57 ;
V_57 = F_68 ( T_7 -> V_61 , V_44 ) ;
V_52 = V_57 -> V_62 [ ! V_26 ] ;
V_53 = V_57 -> V_62 [ V_26 ] ;
#endif
F_69 () ;
#ifdef V_45
V_50 = V_57 -> V_63 [ ! V_26 ] ;
V_51 = V_57 -> V_63 [ V_26 ] ;
#else
V_50 = V_57 -> V_64 [ ! V_26 ] ;
V_51 = V_57 -> V_64 [ V_26 ] ;
#endif
V_54 = V_50 - V_52 ;
V_55 = V_51 - V_53 ;
F_70 ( L_3 , V_44 , V_54 , V_55 ) ;
}
F_70 ( L_4 ) ;
#elif F_65 ( V_65 )
V_26 = F_2 ( T_7 -> V_47 ) & 0x1 ;
F_66 ( L_5 ,
V_48 , V_49 , V_26 ,
F_2 ( T_7 -> V_66 [ ! V_26 ] ) ,
F_2 ( T_7 -> V_66 [ V_26 ] ) ) ;
#endif
}
static void F_71 ( void )
{
F_72 ( T_7 ) ;
}
static void F_73 ( void )
{
F_38 () ;
F_74 ( F_75 ( & V_67 ) ) ;
T_7 = & V_67 ;
}
static void F_76 ( void )
{
F_77 ( & V_67 ) ;
T_7 = & V_68 ;
}
static int F_78 ( void )
{
F_79 () ;
return 0 ;
}
static void F_80 ( int V_26 )
{
F_81 () ;
}
static void F_82 ( struct V_7 * V_9 )
{
F_83 ( & V_9 -> V_36 , F_33 ) ;
}
static int F_84 ( void )
{
return 0 ;
}
static void F_85 ( int V_26 )
{
}
static void F_86 ( struct V_7 * V_9 )
{
F_87 ( & V_9 -> V_36 , F_33 ) ;
}
static bool T_3 F_88 ( void )
{
return V_24 == & V_69 ;
}
static bool T_3 F_88 ( void )
{
return false ;
}
static void F_89 ( struct V_35 * V_38 )
{
struct V_70 * V_71 =
F_13 ( V_38 , struct V_70 , V_72 ) ;
F_90 ( & V_71 -> V_73 , 0 ) ;
}
static int F_91 ( void * V_74 )
{
unsigned long V_75 ;
unsigned long V_76 ;
unsigned long V_77 ;
struct V_70 V_78 = { . V_73 = 0 } ;
struct V_79 V_80 ;
F_92 ( L_6 ) ;
V_80 . V_81 = 1 ;
if ( F_93 ( V_82 , V_83 , & V_80 ) < 0 ) {
F_92 ( L_7 ) ;
V_84 ++ ;
}
F_94 ( & V_78 . V_72 ) ;
do {
V_77 = V_85 ;
while ( F_95 ( V_86 , V_77 ) ) {
F_52 ( V_77 - V_86 ) ;
F_96 ( L_8 ) ;
if ( F_97 () )
goto V_87;
}
V_76 = V_77 + V_88 * V_42 ;
V_75 = V_86 ;
while ( F_95 ( V_86 , V_76 ) ) {
if ( ! F_98 ( & V_78 . V_73 ) ) {
F_90 ( & V_78 . V_73 , 1 ) ;
F_37 ( & V_78 . V_72 , F_89 ) ;
if ( V_86 - V_75 >
V_88 * V_42 - V_42 / 2 ) {
F_92 ( L_9 ) ;
V_89 ++ ;
}
V_75 = V_86 ;
}
F_96 ( L_8 ) ;
if ( F_97 () )
goto V_87;
}
while ( V_77 == V_85 &&
! F_99 () ) {
if ( F_100 ( & V_90 ) ) {
V_85 = V_86 +
V_91 * V_42 ;
V_92 ++ ;
F_101 ( & V_90 ) ;
break;
}
F_102 ( 1 ) ;
}
V_87: F_96 ( L_8 ) ;
} while ( ! F_97 () );
while ( ! F_99 () || F_98 ( & V_78 . V_73 ) ) {
F_103 ( L_8 ) ;
F_102 ( 1 ) ;
}
F_104 ( & V_78 . V_72 ) ;
F_105 ( L_8 ) ;
return 0 ;
}
static void F_106 ( struct V_35 * V_93 )
{
}
static int
F_107 ( void * V_74 )
{
int V_94 = 1 ;
int V_1 ;
int V_95 ;
struct V_35 * V_93 ;
if ( V_96 > 0 &&
V_97 > 0 &&
V_98 > 0 &&
V_24 -> V_99 &&
V_24 -> V_100 ) {
V_93 = F_108 ( sizeof( * V_93 ) *
V_101 * V_96 ) ;
V_94 = ! V_93 ;
}
if ( V_94 ) {
F_92 ( L_10 ) ;
goto V_102;
}
F_92 ( L_11 ) ;
do {
F_52 ( V_97 ) ;
F_109 ( & V_103 ) ;
F_74 ( F_110 ( V_82 ) ) ;
for ( V_1 = 0 ; V_1 < V_101 ; V_1 ++ ) {
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
V_24 -> V_99 ( & V_93 [ V_1 * V_96 + V_95 ] ,
F_106 ) ;
}
F_52 ( V_98 ) ;
F_74 ( F_110 ( V_82 ) ) ;
}
V_24 -> V_100 () ;
F_96 ( L_12 ) ;
} while ( ! F_97 () );
F_111 ( V_93 ) ;
V_102:
F_105 ( L_12 ) ;
return 0 ;
}
static int
F_112 ( void * V_74 )
{
unsigned long V_104 ;
int V_105 ;
F_92 ( L_13 ) ;
do {
V_104 = V_86 + V_106 * V_42 ;
while ( F_95 ( V_86 , V_104 ) &&
! F_99 () ) {
F_52 ( 1 ) ;
}
V_105 = V_107 ;
while ( V_105 > 0 &&
! F_99 () ) {
V_24 -> V_108 () ;
F_22 ( V_109 ) ;
V_105 -= V_109 ;
}
F_96 ( L_14 ) ;
} while ( ! F_97 () );
F_105 ( L_14 ) ;
return 0 ;
}
static int
F_113 ( void * V_74 )
{
bool V_110 = ! F_114 () && ! F_115 () ;
int V_111 = 0 ;
unsigned long V_112 ;
bool V_113 = V_114 , V_115 = V_116 , V_117 = V_118 ;
bool V_119 = V_120 ;
int V_1 ;
struct V_7 * V_27 ;
struct V_7 * V_32 ;
static F_116 ( rand ) ;
int V_121 [] = { V_122 , V_123 ,
V_124 , V_125 } ;
int V_126 = 0 ;
F_92 ( L_15 ) ;
if ( ! V_110 ) {
F_66 ( L_16 V_49
L_17 ,
V_48 , V_24 -> V_25 ) ;
F_66 ( L_16 V_49
L_18 ,
V_48 ) ;
}
if ( ! V_113 && ! V_115 && ! V_117 && ! V_119 )
V_113 = V_115 = V_117 = V_119 = true ;
if ( V_113 && V_24 -> V_127 && V_24 -> V_128 )
V_121 [ V_126 ++ ] = V_124 ;
else if ( V_114 && ( ! V_24 -> V_127 || ! V_24 -> V_128 ) )
F_66 ( L_19 ) ;
if ( V_115 && V_24 -> V_129 )
V_121 [ V_126 ++ ] = V_123 ;
else if ( V_116 && ! V_24 -> V_129 )
F_66 ( L_20 ) ;
if ( V_117 && V_24 -> V_37 )
V_121 [ V_126 ++ ] = V_122 ;
else if ( V_118 && ! V_24 -> V_37 )
F_66 ( L_21 ) ;
if ( V_119 && V_24 -> V_130 )
V_121 [ V_126 ++ ] = V_125 ;
else if ( V_120 && ! V_24 -> V_130 )
F_66 ( L_22 ) ;
if ( F_117 ( V_126 == 0 ,
L_23 ) ) {
V_2 = V_131 ;
F_105 ( L_24 ) ;
}
do {
V_2 = V_132 ;
F_102 ( 1 ) ;
V_27 = F_7 () ;
if ( V_27 == NULL )
continue;
V_27 -> V_28 = 0 ;
V_2 = V_133 ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
V_2 = V_134 ;
V_32 = F_118 ( V_135 ,
V_82 == V_136 ) ;
V_27 -> V_31 = 1 ;
F_119 ( V_135 , V_27 ) ;
F_120 () ;
if ( V_32 ) {
V_1 = V_32 -> V_28 ;
if ( V_1 > V_29 )
V_1 = V_29 ;
F_10 ( & V_30 [ V_1 ] ) ;
V_32 -> V_28 ++ ;
switch ( V_121 [ F_19 ( & rand ) % V_126 ] ) {
case V_122 :
V_2 = V_122 ;
V_24 -> V_37 ( V_32 ) ;
break;
case V_123 :
V_2 = V_123 ;
V_24 -> V_129 () ;
F_29 ( V_32 ) ;
break;
case V_124 :
V_2 = V_124 ;
V_112 = V_24 -> V_127 () ;
V_1 = F_19 ( & rand ) % 16 ;
if ( V_1 != 0 )
F_52 ( V_1 ) ;
F_22 ( F_19 ( & rand ) % 1000 ) ;
V_2 = V_137 ;
V_24 -> V_128 ( V_112 ) ;
F_29 ( V_32 ) ;
break;
case V_125 :
V_2 = V_125 ;
V_24 -> V_130 () ;
F_29 ( V_32 ) ;
break;
default:
F_121 ( 1 ) ;
break;
}
}
F_122 ( ++ V_138 ) ;
if ( V_110 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_111 - 1 ) ) ) {
F_121 ( V_111 == 0 && F_114 () ) ;
if ( V_111 >= 0 )
F_123 () ;
else
F_124 () ;
if ( ++ V_111 > 3 )
V_111 = - V_111 ;
}
V_2 = V_139 ;
F_96 ( L_24 ) ;
} while ( ! F_97 () );
if ( V_111 > 0 )
V_111 = - V_111 ;
while ( V_110 && V_111 ++ < 0 )
F_124 () ;
F_121 ( V_110 && F_114 () ) ;
V_2 = V_131 ;
F_105 ( L_24 ) ;
return 0 ;
}
static int
F_125 ( void * V_74 )
{
F_116 ( rand ) ;
F_92 ( L_25 ) ;
F_126 ( V_82 , V_140 ) ;
do {
F_102 ( 1 + F_19 ( & rand ) % 10 ) ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
if ( V_24 -> V_100 != NULL &&
F_19 ( & rand ) % ( V_141 * 8 ) == 0 ) {
V_24 -> V_100 () ;
} else if ( V_118 == V_116 ) {
if ( F_19 ( & rand ) & 0x80 )
V_24 -> V_130 () ;
else
V_24 -> V_129 () ;
} else if ( V_118 ) {
V_24 -> V_130 () ;
} else {
V_24 -> V_129 () ;
}
F_96 ( L_26 ) ;
} while ( ! F_97 () );
F_105 ( L_26 ) ;
return 0 ;
}
static void F_127 ( unsigned long V_142 )
{
int V_26 ;
unsigned long V_19 ;
unsigned long V_20 ;
static F_116 ( rand ) ;
static F_128 ( V_143 ) ;
struct V_7 * V_9 ;
int V_144 ;
unsigned long long V_4 ;
V_26 = V_24 -> V_145 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_118 ( V_135 ,
F_129 () ||
F_130 () ||
F_131 ( T_7 ) ||
F_88 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_146 ( V_26 ) ;
return;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_147 ) ;
F_132 ( & V_143 ) ;
V_24 -> V_148 ( & rand ) ;
V_149 ++ ;
F_133 ( & V_143 ) ;
F_79 () ;
V_144 = V_9 -> V_28 ;
if ( V_144 > V_29 ) {
V_144 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_144 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 , V_4 ,
V_19 , V_20 ) ;
F_134 ( V_150 ) ;
}
F_135 ( V_151 [ V_144 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_135 ( V_152 [ V_20 ] ) ;
F_81 () ;
V_24 -> V_146 ( V_26 ) ;
}
static int
F_136 ( void * V_74 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_26 ;
F_116 ( rand ) ;
struct V_7 * V_9 ;
int V_144 ;
struct V_153 V_154 ;
unsigned long long V_4 ;
F_92 ( L_27 ) ;
F_126 ( V_82 , V_140 ) ;
if ( V_155 && V_24 -> V_156 )
F_137 ( & V_154 , F_127 , 0 ) ;
do {
if ( V_155 && V_24 -> V_156 ) {
if ( ! F_138 ( & V_154 ) )
F_139 ( & V_154 , V_86 + 1 ) ;
}
V_26 = V_24 -> V_145 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_118 ( V_135 ,
F_129 () ||
F_130 () ||
F_131 ( T_7 ) ||
F_88 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_146 ( V_26 ) ;
F_52 ( V_42 ) ;
continue;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_147 ) ;
V_24 -> V_148 ( & rand ) ;
F_79 () ;
V_144 = V_9 -> V_28 ;
if ( V_144 > V_29 ) {
V_144 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_144 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 ,
V_4 , V_19 , V_20 ) ;
F_134 ( V_150 ) ;
}
F_135 ( V_151 [ V_144 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_135 ( V_152 [ V_20 ] ) ;
F_81 () ;
V_24 -> V_146 ( V_26 ) ;
F_96 ( L_28 ) ;
} while ( ! F_97 () );
if ( V_155 && V_24 -> V_156 ) {
F_140 ( & V_154 ) ;
F_141 ( & V_154 ) ;
}
F_105 ( L_28 ) ;
return 0 ;
}
static void
F_142 ( void )
{
int V_44 ;
int V_1 ;
long V_157 [ V_29 + 1 ] = { 0 } ;
long V_158 [ V_29 + 1 ] = { 0 } ;
static unsigned long V_159 = V_160 ;
struct V_161 * V_162 ;
F_67 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
V_157 [ V_1 ] += F_143 ( V_151 , V_44 ) [ V_1 ] ;
V_158 [ V_1 ] += F_143 ( V_152 , V_44 ) [ V_1 ] ;
}
}
for ( V_1 = V_29 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_157 [ V_1 ] != 0 )
break;
}
F_66 ( L_29 , V_48 , V_49 ) ;
F_70 ( L_30 ,
V_135 ,
V_138 ,
F_9 ( & V_11 ) ,
F_144 ( & V_13 ) ,
F_144 ( & V_12 ) ,
F_144 ( & V_16 ) ) ;
F_70 ( L_31 ,
F_144 ( & V_147 ) ,
V_163 ,
V_164 ,
V_84 ) ;
F_70 ( L_32 ,
V_89 ,
V_92 ,
V_149 ) ;
F_145 () ;
F_70 ( L_33 ,
V_165 ,
V_166 ,
V_163 ) ;
F_70 ( L_34 , F_146 ( & V_103 ) ) ;
F_66 ( L_29 , V_48 , V_49 ) ;
if ( F_144 ( & V_147 ) != 0 ||
V_163 != 0 ||
V_164 != 0 ||
V_84 != 0 ||
V_89 != 0 ||
V_1 > 1 ) {
F_70 ( L_16 , L_35 ) ;
F_10 ( & V_167 ) ;
F_121 ( 1 ) ;
}
F_70 ( L_36 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_70 ( L_37 , V_157 [ V_1 ] ) ;
F_70 ( L_4 ) ;
F_66 ( L_29 , V_48 , V_49 ) ;
F_70 ( L_38 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_70 ( L_37 , V_158 [ V_1 ] ) ;
F_70 ( L_4 ) ;
F_66 ( L_29 , V_48 , V_49 ) ;
F_70 ( L_39 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_70 ( L_40 , F_144 ( & V_30 [ V_1 ] ) ) ;
}
F_70 ( L_4 ) ;
if ( V_24 -> V_168 )
V_24 -> V_168 () ;
if ( V_159 == V_138 &&
V_135 != NULL ) {
int T_3 V_169 = 0 ;
unsigned long T_3 V_170 = 0 ;
unsigned long T_3 V_20 = 0 ;
F_147 ( V_24 -> V_171 ,
& V_169 , & V_170 , & V_20 ) ;
F_148 ( V_24 -> V_171 , T_7 ,
& V_169 , & V_170 , & V_20 ) ;
V_162 = F_2 ( V_136 ) ;
F_66 ( L_41 ,
F_1 () ,
V_2 ,
V_170 , V_20 , V_169 ,
V_162 == NULL ? ~ 0UL : V_162 -> V_172 ) ;
F_149 () ;
F_134 ( V_150 ) ;
}
V_159 = V_138 ;
}
static int
F_150 ( void * V_74 )
{
F_92 ( L_42 ) ;
do {
F_52 ( V_173 * V_42 ) ;
F_142 () ;
F_103 ( L_43 ) ;
} while ( ! F_97 () );
F_105 ( L_43 ) ;
return 0 ;
}
static inline void
F_151 ( struct V_174 * V_24 , const char * V_175 )
{
F_66 ( L_16 V_49
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_48 , V_175 , V_23 , V_141 ,
V_173 , V_176 , V_177 , V_178 ,
V_179 , V_155 , V_107 , V_109 , V_106 ,
V_180 , V_24 -> V_181 ,
V_91 , V_88 , V_182 ,
V_183 , V_184 ,
V_185 ,
V_186 , V_187 ) ;
}
static int F_152 ( unsigned int V_44 )
{
struct V_161 * V_154 ;
if ( V_188 [ V_44 ] == NULL )
return 0 ;
F_153 ( & V_90 ) ;
V_154 = V_188 [ V_44 ] ;
V_188 [ V_44 ] = NULL ;
F_101 ( & V_90 ) ;
F_154 ( F_91 , V_154 ) ;
return 0 ;
}
static int F_155 ( unsigned int V_44 )
{
int V_189 ;
if ( V_188 [ V_44 ] != NULL )
return 0 ;
F_153 ( & V_90 ) ;
F_92 ( L_53 ) ;
V_188 [ V_44 ] = F_156 ( F_91 , NULL ,
F_157 ( V_44 ) ,
L_8 ) ;
if ( F_158 ( V_188 [ V_44 ] ) ) {
V_189 = F_159 ( V_188 [ V_44 ] ) ;
F_92 ( L_54 ) ;
V_164 ++ ;
V_188 [ V_44 ] = NULL ;
F_101 ( & V_90 ) ;
return V_189 ;
}
F_160 ( V_188 [ V_44 ] , V_44 ) ;
F_161 ( V_188 [ V_44 ] ) ;
F_101 ( & V_90 ) ;
return 0 ;
}
static int F_162 ( void * args )
{
unsigned long V_190 ;
F_92 ( L_55 ) ;
if ( V_184 > 0 ) {
F_92 ( L_56 ) ;
F_52 ( V_184 * V_42 ) ;
F_92 ( L_57 ) ;
}
if ( ! F_99 () ) {
V_190 = F_163 () + V_183 ;
F_66 ( L_58 ) ;
F_17 () ;
F_79 () ;
while ( F_95 ( F_163 () , V_190 ) )
continue;
F_81 () ;
F_27 () ;
F_66 ( L_59 ) ;
}
F_103 ( L_60 ) ;
while ( ! F_99 () )
F_52 ( 10 * V_42 ) ;
return 0 ;
}
static int T_8 F_164 ( void )
{
if ( V_183 <= 0 )
return 0 ;
return F_165 ( F_162 , NULL , V_191 ) ;
}
static void F_166 ( struct V_35 * V_72 )
{
F_10 ( & V_192 ) ;
}
static int F_167 ( void * V_74 )
{
long V_193 = ( long ) V_74 ;
bool V_194 = 0 ;
bool V_195 ;
struct V_35 V_72 ;
F_94 ( & V_72 ) ;
F_92 ( L_61 ) ;
F_126 ( V_82 , V_140 ) ;
do {
F_168 ( V_196 [ V_193 ] ,
( V_195 =
F_98 ( & V_197 ) ) != V_194 ||
F_97 () ) ;
V_194 = V_195 ;
if ( F_97 () )
break;
F_169 () ;
V_24 -> V_99 ( & V_72 , F_166 ) ;
F_170 () ;
if ( F_171 ( & V_198 ) )
F_172 ( & V_199 ) ;
} while ( ! F_97 () );
if ( V_24 -> V_100 != NULL )
V_24 -> V_100 () ;
F_104 ( & V_72 ) ;
F_105 ( L_62 ) ;
return 0 ;
}
static int F_173 ( void * V_74 )
{
int V_1 ;
F_92 ( L_63 ) ;
do {
F_174 ( & V_192 , 0 ) ;
F_174 ( & V_198 , V_185 ) ;
F_90 ( & V_197 , ! V_197 ) ;
for ( V_1 = 0 ; V_1 < V_185 ; V_1 ++ )
F_172 ( & V_196 [ V_1 ] ) ;
F_168 ( V_199 ,
F_144 ( & V_198 ) == 0 ||
F_97 () ) ;
if ( F_97 () )
break;
V_166 ++ ;
V_24 -> V_100 () ;
if ( F_144 ( & V_192 ) != V_185 ) {
V_163 ++ ;
F_175 ( L_64 ,
F_144 ( & V_192 ) ,
V_185 ) ;
F_121 ( 1 ) ;
}
V_165 ++ ;
F_52 ( V_42 / 10 ) ;
} while ( ! F_97 () );
F_105 ( L_65 ) ;
return 0 ;
}
static int F_176 ( void )
{
int V_1 ;
int V_200 ;
if ( V_185 <= 0 )
return 0 ;
if ( V_24 -> V_99 == NULL || V_24 -> V_100 == NULL ) {
F_66 ( L_16 V_49
L_66 ,
V_48 , V_24 -> V_25 ) ;
F_66 ( L_16 V_49
L_67 ,
V_48 ) ;
return 0 ;
}
F_174 ( & V_198 , 0 ) ;
F_174 ( & V_192 , 0 ) ;
V_201 =
F_177 ( V_185 * sizeof( V_201 [ 0 ] ) ,
V_202 ) ;
V_196 =
F_177 ( V_185 * sizeof( V_196 [ 0 ] ) ,
V_202 ) ;
if ( V_201 == NULL || ! V_196 )
return - V_203 ;
for ( V_1 = 0 ; V_1 < V_185 ; V_1 ++ ) {
F_178 ( & V_196 [ V_1 ] ) ;
V_200 = F_165 ( F_167 ,
( void * ) ( long ) V_1 ,
V_201 [ V_1 ] ) ;
if ( V_200 )
return V_200 ;
}
return F_165 ( F_173 , NULL , V_204 ) ;
}
static void F_179 ( void )
{
int V_1 ;
F_154 ( F_173 , V_204 ) ;
if ( V_201 != NULL ) {
for ( V_1 = 0 ; V_1 < V_185 ; V_1 ++ )
F_154 ( F_167 ,
V_201 [ V_1 ] ) ;
F_180 ( V_201 ) ;
V_201 = NULL ;
}
if ( V_196 != NULL ) {
F_180 ( V_196 ) ;
V_196 = NULL ;
}
}
static void
F_181 ( void )
{
int V_1 ;
F_182 () ;
if ( F_183 () ) {
if ( V_24 -> V_100 != NULL )
V_24 -> V_100 () ;
return;
}
F_179 () ;
F_154 ( F_162 , V_191 ) ;
F_154 ( F_113 , V_136 ) ;
if ( V_205 ) {
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ )
F_154 ( F_136 ,
V_205 [ V_1 ] ) ;
F_180 ( V_205 ) ;
}
V_135 = NULL ;
if ( V_206 ) {
for ( V_1 = 0 ; V_1 < V_141 ; V_1 ++ ) {
F_154 ( F_125 ,
V_206 [ V_1 ] ) ;
}
F_180 ( V_206 ) ;
V_206 = NULL ;
}
F_154 ( F_150 , V_207 ) ;
F_154 ( F_112 , V_208 ) ;
for ( V_1 = 0 ; V_1 < V_209 ; V_1 ++ )
F_154 ( F_107 , V_210 [ V_1 ] ) ;
if ( ( V_180 == 1 && V_24 -> V_181 ) ||
V_180 == 2 )
F_184 ( V_211 ) ;
if ( V_24 -> V_100 != NULL )
V_24 -> V_100 () ;
if ( V_24 -> V_212 != NULL )
V_24 -> V_212 () ;
F_142 () ;
if ( F_144 ( & V_167 ) || V_163 )
F_151 ( V_24 , L_68 ) ;
else if ( F_185 () )
F_151 ( V_24 ,
L_69 ) ;
else
F_151 ( V_24 , L_70 ) ;
F_186 () ;
}
static void F_187 ( struct V_35 * V_93 )
{
}
static void F_188 ( struct V_35 * V_93 )
{
F_66 ( L_71 ) ;
}
static void F_189 ( void )
{
#ifdef F_190
struct V_35 V_213 ;
struct V_35 V_214 ;
F_94 ( & V_213 ) ;
F_94 ( & V_214 ) ;
F_66 ( L_72 ) ;
F_79 () ;
F_17 () ;
F_37 ( & V_213 , F_187 ) ;
F_169 () ;
F_37 ( & V_214 , F_187 ) ;
F_37 ( & V_214 , F_188 ) ;
F_170 () ;
F_27 () ;
F_81 () ;
F_191 () ;
F_66 ( L_73 ) ;
F_104 ( & V_213 ) ;
F_104 ( & V_214 ) ;
#else
F_66 ( L_74 ) ;
#endif
}
static int T_8
F_192 ( void )
{
int V_1 ;
int V_44 ;
int V_215 = 0 ;
static struct V_174 * V_216 [] = {
& V_217 , & V_218 , & V_219 , & V_220 , & V_221 ,
& V_222 , V_223
} ;
if ( ! F_193 ( V_48 , V_176 , & V_224 ) )
return - V_225 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_216 ) ; V_1 ++ ) {
V_24 = V_216 [ V_1 ] ;
if ( strcmp ( V_48 , V_24 -> V_25 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_216 ) ) {
F_66 ( L_75 ,
V_48 ) ;
F_66 ( L_76 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_216 ) ; V_1 ++ )
F_66 ( L_77 , V_216 [ V_1 ] -> V_25 ) ;
F_66 ( L_4 ) ;
V_215 = - V_226 ;
goto V_227;
}
if ( V_24 -> V_108 == NULL && V_107 != 0 ) {
F_66 ( L_78 ) ;
V_107 = 0 ;
}
if ( V_24 -> V_228 )
V_24 -> V_228 () ;
if ( V_229 >= 0 ) {
V_23 = V_229 ;
} else {
V_23 = F_194 () - 2 - V_229 ;
if ( V_23 <= 0 )
V_23 = 1 ;
}
F_151 ( V_24 , L_79 ) ;
F_39 ( & V_11 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_230 ) ; V_1 ++ ) {
V_230 [ V_1 ] . V_31 = 0 ;
F_15 ( & V_230 [ V_1 ] . V_15 ,
& V_11 ) ;
}
V_135 = NULL ;
V_138 = 0 ;
F_174 ( & V_13 , 0 ) ;
F_174 ( & V_12 , 0 ) ;
F_174 ( & V_16 , 0 ) ;
F_174 ( & V_147 , 0 ) ;
F_174 ( & V_167 , 0 ) ;
V_163 = 0 ;
V_164 = 0 ;
V_84 = 0 ;
V_89 = 0 ;
V_92 = 0 ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_174 ( & V_30 [ V_1 ] , 0 ) ;
F_67 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_143 ( V_151 , V_44 ) [ V_1 ] = 0 ;
F_143 ( V_152 , V_44 ) [ V_1 ] = 0 ;
}
}
V_215 = F_165 ( F_113 , NULL ,
V_136 ) ;
if ( V_215 )
goto V_227;
if ( V_141 > 0 ) {
V_206 = F_177 ( V_141 *
sizeof( V_206 [ 0 ] ) ,
V_202 ) ;
if ( V_206 == NULL ) {
F_195 ( L_80 ) ;
V_215 = - V_203 ;
goto V_227;
}
}
for ( V_1 = 0 ; V_1 < V_141 ; V_1 ++ ) {
V_215 = F_165 ( F_125 ,
NULL , V_206 [ V_1 ] ) ;
if ( V_215 )
goto V_227;
}
V_205 = F_177 ( V_23 * sizeof( V_205 [ 0 ] ) ,
V_202 ) ;
if ( V_205 == NULL ) {
F_195 ( L_80 ) ;
V_215 = - V_203 ;
goto V_227;
}
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ ) {
V_215 = F_165 ( F_136 , NULL ,
V_205 [ V_1 ] ) ;
if ( V_215 )
goto V_227;
}
if ( V_173 > 0 ) {
V_215 = F_165 ( F_150 , NULL ,
V_207 ) ;
if ( V_215 )
goto V_227;
}
if ( V_177 && V_178 > 0 ) {
V_215 = F_196 ( V_178 * V_42 ) ;
if ( V_215 )
goto V_227;
}
if ( V_179 < 0 )
V_179 = 0 ;
if ( V_179 ) {
V_215 = F_197 ( V_179 * V_42 ) ;
if ( V_215 )
goto V_227;
}
if ( V_107 < 0 )
V_107 = 0 ;
if ( V_107 ) {
V_215 = F_165 ( F_112 , NULL ,
V_208 ) ;
if ( V_215 )
goto V_227;
}
if ( V_91 < 1 )
V_91 = 1 ;
if ( V_88 < 2 )
V_88 = 2 ;
if ( ( V_180 == 1 && V_24 -> V_181 ) ||
V_180 == 2 ) {
V_85 = V_86 + V_91 * V_42 ;
V_215 = F_198 ( V_231 , L_81 ,
F_155 ,
F_152 ) ;
if ( V_215 < 0 )
goto V_227;
V_211 = V_215 ;
}
V_215 = F_199 ( V_182 , F_181 ) ;
if ( V_215 )
goto V_227;
V_215 = F_200 ( V_187 * V_42 , V_186 * V_42 ) ;
if ( V_215 )
goto V_227;
V_215 = F_164 () ;
if ( V_215 )
goto V_227;
V_215 = F_176 () ;
if ( V_215 )
goto V_227;
if ( V_232 )
F_189 () ;
if ( V_101 > 0 ) {
V_209 = ( F_194 () + 3 ) / 4 ;
V_210 = F_201 ( V_209 , sizeof( * V_210 ) ,
V_202 ) ;
if ( ! V_210 ) {
F_195 ( L_80 ) ;
V_215 = - V_203 ;
goto V_227;
}
for ( V_1 = 0 ; V_1 < V_209 ; V_1 ++ ) {
V_215 = F_165 ( F_107 ,
NULL ,
V_210 [ V_1 ] ) ;
if ( V_215 )
goto V_227;
}
}
F_182 () ;
F_202 () ;
return 0 ;
V_227:
F_202 () ;
F_181 () ;
return V_215 ;
}
