static int
F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_6 == V_7 )
V_6 = V_8 ;
else
F_3 ( V_9
L_1 ) ;
F_4 ( & V_5 ) ;
return V_10 ;
}
static void F_5 ( char * V_11 )
{
if ( F_6 ( V_6 ) == V_8 ) {
F_3 ( V_12
L_2 ,
V_11 ) ;
F_7 ( V_13 ) ;
}
}
static struct V_14 *
F_8 ( void )
{
struct V_15 * V_16 ;
F_9 ( & V_17 ) ;
if ( F_10 ( & V_18 ) ) {
F_11 ( & V_19 ) ;
F_12 ( & V_17 ) ;
return NULL ;
}
F_11 ( & V_20 ) ;
V_16 = V_18 . V_21 ;
F_13 ( V_16 ) ;
F_12 ( & V_17 ) ;
return F_14 ( V_16 , struct V_14 , V_22 ) ;
}
static void
F_15 ( struct V_14 * V_16 )
{
F_11 ( & V_23 ) ;
F_9 ( & V_17 ) ;
F_16 ( & V_16 -> V_22 , & V_18 ) ;
F_12 ( & V_17 ) ;
}
static unsigned long
F_17 ( struct V_24 * V_25 )
{
if ( -- V_25 -> V_26 < 0 ) {
V_25 -> V_27 += ( unsigned long ) F_18 () ;
V_25 -> V_26 = V_28 ;
}
V_25 -> V_27 = V_25 -> V_27 * V_29 + V_30 ;
return F_19 ( V_25 -> V_27 ) ;
}
static void
F_20 ( char * V_11 )
{
while ( V_31 || ! V_32 ) {
if ( V_32 )
F_21 ( 1 ) ;
else
F_21 ( F_22 ( V_33 ) ) ;
F_5 ( V_11 ) ;
}
}
static int F_23 ( void ) __acquires( T_1 )
{
F_24 () ;
return 0 ;
}
static void F_25 ( struct V_24 * V_25 )
{
const unsigned long V_34 = 200 ;
const unsigned long V_35 = 50 ;
if ( ! ( F_17 ( V_25 ) % ( V_36 * 2000 * V_35 ) ) )
F_26 ( V_35 ) ;
if ( ! ( F_17 ( V_25 ) % ( V_36 * 2 * V_34 ) ) )
F_27 ( V_34 ) ;
#ifdef F_28
if ( ! F_29 () && ! ( F_17 ( V_25 ) % ( V_36 * 20000 ) ) )
F_30 () ;
#endif
}
static void F_31 ( int V_37 ) __releases( T_1 )
{
F_32 () ;
}
static int F_33 ( void )
{
return F_34 () ;
}
static void
F_35 ( struct V_38 * V_16 )
{
int V_39 ;
struct V_14 * V_40 = F_14 ( V_16 , struct V_14 , V_41 ) ;
if ( V_6 != V_7 ) {
return;
}
V_39 = V_40 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
if ( ++ V_40 -> V_42 >= V_43 ) {
V_40 -> V_45 = 0 ;
F_15 ( V_40 ) ;
} else
V_46 -> V_47 ( V_40 ) ;
}
static int F_36 ( void )
{
return 0 ;
}
static void F_37 ( struct V_14 * V_16 )
{
F_38 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_39 ( struct V_14 * V_16 )
{
int V_39 ;
struct V_14 * V_40 ;
struct V_14 * V_48 ;
V_46 -> V_49 () ;
F_40 ( & V_16 -> V_22 , & V_50 ) ;
F_41 (rp, rp1, &rcu_torture_removed, rtort_free) {
V_39 = V_40 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
if ( ++ V_40 -> V_42 >= V_43 ) {
V_40 -> V_45 = 0 ;
F_42 ( & V_40 -> V_22 ) ;
F_15 ( V_40 ) ;
}
}
}
static void F_43 ( void )
{
F_44 ( & V_50 ) ;
}
static int F_45 ( void ) __acquires( T_2 )
{
F_46 () ;
return 0 ;
}
static void F_47 ( int V_37 ) __releases( T_2 )
{
F_48 () ;
}
static int F_49 ( void )
{
return F_50 () ;
}
static void F_51 ( struct V_14 * V_16 )
{
F_52 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_51 ) ;
F_43 () ;
}
static void F_55 ( void )
{
F_56 ( & V_51 ) ;
F_57 ( & V_51 ) ;
}
static int F_58 ( void ) __acquires( &srcu_ctl
static void F_59 ( struct V_24 * V_25 )
{
long V_52 ;
const long V_53 = 1000000 / V_33 ;
const long V_54 = 10 ;
V_52 = F_17 ( V_25 ) % ( V_36 * 2 * V_54 * V_53 ) ;
if ( ! V_52 )
F_21 ( V_54 ) ;
else
F_25 ( V_25 ) ;
}
static void F_60 ( int V_37 ) __releases( &srcu_ctl
static int F_61 ( void )
{
return F_62 ( & V_51 ) ;
}
static void F_63 ( struct V_14 * V_40 )
{
F_64 ( & V_51 , & V_40 -> V_41 , F_35 ) ;
}
static void F_65 ( void )
{
F_56 ( & V_51 ) ;
}
static int F_66 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_37 = V_51 . V_58 & 0x1 ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_3 ,
V_59 , V_60 , V_37 ) ;
F_67 (cpu) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_4 , V_57 ,
F_68 ( V_51 . V_61 , V_57 ) -> V_62 [ ! V_37 ] ,
F_68 ( V_51 . V_61 , V_57 ) -> V_62 [ V_37 ] ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
return V_56 ;
}
static int F_69 ( void ) __acquires( &srcu_ctl
static void F_70 ( int V_37 ) __releases( &srcu_ctl
static void F_71 ( void )
{
F_72 ( & V_51 ) ;
}
static int F_73 ( void )
{
F_74 () ;
return 0 ;
}
static void F_75 ( int V_37 )
{
F_76 () ;
}
static void F_77 ( struct V_14 * V_16 )
{
F_78 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_79 ( struct V_38 * V_63 )
{
struct V_64 * V_65 =
F_14 ( V_63 , struct V_64 , V_66 ) ;
F_80 () ;
V_65 -> V_67 = 0 ;
}
static int F_81 ( void * V_68 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
struct V_64 V_72 = { . V_67 = 0 } ;
struct V_73 V_74 ;
F_82 ( L_6 ) ;
V_74 . V_75 = 1 ;
if ( F_83 ( V_76 , V_77 , & V_74 ) < 0 ) {
F_82 ( L_7 ) ;
V_78 ++ ;
}
F_84 ( & V_72 . V_66 ) ;
do {
V_71 = V_79 ;
while ( F_85 ( V_80 , V_71 ) ) {
F_7 ( 1 ) ;
F_20 ( L_8 ) ;
if ( F_86 () ||
V_6 != V_7 )
goto V_81;
}
V_70 = V_71 + V_82 * V_33 ;
V_69 = V_80 ;
while ( F_85 ( V_80 , V_70 ) ) {
if ( ! V_72 . V_67 ) {
F_80 () ;
V_72 . V_67 = 1 ;
F_38 ( & V_72 . V_66 , F_79 ) ;
if ( V_80 - V_69 >
V_82 * V_33 - V_33 / 2 ) {
F_82 ( L_9 ) ;
V_83 ++ ;
}
V_69 = V_80 ;
}
F_87 () ;
F_20 ( L_8 ) ;
if ( F_86 () ||
V_6 != V_7 )
goto V_81;
}
while ( V_71 == V_79 &&
! F_86 () ) {
if ( F_88 ( & V_84 ) ) {
V_79 = V_80 +
V_85 * V_33 ;
V_86 ++ ;
F_4 ( & V_84 ) ;
break;
}
F_7 ( 1 ) ;
}
V_81: F_20 ( L_8 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_10 ) ;
F_5 ( L_8 ) ;
while ( ! F_86 () || V_72 . V_67 )
F_7 ( 1 ) ;
F_80 () ;
F_89 ( & V_72 . V_66 ) ;
return 0 ;
}
static int
F_90 ( void * V_68 )
{
unsigned long V_87 ;
int V_88 ;
F_82 ( L_11 ) ;
do {
V_87 = V_80 + V_89 * V_33 ;
while ( F_85 ( V_80 , V_87 ) &&
! F_86 () ) {
F_21 ( 1 ) ;
}
V_88 = V_90 ;
while ( V_88 > 0 &&
! F_86 () ) {
V_46 -> V_91 () ;
F_27 ( V_92 ) ;
V_88 -= V_92 ;
}
F_20 ( L_12 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_86 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_91 ( void * V_68 )
{
int V_39 ;
long V_93 = F_34 () ;
struct V_14 * V_40 ;
struct V_14 * V_94 ;
static F_92 ( rand ) ;
F_82 ( L_14 ) ;
F_93 ( V_76 , 19 ) ;
do {
F_7 ( 1 ) ;
V_40 = F_8 () ;
if ( V_40 == NULL )
continue;
V_40 -> V_42 = 0 ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_94 = F_94 ( V_95 ,
V_76 == V_96 ) ;
V_40 -> V_45 = 1 ;
F_95 ( V_95 , V_40 ) ;
F_96 () ;
if ( V_94 ) {
V_39 = V_94 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
V_94 -> V_42 ++ ;
V_46 -> V_47 ( V_94 ) ;
}
F_97 ( ++ V_97 ) ;
V_93 = V_46 -> V_58 () ;
F_20 ( L_15 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_86 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_98 ( void * V_68 )
{
F_92 ( rand ) ;
F_82 ( L_17 ) ;
F_93 ( V_76 , 19 ) ;
do {
F_7 ( 1 + F_17 ( & rand ) % 10 ) ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_46 -> V_49 () ;
F_20 ( L_18 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_86 () )
F_7 ( 1 ) ;
return 0 ;
}
void F_99 ( void )
{
static T_3 V_98 = F_100 ( 0 ) ;
if ( F_101 ( & V_98 ) )
return;
if ( F_102 ( & V_98 , 1 ) != 0 )
return;
F_103 ( V_46 -> V_99 , (struct V_38 * ) ~ 0UL ) ;
F_104 ( V_100 ) ;
}
static void F_105 ( unsigned long V_101 )
{
int V_37 ;
int V_58 ;
static F_92 ( rand ) ;
static F_106 ( V_102 ) ;
struct V_14 * V_16 ;
int V_103 ;
V_37 = V_46 -> V_104 () ;
V_58 = V_46 -> V_58 () ;
V_16 = F_94 ( V_95 ,
F_107 () ||
F_108 () ||
F_109 ( & V_51 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_105 ( V_37 ) ;
return;
}
F_103 ( V_46 -> V_99 , & V_16 -> V_41 ) ;
if ( V_16 -> V_45 == 0 )
F_11 ( & V_106 ) ;
F_110 ( & V_102 ) ;
V_46 -> V_107 ( & rand ) ;
V_108 ++ ;
F_111 ( & V_102 ) ;
F_74 () ;
V_103 = V_16 -> V_42 ;
if ( V_103 > V_43 ) {
V_103 = V_43 ;
}
if ( V_103 > 1 )
F_99 () ;
F_112 ( V_109 [ V_103 ] ) ;
V_58 = V_46 -> V_58 () - V_58 ;
if ( V_58 > V_43 ) {
V_58 = V_43 ;
}
F_112 ( V_110 [ V_58 ] ) ;
F_76 () ;
V_46 -> V_105 ( V_37 ) ;
}
static int
F_113 ( void * V_68 )
{
int V_58 ;
int V_37 ;
F_92 ( rand ) ;
struct V_14 * V_16 ;
int V_103 ;
struct V_111 V_112 ;
F_82 ( L_20 ) ;
F_93 ( V_76 , 19 ) ;
if ( V_113 && V_46 -> V_114 )
F_114 ( & V_112 , F_105 , 0 ) ;
do {
if ( V_113 && V_46 -> V_114 ) {
if ( ! F_115 ( & V_112 ) )
F_116 ( & V_112 , V_80 + 1 ) ;
}
V_37 = V_46 -> V_104 () ;
V_58 = V_46 -> V_58 () ;
V_16 = F_94 ( V_95 ,
F_107 () ||
F_108 () ||
F_109 ( & V_51 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_105 ( V_37 ) ;
F_21 ( V_33 ) ;
continue;
}
F_103 ( V_46 -> V_99 , & V_16 -> V_41 ) ;
if ( V_16 -> V_45 == 0 )
F_11 ( & V_106 ) ;
V_46 -> V_107 ( & rand ) ;
F_74 () ;
V_103 = V_16 -> V_42 ;
if ( V_103 > V_43 ) {
V_103 = V_43 ;
}
if ( V_103 > 1 )
F_99 () ;
F_112 ( V_109 [ V_103 ] ) ;
V_58 = V_46 -> V_58 () - V_58 ;
if ( V_58 > V_43 ) {
V_58 = V_43 ;
}
F_112 ( V_110 [ V_58 ] ) ;
F_76 () ;
V_46 -> V_105 ( V_37 ) ;
F_117 () ;
F_20 ( L_21 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_113 && V_46 -> V_114 )
F_118 ( & V_112 ) ;
while ( ! F_86 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_119 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_39 ;
long V_115 [ V_43 + 1 ] = { 0 } ;
long V_116 [ V_43 + 1 ] = { 0 } ;
F_67 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_115 [ V_39 ] += F_120 ( V_109 , V_57 ) [ V_39 ] ;
V_116 [ V_39 ] += F_120 ( V_110 , V_57 ) [ V_39 ] ;
}
}
for ( V_39 = V_43 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_115 [ V_39 ] != 0 )
break;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_23 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] ,
L_24
L_25
L_26
L_27
L_28 ,
V_95 ,
V_97 ,
F_10 ( & V_18 ) ,
F_101 ( & V_20 ) ,
F_101 ( & V_19 ) ,
F_101 ( & V_23 ) ,
F_101 ( & V_106 ) ,
V_117 ,
V_78 ,
V_83 ,
V_86 ,
V_108 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ,
V_122 ,
V_123 ,
V_124 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
if ( F_101 ( & V_106 ) != 0 ||
V_124 != 0 ||
V_117 != 0 ||
V_78 != 0 ||
V_83 != 0 ||
V_39 > 1 ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_30 ) ;
F_11 ( & V_125 ) ;
F_121 ( 1 ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_31 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_56 += sprintf ( & V_55 [ V_56 ] , L_32 , V_115 [ V_39 ] ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_33 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_56 += sprintf ( & V_55 [ V_56 ] , L_32 , V_116 [ V_39 ] ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_34 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_35 ,
F_101 ( & V_44 [ V_39 ] ) ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
if ( V_46 -> V_126 )
V_56 += V_46 -> V_126 ( & V_55 [ V_56 ] ) ;
return V_56 ;
}
static void
F_122 ( void )
{
int V_56 ;
V_56 = F_119 ( V_127 ) ;
F_3 ( V_128 L_36 , V_127 ) ;
}
static int
F_123 ( void * V_68 )
{
F_82 ( L_37 ) ;
do {
F_21 ( V_129 * V_33 ) ;
F_122 () ;
F_5 ( L_38 ) ;
} while ( ! F_86 () );
F_82 ( L_39 ) ;
return 0 ;
}
static void F_124 ( void )
{
int V_39 ;
F_125 ( V_130 ) ;
F_126 () ;
if ( F_127 () == 1 ) {
F_128 () ;
return;
}
if ( V_131 != - 1 )
F_129 ( V_131 , V_130 ) ;
F_130 ( V_76 , V_130 ) ;
if ( V_132 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ )
if ( V_132 [ V_39 ] )
F_130 ( V_132 [ V_39 ] ,
V_130 ) ;
}
if ( V_133 ) {
for ( V_39 = 0 ; V_39 < V_134 ; V_39 ++ )
if ( V_133 [ V_39 ] )
F_130 ( V_133 [ V_39 ] ,
V_130 ) ;
}
if ( V_96 )
F_130 ( V_96 , V_130 ) ;
if ( V_135 )
F_130 ( V_135 , V_130 ) ;
if ( V_131 == - 1 )
V_131 = F_127 () - 1 ;
else
V_131 -- ;
F_128 () ;
}
static int
F_131 ( void * V_68 )
{
F_82 ( L_40 ) ;
do {
F_21 ( V_136 * V_33 ) ;
F_124 () ;
F_5 ( L_41 ) ;
} while ( ! F_86 () );
F_82 ( L_42 ) ;
return 0 ;
}
static int
F_132 ( void * V_68 )
{
F_82 ( L_43 ) ;
do {
F_21 ( V_137 * V_33 ) ;
V_31 = 1 ;
if ( ! F_86 () )
F_21 ( V_137 * V_33 ) ;
V_31 = 0 ;
F_5 ( L_44 ) ;
} while ( ! F_86 () );
F_82 ( L_45 ) ;
return 0 ;
}
static inline void
F_133 ( struct V_138 * V_46 , char * V_139 )
{
F_3 ( V_128 L_36 V_60
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_59 , V_139 , V_36 , V_134 ,
V_129 , V_140 , V_141 , V_136 ,
V_137 , V_113 , V_90 , V_92 , V_89 ,
V_142 , V_46 -> V_143 ,
V_85 , V_82 , V_144 ,
V_145 , V_146 ) ;
}
static void F_134 ( int V_57 )
{
struct V_147 * V_112 ;
if ( V_148 [ V_57 ] == NULL )
return;
F_2 ( & V_84 ) ;
F_82 ( L_53 ) ;
V_112 = V_148 [ V_57 ] ;
V_148 [ V_57 ] = NULL ;
F_4 ( & V_84 ) ;
F_135 ( V_112 ) ;
V_148 [ V_57 ] = NULL ;
}
static int F_136 ( int V_57 )
{
int V_149 ;
if ( V_148 [ V_57 ] != NULL )
return 0 ;
F_2 ( & V_84 ) ;
F_82 ( L_54 ) ;
V_148 [ V_57 ] = F_137 ( F_81 , NULL ,
F_138 ( V_57 ) ,
L_8 ) ;
if ( F_139 ( V_148 [ V_57 ] ) ) {
V_149 = F_140 ( V_148 [ V_57 ] ) ;
F_82 ( L_55 ) ;
V_117 ++ ;
V_148 [ V_57 ] = NULL ;
F_4 ( & V_84 ) ;
return V_149 ;
}
F_141 ( V_148 [ V_57 ] , V_57 ) ;
F_142 ( V_148 [ V_57 ] ) ;
F_4 ( & V_84 ) ;
return 0 ;
}
static int
F_143 ( void * V_68 )
{
long V_150 ;
unsigned long V_151 ;
F_82 ( L_56 ) ;
V_151 = F_6 ( V_80 ) ;
while ( F_85 ( V_151 , V_152 ) &&
! F_86 () ) {
V_150 = V_152 - V_151 ;
if ( V_140 )
F_3 ( V_128 L_36 V_60
L_57
L_58 ,
V_59 , V_150 ) ;
F_21 ( V_150 ) ;
V_151 = F_6 ( V_80 ) ;
}
if ( F_86 () ) {
F_82 ( L_59 ) ;
return 0 ;
}
F_82 ( L_60 ) ;
V_153 = NULL ;
F_144 () ;
F_145 () ;
return 0 ;
}
static int T_4
F_146 ( void * V_68 )
{
int V_57 ;
int V_154 = - 1 ;
F_92 ( rand ) ;
F_82 ( L_61 ) ;
F_147 (cpu)
V_154 = V_57 ;
F_148 ( V_154 < 0 ) ;
if ( V_146 > 0 ) {
F_82 ( L_62 ) ;
F_21 ( V_146 * V_33 ) ;
F_82 ( L_63 ) ;
}
while ( ! F_86 () ) {
V_57 = ( F_17 ( & rand ) >> 4 ) % ( V_154 + 1 ) ;
if ( F_149 ( V_57 ) && F_150 ( V_57 ) ) {
if ( V_140 )
F_3 ( V_128 L_36 V_60
L_64 ,
V_59 , V_57 ) ;
V_121 ++ ;
if ( F_151 ( V_57 ) == 0 ) {
if ( V_140 )
F_3 ( V_128 L_36 V_60
L_65
L_66 ,
V_59 , V_57 ) ;
V_120 ++ ;
}
} else if ( F_150 ( V_57 ) ) {
if ( V_140 )
F_3 ( V_128 L_36 V_60
L_67 ,
V_59 , V_57 ) ;
V_119 ++ ;
if ( F_152 ( V_57 ) == 0 ) {
if ( V_140 )
F_3 ( V_128 L_36 V_60
L_65
L_68 ,
V_59 , V_57 ) ;
V_118 ++ ;
}
}
F_21 ( V_145 * V_33 ) ;
}
F_82 ( L_69 ) ;
return 0 ;
}
static int T_4
F_153 ( void )
{
int V_155 ;
if ( V_145 <= 0 )
return 0 ;
V_156 = F_154 ( F_146 , NULL , L_70 ) ;
if ( F_139 ( V_156 ) ) {
V_155 = F_140 ( V_156 ) ;
V_156 = NULL ;
return V_155 ;
}
return 0 ;
}
static void F_155 ( void )
{
if ( V_156 == NULL )
return;
F_82 ( L_71 ) ;
F_135 ( V_156 ) ;
V_156 = NULL ;
}
static int
F_153 ( void )
{
return 0 ;
}
static void F_155 ( void )
{
}
static int T_4 F_156 ( void * args )
{
unsigned long V_157 ;
F_82 ( L_72 ) ;
if ( V_158 > 0 ) {
F_82 ( L_73 ) ;
F_21 ( V_158 * V_33 ) ;
F_82 ( L_74 ) ;
}
if ( ! F_86 () ) {
V_157 = F_157 () + V_159 ;
F_3 ( V_128 L_75 ) ;
F_24 () ;
F_74 () ;
while ( F_85 ( F_157 () , V_157 ) )
continue;
F_76 () ;
F_32 () ;
F_3 ( V_128 L_76 ) ;
}
F_5 ( L_77 ) ;
while ( ! F_86 () )
F_21 ( 10 * V_33 ) ;
return 0 ;
}
static int T_5 F_158 ( void )
{
int V_155 ;
if ( V_159 <= 0 )
return 0 ;
V_160 = F_154 ( F_156 , NULL , L_77 ) ;
if ( F_139 ( V_160 ) ) {
V_155 = F_140 ( V_160 ) ;
V_160 = NULL ;
return V_155 ;
}
return 0 ;
}
static void F_159 ( void )
{
if ( V_160 == NULL )
return;
F_82 ( L_78 ) ;
F_135 ( V_160 ) ;
V_160 = NULL ;
}
void F_160 ( struct V_38 * V_66 )
{
F_11 ( & V_161 ) ;
}
static int F_161 ( void * V_68 )
{
long V_162 = ( long ) V_68 ;
struct V_38 V_66 ;
F_84 ( & V_66 ) ;
F_82 ( L_79 ) ;
F_93 ( V_76 , 19 ) ;
do {
F_162 ( V_163 [ V_162 ] ,
F_101 ( & V_164 ) == V_165 ||
F_86 () ||
V_6 != V_7 ) ;
if ( F_86 () || V_6 != V_7 )
break;
V_46 -> V_166 ( & V_66 , F_160 ) ;
if ( F_163 ( & V_164 ) )
F_164 ( & V_167 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_80 ) ;
F_5 ( L_81 ) ;
while ( ! F_86 () )
F_21 ( 1 ) ;
V_46 -> V_168 () ;
F_89 ( & V_66 ) ;
return 0 ;
}
static int F_165 ( void * V_68 )
{
int V_39 ;
F_82 ( L_82 ) ;
do {
F_166 ( & V_161 , 0 ) ;
F_166 ( & V_164 , V_165 ) ;
for ( V_39 = 0 ; V_39 < V_165 ; V_39 ++ )
F_164 ( & V_163 [ V_39 ] ) ;
F_162 ( V_167 ,
F_101 ( & V_164 ) == 0 ||
F_86 () ||
V_6 != V_7 ) ;
if ( F_86 () || V_6 != V_7 )
break;
V_123 ++ ;
V_46 -> V_168 () ;
if ( F_101 ( & V_161 ) != V_165 ) {
V_124 ++ ;
F_121 ( 1 ) ;
}
V_122 ++ ;
F_21 ( V_33 / 10 ) ;
} while ( ! F_86 () && V_6 == V_7 );
F_82 ( L_83 ) ;
F_5 ( L_81 ) ;
while ( ! F_86 () )
F_21 ( 1 ) ;
return 0 ;
}
static int F_167 ( void )
{
int V_39 ;
int V_155 ;
if ( V_165 == 0 )
return 0 ;
if ( V_46 -> V_166 == NULL || V_46 -> V_168 == NULL ) {
F_3 ( V_128 L_36 V_60
L_84 ,
V_59 , V_46 -> V_99 ) ;
F_3 ( V_128 L_36 V_60
L_85 ,
V_59 ) ;
return 0 ;
}
F_166 ( & V_164 , 0 ) ;
F_166 ( & V_161 , 0 ) ;
V_169 =
F_168 ( V_165 * sizeof( V_169 [ 0 ] ) ,
V_170 ) ;
V_163 =
F_168 ( V_165 * sizeof( V_163 [ 0 ] ) ,
V_170 ) ;
if ( V_169 == NULL || V_163 == 0 )
return - V_171 ;
for ( V_39 = 0 ; V_39 < V_165 ; V_39 ++ ) {
F_169 ( & V_163 [ V_39 ] ) ;
V_169 [ V_39 ] = F_154 ( F_161 ,
( void * ) ( long ) V_39 ,
L_81 ) ;
if ( F_139 ( V_169 [ V_39 ] ) ) {
V_155 = F_140 ( V_169 [ V_39 ] ) ;
F_170 ( L_86 ) ;
V_169 [ V_39 ] = NULL ;
return V_155 ;
}
}
V_172 = F_154 ( F_165 , NULL ,
L_87 ) ;
if ( F_139 ( V_172 ) ) {
V_155 = F_140 ( V_172 ) ;
F_170 ( L_88 ) ;
V_172 = NULL ;
}
return 0 ;
}
static void F_171 ( void )
{
int V_39 ;
if ( V_172 != NULL ) {
F_82 ( L_89 ) ;
F_135 ( V_172 ) ;
V_172 = NULL ;
}
if ( V_169 != NULL ) {
for ( V_39 = 0 ; V_39 < V_165 ; V_39 ++ ) {
if ( V_169 [ V_39 ] != NULL ) {
F_82 ( L_90 ) ;
F_135 ( V_169 [ V_39 ] ) ;
V_169 [ V_39 ] = NULL ;
}
}
F_172 ( V_169 ) ;
V_169 = NULL ;
}
if ( V_163 != NULL ) {
F_172 ( V_163 ) ;
V_163 = NULL ;
}
}
static int F_173 ( struct V_1 * V_173 ,
unsigned long V_174 , void * V_175 )
{
long V_57 = ( long ) V_175 ;
switch ( V_174 ) {
case V_176 :
case V_177 :
( void ) F_136 ( V_57 ) ;
break;
case V_178 :
F_134 ( V_57 ) ;
break;
default:
break;
}
return V_179 ;
}
static void
F_144 ( void )
{
int V_39 ;
F_2 ( & V_5 ) ;
F_174 () ;
if ( V_6 == V_8 ) {
F_3 ( V_9
L_1 ) ;
F_4 ( & V_5 ) ;
F_7 ( 10 ) ;
if ( V_46 -> V_168 != NULL )
V_46 -> V_168 () ;
return;
}
V_6 = V_180 ;
F_4 ( & V_5 ) ;
F_175 ( & V_181 ) ;
F_171 () ;
F_159 () ;
if ( V_182 ) {
F_82 ( L_91 ) ;
F_135 ( V_182 ) ;
}
V_182 = NULL ;
if ( V_183 ) {
F_82 ( L_92 ) ;
F_135 ( V_183 ) ;
F_176 ( V_130 ) ;
}
V_183 = NULL ;
if ( V_96 ) {
F_82 ( L_93 ) ;
F_135 ( V_96 ) ;
}
V_96 = NULL ;
if ( V_132 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
if ( V_132 [ V_39 ] ) {
F_82 (
L_94 ) ;
F_135 ( V_132 [ V_39 ] ) ;
}
V_132 [ V_39 ] = NULL ;
}
F_172 ( V_132 ) ;
V_132 = NULL ;
}
V_95 = NULL ;
if ( V_133 ) {
for ( V_39 = 0 ; V_39 < V_134 ; V_39 ++ ) {
if ( V_133 [ V_39 ] ) {
F_82 (
L_95 ) ;
F_135 ( V_133 [ V_39 ] ) ;
}
V_133 [ V_39 ] = NULL ;
}
F_172 ( V_133 ) ;
V_133 = NULL ;
}
if ( V_135 ) {
F_82 ( L_96 ) ;
F_135 ( V_135 ) ;
}
V_135 = NULL ;
if ( V_184 ) {
F_82 ( L_97 ) ;
F_135 ( V_184 ) ;
}
V_184 = NULL ;
if ( ( V_142 == 1 && V_46 -> V_143 ) ||
V_142 == 2 ) {
F_177 ( & V_185 ) ;
F_67 (i)
F_134 ( V_39 ) ;
}
if ( V_153 != NULL ) {
F_82 ( L_98 ) ;
F_135 ( V_153 ) ;
}
V_153 = NULL ;
F_155 () ;
if ( V_46 -> V_168 != NULL )
V_46 -> V_168 () ;
F_122 () ;
if ( V_46 -> V_186 )
V_46 -> V_186 () ;
if ( F_101 ( & V_125 ) || V_124 )
F_133 ( V_46 , L_99 ) ;
else if ( V_118 != V_119 ||
V_120 != V_121 )
F_133 ( V_46 ,
L_100 ) ;
else
F_133 ( V_46 , L_101 ) ;
}
static int T_5
F_178 ( void )
{
int V_39 ;
int V_57 ;
int V_187 = 0 ;
int V_149 ;
static struct V_138 * V_188 [] =
{ & V_189 , & V_190 , & V_191 ,
& V_192 , & V_193 , & V_194 ,
& V_195 , & V_196 , & V_197 ,
& V_198 , & V_199 ,
& V_200 , & V_201 , & V_202 , } ;
F_2 ( & V_5 ) ;
for ( V_39 = 0 ; V_39 < F_179 ( V_188 ) ; V_39 ++ ) {
V_46 = V_188 [ V_39 ] ;
if ( strcmp ( V_59 , V_46 -> V_99 ) == 0 )
break;
}
if ( V_39 == F_179 ( V_188 ) ) {
F_3 ( V_128 L_102 ,
V_59 ) ;
F_3 ( V_128 L_103 ) ;
for ( V_39 = 0 ; V_39 < F_179 ( V_188 ) ; V_39 ++ )
F_3 ( V_128 L_104 , V_188 [ V_39 ] -> V_99 ) ;
F_3 ( V_128 L_5 ) ;
F_4 ( & V_5 ) ;
return - V_203 ;
}
if ( V_46 -> V_91 == NULL && V_90 != 0 ) {
F_3 ( V_128 L_105
L_106 ) ;
V_90 = 0 ;
}
if ( V_46 -> V_204 )
V_46 -> V_204 () ;
if ( V_205 >= 0 )
V_36 = V_205 ;
else
V_36 = 2 * F_127 () ;
F_133 ( V_46 , L_107 ) ;
V_6 = V_7 ;
F_44 ( & V_18 ) ;
for ( V_39 = 0 ; V_39 < F_179 ( V_206 ) ; V_39 ++ ) {
V_206 [ V_39 ] . V_45 = 0 ;
F_16 ( & V_206 [ V_39 ] . V_22 ,
& V_18 ) ;
}
V_95 = NULL ;
V_97 = 0 ;
F_166 ( & V_20 , 0 ) ;
F_166 ( & V_19 , 0 ) ;
F_166 ( & V_23 , 0 ) ;
F_166 ( & V_106 , 0 ) ;
F_166 ( & V_125 , 0 ) ;
V_124 = 0 ;
V_117 = 0 ;
V_78 = 0 ;
V_83 = 0 ;
V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
F_166 ( & V_44 [ V_39 ] , 0 ) ;
F_67 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
F_120 ( V_109 , V_57 ) [ V_39 ] = 0 ;
F_120 ( V_110 , V_57 ) [ V_39 ] = 0 ;
}
}
F_82 ( L_108 ) ;
V_96 = F_154 ( F_91 , NULL ,
L_15 ) ;
if ( F_139 ( V_96 ) ) {
V_187 = F_140 ( V_96 ) ;
F_170 ( L_109 ) ;
V_96 = NULL ;
goto V_207;
}
V_133 = F_168 ( V_134 * sizeof( V_133 [ 0 ] ) ,
V_170 ) ;
if ( V_133 == NULL ) {
F_170 ( L_110 ) ;
V_187 = - V_171 ;
goto V_207;
}
for ( V_39 = 0 ; V_39 < V_134 ; V_39 ++ ) {
F_82 ( L_111 ) ;
V_133 [ V_39 ] = F_154 ( F_98 , NULL ,
L_18 ) ;
if ( F_139 ( V_133 [ V_39 ] ) ) {
V_187 = F_140 ( V_133 [ V_39 ] ) ;
F_170 ( L_112 ) ;
V_133 [ V_39 ] = NULL ;
goto V_207;
}
}
V_132 = F_168 ( V_36 * sizeof( V_132 [ 0 ] ) ,
V_170 ) ;
if ( V_132 == NULL ) {
F_170 ( L_110 ) ;
V_187 = - V_171 ;
goto V_207;
}
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
F_82 ( L_113 ) ;
V_132 [ V_39 ] = F_154 ( F_113 , NULL ,
L_21 ) ;
if ( F_139 ( V_132 [ V_39 ] ) ) {
V_187 = F_140 ( V_132 [ V_39 ] ) ;
F_170 ( L_114 ) ;
V_132 [ V_39 ] = NULL ;
goto V_207;
}
}
if ( V_129 > 0 ) {
F_82 ( L_115 ) ;
V_135 = F_154 ( F_123 , NULL ,
L_38 ) ;
if ( F_139 ( V_135 ) ) {
V_187 = F_140 ( V_135 ) ;
F_170 ( L_116 ) ;
V_135 = NULL ;
goto V_207;
}
}
if ( V_141 ) {
V_131 = F_127 () - 1 ;
if ( ! F_180 ( & V_130 , V_170 ) ) {
V_187 = - V_171 ;
F_170 ( L_117 ) ;
goto V_207;
}
V_183 = F_154 ( F_131 , NULL ,
L_41 ) ;
if ( F_139 ( V_183 ) ) {
F_176 ( V_130 ) ;
V_187 = F_140 ( V_183 ) ;
F_170 ( L_118 ) ;
V_183 = NULL ;
goto V_207;
}
}
if ( V_137 < 0 )
V_137 = 0 ;
if ( V_137 ) {
V_182 = F_154 ( F_132 , NULL ,
L_44 ) ;
if ( F_139 ( V_182 ) ) {
V_187 = F_140 ( V_182 ) ;
F_170 ( L_119 ) ;
V_182 = NULL ;
goto V_207;
}
}
if ( V_90 < 0 )
V_90 = 0 ;
if ( V_90 ) {
V_184 = F_154 ( F_90 , NULL ,
L_12 ) ;
if ( F_139 ( V_184 ) ) {
V_187 = F_140 ( V_184 ) ;
F_170 ( L_120 ) ;
V_184 = NULL ;
goto V_207;
}
}
if ( V_85 < 1 )
V_85 = 1 ;
if ( V_82 < 2 )
V_82 = 2 ;
if ( ( V_142 == 1 && V_46 -> V_143 ) ||
V_142 == 2 ) {
V_79 = V_80 + V_85 * V_33 ;
F_181 ( & V_185 ) ;
F_67 (i) {
if ( F_182 ( V_39 ) )
continue;
V_149 = F_136 ( V_39 ) ;
if ( V_149 < 0 ) {
V_187 = V_149 ;
goto V_207;
}
}
}
if ( V_144 > 0 ) {
V_152 = V_80 + V_144 * V_33 ;
V_153 = F_154 ( F_143 , NULL ,
L_121 ) ;
if ( F_139 ( V_153 ) ) {
V_187 = F_140 ( V_153 ) ;
F_170 ( L_122 ) ;
V_153 = NULL ;
goto V_207;
}
}
V_39 = F_153 () ;
if ( V_39 != 0 ) {
V_187 = V_39 ;
goto V_207;
}
F_183 ( & V_181 ) ;
V_39 = F_158 () ;
if ( V_39 != 0 ) {
V_187 = V_39 ;
goto V_207;
}
V_149 = F_167 () ;
if ( V_149 != 0 ) {
V_187 = V_149 ;
goto V_207;
}
F_174 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_207:
F_4 ( & V_5 ) ;
F_144 () ;
return V_187 ;
}
