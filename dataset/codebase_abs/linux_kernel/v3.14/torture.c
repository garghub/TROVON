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
static int
F_4 ( struct V_4 * V_5 ,
unsigned long V_6 , void * V_7 )
{
F_5 ( & V_8 ) ;
if ( V_9 == V_10 )
V_9 = V_11 ;
else
F_6 (
L_1 ) ;
F_7 ( & V_8 ) ;
return V_12 ;
}
static void F_8 ( const char * V_13 )
{
if ( F_9 ( V_9 ) == V_11 ) {
F_10 (
L_2 ,
V_13 ) ;
F_11 ( V_14 ) ;
}
}
static struct V_15 *
F_12 ( void )
{
struct V_16 * V_17 ;
F_13 ( & V_18 ) ;
if ( F_14 ( & V_19 ) ) {
F_15 ( & V_20 ) ;
F_16 ( & V_18 ) ;
return NULL ;
}
F_15 ( & V_21 ) ;
V_17 = V_19 . V_22 ;
F_17 ( V_17 ) ;
F_16 ( & V_18 ) ;
return F_18 ( V_17 , struct V_15 , V_23 ) ;
}
static void
F_19 ( struct V_15 * V_17 )
{
F_15 ( & V_24 ) ;
F_13 ( & V_18 ) ;
F_20 ( & V_17 -> V_23 , & V_19 ) ;
F_16 ( & V_18 ) ;
}
static unsigned long
F_21 ( struct V_25 * V_26 )
{
if ( -- V_26 -> V_27 < 0 ) {
V_26 -> V_28 += ( unsigned long ) F_22 () ;
V_26 -> V_27 = V_29 ;
}
V_26 -> V_28 = V_26 -> V_28 * V_30 + V_31 ;
return F_23 ( V_26 -> V_28 ) ;
}
static void
F_24 ( const char * V_13 )
{
while ( V_32 || ! V_33 ) {
if ( V_33 )
F_25 ( 1 ) ;
else
F_25 ( F_26 ( V_34 ) ) ;
F_8 ( V_13 ) ;
}
}
static int F_27 ( void ) __acquires( T_4 )
{
F_28 () ;
return 0 ;
}
static void F_29 ( struct V_25 * V_26 )
{
const unsigned long V_35 = 200 ;
const unsigned long V_36 = 50 ;
if ( ! ( F_21 ( V_26 ) % ( V_37 * 2000 * V_36 ) ) )
F_30 ( V_36 ) ;
if ( ! ( F_21 ( V_26 ) % ( V_37 * 2 * V_35 ) ) )
F_31 ( V_35 ) ;
#ifdef F_32
if ( ! F_33 () && ! ( F_21 ( V_26 ) % ( V_37 * 20000 ) ) )
F_34 () ;
#endif
}
static void F_35 ( int V_38 ) __releases( T_4 )
{
F_36 () ;
}
static int F_37 ( void )
{
return F_38 () ;
}
static void
F_39 ( struct V_39 * V_17 )
{
int V_40 ;
struct V_15 * V_41 = F_18 ( V_17 , struct V_15 , V_42 ) ;
if ( V_9 != V_10 ) {
return;
}
V_40 = V_41 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
if ( ++ V_41 -> V_43 >= V_44 ) {
V_41 -> V_46 = 0 ;
F_19 ( V_41 ) ;
} else {
V_47 -> V_48 ( V_41 ) ;
}
}
static int F_40 ( void )
{
return 0 ;
}
static void F_41 ( struct V_15 * V_17 )
{
F_42 ( & V_17 -> V_42 , F_39 ) ;
}
static void F_43 ( void )
{
F_44 ( & V_49 ) ;
}
static int F_45 ( void ) __acquires( T_5 )
{
F_46 () ;
return 0 ;
}
static void F_47 ( int V_38 ) __releases( T_5 )
{
F_48 () ;
}
static int F_49 ( void )
{
return F_50 () ;
}
static void F_51 ( struct V_15 * V_17 )
{
F_52 ( & V_17 -> V_42 , F_39 ) ;
}
static int F_53 ( void ) __acquires( &srcu_ctl
static void F_54 ( struct V_25 * V_26 )
{
long V_50 ;
const long V_51 = 1000000 / V_34 ;
const long V_52 = 10 ;
V_50 = F_21 ( V_26 ) % ( V_37 * 2 * V_52 * V_51 ) ;
if ( ! V_50 )
F_25 ( V_52 ) ;
else
F_29 ( V_26 ) ;
}
static void F_55 ( int V_38 ) __releases( &srcu_ctl
static int F_56 ( void )
{
return F_57 ( & V_53 ) ;
}
static void F_58 ( struct V_15 * V_41 )
{
F_59 ( & V_53 , & V_41 -> V_42 , F_39 ) ;
}
static void F_60 ( void )
{
F_61 ( & V_53 ) ;
}
static void F_62 ( struct V_39 * V_54 ,
void (* F_63)( struct V_39 * V_54 ) )
{
F_59 ( & V_53 , V_54 , F_63 ) ;
}
static void F_64 ( void )
{
F_65 ( & V_53 ) ;
}
static void F_66 ( char * V_55 )
{
int V_56 ;
int V_38 = V_53 . V_57 & 0x1 ;
V_55 += sprintf ( V_55 , L_3 ,
V_58 , V_59 , V_38 ) ;
F_67 (cpu) {
V_55 += sprintf ( V_55 , L_4 , V_56 ,
F_68 ( V_53 . V_60 , V_56 ) -> V_61 [ ! V_38 ] ,
F_68 ( V_53 . V_60 , V_56 ) -> V_61 [ V_38 ] ) ;
}
sprintf ( V_55 , L_5 ) ;
}
static void F_69 ( void )
{
F_70 ( & V_53 ) ;
}
static int F_71 ( void )
{
F_72 () ;
return 0 ;
}
static void F_73 ( int V_38 )
{
F_74 () ;
}
static void F_75 ( struct V_15 * V_17 )
{
F_76 ( & V_17 -> V_42 , F_39 ) ;
}
static void F_77 ( struct V_39 * V_54 )
{
struct V_62 * V_63 =
F_18 ( V_54 , struct V_62 , V_64 ) ;
F_78 () ;
V_63 -> V_65 = 0 ;
}
static int F_79 ( void * V_66 )
{
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
struct V_62 V_70 = { . V_65 = 0 } ;
struct V_71 V_72 ;
F_80 ( L_6 ) ;
V_72 . V_73 = 1 ;
if ( F_81 ( V_74 , V_75 , & V_72 ) < 0 ) {
F_80 ( L_7 ) ;
V_76 ++ ;
}
F_82 ( & V_70 . V_64 ) ;
do {
V_69 = V_77 ;
while ( F_83 ( V_78 , V_69 ) ) {
F_25 ( V_69 - V_78 ) ;
F_24 ( L_8 ) ;
if ( F_84 () ||
V_9 != V_10 )
goto V_79;
}
V_68 = V_69 + V_80 * V_34 ;
V_67 = V_78 ;
while ( F_83 ( V_78 , V_68 ) ) {
if ( ! V_70 . V_65 ) {
F_78 () ;
V_70 . V_65 = 1 ;
F_42 ( & V_70 . V_64 , F_77 ) ;
if ( V_78 - V_67 >
V_80 * V_34 - V_34 / 2 ) {
F_80 ( L_9 ) ;
V_81 ++ ;
}
V_67 = V_78 ;
}
F_85 () ;
F_24 ( L_8 ) ;
if ( F_84 () ||
V_9 != V_10 )
goto V_79;
}
while ( V_69 == V_77 &&
! F_84 () ) {
if ( F_86 ( & V_82 ) ) {
V_77 = V_78 +
V_83 * V_34 ;
V_84 ++ ;
F_7 ( & V_82 ) ;
break;
}
F_11 ( 1 ) ;
}
V_79: F_24 ( L_8 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_10 ) ;
F_8 ( L_8 ) ;
while ( ! F_84 () || V_70 . V_65 )
F_11 ( 1 ) ;
F_78 () ;
F_87 ( & V_70 . V_64 ) ;
return 0 ;
}
static int
F_88 ( void * V_66 )
{
unsigned long V_85 ;
int V_86 ;
F_80 ( L_11 ) ;
do {
V_85 = V_78 + V_87 * V_34 ;
while ( F_83 ( V_78 , V_85 ) &&
! F_84 () ) {
F_25 ( 1 ) ;
}
V_86 = V_88 ;
while ( V_86 > 0 &&
! F_84 () ) {
V_47 -> V_89 () ;
F_31 ( V_90 ) ;
V_86 -= V_90 ;
}
F_24 ( L_12 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_13 ) ;
F_8 ( L_12 ) ;
while ( ! F_84 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_89 ( void * V_66 )
{
bool exp ;
int V_40 ;
struct V_15 * V_41 ;
struct V_15 * V_91 ;
struct V_15 * V_92 ;
static F_90 ( rand ) ;
F_80 ( L_14 ) ;
F_91 ( V_74 , 19 ) ;
do {
F_11 ( 1 ) ;
V_41 = F_12 () ;
if ( V_41 == NULL )
continue;
V_41 -> V_43 = 0 ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
V_92 = F_92 ( V_93 ,
V_74 == V_94 ) ;
V_41 -> V_46 = 1 ;
F_93 ( V_93 , V_41 ) ;
F_94 () ;
if ( V_92 ) {
V_40 = V_92 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
V_92 -> V_43 ++ ;
if ( V_95 == V_96 )
exp = ! ! ( F_21 ( & rand ) & 0x80 ) ;
else
exp = V_96 ;
if ( ! exp ) {
V_47 -> V_48 ( V_92 ) ;
} else {
V_47 -> V_97 () ;
F_95 ( & V_92 -> V_23 ,
& V_49 ) ;
F_96 (rp, rp1,
&rcu_torture_removed,
rtort_free) {
V_40 = V_41 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
if ( ++ V_41 -> V_43 >=
V_44 ) {
V_41 -> V_46 = 0 ;
F_97 ( & V_41 -> V_23 ) ;
F_19 ( V_41 ) ;
}
}
}
}
F_98 ( ++ V_98 ) ;
F_24 ( L_15 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_16 ) ;
F_8 ( L_15 ) ;
while ( ! F_84 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_99 ( void * V_66 )
{
F_90 ( rand ) ;
F_80 ( L_17 ) ;
F_91 ( V_74 , 19 ) ;
do {
F_11 ( 1 + F_21 ( & rand ) % 10 ) ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
if ( V_47 -> V_99 != NULL &&
F_21 ( & rand ) % ( V_100 * 8 ) == 0 ) {
V_47 -> V_99 () ;
} else if ( V_95 == V_96 ) {
if ( F_21 ( & rand ) & 0x80 )
V_47 -> V_101 () ;
else
V_47 -> V_97 () ;
} else if ( V_95 ) {
V_47 -> V_101 () ;
} else {
V_47 -> V_97 () ;
}
F_24 ( L_18 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_19 ) ;
F_8 ( L_18 ) ;
while ( ! F_84 () )
F_11 ( 1 ) ;
return 0 ;
}
void F_100 ( void )
{
static T_6 V_102 = F_101 ( 0 ) ;
if ( F_102 ( & V_102 ) )
return;
if ( F_103 ( & V_102 , 1 ) != 0 )
return;
F_104 ( V_103 ) ;
}
static void F_105 ( unsigned long V_104 )
{
int V_38 ;
int V_57 ;
int V_105 ;
static F_90 ( rand ) ;
static F_106 ( V_106 ) ;
struct V_15 * V_17 ;
int V_107 ;
unsigned long long V_1 ;
V_38 = V_47 -> V_108 () ;
V_57 = V_47 -> V_57 () ;
V_1 = F_1 () ;
V_17 = F_92 ( V_93 ,
F_107 () ||
F_108 () ||
F_109 ( & V_53 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_109 ( V_38 ) ;
return;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_110 ) ;
F_110 ( & V_106 ) ;
V_47 -> V_111 ( & rand ) ;
V_112 ++ ;
F_111 ( & V_106 ) ;
F_72 () ;
V_107 = V_17 -> V_43 ;
if ( V_107 > V_44 ) {
V_107 = V_44 ;
}
V_105 = V_47 -> V_57 () ;
if ( V_107 > 1 ) {
F_112 ( V_47 -> V_113 , & V_17 -> V_42 , V_1 ,
V_57 , V_105 ) ;
F_100 () ;
}
F_113 ( V_114 [ V_107 ] ) ;
V_57 = V_105 - V_57 ;
if ( V_57 > V_44 ) {
V_57 = V_44 ;
}
F_113 ( V_115 [ V_57 ] ) ;
F_74 () ;
V_47 -> V_109 ( V_38 ) ;
}
static int
F_114 ( void * V_66 )
{
int V_57 ;
int V_105 ;
int V_38 ;
F_90 ( rand ) ;
struct V_15 * V_17 ;
int V_107 ;
struct V_116 V_117 ;
unsigned long long V_1 ;
F_80 ( L_20 ) ;
F_91 ( V_74 , 19 ) ;
if ( V_118 && V_47 -> V_119 )
F_115 ( & V_117 , F_105 , 0 ) ;
do {
if ( V_118 && V_47 -> V_119 ) {
if ( ! F_116 ( & V_117 ) )
F_117 ( & V_117 , V_78 + 1 ) ;
}
V_38 = V_47 -> V_108 () ;
V_57 = V_47 -> V_57 () ;
V_1 = F_1 () ;
V_17 = F_92 ( V_93 ,
F_107 () ||
F_108 () ||
F_109 ( & V_53 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_109 ( V_38 ) ;
F_25 ( V_34 ) ;
continue;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_110 ) ;
V_47 -> V_111 ( & rand ) ;
F_72 () ;
V_107 = V_17 -> V_43 ;
if ( V_107 > V_44 ) {
V_107 = V_44 ;
}
V_105 = V_47 -> V_57 () ;
if ( V_107 > 1 ) {
F_112 ( V_47 -> V_113 , & V_17 -> V_42 ,
V_1 , V_57 , V_105 ) ;
F_100 () ;
}
F_113 ( V_114 [ V_107 ] ) ;
V_57 = V_105 - V_57 ;
if ( V_57 > V_44 ) {
V_57 = V_44 ;
}
F_113 ( V_115 [ V_57 ] ) ;
F_74 () ;
V_47 -> V_109 ( V_38 ) ;
F_118 () ;
F_24 ( L_21 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_22 ) ;
F_8 ( L_21 ) ;
if ( V_118 && V_47 -> V_119 )
F_119 ( & V_117 ) ;
while ( ! F_84 () )
F_11 ( 1 ) ;
return 0 ;
}
static void
F_120 ( char * V_55 )
{
int V_56 ;
int V_40 ;
long V_120 [ V_44 + 1 ] = { 0 } ;
long V_121 [ V_44 + 1 ] = { 0 } ;
F_67 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_120 [ V_40 ] += F_121 ( V_114 , V_56 ) [ V_40 ] ;
V_121 [ V_40 ] += F_121 ( V_115 , V_56 ) [ V_40 ] ;
}
}
for ( V_40 = V_44 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( V_120 [ V_40 ] != 0 )
break;
}
V_55 += sprintf ( V_55 , L_23 , V_58 , V_59 ) ;
V_55 += sprintf ( V_55 ,
L_24 ,
V_93 ,
V_98 ,
F_14 ( & V_19 ) ,
F_102 ( & V_21 ) ,
F_102 ( & V_20 ) ,
F_102 ( & V_24 ) ) ;
V_55 += sprintf ( V_55 , L_25 ,
F_102 ( & V_110 ) ,
V_122 ,
V_76 ) ;
V_55 += sprintf ( V_55 , L_26 ,
V_81 ,
V_84 ,
V_112 ) ;
V_55 += sprintf ( V_55 ,
L_27 ,
V_123 , V_124 ,
V_125 , V_126 ,
V_127 , V_128 ,
V_129 , V_130 ,
V_131 , V_132 , V_34 ) ;
V_55 += sprintf ( V_55 , L_28 ,
V_133 ,
V_134 ,
V_135 ) ;
V_55 += sprintf ( V_55 , L_29 , V_58 , V_59 ) ;
if ( F_102 ( & V_110 ) != 0 ||
V_135 != 0 ||
V_122 != 0 ||
V_76 != 0 ||
V_81 != 0 ||
V_40 > 1 ) {
V_55 += sprintf ( V_55 , L_30 ) ;
F_15 ( & V_136 ) ;
F_122 ( 1 ) ;
}
V_55 += sprintf ( V_55 , L_31 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
V_55 += sprintf ( V_55 , L_32 , V_120 [ V_40 ] ) ;
V_55 += sprintf ( V_55 , L_29 , V_58 , V_59 ) ;
V_55 += sprintf ( V_55 , L_33 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
V_55 += sprintf ( V_55 , L_32 , V_121 [ V_40 ] ) ;
V_55 += sprintf ( V_55 , L_29 , V_58 , V_59 ) ;
V_55 += sprintf ( V_55 , L_34 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_55 += sprintf ( V_55 , L_35 ,
F_102 ( & V_45 [ V_40 ] ) ) ;
}
V_55 += sprintf ( V_55 , L_5 ) ;
if ( V_47 -> V_137 )
V_47 -> V_137 ( V_55 ) ;
}
static void
F_123 ( void )
{
int V_138 = V_139 * 200 + 8192 ;
char * V_140 ;
V_140 = F_124 ( V_138 , V_141 ) ;
if ( ! V_140 ) {
F_125 ( L_36 , V_138 ) ;
return;
}
F_120 ( V_140 ) ;
F_126 ( L_37 , V_140 ) ;
F_127 ( V_140 ) ;
}
static int
F_128 ( void * V_66 )
{
F_80 ( L_38 ) ;
do {
F_25 ( V_142 * V_34 ) ;
F_123 () ;
F_8 ( L_39 ) ;
} while ( ! F_84 () );
F_80 ( L_40 ) ;
return 0 ;
}
static void F_129 ( void )
{
int V_40 ;
F_130 ( V_143 ) ;
F_131 () ;
if ( F_132 () == 1 ) {
F_133 () ;
return;
}
if ( V_144 != - 1 )
F_134 ( V_144 , V_143 ) ;
F_135 ( V_74 , V_143 ) ;
if ( V_145 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ )
if ( V_145 [ V_40 ] )
F_135 ( V_145 [ V_40 ] ,
V_143 ) ;
}
if ( V_146 ) {
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ )
if ( V_146 [ V_40 ] )
F_135 ( V_146 [ V_40 ] ,
V_143 ) ;
}
if ( V_94 )
F_135 ( V_94 , V_143 ) ;
if ( V_147 )
F_135 ( V_147 , V_143 ) ;
if ( V_148 )
F_135 ( V_148 , V_143 ) ;
if ( V_149 )
F_135 ( V_149 , V_143 ) ;
if ( V_150 )
F_135 ( V_150 , V_143 ) ;
#ifdef F_136
if ( V_151 )
F_135 ( V_151 , V_143 ) ;
#endif
if ( V_152 )
F_135 ( V_152 , V_143 ) ;
if ( V_153 )
for ( V_40 = 0 ; V_40 < V_154 ; V_40 ++ )
if ( V_153 [ V_40 ] )
F_135 ( V_153 [ V_40 ] ,
V_143 ) ;
if ( V_155 )
F_135 ( V_155 , V_143 ) ;
if ( V_144 == - 1 )
V_144 = F_132 () - 1 ;
else
V_144 -- ;
F_133 () ;
}
static int
F_137 ( void * V_66 )
{
F_80 ( L_41 ) ;
do {
F_25 ( V_156 * V_34 ) ;
F_129 () ;
F_8 ( L_42 ) ;
} while ( ! F_84 () );
F_80 ( L_43 ) ;
return 0 ;
}
static int
F_138 ( void * V_66 )
{
F_80 ( L_44 ) ;
do {
F_25 ( V_157 * V_34 ) ;
V_32 = 1 ;
if ( ! F_84 () )
F_25 ( V_157 * V_34 ) ;
V_32 = 0 ;
F_8 ( L_45 ) ;
} while ( ! F_84 () );
F_80 ( L_46 ) ;
return 0 ;
}
static inline void
F_139 ( struct V_158 * V_47 , const char * V_159 )
{
F_126 ( L_37 V_59
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_58 , V_159 , V_37 , V_100 ,
V_142 , V_160 , V_161 , V_156 ,
V_157 , V_118 , V_88 , V_90 , V_87 ,
V_162 , V_47 -> V_163 ,
V_83 , V_80 , V_164 ,
V_165 , V_166 ,
V_154 ,
V_167 , V_168 ) ;
}
static void F_140 ( int V_56 )
{
struct V_169 * V_117 ;
if ( V_170 [ V_56 ] == NULL )
return;
F_5 ( & V_82 ) ;
F_80 ( L_56 ) ;
V_117 = V_170 [ V_56 ] ;
V_170 [ V_56 ] = NULL ;
F_7 ( & V_82 ) ;
F_141 ( V_117 ) ;
V_170 [ V_56 ] = NULL ;
}
static int F_142 ( int V_56 )
{
int V_171 ;
if ( V_170 [ V_56 ] != NULL )
return 0 ;
F_5 ( & V_82 ) ;
F_80 ( L_57 ) ;
V_170 [ V_56 ] = F_143 ( F_79 , NULL ,
F_144 ( V_56 ) ,
L_8 ) ;
if ( F_145 ( V_170 [ V_56 ] ) ) {
V_171 = F_146 ( V_170 [ V_56 ] ) ;
F_80 ( L_58 ) ;
V_122 ++ ;
V_170 [ V_56 ] = NULL ;
F_7 ( & V_82 ) ;
return V_171 ;
}
F_147 ( V_170 [ V_56 ] , V_56 ) ;
F_148 ( V_170 [ V_56 ] ) ;
F_7 ( & V_82 ) ;
return 0 ;
}
static int
F_149 ( void * V_66 )
{
long V_172 ;
unsigned long V_173 ;
F_80 ( L_59 ) ;
V_173 = F_9 ( V_78 ) ;
while ( F_83 ( V_173 , V_174 ) &&
! F_84 () ) {
V_172 = V_174 - V_173 ;
if ( V_160 )
F_126 ( L_37 V_59
L_60 ,
V_58 , V_172 ) ;
F_25 ( V_172 ) ;
V_173 = F_9 ( V_78 ) ;
}
if ( F_84 () ) {
F_80 ( L_61 ) ;
return 0 ;
}
F_80 ( L_62 ) ;
V_150 = NULL ;
F_150 () ;
F_151 () ;
return 0 ;
}
static int
F_152 ( void * V_66 )
{
int V_56 ;
unsigned long V_172 ;
int V_175 = - 1 ;
F_90 ( rand ) ;
int V_176 ;
unsigned long V_177 ;
F_80 ( L_63 ) ;
F_153 (cpu)
V_175 = V_56 ;
F_154 ( V_175 < 0 ) ;
if ( V_168 > 0 ) {
F_80 ( L_64 ) ;
F_25 ( V_168 * V_34 ) ;
F_80 ( L_65 ) ;
}
while ( ! F_84 () ) {
V_56 = ( F_21 ( & rand ) >> 4 ) % ( V_175 + 1 ) ;
if ( F_155 ( V_56 ) && F_156 ( V_56 ) ) {
if ( V_160 )
F_126 ( L_37 V_59
L_66 ,
V_58 , V_56 ) ;
V_177 = V_78 ;
V_126 ++ ;
V_176 = F_157 ( V_56 ) ;
if ( V_176 ) {
if ( V_160 )
F_126 ( L_37 V_59
L_67 ,
V_58 , V_56 , V_176 ) ;
} else {
if ( V_160 )
F_126 ( L_37 V_59
L_68 ,
V_58 , V_56 ) ;
V_125 ++ ;
V_172 = V_78 - V_177 ;
V_132 += V_172 ;
if ( V_129 < 0 ) {
V_129 = V_172 ;
V_130 = V_172 ;
}
if ( V_129 > V_172 )
V_129 = V_172 ;
if ( V_130 < V_172 )
V_130 = V_172 ;
}
} else if ( F_156 ( V_56 ) ) {
if ( V_160 )
F_126 ( L_37 V_59
L_69 ,
V_58 , V_56 ) ;
V_177 = V_78 ;
V_124 ++ ;
V_176 = F_158 ( V_56 ) ;
if ( V_176 ) {
if ( V_160 )
F_126 ( L_37 V_59
L_70 ,
V_58 , V_56 , V_176 ) ;
} else {
if ( V_160 )
F_126 ( L_37 V_59
L_71 ,
V_58 , V_56 ) ;
V_123 ++ ;
V_172 = V_78 - V_177 ;
V_131 += V_172 ;
if ( V_127 < 0 ) {
V_127 = V_172 ;
V_128 = V_172 ;
}
if ( V_127 > V_172 )
V_127 = V_172 ;
if ( V_128 < V_172 )
V_128 = V_172 ;
}
}
F_25 ( V_167 * V_34 ) ;
}
F_80 ( L_72 ) ;
return 0 ;
}
static int
F_159 ( void )
{
int V_176 ;
if ( V_167 <= 0 )
return 0 ;
V_151 = F_160 ( F_152 , NULL , L_73 ) ;
if ( F_145 ( V_151 ) ) {
V_176 = F_146 ( V_151 ) ;
V_151 = NULL ;
return V_176 ;
}
return 0 ;
}
static void F_161 ( void )
{
if ( V_151 == NULL )
return;
F_80 ( L_74 ) ;
F_141 ( V_151 ) ;
V_151 = NULL ;
}
static int
F_159 ( void )
{
return 0 ;
}
static void F_161 ( void )
{
}
static int F_162 ( void * args )
{
unsigned long V_178 ;
F_80 ( L_75 ) ;
if ( V_166 > 0 ) {
F_80 ( L_76 ) ;
F_25 ( V_166 * V_34 ) ;
F_80 ( L_77 ) ;
}
if ( ! F_84 () ) {
V_178 = F_163 () + V_165 ;
F_126 ( L_78 ) ;
F_28 () ;
F_72 () ;
while ( F_83 ( F_163 () , V_178 ) )
continue;
F_74 () ;
F_36 () ;
F_126 ( L_79 ) ;
}
F_8 ( L_80 ) ;
while ( ! F_84 () )
F_25 ( 10 * V_34 ) ;
return 0 ;
}
static int T_7 F_164 ( void )
{
int V_176 ;
if ( V_165 <= 0 )
return 0 ;
V_152 = F_160 ( F_162 , NULL , L_80 ) ;
if ( F_145 ( V_152 ) ) {
V_176 = F_146 ( V_152 ) ;
V_152 = NULL ;
return V_176 ;
}
return 0 ;
}
static void F_165 ( void )
{
if ( V_152 == NULL )
return;
F_80 ( L_81 ) ;
F_141 ( V_152 ) ;
V_152 = NULL ;
}
void F_166 ( struct V_39 * V_64 )
{
F_15 ( & V_179 ) ;
}
static int F_167 ( void * V_66 )
{
long V_180 = ( long ) V_66 ;
bool V_181 = 0 ;
bool V_182 ;
struct V_39 V_64 ;
F_82 ( & V_64 ) ;
F_80 ( L_82 ) ;
F_91 ( V_74 , 19 ) ;
do {
F_168 ( V_183 [ V_180 ] ,
( V_182 =
F_9 ( V_184 ) ) != V_181 ||
F_84 () ||
V_9 != V_10 ) ;
V_181 = V_182 ;
F_78 () ;
if ( F_84 () || V_9 != V_10 )
break;
V_47 -> V_185 ( & V_64 , F_166 ) ;
if ( F_169 ( & V_186 ) )
F_170 ( & V_187 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_83 ) ;
F_8 ( L_84 ) ;
while ( ! F_84 () )
F_25 ( 1 ) ;
V_47 -> V_99 () ;
F_87 ( & V_64 ) ;
return 0 ;
}
static int F_171 ( void * V_66 )
{
int V_40 ;
F_80 ( L_85 ) ;
do {
F_172 ( & V_179 , 0 ) ;
F_172 ( & V_186 , V_154 ) ;
F_78 () ;
V_184 = ! V_184 ;
for ( V_40 = 0 ; V_40 < V_154 ; V_40 ++ )
F_170 ( & V_183 [ V_40 ] ) ;
F_168 ( V_187 ,
F_102 ( & V_186 ) == 0 ||
F_84 () ||
V_9 != V_10 ) ;
if ( F_84 () || V_9 != V_10 )
break;
V_134 ++ ;
V_47 -> V_99 () ;
if ( F_102 ( & V_179 ) != V_154 ) {
V_135 ++ ;
F_122 ( 1 ) ;
}
V_133 ++ ;
F_25 ( V_34 / 10 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_86 ) ;
F_8 ( L_87 ) ;
while ( ! F_84 () )
F_25 ( 1 ) ;
return 0 ;
}
static int F_173 ( void )
{
int V_40 ;
int V_176 ;
if ( V_154 == 0 )
return 0 ;
if ( V_47 -> V_185 == NULL || V_47 -> V_99 == NULL ) {
F_126 ( L_37 V_59
L_88 ,
V_58 , V_47 -> V_113 ) ;
F_126 ( L_37 V_59
L_89 ,
V_58 ) ;
return 0 ;
}
F_172 ( & V_186 , 0 ) ;
F_172 ( & V_179 , 0 ) ;
V_153 =
F_174 ( V_154 * sizeof( V_153 [ 0 ] ) ,
V_141 ) ;
V_183 =
F_174 ( V_154 * sizeof( V_183 [ 0 ] ) ,
V_141 ) ;
if ( V_153 == NULL || ! V_183 )
return - V_188 ;
for ( V_40 = 0 ; V_40 < V_154 ; V_40 ++ ) {
F_175 ( & V_183 [ V_40 ] ) ;
V_153 [ V_40 ] = F_160 ( F_167 ,
( void * ) ( long ) V_40 ,
L_84 ) ;
if ( F_145 ( V_153 [ V_40 ] ) ) {
V_176 = F_146 ( V_153 [ V_40 ] ) ;
F_176 ( L_90 ) ;
V_153 [ V_40 ] = NULL ;
return V_176 ;
}
}
V_155 = F_160 ( F_171 , NULL ,
L_87 ) ;
if ( F_145 ( V_155 ) ) {
V_176 = F_146 ( V_155 ) ;
F_176 ( L_91 ) ;
V_155 = NULL ;
}
return 0 ;
}
static void F_177 ( void )
{
int V_40 ;
if ( V_155 != NULL ) {
F_80 ( L_92 ) ;
F_141 ( V_155 ) ;
V_155 = NULL ;
}
if ( V_153 != NULL ) {
for ( V_40 = 0 ; V_40 < V_154 ; V_40 ++ ) {
if ( V_153 [ V_40 ] != NULL ) {
F_80 ( L_93 ) ;
F_141 ( V_153 [ V_40 ] ) ;
V_153 [ V_40 ] = NULL ;
}
}
F_127 ( V_153 ) ;
V_153 = NULL ;
}
if ( V_183 != NULL ) {
F_127 ( V_183 ) ;
V_183 = NULL ;
}
}
static int F_178 ( struct V_4 * V_189 ,
unsigned long V_190 , void * V_191 )
{
long V_56 = ( long ) V_191 ;
switch ( V_190 ) {
case V_192 :
case V_193 :
( void ) F_142 ( V_56 ) ;
break;
case V_194 :
F_140 ( V_56 ) ;
break;
default:
break;
}
return V_195 ;
}
static void
F_150 ( void )
{
int V_40 ;
F_5 ( & V_8 ) ;
F_179 () ;
if ( V_9 == V_11 ) {
F_6 (
L_1 ) ;
F_7 ( & V_8 ) ;
F_11 ( 10 ) ;
if ( V_47 -> V_99 != NULL )
V_47 -> V_99 () ;
return;
}
V_9 = V_196 ;
F_7 ( & V_8 ) ;
F_180 ( & V_197 ) ;
F_177 () ;
F_165 () ;
if ( V_148 ) {
F_80 ( L_94 ) ;
F_141 ( V_148 ) ;
}
V_148 = NULL ;
if ( V_198 ) {
F_80 ( L_95 ) ;
F_141 ( V_198 ) ;
F_181 ( V_143 ) ;
}
V_198 = NULL ;
if ( V_94 ) {
F_80 ( L_96 ) ;
F_141 ( V_94 ) ;
}
V_94 = NULL ;
if ( V_145 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
if ( V_145 [ V_40 ] ) {
F_80 (
L_97 ) ;
F_141 ( V_145 [ V_40 ] ) ;
}
V_145 [ V_40 ] = NULL ;
}
F_127 ( V_145 ) ;
V_145 = NULL ;
}
V_93 = NULL ;
if ( V_146 ) {
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
if ( V_146 [ V_40 ] ) {
F_80 (
L_98 ) ;
F_141 ( V_146 [ V_40 ] ) ;
}
V_146 [ V_40 ] = NULL ;
}
F_127 ( V_146 ) ;
V_146 = NULL ;
}
if ( V_147 ) {
F_80 ( L_99 ) ;
F_141 ( V_147 ) ;
}
V_147 = NULL ;
if ( V_149 ) {
F_80 ( L_100 ) ;
F_141 ( V_149 ) ;
}
V_149 = NULL ;
if ( ( V_162 == 1 && V_47 -> V_163 ) ||
V_162 == 2 ) {
F_182 ( & V_199 ) ;
F_67 (i)
F_140 ( V_40 ) ;
}
if ( V_150 != NULL ) {
F_80 ( L_101 ) ;
F_141 ( V_150 ) ;
}
V_150 = NULL ;
F_161 () ;
if ( V_47 -> V_99 != NULL )
V_47 -> V_99 () ;
F_123 () ;
if ( F_102 ( & V_136 ) || V_135 )
F_139 ( V_47 , L_102 ) ;
else if ( V_123 != V_124 ||
V_125 != V_126 )
F_139 ( V_47 ,
L_103 ) ;
else
F_139 ( V_47 , L_104 ) ;
}
static void F_183 ( struct V_39 * V_200 )
{
}
static void F_184 ( struct V_39 * V_200 )
{
F_126 ( L_105 ) ;
}
static void F_185 ( void )
{
#ifdef F_186
struct V_39 V_201 ;
struct V_39 V_202 ;
F_82 ( & V_201 ) ;
F_82 ( & V_202 ) ;
F_126 ( L_106 ) ;
F_72 () ;
F_28 () ;
F_42 ( & V_201 , F_183 ) ;
F_187 () ;
F_42 ( & V_202 , F_183 ) ;
F_42 ( & V_202 , F_184 ) ;
F_188 () ;
F_36 () ;
F_74 () ;
F_189 () ;
F_126 ( L_107 ) ;
F_87 ( & V_201 ) ;
F_87 ( & V_202 ) ;
#else
F_126 ( L_108 ) ;
#endif
}
static int T_7
F_190 ( void )
{
int V_40 ;
int V_56 ;
int V_203 = 0 ;
int V_171 ;
static struct V_158 * V_204 [] = {
& V_205 , & V_206 , & V_207 , & V_208 ,
} ;
F_5 ( & V_8 ) ;
for ( V_40 = 0 ; V_40 < F_191 ( V_204 ) ; V_40 ++ ) {
V_47 = V_204 [ V_40 ] ;
if ( strcmp ( V_58 , V_47 -> V_113 ) == 0 )
break;
}
if ( V_40 == F_191 ( V_204 ) ) {
F_126 ( L_109 ,
V_58 ) ;
F_126 ( L_110 ) ;
for ( V_40 = 0 ; V_40 < F_191 ( V_204 ) ; V_40 ++ )
F_126 ( L_111 , V_204 [ V_40 ] -> V_113 ) ;
F_126 ( L_5 ) ;
F_7 ( & V_8 ) ;
return - V_209 ;
}
if ( V_47 -> V_89 == NULL && V_88 != 0 ) {
F_126 ( L_112 ) ;
V_88 = 0 ;
}
if ( V_47 -> V_210 )
V_47 -> V_210 () ;
if ( V_211 >= 0 )
V_37 = V_211 ;
else
V_37 = 2 * F_132 () ;
F_139 ( V_47 , L_113 ) ;
V_9 = V_10 ;
F_44 ( & V_19 ) ;
for ( V_40 = 0 ; V_40 < F_191 ( V_212 ) ; V_40 ++ ) {
V_212 [ V_40 ] . V_46 = 0 ;
F_20 ( & V_212 [ V_40 ] . V_23 ,
& V_19 ) ;
}
V_93 = NULL ;
V_98 = 0 ;
F_172 ( & V_21 , 0 ) ;
F_172 ( & V_20 , 0 ) ;
F_172 ( & V_24 , 0 ) ;
F_172 ( & V_110 , 0 ) ;
F_172 ( & V_136 , 0 ) ;
V_135 = 0 ;
V_122 = 0 ;
V_76 = 0 ;
V_81 = 0 ;
V_84 = 0 ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
F_172 ( & V_45 [ V_40 ] , 0 ) ;
F_67 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
F_121 ( V_114 , V_56 ) [ V_40 ] = 0 ;
F_121 ( V_115 , V_56 ) [ V_40 ] = 0 ;
}
}
F_80 ( L_114 ) ;
V_94 = F_192 ( F_89 , NULL ,
L_15 ) ;
if ( F_145 ( V_94 ) ) {
V_203 = F_146 ( V_94 ) ;
F_176 ( L_115 ) ;
V_94 = NULL ;
goto V_213;
}
F_148 ( V_94 ) ;
V_146 = F_174 ( V_100 * sizeof( V_146 [ 0 ] ) ,
V_141 ) ;
if ( V_146 == NULL ) {
F_176 ( L_116 ) ;
V_203 = - V_188 ;
goto V_213;
}
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
F_80 ( L_117 ) ;
V_146 [ V_40 ] = F_160 ( F_99 , NULL ,
L_18 ) ;
if ( F_145 ( V_146 [ V_40 ] ) ) {
V_203 = F_146 ( V_146 [ V_40 ] ) ;
F_176 ( L_118 ) ;
V_146 [ V_40 ] = NULL ;
goto V_213;
}
}
V_145 = F_174 ( V_37 * sizeof( V_145 [ 0 ] ) ,
V_141 ) ;
if ( V_145 == NULL ) {
F_176 ( L_116 ) ;
V_203 = - V_188 ;
goto V_213;
}
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
F_80 ( L_119 ) ;
V_145 [ V_40 ] = F_160 ( F_114 , NULL ,
L_21 ) ;
if ( F_145 ( V_145 [ V_40 ] ) ) {
V_203 = F_146 ( V_145 [ V_40 ] ) ;
F_176 ( L_120 ) ;
V_145 [ V_40 ] = NULL ;
goto V_213;
}
}
if ( V_142 > 0 ) {
F_80 ( L_121 ) ;
V_147 = F_160 ( F_128 , NULL ,
L_39 ) ;
if ( F_145 ( V_147 ) ) {
V_203 = F_146 ( V_147 ) ;
F_176 ( L_122 ) ;
V_147 = NULL ;
goto V_213;
}
}
if ( V_161 ) {
V_144 = F_132 () - 1 ;
if ( ! F_193 ( & V_143 , V_141 ) ) {
V_203 = - V_188 ;
F_176 ( L_123 ) ;
goto V_213;
}
V_198 = F_160 ( F_137 , NULL ,
L_42 ) ;
if ( F_145 ( V_198 ) ) {
F_181 ( V_143 ) ;
V_203 = F_146 ( V_198 ) ;
F_176 ( L_124 ) ;
V_198 = NULL ;
goto V_213;
}
}
if ( V_157 < 0 )
V_157 = 0 ;
if ( V_157 ) {
V_148 = F_160 ( F_138 , NULL ,
L_45 ) ;
if ( F_145 ( V_148 ) ) {
V_203 = F_146 ( V_148 ) ;
F_176 ( L_125 ) ;
V_148 = NULL ;
goto V_213;
}
}
if ( V_88 < 0 )
V_88 = 0 ;
if ( V_88 ) {
V_149 = F_160 ( F_88 , NULL ,
L_12 ) ;
if ( F_145 ( V_149 ) ) {
V_203 = F_146 ( V_149 ) ;
F_176 ( L_126 ) ;
V_149 = NULL ;
goto V_213;
}
}
if ( V_83 < 1 )
V_83 = 1 ;
if ( V_80 < 2 )
V_80 = 2 ;
if ( ( V_162 == 1 && V_47 -> V_163 ) ||
V_162 == 2 ) {
V_77 = V_78 + V_83 * V_34 ;
F_194 ( & V_199 ) ;
F_67 (i) {
if ( F_195 ( V_40 ) )
continue;
V_171 = F_142 ( V_40 ) ;
if ( V_171 < 0 ) {
V_203 = V_171 ;
goto V_213;
}
}
}
if ( V_164 > 0 ) {
V_174 = V_78 + V_164 * V_34 ;
V_150 = F_192 ( F_149 , NULL ,
L_127 ) ;
if ( F_145 ( V_150 ) ) {
V_203 = F_146 ( V_150 ) ;
F_176 ( L_128 ) ;
V_150 = NULL ;
goto V_213;
}
F_148 ( V_150 ) ;
}
V_40 = F_159 () ;
if ( V_40 != 0 ) {
V_203 = V_40 ;
goto V_213;
}
F_196 ( & V_197 ) ;
V_40 = F_164 () ;
if ( V_40 != 0 ) {
V_203 = V_40 ;
goto V_213;
}
V_171 = F_173 () ;
if ( V_171 != 0 ) {
V_203 = V_171 ;
goto V_213;
}
if ( V_214 )
F_185 () ;
F_179 () ;
F_7 ( & V_8 ) ;
return 0 ;
V_213:
F_7 ( & V_8 ) ;
F_150 () ;
return V_203 ;
}
