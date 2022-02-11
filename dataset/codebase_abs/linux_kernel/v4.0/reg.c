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
static unsigned int
F_54 ( const struct V_1 * V_25 ,
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
unsigned int F_55 ( const struct V_1 * V_25 ,
const struct V_34 * V_61 )
{
unsigned int V_72 = F_54 ( V_25 , V_61 ) ;
if ( V_61 -> V_73 & V_74 )
V_72 = F_56 (unsigned int, bw, MHZ_TO_KHZ(80)) ;
if ( V_61 -> V_73 & V_75 )
V_72 = F_56 (unsigned int, bw, MHZ_TO_KHZ(40)) ;
if ( V_61 -> V_73 & V_76 &&
V_61 -> V_73 & V_77 )
V_72 = F_56 (unsigned int, bw, MHZ_TO_KHZ(20)) ;
return V_72 ;
}
static bool F_57 ( const struct V_34 * V_61 )
{
const struct V_62 * V_63 = & V_61 -> V_63 ;
T_1 V_78 ;
if ( V_63 -> V_71 <= 0 || V_63 -> V_70 <= 0 )
return false ;
if ( V_63 -> V_71 > V_63 -> V_70 )
return false ;
V_78 = V_63 -> V_70 - V_63 -> V_71 ;
if ( V_63 -> V_70 <= V_63 -> V_71 ||
V_63 -> V_79 > V_78 )
return false ;
return true ;
}
static bool F_58 ( const struct V_1 * V_25 )
{
const struct V_34 * V_80 = NULL ;
unsigned int V_32 ;
if ( ! V_25 -> V_33 )
return false ;
if ( F_20 ( V_25 -> V_33 > V_81 ) )
return false ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_80 = & V_25 -> V_37 [ V_32 ] ;
if ( ! F_57 ( V_80 ) )
return false ;
}
return true ;
}
static bool F_59 ( const struct V_62 * V_63 ,
T_1 V_82 , T_1 V_83 )
{
T_1 V_71 , V_70 ;
V_71 = V_82 - ( V_83 / 2 ) ;
V_70 = V_82 + ( V_83 / 2 ) ;
if ( V_71 >= V_63 -> V_71 &&
V_70 <= V_63 -> V_70 )
return true ;
return false ;
}
static bool F_60 ( const struct V_62 * V_63 ,
T_1 V_84 )
{
#define F_61 1000000
T_1 V_85 = V_84 > 45 * F_61 ?
10 * F_61 : 2 * F_61 ;
if ( abs ( V_84 - V_63 -> V_71 ) <= V_85 )
return true ;
if ( abs ( V_84 - V_63 -> V_70 ) <= V_85 )
return true ;
return false ;
#undef F_61
}
static enum V_5
F_62 ( const enum V_5 V_86 ,
const enum V_5 V_87 )
{
if ( V_86 != V_87 )
return V_7 ;
return V_86 ;
}
static int F_63 ( const struct V_1 * V_88 ,
const struct V_1 * V_89 ,
const struct V_34 * V_90 ,
const struct V_34 * V_91 ,
struct V_34 * V_92 )
{
const struct V_62 * V_93 , * V_94 ;
struct V_62 * V_63 ;
const struct V_95 * V_96 , * V_97 ;
struct V_95 * V_98 ;
T_1 V_78 , V_99 , V_100 ;
V_93 = & V_90 -> V_63 ;
V_94 = & V_91 -> V_63 ;
V_63 = & V_92 -> V_63 ;
V_96 = & V_90 -> V_98 ;
V_97 = & V_91 -> V_98 ;
V_98 = & V_92 -> V_98 ;
V_63 -> V_71 = F_64 ( V_93 -> V_71 ,
V_94 -> V_71 ) ;
V_63 -> V_70 = F_65 ( V_93 -> V_70 ,
V_94 -> V_70 ) ;
V_99 = V_93 -> V_79 ;
V_100 = V_94 -> V_79 ;
if ( V_90 -> V_73 & V_101 )
V_99 = F_55 ( V_88 , V_90 ) ;
if ( V_91 -> V_73 & V_101 )
V_100 = F_55 ( V_89 , V_91 ) ;
V_63 -> V_79 = F_65 ( V_99 , V_100 ) ;
V_92 -> V_73 = V_90 -> V_73 | V_91 -> V_73 ;
if ( ( V_90 -> V_73 & V_101 ) &&
( V_91 -> V_73 & V_101 ) )
V_92 -> V_73 |= V_101 ;
else
V_92 -> V_73 &= ~ V_101 ;
V_78 = V_63 -> V_70 - V_63 -> V_71 ;
if ( V_63 -> V_79 > V_78 )
V_63 -> V_79 = V_78 ;
V_98 -> V_102 = F_65 ( V_96 -> V_102 ,
V_97 -> V_102 ) ;
V_98 -> V_103 = F_65 ( V_96 -> V_103 ,
V_97 -> V_103 ) ;
V_92 -> V_104 = F_64 ( V_90 -> V_104 ,
V_91 -> V_104 ) ;
if ( ! F_57 ( V_92 ) )
return - V_105 ;
return 0 ;
}
static bool F_66 ( struct V_34 * V_106 ,
struct V_34 * V_107 )
{
if ( V_106 -> V_73 != V_107 -> V_73 )
return false ;
if ( ( V_106 -> V_98 . V_103 >
V_107 -> V_98 . V_103 ) ||
V_106 -> V_98 . V_102 > V_107 -> V_98 . V_102 )
return false ;
if ( V_106 -> V_63 . V_71 > V_107 -> V_63 . V_71 ||
V_106 -> V_63 . V_70 < V_107 -> V_63 . V_70 )
return false ;
if ( V_106 -> V_63 . V_79 <
V_107 -> V_63 . V_79 )
return false ;
return true ;
}
static void F_67 ( struct V_34 * V_61 ,
struct V_34 * V_37 , T_1 * V_108 )
{
struct V_34 * V_109 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < * V_108 ; V_32 ++ ) {
V_109 = & V_37 [ V_32 ] ;
if ( F_66 ( V_109 , V_61 ) )
return;
if ( F_66 ( V_61 , V_109 ) ) {
memcpy ( V_109 , V_61 , sizeof( * V_61 ) ) ;
return;
}
}
memcpy ( & V_37 [ * V_108 ] , V_61 , sizeof( * V_61 ) ) ;
( * V_108 ) ++ ;
}
static struct V_1 *
F_68 ( const struct V_1 * V_88 ,
const struct V_1 * V_89 )
{
int V_14 , V_31 ;
unsigned int V_110 , V_111 ;
unsigned int V_112 = 0 ;
const struct V_34 * V_90 , * V_91 ;
struct V_34 V_92 ;
struct V_1 * V_25 ;
if ( ! V_88 || ! V_89 )
return NULL ;
for ( V_110 = 0 ; V_110 < V_88 -> V_33 ; V_110 ++ ) {
V_90 = & V_88 -> V_37 [ V_110 ] ;
for ( V_111 = 0 ; V_111 < V_89 -> V_33 ; V_111 ++ ) {
V_91 = & V_89 -> V_37 [ V_111 ] ;
if ( ! F_63 ( V_88 , V_89 , V_90 , V_91 ,
& V_92 ) )
V_112 ++ ;
}
}
if ( ! V_112 )
return NULL ;
V_31 = sizeof( struct V_1 ) +
V_112 * sizeof( struct V_34 ) ;
V_25 = F_31 ( V_31 , V_35 ) ;
if ( ! V_25 )
return NULL ;
for ( V_110 = 0 ; V_110 < V_88 -> V_33 ; V_110 ++ ) {
V_90 = & V_88 -> V_37 [ V_110 ] ;
for ( V_111 = 0 ; V_111 < V_89 -> V_33 ; V_111 ++ ) {
V_91 = & V_89 -> V_37 [ V_111 ] ;
V_14 = F_63 ( V_88 , V_89 , V_90 , V_91 ,
& V_92 ) ;
if ( V_14 )
continue;
F_67 ( & V_92 , V_25 -> V_37 ,
& V_25 -> V_33 ) ;
}
}
V_25 -> V_26 [ 0 ] = '9' ;
V_25 -> V_26 [ 1 ] = '8' ;
V_25 -> V_6 = F_62 ( V_88 -> V_6 ,
V_89 -> V_6 ) ;
return V_25 ;
}
static T_1 F_69 ( T_1 V_113 )
{
T_1 V_114 = 0 ;
if ( V_113 & V_115 )
V_114 |= V_116 ;
if ( V_113 & V_117 )
V_114 |= V_118 ;
if ( V_113 & V_119 )
V_114 |= V_120 ;
if ( V_113 & V_121 )
V_114 |= V_122 ;
if ( V_113 & V_123 )
V_114 |= V_124 ;
if ( V_113 & V_76 )
V_114 |= V_125 ;
if ( V_113 & V_77 )
V_114 |= V_126 ;
if ( V_113 & V_75 )
V_114 |= V_127 ;
if ( V_113 & V_74 )
V_114 |= V_128 ;
return V_114 ;
}
static const struct V_34 *
F_70 ( struct V_3 * V_3 , T_1 V_129 ,
const struct V_1 * V_4 )
{
int V_32 ;
bool V_130 = false ;
bool V_131 = false ;
if ( ! V_4 )
return F_32 ( - V_105 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; V_32 ++ ) {
const struct V_34 * V_132 ;
const struct V_62 * V_133 = NULL ;
V_132 = & V_4 -> V_37 [ V_32 ] ;
V_133 = & V_132 -> V_63 ;
if ( ! V_130 )
V_130 = F_60 ( V_133 , V_129 ) ;
V_131 = F_59 ( V_133 , V_129 , F_71 ( 20 ) ) ;
if ( V_130 && V_131 )
return V_132 ;
}
if ( ! V_130 )
return F_32 ( - V_134 ) ;
return F_32 ( - V_105 ) ;
}
const struct V_34 * F_72 ( struct V_3 * V_3 ,
T_1 V_129 )
{
const struct V_1 * V_4 ;
V_4 = F_53 ( V_3 ) ;
return F_70 ( V_3 , V_129 , V_4 ) ;
}
const char * F_73 ( enum V_135 V_58 )
{
switch ( V_58 ) {
case V_136 :
return L_14 ;
case V_60 :
return L_15 ;
case V_137 :
return L_16 ;
case V_59 :
return L_17 ;
default:
F_20 ( 1 ) ;
return L_18 ;
}
}
static void F_74 ( const struct V_1 * V_4 ,
struct V_138 * V_139 ,
const struct V_34 * V_80 )
{
const struct V_95 * V_98 ;
const struct V_62 * V_63 ;
char V_103 [ 32 ] , V_72 [ 32 ] ;
V_98 = & V_80 -> V_98 ;
V_63 = & V_80 -> V_63 ;
if ( ! V_98 -> V_103 )
snprintf ( V_103 , sizeof( V_103 ) , L_19 ) ;
else
snprintf ( V_103 , sizeof( V_103 ) , L_20 ,
V_98 -> V_103 ) ;
if ( V_80 -> V_73 & V_101 )
snprintf ( V_72 , sizeof( V_72 ) , L_21 ,
V_63 -> V_79 ,
F_55 ( V_4 , V_80 ) ) ;
else
snprintf ( V_72 , sizeof( V_72 ) , L_22 ,
V_63 -> V_79 ) ;
F_6 ( L_23 ,
V_139 -> V_129 ) ;
F_6 ( L_24 ,
V_63 -> V_71 , V_63 -> V_70 ,
V_72 , V_103 ,
V_98 -> V_102 ) ;
}
static void F_74 ( const struct V_1 * V_4 ,
struct V_138 * V_139 ,
const struct V_34 * V_80 )
{
return;
}
static void F_75 ( struct V_3 * V_3 ,
enum V_135 V_58 ,
struct V_138 * V_139 )
{
T_1 V_73 , V_140 = 0 ;
const struct V_34 * V_80 = NULL ;
const struct V_95 * V_98 = NULL ;
const struct V_62 * V_63 = NULL ;
struct V_3 * V_141 = NULL ;
struct V_16 * V_19 = F_10 () ;
const struct V_1 * V_4 ;
T_1 V_79 ;
V_141 = F_76 ( V_19 -> V_142 ) ;
V_73 = V_139 -> V_143 ;
V_80 = F_72 ( V_3 , F_71 ( V_139 -> V_129 ) ) ;
if ( F_77 ( V_80 ) ) {
if ( V_58 == V_59 &&
F_78 ( V_80 ) == - V_134 )
return;
if ( V_19 -> V_58 == V_137 &&
V_141 && V_141 == V_3 &&
V_141 -> V_144 & V_145 ) {
F_6 ( L_25 ,
V_139 -> V_129 ) ;
V_139 -> V_143 |= V_146 ;
V_139 -> V_73 = V_139 -> V_143 ;
} else {
F_6 ( L_26 ,
V_139 -> V_129 ) ;
V_139 -> V_73 |= V_146 ;
}
return;
}
V_4 = F_53 ( V_3 ) ;
F_74 ( V_4 , V_139 , V_80 ) ;
V_98 = & V_80 -> V_98 ;
V_63 = & V_80 -> V_63 ;
V_79 = V_63 -> V_79 ;
if ( V_80 -> V_73 & V_101 )
V_79 = F_55 ( V_4 , V_80 ) ;
if ( V_79 < F_71 ( 40 ) )
V_140 = V_147 ;
if ( V_79 < F_71 ( 80 ) )
V_140 |= V_127 ;
if ( V_79 < F_71 ( 160 ) )
V_140 |= V_128 ;
if ( V_19 -> V_58 == V_137 &&
V_141 && V_141 == V_3 &&
V_141 -> V_144 & V_145 ) {
V_139 -> V_73 = V_139 -> V_143 =
F_69 ( V_80 -> V_73 ) | V_140 ;
V_139 -> V_103 = V_139 -> V_148 =
( int ) F_79 ( V_98 -> V_103 ) ;
V_139 -> V_149 = V_139 -> V_150 = V_139 -> V_151 =
( int ) F_80 ( V_98 -> V_102 ) ;
if ( V_139 -> V_73 & V_118 ) {
V_139 -> V_104 = V_152 ;
if ( V_80 -> V_104 )
V_139 -> V_104 = V_80 -> V_104 ;
}
return;
}
V_139 -> V_153 = V_154 ;
V_139 -> V_155 = V_156 ;
V_139 -> V_157 = false ;
V_139 -> V_73 = V_73 | V_140 | F_69 ( V_80 -> V_73 ) ;
V_139 -> V_103 =
F_56 ( int , V_139 -> V_148 ,
F_79 ( V_98 -> V_103 ) ) ;
V_139 -> V_149 = ( int ) F_80 ( V_98 -> V_102 ) ;
if ( V_139 -> V_73 & V_118 ) {
if ( V_80 -> V_104 )
V_139 -> V_104 = V_80 -> V_104 ;
else
V_139 -> V_104 = V_152 ;
}
if ( V_139 -> V_151 ) {
if ( V_58 == V_59 &&
V_3 -> V_144 & V_158 )
V_139 -> V_150 = V_139 -> V_149 ;
else
V_139 -> V_150 = F_65 ( V_139 -> V_151 ,
V_139 -> V_149 ) ;
} else
V_139 -> V_150 = V_139 -> V_149 ;
}
static void F_81 ( struct V_3 * V_3 ,
enum V_135 V_58 ,
struct V_159 * V_160 )
{
unsigned int V_32 ;
if ( ! V_160 )
return;
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ )
F_75 ( V_3 , V_58 , & V_160 -> V_162 [ V_32 ] ) ;
}
static bool F_82 ( struct V_16 * V_18 )
{
if ( V_18 -> V_58 != V_60 )
return false ;
return V_18 -> V_163 == V_164 ;
}
static bool F_83 ( struct V_16 * V_18 )
{
if ( V_18 -> V_58 != V_60 )
return false ;
return V_18 -> V_163 == V_165 ;
}
bool F_84 ( void )
{
return F_82 ( F_10 () ) ;
}
static enum V_54
F_85 ( struct V_16 * V_166 )
{
struct V_16 * V_19 = F_10 () ;
if ( ! V_167 )
return V_55 ;
if ( F_82 ( V_19 ) &&
! F_27 ( V_166 -> V_26 ) )
return V_168 ;
return V_56 ;
}
static bool F_86 ( struct V_3 * V_3 )
{
return ! ( V_3 -> V_169 & V_170 ) ;
}
static int F_85 ( struct V_16 * V_166 )
{
return V_55 ;
}
static bool F_86 ( struct V_3 * V_3 )
{
return true ;
}
static bool F_87 ( struct V_3 * V_3 )
{
if ( V_3 -> V_144 & V_145 &&
! ( V_3 -> V_144 & V_171 ) )
return true ;
return false ;
}
static bool F_88 ( struct V_3 * V_3 ,
enum V_135 V_58 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_3 -> V_144 & V_172 )
return true ;
if ( ! V_19 ) {
F_6 ( L_27
L_28 ,
F_73 ( V_58 ) ) ;
return true ;
}
if ( V_58 == V_136 &&
V_3 -> V_144 & V_171 ) {
F_6 ( L_27
L_29
L_30 ,
F_73 ( V_58 ) ) ;
return true ;
}
if ( F_87 ( V_3 ) && ! V_3 -> V_4 &&
V_58 != V_59 &&
! F_21 ( V_19 -> V_26 ) ) {
F_6 ( L_27
L_31
L_32 ,
F_73 ( V_58 ) ) ;
return true ;
}
if ( F_82 ( V_19 ) )
return F_86 ( V_3 ) ;
return false ;
}
static bool F_89 ( struct V_3 * V_3 )
{
const struct V_1 * V_173 = F_1 () ;
const struct V_1 * V_174 = F_3 ( V_3 ) ;
struct V_16 * V_19 = F_10 () ;
if ( F_21 ( V_173 -> V_26 ) || ( V_174 && F_21 ( V_174 -> V_26 ) ) )
return true ;
if ( V_19 && V_19 -> V_58 != V_59 &&
V_3 -> V_144 & V_171 )
return true ;
return false ;
}
static void F_90 ( struct V_3 * V_3 , unsigned int V_175 ,
struct V_176 * V_176 )
{
struct V_159 * V_160 ;
struct V_138 * V_139 ;
bool V_177 = false ;
struct V_138 V_178 ;
V_160 = V_3 -> V_179 [ V_176 -> V_139 . V_180 ] ;
V_139 = & V_160 -> V_162 [ V_175 ] ;
if ( F_91 ( V_139 -> V_129 != V_176 -> V_139 . V_129 ) )
return;
if ( V_139 -> V_157 )
return;
V_139 -> V_157 = true ;
if ( ! F_89 ( V_3 ) )
return;
if ( V_3 -> V_144 & V_181 )
return;
V_178 . V_129 = V_139 -> V_129 ;
V_178 . V_73 = V_139 -> V_73 ;
if ( V_139 -> V_73 & V_116 ) {
V_139 -> V_73 &= ~ V_116 ;
V_177 = true ;
}
if ( V_177 )
F_92 ( V_3 , & V_178 , V_139 ) ;
}
static void F_93 ( struct V_3 * V_3 ,
struct V_176 * V_176 )
{
unsigned int V_32 ;
struct V_159 * V_160 ;
if ( ! V_3 -> V_179 [ V_176 -> V_139 . V_180 ] )
return;
V_160 = V_3 -> V_179 [ V_176 -> V_139 . V_180 ] ;
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ )
F_90 ( V_3 , V_32 , V_176 ) ;
}
static void F_94 ( struct V_3 * V_3 )
{
unsigned int V_32 ;
struct V_159 * V_160 ;
struct V_176 * V_176 ;
F_95 (reg_beacon, &reg_beacon_list, list) {
if ( ! V_3 -> V_179 [ V_176 -> V_139 . V_180 ] )
continue;
V_160 = V_3 -> V_179 [ V_176 -> V_139 . V_180 ] ;
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ )
F_90 ( V_3 , V_32 , V_176 ) ;
}
}
static void F_96 ( struct V_3 * V_3 )
{
if ( ! V_17 )
return;
F_94 ( V_3 ) ;
}
static bool F_97 ( struct V_138 * V_139 )
{
if ( ! V_139 )
return false ;
if ( V_139 -> V_73 & V_146 )
return false ;
if ( ( V_139 -> V_73 & V_147 ) == V_147 )
return false ;
return true ;
}
static void F_98 ( struct V_3 * V_3 ,
struct V_138 * V_182 )
{
struct V_159 * V_160 = V_3 -> V_179 [ V_182 -> V_180 ] ;
struct V_138 * V_183 = NULL , * V_184 = NULL ;
unsigned int V_32 ;
if ( ! F_97 ( V_182 ) ) {
V_182 -> V_73 |= V_147 ;
return;
}
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ ) {
struct V_138 * V_185 = & V_160 -> V_162 [ V_32 ] ;
if ( V_185 -> V_129 == ( V_182 -> V_129 - 20 ) )
V_183 = V_185 ;
if ( V_185 -> V_129 == ( V_182 -> V_129 + 20 ) )
V_184 = V_185 ;
}
if ( ! F_97 ( V_183 ) )
V_182 -> V_73 |= V_125 ;
else
V_182 -> V_73 &= ~ V_125 ;
if ( ! F_97 ( V_184 ) )
V_182 -> V_73 |= V_126 ;
else
V_182 -> V_73 &= ~ V_126 ;
}
static void F_99 ( struct V_3 * V_3 ,
struct V_159 * V_160 )
{
unsigned int V_32 ;
if ( ! V_160 )
return;
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ )
F_98 ( V_3 , & V_160 -> V_162 [ V_32 ] ) ;
}
static void F_100 ( struct V_3 * V_3 )
{
enum V_186 V_180 ;
if ( ! V_3 )
return;
for ( V_180 = 0 ; V_180 < V_187 ; V_180 ++ )
F_99 ( V_3 , V_3 -> V_179 [ V_180 ] ) ;
}
static void F_101 ( struct V_3 * V_3 ,
struct V_16 * V_18 )
{
if ( V_3 -> V_188 )
V_3 -> V_188 ( V_3 , V_18 ) ;
}
static bool F_102 ( struct V_3 * V_3 , struct V_189 * V_190 )
{
struct V_191 V_192 ;
struct V_193 * V_194 = F_103 ( V_3 ) ;
enum V_195 V_196 ;
F_104 ( V_190 ) ;
V_196 = V_190 -> V_196 ;
if ( ! V_190 -> V_197 || ! F_105 ( V_190 -> V_197 ) )
goto V_198;
switch ( V_196 ) {
case V_199 :
case V_200 :
if ( ! V_190 -> V_201 )
goto V_198;
V_192 = V_190 -> V_192 ;
break;
case V_202 :
if ( ! V_190 -> V_203 )
goto V_198;
V_192 = V_190 -> V_192 ;
break;
case V_204 :
case V_205 :
if ( ! V_190 -> V_206 ||
! V_190 -> V_206 -> V_207 . V_182 )
goto V_198;
if ( ! V_194 -> V_208 -> V_209 ||
F_106 ( V_194 , V_190 , & V_192 ) )
F_107 ( & V_192 ,
V_190 -> V_206 -> V_207 . V_182 ,
V_210 ) ;
break;
case V_211 :
case V_212 :
case V_213 :
break;
default:
F_20 ( 1 ) ;
break;
}
F_108 ( V_190 ) ;
switch ( V_196 ) {
case V_199 :
case V_200 :
case V_202 :
return F_109 ( V_3 , & V_192 , V_196 ) ;
case V_204 :
case V_205 :
return F_110 ( V_3 , & V_192 ,
V_146 ) ;
default:
break;
}
return true ;
V_198:
F_108 ( V_190 ) ;
return true ;
}
static void F_111 ( struct V_3 * V_3 )
{
struct V_189 * V_190 ;
struct V_193 * V_194 = F_103 ( V_3 ) ;
F_18 () ;
F_95 (wdev, &rdev->wdev_list, list)
if ( ! F_102 ( V_3 , V_190 ) )
F_112 ( V_194 , V_190 ) ;
}
static void F_113 ( struct V_38 * V_39 )
{
struct V_193 * V_194 ;
F_6 ( L_33 ) ;
F_34 () ;
F_95 (rdev, &cfg80211_rdev_list, list)
if ( ! ( V_194 -> V_3 . V_144 &
V_214 ) )
F_111 ( & V_194 -> V_3 ) ;
F_42 () ;
}
static void F_114 ( void )
{
F_115 ( V_215 ,
& V_216 ,
F_116 ( V_217 ) ) ;
}
static void F_117 ( struct V_3 * V_3 ,
enum V_135 V_58 )
{
enum V_186 V_180 ;
struct V_16 * V_19 = F_10 () ;
if ( F_88 ( V_3 , V_58 ) ) {
if ( V_58 == V_136 &&
V_3 -> V_144 & V_171 )
F_101 ( V_3 , V_19 ) ;
return;
}
V_19 -> V_6 = F_1 () -> V_6 ;
for ( V_180 = 0 ; V_180 < V_187 ; V_180 ++ )
F_81 ( V_3 , V_58 , V_3 -> V_179 [ V_180 ] ) ;
F_96 ( V_3 ) ;
F_100 ( V_3 ) ;
F_101 ( V_3 , V_19 ) ;
}
static void F_118 ( enum V_135 V_58 )
{
struct V_193 * V_194 ;
struct V_3 * V_3 ;
F_18 () ;
F_95 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_194 -> V_3 ;
F_117 ( V_3 , V_58 ) ;
}
F_114 () ;
}
static void F_119 ( struct V_3 * V_3 ,
struct V_138 * V_139 ,
const struct V_1 * V_4 )
{
T_1 V_140 = 0 ;
const struct V_34 * V_80 = NULL ;
const struct V_95 * V_98 = NULL ;
const struct V_62 * V_63 = NULL ;
T_1 V_79 ;
V_80 = F_70 ( V_3 , F_71 ( V_139 -> V_129 ) ,
V_4 ) ;
if ( F_77 ( V_80 ) ) {
F_6 ( L_34 ,
V_139 -> V_129 ) ;
if ( V_3 -> V_144 & V_172 ) {
V_139 -> V_73 |= V_146 ;
} else {
V_139 -> V_143 |= V_146 ;
V_139 -> V_73 = V_139 -> V_143 ;
}
return;
}
F_74 ( V_4 , V_139 , V_80 ) ;
V_98 = & V_80 -> V_98 ;
V_63 = & V_80 -> V_63 ;
V_79 = V_63 -> V_79 ;
if ( V_80 -> V_73 & V_101 )
V_79 = F_55 ( V_4 , V_80 ) ;
if ( V_79 < F_71 ( 40 ) )
V_140 = V_147 ;
if ( V_79 < F_71 ( 80 ) )
V_140 |= V_127 ;
if ( V_79 < F_71 ( 160 ) )
V_140 |= V_128 ;
V_139 -> V_155 = V_156 ;
V_139 -> V_153 = V_154 ;
V_139 -> V_157 = false ;
if ( V_3 -> V_144 & V_172 )
V_139 -> V_73 = V_139 -> V_143 | V_140 |
F_69 ( V_80 -> V_73 ) ;
else
V_139 -> V_73 |= F_69 ( V_80 -> V_73 ) | V_140 ;
V_139 -> V_103 = ( int ) F_79 ( V_98 -> V_103 ) ;
V_139 -> V_149 = V_139 -> V_150 =
( int ) F_80 ( V_98 -> V_102 ) ;
if ( V_139 -> V_73 & V_118 ) {
if ( V_80 -> V_104 )
V_139 -> V_104 = V_80 -> V_104 ;
else
V_139 -> V_104 = V_152 ;
}
V_139 -> V_150 = V_139 -> V_149 ;
}
static void F_120 ( struct V_3 * V_3 ,
struct V_159 * V_160 ,
const struct V_1 * V_4 )
{
unsigned int V_32 ;
if ( ! V_160 )
return;
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ )
F_119 ( V_3 , & V_160 -> V_162 [ V_32 ] , V_4 ) ;
}
void F_121 ( struct V_3 * V_3 ,
const struct V_1 * V_4 )
{
enum V_186 V_180 ;
unsigned int V_218 = 0 ;
F_29 ( ! ( V_3 -> V_144 & V_171 ) ,
L_35 ) ;
V_3 -> V_144 |= V_171 ;
for ( V_180 = 0 ; V_180 < V_187 ; V_180 ++ ) {
if ( ! V_3 -> V_179 [ V_180 ] )
continue;
F_120 ( V_3 , V_3 -> V_179 [ V_180 ] , V_4 ) ;
V_218 ++ ;
}
F_20 ( ! V_218 ) ;
}
static void F_122 ( void )
{
bool V_219 = false ;
struct V_16 * V_19 = F_10 () ;
V_19 -> V_57 = true ;
F_123 ( & V_220 ) ;
if ( ! F_36 ( & V_221 ) )
V_219 = true ;
F_124 ( & V_220 ) ;
if ( V_19 -> V_58 == V_60 )
F_125 ( & V_222 ) ;
if ( V_219 )
F_45 ( & V_223 ) ;
}
static enum V_54
F_126 ( struct V_16 * V_224 )
{
V_224 -> V_225 = false ;
V_224 -> V_57 = false ;
F_15 ( V_224 ) ;
return F_51 ( V_224 ) ;
}
static enum V_54
F_127 ( struct V_16 * V_226 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_83 ( V_226 ) ) {
V_227 = true ;
return V_228 ;
}
if ( F_82 ( V_226 ) )
return F_85 ( V_226 ) ;
if ( F_82 ( V_19 ) )
return V_55 ;
if ( V_19 -> V_58 == V_59 )
return V_229 ;
if ( V_19 -> V_58 == V_60 &&
V_19 -> V_225 )
return V_55 ;
if ( ( V_19 -> V_58 == V_136 ||
V_19 -> V_58 == V_137 ||
V_19 -> V_58 == V_60 ) &&
F_27 ( V_19 -> V_26 ) )
return V_55 ;
if ( ! F_27 ( V_226 -> V_26 ) )
return V_168 ;
return V_56 ;
}
static enum V_54
F_128 ( struct V_16 * V_226 )
{
enum V_54 V_230 ;
V_230 = F_127 ( V_226 ) ;
if ( V_230 == V_55 ||
V_230 == V_168 ||
V_230 == V_228 ) {
F_12 ( V_226 ) ;
return V_230 ;
}
V_226 -> V_225 = V_230 == V_229 ;
V_226 -> V_57 = false ;
F_15 ( V_226 ) ;
V_29 [ 0 ] = V_226 -> V_26 [ 0 ] ;
V_29 [ 1 ] = V_226 -> V_26 [ 1 ] ;
return F_51 ( V_226 ) ;
}
static enum V_54
F_129 ( struct V_16 * V_231 )
{
struct V_16 * V_19 = F_10 () ;
if ( V_19 -> V_58 == V_136 ) {
if ( F_27 ( V_231 -> V_26 ) )
return V_56 ;
return V_168 ;
}
if ( V_19 -> V_58 == V_137 &&
! F_27 ( V_231 -> V_26 ) )
return V_168 ;
return V_229 ;
}
static enum V_54
F_130 ( struct V_3 * V_3 ,
struct V_16 * V_231 )
{
const struct V_1 * V_4 , * V_65 ;
enum V_54 V_230 ;
V_230 = F_129 ( V_231 ) ;
switch ( V_230 ) {
case V_56 :
break;
case V_55 :
case V_228 :
F_12 ( V_231 ) ;
return V_230 ;
case V_229 :
case V_168 :
V_4 = F_30 ( F_1 () ) ;
if ( F_77 ( V_4 ) ) {
F_12 ( V_231 ) ;
return V_55 ;
}
V_65 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_65 ) ;
}
V_231 -> V_225 = V_230 == V_229 ;
V_231 -> V_57 = false ;
F_15 ( V_231 ) ;
if ( V_230 == V_168 ) {
F_131 ( V_231 ) ;
F_122 () ;
return V_230 ;
}
return F_51 ( V_231 ) ;
}
static enum V_54
F_132 ( struct V_3 * V_3 ,
struct V_16 * V_232 )
{
struct V_3 * V_233 = NULL ;
struct V_16 * V_19 = F_10 () ;
if ( F_82 ( V_19 ) ) {
if ( F_27 ( V_232 -> V_26 ) )
return V_55 ;
return V_168 ;
} else {
if ( V_3 -> V_144 & V_234 )
return V_55 ;
}
if ( F_133 ( ! F_25 ( V_232 -> V_26 ) ) )
return - V_105 ;
if ( V_19 -> V_58 != V_59 )
return V_56 ;
V_233 = F_76 ( V_19 -> V_142 ) ;
if ( V_233 != V_3 ) {
if ( F_27 ( V_232 -> V_26 ) )
return V_55 ;
return V_168 ;
}
if ( F_27 ( V_232 -> V_26 ) )
return V_56 ;
return V_168 ;
}
static enum V_54
F_134 ( struct V_3 * V_3 ,
struct V_16 * V_232 )
{
enum V_54 V_230 ;
V_230 = F_132 ( V_3 , V_232 ) ;
switch ( V_230 ) {
case V_56 :
break;
case V_55 :
case V_228 :
case V_168 :
F_12 ( V_232 ) ;
return V_230 ;
case V_229 :
F_12 ( V_232 ) ;
F_47 ( 1 , L_36 ) ;
return V_55 ;
}
V_232 -> V_225 = false ;
V_232 -> V_57 = false ;
F_15 ( V_232 ) ;
return F_51 ( V_232 ) ;
}
static void F_135 ( struct V_16 * V_235 )
{
struct V_3 * V_3 = NULL ;
enum V_54 V_230 ;
if ( V_235 -> V_142 != V_236 )
V_3 = F_76 ( V_235 -> V_142 ) ;
switch ( V_235 -> V_58 ) {
case V_136 :
F_126 ( V_235 ) ;
return;
case V_60 :
V_230 = F_128 ( V_235 ) ;
if ( V_230 == V_55 ||
V_230 == V_168 ||
V_230 == V_228 )
return;
F_136 ( V_215 ,
& V_222 , F_116 ( 3142 ) ) ;
return;
case V_137 :
if ( ! V_3 )
goto V_237;
V_230 = F_130 ( V_3 , V_235 ) ;
break;
case V_59 :
if ( ! V_3 )
goto V_237;
V_230 = F_134 ( V_3 , V_235 ) ;
break;
default:
F_29 ( 1 , L_37 , V_235 -> V_58 ) ;
goto V_237;
}
if ( V_230 == V_168 && V_3 &&
V_3 -> V_144 & V_145 ) {
F_117 ( V_3 , V_235 -> V_58 ) ;
F_114 () ;
}
return;
V_237:
F_12 ( V_235 ) ;
}
static bool F_137 ( void )
{
struct V_193 * V_194 ;
struct V_3 * V_3 ;
bool V_238 = false ;
F_18 () ;
F_95 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_194 -> V_3 ;
if ( V_3 -> V_144 & V_172 )
V_238 = true ;
else
return false ;
}
return V_238 ;
}
static void F_138 ( void )
{
struct V_16 * V_235 , * V_19 ;
V_19 = F_10 () ;
if ( V_19 && ! V_19 -> V_57 ) {
F_135 ( V_19 ) ;
return;
}
F_123 ( & V_220 ) ;
if ( F_36 ( & V_221 ) ) {
F_124 ( & V_220 ) ;
return;
}
V_235 = F_37 ( & V_221 ,
struct V_16 ,
V_45 ) ;
F_139 ( & V_235 -> V_45 ) ;
F_124 ( & V_220 ) ;
if ( F_137 () ) {
F_12 ( V_235 ) ;
return;
}
F_135 ( V_235 ) ;
}
static void F_140 ( void )
{
struct V_193 * V_194 ;
struct V_176 * V_239 , * V_65 ;
F_141 ( & V_240 ) ;
F_142 (pending_beacon, tmp,
&reg_pending_beacons, list) {
F_139 ( & V_239 -> V_45 ) ;
F_95 (rdev, &cfg80211_rdev_list, list)
F_93 ( & V_194 -> V_3 , V_239 ) ;
F_44 ( & V_239 -> V_45 , & V_241 ) ;
}
F_143 ( & V_240 ) ;
}
static void F_144 ( void )
{
struct V_193 * V_194 ;
struct V_3 * V_3 ;
const struct V_1 * V_65 ;
const struct V_1 * V_4 ;
enum V_186 V_180 ;
struct V_16 V_18 = {} ;
F_95 (rdev, &cfg80211_rdev_list, list) {
V_3 = & V_194 -> V_3 ;
F_123 ( & V_220 ) ;
V_4 = V_194 -> V_242 ;
V_194 -> V_242 = NULL ;
F_124 ( & V_220 ) ;
if ( V_4 == NULL )
continue;
V_65 = F_3 ( V_3 ) ;
F_16 ( V_3 -> V_4 , V_4 ) ;
F_8 ( V_65 ) ;
for ( V_180 = 0 ; V_180 < V_187 ; V_180 ++ )
F_120 ( V_3 , V_3 -> V_179 [ V_180 ] , V_4 ) ;
F_100 ( V_3 ) ;
V_18 . V_142 = F_145 ( V_3 ) ;
V_18 . V_26 [ 0 ] = V_4 -> V_26 [ 0 ] ;
V_18 . V_26 [ 1 ] = V_4 -> V_26 [ 1 ] ;
V_18 . V_58 = V_137 ;
F_146 ( & V_18 ) ;
}
F_114 () ;
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
F_123 ( & V_220 ) ;
F_44 ( & V_18 -> V_45 , & V_221 ) ;
F_124 ( & V_220 ) ;
F_45 ( & V_223 ) ;
}
static int F_149 ( const char * V_26 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_136 ;
F_148 ( V_18 ) ;
return 0 ;
}
int F_150 ( const char * V_26 ,
enum V_243 V_163 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 ) )
return - V_105 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_142 = V_236 ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_60 ;
V_18 -> V_163 = V_163 ;
F_148 ( V_18 ) ;
return 0 ;
}
int F_151 ( void )
{
struct V_16 * V_18 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_142 = V_236 ;
V_18 -> V_58 = V_60 ;
V_18 -> V_163 = V_165 ;
F_148 ( V_18 ) ;
return 0 ;
}
int F_152 ( struct V_3 * V_3 , const char * V_26 )
{
struct V_16 * V_18 ;
if ( F_20 ( ! V_26 || ! V_3 ) )
return - V_105 ;
V_3 -> V_144 &= ~ V_171 ;
V_18 = F_31 ( sizeof( struct V_16 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_142 = F_145 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_137 ;
F_148 ( V_18 ) ;
return 0 ;
}
void F_153 ( struct V_3 * V_3 , enum V_186 V_180 ,
const T_2 * V_244 , T_2 V_245 )
{
char V_26 [ 2 ] ;
enum V_246 V_50 = V_247 ;
struct V_16 * V_18 = NULL , * V_19 ;
if ( V_245 & 0x01 )
return;
if ( V_245 < V_248 )
return;
V_18 = F_31 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return;
V_26 [ 0 ] = V_244 [ 0 ] ;
V_26 [ 1 ] = V_244 [ 1 ] ;
if ( V_244 [ 2 ] == 'I' )
V_50 = V_249 ;
else if ( V_244 [ 2 ] == 'O' )
V_50 = V_250 ;
F_154 () ;
V_19 = F_10 () ;
if ( F_133 ( ! V_19 ) )
goto V_12;
if ( V_19 -> V_58 == V_59 &&
V_19 -> V_142 != V_236 )
goto V_12;
V_18 -> V_142 = F_145 ( V_3 ) ;
V_18 -> V_26 [ 0 ] = V_26 [ 0 ] ;
V_18 -> V_26 [ 1 ] = V_26 [ 1 ] ;
V_18 -> V_58 = V_59 ;
V_18 -> V_251 = V_50 ;
F_148 ( V_18 ) ;
V_18 = NULL ;
V_12:
F_13 ( V_18 ) ;
F_155 () ;
}
static void F_156 ( char * V_26 , bool V_252 )
{
V_26 [ 0 ] = '9' ;
V_26 [ 1 ] = '7' ;
if ( F_28 () ) {
if ( V_252 ) {
F_6 ( L_38 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
if ( ! F_21 ( V_253 ) ) {
F_6 ( L_39 ,
V_253 [ 0 ] , V_253 [ 1 ] ) ;
V_26 [ 0 ] = V_253 [ 0 ] ;
V_26 [ 1 ] = V_253 [ 1 ] ;
}
} else {
F_6 ( L_40 ,
V_29 [ 0 ] , V_29 [ 1 ] ) ;
V_26 [ 0 ] = V_29 [ 0 ] ;
V_26 [ 1 ] = V_29 [ 1 ] ;
}
} else if ( ! F_21 ( V_253 ) ) {
F_6 ( L_39 ,
V_253 [ 0 ] , V_253 [ 1 ] ) ;
V_26 [ 0 ] = V_253 [ 0 ] ;
V_26 [ 1 ] = V_253 [ 1 ] ;
} else
F_6 ( L_41 ) ;
}
static void F_157 ( struct V_3 * V_3 )
{
struct V_159 * V_160 ;
enum V_186 V_180 ;
struct V_138 * V_139 ;
int V_32 ;
for ( V_180 = 0 ; V_180 < V_187 ; V_180 ++ ) {
V_160 = V_3 -> V_179 [ V_180 ] ;
if ( ! V_160 )
continue;
for ( V_32 = 0 ; V_32 < V_160 -> V_161 ; V_32 ++ ) {
V_139 = & V_160 -> V_162 [ V_32 ] ;
V_139 -> V_73 = V_139 -> V_143 ;
V_139 -> V_103 = V_139 -> V_148 ;
V_139 -> V_150 = V_139 -> V_151 ;
V_139 -> V_157 = false ;
}
}
}
static void F_158 ( bool V_252 )
{
char V_26 [ 2 ] ;
char V_254 [ 2 ] ;
struct V_176 * V_176 , * V_255 ;
struct V_16 * V_235 , * V_65 ;
F_159 ( V_256 ) ;
struct V_193 * V_194 ;
F_18 () ;
V_227 = false ;
F_17 ( true , & V_24 ) ;
F_156 ( V_26 , V_252 ) ;
F_123 ( & V_220 ) ;
F_142 (reg_request, tmp, &reg_requests_list, list) {
if ( V_235 -> V_58 != V_60 )
continue;
F_160 ( & V_235 -> V_45 , & V_256 ) ;
}
F_124 ( & V_220 ) ;
F_141 ( & V_240 ) ;
F_142 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_176 -> V_45 ) ;
F_13 ( V_176 ) ;
}
F_143 ( & V_240 ) ;
F_142 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_176 -> V_45 ) ;
F_13 ( V_176 ) ;
}
V_254 [ 0 ] = V_23 -> V_26 [ 0 ] ;
V_254 [ 1 ] = V_23 -> V_26 [ 1 ] ;
F_95 (rdev, &cfg80211_rdev_list, list) {
if ( V_194 -> V_3 . V_144 & V_172 )
continue;
if ( V_194 -> V_3 . V_144 & V_171 )
F_157 ( & V_194 -> V_3 ) ;
}
F_149 ( V_254 ) ;
if ( F_25 ( V_26 ) )
F_150 ( V_29 , V_257 ) ;
F_123 ( & V_220 ) ;
F_161 ( & V_256 , & V_221 ) ;
F_124 ( & V_220 ) ;
F_6 ( L_42 ) ;
F_45 ( & V_223 ) ;
}
void F_162 ( void )
{
F_6 ( L_43 ) ;
F_158 ( false ) ;
}
static bool F_163 ( T_3 V_258 )
{
if ( V_258 == F_164 ( 12 , V_259 ) ||
V_258 == F_164 ( 13 , V_259 ) ||
V_258 == F_164 ( 14 , V_259 ) )
return true ;
return false ;
}
static bool F_165 ( struct V_138 * V_260 )
{
struct V_176 * V_239 ;
F_95 (pending_beacon, &reg_pending_beacons, list)
if ( V_260 -> V_129 ==
V_239 -> V_139 . V_129 )
return true ;
return false ;
}
int F_166 ( struct V_3 * V_3 ,
struct V_138 * V_260 ,
T_4 V_261 )
{
struct V_176 * V_176 ;
bool V_262 ;
if ( V_260 -> V_157 ||
V_260 -> V_73 & V_118 ||
( V_260 -> V_180 == V_259 &&
! F_163 ( V_260 -> V_129 ) ) )
return 0 ;
F_141 ( & V_240 ) ;
V_262 = F_165 ( V_260 ) ;
F_143 ( & V_240 ) ;
if ( V_262 )
return 0 ;
V_176 = F_31 ( sizeof( struct V_176 ) , V_261 ) ;
if ( ! V_176 )
return - V_36 ;
F_6 ( L_44 ,
V_260 -> V_129 ,
F_167 ( V_260 -> V_129 ) ,
F_168 ( V_3 ) ) ;
memcpy ( & V_176 -> V_139 , V_260 ,
sizeof( struct V_138 ) ) ;
F_141 ( & V_240 ) ;
F_44 ( & V_176 -> V_45 , & V_263 ) ;
F_143 ( & V_240 ) ;
F_45 ( & V_223 ) ;
return 0 ;
}
static void F_169 ( const struct V_1 * V_25 )
{
unsigned int V_32 ;
const struct V_34 * V_80 = NULL ;
const struct V_62 * V_63 = NULL ;
const struct V_95 * V_98 = NULL ;
char V_72 [ 32 ] , V_264 [ 32 ] ;
F_49 ( L_45 ) ;
for ( V_32 = 0 ; V_32 < V_25 -> V_33 ; V_32 ++ ) {
V_80 = & V_25 -> V_37 [ V_32 ] ;
V_63 = & V_80 -> V_63 ;
V_98 = & V_80 -> V_98 ;
if ( V_80 -> V_73 & V_101 )
snprintf ( V_72 , sizeof( V_72 ) , L_21 ,
V_63 -> V_79 ,
F_55 ( V_25 , V_80 ) ) ;
else
snprintf ( V_72 , sizeof( V_72 ) , L_22 ,
V_63 -> V_79 ) ;
if ( V_80 -> V_73 & V_117 )
F_170 ( V_264 , sizeof( V_264 ) , L_46 ,
V_80 -> V_104 / 1000 ) ;
else
F_170 ( V_264 , sizeof( V_264 ) , L_19 ) ;
if ( V_98 -> V_103 )
F_49 ( L_47 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_72 ,
V_98 -> V_103 ,
V_98 -> V_102 ,
V_264 ) ;
else
F_49 ( L_48 ,
V_63 -> V_71 ,
V_63 -> V_70 ,
V_72 ,
V_98 -> V_102 ,
V_264 ) ;
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
F_6 ( L_49 ,
V_6 ) ;
return false ;
}
}
static void F_172 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 = F_10 () ;
if ( F_24 ( V_25 -> V_26 ) ) {
if ( V_19 -> V_58 == V_59 ) {
struct V_193 * V_194 ;
V_194 = F_173 ( V_19 -> V_142 ) ;
if ( V_194 ) {
F_49 ( L_50 ,
V_194 -> V_265 [ 0 ] ,
V_194 -> V_265 [ 1 ] ) ;
} else
F_49 ( L_51 ) ;
} else
F_49 ( L_51 ) ;
} else if ( F_21 ( V_25 -> V_26 ) ) {
F_49 ( L_52 ) ;
} else {
if ( F_23 ( V_25 -> V_26 ) )
F_49 ( L_53 ) ;
else {
if ( F_82 ( V_19 ) )
F_49 ( L_54 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
else
F_49 ( L_55 ,
V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
}
}
F_49 ( L_56 , F_4 ( V_25 -> V_6 ) ) ;
F_169 ( V_25 ) ;
}
static void F_174 ( const struct V_1 * V_25 )
{
F_49 ( L_57 , V_25 -> V_26 [ 0 ] , V_25 -> V_26 [ 1 ] ) ;
F_169 ( V_25 ) ;
}
static int F_175 ( const struct V_1 * V_25 )
{
if ( ! F_21 ( V_25 -> V_26 ) )
return - V_105 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_176 ( const struct V_1 * V_25 ,
struct V_16 * V_226 )
{
const struct V_1 * V_266 = NULL ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_267 ;
if ( ! F_58 ( V_25 ) ) {
F_177 ( L_58 ) ;
F_174 ( V_25 ) ;
return - V_105 ;
}
if ( ! V_226 -> V_225 ) {
F_17 ( false , V_25 ) ;
return 0 ;
}
V_266 = F_68 ( V_25 , F_1 () ) ;
if ( ! V_266 )
return - V_105 ;
F_13 ( V_25 ) ;
V_25 = NULL ;
F_17 ( false , V_266 ) ;
return 0 ;
}
static int F_178 ( const struct V_1 * V_25 ,
struct V_16 * V_231 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_266 = NULL ;
const struct V_1 * V_65 ;
struct V_3 * V_141 ;
if ( F_21 ( V_25 -> V_26 ) )
return - V_105 ;
if ( ! F_27 ( V_25 -> V_26 ) )
return - V_267 ;
if ( ! F_58 ( V_25 ) ) {
F_177 ( L_58 ) ;
F_174 ( V_25 ) ;
return - V_105 ;
}
V_141 = F_76 ( V_231 -> V_142 ) ;
if ( ! V_141 ) {
F_136 ( V_215 ,
& V_222 , 0 ) ;
return - V_268 ;
}
if ( ! V_231 -> V_225 ) {
if ( V_141 -> V_4 )
return - V_267 ;
V_4 = F_30 ( V_25 ) ;
if ( F_77 ( V_4 ) )
return F_78 ( V_4 ) ;
F_16 ( V_141 -> V_4 , V_4 ) ;
F_17 ( false , V_25 ) ;
return 0 ;
}
V_266 = F_68 ( V_25 , F_1 () ) ;
if ( ! V_266 )
return - V_105 ;
V_65 = F_3 ( V_141 ) ;
F_16 ( V_141 -> V_4 , V_25 ) ;
F_8 ( V_65 ) ;
V_25 = NULL ;
F_17 ( false , V_266 ) ;
return 0 ;
}
static int F_179 ( const struct V_1 * V_25 ,
struct V_16 * V_232 )
{
struct V_3 * V_141 ;
if ( ! F_22 ( V_25 -> V_26 ) && ! F_25 ( V_25 -> V_26 ) &&
! F_23 ( V_25 -> V_26 ) )
return - V_105 ;
if ( ! F_58 ( V_25 ) ) {
F_177 ( L_58 ) ;
F_174 ( V_25 ) ;
return - V_105 ;
}
V_141 = F_76 ( V_232 -> V_142 ) ;
if ( ! V_141 ) {
F_136 ( V_215 ,
& V_222 , 0 ) ;
return - V_268 ;
}
if ( V_232 -> V_225 )
return - V_105 ;
F_17 ( false , V_25 ) ;
return 0 ;
}
int F_41 ( const struct V_1 * V_25 )
{
struct V_16 * V_19 ;
bool V_269 = false ;
int V_14 ;
if ( ! F_52 ( V_25 -> V_26 ) ) {
F_13 ( V_25 ) ;
return - V_105 ;
}
V_19 = F_10 () ;
switch ( V_19 -> V_58 ) {
case V_136 :
V_14 = F_175 ( V_25 ) ;
break;
case V_60 :
V_14 = F_176 ( V_25 , V_19 ) ;
V_269 = true ;
break;
case V_137 :
V_14 = F_178 ( V_25 , V_19 ) ;
break;
case V_59 :
V_14 = F_179 ( V_25 , V_19 ) ;
break;
default:
F_29 ( 1 , L_37 , V_19 -> V_58 ) ;
return - V_105 ;
}
if ( V_14 ) {
switch ( V_14 ) {
case - V_267 :
F_122 () ;
break;
default:
F_158 ( V_269 ) ;
}
F_13 ( V_25 ) ;
return V_14 ;
}
if ( F_20 ( ! V_19 -> V_225 && V_25 != F_1 () ) )
return - V_105 ;
F_118 ( V_19 -> V_58 ) ;
F_172 ( F_1 () ) ;
F_131 ( V_19 ) ;
F_122 () ;
return 0 ;
}
static int F_180 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
const struct V_1 * V_4 ;
const struct V_1 * V_270 ;
struct V_193 * V_194 ;
if ( F_20 ( ! V_3 || ! V_25 ) )
return - V_105 ;
if ( F_29 ( ! ( V_3 -> V_144 & V_172 ) ,
L_59 ) )
return - V_271 ;
if ( F_29 ( ! F_58 ( V_25 ) , L_60 ) ) {
F_174 ( V_25 ) ;
return - V_105 ;
}
V_4 = F_30 ( V_25 ) ;
if ( F_77 ( V_4 ) )
return F_78 ( V_4 ) ;
V_194 = F_103 ( V_3 ) ;
F_123 ( & V_220 ) ;
V_270 = V_194 -> V_242 ;
V_194 -> V_242 = V_4 ;
F_124 ( & V_220 ) ;
F_13 ( V_270 ) ;
return 0 ;
}
int F_181 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_272 = F_180 ( V_3 , V_25 ) ;
if ( V_272 )
return V_272 ;
F_45 ( & V_223 ) ;
return 0 ;
}
int F_182 ( struct V_3 * V_3 ,
struct V_1 * V_25 )
{
int V_272 ;
F_18 () ;
V_272 = F_180 ( V_3 , V_25 ) ;
if ( V_272 )
return V_272 ;
F_144 () ;
return 0 ;
}
void F_183 ( struct V_3 * V_3 )
{
struct V_16 * V_19 ;
if ( V_3 -> V_144 & V_172 )
V_3 -> V_144 |= V_181 |
V_234 ;
if ( ! F_86 ( V_3 ) )
V_167 ++ ;
V_19 = F_10 () ;
F_117 ( V_3 , V_19 -> V_58 ) ;
}
void F_184 ( struct V_3 * V_3 )
{
struct V_3 * V_141 = NULL ;
struct V_16 * V_19 ;
V_19 = F_10 () ;
if ( ! F_86 ( V_3 ) )
V_167 -- ;
F_8 ( F_3 ( V_3 ) ) ;
F_185 ( V_3 -> V_4 , NULL ) ;
if ( V_19 )
V_141 = F_76 ( V_19 -> V_142 ) ;
if ( ! V_141 || V_141 != V_3 )
return;
V_19 -> V_142 = V_236 ;
V_19 -> V_251 = V_247 ;
}
static void F_186 ( struct V_38 * V_39 )
{
F_6 ( L_61 ) ;
F_34 () ;
F_158 ( true ) ;
F_42 () ;
}
int F_187 ( int V_258 )
{
if ( V_258 >= 5150 && V_258 <= 5250 )
return 0 ;
if ( V_258 > 5250 && V_258 <= 5350 )
return 1 ;
if ( V_258 > 5350 && V_258 <= 5470 )
return 2 ;
if ( V_258 > 5470 && V_258 <= 5725 )
return 3 ;
if ( V_258 > 5725 && V_258 <= 5825 )
return 4 ;
return - V_105 ;
}
bool F_188 ( void )
{
return V_227 ;
}
int T_5 F_189 ( void )
{
int V_273 = 0 ;
V_51 = F_190 ( L_62 , 0 , NULL , 0 ) ;
if ( F_77 ( V_51 ) )
return F_78 ( V_51 ) ;
F_191 ( & V_220 ) ;
F_191 ( & V_240 ) ;
F_46 () ;
F_16 ( V_2 , V_23 ) ;
V_29 [ 0 ] = '9' ;
V_29 [ 1 ] = '7' ;
V_273 = F_149 ( V_23 -> V_26 ) ;
if ( V_273 ) {
if ( V_273 == - V_36 )
return V_273 ;
F_177 ( L_63 ) ;
}
if ( ! F_21 ( V_253 ) )
F_150 ( V_253 ,
V_257 ) ;
return 0 ;
}
void F_192 ( void )
{
struct V_16 * V_235 , * V_65 ;
struct V_176 * V_176 , * V_255 ;
F_193 ( & V_223 ) ;
F_194 ( & V_222 ) ;
F_194 ( & V_216 ) ;
F_34 () ;
F_17 ( true , NULL ) ;
F_42 () ;
F_195 ( & V_51 -> V_13 , true ) ;
F_196 ( V_51 ) ;
F_142 (reg_beacon, btmp, &reg_pending_beacons, list) {
F_38 ( & V_176 -> V_45 ) ;
F_13 ( V_176 ) ;
}
F_142 (reg_beacon, btmp, &reg_beacon_list, list) {
F_38 ( & V_176 -> V_45 ) ;
F_13 ( V_176 ) ;
}
F_142 (reg_request, tmp, &reg_requests_list, list) {
F_38 ( & V_235 -> V_45 ) ;
F_13 ( V_235 ) ;
}
}
