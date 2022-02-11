static const struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ) ;
}
static const struct V_1 * F_3 ( struct V_3 * V_3 )
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
F_6 ( L_6
L_7
L_8 ,
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
static void F_12 ( void )
{
struct V_16 * V_18 ;
V_18 = F_10 () ;
if ( V_18 != & V_19 && V_18 )
F_9 ( V_18 , V_15 ) ;
}
static void F_13 ( struct V_16 * V_20 )
{
F_12 () ;
F_14 ( V_17 , V_20 ) ;
}
static void F_15 ( bool V_21 ,
const struct V_1 * V_22 )
{
const struct V_1 * V_14 ;
F_16 () ;
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
F_14 ( V_2 , V_22 ) ;
if ( ! V_21 )
return;
F_13 ( & V_19 ) ;
}
static void F_17 ( const struct V_1 * V_25 )
{
struct V_16 * V_18 ;
V_18 = F_10 () ;
F_18 ( ! V_18 ) ;
F_15 ( false , V_25 ) ;
V_23 = V_25 ;
}
bool F_19 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] == '0' && V_26 [ 1 ] == '0' ;
}
static bool F_20 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] && V_26 [ 1 ] ;
}
static bool F_21 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] == '9' && V_26 [ 1 ] == '9' ;
}
static bool F_22 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return V_26 [ 0 ] == '9' && V_26 [ 1 ] == '8' ;
}
static bool F_23 ( const char * V_26 )
{
if ( ! V_26 )
return false ;
return isalpha ( V_26 [ 0 ] ) && isalpha ( V_26 [ 1 ] ) ;
}
static bool F_24 ( const char * V_27 , const char * V_28 )
{
if ( ! V_27 || ! V_28 )
return false ;
return V_27 [ 0 ] == V_28 [ 0 ] && V_27 [ 1 ] == V_28 [ 1 ] ;
}
static bool F_25 ( const char * V_26 )
{
const struct V_1 * V_14 = F_1 () ;
if ( ! V_14 )
return true ;
return ! F_24 ( V_14 -> V_26 , V_26 ) ;
}
static bool F_26 ( void )
{
if ( V_29 [ 0 ] == '9' && V_29 [ 1 ] == '7' )
return false ;
if ( F_27 ( ! F_19 ( V_29 ) && ! F_23 ( V_29 ) ,
L_9 ,
V_29 [ 0 ] , V_29 [ 1 ] ) )
return false ;
return true ;
}
static const struct V_1 *
F_28 ( const struct V_1 * V_30 )
{
struct V_1 * V_4 ;
int V_31 ;
unsigned int V_32 ;
V_31 =
sizeof( struct V_1 ) +
V_30 -> V_33 * sizeof( struct V_34 ) ;
V_4 = F_29 ( V_31 , V_35 ) ;
if ( ! V_4 )
return F_30 ( - V_36 ) ;
memcpy ( V_4 , V_30 , sizeof( struct V_1 ) ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_33 ; V_32 ++ )
memcpy ( & V_4 -> V_37 [ V_32 ] , & V_30 -> V_37 [ V_32 ] ,
sizeof( struct V_34 ) ) ;
return V_4 ;
}
static void F_31 ( struct V_38 * V_39 )
{
struct V_40 * V_20 ;
const struct V_1 * V_41 , * V_42 = NULL ;
int V_32 ;
F_32 () ;
F_33 ( & V_43 ) ;
while ( ! F_34 ( & V_44 ) ) {
V_20 = F_35 ( & V_44 ,
struct V_40 ,
V_45 ) ;
F_36 ( & V_20 -> V_45 ) ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
V_41 = V_47 [ V_32 ] ;
if ( F_24 ( V_20 -> V_26 , V_41 -> V_26 ) ) {
V_42 = F_28 ( V_41 ) ;
break;
}
}
F_37 ( V_20 ) ;
}
F_38 ( & V_43 ) ;
if ( ! F_39 ( V_42 ) )
F_40 ( V_42 ) ;
F_41 () ;
}
static void F_42 ( const char * V_26 )
{
struct V_40 * V_20 ;
if ( ! V_26 )
return;
V_20 = F_29 ( sizeof( struct V_40 ) , V_35 ) ;
if ( ! V_20 )
return;
memcpy ( V_20 -> V_26 , V_26 , 2 ) ;
F_33 ( & V_43 ) ;
F_43 ( & V_20 -> V_45 , & V_44 ) ;
F_38 ( & V_43 ) ;
F_44 ( & V_48 ) ;
}
static void F_45 ( void )
{
F_46 ( ! V_46 , L_10 ) ;
}
static inline void F_45 ( void ) {}
static inline void F_42 ( const char * V_26 ) {}
static int F_47 ( const char * V_26 )
{
if ( ! F_19 ( ( char * ) V_26 ) )
F_48 ( L_11 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
else
F_48 ( L_12 ) ;
F_42 ( V_26 ) ;
return F_49 ( & V_49 -> V_13 . V_50 , V_51 ) ;
}
static enum V_52
F_50 ( struct V_16 * V_20 )
{
if ( F_47 ( V_20 -> V_26 ) )
return V_53 ;
return V_54 ;
}
bool F_51 ( const char * V_26 )
{
struct V_16 * V_18 = F_10 () ;
if ( ! V_18 || V_18 -> V_55 )
return false ;
return F_24 ( V_18 -> V_26 , V_26 ) ;
}
static bool F_52 ( const struct V_34 * V_56 )
{
const struct V_57 * V_58 = & V_56 -> V_58 ;
T_1 V_59 ;
if ( V_58 -> V_60 <= 0 || V_58 -> V_61 <= 0 )
return false ;
if ( V_58 -> V_60 > V_58 -> V_61 )
return false ;
V_59 = V_58 -> V_61 - V_58 -> V_60 ;
if ( V_58 -> V_61 <= V_58 -> V_60 ||
V_58 -> V_62 > V_59 )
return false ;
return true ;
}
static bool F_53 ( const struct V_1 * V_25 )
{
const struct V_34 * V_63 = NULL ;
unsigned int V_32 ;
if ( ! V_25 -> V_33 )
return false ;
if ( F_18 ( V_25 -> V_33 > V_64 ) )
return false ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_63 = & V_25 -> V_37 [ V_32 ] ;
if ( ! F_52 ( V_63 ) )
return false ;
}
return true ;
}
static bool F_54 ( const struct V_57 * V_58 ,
T_1 V_65 , T_1 V_66 )
{
T_1 V_60 , V_61 ;
V_60 = V_65 - ( V_66 / 2 ) ;
V_61 = V_65 + ( V_66 / 2 ) ;
if ( V_60 >= V_58 -> V_60 &&
V_61 <= V_58 -> V_61 )
return true ;
return false ;
}
static bool F_55 ( const struct V_57 * V_58 ,
T_1 V_67 )
{
#define F_56 1000000
T_1 V_68 = V_67 > 45 * F_56 ?
10 * F_56 : 2 * F_56 ;
if ( abs ( V_67 - V_58 -> V_60 ) <= V_68 )
return true ;
if ( abs ( V_67 - V_58 -> V_61 ) <= V_68 )
return true ;
return false ;
#undef F_56
}
static enum V_5
F_57 ( const enum V_5 V_69 ,
const enum V_5 V_70 )
{
if ( V_69 != V_70 )
return V_7 ;
return V_69 ;
}
static int F_58 ( const struct V_34 * V_71 ,
const struct V_34 * V_72 ,
struct V_34 * V_73 )
{
const struct V_57 * V_74 , * V_75 ;
struct V_57 * V_58 ;
const struct V_76 * V_77 , * V_78 ;
struct V_76 * V_79 ;
T_1 V_59 ;
V_74 = & V_71 -> V_58 ;
V_75 = & V_72 -> V_58 ;
V_58 = & V_73 -> V_58 ;
V_77 = & V_71 -> V_79 ;
V_78 = & V_72 -> V_79 ;
V_79 = & V_73 -> V_79 ;
V_58 -> V_60 = F_59 ( V_74 -> V_60 ,
V_75 -> V_60 ) ;
V_58 -> V_61 = F_60 ( V_74 -> V_61 ,
V_75 -> V_61 ) ;
V_58 -> V_62 = F_60 ( V_74 -> V_62 ,
V_75 -> V_62 ) ;
V_59 = V_58 -> V_61 - V_58 -> V_60 ;
if ( V_58 -> V_62 > V_59 )
V_58 -> V_62 = V_59 ;
V_79 -> V_80 = F_60 ( V_77 -> V_80 ,
V_78 -> V_80 ) ;
V_79 -> V_81 = F_60 ( V_77 -> V_81 ,
V_78 -> V_81 ) ;
V_73 -> V_82 = V_71 -> V_82 | V_72 -> V_82 ;
if ( ! F_52 ( V_73 ) )
return - V_83 ;
return 0 ;
}
static struct V_1 *
F_61 ( const struct V_1 * V_84 ,
const struct V_1 * V_85 )
{
int V_14 , V_31 ;
unsigned int V_86 , V_87 ;
unsigned int V_88 = 0 , V_89 = 0 ;
const struct V_34 * V_71 , * V_72 ;
struct V_34 * V_73 ;
struct V_1 * V_25 ;
struct V_34 V_90 ;
if ( ! V_84 || ! V_85 )
return NULL ;
for ( V_86 = 0 ; V_86 < V_84 -> V_33 ; V_86 ++ ) {
V_71 = & V_84 -> V_37 [ V_86 ] ;
for ( V_87 = 0 ; V_87 < V_85 -> V_33 ; V_87 ++ ) {
V_72 = & V_85 -> V_37 [ V_87 ] ;
if ( ! F_58 ( V_71 , V_72 , & V_90 ) )
V_88 ++ ;
}
}
if ( ! V_88 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_88 * sizeof( struct V_34 ) ;
V_25 = F_29 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_86 = 0 ; V_86 < V_84 -> V_33 && V_89 < V_88 ; V_86 ++ ) {
V_71 = & V_84 -> V_37 [ V_86 ] ;
for ( V_87 = 0 ; V_87 < V_85 -> V_33 && V_89 < V_88 ; V_87 ++ ) {
V_72 = & V_85 -> V_37 [ V_87 ] ;
V_73 = & V_25 -> V_37 [ V_89 ] ;
V_14 = F_58 ( V_71 , V_72 , V_73 ) ;
if ( V_14 )
continue;
V_89 ++ ;
}
}
if ( V_89 != V_88 ) {
F_37 ( V_25 ) ;
return NULL ;
}
V_25 -> V_33 = V_88 ;
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_57 ( V_84 -> V_6 ,
V_85 -> V_6 ) ;
return V_25 ;
}
static T_1 F_62 ( T_1 V_91 )
{
T_1 V_92 = 0 ;
if ( V_91 & V_93 )
V_92 |= V_94 ;
if ( V_91 & V_95 )
V_92 |= V_96 ;
if ( V_91 & V_97 )
V_92 |= V_98 ;
return V_92 ;
}
static const struct V_34 *
F_63 ( struct V_3 * V_3 , T_1 V_99 ,
const struct V_1 * V_4 )
{
int V_32 ;
bool V_100 = false ;
bool V_101 = false ;
if ( ! V_4 )
return F_30 ( - V_83 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_102 ;
const struct V_57 * V_103 = NULL ;
V_102 = & V_4 -> V_37 [ V_32 ] ;
V_103 = & V_102 -> V_58 ;
if ( ! V_100 )
V_100 = F_55 ( V_103 , V_99 ) ;
V_101 = F_54 ( V_103 , V_99 , F_64 ( 20 ) ) ;
if ( V_100 && V_101 )
return V_102 ;
}
if ( ! V_100 )
return F_30 ( - V_104 ) ;
return F_30 ( - V_83 ) ;
}
const struct V_34 * F_65 ( struct V_3 * V_3 ,
T_1 V_99 )
{
const struct V_1 * V_4 ;
struct V_16 * V_18 = F_10 () ;
if ( V_18 -> V_105 != V_106 &&
V_18 -> V_105 != V_107 &&
V_3 -> V_4 )
V_4 = F_3 ( V_3 ) ;
else
V_4 = F_1 () ;
return F_63 ( V_3 , V_99 , V_4 ) ;
}
const char * F_66 ( enum V_108 V_105 )
{
switch ( V_105 ) {
case V_109 :
return L_13 ;
case V_107 :
return L_14 ;
case V_110 :
return L_15 ;
case V_106 :
return L_16 ;
default:
F_18 ( 1 ) ;
return L_17 ;
}
}
static void F_67 ( struct V_111 * V_112 ,
const struct V_34 * V_63 )
{
const struct V_76 * V_79 ;
const struct V_57 * V_58 ;
char V_81 [ 32 ] ;
V_79 = & V_63 -> V_79 ;
V_58 = & V_63 -> V_58 ;
if ( ! V_79 -> V_81 )
snprintf ( V_81 , 32 , L_18 ) ;
else
snprintf ( V_81 , 32 , L_19 , V_79 -> V_81 ) ;
F_6 ( L_20 ,
V_112 -> V_99 ) ;
F_6 ( L_21 ,
V_58 -> V_60 , V_58 -> V_61 ,
V_58 -> V_62 , V_81 ,
V_79 -> V_80 ) ;
}
static void F_67 ( struct V_111 * V_112 ,
const struct V_34 * V_63 )
{
return;
}
static void F_68 ( struct V_3 * V_3 ,
enum V_108 V_105 ,
struct V_111 * V_112 )
{
T_1 V_82 , V_113 = 0 ;
const struct V_34 * V_63 = NULL ;
const struct V_76 * V_79 = NULL ;
const struct V_57 * V_58 = NULL ;
struct V_3 * V_114 = NULL ;
struct V_16 * V_18 = F_10 () ;
V_114 = F_69 ( V_18 -> V_115 ) ;
V_82 = V_112 -> V_116 ;
V_63 = F_65 ( V_3 , F_64 ( V_112 -> V_99 ) ) ;
if ( F_70 ( V_63 ) ) {
if ( V_105 == V_106 &&
F_71 ( V_63 ) == - V_104 )
return;
if ( V_18 -> V_105 == V_110 &&
V_114 && V_114 == V_3 &&
V_114 -> V_117 & V_118 ) {
F_6 ( L_22 ,
V_112 -> V_99 ) ;
V_112 -> V_116 |= V_119 ;
V_112 -> V_82 = V_112 -> V_116 ;
} else {
F_6 ( L_23 ,
V_112 -> V_99 ) ;
V_112 -> V_82 |= V_119 ;
}
return;
}
F_67 ( V_112 , V_63 ) ;
V_79 = & V_63 -> V_79 ;
V_58 = & V_63 -> V_58 ;
if ( V_58 -> V_62 < F_64 ( 40 ) )
V_113 = V_120 ;
if ( V_58 -> V_62 < F_64 ( 80 ) )
V_113 |= V_121 ;
if ( V_58 -> V_62 < F_64 ( 160 ) )
V_113 |= V_122 ;
if ( V_18 -> V_105 == V_110 &&
V_114 && V_114 == V_3 &&
V_114 -> V_117 & V_118 ) {
V_112 -> V_82 = V_112 -> V_116 =
F_62 ( V_63 -> V_82 ) | V_113 ;
V_112 -> V_81 = V_112 -> V_123 =
( int ) F_72 ( V_79 -> V_81 ) ;
V_112 -> V_124 = V_112 -> V_125 = V_112 -> V_126 =
( int ) F_73 ( V_79 -> V_80 ) ;
return;
}
V_112 -> V_127 = V_128 ;
V_112 -> V_129 = V_130 ;
V_112 -> V_131 = false ;
V_112 -> V_82 = V_82 | V_113 | F_62 ( V_63 -> V_82 ) ;
V_112 -> V_81 =
F_74 ( int , V_112 -> V_123 ,
F_72 ( V_79 -> V_81 ) ) ;
V_112 -> V_124 = ( int ) F_73 ( V_79 -> V_80 ) ;
if ( V_112 -> V_126 ) {
if ( V_105 == V_106 &&
V_3 -> V_117 & V_132 )
V_112 -> V_125 = V_112 -> V_124 ;
else
V_112 -> V_125 = F_60 ( V_112 -> V_126 ,
V_112 -> V_124 ) ;
} else
V_112 -> V_125 = V_112 -> V_124 ;
}
static void F_75 ( struct V_3 * V_3 ,
enum V_108 V_105 ,
struct V_133 * V_134 )
{
unsigned int V_32 ;
if ( ! V_134 )
return;
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ )
F_68 ( V_3 , V_105 , & V_134 -> V_136 [ V_32 ] ) ;
}
static bool F_76 ( struct V_16 * V_20 )
{
if ( V_20 -> V_105 != V_107 )
return false ;
return V_20 -> V_137 == V_138 ;
}
bool F_77 ( void )
{
return F_76 ( F_10 () ) ;
}
static enum V_52
F_78 ( struct V_16 * V_139 )
{
struct V_16 * V_18 = F_10 () ;
if ( ! V_140 )
return V_53 ;
if ( F_76 ( V_18 ) &&
! F_25 ( V_139 -> V_26 ) )
return V_141 ;
return V_54 ;
}
static bool F_79 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_142 & V_143 ) ;
}
static int F_78 ( struct V_16 * V_139 )
{
return V_53 ;
}
static bool F_79 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_80 ( struct V_3 * V_3 )
{
if ( V_3 -> V_117 & V_118 &&
! ( V_3 -> V_117 & V_144 ) )
return true ;
return false ;
}
static bool F_81 ( struct V_3 * V_3 ,
enum V_108 V_105 )
{
struct V_16 * V_18 = F_10 () ;
if ( ! V_18 ) {
F_6 ( L_24
L_25 ,
F_66 ( V_105 ) ) ;
return true ;
}
if ( V_105 == V_109 &&
V_3 -> V_117 & V_144 ) {
F_6 ( L_24
L_26
L_27 ,
F_66 ( V_105 ) ) ;
return true ;
}
if ( F_80 ( V_3 ) && ! V_3 -> V_4 &&
V_105 != V_106 &&
! F_19 ( V_18 -> V_26 ) ) {
F_6 ( L_24
L_28
L_29 ,
F_66 ( V_105 ) ) ;
return true ;
}
if ( F_76 ( V_18 ) )
return F_79 ( V_3 ) ;
return false ;
}
static bool F_82 ( struct V_3 * V_3 )
{
const struct V_1 * V_145 = F_1 () ;
const struct V_1 * V_146 = F_3 ( V_3 ) ;
struct V_16 * V_18 = F_10 () ;
if ( F_19 ( V_145 -> V_26 ) || ( V_146 && F_19 ( V_146 -> V_26 ) ) )
return true ;
if ( V_18 && V_18 -> V_105 != V_106 &&
V_3 -> V_117 & V_144 )
return true ;
return false ;
}
static void F_83 ( struct V_3 * V_3 , unsigned int V_147 ,
struct V_148 * V_148 )
{
struct V_133 * V_134 ;
struct V_111 * V_112 ;
bool V_149 = false ;
struct V_111 V_150 ;
V_134 = V_3 -> V_151 [ V_148 -> V_112 . V_152 ] ;
V_112 = & V_134 -> V_136 [ V_147 ] ;
if ( F_84 ( V_112 -> V_99 != V_148 -> V_112 . V_99 ) )
return;
if ( V_112 -> V_131 )
return;
V_112 -> V_131 = true ;
if ( ! F_82 ( V_3 ) )
return;
if ( V_3 -> V_117 & V_153 )
return;
V_150 . V_99 = V_112 -> V_99 ;
V_150 . V_82 = V_112 -> V_82 ;
if ( V_112 -> V_82 & V_94 ) {
V_112 -> V_82 &= ~ V_94 ;
V_149 = true ;
}
if ( V_149 )
F_85 ( V_3 , & V_150 , V_112 ) ;
}
static void F_86 ( struct V_3 * V_3 ,
struct V_148 * V_148 )
{
unsigned int V_32 ;
struct V_133 * V_134 ;
if ( ! V_3 -> V_151 [ V_148 -> V_112 . V_152 ] )
return;
V_134 = V_3 -> V_151 [ V_148 -> V_112 . V_152 ] ;
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ )
F_83 ( V_3 , V_32 , V_148 ) ;
}
static void F_87 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_133 * V_134 ;
struct V_148 * V_148 ;
F_88 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_151 [ V_148 -> V_112 . V_152 ] )
continue;
V_134 = V_3 -> V_151 [ V_148 -> V_112 . V_152 ] ;
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ )
F_83 ( V_3 , V_32 , V_148 ) ;
}
}
static void F_89 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_87 ( V_3 ) ;
}
static bool F_90 ( struct V_111 * V_112 )
{
if ( ! V_112 )
return false ;
if ( V_112 -> V_82 & V_119 )
return false ;
if ( ( V_112 -> V_82 & V_120 ) == V_120 )
return false ;
return true ;
}
static void F_91 ( struct V_3 * V_3 ,
struct V_111 * V_154 )
{
struct V_133 * V_134 = V_3 -> V_151 [ V_154 -> V_152 ] ;
struct V_111 * V_155 = NULL , * V_156 = NULL ;
unsigned int V_32 ;
if ( ! F_90 ( V_154 ) ) {
V_154 -> V_82 |= V_120 ;
return;
}
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ ) {
struct V_111 * V_157 = & V_134 -> V_136 [ V_32 ] ;
if ( V_157 -> V_99 == ( V_154 -> V_99 - 20 ) )
V_155 = V_157 ;
if ( V_157 -> V_99 == ( V_154 -> V_99 + 20 ) )
V_156 = V_157 ;
}
if ( ! F_90 ( V_155 ) )
V_154 -> V_82 |= V_158 ;
else
V_154 -> V_82 &= ~ V_158 ;
if ( ! F_90 ( V_156 ) )
V_154 -> V_82 |= V_159 ;
else
V_154 -> V_82 &= ~ V_159 ;
}
static void F_92 ( struct V_3 * V_3 ,
struct V_133 * V_134 )
{
unsigned int V_32 ;
if ( ! V_134 )
return;
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ )
F_91 ( V_3 , & V_134 -> V_136 [ V_32 ] ) ;
}
static void F_93 ( struct V_3 * V_3 )
{
enum V_160 V_152 ;
if ( ! V_3 )
return;
for ( V_152 = 0 ; V_152 < V_161 ; V_152 ++ )
F_92 ( V_3 , V_3 -> V_151 [ V_152 ] ) ;
}
static void F_94 ( struct V_3 * V_3 ,
struct V_16 * V_20 )
{
if ( V_3 -> V_162 )
V_3 -> V_162 ( V_3 , V_20 ) ;
}
static void F_95 ( struct V_3 * V_3 ,
enum V_108 V_105 )
{
enum V_160 V_152 ;
struct V_16 * V_18 = F_10 () ;
if ( F_81 ( V_3 , V_105 ) ) {
if ( V_105 == V_109 &&
V_3 -> V_117 & V_144 )
F_94 ( V_3 , V_18 ) ;
return;
}
V_18 -> V_6 = F_1 () -> V_6 ;
for ( V_152 = 0 ; V_152 < V_161 ; V_152 ++ )
F_75 ( V_3 , V_105 , V_3 -> V_151 [ V_152 ] ) ;
F_89 ( V_3 ) ;
F_93 ( V_3 ) ;
F_94 ( V_3 , V_18 ) ;
}
static void F_96 ( enum V_108 V_105 )
{
struct V_163 * V_164 ;
struct V_3 * V_3 ;
F_16 () ;
F_88 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_164 -> V_3 ;
F_95 ( V_3 , V_105 ) ;
}
}
static void F_97 ( struct V_3 * V_3 ,
struct V_111 * V_112 ,
const struct V_1 * V_4 )
{
T_1 V_113 = 0 ;
const struct V_34 * V_63 = NULL ;
const struct V_76 * V_79 = NULL ;
const struct V_57 * V_58 = NULL ;
V_63 = F_63 ( V_3 , F_64 ( V_112 -> V_99 ) ,
V_4 ) ;
if ( F_70 ( V_63 ) ) {
F_6 ( L_30 ,
V_112 -> V_99 ) ;
V_112 -> V_116 |= V_119 ;
V_112 -> V_82 = V_112 -> V_116 ;
return;
}
F_67 ( V_112 , V_63 ) ;
V_79 = & V_63 -> V_79 ;
V_58 = & V_63 -> V_58 ;
if ( V_58 -> V_62 < F_64 ( 40 ) )
V_113 = V_120 ;
if ( V_58 -> V_62 < F_64 ( 80 ) )
V_113 |= V_121 ;
if ( V_58 -> V_62 < F_64 ( 160 ) )
V_113 |= V_122 ;
V_112 -> V_82 |= F_62 ( V_63 -> V_82 ) | V_113 ;
V_112 -> V_81 = ( int ) F_72 ( V_79 -> V_81 ) ;
V_112 -> V_124 = V_112 -> V_125 =
( int ) F_73 ( V_79 -> V_80 ) ;
}
static void F_98 ( struct V_3 * V_3 ,
struct V_133 * V_134 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_134 )
return;
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ )
F_97 ( V_3 , & V_134 -> V_136 [ V_32 ] , V_4 ) ;
}
void F_99 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_160 V_152 ;
unsigned int V_165 = 0 ;
F_27 ( ! ( V_3 -> V_117 & V_144 ) ,
L_31 ) ;
V_3 -> V_117 |= V_144 ;
for ( V_152 = 0 ; V_152 < V_161 ; V_152 ++ ) {
if ( ! V_3 -> V_151 [ V_152 ] )
continue;
F_98 ( V_3 , V_3 -> V_151 [ V_152 ] , V_4 ) ;
V_165 ++ ;
}
F_18 ( ! V_165 ) ;
}
static void F_100 ( void )
{
bool V_166 = false ;
struct V_16 * V_18 = F_10 () ;
V_18 -> V_55 = true ;
F_101 ( & V_167 ) ;
if ( ! F_34 ( & V_168 ) )
V_166 = true ;
F_102 ( & V_167 ) ;
if ( V_18 -> V_105 == V_107 )
F_103 ( & V_169 ) ;
if ( V_166 )
F_44 ( & V_170 ) ;
}
static enum V_52
F_104 ( struct V_16 * V_171 )
{
V_171 -> V_172 = false ;
V_171 -> V_55 = false ;
F_13 ( V_171 ) ;
return F_50 ( V_171 ) ;
}
static enum V_52
F_105 ( struct V_16 * V_173 )
{
struct V_16 * V_18 = F_10 () ;
if ( F_76 ( V_173 ) )
return F_78 ( V_173 ) ;
if ( F_76 ( V_18 ) )
return V_53 ;
if ( V_18 -> V_105 == V_106 )
return V_174 ;
if ( V_18 -> V_105 == V_107 &&
V_18 -> V_172 )
return V_53 ;
if ( ( V_18 -> V_105 == V_109 ||
V_18 -> V_105 == V_110 ||
V_18 -> V_105 == V_107 ) &&
F_25 ( V_18 -> V_26 ) )
return V_53 ;
if ( ! F_25 ( V_173 -> V_26 ) )
return V_141 ;
return V_54 ;
}
static enum V_52
F_106 ( struct V_16 * V_173 )
{
enum V_52 V_175 ;
V_175 = F_105 ( V_173 ) ;
if ( V_175 == V_53 ||
V_175 == V_141 ) {
F_37 ( V_173 ) ;
return V_175 ;
}
V_173 -> V_172 = V_175 == V_174 ;
V_173 -> V_55 = false ;
F_13 ( V_173 ) ;
V_29 [ 0 ] = V_173 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_173 -> V_26 [ 1 ] ;
return F_50 ( V_173 ) ;
}
static enum V_52
F_107 ( struct V_16 * V_176 )
{
struct V_16 * V_18 = F_10 () ;
if ( V_18 -> V_105 == V_109 ) {
if ( F_25 ( V_176 -> V_26 ) )
return V_54 ;
return V_141 ;
}
if ( V_18 -> V_105 == V_110 &&
! F_25 ( V_176 -> V_26 ) )
return V_141 ;
return V_174 ;
}
static enum V_52
F_108 ( struct V_3 * V_3 ,
struct V_16 * V_176 )
{
const struct V_1 * V_4 ;
enum V_52 V_175 ;
V_175 = F_107 ( V_176 ) ;
switch ( V_175 ) {
case V_54 :
break;
case V_53 :
F_37 ( V_176 ) ;
return V_175 ;
case V_174 :
case V_141 :
V_4 = F_28 ( F_1 () ) ;
if ( F_70 ( V_4 ) ) {
F_37 ( V_176 ) ;
return V_53 ;
}
F_14 ( V_3 -> V_4 , V_4 ) ;
}
V_176 -> V_172 = V_175 == V_174 ;
V_176 -> V_55 = false ;
F_13 ( V_176 ) ;
if ( V_175 == V_141 ) {
F_109 ( V_176 ) ;
F_100 () ;
return V_175 ;
}
return F_50 ( V_176 ) ;
}
static enum V_52
F_110 ( struct V_3 * V_3 ,
struct V_16 * V_177 )
{
struct V_3 * V_178 = NULL ;
struct V_16 * V_18 = F_10 () ;
if ( F_76 ( V_18 ) ) {
if ( F_25 ( V_177 -> V_26 ) )
return V_53 ;
return V_141 ;
} else {
if ( V_3 -> V_117 & V_179 )
return V_53 ;
}
if ( F_111 ( ! F_23 ( V_177 -> V_26 ) ) )
return - V_83 ;
if ( V_18 -> V_105 != V_106 )
return V_54 ;
V_178 = F_69 ( V_18 -> V_115 ) ;
if ( V_178 != V_3 ) {
if ( F_25 ( V_177 -> V_26 ) )
return V_53 ;
return V_141 ;
}
if ( F_18 ( F_25 ( V_177 -> V_26 ) ) )
return V_54 ;
return V_141 ;
}
static enum V_52
F_112 ( struct V_3 * V_3 ,
struct V_16 * V_177 )
{
enum V_52 V_175 ;
V_175 = F_110 ( V_3 , V_177 ) ;
switch ( V_175 ) {
case V_54 :
break;
case V_53 :
case V_141 :
F_37 ( V_177 ) ;
return V_175 ;
case V_174 :
F_37 ( V_177 ) ;
F_46 ( 1 , L_32 ) ;
return V_53 ;
}
V_177 -> V_172 = false ;
V_177 -> V_55 = false ;
F_13 ( V_177 ) ;
return F_50 ( V_177 ) ;
}
static void F_113 ( struct V_16 * V_180 )
{
struct V_3 * V_3 = NULL ;
enum V_52 V_175 ;
if ( F_18 ( ! V_180 -> V_26 ) )
return;
if ( V_180 -> V_115 != V_181 )
V_3 = F_69 ( V_180 -> V_115 ) ;
if ( V_180 -> V_105 == V_110 && ! V_3 ) {
F_37 ( V_180 ) ;
return;
}
switch ( V_180 -> V_105 ) {
case V_109 :
F_104 ( V_180 ) ;
return;
case V_107 :
V_175 = F_106 ( V_180 ) ;
if ( V_175 == V_53 ||
V_175 == V_141 )
return;
F_114 ( & V_169 , F_115 ( 3142 ) ) ;
return;
case V_110 :
V_175 = F_108 ( V_3 , V_180 ) ;
break;
case V_106 :
V_175 = F_112 ( V_3 , V_180 ) ;
break;
default:
F_27 ( 1 , L_33 , V_180 -> V_105 ) ;
return;
}
if ( V_175 == V_141 && V_3 &&
V_3 -> V_117 & V_118 )
F_95 ( V_3 , V_180 -> V_105 ) ;
}
static void F_116 ( void )
{
struct V_16 * V_180 , * V_18 ;
V_18 = F_10 () ;
if ( V_18 && ! V_18 -> V_55 ) {
F_6 ( L_34 ) ;
return;
}
F_101 ( & V_167 ) ;
if ( F_34 ( & V_168 ) ) {
F_102 ( & V_167 ) ;
return;
}
V_180 = F_35 ( & V_168 ,
struct V_16 ,
V_45 ) ;
F_117 ( & V_180 -> V_45 ) ;
F_102 ( & V_167 ) ;
F_113 ( V_180 ) ;
}
static void F_118 ( void )
{
struct V_163 * V_164 ;
struct V_148 * V_182 , * V_183 ;
F_119 ( & V_184 ) ;
F_120 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_117 ( & V_182 -> V_45 ) ;
F_88 (rdev, &cfg80211_rdev_list, list)
F_86 ( & V_164 -> V_3 , V_182 ) ;
F_43 ( & V_182 -> V_45 , & V_185 ) ;
}
F_121 ( & V_184 ) ;
}
static void F_122 ( struct V_38 * V_39 )
{
F_32 () ;
F_116 () ;
F_118 () ;
F_41 () ;
}
static void F_123 ( struct V_16 * V_20 )
{
V_20 -> V_26 [ 0 ] = toupper ( V_20 -> V_26 [ 0 ] ) ;
V_20 -> V_26 [ 1 ] = toupper ( V_20 -> V_26 [ 1 ] ) ;
F_101 ( & V_167 ) ;
F_43 ( & V_20 -> V_45 , & V_168 ) ;
F_102 ( & V_167 ) ;
F_44 ( & V_170 ) ;
}
static int F_124 ( const char * V_26 )
{
struct V_16 * V_20 ;
V_20 = F_29 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_105 = V_109 ;
F_123 ( V_20 ) ;
return 0 ;
}
int F_125 ( const char * V_26 ,
enum V_186 V_137 )
{
struct V_16 * V_20 ;
if ( F_18 ( ! V_26 ) )
return - V_83 ;
V_20 = F_29 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_115 = V_181 ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_105 = V_107 ;
V_20 -> V_137 = V_137 ;
F_123 ( V_20 ) ;
return 0 ;
}
int F_126 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_20 ;
if ( F_18 ( ! V_26 || ! V_3 ) )
return - V_83 ;
V_3 -> V_117 &= ~ V_144 ;
V_20 = F_29 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_115 = F_127 ( V_3 ) ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_105 = V_110 ;
F_123 ( V_20 ) ;
return 0 ;
}
void F_128 ( struct V_3 * V_3 , enum V_160 V_152 ,
const T_2 * V_187 , T_2 V_188 )
{
char V_26 [ 2 ] ;
enum V_189 V_190 = V_191 ;
struct V_16 * V_20 = NULL , * V_18 ;
if ( V_188 & 0x01 )
return;
if ( V_188 < V_192 )
return;
V_20 = F_29 ( sizeof( * V_20 ) , V_35 ) ;
if ( ! V_20 )
return;
V_26 [ 0 ] = V_187 [ 0 ] ;
V_26 [ 1 ] = V_187 [ 1 ] ;
if ( V_187 [ 2 ] == 'I' )
V_190 = V_193 ;
else if ( V_187 [ 2 ] == 'O' )
V_190 = V_194 ;
F_129 () ;
V_18 = F_10 () ;
if ( F_111 ( ! V_18 ) )
goto V_12;
if ( V_18 -> V_105 == V_106 &&
V_18 -> V_115 != V_181 )
goto V_12;
V_20 -> V_115 = F_127 ( V_3 ) ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_105 = V_106 ;
V_20 -> V_195 = V_190 ;
F_123 ( V_20 ) ;
V_20 = NULL ;
V_12:
F_37 ( V_20 ) ;
F_130 () ;
}
static void F_131 ( char * V_26 , bool V_196 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_26 () ) {
if ( V_196 ) {
F_6 ( L_35 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_19 ( V_197 ) ) {
F_6 ( L_36 ,
V_197 [ 0 ] , V_197 [ 1 ] ) ;
V_26 [ 0 ] = V_197 [ 0 ] ;
V_26 [ 1 ] = V_197 [ 1 ] ;
}
} else {
F_6 ( L_37 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_19 ( V_197 ) ) {
F_6 ( L_36 ,
V_197 [ 0 ] , V_197 [ 1 ] ) ;
V_26 [ 0 ] = V_197 [ 0 ] ;
V_26 [ 1 ] = V_197 [ 1 ] ;
} else
F_6 ( L_38 ) ;
}
static void F_132 ( struct V_3 * V_3 )
{
struct V_133 * V_134 ;
enum V_160 V_152 ;
struct V_111 * V_112 ;
int V_32 ;
for ( V_152 = 0 ; V_152 < V_161 ; V_152 ++ ) {
V_134 = V_3 -> V_151 [ V_152 ] ;
if ( ! V_134 )
continue;
for ( V_32 = 0 ; V_32 < V_134 -> V_135 ; V_32 ++ ) {
V_112 = & V_134 -> V_136 [ V_32 ] ;
V_112 -> V_82 = V_112 -> V_116 ;
V_112 -> V_81 = V_112 -> V_123 ;
V_112 -> V_125 = V_112 -> V_126 ;
V_112 -> V_131 = false ;
}
}
}
static void F_133 ( bool V_196 )
{
char V_26 [ 2 ] ;
char V_198 [ 2 ] ;
struct V_148 * V_148 , * V_199 ;
struct V_16 * V_180 , * V_183 ;
F_134 ( V_200 ) ;
struct V_163 * V_164 ;
F_16 () ;
F_15 ( true , & V_24 ) ;
F_131 ( V_26 , V_196 ) ;
F_101 ( & V_167 ) ;
F_120 (reg_request, tmp, &reg_requests_list, list) {
if ( V_180 -> V_105 != V_107 )
continue;
F_135 ( & V_180 -> V_45 , & V_200 ) ;
}
F_102 ( & V_167 ) ;
F_119 ( & V_184 ) ;
F_120 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_36 ( & V_148 -> V_45 ) ;
F_37 ( V_148 ) ;
}
F_121 ( & V_184 ) ;
F_120 (reg_beacon, btmp, &reg_beacon_list, list) {
F_36 ( & V_148 -> V_45 ) ;
F_37 ( V_148 ) ;
}
V_198 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_198 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_88 (rdev, &cfg80211_rdev_list, list) {
if ( V_164 -> V_3 . V_117 & V_144 )
F_132 ( & V_164 -> V_3 ) ;
}
F_124 ( V_198 ) ;
if ( F_23 ( V_26 ) )
F_125 ( V_29 , V_201 ) ;
F_101 ( & V_167 ) ;
F_136 ( & V_200 , & V_168 ) ;
F_102 ( & V_167 ) ;
F_6 ( L_39 ) ;
F_44 ( & V_170 ) ;
}
void F_137 ( void )
{
F_6 ( L_40 ) ;
F_133 ( false ) ;
}
static bool F_138 ( T_3 V_202 )
{
if ( V_202 == F_139 ( 12 , V_203 ) ||
V_202 == F_139 ( 13 , V_203 ) ||
V_202 == F_139 ( 14 , V_203 ) )
return true ;
return false ;
}
static bool F_140 ( struct V_111 * V_204 )
{
struct V_148 * V_182 ;
F_88 (pending_beacon, &reg_pending_beacons, list)
if ( V_204 -> V_99 ==
V_182 -> V_112 . V_99 )
return true ;
return false ;
}
int F_141 ( struct V_3 * V_3 ,
struct V_111 * V_204 ,
T_4 V_205 )
{
struct V_148 * V_148 ;
bool V_206 ;
if ( V_204 -> V_131 ||
V_204 -> V_82 & V_96 ||
( V_204 -> V_152 == V_203 &&
! F_138 ( V_204 -> V_99 ) ) )
return 0 ;
F_119 ( & V_184 ) ;
V_206 = F_140 ( V_204 ) ;
F_121 ( & V_184 ) ;
if ( V_206 )
return 0 ;
V_148 = F_29 ( sizeof( struct V_148 ) , V_205 ) ;
if ( ! V_148 )
return - V_36 ;
F_6 ( L_41 ,
V_204 -> V_99 ,
F_142 ( V_204 -> V_99 ) ,
F_143 ( V_3 ) ) ;
memcpy ( & V_148 -> V_112 , V_204 ,
sizeof( struct V_111 ) ) ;
F_119 ( & V_184 ) ;
F_43 ( & V_148 -> V_45 , & V_207 ) ;
F_121 ( & V_184 ) ;
F_44 ( & V_170 ) ;
return 0 ;
}
static void F_144 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_63 = NULL ;
const struct V_57 * V_58 = NULL ;
const struct V_76 * V_79 = NULL ;
F_48 ( L_42 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_63 = & V_25 -> V_37 [ V_32 ] ;
V_58 = & V_63 -> V_58 ;
V_79 = & V_63 -> V_79 ;
if ( V_79 -> V_81 )
F_48 ( L_43 ,
V_58 -> V_60 ,
V_58 -> V_61 ,
V_58 -> V_62 ,
V_79 -> V_81 ,
V_79 -> V_80 ) ;
else
F_48 ( L_44 ,
V_58 -> V_60 ,
V_58 -> V_61 ,
V_58 -> V_62 ,
V_79 -> V_80 ) ;
}
}
bool F_145 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
F_6 ( L_45 ,
V_6 ) ;
return false ;
}
}
static void F_146 ( const struct V_1 * V_25 )
{
struct V_16 * V_18 = F_10 () ;
if ( F_22 ( V_25 -> V_26 ) ) {
if ( V_18 -> V_105 == V_106 ) {
struct V_163 * V_164 ;
V_164 = F_147 ( V_18 -> V_115 ) ;
if ( V_164 ) {
F_48 ( L_46 ,
V_164 -> V_208 [ 0 ] ,
V_164 -> V_208 [ 1 ] ) ;
} else
F_48 ( L_47 ) ;
} else
F_48 ( L_47 ) ;
} else if ( F_19 ( V_25 -> V_26 ) ) {
F_48 ( L_48 ) ;
} else {
if ( F_21 ( V_25 -> V_26 ) )
F_48 ( L_49 ) ;
else {
if ( F_76 ( V_18 ) )
F_48 ( L_50 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_48 ( L_51 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_48 ( L_52 , F_4 ( V_25 -> V_6 ) ) ;
F_144 ( V_25 ) ;
}
static void F_148 ( const struct V_1 * V_25 )
{
F_48 ( L_53 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_144 ( V_25 ) ;
}
static int F_149 ( const struct V_1 * V_25 )
{
if ( ! F_19 ( V_25 -> V_26 ) )
return - V_83 ;
F_17 ( V_25 ) ;
return 0 ;
}
static int F_150 ( const struct V_1 * V_25 ,
struct V_16 * V_173 )
{
const struct V_1 * V_209 = NULL ;
if ( F_19 ( V_25 -> V_26 ) )
return - V_83 ;
if ( ! F_25 ( V_25 -> V_26 ) )
return - V_210 ;
if ( ! F_53 ( V_25 ) ) {
F_151 ( L_54 ) ;
F_148 ( V_25 ) ;
return - V_83 ;
}
if ( ! V_173 -> V_172 ) {
F_15 ( false , V_25 ) ;
return 0 ;
}
V_209 = F_61 ( V_25 , F_1 () ) ;
if ( ! V_209 )
return - V_83 ;
F_37 ( V_25 ) ;
V_25 = NULL ;
F_15 ( false , V_209 ) ;
return 0 ;
}
static int F_152 ( const struct V_1 * V_25 ,
struct V_16 * V_176 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_209 = NULL ;
const struct V_1 * V_183 ;
struct V_3 * V_114 ;
if ( F_19 ( V_25 -> V_26 ) )
return - V_83 ;
if ( ! F_25 ( V_25 -> V_26 ) )
return - V_210 ;
if ( ! F_53 ( V_25 ) ) {
F_151 ( L_54 ) ;
F_148 ( V_25 ) ;
return - V_83 ;
}
V_114 = F_69 ( V_176 -> V_115 ) ;
if ( ! V_114 ) {
F_114 ( & V_169 , 0 ) ;
return - V_211 ;
}
if ( ! V_176 -> V_172 ) {
if ( V_114 -> V_4 )
return - V_210 ;
V_4 = F_28 ( V_25 ) ;
if ( F_70 ( V_4 ) )
return F_71 ( V_4 ) ;
F_14 ( V_114 -> V_4 , V_4 ) ;
F_15 ( false , V_25 ) ;
return 0 ;
}
V_209 = F_61 ( V_25 , F_1 () ) ;
if ( ! V_209 )
return - V_83 ;
V_183 = F_3 ( V_114 ) ;
F_14 ( V_114 -> V_4 , V_25 ) ;
F_8 ( V_183 ) ;
V_25 = NULL ;
F_15 ( false , V_209 ) ;
return 0 ;
}
static int F_153 ( const struct V_1 * V_25 ,
struct V_16 * V_177 )
{
struct V_3 * V_114 ;
if ( ! F_20 ( V_25 -> V_26 ) && ! F_23 ( V_25 -> V_26 ) &&
! F_21 ( V_25 -> V_26 ) )
return - V_83 ;
if ( ! F_53 ( V_25 ) ) {
F_151 ( L_54 ) ;
F_148 ( V_25 ) ;
return - V_83 ;
}
V_114 = F_69 ( V_177 -> V_115 ) ;
if ( ! V_114 ) {
F_114 ( & V_169 , 0 ) ;
return - V_211 ;
}
if ( V_177 -> V_172 )
return - V_83 ;
F_15 ( false , V_25 ) ;
return 0 ;
}
int F_40 ( const struct V_1 * V_25 )
{
struct V_16 * V_18 ;
bool V_212 = false ;
int V_14 ;
if ( ! F_51 ( V_25 -> V_26 ) ) {
F_37 ( V_25 ) ;
return - V_83 ;
}
V_18 = F_10 () ;
switch ( V_18 -> V_105 ) {
case V_109 :
V_14 = F_149 ( V_25 ) ;
break;
case V_107 :
V_14 = F_150 ( V_25 , V_18 ) ;
V_212 = true ;
break;
case V_110 :
V_14 = F_152 ( V_25 , V_18 ) ;
break;
case V_106 :
V_14 = F_153 ( V_25 , V_18 ) ;
break;
default:
F_27 ( 1 , L_33 , V_18 -> V_105 ) ;
return - V_83 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_210 :
F_100 () ;
break;
default:
F_133 ( V_212 ) ;
}
F_37 ( V_25 ) ;
return V_14 ;
}
if ( F_18 ( ! V_18 -> V_172 && V_25 != F_1 () ) )
return - V_83 ;
F_96 ( V_18 -> V_105 ) ;
F_146 ( F_1 () ) ;
F_109 ( V_18 ) ;
F_100 () ;
return 0 ;
}
int F_154 ( struct V_213 * V_13 , struct V_214 * V_190 )
{
struct V_16 * V_18 ;
T_2 V_26 [ 2 ] ;
bool V_215 = false ;
F_129 () ;
V_18 = F_10 () ;
if ( V_18 && ! V_18 -> V_55 ) {
memcpy ( V_26 , V_18 -> V_26 , 2 ) ;
V_215 = true ;
}
F_130 () ;
if ( V_215 )
return F_155 ( V_190 , L_55 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
return 0 ;
}
void F_156 ( struct V_3 * V_3 )
{
struct V_16 * V_18 ;
if ( ! F_79 ( V_3 ) )
V_140 ++ ;
V_18 = F_10 () ;
F_95 ( V_3 , V_18 -> V_105 ) ;
}
void F_157 ( struct V_3 * V_3 )
{
struct V_3 * V_114 = NULL ;
struct V_16 * V_18 ;
V_18 = F_10 () ;
if ( ! F_79 ( V_3 ) )
V_140 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_14 ( V_3 -> V_4 , NULL ) ;
if ( V_18 )
V_114 = F_69 ( V_18 -> V_115 ) ;
if ( ! V_114 || V_114 != V_3 )
return;
V_18 -> V_115 = V_181 ;
V_18 -> V_195 = V_191 ;
}
static void F_158 ( struct V_38 * V_39 )
{
F_6 ( L_56 ) ;
F_32 () ;
F_133 ( true ) ;
F_41 () ;
}
int T_5 F_159 ( void )
{
int V_216 = 0 ;
V_49 = F_160 ( L_57 , 0 , NULL , 0 ) ;
if ( F_70 ( V_49 ) )
return F_71 ( V_49 ) ;
V_49 -> V_13 . type = & V_217 ;
F_161 ( & V_167 ) ;
F_161 ( & V_184 ) ;
F_45 () ;
F_14 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_216 = F_124 ( V_23 -> V_26 ) ;
if ( V_216 ) {
if ( V_216 == - V_36 )
return V_216 ;
F_151 ( L_58 ) ;
}
if ( ! F_19 ( V_197 ) )
F_125 ( V_197 ,
V_201 ) ;
return 0 ;
}
void F_162 ( void )
{
struct V_16 * V_180 , * V_183 ;
struct V_148 * V_148 , * V_199 ;
F_163 ( & V_170 ) ;
F_164 ( & V_169 ) ;
F_32 () ;
F_15 ( true , NULL ) ;
F_41 () ;
F_165 ( & V_49 -> V_13 , true ) ;
F_166 ( V_49 ) ;
F_120 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_36 ( & V_148 -> V_45 ) ;
F_37 ( V_148 ) ;
}
F_120 (reg_beacon, btmp, &reg_beacon_list, list) {
F_36 ( & V_148 -> V_45 ) ;
F_37 ( V_148 ) ;
}
F_120 (reg_request, tmp, &reg_requests_list, list) {
F_36 ( & V_180 -> V_45 ) ;
F_37 ( V_180 ) ;
}
}
