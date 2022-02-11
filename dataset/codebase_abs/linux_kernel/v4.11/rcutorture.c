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
int V_44 ;
int V_26 = T_7 -> V_20 & 0x1 ;
F_65 ( L_2 ,
V_45 , V_46 , V_26 ) ;
F_66 (cpu) {
unsigned long V_47 , V_48 ;
unsigned long V_49 , V_50 ;
long V_51 , V_52 ;
struct V_53 * V_54 = F_67 ( T_7 -> V_55 , V_44 ) ;
V_49 = V_54 -> V_56 [ ! V_26 ] ;
V_50 = V_54 -> V_56 [ V_26 ] ;
F_68 () ;
V_47 = V_54 -> V_57 [ ! V_26 ] ;
V_48 = V_54 -> V_57 [ V_26 ] ;
V_51 = V_47 - V_49 ;
V_52 = V_48 - V_50 ;
F_69 ( L_3 , V_44 , V_51 , V_52 ) ;
}
F_69 ( L_4 ) ;
}
static void F_70 ( void )
{
F_71 ( T_7 ) ;
}
static void F_72 ( void )
{
F_38 () ;
F_73 ( F_74 ( & V_58 ) ) ;
T_7 = & V_58 ;
}
static void F_75 ( void )
{
F_76 ( & V_58 ) ;
T_7 = & V_59 ;
}
static int F_77 ( void )
{
F_78 () ;
return 0 ;
}
static void F_79 ( int V_26 )
{
F_80 () ;
}
static void F_81 ( struct V_7 * V_9 )
{
F_82 ( & V_9 -> V_36 , F_33 ) ;
}
static int F_83 ( void )
{
return 0 ;
}
static void F_84 ( int V_26 )
{
}
static void F_85 ( struct V_7 * V_9 )
{
F_86 ( & V_9 -> V_36 , F_33 ) ;
}
static bool T_3 F_87 ( void )
{
return V_24 == & V_60 ;
}
static bool T_3 F_87 ( void )
{
return false ;
}
static void F_88 ( struct V_35 * V_38 )
{
struct V_61 * V_62 =
F_13 ( V_38 , struct V_61 , V_63 ) ;
F_89 ( & V_62 -> V_64 , 0 ) ;
}
static int F_90 ( void * V_65 )
{
unsigned long V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
struct V_61 V_69 = { . V_64 = 0 } ;
struct V_70 V_71 ;
F_91 ( L_5 ) ;
V_71 . V_72 = 1 ;
if ( F_92 ( V_73 , V_74 , & V_71 ) < 0 ) {
F_91 ( L_6 ) ;
V_75 ++ ;
}
F_93 ( & V_69 . V_63 ) ;
do {
V_68 = V_76 ;
while ( F_94 ( V_77 , V_68 ) ) {
F_52 ( V_68 - V_77 ) ;
F_95 ( L_7 ) ;
if ( F_96 () )
goto V_78;
}
V_67 = V_68 + V_79 * V_42 ;
V_66 = V_77 ;
while ( F_94 ( V_77 , V_67 ) ) {
if ( ! F_97 ( & V_69 . V_64 ) ) {
F_89 ( & V_69 . V_64 , 1 ) ;
F_37 ( & V_69 . V_63 , F_88 ) ;
if ( V_77 - V_66 >
V_79 * V_42 - V_42 / 2 ) {
F_91 ( L_8 ) ;
V_80 ++ ;
}
V_66 = V_77 ;
}
F_95 ( L_7 ) ;
if ( F_96 () )
goto V_78;
}
while ( V_68 == V_76 &&
! F_98 () ) {
if ( F_99 ( & V_81 ) ) {
V_76 = V_77 +
V_82 * V_42 ;
V_83 ++ ;
F_100 ( & V_81 ) ;
break;
}
F_101 ( 1 ) ;
}
V_78: F_95 ( L_7 ) ;
} while ( ! F_96 () );
while ( ! F_98 () || F_97 ( & V_69 . V_64 ) ) {
F_102 ( L_7 ) ;
F_101 ( 1 ) ;
}
F_103 ( & V_69 . V_63 ) ;
F_104 ( L_7 ) ;
return 0 ;
}
static void F_105 ( struct V_35 * V_84 )
{
}
static int
F_106 ( void * V_65 )
{
int V_85 = 1 ;
int V_1 ;
int V_86 ;
struct V_35 * V_84 ;
if ( V_87 > 0 &&
V_88 > 0 &&
V_89 > 0 &&
V_24 -> V_90 &&
V_24 -> V_91 ) {
V_84 = F_107 ( sizeof( * V_84 ) *
V_92 * V_87 ) ;
V_85 = ! V_84 ;
}
if ( V_85 ) {
F_91 ( L_9 ) ;
goto V_93;
}
F_91 ( L_10 ) ;
do {
F_52 ( V_88 ) ;
F_108 ( & V_94 ) ;
F_73 ( F_109 ( V_73 ) ) ;
for ( V_1 = 0 ; V_1 < V_92 ; V_1 ++ ) {
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
V_24 -> V_90 ( & V_84 [ V_1 * V_87 + V_86 ] ,
F_105 ) ;
}
F_52 ( V_89 ) ;
F_73 ( F_109 ( V_73 ) ) ;
}
V_24 -> V_91 () ;
F_95 ( L_11 ) ;
} while ( ! F_96 () );
F_110 ( V_84 ) ;
V_93:
F_104 ( L_11 ) ;
return 0 ;
}
static int
F_111 ( void * V_65 )
{
unsigned long V_95 ;
int V_96 ;
F_91 ( L_12 ) ;
do {
V_95 = V_77 + V_97 * V_42 ;
while ( F_94 ( V_77 , V_95 ) &&
! F_98 () ) {
F_52 ( 1 ) ;
}
V_96 = V_98 ;
while ( V_96 > 0 &&
! F_98 () ) {
V_24 -> V_99 () ;
F_22 ( V_100 ) ;
V_96 -= V_100 ;
}
F_95 ( L_13 ) ;
} while ( ! F_96 () );
F_104 ( L_13 ) ;
return 0 ;
}
static int
F_112 ( void * V_65 )
{
bool V_101 = ! F_113 () && ! F_114 () ;
int V_102 = 0 ;
unsigned long V_103 ;
bool V_104 = V_105 , V_106 = V_107 , V_108 = V_109 ;
bool V_110 = V_111 ;
int V_1 ;
struct V_7 * V_27 ;
struct V_7 * V_32 ;
static F_115 ( rand ) ;
int V_112 [] = { V_113 , V_114 ,
V_115 , V_116 } ;
int V_117 = 0 ;
F_91 ( L_14 ) ;
if ( ! V_101 ) {
F_65 ( L_15 V_46
L_16 ,
V_45 , V_24 -> V_25 ) ;
F_65 ( L_15 V_46
L_17 ,
V_45 ) ;
}
if ( ! V_104 && ! V_106 && ! V_108 && ! V_110 )
V_104 = V_106 = V_108 = V_110 = true ;
if ( V_104 && V_24 -> V_118 && V_24 -> V_119 )
V_112 [ V_117 ++ ] = V_115 ;
else if ( V_105 && ( ! V_24 -> V_118 || ! V_24 -> V_119 ) )
F_65 ( L_18 ) ;
if ( V_106 && V_24 -> V_120 )
V_112 [ V_117 ++ ] = V_114 ;
else if ( V_107 && ! V_24 -> V_120 )
F_65 ( L_19 ) ;
if ( V_108 && V_24 -> V_37 )
V_112 [ V_117 ++ ] = V_113 ;
else if ( V_109 && ! V_24 -> V_37 )
F_65 ( L_20 ) ;
if ( V_110 && V_24 -> V_121 )
V_112 [ V_117 ++ ] = V_116 ;
else if ( V_111 && ! V_24 -> V_121 )
F_65 ( L_21 ) ;
if ( F_116 ( V_117 == 0 ,
L_22 ) ) {
V_2 = V_122 ;
F_104 ( L_23 ) ;
}
do {
V_2 = V_123 ;
F_101 ( 1 ) ;
V_27 = F_7 () ;
if ( V_27 == NULL )
continue;
V_27 -> V_28 = 0 ;
V_2 = V_124 ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
V_2 = V_125 ;
V_32 = F_117 ( V_126 ,
V_73 == V_127 ) ;
V_27 -> V_31 = 1 ;
F_118 ( V_126 , V_27 ) ;
F_119 () ;
if ( V_32 ) {
V_1 = V_32 -> V_28 ;
if ( V_1 > V_29 )
V_1 = V_29 ;
F_10 ( & V_30 [ V_1 ] ) ;
V_32 -> V_28 ++ ;
switch ( V_112 [ F_19 ( & rand ) % V_117 ] ) {
case V_113 :
V_2 = V_113 ;
V_24 -> V_37 ( V_32 ) ;
break;
case V_114 :
V_2 = V_114 ;
V_24 -> V_120 () ;
F_29 ( V_32 ) ;
break;
case V_115 :
V_2 = V_115 ;
V_103 = V_24 -> V_118 () ;
V_1 = F_19 ( & rand ) % 16 ;
if ( V_1 != 0 )
F_52 ( V_1 ) ;
F_22 ( F_19 ( & rand ) % 1000 ) ;
V_2 = V_128 ;
V_24 -> V_119 ( V_103 ) ;
F_29 ( V_32 ) ;
break;
case V_116 :
V_2 = V_116 ;
V_24 -> V_121 () ;
F_29 ( V_32 ) ;
break;
default:
F_120 ( 1 ) ;
break;
}
}
F_121 ( ++ V_129 ) ;
if ( V_101 &&
! ( F_19 ( & rand ) & 0xff & ( ! ! V_102 - 1 ) ) ) {
F_120 ( V_102 == 0 && F_113 () ) ;
if ( V_102 >= 0 )
F_122 () ;
else
F_123 () ;
if ( ++ V_102 > 3 )
V_102 = - V_102 ;
}
V_2 = V_130 ;
F_95 ( L_23 ) ;
} while ( ! F_96 () );
if ( V_102 > 0 )
V_102 = - V_102 ;
while ( V_101 && V_102 ++ < 0 )
F_123 () ;
F_120 ( V_101 && F_113 () ) ;
V_2 = V_122 ;
F_104 ( L_23 ) ;
return 0 ;
}
static int
F_124 ( void * V_65 )
{
F_115 ( rand ) ;
F_91 ( L_24 ) ;
F_125 ( V_73 , V_131 ) ;
do {
F_101 ( 1 + F_19 ( & rand ) % 10 ) ;
F_22 ( F_19 ( & rand ) & 0x3ff ) ;
if ( V_24 -> V_91 != NULL &&
F_19 ( & rand ) % ( V_132 * 8 ) == 0 ) {
V_24 -> V_91 () ;
} else if ( V_109 == V_107 ) {
if ( F_19 ( & rand ) & 0x80 )
V_24 -> V_121 () ;
else
V_24 -> V_120 () ;
} else if ( V_109 ) {
V_24 -> V_121 () ;
} else {
V_24 -> V_120 () ;
}
F_95 ( L_25 ) ;
} while ( ! F_96 () );
F_104 ( L_25 ) ;
return 0 ;
}
static void F_126 ( unsigned long V_133 )
{
int V_26 ;
unsigned long V_19 ;
unsigned long V_20 ;
static F_115 ( rand ) ;
static F_127 ( V_134 ) ;
struct V_7 * V_9 ;
int V_135 ;
unsigned long long V_4 ;
V_26 = V_24 -> V_136 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_117 ( V_126 ,
F_128 () ||
F_129 () ||
F_130 ( T_7 ) ||
F_87 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_137 ( V_26 ) ;
return;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_138 ) ;
F_131 ( & V_134 ) ;
V_24 -> V_139 ( & rand ) ;
V_140 ++ ;
F_132 ( & V_134 ) ;
F_78 () ;
V_135 = V_9 -> V_28 ;
if ( V_135 > V_29 ) {
V_135 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_135 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 , V_4 ,
V_19 , V_20 ) ;
F_133 ( V_141 ) ;
}
F_134 ( V_142 [ V_135 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_134 ( V_143 [ V_20 ] ) ;
F_80 () ;
V_24 -> V_137 ( V_26 ) ;
}
static int
F_135 ( void * V_65 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_26 ;
F_115 ( rand ) ;
struct V_7 * V_9 ;
int V_135 ;
struct V_144 V_145 ;
unsigned long long V_4 ;
F_91 ( L_26 ) ;
F_125 ( V_73 , V_131 ) ;
if ( V_146 && V_24 -> V_147 )
F_136 ( & V_145 , F_126 , 0 ) ;
do {
if ( V_146 && V_24 -> V_147 ) {
if ( ! F_137 ( & V_145 ) )
F_138 ( & V_145 , V_77 + 1 ) ;
}
V_26 = V_24 -> V_136 () ;
if ( V_24 -> V_19 )
V_19 = V_24 -> V_19 () ;
else
V_19 = V_24 -> V_20 () ;
V_4 = F_4 () ;
V_9 = F_117 ( V_126 ,
F_128 () ||
F_129 () ||
F_130 ( T_7 ) ||
F_87 () ) ;
if ( V_9 == NULL ) {
V_24 -> V_137 ( V_26 ) ;
F_52 ( V_42 ) ;
continue;
}
if ( V_9 -> V_31 == 0 )
F_10 ( & V_138 ) ;
V_24 -> V_139 ( & rand ) ;
F_78 () ;
V_135 = V_9 -> V_28 ;
if ( V_135 > V_29 ) {
V_135 = V_29 ;
}
V_20 = V_24 -> V_20 () ;
if ( V_135 > 1 ) {
F_21 ( V_24 -> V_25 , & V_9 -> V_36 ,
V_4 , V_19 , V_20 ) ;
F_133 ( V_141 ) ;
}
F_134 ( V_142 [ V_135 ] ) ;
V_20 = V_20 - V_19 ;
if ( V_24 -> V_19 )
V_20 ++ ;
if ( V_20 > V_29 ) {
V_20 = V_29 ;
}
F_134 ( V_143 [ V_20 ] ) ;
F_80 () ;
V_24 -> V_137 ( V_26 ) ;
F_95 ( L_27 ) ;
} while ( ! F_96 () );
if ( V_146 && V_24 -> V_147 ) {
F_139 ( & V_145 ) ;
F_140 ( & V_145 ) ;
}
F_104 ( L_27 ) ;
return 0 ;
}
static void
F_141 ( void )
{
int V_44 ;
int V_1 ;
long V_148 [ V_29 + 1 ] = { 0 } ;
long V_149 [ V_29 + 1 ] = { 0 } ;
static unsigned long V_150 = V_151 ;
struct V_152 * V_153 ;
F_66 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
V_148 [ V_1 ] += F_142 ( V_142 , V_44 ) [ V_1 ] ;
V_149 [ V_1 ] += F_142 ( V_143 , V_44 ) [ V_1 ] ;
}
}
for ( V_1 = V_29 - 1 ; V_1 >= 0 ; V_1 -- ) {
if ( V_148 [ V_1 ] != 0 )
break;
}
F_65 ( L_28 , V_45 , V_46 ) ;
F_69 ( L_29 ,
V_126 ,
V_129 ,
F_9 ( & V_11 ) ,
F_143 ( & V_13 ) ,
F_143 ( & V_12 ) ,
F_143 ( & V_16 ) ) ;
F_69 ( L_30 ,
F_143 ( & V_138 ) ,
V_154 ,
V_155 ,
V_75 ) ;
F_69 ( L_31 ,
V_80 ,
V_83 ,
V_140 ) ;
F_144 () ;
F_69 ( L_32 ,
V_156 ,
V_157 ,
V_154 ) ;
F_69 ( L_33 , F_145 ( & V_94 ) ) ;
F_65 ( L_28 , V_45 , V_46 ) ;
if ( F_143 ( & V_138 ) != 0 ||
V_154 != 0 ||
V_155 != 0 ||
V_75 != 0 ||
V_80 != 0 ||
V_1 > 1 ) {
F_69 ( L_15 , L_34 ) ;
F_10 ( & V_158 ) ;
F_120 ( 1 ) ;
}
F_69 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_69 ( L_36 , V_148 [ V_1 ] ) ;
F_69 ( L_4 ) ;
F_65 ( L_28 , V_45 , V_46 ) ;
F_69 ( L_37 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_69 ( L_36 , V_149 [ V_1 ] ) ;
F_69 ( L_4 ) ;
F_65 ( L_28 , V_45 , V_46 ) ;
F_69 ( L_38 ) ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_69 ( L_39 , F_143 ( & V_30 [ V_1 ] ) ) ;
}
F_69 ( L_4 ) ;
if ( V_24 -> V_159 )
V_24 -> V_159 () ;
if ( V_150 == V_129 &&
V_126 != NULL ) {
int T_3 V_160 ;
unsigned long T_3 V_161 ;
unsigned long T_3 V_20 ;
F_146 ( V_24 -> V_162 ,
& V_160 , & V_161 , & V_20 ) ;
V_153 = F_2 ( V_127 ) ;
F_65 ( L_40 ,
F_1 () ,
V_2 ,
V_161 , V_20 , V_160 ,
V_153 == NULL ? ~ 0UL : V_153 -> V_163 ) ;
F_147 () ;
F_133 ( V_141 ) ;
}
V_150 = V_129 ;
}
static int
F_148 ( void * V_65 )
{
F_91 ( L_41 ) ;
do {
F_52 ( V_164 * V_42 ) ;
F_141 () ;
F_102 ( L_42 ) ;
} while ( ! F_96 () );
F_104 ( L_42 ) ;
return 0 ;
}
static inline void
F_149 ( struct V_165 * V_24 , const char * V_166 )
{
F_65 ( L_15 V_46
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51 ,
V_45 , V_166 , V_23 , V_132 ,
V_164 , V_167 , V_168 , V_169 ,
V_170 , V_146 , V_98 , V_100 , V_97 ,
V_171 , V_24 -> V_172 ,
V_82 , V_79 , V_173 ,
V_174 , V_175 ,
V_176 ,
V_177 , V_178 ) ;
}
static int F_150 ( unsigned int V_44 )
{
struct V_152 * V_145 ;
if ( V_179 [ V_44 ] == NULL )
return 0 ;
F_151 ( & V_81 ) ;
V_145 = V_179 [ V_44 ] ;
V_179 [ V_44 ] = NULL ;
F_100 ( & V_81 ) ;
F_152 ( F_90 , V_145 ) ;
return 0 ;
}
static int F_153 ( unsigned int V_44 )
{
int V_180 ;
if ( V_179 [ V_44 ] != NULL )
return 0 ;
F_151 ( & V_81 ) ;
F_91 ( L_52 ) ;
V_179 [ V_44 ] = F_154 ( F_90 , NULL ,
F_155 ( V_44 ) ,
L_7 ) ;
if ( F_156 ( V_179 [ V_44 ] ) ) {
V_180 = F_157 ( V_179 [ V_44 ] ) ;
F_91 ( L_53 ) ;
V_155 ++ ;
V_179 [ V_44 ] = NULL ;
F_100 ( & V_81 ) ;
return V_180 ;
}
F_158 ( V_179 [ V_44 ] , V_44 ) ;
F_159 ( V_179 [ V_44 ] ) ;
F_100 ( & V_81 ) ;
return 0 ;
}
static int F_160 ( void * args )
{
unsigned long V_181 ;
F_91 ( L_54 ) ;
if ( V_175 > 0 ) {
F_91 ( L_55 ) ;
F_52 ( V_175 * V_42 ) ;
F_91 ( L_56 ) ;
}
if ( ! F_98 () ) {
V_181 = F_161 () + V_174 ;
F_65 ( L_57 ) ;
F_17 () ;
F_78 () ;
while ( F_94 ( F_161 () , V_181 ) )
continue;
F_80 () ;
F_27 () ;
F_65 ( L_58 ) ;
}
F_102 ( L_59 ) ;
while ( ! F_98 () )
F_52 ( 10 * V_42 ) ;
return 0 ;
}
static int T_8 F_162 ( void )
{
if ( V_174 <= 0 )
return 0 ;
return F_163 ( F_160 , NULL , V_182 ) ;
}
static void F_164 ( struct V_35 * V_63 )
{
F_10 ( & V_183 ) ;
}
static int F_165 ( void * V_65 )
{
long V_184 = ( long ) V_65 ;
bool V_185 = 0 ;
bool V_186 ;
struct V_35 V_63 ;
F_93 ( & V_63 ) ;
F_91 ( L_60 ) ;
F_125 ( V_73 , V_131 ) ;
do {
F_166 ( V_187 [ V_184 ] ,
( V_186 =
F_97 ( & V_188 ) ) != V_185 ||
F_96 () ) ;
V_185 = V_186 ;
if ( F_96 () )
break;
F_167 () ;
V_24 -> V_90 ( & V_63 , F_164 ) ;
F_168 () ;
if ( F_169 ( & V_189 ) )
F_170 ( & V_190 ) ;
} while ( ! F_96 () );
if ( V_24 -> V_91 != NULL )
V_24 -> V_91 () ;
F_103 ( & V_63 ) ;
F_104 ( L_61 ) ;
return 0 ;
}
static int F_171 ( void * V_65 )
{
int V_1 ;
F_91 ( L_62 ) ;
do {
F_172 ( & V_183 , 0 ) ;
F_172 ( & V_189 , V_176 ) ;
F_89 ( & V_188 , ! V_188 ) ;
for ( V_1 = 0 ; V_1 < V_176 ; V_1 ++ )
F_170 ( & V_187 [ V_1 ] ) ;
F_166 ( V_190 ,
F_143 ( & V_189 ) == 0 ||
F_96 () ) ;
if ( F_96 () )
break;
V_157 ++ ;
V_24 -> V_91 () ;
if ( F_143 ( & V_183 ) != V_176 ) {
V_154 ++ ;
F_173 ( L_63 ,
F_143 ( & V_183 ) ,
V_176 ) ;
F_120 ( 1 ) ;
}
V_156 ++ ;
F_52 ( V_42 / 10 ) ;
} while ( ! F_96 () );
F_104 ( L_64 ) ;
return 0 ;
}
static int F_174 ( void )
{
int V_1 ;
int V_191 ;
if ( V_176 <= 0 )
return 0 ;
if ( V_24 -> V_90 == NULL || V_24 -> V_91 == NULL ) {
F_65 ( L_15 V_46
L_65 ,
V_45 , V_24 -> V_25 ) ;
F_65 ( L_15 V_46
L_66 ,
V_45 ) ;
return 0 ;
}
F_172 ( & V_189 , 0 ) ;
F_172 ( & V_183 , 0 ) ;
V_192 =
F_175 ( V_176 * sizeof( V_192 [ 0 ] ) ,
V_193 ) ;
V_187 =
F_175 ( V_176 * sizeof( V_187 [ 0 ] ) ,
V_193 ) ;
if ( V_192 == NULL || ! V_187 )
return - V_194 ;
for ( V_1 = 0 ; V_1 < V_176 ; V_1 ++ ) {
F_176 ( & V_187 [ V_1 ] ) ;
V_191 = F_163 ( F_165 ,
( void * ) ( long ) V_1 ,
V_192 [ V_1 ] ) ;
if ( V_191 )
return V_191 ;
}
return F_163 ( F_171 , NULL , V_195 ) ;
}
static void F_177 ( void )
{
int V_1 ;
F_152 ( F_171 , V_195 ) ;
if ( V_192 != NULL ) {
for ( V_1 = 0 ; V_1 < V_176 ; V_1 ++ )
F_152 ( F_165 ,
V_192 [ V_1 ] ) ;
F_178 ( V_192 ) ;
V_192 = NULL ;
}
if ( V_187 != NULL ) {
F_178 ( V_187 ) ;
V_187 = NULL ;
}
}
static void
F_179 ( void )
{
int V_1 ;
F_180 () ;
if ( F_181 () ) {
if ( V_24 -> V_91 != NULL )
V_24 -> V_91 () ;
return;
}
F_177 () ;
F_152 ( F_160 , V_182 ) ;
F_152 ( F_112 , V_127 ) ;
if ( V_196 ) {
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ )
F_152 ( F_135 ,
V_196 [ V_1 ] ) ;
F_178 ( V_196 ) ;
}
V_126 = NULL ;
if ( V_197 ) {
for ( V_1 = 0 ; V_1 < V_132 ; V_1 ++ ) {
F_152 ( F_124 ,
V_197 [ V_1 ] ) ;
}
F_178 ( V_197 ) ;
V_197 = NULL ;
}
F_152 ( F_148 , V_198 ) ;
F_152 ( F_111 , V_199 ) ;
for ( V_1 = 0 ; V_1 < V_200 ; V_1 ++ )
F_152 ( F_106 , V_201 [ V_1 ] ) ;
if ( ( V_171 == 1 && V_24 -> V_172 ) ||
V_171 == 2 )
F_182 ( V_202 ) ;
if ( V_24 -> V_91 != NULL )
V_24 -> V_91 () ;
if ( V_24 -> V_203 != NULL )
V_24 -> V_203 () ;
F_141 () ;
if ( F_143 ( & V_158 ) || V_154 )
F_149 ( V_24 , L_67 ) ;
else if ( F_183 () )
F_149 ( V_24 ,
L_68 ) ;
else
F_149 ( V_24 , L_69 ) ;
F_184 () ;
}
static void F_185 ( struct V_35 * V_84 )
{
}
static void F_186 ( struct V_35 * V_84 )
{
F_65 ( L_70 ) ;
}
static void F_187 ( void )
{
#ifdef F_188
struct V_35 V_204 ;
struct V_35 V_205 ;
F_93 ( & V_204 ) ;
F_93 ( & V_205 ) ;
F_65 ( L_71 ) ;
F_78 () ;
F_17 () ;
F_37 ( & V_204 , F_185 ) ;
F_167 () ;
F_37 ( & V_205 , F_185 ) ;
F_37 ( & V_205 , F_186 ) ;
F_168 () ;
F_27 () ;
F_80 () ;
F_189 () ;
F_65 ( L_72 ) ;
F_103 ( & V_204 ) ;
F_103 ( & V_205 ) ;
#else
F_65 ( L_73 ) ;
#endif
}
static int T_8
F_190 ( void )
{
int V_1 ;
int V_44 ;
int V_206 = 0 ;
static struct V_165 * V_207 [] = {
& V_208 , & V_209 , & V_210 , & V_211 , & V_212 ,
& V_213 , V_214
} ;
if ( ! F_191 ( V_45 , V_167 , & V_215 ) )
return - V_216 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_207 ) ; V_1 ++ ) {
V_24 = V_207 [ V_1 ] ;
if ( strcmp ( V_45 , V_24 -> V_25 ) == 0 )
break;
}
if ( V_1 == F_3 ( V_207 ) ) {
F_65 ( L_74 ,
V_45 ) ;
F_65 ( L_75 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_207 ) ; V_1 ++ )
F_65 ( L_76 , V_207 [ V_1 ] -> V_25 ) ;
F_65 ( L_4 ) ;
V_206 = - V_217 ;
goto V_218;
}
if ( V_24 -> V_99 == NULL && V_98 != 0 ) {
F_65 ( L_77 ) ;
V_98 = 0 ;
}
if ( V_24 -> V_219 )
V_24 -> V_219 () ;
if ( V_220 >= 0 ) {
V_23 = V_220 ;
} else {
V_23 = F_192 () - 2 - V_220 ;
if ( V_23 <= 0 )
V_23 = 1 ;
}
F_149 ( V_24 , L_78 ) ;
F_39 ( & V_11 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_221 ) ; V_1 ++ ) {
V_221 [ V_1 ] . V_31 = 0 ;
F_15 ( & V_221 [ V_1 ] . V_15 ,
& V_11 ) ;
}
V_126 = NULL ;
V_129 = 0 ;
F_172 ( & V_13 , 0 ) ;
F_172 ( & V_12 , 0 ) ;
F_172 ( & V_16 , 0 ) ;
F_172 ( & V_138 , 0 ) ;
F_172 ( & V_158 , 0 ) ;
V_154 = 0 ;
V_155 = 0 ;
V_75 = 0 ;
V_80 = 0 ;
V_83 = 0 ;
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ )
F_172 ( & V_30 [ V_1 ] , 0 ) ;
F_66 (cpu) {
for ( V_1 = 0 ; V_1 < V_29 + 1 ; V_1 ++ ) {
F_142 ( V_142 , V_44 ) [ V_1 ] = 0 ;
F_142 ( V_143 , V_44 ) [ V_1 ] = 0 ;
}
}
V_206 = F_163 ( F_112 , NULL ,
V_127 ) ;
if ( V_206 )
goto V_218;
if ( V_132 > 0 ) {
V_197 = F_175 ( V_132 *
sizeof( V_197 [ 0 ] ) ,
V_193 ) ;
if ( V_197 == NULL ) {
F_193 ( L_79 ) ;
V_206 = - V_194 ;
goto V_218;
}
}
for ( V_1 = 0 ; V_1 < V_132 ; V_1 ++ ) {
V_206 = F_163 ( F_124 ,
NULL , V_197 [ V_1 ] ) ;
if ( V_206 )
goto V_218;
}
V_196 = F_175 ( V_23 * sizeof( V_196 [ 0 ] ) ,
V_193 ) ;
if ( V_196 == NULL ) {
F_193 ( L_79 ) ;
V_206 = - V_194 ;
goto V_218;
}
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ ) {
V_206 = F_163 ( F_135 , NULL ,
V_196 [ V_1 ] ) ;
if ( V_206 )
goto V_218;
}
if ( V_164 > 0 ) {
V_206 = F_163 ( F_148 , NULL ,
V_198 ) ;
if ( V_206 )
goto V_218;
}
if ( V_168 && V_169 > 0 ) {
V_206 = F_194 ( V_169 * V_42 ) ;
if ( V_206 )
goto V_218;
}
if ( V_170 < 0 )
V_170 = 0 ;
if ( V_170 ) {
V_206 = F_195 ( V_170 * V_42 ) ;
if ( V_206 )
goto V_218;
}
if ( V_98 < 0 )
V_98 = 0 ;
if ( V_98 ) {
V_206 = F_163 ( F_111 , NULL ,
V_199 ) ;
if ( V_206 )
goto V_218;
}
if ( V_82 < 1 )
V_82 = 1 ;
if ( V_79 < 2 )
V_79 = 2 ;
if ( ( V_171 == 1 && V_24 -> V_172 ) ||
V_171 == 2 ) {
V_76 = V_77 + V_82 * V_42 ;
V_206 = F_196 ( V_222 , L_80 ,
F_153 ,
F_150 ) ;
if ( V_206 < 0 )
goto V_218;
V_202 = V_206 ;
}
V_206 = F_197 ( V_173 , F_179 ) ;
if ( V_206 )
goto V_218;
V_206 = F_198 ( V_178 * V_42 , V_177 * V_42 ) ;
if ( V_206 )
goto V_218;
V_206 = F_162 () ;
if ( V_206 )
goto V_218;
V_206 = F_174 () ;
if ( V_206 )
goto V_218;
if ( V_223 )
F_187 () ;
if ( V_92 > 0 ) {
V_200 = ( F_192 () + 3 ) / 4 ;
V_201 = F_199 ( V_200 , sizeof( * V_201 ) ,
V_193 ) ;
if ( ! V_201 ) {
F_193 ( L_79 ) ;
V_206 = - V_194 ;
goto V_218;
}
for ( V_1 = 0 ; V_1 < V_200 ; V_1 ++ ) {
V_206 = F_163 ( F_106 ,
NULL ,
V_201 [ V_1 ] ) ;
if ( V_206 )
goto V_218;
}
}
F_180 () ;
F_200 () ;
return 0 ;
V_218:
F_200 () ;
F_179 () ;
return V_206 ;
}
