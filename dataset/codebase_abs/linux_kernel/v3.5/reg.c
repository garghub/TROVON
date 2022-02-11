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
F_20 ( & V_31 ) ;
while ( ! F_21 ( & V_32 ) ) {
V_27 = F_22 ( & V_32 ,
struct V_26 ,
V_33 ) ;
F_23 ( & V_27 -> V_33 ) ;
for ( V_18 = 0 ; V_18 < V_34 ; V_18 ++ ) {
V_28 = V_35 [ V_18 ] ;
if ( ! memcmp ( V_27 -> V_10 , V_28 -> V_10 , 2 ) ) {
V_30 = F_17 ( & V_29 , V_28 ) ;
if ( V_30 )
break;
F_20 ( & V_36 ) ;
F_24 ( V_29 ) ;
F_25 ( & V_36 ) ;
break;
}
}
F_4 ( V_27 ) ;
}
F_25 ( & V_31 ) ;
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
F_20 ( & V_31 ) ;
F_27 ( & V_27 -> V_33 , & V_32 ) ;
F_25 ( & V_31 ) ;
F_28 ( & V_37 ) ;
}
static void F_29 ( void )
{
F_30 ( ! V_34 , L_2 ) ;
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
return F_33 ( & V_38 -> V_39 . V_40 , V_41 ) ;
}
bool F_34 ( const char * V_10 )
{
F_14 () ;
if ( ! V_6 )
return false ;
return F_12 ( V_6 -> V_10 , V_10 ) ;
}
static bool F_35 ( const struct V_20 * V_42 )
{
const struct V_43 * V_44 = & V_42 -> V_44 ;
T_1 V_45 ;
if ( V_44 -> V_46 <= 0 || V_44 -> V_47 <= 0 )
return false ;
if ( V_44 -> V_46 > V_44 -> V_47 )
return false ;
V_45 = V_44 -> V_47 - V_44 -> V_46 ;
if ( V_44 -> V_47 <= V_44 -> V_46 ||
V_44 -> V_48 > V_45 )
return false ;
return true ;
}
static bool F_36 ( const struct V_8 * V_9 )
{
const struct V_20 * V_49 = NULL ;
unsigned int V_18 ;
if ( ! V_9 -> V_19 )
return false ;
if ( F_37 ( V_9 -> V_19 > V_50 ) )
return false ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_49 = & V_9 -> V_23 [ V_18 ] ;
if ( ! F_35 ( V_49 ) )
return false ;
}
return true ;
}
static bool F_38 ( const struct V_43 * V_44 ,
T_1 V_51 ,
T_1 V_52 )
{
T_1 V_46 , V_47 ;
V_46 = V_51 - ( V_52 / 2 ) ;
V_47 = V_51 + ( V_52 / 2 ) ;
if ( V_46 >= V_44 -> V_46 &&
V_47 <= V_44 -> V_47 )
return true ;
return false ;
}
static bool F_39 ( const struct V_43 * V_44 ,
T_1 V_53 )
{
#define F_40 1000000
if ( abs ( V_53 - V_44 -> V_46 ) <= ( 2 * F_40 ) )
return true ;
if ( abs ( V_53 - V_44 -> V_47 ) <= ( 2 * F_40 ) )
return true ;
return false ;
#undef F_40
}
static int F_41 (
const struct V_20 * V_54 ,
const struct V_20 * V_55 ,
struct V_20 * V_56 )
{
const struct V_43 * V_57 , * V_58 ;
struct V_43 * V_44 ;
const struct V_59 * V_60 , * V_61 ;
struct V_59 * V_62 ;
T_1 V_45 ;
V_57 = & V_54 -> V_44 ;
V_58 = & V_55 -> V_44 ;
V_44 = & V_56 -> V_44 ;
V_60 = & V_54 -> V_62 ;
V_61 = & V_55 -> V_62 ;
V_62 = & V_56 -> V_62 ;
V_44 -> V_46 = F_42 ( V_57 -> V_46 ,
V_58 -> V_46 ) ;
V_44 -> V_47 = F_43 ( V_57 -> V_47 ,
V_58 -> V_47 ) ;
V_44 -> V_48 = F_43 ( V_57 -> V_48 ,
V_58 -> V_48 ) ;
V_45 = V_44 -> V_47 - V_44 -> V_46 ;
if ( V_44 -> V_48 > V_45 )
V_44 -> V_48 = V_45 ;
V_62 -> V_63 = F_43 ( V_60 -> V_63 ,
V_61 -> V_63 ) ;
V_62 -> V_64 = F_43 ( V_60 -> V_64 ,
V_61 -> V_64 ) ;
V_56 -> V_65 = ( V_54 -> V_65 | V_55 -> V_65 ) ;
if ( ! F_35 ( V_56 ) )
return - V_66 ;
return 0 ;
}
static struct V_8 * F_44 (
const struct V_8 * V_67 ,
const struct V_8 * V_68 )
{
int V_30 , V_17 ;
unsigned int V_69 , V_70 ;
unsigned int V_71 = 0 , V_72 = 0 ;
const struct V_20 * V_54 , * V_55 ;
struct V_20 * V_56 ;
struct V_8 * V_9 ;
struct V_20 V_73 ;
V_56 = & V_73 ;
memset ( V_56 , 0 , sizeof( struct V_20 ) ) ;
if ( ! V_67 || ! V_68 )
return NULL ;
for ( V_69 = 0 ; V_69 < V_67 -> V_19 ; V_69 ++ ) {
V_54 = & V_67 -> V_23 [ V_69 ] ;
for ( V_70 = 0 ; V_70 < V_68 -> V_19 ; V_70 ++ ) {
V_55 = & V_68 -> V_23 [ V_70 ] ;
if ( ! F_41 ( V_54 , V_55 ,
V_56 ) )
V_71 ++ ;
memset ( V_56 , 0 ,
sizeof( struct V_20 ) ) ;
}
}
if ( ! V_71 )
return NULL ;
V_17 = sizeof( struct V_8 ) +
( ( V_71 + 1 ) * sizeof( struct V_20 ) ) ;
V_9 = F_18 ( V_17 , V_21 ) ;
if ( ! V_9 )
return NULL ;
for ( V_69 = 0 ; V_69 < V_67 -> V_19 ; V_69 ++ ) {
V_54 = & V_67 -> V_23 [ V_69 ] ;
for ( V_70 = 0 ; V_70 < V_68 -> V_19 ; V_70 ++ ) {
V_55 = & V_68 -> V_23 [ V_70 ] ;
V_56 = & V_9 -> V_23 [ V_72 ] ;
V_30 = F_41 ( V_54 , V_55 ,
V_56 ) ;
if ( V_30 )
continue;
V_72 ++ ;
}
}
if ( V_72 != V_71 ) {
F_4 ( V_9 ) ;
return NULL ;
}
V_9 -> V_19 = V_71 ;
V_9 -> V_10 [ 0 ] = '9' ;
V_9 -> V_10 [ 1 ] = '8' ;
return V_9 ;
}
static T_1 F_45 ( T_1 V_74 )
{
T_1 V_75 = 0 ;
if ( V_74 & V_76 )
V_75 |= V_77 ;
if ( V_74 & V_78 )
V_75 |= V_79 ;
if ( V_74 & V_80 )
V_75 |= V_81 ;
return V_75 ;
}
static int F_46 ( struct V_82 * V_82 ,
T_1 V_83 ,
T_1 V_84 ,
const struct V_20 * * V_49 ,
const struct V_8 * V_85 )
{
int V_18 ;
bool V_86 = false ;
const struct V_8 * V_16 ;
bool V_87 = false ;
if ( ! V_84 )
V_84 = F_47 ( 20 ) ;
V_16 = V_85 ? V_85 : V_3 ;
if ( ! V_85 &&
V_6 -> V_88 != V_89 &&
V_6 -> V_88 != V_90 &&
V_82 -> V_16 )
V_16 = V_82 -> V_16 ;
if ( ! V_16 )
return - V_66 ;
for ( V_18 = 0 ; V_18 < V_16 -> V_19 ; V_18 ++ ) {
const struct V_20 * V_91 ;
const struct V_43 * V_92 = NULL ;
V_91 = & V_16 -> V_23 [ V_18 ] ;
V_92 = & V_91 -> V_44 ;
if ( ! V_86 )
V_86 = F_39 ( V_92 , V_83 ) ;
V_87 = F_38 ( V_92 ,
V_83 ,
V_84 ) ;
if ( V_86 && V_87 ) {
* V_49 = V_91 ;
return 0 ;
}
}
if ( ! V_86 )
return - V_93 ;
return - V_66 ;
}
int F_48 ( struct V_82 * V_82 ,
T_1 V_83 ,
T_1 V_84 ,
const struct V_20 * * V_49 )
{
F_14 () ;
return F_46 ( V_82 ,
V_83 ,
V_84 ,
V_49 ,
NULL ) ;
}
static const char * F_49 ( enum V_94 V_88 )
{
switch ( V_88 ) {
case V_95 :
return L_5 ;
case V_90 :
return L_6 ;
case V_96 :
return L_7 ;
case V_89 :
return L_8 ;
default:
F_37 ( 1 ) ;
return L_9 ;
}
}
static void F_50 ( struct V_97 * V_98 ,
T_1 V_84 ,
const struct V_20 * V_49 )
{
const struct V_59 * V_62 ;
const struct V_43 * V_44 ;
char V_64 [ 32 ] ;
V_62 = & V_49 -> V_62 ;
V_44 = & V_49 -> V_44 ;
if ( ! V_62 -> V_64 )
snprintf ( V_64 , 32 , L_10 ) ;
else
snprintf ( V_64 , 32 , L_11 , V_62 -> V_64 ) ;
F_51 ( L_12
L_13 ,
V_98 -> V_83 ,
F_52 ( V_84 ) ) ;
F_51 ( L_14 ,
V_44 -> V_46 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_64 ,
V_62 -> V_63 ) ;
}
static void F_50 ( struct V_97 * V_98 ,
T_1 V_84 ,
const struct V_20 * V_49 )
{
return;
}
static void F_53 ( struct V_82 * V_82 ,
enum V_94 V_88 ,
enum V_99 V_100 ,
unsigned int V_101 )
{
int V_30 ;
T_1 V_65 , V_102 = 0 ;
T_1 V_84 = F_47 ( 20 ) ;
const struct V_20 * V_49 = NULL ;
const struct V_59 * V_62 = NULL ;
const struct V_43 * V_44 = NULL ;
struct V_103 * V_104 ;
struct V_97 * V_98 ;
struct V_82 * V_105 = NULL ;
F_14 () ;
V_105 = F_54 ( V_6 -> V_106 ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
F_6 ( V_101 >= V_104 -> V_108 ) ;
V_98 = & V_104 -> V_109 [ V_101 ] ;
V_65 = V_98 -> V_110 ;
V_30 = F_48 ( V_82 ,
F_47 ( V_98 -> V_83 ) ,
V_84 ,
& V_49 ) ;
if ( V_30 ) {
if ( V_88 == V_89 &&
V_30 == - V_93 )
return;
F_51 ( L_15 , V_98 -> V_83 ) ;
V_98 -> V_65 = V_111 ;
return;
}
F_50 ( V_98 , V_84 , V_49 ) ;
V_62 = & V_49 -> V_62 ;
V_44 = & V_49 -> V_44 ;
if ( V_44 -> V_48 < F_47 ( 40 ) )
V_102 = V_112 ;
if ( V_6 -> V_88 == V_96 &&
V_105 && V_105 == V_82 &&
V_105 -> V_65 & V_113 ) {
V_98 -> V_65 = V_98 -> V_110 =
F_45 ( V_49 -> V_65 ) | V_102 ;
V_98 -> V_64 = V_98 -> V_114 =
( int ) F_55 ( V_62 -> V_64 ) ;
V_98 -> V_115 = V_98 -> V_116 =
( int ) F_56 ( V_62 -> V_63 ) ;
return;
}
V_98 -> V_117 = false ;
V_98 -> V_65 = V_65 | V_102 | F_45 ( V_49 -> V_65 ) ;
V_98 -> V_64 = F_43 ( V_98 -> V_114 ,
( int ) F_55 ( V_62 -> V_64 ) ) ;
V_98 -> V_118 = ( int ) F_56 ( V_62 -> V_63 ) ;
V_98 -> V_115 = F_43 ( V_98 -> V_115 , V_98 -> V_118 ) ;
}
static void F_57 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
enum V_94 V_88 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_6 ( ! V_82 -> V_107 [ V_100 ] ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_53 ( V_82 , V_88 , V_100 , V_18 ) ;
}
static bool F_58 ( struct V_82 * V_82 ,
enum V_94 V_88 )
{
if ( ! V_6 ) {
F_51 ( L_16
L_17 ,
F_49 ( V_88 ) ) ;
return true ;
}
if ( V_88 == V_95 &&
V_82 -> V_65 & V_119 ) {
F_51 ( L_18
L_19
L_20 ,
F_49 ( V_88 ) ) ;
return true ;
}
if ( V_82 -> V_65 & V_113 && ! V_82 -> V_16 &&
V_88 != V_89 &&
! F_7 ( V_6 -> V_10 ) ) {
F_51 ( L_18
L_21
L_22 ,
F_49 ( V_88 ) ) ;
return true ;
}
return false ;
}
static void F_59 ( struct V_82 * V_82 ,
unsigned int V_101 ,
struct V_120 * V_120 )
{
struct V_103 * V_104 ;
struct V_97 * V_98 ;
bool V_121 = false ;
struct V_97 V_122 ;
F_14 () ;
V_104 = V_82 -> V_107 [ V_120 -> V_98 . V_100 ] ;
V_98 = & V_104 -> V_109 [ V_101 ] ;
if ( F_60 ( V_98 -> V_83 != V_120 -> V_98 . V_83 ) )
return;
if ( V_98 -> V_117 )
return;
V_98 -> V_117 = true ;
if ( V_82 -> V_65 & V_123 )
return;
V_122 . V_83 = V_98 -> V_83 ;
V_122 . V_65 = V_98 -> V_65 ;
if ( V_98 -> V_65 & V_77 ) {
V_98 -> V_65 &= ~ V_77 ;
V_121 = true ;
}
if ( V_98 -> V_65 & V_79 ) {
V_98 -> V_65 &= ~ V_79 ;
V_121 = true ;
}
if ( V_121 )
F_61 ( V_82 , & V_122 , V_98 ) ;
}
static void F_62 ( struct V_82 * V_82 ,
struct V_120 * V_120 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_14 () ;
if ( ! V_82 -> V_107 [ V_120 -> V_98 . V_100 ] )
return;
V_104 = V_82 -> V_107 [ V_120 -> V_98 . V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_59 ( V_82 , V_18 , V_120 ) ;
}
static void F_63 ( struct V_82 * V_82 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
struct V_120 * V_120 ;
F_14 () ;
if ( F_21 ( & V_124 ) )
return;
F_64 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_82 -> V_107 [ V_120 -> V_98 . V_100 ] )
continue;
V_104 = V_82 -> V_107 [ V_120 -> V_98 . V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_59 ( V_82 , V_18 , V_120 ) ;
}
}
static bool F_65 ( struct V_82 * V_82 )
{
if ( F_7 ( V_3 -> V_10 ) ||
( V_82 -> V_16 && F_7 ( V_82 -> V_16 -> V_10 ) ) )
return true ;
if ( V_6 &&
V_6 -> V_88 != V_89 &&
V_82 -> V_65 & V_119 )
return true ;
return false ;
}
static void F_66 ( struct V_82 * V_82 )
{
if ( ! V_6 )
return;
if ( ! F_65 ( V_82 ) )
return;
F_63 ( V_82 ) ;
}
static bool F_67 ( struct V_97 * V_98 )
{
if ( ! V_98 )
return true ;
if ( V_98 -> V_65 & V_111 )
return true ;
if ( V_112 == ( V_98 -> V_65 & ( V_112 ) ) )
return true ;
return false ;
}
static void F_68 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
unsigned int V_101 )
{
struct V_103 * V_104 ;
struct V_97 * V_125 ;
struct V_97 * V_126 = NULL , * V_127 = NULL ;
unsigned int V_18 ;
F_14 () ;
V_104 = V_82 -> V_107 [ V_100 ] ;
F_6 ( V_101 >= V_104 -> V_108 ) ;
V_125 = & V_104 -> V_109 [ V_101 ] ;
if ( F_67 ( V_125 ) ) {
V_125 -> V_65 |= V_112 ;
return;
}
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ ) {
struct V_97 * V_128 = & V_104 -> V_109 [ V_18 ] ;
if ( V_128 -> V_83 == ( V_125 -> V_83 - 20 ) )
V_126 = V_128 ;
if ( V_128 -> V_83 == ( V_125 -> V_83 + 20 ) )
V_127 = V_128 ;
}
if ( F_67 ( V_126 ) )
V_125 -> V_65 |= V_129 ;
else
V_125 -> V_65 &= ~ V_129 ;
if ( F_67 ( V_127 ) )
V_125 -> V_65 |= V_130 ;
else
V_125 -> V_65 &= ~ V_130 ;
}
static void F_69 ( struct V_82 * V_82 ,
enum V_99 V_100 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_6 ( ! V_82 -> V_107 [ V_100 ] ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_68 ( V_82 , V_100 , V_18 ) ;
}
static void F_70 ( struct V_82 * V_82 )
{
enum V_99 V_100 ;
if ( ! V_82 )
return;
for ( V_100 = 0 ; V_100 < V_131 ; V_100 ++ ) {
if ( V_82 -> V_107 [ V_100 ] )
F_69 ( V_82 , V_100 ) ;
}
}
static void F_71 ( struct V_82 * V_82 ,
enum V_94 V_88 )
{
enum V_99 V_100 ;
F_1 () ;
if ( F_58 ( V_82 , V_88 ) )
return;
V_6 -> V_132 = V_3 -> V_132 ;
for ( V_100 = 0 ; V_100 < V_131 ; V_100 ++ ) {
if ( V_82 -> V_107 [ V_100 ] )
F_57 ( V_82 , V_100 , V_88 ) ;
}
F_66 ( V_82 ) ;
F_70 ( V_82 ) ;
if ( V_82 -> V_133 )
V_82 -> V_133 ( V_82 , V_6 ) ;
}
void F_72 ( struct V_82 * V_82 ,
enum V_94 V_134 )
{
F_20 ( & V_1 ) ;
F_71 ( V_82 , V_134 ) ;
F_25 ( & V_1 ) ;
}
static void F_73 ( enum V_94 V_88 )
{
struct V_135 * V_136 ;
struct V_82 * V_82 ;
F_64 (rdev, &cfg80211_rdev_list, list) {
V_82 = & V_136 -> V_82 ;
F_71 ( V_82 , V_88 ) ;
if ( V_88 == V_95 &&
V_82 -> V_65 & V_119 &&
V_82 -> V_133 )
V_82 -> V_133 ( V_82 , V_6 ) ;
}
}
static void F_74 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
unsigned int V_101 ,
const struct V_8 * V_16 )
{
int V_30 ;
T_1 V_84 = F_47 ( 20 ) ;
T_1 V_102 = 0 ;
const struct V_20 * V_49 = NULL ;
const struct V_59 * V_62 = NULL ;
const struct V_43 * V_44 = NULL ;
struct V_103 * V_104 ;
struct V_97 * V_98 ;
F_1 () ;
V_104 = V_82 -> V_107 [ V_100 ] ;
F_6 ( V_101 >= V_104 -> V_108 ) ;
V_98 = & V_104 -> V_109 [ V_101 ] ;
V_30 = F_46 ( V_82 ,
F_47 ( V_98 -> V_83 ) ,
V_84 ,
& V_49 ,
V_16 ) ;
if ( V_30 ) {
F_51 ( L_23
L_24
L_25 ,
V_98 -> V_83 ,
F_52 ( V_84 ) ) ;
V_98 -> V_65 = V_111 ;
return;
}
F_50 ( V_98 , V_84 , V_49 ) ;
V_62 = & V_49 -> V_62 ;
V_44 = & V_49 -> V_44 ;
if ( V_44 -> V_48 < F_47 ( 40 ) )
V_102 = V_112 ;
V_98 -> V_65 |= F_45 ( V_49 -> V_65 ) | V_102 ;
V_98 -> V_64 = ( int ) F_55 ( V_62 -> V_64 ) ;
V_98 -> V_115 = ( int ) F_56 ( V_62 -> V_63 ) ;
}
static void F_75 ( struct V_82 * V_82 , enum V_99 V_100 ,
const struct V_8 * V_16 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_6 ( ! V_82 -> V_107 [ V_100 ] ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_74 ( V_82 , V_100 , V_18 , V_16 ) ;
}
void F_76 ( struct V_82 * V_82 ,
const struct V_8 * V_16 )
{
enum V_99 V_100 ;
unsigned int V_137 = 0 ;
F_20 ( & V_1 ) ;
for ( V_100 = 0 ; V_100 < V_131 ; V_100 ++ ) {
if ( ! V_82 -> V_107 [ V_100 ] )
continue;
F_75 ( V_82 , V_100 , V_16 ) ;
V_137 ++ ;
}
F_25 ( & V_1 ) ;
F_37 ( ! V_137 ) ;
}
static int F_77 ( struct V_82 * V_82 ,
struct V_138 * V_139 )
{
struct V_82 * V_140 = NULL ;
F_14 () ;
if ( ! V_6 )
return 0 ;
switch ( V_139 -> V_88 ) {
case V_95 :
return 0 ;
case V_89 :
V_140 = F_54 ( V_6 -> V_106 ) ;
if ( F_78 ( ! F_11 ( V_139 -> V_10 ) ) )
return - V_66 ;
if ( V_6 -> V_88 ==
V_89 ) {
if ( V_140 != V_82 ) {
if ( F_13 ( V_139 -> V_10 ) )
return - V_141 ;
return - V_142 ;
}
if ( F_37 ( F_13 ( V_139 -> V_10 ) ) )
return 0 ;
return - V_142 ;
}
return 0 ;
case V_96 :
if ( V_6 -> V_88 == V_95 ) {
if ( F_13 ( V_139 -> V_10 ) )
return 0 ;
return - V_142 ;
}
if ( V_6 -> V_88 == V_96 &&
! F_13 ( V_139 -> V_10 ) )
return - V_142 ;
return V_143 ;
case V_90 :
if ( V_6 -> V_88 == V_89 )
return V_143 ;
if ( V_6 -> V_88 == V_90 &&
V_6 -> V_144 )
return - V_141 ;
if ( V_6 -> V_88 == V_95 ||
V_6 -> V_88 == V_96 ||
V_6 -> V_88 == V_90 ) {
if ( F_13 ( V_6 -> V_10 ) )
return - V_145 ;
}
if ( ! F_13 ( V_139 -> V_10 ) )
return - V_142 ;
return 0 ;
}
return - V_66 ;
}
static void F_79 ( void )
{
bool V_146 = false ;
V_6 -> V_147 = true ;
F_80 ( & V_148 ) ;
if ( ! F_21 ( & V_149 ) )
V_146 = true ;
F_81 ( & V_148 ) ;
if ( V_6 -> V_88 == V_90 )
F_82 ( & V_150 ) ;
if ( V_146 )
F_28 ( & V_151 ) ;
}
static int F_83 ( struct V_82 * V_82 ,
struct V_138 * V_139 )
{
bool V_144 = false ;
int V_30 = 0 ;
F_14 () ;
V_30 = F_77 ( V_82 , V_139 ) ;
if ( V_30 == V_143 ) {
if ( V_139 -> V_88 ==
V_96 ) {
V_30 = F_17 ( & V_82 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_139 ) ;
return V_30 ;
}
}
V_144 = true ;
} else if ( V_30 ) {
if ( V_30 == - V_142 &&
V_139 -> V_88 ==
V_96 ) {
V_30 = F_17 ( & V_82 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_139 ) ;
return V_30 ;
}
V_30 = - V_142 ;
goto V_152;
}
F_4 ( V_139 ) ;
return V_30 ;
}
V_152:
if ( V_6 != & V_7 )
F_4 ( V_6 ) ;
V_6 = V_139 ;
V_6 -> V_144 = V_144 ;
V_139 = NULL ;
if ( V_6 -> V_88 == V_90 ) {
V_13 [ 0 ] = V_6 -> V_10 [ 0 ] ;
V_13 [ 1 ] = V_6 -> V_10 [ 1 ] ;
}
if ( V_30 < 0 ) {
if ( V_30 == - V_142 ) {
F_84 ( V_6 ) ;
F_79 () ;
}
return V_30 ;
}
return F_31 ( V_6 -> V_10 ) ;
}
static void F_85 ( struct V_138 * V_153 ,
enum V_94 V_154 )
{
int V_30 = 0 ;
struct V_82 * V_82 = NULL ;
F_6 ( ! V_153 -> V_10 ) ;
if ( F_86 ( V_153 -> V_106 ) )
V_82 = F_54 ( V_153 -> V_106 ) ;
if ( V_154 == V_96 &&
! V_82 ) {
F_4 ( V_153 ) ;
return;
}
V_30 = F_83 ( V_82 , V_153 ) ;
if ( V_30 == - V_142 && V_82 &&
V_82 -> V_65 & V_113 ) {
F_71 ( V_82 , V_154 ) ;
return;
}
if ( V_30 != - V_142 &&
V_154 == V_90 )
F_87 ( & V_150 , F_88 ( 3142 ) ) ;
}
static void F_89 ( void )
{
struct V_138 * V_153 ;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
if ( V_6 && ! V_6 -> V_147 ) {
F_51 ( L_26
L_27 ) ;
goto V_155;
}
F_80 ( & V_148 ) ;
if ( F_21 ( & V_149 ) ) {
F_81 ( & V_148 ) ;
goto V_155;
}
V_153 = F_22 ( & V_149 ,
struct V_138 ,
V_33 ) ;
F_90 ( & V_153 -> V_33 ) ;
F_81 ( & V_148 ) ;
F_85 ( V_153 , V_153 -> V_88 ) ;
V_155:
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
}
static void F_91 ( void )
{
struct V_135 * V_136 ;
struct V_120 * V_156 , * V_157 ;
F_20 ( & V_36 ) ;
F_92 ( & V_158 ) ;
if ( F_21 ( & V_159 ) ) {
F_93 ( & V_158 ) ;
goto V_155;
}
F_94 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_90 ( & V_156 -> V_33 ) ;
F_64 (rdev, &cfg80211_rdev_list, list)
F_62 ( & V_136 -> V_82 , V_156 ) ;
F_27 ( & V_156 -> V_33 , & V_124 ) ;
}
F_93 ( & V_158 ) ;
V_155:
F_25 ( & V_36 ) ;
}
static void F_95 ( struct V_24 * V_25 )
{
F_89 () ;
F_91 () ;
}
static void F_96 ( struct V_138 * V_27 )
{
if ( isalpha ( V_27 -> V_10 [ 0 ] ) )
V_27 -> V_10 [ 0 ] = toupper ( V_27 -> V_10 [ 0 ] ) ;
if ( isalpha ( V_27 -> V_10 [ 1 ] ) )
V_27 -> V_10 [ 1 ] = toupper ( V_27 -> V_10 [ 1 ] ) ;
F_80 ( & V_148 ) ;
F_27 ( & V_27 -> V_33 , & V_149 ) ;
F_81 ( & V_148 ) ;
F_28 ( & V_151 ) ;
}
static int F_97 ( const char * V_10 )
{
struct V_138 * V_27 ;
V_27 = F_18 ( sizeof( struct V_138 ) ,
V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_95 ;
F_96 ( V_27 ) ;
return 0 ;
}
int F_98 ( const char * V_10 )
{
struct V_138 * V_27 ;
F_6 ( ! V_10 ) ;
V_27 = F_18 ( sizeof( struct V_138 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_106 = V_160 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_90 ;
F_96 ( V_27 ) ;
return 0 ;
}
int F_99 ( struct V_82 * V_82 , const char * V_10 )
{
struct V_138 * V_27 ;
F_6 ( ! V_10 ) ;
F_6 ( ! V_82 ) ;
V_27 = F_18 ( sizeof( struct V_138 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_106 = F_100 ( V_82 ) ;
F_6 ( ! F_86 ( V_27 -> V_106 ) ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_96 ;
F_96 ( V_27 ) ;
return 0 ;
}
void F_101 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
T_2 * V_161 ,
T_2 V_162 )
{
char V_10 [ 2 ] ;
enum V_163 V_164 = V_165 ;
struct V_138 * V_27 ;
F_20 ( & V_1 ) ;
if ( F_78 ( ! V_6 ) )
goto V_155;
if ( V_162 & 0x01 )
goto V_155;
if ( V_162 < V_166 )
goto V_155;
V_10 [ 0 ] = V_161 [ 0 ] ;
V_10 [ 1 ] = V_161 [ 1 ] ;
if ( V_161 [ 2 ] == 'I' )
V_164 = V_167 ;
else if ( V_161 [ 2 ] == 'O' )
V_164 = V_168 ;
if ( F_60 ( V_6 -> V_88 ==
V_89 &&
F_86 ( V_6 -> V_106 ) ) )
goto V_155;
V_27 = F_18 ( sizeof( struct V_138 ) , V_21 ) ;
if ( ! V_27 )
goto V_155;
V_27 -> V_106 = F_100 ( V_82 ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_89 ;
V_27 -> V_169 = V_164 ;
F_25 ( & V_1 ) ;
F_96 ( V_27 ) ;
return;
V_155:
F_25 ( & V_1 ) ;
}
static void F_102 ( char * V_10 , bool V_170 )
{
V_10 [ 0 ] = '9' ;
V_10 [ 1 ] = '7' ;
if ( F_15 () ) {
if ( V_170 ) {
F_51 ( L_28
L_29 ) ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
if ( ! F_7 ( V_171 ) ) {
F_51 ( L_30
L_31 ,
V_171 [ 0 ] ,
V_171 [ 1 ] ) ;
V_10 [ 0 ] = V_171 [ 0 ] ;
V_10 [ 1 ] = V_171 [ 1 ] ;
}
} else {
F_51 ( L_28
L_32 ,
V_13 [ 0 ] ,
V_13 [ 1 ] ) ;
V_10 [ 0 ] = V_13 [ 0 ] ;
V_10 [ 1 ] = V_13 [ 1 ] ;
}
} else if ( ! F_7 ( V_171 ) ) {
F_51 ( L_30
L_31 ,
V_171 [ 0 ] ,
V_171 [ 1 ] ) ;
V_10 [ 0 ] = V_171 [ 0 ] ;
V_10 [ 1 ] = V_171 [ 1 ] ;
} else
F_51 ( L_33 ) ;
}
static void F_103 ( struct V_82 * V_82 )
{
struct V_103 * V_104 ;
enum V_99 V_100 ;
struct V_97 * V_98 ;
int V_18 ;
for ( V_100 = 0 ; V_100 < V_131 ; V_100 ++ ) {
V_104 = V_82 -> V_107 [ V_100 ] ;
if ( ! V_104 )
continue;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ ) {
V_98 = & V_104 -> V_109 [ V_18 ] ;
V_98 -> V_65 = V_98 -> V_110 ;
V_98 -> V_64 = V_98 -> V_114 ;
V_98 -> V_115 = V_98 -> V_116 ;
}
}
}
static void F_104 ( bool V_170 )
{
char V_10 [ 2 ] ;
char V_172 [ 2 ] ;
struct V_120 * V_120 , * V_173 ;
struct V_138 * V_153 , * V_157 ;
F_105 ( V_174 ) ;
struct V_135 * V_136 ;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_102 ( V_10 , V_170 ) ;
F_80 ( & V_148 ) ;
if ( ! F_21 ( & V_149 ) ) {
F_94 (reg_request, tmp,
&reg_requests_list, list) {
if ( V_153 -> V_88 !=
V_90 )
continue;
F_23 ( & V_153 -> V_33 ) ;
F_27 ( & V_153 -> V_33 , & V_174 ) ;
}
}
F_81 ( & V_148 ) ;
F_92 ( & V_158 ) ;
if ( ! F_21 ( & V_159 ) ) {
F_94 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_120 -> V_33 ) ;
F_4 ( V_120 ) ;
}
}
F_93 ( & V_158 ) ;
if ( ! F_21 ( & V_124 ) ) {
F_94 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_120 -> V_33 ) ;
F_4 ( V_120 ) ;
}
}
V_3 = V_4 ;
V_172 [ 0 ] = V_3 -> V_10 [ 0 ] ;
V_172 [ 1 ] = V_3 -> V_10 [ 1 ] ;
F_64 (rdev, &cfg80211_rdev_list, list) {
if ( V_136 -> V_82 . V_65 & V_119 )
F_103 ( & V_136 -> V_82 ) ;
}
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
F_97 ( V_172 ) ;
if ( F_11 ( V_10 ) )
F_98 ( V_13 ) ;
if ( F_21 ( & V_174 ) )
return;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
F_80 ( & V_148 ) ;
F_94 (reg_request, tmp, &tmp_reg_req_list, list) {
F_51 ( L_34
L_35 ,
V_153 -> V_10 [ 0 ] ,
V_153 -> V_10 [ 1 ] ) ;
F_23 ( & V_153 -> V_33 ) ;
F_27 ( & V_153 -> V_33 , & V_149 ) ;
}
F_81 ( & V_148 ) ;
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
F_51 ( L_36 ) ;
F_28 ( & V_151 ) ;
}
void F_106 ( void )
{
F_51 ( L_37
L_38 ) ;
F_104 ( false ) ;
}
static bool F_107 ( T_3 V_175 )
{
if ( V_175 == F_108 ( 12 , V_176 ) ||
V_175 == F_108 ( 13 , V_176 ) ||
V_175 == F_108 ( 14 , V_176 ) )
return true ;
return false ;
}
int F_109 ( struct V_82 * V_82 ,
struct V_97 * V_177 ,
T_4 V_178 )
{
struct V_120 * V_120 ;
if ( F_60 ( ( V_177 -> V_117 ||
( V_177 -> V_65 & V_81 ) ||
( V_177 -> V_100 == V_176 &&
! F_107 ( V_177 -> V_83 ) ) ) ) )
return 0 ;
V_120 = F_18 ( sizeof( struct V_120 ) , V_178 ) ;
if ( ! V_120 )
return - V_22 ;
F_51 ( L_39
L_40 ,
V_177 -> V_83 ,
F_110 ( V_177 -> V_83 ) ,
F_111 ( V_82 ) ) ;
memcpy ( & V_120 -> V_98 , V_177 ,
sizeof( struct V_97 ) ) ;
F_92 ( & V_158 ) ;
F_27 ( & V_120 -> V_33 , & V_159 ) ;
F_93 ( & V_158 ) ;
F_28 ( & V_151 ) ;
return 0 ;
}
static void F_112 ( const struct V_8 * V_9 )
{
unsigned int V_18 ;
const struct V_20 * V_49 = NULL ;
const struct V_43 * V_44 = NULL ;
const struct V_59 * V_62 = NULL ;
F_32 ( L_41 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_49 = & V_9 -> V_23 [ V_18 ] ;
V_44 = & V_49 -> V_44 ;
V_62 = & V_49 -> V_62 ;
if ( V_62 -> V_64 )
F_32 ( L_42 ,
V_44 -> V_46 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_62 -> V_64 ,
V_62 -> V_63 ) ;
else
F_32 ( L_43 ,
V_44 -> V_46 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_62 -> V_63 ) ;
}
}
bool F_113 ( T_2 V_132 )
{
switch ( V_132 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
return true ;
default:
F_51 ( L_44 ,
V_132 ) ;
return false ;
}
}
static void F_114 ( T_2 V_132 )
{
if ( ! V_132 )
return;
switch ( V_132 ) {
case V_180 :
F_32 ( L_45 ) ;
break;
case V_181 :
F_32 ( L_46 ) ;
break;
case V_182 :
F_32 ( L_47 ) ;
break;
default:
F_32 ( L_48 ) ;
break;
}
}
static void F_115 ( const struct V_8 * V_9 )
{
if ( F_10 ( V_9 -> V_10 ) ) {
if ( V_6 -> V_88 ==
V_89 ) {
struct V_135 * V_136 ;
V_136 = F_116 (
V_6 -> V_106 ) ;
if ( V_136 ) {
F_32 ( L_49 ,
V_136 -> V_183 [ 0 ] ,
V_136 -> V_183 [ 1 ] ) ;
} else
F_32 ( L_50 ) ;
} else
F_32 ( L_50 ) ;
} else if ( F_7 ( V_9 -> V_10 ) )
F_32 ( L_51 ) ;
else {
if ( F_9 ( V_9 -> V_10 ) )
F_32 ( L_52 ) ;
else
F_32 ( L_53 ,
V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
}
F_114 ( V_9 -> V_132 ) ;
F_112 ( V_9 ) ;
}
static void F_117 ( const struct V_8 * V_9 )
{
F_32 ( L_54 , V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
F_112 ( V_9 ) ;
}
static int F_118 ( const struct V_8 * V_9 )
{
const struct V_8 * V_184 = NULL ;
struct V_135 * V_136 = NULL ;
struct V_82 * V_105 ;
if ( F_7 ( V_9 -> V_10 ) ) {
if ( F_37 ( ! F_34 ( V_9 -> V_10 ) ) )
return - V_66 ;
F_5 ( V_9 ) ;
return 0 ;
}
if ( ! F_8 ( V_9 -> V_10 ) && ! F_11 ( V_9 -> V_10 ) &&
! F_9 ( V_9 -> V_10 ) )
return - V_66 ;
if ( ! V_6 )
return - V_66 ;
if ( V_6 -> V_88 != V_89 ) {
if ( ! F_13 ( V_9 -> V_10 ) )
return - V_66 ;
}
if ( F_37 ( ! F_34 ( V_9 -> V_10 ) ) )
return - V_66 ;
if ( ! F_36 ( V_9 ) ) {
F_119 ( L_55 ) ;
F_117 ( V_9 ) ;
return - V_66 ;
}
V_105 = F_54 ( V_6 -> V_106 ) ;
if ( ! V_105 &&
( V_6 -> V_88 == V_96 ||
V_6 -> V_88 == V_89 ) ) {
F_87 ( & V_150 , 0 ) ;
return - V_185 ;
}
if ( ! V_6 -> V_144 ) {
int V_30 ;
if ( V_6 -> V_88 != V_96 ) {
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_105 -> V_16 )
return - V_142 ;
V_30 = F_17 ( & V_105 -> V_16 , V_9 ) ;
if ( V_30 )
return V_30 ;
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_6 -> V_88 != V_89 ) {
V_184 = F_44 ( V_9 , V_3 ) ;
if ( ! V_184 )
return - V_66 ;
if ( V_6 -> V_88 == V_96 )
V_105 -> V_16 = V_9 ;
else
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_184 ;
return 0 ;
}
if ( ! V_184 )
return - V_66 ;
V_136 = F_120 ( V_105 ) ;
V_136 -> V_183 [ 0 ] = V_9 -> V_10 [ 0 ] ;
V_136 -> V_183 [ 1 ] = V_9 -> V_10 [ 1 ] ;
V_136 -> V_164 = V_6 -> V_169 ;
F_6 ( V_184 == V_9 ) ;
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_184 ;
return 0 ;
}
int F_24 ( const struct V_8 * V_9 )
{
int V_30 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_30 = F_118 ( V_9 ) ;
if ( V_30 ) {
F_4 ( V_9 ) ;
F_25 ( & V_1 ) ;
return V_30 ;
}
if ( ! V_6 -> V_144 )
F_6 ( V_9 != V_3 ) ;
F_73 ( V_6 -> V_88 ) ;
F_115 ( V_3 ) ;
F_84 ( V_6 ) ;
F_79 () ;
F_25 ( & V_1 ) ;
return V_30 ;
}
int F_121 ( struct V_186 * V_39 , struct V_187 * V_164 )
{
if ( V_6 && ! V_6 -> V_147 ) {
if ( F_122 ( V_164 , L_56 ,
V_6 -> V_10 [ 0 ] ,
V_6 -> V_10 [ 1 ] ) )
return - V_22 ;
}
return 0 ;
}
int F_121 ( struct V_186 * V_39 , struct V_187 * V_164 )
{
return - V_185 ;
}
void F_123 ( struct V_82 * V_82 )
{
struct V_82 * V_105 = NULL ;
F_14 () ;
F_20 ( & V_1 ) ;
F_4 ( V_82 -> V_16 ) ;
if ( V_6 )
V_105 = F_54 ( V_6 -> V_106 ) ;
if ( ! V_105 || V_105 != V_82 )
goto V_155;
V_6 -> V_106 = V_160 ;
V_6 -> V_169 = V_165 ;
V_155:
F_25 ( & V_1 ) ;
}
static void F_124 ( struct V_24 * V_25 )
{
F_51 ( L_57
L_58 ) ;
F_104 ( true ) ;
}
int T_5 F_125 ( void )
{
int V_188 = 0 ;
V_38 = F_126 ( L_59 , 0 , NULL , 0 ) ;
if ( F_127 ( V_38 ) )
return F_128 ( V_38 ) ;
V_38 -> V_39 . type = & V_189 ;
F_129 ( & V_148 ) ;
F_129 ( & V_158 ) ;
F_29 () ;
V_3 = V_4 ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
V_188 = F_97 ( V_3 -> V_10 ) ;
if ( V_188 ) {
if ( V_188 == - V_22 )
return V_188 ;
F_119 ( L_60 ) ;
#ifdef F_130
F_37 ( V_188 ) ;
#endif
}
if ( ! F_7 ( V_171 ) )
F_98 ( V_171 ) ;
return 0 ;
}
void F_131 ( void )
{
struct V_138 * V_153 , * V_157 ;
struct V_120 * V_120 , * V_173 ;
F_132 ( & V_151 ) ;
F_133 ( & V_150 ) ;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_134 ( & V_38 -> V_39 , true ) ;
F_135 ( V_38 ) ;
F_92 ( & V_158 ) ;
if ( ! F_21 ( & V_159 ) ) {
F_94 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_120 -> V_33 ) ;
F_4 ( V_120 ) ;
}
}
F_93 ( & V_158 ) ;
if ( ! F_21 ( & V_124 ) ) {
F_94 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_120 -> V_33 ) ;
F_4 ( V_120 ) ;
}
}
F_80 ( & V_148 ) ;
if ( ! F_21 ( & V_149 ) ) {
F_94 (reg_request, tmp,
&reg_requests_list, list) {
F_23 ( & V_153 -> V_33 ) ;
F_4 ( V_153 ) ;
}
}
F_81 ( & V_148 ) ;
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
}
