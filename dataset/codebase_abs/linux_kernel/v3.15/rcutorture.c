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
static void
F_26 ( struct V_20 * V_6 )
{
int V_21 ;
struct V_4 * V_22 = F_10 ( V_6 , struct V_4 , V_23 ) ;
if ( F_27 () ) {
return;
}
V_21 = V_22 -> V_24 ;
if ( V_21 > V_25 )
V_21 = V_25 ;
F_7 ( & V_26 [ V_21 ] ) ;
if ( ++ V_22 -> V_24 >= V_25 ) {
V_22 -> V_27 = 0 ;
F_11 ( V_22 ) ;
} else {
V_28 -> V_29 ( V_22 ) ;
}
}
static int F_28 ( void )
{
return 0 ;
}
static void F_29 ( struct V_4 * V_6 )
{
F_30 ( & V_6 -> V_23 , F_26 ) ;
}
static void F_31 ( void )
{
F_32 ( & V_30 ) ;
}
static int F_33 ( void ) __acquires( T_5 )
{
F_34 () ;
return 0 ;
}
static void F_35 ( int V_19 ) __releases( T_5 )
{
F_36 () ;
}
static int F_37 ( void )
{
return F_38 () ;
}
static void F_39 ( struct V_4 * V_6 )
{
F_40 ( & V_6 -> V_23 , F_26 ) ;
}
static void F_41 ( struct V_4 * V_6 )
{
F_26 ( & V_6 -> V_23 ) ;
}
static void F_42 ( void )
{
}
static void
F_43 ( struct V_20 * V_31 , void (* F_44)( struct V_20 * V_32 ) )
{
F_44 ( V_31 ) ;
}
static int F_45 ( void ) __acquires( &srcu_ctl
static void F_46 ( struct V_14 * V_15 )
{
long V_33 ;
const long V_34 = 1000000 / V_35 ;
const long V_36 = 10 ;
V_33 = F_16 ( V_15 ) %
( V_18 * 2 * V_36 * V_34 ) ;
if ( ! V_33 )
F_47 ( V_36 ) ;
else
F_15 ( V_15 ) ;
}
static void F_48 ( int V_19 ) __releases( &srcu_ctl
static int F_49 ( void )
{
return F_50 ( & V_37 ) ;
}
static void F_51 ( struct V_4 * V_22 )
{
F_52 ( & V_37 , & V_22 -> V_23 , F_26 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_37 ) ;
}
static void F_55 ( struct V_20 * V_31 ,
void (* F_44)( struct V_20 * V_31 ) )
{
F_52 ( & V_37 , V_31 , F_44 ) ;
}
static void F_56 ( void )
{
F_57 ( & V_37 ) ;
}
static void F_58 ( char * V_38 )
{
int V_39 ;
int V_19 = V_37 . V_40 & 0x1 ;
V_38 += sprintf ( V_38 , L_1 ,
V_41 , V_42 , V_19 ) ;
F_59 (cpu) {
V_38 += sprintf ( V_38 , L_2 , V_39 ,
F_60 ( V_37 . V_43 , V_39 ) -> V_44 [ ! V_19 ] ,
F_60 ( V_37 . V_43 , V_39 ) -> V_44 [ V_19 ] ) ;
}
sprintf ( V_38 , L_3 ) ;
}
static void F_61 ( void )
{
F_62 ( & V_37 ) ;
}
static int F_63 ( void )
{
F_64 () ;
return 0 ;
}
static void F_65 ( int V_19 )
{
F_66 () ;
}
static void F_67 ( struct V_4 * V_6 )
{
F_68 ( & V_6 -> V_23 , F_26 ) ;
}
static void F_69 ( struct V_20 * V_31 )
{
struct V_45 * V_46 =
F_10 ( V_31 , struct V_45 , V_32 ) ;
F_70 () ;
V_46 -> V_47 = 0 ;
}
static int F_71 ( void * V_48 )
{
unsigned long V_49 ;
unsigned long V_50 ;
unsigned long V_51 ;
struct V_45 V_52 = { . V_47 = 0 } ;
struct V_53 V_54 ;
F_72 ( L_4 ) ;
V_54 . V_55 = 1 ;
if ( F_73 ( V_56 , V_57 , & V_54 ) < 0 ) {
F_72 ( L_5 ) ;
V_58 ++ ;
}
F_74 ( & V_52 . V_32 ) ;
do {
V_51 = V_59 ;
while ( F_75 ( V_60 , V_51 ) ) {
F_47 ( V_51 - V_60 ) ;
F_76 ( L_6 ) ;
if ( F_77 () )
goto V_61;
}
V_50 = V_51 + V_62 * V_35 ;
V_49 = V_60 ;
while ( F_75 ( V_60 , V_50 ) ) {
if ( ! V_52 . V_47 ) {
F_70 () ;
V_52 . V_47 = 1 ;
F_30 ( & V_52 . V_32 , F_69 ) ;
if ( V_60 - V_49 >
V_62 * V_35 - V_35 / 2 ) {
F_72 ( L_7 ) ;
V_63 ++ ;
}
V_49 = V_60 ;
}
F_78 () ;
F_76 ( L_6 ) ;
if ( F_77 () )
goto V_61;
}
while ( V_51 == V_59 &&
! F_79 () ) {
if ( F_80 ( & V_64 ) ) {
V_59 = V_60 +
V_65 * V_35 ;
V_66 ++ ;
F_81 ( & V_64 ) ;
break;
}
F_82 ( 1 ) ;
}
V_61: F_76 ( L_6 ) ;
} while ( ! F_77 () );
while ( ! F_79 () || V_52 . V_47 ) {
F_83 ( L_6 ) ;
F_82 ( 1 ) ;
}
F_70 () ;
F_84 ( & V_52 . V_32 ) ;
F_85 ( L_6 ) ;
return 0 ;
}
static int
F_86 ( void * V_48 )
{
unsigned long V_67 ;
int V_68 ;
F_72 ( L_8 ) ;
do {
V_67 = V_60 + V_69 * V_35 ;
while ( F_75 ( V_60 , V_67 ) &&
! F_79 () ) {
F_47 ( 1 ) ;
}
V_68 = V_70 ;
while ( V_68 > 0 &&
! F_79 () ) {
V_28 -> V_71 () ;
F_18 ( V_72 ) ;
V_68 -= V_72 ;
}
F_76 ( L_9 ) ;
} while ( ! F_77 () );
F_85 ( L_9 ) ;
return 0 ;
}
static int
F_87 ( void * V_48 )
{
bool exp ;
int V_21 ;
struct V_4 * V_22 ;
struct V_4 * V_73 ;
struct V_4 * V_74 ;
static F_88 ( rand ) ;
F_72 ( L_10 ) ;
F_89 ( V_56 , V_75 ) ;
do {
F_82 ( 1 ) ;
V_22 = F_4 () ;
if ( V_22 == NULL )
continue;
V_22 -> V_24 = 0 ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
V_74 = F_90 ( V_76 ,
V_56 == V_77 ) ;
V_22 -> V_27 = 1 ;
F_91 ( V_76 , V_22 ) ;
F_92 () ;
if ( V_74 ) {
V_21 = V_74 -> V_24 ;
if ( V_21 > V_25 )
V_21 = V_25 ;
F_7 ( & V_26 [ V_21 ] ) ;
V_74 -> V_24 ++ ;
if ( V_78 == V_79 )
exp = ! ! ( F_16 ( & rand ) & 0x80 ) ;
else
exp = V_79 ;
if ( ! exp ) {
V_28 -> V_29 ( V_74 ) ;
} else {
V_28 -> V_80 () ;
F_93 ( & V_74 -> V_12 ,
& V_30 ) ;
F_94 (rp, rp1,
&rcu_torture_removed,
rtort_free) {
V_21 = V_22 -> V_24 ;
if ( V_21 > V_25 )
V_21 = V_25 ;
F_7 ( & V_26 [ V_21 ] ) ;
if ( ++ V_22 -> V_24 >=
V_25 ) {
V_22 -> V_27 = 0 ;
F_95 ( & V_22 -> V_12 ) ;
F_11 ( V_22 ) ;
}
}
}
}
F_96 ( ++ V_81 ) ;
F_76 ( L_11 ) ;
} while ( ! F_77 () );
F_85 ( L_11 ) ;
return 0 ;
}
static int
F_97 ( void * V_48 )
{
F_88 ( rand ) ;
F_72 ( L_12 ) ;
F_89 ( V_56 , V_75 ) ;
do {
F_82 ( 1 + F_16 ( & rand ) % 10 ) ;
F_18 ( F_16 ( & rand ) & 0x3ff ) ;
if ( V_28 -> V_82 != NULL &&
F_16 ( & rand ) % ( V_83 * 8 ) == 0 ) {
V_28 -> V_82 () ;
} else if ( V_78 == V_79 ) {
if ( F_16 ( & rand ) & 0x80 )
V_28 -> V_84 () ;
else
V_28 -> V_80 () ;
} else if ( V_78 ) {
V_28 -> V_84 () ;
} else {
V_28 -> V_80 () ;
}
F_76 ( L_13 ) ;
} while ( ! F_77 () );
F_85 ( L_13 ) ;
return 0 ;
}
void F_98 ( void )
{
static T_6 V_85 = F_99 ( 0 ) ;
if ( F_100 ( & V_85 ) )
return;
if ( F_101 ( & V_85 , 1 ) != 0 )
return;
F_102 ( V_86 ) ;
}
static void F_103 ( unsigned long V_87 )
{
int V_19 ;
int V_40 ;
int V_88 ;
static F_88 ( rand ) ;
static F_104 ( V_89 ) ;
struct V_4 * V_6 ;
int V_90 ;
unsigned long long V_1 ;
V_19 = V_28 -> V_91 () ;
V_40 = V_28 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_90 ( V_76 ,
F_105 () ||
F_106 () ||
F_107 ( & V_37 ) ) ;
if ( V_6 == NULL ) {
V_28 -> V_92 ( V_19 ) ;
return;
}
if ( V_6 -> V_27 == 0 )
F_7 ( & V_93 ) ;
F_108 ( & V_89 ) ;
V_28 -> V_94 ( & rand ) ;
V_95 ++ ;
F_109 ( & V_89 ) ;
F_64 () ;
V_90 = V_6 -> V_24 ;
if ( V_90 > V_25 ) {
V_90 = V_25 ;
}
V_88 = V_28 -> V_40 () ;
if ( V_90 > 1 ) {
F_110 ( V_28 -> V_96 , & V_6 -> V_23 , V_1 ,
V_40 , V_88 ) ;
F_98 () ;
}
F_111 ( V_97 [ V_90 ] ) ;
V_40 = V_88 - V_40 ;
if ( V_40 > V_25 ) {
V_40 = V_25 ;
}
F_111 ( V_98 [ V_40 ] ) ;
F_66 () ;
V_28 -> V_92 ( V_19 ) ;
}
static int
F_112 ( void * V_48 )
{
int V_40 ;
int V_88 ;
int V_19 ;
F_88 ( rand ) ;
struct V_4 * V_6 ;
int V_90 ;
struct V_99 V_100 ;
unsigned long long V_1 ;
F_72 ( L_14 ) ;
F_89 ( V_56 , V_75 ) ;
if ( V_101 && V_28 -> V_102 )
F_113 ( & V_100 , F_103 , 0 ) ;
do {
if ( V_101 && V_28 -> V_102 ) {
if ( ! F_114 ( & V_100 ) )
F_115 ( & V_100 , V_60 + 1 ) ;
}
V_19 = V_28 -> V_91 () ;
V_40 = V_28 -> V_40 () ;
V_1 = F_1 () ;
V_6 = F_90 ( V_76 ,
F_105 () ||
F_106 () ||
F_107 ( & V_37 ) ) ;
if ( V_6 == NULL ) {
V_28 -> V_92 ( V_19 ) ;
F_47 ( V_35 ) ;
continue;
}
if ( V_6 -> V_27 == 0 )
F_7 ( & V_93 ) ;
V_28 -> V_94 ( & rand ) ;
F_64 () ;
V_90 = V_6 -> V_24 ;
if ( V_90 > V_25 ) {
V_90 = V_25 ;
}
V_88 = V_28 -> V_40 () ;
if ( V_90 > 1 ) {
F_110 ( V_28 -> V_96 , & V_6 -> V_23 ,
V_1 , V_40 , V_88 ) ;
F_98 () ;
}
F_111 ( V_97 [ V_90 ] ) ;
V_40 = V_88 - V_40 ;
if ( V_40 > V_25 ) {
V_40 = V_25 ;
}
F_111 ( V_98 [ V_40 ] ) ;
F_66 () ;
V_28 -> V_92 ( V_19 ) ;
F_116 () ;
F_76 ( L_15 ) ;
} while ( ! F_77 () );
if ( V_101 && V_28 -> V_102 )
F_117 ( & V_100 ) ;
F_85 ( L_15 ) ;
return 0 ;
}
static void
F_118 ( char * V_38 )
{
int V_39 ;
int V_21 ;
long V_103 [ V_25 + 1 ] = { 0 } ;
long V_104 [ V_25 + 1 ] = { 0 } ;
F_59 (cpu) {
for ( V_21 = 0 ; V_21 < V_25 + 1 ; V_21 ++ ) {
V_103 [ V_21 ] += F_119 ( V_97 , V_39 ) [ V_21 ] ;
V_104 [ V_21 ] += F_119 ( V_98 , V_39 ) [ V_21 ] ;
}
}
for ( V_21 = V_25 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( V_103 [ V_21 ] != 0 )
break;
}
V_38 += sprintf ( V_38 , L_16 , V_41 , V_42 ) ;
V_38 += sprintf ( V_38 ,
L_17 ,
V_76 ,
V_81 ,
F_6 ( & V_8 ) ,
F_100 ( & V_10 ) ,
F_100 ( & V_9 ) ,
F_100 ( & V_13 ) ) ;
V_38 += sprintf ( V_38 , L_18 ,
F_100 ( & V_93 ) ,
V_105 ,
V_58 ) ;
V_38 += sprintf ( V_38 , L_19 ,
V_63 ,
V_66 ,
V_95 ) ;
V_38 = F_120 ( V_38 ) ;
V_38 += sprintf ( V_38 , L_20 ,
V_106 ,
V_107 ,
V_108 ) ;
V_38 += sprintf ( V_38 , L_21 , V_41 , V_42 ) ;
if ( F_100 ( & V_93 ) != 0 ||
V_108 != 0 ||
V_105 != 0 ||
V_58 != 0 ||
V_63 != 0 ||
V_21 > 1 ) {
V_38 += sprintf ( V_38 , L_22 ) ;
F_7 ( & V_109 ) ;
F_121 ( 1 ) ;
}
V_38 += sprintf ( V_38 , L_23 ) ;
for ( V_21 = 0 ; V_21 < V_25 + 1 ; V_21 ++ )
V_38 += sprintf ( V_38 , L_24 , V_103 [ V_21 ] ) ;
V_38 += sprintf ( V_38 , L_21 , V_41 , V_42 ) ;
V_38 += sprintf ( V_38 , L_25 ) ;
for ( V_21 = 0 ; V_21 < V_25 + 1 ; V_21 ++ )
V_38 += sprintf ( V_38 , L_24 , V_104 [ V_21 ] ) ;
V_38 += sprintf ( V_38 , L_21 , V_41 , V_42 ) ;
V_38 += sprintf ( V_38 , L_26 ) ;
for ( V_21 = 0 ; V_21 < V_25 + 1 ; V_21 ++ ) {
V_38 += sprintf ( V_38 , L_27 ,
F_100 ( & V_26 [ V_21 ] ) ) ;
}
V_38 += sprintf ( V_38 , L_3 ) ;
if ( V_28 -> V_110 )
V_28 -> V_110 ( V_38 ) ;
}
static void
F_122 ( void )
{
int V_111 = V_112 * 200 + 8192 ;
char * V_113 ;
V_113 = F_123 ( V_111 , V_114 ) ;
if ( ! V_113 ) {
F_124 ( L_28 , V_111 ) ;
return;
}
F_118 ( V_113 ) ;
F_125 ( L_29 , V_113 ) ;
F_126 ( V_113 ) ;
}
static int
F_127 ( void * V_48 )
{
F_72 ( L_30 ) ;
do {
F_47 ( V_115 * V_35 ) ;
F_122 () ;
F_83 ( L_31 ) ;
} while ( ! F_77 () );
F_85 ( L_31 ) ;
return 0 ;
}
static inline void
F_128 ( struct V_116 * V_28 , const char * V_117 )
{
F_125 ( L_29 V_42
L_32
L_33
L_34
L_35
L_36
L_37
L_38
L_39
L_40 ,
V_41 , V_117 , V_18 , V_83 ,
V_115 , V_118 , V_119 , V_120 ,
V_121 , V_101 , V_70 , V_72 , V_69 ,
V_122 , V_28 -> V_123 ,
V_65 , V_62 , V_124 ,
V_125 , V_126 ,
V_127 ,
V_128 , V_129 ) ;
}
static void F_129 ( int V_39 )
{
struct V_130 * V_100 ;
if ( V_131 [ V_39 ] == NULL )
return;
F_130 ( & V_64 ) ;
V_100 = V_131 [ V_39 ] ;
V_131 [ V_39 ] = NULL ;
F_81 ( & V_64 ) ;
F_131 ( F_71 , V_100 ) ;
}
static int F_132 ( int V_39 )
{
int V_132 ;
if ( V_131 [ V_39 ] != NULL )
return 0 ;
F_130 ( & V_64 ) ;
F_72 ( L_41 ) ;
V_131 [ V_39 ] = F_133 ( F_71 , NULL ,
F_134 ( V_39 ) ,
L_6 ) ;
if ( F_135 ( V_131 [ V_39 ] ) ) {
V_132 = F_136 ( V_131 [ V_39 ] ) ;
F_72 ( L_42 ) ;
V_105 ++ ;
V_131 [ V_39 ] = NULL ;
F_81 ( & V_64 ) ;
return V_132 ;
}
F_137 ( V_131 [ V_39 ] , V_39 ) ;
F_138 ( V_131 [ V_39 ] ) ;
F_81 ( & V_64 ) ;
return 0 ;
}
static int F_139 ( void * args )
{
unsigned long V_133 ;
F_72 ( L_43 ) ;
if ( V_126 > 0 ) {
F_72 ( L_44 ) ;
F_47 ( V_126 * V_35 ) ;
F_72 ( L_45 ) ;
}
if ( ! F_79 () ) {
V_133 = F_140 () + V_125 ;
F_125 ( L_46 ) ;
F_14 () ;
F_64 () ;
while ( F_75 ( F_140 () , V_133 ) )
continue;
F_66 () ;
F_23 () ;
F_125 ( L_47 ) ;
}
F_83 ( L_48 ) ;
while ( ! F_79 () )
F_47 ( 10 * V_35 ) ;
return 0 ;
}
static int T_7 F_141 ( void )
{
if ( V_125 <= 0 )
return 0 ;
return F_142 ( F_139 , NULL , V_134 ) ;
}
void F_143 ( struct V_20 * V_32 )
{
F_7 ( & V_135 ) ;
}
static int F_144 ( void * V_48 )
{
long V_136 = ( long ) V_48 ;
bool V_137 = 0 ;
bool V_138 ;
struct V_20 V_32 ;
F_74 ( & V_32 ) ;
F_72 ( L_49 ) ;
F_89 ( V_56 , V_75 ) ;
do {
F_145 ( V_139 [ V_136 ] ,
( V_138 =
F_146 ( V_140 ) ) != V_137 ||
F_77 () ) ;
V_137 = V_138 ;
F_70 () ;
if ( F_77 () )
break;
V_28 -> V_141 ( & V_32 , F_143 ) ;
if ( F_147 ( & V_142 ) )
F_148 ( & V_143 ) ;
} while ( ! F_77 () );
V_28 -> V_82 () ;
F_84 ( & V_32 ) ;
F_85 ( L_50 ) ;
return 0 ;
}
static int F_149 ( void * V_48 )
{
int V_21 ;
F_72 ( L_51 ) ;
do {
F_150 ( & V_135 , 0 ) ;
F_150 ( & V_142 , V_127 ) ;
F_70 () ;
V_140 = ! V_140 ;
for ( V_21 = 0 ; V_21 < V_127 ; V_21 ++ )
F_148 ( & V_139 [ V_21 ] ) ;
F_145 ( V_143 ,
F_100 ( & V_142 ) == 0 ||
F_77 () ) ;
if ( F_77 () )
break;
V_107 ++ ;
V_28 -> V_82 () ;
if ( F_100 ( & V_135 ) != V_127 ) {
V_108 ++ ;
F_121 ( 1 ) ;
}
V_106 ++ ;
F_47 ( V_35 / 10 ) ;
} while ( ! F_77 () );
F_85 ( L_52 ) ;
return 0 ;
}
static int F_151 ( void )
{
int V_21 ;
int V_144 ;
if ( V_127 == 0 )
return 0 ;
if ( V_28 -> V_141 == NULL || V_28 -> V_82 == NULL ) {
F_125 ( L_29 V_42
L_53 ,
V_41 , V_28 -> V_96 ) ;
F_125 ( L_29 V_42
L_54 ,
V_41 ) ;
return 0 ;
}
F_150 ( & V_142 , 0 ) ;
F_150 ( & V_135 , 0 ) ;
V_145 =
F_152 ( V_127 * sizeof( V_145 [ 0 ] ) ,
V_114 ) ;
V_139 =
F_152 ( V_127 * sizeof( V_139 [ 0 ] ) ,
V_114 ) ;
if ( V_145 == NULL || ! V_139 )
return - V_146 ;
for ( V_21 = 0 ; V_21 < V_127 ; V_21 ++ ) {
F_153 ( & V_139 [ V_21 ] ) ;
V_144 = F_142 ( F_144 ,
( void * ) ( long ) V_21 ,
V_145 [ V_21 ] ) ;
if ( V_144 )
return V_144 ;
}
return F_142 ( F_149 , NULL , V_147 ) ;
}
static void F_154 ( void )
{
int V_21 ;
F_131 ( F_149 , V_147 ) ;
if ( V_145 != NULL ) {
for ( V_21 = 0 ; V_21 < V_127 ; V_21 ++ )
F_131 ( F_144 ,
V_145 [ V_21 ] ) ;
F_126 ( V_145 ) ;
V_145 = NULL ;
}
if ( V_139 != NULL ) {
F_126 ( V_139 ) ;
V_139 = NULL ;
}
}
static int F_155 ( struct V_148 * V_149 ,
unsigned long V_150 , void * V_151 )
{
long V_39 = ( long ) V_151 ;
switch ( V_150 ) {
case V_152 :
case V_153 :
( void ) F_132 ( V_39 ) ;
break;
case V_154 :
F_129 ( V_39 ) ;
break;
default:
break;
}
return V_155 ;
}
static void
F_156 ( void )
{
int V_21 ;
F_157 () ;
if ( F_158 () ) {
if ( V_28 -> V_82 != NULL )
V_28 -> V_82 () ;
return;
}
F_154 () ;
F_131 ( F_139 , V_134 ) ;
F_131 ( F_87 , V_77 ) ;
if ( V_156 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_131 ( F_112 ,
V_156 [ V_21 ] ) ;
F_126 ( V_156 ) ;
}
V_76 = NULL ;
if ( V_157 ) {
for ( V_21 = 0 ; V_21 < V_83 ; V_21 ++ ) {
F_131 ( F_97 ,
V_157 [ V_21 ] ) ;
}
F_126 ( V_157 ) ;
V_157 = NULL ;
}
F_131 ( F_127 , V_158 ) ;
F_131 ( F_86 , V_159 ) ;
if ( ( V_122 == 1 && V_28 -> V_123 ) ||
V_122 == 2 ) {
F_159 ( & V_160 ) ;
F_59 (i)
F_129 ( V_21 ) ;
}
if ( V_28 -> V_82 != NULL )
V_28 -> V_82 () ;
F_122 () ;
if ( F_100 ( & V_109 ) || V_108 )
F_128 ( V_28 , L_55 ) ;
else if ( F_160 () )
F_128 ( V_28 ,
L_56 ) ;
else
F_128 ( V_28 , L_57 ) ;
}
static void F_161 ( struct V_20 * V_161 )
{
}
static void F_162 ( struct V_20 * V_161 )
{
F_125 ( L_58 ) ;
}
static void F_163 ( void )
{
#ifdef F_164
struct V_20 V_162 ;
struct V_20 V_163 ;
F_74 ( & V_162 ) ;
F_74 ( & V_163 ) ;
F_125 ( L_59 ) ;
F_64 () ;
F_14 () ;
F_30 ( & V_162 , F_161 ) ;
F_165 () ;
F_30 ( & V_163 , F_161 ) ;
F_30 ( & V_163 , F_162 ) ;
F_166 () ;
F_23 () ;
F_66 () ;
F_167 () ;
F_125 ( L_60 ) ;
F_84 ( & V_162 ) ;
F_84 ( & V_163 ) ;
#else
F_125 ( L_61 ) ;
#endif
}
static int T_7
F_168 ( void )
{
int V_21 ;
int V_39 ;
int V_164 = 0 ;
static struct V_116 * V_165 [] = {
& V_166 , & V_167 , & V_168 , & V_169 , & V_170 ,
} ;
F_169 ( V_41 , V_118 , & V_171 ) ;
for ( V_21 = 0 ; V_21 < F_170 ( V_165 ) ; V_21 ++ ) {
V_28 = V_165 [ V_21 ] ;
if ( strcmp ( V_41 , V_28 -> V_96 ) == 0 )
break;
}
if ( V_21 == F_170 ( V_165 ) ) {
F_125 ( L_62 ,
V_41 ) ;
F_125 ( L_63 ) ;
for ( V_21 = 0 ; V_21 < F_170 ( V_165 ) ; V_21 ++ )
F_125 ( L_64 , V_165 [ V_21 ] -> V_96 ) ;
F_125 ( L_3 ) ;
F_171 () ;
return - V_172 ;
}
if ( V_28 -> V_71 == NULL && V_70 != 0 ) {
F_125 ( L_65 ) ;
V_70 = 0 ;
}
if ( V_28 -> V_173 )
V_28 -> V_173 () ;
if ( V_174 >= 0 )
V_18 = V_174 ;
else
V_18 = 2 * F_172 () ;
F_128 ( V_28 , L_66 ) ;
F_32 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 < F_170 ( V_175 ) ; V_21 ++ ) {
V_175 [ V_21 ] . V_27 = 0 ;
F_12 ( & V_175 [ V_21 ] . V_12 ,
& V_8 ) ;
}
V_76 = NULL ;
V_81 = 0 ;
F_150 ( & V_10 , 0 ) ;
F_150 ( & V_9 , 0 ) ;
F_150 ( & V_13 , 0 ) ;
F_150 ( & V_93 , 0 ) ;
F_150 ( & V_109 , 0 ) ;
V_108 = 0 ;
V_105 = 0 ;
V_58 = 0 ;
V_63 = 0 ;
V_66 = 0 ;
for ( V_21 = 0 ; V_21 < V_25 + 1 ; V_21 ++ )
F_150 ( & V_26 [ V_21 ] , 0 ) ;
F_59 (cpu) {
for ( V_21 = 0 ; V_21 < V_25 + 1 ; V_21 ++ ) {
F_119 ( V_97 , V_39 ) [ V_21 ] = 0 ;
F_119 ( V_98 , V_39 ) [ V_21 ] = 0 ;
}
}
V_164 = F_142 ( F_87 , NULL ,
V_77 ) ;
if ( V_164 )
goto V_176;
V_157 = F_152 ( V_83 * sizeof( V_157 [ 0 ] ) ,
V_114 ) ;
if ( V_157 == NULL ) {
F_173 ( L_67 ) ;
V_164 = - V_146 ;
goto V_176;
}
for ( V_21 = 0 ; V_21 < V_83 ; V_21 ++ ) {
V_164 = F_142 ( F_97 ,
NULL , V_157 [ V_21 ] ) ;
if ( V_164 )
goto V_176;
}
V_156 = F_152 ( V_18 * sizeof( V_156 [ 0 ] ) ,
V_114 ) ;
if ( V_156 == NULL ) {
F_173 ( L_67 ) ;
V_164 = - V_146 ;
goto V_176;
}
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
V_164 = F_142 ( F_112 , NULL ,
V_156 [ V_21 ] ) ;
if ( V_164 )
goto V_176;
}
if ( V_115 > 0 ) {
V_164 = F_142 ( F_127 , NULL ,
V_158 ) ;
if ( V_164 )
goto V_176;
}
if ( V_119 ) {
V_164 = F_174 ( V_120 * V_35 ) ;
if ( V_164 )
goto V_176;
}
if ( V_121 < 0 )
V_121 = 0 ;
if ( V_121 ) {
V_164 = F_175 ( V_121 * V_35 ) ;
if ( V_164 )
goto V_176;
}
if ( V_70 < 0 )
V_70 = 0 ;
if ( V_70 ) {
F_142 ( F_86 , NULL , V_159 ) ;
if ( V_164 )
goto V_176;
}
if ( V_65 < 1 )
V_65 = 1 ;
if ( V_62 < 2 )
V_62 = 2 ;
if ( ( V_122 == 1 && V_28 -> V_123 ) ||
V_122 == 2 ) {
V_59 = V_60 + V_65 * V_35 ;
F_176 ( & V_160 ) ;
F_59 (i) {
if ( F_177 ( V_21 ) )
continue;
V_164 = F_132 ( V_21 ) ;
if ( V_164 )
goto V_176;
}
}
V_164 = F_178 ( V_124 , F_156 ) ;
if ( V_164 )
goto V_176;
V_164 = F_179 ( V_129 * V_35 , V_128 * V_35 ) ;
if ( V_164 )
goto V_176;
V_164 = F_141 () ;
if ( V_164 )
goto V_176;
V_164 = F_151 () ;
if ( V_164 )
goto V_176;
if ( V_177 )
F_163 () ;
F_157 () ;
F_171 () ;
return 0 ;
V_176:
F_171 () ;
F_156 () ;
return V_164 ;
}
