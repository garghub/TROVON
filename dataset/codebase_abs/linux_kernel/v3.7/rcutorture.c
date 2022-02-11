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
static void F_54 ( void )
{
F_55 ( & V_49 ) ;
F_44 () ;
}
static void F_56 ( void )
{
F_57 ( & V_49 ) ;
F_58 ( & V_49 ) ;
}
static int F_59 ( void ) __acquires( &srcu_ctl
static void F_60 ( struct V_22 * V_23 )
{
long V_50 ;
const long V_51 = 1000000 / V_31 ;
const long V_52 = 10 ;
V_50 = F_18 ( V_23 ) % ( V_34 * 2 * V_52 * V_51 ) ;
if ( ! V_50 )
F_22 ( V_52 ) ;
else
F_26 ( V_23 ) ;
}
static void F_61 ( int V_35 ) __releases( &srcu_ctl
static int F_62 ( void )
{
return F_63 ( & V_49 ) ;
}
static void F_64 ( struct V_12 * V_38 )
{
F_65 ( & V_49 , & V_38 -> V_39 , F_36 ) ;
}
static void F_66 ( void )
{
F_57 ( & V_49 ) ;
}
static void F_67 ( struct V_36 * V_53 ,
void (* F_68)( struct V_36 * V_53 ) )
{
F_65 ( & V_49 , V_53 , F_68 ) ;
}
static void F_69 ( void )
{
F_70 ( & V_49 ) ;
}
static int F_71 ( char * V_54 )
{
int V_55 = 0 ;
int V_56 ;
int V_35 = V_49 . V_57 & 0x1 ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_3 ,
V_58 , V_59 , V_35 ) ;
F_72 (cpu) {
V_55 += sprintf ( & V_54 [ V_55 ] , L_4 , V_56 ,
F_73 ( V_49 . V_60 , V_56 ) -> V_61 [ ! V_35 ] ,
F_73 ( V_49 . V_60 , V_56 ) -> V_61 [ V_35 ] ) ;
}
V_55 += sprintf ( & V_54 [ V_55 ] , L_5 ) ;
return V_55 ;
}
static int F_74 ( void ) __acquires( &srcu_ctl
static void F_75 ( int V_35 ) __releases( &srcu_ctl
static void F_76 ( void )
{
F_77 ( & V_49 ) ;
}
static int F_78 ( void )
{
F_79 () ;
return 0 ;
}
static void F_80 ( int V_35 )
{
F_81 () ;
}
static void F_82 ( struct V_12 * V_14 )
{
F_83 ( & V_14 -> V_39 , F_36 ) ;
}
static void F_84 ( struct V_36 * V_53 )
{
struct V_62 * V_63 =
F_15 ( V_53 , struct V_62 , V_64 ) ;
F_85 () ;
V_63 -> V_65 = 0 ;
}
static int F_86 ( void * V_66 )
{
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
struct V_62 V_70 = { . V_65 = 0 } ;
struct V_71 V_72 ;
F_87 ( L_6 ) ;
V_72 . V_73 = 1 ;
if ( F_88 ( V_74 , V_75 , & V_72 ) < 0 ) {
F_87 ( L_7 ) ;
V_76 ++ ;
}
F_89 ( & V_70 . V_64 ) ;
do {
V_69 = V_77 ;
while ( F_90 ( V_78 , V_69 ) ) {
F_8 ( 1 ) ;
F_21 ( L_8 ) ;
if ( F_91 () ||
V_6 != V_7 )
goto V_79;
}
V_68 = V_69 + V_80 * V_31 ;
V_67 = V_78 ;
while ( F_90 ( V_78 , V_68 ) ) {
if ( ! V_70 . V_65 ) {
F_85 () ;
V_70 . V_65 = 1 ;
F_39 ( & V_70 . V_64 , F_84 ) ;
if ( V_78 - V_67 >
V_80 * V_31 - V_31 / 2 ) {
F_87 ( L_9 ) ;
V_81 ++ ;
}
V_67 = V_78 ;
}
F_92 () ;
F_21 ( L_8 ) ;
if ( F_91 () ||
V_6 != V_7 )
goto V_79;
}
while ( V_69 == V_77 &&
! F_91 () ) {
if ( F_93 ( & V_82 ) ) {
V_77 = V_78 +
V_83 * V_31 ;
V_84 ++ ;
F_4 ( & V_82 ) ;
break;
}
F_8 ( 1 ) ;
}
V_79: F_21 ( L_8 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_10 ) ;
F_5 ( L_8 ) ;
while ( ! F_91 () || V_70 . V_65 )
F_8 ( 1 ) ;
F_85 () ;
F_94 ( & V_70 . V_64 ) ;
return 0 ;
}
static int
F_95 ( void * V_66 )
{
unsigned long V_85 ;
int V_86 ;
F_87 ( L_11 ) ;
do {
V_85 = V_78 + V_87 * V_31 ;
while ( F_90 ( V_78 , V_85 ) &&
! F_91 () ) {
F_22 ( 1 ) ;
}
V_86 = V_88 ;
while ( V_86 > 0 &&
! F_91 () ) {
V_44 -> V_89 () ;
F_28 ( V_90 ) ;
V_86 -= V_90 ;
}
F_21 ( L_12 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_91 () )
F_8 ( 1 ) ;
return 0 ;
}
static int
F_96 ( void * V_66 )
{
int V_37 ;
long V_91 = F_35 () ;
struct V_12 * V_38 ;
struct V_12 * V_92 ;
static F_97 ( rand ) ;
F_87 ( L_14 ) ;
F_98 ( V_74 , 19 ) ;
do {
F_8 ( 1 ) ;
V_38 = F_9 () ;
if ( V_38 == NULL )
continue;
V_38 -> V_40 = 0 ;
F_28 ( F_18 ( & rand ) & 0x3ff ) ;
V_92 = F_99 ( V_93 ,
V_74 == V_94 ) ;
V_38 -> V_43 = 1 ;
F_100 ( V_93 , V_38 ) ;
F_101 () ;
if ( V_92 ) {
V_37 = V_92 -> V_40 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
F_12 ( & V_42 [ V_37 ] ) ;
V_92 -> V_40 ++ ;
V_44 -> V_45 ( V_92 ) ;
}
F_102 ( ++ V_95 ) ;
V_91 = V_44 -> V_57 () ;
F_21 ( L_15 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_91 () )
F_8 ( 1 ) ;
return 0 ;
}
static int
F_103 ( void * V_66 )
{
F_97 ( rand ) ;
F_87 ( L_17 ) ;
F_98 ( V_74 , 19 ) ;
do {
F_8 ( 1 + F_18 ( & rand ) % 10 ) ;
F_28 ( F_18 ( & rand ) & 0x3ff ) ;
if ( V_44 -> V_96 != NULL &&
F_18 ( & rand ) % ( V_97 * 8 ) == 0 )
V_44 -> V_96 () ;
else
V_44 -> V_47 () ;
F_21 ( L_18 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_91 () )
F_8 ( 1 ) ;
return 0 ;
}
void F_104 ( void )
{
static T_3 V_98 = F_105 ( 0 ) ;
if ( F_106 ( & V_98 ) )
return;
if ( F_107 ( & V_98 , 1 ) != 0 )
return;
F_108 ( V_44 -> V_99 , (struct V_36 * ) ~ 0UL ) ;
F_109 ( V_100 ) ;
}
static void F_110 ( unsigned long V_101 )
{
int V_35 ;
int V_57 ;
static F_97 ( rand ) ;
static F_111 ( V_102 ) ;
struct V_12 * V_14 ;
int V_103 ;
V_35 = V_44 -> V_104 () ;
V_57 = V_44 -> V_57 () ;
V_14 = F_99 ( V_93 ,
F_112 () ||
F_113 () ||
F_114 ( & V_49 ) ) ;
if ( V_14 == NULL ) {
V_44 -> V_105 ( V_35 ) ;
return;
}
F_108 ( V_44 -> V_99 , & V_14 -> V_39 ) ;
if ( V_14 -> V_43 == 0 )
F_12 ( & V_106 ) ;
F_115 ( & V_102 ) ;
V_44 -> V_107 ( & rand ) ;
V_108 ++ ;
F_116 ( & V_102 ) ;
F_79 () ;
V_103 = V_14 -> V_40 ;
if ( V_103 > V_41 ) {
V_103 = V_41 ;
}
if ( V_103 > 1 )
F_104 () ;
F_117 ( V_109 [ V_103 ] ) ;
V_57 = V_44 -> V_57 () - V_57 ;
if ( V_57 > V_41 ) {
V_57 = V_41 ;
}
F_117 ( V_110 [ V_57 ] ) ;
F_81 () ;
V_44 -> V_105 ( V_35 ) ;
}
static int
F_118 ( void * V_66 )
{
int V_57 ;
int V_35 ;
F_97 ( rand ) ;
struct V_12 * V_14 ;
int V_103 ;
struct V_111 V_112 ;
F_87 ( L_20 ) ;
F_98 ( V_74 , 19 ) ;
if ( V_113 && V_44 -> V_114 )
F_119 ( & V_112 , F_110 , 0 ) ;
do {
if ( V_113 && V_44 -> V_114 ) {
if ( ! F_120 ( & V_112 ) )
F_121 ( & V_112 , V_78 + 1 ) ;
}
V_35 = V_44 -> V_104 () ;
V_57 = V_44 -> V_57 () ;
V_14 = F_99 ( V_93 ,
F_112 () ||
F_113 () ||
F_114 ( & V_49 ) ) ;
if ( V_14 == NULL ) {
V_44 -> V_105 ( V_35 ) ;
F_22 ( V_31 ) ;
continue;
}
F_108 ( V_44 -> V_99 , & V_14 -> V_39 ) ;
if ( V_14 -> V_43 == 0 )
F_12 ( & V_106 ) ;
V_44 -> V_107 ( & rand ) ;
F_79 () ;
V_103 = V_14 -> V_40 ;
if ( V_103 > V_41 ) {
V_103 = V_41 ;
}
if ( V_103 > 1 )
F_104 () ;
F_117 ( V_109 [ V_103 ] ) ;
V_57 = V_44 -> V_57 () - V_57 ;
if ( V_57 > V_41 ) {
V_57 = V_41 ;
}
F_117 ( V_110 [ V_57 ] ) ;
F_81 () ;
V_44 -> V_105 ( V_35 ) ;
F_122 () ;
F_21 ( L_21 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_113 && V_44 -> V_114 )
F_123 ( & V_112 ) ;
while ( ! F_91 () )
F_8 ( 1 ) ;
return 0 ;
}
static int
F_124 ( char * V_54 )
{
int V_55 = 0 ;
int V_56 ;
int V_37 ;
long V_115 [ V_41 + 1 ] = { 0 } ;
long V_116 [ V_41 + 1 ] = { 0 } ;
F_72 (cpu) {
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ ) {
V_115 [ V_37 ] += F_125 ( V_109 , V_56 ) [ V_37 ] ;
V_116 [ V_37 ] += F_125 ( V_110 , V_56 ) [ V_37 ] ;
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
F_106 ( & V_18 ) ,
F_106 ( & V_17 ) ,
F_106 ( & V_21 ) ) ;
V_55 += sprintf ( & V_54 [ V_55 ] , L_25 ,
F_106 ( & V_106 ) ,
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
if ( F_106 ( & V_106 ) != 0 ||
V_130 != 0 ||
V_117 != 0 ||
V_76 != 0 ||
V_81 != 0 ||
V_37 > 1 ) {
V_55 += sprintf ( & V_54 [ V_55 ] , L_30 ) ;
F_12 ( & V_131 ) ;
F_126 ( 1 ) ;
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
F_106 ( & V_42 [ V_37 ] ) ) ;
}
V_55 += sprintf ( & V_54 [ V_55 ] , L_5 ) ;
if ( V_44 -> V_132 )
V_55 += V_44 -> V_132 ( & V_54 [ V_55 ] ) ;
return V_55 ;
}
static void
F_127 ( void )
{
int V_55 ;
V_55 = F_124 ( V_133 ) ;
F_128 ( L_36 , V_133 ) ;
}
static int
F_129 ( void * V_66 )
{
F_87 ( L_37 ) ;
do {
F_22 ( V_134 * V_31 ) ;
F_127 () ;
F_5 ( L_38 ) ;
} while ( ! F_91 () );
F_87 ( L_39 ) ;
return 0 ;
}
static void F_130 ( void )
{
int V_37 ;
F_131 ( V_135 ) ;
F_132 () ;
if ( F_133 () == 1 ) {
F_134 () ;
return;
}
if ( V_136 != - 1 )
F_135 ( V_136 , V_135 ) ;
F_136 ( V_74 , V_135 ) ;
if ( V_137 ) {
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ )
if ( V_137 [ V_37 ] )
F_136 ( V_137 [ V_37 ] ,
V_135 ) ;
}
if ( V_138 ) {
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ )
if ( V_138 [ V_37 ] )
F_136 ( V_138 [ V_37 ] ,
V_135 ) ;
}
if ( V_94 )
F_136 ( V_94 , V_135 ) ;
if ( V_139 )
F_136 ( V_139 , V_135 ) ;
if ( V_136 == - 1 )
V_136 = F_133 () - 1 ;
else
V_136 -- ;
F_134 () ;
}
static int
F_137 ( void * V_66 )
{
F_87 ( L_40 ) ;
do {
F_22 ( V_140 * V_31 ) ;
F_130 () ;
F_5 ( L_41 ) ;
} while ( ! F_91 () );
F_87 ( L_42 ) ;
return 0 ;
}
static int
F_138 ( void * V_66 )
{
F_87 ( L_43 ) ;
do {
F_22 ( V_141 * V_31 ) ;
V_29 = 1 ;
if ( ! F_91 () )
F_22 ( V_141 * V_31 ) ;
V_29 = 0 ;
F_5 ( L_44 ) ;
} while ( ! F_91 () );
F_87 ( L_45 ) ;
return 0 ;
}
static inline void
F_139 ( struct V_142 * V_44 , char * V_143 )
{
F_128 ( L_36 V_59
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_58 , V_143 , V_34 , V_97 ,
V_134 , V_144 , V_145 , V_140 ,
V_141 , V_113 , V_88 , V_90 , V_87 ,
V_146 , V_44 -> V_147 ,
V_83 , V_80 , V_148 ,
V_149 , V_150 ) ;
}
static void F_140 ( int V_56 )
{
struct V_151 * V_112 ;
if ( V_152 [ V_56 ] == NULL )
return;
F_2 ( & V_82 ) ;
F_87 ( L_53 ) ;
V_112 = V_152 [ V_56 ] ;
V_152 [ V_56 ] = NULL ;
F_4 ( & V_82 ) ;
F_141 ( V_112 ) ;
V_152 [ V_56 ] = NULL ;
}
static int F_142 ( int V_56 )
{
int V_153 ;
if ( V_152 [ V_56 ] != NULL )
return 0 ;
F_2 ( & V_82 ) ;
F_87 ( L_54 ) ;
V_152 [ V_56 ] = F_143 ( F_86 , NULL ,
F_144 ( V_56 ) ,
L_8 ) ;
if ( F_145 ( V_152 [ V_56 ] ) ) {
V_153 = F_146 ( V_152 [ V_56 ] ) ;
F_87 ( L_55 ) ;
V_117 ++ ;
V_152 [ V_56 ] = NULL ;
F_4 ( & V_82 ) ;
return V_153 ;
}
F_147 ( V_152 [ V_56 ] , V_56 ) ;
F_148 ( V_152 [ V_56 ] ) ;
F_4 ( & V_82 ) ;
return 0 ;
}
static int
F_149 ( void * V_66 )
{
long V_154 ;
unsigned long V_155 ;
F_87 ( L_56 ) ;
V_155 = F_6 ( V_78 ) ;
while ( F_90 ( V_155 , V_156 ) &&
! F_91 () ) {
V_154 = V_156 - V_155 ;
if ( V_144 )
F_128 ( L_36 V_59
L_57 ,
V_58 , V_154 ) ;
F_22 ( V_154 ) ;
V_155 = F_6 ( V_78 ) ;
}
if ( F_91 () ) {
F_87 ( L_58 ) ;
return 0 ;
}
F_87 ( L_59 ) ;
V_157 = NULL ;
F_150 () ;
F_151 () ;
return 0 ;
}
static int T_4
F_152 ( void * V_66 )
{
int V_56 ;
unsigned long V_154 ;
int V_158 = - 1 ;
F_97 ( rand ) ;
unsigned long V_159 ;
F_87 ( L_60 ) ;
F_153 (cpu)
V_158 = V_56 ;
F_154 ( V_158 < 0 ) ;
if ( V_150 > 0 ) {
F_87 ( L_61 ) ;
F_22 ( V_150 * V_31 ) ;
F_87 ( L_62 ) ;
}
while ( ! F_91 () ) {
V_56 = ( F_18 ( & rand ) >> 4 ) % ( V_158 + 1 ) ;
if ( F_155 ( V_56 ) && F_156 ( V_56 ) ) {
if ( V_144 )
F_128 ( L_36 V_59
L_63 ,
V_58 , V_56 ) ;
V_159 = V_78 ;
V_121 ++ ;
if ( F_157 ( V_56 ) == 0 ) {
if ( V_144 )
F_128 ( L_36 V_59
L_64 ,
V_58 , V_56 ) ;
V_120 ++ ;
V_154 = V_78 - V_159 ;
V_127 += V_154 ;
if ( V_124 < 0 ) {
V_124 = V_154 ;
V_125 = V_154 ;
}
if ( V_124 > V_154 )
V_124 = V_154 ;
if ( V_125 < V_154 )
V_125 = V_154 ;
}
} else if ( F_156 ( V_56 ) ) {
if ( V_144 )
F_128 ( L_36 V_59
L_65 ,
V_58 , V_56 ) ;
V_159 = V_78 ;
V_119 ++ ;
if ( F_158 ( V_56 ) == 0 ) {
if ( V_144 )
F_128 ( L_36 V_59
L_66 ,
V_58 , V_56 ) ;
V_118 ++ ;
V_154 = V_78 - V_159 ;
V_126 += V_154 ;
if ( V_122 < 0 ) {
V_122 = V_154 ;
V_123 = V_154 ;
}
if ( V_122 > V_154 )
V_122 = V_154 ;
if ( V_123 < V_154 )
V_123 = V_154 ;
}
}
F_22 ( V_149 * V_31 ) ;
}
F_87 ( L_67 ) ;
return 0 ;
}
static int T_4
F_159 ( void )
{
int V_160 ;
if ( V_149 <= 0 )
return 0 ;
V_161 = F_160 ( F_152 , NULL , L_68 ) ;
if ( F_145 ( V_161 ) ) {
V_160 = F_146 ( V_161 ) ;
V_161 = NULL ;
return V_160 ;
}
return 0 ;
}
static void F_161 ( void )
{
if ( V_161 == NULL )
return;
F_87 ( L_69 ) ;
F_141 ( V_161 ) ;
V_161 = NULL ;
}
static int
F_159 ( void )
{
return 0 ;
}
static void F_161 ( void )
{
}
static int T_4 F_162 ( void * args )
{
unsigned long V_162 ;
F_87 ( L_70 ) ;
if ( V_163 > 0 ) {
F_87 ( L_71 ) ;
F_22 ( V_163 * V_31 ) ;
F_87 ( L_72 ) ;
}
if ( ! F_91 () ) {
V_162 = F_163 () + V_164 ;
F_128 ( L_73 ) ;
F_25 () ;
F_79 () ;
while ( F_90 ( F_163 () , V_162 ) )
continue;
F_81 () ;
F_33 () ;
F_128 ( L_74 ) ;
}
F_5 ( L_75 ) ;
while ( ! F_91 () )
F_22 ( 10 * V_31 ) ;
return 0 ;
}
static int T_5 F_164 ( void )
{
int V_160 ;
if ( V_164 <= 0 )
return 0 ;
V_165 = F_160 ( F_162 , NULL , L_75 ) ;
if ( F_145 ( V_165 ) ) {
V_160 = F_146 ( V_165 ) ;
V_165 = NULL ;
return V_160 ;
}
return 0 ;
}
static void F_165 ( void )
{
if ( V_165 == NULL )
return;
F_87 ( L_76 ) ;
F_141 ( V_165 ) ;
V_165 = NULL ;
}
void F_166 ( struct V_36 * V_64 )
{
F_12 ( & V_166 ) ;
}
static int F_167 ( void * V_66 )
{
long V_167 = ( long ) V_66 ;
bool V_168 = 0 ;
struct V_36 V_64 ;
F_89 ( & V_64 ) ;
F_87 ( L_77 ) ;
F_98 ( V_74 , 19 ) ;
do {
F_168 ( V_169 [ V_167 ] ,
V_170 != V_168 ||
F_91 () ||
V_6 != V_7 ) ;
V_168 = V_170 ;
F_85 () ;
if ( F_91 () || V_6 != V_7 )
break;
V_44 -> V_171 ( & V_64 , F_166 ) ;
if ( F_169 ( & V_172 ) )
F_170 ( & V_173 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_78 ) ;
F_5 ( L_79 ) ;
while ( ! F_91 () )
F_22 ( 1 ) ;
V_44 -> V_96 () ;
F_94 ( & V_64 ) ;
return 0 ;
}
static int F_171 ( void * V_66 )
{
int V_37 ;
F_87 ( L_80 ) ;
do {
F_172 ( & V_166 , 0 ) ;
F_172 ( & V_172 , V_174 ) ;
F_85 () ;
V_170 = ! V_170 ;
for ( V_37 = 0 ; V_37 < V_174 ; V_37 ++ )
F_170 ( & V_169 [ V_37 ] ) ;
F_168 ( V_173 ,
F_106 ( & V_172 ) == 0 ||
F_91 () ||
V_6 != V_7 ) ;
if ( F_91 () || V_6 != V_7 )
break;
V_129 ++ ;
V_44 -> V_96 () ;
if ( F_106 ( & V_166 ) != V_174 ) {
V_130 ++ ;
F_126 ( 1 ) ;
}
V_128 ++ ;
F_22 ( V_31 / 10 ) ;
} while ( ! F_91 () && V_6 == V_7 );
F_87 ( L_81 ) ;
F_5 ( L_82 ) ;
while ( ! F_91 () )
F_22 ( 1 ) ;
return 0 ;
}
static int F_173 ( void )
{
int V_37 ;
int V_160 ;
if ( V_174 == 0 )
return 0 ;
if ( V_44 -> V_171 == NULL || V_44 -> V_96 == NULL ) {
F_128 ( L_36 V_59
L_83 ,
V_58 , V_44 -> V_99 ) ;
F_128 ( L_36 V_59
L_84 ,
V_58 ) ;
return 0 ;
}
F_172 ( & V_172 , 0 ) ;
F_172 ( & V_166 , 0 ) ;
V_175 =
F_174 ( V_174 * sizeof( V_175 [ 0 ] ) ,
V_176 ) ;
V_169 =
F_174 ( V_174 * sizeof( V_169 [ 0 ] ) ,
V_176 ) ;
if ( V_175 == NULL || V_169 == 0 )
return - V_177 ;
for ( V_37 = 0 ; V_37 < V_174 ; V_37 ++ ) {
F_175 ( & V_169 [ V_37 ] ) ;
V_175 [ V_37 ] = F_160 ( F_167 ,
( void * ) ( long ) V_37 ,
L_79 ) ;
if ( F_145 ( V_175 [ V_37 ] ) ) {
V_160 = F_146 ( V_175 [ V_37 ] ) ;
F_176 ( L_85 ) ;
V_175 [ V_37 ] = NULL ;
return V_160 ;
}
}
V_178 = F_160 ( F_171 , NULL ,
L_82 ) ;
if ( F_145 ( V_178 ) ) {
V_160 = F_146 ( V_178 ) ;
F_176 ( L_86 ) ;
V_178 = NULL ;
}
return 0 ;
}
static void F_177 ( void )
{
int V_37 ;
if ( V_178 != NULL ) {
F_87 ( L_87 ) ;
F_141 ( V_178 ) ;
V_178 = NULL ;
}
if ( V_175 != NULL ) {
for ( V_37 = 0 ; V_37 < V_174 ; V_37 ++ ) {
if ( V_175 [ V_37 ] != NULL ) {
F_87 ( L_88 ) ;
F_141 ( V_175 [ V_37 ] ) ;
V_175 [ V_37 ] = NULL ;
}
}
F_178 ( V_175 ) ;
V_175 = NULL ;
}
if ( V_169 != NULL ) {
F_178 ( V_169 ) ;
V_169 = NULL ;
}
}
static int F_179 ( struct V_1 * V_179 ,
unsigned long V_180 , void * V_181 )
{
long V_56 = ( long ) V_181 ;
switch ( V_180 ) {
case V_182 :
case V_183 :
( void ) F_142 ( V_56 ) ;
break;
case V_184 :
F_140 ( V_56 ) ;
break;
default:
break;
}
return V_185 ;
}
static void
F_150 ( void )
{
int V_37 ;
F_2 ( & V_5 ) ;
F_180 () ;
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
F_181 ( & V_187 ) ;
F_177 () ;
F_165 () ;
if ( V_188 ) {
F_87 ( L_89 ) ;
F_141 ( V_188 ) ;
}
V_188 = NULL ;
if ( V_189 ) {
F_87 ( L_90 ) ;
F_141 ( V_189 ) ;
F_182 ( V_135 ) ;
}
V_189 = NULL ;
if ( V_94 ) {
F_87 ( L_91 ) ;
F_141 ( V_94 ) ;
}
V_94 = NULL ;
if ( V_137 ) {
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
if ( V_137 [ V_37 ] ) {
F_87 (
L_92 ) ;
F_141 ( V_137 [ V_37 ] ) ;
}
V_137 [ V_37 ] = NULL ;
}
F_178 ( V_137 ) ;
V_137 = NULL ;
}
V_93 = NULL ;
if ( V_138 ) {
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ ) {
if ( V_138 [ V_37 ] ) {
F_87 (
L_93 ) ;
F_141 ( V_138 [ V_37 ] ) ;
}
V_138 [ V_37 ] = NULL ;
}
F_178 ( V_138 ) ;
V_138 = NULL ;
}
if ( V_139 ) {
F_87 ( L_94 ) ;
F_141 ( V_139 ) ;
}
V_139 = NULL ;
if ( V_190 ) {
F_87 ( L_95 ) ;
F_141 ( V_190 ) ;
}
V_190 = NULL ;
if ( ( V_146 == 1 && V_44 -> V_147 ) ||
V_146 == 2 ) {
F_183 ( & V_191 ) ;
F_72 (i)
F_140 ( V_37 ) ;
}
if ( V_157 != NULL ) {
F_87 ( L_96 ) ;
F_141 ( V_157 ) ;
}
V_157 = NULL ;
F_161 () ;
if ( V_44 -> V_96 != NULL )
V_44 -> V_96 () ;
F_127 () ;
if ( V_44 -> V_192 )
V_44 -> V_192 () ;
if ( F_106 ( & V_131 ) || V_130 )
F_139 ( V_44 , L_97 ) ;
else if ( V_118 != V_119 ||
V_120 != V_121 )
F_139 ( V_44 ,
L_98 ) ;
else
F_139 ( V_44 , L_99 ) ;
}
static int T_5
F_184 ( void )
{
int V_37 ;
int V_56 ;
int V_193 = 0 ;
int V_153 ;
static struct V_142 * V_194 [] =
{ & V_195 , & V_196 , & V_197 ,
& V_198 , & V_199 , & V_200 ,
& V_201 , & V_202 , & V_203 ,
& V_204 , & V_205 ,
& V_206 , & V_207 , & V_208 , } ;
F_2 ( & V_5 ) ;
for ( V_37 = 0 ; V_37 < F_185 ( V_194 ) ; V_37 ++ ) {
V_44 = V_194 [ V_37 ] ;
if ( strcmp ( V_58 , V_44 -> V_99 ) == 0 )
break;
}
if ( V_37 == F_185 ( V_194 ) ) {
F_128 ( L_100 ,
V_58 ) ;
F_128 ( L_101 ) ;
for ( V_37 = 0 ; V_37 < F_185 ( V_194 ) ; V_37 ++ )
F_128 ( L_102 , V_194 [ V_37 ] -> V_99 ) ;
F_128 ( L_5 ) ;
F_4 ( & V_5 ) ;
return - V_209 ;
}
if ( V_44 -> V_89 == NULL && V_88 != 0 ) {
F_128 ( L_103 ) ;
V_88 = 0 ;
}
if ( V_44 -> V_210 )
V_44 -> V_210 () ;
if ( V_211 >= 0 )
V_34 = V_211 ;
else
V_34 = 2 * F_133 () ;
F_139 ( V_44 , L_104 ) ;
V_6 = V_7 ;
F_45 ( & V_16 ) ;
for ( V_37 = 0 ; V_37 < F_185 ( V_212 ) ; V_37 ++ ) {
V_212 [ V_37 ] . V_43 = 0 ;
F_17 ( & V_212 [ V_37 ] . V_20 ,
& V_16 ) ;
}
V_93 = NULL ;
V_95 = 0 ;
F_172 ( & V_18 , 0 ) ;
F_172 ( & V_17 , 0 ) ;
F_172 ( & V_21 , 0 ) ;
F_172 ( & V_106 , 0 ) ;
F_172 ( & V_131 , 0 ) ;
V_130 = 0 ;
V_117 = 0 ;
V_76 = 0 ;
V_81 = 0 ;
V_84 = 0 ;
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ )
F_172 ( & V_42 [ V_37 ] , 0 ) ;
F_72 (cpu) {
for ( V_37 = 0 ; V_37 < V_41 + 1 ; V_37 ++ ) {
F_125 ( V_109 , V_56 ) [ V_37 ] = 0 ;
F_125 ( V_110 , V_56 ) [ V_37 ] = 0 ;
}
}
F_87 ( L_105 ) ;
V_94 = F_186 ( F_96 , NULL ,
L_15 ) ;
if ( F_145 ( V_94 ) ) {
V_193 = F_146 ( V_94 ) ;
F_176 ( L_106 ) ;
V_94 = NULL ;
goto V_213;
}
F_148 ( V_94 ) ;
V_138 = F_174 ( V_97 * sizeof( V_138 [ 0 ] ) ,
V_176 ) ;
if ( V_138 == NULL ) {
F_176 ( L_107 ) ;
V_193 = - V_177 ;
goto V_213;
}
for ( V_37 = 0 ; V_37 < V_97 ; V_37 ++ ) {
F_87 ( L_108 ) ;
V_138 [ V_37 ] = F_160 ( F_103 , NULL ,
L_18 ) ;
if ( F_145 ( V_138 [ V_37 ] ) ) {
V_193 = F_146 ( V_138 [ V_37 ] ) ;
F_176 ( L_109 ) ;
V_138 [ V_37 ] = NULL ;
goto V_213;
}
}
V_137 = F_174 ( V_34 * sizeof( V_137 [ 0 ] ) ,
V_176 ) ;
if ( V_137 == NULL ) {
F_176 ( L_107 ) ;
V_193 = - V_177 ;
goto V_213;
}
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
F_87 ( L_110 ) ;
V_137 [ V_37 ] = F_160 ( F_118 , NULL ,
L_21 ) ;
if ( F_145 ( V_137 [ V_37 ] ) ) {
V_193 = F_146 ( V_137 [ V_37 ] ) ;
F_176 ( L_111 ) ;
V_137 [ V_37 ] = NULL ;
goto V_213;
}
}
if ( V_134 > 0 ) {
F_87 ( L_112 ) ;
V_139 = F_160 ( F_129 , NULL ,
L_38 ) ;
if ( F_145 ( V_139 ) ) {
V_193 = F_146 ( V_139 ) ;
F_176 ( L_113 ) ;
V_139 = NULL ;
goto V_213;
}
}
if ( V_145 ) {
V_136 = F_133 () - 1 ;
if ( ! F_187 ( & V_135 , V_176 ) ) {
V_193 = - V_177 ;
F_176 ( L_114 ) ;
goto V_213;
}
V_189 = F_160 ( F_137 , NULL ,
L_41 ) ;
if ( F_145 ( V_189 ) ) {
F_182 ( V_135 ) ;
V_193 = F_146 ( V_189 ) ;
F_176 ( L_115 ) ;
V_189 = NULL ;
goto V_213;
}
}
if ( V_141 < 0 )
V_141 = 0 ;
if ( V_141 ) {
V_188 = F_160 ( F_138 , NULL ,
L_44 ) ;
if ( F_145 ( V_188 ) ) {
V_193 = F_146 ( V_188 ) ;
F_176 ( L_116 ) ;
V_188 = NULL ;
goto V_213;
}
}
if ( V_88 < 0 )
V_88 = 0 ;
if ( V_88 ) {
V_190 = F_160 ( F_95 , NULL ,
L_12 ) ;
if ( F_145 ( V_190 ) ) {
V_193 = F_146 ( V_190 ) ;
F_176 ( L_117 ) ;
V_190 = NULL ;
goto V_213;
}
}
if ( V_83 < 1 )
V_83 = 1 ;
if ( V_80 < 2 )
V_80 = 2 ;
if ( ( V_146 == 1 && V_44 -> V_147 ) ||
V_146 == 2 ) {
V_77 = V_78 + V_83 * V_31 ;
F_188 ( & V_191 ) ;
F_72 (i) {
if ( F_189 ( V_37 ) )
continue;
V_153 = F_142 ( V_37 ) ;
if ( V_153 < 0 ) {
V_193 = V_153 ;
goto V_213;
}
}
}
if ( V_148 > 0 ) {
V_156 = V_78 + V_148 * V_31 ;
V_157 = F_186 ( F_149 , NULL ,
L_118 ) ;
if ( F_145 ( V_157 ) ) {
V_193 = F_146 ( V_157 ) ;
F_176 ( L_119 ) ;
V_157 = NULL ;
goto V_213;
}
F_148 ( V_157 ) ;
}
V_37 = F_159 () ;
if ( V_37 != 0 ) {
V_193 = V_37 ;
goto V_213;
}
F_190 ( & V_187 ) ;
V_37 = F_164 () ;
if ( V_37 != 0 ) {
V_193 = V_37 ;
goto V_213;
}
V_153 = F_173 () ;
if ( V_153 != 0 ) {
V_193 = V_153 ;
goto V_213;
}
F_180 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_213:
F_4 ( & V_5 ) ;
F_150 () ;
return V_193 ;
}
