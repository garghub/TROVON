static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_3 ) {
case V_8 :
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
memcpy ( V_4 , V_10 [ V_7 ] . V_11 ,
V_12 ) ;
V_4 += V_12 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_13 ; V_7 ++ ) {
sprintf ( V_4 , L_1 , V_7 ) ;
V_4 += V_12 ;
sprintf ( V_4 , L_2 , V_7 ) ;
V_4 += V_12 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_14 ; V_7 ++ ) {
sprintf ( V_4 , L_3 , V_7 ) ;
V_4 += V_12 ;
sprintf ( V_4 , L_4 , V_7 ) ;
V_4 += V_12 ;
}
break;
}
}
static void F_3 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_17 ;
int V_7 ;
V_6 -> V_18 . V_19 ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_17 = ( T_2 * ) V_6 + V_10 [ V_7 ] . V_20 ;
* V_4 ++ = * ( T_3 * ) V_17 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_13 ; V_7 ++ ) {
* V_4 ++ = V_6 -> V_21 . V_22 [ V_7 ] ;
* V_4 ++ = V_6 -> V_21 . V_23 [ V_7 ] ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_14 ; V_7 ++ ) {
* V_4 ++ = V_6 -> V_21 . V_24 [ V_7 ] ;
* V_4 ++ = V_6 -> V_21 . V_25 [ V_7 ] ;
}
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
switch ( V_3 ) {
case V_8 :
V_26 = V_9 +
( V_6 -> V_13 * 2 ) +
( V_6 -> V_14 * 2 ) ;
break;
default:
V_26 = - V_27 ;
}
return V_26 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_29 -> V_30 = V_6 -> V_31 . V_32 ;
V_29 -> V_33 = V_6 -> V_31 . V_33 ;
V_29 -> V_34 = V_6 -> V_31 . V_34 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_6 -> V_31 . V_36 ;
int V_26 = 0 ;
if ( V_29 -> V_30 && ( V_6 -> V_31 . V_30 != V_37 ) ) {
F_7 ( V_2 ,
L_5 ) ;
return - V_38 ;
}
V_6 -> V_31 . V_32 = V_29 -> V_30 ;
V_6 -> V_31 . V_33 = V_29 -> V_33 ;
V_6 -> V_31 . V_34 = V_29 -> V_34 ;
F_8 ( V_36 , V_39 ) ;
F_8 ( V_36 , V_40 ) ;
if ( V_29 -> V_34 ) {
F_9 ( V_36 , V_39 ) ;
F_9 ( V_36 , V_40 ) ;
}
if ( V_29 -> V_33 ) {
if ( F_10 ( V_36 , V_40 ) )
F_8 ( V_36 , V_40 ) ;
else
F_9 ( V_36 , V_40 ) ;
}
if ( F_11 ( V_2 ) )
V_26 = V_6 -> V_41 . V_42 ( V_6 ) ;
return V_26 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_35 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_6 -> V_31 . V_36 ;
V_43 -> V_44 . V_45 = V_6 -> V_31 . V_46 ;
V_43 -> V_44 . V_30 = V_6 -> V_31 . V_30 ;
V_43 -> V_44 . V_47 = V_6 -> V_31 . V_47 ;
V_43 -> V_44 . V_48 = V_6 -> V_31 . V_48 ;
V_43 -> V_44 . V_49 = V_50 ;
F_13 ( V_43 , V_51 , V_36 , V_51 ) ;
F_13 ( V_43 , V_52 , V_36 , V_52 ) ;
F_13 ( V_43 , V_53 , V_36 , V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_35 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = & V_6 -> V_31 . V_36 ;
F_15 ( V_52 ) ;
T_1 V_47 ;
int V_26 ;
V_47 = V_43 -> V_44 . V_47 ;
if ( V_43 -> V_44 . V_45 != V_6 -> V_31 . V_46 ) {
F_7 ( V_2 , L_6 ,
V_43 -> V_44 . V_45 ) ;
return - V_38 ;
}
if ( ( V_43 -> V_44 . V_30 != V_37 ) &&
( V_43 -> V_44 . V_30 != V_54 ) ) {
F_7 ( V_2 , L_7 ,
V_43 -> V_44 . V_30 ) ;
return - V_38 ;
}
if ( V_43 -> V_44 . V_30 == V_54 ) {
if ( ! V_6 -> V_41 . V_55 ( V_6 , V_47 ) ) {
F_7 ( V_2 , L_8 , V_47 ) ;
return - V_38 ;
}
if ( V_43 -> V_44 . V_48 != V_56 ) {
F_7 ( V_2 , L_9 ,
V_43 -> V_44 . V_48 ) ;
return - V_38 ;
}
}
F_16 ( V_6 , V_57 , V_2 ,
L_10 ,
V_58 , V_43 -> V_59 . V_52 ,
V_58 , V_36 -> V_59 . V_51 ) ;
F_17 ( V_52 ,
V_43 -> V_59 . V_52 , V_36 -> V_59 . V_51 ,
V_58 ) ;
if ( ( V_43 -> V_44 . V_30 == V_37 ) &&
F_18 ( V_52 , V_58 ) ) {
F_7 ( V_2 ,
L_11 ) ;
return - V_38 ;
}
V_26 = 0 ;
V_6 -> V_31 . V_30 = V_43 -> V_44 . V_30 ;
V_6 -> V_31 . V_47 = V_47 ;
V_6 -> V_31 . V_48 = V_43 -> V_44 . V_48 ;
F_19 ( V_36 -> V_59 . V_52 , V_52 ,
V_58 ) ;
if ( V_43 -> V_44 . V_30 == V_37 )
F_9 ( V_36 , V_60 ) ;
else
F_8 ( V_36 , V_60 ) ;
if ( F_11 ( V_2 ) )
V_26 = V_6 -> V_41 . V_42 ( V_6 ) ;
return V_26 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_63 * V_64 = & V_6 -> V_64 ;
F_21 ( V_62 -> V_65 , V_66 , sizeof( V_62 -> V_65 ) ) ;
F_21 ( V_62 -> V_67 , V_68 , sizeof( V_62 -> V_67 ) ) ;
F_21 ( V_62 -> V_69 , F_22 ( V_6 -> V_70 ) ,
sizeof( V_62 -> V_69 ) ) ;
snprintf ( V_62 -> V_71 , sizeof( V_62 -> V_71 ) , L_12 ,
F_23 ( V_64 -> V_67 , V_72 , V_73 ) ,
F_23 ( V_64 -> V_67 , V_72 , V_74 ) ,
F_23 ( V_64 -> V_67 , V_72 , V_75 ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_76 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_76 = V_77 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_79 , 0 , sizeof( struct V_78 ) ) ;
V_79 -> V_80 = V_6 -> V_81 ;
V_79 -> V_82 = V_6 -> V_83 ;
V_79 -> V_84 = V_6 -> V_85 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_86 * V_18 = & V_6 -> V_18 ;
unsigned int V_83 , V_87 , V_81 ;
unsigned int V_85 ;
if ( ( V_79 -> V_88 ) ||
( V_79 -> V_89 ) ||
( V_79 -> V_90 ) ||
( V_79 -> V_91 ) ||
( V_79 -> V_92 ) ||
( V_79 -> V_93 ) ||
( V_79 -> V_94 ) ||
( V_79 -> V_95 ) ||
( V_79 -> V_96 ) ||
( V_79 -> V_97 ) ||
( V_79 -> V_98 ) ||
( V_79 -> V_99 ) ||
( V_79 -> V_100 ) ||
( V_79 -> V_101 ) ||
( V_79 -> V_102 ) ||
( V_79 -> V_103 ) ||
( V_79 -> V_104 ) ||
( V_79 -> V_105 ) ||
( V_79 -> V_106 ) ) {
F_7 ( V_2 , L_13 ) ;
return - V_27 ;
}
V_87 = V_18 -> V_107 ( V_6 , V_79 -> V_80 ) ;
V_81 = V_79 -> V_80 ;
V_83 = V_79 -> V_82 ;
if ( V_81 && ! V_87 )
V_87 = 1 ;
if ( V_87 > V_108 ) {
F_7 ( V_2 , L_14 ,
V_18 -> V_109 ( V_6 , V_108 ) ) ;
return - V_38 ;
}
if ( V_83 > V_6 -> V_110 ) {
F_7 ( V_2 , L_15 ,
V_6 -> V_110 ) ;
return - V_38 ;
}
V_85 = V_79 -> V_84 ;
if ( V_85 > V_6 -> V_111 ) {
F_7 ( V_2 , L_16 ,
V_6 -> V_111 ) ;
return - V_38 ;
}
V_6 -> V_87 = V_87 ;
V_6 -> V_81 = V_81 ;
V_6 -> V_83 = V_83 ;
V_18 -> V_112 ( V_6 ) ;
V_6 -> V_85 = V_85 ;
V_18 -> V_113 ( V_6 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_114 * V_115 , T_1 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_115 -> V_43 ) {
case V_117 :
V_115 -> V_4 = V_6 -> V_14 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sizeof( V_6 -> V_118 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_31 ( V_6 -> V_119 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_120 , T_2 * V_121 ,
T_2 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
if ( V_120 ) {
for ( V_7 = 0 ; V_7 < F_31 ( V_6 -> V_119 ) ; V_7 ++ )
V_120 [ V_7 ] = F_23 ( V_6 -> V_119 [ V_7 ] ,
V_123 , V_124 ) ;
}
if ( V_121 )
memcpy ( V_121 , V_6 -> V_118 , sizeof( V_6 -> V_118 ) ) ;
if ( V_122 )
* V_122 = V_125 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , const T_1 * V_120 ,
const T_2 * V_121 , const T_2 V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_86 * V_18 = & V_6 -> V_18 ;
unsigned int V_26 ;
if ( V_122 != V_126 && V_122 != V_125 ) {
F_7 ( V_2 , L_17 ) ;
return - V_27 ;
}
if ( V_120 ) {
V_26 = V_18 -> V_127 ( V_6 , V_120 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_121 ) {
V_26 = V_18 -> V_128 ( V_6 , V_121 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_130 -> V_131 = V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 ;
if ( V_6 -> V_138 )
V_130 -> V_139 = F_35 ( V_6 -> V_138 ) ;
else
V_130 -> V_139 = - 1 ;
V_130 -> V_140 = ( 1 << V_141 ) | ( 1 << V_142 ) ;
V_130 -> V_143 = ( 1 << V_144 ) |
( 1 << V_145 ) |
( 1 << V_146 ) |
( 1 << V_147 ) |
( 1 << V_148 ) |
( 1 << V_149 ) |
( 1 << V_150 ) |
( 1 << V_151 ) |
( 1 << V_152 ) |
( 1 << V_153 ) |
( 1 << V_154 ) ;
return 0 ;
}
const struct V_155 * F_36 ( void )
{
return & V_156 ;
}
