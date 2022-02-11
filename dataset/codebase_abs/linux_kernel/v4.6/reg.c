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
T_1 V_86 , T_1 V_87 )
{
T_1 V_75 , V_74 ;
V_75 = V_86 - ( V_87 / 2 ) ;
V_74 = V_86 + ( V_87 / 2 ) ;
if ( V_75 >= V_67 -> V_75 &&
V_74 <= V_67 -> V_74 )
return true ;
return false ;
}
static bool F_68 ( const struct V_66 * V_67 ,
T_1 V_88 )
{
#define F_69 1000000
T_1 V_89 = V_88 > 45 * F_69 ?
10 * F_69 : 2 * F_69 ;
if ( abs ( V_88 - V_67 -> V_75 ) <= V_89 )
return true ;
if ( abs ( V_88 - V_67 -> V_74 ) <= V_89 )
return true ;
return false ;
#undef F_69
}
static enum V_5
F_70 ( const enum V_5 V_90 ,
const enum V_5 V_91 )
{
if ( V_90 != V_91 )
return V_7 ;
return V_90 ;
}
static int F_71 ( const struct V_1 * V_92 ,
const struct V_1 * V_93 ,
const struct V_34 * V_94 ,
const struct V_34 * V_95 ,
struct V_34 * V_96 )
{
const struct V_66 * V_97 , * V_98 ;
struct V_66 * V_67 ;
const struct V_99 * V_100 , * V_101 ;
struct V_99 * V_102 ;
T_1 V_82 , V_103 , V_104 ;
V_97 = & V_94 -> V_67 ;
V_98 = & V_95 -> V_67 ;
V_67 = & V_96 -> V_67 ;
V_100 = & V_94 -> V_102 ;
V_101 = & V_95 -> V_102 ;
V_102 = & V_96 -> V_102 ;
V_67 -> V_75 = F_72 ( V_97 -> V_75 ,
V_98 -> V_75 ) ;
V_67 -> V_74 = F_73 ( V_97 -> V_74 ,
V_98 -> V_74 ) ;
V_103 = V_97 -> V_83 ;
V_104 = V_98 -> V_83 ;
if ( V_94 -> V_77 & V_105 )
V_103 = F_63 ( V_92 , V_94 ) ;
if ( V_95 -> V_77 & V_105 )
V_104 = F_63 ( V_93 , V_95 ) ;
V_67 -> V_83 = F_73 ( V_103 , V_104 ) ;
V_96 -> V_77 = V_94 -> V_77 | V_95 -> V_77 ;
if ( ( V_94 -> V_77 & V_105 ) &&
( V_95 -> V_77 & V_105 ) )
V_96 -> V_77 |= V_105 ;
else
V_96 -> V_77 &= ~ V_105 ;
V_82 = V_67 -> V_74 - V_67 -> V_75 ;
if ( V_67 -> V_83 > V_82 )
V_67 -> V_83 = V_82 ;
V_102 -> V_106 = F_73 ( V_100 -> V_106 ,
V_101 -> V_106 ) ;
V_102 -> V_107 = F_73 ( V_100 -> V_107 ,
V_101 -> V_107 ) ;
V_96 -> V_108 = F_72 ( V_94 -> V_108 ,
V_95 -> V_108 ) ;
if ( ! F_65 ( V_96 ) )
return - V_56 ;
return 0 ;
}
static bool F_74 ( struct V_34 * V_109 ,
struct V_34 * V_110 )
{
if ( V_109 -> V_77 != V_110 -> V_77 )
return false ;
if ( ( V_109 -> V_102 . V_107 >
V_110 -> V_102 . V_107 ) ||
V_109 -> V_102 . V_106 > V_110 -> V_102 . V_106 )
return false ;
if ( V_109 -> V_67 . V_75 > V_110 -> V_67 . V_75 ||
V_109 -> V_67 . V_74 < V_110 -> V_67 . V_74 )
return false ;
if ( V_109 -> V_67 . V_83 <
V_110 -> V_67 . V_83 )
return false ;
return true ;
}
static void F_75 ( struct V_34 * V_65 ,
struct V_34 * V_37 , T_1 * V_111 )
{
struct V_34 * V_112 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < * V_111 ; V_32 ++ ) {
V_112 = & V_37 [ V_32 ] ;
if ( F_74 ( V_112 , V_65 ) )
return;
if ( F_74 ( V_65 , V_112 ) ) {
memcpy ( V_112 , V_65 , sizeof( * V_65 ) ) ;
return;
}
}
memcpy ( & V_37 [ * V_111 ] , V_65 , sizeof( * V_65 ) ) ;
( * V_111 ) ++ ;
}
static struct V_1 *
F_76 ( const struct V_1 * V_92 ,
const struct V_1 * V_93 )
{
int V_14 , V_31 ;
unsigned int V_113 , V_114 ;
unsigned int V_115 = 0 ;
const struct V_34 * V_94 , * V_95 ;
struct V_34 V_96 ;
struct V_1 * V_25 ;
if ( ! V_92 || ! V_93 )
return NULL ;
for ( V_113 = 0 ; V_113 < V_92 -> V_33 ; V_113 ++ ) {
V_94 = & V_92 -> V_37 [ V_113 ] ;
for ( V_114 = 0 ; V_114 < V_93 -> V_33 ; V_114 ++ ) {
V_95 = & V_93 -> V_37 [ V_114 ] ;
if ( ! F_71 ( V_92 , V_93 , V_94 , V_95 ,
& V_96 ) )
V_115 ++ ;
}
}
if ( ! V_115 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_115 * sizeof( struct V_34 ) ;
V_25 = F_31 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_113 = 0 ; V_113 < V_92 -> V_33 ; V_113 ++ ) {
V_94 = & V_92 -> V_37 [ V_113 ] ;
for ( V_114 = 0 ; V_114 < V_93 -> V_33 ; V_114 ++ ) {
V_95 = & V_93 -> V_37 [ V_114 ] ;
V_14 = F_71 ( V_92 , V_93 , V_94 , V_95 ,
& V_96 ) ;
if ( V_14 )
continue;
F_75 ( & V_96 , V_25 -> V_37 ,
& V_25 -> V_33 ) ;
}
}
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_70 ( V_92 -> V_6 ,
V_93 -> V_6 ) ;
return V_25 ;
}
static T_1 F_77 ( T_1 V_116 )
{
T_1 V_117 = 0 ;
if ( V_116 & V_118 )
V_117 |= V_119 ;
if ( V_116 & V_120 )
V_117 |= V_121 ;
if ( V_116 & V_122 )
V_117 |= V_123 ;
if ( V_116 & V_124 )
V_117 |= V_125 ;
if ( V_116 & V_126 )
V_117 |= V_127 ;
if ( V_116 & V_80 )
V_117 |= V_128 ;
if ( V_116 & V_81 )
V_117 |= V_129 ;
if ( V_116 & V_79 )
V_117 |= V_130 ;
if ( V_116 & V_78 )
V_117 |= V_131 ;
return V_117 ;
}
static const struct V_34 *
F_78 ( T_1 V_132 ,
const struct V_1 * V_4 , T_1 V_76 )
{
int V_32 ;
bool V_133 = false ;
bool V_134 = false ;
if ( ! V_4 )
return F_32 ( - V_56 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_135 ;
const struct V_66 * V_136 = NULL ;
V_135 = & V_4 -> V_37 [ V_32 ] ;
V_136 = & V_135 -> V_67 ;
if ( ! V_133 )
V_133 = F_68 ( V_136 , V_132 ) ;
V_134 = F_67 ( V_136 , V_132 , V_76 ) ;
if ( V_133 && V_134 )
return V_135 ;
}
if ( ! V_133 )
return F_32 ( - V_137 ) ;
return F_32 ( - V_56 ) ;
}
static const struct V_34 *
F_79 ( struct V_3 * V_3 , T_1 V_132 , T_1 V_138 )
{
const struct V_1 * V_4 = F_61 ( V_3 ) ;
const struct V_34 * V_84 = NULL ;
T_1 V_76 ;
for ( V_76 = F_80 ( 20 ) ; V_76 >= V_138 ; V_76 = V_76 / 2 ) {
V_84 = F_78 ( V_132 , V_4 , V_76 ) ;
if ( ! F_81 ( V_84 ) )
return V_84 ;
}
return V_84 ;
}
const struct V_34 * F_82 ( struct V_3 * V_3 ,
T_1 V_132 )
{
return F_79 ( V_3 , V_132 , F_80 ( 20 ) ) ;
}
const char * F_83 ( enum V_139 V_62 )
{
switch ( V_62 ) {
case V_140 :
return L_14 ;
case V_64 :
return L_15 ;
case V_141 :
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
const struct V_142 * V_143 )
{
const struct V_66 * V_67 = NULL ;
T_1 V_83 , V_144 = 0 ;
V_67 = & V_84 -> V_67 ;
V_83 = V_67 -> V_83 ;
if ( V_84 -> V_77 & V_105 )
V_83 = F_63 ( V_4 , V_84 ) ;
if ( ! F_67 ( V_67 , F_80 ( V_143 -> V_132 ) ,
F_80 ( 10 ) ) )
V_144 |= V_145 ;
if ( ! F_67 ( V_67 , F_80 ( V_143 -> V_132 ) ,
F_80 ( 20 ) ) )
V_144 |= V_146 ;
if ( V_83 < F_80 ( 10 ) )
V_144 |= V_145 ;
if ( V_83 < F_80 ( 20 ) )
V_144 |= V_146 ;
if ( V_83 < F_80 ( 40 ) )
V_144 |= V_147 ;
if ( V_83 < F_80 ( 80 ) )
V_144 |= V_130 ;
if ( V_83 < F_80 ( 160 ) )
V_144 |= V_131 ;
return V_144 ;
}
static void F_85 ( struct V_3 * V_3 ,
enum V_139 V_62 ,
struct V_142 * V_143 )
{
T_1 V_77 , V_144 = 0 ;
const struct V_34 * V_84 = NULL ;
const struct V_99 * V_102 = NULL ;
struct V_3 * V_148 = NULL ;
struct V_16 * V_20 = F_10 () ;
const struct V_1 * V_4 ;
V_148 = F_86 ( V_20 -> V_149 ) ;
V_77 = V_143 -> V_150 ;
V_84 = F_82 ( V_3 , F_80 ( V_143 -> V_132 ) ) ;
if ( F_81 ( V_84 ) ) {
if ( V_62 == V_63 &&
F_87 ( V_84 ) == - V_137 )
return;
if ( V_20 -> V_62 == V_141 &&
V_148 && V_148 == V_3 &&
V_148 -> V_151 & V_152 ) {
F_6 ( L_19 ,
V_143 -> V_132 ) ;
V_143 -> V_150 |= V_153 ;
V_143 -> V_77 = V_143 -> V_150 ;
} else {
F_6 ( L_20 ,
V_143 -> V_132 ) ;
V_143 -> V_77 |= V_153 ;
}
return;
}
V_4 = F_61 ( V_3 ) ;
V_102 = & V_84 -> V_102 ;
V_144 = F_84 ( V_4 , V_84 , V_143 ) ;
if ( V_20 -> V_62 == V_141 &&
V_148 && V_148 == V_3 &&
V_148 -> V_151 & V_152 ) {
V_143 -> V_77 = V_143 -> V_150 =
F_77 ( V_84 -> V_77 ) | V_144 ;
V_143 -> V_107 = V_143 -> V_154 =
( int ) F_88 ( V_102 -> V_107 ) ;
V_143 -> V_155 = V_143 -> V_156 = V_143 -> V_157 =
( int ) F_89 ( V_102 -> V_106 ) ;
if ( V_143 -> V_77 & V_121 ) {
V_143 -> V_108 = V_158 ;
if ( V_84 -> V_108 )
V_143 -> V_108 = V_84 -> V_108 ;
}
return;
}
V_143 -> V_159 = V_160 ;
V_143 -> V_161 = V_162 ;
V_143 -> V_163 = false ;
V_143 -> V_77 = V_77 | V_144 | F_77 ( V_84 -> V_77 ) ;
V_143 -> V_107 =
F_64 ( int , V_143 -> V_154 ,
F_88 ( V_102 -> V_107 ) ) ;
V_143 -> V_155 = ( int ) F_89 ( V_102 -> V_106 ) ;
if ( V_143 -> V_77 & V_121 ) {
if ( V_84 -> V_108 )
V_143 -> V_108 = V_84 -> V_108 ;
else
V_143 -> V_108 = V_158 ;
}
if ( V_143 -> V_157 ) {
if ( V_62 == V_63 &&
V_3 -> V_151 & V_164 )
V_143 -> V_156 = V_143 -> V_155 ;
else
V_143 -> V_156 = F_73 ( V_143 -> V_157 ,
V_143 -> V_155 ) ;
} else
V_143 -> V_156 = V_143 -> V_155 ;
}
static void F_90 ( struct V_3 * V_3 ,
enum V_139 V_62 ,
struct V_165 * V_166 )
{
unsigned int V_32 ;
if ( ! V_166 )
return;
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ )
F_85 ( V_3 , V_62 , & V_166 -> V_168 [ V_32 ] ) ;
}
static bool F_91 ( struct V_16 * V_18 )
{
if ( V_18 -> V_62 != V_64 )
return false ;
return V_18 -> V_169 == V_170 ;
}
bool F_92 ( void )
{
return F_91 ( F_10 () ) ;
}
static enum V_171
F_93 ( struct V_16 * V_172 )
{
struct V_16 * V_20 = F_10 () ;
if ( ! V_173 )
return V_174 ;
if ( F_91 ( V_20 ) &&
! F_27 ( V_172 -> V_26 ) )
return V_175 ;
return V_176 ;
}
static bool F_94 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_177 & V_178 ) ;
}
static enum V_171
F_93 ( struct V_16 * V_172 )
{
return V_174 ;
}
static bool F_94 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_95 ( struct V_3 * V_3 )
{
if ( V_3 -> V_151 & V_152 &&
! ( V_3 -> V_151 & V_179 ) )
return true ;
return false ;
}
static bool F_96 ( struct V_3 * V_3 ,
enum V_139 V_62 )
{
struct V_16 * V_20 = F_10 () ;
if ( V_3 -> V_151 & V_180 )
return true ;
if ( ! V_20 ) {
F_6 ( L_21 ,
F_83 ( V_62 ) ) ;
return true ;
}
if ( V_62 == V_140 &&
V_3 -> V_151 & V_179 ) {
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
const struct V_1 * V_181 = F_1 () ;
const struct V_1 * V_182 = F_3 ( V_3 ) ;
struct V_16 * V_20 = F_10 () ;
if ( F_21 ( V_181 -> V_26 ) || ( V_182 && F_21 ( V_182 -> V_26 ) ) )
return true ;
if ( V_20 && V_20 -> V_62 != V_63 &&
V_3 -> V_151 & V_179 )
return true ;
return false ;
}
static void F_98 ( struct V_3 * V_3 , unsigned int V_183 ,
struct V_184 * V_184 )
{
struct V_165 * V_166 ;
struct V_142 * V_143 ;
bool V_185 = false ;
struct V_142 V_186 ;
V_166 = V_3 -> V_187 [ V_184 -> V_143 . V_188 ] ;
V_143 = & V_166 -> V_168 [ V_183 ] ;
if ( F_99 ( V_143 -> V_132 != V_184 -> V_143 . V_132 ) )
return;
if ( V_143 -> V_163 )
return;
V_143 -> V_163 = true ;
if ( ! F_97 ( V_3 ) )
return;
if ( V_3 -> V_151 & V_189 )
return;
V_186 . V_132 = V_143 -> V_132 ;
V_186 . V_77 = V_143 -> V_77 ;
if ( V_143 -> V_77 & V_119 ) {
V_143 -> V_77 &= ~ V_119 ;
V_185 = true ;
}
if ( V_185 )
F_100 ( V_3 , & V_186 , V_143 ) ;
}
static void F_101 ( struct V_3 * V_3 ,
struct V_184 * V_184 )
{
unsigned int V_32 ;
struct V_165 * V_166 ;
if ( ! V_3 -> V_187 [ V_184 -> V_143 . V_188 ] )
return;
V_166 = V_3 -> V_187 [ V_184 -> V_143 . V_188 ] ;
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ )
F_98 ( V_3 , V_32 , V_184 ) ;
}
static void F_102 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_165 * V_166 ;
struct V_184 * V_184 ;
F_103 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_187 [ V_184 -> V_143 . V_188 ] )
continue;
V_166 = V_3 -> V_187 [ V_184 -> V_143 . V_188 ] ;
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ )
F_98 ( V_3 , V_32 , V_184 ) ;
}
}
static void F_104 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_102 ( V_3 ) ;
}
static bool F_105 ( struct V_142 * V_143 )
{
if ( ! V_143 )
return false ;
if ( V_143 -> V_77 & V_153 )
return false ;
if ( ( V_143 -> V_77 & V_147 ) == V_147 )
return false ;
return true ;
}
static void F_106 ( struct V_3 * V_3 ,
struct V_142 * V_190 )
{
struct V_165 * V_166 = V_3 -> V_187 [ V_190 -> V_188 ] ;
struct V_142 * V_191 = NULL , * V_192 = NULL ;
unsigned int V_32 ;
if ( ! F_105 ( V_190 ) ) {
V_190 -> V_77 |= V_147 ;
return;
}
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ ) {
struct V_142 * V_193 = & V_166 -> V_168 [ V_32 ] ;
if ( V_193 -> V_132 == ( V_190 -> V_132 - 20 ) )
V_191 = V_193 ;
if ( V_193 -> V_132 == ( V_190 -> V_132 + 20 ) )
V_192 = V_193 ;
}
if ( ! F_105 ( V_191 ) )
V_190 -> V_77 |= V_128 ;
else
V_190 -> V_77 &= ~ V_128 ;
if ( ! F_105 ( V_192 ) )
V_190 -> V_77 |= V_129 ;
else
V_190 -> V_77 &= ~ V_129 ;
}
static void F_107 ( struct V_3 * V_3 ,
struct V_165 * V_166 )
{
unsigned int V_32 ;
if ( ! V_166 )
return;
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ )
F_106 ( V_3 , & V_166 -> V_168 [ V_32 ] ) ;
}
static void F_108 ( struct V_3 * V_3 )
{
enum V_194 V_188 ;
if ( ! V_3 )
return;
for ( V_188 = 0 ; V_188 < V_195 ; V_188 ++ )
F_107 ( V_3 , V_3 -> V_187 [ V_188 ] ) ;
}
static void F_109 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_196 )
V_3 -> V_196 ( V_3 , V_18 ) ;
}
static bool F_110 ( struct V_3 * V_3 , struct V_197 * V_198 )
{
struct V_199 V_200 ;
struct V_201 * V_202 = F_111 ( V_3 ) ;
enum V_203 V_204 ;
F_112 ( V_198 ) ;
V_204 = V_198 -> V_204 ;
if ( ! V_198 -> V_205 || ! F_113 ( V_198 -> V_205 ) )
goto V_206;
switch ( V_204 ) {
case V_207 :
case V_208 :
if ( ! V_198 -> V_209 )
goto V_206;
V_200 = V_198 -> V_200 ;
break;
case V_210 :
if ( ! V_198 -> V_211 )
goto V_206;
V_200 = V_198 -> V_200 ;
break;
case V_212 :
case V_213 :
if ( ! V_198 -> V_214 ||
! V_198 -> V_214 -> V_215 . V_190 )
goto V_206;
if ( ! V_202 -> V_216 -> V_217 ||
F_114 ( V_202 , V_198 , & V_200 ) )
F_115 ( & V_200 ,
V_198 -> V_214 -> V_215 . V_190 ,
V_218 ) ;
break;
case V_219 :
case V_220 :
case V_221 :
break;
default:
F_20 ( 1 ) ;
break;
}
F_116 ( V_198 ) ;
switch ( V_204 ) {
case V_207 :
case V_208 :
case V_210 :
return F_117 ( V_3 , & V_200 , V_204 ) ;
case V_212 :
case V_213 :
return F_118 ( V_3 , & V_200 ,
V_153 ) ;
default:
break;
}
return true ;
V_206:
F_116 ( V_198 ) ;
return true ;
}
static void F_119 ( struct V_3 * V_3 )
{
struct V_197 * V_198 ;
struct V_201 * V_202 = F_111 ( V_3 ) ;
F_18 () ;
F_103 (wdev, &rdev->wdev_list, list)
if ( ! F_110 ( V_3 , V_198 ) )
F_120 ( V_202 , V_198 ) ;
}
static void F_121 ( struct V_38 * V_39 )
{
struct V_201 * V_202 ;
F_6 ( L_24 ) ;
F_34 () ;
F_103 (rdev, &cfg80211_rdev_list, list)
if ( ! ( V_202 -> V_3 . V_151 &
V_222 ) )
F_119 ( & V_202 -> V_3 ) ;
F_41 () ;
}
static void F_122 ( void )
{
F_123 ( V_60 ,
& V_223 ,
F_58 ( V_224 ) ) ;
}
static void F_124 ( struct V_3 * V_3 ,
enum V_139 V_62 )
{
enum V_194 V_188 ;
struct V_16 * V_20 = F_10 () ;
if ( F_96 ( V_3 , V_62 ) ) {
if ( V_62 == V_140 &&
V_3 -> V_151 & V_179 )
F_109 ( V_3 , V_20 ) ;
return;
}
V_20 -> V_6 = F_1 () -> V_6 ;
for ( V_188 = 0 ; V_188 < V_195 ; V_188 ++ )
F_90 ( V_3 , V_62 , V_3 -> V_187 [ V_188 ] ) ;
F_104 ( V_3 ) ;
F_108 ( V_3 ) ;
F_109 ( V_3 , V_20 ) ;
}
static void F_125 ( enum V_139 V_62 )
{
struct V_201 * V_202 ;
struct V_3 * V_3 ;
F_18 () ;
F_103 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_202 -> V_3 ;
F_124 ( V_3 , V_62 ) ;
}
F_122 () ;
}
static void F_126 ( struct V_3 * V_3 ,
struct V_142 * V_143 ,
const struct V_1 * V_4 )
{
T_1 V_144 = 0 ;
const struct V_34 * V_84 = NULL ;
const struct V_99 * V_102 = NULL ;
T_1 V_76 ;
for ( V_76 = F_80 ( 20 ) ; V_76 >= F_80 ( 5 ) ; V_76 = V_76 / 2 ) {
V_84 = F_78 ( F_80 ( V_143 -> V_132 ) ,
V_4 , V_76 ) ;
if ( ! F_81 ( V_84 ) )
break;
}
if ( F_81 ( V_84 ) ) {
F_6 ( L_25 ,
V_143 -> V_132 ) ;
if ( V_3 -> V_151 & V_180 ) {
V_143 -> V_77 |= V_153 ;
} else {
V_143 -> V_150 |= V_153 ;
V_143 -> V_77 = V_143 -> V_150 ;
}
return;
}
V_102 = & V_84 -> V_102 ;
V_144 = F_84 ( V_4 , V_84 , V_143 ) ;
V_143 -> V_161 = V_162 ;
V_143 -> V_159 = V_160 ;
V_143 -> V_163 = false ;
if ( V_3 -> V_151 & V_180 )
V_143 -> V_77 = V_143 -> V_150 | V_144 |
F_77 ( V_84 -> V_77 ) ;
else
V_143 -> V_77 |= F_77 ( V_84 -> V_77 ) | V_144 ;
V_143 -> V_107 = ( int ) F_88 ( V_102 -> V_107 ) ;
V_143 -> V_155 = V_143 -> V_156 =
( int ) F_89 ( V_102 -> V_106 ) ;
if ( V_143 -> V_77 & V_121 ) {
if ( V_84 -> V_108 )
V_143 -> V_108 = V_84 -> V_108 ;
else
V_143 -> V_108 = V_158 ;
}
V_143 -> V_156 = V_143 -> V_155 ;
}
static void F_127 ( struct V_3 * V_3 ,
struct V_165 * V_166 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_166 )
return;
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ )
F_126 ( V_3 , & V_166 -> V_168 [ V_32 ] , V_4 ) ;
}
void F_128 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_194 V_188 ;
unsigned int V_225 = 0 ;
F_29 ( ! ( V_3 -> V_151 & V_179 ) ,
L_26 ) ;
V_3 -> V_151 |= V_179 ;
for ( V_188 = 0 ; V_188 < V_195 ; V_188 ++ ) {
if ( ! V_3 -> V_187 [ V_188 ] )
continue;
F_127 ( V_3 , V_3 -> V_187 [ V_188 ] , V_4 ) ;
V_225 ++ ;
}
F_20 ( ! V_225 ) ;
}
static void F_129 ( void )
{
bool V_226 = false ;
struct V_16 * V_20 = F_10 () ;
V_20 -> V_61 = true ;
F_130 ( & V_227 ) ;
if ( ! F_36 ( & V_228 ) )
V_226 = true ;
F_131 ( & V_227 ) ;
F_50 () ;
if ( V_226 )
F_45 ( & V_229 ) ;
}
static enum V_171
F_132 ( struct V_16 * V_230 )
{
if ( F_59 ( V_230 ) ) {
V_230 -> V_231 = false ;
V_230 -> V_61 = false ;
F_15 ( V_230 ) ;
return V_176 ;
}
return V_174 ;
}
static enum V_171
F_133 ( struct V_16 * V_232 )
{
struct V_16 * V_20 = F_10 () ;
if ( F_91 ( V_232 ) )
return F_93 ( V_232 ) ;
if ( F_91 ( V_20 ) )
return V_174 ;
if ( V_20 -> V_62 == V_63 )
return V_233 ;
if ( V_20 -> V_62 == V_64 &&
V_20 -> V_231 )
return V_174 ;
if ( ( V_20 -> V_62 == V_140 ||
V_20 -> V_62 == V_141 ||
V_20 -> V_62 == V_64 ) &&
F_27 ( V_20 -> V_26 ) )
return V_174 ;
if ( ! F_27 ( V_232 -> V_26 ) )
return V_175 ;
return V_176 ;
}
static enum V_171
F_134 ( struct V_16 * V_232 )
{
enum V_171 V_234 ;
V_234 = F_133 ( V_232 ) ;
if ( V_234 == V_174 ||
V_234 == V_175 )
return V_174 ;
V_232 -> V_231 = V_234 == V_233 ;
V_232 -> V_61 = false ;
if ( F_59 ( V_232 ) ) {
F_15 ( V_232 ) ;
V_29 [ 0 ] = V_232 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_232 -> V_26 [ 1 ] ;
return V_176 ;
}
return V_174 ;
}
static enum V_171
F_135 ( struct V_16 * V_235 )
{
struct V_16 * V_20 = F_10 () ;
if ( V_20 -> V_62 == V_140 ) {
if ( F_27 ( V_235 -> V_26 ) )
return V_176 ;
return V_175 ;
}
if ( V_20 -> V_62 == V_141 &&
! F_27 ( V_235 -> V_26 ) )
return V_175 ;
return V_233 ;
}
static enum V_171
F_136 ( struct V_3 * V_3 ,
struct V_16 * V_235 )
{
const struct V_1 * V_4 , * V_69 ;
enum V_171 V_234 ;
V_234 = F_135 ( V_235 ) ;
switch ( V_234 ) {
case V_176 :
break;
case V_174 :
return V_174 ;
case V_233 :
case V_175 :
V_4 = F_30 ( F_1 () ) ;
if ( F_81 ( V_4 ) )
return V_174 ;
V_69 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_69 ) ;
}
V_235 -> V_231 = V_234 == V_233 ;
V_235 -> V_61 = false ;
if ( V_234 == V_175 ) {
F_137 ( V_235 ) ;
F_15 ( V_235 ) ;
F_129 () ;
return V_175 ;
}
if ( F_59 ( V_235 ) ) {
F_15 ( V_235 ) ;
return V_176 ;
}
return V_174 ;
}
static enum V_171
F_138 ( struct V_3 * V_3 ,
struct V_16 * V_236 )
{
struct V_3 * V_237 = NULL ;
struct V_16 * V_20 = F_10 () ;
if ( F_91 ( V_20 ) ) {
if ( F_27 ( V_236 -> V_26 ) )
return V_174 ;
return V_175 ;
} else {
if ( V_3 -> V_151 & V_238 )
return V_174 ;
}
if ( F_139 ( ! F_25 ( V_236 -> V_26 ) ) )
return - V_56 ;
if ( V_20 -> V_62 != V_63 )
return V_176 ;
V_237 = F_86 ( V_20 -> V_149 ) ;
if ( V_237 != V_3 ) {
if ( F_27 ( V_236 -> V_26 ) )
return V_174 ;
return V_175 ;
}
if ( F_27 ( V_236 -> V_26 ) )
return V_176 ;
return V_175 ;
}
static enum V_171
F_140 ( struct V_3 * V_3 ,
struct V_16 * V_236 )
{
enum V_171 V_234 ;
V_234 = F_138 ( V_3 , V_236 ) ;
switch ( V_234 ) {
case V_176 :
break;
case V_174 :
return V_174 ;
case V_175 :
F_12 ( V_236 ) ;
return V_175 ;
case V_233 :
F_47 ( 1 , L_27 ) ;
return V_174 ;
}
V_236 -> V_231 = false ;
V_236 -> V_61 = false ;
if ( F_59 ( V_236 ) ) {
F_15 ( V_236 ) ;
return V_176 ;
}
return V_174 ;
}
static void F_141 ( struct V_16 * V_239 )
{
struct V_3 * V_3 = NULL ;
enum V_171 V_234 ;
if ( V_239 -> V_149 != V_240 )
V_3 = F_86 ( V_239 -> V_149 ) ;
switch ( V_239 -> V_62 ) {
case V_140 :
V_234 = F_132 ( V_239 ) ;
break;
case V_64 :
V_234 = F_134 ( V_239 ) ;
break;
case V_141 :
if ( ! V_3 )
goto V_241;
V_234 = F_136 ( V_3 , V_239 ) ;
break;
case V_63 :
if ( ! V_3 )
goto V_241;
V_234 = F_140 ( V_3 , V_239 ) ;
break;
default:
F_29 ( 1 , L_28 , V_239 -> V_62 ) ;
goto V_241;
}
if ( V_234 == V_174 )
goto V_241;
F_29 ( V_234 != V_176 && V_234 != V_175 ,
L_29 , V_234 ) ;
if ( V_234 == V_175 && V_3 &&
V_3 -> V_151 & V_152 ) {
F_124 ( V_3 , V_239 -> V_62 ) ;
F_122 () ;
}
return;
V_241:
F_12 ( V_239 ) ;
}
static bool F_142 ( void )
{
struct V_201 * V_202 ;
struct V_3 * V_3 ;
bool V_242 = false ;
F_18 () ;
F_103 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_202 -> V_3 ;
if ( V_3 -> V_151 & V_180 )
V_242 = true ;
else
return false ;
}
return V_242 ;
}
static void F_143 ( void )
{
struct V_16 * V_239 , * V_20 ;
V_20 = F_10 () ;
if ( V_20 && ! V_20 -> V_61 ) {
F_141 ( V_20 ) ;
return;
}
F_130 ( & V_227 ) ;
if ( F_36 ( & V_228 ) ) {
F_131 ( & V_227 ) ;
return;
}
V_239 = F_37 ( & V_228 ,
struct V_16 ,
V_43 ) ;
F_144 ( & V_239 -> V_43 ) ;
F_131 ( & V_227 ) ;
if ( F_142 () ) {
F_12 ( V_239 ) ;
return;
}
F_141 ( V_239 ) ;
V_20 = F_10 () ;
F_130 ( & V_227 ) ;
if ( ! F_36 ( & V_228 ) && V_20 && V_20 -> V_61 )
F_45 ( & V_229 ) ;
F_131 ( & V_227 ) ;
}
static void F_145 ( void )
{
struct V_201 * V_202 ;
struct V_184 * V_243 , * V_69 ;
F_146 ( & V_244 ) ;
F_147 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_144 ( & V_243 -> V_43 ) ;
F_103 (rdev, &cfg80211_rdev_list, list)
F_101 ( & V_202 -> V_3 , V_243 ) ;
F_44 ( & V_243 -> V_43 , & V_245 ) ;
}
F_148 ( & V_244 ) ;
}
static void F_149 ( void )
{
struct V_201 * V_202 ;
struct V_3 * V_3 ;
const struct V_1 * V_69 ;
const struct V_1 * V_4 ;
enum V_194 V_188 ;
struct V_16 V_18 = {} ;
F_103 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_202 -> V_3 ;
F_130 ( & V_227 ) ;
V_4 = V_202 -> V_246 ;
V_202 -> V_246 = NULL ;
F_131 ( & V_227 ) ;
if ( V_4 == NULL )
continue;
V_69 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_69 ) ;
for ( V_188 = 0 ; V_188 < V_195 ; V_188 ++ )
F_127 ( V_3 , V_3 -> V_187 [ V_188 ] , V_4 ) ;
F_108 ( V_3 ) ;
V_18 . V_149 = F_150 ( V_3 ) ;
V_18 . V_26 [ 0 ] = V_4 -> V_26 [ 0 ] ;
V_18 . V_26 [ 1 ] = V_4 -> V_26 [ 1 ] ;
V_18 . V_62 = V_141 ;
F_151 ( & V_18 ) ;
}
F_122 () ;
}
static void F_152 ( struct V_38 * V_39 )
{
F_34 () ;
F_143 () ;
F_145 () ;
F_149 () ;
F_41 () ;
}
static void F_153 ( struct V_16 * V_18 )
{
V_18 -> V_26 [ 0 ] = toupper ( V_18 -> V_26 [ 0 ] ) ;
V_18 -> V_26 [ 1 ] = toupper ( V_18 -> V_26 [ 1 ] ) ;
F_130 ( & V_227 ) ;
F_44 ( & V_18 -> V_43 , & V_228 ) ;
F_131 ( & V_227 ) ;
F_45 ( & V_229 ) ;
}
static int F_154 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_140 ;
F_153 ( V_18 ) ;
return 0 ;
}
int F_155 ( const char * V_26 ,
enum V_247 V_169 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_56 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_149 = V_240 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_64 ;
V_18 -> V_169 = V_169 ;
F_54 () ;
F_153 ( V_18 ) ;
return 0 ;
}
int F_156 ( bool V_248 , T_1 V_249 )
{
F_130 ( & V_250 ) ;
V_251 = V_248 ;
if ( V_251 ) {
if ( ! V_252 )
V_252 = V_249 ;
} else {
V_252 = 0 ;
}
F_131 ( & V_250 ) ;
if ( ! V_248 )
F_122 () ;
return 0 ;
}
void F_157 ( T_1 V_249 )
{
F_130 ( & V_250 ) ;
if ( V_252 != V_249 ) {
F_131 ( & V_250 ) ;
return;
}
V_251 = false ;
V_252 = 0 ;
F_131 ( & V_250 ) ;
F_122 () ;
}
int F_158 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_56 ;
V_3 -> V_151 &= ~ V_179 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_149 = F_150 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_141 ;
F_54 () ;
F_153 ( V_18 ) ;
return 0 ;
}
void F_159 ( struct V_3 * V_3 , enum V_194 V_188 ,
const T_3 * V_253 , T_3 V_254 )
{
char V_26 [ 2 ] ;
enum V_255 V_53 = V_256 ;
struct V_16 * V_18 = NULL , * V_20 ;
if ( V_254 & 0x01 )
return;
if ( V_254 < V_257 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_253 [ 0 ] ;
V_26 [ 1 ] = V_253 [ 1 ] ;
if ( V_253 [ 2 ] == 'I' )
V_53 = V_258 ;
else if ( V_253 [ 2 ] == 'O' )
V_53 = V_259 ;
F_160 () ;
V_20 = F_10 () ;
if ( F_139 ( ! V_20 ) )
goto V_12;
if ( V_20 -> V_62 == V_63 &&
V_20 -> V_149 != V_240 )
goto V_12;
V_18 -> V_149 = F_150 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_62 = V_63 ;
V_18 -> V_260 = V_53 ;
F_54 () ;
F_153 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_161 () ;
}
static void F_162 ( char * V_26 , bool V_261 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_261 ) {
F_6 ( L_30 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_262 ) ) {
F_6 ( L_31 ,
V_262 [ 0 ] , V_262 [ 1 ] ) ;
V_26 [ 0 ] = V_262 [ 0 ] ;
V_26 [ 1 ] = V_262 [ 1 ] ;
}
} else {
F_6 ( L_32 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_262 ) ) {
F_6 ( L_31 ,
V_262 [ 0 ] , V_262 [ 1 ] ) ;
V_26 [ 0 ] = V_262 [ 0 ] ;
V_26 [ 1 ] = V_262 [ 1 ] ;
} else
F_6 ( L_33 ) ;
}
static void F_163 ( struct V_3 * V_3 )
{
struct V_165 * V_166 ;
enum V_194 V_188 ;
struct V_142 * V_143 ;
int V_32 ;
for ( V_188 = 0 ; V_188 < V_195 ; V_188 ++ ) {
V_166 = V_3 -> V_187 [ V_188 ] ;
if ( ! V_166 )
continue;
for ( V_32 = 0 ; V_32 < V_166 -> V_167 ; V_32 ++ ) {
V_143 = & V_166 -> V_168 [ V_32 ] ;
V_143 -> V_77 = V_143 -> V_150 ;
V_143 -> V_107 = V_143 -> V_154 ;
V_143 -> V_156 = V_143 -> V_157 ;
V_143 -> V_163 = false ;
}
}
}
static void F_49 ( bool V_261 )
{
char V_26 [ 2 ] ;
char V_263 [ 2 ] ;
struct V_184 * V_184 , * V_264 ;
F_164 ( V_265 ) ;
struct V_201 * V_202 ;
F_18 () ;
F_130 ( & V_250 ) ;
if ( V_251 && ! V_252 ) {
V_251 = false ;
F_122 () ;
}
F_131 ( & V_250 ) ;
F_17 ( true , & V_24 ) ;
F_162 ( V_26 , V_261 ) ;
F_130 ( & V_227 ) ;
F_165 ( & V_228 , & V_265 ) ;
F_131 ( & V_227 ) ;
F_146 ( & V_244 ) ;
F_147 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_184 -> V_43 ) ;
F_13 ( V_184 ) ;
}
F_148 ( & V_244 ) ;
F_147 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_184 -> V_43 ) ;
F_13 ( V_184 ) ;
}
V_263 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_263 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_103 (rdev, &cfg80211_rdev_list, list) {
if ( V_202 -> V_3 . V_151 & V_180 )
continue;
if ( V_202 -> V_3 . V_151 & V_179 )
F_163 ( & V_202 -> V_3 ) ;
}
F_154 ( V_263 ) ;
if ( F_25 ( V_26 ) )
F_155 ( V_26 , V_266 ) ;
F_130 ( & V_227 ) ;
F_165 ( & V_265 , & V_228 ) ;
F_131 ( & V_227 ) ;
F_6 ( L_34 ) ;
F_45 ( & V_229 ) ;
}
void F_166 ( void )
{
F_6 ( L_35 ) ;
F_49 ( false ) ;
}
static bool F_167 ( T_4 V_267 )
{
if ( V_267 == F_168 ( 12 , V_268 ) ||
V_267 == F_168 ( 13 , V_268 ) ||
V_267 == F_168 ( 14 , V_268 ) )
return true ;
return false ;
}
static bool F_169 ( struct V_142 * V_269 )
{
struct V_184 * V_243 ;
F_103 (pending_beacon, &reg_pending_beacons, list)
if ( V_269 -> V_132 ==
V_243 -> V_143 . V_132 )
return true ;
return false ;
}
int F_170 ( struct V_3 * V_3 ,
struct V_142 * V_269 ,
T_5 V_270 )
{
struct V_184 * V_184 ;
bool V_271 ;
if ( V_269 -> V_163 ||
V_269 -> V_77 & V_121 ||
( V_269 -> V_188 == V_268 &&
! F_167 ( V_269 -> V_132 ) ) )
return 0 ;
F_146 ( & V_244 ) ;
V_271 = F_169 ( V_269 ) ;
F_148 ( & V_244 ) ;
if ( V_271 )
return 0 ;
V_184 = F_31 ( sizeof( struct V_184 ) , V_270 ) ;
if ( ! V_184 )
return - V_36 ;
F_6 ( L_36 ,
V_269 -> V_132 ,
F_171 ( V_269 -> V_132 ) ,
F_172 ( V_3 ) ) ;
memcpy ( & V_184 -> V_143 , V_269 ,
sizeof( struct V_142 ) ) ;
F_146 ( & V_244 ) ;
F_44 ( & V_184 -> V_43 , & V_272 ) ;
F_148 ( & V_244 ) ;
F_45 ( & V_229 ) ;
return 0 ;
}
static void F_173 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_84 = NULL ;
const struct V_66 * V_67 = NULL ;
const struct V_99 * V_102 = NULL ;
char V_76 [ 32 ] , V_273 [ 32 ] ;
F_6 ( L_37 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_84 = & V_25 -> V_37 [ V_32 ] ;
V_67 = & V_84 -> V_67 ;
V_102 = & V_84 -> V_102 ;
if ( V_84 -> V_77 & V_105 )
snprintf ( V_76 , sizeof( V_76 ) , L_38 ,
V_67 -> V_83 ,
F_63 ( V_25 , V_84 ) ) ;
else
snprintf ( V_76 , sizeof( V_76 ) , L_39 ,
V_67 -> V_83 ) ;
if ( V_84 -> V_77 & V_120 )
F_174 ( V_273 , sizeof( V_273 ) , L_40 ,
V_84 -> V_108 / 1000 ) ;
else
F_174 ( V_273 , sizeof( V_273 ) , L_41 ) ;
if ( V_102 -> V_107 )
F_6 ( L_42 ,
V_67 -> V_75 ,
V_67 -> V_74 ,
V_76 ,
V_102 -> V_107 ,
V_102 -> V_106 ,
V_273 ) ;
else
F_6 ( L_43 ,
V_67 -> V_75 ,
V_67 -> V_74 ,
V_76 ,
V_102 -> V_106 ,
V_273 ) ;
}
}
bool F_175 ( enum V_5 V_6 )
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
static void F_176 ( const struct V_1 * V_25 )
{
struct V_16 * V_20 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_20 -> V_62 == V_63 ) {
struct V_201 * V_202 ;
V_202 = F_177 ( V_20 -> V_149 ) ;
if ( V_202 ) {
F_6 ( L_45 ,
V_202 -> V_274 [ 0 ] ,
V_202 -> V_274 [ 1 ] ) ;
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
F_173 ( V_25 ) ;
}
static void F_178 ( const struct V_1 * V_25 )
{
F_6 ( L_52 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_173 ( V_25 ) ;
}
static int F_179 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_56 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_180 ( const struct V_1 * V_25 ,
struct V_16 * V_232 )
{
const struct V_1 * V_275 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_276 ;
if ( ! F_66 ( V_25 ) ) {
F_181 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_178 ( V_25 ) ;
return - V_56 ;
}
if ( ! V_232 -> V_231 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_275 = F_76 ( V_25 , F_1 () ) ;
if ( ! V_275 )
return - V_56 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_275 ) ;
return 0 ;
}
static int F_182 ( const struct V_1 * V_25 ,
struct V_16 * V_235 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_275 = NULL ;
const struct V_1 * V_69 ;
struct V_3 * V_148 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_56 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_276 ;
if ( ! F_66 ( V_25 ) ) {
F_181 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_178 ( V_25 ) ;
return - V_56 ;
}
V_148 = F_86 ( V_235 -> V_149 ) ;
if ( ! V_148 )
return - V_277 ;
if ( ! V_235 -> V_231 ) {
if ( V_148 -> V_4 )
return - V_276 ;
V_4 = F_30 ( V_25 ) ;
if ( F_81 ( V_4 ) )
return F_87 ( V_4 ) ;
F_16 ( V_148 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_275 = F_76 ( V_25 , F_1 () ) ;
if ( ! V_275 )
return - V_56 ;
V_69 = F_3 ( V_148 ) ;
F_16 ( V_148 -> V_4 , V_25 ) ;
F_8 ( V_69 ) ;
V_25 = NULL ;
F_17 ( false , V_275 ) ;
return 0 ;
}
static int F_183 ( const struct V_1 * V_25 ,
struct V_16 * V_236 )
{
struct V_3 * V_148 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_56 ;
if ( ! F_66 ( V_25 ) ) {
F_181 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_178 ( V_25 ) ;
return - V_56 ;
}
V_148 = F_86 ( V_236 -> V_149 ) ;
if ( ! V_148 )
return - V_277 ;
if ( V_236 -> V_231 )
return - V_56 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_39 ( const struct V_1 * V_25 ,
enum V_278 V_279 )
{
struct V_16 * V_20 ;
bool V_280 = false ;
int V_14 ;
if ( ! F_60 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_56 ;
}
if ( V_279 == V_281 )
F_54 () ;
V_20 = F_10 () ;
switch ( V_20 -> V_62 ) {
case V_140 :
V_14 = F_179 ( V_25 ) ;
break;
case V_64 :
V_14 = F_180 ( V_25 , V_20 ) ;
V_280 = true ;
break;
case V_141 :
V_14 = F_182 ( V_25 , V_20 ) ;
break;
case V_63 :
V_14 = F_183 ( V_25 , V_20 ) ;
break;
default:
F_29 ( 1 , L_28 , V_20 -> V_62 ) ;
F_13 ( V_25 ) ;
return - V_56 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_276 :
F_129 () ;
break;
default:
F_49 ( V_280 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_20 -> V_231 && V_25 != F_1 () ) )
return - V_56 ;
F_125 ( V_20 -> V_62 ) ;
F_176 ( F_1 () ) ;
F_137 ( V_20 ) ;
F_129 () ;
return 0 ;
}
static int F_184 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_282 ;
struct V_201 * V_202 ;
if ( F_20 ( ! V_3 || ! V_25 ) )
return - V_56 ;
if ( F_29 ( ! ( V_3 -> V_151 & V_180 ) ,
L_54 ) )
return - V_283 ;
if ( F_29 ( ! F_66 ( V_25 ) , L_55 ) ) {
F_178 ( V_25 ) ;
return - V_56 ;
}
V_4 = F_30 ( V_25 ) ;
if ( F_81 ( V_4 ) )
return F_87 ( V_4 ) ;
V_202 = F_111 ( V_3 ) ;
F_130 ( & V_227 ) ;
V_282 = V_202 -> V_246 ;
V_202 -> V_246 = V_4 ;
F_131 ( & V_227 ) ;
F_13 ( V_282 ) ;
return 0 ;
}
int F_185 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_54 = F_184 ( V_3 , V_25 ) ;
if ( V_54 )
return V_54 ;
F_45 ( & V_229 ) ;
return 0 ;
}
int F_186 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_54 ;
F_18 () ;
V_54 = F_184 ( V_3 , V_25 ) ;
if ( V_54 )
return V_54 ;
F_149 () ;
return 0 ;
}
void F_187 ( struct V_3 * V_3 )
{
struct V_16 * V_20 ;
if ( V_3 -> V_151 & V_180 )
V_3 -> V_151 |= V_189 |
V_238 ;
if ( ! F_94 ( V_3 ) )
V_173 ++ ;
V_20 = F_10 () ;
F_124 ( V_3 , V_20 -> V_62 ) ;
}
void F_188 ( struct V_3 * V_3 )
{
struct V_3 * V_148 = NULL ;
struct V_16 * V_20 ;
V_20 = F_10 () ;
if ( ! F_94 ( V_3 ) )
V_173 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_189 ( V_3 -> V_4 , NULL ) ;
if ( V_20 )
V_148 = F_86 ( V_20 -> V_149 ) ;
if ( ! V_148 || V_148 != V_3 )
return;
V_20 -> V_149 = V_240 ;
V_20 -> V_260 = V_256 ;
}
int F_190 ( int V_267 )
{
if ( V_267 >= 5150 && V_267 <= 5250 )
return 0 ;
if ( V_267 > 5250 && V_267 <= 5350 )
return 1 ;
if ( V_267 > 5350 && V_267 <= 5470 )
return 2 ;
if ( V_267 > 5470 && V_267 <= 5725 )
return 3 ;
if ( V_267 > 5725 && V_267 <= 5825 )
return 4 ;
return - V_56 ;
}
bool F_191 ( void )
{
return V_251 ;
}
int T_6 F_192 ( void )
{
int V_284 = 0 ;
V_57 = F_193 ( L_56 , 0 , NULL , 0 ) ;
if ( F_81 ( V_57 ) )
return F_87 ( V_57 ) ;
F_194 ( & V_227 ) ;
F_194 ( & V_244 ) ;
F_194 ( & V_250 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_284 = F_154 ( V_23 -> V_26 ) ;
if ( V_284 ) {
if ( V_284 == - V_36 ) {
F_195 ( V_57 ) ;
return V_284 ;
}
F_181 ( L_57 ) ;
}
if ( ! F_21 ( V_262 ) )
F_155 ( V_262 ,
V_266 ) ;
return 0 ;
}
void F_196 ( void )
{
struct V_16 * V_239 , * V_69 ;
struct V_184 * V_184 , * V_264 ;
F_197 ( & V_229 ) ;
F_52 () ;
F_53 ( & V_223 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_41 () ;
F_198 ( & V_57 -> V_13 , true ) ;
F_195 ( V_57 ) ;
F_147 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_184 -> V_43 ) ;
F_13 ( V_184 ) ;
}
F_147 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_184 -> V_43 ) ;
F_13 ( V_184 ) ;
}
F_147 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_239 -> V_43 ) ;
F_13 ( V_239 ) ;
}
}
