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
const struct V_1 * V_4 , T_1 V_78 )
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
V_136 = F_61 ( V_138 , V_134 , V_78 ) ;
if ( V_135 && V_136 )
return V_137 ;
}
if ( ! V_135 )
return F_32 ( - V_139 ) ;
return F_32 ( - V_54 ) ;
}
const struct V_34 * F_73 ( struct V_3 * V_3 ,
T_1 V_134 , T_1 V_140 )
{
const struct V_1 * V_4 = F_55 ( V_3 ) ;
const struct V_34 * V_86 = NULL ;
T_1 V_78 ;
for ( V_78 = F_74 ( 20 ) ; V_78 >= V_140 ; V_78 = V_78 / 2 ) {
V_86 = F_72 ( V_3 , V_134 , V_4 , V_78 ) ;
if ( ! F_75 ( V_86 ) )
return V_86 ;
}
return V_86 ;
}
const struct V_34 * F_76 ( struct V_3 * V_3 ,
T_1 V_134 )
{
return F_73 ( V_3 , V_134 , F_74 ( 20 ) ) ;
}
const char * F_77 ( enum V_141 V_64 )
{
switch ( V_64 ) {
case V_142 :
return L_15 ;
case V_66 :
return L_16 ;
case V_143 :
return L_17 ;
case V_65 :
return L_18 ;
default:
F_20 ( 1 ) ;
return L_19 ;
}
}
static void F_78 ( const struct V_1 * V_4 ,
struct V_144 * V_145 ,
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
V_145 -> V_134 ) ;
F_6 ( L_25 ,
V_69 -> V_77 , V_69 -> V_76 ,
V_78 , V_109 ,
V_104 -> V_108 ) ;
}
static void F_78 ( const struct V_1 * V_4 ,
struct V_144 * V_145 ,
const struct V_34 * V_86 )
{
return;
}
static void F_79 ( struct V_3 * V_3 ,
enum V_141 V_64 ,
struct V_144 * V_145 )
{
T_1 V_79 , V_146 = 0 ;
const struct V_34 * V_86 = NULL ;
const struct V_101 * V_104 = NULL ;
const struct V_68 * V_69 = NULL ;
struct V_3 * V_147 = NULL ;
struct V_16 * V_19 = F_10 () ;
const struct V_1 * V_4 ;
T_1 V_85 ;
V_147 = F_80 ( V_19 -> V_148 ) ;
V_79 = V_145 -> V_149 ;
V_86 = F_76 ( V_3 , F_74 ( V_145 -> V_134 ) ) ;
if ( F_75 ( V_86 ) ) {
if ( V_64 == V_65 &&
F_81 ( V_86 ) == - V_139 )
return;
if ( V_19 -> V_64 == V_143 &&
V_147 && V_147 == V_3 &&
V_147 -> V_150 & V_151 ) {
F_6 ( L_26 ,
V_145 -> V_134 ) ;
V_145 -> V_149 |= V_152 ;
V_145 -> V_79 = V_145 -> V_149 ;
} else {
F_6 ( L_27 ,
V_145 -> V_134 ) ;
V_145 -> V_79 |= V_152 ;
}
return;
}
V_4 = F_55 ( V_3 ) ;
F_78 ( V_4 , V_145 , V_86 ) ;
V_104 = & V_86 -> V_104 ;
V_69 = & V_86 -> V_69 ;
V_85 = V_69 -> V_85 ;
if ( V_86 -> V_79 & V_107 )
V_85 = F_57 ( V_4 , V_86 ) ;
if ( ! F_61 ( V_69 , F_74 ( V_145 -> V_134 ) ,
F_74 ( 10 ) ) )
V_146 |= V_153 ;
if ( ! F_61 ( V_69 , F_74 ( V_145 -> V_134 ) ,
F_74 ( 20 ) ) )
V_146 |= V_154 ;
if ( V_85 < F_74 ( 10 ) )
V_146 |= V_153 ;
if ( V_85 < F_74 ( 20 ) )
V_146 |= V_154 ;
if ( V_85 < F_74 ( 40 ) )
V_146 |= V_155 ;
if ( V_85 < F_74 ( 80 ) )
V_146 |= V_132 ;
if ( V_85 < F_74 ( 160 ) )
V_146 |= V_133 ;
if ( V_19 -> V_64 == V_143 &&
V_147 && V_147 == V_3 &&
V_147 -> V_150 & V_151 ) {
V_145 -> V_79 = V_145 -> V_149 =
F_71 ( V_86 -> V_79 ) | V_146 ;
V_145 -> V_109 = V_145 -> V_156 =
( int ) F_82 ( V_104 -> V_109 ) ;
V_145 -> V_157 = V_145 -> V_158 = V_145 -> V_159 =
( int ) F_83 ( V_104 -> V_108 ) ;
if ( V_145 -> V_79 & V_123 ) {
V_145 -> V_110 = V_160 ;
if ( V_86 -> V_110 )
V_145 -> V_110 = V_86 -> V_110 ;
}
return;
}
V_145 -> V_161 = V_162 ;
V_145 -> V_163 = V_164 ;
V_145 -> V_165 = false ;
V_145 -> V_79 = V_79 | V_146 | F_71 ( V_86 -> V_79 ) ;
V_145 -> V_109 =
F_58 ( int , V_145 -> V_156 ,
F_82 ( V_104 -> V_109 ) ) ;
V_145 -> V_157 = ( int ) F_83 ( V_104 -> V_108 ) ;
if ( V_145 -> V_79 & V_123 ) {
if ( V_86 -> V_110 )
V_145 -> V_110 = V_86 -> V_110 ;
else
V_145 -> V_110 = V_160 ;
}
if ( V_145 -> V_159 ) {
if ( V_64 == V_65 &&
V_3 -> V_150 & V_166 )
V_145 -> V_158 = V_145 -> V_157 ;
else
V_145 -> V_158 = F_67 ( V_145 -> V_159 ,
V_145 -> V_157 ) ;
} else
V_145 -> V_158 = V_145 -> V_157 ;
}
static void F_84 ( struct V_3 * V_3 ,
enum V_141 V_64 ,
struct V_167 * V_168 )
{
unsigned int V_32 ;
if ( ! V_168 )
return;
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ )
F_79 ( V_3 , V_64 , & V_168 -> V_170 [ V_32 ] ) ;
}
static bool F_85 ( struct V_16 * V_18 )
{
if ( V_18 -> V_64 != V_66 )
return false ;
return V_18 -> V_171 == V_172 ;
}
bool F_86 ( void )
{
return F_85 ( F_10 () ) ;
}
static enum V_58
F_87 ( struct V_16 * V_173 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_174 )
return V_59 ;
if ( F_85 ( V_19 ) &&
! F_27 ( V_173 -> V_26 ) )
return V_175 ;
return V_62 ;
}
static bool F_88 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_176 & V_177 ) ;
}
static int F_87 ( struct V_16 * V_173 )
{
return V_59 ;
}
static bool F_88 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_89 ( struct V_3 * V_3 )
{
if ( V_3 -> V_150 & V_151 &&
! ( V_3 -> V_150 & V_178 ) )
return true ;
return false ;
}
static bool F_90 ( struct V_3 * V_3 ,
enum V_141 V_64 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_3 -> V_150 & V_179 )
return true ;
if ( ! V_19 ) {
F_6 ( L_28
L_29 ,
F_77 ( V_64 ) ) ;
return true ;
}
if ( V_64 == V_142 &&
V_3 -> V_150 & V_178 ) {
F_6 ( L_28
L_30
L_31 ,
F_77 ( V_64 ) ) ;
return true ;
}
if ( F_89 ( V_3 ) && ! V_3 -> V_4 &&
V_64 != V_65 &&
! F_21 ( V_19 -> V_26 ) ) {
F_6 ( L_28
L_32
L_33 ,
F_77 ( V_64 ) ) ;
return true ;
}
if ( F_85 ( V_19 ) )
return F_88 ( V_3 ) ;
return false ;
}
static bool F_91 ( struct V_3 * V_3 )
{
const struct V_1 * V_180 = F_1 () ;
const struct V_1 * V_181 = F_3 ( V_3 ) ;
struct V_16 * V_19 = F_10 () ;
if ( F_21 ( V_180 -> V_26 ) || ( V_181 && F_21 ( V_181 -> V_26 ) ) )
return true ;
if ( V_19 && V_19 -> V_64 != V_65 &&
V_3 -> V_150 & V_178 )
return true ;
return false ;
}
static void F_92 ( struct V_3 * V_3 , unsigned int V_182 ,
struct V_183 * V_183 )
{
struct V_167 * V_168 ;
struct V_144 * V_145 ;
bool V_184 = false ;
struct V_144 V_185 ;
V_168 = V_3 -> V_186 [ V_183 -> V_145 . V_187 ] ;
V_145 = & V_168 -> V_170 [ V_182 ] ;
if ( F_93 ( V_145 -> V_134 != V_183 -> V_145 . V_134 ) )
return;
if ( V_145 -> V_165 )
return;
V_145 -> V_165 = true ;
if ( ! F_91 ( V_3 ) )
return;
if ( V_3 -> V_150 & V_188 )
return;
V_185 . V_134 = V_145 -> V_134 ;
V_185 . V_79 = V_145 -> V_79 ;
if ( V_145 -> V_79 & V_121 ) {
V_145 -> V_79 &= ~ V_121 ;
V_184 = true ;
}
if ( V_184 )
F_94 ( V_3 , & V_185 , V_145 ) ;
}
static void F_95 ( struct V_3 * V_3 ,
struct V_183 * V_183 )
{
unsigned int V_32 ;
struct V_167 * V_168 ;
if ( ! V_3 -> V_186 [ V_183 -> V_145 . V_187 ] )
return;
V_168 = V_3 -> V_186 [ V_183 -> V_145 . V_187 ] ;
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ )
F_92 ( V_3 , V_32 , V_183 ) ;
}
static void F_96 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_167 * V_168 ;
struct V_183 * V_183 ;
F_97 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_186 [ V_183 -> V_145 . V_187 ] )
continue;
V_168 = V_3 -> V_186 [ V_183 -> V_145 . V_187 ] ;
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ )
F_92 ( V_3 , V_32 , V_183 ) ;
}
}
static void F_98 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_96 ( V_3 ) ;
}
static bool F_99 ( struct V_144 * V_145 )
{
if ( ! V_145 )
return false ;
if ( V_145 -> V_79 & V_152 )
return false ;
if ( ( V_145 -> V_79 & V_155 ) == V_155 )
return false ;
return true ;
}
static void F_100 ( struct V_3 * V_3 ,
struct V_144 * V_189 )
{
struct V_167 * V_168 = V_3 -> V_186 [ V_189 -> V_187 ] ;
struct V_144 * V_190 = NULL , * V_191 = NULL ;
unsigned int V_32 ;
if ( ! F_99 ( V_189 ) ) {
V_189 -> V_79 |= V_155 ;
return;
}
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ ) {
struct V_144 * V_192 = & V_168 -> V_170 [ V_32 ] ;
if ( V_192 -> V_134 == ( V_189 -> V_134 - 20 ) )
V_190 = V_192 ;
if ( V_192 -> V_134 == ( V_189 -> V_134 + 20 ) )
V_191 = V_192 ;
}
if ( ! F_99 ( V_190 ) )
V_189 -> V_79 |= V_130 ;
else
V_189 -> V_79 &= ~ V_130 ;
if ( ! F_99 ( V_191 ) )
V_189 -> V_79 |= V_131 ;
else
V_189 -> V_79 &= ~ V_131 ;
}
static void F_101 ( struct V_3 * V_3 ,
struct V_167 * V_168 )
{
unsigned int V_32 ;
if ( ! V_168 )
return;
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ )
F_100 ( V_3 , & V_168 -> V_170 [ V_32 ] ) ;
}
static void F_102 ( struct V_3 * V_3 )
{
enum V_193 V_187 ;
if ( ! V_3 )
return;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ )
F_101 ( V_3 , V_3 -> V_186 [ V_187 ] ) ;
}
static void F_103 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_195 )
V_3 -> V_195 ( V_3 , V_18 ) ;
}
static bool F_104 ( struct V_3 * V_3 , struct V_196 * V_197 )
{
struct V_198 V_199 ;
struct V_200 * V_201 = F_105 ( V_3 ) ;
enum V_202 V_203 ;
F_106 ( V_197 ) ;
V_203 = V_197 -> V_203 ;
if ( ! V_197 -> V_204 || ! F_107 ( V_197 -> V_204 ) )
goto V_205;
switch ( V_203 ) {
case V_206 :
case V_207 :
if ( ! V_197 -> V_208 )
goto V_205;
V_199 = V_197 -> V_199 ;
break;
case V_209 :
if ( ! V_197 -> V_210 )
goto V_205;
V_199 = V_197 -> V_199 ;
break;
case V_211 :
case V_212 :
if ( ! V_197 -> V_213 ||
! V_197 -> V_213 -> V_214 . V_189 )
goto V_205;
if ( ! V_201 -> V_215 -> V_216 ||
F_108 ( V_201 , V_197 , & V_199 ) )
F_109 ( & V_199 ,
V_197 -> V_213 -> V_214 . V_189 ,
V_217 ) ;
break;
case V_218 :
case V_219 :
case V_220 :
break;
default:
F_20 ( 1 ) ;
break;
}
F_110 ( V_197 ) ;
switch ( V_203 ) {
case V_206 :
case V_207 :
case V_209 :
return F_111 ( V_3 , & V_199 , V_203 ) ;
case V_211 :
case V_212 :
return F_112 ( V_3 , & V_199 ,
V_152 ) ;
default:
break;
}
return true ;
V_205:
F_110 ( V_197 ) ;
return true ;
}
static void F_113 ( struct V_3 * V_3 )
{
struct V_196 * V_197 ;
struct V_200 * V_201 = F_105 ( V_3 ) ;
F_18 () ;
F_97 (wdev, &rdev->wdev_list, list)
if ( ! F_104 ( V_3 , V_197 ) )
F_114 ( V_201 , V_197 ) ;
}
static void F_115 ( struct V_38 * V_39 )
{
struct V_200 * V_201 ;
F_6 ( L_34 ) ;
F_34 () ;
F_97 (rdev, &cfg80211_rdev_list, list)
if ( ! ( V_201 -> V_3 . V_150 &
V_221 ) )
F_113 ( & V_201 -> V_3 ) ;
F_42 () ;
}
static void F_116 ( void )
{
F_117 ( V_60 ,
& V_222 ,
F_53 ( V_223 ) ) ;
}
static void F_118 ( struct V_3 * V_3 ,
enum V_141 V_64 )
{
enum V_193 V_187 ;
struct V_16 * V_19 = F_10 () ;
if ( F_90 ( V_3 , V_64 ) ) {
if ( V_64 == V_142 &&
V_3 -> V_150 & V_178 )
F_103 ( V_3 , V_19 ) ;
return;
}
V_19 -> V_6 = F_1 () -> V_6 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ )
F_84 ( V_3 , V_64 , V_3 -> V_186 [ V_187 ] ) ;
F_98 ( V_3 ) ;
F_102 ( V_3 ) ;
F_103 ( V_3 , V_19 ) ;
}
static void F_119 ( enum V_141 V_64 )
{
struct V_200 * V_201 ;
struct V_3 * V_3 ;
F_18 () ;
F_97 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_201 -> V_3 ;
F_118 ( V_3 , V_64 ) ;
}
F_116 () ;
}
static void F_120 ( struct V_3 * V_3 ,
struct V_144 * V_145 ,
const struct V_1 * V_4 )
{
T_1 V_146 = 0 ;
const struct V_34 * V_86 = NULL ;
const struct V_101 * V_104 = NULL ;
const struct V_68 * V_69 = NULL ;
T_1 V_85 ;
T_1 V_78 ;
for ( V_78 = F_74 ( 20 ) ; V_78 >= F_74 ( 5 ) ; V_78 = V_78 / 2 ) {
V_86 = F_72 ( V_3 ,
F_74 ( V_145 -> V_134 ) ,
V_4 , V_78 ) ;
if ( ! F_75 ( V_86 ) )
break;
}
if ( F_75 ( V_86 ) ) {
F_6 ( L_35 ,
V_145 -> V_134 ) ;
if ( V_3 -> V_150 & V_179 ) {
V_145 -> V_79 |= V_152 ;
} else {
V_145 -> V_149 |= V_152 ;
V_145 -> V_79 = V_145 -> V_149 ;
}
return;
}
F_78 ( V_4 , V_145 , V_86 ) ;
V_104 = & V_86 -> V_104 ;
V_69 = & V_86 -> V_69 ;
V_85 = V_69 -> V_85 ;
if ( V_86 -> V_79 & V_107 )
V_85 = F_57 ( V_4 , V_86 ) ;
if ( ! F_61 ( V_69 , F_74 ( V_145 -> V_134 ) ,
F_74 ( 10 ) ) )
V_146 |= V_153 ;
if ( ! F_61 ( V_69 , F_74 ( V_145 -> V_134 ) ,
F_74 ( 20 ) ) )
V_146 |= V_154 ;
if ( V_85 < F_74 ( 10 ) )
V_146 |= V_153 ;
if ( V_85 < F_74 ( 20 ) )
V_146 |= V_154 ;
if ( V_85 < F_74 ( 40 ) )
V_146 |= V_155 ;
if ( V_85 < F_74 ( 80 ) )
V_146 |= V_132 ;
if ( V_85 < F_74 ( 160 ) )
V_146 |= V_133 ;
V_145 -> V_163 = V_164 ;
V_145 -> V_161 = V_162 ;
V_145 -> V_165 = false ;
if ( V_3 -> V_150 & V_179 )
V_145 -> V_79 = V_145 -> V_149 | V_146 |
F_71 ( V_86 -> V_79 ) ;
else
V_145 -> V_79 |= F_71 ( V_86 -> V_79 ) | V_146 ;
V_145 -> V_109 = ( int ) F_82 ( V_104 -> V_109 ) ;
V_145 -> V_157 = V_145 -> V_158 =
( int ) F_83 ( V_104 -> V_108 ) ;
if ( V_145 -> V_79 & V_123 ) {
if ( V_86 -> V_110 )
V_145 -> V_110 = V_86 -> V_110 ;
else
V_145 -> V_110 = V_160 ;
}
V_145 -> V_158 = V_145 -> V_157 ;
}
static void F_121 ( struct V_3 * V_3 ,
struct V_167 * V_168 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_168 )
return;
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ )
F_120 ( V_3 , & V_168 -> V_170 [ V_32 ] , V_4 ) ;
}
void F_122 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_193 V_187 ;
unsigned int V_224 = 0 ;
F_29 ( ! ( V_3 -> V_150 & V_178 ) ,
L_36 ) ;
V_3 -> V_150 |= V_178 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
if ( ! V_3 -> V_186 [ V_187 ] )
continue;
F_121 ( V_3 , V_3 -> V_186 [ V_187 ] , V_4 ) ;
V_224 ++ ;
}
F_20 ( ! V_224 ) ;
}
static void F_123 ( void )
{
bool V_225 = false ;
struct V_16 * V_19 = F_10 () ;
V_19 -> V_63 = true ;
F_124 ( & V_226 ) ;
if ( ! F_36 ( & V_227 ) )
V_225 = true ;
F_125 ( & V_226 ) ;
F_126 ( & V_61 ) ;
if ( V_225 )
F_45 ( & V_228 ) ;
}
static enum V_58
F_127 ( struct V_16 * V_229 )
{
V_229 -> V_230 = false ;
V_229 -> V_63 = false ;
F_15 ( V_229 ) ;
return F_51 ( V_229 ) ;
}
static enum V_58
F_128 ( struct V_16 * V_231 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_85 ( V_231 ) )
return F_87 ( V_231 ) ;
if ( F_85 ( V_19 ) )
return V_59 ;
if ( V_19 -> V_64 == V_65 )
return V_232 ;
if ( V_19 -> V_64 == V_66 &&
V_19 -> V_230 )
return V_59 ;
if ( ( V_19 -> V_64 == V_142 ||
V_19 -> V_64 == V_143 ||
V_19 -> V_64 == V_66 ) &&
F_27 ( V_19 -> V_26 ) )
return V_59 ;
if ( ! F_27 ( V_231 -> V_26 ) )
return V_175 ;
return V_62 ;
}
static enum V_58
F_129 ( struct V_16 * V_231 )
{
enum V_58 V_233 ;
V_233 = F_128 ( V_231 ) ;
if ( V_233 == V_59 ||
V_233 == V_175 ) {
F_12 ( V_231 ) ;
return V_233 ;
}
V_231 -> V_230 = V_233 == V_232 ;
V_231 -> V_63 = false ;
F_15 ( V_231 ) ;
V_29 [ 0 ] = V_231 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_231 -> V_26 [ 1 ] ;
return F_51 ( V_231 ) ;
}
static enum V_58
F_130 ( struct V_16 * V_234 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_64 == V_142 ) {
if ( F_27 ( V_234 -> V_26 ) )
return V_62 ;
return V_175 ;
}
if ( V_19 -> V_64 == V_143 &&
! F_27 ( V_234 -> V_26 ) )
return V_175 ;
return V_232 ;
}
static enum V_58
F_131 ( struct V_3 * V_3 ,
struct V_16 * V_234 )
{
const struct V_1 * V_4 , * V_71 ;
enum V_58 V_233 ;
V_233 = F_130 ( V_234 ) ;
switch ( V_233 ) {
case V_62 :
break;
case V_59 :
F_12 ( V_234 ) ;
return V_233 ;
case V_232 :
case V_175 :
V_4 = F_30 ( F_1 () ) ;
if ( F_75 ( V_4 ) ) {
F_12 ( V_234 ) ;
return V_59 ;
}
V_71 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_71 ) ;
}
V_234 -> V_230 = V_233 == V_232 ;
V_234 -> V_63 = false ;
F_15 ( V_234 ) ;
if ( V_233 == V_175 ) {
F_132 ( V_234 ) ;
F_123 () ;
return V_233 ;
}
return F_51 ( V_234 ) ;
}
static enum V_58
F_133 ( struct V_3 * V_3 ,
struct V_16 * V_235 )
{
struct V_3 * V_236 = NULL ;
struct V_16 * V_19 = F_10 () ;
if ( F_85 ( V_19 ) ) {
if ( F_27 ( V_235 -> V_26 ) )
return V_59 ;
return V_175 ;
} else {
if ( V_3 -> V_150 & V_237 )
return V_59 ;
}
if ( F_134 ( ! F_25 ( V_235 -> V_26 ) ) )
return - V_54 ;
if ( V_19 -> V_64 != V_65 )
return V_62 ;
V_236 = F_80 ( V_19 -> V_148 ) ;
if ( V_236 != V_3 ) {
if ( F_27 ( V_235 -> V_26 ) )
return V_59 ;
return V_175 ;
}
if ( F_27 ( V_235 -> V_26 ) )
return V_62 ;
return V_175 ;
}
static enum V_58
F_135 ( struct V_3 * V_3 ,
struct V_16 * V_235 )
{
enum V_58 V_233 ;
V_233 = F_133 ( V_3 , V_235 ) ;
switch ( V_233 ) {
case V_62 :
break;
case V_59 :
case V_175 :
F_12 ( V_235 ) ;
return V_233 ;
case V_232 :
F_12 ( V_235 ) ;
F_47 ( 1 , L_37 ) ;
return V_59 ;
}
V_235 -> V_230 = false ;
V_235 -> V_63 = false ;
F_15 ( V_235 ) ;
return F_51 ( V_235 ) ;
}
static void F_136 ( struct V_16 * V_238 )
{
struct V_3 * V_3 = NULL ;
enum V_58 V_233 ;
if ( V_238 -> V_148 != V_239 )
V_3 = F_80 ( V_238 -> V_148 ) ;
switch ( V_238 -> V_64 ) {
case V_142 :
F_127 ( V_238 ) ;
return;
case V_66 :
F_129 ( V_238 ) ;
return;
case V_143 :
if ( ! V_3 )
goto V_240;
V_233 = F_131 ( V_3 , V_238 ) ;
break;
case V_65 :
if ( ! V_3 )
goto V_240;
V_233 = F_135 ( V_3 , V_238 ) ;
break;
default:
F_29 ( 1 , L_38 , V_238 -> V_64 ) ;
goto V_240;
}
if ( V_233 == V_175 && V_3 &&
V_3 -> V_150 & V_151 ) {
F_118 ( V_3 , V_238 -> V_64 ) ;
F_116 () ;
}
return;
V_240:
F_12 ( V_238 ) ;
}
static bool F_137 ( void )
{
struct V_200 * V_201 ;
struct V_3 * V_3 ;
bool V_241 = false ;
F_18 () ;
F_97 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_201 -> V_3 ;
if ( V_3 -> V_150 & V_179 )
V_241 = true ;
else
return false ;
}
return V_241 ;
}
static void F_138 ( void )
{
struct V_16 * V_238 , * V_19 ;
V_19 = F_10 () ;
if ( V_19 && ! V_19 -> V_63 ) {
F_136 ( V_19 ) ;
return;
}
F_124 ( & V_226 ) ;
if ( F_36 ( & V_227 ) ) {
F_125 ( & V_226 ) ;
return;
}
V_238 = F_37 ( & V_227 ,
struct V_16 ,
V_45 ) ;
F_139 ( & V_238 -> V_45 ) ;
F_125 ( & V_226 ) ;
if ( F_137 () ) {
F_12 ( V_238 ) ;
return;
}
F_136 ( V_238 ) ;
V_19 = F_10 () ;
F_124 ( & V_226 ) ;
if ( ! F_36 ( & V_227 ) && V_19 && V_19 -> V_63 )
F_45 ( & V_228 ) ;
F_125 ( & V_226 ) ;
}
static void F_140 ( void )
{
struct V_200 * V_201 ;
struct V_183 * V_242 , * V_71 ;
F_141 ( & V_243 ) ;
F_142 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_139 ( & V_242 -> V_45 ) ;
F_97 (rdev, &cfg80211_rdev_list, list)
F_95 ( & V_201 -> V_3 , V_242 ) ;
F_44 ( & V_242 -> V_45 , & V_244 ) ;
}
F_143 ( & V_243 ) ;
}
static void F_144 ( void )
{
struct V_200 * V_201 ;
struct V_3 * V_3 ;
const struct V_1 * V_71 ;
const struct V_1 * V_4 ;
enum V_193 V_187 ;
struct V_16 V_18 = {} ;
F_97 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_201 -> V_3 ;
F_124 ( & V_226 ) ;
V_4 = V_201 -> V_245 ;
V_201 -> V_245 = NULL ;
F_125 ( & V_226 ) ;
if ( V_4 == NULL )
continue;
V_71 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_71 ) ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ )
F_121 ( V_3 , V_3 -> V_186 [ V_187 ] , V_4 ) ;
F_102 ( V_3 ) ;
V_18 . V_148 = F_145 ( V_3 ) ;
V_18 . V_26 [ 0 ] = V_4 -> V_26 [ 0 ] ;
V_18 . V_26 [ 1 ] = V_4 -> V_26 [ 1 ] ;
V_18 . V_64 = V_143 ;
F_146 ( & V_18 ) ;
}
F_116 () ;
}
static void F_147 ( struct V_38 * V_39 )
{
F_34 () ;
F_138 () ;
F_140 () ;
F_144 () ;
F_42 () ;
}
static void F_148 ( struct V_16 * V_18 )
{
V_18 -> V_26 [ 0 ] = toupper ( V_18 -> V_26 [ 0 ] ) ;
V_18 -> V_26 [ 1 ] = toupper ( V_18 -> V_26 [ 1 ] ) ;
F_124 ( & V_226 ) ;
F_44 ( & V_18 -> V_45 , & V_227 ) ;
F_125 ( & V_226 ) ;
F_45 ( & V_228 ) ;
}
static int F_149 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_142 ;
F_148 ( V_18 ) ;
return 0 ;
}
int F_150 ( const char * V_26 ,
enum V_246 V_171 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_54 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_148 = V_239 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_66 ;
V_18 -> V_171 = V_171 ;
V_52 = 0 ;
F_148 ( V_18 ) ;
return 0 ;
}
int F_151 ( bool V_247 , T_1 V_248 )
{
F_124 ( & V_249 ) ;
V_250 = V_247 ;
if ( V_250 ) {
if ( ! V_251 )
V_251 = V_248 ;
} else {
V_251 = 0 ;
}
F_125 ( & V_249 ) ;
if ( ! V_247 )
F_116 () ;
return 0 ;
}
void F_152 ( T_1 V_248 )
{
F_124 ( & V_249 ) ;
if ( V_251 != V_248 ) {
F_125 ( & V_249 ) ;
return;
}
V_250 = false ;
V_251 = 0 ;
F_125 ( & V_249 ) ;
F_116 () ;
}
int F_153 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_54 ;
V_3 -> V_150 &= ~ V_178 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_148 = F_145 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_143 ;
V_52 = 0 ;
F_148 ( V_18 ) ;
return 0 ;
}
void F_154 ( struct V_3 * V_3 , enum V_193 V_187 ,
const T_2 * V_252 , T_2 V_253 )
{
char V_26 [ 2 ] ;
enum V_254 V_51 = V_255 ;
struct V_16 * V_18 = NULL , * V_19 ;
if ( V_253 & 0x01 )
return;
if ( V_253 < V_256 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_252 [ 0 ] ;
V_26 [ 1 ] = V_252 [ 1 ] ;
if ( V_252 [ 2 ] == 'I' )
V_51 = V_257 ;
else if ( V_252 [ 2 ] == 'O' )
V_51 = V_258 ;
F_155 () ;
V_19 = F_10 () ;
if ( F_134 ( ! V_19 ) )
goto V_12;
if ( V_19 -> V_64 == V_65 &&
V_19 -> V_148 != V_239 )
goto V_12;
V_18 -> V_148 = F_145 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_64 = V_65 ;
V_18 -> V_259 = V_51 ;
V_52 = 0 ;
F_148 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_156 () ;
}
static void F_157 ( char * V_26 , bool V_260 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_260 ) {
F_6 ( L_39 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_261 ) ) {
F_6 ( L_40 ,
V_261 [ 0 ] , V_261 [ 1 ] ) ;
V_26 [ 0 ] = V_261 [ 0 ] ;
V_26 [ 1 ] = V_261 [ 1 ] ;
}
} else {
F_6 ( L_41 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_261 ) ) {
F_6 ( L_40 ,
V_261 [ 0 ] , V_261 [ 1 ] ) ;
V_26 [ 0 ] = V_261 [ 0 ] ;
V_26 [ 1 ] = V_261 [ 1 ] ;
} else
F_6 ( L_42 ) ;
}
static void F_158 ( struct V_3 * V_3 )
{
struct V_167 * V_168 ;
enum V_193 V_187 ;
struct V_144 * V_145 ;
int V_32 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
V_168 = V_3 -> V_186 [ V_187 ] ;
if ( ! V_168 )
continue;
for ( V_32 = 0 ; V_32 < V_168 -> V_169 ; V_32 ++ ) {
V_145 = & V_168 -> V_170 [ V_32 ] ;
V_145 -> V_79 = V_145 -> V_149 ;
V_145 -> V_109 = V_145 -> V_156 ;
V_145 -> V_158 = V_145 -> V_159 ;
V_145 -> V_165 = false ;
}
}
}
static void F_159 ( bool V_260 )
{
char V_26 [ 2 ] ;
char V_262 [ 2 ] ;
struct V_183 * V_183 , * V_263 ;
F_160 ( V_264 ) ;
struct V_200 * V_201 ;
F_18 () ;
F_124 ( & V_249 ) ;
if ( V_250 && ! V_251 ) {
V_250 = false ;
F_116 () ;
}
F_125 ( & V_249 ) ;
F_17 ( true , & V_24 ) ;
F_157 ( V_26 , V_260 ) ;
F_124 ( & V_226 ) ;
F_161 ( & V_227 , & V_264 ) ;
F_125 ( & V_226 ) ;
F_141 ( & V_243 ) ;
F_142 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_183 -> V_45 ) ;
F_13 ( V_183 ) ;
}
F_143 ( & V_243 ) ;
F_142 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_183 -> V_45 ) ;
F_13 ( V_183 ) ;
}
V_262 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_262 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_97 (rdev, &cfg80211_rdev_list, list) {
if ( V_201 -> V_3 . V_150 & V_179 )
continue;
if ( V_201 -> V_3 . V_150 & V_178 )
F_158 ( & V_201 -> V_3 ) ;
}
F_149 ( V_262 ) ;
if ( F_25 ( V_26 ) )
F_150 ( V_26 , V_265 ) ;
F_124 ( & V_226 ) ;
F_161 ( & V_264 , & V_227 ) ;
F_125 ( & V_226 ) ;
F_6 ( L_43 ) ;
F_45 ( & V_228 ) ;
}
void F_162 ( void )
{
F_6 ( L_44 ) ;
F_159 ( false ) ;
}
static bool F_163 ( T_3 V_266 )
{
if ( V_266 == F_164 ( 12 , V_267 ) ||
V_266 == F_164 ( 13 , V_267 ) ||
V_266 == F_164 ( 14 , V_267 ) )
return true ;
return false ;
}
static bool F_165 ( struct V_144 * V_268 )
{
struct V_183 * V_242 ;
F_97 (pending_beacon, &reg_pending_beacons, list)
if ( V_268 -> V_134 ==
V_242 -> V_145 . V_134 )
return true ;
return false ;
}
int F_166 ( struct V_3 * V_3 ,
struct V_144 * V_268 ,
T_4 V_269 )
{
struct V_183 * V_183 ;
bool V_270 ;
if ( V_268 -> V_165 ||
V_268 -> V_79 & V_123 ||
( V_268 -> V_187 == V_267 &&
! F_163 ( V_268 -> V_134 ) ) )
return 0 ;
F_141 ( & V_243 ) ;
V_270 = F_165 ( V_268 ) ;
F_143 ( & V_243 ) ;
if ( V_270 )
return 0 ;
V_183 = F_31 ( sizeof( struct V_183 ) , V_269 ) ;
if ( ! V_183 )
return - V_36 ;
F_6 ( L_45 ,
V_268 -> V_134 ,
F_167 ( V_268 -> V_134 ) ,
F_168 ( V_3 ) ) ;
memcpy ( & V_183 -> V_145 , V_268 ,
sizeof( struct V_144 ) ) ;
F_141 ( & V_243 ) ;
F_44 ( & V_183 -> V_45 , & V_271 ) ;
F_143 ( & V_243 ) ;
F_45 ( & V_228 ) ;
return 0 ;
}
static void F_169 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_86 = NULL ;
const struct V_68 * V_69 = NULL ;
const struct V_101 * V_104 = NULL ;
char V_78 [ 32 ] , V_272 [ 32 ] ;
F_170 ( L_46 ) ;
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
F_171 ( V_272 , sizeof( V_272 ) , L_47 ,
V_86 -> V_110 / 1000 ) ;
else
F_171 ( V_272 , sizeof( V_272 ) , L_20 ) ;
if ( V_104 -> V_109 )
F_170 ( L_48 ,
V_69 -> V_77 ,
V_69 -> V_76 ,
V_78 ,
V_104 -> V_109 ,
V_104 -> V_108 ,
V_272 ) ;
else
F_170 ( L_49 ,
V_69 -> V_77 ,
V_69 -> V_76 ,
V_78 ,
V_104 -> V_108 ,
V_272 ) ;
}
}
bool F_172 ( enum V_5 V_6 )
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
static void F_173 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_19 -> V_64 == V_65 ) {
struct V_200 * V_201 ;
V_201 = F_174 ( V_19 -> V_148 ) ;
if ( V_201 ) {
F_170 ( L_51 ,
V_201 -> V_273 [ 0 ] ,
V_201 -> V_273 [ 1 ] ) ;
} else
F_170 ( L_52 ) ;
} else
F_170 ( L_52 ) ;
} else if ( F_21 ( V_25 -> V_26 ) ) {
F_170 ( L_53 ) ;
} else {
if ( F_23 ( V_25 -> V_26 ) )
F_170 ( L_54 ) ;
else {
if ( F_85 ( V_19 ) )
F_170 ( L_55 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_170 ( L_56 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_170 ( L_57 , F_4 ( V_25 -> V_6 ) ) ;
F_169 ( V_25 ) ;
}
static void F_175 ( const struct V_1 * V_25 )
{
F_170 ( L_58 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_169 ( V_25 ) ;
}
static int F_176 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_54 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_177 ( const struct V_1 * V_25 ,
struct V_16 * V_231 )
{
const struct V_1 * V_274 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_275 ;
if ( ! F_60 ( V_25 ) ) {
F_178 ( L_59 ) ;
F_175 ( V_25 ) ;
return - V_54 ;
}
if ( ! V_231 -> V_230 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_274 = F_70 ( V_25 , F_1 () ) ;
if ( ! V_274 )
return - V_54 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_274 ) ;
return 0 ;
}
static int F_179 ( const struct V_1 * V_25 ,
struct V_16 * V_234 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_274 = NULL ;
const struct V_1 * V_71 ;
struct V_3 * V_147 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_54 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_275 ;
if ( ! F_60 ( V_25 ) ) {
F_178 ( L_59 ) ;
F_175 ( V_25 ) ;
return - V_54 ;
}
V_147 = F_80 ( V_234 -> V_148 ) ;
if ( ! V_147 ) {
F_52 ( V_60 ,
& V_61 , 0 ) ;
return - V_276 ;
}
if ( ! V_234 -> V_230 ) {
if ( V_147 -> V_4 )
return - V_275 ;
V_4 = F_30 ( V_25 ) ;
if ( F_75 ( V_4 ) )
return F_81 ( V_4 ) ;
F_16 ( V_147 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_274 = F_70 ( V_25 , F_1 () ) ;
if ( ! V_274 )
return - V_54 ;
V_71 = F_3 ( V_147 ) ;
F_16 ( V_147 -> V_4 , V_25 ) ;
F_8 ( V_71 ) ;
V_25 = NULL ;
F_17 ( false , V_274 ) ;
return 0 ;
}
static int F_180 ( const struct V_1 * V_25 ,
struct V_16 * V_235 )
{
struct V_3 * V_147 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_54 ;
if ( ! F_60 ( V_25 ) ) {
F_178 ( L_59 ) ;
F_175 ( V_25 ) ;
return - V_54 ;
}
V_147 = F_80 ( V_235 -> V_148 ) ;
if ( ! V_147 ) {
F_52 ( V_60 ,
& V_61 , 0 ) ;
return - V_276 ;
}
if ( V_235 -> V_230 )
return - V_54 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_41 ( const struct V_1 * V_25 ,
enum V_277 V_278 )
{
struct V_16 * V_19 ;
bool V_279 = false ;
int V_14 ;
if ( ! F_54 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_54 ;
}
if ( V_278 == V_280 )
V_52 = 0 ;
V_19 = F_10 () ;
switch ( V_19 -> V_64 ) {
case V_142 :
V_14 = F_176 ( V_25 ) ;
break;
case V_66 :
V_14 = F_177 ( V_25 , V_19 ) ;
V_279 = true ;
break;
case V_143 :
V_14 = F_179 ( V_25 , V_19 ) ;
break;
case V_65 :
V_14 = F_180 ( V_25 , V_19 ) ;
break;
default:
F_29 ( 1 , L_38 , V_19 -> V_64 ) ;
return - V_54 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_275 :
F_123 () ;
break;
default:
F_159 ( V_279 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_19 -> V_230 && V_25 != F_1 () ) )
return - V_54 ;
F_119 ( V_19 -> V_64 ) ;
F_173 ( F_1 () ) ;
F_132 ( V_19 ) ;
F_123 () ;
return 0 ;
}
static int F_181 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_281 ;
struct V_200 * V_201 ;
if ( F_20 ( ! V_3 || ! V_25 ) )
return - V_54 ;
if ( F_29 ( ! ( V_3 -> V_150 & V_179 ) ,
L_60 ) )
return - V_282 ;
if ( F_29 ( ! F_60 ( V_25 ) , L_61 ) ) {
F_175 ( V_25 ) ;
return - V_54 ;
}
V_4 = F_30 ( V_25 ) ;
if ( F_75 ( V_4 ) )
return F_81 ( V_4 ) ;
V_201 = F_105 ( V_3 ) ;
F_124 ( & V_226 ) ;
V_281 = V_201 -> V_245 ;
V_201 -> V_245 = V_4 ;
F_125 ( & V_226 ) ;
F_13 ( V_281 ) ;
return 0 ;
}
int F_182 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_283 = F_181 ( V_3 , V_25 ) ;
if ( V_283 )
return V_283 ;
F_45 ( & V_228 ) ;
return 0 ;
}
int F_183 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_283 ;
F_18 () ;
V_283 = F_181 ( V_3 , V_25 ) ;
if ( V_283 )
return V_283 ;
F_144 () ;
return 0 ;
}
void F_184 ( struct V_3 * V_3 )
{
struct V_16 * V_19 ;
if ( V_3 -> V_150 & V_179 )
V_3 -> V_150 |= V_188 |
V_237 ;
if ( ! F_88 ( V_3 ) )
V_174 ++ ;
V_19 = F_10 () ;
F_118 ( V_3 , V_19 -> V_64 ) ;
}
void F_185 ( struct V_3 * V_3 )
{
struct V_3 * V_147 = NULL ;
struct V_16 * V_19 ;
V_19 = F_10 () ;
if ( ! F_88 ( V_3 ) )
V_174 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_186 ( V_3 -> V_4 , NULL ) ;
if ( V_19 )
V_147 = F_80 ( V_19 -> V_148 ) ;
if ( ! V_147 || V_147 != V_3 )
return;
V_19 -> V_148 = V_239 ;
V_19 -> V_259 = V_255 ;
}
static void F_187 ( struct V_38 * V_39 )
{
F_6 ( L_62 ) ;
F_34 () ;
V_52 ++ ;
F_159 ( true ) ;
F_42 () ;
}
int F_188 ( int V_266 )
{
if ( V_266 >= 5150 && V_266 <= 5250 )
return 0 ;
if ( V_266 > 5250 && V_266 <= 5350 )
return 1 ;
if ( V_266 > 5350 && V_266 <= 5470 )
return 2 ;
if ( V_266 > 5470 && V_266 <= 5725 )
return 3 ;
if ( V_266 > 5725 && V_266 <= 5825 )
return 4 ;
return - V_54 ;
}
bool F_189 ( void )
{
return V_250 ;
}
int T_5 F_190 ( void )
{
int V_284 = 0 ;
V_55 = F_191 ( L_63 , 0 , NULL , 0 ) ;
if ( F_75 ( V_55 ) )
return F_81 ( V_55 ) ;
F_192 ( & V_226 ) ;
F_192 ( & V_243 ) ;
F_192 ( & V_249 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_284 = F_149 ( V_23 -> V_26 ) ;
if ( V_284 ) {
if ( V_284 == - V_36 )
return V_284 ;
F_178 ( L_64 ) ;
}
if ( ! F_21 ( V_261 ) )
F_150 ( V_261 ,
V_265 ) ;
return 0 ;
}
void F_193 ( void )
{
struct V_16 * V_238 , * V_71 ;
struct V_183 * V_183 , * V_263 ;
F_194 ( & V_228 ) ;
F_195 ( & V_61 ) ;
F_195 ( & V_222 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_42 () ;
F_196 ( & V_55 -> V_13 , true ) ;
F_197 ( V_55 ) ;
F_142 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_183 -> V_45 ) ;
F_13 ( V_183 ) ;
}
F_142 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_183 -> V_45 ) ;
F_13 ( V_183 ) ;
}
F_142 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_238 -> V_45 ) ;
F_13 ( V_238 ) ;
}
}
