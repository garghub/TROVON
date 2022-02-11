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
static void F_63 ( char * V_40 )
{
int V_41 ;
int V_19 = V_39 . V_42 & 0x1 ;
V_40 += sprintf ( V_40 , L_1 ,
V_43 , V_44 , V_19 ) ;
F_64 (cpu) {
long V_45 , V_46 ;
V_45 = ( long ) F_65 ( V_39 . V_47 , V_41 ) -> V_48 [ ! V_19 ] ;
V_46 = ( long ) F_65 ( V_39 . V_47 , V_41 ) -> V_48 [ V_19 ] ;
V_40 += sprintf ( V_40 , L_2 , V_41 , V_45 , V_46 ) ;
}
sprintf ( V_40 , L_3 ) ;
}
static void F_66 ( void )
{
F_67 ( & V_39 ) ;
}
static int F_68 ( void )
{
F_69 () ;
return 0 ;
}
static void F_70 ( int V_19 )
{
F_71 () ;
}
static void F_72 ( struct V_4 * V_6 )
{
F_73 ( & V_6 -> V_30 , F_31 ) ;
}
static void F_74 ( struct V_29 * V_33 )
{
struct V_49 * V_50 =
F_10 ( V_33 , struct V_49 , V_34 ) ;
F_75 () ;
V_50 -> V_51 = 0 ;
}
static int F_76 ( void * V_52 )
{
unsigned long V_53 ;
unsigned long V_54 ;
unsigned long V_55 ;
struct V_49 V_56 = { . V_51 = 0 } ;
struct V_57 V_58 ;
F_77 ( L_4 ) ;
V_58 . V_59 = 1 ;
if ( F_78 ( V_60 , V_61 , & V_58 ) < 0 ) {
F_77 ( L_5 ) ;
V_62 ++ ;
}
F_79 ( & V_56 . V_34 ) ;
do {
V_55 = V_63 ;
while ( F_80 ( V_64 , V_55 ) ) {
F_52 ( V_55 - V_64 ) ;
F_81 ( L_6 ) ;
if ( F_82 () )
goto V_65;
}
V_54 = V_55 + V_66 * V_37 ;
V_53 = V_64 ;
while ( F_80 ( V_64 , V_54 ) ) {
if ( ! V_56 . V_51 ) {
F_75 () ;
V_56 . V_51 = 1 ;
F_35 ( & V_56 . V_34 , F_74 ) ;
if ( V_64 - V_53 >
V_66 * V_37 - V_37 / 2 ) {
F_77 ( L_7 ) ;
V_67 ++ ;
}
V_53 = V_64 ;
}
F_83 () ;
F_81 ( L_6 ) ;
if ( F_82 () )
goto V_65;
}
while ( V_55 == V_63 &&
! F_84 () ) {
if ( F_85 ( & V_68 ) ) {
V_63 = V_64 +
V_69 * V_37 ;
V_70 ++ ;
F_86 ( & V_68 ) ;
break;
}
F_87 ( 1 ) ;
}
V_65: F_81 ( L_6 ) ;
} while ( ! F_82 () );
while ( ! F_84 () || V_56 . V_51 ) {
F_88 ( L_6 ) ;
F_87 ( 1 ) ;
}
F_75 () ;
F_89 ( & V_56 . V_34 ) ;
F_90 ( L_6 ) ;
return 0 ;
}
static int
F_91 ( void * V_52 )
{
unsigned long V_71 ;
int V_72 ;
F_77 ( L_8 ) ;
do {
V_71 = V_64 + V_73 * V_37 ;
while ( F_80 ( V_64 , V_71 ) &&
! F_84 () ) {
F_52 ( 1 ) ;
}
V_72 = V_74 ;
while ( V_72 > 0 &&
! F_84 () ) {
V_31 -> V_75 () ;
F_18 ( V_76 ) ;
V_72 -= V_76 ;
}
F_81 ( L_9 ) ;
} while ( ! F_82 () );
F_90 ( L_9 ) ;
return 0 ;
}
static int
F_92 ( void * V_52 )
{
unsigned long V_77 ;
bool V_78 = V_79 , V_80 = V_81 , V_82 = V_83 ;
bool V_84 = V_85 ;
int V_21 ;
struct V_4 * V_20 ;
struct V_4 * V_26 ;
static F_93 ( rand ) ;
int V_86 [] = { V_87 , V_88 ,
V_89 , V_90 } ;
int V_91 = 0 ;
F_77 ( L_10 ) ;
if ( ! V_78 && ! V_80 && ! V_82 && ! V_85 )
V_78 = V_80 = V_82 = V_84 = true ;
if ( V_78 && V_31 -> V_92 && V_31 -> V_93 )
V_86 [ V_91 ++ ] = V_89 ;
else if ( V_79 && ( ! V_31 -> V_92 || ! V_31 -> V_93 ) )
F_94 ( L_11 ) ;
if ( V_80 && V_31 -> V_94 )
V_86 [ V_91 ++ ] = V_88 ;
else if ( V_81 && ! V_31 -> V_94 )
F_94 ( L_12 ) ;
if ( V_82 && V_31 -> V_32 )
V_86 [ V_91 ++ ] = V_87 ;
else if ( V_83 && ! V_31 -> V_32 )
F_94 ( L_13 ) ;
if ( V_84 && V_31 -> V_95 )
V_86 [ V_91 ++ ] = V_90 ;
else if ( V_85 && ! V_31 -> V_95 )
F_94 ( L_14 ) ;
if ( F_95 ( V_91 == 0 ,
L_15 ) ) {
V_96 = V_97 ;
F_90 ( L_16 ) ;
}
do {
V_96 = V_98 ;
F_87 ( 1 ) ;
V_20 = F_4 () ;
if ( V_20 == NULL )
continue;
V_20 -> V_22 = 0 ;
V_96 = V_99 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_96 = V_100 ;
V_26 = F_96 ( V_101 ,
V_60 == V_102 ) ;
V_20 -> V_25 = 1 ;
F_97 ( V_101 , V_20 ) ;
F_98 () ;
if ( V_26 ) {
V_21 = V_26 -> V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
F_7 ( & V_24 [ V_21 ] ) ;
V_26 -> V_22 ++ ;
switch ( V_86 [ F_16 ( & rand ) % V_91 ] ) {
case V_87 :
V_96 = V_87 ;
V_31 -> V_32 ( V_26 ) ;
break;
case V_88 :
V_96 = V_88 ;
V_31 -> V_94 () ;
F_27 ( V_26 ) ;
break;
case V_89 :
V_96 = V_89 ;
V_77 = V_31 -> V_92 () ;
V_21 = F_16 ( & rand ) % 16 ;
if ( V_21 != 0 )
F_52 ( V_21 ) ;
F_18 ( F_16 ( & rand ) % 1000 ) ;
V_96 = V_103 ;
V_31 -> V_93 ( V_77 ) ;
F_27 ( V_26 ) ;
break;
case V_90 :
V_96 = V_90 ;
V_31 -> V_95 () ;
F_27 ( V_26 ) ;
break;
default:
F_99 ( 1 ) ;
break;
}
}
F_100 ( ++ V_104 ) ;
V_96 = V_105 ;
F_81 ( L_16 ) ;
} while ( ! F_82 () );
V_96 = V_97 ;
F_90 ( L_16 ) ;
return 0 ;
}
static int
F_101 ( void * V_52 )
{
F_93 ( rand ) ;
F_77 ( L_17 ) ;
F_102 ( V_60 , V_106 ) ;
do {
F_87 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_31 -> V_107 != NULL &&
F_16 ( & rand ) % ( V_108 * 8 ) == 0 ) {
V_31 -> V_107 () ;
} else if ( V_83 == V_81 ) {
if ( F_16 ( & rand ) & 0x80 )
V_31 -> V_95 () ;
else
V_31 -> V_94 () ;
} else if ( V_83 ) {
V_31 -> V_95 () ;
} else {
V_31 -> V_94 () ;
}
F_81 ( L_18 ) ;
} while ( ! F_82 () );
F_90 ( L_18 ) ;
return 0 ;
}
static void F_103 ( void )
{
static T_6 V_109 = F_104 ( 0 ) ;
if ( F_105 ( & V_109 ) )
return;
if ( F_106 ( & V_109 , 1 ) != 0 )
return;
F_107 ( V_110 ) ;
}
static void F_108 ( unsigned long V_111 )
{
int V_19 ;
int V_42 ;
int V_112 ;
static F_93 ( rand ) ;
static F_109 ( V_113 ) ;
struct V_4 * V_6 ;
int V_114 ;
unsigned long long V_1 ;
V_19 = V_31 -> V_115 () ;
V_42 = V_31 -> V_42 () ;
V_1 = F_1 () ;
V_6 = F_96 ( V_101 ,
F_110 () ||
F_111 () ||
F_112 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_116 ( V_19 ) ;
return;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_117 ) ;
F_113 ( & V_113 ) ;
V_31 -> V_118 ( & rand ) ;
V_119 ++ ;
F_114 ( & V_113 ) ;
F_69 () ;
V_114 = V_6 -> V_22 ;
if ( V_114 > V_23 ) {
V_114 = V_23 ;
}
V_112 = V_31 -> V_42 () ;
if ( V_114 > 1 ) {
F_115 ( V_31 -> V_120 , & V_6 -> V_30 , V_1 ,
V_42 , V_112 ) ;
F_103 () ;
}
F_116 ( V_121 [ V_114 ] ) ;
V_42 = V_112 - V_42 ;
if ( V_42 > V_23 ) {
V_42 = V_23 ;
}
F_116 ( V_122 [ V_42 ] ) ;
F_71 () ;
V_31 -> V_116 ( V_19 ) ;
}
static int
F_117 ( void * V_52 )
{
int V_42 ;
int V_112 ;
int V_19 ;
F_93 ( rand ) ;
struct V_4 * V_6 ;
int V_114 ;
struct V_123 V_124 ;
unsigned long long V_1 ;
F_77 ( L_19 ) ;
F_102 ( V_60 , V_106 ) ;
if ( V_125 && V_31 -> V_126 )
F_118 ( & V_124 , F_108 , 0 ) ;
do {
if ( V_125 && V_31 -> V_126 ) {
if ( ! F_119 ( & V_124 ) )
F_120 ( & V_124 , V_64 + 1 ) ;
}
V_19 = V_31 -> V_115 () ;
V_42 = V_31 -> V_42 () ;
V_1 = F_1 () ;
V_6 = F_96 ( V_101 ,
F_110 () ||
F_111 () ||
F_112 ( & V_39 ) ) ;
if ( V_6 == NULL ) {
V_31 -> V_116 ( V_19 ) ;
F_52 ( V_37 ) ;
continue;
}
if ( V_6 -> V_25 == 0 )
F_7 ( & V_117 ) ;
V_31 -> V_118 ( & rand ) ;
F_69 () ;
V_114 = V_6 -> V_22 ;
if ( V_114 > V_23 ) {
V_114 = V_23 ;
}
V_112 = V_31 -> V_42 () ;
if ( V_114 > 1 ) {
F_115 ( V_31 -> V_120 , & V_6 -> V_30 ,
V_1 , V_42 , V_112 ) ;
F_103 () ;
}
F_116 ( V_121 [ V_114 ] ) ;
V_42 = V_112 - V_42 ;
if ( V_42 > V_23 ) {
V_42 = V_23 ;
}
F_116 ( V_122 [ V_42 ] ) ;
F_71 () ;
V_31 -> V_116 ( V_19 ) ;
F_83 () ;
F_81 ( L_20 ) ;
} while ( ! F_82 () );
if ( V_125 && V_31 -> V_126 ) {
F_121 ( & V_124 ) ;
F_122 ( & V_124 ) ;
}
F_90 ( L_20 ) ;
return 0 ;
}
static void
F_123 ( char * V_40 )
{
int V_41 ;
int V_21 ;
long V_127 [ V_23 + 1 ] = { 0 } ;
long V_128 [ V_23 + 1 ] = { 0 } ;
static unsigned long V_129 = V_130 ;
F_64 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_127 [ V_21 ] += F_124 ( V_121 , V_41 ) [ V_21 ] ;
V_128 [ V_21 ] += F_124 ( V_122 , V_41 ) [ V_21 ] ;
}
}
for ( V_21 = V_23 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_127 [ V_21 ] != 0 )
break;
}
V_40 += sprintf ( V_40 , L_21 , V_43 , V_44 ) ;
V_40 += sprintf ( V_40 ,
L_22 ,
V_101 ,
V_104 ,
F_6 ( & V_8 ) ,
F_105 ( & V_10 ) ,
F_105 ( & V_9 ) ,
F_105 ( & V_13 ) ) ;
V_40 += sprintf ( V_40 , L_23 ,
F_105 ( & V_117 ) ,
V_131 ,
V_62 ) ;
V_40 += sprintf ( V_40 , L_24 ,
V_67 ,
V_70 ,
V_119 ) ;
V_40 = F_125 ( V_40 ) ;
V_40 += sprintf ( V_40 , L_25 ,
V_132 ,
V_133 ,
V_134 ) ;
V_40 += sprintf ( V_40 , L_26 , V_43 , V_44 ) ;
if ( F_105 ( & V_117 ) != 0 ||
V_134 != 0 ||
V_131 != 0 ||
V_62 != 0 ||
V_67 != 0 ||
V_21 > 1 ) {
V_40 += sprintf ( V_40 , L_27 ) ;
F_7 ( & V_135 ) ;
F_99 ( 1 ) ;
}
V_40 += sprintf ( V_40 , L_28 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
V_40 += sprintf ( V_40 , L_29 , V_127 [ V_21 ] ) ;
V_40 += sprintf ( V_40 , L_26 , V_43 , V_44 ) ;
V_40 += sprintf ( V_40 , L_30 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
V_40 += sprintf ( V_40 , L_29 , V_128 [ V_21 ] ) ;
V_40 += sprintf ( V_40 , L_26 , V_43 , V_44 ) ;
V_40 += sprintf ( V_40 , L_31 ) ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
V_40 += sprintf ( V_40 , L_32 ,
F_105 ( & V_24 [ V_21 ] ) ) ;
}
V_40 += sprintf ( V_40 , L_3 ) ;
if ( V_31 -> V_136 )
V_31 -> V_136 ( V_40 ) ;
if ( V_129 == V_104 &&
V_101 != NULL ) {
int T_3 V_137 ;
unsigned long T_3 V_138 ;
unsigned long T_3 V_42 ;
F_126 ( V_31 -> V_139 ,
& V_137 , & V_138 , & V_42 ) ;
V_40 += sprintf ( V_40 ,
L_33 ,
V_96 ,
V_138 , V_42 , V_137 ) ;
F_127 () ;
F_103 () ;
}
V_129 = V_104 ;
}
static void
F_128 ( void )
{
int V_140 = V_141 * 200 + 8192 ;
char * V_142 ;
V_142 = F_129 ( V_140 , V_143 ) ;
if ( ! V_142 ) {
F_130 ( L_34 , V_140 ) ;
return;
}
F_123 ( V_142 ) ;
F_94 ( L_35 , V_142 ) ;
F_131 ( V_142 ) ;
}
static int
F_132 ( void * V_52 )
{
F_77 ( L_36 ) ;
do {
F_52 ( V_144 * V_37 ) ;
F_128 () ;
F_88 ( L_37 ) ;
} while ( ! F_82 () );
F_90 ( L_37 ) ;
return 0 ;
}
static inline void
F_133 ( struct V_145 * V_31 , const char * V_146 )
{
F_94 ( L_35 V_44
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46 ,
V_43 , V_146 , V_18 , V_108 ,
V_144 , V_147 , V_148 , V_149 ,
V_150 , V_125 , V_74 , V_76 , V_73 ,
V_151 , V_31 -> V_152 ,
V_69 , V_66 , V_153 ,
V_154 , V_155 ,
V_156 ,
V_157 , V_158 ) ;
}
static void F_134 ( int V_41 )
{
struct V_159 * V_124 ;
if ( V_160 [ V_41 ] == NULL )
return;
F_135 ( & V_68 ) ;
V_124 = V_160 [ V_41 ] ;
V_160 [ V_41 ] = NULL ;
F_86 ( & V_68 ) ;
F_136 ( F_76 , V_124 ) ;
}
static int F_137 ( int V_41 )
{
int V_161 ;
if ( V_160 [ V_41 ] != NULL )
return 0 ;
F_135 ( & V_68 ) ;
F_77 ( L_47 ) ;
V_160 [ V_41 ] = F_138 ( F_76 , NULL ,
F_139 ( V_41 ) ,
L_6 ) ;
if ( F_140 ( V_160 [ V_41 ] ) ) {
V_161 = F_141 ( V_160 [ V_41 ] ) ;
F_77 ( L_48 ) ;
V_131 ++ ;
V_160 [ V_41 ] = NULL ;
F_86 ( & V_68 ) ;
return V_161 ;
}
F_142 ( V_160 [ V_41 ] , V_41 ) ;
F_143 ( V_160 [ V_41 ] ) ;
F_86 ( & V_68 ) ;
return 0 ;
}
static int F_144 ( void * args )
{
unsigned long V_162 ;
F_77 ( L_49 ) ;
if ( V_155 > 0 ) {
F_77 ( L_50 ) ;
F_52 ( V_155 * V_37 ) ;
F_77 ( L_51 ) ;
}
if ( ! F_84 () ) {
V_162 = F_145 () + V_154 ;
F_94 ( L_52 ) ;
F_14 () ;
F_69 () ;
while ( F_80 ( F_145 () , V_162 ) )
continue;
F_71 () ;
F_23 () ;
F_94 ( L_53 ) ;
}
F_88 ( L_54 ) ;
while ( ! F_84 () )
F_52 ( 10 * V_37 ) ;
return 0 ;
}
static int T_7 F_146 ( void )
{
if ( V_154 <= 0 )
return 0 ;
return F_147 ( F_144 , NULL , V_163 ) ;
}
static void F_148 ( struct V_29 * V_34 )
{
F_7 ( & V_164 ) ;
}
static int F_149 ( void * V_52 )
{
long V_165 = ( long ) V_52 ;
bool V_166 = 0 ;
bool V_167 ;
struct V_29 V_34 ;
F_79 ( & V_34 ) ;
F_77 ( L_55 ) ;
F_102 ( V_60 , V_106 ) ;
do {
F_150 ( V_168 [ V_165 ] ,
( V_167 =
F_151 ( V_169 ) ) != V_166 ||
F_82 () ) ;
V_166 = V_167 ;
F_75 () ;
if ( F_82 () )
break;
V_31 -> V_170 ( & V_34 , F_148 ) ;
if ( F_152 ( & V_171 ) )
F_153 ( & V_172 ) ;
} while ( ! F_82 () );
V_31 -> V_107 () ;
F_89 ( & V_34 ) ;
F_90 ( L_56 ) ;
return 0 ;
}
static int F_154 ( void * V_52 )
{
int V_21 ;
F_77 ( L_57 ) ;
do {
F_155 ( & V_164 , 0 ) ;
F_155 ( & V_171 , V_156 ) ;
F_75 () ;
V_169 = ! V_169 ;
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ )
F_153 ( & V_168 [ V_21 ] ) ;
F_150 ( V_172 ,
F_105 ( & V_171 ) == 0 ||
F_82 () ) ;
if ( F_82 () )
break;
V_133 ++ ;
V_31 -> V_107 () ;
if ( F_105 ( & V_164 ) != V_156 ) {
V_134 ++ ;
F_99 ( 1 ) ;
}
V_132 ++ ;
F_52 ( V_37 / 10 ) ;
} while ( ! F_82 () );
F_90 ( L_58 ) ;
return 0 ;
}
static int F_156 ( void )
{
int V_21 ;
int V_173 ;
if ( V_156 == 0 )
return 0 ;
if ( V_31 -> V_170 == NULL || V_31 -> V_107 == NULL ) {
F_94 ( L_35 V_44
L_59 ,
V_43 , V_31 -> V_120 ) ;
F_94 ( L_35 V_44
L_60 ,
V_43 ) ;
return 0 ;
}
F_155 ( & V_171 , 0 ) ;
F_155 ( & V_164 , 0 ) ;
V_174 =
F_157 ( V_156 * sizeof( V_174 [ 0 ] ) ,
V_143 ) ;
V_168 =
F_157 ( V_156 * sizeof( V_168 [ 0 ] ) ,
V_143 ) ;
if ( V_174 == NULL || ! V_168 )
return - V_175 ;
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ ) {
F_158 ( & V_168 [ V_21 ] ) ;
V_173 = F_147 ( F_149 ,
( void * ) ( long ) V_21 ,
V_174 [ V_21 ] ) ;
if ( V_173 )
return V_173 ;
}
return F_147 ( F_154 , NULL , V_176 ) ;
}
static void F_159 ( void )
{
int V_21 ;
F_136 ( F_154 , V_176 ) ;
if ( V_174 != NULL ) {
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ )
F_136 ( F_149 ,
V_174 [ V_21 ] ) ;
F_131 ( V_174 ) ;
V_174 = NULL ;
}
if ( V_168 != NULL ) {
F_131 ( V_168 ) ;
V_168 = NULL ;
}
}
static int F_160 ( struct V_177 * V_178 ,
unsigned long V_179 , void * V_180 )
{
long V_41 = ( long ) V_180 ;
switch ( V_179 ) {
case V_181 :
case V_182 :
( void ) F_137 ( V_41 ) ;
break;
case V_183 :
F_134 ( V_41 ) ;
break;
default:
break;
}
return V_184 ;
}
static void
F_161 ( void )
{
int V_21 ;
F_162 () ;
if ( F_163 () ) {
if ( V_31 -> V_107 != NULL )
V_31 -> V_107 () ;
return;
}
F_159 () ;
F_136 ( F_144 , V_163 ) ;
F_136 ( F_92 , V_102 ) ;
if ( V_185 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_136 ( F_117 ,
V_185 [ V_21 ] ) ;
F_131 ( V_185 ) ;
}
V_101 = NULL ;
if ( V_186 ) {
for ( V_21 = 0 ; V_21 < V_108 ; V_21 ++ ) {
F_136 ( F_101 ,
V_186 [ V_21 ] ) ;
}
F_131 ( V_186 ) ;
V_186 = NULL ;
}
F_136 ( F_132 , V_187 ) ;
F_136 ( F_91 , V_188 ) ;
if ( ( V_151 == 1 && V_31 -> V_152 ) ||
V_151 == 2 ) {
F_164 ( & V_189 ) ;
F_64 (i)
F_134 ( V_21 ) ;
}
if ( V_31 -> V_107 != NULL )
V_31 -> V_107 () ;
F_128 () ;
if ( F_105 ( & V_135 ) || V_134 )
F_133 ( V_31 , L_61 ) ;
else if ( F_165 () )
F_133 ( V_31 ,
L_62 ) ;
else
F_133 ( V_31 , L_63 ) ;
}
static void F_166 ( struct V_29 * V_190 )
{
}
static void F_167 ( struct V_29 * V_190 )
{
F_94 ( L_64 ) ;
}
static void F_168 ( void )
{
#ifdef F_169
struct V_29 V_191 ;
struct V_29 V_192 ;
F_79 ( & V_191 ) ;
F_79 ( & V_192 ) ;
F_94 ( L_65 ) ;
F_69 () ;
F_14 () ;
F_35 ( & V_191 , F_166 ) ;
F_170 () ;
F_35 ( & V_192 , F_166 ) ;
F_35 ( & V_192 , F_167 ) ;
F_171 () ;
F_23 () ;
F_71 () ;
F_172 () ;
F_94 ( L_66 ) ;
F_89 ( & V_191 ) ;
F_89 ( & V_192 ) ;
#else
F_94 ( L_67 ) ;
#endif
}
static int T_7
F_173 ( void )
{
int V_21 ;
int V_41 ;
int V_193 = 0 ;
static struct V_145 * V_194 [] = {
& V_195 , & V_196 , & V_197 , & V_198 , & V_199 ,
} ;
if ( ! F_174 ( V_43 , V_147 , & V_200 ) )
return - V_201 ;
for ( V_21 = 0 ; V_21 < F_175 ( V_194 ) ; V_21 ++ ) {
V_31 = V_194 [ V_21 ] ;
if ( strcmp ( V_43 , V_31 -> V_120 ) == 0 )
break;
}
if ( V_21 == F_175 ( V_194 ) ) {
F_94 ( L_68 ,
V_43 ) ;
F_94 ( L_69 ) ;
for ( V_21 = 0 ; V_21 < F_175 ( V_194 ) ; V_21 ++ )
F_94 ( L_70 , V_194 [ V_21 ] -> V_120 ) ;
F_94 ( L_3 ) ;
F_176 () ;
return - V_202 ;
}
if ( V_31 -> V_75 == NULL && V_74 != 0 ) {
F_94 ( L_71 ) ;
V_74 = 0 ;
}
if ( V_31 -> V_203 )
V_31 -> V_203 () ;
if ( V_204 >= 0 ) {
V_18 = V_204 ;
} else {
V_18 = F_177 () - 1 ;
if ( V_18 <= 0 )
V_18 = 1 ;
}
F_133 ( V_31 , L_72 ) ;
F_37 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_175 ( V_205 ) ; V_21 ++ ) {
V_205 [ V_21 ] . V_25 = 0 ;
F_12 ( & V_205 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_101 = NULL ;
V_104 = 0 ;
F_155 ( & V_10 , 0 ) ;
F_155 ( & V_9 , 0 ) ;
F_155 ( & V_13 , 0 ) ;
F_155 ( & V_117 , 0 ) ;
F_155 ( & V_135 , 0 ) ;
V_134 = 0 ;
V_131 = 0 ;
V_62 = 0 ;
V_67 = 0 ;
V_70 = 0 ;
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ )
F_155 ( & V_24 [ V_21 ] , 0 ) ;
F_64 (cpu) {
for ( V_21 = 0 ; V_21 < V_23 + 1 ; V_21 ++ ) {
F_124 ( V_121 , V_41 ) [ V_21 ] = 0 ;
F_124 ( V_122 , V_41 ) [ V_21 ] = 0 ;
}
}
V_193 = F_147 ( F_92 , NULL ,
V_102 ) ;
if ( V_193 )
goto V_206;
V_186 = F_157 ( V_108 * sizeof( V_186 [ 0 ] ) ,
V_143 ) ;
if ( V_186 == NULL ) {
F_178 ( L_73 ) ;
V_193 = - V_175 ;
goto V_206;
}
for ( V_21 = 0 ; V_21 < V_108 ; V_21 ++ ) {
V_193 = F_147 ( F_101 ,
NULL , V_186 [ V_21 ] ) ;
if ( V_193 )
goto V_206;
}
V_185 = F_157 ( V_18 * sizeof( V_185 [ 0 ] ) ,
V_143 ) ;
if ( V_185 == NULL ) {
F_178 ( L_73 ) ;
V_193 = - V_175 ;
goto V_206;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_193 = F_147 ( F_117 , NULL ,
V_185 [ V_21 ] ) ;
if ( V_193 )
goto V_206;
}
if ( V_144 > 0 ) {
V_193 = F_147 ( F_132 , NULL ,
V_187 ) ;
if ( V_193 )
goto V_206;
}
if ( V_148 ) {
V_193 = F_179 ( V_149 * V_37 ) ;
if ( V_193 )
goto V_206;
}
if ( V_150 < 0 )
V_150 = 0 ;
if ( V_150 ) {
V_193 = F_180 ( V_150 * V_37 ) ;
if ( V_193 )
goto V_206;
}
if ( V_74 < 0 )
V_74 = 0 ;
if ( V_74 ) {
V_193 = F_147 ( F_91 , NULL ,
V_188 ) ;
if ( V_193 )
goto V_206;
}
if ( V_69 < 1 )
V_69 = 1 ;
if ( V_66 < 2 )
V_66 = 2 ;
if ( ( V_151 == 1 && V_31 -> V_152 ) ||
V_151 == 2 ) {
V_63 = V_64 + V_69 * V_37 ;
F_181 ( & V_189 ) ;
F_64 (i) {
if ( F_182 ( V_21 ) )
continue;
V_193 = F_137 ( V_21 ) ;
if ( V_193 )
goto V_206;
}
}
V_193 = F_183 ( V_153 , F_161 ) ;
if ( V_193 )
goto V_206;
V_193 = F_184 ( V_158 * V_37 , V_157 * V_37 ) ;
if ( V_193 )
goto V_206;
V_193 = F_146 () ;
if ( V_193 )
goto V_206;
V_193 = F_156 () ;
if ( V_193 )
goto V_206;
if ( V_207 )
F_168 () ;
F_162 () ;
F_176 () ;
return 0 ;
V_206:
F_176 () ;
F_161 () ;
return V_193 ;
}
