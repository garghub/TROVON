static const char * F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
if ( V_1 >= F_3 ( V_3 ) )
return L_1 ;
return V_3 [ V_1 ] ;
}
static T_1 T_2 F_4 ( void )
{
T_1 V_4 = F_5 () ;
unsigned long T_3 V_5 = F_6 ( V_4 , V_6 ) ;
return V_4 ;
}
static T_1 T_2 F_4 ( void )
{
return 0ULL ;
}
static struct V_7 *
F_7 ( void )
{
struct V_8 * V_9 ;
F_8 ( & V_10 ) ;
if ( F_9 ( & V_11 ) ) {
F_10 ( & V_12 ) ;
F_11 ( & V_10 ) ;
return NULL ;
}
F_10 ( & V_13 ) ;
V_9 = V_11 . V_14 ;
F_12 ( V_9 ) ;
F_11 ( & V_10 ) ;
return F_13 ( V_9 , struct V_7 , V_15 ) ;
}
static void
F_14 ( struct V_7 * V_9 )
{
F_10 ( & V_16 ) ;
F_8 ( & V_10 ) ;
F_15 ( & V_9 -> V_15 , & V_11 ) ;
F_11 ( & V_10 ) ;
}
static int F_16 ( void ) __acquires( T_4 )
{
F_17 () ;
return 0 ;
}
static void F_18 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
unsigned long V_20 ;
const unsigned long V_21 = 200 ;
const unsigned long V_22 = 50 ;
unsigned long long V_4 ;
if ( ! ( F_19 ( V_18 ) % ( V_23 * 2000 * V_22 ) ) ) {
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
F_20 ( V_22 ) ;
V_20 = V_24 -> V_20 () ;
F_21 ( V_24 -> V_25 , NULL , V_4 ,
V_19 , V_20 ) ;
}
if ( ! ( F_19 ( V_18 ) % ( V_23 * 2 * V_21 ) ) )
F_22 ( V_21 ) ;
#ifdef F_23
if ( ! F_24 () &&
! ( F_19 ( V_18 ) % ( V_23 * 20000 ) ) )
F_25 () ;
#endif
}
static void F_26 ( int V_26 ) __releases( T_4 )
{
F_27 () ;
}
static bool
F_28 ( struct V_7 * V_27 )
{
int V_1 ;
V_1 = V_27 -> V_28 ;
if ( V_1 > V_29 )
V_1 = V_29 ;
F_10 ( & V_30 [ V_1 ] ) ;
if ( ++ V_27 -> V_28 >= V_29 ) {
V_27 -> V_31 = 0 ;
return true ;
}
return false ;
}
static void
F_29 ( struct V_7 * V_32 )
{
struct V_7 * V_27 ;
struct V_7 * V_33 ;
if ( V_32 )
F_30 ( & V_32 -> V_15 , & V_34 ) ;
F_31 (rp, rp1, &rcu_torture_removed, rtort_free) {
if ( F_28 ( V_27 ) ) {
F_32 ( & V_27 -> V_15 ) ;
F_14 ( V_27 ) ;
}
}
}
static void
F_33 ( struct V_35 * V_9 )
{
struct V_7 * V_27 = F_13 ( V_9 , struct V_7 , V_36 ) ;
if ( F_34 () ) {
return;
}
if ( F_28 ( V_27 ) )
F_14 ( V_27 ) ;
else
V_24 -> V_37 ( V_27 ) ;
}
static unsigned long F_35 ( void )
{
return 0 ;
}
static void F_36 ( struct V_7 * V_9 )
{
F_37 ( & V_9 -> V_36 , F_33 ) ;
}
static void F_38 ( void )
{
F_39 ( & V_34 ) ;
}
static int F_40 ( void ) __acquires( T_5 )
{
F_41 () ;
return 0 ;
}
static void F_42 ( int V_26 ) __releases( T_5 )
{
F_43 () ;
}
static void F_44 ( struct V_7 * V_9 )
{
F_45 ( & V_9 -> V_36 , F_33 ) ;
}
static void F_46 ( struct V_7 * V_9 )
{
F_33 ( & V_9 -> V_36 ) ;
}
static void F_47 ( void )
{
}
static void
F_48 ( struct V_35 * V_38 , T_6 V_39 )
{
V_39 ( V_38 ) ;
}
static int F_49 ( void ) __acquires( T_7 )
{
return F_50 ( T_7 ) ;
}
static void F_51 ( struct V_17 * V_18 )
{
long V_40 ;
const long V_41 = 1000000 / V_42 ;
const long V_43 = 10 ;
V_40 = F_19 ( V_18 ) %
( V_23 * 2 * V_43 * V_41 ) ;
if ( ! V_40 )
F_52 ( V_43 ) ;
else
F_18 ( V_18 ) ;
}
static void F_53 ( int V_26 ) __releases( T_7 )
{
F_54 ( T_7 , V_26 ) ;
}
static unsigned long F_55 ( void )
{
return F_56 ( T_7 ) ;
}
static void F_57 ( struct V_7 * V_27 )
{
F_58 ( T_7 , & V_27 -> V_36 , F_33 ) ;
}
static void F_59 ( void )
{
F_60 ( T_7 ) ;
}
static void F_61 ( struct V_35 * V_38 ,
T_6 V_39 )
{
F_58 ( T_7 , V_38 , V_39 ) ;
}
static void F_62 ( void )
{
F_63 ( T_7 ) ;
}
static void F_64 ( void )
{
int T_3 V_44 ;
int V_26 ;
#ifdef F_65
V_26 = T_7 -> V_45 & 0x1 ;
F_66 ( L_2 ,
V_46 , V_47 , V_26 ) ;
F_67 (cpu) {
unsigned long V_48 , V_49 ;
unsigned long V_50 , V_51 ;
long V_52 , V_53 ;
struct V_54 * V_55 ;
V_55 = F_68 ( T_7 -> V_56 , V_44 ) ;
V_50 = V_55 -> V_57 [ ! V_26 ] ;
V_51 = V_55 -> V_57 [ V_26 ] ;
F_69 () ;
V_48 = V_55 -> V_58 [ ! V_26 ] ;
V_49 = V_55 -> V_58 [ V_26 ] ;
V_52 = V_48 - V_50 ;
V_53 = V_49 - V_51 ;
F_70 ( L_3 , V_44 , V_52 , V_53 ) ;
}
F_70 ( L_4 ) ;
#elif F_71 ( V_59 )
V_26 = F_2 ( T_7 -> V_45 ) & 0x1 ;
F_66 ( L_5 ,
V_46 , V_47 , V_26 ,
F_2 ( T_7 -> V_60 [ ! V_26 ] ) ,
F_2 ( T_7 -> V_60 [ V_26 ] ) ) ;
#endif
}
static void F_72 ( void )
{
F_73 ( T_7 ) ;
}
static void F_74 ( void )
{
F_38 () ;
F_75 ( F_76 ( & V_61 ) ) ;
T_7 = & V_61 ;
}
static void F_77 ( void )
{
F_78 ( & V_61 ) ;
T_7 = & V_62 ;
}
static int F_79 ( void )
{
F_80 () ;
return 0 ;
}
static void F_81 ( int V_26 )
{
F_82 () ;
}
static void F_83 ( struct V_7 * V_9 )
{
F_84 ( & V_9 -> V_36 , F_33 ) ;
}
static int F_85 ( void )
{
return 0 ;
}
static void F_86 ( int V_26 )
{
}
static void F_87 ( struct V_7 * V_9 )
{
F_88 ( & V_9 -> V_36 , F_33 ) ;
}
static bool T_3 F_89 ( void )
{
return V_24 == & V_63 ;
}
static bool T_3 F_89 ( void )
{
return false ;
}
static void F_90 ( struct V_35 * V_38 )
{
struct V_64 * V_65 =
F_13 ( V_38 , struct V_64 , V_66 ) ;
F_91 ( & V_65 -> V_67 , 0 ) ;
}
static int F_92 ( void * V_68 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
struct V_64 V_72 = { . V_67 = 0 } ;
struct V_73 V_74 ;
F_93 ( L_6 ) ;
V_74 . V_75 = 1 ;
if ( F_94 ( V_76 , V_77 , & V_74 ) < 0 ) {
F_93 ( L_7 ) ;
V_78 ++ ;
}
F_95 ( & V_72 . V_66 ) ;
do {
V_71 = V_79 ;
while ( F_96 ( V_80 , V_71 ) ) {
F_52 ( V_71 - V_80 ) ;
F_97 ( L_8 ) ;
if ( F_98 () )
goto V_81;
}
V_70 = V_71 + V_82 * V_42 ;
V_69 = V_80 ;
while ( F_96 ( V_80 , V_70 ) ) {
if ( ! F_99 ( & V_72 . V_67 ) ) {
F_91 ( & V_72 . V_67 , 1 ) ;
F_37 ( & V_72 . V_66 , F_90 ) ;
if ( V_80 - V_69 >
V_82 * V_42 - V_42 / 2 ) {
F_93 ( L_9 ) ;
V_83 ++ ;
}
V_69 = V_80 ;
}
F_97 ( L_8 ) ;
if ( F_98 () )
goto V_81;
}
while ( V_71 == V_79 &&
! F_100 () ) {
if ( F_101 ( & V_84 ) ) {
V_79 = V_80 +
V_85 * V_42 ;
V_86 ++ ;
F_102 ( & V_84 ) ;
break;
}
F_103 ( 1 ) ;
}
V_81: F_97 ( L_8 ) ;
} while ( ! F_98 () );
while ( ! F_100 () || F_99 ( & V_72 . V_67 ) ) {
F_104 ( L_8 ) ;
F_103 ( 1 ) ;
}
F_105 ( & V_72 . V_66 ) ;
F_106 ( L_8 ) ;
return 0 ;
}
static void F_107 ( struct V_35 * V_87 )
{
}
static int
F_108 ( void * V_68 )
{
int V_88 = 1 ;
int V_1 ;
int V_89 ;
struct V_35 * V_87 ;
if ( V_90 > 0 &&
V_91 > 0 &&
V_92 > 0 &&
V_24 -> V_93 &&
V_24 -> V_94 ) {
V_87 = F_109 ( sizeof( * V_87 ) *
V_95 * V_90 ) ;
V_88 = ! V_87 ;
}
if ( V_88 ) {
F_93 ( L_10 ) ;
goto V_96;
}
F_93 ( L_11 ) ;
do {
F_52 ( V_91 ) ;
F_110 ( & V_97 ) ;
F_75 ( F_111 ( V_76 ) ) ;
for ( V_1 = 0 ; V_1 < V_95 ; V_1 ++ ) {
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
V_24 -> V_93 ( & V_87 [ V_1 * V_90 + V_89 ] ,
F_107 ) ;
}
F_52 ( V_92 ) ;
F_75 ( F_111 ( V_76 ) ) ;
}
V_24 -> V_94 () ;
F_97 ( L_12 ) ;
} while ( ! F_98 () );
F_112 ( V_87 ) ;
V_96:
F_106 ( L_12 ) ;
return 0 ;
}
static int
F_113 ( void * V_68 )
{
unsigned long V_98 ;
int V_99 ;
F_93 ( L_13 ) ;
do {
V_98 = V_80 + V_100 * V_42 ;
while ( F_96 ( V_80 , V_98 ) &&
! F_100 () ) {
F_52 ( 1 ) ;
}
V_99 = V_101 ;
while ( V_99 > 0 &&
! F_100 () ) {
V_24 -> V_102 () ;
F_22 ( V_103 ) ;
V_99 -= V_103 ;
}
F_97 ( L_14 ) ;
} while ( ! F_98 () );
F_106 ( L_14 ) ;
return 0 ;
}
static int
F_114 ( void * V_68 )
{
bool V_104 = ! F_115 () && ! F_116 () ;
int V_105 = 0 ;
unsigned long V_106 ;
bool V_107 = V_108 , V_109 = V_110 , V_111 = V_112 ;
bool V_113 = V_114 ;
int V_1 ;
struct V_7 * V_27 ;
struct V_7 * V_32 ;
static F_117 ( rand ) ;
int V_115 [] = { V_116 , V_117 ,
V_118 , V_119 } ;
int V_120 = 0 ;
F_93 ( L_15 ) ;
if ( ! V_104 ) {
F_66 ( L_16 V_47
L_17 ,
V_46 , V_24 -> V_25 ) ;
F_66 ( L_16 V_47
L_18 ,
V_46 ) ;
}
if ( ! V_107 && ! V_109 && ! V_111 && ! V_113 )
V_107 = V_109 = V_111 = V_113 = true ;
if ( V_107 && V_24 -> V_121 && V_24 -> V_122 )
V_115 [ V_120 ++ ] = V_118 ;
else if ( V_108 && ( ! V_24 -> V_121 || ! V_24 -> V_122 ) )
F_66 ( L_19 ) ;
if ( V_109 && V_24 -> V_123 )
V_115 [ V_120 ++ ] = V_117 ;
else if ( V_110 && ! V_24 -> V_123 )
F_66 ( L_20 ) ;
if ( V_111 && V_24 -> V_37 )
V_115 [ V_120 ++ ] = V_116 ;
else if ( V_112 && ! V_24 -> V_37 )
F_66 ( L_21 ) ;
if ( V_113 && V_24 -> V_124 )
V_115 [ V_120 ++ ] = V_119 ;
else if ( V_114 && ! V_24 -> V_124 )
F_66 ( L_22 ) ;
if ( F_118 ( V_120 == 0 ,
L_23 ) ) {
V_2 = V_125 ;
F_106 ( L_24 ) ;
}
do {
V_2 = V_126 ;
F_103 ( 1 ) ;
V_27 = F_7 () ;
if ( V_27 == NULL )
continue;
V_27 -> V_28 = 0 ;
V_2 = V_127 ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
V_2 = V_128 ;
V_32 = F_119 ( V_129 ,
V_76 == V_130 ) ;
V_27 -> V_31 = 1 ;
F_120 ( V_129 , V_27 ) ;
F_121 () ;
if ( V_32 ) {
V_1 = V_32 -> V_28 ;
if ( V_1 > V_29 )
V_1 = V_29 ;
F_10 ( & V_30 [ V_1 ] ) ;
V_32 -> V_28 ++ ;
switch ( V_115 [ F_19 ( & rand ) % V_120 ] ) {
case V_116 :
V_2 = V_116 ;
V_24 -> V_37 ( V_32 ) ;
break;
case V_117 :
V_2 = V_117 ;
V_24 -> V_123 () ;
F_29 ( V_32 ) ;
break;
case V_118 :
V_2 = V_118 ;
V_106 = V_24 -> V_121 () ;
V_1 = F_19 ( & rand ) % 16 ;
if ( V_1 != 0 )
F_52 ( V_1 ) ;
F_22 ( F_19 ( & rand ) % 1000 ) ;
V_2 = V_131 ;
V_24 -> V_122 ( V_106 ) ;
F_29 ( V_32 ) ;
break;
case V_119 :
V_2 = V_119 ;
V_24 -> V_124 () ;
F_29 ( V_32 ) ;
break;
default:
F_122 ( 1 ) ;
break;
}
}
F_123 ( ++ V_132 ) ;
if ( V_104 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_105 - 1 ) ) ) {
F_122 ( V_105 == 0 && F_115 () ) ;
if ( V_105 >= 0 )
F_124 () ;
else
F_125 () ;
if ( ++ V_105 > 3 )
V_105 = - V_105 ;
}
V_2 = V_133 ;
F_97 ( L_24 ) ;
} while ( ! F_98 () );
if ( V_105 > 0 )
V_105 = - V_105 ;
while ( V_104 && V_105 ++ < 0 )
F_125 () ;
F_122 ( V_104 && F_115 () ) ;
V_2 = V_125 ;
F_106 ( L_24 ) ;
return 0 ;
}
static int
F_126 ( void * V_68 )
{
F_117 ( rand ) ;
F_93 ( L_25 ) ;
F_127 ( V_76 , V_134 ) ;
do {
F_103 ( 1 + F_19 ( & rand ) % 10 ) ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
if ( V_24 -> V_94 != NULL &&
F_19 ( & rand ) % ( V_135 * 8 ) == 0 ) {
V_24 -> V_94 () ;
} else if ( V_112 == V_110 ) {
if ( F_19 ( & rand ) & 0x80 )
V_24 -> V_124 () ;
else
V_24 -> V_123 () ;
} else if ( V_112 ) {
V_24 -> V_124 () ;
} else {
V_24 -> V_123 () ;
}
F_97 ( L_26 ) ;
} while ( ! F_98 () );
F_106 ( L_26 ) ;
return 0 ;
}
static void F_128 ( unsigned long V_136 )
{
int V_26 ;
unsigned long V_19 ;
unsigned long V_20 ;
static F_117 ( rand ) ;
static F_129 ( V_137 ) ;
struct V_7 * V_9 ;
int V_138 ;
unsigned long long V_4 ;
V_26 = V_24 -> V_139 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_119 ( V_129 ,
F_130 () ||
F_131 () ||
F_132 ( T_7 ) ||
F_89 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_140 ( V_26 ) ;
return;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_141 ) ;
F_133 ( & V_137 ) ;
V_24 -> V_142 ( & rand ) ;
V_143 ++ ;
F_134 ( & V_137 ) ;
F_80 () ;
V_138 = V_9 -> V_28 ;
if ( V_138 > V_29 ) {
V_138 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_138 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 , V_4 ,
V_19 , V_20 ) ;
F_135 ( V_144 ) ;
}
F_136 ( V_145 [ V_138 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_136 ( V_146 [ V_20 ] ) ;
F_82 () ;
V_24 -> V_140 ( V_26 ) ;
}
static int
F_137 ( void * V_68 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_26 ;
F_117 ( rand ) ;
struct V_7 * V_9 ;
int V_138 ;
struct V_147 V_148 ;
unsigned long long V_4 ;
F_93 ( L_27 ) ;
F_127 ( V_76 , V_134 ) ;
if ( V_149 && V_24 -> V_150 )
F_138 ( & V_148 , F_128 , 0 ) ;
do {
if ( V_149 && V_24 -> V_150 ) {
if ( ! F_139 ( & V_148 ) )
F_140 ( & V_148 , V_80 + 1 ) ;
}
V_26 = V_24 -> V_139 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_119 ( V_129 ,
F_130 () ||
F_131 () ||
F_132 ( T_7 ) ||
F_89 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_140 ( V_26 ) ;
F_52 ( V_42 ) ;
continue;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_141 ) ;
V_24 -> V_142 ( & rand ) ;
F_80 () ;
V_138 = V_9 -> V_28 ;
if ( V_138 > V_29 ) {
V_138 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_138 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 ,
V_4 , V_19 , V_20 ) ;
F_135 ( V_144 ) ;
}
F_136 ( V_145 [ V_138 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_136 ( V_146 [ V_20 ] ) ;
F_82 () ;
V_24 -> V_140 ( V_26 ) ;
F_97 ( L_28 ) ;
} while ( ! F_98 () );
if ( V_149 && V_24 -> V_150 ) {
F_141 ( & V_148 ) ;
F_142 ( & V_148 ) ;
}
F_106 ( L_28 ) ;
return 0 ;
}
static void
F_143 ( void )
{
int V_44 ;
int V_1 ;
long V_151 [ V_29 + 1 ] = { 0 } ;
long V_152 [ V_29 + 1 ] = { 0 } ;
static unsigned long V_153 = V_154 ;
struct V_155 * V_156 ;
F_67 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
V_151 [ V_1 ] += F_144 ( V_145 , V_44 ) [ V_1 ] ;
V_152 [ V_1 ] += F_144 ( V_146 , V_44 ) [ V_1 ] ;
}
}
for ( V_1 = V_29 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_151 [ V_1 ] != 0 )
break;
}
F_66 ( L_29 , V_46 , V_47 ) ;
F_70 ( L_30 ,
V_129 ,
V_132 ,
F_9 ( & V_11 ) ,
F_145 ( & V_13 ) ,
F_145 ( & V_12 ) ,
F_145 ( & V_16 ) ) ;
F_70 ( L_31 ,
F_145 ( & V_141 ) ,
V_157 ,
V_158 ,
V_78 ) ;
F_70 ( L_32 ,
V_83 ,
V_86 ,
V_143 ) ;
F_146 () ;
F_70 ( L_33 ,
V_159 ,
V_160 ,
V_157 ) ;
F_70 ( L_34 , F_147 ( & V_97 ) ) ;
F_66 ( L_29 , V_46 , V_47 ) ;
if ( F_145 ( & V_141 ) != 0 ||
V_157 != 0 ||
V_158 != 0 ||
V_78 != 0 ||
V_83 != 0 ||
V_1 > 1 ) {
F_70 ( L_16 , L_35 ) ;
F_10 ( & V_161 ) ;
F_122 ( 1 ) ;
}
F_70 ( L_36 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_70 ( L_37 , V_151 [ V_1 ] ) ;
F_70 ( L_4 ) ;
F_66 ( L_29 , V_46 , V_47 ) ;
F_70 ( L_38 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_70 ( L_37 , V_152 [ V_1 ] ) ;
F_70 ( L_4 ) ;
F_66 ( L_29 , V_46 , V_47 ) ;
F_70 ( L_39 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_70 ( L_40 , F_145 ( & V_30 [ V_1 ] ) ) ;
}
F_70 ( L_4 ) ;
if ( V_24 -> V_162 )
V_24 -> V_162 () ;
if ( V_153 == V_132 &&
V_129 != NULL ) {
int T_3 V_163 = 0 ;
unsigned long T_3 V_164 = 0 ;
unsigned long T_3 V_20 = 0 ;
F_148 ( V_24 -> V_165 ,
& V_163 , & V_164 , & V_20 ) ;
F_149 ( V_24 -> V_165 , T_7 ,
& V_163 , & V_164 , & V_20 ) ;
V_156 = F_2 ( V_130 ) ;
F_66 ( L_41 ,
F_1 () ,
V_2 ,
V_164 , V_20 , V_163 ,
V_156 == NULL ? ~ 0UL : V_156 -> V_166 ) ;
F_150 () ;
F_135 ( V_144 ) ;
}
V_153 = V_132 ;
}
static int
F_151 ( void * V_68 )
{
F_93 ( L_42 ) ;
do {
F_52 ( V_167 * V_42 ) ;
F_143 () ;
F_104 ( L_43 ) ;
} while ( ! F_98 () );
F_106 ( L_43 ) ;
return 0 ;
}
static inline void
F_152 ( struct V_168 * V_24 , const char * V_169 )
{
F_66 ( L_16 V_47
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_46 , V_169 , V_23 , V_135 ,
V_167 , V_170 , V_171 , V_172 ,
V_173 , V_149 , V_101 , V_103 , V_100 ,
V_174 , V_24 -> V_175 ,
V_85 , V_82 , V_176 ,
V_177 , V_178 ,
V_179 ,
V_180 , V_181 ) ;
}
static int F_153 ( unsigned int V_44 )
{
struct V_155 * V_148 ;
if ( V_182 [ V_44 ] == NULL )
return 0 ;
F_154 ( & V_84 ) ;
V_148 = V_182 [ V_44 ] ;
V_182 [ V_44 ] = NULL ;
F_102 ( & V_84 ) ;
F_155 ( F_92 , V_148 ) ;
return 0 ;
}
static int F_156 ( unsigned int V_44 )
{
int V_183 ;
if ( V_182 [ V_44 ] != NULL )
return 0 ;
F_154 ( & V_84 ) ;
F_93 ( L_53 ) ;
V_182 [ V_44 ] = F_157 ( F_92 , NULL ,
F_158 ( V_44 ) ,
L_8 ) ;
if ( F_159 ( V_182 [ V_44 ] ) ) {
V_183 = F_160 ( V_182 [ V_44 ] ) ;
F_93 ( L_54 ) ;
V_158 ++ ;
V_182 [ V_44 ] = NULL ;
F_102 ( & V_84 ) ;
return V_183 ;
}
F_161 ( V_182 [ V_44 ] , V_44 ) ;
F_162 ( V_182 [ V_44 ] ) ;
F_102 ( & V_84 ) ;
return 0 ;
}
static int F_163 ( void * args )
{
unsigned long V_184 ;
F_93 ( L_55 ) ;
if ( V_178 > 0 ) {
F_93 ( L_56 ) ;
F_52 ( V_178 * V_42 ) ;
F_93 ( L_57 ) ;
}
if ( ! F_100 () ) {
V_184 = F_164 () + V_177 ;
F_66 ( L_58 ) ;
F_17 () ;
F_80 () ;
while ( F_96 ( F_164 () , V_184 ) )
continue;
F_82 () ;
F_27 () ;
F_66 ( L_59 ) ;
}
F_104 ( L_60 ) ;
while ( ! F_100 () )
F_52 ( 10 * V_42 ) ;
return 0 ;
}
static int T_8 F_165 ( void )
{
if ( V_177 <= 0 )
return 0 ;
return F_166 ( F_163 , NULL , V_185 ) ;
}
static void F_167 ( struct V_35 * V_66 )
{
F_10 ( & V_186 ) ;
}
static int F_168 ( void * V_68 )
{
long V_187 = ( long ) V_68 ;
bool V_188 = 0 ;
bool V_189 ;
struct V_35 V_66 ;
F_95 ( & V_66 ) ;
F_93 ( L_61 ) ;
F_127 ( V_76 , V_134 ) ;
do {
F_169 ( V_190 [ V_187 ] ,
( V_189 =
F_99 ( & V_191 ) ) != V_188 ||
F_98 () ) ;
V_188 = V_189 ;
if ( F_98 () )
break;
F_170 () ;
V_24 -> V_93 ( & V_66 , F_167 ) ;
F_171 () ;
if ( F_172 ( & V_192 ) )
F_173 ( & V_193 ) ;
} while ( ! F_98 () );
if ( V_24 -> V_94 != NULL )
V_24 -> V_94 () ;
F_105 ( & V_66 ) ;
F_106 ( L_62 ) ;
return 0 ;
}
static int F_174 ( void * V_68 )
{
int V_1 ;
F_93 ( L_63 ) ;
do {
F_175 ( & V_186 , 0 ) ;
F_175 ( & V_192 , V_179 ) ;
F_91 ( & V_191 , ! V_191 ) ;
for ( V_1 = 0 ; V_1 < V_179 ; V_1 ++ )
F_173 ( & V_190 [ V_1 ] ) ;
F_169 ( V_193 ,
F_145 ( & V_192 ) == 0 ||
F_98 () ) ;
if ( F_98 () )
break;
V_160 ++ ;
V_24 -> V_94 () ;
if ( F_145 ( & V_186 ) != V_179 ) {
V_157 ++ ;
F_176 ( L_64 ,
F_145 ( & V_186 ) ,
V_179 ) ;
F_122 ( 1 ) ;
}
V_159 ++ ;
F_52 ( V_42 / 10 ) ;
} while ( ! F_98 () );
F_106 ( L_65 ) ;
return 0 ;
}
static int F_177 ( void )
{
int V_1 ;
int V_194 ;
if ( V_179 <= 0 )
return 0 ;
if ( V_24 -> V_93 == NULL || V_24 -> V_94 == NULL ) {
F_66 ( L_16 V_47
L_66 ,
V_46 , V_24 -> V_25 ) ;
F_66 ( L_16 V_47
L_67 ,
V_46 ) ;
return 0 ;
}
F_175 ( & V_192 , 0 ) ;
F_175 ( & V_186 , 0 ) ;
V_195 =
F_178 ( V_179 * sizeof( V_195 [ 0 ] ) ,
V_196 ) ;
V_190 =
F_178 ( V_179 * sizeof( V_190 [ 0 ] ) ,
V_196 ) ;
if ( V_195 == NULL || ! V_190 )
return - V_197 ;
for ( V_1 = 0 ; V_1 < V_179 ; V_1 ++ ) {
F_179 ( & V_190 [ V_1 ] ) ;
V_194 = F_166 ( F_168 ,
( void * ) ( long ) V_1 ,
V_195 [ V_1 ] ) ;
if ( V_194 )
return V_194 ;
}
return F_166 ( F_174 , NULL , V_198 ) ;
}
static void F_180 ( void )
{
int V_1 ;
F_155 ( F_174 , V_198 ) ;
if ( V_195 != NULL ) {
for ( V_1 = 0 ; V_1 < V_179 ; V_1 ++ )
F_155 ( F_168 ,
V_195 [ V_1 ] ) ;
F_181 ( V_195 ) ;
V_195 = NULL ;
}
if ( V_190 != NULL ) {
F_181 ( V_190 ) ;
V_190 = NULL ;
}
}
static void
F_182 ( void )
{
int V_1 ;
F_183 () ;
if ( F_184 () ) {
if ( V_24 -> V_94 != NULL )
V_24 -> V_94 () ;
return;
}
F_180 () ;
F_155 ( F_163 , V_185 ) ;
F_155 ( F_114 , V_130 ) ;
if ( V_199 ) {
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ )
F_155 ( F_137 ,
V_199 [ V_1 ] ) ;
F_181 ( V_199 ) ;
}
V_129 = NULL ;
if ( V_200 ) {
for ( V_1 = 0 ; V_1 < V_135 ; V_1 ++ ) {
F_155 ( F_126 ,
V_200 [ V_1 ] ) ;
}
F_181 ( V_200 ) ;
V_200 = NULL ;
}
F_155 ( F_151 , V_201 ) ;
F_155 ( F_113 , V_202 ) ;
for ( V_1 = 0 ; V_1 < V_203 ; V_1 ++ )
F_155 ( F_108 , V_204 [ V_1 ] ) ;
if ( ( V_174 == 1 && V_24 -> V_175 ) ||
V_174 == 2 )
F_185 ( V_205 ) ;
if ( V_24 -> V_94 != NULL )
V_24 -> V_94 () ;
if ( V_24 -> V_206 != NULL )
V_24 -> V_206 () ;
F_143 () ;
if ( F_145 ( & V_161 ) || V_157 )
F_152 ( V_24 , L_68 ) ;
else if ( F_186 () )
F_152 ( V_24 ,
L_69 ) ;
else
F_152 ( V_24 , L_70 ) ;
F_187 () ;
}
static void F_188 ( struct V_35 * V_87 )
{
}
static void F_189 ( struct V_35 * V_87 )
{
F_66 ( L_71 ) ;
}
static void F_190 ( void )
{
#ifdef F_191
struct V_35 V_207 ;
struct V_35 V_208 ;
F_95 ( & V_207 ) ;
F_95 ( & V_208 ) ;
F_66 ( L_72 ) ;
F_80 () ;
F_17 () ;
F_37 ( & V_207 , F_188 ) ;
F_170 () ;
F_37 ( & V_208 , F_188 ) ;
F_37 ( & V_208 , F_189 ) ;
F_171 () ;
F_27 () ;
F_82 () ;
F_192 () ;
F_66 ( L_73 ) ;
F_105 ( & V_207 ) ;
F_105 ( & V_208 ) ;
#else
F_66 ( L_74 ) ;
#endif
}
static int T_8
F_193 ( void )
{
int V_1 ;
int V_44 ;
int V_209 = 0 ;
static struct V_168 * V_210 [] = {
& V_211 , & V_212 , & V_213 , & V_214 , & V_215 ,
& V_216 , V_217
} ;
if ( ! F_194 ( V_46 , V_170 , & V_218 ) )
return - V_219 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_210 ) ; V_1 ++ ) {
V_24 = V_210 [ V_1 ] ;
if ( strcmp ( V_46 , V_24 -> V_25 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_210 ) ) {
F_66 ( L_75 ,
V_46 ) ;
F_66 ( L_76 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_210 ) ; V_1 ++ )
F_66 ( L_77 , V_210 [ V_1 ] -> V_25 ) ;
F_66 ( L_4 ) ;
V_209 = - V_220 ;
goto V_221;
}
if ( V_24 -> V_102 == NULL && V_101 != 0 ) {
F_66 ( L_78 ) ;
V_101 = 0 ;
}
if ( V_24 -> V_222 )
V_24 -> V_222 () ;
if ( V_223 >= 0 ) {
V_23 = V_223 ;
} else {
V_23 = F_195 () - 2 - V_223 ;
if ( V_23 <= 0 )
V_23 = 1 ;
}
F_152 ( V_24 , L_79 ) ;
F_39 ( & V_11 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_224 ) ; V_1 ++ ) {
V_224 [ V_1 ] . V_31 = 0 ;
F_15 ( & V_224 [ V_1 ] . V_15 ,
& V_11 ) ;
}
V_129 = NULL ;
V_132 = 0 ;
F_175 ( & V_13 , 0 ) ;
F_175 ( & V_12 , 0 ) ;
F_175 ( & V_16 , 0 ) ;
F_175 ( & V_141 , 0 ) ;
F_175 ( & V_161 , 0 ) ;
V_157 = 0 ;
V_158 = 0 ;
V_78 = 0 ;
V_83 = 0 ;
V_86 = 0 ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_175 ( & V_30 [ V_1 ] , 0 ) ;
F_67 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_144 ( V_145 , V_44 ) [ V_1 ] = 0 ;
F_144 ( V_146 , V_44 ) [ V_1 ] = 0 ;
}
}
V_209 = F_166 ( F_114 , NULL ,
V_130 ) ;
if ( V_209 )
goto V_221;
if ( V_135 > 0 ) {
V_200 = F_178 ( V_135 *
sizeof( V_200 [ 0 ] ) ,
V_196 ) ;
if ( V_200 == NULL ) {
F_196 ( L_80 ) ;
V_209 = - V_197 ;
goto V_221;
}
}
for ( V_1 = 0 ; V_1 < V_135 ; V_1 ++ ) {
V_209 = F_166 ( F_126 ,
NULL , V_200 [ V_1 ] ) ;
if ( V_209 )
goto V_221;
}
V_199 = F_178 ( V_23 * sizeof( V_199 [ 0 ] ) ,
V_196 ) ;
if ( V_199 == NULL ) {
F_196 ( L_80 ) ;
V_209 = - V_197 ;
goto V_221;
}
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ ) {
V_209 = F_166 ( F_137 , NULL ,
V_199 [ V_1 ] ) ;
if ( V_209 )
goto V_221;
}
if ( V_167 > 0 ) {
V_209 = F_166 ( F_151 , NULL ,
V_201 ) ;
if ( V_209 )
goto V_221;
}
if ( V_171 && V_172 > 0 ) {
V_209 = F_197 ( V_172 * V_42 ) ;
if ( V_209 )
goto V_221;
}
if ( V_173 < 0 )
V_173 = 0 ;
if ( V_173 ) {
V_209 = F_198 ( V_173 * V_42 ) ;
if ( V_209 )
goto V_221;
}
if ( V_101 < 0 )
V_101 = 0 ;
if ( V_101 ) {
V_209 = F_166 ( F_113 , NULL ,
V_202 ) ;
if ( V_209 )
goto V_221;
}
if ( V_85 < 1 )
V_85 = 1 ;
if ( V_82 < 2 )
V_82 = 2 ;
if ( ( V_174 == 1 && V_24 -> V_175 ) ||
V_174 == 2 ) {
V_79 = V_80 + V_85 * V_42 ;
V_209 = F_199 ( V_225 , L_81 ,
F_156 ,
F_153 ) ;
if ( V_209 < 0 )
goto V_221;
V_205 = V_209 ;
}
V_209 = F_200 ( V_176 , F_182 ) ;
if ( V_209 )
goto V_221;
V_209 = F_201 ( V_181 * V_42 , V_180 * V_42 ) ;
if ( V_209 )
goto V_221;
V_209 = F_165 () ;
if ( V_209 )
goto V_221;
V_209 = F_177 () ;
if ( V_209 )
goto V_221;
if ( V_226 )
F_190 () ;
if ( V_95 > 0 ) {
V_203 = ( F_195 () + 3 ) / 4 ;
V_204 = F_202 ( V_203 , sizeof( * V_204 ) ,
V_196 ) ;
if ( ! V_204 ) {
F_196 ( L_80 ) ;
V_209 = - V_197 ;
goto V_221;
}
for ( V_1 = 0 ; V_1 < V_203 ; V_1 ++ ) {
V_209 = F_166 ( F_108 ,
NULL ,
V_204 [ V_1 ] ) ;
if ( V_209 )
goto V_221;
}
}
F_183 () ;
F_203 () ;
return 0 ;
V_221:
F_203 () ;
F_182 () ;
return V_209 ;
}
