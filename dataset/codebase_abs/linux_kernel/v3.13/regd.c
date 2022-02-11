static inline bool F_1 ( T_1 V_1 )
{
return ( ( V_1 & V_2 ) != V_2 ) &&
( ( ( V_1 & V_3 ) == V_4 ) ||
( V_1 == V_5 ) ) ;
}
static T_1 F_2 ( struct V_6 * V_7 )
{
return V_7 -> V_8 & ~ V_9 ;
}
bool F_3 ( struct V_6 * V_7 )
{
return F_1 ( F_2 ( V_7 ) ) ;
}
static const struct V_10 * F_4 ( void )
{
return & V_11 ;
}
static const struct
V_10 * F_5 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_12 -> V_13 ) {
case 0x60 :
case 0x61 :
case 0x62 :
return & V_14 ;
case 0x63 :
case 0x65 :
return & V_15 ;
case 0x64 :
return & V_11 ;
case 0x66 :
case 0x69 :
return & V_16 ;
case 0x67 :
case 0x68 :
case 0x6A :
case 0x6C :
return & V_17 ;
default:
F_6 ( 1 ) ;
return F_4 () ;
}
}
bool F_7 ( T_1 V_18 )
{
return V_18 == V_19 ;
}
static bool F_8 ( T_1 V_20 )
{
return ( V_20 >= 5260 && V_20 <= 5700 ) ;
}
static void
F_9 ( struct V_21 * V_21 ,
enum V_22 V_23 )
{
enum V_24 V_25 ;
struct V_26 * V_27 ;
const struct V_28 * V_29 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ ) {
if ( ! V_21 -> V_34 [ V_25 ] )
continue;
V_27 = V_21 -> V_34 [ V_25 ] ;
for ( V_32 = 0 ; V_32 < V_27 -> V_35 ; V_32 ++ ) {
V_31 = & V_27 -> V_36 [ V_32 ] ;
if ( F_8 ( V_31 -> V_20 ) ||
( V_31 -> V_37 & V_38 ) )
continue;
if ( V_23 == V_39 ) {
V_29 = F_10 ( V_21 , V_31 -> V_20 ) ;
if ( F_11 ( V_29 ) )
continue;
if ( ! ( V_29 -> V_37 &
V_40 ) )
V_31 -> V_37 &=
~ V_41 ;
if ( ! ( V_29 -> V_37 &
V_42 ) )
V_31 -> V_37 &=
~ V_43 ;
} else {
if ( V_31 -> V_44 )
V_31 -> V_37 &= ~ ( V_41 |
V_43 ) ;
}
}
}
}
static void
F_12 ( struct V_21 * V_21 ,
enum V_22 V_23 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
const struct V_28 * V_29 ;
V_27 = V_21 -> V_34 [ V_45 ] ;
if ( ! V_27 )
return;
if ( V_23 != V_39 ) {
V_31 = & V_27 -> V_36 [ 11 ] ;
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
V_31 = & V_27 -> V_36 [ 12 ] ;
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
return;
}
V_31 = & V_27 -> V_36 [ 11 ] ;
V_29 = F_10 ( V_21 , V_31 -> V_20 ) ;
if ( ! F_11 ( V_29 ) ) {
if ( ! ( V_29 -> V_37 & V_42 ) )
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
}
V_31 = & V_27 -> V_36 [ 12 ] ;
V_29 = F_10 ( V_21 , V_31 -> V_20 ) ;
if ( ! F_11 ( V_29 ) ) {
if ( ! ( V_29 -> V_37 & V_42 ) )
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
}
}
static void F_13 ( struct V_21 * V_21 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
if ( ! V_21 -> V_34 [ V_46 ] )
return;
V_27 = V_21 -> V_34 [ V_46 ] ;
for ( V_32 = 0 ; V_32 < V_27 -> V_35 ; V_32 ++ ) {
V_31 = & V_27 -> V_36 [ V_32 ] ;
if ( ! F_8 ( V_31 -> V_20 ) )
continue;
if ( ! ( V_31 -> V_37 & V_47 ) )
V_31 -> V_37 |= V_38 |
V_41 |
V_43 ;
}
}
static void F_14 ( struct V_21 * V_21 ,
enum V_22 V_23 ,
struct V_6 * V_7 )
{
switch ( V_7 -> V_12 -> V_13 ) {
case 0x60 :
case 0x63 :
case 0x66 :
case 0x67 :
case 0x6C :
F_9 ( V_21 , V_23 ) ;
break;
case 0x68 :
F_9 ( V_21 , V_23 ) ;
F_12 ( V_21 , V_23 ) ;
break;
}
}
static T_1 F_15 ( char * V_48 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ ) {
if ( ! memcmp ( V_49 [ V_32 ] . V_50 , V_48 , 2 ) )
return V_49 [ V_32 ] . V_51 ;
}
return - 1 ;
}
static int F_17 ( struct V_21 * V_21 ,
struct V_6 * V_7 ,
struct V_52 * V_53 )
{
T_1 V_54 ;
if ( V_53 -> V_23 == V_39 &&
! F_3 ( V_7 ) )
return - V_55 ;
V_54 = F_15 ( V_53 -> V_48 ) ;
if ( V_54 == ( T_1 ) - 1 )
return - V_55 ;
V_7 -> V_8 = V_2 ;
V_7 -> V_8 |= V_54 ;
F_18 ( V_7 ) ;
F_14 ( V_21 , V_53 -> V_23 , V_7 ) ;
return 0 ;
}
static void F_19 ( struct V_21 * V_21 ,
struct V_6 * V_7 ,
struct V_52 * V_53 )
{
if ( F_17 ( V_21 , V_7 , V_53 ) )
return;
F_20 ( V_56 L_1
L_2 ,
V_7 -> V_8 ,
F_21 ( V_53 -> V_23 ) ) ;
}
static bool F_22 ( struct V_6 * V_7 )
{
if ( F_23 ( V_57 ) )
return true ;
switch ( V_7 -> V_54 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
return false ;
}
return true ;
}
static void F_24 ( struct V_21 * V_21 ,
struct V_6 * V_7 ,
struct V_52 * V_53 )
{
if ( ! F_23 ( V_118 ) )
return;
if ( ! F_22 ( V_7 ) )
return;
F_19 ( V_21 , V_7 , V_53 ) ;
}
void F_25 ( struct V_21 * V_21 ,
struct V_52 * V_53 ,
struct V_6 * V_7 )
{
struct V_119 * V_120 = F_26 ( V_7 , struct V_119 ,
V_121 ) ;
F_13 ( V_21 ) ;
if ( ! V_53 )
return;
switch ( V_53 -> V_23 ) {
case V_122 :
if ( ! F_3 ( & V_120 -> V_123 ) )
break;
memcpy ( V_7 , & V_120 -> V_123 ,
sizeof( struct V_6 ) ) ;
break;
case V_124 :
break;
case V_125 :
F_24 ( V_21 , V_7 , V_53 ) ;
break;
case V_39 :
F_19 ( V_21 , V_7 , V_53 ) ;
break;
}
}
static bool F_27 ( struct V_6 * V_7 )
{
T_1 V_126 = F_2 ( V_7 ) ;
int V_32 ;
if ( V_126 & V_2 ) {
T_1 V_127 = V_126 & ~ V_2 ;
F_20 ( V_56
L_3
L_4 ) ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ )
if ( V_49 [ V_32 ] . V_51 == V_127 )
return true ;
} else {
if ( V_126 != V_128 )
F_20 ( V_56 L_5
L_6 ) ;
for ( V_32 = 0 ; V_32 < F_16 ( V_129 ) ; V_32 ++ )
if ( V_129 [ V_32 ] . V_13 == V_126 )
return true ;
}
F_20 ( V_56
L_7 , V_126 ) ;
return false ;
}
static struct V_130 *
F_28 ( T_1 V_51 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ ) {
if ( V_49 [ V_32 ] . V_51 == V_51 )
return & V_49 [ V_32 ] ;
}
return NULL ;
}
static struct V_130 *
F_29 ( int V_131 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ ) {
if ( V_49 [ V_32 ] . V_13 == V_131 )
return & V_49 [ V_32 ] ;
}
return NULL ;
}
static T_1 F_30 ( T_1 V_126 )
{
if ( V_126 & V_2 ) {
struct V_130 * V_132 = NULL ;
T_1 V_127 = V_126 & ~ V_2 ;
V_132 = F_28 ( V_127 ) ;
if ( V_132 != NULL )
return V_127 ;
}
return V_128 ;
}
static struct V_133 *
F_31 ( int V_131 )
{
int V_32 ;
if ( V_131 == V_134 )
return NULL ;
for ( V_32 = 0 ; V_32 < F_16 ( V_129 ) ; V_32 ++ ) {
if ( V_129 [ V_32 ] . V_13 == V_131 )
return & V_129 [ V_32 ] ;
}
return NULL ;
}
static int
F_32 ( struct V_6 * V_7 ,
struct V_21 * V_21 ,
void (* F_33)( struct V_21 * V_21 ,
struct V_52 * V_53 ) )
{
const struct V_10 * V_1 ;
V_21 -> F_33 = F_33 ;
V_21 -> V_37 |= V_135 ;
if ( F_3 ( V_7 ) ) {
V_1 = F_5 ( V_7 ) ;
V_21 -> V_37 |= V_136 ;
} else {
V_1 = F_4 () ;
}
F_34 ( V_21 , V_1 ) ;
F_13 ( V_21 ) ;
F_14 ( V_21 , V_124 , V_7 ) ;
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 != V_2 )
return;
F_20 ( V_56 L_8 ) ;
V_7 -> V_8 = 0x64 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_130 * V_132 = NULL ;
T_1 V_131 ;
if ( ! V_7 )
return - V_55 ;
F_35 ( V_7 ) ;
F_20 ( V_56 L_9 , V_7 -> V_8 ) ;
if ( ! F_27 ( V_7 ) ) {
F_36 ( L_10 ) ;
return - V_55 ;
}
V_131 = F_2 ( V_7 ) ;
V_7 -> V_54 = F_30 ( V_131 ) ;
if ( V_7 -> V_54 == V_128 &&
V_131 == V_128 ) {
F_20 ( V_56 L_11
L_12 ) ;
V_7 -> V_54 = V_58 ;
}
if ( V_7 -> V_54 == V_128 ) {
V_132 = NULL ;
} else {
F_20 ( V_56 L_13
L_14 ) ;
V_132 = F_28 ( V_7 -> V_54 ) ;
if ( V_132 == NULL ) {
F_20 ( V_56
L_15
L_16 ,
V_7 -> V_54 ) ;
return - V_55 ;
} else {
V_131 = V_132 -> V_13 ;
F_20 ( V_56 L_17
L_18 ,
V_131 ) ;
}
}
V_7 -> V_12 = F_31 ( V_131 ) ;
if ( ! V_7 -> V_12 ) {
F_20 ( V_56 L_19
L_20 ) ;
return - V_55 ;
}
if ( ! V_132 )
V_132 = F_29 ( V_131 ) ;
if ( V_132 ) {
V_7 -> V_48 [ 0 ] = V_132 -> V_50 [ 0 ] ;
V_7 -> V_48 [ 1 ] = V_132 -> V_50 [ 1 ] ;
} else {
V_7 -> V_48 [ 0 ] = '0' ;
V_7 -> V_48 [ 1 ] = '0' ;
}
F_20 ( V_56 L_21 ,
V_7 -> V_48 [ 0 ] , V_7 -> V_48 [ 1 ] ) ;
F_20 ( V_56 L_22 ,
V_7 -> V_12 -> V_13 ) ;
return 0 ;
}
int
F_37 ( struct V_6 * V_7 ,
struct V_21 * V_21 ,
void (* F_33)( struct V_21 * V_21 ,
struct V_52 * V_53 ) )
{
struct V_119 * V_120 = F_26 ( V_7 , struct V_119 ,
V_121 ) ;
int V_137 ;
V_137 = F_18 ( V_7 ) ;
if ( V_137 )
return V_137 ;
if ( F_3 ( V_7 ) )
memcpy ( & V_120 -> V_123 , V_7 ,
sizeof( struct V_6 ) ) ;
F_32 ( V_7 , V_21 , F_33 ) ;
return 0 ;
}
T_2 F_38 ( struct V_6 * V_7 ,
enum V_24 V_25 )
{
if ( ! V_7 -> V_12 ||
( V_7 -> V_54 == V_128 &&
F_1 ( F_2 ( V_7 ) ) ) ) {
return V_138 ;
}
switch ( V_25 ) {
case V_45 :
return V_7 -> V_12 -> V_139 ;
case V_46 :
return V_7 -> V_12 -> V_140 ;
default:
return V_141 ;
}
}
