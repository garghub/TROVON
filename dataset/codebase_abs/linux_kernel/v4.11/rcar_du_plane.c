static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
V_5 = F_2 ( V_2 -> V_2 . V_6 ) ;
if ( ! V_5 -> V_7 ||
V_5 -> V_7 -> V_8 != V_4 -> V_7 -> V_8 )
return true ;
if ( V_5 -> V_9 != V_4 -> V_9 )
return true ;
return false ;
}
static unsigned int F_3 ( struct V_3 * V_6 )
{
unsigned int V_10 ;
if ( V_6 -> V_11 == - 1 )
return 0 ;
V_10 = 1 << V_6 -> V_11 ;
if ( V_6 -> V_7 -> V_8 == 2 )
V_10 |= 1 << ( ( V_6 -> V_11 + 1 ) % 8 ) ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_6 ,
unsigned int free )
{
unsigned int V_12 = V_6 -> V_7 -> V_8 ;
int V_13 = - 1 ;
int V_14 ;
if ( V_6 -> V_9 == V_15 ) {
if ( V_2 -> V_16 -> V_17 != 0 )
return - V_18 ;
V_13 = 0 ;
} else if ( V_6 -> V_9 == V_19 ) {
V_13 = V_2 -> V_16 -> V_17 == 0 ? 1 : 0 ;
}
if ( V_13 >= 0 )
return free & ( 1 << V_13 ) ? V_13 : - V_20 ;
for ( V_14 = V_21 - 1 ; V_14 >= 0 ; -- V_14 ) {
if ( ! ( free & ( 1 << V_14 ) ) )
continue;
if ( V_12 == 1 || free & ( 1 << ( ( V_14 + 1 ) % 8 ) ) )
break;
}
return V_14 < 0 ? - V_20 : V_14 ;
}
int F_5 ( struct V_22 * V_23 ,
struct V_24 * V_6 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
unsigned int V_28 [ V_29 ] = { 0 , } ;
unsigned int V_30 [ V_29 ] = { 0 , } ;
bool V_31 = false ;
unsigned int V_32 = 0 ;
unsigned int V_14 ;
struct V_33 * V_33 ;
struct V_34 * V_34 ;
F_6 (state, drm_plane, drm_plane_state, i) {
struct V_3 * V_35 ;
struct V_1 * V_2 ;
unsigned int V_17 ;
V_2 = F_7 ( V_33 ) ;
V_35 = F_2 ( V_34 ) ;
F_8 ( V_26 -> V_23 , L_1 , V_36 ,
V_2 -> V_16 -> V_17 , V_2 - V_2 -> V_16 -> V_8 ) ;
if ( ! V_35 -> V_7 ) {
F_8 ( V_26 -> V_23 , L_2 ,
V_36 ) ;
V_17 = V_2 - V_2 -> V_16 -> V_8 ;
V_28 [ V_2 -> V_16 -> V_17 ] |= 1 << V_17 ;
V_35 -> V_11 = - 1 ;
continue;
}
if ( F_1 ( V_2 , V_35 ) ) {
F_8 ( V_26 -> V_23 , L_3 ,
V_36 ) ;
V_32 |= 1 << V_2 -> V_16 -> V_17 ;
V_31 = true ;
V_17 = V_2 - V_2 -> V_16 -> V_8 ;
V_28 [ V_2 -> V_16 -> V_17 ] |= 1 << V_17 ;
V_35 -> V_11 = - 1 ;
}
}
if ( ! V_31 )
return 0 ;
while ( V_32 ) {
unsigned int V_17 = F_9 ( V_32 ) - 1 ;
struct V_37 * V_16 = & V_26 -> V_32 [ V_17 ] ;
unsigned int V_38 = 0 ;
F_8 ( V_26 -> V_23 , L_4 ,
V_36 , V_17 ) ;
for ( V_14 = 0 ; V_14 < V_16 -> V_12 ; ++ V_14 ) {
struct V_1 * V_2 = & V_16 -> V_8 [ V_14 ] ;
struct V_3 * V_35 ;
struct V_34 * V_39 ;
V_39 = F_10 ( V_6 , & V_2 -> V_2 ) ;
if ( F_11 ( V_39 ) )
return F_12 ( V_39 ) ;
if ( V_28 [ V_17 ] & ( 1 << V_14 ) ) {
F_8 ( V_26 -> V_23 ,
L_5 ,
V_36 , V_2 -> V_16 -> V_17 ,
V_2 - V_2 -> V_16 -> V_8 ) ;
continue;
}
V_35 = F_2 ( V_2 -> V_2 . V_6 ) ;
V_38 |= F_3 ( V_35 ) ;
F_8 ( V_26 -> V_23 ,
L_6 ,
V_36 , V_2 -> V_16 -> V_17 ,
V_2 - V_2 -> V_16 -> V_8 ,
V_35 -> V_7 ?
V_35 -> V_7 -> V_8 : 0 ,
V_35 -> V_11 ) ;
}
V_30 [ V_17 ] = 0xff & ~ V_38 ;
V_32 &= ~ ( 1 << V_17 ) ;
F_8 ( V_26 -> V_23 , L_7 ,
V_36 , V_17 , V_30 [ V_17 ] ) ;
}
F_6 (state, drm_plane, drm_plane_state, i) {
struct V_3 * V_35 ;
struct V_1 * V_2 ;
unsigned int V_40 ;
unsigned int free ;
int V_41 ;
V_2 = F_7 ( V_33 ) ;
V_35 = F_2 ( V_34 ) ;
F_8 ( V_26 -> V_23 , L_8 , V_36 ,
V_2 -> V_16 -> V_17 , V_2 - V_2 -> V_16 -> V_8 ) ;
if ( ! V_35 -> V_7 ||
! F_1 ( V_2 , V_35 ) )
continue;
V_40 = F_13 ( V_35 -> V_6 . V_42 ) -> V_17 % 2
? V_2 -> V_16 -> V_43
: ~ V_2 -> V_16 -> V_43 ;
free = V_30 [ V_2 -> V_16 -> V_17 ] ;
V_41 = F_4 ( V_2 , V_35 ,
free & V_40 ) ;
if ( V_41 < 0 )
V_41 = F_4 ( V_2 , V_35 ,
free ) ;
if ( V_41 < 0 ) {
F_8 ( V_26 -> V_23 , L_9 ,
V_36 ) ;
return V_41 ;
}
F_8 ( V_26 -> V_23 , L_10 ,
V_36 , V_35 -> V_7 -> V_8 , V_41 ) ;
V_35 -> V_11 = V_41 ;
V_30 [ V_2 -> V_16 -> V_17 ] &=
~ F_3 ( V_35 ) ;
F_8 ( V_26 -> V_23 , L_7 ,
V_36 , V_2 -> V_16 -> V_17 ,
V_30 [ V_2 -> V_16 -> V_17 ] ) ;
}
return 0 ;
}
static void F_14 ( struct V_37 * V_44 ,
unsigned int V_17 , T_1 V_45 , T_1 V_46 )
{
F_15 ( V_44 -> V_23 , V_44 -> V_47 + V_17 * V_48 + V_45 ,
V_46 ) ;
}
static void F_16 ( struct V_37 * V_44 ,
const struct V_3 * V_6 )
{
unsigned int V_49 = V_6 -> V_6 . V_49 >> 16 ;
unsigned int V_50 = V_6 -> V_6 . V_50 >> 16 ;
unsigned int V_17 = V_6 -> V_11 ;
unsigned int V_51 ;
bool V_52 ;
T_1 V_53 [ 2 ] ;
V_52 = V_6 -> V_6 . V_42 -> V_6 -> V_54 . V_55
& V_56 ;
if ( V_6 -> V_9 == V_57 ) {
struct V_58 * V_59 = V_6 -> V_6 . V_59 ;
struct V_60 * V_61 ;
unsigned int V_14 ;
if ( V_6 -> V_7 -> V_8 == 2 )
V_51 = V_59 -> V_62 [ 0 ] ;
else
V_51 = V_59 -> V_62 [ 0 ] * 8 / V_6 -> V_7 -> V_63 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_7 -> V_8 ; ++ V_14 ) {
V_61 = F_17 ( V_59 , V_14 ) ;
V_53 [ V_14 ] = V_61 -> V_64 + V_59 -> V_65 [ V_14 ] ;
}
} else {
V_51 = V_6 -> V_6 . V_66 >> 16 ;
V_53 [ 0 ] = 0 ;
V_53 [ 1 ] = 0 ;
}
F_14 ( V_44 , V_17 , V_67 ,
( V_52 && V_6 -> V_7 -> V_63 == 32 ) ?
V_51 * 2 : V_51 ) ;
F_14 ( V_44 , V_17 , V_68 , V_49 ) ;
F_14 ( V_44 , V_17 , V_69 , V_50 *
( ! V_52 && V_6 -> V_7 -> V_63 == 32 ? 2 : 1 ) ) ;
F_14 ( V_44 , V_17 , V_70 , V_53 [ 0 ] ) ;
if ( V_6 -> V_7 -> V_8 == 2 ) {
V_17 = ( V_17 + 1 ) % 8 ;
F_14 ( V_44 , V_17 , V_67 , V_51 ) ;
F_14 ( V_44 , V_17 , V_68 , V_49 ) ;
F_14 ( V_44 , V_17 , V_69 , V_50 *
( V_6 -> V_7 -> V_63 == 16 ? 2 : 1 ) / 2 ) ;
F_14 ( V_44 , V_17 , V_70 , V_53 [ 1 ] ) ;
}
}
static void F_18 ( struct V_37 * V_44 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
T_1 V_71 ;
T_1 V_72 ;
if ( V_6 -> V_7 -> V_73 != V_74 )
F_14 ( V_44 , V_17 , V_75 , V_76 ) ;
else
F_14 ( V_44 , V_17 , V_75 ,
V_77 | V_6 -> V_78 ) ;
V_72 = V_79 | V_6 -> V_7 -> V_72 ;
if ( ( V_6 -> V_71 & V_80 ) == V_81 )
V_72 |= V_82 ;
if ( V_6 -> V_7 -> V_73 == V_83 )
V_72 |= V_84 ;
F_14 ( V_44 , V_17 , V_85 , V_72 ) ;
switch ( V_6 -> V_7 -> V_73 ) {
case V_86 :
V_71 = ( ( V_6 -> V_71 & 0xf80000 ) >> 8 )
| ( ( V_6 -> V_71 & 0x00fc00 ) >> 5 )
| ( ( V_6 -> V_71 & 0x0000f8 ) >> 3 ) ;
F_14 ( V_44 , V_17 , V_87 , V_71 ) ;
break;
case V_88 :
case V_74 :
V_71 = ( ( V_6 -> V_71 & 0xf80000 ) >> 9 )
| ( ( V_6 -> V_71 & 0x00f800 ) >> 6 )
| ( ( V_6 -> V_71 & 0x0000f8 ) >> 3 ) ;
F_14 ( V_44 , V_17 , V_87 , V_71 ) ;
break;
case V_89 :
case V_90 :
F_14 ( V_44 , V_17 , V_91 ,
V_92 | ( V_6 -> V_71 & 0xffffff ) ) ;
break;
}
}
static void F_19 ( struct V_37 * V_44 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
T_1 V_93 = V_94 ;
T_1 V_95 ;
F_18 ( V_44 , V_17 , V_6 ) ;
if ( V_6 -> V_7 -> V_8 == 2 ) {
if ( V_6 -> V_11 != V_17 ) {
if ( V_6 -> V_7 -> V_73 == V_96 ||
V_6 -> V_7 -> V_73 == V_97 )
V_93 |= V_98 ;
if ( V_6 -> V_7 -> V_73 == V_97 )
V_93 |= V_99 ;
V_93 |= V_100 ;
} else {
V_93 |= V_101 ;
}
}
F_14 ( V_44 , V_17 , V_102 , V_93 ) ;
V_95 = V_6 -> V_7 -> V_103 | V_104 ;
if ( V_6 -> V_9 != V_57 )
V_95 |= V_105 ;
F_14 ( V_44 , V_17 , V_106 , V_95 ) ;
}
static void F_20 ( struct V_37 * V_44 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
F_14 ( V_44 , V_17 , V_85 ,
V_82 | V_6 -> V_7 -> V_72 ) ;
F_14 ( V_44 , V_17 , V_106 ,
V_6 -> V_7 -> V_103 | V_104 ) ;
}
static void F_21 ( struct V_37 * V_44 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
struct V_25 * V_26 = V_44 -> V_23 ;
if ( V_26 -> V_107 -> V_108 < 3 )
F_19 ( V_44 , V_17 , V_6 ) ;
else
F_20 ( V_44 , V_17 , V_6 ) ;
F_14 ( V_44 , V_17 , V_109 , V_6 -> V_6 . V_110 ) ;
F_14 ( V_44 , V_17 , V_111 , V_6 -> V_6 . V_112 ) ;
F_14 ( V_44 , V_17 , V_113 , V_6 -> V_6 . V_114 ) ;
F_14 ( V_44 , V_17 , V_115 , V_6 -> V_6 . V_116 ) ;
if ( V_26 -> V_107 -> V_108 < 3 ) {
F_14 ( V_44 , V_17 , V_117 , 0 ) ;
F_14 ( V_44 , V_17 , V_118 , 4095 ) ;
F_14 ( V_44 , V_17 , V_119 , 0 ) ;
F_14 ( V_44 , V_17 , V_120 , 0 ) ;
}
}
void F_22 ( struct V_37 * V_44 ,
const struct V_3 * V_6 )
{
struct V_25 * V_26 = V_44 -> V_23 ;
F_21 ( V_44 , V_6 -> V_11 , V_6 ) ;
if ( V_6 -> V_7 -> V_8 == 2 )
F_21 ( V_44 , ( V_6 -> V_11 + 1 ) % 8 ,
V_6 ) ;
if ( V_26 -> V_107 -> V_108 < 3 )
F_16 ( V_44 , V_6 ) ;
if ( V_6 -> V_9 == V_19 ) {
unsigned int V_121 = V_44 -> V_17 ? 2 : 0 ;
if ( V_26 -> V_121 != V_121 ) {
V_26 -> V_121 = V_121 ;
F_23 ( V_26 ) ;
}
}
}
static int F_24 ( struct V_33 * V_2 ,
struct V_34 * V_6 )
{
struct V_3 * V_122 = F_2 ( V_6 ) ;
struct V_1 * V_123 = F_7 ( V_2 ) ;
struct V_25 * V_26 = V_123 -> V_16 -> V_23 ;
if ( ! V_6 -> V_59 || ! V_6 -> V_42 ) {
V_122 -> V_7 = NULL ;
return 0 ;
}
if ( V_6 -> V_66 >> 16 != V_6 -> V_110 ||
V_6 -> V_124 >> 16 != V_6 -> V_112 ) {
F_8 ( V_26 -> V_23 , L_11 , V_36 ) ;
return - V_18 ;
}
V_122 -> V_7 = F_25 ( V_6 -> V_59 -> V_7 -> V_7 ) ;
if ( V_122 -> V_7 == NULL ) {
F_8 ( V_26 -> V_23 , L_12 , V_36 ,
V_6 -> V_59 -> V_7 -> V_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_26 ( struct V_33 * V_2 ,
struct V_34 * V_125 )
{
struct V_1 * V_123 = F_7 ( V_2 ) ;
struct V_3 * V_126 ;
struct V_3 * V_127 ;
if ( ! V_2 -> V_6 -> V_42 )
return;
F_27 ( V_123 ) ;
V_126 = F_2 ( V_125 ) ;
V_127 = F_2 ( V_2 -> V_6 ) ;
if ( ( V_126 -> V_9 == V_57 ) !=
( V_127 -> V_9 == V_57 ) )
V_123 -> V_16 -> V_128 = true ;
}
static struct V_34 *
F_28 ( struct V_33 * V_2 )
{
struct V_3 * V_6 ;
struct V_3 * V_129 ;
if ( F_29 ( ! V_2 -> V_6 ) )
return NULL ;
V_6 = F_2 ( V_2 -> V_6 ) ;
V_129 = F_30 ( V_6 , sizeof( * V_6 ) , V_130 ) ;
if ( V_129 == NULL )
return NULL ;
F_31 ( V_2 , & V_129 -> V_6 ) ;
return & V_129 -> V_6 ;
}
static void F_32 ( struct V_33 * V_2 ,
struct V_34 * V_6 )
{
F_33 ( V_6 ) ;
F_34 ( F_2 ( V_6 ) ) ;
}
static void F_35 ( struct V_33 * V_2 )
{
struct V_3 * V_6 ;
if ( V_2 -> V_6 ) {
F_32 ( V_2 , V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
V_6 = F_36 ( sizeof( * V_6 ) , V_130 ) ;
if ( V_6 == NULL )
return;
V_6 -> V_11 = - 1 ;
V_6 -> V_9 = V_57 ;
V_6 -> V_78 = 255 ;
V_6 -> V_71 = V_81 ;
V_6 -> V_6 . V_131 = V_2 -> type == V_132 ? 0 : 1 ;
V_2 -> V_6 = & V_6 -> V_6 ;
V_2 -> V_6 -> V_2 = V_2 ;
}
static int F_37 ( struct V_33 * V_2 ,
struct V_34 * V_6 ,
struct V_133 * V_134 ,
T_2 V_135 )
{
struct V_3 * V_122 = F_2 ( V_6 ) ;
struct V_25 * V_26 = F_7 ( V_2 ) -> V_16 -> V_23 ;
if ( V_134 == V_26 -> V_136 . V_78 )
V_122 -> V_78 = V_135 ;
else if ( V_134 == V_26 -> V_136 . V_71 )
V_122 -> V_71 = V_135 ;
else
return - V_18 ;
return 0 ;
}
static int F_38 ( struct V_33 * V_2 ,
const struct V_34 * V_6 , struct V_133 * V_134 ,
T_2 * V_135 )
{
const struct V_3 * V_122 =
F_39 ( V_6 , const struct V_3 , V_6 ) ;
struct V_25 * V_26 = F_7 ( V_2 ) -> V_16 -> V_23 ;
if ( V_134 == V_26 -> V_136 . V_78 )
* V_135 = V_122 -> V_78 ;
else if ( V_134 == V_26 -> V_136 . V_71 )
* V_135 = V_122 -> V_71 ;
else
return - V_18 ;
return 0 ;
}
int F_40 ( struct V_37 * V_44 )
{
struct V_25 * V_26 = V_44 -> V_23 ;
unsigned int V_137 ;
unsigned int V_14 ;
int V_138 ;
V_44 -> V_12 = V_44 -> V_139 + 7 ;
V_137 = ( ( 1 << V_26 -> V_139 ) - 1 ) & ( 3 << ( 2 * V_44 -> V_17 ) ) ;
for ( V_14 = 0 ; V_14 < V_44 -> V_12 ; ++ V_14 ) {
enum V_140 type = V_14 < V_44 -> V_139
? V_132
: V_141 ;
struct V_1 * V_2 = & V_44 -> V_8 [ V_14 ] ;
V_2 -> V_16 = V_44 ;
V_138 = F_41 ( V_26 -> V_142 , & V_2 -> V_2 , V_137 ,
& V_143 , V_144 ,
F_42 ( V_144 ) , type ,
NULL ) ;
if ( V_138 < 0 )
return V_138 ;
F_43 ( & V_2 -> V_2 ,
& V_145 ) ;
if ( type == V_132 )
continue;
F_44 ( & V_2 -> V_2 . V_146 ,
V_26 -> V_136 . V_78 , 255 ) ;
F_44 ( & V_2 -> V_2 . V_146 ,
V_26 -> V_136 . V_71 ,
V_81 ) ;
F_45 ( & V_2 -> V_2 , 1 , 1 , 7 ) ;
}
return 0 ;
}
