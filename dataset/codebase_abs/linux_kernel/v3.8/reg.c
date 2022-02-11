static inline void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static void F_3 ( bool V_2 )
{
if ( V_3 == V_4 )
V_3 = NULL ;
if ( V_4 == & V_5 )
V_4 = NULL ;
if ( V_3 == & V_5 )
V_3 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
V_4 = & V_5 ;
V_3 = NULL ;
if ( ! V_2 )
return;
if ( V_6 != & V_7 )
F_4 ( V_6 ) ;
V_6 = & V_7 ;
}
static void F_5 ( const struct V_8 * V_9 )
{
F_6 ( ! V_6 ) ;
F_3 ( false ) ;
V_4 = V_9 ;
V_3 = V_9 ;
}
bool F_7 ( const char * V_10 )
{
if ( ! V_10 )
return false ;
if ( V_10 [ 0 ] == '0' && V_10 [ 1 ] == '0' )
return true ;
return false ;
}
static bool F_8 ( const char * V_10 )
{
if ( ! V_10 )
return false ;
if ( V_10 [ 0 ] != 0 && V_10 [ 1 ] != 0 )
return true ;
return false ;
}
static bool F_9 ( const char * V_10 )
{
if ( ! V_10 )
return false ;
if ( V_10 [ 0 ] == '9' && V_10 [ 1 ] == '9' )
return true ;
return false ;
}
static bool F_10 ( const char * V_10 )
{
if ( ! V_10 )
return false ;
if ( V_10 [ 0 ] == '9' && V_10 [ 1 ] == '8' )
return true ;
return false ;
}
static bool F_11 ( const char * V_10 )
{
if ( ! V_10 )
return false ;
if ( isalpha ( V_10 [ 0 ] ) && isalpha ( V_10 [ 1 ] ) )
return true ;
return false ;
}
static bool F_12 ( const char * V_11 , const char * V_12 )
{
if ( ! V_11 || ! V_12 )
return false ;
if ( V_11 [ 0 ] == V_12 [ 0 ] &&
V_11 [ 1 ] == V_12 [ 1 ] )
return true ;
return false ;
}
static bool F_13 ( const char * V_10 )
{
F_14 () ;
if ( ! V_3 )
return true ;
if ( F_12 ( V_3 -> V_10 , V_10 ) )
return false ;
return true ;
}
static bool F_15 ( void )
{
if ( V_13 [ 0 ] == '9' && V_13 [ 1 ] == '7' )
return false ;
if ( F_16 ( ( ! F_7 ( V_13 ) &&
! F_11 ( V_13 ) ) ,
L_1 ,
V_13 [ 0 ] ,
V_13 [ 1 ] ) )
return false ;
return true ;
}
static int F_17 ( const struct V_8 * * V_14 ,
const struct V_8 * V_15 )
{
struct V_8 * V_16 ;
int V_17 = 0 ;
unsigned int V_18 ;
V_17 = sizeof( struct V_8 ) +
( ( V_15 -> V_19 + 1 ) * sizeof( struct V_20 ) ) ;
V_16 = F_18 ( V_17 , V_21 ) ;
if ( ! V_16 )
return - V_22 ;
memcpy ( V_16 , V_15 , sizeof( struct V_8 ) ) ;
for ( V_18 = 0 ; V_18 < V_15 -> V_19 ; V_18 ++ )
memcpy ( & V_16 -> V_23 [ V_18 ] , & V_15 -> V_23 [ V_18 ] ,
sizeof( struct V_20 ) ) ;
* V_14 = V_16 ;
return 0 ;
}
static void F_19 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
const struct V_8 * V_28 , * V_29 ;
int V_18 , V_30 ;
bool V_31 = false ;
F_20 ( & V_32 ) ;
F_20 ( & V_33 ) ;
while ( ! F_21 ( & V_34 ) ) {
V_27 = F_22 ( & V_34 ,
struct V_26 ,
V_35 ) ;
F_23 ( & V_27 -> V_35 ) ;
for ( V_18 = 0 ; V_18 < V_36 ; V_18 ++ ) {
V_28 = V_37 [ V_18 ] ;
if ( ! memcmp ( V_27 -> V_10 , V_28 -> V_10 , 2 ) ) {
V_30 = F_17 ( & V_29 , V_28 ) ;
if ( V_30 )
break;
V_31 = true ;
break;
}
}
F_4 ( V_27 ) ;
}
F_24 ( & V_33 ) ;
if ( V_31 )
F_25 ( V_29 ) ;
F_24 ( & V_32 ) ;
}
static void F_26 ( const char * V_10 )
{
struct V_26 * V_27 ;
if ( ! V_10 )
return;
V_27 = F_18 ( sizeof( struct V_26 ) , V_21 ) ;
if ( ! V_27 )
return;
memcpy ( V_27 -> V_10 , V_10 , 2 ) ;
F_20 ( & V_33 ) ;
F_27 ( & V_27 -> V_35 , & V_34 ) ;
F_24 ( & V_33 ) ;
F_28 ( & V_38 ) ;
}
static void F_29 ( void )
{
F_30 ( ! V_36 , L_2 ) ;
}
static inline void F_29 ( void ) {}
static inline void F_26 ( const char * V_10 ) {}
static int F_31 ( const char * V_10 )
{
if ( ! F_7 ( ( char * ) V_10 ) )
F_32 ( L_3 ,
V_10 [ 0 ] , V_10 [ 1 ] ) ;
else
F_32 ( L_4 ) ;
F_26 ( V_10 ) ;
return F_33 ( & V_39 -> V_40 . V_41 , V_42 ) ;
}
bool F_34 ( const char * V_10 )
{
F_14 () ;
if ( ! V_6 )
return false ;
return F_12 ( V_6 -> V_10 , V_10 ) ;
}
static bool F_35 ( const struct V_20 * V_43 )
{
const struct V_44 * V_45 = & V_43 -> V_45 ;
T_1 V_46 ;
if ( V_45 -> V_47 <= 0 || V_45 -> V_48 <= 0 )
return false ;
if ( V_45 -> V_47 > V_45 -> V_48 )
return false ;
V_46 = V_45 -> V_48 - V_45 -> V_47 ;
if ( V_45 -> V_48 <= V_45 -> V_47 ||
V_45 -> V_49 > V_46 )
return false ;
return true ;
}
static bool F_36 ( const struct V_8 * V_9 )
{
const struct V_20 * V_50 = NULL ;
unsigned int V_18 ;
if ( ! V_9 -> V_19 )
return false ;
if ( F_37 ( V_9 -> V_19 > V_51 ) )
return false ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_50 = & V_9 -> V_23 [ V_18 ] ;
if ( ! F_35 ( V_50 ) )
return false ;
}
return true ;
}
static bool F_38 ( const struct V_44 * V_45 ,
T_1 V_52 ,
T_1 V_53 )
{
T_1 V_47 , V_48 ;
V_47 = V_52 - ( V_53 / 2 ) ;
V_48 = V_52 + ( V_53 / 2 ) ;
if ( V_47 >= V_45 -> V_47 &&
V_48 <= V_45 -> V_48 )
return true ;
return false ;
}
static bool F_39 ( const struct V_44 * V_45 ,
T_1 V_54 )
{
#define F_40 1000000
T_1 V_55 = V_54 > 45 * F_40 ?
10 * F_40 : 2 * F_40 ;
if ( abs ( V_54 - V_45 -> V_47 ) <= V_55 )
return true ;
if ( abs ( V_54 - V_45 -> V_48 ) <= V_55 )
return true ;
return false ;
#undef F_40
}
static int F_41 (
const struct V_20 * V_56 ,
const struct V_20 * V_57 ,
struct V_20 * V_58 )
{
const struct V_44 * V_59 , * V_60 ;
struct V_44 * V_45 ;
const struct V_61 * V_62 , * V_63 ;
struct V_61 * V_64 ;
T_1 V_46 ;
V_59 = & V_56 -> V_45 ;
V_60 = & V_57 -> V_45 ;
V_45 = & V_58 -> V_45 ;
V_62 = & V_56 -> V_64 ;
V_63 = & V_57 -> V_64 ;
V_64 = & V_58 -> V_64 ;
V_45 -> V_47 = F_42 ( V_59 -> V_47 ,
V_60 -> V_47 ) ;
V_45 -> V_48 = F_43 ( V_59 -> V_48 ,
V_60 -> V_48 ) ;
V_45 -> V_49 = F_43 ( V_59 -> V_49 ,
V_60 -> V_49 ) ;
V_46 = V_45 -> V_48 - V_45 -> V_47 ;
if ( V_45 -> V_49 > V_46 )
V_45 -> V_49 = V_46 ;
V_64 -> V_65 = F_43 ( V_62 -> V_65 ,
V_63 -> V_65 ) ;
V_64 -> V_66 = F_43 ( V_62 -> V_66 ,
V_63 -> V_66 ) ;
V_58 -> V_67 = ( V_56 -> V_67 | V_57 -> V_67 ) ;
if ( ! F_35 ( V_58 ) )
return - V_68 ;
return 0 ;
}
static struct V_8 * F_44 (
const struct V_8 * V_69 ,
const struct V_8 * V_70 )
{
int V_30 , V_17 ;
unsigned int V_71 , V_72 ;
unsigned int V_73 = 0 , V_74 = 0 ;
const struct V_20 * V_56 , * V_57 ;
struct V_20 * V_58 ;
struct V_8 * V_9 ;
struct V_20 V_75 ;
V_58 = & V_75 ;
memset ( V_58 , 0 , sizeof( struct V_20 ) ) ;
if ( ! V_69 || ! V_70 )
return NULL ;
for ( V_71 = 0 ; V_71 < V_69 -> V_19 ; V_71 ++ ) {
V_56 = & V_69 -> V_23 [ V_71 ] ;
for ( V_72 = 0 ; V_72 < V_70 -> V_19 ; V_72 ++ ) {
V_57 = & V_70 -> V_23 [ V_72 ] ;
if ( ! F_41 ( V_56 , V_57 ,
V_58 ) )
V_73 ++ ;
memset ( V_58 , 0 ,
sizeof( struct V_20 ) ) ;
}
}
if ( ! V_73 )
return NULL ;
V_17 = sizeof( struct V_8 ) +
( ( V_73 + 1 ) * sizeof( struct V_20 ) ) ;
V_9 = F_18 ( V_17 , V_21 ) ;
if ( ! V_9 )
return NULL ;
for ( V_71 = 0 ; V_71 < V_69 -> V_19 ; V_71 ++ ) {
V_56 = & V_69 -> V_23 [ V_71 ] ;
for ( V_72 = 0 ; V_72 < V_70 -> V_19 ; V_72 ++ ) {
V_57 = & V_70 -> V_23 [ V_72 ] ;
V_58 = & V_9 -> V_23 [ V_74 ] ;
V_30 = F_41 ( V_56 , V_57 ,
V_58 ) ;
if ( V_30 )
continue;
V_74 ++ ;
}
}
if ( V_74 != V_73 ) {
F_4 ( V_9 ) ;
return NULL ;
}
V_9 -> V_19 = V_73 ;
V_9 -> V_10 [ 0 ] = '9' ;
V_9 -> V_10 [ 1 ] = '8' ;
return V_9 ;
}
static T_1 F_45 ( T_1 V_76 )
{
T_1 V_77 = 0 ;
if ( V_76 & V_78 )
V_77 |= V_79 ;
if ( V_76 & V_80 )
V_77 |= V_81 ;
if ( V_76 & V_82 )
V_77 |= V_83 ;
if ( V_76 & V_84 )
V_77 |= V_85 ;
return V_77 ;
}
static int F_46 ( struct V_86 * V_86 ,
T_1 V_87 ,
T_1 V_88 ,
const struct V_20 * * V_50 ,
const struct V_8 * V_89 )
{
int V_18 ;
bool V_90 = false ;
const struct V_8 * V_16 ;
bool V_91 = false ;
if ( ! V_88 )
V_88 = F_47 ( 20 ) ;
V_16 = V_89 ? V_89 : V_3 ;
if ( ! V_89 &&
V_6 -> V_92 != V_93 &&
V_6 -> V_92 != V_94 &&
V_86 -> V_16 )
V_16 = V_86 -> V_16 ;
if ( ! V_16 )
return - V_68 ;
for ( V_18 = 0 ; V_18 < V_16 -> V_19 ; V_18 ++ ) {
const struct V_20 * V_95 ;
const struct V_44 * V_96 = NULL ;
V_95 = & V_16 -> V_23 [ V_18 ] ;
V_96 = & V_95 -> V_45 ;
if ( ! V_90 )
V_90 = F_39 ( V_96 , V_87 ) ;
V_91 = F_38 ( V_96 ,
V_87 ,
V_88 ) ;
if ( V_90 && V_91 ) {
* V_50 = V_95 ;
return 0 ;
}
}
if ( ! V_90 )
return - V_97 ;
return - V_68 ;
}
int F_48 ( struct V_86 * V_86 ,
T_1 V_87 ,
T_1 V_88 ,
const struct V_20 * * V_50 )
{
F_14 () ;
return F_46 ( V_86 ,
V_87 ,
V_88 ,
V_50 ,
NULL ) ;
}
static const char * F_49 ( enum V_98 V_92 )
{
switch ( V_92 ) {
case V_99 :
return L_5 ;
case V_94 :
return L_6 ;
case V_100 :
return L_7 ;
case V_93 :
return L_8 ;
default:
F_37 ( 1 ) ;
return L_9 ;
}
}
static void F_50 ( struct V_101 * V_102 ,
T_1 V_88 ,
const struct V_20 * V_50 )
{
const struct V_61 * V_64 ;
const struct V_44 * V_45 ;
char V_66 [ 32 ] ;
V_64 = & V_50 -> V_64 ;
V_45 = & V_50 -> V_45 ;
if ( ! V_64 -> V_66 )
snprintf ( V_66 , 32 , L_10 ) ;
else
snprintf ( V_66 , 32 , L_11 , V_64 -> V_66 ) ;
F_51 ( L_12
L_13 ,
V_102 -> V_87 ,
F_52 ( V_88 ) ) ;
F_51 ( L_14 ,
V_45 -> V_47 ,
V_45 -> V_48 ,
V_45 -> V_49 ,
V_66 ,
V_64 -> V_65 ) ;
}
static void F_50 ( struct V_101 * V_102 ,
T_1 V_88 ,
const struct V_20 * V_50 )
{
return;
}
static void F_53 ( struct V_86 * V_86 ,
enum V_98 V_92 ,
enum V_103 V_104 ,
unsigned int V_105 )
{
int V_30 ;
T_1 V_67 , V_106 = 0 ;
T_1 V_88 = F_47 ( 20 ) ;
const struct V_20 * V_50 = NULL ;
const struct V_61 * V_64 = NULL ;
const struct V_44 * V_45 = NULL ;
struct V_107 * V_108 ;
struct V_101 * V_102 ;
struct V_86 * V_109 = NULL ;
F_14 () ;
V_109 = F_54 ( V_6 -> V_110 ) ;
V_108 = V_86 -> V_111 [ V_104 ] ;
F_6 ( V_105 >= V_108 -> V_112 ) ;
V_102 = & V_108 -> V_113 [ V_105 ] ;
V_67 = V_102 -> V_114 ;
V_30 = F_48 ( V_86 ,
F_47 ( V_102 -> V_87 ) ,
V_88 ,
& V_50 ) ;
if ( V_30 ) {
if ( V_92 == V_93 &&
V_30 == - V_97 )
return;
F_51 ( L_15 , V_102 -> V_87 ) ;
V_102 -> V_67 = V_115 ;
return;
}
F_50 ( V_102 , V_88 , V_50 ) ;
V_64 = & V_50 -> V_64 ;
V_45 = & V_50 -> V_45 ;
if ( V_45 -> V_49 < F_47 ( 40 ) )
V_106 = V_116 ;
if ( V_6 -> V_92 == V_100 &&
V_109 && V_109 == V_86 &&
V_109 -> V_67 & V_117 ) {
V_102 -> V_67 = V_102 -> V_114 =
F_45 ( V_50 -> V_67 ) | V_106 ;
V_102 -> V_66 = V_102 -> V_118 =
( int ) F_55 ( V_64 -> V_66 ) ;
V_102 -> V_119 = V_102 -> V_120 = V_102 -> V_121 =
( int ) F_56 ( V_64 -> V_65 ) ;
return;
}
V_102 -> V_122 = false ;
V_102 -> V_67 = V_67 | V_106 | F_45 ( V_50 -> V_67 ) ;
V_102 -> V_66 = F_43 ( V_102 -> V_118 ,
( int ) F_55 ( V_64 -> V_66 ) ) ;
V_102 -> V_119 = ( int ) F_56 ( V_64 -> V_65 ) ;
if ( V_102 -> V_121 ) {
if ( V_92 == V_93 &&
V_86 -> V_67 & V_123 &&
V_86 -> V_67 & V_117 )
V_102 -> V_120 = V_102 -> V_119 ;
else
V_102 -> V_120 = F_43 ( V_102 -> V_121 ,
V_102 -> V_119 ) ;
} else
V_102 -> V_120 = V_102 -> V_119 ;
}
static void F_57 ( struct V_86 * V_86 ,
enum V_103 V_104 ,
enum V_98 V_92 )
{
unsigned int V_18 ;
struct V_107 * V_108 ;
F_6 ( ! V_86 -> V_111 [ V_104 ] ) ;
V_108 = V_86 -> V_111 [ V_104 ] ;
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ )
F_53 ( V_86 , V_92 , V_104 , V_18 ) ;
}
static bool F_58 ( struct V_124 * V_27 )
{
if ( V_27 -> V_92 != V_94 )
return false ;
if ( V_27 -> V_125 != V_126 )
return false ;
return true ;
}
bool F_59 ( void )
{
bool V_127 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_127 = F_58 ( V_6 ) ;
F_24 ( & V_1 ) ;
return V_127 ;
}
static int F_60 ( struct V_124 * V_128 )
{
if ( ! V_129 )
return - V_130 ;
if ( F_58 ( V_6 ) ) {
if ( ! F_13 ( V_128 -> V_10 ) )
return - V_131 ;
return 0 ;
}
return 0 ;
}
static bool F_61 ( struct V_86 * V_86 )
{
if ( ! ( V_86 -> V_132 & V_133 ) )
return true ;
return false ;
}
static int F_60 ( struct V_124 * V_128 )
{
return - V_130 ;
}
static int F_61 ( struct V_86 * V_86 )
{
return true ;
}
static bool F_62 ( struct V_86 * V_86 ,
enum V_98 V_92 )
{
if ( ! V_6 ) {
F_51 ( L_16
L_17 ,
F_49 ( V_92 ) ) ;
return true ;
}
if ( V_92 == V_99 &&
V_86 -> V_67 & V_123 ) {
F_51 ( L_18
L_19
L_20 ,
F_49 ( V_92 ) ) ;
return true ;
}
if ( V_86 -> V_67 & V_117 && ! V_86 -> V_16 &&
V_92 != V_93 &&
! F_7 ( V_6 -> V_10 ) ) {
F_51 ( L_18
L_21
L_22 ,
F_49 ( V_92 ) ) ;
return true ;
}
if ( F_58 ( V_6 ) )
return F_61 ( V_86 ) ;
return false ;
}
static void F_63 ( struct V_86 * V_86 ,
unsigned int V_105 ,
struct V_134 * V_134 )
{
struct V_107 * V_108 ;
struct V_101 * V_102 ;
bool V_135 = false ;
struct V_101 V_136 ;
F_14 () ;
V_108 = V_86 -> V_111 [ V_134 -> V_102 . V_104 ] ;
V_102 = & V_108 -> V_113 [ V_105 ] ;
if ( F_64 ( V_102 -> V_87 != V_134 -> V_102 . V_87 ) )
return;
if ( V_102 -> V_122 )
return;
V_102 -> V_122 = true ;
if ( V_86 -> V_67 & V_137 )
return;
V_136 . V_87 = V_102 -> V_87 ;
V_136 . V_67 = V_102 -> V_67 ;
if ( V_102 -> V_67 & V_79 ) {
V_102 -> V_67 &= ~ V_79 ;
V_135 = true ;
}
if ( V_102 -> V_67 & V_81 ) {
V_102 -> V_67 &= ~ V_81 ;
V_135 = true ;
}
if ( V_135 )
F_65 ( V_86 , & V_136 , V_102 ) ;
}
static void F_66 ( struct V_86 * V_86 ,
struct V_134 * V_134 )
{
unsigned int V_18 ;
struct V_107 * V_108 ;
F_14 () ;
if ( ! V_86 -> V_111 [ V_134 -> V_102 . V_104 ] )
return;
V_108 = V_86 -> V_111 [ V_134 -> V_102 . V_104 ] ;
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ )
F_63 ( V_86 , V_18 , V_134 ) ;
}
static void F_67 ( struct V_86 * V_86 )
{
unsigned int V_18 ;
struct V_107 * V_108 ;
struct V_134 * V_134 ;
F_14 () ;
if ( F_21 ( & V_138 ) )
return;
F_68 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_86 -> V_111 [ V_134 -> V_102 . V_104 ] )
continue;
V_108 = V_86 -> V_111 [ V_134 -> V_102 . V_104 ] ;
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ )
F_63 ( V_86 , V_18 , V_134 ) ;
}
}
static bool F_69 ( struct V_86 * V_86 )
{
if ( F_7 ( V_3 -> V_10 ) ||
( V_86 -> V_16 && F_7 ( V_86 -> V_16 -> V_10 ) ) )
return true ;
if ( V_6 &&
V_6 -> V_92 != V_93 &&
V_86 -> V_67 & V_123 )
return true ;
return false ;
}
static void F_70 ( struct V_86 * V_86 )
{
if ( ! V_6 )
return;
if ( ! F_69 ( V_86 ) )
return;
F_67 ( V_86 ) ;
}
static bool F_71 ( struct V_101 * V_102 )
{
if ( ! V_102 )
return true ;
if ( V_102 -> V_67 & V_115 )
return true ;
if ( V_116 == ( V_102 -> V_67 & ( V_116 ) ) )
return true ;
return false ;
}
static void F_72 ( struct V_86 * V_86 ,
enum V_103 V_104 ,
unsigned int V_105 )
{
struct V_107 * V_108 ;
struct V_101 * V_139 ;
struct V_101 * V_140 = NULL , * V_141 = NULL ;
unsigned int V_18 ;
F_14 () ;
V_108 = V_86 -> V_111 [ V_104 ] ;
F_6 ( V_105 >= V_108 -> V_112 ) ;
V_139 = & V_108 -> V_113 [ V_105 ] ;
if ( F_71 ( V_139 ) ) {
V_139 -> V_67 |= V_116 ;
return;
}
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ ) {
struct V_101 * V_142 = & V_108 -> V_113 [ V_18 ] ;
if ( V_142 -> V_87 == ( V_139 -> V_87 - 20 ) )
V_140 = V_142 ;
if ( V_142 -> V_87 == ( V_139 -> V_87 + 20 ) )
V_141 = V_142 ;
}
if ( F_71 ( V_140 ) )
V_139 -> V_67 |= V_143 ;
else
V_139 -> V_67 &= ~ V_143 ;
if ( F_71 ( V_141 ) )
V_139 -> V_67 |= V_144 ;
else
V_139 -> V_67 &= ~ V_144 ;
}
static void F_73 ( struct V_86 * V_86 ,
enum V_103 V_104 )
{
unsigned int V_18 ;
struct V_107 * V_108 ;
F_6 ( ! V_86 -> V_111 [ V_104 ] ) ;
V_108 = V_86 -> V_111 [ V_104 ] ;
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ )
F_72 ( V_86 , V_104 , V_18 ) ;
}
static void F_74 ( struct V_86 * V_86 )
{
enum V_103 V_104 ;
if ( ! V_86 )
return;
for ( V_104 = 0 ; V_104 < V_145 ; V_104 ++ ) {
if ( V_86 -> V_111 [ V_104 ] )
F_73 ( V_86 , V_104 ) ;
}
}
static void F_75 ( struct V_86 * V_86 ,
enum V_98 V_92 )
{
enum V_103 V_104 ;
F_1 () ;
if ( F_62 ( V_86 , V_92 ) )
return;
V_6 -> V_146 = V_3 -> V_146 ;
for ( V_104 = 0 ; V_104 < V_145 ; V_104 ++ ) {
if ( V_86 -> V_111 [ V_104 ] )
F_57 ( V_86 , V_104 , V_92 ) ;
}
F_70 ( V_86 ) ;
F_74 ( V_86 ) ;
if ( V_86 -> V_147 )
V_86 -> V_147 ( V_86 , V_6 ) ;
}
static void F_76 ( enum V_98 V_92 )
{
struct V_148 * V_149 ;
struct V_86 * V_86 ;
F_68 (rdev, &cfg80211_rdev_list, list) {
V_86 = & V_149 -> V_86 ;
F_75 ( V_86 , V_92 ) ;
if ( V_92 == V_99 &&
V_86 -> V_67 & V_123 &&
V_86 -> V_147 )
V_86 -> V_147 ( V_86 , V_6 ) ;
}
}
static void F_77 ( struct V_86 * V_86 ,
enum V_103 V_104 ,
unsigned int V_105 ,
const struct V_8 * V_16 )
{
int V_30 ;
T_1 V_88 = F_47 ( 20 ) ;
T_1 V_106 = 0 ;
const struct V_20 * V_50 = NULL ;
const struct V_61 * V_64 = NULL ;
const struct V_44 * V_45 = NULL ;
struct V_107 * V_108 ;
struct V_101 * V_102 ;
F_1 () ;
V_108 = V_86 -> V_111 [ V_104 ] ;
F_6 ( V_105 >= V_108 -> V_112 ) ;
V_102 = & V_108 -> V_113 [ V_105 ] ;
V_30 = F_46 ( V_86 ,
F_47 ( V_102 -> V_87 ) ,
V_88 ,
& V_50 ,
V_16 ) ;
if ( V_30 ) {
F_51 ( L_23
L_24
L_25 ,
V_102 -> V_87 ,
F_52 ( V_88 ) ) ;
V_102 -> V_67 = V_115 ;
return;
}
F_50 ( V_102 , V_88 , V_50 ) ;
V_64 = & V_50 -> V_64 ;
V_45 = & V_50 -> V_45 ;
if ( V_45 -> V_49 < F_47 ( 40 ) )
V_106 = V_116 ;
V_102 -> V_67 |= F_45 ( V_50 -> V_67 ) | V_106 ;
V_102 -> V_66 = ( int ) F_55 ( V_64 -> V_66 ) ;
V_102 -> V_119 = V_102 -> V_120 =
( int ) F_56 ( V_64 -> V_65 ) ;
}
static void F_78 ( struct V_86 * V_86 , enum V_103 V_104 ,
const struct V_8 * V_16 )
{
unsigned int V_18 ;
struct V_107 * V_108 ;
F_6 ( ! V_86 -> V_111 [ V_104 ] ) ;
V_108 = V_86 -> V_111 [ V_104 ] ;
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ )
F_77 ( V_86 , V_104 , V_18 , V_16 ) ;
}
void F_79 ( struct V_86 * V_86 ,
const struct V_8 * V_16 )
{
enum V_103 V_104 ;
unsigned int V_150 = 0 ;
F_20 ( & V_1 ) ;
for ( V_104 = 0 ; V_104 < V_145 ; V_104 ++ ) {
if ( ! V_86 -> V_111 [ V_104 ] )
continue;
F_78 ( V_86 , V_104 , V_16 ) ;
V_150 ++ ;
}
F_24 ( & V_1 ) ;
F_37 ( ! V_150 ) ;
}
static int F_80 ( struct V_86 * V_86 ,
struct V_124 * V_128 )
{
struct V_86 * V_151 = NULL ;
F_14 () ;
if ( ! V_6 )
return 0 ;
switch ( V_128 -> V_92 ) {
case V_99 :
return 0 ;
case V_93 :
if ( F_58 ( V_6 ) ) {
if ( F_13 ( V_128 -> V_10 ) )
return - V_130 ;
return - V_131 ;
}
V_151 = F_54 ( V_6 -> V_110 ) ;
if ( F_81 ( ! F_11 ( V_128 -> V_10 ) ) )
return - V_68 ;
if ( V_6 -> V_92 ==
V_93 ) {
if ( V_151 != V_86 ) {
if ( F_13 ( V_128 -> V_10 ) )
return - V_130 ;
return - V_131 ;
}
if ( F_37 ( F_13 ( V_128 -> V_10 ) ) )
return 0 ;
return - V_131 ;
}
return 0 ;
case V_100 :
if ( V_6 -> V_92 == V_99 ) {
if ( F_13 ( V_128 -> V_10 ) )
return 0 ;
return - V_131 ;
}
if ( V_6 -> V_92 == V_100 &&
! F_13 ( V_128 -> V_10 ) )
return - V_131 ;
return V_152 ;
case V_94 :
if ( F_58 ( V_128 ) )
return F_60 ( V_128 ) ;
if ( F_58 ( V_6 ) )
return - V_130 ;
if ( V_6 -> V_92 == V_93 )
return V_152 ;
if ( V_6 -> V_92 == V_94 &&
V_6 -> V_153 )
return - V_130 ;
if ( V_6 -> V_92 == V_99 ||
V_6 -> V_92 == V_100 ||
V_6 -> V_92 == V_94 ) {
if ( F_13 ( V_6 -> V_10 ) )
return - V_154 ;
}
if ( ! F_13 ( V_128 -> V_10 ) )
return - V_131 ;
return 0 ;
}
return - V_68 ;
}
static void F_82 ( void )
{
bool V_155 = false ;
V_6 -> V_156 = true ;
F_83 ( & V_157 ) ;
if ( ! F_21 ( & V_158 ) )
V_155 = true ;
F_84 ( & V_157 ) ;
if ( V_6 -> V_92 == V_94 )
F_85 ( & V_159 ) ;
if ( V_155 )
F_28 ( & V_160 ) ;
}
static int F_86 ( struct V_86 * V_86 ,
struct V_124 * V_128 )
{
bool V_153 = false ;
int V_30 = 0 ;
F_14 () ;
V_30 = F_80 ( V_86 , V_128 ) ;
if ( V_30 == V_152 ) {
if ( V_128 -> V_92 ==
V_100 ) {
V_30 = F_17 ( & V_86 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_128 ) ;
return V_30 ;
}
}
V_153 = true ;
} else if ( V_30 ) {
if ( V_30 == - V_131 &&
V_128 -> V_92 ==
V_100 ) {
V_30 = F_17 ( & V_86 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_128 ) ;
return V_30 ;
}
V_30 = - V_131 ;
goto V_161;
}
F_4 ( V_128 ) ;
return V_30 ;
}
V_161:
if ( V_6 != & V_7 )
F_4 ( V_6 ) ;
V_6 = V_128 ;
V_6 -> V_153 = V_153 ;
V_128 = NULL ;
if ( V_6 -> V_92 == V_94 ) {
V_13 [ 0 ] = V_6 -> V_10 [ 0 ] ;
V_13 [ 1 ] = V_6 -> V_10 [ 1 ] ;
}
if ( V_30 < 0 ) {
if ( V_30 == - V_131 ) {
F_87 ( V_6 ) ;
F_82 () ;
}
return V_30 ;
}
return F_31 ( V_6 -> V_10 ) ;
}
static void F_88 ( struct V_124 * V_162 ,
enum V_98 V_163 )
{
int V_30 = 0 ;
struct V_86 * V_86 = NULL ;
F_6 ( ! V_162 -> V_10 ) ;
if ( F_89 ( V_162 -> V_110 ) )
V_86 = F_54 ( V_162 -> V_110 ) ;
if ( V_163 == V_100 &&
! V_86 ) {
F_4 ( V_162 ) ;
return;
}
V_30 = F_86 ( V_86 , V_162 ) ;
if ( V_30 == - V_131 && V_86 &&
V_86 -> V_67 & V_117 ) {
F_75 ( V_86 , V_163 ) ;
return;
}
if ( V_30 != - V_131 &&
V_163 == V_94 )
F_90 ( & V_159 , F_91 ( 3142 ) ) ;
}
static void F_92 ( void )
{
struct V_124 * V_162 ;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
if ( V_6 && ! V_6 -> V_156 ) {
F_51 ( L_26
L_27 ) ;
goto V_164;
}
F_83 ( & V_157 ) ;
if ( F_21 ( & V_158 ) ) {
F_84 ( & V_157 ) ;
goto V_164;
}
V_162 = F_22 ( & V_158 ,
struct V_124 ,
V_35 ) ;
F_93 ( & V_162 -> V_35 ) ;
F_84 ( & V_157 ) ;
F_88 ( V_162 , V_162 -> V_92 ) ;
V_164:
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
}
static void F_94 ( void )
{
struct V_148 * V_149 ;
struct V_134 * V_165 , * V_166 ;
F_20 ( & V_32 ) ;
F_95 ( & V_167 ) ;
if ( F_21 ( & V_168 ) ) {
F_96 ( & V_167 ) ;
goto V_164;
}
F_97 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_93 ( & V_165 -> V_35 ) ;
F_68 (rdev, &cfg80211_rdev_list, list)
F_66 ( & V_149 -> V_86 , V_165 ) ;
F_27 ( & V_165 -> V_35 , & V_138 ) ;
}
F_96 ( & V_167 ) ;
V_164:
F_24 ( & V_32 ) ;
}
static void F_98 ( struct V_24 * V_25 )
{
F_92 () ;
F_94 () ;
}
static void F_99 ( struct V_124 * V_27 )
{
if ( isalpha ( V_27 -> V_10 [ 0 ] ) )
V_27 -> V_10 [ 0 ] = toupper ( V_27 -> V_10 [ 0 ] ) ;
if ( isalpha ( V_27 -> V_10 [ 1 ] ) )
V_27 -> V_10 [ 1 ] = toupper ( V_27 -> V_10 [ 1 ] ) ;
F_83 ( & V_157 ) ;
F_27 ( & V_27 -> V_35 , & V_158 ) ;
F_84 ( & V_157 ) ;
F_28 ( & V_160 ) ;
}
static int F_100 ( const char * V_10 )
{
struct V_124 * V_27 ;
V_27 = F_18 ( sizeof( struct V_124 ) ,
V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_92 = V_99 ;
F_99 ( V_27 ) ;
return 0 ;
}
int F_101 ( const char * V_10 ,
enum V_169 V_125 )
{
struct V_124 * V_27 ;
F_6 ( ! V_10 ) ;
V_27 = F_18 ( sizeof( struct V_124 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_110 = V_170 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_92 = V_94 ;
V_27 -> V_125 = V_125 ;
F_99 ( V_27 ) ;
return 0 ;
}
int F_102 ( struct V_86 * V_86 , const char * V_10 )
{
struct V_124 * V_27 ;
F_6 ( ! V_10 ) ;
F_6 ( ! V_86 ) ;
V_27 = F_18 ( sizeof( struct V_124 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_110 = F_103 ( V_86 ) ;
F_6 ( ! F_89 ( V_27 -> V_110 ) ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_92 = V_100 ;
F_99 ( V_27 ) ;
return 0 ;
}
void F_104 ( struct V_86 * V_86 ,
enum V_103 V_104 ,
const T_2 * V_171 ,
T_2 V_172 )
{
char V_10 [ 2 ] ;
enum V_173 V_174 = V_175 ;
struct V_124 * V_27 ;
F_20 ( & V_1 ) ;
if ( F_81 ( ! V_6 ) )
goto V_164;
if ( V_172 & 0x01 )
goto V_164;
if ( V_172 < V_176 )
goto V_164;
V_10 [ 0 ] = V_171 [ 0 ] ;
V_10 [ 1 ] = V_171 [ 1 ] ;
if ( V_171 [ 2 ] == 'I' )
V_174 = V_177 ;
else if ( V_171 [ 2 ] == 'O' )
V_174 = V_178 ;
if ( F_64 ( V_6 -> V_92 ==
V_93 &&
F_89 ( V_6 -> V_110 ) ) )
goto V_164;
V_27 = F_18 ( sizeof( struct V_124 ) , V_21 ) ;
if ( ! V_27 )
goto V_164;
V_27 -> V_110 = F_103 ( V_86 ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_92 = V_93 ;
V_27 -> V_179 = V_174 ;
F_24 ( & V_1 ) ;
F_99 ( V_27 ) ;
return;
V_164:
F_24 ( & V_1 ) ;
}
static void F_105 ( char * V_10 , bool V_180 )
{
V_10 [ 0 ] = '9' ;
V_10 [ 1 ] = '7' ;
if ( F_15 () ) {
if ( V_180 ) {
F_51 ( L_28
L_29 ) ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
if ( ! F_7 ( V_181 ) ) {
F_51 ( L_30
L_31 ,
V_181 [ 0 ] ,
V_181 [ 1 ] ) ;
V_10 [ 0 ] = V_181 [ 0 ] ;
V_10 [ 1 ] = V_181 [ 1 ] ;
}
} else {
F_51 ( L_28
L_32 ,
V_13 [ 0 ] ,
V_13 [ 1 ] ) ;
V_10 [ 0 ] = V_13 [ 0 ] ;
V_10 [ 1 ] = V_13 [ 1 ] ;
}
} else if ( ! F_7 ( V_181 ) ) {
F_51 ( L_30
L_31 ,
V_181 [ 0 ] ,
V_181 [ 1 ] ) ;
V_10 [ 0 ] = V_181 [ 0 ] ;
V_10 [ 1 ] = V_181 [ 1 ] ;
} else
F_51 ( L_33 ) ;
}
static void F_106 ( struct V_86 * V_86 )
{
struct V_107 * V_108 ;
enum V_103 V_104 ;
struct V_101 * V_102 ;
int V_18 ;
for ( V_104 = 0 ; V_104 < V_145 ; V_104 ++ ) {
V_108 = V_86 -> V_111 [ V_104 ] ;
if ( ! V_108 )
continue;
for ( V_18 = 0 ; V_18 < V_108 -> V_112 ; V_18 ++ ) {
V_102 = & V_108 -> V_113 [ V_18 ] ;
V_102 -> V_67 = V_102 -> V_114 ;
V_102 -> V_66 = V_102 -> V_118 ;
V_102 -> V_120 = V_102 -> V_121 ;
V_102 -> V_122 = false ;
}
}
}
static void F_107 ( bool V_180 )
{
char V_10 [ 2 ] ;
char V_182 [ 2 ] ;
struct V_134 * V_134 , * V_183 ;
struct V_124 * V_162 , * V_166 ;
F_108 ( V_184 ) ;
struct V_148 * V_149 ;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_105 ( V_10 , V_180 ) ;
F_83 ( & V_157 ) ;
if ( ! F_21 ( & V_158 ) ) {
F_97 (reg_request, tmp,
&reg_requests_list, list) {
if ( V_162 -> V_92 !=
V_94 )
continue;
F_109 ( & V_162 -> V_35 , & V_184 ) ;
}
}
F_84 ( & V_157 ) ;
F_95 ( & V_167 ) ;
if ( ! F_21 ( & V_168 ) ) {
F_97 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_134 -> V_35 ) ;
F_4 ( V_134 ) ;
}
}
F_96 ( & V_167 ) ;
if ( ! F_21 ( & V_138 ) ) {
F_97 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_134 -> V_35 ) ;
F_4 ( V_134 ) ;
}
}
V_3 = V_4 ;
V_182 [ 0 ] = V_3 -> V_10 [ 0 ] ;
V_182 [ 1 ] = V_3 -> V_10 [ 1 ] ;
F_68 (rdev, &cfg80211_rdev_list, list) {
if ( V_149 -> V_86 . V_67 & V_123 )
F_106 ( & V_149 -> V_86 ) ;
}
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
F_100 ( V_182 ) ;
if ( F_11 ( V_10 ) )
F_101 ( V_13 , V_185 ) ;
if ( F_21 ( & V_184 ) )
return;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
F_83 ( & V_157 ) ;
F_97 (reg_request, tmp, &tmp_reg_req_list, list) {
F_51 ( L_34
L_35 ,
V_162 -> V_10 [ 0 ] ,
V_162 -> V_10 [ 1 ] ) ;
F_109 ( & V_162 -> V_35 , & V_158 ) ;
}
F_84 ( & V_157 ) ;
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
F_51 ( L_36 ) ;
F_28 ( & V_160 ) ;
}
void F_110 ( void )
{
F_51 ( L_37
L_38 ) ;
F_107 ( false ) ;
}
static bool F_111 ( T_3 V_186 )
{
if ( V_186 == F_112 ( 12 , V_187 ) ||
V_186 == F_112 ( 13 , V_187 ) ||
V_186 == F_112 ( 14 , V_187 ) )
return true ;
return false ;
}
int F_113 ( struct V_86 * V_86 ,
struct V_101 * V_188 ,
T_4 V_189 )
{
struct V_134 * V_134 ;
if ( F_64 ( ( V_188 -> V_122 ||
( V_188 -> V_67 & V_83 ) ||
( V_188 -> V_104 == V_187 &&
! F_111 ( V_188 -> V_87 ) ) ) ) )
return 0 ;
V_134 = F_18 ( sizeof( struct V_134 ) , V_189 ) ;
if ( ! V_134 )
return - V_22 ;
F_51 ( L_39
L_40 ,
V_188 -> V_87 ,
F_114 ( V_188 -> V_87 ) ,
F_115 ( V_86 ) ) ;
memcpy ( & V_134 -> V_102 , V_188 ,
sizeof( struct V_101 ) ) ;
F_95 ( & V_167 ) ;
F_27 ( & V_134 -> V_35 , & V_168 ) ;
F_96 ( & V_167 ) ;
F_28 ( & V_160 ) ;
return 0 ;
}
static void F_116 ( const struct V_8 * V_9 )
{
unsigned int V_18 ;
const struct V_20 * V_50 = NULL ;
const struct V_44 * V_45 = NULL ;
const struct V_61 * V_64 = NULL ;
F_32 ( L_41 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_50 = & V_9 -> V_23 [ V_18 ] ;
V_45 = & V_50 -> V_45 ;
V_64 = & V_50 -> V_64 ;
if ( V_64 -> V_66 )
F_32 ( L_42 ,
V_45 -> V_47 ,
V_45 -> V_48 ,
V_45 -> V_49 ,
V_64 -> V_66 ,
V_64 -> V_65 ) ;
else
F_32 ( L_43 ,
V_45 -> V_47 ,
V_45 -> V_48 ,
V_45 -> V_49 ,
V_64 -> V_65 ) ;
}
}
bool F_117 ( T_2 V_146 )
{
switch ( V_146 ) {
case V_190 :
case V_191 :
case V_192 :
case V_193 :
return true ;
default:
F_51 ( L_44 ,
V_146 ) ;
return false ;
}
}
static void F_118 ( T_2 V_146 )
{
if ( ! V_146 )
return;
switch ( V_146 ) {
case V_191 :
F_32 ( L_45 ) ;
break;
case V_192 :
F_32 ( L_46 ) ;
break;
case V_193 :
F_32 ( L_47 ) ;
break;
default:
F_32 ( L_48 ) ;
break;
}
}
static void F_119 ( const struct V_8 * V_9 )
{
if ( F_10 ( V_9 -> V_10 ) ) {
if ( V_6 -> V_92 ==
V_93 ) {
struct V_148 * V_149 ;
V_149 = F_120 (
V_6 -> V_110 ) ;
if ( V_149 ) {
F_32 ( L_49 ,
V_149 -> V_194 [ 0 ] ,
V_149 -> V_194 [ 1 ] ) ;
} else
F_32 ( L_50 ) ;
} else
F_32 ( L_50 ) ;
} else if ( F_7 ( V_9 -> V_10 ) )
F_32 ( L_51 ) ;
else {
if ( F_9 ( V_9 -> V_10 ) )
F_32 ( L_52 ) ;
else {
if ( F_58 ( V_6 ) )
F_32 ( L_53
L_54 ,
V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
else
F_32 ( L_53
L_55 ,
V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
}
}
F_118 ( V_9 -> V_146 ) ;
F_116 ( V_9 ) ;
}
static void F_121 ( const struct V_8 * V_9 )
{
F_32 ( L_56 , V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
F_116 ( V_9 ) ;
}
static int F_122 ( const struct V_8 * V_9 )
{
const struct V_8 * V_195 = NULL ;
struct V_86 * V_109 ;
if ( F_7 ( V_9 -> V_10 ) ) {
if ( F_37 ( ! F_34 ( V_9 -> V_10 ) ) )
return - V_68 ;
F_5 ( V_9 ) ;
return 0 ;
}
if ( ! F_8 ( V_9 -> V_10 ) && ! F_11 ( V_9 -> V_10 ) &&
! F_9 ( V_9 -> V_10 ) )
return - V_68 ;
if ( ! V_6 )
return - V_68 ;
if ( V_6 -> V_92 != V_93 ) {
if ( ! F_13 ( V_9 -> V_10 ) )
return - V_131 ;
}
if ( F_37 ( ! F_34 ( V_9 -> V_10 ) ) )
return - V_68 ;
if ( ! F_36 ( V_9 ) ) {
F_123 ( L_57 ) ;
F_121 ( V_9 ) ;
return - V_68 ;
}
V_109 = F_54 ( V_6 -> V_110 ) ;
if ( ! V_109 &&
( V_6 -> V_92 == V_100 ||
V_6 -> V_92 == V_93 ) ) {
F_90 ( & V_159 , 0 ) ;
return - V_196 ;
}
if ( ! V_6 -> V_153 ) {
int V_30 ;
if ( V_6 -> V_92 != V_100 ) {
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_109 -> V_16 )
return - V_131 ;
V_30 = F_17 ( & V_109 -> V_16 , V_9 ) ;
if ( V_30 )
return V_30 ;
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_6 -> V_92 != V_93 ) {
V_195 = F_44 ( V_9 , V_3 ) ;
if ( ! V_195 )
return - V_68 ;
if ( V_6 -> V_92 == V_100 )
V_109 -> V_16 = V_9 ;
else
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_195 ;
return 0 ;
}
return - V_68 ;
}
int F_25 ( const struct V_8 * V_9 )
{
int V_30 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_30 = F_122 ( V_9 ) ;
if ( V_30 ) {
if ( V_30 == - V_131 )
F_82 () ;
F_4 ( V_9 ) ;
F_24 ( & V_1 ) ;
return V_30 ;
}
if ( ! V_6 -> V_153 )
F_6 ( V_9 != V_3 ) ;
F_76 ( V_6 -> V_92 ) ;
F_119 ( V_3 ) ;
F_87 ( V_6 ) ;
F_82 () ;
F_24 ( & V_1 ) ;
return V_30 ;
}
int F_124 ( struct V_197 * V_40 , struct V_198 * V_174 )
{
if ( V_6 && ! V_6 -> V_156 ) {
if ( F_125 ( V_174 , L_58 ,
V_6 -> V_10 [ 0 ] ,
V_6 -> V_10 [ 1 ] ) )
return - V_22 ;
}
return 0 ;
}
void F_126 ( struct V_86 * V_86 )
{
F_14 () ;
F_20 ( & V_1 ) ;
if ( ! F_61 ( V_86 ) )
V_129 ++ ;
F_75 ( V_86 , V_99 ) ;
F_24 ( & V_1 ) ;
}
void F_127 ( struct V_86 * V_86 )
{
struct V_86 * V_109 = NULL ;
F_14 () ;
F_20 ( & V_1 ) ;
if ( ! F_61 ( V_86 ) )
V_129 -- ;
F_4 ( V_86 -> V_16 ) ;
if ( V_6 )
V_109 = F_54 ( V_6 -> V_110 ) ;
if ( ! V_109 || V_109 != V_86 )
goto V_164;
V_6 -> V_110 = V_170 ;
V_6 -> V_179 = V_175 ;
V_164:
F_24 ( & V_1 ) ;
}
static void F_128 ( struct V_24 * V_25 )
{
F_51 ( L_59
L_60 ) ;
F_107 ( true ) ;
}
int T_5 F_129 ( void )
{
int V_199 = 0 ;
V_39 = F_130 ( L_61 , 0 , NULL , 0 ) ;
if ( F_131 ( V_39 ) )
return F_132 ( V_39 ) ;
V_39 -> V_40 . type = & V_200 ;
F_133 ( & V_157 ) ;
F_133 ( & V_167 ) ;
F_29 () ;
V_3 = V_4 ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
V_199 = F_100 ( V_3 -> V_10 ) ;
if ( V_199 ) {
if ( V_199 == - V_22 )
return V_199 ;
F_123 ( L_62 ) ;
#ifdef F_134
F_37 ( V_199 ) ;
#endif
}
if ( ! F_7 ( V_181 ) )
F_101 ( V_181 ,
V_185 ) ;
return 0 ;
}
void F_135 ( void )
{
struct V_124 * V_162 , * V_166 ;
struct V_134 * V_134 , * V_183 ;
F_136 ( & V_160 ) ;
F_137 ( & V_159 ) ;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_138 ( & V_39 -> V_40 , true ) ;
F_139 ( V_39 ) ;
F_95 ( & V_167 ) ;
if ( ! F_21 ( & V_168 ) ) {
F_97 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_134 -> V_35 ) ;
F_4 ( V_134 ) ;
}
}
F_96 ( & V_167 ) ;
if ( ! F_21 ( & V_138 ) ) {
F_97 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_134 -> V_35 ) ;
F_4 ( V_134 ) ;
}
}
F_83 ( & V_157 ) ;
if ( ! F_21 ( & V_158 ) ) {
F_97 (reg_request, tmp,
&reg_requests_list, list) {
F_23 ( & V_162 -> V_35 ) ;
F_4 ( V_162 ) ;
}
}
F_84 ( & V_157 ) ;
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
}
