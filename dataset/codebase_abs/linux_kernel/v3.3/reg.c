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
static inline void F_26 ( const char * V_10 ) {}
static int F_29 ( const char * V_10 )
{
if ( ! F_7 ( ( char * ) V_10 ) )
F_30 ( L_2 ,
V_10 [ 0 ] , V_10 [ 1 ] ) ;
else
F_30 ( L_3 ) ;
F_26 ( V_10 ) ;
return F_31 ( & V_38 -> V_39 . V_40 , V_41 ) ;
}
bool F_32 ( const char * V_10 )
{
F_14 () ;
if ( ! V_6 )
return false ;
return F_12 ( V_6 -> V_10 , V_10 ) ;
}
static bool F_33 ( const struct V_20 * V_42 )
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
static bool F_34 ( const struct V_8 * V_9 )
{
const struct V_20 * V_49 = NULL ;
unsigned int V_18 ;
if ( ! V_9 -> V_19 )
return false ;
if ( F_35 ( V_9 -> V_19 > V_50 ) )
return false ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_49 = & V_9 -> V_23 [ V_18 ] ;
if ( ! F_33 ( V_49 ) )
return false ;
}
return true ;
}
static bool F_36 ( const struct V_43 * V_44 ,
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
static bool F_37 ( const struct V_43 * V_44 ,
T_1 V_53 )
{
#define F_38 1000000
if ( abs ( V_53 - V_44 -> V_46 ) <= ( 2 * F_38 ) )
return true ;
if ( abs ( V_53 - V_44 -> V_47 ) <= ( 2 * F_38 ) )
return true ;
return false ;
#undef F_38
}
static int F_39 (
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
V_44 -> V_46 = F_40 ( V_57 -> V_46 ,
V_58 -> V_46 ) ;
V_44 -> V_47 = F_41 ( V_57 -> V_47 ,
V_58 -> V_47 ) ;
V_44 -> V_48 = F_41 ( V_57 -> V_48 ,
V_58 -> V_48 ) ;
V_45 = V_44 -> V_47 - V_44 -> V_46 ;
if ( V_44 -> V_48 > V_45 )
V_44 -> V_48 = V_45 ;
V_62 -> V_63 = F_41 ( V_60 -> V_63 ,
V_61 -> V_63 ) ;
V_62 -> V_64 = F_41 ( V_60 -> V_64 ,
V_61 -> V_64 ) ;
V_56 -> V_65 = ( V_54 -> V_65 | V_55 -> V_65 ) ;
if ( ! F_33 ( V_56 ) )
return - V_66 ;
return 0 ;
}
static struct V_8 * F_42 (
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
if ( ! F_39 ( V_54 , V_55 ,
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
V_30 = F_39 ( V_54 , V_55 ,
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
static T_1 F_43 ( T_1 V_74 )
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
static int F_44 ( struct V_82 * V_82 ,
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
V_84 = F_45 ( 20 ) ;
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
V_86 = F_37 ( V_92 , V_83 ) ;
V_87 = F_36 ( V_92 ,
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
int F_46 ( struct V_82 * V_82 ,
T_1 V_83 ,
T_1 V_84 ,
const struct V_20 * * V_49 )
{
F_14 () ;
return F_44 ( V_82 ,
V_83 ,
V_84 ,
V_49 ,
NULL ) ;
}
static const char * F_47 ( enum V_94 V_88 )
{
switch ( V_88 ) {
case V_95 :
return L_4 ;
case V_90 :
return L_5 ;
case V_96 :
return L_6 ;
case V_89 :
return L_7 ;
default:
F_35 ( 1 ) ;
return L_8 ;
}
}
static void F_48 ( struct V_97 * V_98 ,
T_1 V_84 ,
const struct V_20 * V_49 )
{
const struct V_59 * V_62 ;
const struct V_43 * V_44 ;
char V_64 [ 32 ] ;
V_62 = & V_49 -> V_62 ;
V_44 = & V_49 -> V_44 ;
if ( ! V_62 -> V_64 )
snprintf ( V_64 , 32 , L_9 ) ;
else
snprintf ( V_64 , 32 , L_10 , V_62 -> V_64 ) ;
F_49 ( L_11
L_12 ,
V_98 -> V_83 ,
F_50 ( V_84 ) ) ;
F_49 ( L_13 ,
V_44 -> V_46 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_64 ,
V_62 -> V_63 ) ;
}
static void F_48 ( struct V_97 * V_98 ,
T_1 V_84 ,
const struct V_20 * V_49 )
{
return;
}
static void F_51 ( struct V_82 * V_82 ,
enum V_94 V_88 ,
enum V_99 V_100 ,
unsigned int V_101 )
{
int V_30 ;
T_1 V_65 , V_102 = 0 ;
T_1 V_84 = F_45 ( 20 ) ;
const struct V_20 * V_49 = NULL ;
const struct V_59 * V_62 = NULL ;
const struct V_43 * V_44 = NULL ;
struct V_103 * V_104 ;
struct V_97 * V_98 ;
struct V_82 * V_105 = NULL ;
F_14 () ;
V_105 = F_52 ( V_6 -> V_106 ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
F_6 ( V_101 >= V_104 -> V_108 ) ;
V_98 = & V_104 -> V_109 [ V_101 ] ;
V_65 = V_98 -> V_110 ;
V_30 = F_46 ( V_82 ,
F_45 ( V_98 -> V_83 ) ,
V_84 ,
& V_49 ) ;
if ( V_30 ) {
if ( V_88 == V_89 &&
V_30 == - V_93 )
return;
F_49 ( L_14 , V_98 -> V_83 ) ;
V_98 -> V_65 = V_111 ;
return;
}
F_48 ( V_98 , V_84 , V_49 ) ;
V_62 = & V_49 -> V_62 ;
V_44 = & V_49 -> V_44 ;
if ( V_44 -> V_48 < F_45 ( 40 ) )
V_102 = V_112 ;
if ( V_6 -> V_88 == V_96 &&
V_105 && V_105 == V_82 &&
V_105 -> V_65 & V_113 ) {
V_98 -> V_65 = V_98 -> V_110 =
F_43 ( V_49 -> V_65 ) | V_102 ;
V_98 -> V_64 = V_98 -> V_114 =
( int ) F_53 ( V_62 -> V_64 ) ;
V_98 -> V_115 = V_98 -> V_116 =
( int ) F_54 ( V_62 -> V_63 ) ;
return;
}
V_98 -> V_117 = false ;
V_98 -> V_65 = V_65 | V_102 | F_43 ( V_49 -> V_65 ) ;
V_98 -> V_64 = F_41 ( V_98 -> V_114 ,
( int ) F_53 ( V_62 -> V_64 ) ) ;
if ( V_98 -> V_116 ) {
if ( V_88 == V_89 &&
V_82 -> V_65 & V_118 &&
V_82 -> V_65 & V_113 ) {
V_98 -> V_115 =
F_54 ( V_62 -> V_63 ) ;
} else {
V_98 -> V_115 = F_41 ( V_98 -> V_116 ,
( int ) F_54 ( V_62 -> V_63 ) ) ;
}
} else
V_98 -> V_115 = ( int ) F_54 ( V_62 -> V_63 ) ;
}
static void F_55 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
enum V_94 V_88 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_6 ( ! V_82 -> V_107 [ V_100 ] ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_51 ( V_82 , V_88 , V_100 , V_18 ) ;
}
static bool F_56 ( struct V_82 * V_82 ,
enum V_94 V_88 )
{
if ( ! V_6 ) {
F_49 ( L_15
L_16 ,
F_47 ( V_88 ) ) ;
return true ;
}
if ( V_88 == V_95 &&
V_82 -> V_65 & V_118 ) {
F_49 ( L_17
L_18
L_19 ,
F_47 ( V_88 ) ) ;
return true ;
}
if ( V_82 -> V_65 & V_113 && ! V_82 -> V_16 &&
V_88 != V_89 &&
! F_7 ( V_6 -> V_10 ) ) {
F_49 ( L_17
L_20
L_21 ,
F_47 ( V_88 ) ) ;
return true ;
}
return false ;
}
static void F_57 ( struct V_82 * V_82 ,
unsigned int V_101 ,
struct V_119 * V_119 )
{
struct V_103 * V_104 ;
struct V_97 * V_98 ;
bool V_120 = false ;
struct V_97 V_121 ;
F_14 () ;
V_104 = V_82 -> V_107 [ V_119 -> V_98 . V_100 ] ;
V_98 = & V_104 -> V_109 [ V_101 ] ;
if ( F_58 ( V_98 -> V_83 != V_119 -> V_98 . V_83 ) )
return;
if ( V_98 -> V_117 )
return;
V_98 -> V_117 = true ;
if ( V_82 -> V_65 & V_122 )
return;
V_121 . V_83 = V_98 -> V_83 ;
V_121 . V_65 = V_98 -> V_65 ;
if ( V_98 -> V_65 & V_77 ) {
V_98 -> V_65 &= ~ V_77 ;
V_120 = true ;
}
if ( V_98 -> V_65 & V_79 ) {
V_98 -> V_65 &= ~ V_79 ;
V_120 = true ;
}
if ( V_120 )
F_59 ( V_82 , & V_121 , V_98 ) ;
}
static void F_60 ( struct V_82 * V_82 ,
struct V_119 * V_119 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_14 () ;
if ( ! V_82 -> V_107 [ V_119 -> V_98 . V_100 ] )
return;
V_104 = V_82 -> V_107 [ V_119 -> V_98 . V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_57 ( V_82 , V_18 , V_119 ) ;
}
static void F_61 ( struct V_82 * V_82 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
struct V_119 * V_119 ;
F_14 () ;
if ( F_21 ( & V_123 ) )
return;
F_62 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_82 -> V_107 [ V_119 -> V_98 . V_100 ] )
continue;
V_104 = V_82 -> V_107 [ V_119 -> V_98 . V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_57 ( V_82 , V_18 , V_119 ) ;
}
}
static bool F_63 ( struct V_82 * V_82 )
{
if ( F_7 ( V_3 -> V_10 ) ||
( V_82 -> V_16 && F_7 ( V_82 -> V_16 -> V_10 ) ) )
return true ;
if ( V_6 &&
V_6 -> V_88 != V_89 &&
V_82 -> V_65 & V_118 )
return true ;
return false ;
}
static void F_64 ( struct V_82 * V_82 )
{
if ( ! V_6 )
return;
if ( ! F_63 ( V_82 ) )
return;
F_61 ( V_82 ) ;
}
static bool F_65 ( struct V_97 * V_98 )
{
if ( ! V_98 )
return true ;
if ( V_98 -> V_65 & V_111 )
return true ;
if ( V_112 == ( V_98 -> V_65 & ( V_112 ) ) )
return true ;
return false ;
}
static void F_66 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
unsigned int V_101 )
{
struct V_103 * V_104 ;
struct V_97 * V_124 ;
struct V_97 * V_125 = NULL , * V_126 = NULL ;
unsigned int V_18 ;
F_14 () ;
V_104 = V_82 -> V_107 [ V_100 ] ;
F_6 ( V_101 >= V_104 -> V_108 ) ;
V_124 = & V_104 -> V_109 [ V_101 ] ;
if ( F_65 ( V_124 ) ) {
V_124 -> V_65 |= V_112 ;
return;
}
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ ) {
struct V_97 * V_127 = & V_104 -> V_109 [ V_18 ] ;
if ( V_127 -> V_83 == ( V_124 -> V_83 - 20 ) )
V_125 = V_127 ;
if ( V_127 -> V_83 == ( V_124 -> V_83 + 20 ) )
V_126 = V_127 ;
}
if ( F_65 ( V_125 ) )
V_124 -> V_65 |= V_128 ;
else
V_124 -> V_65 &= ~ V_128 ;
if ( F_65 ( V_126 ) )
V_124 -> V_65 |= V_129 ;
else
V_124 -> V_65 &= ~ V_129 ;
}
static void F_67 ( struct V_82 * V_82 ,
enum V_99 V_100 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_6 ( ! V_82 -> V_107 [ V_100 ] ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_66 ( V_82 , V_100 , V_18 ) ;
}
static void F_68 ( struct V_82 * V_82 )
{
enum V_99 V_100 ;
if ( ! V_82 )
return;
for ( V_100 = 0 ; V_100 < V_130 ; V_100 ++ ) {
if ( V_82 -> V_107 [ V_100 ] )
F_67 ( V_82 , V_100 ) ;
}
}
static void F_69 ( struct V_82 * V_82 ,
enum V_94 V_88 )
{
enum V_99 V_100 ;
F_1 () ;
if ( F_56 ( V_82 , V_88 ) )
return;
V_6 -> V_131 = V_3 -> V_131 ;
for ( V_100 = 0 ; V_100 < V_130 ; V_100 ++ ) {
if ( V_82 -> V_107 [ V_100 ] )
F_55 ( V_82 , V_100 , V_88 ) ;
}
F_64 ( V_82 ) ;
F_68 ( V_82 ) ;
if ( V_82 -> V_132 )
V_82 -> V_132 ( V_82 , V_6 ) ;
}
void F_70 ( struct V_82 * V_82 ,
enum V_94 V_133 )
{
F_20 ( & V_1 ) ;
F_69 ( V_82 , V_133 ) ;
F_25 ( & V_1 ) ;
}
static void F_71 ( enum V_94 V_88 )
{
struct V_134 * V_135 ;
struct V_82 * V_82 ;
F_62 (rdev, &cfg80211_rdev_list, list) {
V_82 = & V_135 -> V_82 ;
F_69 ( V_82 , V_88 ) ;
if ( V_88 == V_95 &&
V_82 -> V_65 & V_118 &&
V_82 -> V_132 )
V_82 -> V_132 ( V_82 , V_6 ) ;
}
}
static void F_72 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
unsigned int V_101 ,
const struct V_8 * V_16 )
{
int V_30 ;
T_1 V_84 = F_45 ( 20 ) ;
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
V_30 = F_44 ( V_82 ,
F_45 ( V_98 -> V_83 ) ,
V_84 ,
& V_49 ,
V_16 ) ;
if ( V_30 ) {
F_49 ( L_22
L_23
L_24 ,
V_98 -> V_83 ,
F_50 ( V_84 ) ) ;
V_98 -> V_65 = V_111 ;
return;
}
F_48 ( V_98 , V_84 , V_49 ) ;
V_62 = & V_49 -> V_62 ;
V_44 = & V_49 -> V_44 ;
if ( V_44 -> V_48 < F_45 ( 40 ) )
V_102 = V_112 ;
V_98 -> V_65 |= F_43 ( V_49 -> V_65 ) | V_102 ;
V_98 -> V_64 = ( int ) F_53 ( V_62 -> V_64 ) ;
V_98 -> V_115 = ( int ) F_54 ( V_62 -> V_63 ) ;
}
static void F_73 ( struct V_82 * V_82 , enum V_99 V_100 ,
const struct V_8 * V_16 )
{
unsigned int V_18 ;
struct V_103 * V_104 ;
F_6 ( ! V_82 -> V_107 [ V_100 ] ) ;
V_104 = V_82 -> V_107 [ V_100 ] ;
for ( V_18 = 0 ; V_18 < V_104 -> V_108 ; V_18 ++ )
F_72 ( V_82 , V_100 , V_18 , V_16 ) ;
}
void F_74 ( struct V_82 * V_82 ,
const struct V_8 * V_16 )
{
enum V_99 V_100 ;
unsigned int V_136 = 0 ;
F_20 ( & V_1 ) ;
for ( V_100 = 0 ; V_100 < V_130 ; V_100 ++ ) {
if ( ! V_82 -> V_107 [ V_100 ] )
continue;
F_73 ( V_82 , V_100 , V_16 ) ;
V_136 ++ ;
}
F_25 ( & V_1 ) ;
F_35 ( ! V_136 ) ;
}
static int F_75 ( struct V_82 * V_82 ,
struct V_137 * V_138 )
{
struct V_82 * V_139 = NULL ;
F_14 () ;
if ( ! V_6 )
return 0 ;
switch ( V_138 -> V_88 ) {
case V_95 :
return 0 ;
case V_89 :
V_139 = F_52 ( V_6 -> V_106 ) ;
if ( F_76 ( ! F_11 ( V_138 -> V_10 ) ) )
return - V_66 ;
if ( V_6 -> V_88 ==
V_89 ) {
if ( V_139 != V_82 ) {
if ( F_13 ( V_138 -> V_10 ) )
return - V_140 ;
return - V_141 ;
}
if ( F_35 ( F_13 ( V_138 -> V_10 ) ) )
return 0 ;
return - V_141 ;
}
return 0 ;
case V_96 :
if ( V_6 -> V_88 == V_95 ) {
if ( F_13 ( V_138 -> V_10 ) )
return 0 ;
return - V_141 ;
}
if ( V_6 -> V_88 == V_96 &&
! F_13 ( V_138 -> V_10 ) )
return - V_141 ;
return V_142 ;
case V_90 :
if ( V_6 -> V_88 == V_89 )
return V_142 ;
if ( V_6 -> V_88 == V_90 &&
V_6 -> V_143 )
return - V_140 ;
if ( V_6 -> V_88 == V_95 ||
V_6 -> V_88 == V_96 ||
V_6 -> V_88 == V_90 ) {
if ( F_13 ( V_6 -> V_10 ) )
return - V_144 ;
}
if ( ! F_13 ( V_138 -> V_10 ) )
return - V_141 ;
return 0 ;
}
return - V_66 ;
}
static void F_77 ( void )
{
bool V_145 = false ;
V_6 -> V_146 = true ;
F_78 ( & V_147 ) ;
if ( ! F_21 ( & V_148 ) )
V_145 = true ;
F_79 ( & V_147 ) ;
if ( V_6 -> V_88 == V_90 )
F_80 ( & V_149 ) ;
if ( V_145 )
F_28 ( & V_150 ) ;
}
static int F_81 ( struct V_82 * V_82 ,
struct V_137 * V_138 )
{
bool V_143 = false ;
int V_30 = 0 ;
F_14 () ;
V_30 = F_75 ( V_82 , V_138 ) ;
if ( V_30 == V_142 ) {
if ( V_138 -> V_88 ==
V_96 ) {
V_30 = F_17 ( & V_82 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_138 ) ;
return V_30 ;
}
}
V_143 = true ;
} else if ( V_30 ) {
if ( V_30 == - V_141 &&
V_138 -> V_88 ==
V_96 ) {
V_30 = F_17 ( & V_82 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_138 ) ;
return V_30 ;
}
V_30 = - V_141 ;
goto V_151;
}
F_4 ( V_138 ) ;
return V_30 ;
}
V_151:
if ( V_6 != & V_7 )
F_4 ( V_6 ) ;
V_6 = V_138 ;
V_6 -> V_143 = V_143 ;
V_138 = NULL ;
if ( V_6 -> V_88 == V_90 ) {
V_13 [ 0 ] = V_6 -> V_10 [ 0 ] ;
V_13 [ 1 ] = V_6 -> V_10 [ 1 ] ;
}
if ( V_30 < 0 ) {
if ( V_30 == - V_141 ) {
F_82 ( V_6 ) ;
F_77 () ;
}
return V_30 ;
}
return F_29 ( V_6 -> V_10 ) ;
}
static void F_83 ( struct V_137 * V_152 ,
enum V_94 V_153 )
{
int V_30 = 0 ;
struct V_82 * V_82 = NULL ;
F_6 ( ! V_152 -> V_10 ) ;
if ( F_84 ( V_152 -> V_106 ) )
V_82 = F_52 ( V_152 -> V_106 ) ;
if ( V_153 == V_96 &&
! V_82 ) {
F_4 ( V_152 ) ;
return;
}
V_30 = F_81 ( V_82 , V_152 ) ;
if ( V_30 == - V_141 && V_82 &&
V_82 -> V_65 & V_113 ) {
F_69 ( V_82 , V_153 ) ;
return;
}
if ( V_30 != - V_141 &&
V_153 == V_90 )
F_85 ( & V_149 , F_86 ( 3142 ) ) ;
}
static void F_87 ( void )
{
struct V_137 * V_152 ;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
if ( V_6 && ! V_6 -> V_146 ) {
F_49 ( L_25
L_26 ) ;
goto V_154;
}
F_78 ( & V_147 ) ;
if ( F_21 ( & V_148 ) ) {
F_79 ( & V_147 ) ;
goto V_154;
}
V_152 = F_22 ( & V_148 ,
struct V_137 ,
V_33 ) ;
F_88 ( & V_152 -> V_33 ) ;
F_79 ( & V_147 ) ;
F_83 ( V_152 , V_152 -> V_88 ) ;
V_154:
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
}
static void F_89 ( void )
{
struct V_134 * V_135 ;
struct V_119 * V_155 , * V_156 ;
F_20 ( & V_36 ) ;
F_90 ( & V_157 ) ;
if ( F_21 ( & V_158 ) ) {
F_91 ( & V_157 ) ;
goto V_154;
}
F_92 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_88 ( & V_155 -> V_33 ) ;
F_62 (rdev, &cfg80211_rdev_list, list)
F_60 ( & V_135 -> V_82 , V_155 ) ;
F_27 ( & V_155 -> V_33 , & V_123 ) ;
}
F_91 ( & V_157 ) ;
V_154:
F_25 ( & V_36 ) ;
}
static void F_93 ( struct V_24 * V_25 )
{
F_87 () ;
F_89 () ;
}
static void F_94 ( struct V_137 * V_27 )
{
if ( isalpha ( V_27 -> V_10 [ 0 ] ) )
V_27 -> V_10 [ 0 ] = toupper ( V_27 -> V_10 [ 0 ] ) ;
if ( isalpha ( V_27 -> V_10 [ 1 ] ) )
V_27 -> V_10 [ 1 ] = toupper ( V_27 -> V_10 [ 1 ] ) ;
F_78 ( & V_147 ) ;
F_27 ( & V_27 -> V_33 , & V_148 ) ;
F_79 ( & V_147 ) ;
F_28 ( & V_150 ) ;
}
static int F_95 ( const char * V_10 )
{
struct V_137 * V_27 ;
V_27 = F_18 ( sizeof( struct V_137 ) ,
V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_95 ;
F_94 ( V_27 ) ;
return 0 ;
}
int F_96 ( const char * V_10 )
{
struct V_137 * V_27 ;
F_6 ( ! V_10 ) ;
V_27 = F_18 ( sizeof( struct V_137 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_106 = V_159 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_90 ;
F_94 ( V_27 ) ;
return 0 ;
}
int F_97 ( struct V_82 * V_82 , const char * V_10 )
{
struct V_137 * V_27 ;
F_6 ( ! V_10 ) ;
F_6 ( ! V_82 ) ;
V_27 = F_18 ( sizeof( struct V_137 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_106 = F_98 ( V_82 ) ;
F_6 ( ! F_84 ( V_27 -> V_106 ) ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_96 ;
F_94 ( V_27 ) ;
return 0 ;
}
void F_99 ( struct V_82 * V_82 ,
enum V_99 V_100 ,
T_2 * V_160 ,
T_2 V_161 )
{
char V_10 [ 2 ] ;
enum V_162 V_163 = V_164 ;
struct V_137 * V_27 ;
F_20 ( & V_1 ) ;
if ( F_76 ( ! V_6 ) )
goto V_154;
if ( V_161 & 0x01 )
goto V_154;
if ( V_161 < V_165 )
goto V_154;
V_10 [ 0 ] = V_160 [ 0 ] ;
V_10 [ 1 ] = V_160 [ 1 ] ;
if ( V_160 [ 2 ] == 'I' )
V_163 = V_166 ;
else if ( V_160 [ 2 ] == 'O' )
V_163 = V_167 ;
if ( F_58 ( V_6 -> V_88 ==
V_89 &&
F_84 ( V_6 -> V_106 ) ) )
goto V_154;
V_27 = F_18 ( sizeof( struct V_137 ) , V_21 ) ;
if ( ! V_27 )
goto V_154;
V_27 -> V_106 = F_98 ( V_82 ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_88 = V_89 ;
V_27 -> V_168 = V_163 ;
F_25 ( & V_1 ) ;
F_94 ( V_27 ) ;
return;
V_154:
F_25 ( & V_1 ) ;
}
static void F_100 ( char * V_10 , bool V_169 )
{
V_10 [ 0 ] = '9' ;
V_10 [ 1 ] = '7' ;
if ( F_15 () ) {
if ( V_169 ) {
F_49 ( L_27
L_28 ) ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
if ( ! F_7 ( V_170 ) ) {
F_49 ( L_29
L_30 ,
V_170 [ 0 ] ,
V_170 [ 1 ] ) ;
V_10 [ 0 ] = V_170 [ 0 ] ;
V_10 [ 1 ] = V_170 [ 1 ] ;
}
} else {
F_49 ( L_27
L_31 ,
V_13 [ 0 ] ,
V_13 [ 1 ] ) ;
V_10 [ 0 ] = V_13 [ 0 ] ;
V_10 [ 1 ] = V_13 [ 1 ] ;
}
} else if ( ! F_7 ( V_170 ) ) {
F_49 ( L_29
L_30 ,
V_170 [ 0 ] ,
V_170 [ 1 ] ) ;
V_10 [ 0 ] = V_170 [ 0 ] ;
V_10 [ 1 ] = V_170 [ 1 ] ;
} else
F_49 ( L_32 ) ;
}
static void F_101 ( struct V_82 * V_82 )
{
struct V_103 * V_104 ;
enum V_99 V_100 ;
struct V_97 * V_98 ;
int V_18 ;
for ( V_100 = 0 ; V_100 < V_130 ; V_100 ++ ) {
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
static void F_102 ( bool V_169 )
{
char V_10 [ 2 ] ;
char V_171 [ 2 ] ;
struct V_119 * V_119 , * V_172 ;
struct V_137 * V_152 , * V_156 ;
F_103 ( V_173 ) ;
struct V_134 * V_135 ;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_100 ( V_10 , V_169 ) ;
F_78 ( & V_147 ) ;
if ( ! F_21 ( & V_148 ) ) {
F_92 (reg_request, tmp,
&reg_requests_list, list) {
if ( V_152 -> V_88 !=
V_90 )
continue;
F_23 ( & V_152 -> V_33 ) ;
F_27 ( & V_152 -> V_33 , & V_173 ) ;
}
}
F_79 ( & V_147 ) ;
F_90 ( & V_157 ) ;
if ( ! F_21 ( & V_158 ) ) {
F_92 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_119 -> V_33 ) ;
F_4 ( V_119 ) ;
}
}
F_91 ( & V_157 ) ;
if ( ! F_21 ( & V_123 ) ) {
F_92 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_119 -> V_33 ) ;
F_4 ( V_119 ) ;
}
}
V_3 = V_4 ;
V_171 [ 0 ] = V_3 -> V_10 [ 0 ] ;
V_171 [ 1 ] = V_3 -> V_10 [ 1 ] ;
F_62 (rdev, &cfg80211_rdev_list, list) {
if ( V_135 -> V_82 . V_65 & V_118 )
F_101 ( & V_135 -> V_82 ) ;
}
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
F_95 ( V_171 ) ;
if ( F_11 ( V_10 ) )
F_96 ( V_13 ) ;
if ( F_21 ( & V_173 ) )
return;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
F_78 ( & V_147 ) ;
F_92 (reg_request, tmp, &tmp_reg_req_list, list) {
F_49 ( L_33
L_34 ,
V_152 -> V_10 [ 0 ] ,
V_152 -> V_10 [ 1 ] ) ;
F_23 ( & V_152 -> V_33 ) ;
F_27 ( & V_152 -> V_33 , & V_148 ) ;
}
F_79 ( & V_147 ) ;
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
F_49 ( L_35 ) ;
F_28 ( & V_150 ) ;
}
void F_104 ( void )
{
F_49 ( L_36
L_37 ) ;
F_102 ( false ) ;
}
static bool F_105 ( T_3 V_174 )
{
if ( V_174 == F_106 ( 12 , V_175 ) ||
V_174 == F_106 ( 13 , V_175 ) ||
V_174 == F_106 ( 14 , V_175 ) )
return true ;
return false ;
}
int F_107 ( struct V_82 * V_82 ,
struct V_97 * V_176 ,
T_4 V_177 )
{
struct V_119 * V_119 ;
if ( F_58 ( ( V_176 -> V_117 ||
( V_176 -> V_65 & V_81 ) ||
( V_176 -> V_100 == V_175 &&
! F_105 ( V_176 -> V_83 ) ) ) ) )
return 0 ;
V_119 = F_18 ( sizeof( struct V_119 ) , V_177 ) ;
if ( ! V_119 )
return - V_22 ;
F_49 ( L_38
L_39 ,
V_176 -> V_83 ,
F_108 ( V_176 -> V_83 ) ,
F_109 ( V_82 ) ) ;
memcpy ( & V_119 -> V_98 , V_176 ,
sizeof( struct V_97 ) ) ;
F_90 ( & V_157 ) ;
F_27 ( & V_119 -> V_33 , & V_158 ) ;
F_91 ( & V_157 ) ;
F_28 ( & V_150 ) ;
return 0 ;
}
static void F_110 ( const struct V_8 * V_9 )
{
unsigned int V_18 ;
const struct V_20 * V_49 = NULL ;
const struct V_43 * V_44 = NULL ;
const struct V_59 * V_62 = NULL ;
F_30 ( L_40 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_49 = & V_9 -> V_23 [ V_18 ] ;
V_44 = & V_49 -> V_44 ;
V_62 = & V_49 -> V_62 ;
if ( V_62 -> V_64 )
F_30 ( L_41 ,
V_44 -> V_46 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_62 -> V_64 ,
V_62 -> V_63 ) ;
else
F_30 ( L_42 ,
V_44 -> V_46 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_62 -> V_63 ) ;
}
}
bool F_111 ( T_2 V_131 )
{
switch ( V_131 ) {
case V_178 :
case V_179 :
case V_180 :
case V_181 :
return true ;
default:
F_49 ( L_43 ,
V_131 ) ;
return false ;
}
}
static void F_112 ( T_2 V_131 )
{
if ( ! V_131 )
return;
switch ( V_131 ) {
case V_179 :
F_30 ( L_44 ) ;
break;
case V_180 :
F_30 ( L_45 ) ;
break;
case V_181 :
F_30 ( L_46 ) ;
break;
default:
F_30 ( L_47 ) ;
break;
}
}
static void F_113 ( const struct V_8 * V_9 )
{
if ( F_10 ( V_9 -> V_10 ) ) {
if ( V_6 -> V_88 ==
V_89 ) {
struct V_134 * V_135 ;
V_135 = F_114 (
V_6 -> V_106 ) ;
if ( V_135 ) {
F_30 ( L_48 ,
V_135 -> V_182 [ 0 ] ,
V_135 -> V_182 [ 1 ] ) ;
} else
F_30 ( L_49 ) ;
} else
F_30 ( L_49 ) ;
} else if ( F_7 ( V_9 -> V_10 ) )
F_30 ( L_50 ) ;
else {
if ( F_9 ( V_9 -> V_10 ) )
F_30 ( L_51 ) ;
else
F_30 ( L_52 ,
V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
}
F_112 ( V_9 -> V_131 ) ;
F_110 ( V_9 ) ;
}
static void F_115 ( const struct V_8 * V_9 )
{
F_30 ( L_53 , V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
F_110 ( V_9 ) ;
}
static int F_116 ( const struct V_8 * V_9 )
{
const struct V_8 * V_183 = NULL ;
struct V_134 * V_135 = NULL ;
struct V_82 * V_105 ;
if ( F_7 ( V_9 -> V_10 ) ) {
if ( F_35 ( ! F_32 ( V_9 -> V_10 ) ) )
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
if ( F_35 ( ! F_32 ( V_9 -> V_10 ) ) )
return - V_66 ;
if ( ! F_34 ( V_9 ) ) {
F_117 ( L_54 ) ;
F_115 ( V_9 ) ;
return - V_66 ;
}
V_105 = F_52 ( V_6 -> V_106 ) ;
if ( ! V_105 &&
( V_6 -> V_88 == V_96 ||
V_6 -> V_88 == V_89 ) ) {
F_85 ( & V_149 , 0 ) ;
return - V_184 ;
}
if ( ! V_6 -> V_143 ) {
int V_30 ;
if ( V_6 -> V_88 != V_96 ) {
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_105 -> V_16 )
return - V_141 ;
V_30 = F_17 ( & V_105 -> V_16 , V_9 ) ;
if ( V_30 )
return V_30 ;
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_6 -> V_88 != V_89 ) {
V_183 = F_42 ( V_9 , V_3 ) ;
if ( ! V_183 )
return - V_66 ;
if ( V_6 -> V_88 == V_96 )
V_105 -> V_16 = V_9 ;
else
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_183 ;
return 0 ;
}
if ( ! V_183 )
return - V_66 ;
V_135 = F_118 ( V_105 ) ;
V_135 -> V_182 [ 0 ] = V_9 -> V_10 [ 0 ] ;
V_135 -> V_182 [ 1 ] = V_9 -> V_10 [ 1 ] ;
V_135 -> V_163 = V_6 -> V_168 ;
F_6 ( V_183 == V_9 ) ;
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_183 ;
return 0 ;
}
int F_24 ( const struct V_8 * V_9 )
{
int V_30 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_30 = F_116 ( V_9 ) ;
if ( V_30 ) {
F_4 ( V_9 ) ;
F_25 ( & V_1 ) ;
return V_30 ;
}
if ( ! V_6 -> V_143 )
F_6 ( V_9 != V_3 ) ;
F_71 ( V_6 -> V_88 ) ;
F_113 ( V_3 ) ;
F_82 ( V_6 ) ;
F_77 () ;
F_25 ( & V_1 ) ;
return V_30 ;
}
int F_119 ( struct V_185 * V_39 , struct V_186 * V_163 )
{
if ( V_6 && ! V_6 -> V_146 ) {
if ( F_120 ( V_163 , L_55 ,
V_6 -> V_10 [ 0 ] ,
V_6 -> V_10 [ 1 ] ) )
return - V_22 ;
}
return 0 ;
}
int F_119 ( struct V_185 * V_39 , struct V_186 * V_163 )
{
return - V_184 ;
}
void F_121 ( struct V_82 * V_82 )
{
struct V_82 * V_105 = NULL ;
F_14 () ;
F_20 ( & V_1 ) ;
F_4 ( V_82 -> V_16 ) ;
if ( V_6 )
V_105 = F_52 ( V_6 -> V_106 ) ;
if ( ! V_105 || V_105 != V_82 )
goto V_154;
V_6 -> V_106 = V_159 ;
V_6 -> V_168 = V_164 ;
V_154:
F_25 ( & V_1 ) ;
}
static void F_122 ( struct V_24 * V_25 )
{
F_49 ( L_56
L_57 ) ;
F_102 ( true ) ;
}
int T_5 F_123 ( void )
{
int V_187 = 0 ;
V_38 = F_124 ( L_58 , 0 , NULL , 0 ) ;
if ( F_125 ( V_38 ) )
return F_126 ( V_38 ) ;
V_38 -> V_39 . type = & V_188 ;
F_127 ( & V_147 ) ;
F_127 ( & V_157 ) ;
V_3 = V_4 ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
V_187 = F_95 ( V_3 -> V_10 ) ;
if ( V_187 ) {
if ( V_187 == - V_22 )
return V_187 ;
F_117 ( L_59 ) ;
#ifdef F_128
F_35 ( V_187 ) ;
#endif
}
if ( ! F_7 ( V_170 ) )
F_96 ( V_170 ) ;
return 0 ;
}
void F_129 ( void )
{
struct V_137 * V_152 , * V_156 ;
struct V_119 * V_119 , * V_172 ;
F_130 ( & V_150 ) ;
F_80 ( & V_149 ) ;
F_20 ( & V_36 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_131 ( & V_38 -> V_39 , true ) ;
F_132 ( V_38 ) ;
F_90 ( & V_157 ) ;
if ( ! F_21 ( & V_158 ) ) {
F_92 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_119 -> V_33 ) ;
F_4 ( V_119 ) ;
}
}
F_91 ( & V_157 ) ;
if ( ! F_21 ( & V_123 ) ) {
F_92 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_119 -> V_33 ) ;
F_4 ( V_119 ) ;
}
}
F_78 ( & V_147 ) ;
if ( ! F_21 ( & V_148 ) ) {
F_92 (reg_request, tmp,
&reg_requests_list, list) {
F_23 ( & V_152 -> V_33 ) ;
F_4 ( V_152 ) ;
}
}
F_79 ( & V_147 ) ;
F_25 ( & V_1 ) ;
F_25 ( & V_36 ) ;
}
