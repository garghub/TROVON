static bool F_1 (
const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
if ( ! V_2 -> V_4 ||
V_2 -> V_4 -> V_5 != V_3 -> V_4 -> V_5 )
return true ;
if ( V_2 -> V_6 != V_3 -> V_6 )
return true ;
return false ;
}
static unsigned int F_2 ( struct V_1 * V_7 )
{
unsigned int V_8 ;
if ( V_7 -> V_9 == - 1 )
return 0 ;
V_8 = 1 << V_7 -> V_9 ;
if ( V_7 -> V_4 -> V_5 == 2 )
V_8 |= 1 << ( ( V_7 -> V_9 + 1 ) % 8 ) ;
return V_8 ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_1 * V_7 ,
unsigned int free )
{
unsigned int V_12 = V_7 -> V_4 -> V_5 ;
int V_13 = - 1 ;
int V_14 ;
if ( V_7 -> V_6 == V_15 ) {
if ( V_11 -> V_16 -> V_17 != 0 )
return - V_18 ;
V_13 = 0 ;
} else if ( V_7 -> V_6 == V_19 ) {
V_13 = V_11 -> V_16 -> V_17 == 0 ? 1 : 0 ;
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
int F_4 ( struct V_22 * V_23 ,
struct V_24 * V_7 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
unsigned int V_28 [ V_29 ] = { 0 , } ;
unsigned int V_30 [ V_29 ] = { 0 , } ;
bool V_31 = false ;
unsigned int V_32 = 0 ;
unsigned int V_14 ;
struct V_33 * V_33 ;
struct V_34 * V_35 ;
struct V_34 * V_36 ;
F_5 (state, drm_plane, old_drm_plane_state,
new_drm_plane_state, i) {
struct V_1 * V_37 ;
struct V_1 * V_38 ;
struct V_10 * V_11 ;
unsigned int V_17 ;
V_11 = F_6 ( V_33 ) ;
V_37 = F_7 ( V_35 ) ;
V_38 = F_7 ( V_36 ) ;
F_8 ( V_26 -> V_23 , L_1 , V_39 ,
V_11 -> V_16 -> V_17 , V_11 - V_11 -> V_16 -> V_5 ) ;
if ( ! V_38 -> V_4 ) {
F_8 ( V_26 -> V_23 , L_2 ,
V_39 ) ;
V_17 = V_11 - V_11 -> V_16 -> V_5 ;
V_28 [ V_11 -> V_16 -> V_17 ] |= 1 << V_17 ;
V_38 -> V_9 = - 1 ;
continue;
}
if ( F_1 ( V_37 , V_38 ) ) {
F_8 ( V_26 -> V_23 , L_3 ,
V_39 ) ;
V_32 |= 1 << V_11 -> V_16 -> V_17 ;
V_31 = true ;
V_17 = V_11 - V_11 -> V_16 -> V_5 ;
V_28 [ V_11 -> V_16 -> V_17 ] |= 1 << V_17 ;
V_38 -> V_9 = - 1 ;
}
}
if ( ! V_31 )
return 0 ;
while ( V_32 ) {
unsigned int V_17 = F_9 ( V_32 ) - 1 ;
struct V_40 * V_16 = & V_26 -> V_32 [ V_17 ] ;
unsigned int V_41 = 0 ;
F_8 ( V_26 -> V_23 , L_4 ,
V_39 , V_17 ) ;
for ( V_14 = 0 ; V_14 < V_16 -> V_12 ; ++ V_14 ) {
struct V_10 * V_11 = & V_16 -> V_5 [ V_14 ] ;
struct V_1 * V_38 ;
struct V_34 * V_42 ;
V_42 = F_10 ( V_7 , & V_11 -> V_11 ) ;
if ( F_11 ( V_42 ) )
return F_12 ( V_42 ) ;
if ( V_28 [ V_17 ] & ( 1 << V_14 ) ) {
F_8 ( V_26 -> V_23 ,
L_5 ,
V_39 , V_11 -> V_16 -> V_17 ,
V_11 - V_11 -> V_16 -> V_5 ) ;
continue;
}
V_38 = F_7 ( V_42 ) ;
V_41 |= F_2 ( V_38 ) ;
F_8 ( V_26 -> V_23 ,
L_6 ,
V_39 , V_11 -> V_16 -> V_17 ,
V_11 - V_11 -> V_16 -> V_5 ,
V_38 -> V_4 ?
V_38 -> V_4 -> V_5 : 0 ,
V_38 -> V_9 ) ;
}
V_30 [ V_17 ] = 0xff & ~ V_41 ;
V_32 &= ~ ( 1 << V_17 ) ;
F_8 ( V_26 -> V_23 , L_7 ,
V_39 , V_17 , V_30 [ V_17 ] ) ;
}
F_5 (state, drm_plane, old_drm_plane_state,
new_drm_plane_state, i) {
struct V_1 * V_37 ;
struct V_1 * V_38 ;
struct V_10 * V_11 ;
unsigned int V_43 ;
unsigned int free ;
int V_44 ;
V_11 = F_6 ( V_33 ) ;
V_37 = F_7 ( V_35 ) ;
V_38 = F_7 ( V_36 ) ;
F_8 ( V_26 -> V_23 , L_8 , V_39 ,
V_11 -> V_16 -> V_17 , V_11 - V_11 -> V_16 -> V_5 ) ;
if ( ! V_38 -> V_4 ||
! F_1 ( V_37 , V_38 ) )
continue;
V_43 = F_13 ( V_38 -> V_7 . V_45 ) -> V_17 % 2
? V_11 -> V_16 -> V_46
: ~ V_11 -> V_16 -> V_46 ;
free = V_30 [ V_11 -> V_16 -> V_17 ] ;
V_44 = F_3 ( V_11 , V_38 ,
free & V_43 ) ;
if ( V_44 < 0 )
V_44 = F_3 ( V_11 , V_38 ,
free ) ;
if ( V_44 < 0 ) {
F_8 ( V_26 -> V_23 , L_9 ,
V_39 ) ;
return V_44 ;
}
F_8 ( V_26 -> V_23 , L_10 ,
V_39 , V_38 -> V_4 -> V_5 , V_44 ) ;
V_38 -> V_9 = V_44 ;
V_30 [ V_11 -> V_16 -> V_17 ] &=
~ F_2 ( V_38 ) ;
F_8 ( V_26 -> V_23 , L_7 ,
V_39 , V_11 -> V_16 -> V_17 ,
V_30 [ V_11 -> V_16 -> V_17 ] ) ;
}
return 0 ;
}
static void F_14 ( struct V_40 * V_47 ,
unsigned int V_17 , T_1 V_48 , T_1 V_49 )
{
F_15 ( V_47 -> V_23 , V_47 -> V_50 + V_17 * V_51 + V_48 ,
V_49 ) ;
}
static void F_16 ( struct V_40 * V_47 ,
const struct V_1 * V_7 )
{
unsigned int V_52 = V_7 -> V_7 . V_52 >> 16 ;
unsigned int V_53 = V_7 -> V_7 . V_53 >> 16 ;
unsigned int V_17 = V_7 -> V_9 ;
unsigned int V_54 ;
bool V_55 ;
T_1 V_56 [ 2 ] ;
V_55 = V_7 -> V_7 . V_45 -> V_7 -> V_57 . V_58
& V_59 ;
if ( V_7 -> V_6 == V_60 ) {
struct V_61 * V_62 = V_7 -> V_7 . V_62 ;
struct V_63 * V_64 ;
unsigned int V_14 ;
if ( V_7 -> V_4 -> V_5 == 2 )
V_54 = V_62 -> V_65 [ 0 ] ;
else
V_54 = V_62 -> V_65 [ 0 ] * 8 / V_7 -> V_4 -> V_66 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_4 -> V_5 ; ++ V_14 ) {
V_64 = F_17 ( V_62 , V_14 ) ;
V_56 [ V_14 ] = V_64 -> V_67 + V_62 -> V_68 [ V_14 ] ;
}
} else {
V_54 = V_7 -> V_7 . V_69 >> 16 ;
V_56 [ 0 ] = 0 ;
V_56 [ 1 ] = 0 ;
}
F_14 ( V_47 , V_17 , V_70 ,
( V_55 && V_7 -> V_4 -> V_66 == 32 ) ?
V_54 * 2 : V_54 ) ;
F_14 ( V_47 , V_17 , V_71 , V_52 ) ;
F_14 ( V_47 , V_17 , V_72 , V_53 *
( ! V_55 && V_7 -> V_4 -> V_66 == 32 ? 2 : 1 ) ) ;
F_14 ( V_47 , V_17 , V_73 , V_56 [ 0 ] ) ;
if ( V_7 -> V_4 -> V_5 == 2 ) {
V_17 = ( V_17 + 1 ) % 8 ;
F_14 ( V_47 , V_17 , V_70 , V_54 ) ;
F_14 ( V_47 , V_17 , V_71 , V_52 ) ;
F_14 ( V_47 , V_17 , V_72 , V_53 *
( V_7 -> V_4 -> V_66 == 16 ? 2 : 1 ) / 2 ) ;
F_14 ( V_47 , V_17 , V_73 , V_56 [ 1 ] ) ;
}
}
static void F_18 ( struct V_40 * V_47 ,
unsigned int V_17 ,
const struct V_1 * V_7 )
{
T_1 V_74 ;
T_1 V_75 ;
if ( V_7 -> V_4 -> V_76 != V_77 )
F_14 ( V_47 , V_17 , V_78 , V_79 ) ;
else
F_14 ( V_47 , V_17 , V_78 ,
V_80 | V_7 -> V_81 ) ;
V_75 = V_82 | V_7 -> V_4 -> V_75 ;
if ( ( V_7 -> V_74 & V_83 ) == V_84 )
V_75 |= V_85 ;
if ( V_7 -> V_4 -> V_76 == V_86 )
V_75 |= V_87 ;
F_14 ( V_47 , V_17 , V_88 , V_75 ) ;
switch ( V_7 -> V_4 -> V_76 ) {
case V_89 :
V_74 = ( ( V_7 -> V_74 & 0xf80000 ) >> 8 )
| ( ( V_7 -> V_74 & 0x00fc00 ) >> 5 )
| ( ( V_7 -> V_74 & 0x0000f8 ) >> 3 ) ;
F_14 ( V_47 , V_17 , V_90 , V_74 ) ;
break;
case V_91 :
case V_77 :
V_74 = ( ( V_7 -> V_74 & 0xf80000 ) >> 9 )
| ( ( V_7 -> V_74 & 0x00f800 ) >> 6 )
| ( ( V_7 -> V_74 & 0x0000f8 ) >> 3 ) ;
F_14 ( V_47 , V_17 , V_90 , V_74 ) ;
break;
case V_92 :
case V_93 :
F_14 ( V_47 , V_17 , V_94 ,
V_95 | ( V_7 -> V_74 & 0xffffff ) ) ;
break;
}
}
static void F_19 ( struct V_40 * V_47 ,
unsigned int V_17 ,
const struct V_1 * V_7 )
{
T_1 V_96 = V_97 ;
T_1 V_98 ;
F_18 ( V_47 , V_17 , V_7 ) ;
if ( V_7 -> V_4 -> V_5 == 2 ) {
if ( V_7 -> V_9 != V_17 ) {
if ( V_7 -> V_4 -> V_76 == V_99 ||
V_7 -> V_4 -> V_76 == V_100 )
V_96 |= V_101 ;
if ( V_7 -> V_4 -> V_76 == V_100 )
V_96 |= V_102 ;
V_96 |= V_103 ;
} else {
V_96 |= V_104 ;
}
}
F_14 ( V_47 , V_17 , V_105 , V_96 ) ;
V_98 = V_7 -> V_4 -> V_106 | V_107 ;
if ( V_7 -> V_6 != V_60 )
V_98 |= V_108 ;
F_14 ( V_47 , V_17 , V_109 , V_98 ) ;
}
static void F_20 ( struct V_40 * V_47 ,
unsigned int V_17 ,
const struct V_1 * V_7 )
{
F_14 ( V_47 , V_17 , V_88 ,
V_85 | V_7 -> V_4 -> V_75 ) ;
F_14 ( V_47 , V_17 , V_109 ,
V_7 -> V_4 -> V_106 | V_107 ) ;
}
static void F_21 ( struct V_40 * V_47 ,
unsigned int V_17 ,
const struct V_1 * V_7 )
{
struct V_25 * V_26 = V_47 -> V_23 ;
if ( V_26 -> V_110 -> V_111 < 3 )
F_19 ( V_47 , V_17 , V_7 ) ;
else
F_20 ( V_47 , V_17 , V_7 ) ;
F_14 ( V_47 , V_17 , V_112 , V_7 -> V_7 . V_113 ) ;
F_14 ( V_47 , V_17 , V_114 , V_7 -> V_7 . V_115 ) ;
F_14 ( V_47 , V_17 , V_116 , V_7 -> V_7 . V_117 ) ;
F_14 ( V_47 , V_17 , V_118 , V_7 -> V_7 . V_119 ) ;
if ( V_26 -> V_110 -> V_111 < 3 ) {
F_14 ( V_47 , V_17 , V_120 , 0 ) ;
F_14 ( V_47 , V_17 , V_121 , 4095 ) ;
F_14 ( V_47 , V_17 , V_122 , 0 ) ;
F_14 ( V_47 , V_17 , V_123 , 0 ) ;
}
}
void F_22 ( struct V_40 * V_47 ,
const struct V_1 * V_7 )
{
struct V_25 * V_26 = V_47 -> V_23 ;
F_21 ( V_47 , V_7 -> V_9 , V_7 ) ;
if ( V_7 -> V_4 -> V_5 == 2 )
F_21 ( V_47 , ( V_7 -> V_9 + 1 ) % 8 ,
V_7 ) ;
if ( V_26 -> V_110 -> V_111 < 3 )
F_16 ( V_47 , V_7 ) ;
if ( V_7 -> V_6 == V_19 ) {
unsigned int V_124 = V_47 -> V_17 ? 2 : 0 ;
if ( V_26 -> V_124 != V_124 ) {
V_26 -> V_124 = V_124 ;
F_23 ( V_26 ) ;
}
}
}
static int F_24 ( struct V_33 * V_11 ,
struct V_34 * V_7 )
{
struct V_1 * V_125 = F_7 ( V_7 ) ;
struct V_10 * V_126 = F_6 ( V_11 ) ;
struct V_25 * V_26 = V_126 -> V_16 -> V_23 ;
if ( ! V_7 -> V_62 || ! V_7 -> V_45 ) {
V_125 -> V_4 = NULL ;
return 0 ;
}
if ( V_7 -> V_69 >> 16 != V_7 -> V_113 ||
V_7 -> V_127 >> 16 != V_7 -> V_115 ) {
F_8 ( V_26 -> V_23 , L_11 , V_39 ) ;
return - V_18 ;
}
V_125 -> V_4 = F_25 ( V_7 -> V_62 -> V_4 -> V_4 ) ;
if ( V_125 -> V_4 == NULL ) {
F_8 ( V_26 -> V_23 , L_12 , V_39 ,
V_7 -> V_62 -> V_4 -> V_4 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_26 ( struct V_33 * V_11 ,
struct V_34 * V_2 )
{
struct V_10 * V_126 = F_6 ( V_11 ) ;
struct V_1 * V_128 ;
struct V_1 * V_129 ;
if ( ! V_11 -> V_7 -> V_45 )
return;
F_27 ( V_126 ) ;
V_128 = F_7 ( V_2 ) ;
V_129 = F_7 ( V_11 -> V_7 ) ;
if ( ( V_128 -> V_6 == V_60 ) !=
( V_129 -> V_6 == V_60 ) )
V_126 -> V_16 -> V_130 = true ;
}
static struct V_34 *
F_28 ( struct V_33 * V_11 )
{
struct V_1 * V_7 ;
struct V_1 * V_131 ;
if ( F_29 ( ! V_11 -> V_7 ) )
return NULL ;
V_7 = F_7 ( V_11 -> V_7 ) ;
V_131 = F_30 ( V_7 , sizeof( * V_7 ) , V_132 ) ;
if ( V_131 == NULL )
return NULL ;
F_31 ( V_11 , & V_131 -> V_7 ) ;
return & V_131 -> V_7 ;
}
static void F_32 ( struct V_33 * V_11 ,
struct V_34 * V_7 )
{
F_33 ( V_7 ) ;
F_34 ( F_7 ( V_7 ) ) ;
}
static void F_35 ( struct V_33 * V_11 )
{
struct V_1 * V_7 ;
if ( V_11 -> V_7 ) {
F_32 ( V_11 , V_11 -> V_7 ) ;
V_11 -> V_7 = NULL ;
}
V_7 = F_36 ( sizeof( * V_7 ) , V_132 ) ;
if ( V_7 == NULL )
return;
V_7 -> V_9 = - 1 ;
V_7 -> V_6 = V_60 ;
V_7 -> V_81 = 255 ;
V_7 -> V_74 = V_84 ;
V_7 -> V_7 . V_133 = V_11 -> type == V_134 ? 0 : 1 ;
V_11 -> V_7 = & V_7 -> V_7 ;
V_11 -> V_7 -> V_11 = V_11 ;
}
static int F_37 ( struct V_33 * V_11 ,
struct V_34 * V_7 ,
struct V_135 * V_136 ,
T_2 V_137 )
{
struct V_1 * V_125 = F_7 ( V_7 ) ;
struct V_25 * V_26 = F_6 ( V_11 ) -> V_16 -> V_23 ;
if ( V_136 == V_26 -> V_138 . V_81 )
V_125 -> V_81 = V_137 ;
else if ( V_136 == V_26 -> V_138 . V_74 )
V_125 -> V_74 = V_137 ;
else
return - V_18 ;
return 0 ;
}
static int F_38 ( struct V_33 * V_11 ,
const struct V_34 * V_7 , struct V_135 * V_136 ,
T_2 * V_137 )
{
const struct V_1 * V_125 =
F_39 ( V_7 , const struct V_1 , V_7 ) ;
struct V_25 * V_26 = F_6 ( V_11 ) -> V_16 -> V_23 ;
if ( V_136 == V_26 -> V_138 . V_81 )
* V_137 = V_125 -> V_81 ;
else if ( V_136 == V_26 -> V_138 . V_74 )
* V_137 = V_125 -> V_74 ;
else
return - V_18 ;
return 0 ;
}
int F_40 ( struct V_40 * V_47 )
{
struct V_25 * V_26 = V_47 -> V_23 ;
unsigned int V_139 ;
unsigned int V_14 ;
int V_140 ;
V_47 -> V_12 = V_47 -> V_141 + 7 ;
V_139 = ( ( 1 << V_26 -> V_141 ) - 1 ) & ( 3 << ( 2 * V_47 -> V_17 ) ) ;
for ( V_14 = 0 ; V_14 < V_47 -> V_12 ; ++ V_14 ) {
enum V_142 type = V_14 < V_47 -> V_141
? V_134
: V_143 ;
struct V_10 * V_11 = & V_47 -> V_5 [ V_14 ] ;
V_11 -> V_16 = V_47 ;
V_140 = F_41 ( V_26 -> V_144 , & V_11 -> V_11 , V_139 ,
& V_145 , V_146 ,
F_42 ( V_146 ) ,
NULL , type , NULL ) ;
if ( V_140 < 0 )
return V_140 ;
F_43 ( & V_11 -> V_11 ,
& V_147 ) ;
if ( type == V_134 )
continue;
F_44 ( & V_11 -> V_11 . V_148 ,
V_26 -> V_138 . V_81 , 255 ) ;
F_44 ( & V_11 -> V_11 . V_148 ,
V_26 -> V_138 . V_74 ,
V_84 ) ;
F_45 ( & V_11 -> V_11 , 1 , 1 , 7 ) ;
}
return 0 ;
}
