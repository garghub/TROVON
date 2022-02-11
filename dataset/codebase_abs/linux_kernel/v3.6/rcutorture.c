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
} else {
V_46 -> V_47 ( V_40 ) ;
}
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
static void F_66 ( struct V_38 * V_55 ,
void (* F_67)( struct V_38 * V_55 ) )
{
F_64 ( & V_51 , V_55 , F_67 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_51 ) ;
}
static int F_70 ( char * V_56 )
{
int V_57 = 0 ;
int V_58 ;
int V_37 = V_51 . V_59 & 0x1 ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_3 ,
V_60 , V_61 , V_37 ) ;
F_71 (cpu) {
V_57 += sprintf ( & V_56 [ V_57 ] , L_4 , V_58 ,
F_72 ( V_51 . V_62 , V_58 ) -> V_63 [ ! V_37 ] ,
F_72 ( V_51 . V_62 , V_58 ) -> V_63 [ V_37 ] ) ;
}
V_57 += sprintf ( & V_56 [ V_57 ] , L_5 ) ;
return V_57 ;
}
static int F_73 ( void ) __acquires( &srcu_ctl
static void F_74 ( int V_37 ) __releases( &srcu_ctl
static void F_75 ( void )
{
F_76 ( & V_51 ) ;
}
static int F_77 ( void )
{
F_78 () ;
return 0 ;
}
static void F_79 ( int V_37 )
{
F_80 () ;
}
static void F_81 ( struct V_14 * V_16 )
{
F_82 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_83 ( struct V_38 * V_55 )
{
struct V_64 * V_65 =
F_14 ( V_55 , struct V_64 , V_66 ) ;
F_84 () ;
V_65 -> V_67 = 0 ;
}
static int F_85 ( void * V_68 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
struct V_64 V_72 = { . V_67 = 0 } ;
struct V_73 V_74 ;
F_86 ( L_6 ) ;
V_74 . V_75 = 1 ;
if ( F_87 ( V_76 , V_77 , & V_74 ) < 0 ) {
F_86 ( L_7 ) ;
V_78 ++ ;
}
F_88 ( & V_72 . V_66 ) ;
do {
V_71 = V_79 ;
while ( F_89 ( V_80 , V_71 ) ) {
F_7 ( 1 ) ;
F_20 ( L_8 ) ;
if ( F_90 () ||
V_6 != V_7 )
goto V_81;
}
V_70 = V_71 + V_82 * V_33 ;
V_69 = V_80 ;
while ( F_89 ( V_80 , V_70 ) ) {
if ( ! V_72 . V_67 ) {
F_84 () ;
V_72 . V_67 = 1 ;
F_38 ( & V_72 . V_66 , F_83 ) ;
if ( V_80 - V_69 >
V_82 * V_33 - V_33 / 2 ) {
F_86 ( L_9 ) ;
V_83 ++ ;
}
V_69 = V_80 ;
}
F_91 () ;
F_20 ( L_8 ) ;
if ( F_90 () ||
V_6 != V_7 )
goto V_81;
}
while ( V_71 == V_79 &&
! F_90 () ) {
if ( F_92 ( & V_84 ) ) {
V_79 = V_80 +
V_85 * V_33 ;
V_86 ++ ;
F_4 ( & V_84 ) ;
break;
}
F_7 ( 1 ) ;
}
V_81: F_20 ( L_8 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_10 ) ;
F_5 ( L_8 ) ;
while ( ! F_90 () || V_72 . V_67 )
F_7 ( 1 ) ;
F_84 () ;
F_93 ( & V_72 . V_66 ) ;
return 0 ;
}
static int
F_94 ( void * V_68 )
{
unsigned long V_87 ;
int V_88 ;
F_86 ( L_11 ) ;
do {
V_87 = V_80 + V_89 * V_33 ;
while ( F_89 ( V_80 , V_87 ) &&
! F_90 () ) {
F_21 ( 1 ) ;
}
V_88 = V_90 ;
while ( V_88 > 0 &&
! F_90 () ) {
V_46 -> V_91 () ;
F_27 ( V_92 ) ;
V_88 -= V_92 ;
}
F_20 ( L_12 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_90 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_95 ( void * V_68 )
{
int V_39 ;
long V_93 = F_34 () ;
struct V_14 * V_40 ;
struct V_14 * V_94 ;
static F_96 ( rand ) ;
F_86 ( L_14 ) ;
F_97 ( V_76 , 19 ) ;
do {
F_7 ( 1 ) ;
V_40 = F_8 () ;
if ( V_40 == NULL )
continue;
V_40 -> V_42 = 0 ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_94 = F_98 ( V_95 ,
V_76 == V_96 ) ;
V_40 -> V_45 = 1 ;
F_99 ( V_95 , V_40 ) ;
F_100 () ;
if ( V_94 ) {
V_39 = V_94 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
V_94 -> V_42 ++ ;
V_46 -> V_47 ( V_94 ) ;
}
F_101 ( ++ V_97 ) ;
V_93 = V_46 -> V_59 () ;
F_20 ( L_15 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_90 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_102 ( void * V_68 )
{
F_96 ( rand ) ;
F_86 ( L_17 ) ;
F_97 ( V_76 , 19 ) ;
do {
F_7 ( 1 + F_17 ( & rand ) % 10 ) ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
if ( V_46 -> V_98 != NULL &&
F_17 ( & rand ) % ( V_99 * 8 ) == 0 )
V_46 -> V_98 () ;
else
V_46 -> V_49 () ;
F_20 ( L_18 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_90 () )
F_7 ( 1 ) ;
return 0 ;
}
void F_103 ( void )
{
static T_3 V_100 = F_104 ( 0 ) ;
if ( F_105 ( & V_100 ) )
return;
if ( F_106 ( & V_100 , 1 ) != 0 )
return;
F_107 ( V_46 -> V_101 , (struct V_38 * ) ~ 0UL ) ;
F_108 ( V_102 ) ;
}
static void F_109 ( unsigned long V_103 )
{
int V_37 ;
int V_59 ;
static F_96 ( rand ) ;
static F_110 ( V_104 ) ;
struct V_14 * V_16 ;
int V_105 ;
V_37 = V_46 -> V_106 () ;
V_59 = V_46 -> V_59 () ;
V_16 = F_98 ( V_95 ,
F_111 () ||
F_112 () ||
F_113 ( & V_51 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_107 ( V_37 ) ;
return;
}
F_107 ( V_46 -> V_101 , & V_16 -> V_41 ) ;
if ( V_16 -> V_45 == 0 )
F_11 ( & V_108 ) ;
F_114 ( & V_104 ) ;
V_46 -> V_109 ( & rand ) ;
V_110 ++ ;
F_115 ( & V_104 ) ;
F_78 () ;
V_105 = V_16 -> V_42 ;
if ( V_105 > V_43 ) {
V_105 = V_43 ;
}
if ( V_105 > 1 )
F_103 () ;
F_116 ( V_111 [ V_105 ] ) ;
V_59 = V_46 -> V_59 () - V_59 ;
if ( V_59 > V_43 ) {
V_59 = V_43 ;
}
F_116 ( V_112 [ V_59 ] ) ;
F_80 () ;
V_46 -> V_107 ( V_37 ) ;
}
static int
F_117 ( void * V_68 )
{
int V_59 ;
int V_37 ;
F_96 ( rand ) ;
struct V_14 * V_16 ;
int V_105 ;
struct V_113 V_114 ;
F_86 ( L_20 ) ;
F_97 ( V_76 , 19 ) ;
if ( V_115 && V_46 -> V_116 )
F_118 ( & V_114 , F_109 , 0 ) ;
do {
if ( V_115 && V_46 -> V_116 ) {
if ( ! F_119 ( & V_114 ) )
F_120 ( & V_114 , V_80 + 1 ) ;
}
V_37 = V_46 -> V_106 () ;
V_59 = V_46 -> V_59 () ;
V_16 = F_98 ( V_95 ,
F_111 () ||
F_112 () ||
F_113 ( & V_51 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_107 ( V_37 ) ;
F_21 ( V_33 ) ;
continue;
}
F_107 ( V_46 -> V_101 , & V_16 -> V_41 ) ;
if ( V_16 -> V_45 == 0 )
F_11 ( & V_108 ) ;
V_46 -> V_109 ( & rand ) ;
F_78 () ;
V_105 = V_16 -> V_42 ;
if ( V_105 > V_43 ) {
V_105 = V_43 ;
}
if ( V_105 > 1 )
F_103 () ;
F_116 ( V_111 [ V_105 ] ) ;
V_59 = V_46 -> V_59 () - V_59 ;
if ( V_59 > V_43 ) {
V_59 = V_43 ;
}
F_116 ( V_112 [ V_59 ] ) ;
F_80 () ;
V_46 -> V_107 ( V_37 ) ;
F_121 () ;
F_20 ( L_21 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_115 && V_46 -> V_116 )
F_122 ( & V_114 ) ;
while ( ! F_90 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_123 ( char * V_56 )
{
int V_57 = 0 ;
int V_58 ;
int V_39 ;
long V_117 [ V_43 + 1 ] = { 0 } ;
long V_118 [ V_43 + 1 ] = { 0 } ;
F_71 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_117 [ V_39 ] += F_124 ( V_111 , V_58 ) [ V_39 ] ;
V_118 [ V_39 ] += F_124 ( V_112 , V_58 ) [ V_39 ] ;
}
}
for ( V_39 = V_43 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_117 [ V_39 ] != 0 )
break;
}
V_57 += sprintf ( & V_56 [ V_57 ] , L_23 , V_60 , V_61 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] ,
L_24 ,
V_95 ,
V_97 ,
F_10 ( & V_18 ) ,
F_105 ( & V_20 ) ,
F_105 ( & V_19 ) ,
F_105 ( & V_23 ) ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_25 ,
F_105 ( & V_108 ) ,
V_119 ,
V_78 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_26 ,
V_83 ,
V_86 ,
V_110 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_27 ,
V_120 ,
V_121 ,
V_122 ,
V_123 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_28 ,
V_124 ,
V_125 ,
V_126 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_29 , V_60 , V_61 ) ;
if ( F_105 ( & V_108 ) != 0 ||
V_126 != 0 ||
V_119 != 0 ||
V_78 != 0 ||
V_83 != 0 ||
V_39 > 1 ) {
V_57 += sprintf ( & V_56 [ V_57 ] , L_30 ) ;
F_11 ( & V_127 ) ;
F_125 ( 1 ) ;
}
V_57 += sprintf ( & V_56 [ V_57 ] , L_31 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_57 += sprintf ( & V_56 [ V_57 ] , L_32 , V_117 [ V_39 ] ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_29 , V_60 , V_61 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_33 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_57 += sprintf ( & V_56 [ V_57 ] , L_32 , V_118 [ V_39 ] ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_29 , V_60 , V_61 ) ;
V_57 += sprintf ( & V_56 [ V_57 ] , L_34 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_57 += sprintf ( & V_56 [ V_57 ] , L_35 ,
F_105 ( & V_44 [ V_39 ] ) ) ;
}
V_57 += sprintf ( & V_56 [ V_57 ] , L_5 ) ;
if ( V_46 -> V_128 )
V_57 += V_46 -> V_128 ( & V_56 [ V_57 ] ) ;
return V_57 ;
}
static void
F_126 ( void )
{
int V_57 ;
V_57 = F_123 ( V_129 ) ;
F_3 ( V_130 L_36 , V_129 ) ;
}
static int
F_127 ( void * V_68 )
{
F_86 ( L_37 ) ;
do {
F_21 ( V_131 * V_33 ) ;
F_126 () ;
F_5 ( L_38 ) ;
} while ( ! F_90 () );
F_86 ( L_39 ) ;
return 0 ;
}
static void F_128 ( void )
{
int V_39 ;
F_129 ( V_132 ) ;
F_130 () ;
if ( F_131 () == 1 ) {
F_132 () ;
return;
}
if ( V_133 != - 1 )
F_133 ( V_133 , V_132 ) ;
F_134 ( V_76 , V_132 ) ;
if ( V_134 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ )
if ( V_134 [ V_39 ] )
F_134 ( V_134 [ V_39 ] ,
V_132 ) ;
}
if ( V_135 ) {
for ( V_39 = 0 ; V_39 < V_99 ; V_39 ++ )
if ( V_135 [ V_39 ] )
F_134 ( V_135 [ V_39 ] ,
V_132 ) ;
}
if ( V_96 )
F_134 ( V_96 , V_132 ) ;
if ( V_136 )
F_134 ( V_136 , V_132 ) ;
if ( V_133 == - 1 )
V_133 = F_131 () - 1 ;
else
V_133 -- ;
F_132 () ;
}
static int
F_135 ( void * V_68 )
{
F_86 ( L_40 ) ;
do {
F_21 ( V_137 * V_33 ) ;
F_128 () ;
F_5 ( L_41 ) ;
} while ( ! F_90 () );
F_86 ( L_42 ) ;
return 0 ;
}
static int
F_136 ( void * V_68 )
{
F_86 ( L_43 ) ;
do {
F_21 ( V_138 * V_33 ) ;
V_31 = 1 ;
if ( ! F_90 () )
F_21 ( V_138 * V_33 ) ;
V_31 = 0 ;
F_5 ( L_44 ) ;
} while ( ! F_90 () );
F_86 ( L_45 ) ;
return 0 ;
}
static inline void
F_137 ( struct V_139 * V_46 , char * V_140 )
{
F_3 ( V_130 L_36 V_61
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_60 , V_140 , V_36 , V_99 ,
V_131 , V_141 , V_142 , V_137 ,
V_138 , V_115 , V_90 , V_92 , V_89 ,
V_143 , V_46 -> V_144 ,
V_85 , V_82 , V_145 ,
V_146 , V_147 ) ;
}
static void F_138 ( int V_58 )
{
struct V_148 * V_114 ;
if ( V_149 [ V_58 ] == NULL )
return;
F_2 ( & V_84 ) ;
F_86 ( L_53 ) ;
V_114 = V_149 [ V_58 ] ;
V_149 [ V_58 ] = NULL ;
F_4 ( & V_84 ) ;
F_139 ( V_114 ) ;
V_149 [ V_58 ] = NULL ;
}
static int F_140 ( int V_58 )
{
int V_150 ;
if ( V_149 [ V_58 ] != NULL )
return 0 ;
F_2 ( & V_84 ) ;
F_86 ( L_54 ) ;
V_149 [ V_58 ] = F_141 ( F_85 , NULL ,
F_142 ( V_58 ) ,
L_8 ) ;
if ( F_143 ( V_149 [ V_58 ] ) ) {
V_150 = F_144 ( V_149 [ V_58 ] ) ;
F_86 ( L_55 ) ;
V_119 ++ ;
V_149 [ V_58 ] = NULL ;
F_4 ( & V_84 ) ;
return V_150 ;
}
F_145 ( V_149 [ V_58 ] , V_58 ) ;
F_146 ( V_149 [ V_58 ] ) ;
F_4 ( & V_84 ) ;
return 0 ;
}
static int
F_147 ( void * V_68 )
{
long V_151 ;
unsigned long V_152 ;
F_86 ( L_56 ) ;
V_152 = F_6 ( V_80 ) ;
while ( F_89 ( V_152 , V_153 ) &&
! F_90 () ) {
V_151 = V_153 - V_152 ;
if ( V_141 )
F_3 ( V_130 L_36 V_61
L_57 ,
V_60 , V_151 ) ;
F_21 ( V_151 ) ;
V_152 = F_6 ( V_80 ) ;
}
if ( F_90 () ) {
F_86 ( L_58 ) ;
return 0 ;
}
F_86 ( L_59 ) ;
V_154 = NULL ;
F_148 () ;
F_149 () ;
return 0 ;
}
static int T_4
F_150 ( void * V_68 )
{
int V_58 ;
int V_155 = - 1 ;
F_96 ( rand ) ;
F_86 ( L_60 ) ;
F_151 (cpu)
V_155 = V_58 ;
F_152 ( V_155 < 0 ) ;
if ( V_147 > 0 ) {
F_86 ( L_61 ) ;
F_21 ( V_147 * V_33 ) ;
F_86 ( L_62 ) ;
}
while ( ! F_90 () ) {
V_58 = ( F_17 ( & rand ) >> 4 ) % ( V_155 + 1 ) ;
if ( F_153 ( V_58 ) && F_154 ( V_58 ) ) {
if ( V_141 )
F_3 ( V_130 L_36 V_61
L_63 ,
V_60 , V_58 ) ;
V_123 ++ ;
if ( F_155 ( V_58 ) == 0 ) {
if ( V_141 )
F_3 ( V_130 L_36 V_61
L_64 ,
V_60 , V_58 ) ;
V_122 ++ ;
}
} else if ( F_154 ( V_58 ) ) {
if ( V_141 )
F_3 ( V_130 L_36 V_61
L_65 ,
V_60 , V_58 ) ;
V_121 ++ ;
if ( F_156 ( V_58 ) == 0 ) {
if ( V_141 )
F_3 ( V_130 L_36 V_61
L_66 ,
V_60 , V_58 ) ;
V_120 ++ ;
}
}
F_21 ( V_146 * V_33 ) ;
}
F_86 ( L_67 ) ;
return 0 ;
}
static int T_4
F_157 ( void )
{
int V_156 ;
if ( V_146 <= 0 )
return 0 ;
V_157 = F_158 ( F_150 , NULL , L_68 ) ;
if ( F_143 ( V_157 ) ) {
V_156 = F_144 ( V_157 ) ;
V_157 = NULL ;
return V_156 ;
}
return 0 ;
}
static void F_159 ( void )
{
if ( V_157 == NULL )
return;
F_86 ( L_69 ) ;
F_139 ( V_157 ) ;
V_157 = NULL ;
}
static int
F_157 ( void )
{
return 0 ;
}
static void F_159 ( void )
{
}
static int T_4 F_160 ( void * args )
{
unsigned long V_158 ;
F_86 ( L_70 ) ;
if ( V_159 > 0 ) {
F_86 ( L_71 ) ;
F_21 ( V_159 * V_33 ) ;
F_86 ( L_72 ) ;
}
if ( ! F_90 () ) {
V_158 = F_161 () + V_160 ;
F_3 ( V_130 L_73 ) ;
F_24 () ;
F_78 () ;
while ( F_89 ( F_161 () , V_158 ) )
continue;
F_80 () ;
F_32 () ;
F_3 ( V_130 L_74 ) ;
}
F_5 ( L_75 ) ;
while ( ! F_90 () )
F_21 ( 10 * V_33 ) ;
return 0 ;
}
static int T_5 F_162 ( void )
{
int V_156 ;
if ( V_160 <= 0 )
return 0 ;
V_161 = F_158 ( F_160 , NULL , L_75 ) ;
if ( F_143 ( V_161 ) ) {
V_156 = F_144 ( V_161 ) ;
V_161 = NULL ;
return V_156 ;
}
return 0 ;
}
static void F_163 ( void )
{
if ( V_161 == NULL )
return;
F_86 ( L_76 ) ;
F_139 ( V_161 ) ;
V_161 = NULL ;
}
void F_164 ( struct V_38 * V_66 )
{
F_11 ( & V_162 ) ;
}
static int F_165 ( void * V_68 )
{
long V_163 = ( long ) V_68 ;
bool V_164 = 0 ;
struct V_38 V_66 ;
F_88 ( & V_66 ) ;
F_86 ( L_77 ) ;
F_97 ( V_76 , 19 ) ;
do {
F_166 ( V_165 [ V_163 ] ,
V_166 != V_164 ||
F_90 () ||
V_6 != V_7 ) ;
V_164 = V_166 ;
F_84 () ;
if ( F_90 () || V_6 != V_7 )
break;
V_46 -> V_167 ( & V_66 , F_164 ) ;
if ( F_167 ( & V_168 ) )
F_168 ( & V_169 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_78 ) ;
F_5 ( L_79 ) ;
while ( ! F_90 () )
F_21 ( 1 ) ;
V_46 -> V_98 () ;
F_93 ( & V_66 ) ;
return 0 ;
}
static int F_169 ( void * V_68 )
{
int V_39 ;
F_86 ( L_80 ) ;
do {
F_170 ( & V_162 , 0 ) ;
F_170 ( & V_168 , V_170 ) ;
F_84 () ;
V_166 = ! V_166 ;
for ( V_39 = 0 ; V_39 < V_170 ; V_39 ++ )
F_168 ( & V_165 [ V_39 ] ) ;
F_166 ( V_169 ,
F_105 ( & V_168 ) == 0 ||
F_90 () ||
V_6 != V_7 ) ;
if ( F_90 () || V_6 != V_7 )
break;
V_125 ++ ;
V_46 -> V_98 () ;
if ( F_105 ( & V_162 ) != V_170 ) {
V_126 ++ ;
F_125 ( 1 ) ;
}
V_124 ++ ;
F_21 ( V_33 / 10 ) ;
} while ( ! F_90 () && V_6 == V_7 );
F_86 ( L_81 ) ;
F_5 ( L_82 ) ;
while ( ! F_90 () )
F_21 ( 1 ) ;
return 0 ;
}
static int F_171 ( void )
{
int V_39 ;
int V_156 ;
if ( V_170 == 0 )
return 0 ;
if ( V_46 -> V_167 == NULL || V_46 -> V_98 == NULL ) {
F_3 ( V_130 L_36 V_61
L_83 ,
V_60 , V_46 -> V_101 ) ;
F_3 ( V_130 L_36 V_61
L_84 ,
V_60 ) ;
return 0 ;
}
F_170 ( & V_168 , 0 ) ;
F_170 ( & V_162 , 0 ) ;
V_171 =
F_172 ( V_170 * sizeof( V_171 [ 0 ] ) ,
V_172 ) ;
V_165 =
F_172 ( V_170 * sizeof( V_165 [ 0 ] ) ,
V_172 ) ;
if ( V_171 == NULL || V_165 == 0 )
return - V_173 ;
for ( V_39 = 0 ; V_39 < V_170 ; V_39 ++ ) {
F_173 ( & V_165 [ V_39 ] ) ;
V_171 [ V_39 ] = F_158 ( F_165 ,
( void * ) ( long ) V_39 ,
L_79 ) ;
if ( F_143 ( V_171 [ V_39 ] ) ) {
V_156 = F_144 ( V_171 [ V_39 ] ) ;
F_174 ( L_85 ) ;
V_171 [ V_39 ] = NULL ;
return V_156 ;
}
}
V_174 = F_158 ( F_169 , NULL ,
L_82 ) ;
if ( F_143 ( V_174 ) ) {
V_156 = F_144 ( V_174 ) ;
F_174 ( L_86 ) ;
V_174 = NULL ;
}
return 0 ;
}
static void F_175 ( void )
{
int V_39 ;
if ( V_174 != NULL ) {
F_86 ( L_87 ) ;
F_139 ( V_174 ) ;
V_174 = NULL ;
}
if ( V_171 != NULL ) {
for ( V_39 = 0 ; V_39 < V_170 ; V_39 ++ ) {
if ( V_171 [ V_39 ] != NULL ) {
F_86 ( L_88 ) ;
F_139 ( V_171 [ V_39 ] ) ;
V_171 [ V_39 ] = NULL ;
}
}
F_176 ( V_171 ) ;
V_171 = NULL ;
}
if ( V_165 != NULL ) {
F_176 ( V_165 ) ;
V_165 = NULL ;
}
}
static int F_177 ( struct V_1 * V_175 ,
unsigned long V_176 , void * V_177 )
{
long V_58 = ( long ) V_177 ;
switch ( V_176 ) {
case V_178 :
case V_179 :
( void ) F_140 ( V_58 ) ;
break;
case V_180 :
F_138 ( V_58 ) ;
break;
default:
break;
}
return V_181 ;
}
static void
F_148 ( void )
{
int V_39 ;
F_2 ( & V_5 ) ;
F_178 () ;
if ( V_6 == V_8 ) {
F_3 ( V_9
L_1 ) ;
F_4 ( & V_5 ) ;
F_7 ( 10 ) ;
if ( V_46 -> V_98 != NULL )
V_46 -> V_98 () ;
return;
}
V_6 = V_182 ;
F_4 ( & V_5 ) ;
F_179 ( & V_183 ) ;
F_175 () ;
F_163 () ;
if ( V_184 ) {
F_86 ( L_89 ) ;
F_139 ( V_184 ) ;
}
V_184 = NULL ;
if ( V_185 ) {
F_86 ( L_90 ) ;
F_139 ( V_185 ) ;
F_180 ( V_132 ) ;
}
V_185 = NULL ;
if ( V_96 ) {
F_86 ( L_91 ) ;
F_139 ( V_96 ) ;
}
V_96 = NULL ;
if ( V_134 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
if ( V_134 [ V_39 ] ) {
F_86 (
L_92 ) ;
F_139 ( V_134 [ V_39 ] ) ;
}
V_134 [ V_39 ] = NULL ;
}
F_176 ( V_134 ) ;
V_134 = NULL ;
}
V_95 = NULL ;
if ( V_135 ) {
for ( V_39 = 0 ; V_39 < V_99 ; V_39 ++ ) {
if ( V_135 [ V_39 ] ) {
F_86 (
L_93 ) ;
F_139 ( V_135 [ V_39 ] ) ;
}
V_135 [ V_39 ] = NULL ;
}
F_176 ( V_135 ) ;
V_135 = NULL ;
}
if ( V_136 ) {
F_86 ( L_94 ) ;
F_139 ( V_136 ) ;
}
V_136 = NULL ;
if ( V_186 ) {
F_86 ( L_95 ) ;
F_139 ( V_186 ) ;
}
V_186 = NULL ;
if ( ( V_143 == 1 && V_46 -> V_144 ) ||
V_143 == 2 ) {
F_181 ( & V_187 ) ;
F_71 (i)
F_138 ( V_39 ) ;
}
if ( V_154 != NULL ) {
F_86 ( L_96 ) ;
F_139 ( V_154 ) ;
}
V_154 = NULL ;
F_159 () ;
if ( V_46 -> V_98 != NULL )
V_46 -> V_98 () ;
F_126 () ;
if ( V_46 -> V_188 )
V_46 -> V_188 () ;
if ( F_105 ( & V_127 ) || V_126 )
F_137 ( V_46 , L_97 ) ;
else if ( V_120 != V_121 ||
V_122 != V_123 )
F_137 ( V_46 ,
L_98 ) ;
else
F_137 ( V_46 , L_99 ) ;
}
static int T_5
F_182 ( void )
{
int V_39 ;
int V_58 ;
int V_189 = 0 ;
int V_150 ;
static struct V_139 * V_190 [] =
{ & V_191 , & V_192 , & V_193 ,
& V_194 , & V_195 , & V_196 ,
& V_197 , & V_198 , & V_199 ,
& V_200 , & V_201 ,
& V_202 , & V_203 , & V_204 , } ;
F_2 ( & V_5 ) ;
for ( V_39 = 0 ; V_39 < F_183 ( V_190 ) ; V_39 ++ ) {
V_46 = V_190 [ V_39 ] ;
if ( strcmp ( V_60 , V_46 -> V_101 ) == 0 )
break;
}
if ( V_39 == F_183 ( V_190 ) ) {
F_3 ( V_130 L_100 ,
V_60 ) ;
F_3 ( V_130 L_101 ) ;
for ( V_39 = 0 ; V_39 < F_183 ( V_190 ) ; V_39 ++ )
F_3 ( V_130 L_102 , V_190 [ V_39 ] -> V_101 ) ;
F_3 ( V_130 L_5 ) ;
F_4 ( & V_5 ) ;
return - V_205 ;
}
if ( V_46 -> V_91 == NULL && V_90 != 0 ) {
F_3 ( V_130 L_103 ) ;
V_90 = 0 ;
}
if ( V_46 -> V_206 )
V_46 -> V_206 () ;
if ( V_207 >= 0 )
V_36 = V_207 ;
else
V_36 = 2 * F_131 () ;
F_137 ( V_46 , L_104 ) ;
V_6 = V_7 ;
F_44 ( & V_18 ) ;
for ( V_39 = 0 ; V_39 < F_183 ( V_208 ) ; V_39 ++ ) {
V_208 [ V_39 ] . V_45 = 0 ;
F_16 ( & V_208 [ V_39 ] . V_22 ,
& V_18 ) ;
}
V_95 = NULL ;
V_97 = 0 ;
F_170 ( & V_20 , 0 ) ;
F_170 ( & V_19 , 0 ) ;
F_170 ( & V_23 , 0 ) ;
F_170 ( & V_108 , 0 ) ;
F_170 ( & V_127 , 0 ) ;
V_126 = 0 ;
V_119 = 0 ;
V_78 = 0 ;
V_83 = 0 ;
V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
F_170 ( & V_44 [ V_39 ] , 0 ) ;
F_71 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
F_124 ( V_111 , V_58 ) [ V_39 ] = 0 ;
F_124 ( V_112 , V_58 ) [ V_39 ] = 0 ;
}
}
F_86 ( L_105 ) ;
V_96 = F_158 ( F_95 , NULL ,
L_15 ) ;
if ( F_143 ( V_96 ) ) {
V_189 = F_144 ( V_96 ) ;
F_174 ( L_106 ) ;
V_96 = NULL ;
goto V_209;
}
V_135 = F_172 ( V_99 * sizeof( V_135 [ 0 ] ) ,
V_172 ) ;
if ( V_135 == NULL ) {
F_174 ( L_107 ) ;
V_189 = - V_173 ;
goto V_209;
}
for ( V_39 = 0 ; V_39 < V_99 ; V_39 ++ ) {
F_86 ( L_108 ) ;
V_135 [ V_39 ] = F_158 ( F_102 , NULL ,
L_18 ) ;
if ( F_143 ( V_135 [ V_39 ] ) ) {
V_189 = F_144 ( V_135 [ V_39 ] ) ;
F_174 ( L_109 ) ;
V_135 [ V_39 ] = NULL ;
goto V_209;
}
}
V_134 = F_172 ( V_36 * sizeof( V_134 [ 0 ] ) ,
V_172 ) ;
if ( V_134 == NULL ) {
F_174 ( L_107 ) ;
V_189 = - V_173 ;
goto V_209;
}
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
F_86 ( L_110 ) ;
V_134 [ V_39 ] = F_158 ( F_117 , NULL ,
L_21 ) ;
if ( F_143 ( V_134 [ V_39 ] ) ) {
V_189 = F_144 ( V_134 [ V_39 ] ) ;
F_174 ( L_111 ) ;
V_134 [ V_39 ] = NULL ;
goto V_209;
}
}
if ( V_131 > 0 ) {
F_86 ( L_112 ) ;
V_136 = F_158 ( F_127 , NULL ,
L_38 ) ;
if ( F_143 ( V_136 ) ) {
V_189 = F_144 ( V_136 ) ;
F_174 ( L_113 ) ;
V_136 = NULL ;
goto V_209;
}
}
if ( V_142 ) {
V_133 = F_131 () - 1 ;
if ( ! F_184 ( & V_132 , V_172 ) ) {
V_189 = - V_173 ;
F_174 ( L_114 ) ;
goto V_209;
}
V_185 = F_158 ( F_135 , NULL ,
L_41 ) ;
if ( F_143 ( V_185 ) ) {
F_180 ( V_132 ) ;
V_189 = F_144 ( V_185 ) ;
F_174 ( L_115 ) ;
V_185 = NULL ;
goto V_209;
}
}
if ( V_138 < 0 )
V_138 = 0 ;
if ( V_138 ) {
V_184 = F_158 ( F_136 , NULL ,
L_44 ) ;
if ( F_143 ( V_184 ) ) {
V_189 = F_144 ( V_184 ) ;
F_174 ( L_116 ) ;
V_184 = NULL ;
goto V_209;
}
}
if ( V_90 < 0 )
V_90 = 0 ;
if ( V_90 ) {
V_186 = F_158 ( F_94 , NULL ,
L_12 ) ;
if ( F_143 ( V_186 ) ) {
V_189 = F_144 ( V_186 ) ;
F_174 ( L_117 ) ;
V_186 = NULL ;
goto V_209;
}
}
if ( V_85 < 1 )
V_85 = 1 ;
if ( V_82 < 2 )
V_82 = 2 ;
if ( ( V_143 == 1 && V_46 -> V_144 ) ||
V_143 == 2 ) {
V_79 = V_80 + V_85 * V_33 ;
F_185 ( & V_187 ) ;
F_71 (i) {
if ( F_186 ( V_39 ) )
continue;
V_150 = F_140 ( V_39 ) ;
if ( V_150 < 0 ) {
V_189 = V_150 ;
goto V_209;
}
}
}
if ( V_145 > 0 ) {
V_153 = V_80 + V_145 * V_33 ;
V_154 = F_158 ( F_147 , NULL ,
L_118 ) ;
if ( F_143 ( V_154 ) ) {
V_189 = F_144 ( V_154 ) ;
F_174 ( L_119 ) ;
V_154 = NULL ;
goto V_209;
}
}
V_39 = F_157 () ;
if ( V_39 != 0 ) {
V_189 = V_39 ;
goto V_209;
}
F_187 ( & V_183 ) ;
V_39 = F_162 () ;
if ( V_39 != 0 ) {
V_189 = V_39 ;
goto V_209;
}
V_150 = F_171 () ;
if ( V_150 != 0 ) {
V_189 = V_150 ;
goto V_209;
}
F_178 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_209:
F_4 ( & V_5 ) ;
F_148 () ;
return V_189 ;
}
