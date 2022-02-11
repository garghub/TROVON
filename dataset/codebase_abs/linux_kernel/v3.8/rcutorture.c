static int
F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_6 == V_7 )
V_6 = V_8 ;
else
F_3 (
L_1 ) ;
F_4 ( & V_5 ) ;
return V_9 ;
}
static void F_5 ( char * V_10 )
{
if ( F_6 ( V_6 ) == V_8 ) {
F_7 (
L_2 ,
V_10 ) ;
F_8 ( V_11 ) ;
}
}
static struct V_12 *
F_9 ( void )
{
struct V_13 * V_14 ;
F_10 ( & V_15 ) ;
if ( F_11 ( & V_16 ) ) {
F_12 ( & V_17 ) ;
F_13 ( & V_15 ) ;
return NULL ;
}
F_12 ( & V_18 ) ;
V_14 = V_16 . V_19 ;
F_14 ( V_14 ) ;
F_13 ( & V_15 ) ;
return F_15 ( V_14 , struct V_12 , V_20 ) ;
}
static void
F_16 ( struct V_12 * V_14 )
{
F_12 ( & V_21 ) ;
F_10 ( & V_15 ) ;
F_17 ( & V_14 -> V_20 , & V_16 ) ;
F_13 ( & V_15 ) ;
}
static unsigned long
F_18 ( struct V_22 * V_23 )
{
if ( -- V_23 -> V_24 < 0 ) {
V_23 -> V_25 += ( unsigned long ) F_19 () ;
V_23 -> V_24 = V_26 ;
}
V_23 -> V_25 = V_23 -> V_25 * V_27 + V_28 ;
return F_20 ( V_23 -> V_25 ) ;
}
static void
F_21 ( char * V_10 )
{
while ( V_29 || ! V_30 ) {
if ( V_30 )
F_22 ( 1 ) ;
else
F_22 ( F_23 ( V_31 ) ) ;
F_5 ( V_10 ) ;
}
}
static int F_24 ( void ) __acquires( T_1 )
{
F_25 () ;
return 0 ;
}
static void F_26 ( struct V_22 * V_23 )
{
const unsigned long V_32 = 200 ;
const unsigned long V_33 = 50 ;
if ( ! ( F_18 ( V_23 ) % ( V_34 * 2000 * V_33 ) ) )
F_27 ( V_33 ) ;
if ( ! ( F_18 ( V_23 ) % ( V_34 * 2 * V_32 ) ) )
F_28 ( V_32 ) ;
#ifdef F_29
if ( ! F_30 () && ! ( F_18 ( V_23 ) % ( V_34 * 20000 ) ) )
F_31 () ;
#endif
}
static void F_32 ( int V_35 ) __releases( T_1 )
{
F_33 () ;
}
static int F_34 ( void )
{
return F_35 () ;
}
static void
F_36 ( struct V_36 * V_14 )
{
int V_37 ;
struct V_12 * V_38 = F_15 ( V_14 , struct V_12 , V_39 ) ;
if ( V_6 != V_7 ) {
return;
}
V_37 = V_38 -> V_40 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
F_12 ( & V_42 [ V_37 ] ) ;
if ( ++ V_38 -> V_40 >= V_41 ) {
V_38 -> V_43 = 0 ;
F_16 ( V_38 ) ;
} else {
V_44 -> V_45 ( V_38 ) ;
}
}
static int F_37 ( void )
{
return 0 ;
}
static void F_38 ( struct V_12 * V_14 )
{
F_39 ( & V_14 -> V_39 , F_36 ) ;
}
static void F_40 ( struct V_12 * V_14 )
{
int V_37 ;
struct V_12 * V_38 ;
struct V_12 * V_46 ;
V_44 -> V_47 () ;
F_41 ( & V_14 -> V_20 , & V_48 ) ;
F_42 (rp, rp1, &rcu_torture_removed, rtort_free) {
V_37 = V_38 -> V_40 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
F_12 ( & V_42 [ V_37 ] ) ;
if ( ++ V_38 -> V_40 >= V_41 ) {
V_38 -> V_43 = 0 ;
F_43 ( & V_38 -> V_20 ) ;
F_16 ( V_38 ) ;
}
}
}
static void F_44 ( void )
{
F_45 ( & V_48 ) ;
}
static int F_46 ( void ) __acquires( T_2 )
{
F_47 () ;
return 0 ;
}
static void F_48 ( int V_35 ) __releases( T_2 )
{
F_49 () ;
}
static int F_50 ( void )
{
return F_51 () ;
}
static void F_52 ( struct V_12 * V_14 )
{
F_53 ( & V_14 -> V_39 , F_36 ) ;
}
static int F_54 ( void ) __acquires( &srcu_ctl
static void F_55 ( struct V_22 * V_23 )
{
long V_49 ;
const long V_50 = 1000000 / V_31 ;
const long V_51 = 10 ;
V_49 = F_18 ( V_23 ) % ( V_34 * 2 * V_51 * V_50 ) ;
if ( ! V_49 )
F_22 ( V_51 ) ;
else
F_26 ( V_23 ) ;
}
static void F_56 ( int V_35 ) __releases( &srcu_ctl
static int F_57 ( void )
{
return F_58 ( & V_52 ) ;
}
static void F_59 ( struct V_12 * V_38 )
{
F_60 ( & V_52 , & V_38 -> V_39 , F_36 ) ;
}
static void F_61 ( void )
{
F_62 ( & V_52 ) ;
}
static void F_63 ( struct V_36 * V_53 ,
void (* F_64)( struct V_36 * V_53 ) )
{
F_60 ( & V_52 , V_53 , F_64 ) ;
}
static void F_65 ( void )
{
F_66 ( & V_52 ) ;
}
static int F_67 ( char * V_54 )
{
int V_55 = 0 ;
int V_56 ;
int V_35 = V_52 . V_57 & 0x1 ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_3 ,
V_58 , V_59 , V_35 ) ;
F_68 (cpu) {
V_55 += sprintf ( & V_54 [ V_55 ] , L_4 , V_56 ,
F_69 ( V_52 . V_60 , V_56 ) -> V_61 [ ! V_35 ] ,
F_69 ( V_52 . V_60 , V_56 ) -> V_61 [ V_35 ] ) ;
}
V_55 += sprintf ( & V_54 [ V_55 ] , L_5 ) ;
return V_55 ;
}
static int F_70 ( void ) __acquires( &srcu_ctl
static void F_71 ( int V_35 ) __releases( &srcu_ctl
static void F_72 ( void )
{
F_73 ( & V_52 ) ;
}
static int F_74 ( void )
{
F_75 () ;
return 0 ;
}
static void F_76 ( int V_35 )
{
F_77 () ;
}
static void F_78 ( struct V_12 * V_14 )
{
F_79 ( & V_14 -> V_39 , F_36 ) ;
}
static void F_80 ( struct V_36 * V_53 )
{
struct V_62 * V_63 =
F_15 ( V_53 , struct V_62 , V_64 ) ;
F_81 () ;
V_63 -> V_65 = 0 ;
}
static int F_82 ( void * V_66 )
{
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
struct V_62 V_70 = { . V_65 = 0 } ;
struct V_71 V_72 ;
F_83 ( L_6 ) ;
V_72 . V_73 = 1 ;
if ( F_84 ( V_74 , V_75 , & V_72 ) < 0 ) {
F_83 ( L_7 ) ;
V_76 ++ ;
}
F_85 ( & V_70 . V_64 ) ;
do {
V_69 = V_77 ;
while ( F_86 ( V_78 , V_69 ) ) {
F_8 ( 1 ) ;
F_21 ( L_8 ) ;
if ( F_87 () ||
V_6 != V_7 )
goto V_79;
}
V_68 = V_69 + V_80 * V_31 ;
V_67 = V_78 ;
while ( F_86 ( V_78 , V_68 ) ) {
if ( ! V_70 . V_65 ) {
F_81 () ;
V_70 . V_65 = 1 ;
F_39 ( & V_70 . V_64 , F_80 ) ;
if ( V_78 - V_67 >
V_80 * V_31 - V_31 / 2 ) {
F_83 ( L_9 ) ;
V_81 ++ ;
}
V_67 = V_78 ;
}
F_88 () ;
F_21 ( L_8 ) ;
if ( F_87 () ||
V_6 != V_7 )
goto V_79;
}
while ( V_69 == V_77 &&
! F_87 () ) {
if ( F_89 ( & V_82 ) ) {
V_77 = V_78 +
V_83 * V_31 ;
V_84 ++ ;
F_4 ( & V_82 ) ;
break;
}
F_8 ( 1 ) ;
}
V_79: F_21 ( L_8 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_10 ) ;
F_5 ( L_8 ) ;
while ( ! F_87 () || V_70 . V_65 )
F_8 ( 1 ) ;
F_81 () ;
F_90 ( & V_70 . V_64 ) ;
return 0 ;
}
static int
F_91 ( void * V_66 )
{
unsigned long V_85 ;
int V_86 ;
F_83 ( L_11 ) ;
do {
V_85 = V_78 + V_87 * V_31 ;
while ( F_86 ( V_78 , V_85 ) &&
! F_87 () ) {
F_22 ( 1 ) ;
}
V_86 = V_88 ;
while ( V_86 > 0 &&
! F_87 () ) {
V_44 -> V_89 () ;
F_28 ( V_90 ) ;
V_86 -= V_90 ;
}
F_21 ( L_12 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_87 () )
F_8 ( 1 ) ;
return 0 ;
}
static int
F_92 ( void * V_66 )
{
int V_37 ;
long V_91 = F_35 () ;
struct V_12 * V_38 ;
struct V_12 * V_92 ;
static F_93 ( rand ) ;
F_83 ( L_14 ) ;
F_94 ( V_74 , 19 ) ;
do {
F_8 ( 1 ) ;
V_38 = F_9 () ;
if ( V_38 == NULL )
continue;
V_38 -> V_40 = 0 ;
F_28 ( F_18 ( & rand ) & 0x3ff ) ;
V_92 = F_95 ( V_93 ,
V_74 == V_94 ) ;
V_38 -> V_43 = 1 ;
F_96 ( V_93 , V_38 ) ;
F_97 () ;
if ( V_92 ) {
V_37 = V_92 -> V_40 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
F_12 ( & V_42 [ V_37 ] ) ;
V_92 -> V_40 ++ ;
V_44 -> V_45 ( V_92 ) ;
}
F_98 ( ++ V_95 ) ;
V_91 = V_44 -> V_57 () ;
F_21 ( L_15 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_87 () )
F_8 ( 1 ) ;
return 0 ;
}
static int
F_99 ( void * V_66 )
{
F_93 ( rand ) ;
F_83 ( L_17 ) ;
F_94 ( V_74 , 19 ) ;
do {
F_8 ( 1 + F_18 ( & rand ) % 10 ) ;
F_28 ( F_18 ( & rand ) & 0x3ff ) ;
if ( V_44 -> V_96 != NULL &&
F_18 ( & rand ) % ( V_97 * 8 ) == 0 )
V_44 -> V_96 () ;
else
V_44 -> V_47 () ;
F_21 ( L_18 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_87 () )
F_8 ( 1 ) ;
return 0 ;
}
void F_100 ( void )
{
static T_3 V_98 = F_101 ( 0 ) ;
if ( F_102 ( & V_98 ) )
return;
if ( F_103 ( & V_98 , 1 ) != 0 )
return;
F_104 ( V_44 -> V_99 , (struct V_36 * ) ~ 0UL ) ;
F_105 ( V_100 ) ;
}
static void F_106 ( unsigned long V_101 )
{
int V_35 ;
int V_57 ;
static F_93 ( rand ) ;
static F_107 ( V_102 ) ;
struct V_12 * V_14 ;
int V_103 ;
V_35 = V_44 -> V_104 () ;
V_57 = V_44 -> V_57 () ;
V_14 = F_95 ( V_93 ,
F_108 () ||
F_109 () ||
F_110 ( & V_52 ) ) ;
if ( V_14 == NULL ) {
V_44 -> V_105 ( V_35 ) ;
return;
}
F_104 ( V_44 -> V_99 , & V_14 -> V_39 ) ;
if ( V_14 -> V_43 == 0 )
F_12 ( & V_106 ) ;
F_111 ( & V_102 ) ;
V_44 -> V_107 ( & rand ) ;
V_108 ++ ;
F_112 ( & V_102 ) ;
F_75 () ;
V_103 = V_14 -> V_40 ;
if ( V_103 > V_41 ) {
V_103 = V_41 ;
}
if ( V_103 > 1 )
F_100 () ;
F_113 ( V_109 [ V_103 ] ) ;
V_57 = V_44 -> V_57 () - V_57 ;
if ( V_57 > V_41 ) {
V_57 = V_41 ;
}
F_113 ( V_110 [ V_57 ] ) ;
F_77 () ;
V_44 -> V_105 ( V_35 ) ;
}
static int
F_114 ( void * V_66 )
{
int V_57 ;
int V_35 ;
F_93 ( rand ) ;
struct V_12 * V_14 ;
int V_103 ;
struct V_111 V_112 ;
F_83 ( L_20 ) ;
F_94 ( V_74 , 19 ) ;
if ( V_113 && V_44 -> V_114 )
F_115 ( & V_112 , F_106 , 0 ) ;
do {
if ( V_113 && V_44 -> V_114 ) {
if ( ! F_116 ( & V_112 ) )
F_117 ( & V_112 , V_78 + 1 ) ;
}
V_35 = V_44 -> V_104 () ;
V_57 = V_44 -> V_57 () ;
V_14 = F_95 ( V_93 ,
F_108 () ||
F_109 () ||
F_110 ( & V_52 ) ) ;
if ( V_14 == NULL ) {
V_44 -> V_105 ( V_35 ) ;
F_22 ( V_31 ) ;
continue;
}
F_104 ( V_44 -> V_99 , & V_14 -> V_39 ) ;
if ( V_14 -> V_43 == 0 )
F_12 ( & V_106 ) ;
V_44 -> V_107 ( & rand ) ;
F_75 () ;
V_103 = V_14 -> V_40 ;
if ( V_103 > V_41 ) {
V_103 = V_41 ;
}
if ( V_103 > 1 )
F_100 () ;
F_113 ( V_109 [ V_103 ] ) ;
V_57 = V_44 -> V_57 () - V_57 ;
if ( V_57 > V_41 ) {
V_57 = V_41 ;
}
F_113 ( V_110 [ V_57 ] ) ;
F_77 () ;
V_44 -> V_105 ( V_35 ) ;
F_118 () ;
F_21 ( L_21 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_113 && V_44 -> V_114 )
F_119 ( & V_112 ) ;
while ( ! F_87 () )
F_8 ( 1 ) ;
return 0 ;
}
static int
F_120 ( char * V_54 )
{
int V_55 = 0 ;
int V_56 ;
int V_37 ;
long V_115 [ V_41 + 1 ] = { 0 } ;
long V_116 [ V_41 + 1 ] = { 0 } ;
F_68 (cpu) {
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ ) {
V_115 [ V_37 ] += F_121 ( V_109 , V_56 ) [ V_37 ] ;
V_116 [ V_37 ] += F_121 ( V_110 , V_56 ) [ V_37 ] ;
}
}
for ( V_37 = V_41 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_115 [ V_37 ] != 0 )
break;
}
V_55 += sprintf ( & V_54 [ V_55 ] , L_23 , V_58 , V_59 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] ,
L_24 ,
V_93 ,
V_95 ,
F_11 ( & V_16 ) ,
F_102 ( & V_18 ) ,
F_102 ( & V_17 ) ,
F_102 ( & V_21 ) ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_25 ,
F_102 ( & V_106 ) ,
V_117 ,
V_76 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_26 ,
V_81 ,
V_84 ,
V_108 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] ,
L_27 ,
V_118 , V_119 ,
V_120 , V_121 ,
V_122 , V_123 ,
V_124 , V_125 ,
V_126 , V_127 , V_31 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_28 ,
V_128 ,
V_129 ,
V_130 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_29 , V_58 , V_59 ) ;
if ( F_102 ( & V_106 ) != 0 ||
V_130 != 0 ||
V_117 != 0 ||
V_76 != 0 ||
V_81 != 0 ||
V_37 > 1 ) {
V_55 += sprintf ( & V_54 [ V_55 ] , L_30 ) ;
F_12 ( & V_131 ) ;
F_122 ( 1 ) ;
}
V_55 += sprintf ( & V_54 [ V_55 ] , L_31 ) ;
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ )
V_55 += sprintf ( & V_54 [ V_55 ] , L_32 , V_115 [ V_37 ] ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_29 , V_58 , V_59 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_33 ) ;
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ )
V_55 += sprintf ( & V_54 [ V_55 ] , L_32 , V_116 [ V_37 ] ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_29 , V_58 , V_59 ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_34 ) ;
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ ) {
V_55 += sprintf ( & V_54 [ V_55 ] , L_35 ,
F_102 ( & V_42 [ V_37 ] ) ) ;
}
V_55 += sprintf ( & V_54 [ V_55 ] , L_5 ) ;
if ( V_44 -> V_132 )
V_55 += V_44 -> V_132 ( & V_54 [ V_55 ] ) ;
return V_55 ;
}
static void
F_123 ( void )
{
int V_55 ;
V_55 = F_120 ( V_133 ) ;
F_124 ( L_36 , V_133 ) ;
}
static int
F_125 ( void * V_66 )
{
F_83 ( L_37 ) ;
do {
F_22 ( V_134 * V_31 ) ;
F_123 () ;
F_5 ( L_38 ) ;
} while ( ! F_87 () );
F_83 ( L_39 ) ;
return 0 ;
}
static void F_126 ( void )
{
int V_37 ;
F_127 ( V_135 ) ;
F_128 () ;
if ( F_129 () == 1 ) {
F_130 () ;
return;
}
if ( V_136 != - 1 )
F_131 ( V_136 , V_135 ) ;
F_132 ( V_74 , V_135 ) ;
if ( V_137 ) {
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ )
if ( V_137 [ V_37 ] )
F_132 ( V_137 [ V_37 ] ,
V_135 ) ;
}
if ( V_138 ) {
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ )
if ( V_138 [ V_37 ] )
F_132 ( V_138 [ V_37 ] ,
V_135 ) ;
}
if ( V_94 )
F_132 ( V_94 , V_135 ) ;
if ( V_139 )
F_132 ( V_139 , V_135 ) ;
if ( V_136 == - 1 )
V_136 = F_129 () - 1 ;
else
V_136 -- ;
F_130 () ;
}
static int
F_133 ( void * V_66 )
{
F_83 ( L_40 ) ;
do {
F_22 ( V_140 * V_31 ) ;
F_126 () ;
F_5 ( L_41 ) ;
} while ( ! F_87 () );
F_83 ( L_42 ) ;
return 0 ;
}
static int
F_134 ( void * V_66 )
{
F_83 ( L_43 ) ;
do {
F_22 ( V_141 * V_31 ) ;
V_29 = 1 ;
if ( ! F_87 () )
F_22 ( V_141 * V_31 ) ;
V_29 = 0 ;
F_5 ( L_44 ) ;
} while ( ! F_87 () );
F_83 ( L_45 ) ;
return 0 ;
}
static inline void
F_135 ( struct V_142 * V_44 , char * V_143 )
{
F_124 ( L_36 V_59
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_58 , V_143 , V_34 , V_97 ,
V_134 , V_144 , V_145 , V_140 ,
V_141 , V_113 , V_88 , V_90 , V_87 ,
V_146 , V_44 -> V_147 ,
V_83 , V_80 , V_148 ,
V_149 , V_150 ,
V_151 ,
V_152 , V_153 ) ;
}
static void F_136 ( int V_56 )
{
struct V_154 * V_112 ;
if ( V_155 [ V_56 ] == NULL )
return;
F_2 ( & V_82 ) ;
F_83 ( L_55 ) ;
V_112 = V_155 [ V_56 ] ;
V_155 [ V_56 ] = NULL ;
F_4 ( & V_82 ) ;
F_137 ( V_112 ) ;
V_155 [ V_56 ] = NULL ;
}
static int F_138 ( int V_56 )
{
int V_156 ;
if ( V_155 [ V_56 ] != NULL )
return 0 ;
F_2 ( & V_82 ) ;
F_83 ( L_56 ) ;
V_155 [ V_56 ] = F_139 ( F_82 , NULL ,
F_140 ( V_56 ) ,
L_8 ) ;
if ( F_141 ( V_155 [ V_56 ] ) ) {
V_156 = F_142 ( V_155 [ V_56 ] ) ;
F_83 ( L_57 ) ;
V_117 ++ ;
V_155 [ V_56 ] = NULL ;
F_4 ( & V_82 ) ;
return V_156 ;
}
F_143 ( V_155 [ V_56 ] , V_56 ) ;
F_144 ( V_155 [ V_56 ] ) ;
F_4 ( & V_82 ) ;
return 0 ;
}
static int
F_145 ( void * V_66 )
{
long V_157 ;
unsigned long V_158 ;
F_83 ( L_58 ) ;
V_158 = F_6 ( V_78 ) ;
while ( F_86 ( V_158 , V_159 ) &&
! F_87 () ) {
V_157 = V_159 - V_158 ;
if ( V_144 )
F_124 ( L_36 V_59
L_59 ,
V_58 , V_157 ) ;
F_22 ( V_157 ) ;
V_158 = F_6 ( V_78 ) ;
}
if ( F_87 () ) {
F_83 ( L_60 ) ;
return 0 ;
}
F_83 ( L_61 ) ;
V_160 = NULL ;
F_146 () ;
F_147 () ;
return 0 ;
}
static int T_4
F_148 ( void * V_66 )
{
int V_56 ;
unsigned long V_157 ;
int V_161 = - 1 ;
F_93 ( rand ) ;
int V_162 ;
unsigned long V_163 ;
F_83 ( L_62 ) ;
F_149 (cpu)
V_161 = V_56 ;
F_150 ( V_161 < 0 ) ;
if ( V_153 > 0 ) {
F_83 ( L_63 ) ;
F_22 ( V_153 * V_31 ) ;
F_83 ( L_64 ) ;
}
while ( ! F_87 () ) {
V_56 = ( F_18 ( & rand ) >> 4 ) % ( V_161 + 1 ) ;
if ( F_151 ( V_56 ) && F_152 ( V_56 ) ) {
if ( V_144 )
F_124 ( L_36 V_59
L_65 ,
V_58 , V_56 ) ;
V_163 = V_78 ;
V_121 ++ ;
V_162 = F_153 ( V_56 ) ;
if ( V_162 ) {
if ( V_144 )
F_124 ( L_36 V_59
L_66 ,
V_58 , V_56 , V_162 ) ;
} else {
if ( V_144 )
F_124 ( L_36 V_59
L_67 ,
V_58 , V_56 ) ;
V_120 ++ ;
V_157 = V_78 - V_163 ;
V_127 += V_157 ;
if ( V_124 < 0 ) {
V_124 = V_157 ;
V_125 = V_157 ;
}
if ( V_124 > V_157 )
V_124 = V_157 ;
if ( V_125 < V_157 )
V_125 = V_157 ;
}
} else if ( F_152 ( V_56 ) ) {
if ( V_144 )
F_124 ( L_36 V_59
L_68 ,
V_58 , V_56 ) ;
V_163 = V_78 ;
V_119 ++ ;
if ( F_154 ( V_56 ) == 0 ) {
if ( V_144 )
F_124 ( L_36 V_59
L_69 ,
V_58 , V_56 ) ;
V_118 ++ ;
V_157 = V_78 - V_163 ;
V_126 += V_157 ;
if ( V_122 < 0 ) {
V_122 = V_157 ;
V_123 = V_157 ;
}
if ( V_122 > V_157 )
V_122 = V_157 ;
if ( V_123 < V_157 )
V_123 = V_157 ;
}
}
F_22 ( V_152 * V_31 ) ;
}
F_83 ( L_70 ) ;
return 0 ;
}
static int T_4
F_155 ( void )
{
int V_162 ;
if ( V_152 <= 0 )
return 0 ;
V_164 = F_156 ( F_148 , NULL , L_71 ) ;
if ( F_141 ( V_164 ) ) {
V_162 = F_142 ( V_164 ) ;
V_164 = NULL ;
return V_162 ;
}
return 0 ;
}
static void F_157 ( void )
{
if ( V_164 == NULL )
return;
F_83 ( L_72 ) ;
F_137 ( V_164 ) ;
V_164 = NULL ;
}
static int
F_155 ( void )
{
return 0 ;
}
static void F_157 ( void )
{
}
static int T_4 F_158 ( void * args )
{
unsigned long V_165 ;
F_83 ( L_73 ) ;
if ( V_150 > 0 ) {
F_83 ( L_74 ) ;
F_22 ( V_150 * V_31 ) ;
F_83 ( L_75 ) ;
}
if ( ! F_87 () ) {
V_165 = F_159 () + V_149 ;
F_124 ( L_76 ) ;
F_25 () ;
F_75 () ;
while ( F_86 ( F_159 () , V_165 ) )
continue;
F_77 () ;
F_33 () ;
F_124 ( L_77 ) ;
}
F_5 ( L_78 ) ;
while ( ! F_87 () )
F_22 ( 10 * V_31 ) ;
return 0 ;
}
static int T_5 F_160 ( void )
{
int V_162 ;
if ( V_149 <= 0 )
return 0 ;
V_166 = F_156 ( F_158 , NULL , L_78 ) ;
if ( F_141 ( V_166 ) ) {
V_162 = F_142 ( V_166 ) ;
V_166 = NULL ;
return V_162 ;
}
return 0 ;
}
static void F_161 ( void )
{
if ( V_166 == NULL )
return;
F_83 ( L_79 ) ;
F_137 ( V_166 ) ;
V_166 = NULL ;
}
void F_162 ( struct V_36 * V_64 )
{
F_12 ( & V_167 ) ;
}
static int F_163 ( void * V_66 )
{
long V_168 = ( long ) V_66 ;
bool V_169 = 0 ;
struct V_36 V_64 ;
F_85 ( & V_64 ) ;
F_83 ( L_80 ) ;
F_94 ( V_74 , 19 ) ;
do {
F_164 ( V_170 [ V_168 ] ,
V_171 != V_169 ||
F_87 () ||
V_6 != V_7 ) ;
V_169 = V_171 ;
F_81 () ;
if ( F_87 () || V_6 != V_7 )
break;
V_44 -> V_172 ( & V_64 , F_162 ) ;
if ( F_165 ( & V_173 ) )
F_166 ( & V_174 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_81 ) ;
F_5 ( L_82 ) ;
while ( ! F_87 () )
F_22 ( 1 ) ;
V_44 -> V_96 () ;
F_90 ( & V_64 ) ;
return 0 ;
}
static int F_167 ( void * V_66 )
{
int V_37 ;
F_83 ( L_83 ) ;
do {
F_168 ( & V_167 , 0 ) ;
F_168 ( & V_173 , V_151 ) ;
F_81 () ;
V_171 = ! V_171 ;
for ( V_37 = 0 ; V_37 < V_151 ; V_37 ++ )
F_166 ( & V_170 [ V_37 ] ) ;
F_164 ( V_174 ,
F_102 ( & V_173 ) == 0 ||
F_87 () ||
V_6 != V_7 ) ;
if ( F_87 () || V_6 != V_7 )
break;
V_129 ++ ;
V_44 -> V_96 () ;
if ( F_102 ( & V_167 ) != V_151 ) {
V_130 ++ ;
F_122 ( 1 ) ;
}
V_128 ++ ;
F_22 ( V_31 / 10 ) ;
} while ( ! F_87 () && V_6 == V_7 );
F_83 ( L_84 ) ;
F_5 ( L_85 ) ;
while ( ! F_87 () )
F_22 ( 1 ) ;
return 0 ;
}
static int F_169 ( void )
{
int V_37 ;
int V_162 ;
if ( V_151 == 0 )
return 0 ;
if ( V_44 -> V_172 == NULL || V_44 -> V_96 == NULL ) {
F_124 ( L_36 V_59
L_86 ,
V_58 , V_44 -> V_99 ) ;
F_124 ( L_36 V_59
L_87 ,
V_58 ) ;
return 0 ;
}
F_168 ( & V_173 , 0 ) ;
F_168 ( & V_167 , 0 ) ;
V_175 =
F_170 ( V_151 * sizeof( V_175 [ 0 ] ) ,
V_176 ) ;
V_170 =
F_170 ( V_151 * sizeof( V_170 [ 0 ] ) ,
V_176 ) ;
if ( V_175 == NULL || V_170 == 0 )
return - V_177 ;
for ( V_37 = 0 ; V_37 < V_151 ; V_37 ++ ) {
F_171 ( & V_170 [ V_37 ] ) ;
V_175 [ V_37 ] = F_156 ( F_163 ,
( void * ) ( long ) V_37 ,
L_82 ) ;
if ( F_141 ( V_175 [ V_37 ] ) ) {
V_162 = F_142 ( V_175 [ V_37 ] ) ;
F_172 ( L_88 ) ;
V_175 [ V_37 ] = NULL ;
return V_162 ;
}
}
V_178 = F_156 ( F_167 , NULL ,
L_85 ) ;
if ( F_141 ( V_178 ) ) {
V_162 = F_142 ( V_178 ) ;
F_172 ( L_89 ) ;
V_178 = NULL ;
}
return 0 ;
}
static void F_173 ( void )
{
int V_37 ;
if ( V_178 != NULL ) {
F_83 ( L_90 ) ;
F_137 ( V_178 ) ;
V_178 = NULL ;
}
if ( V_175 != NULL ) {
for ( V_37 = 0 ; V_37 < V_151 ; V_37 ++ ) {
if ( V_175 [ V_37 ] != NULL ) {
F_83 ( L_91 ) ;
F_137 ( V_175 [ V_37 ] ) ;
V_175 [ V_37 ] = NULL ;
}
}
F_174 ( V_175 ) ;
V_175 = NULL ;
}
if ( V_170 != NULL ) {
F_174 ( V_170 ) ;
V_170 = NULL ;
}
}
static int F_175 ( struct V_1 * V_179 ,
unsigned long V_180 , void * V_181 )
{
long V_56 = ( long ) V_181 ;
switch ( V_180 ) {
case V_182 :
case V_183 :
( void ) F_138 ( V_56 ) ;
break;
case V_184 :
F_136 ( V_56 ) ;
break;
default:
break;
}
return V_185 ;
}
static void
F_146 ( void )
{
int V_37 ;
F_2 ( & V_5 ) ;
F_176 () ;
if ( V_6 == V_8 ) {
F_3 (
L_1 ) ;
F_4 ( & V_5 ) ;
F_8 ( 10 ) ;
if ( V_44 -> V_96 != NULL )
V_44 -> V_96 () ;
return;
}
V_6 = V_186 ;
F_4 ( & V_5 ) ;
F_177 ( & V_187 ) ;
F_173 () ;
F_161 () ;
if ( V_188 ) {
F_83 ( L_92 ) ;
F_137 ( V_188 ) ;
}
V_188 = NULL ;
if ( V_189 ) {
F_83 ( L_93 ) ;
F_137 ( V_189 ) ;
F_178 ( V_135 ) ;
}
V_189 = NULL ;
if ( V_94 ) {
F_83 ( L_94 ) ;
F_137 ( V_94 ) ;
}
V_94 = NULL ;
if ( V_137 ) {
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
if ( V_137 [ V_37 ] ) {
F_83 (
L_95 ) ;
F_137 ( V_137 [ V_37 ] ) ;
}
V_137 [ V_37 ] = NULL ;
}
F_174 ( V_137 ) ;
V_137 = NULL ;
}
V_93 = NULL ;
if ( V_138 ) {
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ ) {
if ( V_138 [ V_37 ] ) {
F_83 (
L_96 ) ;
F_137 ( V_138 [ V_37 ] ) ;
}
V_138 [ V_37 ] = NULL ;
}
F_174 ( V_138 ) ;
V_138 = NULL ;
}
if ( V_139 ) {
F_83 ( L_97 ) ;
F_137 ( V_139 ) ;
}
V_139 = NULL ;
if ( V_190 ) {
F_83 ( L_98 ) ;
F_137 ( V_190 ) ;
}
V_190 = NULL ;
if ( ( V_146 == 1 && V_44 -> V_147 ) ||
V_146 == 2 ) {
F_179 ( & V_191 ) ;
F_68 (i)
F_136 ( V_37 ) ;
}
if ( V_160 != NULL ) {
F_83 ( L_99 ) ;
F_137 ( V_160 ) ;
}
V_160 = NULL ;
F_157 () ;
if ( V_44 -> V_96 != NULL )
V_44 -> V_96 () ;
F_123 () ;
if ( F_102 ( & V_131 ) || V_130 )
F_135 ( V_44 , L_100 ) ;
else if ( V_118 != V_119 ||
V_120 != V_121 )
F_135 ( V_44 ,
L_101 ) ;
else
F_135 ( V_44 , L_102 ) ;
}
static int T_5
F_180 ( void )
{
int V_37 ;
int V_56 ;
int V_192 = 0 ;
int V_156 ;
static struct V_142 * V_193 [] =
{ & V_194 , & V_195 , & V_196 ,
& V_197 , & V_198 , & V_199 ,
& V_200 , & V_201 , & V_202 ,
& V_203 , & V_204 ,
& V_205 , & V_206 , & V_207 , } ;
F_2 ( & V_5 ) ;
for ( V_37 = 0 ; V_37 < F_181 ( V_193 ) ; V_37 ++ ) {
V_44 = V_193 [ V_37 ] ;
if ( strcmp ( V_58 , V_44 -> V_99 ) == 0 )
break;
}
if ( V_37 == F_181 ( V_193 ) ) {
F_124 ( L_103 ,
V_58 ) ;
F_124 ( L_104 ) ;
for ( V_37 = 0 ; V_37 < F_181 ( V_193 ) ; V_37 ++ )
F_124 ( L_105 , V_193 [ V_37 ] -> V_99 ) ;
F_124 ( L_5 ) ;
F_4 ( & V_5 ) ;
return - V_208 ;
}
if ( V_44 -> V_89 == NULL && V_88 != 0 ) {
F_124 ( L_106 ) ;
V_88 = 0 ;
}
if ( V_44 -> V_209 )
V_44 -> V_209 () ;
if ( V_210 >= 0 )
V_34 = V_210 ;
else
V_34 = 2 * F_129 () ;
F_135 ( V_44 , L_107 ) ;
V_6 = V_7 ;
F_45 ( & V_16 ) ;
for ( V_37 = 0 ; V_37 < F_181 ( V_211 ) ; V_37 ++ ) {
V_211 [ V_37 ] . V_43 = 0 ;
F_17 ( & V_211 [ V_37 ] . V_20 ,
& V_16 ) ;
}
V_93 = NULL ;
V_95 = 0 ;
F_168 ( & V_18 , 0 ) ;
F_168 ( & V_17 , 0 ) ;
F_168 ( & V_21 , 0 ) ;
F_168 ( & V_106 , 0 ) ;
F_168 ( & V_131 , 0 ) ;
V_130 = 0 ;
V_117 = 0 ;
V_76 = 0 ;
V_81 = 0 ;
V_84 = 0 ;
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ )
F_168 ( & V_42 [ V_37 ] , 0 ) ;
F_68 (cpu) {
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ ) {
F_121 ( V_109 , V_56 ) [ V_37 ] = 0 ;
F_121 ( V_110 , V_56 ) [ V_37 ] = 0 ;
}
}
F_83 ( L_108 ) ;
V_94 = F_182 ( F_92 , NULL ,
L_15 ) ;
if ( F_141 ( V_94 ) ) {
V_192 = F_142 ( V_94 ) ;
F_172 ( L_109 ) ;
V_94 = NULL ;
goto V_212;
}
F_144 ( V_94 ) ;
V_138 = F_170 ( V_97 * sizeof( V_138 [ 0 ] ) ,
V_176 ) ;
if ( V_138 == NULL ) {
F_172 ( L_110 ) ;
V_192 = - V_177 ;
goto V_212;
}
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ ) {
F_83 ( L_111 ) ;
V_138 [ V_37 ] = F_156 ( F_99 , NULL ,
L_18 ) ;
if ( F_141 ( V_138 [ V_37 ] ) ) {
V_192 = F_142 ( V_138 [ V_37 ] ) ;
F_172 ( L_112 ) ;
V_138 [ V_37 ] = NULL ;
goto V_212;
}
}
V_137 = F_170 ( V_34 * sizeof( V_137 [ 0 ] ) ,
V_176 ) ;
if ( V_137 == NULL ) {
F_172 ( L_110 ) ;
V_192 = - V_177 ;
goto V_212;
}
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
F_83 ( L_113 ) ;
V_137 [ V_37 ] = F_156 ( F_114 , NULL ,
L_21 ) ;
if ( F_141 ( V_137 [ V_37 ] ) ) {
V_192 = F_142 ( V_137 [ V_37 ] ) ;
F_172 ( L_114 ) ;
V_137 [ V_37 ] = NULL ;
goto V_212;
}
}
if ( V_134 > 0 ) {
F_83 ( L_115 ) ;
V_139 = F_156 ( F_125 , NULL ,
L_38 ) ;
if ( F_141 ( V_139 ) ) {
V_192 = F_142 ( V_139 ) ;
F_172 ( L_116 ) ;
V_139 = NULL ;
goto V_212;
}
}
if ( V_145 ) {
V_136 = F_129 () - 1 ;
if ( ! F_183 ( & V_135 , V_176 ) ) {
V_192 = - V_177 ;
F_172 ( L_117 ) ;
goto V_212;
}
V_189 = F_156 ( F_133 , NULL ,
L_41 ) ;
if ( F_141 ( V_189 ) ) {
F_178 ( V_135 ) ;
V_192 = F_142 ( V_189 ) ;
F_172 ( L_118 ) ;
V_189 = NULL ;
goto V_212;
}
}
if ( V_141 < 0 )
V_141 = 0 ;
if ( V_141 ) {
V_188 = F_156 ( F_134 , NULL ,
L_44 ) ;
if ( F_141 ( V_188 ) ) {
V_192 = F_142 ( V_188 ) ;
F_172 ( L_119 ) ;
V_188 = NULL ;
goto V_212;
}
}
if ( V_88 < 0 )
V_88 = 0 ;
if ( V_88 ) {
V_190 = F_156 ( F_91 , NULL ,
L_12 ) ;
if ( F_141 ( V_190 ) ) {
V_192 = F_142 ( V_190 ) ;
F_172 ( L_120 ) ;
V_190 = NULL ;
goto V_212;
}
}
if ( V_83 < 1 )
V_83 = 1 ;
if ( V_80 < 2 )
V_80 = 2 ;
if ( ( V_146 == 1 && V_44 -> V_147 ) ||
V_146 == 2 ) {
V_77 = V_78 + V_83 * V_31 ;
F_184 ( & V_191 ) ;
F_68 (i) {
if ( F_185 ( V_37 ) )
continue;
V_156 = F_138 ( V_37 ) ;
if ( V_156 < 0 ) {
V_192 = V_156 ;
goto V_212;
}
}
}
if ( V_148 > 0 ) {
V_159 = V_78 + V_148 * V_31 ;
V_160 = F_182 ( F_145 , NULL ,
L_121 ) ;
if ( F_141 ( V_160 ) ) {
V_192 = F_142 ( V_160 ) ;
F_172 ( L_122 ) ;
V_160 = NULL ;
goto V_212;
}
F_144 ( V_160 ) ;
}
V_37 = F_155 () ;
if ( V_37 != 0 ) {
V_192 = V_37 ;
goto V_212;
}
F_186 ( & V_187 ) ;
V_37 = F_160 () ;
if ( V_37 != 0 ) {
V_192 = V_37 ;
goto V_212;
}
V_156 = F_169 () ;
if ( V_156 != 0 ) {
V_192 = V_156 ;
goto V_212;
}
F_176 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_212:
F_4 ( & V_5 ) ;
F_146 () ;
return V_192 ;
}
