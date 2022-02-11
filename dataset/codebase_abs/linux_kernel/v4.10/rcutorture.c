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
int V_44 ;
int V_26 = T_7 -> V_20 & 0x1 ;
F_65 ( L_2 ,
V_45 , V_46 , V_26 ) ;
F_66 (cpu) {
long V_47 , V_48 ;
V_47 = ( long ) F_67 ( T_7 -> V_49 , V_44 ) -> V_50 [ ! V_26 ] ;
V_48 = ( long ) F_67 ( T_7 -> V_49 , V_44 ) -> V_50 [ V_26 ] ;
F_68 ( L_3 , V_44 , V_47 , V_48 ) ;
}
F_68 ( L_4 ) ;
}
static void F_69 ( void )
{
F_70 ( T_7 ) ;
}
static void F_71 ( void )
{
F_38 () ;
F_72 ( F_73 ( & V_51 ) ) ;
T_7 = & V_51 ;
}
static void F_74 ( void )
{
F_75 ( & V_51 ) ;
T_7 = & V_52 ;
}
static int F_76 ( void )
{
F_77 () ;
return 0 ;
}
static void F_78 ( int V_26 )
{
F_79 () ;
}
static void F_80 ( struct V_7 * V_9 )
{
F_81 ( & V_9 -> V_36 , F_33 ) ;
}
static int F_82 ( void )
{
return 0 ;
}
static void F_83 ( int V_26 )
{
}
static void F_84 ( struct V_7 * V_9 )
{
F_85 ( & V_9 -> V_36 , F_33 ) ;
}
static bool T_3 F_86 ( void )
{
return V_24 == & V_53 ;
}
static bool T_3 F_86 ( void )
{
return false ;
}
static void F_87 ( struct V_35 * V_38 )
{
struct V_54 * V_55 =
F_13 ( V_38 , struct V_54 , V_56 ) ;
F_88 ( & V_55 -> V_57 , 0 ) ;
}
static int F_89 ( void * V_58 )
{
unsigned long V_59 ;
unsigned long V_60 ;
unsigned long V_61 ;
struct V_54 V_62 = { . V_57 = 0 } ;
struct V_63 V_64 ;
F_90 ( L_5 ) ;
V_64 . V_65 = 1 ;
if ( F_91 ( V_66 , V_67 , & V_64 ) < 0 ) {
F_90 ( L_6 ) ;
V_68 ++ ;
}
F_92 ( & V_62 . V_56 ) ;
do {
V_61 = V_69 ;
while ( F_93 ( V_70 , V_61 ) ) {
F_52 ( V_61 - V_70 ) ;
F_94 ( L_7 ) ;
if ( F_95 () )
goto V_71;
}
V_60 = V_61 + V_72 * V_42 ;
V_59 = V_70 ;
while ( F_93 ( V_70 , V_60 ) ) {
if ( ! F_96 ( & V_62 . V_57 ) ) {
F_88 ( & V_62 . V_57 , 1 ) ;
F_37 ( & V_62 . V_56 , F_87 ) ;
if ( V_70 - V_59 >
V_72 * V_42 - V_42 / 2 ) {
F_90 ( L_8 ) ;
V_73 ++ ;
}
V_59 = V_70 ;
}
F_94 ( L_7 ) ;
if ( F_95 () )
goto V_71;
}
while ( V_61 == V_69 &&
! F_97 () ) {
if ( F_98 ( & V_74 ) ) {
V_69 = V_70 +
V_75 * V_42 ;
V_76 ++ ;
F_99 ( & V_74 ) ;
break;
}
F_100 ( 1 ) ;
}
V_71: F_94 ( L_7 ) ;
} while ( ! F_95 () );
while ( ! F_97 () || F_96 ( & V_62 . V_57 ) ) {
F_101 ( L_7 ) ;
F_100 ( 1 ) ;
}
F_102 ( & V_62 . V_56 ) ;
F_103 ( L_7 ) ;
return 0 ;
}
static void F_104 ( struct V_35 * V_77 )
{
}
static int
F_105 ( void * V_58 )
{
int V_78 = 1 ;
int V_1 ;
int V_79 ;
struct V_35 * V_77 ;
if ( V_80 > 0 &&
V_81 > 0 &&
V_82 > 0 &&
V_24 -> V_83 &&
V_24 -> V_84 ) {
V_77 = F_106 ( sizeof( * V_77 ) *
V_85 * V_80 ) ;
V_78 = ! V_77 ;
}
if ( V_78 ) {
F_90 ( L_9 ) ;
goto V_86;
}
F_90 ( L_10 ) ;
do {
F_52 ( V_81 ) ;
F_107 ( & V_87 ) ;
F_72 ( F_108 ( V_66 ) ) ;
for ( V_1 = 0 ; V_1 < V_85 ; V_1 ++ ) {
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_24 -> V_83 ( & V_77 [ V_1 * V_80 + V_79 ] ,
F_104 ) ;
}
F_52 ( V_82 ) ;
F_72 ( F_108 ( V_66 ) ) ;
}
V_24 -> V_84 () ;
F_94 ( L_11 ) ;
} while ( ! F_95 () );
F_109 ( V_77 ) ;
V_86:
F_103 ( L_11 ) ;
return 0 ;
}
static int
F_110 ( void * V_58 )
{
unsigned long V_88 ;
int V_89 ;
F_90 ( L_12 ) ;
do {
V_88 = V_70 + V_90 * V_42 ;
while ( F_93 ( V_70 , V_88 ) &&
! F_97 () ) {
F_52 ( 1 ) ;
}
V_89 = V_91 ;
while ( V_89 > 0 &&
! F_97 () ) {
V_24 -> V_92 () ;
F_22 ( V_93 ) ;
V_89 -= V_93 ;
}
F_94 ( L_13 ) ;
} while ( ! F_95 () );
F_103 ( L_13 ) ;
return 0 ;
}
static int
F_111 ( void * V_58 )
{
bool V_94 = ! F_112 () && ! F_113 () ;
int V_95 = 0 ;
unsigned long V_96 ;
bool V_97 = V_98 , V_99 = V_100 , V_101 = V_102 ;
bool V_103 = V_104 ;
int V_1 ;
struct V_7 * V_27 ;
struct V_7 * V_32 ;
static F_114 ( rand ) ;
int V_105 [] = { V_106 , V_107 ,
V_108 , V_109 } ;
int V_110 = 0 ;
F_90 ( L_14 ) ;
if ( ! V_94 ) {
F_65 ( L_15 V_46
L_16 ,
V_45 , V_24 -> V_25 ) ;
F_65 ( L_15 V_46
L_17 ,
V_45 ) ;
}
if ( ! V_97 && ! V_99 && ! V_101 && ! V_103 )
V_97 = V_99 = V_101 = V_103 = true ;
if ( V_97 && V_24 -> V_111 && V_24 -> V_112 )
V_105 [ V_110 ++ ] = V_108 ;
else if ( V_98 && ( ! V_24 -> V_111 || ! V_24 -> V_112 ) )
F_65 ( L_18 ) ;
if ( V_99 && V_24 -> V_113 )
V_105 [ V_110 ++ ] = V_107 ;
else if ( V_100 && ! V_24 -> V_113 )
F_65 ( L_19 ) ;
if ( V_101 && V_24 -> V_37 )
V_105 [ V_110 ++ ] = V_106 ;
else if ( V_102 && ! V_24 -> V_37 )
F_65 ( L_20 ) ;
if ( V_103 && V_24 -> V_114 )
V_105 [ V_110 ++ ] = V_109 ;
else if ( V_104 && ! V_24 -> V_114 )
F_65 ( L_21 ) ;
if ( F_115 ( V_110 == 0 ,
L_22 ) ) {
V_2 = V_115 ;
F_103 ( L_23 ) ;
}
do {
V_2 = V_116 ;
F_100 ( 1 ) ;
V_27 = F_7 () ;
if ( V_27 == NULL )
continue;
V_27 -> V_28 = 0 ;
V_2 = V_117 ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
V_2 = V_118 ;
V_32 = F_116 ( V_119 ,
V_66 == V_120 ) ;
V_27 -> V_31 = 1 ;
F_117 ( V_119 , V_27 ) ;
F_118 () ;
if ( V_32 ) {
V_1 = V_32 -> V_28 ;
if ( V_1 > V_29 )
V_1 = V_29 ;
F_10 ( & V_30 [ V_1 ] ) ;
V_32 -> V_28 ++ ;
switch ( V_105 [ F_19 ( & rand ) % V_110 ] ) {
case V_106 :
V_2 = V_106 ;
V_24 -> V_37 ( V_32 ) ;
break;
case V_107 :
V_2 = V_107 ;
V_24 -> V_113 () ;
F_29 ( V_32 ) ;
break;
case V_108 :
V_2 = V_108 ;
V_96 = V_24 -> V_111 () ;
V_1 = F_19 ( & rand ) % 16 ;
if ( V_1 != 0 )
F_52 ( V_1 ) ;
F_22 ( F_19 ( & rand ) % 1000 ) ;
V_2 = V_121 ;
V_24 -> V_112 ( V_96 ) ;
F_29 ( V_32 ) ;
break;
case V_109 :
V_2 = V_109 ;
V_24 -> V_114 () ;
F_29 ( V_32 ) ;
break;
default:
F_119 ( 1 ) ;
break;
}
}
F_120 ( ++ V_122 ) ;
if ( V_94 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_95 - 1 ) ) ) {
F_119 ( V_95 == 0 && F_112 () ) ;
if ( V_95 >= 0 )
F_121 () ;
else
F_122 () ;
if ( ++ V_95 > 3 )
V_95 = - V_95 ;
}
V_2 = V_123 ;
F_94 ( L_23 ) ;
} while ( ! F_95 () );
if ( V_95 > 0 )
V_95 = - V_95 ;
while ( V_94 && V_95 ++ < 0 )
F_122 () ;
F_119 ( V_94 && F_112 () ) ;
V_2 = V_115 ;
F_103 ( L_23 ) ;
return 0 ;
}
static int
F_123 ( void * V_58 )
{
F_114 ( rand ) ;
F_90 ( L_24 ) ;
F_124 ( V_66 , V_124 ) ;
do {
F_100 ( 1 + F_19 ( & rand ) % 10 ) ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
if ( V_24 -> V_84 != NULL &&
F_19 ( & rand ) % ( V_125 * 8 ) == 0 ) {
V_24 -> V_84 () ;
} else if ( V_102 == V_100 ) {
if ( F_19 ( & rand ) & 0x80 )
V_24 -> V_114 () ;
else
V_24 -> V_113 () ;
} else if ( V_102 ) {
V_24 -> V_114 () ;
} else {
V_24 -> V_113 () ;
}
F_94 ( L_25 ) ;
} while ( ! F_95 () );
F_103 ( L_25 ) ;
return 0 ;
}
static void F_125 ( unsigned long V_126 )
{
int V_26 ;
unsigned long V_19 ;
unsigned long V_20 ;
static F_114 ( rand ) ;
static F_126 ( V_127 ) ;
struct V_7 * V_9 ;
int V_128 ;
unsigned long long V_4 ;
V_26 = V_24 -> V_129 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_116 ( V_119 ,
F_127 () ||
F_128 () ||
F_129 ( T_7 ) ||
F_86 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_130 ( V_26 ) ;
return;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_131 ) ;
F_130 ( & V_127 ) ;
V_24 -> V_132 ( & rand ) ;
V_133 ++ ;
F_131 ( & V_127 ) ;
F_77 () ;
V_128 = V_9 -> V_28 ;
if ( V_128 > V_29 ) {
V_128 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_128 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 , V_4 ,
V_19 , V_20 ) ;
F_132 ( V_134 ) ;
}
F_133 ( V_135 [ V_128 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_133 ( V_136 [ V_20 ] ) ;
F_79 () ;
V_24 -> V_130 ( V_26 ) ;
}
static int
F_134 ( void * V_58 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_26 ;
F_114 ( rand ) ;
struct V_7 * V_9 ;
int V_128 ;
struct V_137 V_138 ;
unsigned long long V_4 ;
F_90 ( L_26 ) ;
F_124 ( V_66 , V_124 ) ;
if ( V_139 && V_24 -> V_140 )
F_135 ( & V_138 , F_125 , 0 ) ;
do {
if ( V_139 && V_24 -> V_140 ) {
if ( ! F_136 ( & V_138 ) )
F_137 ( & V_138 , V_70 + 1 ) ;
}
V_26 = V_24 -> V_129 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_116 ( V_119 ,
F_127 () ||
F_128 () ||
F_129 ( T_7 ) ||
F_86 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_130 ( V_26 ) ;
F_52 ( V_42 ) ;
continue;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_131 ) ;
V_24 -> V_132 ( & rand ) ;
F_77 () ;
V_128 = V_9 -> V_28 ;
if ( V_128 > V_29 ) {
V_128 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_128 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 ,
V_4 , V_19 , V_20 ) ;
F_132 ( V_134 ) ;
}
F_133 ( V_135 [ V_128 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_133 ( V_136 [ V_20 ] ) ;
F_79 () ;
V_24 -> V_130 ( V_26 ) ;
F_94 ( L_27 ) ;
} while ( ! F_95 () );
if ( V_139 && V_24 -> V_140 ) {
F_138 ( & V_138 ) ;
F_139 ( & V_138 ) ;
}
F_103 ( L_27 ) ;
return 0 ;
}
static void
F_140 ( void )
{
int V_44 ;
int V_1 ;
long V_141 [ V_29 + 1 ] = { 0 } ;
long V_142 [ V_29 + 1 ] = { 0 } ;
static unsigned long V_143 = V_144 ;
struct V_145 * V_146 ;
F_66 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
V_141 [ V_1 ] += F_141 ( V_135 , V_44 ) [ V_1 ] ;
V_142 [ V_1 ] += F_141 ( V_136 , V_44 ) [ V_1 ] ;
}
}
for ( V_1 = V_29 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_141 [ V_1 ] != 0 )
break;
}
F_65 ( L_28 , V_45 , V_46 ) ;
F_68 ( L_29 ,
V_119 ,
V_122 ,
F_9 ( & V_11 ) ,
F_142 ( & V_13 ) ,
F_142 ( & V_12 ) ,
F_142 ( & V_16 ) ) ;
F_68 ( L_30 ,
F_142 ( & V_131 ) ,
V_147 ,
V_148 ,
V_68 ) ;
F_68 ( L_31 ,
V_73 ,
V_76 ,
V_133 ) ;
F_143 () ;
F_68 ( L_32 ,
V_149 ,
V_150 ,
V_147 ) ;
F_68 ( L_33 , F_144 ( & V_87 ) ) ;
F_65 ( L_28 , V_45 , V_46 ) ;
if ( F_142 ( & V_131 ) != 0 ||
V_147 != 0 ||
V_148 != 0 ||
V_68 != 0 ||
V_73 != 0 ||
V_1 > 1 ) {
F_68 ( L_15 , L_34 ) ;
F_10 ( & V_151 ) ;
F_119 ( 1 ) ;
}
F_68 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_68 ( L_36 , V_141 [ V_1 ] ) ;
F_68 ( L_4 ) ;
F_65 ( L_28 , V_45 , V_46 ) ;
F_68 ( L_37 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_68 ( L_36 , V_142 [ V_1 ] ) ;
F_68 ( L_4 ) ;
F_65 ( L_28 , V_45 , V_46 ) ;
F_68 ( L_38 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_68 ( L_39 , F_142 ( & V_30 [ V_1 ] ) ) ;
}
F_68 ( L_4 ) ;
if ( V_24 -> V_152 )
V_24 -> V_152 () ;
if ( V_143 == V_122 &&
V_119 != NULL ) {
int T_3 V_153 ;
unsigned long T_3 V_154 ;
unsigned long T_3 V_20 ;
F_145 ( V_24 -> V_155 ,
& V_153 , & V_154 , & V_20 ) ;
V_146 = F_2 ( V_120 ) ;
F_65 ( L_40 ,
F_1 () ,
V_2 ,
V_154 , V_20 , V_153 ,
V_146 == NULL ? ~ 0UL : V_146 -> V_156 ) ;
F_146 () ;
F_132 ( V_134 ) ;
}
V_143 = V_122 ;
}
static int
F_147 ( void * V_58 )
{
F_90 ( L_41 ) ;
do {
F_52 ( V_157 * V_42 ) ;
F_140 () ;
F_101 ( L_42 ) ;
} while ( ! F_95 () );
F_103 ( L_42 ) ;
return 0 ;
}
static inline void
F_148 ( struct V_158 * V_24 , const char * V_159 )
{
F_65 ( L_15 V_46
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51 ,
V_45 , V_159 , V_23 , V_125 ,
V_157 , V_160 , V_161 , V_162 ,
V_163 , V_139 , V_91 , V_93 , V_90 ,
V_164 , V_24 -> V_165 ,
V_75 , V_72 , V_166 ,
V_167 , V_168 ,
V_169 ,
V_170 , V_171 ) ;
}
static int F_149 ( unsigned int V_44 )
{
struct V_145 * V_138 ;
if ( V_172 [ V_44 ] == NULL )
return 0 ;
F_150 ( & V_74 ) ;
V_138 = V_172 [ V_44 ] ;
V_172 [ V_44 ] = NULL ;
F_99 ( & V_74 ) ;
F_151 ( F_89 , V_138 ) ;
return 0 ;
}
static int F_152 ( unsigned int V_44 )
{
int V_173 ;
if ( V_172 [ V_44 ] != NULL )
return 0 ;
F_150 ( & V_74 ) ;
F_90 ( L_52 ) ;
V_172 [ V_44 ] = F_153 ( F_89 , NULL ,
F_154 ( V_44 ) ,
L_7 ) ;
if ( F_155 ( V_172 [ V_44 ] ) ) {
V_173 = F_156 ( V_172 [ V_44 ] ) ;
F_90 ( L_53 ) ;
V_148 ++ ;
V_172 [ V_44 ] = NULL ;
F_99 ( & V_74 ) ;
return V_173 ;
}
F_157 ( V_172 [ V_44 ] , V_44 ) ;
F_158 ( V_172 [ V_44 ] ) ;
F_99 ( & V_74 ) ;
return 0 ;
}
static int F_159 ( void * args )
{
unsigned long V_174 ;
F_90 ( L_54 ) ;
if ( V_168 > 0 ) {
F_90 ( L_55 ) ;
F_52 ( V_168 * V_42 ) ;
F_90 ( L_56 ) ;
}
if ( ! F_97 () ) {
V_174 = F_160 () + V_167 ;
F_65 ( L_57 ) ;
F_17 () ;
F_77 () ;
while ( F_93 ( F_160 () , V_174 ) )
continue;
F_79 () ;
F_27 () ;
F_65 ( L_58 ) ;
}
F_101 ( L_59 ) ;
while ( ! F_97 () )
F_52 ( 10 * V_42 ) ;
return 0 ;
}
static int T_8 F_161 ( void )
{
if ( V_167 <= 0 )
return 0 ;
return F_162 ( F_159 , NULL , V_175 ) ;
}
static void F_163 ( struct V_35 * V_56 )
{
F_10 ( & V_176 ) ;
}
static int F_164 ( void * V_58 )
{
long V_177 = ( long ) V_58 ;
bool V_178 = 0 ;
bool V_179 ;
struct V_35 V_56 ;
F_92 ( & V_56 ) ;
F_90 ( L_60 ) ;
F_124 ( V_66 , V_124 ) ;
do {
F_165 ( V_180 [ V_177 ] ,
( V_179 =
F_96 ( & V_181 ) ) != V_178 ||
F_95 () ) ;
V_178 = V_179 ;
if ( F_95 () )
break;
F_166 () ;
V_24 -> V_83 ( & V_56 , F_163 ) ;
F_167 () ;
if ( F_168 ( & V_182 ) )
F_169 ( & V_183 ) ;
} while ( ! F_95 () );
if ( V_24 -> V_84 != NULL )
V_24 -> V_84 () ;
F_102 ( & V_56 ) ;
F_103 ( L_61 ) ;
return 0 ;
}
static int F_170 ( void * V_58 )
{
int V_1 ;
F_90 ( L_62 ) ;
do {
F_171 ( & V_176 , 0 ) ;
F_171 ( & V_182 , V_169 ) ;
F_88 ( & V_181 , ! V_181 ) ;
for ( V_1 = 0 ; V_1 < V_169 ; V_1 ++ )
F_169 ( & V_180 [ V_1 ] ) ;
F_165 ( V_183 ,
F_142 ( & V_182 ) == 0 ||
F_95 () ) ;
if ( F_95 () )
break;
V_150 ++ ;
V_24 -> V_84 () ;
if ( F_142 ( & V_176 ) != V_169 ) {
V_147 ++ ;
F_172 ( L_63 ,
F_142 ( & V_176 ) ,
V_169 ) ;
F_119 ( 1 ) ;
}
V_149 ++ ;
F_52 ( V_42 / 10 ) ;
} while ( ! F_95 () );
F_103 ( L_64 ) ;
return 0 ;
}
static int F_173 ( void )
{
int V_1 ;
int V_184 ;
if ( V_169 <= 0 )
return 0 ;
if ( V_24 -> V_83 == NULL || V_24 -> V_84 == NULL ) {
F_65 ( L_15 V_46
L_65 ,
V_45 , V_24 -> V_25 ) ;
F_65 ( L_15 V_46
L_66 ,
V_45 ) ;
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
if ( V_24 -> V_84 != NULL )
V_24 -> V_84 () ;
return;
}
F_176 () ;
F_151 ( F_159 , V_175 ) ;
F_151 ( F_111 , V_120 ) ;
if ( V_189 ) {
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ )
F_151 ( F_134 ,
V_189 [ V_1 ] ) ;
F_177 ( V_189 ) ;
}
V_119 = NULL ;
if ( V_190 ) {
for ( V_1 = 0 ; V_1 < V_125 ; V_1 ++ ) {
F_151 ( F_123 ,
V_190 [ V_1 ] ) ;
}
F_177 ( V_190 ) ;
V_190 = NULL ;
}
F_151 ( F_147 , V_191 ) ;
F_151 ( F_110 , V_192 ) ;
for ( V_1 = 0 ; V_1 < V_193 ; V_1 ++ )
F_151 ( F_105 , V_194 [ V_1 ] ) ;
if ( ( V_164 == 1 && V_24 -> V_165 ) ||
V_164 == 2 )
F_181 ( V_195 ) ;
if ( V_24 -> V_84 != NULL )
V_24 -> V_84 () ;
if ( V_24 -> V_196 != NULL )
V_24 -> V_196 () ;
F_140 () ;
if ( F_142 ( & V_151 ) || V_147 )
F_148 ( V_24 , L_67 ) ;
else if ( F_182 () )
F_148 ( V_24 ,
L_68 ) ;
else
F_148 ( V_24 , L_69 ) ;
F_183 () ;
}
static void F_184 ( struct V_35 * V_77 )
{
}
static void F_185 ( struct V_35 * V_77 )
{
F_65 ( L_70 ) ;
}
static void F_186 ( void )
{
#ifdef F_187
struct V_35 V_197 ;
struct V_35 V_198 ;
F_92 ( & V_197 ) ;
F_92 ( & V_198 ) ;
F_65 ( L_71 ) ;
F_77 () ;
F_17 () ;
F_37 ( & V_197 , F_184 ) ;
F_166 () ;
F_37 ( & V_198 , F_184 ) ;
F_37 ( & V_198 , F_185 ) ;
F_167 () ;
F_27 () ;
F_79 () ;
F_188 () ;
F_65 ( L_72 ) ;
F_102 ( & V_197 ) ;
F_102 ( & V_198 ) ;
#else
F_65 ( L_73 ) ;
#endif
}
static int T_8
F_189 ( void )
{
int V_1 ;
int V_44 ;
int V_199 = 0 ;
static struct V_158 * V_200 [] = {
& V_201 , & V_202 , & V_203 , & V_204 , & V_205 ,
& V_206 , V_207
} ;
if ( ! F_190 ( V_45 , V_160 , & V_208 ) )
return - V_209 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_200 ) ; V_1 ++ ) {
V_24 = V_200 [ V_1 ] ;
if ( strcmp ( V_45 , V_24 -> V_25 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_200 ) ) {
F_65 ( L_74 ,
V_45 ) ;
F_65 ( L_75 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_200 ) ; V_1 ++ )
F_65 ( L_76 , V_200 [ V_1 ] -> V_25 ) ;
F_65 ( L_4 ) ;
V_199 = - V_210 ;
goto V_211;
}
if ( V_24 -> V_92 == NULL && V_91 != 0 ) {
F_65 ( L_77 ) ;
V_91 = 0 ;
}
if ( V_24 -> V_212 )
V_24 -> V_212 () ;
if ( V_213 >= 0 ) {
V_23 = V_213 ;
} else {
V_23 = F_191 () - 2 - V_213 ;
if ( V_23 <= 0 )
V_23 = 1 ;
}
F_148 ( V_24 , L_78 ) ;
F_39 ( & V_11 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_214 ) ; V_1 ++ ) {
V_214 [ V_1 ] . V_31 = 0 ;
F_15 ( & V_214 [ V_1 ] . V_15 ,
& V_11 ) ;
}
V_119 = NULL ;
V_122 = 0 ;
F_171 ( & V_13 , 0 ) ;
F_171 ( & V_12 , 0 ) ;
F_171 ( & V_16 , 0 ) ;
F_171 ( & V_131 , 0 ) ;
F_171 ( & V_151 , 0 ) ;
V_147 = 0 ;
V_148 = 0 ;
V_68 = 0 ;
V_73 = 0 ;
V_76 = 0 ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_171 ( & V_30 [ V_1 ] , 0 ) ;
F_66 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_141 ( V_135 , V_44 ) [ V_1 ] = 0 ;
F_141 ( V_136 , V_44 ) [ V_1 ] = 0 ;
}
}
V_199 = F_162 ( F_111 , NULL ,
V_120 ) ;
if ( V_199 )
goto V_211;
if ( V_125 > 0 ) {
V_190 = F_174 ( V_125 *
sizeof( V_190 [ 0 ] ) ,
V_186 ) ;
if ( V_190 == NULL ) {
F_192 ( L_79 ) ;
V_199 = - V_187 ;
goto V_211;
}
}
for ( V_1 = 0 ; V_1 < V_125 ; V_1 ++ ) {
V_199 = F_162 ( F_123 ,
NULL , V_190 [ V_1 ] ) ;
if ( V_199 )
goto V_211;
}
V_189 = F_174 ( V_23 * sizeof( V_189 [ 0 ] ) ,
V_186 ) ;
if ( V_189 == NULL ) {
F_192 ( L_79 ) ;
V_199 = - V_187 ;
goto V_211;
}
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ ) {
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
V_199 = F_193 ( V_162 * V_42 ) ;
if ( V_199 )
goto V_211;
}
if ( V_163 < 0 )
V_163 = 0 ;
if ( V_163 ) {
V_199 = F_194 ( V_163 * V_42 ) ;
if ( V_199 )
goto V_211;
}
if ( V_91 < 0 )
V_91 = 0 ;
if ( V_91 ) {
V_199 = F_162 ( F_110 , NULL ,
V_192 ) ;
if ( V_199 )
goto V_211;
}
if ( V_75 < 1 )
V_75 = 1 ;
if ( V_72 < 2 )
V_72 = 2 ;
if ( ( V_164 == 1 && V_24 -> V_165 ) ||
V_164 == 2 ) {
V_69 = V_70 + V_75 * V_42 ;
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
V_199 = F_197 ( V_171 * V_42 , V_170 * V_42 ) ;
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
if ( V_85 > 0 ) {
V_193 = ( F_191 () + 3 ) / 4 ;
V_194 = F_198 ( V_193 , sizeof( * V_194 ) ,
V_186 ) ;
if ( ! V_194 ) {
F_192 ( L_79 ) ;
V_199 = - V_187 ;
goto V_211;
}
for ( V_1 = 0 ; V_1 < V_193 ; V_1 ++ ) {
V_199 = F_162 ( F_105 ,
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
