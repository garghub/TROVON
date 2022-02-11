static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
switch ( V_3 ) {
case V_6 :
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
memcpy ( V_4 , V_8 [ V_5 ] . V_9 ,
V_10 ) ;
V_4 += V_10 ;
}
break;
}
}
static void F_2 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_3 * V_4 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
T_2 * V_15 ;
int V_5 ;
V_14 -> V_16 . V_17 ( V_14 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_15 = ( T_2 * ) V_14 + V_8 [ V_5 ] . V_18 ;
* V_4 ++ = * ( T_3 * ) V_15 ;
}
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_19 ;
switch ( V_3 ) {
case V_6 :
V_19 = V_7 ;
break;
default:
V_19 = - V_20 ;
}
return V_19 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_22 -> V_23 = V_14 -> V_24 . V_25 ;
V_22 -> V_26 = V_14 -> V_24 . V_26 ;
V_22 -> V_27 = V_14 -> V_24 . V_27 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
int V_19 = 0 ;
if ( V_22 -> V_23 && ( V_14 -> V_24 . V_23 != V_28 ) ) {
F_7 ( V_2 ,
L_1 ) ;
return - V_29 ;
}
V_14 -> V_24 . V_25 = V_22 -> V_23 ;
V_14 -> V_24 . V_26 = V_22 -> V_26 ;
V_14 -> V_24 . V_27 = V_22 -> V_27 ;
V_14 -> V_24 . V_30 &= ~ V_31 ;
V_14 -> V_24 . V_30 &= ~ V_32 ;
if ( V_22 -> V_27 ) {
V_14 -> V_24 . V_30 |= V_31 ;
V_14 -> V_24 . V_30 |= V_32 ;
}
if ( V_22 -> V_26 )
V_14 -> V_24 . V_30 ^= V_32 ;
if ( F_8 ( V_2 ) )
V_19 = V_14 -> V_33 . V_34 ( V_14 ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_36 -> V_37 = V_14 -> V_24 . V_38 ;
V_36 -> V_39 = V_14 -> V_24 . V_39 ;
V_36 -> V_30 = V_14 -> V_24 . V_30 ;
V_36 -> V_40 = V_14 -> V_24 . V_40 ;
V_36 -> V_23 = V_14 -> V_24 . V_23 ;
F_10 ( V_36 , V_14 -> V_24 . V_41 ) ;
V_36 -> V_42 = V_14 -> V_24 . V_42 ;
V_36 -> V_43 = V_44 ;
V_36 -> V_45 = V_46 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
T_1 V_41 ;
int V_19 ;
V_41 = F_12 ( V_36 ) ;
if ( V_36 -> V_37 != V_14 -> V_24 . V_38 ) {
F_7 ( V_2 , L_2 ,
V_36 -> V_37 ) ;
return - V_29 ;
}
if ( ( V_36 -> V_23 != V_28 ) &&
( V_36 -> V_23 != V_47 ) ) {
F_7 ( V_2 , L_3 ,
V_36 -> V_23 ) ;
return - V_29 ;
}
if ( V_36 -> V_23 == V_47 ) {
switch ( V_41 ) {
case V_48 :
break;
case V_49 :
if ( V_14 -> V_50 != V_51 ) {
F_7 ( V_2 , L_4 ,
V_41 ) ;
return - V_29 ;
}
break;
case V_52 :
if ( V_14 -> V_50 != V_53 ) {
F_7 ( V_2 , L_4 ,
V_41 ) ;
return - V_29 ;
}
break;
default:
F_7 ( V_2 , L_4 , V_41 ) ;
return - V_29 ;
}
if ( V_36 -> V_42 != V_54 ) {
F_7 ( V_2 , L_5 ,
V_36 -> V_42 ) ;
return - V_29 ;
}
}
F_13 ( V_14 , V_55 , V_2 ,
L_6 ,
V_36 -> V_30 , V_14 -> V_24 . V_39 ) ;
V_36 -> V_30 &= V_14 -> V_24 . V_39 ;
if ( ( V_36 -> V_23 == V_28 ) && ! V_36 -> V_30 ) {
F_7 ( V_2 ,
L_7 ) ;
return - V_29 ;
}
V_19 = 0 ;
V_14 -> V_24 . V_23 = V_36 -> V_23 ;
V_14 -> V_24 . V_41 = V_41 ;
V_14 -> V_24 . V_42 = V_36 -> V_42 ;
V_14 -> V_24 . V_30 = V_36 -> V_30 ;
if ( V_36 -> V_23 == V_28 )
V_14 -> V_24 . V_30 |= V_56 ;
else
V_14 -> V_24 . V_30 &= ~ V_56 ;
if ( F_8 ( V_2 ) )
V_19 = V_14 -> V_33 . V_34 ( V_14 ) ;
return V_19 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_59 * V_60 = & V_14 -> V_60 ;
F_15 ( V_58 -> V_61 , V_62 , sizeof( V_58 -> V_61 ) ) ;
F_15 ( V_58 -> V_63 , V_64 , sizeof( V_58 -> V_63 ) ) ;
F_15 ( V_58 -> V_65 , F_16 ( V_14 -> V_66 ) ,
sizeof( V_58 -> V_65 ) ) ;
snprintf ( V_58 -> V_67 , sizeof( V_58 -> V_67 ) , L_8 ,
F_17 ( V_60 -> V_63 , V_68 , V_69 ) ,
F_17 ( V_60 -> V_63 , V_68 , V_70 ) ,
F_17 ( V_60 -> V_63 , V_68 , V_71 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return V_14 -> V_72 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_73 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_14 -> V_72 = V_73 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 -> V_76 = V_14 -> V_77 ;
V_75 -> V_78 = V_14 -> V_79 ;
V_75 -> V_80 = V_14 -> V_81 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_82 * V_16 = & V_14 -> V_16 ;
unsigned int V_79 , V_83 , V_77 ;
unsigned int V_81 ;
if ( ( V_75 -> V_84 ) ||
( V_75 -> V_85 ) ||
( V_75 -> V_86 ) ||
( V_75 -> V_87 ) ||
( V_75 -> V_88 ) ||
( V_75 -> V_89 ) ||
( V_75 -> V_90 ) ||
( V_75 -> V_91 ) ||
( V_75 -> V_92 ) ||
( V_75 -> V_93 ) ||
( V_75 -> V_94 ) ||
( V_75 -> V_95 ) ||
( V_75 -> V_96 ) ||
( V_75 -> V_97 ) ||
( V_75 -> V_98 ) ||
( V_75 -> V_99 ) ||
( V_75 -> V_100 ) ||
( V_75 -> V_101 ) ||
( V_75 -> V_102 ) ) {
F_7 ( V_2 , L_9 ) ;
return - V_20 ;
}
V_83 = V_16 -> V_103 ( V_14 , V_75 -> V_76 ) ;
V_77 = V_75 -> V_76 ;
V_79 = V_75 -> V_78 ;
if ( V_77 && ! V_83 )
V_83 = 1 ;
if ( V_83 > V_104 ) {
F_7 ( V_2 , L_10 ,
V_16 -> V_105 ( V_14 , V_104 ) ) ;
return - V_29 ;
}
if ( V_79 > V_14 -> V_106 ) {
F_7 ( V_2 , L_11 ,
V_14 -> V_106 ) ;
return - V_29 ;
}
V_81 = V_75 -> V_80 ;
if ( V_81 > V_14 -> V_107 ) {
F_7 ( V_2 , L_12 ,
V_14 -> V_107 ) ;
return - V_29 ;
}
V_14 -> V_83 = V_83 ;
V_14 -> V_77 = V_77 ;
V_14 -> V_79 = V_79 ;
V_16 -> V_108 ( V_14 ) ;
V_14 -> V_81 = V_81 ;
V_16 -> V_109 ( V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_110 * V_111 , T_1 * V_112 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
switch ( V_111 -> V_36 ) {
case V_113 :
V_111 -> V_4 = V_14 -> V_114 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return sizeof( V_14 -> V_115 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return F_25 ( V_14 -> V_116 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_117 , T_2 * V_118 ,
T_2 * V_119 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
unsigned int V_5 ;
if ( V_117 ) {
for ( V_5 = 0 ; V_5 < F_25 ( V_14 -> V_116 ) ; V_5 ++ )
V_117 [ V_5 ] = F_17 ( V_14 -> V_116 [ V_5 ] ,
V_120 , V_121 ) ;
}
if ( V_118 )
memcpy ( V_118 , V_14 -> V_115 , sizeof( V_14 -> V_115 ) ) ;
if ( V_119 )
* V_119 = V_122 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const T_1 * V_117 ,
const T_2 * V_118 , const T_2 V_119 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_82 * V_16 = & V_14 -> V_16 ;
unsigned int V_19 ;
if ( V_119 != V_123 && V_119 != V_122 ) {
F_7 ( V_2 , L_13 ) ;
return - V_20 ;
}
if ( V_117 ) {
V_19 = V_16 -> V_124 ( V_14 , V_117 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_118 ) {
V_19 = V_16 -> V_125 ( V_14 , V_118 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_127 -> V_128 = V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 ;
if ( V_14 -> V_135 )
V_127 -> V_136 = F_29 ( V_14 -> V_135 ) ;
else
V_127 -> V_136 = - 1 ;
V_127 -> V_137 = ( 1 << V_138 ) | ( 1 << V_139 ) ;
V_127 -> V_140 = ( 1 << V_141 ) |
( 1 << V_142 ) |
( 1 << V_143 ) |
( 1 << V_144 ) |
( 1 << V_145 ) |
( 1 << V_146 ) |
( 1 << V_147 ) |
( 1 << V_148 ) |
( 1 << V_149 ) |
( 1 << V_150 ) |
( 1 << V_151 ) ;
return 0 ;
}
const struct V_152 * F_30 ( void )
{
return & V_153 ;
}
