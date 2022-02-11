static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
F_2 ( L_1 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
memcpy ( V_4 , V_9 [ V_5 ] . V_10 ,
V_11 ) ;
V_4 += V_11 ;
}
break;
}
F_2 ( L_2 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
T_2 * V_16 ;
int V_5 ;
F_2 ( L_1 , V_6 ) ;
V_15 -> V_17 . V_18 ( V_15 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_16 = ( T_2 * ) V_15 + V_9 [ V_5 ] . V_19 ;
* V_4 ++ = * ( T_3 * ) V_16 ;
}
F_2 ( L_2 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_20 ;
F_2 ( L_1 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
V_20 = V_8 ;
break;
default:
V_20 = - V_21 ;
}
F_2 ( L_2 , V_6 ) ;
return V_20 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
F_2 ( L_3 ) ;
V_23 -> V_24 = V_15 -> V_25 ;
V_23 -> V_26 = V_15 -> V_26 ;
V_23 -> V_27 = V_15 -> V_27 ;
F_2 ( L_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
int V_20 = 0 ;
F_2 ( L_5 ) ;
F_2 ( L_6 ,
V_23 -> V_24 , V_23 -> V_26 , V_23 -> V_27 ) ;
V_15 -> V_25 = V_23 -> V_24 ;
if ( V_23 -> V_24 ) {
V_29 -> V_30 |= V_31 ;
V_29 -> V_30 |= V_32 ;
} else {
V_29 -> V_30 &= ~ V_31 ;
V_29 -> V_30 &= ~ V_32 ;
V_15 -> V_26 = V_23 -> V_26 ;
V_15 -> V_27 = V_23 -> V_27 ;
}
if ( F_8 ( V_2 ) )
V_20 = F_9 ( V_29 ) ;
F_2 ( L_7 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
int V_20 ;
F_2 ( L_8 ) ;
if ( ! V_15 -> V_29 )
return - V_35 ;
V_20 = F_11 ( V_15 -> V_29 , V_34 ) ;
F_2 ( L_9 ) ;
return V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
T_1 V_36 ;
int V_20 ;
F_2 ( L_10 ) ;
if ( ! V_15 -> V_29 )
return - V_35 ;
V_36 = F_13 ( V_34 ) ;
if ( V_34 -> V_37 != V_29 -> V_38 )
return - V_39 ;
if ( ( V_34 -> V_24 != V_40 ) &&
( V_34 -> V_24 != V_41 ) )
return - V_39 ;
if ( V_34 -> V_24 == V_41 ) {
switch ( V_36 ) {
case V_42 :
case V_43 :
case V_44 :
break;
default:
return - V_39 ;
}
if ( V_34 -> V_45 != V_46 )
return - V_39 ;
}
V_34 -> V_30 &= V_29 -> V_47 ;
if ( ( V_34 -> V_24 == V_40 ) && ! V_34 -> V_30 )
return - V_39 ;
V_20 = 0 ;
V_29 -> V_24 = V_34 -> V_24 ;
V_29 -> V_36 = V_36 ;
V_29 -> V_45 = V_34 -> V_45 ;
V_29 -> V_30 = V_34 -> V_30 ;
if ( V_34 -> V_24 == V_40 )
V_29 -> V_30 |= V_48 ;
else
V_29 -> V_30 &= ~ V_48 ;
if ( F_8 ( V_2 ) )
V_20 = F_9 ( V_29 ) ;
F_2 ( L_11 ) ;
return V_20 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_51 * V_52 = & V_15 -> V_52 ;
F_15 ( V_50 -> V_53 , V_54 , sizeof( V_50 -> V_53 ) ) ;
F_15 ( V_50 -> V_55 , V_56 , sizeof( V_50 -> V_55 ) ) ;
F_15 ( V_50 -> V_57 , F_16 ( V_15 -> V_58 ) ,
sizeof( V_50 -> V_57 ) ) ;
snprintf ( V_50 -> V_59 , sizeof( V_50 -> V_59 ) , L_12 ,
F_17 ( V_52 -> V_55 , V_60 , V_61 ) ,
F_17 ( V_52 -> V_55 , V_60 , V_62 ) ,
F_17 ( V_52 -> V_55 , V_60 , V_63 ) ) ;
V_50 -> V_64 = V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
F_2 ( L_13 ) ;
memset ( V_66 , 0 , sizeof( struct V_65 ) ) ;
V_66 -> V_67 = V_15 -> V_68 ;
V_66 -> V_69 = V_15 -> V_70 ;
V_66 -> V_71 = V_15 -> V_72 ;
F_2 ( L_14 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_73 * V_17 = & V_15 -> V_17 ;
unsigned int V_70 , V_74 , V_68 ;
unsigned int V_72 ;
F_2 ( L_15 ) ;
if ( ( V_66 -> V_75 ) ||
( V_66 -> V_76 ) ||
( V_66 -> V_77 ) ||
( V_66 -> V_78 ) ||
( V_66 -> V_79 ) ||
( V_66 -> V_80 ) ||
( V_66 -> V_81 ) ||
( V_66 -> V_82 ) ||
( V_66 -> V_83 ) ||
( V_66 -> V_84 ) ||
( V_66 -> V_85 ) ||
( V_66 -> V_86 ) ||
( V_66 -> V_87 ) ||
( V_66 -> V_88 ) ||
( V_66 -> V_89 ) ||
( V_66 -> V_90 ) ||
( V_66 -> V_91 ) ||
( V_66 -> V_92 ) ||
( V_66 -> V_93 ) )
return - V_21 ;
V_74 = V_17 -> V_94 ( V_15 , V_66 -> V_67 ) ;
V_68 = V_66 -> V_67 ;
V_70 = V_66 -> V_69 ;
if ( V_68 && ! V_74 )
V_74 = 1 ;
if ( V_74 > V_95 ) {
F_20 ( V_2 , L_16 ,
V_17 -> V_96 ( V_15 , V_95 ) ) ;
return - V_39 ;
}
if ( V_70 > V_15 -> V_97 ) {
F_20 ( V_2 , L_17 ,
V_15 -> V_97 ) ;
return - V_39 ;
}
V_72 = V_66 -> V_71 ;
if ( V_72 > V_15 -> V_98 ) {
F_20 ( V_2 , L_18 ,
V_15 -> V_98 ) ;
return - V_39 ;
}
V_15 -> V_74 = V_74 ;
V_15 -> V_68 = V_68 ;
V_15 -> V_70 = V_70 ;
V_17 -> V_99 ( V_15 ) ;
V_15 -> V_72 = V_72 ;
V_17 -> V_100 ( V_15 ) ;
F_2 ( L_19 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_101 * V_102 , T_1 * V_103 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
switch ( V_102 -> V_34 ) {
case V_104 :
V_102 -> V_4 = V_15 -> V_105 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
return sizeof( V_15 -> V_106 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
return F_24 ( V_15 -> V_107 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_108 , T_2 * V_109 ,
T_2 * V_110 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
unsigned int V_5 ;
if ( V_108 ) {
for ( V_5 = 0 ; V_5 < F_24 ( V_15 -> V_107 ) ; V_5 ++ )
V_108 [ V_5 ] = F_17 ( V_15 -> V_107 [ V_5 ] ,
V_111 , V_112 ) ;
}
if ( V_109 )
memcpy ( V_109 , V_15 -> V_106 , sizeof( V_15 -> V_106 ) ) ;
if ( V_110 )
* V_110 = V_113 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const T_1 * V_108 ,
const T_2 * V_109 , const T_2 V_110 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_73 * V_17 = & V_15 -> V_17 ;
unsigned int V_20 ;
if ( V_110 != V_114 && V_110 != V_113 )
return - V_21 ;
if ( V_108 ) {
V_20 = V_17 -> V_115 ( V_15 , V_108 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_109 ) {
V_20 = V_17 -> V_116 ( V_15 , V_109 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
V_118 -> V_119 = V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 ;
if ( V_15 -> V_126 )
V_118 -> V_127 = F_28 ( V_15 -> V_126 ) ;
else
V_118 -> V_127 = - 1 ;
V_118 -> V_128 = ( 1 << V_129 ) | ( 1 << V_130 ) ;
V_118 -> V_131 = ( 1 << V_132 ) |
( 1 << V_133 ) |
( 1 << V_134 ) |
( 1 << V_135 ) |
( 1 << V_136 ) |
( 1 << V_137 ) |
( 1 << V_138 ) |
( 1 << V_139 ) |
( 1 << V_140 ) |
( 1 << V_141 ) |
( 1 << V_142 ) ;
return 0 ;
}
struct V_143 * F_29 ( void )
{
return (struct V_143 * ) & V_144 ;
}
