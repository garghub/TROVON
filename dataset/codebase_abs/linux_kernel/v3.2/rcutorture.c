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
static void F_67 ( void )
{
F_68 ( & V_51 ) ;
}
static int F_69 ( void )
{
F_70 () ;
return 0 ;
}
static void F_71 ( int V_37 )
{
F_72 () ;
}
static void F_73 ( struct V_14 * V_16 )
{
F_74 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_75 ( struct V_38 * V_63 )
{
struct V_64 * V_65 =
F_14 ( V_63 , struct V_64 , V_66 ) ;
F_76 () ;
V_65 -> V_67 = 0 ;
}
static int F_77 ( void * V_68 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
struct V_64 V_72 = { . V_67 = 0 } ;
struct V_73 V_74 ;
F_78 ( L_6 ) ;
V_74 . V_75 = 1 ;
if ( F_79 ( V_76 , V_77 , & V_74 ) < 0 ) {
F_78 ( L_7 ) ;
V_78 ++ ;
}
F_80 ( & V_72 . V_66 ) ;
do {
V_71 = V_79 ;
while ( F_81 ( V_80 , V_71 ) ) {
F_7 ( 1 ) ;
F_20 ( L_8 ) ;
if ( F_82 () ||
V_6 != V_7 )
goto V_81;
}
V_70 = V_71 + V_82 * V_33 ;
V_69 = V_80 ;
while ( F_81 ( V_80 , V_70 ) ) {
if ( ! V_72 . V_67 ) {
F_76 () ;
V_72 . V_67 = 1 ;
F_38 ( & V_72 . V_66 , F_75 ) ;
if ( V_80 - V_69 >
V_82 * V_33 - V_33 / 2 ) {
F_78 ( L_9 ) ;
V_83 ++ ;
}
V_69 = V_80 ;
}
F_83 () ;
F_20 ( L_8 ) ;
if ( F_82 () ||
V_6 != V_7 )
goto V_81;
}
while ( V_71 == V_79 &&
! F_82 () ) {
if ( F_84 ( & V_84 ) ) {
V_79 = V_80 +
V_85 * V_33 ;
V_86 ++ ;
F_4 ( & V_84 ) ;
break;
}
F_7 ( 1 ) ;
}
V_81: F_20 ( L_8 ) ;
} while ( ! F_82 () && V_6 == V_7 );
F_78 ( L_10 ) ;
F_5 ( L_8 ) ;
while ( ! F_82 () || V_72 . V_67 )
F_7 ( 1 ) ;
F_76 () ;
F_85 ( & V_72 . V_66 ) ;
return 0 ;
}
static int
F_86 ( void * V_68 )
{
unsigned long V_87 ;
int V_88 ;
F_78 ( L_11 ) ;
do {
V_87 = V_80 + V_89 * V_33 ;
while ( F_81 ( V_80 , V_87 ) &&
! F_82 () ) {
F_21 ( 1 ) ;
}
V_88 = V_90 ;
while ( V_88 > 0 &&
! F_82 () ) {
V_46 -> V_91 () ;
F_27 ( V_92 ) ;
V_88 -= V_92 ;
}
F_20 ( L_12 ) ;
} while ( ! F_82 () && V_6 == V_7 );
F_78 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_82 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_87 ( void * V_68 )
{
int V_39 ;
long V_93 = F_34 () ;
struct V_14 * V_40 ;
struct V_14 * V_94 ;
static F_88 ( rand ) ;
F_78 ( L_14 ) ;
F_89 ( V_76 , 19 ) ;
do {
F_7 ( 1 ) ;
V_40 = F_8 () ;
if ( V_40 == NULL )
continue;
V_40 -> V_42 = 0 ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_94 = F_90 ( V_95 ,
V_76 == V_96 ) ;
V_40 -> V_45 = 1 ;
F_91 ( V_95 , V_40 ) ;
F_92 () ;
if ( V_94 ) {
V_39 = V_94 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
V_94 -> V_42 ++ ;
V_46 -> V_47 ( V_94 ) ;
}
F_93 ( ++ V_97 ) ;
V_93 = V_46 -> V_58 () ;
F_20 ( L_15 ) ;
} while ( ! F_82 () && V_6 == V_7 );
F_78 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_82 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_94 ( void * V_68 )
{
F_88 ( rand ) ;
F_78 ( L_17 ) ;
F_89 ( V_76 , 19 ) ;
do {
F_7 ( 1 + F_17 ( & rand ) % 10 ) ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_46 -> V_49 () ;
F_20 ( L_18 ) ;
} while ( ! F_82 () && V_6 == V_7 );
F_78 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_82 () )
F_7 ( 1 ) ;
return 0 ;
}
static void F_95 ( unsigned long V_98 )
{
int V_37 ;
int V_58 ;
static F_88 ( rand ) ;
static F_96 ( V_99 ) ;
struct V_14 * V_16 ;
int V_100 ;
V_37 = V_46 -> V_101 () ;
V_58 = V_46 -> V_58 () ;
V_16 = F_90 ( V_95 ,
F_97 () ||
F_98 () ||
F_99 ( & V_51 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_102 ( V_37 ) ;
return;
}
if ( V_16 -> V_45 == 0 )
F_11 ( & V_103 ) ;
F_100 ( & V_99 ) ;
V_46 -> V_104 ( & rand ) ;
V_105 ++ ;
F_101 ( & V_99 ) ;
F_70 () ;
V_100 = V_16 -> V_42 ;
if ( V_100 > V_43 ) {
V_100 = V_43 ;
}
F_102 ( V_106 [ V_100 ] ) ;
V_58 = V_46 -> V_58 () - V_58 ;
if ( V_58 > V_43 ) {
V_58 = V_43 ;
}
F_102 ( V_107 [ V_58 ] ) ;
F_72 () ;
V_46 -> V_102 ( V_37 ) ;
}
static int
F_103 ( void * V_68 )
{
int V_58 ;
int V_37 ;
F_88 ( rand ) ;
struct V_14 * V_16 ;
int V_100 ;
struct V_108 V_109 ;
F_78 ( L_20 ) ;
F_89 ( V_76 , 19 ) ;
if ( V_110 && V_46 -> V_111 )
F_104 ( & V_109 , F_95 , 0 ) ;
do {
if ( V_110 && V_46 -> V_111 ) {
if ( ! F_105 ( & V_109 ) )
F_106 ( & V_109 , V_80 + 1 ) ;
}
V_37 = V_46 -> V_101 () ;
V_58 = V_46 -> V_58 () ;
V_16 = F_90 ( V_95 ,
F_97 () ||
F_98 () ||
F_99 ( & V_51 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_102 ( V_37 ) ;
F_21 ( V_33 ) ;
continue;
}
if ( V_16 -> V_45 == 0 )
F_11 ( & V_103 ) ;
V_46 -> V_104 ( & rand ) ;
F_70 () ;
V_100 = V_16 -> V_42 ;
if ( V_100 > V_43 ) {
V_100 = V_43 ;
}
F_102 ( V_106 [ V_100 ] ) ;
V_58 = V_46 -> V_58 () - V_58 ;
if ( V_58 > V_43 ) {
V_58 = V_43 ;
}
F_102 ( V_107 [ V_58 ] ) ;
F_72 () ;
V_46 -> V_102 ( V_37 ) ;
F_107 () ;
F_20 ( L_21 ) ;
} while ( ! F_82 () && V_6 == V_7 );
F_78 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_110 && V_46 -> V_111 )
F_108 ( & V_109 ) ;
while ( ! F_82 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_109 ( char * V_55 )
{
int V_56 = 0 ;
int V_57 ;
int V_39 ;
long V_112 [ V_43 + 1 ] = { 0 } ;
long V_113 [ V_43 + 1 ] = { 0 } ;
F_65 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_112 [ V_39 ] += F_110 ( V_106 , V_57 ) [ V_39 ] ;
V_113 [ V_39 ] += F_110 ( V_107 , V_57 ) [ V_39 ] ;
}
}
for ( V_39 = V_43 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_112 [ V_39 ] != 0 )
break;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_23 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] ,
L_24
L_25
L_26 ,
V_95 ,
V_97 ,
F_10 ( & V_18 ) ,
F_111 ( & V_20 ) ,
F_111 ( & V_19 ) ,
F_111 ( & V_23 ) ,
F_111 ( & V_103 ) ,
V_114 ,
V_78 ,
V_83 ,
V_86 ,
V_105 ) ;
if ( F_111 ( & V_103 ) != 0 ||
V_114 != 0 ||
V_78 != 0 ||
V_83 != 0 )
V_56 += sprintf ( & V_55 [ V_56 ] , L_27 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_28 , V_59 , V_60 ) ;
if ( V_39 > 1 ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_29 ) ;
F_11 ( & V_115 ) ;
F_112 ( 1 ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_30 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_56 += sprintf ( & V_55 [ V_56 ] , L_31 , V_112 [ V_39 ] ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_28 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_32 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_56 += sprintf ( & V_55 [ V_56 ] , L_31 , V_113 [ V_39 ] ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_28 , V_59 , V_60 ) ;
V_56 += sprintf ( & V_55 [ V_56 ] , L_33 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_56 += sprintf ( & V_55 [ V_56 ] , L_34 ,
F_111 ( & V_44 [ V_39 ] ) ) ;
}
V_56 += sprintf ( & V_55 [ V_56 ] , L_5 ) ;
if ( V_46 -> V_116 )
V_56 += V_46 -> V_116 ( & V_55 [ V_56 ] ) ;
return V_56 ;
}
static void
F_113 ( void )
{
int V_56 ;
V_56 = F_109 ( V_117 ) ;
F_3 ( V_118 L_35 , V_117 ) ;
}
static int
F_114 ( void * V_68 )
{
F_78 ( L_36 ) ;
do {
F_21 ( V_119 * V_33 ) ;
F_113 () ;
F_5 ( L_37 ) ;
} while ( ! F_82 () );
F_78 ( L_38 ) ;
return 0 ;
}
static void F_115 ( void )
{
int V_39 ;
F_116 ( V_120 ) ;
F_117 () ;
if ( F_118 () == 1 ) {
F_119 () ;
return;
}
if ( V_121 != - 1 )
F_120 ( V_121 , V_120 ) ;
F_121 ( V_76 , V_120 ) ;
if ( V_122 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ )
if ( V_122 [ V_39 ] )
F_121 ( V_122 [ V_39 ] ,
V_120 ) ;
}
if ( V_123 ) {
for ( V_39 = 0 ; V_39 < V_124 ; V_39 ++ )
if ( V_123 [ V_39 ] )
F_121 ( V_123 [ V_39 ] ,
V_120 ) ;
}
if ( V_96 )
F_121 ( V_96 , V_120 ) ;
if ( V_125 )
F_121 ( V_125 , V_120 ) ;
if ( V_121 == - 1 )
V_121 = F_118 () - 1 ;
else
V_121 -- ;
F_119 () ;
}
static int
F_122 ( void * V_68 )
{
F_78 ( L_39 ) ;
do {
F_21 ( V_126 * V_33 ) ;
F_115 () ;
F_5 ( L_40 ) ;
} while ( ! F_82 () );
F_78 ( L_41 ) ;
return 0 ;
}
static int
F_123 ( void * V_68 )
{
F_78 ( L_42 ) ;
do {
F_21 ( V_127 * V_33 ) ;
V_31 = 1 ;
if ( ! F_82 () )
F_21 ( V_127 * V_33 ) ;
V_31 = 0 ;
F_5 ( L_43 ) ;
} while ( ! F_82 () );
F_78 ( L_44 ) ;
return 0 ;
}
static inline void
F_124 ( struct V_128 * V_46 , char * V_129 )
{
F_3 ( V_118 L_35 V_60
L_45
L_46
L_47
L_48
L_49
L_50 ,
V_59 , V_129 , V_36 , V_124 ,
V_119 , V_130 , V_131 , V_126 ,
V_127 , V_110 , V_90 , V_92 , V_89 ,
V_132 , V_46 -> V_133 ,
V_85 , V_82 ) ;
}
static void F_125 ( int V_57 )
{
struct V_134 * V_109 ;
if ( V_135 [ V_57 ] == NULL )
return;
F_2 ( & V_84 ) ;
F_78 ( L_51 ) ;
V_109 = V_135 [ V_57 ] ;
V_135 [ V_57 ] = NULL ;
F_4 ( & V_84 ) ;
F_126 ( V_109 ) ;
}
static int F_127 ( int V_57 )
{
int V_136 ;
if ( V_135 [ V_57 ] != NULL )
return 0 ;
F_2 ( & V_84 ) ;
F_78 ( L_52 ) ;
V_135 [ V_57 ] = F_128 ( F_77 , NULL ,
F_129 ( V_57 ) ,
L_8 ) ;
if ( F_130 ( V_135 [ V_57 ] ) ) {
V_136 = F_131 ( V_135 [ V_57 ] ) ;
F_78 ( L_53 ) ;
V_114 ++ ;
V_135 [ V_57 ] = NULL ;
F_4 ( & V_84 ) ;
return V_136 ;
}
F_132 ( V_135 [ V_57 ] , V_57 ) ;
F_133 ( V_135 [ V_57 ] ) ;
F_4 ( & V_84 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_137 ,
unsigned long V_138 , void * V_139 )
{
long V_57 = ( long ) V_139 ;
switch ( V_138 ) {
case V_140 :
case V_141 :
( void ) F_127 ( V_57 ) ;
break;
case V_142 :
F_125 ( V_57 ) ;
break;
default:
break;
}
return V_143 ;
}
static void
F_135 ( void )
{
int V_39 ;
F_2 ( & V_5 ) ;
F_136 () ;
if ( V_6 == V_8 ) {
F_3 ( V_9
L_1 ) ;
F_4 ( & V_5 ) ;
F_7 ( 10 ) ;
if ( V_46 -> V_144 != NULL )
V_46 -> V_144 () ;
return;
}
V_6 = V_145 ;
F_4 ( & V_5 ) ;
F_137 ( & V_146 ) ;
if ( V_147 ) {
F_78 ( L_54 ) ;
F_126 ( V_147 ) ;
}
V_147 = NULL ;
if ( V_148 ) {
F_78 ( L_55 ) ;
F_126 ( V_148 ) ;
F_138 ( V_120 ) ;
}
V_148 = NULL ;
if ( V_96 ) {
F_78 ( L_56 ) ;
F_126 ( V_96 ) ;
}
V_96 = NULL ;
if ( V_122 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
if ( V_122 [ V_39 ] ) {
F_78 (
L_57 ) ;
F_126 ( V_122 [ V_39 ] ) ;
}
V_122 [ V_39 ] = NULL ;
}
F_139 ( V_122 ) ;
V_122 = NULL ;
}
V_95 = NULL ;
if ( V_123 ) {
for ( V_39 = 0 ; V_39 < V_124 ; V_39 ++ ) {
if ( V_123 [ V_39 ] ) {
F_78 (
L_58 ) ;
F_126 ( V_123 [ V_39 ] ) ;
}
V_123 [ V_39 ] = NULL ;
}
F_139 ( V_123 ) ;
V_123 = NULL ;
}
if ( V_125 ) {
F_78 ( L_59 ) ;
F_126 ( V_125 ) ;
}
V_125 = NULL ;
if ( V_149 ) {
F_78 ( L_60 ) ;
F_126 ( V_149 ) ;
}
V_149 = NULL ;
if ( ( V_132 == 1 && V_46 -> V_133 ) ||
V_132 == 2 ) {
F_140 ( & V_150 ) ;
F_65 (i)
F_125 ( V_39 ) ;
}
if ( V_46 -> V_144 != NULL )
V_46 -> V_144 () ;
F_113 () ;
if ( V_46 -> V_151 )
V_46 -> V_151 () ;
if ( F_111 ( & V_115 ) )
F_124 ( V_46 , L_61 ) ;
else
F_124 ( V_46 , L_62 ) ;
}
static int T_3
F_141 ( void )
{
int V_39 ;
int V_57 ;
int V_152 = 0 ;
static struct V_128 * V_153 [] =
{ & V_154 , & V_155 , & V_156 ,
& V_157 , & V_158 , & V_159 ,
& V_160 , & V_161 ,
& V_162 , & V_163 , & V_164 , } ;
F_2 ( & V_5 ) ;
for ( V_39 = 0 ; V_39 < F_142 ( V_153 ) ; V_39 ++ ) {
V_46 = V_153 [ V_39 ] ;
if ( strcmp ( V_59 , V_46 -> V_165 ) == 0 )
break;
}
if ( V_39 == F_142 ( V_153 ) ) {
F_3 ( V_118 L_63 ,
V_59 ) ;
F_3 ( V_118 L_64 ) ;
for ( V_39 = 0 ; V_39 < F_142 ( V_153 ) ; V_39 ++ )
F_3 ( V_118 L_65 , V_153 [ V_39 ] -> V_165 ) ;
F_3 ( V_118 L_5 ) ;
F_4 ( & V_5 ) ;
return - V_166 ;
}
if ( V_46 -> V_91 == NULL && V_90 != 0 ) {
F_3 ( V_118 L_66
L_67 ) ;
V_90 = 0 ;
}
if ( V_46 -> V_167 )
V_46 -> V_167 () ;
if ( V_168 >= 0 )
V_36 = V_168 ;
else
V_36 = 2 * F_118 () ;
F_124 ( V_46 , L_68 ) ;
V_6 = V_7 ;
F_44 ( & V_18 ) ;
for ( V_39 = 0 ; V_39 < F_142 ( V_169 ) ; V_39 ++ ) {
V_169 [ V_39 ] . V_45 = 0 ;
F_16 ( & V_169 [ V_39 ] . V_22 ,
& V_18 ) ;
}
V_95 = NULL ;
V_97 = 0 ;
F_143 ( & V_20 , 0 ) ;
F_143 ( & V_19 , 0 ) ;
F_143 ( & V_23 , 0 ) ;
F_143 ( & V_103 , 0 ) ;
F_143 ( & V_115 , 0 ) ;
V_114 = 0 ;
V_78 = 0 ;
V_83 = 0 ;
V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
F_143 ( & V_44 [ V_39 ] , 0 ) ;
F_65 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
F_110 ( V_106 , V_57 ) [ V_39 ] = 0 ;
F_110 ( V_107 , V_57 ) [ V_39 ] = 0 ;
}
}
F_78 ( L_69 ) ;
V_96 = F_144 ( F_87 , NULL ,
L_15 ) ;
if ( F_130 ( V_96 ) ) {
V_152 = F_131 ( V_96 ) ;
F_145 ( L_70 ) ;
V_96 = NULL ;
goto V_170;
}
V_123 = F_146 ( V_124 * sizeof( V_123 [ 0 ] ) ,
V_171 ) ;
if ( V_123 == NULL ) {
F_145 ( L_71 ) ;
V_152 = - V_172 ;
goto V_170;
}
for ( V_39 = 0 ; V_39 < V_124 ; V_39 ++ ) {
F_78 ( L_72 ) ;
V_123 [ V_39 ] = F_144 ( F_94 , NULL ,
L_18 ) ;
if ( F_130 ( V_123 [ V_39 ] ) ) {
V_152 = F_131 ( V_123 [ V_39 ] ) ;
F_145 ( L_73 ) ;
V_123 [ V_39 ] = NULL ;
goto V_170;
}
}
V_122 = F_146 ( V_36 * sizeof( V_122 [ 0 ] ) ,
V_171 ) ;
if ( V_122 == NULL ) {
F_145 ( L_71 ) ;
V_152 = - V_172 ;
goto V_170;
}
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
F_78 ( L_74 ) ;
V_122 [ V_39 ] = F_144 ( F_103 , NULL ,
L_21 ) ;
if ( F_130 ( V_122 [ V_39 ] ) ) {
V_152 = F_131 ( V_122 [ V_39 ] ) ;
F_145 ( L_75 ) ;
V_122 [ V_39 ] = NULL ;
goto V_170;
}
}
if ( V_119 > 0 ) {
F_78 ( L_76 ) ;
V_125 = F_144 ( F_114 , NULL ,
L_37 ) ;
if ( F_130 ( V_125 ) ) {
V_152 = F_131 ( V_125 ) ;
F_145 ( L_77 ) ;
V_125 = NULL ;
goto V_170;
}
}
if ( V_131 ) {
V_121 = F_118 () - 1 ;
if ( ! F_147 ( & V_120 , V_171 ) ) {
V_152 = - V_172 ;
F_145 ( L_78 ) ;
goto V_170;
}
V_148 = F_144 ( F_122 , NULL ,
L_40 ) ;
if ( F_130 ( V_148 ) ) {
F_138 ( V_120 ) ;
V_152 = F_131 ( V_148 ) ;
F_145 ( L_79 ) ;
V_148 = NULL ;
goto V_170;
}
}
if ( V_127 < 0 )
V_127 = 0 ;
if ( V_127 ) {
V_147 = F_144 ( F_123 , NULL ,
L_43 ) ;
if ( F_130 ( V_147 ) ) {
V_152 = F_131 ( V_147 ) ;
F_145 ( L_80 ) ;
V_147 = NULL ;
goto V_170;
}
}
if ( V_90 < 0 )
V_90 = 0 ;
if ( V_90 ) {
V_149 = F_144 ( F_86 , NULL ,
L_12 ) ;
if ( F_130 ( V_149 ) ) {
V_152 = F_131 ( V_149 ) ;
F_145 ( L_81 ) ;
V_149 = NULL ;
goto V_170;
}
}
if ( V_85 < 1 )
V_85 = 1 ;
if ( V_82 < 2 )
V_82 = 2 ;
if ( ( V_132 == 1 && V_46 -> V_133 ) ||
V_132 == 2 ) {
int V_136 ;
V_79 = V_80 + V_85 * V_33 ;
F_148 ( & V_150 ) ;
F_65 (i) {
if ( F_149 ( V_39 ) )
continue;
V_136 = F_127 ( V_39 ) ;
if ( V_136 < 0 ) {
V_152 = V_136 ;
goto V_170;
}
}
}
F_150 ( & V_146 ) ;
F_136 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_170:
F_4 ( & V_5 ) ;
F_135 () ;
return V_152 ;
}
