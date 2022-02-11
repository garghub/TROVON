static inline void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static const struct V_2 * F_3 ( void )
{
return F_4 ( V_3 ,
F_5 ( & V_1 ) ) ;
}
static const struct V_2 * F_6 ( struct V_4 * V_4 )
{
return F_4 ( V_4 -> V_5 ,
F_5 ( & V_1 ) ) ;
}
static void F_7 ( const struct V_2 * V_6 )
{
if ( ! V_6 )
return;
F_8 ( (struct V_2 * ) V_6 , V_7 ) ;
}
static struct V_8 * F_9 ( void )
{
return F_10 ( V_9 ,
F_5 ( & V_1 ) ) ;
}
static void F_11 ( bool V_10 ,
const struct V_2 * V_11 )
{
const struct V_2 * V_6 ;
struct V_8 * V_12 ;
F_1 () ;
V_6 = F_3 () ;
if ( V_6 == V_13 )
V_6 = NULL ;
if ( V_13 == & V_14 )
V_13 = NULL ;
if ( V_6 == & V_14 )
V_6 = NULL ;
F_7 ( V_6 ) ;
F_7 ( V_13 ) ;
V_13 = & V_14 ;
F_12 ( V_3 , V_11 ) ;
if ( ! V_10 )
return;
V_12 = F_9 () ;
if ( V_12 != & V_15 && V_12 )
F_8 ( V_12 , V_7 ) ;
F_12 ( V_9 , & V_15 ) ;
}
static void F_13 ( const struct V_2 * V_16 )
{
struct V_8 * V_12 ;
V_12 = F_9 () ;
F_14 ( ! V_12 ) ;
F_11 ( false , V_16 ) ;
V_13 = V_16 ;
}
bool F_15 ( const char * V_17 )
{
if ( ! V_17 )
return false ;
return V_17 [ 0 ] == '0' && V_17 [ 1 ] == '0' ;
}
static bool F_16 ( const char * V_17 )
{
if ( ! V_17 )
return false ;
return V_17 [ 0 ] && V_17 [ 1 ] ;
}
static bool F_17 ( const char * V_17 )
{
if ( ! V_17 )
return false ;
return V_17 [ 0 ] == '9' && V_17 [ 1 ] == '9' ;
}
static bool F_18 ( const char * V_17 )
{
if ( ! V_17 )
return false ;
return V_17 [ 0 ] == '9' && V_17 [ 1 ] == '8' ;
}
static bool F_19 ( const char * V_17 )
{
if ( ! V_17 )
return false ;
return isalpha ( V_17 [ 0 ] ) && isalpha ( V_17 [ 1 ] ) ;
}
static bool F_20 ( const char * V_18 , const char * V_19 )
{
if ( ! V_18 || ! V_19 )
return false ;
return V_18 [ 0 ] == V_19 [ 0 ] && V_18 [ 1 ] == V_19 [ 1 ] ;
}
static bool F_21 ( const char * V_17 )
{
const struct V_2 * V_6 = F_3 () ;
if ( ! V_6 )
return true ;
return ! F_20 ( V_6 -> V_17 , V_17 ) ;
}
static bool F_22 ( void )
{
if ( V_20 [ 0 ] == '9' && V_20 [ 1 ] == '7' )
return false ;
if ( F_23 ( ! F_15 ( V_20 ) && ! F_19 ( V_20 ) ,
L_1 ,
V_20 [ 0 ] , V_20 [ 1 ] ) )
return false ;
return true ;
}
static const struct V_2 *
F_24 ( const struct V_2 * V_21 )
{
struct V_2 * V_5 ;
int V_22 ;
unsigned int V_23 ;
V_22 =
sizeof( struct V_2 ) +
V_21 -> V_24 * sizeof( struct V_25 ) ;
V_5 = F_25 ( V_22 , V_26 ) ;
if ( ! V_5 )
return F_26 ( - V_27 ) ;
memcpy ( V_5 , V_21 , sizeof( struct V_2 ) ) ;
for ( V_23 = 0 ; V_23 < V_21 -> V_24 ; V_23 ++ )
memcpy ( & V_5 -> V_28 [ V_23 ] , & V_21 -> V_28 [ V_23 ] ,
sizeof( struct V_25 ) ) ;
return V_5 ;
}
static void F_27 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
const struct V_2 * V_33 , * V_34 = NULL ;
int V_23 ;
F_28 ( & V_35 ) ;
F_28 ( & V_36 ) ;
while ( ! F_29 ( & V_37 ) ) {
V_32 = F_30 ( & V_37 ,
struct V_31 ,
V_38 ) ;
F_31 ( & V_32 -> V_38 ) ;
for ( V_23 = 0 ; V_23 < V_39 ; V_23 ++ ) {
V_33 = V_40 [ V_23 ] ;
if ( F_20 ( V_32 -> V_17 , V_33 -> V_17 ) ) {
V_34 = F_24 ( V_33 ) ;
break;
}
}
F_32 ( V_32 ) ;
}
F_33 ( & V_36 ) ;
if ( ! F_34 ( V_34 ) )
F_35 ( V_34 ) ;
F_33 ( & V_35 ) ;
}
static void F_36 ( const char * V_17 )
{
struct V_31 * V_32 ;
if ( ! V_17 )
return;
V_32 = F_25 ( sizeof( struct V_31 ) , V_26 ) ;
if ( ! V_32 )
return;
memcpy ( V_32 -> V_17 , V_17 , 2 ) ;
F_28 ( & V_36 ) ;
F_37 ( & V_32 -> V_38 , & V_37 ) ;
F_33 ( & V_36 ) ;
F_38 ( & V_41 ) ;
}
static void F_39 ( void )
{
F_40 ( ! V_39 , L_2 ) ;
}
static inline void F_39 ( void ) {}
static inline void F_36 ( const char * V_17 ) {}
static int F_41 ( const char * V_17 )
{
if ( ! F_15 ( ( char * ) V_17 ) )
F_42 ( L_3 ,
V_17 [ 0 ] , V_17 [ 1 ] ) ;
else
F_42 ( L_4 ) ;
F_36 ( V_17 ) ;
return F_43 ( & V_42 -> V_43 . V_44 , V_45 ) ;
}
static bool F_44 ( const char * V_17 )
{
struct V_8 * V_12 = F_9 () ;
if ( ! V_12 || V_12 -> V_46 )
return false ;
return F_20 ( V_12 -> V_17 , V_17 ) ;
}
static bool F_45 ( const struct V_25 * V_47 )
{
const struct V_48 * V_49 = & V_47 -> V_49 ;
T_1 V_50 ;
if ( V_49 -> V_51 <= 0 || V_49 -> V_52 <= 0 )
return false ;
if ( V_49 -> V_51 > V_49 -> V_52 )
return false ;
V_50 = V_49 -> V_52 - V_49 -> V_51 ;
if ( V_49 -> V_52 <= V_49 -> V_51 ||
V_49 -> V_53 > V_50 )
return false ;
return true ;
}
static bool F_46 ( const struct V_2 * V_16 )
{
const struct V_25 * V_54 = NULL ;
unsigned int V_23 ;
if ( ! V_16 -> V_24 )
return false ;
if ( F_14 ( V_16 -> V_24 > V_55 ) )
return false ;
for ( V_23 = 0 ; V_23 < V_16 -> V_24 ; V_23 ++ ) {
V_54 = & V_16 -> V_28 [ V_23 ] ;
if ( ! F_45 ( V_54 ) )
return false ;
}
return true ;
}
static bool F_47 ( const struct V_48 * V_49 ,
T_1 V_56 , T_1 V_57 )
{
T_1 V_51 , V_52 ;
V_51 = V_56 - ( V_57 / 2 ) ;
V_52 = V_56 + ( V_57 / 2 ) ;
if ( V_51 >= V_49 -> V_51 &&
V_52 <= V_49 -> V_52 )
return true ;
return false ;
}
static bool F_48 ( const struct V_48 * V_49 ,
T_1 V_58 )
{
#define F_49 1000000
T_1 V_59 = V_58 > 45 * F_49 ?
10 * F_49 : 2 * F_49 ;
if ( abs ( V_58 - V_49 -> V_51 ) <= V_59 )
return true ;
if ( abs ( V_58 - V_49 -> V_52 ) <= V_59 )
return true ;
return false ;
#undef F_49
}
static int F_50 ( const struct V_25 * V_60 ,
const struct V_25 * V_61 ,
struct V_25 * V_62 )
{
const struct V_48 * V_63 , * V_64 ;
struct V_48 * V_49 ;
const struct V_65 * V_66 , * V_67 ;
struct V_65 * V_68 ;
T_1 V_50 ;
V_63 = & V_60 -> V_49 ;
V_64 = & V_61 -> V_49 ;
V_49 = & V_62 -> V_49 ;
V_66 = & V_60 -> V_68 ;
V_67 = & V_61 -> V_68 ;
V_68 = & V_62 -> V_68 ;
V_49 -> V_51 = F_51 ( V_63 -> V_51 ,
V_64 -> V_51 ) ;
V_49 -> V_52 = F_52 ( V_63 -> V_52 ,
V_64 -> V_52 ) ;
V_49 -> V_53 = F_52 ( V_63 -> V_53 ,
V_64 -> V_53 ) ;
V_50 = V_49 -> V_52 - V_49 -> V_51 ;
if ( V_49 -> V_53 > V_50 )
V_49 -> V_53 = V_50 ;
V_68 -> V_69 = F_52 ( V_66 -> V_69 ,
V_67 -> V_69 ) ;
V_68 -> V_70 = F_52 ( V_66 -> V_70 ,
V_67 -> V_70 ) ;
V_62 -> V_71 = V_60 -> V_71 | V_61 -> V_71 ;
if ( ! F_45 ( V_62 ) )
return - V_72 ;
return 0 ;
}
static struct V_2 *
F_53 ( const struct V_2 * V_73 ,
const struct V_2 * V_74 )
{
int V_6 , V_22 ;
unsigned int V_75 , V_76 ;
unsigned int V_77 = 0 , V_78 = 0 ;
const struct V_25 * V_60 , * V_61 ;
struct V_25 * V_62 ;
struct V_2 * V_16 ;
struct V_25 V_79 ;
if ( ! V_73 || ! V_74 )
return NULL ;
for ( V_75 = 0 ; V_75 < V_73 -> V_24 ; V_75 ++ ) {
V_60 = & V_73 -> V_28 [ V_75 ] ;
for ( V_76 = 0 ; V_76 < V_74 -> V_24 ; V_76 ++ ) {
V_61 = & V_74 -> V_28 [ V_76 ] ;
if ( ! F_50 ( V_60 , V_61 , & V_79 ) )
V_77 ++ ;
}
}
if ( ! V_77 )
return NULL ;
V_22 = sizeof( struct V_2 ) +
V_77 * sizeof( struct V_25 ) ;
V_16 = F_25 ( V_22 , V_26 ) ;
if ( ! V_16 )
return NULL ;
for ( V_75 = 0 ; V_75 < V_73 -> V_24 && V_78 < V_77 ; V_75 ++ ) {
V_60 = & V_73 -> V_28 [ V_75 ] ;
for ( V_76 = 0 ; V_76 < V_74 -> V_24 && V_78 < V_77 ; V_76 ++ ) {
V_61 = & V_74 -> V_28 [ V_76 ] ;
V_62 = & V_16 -> V_28 [ V_78 ] ;
V_6 = F_50 ( V_60 , V_61 , V_62 ) ;
if ( V_6 )
continue;
V_78 ++ ;
}
}
if ( V_78 != V_77 ) {
F_32 ( V_16 ) ;
return NULL ;
}
V_16 -> V_24 = V_77 ;
V_16 -> V_17 [ 0 ] = '9' ;
V_16 -> V_17 [ 1 ] = '8' ;
return V_16 ;
}
static T_1 F_54 ( T_1 V_80 )
{
T_1 V_81 = 0 ;
if ( V_80 & V_82 )
V_81 |= V_83 ;
if ( V_80 & V_84 )
V_81 |= V_85 ;
if ( V_80 & V_86 )
V_81 |= V_87 ;
if ( V_80 & V_88 )
V_81 |= V_89 ;
return V_81 ;
}
static const struct V_25 *
F_55 ( struct V_4 * V_4 , T_1 V_90 ,
const struct V_2 * V_5 )
{
int V_23 ;
bool V_91 = false ;
bool V_92 = false ;
if ( ! V_5 )
return F_26 ( - V_72 ) ;
for ( V_23 = 0 ; V_23 < V_5 -> V_24 ; V_23 ++ ) {
const struct V_25 * V_93 ;
const struct V_48 * V_94 = NULL ;
V_93 = & V_5 -> V_28 [ V_23 ] ;
V_94 = & V_93 -> V_49 ;
if ( ! V_91 )
V_91 = F_48 ( V_94 , V_90 ) ;
V_92 = F_47 ( V_94 , V_90 , F_56 ( 20 ) ) ;
if ( V_91 && V_92 )
return V_93 ;
}
if ( ! V_91 )
return F_26 ( - V_95 ) ;
return F_26 ( - V_72 ) ;
}
const struct V_25 * F_57 ( struct V_4 * V_4 ,
T_1 V_90 )
{
const struct V_2 * V_5 ;
struct V_8 * V_12 = F_9 () ;
if ( V_12 -> V_96 != V_97 &&
V_12 -> V_96 != V_98 &&
V_4 -> V_5 )
V_5 = F_6 ( V_4 ) ;
else
V_5 = F_3 () ;
return F_55 ( V_4 , V_90 , V_5 ) ;
}
static const char * F_58 ( enum V_99 V_96 )
{
switch ( V_96 ) {
case V_100 :
return L_5 ;
case V_98 :
return L_6 ;
case V_101 :
return L_7 ;
case V_97 :
return L_8 ;
default:
F_14 ( 1 ) ;
return L_9 ;
}
}
static void F_59 ( struct V_102 * V_103 ,
const struct V_25 * V_54 )
{
const struct V_65 * V_68 ;
const struct V_48 * V_49 ;
char V_70 [ 32 ] ;
V_68 = & V_54 -> V_68 ;
V_49 = & V_54 -> V_49 ;
if ( ! V_68 -> V_70 )
snprintf ( V_70 , 32 , L_10 ) ;
else
snprintf ( V_70 , 32 , L_11 , V_68 -> V_70 ) ;
F_60 ( L_12 ,
V_103 -> V_90 ) ;
F_60 ( L_13 ,
V_49 -> V_51 , V_49 -> V_52 ,
V_49 -> V_53 , V_70 ,
V_68 -> V_69 ) ;
}
static void F_59 ( struct V_102 * V_103 ,
const struct V_25 * V_54 )
{
return;
}
static void F_61 ( struct V_4 * V_4 ,
enum V_99 V_96 ,
struct V_102 * V_103 )
{
T_1 V_71 , V_104 = 0 ;
const struct V_25 * V_54 = NULL ;
const struct V_65 * V_68 = NULL ;
const struct V_48 * V_49 = NULL ;
struct V_4 * V_105 = NULL ;
struct V_8 * V_12 = F_9 () ;
V_105 = F_62 ( V_12 -> V_106 ) ;
V_71 = V_103 -> V_107 ;
V_54 = F_57 ( V_4 , F_56 ( V_103 -> V_90 ) ) ;
if ( F_63 ( V_54 ) ) {
if ( V_96 == V_97 &&
F_64 ( V_54 ) == - V_95 )
return;
F_60 ( L_14 , V_103 -> V_90 ) ;
V_103 -> V_71 |= V_108 ;
return;
}
F_59 ( V_103 , V_54 ) ;
V_68 = & V_54 -> V_68 ;
V_49 = & V_54 -> V_49 ;
if ( V_49 -> V_53 < F_56 ( 40 ) )
V_104 = V_109 ;
if ( V_49 -> V_53 < F_56 ( 80 ) )
V_104 |= V_110 ;
if ( V_49 -> V_53 < F_56 ( 160 ) )
V_104 |= V_111 ;
if ( V_12 -> V_96 == V_101 &&
V_105 && V_105 == V_4 &&
V_105 -> V_71 & V_112 ) {
V_103 -> V_71 = V_103 -> V_107 =
F_54 ( V_54 -> V_71 ) | V_104 ;
V_103 -> V_70 = V_103 -> V_113 =
( int ) F_65 ( V_68 -> V_70 ) ;
V_103 -> V_114 = V_103 -> V_115 = V_103 -> V_116 =
( int ) F_66 ( V_68 -> V_69 ) ;
return;
}
V_103 -> V_117 = V_118 ;
V_103 -> V_119 = V_120 ;
V_103 -> V_121 = false ;
V_103 -> V_71 = V_71 | V_104 | F_54 ( V_54 -> V_71 ) ;
V_103 -> V_70 =
F_67 ( int , V_103 -> V_113 ,
F_65 ( V_68 -> V_70 ) ) ;
V_103 -> V_114 = ( int ) F_66 ( V_68 -> V_69 ) ;
if ( V_103 -> V_116 ) {
if ( V_96 == V_97 &&
V_4 -> V_71 & V_122 &&
V_4 -> V_71 & V_112 )
V_103 -> V_115 = V_103 -> V_114 ;
else
V_103 -> V_115 = F_52 ( V_103 -> V_116 ,
V_103 -> V_114 ) ;
} else
V_103 -> V_115 = V_103 -> V_114 ;
}
static void F_68 ( struct V_4 * V_4 ,
enum V_99 V_96 ,
struct V_123 * V_124 )
{
unsigned int V_23 ;
if ( ! V_124 )
return;
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ )
F_61 ( V_4 , V_96 , & V_124 -> V_126 [ V_23 ] ) ;
}
static bool F_69 ( struct V_8 * V_32 )
{
if ( V_32 -> V_96 != V_98 )
return false ;
return V_32 -> V_127 == V_128 ;
}
bool F_70 ( void )
{
bool V_129 ;
F_28 ( & V_1 ) ;
V_129 = F_69 ( F_9 () ) ;
F_33 ( & V_1 ) ;
return V_129 ;
}
static enum V_130
F_71 ( struct V_8 * V_131 )
{
struct V_8 * V_12 = F_9 () ;
if ( ! V_132 )
return V_133 ;
if ( F_69 ( V_12 ) &&
! F_21 ( V_131 -> V_17 ) )
return V_134 ;
return V_135 ;
}
static bool F_72 ( struct V_4 * V_4 )
{
return ! ( V_4 -> V_136 & V_137 ) ;
}
static int F_71 ( struct V_8 * V_131 )
{
return V_133 ;
}
static bool F_72 ( struct V_4 * V_4 )
{
return true ;
}
static bool F_73 ( struct V_4 * V_4 ,
enum V_99 V_96 )
{
struct V_8 * V_12 = F_9 () ;
if ( ! V_12 ) {
F_60 ( L_15 ,
F_58 ( V_96 ) ) ;
return true ;
}
if ( V_96 == V_100 &&
V_4 -> V_71 & V_122 ) {
F_60 ( L_16 ,
F_58 ( V_96 ) ) ;
return true ;
}
if ( V_4 -> V_71 & V_112 && ! V_4 -> V_5 &&
V_96 != V_97 &&
! F_15 ( V_12 -> V_17 ) ) {
F_60 ( L_17 ,
F_58 ( V_96 ) ) ;
return true ;
}
if ( F_69 ( V_12 ) )
return F_72 ( V_4 ) ;
return false ;
}
static bool F_74 ( struct V_4 * V_4 )
{
const struct V_2 * V_138 = F_3 () ;
const struct V_2 * V_139 = F_6 ( V_4 ) ;
struct V_8 * V_12 = F_9 () ;
if ( F_15 ( V_138 -> V_17 ) || ( V_139 && F_15 ( V_139 -> V_17 ) ) )
return true ;
if ( V_12 && V_12 -> V_96 != V_97 &&
V_4 -> V_71 & V_122 )
return true ;
return false ;
}
static void F_75 ( struct V_4 * V_4 , unsigned int V_140 ,
struct V_141 * V_141 )
{
struct V_123 * V_124 ;
struct V_102 * V_103 ;
bool V_142 = false ;
struct V_102 V_143 ;
V_124 = V_4 -> V_144 [ V_141 -> V_103 . V_145 ] ;
V_103 = & V_124 -> V_126 [ V_140 ] ;
if ( F_76 ( V_103 -> V_90 != V_141 -> V_103 . V_90 ) )
return;
if ( V_103 -> V_121 )
return;
V_103 -> V_121 = true ;
if ( ! F_74 ( V_4 ) )
return;
if ( V_4 -> V_71 & V_146 )
return;
V_143 . V_90 = V_103 -> V_90 ;
V_143 . V_71 = V_103 -> V_71 ;
if ( V_103 -> V_71 & V_83 ) {
V_103 -> V_71 &= ~ V_83 ;
V_142 = true ;
}
if ( V_103 -> V_71 & V_85 ) {
V_103 -> V_71 &= ~ V_85 ;
V_142 = true ;
}
if ( V_142 )
F_77 ( V_4 , & V_143 , V_103 ) ;
}
static void F_78 ( struct V_4 * V_4 ,
struct V_141 * V_141 )
{
unsigned int V_23 ;
struct V_123 * V_124 ;
if ( ! V_4 -> V_144 [ V_141 -> V_103 . V_145 ] )
return;
V_124 = V_4 -> V_144 [ V_141 -> V_103 . V_145 ] ;
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ )
F_75 ( V_4 , V_23 , V_141 ) ;
}
static void F_79 ( struct V_4 * V_4 )
{
unsigned int V_23 ;
struct V_123 * V_124 ;
struct V_141 * V_141 ;
F_80 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_4 -> V_144 [ V_141 -> V_103 . V_145 ] )
continue;
V_124 = V_4 -> V_144 [ V_141 -> V_103 . V_145 ] ;
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ )
F_75 ( V_4 , V_23 , V_141 ) ;
}
}
static void F_81 ( struct V_4 * V_4 )
{
if ( ! V_9 )
return;
F_79 ( V_4 ) ;
}
static bool F_82 ( struct V_102 * V_103 )
{
if ( ! V_103 )
return false ;
if ( V_103 -> V_71 & V_108 )
return false ;
if ( ( V_103 -> V_71 & V_109 ) == V_109 )
return false ;
return true ;
}
static void F_83 ( struct V_4 * V_4 ,
struct V_102 * V_147 )
{
struct V_123 * V_124 = V_4 -> V_144 [ V_147 -> V_145 ] ;
struct V_102 * V_148 = NULL , * V_149 = NULL ;
unsigned int V_23 ;
if ( ! F_82 ( V_147 ) ) {
V_147 -> V_71 |= V_109 ;
return;
}
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ ) {
struct V_102 * V_150 = & V_124 -> V_126 [ V_23 ] ;
if ( V_150 -> V_90 == ( V_147 -> V_90 - 20 ) )
V_148 = V_150 ;
if ( V_150 -> V_90 == ( V_147 -> V_90 + 20 ) )
V_149 = V_150 ;
}
if ( ! F_82 ( V_148 ) )
V_147 -> V_71 |= V_151 ;
else
V_147 -> V_71 &= ~ V_151 ;
if ( ! F_82 ( V_149 ) )
V_147 -> V_71 |= V_152 ;
else
V_147 -> V_71 &= ~ V_152 ;
}
static void F_84 ( struct V_4 * V_4 ,
struct V_123 * V_124 )
{
unsigned int V_23 ;
if ( ! V_124 )
return;
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ )
F_83 ( V_4 , & V_124 -> V_126 [ V_23 ] ) ;
}
static void F_85 ( struct V_4 * V_4 )
{
enum V_153 V_145 ;
if ( ! V_4 )
return;
for ( V_145 = 0 ; V_145 < V_154 ; V_145 ++ )
F_84 ( V_4 , V_4 -> V_144 [ V_145 ] ) ;
}
static void F_86 ( struct V_4 * V_4 ,
enum V_99 V_96 )
{
enum V_153 V_145 ;
struct V_8 * V_12 = F_9 () ;
if ( F_73 ( V_4 , V_96 ) )
return;
V_12 -> V_155 = F_3 () -> V_155 ;
for ( V_145 = 0 ; V_145 < V_154 ; V_145 ++ )
F_68 ( V_4 , V_96 , V_4 -> V_144 [ V_145 ] ) ;
F_81 ( V_4 ) ;
F_85 ( V_4 ) ;
if ( V_4 -> V_156 )
V_4 -> V_156 ( V_4 , V_12 ) ;
}
static void F_87 ( enum V_99 V_96 )
{
struct V_157 * V_158 ;
struct V_4 * V_4 ;
F_88 () ;
F_80 (rdev, &cfg80211_rdev_list, list) {
V_4 = & V_158 -> V_4 ;
F_86 ( V_4 , V_96 ) ;
if ( V_96 == V_100 &&
V_4 -> V_71 & V_122 &&
V_4 -> V_156 )
V_4 -> V_156 ( V_4 , F_9 () ) ;
}
}
static void F_89 ( struct V_4 * V_4 ,
struct V_102 * V_103 ,
const struct V_2 * V_5 )
{
T_1 V_104 = 0 ;
const struct V_25 * V_54 = NULL ;
const struct V_65 * V_68 = NULL ;
const struct V_48 * V_49 = NULL ;
V_54 = F_55 ( V_4 , F_56 ( V_103 -> V_90 ) ,
V_5 ) ;
if ( F_63 ( V_54 ) ) {
F_60 ( L_18 ,
V_103 -> V_90 ) ;
V_103 -> V_71 = V_108 ;
return;
}
F_59 ( V_103 , V_54 ) ;
V_68 = & V_54 -> V_68 ;
V_49 = & V_54 -> V_49 ;
if ( V_49 -> V_53 < F_56 ( 40 ) )
V_104 = V_109 ;
if ( V_49 -> V_53 < F_56 ( 80 ) )
V_104 |= V_110 ;
if ( V_49 -> V_53 < F_56 ( 160 ) )
V_104 |= V_111 ;
V_103 -> V_71 |= F_54 ( V_54 -> V_71 ) | V_104 ;
V_103 -> V_70 = ( int ) F_65 ( V_68 -> V_70 ) ;
V_103 -> V_114 = V_103 -> V_115 =
( int ) F_66 ( V_68 -> V_69 ) ;
}
static void F_90 ( struct V_4 * V_4 ,
struct V_123 * V_124 ,
const struct V_2 * V_5 )
{
unsigned int V_23 ;
if ( ! V_124 )
return;
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ )
F_89 ( V_4 , & V_124 -> V_126 [ V_23 ] , V_5 ) ;
}
void F_91 ( struct V_4 * V_4 ,
const struct V_2 * V_5 )
{
enum V_153 V_145 ;
unsigned int V_159 = 0 ;
for ( V_145 = 0 ; V_145 < V_154 ; V_145 ++ ) {
if ( ! V_4 -> V_144 [ V_145 ] )
continue;
F_90 ( V_4 , V_4 -> V_144 [ V_145 ] , V_5 ) ;
V_159 ++ ;
}
F_14 ( ! V_159 ) ;
}
static enum V_130
F_92 ( struct V_4 * V_4 ,
struct V_8 * V_131 )
{
struct V_4 * V_160 = NULL ;
struct V_8 * V_12 = F_9 () ;
if ( ! V_12 )
return V_135 ;
switch ( V_131 -> V_96 ) {
case V_100 :
return V_135 ;
case V_97 :
if ( F_69 ( V_12 ) ) {
if ( F_21 ( V_131 -> V_17 ) )
return V_133 ;
return V_134 ;
}
V_160 = F_62 ( V_12 -> V_106 ) ;
if ( F_93 ( ! F_19 ( V_131 -> V_17 ) ) )
return - V_72 ;
if ( V_12 -> V_96 == V_97 ) {
if ( V_160 != V_4 ) {
if ( F_21 ( V_131 -> V_17 ) )
return V_133 ;
return V_134 ;
}
if ( F_14 ( F_21 ( V_131 -> V_17 ) ) )
return V_135 ;
return V_134 ;
}
return 0 ;
case V_101 :
if ( V_12 -> V_96 == V_100 ) {
if ( F_21 ( V_131 -> V_17 ) )
return V_135 ;
return V_134 ;
}
if ( V_12 -> V_96 == V_101 &&
! F_21 ( V_131 -> V_17 ) )
return V_134 ;
return V_161 ;
case V_98 :
if ( F_69 ( V_131 ) )
return F_71 ( V_131 ) ;
if ( F_69 ( V_12 ) )
return V_133 ;
if ( V_12 -> V_96 == V_97 )
return V_161 ;
if ( V_12 -> V_96 == V_98 &&
V_12 -> V_162 )
return V_133 ;
if ( ( V_12 -> V_96 == V_100 ||
V_12 -> V_96 == V_101 ||
V_12 -> V_96 == V_98 ) &&
F_21 ( V_12 -> V_17 ) )
return V_133 ;
if ( ! F_21 ( V_131 -> V_17 ) )
return V_134 ;
return V_135 ;
}
return V_133 ;
}
static void F_94 ( void )
{
bool V_163 = false ;
struct V_8 * V_12 = F_9 () ;
V_12 -> V_46 = true ;
F_95 ( & V_164 ) ;
if ( ! F_29 ( & V_165 ) )
V_163 = true ;
F_96 ( & V_164 ) ;
if ( V_12 -> V_96 == V_98 )
F_97 ( & V_166 ) ;
if ( V_163 )
F_38 ( & V_167 ) ;
}
static enum V_130
F_98 ( struct V_4 * V_4 ,
struct V_8 * V_131 )
{
const struct V_2 * V_5 ;
bool V_162 = false ;
enum V_130 V_168 ;
struct V_8 * V_12 ;
V_168 = F_92 ( V_4 , V_131 ) ;
switch ( V_168 ) {
case V_161 :
if ( V_131 -> V_96 ==
V_101 ) {
V_5 = F_24 ( F_3 () ) ;
if ( F_63 ( V_5 ) ) {
F_32 ( V_131 ) ;
return F_64 ( V_5 ) ;
}
F_12 ( V_4 -> V_5 , V_5 ) ;
}
V_162 = true ;
break;
case V_135 :
break;
default:
if ( V_168 == V_134 &&
V_131 -> V_96 == V_101 ) {
V_5 = F_24 ( F_3 () ) ;
if ( F_63 ( V_5 ) ) {
F_32 ( V_131 ) ;
return V_133 ;
}
V_168 = V_134 ;
F_12 ( V_4 -> V_5 , V_5 ) ;
goto V_169;
}
F_32 ( V_131 ) ;
return V_168 ;
}
V_169:
V_12 = F_9 () ;
if ( V_12 != & V_15 && V_12 )
F_8 ( V_12 , V_7 ) ;
V_131 -> V_162 = V_162 ;
V_131 -> V_46 = false ;
F_12 ( V_9 , V_131 ) ;
V_12 = V_131 ;
V_131 = NULL ;
if ( V_12 -> V_96 == V_98 ) {
V_20 [ 0 ] = V_12 -> V_17 [ 0 ] ;
V_20 [ 1 ] = V_12 -> V_17 [ 1 ] ;
}
if ( V_168 != V_135 && V_168 != V_161 ) {
if ( V_168 == V_134 ) {
F_99 ( V_12 ) ;
F_94 () ;
}
return V_168 ;
}
if ( F_41 ( V_12 -> V_17 ) )
return V_133 ;
return V_135 ;
}
static void F_100 ( struct V_8 * V_170 ,
enum V_99 V_171 )
{
struct V_4 * V_4 = NULL ;
if ( F_14 ( ! V_170 -> V_17 ) )
return;
if ( V_170 -> V_106 != V_172 )
V_4 = F_62 ( V_170 -> V_106 ) ;
if ( V_171 == V_101 && ! V_4 ) {
F_32 ( V_170 ) ;
return;
}
switch ( F_98 ( V_4 , V_170 ) ) {
case V_134 :
if ( V_4 && V_4 -> V_71 & V_112 )
F_86 ( V_4 , V_171 ) ;
break;
default:
if ( V_171 == V_98 )
F_101 ( & V_166 ,
F_102 ( 3142 ) ) ;
break;
}
}
static void F_103 ( void )
{
struct V_8 * V_170 , * V_12 ;
F_28 ( & V_35 ) ;
F_28 ( & V_1 ) ;
V_12 = F_9 () ;
if ( V_12 && ! V_12 -> V_46 ) {
F_60 ( L_19 ) ;
goto V_173;
}
F_95 ( & V_164 ) ;
if ( F_29 ( & V_165 ) ) {
F_96 ( & V_164 ) ;
goto V_173;
}
V_170 = F_30 ( & V_165 ,
struct V_8 ,
V_38 ) ;
F_104 ( & V_170 -> V_38 ) ;
F_96 ( & V_164 ) ;
F_100 ( V_170 , V_170 -> V_96 ) ;
V_173:
F_33 ( & V_1 ) ;
F_33 ( & V_35 ) ;
}
static void F_105 ( void )
{
struct V_157 * V_158 ;
struct V_141 * V_174 , * V_175 ;
F_28 ( & V_35 ) ;
F_28 ( & V_1 ) ;
F_106 ( & V_176 ) ;
F_107 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_104 ( & V_174 -> V_38 ) ;
F_80 (rdev, &cfg80211_rdev_list, list)
F_78 ( & V_158 -> V_4 , V_174 ) ;
F_37 ( & V_174 -> V_38 , & V_177 ) ;
}
F_108 ( & V_176 ) ;
F_33 ( & V_1 ) ;
F_33 ( & V_35 ) ;
}
static void F_109 ( struct V_29 * V_30 )
{
F_103 () ;
F_105 () ;
}
static void F_110 ( struct V_8 * V_32 )
{
V_32 -> V_17 [ 0 ] = toupper ( V_32 -> V_17 [ 0 ] ) ;
V_32 -> V_17 [ 1 ] = toupper ( V_32 -> V_17 [ 1 ] ) ;
F_95 ( & V_164 ) ;
F_37 ( & V_32 -> V_38 , & V_165 ) ;
F_96 ( & V_164 ) ;
F_38 ( & V_167 ) ;
}
static int F_111 ( const char * V_17 )
{
struct V_8 * V_32 ;
V_32 = F_25 ( sizeof( struct V_8 ) , V_26 ) ;
if ( ! V_32 )
return - V_27 ;
V_32 -> V_17 [ 0 ] = V_17 [ 0 ] ;
V_32 -> V_17 [ 1 ] = V_17 [ 1 ] ;
V_32 -> V_96 = V_100 ;
F_110 ( V_32 ) ;
return 0 ;
}
int F_112 ( const char * V_17 ,
enum V_178 V_127 )
{
struct V_8 * V_32 ;
if ( F_14 ( ! V_17 ) )
return - V_72 ;
V_32 = F_25 ( sizeof( struct V_8 ) , V_26 ) ;
if ( ! V_32 )
return - V_27 ;
V_32 -> V_106 = V_172 ;
V_32 -> V_17 [ 0 ] = V_17 [ 0 ] ;
V_32 -> V_17 [ 1 ] = V_17 [ 1 ] ;
V_32 -> V_96 = V_98 ;
V_32 -> V_127 = V_127 ;
F_110 ( V_32 ) ;
return 0 ;
}
int F_113 ( struct V_4 * V_4 , const char * V_17 )
{
struct V_8 * V_32 ;
if ( F_14 ( ! V_17 || ! V_4 ) )
return - V_72 ;
V_32 = F_25 ( sizeof( struct V_8 ) , V_26 ) ;
if ( ! V_32 )
return - V_27 ;
V_32 -> V_106 = F_114 ( V_4 ) ;
V_32 -> V_17 [ 0 ] = V_17 [ 0 ] ;
V_32 -> V_17 [ 1 ] = V_17 [ 1 ] ;
V_32 -> V_96 = V_101 ;
F_110 ( V_32 ) ;
return 0 ;
}
void F_115 ( struct V_4 * V_4 , enum V_153 V_145 ,
const T_2 * V_179 , T_2 V_180 )
{
char V_17 [ 2 ] ;
enum V_181 V_182 = V_183 ;
struct V_8 * V_32 , * V_12 ;
F_28 ( & V_1 ) ;
V_12 = F_9 () ;
if ( F_93 ( ! V_12 ) )
goto V_173;
if ( V_180 & 0x01 )
goto V_173;
if ( V_180 < V_184 )
goto V_173;
V_17 [ 0 ] = V_179 [ 0 ] ;
V_17 [ 1 ] = V_179 [ 1 ] ;
if ( V_179 [ 2 ] == 'I' )
V_182 = V_185 ;
else if ( V_179 [ 2 ] == 'O' )
V_182 = V_186 ;
if ( V_12 -> V_96 == V_97 &&
V_12 -> V_106 != V_172 )
goto V_173;
V_32 = F_25 ( sizeof( struct V_8 ) , V_26 ) ;
if ( ! V_32 )
goto V_173;
V_32 -> V_106 = F_114 ( V_4 ) ;
V_32 -> V_17 [ 0 ] = V_17 [ 0 ] ;
V_32 -> V_17 [ 1 ] = V_17 [ 1 ] ;
V_32 -> V_96 = V_97 ;
V_32 -> V_187 = V_182 ;
F_110 ( V_32 ) ;
V_173:
F_33 ( & V_1 ) ;
}
static void F_116 ( char * V_17 , bool V_188 )
{
V_17 [ 0 ] = '9' ;
V_17 [ 1 ] = '7' ;
if ( F_22 () ) {
if ( V_188 ) {
F_60 ( L_20 ) ;
V_20 [ 0 ] = '9' ;
V_20 [ 1 ] = '7' ;
if ( ! F_15 ( V_189 ) ) {
F_60 ( L_21 ,
V_189 [ 0 ] , V_189 [ 1 ] ) ;
V_17 [ 0 ] = V_189 [ 0 ] ;
V_17 [ 1 ] = V_189 [ 1 ] ;
}
} else {
F_60 ( L_22 ,
V_20 [ 0 ] , V_20 [ 1 ] ) ;
V_17 [ 0 ] = V_20 [ 0 ] ;
V_17 [ 1 ] = V_20 [ 1 ] ;
}
} else if ( ! F_15 ( V_189 ) ) {
F_60 ( L_21 ,
V_189 [ 0 ] , V_189 [ 1 ] ) ;
V_17 [ 0 ] = V_189 [ 0 ] ;
V_17 [ 1 ] = V_189 [ 1 ] ;
} else
F_60 ( L_23 ) ;
}
static void F_117 ( struct V_4 * V_4 )
{
struct V_123 * V_124 ;
enum V_153 V_145 ;
struct V_102 * V_103 ;
int V_23 ;
for ( V_145 = 0 ; V_145 < V_154 ; V_145 ++ ) {
V_124 = V_4 -> V_144 [ V_145 ] ;
if ( ! V_124 )
continue;
for ( V_23 = 0 ; V_23 < V_124 -> V_125 ; V_23 ++ ) {
V_103 = & V_124 -> V_126 [ V_23 ] ;
V_103 -> V_71 = V_103 -> V_107 ;
V_103 -> V_70 = V_103 -> V_113 ;
V_103 -> V_115 = V_103 -> V_116 ;
V_103 -> V_121 = false ;
}
}
}
static void F_118 ( bool V_188 )
{
char V_17 [ 2 ] ;
char V_190 [ 2 ] ;
struct V_141 * V_141 , * V_191 ;
struct V_8 * V_170 , * V_175 ;
F_119 ( V_192 ) ;
struct V_157 * V_158 ;
F_28 ( & V_35 ) ;
F_28 ( & V_1 ) ;
F_11 ( true , & V_14 ) ;
F_116 ( V_17 , V_188 ) ;
F_95 ( & V_164 ) ;
F_107 (reg_request, tmp, &reg_requests_list, list) {
if ( V_170 -> V_96 != V_98 )
continue;
F_120 ( & V_170 -> V_38 , & V_192 ) ;
}
F_96 ( & V_164 ) ;
F_106 ( & V_176 ) ;
F_107 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_31 ( & V_141 -> V_38 ) ;
F_32 ( V_141 ) ;
}
F_108 ( & V_176 ) ;
F_107 (reg_beacon, btmp, &reg_beacon_list, list) {
F_31 ( & V_141 -> V_38 ) ;
F_32 ( V_141 ) ;
}
V_190 [ 0 ] = V_13 -> V_17 [ 0 ] ;
V_190 [ 1 ] = V_13 -> V_17 [ 1 ] ;
F_80 (rdev, &cfg80211_rdev_list, list) {
if ( V_158 -> V_4 . V_71 & V_122 )
F_117 ( & V_158 -> V_4 ) ;
}
F_111 ( V_190 ) ;
if ( F_19 ( V_17 ) )
F_112 ( V_20 , V_193 ) ;
F_95 ( & V_164 ) ;
F_121 ( & V_192 , & V_165 ) ;
F_96 ( & V_164 ) ;
F_33 ( & V_1 ) ;
F_33 ( & V_35 ) ;
F_60 ( L_24 ) ;
F_38 ( & V_167 ) ;
}
void F_122 ( void )
{
F_60 ( L_25 ) ;
F_118 ( false ) ;
}
static bool F_123 ( T_3 V_194 )
{
if ( V_194 == F_124 ( 12 , V_195 ) ||
V_194 == F_124 ( 13 , V_195 ) ||
V_194 == F_124 ( 14 , V_195 ) )
return true ;
return false ;
}
static bool F_125 ( struct V_102 * V_196 )
{
struct V_141 * V_174 ;
F_80 (pending_beacon, &reg_pending_beacons, list)
if ( V_196 -> V_90 ==
V_174 -> V_103 . V_90 )
return true ;
return false ;
}
int F_126 ( struct V_4 * V_4 ,
struct V_102 * V_196 ,
T_4 V_197 )
{
struct V_141 * V_141 ;
bool V_198 ;
if ( V_196 -> V_121 ||
V_196 -> V_71 & V_87 ||
( V_196 -> V_145 == V_195 &&
! F_123 ( V_196 -> V_90 ) ) )
return 0 ;
F_106 ( & V_176 ) ;
V_198 = F_125 ( V_196 ) ;
F_108 ( & V_176 ) ;
if ( V_198 )
return 0 ;
V_141 = F_25 ( sizeof( struct V_141 ) , V_197 ) ;
if ( ! V_141 )
return - V_27 ;
F_60 ( L_26 ,
V_196 -> V_90 ,
F_127 ( V_196 -> V_90 ) ,
F_128 ( V_4 ) ) ;
memcpy ( & V_141 -> V_103 , V_196 ,
sizeof( struct V_102 ) ) ;
F_106 ( & V_176 ) ;
F_37 ( & V_141 -> V_38 , & V_199 ) ;
F_108 ( & V_176 ) ;
F_38 ( & V_167 ) ;
return 0 ;
}
static void F_129 ( const struct V_2 * V_16 )
{
unsigned int V_23 ;
const struct V_25 * V_54 = NULL ;
const struct V_48 * V_49 = NULL ;
const struct V_65 * V_68 = NULL ;
F_42 ( L_27 ) ;
for ( V_23 = 0 ; V_23 < V_16 -> V_24 ; V_23 ++ ) {
V_54 = & V_16 -> V_28 [ V_23 ] ;
V_49 = & V_54 -> V_49 ;
V_68 = & V_54 -> V_68 ;
if ( V_68 -> V_70 )
F_42 ( L_28 ,
V_49 -> V_51 ,
V_49 -> V_52 ,
V_49 -> V_53 ,
V_68 -> V_70 ,
V_68 -> V_69 ) ;
else
F_42 ( L_29 ,
V_49 -> V_51 ,
V_49 -> V_52 ,
V_49 -> V_53 ,
V_68 -> V_69 ) ;
}
}
bool F_130 ( T_2 V_155 )
{
switch ( V_155 ) {
case V_200 :
case V_201 :
case V_202 :
case V_203 :
return true ;
default:
F_60 ( L_30 ,
V_155 ) ;
return false ;
}
}
static void F_131 ( T_2 V_155 )
{
if ( ! V_155 )
return;
switch ( V_155 ) {
case V_201 :
F_42 ( L_31 ) ;
break;
case V_202 :
F_42 ( L_32 ) ;
break;
case V_203 :
F_42 ( L_33 ) ;
break;
default:
F_42 ( L_34 ) ;
break;
}
}
static void F_132 ( const struct V_2 * V_16 )
{
struct V_8 * V_12 = F_9 () ;
if ( F_18 ( V_16 -> V_17 ) ) {
if ( V_12 -> V_96 == V_97 ) {
struct V_157 * V_158 ;
V_158 = F_133 ( V_12 -> V_106 ) ;
if ( V_158 ) {
F_42 ( L_35 ,
V_158 -> V_204 [ 0 ] ,
V_158 -> V_204 [ 1 ] ) ;
} else
F_42 ( L_36 ) ;
} else
F_42 ( L_36 ) ;
} else if ( F_15 ( V_16 -> V_17 ) ) {
F_42 ( L_37 ) ;
} else {
if ( F_17 ( V_16 -> V_17 ) )
F_42 ( L_38 ) ;
else {
if ( F_69 ( V_12 ) )
F_42 ( L_39 ,
V_16 -> V_17 [ 0 ] , V_16 -> V_17 [ 1 ] ) ;
else
F_42 ( L_40 ,
V_16 -> V_17 [ 0 ] , V_16 -> V_17 [ 1 ] ) ;
}
}
F_131 ( V_16 -> V_155 ) ;
F_129 ( V_16 ) ;
}
static void F_134 ( const struct V_2 * V_16 )
{
F_42 ( L_41 , V_16 -> V_17 [ 0 ] , V_16 -> V_17 [ 1 ] ) ;
F_129 ( V_16 ) ;
}
static int F_135 ( const struct V_2 * V_16 )
{
const struct V_2 * V_5 ;
const struct V_2 * V_205 = NULL ;
struct V_4 * V_105 ;
struct V_8 * V_12 = F_9 () ;
if ( ! F_44 ( V_16 -> V_17 ) )
return - V_72 ;
if ( F_15 ( V_16 -> V_17 ) ) {
F_13 ( V_16 ) ;
return 0 ;
}
if ( ! F_16 ( V_16 -> V_17 ) && ! F_19 ( V_16 -> V_17 ) &&
! F_17 ( V_16 -> V_17 ) )
return - V_72 ;
if ( V_12 -> V_96 != V_97 ) {
if ( ! F_21 ( V_16 -> V_17 ) )
return - V_206 ;
}
if ( ! F_46 ( V_16 ) ) {
F_136 ( L_42 ) ;
F_134 ( V_16 ) ;
return - V_72 ;
}
V_105 = F_62 ( V_12 -> V_106 ) ;
if ( ! V_105 &&
( V_12 -> V_96 == V_101 ||
V_12 -> V_96 == V_97 ) ) {
F_101 ( & V_166 , 0 ) ;
return - V_207 ;
}
if ( ! V_12 -> V_162 ) {
if ( V_12 -> V_96 != V_101 ) {
F_11 ( false , V_16 ) ;
return 0 ;
}
if ( V_105 -> V_5 )
return - V_206 ;
V_5 = F_24 ( V_16 ) ;
if ( F_63 ( V_5 ) )
return F_64 ( V_5 ) ;
F_12 ( V_105 -> V_5 , V_5 ) ;
F_11 ( false , V_16 ) ;
return 0 ;
}
if ( V_12 -> V_96 != V_97 ) {
V_205 = F_53 ( V_16 , F_3 () ) ;
if ( ! V_205 )
return - V_72 ;
if ( V_12 -> V_96 == V_101 ) {
const struct V_2 * V_175 ;
V_175 = F_6 ( V_105 ) ;
F_12 ( V_105 -> V_5 , V_16 ) ;
F_7 ( V_175 ) ;
} else {
F_32 ( V_16 ) ;
}
V_16 = NULL ;
F_11 ( false , V_205 ) ;
return 0 ;
}
return - V_72 ;
}
int F_35 ( const struct V_2 * V_16 )
{
struct V_8 * V_12 ;
int V_6 ;
F_28 ( & V_1 ) ;
V_12 = F_9 () ;
V_6 = F_135 ( V_16 ) ;
if ( V_6 ) {
if ( V_6 == - V_206 )
F_94 () ;
F_32 ( V_16 ) ;
goto V_173;
}
if ( F_14 ( ! V_12 -> V_162 && V_16 != F_3 () ) ) {
V_6 = - V_72 ;
goto V_173;
}
F_87 ( V_12 -> V_96 ) ;
F_132 ( F_3 () ) ;
F_99 ( V_12 ) ;
F_94 () ;
V_173:
F_33 ( & V_1 ) ;
return V_6 ;
}
int F_137 ( struct V_208 * V_43 , struct V_209 * V_182 )
{
struct V_8 * V_12 ;
T_2 V_17 [ 2 ] ;
bool V_210 = false ;
F_138 () ;
V_12 = F_9 () ;
if ( V_12 && ! V_12 -> V_46 ) {
memcpy ( V_17 , V_12 -> V_17 , 2 ) ;
V_210 = true ;
}
F_139 () ;
if ( V_210 )
return F_140 ( V_182 , L_43 ,
V_17 [ 0 ] , V_17 [ 1 ] ) ;
return 0 ;
}
void F_141 ( struct V_4 * V_4 )
{
F_28 ( & V_1 ) ;
if ( ! F_72 ( V_4 ) )
V_132 ++ ;
F_86 ( V_4 , V_100 ) ;
F_33 ( & V_1 ) ;
}
void F_142 ( struct V_4 * V_4 )
{
struct V_4 * V_105 = NULL ;
struct V_8 * V_12 ;
F_28 ( & V_1 ) ;
V_12 = F_9 () ;
if ( ! F_72 ( V_4 ) )
V_132 -- ;
F_7 ( F_6 ( V_4 ) ) ;
F_12 ( V_4 -> V_5 , NULL ) ;
if ( V_12 )
V_105 = F_62 ( V_12 -> V_106 ) ;
if ( ! V_105 || V_105 != V_4 )
goto V_173;
V_12 -> V_106 = V_172 ;
V_12 -> V_187 = V_183 ;
V_173:
F_33 ( & V_1 ) ;
}
static void F_143 ( struct V_29 * V_30 )
{
F_60 ( L_44 ) ;
F_118 ( true ) ;
}
int T_5 F_144 ( void )
{
int V_211 = 0 ;
V_42 = F_145 ( L_45 , 0 , NULL , 0 ) ;
if ( F_63 ( V_42 ) )
return F_64 ( V_42 ) ;
V_42 -> V_43 . type = & V_212 ;
F_146 ( & V_164 ) ;
F_146 ( & V_176 ) ;
F_39 () ;
F_12 ( V_3 , V_13 ) ;
V_20 [ 0 ] = '9' ;
V_20 [ 1 ] = '7' ;
V_211 = F_111 ( V_13 -> V_17 ) ;
if ( V_211 ) {
if ( V_211 == - V_27 )
return V_211 ;
F_136 ( L_46 ) ;
}
if ( ! F_15 ( V_189 ) )
F_112 ( V_189 ,
V_193 ) ;
return 0 ;
}
void F_147 ( void )
{
struct V_8 * V_170 , * V_175 ;
struct V_141 * V_141 , * V_191 ;
F_148 ( & V_167 ) ;
F_149 ( & V_166 ) ;
F_28 ( & V_1 ) ;
F_11 ( true , NULL ) ;
F_33 ( & V_1 ) ;
F_150 ( & V_42 -> V_43 , true ) ;
F_151 ( V_42 ) ;
F_107 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_31 ( & V_141 -> V_38 ) ;
F_32 ( V_141 ) ;
}
F_107 (reg_beacon, btmp, &reg_beacon_list, list) {
F_31 ( & V_141 -> V_38 ) ;
F_32 ( V_141 ) ;
}
F_107 (reg_request, tmp, &reg_requests_list, list) {
F_31 ( & V_170 -> V_38 ) ;
F_32 ( V_170 ) ;
}
}
