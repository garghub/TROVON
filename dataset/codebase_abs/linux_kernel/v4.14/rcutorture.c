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
( void ) F_6 ( V_4 , V_5 ) ;
return V_4 ;
}
static T_1 T_2 F_4 ( void )
{
return 0ULL ;
}
static struct V_6 *
F_7 ( void )
{
struct V_7 * V_8 ;
F_8 ( & V_9 ) ;
if ( F_9 ( & V_10 ) ) {
F_10 ( & V_11 ) ;
F_11 ( & V_9 ) ;
return NULL ;
}
F_10 ( & V_12 ) ;
V_8 = V_10 . V_13 ;
F_12 ( V_8 ) ;
F_11 ( & V_9 ) ;
return F_13 ( V_8 , struct V_6 , V_14 ) ;
}
static void
F_14 ( struct V_6 * V_8 )
{
F_10 ( & V_15 ) ;
F_8 ( & V_9 ) ;
F_15 ( & V_8 -> V_14 , & V_10 ) ;
F_11 ( & V_9 ) ;
}
static int F_16 ( void ) __acquires( T_3 )
{
F_17 () ;
return 0 ;
}
static void F_18 ( struct V_16 * V_17 )
{
unsigned long V_18 ;
unsigned long V_19 ;
const unsigned long V_20 = 200 ;
const unsigned long V_21 = 50 ;
unsigned long long V_4 ;
if ( ! ( F_19 ( V_17 ) % ( V_22 * 2000 * V_21 ) ) ) {
V_18 = V_23 -> V_19 () ;
V_4 = F_4 () ;
F_20 ( V_21 ) ;
V_19 = V_23 -> V_19 () ;
F_21 ( V_23 -> V_24 , NULL , V_4 ,
V_18 , V_19 ) ;
}
if ( ! ( F_19 ( V_17 ) % ( V_22 * 2 * V_20 ) ) )
F_22 ( V_20 ) ;
#ifdef F_23
if ( ! F_24 () &&
! ( F_19 ( V_17 ) % ( V_22 * 20000 ) ) )
F_25 () ;
#endif
}
static void F_26 ( int V_25 ) __releases( T_3 )
{
F_27 () ;
}
static bool
F_28 ( struct V_6 * V_26 )
{
int V_1 ;
V_1 = V_26 -> V_27 ;
if ( V_1 > V_28 )
V_1 = V_28 ;
F_10 ( & V_29 [ V_1 ] ) ;
if ( ++ V_26 -> V_27 >= V_28 ) {
V_26 -> V_30 = 0 ;
return true ;
}
return false ;
}
static void
F_29 ( struct V_6 * V_31 )
{
struct V_6 * V_26 ;
struct V_6 * V_32 ;
if ( V_31 )
F_30 ( & V_31 -> V_14 , & V_33 ) ;
F_31 (rp, rp1, &rcu_torture_removed, rtort_free) {
if ( F_28 ( V_26 ) ) {
F_32 ( & V_26 -> V_14 ) ;
F_14 ( V_26 ) ;
}
}
}
static void
F_33 ( struct V_34 * V_8 )
{
struct V_6 * V_26 = F_13 ( V_8 , struct V_6 , V_35 ) ;
if ( F_34 () ) {
return;
}
if ( F_28 ( V_26 ) )
F_14 ( V_26 ) ;
else
V_23 -> V_36 ( V_26 ) ;
}
static unsigned long F_35 ( void )
{
return 0 ;
}
static void F_36 ( struct V_6 * V_8 )
{
F_37 ( & V_8 -> V_35 , F_33 ) ;
}
static void F_38 ( void )
{
F_39 ( & V_33 ) ;
}
static int F_40 ( void ) __acquires( T_4 )
{
F_41 () ;
return 0 ;
}
static void F_42 ( int V_25 ) __releases( T_4 )
{
F_43 () ;
}
static void F_44 ( struct V_6 * V_8 )
{
F_45 ( & V_8 -> V_35 , F_33 ) ;
}
static void F_46 ( struct V_6 * V_8 )
{
F_33 ( & V_8 -> V_35 ) ;
}
static void F_47 ( void )
{
}
static void
F_48 ( struct V_34 * V_37 , T_5 V_38 )
{
V_38 ( V_37 ) ;
}
static int F_49 ( void ) __acquires( T_6 )
{
return F_50 ( T_6 ) ;
}
static void F_51 ( struct V_16 * V_17 )
{
long V_39 ;
const long V_40 = 1000000 / V_41 ;
const long V_42 = 10 ;
V_39 = F_19 ( V_17 ) %
( V_22 * 2 * V_42 * V_40 ) ;
if ( ! V_39 && F_52 () )
F_53 ( V_42 ) ;
else
F_18 ( V_17 ) ;
}
static void F_54 ( int V_25 ) __releases( T_6 )
{
F_55 ( T_6 , V_25 ) ;
}
static unsigned long F_56 ( void )
{
return F_57 ( T_6 ) ;
}
static void F_58 ( struct V_6 * V_26 )
{
F_59 ( T_6 , & V_26 -> V_35 , F_33 ) ;
}
static void F_60 ( void )
{
F_61 ( T_6 ) ;
}
static void F_62 ( struct V_34 * V_37 ,
T_5 V_38 )
{
F_59 ( T_6 , V_37 , V_38 ) ;
}
static void F_63 ( void )
{
F_64 ( T_6 ) ;
}
static void F_65 ( void )
{
F_66 ( T_6 , V_43 , V_44 ) ;
}
static void F_67 ( void )
{
F_68 ( T_6 ) ;
}
static void F_69 ( void )
{
F_38 () ;
F_70 ( F_71 ( & V_45 ) ) ;
T_6 = & V_45 ;
}
static void F_72 ( void )
{
F_73 ( & V_45 ) ;
T_6 = & V_46 ;
}
static int F_74 ( void )
{
F_75 () ;
return 0 ;
}
static void F_76 ( int V_25 )
{
F_77 () ;
}
static void F_78 ( struct V_6 * V_8 )
{
F_79 ( & V_8 -> V_35 , F_33 ) ;
}
static int F_80 ( void )
{
return 0 ;
}
static void F_81 ( int V_25 )
{
}
static void F_82 ( struct V_6 * V_8 )
{
F_83 ( & V_8 -> V_35 , F_33 ) ;
}
static bool T_7 F_84 ( void )
{
return V_23 == & V_47 ;
}
static void F_85 ( struct V_34 * V_37 )
{
struct V_48 * V_49 =
F_13 ( V_37 , struct V_48 , V_50 ) ;
F_86 ( & V_49 -> V_51 , 0 ) ;
}
static int F_87 ( void * V_52 )
{
unsigned long V_53 ;
unsigned long V_54 ;
unsigned long V_55 ;
struct V_48 V_56 = { . V_51 = 0 } ;
struct V_57 V_58 ;
F_88 ( L_2 ) ;
V_58 . V_59 = 1 ;
if ( F_89 ( V_60 , V_61 , & V_58 ) < 0 ) {
F_88 ( L_3 ) ;
V_62 ++ ;
}
F_90 ( & V_56 . V_50 ) ;
do {
V_55 = V_63 ;
while ( F_91 ( V_64 , V_55 ) ) {
F_53 ( V_55 - V_64 ) ;
F_92 ( L_4 ) ;
if ( F_93 () )
goto V_65;
}
V_54 = V_55 + V_66 * V_41 ;
V_53 = V_64 ;
while ( F_91 ( V_64 , V_54 ) ) {
if ( ! F_94 ( & V_56 . V_51 ) ) {
F_86 ( & V_56 . V_51 , 1 ) ;
F_37 ( & V_56 . V_50 , F_85 ) ;
if ( V_64 - V_53 >
V_66 * V_41 - V_41 / 2 ) {
F_88 ( L_5 ) ;
V_67 ++ ;
}
V_53 = V_64 ;
}
F_92 ( L_4 ) ;
if ( F_93 () )
goto V_65;
}
while ( V_55 == V_63 &&
! F_95 () ) {
if ( F_96 ( & V_68 ) ) {
V_63 = V_64 +
V_69 * V_41 ;
V_70 ++ ;
F_97 ( & V_68 ) ;
break;
}
F_98 ( 1 ) ;
}
V_65: F_92 ( L_4 ) ;
} while ( ! F_93 () );
while ( ! F_95 () || F_94 ( & V_56 . V_51 ) ) {
F_99 ( L_4 ) ;
F_98 ( 1 ) ;
}
F_100 ( & V_56 . V_50 ) ;
F_101 ( L_4 ) ;
return 0 ;
}
static void F_102 ( struct V_34 * V_71 )
{
}
static int
F_103 ( void * V_52 )
{
int V_72 = 1 ;
int V_1 ;
int V_73 ;
struct V_34 * V_71 ;
if ( V_74 > 0 &&
V_75 > 0 &&
V_76 > 0 &&
V_23 -> V_77 &&
V_23 -> V_78 ) {
V_71 = F_104 ( sizeof( * V_71 ) *
V_79 * V_74 ) ;
V_72 = ! V_71 ;
}
if ( V_72 ) {
F_88 ( L_6 ) ;
goto V_80;
}
F_88 ( L_7 ) ;
do {
F_53 ( V_75 ) ;
F_105 ( & V_81 ) ;
F_70 ( F_106 ( V_60 ) ) ;
for ( V_1 = 0 ; V_1 < V_79 ; V_1 ++ ) {
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_23 -> V_77 ( & V_71 [ V_1 * V_74 + V_73 ] ,
F_102 ) ;
}
F_53 ( V_76 ) ;
F_70 ( F_106 ( V_60 ) ) ;
}
V_23 -> V_78 () ;
F_92 ( L_8 ) ;
} while ( ! F_93 () );
F_107 ( V_71 ) ;
V_80:
F_101 ( L_8 ) ;
return 0 ;
}
static int
F_108 ( void * V_52 )
{
unsigned long V_82 ;
int V_83 ;
F_88 ( L_9 ) ;
do {
V_82 = V_64 + V_84 * V_41 ;
while ( F_91 ( V_64 , V_82 ) &&
! F_95 () ) {
F_53 ( 1 ) ;
}
V_83 = V_85 ;
while ( V_83 > 0 &&
! F_95 () ) {
V_23 -> V_86 () ;
F_22 ( V_87 ) ;
V_83 -= V_87 ;
}
F_92 ( L_10 ) ;
} while ( ! F_93 () );
F_101 ( L_10 ) ;
return 0 ;
}
static int
F_109 ( void * V_52 )
{
bool V_88 = ! F_110 () && ! F_111 () ;
int V_89 = 0 ;
unsigned long V_90 ;
bool V_91 = V_92 , V_93 = V_94 , V_95 = V_96 ;
bool V_97 = V_98 ;
int V_1 ;
struct V_6 * V_26 ;
struct V_6 * V_31 ;
static F_112 ( rand ) ;
int V_99 [] = { V_100 , V_101 ,
V_102 , V_103 } ;
int V_104 = 0 ;
F_88 ( L_11 ) ;
if ( ! V_88 ) {
F_113 ( L_12 V_44
L_13 ,
V_43 , V_23 -> V_24 ) ;
F_113 ( L_12 V_44
L_14 ,
V_43 ) ;
}
if ( ! V_91 && ! V_93 && ! V_95 && ! V_97 )
V_91 = V_93 = V_95 = V_97 = true ;
if ( V_91 && V_23 -> V_105 && V_23 -> V_106 )
V_99 [ V_104 ++ ] = V_102 ;
else if ( V_92 && ( ! V_23 -> V_105 || ! V_23 -> V_106 ) )
F_113 ( L_15 ) ;
if ( V_93 && V_23 -> V_107 )
V_99 [ V_104 ++ ] = V_101 ;
else if ( V_94 && ! V_23 -> V_107 )
F_113 ( L_16 ) ;
if ( V_95 && V_23 -> V_36 )
V_99 [ V_104 ++ ] = V_100 ;
else if ( V_96 && ! V_23 -> V_36 )
F_113 ( L_17 ) ;
if ( V_97 && V_23 -> V_108 )
V_99 [ V_104 ++ ] = V_103 ;
else if ( V_98 && ! V_23 -> V_108 )
F_113 ( L_18 ) ;
if ( F_114 ( V_104 == 0 ,
L_19 ) ) {
V_2 = V_109 ;
F_101 ( L_20 ) ;
}
do {
V_2 = V_110 ;
F_98 ( 1 ) ;
V_26 = F_7 () ;
if ( V_26 == NULL )
continue;
V_26 -> V_27 = 0 ;
V_2 = V_111 ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
V_2 = V_112 ;
V_31 = F_115 ( V_113 ,
V_60 == V_114 ) ;
V_26 -> V_30 = 1 ;
F_116 ( V_113 , V_26 ) ;
F_117 () ;
if ( V_31 ) {
V_1 = V_31 -> V_27 ;
if ( V_1 > V_28 )
V_1 = V_28 ;
F_10 ( & V_29 [ V_1 ] ) ;
V_31 -> V_27 ++ ;
switch ( V_99 [ F_19 ( & rand ) % V_104 ] ) {
case V_100 :
V_2 = V_100 ;
V_23 -> V_36 ( V_31 ) ;
break;
case V_101 :
V_2 = V_101 ;
V_23 -> V_107 () ;
F_29 ( V_31 ) ;
break;
case V_102 :
V_2 = V_102 ;
V_90 = V_23 -> V_105 () ;
V_1 = F_19 ( & rand ) % 16 ;
if ( V_1 != 0 )
F_53 ( V_1 ) ;
F_22 ( F_19 ( & rand ) % 1000 ) ;
V_2 = V_115 ;
V_23 -> V_106 ( V_90 ) ;
F_29 ( V_31 ) ;
break;
case V_103 :
V_2 = V_103 ;
V_23 -> V_108 () ;
F_29 ( V_31 ) ;
break;
default:
F_118 ( 1 ) ;
break;
}
}
F_119 ( ++ V_116 ) ;
if ( V_88 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_89 - 1 ) ) ) {
F_118 ( V_89 == 0 && F_110 () ) ;
if ( V_89 >= 0 )
F_120 () ;
else
F_121 () ;
if ( ++ V_89 > 3 )
V_89 = - V_89 ;
}
V_2 = V_117 ;
F_92 ( L_20 ) ;
} while ( ! F_93 () );
if ( V_89 > 0 )
V_89 = - V_89 ;
while ( V_88 && V_89 ++ < 0 )
F_121 () ;
F_118 ( V_88 && F_110 () ) ;
V_2 = V_109 ;
F_101 ( L_20 ) ;
return 0 ;
}
static int
F_122 ( void * V_52 )
{
F_112 ( rand ) ;
F_88 ( L_21 ) ;
F_123 ( V_60 , V_118 ) ;
do {
F_98 ( 1 + F_19 ( & rand ) % 10 ) ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
if ( V_23 -> V_78 != NULL &&
F_19 ( & rand ) % ( V_119 * 8 ) == 0 ) {
V_23 -> V_78 () ;
} else if ( V_96 == V_94 ) {
if ( F_19 ( & rand ) & 0x80 )
V_23 -> V_108 () ;
else
V_23 -> V_107 () ;
} else if ( V_96 ) {
V_23 -> V_108 () ;
} else {
V_23 -> V_107 () ;
}
F_92 ( L_22 ) ;
} while ( ! F_93 () );
F_101 ( L_22 ) ;
return 0 ;
}
static void F_124 ( struct V_34 * V_71 )
{
F_125 ( V_71 ) ;
}
static void F_126 ( unsigned long V_120 )
{
int V_25 ;
unsigned long V_18 ;
unsigned long V_19 ;
static F_112 ( rand ) ;
static F_127 ( V_121 ) ;
struct V_6 * V_8 ;
int V_122 ;
unsigned long long V_4 ;
V_25 = V_23 -> V_123 () ;
if ( V_23 -> V_18 )
V_18 = V_23 -> V_18 () ;
else
V_18 = V_23 -> V_19 () ;
V_4 = F_4 () ;
V_8 = F_115 ( V_113 ,
F_128 () ||
F_129 () ||
F_130 ( T_6 ) ||
F_84 () ) ;
if ( V_8 == NULL ) {
V_23 -> V_124 ( V_25 ) ;
return;
}
if ( V_8 -> V_30 == 0 )
F_10 ( & V_125 ) ;
F_131 ( & V_121 ) ;
V_23 -> V_126 ( & rand ) ;
V_127 ++ ;
F_132 ( & V_121 ) ;
F_75 () ;
V_122 = V_8 -> V_27 ;
if ( V_122 > V_28 ) {
V_122 = V_28 ;
}
V_19 = V_23 -> V_19 () ;
if ( V_122 > 1 ) {
F_21 ( V_23 -> V_24 , & V_8 -> V_35 , V_4 ,
V_18 , V_19 ) ;
F_133 ( V_128 ) ;
}
F_134 ( V_129 [ V_122 ] ) ;
V_19 = V_19 - V_18 ;
if ( V_23 -> V_18 )
V_19 ++ ;
if ( V_19 > V_28 ) {
V_19 = V_28 ;
}
F_134 ( V_130 [ V_19 ] ) ;
F_77 () ;
V_23 -> V_124 ( V_25 ) ;
if ( V_23 -> V_77 ) {
struct V_34 * V_71 = F_135 ( sizeof( * V_71 ) , V_131 ) ;
if ( V_71 )
V_23 -> V_77 ( V_71 , F_124 ) ;
}
}
static int
F_136 ( void * V_52 )
{
unsigned long V_18 ;
unsigned long V_19 ;
int V_25 ;
F_112 ( rand ) ;
struct V_6 * V_8 ;
int V_122 ;
struct V_132 V_133 ;
unsigned long long V_4 ;
F_88 ( L_23 ) ;
F_123 ( V_60 , V_118 ) ;
if ( V_134 && V_23 -> V_135 )
F_137 ( & V_133 , F_126 , 0 ) ;
do {
if ( V_134 && V_23 -> V_135 ) {
if ( ! F_138 ( & V_133 ) )
F_139 ( & V_133 , V_64 + 1 ) ;
}
V_25 = V_23 -> V_123 () ;
if ( V_23 -> V_18 )
V_18 = V_23 -> V_18 () ;
else
V_18 = V_23 -> V_19 () ;
V_4 = F_4 () ;
V_8 = F_115 ( V_113 ,
F_128 () ||
F_129 () ||
F_130 ( T_6 ) ||
F_84 () ) ;
if ( V_8 == NULL ) {
V_23 -> V_124 ( V_25 ) ;
F_53 ( V_41 ) ;
continue;
}
if ( V_8 -> V_30 == 0 )
F_10 ( & V_125 ) ;
V_23 -> V_126 ( & rand ) ;
F_75 () ;
V_122 = V_8 -> V_27 ;
if ( V_122 > V_28 ) {
V_122 = V_28 ;
}
V_19 = V_23 -> V_19 () ;
if ( V_122 > 1 ) {
F_21 ( V_23 -> V_24 , & V_8 -> V_35 ,
V_4 , V_18 , V_19 ) ;
F_133 ( V_128 ) ;
}
F_134 ( V_129 [ V_122 ] ) ;
V_19 = V_19 - V_18 ;
if ( V_23 -> V_18 )
V_19 ++ ;
if ( V_19 > V_28 ) {
V_19 = V_28 ;
}
F_134 ( V_130 [ V_19 ] ) ;
F_77 () ;
V_23 -> V_124 ( V_25 ) ;
F_92 ( L_24 ) ;
} while ( ! F_93 () );
if ( V_134 && V_23 -> V_135 ) {
F_140 ( & V_133 ) ;
F_141 ( & V_133 ) ;
}
F_101 ( L_24 ) ;
return 0 ;
}
static void
F_142 ( void )
{
int V_136 ;
int V_1 ;
long V_137 [ V_28 + 1 ] = { 0 } ;
long V_138 [ V_28 + 1 ] = { 0 } ;
static unsigned long V_139 = V_140 ;
struct V_141 * V_142 ;
F_143 (cpu) {
for ( V_1 = 0 ; V_1 < V_28 + 1 ; V_1 ++ ) {
V_137 [ V_1 ] += F_144 ( V_129 , V_136 ) [ V_1 ] ;
V_138 [ V_1 ] += F_144 ( V_130 , V_136 ) [ V_1 ] ;
}
}
for ( V_1 = V_28 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_137 [ V_1 ] != 0 )
break;
}
F_113 ( L_25 , V_43 , V_44 ) ;
F_145 ( L_26 ,
V_113 ,
V_116 ,
F_9 ( & V_10 ) ,
F_146 ( & V_12 ) ,
F_146 ( & V_11 ) ,
F_146 ( & V_15 ) ) ;
F_145 ( L_27 ,
F_146 ( & V_125 ) ,
V_143 ,
V_144 ,
V_62 ) ;
F_145 ( L_28 ,
V_67 ,
V_70 ,
V_127 ) ;
F_147 () ;
F_145 ( L_29 ,
V_145 ,
V_146 ,
V_143 ) ;
F_145 ( L_30 , F_148 ( & V_81 ) ) ;
F_113 ( L_25 , V_43 , V_44 ) ;
if ( F_146 ( & V_125 ) != 0 ||
V_143 != 0 ||
V_144 != 0 ||
V_62 != 0 ||
V_67 != 0 ||
V_1 > 1 ) {
F_145 ( L_12 , L_31 ) ;
F_10 ( & V_147 ) ;
F_118 ( 1 ) ;
}
F_145 ( L_32 ) ;
for ( V_1 = 0 ; V_1 < V_28 + 1 ; V_1 ++ )
F_145 ( L_33 , V_137 [ V_1 ] ) ;
F_145 ( L_34 ) ;
F_113 ( L_25 , V_43 , V_44 ) ;
F_145 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_28 + 1 ; V_1 ++ )
F_145 ( L_33 , V_138 [ V_1 ] ) ;
F_145 ( L_34 ) ;
F_113 ( L_25 , V_43 , V_44 ) ;
F_145 ( L_36 ) ;
for ( V_1 = 0 ; V_1 < V_28 + 1 ; V_1 ++ ) {
F_145 ( L_37 , F_146 ( & V_29 [ V_1 ] ) ) ;
}
F_145 ( L_34 ) ;
if ( V_23 -> V_148 )
V_23 -> V_148 () ;
if ( V_139 == V_116 &&
V_113 != NULL ) {
int T_7 V_149 = 0 ;
unsigned long T_7 V_150 = 0 ;
unsigned long T_7 V_19 = 0 ;
F_149 ( V_23 -> V_151 ,
& V_149 , & V_150 , & V_19 ) ;
F_150 ( V_23 -> V_151 , T_6 ,
& V_149 , & V_150 , & V_19 ) ;
V_142 = F_2 ( V_114 ) ;
F_113 ( L_38 ,
F_1 () ,
V_2 ,
V_150 , V_19 , V_149 ,
V_142 == NULL ? ~ 0UL : V_142 -> V_152 ,
V_142 == NULL ? - 1 : ( int ) F_151 ( V_142 ) ) ;
F_152 () ;
F_133 ( V_128 ) ;
}
V_139 = V_116 ;
}
static int
F_153 ( void * V_52 )
{
F_88 ( L_39 ) ;
do {
F_53 ( V_153 * V_41 ) ;
F_142 () ;
F_99 ( L_40 ) ;
} while ( ! F_93 () );
F_101 ( L_40 ) ;
return 0 ;
}
static inline void
F_154 ( struct V_154 * V_23 , const char * V_155 )
{
F_113 ( L_12 V_44
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49 ,
V_43 , V_155 , V_22 , V_119 ,
V_153 , V_156 , V_157 , V_158 ,
V_159 , V_134 , V_85 , V_87 , V_84 ,
V_160 , V_23 -> V_161 ,
V_69 , V_66 , V_162 ,
V_163 , V_164 ,
V_165 ,
V_166 , V_167 ) ;
}
static int F_155 ( unsigned int V_136 )
{
struct V_141 * V_133 ;
if ( V_168 [ V_136 ] == NULL )
return 0 ;
F_156 ( & V_68 ) ;
V_133 = V_168 [ V_136 ] ;
V_168 [ V_136 ] = NULL ;
F_97 ( & V_68 ) ;
F_157 ( F_87 , V_133 ) ;
return 0 ;
}
static int F_158 ( unsigned int V_136 )
{
int V_169 ;
if ( V_168 [ V_136 ] != NULL )
return 0 ;
F_156 ( & V_68 ) ;
F_88 ( L_50 ) ;
V_168 [ V_136 ] = F_159 ( F_87 , NULL ,
F_160 ( V_136 ) ,
L_4 ) ;
if ( F_161 ( V_168 [ V_136 ] ) ) {
V_169 = F_162 ( V_168 [ V_136 ] ) ;
F_88 ( L_51 ) ;
V_144 ++ ;
V_168 [ V_136 ] = NULL ;
F_97 ( & V_68 ) ;
return V_169 ;
}
F_163 ( V_168 [ V_136 ] , V_136 ) ;
F_164 ( V_168 [ V_136 ] ) ;
F_97 ( & V_68 ) ;
return 0 ;
}
static int F_165 ( void * args )
{
unsigned long V_170 ;
F_88 ( L_52 ) ;
if ( V_164 > 0 ) {
F_88 ( L_53 ) ;
F_53 ( V_164 * V_41 ) ;
F_88 ( L_54 ) ;
}
if ( ! F_95 () ) {
V_170 = F_166 () + V_163 ;
F_113 ( L_55 ) ;
F_17 () ;
F_75 () ;
while ( F_91 ( F_166 () , V_170 ) )
continue;
F_77 () ;
F_27 () ;
F_113 ( L_56 ) ;
}
F_99 ( L_57 ) ;
while ( ! F_95 () )
F_53 ( 10 * V_41 ) ;
return 0 ;
}
static int T_8 F_167 ( void )
{
if ( V_163 <= 0 )
return 0 ;
return F_168 ( F_165 , NULL , V_171 ) ;
}
static void F_169 ( struct V_34 * V_50 )
{
F_10 ( & V_172 ) ;
}
static int F_170 ( void * V_52 )
{
long V_173 = ( long ) V_52 ;
bool V_174 = 0 ;
bool V_175 ;
struct V_34 V_50 ;
F_90 ( & V_50 ) ;
F_88 ( L_58 ) ;
F_123 ( V_60 , V_118 ) ;
do {
F_171 ( V_176 [ V_173 ] ,
( V_175 =
F_94 ( & V_177 ) ) != V_174 ||
F_93 () ) ;
V_174 = V_175 ;
if ( F_93 () )
break;
F_172 () ;
V_23 -> V_77 ( & V_50 , F_169 ) ;
F_173 () ;
if ( F_174 ( & V_178 ) )
F_175 ( & V_179 ) ;
} while ( ! F_93 () );
if ( V_23 -> V_78 != NULL )
V_23 -> V_78 () ;
F_100 ( & V_50 ) ;
F_101 ( L_59 ) ;
return 0 ;
}
static int F_176 ( void * V_52 )
{
int V_1 ;
F_88 ( L_60 ) ;
do {
F_177 ( & V_172 , 0 ) ;
F_177 ( & V_178 , V_165 ) ;
F_86 ( & V_177 , ! V_177 ) ;
for ( V_1 = 0 ; V_1 < V_165 ; V_1 ++ )
F_175 ( & V_176 [ V_1 ] ) ;
F_171 ( V_179 ,
F_146 ( & V_178 ) == 0 ||
F_93 () ) ;
if ( F_93 () )
break;
V_146 ++ ;
V_23 -> V_78 () ;
if ( F_146 ( & V_172 ) != V_165 ) {
V_143 ++ ;
F_178 ( L_61 ,
F_146 ( & V_172 ) ,
V_165 ) ;
F_118 ( 1 ) ;
}
V_145 ++ ;
F_53 ( V_41 / 10 ) ;
} while ( ! F_93 () );
F_101 ( L_62 ) ;
return 0 ;
}
static int F_179 ( void )
{
int V_1 ;
int V_180 ;
if ( V_165 <= 0 )
return 0 ;
if ( V_23 -> V_77 == NULL || V_23 -> V_78 == NULL ) {
F_113 ( L_12 V_44
L_63 ,
V_43 , V_23 -> V_24 ) ;
F_113 ( L_12 V_44
L_64 ,
V_43 ) ;
return 0 ;
}
F_177 ( & V_178 , 0 ) ;
F_177 ( & V_172 , 0 ) ;
V_181 =
F_180 ( V_165 * sizeof( V_181 [ 0 ] ) ,
V_182 ) ;
V_176 =
F_180 ( V_165 * sizeof( V_176 [ 0 ] ) ,
V_182 ) ;
if ( V_181 == NULL || ! V_176 )
return - V_183 ;
for ( V_1 = 0 ; V_1 < V_165 ; V_1 ++ ) {
F_181 ( & V_176 [ V_1 ] ) ;
V_180 = F_168 ( F_170 ,
( void * ) ( long ) V_1 ,
V_181 [ V_1 ] ) ;
if ( V_180 )
return V_180 ;
}
return F_168 ( F_176 , NULL , V_184 ) ;
}
static void F_182 ( void )
{
int V_1 ;
F_157 ( F_176 , V_184 ) ;
if ( V_181 != NULL ) {
for ( V_1 = 0 ; V_1 < V_165 ; V_1 ++ )
F_157 ( F_170 ,
V_181 [ V_1 ] ) ;
F_125 ( V_181 ) ;
V_181 = NULL ;
}
if ( V_176 != NULL ) {
F_125 ( V_176 ) ;
V_176 = NULL ;
}
}
static void
F_183 ( void )
{
int V_1 ;
F_184 () ;
if ( F_185 () ) {
if ( V_23 -> V_78 != NULL )
V_23 -> V_78 () ;
return;
}
F_182 () ;
F_157 ( F_165 , V_171 ) ;
F_157 ( F_109 , V_114 ) ;
if ( V_185 ) {
for ( V_1 = 0 ; V_1 < V_22 ; V_1 ++ )
F_157 ( F_136 ,
V_185 [ V_1 ] ) ;
F_125 ( V_185 ) ;
}
V_113 = NULL ;
if ( V_186 ) {
for ( V_1 = 0 ; V_1 < V_119 ; V_1 ++ ) {
F_157 ( F_122 ,
V_186 [ V_1 ] ) ;
}
F_125 ( V_186 ) ;
V_186 = NULL ;
}
F_157 ( F_153 , V_187 ) ;
F_157 ( F_108 , V_188 ) ;
for ( V_1 = 0 ; V_1 < V_189 ; V_1 ++ )
F_157 ( F_103 , V_190 [ V_1 ] ) ;
if ( ( V_160 == 1 && V_23 -> V_161 ) ||
V_160 == 2 )
F_186 ( V_191 ) ;
if ( V_23 -> V_78 != NULL )
V_23 -> V_78 () ;
if ( V_23 -> V_192 != NULL )
V_23 -> V_192 () ;
F_142 () ;
if ( F_146 ( & V_147 ) || V_143 )
F_154 ( V_23 , L_65 ) ;
else if ( F_187 () )
F_154 ( V_23 ,
L_66 ) ;
else
F_154 ( V_23 , L_67 ) ;
F_188 () ;
}
static void F_189 ( struct V_34 * V_71 )
{
}
static void F_190 ( struct V_34 * V_71 )
{
F_113 ( L_68 ) ;
}
static void F_191 ( void )
{
#ifdef F_192
struct V_34 V_193 ;
struct V_34 V_194 ;
F_90 ( & V_193 ) ;
F_90 ( & V_194 ) ;
F_113 ( L_69 ) ;
F_75 () ;
F_17 () ;
F_37 ( & V_193 , F_189 ) ;
F_172 () ;
F_37 ( & V_194 , F_189 ) ;
F_37 ( & V_194 , F_190 ) ;
F_173 () ;
F_27 () ;
F_77 () ;
F_193 () ;
F_113 ( L_70 ) ;
F_100 ( & V_193 ) ;
F_100 ( & V_194 ) ;
#else
F_113 ( L_71 ) ;
#endif
}
static int T_8
F_194 ( void )
{
int V_1 ;
int V_136 ;
int V_195 = 0 ;
static struct V_154 * V_196 [] = {
& V_197 , & V_198 , & V_199 , & V_200 , & V_201 ,
& V_202 , & V_47 ,
} ;
if ( ! F_195 ( V_43 , V_156 , & V_203 ) )
return - V_204 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_196 ) ; V_1 ++ ) {
V_23 = V_196 [ V_1 ] ;
if ( strcmp ( V_43 , V_23 -> V_24 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_196 ) ) {
F_113 ( L_72 ,
V_43 ) ;
F_113 ( L_73 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_196 ) ; V_1 ++ )
F_113 ( L_74 , V_196 [ V_1 ] -> V_24 ) ;
F_113 ( L_34 ) ;
V_195 = - V_205 ;
goto V_206;
}
if ( V_23 -> V_86 == NULL && V_85 != 0 ) {
F_113 ( L_75 ) ;
V_85 = 0 ;
}
if ( V_23 -> V_207 )
V_23 -> V_207 () ;
if ( V_208 >= 0 ) {
V_22 = V_208 ;
} else {
V_22 = F_196 () - 2 - V_208 ;
if ( V_22 <= 0 )
V_22 = 1 ;
}
F_154 ( V_23 , L_76 ) ;
F_39 ( & V_10 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_209 ) ; V_1 ++ ) {
V_209 [ V_1 ] . V_30 = 0 ;
F_15 ( & V_209 [ V_1 ] . V_14 ,
& V_10 ) ;
}
V_113 = NULL ;
V_116 = 0 ;
F_177 ( & V_12 , 0 ) ;
F_177 ( & V_11 , 0 ) ;
F_177 ( & V_15 , 0 ) ;
F_177 ( & V_125 , 0 ) ;
F_177 ( & V_147 , 0 ) ;
V_143 = 0 ;
V_144 = 0 ;
V_62 = 0 ;
V_67 = 0 ;
V_70 = 0 ;
for ( V_1 = 0 ; V_1 < V_28 + 1 ; V_1 ++ )
F_177 ( & V_29 [ V_1 ] , 0 ) ;
F_143 (cpu) {
for ( V_1 = 0 ; V_1 < V_28 + 1 ; V_1 ++ ) {
F_144 ( V_129 , V_136 ) [ V_1 ] = 0 ;
F_144 ( V_130 , V_136 ) [ V_1 ] = 0 ;
}
}
V_195 = F_168 ( F_109 , NULL ,
V_114 ) ;
if ( V_195 )
goto V_206;
if ( V_119 > 0 ) {
V_186 = F_180 ( V_119 *
sizeof( V_186 [ 0 ] ) ,
V_182 ) ;
if ( V_186 == NULL ) {
F_197 ( L_77 ) ;
V_195 = - V_183 ;
goto V_206;
}
}
for ( V_1 = 0 ; V_1 < V_119 ; V_1 ++ ) {
V_195 = F_168 ( F_122 ,
NULL , V_186 [ V_1 ] ) ;
if ( V_195 )
goto V_206;
}
V_185 = F_180 ( V_22 * sizeof( V_185 [ 0 ] ) ,
V_182 ) ;
if ( V_185 == NULL ) {
F_197 ( L_77 ) ;
V_195 = - V_183 ;
goto V_206;
}
for ( V_1 = 0 ; V_1 < V_22 ; V_1 ++ ) {
V_195 = F_168 ( F_136 , NULL ,
V_185 [ V_1 ] ) ;
if ( V_195 )
goto V_206;
}
if ( V_153 > 0 ) {
V_195 = F_168 ( F_153 , NULL ,
V_187 ) ;
if ( V_195 )
goto V_206;
}
if ( V_157 && V_158 > 0 ) {
V_195 = F_198 ( V_158 * V_41 ) ;
if ( V_195 )
goto V_206;
}
if ( V_159 < 0 )
V_159 = 0 ;
if ( V_159 ) {
V_195 = F_199 ( V_159 * V_41 ) ;
if ( V_195 )
goto V_206;
}
if ( V_85 < 0 )
V_85 = 0 ;
if ( V_85 ) {
V_195 = F_168 ( F_108 , NULL ,
V_188 ) ;
if ( V_195 )
goto V_206;
}
if ( V_69 < 1 )
V_69 = 1 ;
if ( V_66 < 2 )
V_66 = 2 ;
if ( ( V_160 == 1 && V_23 -> V_161 ) ||
V_160 == 2 ) {
V_63 = V_64 + V_69 * V_41 ;
V_195 = F_200 ( V_210 , L_78 ,
F_158 ,
F_155 ) ;
if ( V_195 < 0 )
goto V_206;
V_191 = V_195 ;
}
V_195 = F_201 ( V_162 , F_183 ) ;
if ( V_195 )
goto V_206;
V_195 = F_202 ( V_167 * V_41 , V_166 * V_41 ) ;
if ( V_195 )
goto V_206;
V_195 = F_167 () ;
if ( V_195 )
goto V_206;
V_195 = F_179 () ;
if ( V_195 )
goto V_206;
if ( V_211 )
F_191 () ;
if ( V_79 > 0 ) {
V_189 = ( F_196 () + 3 ) / 4 ;
V_190 = F_203 ( V_189 , sizeof( * V_190 ) ,
V_182 ) ;
if ( ! V_190 ) {
F_197 ( L_77 ) ;
V_195 = - V_183 ;
goto V_206;
}
for ( V_1 = 0 ; V_1 < V_189 ; V_1 ++ ) {
V_195 = F_168 ( F_103 ,
NULL ,
V_190 [ V_1 ] ) ;
if ( V_195 )
goto V_206;
}
}
F_184 () ;
F_204 () ;
return 0 ;
V_206:
F_204 () ;
F_183 () ;
return V_195 ;
}
