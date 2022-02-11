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
F_44 ( struct V_29 * V_33 , T_6 V_34 )
{
V_34 ( V_33 ) ;
}
static int F_45 ( void ) __acquires( T_7 )
{
return F_46 ( T_7 ) ;
}
static void F_47 ( struct V_14 * V_15 )
{
long V_35 ;
const long V_36 = 1000000 / V_37 ;
const long V_38 = 10 ;
V_35 = F_16 ( V_15 ) %
( V_18 * 2 * V_38 * V_36 ) ;
if ( ! V_35 )
F_48 ( V_38 ) ;
else
F_15 ( V_15 ) ;
}
static void F_49 ( int V_19 ) __releases( T_7 )
{
F_50 ( T_7 , V_19 ) ;
}
static unsigned long F_51 ( void )
{
return F_52 ( T_7 ) ;
}
static void F_53 ( struct V_4 * V_20 )
{
F_54 ( T_7 , & V_20 -> V_30 , F_29 ) ;
}
static void F_55 ( void )
{
F_56 ( T_7 ) ;
}
static void F_57 ( struct V_29 * V_33 ,
T_6 V_34 )
{
F_54 ( T_7 , V_33 , V_34 ) ;
}
static void F_58 ( void )
{
F_59 ( T_7 ) ;
}
static void F_60 ( void )
{
int V_39 ;
int V_19 = T_7 -> V_40 & 0x1 ;
F_61 ( L_1 ,
V_41 , V_42 , V_19 ) ;
F_62 (cpu) {
long V_43 , V_44 ;
V_43 = ( long ) F_63 ( T_7 -> V_45 , V_39 ) -> V_46 [ ! V_19 ] ;
V_44 = ( long ) F_63 ( T_7 -> V_45 , V_39 ) -> V_46 [ V_19 ] ;
F_64 ( L_2 , V_39 , V_43 , V_44 ) ;
}
F_64 ( L_3 ) ;
}
static void F_65 ( void )
{
F_66 ( T_7 ) ;
}
static void F_67 ( void )
{
F_34 () ;
F_68 ( F_69 ( & V_47 ) ) ;
T_7 = & V_47 ;
}
static void F_70 ( void )
{
F_71 ( & V_47 ) ;
T_7 = & V_48 ;
}
static int F_72 ( void )
{
F_73 () ;
return 0 ;
}
static void F_74 ( int V_19 )
{
F_75 () ;
}
static void F_76 ( struct V_4 * V_6 )
{
F_77 ( & V_6 -> V_30 , F_29 ) ;
}
static int F_78 ( void )
{
return 0 ;
}
static void F_79 ( int V_19 )
{
}
static void F_80 ( struct V_4 * V_6 )
{
F_81 ( & V_6 -> V_30 , F_29 ) ;
}
static bool T_3 F_82 ( void )
{
return V_31 == & V_49 ;
}
static bool T_3 F_82 ( void )
{
return false ;
}
static void F_83 ( struct V_29 * V_33 )
{
struct V_50 * V_51 =
F_10 ( V_33 , struct V_50 , V_52 ) ;
F_84 ( & V_51 -> V_53 , 0 ) ;
}
static int F_85 ( void * V_54 )
{
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long V_57 ;
struct V_50 V_58 = { . V_53 = 0 } ;
struct V_59 V_60 ;
F_86 ( L_4 ) ;
V_60 . V_61 = 1 ;
if ( F_87 ( V_62 , V_63 , & V_60 ) < 0 ) {
F_86 ( L_5 ) ;
V_64 ++ ;
}
F_88 ( & V_58 . V_52 ) ;
do {
V_57 = V_65 ;
while ( F_89 ( V_66 , V_57 ) ) {
F_48 ( V_57 - V_66 ) ;
F_90 ( L_6 ) ;
if ( F_91 () )
goto V_67;
}
V_56 = V_57 + V_68 * V_37 ;
V_55 = V_66 ;
while ( F_89 ( V_66 , V_56 ) ) {
if ( ! F_92 ( & V_58 . V_53 ) ) {
F_84 ( & V_58 . V_53 , 1 ) ;
F_33 ( & V_58 . V_52 , F_83 ) ;
if ( V_66 - V_55 >
V_68 * V_37 - V_37 / 2 ) {
F_86 ( L_7 ) ;
V_69 ++ ;
}
V_55 = V_66 ;
}
F_90 ( L_6 ) ;
if ( F_91 () )
goto V_67;
}
while ( V_57 == V_65 &&
! F_93 () ) {
if ( F_94 ( & V_70 ) ) {
V_65 = V_66 +
V_71 * V_37 ;
V_72 ++ ;
F_95 ( & V_70 ) ;
break;
}
F_96 ( 1 ) ;
}
V_67: F_90 ( L_6 ) ;
} while ( ! F_91 () );
while ( ! F_93 () || F_92 ( & V_58 . V_53 ) ) {
F_97 ( L_6 ) ;
F_96 ( 1 ) ;
}
F_98 ( & V_58 . V_52 ) ;
F_99 ( L_6 ) ;
return 0 ;
}
static void F_100 ( struct V_29 * V_73 )
{
}
static int
F_101 ( void * V_54 )
{
int V_74 = 1 ;
int V_21 ;
int V_75 ;
struct V_29 * V_73 ;
if ( V_76 > 0 &&
V_77 > 0 &&
V_78 > 0 &&
V_31 -> V_79 &&
V_31 -> V_80 ) {
V_73 = F_102 ( sizeof( * V_73 ) *
V_81 * V_76 ) ;
V_74 = ! V_73 ;
}
if ( V_74 ) {
F_86 ( L_8 ) ;
goto V_82;
}
F_86 ( L_9 ) ;
do {
F_48 ( V_77 ) ;
F_103 ( & V_83 ) ;
F_68 ( F_104 ( V_62 ) ) ;
for ( V_21 = 0 ; V_21 < V_81 ; V_21 ++ ) {
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
V_31 -> V_79 ( & V_73 [ V_21 * V_76 + V_75 ] ,
F_100 ) ;
}
F_48 ( V_78 ) ;
F_68 ( F_104 ( V_62 ) ) ;
}
V_31 -> V_80 () ;
F_90 ( L_10 ) ;
} while ( ! F_91 () );
F_105 ( V_73 ) ;
V_82:
F_99 ( L_10 ) ;
return 0 ;
}
static int
F_106 ( void * V_54 )
{
unsigned long V_84 ;
int V_85 ;
F_86 ( L_11 ) ;
do {
V_84 = V_66 + V_86 * V_37 ;
while ( F_89 ( V_66 , V_84 ) &&
! F_93 () ) {
F_48 ( 1 ) ;
}
V_85 = V_87 ;
while ( V_85 > 0 &&
! F_93 () ) {
V_31 -> V_88 () ;
F_18 ( V_89 ) ;
V_85 -= V_89 ;
}
F_90 ( L_12 ) ;
} while ( ! F_91 () );
F_99 ( L_12 ) ;
return 0 ;
}
static int
F_107 ( void * V_54 )
{
bool V_90 = ! F_108 () ;
int V_91 = 0 ;
unsigned long V_92 ;
bool V_93 = V_94 , V_95 = V_96 , V_97 = V_98 ;
bool V_99 = V_100 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_109 ( rand ) ;
int V_101 [] = { V_102 , V_103 ,
V_104 , V_105 } ;
int V_106 = 0 ;
F_86 ( L_13 ) ;
F_61 ( L_14 V_42
L_15 ,
V_41 , V_31 -> V_107 ) ;
F_61 ( L_14 V_42
L_16 ,
V_41 ) ;
if ( ! V_93 && ! V_95 && ! V_97 && ! V_99 )
V_93 = V_95 = V_97 = V_99 = true ;
if ( V_93 && V_31 -> V_108 && V_31 -> V_109 )
V_101 [ V_106 ++ ] = V_104 ;
else if ( V_94 && ( ! V_31 -> V_108 || ! V_31 -> V_109 ) )
F_61 ( L_17 ) ;
if ( V_95 && V_31 -> V_110 )
V_101 [ V_106 ++ ] = V_103 ;
else if ( V_96 && ! V_31 -> V_110 )
F_61 ( L_18 ) ;
if ( V_97 && V_31 -> V_32 )
V_101 [ V_106 ++ ] = V_102 ;
else if ( V_98 && ! V_31 -> V_32 )
F_61 ( L_19 ) ;
if ( V_99 && V_31 -> V_111 )
V_101 [ V_106 ++ ] = V_105 ;
else if ( V_100 && ! V_31 -> V_111 )
F_61 ( L_20 ) ;
if ( F_110 ( V_106 == 0 ,
L_21 ) ) {
V_112 = V_113 ;
F_99 ( L_22 ) ;
}
do {
V_112 = V_114 ;
F_96 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_112 = V_115 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_112 = V_116 ;
V_26 = F_111 ( V_117 ,
V_62 == V_118 ) ;
V_20 -> V_25 = 1 ;
F_112 ( V_117 , V_20 ) ;
F_113 () ;
if ( V_26 ) {
V_21 = V_26 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
V_26 -> V_22 ++ ;
switch ( V_101 [ F_16 ( & rand ) % V_106 ] ) {
case V_102 :
V_112 = V_102 ;
V_31 -> V_32 ( V_26 ) ;
break;
case V_103 :
V_112 = V_103 ;
V_31 -> V_110 () ;
F_25 ( V_26 ) ;
break;
case V_104 :
V_112 = V_104 ;
V_92 = V_31 -> V_108 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_48 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_112 = V_119 ;
V_31 -> V_109 ( V_92 ) ;
F_25 ( V_26 ) ;
break;
case V_105 :
V_112 = V_105 ;
V_31 -> V_111 () ;
F_25 ( V_26 ) ;
break;
default:
F_114 ( 1 ) ;
break;
}
}
F_115 ( ++ V_120 ) ;
if ( V_90 &&
! ( F_16 ( & rand ) & 0xff & ( ! ! V_91 - 1 ) ) ) {
F_114 ( V_91 == 0 && F_108 () ) ;
if ( V_91 >= 0 )
F_116 () ;
else
F_117 () ;
if ( ++ V_91 > 3 )
V_91 = - V_91 ;
}
V_112 = V_121 ;
F_90 ( L_22 ) ;
} while ( ! F_91 () );
if ( V_91 > 0 )
V_91 = - V_91 ;
while ( V_90 && V_91 ++ < 0 )
F_117 () ;
F_114 ( V_90 && F_108 () ) ;
V_112 = V_113 ;
F_99 ( L_22 ) ;
return 0 ;
}
static int
F_118 ( void * V_54 )
{
F_109 ( rand ) ;
F_86 ( L_23 ) ;
F_119 ( V_62 , V_122 ) ;
do {
F_96 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_31 -> V_80 != NULL &&
F_16 ( & rand ) % ( V_123 * 8 ) == 0 ) {
V_31 -> V_80 () ;
} else if ( V_98 == V_96 ) {
if ( F_16 ( & rand ) & 0x80 )
V_31 -> V_111 () ;
else
V_31 -> V_110 () ;
} else if ( V_98 ) {
V_31 -> V_111 () ;
} else {
V_31 -> V_110 () ;
}
F_90 ( L_24 ) ;
} while ( ! F_91 () );
F_99 ( L_24 ) ;
return 0 ;
}
static void F_120 ( void )
{
static T_8 V_124 = F_121 ( 0 ) ;
if ( F_122 ( & V_124 ) )
return;
if ( F_123 ( & V_124 , 1 ) != 0 )
return;
F_124 ( V_125 ) ;
}
static void F_125 ( unsigned long V_126 )
{
int V_19 ;
unsigned long V_127 ;
unsigned long V_40 ;
static F_109 ( rand ) ;
static F_126 ( V_128 ) ;
struct V_4 * V_6 ;
int V_129 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_130 () ;
if ( V_31 -> V_127 )
V_127 = V_31 -> V_127 () ;
else
V_127 = V_31 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_111 ( V_117 ,
F_127 () ||
F_128 () ||
F_129 ( T_7 ) ||
F_82 () ) ;
if ( V_6 == NULL ) {
V_31 -> V_131 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_132 ) ;
F_130 ( & V_128 ) ;
V_31 -> V_133 ( & rand ) ;
V_134 ++ ;
F_131 ( & V_128 ) ;
F_73 () ;
V_129 = V_6 -> V_22 ;
if ( V_129 > V_23 ) {
V_129 = V_23 ;
}
V_40 = V_31 -> V_40 () ;
if ( V_129 > 1 ) {
F_132 ( V_31 -> V_107 , & V_6 -> V_30 , V_1 ,
V_127 , V_40 ) ;
F_120 () ;
}
F_133 ( V_135 [ V_129 ] ) ;
V_40 = V_40 - V_127 ;
if ( V_31 -> V_127 )
V_40 ++ ;
if ( V_40 > V_23 ) {
V_40 = V_23 ;
}
F_133 ( V_136 [ V_40 ] ) ;
F_75 () ;
V_31 -> V_131 ( V_19 ) ;
}
static int
F_134 ( void * V_54 )
{
unsigned long V_127 ;
unsigned long V_40 ;
int V_19 ;
F_109 ( rand ) ;
struct V_4 * V_6 ;
int V_129 ;
struct V_137 V_138 ;
unsigned long long V_1 ;
F_86 ( L_25 ) ;
F_119 ( V_62 , V_122 ) ;
if ( V_139 && V_31 -> V_140 )
F_135 ( & V_138 , F_125 , 0 ) ;
do {
if ( V_139 && V_31 -> V_140 ) {
if ( ! F_136 ( & V_138 ) )
F_137 ( & V_138 , V_66 + 1 ) ;
}
V_19 = V_31 -> V_130 () ;
if ( V_31 -> V_127 )
V_127 = V_31 -> V_127 () ;
else
V_127 = V_31 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_111 ( V_117 ,
F_127 () ||
F_128 () ||
F_129 ( T_7 ) ||
F_82 () ) ;
if ( V_6 == NULL ) {
V_31 -> V_131 ( V_19 ) ;
F_48 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_132 ) ;
V_31 -> V_133 ( & rand ) ;
F_73 () ;
V_129 = V_6 -> V_22 ;
if ( V_129 > V_23 ) {
V_129 = V_23 ;
}
V_40 = V_31 -> V_40 () ;
if ( V_129 > 1 ) {
F_132 ( V_31 -> V_107 , & V_6 -> V_30 ,
V_1 , V_127 , V_40 ) ;
F_120 () ;
}
F_133 ( V_135 [ V_129 ] ) ;
V_40 = V_40 - V_127 ;
if ( V_31 -> V_127 )
V_40 ++ ;
if ( V_40 > V_23 ) {
V_40 = V_23 ;
}
F_133 ( V_136 [ V_40 ] ) ;
F_75 () ;
V_31 -> V_131 ( V_19 ) ;
F_90 ( L_26 ) ;
} while ( ! F_91 () );
if ( V_139 && V_31 -> V_140 ) {
F_138 ( & V_138 ) ;
F_139 ( & V_138 ) ;
}
F_99 ( L_26 ) ;
return 0 ;
}
static void
F_140 ( void )
{
int V_39 ;
int V_21 ;
long V_141 [ V_23 + 1 ] = { 0 } ;
long V_142 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_143 = V_144 ;
F_62 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_141 [ V_21 ] += F_141 ( V_135 , V_39 ) [ V_21 ] ;
V_142 [ V_21 ] += F_141 ( V_136 , V_39 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_141 [ V_21 ] != 0 )
break;
}
F_61 ( L_27 , V_41 , V_42 ) ;
F_64 ( L_28 ,
V_117 ,
V_120 ,
F_6 ( & V_8 ) ,
F_122 ( & V_10 ) ,
F_122 ( & V_9 ) ,
F_122 ( & V_13 ) ) ;
F_64 ( L_29 ,
F_122 ( & V_132 ) ,
V_145 ,
V_64 ) ;
F_64 ( L_30 ,
V_69 ,
V_72 ,
V_134 ) ;
F_142 () ;
F_64 ( L_31 ,
V_146 ,
V_147 ,
V_148 ) ;
F_64 ( L_32 , F_143 ( & V_83 ) ) ;
F_61 ( L_27 , V_41 , V_42 ) ;
if ( F_122 ( & V_132 ) != 0 ||
V_148 != 0 ||
V_145 != 0 ||
V_64 != 0 ||
V_69 != 0 ||
V_21 > 1 ) {
F_64 ( L_14 , L_33 ) ;
F_7 ( & V_149 ) ;
F_114 ( 1 ) ;
}
F_64 ( L_34 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_64 ( L_35 , V_141 [ V_21 ] ) ;
F_64 ( L_3 ) ;
F_61 ( L_27 , V_41 , V_42 ) ;
F_64 ( L_36 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_64 ( L_35 , V_142 [ V_21 ] ) ;
F_64 ( L_3 ) ;
F_61 ( L_27 , V_41 , V_42 ) ;
F_64 ( L_37 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_64 ( L_38 , F_122 ( & V_24 [ V_21 ] ) ) ;
}
F_64 ( L_3 ) ;
if ( V_31 -> V_150 )
V_31 -> V_150 () ;
if ( V_143 == V_120 &&
V_117 != NULL ) {
int T_3 V_151 ;
unsigned long T_3 V_152 ;
unsigned long T_3 V_40 ;
F_144 ( V_31 -> V_153 ,
& V_151 , & V_152 , & V_40 ) ;
F_61 ( L_39 ,
V_112 ,
V_152 , V_40 , V_151 ) ;
F_145 () ;
F_120 () ;
}
V_143 = V_120 ;
}
static int
F_146 ( void * V_54 )
{
F_86 ( L_40 ) ;
do {
F_48 ( V_154 * V_37 ) ;
F_140 () ;
F_97 ( L_41 ) ;
} while ( ! F_91 () );
F_99 ( L_41 ) ;
return 0 ;
}
static inline void
F_147 ( struct V_155 * V_31 , const char * V_156 )
{
F_61 ( L_14 V_42
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50 ,
V_41 , V_156 , V_18 , V_123 ,
V_154 , V_157 , V_158 , V_159 ,
V_160 , V_139 , V_87 , V_89 , V_86 ,
V_161 , V_31 -> V_162 ,
V_71 , V_68 , V_163 ,
V_164 , V_165 ,
V_166 ,
V_167 , V_168 ) ;
}
static void F_148 ( int V_39 )
{
struct V_169 * V_138 ;
if ( V_170 [ V_39 ] == NULL )
return;
F_149 ( & V_70 ) ;
V_138 = V_170 [ V_39 ] ;
V_170 [ V_39 ] = NULL ;
F_95 ( & V_70 ) ;
F_150 ( F_85 , V_138 ) ;
}
static int F_151 ( int V_39 )
{
int V_171 ;
if ( V_170 [ V_39 ] != NULL )
return 0 ;
F_149 ( & V_70 ) ;
F_86 ( L_51 ) ;
V_170 [ V_39 ] = F_152 ( F_85 , NULL ,
F_153 ( V_39 ) ,
L_6 ) ;
if ( F_154 ( V_170 [ V_39 ] ) ) {
V_171 = F_155 ( V_170 [ V_39 ] ) ;
F_86 ( L_52 ) ;
V_145 ++ ;
V_170 [ V_39 ] = NULL ;
F_95 ( & V_70 ) ;
return V_171 ;
}
F_156 ( V_170 [ V_39 ] , V_39 ) ;
F_157 ( V_170 [ V_39 ] ) ;
F_95 ( & V_70 ) ;
return 0 ;
}
static int F_158 ( void * args )
{
unsigned long V_172 ;
F_86 ( L_53 ) ;
if ( V_165 > 0 ) {
F_86 ( L_54 ) ;
F_48 ( V_165 * V_37 ) ;
F_86 ( L_55 ) ;
}
if ( ! F_93 () ) {
V_172 = F_159 () + V_164 ;
F_61 ( L_56 ) ;
F_14 () ;
F_73 () ;
while ( F_89 ( F_159 () , V_172 ) )
continue;
F_75 () ;
F_23 () ;
F_61 ( L_57 ) ;
}
F_97 ( L_58 ) ;
while ( ! F_93 () )
F_48 ( 10 * V_37 ) ;
return 0 ;
}
static int T_9 F_160 ( void )
{
if ( V_164 <= 0 )
return 0 ;
return F_161 ( F_158 , NULL , V_173 ) ;
}
static void F_162 ( struct V_29 * V_52 )
{
F_7 ( & V_174 ) ;
}
static int F_163 ( void * V_54 )
{
long V_175 = ( long ) V_54 ;
bool V_176 = 0 ;
bool V_177 ;
struct V_29 V_52 ;
F_88 ( & V_52 ) ;
F_86 ( L_59 ) ;
F_119 ( V_62 , V_122 ) ;
do {
F_164 ( V_178 [ V_175 ] ,
( V_177 =
F_92 ( & V_179 ) ) != V_176 ||
F_91 () ) ;
V_176 = V_177 ;
if ( F_91 () )
break;
V_31 -> V_79 ( & V_52 , F_162 ) ;
if ( F_165 ( & V_180 ) )
F_166 ( & V_181 ) ;
} while ( ! F_91 () );
if ( V_31 -> V_80 != NULL )
V_31 -> V_80 () ;
F_98 ( & V_52 ) ;
F_99 ( L_60 ) ;
return 0 ;
}
static int F_167 ( void * V_54 )
{
int V_21 ;
F_86 ( L_61 ) ;
do {
F_168 ( & V_174 , 0 ) ;
F_168 ( & V_180 , V_166 ) ;
F_84 ( & V_179 , ! V_179 ) ;
for ( V_21 = 0 ; V_21 < V_166 ; V_21 ++ )
F_166 ( & V_178 [ V_21 ] ) ;
F_164 ( V_181 ,
F_122 ( & V_180 ) == 0 ||
F_91 () ) ;
if ( F_91 () )
break;
V_147 ++ ;
V_31 -> V_80 () ;
if ( F_122 ( & V_174 ) != V_166 ) {
V_148 ++ ;
F_169 ( L_62 ,
F_122 ( & V_174 ) ,
V_166 ) ;
F_114 ( 1 ) ;
}
V_146 ++ ;
F_48 ( V_37 / 10 ) ;
} while ( ! F_91 () );
F_99 ( L_63 ) ;
return 0 ;
}
static int F_170 ( void )
{
int V_21 ;
int V_182 ;
if ( V_166 <= 0 )
return 0 ;
if ( V_31 -> V_79 == NULL || V_31 -> V_80 == NULL ) {
F_61 ( L_14 V_42
L_64 ,
V_41 , V_31 -> V_107 ) ;
F_61 ( L_14 V_42
L_65 ,
V_41 ) ;
return 0 ;
}
F_168 ( & V_180 , 0 ) ;
F_168 ( & V_174 , 0 ) ;
V_183 =
F_171 ( V_166 * sizeof( V_183 [ 0 ] ) ,
V_184 ) ;
V_178 =
F_171 ( V_166 * sizeof( V_178 [ 0 ] ) ,
V_184 ) ;
if ( V_183 == NULL || ! V_178 )
return - V_185 ;
for ( V_21 = 0 ; V_21 < V_166 ; V_21 ++ ) {
F_172 ( & V_178 [ V_21 ] ) ;
V_182 = F_161 ( F_163 ,
( void * ) ( long ) V_21 ,
V_183 [ V_21 ] ) ;
if ( V_182 )
return V_182 ;
}
return F_161 ( F_167 , NULL , V_186 ) ;
}
static void F_173 ( void )
{
int V_21 ;
F_150 ( F_167 , V_186 ) ;
if ( V_183 != NULL ) {
for ( V_21 = 0 ; V_21 < V_166 ; V_21 ++ )
F_150 ( F_163 ,
V_183 [ V_21 ] ) ;
F_174 ( V_183 ) ;
V_183 = NULL ;
}
if ( V_178 != NULL ) {
F_174 ( V_178 ) ;
V_178 = NULL ;
}
}
static int F_175 ( struct V_187 * V_188 ,
unsigned long V_189 , void * V_190 )
{
long V_39 = ( long ) V_190 ;
switch ( V_189 ) {
case V_191 :
case V_192 :
( void ) F_151 ( V_39 ) ;
break;
case V_193 :
F_148 ( V_39 ) ;
break;
default:
break;
}
return V_194 ;
}
static void
F_176 ( void )
{
int V_21 ;
F_177 () ;
if ( F_178 () ) {
if ( V_31 -> V_80 != NULL )
V_31 -> V_80 () ;
return;
}
F_173 () ;
F_150 ( F_158 , V_173 ) ;
F_150 ( F_107 , V_118 ) ;
if ( V_195 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_150 ( F_134 ,
V_195 [ V_21 ] ) ;
F_174 ( V_195 ) ;
}
V_117 = NULL ;
if ( V_196 ) {
for ( V_21 = 0 ; V_21 < V_123 ; V_21 ++ ) {
F_150 ( F_118 ,
V_196 [ V_21 ] ) ;
}
F_174 ( V_196 ) ;
V_196 = NULL ;
}
F_150 ( F_146 , V_197 ) ;
F_150 ( F_106 , V_198 ) ;
for ( V_21 = 0 ; V_21 < V_199 ; V_21 ++ )
F_150 ( F_101 , V_200 [ V_21 ] ) ;
if ( ( V_161 == 1 && V_31 -> V_162 ) ||
V_161 == 2 ) {
F_179 ( & V_201 ) ;
F_62 (i)
F_148 ( V_21 ) ;
}
if ( V_31 -> V_80 != NULL )
V_31 -> V_80 () ;
if ( V_31 -> V_202 != NULL )
V_31 -> V_202 () ;
F_140 () ;
if ( F_122 ( & V_149 ) || V_148 )
F_147 ( V_31 , L_66 ) ;
else if ( F_180 () )
F_147 ( V_31 ,
L_67 ) ;
else
F_147 ( V_31 , L_68 ) ;
F_181 () ;
}
static void F_182 ( struct V_29 * V_73 )
{
}
static void F_183 ( struct V_29 * V_73 )
{
F_61 ( L_69 ) ;
}
static void F_184 ( void )
{
#ifdef F_185
struct V_29 V_203 ;
struct V_29 V_204 ;
F_88 ( & V_203 ) ;
F_88 ( & V_204 ) ;
F_61 ( L_70 ) ;
F_73 () ;
F_14 () ;
F_33 ( & V_203 , F_182 ) ;
F_186 () ;
F_33 ( & V_204 , F_182 ) ;
F_33 ( & V_204 , F_183 ) ;
F_187 () ;
F_23 () ;
F_75 () ;
F_188 () ;
F_61 ( L_71 ) ;
F_98 ( & V_203 ) ;
F_98 ( & V_204 ) ;
#else
F_61 ( L_72 ) ;
#endif
}
static int T_9
F_189 ( void )
{
int V_21 ;
int V_39 ;
int V_205 = 0 ;
static struct V_155 * V_206 [] = {
& V_207 , & V_208 , & V_209 , & V_210 , & V_211 ,
& V_212 , V_213
} ;
if ( ! F_190 ( V_41 , V_157 , & V_214 ) )
return - V_215 ;
for ( V_21 = 0 ; V_21 < F_191 ( V_206 ) ; V_21 ++ ) {
V_31 = V_206 [ V_21 ] ;
if ( strcmp ( V_41 , V_31 -> V_107 ) == 0 )
break;
}
if ( V_21 == F_191 ( V_206 ) ) {
F_61 ( L_73 ,
V_41 ) ;
F_61 ( L_74 ) ;
for ( V_21 = 0 ; V_21 < F_191 ( V_206 ) ; V_21 ++ )
F_61 ( L_75 , V_206 [ V_21 ] -> V_107 ) ;
F_61 ( L_3 ) ;
V_205 = - V_216 ;
goto V_217;
}
if ( V_31 -> V_88 == NULL && V_87 != 0 ) {
F_61 ( L_76 ) ;
V_87 = 0 ;
}
if ( V_31 -> V_218 )
V_31 -> V_218 () ;
if ( V_219 >= 0 ) {
V_18 = V_219 ;
} else {
V_18 = F_192 () - 2 - V_219 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_147 ( V_31 , L_77 ) ;
F_35 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_191 ( V_220 ) ; V_21 ++ ) {
V_220 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_220 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_117 = NULL ;
V_120 = 0 ;
F_168 ( & V_10 , 0 ) ;
F_168 ( & V_9 , 0 ) ;
F_168 ( & V_13 , 0 ) ;
F_168 ( & V_132 , 0 ) ;
F_168 ( & V_149 , 0 ) ;
V_148 = 0 ;
V_145 = 0 ;
V_64 = 0 ;
V_69 = 0 ;
V_72 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_168 ( & V_24 [ V_21 ] , 0 ) ;
F_62 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_141 ( V_135 , V_39 ) [ V_21 ] = 0 ;
F_141 ( V_136 , V_39 ) [ V_21 ] = 0 ;
}
}
V_205 = F_161 ( F_107 , NULL ,
V_118 ) ;
if ( V_205 )
goto V_217;
if ( V_123 > 0 ) {
V_196 = F_171 ( V_123 *
sizeof( V_196 [ 0 ] ) ,
V_184 ) ;
if ( V_196 == NULL ) {
F_193 ( L_78 ) ;
V_205 = - V_185 ;
goto V_217;
}
}
for ( V_21 = 0 ; V_21 < V_123 ; V_21 ++ ) {
V_205 = F_161 ( F_118 ,
NULL , V_196 [ V_21 ] ) ;
if ( V_205 )
goto V_217;
}
V_195 = F_171 ( V_18 * sizeof( V_195 [ 0 ] ) ,
V_184 ) ;
if ( V_195 == NULL ) {
F_193 ( L_78 ) ;
V_205 = - V_185 ;
goto V_217;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_205 = F_161 ( F_134 , NULL ,
V_195 [ V_21 ] ) ;
if ( V_205 )
goto V_217;
}
if ( V_154 > 0 ) {
V_205 = F_161 ( F_146 , NULL ,
V_197 ) ;
if ( V_205 )
goto V_217;
}
if ( V_158 && V_159 > 0 ) {
V_205 = F_194 ( V_159 * V_37 ) ;
if ( V_205 )
goto V_217;
}
if ( V_160 < 0 )
V_160 = 0 ;
if ( V_160 ) {
V_205 = F_195 ( V_160 * V_37 ) ;
if ( V_205 )
goto V_217;
}
if ( V_87 < 0 )
V_87 = 0 ;
if ( V_87 ) {
V_205 = F_161 ( F_106 , NULL ,
V_198 ) ;
if ( V_205 )
goto V_217;
}
if ( V_71 < 1 )
V_71 = 1 ;
if ( V_68 < 2 )
V_68 = 2 ;
if ( ( V_161 == 1 && V_31 -> V_162 ) ||
V_161 == 2 ) {
V_65 = V_66 + V_71 * V_37 ;
F_196 ( & V_201 ) ;
F_62 (i) {
if ( F_197 ( V_21 ) )
continue;
V_205 = F_151 ( V_21 ) ;
if ( V_205 )
goto V_217;
}
}
V_205 = F_198 ( V_163 , F_176 ) ;
if ( V_205 )
goto V_217;
V_205 = F_199 ( V_168 * V_37 , V_167 * V_37 ) ;
if ( V_205 )
goto V_217;
V_205 = F_160 () ;
if ( V_205 )
goto V_217;
V_205 = F_170 () ;
if ( V_205 )
goto V_217;
if ( V_221 )
F_184 () ;
if ( V_81 > 0 ) {
V_199 = ( F_192 () + 3 ) / 4 ;
V_200 = F_200 ( V_199 , sizeof( * V_200 ) ,
V_184 ) ;
if ( ! V_200 ) {
F_193 ( L_78 ) ;
V_205 = - V_185 ;
goto V_217;
}
for ( V_21 = 0 ; V_21 < V_199 ; V_21 ++ ) {
V_205 = F_161 ( F_101 ,
NULL ,
V_200 [ V_21 ] ) ;
if ( V_205 )
goto V_217;
}
}
F_177 () ;
F_201 () ;
return 0 ;
V_217:
F_201 () ;
F_176 () ;
return V_205 ;
}
