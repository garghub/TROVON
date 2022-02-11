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
static void F_63 ( void )
{
F_56 ( & V_51 ) ;
}
static int F_64 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_37 = V_51 . V_58 & 0x1 ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_3 ,
V_59 , V_60 , V_37 ) ;
F_65 (cpu) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_4 , V_57 ,
F_66 ( V_51 . V_61 , V_57 ) -> V_62 [ ! V_37 ] ,
F_66 ( V_51 . V_61 , V_57 ) -> V_62 [ V_37 ] ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
return V_56 ;
}
static int F_67 ( void ) __acquires( &srcu_ctl
static void F_68 ( int V_37 ) __releases( &srcu_ctl
static void F_69 ( void )
{
F_70 ( & V_51 ) ;
}
static int F_71 ( void )
{
F_72 () ;
return 0 ;
}
static void F_73 ( int V_37 )
{
F_74 () ;
}
static void F_75 ( struct V_14 * V_16 )
{
F_76 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_77 ( struct V_38 * V_63 )
{
struct V_64 * V_65 =
F_14 ( V_63 , struct V_64 , V_66 ) ;
F_78 () ;
V_65 -> V_67 = 0 ;
}
static int F_79 ( void * V_68 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
struct V_64 V_72 = { . V_67 = 0 } ;
struct V_73 V_74 ;
F_80 ( L_6 ) ;
V_74 . V_75 = 1 ;
if ( F_81 ( V_76 , V_77 , & V_74 ) < 0 ) {
F_80 ( L_7 ) ;
V_78 ++ ;
}
F_82 ( & V_72 . V_66 ) ;
do {
V_71 = V_79 ;
while ( F_83 ( V_80 , V_71 ) ) {
F_7 ( 1 ) ;
F_20 ( L_8 ) ;
if ( F_84 () ||
V_6 != V_7 )
goto V_81;
}
V_70 = V_71 + V_82 * V_33 ;
V_69 = V_80 ;
while ( F_83 ( V_80 , V_70 ) ) {
if ( ! V_72 . V_67 ) {
F_78 () ;
V_72 . V_67 = 1 ;
F_38 ( & V_72 . V_66 , F_77 ) ;
if ( V_80 - V_69 >
V_82 * V_33 - V_33 / 2 ) {
F_80 ( L_9 ) ;
V_83 ++ ;
}
V_69 = V_80 ;
}
F_85 () ;
F_20 ( L_8 ) ;
if ( F_84 () ||
V_6 != V_7 )
goto V_81;
}
while ( V_71 == V_79 &&
! F_84 () ) {
if ( F_86 ( & V_84 ) ) {
V_79 = V_80 +
V_85 * V_33 ;
V_86 ++ ;
F_4 ( & V_84 ) ;
break;
}
F_7 ( 1 ) ;
}
V_81: F_20 ( L_8 ) ;
} while ( ! F_84 () && V_6 == V_7 );
F_80 ( L_10 ) ;
F_5 ( L_8 ) ;
while ( ! F_84 () || V_72 . V_67 )
F_7 ( 1 ) ;
F_78 () ;
F_87 ( & V_72 . V_66 ) ;
return 0 ;
}
static int
F_88 ( void * V_68 )
{
unsigned long V_87 ;
int V_88 ;
F_80 ( L_11 ) ;
do {
V_87 = V_80 + V_89 * V_33 ;
while ( F_83 ( V_80 , V_87 ) &&
! F_84 () ) {
F_21 ( 1 ) ;
}
V_88 = V_90 ;
while ( V_88 > 0 &&
! F_84 () ) {
V_46 -> V_91 () ;
F_27 ( V_92 ) ;
V_88 -= V_92 ;
}
F_20 ( L_12 ) ;
} while ( ! F_84 () && V_6 == V_7 );
F_80 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_84 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_89 ( void * V_68 )
{
int V_39 ;
long V_93 = F_34 () ;
struct V_14 * V_40 ;
struct V_14 * V_94 ;
static F_90 ( rand ) ;
F_80 ( L_14 ) ;
F_91 ( V_76 , 19 ) ;
do {
F_7 ( 1 ) ;
V_40 = F_8 () ;
if ( V_40 == NULL )
continue;
V_40 -> V_42 = 0 ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_94 = F_92 ( V_95 ,
V_76 == V_96 ) ;
V_40 -> V_45 = 1 ;
F_93 ( V_95 , V_40 ) ;
F_94 () ;
if ( V_94 ) {
V_39 = V_94 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
V_94 -> V_42 ++ ;
V_46 -> V_47 ( V_94 ) ;
}
F_95 ( ++ V_97 ) ;
V_93 = V_46 -> V_58 () ;
F_20 ( L_15 ) ;
} while ( ! F_84 () && V_6 == V_7 );
F_80 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_84 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_96 ( void * V_68 )
{
F_90 ( rand ) ;
F_80 ( L_17 ) ;
F_91 ( V_76 , 19 ) ;
do {
F_7 ( 1 + F_17 ( & rand ) % 10 ) ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_46 -> V_49 () ;
F_20 ( L_18 ) ;
} while ( ! F_84 () && V_6 == V_7 );
F_80 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_84 () )
F_7 ( 1 ) ;
return 0 ;
}
void F_97 ( void )
{
static T_3 V_98 = F_98 ( 0 ) ;
if ( F_99 ( & V_98 ) )
return;
if ( F_100 ( & V_98 , 1 ) != 0 )
return;
F_101 ( V_46 -> V_99 , (struct V_38 * ) ~ 0UL ) ;
F_102 ( V_100 ) ;
}
static void F_103 ( unsigned long V_101 )
{
int V_37 ;
int V_58 ;
static F_90 ( rand ) ;
static F_104 ( V_102 ) ;
struct V_14 * V_16 ;
int V_103 ;
V_37 = V_46 -> V_104 () ;
V_58 = V_46 -> V_58 () ;
V_16 = F_92 ( V_95 ,
F_105 () ||
F_106 () ||
F_107 ( & V_51 ) ) ;
F_101 ( V_46 -> V_99 , & V_16 -> V_41 ) ;
if ( V_16 == NULL ) {
V_46 -> V_105 ( V_37 ) ;
return;
}
if ( V_16 -> V_45 == 0 )
F_11 ( & V_106 ) ;
F_108 ( & V_102 ) ;
V_46 -> V_107 ( & rand ) ;
V_108 ++ ;
F_109 ( & V_102 ) ;
F_72 () ;
V_103 = V_16 -> V_42 ;
if ( V_103 > V_43 ) {
V_103 = V_43 ;
}
if ( V_103 > 1 )
F_97 () ;
F_110 ( V_109 [ V_103 ] ) ;
V_58 = V_46 -> V_58 () - V_58 ;
if ( V_58 > V_43 ) {
V_58 = V_43 ;
}
F_110 ( V_110 [ V_58 ] ) ;
F_74 () ;
V_46 -> V_105 ( V_37 ) ;
}
static int
F_111 ( void * V_68 )
{
int V_58 ;
int V_37 ;
F_90 ( rand ) ;
struct V_14 * V_16 ;
int V_103 ;
struct V_111 V_112 ;
F_80 ( L_20 ) ;
F_91 ( V_76 , 19 ) ;
if ( V_113 && V_46 -> V_114 )
F_112 ( & V_112 , F_103 , 0 ) ;
do {
if ( V_113 && V_46 -> V_114 ) {
if ( ! F_113 ( & V_112 ) )
F_114 ( & V_112 , V_80 + 1 ) ;
}
V_37 = V_46 -> V_104 () ;
V_58 = V_46 -> V_58 () ;
V_16 = F_92 ( V_95 ,
F_105 () ||
F_106 () ||
F_107 ( & V_51 ) ) ;
F_101 ( V_46 -> V_99 , & V_16 -> V_41 ) ;
if ( V_16 == NULL ) {
V_46 -> V_105 ( V_37 ) ;
F_21 ( V_33 ) ;
continue;
}
if ( V_16 -> V_45 == 0 )
F_11 ( & V_106 ) ;
V_46 -> V_107 ( & rand ) ;
F_72 () ;
V_103 = V_16 -> V_42 ;
if ( V_103 > V_43 ) {
V_103 = V_43 ;
}
if ( V_103 > 1 )
F_97 () ;
F_110 ( V_109 [ V_103 ] ) ;
V_58 = V_46 -> V_58 () - V_58 ;
if ( V_58 > V_43 ) {
V_58 = V_43 ;
}
F_110 ( V_110 [ V_58 ] ) ;
F_74 () ;
V_46 -> V_105 ( V_37 ) ;
F_115 () ;
F_20 ( L_21 ) ;
} while ( ! F_84 () && V_6 == V_7 );
F_80 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_113 && V_46 -> V_114 )
F_116 ( & V_112 ) ;
while ( ! F_84 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_117 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_39 ;
long V_115 [ V_43 + 1 ] = { 0 } ;
long V_116 [ V_43 + 1 ] = { 0 } ;
F_65 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_115 [ V_39 ] += F_118 ( V_109 , V_57 ) [ V_39 ] ;
V_116 [ V_39 ] += F_118 ( V_110 , V_57 ) [ V_39 ] ;
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
L_27 ,
V_95 ,
V_97 ,
F_10 ( & V_18 ) ,
F_99 ( & V_20 ) ,
F_99 ( & V_19 ) ,
F_99 ( & V_23 ) ,
F_99 ( & V_106 ) ,
V_117 ,
V_78 ,
V_83 ,
V_86 ,
V_108 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ) ;
if ( F_99 ( & V_106 ) != 0 ||
V_117 != 0 ||
V_78 != 0 ||
V_83 != 0 )
V_56 += sprintf ( & V_55 [ V_56 ] , L_28 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 , V_59 , V_60 ) ;
if ( V_39 > 1 ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_30 ) ;
F_11 ( & V_122 ) ;
F_119 ( 1 ) ;
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
F_99 ( & V_44 [ V_39 ] ) ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
if ( V_46 -> V_123 )
V_56 += V_46 -> V_123 ( & V_55 [ V_56 ] ) ;
return V_56 ;
}
static void
F_120 ( void )
{
int V_56 ;
V_56 = F_117 ( V_124 ) ;
F_3 ( V_125 L_36 , V_124 ) ;
}
static int
F_121 ( void * V_68 )
{
F_80 ( L_37 ) ;
do {
F_21 ( V_126 * V_33 ) ;
F_120 () ;
F_5 ( L_38 ) ;
} while ( ! F_84 () );
F_80 ( L_39 ) ;
return 0 ;
}
static void F_122 ( void )
{
int V_39 ;
F_123 ( V_127 ) ;
F_124 () ;
if ( F_125 () == 1 ) {
F_126 () ;
return;
}
if ( V_128 != - 1 )
F_127 ( V_128 , V_127 ) ;
F_128 ( V_76 , V_127 ) ;
if ( V_129 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ )
if ( V_129 [ V_39 ] )
F_128 ( V_129 [ V_39 ] ,
V_127 ) ;
}
if ( V_130 ) {
for ( V_39 = 0 ; V_39 < V_131 ; V_39 ++ )
if ( V_130 [ V_39 ] )
F_128 ( V_130 [ V_39 ] ,
V_127 ) ;
}
if ( V_96 )
F_128 ( V_96 , V_127 ) ;
if ( V_132 )
F_128 ( V_132 , V_127 ) ;
if ( V_128 == - 1 )
V_128 = F_125 () - 1 ;
else
V_128 -- ;
F_126 () ;
}
static int
F_129 ( void * V_68 )
{
F_80 ( L_40 ) ;
do {
F_21 ( V_133 * V_33 ) ;
F_122 () ;
F_5 ( L_41 ) ;
} while ( ! F_84 () );
F_80 ( L_42 ) ;
return 0 ;
}
static int
F_130 ( void * V_68 )
{
F_80 ( L_43 ) ;
do {
F_21 ( V_134 * V_33 ) ;
V_31 = 1 ;
if ( ! F_84 () )
F_21 ( V_134 * V_33 ) ;
V_31 = 0 ;
F_5 ( L_44 ) ;
} while ( ! F_84 () );
F_80 ( L_45 ) ;
return 0 ;
}
static inline void
F_131 ( struct V_135 * V_46 , char * V_136 )
{
F_3 ( V_125 L_36 V_60
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_59 , V_136 , V_36 , V_131 ,
V_126 , V_137 , V_138 , V_133 ,
V_134 , V_113 , V_90 , V_92 , V_89 ,
V_139 , V_46 -> V_140 ,
V_85 , V_82 , V_141 ,
V_142 ) ;
}
static void F_132 ( int V_57 )
{
struct V_143 * V_112 ;
if ( V_144 [ V_57 ] == NULL )
return;
F_2 ( & V_84 ) ;
F_80 ( L_53 ) ;
V_112 = V_144 [ V_57 ] ;
V_144 [ V_57 ] = NULL ;
F_4 ( & V_84 ) ;
F_133 ( V_112 ) ;
}
static int F_134 ( int V_57 )
{
int V_145 ;
if ( V_144 [ V_57 ] != NULL )
return 0 ;
F_2 ( & V_84 ) ;
F_80 ( L_54 ) ;
V_144 [ V_57 ] = F_135 ( F_79 , NULL ,
F_136 ( V_57 ) ,
L_8 ) ;
if ( F_137 ( V_144 [ V_57 ] ) ) {
V_145 = F_138 ( V_144 [ V_57 ] ) ;
F_80 ( L_55 ) ;
V_117 ++ ;
V_144 [ V_57 ] = NULL ;
F_4 ( & V_84 ) ;
return V_145 ;
}
F_139 ( V_144 [ V_57 ] , V_57 ) ;
F_140 ( V_144 [ V_57 ] ) ;
F_4 ( & V_84 ) ;
return 0 ;
}
static int
F_141 ( void * V_68 )
{
long V_146 ;
unsigned long V_147 ;
F_80 ( L_56 ) ;
V_147 = F_6 ( V_80 ) ;
while ( F_83 ( V_147 , V_148 ) &&
! F_84 () ) {
V_146 = V_148 - V_147 ;
if ( V_137 )
F_3 ( V_125 L_36 V_60
L_57
L_58 ,
V_59 , V_146 ) ;
F_21 ( V_146 ) ;
V_147 = F_6 ( V_80 ) ;
}
if ( F_84 () ) {
F_80 ( L_59 ) ;
return 0 ;
}
F_80 ( L_60 ) ;
V_149 = NULL ;
F_142 () ;
F_143 () ;
return 0 ;
}
static int T_4
F_144 ( void * V_68 )
{
int V_57 ;
int V_150 = - 1 ;
F_90 ( rand ) ;
F_80 ( L_61 ) ;
F_145 (cpu)
V_150 = V_57 ;
F_146 ( V_150 < 0 ) ;
while ( ! F_84 () ) {
V_57 = ( F_17 ( & rand ) >> 4 ) % ( V_150 + 1 ) ;
if ( F_147 ( V_57 ) && F_148 ( V_57 ) ) {
if ( V_137 )
F_3 ( V_125 L_36 V_60
L_62 ,
V_59 , V_57 ) ;
V_121 ++ ;
if ( F_149 ( V_57 ) == 0 ) {
if ( V_137 )
F_3 ( V_125 L_36 V_60
L_63
L_64 ,
V_59 , V_57 ) ;
V_120 ++ ;
}
} else if ( F_148 ( V_57 ) ) {
if ( V_137 )
F_3 ( V_125 L_36 V_60
L_65 ,
V_59 , V_57 ) ;
V_119 ++ ;
if ( F_150 ( V_57 ) == 0 ) {
if ( V_137 )
F_3 ( V_125 L_36 V_60
L_63
L_66 ,
V_59 , V_57 ) ;
V_118 ++ ;
}
}
F_21 ( V_142 * V_33 ) ;
}
F_80 ( L_67 ) ;
return 0 ;
}
static int T_4
F_151 ( void )
{
if ( V_142 <= 0 )
return 0 ;
V_151 = F_152 ( F_144 , NULL , L_68 ) ;
if ( F_137 ( V_151 ) ) {
V_151 = NULL ;
return F_138 ( V_151 ) ;
}
return 0 ;
}
static void F_153 ( void )
{
if ( V_151 == NULL )
return;
F_80 ( L_69 ) ;
F_133 ( V_151 ) ;
}
static void
F_151 ( void )
{
}
static void F_153 ( void )
{
}
static int F_154 ( struct V_1 * V_152 ,
unsigned long V_153 , void * V_154 )
{
long V_57 = ( long ) V_154 ;
switch ( V_153 ) {
case V_155 :
case V_156 :
( void ) F_134 ( V_57 ) ;
break;
case V_157 :
F_132 ( V_57 ) ;
break;
default:
break;
}
return V_158 ;
}
static void
F_142 ( void )
{
int V_39 ;
F_2 ( & V_5 ) ;
F_155 () ;
if ( V_6 == V_8 ) {
F_3 ( V_9
L_1 ) ;
F_4 ( & V_5 ) ;
F_7 ( 10 ) ;
if ( V_46 -> V_159 != NULL )
V_46 -> V_159 () ;
return;
}
V_6 = V_160 ;
F_4 ( & V_5 ) ;
F_156 ( & V_161 ) ;
if ( V_162 ) {
F_80 ( L_70 ) ;
F_133 ( V_162 ) ;
}
V_162 = NULL ;
if ( V_163 ) {
F_80 ( L_71 ) ;
F_133 ( V_163 ) ;
F_157 ( V_127 ) ;
}
V_163 = NULL ;
if ( V_96 ) {
F_80 ( L_72 ) ;
F_133 ( V_96 ) ;
}
V_96 = NULL ;
if ( V_129 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
if ( V_129 [ V_39 ] ) {
F_80 (
L_73 ) ;
F_133 ( V_129 [ V_39 ] ) ;
}
V_129 [ V_39 ] = NULL ;
}
F_158 ( V_129 ) ;
V_129 = NULL ;
}
V_95 = NULL ;
if ( V_130 ) {
for ( V_39 = 0 ; V_39 < V_131 ; V_39 ++ ) {
if ( V_130 [ V_39 ] ) {
F_80 (
L_74 ) ;
F_133 ( V_130 [ V_39 ] ) ;
}
V_130 [ V_39 ] = NULL ;
}
F_158 ( V_130 ) ;
V_130 = NULL ;
}
if ( V_132 ) {
F_80 ( L_75 ) ;
F_133 ( V_132 ) ;
}
V_132 = NULL ;
if ( V_164 ) {
F_80 ( L_76 ) ;
F_133 ( V_164 ) ;
}
V_164 = NULL ;
if ( ( V_139 == 1 && V_46 -> V_140 ) ||
V_139 == 2 ) {
F_159 ( & V_165 ) ;
F_65 (i)
F_132 ( V_39 ) ;
}
if ( V_149 != NULL ) {
F_80 ( L_77 ) ;
F_133 ( V_149 ) ;
}
F_153 () ;
if ( V_46 -> V_159 != NULL )
V_46 -> V_159 () ;
F_120 () ;
if ( V_46 -> V_166 )
V_46 -> V_166 () ;
if ( F_99 ( & V_122 ) )
F_131 ( V_46 , L_78 ) ;
else
F_131 ( V_46 , L_79 ) ;
}
static int T_5
F_160 ( void )
{
int V_39 ;
int V_57 ;
int V_167 = 0 ;
static struct V_135 * V_168 [] =
{ & V_169 , & V_170 , & V_171 ,
& V_172 , & V_173 , & V_174 ,
& V_175 , & V_176 , & V_177 ,
& V_178 , & V_179 , & V_180 , } ;
F_2 ( & V_5 ) ;
for ( V_39 = 0 ; V_39 < F_161 ( V_168 ) ; V_39 ++ ) {
V_46 = V_168 [ V_39 ] ;
if ( strcmp ( V_59 , V_46 -> V_99 ) == 0 )
break;
}
if ( V_39 == F_161 ( V_168 ) ) {
F_3 ( V_125 L_80 ,
V_59 ) ;
F_3 ( V_125 L_81 ) ;
for ( V_39 = 0 ; V_39 < F_161 ( V_168 ) ; V_39 ++ )
F_3 ( V_125 L_82 , V_168 [ V_39 ] -> V_99 ) ;
F_3 ( V_125 L_5 ) ;
F_4 ( & V_5 ) ;
return - V_181 ;
}
if ( V_46 -> V_91 == NULL && V_90 != 0 ) {
F_3 ( V_125 L_83
L_84 ) ;
V_90 = 0 ;
}
if ( V_46 -> V_182 )
V_46 -> V_182 () ;
if ( V_183 >= 0 )
V_36 = V_183 ;
else
V_36 = 2 * F_125 () ;
F_131 ( V_46 , L_85 ) ;
V_6 = V_7 ;
F_44 ( & V_18 ) ;
for ( V_39 = 0 ; V_39 < F_161 ( V_184 ) ; V_39 ++ ) {
V_184 [ V_39 ] . V_45 = 0 ;
F_16 ( & V_184 [ V_39 ] . V_22 ,
& V_18 ) ;
}
V_95 = NULL ;
V_97 = 0 ;
F_162 ( & V_20 , 0 ) ;
F_162 ( & V_19 , 0 ) ;
F_162 ( & V_23 , 0 ) ;
F_162 ( & V_106 , 0 ) ;
F_162 ( & V_122 , 0 ) ;
V_117 = 0 ;
V_78 = 0 ;
V_83 = 0 ;
V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
F_162 ( & V_44 [ V_39 ] , 0 ) ;
F_65 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
F_118 ( V_109 , V_57 ) [ V_39 ] = 0 ;
F_118 ( V_110 , V_57 ) [ V_39 ] = 0 ;
}
}
F_80 ( L_86 ) ;
V_96 = F_152 ( F_89 , NULL ,
L_15 ) ;
if ( F_137 ( V_96 ) ) {
V_167 = F_138 ( V_96 ) ;
F_163 ( L_87 ) ;
V_96 = NULL ;
goto V_185;
}
V_130 = F_164 ( V_131 * sizeof( V_130 [ 0 ] ) ,
V_186 ) ;
if ( V_130 == NULL ) {
F_163 ( L_88 ) ;
V_167 = - V_187 ;
goto V_185;
}
for ( V_39 = 0 ; V_39 < V_131 ; V_39 ++ ) {
F_80 ( L_89 ) ;
V_130 [ V_39 ] = F_152 ( F_96 , NULL ,
L_18 ) ;
if ( F_137 ( V_130 [ V_39 ] ) ) {
V_167 = F_138 ( V_130 [ V_39 ] ) ;
F_163 ( L_90 ) ;
V_130 [ V_39 ] = NULL ;
goto V_185;
}
}
V_129 = F_164 ( V_36 * sizeof( V_129 [ 0 ] ) ,
V_186 ) ;
if ( V_129 == NULL ) {
F_163 ( L_88 ) ;
V_167 = - V_187 ;
goto V_185;
}
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
F_80 ( L_91 ) ;
V_129 [ V_39 ] = F_152 ( F_111 , NULL ,
L_21 ) ;
if ( F_137 ( V_129 [ V_39 ] ) ) {
V_167 = F_138 ( V_129 [ V_39 ] ) ;
F_163 ( L_92 ) ;
V_129 [ V_39 ] = NULL ;
goto V_185;
}
}
if ( V_126 > 0 ) {
F_80 ( L_93 ) ;
V_132 = F_152 ( F_121 , NULL ,
L_38 ) ;
if ( F_137 ( V_132 ) ) {
V_167 = F_138 ( V_132 ) ;
F_163 ( L_94 ) ;
V_132 = NULL ;
goto V_185;
}
}
if ( V_138 ) {
V_128 = F_125 () - 1 ;
if ( ! F_165 ( & V_127 , V_186 ) ) {
V_167 = - V_187 ;
F_163 ( L_95 ) ;
goto V_185;
}
V_163 = F_152 ( F_129 , NULL ,
L_41 ) ;
if ( F_137 ( V_163 ) ) {
F_157 ( V_127 ) ;
V_167 = F_138 ( V_163 ) ;
F_163 ( L_96 ) ;
V_163 = NULL ;
goto V_185;
}
}
if ( V_134 < 0 )
V_134 = 0 ;
if ( V_134 ) {
V_162 = F_152 ( F_130 , NULL ,
L_44 ) ;
if ( F_137 ( V_162 ) ) {
V_167 = F_138 ( V_162 ) ;
F_163 ( L_97 ) ;
V_162 = NULL ;
goto V_185;
}
}
if ( V_90 < 0 )
V_90 = 0 ;
if ( V_90 ) {
V_164 = F_152 ( F_88 , NULL ,
L_12 ) ;
if ( F_137 ( V_164 ) ) {
V_167 = F_138 ( V_164 ) ;
F_163 ( L_98 ) ;
V_164 = NULL ;
goto V_185;
}
}
if ( V_85 < 1 )
V_85 = 1 ;
if ( V_82 < 2 )
V_82 = 2 ;
if ( ( V_139 == 1 && V_46 -> V_140 ) ||
V_139 == 2 ) {
int V_145 ;
V_79 = V_80 + V_85 * V_33 ;
F_166 ( & V_165 ) ;
F_65 (i) {
if ( F_167 ( V_39 ) )
continue;
V_145 = F_134 ( V_39 ) ;
if ( V_145 < 0 ) {
V_167 = V_145 ;
goto V_185;
}
}
}
if ( V_141 > 0 ) {
V_148 = V_80 + V_141 * V_33 ;
V_149 = F_152 ( F_141 , NULL ,
L_99 ) ;
if ( F_137 ( V_149 ) ) {
V_167 = F_138 ( V_149 ) ;
F_163 ( L_100 ) ;
V_149 = NULL ;
goto V_185;
}
}
F_151 () ;
F_168 ( & V_161 ) ;
F_155 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_185:
F_4 ( & V_5 ) ;
F_142 () ;
return V_167 ;
}
