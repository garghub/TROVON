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
V_36 -> V_37 . V_38 = V_14 -> V_24 . V_39 ;
F_10 ( V_36 -> V_40 . V_41 ,
V_14 -> V_24 . V_41 ) ;
F_10 ( V_36 -> V_40 . V_30 ,
V_14 -> V_24 . V_30 ) ;
F_10 ( V_36 -> V_40 . V_42 ,
V_14 -> V_24 . V_42 ) ;
V_36 -> V_37 . V_23 = V_14 -> V_24 . V_23 ;
V_36 -> V_37 . V_43 = V_14 -> V_24 . V_43 ;
V_36 -> V_37 . V_44 = V_14 -> V_24 . V_44 ;
V_36 -> V_37 . V_45 = V_46 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
T_1 V_30 ;
T_1 V_43 ;
int V_19 ;
V_43 = V_36 -> V_37 . V_43 ;
if ( V_36 -> V_37 . V_38 != V_14 -> V_24 . V_39 ) {
F_7 ( V_2 , L_2 ,
V_36 -> V_37 . V_38 ) ;
return - V_29 ;
}
if ( ( V_36 -> V_37 . V_23 != V_28 ) &&
( V_36 -> V_37 . V_23 != V_47 ) ) {
F_7 ( V_2 , L_3 ,
V_36 -> V_37 . V_23 ) ;
return - V_29 ;
}
if ( V_36 -> V_37 . V_23 == V_47 ) {
if ( ! V_14 -> V_33 . V_48 ( V_14 , V_43 ) ) {
F_7 ( V_2 , L_4 , V_43 ) ;
return - V_29 ;
}
if ( V_36 -> V_37 . V_44 != V_49 ) {
F_7 ( V_2 , L_5 ,
V_36 -> V_37 . V_44 ) ;
return - V_29 ;
}
}
F_12 ( & V_30 ,
V_36 -> V_40 . V_30 ) ;
F_13 ( V_14 , V_50 , V_2 ,
L_6 ,
V_30 , V_14 -> V_24 . V_41 ) ;
V_30 &= V_14 -> V_24 . V_41 ;
if ( ( V_36 -> V_37 . V_23 == V_28 ) && ! V_30 ) {
F_7 ( V_2 ,
L_7 ) ;
return - V_29 ;
}
V_19 = 0 ;
V_14 -> V_24 . V_23 = V_36 -> V_37 . V_23 ;
V_14 -> V_24 . V_43 = V_43 ;
V_14 -> V_24 . V_44 = V_36 -> V_37 . V_44 ;
V_14 -> V_24 . V_30 = V_30 ;
if ( V_36 -> V_37 . V_23 == V_28 )
V_14 -> V_24 . V_30 |= V_51 ;
else
V_14 -> V_24 . V_30 &= ~ V_51 ;
if ( F_8 ( V_2 ) )
V_19 = V_14 -> V_33 . V_34 ( V_14 ) ;
return V_19 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_54 * V_55 = & V_14 -> V_55 ;
F_15 ( V_53 -> V_56 , V_57 , sizeof( V_53 -> V_56 ) ) ;
F_15 ( V_53 -> V_58 , V_59 , sizeof( V_53 -> V_58 ) ) ;
F_15 ( V_53 -> V_60 , F_16 ( V_14 -> V_61 ) ,
sizeof( V_53 -> V_60 ) ) ;
snprintf ( V_53 -> V_62 , sizeof( V_53 -> V_62 ) , L_8 ,
F_17 ( V_55 -> V_58 , V_63 , V_64 ) ,
F_17 ( V_55 -> V_58 , V_63 , V_65 ) ,
F_17 ( V_55 -> V_58 , V_63 , V_66 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return V_14 -> V_67 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_68 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_14 -> V_67 = V_68 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_71 = V_14 -> V_72 ;
V_70 -> V_73 = V_14 -> V_74 ;
V_70 -> V_75 = V_14 -> V_76 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_77 * V_16 = & V_14 -> V_16 ;
unsigned int V_74 , V_78 , V_72 ;
unsigned int V_76 ;
if ( ( V_70 -> V_79 ) ||
( V_70 -> V_80 ) ||
( V_70 -> V_81 ) ||
( V_70 -> V_82 ) ||
( V_70 -> V_83 ) ||
( V_70 -> V_84 ) ||
( V_70 -> V_85 ) ||
( V_70 -> V_86 ) ||
( V_70 -> V_87 ) ||
( V_70 -> V_88 ) ||
( V_70 -> V_89 ) ||
( V_70 -> V_90 ) ||
( V_70 -> V_91 ) ||
( V_70 -> V_92 ) ||
( V_70 -> V_93 ) ||
( V_70 -> V_94 ) ||
( V_70 -> V_95 ) ||
( V_70 -> V_96 ) ||
( V_70 -> V_97 ) ) {
F_7 ( V_2 , L_9 ) ;
return - V_20 ;
}
V_78 = V_16 -> V_98 ( V_14 , V_70 -> V_71 ) ;
V_72 = V_70 -> V_71 ;
V_74 = V_70 -> V_73 ;
if ( V_72 && ! V_78 )
V_78 = 1 ;
if ( V_78 > V_99 ) {
F_7 ( V_2 , L_10 ,
V_16 -> V_100 ( V_14 , V_99 ) ) ;
return - V_29 ;
}
if ( V_74 > V_14 -> V_101 ) {
F_7 ( V_2 , L_11 ,
V_14 -> V_101 ) ;
return - V_29 ;
}
V_76 = V_70 -> V_75 ;
if ( V_76 > V_14 -> V_102 ) {
F_7 ( V_2 , L_12 ,
V_14 -> V_102 ) ;
return - V_29 ;
}
V_14 -> V_78 = V_78 ;
V_14 -> V_72 = V_72 ;
V_14 -> V_74 = V_74 ;
V_16 -> V_103 ( V_14 ) ;
V_14 -> V_76 = V_76 ;
V_16 -> V_104 ( V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_105 * V_106 , T_1 * V_107 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
switch ( V_106 -> V_36 ) {
case V_108 :
V_106 -> V_4 = V_14 -> V_109 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return sizeof( V_14 -> V_110 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return F_25 ( V_14 -> V_111 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_112 , T_2 * V_113 ,
T_2 * V_114 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
unsigned int V_5 ;
if ( V_112 ) {
for ( V_5 = 0 ; V_5 < F_25 ( V_14 -> V_111 ) ; V_5 ++ )
V_112 [ V_5 ] = F_17 ( V_14 -> V_111 [ V_5 ] ,
V_115 , V_116 ) ;
}
if ( V_113 )
memcpy ( V_113 , V_14 -> V_110 , sizeof( V_14 -> V_110 ) ) ;
if ( V_114 )
* V_114 = V_117 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const T_1 * V_112 ,
const T_2 * V_113 , const T_2 V_114 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_77 * V_16 = & V_14 -> V_16 ;
unsigned int V_19 ;
if ( V_114 != V_118 && V_114 != V_117 ) {
F_7 ( V_2 , L_13 ) ;
return - V_20 ;
}
if ( V_112 ) {
V_19 = V_16 -> V_119 ( V_14 , V_112 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_113 ) {
V_19 = V_16 -> V_120 ( V_14 , V_113 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_122 -> V_123 = V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 ;
if ( V_14 -> V_130 )
V_122 -> V_131 = F_29 ( V_14 -> V_130 ) ;
else
V_122 -> V_131 = - 1 ;
V_122 -> V_132 = ( 1 << V_133 ) | ( 1 << V_134 ) ;
V_122 -> V_135 = ( 1 << V_136 ) |
( 1 << V_137 ) |
( 1 << V_138 ) |
( 1 << V_139 ) |
( 1 << V_140 ) |
( 1 << V_141 ) |
( 1 << V_142 ) |
( 1 << V_143 ) |
( 1 << V_144 ) |
( 1 << V_145 ) |
( 1 << V_146 ) ;
return 0 ;
}
const struct V_147 * F_30 ( void )
{
return & V_148 ;
}
