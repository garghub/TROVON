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
static int F_66 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_38 = V_53 . V_58 & 0x1 ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_3 ,
V_59 , V_60 , V_38 ) ;
F_67 (cpu) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_4 , V_57 ,
F_68 ( V_53 . V_61 , V_57 ) -> V_62 [ ! V_38 ] ,
F_68 ( V_53 . V_61 , V_57 ) -> V_62 [ V_38 ] ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
return V_56 ;
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
struct V_63 * V_64 =
F_18 ( V_54 , struct V_63 , V_65 ) ;
F_78 () ;
V_64 -> V_66 = 0 ;
}
static int F_79 ( void * V_67 )
{
unsigned long V_68 ;
unsigned long V_69 ;
unsigned long V_70 ;
struct V_63 V_71 = { . V_66 = 0 } ;
struct V_72 V_73 ;
F_80 ( L_6 ) ;
V_73 . V_74 = 1 ;
if ( F_81 ( V_75 , V_76 , & V_73 ) < 0 ) {
F_80 ( L_7 ) ;
V_77 ++ ;
}
F_82 ( & V_71 . V_65 ) ;
do {
V_70 = V_78 ;
while ( F_83 ( V_79 , V_70 ) ) {
F_25 ( V_70 - V_79 ) ;
F_24 ( L_8 ) ;
if ( F_84 () ||
V_9 != V_10 )
goto V_80;
}
V_69 = V_70 + V_81 * V_34 ;
V_68 = V_79 ;
while ( F_83 ( V_79 , V_69 ) ) {
if ( ! V_71 . V_66 ) {
F_78 () ;
V_71 . V_66 = 1 ;
F_42 ( & V_71 . V_65 , F_77 ) ;
if ( V_79 - V_68 >
V_81 * V_34 - V_34 / 2 ) {
F_80 ( L_9 ) ;
V_82 ++ ;
}
V_68 = V_79 ;
}
F_85 () ;
F_24 ( L_8 ) ;
if ( F_84 () ||
V_9 != V_10 )
goto V_80;
}
while ( V_70 == V_78 &&
! F_84 () ) {
if ( F_86 ( & V_83 ) ) {
V_78 = V_79 +
V_84 * V_34 ;
V_85 ++ ;
F_7 ( & V_83 ) ;
break;
}
F_11 ( 1 ) ;
}
V_80: F_24 ( L_8 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_10 ) ;
F_8 ( L_8 ) ;
while ( ! F_84 () || V_71 . V_66 )
F_11 ( 1 ) ;
F_78 () ;
F_87 ( & V_71 . V_65 ) ;
return 0 ;
}
static int
F_88 ( void * V_67 )
{
unsigned long V_86 ;
int V_87 ;
F_80 ( L_11 ) ;
do {
V_86 = V_79 + V_88 * V_34 ;
while ( F_83 ( V_79 , V_86 ) &&
! F_84 () ) {
F_25 ( 1 ) ;
}
V_87 = V_89 ;
while ( V_87 > 0 &&
! F_84 () ) {
V_47 -> V_90 () ;
F_31 ( V_91 ) ;
V_87 -= V_91 ;
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
F_89 ( void * V_67 )
{
bool exp ;
int V_40 ;
struct V_15 * V_41 ;
struct V_15 * V_92 ;
struct V_15 * V_93 ;
static F_90 ( rand ) ;
F_80 ( L_14 ) ;
F_91 ( V_75 , 19 ) ;
do {
F_11 ( 1 ) ;
V_41 = F_12 () ;
if ( V_41 == NULL )
continue;
V_41 -> V_43 = 0 ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
V_93 = F_92 ( V_94 ,
V_75 == V_95 ) ;
V_41 -> V_46 = 1 ;
F_93 ( V_94 , V_41 ) ;
F_94 () ;
if ( V_93 ) {
V_40 = V_93 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
V_93 -> V_43 ++ ;
if ( V_96 == V_97 )
exp = ! ! ( F_21 ( & rand ) & 0x80 ) ;
else
exp = V_97 ;
if ( ! exp ) {
V_47 -> V_48 ( V_93 ) ;
} else {
V_47 -> V_98 () ;
F_95 ( & V_93 -> V_23 ,
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
F_98 ( ++ V_99 ) ;
F_24 ( L_15 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_16 ) ;
F_8 ( L_15 ) ;
while ( ! F_84 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_99 ( void * V_67 )
{
F_90 ( rand ) ;
F_80 ( L_17 ) ;
F_91 ( V_75 , 19 ) ;
do {
F_11 ( 1 + F_21 ( & rand ) % 10 ) ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
if ( V_47 -> V_100 != NULL &&
F_21 ( & rand ) % ( V_101 * 8 ) == 0 ) {
V_47 -> V_100 () ;
} else if ( V_96 == V_97 ) {
if ( F_21 ( & rand ) & 0x80 )
V_47 -> V_102 () ;
else
V_47 -> V_98 () ;
} else if ( V_96 ) {
V_47 -> V_102 () ;
} else {
V_47 -> V_98 () ;
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
static T_6 V_103 = F_101 ( 0 ) ;
if ( F_102 ( & V_103 ) )
return;
if ( F_103 ( & V_103 , 1 ) != 0 )
return;
F_104 ( V_104 ) ;
}
static void F_105 ( unsigned long V_105 )
{
int V_38 ;
int V_58 ;
int V_106 ;
static F_90 ( rand ) ;
static F_106 ( V_107 ) ;
struct V_15 * V_17 ;
int V_108 ;
unsigned long long V_1 ;
V_38 = V_47 -> V_109 () ;
V_58 = V_47 -> V_58 () ;
V_1 = F_1 () ;
V_17 = F_92 ( V_94 ,
F_107 () ||
F_108 () ||
F_109 ( & V_53 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_110 ( V_38 ) ;
return;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_111 ) ;
F_110 ( & V_107 ) ;
V_47 -> V_112 ( & rand ) ;
V_113 ++ ;
F_111 ( & V_107 ) ;
F_72 () ;
V_108 = V_17 -> V_43 ;
if ( V_108 > V_44 ) {
V_108 = V_44 ;
}
V_106 = V_47 -> V_58 () ;
if ( V_108 > 1 ) {
F_112 ( V_47 -> V_114 , & V_17 -> V_42 , V_1 ,
V_58 , V_106 ) ;
F_100 () ;
}
F_113 ( V_115 [ V_108 ] ) ;
V_58 = V_106 - V_58 ;
if ( V_58 > V_44 ) {
V_58 = V_44 ;
}
F_113 ( V_116 [ V_58 ] ) ;
F_74 () ;
V_47 -> V_110 ( V_38 ) ;
}
static int
F_114 ( void * V_67 )
{
int V_58 ;
int V_106 ;
int V_38 ;
F_90 ( rand ) ;
struct V_15 * V_17 ;
int V_108 ;
struct V_117 V_118 ;
unsigned long long V_1 ;
F_80 ( L_20 ) ;
F_91 ( V_75 , 19 ) ;
if ( V_119 && V_47 -> V_120 )
F_115 ( & V_118 , F_105 , 0 ) ;
do {
if ( V_119 && V_47 -> V_120 ) {
if ( ! F_116 ( & V_118 ) )
F_117 ( & V_118 , V_79 + 1 ) ;
}
V_38 = V_47 -> V_109 () ;
V_58 = V_47 -> V_58 () ;
V_1 = F_1 () ;
V_17 = F_92 ( V_94 ,
F_107 () ||
F_108 () ||
F_109 ( & V_53 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_110 ( V_38 ) ;
F_25 ( V_34 ) ;
continue;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_111 ) ;
V_47 -> V_112 ( & rand ) ;
F_72 () ;
V_108 = V_17 -> V_43 ;
if ( V_108 > V_44 ) {
V_108 = V_44 ;
}
V_106 = V_47 -> V_58 () ;
if ( V_108 > 1 ) {
F_112 ( V_47 -> V_114 , & V_17 -> V_42 ,
V_1 , V_58 , V_106 ) ;
F_100 () ;
}
F_113 ( V_115 [ V_108 ] ) ;
V_58 = V_106 - V_58 ;
if ( V_58 > V_44 ) {
V_58 = V_44 ;
}
F_113 ( V_116 [ V_58 ] ) ;
F_74 () ;
V_47 -> V_110 ( V_38 ) ;
F_118 () ;
F_24 ( L_21 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_22 ) ;
F_8 ( L_21 ) ;
if ( V_119 && V_47 -> V_120 )
F_119 ( & V_118 ) ;
while ( ! F_84 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_120 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_40 ;
long V_121 [ V_44 + 1 ] = { 0 } ;
long V_122 [ V_44 + 1 ] = { 0 } ;
F_67 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_121 [ V_40 ] += F_121 ( V_115 , V_57 ) [ V_40 ] ;
V_122 [ V_40 ] += F_121 ( V_116 , V_57 ) [ V_40 ] ;
}
}
for ( V_40 = V_44 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( V_121 [ V_40 ] != 0 )
break;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_23 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] ,
L_24 ,
V_94 ,
V_99 ,
F_14 ( & V_19 ) ,
F_102 ( & V_21 ) ,
F_102 ( & V_20 ) ,
F_102 ( & V_24 ) ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_25 ,
F_102 ( & V_111 ) ,
V_123 ,
V_77 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_26 ,
V_82 ,
V_85 ,
V_113 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] ,
L_27 ,
V_124 , V_125 ,
V_126 , V_127 ,
V_128 , V_129 ,
V_130 , V_131 ,
V_132 , V_133 , V_34 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_28 ,
V_134 ,
V_135 ,
V_136 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
if ( F_102 ( & V_111 ) != 0 ||
V_136 != 0 ||
V_123 != 0 ||
V_77 != 0 ||
V_82 != 0 ||
V_40 > 1 ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_30 ) ;
F_15 ( & V_137 ) ;
F_122 ( 1 ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_31 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
V_56 += sprintf ( & V_55 [ V_56 ] , L_32 , V_121 [ V_40 ] ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_33 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
V_56 += sprintf ( & V_55 [ V_56 ] , L_32 , V_122 [ V_40 ] ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_34 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_35 ,
F_102 ( & V_45 [ V_40 ] ) ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
if ( V_47 -> V_138 )
V_56 += V_47 -> V_138 ( & V_55 [ V_56 ] ) ;
return V_56 ;
}
static void
F_123 ( void )
{
int V_56 ;
V_56 = F_120 ( V_139 ) ;
F_124 ( L_36 , V_139 ) ;
}
static int
F_125 ( void * V_67 )
{
F_80 ( L_37 ) ;
do {
F_25 ( V_140 * V_34 ) ;
F_123 () ;
F_8 ( L_38 ) ;
} while ( ! F_84 () );
F_80 ( L_39 ) ;
return 0 ;
}
static void F_126 ( void )
{
int V_40 ;
F_127 ( V_141 ) ;
F_128 () ;
if ( F_129 () == 1 ) {
F_130 () ;
return;
}
if ( V_142 != - 1 )
F_131 ( V_142 , V_141 ) ;
F_132 ( V_75 , V_141 ) ;
if ( V_143 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ )
if ( V_143 [ V_40 ] )
F_132 ( V_143 [ V_40 ] ,
V_141 ) ;
}
if ( V_144 ) {
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ )
if ( V_144 [ V_40 ] )
F_132 ( V_144 [ V_40 ] ,
V_141 ) ;
}
if ( V_95 )
F_132 ( V_95 , V_141 ) ;
if ( V_145 )
F_132 ( V_145 , V_141 ) ;
if ( V_146 )
F_132 ( V_146 , V_141 ) ;
if ( V_147 )
F_132 ( V_147 , V_141 ) ;
if ( V_148 )
F_132 ( V_148 , V_141 ) ;
#ifdef F_133
if ( V_149 )
F_132 ( V_149 , V_141 ) ;
#endif
if ( V_150 )
F_132 ( V_150 , V_141 ) ;
if ( V_151 )
for ( V_40 = 0 ; V_40 < V_152 ; V_40 ++ )
if ( V_151 [ V_40 ] )
F_132 ( V_151 [ V_40 ] ,
V_141 ) ;
if ( V_153 )
F_132 ( V_153 , V_141 ) ;
if ( V_142 == - 1 )
V_142 = F_129 () - 1 ;
else
V_142 -- ;
F_130 () ;
}
static int
F_134 ( void * V_67 )
{
F_80 ( L_40 ) ;
do {
F_25 ( V_154 * V_34 ) ;
F_126 () ;
F_8 ( L_41 ) ;
} while ( ! F_84 () );
F_80 ( L_42 ) ;
return 0 ;
}
static int
F_135 ( void * V_67 )
{
F_80 ( L_43 ) ;
do {
F_25 ( V_155 * V_34 ) ;
V_32 = 1 ;
if ( ! F_84 () )
F_25 ( V_155 * V_34 ) ;
V_32 = 0 ;
F_8 ( L_44 ) ;
} while ( ! F_84 () );
F_80 ( L_45 ) ;
return 0 ;
}
static inline void
F_136 ( struct V_156 * V_47 , const char * V_157 )
{
F_124 ( L_36 V_60
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_59 , V_157 , V_37 , V_101 ,
V_140 , V_158 , V_159 , V_154 ,
V_155 , V_119 , V_89 , V_91 , V_88 ,
V_160 , V_47 -> V_161 ,
V_84 , V_81 , V_162 ,
V_163 , V_164 ,
V_152 ,
V_165 , V_166 ) ;
}
static void F_137 ( int V_57 )
{
struct V_167 * V_118 ;
if ( V_168 [ V_57 ] == NULL )
return;
F_5 ( & V_83 ) ;
F_80 ( L_55 ) ;
V_118 = V_168 [ V_57 ] ;
V_168 [ V_57 ] = NULL ;
F_7 ( & V_83 ) ;
F_138 ( V_118 ) ;
V_168 [ V_57 ] = NULL ;
}
static int F_139 ( int V_57 )
{
int V_169 ;
if ( V_168 [ V_57 ] != NULL )
return 0 ;
F_5 ( & V_83 ) ;
F_80 ( L_56 ) ;
V_168 [ V_57 ] = F_140 ( F_79 , NULL ,
F_141 ( V_57 ) ,
L_8 ) ;
if ( F_142 ( V_168 [ V_57 ] ) ) {
V_169 = F_143 ( V_168 [ V_57 ] ) ;
F_80 ( L_57 ) ;
V_123 ++ ;
V_168 [ V_57 ] = NULL ;
F_7 ( & V_83 ) ;
return V_169 ;
}
F_144 ( V_168 [ V_57 ] , V_57 ) ;
F_145 ( V_168 [ V_57 ] ) ;
F_7 ( & V_83 ) ;
return 0 ;
}
static int
F_146 ( void * V_67 )
{
long V_170 ;
unsigned long V_171 ;
F_80 ( L_58 ) ;
V_171 = F_9 ( V_79 ) ;
while ( F_83 ( V_171 , V_172 ) &&
! F_84 () ) {
V_170 = V_172 - V_171 ;
if ( V_158 )
F_124 ( L_36 V_60
L_59 ,
V_59 , V_170 ) ;
F_25 ( V_170 ) ;
V_171 = F_9 ( V_79 ) ;
}
if ( F_84 () ) {
F_80 ( L_60 ) ;
return 0 ;
}
F_80 ( L_61 ) ;
V_148 = NULL ;
F_147 () ;
F_148 () ;
return 0 ;
}
static int
F_149 ( void * V_67 )
{
int V_57 ;
unsigned long V_170 ;
int V_173 = - 1 ;
F_90 ( rand ) ;
int V_174 ;
unsigned long V_175 ;
F_80 ( L_62 ) ;
F_150 (cpu)
V_173 = V_57 ;
F_151 ( V_173 < 0 ) ;
if ( V_166 > 0 ) {
F_80 ( L_63 ) ;
F_25 ( V_166 * V_34 ) ;
F_80 ( L_64 ) ;
}
while ( ! F_84 () ) {
V_57 = ( F_21 ( & rand ) >> 4 ) % ( V_173 + 1 ) ;
if ( F_152 ( V_57 ) && F_153 ( V_57 ) ) {
if ( V_158 )
F_124 ( L_36 V_60
L_65 ,
V_59 , V_57 ) ;
V_175 = V_79 ;
V_127 ++ ;
V_174 = F_154 ( V_57 ) ;
if ( V_174 ) {
if ( V_158 )
F_124 ( L_36 V_60
L_66 ,
V_59 , V_57 , V_174 ) ;
} else {
if ( V_158 )
F_124 ( L_36 V_60
L_67 ,
V_59 , V_57 ) ;
V_126 ++ ;
V_170 = V_79 - V_175 ;
V_133 += V_170 ;
if ( V_130 < 0 ) {
V_130 = V_170 ;
V_131 = V_170 ;
}
if ( V_130 > V_170 )
V_130 = V_170 ;
if ( V_131 < V_170 )
V_131 = V_170 ;
}
} else if ( F_153 ( V_57 ) ) {
if ( V_158 )
F_124 ( L_36 V_60
L_68 ,
V_59 , V_57 ) ;
V_175 = V_79 ;
V_125 ++ ;
V_174 = F_155 ( V_57 ) ;
if ( V_174 ) {
if ( V_158 )
F_124 ( L_36 V_60
L_69 ,
V_59 , V_57 , V_174 ) ;
} else {
if ( V_158 )
F_124 ( L_36 V_60
L_70 ,
V_59 , V_57 ) ;
V_124 ++ ;
V_170 = V_79 - V_175 ;
V_132 += V_170 ;
if ( V_128 < 0 ) {
V_128 = V_170 ;
V_129 = V_170 ;
}
if ( V_128 > V_170 )
V_128 = V_170 ;
if ( V_129 < V_170 )
V_129 = V_170 ;
}
}
F_25 ( V_165 * V_34 ) ;
}
F_80 ( L_71 ) ;
return 0 ;
}
static int
F_156 ( void )
{
int V_174 ;
if ( V_165 <= 0 )
return 0 ;
V_149 = F_157 ( F_149 , NULL , L_72 ) ;
if ( F_142 ( V_149 ) ) {
V_174 = F_143 ( V_149 ) ;
V_149 = NULL ;
return V_174 ;
}
return 0 ;
}
static void F_158 ( void )
{
if ( V_149 == NULL )
return;
F_80 ( L_73 ) ;
F_138 ( V_149 ) ;
V_149 = NULL ;
}
static int
F_156 ( void )
{
return 0 ;
}
static void F_158 ( void )
{
}
static int F_159 ( void * args )
{
unsigned long V_176 ;
F_80 ( L_74 ) ;
if ( V_164 > 0 ) {
F_80 ( L_75 ) ;
F_25 ( V_164 * V_34 ) ;
F_80 ( L_76 ) ;
}
if ( ! F_84 () ) {
V_176 = F_160 () + V_163 ;
F_124 ( L_77 ) ;
F_28 () ;
F_72 () ;
while ( F_83 ( F_160 () , V_176 ) )
continue;
F_74 () ;
F_36 () ;
F_124 ( L_78 ) ;
}
F_8 ( L_79 ) ;
while ( ! F_84 () )
F_25 ( 10 * V_34 ) ;
return 0 ;
}
static int T_7 F_161 ( void )
{
int V_174 ;
if ( V_163 <= 0 )
return 0 ;
V_150 = F_157 ( F_159 , NULL , L_79 ) ;
if ( F_142 ( V_150 ) ) {
V_174 = F_143 ( V_150 ) ;
V_150 = NULL ;
return V_174 ;
}
return 0 ;
}
static void F_162 ( void )
{
if ( V_150 == NULL )
return;
F_80 ( L_80 ) ;
F_138 ( V_150 ) ;
V_150 = NULL ;
}
void F_163 ( struct V_39 * V_65 )
{
F_15 ( & V_177 ) ;
}
static int F_164 ( void * V_67 )
{
long V_178 = ( long ) V_67 ;
bool V_179 = 0 ;
struct V_39 V_65 ;
F_82 ( & V_65 ) ;
F_80 ( L_81 ) ;
F_91 ( V_75 , 19 ) ;
do {
F_165 ( V_180 [ V_178 ] ,
V_181 != V_179 ||
F_84 () ||
V_9 != V_10 ) ;
V_179 = V_181 ;
F_78 () ;
if ( F_84 () || V_9 != V_10 )
break;
V_47 -> V_182 ( & V_65 , F_163 ) ;
if ( F_166 ( & V_183 ) )
F_167 ( & V_184 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_82 ) ;
F_8 ( L_83 ) ;
while ( ! F_84 () )
F_25 ( 1 ) ;
V_47 -> V_100 () ;
F_87 ( & V_65 ) ;
return 0 ;
}
static int F_168 ( void * V_67 )
{
int V_40 ;
F_80 ( L_84 ) ;
do {
F_169 ( & V_177 , 0 ) ;
F_169 ( & V_183 , V_152 ) ;
F_78 () ;
V_181 = ! V_181 ;
for ( V_40 = 0 ; V_40 < V_152 ; V_40 ++ )
F_167 ( & V_180 [ V_40 ] ) ;
F_165 ( V_184 ,
F_102 ( & V_183 ) == 0 ||
F_84 () ||
V_9 != V_10 ) ;
if ( F_84 () || V_9 != V_10 )
break;
V_135 ++ ;
V_47 -> V_100 () ;
if ( F_102 ( & V_177 ) != V_152 ) {
V_136 ++ ;
F_122 ( 1 ) ;
}
V_134 ++ ;
F_25 ( V_34 / 10 ) ;
} while ( ! F_84 () && V_9 == V_10 );
F_80 ( L_85 ) ;
F_8 ( L_86 ) ;
while ( ! F_84 () )
F_25 ( 1 ) ;
return 0 ;
}
static int F_170 ( void )
{
int V_40 ;
int V_174 ;
if ( V_152 == 0 )
return 0 ;
if ( V_47 -> V_182 == NULL || V_47 -> V_100 == NULL ) {
F_124 ( L_36 V_60
L_87 ,
V_59 , V_47 -> V_114 ) ;
F_124 ( L_36 V_60
L_88 ,
V_59 ) ;
return 0 ;
}
F_169 ( & V_183 , 0 ) ;
F_169 ( & V_177 , 0 ) ;
V_151 =
F_171 ( V_152 * sizeof( V_151 [ 0 ] ) ,
V_185 ) ;
V_180 =
F_171 ( V_152 * sizeof( V_180 [ 0 ] ) ,
V_185 ) ;
if ( V_151 == NULL || ! V_180 )
return - V_186 ;
for ( V_40 = 0 ; V_40 < V_152 ; V_40 ++ ) {
F_172 ( & V_180 [ V_40 ] ) ;
V_151 [ V_40 ] = F_157 ( F_164 ,
( void * ) ( long ) V_40 ,
L_83 ) ;
if ( F_142 ( V_151 [ V_40 ] ) ) {
V_174 = F_143 ( V_151 [ V_40 ] ) ;
F_173 ( L_89 ) ;
V_151 [ V_40 ] = NULL ;
return V_174 ;
}
}
V_153 = F_157 ( F_168 , NULL ,
L_86 ) ;
if ( F_142 ( V_153 ) ) {
V_174 = F_143 ( V_153 ) ;
F_173 ( L_90 ) ;
V_153 = NULL ;
}
return 0 ;
}
static void F_174 ( void )
{
int V_40 ;
if ( V_153 != NULL ) {
F_80 ( L_91 ) ;
F_138 ( V_153 ) ;
V_153 = NULL ;
}
if ( V_151 != NULL ) {
for ( V_40 = 0 ; V_40 < V_152 ; V_40 ++ ) {
if ( V_151 [ V_40 ] != NULL ) {
F_80 ( L_92 ) ;
F_138 ( V_151 [ V_40 ] ) ;
V_151 [ V_40 ] = NULL ;
}
}
F_175 ( V_151 ) ;
V_151 = NULL ;
}
if ( V_180 != NULL ) {
F_175 ( V_180 ) ;
V_180 = NULL ;
}
}
static int F_176 ( struct V_4 * V_187 ,
unsigned long V_188 , void * V_189 )
{
long V_57 = ( long ) V_189 ;
switch ( V_188 ) {
case V_190 :
case V_191 :
( void ) F_139 ( V_57 ) ;
break;
case V_192 :
F_137 ( V_57 ) ;
break;
default:
break;
}
return V_193 ;
}
static void
F_147 ( void )
{
int V_40 ;
F_5 ( & V_8 ) ;
F_177 () ;
if ( V_9 == V_11 ) {
F_6 (
L_1 ) ;
F_7 ( & V_8 ) ;
F_11 ( 10 ) ;
if ( V_47 -> V_100 != NULL )
V_47 -> V_100 () ;
return;
}
V_9 = V_194 ;
F_7 ( & V_8 ) ;
F_178 ( & V_195 ) ;
F_174 () ;
F_162 () ;
if ( V_146 ) {
F_80 ( L_93 ) ;
F_138 ( V_146 ) ;
}
V_146 = NULL ;
if ( V_196 ) {
F_80 ( L_94 ) ;
F_138 ( V_196 ) ;
F_179 ( V_141 ) ;
}
V_196 = NULL ;
if ( V_95 ) {
F_80 ( L_95 ) ;
F_138 ( V_95 ) ;
}
V_95 = NULL ;
if ( V_143 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
if ( V_143 [ V_40 ] ) {
F_80 (
L_96 ) ;
F_138 ( V_143 [ V_40 ] ) ;
}
V_143 [ V_40 ] = NULL ;
}
F_175 ( V_143 ) ;
V_143 = NULL ;
}
V_94 = NULL ;
if ( V_144 ) {
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
if ( V_144 [ V_40 ] ) {
F_80 (
L_97 ) ;
F_138 ( V_144 [ V_40 ] ) ;
}
V_144 [ V_40 ] = NULL ;
}
F_175 ( V_144 ) ;
V_144 = NULL ;
}
if ( V_145 ) {
F_80 ( L_98 ) ;
F_138 ( V_145 ) ;
}
V_145 = NULL ;
if ( V_147 ) {
F_80 ( L_99 ) ;
F_138 ( V_147 ) ;
}
V_147 = NULL ;
if ( ( V_160 == 1 && V_47 -> V_161 ) ||
V_160 == 2 ) {
F_180 ( & V_197 ) ;
F_67 (i)
F_137 ( V_40 ) ;
}
if ( V_148 != NULL ) {
F_80 ( L_100 ) ;
F_138 ( V_148 ) ;
}
V_148 = NULL ;
F_158 () ;
if ( V_47 -> V_100 != NULL )
V_47 -> V_100 () ;
F_123 () ;
if ( F_102 ( & V_137 ) || V_136 )
F_136 ( V_47 , L_101 ) ;
else if ( V_124 != V_125 ||
V_126 != V_127 )
F_136 ( V_47 ,
L_102 ) ;
else
F_136 ( V_47 , L_103 ) ;
}
static void F_181 ( struct V_39 * V_198 )
{
}
static void F_182 ( struct V_39 * V_198 )
{
F_124 ( L_104 ) ;
}
static void F_183 ( void )
{
#ifdef F_184
struct V_39 V_199 ;
struct V_39 V_200 ;
F_82 ( & V_199 ) ;
F_82 ( & V_200 ) ;
F_124 ( L_105 ) ;
F_72 () ;
F_28 () ;
F_42 ( & V_199 , F_181 ) ;
F_185 () ;
F_42 ( & V_200 , F_181 ) ;
F_42 ( & V_200 , F_182 ) ;
F_186 () ;
F_36 () ;
F_74 () ;
F_187 () ;
F_124 ( L_106 ) ;
F_87 ( & V_199 ) ;
F_87 ( & V_200 ) ;
#else
F_124 ( L_107 ) ;
#endif
}
static int T_7
F_188 ( void )
{
int V_40 ;
int V_57 ;
int V_201 = 0 ;
int V_169 ;
static struct V_156 * V_202 [] = {
& V_203 , & V_204 , & V_205 , & V_206 ,
} ;
F_5 ( & V_8 ) ;
for ( V_40 = 0 ; V_40 < F_189 ( V_202 ) ; V_40 ++ ) {
V_47 = V_202 [ V_40 ] ;
if ( strcmp ( V_59 , V_47 -> V_114 ) == 0 )
break;
}
if ( V_40 == F_189 ( V_202 ) ) {
F_124 ( L_108 ,
V_59 ) ;
F_124 ( L_109 ) ;
for ( V_40 = 0 ; V_40 < F_189 ( V_202 ) ; V_40 ++ )
F_124 ( L_110 , V_202 [ V_40 ] -> V_114 ) ;
F_124 ( L_5 ) ;
F_7 ( & V_8 ) ;
return - V_207 ;
}
if ( V_47 -> V_90 == NULL && V_89 != 0 ) {
F_124 ( L_111 ) ;
V_89 = 0 ;
}
if ( V_47 -> V_208 )
V_47 -> V_208 () ;
if ( V_209 >= 0 )
V_37 = V_209 ;
else
V_37 = 2 * F_129 () ;
F_136 ( V_47 , L_112 ) ;
V_9 = V_10 ;
F_44 ( & V_19 ) ;
for ( V_40 = 0 ; V_40 < F_189 ( V_210 ) ; V_40 ++ ) {
V_210 [ V_40 ] . V_46 = 0 ;
F_20 ( & V_210 [ V_40 ] . V_23 ,
& V_19 ) ;
}
V_94 = NULL ;
V_99 = 0 ;
F_169 ( & V_21 , 0 ) ;
F_169 ( & V_20 , 0 ) ;
F_169 ( & V_24 , 0 ) ;
F_169 ( & V_111 , 0 ) ;
F_169 ( & V_137 , 0 ) ;
V_136 = 0 ;
V_123 = 0 ;
V_77 = 0 ;
V_82 = 0 ;
V_85 = 0 ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
F_169 ( & V_45 [ V_40 ] , 0 ) ;
F_67 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
F_121 ( V_115 , V_57 ) [ V_40 ] = 0 ;
F_121 ( V_116 , V_57 ) [ V_40 ] = 0 ;
}
}
F_80 ( L_113 ) ;
V_95 = F_190 ( F_89 , NULL ,
L_15 ) ;
if ( F_142 ( V_95 ) ) {
V_201 = F_143 ( V_95 ) ;
F_173 ( L_114 ) ;
V_95 = NULL ;
goto V_211;
}
F_145 ( V_95 ) ;
V_144 = F_171 ( V_101 * sizeof( V_144 [ 0 ] ) ,
V_185 ) ;
if ( V_144 == NULL ) {
F_173 ( L_115 ) ;
V_201 = - V_186 ;
goto V_211;
}
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
F_80 ( L_116 ) ;
V_144 [ V_40 ] = F_157 ( F_99 , NULL ,
L_18 ) ;
if ( F_142 ( V_144 [ V_40 ] ) ) {
V_201 = F_143 ( V_144 [ V_40 ] ) ;
F_173 ( L_117 ) ;
V_144 [ V_40 ] = NULL ;
goto V_211;
}
}
V_143 = F_171 ( V_37 * sizeof( V_143 [ 0 ] ) ,
V_185 ) ;
if ( V_143 == NULL ) {
F_173 ( L_115 ) ;
V_201 = - V_186 ;
goto V_211;
}
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
F_80 ( L_118 ) ;
V_143 [ V_40 ] = F_157 ( F_114 , NULL ,
L_21 ) ;
if ( F_142 ( V_143 [ V_40 ] ) ) {
V_201 = F_143 ( V_143 [ V_40 ] ) ;
F_173 ( L_119 ) ;
V_143 [ V_40 ] = NULL ;
goto V_211;
}
}
if ( V_140 > 0 ) {
F_80 ( L_120 ) ;
V_145 = F_157 ( F_125 , NULL ,
L_38 ) ;
if ( F_142 ( V_145 ) ) {
V_201 = F_143 ( V_145 ) ;
F_173 ( L_121 ) ;
V_145 = NULL ;
goto V_211;
}
}
if ( V_159 ) {
V_142 = F_129 () - 1 ;
if ( ! F_191 ( & V_141 , V_185 ) ) {
V_201 = - V_186 ;
F_173 ( L_122 ) ;
goto V_211;
}
V_196 = F_157 ( F_134 , NULL ,
L_41 ) ;
if ( F_142 ( V_196 ) ) {
F_179 ( V_141 ) ;
V_201 = F_143 ( V_196 ) ;
F_173 ( L_123 ) ;
V_196 = NULL ;
goto V_211;
}
}
if ( V_155 < 0 )
V_155 = 0 ;
if ( V_155 ) {
V_146 = F_157 ( F_135 , NULL ,
L_44 ) ;
if ( F_142 ( V_146 ) ) {
V_201 = F_143 ( V_146 ) ;
F_173 ( L_124 ) ;
V_146 = NULL ;
goto V_211;
}
}
if ( V_89 < 0 )
V_89 = 0 ;
if ( V_89 ) {
V_147 = F_157 ( F_88 , NULL ,
L_12 ) ;
if ( F_142 ( V_147 ) ) {
V_201 = F_143 ( V_147 ) ;
F_173 ( L_125 ) ;
V_147 = NULL ;
goto V_211;
}
}
if ( V_84 < 1 )
V_84 = 1 ;
if ( V_81 < 2 )
V_81 = 2 ;
if ( ( V_160 == 1 && V_47 -> V_161 ) ||
V_160 == 2 ) {
V_78 = V_79 + V_84 * V_34 ;
F_192 ( & V_197 ) ;
F_67 (i) {
if ( F_193 ( V_40 ) )
continue;
V_169 = F_139 ( V_40 ) ;
if ( V_169 < 0 ) {
V_201 = V_169 ;
goto V_211;
}
}
}
if ( V_162 > 0 ) {
V_172 = V_79 + V_162 * V_34 ;
V_148 = F_190 ( F_146 , NULL ,
L_126 ) ;
if ( F_142 ( V_148 ) ) {
V_201 = F_143 ( V_148 ) ;
F_173 ( L_127 ) ;
V_148 = NULL ;
goto V_211;
}
F_145 ( V_148 ) ;
}
V_40 = F_156 () ;
if ( V_40 != 0 ) {
V_201 = V_40 ;
goto V_211;
}
F_194 ( & V_195 ) ;
V_40 = F_161 () ;
if ( V_40 != 0 ) {
V_201 = V_40 ;
goto V_211;
}
V_169 = F_170 () ;
if ( V_169 != 0 ) {
V_201 = V_169 ;
goto V_211;
}
if ( V_212 )
F_183 () ;
F_177 () ;
F_7 ( & V_8 ) ;
return 0 ;
V_211:
F_7 ( & V_8 ) ;
F_147 () ;
return V_201 ;
}
