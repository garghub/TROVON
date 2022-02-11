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
const unsigned long V_19 = 200 ;
const unsigned long V_20 = 50 ;
if ( ! ( F_19 ( V_18 ) % ( V_21 * 2000 * V_20 ) ) )
F_20 ( V_20 ) ;
if ( ! ( F_19 ( V_18 ) % ( V_21 * 2 * V_19 ) ) )
F_21 ( V_19 ) ;
#ifdef F_22
if ( ! F_23 () &&
! ( F_19 ( V_18 ) % ( V_21 * 20000 ) ) )
F_24 () ;
#endif
}
static void F_25 ( int V_22 ) __releases( T_4 )
{
F_26 () ;
}
static bool
F_27 ( struct V_7 * V_23 )
{
int V_1 ;
V_1 = V_23 -> V_24 ;
if ( V_1 > V_25 )
V_1 = V_25 ;
F_10 ( & V_26 [ V_1 ] ) ;
if ( ++ V_23 -> V_24 >= V_25 ) {
V_23 -> V_27 = 0 ;
return true ;
}
return false ;
}
static void
F_28 ( struct V_7 * V_28 )
{
struct V_7 * V_23 ;
struct V_7 * V_29 ;
if ( V_28 )
F_29 ( & V_28 -> V_15 , & V_30 ) ;
F_30 (rp, rp1, &rcu_torture_removed, rtort_free) {
if ( F_27 ( V_23 ) ) {
F_31 ( & V_23 -> V_15 ) ;
F_14 ( V_23 ) ;
}
}
}
static void
F_32 ( struct V_31 * V_9 )
{
struct V_7 * V_23 = F_13 ( V_9 , struct V_7 , V_32 ) ;
if ( F_33 () ) {
return;
}
if ( F_27 ( V_23 ) )
F_14 ( V_23 ) ;
else
V_33 -> V_34 ( V_23 ) ;
}
static unsigned long F_34 ( void )
{
return 0 ;
}
static void F_35 ( struct V_7 * V_9 )
{
F_36 ( & V_9 -> V_32 , F_32 ) ;
}
static void F_37 ( void )
{
F_38 ( & V_30 ) ;
}
static int F_39 ( void ) __acquires( T_5 )
{
F_40 () ;
return 0 ;
}
static void F_41 ( int V_22 ) __releases( T_5 )
{
F_42 () ;
}
static void F_43 ( struct V_7 * V_9 )
{
F_44 ( & V_9 -> V_32 , F_32 ) ;
}
static void F_45 ( struct V_7 * V_9 )
{
F_32 ( & V_9 -> V_32 ) ;
}
static void F_46 ( void )
{
}
static void
F_47 ( struct V_31 * V_35 , T_6 V_36 )
{
V_36 ( V_35 ) ;
}
static int F_48 ( void ) __acquires( T_7 )
{
return F_49 ( T_7 ) ;
}
static void F_50 ( struct V_17 * V_18 )
{
long V_37 ;
const long V_38 = 1000000 / V_39 ;
const long V_40 = 10 ;
V_37 = F_19 ( V_18 ) %
( V_21 * 2 * V_40 * V_38 ) ;
if ( ! V_37 )
F_51 ( V_40 ) ;
else
F_18 ( V_18 ) ;
}
static void F_52 ( int V_22 ) __releases( T_7 )
{
F_53 ( T_7 , V_22 ) ;
}
static unsigned long F_54 ( void )
{
return F_55 ( T_7 ) ;
}
static void F_56 ( struct V_7 * V_23 )
{
F_57 ( T_7 , & V_23 -> V_32 , F_32 ) ;
}
static void F_58 ( void )
{
F_59 ( T_7 ) ;
}
static void F_60 ( struct V_31 * V_35 ,
T_6 V_36 )
{
F_57 ( T_7 , V_35 , V_36 ) ;
}
static void F_61 ( void )
{
F_62 ( T_7 ) ;
}
static void F_63 ( void )
{
int V_41 ;
int V_22 = T_7 -> V_42 & 0x1 ;
F_64 ( L_2 ,
V_43 , V_44 , V_22 ) ;
F_65 (cpu) {
long V_45 , V_46 ;
V_45 = ( long ) F_66 ( T_7 -> V_47 , V_41 ) -> V_48 [ ! V_22 ] ;
V_46 = ( long ) F_66 ( T_7 -> V_47 , V_41 ) -> V_48 [ V_22 ] ;
F_67 ( L_3 , V_41 , V_45 , V_46 ) ;
}
F_67 ( L_4 ) ;
}
static void F_68 ( void )
{
F_69 ( T_7 ) ;
}
static void F_70 ( void )
{
F_37 () ;
F_71 ( F_72 ( & V_49 ) ) ;
T_7 = & V_49 ;
}
static void F_73 ( void )
{
F_74 ( & V_49 ) ;
T_7 = & V_50 ;
}
static int F_75 ( void )
{
F_76 () ;
return 0 ;
}
static void F_77 ( int V_22 )
{
F_78 () ;
}
static void F_79 ( struct V_7 * V_9 )
{
F_80 ( & V_9 -> V_32 , F_32 ) ;
}
static int F_81 ( void )
{
return 0 ;
}
static void F_82 ( int V_22 )
{
}
static void F_83 ( struct V_7 * V_9 )
{
F_84 ( & V_9 -> V_32 , F_32 ) ;
}
static bool T_3 F_85 ( void )
{
return V_33 == & V_51 ;
}
static bool T_3 F_85 ( void )
{
return false ;
}
static void F_86 ( struct V_31 * V_35 )
{
struct V_52 * V_53 =
F_13 ( V_35 , struct V_52 , V_54 ) ;
F_87 ( & V_53 -> V_55 , 0 ) ;
}
static int F_88 ( void * V_56 )
{
unsigned long V_57 ;
unsigned long V_58 ;
unsigned long V_59 ;
struct V_52 V_60 = { . V_55 = 0 } ;
struct V_61 V_62 ;
F_89 ( L_5 ) ;
V_62 . V_63 = 1 ;
if ( F_90 ( V_64 , V_65 , & V_62 ) < 0 ) {
F_89 ( L_6 ) ;
V_66 ++ ;
}
F_91 ( & V_60 . V_54 ) ;
do {
V_59 = V_67 ;
while ( F_92 ( V_68 , V_59 ) ) {
F_51 ( V_59 - V_68 ) ;
F_93 ( L_7 ) ;
if ( F_94 () )
goto V_69;
}
V_58 = V_59 + V_70 * V_39 ;
V_57 = V_68 ;
while ( F_92 ( V_68 , V_58 ) ) {
if ( ! F_95 ( & V_60 . V_55 ) ) {
F_87 ( & V_60 . V_55 , 1 ) ;
F_36 ( & V_60 . V_54 , F_86 ) ;
if ( V_68 - V_57 >
V_70 * V_39 - V_39 / 2 ) {
F_89 ( L_8 ) ;
V_71 ++ ;
}
V_57 = V_68 ;
}
F_93 ( L_7 ) ;
if ( F_94 () )
goto V_69;
}
while ( V_59 == V_67 &&
! F_96 () ) {
if ( F_97 ( & V_72 ) ) {
V_67 = V_68 +
V_73 * V_39 ;
V_74 ++ ;
F_98 ( & V_72 ) ;
break;
}
F_99 ( 1 ) ;
}
V_69: F_93 ( L_7 ) ;
} while ( ! F_94 () );
while ( ! F_96 () || F_95 ( & V_60 . V_55 ) ) {
F_100 ( L_7 ) ;
F_99 ( 1 ) ;
}
F_101 ( & V_60 . V_54 ) ;
F_102 ( L_7 ) ;
return 0 ;
}
static void F_103 ( struct V_31 * V_75 )
{
}
static int
F_104 ( void * V_56 )
{
int V_76 = 1 ;
int V_1 ;
int V_77 ;
struct V_31 * V_75 ;
if ( V_78 > 0 &&
V_79 > 0 &&
V_80 > 0 &&
V_33 -> V_81 &&
V_33 -> V_82 ) {
V_75 = F_105 ( sizeof( * V_75 ) *
V_83 * V_78 ) ;
V_76 = ! V_75 ;
}
if ( V_76 ) {
F_89 ( L_9 ) ;
goto V_84;
}
F_89 ( L_10 ) ;
do {
F_51 ( V_79 ) ;
F_106 ( & V_85 ) ;
F_71 ( F_107 ( V_64 ) ) ;
for ( V_1 = 0 ; V_1 < V_83 ; V_1 ++ ) {
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
V_33 -> V_81 ( & V_75 [ V_1 * V_78 + V_77 ] ,
F_103 ) ;
}
F_51 ( V_80 ) ;
F_71 ( F_107 ( V_64 ) ) ;
}
V_33 -> V_82 () ;
F_93 ( L_11 ) ;
} while ( ! F_94 () );
F_108 ( V_75 ) ;
V_84:
F_102 ( L_11 ) ;
return 0 ;
}
static int
F_109 ( void * V_56 )
{
unsigned long V_86 ;
int V_87 ;
F_89 ( L_12 ) ;
do {
V_86 = V_68 + V_88 * V_39 ;
while ( F_92 ( V_68 , V_86 ) &&
! F_96 () ) {
F_51 ( 1 ) ;
}
V_87 = V_89 ;
while ( V_87 > 0 &&
! F_96 () ) {
V_33 -> V_90 () ;
F_21 ( V_91 ) ;
V_87 -= V_91 ;
}
F_93 ( L_13 ) ;
} while ( ! F_94 () );
F_102 ( L_13 ) ;
return 0 ;
}
static int
F_110 ( void * V_56 )
{
bool V_92 = ! F_111 () && ! F_112 () ;
int V_93 = 0 ;
unsigned long V_94 ;
bool V_95 = V_96 , V_97 = V_98 , V_99 = V_100 ;
bool V_101 = V_102 ;
int V_1 ;
struct V_7 * V_23 ;
struct V_7 * V_28 ;
static F_113 ( rand ) ;
int V_103 [] = { V_104 , V_105 ,
V_106 , V_107 } ;
int V_108 = 0 ;
F_89 ( L_14 ) ;
if ( ! V_92 ) {
F_64 ( L_15 V_44
L_16 ,
V_43 , V_33 -> V_109 ) ;
F_64 ( L_15 V_44
L_17 ,
V_43 ) ;
}
if ( ! V_95 && ! V_97 && ! V_99 && ! V_101 )
V_95 = V_97 = V_99 = V_101 = true ;
if ( V_95 && V_33 -> V_110 && V_33 -> V_111 )
V_103 [ V_108 ++ ] = V_106 ;
else if ( V_96 && ( ! V_33 -> V_110 || ! V_33 -> V_111 ) )
F_64 ( L_18 ) ;
if ( V_97 && V_33 -> V_112 )
V_103 [ V_108 ++ ] = V_105 ;
else if ( V_98 && ! V_33 -> V_112 )
F_64 ( L_19 ) ;
if ( V_99 && V_33 -> V_34 )
V_103 [ V_108 ++ ] = V_104 ;
else if ( V_100 && ! V_33 -> V_34 )
F_64 ( L_20 ) ;
if ( V_101 && V_33 -> V_113 )
V_103 [ V_108 ++ ] = V_107 ;
else if ( V_102 && ! V_33 -> V_113 )
F_64 ( L_21 ) ;
if ( F_114 ( V_108 == 0 ,
L_22 ) ) {
V_2 = V_114 ;
F_102 ( L_23 ) ;
}
do {
V_2 = V_115 ;
F_99 ( 1 ) ;
V_23 = F_7 () ;
if ( V_23 == NULL )
continue;
V_23 -> V_24 = 0 ;
V_2 = V_116 ;
F_21 ( F_19 ( & rand ) & 0x3ff ) ;
V_2 = V_117 ;
V_28 = F_115 ( V_118 ,
V_64 == V_119 ) ;
V_23 -> V_27 = 1 ;
F_116 ( V_118 , V_23 ) ;
F_117 () ;
if ( V_28 ) {
V_1 = V_28 -> V_24 ;
if ( V_1 > V_25 )
V_1 = V_25 ;
F_10 ( & V_26 [ V_1 ] ) ;
V_28 -> V_24 ++ ;
switch ( V_103 [ F_19 ( & rand ) % V_108 ] ) {
case V_104 :
V_2 = V_104 ;
V_33 -> V_34 ( V_28 ) ;
break;
case V_105 :
V_2 = V_105 ;
V_33 -> V_112 () ;
F_28 ( V_28 ) ;
break;
case V_106 :
V_2 = V_106 ;
V_94 = V_33 -> V_110 () ;
V_1 = F_19 ( & rand ) % 16 ;
if ( V_1 != 0 )
F_51 ( V_1 ) ;
F_21 ( F_19 ( & rand ) % 1000 ) ;
V_2 = V_120 ;
V_33 -> V_111 ( V_94 ) ;
F_28 ( V_28 ) ;
break;
case V_107 :
V_2 = V_107 ;
V_33 -> V_113 () ;
F_28 ( V_28 ) ;
break;
default:
F_118 ( 1 ) ;
break;
}
}
F_119 ( ++ V_121 ) ;
if ( V_92 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_93 - 1 ) ) ) {
F_118 ( V_93 == 0 && F_111 () ) ;
if ( V_93 >= 0 )
F_120 () ;
else
F_121 () ;
if ( ++ V_93 > 3 )
V_93 = - V_93 ;
}
V_2 = V_122 ;
F_93 ( L_23 ) ;
} while ( ! F_94 () );
if ( V_93 > 0 )
V_93 = - V_93 ;
while ( V_92 && V_93 ++ < 0 )
F_121 () ;
F_118 ( V_92 && F_111 () ) ;
V_2 = V_114 ;
F_102 ( L_23 ) ;
return 0 ;
}
static int
F_122 ( void * V_56 )
{
F_113 ( rand ) ;
F_89 ( L_24 ) ;
F_123 ( V_64 , V_123 ) ;
do {
F_99 ( 1 + F_19 ( & rand ) % 10 ) ;
F_21 ( F_19 ( & rand ) & 0x3ff ) ;
if ( V_33 -> V_82 != NULL &&
F_19 ( & rand ) % ( V_124 * 8 ) == 0 ) {
V_33 -> V_82 () ;
} else if ( V_100 == V_98 ) {
if ( F_19 ( & rand ) & 0x80 )
V_33 -> V_113 () ;
else
V_33 -> V_112 () ;
} else if ( V_100 ) {
V_33 -> V_113 () ;
} else {
V_33 -> V_112 () ;
}
F_93 ( L_25 ) ;
} while ( ! F_94 () );
F_102 ( L_25 ) ;
return 0 ;
}
static void F_124 ( unsigned long V_125 )
{
int V_22 ;
unsigned long V_126 ;
unsigned long V_42 ;
static F_113 ( rand ) ;
static F_125 ( V_127 ) ;
struct V_7 * V_9 ;
int V_128 ;
unsigned long long V_4 ;
V_22 = V_33 -> V_129 () ;
if ( V_33 -> V_126 )
V_126 = V_33 -> V_126 () ;
else
V_126 = V_33 -> V_42 () ;
V_4 = F_4 () ;
V_9 = F_115 ( V_118 ,
F_126 () ||
F_127 () ||
F_128 ( T_7 ) ||
F_85 () ) ;
if ( V_9 == NULL ) {
V_33 -> V_130 ( V_22 ) ;
return;
}
if ( V_9 -> V_27 == 0 )
F_10 ( & V_131 ) ;
F_129 ( & V_127 ) ;
V_33 -> V_132 ( & rand ) ;
V_133 ++ ;
F_130 ( & V_127 ) ;
F_76 () ;
V_128 = V_9 -> V_24 ;
if ( V_128 > V_25 ) {
V_128 = V_25 ;
}
V_42 = V_33 -> V_42 () ;
if ( V_128 > 1 ) {
F_131 ( V_33 -> V_109 , & V_9 -> V_32 , V_4 ,
V_126 , V_42 ) ;
F_132 ( V_134 ) ;
}
F_133 ( V_135 [ V_128 ] ) ;
V_42 = V_42 - V_126 ;
if ( V_33 -> V_126 )
V_42 ++ ;
if ( V_42 > V_25 ) {
V_42 = V_25 ;
}
F_133 ( V_136 [ V_42 ] ) ;
F_78 () ;
V_33 -> V_130 ( V_22 ) ;
}
static int
F_134 ( void * V_56 )
{
unsigned long V_126 ;
unsigned long V_42 ;
int V_22 ;
F_113 ( rand ) ;
struct V_7 * V_9 ;
int V_128 ;
struct V_137 V_138 ;
unsigned long long V_4 ;
F_89 ( L_26 ) ;
F_123 ( V_64 , V_123 ) ;
if ( V_139 && V_33 -> V_140 )
F_135 ( & V_138 , F_124 , 0 ) ;
do {
if ( V_139 && V_33 -> V_140 ) {
if ( ! F_136 ( & V_138 ) )
F_137 ( & V_138 , V_68 + 1 ) ;
}
V_22 = V_33 -> V_129 () ;
if ( V_33 -> V_126 )
V_126 = V_33 -> V_126 () ;
else
V_126 = V_33 -> V_42 () ;
V_4 = F_4 () ;
V_9 = F_115 ( V_118 ,
F_126 () ||
F_127 () ||
F_128 ( T_7 ) ||
F_85 () ) ;
if ( V_9 == NULL ) {
V_33 -> V_130 ( V_22 ) ;
F_51 ( V_39 ) ;
continue;
}
if ( V_9 -> V_27 == 0 )
F_10 ( & V_131 ) ;
V_33 -> V_132 ( & rand ) ;
F_76 () ;
V_128 = V_9 -> V_24 ;
if ( V_128 > V_25 ) {
V_128 = V_25 ;
}
V_42 = V_33 -> V_42 () ;
if ( V_128 > 1 ) {
F_131 ( V_33 -> V_109 , & V_9 -> V_32 ,
V_4 , V_126 , V_42 ) ;
F_132 ( V_134 ) ;
}
F_133 ( V_135 [ V_128 ] ) ;
V_42 = V_42 - V_126 ;
if ( V_33 -> V_126 )
V_42 ++ ;
if ( V_42 > V_25 ) {
V_42 = V_25 ;
}
F_133 ( V_136 [ V_42 ] ) ;
F_78 () ;
V_33 -> V_130 ( V_22 ) ;
F_93 ( L_27 ) ;
} while ( ! F_94 () );
if ( V_139 && V_33 -> V_140 ) {
F_138 ( & V_138 ) ;
F_139 ( & V_138 ) ;
}
F_102 ( L_27 ) ;
return 0 ;
}
static void
F_140 ( void )
{
int V_41 ;
int V_1 ;
long V_141 [ V_25 + 1 ] = { 0 } ;
long V_142 [ V_25 + 1 ] = { 0 } ;
static unsigned long V_143 = V_144 ;
struct V_145 * V_146 ;
F_65 (cpu) {
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ ) {
V_141 [ V_1 ] += F_141 ( V_135 , V_41 ) [ V_1 ] ;
V_142 [ V_1 ] += F_141 ( V_136 , V_41 ) [ V_1 ] ;
}
}
for ( V_1 = V_25 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_141 [ V_1 ] != 0 )
break;
}
F_64 ( L_28 , V_43 , V_44 ) ;
F_67 ( L_29 ,
V_118 ,
V_121 ,
F_9 ( & V_11 ) ,
F_142 ( & V_13 ) ,
F_142 ( & V_12 ) ,
F_142 ( & V_16 ) ) ;
F_67 ( L_30 ,
F_142 ( & V_131 ) ,
V_147 ,
V_148 ,
V_66 ) ;
F_67 ( L_31 ,
V_71 ,
V_74 ,
V_133 ) ;
F_143 () ;
F_67 ( L_32 ,
V_149 ,
V_150 ,
V_147 ) ;
F_67 ( L_33 , F_144 ( & V_85 ) ) ;
F_64 ( L_28 , V_43 , V_44 ) ;
if ( F_142 ( & V_131 ) != 0 ||
V_147 != 0 ||
V_148 != 0 ||
V_66 != 0 ||
V_71 != 0 ||
V_1 > 1 ) {
F_67 ( L_15 , L_34 ) ;
F_10 ( & V_151 ) ;
F_118 ( 1 ) ;
}
F_67 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ )
F_67 ( L_36 , V_141 [ V_1 ] ) ;
F_67 ( L_4 ) ;
F_64 ( L_28 , V_43 , V_44 ) ;
F_67 ( L_37 ) ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ )
F_67 ( L_36 , V_142 [ V_1 ] ) ;
F_67 ( L_4 ) ;
F_64 ( L_28 , V_43 , V_44 ) ;
F_67 ( L_38 ) ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ ) {
F_67 ( L_39 , F_142 ( & V_26 [ V_1 ] ) ) ;
}
F_67 ( L_4 ) ;
if ( V_33 -> V_152 )
V_33 -> V_152 () ;
if ( V_143 == V_121 &&
V_118 != NULL ) {
int T_3 V_153 ;
unsigned long T_3 V_154 ;
unsigned long T_3 V_42 ;
F_145 ( V_33 -> V_155 ,
& V_153 , & V_154 , & V_42 ) ;
V_146 = F_2 ( V_119 ) ;
F_64 ( L_40 ,
F_1 () ,
V_2 ,
V_154 , V_42 , V_153 ,
V_146 == NULL ? ~ 0UL : V_146 -> V_156 ) ;
F_146 () ;
F_132 ( V_134 ) ;
}
V_143 = V_121 ;
}
static int
F_147 ( void * V_56 )
{
F_89 ( L_41 ) ;
do {
F_51 ( V_157 * V_39 ) ;
F_140 () ;
F_100 ( L_42 ) ;
} while ( ! F_94 () );
F_102 ( L_42 ) ;
return 0 ;
}
static inline void
F_148 ( struct V_158 * V_33 , const char * V_159 )
{
F_64 ( L_15 V_44
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51 ,
V_43 , V_159 , V_21 , V_124 ,
V_157 , V_160 , V_161 , V_162 ,
V_163 , V_139 , V_89 , V_91 , V_88 ,
V_164 , V_33 -> V_165 ,
V_73 , V_70 , V_166 ,
V_167 , V_168 ,
V_169 ,
V_170 , V_171 ) ;
}
static int F_149 ( unsigned int V_41 )
{
struct V_145 * V_138 ;
if ( V_172 [ V_41 ] == NULL )
return 0 ;
F_150 ( & V_72 ) ;
V_138 = V_172 [ V_41 ] ;
V_172 [ V_41 ] = NULL ;
F_98 ( & V_72 ) ;
F_151 ( F_88 , V_138 ) ;
return 0 ;
}
static int F_152 ( unsigned int V_41 )
{
int V_173 ;
if ( V_172 [ V_41 ] != NULL )
return 0 ;
F_150 ( & V_72 ) ;
F_89 ( L_52 ) ;
V_172 [ V_41 ] = F_153 ( F_88 , NULL ,
F_154 ( V_41 ) ,
L_7 ) ;
if ( F_155 ( V_172 [ V_41 ] ) ) {
V_173 = F_156 ( V_172 [ V_41 ] ) ;
F_89 ( L_53 ) ;
V_148 ++ ;
V_172 [ V_41 ] = NULL ;
F_98 ( & V_72 ) ;
return V_173 ;
}
F_157 ( V_172 [ V_41 ] , V_41 ) ;
F_158 ( V_172 [ V_41 ] ) ;
F_98 ( & V_72 ) ;
return 0 ;
}
static int F_159 ( void * args )
{
unsigned long V_174 ;
F_89 ( L_54 ) ;
if ( V_168 > 0 ) {
F_89 ( L_55 ) ;
F_51 ( V_168 * V_39 ) ;
F_89 ( L_56 ) ;
}
if ( ! F_96 () ) {
V_174 = F_160 () + V_167 ;
F_64 ( L_57 ) ;
F_17 () ;
F_76 () ;
while ( F_92 ( F_160 () , V_174 ) )
continue;
F_78 () ;
F_26 () ;
F_64 ( L_58 ) ;
}
F_100 ( L_59 ) ;
while ( ! F_96 () )
F_51 ( 10 * V_39 ) ;
return 0 ;
}
static int T_8 F_161 ( void )
{
if ( V_167 <= 0 )
return 0 ;
return F_162 ( F_159 , NULL , V_175 ) ;
}
static void F_163 ( struct V_31 * V_54 )
{
F_10 ( & V_176 ) ;
}
static int F_164 ( void * V_56 )
{
long V_177 = ( long ) V_56 ;
bool V_178 = 0 ;
bool V_179 ;
struct V_31 V_54 ;
F_91 ( & V_54 ) ;
F_89 ( L_60 ) ;
F_123 ( V_64 , V_123 ) ;
do {
F_165 ( V_180 [ V_177 ] ,
( V_179 =
F_95 ( & V_181 ) ) != V_178 ||
F_94 () ) ;
V_178 = V_179 ;
if ( F_94 () )
break;
F_166 () ;
V_33 -> V_81 ( & V_54 , F_163 ) ;
F_167 () ;
if ( F_168 ( & V_182 ) )
F_169 ( & V_183 ) ;
} while ( ! F_94 () );
if ( V_33 -> V_82 != NULL )
V_33 -> V_82 () ;
F_101 ( & V_54 ) ;
F_102 ( L_61 ) ;
return 0 ;
}
static int F_170 ( void * V_56 )
{
int V_1 ;
F_89 ( L_62 ) ;
do {
F_171 ( & V_176 , 0 ) ;
F_171 ( & V_182 , V_169 ) ;
F_87 ( & V_181 , ! V_181 ) ;
for ( V_1 = 0 ; V_1 < V_169 ; V_1 ++ )
F_169 ( & V_180 [ V_1 ] ) ;
F_165 ( V_183 ,
F_142 ( & V_182 ) == 0 ||
F_94 () ) ;
if ( F_94 () )
break;
V_150 ++ ;
V_33 -> V_82 () ;
if ( F_142 ( & V_176 ) != V_169 ) {
V_147 ++ ;
F_172 ( L_63 ,
F_142 ( & V_176 ) ,
V_169 ) ;
F_118 ( 1 ) ;
}
V_149 ++ ;
F_51 ( V_39 / 10 ) ;
} while ( ! F_94 () );
F_102 ( L_64 ) ;
return 0 ;
}
static int F_173 ( void )
{
int V_1 ;
int V_184 ;
if ( V_169 <= 0 )
return 0 ;
if ( V_33 -> V_81 == NULL || V_33 -> V_82 == NULL ) {
F_64 ( L_15 V_44
L_65 ,
V_43 , V_33 -> V_109 ) ;
F_64 ( L_15 V_44
L_66 ,
V_43 ) ;
return 0 ;
}
F_171 ( & V_182 , 0 ) ;
F_171 ( & V_176 , 0 ) ;
V_185 =
F_174 ( V_169 * sizeof( V_185 [ 0 ] ) ,
V_186 ) ;
V_180 =
F_174 ( V_169 * sizeof( V_180 [ 0 ] ) ,
V_186 ) ;
if ( V_185 == NULL || ! V_180 )
return - V_187 ;
for ( V_1 = 0 ; V_1 < V_169 ; V_1 ++ ) {
F_175 ( & V_180 [ V_1 ] ) ;
V_184 = F_162 ( F_164 ,
( void * ) ( long ) V_1 ,
V_185 [ V_1 ] ) ;
if ( V_184 )
return V_184 ;
}
return F_162 ( F_170 , NULL , V_188 ) ;
}
static void F_176 ( void )
{
int V_1 ;
F_151 ( F_170 , V_188 ) ;
if ( V_185 != NULL ) {
for ( V_1 = 0 ; V_1 < V_169 ; V_1 ++ )
F_151 ( F_164 ,
V_185 [ V_1 ] ) ;
F_177 ( V_185 ) ;
V_185 = NULL ;
}
if ( V_180 != NULL ) {
F_177 ( V_180 ) ;
V_180 = NULL ;
}
}
static void
F_178 ( void )
{
int V_1 ;
F_179 () ;
if ( F_180 () ) {
if ( V_33 -> V_82 != NULL )
V_33 -> V_82 () ;
return;
}
F_176 () ;
F_151 ( F_159 , V_175 ) ;
F_151 ( F_110 , V_119 ) ;
if ( V_189 ) {
for ( V_1 = 0 ; V_1 < V_21 ; V_1 ++ )
F_151 ( F_134 ,
V_189 [ V_1 ] ) ;
F_177 ( V_189 ) ;
}
V_118 = NULL ;
if ( V_190 ) {
for ( V_1 = 0 ; V_1 < V_124 ; V_1 ++ ) {
F_151 ( F_122 ,
V_190 [ V_1 ] ) ;
}
F_177 ( V_190 ) ;
V_190 = NULL ;
}
F_151 ( F_147 , V_191 ) ;
F_151 ( F_109 , V_192 ) ;
for ( V_1 = 0 ; V_1 < V_193 ; V_1 ++ )
F_151 ( F_104 , V_194 [ V_1 ] ) ;
if ( ( V_164 == 1 && V_33 -> V_165 ) ||
V_164 == 2 )
F_181 ( V_195 ) ;
if ( V_33 -> V_82 != NULL )
V_33 -> V_82 () ;
if ( V_33 -> V_196 != NULL )
V_33 -> V_196 () ;
F_140 () ;
if ( F_142 ( & V_151 ) || V_147 )
F_148 ( V_33 , L_67 ) ;
else if ( F_182 () )
F_148 ( V_33 ,
L_68 ) ;
else
F_148 ( V_33 , L_69 ) ;
F_183 () ;
}
static void F_184 ( struct V_31 * V_75 )
{
}
static void F_185 ( struct V_31 * V_75 )
{
F_64 ( L_70 ) ;
}
static void F_186 ( void )
{
#ifdef F_187
struct V_31 V_197 ;
struct V_31 V_198 ;
F_91 ( & V_197 ) ;
F_91 ( & V_198 ) ;
F_64 ( L_71 ) ;
F_76 () ;
F_17 () ;
F_36 ( & V_197 , F_184 ) ;
F_166 () ;
F_36 ( & V_198 , F_184 ) ;
F_36 ( & V_198 , F_185 ) ;
F_167 () ;
F_26 () ;
F_78 () ;
F_188 () ;
F_64 ( L_72 ) ;
F_101 ( & V_197 ) ;
F_101 ( & V_198 ) ;
#else
F_64 ( L_73 ) ;
#endif
}
static int T_8
F_189 ( void )
{
int V_1 ;
int V_41 ;
int V_199 = 0 ;
static struct V_158 * V_200 [] = {
& V_201 , & V_202 , & V_203 , & V_204 , & V_205 ,
& V_206 , V_207
} ;
if ( ! F_190 ( V_43 , V_160 , & V_208 ) )
return - V_209 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_200 ) ; V_1 ++ ) {
V_33 = V_200 [ V_1 ] ;
if ( strcmp ( V_43 , V_33 -> V_109 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_200 ) ) {
F_64 ( L_74 ,
V_43 ) ;
F_64 ( L_75 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_200 ) ; V_1 ++ )
F_64 ( L_76 , V_200 [ V_1 ] -> V_109 ) ;
F_64 ( L_4 ) ;
V_199 = - V_210 ;
goto V_211;
}
if ( V_33 -> V_90 == NULL && V_89 != 0 ) {
F_64 ( L_77 ) ;
V_89 = 0 ;
}
if ( V_33 -> V_212 )
V_33 -> V_212 () ;
if ( V_213 >= 0 ) {
V_21 = V_213 ;
} else {
V_21 = F_191 () - 2 - V_213 ;
if ( V_21 <= 0 )
V_21 = 1 ;
}
F_148 ( V_33 , L_78 ) ;
F_38 ( & V_11 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_214 ) ; V_1 ++ ) {
V_214 [ V_1 ] . V_27 = 0 ;
F_15 ( & V_214 [ V_1 ] . V_15 ,
& V_11 ) ;
}
V_118 = NULL ;
V_121 = 0 ;
F_171 ( & V_13 , 0 ) ;
F_171 ( & V_12 , 0 ) ;
F_171 ( & V_16 , 0 ) ;
F_171 ( & V_131 , 0 ) ;
F_171 ( & V_151 , 0 ) ;
V_147 = 0 ;
V_148 = 0 ;
V_66 = 0 ;
V_71 = 0 ;
V_74 = 0 ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ )
F_171 ( & V_26 [ V_1 ] , 0 ) ;
F_65 (cpu) {
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ ) {
F_141 ( V_135 , V_41 ) [ V_1 ] = 0 ;
F_141 ( V_136 , V_41 ) [ V_1 ] = 0 ;
}
}
V_199 = F_162 ( F_110 , NULL ,
V_119 ) ;
if ( V_199 )
goto V_211;
if ( V_124 > 0 ) {
V_190 = F_174 ( V_124 *
sizeof( V_190 [ 0 ] ) ,
V_186 ) ;
if ( V_190 == NULL ) {
F_192 ( L_79 ) ;
V_199 = - V_187 ;
goto V_211;
}
}
for ( V_1 = 0 ; V_1 < V_124 ; V_1 ++ ) {
V_199 = F_162 ( F_122 ,
NULL , V_190 [ V_1 ] ) ;
if ( V_199 )
goto V_211;
}
V_189 = F_174 ( V_21 * sizeof( V_189 [ 0 ] ) ,
V_186 ) ;
if ( V_189 == NULL ) {
F_192 ( L_79 ) ;
V_199 = - V_187 ;
goto V_211;
}
for ( V_1 = 0 ; V_1 < V_21 ; V_1 ++ ) {
V_199 = F_162 ( F_134 , NULL ,
V_189 [ V_1 ] ) ;
if ( V_199 )
goto V_211;
}
if ( V_157 > 0 ) {
V_199 = F_162 ( F_147 , NULL ,
V_191 ) ;
if ( V_199 )
goto V_211;
}
if ( V_161 && V_162 > 0 ) {
V_199 = F_193 ( V_162 * V_39 ) ;
if ( V_199 )
goto V_211;
}
if ( V_163 < 0 )
V_163 = 0 ;
if ( V_163 ) {
V_199 = F_194 ( V_163 * V_39 ) ;
if ( V_199 )
goto V_211;
}
if ( V_89 < 0 )
V_89 = 0 ;
if ( V_89 ) {
V_199 = F_162 ( F_109 , NULL ,
V_192 ) ;
if ( V_199 )
goto V_211;
}
if ( V_73 < 1 )
V_73 = 1 ;
if ( V_70 < 2 )
V_70 = 2 ;
if ( ( V_164 == 1 && V_33 -> V_165 ) ||
V_164 == 2 ) {
V_67 = V_68 + V_73 * V_39 ;
V_199 = F_195 ( V_215 , L_80 ,
F_152 ,
F_149 ) ;
if ( V_199 < 0 )
goto V_211;
V_195 = V_199 ;
}
V_199 = F_196 ( V_166 , F_178 ) ;
if ( V_199 )
goto V_211;
V_199 = F_197 ( V_171 * V_39 , V_170 * V_39 ) ;
if ( V_199 )
goto V_211;
V_199 = F_161 () ;
if ( V_199 )
goto V_211;
V_199 = F_173 () ;
if ( V_199 )
goto V_211;
if ( V_216 )
F_186 () ;
if ( V_83 > 0 ) {
V_193 = ( F_191 () + 3 ) / 4 ;
V_194 = F_198 ( V_193 , sizeof( * V_194 ) ,
V_186 ) ;
if ( ! V_194 ) {
F_192 ( L_79 ) ;
V_199 = - V_187 ;
goto V_211;
}
for ( V_1 = 0 ; V_1 < V_193 ; V_1 ++ ) {
V_199 = F_162 ( F_104 ,
NULL ,
V_194 [ V_1 ] ) ;
if ( V_199 )
goto V_211;
}
}
F_179 () ;
F_199 () ;
return 0 ;
V_211:
F_199 () ;
F_178 () ;
return V_199 ;
}
