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
bool V_92 = ! F_111 () ;
int V_93 = 0 ;
unsigned long V_94 ;
bool V_95 = V_96 , V_97 = V_98 , V_99 = V_100 ;
bool V_101 = V_102 ;
int V_1 ;
struct V_7 * V_23 ;
struct V_7 * V_28 ;
static F_112 ( rand ) ;
int V_103 [] = { V_104 , V_105 ,
V_106 , V_107 } ;
int V_108 = 0 ;
F_89 ( L_14 ) ;
F_64 ( L_15 V_44
L_16 ,
V_43 , V_33 -> V_109 ) ;
F_64 ( L_15 V_44
L_17 ,
V_43 ) ;
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
if ( F_113 ( V_108 == 0 ,
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
V_28 = F_114 ( V_118 ,
V_64 == V_119 ) ;
V_23 -> V_27 = 1 ;
F_115 ( V_118 , V_23 ) ;
F_116 () ;
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
F_117 ( 1 ) ;
break;
}
}
F_118 ( ++ V_121 ) ;
if ( V_92 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_93 - 1 ) ) ) {
F_117 ( V_93 == 0 && F_111 () ) ;
if ( V_93 >= 0 )
F_119 () ;
else
F_120 () ;
if ( ++ V_93 > 3 )
V_93 = - V_93 ;
}
V_2 = V_122 ;
F_93 ( L_23 ) ;
} while ( ! F_94 () );
if ( V_93 > 0 )
V_93 = - V_93 ;
while ( V_92 && V_93 ++ < 0 )
F_120 () ;
F_117 ( V_92 && F_111 () ) ;
V_2 = V_114 ;
F_102 ( L_23 ) ;
return 0 ;
}
static int
F_121 ( void * V_56 )
{
F_112 ( rand ) ;
F_89 ( L_24 ) ;
F_122 ( V_64 , V_123 ) ;
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
static void F_123 ( void )
{
static T_8 V_125 = F_124 ( 0 ) ;
if ( F_125 ( & V_125 ) )
return;
if ( F_126 ( & V_125 , 1 ) != 0 )
return;
F_127 ( V_126 ) ;
}
static void F_128 ( unsigned long V_127 )
{
int V_22 ;
unsigned long V_128 ;
unsigned long V_42 ;
static F_112 ( rand ) ;
static F_129 ( V_129 ) ;
struct V_7 * V_9 ;
int V_130 ;
unsigned long long V_4 ;
V_22 = V_33 -> V_131 () ;
if ( V_33 -> V_128 )
V_128 = V_33 -> V_128 () ;
else
V_128 = V_33 -> V_42 () ;
V_4 = F_4 () ;
V_9 = F_114 ( V_118 ,
F_130 () ||
F_131 () ||
F_132 ( T_7 ) ||
F_85 () ) ;
if ( V_9 == NULL ) {
V_33 -> V_132 ( V_22 ) ;
return;
}
if ( V_9 -> V_27 == 0 )
F_10 ( & V_133 ) ;
F_133 ( & V_129 ) ;
V_33 -> V_134 ( & rand ) ;
V_135 ++ ;
F_134 ( & V_129 ) ;
F_76 () ;
V_130 = V_9 -> V_24 ;
if ( V_130 > V_25 ) {
V_130 = V_25 ;
}
V_42 = V_33 -> V_42 () ;
if ( V_130 > 1 ) {
F_135 ( V_33 -> V_109 , & V_9 -> V_32 , V_4 ,
V_128 , V_42 ) ;
F_123 () ;
}
F_136 ( V_136 [ V_130 ] ) ;
V_42 = V_42 - V_128 ;
if ( V_33 -> V_128 )
V_42 ++ ;
if ( V_42 > V_25 ) {
V_42 = V_25 ;
}
F_136 ( V_137 [ V_42 ] ) ;
F_78 () ;
V_33 -> V_132 ( V_22 ) ;
}
static int
F_137 ( void * V_56 )
{
unsigned long V_128 ;
unsigned long V_42 ;
int V_22 ;
F_112 ( rand ) ;
struct V_7 * V_9 ;
int V_130 ;
struct V_138 V_139 ;
unsigned long long V_4 ;
F_89 ( L_26 ) ;
F_122 ( V_64 , V_123 ) ;
if ( V_140 && V_33 -> V_141 )
F_138 ( & V_139 , F_128 , 0 ) ;
do {
if ( V_140 && V_33 -> V_141 ) {
if ( ! F_139 ( & V_139 ) )
F_140 ( & V_139 , V_68 + 1 ) ;
}
V_22 = V_33 -> V_131 () ;
if ( V_33 -> V_128 )
V_128 = V_33 -> V_128 () ;
else
V_128 = V_33 -> V_42 () ;
V_4 = F_4 () ;
V_9 = F_114 ( V_118 ,
F_130 () ||
F_131 () ||
F_132 ( T_7 ) ||
F_85 () ) ;
if ( V_9 == NULL ) {
V_33 -> V_132 ( V_22 ) ;
F_51 ( V_39 ) ;
continue;
}
if ( V_9 -> V_27 == 0 )
F_10 ( & V_133 ) ;
V_33 -> V_134 ( & rand ) ;
F_76 () ;
V_130 = V_9 -> V_24 ;
if ( V_130 > V_25 ) {
V_130 = V_25 ;
}
V_42 = V_33 -> V_42 () ;
if ( V_130 > 1 ) {
F_135 ( V_33 -> V_109 , & V_9 -> V_32 ,
V_4 , V_128 , V_42 ) ;
F_123 () ;
}
F_136 ( V_136 [ V_130 ] ) ;
V_42 = V_42 - V_128 ;
if ( V_33 -> V_128 )
V_42 ++ ;
if ( V_42 > V_25 ) {
V_42 = V_25 ;
}
F_136 ( V_137 [ V_42 ] ) ;
F_78 () ;
V_33 -> V_132 ( V_22 ) ;
F_93 ( L_27 ) ;
} while ( ! F_94 () );
if ( V_140 && V_33 -> V_141 ) {
F_141 ( & V_139 ) ;
F_142 ( & V_139 ) ;
}
F_102 ( L_27 ) ;
return 0 ;
}
static void
F_143 ( void )
{
int V_41 ;
int V_1 ;
long V_142 [ V_25 + 1 ] = { 0 } ;
long V_143 [ V_25 + 1 ] = { 0 } ;
static unsigned long V_144 = V_145 ;
F_65 (cpu) {
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ ) {
V_142 [ V_1 ] += F_144 ( V_136 , V_41 ) [ V_1 ] ;
V_143 [ V_1 ] += F_144 ( V_137 , V_41 ) [ V_1 ] ;
}
}
for ( V_1 = V_25 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_142 [ V_1 ] != 0 )
break;
}
F_64 ( L_28 , V_43 , V_44 ) ;
F_67 ( L_29 ,
V_118 ,
V_121 ,
F_9 ( & V_11 ) ,
F_125 ( & V_13 ) ,
F_125 ( & V_12 ) ,
F_125 ( & V_16 ) ) ;
F_67 ( L_30 ,
F_125 ( & V_133 ) ,
V_146 ,
V_66 ) ;
F_67 ( L_31 ,
V_71 ,
V_74 ,
V_135 ) ;
F_145 () ;
F_67 ( L_32 ,
V_147 ,
V_148 ,
V_149 ) ;
F_67 ( L_33 , F_146 ( & V_85 ) ) ;
F_64 ( L_28 , V_43 , V_44 ) ;
if ( F_125 ( & V_133 ) != 0 ||
V_149 != 0 ||
V_146 != 0 ||
V_66 != 0 ||
V_71 != 0 ||
V_1 > 1 ) {
F_67 ( L_15 , L_34 ) ;
F_10 ( & V_150 ) ;
F_117 ( 1 ) ;
}
F_67 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ )
F_67 ( L_36 , V_142 [ V_1 ] ) ;
F_67 ( L_4 ) ;
F_64 ( L_28 , V_43 , V_44 ) ;
F_67 ( L_37 ) ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ )
F_67 ( L_36 , V_143 [ V_1 ] ) ;
F_67 ( L_4 ) ;
F_64 ( L_28 , V_43 , V_44 ) ;
F_67 ( L_38 ) ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ ) {
F_67 ( L_39 , F_125 ( & V_26 [ V_1 ] ) ) ;
}
F_67 ( L_4 ) ;
if ( V_33 -> V_151 )
V_33 -> V_151 () ;
if ( V_144 == V_121 &&
V_118 != NULL ) {
int T_3 V_152 ;
unsigned long T_3 V_153 ;
unsigned long T_3 V_42 ;
F_147 ( V_33 -> V_154 ,
& V_152 , & V_153 , & V_42 ) ;
F_64 ( L_40 ,
F_1 () ,
V_2 ,
V_153 , V_42 , V_152 ) ;
F_148 () ;
F_123 () ;
}
V_144 = V_121 ;
}
static int
F_149 ( void * V_56 )
{
F_89 ( L_41 ) ;
do {
F_51 ( V_155 * V_39 ) ;
F_143 () ;
F_100 ( L_42 ) ;
} while ( ! F_94 () );
F_102 ( L_42 ) ;
return 0 ;
}
static inline void
F_150 ( struct V_156 * V_33 , const char * V_157 )
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
V_43 , V_157 , V_21 , V_124 ,
V_155 , V_158 , V_159 , V_160 ,
V_161 , V_140 , V_89 , V_91 , V_88 ,
V_162 , V_33 -> V_163 ,
V_73 , V_70 , V_164 ,
V_165 , V_166 ,
V_167 ,
V_168 , V_169 ) ;
}
static void F_151 ( int V_41 )
{
struct V_170 * V_139 ;
if ( V_171 [ V_41 ] == NULL )
return;
F_152 ( & V_72 ) ;
V_139 = V_171 [ V_41 ] ;
V_171 [ V_41 ] = NULL ;
F_98 ( & V_72 ) ;
F_153 ( F_88 , V_139 ) ;
}
static int F_154 ( int V_41 )
{
int V_172 ;
if ( V_171 [ V_41 ] != NULL )
return 0 ;
F_152 ( & V_72 ) ;
F_89 ( L_52 ) ;
V_171 [ V_41 ] = F_155 ( F_88 , NULL ,
F_156 ( V_41 ) ,
L_7 ) ;
if ( F_157 ( V_171 [ V_41 ] ) ) {
V_172 = F_158 ( V_171 [ V_41 ] ) ;
F_89 ( L_53 ) ;
V_146 ++ ;
V_171 [ V_41 ] = NULL ;
F_98 ( & V_72 ) ;
return V_172 ;
}
F_159 ( V_171 [ V_41 ] , V_41 ) ;
F_160 ( V_171 [ V_41 ] ) ;
F_98 ( & V_72 ) ;
return 0 ;
}
static int F_161 ( void * args )
{
unsigned long V_173 ;
F_89 ( L_54 ) ;
if ( V_166 > 0 ) {
F_89 ( L_55 ) ;
F_51 ( V_166 * V_39 ) ;
F_89 ( L_56 ) ;
}
if ( ! F_96 () ) {
V_173 = F_162 () + V_165 ;
F_64 ( L_57 ) ;
F_17 () ;
F_76 () ;
while ( F_92 ( F_162 () , V_173 ) )
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
static int T_9 F_163 ( void )
{
if ( V_165 <= 0 )
return 0 ;
return F_164 ( F_161 , NULL , V_174 ) ;
}
static void F_165 ( struct V_31 * V_54 )
{
F_10 ( & V_175 ) ;
}
static int F_166 ( void * V_56 )
{
long V_176 = ( long ) V_56 ;
bool V_177 = 0 ;
bool V_178 ;
struct V_31 V_54 ;
F_91 ( & V_54 ) ;
F_89 ( L_60 ) ;
F_122 ( V_64 , V_123 ) ;
do {
F_167 ( V_179 [ V_176 ] ,
( V_178 =
F_95 ( & V_180 ) ) != V_177 ||
F_94 () ) ;
V_177 = V_178 ;
if ( F_94 () )
break;
V_33 -> V_81 ( & V_54 , F_165 ) ;
if ( F_168 ( & V_181 ) )
F_169 ( & V_182 ) ;
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
F_171 ( & V_175 , 0 ) ;
F_171 ( & V_181 , V_167 ) ;
F_87 ( & V_180 , ! V_180 ) ;
for ( V_1 = 0 ; V_1 < V_167 ; V_1 ++ )
F_169 ( & V_179 [ V_1 ] ) ;
F_167 ( V_182 ,
F_125 ( & V_181 ) == 0 ||
F_94 () ) ;
if ( F_94 () )
break;
V_148 ++ ;
V_33 -> V_82 () ;
if ( F_125 ( & V_175 ) != V_167 ) {
V_149 ++ ;
F_172 ( L_63 ,
F_125 ( & V_175 ) ,
V_167 ) ;
F_117 ( 1 ) ;
}
V_147 ++ ;
F_51 ( V_39 / 10 ) ;
} while ( ! F_94 () );
F_102 ( L_64 ) ;
return 0 ;
}
static int F_173 ( void )
{
int V_1 ;
int V_183 ;
if ( V_167 <= 0 )
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
F_171 ( & V_181 , 0 ) ;
F_171 ( & V_175 , 0 ) ;
V_184 =
F_174 ( V_167 * sizeof( V_184 [ 0 ] ) ,
V_185 ) ;
V_179 =
F_174 ( V_167 * sizeof( V_179 [ 0 ] ) ,
V_185 ) ;
if ( V_184 == NULL || ! V_179 )
return - V_186 ;
for ( V_1 = 0 ; V_1 < V_167 ; V_1 ++ ) {
F_175 ( & V_179 [ V_1 ] ) ;
V_183 = F_164 ( F_166 ,
( void * ) ( long ) V_1 ,
V_184 [ V_1 ] ) ;
if ( V_183 )
return V_183 ;
}
return F_164 ( F_170 , NULL , V_187 ) ;
}
static void F_176 ( void )
{
int V_1 ;
F_153 ( F_170 , V_187 ) ;
if ( V_184 != NULL ) {
for ( V_1 = 0 ; V_1 < V_167 ; V_1 ++ )
F_153 ( F_166 ,
V_184 [ V_1 ] ) ;
F_177 ( V_184 ) ;
V_184 = NULL ;
}
if ( V_179 != NULL ) {
F_177 ( V_179 ) ;
V_179 = NULL ;
}
}
static int F_178 ( struct V_188 * V_189 ,
unsigned long V_190 , void * V_191 )
{
long V_41 = ( long ) V_191 ;
switch ( V_190 ) {
case V_192 :
case V_193 :
( void ) F_154 ( V_41 ) ;
break;
case V_194 :
F_151 ( V_41 ) ;
break;
default:
break;
}
return V_195 ;
}
static void
F_179 ( void )
{
int V_1 ;
F_180 () ;
if ( F_181 () ) {
if ( V_33 -> V_82 != NULL )
V_33 -> V_82 () ;
return;
}
F_176 () ;
F_153 ( F_161 , V_174 ) ;
F_153 ( F_110 , V_119 ) ;
if ( V_196 ) {
for ( V_1 = 0 ; V_1 < V_21 ; V_1 ++ )
F_153 ( F_137 ,
V_196 [ V_1 ] ) ;
F_177 ( V_196 ) ;
}
V_118 = NULL ;
if ( V_197 ) {
for ( V_1 = 0 ; V_1 < V_124 ; V_1 ++ ) {
F_153 ( F_121 ,
V_197 [ V_1 ] ) ;
}
F_177 ( V_197 ) ;
V_197 = NULL ;
}
F_153 ( F_149 , V_198 ) ;
F_153 ( F_109 , V_199 ) ;
for ( V_1 = 0 ; V_1 < V_200 ; V_1 ++ )
F_153 ( F_104 , V_201 [ V_1 ] ) ;
if ( ( V_162 == 1 && V_33 -> V_163 ) ||
V_162 == 2 ) {
F_182 ( & V_202 ) ;
F_65 (i)
F_151 ( V_1 ) ;
}
if ( V_33 -> V_82 != NULL )
V_33 -> V_82 () ;
if ( V_33 -> V_203 != NULL )
V_33 -> V_203 () ;
F_143 () ;
if ( F_125 ( & V_150 ) || V_149 )
F_150 ( V_33 , L_67 ) ;
else if ( F_183 () )
F_150 ( V_33 ,
L_68 ) ;
else
F_150 ( V_33 , L_69 ) ;
F_184 () ;
}
static void F_185 ( struct V_31 * V_75 )
{
}
static void F_186 ( struct V_31 * V_75 )
{
F_64 ( L_70 ) ;
}
static void F_187 ( void )
{
#ifdef F_188
struct V_31 V_204 ;
struct V_31 V_205 ;
F_91 ( & V_204 ) ;
F_91 ( & V_205 ) ;
F_64 ( L_71 ) ;
F_76 () ;
F_17 () ;
F_36 ( & V_204 , F_185 ) ;
F_189 () ;
F_36 ( & V_205 , F_185 ) ;
F_36 ( & V_205 , F_186 ) ;
F_190 () ;
F_26 () ;
F_78 () ;
F_191 () ;
F_64 ( L_72 ) ;
F_101 ( & V_204 ) ;
F_101 ( & V_205 ) ;
#else
F_64 ( L_73 ) ;
#endif
}
static int T_9
F_192 ( void )
{
int V_1 ;
int V_41 ;
int V_206 = 0 ;
static struct V_156 * V_207 [] = {
& V_208 , & V_209 , & V_210 , & V_211 , & V_212 ,
& V_213 , V_214
} ;
if ( ! F_193 ( V_43 , V_158 , & V_215 ) )
return - V_216 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_207 ) ; V_1 ++ ) {
V_33 = V_207 [ V_1 ] ;
if ( strcmp ( V_43 , V_33 -> V_109 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_207 ) ) {
F_64 ( L_74 ,
V_43 ) ;
F_64 ( L_75 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_207 ) ; V_1 ++ )
F_64 ( L_76 , V_207 [ V_1 ] -> V_109 ) ;
F_64 ( L_4 ) ;
V_206 = - V_217 ;
goto V_218;
}
if ( V_33 -> V_90 == NULL && V_89 != 0 ) {
F_64 ( L_77 ) ;
V_89 = 0 ;
}
if ( V_33 -> V_219 )
V_33 -> V_219 () ;
if ( V_220 >= 0 ) {
V_21 = V_220 ;
} else {
V_21 = F_194 () - 2 - V_220 ;
if ( V_21 <= 0 )
V_21 = 1 ;
}
F_150 ( V_33 , L_78 ) ;
F_38 ( & V_11 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_221 ) ; V_1 ++ ) {
V_221 [ V_1 ] . V_27 = 0 ;
F_15 ( & V_221 [ V_1 ] . V_15 ,
& V_11 ) ;
}
V_118 = NULL ;
V_121 = 0 ;
F_171 ( & V_13 , 0 ) ;
F_171 ( & V_12 , 0 ) ;
F_171 ( & V_16 , 0 ) ;
F_171 ( & V_133 , 0 ) ;
F_171 ( & V_150 , 0 ) ;
V_149 = 0 ;
V_146 = 0 ;
V_66 = 0 ;
V_71 = 0 ;
V_74 = 0 ;
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ )
F_171 ( & V_26 [ V_1 ] , 0 ) ;
F_65 (cpu) {
for ( V_1 = 0 ; V_1 < V_25 + 1 ; V_1 ++ ) {
F_144 ( V_136 , V_41 ) [ V_1 ] = 0 ;
F_144 ( V_137 , V_41 ) [ V_1 ] = 0 ;
}
}
V_206 = F_164 ( F_110 , NULL ,
V_119 ) ;
if ( V_206 )
goto V_218;
if ( V_124 > 0 ) {
V_197 = F_174 ( V_124 *
sizeof( V_197 [ 0 ] ) ,
V_185 ) ;
if ( V_197 == NULL ) {
F_195 ( L_79 ) ;
V_206 = - V_186 ;
goto V_218;
}
}
for ( V_1 = 0 ; V_1 < V_124 ; V_1 ++ ) {
V_206 = F_164 ( F_121 ,
NULL , V_197 [ V_1 ] ) ;
if ( V_206 )
goto V_218;
}
V_196 = F_174 ( V_21 * sizeof( V_196 [ 0 ] ) ,
V_185 ) ;
if ( V_196 == NULL ) {
F_195 ( L_79 ) ;
V_206 = - V_186 ;
goto V_218;
}
for ( V_1 = 0 ; V_1 < V_21 ; V_1 ++ ) {
V_206 = F_164 ( F_137 , NULL ,
V_196 [ V_1 ] ) ;
if ( V_206 )
goto V_218;
}
if ( V_155 > 0 ) {
V_206 = F_164 ( F_149 , NULL ,
V_198 ) ;
if ( V_206 )
goto V_218;
}
if ( V_159 && V_160 > 0 ) {
V_206 = F_196 ( V_160 * V_39 ) ;
if ( V_206 )
goto V_218;
}
if ( V_161 < 0 )
V_161 = 0 ;
if ( V_161 ) {
V_206 = F_197 ( V_161 * V_39 ) ;
if ( V_206 )
goto V_218;
}
if ( V_89 < 0 )
V_89 = 0 ;
if ( V_89 ) {
V_206 = F_164 ( F_109 , NULL ,
V_199 ) ;
if ( V_206 )
goto V_218;
}
if ( V_73 < 1 )
V_73 = 1 ;
if ( V_70 < 2 )
V_70 = 2 ;
if ( ( V_162 == 1 && V_33 -> V_163 ) ||
V_162 == 2 ) {
V_67 = V_68 + V_73 * V_39 ;
F_198 ( & V_202 ) ;
F_65 (i) {
if ( F_199 ( V_1 ) )
continue;
V_206 = F_154 ( V_1 ) ;
if ( V_206 )
goto V_218;
}
}
V_206 = F_200 ( V_164 , F_179 ) ;
if ( V_206 )
goto V_218;
V_206 = F_201 ( V_169 * V_39 , V_168 * V_39 ) ;
if ( V_206 )
goto V_218;
V_206 = F_163 () ;
if ( V_206 )
goto V_218;
V_206 = F_173 () ;
if ( V_206 )
goto V_218;
if ( V_222 )
F_187 () ;
if ( V_83 > 0 ) {
V_200 = ( F_194 () + 3 ) / 4 ;
V_201 = F_202 ( V_200 , sizeof( * V_201 ) ,
V_185 ) ;
if ( ! V_201 ) {
F_195 ( L_79 ) ;
V_206 = - V_186 ;
goto V_218;
}
for ( V_1 = 0 ; V_1 < V_200 ; V_1 ++ ) {
V_206 = F_164 ( F_104 ,
NULL ,
V_201 [ V_1 ] ) ;
if ( V_206 )
goto V_218;
}
}
F_180 () ;
F_203 () ;
return 0 ;
V_218:
F_203 () ;
F_179 () ;
return V_206 ;
}
