static const struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ) ;
}
static const struct V_1 * F_3 ( struct V_3 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_4 ( const struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_5 ( (struct V_1 * ) V_5 , V_6 ) ;
}
static struct V_7 * F_6 ( void )
{
return F_7 ( V_8 ) ;
}
static void F_8 ( bool V_9 ,
const struct V_1 * V_10 )
{
const struct V_1 * V_5 ;
struct V_7 * V_11 ;
F_9 () ;
V_5 = F_1 () ;
if ( V_5 == V_12 )
V_5 = NULL ;
if ( V_12 == & V_13 )
V_12 = NULL ;
if ( V_5 == & V_13 )
V_5 = NULL ;
F_4 ( V_5 ) ;
F_4 ( V_12 ) ;
V_12 = & V_13 ;
F_10 ( V_2 , V_10 ) ;
if ( ! V_9 )
return;
V_11 = F_6 () ;
if ( V_11 != & V_14 && V_11 )
F_5 ( V_11 , V_6 ) ;
F_10 ( V_8 , & V_14 ) ;
}
static void F_11 ( const struct V_1 * V_15 )
{
struct V_7 * V_11 ;
V_11 = F_6 () ;
F_12 ( ! V_11 ) ;
F_8 ( false , V_15 ) ;
V_12 = V_15 ;
}
bool F_13 ( const char * V_16 )
{
if ( ! V_16 )
return false ;
return V_16 [ 0 ] == '0' && V_16 [ 1 ] == '0' ;
}
static bool F_14 ( const char * V_16 )
{
if ( ! V_16 )
return false ;
return V_16 [ 0 ] && V_16 [ 1 ] ;
}
static bool F_15 ( const char * V_16 )
{
if ( ! V_16 )
return false ;
return V_16 [ 0 ] == '9' && V_16 [ 1 ] == '9' ;
}
static bool F_16 ( const char * V_16 )
{
if ( ! V_16 )
return false ;
return V_16 [ 0 ] == '9' && V_16 [ 1 ] == '8' ;
}
static bool F_17 ( const char * V_16 )
{
if ( ! V_16 )
return false ;
return isalpha ( V_16 [ 0 ] ) && isalpha ( V_16 [ 1 ] ) ;
}
static bool F_18 ( const char * V_17 , const char * V_18 )
{
if ( ! V_17 || ! V_18 )
return false ;
return V_17 [ 0 ] == V_18 [ 0 ] && V_17 [ 1 ] == V_18 [ 1 ] ;
}
static bool F_19 ( const char * V_16 )
{
const struct V_1 * V_5 = F_1 () ;
if ( ! V_5 )
return true ;
return ! F_18 ( V_5 -> V_16 , V_16 ) ;
}
static bool F_20 ( void )
{
if ( V_19 [ 0 ] == '9' && V_19 [ 1 ] == '7' )
return false ;
if ( F_21 ( ! F_13 ( V_19 ) && ! F_17 ( V_19 ) ,
L_1 ,
V_19 [ 0 ] , V_19 [ 1 ] ) )
return false ;
return true ;
}
static const struct V_1 *
F_22 ( const struct V_1 * V_20 )
{
struct V_1 * V_4 ;
int V_21 ;
unsigned int V_22 ;
V_21 =
sizeof( struct V_1 ) +
V_20 -> V_23 * sizeof( struct V_24 ) ;
V_4 = F_23 ( V_21 , V_25 ) ;
if ( ! V_4 )
return F_24 ( - V_26 ) ;
memcpy ( V_4 , V_20 , sizeof( struct V_1 ) ) ;
for ( V_22 = 0 ; V_22 < V_20 -> V_23 ; V_22 ++ )
memcpy ( & V_4 -> V_27 [ V_22 ] , & V_20 -> V_27 [ V_22 ] ,
sizeof( struct V_24 ) ) ;
return V_4 ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_30 * V_31 ;
const struct V_1 * V_32 , * V_33 = NULL ;
int V_22 ;
F_26 () ;
F_27 ( & V_34 ) ;
while ( ! F_28 ( & V_35 ) ) {
V_31 = F_29 ( & V_35 ,
struct V_30 ,
V_36 ) ;
F_30 ( & V_31 -> V_36 ) ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ ) {
V_32 = V_38 [ V_22 ] ;
if ( F_18 ( V_31 -> V_16 , V_32 -> V_16 ) ) {
V_33 = F_22 ( V_32 ) ;
break;
}
}
F_31 ( V_31 ) ;
}
F_32 ( & V_34 ) ;
if ( ! F_33 ( V_33 ) )
F_34 ( V_33 ) ;
F_35 () ;
}
static void F_36 ( const char * V_16 )
{
struct V_30 * V_31 ;
if ( ! V_16 )
return;
V_31 = F_23 ( sizeof( struct V_30 ) , V_25 ) ;
if ( ! V_31 )
return;
memcpy ( V_31 -> V_16 , V_16 , 2 ) ;
F_27 ( & V_34 ) ;
F_37 ( & V_31 -> V_36 , & V_35 ) ;
F_32 ( & V_34 ) ;
F_38 ( & V_39 ) ;
}
static void F_39 ( void )
{
F_40 ( ! V_37 , L_2 ) ;
}
static inline void F_39 ( void ) {}
static inline void F_36 ( const char * V_16 ) {}
static int F_41 ( const char * V_16 )
{
if ( ! F_13 ( ( char * ) V_16 ) )
F_42 ( L_3 ,
V_16 [ 0 ] , V_16 [ 1 ] ) ;
else
F_42 ( L_4 ) ;
F_36 ( V_16 ) ;
return F_43 ( & V_40 -> V_41 . V_42 , V_43 ) ;
}
static bool F_44 ( const char * V_16 )
{
struct V_7 * V_11 = F_6 () ;
if ( ! V_11 || V_11 -> V_44 )
return false ;
return F_18 ( V_11 -> V_16 , V_16 ) ;
}
static bool F_45 ( const struct V_24 * V_45 )
{
const struct V_46 * V_47 = & V_45 -> V_47 ;
T_1 V_48 ;
if ( V_47 -> V_49 <= 0 || V_47 -> V_50 <= 0 )
return false ;
if ( V_47 -> V_49 > V_47 -> V_50 )
return false ;
V_48 = V_47 -> V_50 - V_47 -> V_49 ;
if ( V_47 -> V_50 <= V_47 -> V_49 ||
V_47 -> V_51 > V_48 )
return false ;
return true ;
}
static bool F_46 ( const struct V_1 * V_15 )
{
const struct V_24 * V_52 = NULL ;
unsigned int V_22 ;
if ( ! V_15 -> V_23 )
return false ;
if ( F_12 ( V_15 -> V_23 > V_53 ) )
return false ;
for ( V_22 = 0 ; V_22 < V_15 -> V_23 ; V_22 ++ ) {
V_52 = & V_15 -> V_27 [ V_22 ] ;
if ( ! F_45 ( V_52 ) )
return false ;
}
return true ;
}
static bool F_47 ( const struct V_46 * V_47 ,
T_1 V_54 , T_1 V_55 )
{
T_1 V_49 , V_50 ;
V_49 = V_54 - ( V_55 / 2 ) ;
V_50 = V_54 + ( V_55 / 2 ) ;
if ( V_49 >= V_47 -> V_49 &&
V_50 <= V_47 -> V_50 )
return true ;
return false ;
}
static bool F_48 ( const struct V_46 * V_47 ,
T_1 V_56 )
{
#define F_49 1000000
T_1 V_57 = V_56 > 45 * F_49 ?
10 * F_49 : 2 * F_49 ;
if ( abs ( V_56 - V_47 -> V_49 ) <= V_57 )
return true ;
if ( abs ( V_56 - V_47 -> V_50 ) <= V_57 )
return true ;
return false ;
#undef F_49
}
static int F_50 ( const struct V_24 * V_58 ,
const struct V_24 * V_59 ,
struct V_24 * V_60 )
{
const struct V_46 * V_61 , * V_62 ;
struct V_46 * V_47 ;
const struct V_63 * V_64 , * V_65 ;
struct V_63 * V_66 ;
T_1 V_48 ;
V_61 = & V_58 -> V_47 ;
V_62 = & V_59 -> V_47 ;
V_47 = & V_60 -> V_47 ;
V_64 = & V_58 -> V_66 ;
V_65 = & V_59 -> V_66 ;
V_66 = & V_60 -> V_66 ;
V_47 -> V_49 = F_51 ( V_61 -> V_49 ,
V_62 -> V_49 ) ;
V_47 -> V_50 = F_52 ( V_61 -> V_50 ,
V_62 -> V_50 ) ;
V_47 -> V_51 = F_52 ( V_61 -> V_51 ,
V_62 -> V_51 ) ;
V_48 = V_47 -> V_50 - V_47 -> V_49 ;
if ( V_47 -> V_51 > V_48 )
V_47 -> V_51 = V_48 ;
V_66 -> V_67 = F_52 ( V_64 -> V_67 ,
V_65 -> V_67 ) ;
V_66 -> V_68 = F_52 ( V_64 -> V_68 ,
V_65 -> V_68 ) ;
V_60 -> V_69 = V_58 -> V_69 | V_59 -> V_69 ;
if ( ! F_45 ( V_60 ) )
return - V_70 ;
return 0 ;
}
static struct V_1 *
F_53 ( const struct V_1 * V_71 ,
const struct V_1 * V_72 )
{
int V_5 , V_21 ;
unsigned int V_73 , V_74 ;
unsigned int V_75 = 0 , V_76 = 0 ;
const struct V_24 * V_58 , * V_59 ;
struct V_24 * V_60 ;
struct V_1 * V_15 ;
struct V_24 V_77 ;
if ( ! V_71 || ! V_72 )
return NULL ;
for ( V_73 = 0 ; V_73 < V_71 -> V_23 ; V_73 ++ ) {
V_58 = & V_71 -> V_27 [ V_73 ] ;
for ( V_74 = 0 ; V_74 < V_72 -> V_23 ; V_74 ++ ) {
V_59 = & V_72 -> V_27 [ V_74 ] ;
if ( ! F_50 ( V_58 , V_59 , & V_77 ) )
V_75 ++ ;
}
}
if ( ! V_75 )
return NULL ;
V_21 = sizeof( struct V_1 ) +
V_75 * sizeof( struct V_24 ) ;
V_15 = F_23 ( V_21 , V_25 ) ;
if ( ! V_15 )
return NULL ;
for ( V_73 = 0 ; V_73 < V_71 -> V_23 && V_76 < V_75 ; V_73 ++ ) {
V_58 = & V_71 -> V_27 [ V_73 ] ;
for ( V_74 = 0 ; V_74 < V_72 -> V_23 && V_76 < V_75 ; V_74 ++ ) {
V_59 = & V_72 -> V_27 [ V_74 ] ;
V_60 = & V_15 -> V_27 [ V_76 ] ;
V_5 = F_50 ( V_58 , V_59 , V_60 ) ;
if ( V_5 )
continue;
V_76 ++ ;
}
}
if ( V_76 != V_75 ) {
F_31 ( V_15 ) ;
return NULL ;
}
V_15 -> V_23 = V_75 ;
V_15 -> V_16 [ 0 ] = '9' ;
V_15 -> V_16 [ 1 ] = '8' ;
return V_15 ;
}
static T_1 F_54 ( T_1 V_78 )
{
T_1 V_79 = 0 ;
if ( V_78 & V_80 )
V_79 |= V_81 ;
if ( V_78 & V_82 )
V_79 |= V_83 ;
if ( V_78 & V_84 )
V_79 |= V_85 ;
if ( V_78 & V_86 )
V_79 |= V_87 ;
return V_79 ;
}
static const struct V_24 *
F_55 ( struct V_3 * V_3 , T_1 V_88 ,
const struct V_1 * V_4 )
{
int V_22 ;
bool V_89 = false ;
bool V_90 = false ;
if ( ! V_4 )
return F_24 ( - V_70 ) ;
for ( V_22 = 0 ; V_22 < V_4 -> V_23 ; V_22 ++ ) {
const struct V_24 * V_91 ;
const struct V_46 * V_92 = NULL ;
V_91 = & V_4 -> V_27 [ V_22 ] ;
V_92 = & V_91 -> V_47 ;
if ( ! V_89 )
V_89 = F_48 ( V_92 , V_88 ) ;
V_90 = F_47 ( V_92 , V_88 , F_56 ( 20 ) ) ;
if ( V_89 && V_90 )
return V_91 ;
}
if ( ! V_89 )
return F_24 ( - V_93 ) ;
return F_24 ( - V_70 ) ;
}
const struct V_24 * F_57 ( struct V_3 * V_3 ,
T_1 V_88 )
{
const struct V_1 * V_4 ;
struct V_7 * V_11 = F_6 () ;
if ( V_11 -> V_94 != V_95 &&
V_11 -> V_94 != V_96 &&
V_3 -> V_4 )
V_4 = F_3 ( V_3 ) ;
else
V_4 = F_1 () ;
return F_55 ( V_3 , V_88 , V_4 ) ;
}
const char * F_58 ( enum V_97 V_94 )
{
switch ( V_94 ) {
case V_98 :
return L_5 ;
case V_96 :
return L_6 ;
case V_99 :
return L_7 ;
case V_95 :
return L_8 ;
default:
F_12 ( 1 ) ;
return L_9 ;
}
}
static void F_59 ( struct V_100 * V_101 ,
const struct V_24 * V_52 )
{
const struct V_63 * V_66 ;
const struct V_46 * V_47 ;
char V_68 [ 32 ] ;
V_66 = & V_52 -> V_66 ;
V_47 = & V_52 -> V_47 ;
if ( ! V_66 -> V_68 )
snprintf ( V_68 , 32 , L_10 ) ;
else
snprintf ( V_68 , 32 , L_11 , V_66 -> V_68 ) ;
F_60 ( L_12 ,
V_101 -> V_88 ) ;
F_60 ( L_13 ,
V_47 -> V_49 , V_47 -> V_50 ,
V_47 -> V_51 , V_68 ,
V_66 -> V_67 ) ;
}
static void F_59 ( struct V_100 * V_101 ,
const struct V_24 * V_52 )
{
return;
}
static void F_61 ( struct V_3 * V_3 ,
enum V_97 V_94 ,
struct V_100 * V_101 )
{
T_1 V_69 , V_102 = 0 ;
const struct V_24 * V_52 = NULL ;
const struct V_63 * V_66 = NULL ;
const struct V_46 * V_47 = NULL ;
struct V_3 * V_103 = NULL ;
struct V_7 * V_11 = F_6 () ;
V_103 = F_62 ( V_11 -> V_104 ) ;
V_69 = V_101 -> V_105 ;
V_52 = F_57 ( V_3 , F_56 ( V_101 -> V_88 ) ) ;
if ( F_63 ( V_52 ) ) {
if ( V_94 == V_95 &&
F_64 ( V_52 ) == - V_93 )
return;
F_60 ( L_14 , V_101 -> V_88 ) ;
V_101 -> V_69 |= V_106 ;
return;
}
F_59 ( V_101 , V_52 ) ;
V_66 = & V_52 -> V_66 ;
V_47 = & V_52 -> V_47 ;
if ( V_47 -> V_51 < F_56 ( 40 ) )
V_102 = V_107 ;
if ( V_47 -> V_51 < F_56 ( 80 ) )
V_102 |= V_108 ;
if ( V_47 -> V_51 < F_56 ( 160 ) )
V_102 |= V_109 ;
if ( V_11 -> V_94 == V_99 &&
V_103 && V_103 == V_3 &&
V_103 -> V_69 & V_110 ) {
V_101 -> V_69 = V_101 -> V_105 =
F_54 ( V_52 -> V_69 ) | V_102 ;
V_101 -> V_68 = V_101 -> V_111 =
( int ) F_65 ( V_66 -> V_68 ) ;
V_101 -> V_112 = V_101 -> V_113 = V_101 -> V_114 =
( int ) F_66 ( V_66 -> V_67 ) ;
return;
}
V_101 -> V_115 = V_116 ;
V_101 -> V_117 = V_118 ;
V_101 -> V_119 = false ;
V_101 -> V_69 = V_69 | V_102 | F_54 ( V_52 -> V_69 ) ;
V_101 -> V_68 =
F_67 ( int , V_101 -> V_111 ,
F_65 ( V_66 -> V_68 ) ) ;
V_101 -> V_112 = ( int ) F_66 ( V_66 -> V_67 ) ;
if ( V_101 -> V_114 ) {
if ( V_94 == V_95 &&
V_3 -> V_69 & V_120 &&
V_3 -> V_69 & V_110 )
V_101 -> V_113 = V_101 -> V_112 ;
else
V_101 -> V_113 = F_52 ( V_101 -> V_114 ,
V_101 -> V_112 ) ;
} else
V_101 -> V_113 = V_101 -> V_112 ;
}
static void F_68 ( struct V_3 * V_3 ,
enum V_97 V_94 ,
struct V_121 * V_122 )
{
unsigned int V_22 ;
if ( ! V_122 )
return;
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ )
F_61 ( V_3 , V_94 , & V_122 -> V_124 [ V_22 ] ) ;
}
static bool F_69 ( struct V_7 * V_31 )
{
if ( V_31 -> V_94 != V_96 )
return false ;
return V_31 -> V_125 == V_126 ;
}
bool F_70 ( void )
{
return F_69 ( F_6 () ) ;
}
static enum V_127
F_71 ( struct V_7 * V_128 )
{
struct V_7 * V_11 = F_6 () ;
if ( ! V_129 )
return V_130 ;
if ( F_69 ( V_11 ) &&
! F_19 ( V_128 -> V_16 ) )
return V_131 ;
return V_132 ;
}
static bool F_72 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_133 & V_134 ) ;
}
static int F_71 ( struct V_7 * V_128 )
{
return V_130 ;
}
static bool F_72 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_73 ( struct V_3 * V_3 )
{
if ( V_3 -> V_69 & V_110 &&
! ( V_3 -> V_69 & V_120 ) )
return true ;
return false ;
}
static bool F_74 ( struct V_3 * V_3 ,
enum V_97 V_94 )
{
struct V_7 * V_11 = F_6 () ;
if ( ! V_11 ) {
F_60 ( L_15
L_16 ,
F_58 ( V_94 ) ) ;
return true ;
}
if ( V_94 == V_98 &&
V_3 -> V_69 & V_120 ) {
F_60 ( L_15
L_17
L_18 ,
F_58 ( V_94 ) ) ;
return true ;
}
if ( F_73 ( V_3 ) && ! V_3 -> V_4 &&
V_94 != V_95 &&
! F_13 ( V_11 -> V_16 ) ) {
F_60 ( L_15
L_19
L_20 ,
F_58 ( V_94 ) ) ;
return true ;
}
if ( F_69 ( V_11 ) )
return F_72 ( V_3 ) ;
return false ;
}
static bool F_75 ( struct V_3 * V_3 )
{
const struct V_1 * V_135 = F_1 () ;
const struct V_1 * V_136 = F_3 ( V_3 ) ;
struct V_7 * V_11 = F_6 () ;
if ( F_13 ( V_135 -> V_16 ) || ( V_136 && F_13 ( V_136 -> V_16 ) ) )
return true ;
if ( V_11 && V_11 -> V_94 != V_95 &&
V_3 -> V_69 & V_120 )
return true ;
return false ;
}
static void F_76 ( struct V_3 * V_3 , unsigned int V_137 ,
struct V_138 * V_138 )
{
struct V_121 * V_122 ;
struct V_100 * V_101 ;
bool V_139 = false ;
struct V_100 V_140 ;
V_122 = V_3 -> V_141 [ V_138 -> V_101 . V_142 ] ;
V_101 = & V_122 -> V_124 [ V_137 ] ;
if ( F_77 ( V_101 -> V_88 != V_138 -> V_101 . V_88 ) )
return;
if ( V_101 -> V_119 )
return;
V_101 -> V_119 = true ;
if ( ! F_75 ( V_3 ) )
return;
if ( V_3 -> V_69 & V_143 )
return;
V_140 . V_88 = V_101 -> V_88 ;
V_140 . V_69 = V_101 -> V_69 ;
if ( V_101 -> V_69 & V_81 ) {
V_101 -> V_69 &= ~ V_81 ;
V_139 = true ;
}
if ( V_101 -> V_69 & V_83 ) {
V_101 -> V_69 &= ~ V_83 ;
V_139 = true ;
}
if ( V_139 )
F_78 ( V_3 , & V_140 , V_101 ) ;
}
static void F_79 ( struct V_3 * V_3 ,
struct V_138 * V_138 )
{
unsigned int V_22 ;
struct V_121 * V_122 ;
if ( ! V_3 -> V_141 [ V_138 -> V_101 . V_142 ] )
return;
V_122 = V_3 -> V_141 [ V_138 -> V_101 . V_142 ] ;
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ )
F_76 ( V_3 , V_22 , V_138 ) ;
}
static void F_80 ( struct V_3 * V_3 )
{
unsigned int V_22 ;
struct V_121 * V_122 ;
struct V_138 * V_138 ;
F_81 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_141 [ V_138 -> V_101 . V_142 ] )
continue;
V_122 = V_3 -> V_141 [ V_138 -> V_101 . V_142 ] ;
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ )
F_76 ( V_3 , V_22 , V_138 ) ;
}
}
static void F_82 ( struct V_3 * V_3 )
{
if ( ! V_8 )
return;
F_80 ( V_3 ) ;
}
static bool F_83 ( struct V_100 * V_101 )
{
if ( ! V_101 )
return false ;
if ( V_101 -> V_69 & V_106 )
return false ;
if ( ( V_101 -> V_69 & V_107 ) == V_107 )
return false ;
return true ;
}
static void F_84 ( struct V_3 * V_3 ,
struct V_100 * V_144 )
{
struct V_121 * V_122 = V_3 -> V_141 [ V_144 -> V_142 ] ;
struct V_100 * V_145 = NULL , * V_146 = NULL ;
unsigned int V_22 ;
if ( ! F_83 ( V_144 ) ) {
V_144 -> V_69 |= V_107 ;
return;
}
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ ) {
struct V_100 * V_147 = & V_122 -> V_124 [ V_22 ] ;
if ( V_147 -> V_88 == ( V_144 -> V_88 - 20 ) )
V_145 = V_147 ;
if ( V_147 -> V_88 == ( V_144 -> V_88 + 20 ) )
V_146 = V_147 ;
}
if ( ! F_83 ( V_145 ) )
V_144 -> V_69 |= V_148 ;
else
V_144 -> V_69 &= ~ V_148 ;
if ( ! F_83 ( V_146 ) )
V_144 -> V_69 |= V_149 ;
else
V_144 -> V_69 &= ~ V_149 ;
}
static void F_85 ( struct V_3 * V_3 ,
struct V_121 * V_122 )
{
unsigned int V_22 ;
if ( ! V_122 )
return;
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ )
F_84 ( V_3 , & V_122 -> V_124 [ V_22 ] ) ;
}
static void F_86 ( struct V_3 * V_3 )
{
enum V_150 V_142 ;
if ( ! V_3 )
return;
for ( V_142 = 0 ; V_142 < V_151 ; V_142 ++ )
F_85 ( V_3 , V_3 -> V_141 [ V_142 ] ) ;
}
static void F_87 ( struct V_3 * V_3 ,
enum V_97 V_94 )
{
enum V_150 V_142 ;
struct V_7 * V_11 = F_6 () ;
if ( F_74 ( V_3 , V_94 ) )
return;
V_11 -> V_152 = F_1 () -> V_152 ;
for ( V_142 = 0 ; V_142 < V_151 ; V_142 ++ )
F_68 ( V_3 , V_94 , V_3 -> V_141 [ V_142 ] ) ;
F_82 ( V_3 ) ;
F_86 ( V_3 ) ;
if ( V_3 -> V_153 )
V_3 -> V_153 ( V_3 , V_11 ) ;
}
static void F_88 ( enum V_97 V_94 )
{
struct V_154 * V_155 ;
struct V_3 * V_3 ;
F_9 () ;
F_81 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_155 -> V_3 ;
F_87 ( V_3 , V_94 ) ;
if ( V_94 == V_98 &&
V_3 -> V_69 & V_120 &&
V_3 -> V_153 )
V_3 -> V_153 ( V_3 , F_6 () ) ;
}
}
static void F_89 ( struct V_3 * V_3 ,
struct V_100 * V_101 ,
const struct V_1 * V_4 )
{
T_1 V_102 = 0 ;
const struct V_24 * V_52 = NULL ;
const struct V_63 * V_66 = NULL ;
const struct V_46 * V_47 = NULL ;
V_52 = F_55 ( V_3 , F_56 ( V_101 -> V_88 ) ,
V_4 ) ;
if ( F_63 ( V_52 ) ) {
F_60 ( L_21 ,
V_101 -> V_88 ) ;
V_101 -> V_69 = V_106 ;
return;
}
F_59 ( V_101 , V_52 ) ;
V_66 = & V_52 -> V_66 ;
V_47 = & V_52 -> V_47 ;
if ( V_47 -> V_51 < F_56 ( 40 ) )
V_102 = V_107 ;
if ( V_47 -> V_51 < F_56 ( 80 ) )
V_102 |= V_108 ;
if ( V_47 -> V_51 < F_56 ( 160 ) )
V_102 |= V_109 ;
V_101 -> V_69 |= F_54 ( V_52 -> V_69 ) | V_102 ;
V_101 -> V_68 = ( int ) F_65 ( V_66 -> V_68 ) ;
V_101 -> V_112 = V_101 -> V_113 =
( int ) F_66 ( V_66 -> V_67 ) ;
}
static void F_90 ( struct V_3 * V_3 ,
struct V_121 * V_122 ,
const struct V_1 * V_4 )
{
unsigned int V_22 ;
if ( ! V_122 )
return;
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ )
F_89 ( V_3 , & V_122 -> V_124 [ V_22 ] , V_4 ) ;
}
void F_91 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_150 V_142 ;
unsigned int V_156 = 0 ;
for ( V_142 = 0 ; V_142 < V_151 ; V_142 ++ ) {
if ( ! V_3 -> V_141 [ V_142 ] )
continue;
F_90 ( V_3 , V_3 -> V_141 [ V_142 ] , V_4 ) ;
V_156 ++ ;
}
F_12 ( ! V_156 ) ;
}
static enum V_127
F_92 ( struct V_3 * V_3 ,
struct V_7 * V_128 )
{
struct V_3 * V_157 = NULL ;
struct V_7 * V_11 = F_6 () ;
if ( ! V_11 )
return V_132 ;
switch ( V_128 -> V_94 ) {
case V_98 :
return V_132 ;
case V_95 :
if ( F_69 ( V_11 ) ) {
if ( F_19 ( V_128 -> V_16 ) )
return V_130 ;
return V_131 ;
}
V_157 = F_62 ( V_11 -> V_104 ) ;
if ( F_93 ( ! F_17 ( V_128 -> V_16 ) ) )
return - V_70 ;
if ( V_11 -> V_94 == V_95 ) {
if ( V_157 != V_3 ) {
if ( F_19 ( V_128 -> V_16 ) )
return V_130 ;
return V_131 ;
}
if ( F_12 ( F_19 ( V_128 -> V_16 ) ) )
return V_132 ;
return V_131 ;
}
return V_132 ;
case V_99 :
if ( V_11 -> V_94 == V_98 ) {
if ( F_19 ( V_128 -> V_16 ) )
return V_132 ;
return V_131 ;
}
if ( V_11 -> V_94 == V_99 &&
! F_19 ( V_128 -> V_16 ) )
return V_131 ;
return V_158 ;
case V_96 :
if ( F_69 ( V_128 ) )
return F_71 ( V_128 ) ;
if ( F_69 ( V_11 ) )
return V_130 ;
if ( V_11 -> V_94 == V_95 )
return V_158 ;
if ( V_11 -> V_94 == V_96 &&
V_11 -> V_159 )
return V_130 ;
if ( ( V_11 -> V_94 == V_98 ||
V_11 -> V_94 == V_99 ||
V_11 -> V_94 == V_96 ) &&
F_19 ( V_11 -> V_16 ) )
return V_130 ;
if ( ! F_19 ( V_128 -> V_16 ) )
return V_131 ;
return V_132 ;
}
return V_130 ;
}
static void F_94 ( void )
{
bool V_160 = false ;
struct V_7 * V_11 = F_6 () ;
V_11 -> V_44 = true ;
F_95 ( & V_161 ) ;
if ( ! F_28 ( & V_162 ) )
V_160 = true ;
F_96 ( & V_161 ) ;
if ( V_11 -> V_94 == V_96 )
F_97 ( & V_163 ) ;
if ( V_160 )
F_38 ( & V_164 ) ;
}
static enum V_127
F_98 ( struct V_3 * V_3 ,
struct V_7 * V_128 )
{
const struct V_1 * V_4 ;
bool V_159 = false ;
enum V_127 V_165 ;
struct V_7 * V_11 ;
V_165 = F_92 ( V_3 , V_128 ) ;
switch ( V_165 ) {
case V_158 :
if ( V_128 -> V_94 ==
V_99 ) {
V_4 = F_22 ( F_1 () ) ;
if ( F_63 ( V_4 ) ) {
F_31 ( V_128 ) ;
return F_64 ( V_4 ) ;
}
F_10 ( V_3 -> V_4 , V_4 ) ;
}
V_159 = true ;
break;
case V_132 :
break;
default:
if ( V_165 == V_131 &&
V_128 -> V_94 == V_99 ) {
V_4 = F_22 ( F_1 () ) ;
if ( F_63 ( V_4 ) ) {
F_31 ( V_128 ) ;
return V_130 ;
}
V_165 = V_131 ;
F_10 ( V_3 -> V_4 , V_4 ) ;
goto V_166;
}
F_31 ( V_128 ) ;
return V_165 ;
}
V_166:
V_11 = F_6 () ;
if ( V_11 != & V_14 && V_11 )
F_5 ( V_11 , V_6 ) ;
V_128 -> V_159 = V_159 ;
V_128 -> V_44 = false ;
F_10 ( V_8 , V_128 ) ;
V_11 = V_128 ;
V_128 = NULL ;
if ( V_11 -> V_94 == V_96 ) {
V_19 [ 0 ] = V_11 -> V_16 [ 0 ] ;
V_19 [ 1 ] = V_11 -> V_16 [ 1 ] ;
}
if ( V_165 != V_132 && V_165 != V_158 ) {
if ( V_165 == V_131 ) {
F_99 ( V_11 ) ;
F_94 () ;
}
return V_165 ;
}
if ( F_41 ( V_11 -> V_16 ) )
return V_130 ;
return V_132 ;
}
static void F_100 ( struct V_7 * V_167 ,
enum V_97 V_168 )
{
struct V_3 * V_3 = NULL ;
if ( F_12 ( ! V_167 -> V_16 ) )
return;
if ( V_167 -> V_104 != V_169 )
V_3 = F_62 ( V_167 -> V_104 ) ;
if ( V_168 == V_99 && ! V_3 ) {
F_31 ( V_167 ) ;
return;
}
switch ( F_98 ( V_3 , V_167 ) ) {
case V_131 :
if ( V_3 && V_3 -> V_69 & V_110 )
F_87 ( V_3 , V_168 ) ;
break;
default:
if ( V_168 == V_96 )
F_101 ( & V_163 ,
F_102 ( 3142 ) ) ;
break;
}
}
static void F_103 ( void )
{
struct V_7 * V_167 , * V_11 ;
V_11 = F_6 () ;
if ( V_11 && ! V_11 -> V_44 ) {
F_60 ( L_22 ) ;
return;
}
F_95 ( & V_161 ) ;
if ( F_28 ( & V_162 ) ) {
F_96 ( & V_161 ) ;
return;
}
V_167 = F_29 ( & V_162 ,
struct V_7 ,
V_36 ) ;
F_104 ( & V_167 -> V_36 ) ;
F_96 ( & V_161 ) ;
F_100 ( V_167 , V_167 -> V_94 ) ;
}
static void F_105 ( void )
{
struct V_154 * V_155 ;
struct V_138 * V_170 , * V_171 ;
F_106 ( & V_172 ) ;
F_107 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_104 ( & V_170 -> V_36 ) ;
F_81 (rdev, &cfg80211_rdev_list, list)
F_79 ( & V_155 -> V_3 , V_170 ) ;
F_37 ( & V_170 -> V_36 , & V_173 ) ;
}
F_108 ( & V_172 ) ;
}
static void F_109 ( struct V_28 * V_29 )
{
F_26 () ;
F_103 () ;
F_105 () ;
F_35 () ;
}
static void F_110 ( struct V_7 * V_31 )
{
V_31 -> V_16 [ 0 ] = toupper ( V_31 -> V_16 [ 0 ] ) ;
V_31 -> V_16 [ 1 ] = toupper ( V_31 -> V_16 [ 1 ] ) ;
F_95 ( & V_161 ) ;
F_37 ( & V_31 -> V_36 , & V_162 ) ;
F_96 ( & V_161 ) ;
F_38 ( & V_164 ) ;
}
static int F_111 ( const char * V_16 )
{
struct V_7 * V_31 ;
V_31 = F_23 ( sizeof( struct V_7 ) , V_25 ) ;
if ( ! V_31 )
return - V_26 ;
V_31 -> V_16 [ 0 ] = V_16 [ 0 ] ;
V_31 -> V_16 [ 1 ] = V_16 [ 1 ] ;
V_31 -> V_94 = V_98 ;
F_110 ( V_31 ) ;
return 0 ;
}
int F_112 ( const char * V_16 ,
enum V_174 V_125 )
{
struct V_7 * V_31 ;
if ( F_12 ( ! V_16 ) )
return - V_70 ;
V_31 = F_23 ( sizeof( struct V_7 ) , V_25 ) ;
if ( ! V_31 )
return - V_26 ;
V_31 -> V_104 = V_169 ;
V_31 -> V_16 [ 0 ] = V_16 [ 0 ] ;
V_31 -> V_16 [ 1 ] = V_16 [ 1 ] ;
V_31 -> V_94 = V_96 ;
V_31 -> V_125 = V_125 ;
F_110 ( V_31 ) ;
return 0 ;
}
int F_113 ( struct V_3 * V_3 , const char * V_16 )
{
struct V_7 * V_31 ;
if ( F_12 ( ! V_16 || ! V_3 ) )
return - V_70 ;
V_31 = F_23 ( sizeof( struct V_7 ) , V_25 ) ;
if ( ! V_31 )
return - V_26 ;
V_31 -> V_104 = F_114 ( V_3 ) ;
V_31 -> V_16 [ 0 ] = V_16 [ 0 ] ;
V_31 -> V_16 [ 1 ] = V_16 [ 1 ] ;
V_31 -> V_94 = V_99 ;
F_110 ( V_31 ) ;
return 0 ;
}
void F_115 ( struct V_3 * V_3 , enum V_150 V_142 ,
const T_2 * V_175 , T_2 V_176 )
{
char V_16 [ 2 ] ;
enum V_177 V_178 = V_179 ;
struct V_7 * V_31 = NULL , * V_11 ;
if ( V_176 & 0x01 )
return;
if ( V_176 < V_180 )
return;
V_31 = F_23 ( sizeof( * V_31 ) , V_25 ) ;
if ( ! V_31 )
return;
V_16 [ 0 ] = V_175 [ 0 ] ;
V_16 [ 1 ] = V_175 [ 1 ] ;
if ( V_175 [ 2 ] == 'I' )
V_178 = V_181 ;
else if ( V_175 [ 2 ] == 'O' )
V_178 = V_182 ;
F_116 () ;
V_11 = F_6 () ;
if ( F_93 ( ! V_11 ) )
goto V_183;
if ( V_11 -> V_94 == V_95 &&
V_11 -> V_104 != V_169 )
goto V_183;
V_31 -> V_104 = F_114 ( V_3 ) ;
V_31 -> V_16 [ 0 ] = V_16 [ 0 ] ;
V_31 -> V_16 [ 1 ] = V_16 [ 1 ] ;
V_31 -> V_94 = V_95 ;
V_31 -> V_184 = V_178 ;
F_110 ( V_31 ) ;
V_31 = NULL ;
V_183:
F_31 ( V_31 ) ;
F_117 () ;
}
static void F_118 ( char * V_16 , bool V_185 )
{
V_16 [ 0 ] = '9' ;
V_16 [ 1 ] = '7' ;
if ( F_20 () ) {
if ( V_185 ) {
F_60 ( L_23 ) ;
V_19 [ 0 ] = '9' ;
V_19 [ 1 ] = '7' ;
if ( ! F_13 ( V_186 ) ) {
F_60 ( L_24 ,
V_186 [ 0 ] , V_186 [ 1 ] ) ;
V_16 [ 0 ] = V_186 [ 0 ] ;
V_16 [ 1 ] = V_186 [ 1 ] ;
}
} else {
F_60 ( L_25 ,
V_19 [ 0 ] , V_19 [ 1 ] ) ;
V_16 [ 0 ] = V_19 [ 0 ] ;
V_16 [ 1 ] = V_19 [ 1 ] ;
}
} else if ( ! F_13 ( V_186 ) ) {
F_60 ( L_24 ,
V_186 [ 0 ] , V_186 [ 1 ] ) ;
V_16 [ 0 ] = V_186 [ 0 ] ;
V_16 [ 1 ] = V_186 [ 1 ] ;
} else
F_60 ( L_26 ) ;
}
static void F_119 ( struct V_3 * V_3 )
{
struct V_121 * V_122 ;
enum V_150 V_142 ;
struct V_100 * V_101 ;
int V_22 ;
for ( V_142 = 0 ; V_142 < V_151 ; V_142 ++ ) {
V_122 = V_3 -> V_141 [ V_142 ] ;
if ( ! V_122 )
continue;
for ( V_22 = 0 ; V_22 < V_122 -> V_123 ; V_22 ++ ) {
V_101 = & V_122 -> V_124 [ V_22 ] ;
V_101 -> V_69 = V_101 -> V_105 ;
V_101 -> V_68 = V_101 -> V_111 ;
V_101 -> V_113 = V_101 -> V_114 ;
V_101 -> V_119 = false ;
}
}
}
static void F_120 ( bool V_185 )
{
char V_16 [ 2 ] ;
char V_187 [ 2 ] ;
struct V_138 * V_138 , * V_188 ;
struct V_7 * V_167 , * V_171 ;
F_121 ( V_189 ) ;
struct V_154 * V_155 ;
F_9 () ;
F_8 ( true , & V_13 ) ;
F_118 ( V_16 , V_185 ) ;
F_95 ( & V_161 ) ;
F_107 (reg_request, tmp, &reg_requests_list, list) {
if ( V_167 -> V_94 != V_96 )
continue;
F_122 ( & V_167 -> V_36 , & V_189 ) ;
}
F_96 ( & V_161 ) ;
F_106 ( & V_172 ) ;
F_107 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_30 ( & V_138 -> V_36 ) ;
F_31 ( V_138 ) ;
}
F_108 ( & V_172 ) ;
F_107 (reg_beacon, btmp, &reg_beacon_list, list) {
F_30 ( & V_138 -> V_36 ) ;
F_31 ( V_138 ) ;
}
V_187 [ 0 ] = V_12 -> V_16 [ 0 ] ;
V_187 [ 1 ] = V_12 -> V_16 [ 1 ] ;
F_81 (rdev, &cfg80211_rdev_list, list) {
if ( V_155 -> V_3 . V_69 & V_120 )
F_119 ( & V_155 -> V_3 ) ;
}
F_111 ( V_187 ) ;
if ( F_17 ( V_16 ) )
F_112 ( V_19 , V_190 ) ;
F_95 ( & V_161 ) ;
F_123 ( & V_189 , & V_162 ) ;
F_96 ( & V_161 ) ;
F_60 ( L_27 ) ;
F_38 ( & V_164 ) ;
}
void F_124 ( void )
{
F_60 ( L_28 ) ;
F_120 ( false ) ;
}
static bool F_125 ( T_3 V_191 )
{
if ( V_191 == F_126 ( 12 , V_192 ) ||
V_191 == F_126 ( 13 , V_192 ) ||
V_191 == F_126 ( 14 , V_192 ) )
return true ;
return false ;
}
static bool F_127 ( struct V_100 * V_193 )
{
struct V_138 * V_170 ;
F_81 (pending_beacon, &reg_pending_beacons, list)
if ( V_193 -> V_88 ==
V_170 -> V_101 . V_88 )
return true ;
return false ;
}
int F_128 ( struct V_3 * V_3 ,
struct V_100 * V_193 ,
T_4 V_194 )
{
struct V_138 * V_138 ;
bool V_195 ;
if ( V_193 -> V_119 ||
V_193 -> V_69 & V_85 ||
( V_193 -> V_142 == V_192 &&
! F_125 ( V_193 -> V_88 ) ) )
return 0 ;
F_106 ( & V_172 ) ;
V_195 = F_127 ( V_193 ) ;
F_108 ( & V_172 ) ;
if ( V_195 )
return 0 ;
V_138 = F_23 ( sizeof( struct V_138 ) , V_194 ) ;
if ( ! V_138 )
return - V_26 ;
F_60 ( L_29 ,
V_193 -> V_88 ,
F_129 ( V_193 -> V_88 ) ,
F_130 ( V_3 ) ) ;
memcpy ( & V_138 -> V_101 , V_193 ,
sizeof( struct V_100 ) ) ;
F_106 ( & V_172 ) ;
F_37 ( & V_138 -> V_36 , & V_196 ) ;
F_108 ( & V_172 ) ;
F_38 ( & V_164 ) ;
return 0 ;
}
static void F_131 ( const struct V_1 * V_15 )
{
unsigned int V_22 ;
const struct V_24 * V_52 = NULL ;
const struct V_46 * V_47 = NULL ;
const struct V_63 * V_66 = NULL ;
F_42 ( L_30 ) ;
for ( V_22 = 0 ; V_22 < V_15 -> V_23 ; V_22 ++ ) {
V_52 = & V_15 -> V_27 [ V_22 ] ;
V_47 = & V_52 -> V_47 ;
V_66 = & V_52 -> V_66 ;
if ( V_66 -> V_68 )
F_42 ( L_31 ,
V_47 -> V_49 ,
V_47 -> V_50 ,
V_47 -> V_51 ,
V_66 -> V_68 ,
V_66 -> V_67 ) ;
else
F_42 ( L_32 ,
V_47 -> V_49 ,
V_47 -> V_50 ,
V_47 -> V_51 ,
V_66 -> V_67 ) ;
}
}
bool F_132 ( T_2 V_152 )
{
switch ( V_152 ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
return true ;
default:
F_60 ( L_33 ,
V_152 ) ;
return false ;
}
}
static void F_133 ( T_2 V_152 )
{
if ( ! V_152 )
return;
switch ( V_152 ) {
case V_198 :
F_42 ( L_34 ) ;
break;
case V_199 :
F_42 ( L_35 ) ;
break;
case V_200 :
F_42 ( L_36 ) ;
break;
default:
F_42 ( L_37 ) ;
break;
}
}
static void F_134 ( const struct V_1 * V_15 )
{
struct V_7 * V_11 = F_6 () ;
if ( F_16 ( V_15 -> V_16 ) ) {
if ( V_11 -> V_94 == V_95 ) {
struct V_154 * V_155 ;
V_155 = F_135 ( V_11 -> V_104 ) ;
if ( V_155 ) {
F_42 ( L_38 ,
V_155 -> V_201 [ 0 ] ,
V_155 -> V_201 [ 1 ] ) ;
} else
F_42 ( L_39 ) ;
} else
F_42 ( L_39 ) ;
} else if ( F_13 ( V_15 -> V_16 ) ) {
F_42 ( L_40 ) ;
} else {
if ( F_15 ( V_15 -> V_16 ) )
F_42 ( L_41 ) ;
else {
if ( F_69 ( V_11 ) )
F_42 ( L_42 ,
V_15 -> V_16 [ 0 ] , V_15 -> V_16 [ 1 ] ) ;
else
F_42 ( L_43 ,
V_15 -> V_16 [ 0 ] , V_15 -> V_16 [ 1 ] ) ;
}
}
F_133 ( V_15 -> V_152 ) ;
F_131 ( V_15 ) ;
}
static void F_136 ( const struct V_1 * V_15 )
{
F_42 ( L_44 , V_15 -> V_16 [ 0 ] , V_15 -> V_16 [ 1 ] ) ;
F_131 ( V_15 ) ;
}
static int F_137 ( const struct V_1 * V_15 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_202 = NULL ;
struct V_3 * V_103 ;
struct V_7 * V_11 = F_6 () ;
if ( ! F_44 ( V_15 -> V_16 ) )
return - V_70 ;
if ( F_13 ( V_15 -> V_16 ) ) {
F_11 ( V_15 ) ;
return 0 ;
}
if ( ! F_14 ( V_15 -> V_16 ) && ! F_17 ( V_15 -> V_16 ) &&
! F_15 ( V_15 -> V_16 ) )
return - V_70 ;
if ( V_11 -> V_94 != V_95 ) {
if ( ! F_19 ( V_15 -> V_16 ) )
return - V_203 ;
}
if ( ! F_46 ( V_15 ) ) {
F_138 ( L_45 ) ;
F_136 ( V_15 ) ;
return - V_70 ;
}
V_103 = F_62 ( V_11 -> V_104 ) ;
if ( ! V_103 &&
( V_11 -> V_94 == V_99 ||
V_11 -> V_94 == V_95 ) ) {
F_101 ( & V_163 , 0 ) ;
return - V_204 ;
}
if ( ! V_11 -> V_159 ) {
if ( V_11 -> V_94 != V_99 ) {
F_8 ( false , V_15 ) ;
return 0 ;
}
if ( V_103 -> V_4 )
return - V_203 ;
V_4 = F_22 ( V_15 ) ;
if ( F_63 ( V_4 ) )
return F_64 ( V_4 ) ;
F_10 ( V_103 -> V_4 , V_4 ) ;
F_8 ( false , V_15 ) ;
return 0 ;
}
if ( V_11 -> V_94 != V_95 ) {
V_202 = F_53 ( V_15 , F_1 () ) ;
if ( ! V_202 )
return - V_70 ;
if ( V_11 -> V_94 == V_99 ) {
const struct V_1 * V_171 ;
V_171 = F_3 ( V_103 ) ;
F_10 ( V_103 -> V_4 , V_15 ) ;
F_4 ( V_171 ) ;
} else {
F_31 ( V_15 ) ;
}
V_15 = NULL ;
F_8 ( false , V_202 ) ;
return 0 ;
}
return - V_70 ;
}
int F_34 ( const struct V_1 * V_15 )
{
struct V_7 * V_11 ;
int V_5 ;
V_11 = F_6 () ;
V_5 = F_137 ( V_15 ) ;
if ( V_5 ) {
if ( V_5 == - V_203 )
F_94 () ;
F_31 ( V_15 ) ;
return V_5 ;
}
if ( F_12 ( ! V_11 -> V_159 && V_15 != F_1 () ) )
return - V_70 ;
F_88 ( V_11 -> V_94 ) ;
F_134 ( F_1 () ) ;
F_99 ( V_11 ) ;
F_94 () ;
return 0 ;
}
int F_139 ( struct V_205 * V_41 , struct V_206 * V_178 )
{
struct V_7 * V_11 ;
T_2 V_16 [ 2 ] ;
bool V_207 = false ;
F_116 () ;
V_11 = F_6 () ;
if ( V_11 && ! V_11 -> V_44 ) {
memcpy ( V_16 , V_11 -> V_16 , 2 ) ;
V_207 = true ;
}
F_117 () ;
if ( V_207 )
return F_140 ( V_178 , L_46 ,
V_16 [ 0 ] , V_16 [ 1 ] ) ;
return 0 ;
}
void F_141 ( struct V_3 * V_3 )
{
struct V_7 * V_11 ;
if ( ! F_72 ( V_3 ) )
V_129 ++ ;
V_11 = F_6 () ;
F_87 ( V_3 , V_11 -> V_94 ) ;
}
void F_142 ( struct V_3 * V_3 )
{
struct V_3 * V_103 = NULL ;
struct V_7 * V_11 ;
V_11 = F_6 () ;
if ( ! F_72 ( V_3 ) )
V_129 -- ;
F_4 ( F_3 ( V_3 ) ) ;
F_10 ( V_3 -> V_4 , NULL ) ;
if ( V_11 )
V_103 = F_62 ( V_11 -> V_104 ) ;
if ( ! V_103 || V_103 != V_3 )
return;
V_11 -> V_104 = V_169 ;
V_11 -> V_184 = V_179 ;
}
static void F_143 ( struct V_28 * V_29 )
{
F_60 ( L_47 ) ;
F_26 () ;
F_120 ( true ) ;
F_35 () ;
}
int T_5 F_144 ( void )
{
int V_208 = 0 ;
V_40 = F_145 ( L_48 , 0 , NULL , 0 ) ;
if ( F_63 ( V_40 ) )
return F_64 ( V_40 ) ;
V_40 -> V_41 . type = & V_209 ;
F_146 ( & V_161 ) ;
F_146 ( & V_172 ) ;
F_39 () ;
F_10 ( V_2 , V_12 ) ;
V_19 [ 0 ] = '9' ;
V_19 [ 1 ] = '7' ;
V_208 = F_111 ( V_12 -> V_16 ) ;
if ( V_208 ) {
if ( V_208 == - V_26 )
return V_208 ;
F_138 ( L_49 ) ;
}
if ( ! F_13 ( V_186 ) )
F_112 ( V_186 ,
V_190 ) ;
return 0 ;
}
void F_147 ( void )
{
struct V_7 * V_167 , * V_171 ;
struct V_138 * V_138 , * V_188 ;
F_148 ( & V_164 ) ;
F_149 ( & V_163 ) ;
F_26 () ;
F_8 ( true , NULL ) ;
F_35 () ;
F_150 ( & V_40 -> V_41 , true ) ;
F_151 ( V_40 ) ;
F_107 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_30 ( & V_138 -> V_36 ) ;
F_31 ( V_138 ) ;
}
F_107 (reg_beacon, btmp, &reg_beacon_list, list) {
F_30 ( & V_138 -> V_36 ) ;
F_31 ( V_138 ) ;
}
F_107 (reg_request, tmp, &reg_requests_list, list) {
F_30 ( & V_167 -> V_36 ) ;
F_31 ( V_167 ) ;
}
}
