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
static void F_83 ( struct V_29 * V_33 )
{
struct V_49 * V_50 =
F_10 ( V_33 , struct V_49 , V_34 ) ;
F_84 ( & V_50 -> V_51 , 0 ) ;
}
static int F_85 ( void * V_52 )
{
unsigned long V_53 ;
unsigned long V_54 ;
unsigned long V_55 ;
struct V_49 V_56 = { . V_51 = 0 } ;
struct V_57 V_58 ;
F_86 ( L_4 ) ;
V_58 . V_59 = 1 ;
if ( F_87 ( V_60 , V_61 , & V_58 ) < 0 ) {
F_86 ( L_5 ) ;
V_62 ++ ;
}
F_88 ( & V_56 . V_34 ) ;
do {
V_55 = V_63 ;
while ( F_89 ( V_64 , V_55 ) ) {
F_49 ( V_55 - V_64 ) ;
F_90 ( L_6 ) ;
if ( F_91 () )
goto V_65;
}
V_54 = V_55 + V_66 * V_37 ;
V_53 = V_64 ;
while ( F_89 ( V_64 , V_54 ) ) {
if ( ! F_92 ( & V_56 . V_51 ) ) {
F_84 ( & V_56 . V_51 , 1 ) ;
F_33 ( & V_56 . V_34 , F_83 ) ;
if ( V_64 - V_53 >
V_66 * V_37 - V_37 / 2 ) {
F_86 ( L_7 ) ;
V_67 ++ ;
}
V_53 = V_64 ;
}
F_93 () ;
F_90 ( L_6 ) ;
if ( F_91 () )
goto V_65;
}
while ( V_55 == V_63 &&
! F_94 () ) {
if ( F_95 ( & V_68 ) ) {
V_63 = V_64 +
V_69 * V_37 ;
V_70 ++ ;
F_96 ( & V_68 ) ;
break;
}
F_97 ( 1 ) ;
}
V_65: F_90 ( L_6 ) ;
} while ( ! F_91 () );
while ( ! F_94 () || F_92 ( & V_56 . V_51 ) ) {
F_98 ( L_6 ) ;
F_97 ( 1 ) ;
}
F_99 ( & V_56 . V_34 ) ;
F_100 ( L_6 ) ;
return 0 ;
}
static void F_101 ( struct V_29 * V_71 )
{
}
static int
F_102 ( void * V_52 )
{
int V_72 = 1 ;
int V_21 ;
int V_73 ;
struct V_29 * V_71 ;
if ( V_74 > 0 &&
V_75 > 0 &&
V_76 > 0 &&
V_31 -> V_77 &&
V_31 -> V_78 ) {
V_71 = F_103 ( sizeof( * V_71 ) *
V_79 * V_74 ) ;
V_72 = ! V_71 ;
}
if ( V_72 ) {
F_86 ( L_8 ) ;
while ( ! F_91 () )
F_49 ( V_37 ) ;
return 0 ;
}
F_86 ( L_9 ) ;
do {
F_49 ( V_75 ) ;
F_104 ( & V_80 ) ;
F_69 ( F_105 ( V_60 ) ) ;
for ( V_21 = 0 ; V_21 < V_79 ; V_21 ++ ) {
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_31 -> V_77 ( & V_71 [ V_21 * V_74 + V_73 ] ,
F_101 ) ;
}
F_49 ( V_76 ) ;
F_69 ( F_105 ( V_60 ) ) ;
}
V_31 -> V_78 () ;
F_90 ( L_10 ) ;
} while ( ! F_91 () );
F_106 ( V_71 ) ;
F_100 ( L_10 ) ;
return 0 ;
}
static int
F_107 ( void * V_52 )
{
unsigned long V_81 ;
int V_82 ;
F_86 ( L_11 ) ;
do {
V_81 = V_64 + V_83 * V_37 ;
while ( F_89 ( V_64 , V_81 ) &&
! F_94 () ) {
F_49 ( 1 ) ;
}
V_82 = V_84 ;
while ( V_82 > 0 &&
! F_94 () ) {
V_31 -> V_85 () ;
F_18 ( V_86 ) ;
V_82 -= V_86 ;
}
F_90 ( L_12 ) ;
} while ( ! F_91 () );
F_100 ( L_12 ) ;
return 0 ;
}
static int
F_108 ( void * V_52 )
{
bool V_87 = ! F_109 () ;
int V_88 = 0 ;
unsigned long V_89 ;
bool V_90 = V_91 , V_92 = V_93 , V_94 = V_95 ;
bool V_96 = V_97 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_110 ( rand ) ;
int V_98 [] = { V_99 , V_100 ,
V_101 , V_102 } ;
int V_103 = 0 ;
F_86 ( L_13 ) ;
F_62 ( L_14 V_42
L_15 ,
V_41 , V_31 -> V_104 ) ;
F_62 ( L_14 V_42
L_16 ,
V_41 ) ;
if ( ! V_90 && ! V_92 && ! V_94 && ! V_96 )
V_90 = V_92 = V_94 = V_96 = true ;
if ( V_90 && V_31 -> V_105 && V_31 -> V_106 )
V_98 [ V_103 ++ ] = V_101 ;
else if ( V_91 && ( ! V_31 -> V_105 || ! V_31 -> V_106 ) )
F_62 ( L_17 ) ;
if ( V_92 && V_31 -> V_107 )
V_98 [ V_103 ++ ] = V_100 ;
else if ( V_93 && ! V_31 -> V_107 )
F_62 ( L_18 ) ;
if ( V_94 && V_31 -> V_32 )
V_98 [ V_103 ++ ] = V_99 ;
else if ( V_95 && ! V_31 -> V_32 )
F_62 ( L_19 ) ;
if ( V_96 && V_31 -> V_108 )
V_98 [ V_103 ++ ] = V_102 ;
else if ( V_97 && ! V_31 -> V_108 )
F_62 ( L_20 ) ;
if ( F_111 ( V_103 == 0 ,
L_21 ) ) {
V_109 = V_110 ;
F_100 ( L_22 ) ;
}
do {
V_109 = V_111 ;
F_97 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_109 = V_112 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_109 = V_113 ;
V_26 = F_112 ( V_114 ,
V_60 == V_115 ) ;
V_20 -> V_25 = 1 ;
F_113 ( V_114 , V_20 ) ;
F_114 () ;
if ( V_26 ) {
V_21 = V_26 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
V_26 -> V_22 ++ ;
switch ( V_98 [ F_16 ( & rand ) % V_103 ] ) {
case V_99 :
V_109 = V_99 ;
V_31 -> V_32 ( V_26 ) ;
break;
case V_100 :
V_109 = V_100 ;
V_31 -> V_107 () ;
F_25 ( V_26 ) ;
break;
case V_101 :
V_109 = V_101 ;
V_89 = V_31 -> V_105 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_49 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_109 = V_116 ;
V_31 -> V_106 ( V_89 ) ;
F_25 ( V_26 ) ;
break;
case V_102 :
V_109 = V_102 ;
V_31 -> V_108 () ;
F_25 ( V_26 ) ;
break;
default:
F_115 ( 1 ) ;
break;
}
}
F_116 ( ++ V_117 ) ;
if ( V_87 &&
! ( F_16 ( & rand ) & 0xff & ( ! ! V_88 - 1 ) ) ) {
F_115 ( V_88 == 0 && F_109 () ) ;
if ( V_88 >= 0 )
F_117 () ;
else
F_118 () ;
if ( ++ V_88 > 3 )
V_88 = - V_88 ;
}
V_109 = V_118 ;
F_90 ( L_22 ) ;
} while ( ! F_91 () );
if ( V_88 > 0 )
V_88 = - V_88 ;
while ( V_87 && V_88 ++ < 0 )
F_118 () ;
F_115 ( V_87 && F_109 () ) ;
V_109 = V_110 ;
F_100 ( L_22 ) ;
return 0 ;
}
static int
F_119 ( void * V_52 )
{
F_110 ( rand ) ;
F_86 ( L_23 ) ;
F_120 ( V_60 , V_119 ) ;
do {
F_97 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_31 -> V_78 != NULL &&
F_16 ( & rand ) % ( V_120 * 8 ) == 0 ) {
V_31 -> V_78 () ;
} else if ( V_95 == V_93 ) {
if ( F_16 ( & rand ) & 0x80 )
V_31 -> V_108 () ;
else
V_31 -> V_107 () ;
} else if ( V_95 ) {
V_31 -> V_108 () ;
} else {
V_31 -> V_107 () ;
}
F_90 ( L_24 ) ;
} while ( ! F_91 () );
F_100 ( L_24 ) ;
return 0 ;
}
static void F_121 ( void )
{
static T_7 V_121 = F_122 ( 0 ) ;
if ( F_123 ( & V_121 ) )
return;
if ( F_124 ( & V_121 , 1 ) != 0 )
return;
F_125 ( V_122 ) ;
}
static void F_126 ( unsigned long V_123 )
{
int V_19 ;
unsigned long V_124 ;
unsigned long V_40 ;
static F_110 ( rand ) ;
static F_127 ( V_125 ) ;
struct V_4 * V_6 ;
int V_126 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_127 () ;
if ( V_31 -> V_124 )
V_124 = V_31 -> V_124 () ;
else
V_124 = V_31 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_112 ( V_114 ,
F_128 () ||
F_129 () ||
F_130 ( T_6 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_128 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_129 ) ;
F_131 ( & V_125 ) ;
V_31 -> V_130 ( & rand ) ;
V_131 ++ ;
F_132 ( & V_125 ) ;
F_74 () ;
V_126 = V_6 -> V_22 ;
if ( V_126 > V_23 ) {
V_126 = V_23 ;
}
V_40 = V_31 -> V_40 () ;
if ( V_126 > 1 ) {
F_133 ( V_31 -> V_104 , & V_6 -> V_30 , V_1 ,
V_124 , V_40 ) ;
F_121 () ;
}
F_134 ( V_132 [ V_126 ] ) ;
V_40 = V_40 - V_124 ;
if ( V_31 -> V_124 )
V_40 ++ ;
if ( V_40 > V_23 ) {
V_40 = V_23 ;
}
F_134 ( V_133 [ V_40 ] ) ;
F_76 () ;
V_31 -> V_128 ( V_19 ) ;
}
static int
F_135 ( void * V_52 )
{
unsigned long V_124 ;
unsigned long V_40 ;
int V_19 ;
F_110 ( rand ) ;
struct V_4 * V_6 ;
int V_126 ;
struct V_134 V_135 ;
unsigned long long V_1 ;
F_86 ( L_25 ) ;
F_120 ( V_60 , V_119 ) ;
if ( V_136 && V_31 -> V_137 )
F_136 ( & V_135 , F_126 , 0 ) ;
do {
if ( V_136 && V_31 -> V_137 ) {
if ( ! F_137 ( & V_135 ) )
F_138 ( & V_135 , V_64 + 1 ) ;
}
V_19 = V_31 -> V_127 () ;
if ( V_31 -> V_124 )
V_124 = V_31 -> V_124 () ;
else
V_124 = V_31 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_112 ( V_114 ,
F_128 () ||
F_129 () ||
F_130 ( T_6 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_128 ( V_19 ) ;
F_49 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_129 ) ;
V_31 -> V_130 ( & rand ) ;
F_74 () ;
V_126 = V_6 -> V_22 ;
if ( V_126 > V_23 ) {
V_126 = V_23 ;
}
V_40 = V_31 -> V_40 () ;
if ( V_126 > 1 ) {
F_133 ( V_31 -> V_104 , & V_6 -> V_30 ,
V_1 , V_124 , V_40 ) ;
F_121 () ;
}
F_134 ( V_132 [ V_126 ] ) ;
V_40 = V_40 - V_124 ;
if ( V_31 -> V_124 )
V_40 ++ ;
if ( V_40 > V_23 ) {
V_40 = V_23 ;
}
F_134 ( V_133 [ V_40 ] ) ;
F_76 () ;
V_31 -> V_128 ( V_19 ) ;
F_93 () ;
F_90 ( L_26 ) ;
} while ( ! F_91 () );
if ( V_136 && V_31 -> V_137 ) {
F_139 ( & V_135 ) ;
F_140 ( & V_135 ) ;
}
F_100 ( L_26 ) ;
return 0 ;
}
static void
F_141 ( void )
{
int V_39 ;
int V_21 ;
long V_138 [ V_23 + 1 ] = { 0 } ;
long V_139 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_140 = V_141 ;
F_63 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_138 [ V_21 ] += F_142 ( V_132 , V_39 ) [ V_21 ] ;
V_139 [ V_21 ] += F_142 ( V_133 , V_39 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_138 [ V_21 ] != 0 )
break;
}
F_62 ( L_27 , V_41 , V_42 ) ;
F_65 ( L_28 ,
V_114 ,
V_117 ,
F_6 ( & V_8 ) ,
F_123 ( & V_10 ) ,
F_123 ( & V_9 ) ,
F_123 ( & V_13 ) ) ;
F_65 ( L_29 ,
F_123 ( & V_129 ) ,
V_142 ,
V_62 ) ;
F_65 ( L_30 ,
V_67 ,
V_70 ,
V_131 ) ;
F_143 () ;
F_65 ( L_31 ,
V_143 ,
V_144 ,
V_145 ) ;
F_65 ( L_32 , F_144 ( & V_80 ) ) ;
F_62 ( L_27 , V_41 , V_42 ) ;
if ( F_123 ( & V_129 ) != 0 ||
V_145 != 0 ||
V_142 != 0 ||
V_62 != 0 ||
V_67 != 0 ||
V_21 > 1 ) {
F_65 ( L_14 , L_33 ) ;
F_7 ( & V_146 ) ;
F_115 ( 1 ) ;
}
F_65 ( L_34 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_65 ( L_35 , V_138 [ V_21 ] ) ;
F_65 ( L_3 ) ;
F_62 ( L_27 , V_41 , V_42 ) ;
F_65 ( L_36 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_65 ( L_35 , V_139 [ V_21 ] ) ;
F_65 ( L_3 ) ;
F_62 ( L_27 , V_41 , V_42 ) ;
F_65 ( L_37 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_65 ( L_38 , F_123 ( & V_24 [ V_21 ] ) ) ;
}
F_65 ( L_3 ) ;
if ( V_31 -> V_147 )
V_31 -> V_147 () ;
if ( V_140 == V_117 &&
V_114 != NULL ) {
int T_3 V_148 ;
unsigned long T_3 V_149 ;
unsigned long T_3 V_40 ;
F_145 ( V_31 -> V_150 ,
& V_148 , & V_149 , & V_40 ) ;
F_62 ( L_39 ,
V_109 ,
V_149 , V_40 , V_148 ) ;
F_146 () ;
F_121 () ;
}
V_140 = V_117 ;
}
static int
F_147 ( void * V_52 )
{
F_86 ( L_40 ) ;
do {
F_49 ( V_151 * V_37 ) ;
F_141 () ;
F_98 ( L_41 ) ;
} while ( ! F_91 () );
F_100 ( L_41 ) ;
return 0 ;
}
static inline void
F_148 ( struct V_152 * V_31 , const char * V_153 )
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
V_41 , V_153 , V_18 , V_120 ,
V_151 , V_154 , V_155 , V_156 ,
V_157 , V_136 , V_84 , V_86 , V_83 ,
V_158 , V_31 -> V_159 ,
V_69 , V_66 , V_160 ,
V_161 , V_162 ,
V_163 ,
V_164 , V_165 ) ;
}
static void F_149 ( int V_39 )
{
struct V_166 * V_135 ;
if ( V_167 [ V_39 ] == NULL )
return;
F_150 ( & V_68 ) ;
V_135 = V_167 [ V_39 ] ;
V_167 [ V_39 ] = NULL ;
F_96 ( & V_68 ) ;
F_151 ( F_85 , V_135 ) ;
}
static int F_152 ( int V_39 )
{
int V_168 ;
if ( V_167 [ V_39 ] != NULL )
return 0 ;
F_150 ( & V_68 ) ;
F_86 ( L_51 ) ;
V_167 [ V_39 ] = F_153 ( F_85 , NULL ,
F_154 ( V_39 ) ,
L_6 ) ;
if ( F_155 ( V_167 [ V_39 ] ) ) {
V_168 = F_156 ( V_167 [ V_39 ] ) ;
F_86 ( L_52 ) ;
V_142 ++ ;
V_167 [ V_39 ] = NULL ;
F_96 ( & V_68 ) ;
return V_168 ;
}
F_157 ( V_167 [ V_39 ] , V_39 ) ;
F_158 ( V_167 [ V_39 ] ) ;
F_96 ( & V_68 ) ;
return 0 ;
}
static int F_159 ( void * args )
{
unsigned long V_169 ;
F_86 ( L_53 ) ;
if ( V_162 > 0 ) {
F_86 ( L_54 ) ;
F_49 ( V_162 * V_37 ) ;
F_86 ( L_55 ) ;
}
if ( ! F_94 () ) {
V_169 = F_160 () + V_161 ;
F_62 ( L_56 ) ;
F_14 () ;
F_74 () ;
while ( F_89 ( F_160 () , V_169 ) )
continue;
F_76 () ;
F_23 () ;
F_62 ( L_57 ) ;
}
F_98 ( L_58 ) ;
while ( ! F_94 () )
F_49 ( 10 * V_37 ) ;
return 0 ;
}
static int T_8 F_161 ( void )
{
if ( V_161 <= 0 )
return 0 ;
return F_162 ( F_159 , NULL , V_170 ) ;
}
static void F_163 ( struct V_29 * V_34 )
{
F_7 ( & V_171 ) ;
}
static int F_164 ( void * V_52 )
{
long V_172 = ( long ) V_52 ;
bool V_173 = 0 ;
bool V_174 ;
struct V_29 V_34 ;
F_88 ( & V_34 ) ;
F_86 ( L_59 ) ;
F_120 ( V_60 , V_119 ) ;
do {
F_165 ( V_175 [ V_172 ] ,
( V_174 =
F_92 ( & V_176 ) ) != V_173 ||
F_91 () ) ;
V_173 = V_174 ;
if ( F_91 () )
break;
V_31 -> V_77 ( & V_34 , F_163 ) ;
if ( F_166 ( & V_177 ) )
F_167 ( & V_178 ) ;
} while ( ! F_91 () );
if ( V_31 -> V_78 != NULL )
V_31 -> V_78 () ;
F_99 ( & V_34 ) ;
F_100 ( L_60 ) ;
return 0 ;
}
static int F_168 ( void * V_52 )
{
int V_21 ;
F_86 ( L_61 ) ;
do {
F_169 ( & V_171 , 0 ) ;
F_169 ( & V_177 , V_163 ) ;
F_84 ( & V_176 , ! V_176 ) ;
for ( V_21 = 0 ; V_21 < V_163 ; V_21 ++ )
F_167 ( & V_175 [ V_21 ] ) ;
F_165 ( V_178 ,
F_123 ( & V_177 ) == 0 ||
F_91 () ) ;
if ( F_91 () )
break;
V_144 ++ ;
V_31 -> V_78 () ;
if ( F_123 ( & V_171 ) != V_163 ) {
V_145 ++ ;
F_170 ( L_62 ,
F_123 ( & V_171 ) ,
V_163 ) ;
F_115 ( 1 ) ;
}
V_143 ++ ;
F_49 ( V_37 / 10 ) ;
} while ( ! F_91 () );
F_100 ( L_63 ) ;
return 0 ;
}
static int F_171 ( void )
{
int V_21 ;
int V_179 ;
if ( V_163 == 0 )
return 0 ;
if ( V_31 -> V_77 == NULL || V_31 -> V_78 == NULL ) {
F_62 ( L_14 V_42
L_64 ,
V_41 , V_31 -> V_104 ) ;
F_62 ( L_14 V_42
L_65 ,
V_41 ) ;
return 0 ;
}
F_169 ( & V_177 , 0 ) ;
F_169 ( & V_171 , 0 ) ;
V_180 =
F_172 ( V_163 * sizeof( V_180 [ 0 ] ) ,
V_181 ) ;
V_175 =
F_172 ( V_163 * sizeof( V_175 [ 0 ] ) ,
V_181 ) ;
if ( V_180 == NULL || ! V_175 )
return - V_182 ;
for ( V_21 = 0 ; V_21 < V_163 ; V_21 ++ ) {
F_173 ( & V_175 [ V_21 ] ) ;
V_179 = F_162 ( F_164 ,
( void * ) ( long ) V_21 ,
V_180 [ V_21 ] ) ;
if ( V_179 )
return V_179 ;
}
return F_162 ( F_168 , NULL , V_183 ) ;
}
static void F_174 ( void )
{
int V_21 ;
F_151 ( F_168 , V_183 ) ;
if ( V_180 != NULL ) {
for ( V_21 = 0 ; V_21 < V_163 ; V_21 ++ )
F_151 ( F_164 ,
V_180 [ V_21 ] ) ;
F_175 ( V_180 ) ;
V_180 = NULL ;
}
if ( V_175 != NULL ) {
F_175 ( V_175 ) ;
V_175 = NULL ;
}
}
static int F_176 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
long V_39 = ( long ) V_187 ;
switch ( V_186 ) {
case V_188 :
case V_189 :
( void ) F_152 ( V_39 ) ;
break;
case V_190 :
F_149 ( V_39 ) ;
break;
default:
break;
}
return V_191 ;
}
static void
F_177 ( void )
{
int V_21 ;
F_178 () ;
if ( F_179 () ) {
if ( V_31 -> V_78 != NULL )
V_31 -> V_78 () ;
return;
}
F_174 () ;
F_151 ( F_159 , V_170 ) ;
F_151 ( F_108 , V_115 ) ;
if ( V_192 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_151 ( F_135 ,
V_192 [ V_21 ] ) ;
F_175 ( V_192 ) ;
}
V_114 = NULL ;
if ( V_193 ) {
for ( V_21 = 0 ; V_21 < V_120 ; V_21 ++ ) {
F_151 ( F_119 ,
V_193 [ V_21 ] ) ;
}
F_175 ( V_193 ) ;
V_193 = NULL ;
}
F_151 ( F_147 , V_194 ) ;
F_151 ( F_107 , V_195 ) ;
for ( V_21 = 0 ; V_21 < V_196 ; V_21 ++ )
F_151 ( F_102 , V_197 [ V_21 ] ) ;
if ( ( V_158 == 1 && V_31 -> V_159 ) ||
V_158 == 2 ) {
F_180 ( & V_198 ) ;
F_63 (i)
F_149 ( V_21 ) ;
}
if ( V_31 -> V_78 != NULL )
V_31 -> V_78 () ;
if ( V_31 -> V_199 != NULL )
V_31 -> V_199 () ;
F_141 () ;
if ( F_123 ( & V_146 ) || V_145 )
F_148 ( V_31 , L_66 ) ;
else if ( F_181 () )
F_148 ( V_31 ,
L_67 ) ;
else
F_148 ( V_31 , L_68 ) ;
F_182 () ;
}
static void F_183 ( struct V_29 * V_71 )
{
}
static void F_184 ( struct V_29 * V_71 )
{
F_62 ( L_69 ) ;
}
static void F_185 ( void )
{
#ifdef F_186
struct V_29 V_200 ;
struct V_29 V_201 ;
F_88 ( & V_200 ) ;
F_88 ( & V_201 ) ;
F_62 ( L_70 ) ;
F_74 () ;
F_14 () ;
F_33 ( & V_200 , F_183 ) ;
F_187 () ;
F_33 ( & V_201 , F_183 ) ;
F_33 ( & V_201 , F_184 ) ;
F_188 () ;
F_23 () ;
F_76 () ;
F_189 () ;
F_62 ( L_71 ) ;
F_99 ( & V_200 ) ;
F_99 ( & V_201 ) ;
#else
F_62 ( L_72 ) ;
#endif
}
static int T_8
F_190 ( void )
{
int V_21 ;
int V_39 ;
int V_202 = 0 ;
static struct V_152 * V_203 [] = {
& V_204 , & V_205 , & V_206 , & V_207 , & V_208 ,
& V_209 , V_210
} ;
if ( ! F_191 ( V_41 , V_154 , & V_211 ) )
return - V_212 ;
for ( V_21 = 0 ; V_21 < F_192 ( V_203 ) ; V_21 ++ ) {
V_31 = V_203 [ V_21 ] ;
if ( strcmp ( V_41 , V_31 -> V_104 ) == 0 )
break;
}
if ( V_21 == F_192 ( V_203 ) ) {
F_62 ( L_73 ,
V_41 ) ;
F_62 ( L_74 ) ;
for ( V_21 = 0 ; V_21 < F_192 ( V_203 ) ; V_21 ++ )
F_62 ( L_75 , V_203 [ V_21 ] -> V_104 ) ;
F_62 ( L_3 ) ;
F_193 () ;
return - V_213 ;
}
if ( V_31 -> V_85 == NULL && V_84 != 0 ) {
F_62 ( L_76 ) ;
V_84 = 0 ;
}
if ( V_31 -> V_214 )
V_31 -> V_214 () ;
if ( V_215 >= 0 ) {
V_18 = V_215 ;
} else {
V_18 = F_194 () - 2 - V_215 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_148 ( V_31 , L_77 ) ;
F_35 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_192 ( V_216 ) ; V_21 ++ ) {
V_216 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_216 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_114 = NULL ;
V_117 = 0 ;
F_169 ( & V_10 , 0 ) ;
F_169 ( & V_9 , 0 ) ;
F_169 ( & V_13 , 0 ) ;
F_169 ( & V_129 , 0 ) ;
F_169 ( & V_146 , 0 ) ;
V_145 = 0 ;
V_142 = 0 ;
V_62 = 0 ;
V_67 = 0 ;
V_70 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_169 ( & V_24 [ V_21 ] , 0 ) ;
F_63 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_142 ( V_132 , V_39 ) [ V_21 ] = 0 ;
F_142 ( V_133 , V_39 ) [ V_21 ] = 0 ;
}
}
V_202 = F_162 ( F_108 , NULL ,
V_115 ) ;
if ( V_202 )
goto V_217;
V_193 = F_172 ( V_120 * sizeof( V_193 [ 0 ] ) ,
V_181 ) ;
if ( V_193 == NULL ) {
F_195 ( L_78 ) ;
V_202 = - V_182 ;
goto V_217;
}
for ( V_21 = 0 ; V_21 < V_120 ; V_21 ++ ) {
V_202 = F_162 ( F_119 ,
NULL , V_193 [ V_21 ] ) ;
if ( V_202 )
goto V_217;
}
V_192 = F_172 ( V_18 * sizeof( V_192 [ 0 ] ) ,
V_181 ) ;
if ( V_192 == NULL ) {
F_195 ( L_78 ) ;
V_202 = - V_182 ;
goto V_217;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_202 = F_162 ( F_135 , NULL ,
V_192 [ V_21 ] ) ;
if ( V_202 )
goto V_217;
}
if ( V_151 > 0 ) {
V_202 = F_162 ( F_147 , NULL ,
V_194 ) ;
if ( V_202 )
goto V_217;
}
if ( V_155 ) {
V_202 = F_196 ( V_156 * V_37 ) ;
if ( V_202 )
goto V_217;
}
if ( V_157 < 0 )
V_157 = 0 ;
if ( V_157 ) {
V_202 = F_197 ( V_157 * V_37 ) ;
if ( V_202 )
goto V_217;
}
if ( V_84 < 0 )
V_84 = 0 ;
if ( V_84 ) {
V_202 = F_162 ( F_107 , NULL ,
V_195 ) ;
if ( V_202 )
goto V_217;
}
if ( V_69 < 1 )
V_69 = 1 ;
if ( V_66 < 2 )
V_66 = 2 ;
if ( ( V_158 == 1 && V_31 -> V_159 ) ||
V_158 == 2 ) {
V_63 = V_64 + V_69 * V_37 ;
F_198 ( & V_198 ) ;
F_63 (i) {
if ( F_199 ( V_21 ) )
continue;
V_202 = F_152 ( V_21 ) ;
if ( V_202 )
goto V_217;
}
}
V_202 = F_200 ( V_160 , F_177 ) ;
if ( V_202 )
goto V_217;
V_202 = F_201 ( V_165 * V_37 , V_164 * V_37 ) ;
if ( V_202 )
goto V_217;
V_202 = F_161 () ;
if ( V_202 )
goto V_217;
V_202 = F_171 () ;
if ( V_202 )
goto V_217;
if ( V_218 )
F_185 () ;
if ( V_79 > 0 ) {
V_196 = ( F_194 () + 3 ) / 4 ;
V_197 = F_202 ( V_196 , sizeof( * V_197 ) ,
V_181 ) ;
if ( ! V_197 ) {
F_195 ( L_78 ) ;
V_202 = - V_182 ;
goto V_217;
}
for ( V_21 = 0 ; V_21 < V_196 ; V_21 ++ ) {
V_202 = F_162 ( F_102 ,
NULL ,
V_197 [ V_21 ] ) ;
if ( V_202 )
goto V_217;
}
}
F_178 () ;
F_193 () ;
return 0 ;
V_217:
F_193 () ;
F_177 () ;
return V_202 ;
}
