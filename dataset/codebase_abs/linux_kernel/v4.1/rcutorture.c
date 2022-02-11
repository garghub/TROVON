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
static int F_46 ( void ) __acquires( &srcu_ctl
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
static void F_49 ( int V_19 ) __releases( &srcu_ctl
static unsigned long F_50 ( void )
{
return F_51 ( & V_39 ) ;
}
static void F_52 ( struct V_4 * V_20 )
{
F_53 ( & V_39 , & V_20 -> V_30 , F_29 ) ;
}
static void F_54 ( void )
{
F_55 ( & V_39 ) ;
}
static void F_56 ( struct V_29 * V_33 ,
void (* F_45)( struct V_29 * V_33 ) )
{
F_53 ( & V_39 , V_33 , F_45 ) ;
}
static void F_57 ( void )
{
F_58 ( & V_39 ) ;
}
static void F_59 ( void )
{
int V_40 ;
int V_19 = V_39 . V_41 & 0x1 ;
F_60 ( L_1 ,
V_42 , V_43 , V_19 ) ;
F_61 (cpu) {
long V_44 , V_45 ;
V_44 = ( long ) F_62 ( V_39 . V_46 , V_40 ) -> V_47 [ ! V_19 ] ;
V_45 = ( long ) F_62 ( V_39 . V_46 , V_40 ) -> V_47 [ V_19 ] ;
F_63 ( L_2 , V_40 , V_44 , V_45 ) ;
}
F_63 ( L_3 ) ;
}
static void F_64 ( void )
{
F_65 ( & V_39 ) ;
}
static int F_66 ( void )
{
F_67 () ;
return 0 ;
}
static void F_68 ( int V_19 )
{
F_69 () ;
}
static void F_70 ( struct V_4 * V_6 )
{
F_71 ( & V_6 -> V_30 , F_29 ) ;
}
static int F_72 ( void )
{
return 0 ;
}
static void F_73 ( int V_19 )
{
}
static void F_74 ( struct V_4 * V_6 )
{
F_75 ( & V_6 -> V_30 , F_29 ) ;
}
static void F_76 ( struct V_29 * V_33 )
{
struct V_48 * V_49 =
F_10 ( V_33 , struct V_48 , V_34 ) ;
F_77 () ;
V_49 -> V_50 = 0 ;
}
static int F_78 ( void * V_51 )
{
unsigned long V_52 ;
unsigned long V_53 ;
unsigned long V_54 ;
struct V_48 V_55 = { . V_50 = 0 } ;
struct V_56 V_57 ;
F_79 ( L_4 ) ;
V_57 . V_58 = 1 ;
if ( F_80 ( V_59 , V_60 , & V_57 ) < 0 ) {
F_79 ( L_5 ) ;
V_61 ++ ;
}
F_81 ( & V_55 . V_34 ) ;
do {
V_54 = V_62 ;
while ( F_82 ( V_63 , V_54 ) ) {
F_48 ( V_54 - V_63 ) ;
F_83 ( L_6 ) ;
if ( F_84 () )
goto V_64;
}
V_53 = V_54 + V_65 * V_37 ;
V_52 = V_63 ;
while ( F_82 ( V_63 , V_53 ) ) {
if ( ! V_55 . V_50 ) {
F_77 () ;
V_55 . V_50 = 1 ;
F_33 ( & V_55 . V_34 , F_76 ) ;
if ( V_63 - V_52 >
V_65 * V_37 - V_37 / 2 ) {
F_79 ( L_7 ) ;
V_66 ++ ;
}
V_52 = V_63 ;
}
F_85 () ;
F_83 ( L_6 ) ;
if ( F_84 () )
goto V_64;
}
while ( V_54 == V_62 &&
! F_86 () ) {
if ( F_87 ( & V_67 ) ) {
V_62 = V_63 +
V_68 * V_37 ;
V_69 ++ ;
F_88 ( & V_67 ) ;
break;
}
F_89 ( 1 ) ;
}
V_64: F_83 ( L_6 ) ;
} while ( ! F_84 () );
while ( ! F_86 () || V_55 . V_50 ) {
F_90 ( L_6 ) ;
F_89 ( 1 ) ;
}
F_77 () ;
F_91 ( & V_55 . V_34 ) ;
F_92 ( L_6 ) ;
return 0 ;
}
static void F_93 ( struct V_29 * V_70 )
{
}
static int
F_94 ( void * V_51 )
{
int V_71 = 1 ;
int V_21 ;
int V_72 ;
struct V_29 * V_70 ;
if ( V_73 > 0 &&
V_74 > 0 &&
V_75 > 0 &&
V_31 -> V_76 &&
V_31 -> V_77 ) {
V_70 = F_95 ( sizeof( * V_70 ) *
V_78 * V_73 ) ;
V_71 = ! V_70 ;
}
if ( V_71 ) {
F_79 ( L_8 ) ;
while ( ! F_84 () )
F_48 ( V_37 ) ;
return 0 ;
}
F_79 ( L_9 ) ;
do {
F_48 ( V_74 ) ;
F_96 ( & V_79 ) ;
F_97 ( F_98 ( V_59 ) ) ;
for ( V_21 = 0 ; V_21 < V_78 ; V_21 ++ ) {
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
V_31 -> V_76 ( & V_70 [ V_21 * V_73 + V_72 ] ,
F_93 ) ;
}
F_48 ( V_75 ) ;
F_97 ( F_98 ( V_59 ) ) ;
}
V_31 -> V_77 () ;
F_83 ( L_10 ) ;
} while ( ! F_84 () );
F_99 ( V_70 ) ;
F_92 ( L_10 ) ;
return 0 ;
}
static int
F_100 ( void * V_51 )
{
unsigned long V_80 ;
int V_81 ;
F_79 ( L_11 ) ;
do {
V_80 = V_63 + V_82 * V_37 ;
while ( F_82 ( V_63 , V_80 ) &&
! F_86 () ) {
F_48 ( 1 ) ;
}
V_81 = V_83 ;
while ( V_81 > 0 &&
! F_86 () ) {
V_31 -> V_84 () ;
F_18 ( V_85 ) ;
V_81 -= V_85 ;
}
F_83 ( L_12 ) ;
} while ( ! F_84 () );
F_92 ( L_12 ) ;
return 0 ;
}
static int
F_101 ( void * V_51 )
{
bool V_86 = ! F_102 () ;
int V_87 = 0 ;
unsigned long V_88 ;
bool V_89 = V_90 , V_91 = V_92 , V_93 = V_94 ;
bool V_95 = V_96 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_103 ( rand ) ;
int V_97 [] = { V_98 , V_99 ,
V_100 , V_101 } ;
int V_102 = 0 ;
F_79 ( L_13 ) ;
F_60 ( L_14 V_43
L_15 ,
V_42 , V_31 -> V_103 ) ;
F_60 ( L_14 V_43
L_16 ,
V_42 ) ;
if ( ! V_89 && ! V_91 && ! V_93 && ! V_95 )
V_89 = V_91 = V_93 = V_95 = true ;
if ( V_89 && V_31 -> V_104 && V_31 -> V_105 )
V_97 [ V_102 ++ ] = V_100 ;
else if ( V_90 && ( ! V_31 -> V_104 || ! V_31 -> V_105 ) )
F_60 ( L_17 ) ;
if ( V_91 && V_31 -> V_106 )
V_97 [ V_102 ++ ] = V_99 ;
else if ( V_92 && ! V_31 -> V_106 )
F_60 ( L_18 ) ;
if ( V_93 && V_31 -> V_32 )
V_97 [ V_102 ++ ] = V_98 ;
else if ( V_94 && ! V_31 -> V_32 )
F_60 ( L_19 ) ;
if ( V_95 && V_31 -> V_107 )
V_97 [ V_102 ++ ] = V_101 ;
else if ( V_96 && ! V_31 -> V_107 )
F_60 ( L_20 ) ;
if ( F_104 ( V_102 == 0 ,
L_21 ) ) {
V_108 = V_109 ;
F_92 ( L_22 ) ;
}
do {
V_108 = V_110 ;
F_89 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_108 = V_111 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_108 = V_112 ;
V_26 = F_105 ( V_113 ,
V_59 == V_114 ) ;
V_20 -> V_25 = 1 ;
F_106 ( V_113 , V_20 ) ;
F_107 () ;
if ( V_26 ) {
V_21 = V_26 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
V_26 -> V_22 ++ ;
switch ( V_97 [ F_16 ( & rand ) % V_102 ] ) {
case V_98 :
V_108 = V_98 ;
V_31 -> V_32 ( V_26 ) ;
break;
case V_99 :
V_108 = V_99 ;
V_31 -> V_106 () ;
F_25 ( V_26 ) ;
break;
case V_100 :
V_108 = V_100 ;
V_88 = V_31 -> V_104 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_48 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_108 = V_115 ;
V_31 -> V_105 ( V_88 ) ;
F_25 ( V_26 ) ;
break;
case V_101 :
V_108 = V_101 ;
V_31 -> V_107 () ;
F_25 ( V_26 ) ;
break;
default:
F_108 ( 1 ) ;
break;
}
}
F_109 ( ++ V_116 ) ;
if ( V_86 &&
! ( F_16 ( & rand ) & 0xff & ( ! ! V_87 - 1 ) ) ) {
F_108 ( V_87 == 0 && F_102 () ) ;
if ( V_87 >= 0 )
F_110 () ;
else
F_111 () ;
if ( ++ V_87 > 3 )
V_87 = - V_87 ;
}
V_108 = V_117 ;
F_83 ( L_22 ) ;
} while ( ! F_84 () );
if ( V_87 > 0 )
V_87 = - V_87 ;
while ( V_86 && V_87 ++ < 0 )
F_111 () ;
F_108 ( V_86 && F_102 () ) ;
V_108 = V_109 ;
F_92 ( L_22 ) ;
return 0 ;
}
static int
F_112 ( void * V_51 )
{
F_103 ( rand ) ;
F_79 ( L_23 ) ;
F_113 ( V_59 , V_118 ) ;
do {
F_89 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_31 -> V_77 != NULL &&
F_16 ( & rand ) % ( V_119 * 8 ) == 0 ) {
V_31 -> V_77 () ;
} else if ( V_94 == V_92 ) {
if ( F_16 ( & rand ) & 0x80 )
V_31 -> V_107 () ;
else
V_31 -> V_106 () ;
} else if ( V_94 ) {
V_31 -> V_107 () ;
} else {
V_31 -> V_106 () ;
}
F_83 ( L_24 ) ;
} while ( ! F_84 () );
F_92 ( L_24 ) ;
return 0 ;
}
static void F_114 ( void )
{
static T_6 V_120 = F_115 ( 0 ) ;
if ( F_116 ( & V_120 ) )
return;
if ( F_117 ( & V_120 , 1 ) != 0 )
return;
F_118 ( V_121 ) ;
}
static void F_119 ( unsigned long V_122 )
{
int V_19 ;
unsigned long V_123 ;
unsigned long V_41 ;
static F_103 ( rand ) ;
static F_120 ( V_124 ) ;
struct V_4 * V_6 ;
int V_125 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_126 () ;
if ( V_31 -> V_123 )
V_123 = V_31 -> V_123 () ;
else
V_123 = V_31 -> V_41 () ;
V_1 = F_1 () ;
V_6 = F_105 ( V_113 ,
F_121 () ||
F_122 () ||
F_123 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_127 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_128 ) ;
F_124 ( & V_124 ) ;
V_31 -> V_129 ( & rand ) ;
V_130 ++ ;
F_125 ( & V_124 ) ;
F_67 () ;
V_125 = V_6 -> V_22 ;
if ( V_125 > V_23 ) {
V_125 = V_23 ;
}
V_41 = V_31 -> V_41 () ;
if ( V_125 > 1 ) {
F_126 ( V_31 -> V_103 , & V_6 -> V_30 , V_1 ,
V_123 , V_41 ) ;
F_114 () ;
}
F_127 ( V_131 [ V_125 ] ) ;
V_41 = V_41 - V_123 ;
if ( V_31 -> V_123 )
V_41 ++ ;
if ( V_41 > V_23 ) {
V_41 = V_23 ;
}
F_127 ( V_132 [ V_41 ] ) ;
F_69 () ;
V_31 -> V_127 ( V_19 ) ;
}
static int
F_128 ( void * V_51 )
{
unsigned long V_123 ;
unsigned long V_41 ;
int V_19 ;
F_103 ( rand ) ;
struct V_4 * V_6 ;
int V_125 ;
struct V_133 V_134 ;
unsigned long long V_1 ;
F_79 ( L_25 ) ;
F_113 ( V_59 , V_118 ) ;
if ( V_135 && V_31 -> V_136 )
F_129 ( & V_134 , F_119 , 0 ) ;
do {
if ( V_135 && V_31 -> V_136 ) {
if ( ! F_130 ( & V_134 ) )
F_131 ( & V_134 , V_63 + 1 ) ;
}
V_19 = V_31 -> V_126 () ;
if ( V_31 -> V_123 )
V_123 = V_31 -> V_123 () ;
else
V_123 = V_31 -> V_41 () ;
V_1 = F_1 () ;
V_6 = F_105 ( V_113 ,
F_121 () ||
F_122 () ||
F_123 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_127 ( V_19 ) ;
F_48 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_128 ) ;
V_31 -> V_129 ( & rand ) ;
F_67 () ;
V_125 = V_6 -> V_22 ;
if ( V_125 > V_23 ) {
V_125 = V_23 ;
}
V_41 = V_31 -> V_41 () ;
if ( V_125 > 1 ) {
F_126 ( V_31 -> V_103 , & V_6 -> V_30 ,
V_1 , V_123 , V_41 ) ;
F_114 () ;
}
F_127 ( V_131 [ V_125 ] ) ;
V_41 = V_41 - V_123 ;
if ( V_31 -> V_123 )
V_41 ++ ;
if ( V_41 > V_23 ) {
V_41 = V_23 ;
}
F_127 ( V_132 [ V_41 ] ) ;
F_69 () ;
V_31 -> V_127 ( V_19 ) ;
F_85 () ;
F_83 ( L_26 ) ;
} while ( ! F_84 () );
if ( V_135 && V_31 -> V_136 ) {
F_132 ( & V_134 ) ;
F_133 ( & V_134 ) ;
}
F_92 ( L_26 ) ;
return 0 ;
}
static void
F_134 ( void )
{
int V_40 ;
int V_21 ;
long V_137 [ V_23 + 1 ] = { 0 } ;
long V_138 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_139 = V_140 ;
F_61 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_137 [ V_21 ] += F_135 ( V_131 , V_40 ) [ V_21 ] ;
V_138 [ V_21 ] += F_135 ( V_132 , V_40 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_137 [ V_21 ] != 0 )
break;
}
F_60 ( L_27 , V_42 , V_43 ) ;
F_63 ( L_28 ,
V_113 ,
V_116 ,
F_6 ( & V_8 ) ,
F_116 ( & V_10 ) ,
F_116 ( & V_9 ) ,
F_116 ( & V_13 ) ) ;
F_63 ( L_29 ,
F_116 ( & V_128 ) ,
V_141 ,
V_61 ) ;
F_63 ( L_30 ,
V_66 ,
V_69 ,
V_130 ) ;
F_136 () ;
F_63 ( L_31 ,
V_142 ,
V_143 ,
V_144 ) ;
F_63 ( L_32 , F_137 ( & V_79 ) ) ;
F_60 ( L_27 , V_42 , V_43 ) ;
if ( F_116 ( & V_128 ) != 0 ||
V_144 != 0 ||
V_141 != 0 ||
V_61 != 0 ||
V_66 != 0 ||
V_21 > 1 ) {
F_63 ( L_14 , L_33 ) ;
F_7 ( & V_145 ) ;
F_108 ( 1 ) ;
}
F_63 ( L_34 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_63 ( L_35 , V_137 [ V_21 ] ) ;
F_63 ( L_3 ) ;
F_60 ( L_27 , V_42 , V_43 ) ;
F_63 ( L_36 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_63 ( L_35 , V_138 [ V_21 ] ) ;
F_63 ( L_3 ) ;
F_60 ( L_27 , V_42 , V_43 ) ;
F_63 ( L_37 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_63 ( L_38 , F_116 ( & V_24 [ V_21 ] ) ) ;
}
F_63 ( L_3 ) ;
if ( V_31 -> V_146 )
V_31 -> V_146 () ;
if ( V_139 == V_116 &&
V_113 != NULL ) {
int T_3 V_147 ;
unsigned long T_3 V_148 ;
unsigned long T_3 V_41 ;
F_138 ( V_31 -> V_149 ,
& V_147 , & V_148 , & V_41 ) ;
F_60 ( L_39 ,
V_108 ,
V_148 , V_41 , V_147 ) ;
F_139 () ;
F_114 () ;
}
V_139 = V_116 ;
}
static int
F_140 ( void * V_51 )
{
F_79 ( L_40 ) ;
do {
F_48 ( V_150 * V_37 ) ;
F_134 () ;
F_90 ( L_41 ) ;
} while ( ! F_84 () );
F_92 ( L_41 ) ;
return 0 ;
}
static inline void
F_141 ( struct V_151 * V_31 , const char * V_152 )
{
F_60 ( L_14 V_43
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50 ,
V_42 , V_152 , V_18 , V_119 ,
V_150 , V_153 , V_154 , V_155 ,
V_156 , V_135 , V_83 , V_85 , V_82 ,
V_157 , V_31 -> V_158 ,
V_68 , V_65 , V_159 ,
V_160 , V_161 ,
V_162 ,
V_163 , V_164 ) ;
}
static void F_142 ( int V_40 )
{
struct V_165 * V_134 ;
if ( V_166 [ V_40 ] == NULL )
return;
F_143 ( & V_67 ) ;
V_134 = V_166 [ V_40 ] ;
V_166 [ V_40 ] = NULL ;
F_88 ( & V_67 ) ;
F_144 ( F_78 , V_134 ) ;
}
static int F_145 ( int V_40 )
{
int V_167 ;
if ( V_166 [ V_40 ] != NULL )
return 0 ;
F_143 ( & V_67 ) ;
F_79 ( L_51 ) ;
V_166 [ V_40 ] = F_146 ( F_78 , NULL ,
F_147 ( V_40 ) ,
L_6 ) ;
if ( F_148 ( V_166 [ V_40 ] ) ) {
V_167 = F_149 ( V_166 [ V_40 ] ) ;
F_79 ( L_52 ) ;
V_141 ++ ;
V_166 [ V_40 ] = NULL ;
F_88 ( & V_67 ) ;
return V_167 ;
}
F_150 ( V_166 [ V_40 ] , V_40 ) ;
F_151 ( V_166 [ V_40 ] ) ;
F_88 ( & V_67 ) ;
return 0 ;
}
static int F_152 ( void * args )
{
unsigned long V_168 ;
F_79 ( L_53 ) ;
if ( V_161 > 0 ) {
F_79 ( L_54 ) ;
F_48 ( V_161 * V_37 ) ;
F_79 ( L_55 ) ;
}
if ( ! F_86 () ) {
V_168 = F_153 () + V_160 ;
F_60 ( L_56 ) ;
F_14 () ;
F_67 () ;
while ( F_82 ( F_153 () , V_168 ) )
continue;
F_69 () ;
F_23 () ;
F_60 ( L_57 ) ;
}
F_90 ( L_58 ) ;
while ( ! F_86 () )
F_48 ( 10 * V_37 ) ;
return 0 ;
}
static int T_7 F_154 ( void )
{
if ( V_160 <= 0 )
return 0 ;
return F_155 ( F_152 , NULL , V_169 ) ;
}
static void F_156 ( struct V_29 * V_34 )
{
F_7 ( & V_170 ) ;
}
static int F_157 ( void * V_51 )
{
long V_171 = ( long ) V_51 ;
bool V_172 = 0 ;
bool V_173 ;
struct V_29 V_34 ;
F_81 ( & V_34 ) ;
F_79 ( L_59 ) ;
F_113 ( V_59 , V_118 ) ;
do {
F_158 ( V_174 [ V_171 ] ,
( V_173 =
F_159 ( V_175 ) ) != V_172 ||
F_84 () ) ;
V_172 = V_173 ;
F_77 () ;
if ( F_84 () )
break;
V_31 -> V_76 ( & V_34 , F_156 ) ;
if ( F_160 ( & V_176 ) )
F_161 ( & V_177 ) ;
} while ( ! F_84 () );
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
F_91 ( & V_34 ) ;
F_92 ( L_60 ) ;
return 0 ;
}
static int F_162 ( void * V_51 )
{
int V_21 ;
F_79 ( L_61 ) ;
do {
F_163 ( & V_170 , 0 ) ;
F_163 ( & V_176 , V_162 ) ;
F_77 () ;
V_175 = ! V_175 ;
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ )
F_161 ( & V_174 [ V_21 ] ) ;
F_158 ( V_177 ,
F_116 ( & V_176 ) == 0 ||
F_84 () ) ;
if ( F_84 () )
break;
V_143 ++ ;
V_31 -> V_77 () ;
if ( F_116 ( & V_170 ) != V_162 ) {
V_144 ++ ;
F_164 ( L_62 ,
F_116 ( & V_170 ) ,
V_162 ) ;
F_108 ( 1 ) ;
}
V_142 ++ ;
F_48 ( V_37 / 10 ) ;
} while ( ! F_84 () );
F_92 ( L_63 ) ;
return 0 ;
}
static int F_165 ( void )
{
int V_21 ;
int V_178 ;
if ( V_162 == 0 )
return 0 ;
if ( V_31 -> V_76 == NULL || V_31 -> V_77 == NULL ) {
F_60 ( L_14 V_43
L_64 ,
V_42 , V_31 -> V_103 ) ;
F_60 ( L_14 V_43
L_65 ,
V_42 ) ;
return 0 ;
}
F_163 ( & V_176 , 0 ) ;
F_163 ( & V_170 , 0 ) ;
V_179 =
F_166 ( V_162 * sizeof( V_179 [ 0 ] ) ,
V_180 ) ;
V_174 =
F_166 ( V_162 * sizeof( V_174 [ 0 ] ) ,
V_180 ) ;
if ( V_179 == NULL || ! V_174 )
return - V_181 ;
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ ) {
F_167 ( & V_174 [ V_21 ] ) ;
V_178 = F_155 ( F_157 ,
( void * ) ( long ) V_21 ,
V_179 [ V_21 ] ) ;
if ( V_178 )
return V_178 ;
}
return F_155 ( F_162 , NULL , V_182 ) ;
}
static void F_168 ( void )
{
int V_21 ;
F_144 ( F_162 , V_182 ) ;
if ( V_179 != NULL ) {
for ( V_21 = 0 ; V_21 < V_162 ; V_21 ++ )
F_144 ( F_157 ,
V_179 [ V_21 ] ) ;
F_169 ( V_179 ) ;
V_179 = NULL ;
}
if ( V_174 != NULL ) {
F_169 ( V_174 ) ;
V_174 = NULL ;
}
}
static int F_170 ( struct V_183 * V_184 ,
unsigned long V_185 , void * V_186 )
{
long V_40 = ( long ) V_186 ;
switch ( V_185 ) {
case V_187 :
case V_188 :
( void ) F_145 ( V_40 ) ;
break;
case V_189 :
F_142 ( V_40 ) ;
break;
default:
break;
}
return V_190 ;
}
static void
F_171 ( void )
{
int V_21 ;
F_172 () ;
if ( F_173 () ) {
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
return;
}
F_168 () ;
F_144 ( F_152 , V_169 ) ;
F_144 ( F_101 , V_114 ) ;
if ( V_191 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_144 ( F_128 ,
V_191 [ V_21 ] ) ;
F_169 ( V_191 ) ;
}
V_113 = NULL ;
if ( V_192 ) {
for ( V_21 = 0 ; V_21 < V_119 ; V_21 ++ ) {
F_144 ( F_112 ,
V_192 [ V_21 ] ) ;
}
F_169 ( V_192 ) ;
V_192 = NULL ;
}
F_144 ( F_140 , V_193 ) ;
F_144 ( F_100 , V_194 ) ;
for ( V_21 = 0 ; V_21 < V_195 ; V_21 ++ )
F_144 ( F_94 , V_196 [ V_21 ] ) ;
if ( ( V_157 == 1 && V_31 -> V_158 ) ||
V_157 == 2 ) {
F_174 ( & V_197 ) ;
F_61 (i)
F_142 ( V_21 ) ;
}
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
F_134 () ;
if ( F_116 ( & V_145 ) || V_144 )
F_141 ( V_31 , L_66 ) ;
else if ( F_175 () )
F_141 ( V_31 ,
L_67 ) ;
else
F_141 ( V_31 , L_68 ) ;
F_176 () ;
}
static void F_177 ( struct V_29 * V_70 )
{
}
static void F_178 ( struct V_29 * V_70 )
{
F_60 ( L_69 ) ;
}
static void F_179 ( void )
{
#ifdef F_180
struct V_29 V_198 ;
struct V_29 V_199 ;
F_81 ( & V_198 ) ;
F_81 ( & V_199 ) ;
F_60 ( L_70 ) ;
F_67 () ;
F_14 () ;
F_33 ( & V_198 , F_177 ) ;
F_181 () ;
F_33 ( & V_199 , F_177 ) ;
F_33 ( & V_199 , F_178 ) ;
F_182 () ;
F_23 () ;
F_69 () ;
F_183 () ;
F_60 ( L_71 ) ;
F_91 ( & V_198 ) ;
F_91 ( & V_199 ) ;
#else
F_60 ( L_72 ) ;
#endif
}
static int T_7
F_184 ( void )
{
int V_21 ;
int V_40 ;
int V_200 = 0 ;
static struct V_151 * V_201 [] = {
& V_202 , & V_203 , & V_204 , & V_205 , & V_206 ,
V_207
} ;
if ( ! F_185 ( V_42 , V_153 , & V_208 ) )
return - V_209 ;
for ( V_21 = 0 ; V_21 < F_186 ( V_201 ) ; V_21 ++ ) {
V_31 = V_201 [ V_21 ] ;
if ( strcmp ( V_42 , V_31 -> V_103 ) == 0 )
break;
}
if ( V_21 == F_186 ( V_201 ) ) {
F_60 ( L_73 ,
V_42 ) ;
F_60 ( L_74 ) ;
for ( V_21 = 0 ; V_21 < F_186 ( V_201 ) ; V_21 ++ )
F_60 ( L_75 , V_201 [ V_21 ] -> V_103 ) ;
F_60 ( L_3 ) ;
F_187 () ;
return - V_210 ;
}
if ( V_31 -> V_84 == NULL && V_83 != 0 ) {
F_60 ( L_76 ) ;
V_83 = 0 ;
}
if ( V_31 -> V_211 )
V_31 -> V_211 () ;
if ( V_212 >= 0 ) {
V_18 = V_212 ;
} else {
V_18 = F_188 () - 1 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_141 ( V_31 , L_77 ) ;
F_35 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_186 ( V_213 ) ; V_21 ++ ) {
V_213 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_213 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_113 = NULL ;
V_116 = 0 ;
F_163 ( & V_10 , 0 ) ;
F_163 ( & V_9 , 0 ) ;
F_163 ( & V_13 , 0 ) ;
F_163 ( & V_128 , 0 ) ;
F_163 ( & V_145 , 0 ) ;
V_144 = 0 ;
V_141 = 0 ;
V_61 = 0 ;
V_66 = 0 ;
V_69 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_163 ( & V_24 [ V_21 ] , 0 ) ;
F_61 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_135 ( V_131 , V_40 ) [ V_21 ] = 0 ;
F_135 ( V_132 , V_40 ) [ V_21 ] = 0 ;
}
}
V_200 = F_155 ( F_101 , NULL ,
V_114 ) ;
if ( V_200 )
goto V_214;
V_192 = F_166 ( V_119 * sizeof( V_192 [ 0 ] ) ,
V_180 ) ;
if ( V_192 == NULL ) {
F_189 ( L_78 ) ;
V_200 = - V_181 ;
goto V_214;
}
for ( V_21 = 0 ; V_21 < V_119 ; V_21 ++ ) {
V_200 = F_155 ( F_112 ,
NULL , V_192 [ V_21 ] ) ;
if ( V_200 )
goto V_214;
}
V_191 = F_166 ( V_18 * sizeof( V_191 [ 0 ] ) ,
V_180 ) ;
if ( V_191 == NULL ) {
F_189 ( L_78 ) ;
V_200 = - V_181 ;
goto V_214;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_200 = F_155 ( F_128 , NULL ,
V_191 [ V_21 ] ) ;
if ( V_200 )
goto V_214;
}
if ( V_150 > 0 ) {
V_200 = F_155 ( F_140 , NULL ,
V_193 ) ;
if ( V_200 )
goto V_214;
}
if ( V_154 ) {
V_200 = F_190 ( V_155 * V_37 ) ;
if ( V_200 )
goto V_214;
}
if ( V_156 < 0 )
V_156 = 0 ;
if ( V_156 ) {
V_200 = F_191 ( V_156 * V_37 ) ;
if ( V_200 )
goto V_214;
}
if ( V_83 < 0 )
V_83 = 0 ;
if ( V_83 ) {
V_200 = F_155 ( F_100 , NULL ,
V_194 ) ;
if ( V_200 )
goto V_214;
}
if ( V_68 < 1 )
V_68 = 1 ;
if ( V_65 < 2 )
V_65 = 2 ;
if ( ( V_157 == 1 && V_31 -> V_158 ) ||
V_157 == 2 ) {
V_62 = V_63 + V_68 * V_37 ;
F_192 ( & V_197 ) ;
F_61 (i) {
if ( F_193 ( V_21 ) )
continue;
V_200 = F_145 ( V_21 ) ;
if ( V_200 )
goto V_214;
}
}
V_200 = F_194 ( V_159 , F_171 ) ;
if ( V_200 )
goto V_214;
V_200 = F_195 ( V_164 * V_37 , V_163 * V_37 ) ;
if ( V_200 )
goto V_214;
V_200 = F_154 () ;
if ( V_200 )
goto V_214;
V_200 = F_165 () ;
if ( V_200 )
goto V_214;
if ( V_215 )
F_179 () ;
if ( V_78 > 0 ) {
V_195 = ( F_188 () + 3 ) / 4 ;
V_196 = F_196 ( V_195 , sizeof( * V_196 ) ,
V_180 ) ;
if ( ! V_196 ) {
F_189 ( L_78 ) ;
V_200 = - V_181 ;
goto V_214;
}
for ( V_21 = 0 ; V_21 < V_195 ; V_21 ++ ) {
V_200 = F_155 ( F_94 ,
NULL ,
V_196 [ V_21 ] ) ;
if ( V_200 )
goto V_214;
}
}
F_172 () ;
F_187 () ;
return 0 ;
V_214:
F_187 () ;
F_171 () ;
return V_200 ;
}
