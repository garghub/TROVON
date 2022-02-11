static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) )
return true ;
switch ( V_2 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
return false ;
}
return true ;
}
static bool F_3 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_65 ) )
return false ;
if ( ! F_1 ( V_2 ) )
return false ;
return true ;
}
static inline bool F_4 ( T_1 V_66 )
{
return ( ( V_66 & V_67 ) != V_67 ) &&
( ( ( V_66 & V_68 ) == V_69 ) ||
( V_66 == V_70 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_71 & ~ V_72 ;
}
bool F_6 ( struct V_1 * V_2 )
{
return F_4 ( F_5 ( V_2 ) ) ;
}
static const struct V_73 * F_7 ( void )
{
return & V_74 ;
}
static const struct
V_73 * F_8 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_75 -> V_76 ) {
case 0x60 :
case 0x61 :
case 0x62 :
return & V_77 ;
case 0x63 :
case 0x65 :
return & V_78 ;
case 0x64 :
return & V_74 ;
case 0x66 :
case 0x69 :
return & V_79 ;
case 0x67 :
case 0x68 :
case 0x6A :
case 0x6C :
return & V_80 ;
default:
F_9 ( 1 ) ;
return F_7 () ;
}
}
bool F_10 ( T_1 V_81 )
{
return V_81 == V_82 ;
}
static bool F_11 ( T_1 V_83 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_4 == V_84 )
return ( V_83 >= 5500 && V_83 <= 5700 ) ;
return ( V_83 >= 5260 && V_83 <= 5700 ) ;
}
static void F_12 ( struct V_85 * V_85 ,
struct V_86 * V_87 )
{
const struct V_88 * V_89 ;
V_89 = F_13 ( V_85 , F_14 ( V_87 -> V_83 ) ) ;
if ( F_15 ( V_89 ) )
return;
if ( ! ( V_89 -> V_90 & V_91 ) )
if ( V_87 -> V_90 & V_92 )
V_87 -> V_90 &= ~ V_92 ;
}
static void F_16 ( struct V_85 * V_85 , T_1 V_83 )
{
struct V_86 * V_87 ;
V_87 = F_17 ( V_85 , V_83 ) ;
if ( ! V_87 )
return;
F_12 ( V_85 , V_87 ) ;
}
static void F_18 ( struct V_86 * V_87 )
{
V_87 -> V_90 |= V_92 ;
}
static void F_19 ( struct V_85 * V_85 , T_1 V_83 )
{
struct V_86 * V_87 ;
V_87 = F_17 ( V_85 , V_83 ) ;
if ( ! V_87 )
return;
F_18 ( V_87 ) ;
}
static void
F_20 ( struct V_85 * V_85 ,
struct V_1 * V_2 ,
enum V_93 V_94 ,
struct V_86 * V_87 )
{
if ( F_11 ( V_87 -> V_83 , V_2 ) ||
( V_87 -> V_90 & V_95 ) )
return;
switch ( V_94 ) {
case V_96 :
F_12 ( V_85 , V_87 ) ;
break;
case V_97 :
if ( F_3 ( V_2 ) )
F_12 ( V_85 , V_87 ) ;
break;
default:
if ( V_87 -> V_98 )
V_87 -> V_90 &= ~ V_92 ;
}
}
static void
F_21 ( struct V_85 * V_85 ,
struct V_1 * V_2 ,
enum V_93 V_94 )
{
enum V_99 V_100 ;
struct V_101 * V_102 ;
struct V_86 * V_87 ;
unsigned int V_103 ;
for ( V_100 = 0 ; V_100 < V_104 ; V_100 ++ ) {
if ( ! V_85 -> V_105 [ V_100 ] )
continue;
V_102 = V_85 -> V_105 [ V_100 ] ;
for ( V_103 = 0 ; V_103 < V_102 -> V_106 ; V_103 ++ ) {
V_87 = & V_102 -> V_107 [ V_103 ] ;
F_20 ( V_85 , V_2 ,
V_94 , V_87 ) ;
}
}
}
static void
F_22 ( struct V_85 * V_85 ,
struct V_1 * V_2 ,
enum V_93 V_94 )
{
struct V_101 * V_102 ;
V_102 = V_85 -> V_105 [ V_108 ] ;
if ( ! V_102 )
return;
switch( V_94 ) {
case V_96 :
F_16 ( V_85 , 2467 ) ;
F_16 ( V_85 , 2472 ) ;
break;
case V_97 :
if ( ! F_3 ( V_2 ) )
break;
F_16 ( V_85 , 2467 ) ;
F_16 ( V_85 , 2472 ) ;
break;
default:
F_19 ( V_85 , 2467 ) ;
F_19 ( V_85 , 2472 ) ;
}
}
static void F_23 ( struct V_85 * V_85 ,
struct V_1 * V_2 )
{
struct V_101 * V_102 ;
struct V_86 * V_87 ;
unsigned int V_103 ;
if ( ! V_85 -> V_105 [ V_109 ] )
return;
V_102 = V_85 -> V_105 [ V_109 ] ;
for ( V_103 = 0 ; V_103 < V_102 -> V_106 ; V_103 ++ ) {
V_87 = & V_102 -> V_107 [ V_103 ] ;
if ( ! F_11 ( V_87 -> V_83 , V_2 ) )
continue;
if ( ! ( V_87 -> V_90 & V_110 ) )
V_87 -> V_90 |= V_95 |
V_92 ;
}
}
static void F_24 ( struct V_85 * V_85 ,
enum V_93 V_94 ,
struct V_1 * V_2 )
{
switch ( V_2 -> V_75 -> V_76 ) {
case 0x60 :
case 0x63 :
case 0x66 :
case 0x67 :
case 0x6C :
F_21 ( V_85 , V_2 , V_94 ) ;
break;
case 0x68 :
F_21 ( V_85 , V_2 , V_94 ) ;
F_22 ( V_85 , V_2 , V_94 ) ;
break;
default:
if ( F_3 ( V_2 ) )
F_21 ( V_85 , V_2 , V_94 ) ;
}
}
T_1 F_25 ( char * V_111 )
{
unsigned int V_103 ;
for ( V_103 = 0 ; V_103 < F_26 ( V_112 ) ; V_103 ++ ) {
if ( ! memcmp ( V_112 [ V_103 ] . V_113 , V_111 , 2 ) )
return V_112 [ V_103 ] . V_114 ;
}
return - 1 ;
}
static int F_27 ( struct V_85 * V_85 ,
struct V_1 * V_2 ,
struct V_115 * V_116 )
{
T_1 V_4 ;
if ( V_116 -> V_94 == V_96 &&
! F_6 ( V_2 ) )
return - V_117 ;
V_4 = F_25 ( V_116 -> V_111 ) ;
if ( V_4 == ( T_1 ) - 1 )
return - V_117 ;
V_2 -> V_71 = V_67 ;
V_2 -> V_71 |= V_4 ;
F_28 ( V_2 ) ;
F_24 ( V_85 , V_116 -> V_94 , V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_85 * V_85 ,
struct V_1 * V_2 ,
struct V_115 * V_116 )
{
if ( F_27 ( V_85 , V_2 , V_116 ) )
return;
F_30 ( V_118 L_1
L_2 ,
V_2 -> V_71 ,
F_31 ( V_116 -> V_94 ) ) ;
}
void F_32 ( struct V_85 * V_85 ,
struct V_115 * V_116 ,
struct V_1 * V_2 )
{
struct V_119 * V_120 = F_33 ( V_2 , struct V_119 ,
V_121 ) ;
F_23 ( V_85 , V_2 ) ;
if ( ! V_116 )
return;
V_2 -> V_122 = V_116 -> V_123 ;
switch ( V_116 -> V_94 ) {
case V_124 :
if ( ! F_6 ( & V_120 -> V_125 ) )
break;
memcpy ( V_2 , & V_120 -> V_125 ,
sizeof( struct V_1 ) ) ;
break;
case V_126 :
break;
case V_97 :
if ( F_3 ( V_2 ) )
F_29 ( V_85 , V_2 , V_116 ) ;
break;
case V_96 :
F_29 ( V_85 , V_2 , V_116 ) ;
break;
}
}
static bool F_34 ( struct V_1 * V_2 )
{
T_1 V_127 = F_5 ( V_2 ) ;
int V_103 ;
if ( V_127 & V_67 ) {
T_1 V_128 = V_127 & ~ V_67 ;
F_30 ( V_118
L_3
L_4 ) ;
for ( V_103 = 0 ; V_103 < F_26 ( V_112 ) ; V_103 ++ )
if ( V_112 [ V_103 ] . V_114 == V_128 )
return true ;
} else {
if ( V_127 != V_129 )
F_30 ( V_118 L_5
L_6 ) ;
for ( V_103 = 0 ; V_103 < F_26 ( V_130 ) ; V_103 ++ )
if ( V_130 [ V_103 ] . V_76 == V_127 )
return true ;
}
F_30 ( V_118
L_7 , V_127 ) ;
return false ;
}
static struct V_131 *
F_35 ( T_1 V_114 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < F_26 ( V_112 ) ; V_103 ++ ) {
if ( V_112 [ V_103 ] . V_114 == V_114 )
return & V_112 [ V_103 ] ;
}
return NULL ;
}
static struct V_131 *
F_36 ( int V_132 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < F_26 ( V_112 ) ; V_103 ++ ) {
if ( V_112 [ V_103 ] . V_133 == V_132 )
return & V_112 [ V_103 ] ;
}
return NULL ;
}
static T_1 F_37 ( T_1 V_127 )
{
if ( V_127 & V_67 ) {
struct V_131 * V_134 = NULL ;
T_1 V_128 = V_127 & ~ V_67 ;
V_134 = F_35 ( V_128 ) ;
if ( V_134 != NULL )
return V_128 ;
}
return V_129 ;
}
static struct V_135 *
F_38 ( int V_132 )
{
int V_103 ;
if ( V_132 == V_136 )
return NULL ;
for ( V_103 = 0 ; V_103 < F_26 ( V_130 ) ; V_103 ++ ) {
if ( V_130 [ V_103 ] . V_76 == V_132 )
return & V_130 [ V_103 ] ;
}
return NULL ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_85 * V_85 ,
void (* F_40)( struct V_85 * V_85 ,
struct V_115 * V_116 ) )
{
const struct V_73 * V_66 ;
V_85 -> F_40 = F_40 ;
V_85 -> V_137 |= V_138 |
V_139 ;
if ( F_6 ( V_2 ) ) {
V_66 = F_8 ( V_2 ) ;
V_85 -> V_137 |= V_140 ;
} else {
V_66 = F_7 () ;
}
F_41 ( V_85 , V_66 ) ;
F_23 ( V_85 , V_2 ) ;
F_24 ( V_85 , V_126 , V_2 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 != V_67 )
return;
F_30 ( V_118 L_8 ) ;
V_2 -> V_71 = 0x64 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_131 * V_134 = NULL ;
T_1 V_132 ;
if ( ! V_2 )
return - V_117 ;
F_42 ( V_2 ) ;
F_30 ( V_118 L_9 , V_2 -> V_71 ) ;
if ( ! F_34 ( V_2 ) ) {
F_43 ( L_10 ) ;
return - V_117 ;
}
V_132 = F_5 ( V_2 ) ;
V_2 -> V_4 = F_37 ( V_132 ) ;
if ( V_2 -> V_4 == V_129 &&
V_132 == V_129 ) {
F_30 ( V_118 L_11
L_12 ) ;
V_2 -> V_4 = V_5 ;
}
if ( V_2 -> V_4 == V_129 ) {
V_134 = NULL ;
} else {
F_30 ( V_118 L_13
L_14 ) ;
V_134 = F_35 ( V_2 -> V_4 ) ;
if ( V_134 == NULL ) {
F_30 ( V_118
L_15
L_16 ,
V_2 -> V_4 ) ;
return - V_117 ;
} else {
V_132 = V_134 -> V_133 ;
F_30 ( V_118 L_17
L_18 ,
V_132 ) ;
}
}
V_2 -> V_75 = F_38 ( V_132 ) ;
if ( ! V_2 -> V_75 ) {
F_30 ( V_118 L_19
L_20 ) ;
return - V_117 ;
}
if ( ! V_134 )
V_134 = F_36 ( V_132 ) ;
if ( V_134 ) {
V_2 -> V_111 [ 0 ] = V_134 -> V_113 [ 0 ] ;
V_2 -> V_111 [ 1 ] = V_134 -> V_113 [ 1 ] ;
} else {
V_2 -> V_111 [ 0 ] = '0' ;
V_2 -> V_111 [ 1 ] = '0' ;
}
F_30 ( V_118 L_21 ,
V_2 -> V_111 [ 0 ] , V_2 -> V_111 [ 1 ] ) ;
F_30 ( V_118 L_22 ,
V_2 -> V_75 -> V_76 ) ;
return 0 ;
}
int
F_44 ( struct V_1 * V_2 ,
struct V_85 * V_85 ,
void (* F_40)( struct V_85 * V_85 ,
struct V_115 * V_116 ) )
{
struct V_119 * V_120 = F_33 ( V_2 , struct V_119 ,
V_121 ) ;
int V_141 ;
V_141 = F_28 ( V_2 ) ;
if ( V_141 )
return V_141 ;
if ( F_6 ( V_2 ) )
memcpy ( & V_120 -> V_125 , V_2 ,
sizeof( struct V_1 ) ) ;
F_39 ( V_2 , V_85 , F_40 ) ;
return 0 ;
}
T_2 F_45 ( struct V_1 * V_2 ,
enum V_99 V_100 )
{
if ( ! V_2 -> V_75 ||
( V_2 -> V_4 == V_129 &&
F_4 ( F_5 ( V_2 ) ) ) ) {
return V_142 ;
}
if ( F_5 ( V_2 ) == V_129 ) {
switch ( V_2 -> V_122 ) {
case V_143 :
return V_144 ;
case V_145 :
return V_146 ;
case V_147 :
return V_148 ;
default:
break;
}
}
switch ( V_100 ) {
case V_108 :
return V_2 -> V_75 -> V_149 ;
case V_109 :
return V_2 -> V_75 -> V_150 ;
default:
return V_151 ;
}
}
