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
static int F_24 ( void )
{
return F_25 () ;
}
static bool
F_26 ( struct V_4 * V_20 )
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
F_27 ( struct V_4 * V_26 )
{
struct V_4 * V_20 ;
struct V_4 * V_27 ;
if ( V_26 )
F_28 ( & V_26 -> V_12 , & V_28 ) ;
F_29 (rp, rp1, &rcu_torture_removed, rtort_free) {
if ( F_26 ( V_20 ) ) {
F_30 ( & V_20 -> V_12 ) ;
F_11 ( V_20 ) ;
}
}
}
static void
F_31 ( struct V_29 * V_6 )
{
struct V_4 * V_20 = F_10 ( V_6 , struct V_4 , V_30 ) ;
if ( F_32 () ) {
return;
}
if ( F_26 ( V_20 ) )
F_11 ( V_20 ) ;
else
V_31 -> V_32 ( V_20 ) ;
}
static int F_33 ( void )
{
return 0 ;
}
static void F_34 ( struct V_4 * V_6 )
{
F_35 ( & V_6 -> V_30 , F_31 ) ;
}
static void F_36 ( void )
{
F_37 ( & V_28 ) ;
}
static int F_38 ( void ) __acquires( T_5 )
{
F_39 () ;
return 0 ;
}
static void F_40 ( int V_19 ) __releases( T_5 )
{
F_41 () ;
}
static int F_42 ( void )
{
return F_43 () ;
}
static void F_44 ( struct V_4 * V_6 )
{
F_45 ( & V_6 -> V_30 , F_31 ) ;
}
static void F_46 ( struct V_4 * V_6 )
{
F_31 ( & V_6 -> V_30 ) ;
}
static void F_47 ( void )
{
}
static void
F_48 ( struct V_29 * V_33 , void (* F_49)( struct V_29 * V_34 ) )
{
F_49 ( V_33 ) ;
}
static int F_50 ( void ) __acquires( &srcu_ctl
static void F_51 ( struct V_14 * V_15 )
{
long V_35 ;
const long V_36 = 1000000 / V_37 ;
const long V_38 = 10 ;
V_35 = F_16 ( V_15 ) %
( V_18 * 2 * V_38 * V_36 ) ;
if ( ! V_35 )
F_52 ( V_38 ) ;
else
F_15 ( V_15 ) ;
}
static void F_53 ( int V_19 ) __releases( &srcu_ctl
static int F_54 ( void )
{
return F_55 ( & V_39 ) ;
}
static void F_56 ( struct V_4 * V_20 )
{
F_57 ( & V_39 , & V_20 -> V_30 , F_31 ) ;
}
static void F_58 ( void )
{
F_59 ( & V_39 ) ;
}
static void F_60 ( struct V_29 * V_33 ,
void (* F_49)( struct V_29 * V_33 ) )
{
F_57 ( & V_39 , V_33 , F_49 ) ;
}
static void F_61 ( void )
{
F_62 ( & V_39 ) ;
}
static void F_63 ( void )
{
int V_40 ;
int V_19 = V_39 . V_41 & 0x1 ;
F_64 ( L_1 ,
V_42 , V_43 , V_19 ) ;
F_65 (cpu) {
long V_44 , V_45 ;
V_44 = ( long ) F_66 ( V_39 . V_46 , V_40 ) -> V_47 [ ! V_19 ] ;
V_45 = ( long ) F_66 ( V_39 . V_46 , V_40 ) -> V_47 [ V_19 ] ;
F_67 ( L_2 , V_40 , V_44 , V_45 ) ;
}
F_67 ( L_3 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_39 ) ;
}
static int F_70 ( void )
{
F_71 () ;
return 0 ;
}
static void F_72 ( int V_19 )
{
F_73 () ;
}
static void F_74 ( struct V_4 * V_6 )
{
F_75 ( & V_6 -> V_30 , F_31 ) ;
}
static int F_76 ( void )
{
return 0 ;
}
static void F_77 ( int V_19 )
{
}
static void F_78 ( struct V_4 * V_6 )
{
F_79 ( & V_6 -> V_30 , F_31 ) ;
}
static void F_80 ( struct V_29 * V_33 )
{
struct V_48 * V_49 =
F_10 ( V_33 , struct V_48 , V_34 ) ;
F_81 () ;
V_49 -> V_50 = 0 ;
}
static int F_82 ( void * V_51 )
{
unsigned long V_52 ;
unsigned long V_53 ;
unsigned long V_54 ;
struct V_48 V_55 = { . V_50 = 0 } ;
struct V_56 V_57 ;
F_83 ( L_4 ) ;
V_57 . V_58 = 1 ;
if ( F_84 ( V_59 , V_60 , & V_57 ) < 0 ) {
F_83 ( L_5 ) ;
V_61 ++ ;
}
F_85 ( & V_55 . V_34 ) ;
do {
V_54 = V_62 ;
while ( F_86 ( V_63 , V_54 ) ) {
F_52 ( V_54 - V_63 ) ;
F_87 ( L_6 ) ;
if ( F_88 () )
goto V_64;
}
V_53 = V_54 + V_65 * V_37 ;
V_52 = V_63 ;
while ( F_86 ( V_63 , V_53 ) ) {
if ( ! V_55 . V_50 ) {
F_81 () ;
V_55 . V_50 = 1 ;
F_35 ( & V_55 . V_34 , F_80 ) ;
if ( V_63 - V_52 >
V_65 * V_37 - V_37 / 2 ) {
F_83 ( L_7 ) ;
V_66 ++ ;
}
V_52 = V_63 ;
}
F_89 () ;
F_87 ( L_6 ) ;
if ( F_88 () )
goto V_64;
}
while ( V_54 == V_62 &&
! F_90 () ) {
if ( F_91 ( & V_67 ) ) {
V_62 = V_63 +
V_68 * V_37 ;
V_69 ++ ;
F_92 ( & V_67 ) ;
break;
}
F_93 ( 1 ) ;
}
V_64: F_87 ( L_6 ) ;
} while ( ! F_88 () );
while ( ! F_90 () || V_55 . V_50 ) {
F_94 ( L_6 ) ;
F_93 ( 1 ) ;
}
F_81 () ;
F_95 ( & V_55 . V_34 ) ;
F_96 ( L_6 ) ;
return 0 ;
}
static void F_97 ( struct V_29 * V_70 )
{
}
static int
F_98 ( void * V_51 )
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
V_70 = F_99 ( sizeof( * V_70 ) *
V_78 * V_73 ) ;
V_71 = ! V_70 ;
}
if ( V_71 ) {
F_83 ( L_8 ) ;
while ( ! F_88 () )
F_52 ( V_37 ) ;
return 0 ;
}
F_83 ( L_9 ) ;
do {
F_52 ( V_74 ) ;
F_100 ( & V_79 ) ;
F_101 ( F_102 ( V_59 ) ) ;
for ( V_21 = 0 ; V_21 < V_78 ; V_21 ++ ) {
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
V_31 -> V_76 ( & V_70 [ V_21 * V_73 + V_72 ] ,
F_97 ) ;
}
F_52 ( V_75 ) ;
F_101 ( F_102 ( V_59 ) ) ;
}
V_31 -> V_77 () ;
F_87 ( L_10 ) ;
} while ( ! F_88 () );
F_96 ( L_10 ) ;
return 0 ;
}
static int
F_103 ( void * V_51 )
{
unsigned long V_80 ;
int V_81 ;
F_83 ( L_11 ) ;
do {
V_80 = V_63 + V_82 * V_37 ;
while ( F_86 ( V_63 , V_80 ) &&
! F_90 () ) {
F_52 ( 1 ) ;
}
V_81 = V_83 ;
while ( V_81 > 0 &&
! F_90 () ) {
V_31 -> V_84 () ;
F_18 ( V_85 ) ;
V_81 -= V_85 ;
}
F_87 ( L_12 ) ;
} while ( ! F_88 () );
F_96 ( L_12 ) ;
return 0 ;
}
static int
F_104 ( void * V_51 )
{
unsigned long V_86 ;
bool V_87 = V_88 , V_89 = V_90 , V_91 = V_92 ;
bool V_93 = V_94 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_105 ( rand ) ;
int V_95 [] = { V_96 , V_97 ,
V_98 , V_99 } ;
int V_100 = 0 ;
F_83 ( L_13 ) ;
if ( ! V_87 && ! V_89 && ! V_91 && ! V_94 )
V_87 = V_89 = V_91 = V_93 = true ;
if ( V_87 && V_31 -> V_101 && V_31 -> V_102 )
V_95 [ V_100 ++ ] = V_98 ;
else if ( V_88 && ( ! V_31 -> V_101 || ! V_31 -> V_102 ) )
F_64 ( L_14 ) ;
if ( V_89 && V_31 -> V_103 )
V_95 [ V_100 ++ ] = V_97 ;
else if ( V_90 && ! V_31 -> V_103 )
F_64 ( L_15 ) ;
if ( V_91 && V_31 -> V_32 )
V_95 [ V_100 ++ ] = V_96 ;
else if ( V_92 && ! V_31 -> V_32 )
F_64 ( L_16 ) ;
if ( V_93 && V_31 -> V_104 )
V_95 [ V_100 ++ ] = V_99 ;
else if ( V_94 && ! V_31 -> V_104 )
F_64 ( L_17 ) ;
if ( F_106 ( V_100 == 0 ,
L_18 ) ) {
V_105 = V_106 ;
F_96 ( L_19 ) ;
}
do {
V_105 = V_107 ;
F_93 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_105 = V_108 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_105 = V_109 ;
V_26 = F_107 ( V_110 ,
V_59 == V_111 ) ;
V_20 -> V_25 = 1 ;
F_108 ( V_110 , V_20 ) ;
F_109 () ;
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
F_27 ( V_26 ) ;
break;
case V_98 :
V_105 = V_98 ;
V_86 = V_31 -> V_101 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_52 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_105 = V_112 ;
V_31 -> V_102 ( V_86 ) ;
F_27 ( V_26 ) ;
break;
case V_99 :
V_105 = V_99 ;
V_31 -> V_104 () ;
F_27 ( V_26 ) ;
break;
default:
F_110 ( 1 ) ;
break;
}
}
F_111 ( ++ V_113 ) ;
V_105 = V_114 ;
F_87 ( L_19 ) ;
} while ( ! F_88 () );
V_105 = V_106 ;
F_96 ( L_19 ) ;
return 0 ;
}
static int
F_112 ( void * V_51 )
{
F_105 ( rand ) ;
F_83 ( L_20 ) ;
F_113 ( V_59 , V_115 ) ;
do {
F_93 ( 1 + F_16 ( & rand ) % 10 ) ;
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
F_87 ( L_21 ) ;
} while ( ! F_88 () );
F_96 ( L_21 ) ;
return 0 ;
}
static void F_114 ( void )
{
static T_6 V_117 = F_115 ( 0 ) ;
if ( F_116 ( & V_117 ) )
return;
if ( F_117 ( & V_117 , 1 ) != 0 )
return;
F_118 ( V_118 ) ;
}
static void F_119 ( unsigned long V_119 )
{
int V_19 ;
int V_41 ;
int V_120 ;
static F_105 ( rand ) ;
static F_120 ( V_121 ) ;
struct V_4 * V_6 ;
int V_122 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_123 () ;
V_41 = V_31 -> V_41 () ;
V_1 = F_1 () ;
V_6 = F_107 ( V_110 ,
F_121 () ||
F_122 () ||
F_123 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_124 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_125 ) ;
F_124 ( & V_121 ) ;
V_31 -> V_126 ( & rand ) ;
V_127 ++ ;
F_125 ( & V_121 ) ;
F_71 () ;
V_122 = V_6 -> V_22 ;
if ( V_122 > V_23 ) {
V_122 = V_23 ;
}
V_120 = V_31 -> V_41 () ;
if ( V_122 > 1 ) {
F_126 ( V_31 -> V_128 , & V_6 -> V_30 , V_1 ,
V_41 , V_120 ) ;
F_114 () ;
}
F_127 ( V_129 [ V_122 ] ) ;
V_41 = V_120 - V_41 ;
if ( V_41 > V_23 ) {
V_41 = V_23 ;
}
F_127 ( V_130 [ V_41 ] ) ;
F_73 () ;
V_31 -> V_124 ( V_19 ) ;
}
static int
F_128 ( void * V_51 )
{
int V_41 ;
int V_120 ;
int V_19 ;
F_105 ( rand ) ;
struct V_4 * V_6 ;
int V_122 ;
struct V_131 V_132 ;
unsigned long long V_1 ;
F_83 ( L_22 ) ;
F_113 ( V_59 , V_115 ) ;
if ( V_133 && V_31 -> V_134 )
F_129 ( & V_132 , F_119 , 0 ) ;
do {
if ( V_133 && V_31 -> V_134 ) {
if ( ! F_130 ( & V_132 ) )
F_131 ( & V_132 , V_63 + 1 ) ;
}
V_19 = V_31 -> V_123 () ;
V_41 = V_31 -> V_41 () ;
V_1 = F_1 () ;
V_6 = F_107 ( V_110 ,
F_121 () ||
F_122 () ||
F_123 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_124 ( V_19 ) ;
F_52 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_125 ) ;
V_31 -> V_126 ( & rand ) ;
F_71 () ;
V_122 = V_6 -> V_22 ;
if ( V_122 > V_23 ) {
V_122 = V_23 ;
}
V_120 = V_31 -> V_41 () ;
if ( V_122 > 1 ) {
F_126 ( V_31 -> V_128 , & V_6 -> V_30 ,
V_1 , V_41 , V_120 ) ;
F_114 () ;
}
F_127 ( V_129 [ V_122 ] ) ;
V_41 = V_120 - V_41 ;
if ( V_41 > V_23 ) {
V_41 = V_23 ;
}
F_127 ( V_130 [ V_41 ] ) ;
F_73 () ;
V_31 -> V_124 ( V_19 ) ;
F_89 () ;
F_87 ( L_23 ) ;
} while ( ! F_88 () );
if ( V_133 && V_31 -> V_134 ) {
F_132 ( & V_132 ) ;
F_133 ( & V_132 ) ;
}
F_96 ( L_23 ) ;
return 0 ;
}
static void
F_134 ( void )
{
int V_40 ;
int V_21 ;
long V_135 [ V_23 + 1 ] = { 0 } ;
long V_136 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_137 = V_138 ;
F_65 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_135 [ V_21 ] += F_135 ( V_129 , V_40 ) [ V_21 ] ;
V_136 [ V_21 ] += F_135 ( V_130 , V_40 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_135 [ V_21 ] != 0 )
break;
}
F_64 ( L_24 , V_42 , V_43 ) ;
F_67 ( L_25 ,
V_110 ,
V_113 ,
F_6 ( & V_8 ) ,
F_116 ( & V_10 ) ,
F_116 ( & V_9 ) ,
F_116 ( & V_13 ) ) ;
F_67 ( L_26 ,
F_116 ( & V_125 ) ,
V_139 ,
V_61 ) ;
F_67 ( L_27 ,
V_66 ,
V_69 ,
V_127 ) ;
F_136 () ;
F_67 ( L_28 ,
V_140 ,
V_141 ,
V_142 ) ;
F_67 ( L_29 , F_137 ( & V_79 ) ) ;
F_64 ( L_24 , V_42 , V_43 ) ;
if ( F_116 ( & V_125 ) != 0 ||
V_142 != 0 ||
V_139 != 0 ||
V_61 != 0 ||
V_66 != 0 ||
V_21 > 1 ) {
F_67 ( L_30 , L_31 ) ;
F_7 ( & V_143 ) ;
F_110 ( 1 ) ;
}
F_67 ( L_32 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_67 ( L_33 , V_135 [ V_21 ] ) ;
F_67 ( L_3 ) ;
F_64 ( L_24 , V_42 , V_43 ) ;
F_67 ( L_34 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_67 ( L_33 , V_136 [ V_21 ] ) ;
F_67 ( L_3 ) ;
F_64 ( L_24 , V_42 , V_43 ) ;
F_67 ( L_35 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_67 ( L_36 , F_116 ( & V_24 [ V_21 ] ) ) ;
}
F_67 ( L_3 ) ;
if ( V_31 -> V_144 )
V_31 -> V_144 () ;
if ( V_137 == V_113 &&
V_110 != NULL ) {
int T_3 V_145 ;
unsigned long T_3 V_146 ;
unsigned long T_3 V_41 ;
F_138 ( V_31 -> V_147 ,
& V_145 , & V_146 , & V_41 ) ;
F_64 ( L_37 ,
V_105 ,
V_146 , V_41 , V_145 ) ;
F_139 () ;
F_114 () ;
}
V_137 = V_113 ;
}
static int
F_140 ( void * V_51 )
{
F_83 ( L_38 ) ;
do {
F_52 ( V_148 * V_37 ) ;
F_134 () ;
F_94 ( L_39 ) ;
} while ( ! F_88 () );
F_96 ( L_39 ) ;
return 0 ;
}
static inline void
F_141 ( struct V_149 * V_31 , const char * V_150 )
{
F_64 ( L_30 V_43
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
static void F_142 ( int V_40 )
{
struct V_163 * V_132 ;
if ( V_164 [ V_40 ] == NULL )
return;
F_143 ( & V_67 ) ;
V_132 = V_164 [ V_40 ] ;
V_164 [ V_40 ] = NULL ;
F_92 ( & V_67 ) ;
F_144 ( F_82 , V_132 ) ;
}
static int F_145 ( int V_40 )
{
int V_165 ;
if ( V_164 [ V_40 ] != NULL )
return 0 ;
F_143 ( & V_67 ) ;
F_83 ( L_49 ) ;
V_164 [ V_40 ] = F_146 ( F_82 , NULL ,
F_147 ( V_40 ) ,
L_6 ) ;
if ( F_148 ( V_164 [ V_40 ] ) ) {
V_165 = F_149 ( V_164 [ V_40 ] ) ;
F_83 ( L_50 ) ;
V_139 ++ ;
V_164 [ V_40 ] = NULL ;
F_92 ( & V_67 ) ;
return V_165 ;
}
F_150 ( V_164 [ V_40 ] , V_40 ) ;
F_151 ( V_164 [ V_40 ] ) ;
F_92 ( & V_67 ) ;
return 0 ;
}
static int F_152 ( void * args )
{
unsigned long V_166 ;
F_83 ( L_51 ) ;
if ( V_159 > 0 ) {
F_83 ( L_52 ) ;
F_52 ( V_159 * V_37 ) ;
F_83 ( L_53 ) ;
}
if ( ! F_90 () ) {
V_166 = F_153 () + V_158 ;
F_64 ( L_54 ) ;
F_14 () ;
F_71 () ;
while ( F_86 ( F_153 () , V_166 ) )
continue;
F_73 () ;
F_23 () ;
F_64 ( L_55 ) ;
}
F_94 ( L_56 ) ;
while ( ! F_90 () )
F_52 ( 10 * V_37 ) ;
return 0 ;
}
static int T_7 F_154 ( void )
{
if ( V_158 <= 0 )
return 0 ;
return F_155 ( F_152 , NULL , V_167 ) ;
}
static void F_156 ( struct V_29 * V_34 )
{
F_7 ( & V_168 ) ;
}
static int F_157 ( void * V_51 )
{
long V_169 = ( long ) V_51 ;
bool V_170 = 0 ;
bool V_171 ;
struct V_29 V_34 ;
F_85 ( & V_34 ) ;
F_83 ( L_57 ) ;
F_113 ( V_59 , V_115 ) ;
do {
F_158 ( V_172 [ V_169 ] ,
( V_171 =
F_159 ( V_173 ) ) != V_170 ||
F_88 () ) ;
V_170 = V_171 ;
F_81 () ;
if ( F_88 () )
break;
V_31 -> V_76 ( & V_34 , F_156 ) ;
if ( F_160 ( & V_174 ) )
F_161 ( & V_175 ) ;
} while ( ! F_88 () );
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
F_95 ( & V_34 ) ;
F_96 ( L_58 ) ;
return 0 ;
}
static int F_162 ( void * V_51 )
{
int V_21 ;
F_83 ( L_59 ) ;
do {
F_163 ( & V_168 , 0 ) ;
F_163 ( & V_174 , V_160 ) ;
F_81 () ;
V_173 = ! V_173 ;
for ( V_21 = 0 ; V_21 < V_160 ; V_21 ++ )
F_161 ( & V_172 [ V_21 ] ) ;
F_158 ( V_175 ,
F_116 ( & V_174 ) == 0 ||
F_88 () ) ;
if ( F_88 () )
break;
V_141 ++ ;
V_31 -> V_77 () ;
if ( F_116 ( & V_168 ) != V_160 ) {
V_142 ++ ;
F_110 ( 1 ) ;
}
V_140 ++ ;
F_52 ( V_37 / 10 ) ;
} while ( ! F_88 () );
F_96 ( L_60 ) ;
return 0 ;
}
static int F_164 ( void )
{
int V_21 ;
int V_176 ;
if ( V_160 == 0 )
return 0 ;
if ( V_31 -> V_76 == NULL || V_31 -> V_77 == NULL ) {
F_64 ( L_30 V_43
L_61 ,
V_42 , V_31 -> V_128 ) ;
F_64 ( L_30 V_43
L_62 ,
V_42 ) ;
return 0 ;
}
F_163 ( & V_174 , 0 ) ;
F_163 ( & V_168 , 0 ) ;
V_177 =
F_165 ( V_160 * sizeof( V_177 [ 0 ] ) ,
V_178 ) ;
V_172 =
F_165 ( V_160 * sizeof( V_172 [ 0 ] ) ,
V_178 ) ;
if ( V_177 == NULL || ! V_172 )
return - V_179 ;
for ( V_21 = 0 ; V_21 < V_160 ; V_21 ++ ) {
F_166 ( & V_172 [ V_21 ] ) ;
V_176 = F_155 ( F_157 ,
( void * ) ( long ) V_21 ,
V_177 [ V_21 ] ) ;
if ( V_176 )
return V_176 ;
}
return F_155 ( F_162 , NULL , V_180 ) ;
}
static void F_167 ( void )
{
int V_21 ;
F_144 ( F_162 , V_180 ) ;
if ( V_177 != NULL ) {
for ( V_21 = 0 ; V_21 < V_160 ; V_21 ++ )
F_144 ( F_157 ,
V_177 [ V_21 ] ) ;
F_168 ( V_177 ) ;
V_177 = NULL ;
}
if ( V_172 != NULL ) {
F_168 ( V_172 ) ;
V_172 = NULL ;
}
}
static int F_169 ( struct V_181 * V_182 ,
unsigned long V_183 , void * V_184 )
{
long V_40 = ( long ) V_184 ;
switch ( V_183 ) {
case V_185 :
case V_186 :
( void ) F_145 ( V_40 ) ;
break;
case V_187 :
F_142 ( V_40 ) ;
break;
default:
break;
}
return V_188 ;
}
static void
F_170 ( void )
{
int V_21 ;
F_171 () ;
if ( F_172 () ) {
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
return;
}
F_167 () ;
F_144 ( F_152 , V_167 ) ;
F_144 ( F_104 , V_111 ) ;
if ( V_189 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_144 ( F_128 ,
V_189 [ V_21 ] ) ;
F_168 ( V_189 ) ;
}
V_110 = NULL ;
if ( V_190 ) {
for ( V_21 = 0 ; V_21 < V_116 ; V_21 ++ ) {
F_144 ( F_112 ,
V_190 [ V_21 ] ) ;
}
F_168 ( V_190 ) ;
V_190 = NULL ;
}
F_144 ( F_140 , V_191 ) ;
F_144 ( F_103 , V_192 ) ;
for ( V_21 = 0 ; V_21 < V_193 ; V_21 ++ )
F_144 ( F_98 , V_194 [ V_21 ] ) ;
if ( ( V_155 == 1 && V_31 -> V_156 ) ||
V_155 == 2 ) {
F_173 ( & V_195 ) ;
F_65 (i)
F_142 ( V_21 ) ;
}
if ( V_31 -> V_77 != NULL )
V_31 -> V_77 () ;
F_134 () ;
if ( F_116 ( & V_143 ) || V_142 )
F_141 ( V_31 , L_63 ) ;
else if ( F_174 () )
F_141 ( V_31 ,
L_64 ) ;
else
F_141 ( V_31 , L_65 ) ;
F_175 () ;
}
static void F_176 ( struct V_29 * V_70 )
{
}
static void F_177 ( struct V_29 * V_70 )
{
F_64 ( L_66 ) ;
}
static void F_178 ( void )
{
#ifdef F_179
struct V_29 V_196 ;
struct V_29 V_197 ;
F_85 ( & V_196 ) ;
F_85 ( & V_197 ) ;
F_64 ( L_67 ) ;
F_71 () ;
F_14 () ;
F_35 ( & V_196 , F_176 ) ;
F_180 () ;
F_35 ( & V_197 , F_176 ) ;
F_35 ( & V_197 , F_177 ) ;
F_181 () ;
F_23 () ;
F_73 () ;
F_182 () ;
F_64 ( L_68 ) ;
F_95 ( & V_196 ) ;
F_95 ( & V_197 ) ;
#else
F_64 ( L_69 ) ;
#endif
}
static int T_7
F_183 ( void )
{
int V_21 ;
int V_40 ;
int V_198 = 0 ;
static struct V_149 * V_199 [] = {
& V_200 , & V_201 , & V_202 , & V_203 , & V_204 ,
V_205
} ;
if ( ! F_184 ( V_42 , V_151 , & V_206 ) )
return - V_207 ;
for ( V_21 = 0 ; V_21 < F_185 ( V_199 ) ; V_21 ++ ) {
V_31 = V_199 [ V_21 ] ;
if ( strcmp ( V_42 , V_31 -> V_128 ) == 0 )
break;
}
if ( V_21 == F_185 ( V_199 ) ) {
F_64 ( L_70 ,
V_42 ) ;
F_64 ( L_71 ) ;
for ( V_21 = 0 ; V_21 < F_185 ( V_199 ) ; V_21 ++ )
F_64 ( L_72 , V_199 [ V_21 ] -> V_128 ) ;
F_64 ( L_3 ) ;
F_186 () ;
return - V_208 ;
}
if ( V_31 -> V_84 == NULL && V_83 != 0 ) {
F_64 ( L_73 ) ;
V_83 = 0 ;
}
if ( V_31 -> V_209 )
V_31 -> V_209 () ;
if ( V_210 >= 0 ) {
V_18 = V_210 ;
} else {
V_18 = F_187 () - 1 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_141 ( V_31 , L_74 ) ;
F_37 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_185 ( V_211 ) ; V_21 ++ ) {
V_211 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_211 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_110 = NULL ;
V_113 = 0 ;
F_163 ( & V_10 , 0 ) ;
F_163 ( & V_9 , 0 ) ;
F_163 ( & V_13 , 0 ) ;
F_163 ( & V_125 , 0 ) ;
F_163 ( & V_143 , 0 ) ;
V_142 = 0 ;
V_139 = 0 ;
V_61 = 0 ;
V_66 = 0 ;
V_69 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_163 ( & V_24 [ V_21 ] , 0 ) ;
F_65 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_135 ( V_129 , V_40 ) [ V_21 ] = 0 ;
F_135 ( V_130 , V_40 ) [ V_21 ] = 0 ;
}
}
V_198 = F_155 ( F_104 , NULL ,
V_111 ) ;
if ( V_198 )
goto V_212;
V_190 = F_165 ( V_116 * sizeof( V_190 [ 0 ] ) ,
V_178 ) ;
if ( V_190 == NULL ) {
F_188 ( L_75 ) ;
V_198 = - V_179 ;
goto V_212;
}
for ( V_21 = 0 ; V_21 < V_116 ; V_21 ++ ) {
V_198 = F_155 ( F_112 ,
NULL , V_190 [ V_21 ] ) ;
if ( V_198 )
goto V_212;
}
V_189 = F_165 ( V_18 * sizeof( V_189 [ 0 ] ) ,
V_178 ) ;
if ( V_189 == NULL ) {
F_188 ( L_75 ) ;
V_198 = - V_179 ;
goto V_212;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_198 = F_155 ( F_128 , NULL ,
V_189 [ V_21 ] ) ;
if ( V_198 )
goto V_212;
}
if ( V_148 > 0 ) {
V_198 = F_155 ( F_140 , NULL ,
V_191 ) ;
if ( V_198 )
goto V_212;
}
if ( V_152 ) {
V_198 = F_189 ( V_153 * V_37 ) ;
if ( V_198 )
goto V_212;
}
if ( V_154 < 0 )
V_154 = 0 ;
if ( V_154 ) {
V_198 = F_190 ( V_154 * V_37 ) ;
if ( V_198 )
goto V_212;
}
if ( V_83 < 0 )
V_83 = 0 ;
if ( V_83 ) {
V_198 = F_155 ( F_103 , NULL ,
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
F_191 ( & V_195 ) ;
F_65 (i) {
if ( F_192 ( V_21 ) )
continue;
V_198 = F_145 ( V_21 ) ;
if ( V_198 )
goto V_212;
}
}
V_198 = F_193 ( V_157 , F_170 ) ;
if ( V_198 )
goto V_212;
V_198 = F_194 ( V_162 * V_37 , V_161 * V_37 ) ;
if ( V_198 )
goto V_212;
V_198 = F_154 () ;
if ( V_198 )
goto V_212;
V_198 = F_164 () ;
if ( V_198 )
goto V_212;
if ( V_213 )
F_178 () ;
if ( V_78 > 0 ) {
V_193 = ( F_187 () + 3 ) / 4 ;
V_194 = F_195 ( V_193 , sizeof( * V_194 ) ,
V_178 ) ;
if ( ! V_194 ) {
F_188 ( L_75 ) ;
V_198 = - V_179 ;
goto V_212;
}
for ( V_21 = 0 ; V_21 < V_193 ; V_21 ++ ) {
V_198 = F_155 ( F_98 ,
NULL ,
V_194 [ V_21 ] ) ;
if ( V_198 )
goto V_212;
}
}
F_171 () ;
F_186 () ;
return 0 ;
V_212:
F_186 () ;
F_170 () ;
return V_198 ;
}
