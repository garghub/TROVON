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
if ( V_18 != & V_19 && V_18 )
F_9 ( V_18 , V_15 ) ;
}
static void F_13 ( struct V_16 * V_20 )
{
struct V_16 * V_18 ;
V_18 = F_10 () ;
if ( V_18 == V_20 )
return;
F_12 ( V_18 ) ;
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
char V_49 [ 12 ] ;
char * V_50 [] = { V_49 , NULL } ;
snprintf ( V_49 , sizeof( V_49 ) , L_11 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
if ( ! F_19 ( ( char * ) V_26 ) )
F_48 ( L_12 ,
V_26 [ 0 ] , V_26 [ 1 ] ) ;
else
F_48 ( L_13 ) ;
F_42 ( V_26 ) ;
return F_49 ( & V_51 -> V_13 . V_52 , V_53 , V_50 ) ;
}
static enum V_54
F_50 ( struct V_16 * V_20 )
{
if ( F_47 ( V_20 -> V_26 ) )
return V_55 ;
return V_56 ;
}
bool F_51 ( const char * V_26 )
{
struct V_16 * V_18 = F_10 () ;
if ( ! V_18 || V_18 -> V_57 )
return false ;
return F_24 ( V_18 -> V_26 , V_26 ) ;
}
static const struct V_1 * F_52 ( struct V_3 * V_3 )
{
struct V_16 * V_18 = F_10 () ;
if ( V_18 -> V_58 != V_59 &&
V_18 -> V_58 != V_60 &&
V_3 -> V_4 )
return F_3 ( V_3 ) ;
return F_1 () ;
}
unsigned int F_53 ( const struct V_1 * V_25 ,
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
static bool F_54 ( const struct V_34 * V_61 )
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
static bool F_55 ( const struct V_1 * V_25 )
{
const struct V_34 * V_74 = NULL ;
unsigned int V_32 ;
if ( ! V_25 -> V_33 )
return false ;
if ( F_18 ( V_25 -> V_33 > V_75 ) )
return false ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_74 = & V_25 -> V_37 [ V_32 ] ;
if ( ! F_54 ( V_74 ) )
return false ;
}
return true ;
}
static bool F_56 ( const struct V_62 * V_63 ,
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
static bool F_57 ( const struct V_62 * V_63 ,
T_1 V_78 )
{
#define F_58 1000000
T_1 V_79 = V_78 > 45 * F_58 ?
10 * F_58 : 2 * F_58 ;
if ( abs ( V_78 - V_63 -> V_71 ) <= V_79 )
return true ;
if ( abs ( V_78 - V_63 -> V_70 ) <= V_79 )
return true ;
return false ;
#undef F_58
}
static enum V_5
F_59 ( const enum V_5 V_80 ,
const enum V_5 V_81 )
{
if ( V_80 != V_81 )
return V_7 ;
return V_80 ;
}
static int F_60 ( const struct V_1 * V_82 ,
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
V_63 -> V_71 = F_61 ( V_87 -> V_71 ,
V_88 -> V_71 ) ;
V_63 -> V_70 = F_62 ( V_87 -> V_70 ,
V_88 -> V_70 ) ;
V_93 = V_87 -> V_73 ;
V_94 = V_88 -> V_73 ;
if ( V_84 -> V_95 & V_96 )
V_93 = F_53 ( V_82 , V_84 ) ;
if ( V_85 -> V_95 & V_96 )
V_94 = F_53 ( V_83 , V_85 ) ;
V_63 -> V_73 = F_62 ( V_93 , V_94 ) ;
V_86 -> V_95 = V_84 -> V_95 | V_85 -> V_95 ;
if ( ( V_84 -> V_95 & V_96 ) &&
( V_85 -> V_95 & V_96 ) )
V_86 -> V_95 |= V_96 ;
else
V_86 -> V_95 &= ~ V_96 ;
V_72 = V_63 -> V_70 - V_63 -> V_71 ;
if ( V_63 -> V_73 > V_72 )
V_63 -> V_73 = V_72 ;
V_92 -> V_97 = F_62 ( V_90 -> V_97 ,
V_91 -> V_97 ) ;
V_92 -> V_98 = F_62 ( V_90 -> V_98 ,
V_91 -> V_98 ) ;
V_86 -> V_99 = F_61 ( V_84 -> V_99 ,
V_85 -> V_99 ) ;
if ( ! F_54 ( V_86 ) )
return - V_100 ;
return 0 ;
}
static struct V_1 *
F_63 ( const struct V_1 * V_82 ,
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
if ( ! F_60 ( V_82 , V_83 , V_84 , V_85 ,
& V_105 ) )
V_103 ++ ;
}
}
if ( ! V_103 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_103 * sizeof( struct V_34 ) ;
V_25 = F_29 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_101 = 0 ; V_101 < V_82 -> V_33 && V_104 < V_103 ; V_101 ++ ) {
V_84 = & V_82 -> V_37 [ V_101 ] ;
for ( V_102 = 0 ; V_102 < V_83 -> V_33 && V_104 < V_103 ; V_102 ++ ) {
V_85 = & V_83 -> V_37 [ V_102 ] ;
V_86 = & V_25 -> V_37 [ V_104 ] ;
V_14 = F_60 ( V_82 , V_83 , V_84 , V_85 ,
V_86 ) ;
if ( V_14 )
continue;
V_104 ++ ;
}
}
if ( V_104 != V_103 ) {
F_37 ( V_25 ) ;
return NULL ;
}
V_25 -> V_33 = V_103 ;
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_59 ( V_82 -> V_6 ,
V_83 -> V_6 ) ;
return V_25 ;
}
static T_1 F_64 ( T_1 V_106 )
{
T_1 V_107 = 0 ;
if ( V_106 & V_108 )
V_107 |= V_109 ;
if ( V_106 & V_110 )
V_107 |= V_111 ;
if ( V_106 & V_112 )
V_107 |= V_113 ;
return V_107 ;
}
static const struct V_34 *
F_65 ( struct V_3 * V_3 , T_1 V_114 ,
const struct V_1 * V_4 )
{
int V_32 ;
bool V_115 = false ;
bool V_116 = false ;
if ( ! V_4 )
return F_30 ( - V_100 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_117 ;
const struct V_62 * V_118 = NULL ;
V_117 = & V_4 -> V_37 [ V_32 ] ;
V_118 = & V_117 -> V_63 ;
if ( ! V_115 )
V_115 = F_57 ( V_118 , V_114 ) ;
V_116 = F_56 ( V_118 , V_114 , F_66 ( 20 ) ) ;
if ( V_115 && V_116 )
return V_117 ;
}
if ( ! V_115 )
return F_30 ( - V_119 ) ;
return F_30 ( - V_100 ) ;
}
const struct V_34 * F_67 ( struct V_3 * V_3 ,
T_1 V_114 )
{
const struct V_1 * V_4 ;
V_4 = F_52 ( V_3 ) ;
return F_65 ( V_3 , V_114 , V_4 ) ;
}
const char * F_68 ( enum V_120 V_58 )
{
switch ( V_58 ) {
case V_121 :
return L_14 ;
case V_60 :
return L_15 ;
case V_122 :
return L_16 ;
case V_59 :
return L_17 ;
default:
F_18 ( 1 ) ;
return L_18 ;
}
}
static void F_69 ( const struct V_1 * V_4 ,
struct V_123 * V_124 ,
const struct V_34 * V_74 )
{
const struct V_89 * V_92 ;
const struct V_62 * V_63 ;
char V_98 [ 32 ] , V_125 [ 32 ] ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
if ( ! V_92 -> V_98 )
snprintf ( V_98 , sizeof( V_98 ) , L_19 ) ;
else
snprintf ( V_98 , sizeof( V_98 ) , L_20 ,
V_92 -> V_98 ) ;
if ( V_74 -> V_95 & V_96 )
snprintf ( V_125 , sizeof( V_125 ) , L_21 ,
V_63 -> V_73 ,
F_53 ( V_4 , V_74 ) ) ;
else
snprintf ( V_125 , sizeof( V_125 ) , L_22 ,
V_63 -> V_73 ) ;
F_6 ( L_23 ,
V_124 -> V_114 ) ;
F_6 ( L_24 ,
V_63 -> V_71 , V_63 -> V_70 ,
V_125 , V_98 ,
V_92 -> V_97 ) ;
}
static void F_69 ( const struct V_1 * V_4 ,
struct V_123 * V_124 ,
const struct V_34 * V_74 )
{
return;
}
static void F_70 ( struct V_3 * V_3 ,
enum V_120 V_58 ,
struct V_123 * V_124 )
{
T_1 V_95 , V_126 = 0 ;
const struct V_34 * V_74 = NULL ;
const struct V_89 * V_92 = NULL ;
const struct V_62 * V_63 = NULL ;
struct V_3 * V_127 = NULL ;
struct V_16 * V_18 = F_10 () ;
const struct V_1 * V_4 ;
T_1 V_73 ;
V_127 = F_71 ( V_18 -> V_128 ) ;
V_95 = V_124 -> V_129 ;
V_74 = F_67 ( V_3 , F_66 ( V_124 -> V_114 ) ) ;
if ( F_72 ( V_74 ) ) {
if ( V_58 == V_59 &&
F_73 ( V_74 ) == - V_119 )
return;
if ( V_18 -> V_58 == V_122 &&
V_127 && V_127 == V_3 &&
V_127 -> V_130 & V_131 ) {
F_6 ( L_25 ,
V_124 -> V_114 ) ;
V_124 -> V_129 |= V_132 ;
V_124 -> V_95 = V_124 -> V_129 ;
} else {
F_6 ( L_26 ,
V_124 -> V_114 ) ;
V_124 -> V_95 |= V_132 ;
}
return;
}
V_4 = F_52 ( V_3 ) ;
F_69 ( V_4 , V_124 , V_74 ) ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
V_73 = V_63 -> V_73 ;
if ( V_74 -> V_95 & V_96 )
V_73 = F_53 ( V_4 , V_74 ) ;
if ( V_73 < F_66 ( 40 ) )
V_126 = V_133 ;
if ( V_73 < F_66 ( 80 ) )
V_126 |= V_134 ;
if ( V_73 < F_66 ( 160 ) )
V_126 |= V_135 ;
if ( V_18 -> V_58 == V_122 &&
V_127 && V_127 == V_3 &&
V_127 -> V_130 & V_131 ) {
V_124 -> V_95 = V_124 -> V_129 =
F_64 ( V_74 -> V_95 ) | V_126 ;
V_124 -> V_98 = V_124 -> V_136 =
( int ) F_74 ( V_92 -> V_98 ) ;
V_124 -> V_137 = V_124 -> V_138 = V_124 -> V_139 =
( int ) F_75 ( V_92 -> V_97 ) ;
return;
}
V_124 -> V_140 = V_141 ;
V_124 -> V_142 = V_143 ;
V_124 -> V_144 = false ;
V_124 -> V_95 = V_95 | V_126 | F_64 ( V_74 -> V_95 ) ;
V_124 -> V_98 =
F_76 ( int , V_124 -> V_136 ,
F_74 ( V_92 -> V_98 ) ) ;
V_124 -> V_137 = ( int ) F_75 ( V_92 -> V_97 ) ;
if ( V_124 -> V_95 & V_111 ) {
if ( V_74 -> V_99 )
V_124 -> V_99 = V_74 -> V_99 ;
else
V_124 -> V_99 = V_145 ;
}
if ( V_124 -> V_139 ) {
if ( V_58 == V_59 &&
V_3 -> V_130 & V_146 )
V_124 -> V_138 = V_124 -> V_137 ;
else
V_124 -> V_138 = F_62 ( V_124 -> V_139 ,
V_124 -> V_137 ) ;
} else
V_124 -> V_138 = V_124 -> V_137 ;
}
static void F_77 ( struct V_3 * V_3 ,
enum V_120 V_58 ,
struct V_147 * V_148 )
{
unsigned int V_32 ;
if ( ! V_148 )
return;
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ )
F_70 ( V_3 , V_58 , & V_148 -> V_150 [ V_32 ] ) ;
}
static bool F_78 ( struct V_16 * V_20 )
{
if ( V_20 -> V_58 != V_60 )
return false ;
return V_20 -> V_151 == V_152 ;
}
bool F_79 ( void )
{
return F_78 ( F_10 () ) ;
}
static enum V_54
F_80 ( struct V_16 * V_153 )
{
struct V_16 * V_18 = F_10 () ;
if ( ! V_154 )
return V_55 ;
if ( F_78 ( V_18 ) &&
! F_25 ( V_153 -> V_26 ) )
return V_155 ;
return V_56 ;
}
static bool F_81 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_156 & V_157 ) ;
}
static int F_80 ( struct V_16 * V_153 )
{
return V_55 ;
}
static bool F_81 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_82 ( struct V_3 * V_3 )
{
if ( V_3 -> V_130 & V_131 &&
! ( V_3 -> V_130 & V_158 ) )
return true ;
return false ;
}
static bool F_83 ( struct V_3 * V_3 ,
enum V_120 V_58 )
{
struct V_16 * V_18 = F_10 () ;
if ( ! V_18 ) {
F_6 ( L_27
L_28 ,
F_68 ( V_58 ) ) ;
return true ;
}
if ( V_58 == V_121 &&
V_3 -> V_130 & V_158 ) {
F_6 ( L_27
L_29
L_30 ,
F_68 ( V_58 ) ) ;
return true ;
}
if ( F_82 ( V_3 ) && ! V_3 -> V_4 &&
V_58 != V_59 &&
! F_19 ( V_18 -> V_26 ) ) {
F_6 ( L_27
L_31
L_32 ,
F_68 ( V_58 ) ) ;
return true ;
}
if ( F_78 ( V_18 ) )
return F_81 ( V_3 ) ;
return false ;
}
static bool F_84 ( struct V_3 * V_3 )
{
const struct V_1 * V_159 = F_1 () ;
const struct V_1 * V_160 = F_3 ( V_3 ) ;
struct V_16 * V_18 = F_10 () ;
if ( F_19 ( V_159 -> V_26 ) || ( V_160 && F_19 ( V_160 -> V_26 ) ) )
return true ;
if ( V_18 && V_18 -> V_58 != V_59 &&
V_3 -> V_130 & V_158 )
return true ;
return false ;
}
static void F_85 ( struct V_3 * V_3 , unsigned int V_161 ,
struct V_162 * V_162 )
{
struct V_147 * V_148 ;
struct V_123 * V_124 ;
bool V_163 = false ;
struct V_123 V_164 ;
V_148 = V_3 -> V_165 [ V_162 -> V_124 . V_166 ] ;
V_124 = & V_148 -> V_150 [ V_161 ] ;
if ( F_86 ( V_124 -> V_114 != V_162 -> V_124 . V_114 ) )
return;
if ( V_124 -> V_144 )
return;
V_124 -> V_144 = true ;
if ( ! F_84 ( V_3 ) )
return;
if ( V_3 -> V_130 & V_167 )
return;
V_164 . V_114 = V_124 -> V_114 ;
V_164 . V_95 = V_124 -> V_95 ;
if ( V_124 -> V_95 & V_109 ) {
V_124 -> V_95 &= ~ V_109 ;
V_163 = true ;
}
if ( V_163 )
F_87 ( V_3 , & V_164 , V_124 ) ;
}
static void F_88 ( struct V_3 * V_3 ,
struct V_162 * V_162 )
{
unsigned int V_32 ;
struct V_147 * V_148 ;
if ( ! V_3 -> V_165 [ V_162 -> V_124 . V_166 ] )
return;
V_148 = V_3 -> V_165 [ V_162 -> V_124 . V_166 ] ;
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ )
F_85 ( V_3 , V_32 , V_162 ) ;
}
static void F_89 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_147 * V_148 ;
struct V_162 * V_162 ;
F_90 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_165 [ V_162 -> V_124 . V_166 ] )
continue;
V_148 = V_3 -> V_165 [ V_162 -> V_124 . V_166 ] ;
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ )
F_85 ( V_3 , V_32 , V_162 ) ;
}
}
static void F_91 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_89 ( V_3 ) ;
}
static bool F_92 ( struct V_123 * V_124 )
{
if ( ! V_124 )
return false ;
if ( V_124 -> V_95 & V_132 )
return false ;
if ( ( V_124 -> V_95 & V_133 ) == V_133 )
return false ;
return true ;
}
static void F_93 ( struct V_3 * V_3 ,
struct V_123 * V_168 )
{
struct V_147 * V_148 = V_3 -> V_165 [ V_168 -> V_166 ] ;
struct V_123 * V_169 = NULL , * V_170 = NULL ;
unsigned int V_32 ;
if ( ! F_92 ( V_168 ) ) {
V_168 -> V_95 |= V_133 ;
return;
}
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ ) {
struct V_123 * V_171 = & V_148 -> V_150 [ V_32 ] ;
if ( V_171 -> V_114 == ( V_168 -> V_114 - 20 ) )
V_169 = V_171 ;
if ( V_171 -> V_114 == ( V_168 -> V_114 + 20 ) )
V_170 = V_171 ;
}
if ( ! F_92 ( V_169 ) )
V_168 -> V_95 |= V_172 ;
else
V_168 -> V_95 &= ~ V_172 ;
if ( ! F_92 ( V_170 ) )
V_168 -> V_95 |= V_173 ;
else
V_168 -> V_95 &= ~ V_173 ;
}
static void F_94 ( struct V_3 * V_3 ,
struct V_147 * V_148 )
{
unsigned int V_32 ;
if ( ! V_148 )
return;
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ )
F_93 ( V_3 , & V_148 -> V_150 [ V_32 ] ) ;
}
static void F_95 ( struct V_3 * V_3 )
{
enum V_174 V_166 ;
if ( ! V_3 )
return;
for ( V_166 = 0 ; V_166 < V_175 ; V_166 ++ )
F_94 ( V_3 , V_3 -> V_165 [ V_166 ] ) ;
}
static void F_96 ( struct V_3 * V_3 ,
struct V_16 * V_20 )
{
if ( V_3 -> V_176 )
V_3 -> V_176 ( V_3 , V_20 ) ;
}
static void F_97 ( struct V_3 * V_3 ,
enum V_120 V_58 )
{
enum V_174 V_166 ;
struct V_16 * V_18 = F_10 () ;
if ( F_83 ( V_3 , V_58 ) ) {
if ( V_58 == V_121 &&
V_3 -> V_130 & V_158 )
F_96 ( V_3 , V_18 ) ;
return;
}
V_18 -> V_6 = F_1 () -> V_6 ;
for ( V_166 = 0 ; V_166 < V_175 ; V_166 ++ )
F_77 ( V_3 , V_58 , V_3 -> V_165 [ V_166 ] ) ;
F_91 ( V_3 ) ;
F_95 ( V_3 ) ;
F_96 ( V_3 , V_18 ) ;
}
static void F_98 ( enum V_120 V_58 )
{
struct V_177 * V_178 ;
struct V_3 * V_3 ;
F_16 () ;
F_90 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_178 -> V_3 ;
F_97 ( V_3 , V_58 ) ;
}
}
static void F_99 ( struct V_3 * V_3 ,
struct V_123 * V_124 ,
const struct V_1 * V_4 )
{
T_1 V_126 = 0 ;
const struct V_34 * V_74 = NULL ;
const struct V_89 * V_92 = NULL ;
const struct V_62 * V_63 = NULL ;
T_1 V_73 ;
V_74 = F_65 ( V_3 , F_66 ( V_124 -> V_114 ) ,
V_4 ) ;
if ( F_72 ( V_74 ) ) {
F_6 ( L_33 ,
V_124 -> V_114 ) ;
V_124 -> V_129 |= V_132 ;
V_124 -> V_95 = V_124 -> V_129 ;
return;
}
F_69 ( V_4 , V_124 , V_74 ) ;
V_92 = & V_74 -> V_92 ;
V_63 = & V_74 -> V_63 ;
V_73 = V_63 -> V_73 ;
if ( V_74 -> V_95 & V_96 )
V_73 = F_53 ( V_4 , V_74 ) ;
if ( V_73 < F_66 ( 40 ) )
V_126 = V_133 ;
if ( V_73 < F_66 ( 80 ) )
V_126 |= V_134 ;
if ( V_73 < F_66 ( 160 ) )
V_126 |= V_135 ;
V_124 -> V_95 |= F_64 ( V_74 -> V_95 ) | V_126 ;
V_124 -> V_98 = ( int ) F_74 ( V_92 -> V_98 ) ;
V_124 -> V_137 = V_124 -> V_138 =
( int ) F_75 ( V_92 -> V_97 ) ;
}
static void F_100 ( struct V_3 * V_3 ,
struct V_147 * V_148 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_148 )
return;
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ )
F_99 ( V_3 , & V_148 -> V_150 [ V_32 ] , V_4 ) ;
}
void F_101 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_174 V_166 ;
unsigned int V_179 = 0 ;
F_27 ( ! ( V_3 -> V_130 & V_158 ) ,
L_34 ) ;
V_3 -> V_130 |= V_158 ;
for ( V_166 = 0 ; V_166 < V_175 ; V_166 ++ ) {
if ( ! V_3 -> V_165 [ V_166 ] )
continue;
F_100 ( V_3 , V_3 -> V_165 [ V_166 ] , V_4 ) ;
V_179 ++ ;
}
F_18 ( ! V_179 ) ;
}
static void F_102 ( void )
{
bool V_180 = false ;
struct V_16 * V_18 = F_10 () ;
V_18 -> V_57 = true ;
F_103 ( & V_181 ) ;
if ( ! F_34 ( & V_182 ) )
V_180 = true ;
F_104 ( & V_181 ) ;
if ( V_18 -> V_58 == V_60 )
F_105 ( & V_183 ) ;
if ( V_180 )
F_44 ( & V_184 ) ;
}
static enum V_54
F_106 ( struct V_16 * V_185 )
{
V_185 -> V_186 = false ;
V_185 -> V_57 = false ;
F_13 ( V_185 ) ;
return F_50 ( V_185 ) ;
}
static enum V_54
F_107 ( struct V_16 * V_187 )
{
struct V_16 * V_18 = F_10 () ;
if ( F_78 ( V_187 ) )
return F_80 ( V_187 ) ;
if ( F_78 ( V_18 ) )
return V_55 ;
if ( V_18 -> V_58 == V_59 )
return V_188 ;
if ( V_18 -> V_58 == V_60 &&
V_18 -> V_186 )
return V_55 ;
if ( ( V_18 -> V_58 == V_121 ||
V_18 -> V_58 == V_122 ||
V_18 -> V_58 == V_60 ) &&
F_25 ( V_18 -> V_26 ) )
return V_55 ;
if ( ! F_25 ( V_187 -> V_26 ) )
return V_155 ;
return V_56 ;
}
static enum V_54
F_108 ( struct V_16 * V_187 )
{
enum V_54 V_189 ;
V_189 = F_107 ( V_187 ) ;
if ( V_189 == V_55 ||
V_189 == V_155 ) {
F_37 ( V_187 ) ;
return V_189 ;
}
V_187 -> V_186 = V_189 == V_188 ;
V_187 -> V_57 = false ;
F_13 ( V_187 ) ;
V_29 [ 0 ] = V_187 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_187 -> V_26 [ 1 ] ;
return F_50 ( V_187 ) ;
}
static enum V_54
F_109 ( struct V_16 * V_190 )
{
struct V_16 * V_18 = F_10 () ;
if ( V_18 -> V_58 == V_121 ) {
if ( F_25 ( V_190 -> V_26 ) )
return V_56 ;
return V_155 ;
}
if ( V_18 -> V_58 == V_122 &&
! F_25 ( V_190 -> V_26 ) )
return V_155 ;
return V_188 ;
}
static enum V_54
F_110 ( struct V_3 * V_3 ,
struct V_16 * V_190 )
{
const struct V_1 * V_4 ;
enum V_54 V_189 ;
V_189 = F_109 ( V_190 ) ;
switch ( V_189 ) {
case V_56 :
break;
case V_55 :
F_37 ( V_190 ) ;
return V_189 ;
case V_188 :
case V_155 :
V_4 = F_28 ( F_1 () ) ;
if ( F_72 ( V_4 ) ) {
F_37 ( V_190 ) ;
return V_55 ;
}
F_14 ( V_3 -> V_4 , V_4 ) ;
}
V_190 -> V_186 = V_189 == V_188 ;
V_190 -> V_57 = false ;
F_13 ( V_190 ) ;
if ( V_189 == V_155 ) {
F_111 ( V_190 ) ;
F_102 () ;
return V_189 ;
}
return F_50 ( V_190 ) ;
}
static enum V_54
F_112 ( struct V_3 * V_3 ,
struct V_16 * V_191 )
{
struct V_3 * V_192 = NULL ;
struct V_16 * V_18 = F_10 () ;
if ( F_78 ( V_18 ) ) {
if ( F_25 ( V_191 -> V_26 ) )
return V_55 ;
return V_155 ;
} else {
if ( V_3 -> V_130 & V_193 )
return V_55 ;
}
if ( F_113 ( ! F_23 ( V_191 -> V_26 ) ) )
return - V_100 ;
if ( V_18 -> V_58 != V_59 )
return V_56 ;
V_192 = F_71 ( V_18 -> V_128 ) ;
if ( V_192 != V_3 ) {
if ( F_25 ( V_191 -> V_26 ) )
return V_55 ;
return V_155 ;
}
if ( F_18 ( F_25 ( V_191 -> V_26 ) ) )
return V_56 ;
return V_155 ;
}
static enum V_54
F_114 ( struct V_3 * V_3 ,
struct V_16 * V_191 )
{
enum V_54 V_189 ;
V_189 = F_112 ( V_3 , V_191 ) ;
switch ( V_189 ) {
case V_56 :
break;
case V_55 :
case V_155 :
F_37 ( V_191 ) ;
return V_189 ;
case V_188 :
F_37 ( V_191 ) ;
F_46 ( 1 , L_35 ) ;
return V_55 ;
}
V_191 -> V_186 = false ;
V_191 -> V_57 = false ;
F_13 ( V_191 ) ;
return F_50 ( V_191 ) ;
}
static void F_115 ( struct V_16 * V_194 )
{
struct V_3 * V_3 = NULL ;
enum V_54 V_189 ;
if ( V_194 -> V_128 != V_195 )
V_3 = F_71 ( V_194 -> V_128 ) ;
switch ( V_194 -> V_58 ) {
case V_121 :
F_106 ( V_194 ) ;
return;
case V_60 :
V_189 = F_108 ( V_194 ) ;
if ( V_189 == V_55 ||
V_189 == V_155 )
return;
F_116 ( V_196 ,
& V_183 , F_117 ( 3142 ) ) ;
return;
case V_122 :
if ( ! V_3 )
goto V_197;
V_189 = F_110 ( V_3 , V_194 ) ;
break;
case V_59 :
if ( ! V_3 )
goto V_197;
V_189 = F_114 ( V_3 , V_194 ) ;
break;
default:
F_27 ( 1 , L_36 , V_194 -> V_58 ) ;
goto V_197;
}
if ( V_189 == V_155 && V_3 &&
V_3 -> V_130 & V_131 )
F_97 ( V_3 , V_194 -> V_58 ) ;
return;
V_197:
F_37 ( V_194 ) ;
}
static void F_118 ( void )
{
struct V_16 * V_194 , * V_18 ;
V_18 = F_10 () ;
if ( V_18 && ! V_18 -> V_57 ) {
F_6 ( L_37 ) ;
return;
}
F_103 ( & V_181 ) ;
if ( F_34 ( & V_182 ) ) {
F_104 ( & V_181 ) ;
return;
}
V_194 = F_35 ( & V_182 ,
struct V_16 ,
V_45 ) ;
F_119 ( & V_194 -> V_45 ) ;
F_104 ( & V_181 ) ;
F_115 ( V_194 ) ;
}
static void F_120 ( void )
{
struct V_177 * V_178 ;
struct V_162 * V_198 , * V_65 ;
F_121 ( & V_199 ) ;
F_122 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_119 ( & V_198 -> V_45 ) ;
F_90 (rdev, &cfg80211_rdev_list, list)
F_88 ( & V_178 -> V_3 , V_198 ) ;
F_43 ( & V_198 -> V_45 , & V_200 ) ;
}
F_123 ( & V_199 ) ;
}
static void F_124 ( struct V_38 * V_39 )
{
F_32 () ;
F_118 () ;
F_120 () ;
F_41 () ;
}
static void F_125 ( struct V_16 * V_20 )
{
V_20 -> V_26 [ 0 ] = toupper ( V_20 -> V_26 [ 0 ] ) ;
V_20 -> V_26 [ 1 ] = toupper ( V_20 -> V_26 [ 1 ] ) ;
F_103 ( & V_181 ) ;
F_43 ( & V_20 -> V_45 , & V_182 ) ;
F_104 ( & V_181 ) ;
F_44 ( & V_184 ) ;
}
static int F_126 ( const char * V_26 )
{
struct V_16 * V_20 ;
V_20 = F_29 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_58 = V_121 ;
F_125 ( V_20 ) ;
return 0 ;
}
int F_127 ( const char * V_26 ,
enum V_201 V_151 )
{
struct V_16 * V_20 ;
if ( F_18 ( ! V_26 ) )
return - V_100 ;
V_20 = F_29 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_128 = V_195 ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_58 = V_60 ;
V_20 -> V_151 = V_151 ;
F_125 ( V_20 ) ;
return 0 ;
}
int F_128 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_20 ;
if ( F_18 ( ! V_26 || ! V_3 ) )
return - V_100 ;
V_3 -> V_130 &= ~ V_158 ;
V_20 = F_29 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_128 = F_129 ( V_3 ) ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_58 = V_122 ;
F_125 ( V_20 ) ;
return 0 ;
}
void F_130 ( struct V_3 * V_3 , enum V_174 V_166 ,
const T_2 * V_202 , T_2 V_203 )
{
char V_26 [ 2 ] ;
enum V_204 V_50 = V_205 ;
struct V_16 * V_20 = NULL , * V_18 ;
if ( V_203 & 0x01 )
return;
if ( V_203 < V_206 )
return;
V_20 = F_29 ( sizeof( * V_20 ) , V_35 ) ;
if ( ! V_20 )
return;
V_26 [ 0 ] = V_202 [ 0 ] ;
V_26 [ 1 ] = V_202 [ 1 ] ;
if ( V_202 [ 2 ] == 'I' )
V_50 = V_207 ;
else if ( V_202 [ 2 ] == 'O' )
V_50 = V_208 ;
F_131 () ;
V_18 = F_10 () ;
if ( F_113 ( ! V_18 ) )
goto V_12;
if ( V_18 -> V_58 == V_59 &&
V_18 -> V_128 != V_195 )
goto V_12;
V_20 -> V_128 = F_129 ( V_3 ) ;
V_20 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_20 -> V_58 = V_59 ;
V_20 -> V_209 = V_50 ;
F_125 ( V_20 ) ;
V_20 = NULL ;
V_12:
F_37 ( V_20 ) ;
F_132 () ;
}
static void F_133 ( char * V_26 , bool V_210 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_26 () ) {
if ( V_210 ) {
F_6 ( L_38 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_19 ( V_211 ) ) {
F_6 ( L_39 ,
V_211 [ 0 ] , V_211 [ 1 ] ) ;
V_26 [ 0 ] = V_211 [ 0 ] ;
V_26 [ 1 ] = V_211 [ 1 ] ;
}
} else {
F_6 ( L_40 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_19 ( V_211 ) ) {
F_6 ( L_39 ,
V_211 [ 0 ] , V_211 [ 1 ] ) ;
V_26 [ 0 ] = V_211 [ 0 ] ;
V_26 [ 1 ] = V_211 [ 1 ] ;
} else
F_6 ( L_41 ) ;
}
static void F_134 ( struct V_3 * V_3 )
{
struct V_147 * V_148 ;
enum V_174 V_166 ;
struct V_123 * V_124 ;
int V_32 ;
for ( V_166 = 0 ; V_166 < V_175 ; V_166 ++ ) {
V_148 = V_3 -> V_165 [ V_166 ] ;
if ( ! V_148 )
continue;
for ( V_32 = 0 ; V_32 < V_148 -> V_149 ; V_32 ++ ) {
V_124 = & V_148 -> V_150 [ V_32 ] ;
V_124 -> V_95 = V_124 -> V_129 ;
V_124 -> V_98 = V_124 -> V_136 ;
V_124 -> V_138 = V_124 -> V_139 ;
V_124 -> V_144 = false ;
}
}
}
static void F_135 ( bool V_210 )
{
char V_26 [ 2 ] ;
char V_212 [ 2 ] ;
struct V_162 * V_162 , * V_213 ;
struct V_16 * V_194 , * V_65 ;
F_136 ( V_214 ) ;
struct V_177 * V_178 ;
F_16 () ;
F_15 ( true , & V_24 ) ;
F_133 ( V_26 , V_210 ) ;
F_103 ( & V_181 ) ;
F_122 (reg_request, tmp, &reg_requests_list, list) {
if ( V_194 -> V_58 != V_60 )
continue;
F_137 ( & V_194 -> V_45 , & V_214 ) ;
}
F_104 ( & V_181 ) ;
F_121 ( & V_199 ) ;
F_122 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_36 ( & V_162 -> V_45 ) ;
F_37 ( V_162 ) ;
}
F_123 ( & V_199 ) ;
F_122 (reg_beacon, btmp, &reg_beacon_list, list) {
F_36 ( & V_162 -> V_45 ) ;
F_37 ( V_162 ) ;
}
V_212 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_212 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_90 (rdev, &cfg80211_rdev_list, list) {
if ( V_178 -> V_3 . V_130 & V_158 )
F_134 ( & V_178 -> V_3 ) ;
}
F_126 ( V_212 ) ;
if ( F_23 ( V_26 ) )
F_127 ( V_29 , V_215 ) ;
F_103 ( & V_181 ) ;
F_138 ( & V_214 , & V_182 ) ;
F_104 ( & V_181 ) ;
F_6 ( L_42 ) ;
F_44 ( & V_184 ) ;
}
void F_139 ( void )
{
F_6 ( L_43 ) ;
F_135 ( false ) ;
}
static bool F_140 ( T_3 V_216 )
{
if ( V_216 == F_141 ( 12 , V_217 ) ||
V_216 == F_141 ( 13 , V_217 ) ||
V_216 == F_141 ( 14 , V_217 ) )
return true ;
return false ;
}
static bool F_142 ( struct V_123 * V_218 )
{
struct V_162 * V_198 ;
F_90 (pending_beacon, &reg_pending_beacons, list)
if ( V_218 -> V_114 ==
V_198 -> V_124 . V_114 )
return true ;
return false ;
}
int F_143 ( struct V_3 * V_3 ,
struct V_123 * V_218 ,
T_4 V_219 )
{
struct V_162 * V_162 ;
bool V_220 ;
if ( V_218 -> V_144 ||
V_218 -> V_95 & V_111 ||
( V_218 -> V_166 == V_217 &&
! F_140 ( V_218 -> V_114 ) ) )
return 0 ;
F_121 ( & V_199 ) ;
V_220 = F_142 ( V_218 ) ;
F_123 ( & V_199 ) ;
if ( V_220 )
return 0 ;
V_162 = F_29 ( sizeof( struct V_162 ) , V_219 ) ;
if ( ! V_162 )
return - V_36 ;
F_6 ( L_44 ,
V_218 -> V_114 ,
F_144 ( V_218 -> V_114 ) ,
F_145 ( V_3 ) ) ;
memcpy ( & V_162 -> V_124 , V_218 ,
sizeof( struct V_123 ) ) ;
F_121 ( & V_199 ) ;
F_43 ( & V_162 -> V_45 , & V_221 ) ;
F_123 ( & V_199 ) ;
F_44 ( & V_184 ) ;
return 0 ;
}
static void F_146 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_74 = NULL ;
const struct V_62 * V_63 = NULL ;
const struct V_89 * V_92 = NULL ;
char V_125 [ 32 ] , V_222 [ 32 ] ;
F_48 ( L_45 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_74 = & V_25 -> V_37 [ V_32 ] ;
V_63 = & V_74 -> V_63 ;
V_92 = & V_74 -> V_92 ;
if ( V_74 -> V_95 & V_96 )
snprintf ( V_125 , sizeof( V_125 ) , L_21 ,
V_63 -> V_73 ,
F_53 ( V_25 , V_74 ) ) ;
else
snprintf ( V_125 , sizeof( V_125 ) , L_22 ,
V_63 -> V_73 ) ;
if ( V_74 -> V_95 & V_110 )
F_147 ( V_222 , sizeof( V_222 ) , L_46 ,
V_74 -> V_99 / 1000 ) ;
else
F_147 ( V_222 , sizeof( V_222 ) , L_19 ) ;
if ( V_92 -> V_98 )
F_48 ( L_47 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_125 ,
V_92 -> V_98 ,
V_92 -> V_97 ,
V_222 ) ;
else
F_48 ( L_48 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_125 ,
V_92 -> V_97 ,
V_222 ) ;
}
}
bool F_148 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
F_6 ( L_49 ,
V_6 ) ;
return false ;
}
}
static void F_149 ( const struct V_1 * V_25 )
{
struct V_16 * V_18 = F_10 () ;
if ( F_22 ( V_25 -> V_26 ) ) {
if ( V_18 -> V_58 == V_59 ) {
struct V_177 * V_178 ;
V_178 = F_150 ( V_18 -> V_128 ) ;
if ( V_178 ) {
F_48 ( L_50 ,
V_178 -> V_223 [ 0 ] ,
V_178 -> V_223 [ 1 ] ) ;
} else
F_48 ( L_51 ) ;
} else
F_48 ( L_51 ) ;
} else if ( F_19 ( V_25 -> V_26 ) ) {
F_48 ( L_52 ) ;
} else {
if ( F_21 ( V_25 -> V_26 ) )
F_48 ( L_53 ) ;
else {
if ( F_78 ( V_18 ) )
F_48 ( L_54 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_48 ( L_55 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_48 ( L_56 , F_4 ( V_25 -> V_6 ) ) ;
F_146 ( V_25 ) ;
}
static void F_151 ( const struct V_1 * V_25 )
{
F_48 ( L_57 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_146 ( V_25 ) ;
}
static int F_152 ( const struct V_1 * V_25 )
{
if ( ! F_19 ( V_25 -> V_26 ) )
return - V_100 ;
F_17 ( V_25 ) ;
return 0 ;
}
static int F_153 ( const struct V_1 * V_25 ,
struct V_16 * V_187 )
{
const struct V_1 * V_224 = NULL ;
if ( ! F_25 ( V_25 -> V_26 ) )
return - V_225 ;
if ( ! F_55 ( V_25 ) ) {
F_154 ( L_58 ) ;
F_151 ( V_25 ) ;
return - V_100 ;
}
if ( ! V_187 -> V_186 ) {
F_15 ( false , V_25 ) ;
return 0 ;
}
V_224 = F_63 ( V_25 , F_1 () ) ;
if ( ! V_224 )
return - V_100 ;
F_37 ( V_25 ) ;
V_25 = NULL ;
F_15 ( false , V_224 ) ;
return 0 ;
}
static int F_155 ( const struct V_1 * V_25 ,
struct V_16 * V_190 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_224 = NULL ;
const struct V_1 * V_65 ;
struct V_3 * V_127 ;
if ( F_19 ( V_25 -> V_26 ) )
return - V_100 ;
if ( ! F_25 ( V_25 -> V_26 ) )
return - V_225 ;
if ( ! F_55 ( V_25 ) ) {
F_154 ( L_58 ) ;
F_151 ( V_25 ) ;
return - V_100 ;
}
V_127 = F_71 ( V_190 -> V_128 ) ;
if ( ! V_127 ) {
F_116 ( V_196 ,
& V_183 , 0 ) ;
return - V_226 ;
}
if ( ! V_190 -> V_186 ) {
if ( V_127 -> V_4 )
return - V_225 ;
V_4 = F_28 ( V_25 ) ;
if ( F_72 ( V_4 ) )
return F_73 ( V_4 ) ;
F_14 ( V_127 -> V_4 , V_4 ) ;
F_15 ( false , V_25 ) ;
return 0 ;
}
V_224 = F_63 ( V_25 , F_1 () ) ;
if ( ! V_224 )
return - V_100 ;
V_65 = F_3 ( V_127 ) ;
F_14 ( V_127 -> V_4 , V_25 ) ;
F_8 ( V_65 ) ;
V_25 = NULL ;
F_15 ( false , V_224 ) ;
return 0 ;
}
static int F_156 ( const struct V_1 * V_25 ,
struct V_16 * V_191 )
{
struct V_3 * V_127 ;
if ( ! F_20 ( V_25 -> V_26 ) && ! F_23 ( V_25 -> V_26 ) &&
! F_21 ( V_25 -> V_26 ) )
return - V_100 ;
if ( ! F_55 ( V_25 ) ) {
F_154 ( L_58 ) ;
F_151 ( V_25 ) ;
return - V_100 ;
}
V_127 = F_71 ( V_191 -> V_128 ) ;
if ( ! V_127 ) {
F_116 ( V_196 ,
& V_183 , 0 ) ;
return - V_226 ;
}
if ( V_191 -> V_186 )
return - V_100 ;
F_15 ( false , V_25 ) ;
return 0 ;
}
int F_40 ( const struct V_1 * V_25 )
{
struct V_16 * V_18 ;
bool V_227 = false ;
int V_14 ;
if ( ! F_51 ( V_25 -> V_26 ) ) {
F_37 ( V_25 ) ;
return - V_100 ;
}
V_18 = F_10 () ;
switch ( V_18 -> V_58 ) {
case V_121 :
V_14 = F_152 ( V_25 ) ;
break;
case V_60 :
V_14 = F_153 ( V_25 , V_18 ) ;
V_227 = true ;
break;
case V_122 :
V_14 = F_155 ( V_25 , V_18 ) ;
break;
case V_59 :
V_14 = F_156 ( V_25 , V_18 ) ;
break;
default:
F_27 ( 1 , L_36 , V_18 -> V_58 ) ;
return - V_100 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_225 :
F_102 () ;
break;
default:
F_135 ( V_227 ) ;
}
F_37 ( V_25 ) ;
return V_14 ;
}
if ( F_18 ( ! V_18 -> V_186 && V_25 != F_1 () ) )
return - V_100 ;
F_98 ( V_18 -> V_58 ) ;
F_149 ( F_1 () ) ;
F_111 ( V_18 ) ;
F_102 () ;
return 0 ;
}
void F_157 ( struct V_3 * V_3 )
{
struct V_16 * V_18 ;
if ( ! F_81 ( V_3 ) )
V_154 ++ ;
V_18 = F_10 () ;
F_97 ( V_3 , V_18 -> V_58 ) ;
}
void F_158 ( struct V_3 * V_3 )
{
struct V_3 * V_127 = NULL ;
struct V_16 * V_18 ;
V_18 = F_10 () ;
if ( ! F_81 ( V_3 ) )
V_154 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_14 ( V_3 -> V_4 , NULL ) ;
if ( V_18 )
V_127 = F_71 ( V_18 -> V_128 ) ;
if ( ! V_127 || V_127 != V_3 )
return;
V_18 -> V_128 = V_195 ;
V_18 -> V_209 = V_205 ;
}
static void F_159 ( struct V_38 * V_39 )
{
F_6 ( L_59 ) ;
F_32 () ;
F_135 ( true ) ;
F_41 () ;
}
int T_5 F_160 ( void )
{
int V_228 = 0 ;
V_51 = F_161 ( L_60 , 0 , NULL , 0 ) ;
if ( F_72 ( V_51 ) )
return F_73 ( V_51 ) ;
F_162 ( & V_181 ) ;
F_162 ( & V_199 ) ;
F_45 () ;
F_14 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_228 = F_126 ( V_23 -> V_26 ) ;
if ( V_228 ) {
if ( V_228 == - V_36 )
return V_228 ;
F_154 ( L_61 ) ;
}
if ( ! F_19 ( V_211 ) )
F_127 ( V_211 ,
V_215 ) ;
return 0 ;
}
void F_163 ( void )
{
struct V_16 * V_194 , * V_65 ;
struct V_162 * V_162 , * V_213 ;
F_164 ( & V_184 ) ;
F_165 ( & V_183 ) ;
F_32 () ;
F_15 ( true , NULL ) ;
F_41 () ;
F_166 ( & V_51 -> V_13 , true ) ;
F_167 ( V_51 ) ;
F_122 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_36 ( & V_162 -> V_45 ) ;
F_37 ( V_162 ) ;
}
F_122 (reg_beacon, btmp, &reg_beacon_list, list) {
F_36 ( & V_162 -> V_45 ) ;
F_37 ( V_162 ) ;
}
F_122 (reg_request, tmp, &reg_requests_list, list) {
F_36 ( & V_194 -> V_45 ) ;
F_37 ( V_194 ) ;
}
}
