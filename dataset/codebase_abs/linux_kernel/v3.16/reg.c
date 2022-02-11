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
static struct V_1 *
F_64 ( const struct V_1 * V_82 ,
const struct V_1 * V_83 )
{
int V_14 , V_31 ;
unsigned int V_101 , V_102 ;
unsigned int V_103 = 0 , V_104 = 0 ;
const struct V_34 * V_84 , * V_85 ;
struct V_34 * V_86 ;
struct V_1 * V_25 ;
struct V_34 V_105 ;
if ( ! V_82 || ! V_83 )
return NULL ;
for ( V_101 = 0 ; V_101 < V_82 -> V_33 ; V_101 ++ ) {
V_84 = & V_82 -> V_37 [ V_101 ] ;
for ( V_102 = 0 ; V_102 < V_83 -> V_33 ; V_102 ++ ) {
V_85 = & V_83 -> V_37 [ V_102 ] ;
if ( ! F_61 ( V_82 , V_83 , V_84 , V_85 ,
& V_105 ) )
V_103 ++ ;
}
}
if ( ! V_103 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_103 * sizeof( struct V_34 ) ;
V_25 = F_31 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_101 = 0 ; V_101 < V_82 -> V_33 && V_104 < V_103 ; V_101 ++ ) {
V_84 = & V_82 -> V_37 [ V_101 ] ;
for ( V_102 = 0 ; V_102 < V_83 -> V_33 && V_104 < V_103 ; V_102 ++ ) {
V_85 = & V_83 -> V_37 [ V_102 ] ;
V_86 = & V_25 -> V_37 [ V_104 ] ;
V_14 = F_61 ( V_82 , V_83 , V_84 , V_85 ,
V_86 ) ;
if ( V_14 )
continue;
V_104 ++ ;
}
}
if ( V_104 != V_103 ) {
F_13 ( V_25 ) ;
return NULL ;
}
V_25 -> V_33 = V_103 ;
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_60 ( V_82 -> V_6 ,
V_83 -> V_6 ) ;
return V_25 ;
}
static T_1 F_65 ( T_1 V_106 )
{
T_1 V_107 = 0 ;
if ( V_106 & V_108 )
V_107 |= V_109 ;
if ( V_106 & V_110 )
V_107 |= V_111 ;
if ( V_106 & V_112 )
V_107 |= V_113 ;
if ( V_106 & V_114 )
V_107 |= V_115 ;
return V_107 ;
}
static const struct V_34 *
F_66 ( struct V_3 * V_3 , T_1 V_116 ,
const struct V_1 * V_4 )
{
int V_32 ;
bool V_117 = false ;
bool V_118 = false ;
if ( ! V_4 )
return F_32 ( - V_100 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_119 ;
const struct V_62 * V_120 = NULL ;
V_119 = & V_4 -> V_37 [ V_32 ] ;
V_120 = & V_119 -> V_63 ;
if ( ! V_117 )
V_117 = F_58 ( V_120 , V_116 ) ;
V_118 = F_57 ( V_120 , V_116 , F_67 ( 20 ) ) ;
if ( V_117 && V_118 )
return V_119 ;
}
if ( ! V_117 )
return F_32 ( - V_121 ) ;
return F_32 ( - V_100 ) ;
}
const struct V_34 * F_68 ( struct V_3 * V_3 ,
T_1 V_116 )
{
const struct V_1 * V_4 ;
V_4 = F_53 ( V_3 ) ;
return F_66 ( V_3 , V_116 , V_4 ) ;
}
const char * F_69 ( enum V_122 V_58 )
{
switch ( V_58 ) {
case V_123 :
return L_14 ;
case V_60 :
return L_15 ;
case V_124 :
return L_16 ;
case V_59 :
return L_17 ;
default:
F_20 ( 1 ) ;
return L_18 ;
}
}
static void F_70 ( const struct V_1 * V_4 ,
struct V_125 * V_126 ,
const struct V_34 * V_74 )
{
const struct V_89 * V_92 ;
const struct V_62 * V_63 ;
char V_98 [ 32 ] , V_127 [ 32 ] ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
if ( ! V_92 -> V_98 )
snprintf ( V_98 , sizeof( V_98 ) , L_19 ) ;
else
snprintf ( V_98 , sizeof( V_98 ) , L_20 ,
V_92 -> V_98 ) ;
if ( V_74 -> V_95 & V_96 )
snprintf ( V_127 , sizeof( V_127 ) , L_21 ,
V_63 -> V_73 ,
F_54 ( V_4 , V_74 ) ) ;
else
snprintf ( V_127 , sizeof( V_127 ) , L_22 ,
V_63 -> V_73 ) ;
F_6 ( L_23 ,
V_126 -> V_116 ) ;
F_6 ( L_24 ,
V_63 -> V_71 , V_63 -> V_70 ,
V_127 , V_98 ,
V_92 -> V_97 ) ;
}
static void F_70 ( const struct V_1 * V_4 ,
struct V_125 * V_126 ,
const struct V_34 * V_74 )
{
return;
}
static void F_71 ( struct V_3 * V_3 ,
enum V_122 V_58 ,
struct V_125 * V_126 )
{
T_1 V_95 , V_128 = 0 ;
const struct V_34 * V_74 = NULL ;
const struct V_89 * V_92 = NULL ;
const struct V_62 * V_63 = NULL ;
struct V_3 * V_129 = NULL ;
struct V_16 * V_19 = F_10 () ;
const struct V_1 * V_4 ;
T_1 V_73 ;
V_129 = F_72 ( V_19 -> V_130 ) ;
V_95 = V_126 -> V_131 ;
V_74 = F_68 ( V_3 , F_67 ( V_126 -> V_116 ) ) ;
if ( F_73 ( V_74 ) ) {
if ( V_58 == V_59 &&
F_74 ( V_74 ) == - V_121 )
return;
if ( V_19 -> V_58 == V_124 &&
V_129 && V_129 == V_3 &&
V_129 -> V_132 & V_133 ) {
F_6 ( L_25 ,
V_126 -> V_116 ) ;
V_126 -> V_131 |= V_134 ;
V_126 -> V_95 = V_126 -> V_131 ;
} else {
F_6 ( L_26 ,
V_126 -> V_116 ) ;
V_126 -> V_95 |= V_134 ;
}
return;
}
V_4 = F_53 ( V_3 ) ;
F_70 ( V_4 , V_126 , V_74 ) ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
V_73 = V_63 -> V_73 ;
if ( V_74 -> V_95 & V_96 )
V_73 = F_54 ( V_4 , V_74 ) ;
if ( V_73 < F_67 ( 40 ) )
V_128 = V_135 ;
if ( V_73 < F_67 ( 80 ) )
V_128 |= V_136 ;
if ( V_73 < F_67 ( 160 ) )
V_128 |= V_137 ;
if ( V_19 -> V_58 == V_124 &&
V_129 && V_129 == V_3 &&
V_129 -> V_132 & V_133 ) {
V_126 -> V_95 = V_126 -> V_131 =
F_65 ( V_74 -> V_95 ) | V_128 ;
V_126 -> V_98 = V_126 -> V_138 =
( int ) F_75 ( V_92 -> V_98 ) ;
V_126 -> V_139 = V_126 -> V_140 = V_126 -> V_141 =
( int ) F_76 ( V_92 -> V_97 ) ;
if ( V_126 -> V_95 & V_111 ) {
V_126 -> V_99 = V_142 ;
if ( V_74 -> V_99 )
V_126 -> V_99 = V_74 -> V_99 ;
}
return;
}
V_126 -> V_143 = V_144 ;
V_126 -> V_145 = V_146 ;
V_126 -> V_147 = false ;
V_126 -> V_95 = V_95 | V_128 | F_65 ( V_74 -> V_95 ) ;
V_126 -> V_98 =
F_77 ( int , V_126 -> V_138 ,
F_75 ( V_92 -> V_98 ) ) ;
V_126 -> V_139 = ( int ) F_76 ( V_92 -> V_97 ) ;
if ( V_126 -> V_95 & V_111 ) {
if ( V_74 -> V_99 )
V_126 -> V_99 = V_74 -> V_99 ;
else
V_126 -> V_99 = V_142 ;
}
if ( V_126 -> V_141 ) {
if ( V_58 == V_59 &&
V_3 -> V_132 & V_148 )
V_126 -> V_140 = V_126 -> V_139 ;
else
V_126 -> V_140 = F_63 ( V_126 -> V_141 ,
V_126 -> V_139 ) ;
} else
V_126 -> V_140 = V_126 -> V_139 ;
}
static void F_78 ( struct V_3 * V_3 ,
enum V_122 V_58 ,
struct V_149 * V_150 )
{
unsigned int V_32 ;
if ( ! V_150 )
return;
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ )
F_71 ( V_3 , V_58 , & V_150 -> V_152 [ V_32 ] ) ;
}
static bool F_79 ( struct V_16 * V_18 )
{
if ( V_18 -> V_58 != V_60 )
return false ;
return V_18 -> V_153 == V_154 ;
}
static bool F_80 ( struct V_16 * V_18 )
{
if ( V_18 -> V_58 != V_60 )
return false ;
return V_18 -> V_153 == V_155 ;
}
bool F_81 ( void )
{
return F_79 ( F_10 () ) ;
}
static enum V_54
F_82 ( struct V_16 * V_156 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_157 )
return V_55 ;
if ( F_79 ( V_19 ) &&
! F_27 ( V_156 -> V_26 ) )
return V_158 ;
return V_56 ;
}
static bool F_83 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_159 & V_160 ) ;
}
static int F_82 ( struct V_16 * V_156 )
{
return V_55 ;
}
static bool F_83 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_84 ( struct V_3 * V_3 )
{
if ( V_3 -> V_132 & V_133 &&
! ( V_3 -> V_132 & V_161 ) )
return true ;
return false ;
}
static bool F_85 ( struct V_3 * V_3 ,
enum V_122 V_58 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_19 ) {
F_6 ( L_27
L_28 ,
F_69 ( V_58 ) ) ;
return true ;
}
if ( V_58 == V_123 &&
V_3 -> V_132 & V_161 ) {
F_6 ( L_27
L_29
L_30 ,
F_69 ( V_58 ) ) ;
return true ;
}
if ( F_84 ( V_3 ) && ! V_3 -> V_4 &&
V_58 != V_59 &&
! F_21 ( V_19 -> V_26 ) ) {
F_6 ( L_27
L_31
L_32 ,
F_69 ( V_58 ) ) ;
return true ;
}
if ( F_79 ( V_19 ) )
return F_83 ( V_3 ) ;
return false ;
}
static bool F_86 ( struct V_3 * V_3 )
{
const struct V_1 * V_162 = F_1 () ;
const struct V_1 * V_163 = F_3 ( V_3 ) ;
struct V_16 * V_19 = F_10 () ;
if ( F_21 ( V_162 -> V_26 ) || ( V_163 && F_21 ( V_163 -> V_26 ) ) )
return true ;
if ( V_19 && V_19 -> V_58 != V_59 &&
V_3 -> V_132 & V_161 )
return true ;
return false ;
}
static void F_87 ( struct V_3 * V_3 , unsigned int V_164 ,
struct V_165 * V_165 )
{
struct V_149 * V_150 ;
struct V_125 * V_126 ;
bool V_166 = false ;
struct V_125 V_167 ;
V_150 = V_3 -> V_168 [ V_165 -> V_126 . V_169 ] ;
V_126 = & V_150 -> V_152 [ V_164 ] ;
if ( F_88 ( V_126 -> V_116 != V_165 -> V_126 . V_116 ) )
return;
if ( V_126 -> V_147 )
return;
V_126 -> V_147 = true ;
if ( ! F_86 ( V_3 ) )
return;
if ( V_3 -> V_132 & V_170 )
return;
V_167 . V_116 = V_126 -> V_116 ;
V_167 . V_95 = V_126 -> V_95 ;
if ( V_126 -> V_95 & V_109 ) {
V_126 -> V_95 &= ~ V_109 ;
V_166 = true ;
}
if ( V_166 )
F_89 ( V_3 , & V_167 , V_126 ) ;
}
static void F_90 ( struct V_3 * V_3 ,
struct V_165 * V_165 )
{
unsigned int V_32 ;
struct V_149 * V_150 ;
if ( ! V_3 -> V_168 [ V_165 -> V_126 . V_169 ] )
return;
V_150 = V_3 -> V_168 [ V_165 -> V_126 . V_169 ] ;
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ )
F_87 ( V_3 , V_32 , V_165 ) ;
}
static void F_91 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_149 * V_150 ;
struct V_165 * V_165 ;
F_92 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_168 [ V_165 -> V_126 . V_169 ] )
continue;
V_150 = V_3 -> V_168 [ V_165 -> V_126 . V_169 ] ;
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ )
F_87 ( V_3 , V_32 , V_165 ) ;
}
}
static void F_93 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_91 ( V_3 ) ;
}
static bool F_94 ( struct V_125 * V_126 )
{
if ( ! V_126 )
return false ;
if ( V_126 -> V_95 & V_134 )
return false ;
if ( ( V_126 -> V_95 & V_135 ) == V_135 )
return false ;
return true ;
}
static void F_95 ( struct V_3 * V_3 ,
struct V_125 * V_171 )
{
struct V_149 * V_150 = V_3 -> V_168 [ V_171 -> V_169 ] ;
struct V_125 * V_172 = NULL , * V_173 = NULL ;
unsigned int V_32 ;
if ( ! F_94 ( V_171 ) ) {
V_171 -> V_95 |= V_135 ;
return;
}
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ ) {
struct V_125 * V_174 = & V_150 -> V_152 [ V_32 ] ;
if ( V_174 -> V_116 == ( V_171 -> V_116 - 20 ) )
V_172 = V_174 ;
if ( V_174 -> V_116 == ( V_171 -> V_116 + 20 ) )
V_173 = V_174 ;
}
if ( ! F_94 ( V_172 ) )
V_171 -> V_95 |= V_175 ;
else
V_171 -> V_95 &= ~ V_175 ;
if ( ! F_94 ( V_173 ) )
V_171 -> V_95 |= V_176 ;
else
V_171 -> V_95 &= ~ V_176 ;
}
static void F_96 ( struct V_3 * V_3 ,
struct V_149 * V_150 )
{
unsigned int V_32 ;
if ( ! V_150 )
return;
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ )
F_95 ( V_3 , & V_150 -> V_152 [ V_32 ] ) ;
}
static void F_97 ( struct V_3 * V_3 )
{
enum V_177 V_169 ;
if ( ! V_3 )
return;
for ( V_169 = 0 ; V_169 < V_178 ; V_169 ++ )
F_96 ( V_3 , V_3 -> V_168 [ V_169 ] ) ;
}
static void F_98 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_179 )
V_3 -> V_179 ( V_3 , V_18 ) ;
}
static void F_99 ( struct V_3 * V_3 ,
enum V_122 V_58 )
{
enum V_177 V_169 ;
struct V_16 * V_19 = F_10 () ;
if ( F_85 ( V_3 , V_58 ) ) {
if ( V_58 == V_123 &&
V_3 -> V_132 & V_161 )
F_98 ( V_3 , V_19 ) ;
return;
}
V_19 -> V_6 = F_1 () -> V_6 ;
for ( V_169 = 0 ; V_169 < V_178 ; V_169 ++ )
F_78 ( V_3 , V_58 , V_3 -> V_168 [ V_169 ] ) ;
F_93 ( V_3 ) ;
F_97 ( V_3 ) ;
F_98 ( V_3 , V_19 ) ;
}
static void F_100 ( enum V_122 V_58 )
{
struct V_180 * V_181 ;
struct V_3 * V_3 ;
F_18 () ;
F_92 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_181 -> V_3 ;
F_99 ( V_3 , V_58 ) ;
}
}
static void F_101 ( struct V_3 * V_3 ,
struct V_125 * V_126 ,
const struct V_1 * V_4 )
{
T_1 V_128 = 0 ;
const struct V_34 * V_74 = NULL ;
const struct V_89 * V_92 = NULL ;
const struct V_62 * V_63 = NULL ;
T_1 V_73 ;
V_74 = F_66 ( V_3 , F_67 ( V_126 -> V_116 ) ,
V_4 ) ;
if ( F_73 ( V_74 ) ) {
F_6 ( L_33 ,
V_126 -> V_116 ) ;
V_126 -> V_131 |= V_134 ;
V_126 -> V_95 = V_126 -> V_131 ;
return;
}
F_70 ( V_4 , V_126 , V_74 ) ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
V_73 = V_63 -> V_73 ;
if ( V_74 -> V_95 & V_96 )
V_73 = F_54 ( V_4 , V_74 ) ;
if ( V_73 < F_67 ( 40 ) )
V_128 = V_135 ;
if ( V_73 < F_67 ( 80 ) )
V_128 |= V_136 ;
if ( V_73 < F_67 ( 160 ) )
V_128 |= V_137 ;
V_126 -> V_95 |= F_65 ( V_74 -> V_95 ) | V_128 ;
V_126 -> V_98 = ( int ) F_75 ( V_92 -> V_98 ) ;
V_126 -> V_139 = V_126 -> V_140 =
( int ) F_76 ( V_92 -> V_97 ) ;
}
static void F_102 ( struct V_3 * V_3 ,
struct V_149 * V_150 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_150 )
return;
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ )
F_101 ( V_3 , & V_150 -> V_152 [ V_32 ] , V_4 ) ;
}
void F_103 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_177 V_169 ;
unsigned int V_182 = 0 ;
F_29 ( ! ( V_3 -> V_132 & V_161 ) ,
L_34 ) ;
V_3 -> V_132 |= V_161 ;
for ( V_169 = 0 ; V_169 < V_178 ; V_169 ++ ) {
if ( ! V_3 -> V_168 [ V_169 ] )
continue;
F_102 ( V_3 , V_3 -> V_168 [ V_169 ] , V_4 ) ;
V_182 ++ ;
}
F_20 ( ! V_182 ) ;
}
static void F_104 ( void )
{
bool V_183 = false ;
struct V_16 * V_19 = F_10 () ;
V_19 -> V_57 = true ;
F_105 ( & V_184 ) ;
if ( ! F_36 ( & V_185 ) )
V_183 = true ;
F_106 ( & V_184 ) ;
if ( V_19 -> V_58 == V_60 )
F_107 ( & V_186 ) ;
if ( V_183 )
F_45 ( & V_187 ) ;
}
static enum V_54
F_108 ( struct V_16 * V_188 )
{
V_188 -> V_189 = false ;
V_188 -> V_57 = false ;
F_15 ( V_188 ) ;
return F_51 ( V_188 ) ;
}
static enum V_54
F_109 ( struct V_16 * V_190 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_80 ( V_190 ) ) {
V_191 = true ;
return V_192 ;
}
if ( F_79 ( V_190 ) )
return F_82 ( V_190 ) ;
if ( F_79 ( V_19 ) )
return V_55 ;
if ( V_19 -> V_58 == V_59 )
return V_193 ;
if ( V_19 -> V_58 == V_60 &&
V_19 -> V_189 )
return V_55 ;
if ( ( V_19 -> V_58 == V_123 ||
V_19 -> V_58 == V_124 ||
V_19 -> V_58 == V_60 ) &&
F_27 ( V_19 -> V_26 ) )
return V_55 ;
if ( ! F_27 ( V_190 -> V_26 ) )
return V_158 ;
return V_56 ;
}
static enum V_54
F_110 ( struct V_16 * V_190 )
{
enum V_54 V_194 ;
V_194 = F_109 ( V_190 ) ;
if ( V_194 == V_55 ||
V_194 == V_158 ||
V_194 == V_192 ) {
F_12 ( V_190 ) ;
return V_194 ;
}
V_190 -> V_189 = V_194 == V_193 ;
V_190 -> V_57 = false ;
F_15 ( V_190 ) ;
V_29 [ 0 ] = V_190 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_190 -> V_26 [ 1 ] ;
return F_51 ( V_190 ) ;
}
static enum V_54
F_111 ( struct V_16 * V_195 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_58 == V_123 ) {
if ( F_27 ( V_195 -> V_26 ) )
return V_56 ;
return V_158 ;
}
if ( V_19 -> V_58 == V_124 &&
! F_27 ( V_195 -> V_26 ) )
return V_158 ;
return V_193 ;
}
static enum V_54
F_112 ( struct V_3 * V_3 ,
struct V_16 * V_195 )
{
const struct V_1 * V_4 ;
enum V_54 V_194 ;
V_194 = F_111 ( V_195 ) ;
switch ( V_194 ) {
case V_56 :
break;
case V_55 :
case V_192 :
F_12 ( V_195 ) ;
return V_194 ;
case V_193 :
case V_158 :
V_4 = F_30 ( F_1 () ) ;
if ( F_73 ( V_4 ) ) {
F_12 ( V_195 ) ;
return V_55 ;
}
F_16 ( V_3 -> V_4 , V_4 ) ;
}
V_195 -> V_189 = V_194 == V_193 ;
V_195 -> V_57 = false ;
F_15 ( V_195 ) ;
if ( V_194 == V_158 ) {
F_113 ( V_195 ) ;
F_104 () ;
return V_194 ;
}
return F_51 ( V_195 ) ;
}
static enum V_54
F_114 ( struct V_3 * V_3 ,
struct V_16 * V_196 )
{
struct V_3 * V_197 = NULL ;
struct V_16 * V_19 = F_10 () ;
if ( F_79 ( V_19 ) ) {
if ( F_27 ( V_196 -> V_26 ) )
return V_55 ;
return V_158 ;
} else {
if ( V_3 -> V_132 & V_198 )
return V_55 ;
}
if ( F_115 ( ! F_25 ( V_196 -> V_26 ) ) )
return - V_100 ;
if ( V_19 -> V_58 != V_59 )
return V_56 ;
V_197 = F_72 ( V_19 -> V_130 ) ;
if ( V_197 != V_3 ) {
if ( F_27 ( V_196 -> V_26 ) )
return V_55 ;
return V_158 ;
}
if ( F_20 ( F_27 ( V_196 -> V_26 ) ) )
return V_56 ;
return V_158 ;
}
static enum V_54
F_116 ( struct V_3 * V_3 ,
struct V_16 * V_196 )
{
enum V_54 V_194 ;
V_194 = F_114 ( V_3 , V_196 ) ;
switch ( V_194 ) {
case V_56 :
break;
case V_55 :
case V_192 :
case V_158 :
F_12 ( V_196 ) ;
return V_194 ;
case V_193 :
F_12 ( V_196 ) ;
F_47 ( 1 , L_35 ) ;
return V_55 ;
}
V_196 -> V_189 = false ;
V_196 -> V_57 = false ;
F_15 ( V_196 ) ;
return F_51 ( V_196 ) ;
}
static void F_117 ( struct V_16 * V_199 )
{
struct V_3 * V_3 = NULL ;
enum V_54 V_194 ;
if ( V_199 -> V_130 != V_200 )
V_3 = F_72 ( V_199 -> V_130 ) ;
switch ( V_199 -> V_58 ) {
case V_123 :
F_108 ( V_199 ) ;
return;
case V_60 :
V_194 = F_110 ( V_199 ) ;
if ( V_194 == V_55 ||
V_194 == V_158 ||
V_194 == V_192 )
return;
F_118 ( V_201 ,
& V_186 , F_119 ( 3142 ) ) ;
return;
case V_124 :
if ( ! V_3 )
goto V_202;
V_194 = F_112 ( V_3 , V_199 ) ;
break;
case V_59 :
if ( ! V_3 )
goto V_202;
V_194 = F_116 ( V_3 , V_199 ) ;
break;
default:
F_29 ( 1 , L_36 , V_199 -> V_58 ) ;
goto V_202;
}
if ( V_194 == V_158 && V_3 &&
V_3 -> V_132 & V_133 )
F_99 ( V_3 , V_199 -> V_58 ) ;
return;
V_202:
F_12 ( V_199 ) ;
}
static void F_120 ( void )
{
struct V_16 * V_199 , * V_19 ;
V_19 = F_10 () ;
if ( V_19 && ! V_19 -> V_57 ) {
F_117 ( V_19 ) ;
return;
}
F_105 ( & V_184 ) ;
if ( F_36 ( & V_185 ) ) {
F_106 ( & V_184 ) ;
return;
}
V_199 = F_37 ( & V_185 ,
struct V_16 ,
V_45 ) ;
F_121 ( & V_199 -> V_45 ) ;
F_106 ( & V_184 ) ;
F_117 ( V_199 ) ;
}
static void F_122 ( void )
{
struct V_180 * V_181 ;
struct V_165 * V_203 , * V_65 ;
F_123 ( & V_204 ) ;
F_124 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_121 ( & V_203 -> V_45 ) ;
F_92 (rdev, &cfg80211_rdev_list, list)
F_90 ( & V_181 -> V_3 , V_203 ) ;
F_44 ( & V_203 -> V_45 , & V_205 ) ;
}
F_125 ( & V_204 ) ;
}
static void F_126 ( struct V_38 * V_39 )
{
F_34 () ;
F_120 () ;
F_122 () ;
F_42 () ;
}
static void F_127 ( struct V_16 * V_18 )
{
V_18 -> V_26 [ 0 ] = toupper ( V_18 -> V_26 [ 0 ] ) ;
V_18 -> V_26 [ 1 ] = toupper ( V_18 -> V_26 [ 1 ] ) ;
F_105 ( & V_184 ) ;
F_44 ( & V_18 -> V_45 , & V_185 ) ;
F_106 ( & V_184 ) ;
F_45 ( & V_187 ) ;
}
static int F_128 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_123 ;
F_127 ( V_18 ) ;
return 0 ;
}
int F_129 ( const char * V_26 ,
enum V_206 V_153 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_100 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_130 = V_200 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_60 ;
V_18 -> V_153 = V_153 ;
F_127 ( V_18 ) ;
return 0 ;
}
int F_130 ( void )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_130 = V_200 ;
V_18 -> V_58 = V_60 ;
V_18 -> V_153 = V_155 ;
F_127 ( V_18 ) ;
return 0 ;
}
int F_131 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_100 ;
V_3 -> V_132 &= ~ V_161 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_130 = F_132 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_124 ;
F_127 ( V_18 ) ;
return 0 ;
}
void F_133 ( struct V_3 * V_3 , enum V_177 V_169 ,
const T_2 * V_207 , T_2 V_208 )
{
char V_26 [ 2 ] ;
enum V_209 V_50 = V_210 ;
struct V_16 * V_18 = NULL , * V_19 ;
if ( V_208 & 0x01 )
return;
if ( V_208 < V_211 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_207 [ 0 ] ;
V_26 [ 1 ] = V_207 [ 1 ] ;
if ( V_207 [ 2 ] == 'I' )
V_50 = V_212 ;
else if ( V_207 [ 2 ] == 'O' )
V_50 = V_213 ;
F_134 () ;
V_19 = F_10 () ;
if ( F_115 ( ! V_19 ) )
goto V_12;
if ( V_19 -> V_58 == V_59 &&
V_19 -> V_130 != V_200 )
goto V_12;
V_18 -> V_130 = F_132 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_59 ;
V_18 -> V_214 = V_50 ;
F_127 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_135 () ;
}
static void F_136 ( char * V_26 , bool V_215 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_215 ) {
F_6 ( L_37 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_216 ) ) {
F_6 ( L_38 ,
V_216 [ 0 ] , V_216 [ 1 ] ) ;
V_26 [ 0 ] = V_216 [ 0 ] ;
V_26 [ 1 ] = V_216 [ 1 ] ;
}
} else {
F_6 ( L_39 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_216 ) ) {
F_6 ( L_38 ,
V_216 [ 0 ] , V_216 [ 1 ] ) ;
V_26 [ 0 ] = V_216 [ 0 ] ;
V_26 [ 1 ] = V_216 [ 1 ] ;
} else
F_6 ( L_40 ) ;
}
static void F_137 ( struct V_3 * V_3 )
{
struct V_149 * V_150 ;
enum V_177 V_169 ;
struct V_125 * V_126 ;
int V_32 ;
for ( V_169 = 0 ; V_169 < V_178 ; V_169 ++ ) {
V_150 = V_3 -> V_168 [ V_169 ] ;
if ( ! V_150 )
continue;
for ( V_32 = 0 ; V_32 < V_150 -> V_151 ; V_32 ++ ) {
V_126 = & V_150 -> V_152 [ V_32 ] ;
V_126 -> V_95 = V_126 -> V_131 ;
V_126 -> V_98 = V_126 -> V_138 ;
V_126 -> V_140 = V_126 -> V_141 ;
V_126 -> V_147 = false ;
}
}
}
static void F_138 ( bool V_215 )
{
char V_26 [ 2 ] ;
char V_217 [ 2 ] ;
struct V_165 * V_165 , * V_218 ;
struct V_16 * V_199 , * V_65 ;
F_139 ( V_219 ) ;
struct V_180 * V_181 ;
F_18 () ;
V_191 = false ;
F_17 ( true , & V_24 ) ;
F_136 ( V_26 , V_215 ) ;
F_105 ( & V_184 ) ;
F_124 (reg_request, tmp, &reg_requests_list, list) {
if ( V_199 -> V_58 != V_60 )
continue;
F_140 ( & V_199 -> V_45 , & V_219 ) ;
}
F_106 ( & V_184 ) ;
F_123 ( & V_204 ) ;
F_124 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_165 -> V_45 ) ;
F_13 ( V_165 ) ;
}
F_125 ( & V_204 ) ;
F_124 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_165 -> V_45 ) ;
F_13 ( V_165 ) ;
}
V_217 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_217 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_92 (rdev, &cfg80211_rdev_list, list) {
if ( V_181 -> V_3 . V_132 & V_161 )
F_137 ( & V_181 -> V_3 ) ;
}
F_128 ( V_217 ) ;
if ( F_25 ( V_26 ) )
F_129 ( V_29 , V_220 ) ;
F_105 ( & V_184 ) ;
F_141 ( & V_219 , & V_185 ) ;
F_106 ( & V_184 ) ;
F_6 ( L_41 ) ;
F_45 ( & V_187 ) ;
}
void F_142 ( void )
{
F_6 ( L_42 ) ;
F_138 ( false ) ;
}
static bool F_143 ( T_3 V_221 )
{
if ( V_221 == F_144 ( 12 , V_222 ) ||
V_221 == F_144 ( 13 , V_222 ) ||
V_221 == F_144 ( 14 , V_222 ) )
return true ;
return false ;
}
static bool F_145 ( struct V_125 * V_223 )
{
struct V_165 * V_203 ;
F_92 (pending_beacon, &reg_pending_beacons, list)
if ( V_223 -> V_116 ==
V_203 -> V_126 . V_116 )
return true ;
return false ;
}
int F_146 ( struct V_3 * V_3 ,
struct V_125 * V_223 ,
T_4 V_224 )
{
struct V_165 * V_165 ;
bool V_225 ;
if ( V_223 -> V_147 ||
V_223 -> V_95 & V_111 ||
( V_223 -> V_169 == V_222 &&
! F_143 ( V_223 -> V_116 ) ) )
return 0 ;
F_123 ( & V_204 ) ;
V_225 = F_145 ( V_223 ) ;
F_125 ( & V_204 ) ;
if ( V_225 )
return 0 ;
V_165 = F_31 ( sizeof( struct V_165 ) , V_224 ) ;
if ( ! V_165 )
return - V_36 ;
F_6 ( L_43 ,
V_223 -> V_116 ,
F_147 ( V_223 -> V_116 ) ,
F_148 ( V_3 ) ) ;
memcpy ( & V_165 -> V_126 , V_223 ,
sizeof( struct V_125 ) ) ;
F_123 ( & V_204 ) ;
F_44 ( & V_165 -> V_45 , & V_226 ) ;
F_125 ( & V_204 ) ;
F_45 ( & V_187 ) ;
return 0 ;
}
static void F_149 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_74 = NULL ;
const struct V_62 * V_63 = NULL ;
const struct V_89 * V_92 = NULL ;
char V_127 [ 32 ] , V_227 [ 32 ] ;
F_49 ( L_44 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_74 = & V_25 -> V_37 [ V_32 ] ;
V_63 = & V_74 -> V_63 ;
V_92 = & V_74 -> V_92 ;
if ( V_74 -> V_95 & V_96 )
snprintf ( V_127 , sizeof( V_127 ) , L_21 ,
V_63 -> V_73 ,
F_54 ( V_25 , V_74 ) ) ;
else
snprintf ( V_127 , sizeof( V_127 ) , L_22 ,
V_63 -> V_73 ) ;
if ( V_74 -> V_95 & V_110 )
F_150 ( V_227 , sizeof( V_227 ) , L_45 ,
V_74 -> V_99 / 1000 ) ;
else
F_150 ( V_227 , sizeof( V_227 ) , L_19 ) ;
if ( V_92 -> V_98 )
F_49 ( L_46 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_127 ,
V_92 -> V_98 ,
V_92 -> V_97 ,
V_227 ) ;
else
F_49 ( L_47 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_127 ,
V_92 -> V_97 ,
V_227 ) ;
}
}
bool F_151 ( enum V_5 V_6 )
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
static void F_152 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_19 -> V_58 == V_59 ) {
struct V_180 * V_181 ;
V_181 = F_153 ( V_19 -> V_130 ) ;
if ( V_181 ) {
F_49 ( L_49 ,
V_181 -> V_228 [ 0 ] ,
V_181 -> V_228 [ 1 ] ) ;
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
if ( F_79 ( V_19 ) )
F_49 ( L_53 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_49 ( L_54 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_49 ( L_55 , F_4 ( V_25 -> V_6 ) ) ;
F_149 ( V_25 ) ;
}
static void F_154 ( const struct V_1 * V_25 )
{
F_49 ( L_56 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_149 ( V_25 ) ;
}
static int F_155 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_100 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_156 ( const struct V_1 * V_25 ,
struct V_16 * V_190 )
{
const struct V_1 * V_229 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_230 ;
if ( ! F_56 ( V_25 ) ) {
F_157 ( L_57 ) ;
F_154 ( V_25 ) ;
return - V_100 ;
}
if ( ! V_190 -> V_189 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_229 = F_64 ( V_25 , F_1 () ) ;
if ( ! V_229 )
return - V_100 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_229 ) ;
return 0 ;
}
static int F_158 ( const struct V_1 * V_25 ,
struct V_16 * V_195 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_229 = NULL ;
const struct V_1 * V_65 ;
struct V_3 * V_129 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_100 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_230 ;
if ( ! F_56 ( V_25 ) ) {
F_157 ( L_57 ) ;
F_154 ( V_25 ) ;
return - V_100 ;
}
V_129 = F_72 ( V_195 -> V_130 ) ;
if ( ! V_129 ) {
F_118 ( V_201 ,
& V_186 , 0 ) ;
return - V_231 ;
}
if ( ! V_195 -> V_189 ) {
if ( V_129 -> V_4 )
return - V_230 ;
V_4 = F_30 ( V_25 ) ;
if ( F_73 ( V_4 ) )
return F_74 ( V_4 ) ;
F_16 ( V_129 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_229 = F_64 ( V_25 , F_1 () ) ;
if ( ! V_229 )
return - V_100 ;
V_65 = F_3 ( V_129 ) ;
F_16 ( V_129 -> V_4 , V_25 ) ;
F_8 ( V_65 ) ;
V_25 = NULL ;
F_17 ( false , V_229 ) ;
return 0 ;
}
static int F_159 ( const struct V_1 * V_25 ,
struct V_16 * V_196 )
{
struct V_3 * V_129 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_100 ;
if ( ! F_56 ( V_25 ) ) {
F_157 ( L_57 ) ;
F_154 ( V_25 ) ;
return - V_100 ;
}
V_129 = F_72 ( V_196 -> V_130 ) ;
if ( ! V_129 ) {
F_118 ( V_201 ,
& V_186 , 0 ) ;
return - V_231 ;
}
if ( V_196 -> V_189 )
return - V_100 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_41 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 ;
bool V_232 = false ;
int V_14 ;
if ( ! F_52 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_100 ;
}
V_19 = F_10 () ;
switch ( V_19 -> V_58 ) {
case V_123 :
V_14 = F_155 ( V_25 ) ;
break;
case V_60 :
V_14 = F_156 ( V_25 , V_19 ) ;
V_232 = true ;
break;
case V_124 :
V_14 = F_158 ( V_25 , V_19 ) ;
break;
case V_59 :
V_14 = F_159 ( V_25 , V_19 ) ;
break;
default:
F_29 ( 1 , L_36 , V_19 -> V_58 ) ;
return - V_100 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_230 :
F_104 () ;
break;
default:
F_138 ( V_232 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_19 -> V_189 && V_25 != F_1 () ) )
return - V_100 ;
F_100 ( V_19 -> V_58 ) ;
F_152 ( F_1 () ) ;
F_113 ( V_19 ) ;
F_104 () ;
return 0 ;
}
void F_160 ( struct V_3 * V_3 )
{
struct V_16 * V_19 ;
if ( ! F_83 ( V_3 ) )
V_157 ++ ;
V_19 = F_10 () ;
F_99 ( V_3 , V_19 -> V_58 ) ;
}
void F_161 ( struct V_3 * V_3 )
{
struct V_3 * V_129 = NULL ;
struct V_16 * V_19 ;
V_19 = F_10 () ;
if ( ! F_83 ( V_3 ) )
V_157 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_162 ( V_3 -> V_4 , NULL ) ;
if ( V_19 )
V_129 = F_72 ( V_19 -> V_130 ) ;
if ( ! V_129 || V_129 != V_3 )
return;
V_19 -> V_130 = V_200 ;
V_19 -> V_214 = V_210 ;
}
static void F_163 ( struct V_38 * V_39 )
{
F_6 ( L_58 ) ;
F_34 () ;
F_138 ( true ) ;
F_42 () ;
}
int F_164 ( int V_221 )
{
if ( V_221 >= 5150 && V_221 <= 5250 )
return 0 ;
if ( V_221 > 5250 && V_221 <= 5350 )
return 1 ;
if ( V_221 > 5350 && V_221 <= 5470 )
return 2 ;
if ( V_221 > 5470 && V_221 <= 5725 )
return 3 ;
if ( V_221 > 5725 && V_221 <= 5825 )
return 4 ;
return - V_100 ;
}
bool F_165 ( void )
{
return V_191 ;
}
int T_5 F_166 ( void )
{
int V_233 = 0 ;
V_51 = F_167 ( L_59 , 0 , NULL , 0 ) ;
if ( F_73 ( V_51 ) )
return F_74 ( V_51 ) ;
F_168 ( & V_184 ) ;
F_168 ( & V_204 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_233 = F_128 ( V_23 -> V_26 ) ;
if ( V_233 ) {
if ( V_233 == - V_36 )
return V_233 ;
F_157 ( L_60 ) ;
}
if ( ! F_21 ( V_216 ) )
F_129 ( V_216 ,
V_220 ) ;
return 0 ;
}
void F_169 ( void )
{
struct V_16 * V_199 , * V_65 ;
struct V_165 * V_165 , * V_218 ;
F_170 ( & V_187 ) ;
F_171 ( & V_186 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_42 () ;
F_172 ( & V_51 -> V_13 , true ) ;
F_173 ( V_51 ) ;
F_124 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_165 -> V_45 ) ;
F_13 ( V_165 ) ;
}
F_124 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_165 -> V_45 ) ;
F_13 ( V_165 ) ;
}
F_124 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_199 -> V_45 ) ;
F_13 ( V_199 ) ;
}
}
