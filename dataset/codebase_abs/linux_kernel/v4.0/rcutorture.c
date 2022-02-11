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
unsigned long V_86 ;
bool V_87 = V_88 , V_89 = V_90 , V_91 = V_92 ;
bool V_93 = V_94 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_102 ( rand ) ;
int V_95 [] = { V_96 , V_97 ,
V_98 , V_99 } ;
int V_100 = 0 ;
F_79 ( L_13 ) ;
if ( ! V_87 && ! V_89 && ! V_91 && ! V_94 )
V_87 = V_89 = V_91 = V_93 = true ;
if ( V_87 && V_31 -> V_101 && V_31 -> V_102 )
V_95 [ V_100 ++ ] = V_98 ;
else if ( V_88 && ( ! V_31 -> V_101 || ! V_31 -> V_102 ) )
F_60 ( L_14 ) ;
if ( V_89 && V_31 -> V_103 )
V_95 [ V_100 ++ ] = V_97 ;
else if ( V_90 && ! V_31 -> V_103 )
F_60 ( L_15 ) ;
if ( V_91 && V_31 -> V_32 )
V_95 [ V_100 ++ ] = V_96 ;
else if ( V_92 && ! V_31 -> V_32 )
F_60 ( L_16 ) ;
if ( V_93 && V_31 -> V_104 )
V_95 [ V_100 ++ ] = V_99 ;
else if ( V_94 && ! V_31 -> V_104 )
F_60 ( L_17 ) ;
if ( F_103 ( V_100 == 0 ,
L_18 ) ) {
V_105 = V_106 ;
F_92 ( L_19 ) ;
}
do {
V_105 = V_107 ;
F_89 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_105 = V_108 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_105 = V_109 ;
V_26 = F_104 ( V_110 ,
V_59 == V_111 ) ;
V_20 -> V_25 = 1 ;
F_105 ( V_110 , V_20 ) ;
F_106 () ;
if ( V_26 ) {
V_21 = V_26 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
V_26 -> V_22 ++ ;
switch ( V_95 [ F_16 ( & rand ) % V_100 ] ) {
case V_96 :
V_105 = V_96 ;
V_31 -> V_32 ( V_26 ) ;
break;
case V_97 :
V_105 = V_97 ;
V_31 -> V_103 () ;
F_25 ( V_26 ) ;
break;
case V_98 :
V_105 = V_98 ;
V_86 = V_31 -> V_101 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_48 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_105 = V_112 ;
V_31 -> V_102 ( V_86 ) ;
F_25 ( V_26 ) ;
break;
case V_99 :
V_105 = V_99 ;
V_31 -> V_104 () ;
F_25 ( V_26 ) ;
break;
default:
F_107 ( 1 ) ;
break;
}
}
F_108 ( ++ V_113 ) ;
V_105 = V_114 ;
F_83 ( L_19 ) ;
} while ( ! F_84 () );
V_105 = V_106 ;
F_92 ( L_19 ) ;
return 0 ;
}
static int
F_109 ( void * V_51 )
{
F_102 ( rand ) ;
F_79 ( L_20 ) ;
F_110 ( V_59 , V_115 ) ;
do {
F_89 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_31 -> V_77 != NULL &&
F_16 ( & rand ) % ( V_116 * 8 ) == 0 ) {
V_31 -> V_77 () ;
} else if ( V_92 == V_90 ) {
if ( F_16 ( & rand ) & 0x80 )
V_31 -> V_104 () ;
else
V_31 -> V_103 () ;
} else if ( V_92 ) {
V_31 -> V_104 () ;
} else {
V_31 -> V_103 () ;
}
F_83 ( L_21 ) ;
} while ( ! F_84 () );
F_92 ( L_21 ) ;
return 0 ;
}
static void F_111 ( void )
{
static T_6 V_117 = F_112 ( 0 ) ;
if ( F_113 ( & V_117 ) )
return;
if ( F_114 ( & V_117 , 1 ) != 0 )
return;
F_115 ( V_118 ) ;
}
static void F_116 ( unsigned long V_119 )
{
int V_19 ;
unsigned long V_120 ;
unsigned long V_41 ;
static F_102 ( rand ) ;
static F_117 ( V_121 ) ;
struct V_4 * V_6 ;
int V_122 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_123 () ;
if ( V_31 -> V_120 )
V_120 = V_31 -> V_120 () ;
else
V_120 = V_31 -> V_41 () ;
V_1 = F_1 () ;
V_6 = F_104 ( V_110 ,
F_118 () ||
F_119 () ||
F_120 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_124 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_125 ) ;
F_121 ( & V_121 ) ;
V_31 -> V_126 ( & rand ) ;
V_127 ++ ;
F_122 ( & V_121 ) ;
F_67 () ;
V_122 = V_6 -> V_22 ;
if ( V_122 > V_23 ) {
V_122 = V_23 ;
}
V_41 = V_31 -> V_41 () ;
if ( V_122 > 1 ) {
F_123 ( V_31 -> V_128 , & V_6 -> V_30 , V_1 ,
V_120 , V_41 ) ;
F_111 () ;
}
F_124 ( V_129 [ V_122 ] ) ;
V_41 = V_41 - V_120 ;
if ( V_31 -> V_120 )
V_41 ++ ;
if ( V_41 > V_23 ) {
V_41 = V_23 ;
}
F_124 ( V_130 [ V_41 ] ) ;
F_69 () ;
V_31 -> V_124 ( V_19 ) ;
}
static int
F_125 ( void * V_51 )
{
unsigned long V_120 ;
unsigned long V_41 ;
int V_19 ;
F_102 ( rand ) ;
struct V_4 * V_6 ;
int V_122 ;
struct V_131 V_132 ;
unsigned long long V_1 ;
F_79 ( L_22 ) ;
F_110 ( V_59 , V_115 ) ;
if ( V_133 && V_31 -> V_134 )
F_126 ( & V_132 , F_116 , 0 ) ;
do {
if ( V_133 && V_31 -> V_134 ) {
if ( ! F_127 ( & V_132 ) )
F_128 ( & V_132 , V_63 + 1 ) ;
}
V_19 = V_31 -> V_123 () ;
if ( V_31 -> V_120 )
V_120 = V_31 -> V_120 () ;
else
V_120 = V_31 -> V_41 () ;
V_1 = F_1 () ;
V_6 = F_104 ( V_110 ,
F_118 () ||
F_119 () ||
F_120 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_124 ( V_19 ) ;
F_48 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_125 ) ;
V_31 -> V_126 ( & rand ) ;
F_67 () ;
V_122 = V_6 -> V_22 ;
if ( V_122 > V_23 ) {
V_122 = V_23 ;
}
V_41 = V_31 -> V_41 () ;
if ( V_122 > 1 ) {
F_123 ( V_31 -> V_128 , & V_6 -> V_30 ,
V_1 , V_120 , V_41 ) ;
F_111 () ;
}
F_124 ( V_129 [ V_122 ] ) ;
V_41 = V_41 - V_120 ;
if ( V_31 -> V_120 )
V_41 ++ ;
if ( V_41 > V_23 ) {
V_41 = V_23 ;
}
F_124 ( V_130 [ V_41 ] ) ;
F_69 () ;
V_31 -> V_124 ( V_19 ) ;
F_85 () ;
F_83 ( L_23 ) ;
} while ( ! F_84 () );
if ( V_133 && V_31 -> V_134 ) {
F_129 ( & V_132 ) ;
F_130 ( & V_132 ) ;
}
F_92 ( L_23 ) ;
return 0 ;
}
static void
F_131 ( void )
{
int V_40 ;
int V_21 ;
long V_135 [ V_23 + 1 ] = { 0 } ;
long V_136 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_137 = V_138 ;
F_61 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_135 [ V_21 ] += F_132 ( V_129 , V_40 ) [ V_21 ] ;
V_136 [ V_21 ] += F_132 ( V_130 , V_40 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_135 [ V_21 ] != 0 )
break;
}
F_60 ( L_24 , V_42 , V_43 ) ;
F_63 ( L_25 ,
V_110 ,
V_113 ,
F_6 ( & V_8 ) ,
F_113 ( & V_10 ) ,
F_113 ( & V_9 ) ,
F_113 ( & V_13 ) ) ;
F_63 ( L_26 ,
F_113 ( & V_125 ) ,
V_139 ,
V_61 ) ;
F_63 ( L_27 ,
V_66 ,
V_69 ,
V_127 ) ;
F_133 () ;
F_63 ( L_28 ,
V_140 ,
V_141 ,
V_142 ) ;
F_63 ( L_29 , F_134 ( & V_79 ) ) ;
F_60 ( L_24 , V_42 , V_43 ) ;
if ( F_113 ( & V_125 ) != 0 ||
V_142 != 0 ||
V_139 != 0 ||
V_61 != 0 ||
V_66 != 0 ||
V_21 > 1 ) {
F_63 ( L_30 , L_31 ) ;
F_7 ( & V_143 ) ;
F_107 ( 1 ) ;
}
F_63 ( L_32 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_63 ( L_33 , V_135 [ V_21 ] ) ;
F_63 ( L_3 ) ;
F_60 ( L_24 , V_42 , V_43 ) ;
F_63 ( L_34 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_63 ( L_33 , V_136 [ V_21 ] ) ;
F_63 ( L_3 ) ;
F_60 ( L_24 , V_42 , V_43 ) ;
F_63 ( L_35 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_63 ( L_36 , F_113 ( & V_24 [ V_21 ] ) ) ;
}
F_63 ( L_3 ) ;
if ( V_31 -> V_144 )
V_31 -> V_144 () ;
if ( V_137 == V_113 &&
V_110 != NULL ) {
int T_3 V_145 ;
unsigned long T_3 V_146 ;
unsigned long T_3 V_41 ;
F_135 ( V_31 -> V_147 ,
& V_145 , & V_146 , & V_41 ) ;
F_60 ( L_37 ,
V_105 ,
V_146 , V_41 , V_145 ) ;
F_136 () ;
F_111 () ;
}
V_137 = V_113 ;
}
static int
F_137 ( void * V_51 )
{
F_79 ( L_38 ) ;
do {
F_48 ( V_148 * V_37 ) ;
F_131 () ;
F_90 ( L_39 ) ;
} while ( ! F_84 () );
F_92 ( L_39 ) ;
return 0 ;
}
static inline void
F_138 ( struct V_149 * V_31 , const char * V_150 )
{
F_60 ( L_30 V_43
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48 ,
V_42 , V_150 , V_18 , V_116 ,
V_148 , V_151 , V_152 , V_153 ,
V_154 , V_133 , V_83 , V_85 , V_82 ,
V_155 , V_31 -> V_156 ,
V_68 , V_65 , V_157 ,
V_158 , V_159 ,
V_160 ,
V_161 , V_162 ) ;
}
static void F_139 ( int V_40 )
{
struct V_163 * V_132 ;
if ( V_164 [ V_40 ] == NULL )
return;
F_140 ( & V_67 ) ;
V_132 = V_164 [ V_40 ] ;
V_164 [ V_40 ] = NULL ;
F_88 ( & V_67 ) ;
F_141 ( F_78 , V_132 ) ;
}
static int F_142 ( int V_40 )
{
int V_165 ;
if ( V_164 [ V_40 ] != NULL )
return 0 ;
F_140 ( & V_67 ) ;
F_79 ( L_49 ) ;
V_164 [ V_40 ] = F_143 ( F_78 , NULL ,
F_144 ( V_40 ) ,
L_6 ) ;
if ( F_145 ( V_164 [ V_40 ] ) ) {
V_165 = F_146 ( V_164 [ V_40 ] ) ;
F_79 ( L_50 ) ;
V_139 ++ ;
V_164 [ V_40 ] = NULL ;
F_88 ( & V_67 ) ;
return V_165 ;
}
F_147 ( V_164 [ V_40 ] , V_40 ) ;
F_148 ( V_164 [ V_40 ] ) ;
F_88 ( & V_67 ) ;
return 0 ;
}
static int F_149 ( void * args )
{
unsigned long V_166 ;
F_79 ( L_51 ) ;
if ( V_159 > 0 ) {
F_79 ( L_52 ) ;
F_48 ( V_159 * V_37 ) ;
F_79 ( L_53 ) ;
}
if ( ! F_86 () ) {
V_166 = F_150 () + V_158 ;
F_60 ( L_54 ) ;
F_14 () ;
F_67 () ;
while ( F_82 ( F_150 () , V_166 ) )
continue;
F_69 () ;
F_23 () ;
F_60 ( L_55 ) ;
}
F_90 ( L_56 ) ;
while ( ! F_86 () )
F_48 ( 10 * V_37 ) ;
return 0 ;
}
static int T_7 F_151 ( void )
{
if ( V_158 <= 0 )
return 0 ;
return F_152 ( F_149 , NULL , V_167 ) ;
}
static void F_153 ( struct V_29 * V_34 )
{
F_7 ( & V_168 ) ;
}
static int F_154 ( void * V_51 )
{
long V_169 = ( long ) V_51 ;
bool V_170 = 0 ;
bool V_171 ;
struct V_29 V_34 ;
F_81 ( & V_34 ) ;
F_79 ( L_57 ) ;
F_110 ( V_59 , V_115 ) ;
do {
F_155 ( V_172 [ V_169 ] ,
( V_171 =
F_156 ( V_173 ) ) != V_170 ||
F_84 () ) ;
V_170 = V_171 ;
F_77 () ;
if ( F_84 () )
break;
V_31 -> V_76 ( & V_34 , F_153 ) ;
if ( F_157 ( & V_174 ) )
F_158 ( & V_175 ) ;
} while ( ! F_84 () );
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
F_91 ( & V_34 ) ;
F_92 ( L_58 ) ;
return 0 ;
}
static int F_159 ( void * V_51 )
{
int V_21 ;
F_79 ( L_59 ) ;
do {
F_160 ( & V_168 , 0 ) ;
F_160 ( & V_174 , V_160 ) ;
F_77 () ;
V_173 = ! V_173 ;
for ( V_21 = 0 ; V_21 < V_160 ; V_21 ++ )
F_158 ( & V_172 [ V_21 ] ) ;
F_155 ( V_175 ,
F_113 ( & V_174 ) == 0 ||
F_84 () ) ;
if ( F_84 () )
break;
V_141 ++ ;
V_31 -> V_77 () ;
if ( F_113 ( & V_168 ) != V_160 ) {
V_142 ++ ;
F_161 ( L_60 ,
F_113 ( & V_168 ) ,
V_160 ) ;
F_107 ( 1 ) ;
}
V_140 ++ ;
F_48 ( V_37 / 10 ) ;
} while ( ! F_84 () );
F_92 ( L_61 ) ;
return 0 ;
}
static int F_162 ( void )
{
int V_21 ;
int V_176 ;
if ( V_160 == 0 )
return 0 ;
if ( V_31 -> V_76 == NULL || V_31 -> V_77 == NULL ) {
F_60 ( L_30 V_43
L_62 ,
V_42 , V_31 -> V_128 ) ;
F_60 ( L_30 V_43
L_63 ,
V_42 ) ;
return 0 ;
}
F_160 ( & V_174 , 0 ) ;
F_160 ( & V_168 , 0 ) ;
V_177 =
F_163 ( V_160 * sizeof( V_177 [ 0 ] ) ,
V_178 ) ;
V_172 =
F_163 ( V_160 * sizeof( V_172 [ 0 ] ) ,
V_178 ) ;
if ( V_177 == NULL || ! V_172 )
return - V_179 ;
for ( V_21 = 0 ; V_21 < V_160 ; V_21 ++ ) {
F_164 ( & V_172 [ V_21 ] ) ;
V_176 = F_152 ( F_154 ,
( void * ) ( long ) V_21 ,
V_177 [ V_21 ] ) ;
if ( V_176 )
return V_176 ;
}
return F_152 ( F_159 , NULL , V_180 ) ;
}
static void F_165 ( void )
{
int V_21 ;
F_141 ( F_159 , V_180 ) ;
if ( V_177 != NULL ) {
for ( V_21 = 0 ; V_21 < V_160 ; V_21 ++ )
F_141 ( F_154 ,
V_177 [ V_21 ] ) ;
F_166 ( V_177 ) ;
V_177 = NULL ;
}
if ( V_172 != NULL ) {
F_166 ( V_172 ) ;
V_172 = NULL ;
}
}
static int F_167 ( struct V_181 * V_182 ,
unsigned long V_183 , void * V_184 )
{
long V_40 = ( long ) V_184 ;
switch ( V_183 ) {
case V_185 :
case V_186 :
( void ) F_142 ( V_40 ) ;
break;
case V_187 :
F_139 ( V_40 ) ;
break;
default:
break;
}
return V_188 ;
}
static void
F_168 ( void )
{
int V_21 ;
F_169 () ;
if ( F_170 () ) {
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
return;
}
F_165 () ;
F_141 ( F_149 , V_167 ) ;
F_141 ( F_101 , V_111 ) ;
if ( V_189 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_141 ( F_125 ,
V_189 [ V_21 ] ) ;
F_166 ( V_189 ) ;
}
V_110 = NULL ;
if ( V_190 ) {
for ( V_21 = 0 ; V_21 < V_116 ; V_21 ++ ) {
F_141 ( F_109 ,
V_190 [ V_21 ] ) ;
}
F_166 ( V_190 ) ;
V_190 = NULL ;
}
F_141 ( F_137 , V_191 ) ;
F_141 ( F_100 , V_192 ) ;
for ( V_21 = 0 ; V_21 < V_193 ; V_21 ++ )
F_141 ( F_94 , V_194 [ V_21 ] ) ;
if ( ( V_155 == 1 && V_31 -> V_156 ) ||
V_155 == 2 ) {
F_171 ( & V_195 ) ;
F_61 (i)
F_139 ( V_21 ) ;
}
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
F_131 () ;
if ( F_113 ( & V_143 ) || V_142 )
F_138 ( V_31 , L_64 ) ;
else if ( F_172 () )
F_138 ( V_31 ,
L_65 ) ;
else
F_138 ( V_31 , L_66 ) ;
F_173 () ;
}
static void F_174 ( struct V_29 * V_70 )
{
}
static void F_175 ( struct V_29 * V_70 )
{
F_60 ( L_67 ) ;
}
static void F_176 ( void )
{
#ifdef F_177
struct V_29 V_196 ;
struct V_29 V_197 ;
F_81 ( & V_196 ) ;
F_81 ( & V_197 ) ;
F_60 ( L_68 ) ;
F_67 () ;
F_14 () ;
F_33 ( & V_196 , F_174 ) ;
F_178 () ;
F_33 ( & V_197 , F_174 ) ;
F_33 ( & V_197 , F_175 ) ;
F_179 () ;
F_23 () ;
F_69 () ;
F_180 () ;
F_60 ( L_69 ) ;
F_91 ( & V_196 ) ;
F_91 ( & V_197 ) ;
#else
F_60 ( L_70 ) ;
#endif
}
static int T_7
F_181 ( void )
{
int V_21 ;
int V_40 ;
int V_198 = 0 ;
static struct V_149 * V_199 [] = {
& V_200 , & V_201 , & V_202 , & V_203 , & V_204 ,
V_205
} ;
if ( ! F_182 ( V_42 , V_151 , & V_206 ) )
return - V_207 ;
for ( V_21 = 0 ; V_21 < F_183 ( V_199 ) ; V_21 ++ ) {
V_31 = V_199 [ V_21 ] ;
if ( strcmp ( V_42 , V_31 -> V_128 ) == 0 )
break;
}
if ( V_21 == F_183 ( V_199 ) ) {
F_60 ( L_71 ,
V_42 ) ;
F_60 ( L_72 ) ;
for ( V_21 = 0 ; V_21 < F_183 ( V_199 ) ; V_21 ++ )
F_60 ( L_73 , V_199 [ V_21 ] -> V_128 ) ;
F_60 ( L_3 ) ;
F_184 () ;
return - V_208 ;
}
if ( V_31 -> V_84 == NULL && V_83 != 0 ) {
F_60 ( L_74 ) ;
V_83 = 0 ;
}
if ( V_31 -> V_209 )
V_31 -> V_209 () ;
if ( V_210 >= 0 ) {
V_18 = V_210 ;
} else {
V_18 = F_185 () - 1 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_138 ( V_31 , L_75 ) ;
F_35 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_183 ( V_211 ) ; V_21 ++ ) {
V_211 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_211 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_110 = NULL ;
V_113 = 0 ;
F_160 ( & V_10 , 0 ) ;
F_160 ( & V_9 , 0 ) ;
F_160 ( & V_13 , 0 ) ;
F_160 ( & V_125 , 0 ) ;
F_160 ( & V_143 , 0 ) ;
V_142 = 0 ;
V_139 = 0 ;
V_61 = 0 ;
V_66 = 0 ;
V_69 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_160 ( & V_24 [ V_21 ] , 0 ) ;
F_61 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_132 ( V_129 , V_40 ) [ V_21 ] = 0 ;
F_132 ( V_130 , V_40 ) [ V_21 ] = 0 ;
}
}
V_198 = F_152 ( F_101 , NULL ,
V_111 ) ;
if ( V_198 )
goto V_212;
V_190 = F_163 ( V_116 * sizeof( V_190 [ 0 ] ) ,
V_178 ) ;
if ( V_190 == NULL ) {
F_186 ( L_76 ) ;
V_198 = - V_179 ;
goto V_212;
}
for ( V_21 = 0 ; V_21 < V_116 ; V_21 ++ ) {
V_198 = F_152 ( F_109 ,
NULL , V_190 [ V_21 ] ) ;
if ( V_198 )
goto V_212;
}
V_189 = F_163 ( V_18 * sizeof( V_189 [ 0 ] ) ,
V_178 ) ;
if ( V_189 == NULL ) {
F_186 ( L_76 ) ;
V_198 = - V_179 ;
goto V_212;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_198 = F_152 ( F_125 , NULL ,
V_189 [ V_21 ] ) ;
if ( V_198 )
goto V_212;
}
if ( V_148 > 0 ) {
V_198 = F_152 ( F_137 , NULL ,
V_191 ) ;
if ( V_198 )
goto V_212;
}
if ( V_152 ) {
V_198 = F_187 ( V_153 * V_37 ) ;
if ( V_198 )
goto V_212;
}
if ( V_154 < 0 )
V_154 = 0 ;
if ( V_154 ) {
V_198 = F_188 ( V_154 * V_37 ) ;
if ( V_198 )
goto V_212;
}
if ( V_83 < 0 )
V_83 = 0 ;
if ( V_83 ) {
V_198 = F_152 ( F_100 , NULL ,
V_192 ) ;
if ( V_198 )
goto V_212;
}
if ( V_68 < 1 )
V_68 = 1 ;
if ( V_65 < 2 )
V_65 = 2 ;
if ( ( V_155 == 1 && V_31 -> V_156 ) ||
V_155 == 2 ) {
V_62 = V_63 + V_68 * V_37 ;
F_189 ( & V_195 ) ;
F_61 (i) {
if ( F_190 ( V_21 ) )
continue;
V_198 = F_142 ( V_21 ) ;
if ( V_198 )
goto V_212;
}
}
V_198 = F_191 ( V_157 , F_168 ) ;
if ( V_198 )
goto V_212;
V_198 = F_192 ( V_162 * V_37 , V_161 * V_37 ) ;
if ( V_198 )
goto V_212;
V_198 = F_151 () ;
if ( V_198 )
goto V_212;
V_198 = F_162 () ;
if ( V_198 )
goto V_212;
if ( V_213 )
F_176 () ;
if ( V_78 > 0 ) {
V_193 = ( F_185 () + 3 ) / 4 ;
V_194 = F_193 ( V_193 , sizeof( * V_194 ) ,
V_178 ) ;
if ( ! V_194 ) {
F_186 ( L_76 ) ;
V_198 = - V_179 ;
goto V_212;
}
for ( V_21 = 0 ; V_21 < V_193 ; V_21 ++ ) {
V_198 = F_152 ( F_94 ,
NULL ,
V_194 [ V_21 ] ) ;
if ( V_198 )
goto V_212;
}
}
F_169 () ;
F_184 () ;
return 0 ;
V_212:
F_184 () ;
F_168 () ;
return V_198 ;
}
