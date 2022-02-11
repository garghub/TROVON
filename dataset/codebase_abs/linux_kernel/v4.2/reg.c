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
F_41 ( V_42 , V_48 ) ;
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
F_45 ( & V_49 ) ;
}
static void F_46 ( void )
{
F_47 ( ! V_46 , L_10 ) ;
}
static inline void F_46 ( void ) {}
static inline void F_43 ( const char * V_26 ) {}
static int F_48 ( const char * V_26 )
{
char V_50 [ 12 ] ;
char * V_51 [] = { V_50 , NULL } ;
snprintf ( V_50 , sizeof( V_50 ) , L_11 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
F_43 ( V_26 ) ;
if ( V_52 > V_53 ) {
F_49 ( L_12 ) ;
return - V_54 ;
}
if ( ! F_21 ( ( char * ) V_26 ) )
F_49 ( L_13 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
else
F_49 ( L_14 ) ;
return F_50 ( & V_55 -> V_13 . V_56 , V_57 , V_51 ) ;
}
static enum V_58
F_51 ( struct V_16 * V_18 )
{
if ( F_48 ( V_18 -> V_26 ) )
return V_59 ;
F_52 ( V_60 ,
& V_61 , F_53 ( 3142 ) ) ;
return V_62 ;
}
bool F_54 ( const char * V_26 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_19 || V_19 -> V_63 )
return false ;
return F_26 ( V_19 -> V_26 , V_26 ) ;
}
static const struct V_1 * F_55 ( struct V_3 * V_3 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_64 != V_65 &&
V_19 -> V_64 != V_66 &&
V_3 -> V_4 )
return F_3 ( V_3 ) ;
return F_1 () ;
}
static unsigned int
F_56 ( const struct V_1 * V_25 ,
const struct V_34 * V_67 )
{
const struct V_68 * V_69 = & V_67 -> V_69 ;
const struct V_68 * V_70 ;
const struct V_34 * V_71 ;
T_1 V_72 , V_73 , V_74 , V_75 ;
for ( V_74 = 0 ; V_74 < V_25 -> V_33 ; V_74 ++ )
if ( V_67 == & V_25 -> V_37 [ V_74 ] )
break;
if ( V_74 == V_25 -> V_33 )
return 0 ;
V_75 = V_74 ;
while ( V_75 ) {
V_71 = & V_25 -> V_37 [ -- V_75 ] ;
V_70 = & V_71 -> V_69 ;
if ( V_70 -> V_76 < V_69 -> V_77 )
break;
V_69 = V_70 ;
}
V_72 = V_69 -> V_77 ;
V_69 = & V_67 -> V_69 ;
V_75 = V_74 ;
while ( V_75 < V_25 -> V_33 - 1 ) {
V_71 = & V_25 -> V_37 [ ++ V_75 ] ;
V_70 = & V_71 -> V_69 ;
if ( V_70 -> V_77 > V_69 -> V_76 )
break;
V_69 = V_70 ;
}
V_73 = V_69 -> V_76 ;
return V_73 - V_72 ;
}
unsigned int F_57 ( const struct V_1 * V_25 ,
const struct V_34 * V_67 )
{
unsigned int V_78 = F_56 ( V_25 , V_67 ) ;
if ( V_67 -> V_79 & V_80 )
V_78 = F_58 (unsigned int, bw, MHZ_TO_KHZ(80)) ;
if ( V_67 -> V_79 & V_81 )
V_78 = F_58 (unsigned int, bw, MHZ_TO_KHZ(40)) ;
if ( V_67 -> V_79 & V_82 &&
V_67 -> V_79 & V_83 )
V_78 = F_58 (unsigned int, bw, MHZ_TO_KHZ(20)) ;
return V_78 ;
}
static bool F_59 ( const struct V_34 * V_67 )
{
const struct V_68 * V_69 = & V_67 -> V_69 ;
T_1 V_84 ;
if ( V_69 -> V_77 <= 0 || V_69 -> V_76 <= 0 )
return false ;
if ( V_69 -> V_77 > V_69 -> V_76 )
return false ;
V_84 = V_69 -> V_76 - V_69 -> V_77 ;
if ( V_69 -> V_76 <= V_69 -> V_77 ||
V_69 -> V_85 > V_84 )
return false ;
return true ;
}
static bool F_60 ( const struct V_1 * V_25 )
{
const struct V_34 * V_86 = NULL ;
unsigned int V_32 ;
if ( ! V_25 -> V_33 )
return false ;
if ( F_20 ( V_25 -> V_33 > V_87 ) )
return false ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_86 = & V_25 -> V_37 [ V_32 ] ;
if ( ! F_59 ( V_86 ) )
return false ;
}
return true ;
}
static bool F_61 ( const struct V_68 * V_69 ,
T_1 V_88 , T_1 V_89 )
{
T_1 V_77 , V_76 ;
V_77 = V_88 - ( V_89 / 2 ) ;
V_76 = V_88 + ( V_89 / 2 ) ;
if ( V_77 >= V_69 -> V_77 &&
V_76 <= V_69 -> V_76 )
return true ;
return false ;
}
static bool F_62 ( const struct V_68 * V_69 ,
T_1 V_90 )
{
#define F_63 1000000
T_1 V_91 = V_90 > 45 * F_63 ?
10 * F_63 : 2 * F_63 ;
if ( abs ( V_90 - V_69 -> V_77 ) <= V_91 )
return true ;
if ( abs ( V_90 - V_69 -> V_76 ) <= V_91 )
return true ;
return false ;
#undef F_63
}
static enum V_5
F_64 ( const enum V_5 V_92 ,
const enum V_5 V_93 )
{
if ( V_92 != V_93 )
return V_7 ;
return V_92 ;
}
static int F_65 ( const struct V_1 * V_94 ,
const struct V_1 * V_95 ,
const struct V_34 * V_96 ,
const struct V_34 * V_97 ,
struct V_34 * V_98 )
{
const struct V_68 * V_99 , * V_100 ;
struct V_68 * V_69 ;
const struct V_101 * V_102 , * V_103 ;
struct V_101 * V_104 ;
T_1 V_84 , V_105 , V_106 ;
V_99 = & V_96 -> V_69 ;
V_100 = & V_97 -> V_69 ;
V_69 = & V_98 -> V_69 ;
V_102 = & V_96 -> V_104 ;
V_103 = & V_97 -> V_104 ;
V_104 = & V_98 -> V_104 ;
V_69 -> V_77 = F_66 ( V_99 -> V_77 ,
V_100 -> V_77 ) ;
V_69 -> V_76 = F_67 ( V_99 -> V_76 ,
V_100 -> V_76 ) ;
V_105 = V_99 -> V_85 ;
V_106 = V_100 -> V_85 ;
if ( V_96 -> V_79 & V_107 )
V_105 = F_57 ( V_94 , V_96 ) ;
if ( V_97 -> V_79 & V_107 )
V_106 = F_57 ( V_95 , V_97 ) ;
V_69 -> V_85 = F_67 ( V_105 , V_106 ) ;
V_98 -> V_79 = V_96 -> V_79 | V_97 -> V_79 ;
if ( ( V_96 -> V_79 & V_107 ) &&
( V_97 -> V_79 & V_107 ) )
V_98 -> V_79 |= V_107 ;
else
V_98 -> V_79 &= ~ V_107 ;
V_84 = V_69 -> V_76 - V_69 -> V_77 ;
if ( V_69 -> V_85 > V_84 )
V_69 -> V_85 = V_84 ;
V_104 -> V_108 = F_67 ( V_102 -> V_108 ,
V_103 -> V_108 ) ;
V_104 -> V_109 = F_67 ( V_102 -> V_109 ,
V_103 -> V_109 ) ;
V_98 -> V_110 = F_66 ( V_96 -> V_110 ,
V_97 -> V_110 ) ;
if ( ! F_59 ( V_98 ) )
return - V_54 ;
return 0 ;
}
static bool F_68 ( struct V_34 * V_111 ,
struct V_34 * V_112 )
{
if ( V_111 -> V_79 != V_112 -> V_79 )
return false ;
if ( ( V_111 -> V_104 . V_109 >
V_112 -> V_104 . V_109 ) ||
V_111 -> V_104 . V_108 > V_112 -> V_104 . V_108 )
return false ;
if ( V_111 -> V_69 . V_77 > V_112 -> V_69 . V_77 ||
V_111 -> V_69 . V_76 < V_112 -> V_69 . V_76 )
return false ;
if ( V_111 -> V_69 . V_85 <
V_112 -> V_69 . V_85 )
return false ;
return true ;
}
static void F_69 ( struct V_34 * V_67 ,
struct V_34 * V_37 , T_1 * V_113 )
{
struct V_34 * V_114 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < * V_113 ; V_32 ++ ) {
V_114 = & V_37 [ V_32 ] ;
if ( F_68 ( V_114 , V_67 ) )
return;
if ( F_68 ( V_67 , V_114 ) ) {
memcpy ( V_114 , V_67 , sizeof( * V_67 ) ) ;
return;
}
}
memcpy ( & V_37 [ * V_113 ] , V_67 , sizeof( * V_67 ) ) ;
( * V_113 ) ++ ;
}
static struct V_1 *
F_70 ( const struct V_1 * V_94 ,
const struct V_1 * V_95 )
{
int V_14 , V_31 ;
unsigned int V_115 , V_116 ;
unsigned int V_117 = 0 ;
const struct V_34 * V_96 , * V_97 ;
struct V_34 V_98 ;
struct V_1 * V_25 ;
if ( ! V_94 || ! V_95 )
return NULL ;
for ( V_115 = 0 ; V_115 < V_94 -> V_33 ; V_115 ++ ) {
V_96 = & V_94 -> V_37 [ V_115 ] ;
for ( V_116 = 0 ; V_116 < V_95 -> V_33 ; V_116 ++ ) {
V_97 = & V_95 -> V_37 [ V_116 ] ;
if ( ! F_65 ( V_94 , V_95 , V_96 , V_97 ,
& V_98 ) )
V_117 ++ ;
}
}
if ( ! V_117 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_117 * sizeof( struct V_34 ) ;
V_25 = F_31 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_115 = 0 ; V_115 < V_94 -> V_33 ; V_115 ++ ) {
V_96 = & V_94 -> V_37 [ V_115 ] ;
for ( V_116 = 0 ; V_116 < V_95 -> V_33 ; V_116 ++ ) {
V_97 = & V_95 -> V_37 [ V_116 ] ;
V_14 = F_65 ( V_94 , V_95 , V_96 , V_97 ,
& V_98 ) ;
if ( V_14 )
continue;
F_69 ( & V_98 , V_25 -> V_37 ,
& V_25 -> V_33 ) ;
}
}
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_64 ( V_94 -> V_6 ,
V_95 -> V_6 ) ;
return V_25 ;
}
static T_1 F_71 ( T_1 V_118 )
{
T_1 V_119 = 0 ;
if ( V_118 & V_120 )
V_119 |= V_121 ;
if ( V_118 & V_122 )
V_119 |= V_123 ;
if ( V_118 & V_124 )
V_119 |= V_125 ;
if ( V_118 & V_126 )
V_119 |= V_127 ;
if ( V_118 & V_128 )
V_119 |= V_129 ;
if ( V_118 & V_82 )
V_119 |= V_130 ;
if ( V_118 & V_83 )
V_119 |= V_131 ;
if ( V_118 & V_81 )
V_119 |= V_132 ;
if ( V_118 & V_80 )
V_119 |= V_133 ;
return V_119 ;
}
static const struct V_34 *
F_72 ( struct V_3 * V_3 , T_1 V_134 ,
const struct V_1 * V_4 )
{
int V_32 ;
bool V_135 = false ;
bool V_136 = false ;
if ( ! V_4 )
return F_32 ( - V_54 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_137 ;
const struct V_68 * V_138 = NULL ;
V_137 = & V_4 -> V_37 [ V_32 ] ;
V_138 = & V_137 -> V_69 ;
if ( ! V_135 )
V_135 = F_62 ( V_138 , V_134 ) ;
V_136 = F_61 ( V_138 , V_134 , F_73 ( 20 ) ) ;
if ( V_135 && V_136 )
return V_137 ;
}
if ( ! V_135 )
return F_32 ( - V_139 ) ;
return F_32 ( - V_54 ) ;
}
const struct V_34 * F_74 ( struct V_3 * V_3 ,
T_1 V_134 )
{
const struct V_1 * V_4 ;
V_4 = F_55 ( V_3 ) ;
return F_72 ( V_3 , V_134 , V_4 ) ;
}
const char * F_75 ( enum V_140 V_64 )
{
switch ( V_64 ) {
case V_141 :
return L_15 ;
case V_66 :
return L_16 ;
case V_142 :
return L_17 ;
case V_65 :
return L_18 ;
default:
F_20 ( 1 ) ;
return L_19 ;
}
}
static void F_76 ( const struct V_1 * V_4 ,
struct V_143 * V_144 ,
const struct V_34 * V_86 )
{
const struct V_101 * V_104 ;
const struct V_68 * V_69 ;
char V_109 [ 32 ] , V_78 [ 32 ] ;
V_104 = & V_86 -> V_104 ;
V_69 = & V_86 -> V_69 ;
if ( ! V_104 -> V_109 )
snprintf ( V_109 , sizeof( V_109 ) , L_20 ) ;
else
snprintf ( V_109 , sizeof( V_109 ) , L_21 ,
V_104 -> V_109 ) ;
if ( V_86 -> V_79 & V_107 )
snprintf ( V_78 , sizeof( V_78 ) , L_22 ,
V_69 -> V_85 ,
F_57 ( V_4 , V_86 ) ) ;
else
snprintf ( V_78 , sizeof( V_78 ) , L_23 ,
V_69 -> V_85 ) ;
F_6 ( L_24 ,
V_144 -> V_134 ) ;
F_6 ( L_25 ,
V_69 -> V_77 , V_69 -> V_76 ,
V_78 , V_109 ,
V_104 -> V_108 ) ;
}
static void F_76 ( const struct V_1 * V_4 ,
struct V_143 * V_144 ,
const struct V_34 * V_86 )
{
return;
}
static void F_77 ( struct V_3 * V_3 ,
enum V_140 V_64 ,
struct V_143 * V_144 )
{
T_1 V_79 , V_145 = 0 ;
const struct V_34 * V_86 = NULL ;
const struct V_101 * V_104 = NULL ;
const struct V_68 * V_69 = NULL ;
struct V_3 * V_146 = NULL ;
struct V_16 * V_19 = F_10 () ;
const struct V_1 * V_4 ;
T_1 V_85 ;
V_146 = F_78 ( V_19 -> V_147 ) ;
V_79 = V_144 -> V_148 ;
V_86 = F_74 ( V_3 , F_73 ( V_144 -> V_134 ) ) ;
if ( F_79 ( V_86 ) ) {
if ( V_64 == V_65 &&
F_80 ( V_86 ) == - V_139 )
return;
if ( V_19 -> V_64 == V_142 &&
V_146 && V_146 == V_3 &&
V_146 -> V_149 & V_150 ) {
F_6 ( L_26 ,
V_144 -> V_134 ) ;
V_144 -> V_148 |= V_151 ;
V_144 -> V_79 = V_144 -> V_148 ;
} else {
F_6 ( L_27 ,
V_144 -> V_134 ) ;
V_144 -> V_79 |= V_151 ;
}
return;
}
V_4 = F_55 ( V_3 ) ;
F_76 ( V_4 , V_144 , V_86 ) ;
V_104 = & V_86 -> V_104 ;
V_69 = & V_86 -> V_69 ;
V_85 = V_69 -> V_85 ;
if ( V_86 -> V_79 & V_107 )
V_85 = F_57 ( V_4 , V_86 ) ;
if ( V_85 < F_73 ( 40 ) )
V_145 = V_152 ;
if ( V_85 < F_73 ( 80 ) )
V_145 |= V_132 ;
if ( V_85 < F_73 ( 160 ) )
V_145 |= V_133 ;
if ( V_19 -> V_64 == V_142 &&
V_146 && V_146 == V_3 &&
V_146 -> V_149 & V_150 ) {
V_144 -> V_79 = V_144 -> V_148 =
F_71 ( V_86 -> V_79 ) | V_145 ;
V_144 -> V_109 = V_144 -> V_153 =
( int ) F_81 ( V_104 -> V_109 ) ;
V_144 -> V_154 = V_144 -> V_155 = V_144 -> V_156 =
( int ) F_82 ( V_104 -> V_108 ) ;
if ( V_144 -> V_79 & V_123 ) {
V_144 -> V_110 = V_157 ;
if ( V_86 -> V_110 )
V_144 -> V_110 = V_86 -> V_110 ;
}
return;
}
V_144 -> V_158 = V_159 ;
V_144 -> V_160 = V_161 ;
V_144 -> V_162 = false ;
V_144 -> V_79 = V_79 | V_145 | F_71 ( V_86 -> V_79 ) ;
V_144 -> V_109 =
F_58 ( int , V_144 -> V_153 ,
F_81 ( V_104 -> V_109 ) ) ;
V_144 -> V_154 = ( int ) F_82 ( V_104 -> V_108 ) ;
if ( V_144 -> V_79 & V_123 ) {
if ( V_86 -> V_110 )
V_144 -> V_110 = V_86 -> V_110 ;
else
V_144 -> V_110 = V_157 ;
}
if ( V_144 -> V_156 ) {
if ( V_64 == V_65 &&
V_3 -> V_149 & V_163 )
V_144 -> V_155 = V_144 -> V_154 ;
else
V_144 -> V_155 = F_67 ( V_144 -> V_156 ,
V_144 -> V_154 ) ;
} else
V_144 -> V_155 = V_144 -> V_154 ;
}
static void F_83 ( struct V_3 * V_3 ,
enum V_140 V_64 ,
struct V_164 * V_165 )
{
unsigned int V_32 ;
if ( ! V_165 )
return;
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ )
F_77 ( V_3 , V_64 , & V_165 -> V_167 [ V_32 ] ) ;
}
static bool F_84 ( struct V_16 * V_18 )
{
if ( V_18 -> V_64 != V_66 )
return false ;
return V_18 -> V_168 == V_169 ;
}
bool F_85 ( void )
{
return F_84 ( F_10 () ) ;
}
static enum V_58
F_86 ( struct V_16 * V_170 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_171 )
return V_59 ;
if ( F_84 ( V_19 ) &&
! F_27 ( V_170 -> V_26 ) )
return V_172 ;
return V_62 ;
}
static bool F_87 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_173 & V_174 ) ;
}
static int F_86 ( struct V_16 * V_170 )
{
return V_59 ;
}
static bool F_87 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_88 ( struct V_3 * V_3 )
{
if ( V_3 -> V_149 & V_150 &&
! ( V_3 -> V_149 & V_175 ) )
return true ;
return false ;
}
static bool F_89 ( struct V_3 * V_3 ,
enum V_140 V_64 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_3 -> V_149 & V_176 )
return true ;
if ( ! V_19 ) {
F_6 ( L_28
L_29 ,
F_75 ( V_64 ) ) ;
return true ;
}
if ( V_64 == V_141 &&
V_3 -> V_149 & V_175 ) {
F_6 ( L_28
L_30
L_31 ,
F_75 ( V_64 ) ) ;
return true ;
}
if ( F_88 ( V_3 ) && ! V_3 -> V_4 &&
V_64 != V_65 &&
! F_21 ( V_19 -> V_26 ) ) {
F_6 ( L_28
L_32
L_33 ,
F_75 ( V_64 ) ) ;
return true ;
}
if ( F_84 ( V_19 ) )
return F_87 ( V_3 ) ;
return false ;
}
static bool F_90 ( struct V_3 * V_3 )
{
const struct V_1 * V_177 = F_1 () ;
const struct V_1 * V_178 = F_3 ( V_3 ) ;
struct V_16 * V_19 = F_10 () ;
if ( F_21 ( V_177 -> V_26 ) || ( V_178 && F_21 ( V_178 -> V_26 ) ) )
return true ;
if ( V_19 && V_19 -> V_64 != V_65 &&
V_3 -> V_149 & V_175 )
return true ;
return false ;
}
static void F_91 ( struct V_3 * V_3 , unsigned int V_179 ,
struct V_180 * V_180 )
{
struct V_164 * V_165 ;
struct V_143 * V_144 ;
bool V_181 = false ;
struct V_143 V_182 ;
V_165 = V_3 -> V_183 [ V_180 -> V_144 . V_184 ] ;
V_144 = & V_165 -> V_167 [ V_179 ] ;
if ( F_92 ( V_144 -> V_134 != V_180 -> V_144 . V_134 ) )
return;
if ( V_144 -> V_162 )
return;
V_144 -> V_162 = true ;
if ( ! F_90 ( V_3 ) )
return;
if ( V_3 -> V_149 & V_185 )
return;
V_182 . V_134 = V_144 -> V_134 ;
V_182 . V_79 = V_144 -> V_79 ;
if ( V_144 -> V_79 & V_121 ) {
V_144 -> V_79 &= ~ V_121 ;
V_181 = true ;
}
if ( V_181 )
F_93 ( V_3 , & V_182 , V_144 ) ;
}
static void F_94 ( struct V_3 * V_3 ,
struct V_180 * V_180 )
{
unsigned int V_32 ;
struct V_164 * V_165 ;
if ( ! V_3 -> V_183 [ V_180 -> V_144 . V_184 ] )
return;
V_165 = V_3 -> V_183 [ V_180 -> V_144 . V_184 ] ;
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ )
F_91 ( V_3 , V_32 , V_180 ) ;
}
static void F_95 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_164 * V_165 ;
struct V_180 * V_180 ;
F_96 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_183 [ V_180 -> V_144 . V_184 ] )
continue;
V_165 = V_3 -> V_183 [ V_180 -> V_144 . V_184 ] ;
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ )
F_91 ( V_3 , V_32 , V_180 ) ;
}
}
static void F_97 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_95 ( V_3 ) ;
}
static bool F_98 ( struct V_143 * V_144 )
{
if ( ! V_144 )
return false ;
if ( V_144 -> V_79 & V_151 )
return false ;
if ( ( V_144 -> V_79 & V_152 ) == V_152 )
return false ;
return true ;
}
static void F_99 ( struct V_3 * V_3 ,
struct V_143 * V_186 )
{
struct V_164 * V_165 = V_3 -> V_183 [ V_186 -> V_184 ] ;
struct V_143 * V_187 = NULL , * V_188 = NULL ;
unsigned int V_32 ;
if ( ! F_98 ( V_186 ) ) {
V_186 -> V_79 |= V_152 ;
return;
}
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ ) {
struct V_143 * V_189 = & V_165 -> V_167 [ V_32 ] ;
if ( V_189 -> V_134 == ( V_186 -> V_134 - 20 ) )
V_187 = V_189 ;
if ( V_189 -> V_134 == ( V_186 -> V_134 + 20 ) )
V_188 = V_189 ;
}
if ( ! F_98 ( V_187 ) )
V_186 -> V_79 |= V_130 ;
else
V_186 -> V_79 &= ~ V_130 ;
if ( ! F_98 ( V_188 ) )
V_186 -> V_79 |= V_131 ;
else
V_186 -> V_79 &= ~ V_131 ;
}
static void F_100 ( struct V_3 * V_3 ,
struct V_164 * V_165 )
{
unsigned int V_32 ;
if ( ! V_165 )
return;
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ )
F_99 ( V_3 , & V_165 -> V_167 [ V_32 ] ) ;
}
static void F_101 ( struct V_3 * V_3 )
{
enum V_190 V_184 ;
if ( ! V_3 )
return;
for ( V_184 = 0 ; V_184 < V_191 ; V_184 ++ )
F_100 ( V_3 , V_3 -> V_183 [ V_184 ] ) ;
}
static void F_102 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_192 )
V_3 -> V_192 ( V_3 , V_18 ) ;
}
static bool F_103 ( struct V_3 * V_3 , struct V_193 * V_194 )
{
struct V_195 V_196 ;
struct V_197 * V_198 = F_104 ( V_3 ) ;
enum V_199 V_200 ;
F_105 ( V_194 ) ;
V_200 = V_194 -> V_200 ;
if ( ! V_194 -> V_201 || ! F_106 ( V_194 -> V_201 ) )
goto V_202;
switch ( V_200 ) {
case V_203 :
case V_204 :
if ( ! V_194 -> V_205 )
goto V_202;
V_196 = V_194 -> V_196 ;
break;
case V_206 :
if ( ! V_194 -> V_207 )
goto V_202;
V_196 = V_194 -> V_196 ;
break;
case V_208 :
case V_209 :
if ( ! V_194 -> V_210 ||
! V_194 -> V_210 -> V_211 . V_186 )
goto V_202;
if ( ! V_198 -> V_212 -> V_213 ||
F_107 ( V_198 , V_194 , & V_196 ) )
F_108 ( & V_196 ,
V_194 -> V_210 -> V_211 . V_186 ,
V_214 ) ;
break;
case V_215 :
case V_216 :
case V_217 :
break;
default:
F_20 ( 1 ) ;
break;
}
F_109 ( V_194 ) ;
switch ( V_200 ) {
case V_203 :
case V_204 :
case V_206 :
return F_110 ( V_3 , & V_196 , V_200 ) ;
case V_208 :
case V_209 :
return F_111 ( V_3 , & V_196 ,
V_151 ) ;
default:
break;
}
return true ;
V_202:
F_109 ( V_194 ) ;
return true ;
}
static void F_112 ( struct V_3 * V_3 )
{
struct V_193 * V_194 ;
struct V_197 * V_198 = F_104 ( V_3 ) ;
F_18 () ;
F_96 (wdev, &rdev->wdev_list, list)
if ( ! F_103 ( V_3 , V_194 ) )
F_113 ( V_198 , V_194 ) ;
}
static void F_114 ( struct V_38 * V_39 )
{
struct V_197 * V_198 ;
F_6 ( L_34 ) ;
F_34 () ;
F_96 (rdev, &cfg80211_rdev_list, list)
if ( ! ( V_198 -> V_3 . V_149 &
V_218 ) )
F_112 ( & V_198 -> V_3 ) ;
F_42 () ;
}
static void F_115 ( void )
{
F_116 ( V_60 ,
& V_219 ,
F_53 ( V_220 ) ) ;
}
static void F_117 ( struct V_3 * V_3 ,
enum V_140 V_64 )
{
enum V_190 V_184 ;
struct V_16 * V_19 = F_10 () ;
if ( F_89 ( V_3 , V_64 ) ) {
if ( V_64 == V_141 &&
V_3 -> V_149 & V_175 )
F_102 ( V_3 , V_19 ) ;
return;
}
V_19 -> V_6 = F_1 () -> V_6 ;
for ( V_184 = 0 ; V_184 < V_191 ; V_184 ++ )
F_83 ( V_3 , V_64 , V_3 -> V_183 [ V_184 ] ) ;
F_97 ( V_3 ) ;
F_101 ( V_3 ) ;
F_102 ( V_3 , V_19 ) ;
}
static void F_118 ( enum V_140 V_64 )
{
struct V_197 * V_198 ;
struct V_3 * V_3 ;
F_18 () ;
F_96 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_198 -> V_3 ;
F_117 ( V_3 , V_64 ) ;
}
F_115 () ;
}
static void F_119 ( struct V_3 * V_3 ,
struct V_143 * V_144 ,
const struct V_1 * V_4 )
{
T_1 V_145 = 0 ;
const struct V_34 * V_86 = NULL ;
const struct V_101 * V_104 = NULL ;
const struct V_68 * V_69 = NULL ;
T_1 V_85 ;
V_86 = F_72 ( V_3 , F_73 ( V_144 -> V_134 ) ,
V_4 ) ;
if ( F_79 ( V_86 ) ) {
F_6 ( L_35 ,
V_144 -> V_134 ) ;
if ( V_3 -> V_149 & V_176 ) {
V_144 -> V_79 |= V_151 ;
} else {
V_144 -> V_148 |= V_151 ;
V_144 -> V_79 = V_144 -> V_148 ;
}
return;
}
F_76 ( V_4 , V_144 , V_86 ) ;
V_104 = & V_86 -> V_104 ;
V_69 = & V_86 -> V_69 ;
V_85 = V_69 -> V_85 ;
if ( V_86 -> V_79 & V_107 )
V_85 = F_57 ( V_4 , V_86 ) ;
if ( V_85 < F_73 ( 40 ) )
V_145 = V_152 ;
if ( V_85 < F_73 ( 80 ) )
V_145 |= V_132 ;
if ( V_85 < F_73 ( 160 ) )
V_145 |= V_133 ;
V_144 -> V_160 = V_161 ;
V_144 -> V_158 = V_159 ;
V_144 -> V_162 = false ;
if ( V_3 -> V_149 & V_176 )
V_144 -> V_79 = V_144 -> V_148 | V_145 |
F_71 ( V_86 -> V_79 ) ;
else
V_144 -> V_79 |= F_71 ( V_86 -> V_79 ) | V_145 ;
V_144 -> V_109 = ( int ) F_81 ( V_104 -> V_109 ) ;
V_144 -> V_154 = V_144 -> V_155 =
( int ) F_82 ( V_104 -> V_108 ) ;
if ( V_144 -> V_79 & V_123 ) {
if ( V_86 -> V_110 )
V_144 -> V_110 = V_86 -> V_110 ;
else
V_144 -> V_110 = V_157 ;
}
V_144 -> V_155 = V_144 -> V_154 ;
}
static void F_120 ( struct V_3 * V_3 ,
struct V_164 * V_165 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_165 )
return;
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ )
F_119 ( V_3 , & V_165 -> V_167 [ V_32 ] , V_4 ) ;
}
void F_121 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_190 V_184 ;
unsigned int V_221 = 0 ;
F_29 ( ! ( V_3 -> V_149 & V_175 ) ,
L_36 ) ;
V_3 -> V_149 |= V_175 ;
for ( V_184 = 0 ; V_184 < V_191 ; V_184 ++ ) {
if ( ! V_3 -> V_183 [ V_184 ] )
continue;
F_120 ( V_3 , V_3 -> V_183 [ V_184 ] , V_4 ) ;
V_221 ++ ;
}
F_20 ( ! V_221 ) ;
}
static void F_122 ( void )
{
bool V_222 = false ;
struct V_16 * V_19 = F_10 () ;
V_19 -> V_63 = true ;
F_123 ( & V_223 ) ;
if ( ! F_36 ( & V_224 ) )
V_222 = true ;
F_124 ( & V_223 ) ;
F_125 ( & V_61 ) ;
if ( V_222 )
F_45 ( & V_225 ) ;
}
static enum V_58
F_126 ( struct V_16 * V_226 )
{
V_226 -> V_227 = false ;
V_226 -> V_63 = false ;
F_15 ( V_226 ) ;
return F_51 ( V_226 ) ;
}
static enum V_58
F_127 ( struct V_16 * V_228 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_84 ( V_228 ) )
return F_86 ( V_228 ) ;
if ( F_84 ( V_19 ) )
return V_59 ;
if ( V_19 -> V_64 == V_65 )
return V_229 ;
if ( V_19 -> V_64 == V_66 &&
V_19 -> V_227 )
return V_59 ;
if ( ( V_19 -> V_64 == V_141 ||
V_19 -> V_64 == V_142 ||
V_19 -> V_64 == V_66 ) &&
F_27 ( V_19 -> V_26 ) )
return V_59 ;
if ( ! F_27 ( V_228 -> V_26 ) )
return V_172 ;
return V_62 ;
}
static enum V_58
F_128 ( struct V_16 * V_228 )
{
enum V_58 V_230 ;
V_230 = F_127 ( V_228 ) ;
if ( V_230 == V_59 ||
V_230 == V_172 ) {
F_12 ( V_228 ) ;
return V_230 ;
}
V_228 -> V_227 = V_230 == V_229 ;
V_228 -> V_63 = false ;
F_15 ( V_228 ) ;
V_29 [ 0 ] = V_228 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_228 -> V_26 [ 1 ] ;
return F_51 ( V_228 ) ;
}
static enum V_58
F_129 ( struct V_16 * V_231 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_64 == V_141 ) {
if ( F_27 ( V_231 -> V_26 ) )
return V_62 ;
return V_172 ;
}
if ( V_19 -> V_64 == V_142 &&
! F_27 ( V_231 -> V_26 ) )
return V_172 ;
return V_229 ;
}
static enum V_58
F_130 ( struct V_3 * V_3 ,
struct V_16 * V_231 )
{
const struct V_1 * V_4 , * V_71 ;
enum V_58 V_230 ;
V_230 = F_129 ( V_231 ) ;
switch ( V_230 ) {
case V_62 :
break;
case V_59 :
F_12 ( V_231 ) ;
return V_230 ;
case V_229 :
case V_172 :
V_4 = F_30 ( F_1 () ) ;
if ( F_79 ( V_4 ) ) {
F_12 ( V_231 ) ;
return V_59 ;
}
V_71 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_71 ) ;
}
V_231 -> V_227 = V_230 == V_229 ;
V_231 -> V_63 = false ;
F_15 ( V_231 ) ;
if ( V_230 == V_172 ) {
F_131 ( V_231 ) ;
F_122 () ;
return V_230 ;
}
return F_51 ( V_231 ) ;
}
static enum V_58
F_132 ( struct V_3 * V_3 ,
struct V_16 * V_232 )
{
struct V_3 * V_233 = NULL ;
struct V_16 * V_19 = F_10 () ;
if ( F_84 ( V_19 ) ) {
if ( F_27 ( V_232 -> V_26 ) )
return V_59 ;
return V_172 ;
} else {
if ( V_3 -> V_149 & V_234 )
return V_59 ;
}
if ( F_133 ( ! F_25 ( V_232 -> V_26 ) ) )
return - V_54 ;
if ( V_19 -> V_64 != V_65 )
return V_62 ;
V_233 = F_78 ( V_19 -> V_147 ) ;
if ( V_233 != V_3 ) {
if ( F_27 ( V_232 -> V_26 ) )
return V_59 ;
return V_172 ;
}
if ( F_27 ( V_232 -> V_26 ) )
return V_62 ;
return V_172 ;
}
static enum V_58
F_134 ( struct V_3 * V_3 ,
struct V_16 * V_232 )
{
enum V_58 V_230 ;
V_230 = F_132 ( V_3 , V_232 ) ;
switch ( V_230 ) {
case V_62 :
break;
case V_59 :
case V_172 :
F_12 ( V_232 ) ;
return V_230 ;
case V_229 :
F_12 ( V_232 ) ;
F_47 ( 1 , L_37 ) ;
return V_59 ;
}
V_232 -> V_227 = false ;
V_232 -> V_63 = false ;
F_15 ( V_232 ) ;
return F_51 ( V_232 ) ;
}
static void F_135 ( struct V_16 * V_235 )
{
struct V_3 * V_3 = NULL ;
enum V_58 V_230 ;
if ( V_235 -> V_147 != V_236 )
V_3 = F_78 ( V_235 -> V_147 ) ;
switch ( V_235 -> V_64 ) {
case V_141 :
F_126 ( V_235 ) ;
return;
case V_66 :
V_230 = F_128 ( V_235 ) ;
if ( V_230 == V_59 ||
V_230 == V_172 )
return;
return;
case V_142 :
if ( ! V_3 )
goto V_237;
V_230 = F_130 ( V_3 , V_235 ) ;
break;
case V_65 :
if ( ! V_3 )
goto V_237;
V_230 = F_134 ( V_3 , V_235 ) ;
break;
default:
F_29 ( 1 , L_38 , V_235 -> V_64 ) ;
goto V_237;
}
if ( V_230 == V_172 && V_3 &&
V_3 -> V_149 & V_150 ) {
F_117 ( V_3 , V_235 -> V_64 ) ;
F_115 () ;
}
return;
V_237:
F_12 ( V_235 ) ;
}
static bool F_136 ( void )
{
struct V_197 * V_198 ;
struct V_3 * V_3 ;
bool V_238 = false ;
F_18 () ;
F_96 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_198 -> V_3 ;
if ( V_3 -> V_149 & V_176 )
V_238 = true ;
else
return false ;
}
return V_238 ;
}
static void F_137 ( void )
{
struct V_16 * V_235 , * V_19 ;
V_19 = F_10 () ;
if ( V_19 && ! V_19 -> V_63 ) {
F_135 ( V_19 ) ;
return;
}
F_123 ( & V_223 ) ;
if ( F_36 ( & V_224 ) ) {
F_124 ( & V_223 ) ;
return;
}
V_235 = F_37 ( & V_224 ,
struct V_16 ,
V_45 ) ;
F_138 ( & V_235 -> V_45 ) ;
F_124 ( & V_223 ) ;
if ( F_136 () ) {
F_12 ( V_235 ) ;
return;
}
F_135 ( V_235 ) ;
V_19 = F_10 () ;
F_123 ( & V_223 ) ;
if ( ! F_36 ( & V_224 ) && V_19 && V_19 -> V_63 )
F_45 ( & V_225 ) ;
F_124 ( & V_223 ) ;
}
static void F_139 ( void )
{
struct V_197 * V_198 ;
struct V_180 * V_239 , * V_71 ;
F_140 ( & V_240 ) ;
F_141 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_138 ( & V_239 -> V_45 ) ;
F_96 (rdev, &cfg80211_rdev_list, list)
F_94 ( & V_198 -> V_3 , V_239 ) ;
F_44 ( & V_239 -> V_45 , & V_241 ) ;
}
F_142 ( & V_240 ) ;
}
static void F_143 ( void )
{
struct V_197 * V_198 ;
struct V_3 * V_3 ;
const struct V_1 * V_71 ;
const struct V_1 * V_4 ;
enum V_190 V_184 ;
struct V_16 V_18 = {} ;
F_96 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_198 -> V_3 ;
F_123 ( & V_223 ) ;
V_4 = V_198 -> V_242 ;
V_198 -> V_242 = NULL ;
F_124 ( & V_223 ) ;
if ( V_4 == NULL )
continue;
V_71 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_71 ) ;
for ( V_184 = 0 ; V_184 < V_191 ; V_184 ++ )
F_120 ( V_3 , V_3 -> V_183 [ V_184 ] , V_4 ) ;
F_101 ( V_3 ) ;
V_18 . V_147 = F_144 ( V_3 ) ;
V_18 . V_26 [ 0 ] = V_4 -> V_26 [ 0 ] ;
V_18 . V_26 [ 1 ] = V_4 -> V_26 [ 1 ] ;
V_18 . V_64 = V_142 ;
F_145 ( & V_18 ) ;
}
F_115 () ;
}
static void F_146 ( struct V_38 * V_39 )
{
F_34 () ;
F_137 () ;
F_139 () ;
F_143 () ;
F_42 () ;
}
static void F_147 ( struct V_16 * V_18 )
{
V_18 -> V_26 [ 0 ] = toupper ( V_18 -> V_26 [ 0 ] ) ;
V_18 -> V_26 [ 1 ] = toupper ( V_18 -> V_26 [ 1 ] ) ;
F_123 ( & V_223 ) ;
F_44 ( & V_18 -> V_45 , & V_224 ) ;
F_124 ( & V_223 ) ;
F_45 ( & V_225 ) ;
}
static int F_148 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_141 ;
F_147 ( V_18 ) ;
return 0 ;
}
int F_149 ( const char * V_26 ,
enum V_243 V_168 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_54 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_147 = V_236 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_66 ;
V_18 -> V_168 = V_168 ;
V_52 = 0 ;
F_147 ( V_18 ) ;
return 0 ;
}
int F_150 ( bool V_244 , T_1 V_245 )
{
F_123 ( & V_246 ) ;
V_247 = V_244 ;
if ( V_247 ) {
if ( ! V_248 )
V_248 = V_245 ;
} else {
V_248 = 0 ;
}
F_124 ( & V_246 ) ;
if ( ! V_244 )
F_115 () ;
return 0 ;
}
void F_151 ( T_1 V_245 )
{
F_123 ( & V_246 ) ;
if ( V_248 != V_245 ) {
F_124 ( & V_246 ) ;
return;
}
V_247 = false ;
V_248 = 0 ;
F_124 ( & V_246 ) ;
F_115 () ;
}
int F_152 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_54 ;
V_3 -> V_149 &= ~ V_175 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_147 = F_144 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_142 ;
V_52 = 0 ;
F_147 ( V_18 ) ;
return 0 ;
}
void F_153 ( struct V_3 * V_3 , enum V_190 V_184 ,
const T_2 * V_249 , T_2 V_250 )
{
char V_26 [ 2 ] ;
enum V_251 V_51 = V_252 ;
struct V_16 * V_18 = NULL , * V_19 ;
if ( V_250 & 0x01 )
return;
if ( V_250 < V_253 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_249 [ 0 ] ;
V_26 [ 1 ] = V_249 [ 1 ] ;
if ( V_249 [ 2 ] == 'I' )
V_51 = V_254 ;
else if ( V_249 [ 2 ] == 'O' )
V_51 = V_255 ;
F_154 () ;
V_19 = F_10 () ;
if ( F_133 ( ! V_19 ) )
goto V_12;
if ( V_19 -> V_64 == V_65 &&
V_19 -> V_147 != V_236 )
goto V_12;
V_18 -> V_147 = F_144 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_65 ;
V_18 -> V_256 = V_51 ;
V_52 = 0 ;
F_147 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_155 () ;
}
static void F_156 ( char * V_26 , bool V_257 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_257 ) {
F_6 ( L_39 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_258 ) ) {
F_6 ( L_40 ,
V_258 [ 0 ] , V_258 [ 1 ] ) ;
V_26 [ 0 ] = V_258 [ 0 ] ;
V_26 [ 1 ] = V_258 [ 1 ] ;
}
} else {
F_6 ( L_41 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_258 ) ) {
F_6 ( L_40 ,
V_258 [ 0 ] , V_258 [ 1 ] ) ;
V_26 [ 0 ] = V_258 [ 0 ] ;
V_26 [ 1 ] = V_258 [ 1 ] ;
} else
F_6 ( L_42 ) ;
}
static void F_157 ( struct V_3 * V_3 )
{
struct V_164 * V_165 ;
enum V_190 V_184 ;
struct V_143 * V_144 ;
int V_32 ;
for ( V_184 = 0 ; V_184 < V_191 ; V_184 ++ ) {
V_165 = V_3 -> V_183 [ V_184 ] ;
if ( ! V_165 )
continue;
for ( V_32 = 0 ; V_32 < V_165 -> V_166 ; V_32 ++ ) {
V_144 = & V_165 -> V_167 [ V_32 ] ;
V_144 -> V_79 = V_144 -> V_148 ;
V_144 -> V_109 = V_144 -> V_153 ;
V_144 -> V_155 = V_144 -> V_156 ;
V_144 -> V_162 = false ;
}
}
}
static void F_158 ( bool V_257 )
{
char V_26 [ 2 ] ;
char V_259 [ 2 ] ;
struct V_180 * V_180 , * V_260 ;
F_159 ( V_261 ) ;
struct V_197 * V_198 ;
F_18 () ;
F_123 ( & V_246 ) ;
if ( V_247 && ! V_248 ) {
V_247 = false ;
F_115 () ;
}
F_124 ( & V_246 ) ;
F_17 ( true , & V_24 ) ;
F_156 ( V_26 , V_257 ) ;
F_123 ( & V_223 ) ;
F_160 ( & V_224 , & V_261 ) ;
F_124 ( & V_223 ) ;
F_140 ( & V_240 ) ;
F_141 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_180 -> V_45 ) ;
F_13 ( V_180 ) ;
}
F_142 ( & V_240 ) ;
F_141 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_180 -> V_45 ) ;
F_13 ( V_180 ) ;
}
V_259 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_259 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_96 (rdev, &cfg80211_rdev_list, list) {
if ( V_198 -> V_3 . V_149 & V_176 )
continue;
if ( V_198 -> V_3 . V_149 & V_175 )
F_157 ( & V_198 -> V_3 ) ;
}
F_148 ( V_259 ) ;
if ( F_25 ( V_26 ) )
F_149 ( V_29 , V_262 ) ;
F_123 ( & V_223 ) ;
F_160 ( & V_261 , & V_224 ) ;
F_124 ( & V_223 ) ;
F_6 ( L_43 ) ;
F_45 ( & V_225 ) ;
}
void F_161 ( void )
{
F_6 ( L_44 ) ;
F_158 ( false ) ;
}
static bool F_162 ( T_3 V_263 )
{
if ( V_263 == F_163 ( 12 , V_264 ) ||
V_263 == F_163 ( 13 , V_264 ) ||
V_263 == F_163 ( 14 , V_264 ) )
return true ;
return false ;
}
static bool F_164 ( struct V_143 * V_265 )
{
struct V_180 * V_239 ;
F_96 (pending_beacon, &reg_pending_beacons, list)
if ( V_265 -> V_134 ==
V_239 -> V_144 . V_134 )
return true ;
return false ;
}
int F_165 ( struct V_3 * V_3 ,
struct V_143 * V_265 ,
T_4 V_266 )
{
struct V_180 * V_180 ;
bool V_267 ;
if ( V_265 -> V_162 ||
V_265 -> V_79 & V_123 ||
( V_265 -> V_184 == V_264 &&
! F_162 ( V_265 -> V_134 ) ) )
return 0 ;
F_140 ( & V_240 ) ;
V_267 = F_164 ( V_265 ) ;
F_142 ( & V_240 ) ;
if ( V_267 )
return 0 ;
V_180 = F_31 ( sizeof( struct V_180 ) , V_266 ) ;
if ( ! V_180 )
return - V_36 ;
F_6 ( L_45 ,
V_265 -> V_134 ,
F_166 ( V_265 -> V_134 ) ,
F_167 ( V_3 ) ) ;
memcpy ( & V_180 -> V_144 , V_265 ,
sizeof( struct V_143 ) ) ;
F_140 ( & V_240 ) ;
F_44 ( & V_180 -> V_45 , & V_268 ) ;
F_142 ( & V_240 ) ;
F_45 ( & V_225 ) ;
return 0 ;
}
static void F_168 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_86 = NULL ;
const struct V_68 * V_69 = NULL ;
const struct V_101 * V_104 = NULL ;
char V_78 [ 32 ] , V_269 [ 32 ] ;
F_169 ( L_46 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_86 = & V_25 -> V_37 [ V_32 ] ;
V_69 = & V_86 -> V_69 ;
V_104 = & V_86 -> V_104 ;
if ( V_86 -> V_79 & V_107 )
snprintf ( V_78 , sizeof( V_78 ) , L_22 ,
V_69 -> V_85 ,
F_57 ( V_25 , V_86 ) ) ;
else
snprintf ( V_78 , sizeof( V_78 ) , L_23 ,
V_69 -> V_85 ) ;
if ( V_86 -> V_79 & V_122 )
F_170 ( V_269 , sizeof( V_269 ) , L_47 ,
V_86 -> V_110 / 1000 ) ;
else
F_170 ( V_269 , sizeof( V_269 ) , L_20 ) ;
if ( V_104 -> V_109 )
F_169 ( L_48 ,
V_69 -> V_77 ,
V_69 -> V_76 ,
V_78 ,
V_104 -> V_109 ,
V_104 -> V_108 ,
V_269 ) ;
else
F_169 ( L_49 ,
V_69 -> V_77 ,
V_69 -> V_76 ,
V_78 ,
V_104 -> V_108 ,
V_269 ) ;
}
}
bool F_171 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
F_6 ( L_50 ,
V_6 ) ;
return false ;
}
}
static void F_172 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_19 -> V_64 == V_65 ) {
struct V_197 * V_198 ;
V_198 = F_173 ( V_19 -> V_147 ) ;
if ( V_198 ) {
F_169 ( L_51 ,
V_198 -> V_270 [ 0 ] ,
V_198 -> V_270 [ 1 ] ) ;
} else
F_169 ( L_52 ) ;
} else
F_169 ( L_52 ) ;
} else if ( F_21 ( V_25 -> V_26 ) ) {
F_169 ( L_53 ) ;
} else {
if ( F_23 ( V_25 -> V_26 ) )
F_169 ( L_54 ) ;
else {
if ( F_84 ( V_19 ) )
F_169 ( L_55 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_169 ( L_56 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_169 ( L_57 , F_4 ( V_25 -> V_6 ) ) ;
F_168 ( V_25 ) ;
}
static void F_174 ( const struct V_1 * V_25 )
{
F_169 ( L_58 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_168 ( V_25 ) ;
}
static int F_175 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_54 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_176 ( const struct V_1 * V_25 ,
struct V_16 * V_228 )
{
const struct V_1 * V_271 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_272 ;
if ( ! F_60 ( V_25 ) ) {
F_177 ( L_59 ) ;
F_174 ( V_25 ) ;
return - V_54 ;
}
if ( ! V_228 -> V_227 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_271 = F_70 ( V_25 , F_1 () ) ;
if ( ! V_271 )
return - V_54 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_271 ) ;
return 0 ;
}
static int F_178 ( const struct V_1 * V_25 ,
struct V_16 * V_231 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_271 = NULL ;
const struct V_1 * V_71 ;
struct V_3 * V_146 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_54 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_272 ;
if ( ! F_60 ( V_25 ) ) {
F_177 ( L_59 ) ;
F_174 ( V_25 ) ;
return - V_54 ;
}
V_146 = F_78 ( V_231 -> V_147 ) ;
if ( ! V_146 ) {
F_52 ( V_60 ,
& V_61 , 0 ) ;
return - V_273 ;
}
if ( ! V_231 -> V_227 ) {
if ( V_146 -> V_4 )
return - V_272 ;
V_4 = F_30 ( V_25 ) ;
if ( F_79 ( V_4 ) )
return F_80 ( V_4 ) ;
F_16 ( V_146 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_271 = F_70 ( V_25 , F_1 () ) ;
if ( ! V_271 )
return - V_54 ;
V_71 = F_3 ( V_146 ) ;
F_16 ( V_146 -> V_4 , V_25 ) ;
F_8 ( V_71 ) ;
V_25 = NULL ;
F_17 ( false , V_271 ) ;
return 0 ;
}
static int F_179 ( const struct V_1 * V_25 ,
struct V_16 * V_232 )
{
struct V_3 * V_146 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_54 ;
if ( ! F_60 ( V_25 ) ) {
F_177 ( L_59 ) ;
F_174 ( V_25 ) ;
return - V_54 ;
}
V_146 = F_78 ( V_232 -> V_147 ) ;
if ( ! V_146 ) {
F_52 ( V_60 ,
& V_61 , 0 ) ;
return - V_273 ;
}
if ( V_232 -> V_227 )
return - V_54 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_41 ( const struct V_1 * V_25 ,
enum V_274 V_275 )
{
struct V_16 * V_19 ;
bool V_276 = false ;
int V_14 ;
if ( ! F_54 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_54 ;
}
if ( V_275 == V_277 )
V_52 = 0 ;
V_19 = F_10 () ;
switch ( V_19 -> V_64 ) {
case V_141 :
V_14 = F_175 ( V_25 ) ;
break;
case V_66 :
V_14 = F_176 ( V_25 , V_19 ) ;
V_276 = true ;
break;
case V_142 :
V_14 = F_178 ( V_25 , V_19 ) ;
break;
case V_65 :
V_14 = F_179 ( V_25 , V_19 ) ;
break;
default:
F_29 ( 1 , L_38 , V_19 -> V_64 ) ;
return - V_54 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_272 :
F_122 () ;
break;
default:
F_158 ( V_276 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_19 -> V_227 && V_25 != F_1 () ) )
return - V_54 ;
F_118 ( V_19 -> V_64 ) ;
F_172 ( F_1 () ) ;
F_131 ( V_19 ) ;
F_122 () ;
return 0 ;
}
static int F_180 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_278 ;
struct V_197 * V_198 ;
if ( F_20 ( ! V_3 || ! V_25 ) )
return - V_54 ;
if ( F_29 ( ! ( V_3 -> V_149 & V_176 ) ,
L_60 ) )
return - V_279 ;
if ( F_29 ( ! F_60 ( V_25 ) , L_61 ) ) {
F_174 ( V_25 ) ;
return - V_54 ;
}
V_4 = F_30 ( V_25 ) ;
if ( F_79 ( V_4 ) )
return F_80 ( V_4 ) ;
V_198 = F_104 ( V_3 ) ;
F_123 ( & V_223 ) ;
V_278 = V_198 -> V_242 ;
V_198 -> V_242 = V_4 ;
F_124 ( & V_223 ) ;
F_13 ( V_278 ) ;
return 0 ;
}
int F_181 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_280 = F_180 ( V_3 , V_25 ) ;
if ( V_280 )
return V_280 ;
F_45 ( & V_225 ) ;
return 0 ;
}
int F_182 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_280 ;
F_18 () ;
V_280 = F_180 ( V_3 , V_25 ) ;
if ( V_280 )
return V_280 ;
F_143 () ;
return 0 ;
}
void F_183 ( struct V_3 * V_3 )
{
struct V_16 * V_19 ;
if ( V_3 -> V_149 & V_176 )
V_3 -> V_149 |= V_185 |
V_234 ;
if ( ! F_87 ( V_3 ) )
V_171 ++ ;
V_19 = F_10 () ;
F_117 ( V_3 , V_19 -> V_64 ) ;
}
void F_184 ( struct V_3 * V_3 )
{
struct V_3 * V_146 = NULL ;
struct V_16 * V_19 ;
V_19 = F_10 () ;
if ( ! F_87 ( V_3 ) )
V_171 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_185 ( V_3 -> V_4 , NULL ) ;
if ( V_19 )
V_146 = F_78 ( V_19 -> V_147 ) ;
if ( ! V_146 || V_146 != V_3 )
return;
V_19 -> V_147 = V_236 ;
V_19 -> V_256 = V_252 ;
}
static void F_186 ( struct V_38 * V_39 )
{
F_6 ( L_62 ) ;
F_34 () ;
V_52 ++ ;
F_158 ( true ) ;
F_42 () ;
}
int F_187 ( int V_263 )
{
if ( V_263 >= 5150 && V_263 <= 5250 )
return 0 ;
if ( V_263 > 5250 && V_263 <= 5350 )
return 1 ;
if ( V_263 > 5350 && V_263 <= 5470 )
return 2 ;
if ( V_263 > 5470 && V_263 <= 5725 )
return 3 ;
if ( V_263 > 5725 && V_263 <= 5825 )
return 4 ;
return - V_54 ;
}
bool F_188 ( void )
{
return V_247 ;
}
int T_5 F_189 ( void )
{
int V_281 = 0 ;
V_55 = F_190 ( L_63 , 0 , NULL , 0 ) ;
if ( F_79 ( V_55 ) )
return F_80 ( V_55 ) ;
F_191 ( & V_223 ) ;
F_191 ( & V_240 ) ;
F_191 ( & V_246 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_281 = F_148 ( V_23 -> V_26 ) ;
if ( V_281 ) {
if ( V_281 == - V_36 )
return V_281 ;
F_177 ( L_64 ) ;
}
if ( ! F_21 ( V_258 ) )
F_149 ( V_258 ,
V_262 ) ;
return 0 ;
}
void F_192 ( void )
{
struct V_16 * V_235 , * V_71 ;
struct V_180 * V_180 , * V_260 ;
F_193 ( & V_225 ) ;
F_194 ( & V_61 ) ;
F_194 ( & V_219 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_42 () ;
F_195 ( & V_55 -> V_13 , true ) ;
F_196 ( V_55 ) ;
F_141 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_180 -> V_45 ) ;
F_13 ( V_180 ) ;
}
F_141 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_180 -> V_45 ) ;
F_13 ( V_180 ) ;
}
F_141 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_235 -> V_45 ) ;
F_13 ( V_235 ) ;
}
}
