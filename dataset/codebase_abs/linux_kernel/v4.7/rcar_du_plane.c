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
for ( V_14 = 0 ; V_14 < V_23 -> V_33 . V_34 ; ++ V_14 ) {
struct V_3 * V_35 ;
struct V_1 * V_2 ;
unsigned int V_17 ;
if ( ! V_6 -> V_8 [ V_14 ] )
continue;
V_2 = F_6 ( V_6 -> V_8 [ V_14 ] ) ;
V_35 = F_2 ( V_6 -> V_36 [ V_14 ] ) ;
F_7 ( V_26 -> V_23 , L_1 , V_37 ,
V_2 -> V_16 -> V_17 , V_2 - V_2 -> V_16 -> V_8 ) ;
if ( ! V_35 -> V_7 ) {
F_7 ( V_26 -> V_23 , L_2 ,
V_37 ) ;
V_17 = V_2 - V_2 -> V_16 -> V_8 ;
V_28 [ V_2 -> V_16 -> V_17 ] |= 1 << V_17 ;
V_35 -> V_11 = - 1 ;
continue;
}
if ( F_1 ( V_2 , V_35 ) ) {
F_7 ( V_26 -> V_23 , L_3 ,
V_37 ) ;
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
unsigned int V_17 = F_8 ( V_32 ) - 1 ;
struct V_38 * V_16 = & V_26 -> V_32 [ V_17 ] ;
unsigned int V_39 = 0 ;
F_7 ( V_26 -> V_23 , L_4 ,
V_37 , V_17 ) ;
for ( V_14 = 0 ; V_14 < V_16 -> V_12 ; ++ V_14 ) {
struct V_1 * V_2 = & V_16 -> V_8 [ V_14 ] ;
struct V_3 * V_35 ;
struct V_40 * V_41 ;
V_41 = F_9 ( V_6 , & V_2 -> V_2 ) ;
if ( F_10 ( V_41 ) )
return F_11 ( V_41 ) ;
if ( V_28 [ V_17 ] & ( 1 << V_14 ) ) {
F_7 ( V_26 -> V_23 ,
L_5 ,
V_37 , V_2 -> V_16 -> V_17 ,
V_2 - V_2 -> V_16 -> V_8 ) ;
continue;
}
V_35 = F_2 ( V_2 -> V_2 . V_6 ) ;
V_39 |= F_3 ( V_35 ) ;
F_7 ( V_26 -> V_23 ,
L_6 ,
V_37 , V_2 -> V_16 -> V_17 ,
V_2 - V_2 -> V_16 -> V_8 ,
V_35 -> V_7 ?
V_35 -> V_7 -> V_8 : 0 ,
V_35 -> V_11 ) ;
}
V_30 [ V_17 ] = 0xff & ~ V_39 ;
V_32 &= ~ ( 1 << V_17 ) ;
F_7 ( V_26 -> V_23 , L_7 ,
V_37 , V_17 , V_30 [ V_17 ] ) ;
}
for ( V_14 = 0 ; V_14 < V_23 -> V_33 . V_34 ; ++ V_14 ) {
struct V_3 * V_35 ;
struct V_1 * V_2 ;
unsigned int V_42 ;
unsigned int free ;
int V_43 ;
if ( ! V_6 -> V_8 [ V_14 ] )
continue;
V_2 = F_6 ( V_6 -> V_8 [ V_14 ] ) ;
V_35 = F_2 ( V_6 -> V_36 [ V_14 ] ) ;
F_7 ( V_26 -> V_23 , L_8 , V_37 ,
V_2 -> V_16 -> V_17 , V_2 - V_2 -> V_16 -> V_8 ) ;
if ( ! V_35 -> V_7 ||
! F_1 ( V_2 , V_35 ) )
continue;
V_42 = F_12 ( V_35 -> V_6 . V_44 ) -> V_17 % 2
? V_2 -> V_16 -> V_45
: ~ V_2 -> V_16 -> V_45 ;
free = V_30 [ V_2 -> V_16 -> V_17 ] ;
V_43 = F_4 ( V_2 , V_35 ,
free & V_42 ) ;
if ( V_43 < 0 )
V_43 = F_4 ( V_2 , V_35 ,
free ) ;
if ( V_43 < 0 ) {
F_7 ( V_26 -> V_23 , L_9 ,
V_37 ) ;
return V_43 ;
}
F_7 ( V_26 -> V_23 , L_10 ,
V_37 , V_35 -> V_7 -> V_8 , V_43 ) ;
V_35 -> V_11 = V_43 ;
V_30 [ V_2 -> V_16 -> V_17 ] &=
~ F_3 ( V_35 ) ;
F_7 ( V_26 -> V_23 , L_7 ,
V_37 , V_2 -> V_16 -> V_17 ,
V_30 [ V_2 -> V_16 -> V_17 ] ) ;
}
return 0 ;
}
static void F_13 ( struct V_38 * V_46 ,
unsigned int V_17 , T_1 V_47 , T_1 V_48 )
{
F_14 ( V_46 -> V_23 , V_46 -> V_49 + V_17 * V_50 + V_47 ,
V_48 ) ;
}
static void F_15 ( struct V_38 * V_46 ,
const struct V_3 * V_6 )
{
unsigned int V_51 = V_6 -> V_6 . V_51 >> 16 ;
unsigned int V_52 = V_6 -> V_6 . V_52 >> 16 ;
unsigned int V_17 = V_6 -> V_11 ;
unsigned int V_53 ;
bool V_54 ;
T_1 V_55 [ 2 ] ;
V_54 = V_6 -> V_6 . V_44 -> V_6 -> V_56 . V_57
& V_58 ;
if ( V_6 -> V_9 == V_59 ) {
struct V_60 * V_61 = V_6 -> V_6 . V_61 ;
struct V_62 * V_63 ;
unsigned int V_14 ;
if ( V_6 -> V_7 -> V_8 == 2 )
V_53 = V_61 -> V_64 [ 0 ] ;
else
V_53 = V_61 -> V_64 [ 0 ] * 8 / V_6 -> V_7 -> V_65 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_7 -> V_8 ; ++ V_14 ) {
V_63 = F_16 ( V_61 , V_14 ) ;
V_55 [ V_14 ] = V_63 -> V_66 + V_61 -> V_67 [ V_14 ] ;
}
} else {
V_53 = V_6 -> V_6 . V_68 >> 16 ;
V_55 [ 0 ] = 0 ;
V_55 [ 1 ] = 0 ;
}
F_13 ( V_46 , V_17 , V_69 ,
( V_54 && V_6 -> V_7 -> V_65 == 32 ) ?
V_53 * 2 : V_53 ) ;
F_13 ( V_46 , V_17 , V_70 , V_51 ) ;
F_13 ( V_46 , V_17 , V_71 , V_52 *
( ! V_54 && V_6 -> V_7 -> V_65 == 32 ? 2 : 1 ) ) ;
F_13 ( V_46 , V_17 , V_72 , V_55 [ 0 ] ) ;
if ( V_6 -> V_7 -> V_8 == 2 ) {
V_17 = ( V_17 + 1 ) % 8 ;
F_13 ( V_46 , V_17 , V_69 , V_53 ) ;
F_13 ( V_46 , V_17 , V_70 , V_51 ) ;
F_13 ( V_46 , V_17 , V_71 , V_52 *
( V_6 -> V_7 -> V_65 == 16 ? 2 : 1 ) / 2 ) ;
F_13 ( V_46 , V_17 , V_72 , V_55 [ 1 ] ) ;
}
}
static void F_17 ( struct V_38 * V_46 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
T_1 V_73 ;
T_1 V_74 ;
if ( V_6 -> V_7 -> V_75 != V_76 )
F_13 ( V_46 , V_17 , V_77 , V_78 ) ;
else
F_13 ( V_46 , V_17 , V_77 ,
V_79 | V_6 -> V_80 ) ;
V_74 = V_81 | V_6 -> V_7 -> V_74 ;
if ( ( V_6 -> V_73 & V_82 ) == V_83 )
V_74 |= V_84 ;
if ( V_6 -> V_7 -> V_75 == V_85 )
V_74 |= V_86 ;
F_13 ( V_46 , V_17 , V_87 , V_74 ) ;
switch ( V_6 -> V_7 -> V_75 ) {
case V_88 :
V_73 = ( ( V_6 -> V_73 & 0xf80000 ) >> 8 )
| ( ( V_6 -> V_73 & 0x00fc00 ) >> 5 )
| ( ( V_6 -> V_73 & 0x0000f8 ) >> 3 ) ;
F_13 ( V_46 , V_17 , V_89 , V_73 ) ;
break;
case V_90 :
case V_76 :
V_73 = ( ( V_6 -> V_73 & 0xf80000 ) >> 9 )
| ( ( V_6 -> V_73 & 0x00f800 ) >> 6 )
| ( ( V_6 -> V_73 & 0x0000f8 ) >> 3 ) ;
F_13 ( V_46 , V_17 , V_89 , V_73 ) ;
break;
case V_91 :
case V_92 :
F_13 ( V_46 , V_17 , V_93 ,
V_94 | ( V_6 -> V_73 & 0xffffff ) ) ;
break;
}
}
static void F_18 ( struct V_38 * V_46 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
T_1 V_95 = V_96 ;
T_1 V_97 ;
F_17 ( V_46 , V_17 , V_6 ) ;
if ( V_6 -> V_7 -> V_8 == 2 ) {
if ( V_6 -> V_11 != V_17 ) {
if ( V_6 -> V_7 -> V_75 == V_98 ||
V_6 -> V_7 -> V_75 == V_99 )
V_95 |= V_100 ;
if ( V_6 -> V_7 -> V_75 == V_99 )
V_95 |= V_101 ;
V_95 |= V_102 ;
} else {
V_95 |= V_103 ;
}
}
F_13 ( V_46 , V_17 , V_104 , V_95 ) ;
V_97 = V_6 -> V_7 -> V_105 | V_106 ;
if ( V_6 -> V_9 != V_59 )
V_97 |= V_107 ;
F_13 ( V_46 , V_17 , V_108 , V_97 ) ;
}
static void F_19 ( struct V_38 * V_46 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
F_13 ( V_46 , V_17 , V_87 ,
V_84 | V_6 -> V_7 -> V_74 ) ;
F_13 ( V_46 , V_17 , V_108 ,
V_6 -> V_7 -> V_105 | V_106 ) ;
}
static void F_20 ( struct V_38 * V_46 ,
unsigned int V_17 ,
const struct V_3 * V_6 )
{
struct V_25 * V_26 = V_46 -> V_23 ;
if ( V_26 -> V_109 -> V_110 < 3 )
F_18 ( V_46 , V_17 , V_6 ) ;
else
F_19 ( V_46 , V_17 , V_6 ) ;
F_13 ( V_46 , V_17 , V_111 , V_6 -> V_6 . V_112 ) ;
F_13 ( V_46 , V_17 , V_113 , V_6 -> V_6 . V_114 ) ;
F_13 ( V_46 , V_17 , V_115 , V_6 -> V_6 . V_116 ) ;
F_13 ( V_46 , V_17 , V_117 , V_6 -> V_6 . V_118 ) ;
if ( V_26 -> V_109 -> V_110 < 3 ) {
F_13 ( V_46 , V_17 , V_119 , 0 ) ;
F_13 ( V_46 , V_17 , V_120 , 4095 ) ;
F_13 ( V_46 , V_17 , V_121 , 0 ) ;
F_13 ( V_46 , V_17 , V_122 , 0 ) ;
}
}
void F_21 ( struct V_38 * V_46 ,
const struct V_3 * V_6 )
{
struct V_25 * V_26 = V_46 -> V_23 ;
F_20 ( V_46 , V_6 -> V_11 , V_6 ) ;
if ( V_6 -> V_7 -> V_8 == 2 )
F_20 ( V_46 , ( V_6 -> V_11 + 1 ) % 8 ,
V_6 ) ;
if ( V_26 -> V_109 -> V_110 < 3 )
F_15 ( V_46 , V_6 ) ;
if ( V_6 -> V_9 == V_19 ) {
unsigned int V_123 = V_46 -> V_17 ? 2 : 0 ;
if ( V_26 -> V_123 != V_123 ) {
V_26 -> V_123 = V_123 ;
F_22 ( V_26 ) ;
}
}
}
static int F_23 ( struct V_124 * V_2 ,
struct V_40 * V_6 )
{
struct V_3 * V_125 = F_2 ( V_6 ) ;
struct V_1 * V_126 = F_6 ( V_2 ) ;
struct V_25 * V_26 = V_126 -> V_16 -> V_23 ;
if ( ! V_6 -> V_61 || ! V_6 -> V_44 ) {
V_125 -> V_7 = NULL ;
return 0 ;
}
if ( V_6 -> V_68 >> 16 != V_6 -> V_112 ||
V_6 -> V_127 >> 16 != V_6 -> V_114 ) {
F_7 ( V_26 -> V_23 , L_11 , V_37 ) ;
return - V_18 ;
}
V_125 -> V_7 = F_24 ( V_6 -> V_61 -> V_128 ) ;
if ( V_125 -> V_7 == NULL ) {
F_7 ( V_26 -> V_23 , L_12 , V_37 ,
V_6 -> V_61 -> V_128 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_25 ( struct V_124 * V_2 ,
struct V_40 * V_129 )
{
struct V_1 * V_126 = F_6 ( V_2 ) ;
struct V_3 * V_130 ;
struct V_3 * V_131 ;
if ( ! V_2 -> V_6 -> V_44 )
return;
F_26 ( V_126 ) ;
V_130 = F_2 ( V_129 ) ;
V_131 = F_2 ( V_2 -> V_6 ) ;
if ( ( V_130 -> V_9 == V_59 ) !=
( V_131 -> V_9 == V_59 ) )
V_126 -> V_16 -> V_132 = true ;
}
static struct V_40 *
F_27 ( struct V_124 * V_2 )
{
struct V_3 * V_6 ;
struct V_3 * V_133 ;
if ( F_28 ( ! V_2 -> V_6 ) )
return NULL ;
V_6 = F_2 ( V_2 -> V_6 ) ;
V_133 = F_29 ( V_6 , sizeof( * V_6 ) , V_134 ) ;
if ( V_133 == NULL )
return NULL ;
F_30 ( V_2 , & V_133 -> V_6 ) ;
return & V_133 -> V_6 ;
}
static void F_31 ( struct V_124 * V_2 ,
struct V_40 * V_6 )
{
F_32 ( V_6 ) ;
F_33 ( F_2 ( V_6 ) ) ;
}
static void F_34 ( struct V_124 * V_2 )
{
struct V_3 * V_6 ;
if ( V_2 -> V_6 ) {
F_31 ( V_2 , V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
V_6 = F_35 ( sizeof( * V_6 ) , V_134 ) ;
if ( V_6 == NULL )
return;
V_6 -> V_11 = - 1 ;
V_6 -> V_9 = V_59 ;
V_6 -> V_80 = 255 ;
V_6 -> V_73 = V_83 ;
V_6 -> V_135 = V_2 -> type == V_136 ? 0 : 1 ;
V_2 -> V_6 = & V_6 -> V_6 ;
V_2 -> V_6 -> V_2 = V_2 ;
}
static int F_36 ( struct V_124 * V_2 ,
struct V_40 * V_6 ,
struct V_137 * V_138 ,
T_2 V_139 )
{
struct V_3 * V_125 = F_2 ( V_6 ) ;
struct V_25 * V_26 = F_6 ( V_2 ) -> V_16 -> V_23 ;
if ( V_138 == V_26 -> V_140 . V_80 )
V_125 -> V_80 = V_139 ;
else if ( V_138 == V_26 -> V_140 . V_73 )
V_125 -> V_73 = V_139 ;
else if ( V_138 == V_26 -> V_140 . V_135 )
V_125 -> V_135 = V_139 ;
else
return - V_18 ;
return 0 ;
}
static int F_37 ( struct V_124 * V_2 ,
const struct V_40 * V_6 , struct V_137 * V_138 ,
T_2 * V_139 )
{
const struct V_3 * V_125 =
F_38 ( V_6 , const struct V_3 , V_6 ) ;
struct V_25 * V_26 = F_6 ( V_2 ) -> V_16 -> V_23 ;
if ( V_138 == V_26 -> V_140 . V_80 )
* V_139 = V_125 -> V_80 ;
else if ( V_138 == V_26 -> V_140 . V_73 )
* V_139 = V_125 -> V_73 ;
else if ( V_138 == V_26 -> V_140 . V_135 )
* V_139 = V_125 -> V_135 ;
else
return - V_18 ;
return 0 ;
}
int F_39 ( struct V_38 * V_46 )
{
struct V_25 * V_26 = V_46 -> V_23 ;
unsigned int V_141 ;
unsigned int V_14 ;
int V_142 ;
V_46 -> V_12 = V_46 -> V_143 + 7 ;
V_141 = ( ( 1 << V_26 -> V_143 ) - 1 ) & ( 3 << ( 2 * V_46 -> V_17 ) ) ;
for ( V_14 = 0 ; V_14 < V_46 -> V_12 ; ++ V_14 ) {
enum V_144 type = V_14 < V_46 -> V_143
? V_136
: V_145 ;
struct V_1 * V_2 = & V_46 -> V_8 [ V_14 ] ;
V_2 -> V_16 = V_46 ;
V_142 = F_40 ( V_26 -> V_146 , & V_2 -> V_2 , V_141 ,
& V_147 , V_148 ,
F_41 ( V_148 ) , type ,
NULL ) ;
if ( V_142 < 0 )
return V_142 ;
F_42 ( & V_2 -> V_2 ,
& V_149 ) ;
if ( type == V_136 )
continue;
F_43 ( & V_2 -> V_2 . V_150 ,
V_26 -> V_140 . V_80 , 255 ) ;
F_43 ( & V_2 -> V_2 . V_150 ,
V_26 -> V_140 . V_73 ,
V_83 ) ;
F_43 ( & V_2 -> V_2 . V_150 ,
V_26 -> V_140 . V_135 , 1 ) ;
}
return 0 ;
}
