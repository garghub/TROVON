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
if ( abs ( V_54 - V_45 -> V_47 ) <= ( 2 * F_40 ) )
return true ;
if ( abs ( V_54 - V_45 -> V_48 ) <= ( 2 * F_40 ) )
return true ;
return false ;
#undef F_40
}
static int F_41 (
const struct V_20 * V_55 ,
const struct V_20 * V_56 ,
struct V_20 * V_57 )
{
const struct V_44 * V_58 , * V_59 ;
struct V_44 * V_45 ;
const struct V_60 * V_61 , * V_62 ;
struct V_60 * V_63 ;
T_1 V_46 ;
V_58 = & V_55 -> V_45 ;
V_59 = & V_56 -> V_45 ;
V_45 = & V_57 -> V_45 ;
V_61 = & V_55 -> V_63 ;
V_62 = & V_56 -> V_63 ;
V_63 = & V_57 -> V_63 ;
V_45 -> V_47 = F_42 ( V_58 -> V_47 ,
V_59 -> V_47 ) ;
V_45 -> V_48 = F_43 ( V_58 -> V_48 ,
V_59 -> V_48 ) ;
V_45 -> V_49 = F_43 ( V_58 -> V_49 ,
V_59 -> V_49 ) ;
V_46 = V_45 -> V_48 - V_45 -> V_47 ;
if ( V_45 -> V_49 > V_46 )
V_45 -> V_49 = V_46 ;
V_63 -> V_64 = F_43 ( V_61 -> V_64 ,
V_62 -> V_64 ) ;
V_63 -> V_65 = F_43 ( V_61 -> V_65 ,
V_62 -> V_65 ) ;
V_57 -> V_66 = ( V_55 -> V_66 | V_56 -> V_66 ) ;
if ( ! F_35 ( V_57 ) )
return - V_67 ;
return 0 ;
}
static struct V_8 * F_44 (
const struct V_8 * V_68 ,
const struct V_8 * V_69 )
{
int V_30 , V_17 ;
unsigned int V_70 , V_71 ;
unsigned int V_72 = 0 , V_73 = 0 ;
const struct V_20 * V_55 , * V_56 ;
struct V_20 * V_57 ;
struct V_8 * V_9 ;
struct V_20 V_74 ;
V_57 = & V_74 ;
memset ( V_57 , 0 , sizeof( struct V_20 ) ) ;
if ( ! V_68 || ! V_69 )
return NULL ;
for ( V_70 = 0 ; V_70 < V_68 -> V_19 ; V_70 ++ ) {
V_55 = & V_68 -> V_23 [ V_70 ] ;
for ( V_71 = 0 ; V_71 < V_69 -> V_19 ; V_71 ++ ) {
V_56 = & V_69 -> V_23 [ V_71 ] ;
if ( ! F_41 ( V_55 , V_56 ,
V_57 ) )
V_72 ++ ;
memset ( V_57 , 0 ,
sizeof( struct V_20 ) ) ;
}
}
if ( ! V_72 )
return NULL ;
V_17 = sizeof( struct V_8 ) +
( ( V_72 + 1 ) * sizeof( struct V_20 ) ) ;
V_9 = F_18 ( V_17 , V_21 ) ;
if ( ! V_9 )
return NULL ;
for ( V_70 = 0 ; V_70 < V_68 -> V_19 ; V_70 ++ ) {
V_55 = & V_68 -> V_23 [ V_70 ] ;
for ( V_71 = 0 ; V_71 < V_69 -> V_19 ; V_71 ++ ) {
V_56 = & V_69 -> V_23 [ V_71 ] ;
V_57 = & V_9 -> V_23 [ V_73 ] ;
V_30 = F_41 ( V_55 , V_56 ,
V_57 ) ;
if ( V_30 )
continue;
V_73 ++ ;
}
}
if ( V_73 != V_72 ) {
F_4 ( V_9 ) ;
return NULL ;
}
V_9 -> V_19 = V_72 ;
V_9 -> V_10 [ 0 ] = '9' ;
V_9 -> V_10 [ 1 ] = '8' ;
return V_9 ;
}
static T_1 F_45 ( T_1 V_75 )
{
T_1 V_76 = 0 ;
if ( V_75 & V_77 )
V_76 |= V_78 ;
if ( V_75 & V_79 )
V_76 |= V_80 ;
if ( V_75 & V_81 )
V_76 |= V_82 ;
if ( V_75 & V_83 )
V_76 |= V_84 ;
return V_76 ;
}
static int F_46 ( struct V_85 * V_85 ,
T_1 V_86 ,
T_1 V_87 ,
const struct V_20 * * V_50 ,
const struct V_8 * V_88 )
{
int V_18 ;
bool V_89 = false ;
const struct V_8 * V_16 ;
bool V_90 = false ;
if ( ! V_87 )
V_87 = F_47 ( 20 ) ;
V_16 = V_88 ? V_88 : V_3 ;
if ( ! V_88 &&
V_6 -> V_91 != V_92 &&
V_6 -> V_91 != V_93 &&
V_85 -> V_16 )
V_16 = V_85 -> V_16 ;
if ( ! V_16 )
return - V_67 ;
for ( V_18 = 0 ; V_18 < V_16 -> V_19 ; V_18 ++ ) {
const struct V_20 * V_94 ;
const struct V_44 * V_95 = NULL ;
V_94 = & V_16 -> V_23 [ V_18 ] ;
V_95 = & V_94 -> V_45 ;
if ( ! V_89 )
V_89 = F_39 ( V_95 , V_86 ) ;
V_90 = F_38 ( V_95 ,
V_86 ,
V_87 ) ;
if ( V_89 && V_90 ) {
* V_50 = V_94 ;
return 0 ;
}
}
if ( ! V_89 )
return - V_96 ;
return - V_67 ;
}
int F_48 ( struct V_85 * V_85 ,
T_1 V_86 ,
T_1 V_87 ,
const struct V_20 * * V_50 )
{
F_14 () ;
return F_46 ( V_85 ,
V_86 ,
V_87 ,
V_50 ,
NULL ) ;
}
static const char * F_49 ( enum V_97 V_91 )
{
switch ( V_91 ) {
case V_98 :
return L_5 ;
case V_93 :
return L_6 ;
case V_99 :
return L_7 ;
case V_92 :
return L_8 ;
default:
F_37 ( 1 ) ;
return L_9 ;
}
}
static void F_50 ( struct V_100 * V_101 ,
T_1 V_87 ,
const struct V_20 * V_50 )
{
const struct V_60 * V_63 ;
const struct V_44 * V_45 ;
char V_65 [ 32 ] ;
V_63 = & V_50 -> V_63 ;
V_45 = & V_50 -> V_45 ;
if ( ! V_63 -> V_65 )
snprintf ( V_65 , 32 , L_10 ) ;
else
snprintf ( V_65 , 32 , L_11 , V_63 -> V_65 ) ;
F_51 ( L_12
L_13 ,
V_101 -> V_86 ,
F_52 ( V_87 ) ) ;
F_51 ( L_14 ,
V_45 -> V_47 ,
V_45 -> V_48 ,
V_45 -> V_49 ,
V_65 ,
V_63 -> V_64 ) ;
}
static void F_50 ( struct V_100 * V_101 ,
T_1 V_87 ,
const struct V_20 * V_50 )
{
return;
}
static void F_53 ( struct V_85 * V_85 ,
enum V_97 V_91 ,
enum V_102 V_103 ,
unsigned int V_104 )
{
int V_30 ;
T_1 V_66 , V_105 = 0 ;
T_1 V_87 = F_47 ( 20 ) ;
const struct V_20 * V_50 = NULL ;
const struct V_60 * V_63 = NULL ;
const struct V_44 * V_45 = NULL ;
struct V_106 * V_107 ;
struct V_100 * V_101 ;
struct V_85 * V_108 = NULL ;
F_14 () ;
V_108 = F_54 ( V_6 -> V_109 ) ;
V_107 = V_85 -> V_110 [ V_103 ] ;
F_6 ( V_104 >= V_107 -> V_111 ) ;
V_101 = & V_107 -> V_112 [ V_104 ] ;
V_66 = V_101 -> V_113 ;
V_30 = F_48 ( V_85 ,
F_47 ( V_101 -> V_86 ) ,
V_87 ,
& V_50 ) ;
if ( V_30 ) {
if ( V_91 == V_92 &&
V_30 == - V_96 )
return;
F_51 ( L_15 , V_101 -> V_86 ) ;
V_101 -> V_66 = V_114 ;
return;
}
F_50 ( V_101 , V_87 , V_50 ) ;
V_63 = & V_50 -> V_63 ;
V_45 = & V_50 -> V_45 ;
if ( V_45 -> V_49 < F_47 ( 40 ) )
V_105 = V_115 ;
if ( V_6 -> V_91 == V_99 &&
V_108 && V_108 == V_85 &&
V_108 -> V_66 & V_116 ) {
V_101 -> V_66 = V_101 -> V_113 =
F_45 ( V_50 -> V_66 ) | V_105 ;
V_101 -> V_65 = V_101 -> V_117 =
( int ) F_55 ( V_63 -> V_65 ) ;
V_101 -> V_118 = V_101 -> V_119 =
( int ) F_56 ( V_63 -> V_64 ) ;
return;
}
V_101 -> V_120 = false ;
V_101 -> V_66 = V_66 | V_105 | F_45 ( V_50 -> V_66 ) ;
V_101 -> V_65 = F_43 ( V_101 -> V_117 ,
( int ) F_55 ( V_63 -> V_65 ) ) ;
V_101 -> V_121 = ( int ) F_56 ( V_63 -> V_64 ) ;
if ( V_101 -> V_119 ) {
if ( V_91 == V_92 &&
V_85 -> V_66 & V_122 &&
V_85 -> V_66 & V_116 )
V_101 -> V_118 = V_101 -> V_121 ;
else
V_101 -> V_118 = F_43 ( V_101 -> V_119 ,
V_101 -> V_121 ) ;
} else
V_101 -> V_118 = V_101 -> V_121 ;
}
static void F_57 ( struct V_85 * V_85 ,
enum V_102 V_103 ,
enum V_97 V_91 )
{
unsigned int V_18 ;
struct V_106 * V_107 ;
F_6 ( ! V_85 -> V_110 [ V_103 ] ) ;
V_107 = V_85 -> V_110 [ V_103 ] ;
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ )
F_53 ( V_85 , V_91 , V_103 , V_18 ) ;
}
static bool F_58 ( struct V_123 * V_27 )
{
if ( V_27 -> V_91 != V_93 )
return false ;
if ( V_27 -> V_124 != V_125 )
return false ;
return true ;
}
bool F_59 ( void )
{
bool V_126 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_126 = F_58 ( V_6 ) ;
F_24 ( & V_1 ) ;
return V_126 ;
}
static int F_60 ( struct V_123 * V_127 )
{
if ( ! V_128 )
return - V_129 ;
if ( F_58 ( V_6 ) ) {
if ( ! F_13 ( V_127 -> V_10 ) )
return - V_130 ;
return 0 ;
}
return 0 ;
}
static bool F_61 ( struct V_85 * V_85 )
{
if ( ! ( V_85 -> V_131 & V_132 ) )
return true ;
return false ;
}
static int F_60 ( struct V_123 * V_127 )
{
return - V_129 ;
}
static int F_61 ( struct V_85 * V_85 )
{
return true ;
}
static bool F_62 ( struct V_85 * V_85 ,
enum V_97 V_91 )
{
if ( ! V_6 ) {
F_51 ( L_16
L_17 ,
F_49 ( V_91 ) ) ;
return true ;
}
if ( V_91 == V_98 &&
V_85 -> V_66 & V_122 ) {
F_51 ( L_18
L_19
L_20 ,
F_49 ( V_91 ) ) ;
return true ;
}
if ( V_85 -> V_66 & V_116 && ! V_85 -> V_16 &&
V_91 != V_92 &&
! F_7 ( V_6 -> V_10 ) ) {
F_51 ( L_18
L_21
L_22 ,
F_49 ( V_91 ) ) ;
return true ;
}
if ( F_58 ( V_6 ) )
return F_61 ( V_85 ) ;
return false ;
}
static void F_63 ( struct V_85 * V_85 ,
unsigned int V_104 ,
struct V_133 * V_133 )
{
struct V_106 * V_107 ;
struct V_100 * V_101 ;
bool V_134 = false ;
struct V_100 V_135 ;
F_14 () ;
V_107 = V_85 -> V_110 [ V_133 -> V_101 . V_103 ] ;
V_101 = & V_107 -> V_112 [ V_104 ] ;
if ( F_64 ( V_101 -> V_86 != V_133 -> V_101 . V_86 ) )
return;
if ( V_101 -> V_120 )
return;
V_101 -> V_120 = true ;
if ( V_85 -> V_66 & V_136 )
return;
V_135 . V_86 = V_101 -> V_86 ;
V_135 . V_66 = V_101 -> V_66 ;
if ( V_101 -> V_66 & V_78 ) {
V_101 -> V_66 &= ~ V_78 ;
V_134 = true ;
}
if ( V_101 -> V_66 & V_80 ) {
V_101 -> V_66 &= ~ V_80 ;
V_134 = true ;
}
if ( V_134 )
F_65 ( V_85 , & V_135 , V_101 ) ;
}
static void F_66 ( struct V_85 * V_85 ,
struct V_133 * V_133 )
{
unsigned int V_18 ;
struct V_106 * V_107 ;
F_14 () ;
if ( ! V_85 -> V_110 [ V_133 -> V_101 . V_103 ] )
return;
V_107 = V_85 -> V_110 [ V_133 -> V_101 . V_103 ] ;
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ )
F_63 ( V_85 , V_18 , V_133 ) ;
}
static void F_67 ( struct V_85 * V_85 )
{
unsigned int V_18 ;
struct V_106 * V_107 ;
struct V_133 * V_133 ;
F_14 () ;
if ( F_21 ( & V_137 ) )
return;
F_68 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_85 -> V_110 [ V_133 -> V_101 . V_103 ] )
continue;
V_107 = V_85 -> V_110 [ V_133 -> V_101 . V_103 ] ;
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ )
F_63 ( V_85 , V_18 , V_133 ) ;
}
}
static bool F_69 ( struct V_85 * V_85 )
{
if ( F_7 ( V_3 -> V_10 ) ||
( V_85 -> V_16 && F_7 ( V_85 -> V_16 -> V_10 ) ) )
return true ;
if ( V_6 &&
V_6 -> V_91 != V_92 &&
V_85 -> V_66 & V_122 )
return true ;
return false ;
}
static void F_70 ( struct V_85 * V_85 )
{
if ( ! V_6 )
return;
if ( ! F_69 ( V_85 ) )
return;
F_67 ( V_85 ) ;
}
static bool F_71 ( struct V_100 * V_101 )
{
if ( ! V_101 )
return true ;
if ( V_101 -> V_66 & V_114 )
return true ;
if ( V_115 == ( V_101 -> V_66 & ( V_115 ) ) )
return true ;
return false ;
}
static void F_72 ( struct V_85 * V_85 ,
enum V_102 V_103 ,
unsigned int V_104 )
{
struct V_106 * V_107 ;
struct V_100 * V_138 ;
struct V_100 * V_139 = NULL , * V_140 = NULL ;
unsigned int V_18 ;
F_14 () ;
V_107 = V_85 -> V_110 [ V_103 ] ;
F_6 ( V_104 >= V_107 -> V_111 ) ;
V_138 = & V_107 -> V_112 [ V_104 ] ;
if ( F_71 ( V_138 ) ) {
V_138 -> V_66 |= V_115 ;
return;
}
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ ) {
struct V_100 * V_141 = & V_107 -> V_112 [ V_18 ] ;
if ( V_141 -> V_86 == ( V_138 -> V_86 - 20 ) )
V_139 = V_141 ;
if ( V_141 -> V_86 == ( V_138 -> V_86 + 20 ) )
V_140 = V_141 ;
}
if ( F_71 ( V_139 ) )
V_138 -> V_66 |= V_142 ;
else
V_138 -> V_66 &= ~ V_142 ;
if ( F_71 ( V_140 ) )
V_138 -> V_66 |= V_143 ;
else
V_138 -> V_66 &= ~ V_143 ;
}
static void F_73 ( struct V_85 * V_85 ,
enum V_102 V_103 )
{
unsigned int V_18 ;
struct V_106 * V_107 ;
F_6 ( ! V_85 -> V_110 [ V_103 ] ) ;
V_107 = V_85 -> V_110 [ V_103 ] ;
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ )
F_72 ( V_85 , V_103 , V_18 ) ;
}
static void F_74 ( struct V_85 * V_85 )
{
enum V_102 V_103 ;
if ( ! V_85 )
return;
for ( V_103 = 0 ; V_103 < V_144 ; V_103 ++ ) {
if ( V_85 -> V_110 [ V_103 ] )
F_73 ( V_85 , V_103 ) ;
}
}
static void F_75 ( struct V_85 * V_85 ,
enum V_97 V_91 )
{
enum V_102 V_103 ;
F_1 () ;
if ( F_62 ( V_85 , V_91 ) )
return;
V_6 -> V_145 = V_3 -> V_145 ;
for ( V_103 = 0 ; V_103 < V_144 ; V_103 ++ ) {
if ( V_85 -> V_110 [ V_103 ] )
F_57 ( V_85 , V_103 , V_91 ) ;
}
F_70 ( V_85 ) ;
F_74 ( V_85 ) ;
if ( V_85 -> V_146 )
V_85 -> V_146 ( V_85 , V_6 ) ;
}
static void F_76 ( enum V_97 V_91 )
{
struct V_147 * V_148 ;
struct V_85 * V_85 ;
F_68 (rdev, &cfg80211_rdev_list, list) {
V_85 = & V_148 -> V_85 ;
F_75 ( V_85 , V_91 ) ;
if ( V_91 == V_98 &&
V_85 -> V_66 & V_122 &&
V_85 -> V_146 )
V_85 -> V_146 ( V_85 , V_6 ) ;
}
}
static void F_77 ( struct V_85 * V_85 ,
enum V_102 V_103 ,
unsigned int V_104 ,
const struct V_8 * V_16 )
{
int V_30 ;
T_1 V_87 = F_47 ( 20 ) ;
T_1 V_105 = 0 ;
const struct V_20 * V_50 = NULL ;
const struct V_60 * V_63 = NULL ;
const struct V_44 * V_45 = NULL ;
struct V_106 * V_107 ;
struct V_100 * V_101 ;
F_1 () ;
V_107 = V_85 -> V_110 [ V_103 ] ;
F_6 ( V_104 >= V_107 -> V_111 ) ;
V_101 = & V_107 -> V_112 [ V_104 ] ;
V_30 = F_46 ( V_85 ,
F_47 ( V_101 -> V_86 ) ,
V_87 ,
& V_50 ,
V_16 ) ;
if ( V_30 ) {
F_51 ( L_23
L_24
L_25 ,
V_101 -> V_86 ,
F_52 ( V_87 ) ) ;
V_101 -> V_66 = V_114 ;
return;
}
F_50 ( V_101 , V_87 , V_50 ) ;
V_63 = & V_50 -> V_63 ;
V_45 = & V_50 -> V_45 ;
if ( V_45 -> V_49 < F_47 ( 40 ) )
V_105 = V_115 ;
V_101 -> V_66 |= F_45 ( V_50 -> V_66 ) | V_105 ;
V_101 -> V_65 = ( int ) F_55 ( V_63 -> V_65 ) ;
V_101 -> V_118 = ( int ) F_56 ( V_63 -> V_64 ) ;
}
static void F_78 ( struct V_85 * V_85 , enum V_102 V_103 ,
const struct V_8 * V_16 )
{
unsigned int V_18 ;
struct V_106 * V_107 ;
F_6 ( ! V_85 -> V_110 [ V_103 ] ) ;
V_107 = V_85 -> V_110 [ V_103 ] ;
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ )
F_77 ( V_85 , V_103 , V_18 , V_16 ) ;
}
void F_79 ( struct V_85 * V_85 ,
const struct V_8 * V_16 )
{
enum V_102 V_103 ;
unsigned int V_149 = 0 ;
F_20 ( & V_1 ) ;
for ( V_103 = 0 ; V_103 < V_144 ; V_103 ++ ) {
if ( ! V_85 -> V_110 [ V_103 ] )
continue;
F_78 ( V_85 , V_103 , V_16 ) ;
V_149 ++ ;
}
F_24 ( & V_1 ) ;
F_37 ( ! V_149 ) ;
}
static int F_80 ( struct V_85 * V_85 ,
struct V_123 * V_127 )
{
struct V_85 * V_150 = NULL ;
F_14 () ;
if ( ! V_6 )
return 0 ;
switch ( V_127 -> V_91 ) {
case V_98 :
return 0 ;
case V_92 :
if ( F_58 ( V_6 ) ) {
if ( F_13 ( V_127 -> V_10 ) )
return - V_129 ;
return - V_130 ;
}
V_150 = F_54 ( V_6 -> V_109 ) ;
if ( F_81 ( ! F_11 ( V_127 -> V_10 ) ) )
return - V_67 ;
if ( V_6 -> V_91 ==
V_92 ) {
if ( V_150 != V_85 ) {
if ( F_13 ( V_127 -> V_10 ) )
return - V_129 ;
return - V_130 ;
}
if ( F_37 ( F_13 ( V_127 -> V_10 ) ) )
return 0 ;
return - V_130 ;
}
return 0 ;
case V_99 :
if ( V_6 -> V_91 == V_98 ) {
if ( F_13 ( V_127 -> V_10 ) )
return 0 ;
return - V_130 ;
}
if ( V_6 -> V_91 == V_99 &&
! F_13 ( V_127 -> V_10 ) )
return - V_130 ;
return V_151 ;
case V_93 :
if ( F_58 ( V_127 ) )
return F_60 ( V_127 ) ;
if ( F_58 ( V_6 ) )
return - V_129 ;
if ( V_6 -> V_91 == V_92 )
return V_151 ;
if ( V_6 -> V_91 == V_93 &&
V_6 -> V_152 )
return - V_129 ;
if ( V_6 -> V_91 == V_98 ||
V_6 -> V_91 == V_99 ||
V_6 -> V_91 == V_93 ) {
if ( F_13 ( V_6 -> V_10 ) )
return - V_153 ;
}
if ( ! F_13 ( V_127 -> V_10 ) )
return - V_130 ;
return 0 ;
}
return - V_67 ;
}
static void F_82 ( void )
{
bool V_154 = false ;
V_6 -> V_155 = true ;
F_83 ( & V_156 ) ;
if ( ! F_21 ( & V_157 ) )
V_154 = true ;
F_84 ( & V_156 ) ;
if ( V_6 -> V_91 == V_93 )
F_85 ( & V_158 ) ;
if ( V_154 )
F_28 ( & V_159 ) ;
}
static int F_86 ( struct V_85 * V_85 ,
struct V_123 * V_127 )
{
bool V_152 = false ;
int V_30 = 0 ;
F_14 () ;
V_30 = F_80 ( V_85 , V_127 ) ;
if ( V_30 == V_151 ) {
if ( V_127 -> V_91 ==
V_99 ) {
V_30 = F_17 ( & V_85 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_127 ) ;
return V_30 ;
}
}
V_152 = true ;
} else if ( V_30 ) {
if ( V_30 == - V_130 &&
V_127 -> V_91 ==
V_99 ) {
V_30 = F_17 ( & V_85 -> V_16 , V_3 ) ;
if ( V_30 ) {
F_4 ( V_127 ) ;
return V_30 ;
}
V_30 = - V_130 ;
goto V_160;
}
F_4 ( V_127 ) ;
return V_30 ;
}
V_160:
if ( V_6 != & V_7 )
F_4 ( V_6 ) ;
V_6 = V_127 ;
V_6 -> V_152 = V_152 ;
V_127 = NULL ;
if ( V_6 -> V_91 == V_93 ) {
V_13 [ 0 ] = V_6 -> V_10 [ 0 ] ;
V_13 [ 1 ] = V_6 -> V_10 [ 1 ] ;
}
if ( V_30 < 0 ) {
if ( V_30 == - V_130 ) {
F_87 ( V_6 ) ;
F_82 () ;
}
return V_30 ;
}
return F_31 ( V_6 -> V_10 ) ;
}
static void F_88 ( struct V_123 * V_161 ,
enum V_97 V_162 )
{
int V_30 = 0 ;
struct V_85 * V_85 = NULL ;
F_6 ( ! V_161 -> V_10 ) ;
if ( F_89 ( V_161 -> V_109 ) )
V_85 = F_54 ( V_161 -> V_109 ) ;
if ( V_162 == V_99 &&
! V_85 ) {
F_4 ( V_161 ) ;
return;
}
V_30 = F_86 ( V_85 , V_161 ) ;
if ( V_30 == - V_130 && V_85 &&
V_85 -> V_66 & V_116 ) {
F_75 ( V_85 , V_162 ) ;
return;
}
if ( V_30 != - V_130 &&
V_162 == V_93 )
F_90 ( & V_158 , F_91 ( 3142 ) ) ;
}
static void F_92 ( void )
{
struct V_123 * V_161 ;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
if ( V_6 && ! V_6 -> V_155 ) {
F_51 ( L_26
L_27 ) ;
goto V_163;
}
F_83 ( & V_156 ) ;
if ( F_21 ( & V_157 ) ) {
F_84 ( & V_156 ) ;
goto V_163;
}
V_161 = F_22 ( & V_157 ,
struct V_123 ,
V_35 ) ;
F_93 ( & V_161 -> V_35 ) ;
F_84 ( & V_156 ) ;
F_88 ( V_161 , V_161 -> V_91 ) ;
V_163:
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
}
static void F_94 ( void )
{
struct V_147 * V_148 ;
struct V_133 * V_164 , * V_165 ;
F_20 ( & V_32 ) ;
F_95 ( & V_166 ) ;
if ( F_21 ( & V_167 ) ) {
F_96 ( & V_166 ) ;
goto V_163;
}
F_97 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_93 ( & V_164 -> V_35 ) ;
F_68 (rdev, &cfg80211_rdev_list, list)
F_66 ( & V_148 -> V_85 , V_164 ) ;
F_27 ( & V_164 -> V_35 , & V_137 ) ;
}
F_96 ( & V_166 ) ;
V_163:
F_24 ( & V_32 ) ;
}
static void F_98 ( struct V_24 * V_25 )
{
F_92 () ;
F_94 () ;
}
static void F_99 ( struct V_123 * V_27 )
{
if ( isalpha ( V_27 -> V_10 [ 0 ] ) )
V_27 -> V_10 [ 0 ] = toupper ( V_27 -> V_10 [ 0 ] ) ;
if ( isalpha ( V_27 -> V_10 [ 1 ] ) )
V_27 -> V_10 [ 1 ] = toupper ( V_27 -> V_10 [ 1 ] ) ;
F_83 ( & V_156 ) ;
F_27 ( & V_27 -> V_35 , & V_157 ) ;
F_84 ( & V_156 ) ;
F_28 ( & V_159 ) ;
}
static int F_100 ( const char * V_10 )
{
struct V_123 * V_27 ;
V_27 = F_18 ( sizeof( struct V_123 ) ,
V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_91 = V_98 ;
F_99 ( V_27 ) ;
return 0 ;
}
int F_101 ( const char * V_10 ,
enum V_168 V_124 )
{
struct V_123 * V_27 ;
F_6 ( ! V_10 ) ;
V_27 = F_18 ( sizeof( struct V_123 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_109 = V_169 ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_91 = V_93 ;
V_27 -> V_124 = V_124 ;
F_99 ( V_27 ) ;
return 0 ;
}
int F_102 ( struct V_85 * V_85 , const char * V_10 )
{
struct V_123 * V_27 ;
F_6 ( ! V_10 ) ;
F_6 ( ! V_85 ) ;
V_27 = F_18 ( sizeof( struct V_123 ) , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_27 -> V_109 = F_103 ( V_85 ) ;
F_6 ( ! F_89 ( V_27 -> V_109 ) ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_91 = V_99 ;
F_99 ( V_27 ) ;
return 0 ;
}
void F_104 ( struct V_85 * V_85 ,
enum V_102 V_103 ,
T_2 * V_170 ,
T_2 V_171 )
{
char V_10 [ 2 ] ;
enum V_172 V_173 = V_174 ;
struct V_123 * V_27 ;
F_20 ( & V_1 ) ;
if ( F_81 ( ! V_6 ) )
goto V_163;
if ( V_171 & 0x01 )
goto V_163;
if ( V_171 < V_175 )
goto V_163;
V_10 [ 0 ] = V_170 [ 0 ] ;
V_10 [ 1 ] = V_170 [ 1 ] ;
if ( V_170 [ 2 ] == 'I' )
V_173 = V_176 ;
else if ( V_170 [ 2 ] == 'O' )
V_173 = V_177 ;
if ( F_64 ( V_6 -> V_91 ==
V_92 &&
F_89 ( V_6 -> V_109 ) ) )
goto V_163;
V_27 = F_18 ( sizeof( struct V_123 ) , V_21 ) ;
if ( ! V_27 )
goto V_163;
V_27 -> V_109 = F_103 ( V_85 ) ;
V_27 -> V_10 [ 0 ] = V_10 [ 0 ] ;
V_27 -> V_10 [ 1 ] = V_10 [ 1 ] ;
V_27 -> V_91 = V_92 ;
V_27 -> V_178 = V_173 ;
F_24 ( & V_1 ) ;
F_99 ( V_27 ) ;
return;
V_163:
F_24 ( & V_1 ) ;
}
static void F_105 ( char * V_10 , bool V_179 )
{
V_10 [ 0 ] = '9' ;
V_10 [ 1 ] = '7' ;
if ( F_15 () ) {
if ( V_179 ) {
F_51 ( L_28
L_29 ) ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
if ( ! F_7 ( V_180 ) ) {
F_51 ( L_30
L_31 ,
V_180 [ 0 ] ,
V_180 [ 1 ] ) ;
V_10 [ 0 ] = V_180 [ 0 ] ;
V_10 [ 1 ] = V_180 [ 1 ] ;
}
} else {
F_51 ( L_28
L_32 ,
V_13 [ 0 ] ,
V_13 [ 1 ] ) ;
V_10 [ 0 ] = V_13 [ 0 ] ;
V_10 [ 1 ] = V_13 [ 1 ] ;
}
} else if ( ! F_7 ( V_180 ) ) {
F_51 ( L_30
L_31 ,
V_180 [ 0 ] ,
V_180 [ 1 ] ) ;
V_10 [ 0 ] = V_180 [ 0 ] ;
V_10 [ 1 ] = V_180 [ 1 ] ;
} else
F_51 ( L_33 ) ;
}
static void F_106 ( struct V_85 * V_85 )
{
struct V_106 * V_107 ;
enum V_102 V_103 ;
struct V_100 * V_101 ;
int V_18 ;
for ( V_103 = 0 ; V_103 < V_144 ; V_103 ++ ) {
V_107 = V_85 -> V_110 [ V_103 ] ;
if ( ! V_107 )
continue;
for ( V_18 = 0 ; V_18 < V_107 -> V_111 ; V_18 ++ ) {
V_101 = & V_107 -> V_112 [ V_18 ] ;
V_101 -> V_66 = V_101 -> V_113 ;
V_101 -> V_65 = V_101 -> V_117 ;
V_101 -> V_118 = V_101 -> V_119 ;
V_101 -> V_120 = false ;
}
}
}
static void F_107 ( bool V_179 )
{
char V_10 [ 2 ] ;
char V_181 [ 2 ] ;
struct V_133 * V_133 , * V_182 ;
struct V_123 * V_161 , * V_165 ;
F_108 ( V_183 ) ;
struct V_147 * V_148 ;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_105 ( V_10 , V_179 ) ;
F_83 ( & V_156 ) ;
if ( ! F_21 ( & V_157 ) ) {
F_97 (reg_request, tmp,
&reg_requests_list, list) {
if ( V_161 -> V_91 !=
V_93 )
continue;
F_23 ( & V_161 -> V_35 ) ;
F_27 ( & V_161 -> V_35 , & V_183 ) ;
}
}
F_84 ( & V_156 ) ;
F_95 ( & V_166 ) ;
if ( ! F_21 ( & V_167 ) ) {
F_97 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_133 -> V_35 ) ;
F_4 ( V_133 ) ;
}
}
F_96 ( & V_166 ) ;
if ( ! F_21 ( & V_137 ) ) {
F_97 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_133 -> V_35 ) ;
F_4 ( V_133 ) ;
}
}
V_3 = V_4 ;
V_181 [ 0 ] = V_3 -> V_10 [ 0 ] ;
V_181 [ 1 ] = V_3 -> V_10 [ 1 ] ;
F_68 (rdev, &cfg80211_rdev_list, list) {
if ( V_148 -> V_85 . V_66 & V_122 )
F_106 ( & V_148 -> V_85 ) ;
}
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
F_100 ( V_181 ) ;
if ( F_11 ( V_10 ) )
F_101 ( V_13 , V_184 ) ;
if ( F_21 ( & V_183 ) )
return;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
F_83 ( & V_156 ) ;
F_97 (reg_request, tmp, &tmp_reg_req_list, list) {
F_51 ( L_34
L_35 ,
V_161 -> V_10 [ 0 ] ,
V_161 -> V_10 [ 1 ] ) ;
F_23 ( & V_161 -> V_35 ) ;
F_27 ( & V_161 -> V_35 , & V_157 ) ;
}
F_84 ( & V_156 ) ;
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
F_51 ( L_36 ) ;
F_28 ( & V_159 ) ;
}
void F_109 ( void )
{
F_51 ( L_37
L_38 ) ;
F_107 ( false ) ;
}
static bool F_110 ( T_3 V_185 )
{
if ( V_185 == F_111 ( 12 , V_186 ) ||
V_185 == F_111 ( 13 , V_186 ) ||
V_185 == F_111 ( 14 , V_186 ) )
return true ;
return false ;
}
int F_112 ( struct V_85 * V_85 ,
struct V_100 * V_187 ,
T_4 V_188 )
{
struct V_133 * V_133 ;
if ( F_64 ( ( V_187 -> V_120 ||
( V_187 -> V_66 & V_82 ) ||
( V_187 -> V_103 == V_186 &&
! F_110 ( V_187 -> V_86 ) ) ) ) )
return 0 ;
V_133 = F_18 ( sizeof( struct V_133 ) , V_188 ) ;
if ( ! V_133 )
return - V_22 ;
F_51 ( L_39
L_40 ,
V_187 -> V_86 ,
F_113 ( V_187 -> V_86 ) ,
F_114 ( V_85 ) ) ;
memcpy ( & V_133 -> V_101 , V_187 ,
sizeof( struct V_100 ) ) ;
F_95 ( & V_166 ) ;
F_27 ( & V_133 -> V_35 , & V_167 ) ;
F_96 ( & V_166 ) ;
F_28 ( & V_159 ) ;
return 0 ;
}
static void F_115 ( const struct V_8 * V_9 )
{
unsigned int V_18 ;
const struct V_20 * V_50 = NULL ;
const struct V_44 * V_45 = NULL ;
const struct V_60 * V_63 = NULL ;
F_32 ( L_41 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_19 ; V_18 ++ ) {
V_50 = & V_9 -> V_23 [ V_18 ] ;
V_45 = & V_50 -> V_45 ;
V_63 = & V_50 -> V_63 ;
if ( V_63 -> V_65 )
F_32 ( L_42 ,
V_45 -> V_47 ,
V_45 -> V_48 ,
V_45 -> V_49 ,
V_63 -> V_65 ,
V_63 -> V_64 ) ;
else
F_32 ( L_43 ,
V_45 -> V_47 ,
V_45 -> V_48 ,
V_45 -> V_49 ,
V_63 -> V_64 ) ;
}
}
bool F_116 ( T_2 V_145 )
{
switch ( V_145 ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
return true ;
default:
F_51 ( L_44 ,
V_145 ) ;
return false ;
}
}
static void F_117 ( T_2 V_145 )
{
if ( ! V_145 )
return;
switch ( V_145 ) {
case V_190 :
F_32 ( L_45 ) ;
break;
case V_191 :
F_32 ( L_46 ) ;
break;
case V_192 :
F_32 ( L_47 ) ;
break;
default:
F_32 ( L_48 ) ;
break;
}
}
static void F_118 ( const struct V_8 * V_9 )
{
if ( F_10 ( V_9 -> V_10 ) ) {
if ( V_6 -> V_91 ==
V_92 ) {
struct V_147 * V_148 ;
V_148 = F_119 (
V_6 -> V_109 ) ;
if ( V_148 ) {
F_32 ( L_49 ,
V_148 -> V_193 [ 0 ] ,
V_148 -> V_193 [ 1 ] ) ;
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
F_117 ( V_9 -> V_145 ) ;
F_115 ( V_9 ) ;
}
static void F_120 ( const struct V_8 * V_9 )
{
F_32 ( L_56 , V_9 -> V_10 [ 0 ] , V_9 -> V_10 [ 1 ] ) ;
F_115 ( V_9 ) ;
}
static int F_121 ( const struct V_8 * V_9 )
{
const struct V_8 * V_194 = NULL ;
struct V_147 * V_148 = NULL ;
struct V_85 * V_108 ;
if ( F_7 ( V_9 -> V_10 ) ) {
if ( F_37 ( ! F_34 ( V_9 -> V_10 ) ) )
return - V_67 ;
F_5 ( V_9 ) ;
return 0 ;
}
if ( ! F_8 ( V_9 -> V_10 ) && ! F_11 ( V_9 -> V_10 ) &&
! F_9 ( V_9 -> V_10 ) )
return - V_67 ;
if ( ! V_6 )
return - V_67 ;
if ( V_6 -> V_91 != V_92 ) {
if ( ! F_13 ( V_9 -> V_10 ) )
return - V_130 ;
}
if ( F_37 ( ! F_34 ( V_9 -> V_10 ) ) )
return - V_67 ;
if ( ! F_36 ( V_9 ) ) {
F_122 ( L_57 ) ;
F_120 ( V_9 ) ;
return - V_67 ;
}
V_108 = F_54 ( V_6 -> V_109 ) ;
if ( ! V_108 &&
( V_6 -> V_91 == V_99 ||
V_6 -> V_91 == V_92 ) ) {
F_90 ( & V_158 , 0 ) ;
return - V_195 ;
}
if ( ! V_6 -> V_152 ) {
int V_30 ;
if ( V_6 -> V_91 != V_99 ) {
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_108 -> V_16 )
return - V_130 ;
V_30 = F_17 ( & V_108 -> V_16 , V_9 ) ;
if ( V_30 )
return V_30 ;
F_3 ( false ) ;
V_3 = V_9 ;
return 0 ;
}
if ( V_6 -> V_91 != V_92 ) {
V_194 = F_44 ( V_9 , V_3 ) ;
if ( ! V_194 )
return - V_67 ;
if ( V_6 -> V_91 == V_99 )
V_108 -> V_16 = V_9 ;
else
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_194 ;
return 0 ;
}
if ( ! V_194 )
return - V_67 ;
V_148 = F_123 ( V_108 ) ;
V_148 -> V_193 [ 0 ] = V_9 -> V_10 [ 0 ] ;
V_148 -> V_193 [ 1 ] = V_9 -> V_10 [ 1 ] ;
V_148 -> V_173 = V_6 -> V_178 ;
F_6 ( V_194 == V_9 ) ;
F_4 ( V_9 ) ;
V_9 = NULL ;
F_3 ( false ) ;
V_3 = V_194 ;
return 0 ;
}
int F_25 ( const struct V_8 * V_9 )
{
int V_30 ;
F_14 () ;
F_20 ( & V_1 ) ;
V_30 = F_121 ( V_9 ) ;
if ( V_30 ) {
if ( V_30 == - V_130 )
F_82 () ;
F_4 ( V_9 ) ;
F_24 ( & V_1 ) ;
return V_30 ;
}
if ( ! V_6 -> V_152 )
F_6 ( V_9 != V_3 ) ;
F_76 ( V_6 -> V_91 ) ;
F_118 ( V_3 ) ;
F_87 ( V_6 ) ;
F_82 () ;
F_24 ( & V_1 ) ;
return V_30 ;
}
int F_124 ( struct V_196 * V_40 , struct V_197 * V_173 )
{
if ( V_6 && ! V_6 -> V_155 ) {
if ( F_125 ( V_173 , L_58 ,
V_6 -> V_10 [ 0 ] ,
V_6 -> V_10 [ 1 ] ) )
return - V_22 ;
}
return 0 ;
}
int F_124 ( struct V_196 * V_40 , struct V_197 * V_173 )
{
return - V_195 ;
}
void F_126 ( struct V_85 * V_85 )
{
F_14 () ;
F_20 ( & V_1 ) ;
if ( ! F_61 ( V_85 ) )
V_128 ++ ;
F_75 ( V_85 , V_98 ) ;
F_24 ( & V_1 ) ;
}
void F_127 ( struct V_85 * V_85 )
{
struct V_85 * V_108 = NULL ;
F_14 () ;
F_20 ( & V_1 ) ;
if ( ! F_61 ( V_85 ) )
V_128 -- ;
F_4 ( V_85 -> V_16 ) ;
if ( V_6 )
V_108 = F_54 ( V_6 -> V_109 ) ;
if ( ! V_108 || V_108 != V_85 )
goto V_163;
V_6 -> V_109 = V_169 ;
V_6 -> V_178 = V_174 ;
V_163:
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
int V_198 = 0 ;
V_39 = F_130 ( L_61 , 0 , NULL , 0 ) ;
if ( F_131 ( V_39 ) )
return F_132 ( V_39 ) ;
V_39 -> V_40 . type = & V_199 ;
F_133 ( & V_156 ) ;
F_133 ( & V_166 ) ;
F_29 () ;
V_3 = V_4 ;
V_13 [ 0 ] = '9' ;
V_13 [ 1 ] = '7' ;
V_198 = F_100 ( V_3 -> V_10 ) ;
if ( V_198 ) {
if ( V_198 == - V_22 )
return V_198 ;
F_122 ( L_62 ) ;
#ifdef F_134
F_37 ( V_198 ) ;
#endif
}
if ( ! F_7 ( V_180 ) )
F_101 ( V_180 ,
V_184 ) ;
return 0 ;
}
void F_135 ( void )
{
struct V_123 * V_161 , * V_165 ;
struct V_133 * V_133 , * V_182 ;
F_136 ( & V_159 ) ;
F_137 ( & V_158 ) ;
F_20 ( & V_32 ) ;
F_20 ( & V_1 ) ;
F_3 ( true ) ;
F_138 ( & V_39 -> V_40 , true ) ;
F_139 ( V_39 ) ;
F_95 ( & V_166 ) ;
if ( ! F_21 ( & V_167 ) ) {
F_97 (reg_beacon, btmp,
&reg_pending_beacons, list) {
F_23 ( & V_133 -> V_35 ) ;
F_4 ( V_133 ) ;
}
}
F_96 ( & V_166 ) ;
if ( ! F_21 ( & V_137 ) ) {
F_97 (reg_beacon, btmp,
&reg_beacon_list, list) {
F_23 ( & V_133 -> V_35 ) ;
F_4 ( V_133 ) ;
}
}
F_83 ( & V_156 ) ;
if ( ! F_21 ( & V_157 ) ) {
F_97 (reg_request, tmp,
&reg_requests_list, list) {
F_23 ( & V_161 -> V_35 ) ;
F_4 ( V_161 ) ;
}
}
F_84 ( & V_156 ) ;
F_24 ( & V_1 ) ;
F_24 ( & V_32 ) ;
}
