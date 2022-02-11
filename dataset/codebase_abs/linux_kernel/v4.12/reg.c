static const struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ) ;
}
const struct V_1 * F_3 ( struct V_3 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static const char * F_4 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
return L_1 ;
case V_8 :
return L_2 ;
case V_9 :
return L_3 ;
case V_10 :
return L_4 ;
}
return L_5 ;
}
enum V_5 F_5 ( struct V_3 * V_3 )
{
const struct V_1 * V_4 = NULL ;
const struct V_1 * V_11 = NULL ;
V_4 = F_1 () ;
if ( ! V_3 )
goto V_12;
V_11 = F_3 ( V_3 ) ;
if ( ! V_11 )
goto V_12;
if ( V_11 -> V_6 == V_4 -> V_6 )
goto V_12;
F_6 ( L_6 ,
F_7 ( & V_3 -> V_13 ) ,
F_4 ( V_11 -> V_6 ) ,
F_4 ( V_4 -> V_6 ) ) ;
V_12:
return V_4 -> V_6 ;
}
static void F_8 ( const struct V_1 * V_14 )
{
if ( ! V_14 )
return;
F_9 ( (struct V_1 * ) V_14 , V_15 ) ;
}
static struct V_16 * F_10 ( void )
{
return F_11 ( V_17 ) ;
}
static void F_12 ( struct V_16 * V_18 )
{
if ( V_18 == & V_19 )
return;
if ( V_18 != F_10 () )
F_13 ( V_18 ) ;
}
static void F_14 ( void )
{
struct V_16 * V_20 = F_10 () ;
if ( V_20 != & V_19 && V_20 )
F_9 ( V_20 , V_15 ) ;
}
static void F_15 ( struct V_16 * V_18 )
{
struct V_16 * V_20 ;
V_20 = F_10 () ;
if ( V_20 == V_18 )
return;
F_14 () ;
F_16 ( V_17 , V_18 ) ;
}
static void F_17 ( bool V_21 ,
const struct V_1 * V_22 )
{
const struct V_1 * V_14 ;
F_18 () ;
V_14 = F_1 () ;
if ( V_14 == V_23 )
V_14 = NULL ;
if ( V_23 == & V_24 )
V_23 = NULL ;
if ( V_14 == & V_24 )
V_14 = NULL ;
F_8 ( V_14 ) ;
F_8 ( V_23 ) ;
V_23 = & V_24 ;
F_16 ( V_2 , V_22 ) ;
if ( ! V_21 )
return;
F_15 ( & V_19 ) ;
}
static void F_19 ( const struct V_1 * V_25 )
{
struct V_16 * V_20 ;
V_20 = F_10 () ;
F_20 ( ! V_20 ) ;
F_17 ( false , V_25 ) ;
V_23 = V_25 ;
}
bool F_21 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] == '0' && V_26 [ 1 ] == '0' ;
}
static bool F_22 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] && V_26 [ 1 ] ;
}
static bool F_23 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] == '9' && V_26 [ 1 ] == '9' ;
}
static bool F_24 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] == '9' && V_26 [ 1 ] == '8' ;
}
static bool F_25 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return isalpha ( V_26 [ 0 ] ) && isalpha ( V_26 [ 1 ] ) ;
}
static bool F_26 ( const char * V_27 , const char * V_28 )
{
if ( ! V_27 || ! V_28 )
return false ;
return V_27 [ 0 ] == V_28 [ 0 ] && V_27 [ 1 ] == V_28 [ 1 ] ;
}
static bool F_27 ( const char * V_26 )
{
const struct V_1 * V_14 = F_1 () ;
if ( ! V_14 )
return true ;
return ! F_26 ( V_14 -> V_26 , V_26 ) ;
}
static bool F_28 ( void )
{
if ( V_29 [ 0 ] == '9' && V_29 [ 1 ] == '7' )
return false ;
if ( F_29 ( ! F_21 ( V_29 ) && ! F_25 ( V_29 ) ,
L_7 ,
V_29 [ 0 ] , V_29 [ 1 ] ) )
return false ;
return true ;
}
static const struct V_1 *
F_30 ( const struct V_1 * V_30 )
{
struct V_1 * V_4 ;
int V_31 ;
unsigned int V_32 ;
V_31 =
sizeof( struct V_1 ) +
V_30 -> V_33 * sizeof( struct V_34 ) ;
V_4 = F_31 ( V_31 , V_35 ) ;
if ( ! V_4 )
return F_32 ( - V_36 ) ;
memcpy ( V_4 , V_30 , sizeof( struct V_1 ) ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_33 ; V_32 ++ )
memcpy ( & V_4 -> V_37 [ V_32 ] , & V_30 -> V_37 [ V_32 ] ,
sizeof( struct V_34 ) ) ;
return V_4 ;
}
static void F_33 ( struct V_38 * V_39 )
{
struct V_40 * V_18 ;
F_34 () ;
F_35 ( & V_41 ) ;
while ( ! F_36 ( & V_42 ) ) {
V_18 = F_37 ( & V_42 ,
struct V_40 ,
V_43 ) ;
F_38 ( & V_18 -> V_43 ) ;
F_39 ( V_18 -> V_44 , V_45 ) ;
F_13 ( V_18 ) ;
}
F_40 ( & V_41 ) ;
F_41 () ;
}
static int F_42 ( const char * V_26 )
{
const struct V_1 * V_44 = NULL ;
struct V_40 * V_18 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
if ( F_26 ( V_26 , V_47 [ V_32 ] -> V_26 ) ) {
V_44 = V_47 [ V_32 ] ;
break;
}
}
if ( ! V_44 )
return - V_48 ;
V_18 = F_31 ( sizeof( struct V_40 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_44 = F_30 ( V_44 ) ;
if ( F_43 ( V_18 -> V_44 ) ) {
F_13 ( V_18 ) ;
return - V_36 ;
}
F_35 ( & V_41 ) ;
F_44 ( & V_18 -> V_43 , & V_42 ) ;
F_40 ( & V_41 ) ;
F_45 ( & V_49 ) ;
return 0 ;
}
static void F_46 ( void )
{
F_47 ( ! V_46 , L_8 ) ;
}
static inline void F_46 ( void ) {}
static inline int F_42 ( const char * V_26 )
{
return - V_48 ;
}
static void F_48 ( struct V_38 * V_39 )
{
F_6 ( L_9 ) ;
F_34 () ;
V_50 ++ ;
F_49 ( true ) ;
F_41 () ;
}
static void F_50 ( void )
{
F_51 ( & V_51 ) ;
}
static void F_52 ( void )
{
F_53 ( & V_51 ) ;
}
static void F_54 ( void )
{
V_50 = 0 ;
}
static int F_55 ( const char * V_26 )
{
char V_52 [ 12 ] ;
char * V_53 [] = { V_52 , NULL } ;
int V_54 ;
snprintf ( V_52 , sizeof( V_52 ) , L_10 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
if ( V_50 > V_55 ) {
F_6 ( L_11 ) ;
return - V_56 ;
}
if ( ! F_21 ( ( char * ) V_26 ) )
F_6 ( L_12 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
else
F_6 ( L_13 ) ;
V_54 = F_56 ( & V_57 -> V_13 . V_58 , V_59 , V_53 ) ;
if ( V_54 )
return V_54 ;
F_57 ( V_60 ,
& V_51 , F_58 ( 3142 ) ) ;
return 0 ;
}
static inline void F_50 ( void ) {}
static inline void F_52 ( void ) {}
static inline void F_54 ( void ) {}
static inline int F_55 ( const char * V_26 )
{
return - V_48 ;
}
static bool F_59 ( struct V_16 * V_18 )
{
if ( F_42 ( V_18 -> V_26 ) == 0 )
return true ;
if ( F_55 ( V_18 -> V_26 ) == 0 )
return true ;
return false ;
}
bool F_60 ( const char * V_26 )
{
struct V_16 * V_20 = F_10 () ;
if ( ! V_20 || V_20 -> V_61 )
return false ;
return F_26 ( V_20 -> V_26 , V_26 ) ;
}
static const struct V_1 * F_61 ( struct V_3 * V_3 )
{
struct V_16 * V_20 = F_10 () ;
if ( V_20 -> V_62 != V_63 &&
V_20 -> V_62 != V_64 &&
V_3 -> V_4 )
return F_3 ( V_3 ) ;
return F_1 () ;
}
static unsigned int
F_62 ( const struct V_1 * V_25 ,
const struct V_34 * V_65 )
{
const struct V_66 * V_67 = & V_65 -> V_67 ;
const struct V_66 * V_68 ;
const struct V_34 * V_69 ;
T_1 V_70 , V_71 , V_72 , V_73 ;
for ( V_72 = 0 ; V_72 < V_25 -> V_33 ; V_72 ++ )
if ( V_65 == & V_25 -> V_37 [ V_72 ] )
break;
if ( V_72 == V_25 -> V_33 )
return 0 ;
V_73 = V_72 ;
while ( V_73 ) {
V_69 = & V_25 -> V_37 [ -- V_73 ] ;
V_68 = & V_69 -> V_67 ;
if ( V_68 -> V_74 < V_67 -> V_75 )
break;
V_67 = V_68 ;
}
V_70 = V_67 -> V_75 ;
V_67 = & V_65 -> V_67 ;
V_73 = V_72 ;
while ( V_73 < V_25 -> V_33 - 1 ) {
V_69 = & V_25 -> V_37 [ ++ V_73 ] ;
V_68 = & V_69 -> V_67 ;
if ( V_68 -> V_75 > V_67 -> V_74 )
break;
V_67 = V_68 ;
}
V_71 = V_67 -> V_74 ;
return V_71 - V_70 ;
}
unsigned int F_63 ( const struct V_1 * V_25 ,
const struct V_34 * V_65 )
{
unsigned int V_76 = F_62 ( V_25 , V_65 ) ;
if ( V_65 -> V_77 & V_78 )
V_76 = F_64 (unsigned int, bw, MHZ_TO_KHZ(80)) ;
if ( V_65 -> V_77 & V_79 )
V_76 = F_64 (unsigned int, bw, MHZ_TO_KHZ(40)) ;
if ( V_65 -> V_77 & V_80 &&
V_65 -> V_77 & V_81 )
V_76 = F_64 (unsigned int, bw, MHZ_TO_KHZ(20)) ;
return V_76 ;
}
static bool F_65 ( const struct V_34 * V_65 )
{
const struct V_66 * V_67 = & V_65 -> V_67 ;
T_1 V_82 ;
if ( V_67 -> V_75 <= 0 || V_67 -> V_74 <= 0 )
return false ;
if ( V_67 -> V_75 > V_67 -> V_74 )
return false ;
V_82 = V_67 -> V_74 - V_67 -> V_75 ;
if ( V_67 -> V_74 <= V_67 -> V_75 ||
V_67 -> V_83 > V_82 )
return false ;
return true ;
}
static bool F_66 ( const struct V_1 * V_25 )
{
const struct V_34 * V_84 = NULL ;
unsigned int V_32 ;
if ( ! V_25 -> V_33 )
return false ;
if ( F_20 ( V_25 -> V_33 > V_85 ) )
return false ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_84 = & V_25 -> V_37 [ V_32 ] ;
if ( ! F_65 ( V_84 ) )
return false ;
}
return true ;
}
static bool F_67 ( const struct V_66 * V_67 ,
T_1 V_86 )
{
#define F_68 1000000
T_1 V_87 = V_86 > 45 * F_68 ?
10 * F_68 : 2 * F_68 ;
if ( abs ( V_86 - V_67 -> V_75 ) <= V_87 )
return true ;
if ( abs ( V_86 - V_67 -> V_74 ) <= V_87 )
return true ;
return false ;
#undef F_68
}
static enum V_5
F_69 ( const enum V_5 V_88 ,
const enum V_5 V_89 )
{
if ( V_88 != V_89 )
return V_7 ;
return V_88 ;
}
static int F_70 ( const struct V_1 * V_90 ,
const struct V_1 * V_91 ,
const struct V_34 * V_92 ,
const struct V_34 * V_93 ,
struct V_34 * V_94 )
{
const struct V_66 * V_95 , * V_96 ;
struct V_66 * V_67 ;
const struct V_97 * V_98 , * V_99 ;
struct V_97 * V_100 ;
T_1 V_82 , V_101 , V_102 ;
V_95 = & V_92 -> V_67 ;
V_96 = & V_93 -> V_67 ;
V_67 = & V_94 -> V_67 ;
V_98 = & V_92 -> V_100 ;
V_99 = & V_93 -> V_100 ;
V_100 = & V_94 -> V_100 ;
V_67 -> V_75 = F_71 ( V_95 -> V_75 ,
V_96 -> V_75 ) ;
V_67 -> V_74 = F_72 ( V_95 -> V_74 ,
V_96 -> V_74 ) ;
V_101 = V_95 -> V_83 ;
V_102 = V_96 -> V_83 ;
if ( V_92 -> V_77 & V_103 )
V_101 = F_63 ( V_90 , V_92 ) ;
if ( V_93 -> V_77 & V_103 )
V_102 = F_63 ( V_91 , V_93 ) ;
V_67 -> V_83 = F_72 ( V_101 , V_102 ) ;
V_94 -> V_77 = V_92 -> V_77 | V_93 -> V_77 ;
if ( ( V_92 -> V_77 & V_103 ) &&
( V_93 -> V_77 & V_103 ) )
V_94 -> V_77 |= V_103 ;
else
V_94 -> V_77 &= ~ V_103 ;
V_82 = V_67 -> V_74 - V_67 -> V_75 ;
if ( V_67 -> V_83 > V_82 )
V_67 -> V_83 = V_82 ;
V_100 -> V_104 = F_72 ( V_98 -> V_104 ,
V_99 -> V_104 ) ;
V_100 -> V_105 = F_72 ( V_98 -> V_105 ,
V_99 -> V_105 ) ;
V_94 -> V_106 = F_71 ( V_92 -> V_106 ,
V_93 -> V_106 ) ;
if ( ! F_65 ( V_94 ) )
return - V_56 ;
return 0 ;
}
static bool F_73 ( struct V_34 * V_107 ,
struct V_34 * V_108 )
{
if ( V_107 -> V_77 != V_108 -> V_77 )
return false ;
if ( ( V_107 -> V_100 . V_105 >
V_108 -> V_100 . V_105 ) ||
V_107 -> V_100 . V_104 > V_108 -> V_100 . V_104 )
return false ;
if ( V_107 -> V_67 . V_75 > V_108 -> V_67 . V_75 ||
V_107 -> V_67 . V_74 < V_108 -> V_67 . V_74 )
return false ;
if ( V_107 -> V_67 . V_83 <
V_108 -> V_67 . V_83 )
return false ;
return true ;
}
static void F_74 ( struct V_34 * V_65 ,
struct V_34 * V_37 , T_1 * V_109 )
{
struct V_34 * V_110 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < * V_109 ; V_32 ++ ) {
V_110 = & V_37 [ V_32 ] ;
if ( F_73 ( V_110 , V_65 ) )
return;
if ( F_73 ( V_65 , V_110 ) ) {
memcpy ( V_110 , V_65 , sizeof( * V_65 ) ) ;
return;
}
}
memcpy ( & V_37 [ * V_109 ] , V_65 , sizeof( * V_65 ) ) ;
( * V_109 ) ++ ;
}
static struct V_1 *
F_75 ( const struct V_1 * V_90 ,
const struct V_1 * V_91 )
{
int V_14 , V_31 ;
unsigned int V_111 , V_112 ;
unsigned int V_113 = 0 ;
const struct V_34 * V_92 , * V_93 ;
struct V_34 V_94 ;
struct V_1 * V_25 ;
if ( ! V_90 || ! V_91 )
return NULL ;
for ( V_111 = 0 ; V_111 < V_90 -> V_33 ; V_111 ++ ) {
V_92 = & V_90 -> V_37 [ V_111 ] ;
for ( V_112 = 0 ; V_112 < V_91 -> V_33 ; V_112 ++ ) {
V_93 = & V_91 -> V_37 [ V_112 ] ;
if ( ! F_70 ( V_90 , V_91 , V_92 , V_93 ,
& V_94 ) )
V_113 ++ ;
}
}
if ( ! V_113 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_113 * sizeof( struct V_34 ) ;
V_25 = F_31 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_111 = 0 ; V_111 < V_90 -> V_33 ; V_111 ++ ) {
V_92 = & V_90 -> V_37 [ V_111 ] ;
for ( V_112 = 0 ; V_112 < V_91 -> V_33 ; V_112 ++ ) {
V_93 = & V_91 -> V_37 [ V_112 ] ;
V_14 = F_70 ( V_90 , V_91 , V_92 , V_93 ,
& V_94 ) ;
if ( V_14 )
continue;
F_74 ( & V_94 , V_25 -> V_37 ,
& V_25 -> V_33 ) ;
}
}
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_69 ( V_90 -> V_6 ,
V_91 -> V_6 ) ;
return V_25 ;
}
static T_1 F_76 ( T_1 V_114 )
{
T_1 V_115 = 0 ;
if ( V_114 & V_116 )
V_115 |= V_117 ;
if ( V_114 & V_118 )
V_115 |= V_119 ;
if ( V_114 & V_120 )
V_115 |= V_121 ;
if ( V_114 & V_122 )
V_115 |= V_123 ;
if ( V_114 & V_124 )
V_115 |= V_125 ;
if ( V_114 & V_80 )
V_115 |= V_126 ;
if ( V_114 & V_81 )
V_115 |= V_127 ;
if ( V_114 & V_79 )
V_115 |= V_128 ;
if ( V_114 & V_78 )
V_115 |= V_129 ;
return V_115 ;
}
static const struct V_34 *
F_77 ( T_1 V_130 ,
const struct V_1 * V_4 , T_1 V_76 )
{
int V_32 ;
bool V_131 = false ;
bool V_132 = false ;
if ( ! V_4 )
return F_32 ( - V_56 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_133 ;
const struct V_66 * V_134 = NULL ;
V_133 = & V_4 -> V_37 [ V_32 ] ;
V_134 = & V_133 -> V_67 ;
if ( ! V_131 )
V_131 = F_67 ( V_134 , V_130 ) ;
V_132 = F_78 ( V_134 , V_130 , V_76 ) ;
if ( V_131 && V_132 )
return V_133 ;
}
if ( ! V_131 )
return F_32 ( - V_135 ) ;
return F_32 ( - V_56 ) ;
}
static const struct V_34 *
F_79 ( struct V_3 * V_3 , T_1 V_130 , T_1 V_136 )
{
const struct V_1 * V_4 = F_61 ( V_3 ) ;
const struct V_34 * V_84 = NULL ;
T_1 V_76 ;
for ( V_76 = F_80 ( 20 ) ; V_76 >= V_136 ; V_76 = V_76 / 2 ) {
V_84 = F_77 ( V_130 , V_4 , V_76 ) ;
if ( ! F_81 ( V_84 ) )
return V_84 ;
}
return V_84 ;
}
const struct V_34 * F_82 ( struct V_3 * V_3 ,
T_1 V_130 )
{
return F_79 ( V_3 , V_130 , F_80 ( 20 ) ) ;
}
const char * F_83 ( enum V_137 V_62 )
{
switch ( V_62 ) {
case V_138 :
return L_14 ;
case V_64 :
return L_15 ;
case V_139 :
return L_16 ;
case V_63 :
return L_17 ;
default:
F_20 ( 1 ) ;
return L_18 ;
}
}
static T_2 F_84 ( const struct V_1 * V_4 ,
const struct V_34 * V_84 ,
const struct V_140 * V_141 )
{
const struct V_66 * V_67 = NULL ;
T_1 V_83 , V_142 = 0 ;
V_67 = & V_84 -> V_67 ;
V_83 = V_67 -> V_83 ;
if ( V_84 -> V_77 & V_103 )
V_83 = F_63 ( V_4 , V_84 ) ;
if ( ! F_78 ( V_67 ,
F_80 ( V_141 -> V_130 ) ,
F_80 ( 10 ) ) )
V_142 |= V_143 ;
if ( ! F_78 ( V_67 ,
F_80 ( V_141 -> V_130 ) ,
F_80 ( 20 ) ) )
V_142 |= V_144 ;
if ( V_83 < F_80 ( 10 ) )
V_142 |= V_143 ;
if ( V_83 < F_80 ( 20 ) )
V_142 |= V_144 ;
if ( V_83 < F_80 ( 40 ) )
V_142 |= V_145 ;
if ( V_83 < F_80 ( 80 ) )
V_142 |= V_128 ;
if ( V_83 < F_80 ( 160 ) )
V_142 |= V_129 ;
return V_142 ;
}
static void F_85 ( struct V_3 * V_3 ,
enum V_137 V_62 ,
struct V_140 * V_141 )
{
T_1 V_77 , V_142 = 0 ;
const struct V_34 * V_84 = NULL ;
const struct V_97 * V_100 = NULL ;
struct V_3 * V_146 = NULL ;
struct V_16 * V_20 = F_10 () ;
const struct V_1 * V_4 ;
V_146 = F_86 ( V_20 -> V_147 ) ;
V_77 = V_141 -> V_148 ;
V_84 = F_82 ( V_3 , F_80 ( V_141 -> V_130 ) ) ;
if ( F_81 ( V_84 ) ) {
if ( V_62 == V_63 &&
F_87 ( V_84 ) == - V_135 )
return;
if ( V_20 -> V_62 == V_139 &&
V_146 && V_146 == V_3 &&
V_146 -> V_149 & V_150 ) {
F_6 ( L_19 ,
V_141 -> V_130 ) ;
V_141 -> V_148 |= V_151 ;
V_141 -> V_77 = V_141 -> V_148 ;
} else {
F_6 ( L_20 ,
V_141 -> V_130 ) ;
V_141 -> V_77 |= V_151 ;
}
return;
}
V_4 = F_61 ( V_3 ) ;
V_100 = & V_84 -> V_100 ;
V_142 = F_84 ( V_4 , V_84 , V_141 ) ;
if ( V_20 -> V_62 == V_139 &&
V_146 && V_146 == V_3 &&
V_146 -> V_149 & V_150 ) {
V_141 -> V_77 = V_141 -> V_148 =
F_76 ( V_84 -> V_77 ) | V_142 ;
V_141 -> V_105 = V_141 -> V_152 =
( int ) F_88 ( V_100 -> V_105 ) ;
V_141 -> V_153 = V_141 -> V_154 = V_141 -> V_155 =
( int ) F_89 ( V_100 -> V_104 ) ;
if ( V_141 -> V_77 & V_119 ) {
V_141 -> V_106 = V_156 ;
if ( V_84 -> V_106 )
V_141 -> V_106 = V_84 -> V_106 ;
}
return;
}
V_141 -> V_157 = V_158 ;
V_141 -> V_159 = V_160 ;
V_141 -> V_161 = false ;
V_141 -> V_77 = V_77 | V_142 | F_76 ( V_84 -> V_77 ) ;
V_141 -> V_105 =
F_64 ( int , V_141 -> V_152 ,
F_88 ( V_100 -> V_105 ) ) ;
V_141 -> V_153 = ( int ) F_89 ( V_100 -> V_104 ) ;
if ( V_141 -> V_77 & V_119 ) {
if ( V_84 -> V_106 )
V_141 -> V_106 = V_84 -> V_106 ;
else
V_141 -> V_106 = V_156 ;
}
if ( V_141 -> V_155 ) {
if ( V_62 == V_63 &&
V_3 -> V_149 & V_162 )
V_141 -> V_154 = V_141 -> V_153 ;
else
V_141 -> V_154 = F_72 ( V_141 -> V_155 ,
V_141 -> V_153 ) ;
} else
V_141 -> V_154 = V_141 -> V_153 ;
}
static void F_90 ( struct V_3 * V_3 ,
enum V_137 V_62 ,
struct V_163 * V_164 )
{
unsigned int V_32 ;
if ( ! V_164 )
return;
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ )
F_85 ( V_3 , V_62 , & V_164 -> V_166 [ V_32 ] ) ;
}
static bool F_91 ( struct V_16 * V_18 )
{
if ( V_18 -> V_62 != V_64 )
return false ;
return V_18 -> V_167 == V_168 ;
}
bool F_92 ( void )
{
return F_91 ( F_10 () ) ;
}
static enum V_169
F_93 ( struct V_16 * V_170 )
{
struct V_16 * V_20 = F_10 () ;
if ( ! V_171 )
return V_172 ;
if ( F_91 ( V_20 ) &&
! F_27 ( V_170 -> V_26 ) )
return V_173 ;
return V_174 ;
}
static bool F_94 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_175 & V_176 ) ;
}
static enum V_169
F_93 ( struct V_16 * V_170 )
{
return V_172 ;
}
static bool F_94 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_95 ( struct V_3 * V_3 )
{
if ( V_3 -> V_149 & V_150 &&
! ( V_3 -> V_149 & V_177 ) )
return true ;
return false ;
}
static bool F_96 ( struct V_3 * V_3 ,
enum V_137 V_62 )
{
struct V_16 * V_20 = F_10 () ;
if ( V_3 -> V_149 & V_178 )
return true ;
if ( ! V_20 ) {
F_6 ( L_21 ,
F_83 ( V_62 ) ) ;
return true ;
}
if ( V_62 == V_138 &&
V_3 -> V_149 & V_177 ) {
F_6 ( L_22 ,
F_83 ( V_62 ) ) ;
return true ;
}
if ( F_95 ( V_3 ) && ! V_3 -> V_4 &&
V_62 != V_63 &&
! F_21 ( V_20 -> V_26 ) ) {
F_6 ( L_23 ,
F_83 ( V_62 ) ) ;
return true ;
}
if ( F_91 ( V_20 ) )
return F_94 ( V_3 ) ;
return false ;
}
static bool F_97 ( struct V_3 * V_3 )
{
const struct V_1 * V_179 = F_1 () ;
const struct V_1 * V_180 = F_3 ( V_3 ) ;
struct V_16 * V_20 = F_10 () ;
if ( F_21 ( V_179 -> V_26 ) || ( V_180 && F_21 ( V_180 -> V_26 ) ) )
return true ;
if ( V_20 && V_20 -> V_62 != V_63 &&
V_3 -> V_149 & V_177 )
return true ;
return false ;
}
static void F_98 ( struct V_3 * V_3 , unsigned int V_181 ,
struct V_182 * V_182 )
{
struct V_163 * V_164 ;
struct V_140 * V_141 ;
bool V_183 = false ;
struct V_140 V_184 ;
V_164 = V_3 -> V_185 [ V_182 -> V_141 . V_186 ] ;
V_141 = & V_164 -> V_166 [ V_181 ] ;
if ( F_99 ( V_141 -> V_130 != V_182 -> V_141 . V_130 ) )
return;
if ( V_141 -> V_161 )
return;
V_141 -> V_161 = true ;
if ( ! F_97 ( V_3 ) )
return;
if ( V_3 -> V_149 & V_187 )
return;
V_184 . V_130 = V_141 -> V_130 ;
V_184 . V_77 = V_141 -> V_77 ;
if ( V_141 -> V_77 & V_117 ) {
V_141 -> V_77 &= ~ V_117 ;
V_183 = true ;
}
if ( V_183 )
F_100 ( V_3 , & V_184 , V_141 ) ;
}
static void F_101 ( struct V_3 * V_3 ,
struct V_182 * V_182 )
{
unsigned int V_32 ;
struct V_163 * V_164 ;
if ( ! V_3 -> V_185 [ V_182 -> V_141 . V_186 ] )
return;
V_164 = V_3 -> V_185 [ V_182 -> V_141 . V_186 ] ;
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ )
F_98 ( V_3 , V_32 , V_182 ) ;
}
static void F_102 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_163 * V_164 ;
struct V_182 * V_182 ;
F_103 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_185 [ V_182 -> V_141 . V_186 ] )
continue;
V_164 = V_3 -> V_185 [ V_182 -> V_141 . V_186 ] ;
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ )
F_98 ( V_3 , V_32 , V_182 ) ;
}
}
static void F_104 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_102 ( V_3 ) ;
}
static bool F_105 ( struct V_140 * V_141 )
{
if ( ! V_141 )
return false ;
if ( V_141 -> V_77 & V_151 )
return false ;
if ( ( V_141 -> V_77 & V_145 ) == V_145 )
return false ;
return true ;
}
static void F_106 ( struct V_3 * V_3 ,
struct V_140 * V_188 )
{
struct V_163 * V_164 = V_3 -> V_185 [ V_188 -> V_186 ] ;
struct V_140 * V_189 = NULL , * V_190 = NULL ;
unsigned int V_32 ;
if ( ! F_105 ( V_188 ) ) {
V_188 -> V_77 |= V_145 ;
return;
}
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ ) {
struct V_140 * V_191 = & V_164 -> V_166 [ V_32 ] ;
if ( V_191 -> V_130 == ( V_188 -> V_130 - 20 ) )
V_189 = V_191 ;
if ( V_191 -> V_130 == ( V_188 -> V_130 + 20 ) )
V_190 = V_191 ;
}
if ( ! F_105 ( V_189 ) )
V_188 -> V_77 |= V_126 ;
else
V_188 -> V_77 &= ~ V_126 ;
if ( ! F_105 ( V_190 ) )
V_188 -> V_77 |= V_127 ;
else
V_188 -> V_77 &= ~ V_127 ;
}
static void F_107 ( struct V_3 * V_3 ,
struct V_163 * V_164 )
{
unsigned int V_32 ;
if ( ! V_164 )
return;
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ )
F_106 ( V_3 , & V_164 -> V_166 [ V_32 ] ) ;
}
static void F_108 ( struct V_3 * V_3 )
{
enum V_192 V_186 ;
if ( ! V_3 )
return;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ )
F_107 ( V_3 , V_3 -> V_185 [ V_186 ] ) ;
}
static void F_109 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_194 )
V_3 -> V_194 ( V_3 , V_18 ) ;
}
static bool F_110 ( struct V_3 * V_3 , struct V_195 * V_196 )
{
struct V_197 V_198 ;
struct V_199 * V_200 = F_111 ( V_3 ) ;
enum V_201 V_202 ;
F_112 ( V_196 ) ;
V_202 = V_196 -> V_202 ;
if ( ! V_196 -> V_203 || ! F_113 ( V_196 -> V_203 ) )
goto V_204;
switch ( V_202 ) {
case V_205 :
case V_206 :
if ( ! V_196 -> V_207 )
goto V_204;
V_198 = V_196 -> V_198 ;
break;
case V_208 :
if ( ! V_196 -> V_209 )
goto V_204;
V_198 = V_196 -> V_198 ;
break;
case V_210 :
case V_211 :
if ( ! V_196 -> V_212 ||
! V_196 -> V_212 -> V_213 . V_188 )
goto V_204;
if ( ! V_200 -> V_214 -> V_215 ||
F_114 ( V_200 , V_196 , & V_198 ) )
F_115 ( & V_198 ,
V_196 -> V_212 -> V_213 . V_188 ,
V_216 ) ;
break;
case V_217 :
case V_218 :
case V_219 :
break;
default:
F_20 ( 1 ) ;
break;
}
F_116 ( V_196 ) ;
switch ( V_202 ) {
case V_205 :
case V_206 :
case V_208 :
return F_117 ( V_3 , & V_198 , V_202 ) ;
case V_210 :
case V_211 :
return F_118 ( V_3 , & V_198 ,
V_151 ) ;
default:
break;
}
return true ;
V_204:
F_116 ( V_196 ) ;
return true ;
}
static void F_119 ( struct V_3 * V_3 )
{
struct V_195 * V_196 ;
struct V_199 * V_200 = F_111 ( V_3 ) ;
F_18 () ;
F_103 (wdev, &rdev->wiphy.wdev_list, list)
if ( ! F_110 ( V_3 , V_196 ) )
F_120 ( V_200 , V_196 ) ;
}
static void F_121 ( struct V_38 * V_39 )
{
struct V_199 * V_200 ;
F_6 ( L_24 ) ;
F_34 () ;
F_103 (rdev, &cfg80211_rdev_list, list)
if ( ! ( V_200 -> V_3 . V_149 &
V_220 ) )
F_119 ( & V_200 -> V_3 ) ;
F_41 () ;
}
static void F_122 ( void )
{
F_123 ( V_60 ,
& V_221 ,
F_58 ( V_222 ) ) ;
}
static void F_124 ( struct V_3 * V_3 ,
enum V_137 V_62 )
{
enum V_192 V_186 ;
struct V_16 * V_20 = F_10 () ;
if ( F_96 ( V_3 , V_62 ) ) {
if ( V_62 == V_138 &&
V_3 -> V_149 & V_177 )
F_109 ( V_3 , V_20 ) ;
return;
}
V_20 -> V_6 = F_1 () -> V_6 ;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ )
F_90 ( V_3 , V_62 , V_3 -> V_185 [ V_186 ] ) ;
F_104 ( V_3 ) ;
F_108 ( V_3 ) ;
F_109 ( V_3 , V_20 ) ;
}
static void F_125 ( enum V_137 V_62 )
{
struct V_199 * V_200 ;
struct V_3 * V_3 ;
F_18 () ;
F_103 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_200 -> V_3 ;
F_124 ( V_3 , V_62 ) ;
}
F_122 () ;
}
static void F_126 ( struct V_3 * V_3 ,
struct V_140 * V_141 ,
const struct V_1 * V_4 )
{
T_1 V_142 = 0 ;
const struct V_34 * V_84 = NULL ;
const struct V_97 * V_100 = NULL ;
T_1 V_76 ;
for ( V_76 = F_80 ( 20 ) ; V_76 >= F_80 ( 5 ) ; V_76 = V_76 / 2 ) {
V_84 = F_77 ( F_80 ( V_141 -> V_130 ) ,
V_4 , V_76 ) ;
if ( ! F_81 ( V_84 ) )
break;
}
if ( F_81 ( V_84 ) ) {
F_6 ( L_25 ,
V_141 -> V_130 ) ;
if ( V_3 -> V_149 & V_178 ) {
V_141 -> V_77 |= V_151 ;
} else {
V_141 -> V_148 |= V_151 ;
V_141 -> V_77 = V_141 -> V_148 ;
}
return;
}
V_100 = & V_84 -> V_100 ;
V_142 = F_84 ( V_4 , V_84 , V_141 ) ;
V_141 -> V_159 = V_160 ;
V_141 -> V_157 = V_158 ;
V_141 -> V_161 = false ;
if ( V_3 -> V_149 & V_178 )
V_141 -> V_77 = V_141 -> V_148 | V_142 |
F_76 ( V_84 -> V_77 ) ;
else
V_141 -> V_77 |= F_76 ( V_84 -> V_77 ) | V_142 ;
V_141 -> V_105 = ( int ) F_88 ( V_100 -> V_105 ) ;
V_141 -> V_153 = V_141 -> V_154 =
( int ) F_89 ( V_100 -> V_104 ) ;
if ( V_141 -> V_77 & V_119 ) {
if ( V_84 -> V_106 )
V_141 -> V_106 = V_84 -> V_106 ;
else
V_141 -> V_106 = V_156 ;
}
V_141 -> V_154 = V_141 -> V_153 ;
}
static void F_127 ( struct V_3 * V_3 ,
struct V_163 * V_164 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_164 )
return;
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ )
F_126 ( V_3 , & V_164 -> V_166 [ V_32 ] , V_4 ) ;
}
void F_128 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_192 V_186 ;
unsigned int V_223 = 0 ;
F_29 ( ! ( V_3 -> V_149 & V_177 ) ,
L_26 ) ;
V_3 -> V_149 |= V_177 ;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ ) {
if ( ! V_3 -> V_185 [ V_186 ] )
continue;
F_127 ( V_3 , V_3 -> V_185 [ V_186 ] , V_4 ) ;
V_223 ++ ;
}
F_20 ( ! V_223 ) ;
}
static void F_129 ( void )
{
bool V_224 = false ;
struct V_16 * V_20 = F_10 () ;
V_20 -> V_61 = true ;
F_130 ( & V_225 ) ;
if ( ! F_36 ( & V_226 ) )
V_224 = true ;
F_131 ( & V_225 ) ;
F_50 () ;
if ( V_224 )
F_45 ( & V_227 ) ;
}
static enum V_169
F_132 ( struct V_16 * V_228 )
{
if ( F_59 ( V_228 ) ) {
V_228 -> V_229 = false ;
V_228 -> V_61 = false ;
F_15 ( V_228 ) ;
return V_174 ;
}
return V_172 ;
}
static enum V_169
F_133 ( struct V_16 * V_230 )
{
struct V_16 * V_20 = F_10 () ;
if ( F_91 ( V_230 ) )
return F_93 ( V_230 ) ;
if ( F_91 ( V_20 ) )
return V_172 ;
if ( V_20 -> V_62 == V_63 )
return V_231 ;
if ( V_20 -> V_62 == V_64 &&
V_20 -> V_229 )
return V_172 ;
if ( ( V_20 -> V_62 == V_138 ||
V_20 -> V_62 == V_139 ||
V_20 -> V_62 == V_64 ) &&
F_27 ( V_20 -> V_26 ) )
return V_172 ;
if ( ! F_27 ( V_230 -> V_26 ) )
return V_173 ;
return V_174 ;
}
static enum V_169
F_134 ( struct V_16 * V_230 )
{
enum V_169 V_232 ;
V_232 = F_133 ( V_230 ) ;
if ( V_232 == V_172 ||
V_232 == V_173 )
return V_172 ;
V_230 -> V_229 = V_232 == V_231 ;
V_230 -> V_61 = false ;
if ( F_59 ( V_230 ) ) {
F_15 ( V_230 ) ;
V_29 [ 0 ] = V_230 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_230 -> V_26 [ 1 ] ;
return V_174 ;
}
return V_172 ;
}
static enum V_169
F_135 ( struct V_16 * V_233 )
{
struct V_16 * V_20 = F_10 () ;
if ( V_20 -> V_62 == V_138 ) {
if ( F_27 ( V_233 -> V_26 ) )
return V_174 ;
return V_173 ;
}
if ( V_20 -> V_62 == V_139 &&
! F_27 ( V_233 -> V_26 ) )
return V_173 ;
return V_231 ;
}
static enum V_169
F_136 ( struct V_3 * V_3 ,
struct V_16 * V_233 )
{
const struct V_1 * V_4 , * V_69 ;
enum V_169 V_232 ;
V_232 = F_135 ( V_233 ) ;
switch ( V_232 ) {
case V_174 :
break;
case V_172 :
return V_172 ;
case V_231 :
case V_173 :
V_4 = F_30 ( F_1 () ) ;
if ( F_81 ( V_4 ) )
return V_172 ;
V_69 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_69 ) ;
}
V_233 -> V_229 = V_232 == V_231 ;
V_233 -> V_61 = false ;
if ( V_232 == V_173 ) {
F_137 ( V_233 ) ;
F_15 ( V_233 ) ;
F_129 () ;
return V_173 ;
}
if ( F_59 ( V_233 ) ) {
F_15 ( V_233 ) ;
return V_174 ;
}
return V_172 ;
}
static enum V_169
F_138 ( struct V_3 * V_3 ,
struct V_16 * V_234 )
{
struct V_3 * V_235 = NULL ;
struct V_16 * V_20 = F_10 () ;
if ( F_91 ( V_20 ) ) {
if ( F_27 ( V_234 -> V_26 ) )
return V_172 ;
return V_173 ;
} else {
if ( V_3 -> V_149 & V_236 )
return V_172 ;
}
if ( F_139 ( ! F_25 ( V_234 -> V_26 ) ) )
return - V_56 ;
if ( V_20 -> V_62 != V_63 )
return V_174 ;
V_235 = F_86 ( V_20 -> V_147 ) ;
if ( V_235 != V_3 ) {
if ( F_27 ( V_234 -> V_26 ) )
return V_172 ;
return V_173 ;
}
if ( F_27 ( V_234 -> V_26 ) )
return V_174 ;
return V_173 ;
}
static enum V_169
F_140 ( struct V_3 * V_3 ,
struct V_16 * V_234 )
{
enum V_169 V_232 ;
V_232 = F_138 ( V_3 , V_234 ) ;
switch ( V_232 ) {
case V_174 :
break;
case V_172 :
return V_172 ;
case V_173 :
F_12 ( V_234 ) ;
return V_173 ;
case V_231 :
F_47 ( 1 , L_27 ) ;
return V_172 ;
}
V_234 -> V_229 = false ;
V_234 -> V_61 = false ;
if ( F_59 ( V_234 ) ) {
F_15 ( V_234 ) ;
return V_174 ;
}
return V_172 ;
}
bool F_141 ( struct V_3 * V_237 , struct V_3 * V_238 )
{
const struct V_1 * V_239 = NULL ;
const struct V_1 * V_240 = NULL ;
const struct V_1 * V_241 = NULL ;
bool V_242 ;
F_142 () ;
V_241 = F_143 ( V_2 ) ;
V_239 = F_143 ( V_237 -> V_4 ) ;
if ( ! V_239 )
V_239 = V_241 ;
V_240 = F_143 ( V_238 -> V_4 ) ;
if ( ! V_240 )
V_240 = V_241 ;
V_242 = V_239 -> V_6 == V_240 -> V_6 ;
F_144 () ;
return V_242 ;
}
static void F_145 ( struct V_140 * V_243 ,
struct V_140 * V_244 )
{
if ( ! ( V_243 -> V_77 & V_119 ) ||
! ( V_244 -> V_77 & V_119 ) )
return;
if ( V_243 -> V_77 & V_151 ||
V_244 -> V_77 & V_151 )
return;
if ( V_244 -> V_130 == V_243 -> V_130 &&
V_243 -> V_157 == V_158 ) {
V_243 -> V_157 = V_244 -> V_157 ;
V_243 -> V_159 = V_244 -> V_159 ;
}
}
static void F_146 ( struct V_3 * V_245 ,
struct V_3 * V_246 )
{
struct V_163 * V_247 , * V_248 ;
struct V_140 * V_244 , * V_243 ;
int V_32 , V_249 , V_186 ;
if ( ! F_141 ( V_245 , V_246 ) )
return;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ ) {
V_248 = V_245 -> V_185 [ V_186 ] ;
V_247 = V_246 -> V_185 [ V_186 ] ;
if ( ! V_248 || ! V_247 )
continue;
for ( V_32 = 0 ; V_32 < V_248 -> V_165 ; V_32 ++ ) {
V_243 = & V_248 -> V_166 [ V_32 ] ;
for ( V_249 = 0 ; V_249 < V_247 -> V_165 ; V_249 ++ ) {
V_244 = & V_247 -> V_166 [ V_249 ] ;
F_145 ( V_243 , V_244 ) ;
}
}
}
}
static void F_147 ( struct V_3 * V_3 )
{
struct V_199 * V_200 ;
F_18 () ;
F_103 (rdev, &cfg80211_rdev_list, list) {
if ( V_3 == & V_200 -> V_3 )
continue;
F_146 ( V_3 , & V_200 -> V_3 ) ;
}
}
static void F_148 ( struct V_16 * V_250 )
{
struct V_3 * V_3 = NULL ;
enum V_169 V_232 ;
if ( V_250 -> V_147 != V_251 )
V_3 = F_86 ( V_250 -> V_147 ) ;
switch ( V_250 -> V_62 ) {
case V_138 :
V_232 = F_132 ( V_250 ) ;
break;
case V_64 :
V_232 = F_134 ( V_250 ) ;
break;
case V_139 :
if ( ! V_3 )
goto V_252;
V_232 = F_136 ( V_3 , V_250 ) ;
break;
case V_63 :
if ( ! V_3 )
goto V_252;
V_232 = F_140 ( V_3 , V_250 ) ;
break;
default:
F_29 ( 1 , L_28 , V_250 -> V_62 ) ;
goto V_252;
}
if ( V_232 == V_172 )
goto V_252;
F_29 ( V_232 != V_174 && V_232 != V_173 ,
L_29 , V_232 ) ;
if ( V_232 == V_173 && V_3 &&
V_3 -> V_149 & V_150 ) {
F_124 ( V_3 , V_250 -> V_62 ) ;
F_147 ( V_3 ) ;
F_122 () ;
}
return;
V_252:
F_12 ( V_250 ) ;
}
static bool F_149 ( void )
{
struct V_199 * V_200 ;
struct V_3 * V_3 ;
bool V_253 = false ;
F_18 () ;
F_103 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_200 -> V_3 ;
if ( V_3 -> V_149 & V_178 )
V_253 = true ;
else
return false ;
}
return V_253 ;
}
static void F_150 ( void )
{
struct V_16 * V_250 , * V_20 ;
V_20 = F_10 () ;
if ( V_20 && ! V_20 -> V_61 ) {
F_148 ( V_20 ) ;
return;
}
F_130 ( & V_225 ) ;
if ( F_36 ( & V_226 ) ) {
F_131 ( & V_225 ) ;
return;
}
V_250 = F_37 ( & V_226 ,
struct V_16 ,
V_43 ) ;
F_151 ( & V_250 -> V_43 ) ;
F_131 ( & V_225 ) ;
if ( F_149 () ) {
F_12 ( V_250 ) ;
return;
}
F_148 ( V_250 ) ;
V_20 = F_10 () ;
F_130 ( & V_225 ) ;
if ( ! F_36 ( & V_226 ) && V_20 && V_20 -> V_61 )
F_45 ( & V_227 ) ;
F_131 ( & V_225 ) ;
}
static void F_152 ( void )
{
struct V_199 * V_200 ;
struct V_182 * V_254 , * V_69 ;
F_153 ( & V_255 ) ;
F_154 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_151 ( & V_254 -> V_43 ) ;
F_103 (rdev, &cfg80211_rdev_list, list)
F_101 ( & V_200 -> V_3 , V_254 ) ;
F_44 ( & V_254 -> V_43 , & V_256 ) ;
}
F_155 ( & V_255 ) ;
}
static void F_156 ( void )
{
struct V_199 * V_200 ;
struct V_3 * V_3 ;
const struct V_1 * V_69 ;
const struct V_1 * V_4 ;
enum V_192 V_186 ;
struct V_16 V_18 = {} ;
F_103 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_200 -> V_3 ;
F_130 ( & V_225 ) ;
V_4 = V_200 -> V_257 ;
V_200 -> V_257 = NULL ;
F_131 ( & V_225 ) ;
if ( V_4 == NULL )
continue;
V_69 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_69 ) ;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ )
F_127 ( V_3 , V_3 -> V_185 [ V_186 ] , V_4 ) ;
F_108 ( V_3 ) ;
V_18 . V_147 = F_157 ( V_3 ) ;
V_18 . V_26 [ 0 ] = V_4 -> V_26 [ 0 ] ;
V_18 . V_26 [ 1 ] = V_4 -> V_26 [ 1 ] ;
V_18 . V_62 = V_139 ;
F_158 ( & V_18 ) ;
}
F_122 () ;
}
static void F_159 ( struct V_38 * V_39 )
{
F_34 () ;
F_150 () ;
F_152 () ;
F_156 () ;
F_41 () ;
}
static void F_160 ( struct V_16 * V_18 )
{
V_18 -> V_26 [ 0 ] = toupper ( V_18 -> V_26 [ 0 ] ) ;
V_18 -> V_26 [ 1 ] = toupper ( V_18 -> V_26 [ 1 ] ) ;
F_130 ( & V_225 ) ;
F_44 ( & V_18 -> V_43 , & V_226 ) ;
F_131 ( & V_225 ) ;
F_45 ( & V_227 ) ;
}
static int F_161 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_138 ;
F_160 ( V_18 ) ;
return 0 ;
}
int F_162 ( const char * V_26 ,
enum V_258 V_167 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_56 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_147 = V_251 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_64 ;
V_18 -> V_167 = V_167 ;
F_54 () ;
F_160 ( V_18 ) ;
return 0 ;
}
int F_163 ( bool V_259 , T_1 V_260 )
{
F_130 ( & V_261 ) ;
V_262 = V_259 ;
if ( V_262 ) {
if ( ! V_263 )
V_263 = V_260 ;
} else {
V_263 = 0 ;
}
F_131 ( & V_261 ) ;
if ( ! V_259 )
F_122 () ;
return 0 ;
}
void F_164 ( T_1 V_260 )
{
F_130 ( & V_261 ) ;
if ( V_263 != V_260 ) {
F_131 ( & V_261 ) ;
return;
}
V_262 = false ;
V_263 = 0 ;
F_131 ( & V_261 ) ;
F_122 () ;
}
int F_165 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_56 ;
V_3 -> V_149 &= ~ V_177 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_147 = F_157 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_139 ;
F_54 () ;
F_160 ( V_18 ) ;
return 0 ;
}
void F_166 ( struct V_3 * V_3 , enum V_192 V_186 ,
const T_3 * V_264 , T_3 V_265 )
{
char V_26 [ 2 ] ;
enum V_266 V_53 = V_267 ;
struct V_16 * V_18 = NULL , * V_20 ;
if ( V_265 & 0x01 )
return;
if ( V_265 < V_268 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_264 [ 0 ] ;
V_26 [ 1 ] = V_264 [ 1 ] ;
if ( V_264 [ 2 ] == 'I' )
V_53 = V_269 ;
else if ( V_264 [ 2 ] == 'O' )
V_53 = V_270 ;
F_142 () ;
V_20 = F_10 () ;
if ( F_139 ( ! V_20 ) )
goto V_12;
if ( V_20 -> V_62 == V_63 &&
V_20 -> V_147 != V_251 )
goto V_12;
V_18 -> V_147 = F_157 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_63 ;
V_18 -> V_271 = V_53 ;
F_54 () ;
F_160 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_144 () ;
}
static void F_167 ( char * V_26 , bool V_272 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_272 ) {
F_6 ( L_30 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_273 ) ) {
F_6 ( L_31 ,
V_273 [ 0 ] , V_273 [ 1 ] ) ;
V_26 [ 0 ] = V_273 [ 0 ] ;
V_26 [ 1 ] = V_273 [ 1 ] ;
}
} else {
F_6 ( L_32 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_273 ) ) {
F_6 ( L_31 ,
V_273 [ 0 ] , V_273 [ 1 ] ) ;
V_26 [ 0 ] = V_273 [ 0 ] ;
V_26 [ 1 ] = V_273 [ 1 ] ;
} else
F_6 ( L_33 ) ;
}
static void F_168 ( struct V_3 * V_3 )
{
struct V_163 * V_164 ;
enum V_192 V_186 ;
struct V_140 * V_141 ;
int V_32 ;
for ( V_186 = 0 ; V_186 < V_193 ; V_186 ++ ) {
V_164 = V_3 -> V_185 [ V_186 ] ;
if ( ! V_164 )
continue;
for ( V_32 = 0 ; V_32 < V_164 -> V_165 ; V_32 ++ ) {
V_141 = & V_164 -> V_166 [ V_32 ] ;
V_141 -> V_77 = V_141 -> V_148 ;
V_141 -> V_105 = V_141 -> V_152 ;
V_141 -> V_154 = V_141 -> V_155 ;
V_141 -> V_161 = false ;
}
}
}
static void F_49 ( bool V_272 )
{
char V_26 [ 2 ] ;
char V_274 [ 2 ] ;
struct V_182 * V_182 , * V_275 ;
F_169 ( V_276 ) ;
struct V_199 * V_200 ;
F_18 () ;
F_130 ( & V_261 ) ;
if ( V_262 && ! V_263 ) {
V_262 = false ;
F_122 () ;
}
F_131 ( & V_261 ) ;
F_17 ( true , & V_24 ) ;
F_167 ( V_26 , V_272 ) ;
F_130 ( & V_225 ) ;
F_170 ( & V_226 , & V_276 ) ;
F_131 ( & V_225 ) ;
F_153 ( & V_255 ) ;
F_154 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_182 -> V_43 ) ;
F_13 ( V_182 ) ;
}
F_155 ( & V_255 ) ;
F_154 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_182 -> V_43 ) ;
F_13 ( V_182 ) ;
}
V_274 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_274 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_103 (rdev, &cfg80211_rdev_list, list) {
if ( V_200 -> V_3 . V_149 & V_178 )
continue;
if ( V_200 -> V_3 . V_149 & V_177 )
F_168 ( & V_200 -> V_3 ) ;
}
F_161 ( V_274 ) ;
if ( F_25 ( V_26 ) )
F_162 ( V_26 , V_277 ) ;
F_130 ( & V_225 ) ;
F_170 ( & V_276 , & V_226 ) ;
F_131 ( & V_225 ) ;
F_6 ( L_34 ) ;
F_45 ( & V_227 ) ;
}
void F_171 ( void )
{
F_6 ( L_35 ) ;
F_49 ( false ) ;
}
static bool F_172 ( T_4 V_278 )
{
if ( V_278 == F_173 ( 12 , V_279 ) ||
V_278 == F_173 ( 13 , V_279 ) ||
V_278 == F_173 ( 14 , V_279 ) )
return true ;
return false ;
}
static bool F_174 ( struct V_140 * V_280 )
{
struct V_182 * V_254 ;
F_103 (pending_beacon, &reg_pending_beacons, list)
if ( V_280 -> V_130 ==
V_254 -> V_141 . V_130 )
return true ;
return false ;
}
int F_175 ( struct V_3 * V_3 ,
struct V_140 * V_280 ,
T_5 V_281 )
{
struct V_182 * V_182 ;
bool V_282 ;
if ( V_280 -> V_161 ||
V_280 -> V_77 & V_119 ||
( V_280 -> V_186 == V_279 &&
! F_172 ( V_280 -> V_130 ) ) )
return 0 ;
F_153 ( & V_255 ) ;
V_282 = F_174 ( V_280 ) ;
F_155 ( & V_255 ) ;
if ( V_282 )
return 0 ;
V_182 = F_31 ( sizeof( struct V_182 ) , V_281 ) ;
if ( ! V_182 )
return - V_36 ;
F_6 ( L_36 ,
V_280 -> V_130 ,
F_176 ( V_280 -> V_130 ) ,
F_177 ( V_3 ) ) ;
memcpy ( & V_182 -> V_141 , V_280 ,
sizeof( struct V_140 ) ) ;
F_153 ( & V_255 ) ;
F_44 ( & V_182 -> V_43 , & V_283 ) ;
F_155 ( & V_255 ) ;
F_45 ( & V_227 ) ;
return 0 ;
}
static void F_178 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_84 = NULL ;
const struct V_66 * V_67 = NULL ;
const struct V_97 * V_100 = NULL ;
char V_76 [ 32 ] , V_284 [ 32 ] ;
F_6 ( L_37 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_84 = & V_25 -> V_37 [ V_32 ] ;
V_67 = & V_84 -> V_67 ;
V_100 = & V_84 -> V_100 ;
if ( V_84 -> V_77 & V_103 )
snprintf ( V_76 , sizeof( V_76 ) , L_38 ,
V_67 -> V_83 ,
F_63 ( V_25 , V_84 ) ) ;
else
snprintf ( V_76 , sizeof( V_76 ) , L_39 ,
V_67 -> V_83 ) ;
if ( V_84 -> V_77 & V_118 )
F_179 ( V_284 , sizeof( V_284 ) , L_40 ,
V_84 -> V_106 / 1000 ) ;
else
F_179 ( V_284 , sizeof( V_284 ) , L_41 ) ;
if ( V_100 -> V_105 )
F_6 ( L_42 ,
V_67 -> V_75 ,
V_67 -> V_74 ,
V_76 ,
V_100 -> V_105 ,
V_100 -> V_104 ,
V_284 ) ;
else
F_6 ( L_43 ,
V_67 -> V_75 ,
V_67 -> V_74 ,
V_76 ,
V_100 -> V_104 ,
V_284 ) ;
}
}
bool F_180 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
F_6 ( L_44 , V_6 ) ;
return false ;
}
}
static void F_181 ( const struct V_1 * V_25 )
{
struct V_16 * V_20 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_20 -> V_62 == V_63 ) {
struct V_199 * V_200 ;
V_200 = F_182 ( V_20 -> V_147 ) ;
if ( V_200 ) {
F_6 ( L_45 ,
V_200 -> V_285 [ 0 ] ,
V_200 -> V_285 [ 1 ] ) ;
} else
F_6 ( L_46 ) ;
} else
F_6 ( L_46 ) ;
} else if ( F_21 ( V_25 -> V_26 ) ) {
F_6 ( L_47 ) ;
} else {
if ( F_23 ( V_25 -> V_26 ) )
F_6 ( L_48 ) ;
else {
if ( F_91 ( V_20 ) )
F_6 ( L_49 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_6 ( L_50 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_6 ( L_51 , F_4 ( V_25 -> V_6 ) ) ;
F_178 ( V_25 ) ;
}
static void F_183 ( const struct V_1 * V_25 )
{
F_6 ( L_52 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_178 ( V_25 ) ;
}
static int F_184 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_56 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_185 ( const struct V_1 * V_25 ,
struct V_16 * V_230 )
{
const struct V_1 * V_286 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_287 ;
if ( ! F_66 ( V_25 ) ) {
F_186 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_183 ( V_25 ) ;
return - V_56 ;
}
if ( ! V_230 -> V_229 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_286 = F_75 ( V_25 , F_1 () ) ;
if ( ! V_286 )
return - V_56 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_286 ) ;
return 0 ;
}
static int F_187 ( const struct V_1 * V_25 ,
struct V_16 * V_233 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_286 = NULL ;
const struct V_1 * V_69 ;
struct V_3 * V_146 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_56 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_287 ;
if ( ! F_66 ( V_25 ) ) {
F_186 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_183 ( V_25 ) ;
return - V_56 ;
}
V_146 = F_86 ( V_233 -> V_147 ) ;
if ( ! V_146 )
return - V_288 ;
if ( ! V_233 -> V_229 ) {
if ( V_146 -> V_4 )
return - V_287 ;
V_4 = F_30 ( V_25 ) ;
if ( F_81 ( V_4 ) )
return F_87 ( V_4 ) ;
F_16 ( V_146 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_286 = F_75 ( V_25 , F_1 () ) ;
if ( ! V_286 )
return - V_56 ;
V_69 = F_3 ( V_146 ) ;
F_16 ( V_146 -> V_4 , V_25 ) ;
F_8 ( V_69 ) ;
V_25 = NULL ;
F_17 ( false , V_286 ) ;
return 0 ;
}
static int F_188 ( const struct V_1 * V_25 ,
struct V_16 * V_234 )
{
struct V_3 * V_146 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_56 ;
if ( ! F_66 ( V_25 ) ) {
F_186 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_183 ( V_25 ) ;
return - V_56 ;
}
V_146 = F_86 ( V_234 -> V_147 ) ;
if ( ! V_146 )
return - V_288 ;
if ( V_234 -> V_229 )
return - V_56 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_39 ( const struct V_1 * V_25 ,
enum V_289 V_290 )
{
struct V_16 * V_20 ;
bool V_291 = false ;
int V_14 ;
if ( ! F_60 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_56 ;
}
if ( V_290 == V_292 )
F_54 () ;
V_20 = F_10 () ;
switch ( V_20 -> V_62 ) {
case V_138 :
V_14 = F_184 ( V_25 ) ;
break;
case V_64 :
V_14 = F_185 ( V_25 , V_20 ) ;
V_291 = true ;
break;
case V_139 :
V_14 = F_187 ( V_25 , V_20 ) ;
break;
case V_63 :
V_14 = F_188 ( V_25 , V_20 ) ;
break;
default:
F_29 ( 1 , L_28 , V_20 -> V_62 ) ;
F_13 ( V_25 ) ;
return - V_56 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_287 :
F_129 () ;
break;
default:
F_49 ( V_291 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_20 -> V_229 && V_25 != F_1 () ) )
return - V_56 ;
F_125 ( V_20 -> V_62 ) ;
F_181 ( F_1 () ) ;
F_137 ( V_20 ) ;
F_129 () ;
return 0 ;
}
static int F_189 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_293 ;
struct V_199 * V_200 ;
if ( F_20 ( ! V_3 || ! V_25 ) )
return - V_56 ;
if ( F_29 ( ! ( V_3 -> V_149 & V_178 ) ,
L_54 ) )
return - V_294 ;
if ( F_29 ( ! F_66 ( V_25 ) , L_55 ) ) {
F_183 ( V_25 ) ;
return - V_56 ;
}
V_4 = F_30 ( V_25 ) ;
if ( F_81 ( V_4 ) )
return F_87 ( V_4 ) ;
V_200 = F_111 ( V_3 ) ;
F_130 ( & V_225 ) ;
V_293 = V_200 -> V_257 ;
V_200 -> V_257 = V_4 ;
F_131 ( & V_225 ) ;
F_13 ( V_293 ) ;
return 0 ;
}
int F_190 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_54 = F_189 ( V_3 , V_25 ) ;
if ( V_54 )
return V_54 ;
F_45 ( & V_227 ) ;
return 0 ;
}
int F_191 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_54 ;
F_18 () ;
V_54 = F_189 ( V_3 , V_25 ) ;
if ( V_54 )
return V_54 ;
F_156 () ;
return 0 ;
}
void F_192 ( struct V_3 * V_3 )
{
struct V_16 * V_20 ;
if ( V_3 -> V_149 & V_178 )
V_3 -> V_149 |= V_187 |
V_236 ;
if ( ! F_94 ( V_3 ) )
V_171 ++ ;
V_20 = F_10 () ;
F_124 ( V_3 , V_20 -> V_62 ) ;
F_147 ( V_3 ) ;
}
void F_193 ( struct V_3 * V_3 )
{
struct V_3 * V_146 = NULL ;
struct V_16 * V_20 ;
V_20 = F_10 () ;
if ( ! F_94 ( V_3 ) )
V_171 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_194 ( V_3 -> V_4 , NULL ) ;
if ( V_20 )
V_146 = F_86 ( V_20 -> V_147 ) ;
if ( ! V_146 || V_146 != V_3 )
return;
V_20 -> V_147 = V_251 ;
V_20 -> V_271 = V_267 ;
}
int F_195 ( int V_278 )
{
if ( V_278 >= 5150 && V_278 <= 5250 )
return 0 ;
if ( V_278 > 5250 && V_278 <= 5350 )
return 1 ;
if ( V_278 > 5350 && V_278 <= 5470 )
return 2 ;
if ( V_278 > 5470 && V_278 <= 5725 )
return 3 ;
if ( V_278 > 5725 && V_278 <= 5825 )
return 4 ;
return - V_56 ;
}
bool F_196 ( void )
{
return V_262 ;
}
bool F_197 ( struct V_3 * V_3 )
{
const struct V_1 * V_4 = NULL ;
const struct V_1 * V_11 = NULL ;
bool V_295 = false ;
F_142 () ;
V_4 = F_143 ( V_2 ) ;
V_11 = F_143 ( V_3 -> V_4 ) ;
if ( ! V_11 ) {
if ( V_4 -> V_6 == V_9 )
V_295 = true ;
F_144 () ;
return V_295 ;
}
if ( V_4 -> V_6 == V_11 -> V_6 &&
V_11 -> V_6 == V_9 )
V_295 = true ;
F_144 () ;
return V_295 ;
}
void F_198 ( struct V_3 * V_3 ,
struct V_197 * V_198 ,
enum V_296 V_157 ,
enum V_297 V_298 )
{
struct V_199 * V_200 ;
F_18 () ;
if ( F_20 ( ! F_199 ( V_198 ) ) )
return;
F_103 (rdev, &cfg80211_rdev_list, list) {
if ( V_3 == & V_200 -> V_3 )
continue;
if ( ! F_141 ( V_3 , & V_200 -> V_3 ) )
continue;
if ( ! F_200 ( & V_200 -> V_3 ,
V_198 -> V_141 -> V_130 ) )
continue;
F_201 ( & V_200 -> V_3 , V_198 , V_157 ) ;
if ( V_298 == V_299 ||
V_298 == V_300 )
F_202 ( V_200 ) ;
F_203 ( V_200 , V_198 , V_298 , NULL , V_35 ) ;
}
}
int T_6 F_204 ( void )
{
int V_301 = 0 ;
V_57 = F_205 ( L_56 , 0 , NULL , 0 ) ;
if ( F_81 ( V_57 ) )
return F_87 ( V_57 ) ;
F_206 ( & V_225 ) ;
F_206 ( & V_255 ) ;
F_206 ( & V_261 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_301 = F_161 ( V_23 -> V_26 ) ;
if ( V_301 ) {
if ( V_301 == - V_36 ) {
F_207 ( V_57 ) ;
return V_301 ;
}
F_186 ( L_57 ) ;
}
if ( ! F_21 ( V_273 ) )
F_162 ( V_273 ,
V_277 ) ;
return 0 ;
}
void F_208 ( void )
{
struct V_16 * V_250 , * V_69 ;
struct V_182 * V_182 , * V_275 ;
F_209 ( & V_227 ) ;
F_52 () ;
F_53 ( & V_221 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_41 () ;
F_210 ( & V_57 -> V_13 , true ) ;
F_207 ( V_57 ) ;
F_154 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_182 -> V_43 ) ;
F_13 ( V_182 ) ;
}
F_154 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_182 -> V_43 ) ;
F_13 ( V_182 ) ;
}
F_154 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_250 -> V_43 ) ;
F_13 ( V_250 ) ;
}
}
