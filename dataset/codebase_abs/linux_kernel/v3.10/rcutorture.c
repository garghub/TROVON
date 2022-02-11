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
static void F_8 ( char * V_13 )
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
F_24 ( char * V_13 )
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
static void F_43 ( struct V_15 * V_17 )
{
int V_40 ;
struct V_15 * V_41 ;
struct V_15 * V_49 ;
V_47 -> V_50 () ;
F_44 ( & V_17 -> V_23 , & V_51 ) ;
F_45 (rp, rp1, &rcu_torture_removed, rtort_free) {
V_40 = V_41 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
if ( ++ V_41 -> V_43 >= V_44 ) {
V_41 -> V_46 = 0 ;
F_46 ( & V_41 -> V_23 ) ;
F_19 ( V_41 ) ;
}
}
}
static void F_47 ( void )
{
F_48 ( & V_51 ) ;
}
static int F_49 ( void ) __acquires( T_5 )
{
F_50 () ;
return 0 ;
}
static void F_51 ( int V_38 ) __releases( T_5 )
{
F_52 () ;
}
static int F_53 ( void )
{
return F_54 () ;
}
static void F_55 ( struct V_15 * V_17 )
{
F_56 ( & V_17 -> V_42 , F_39 ) ;
}
static int F_57 ( void ) __acquires( &srcu_ctl
static void F_58 ( struct V_25 * V_26 )
{
long V_52 ;
const long V_53 = 1000000 / V_34 ;
const long V_54 = 10 ;
V_52 = F_21 ( V_26 ) % ( V_37 * 2 * V_54 * V_53 ) ;
if ( ! V_52 )
F_25 ( V_54 ) ;
else
F_29 ( V_26 ) ;
}
static void F_59 ( int V_38 ) __releases( &srcu_ctl
static int F_60 ( void )
{
return F_61 ( & V_55 ) ;
}
static void F_62 ( struct V_15 * V_41 )
{
F_63 ( & V_55 , & V_41 -> V_42 , F_39 ) ;
}
static void F_64 ( void )
{
F_65 ( & V_55 ) ;
}
static void F_66 ( struct V_39 * V_56 ,
void (* F_67)( struct V_39 * V_56 ) )
{
F_63 ( & V_55 , V_56 , F_67 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_55 ) ;
}
static int F_70 ( char * V_57 )
{
int V_58 = 0 ;
int V_59 ;
int V_38 = V_55 . V_60 & 0x1 ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_3 ,
V_61 , V_62 , V_38 ) ;
F_71 (cpu) {
V_58 += sprintf ( & V_57 [ V_58 ] , L_4 , V_59 ,
F_72 ( V_55 . V_63 , V_59 ) -> V_64 [ ! V_38 ] ,
F_72 ( V_55 . V_63 , V_59 ) -> V_64 [ V_38 ] ) ;
}
V_58 += sprintf ( & V_57 [ V_58 ] , L_5 ) ;
return V_58 ;
}
static int F_73 ( void ) __acquires( &srcu_ctl
static void F_74 ( int V_38 ) __releases( &srcu_ctl
static void F_75 ( void )
{
F_76 ( & V_55 ) ;
}
static int F_77 ( void )
{
F_78 () ;
return 0 ;
}
static void F_79 ( int V_38 )
{
F_80 () ;
}
static void F_81 ( struct V_15 * V_17 )
{
F_82 ( & V_17 -> V_42 , F_39 ) ;
}
static void F_83 ( struct V_39 * V_56 )
{
struct V_65 * V_66 =
F_18 ( V_56 , struct V_65 , V_67 ) ;
F_84 () ;
V_66 -> V_68 = 0 ;
}
static int F_85 ( void * V_69 )
{
unsigned long V_70 ;
unsigned long V_71 ;
unsigned long V_72 ;
struct V_65 V_73 = { . V_68 = 0 } ;
struct V_74 V_75 ;
F_86 ( L_6 ) ;
V_75 . V_76 = 1 ;
if ( F_87 ( V_77 , V_78 , & V_75 ) < 0 ) {
F_86 ( L_7 ) ;
V_79 ++ ;
}
F_88 ( & V_73 . V_67 ) ;
do {
V_72 = V_80 ;
while ( F_89 ( V_81 , V_72 ) ) {
F_25 ( V_72 - V_81 ) ;
F_24 ( L_8 ) ;
if ( F_90 () ||
V_9 != V_10 )
goto V_82;
}
V_71 = V_72 + V_83 * V_34 ;
V_70 = V_81 ;
while ( F_89 ( V_81 , V_71 ) ) {
if ( ! V_73 . V_68 ) {
F_84 () ;
V_73 . V_68 = 1 ;
F_42 ( & V_73 . V_67 , F_83 ) ;
if ( V_81 - V_70 >
V_83 * V_34 - V_34 / 2 ) {
F_86 ( L_9 ) ;
V_84 ++ ;
}
V_70 = V_81 ;
}
F_91 () ;
F_24 ( L_8 ) ;
if ( F_90 () ||
V_9 != V_10 )
goto V_82;
}
while ( V_72 == V_80 &&
! F_90 () ) {
if ( F_92 ( & V_85 ) ) {
V_80 = V_81 +
V_86 * V_34 ;
V_87 ++ ;
F_7 ( & V_85 ) ;
break;
}
F_11 ( 1 ) ;
}
V_82: F_24 ( L_8 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_10 ) ;
F_8 ( L_8 ) ;
while ( ! F_90 () || V_73 . V_68 )
F_11 ( 1 ) ;
F_84 () ;
F_93 ( & V_73 . V_67 ) ;
return 0 ;
}
static int
F_94 ( void * V_69 )
{
unsigned long V_88 ;
int V_89 ;
F_86 ( L_11 ) ;
do {
V_88 = V_81 + V_90 * V_34 ;
while ( F_89 ( V_81 , V_88 ) &&
! F_90 () ) {
F_25 ( 1 ) ;
}
V_89 = V_91 ;
while ( V_89 > 0 &&
! F_90 () ) {
V_47 -> V_92 () ;
F_31 ( V_93 ) ;
V_89 -= V_93 ;
}
F_24 ( L_12 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_13 ) ;
F_8 ( L_12 ) ;
while ( ! F_90 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_95 ( void * V_69 )
{
int V_40 ;
long V_94 = F_38 () ;
struct V_15 * V_41 ;
struct V_15 * V_95 ;
static F_96 ( rand ) ;
F_86 ( L_14 ) ;
F_97 ( V_77 , 19 ) ;
do {
F_11 ( 1 ) ;
V_41 = F_12 () ;
if ( V_41 == NULL )
continue;
V_41 -> V_43 = 0 ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
V_95 = F_98 ( V_96 ,
V_77 == V_97 ) ;
V_41 -> V_46 = 1 ;
F_99 ( V_96 , V_41 ) ;
F_100 () ;
if ( V_95 ) {
V_40 = V_95 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
V_95 -> V_43 ++ ;
V_47 -> V_48 ( V_95 ) ;
}
F_101 ( ++ V_98 ) ;
V_94 = V_47 -> V_60 () ;
F_24 ( L_15 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_16 ) ;
F_8 ( L_15 ) ;
while ( ! F_90 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_102 ( void * V_69 )
{
F_96 ( rand ) ;
F_86 ( L_17 ) ;
F_97 ( V_77 , 19 ) ;
do {
F_11 ( 1 + F_21 ( & rand ) % 10 ) ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
if ( V_47 -> V_99 != NULL &&
F_21 ( & rand ) % ( V_100 * 8 ) == 0 )
V_47 -> V_99 () ;
else
V_47 -> V_50 () ;
F_24 ( L_18 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_19 ) ;
F_8 ( L_18 ) ;
while ( ! F_90 () )
F_11 ( 1 ) ;
return 0 ;
}
void F_103 ( void )
{
static T_6 V_101 = F_104 ( 0 ) ;
if ( F_105 ( & V_101 ) )
return;
if ( F_106 ( & V_101 , 1 ) != 0 )
return;
F_107 ( V_102 ) ;
}
static void F_108 ( unsigned long V_103 )
{
int V_38 ;
int V_60 ;
int V_104 ;
static F_96 ( rand ) ;
static F_109 ( V_105 ) ;
struct V_15 * V_17 ;
int V_106 ;
unsigned long long V_1 ;
V_38 = V_47 -> V_107 () ;
V_60 = V_47 -> V_60 () ;
V_1 = F_1 () ;
V_17 = F_98 ( V_96 ,
F_110 () ||
F_111 () ||
F_112 ( & V_55 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_108 ( V_38 ) ;
return;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_109 ) ;
F_113 ( & V_105 ) ;
V_47 -> V_110 ( & rand ) ;
V_111 ++ ;
F_114 ( & V_105 ) ;
F_78 () ;
V_106 = V_17 -> V_43 ;
if ( V_106 > V_44 ) {
V_106 = V_44 ;
}
V_104 = V_47 -> V_60 () ;
if ( V_106 > 1 ) {
F_115 ( V_47 -> V_112 , & V_17 -> V_42 , V_1 ,
V_60 , V_104 ) ;
F_103 () ;
}
F_116 ( V_113 [ V_106 ] ) ;
V_60 = V_104 - V_60 ;
if ( V_60 > V_44 ) {
V_60 = V_44 ;
}
F_116 ( V_114 [ V_60 ] ) ;
F_80 () ;
V_47 -> V_108 ( V_38 ) ;
}
static int
F_117 ( void * V_69 )
{
int V_60 ;
int V_104 ;
int V_38 ;
F_96 ( rand ) ;
struct V_15 * V_17 ;
int V_106 ;
struct V_115 V_116 ;
unsigned long long V_1 ;
F_86 ( L_20 ) ;
F_97 ( V_77 , 19 ) ;
if ( V_117 && V_47 -> V_118 )
F_118 ( & V_116 , F_108 , 0 ) ;
do {
if ( V_117 && V_47 -> V_118 ) {
if ( ! F_119 ( & V_116 ) )
F_120 ( & V_116 , V_81 + 1 ) ;
}
V_38 = V_47 -> V_107 () ;
V_60 = V_47 -> V_60 () ;
V_1 = F_1 () ;
V_17 = F_98 ( V_96 ,
F_110 () ||
F_111 () ||
F_112 ( & V_55 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_108 ( V_38 ) ;
F_25 ( V_34 ) ;
continue;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_109 ) ;
V_47 -> V_110 ( & rand ) ;
F_78 () ;
V_106 = V_17 -> V_43 ;
if ( V_106 > V_44 ) {
V_106 = V_44 ;
}
V_104 = V_47 -> V_60 () ;
if ( V_106 > 1 ) {
F_115 ( V_47 -> V_112 , & V_17 -> V_42 ,
V_1 , V_60 , V_104 ) ;
F_103 () ;
}
F_116 ( V_113 [ V_106 ] ) ;
V_60 = V_104 - V_60 ;
if ( V_60 > V_44 ) {
V_60 = V_44 ;
}
F_116 ( V_114 [ V_60 ] ) ;
F_80 () ;
V_47 -> V_108 ( V_38 ) ;
F_121 () ;
F_24 ( L_21 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_22 ) ;
F_8 ( L_21 ) ;
if ( V_117 && V_47 -> V_118 )
F_122 ( & V_116 ) ;
while ( ! F_90 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_123 ( char * V_57 )
{
int V_58 = 0 ;
int V_59 ;
int V_40 ;
long V_119 [ V_44 + 1 ] = { 0 } ;
long V_120 [ V_44 + 1 ] = { 0 } ;
F_71 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_119 [ V_40 ] += F_124 ( V_113 , V_59 ) [ V_40 ] ;
V_120 [ V_40 ] += F_124 ( V_114 , V_59 ) [ V_40 ] ;
}
}
for ( V_40 = V_44 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( V_119 [ V_40 ] != 0 )
break;
}
V_58 += sprintf ( & V_57 [ V_58 ] , L_23 , V_61 , V_62 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] ,
L_24 ,
V_96 ,
V_98 ,
F_14 ( & V_19 ) ,
F_105 ( & V_21 ) ,
F_105 ( & V_20 ) ,
F_105 ( & V_24 ) ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_25 ,
F_105 ( & V_109 ) ,
V_121 ,
V_79 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_26 ,
V_84 ,
V_87 ,
V_111 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] ,
L_27 ,
V_122 , V_123 ,
V_124 , V_125 ,
V_126 , V_127 ,
V_128 , V_129 ,
V_130 , V_131 , V_34 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_28 ,
V_132 ,
V_133 ,
V_134 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_29 , V_61 , V_62 ) ;
if ( F_105 ( & V_109 ) != 0 ||
V_134 != 0 ||
V_121 != 0 ||
V_79 != 0 ||
V_84 != 0 ||
V_40 > 1 ) {
V_58 += sprintf ( & V_57 [ V_58 ] , L_30 ) ;
F_15 ( & V_135 ) ;
F_125 ( 1 ) ;
}
V_58 += sprintf ( & V_57 [ V_58 ] , L_31 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
V_58 += sprintf ( & V_57 [ V_58 ] , L_32 , V_119 [ V_40 ] ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_29 , V_61 , V_62 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_33 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
V_58 += sprintf ( & V_57 [ V_58 ] , L_32 , V_120 [ V_40 ] ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_29 , V_61 , V_62 ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_34 ) ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_58 += sprintf ( & V_57 [ V_58 ] , L_35 ,
F_105 ( & V_45 [ V_40 ] ) ) ;
}
V_58 += sprintf ( & V_57 [ V_58 ] , L_5 ) ;
if ( V_47 -> V_136 )
V_58 += V_47 -> V_136 ( & V_57 [ V_58 ] ) ;
return V_58 ;
}
static void
F_126 ( void )
{
int V_58 ;
V_58 = F_123 ( V_137 ) ;
F_127 ( L_36 , V_137 ) ;
}
static int
F_128 ( void * V_69 )
{
F_86 ( L_37 ) ;
do {
F_25 ( V_138 * V_34 ) ;
F_126 () ;
F_8 ( L_38 ) ;
} while ( ! F_90 () );
F_86 ( L_39 ) ;
return 0 ;
}
static void F_129 ( void )
{
int V_40 ;
F_130 ( V_139 ) ;
F_131 () ;
if ( F_132 () == 1 ) {
F_133 () ;
return;
}
if ( V_140 != - 1 )
F_134 ( V_140 , V_139 ) ;
F_135 ( V_77 , V_139 ) ;
if ( V_141 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ )
if ( V_141 [ V_40 ] )
F_135 ( V_141 [ V_40 ] ,
V_139 ) ;
}
if ( V_142 ) {
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ )
if ( V_142 [ V_40 ] )
F_135 ( V_142 [ V_40 ] ,
V_139 ) ;
}
if ( V_97 )
F_135 ( V_97 , V_139 ) ;
if ( V_143 )
F_135 ( V_143 , V_139 ) ;
if ( V_144 )
F_135 ( V_144 , V_139 ) ;
if ( V_145 )
F_135 ( V_145 , V_139 ) ;
if ( V_146 )
F_135 ( V_146 , V_139 ) ;
#ifdef F_136
if ( V_147 )
F_135 ( V_147 , V_139 ) ;
#endif
if ( V_148 )
F_135 ( V_148 , V_139 ) ;
if ( V_149 )
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ )
if ( V_149 [ V_40 ] )
F_135 ( V_149 [ V_40 ] ,
V_139 ) ;
if ( V_151 )
F_135 ( V_151 , V_139 ) ;
if ( V_140 == - 1 )
V_140 = F_132 () - 1 ;
else
V_140 -- ;
F_133 () ;
}
static int
F_137 ( void * V_69 )
{
F_86 ( L_40 ) ;
do {
F_25 ( V_152 * V_34 ) ;
F_129 () ;
F_8 ( L_41 ) ;
} while ( ! F_90 () );
F_86 ( L_42 ) ;
return 0 ;
}
static int
F_138 ( void * V_69 )
{
F_86 ( L_43 ) ;
do {
F_25 ( V_153 * V_34 ) ;
V_32 = 1 ;
if ( ! F_90 () )
F_25 ( V_153 * V_34 ) ;
V_32 = 0 ;
F_8 ( L_44 ) ;
} while ( ! F_90 () );
F_86 ( L_45 ) ;
return 0 ;
}
static inline void
F_139 ( struct V_154 * V_47 , char * V_155 )
{
F_127 ( L_36 V_62
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_61 , V_155 , V_37 , V_100 ,
V_138 , V_156 , V_157 , V_152 ,
V_153 , V_117 , V_91 , V_93 , V_90 ,
V_158 , V_47 -> V_159 ,
V_86 , V_83 , V_160 ,
V_161 , V_162 ,
V_150 ,
V_163 , V_164 ) ;
}
static void F_140 ( int V_59 )
{
struct V_165 * V_116 ;
if ( V_166 [ V_59 ] == NULL )
return;
F_5 ( & V_85 ) ;
F_86 ( L_55 ) ;
V_116 = V_166 [ V_59 ] ;
V_166 [ V_59 ] = NULL ;
F_7 ( & V_85 ) ;
F_141 ( V_116 ) ;
V_166 [ V_59 ] = NULL ;
}
static int F_142 ( int V_59 )
{
int V_167 ;
if ( V_166 [ V_59 ] != NULL )
return 0 ;
F_5 ( & V_85 ) ;
F_86 ( L_56 ) ;
V_166 [ V_59 ] = F_143 ( F_85 , NULL ,
F_144 ( V_59 ) ,
L_8 ) ;
if ( F_145 ( V_166 [ V_59 ] ) ) {
V_167 = F_146 ( V_166 [ V_59 ] ) ;
F_86 ( L_57 ) ;
V_121 ++ ;
V_166 [ V_59 ] = NULL ;
F_7 ( & V_85 ) ;
return V_167 ;
}
F_147 ( V_166 [ V_59 ] , V_59 ) ;
F_148 ( V_166 [ V_59 ] ) ;
F_7 ( & V_85 ) ;
return 0 ;
}
static int
F_149 ( void * V_69 )
{
long V_168 ;
unsigned long V_169 ;
F_86 ( L_58 ) ;
V_169 = F_9 ( V_81 ) ;
while ( F_89 ( V_169 , V_170 ) &&
! F_90 () ) {
V_168 = V_170 - V_169 ;
if ( V_156 )
F_127 ( L_36 V_62
L_59 ,
V_61 , V_168 ) ;
F_25 ( V_168 ) ;
V_169 = F_9 ( V_81 ) ;
}
if ( F_90 () ) {
F_86 ( L_60 ) ;
return 0 ;
}
F_86 ( L_61 ) ;
V_146 = NULL ;
F_150 () ;
F_151 () ;
return 0 ;
}
static int T_7
F_152 ( void * V_69 )
{
int V_59 ;
unsigned long V_168 ;
int V_171 = - 1 ;
F_96 ( rand ) ;
int V_172 ;
unsigned long V_173 ;
F_86 ( L_62 ) ;
F_153 (cpu)
V_171 = V_59 ;
F_154 ( V_171 < 0 ) ;
if ( V_164 > 0 ) {
F_86 ( L_63 ) ;
F_25 ( V_164 * V_34 ) ;
F_86 ( L_64 ) ;
}
while ( ! F_90 () ) {
V_59 = ( F_21 ( & rand ) >> 4 ) % ( V_171 + 1 ) ;
if ( F_155 ( V_59 ) && F_156 ( V_59 ) ) {
if ( V_156 )
F_127 ( L_36 V_62
L_65 ,
V_61 , V_59 ) ;
V_173 = V_81 ;
V_125 ++ ;
V_172 = F_157 ( V_59 ) ;
if ( V_172 ) {
if ( V_156 )
F_127 ( L_36 V_62
L_66 ,
V_61 , V_59 , V_172 ) ;
} else {
if ( V_156 )
F_127 ( L_36 V_62
L_67 ,
V_61 , V_59 ) ;
V_124 ++ ;
V_168 = V_81 - V_173 ;
V_131 += V_168 ;
if ( V_128 < 0 ) {
V_128 = V_168 ;
V_129 = V_168 ;
}
if ( V_128 > V_168 )
V_128 = V_168 ;
if ( V_129 < V_168 )
V_129 = V_168 ;
}
} else if ( F_156 ( V_59 ) ) {
if ( V_156 )
F_127 ( L_36 V_62
L_68 ,
V_61 , V_59 ) ;
V_173 = V_81 ;
V_123 ++ ;
if ( F_158 ( V_59 ) == 0 ) {
if ( V_156 )
F_127 ( L_36 V_62
L_69 ,
V_61 , V_59 ) ;
V_122 ++ ;
V_168 = V_81 - V_173 ;
V_130 += V_168 ;
if ( V_126 < 0 ) {
V_126 = V_168 ;
V_127 = V_168 ;
}
if ( V_126 > V_168 )
V_126 = V_168 ;
if ( V_127 < V_168 )
V_127 = V_168 ;
}
}
F_25 ( V_163 * V_34 ) ;
}
F_86 ( L_70 ) ;
return 0 ;
}
static int T_7
F_159 ( void )
{
int V_172 ;
if ( V_163 <= 0 )
return 0 ;
V_147 = F_160 ( F_152 , NULL , L_71 ) ;
if ( F_145 ( V_147 ) ) {
V_172 = F_146 ( V_147 ) ;
V_147 = NULL ;
return V_172 ;
}
return 0 ;
}
static void F_161 ( void )
{
if ( V_147 == NULL )
return;
F_86 ( L_72 ) ;
F_141 ( V_147 ) ;
V_147 = NULL ;
}
static int
F_159 ( void )
{
return 0 ;
}
static void F_161 ( void )
{
}
static int T_7 F_162 ( void * args )
{
unsigned long V_174 ;
F_86 ( L_73 ) ;
if ( V_162 > 0 ) {
F_86 ( L_74 ) ;
F_25 ( V_162 * V_34 ) ;
F_86 ( L_75 ) ;
}
if ( ! F_90 () ) {
V_174 = F_163 () + V_161 ;
F_127 ( L_76 ) ;
F_28 () ;
F_78 () ;
while ( F_89 ( F_163 () , V_174 ) )
continue;
F_80 () ;
F_36 () ;
F_127 ( L_77 ) ;
}
F_8 ( L_78 ) ;
while ( ! F_90 () )
F_25 ( 10 * V_34 ) ;
return 0 ;
}
static int T_8 F_164 ( void )
{
int V_172 ;
if ( V_161 <= 0 )
return 0 ;
V_148 = F_160 ( F_162 , NULL , L_78 ) ;
if ( F_145 ( V_148 ) ) {
V_172 = F_146 ( V_148 ) ;
V_148 = NULL ;
return V_172 ;
}
return 0 ;
}
static void F_165 ( void )
{
if ( V_148 == NULL )
return;
F_86 ( L_79 ) ;
F_141 ( V_148 ) ;
V_148 = NULL ;
}
void F_166 ( struct V_39 * V_67 )
{
F_15 ( & V_175 ) ;
}
static int F_167 ( void * V_69 )
{
long V_176 = ( long ) V_69 ;
bool V_177 = 0 ;
struct V_39 V_67 ;
F_88 ( & V_67 ) ;
F_86 ( L_80 ) ;
F_97 ( V_77 , 19 ) ;
do {
F_168 ( V_178 [ V_176 ] ,
V_179 != V_177 ||
F_90 () ||
V_9 != V_10 ) ;
V_177 = V_179 ;
F_84 () ;
if ( F_90 () || V_9 != V_10 )
break;
V_47 -> V_180 ( & V_67 , F_166 ) ;
if ( F_169 ( & V_181 ) )
F_170 ( & V_182 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_81 ) ;
F_8 ( L_82 ) ;
while ( ! F_90 () )
F_25 ( 1 ) ;
V_47 -> V_99 () ;
F_93 ( & V_67 ) ;
return 0 ;
}
static int F_171 ( void * V_69 )
{
int V_40 ;
F_86 ( L_83 ) ;
do {
F_172 ( & V_175 , 0 ) ;
F_172 ( & V_181 , V_150 ) ;
F_84 () ;
V_179 = ! V_179 ;
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ )
F_170 ( & V_178 [ V_40 ] ) ;
F_168 ( V_182 ,
F_105 ( & V_181 ) == 0 ||
F_90 () ||
V_9 != V_10 ) ;
if ( F_90 () || V_9 != V_10 )
break;
V_133 ++ ;
V_47 -> V_99 () ;
if ( F_105 ( & V_175 ) != V_150 ) {
V_134 ++ ;
F_125 ( 1 ) ;
}
V_132 ++ ;
F_25 ( V_34 / 10 ) ;
} while ( ! F_90 () && V_9 == V_10 );
F_86 ( L_84 ) ;
F_8 ( L_85 ) ;
while ( ! F_90 () )
F_25 ( 1 ) ;
return 0 ;
}
static int F_173 ( void )
{
int V_40 ;
int V_172 ;
if ( V_150 == 0 )
return 0 ;
if ( V_47 -> V_180 == NULL || V_47 -> V_99 == NULL ) {
F_127 ( L_36 V_62
L_86 ,
V_61 , V_47 -> V_112 ) ;
F_127 ( L_36 V_62
L_87 ,
V_61 ) ;
return 0 ;
}
F_172 ( & V_181 , 0 ) ;
F_172 ( & V_175 , 0 ) ;
V_149 =
F_174 ( V_150 * sizeof( V_149 [ 0 ] ) ,
V_183 ) ;
V_178 =
F_174 ( V_150 * sizeof( V_178 [ 0 ] ) ,
V_183 ) ;
if ( V_149 == NULL || ! V_178 )
return - V_184 ;
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ ) {
F_175 ( & V_178 [ V_40 ] ) ;
V_149 [ V_40 ] = F_160 ( F_167 ,
( void * ) ( long ) V_40 ,
L_82 ) ;
if ( F_145 ( V_149 [ V_40 ] ) ) {
V_172 = F_146 ( V_149 [ V_40 ] ) ;
F_176 ( L_88 ) ;
V_149 [ V_40 ] = NULL ;
return V_172 ;
}
}
V_151 = F_160 ( F_171 , NULL ,
L_85 ) ;
if ( F_145 ( V_151 ) ) {
V_172 = F_146 ( V_151 ) ;
F_176 ( L_89 ) ;
V_151 = NULL ;
}
return 0 ;
}
static void F_177 ( void )
{
int V_40 ;
if ( V_151 != NULL ) {
F_86 ( L_90 ) ;
F_141 ( V_151 ) ;
V_151 = NULL ;
}
if ( V_149 != NULL ) {
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ ) {
if ( V_149 [ V_40 ] != NULL ) {
F_86 ( L_91 ) ;
F_141 ( V_149 [ V_40 ] ) ;
V_149 [ V_40 ] = NULL ;
}
}
F_178 ( V_149 ) ;
V_149 = NULL ;
}
if ( V_178 != NULL ) {
F_178 ( V_178 ) ;
V_178 = NULL ;
}
}
static int F_179 ( struct V_4 * V_185 ,
unsigned long V_186 , void * V_187 )
{
long V_59 = ( long ) V_187 ;
switch ( V_186 ) {
case V_188 :
case V_189 :
( void ) F_142 ( V_59 ) ;
break;
case V_190 :
F_140 ( V_59 ) ;
break;
default:
break;
}
return V_191 ;
}
static void
F_150 ( void )
{
int V_40 ;
F_5 ( & V_8 ) ;
F_180 () ;
if ( V_9 == V_11 ) {
F_6 (
L_1 ) ;
F_7 ( & V_8 ) ;
F_11 ( 10 ) ;
if ( V_47 -> V_99 != NULL )
V_47 -> V_99 () ;
return;
}
V_9 = V_192 ;
F_7 ( & V_8 ) ;
F_181 ( & V_193 ) ;
F_177 () ;
F_165 () ;
if ( V_144 ) {
F_86 ( L_92 ) ;
F_141 ( V_144 ) ;
}
V_144 = NULL ;
if ( V_194 ) {
F_86 ( L_93 ) ;
F_141 ( V_194 ) ;
F_182 ( V_139 ) ;
}
V_194 = NULL ;
if ( V_97 ) {
F_86 ( L_94 ) ;
F_141 ( V_97 ) ;
}
V_97 = NULL ;
if ( V_141 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
if ( V_141 [ V_40 ] ) {
F_86 (
L_95 ) ;
F_141 ( V_141 [ V_40 ] ) ;
}
V_141 [ V_40 ] = NULL ;
}
F_178 ( V_141 ) ;
V_141 = NULL ;
}
V_96 = NULL ;
if ( V_142 ) {
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
if ( V_142 [ V_40 ] ) {
F_86 (
L_96 ) ;
F_141 ( V_142 [ V_40 ] ) ;
}
V_142 [ V_40 ] = NULL ;
}
F_178 ( V_142 ) ;
V_142 = NULL ;
}
if ( V_143 ) {
F_86 ( L_97 ) ;
F_141 ( V_143 ) ;
}
V_143 = NULL ;
if ( V_145 ) {
F_86 ( L_98 ) ;
F_141 ( V_145 ) ;
}
V_145 = NULL ;
if ( ( V_158 == 1 && V_47 -> V_159 ) ||
V_158 == 2 ) {
F_183 ( & V_195 ) ;
F_71 (i)
F_140 ( V_40 ) ;
}
if ( V_146 != NULL ) {
F_86 ( L_99 ) ;
F_141 ( V_146 ) ;
}
V_146 = NULL ;
F_161 () ;
if ( V_47 -> V_99 != NULL )
V_47 -> V_99 () ;
F_126 () ;
if ( F_105 ( & V_135 ) || V_134 )
F_139 ( V_47 , L_100 ) ;
else if ( V_122 != V_123 ||
V_124 != V_125 )
F_139 ( V_47 ,
L_101 ) ;
else
F_139 ( V_47 , L_102 ) ;
}
static int T_8
F_184 ( void )
{
int V_40 ;
int V_59 ;
int V_196 = 0 ;
int V_167 ;
static struct V_154 * V_197 [] =
{ & V_198 , & V_199 , & V_200 ,
& V_201 , & V_202 , & V_203 ,
& V_204 , & V_205 , & V_206 ,
& V_207 , & V_208 ,
& V_209 , & V_210 , & V_211 , } ;
F_5 ( & V_8 ) ;
for ( V_40 = 0 ; V_40 < F_185 ( V_197 ) ; V_40 ++ ) {
V_47 = V_197 [ V_40 ] ;
if ( strcmp ( V_61 , V_47 -> V_112 ) == 0 )
break;
}
if ( V_40 == F_185 ( V_197 ) ) {
F_127 ( L_103 ,
V_61 ) ;
F_127 ( L_104 ) ;
for ( V_40 = 0 ; V_40 < F_185 ( V_197 ) ; V_40 ++ )
F_127 ( L_105 , V_197 [ V_40 ] -> V_112 ) ;
F_127 ( L_5 ) ;
F_7 ( & V_8 ) ;
return - V_212 ;
}
if ( V_47 -> V_92 == NULL && V_91 != 0 ) {
F_127 ( L_106 ) ;
V_91 = 0 ;
}
if ( V_47 -> V_213 )
V_47 -> V_213 () ;
if ( V_214 >= 0 )
V_37 = V_214 ;
else
V_37 = 2 * F_132 () ;
F_139 ( V_47 , L_107 ) ;
V_9 = V_10 ;
F_48 ( & V_19 ) ;
for ( V_40 = 0 ; V_40 < F_185 ( V_215 ) ; V_40 ++ ) {
V_215 [ V_40 ] . V_46 = 0 ;
F_20 ( & V_215 [ V_40 ] . V_23 ,
& V_19 ) ;
}
V_96 = NULL ;
V_98 = 0 ;
F_172 ( & V_21 , 0 ) ;
F_172 ( & V_20 , 0 ) ;
F_172 ( & V_24 , 0 ) ;
F_172 ( & V_109 , 0 ) ;
F_172 ( & V_135 , 0 ) ;
V_134 = 0 ;
V_121 = 0 ;
V_79 = 0 ;
V_84 = 0 ;
V_87 = 0 ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
F_172 ( & V_45 [ V_40 ] , 0 ) ;
F_71 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
F_124 ( V_113 , V_59 ) [ V_40 ] = 0 ;
F_124 ( V_114 , V_59 ) [ V_40 ] = 0 ;
}
}
F_86 ( L_108 ) ;
V_97 = F_186 ( F_95 , NULL ,
L_15 ) ;
if ( F_145 ( V_97 ) ) {
V_196 = F_146 ( V_97 ) ;
F_176 ( L_109 ) ;
V_97 = NULL ;
goto V_216;
}
F_148 ( V_97 ) ;
V_142 = F_174 ( V_100 * sizeof( V_142 [ 0 ] ) ,
V_183 ) ;
if ( V_142 == NULL ) {
F_176 ( L_110 ) ;
V_196 = - V_184 ;
goto V_216;
}
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
F_86 ( L_111 ) ;
V_142 [ V_40 ] = F_160 ( F_102 , NULL ,
L_18 ) ;
if ( F_145 ( V_142 [ V_40 ] ) ) {
V_196 = F_146 ( V_142 [ V_40 ] ) ;
F_176 ( L_112 ) ;
V_142 [ V_40 ] = NULL ;
goto V_216;
}
}
V_141 = F_174 ( V_37 * sizeof( V_141 [ 0 ] ) ,
V_183 ) ;
if ( V_141 == NULL ) {
F_176 ( L_110 ) ;
V_196 = - V_184 ;
goto V_216;
}
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
F_86 ( L_113 ) ;
V_141 [ V_40 ] = F_160 ( F_117 , NULL ,
L_21 ) ;
if ( F_145 ( V_141 [ V_40 ] ) ) {
V_196 = F_146 ( V_141 [ V_40 ] ) ;
F_176 ( L_114 ) ;
V_141 [ V_40 ] = NULL ;
goto V_216;
}
}
if ( V_138 > 0 ) {
F_86 ( L_115 ) ;
V_143 = F_160 ( F_128 , NULL ,
L_38 ) ;
if ( F_145 ( V_143 ) ) {
V_196 = F_146 ( V_143 ) ;
F_176 ( L_116 ) ;
V_143 = NULL ;
goto V_216;
}
}
if ( V_157 ) {
V_140 = F_132 () - 1 ;
if ( ! F_187 ( & V_139 , V_183 ) ) {
V_196 = - V_184 ;
F_176 ( L_117 ) ;
goto V_216;
}
V_194 = F_160 ( F_137 , NULL ,
L_41 ) ;
if ( F_145 ( V_194 ) ) {
F_182 ( V_139 ) ;
V_196 = F_146 ( V_194 ) ;
F_176 ( L_118 ) ;
V_194 = NULL ;
goto V_216;
}
}
if ( V_153 < 0 )
V_153 = 0 ;
if ( V_153 ) {
V_144 = F_160 ( F_138 , NULL ,
L_44 ) ;
if ( F_145 ( V_144 ) ) {
V_196 = F_146 ( V_144 ) ;
F_176 ( L_119 ) ;
V_144 = NULL ;
goto V_216;
}
}
if ( V_91 < 0 )
V_91 = 0 ;
if ( V_91 ) {
V_145 = F_160 ( F_94 , NULL ,
L_12 ) ;
if ( F_145 ( V_145 ) ) {
V_196 = F_146 ( V_145 ) ;
F_176 ( L_120 ) ;
V_145 = NULL ;
goto V_216;
}
}
if ( V_86 < 1 )
V_86 = 1 ;
if ( V_83 < 2 )
V_83 = 2 ;
if ( ( V_158 == 1 && V_47 -> V_159 ) ||
V_158 == 2 ) {
V_80 = V_81 + V_86 * V_34 ;
F_188 ( & V_195 ) ;
F_71 (i) {
if ( F_189 ( V_40 ) )
continue;
V_167 = F_142 ( V_40 ) ;
if ( V_167 < 0 ) {
V_196 = V_167 ;
goto V_216;
}
}
}
if ( V_160 > 0 ) {
V_170 = V_81 + V_160 * V_34 ;
V_146 = F_186 ( F_149 , NULL ,
L_121 ) ;
if ( F_145 ( V_146 ) ) {
V_196 = F_146 ( V_146 ) ;
F_176 ( L_122 ) ;
V_146 = NULL ;
goto V_216;
}
F_148 ( V_146 ) ;
}
V_40 = F_159 () ;
if ( V_40 != 0 ) {
V_196 = V_40 ;
goto V_216;
}
F_190 ( & V_193 ) ;
V_40 = F_164 () ;
if ( V_40 != 0 ) {
V_196 = V_40 ;
goto V_216;
}
V_167 = F_173 () ;
if ( V_167 != 0 ) {
V_196 = V_167 ;
goto V_216;
}
F_180 () ;
F_7 ( & V_8 ) ;
return 0 ;
V_216:
F_7 ( & V_8 ) ;
F_150 () ;
return V_196 ;
}
