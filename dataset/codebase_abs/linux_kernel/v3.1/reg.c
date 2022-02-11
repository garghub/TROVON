static inline void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static void F_3 ( void )
{
if ( V_2 == V_3 )
V_2 = NULL ;
if ( V_3 == & V_4 )
V_3 = NULL ;
if ( V_2 == & V_4 )
V_2 = NULL ;
F_4 ( V_2 ) ;
F_4 ( V_3 ) ;
V_3 = & V_4 ;
V_2 = NULL ;
}
static void F_5 ( const struct V_5 * V_6 )
{
F_6 ( ! V_7 ) ;
F_3 () ;
V_3 = V_6 ;
V_2 = V_6 ;
}
bool F_7 ( const char * V_8 )
{
if ( ! V_8 )
return false ;
if ( V_8 [ 0 ] == '0' && V_8 [ 1 ] == '0' )
return true ;
return false ;
}
static bool F_8 ( const char * V_8 )
{
if ( ! V_8 )
return false ;
if ( V_8 [ 0 ] != 0 && V_8 [ 1 ] != 0 )
return true ;
return false ;
}
static bool F_9 ( const char * V_8 )
{
if ( ! V_8 )
return false ;
if ( V_8 [ 0 ] == '9' && V_8 [ 1 ] == '9' )
return true ;
return false ;
}
static bool F_10 ( const char * V_8 )
{
if ( ! V_8 )
return false ;
if ( V_8 [ 0 ] == '9' && V_8 [ 1 ] == '8' )
return true ;
return false ;
}
static bool F_11 ( const char * V_8 )
{
if ( ! V_8 )
return false ;
if ( isalpha ( V_8 [ 0 ] ) && isalpha ( V_8 [ 1 ] ) )
return true ;
return false ;
}
static bool F_12 ( const char * V_9 , const char * V_10 )
{
if ( ! V_9 || ! V_10 )
return false ;
if ( V_9 [ 0 ] == V_10 [ 0 ] &&
V_9 [ 1 ] == V_10 [ 1 ] )
return true ;
return false ;
}
static bool F_13 ( const char * V_8 )
{
F_14 () ;
if ( ! V_2 )
return true ;
if ( F_12 ( V_2 -> V_8 , V_8 ) )
return false ;
return true ;
}
static bool F_15 ( void )
{
if ( V_11 [ 0 ] == '9' && V_11 [ 1 ] == '7' )
return false ;
if ( F_16 ( ( ! F_7 ( V_11 ) &&
! F_11 ( V_11 ) ) ,
L_1 ,
V_11 [ 0 ] ,
V_11 [ 1 ] ) )
return false ;
return true ;
}
static int F_17 ( const struct V_5 * * V_12 ,
const struct V_5 * V_13 )
{
struct V_5 * V_14 ;
int V_15 = 0 ;
unsigned int V_16 ;
V_15 = sizeof( struct V_5 ) +
( ( V_13 -> V_17 + 1 ) * sizeof( struct V_18 ) ) ;
V_14 = F_18 ( V_15 , V_19 ) ;
if ( ! V_14 )
return - V_20 ;
memcpy ( V_14 , V_13 , sizeof( struct V_5 ) ) ;
for ( V_16 = 0 ; V_16 < V_13 -> V_17 ; V_16 ++ )
memcpy ( & V_14 -> V_21 [ V_16 ] , & V_13 -> V_21 [ V_16 ] ,
sizeof( struct V_18 ) ) ;
* V_12 = V_14 ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
const struct V_5 * V_26 , * V_27 ;
int V_16 , V_28 ;
F_20 ( & V_29 ) ;
while ( ! F_21 ( & V_30 ) ) {
V_25 = F_22 ( & V_30 ,
struct V_24 ,
V_31 ) ;
F_23 ( & V_25 -> V_31 ) ;
for ( V_16 = 0 ; V_16 < V_32 ; V_16 ++ ) {
V_26 = V_33 [ V_16 ] ;
if ( ! memcmp ( V_25 -> V_8 , V_26 -> V_8 , 2 ) ) {
V_28 = F_17 ( & V_27 , V_26 ) ;
if ( V_28 )
break;
F_20 ( & V_34 ) ;
F_24 ( V_27 ) ;
F_25 ( & V_34 ) ;
break;
}
}
F_4 ( V_25 ) ;
}
F_25 ( & V_29 ) ;
}
static void F_26 ( const char * V_8 )
{
struct V_24 * V_25 ;
if ( ! V_8 )
return;
V_25 = F_18 ( sizeof( struct V_24 ) , V_19 ) ;
if ( ! V_25 )
return;
memcpy ( V_25 -> V_8 , V_8 , 2 ) ;
F_20 ( & V_29 ) ;
F_27 ( & V_25 -> V_31 , & V_30 ) ;
F_25 ( & V_29 ) ;
F_28 ( & V_35 ) ;
}
static inline void F_26 ( const char * V_8 ) {}
static int F_29 ( const char * V_8 )
{
if ( ! F_7 ( ( char * ) V_8 ) )
F_30 ( L_2 ,
V_8 [ 0 ] , V_8 [ 1 ] ) ;
else
F_30 ( L_3 ) ;
F_26 ( V_8 ) ;
return F_31 ( & V_36 -> V_37 . V_38 , V_39 ) ;
}
bool F_32 ( const char * V_8 )
{
F_14 () ;
if ( ! V_7 )
return false ;
return F_12 ( V_7 -> V_8 , V_8 ) ;
}
static bool F_33 ( const struct V_18 * V_40 )
{
const struct V_41 * V_42 = & V_40 -> V_42 ;
T_1 V_43 ;
if ( V_42 -> V_44 <= 0 || V_42 -> V_45 <= 0 )
return false ;
if ( V_42 -> V_44 > V_42 -> V_45 )
return false ;
V_43 = V_42 -> V_45 - V_42 -> V_44 ;
if ( V_42 -> V_45 <= V_42 -> V_44 ||
V_42 -> V_46 > V_43 )
return false ;
return true ;
}
static bool F_34 ( const struct V_5 * V_6 )
{
const struct V_18 * V_47 = NULL ;
unsigned int V_16 ;
if ( ! V_6 -> V_17 )
return false ;
if ( F_35 ( V_6 -> V_17 > V_48 ) )
return false ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
V_47 = & V_6 -> V_21 [ V_16 ] ;
if ( ! F_33 ( V_47 ) )
return false ;
}
return true ;
}
static bool F_36 ( const struct V_41 * V_42 ,
T_1 V_49 ,
T_1 V_50 )
{
T_1 V_44 , V_45 ;
V_44 = V_49 - ( V_50 / 2 ) ;
V_45 = V_49 + ( V_50 / 2 ) ;
if ( V_44 >= V_42 -> V_44 &&
V_45 <= V_42 -> V_45 )
return true ;
return false ;
}
static bool F_37 ( const struct V_41 * V_42 ,
T_1 V_51 )
{
#define F_38 1000000
if ( abs ( V_51 - V_42 -> V_44 ) <= ( 2 * F_38 ) )
return true ;
if ( abs ( V_51 - V_42 -> V_45 ) <= ( 2 * F_38 ) )
return true ;
return false ;
#undef F_38
}
static int F_39 (
const struct V_18 * V_52 ,
const struct V_18 * V_53 ,
struct V_18 * V_54 )
{
const struct V_41 * V_55 , * V_56 ;
struct V_41 * V_42 ;
const struct V_57 * V_58 , * V_59 ;
struct V_57 * V_60 ;
T_1 V_43 ;
V_55 = & V_52 -> V_42 ;
V_56 = & V_53 -> V_42 ;
V_42 = & V_54 -> V_42 ;
V_58 = & V_52 -> V_60 ;
V_59 = & V_53 -> V_60 ;
V_60 = & V_54 -> V_60 ;
V_42 -> V_44 = F_40 ( V_55 -> V_44 ,
V_56 -> V_44 ) ;
V_42 -> V_45 = F_41 ( V_55 -> V_45 ,
V_56 -> V_45 ) ;
V_42 -> V_46 = F_41 ( V_55 -> V_46 ,
V_56 -> V_46 ) ;
V_43 = V_42 -> V_45 - V_42 -> V_44 ;
if ( V_42 -> V_46 > V_43 )
V_42 -> V_46 = V_43 ;
V_60 -> V_61 = F_41 ( V_58 -> V_61 ,
V_59 -> V_61 ) ;
V_60 -> V_62 = F_41 ( V_58 -> V_62 ,
V_59 -> V_62 ) ;
V_54 -> V_63 = ( V_52 -> V_63 | V_53 -> V_63 ) ;
if ( ! F_33 ( V_54 ) )
return - V_64 ;
return 0 ;
}
static struct V_5 * F_42 (
const struct V_5 * V_65 ,
const struct V_5 * V_66 )
{
int V_28 , V_15 ;
unsigned int V_67 , V_68 ;
unsigned int V_69 = 0 , V_70 = 0 ;
const struct V_18 * V_52 , * V_53 ;
struct V_18 * V_54 ;
struct V_5 * V_6 ;
struct V_18 V_71 ;
V_54 = & V_71 ;
memset ( V_54 , 0 , sizeof( struct V_18 ) ) ;
if ( ! V_65 || ! V_66 )
return NULL ;
for ( V_67 = 0 ; V_67 < V_65 -> V_17 ; V_67 ++ ) {
V_52 = & V_65 -> V_21 [ V_67 ] ;
for ( V_68 = 0 ; V_68 < V_66 -> V_17 ; V_68 ++ ) {
V_53 = & V_66 -> V_21 [ V_68 ] ;
if ( ! F_39 ( V_52 , V_53 ,
V_54 ) )
V_69 ++ ;
memset ( V_54 , 0 ,
sizeof( struct V_18 ) ) ;
}
}
if ( ! V_69 )
return NULL ;
V_15 = sizeof( struct V_5 ) +
( ( V_69 + 1 ) * sizeof( struct V_18 ) ) ;
V_6 = F_18 ( V_15 , V_19 ) ;
if ( ! V_6 )
return NULL ;
for ( V_67 = 0 ; V_67 < V_65 -> V_17 ; V_67 ++ ) {
V_52 = & V_65 -> V_21 [ V_67 ] ;
for ( V_68 = 0 ; V_68 < V_66 -> V_17 ; V_68 ++ ) {
V_53 = & V_66 -> V_21 [ V_68 ] ;
V_54 = & V_6 -> V_21 [ V_70 ] ;
V_28 = F_39 ( V_52 , V_53 ,
V_54 ) ;
if ( V_28 )
continue;
V_70 ++ ;
}
}
if ( V_70 != V_69 ) {
F_4 ( V_6 ) ;
return NULL ;
}
V_6 -> V_17 = V_69 ;
V_6 -> V_8 [ 0 ] = '9' ;
V_6 -> V_8 [ 1 ] = '8' ;
return V_6 ;
}
static T_1 F_43 ( T_1 V_72 )
{
T_1 V_73 = 0 ;
if ( V_72 & V_74 )
V_73 |= V_75 ;
if ( V_72 & V_76 )
V_73 |= V_77 ;
if ( V_72 & V_78 )
V_73 |= V_79 ;
return V_73 ;
}
static int F_44 ( struct V_80 * V_80 ,
T_1 V_81 ,
T_1 V_82 ,
const struct V_18 * * V_47 ,
const struct V_5 * V_83 )
{
int V_16 ;
bool V_84 = false ;
const struct V_5 * V_14 ;
bool V_85 = false ;
if ( ! V_82 )
V_82 = F_45 ( 20 ) ;
V_14 = V_83 ? V_83 : V_2 ;
if ( ! V_83 &&
V_7 -> V_86 != V_87 &&
V_7 -> V_86 != V_88 &&
V_80 -> V_14 )
V_14 = V_80 -> V_14 ;
if ( ! V_14 )
return - V_64 ;
for ( V_16 = 0 ; V_16 < V_14 -> V_17 ; V_16 ++ ) {
const struct V_18 * V_89 ;
const struct V_41 * V_90 = NULL ;
V_89 = & V_14 -> V_21 [ V_16 ] ;
V_90 = & V_89 -> V_42 ;
if ( ! V_84 )
V_84 = F_37 ( V_90 , V_81 ) ;
V_85 = F_36 ( V_90 ,
V_81 ,
V_82 ) ;
if ( V_84 && V_85 ) {
* V_47 = V_89 ;
return 0 ;
}
}
if ( ! V_84 )
return - V_91 ;
return - V_64 ;
}
int F_46 ( struct V_80 * V_80 ,
T_1 V_81 ,
T_1 V_82 ,
const struct V_18 * * V_47 )
{
F_14 () ;
return F_44 ( V_80 ,
V_81 ,
V_82 ,
V_47 ,
NULL ) ;
}
static const char * F_47 ( enum V_92 V_86 )
{
switch ( V_86 ) {
case V_93 :
return L_4 ;
case V_88 :
return L_5 ;
case V_94 :
return L_6 ;
case V_87 :
return L_7 ;
default:
F_35 ( 1 ) ;
return L_8 ;
}
}
static void F_48 ( struct V_95 * V_96 ,
T_1 V_82 ,
const struct V_18 * V_47 )
{
const struct V_57 * V_60 ;
const struct V_41 * V_42 ;
char V_62 [ 32 ] ;
V_60 = & V_47 -> V_60 ;
V_42 = & V_47 -> V_42 ;
if ( ! V_60 -> V_62 )
snprintf ( V_62 , 32 , L_9 ) ;
else
snprintf ( V_62 , 32 , L_10 , V_60 -> V_62 ) ;
F_49 ( L_11
L_12 ,
V_96 -> V_81 ,
F_50 ( V_82 ) ) ;
F_49 ( L_13 ,
V_42 -> V_44 ,
V_42 -> V_45 ,
V_62 ,
V_60 -> V_61 ) ;
}
static void F_48 ( struct V_95 * V_96 ,
T_1 V_82 ,
const struct V_18 * V_47 )
{
return;
}
static void F_51 ( struct V_80 * V_80 ,
enum V_92 V_86 ,
enum V_97 V_98 ,
unsigned int V_99 )
{
int V_28 ;
T_1 V_63 , V_100 = 0 ;
T_1 V_82 = F_45 ( 20 ) ;
const struct V_18 * V_47 = NULL ;
const struct V_57 * V_60 = NULL ;
const struct V_41 * V_42 = NULL ;
struct V_101 * V_102 ;
struct V_95 * V_96 ;
struct V_80 * V_103 = NULL ;
F_14 () ;
V_103 = F_52 ( V_7 -> V_104 ) ;
V_102 = V_80 -> V_105 [ V_98 ] ;
F_6 ( V_99 >= V_102 -> V_106 ) ;
V_96 = & V_102 -> V_107 [ V_99 ] ;
V_63 = V_96 -> V_108 ;
V_28 = F_46 ( V_80 ,
F_45 ( V_96 -> V_81 ) ,
V_82 ,
& V_47 ) ;
if ( V_28 ) {
if ( V_86 == V_87 &&
V_28 == - V_91 )
return;
F_49 ( L_14 , V_96 -> V_81 ) ;
V_96 -> V_63 = V_109 ;
return;
}
F_48 ( V_96 , V_82 , V_47 ) ;
V_60 = & V_47 -> V_60 ;
V_42 = & V_47 -> V_42 ;
if ( V_42 -> V_46 < F_45 ( 40 ) )
V_100 = V_110 ;
if ( V_7 -> V_86 == V_94 &&
V_103 && V_103 == V_80 &&
V_103 -> V_63 & V_111 ) {
V_96 -> V_63 = V_96 -> V_108 =
F_43 ( V_47 -> V_63 ) | V_100 ;
V_96 -> V_62 = V_96 -> V_112 =
( int ) F_53 ( V_60 -> V_62 ) ;
V_96 -> V_113 = V_96 -> V_114 =
( int ) F_54 ( V_60 -> V_61 ) ;
return;
}
V_96 -> V_115 = false ;
V_96 -> V_63 = V_63 | V_100 | F_43 ( V_47 -> V_63 ) ;
V_96 -> V_62 = F_41 ( V_96 -> V_112 ,
( int ) F_53 ( V_60 -> V_62 ) ) ;
if ( V_96 -> V_114 )
V_96 -> V_113 = F_41 ( V_96 -> V_114 ,
( int ) F_54 ( V_60 -> V_61 ) ) ;
else
V_96 -> V_113 = ( int ) F_54 ( V_60 -> V_61 ) ;
}
static void F_55 ( struct V_80 * V_80 ,
enum V_97 V_98 ,
enum V_92 V_86 )
{
unsigned int V_16 ;
struct V_101 * V_102 ;
F_6 ( ! V_80 -> V_105 [ V_98 ] ) ;
V_102 = V_80 -> V_105 [ V_98 ] ;
for ( V_16 = 0 ; V_16 < V_102 -> V_106 ; V_16 ++ )
F_51 ( V_80 , V_86 , V_98 , V_16 ) ;
}
static bool F_56 ( struct V_80 * V_80 ,
enum V_92 V_86 )
{
if ( ! V_7 ) {
F_49 ( L_15
L_16 ,
F_47 ( V_86 ) ) ;
return true ;
}
if ( V_86 == V_93 &&
V_80 -> V_63 & V_116 ) {
F_49 ( L_17
L_18
L_19 ,
F_47 ( V_86 ) ) ;
return true ;
}
if ( V_80 -> V_63 & V_111 && ! V_80 -> V_14 &&
V_86 != V_87 &&
! F_7 ( V_7 -> V_8 ) ) {
F_49 ( L_17
L_20
L_21 ,
F_47 ( V_86 ) ) ;
return true ;
}
return false ;
}
static void F_57 ( enum V_92 V_86 )
{
struct V_117 * V_118 ;
F_58 (rdev, &cfg80211_rdev_list, list)
F_59 ( & V_118 -> V_80 , V_86 ) ;
}
static void F_60 ( struct V_80 * V_80 ,
unsigned int V_99 ,
struct V_119 * V_119 )
{
struct V_101 * V_102 ;
struct V_95 * V_96 ;
bool V_120 = false ;
struct V_95 V_121 ;
F_14 () ;
V_102 = V_80 -> V_105 [ V_119 -> V_96 . V_98 ] ;
V_96 = & V_102 -> V_107 [ V_99 ] ;
if ( F_61 ( V_96 -> V_81 != V_119 -> V_96 . V_81 ) )
return;
if ( V_96 -> V_115 )
return;
V_96 -> V_115 = true ;
if ( V_80 -> V_63 & V_122 )
return;
V_121 . V_81 = V_96 -> V_81 ;
V_121 . V_63 = V_96 -> V_63 ;
if ( V_96 -> V_63 & V_75 ) {
V_96 -> V_63 &= ~ V_75 ;
V_120 = true ;
}
if ( V_96 -> V_63 & V_77 ) {
V_96 -> V_63 &= ~ V_77 ;
V_120 = true ;
}
if ( V_120 )
F_62 ( V_80 , & V_121 , V_96 ) ;
}
static void F_63 ( struct V_80 * V_80 ,
struct V_119 * V_119 )
{
unsigned int V_16 ;
struct V_101 * V_102 ;
F_14 () ;
if ( ! V_80 -> V_105 [ V_119 -> V_96 . V_98 ] )
return;
V_102 = V_80 -> V_105 [ V_119 -> V_96 . V_98 ] ;
for ( V_16 = 0 ; V_16 < V_102 -> V_106 ; V_16 ++ )
F_60 ( V_80 , V_16 , V_119 ) ;
}
static void F_64 ( struct V_80 * V_80 )
{
unsigned int V_16 ;
struct V_101 * V_102 ;
struct V_119 * V_119 ;
F_14 () ;
if ( F_21 ( & V_123 ) )
return;
F_58 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_80 -> V_105 [ V_119 -> V_96 . V_98 ] )
continue;
V_102 = V_80 -> V_105 [ V_119 -> V_96 . V_98 ] ;
for ( V_16 = 0 ; V_16 < V_102 -> V_106 ; V_16 ++ )
F_60 ( V_80 , V_16 , V_119 ) ;
}
}
static bool F_65 ( struct V_80 * V_80 )
{
if ( F_7 ( V_2 -> V_8 ) ||
( V_80 -> V_14 && F_7 ( V_80 -> V_14 -> V_8 ) ) )
return true ;
if ( V_7 &&
V_7 -> V_86 != V_87 &&
V_80 -> V_63 & V_116 )
return true ;
return false ;
}
static void F_66 ( struct V_80 * V_80 )
{
if ( ! V_7 )
return;
if ( ! F_65 ( V_80 ) )
return;
F_64 ( V_80 ) ;
}
static bool F_67 ( struct V_95 * V_96 )
{
if ( ! V_96 )
return true ;
if ( V_96 -> V_63 & V_109 )
return true ;
if ( V_110 == ( V_96 -> V_63 & ( V_110 ) ) )
return true ;
return false ;
}
static void F_68 ( struct V_80 * V_80 ,
enum V_97 V_98 ,
unsigned int V_99 )
{
struct V_101 * V_102 ;
struct V_95 * V_124 ;
struct V_95 * V_125 = NULL , * V_126 = NULL ;
unsigned int V_16 ;
F_14 () ;
V_102 = V_80 -> V_105 [ V_98 ] ;
F_6 ( V_99 >= V_102 -> V_106 ) ;
V_124 = & V_102 -> V_107 [ V_99 ] ;
if ( F_67 ( V_124 ) ) {
V_124 -> V_63 |= V_110 ;
return;
}
for ( V_16 = 0 ; V_16 < V_102 -> V_106 ; V_16 ++ ) {
struct V_95 * V_127 = & V_102 -> V_107 [ V_16 ] ;
if ( V_127 -> V_81 == ( V_124 -> V_81 - 20 ) )
V_125 = V_127 ;
if ( V_127 -> V_81 == ( V_124 -> V_81 + 20 ) )
V_126 = V_127 ;
}
if ( F_67 ( V_125 ) )
V_124 -> V_63 |= V_128 ;
else
V_124 -> V_63 &= ~ V_128 ;
if ( F_67 ( V_126 ) )
V_124 -> V_63 |= V_129 ;
else
V_124 -> V_63 &= ~ V_129 ;
}
static void F_69 ( struct V_80 * V_80 ,
enum V_97 V_98 )
{
unsigned int V_16 ;
struct V_101 * V_102 ;
F_6 ( ! V_80 -> V_105 [ V_98 ] ) ;
V_102 = V_80 -> V_105 [ V_98 ] ;
for ( V_16 = 0 ; V_16 < V_102 -> V_106 ; V_16 ++ )
F_68 ( V_80 , V_98 , V_16 ) ;
}
static void F_70 ( struct V_80 * V_80 )
{
enum V_97 V_98 ;
if ( ! V_80 )
return;
for ( V_98 = 0 ; V_98 < V_130 ; V_98 ++ ) {
if ( V_80 -> V_105 [ V_98 ] )
F_69 ( V_80 , V_98 ) ;
}
}
void F_59 ( struct V_80 * V_80 ,
enum V_92 V_86 )
{
enum V_97 V_98 ;
if ( F_56 ( V_80 , V_86 ) )
return;
for ( V_98 = 0 ; V_98 < V_130 ; V_98 ++ ) {
if ( V_80 -> V_105 [ V_98 ] )
F_55 ( V_80 , V_98 , V_86 ) ;
}
F_66 ( V_80 ) ;
F_70 ( V_80 ) ;
if ( V_80 -> V_131 )
V_80 -> V_131 ( V_80 , V_7 ) ;
}
static void F_71 ( struct V_80 * V_80 ,
enum V_97 V_98 ,
unsigned int V_99 ,
const struct V_5 * V_14 )
{
int V_28 ;
T_1 V_82 = F_45 ( 20 ) ;
T_1 V_100 = 0 ;
const struct V_18 * V_47 = NULL ;
const struct V_57 * V_60 = NULL ;
const struct V_41 * V_42 = NULL ;
struct V_101 * V_102 ;
struct V_95 * V_96 ;
F_1 () ;
V_102 = V_80 -> V_105 [ V_98 ] ;
F_6 ( V_99 >= V_102 -> V_106 ) ;
V_96 = & V_102 -> V_107 [ V_99 ] ;
V_28 = F_44 ( V_80 ,
F_45 ( V_96 -> V_81 ) ,
V_82 ,
& V_47 ,
V_14 ) ;
if ( V_28 ) {
F_49 ( L_22
L_23
L_24 ,
V_96 -> V_81 ,
F_50 ( V_82 ) ) ;
V_96 -> V_63 = V_109 ;
return;
}
F_48 ( V_96 , V_82 , V_47 ) ;
V_60 = & V_47 -> V_60 ;
V_42 = & V_47 -> V_42 ;
if ( V_42 -> V_46 < F_45 ( 40 ) )
V_100 = V_110 ;
V_96 -> V_63 |= F_43 ( V_47 -> V_63 ) | V_100 ;
V_96 -> V_62 = ( int ) F_53 ( V_60 -> V_62 ) ;
V_96 -> V_113 = ( int ) F_54 ( V_60 -> V_61 ) ;
}
static void F_72 ( struct V_80 * V_80 , enum V_97 V_98 ,
const struct V_5 * V_14 )
{
unsigned int V_16 ;
struct V_101 * V_102 ;
F_6 ( ! V_80 -> V_105 [ V_98 ] ) ;
V_102 = V_80 -> V_105 [ V_98 ] ;
for ( V_16 = 0 ; V_16 < V_102 -> V_106 ; V_16 ++ )
F_71 ( V_80 , V_98 , V_16 , V_14 ) ;
}
void F_73 ( struct V_80 * V_80 ,
const struct V_5 * V_14 )
{
enum V_97 V_98 ;
unsigned int V_132 = 0 ;
F_20 ( & V_1 ) ;
for ( V_98 = 0 ; V_98 < V_130 ; V_98 ++ ) {
if ( ! V_80 -> V_105 [ V_98 ] )
continue;
F_72 ( V_80 , V_98 , V_14 ) ;
V_132 ++ ;
}
F_25 ( & V_1 ) ;
F_35 ( ! V_132 ) ;
}
static int F_74 ( struct V_80 * V_80 ,
struct V_133 * V_134 )
{
struct V_80 * V_135 = NULL ;
F_14 () ;
if ( ! V_7 )
return 0 ;
switch ( V_134 -> V_86 ) {
case V_93 :
return 0 ;
case V_87 :
V_135 = F_52 ( V_7 -> V_104 ) ;
if ( F_75 ( ! F_11 ( V_134 -> V_8 ) ) )
return - V_64 ;
if ( V_7 -> V_86 ==
V_87 ) {
if ( V_135 != V_80 ) {
if ( F_13 ( V_134 -> V_8 ) )
return - V_136 ;
return - V_137 ;
}
if ( F_35 ( F_13 ( V_134 -> V_8 ) ) )
return 0 ;
return - V_137 ;
}
return 0 ;
case V_94 :
if ( V_7 -> V_86 == V_93 ) {
if ( F_13 ( V_134 -> V_8 ) )
return 0 ;
return - V_137 ;
}
if ( V_7 -> V_86 == V_94 &&
! F_13 ( V_134 -> V_8 ) )
return - V_137 ;
return V_138 ;
case V_88 :
if ( V_7 -> V_86 == V_87 )
return V_138 ;
if ( V_7 -> V_86 == V_88 &&
V_7 -> V_139 )
return - V_136 ;
if ( V_7 -> V_86 == V_93 ||
V_7 -> V_86 == V_94 ||
V_7 -> V_86 == V_88 ) {
if ( F_13 ( V_7 -> V_8 ) )
return - V_140 ;
}
if ( ! F_13 ( V_134 -> V_8 ) )
return - V_137 ;
return 0 ;
}
return - V_64 ;
}
static void F_76 ( void )
{
bool V_141 = false ;
V_7 -> V_142 = true ;
F_77 ( & V_143 ) ;
if ( ! F_21 ( & V_144 ) )
V_141 = true ;
F_78 ( & V_143 ) ;
if ( V_7 -> V_86 == V_88 )
F_79 ( & V_145 ) ;
if ( V_141 )
F_28 ( & V_146 ) ;
}
static int F_80 ( struct V_80 * V_80 ,
struct V_133 * V_134 )
{
bool V_139 = false ;
int V_28 = 0 ;
F_14 () ;
V_28 = F_74 ( V_80 , V_134 ) ;
if ( V_28 == V_138 ) {
if ( V_134 -> V_86 ==
V_94 ) {
V_28 = F_17 ( & V_80 -> V_14 , V_2 ) ;
if ( V_28 ) {
F_4 ( V_134 ) ;
return V_28 ;
}
}
V_139 = true ;
} else if ( V_28 ) {
if ( V_28 == - V_137 &&
V_134 -> V_86 ==
V_94 ) {
V_28 = F_17 ( & V_80 -> V_14 , V_2 ) ;
if ( V_28 ) {
F_4 ( V_134 ) ;
return V_28 ;
}
V_28 = - V_137 ;
goto V_147;
}
F_4 ( V_134 ) ;
return V_28 ;
}
V_147:
F_4 ( V_7 ) ;
V_7 = V_134 ;
V_7 -> V_139 = V_139 ;
V_134 = NULL ;
if ( V_7 -> V_86 == V_88 ) {
V_11 [ 0 ] = V_7 -> V_8 [ 0 ] ;
V_11 [ 1 ] = V_7 -> V_8 [ 1 ] ;
}
if ( V_28 < 0 ) {
if ( V_28 == - V_137 ) {
F_81 ( V_7 ) ;
F_76 () ;
}
return V_28 ;
}
return F_29 ( V_7 -> V_8 ) ;
}
static void F_82 ( struct V_133 * V_148 )
{
int V_28 = 0 ;
struct V_80 * V_80 = NULL ;
enum V_92 V_86 = V_148 -> V_86 ;
F_6 ( ! V_148 -> V_8 ) ;
if ( F_83 ( V_148 -> V_104 ) )
V_80 = F_52 ( V_148 -> V_104 ) ;
if ( V_148 -> V_86 == V_94 &&
! V_80 ) {
F_4 ( V_148 ) ;
return;
}
V_28 = F_80 ( V_80 , V_148 ) ;
if ( V_28 == - V_137 && V_80 &&
V_80 -> V_63 & V_111 ) {
F_59 ( V_80 , V_86 ) ;
return;
}
if ( V_28 != - V_137 &&
V_148 -> V_86 == V_88 )
F_84 ( & V_145 , F_85 ( 3142 ) ) ;
}
static void F_86 ( void )
{
struct V_133 * V_148 ;
F_20 ( & V_34 ) ;
F_20 ( & V_1 ) ;
if ( V_7 && ! V_7 -> V_142 ) {
F_49 ( L_25
L_26 ) ;
goto V_149;
}
F_77 ( & V_143 ) ;
if ( F_21 ( & V_144 ) ) {
F_78 ( & V_143 ) ;
goto V_149;
}
V_148 = F_22 ( & V_144 ,
struct V_133 ,
V_31 ) ;
F_87 ( & V_148 -> V_31 ) ;
F_78 ( & V_143 ) ;
F_82 ( V_148 ) ;
V_149:
F_25 ( & V_1 ) ;
F_25 ( & V_34 ) ;
}
static void F_88 ( void )
{
struct V_117 * V_118 ;
struct V_119 * V_150 , * V_151 ;
F_20 ( & V_34 ) ;
F_89 ( & V_152 ) ;
if ( F_21 ( & V_153 ) ) {
F_90 ( & V_152 ) ;
goto V_149;
}
F_91 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_87 ( & V_150 -> V_31 ) ;
F_58 (rdev, &cfg80211_rdev_list, list)
F_63 ( & V_118 -> V_80 , V_150 ) ;
F_27 ( & V_150 -> V_31 , & V_123 ) ;
}
F_90 ( & V_152 ) ;
V_149:
F_25 ( & V_34 ) ;
}
static void F_92 ( struct V_22 * V_23 )
{
F_86 () ;
F_88 () ;
}
static void F_93 ( struct V_133 * V_25 )
{
if ( isalpha ( V_25 -> V_8 [ 0 ] ) )
V_25 -> V_8 [ 0 ] = toupper ( V_25 -> V_8 [ 0 ] ) ;
if ( isalpha ( V_25 -> V_8 [ 1 ] ) )
V_25 -> V_8 [ 1 ] = toupper ( V_25 -> V_8 [ 1 ] ) ;
F_77 ( & V_143 ) ;
F_27 ( & V_25 -> V_31 , & V_144 ) ;
F_78 ( & V_143 ) ;
F_28 ( & V_146 ) ;
}
static int F_94 ( const char * V_8 )
{
struct V_133 * V_25 ;
F_4 ( V_7 ) ;
V_7 = NULL ;
V_25 = F_18 ( sizeof( struct V_133 ) ,
V_19 ) ;
if ( ! V_25 )
return - V_20 ;
V_25 -> V_8 [ 0 ] = V_8 [ 0 ] ;
V_25 -> V_8 [ 1 ] = V_8 [ 1 ] ;
V_25 -> V_86 = V_93 ;
F_93 ( V_25 ) ;
return 0 ;
}
int F_95 ( const char * V_8 )
{
struct V_133 * V_25 ;
F_6 ( ! V_8 ) ;
V_25 = F_18 ( sizeof( struct V_133 ) , V_19 ) ;
if ( ! V_25 )
return - V_20 ;
V_25 -> V_104 = V_154 ;
V_25 -> V_8 [ 0 ] = V_8 [ 0 ] ;
V_25 -> V_8 [ 1 ] = V_8 [ 1 ] ;
V_25 -> V_86 = V_88 ;
F_93 ( V_25 ) ;
return 0 ;
}
int F_96 ( struct V_80 * V_80 , const char * V_8 )
{
struct V_133 * V_25 ;
F_6 ( ! V_8 ) ;
F_6 ( ! V_80 ) ;
V_25 = F_18 ( sizeof( struct V_133 ) , V_19 ) ;
if ( ! V_25 )
return - V_20 ;
V_25 -> V_104 = F_97 ( V_80 ) ;
F_6 ( ! F_83 ( V_25 -> V_104 ) ) ;
V_25 -> V_8 [ 0 ] = V_8 [ 0 ] ;
V_25 -> V_8 [ 1 ] = V_8 [ 1 ] ;
V_25 -> V_86 = V_94 ;
F_93 ( V_25 ) ;
return 0 ;
}
void F_98 ( struct V_80 * V_80 ,
enum V_97 V_98 ,
T_2 * V_155 ,
T_2 V_156 )
{
char V_8 [ 2 ] ;
enum V_157 V_158 = V_159 ;
struct V_133 * V_25 ;
F_20 ( & V_1 ) ;
if ( F_75 ( ! V_7 ) )
goto V_149;
if ( V_156 & 0x01 )
goto V_149;
if ( V_156 < V_160 )
goto V_149;
V_8 [ 0 ] = V_155 [ 0 ] ;
V_8 [ 1 ] = V_155 [ 1 ] ;
if ( V_155 [ 2 ] == 'I' )
V_158 = V_161 ;
else if ( V_155 [ 2 ] == 'O' )
V_158 = V_162 ;
if ( F_61 ( V_7 -> V_86 ==
V_87 &&
F_83 ( V_7 -> V_104 ) ) )
goto V_149;
V_25 = F_18 ( sizeof( struct V_133 ) , V_19 ) ;
if ( ! V_25 )
goto V_149;
V_25 -> V_104 = F_97 ( V_80 ) ;
V_25 -> V_8 [ 0 ] = V_8 [ 0 ] ;
V_25 -> V_8 [ 1 ] = V_8 [ 1 ] ;
V_25 -> V_86 = V_87 ;
V_25 -> V_163 = V_158 ;
F_25 ( & V_1 ) ;
F_93 ( V_25 ) ;
return;
V_149:
F_25 ( & V_1 ) ;
}
static void F_99 ( char * V_8 , bool V_164 )
{
V_8 [ 0 ] = '9' ;
V_8 [ 1 ] = '7' ;
if ( F_15 () ) {
if ( V_164 ) {
F_49 ( L_27
L_28 ) ;
V_11 [ 0 ] = '9' ;
V_11 [ 1 ] = '7' ;
if ( ! F_7 ( V_165 ) ) {
F_49 ( L_29
L_30 ,
V_165 [ 0 ] ,
V_165 [ 1 ] ) ;
V_8 [ 0 ] = V_165 [ 0 ] ;
V_8 [ 1 ] = V_165 [ 1 ] ;
}
} else {
F_49 ( L_27
L_31 ,
V_11 [ 0 ] ,
V_11 [ 1 ] ) ;
V_8 [ 0 ] = V_11 [ 0 ] ;
V_8 [ 1 ] = V_11 [ 1 ] ;
}
} else if ( ! F_7 ( V_165 ) ) {
F_49 ( L_29
L_30 ,
V_165 [ 0 ] ,
V_165 [ 1 ] ) ;
V_8 [ 0 ] = V_165 [ 0 ] ;
V_8 [ 1 ] = V_165 [ 1 ] ;
} else
F_49 ( L_32 ) ;
}
static void F_100 ( bool V_164 )
{
char V_8 [ 2 ] ;
struct V_119 * V_119 , * V_166 ;
struct V_133 * V_148 , * V_151 ;
F_101 ( V_167 ) ;
F_20 ( & V_34 ) ;
F_20 ( & V_1 ) ;
F_3 () ;
F_99 ( V_8 , V_164 ) ;
F_77 ( & V_143 ) ;
if ( ! F_21 ( & V_144 ) ) {
F_91 (reg_request, tmp,
&reg_requests_list, list) {
if ( V_148 -> V_86 !=
V_88 )
continue;
F_23 ( & V_148 -> V_31 ) ;
F_27 ( & V_148 -> V_31 , & V_167 ) ;
}
}
F_78 ( & V_143 ) ;
F_89 ( & V_152 ) ;
if ( ! F_21 ( & V_153 ) ) {
F_91 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_119 -> V_31 ) ;
F_4 ( V_119 ) ;
}
}
F_90 ( & V_152 ) ;
if ( ! F_21 ( & V_123 ) ) {
F_91 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_119 -> V_31 ) ;
F_4 ( V_119 ) ;
}
}
V_2 = V_3 ;
F_25 ( & V_1 ) ;
F_25 ( & V_34 ) ;
F_94 ( V_2 -> V_8 ) ;
if ( F_11 ( V_8 ) )
F_95 ( V_11 ) ;
if ( F_21 ( & V_167 ) )
return;
F_20 ( & V_34 ) ;
F_20 ( & V_1 ) ;
F_77 ( & V_143 ) ;
F_91 (reg_request, tmp, &tmp_reg_req_list, list) {
F_49 ( L_33
L_34 ,
V_148 -> V_8 [ 0 ] ,
V_148 -> V_8 [ 1 ] ) ;
F_23 ( & V_148 -> V_31 ) ;
F_27 ( & V_148 -> V_31 , & V_144 ) ;
}
F_78 ( & V_143 ) ;
F_25 ( & V_1 ) ;
F_25 ( & V_34 ) ;
F_49 ( L_35 ) ;
F_28 ( & V_146 ) ;
}
void F_102 ( void )
{
F_49 ( L_36
L_37 ) ;
F_100 ( false ) ;
}
static bool F_103 ( T_3 V_168 )
{
if ( V_168 == F_104 ( 12 , V_169 ) ||
V_168 == F_104 ( 13 , V_169 ) ||
V_168 == F_104 ( 14 , V_169 ) )
return true ;
return false ;
}
int F_105 ( struct V_80 * V_80 ,
struct V_95 * V_170 ,
T_4 V_171 )
{
struct V_119 * V_119 ;
if ( F_61 ( ( V_170 -> V_115 ||
( V_170 -> V_63 & V_79 ) ||
( V_170 -> V_98 == V_169 &&
! F_103 ( V_170 -> V_81 ) ) ) ) )
return 0 ;
V_119 = F_18 ( sizeof( struct V_119 ) , V_171 ) ;
if ( ! V_119 )
return - V_20 ;
F_49 ( L_38
L_39 ,
V_170 -> V_81 ,
F_106 ( V_170 -> V_81 ) ,
F_107 ( V_80 ) ) ;
memcpy ( & V_119 -> V_96 , V_170 ,
sizeof( struct V_95 ) ) ;
F_89 ( & V_152 ) ;
F_27 ( & V_119 -> V_31 , & V_153 ) ;
F_90 ( & V_152 ) ;
F_28 ( & V_146 ) ;
return 0 ;
}
static void F_108 ( const struct V_5 * V_6 )
{
unsigned int V_16 ;
const struct V_18 * V_47 = NULL ;
const struct V_41 * V_42 = NULL ;
const struct V_57 * V_60 = NULL ;
F_30 ( L_40 ) ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
V_47 = & V_6 -> V_21 [ V_16 ] ;
V_42 = & V_47 -> V_42 ;
V_60 = & V_47 -> V_60 ;
if ( V_60 -> V_62 )
F_30 ( L_41 ,
V_42 -> V_44 ,
V_42 -> V_45 ,
V_42 -> V_46 ,
V_60 -> V_62 ,
V_60 -> V_61 ) ;
else
F_30 ( L_42 ,
V_42 -> V_44 ,
V_42 -> V_45 ,
V_42 -> V_46 ,
V_60 -> V_61 ) ;
}
}
static void F_109 ( const struct V_5 * V_6 )
{
if ( F_10 ( V_6 -> V_8 ) ) {
if ( V_7 -> V_86 ==
V_87 ) {
struct V_117 * V_118 ;
V_118 = F_110 (
V_7 -> V_104 ) ;
if ( V_118 ) {
F_30 ( L_43 ,
V_118 -> V_172 [ 0 ] ,
V_118 -> V_172 [ 1 ] ) ;
} else
F_30 ( L_44 ) ;
} else
F_30 ( L_44 ) ;
} else if ( F_7 ( V_6 -> V_8 ) )
F_30 ( L_45 ) ;
else {
if ( F_9 ( V_6 -> V_8 ) )
F_30 ( L_46 ) ;
else
F_30 ( L_47 ,
V_6 -> V_8 [ 0 ] , V_6 -> V_8 [ 1 ] ) ;
}
F_108 ( V_6 ) ;
}
static void F_111 ( const struct V_5 * V_6 )
{
F_30 ( L_48 , V_6 -> V_8 [ 0 ] , V_6 -> V_8 [ 1 ] ) ;
F_108 ( V_6 ) ;
}
static int F_112 ( const struct V_5 * V_6 )
{
const struct V_5 * V_173 = NULL ;
struct V_117 * V_118 = NULL ;
struct V_80 * V_103 ;
if ( F_7 ( V_6 -> V_8 ) ) {
if ( F_35 ( ! F_32 ( V_6 -> V_8 ) ) )
return - V_64 ;
F_5 ( V_6 ) ;
return 0 ;
}
if ( ! F_8 ( V_6 -> V_8 ) && ! F_11 ( V_6 -> V_8 ) &&
! F_9 ( V_6 -> V_8 ) )
return - V_64 ;
if ( ! V_7 )
return - V_64 ;
if ( V_7 -> V_86 != V_87 ) {
if ( ! F_13 ( V_6 -> V_8 ) )
return - V_64 ;
}
if ( F_35 ( ! F_32 ( V_6 -> V_8 ) ) )
return - V_64 ;
if ( ! F_34 ( V_6 ) ) {
F_113 ( L_49 ) ;
F_111 ( V_6 ) ;
return - V_64 ;
}
V_103 = F_52 ( V_7 -> V_104 ) ;
if ( ! V_7 -> V_139 ) {
int V_28 ;
if ( V_7 -> V_86 != V_94 ) {
F_3 () ;
V_2 = V_6 ;
return 0 ;
}
if ( V_103 -> V_14 )
return - V_137 ;
V_28 = F_17 ( & V_103 -> V_14 , V_6 ) ;
if ( V_28 )
return V_28 ;
F_3 () ;
V_2 = V_6 ;
return 0 ;
}
if ( V_7 -> V_86 != V_87 ) {
V_173 = F_42 ( V_6 , V_2 ) ;
if ( ! V_173 )
return - V_64 ;
if ( V_7 -> V_86 == V_94 )
V_103 -> V_14 = V_6 ;
else
F_4 ( V_6 ) ;
V_6 = NULL ;
F_3 () ;
V_2 = V_173 ;
return 0 ;
}
if ( ! V_173 )
return - V_64 ;
V_118 = F_114 ( V_103 ) ;
V_118 -> V_172 [ 0 ] = V_6 -> V_8 [ 0 ] ;
V_118 -> V_172 [ 1 ] = V_6 -> V_8 [ 1 ] ;
V_118 -> V_158 = V_7 -> V_163 ;
F_6 ( V_173 == V_6 ) ;
F_4 ( V_6 ) ;
V_6 = NULL ;
F_3 () ;
V_2 = V_173 ;
return 0 ;
}
int F_24 ( const struct V_5 * V_6 )
{
int V_28 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_28 = F_112 ( V_6 ) ;
if ( V_28 ) {
F_4 ( V_6 ) ;
F_25 ( & V_1 ) ;
return V_28 ;
}
if ( ! V_7 -> V_139 )
F_6 ( V_6 != V_2 ) ;
F_57 ( V_7 -> V_86 ) ;
F_109 ( V_2 ) ;
F_81 ( V_7 ) ;
F_76 () ;
F_25 ( & V_1 ) ;
return V_28 ;
}
int F_115 ( struct V_174 * V_37 , struct V_175 * V_158 )
{
if ( V_7 && ! V_7 -> V_142 ) {
if ( F_116 ( V_158 , L_50 ,
V_7 -> V_8 [ 0 ] ,
V_7 -> V_8 [ 1 ] ) )
return - V_20 ;
}
return 0 ;
}
int F_115 ( struct V_174 * V_37 , struct V_175 * V_158 )
{
return - V_176 ;
}
void F_117 ( struct V_80 * V_80 )
{
struct V_80 * V_103 = NULL ;
F_14 () ;
F_20 ( & V_1 ) ;
F_4 ( V_80 -> V_14 ) ;
if ( V_7 )
V_103 = F_52 ( V_7 -> V_104 ) ;
if ( ! V_103 || V_103 != V_80 )
goto V_149;
V_7 -> V_104 = V_154 ;
V_7 -> V_163 = V_159 ;
V_149:
F_25 ( & V_1 ) ;
}
static void F_118 ( struct V_22 * V_23 )
{
F_49 ( L_51
L_52 ) ;
F_100 ( true ) ;
}
int T_5 F_119 ( void )
{
int V_177 = 0 ;
V_36 = F_120 ( L_53 , 0 , NULL , 0 ) ;
if ( F_121 ( V_36 ) )
return F_122 ( V_36 ) ;
V_36 -> V_37 . type = & V_178 ;
F_123 ( & V_143 ) ;
F_123 ( & V_152 ) ;
V_2 = V_3 ;
V_11 [ 0 ] = '9' ;
V_11 [ 1 ] = '7' ;
V_177 = F_94 ( V_2 -> V_8 ) ;
if ( V_177 ) {
if ( V_177 == - V_20 )
return V_177 ;
F_113 ( L_54 ) ;
#ifdef F_124
F_35 ( V_177 ) ;
#endif
}
if ( ! F_7 ( V_165 ) )
F_95 ( V_165 ) ;
return 0 ;
}
void F_125 ( void )
{
struct V_133 * V_148 , * V_151 ;
struct V_119 * V_119 , * V_166 ;
F_126 ( & V_146 ) ;
F_79 ( & V_145 ) ;
F_20 ( & V_34 ) ;
F_20 ( & V_1 ) ;
F_3 () ;
F_4 ( V_7 ) ;
F_127 ( V_36 ) ;
F_89 ( & V_152 ) ;
if ( ! F_21 ( & V_153 ) ) {
F_91 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_119 -> V_31 ) ;
F_4 ( V_119 ) ;
}
}
F_90 ( & V_152 ) ;
if ( ! F_21 ( & V_123 ) ) {
F_91 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_119 -> V_31 ) ;
F_4 ( V_119 ) ;
}
}
F_77 ( & V_143 ) ;
if ( ! F_21 ( & V_144 ) ) {
F_91 (reg_request, tmp,
&reg_requests_list, list) {
F_23 ( & V_148 -> V_31 ) ;
F_4 ( V_148 ) ;
}
}
F_78 ( & V_143 ) ;
F_25 ( & V_1 ) ;
F_25 ( & V_34 ) ;
}
