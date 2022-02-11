static T_1 T_2 F_1 ( void )
{
T_1 V_1 = F_2 () ;
unsigned long T_3 V_2 = F_3 ( V_1 , V_3 ) ;
return V_1 ;
}
static T_1 T_2 F_1 ( void )
{
return 0ULL ;
}
static struct V_4 *
F_4 ( void )
{
struct V_5 * V_6 ;
F_5 ( & V_7 ) ;
if ( F_6 ( & V_8 ) ) {
F_7 ( & V_9 ) ;
F_8 ( & V_7 ) ;
return NULL ;
}
F_7 ( & V_10 ) ;
V_6 = V_8 . V_11 ;
F_9 ( V_6 ) ;
F_8 ( & V_7 ) ;
return F_10 ( V_6 , struct V_4 , V_12 ) ;
}
static void
F_11 ( struct V_4 * V_6 )
{
F_7 ( & V_13 ) ;
F_5 ( & V_7 ) ;
F_12 ( & V_6 -> V_12 , & V_8 ) ;
F_8 ( & V_7 ) ;
}
static int F_13 ( void ) __acquires( T_4 )
{
F_14 () ;
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
const unsigned long V_16 = 200 ;
const unsigned long V_17 = 50 ;
if ( ! ( F_16 ( V_15 ) % ( V_18 * 2000 * V_17 ) ) )
F_17 ( V_17 ) ;
if ( ! ( F_16 ( V_15 ) % ( V_18 * 2 * V_16 ) ) )
F_18 ( V_16 ) ;
#ifdef F_19
if ( ! F_20 () &&
! ( F_16 ( V_15 ) % ( V_18 * 20000 ) ) )
F_21 () ;
#endif
}
static void F_22 ( int V_19 ) __releases( T_4 )
{
F_23 () ;
}
static bool
F_24 ( struct V_4 * V_20 )
{
int V_21 ;
V_21 = V_20 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
if ( ++ V_20 -> V_22 >= V_23 ) {
V_20 -> V_25 = 0 ;
return true ;
}
return false ;
}
static void
F_25 ( struct V_4 * V_26 )
{
struct V_4 * V_20 ;
struct V_4 * V_27 ;
if ( V_26 )
F_26 ( & V_26 -> V_12 , & V_28 ) ;
F_27 (rp, rp1, &rcu_torture_removed, rtort_free) {
if ( F_24 ( V_20 ) ) {
F_28 ( & V_20 -> V_12 ) ;
F_11 ( V_20 ) ;
}
}
}
static void
F_29 ( struct V_29 * V_6 )
{
struct V_4 * V_20 = F_10 ( V_6 , struct V_4 , V_30 ) ;
if ( F_30 () ) {
return;
}
if ( F_24 ( V_20 ) )
F_11 ( V_20 ) ;
else
V_31 -> V_32 ( V_20 ) ;
}
static unsigned long F_31 ( void )
{
return 0 ;
}
static void F_32 ( struct V_4 * V_6 )
{
F_33 ( & V_6 -> V_30 , F_29 ) ;
}
static void F_34 ( void )
{
F_35 ( & V_28 ) ;
}
static int F_36 ( void ) __acquires( T_5 )
{
F_37 () ;
return 0 ;
}
static void F_38 ( int V_19 ) __releases( T_5 )
{
F_39 () ;
}
static void F_40 ( struct V_4 * V_6 )
{
F_41 ( & V_6 -> V_30 , F_29 ) ;
}
static void F_42 ( struct V_4 * V_6 )
{
F_29 ( & V_6 -> V_30 ) ;
}
static void F_43 ( void )
{
}
static void
F_44 ( struct V_29 * V_33 , void (* F_45)( struct V_29 * V_34 ) )
{
F_45 ( V_33 ) ;
}
static int F_46 ( void ) __acquires( T_6 )
{
return F_47 ( T_6 ) ;
}
static void F_48 ( struct V_14 * V_15 )
{
long V_35 ;
const long V_36 = 1000000 / V_37 ;
const long V_38 = 10 ;
V_35 = F_16 ( V_15 ) %
( V_18 * 2 * V_38 * V_36 ) ;
if ( ! V_35 )
F_49 ( V_38 ) ;
else
F_15 ( V_15 ) ;
}
static void F_50 ( int V_19 ) __releases( T_6 )
{
F_51 ( T_6 , V_19 ) ;
}
static unsigned long F_52 ( void )
{
return F_53 ( T_6 ) ;
}
static void F_54 ( struct V_4 * V_20 )
{
F_55 ( T_6 , & V_20 -> V_30 , F_29 ) ;
}
static void F_56 ( void )
{
F_57 ( T_6 ) ;
}
static void F_58 ( struct V_29 * V_33 ,
void (* F_45)( struct V_29 * V_33 ) )
{
F_55 ( T_6 , V_33 , F_45 ) ;
}
static void F_59 ( void )
{
F_60 ( T_6 ) ;
}
static void F_61 ( void )
{
int V_39 ;
int V_19 = T_6 -> V_40 & 0x1 ;
F_62 ( L_1 ,
V_41 , V_42 , V_19 ) ;
F_63 (cpu) {
long V_43 , V_44 ;
V_43 = ( long ) F_64 ( T_6 -> V_45 , V_39 ) -> V_46 [ ! V_19 ] ;
V_44 = ( long ) F_64 ( T_6 -> V_45 , V_39 ) -> V_46 [ V_19 ] ;
F_65 ( L_2 , V_39 , V_43 , V_44 ) ;
}
F_65 ( L_3 ) ;
}
static void F_66 ( void )
{
F_67 ( T_6 ) ;
}
static void F_68 ( void )
{
F_34 () ;
F_69 ( F_70 ( & V_47 ) ) ;
T_6 = & V_47 ;
}
static void F_71 ( void )
{
F_72 ( & V_47 ) ;
T_6 = & V_48 ;
}
static int F_73 ( void )
{
F_74 () ;
return 0 ;
}
static void F_75 ( int V_19 )
{
F_76 () ;
}
static void F_77 ( struct V_4 * V_6 )
{
F_78 ( & V_6 -> V_30 , F_29 ) ;
}
static int F_79 ( void )
{
return 0 ;
}
static void F_80 ( int V_19 )
{
}
static void F_81 ( struct V_4 * V_6 )
{
F_82 ( & V_6 -> V_30 , F_29 ) ;
}
static bool T_3 F_83 ( void )
{
return V_31 == & V_49 ;
}
static bool F_83 ( void )
{
return false ;
}
static void F_84 ( struct V_29 * V_33 )
{
struct V_50 * V_51 =
F_10 ( V_33 , struct V_50 , V_34 ) ;
F_85 ( & V_51 -> V_52 , 0 ) ;
}
static int F_86 ( void * V_53 )
{
unsigned long V_54 ;
unsigned long V_55 ;
unsigned long V_56 ;
struct V_50 V_57 = { . V_52 = 0 } ;
struct V_58 V_59 ;
F_87 ( L_4 ) ;
V_59 . V_60 = 1 ;
if ( F_88 ( V_61 , V_62 , & V_59 ) < 0 ) {
F_87 ( L_5 ) ;
V_63 ++ ;
}
F_89 ( & V_57 . V_34 ) ;
do {
V_56 = V_64 ;
while ( F_90 ( V_65 , V_56 ) ) {
F_49 ( V_56 - V_65 ) ;
F_91 ( L_6 ) ;
if ( F_92 () )
goto V_66;
}
V_55 = V_56 + V_67 * V_37 ;
V_54 = V_65 ;
while ( F_90 ( V_65 , V_55 ) ) {
if ( ! F_93 ( & V_57 . V_52 ) ) {
F_85 ( & V_57 . V_52 , 1 ) ;
F_33 ( & V_57 . V_34 , F_84 ) ;
if ( V_65 - V_54 >
V_67 * V_37 - V_37 / 2 ) {
F_87 ( L_7 ) ;
V_68 ++ ;
}
V_54 = V_65 ;
}
F_94 () ;
F_91 ( L_6 ) ;
if ( F_92 () )
goto V_66;
}
while ( V_56 == V_64 &&
! F_95 () ) {
if ( F_96 ( & V_69 ) ) {
V_64 = V_65 +
V_70 * V_37 ;
V_71 ++ ;
F_97 ( & V_69 ) ;
break;
}
F_98 ( 1 ) ;
}
V_66: F_91 ( L_6 ) ;
} while ( ! F_92 () );
while ( ! F_95 () || F_93 ( & V_57 . V_52 ) ) {
F_99 ( L_6 ) ;
F_98 ( 1 ) ;
}
F_100 ( & V_57 . V_34 ) ;
F_101 ( L_6 ) ;
return 0 ;
}
static void F_102 ( struct V_29 * V_72 )
{
}
static int
F_103 ( void * V_53 )
{
int V_73 = 1 ;
int V_21 ;
int V_74 ;
struct V_29 * V_72 ;
if ( V_75 > 0 &&
V_76 > 0 &&
V_77 > 0 &&
V_31 -> V_78 &&
V_31 -> V_79 ) {
V_72 = F_104 ( sizeof( * V_72 ) *
V_80 * V_75 ) ;
V_73 = ! V_72 ;
}
if ( V_73 ) {
F_87 ( L_8 ) ;
goto V_81;
}
F_87 ( L_9 ) ;
do {
F_49 ( V_76 ) ;
F_105 ( & V_82 ) ;
F_69 ( F_106 ( V_61 ) ) ;
for ( V_21 = 0 ; V_21 < V_80 ; V_21 ++ ) {
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
V_31 -> V_78 ( & V_72 [ V_21 * V_75 + V_74 ] ,
F_102 ) ;
}
F_49 ( V_77 ) ;
F_69 ( F_106 ( V_61 ) ) ;
}
V_31 -> V_79 () ;
F_91 ( L_10 ) ;
} while ( ! F_92 () );
F_107 ( V_72 ) ;
V_81:
F_101 ( L_10 ) ;
return 0 ;
}
static int
F_108 ( void * V_53 )
{
unsigned long V_83 ;
int V_84 ;
F_87 ( L_11 ) ;
do {
V_83 = V_65 + V_85 * V_37 ;
while ( F_90 ( V_65 , V_83 ) &&
! F_95 () ) {
F_49 ( 1 ) ;
}
V_84 = V_86 ;
while ( V_84 > 0 &&
! F_95 () ) {
V_31 -> V_87 () ;
F_18 ( V_88 ) ;
V_84 -= V_88 ;
}
F_91 ( L_12 ) ;
} while ( ! F_92 () );
F_101 ( L_12 ) ;
return 0 ;
}
static int
F_109 ( void * V_53 )
{
bool V_89 = ! F_110 () ;
int V_90 = 0 ;
unsigned long V_91 ;
bool V_92 = V_93 , V_94 = V_95 , V_96 = V_97 ;
bool V_98 = V_99 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_111 ( rand ) ;
int V_100 [] = { V_101 , V_102 ,
V_103 , V_104 } ;
int V_105 = 0 ;
F_87 ( L_13 ) ;
F_62 ( L_14 V_42
L_15 ,
V_41 , V_31 -> V_106 ) ;
F_62 ( L_14 V_42
L_16 ,
V_41 ) ;
if ( ! V_92 && ! V_94 && ! V_96 && ! V_98 )
V_92 = V_94 = V_96 = V_98 = true ;
if ( V_92 && V_31 -> V_107 && V_31 -> V_108 )
V_100 [ V_105 ++ ] = V_103 ;
else if ( V_93 && ( ! V_31 -> V_107 || ! V_31 -> V_108 ) )
F_62 ( L_17 ) ;
if ( V_94 && V_31 -> V_109 )
V_100 [ V_105 ++ ] = V_102 ;
else if ( V_95 && ! V_31 -> V_109 )
F_62 ( L_18 ) ;
if ( V_96 && V_31 -> V_32 )
V_100 [ V_105 ++ ] = V_101 ;
else if ( V_97 && ! V_31 -> V_32 )
F_62 ( L_19 ) ;
if ( V_98 && V_31 -> V_110 )
V_100 [ V_105 ++ ] = V_104 ;
else if ( V_99 && ! V_31 -> V_110 )
F_62 ( L_20 ) ;
if ( F_112 ( V_105 == 0 ,
L_21 ) ) {
V_111 = V_112 ;
F_101 ( L_22 ) ;
}
do {
V_111 = V_113 ;
F_98 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_111 = V_114 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_111 = V_115 ;
V_26 = F_113 ( V_116 ,
V_61 == V_117 ) ;
V_20 -> V_25 = 1 ;
F_114 ( V_116 , V_20 ) ;
F_115 () ;
if ( V_26 ) {
V_21 = V_26 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
V_26 -> V_22 ++ ;
switch ( V_100 [ F_16 ( & rand ) % V_105 ] ) {
case V_101 :
V_111 = V_101 ;
V_31 -> V_32 ( V_26 ) ;
break;
case V_102 :
V_111 = V_102 ;
V_31 -> V_109 () ;
F_25 ( V_26 ) ;
break;
case V_103 :
V_111 = V_103 ;
V_91 = V_31 -> V_107 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_49 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_111 = V_118 ;
V_31 -> V_108 ( V_91 ) ;
F_25 ( V_26 ) ;
break;
case V_104 :
V_111 = V_104 ;
V_31 -> V_110 () ;
F_25 ( V_26 ) ;
break;
default:
F_116 ( 1 ) ;
break;
}
}
F_117 ( ++ V_119 ) ;
if ( V_89 &&
! ( F_16 ( & rand ) & 0xff & ( ! ! V_90 - 1 ) ) ) {
F_116 ( V_90 == 0 && F_110 () ) ;
if ( V_90 >= 0 )
F_118 () ;
else
F_119 () ;
if ( ++ V_90 > 3 )
V_90 = - V_90 ;
}
V_111 = V_120 ;
F_91 ( L_22 ) ;
} while ( ! F_92 () );
if ( V_90 > 0 )
V_90 = - V_90 ;
while ( V_89 && V_90 ++ < 0 )
F_119 () ;
F_116 ( V_89 && F_110 () ) ;
V_111 = V_112 ;
F_101 ( L_22 ) ;
return 0 ;
}
static int
F_120 ( void * V_53 )
{
F_111 ( rand ) ;
F_87 ( L_23 ) ;
F_121 ( V_61 , V_121 ) ;
do {
F_98 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_31 -> V_79 != NULL &&
F_16 ( & rand ) % ( V_122 * 8 ) == 0 ) {
V_31 -> V_79 () ;
} else if ( V_97 == V_95 ) {
if ( F_16 ( & rand ) & 0x80 )
V_31 -> V_110 () ;
else
V_31 -> V_109 () ;
} else if ( V_97 ) {
V_31 -> V_110 () ;
} else {
V_31 -> V_109 () ;
}
F_91 ( L_24 ) ;
} while ( ! F_92 () );
F_101 ( L_24 ) ;
return 0 ;
}
static void F_122 ( void )
{
static T_7 V_123 = F_123 ( 0 ) ;
if ( F_124 ( & V_123 ) )
return;
if ( F_125 ( & V_123 , 1 ) != 0 )
return;
F_126 ( V_124 ) ;
}
static void F_127 ( unsigned long V_125 )
{
int V_19 ;
unsigned long V_126 ;
unsigned long V_40 ;
static F_111 ( rand ) ;
static F_128 ( V_127 ) ;
struct V_4 * V_6 ;
int V_128 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_129 () ;
if ( V_31 -> V_126 )
V_126 = V_31 -> V_126 () ;
else
V_126 = V_31 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_113 ( V_116 ,
F_129 () ||
F_130 () ||
F_131 ( T_6 ) ||
F_83 () ) ;
if ( V_6 == NULL ) {
V_31 -> V_130 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_131 ) ;
F_132 ( & V_127 ) ;
V_31 -> V_132 ( & rand ) ;
V_133 ++ ;
F_133 ( & V_127 ) ;
F_74 () ;
V_128 = V_6 -> V_22 ;
if ( V_128 > V_23 ) {
V_128 = V_23 ;
}
V_40 = V_31 -> V_40 () ;
if ( V_128 > 1 ) {
F_134 ( V_31 -> V_106 , & V_6 -> V_30 , V_1 ,
V_126 , V_40 ) ;
F_122 () ;
}
F_135 ( V_134 [ V_128 ] ) ;
V_40 = V_40 - V_126 ;
if ( V_31 -> V_126 )
V_40 ++ ;
if ( V_40 > V_23 ) {
V_40 = V_23 ;
}
F_135 ( V_135 [ V_40 ] ) ;
F_76 () ;
V_31 -> V_130 ( V_19 ) ;
}
static int
F_136 ( void * V_53 )
{
unsigned long V_126 ;
unsigned long V_40 ;
int V_19 ;
F_111 ( rand ) ;
struct V_4 * V_6 ;
int V_128 ;
struct V_136 V_137 ;
unsigned long long V_1 ;
F_87 ( L_25 ) ;
F_121 ( V_61 , V_121 ) ;
if ( V_138 && V_31 -> V_139 )
F_137 ( & V_137 , F_127 , 0 ) ;
do {
if ( V_138 && V_31 -> V_139 ) {
if ( ! F_138 ( & V_137 ) )
F_139 ( & V_137 , V_65 + 1 ) ;
}
V_19 = V_31 -> V_129 () ;
if ( V_31 -> V_126 )
V_126 = V_31 -> V_126 () ;
else
V_126 = V_31 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_113 ( V_116 ,
F_129 () ||
F_130 () ||
F_131 ( T_6 ) ||
F_83 () ) ;
if ( V_6 == NULL ) {
V_31 -> V_130 ( V_19 ) ;
F_49 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_131 ) ;
V_31 -> V_132 ( & rand ) ;
F_74 () ;
V_128 = V_6 -> V_22 ;
if ( V_128 > V_23 ) {
V_128 = V_23 ;
}
V_40 = V_31 -> V_40 () ;
if ( V_128 > 1 ) {
F_134 ( V_31 -> V_106 , & V_6 -> V_30 ,
V_1 , V_126 , V_40 ) ;
F_122 () ;
}
F_135 ( V_134 [ V_128 ] ) ;
V_40 = V_40 - V_126 ;
if ( V_31 -> V_126 )
V_40 ++ ;
if ( V_40 > V_23 ) {
V_40 = V_23 ;
}
F_135 ( V_135 [ V_40 ] ) ;
F_76 () ;
V_31 -> V_130 ( V_19 ) ;
F_94 () ;
F_91 ( L_26 ) ;
} while ( ! F_92 () );
if ( V_138 && V_31 -> V_139 ) {
F_140 ( & V_137 ) ;
F_141 ( & V_137 ) ;
}
F_101 ( L_26 ) ;
return 0 ;
}
static void
F_142 ( void )
{
int V_39 ;
int V_21 ;
long V_140 [ V_23 + 1 ] = { 0 } ;
long V_141 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_142 = V_143 ;
F_63 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_140 [ V_21 ] += F_143 ( V_134 , V_39 ) [ V_21 ] ;
V_141 [ V_21 ] += F_143 ( V_135 , V_39 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_140 [ V_21 ] != 0 )
break;
}
F_62 ( L_27 , V_41 , V_42 ) ;
F_65 ( L_28 ,
V_116 ,
V_119 ,
F_6 ( & V_8 ) ,
F_124 ( & V_10 ) ,
F_124 ( & V_9 ) ,
F_124 ( & V_13 ) ) ;
F_65 ( L_29 ,
F_124 ( & V_131 ) ,
V_144 ,
V_63 ) ;
F_65 ( L_30 ,
V_68 ,
V_71 ,
V_133 ) ;
F_144 () ;
F_65 ( L_31 ,
V_145 ,
V_146 ,
V_147 ) ;
F_65 ( L_32 , F_145 ( & V_82 ) ) ;
F_62 ( L_27 , V_41 , V_42 ) ;
if ( F_124 ( & V_131 ) != 0 ||
V_147 != 0 ||
V_144 != 0 ||
V_63 != 0 ||
V_68 != 0 ||
V_21 > 1 ) {
F_65 ( L_14 , L_33 ) ;
F_7 ( & V_148 ) ;
F_116 ( 1 ) ;
}
F_65 ( L_34 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_65 ( L_35 , V_140 [ V_21 ] ) ;
F_65 ( L_3 ) ;
F_62 ( L_27 , V_41 , V_42 ) ;
F_65 ( L_36 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_65 ( L_35 , V_141 [ V_21 ] ) ;
F_65 ( L_3 ) ;
F_62 ( L_27 , V_41 , V_42 ) ;
F_65 ( L_37 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_65 ( L_38 , F_124 ( & V_24 [ V_21 ] ) ) ;
}
F_65 ( L_3 ) ;
if ( V_31 -> V_149 )
V_31 -> V_149 () ;
if ( V_142 == V_119 &&
V_116 != NULL ) {
int T_3 V_150 ;
unsigned long T_3 V_151 ;
unsigned long T_3 V_40 ;
F_146 ( V_31 -> V_152 ,
& V_150 , & V_151 , & V_40 ) ;
F_62 ( L_39 ,
V_111 ,
V_151 , V_40 , V_150 ) ;
F_147 () ;
F_122 () ;
}
V_142 = V_119 ;
}
static int
F_148 ( void * V_53 )
{
F_87 ( L_40 ) ;
do {
F_49 ( V_153 * V_37 ) ;
F_142 () ;
F_99 ( L_41 ) ;
} while ( ! F_92 () );
F_101 ( L_41 ) ;
return 0 ;
}
static inline void
F_149 ( struct V_154 * V_31 , const char * V_155 )
{
F_62 ( L_14 V_42
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50 ,
V_41 , V_155 , V_18 , V_122 ,
V_153 , V_156 , V_157 , V_158 ,
V_159 , V_138 , V_86 , V_88 , V_85 ,
V_160 , V_31 -> V_161 ,
V_70 , V_67 , V_162 ,
V_163 , V_164 ,
V_165 ,
V_166 , V_167 ) ;
}
static void F_150 ( int V_39 )
{
struct V_168 * V_137 ;
if ( V_169 [ V_39 ] == NULL )
return;
F_151 ( & V_69 ) ;
V_137 = V_169 [ V_39 ] ;
V_169 [ V_39 ] = NULL ;
F_97 ( & V_69 ) ;
F_152 ( F_86 , V_137 ) ;
}
static int F_153 ( int V_39 )
{
int V_170 ;
if ( V_169 [ V_39 ] != NULL )
return 0 ;
F_151 ( & V_69 ) ;
F_87 ( L_51 ) ;
V_169 [ V_39 ] = F_154 ( F_86 , NULL ,
F_155 ( V_39 ) ,
L_6 ) ;
if ( F_156 ( V_169 [ V_39 ] ) ) {
V_170 = F_157 ( V_169 [ V_39 ] ) ;
F_87 ( L_52 ) ;
V_144 ++ ;
V_169 [ V_39 ] = NULL ;
F_97 ( & V_69 ) ;
return V_170 ;
}
F_158 ( V_169 [ V_39 ] , V_39 ) ;
F_159 ( V_169 [ V_39 ] ) ;
F_97 ( & V_69 ) ;
return 0 ;
}
static int F_160 ( void * args )
{
unsigned long V_171 ;
F_87 ( L_53 ) ;
if ( V_164 > 0 ) {
F_87 ( L_54 ) ;
F_49 ( V_164 * V_37 ) ;
F_87 ( L_55 ) ;
}
if ( ! F_95 () ) {
V_171 = F_161 () + V_163 ;
F_62 ( L_56 ) ;
F_14 () ;
F_74 () ;
while ( F_90 ( F_161 () , V_171 ) )
continue;
F_76 () ;
F_23 () ;
F_62 ( L_57 ) ;
}
F_99 ( L_58 ) ;
while ( ! F_95 () )
F_49 ( 10 * V_37 ) ;
return 0 ;
}
static int T_8 F_162 ( void )
{
if ( V_163 <= 0 )
return 0 ;
return F_163 ( F_160 , NULL , V_172 ) ;
}
static void F_164 ( struct V_29 * V_34 )
{
F_7 ( & V_173 ) ;
}
static int F_165 ( void * V_53 )
{
long V_174 = ( long ) V_53 ;
bool V_175 = 0 ;
bool V_176 ;
struct V_29 V_34 ;
F_89 ( & V_34 ) ;
F_87 ( L_59 ) ;
F_121 ( V_61 , V_121 ) ;
do {
F_166 ( V_177 [ V_174 ] ,
( V_176 =
F_93 ( & V_178 ) ) != V_175 ||
F_92 () ) ;
V_175 = V_176 ;
if ( F_92 () )
break;
V_31 -> V_78 ( & V_34 , F_164 ) ;
if ( F_167 ( & V_179 ) )
F_168 ( & V_180 ) ;
} while ( ! F_92 () );
if ( V_31 -> V_79 != NULL )
V_31 -> V_79 () ;
F_100 ( & V_34 ) ;
F_101 ( L_60 ) ;
return 0 ;
}
static int F_169 ( void * V_53 )
{
int V_21 ;
F_87 ( L_61 ) ;
do {
F_170 ( & V_173 , 0 ) ;
F_170 ( & V_179 , V_165 ) ;
F_85 ( & V_178 , ! V_178 ) ;
for ( V_21 = 0 ; V_21 < V_165 ; V_21 ++ )
F_168 ( & V_177 [ V_21 ] ) ;
F_166 ( V_180 ,
F_124 ( & V_179 ) == 0 ||
F_92 () ) ;
if ( F_92 () )
break;
V_146 ++ ;
V_31 -> V_79 () ;
if ( F_124 ( & V_173 ) != V_165 ) {
V_147 ++ ;
F_171 ( L_62 ,
F_124 ( & V_173 ) ,
V_165 ) ;
F_116 ( 1 ) ;
}
V_145 ++ ;
F_49 ( V_37 / 10 ) ;
} while ( ! F_92 () );
F_101 ( L_63 ) ;
return 0 ;
}
static int F_172 ( void )
{
int V_21 ;
int V_181 ;
if ( V_165 <= 0 )
return 0 ;
if ( V_31 -> V_78 == NULL || V_31 -> V_79 == NULL ) {
F_62 ( L_14 V_42
L_64 ,
V_41 , V_31 -> V_106 ) ;
F_62 ( L_14 V_42
L_65 ,
V_41 ) ;
return 0 ;
}
F_170 ( & V_179 , 0 ) ;
F_170 ( & V_173 , 0 ) ;
V_182 =
F_173 ( V_165 * sizeof( V_182 [ 0 ] ) ,
V_183 ) ;
V_177 =
F_173 ( V_165 * sizeof( V_177 [ 0 ] ) ,
V_183 ) ;
if ( V_182 == NULL || ! V_177 )
return - V_184 ;
for ( V_21 = 0 ; V_21 < V_165 ; V_21 ++ ) {
F_174 ( & V_177 [ V_21 ] ) ;
V_181 = F_163 ( F_165 ,
( void * ) ( long ) V_21 ,
V_182 [ V_21 ] ) ;
if ( V_181 )
return V_181 ;
}
return F_163 ( F_169 , NULL , V_185 ) ;
}
static void F_175 ( void )
{
int V_21 ;
F_152 ( F_169 , V_185 ) ;
if ( V_182 != NULL ) {
for ( V_21 = 0 ; V_21 < V_165 ; V_21 ++ )
F_152 ( F_165 ,
V_182 [ V_21 ] ) ;
F_176 ( V_182 ) ;
V_182 = NULL ;
}
if ( V_177 != NULL ) {
F_176 ( V_177 ) ;
V_177 = NULL ;
}
}
static int F_177 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
long V_39 = ( long ) V_189 ;
switch ( V_188 ) {
case V_190 :
case V_191 :
( void ) F_153 ( V_39 ) ;
break;
case V_192 :
F_150 ( V_39 ) ;
break;
default:
break;
}
return V_193 ;
}
static void
F_178 ( void )
{
int V_21 ;
F_179 () ;
if ( F_180 () ) {
if ( V_31 -> V_79 != NULL )
V_31 -> V_79 () ;
return;
}
F_175 () ;
F_152 ( F_160 , V_172 ) ;
F_152 ( F_109 , V_117 ) ;
if ( V_194 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_152 ( F_136 ,
V_194 [ V_21 ] ) ;
F_176 ( V_194 ) ;
}
V_116 = NULL ;
if ( V_195 ) {
for ( V_21 = 0 ; V_21 < V_122 ; V_21 ++ ) {
F_152 ( F_120 ,
V_195 [ V_21 ] ) ;
}
F_176 ( V_195 ) ;
V_195 = NULL ;
}
F_152 ( F_148 , V_196 ) ;
F_152 ( F_108 , V_197 ) ;
for ( V_21 = 0 ; V_21 < V_198 ; V_21 ++ )
F_152 ( F_103 , V_199 [ V_21 ] ) ;
if ( ( V_160 == 1 && V_31 -> V_161 ) ||
V_160 == 2 ) {
F_181 ( & V_200 ) ;
F_63 (i)
F_150 ( V_21 ) ;
}
if ( V_31 -> V_79 != NULL )
V_31 -> V_79 () ;
if ( V_31 -> V_201 != NULL )
V_31 -> V_201 () ;
F_142 () ;
if ( F_124 ( & V_148 ) || V_147 )
F_149 ( V_31 , L_66 ) ;
else if ( F_182 () )
F_149 ( V_31 ,
L_67 ) ;
else
F_149 ( V_31 , L_68 ) ;
F_183 () ;
}
static void F_184 ( struct V_29 * V_72 )
{
}
static void F_185 ( struct V_29 * V_72 )
{
F_62 ( L_69 ) ;
}
static void F_186 ( void )
{
#ifdef F_187
struct V_29 V_202 ;
struct V_29 V_203 ;
F_89 ( & V_202 ) ;
F_89 ( & V_203 ) ;
F_62 ( L_70 ) ;
F_74 () ;
F_14 () ;
F_33 ( & V_202 , F_184 ) ;
F_188 () ;
F_33 ( & V_203 , F_184 ) ;
F_33 ( & V_203 , F_185 ) ;
F_189 () ;
F_23 () ;
F_76 () ;
F_190 () ;
F_62 ( L_71 ) ;
F_100 ( & V_202 ) ;
F_100 ( & V_203 ) ;
#else
F_62 ( L_72 ) ;
#endif
}
static int T_8
F_191 ( void )
{
int V_21 ;
int V_39 ;
int V_204 = 0 ;
static struct V_154 * V_205 [] = {
& V_206 , & V_207 , & V_208 , & V_209 , & V_210 ,
& V_211 , V_212
} ;
if ( ! F_192 ( V_41 , V_156 , & V_213 ) )
return - V_214 ;
for ( V_21 = 0 ; V_21 < F_193 ( V_205 ) ; V_21 ++ ) {
V_31 = V_205 [ V_21 ] ;
if ( strcmp ( V_41 , V_31 -> V_106 ) == 0 )
break;
}
if ( V_21 == F_193 ( V_205 ) ) {
F_62 ( L_73 ,
V_41 ) ;
F_62 ( L_74 ) ;
for ( V_21 = 0 ; V_21 < F_193 ( V_205 ) ; V_21 ++ )
F_62 ( L_75 , V_205 [ V_21 ] -> V_106 ) ;
F_62 ( L_3 ) ;
F_194 () ;
return - V_215 ;
}
if ( V_31 -> V_87 == NULL && V_86 != 0 ) {
F_62 ( L_76 ) ;
V_86 = 0 ;
}
if ( V_31 -> V_216 )
V_31 -> V_216 () ;
if ( V_217 >= 0 ) {
V_18 = V_217 ;
} else {
V_18 = F_195 () - 2 - V_217 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_149 ( V_31 , L_77 ) ;
F_35 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_193 ( V_218 ) ; V_21 ++ ) {
V_218 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_218 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_116 = NULL ;
V_119 = 0 ;
F_170 ( & V_10 , 0 ) ;
F_170 ( & V_9 , 0 ) ;
F_170 ( & V_13 , 0 ) ;
F_170 ( & V_131 , 0 ) ;
F_170 ( & V_148 , 0 ) ;
V_147 = 0 ;
V_144 = 0 ;
V_63 = 0 ;
V_68 = 0 ;
V_71 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_170 ( & V_24 [ V_21 ] , 0 ) ;
F_63 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_143 ( V_134 , V_39 ) [ V_21 ] = 0 ;
F_143 ( V_135 , V_39 ) [ V_21 ] = 0 ;
}
}
V_204 = F_163 ( F_109 , NULL ,
V_117 ) ;
if ( V_204 )
goto V_219;
if ( V_122 > 0 ) {
V_195 = F_173 ( V_122 *
sizeof( V_195 [ 0 ] ) ,
V_183 ) ;
if ( V_195 == NULL ) {
F_196 ( L_78 ) ;
V_204 = - V_184 ;
goto V_219;
}
}
for ( V_21 = 0 ; V_21 < V_122 ; V_21 ++ ) {
V_204 = F_163 ( F_120 ,
NULL , V_195 [ V_21 ] ) ;
if ( V_204 )
goto V_219;
}
V_194 = F_173 ( V_18 * sizeof( V_194 [ 0 ] ) ,
V_183 ) ;
if ( V_194 == NULL ) {
F_196 ( L_78 ) ;
V_204 = - V_184 ;
goto V_219;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_204 = F_163 ( F_136 , NULL ,
V_194 [ V_21 ] ) ;
if ( V_204 )
goto V_219;
}
if ( V_153 > 0 ) {
V_204 = F_163 ( F_148 , NULL ,
V_196 ) ;
if ( V_204 )
goto V_219;
}
if ( V_157 && V_158 > 0 ) {
V_204 = F_197 ( V_158 * V_37 ) ;
if ( V_204 )
goto V_219;
}
if ( V_159 < 0 )
V_159 = 0 ;
if ( V_159 ) {
V_204 = F_198 ( V_159 * V_37 ) ;
if ( V_204 )
goto V_219;
}
if ( V_86 < 0 )
V_86 = 0 ;
if ( V_86 ) {
V_204 = F_163 ( F_108 , NULL ,
V_197 ) ;
if ( V_204 )
goto V_219;
}
if ( V_70 < 1 )
V_70 = 1 ;
if ( V_67 < 2 )
V_67 = 2 ;
if ( ( V_160 == 1 && V_31 -> V_161 ) ||
V_160 == 2 ) {
V_64 = V_65 + V_70 * V_37 ;
F_199 ( & V_200 ) ;
F_63 (i) {
if ( F_200 ( V_21 ) )
continue;
V_204 = F_153 ( V_21 ) ;
if ( V_204 )
goto V_219;
}
}
V_204 = F_201 ( V_162 , F_178 ) ;
if ( V_204 )
goto V_219;
V_204 = F_202 ( V_167 * V_37 , V_166 * V_37 ) ;
if ( V_204 )
goto V_219;
V_204 = F_162 () ;
if ( V_204 )
goto V_219;
V_204 = F_172 () ;
if ( V_204 )
goto V_219;
if ( V_220 )
F_186 () ;
if ( V_80 > 0 ) {
V_198 = ( F_195 () + 3 ) / 4 ;
V_199 = F_203 ( V_198 , sizeof( * V_199 ) ,
V_183 ) ;
if ( ! V_199 ) {
F_196 ( L_78 ) ;
V_204 = - V_184 ;
goto V_219;
}
for ( V_21 = 0 ; V_21 < V_198 ; V_21 ++ ) {
V_204 = F_163 ( F_103 ,
NULL ,
V_199 [ V_21 ] ) ;
if ( V_204 )
goto V_219;
}
}
F_179 () ;
F_194 () ;
return 0 ;
V_219:
F_194 () ;
F_178 () ;
return V_204 ;
}
