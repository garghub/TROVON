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
static void F_12 ( struct V_16 * V_18 )
{
if ( V_18 != F_10 () )
F_13 ( V_18 ) ;
}
static void F_14 ( void )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 != & V_20 && V_19 )
F_9 ( V_19 , V_15 ) ;
}
static void F_15 ( struct V_16 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_10 () ;
if ( V_19 == V_18 )
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
F_15 ( & V_20 ) ;
}
static void F_19 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 ;
V_19 = F_10 () ;
F_20 ( ! V_19 ) ;
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
L_9 ,
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
const struct V_1 * V_41 , * V_42 = NULL ;
int V_32 ;
F_34 () ;
F_35 ( & V_43 ) ;
while ( ! F_36 ( & V_44 ) ) {
V_18 = F_37 ( & V_44 ,
struct V_40 ,
V_45 ) ;
F_38 ( & V_18 -> V_45 ) ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
V_41 = V_47 [ V_32 ] ;
if ( F_26 ( V_18 -> V_26 , V_41 -> V_26 ) ) {
V_42 = F_30 ( V_41 ) ;
break;
}
}
F_13 ( V_18 ) ;
}
F_39 ( & V_43 ) ;
if ( ! F_40 ( V_42 ) )
F_41 ( V_42 ) ;
F_42 () ;
}
static void F_43 ( const char * V_26 )
{
struct V_40 * V_18 ;
if ( ! V_26 )
return;
V_18 = F_31 ( sizeof( struct V_40 ) , V_35 ) ;
if ( ! V_18 )
return;
memcpy ( V_18 -> V_26 , V_26 , 2 ) ;
F_35 ( & V_43 ) ;
F_44 ( & V_18 -> V_45 , & V_44 ) ;
F_39 ( & V_43 ) ;
F_45 ( & V_48 ) ;
}
static void F_46 ( void )
{
F_47 ( ! V_46 , L_10 ) ;
}
static inline void F_46 ( void ) {}
static inline void F_43 ( const char * V_26 ) {}
static int F_48 ( const char * V_26 )
{
char V_49 [ 12 ] ;
char * V_50 [] = { V_49 , NULL } ;
snprintf ( V_49 , sizeof( V_49 ) , L_11 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
if ( ! F_21 ( ( char * ) V_26 ) )
F_49 ( L_12 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
else
F_49 ( L_13 ) ;
F_43 ( V_26 ) ;
return F_50 ( & V_51 -> V_13 . V_52 , V_53 , V_50 ) ;
}
static enum V_54
F_51 ( struct V_16 * V_18 )
{
if ( F_48 ( V_18 -> V_26 ) )
return V_55 ;
return V_56 ;
}
bool F_52 ( const char * V_26 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_19 || V_19 -> V_57 )
return false ;
return F_26 ( V_19 -> V_26 , V_26 ) ;
}
static const struct V_1 * F_53 ( struct V_3 * V_3 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_58 != V_59 &&
V_19 -> V_58 != V_60 &&
V_3 -> V_4 )
return F_3 ( V_3 ) ;
return F_1 () ;
}
unsigned int F_54 ( const struct V_1 * V_25 ,
const struct V_34 * V_61 )
{
const struct V_62 * V_63 = & V_61 -> V_63 ;
const struct V_62 * V_64 ;
const struct V_34 * V_65 ;
T_1 V_66 , V_67 , V_68 , V_69 ;
for ( V_68 = 0 ; V_68 < V_25 -> V_33 ; V_68 ++ )
if ( V_61 == & V_25 -> V_37 [ V_68 ] )
break;
if ( V_68 == V_25 -> V_33 )
return 0 ;
V_69 = V_68 ;
while ( V_69 ) {
V_65 = & V_25 -> V_37 [ -- V_69 ] ;
V_64 = & V_65 -> V_63 ;
if ( V_64 -> V_70 < V_63 -> V_71 )
break;
V_63 = V_64 ;
}
V_66 = V_63 -> V_71 ;
V_63 = & V_61 -> V_63 ;
V_69 = V_68 ;
while ( V_69 < V_25 -> V_33 - 1 ) {
V_65 = & V_25 -> V_37 [ ++ V_69 ] ;
V_64 = & V_65 -> V_63 ;
if ( V_64 -> V_71 > V_63 -> V_70 )
break;
V_63 = V_64 ;
}
V_67 = V_63 -> V_70 ;
return V_67 - V_66 ;
}
static bool F_55 ( const struct V_34 * V_61 )
{
const struct V_62 * V_63 = & V_61 -> V_63 ;
T_1 V_72 ;
if ( V_63 -> V_71 <= 0 || V_63 -> V_70 <= 0 )
return false ;
if ( V_63 -> V_71 > V_63 -> V_70 )
return false ;
V_72 = V_63 -> V_70 - V_63 -> V_71 ;
if ( V_63 -> V_70 <= V_63 -> V_71 ||
V_63 -> V_73 > V_72 )
return false ;
return true ;
}
static bool F_56 ( const struct V_1 * V_25 )
{
const struct V_34 * V_74 = NULL ;
unsigned int V_32 ;
if ( ! V_25 -> V_33 )
return false ;
if ( F_20 ( V_25 -> V_33 > V_75 ) )
return false ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_74 = & V_25 -> V_37 [ V_32 ] ;
if ( ! F_55 ( V_74 ) )
return false ;
}
return true ;
}
static bool F_57 ( const struct V_62 * V_63 ,
T_1 V_76 , T_1 V_77 )
{
T_1 V_71 , V_70 ;
V_71 = V_76 - ( V_77 / 2 ) ;
V_70 = V_76 + ( V_77 / 2 ) ;
if ( V_71 >= V_63 -> V_71 &&
V_70 <= V_63 -> V_70 )
return true ;
return false ;
}
static bool F_58 ( const struct V_62 * V_63 ,
T_1 V_78 )
{
#define F_59 1000000
T_1 V_79 = V_78 > 45 * F_59 ?
10 * F_59 : 2 * F_59 ;
if ( abs ( V_78 - V_63 -> V_71 ) <= V_79 )
return true ;
if ( abs ( V_78 - V_63 -> V_70 ) <= V_79 )
return true ;
return false ;
#undef F_59
}
static enum V_5
F_60 ( const enum V_5 V_80 ,
const enum V_5 V_81 )
{
if ( V_80 != V_81 )
return V_7 ;
return V_80 ;
}
static int F_61 ( const struct V_1 * V_82 ,
const struct V_1 * V_83 ,
const struct V_34 * V_84 ,
const struct V_34 * V_85 ,
struct V_34 * V_86 )
{
const struct V_62 * V_87 , * V_88 ;
struct V_62 * V_63 ;
const struct V_89 * V_90 , * V_91 ;
struct V_89 * V_92 ;
T_1 V_72 , V_93 , V_94 ;
V_87 = & V_84 -> V_63 ;
V_88 = & V_85 -> V_63 ;
V_63 = & V_86 -> V_63 ;
V_90 = & V_84 -> V_92 ;
V_91 = & V_85 -> V_92 ;
V_92 = & V_86 -> V_92 ;
V_63 -> V_71 = F_62 ( V_87 -> V_71 ,
V_88 -> V_71 ) ;
V_63 -> V_70 = F_63 ( V_87 -> V_70 ,
V_88 -> V_70 ) ;
V_93 = V_87 -> V_73 ;
V_94 = V_88 -> V_73 ;
if ( V_84 -> V_95 & V_96 )
V_93 = F_54 ( V_82 , V_84 ) ;
if ( V_85 -> V_95 & V_96 )
V_94 = F_54 ( V_83 , V_85 ) ;
V_63 -> V_73 = F_63 ( V_93 , V_94 ) ;
V_86 -> V_95 = V_84 -> V_95 | V_85 -> V_95 ;
if ( ( V_84 -> V_95 & V_96 ) &&
( V_85 -> V_95 & V_96 ) )
V_86 -> V_95 |= V_96 ;
else
V_86 -> V_95 &= ~ V_96 ;
V_72 = V_63 -> V_70 - V_63 -> V_71 ;
if ( V_63 -> V_73 > V_72 )
V_63 -> V_73 = V_72 ;
V_92 -> V_97 = F_63 ( V_90 -> V_97 ,
V_91 -> V_97 ) ;
V_92 -> V_98 = F_63 ( V_90 -> V_98 ,
V_91 -> V_98 ) ;
V_86 -> V_99 = F_62 ( V_84 -> V_99 ,
V_85 -> V_99 ) ;
if ( ! F_55 ( V_86 ) )
return - V_100 ;
return 0 ;
}
static bool F_64 ( struct V_34 * V_101 ,
struct V_34 * V_102 )
{
if ( V_101 -> V_95 != V_102 -> V_95 )
return false ;
if ( ( V_101 -> V_92 . V_98 >
V_102 -> V_92 . V_98 ) ||
V_101 -> V_92 . V_97 > V_102 -> V_92 . V_97 )
return false ;
if ( V_101 -> V_63 . V_71 > V_102 -> V_63 . V_71 ||
V_101 -> V_63 . V_70 < V_102 -> V_63 . V_70 )
return false ;
if ( V_101 -> V_63 . V_73 <
V_102 -> V_63 . V_73 )
return false ;
return true ;
}
static void F_65 ( struct V_34 * V_61 ,
struct V_34 * V_37 , T_1 * V_103 )
{
struct V_34 * V_104 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < * V_103 ; V_32 ++ ) {
V_104 = & V_37 [ V_32 ] ;
if ( F_64 ( V_104 , V_61 ) )
return;
if ( F_64 ( V_61 , V_104 ) ) {
memcpy ( V_104 , V_61 , sizeof( * V_61 ) ) ;
return;
}
}
memcpy ( & V_37 [ * V_103 ] , V_61 , sizeof( * V_61 ) ) ;
( * V_103 ) ++ ;
}
static struct V_1 *
F_66 ( const struct V_1 * V_82 ,
const struct V_1 * V_83 )
{
int V_14 , V_31 ;
unsigned int V_105 , V_106 ;
unsigned int V_107 = 0 ;
const struct V_34 * V_84 , * V_85 ;
struct V_34 V_86 ;
struct V_1 * V_25 ;
if ( ! V_82 || ! V_83 )
return NULL ;
for ( V_105 = 0 ; V_105 < V_82 -> V_33 ; V_105 ++ ) {
V_84 = & V_82 -> V_37 [ V_105 ] ;
for ( V_106 = 0 ; V_106 < V_83 -> V_33 ; V_106 ++ ) {
V_85 = & V_83 -> V_37 [ V_106 ] ;
if ( ! F_61 ( V_82 , V_83 , V_84 , V_85 ,
& V_86 ) )
V_107 ++ ;
}
}
if ( ! V_107 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_107 * sizeof( struct V_34 ) ;
V_25 = F_31 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_105 = 0 ; V_105 < V_82 -> V_33 ; V_105 ++ ) {
V_84 = & V_82 -> V_37 [ V_105 ] ;
for ( V_106 = 0 ; V_106 < V_83 -> V_33 ; V_106 ++ ) {
V_85 = & V_83 -> V_37 [ V_106 ] ;
V_14 = F_61 ( V_82 , V_83 , V_84 , V_85 ,
& V_86 ) ;
if ( V_14 )
continue;
F_65 ( & V_86 , V_25 -> V_37 ,
& V_25 -> V_33 ) ;
}
}
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_60 ( V_82 -> V_6 ,
V_83 -> V_6 ) ;
return V_25 ;
}
static T_1 F_67 ( T_1 V_108 )
{
T_1 V_109 = 0 ;
if ( V_108 & V_110 )
V_109 |= V_111 ;
if ( V_108 & V_112 )
V_109 |= V_113 ;
if ( V_108 & V_114 )
V_109 |= V_115 ;
if ( V_108 & V_116 )
V_109 |= V_117 ;
return V_109 ;
}
static const struct V_34 *
F_68 ( struct V_3 * V_3 , T_1 V_118 ,
const struct V_1 * V_4 )
{
int V_32 ;
bool V_119 = false ;
bool V_120 = false ;
if ( ! V_4 )
return F_32 ( - V_100 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_121 ;
const struct V_62 * V_122 = NULL ;
V_121 = & V_4 -> V_37 [ V_32 ] ;
V_122 = & V_121 -> V_63 ;
if ( ! V_119 )
V_119 = F_58 ( V_122 , V_118 ) ;
V_120 = F_57 ( V_122 , V_118 , F_69 ( 20 ) ) ;
if ( V_119 && V_120 )
return V_121 ;
}
if ( ! V_119 )
return F_32 ( - V_123 ) ;
return F_32 ( - V_100 ) ;
}
const struct V_34 * F_70 ( struct V_3 * V_3 ,
T_1 V_118 )
{
const struct V_1 * V_4 ;
V_4 = F_53 ( V_3 ) ;
return F_68 ( V_3 , V_118 , V_4 ) ;
}
const char * F_71 ( enum V_124 V_58 )
{
switch ( V_58 ) {
case V_125 :
return L_14 ;
case V_60 :
return L_15 ;
case V_126 :
return L_16 ;
case V_59 :
return L_17 ;
default:
F_20 ( 1 ) ;
return L_18 ;
}
}
static void F_72 ( const struct V_1 * V_4 ,
struct V_127 * V_128 ,
const struct V_34 * V_74 )
{
const struct V_89 * V_92 ;
const struct V_62 * V_63 ;
char V_98 [ 32 ] , V_129 [ 32 ] ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
if ( ! V_92 -> V_98 )
snprintf ( V_98 , sizeof( V_98 ) , L_19 ) ;
else
snprintf ( V_98 , sizeof( V_98 ) , L_20 ,
V_92 -> V_98 ) ;
if ( V_74 -> V_95 & V_96 )
snprintf ( V_129 , sizeof( V_129 ) , L_21 ,
V_63 -> V_73 ,
F_54 ( V_4 , V_74 ) ) ;
else
snprintf ( V_129 , sizeof( V_129 ) , L_22 ,
V_63 -> V_73 ) ;
F_6 ( L_23 ,
V_128 -> V_118 ) ;
F_6 ( L_24 ,
V_63 -> V_71 , V_63 -> V_70 ,
V_129 , V_98 ,
V_92 -> V_97 ) ;
}
static void F_72 ( const struct V_1 * V_4 ,
struct V_127 * V_128 ,
const struct V_34 * V_74 )
{
return;
}
static void F_73 ( struct V_3 * V_3 ,
enum V_124 V_58 ,
struct V_127 * V_128 )
{
T_1 V_95 , V_130 = 0 ;
const struct V_34 * V_74 = NULL ;
const struct V_89 * V_92 = NULL ;
const struct V_62 * V_63 = NULL ;
struct V_3 * V_131 = NULL ;
struct V_16 * V_19 = F_10 () ;
const struct V_1 * V_4 ;
T_1 V_73 ;
V_131 = F_74 ( V_19 -> V_132 ) ;
V_95 = V_128 -> V_133 ;
V_74 = F_70 ( V_3 , F_69 ( V_128 -> V_118 ) ) ;
if ( F_75 ( V_74 ) ) {
if ( V_58 == V_59 &&
F_76 ( V_74 ) == - V_123 )
return;
if ( V_19 -> V_58 == V_126 &&
V_131 && V_131 == V_3 &&
V_131 -> V_134 & V_135 ) {
F_6 ( L_25 ,
V_128 -> V_118 ) ;
V_128 -> V_133 |= V_136 ;
V_128 -> V_95 = V_128 -> V_133 ;
} else {
F_6 ( L_26 ,
V_128 -> V_118 ) ;
V_128 -> V_95 |= V_136 ;
}
return;
}
V_4 = F_53 ( V_3 ) ;
F_72 ( V_4 , V_128 , V_74 ) ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
V_73 = V_63 -> V_73 ;
if ( V_74 -> V_95 & V_96 )
V_73 = F_54 ( V_4 , V_74 ) ;
if ( V_73 < F_69 ( 40 ) )
V_130 = V_137 ;
if ( V_73 < F_69 ( 80 ) )
V_130 |= V_138 ;
if ( V_73 < F_69 ( 160 ) )
V_130 |= V_139 ;
if ( V_19 -> V_58 == V_126 &&
V_131 && V_131 == V_3 &&
V_131 -> V_134 & V_135 ) {
V_128 -> V_95 = V_128 -> V_133 =
F_67 ( V_74 -> V_95 ) | V_130 ;
V_128 -> V_98 = V_128 -> V_140 =
( int ) F_77 ( V_92 -> V_98 ) ;
V_128 -> V_141 = V_128 -> V_142 = V_128 -> V_143 =
( int ) F_78 ( V_92 -> V_97 ) ;
if ( V_128 -> V_95 & V_113 ) {
V_128 -> V_99 = V_144 ;
if ( V_74 -> V_99 )
V_128 -> V_99 = V_74 -> V_99 ;
}
return;
}
V_128 -> V_145 = V_146 ;
V_128 -> V_147 = V_148 ;
V_128 -> V_149 = false ;
V_128 -> V_95 = V_95 | V_130 | F_67 ( V_74 -> V_95 ) ;
V_128 -> V_98 =
F_79 ( int , V_128 -> V_140 ,
F_77 ( V_92 -> V_98 ) ) ;
V_128 -> V_141 = ( int ) F_78 ( V_92 -> V_97 ) ;
if ( V_128 -> V_95 & V_113 ) {
if ( V_74 -> V_99 )
V_128 -> V_99 = V_74 -> V_99 ;
else
V_128 -> V_99 = V_144 ;
}
if ( V_128 -> V_143 ) {
if ( V_58 == V_59 &&
V_3 -> V_134 & V_150 )
V_128 -> V_142 = V_128 -> V_141 ;
else
V_128 -> V_142 = F_63 ( V_128 -> V_143 ,
V_128 -> V_141 ) ;
} else
V_128 -> V_142 = V_128 -> V_141 ;
}
static void F_80 ( struct V_3 * V_3 ,
enum V_124 V_58 ,
struct V_151 * V_152 )
{
unsigned int V_32 ;
if ( ! V_152 )
return;
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ )
F_73 ( V_3 , V_58 , & V_152 -> V_154 [ V_32 ] ) ;
}
static bool F_81 ( struct V_16 * V_18 )
{
if ( V_18 -> V_58 != V_60 )
return false ;
return V_18 -> V_155 == V_156 ;
}
static bool F_82 ( struct V_16 * V_18 )
{
if ( V_18 -> V_58 != V_60 )
return false ;
return V_18 -> V_155 == V_157 ;
}
bool F_83 ( void )
{
return F_81 ( F_10 () ) ;
}
static enum V_54
F_84 ( struct V_16 * V_158 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_159 )
return V_55 ;
if ( F_81 ( V_19 ) &&
! F_27 ( V_158 -> V_26 ) )
return V_160 ;
return V_56 ;
}
static bool F_85 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_161 & V_162 ) ;
}
static int F_84 ( struct V_16 * V_158 )
{
return V_55 ;
}
static bool F_85 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_86 ( struct V_3 * V_3 )
{
if ( V_3 -> V_134 & V_135 &&
! ( V_3 -> V_134 & V_163 ) )
return true ;
return false ;
}
static bool F_87 ( struct V_3 * V_3 ,
enum V_124 V_58 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_19 ) {
F_6 ( L_27
L_28 ,
F_71 ( V_58 ) ) ;
return true ;
}
if ( V_58 == V_125 &&
V_3 -> V_134 & V_163 ) {
F_6 ( L_27
L_29
L_30 ,
F_71 ( V_58 ) ) ;
return true ;
}
if ( F_86 ( V_3 ) && ! V_3 -> V_4 &&
V_58 != V_59 &&
! F_21 ( V_19 -> V_26 ) ) {
F_6 ( L_27
L_31
L_32 ,
F_71 ( V_58 ) ) ;
return true ;
}
if ( F_81 ( V_19 ) )
return F_85 ( V_3 ) ;
return false ;
}
static bool F_88 ( struct V_3 * V_3 )
{
const struct V_1 * V_164 = F_1 () ;
const struct V_1 * V_165 = F_3 ( V_3 ) ;
struct V_16 * V_19 = F_10 () ;
if ( F_21 ( V_164 -> V_26 ) || ( V_165 && F_21 ( V_165 -> V_26 ) ) )
return true ;
if ( V_19 && V_19 -> V_58 != V_59 &&
V_3 -> V_134 & V_163 )
return true ;
return false ;
}
static void F_89 ( struct V_3 * V_3 , unsigned int V_166 ,
struct V_167 * V_167 )
{
struct V_151 * V_152 ;
struct V_127 * V_128 ;
bool V_168 = false ;
struct V_127 V_169 ;
V_152 = V_3 -> V_170 [ V_167 -> V_128 . V_171 ] ;
V_128 = & V_152 -> V_154 [ V_166 ] ;
if ( F_90 ( V_128 -> V_118 != V_167 -> V_128 . V_118 ) )
return;
if ( V_128 -> V_149 )
return;
V_128 -> V_149 = true ;
if ( ! F_88 ( V_3 ) )
return;
if ( V_3 -> V_134 & V_172 )
return;
V_169 . V_118 = V_128 -> V_118 ;
V_169 . V_95 = V_128 -> V_95 ;
if ( V_128 -> V_95 & V_111 ) {
V_128 -> V_95 &= ~ V_111 ;
V_168 = true ;
}
if ( V_168 )
F_91 ( V_3 , & V_169 , V_128 ) ;
}
static void F_92 ( struct V_3 * V_3 ,
struct V_167 * V_167 )
{
unsigned int V_32 ;
struct V_151 * V_152 ;
if ( ! V_3 -> V_170 [ V_167 -> V_128 . V_171 ] )
return;
V_152 = V_3 -> V_170 [ V_167 -> V_128 . V_171 ] ;
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ )
F_89 ( V_3 , V_32 , V_167 ) ;
}
static void F_93 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_151 * V_152 ;
struct V_167 * V_167 ;
F_94 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_170 [ V_167 -> V_128 . V_171 ] )
continue;
V_152 = V_3 -> V_170 [ V_167 -> V_128 . V_171 ] ;
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ )
F_89 ( V_3 , V_32 , V_167 ) ;
}
}
static void F_95 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_93 ( V_3 ) ;
}
static bool F_96 ( struct V_127 * V_128 )
{
if ( ! V_128 )
return false ;
if ( V_128 -> V_95 & V_136 )
return false ;
if ( ( V_128 -> V_95 & V_137 ) == V_137 )
return false ;
return true ;
}
static void F_97 ( struct V_3 * V_3 ,
struct V_127 * V_173 )
{
struct V_151 * V_152 = V_3 -> V_170 [ V_173 -> V_171 ] ;
struct V_127 * V_174 = NULL , * V_175 = NULL ;
unsigned int V_32 ;
if ( ! F_96 ( V_173 ) ) {
V_173 -> V_95 |= V_137 ;
return;
}
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ ) {
struct V_127 * V_176 = & V_152 -> V_154 [ V_32 ] ;
if ( V_176 -> V_118 == ( V_173 -> V_118 - 20 ) )
V_174 = V_176 ;
if ( V_176 -> V_118 == ( V_173 -> V_118 + 20 ) )
V_175 = V_176 ;
}
if ( ! F_96 ( V_174 ) )
V_173 -> V_95 |= V_177 ;
else
V_173 -> V_95 &= ~ V_177 ;
if ( ! F_96 ( V_175 ) )
V_173 -> V_95 |= V_178 ;
else
V_173 -> V_95 &= ~ V_178 ;
}
static void F_98 ( struct V_3 * V_3 ,
struct V_151 * V_152 )
{
unsigned int V_32 ;
if ( ! V_152 )
return;
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ )
F_97 ( V_3 , & V_152 -> V_154 [ V_32 ] ) ;
}
static void F_99 ( struct V_3 * V_3 )
{
enum V_179 V_171 ;
if ( ! V_3 )
return;
for ( V_171 = 0 ; V_171 < V_180 ; V_171 ++ )
F_98 ( V_3 , V_3 -> V_170 [ V_171 ] ) ;
}
static void F_100 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_181 )
V_3 -> V_181 ( V_3 , V_18 ) ;
}
static void F_101 ( struct V_3 * V_3 ,
enum V_124 V_58 )
{
enum V_179 V_171 ;
struct V_16 * V_19 = F_10 () ;
if ( F_87 ( V_3 , V_58 ) ) {
if ( V_58 == V_125 &&
V_3 -> V_134 & V_163 )
F_100 ( V_3 , V_19 ) ;
return;
}
V_19 -> V_6 = F_1 () -> V_6 ;
for ( V_171 = 0 ; V_171 < V_180 ; V_171 ++ )
F_80 ( V_3 , V_58 , V_3 -> V_170 [ V_171 ] ) ;
F_95 ( V_3 ) ;
F_99 ( V_3 ) ;
F_100 ( V_3 , V_19 ) ;
}
static void F_102 ( enum V_124 V_58 )
{
struct V_182 * V_183 ;
struct V_3 * V_3 ;
F_18 () ;
F_94 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_183 -> V_3 ;
F_101 ( V_3 , V_58 ) ;
}
}
static void F_103 ( struct V_3 * V_3 ,
struct V_127 * V_128 ,
const struct V_1 * V_4 )
{
T_1 V_130 = 0 ;
const struct V_34 * V_74 = NULL ;
const struct V_89 * V_92 = NULL ;
const struct V_62 * V_63 = NULL ;
T_1 V_73 ;
V_74 = F_68 ( V_3 , F_69 ( V_128 -> V_118 ) ,
V_4 ) ;
if ( F_75 ( V_74 ) ) {
F_6 ( L_33 ,
V_128 -> V_118 ) ;
V_128 -> V_133 |= V_136 ;
V_128 -> V_95 = V_128 -> V_133 ;
return;
}
F_72 ( V_4 , V_128 , V_74 ) ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
V_73 = V_63 -> V_73 ;
if ( V_74 -> V_95 & V_96 )
V_73 = F_54 ( V_4 , V_74 ) ;
if ( V_73 < F_69 ( 40 ) )
V_130 = V_137 ;
if ( V_73 < F_69 ( 80 ) )
V_130 |= V_138 ;
if ( V_73 < F_69 ( 160 ) )
V_130 |= V_139 ;
V_128 -> V_95 |= F_67 ( V_74 -> V_95 ) | V_130 ;
V_128 -> V_98 = ( int ) F_77 ( V_92 -> V_98 ) ;
V_128 -> V_141 = V_128 -> V_142 =
( int ) F_78 ( V_92 -> V_97 ) ;
}
static void F_104 ( struct V_3 * V_3 ,
struct V_151 * V_152 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_152 )
return;
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ )
F_103 ( V_3 , & V_152 -> V_154 [ V_32 ] , V_4 ) ;
}
void F_105 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_179 V_171 ;
unsigned int V_184 = 0 ;
F_29 ( ! ( V_3 -> V_134 & V_163 ) ,
L_34 ) ;
V_3 -> V_134 |= V_163 ;
for ( V_171 = 0 ; V_171 < V_180 ; V_171 ++ ) {
if ( ! V_3 -> V_170 [ V_171 ] )
continue;
F_104 ( V_3 , V_3 -> V_170 [ V_171 ] , V_4 ) ;
V_184 ++ ;
}
F_20 ( ! V_184 ) ;
}
static void F_106 ( void )
{
bool V_185 = false ;
struct V_16 * V_19 = F_10 () ;
V_19 -> V_57 = true ;
F_107 ( & V_186 ) ;
if ( ! F_36 ( & V_187 ) )
V_185 = true ;
F_108 ( & V_186 ) ;
if ( V_19 -> V_58 == V_60 )
F_109 ( & V_188 ) ;
if ( V_185 )
F_45 ( & V_189 ) ;
}
static enum V_54
F_110 ( struct V_16 * V_190 )
{
V_190 -> V_191 = false ;
V_190 -> V_57 = false ;
F_15 ( V_190 ) ;
return F_51 ( V_190 ) ;
}
static enum V_54
F_111 ( struct V_16 * V_192 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_82 ( V_192 ) ) {
V_193 = true ;
return V_194 ;
}
if ( F_81 ( V_192 ) )
return F_84 ( V_192 ) ;
if ( F_81 ( V_19 ) )
return V_55 ;
if ( V_19 -> V_58 == V_59 )
return V_195 ;
if ( V_19 -> V_58 == V_60 &&
V_19 -> V_191 )
return V_55 ;
if ( ( V_19 -> V_58 == V_125 ||
V_19 -> V_58 == V_126 ||
V_19 -> V_58 == V_60 ) &&
F_27 ( V_19 -> V_26 ) )
return V_55 ;
if ( ! F_27 ( V_192 -> V_26 ) )
return V_160 ;
return V_56 ;
}
static enum V_54
F_112 ( struct V_16 * V_192 )
{
enum V_54 V_196 ;
V_196 = F_111 ( V_192 ) ;
if ( V_196 == V_55 ||
V_196 == V_160 ||
V_196 == V_194 ) {
F_12 ( V_192 ) ;
return V_196 ;
}
V_192 -> V_191 = V_196 == V_195 ;
V_192 -> V_57 = false ;
F_15 ( V_192 ) ;
V_29 [ 0 ] = V_192 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_192 -> V_26 [ 1 ] ;
return F_51 ( V_192 ) ;
}
static enum V_54
F_113 ( struct V_16 * V_197 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_58 == V_125 ) {
if ( F_27 ( V_197 -> V_26 ) )
return V_56 ;
return V_160 ;
}
if ( V_19 -> V_58 == V_126 &&
! F_27 ( V_197 -> V_26 ) )
return V_160 ;
return V_195 ;
}
static enum V_54
F_114 ( struct V_3 * V_3 ,
struct V_16 * V_197 )
{
const struct V_1 * V_4 ;
enum V_54 V_196 ;
V_196 = F_113 ( V_197 ) ;
switch ( V_196 ) {
case V_56 :
break;
case V_55 :
case V_194 :
F_12 ( V_197 ) ;
return V_196 ;
case V_195 :
case V_160 :
V_4 = F_30 ( F_1 () ) ;
if ( F_75 ( V_4 ) ) {
F_12 ( V_197 ) ;
return V_55 ;
}
F_16 ( V_3 -> V_4 , V_4 ) ;
}
V_197 -> V_191 = V_196 == V_195 ;
V_197 -> V_57 = false ;
F_15 ( V_197 ) ;
if ( V_196 == V_160 ) {
F_115 ( V_197 ) ;
F_106 () ;
return V_196 ;
}
return F_51 ( V_197 ) ;
}
static enum V_54
F_116 ( struct V_3 * V_3 ,
struct V_16 * V_198 )
{
struct V_3 * V_199 = NULL ;
struct V_16 * V_19 = F_10 () ;
if ( F_81 ( V_19 ) ) {
if ( F_27 ( V_198 -> V_26 ) )
return V_55 ;
return V_160 ;
} else {
if ( V_3 -> V_134 & V_200 )
return V_55 ;
}
if ( F_117 ( ! F_25 ( V_198 -> V_26 ) ) )
return - V_100 ;
if ( V_19 -> V_58 != V_59 )
return V_56 ;
V_199 = F_74 ( V_19 -> V_132 ) ;
if ( V_199 != V_3 ) {
if ( F_27 ( V_198 -> V_26 ) )
return V_55 ;
return V_160 ;
}
if ( F_20 ( F_27 ( V_198 -> V_26 ) ) )
return V_56 ;
return V_160 ;
}
static enum V_54
F_118 ( struct V_3 * V_3 ,
struct V_16 * V_198 )
{
enum V_54 V_196 ;
V_196 = F_116 ( V_3 , V_198 ) ;
switch ( V_196 ) {
case V_56 :
break;
case V_55 :
case V_194 :
case V_160 :
F_12 ( V_198 ) ;
return V_196 ;
case V_195 :
F_12 ( V_198 ) ;
F_47 ( 1 , L_35 ) ;
return V_55 ;
}
V_198 -> V_191 = false ;
V_198 -> V_57 = false ;
F_15 ( V_198 ) ;
return F_51 ( V_198 ) ;
}
static void F_119 ( struct V_16 * V_201 )
{
struct V_3 * V_3 = NULL ;
enum V_54 V_196 ;
if ( V_201 -> V_132 != V_202 )
V_3 = F_74 ( V_201 -> V_132 ) ;
switch ( V_201 -> V_58 ) {
case V_125 :
F_110 ( V_201 ) ;
return;
case V_60 :
V_196 = F_112 ( V_201 ) ;
if ( V_196 == V_55 ||
V_196 == V_160 ||
V_196 == V_194 )
return;
F_120 ( V_203 ,
& V_188 , F_121 ( 3142 ) ) ;
return;
case V_126 :
if ( ! V_3 )
goto V_204;
V_196 = F_114 ( V_3 , V_201 ) ;
break;
case V_59 :
if ( ! V_3 )
goto V_204;
V_196 = F_118 ( V_3 , V_201 ) ;
break;
default:
F_29 ( 1 , L_36 , V_201 -> V_58 ) ;
goto V_204;
}
if ( V_196 == V_160 && V_3 &&
V_3 -> V_134 & V_135 )
F_101 ( V_3 , V_201 -> V_58 ) ;
return;
V_204:
F_12 ( V_201 ) ;
}
static void F_122 ( void )
{
struct V_16 * V_201 , * V_19 ;
V_19 = F_10 () ;
if ( V_19 && ! V_19 -> V_57 ) {
F_119 ( V_19 ) ;
return;
}
F_107 ( & V_186 ) ;
if ( F_36 ( & V_187 ) ) {
F_108 ( & V_186 ) ;
return;
}
V_201 = F_37 ( & V_187 ,
struct V_16 ,
V_45 ) ;
F_123 ( & V_201 -> V_45 ) ;
F_108 ( & V_186 ) ;
F_119 ( V_201 ) ;
}
static void F_124 ( void )
{
struct V_182 * V_183 ;
struct V_167 * V_205 , * V_65 ;
F_125 ( & V_206 ) ;
F_126 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_123 ( & V_205 -> V_45 ) ;
F_94 (rdev, &cfg80211_rdev_list, list)
F_92 ( & V_183 -> V_3 , V_205 ) ;
F_44 ( & V_205 -> V_45 , & V_207 ) ;
}
F_127 ( & V_206 ) ;
}
static void F_128 ( struct V_38 * V_39 )
{
F_34 () ;
F_122 () ;
F_124 () ;
F_42 () ;
}
static void F_129 ( struct V_16 * V_18 )
{
V_18 -> V_26 [ 0 ] = toupper ( V_18 -> V_26 [ 0 ] ) ;
V_18 -> V_26 [ 1 ] = toupper ( V_18 -> V_26 [ 1 ] ) ;
F_107 ( & V_186 ) ;
F_44 ( & V_18 -> V_45 , & V_187 ) ;
F_108 ( & V_186 ) ;
F_45 ( & V_189 ) ;
}
static int F_130 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_125 ;
F_129 ( V_18 ) ;
return 0 ;
}
int F_131 ( const char * V_26 ,
enum V_208 V_155 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_100 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_132 = V_202 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_60 ;
V_18 -> V_155 = V_155 ;
F_129 ( V_18 ) ;
return 0 ;
}
int F_132 ( void )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_132 = V_202 ;
V_18 -> V_58 = V_60 ;
V_18 -> V_155 = V_157 ;
F_129 ( V_18 ) ;
return 0 ;
}
int F_133 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_100 ;
V_3 -> V_134 &= ~ V_163 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_132 = F_134 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_126 ;
F_129 ( V_18 ) ;
return 0 ;
}
void F_135 ( struct V_3 * V_3 , enum V_179 V_171 ,
const T_2 * V_209 , T_2 V_210 )
{
char V_26 [ 2 ] ;
enum V_211 V_50 = V_212 ;
struct V_16 * V_18 = NULL , * V_19 ;
if ( V_210 & 0x01 )
return;
if ( V_210 < V_213 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_209 [ 0 ] ;
V_26 [ 1 ] = V_209 [ 1 ] ;
if ( V_209 [ 2 ] == 'I' )
V_50 = V_214 ;
else if ( V_209 [ 2 ] == 'O' )
V_50 = V_215 ;
F_136 () ;
V_19 = F_10 () ;
if ( F_117 ( ! V_19 ) )
goto V_12;
if ( V_19 -> V_58 == V_59 &&
V_19 -> V_132 != V_202 )
goto V_12;
V_18 -> V_132 = F_134 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_59 ;
V_18 -> V_216 = V_50 ;
F_129 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_137 () ;
}
static void F_138 ( char * V_26 , bool V_217 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_217 ) {
F_6 ( L_37 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_218 ) ) {
F_6 ( L_38 ,
V_218 [ 0 ] , V_218 [ 1 ] ) ;
V_26 [ 0 ] = V_218 [ 0 ] ;
V_26 [ 1 ] = V_218 [ 1 ] ;
}
} else {
F_6 ( L_39 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_218 ) ) {
F_6 ( L_38 ,
V_218 [ 0 ] , V_218 [ 1 ] ) ;
V_26 [ 0 ] = V_218 [ 0 ] ;
V_26 [ 1 ] = V_218 [ 1 ] ;
} else
F_6 ( L_40 ) ;
}
static void F_139 ( struct V_3 * V_3 )
{
struct V_151 * V_152 ;
enum V_179 V_171 ;
struct V_127 * V_128 ;
int V_32 ;
for ( V_171 = 0 ; V_171 < V_180 ; V_171 ++ ) {
V_152 = V_3 -> V_170 [ V_171 ] ;
if ( ! V_152 )
continue;
for ( V_32 = 0 ; V_32 < V_152 -> V_153 ; V_32 ++ ) {
V_128 = & V_152 -> V_154 [ V_32 ] ;
V_128 -> V_95 = V_128 -> V_133 ;
V_128 -> V_98 = V_128 -> V_140 ;
V_128 -> V_142 = V_128 -> V_143 ;
V_128 -> V_149 = false ;
}
}
}
static void F_140 ( bool V_217 )
{
char V_26 [ 2 ] ;
char V_219 [ 2 ] ;
struct V_167 * V_167 , * V_220 ;
struct V_16 * V_201 , * V_65 ;
F_141 ( V_221 ) ;
struct V_182 * V_183 ;
F_18 () ;
V_193 = false ;
F_17 ( true , & V_24 ) ;
F_138 ( V_26 , V_217 ) ;
F_107 ( & V_186 ) ;
F_126 (reg_request, tmp, &reg_requests_list, list) {
if ( V_201 -> V_58 != V_60 )
continue;
F_142 ( & V_201 -> V_45 , & V_221 ) ;
}
F_108 ( & V_186 ) ;
F_125 ( & V_206 ) ;
F_126 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_167 -> V_45 ) ;
F_13 ( V_167 ) ;
}
F_127 ( & V_206 ) ;
F_126 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_167 -> V_45 ) ;
F_13 ( V_167 ) ;
}
V_219 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_219 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_94 (rdev, &cfg80211_rdev_list, list) {
if ( V_183 -> V_3 . V_134 & V_163 )
F_139 ( & V_183 -> V_3 ) ;
}
F_130 ( V_219 ) ;
if ( F_25 ( V_26 ) )
F_131 ( V_29 , V_222 ) ;
F_107 ( & V_186 ) ;
F_143 ( & V_221 , & V_187 ) ;
F_108 ( & V_186 ) ;
F_6 ( L_41 ) ;
F_45 ( & V_189 ) ;
}
void F_144 ( void )
{
F_6 ( L_42 ) ;
F_140 ( false ) ;
}
static bool F_145 ( T_3 V_223 )
{
if ( V_223 == F_146 ( 12 , V_224 ) ||
V_223 == F_146 ( 13 , V_224 ) ||
V_223 == F_146 ( 14 , V_224 ) )
return true ;
return false ;
}
static bool F_147 ( struct V_127 * V_225 )
{
struct V_167 * V_205 ;
F_94 (pending_beacon, &reg_pending_beacons, list)
if ( V_225 -> V_118 ==
V_205 -> V_128 . V_118 )
return true ;
return false ;
}
int F_148 ( struct V_3 * V_3 ,
struct V_127 * V_225 ,
T_4 V_226 )
{
struct V_167 * V_167 ;
bool V_227 ;
if ( V_225 -> V_149 ||
V_225 -> V_95 & V_113 ||
( V_225 -> V_171 == V_224 &&
! F_145 ( V_225 -> V_118 ) ) )
return 0 ;
F_125 ( & V_206 ) ;
V_227 = F_147 ( V_225 ) ;
F_127 ( & V_206 ) ;
if ( V_227 )
return 0 ;
V_167 = F_31 ( sizeof( struct V_167 ) , V_226 ) ;
if ( ! V_167 )
return - V_36 ;
F_6 ( L_43 ,
V_225 -> V_118 ,
F_149 ( V_225 -> V_118 ) ,
F_150 ( V_3 ) ) ;
memcpy ( & V_167 -> V_128 , V_225 ,
sizeof( struct V_127 ) ) ;
F_125 ( & V_206 ) ;
F_44 ( & V_167 -> V_45 , & V_228 ) ;
F_127 ( & V_206 ) ;
F_45 ( & V_189 ) ;
return 0 ;
}
static void F_151 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_74 = NULL ;
const struct V_62 * V_63 = NULL ;
const struct V_89 * V_92 = NULL ;
char V_129 [ 32 ] , V_229 [ 32 ] ;
F_49 ( L_44 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_74 = & V_25 -> V_37 [ V_32 ] ;
V_63 = & V_74 -> V_63 ;
V_92 = & V_74 -> V_92 ;
if ( V_74 -> V_95 & V_96 )
snprintf ( V_129 , sizeof( V_129 ) , L_21 ,
V_63 -> V_73 ,
F_54 ( V_25 , V_74 ) ) ;
else
snprintf ( V_129 , sizeof( V_129 ) , L_22 ,
V_63 -> V_73 ) ;
if ( V_74 -> V_95 & V_112 )
F_152 ( V_229 , sizeof( V_229 ) , L_45 ,
V_74 -> V_99 / 1000 ) ;
else
F_152 ( V_229 , sizeof( V_229 ) , L_19 ) ;
if ( V_92 -> V_98 )
F_49 ( L_46 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_129 ,
V_92 -> V_98 ,
V_92 -> V_97 ,
V_229 ) ;
else
F_49 ( L_47 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_129 ,
V_92 -> V_97 ,
V_229 ) ;
}
}
bool F_153 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
F_6 ( L_48 ,
V_6 ) ;
return false ;
}
}
static void F_154 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_19 -> V_58 == V_59 ) {
struct V_182 * V_183 ;
V_183 = F_155 ( V_19 -> V_132 ) ;
if ( V_183 ) {
F_49 ( L_49 ,
V_183 -> V_230 [ 0 ] ,
V_183 -> V_230 [ 1 ] ) ;
} else
F_49 ( L_50 ) ;
} else
F_49 ( L_50 ) ;
} else if ( F_21 ( V_25 -> V_26 ) ) {
F_49 ( L_51 ) ;
} else {
if ( F_23 ( V_25 -> V_26 ) )
F_49 ( L_52 ) ;
else {
if ( F_81 ( V_19 ) )
F_49 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_49 ( L_54 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_49 ( L_55 , F_4 ( V_25 -> V_6 ) ) ;
F_151 ( V_25 ) ;
}
static void F_156 ( const struct V_1 * V_25 )
{
F_49 ( L_56 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_151 ( V_25 ) ;
}
static int F_157 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_100 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_158 ( const struct V_1 * V_25 ,
struct V_16 * V_192 )
{
const struct V_1 * V_231 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_232 ;
if ( ! F_56 ( V_25 ) ) {
F_159 ( L_57 ) ;
F_156 ( V_25 ) ;
return - V_100 ;
}
if ( ! V_192 -> V_191 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_231 = F_66 ( V_25 , F_1 () ) ;
if ( ! V_231 )
return - V_100 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_231 ) ;
return 0 ;
}
static int F_160 ( const struct V_1 * V_25 ,
struct V_16 * V_197 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_231 = NULL ;
const struct V_1 * V_65 ;
struct V_3 * V_131 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_100 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_232 ;
if ( ! F_56 ( V_25 ) ) {
F_159 ( L_57 ) ;
F_156 ( V_25 ) ;
return - V_100 ;
}
V_131 = F_74 ( V_197 -> V_132 ) ;
if ( ! V_131 ) {
F_120 ( V_203 ,
& V_188 , 0 ) ;
return - V_233 ;
}
if ( ! V_197 -> V_191 ) {
if ( V_131 -> V_4 )
return - V_232 ;
V_4 = F_30 ( V_25 ) ;
if ( F_75 ( V_4 ) )
return F_76 ( V_4 ) ;
F_16 ( V_131 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_231 = F_66 ( V_25 , F_1 () ) ;
if ( ! V_231 )
return - V_100 ;
V_65 = F_3 ( V_131 ) ;
F_16 ( V_131 -> V_4 , V_25 ) ;
F_8 ( V_65 ) ;
V_25 = NULL ;
F_17 ( false , V_231 ) ;
return 0 ;
}
static int F_161 ( const struct V_1 * V_25 ,
struct V_16 * V_198 )
{
struct V_3 * V_131 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_100 ;
if ( ! F_56 ( V_25 ) ) {
F_159 ( L_57 ) ;
F_156 ( V_25 ) ;
return - V_100 ;
}
V_131 = F_74 ( V_198 -> V_132 ) ;
if ( ! V_131 ) {
F_120 ( V_203 ,
& V_188 , 0 ) ;
return - V_233 ;
}
if ( V_198 -> V_191 )
return - V_100 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_41 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 ;
bool V_234 = false ;
int V_14 ;
if ( ! F_52 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_100 ;
}
V_19 = F_10 () ;
switch ( V_19 -> V_58 ) {
case V_125 :
V_14 = F_157 ( V_25 ) ;
break;
case V_60 :
V_14 = F_158 ( V_25 , V_19 ) ;
V_234 = true ;
break;
case V_126 :
V_14 = F_160 ( V_25 , V_19 ) ;
break;
case V_59 :
V_14 = F_161 ( V_25 , V_19 ) ;
break;
default:
F_29 ( 1 , L_36 , V_19 -> V_58 ) ;
return - V_100 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_232 :
F_106 () ;
break;
default:
F_140 ( V_234 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_19 -> V_191 && V_25 != F_1 () ) )
return - V_100 ;
F_102 ( V_19 -> V_58 ) ;
F_154 ( F_1 () ) ;
F_115 ( V_19 ) ;
F_106 () ;
return 0 ;
}
void F_162 ( struct V_3 * V_3 )
{
struct V_16 * V_19 ;
if ( ! F_85 ( V_3 ) )
V_159 ++ ;
V_19 = F_10 () ;
F_101 ( V_3 , V_19 -> V_58 ) ;
}
void F_163 ( struct V_3 * V_3 )
{
struct V_3 * V_131 = NULL ;
struct V_16 * V_19 ;
V_19 = F_10 () ;
if ( ! F_85 ( V_3 ) )
V_159 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_164 ( V_3 -> V_4 , NULL ) ;
if ( V_19 )
V_131 = F_74 ( V_19 -> V_132 ) ;
if ( ! V_131 || V_131 != V_3 )
return;
V_19 -> V_132 = V_202 ;
V_19 -> V_216 = V_212 ;
}
static void F_165 ( struct V_38 * V_39 )
{
F_6 ( L_58 ) ;
F_34 () ;
F_140 ( true ) ;
F_42 () ;
}
int F_166 ( int V_223 )
{
if ( V_223 >= 5150 && V_223 <= 5250 )
return 0 ;
if ( V_223 > 5250 && V_223 <= 5350 )
return 1 ;
if ( V_223 > 5350 && V_223 <= 5470 )
return 2 ;
if ( V_223 > 5470 && V_223 <= 5725 )
return 3 ;
if ( V_223 > 5725 && V_223 <= 5825 )
return 4 ;
return - V_100 ;
}
bool F_167 ( void )
{
return V_193 ;
}
int T_5 F_168 ( void )
{
int V_235 = 0 ;
V_51 = F_169 ( L_59 , 0 , NULL , 0 ) ;
if ( F_75 ( V_51 ) )
return F_76 ( V_51 ) ;
F_170 ( & V_186 ) ;
F_170 ( & V_206 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_235 = F_130 ( V_23 -> V_26 ) ;
if ( V_235 ) {
if ( V_235 == - V_36 )
return V_235 ;
F_159 ( L_60 ) ;
}
if ( ! F_21 ( V_218 ) )
F_131 ( V_218 ,
V_222 ) ;
return 0 ;
}
void F_171 ( void )
{
struct V_16 * V_201 , * V_65 ;
struct V_167 * V_167 , * V_220 ;
F_172 ( & V_189 ) ;
F_173 ( & V_188 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_42 () ;
F_174 ( & V_51 -> V_13 , true ) ;
F_175 ( V_51 ) ;
F_126 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_167 -> V_45 ) ;
F_13 ( V_167 ) ;
}
F_126 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_167 -> V_45 ) ;
F_13 ( V_167 ) ;
}
F_126 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_201 -> V_45 ) ;
F_13 ( V_201 ) ;
}
}
