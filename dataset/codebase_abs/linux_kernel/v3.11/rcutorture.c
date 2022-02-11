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
static void F_73 ( void )
{
F_74 ( & V_55 ) ;
}
static int F_75 ( void )
{
F_76 () ;
return 0 ;
}
static void F_77 ( int V_38 )
{
F_78 () ;
}
static void F_79 ( struct V_15 * V_17 )
{
F_80 ( & V_17 -> V_42 , F_39 ) ;
}
static void F_81 ( struct V_39 * V_56 )
{
struct V_65 * V_66 =
F_18 ( V_56 , struct V_65 , V_67 ) ;
F_82 () ;
V_66 -> V_68 = 0 ;
}
static int F_83 ( void * V_69 )
{
unsigned long V_70 ;
unsigned long V_71 ;
unsigned long V_72 ;
struct V_65 V_73 = { . V_68 = 0 } ;
struct V_74 V_75 ;
F_84 ( L_6 ) ;
V_75 . V_76 = 1 ;
if ( F_85 ( V_77 , V_78 , & V_75 ) < 0 ) {
F_84 ( L_7 ) ;
V_79 ++ ;
}
F_86 ( & V_73 . V_67 ) ;
do {
V_72 = V_80 ;
while ( F_87 ( V_81 , V_72 ) ) {
F_25 ( V_72 - V_81 ) ;
F_24 ( L_8 ) ;
if ( F_88 () ||
V_9 != V_10 )
goto V_82;
}
V_71 = V_72 + V_83 * V_34 ;
V_70 = V_81 ;
while ( F_87 ( V_81 , V_71 ) ) {
if ( ! V_73 . V_68 ) {
F_82 () ;
V_73 . V_68 = 1 ;
F_42 ( & V_73 . V_67 , F_81 ) ;
if ( V_81 - V_70 >
V_83 * V_34 - V_34 / 2 ) {
F_84 ( L_9 ) ;
V_84 ++ ;
}
V_70 = V_81 ;
}
F_89 () ;
F_24 ( L_8 ) ;
if ( F_88 () ||
V_9 != V_10 )
goto V_82;
}
while ( V_72 == V_80 &&
! F_88 () ) {
if ( F_90 ( & V_85 ) ) {
V_80 = V_81 +
V_86 * V_34 ;
V_87 ++ ;
F_7 ( & V_85 ) ;
break;
}
F_11 ( 1 ) ;
}
V_82: F_24 ( L_8 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_10 ) ;
F_8 ( L_8 ) ;
while ( ! F_88 () || V_73 . V_68 )
F_11 ( 1 ) ;
F_82 () ;
F_91 ( & V_73 . V_67 ) ;
return 0 ;
}
static int
F_92 ( void * V_69 )
{
unsigned long V_88 ;
int V_89 ;
F_84 ( L_11 ) ;
do {
V_88 = V_81 + V_90 * V_34 ;
while ( F_87 ( V_81 , V_88 ) &&
! F_88 () ) {
F_25 ( 1 ) ;
}
V_89 = V_91 ;
while ( V_89 > 0 &&
! F_88 () ) {
V_47 -> V_92 () ;
F_31 ( V_93 ) ;
V_89 -= V_93 ;
}
F_24 ( L_12 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_13 ) ;
F_8 ( L_12 ) ;
while ( ! F_88 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_93 ( void * V_69 )
{
int V_40 ;
long V_94 = F_38 () ;
struct V_15 * V_41 ;
struct V_15 * V_95 ;
static F_94 ( rand ) ;
F_84 ( L_14 ) ;
F_95 ( V_77 , 19 ) ;
do {
F_11 ( 1 ) ;
V_41 = F_12 () ;
if ( V_41 == NULL )
continue;
V_41 -> V_43 = 0 ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
V_95 = F_96 ( V_96 ,
V_77 == V_97 ) ;
V_41 -> V_46 = 1 ;
F_97 ( V_96 , V_41 ) ;
F_98 () ;
if ( V_95 ) {
V_40 = V_95 -> V_43 ;
if ( V_40 > V_44 )
V_40 = V_44 ;
F_15 ( & V_45 [ V_40 ] ) ;
V_95 -> V_43 ++ ;
V_47 -> V_48 ( V_95 ) ;
}
F_99 ( ++ V_98 ) ;
V_94 = V_47 -> V_60 () ;
F_24 ( L_15 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_16 ) ;
F_8 ( L_15 ) ;
while ( ! F_88 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_100 ( void * V_69 )
{
F_94 ( rand ) ;
F_84 ( L_17 ) ;
F_95 ( V_77 , 19 ) ;
do {
F_11 ( 1 + F_21 ( & rand ) % 10 ) ;
F_31 ( F_21 ( & rand ) & 0x3ff ) ;
if ( V_47 -> V_99 != NULL &&
F_21 ( & rand ) % ( V_100 * 8 ) == 0 )
V_47 -> V_99 () ;
else
V_47 -> V_50 () ;
F_24 ( L_18 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_19 ) ;
F_8 ( L_18 ) ;
while ( ! F_88 () )
F_11 ( 1 ) ;
return 0 ;
}
void F_101 ( void )
{
static T_6 V_101 = F_102 ( 0 ) ;
if ( F_103 ( & V_101 ) )
return;
if ( F_104 ( & V_101 , 1 ) != 0 )
return;
F_105 ( V_102 ) ;
}
static void F_106 ( unsigned long V_103 )
{
int V_38 ;
int V_60 ;
int V_104 ;
static F_94 ( rand ) ;
static F_107 ( V_105 ) ;
struct V_15 * V_17 ;
int V_106 ;
unsigned long long V_1 ;
V_38 = V_47 -> V_107 () ;
V_60 = V_47 -> V_60 () ;
V_1 = F_1 () ;
V_17 = F_96 ( V_96 ,
F_108 () ||
F_109 () ||
F_110 ( & V_55 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_108 ( V_38 ) ;
return;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_109 ) ;
F_111 ( & V_105 ) ;
V_47 -> V_110 ( & rand ) ;
V_111 ++ ;
F_112 ( & V_105 ) ;
F_76 () ;
V_106 = V_17 -> V_43 ;
if ( V_106 > V_44 ) {
V_106 = V_44 ;
}
V_104 = V_47 -> V_60 () ;
if ( V_106 > 1 ) {
F_113 ( V_47 -> V_112 , & V_17 -> V_42 , V_1 ,
V_60 , V_104 ) ;
F_101 () ;
}
F_114 ( V_113 [ V_106 ] ) ;
V_60 = V_104 - V_60 ;
if ( V_60 > V_44 ) {
V_60 = V_44 ;
}
F_114 ( V_114 [ V_60 ] ) ;
F_78 () ;
V_47 -> V_108 ( V_38 ) ;
}
static int
F_115 ( void * V_69 )
{
int V_60 ;
int V_104 ;
int V_38 ;
F_94 ( rand ) ;
struct V_15 * V_17 ;
int V_106 ;
struct V_115 V_116 ;
unsigned long long V_1 ;
F_84 ( L_20 ) ;
F_95 ( V_77 , 19 ) ;
if ( V_117 && V_47 -> V_118 )
F_116 ( & V_116 , F_106 , 0 ) ;
do {
if ( V_117 && V_47 -> V_118 ) {
if ( ! F_117 ( & V_116 ) )
F_118 ( & V_116 , V_81 + 1 ) ;
}
V_38 = V_47 -> V_107 () ;
V_60 = V_47 -> V_60 () ;
V_1 = F_1 () ;
V_17 = F_96 ( V_96 ,
F_108 () ||
F_109 () ||
F_110 ( & V_55 ) ) ;
if ( V_17 == NULL ) {
V_47 -> V_108 ( V_38 ) ;
F_25 ( V_34 ) ;
continue;
}
if ( V_17 -> V_46 == 0 )
F_15 ( & V_109 ) ;
V_47 -> V_110 ( & rand ) ;
F_76 () ;
V_106 = V_17 -> V_43 ;
if ( V_106 > V_44 ) {
V_106 = V_44 ;
}
V_104 = V_47 -> V_60 () ;
if ( V_106 > 1 ) {
F_113 ( V_47 -> V_112 , & V_17 -> V_42 ,
V_1 , V_60 , V_104 ) ;
F_101 () ;
}
F_114 ( V_113 [ V_106 ] ) ;
V_60 = V_104 - V_60 ;
if ( V_60 > V_44 ) {
V_60 = V_44 ;
}
F_114 ( V_114 [ V_60 ] ) ;
F_78 () ;
V_47 -> V_108 ( V_38 ) ;
F_119 () ;
F_24 ( L_21 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_22 ) ;
F_8 ( L_21 ) ;
if ( V_117 && V_47 -> V_118 )
F_120 ( & V_116 ) ;
while ( ! F_88 () )
F_11 ( 1 ) ;
return 0 ;
}
static int
F_121 ( char * V_57 )
{
int V_58 = 0 ;
int V_59 ;
int V_40 ;
long V_119 [ V_44 + 1 ] = { 0 } ;
long V_120 [ V_44 + 1 ] = { 0 } ;
F_71 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
V_119 [ V_40 ] += F_122 ( V_113 , V_59 ) [ V_40 ] ;
V_120 [ V_40 ] += F_122 ( V_114 , V_59 ) [ V_40 ] ;
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
F_103 ( & V_21 ) ,
F_103 ( & V_20 ) ,
F_103 ( & V_24 ) ) ;
V_58 += sprintf ( & V_57 [ V_58 ] , L_25 ,
F_103 ( & V_109 ) ,
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
if ( F_103 ( & V_109 ) != 0 ||
V_134 != 0 ||
V_121 != 0 ||
V_79 != 0 ||
V_84 != 0 ||
V_40 > 1 ) {
V_58 += sprintf ( & V_57 [ V_58 ] , L_30 ) ;
F_15 ( & V_135 ) ;
F_123 ( 1 ) ;
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
F_103 ( & V_45 [ V_40 ] ) ) ;
}
V_58 += sprintf ( & V_57 [ V_58 ] , L_5 ) ;
if ( V_47 -> V_136 )
V_58 += V_47 -> V_136 ( & V_57 [ V_58 ] ) ;
return V_58 ;
}
static void
F_124 ( void )
{
int V_58 ;
V_58 = F_121 ( V_137 ) ;
F_125 ( L_36 , V_137 ) ;
}
static int
F_126 ( void * V_69 )
{
F_84 ( L_37 ) ;
do {
F_25 ( V_138 * V_34 ) ;
F_124 () ;
F_8 ( L_38 ) ;
} while ( ! F_88 () );
F_84 ( L_39 ) ;
return 0 ;
}
static void F_127 ( void )
{
int V_40 ;
F_128 ( V_139 ) ;
F_129 () ;
if ( F_130 () == 1 ) {
F_131 () ;
return;
}
if ( V_140 != - 1 )
F_132 ( V_140 , V_139 ) ;
F_133 ( V_77 , V_139 ) ;
if ( V_141 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ )
if ( V_141 [ V_40 ] )
F_133 ( V_141 [ V_40 ] ,
V_139 ) ;
}
if ( V_142 ) {
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ )
if ( V_142 [ V_40 ] )
F_133 ( V_142 [ V_40 ] ,
V_139 ) ;
}
if ( V_97 )
F_133 ( V_97 , V_139 ) ;
if ( V_143 )
F_133 ( V_143 , V_139 ) ;
if ( V_144 )
F_133 ( V_144 , V_139 ) ;
if ( V_145 )
F_133 ( V_145 , V_139 ) ;
if ( V_146 )
F_133 ( V_146 , V_139 ) ;
#ifdef F_134
if ( V_147 )
F_133 ( V_147 , V_139 ) ;
#endif
if ( V_148 )
F_133 ( V_148 , V_139 ) ;
if ( V_149 )
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ )
if ( V_149 [ V_40 ] )
F_133 ( V_149 [ V_40 ] ,
V_139 ) ;
if ( V_151 )
F_133 ( V_151 , V_139 ) ;
if ( V_140 == - 1 )
V_140 = F_130 () - 1 ;
else
V_140 -- ;
F_131 () ;
}
static int
F_135 ( void * V_69 )
{
F_84 ( L_40 ) ;
do {
F_25 ( V_152 * V_34 ) ;
F_127 () ;
F_8 ( L_41 ) ;
} while ( ! F_88 () );
F_84 ( L_42 ) ;
return 0 ;
}
static int
F_136 ( void * V_69 )
{
F_84 ( L_43 ) ;
do {
F_25 ( V_153 * V_34 ) ;
V_32 = 1 ;
if ( ! F_88 () )
F_25 ( V_153 * V_34 ) ;
V_32 = 0 ;
F_8 ( L_44 ) ;
} while ( ! F_88 () );
F_84 ( L_45 ) ;
return 0 ;
}
static inline void
F_137 ( struct V_154 * V_47 , char * V_155 )
{
F_125 ( L_36 V_62
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
static void F_138 ( int V_59 )
{
struct V_165 * V_116 ;
if ( V_166 [ V_59 ] == NULL )
return;
F_5 ( & V_85 ) ;
F_84 ( L_55 ) ;
V_116 = V_166 [ V_59 ] ;
V_166 [ V_59 ] = NULL ;
F_7 ( & V_85 ) ;
F_139 ( V_116 ) ;
V_166 [ V_59 ] = NULL ;
}
static int F_140 ( int V_59 )
{
int V_167 ;
if ( V_166 [ V_59 ] != NULL )
return 0 ;
F_5 ( & V_85 ) ;
F_84 ( L_56 ) ;
V_166 [ V_59 ] = F_141 ( F_83 , NULL ,
F_142 ( V_59 ) ,
L_8 ) ;
if ( F_143 ( V_166 [ V_59 ] ) ) {
V_167 = F_144 ( V_166 [ V_59 ] ) ;
F_84 ( L_57 ) ;
V_121 ++ ;
V_166 [ V_59 ] = NULL ;
F_7 ( & V_85 ) ;
return V_167 ;
}
F_145 ( V_166 [ V_59 ] , V_59 ) ;
F_146 ( V_166 [ V_59 ] ) ;
F_7 ( & V_85 ) ;
return 0 ;
}
static int
F_147 ( void * V_69 )
{
long V_168 ;
unsigned long V_169 ;
F_84 ( L_58 ) ;
V_169 = F_9 ( V_81 ) ;
while ( F_87 ( V_169 , V_170 ) &&
! F_88 () ) {
V_168 = V_170 - V_169 ;
if ( V_156 )
F_125 ( L_36 V_62
L_59 ,
V_61 , V_168 ) ;
F_25 ( V_168 ) ;
V_169 = F_9 ( V_81 ) ;
}
if ( F_88 () ) {
F_84 ( L_60 ) ;
return 0 ;
}
F_84 ( L_61 ) ;
V_146 = NULL ;
F_148 () ;
F_149 () ;
return 0 ;
}
static int
F_150 ( void * V_69 )
{
int V_59 ;
unsigned long V_168 ;
int V_171 = - 1 ;
F_94 ( rand ) ;
int V_172 ;
unsigned long V_173 ;
F_84 ( L_62 ) ;
F_151 (cpu)
V_171 = V_59 ;
F_152 ( V_171 < 0 ) ;
if ( V_164 > 0 ) {
F_84 ( L_63 ) ;
F_25 ( V_164 * V_34 ) ;
F_84 ( L_64 ) ;
}
while ( ! F_88 () ) {
V_59 = ( F_21 ( & rand ) >> 4 ) % ( V_171 + 1 ) ;
if ( F_153 ( V_59 ) && F_154 ( V_59 ) ) {
if ( V_156 )
F_125 ( L_36 V_62
L_65 ,
V_61 , V_59 ) ;
V_173 = V_81 ;
V_125 ++ ;
V_172 = F_155 ( V_59 ) ;
if ( V_172 ) {
if ( V_156 )
F_125 ( L_36 V_62
L_66 ,
V_61 , V_59 , V_172 ) ;
} else {
if ( V_156 )
F_125 ( L_36 V_62
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
} else if ( F_154 ( V_59 ) ) {
if ( V_156 )
F_125 ( L_36 V_62
L_68 ,
V_61 , V_59 ) ;
V_173 = V_81 ;
V_123 ++ ;
if ( F_156 ( V_59 ) == 0 ) {
if ( V_156 )
F_125 ( L_36 V_62
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
F_84 ( L_70 ) ;
return 0 ;
}
static int
F_157 ( void )
{
int V_172 ;
if ( V_163 <= 0 )
return 0 ;
V_147 = F_158 ( F_150 , NULL , L_71 ) ;
if ( F_143 ( V_147 ) ) {
V_172 = F_144 ( V_147 ) ;
V_147 = NULL ;
return V_172 ;
}
return 0 ;
}
static void F_159 ( void )
{
if ( V_147 == NULL )
return;
F_84 ( L_72 ) ;
F_139 ( V_147 ) ;
V_147 = NULL ;
}
static int
F_157 ( void )
{
return 0 ;
}
static void F_159 ( void )
{
}
static int F_160 ( void * args )
{
unsigned long V_174 ;
F_84 ( L_73 ) ;
if ( V_162 > 0 ) {
F_84 ( L_74 ) ;
F_25 ( V_162 * V_34 ) ;
F_84 ( L_75 ) ;
}
if ( ! F_88 () ) {
V_174 = F_161 () + V_161 ;
F_125 ( L_76 ) ;
F_28 () ;
F_76 () ;
while ( F_87 ( F_161 () , V_174 ) )
continue;
F_78 () ;
F_36 () ;
F_125 ( L_77 ) ;
}
F_8 ( L_78 ) ;
while ( ! F_88 () )
F_25 ( 10 * V_34 ) ;
return 0 ;
}
static int T_7 F_162 ( void )
{
int V_172 ;
if ( V_161 <= 0 )
return 0 ;
V_148 = F_158 ( F_160 , NULL , L_78 ) ;
if ( F_143 ( V_148 ) ) {
V_172 = F_144 ( V_148 ) ;
V_148 = NULL ;
return V_172 ;
}
return 0 ;
}
static void F_163 ( void )
{
if ( V_148 == NULL )
return;
F_84 ( L_79 ) ;
F_139 ( V_148 ) ;
V_148 = NULL ;
}
void F_164 ( struct V_39 * V_67 )
{
F_15 ( & V_175 ) ;
}
static int F_165 ( void * V_69 )
{
long V_176 = ( long ) V_69 ;
bool V_177 = 0 ;
struct V_39 V_67 ;
F_86 ( & V_67 ) ;
F_84 ( L_80 ) ;
F_95 ( V_77 , 19 ) ;
do {
F_166 ( V_178 [ V_176 ] ,
V_179 != V_177 ||
F_88 () ||
V_9 != V_10 ) ;
V_177 = V_179 ;
F_82 () ;
if ( F_88 () || V_9 != V_10 )
break;
V_47 -> V_180 ( & V_67 , F_164 ) ;
if ( F_167 ( & V_181 ) )
F_168 ( & V_182 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_81 ) ;
F_8 ( L_82 ) ;
while ( ! F_88 () )
F_25 ( 1 ) ;
V_47 -> V_99 () ;
F_91 ( & V_67 ) ;
return 0 ;
}
static int F_169 ( void * V_69 )
{
int V_40 ;
F_84 ( L_83 ) ;
do {
F_170 ( & V_175 , 0 ) ;
F_170 ( & V_181 , V_150 ) ;
F_82 () ;
V_179 = ! V_179 ;
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ )
F_168 ( & V_178 [ V_40 ] ) ;
F_166 ( V_182 ,
F_103 ( & V_181 ) == 0 ||
F_88 () ||
V_9 != V_10 ) ;
if ( F_88 () || V_9 != V_10 )
break;
V_133 ++ ;
V_47 -> V_99 () ;
if ( F_103 ( & V_175 ) != V_150 ) {
V_134 ++ ;
F_123 ( 1 ) ;
}
V_132 ++ ;
F_25 ( V_34 / 10 ) ;
} while ( ! F_88 () && V_9 == V_10 );
F_84 ( L_84 ) ;
F_8 ( L_85 ) ;
while ( ! F_88 () )
F_25 ( 1 ) ;
return 0 ;
}
static int F_171 ( void )
{
int V_40 ;
int V_172 ;
if ( V_150 == 0 )
return 0 ;
if ( V_47 -> V_180 == NULL || V_47 -> V_99 == NULL ) {
F_125 ( L_36 V_62
L_86 ,
V_61 , V_47 -> V_112 ) ;
F_125 ( L_36 V_62
L_87 ,
V_61 ) ;
return 0 ;
}
F_170 ( & V_181 , 0 ) ;
F_170 ( & V_175 , 0 ) ;
V_149 =
F_172 ( V_150 * sizeof( V_149 [ 0 ] ) ,
V_183 ) ;
V_178 =
F_172 ( V_150 * sizeof( V_178 [ 0 ] ) ,
V_183 ) ;
if ( V_149 == NULL || ! V_178 )
return - V_184 ;
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ ) {
F_173 ( & V_178 [ V_40 ] ) ;
V_149 [ V_40 ] = F_158 ( F_165 ,
( void * ) ( long ) V_40 ,
L_82 ) ;
if ( F_143 ( V_149 [ V_40 ] ) ) {
V_172 = F_144 ( V_149 [ V_40 ] ) ;
F_174 ( L_88 ) ;
V_149 [ V_40 ] = NULL ;
return V_172 ;
}
}
V_151 = F_158 ( F_169 , NULL ,
L_85 ) ;
if ( F_143 ( V_151 ) ) {
V_172 = F_144 ( V_151 ) ;
F_174 ( L_89 ) ;
V_151 = NULL ;
}
return 0 ;
}
static void F_175 ( void )
{
int V_40 ;
if ( V_151 != NULL ) {
F_84 ( L_90 ) ;
F_139 ( V_151 ) ;
V_151 = NULL ;
}
if ( V_149 != NULL ) {
for ( V_40 = 0 ; V_40 < V_150 ; V_40 ++ ) {
if ( V_149 [ V_40 ] != NULL ) {
F_84 ( L_91 ) ;
F_139 ( V_149 [ V_40 ] ) ;
V_149 [ V_40 ] = NULL ;
}
}
F_176 ( V_149 ) ;
V_149 = NULL ;
}
if ( V_178 != NULL ) {
F_176 ( V_178 ) ;
V_178 = NULL ;
}
}
static int F_177 ( struct V_4 * V_185 ,
unsigned long V_186 , void * V_187 )
{
long V_59 = ( long ) V_187 ;
switch ( V_186 ) {
case V_188 :
case V_189 :
( void ) F_140 ( V_59 ) ;
break;
case V_190 :
F_138 ( V_59 ) ;
break;
default:
break;
}
return V_191 ;
}
static void
F_148 ( void )
{
int V_40 ;
F_5 ( & V_8 ) ;
F_178 () ;
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
F_179 ( & V_193 ) ;
F_175 () ;
F_163 () ;
if ( V_144 ) {
F_84 ( L_92 ) ;
F_139 ( V_144 ) ;
}
V_144 = NULL ;
if ( V_194 ) {
F_84 ( L_93 ) ;
F_139 ( V_194 ) ;
F_180 ( V_139 ) ;
}
V_194 = NULL ;
if ( V_97 ) {
F_84 ( L_94 ) ;
F_139 ( V_97 ) ;
}
V_97 = NULL ;
if ( V_141 ) {
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
if ( V_141 [ V_40 ] ) {
F_84 (
L_95 ) ;
F_139 ( V_141 [ V_40 ] ) ;
}
V_141 [ V_40 ] = NULL ;
}
F_176 ( V_141 ) ;
V_141 = NULL ;
}
V_96 = NULL ;
if ( V_142 ) {
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
if ( V_142 [ V_40 ] ) {
F_84 (
L_96 ) ;
F_139 ( V_142 [ V_40 ] ) ;
}
V_142 [ V_40 ] = NULL ;
}
F_176 ( V_142 ) ;
V_142 = NULL ;
}
if ( V_143 ) {
F_84 ( L_97 ) ;
F_139 ( V_143 ) ;
}
V_143 = NULL ;
if ( V_145 ) {
F_84 ( L_98 ) ;
F_139 ( V_145 ) ;
}
V_145 = NULL ;
if ( ( V_158 == 1 && V_47 -> V_159 ) ||
V_158 == 2 ) {
F_181 ( & V_195 ) ;
F_71 (i)
F_138 ( V_40 ) ;
}
if ( V_146 != NULL ) {
F_84 ( L_99 ) ;
F_139 ( V_146 ) ;
}
V_146 = NULL ;
F_159 () ;
if ( V_47 -> V_99 != NULL )
V_47 -> V_99 () ;
F_124 () ;
if ( F_103 ( & V_135 ) || V_134 )
F_137 ( V_47 , L_100 ) ;
else if ( V_122 != V_123 ||
V_124 != V_125 )
F_137 ( V_47 ,
L_101 ) ;
else
F_137 ( V_47 , L_102 ) ;
}
static int T_7
F_182 ( void )
{
int V_40 ;
int V_59 ;
int V_196 = 0 ;
int V_167 ;
static struct V_154 * V_197 [] =
{ & V_198 , & V_199 , & V_200 ,
& V_201 , & V_202 , & V_203 ,
& V_204 , & V_205 , & V_206 ,
& V_207 , & V_208 , & V_209 , } ;
F_5 ( & V_8 ) ;
for ( V_40 = 0 ; V_40 < F_183 ( V_197 ) ; V_40 ++ ) {
V_47 = V_197 [ V_40 ] ;
if ( strcmp ( V_61 , V_47 -> V_112 ) == 0 )
break;
}
if ( V_40 == F_183 ( V_197 ) ) {
F_125 ( L_103 ,
V_61 ) ;
F_125 ( L_104 ) ;
for ( V_40 = 0 ; V_40 < F_183 ( V_197 ) ; V_40 ++ )
F_125 ( L_105 , V_197 [ V_40 ] -> V_112 ) ;
F_125 ( L_5 ) ;
F_7 ( & V_8 ) ;
return - V_210 ;
}
if ( V_47 -> V_92 == NULL && V_91 != 0 ) {
F_125 ( L_106 ) ;
V_91 = 0 ;
}
if ( V_47 -> V_211 )
V_47 -> V_211 () ;
if ( V_212 >= 0 )
V_37 = V_212 ;
else
V_37 = 2 * F_130 () ;
F_137 ( V_47 , L_107 ) ;
V_9 = V_10 ;
F_48 ( & V_19 ) ;
for ( V_40 = 0 ; V_40 < F_183 ( V_213 ) ; V_40 ++ ) {
V_213 [ V_40 ] . V_46 = 0 ;
F_20 ( & V_213 [ V_40 ] . V_23 ,
& V_19 ) ;
}
V_96 = NULL ;
V_98 = 0 ;
F_170 ( & V_21 , 0 ) ;
F_170 ( & V_20 , 0 ) ;
F_170 ( & V_24 , 0 ) ;
F_170 ( & V_109 , 0 ) ;
F_170 ( & V_135 , 0 ) ;
V_134 = 0 ;
V_121 = 0 ;
V_79 = 0 ;
V_84 = 0 ;
V_87 = 0 ;
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ )
F_170 ( & V_45 [ V_40 ] , 0 ) ;
F_71 (cpu) {
for ( V_40 = 0 ; V_40 < V_44 + 1 ; V_40 ++ ) {
F_122 ( V_113 , V_59 ) [ V_40 ] = 0 ;
F_122 ( V_114 , V_59 ) [ V_40 ] = 0 ;
}
}
F_84 ( L_108 ) ;
V_97 = F_184 ( F_93 , NULL ,
L_15 ) ;
if ( F_143 ( V_97 ) ) {
V_196 = F_144 ( V_97 ) ;
F_174 ( L_109 ) ;
V_97 = NULL ;
goto V_214;
}
F_146 ( V_97 ) ;
V_142 = F_172 ( V_100 * sizeof( V_142 [ 0 ] ) ,
V_183 ) ;
if ( V_142 == NULL ) {
F_174 ( L_110 ) ;
V_196 = - V_184 ;
goto V_214;
}
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
F_84 ( L_111 ) ;
V_142 [ V_40 ] = F_158 ( F_100 , NULL ,
L_18 ) ;
if ( F_143 ( V_142 [ V_40 ] ) ) {
V_196 = F_144 ( V_142 [ V_40 ] ) ;
F_174 ( L_112 ) ;
V_142 [ V_40 ] = NULL ;
goto V_214;
}
}
V_141 = F_172 ( V_37 * sizeof( V_141 [ 0 ] ) ,
V_183 ) ;
if ( V_141 == NULL ) {
F_174 ( L_110 ) ;
V_196 = - V_184 ;
goto V_214;
}
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
F_84 ( L_113 ) ;
V_141 [ V_40 ] = F_158 ( F_115 , NULL ,
L_21 ) ;
if ( F_143 ( V_141 [ V_40 ] ) ) {
V_196 = F_144 ( V_141 [ V_40 ] ) ;
F_174 ( L_114 ) ;
V_141 [ V_40 ] = NULL ;
goto V_214;
}
}
if ( V_138 > 0 ) {
F_84 ( L_115 ) ;
V_143 = F_158 ( F_126 , NULL ,
L_38 ) ;
if ( F_143 ( V_143 ) ) {
V_196 = F_144 ( V_143 ) ;
F_174 ( L_116 ) ;
V_143 = NULL ;
goto V_214;
}
}
if ( V_157 ) {
V_140 = F_130 () - 1 ;
if ( ! F_185 ( & V_139 , V_183 ) ) {
V_196 = - V_184 ;
F_174 ( L_117 ) ;
goto V_214;
}
V_194 = F_158 ( F_135 , NULL ,
L_41 ) ;
if ( F_143 ( V_194 ) ) {
F_180 ( V_139 ) ;
V_196 = F_144 ( V_194 ) ;
F_174 ( L_118 ) ;
V_194 = NULL ;
goto V_214;
}
}
if ( V_153 < 0 )
V_153 = 0 ;
if ( V_153 ) {
V_144 = F_158 ( F_136 , NULL ,
L_44 ) ;
if ( F_143 ( V_144 ) ) {
V_196 = F_144 ( V_144 ) ;
F_174 ( L_119 ) ;
V_144 = NULL ;
goto V_214;
}
}
if ( V_91 < 0 )
V_91 = 0 ;
if ( V_91 ) {
V_145 = F_158 ( F_92 , NULL ,
L_12 ) ;
if ( F_143 ( V_145 ) ) {
V_196 = F_144 ( V_145 ) ;
F_174 ( L_120 ) ;
V_145 = NULL ;
goto V_214;
}
}
if ( V_86 < 1 )
V_86 = 1 ;
if ( V_83 < 2 )
V_83 = 2 ;
if ( ( V_158 == 1 && V_47 -> V_159 ) ||
V_158 == 2 ) {
V_80 = V_81 + V_86 * V_34 ;
F_186 ( & V_195 ) ;
F_71 (i) {
if ( F_187 ( V_40 ) )
continue;
V_167 = F_140 ( V_40 ) ;
if ( V_167 < 0 ) {
V_196 = V_167 ;
goto V_214;
}
}
}
if ( V_160 > 0 ) {
V_170 = V_81 + V_160 * V_34 ;
V_146 = F_184 ( F_147 , NULL ,
L_121 ) ;
if ( F_143 ( V_146 ) ) {
V_196 = F_144 ( V_146 ) ;
F_174 ( L_122 ) ;
V_146 = NULL ;
goto V_214;
}
F_146 ( V_146 ) ;
}
V_40 = F_157 () ;
if ( V_40 != 0 ) {
V_196 = V_40 ;
goto V_214;
}
F_188 ( & V_193 ) ;
V_40 = F_162 () ;
if ( V_40 != 0 ) {
V_196 = V_40 ;
goto V_214;
}
V_167 = F_171 () ;
if ( V_167 != 0 ) {
V_196 = V_167 ;
goto V_214;
}
F_178 () ;
F_7 ( & V_8 ) ;
return 0 ;
V_214:
F_7 ( & V_8 ) ;
F_148 () ;
return V_196 ;
}
