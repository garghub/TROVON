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
static void F_53 ( struct V_38 * V_51 )
{
struct V_52 * V_53 ;
V_53 = F_14 ( V_51 , struct V_52 , V_51 ) ;
F_54 ( & V_53 -> V_54 ) ;
}
static void V_52 ( void )
{
struct V_52 V_53 ;
F_55 ( & V_53 . V_51 ) ;
F_56 ( & V_53 . V_54 ) ;
F_52 ( & V_53 . V_51 , F_53 ) ;
F_57 ( & V_53 . V_54 ) ;
F_58 ( & V_53 . V_51 ) ;
}
static void F_59 ( void )
{
F_60 ( & V_55 ) ;
F_43 () ;
}
static void F_61 ( void )
{
F_62 ( & V_55 ) ;
F_63 ( & V_55 ) ;
}
static int F_64 ( void ) __acquires( &srcu_ctl
static void F_65 ( struct V_24 * V_25 )
{
long V_56 ;
const long V_57 = 1000000 / V_33 ;
const long V_58 = 10 ;
V_56 = F_17 ( V_25 ) % ( V_36 * 2 * V_58 * V_57 ) ;
if ( ! V_56 )
F_21 ( V_58 ) ;
else
F_25 ( V_25 ) ;
}
static void F_66 ( int V_37 ) __releases( &srcu_ctl
static int F_67 ( void )
{
return F_68 ( & V_55 ) ;
}
static void F_69 ( void )
{
F_62 ( & V_55 ) ;
}
static int F_70 ( char * V_59 )
{
int V_60 = 0 ;
int V_61 ;
int V_37 = V_55 . V_62 & 0x1 ;
V_60 += sprintf ( & V_59 [ V_60 ] , L_3 ,
V_63 , V_64 , V_37 ) ;
F_71 (cpu) {
V_60 += sprintf ( & V_59 [ V_60 ] , L_4 , V_61 ,
F_72 ( V_55 . V_65 , V_61 ) -> V_66 [ ! V_37 ] ,
F_72 ( V_55 . V_65 , V_61 ) -> V_66 [ V_37 ] ) ;
}
V_60 += sprintf ( & V_59 [ V_60 ] , L_5 ) ;
return V_60 ;
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
static void F_77 ( int V_37 )
{
F_78 () ;
}
static void F_79 ( struct V_14 * V_16 )
{
F_80 ( & V_16 -> V_41 , F_35 ) ;
}
static void F_81 ( void )
{
F_82 () ;
}
static void F_83 ( struct V_38 * V_51 )
{
struct V_67 * V_68 =
F_14 ( V_51 , struct V_67 , V_53 ) ;
F_84 () ;
V_68 -> V_69 = 0 ;
}
static int F_85 ( void * V_70 )
{
unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
struct V_67 V_74 = { . V_69 = 0 } ;
struct V_75 V_76 ;
F_86 ( L_6 ) ;
V_76 . V_77 = 1 ;
if ( F_87 ( V_78 , V_79 , & V_76 ) < 0 ) {
F_86 ( L_7 ) ;
V_80 ++ ;
}
F_55 ( & V_74 . V_53 ) ;
do {
V_73 = V_81 ;
while ( V_82 - V_73 > V_83 / 2 ) {
F_7 ( 1 ) ;
F_20 ( L_8 ) ;
if ( F_88 () ||
V_6 != V_7 )
goto V_84;
}
V_72 = V_73 + V_85 * V_33 ;
V_71 = V_82 ;
while ( V_82 - V_72 > V_83 / 2 ) {
if ( ! V_74 . V_69 ) {
F_84 () ;
V_74 . V_69 = 1 ;
F_38 ( & V_74 . V_53 , F_83 ) ;
if ( V_82 - V_71 >
V_85 * V_33 - V_33 / 2 ) {
F_86 ( L_9 ) ;
V_86 ++ ;
}
V_71 = V_82 ;
}
F_89 () ;
F_20 ( L_8 ) ;
if ( F_88 () ||
V_6 != V_7 )
goto V_84;
}
while ( V_73 == V_81 ) {
if ( F_90 ( & V_87 ) ) {
V_81 = V_82 +
V_88 * V_33 ;
V_89 ++ ;
F_4 ( & V_87 ) ;
break;
}
F_7 ( 1 ) ;
}
V_84: F_20 ( L_8 ) ;
} while ( ! F_88 () && V_6 == V_7 );
F_86 ( L_10 ) ;
F_58 ( & V_74 . V_53 ) ;
F_5 ( L_8 ) ;
while ( ! F_88 () || V_74 . V_69 )
F_7 ( 1 ) ;
F_84 () ;
return 0 ;
}
static int
F_91 ( void * V_70 )
{
unsigned long V_90 ;
int V_91 ;
F_86 ( L_11 ) ;
do {
V_90 = V_82 + V_92 * V_33 ;
while ( V_82 - V_90 > V_93 ) {
F_21 ( 1 ) ;
}
V_91 = V_94 ;
while ( V_91 > 0 ) {
V_46 -> V_95 () ;
F_27 ( V_96 ) ;
V_91 -= V_96 ;
}
F_20 ( L_12 ) ;
} while ( ! F_88 () && V_6 == V_7 );
F_86 ( L_13 ) ;
F_5 ( L_12 ) ;
while ( ! F_88 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_92 ( void * V_70 )
{
int V_39 ;
long V_97 = F_34 () ;
struct V_14 * V_40 ;
struct V_14 * V_98 ;
static F_93 ( rand ) ;
F_86 ( L_14 ) ;
F_94 ( V_78 , 19 ) ;
do {
F_7 ( 1 ) ;
V_40 = F_8 () ;
if ( V_40 == NULL )
continue;
V_40 -> V_42 = 0 ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_98 = F_95 ( V_99 ,
V_78 == V_100 ) ;
V_40 -> V_45 = 1 ;
F_96 ( V_99 , V_40 ) ;
F_97 () ;
if ( V_98 ) {
V_39 = V_98 -> V_42 ;
if ( V_39 > V_43 )
V_39 = V_43 ;
F_11 ( & V_44 [ V_39 ] ) ;
V_98 -> V_42 ++ ;
V_46 -> V_47 ( V_98 ) ;
}
F_98 ( ++ V_101 ) ;
V_97 = V_46 -> V_62 () ;
F_20 ( L_15 ) ;
} while ( ! F_88 () && V_6 == V_7 );
F_86 ( L_16 ) ;
F_5 ( L_15 ) ;
while ( ! F_88 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_99 ( void * V_70 )
{
F_93 ( rand ) ;
F_86 ( L_17 ) ;
F_94 ( V_78 , 19 ) ;
do {
F_7 ( 1 + F_17 ( & rand ) % 10 ) ;
F_27 ( F_17 ( & rand ) & 0x3ff ) ;
V_46 -> V_49 () ;
F_20 ( L_18 ) ;
} while ( ! F_88 () && V_6 == V_7 );
F_86 ( L_19 ) ;
F_5 ( L_18 ) ;
while ( ! F_88 () )
F_7 ( 1 ) ;
return 0 ;
}
static void F_100 ( unsigned long V_102 )
{
int V_37 ;
int V_62 ;
static F_93 ( rand ) ;
static F_101 ( V_103 ) ;
struct V_14 * V_16 ;
int V_104 ;
V_37 = V_46 -> V_105 () ;
V_62 = V_46 -> V_62 () ;
V_16 = F_95 ( V_99 ,
F_102 () ||
F_103 () ||
F_104 ( & V_55 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_106 ( V_37 ) ;
return;
}
if ( V_16 -> V_45 == 0 )
F_11 ( & V_107 ) ;
F_105 ( & V_103 ) ;
V_46 -> V_108 ( & rand ) ;
V_109 ++ ;
F_106 ( & V_103 ) ;
F_76 () ;
V_104 = V_16 -> V_42 ;
if ( V_104 > V_43 ) {
V_104 = V_43 ;
}
F_107 ( V_110 [ V_104 ] ) ;
V_62 = V_46 -> V_62 () - V_62 ;
if ( V_62 > V_43 ) {
V_62 = V_43 ;
}
F_107 ( V_111 [ V_62 ] ) ;
F_78 () ;
V_46 -> V_106 ( V_37 ) ;
}
static int
F_108 ( void * V_70 )
{
int V_62 ;
int V_37 ;
F_93 ( rand ) ;
struct V_14 * V_16 ;
int V_104 ;
struct V_112 V_113 ;
F_86 ( L_20 ) ;
F_94 ( V_78 , 19 ) ;
if ( V_114 && V_46 -> V_115 )
F_109 ( & V_113 , F_100 , 0 ) ;
do {
if ( V_114 && V_46 -> V_115 ) {
if ( ! F_110 ( & V_113 ) )
F_111 ( & V_113 , V_82 + 1 ) ;
}
V_37 = V_46 -> V_105 () ;
V_62 = V_46 -> V_62 () ;
V_16 = F_95 ( V_99 ,
F_102 () ||
F_103 () ||
F_104 ( & V_55 ) ) ;
if ( V_16 == NULL ) {
V_46 -> V_106 ( V_37 ) ;
F_21 ( V_33 ) ;
continue;
}
if ( V_16 -> V_45 == 0 )
F_11 ( & V_107 ) ;
V_46 -> V_108 ( & rand ) ;
F_76 () ;
V_104 = V_16 -> V_42 ;
if ( V_104 > V_43 ) {
V_104 = V_43 ;
}
F_107 ( V_110 [ V_104 ] ) ;
V_62 = V_46 -> V_62 () - V_62 ;
if ( V_62 > V_43 ) {
V_62 = V_43 ;
}
F_107 ( V_111 [ V_62 ] ) ;
F_78 () ;
V_46 -> V_106 ( V_37 ) ;
F_112 () ;
F_20 ( L_21 ) ;
} while ( ! F_88 () && V_6 == V_7 );
F_86 ( L_22 ) ;
F_5 ( L_21 ) ;
if ( V_114 && V_46 -> V_115 )
F_113 ( & V_113 ) ;
while ( ! F_88 () )
F_7 ( 1 ) ;
return 0 ;
}
static int
F_114 ( char * V_59 )
{
int V_60 = 0 ;
int V_61 ;
int V_39 ;
long V_116 [ V_43 + 1 ] = { 0 } ;
long V_117 [ V_43 + 1 ] = { 0 } ;
F_71 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_116 [ V_39 ] += F_115 ( V_110 , V_61 ) [ V_39 ] ;
V_117 [ V_39 ] += F_115 ( V_111 , V_61 ) [ V_39 ] ;
}
}
for ( V_39 = V_43 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_116 [ V_39 ] != 0 )
break;
}
V_60 += sprintf ( & V_59 [ V_60 ] , L_23 , V_63 , V_64 ) ;
V_60 += sprintf ( & V_59 [ V_60 ] ,
L_24
L_25
L_26 ,
V_99 ,
V_101 ,
F_10 ( & V_18 ) ,
F_116 ( & V_20 ) ,
F_116 ( & V_19 ) ,
F_116 ( & V_23 ) ,
F_116 ( & V_107 ) ,
V_118 ,
V_80 ,
V_86 ,
V_89 ,
V_109 ) ;
if ( F_116 ( & V_107 ) != 0 ||
V_118 != 0 ||
V_80 != 0 ||
V_86 != 0 )
V_60 += sprintf ( & V_59 [ V_60 ] , L_27 ) ;
V_60 += sprintf ( & V_59 [ V_60 ] , L_28 , V_63 , V_64 ) ;
if ( V_39 > 1 ) {
V_60 += sprintf ( & V_59 [ V_60 ] , L_29 ) ;
F_11 ( & V_119 ) ;
F_117 ( 1 ) ;
}
V_60 += sprintf ( & V_59 [ V_60 ] , L_30 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_60 += sprintf ( & V_59 [ V_60 ] , L_31 , V_116 [ V_39 ] ) ;
V_60 += sprintf ( & V_59 [ V_60 ] , L_28 , V_63 , V_64 ) ;
V_60 += sprintf ( & V_59 [ V_60 ] , L_32 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
V_60 += sprintf ( & V_59 [ V_60 ] , L_31 , V_117 [ V_39 ] ) ;
V_60 += sprintf ( & V_59 [ V_60 ] , L_28 , V_63 , V_64 ) ;
V_60 += sprintf ( & V_59 [ V_60 ] , L_33 ) ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
V_60 += sprintf ( & V_59 [ V_60 ] , L_34 ,
F_116 ( & V_44 [ V_39 ] ) ) ;
}
V_60 += sprintf ( & V_59 [ V_60 ] , L_5 ) ;
if ( V_46 -> V_120 )
V_60 += V_46 -> V_120 ( & V_59 [ V_60 ] ) ;
return V_60 ;
}
static void
F_118 ( void )
{
int V_60 ;
V_60 = F_114 ( V_121 ) ;
F_3 ( V_122 L_35 , V_121 ) ;
}
static int
F_119 ( void * V_70 )
{
F_86 ( L_36 ) ;
do {
F_21 ( V_123 * V_33 ) ;
F_118 () ;
F_5 ( L_37 ) ;
} while ( ! F_88 () );
F_86 ( L_38 ) ;
return 0 ;
}
static void F_120 ( void )
{
int V_39 ;
F_121 ( V_124 ) ;
F_122 () ;
if ( F_123 () == 1 ) {
F_124 () ;
return;
}
if ( V_125 != - 1 )
F_125 ( V_125 , V_124 ) ;
F_126 ( V_78 , V_124 ) ;
if ( V_126 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ )
if ( V_126 [ V_39 ] )
F_126 ( V_126 [ V_39 ] ,
V_124 ) ;
}
if ( V_127 ) {
for ( V_39 = 0 ; V_39 < V_128 ; V_39 ++ )
if ( V_127 [ V_39 ] )
F_126 ( V_127 [ V_39 ] ,
V_124 ) ;
}
if ( V_100 )
F_126 ( V_100 , V_124 ) ;
if ( V_129 )
F_126 ( V_129 , V_124 ) ;
if ( V_125 == - 1 )
V_125 = F_123 () - 1 ;
else
V_125 -- ;
F_124 () ;
}
static int
F_127 ( void * V_70 )
{
F_86 ( L_39 ) ;
do {
F_21 ( V_130 * V_33 ) ;
F_120 () ;
F_5 ( L_40 ) ;
} while ( ! F_88 () );
F_86 ( L_41 ) ;
return 0 ;
}
static int
F_128 ( void * V_70 )
{
F_86 ( L_42 ) ;
do {
F_21 ( V_131 * V_33 ) ;
V_31 = 1 ;
if ( ! F_88 () )
F_21 ( V_131 * V_33 ) ;
V_31 = 0 ;
F_5 ( L_43 ) ;
} while ( ! F_88 () );
F_86 ( L_44 ) ;
return 0 ;
}
static inline void
F_129 ( struct V_132 * V_46 , char * V_133 )
{
F_3 ( V_122 L_35 V_64
L_45
L_46
L_47
L_48
L_49
L_50 ,
V_63 , V_133 , V_36 , V_128 ,
V_123 , V_134 , V_135 , V_130 ,
V_131 , V_114 , V_94 , V_96 , V_92 ,
V_136 , V_46 -> V_137 ,
V_88 , V_85 ) ;
}
static void F_130 ( int V_61 )
{
struct V_138 * V_113 ;
if ( V_139 [ V_61 ] == NULL )
return;
F_2 ( & V_87 ) ;
F_86 ( L_51 ) ;
V_113 = V_139 [ V_61 ] ;
V_139 [ V_61 ] = NULL ;
F_4 ( & V_87 ) ;
F_131 ( V_113 ) ;
}
static int F_132 ( int V_61 )
{
int V_140 ;
if ( V_139 [ V_61 ] != NULL )
return 0 ;
F_2 ( & V_87 ) ;
F_86 ( L_52 ) ;
V_139 [ V_61 ] = F_133 ( F_85 , NULL ,
L_8 ) ;
if ( F_134 ( V_139 [ V_61 ] ) ) {
V_140 = F_135 ( V_139 [ V_61 ] ) ;
F_86 ( L_53 ) ;
V_118 ++ ;
V_139 [ V_61 ] = NULL ;
F_4 ( & V_87 ) ;
return V_140 ;
}
F_136 ( V_139 [ V_61 ] , V_61 ) ;
F_137 ( V_139 [ V_61 ] ) ;
F_4 ( & V_87 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_141 ,
unsigned long V_142 , void * V_143 )
{
long V_61 = ( long ) V_143 ;
switch ( V_142 ) {
case V_144 :
case V_145 :
( void ) F_132 ( V_61 ) ;
break;
case V_146 :
F_130 ( V_61 ) ;
break;
default:
break;
}
return V_147 ;
}
static void
F_139 ( void )
{
int V_39 ;
F_2 ( & V_5 ) ;
F_140 () ;
if ( V_6 == V_8 ) {
F_3 ( V_9
L_1 ) ;
F_4 ( & V_5 ) ;
F_7 ( 10 ) ;
if ( V_46 -> V_148 != NULL )
V_46 -> V_148 () ;
return;
}
V_6 = V_149 ;
F_4 ( & V_5 ) ;
F_141 ( & V_150 ) ;
if ( V_151 ) {
F_86 ( L_54 ) ;
F_131 ( V_151 ) ;
}
V_151 = NULL ;
if ( V_152 ) {
F_86 ( L_55 ) ;
F_131 ( V_152 ) ;
F_142 ( V_124 ) ;
}
V_152 = NULL ;
if ( V_100 ) {
F_86 ( L_56 ) ;
F_131 ( V_100 ) ;
}
V_100 = NULL ;
if ( V_126 ) {
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
if ( V_126 [ V_39 ] ) {
F_86 (
L_57 ) ;
F_131 ( V_126 [ V_39 ] ) ;
}
V_126 [ V_39 ] = NULL ;
}
F_143 ( V_126 ) ;
V_126 = NULL ;
}
V_99 = NULL ;
if ( V_127 ) {
for ( V_39 = 0 ; V_39 < V_128 ; V_39 ++ ) {
if ( V_127 [ V_39 ] ) {
F_86 (
L_58 ) ;
F_131 ( V_127 [ V_39 ] ) ;
}
V_127 [ V_39 ] = NULL ;
}
F_143 ( V_127 ) ;
V_127 = NULL ;
}
if ( V_129 ) {
F_86 ( L_59 ) ;
F_131 ( V_129 ) ;
}
V_129 = NULL ;
if ( V_153 ) {
F_86 ( L_60 ) ;
F_131 ( V_153 ) ;
}
V_153 = NULL ;
if ( ( V_136 == 1 && V_46 -> V_137 ) ||
V_136 == 2 ) {
F_144 ( & V_154 ) ;
F_71 (i)
F_130 ( V_39 ) ;
}
if ( V_46 -> V_148 != NULL )
V_46 -> V_148 () ;
F_118 () ;
if ( V_46 -> V_155 )
V_46 -> V_155 () ;
if ( F_116 ( & V_119 ) )
F_129 ( V_46 , L_61 ) ;
else
F_129 ( V_46 , L_62 ) ;
}
static int T_3
F_145 ( void )
{
int V_39 ;
int V_61 ;
int V_156 = 0 ;
static struct V_132 * V_157 [] =
{ & V_158 , & V_159 , & V_160 ,
& V_161 , & V_162 ,
& V_163 , & V_164 ,
& V_165 , & V_166 , & V_167 , } ;
F_2 ( & V_5 ) ;
for ( V_39 = 0 ; V_39 < F_146 ( V_157 ) ; V_39 ++ ) {
V_46 = V_157 [ V_39 ] ;
if ( strcmp ( V_63 , V_46 -> V_168 ) == 0 )
break;
}
if ( V_39 == F_146 ( V_157 ) ) {
F_3 ( V_122 L_63 ,
V_63 ) ;
F_3 ( V_122 L_64 ) ;
for ( V_39 = 0 ; V_39 < F_146 ( V_157 ) ; V_39 ++ )
F_3 ( V_122 L_65 , V_157 [ V_39 ] -> V_168 ) ;
F_3 ( V_122 L_5 ) ;
F_4 ( & V_5 ) ;
return - V_169 ;
}
if ( V_46 -> V_95 == NULL && V_94 != 0 ) {
F_3 ( V_122 L_66
L_67 ) ;
V_94 = 0 ;
}
if ( V_46 -> V_170 )
V_46 -> V_170 () ;
if ( V_171 >= 0 )
V_36 = V_171 ;
else
V_36 = 2 * F_123 () ;
F_129 ( V_46 , L_68 ) ;
V_6 = V_7 ;
F_44 ( & V_18 ) ;
for ( V_39 = 0 ; V_39 < F_146 ( V_172 ) ; V_39 ++ ) {
V_172 [ V_39 ] . V_45 = 0 ;
F_16 ( & V_172 [ V_39 ] . V_22 ,
& V_18 ) ;
}
V_99 = NULL ;
V_101 = 0 ;
F_147 ( & V_20 , 0 ) ;
F_147 ( & V_19 , 0 ) ;
F_147 ( & V_23 , 0 ) ;
F_147 ( & V_107 , 0 ) ;
F_147 ( & V_119 , 0 ) ;
V_118 = 0 ;
V_80 = 0 ;
V_86 = 0 ;
V_89 = 0 ;
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ )
F_147 ( & V_44 [ V_39 ] , 0 ) ;
F_71 (cpu) {
for ( V_39 = 0 ; V_39 < V_43 + 1 ; V_39 ++ ) {
F_115 ( V_110 , V_61 ) [ V_39 ] = 0 ;
F_115 ( V_111 , V_61 ) [ V_39 ] = 0 ;
}
}
F_86 ( L_69 ) ;
V_100 = F_148 ( F_92 , NULL ,
L_15 ) ;
if ( F_134 ( V_100 ) ) {
V_156 = F_135 ( V_100 ) ;
F_149 ( L_70 ) ;
V_100 = NULL ;
goto V_173;
}
V_127 = F_150 ( V_128 * sizeof( V_127 [ 0 ] ) ,
V_174 ) ;
if ( V_127 == NULL ) {
F_149 ( L_71 ) ;
V_156 = - V_175 ;
goto V_173;
}
for ( V_39 = 0 ; V_39 < V_128 ; V_39 ++ ) {
F_86 ( L_72 ) ;
V_127 [ V_39 ] = F_148 ( F_99 , NULL ,
L_18 ) ;
if ( F_134 ( V_127 [ V_39 ] ) ) {
V_156 = F_135 ( V_127 [ V_39 ] ) ;
F_149 ( L_73 ) ;
V_127 [ V_39 ] = NULL ;
goto V_173;
}
}
V_126 = F_150 ( V_36 * sizeof( V_126 [ 0 ] ) ,
V_174 ) ;
if ( V_126 == NULL ) {
F_149 ( L_71 ) ;
V_156 = - V_175 ;
goto V_173;
}
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
F_86 ( L_74 ) ;
V_126 [ V_39 ] = F_148 ( F_108 , NULL ,
L_21 ) ;
if ( F_134 ( V_126 [ V_39 ] ) ) {
V_156 = F_135 ( V_126 [ V_39 ] ) ;
F_149 ( L_75 ) ;
V_126 [ V_39 ] = NULL ;
goto V_173;
}
}
if ( V_123 > 0 ) {
F_86 ( L_76 ) ;
V_129 = F_148 ( F_119 , NULL ,
L_37 ) ;
if ( F_134 ( V_129 ) ) {
V_156 = F_135 ( V_129 ) ;
F_149 ( L_77 ) ;
V_129 = NULL ;
goto V_173;
}
}
if ( V_135 ) {
V_125 = F_123 () - 1 ;
if ( ! F_151 ( & V_124 , V_174 ) ) {
V_156 = - V_175 ;
F_149 ( L_78 ) ;
goto V_173;
}
V_152 = F_148 ( F_127 , NULL ,
L_40 ) ;
if ( F_134 ( V_152 ) ) {
F_142 ( V_124 ) ;
V_156 = F_135 ( V_152 ) ;
F_149 ( L_79 ) ;
V_152 = NULL ;
goto V_173;
}
}
if ( V_131 < 0 )
V_131 = 0 ;
if ( V_131 ) {
V_151 = F_148 ( F_128 , NULL ,
L_43 ) ;
if ( F_134 ( V_151 ) ) {
V_156 = F_135 ( V_151 ) ;
F_149 ( L_80 ) ;
V_151 = NULL ;
goto V_173;
}
}
if ( V_94 < 0 )
V_94 = 0 ;
if ( V_94 ) {
V_153 = F_148 ( F_91 , NULL ,
L_12 ) ;
if ( F_134 ( V_153 ) ) {
V_156 = F_135 ( V_153 ) ;
F_149 ( L_81 ) ;
V_153 = NULL ;
goto V_173;
}
}
if ( V_88 < 1 )
V_88 = 1 ;
if ( V_85 < 2 )
V_85 = 2 ;
if ( ( V_136 == 1 && V_46 -> V_137 ) ||
V_136 == 2 ) {
int V_140 ;
V_81 = V_82 + V_88 * V_33 ;
F_152 ( & V_154 ) ;
F_71 (i) {
if ( F_153 ( V_39 ) )
continue;
V_140 = F_132 ( V_39 ) ;
if ( V_140 < 0 ) {
V_156 = V_140 ;
goto V_173;
}
}
}
F_154 ( & V_150 ) ;
F_140 () ;
F_4 ( & V_5 ) ;
return 0 ;
V_173:
F_4 ( & V_5 ) ;
F_139 () ;
return V_156 ;
}
