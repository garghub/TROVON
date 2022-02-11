static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 ,
V_7 . V_6 ) -> V_3 ;
}
static int F_4 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 V_12 ;
T_1 V_13 [ 3 ] ;
int V_14 ;
if ( V_10 -> V_15 == V_16 )
return 0 ;
V_13 [ 0 ] = V_17 >> 8 ;
V_13 [ 1 ] = V_17 & 0xff ;
V_13 [ 2 ] = V_10 -> V_15 << 1 ;
V_12 . V_15 = V_16 ;
V_12 . V_18 = 0 ;
V_12 . V_13 = V_13 ;
V_12 . V_19 = sizeof( V_13 ) ;
V_14 = F_5 ( V_10 -> V_20 , & V_12 , 1 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_10 -> V_21 , L_1 , V_22 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_8 , T_2 V_23 , T_1 V_24 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 V_12 ;
T_1 V_13 [ 3 ] ;
int V_14 ;
V_13 [ 0 ] = V_23 >> 8 ;
V_13 [ 1 ] = V_23 & 0xff ;
V_13 [ 2 ] = V_24 ;
V_12 . V_15 = V_10 -> V_15 ;
V_12 . V_18 = V_10 -> V_18 ;
V_12 . V_13 = V_13 ;
V_12 . V_19 = sizeof( V_13 ) ;
V_14 = F_5 ( V_10 -> V_20 , & V_12 , 1 ) ;
if ( V_14 < 0 ) {
F_8 ( & V_8 -> V_3 , L_2 ,
V_22 , V_23 , V_24 ) ;
return V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_8 , T_2 V_23 , T_1 * V_24 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 V_12 [ 2 ] ;
T_1 V_13 [ 2 ] ;
int V_14 ;
V_13 [ 0 ] = V_23 >> 8 ;
V_13 [ 1 ] = V_23 & 0xff ;
V_12 [ 0 ] . V_15 = V_10 -> V_15 ;
V_12 [ 0 ] . V_18 = V_10 -> V_18 ;
V_12 [ 0 ] . V_13 = V_13 ;
V_12 [ 0 ] . V_19 = sizeof( V_13 ) ;
V_12 [ 1 ] . V_15 = V_10 -> V_15 ;
V_12 [ 1 ] . V_18 = V_10 -> V_18 | V_25 ;
V_12 [ 1 ] . V_13 = V_13 ;
V_12 [ 1 ] . V_19 = 1 ;
V_14 = F_5 ( V_10 -> V_20 , V_12 , 2 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_24 = V_13 [ 0 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_8 , T_2 V_23 , T_2 * V_24 )
{
T_1 V_26 , V_27 ;
int V_14 ;
V_14 = F_9 ( V_8 , V_23 , & V_26 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_9 ( V_8 , V_23 + 1 , & V_27 ) ;
if ( V_14 )
return V_14 ;
* V_24 = ( ( T_2 ) V_26 << 8 ) | ( T_2 ) V_27 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_8 , T_2 V_23 , T_2 V_24 )
{
int V_14 ;
V_14 = F_7 ( V_8 , V_23 , V_24 >> 8 ) ;
if ( V_14 )
return V_14 ;
return F_7 ( V_8 , V_23 + 1 , V_24 & 0xff ) ;
}
static int F_12 ( struct V_1 * V_8 , T_2 V_23 ,
T_1 V_28 , T_1 V_24 )
{
T_1 V_29 ;
int V_14 ;
V_14 = F_9 ( V_8 , V_23 , & V_29 ) ;
if ( V_14 )
return V_14 ;
V_29 &= ~ V_28 ;
V_24 &= V_28 ;
V_24 |= V_29 ;
return F_7 ( V_8 , V_23 , V_24 ) ;
}
static int F_13 ( struct V_1 * V_8 ,
const struct V_30 * V_31 )
{
const struct V_32 * V_33 = V_31 -> V_34 ;
unsigned int V_35 ;
T_3 V_36 ;
T_2 V_37 ;
T_1 V_28 , V_24 ;
int V_14 = 0 ;
for ( V_35 = 0 ; V_35 < V_31 -> V_38 ; ++ V_35 , ++ V_33 ) {
V_36 = V_33 -> V_36 ;
V_37 = V_33 -> V_37 ;
V_24 = V_33 -> V_24 ;
V_28 = V_33 -> V_28 ;
if ( V_28 )
V_14 = F_12 ( V_8 , V_37 , V_28 , V_24 ) ;
else
V_14 = F_7 ( V_8 , V_37 , V_24 ) ;
if ( V_14 )
break;
if ( V_36 )
F_14 ( 1000 * V_36 , 1000 * V_36 + 100 ) ;
}
return V_14 ;
}
static int F_15 ( struct V_1 * V_8 )
{
int exp , V_14 ;
T_1 V_39 ;
V_14 = F_9 ( V_8 , V_40 , & V_39 ) ;
if ( V_14 )
return V_14 ;
exp = ( ( int ) V_39 & 0x0f ) << 16 ;
V_14 = F_9 ( V_8 , V_41 , & V_39 ) ;
if ( V_14 )
return V_14 ;
exp |= ( ( int ) V_39 << 8 ) ;
V_14 = F_9 ( V_8 , V_42 , & V_39 ) ;
if ( V_14 )
return V_14 ;
exp |= ( int ) V_39 ;
return exp >> 4 ;
}
static int F_16 ( struct V_1 * V_8 , T_3 V_43 )
{
int V_14 ;
V_43 <<= 4 ;
V_14 = F_7 ( V_8 ,
V_42 ,
V_43 & 0xff ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 ,
V_41 ,
( V_43 >> 8 ) & 0xff ) ;
if ( V_14 )
return V_14 ;
return F_7 ( V_8 ,
V_40 ,
( V_43 >> 16 ) & 0x0f ) ;
}
static int F_17 ( struct V_1 * V_8 )
{
T_2 V_44 ;
int V_14 ;
V_14 = F_10 ( V_8 , V_45 , & V_44 ) ;
if ( V_14 )
return V_14 ;
return V_44 & 0x3ff ;
}
static int F_18 ( struct V_1 * V_8 , bool V_46 )
{
int V_14 ;
V_14 = F_12 ( V_8 , V_47 , F_19 ( 5 ) ,
V_46 ? 0 : F_19 ( 5 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_48 ,
V_46 ? 0x00 : 0x70 ) ;
if ( V_14 )
return V_14 ;
return F_7 ( V_8 , V_49 ,
V_46 ? 0x00 : 0x0f ) ;
}
static int F_20 ( struct V_1 * V_8 )
{
T_3 V_50 = V_8 -> V_51 / 10000 ;
T_3 V_52 , V_53 , V_54 , V_55 , V_56 ;
T_3 V_57 [] = { 1 , 2 , 4 , 8 } ;
T_3 V_58 = 1 , V_59 , V_60 ;
T_1 V_61 , V_62 ;
int V_14 ;
V_14 = F_9 ( V_8 , V_63 , & V_61 ) ;
if ( V_14 )
return V_14 ;
V_62 = V_61 & 0x0f ;
if ( V_62 == 8 || V_62 == 10 )
V_58 = V_62 / 2 ;
V_14 = F_9 ( V_8 , V_64 , & V_61 ) ;
if ( V_14 )
return V_14 ;
V_55 = V_61 >> 4 ;
if ( V_55 == 0 )
V_55 = 16 ;
V_14 = F_9 ( V_8 , V_65 , & V_61 ) ;
if ( V_14 )
return V_14 ;
V_52 = V_61 ;
V_14 = F_9 ( V_8 , V_66 , & V_61 ) ;
if ( V_14 )
return V_14 ;
V_53 = V_61 & 0x0f ;
V_56 = ( ( V_61 >> 4 ) & 0x01 ) + 1 ;
V_14 = F_9 ( V_8 , V_67 , & V_61 ) ;
if ( V_14 )
return V_14 ;
V_62 = V_61 & 0x03 ;
V_59 = V_57 [ V_62 ] ;
if ( ! V_53 || ! V_55 || ! V_56 || ! V_58 )
return - V_68 ;
V_54 = V_50 * V_52 / V_53 ;
V_60 = V_54 / V_55 / V_56 * 2 / V_58 / V_59 ;
return V_60 ;
}
static int F_21 ( struct V_1 * V_8 )
{
T_1 V_31 ;
int V_14 ;
V_14 = F_9 ( V_8 , V_69 , & V_31 ) ;
if ( V_14 )
return V_14 ;
V_31 &= 0xfb ;
return F_7 ( V_8 , V_69 , V_31 ) ;
}
static int F_22 ( struct V_1 * V_8 )
{
T_2 V_70 ;
int V_14 ;
V_14 = F_10 ( V_8 , V_71 , & V_70 ) ;
if ( V_14 )
return V_14 ;
return V_70 ;
}
static int F_23 ( struct V_1 * V_8 )
{
T_2 V_72 ;
int V_14 ;
V_14 = F_10 ( V_8 , V_73 , & V_72 ) ;
if ( V_14 )
return V_14 ;
return V_72 ;
}
static int F_24 ( struct V_1 * V_8 , int V_72 )
{
return F_11 ( V_8 , V_73 , V_72 ) ;
}
static int F_25 ( struct V_1 * V_8 )
{
int V_14 , V_74 = 0 ;
T_1 V_39 , V_61 ;
V_14 = F_9 ( V_8 , V_75 , & V_39 ) ;
if ( V_14 )
return V_14 ;
if ( V_39 & 0x80 ) {
V_14 = F_9 ( V_8 , V_76 ,
& V_61 ) ;
if ( V_14 )
return V_14 ;
if ( V_61 & 0x04 ) {
V_74 = 50 ;
} else {
V_74 = 60 ;
}
} else {
V_14 = F_9 ( V_8 , V_77 ,
& V_61 ) ;
if ( V_14 )
return V_14 ;
if ( V_61 & 0x01 ) {
V_74 = 50 ;
} else {
}
}
return V_74 ;
}
static int F_26 ( struct V_1 * V_8 )
{
T_3 V_78 , V_79 , V_80 , V_81 , V_82 ;
int V_14 ;
V_14 = F_20 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
return - V_68 ;
V_8 -> V_83 = V_14 ;
V_14 = F_22 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
return - V_68 ;
V_8 -> V_84 = V_14 ;
V_14 = F_23 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_82 = V_14 ;
V_78 = V_8 -> V_83 * 100 / V_8 -> V_84 * 100 / 120 ;
V_14 = F_11 ( V_8 , V_85 , V_78 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_78 )
return - V_68 ;
V_79 = ( int ) ( ( V_82 - 4 ) / V_78 ) ;
V_14 = F_7 ( V_8 , V_86 , V_79 ) ;
if ( V_14 )
return V_14 ;
V_80 = V_8 -> V_83 * 100 / V_8 -> V_84 ;
V_14 = F_11 ( V_8 , V_87 , V_80 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_80 )
return - V_68 ;
V_81 = ( int ) ( ( V_82 - 4 ) / V_80 ) ;
return F_7 ( V_8 , V_88 , V_81 ) ;
}
static int F_27 ( struct V_1 * V_8 , int V_89 )
{
T_3 V_90 , V_91 ;
int V_14 ;
V_8 -> V_92 = V_89 * 23 / 25 ;
V_8 -> V_93 = V_89 * 27 / 25 ;
V_90 = V_8 -> V_93 << 1 ;
if ( V_90 > 255 )
V_90 = 255 ;
V_91 = V_8 -> V_92 >> 1 ;
V_14 = F_7 ( V_8 , V_94 , V_8 -> V_93 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_95 , V_8 -> V_92 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_96 , V_8 -> V_93 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_97 , V_8 -> V_92 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_98 , V_90 ) ;
if ( V_14 )
return V_14 ;
return F_7 ( V_8 , V_99 , V_91 ) ;
}
static int F_28 ( struct V_1 * V_8 )
{
T_1 V_39 ;
int V_14 ;
V_14 = F_9 ( V_8 , V_100 , & V_39 ) ;
if ( V_14 )
return V_14 ;
V_39 &= 0xfe ;
return V_39 ? 1 : 0 ;
}
static int F_29 ( struct V_1 * V_8 )
{
T_1 V_39 , V_101 = V_102 ;
int V_14 ;
if ( V_101 > 3 )
return - V_68 ;
V_14 = F_9 ( V_8 , V_103 , & V_39 ) ;
if ( V_14 )
return V_14 ;
V_39 &= ~ ( 3 << 6 ) ;
V_39 |= ( V_101 << 6 ) ;
return F_7 ( V_8 , V_103 , V_39 ) ;
}
static const struct V_30 *
F_30 ( struct V_1 * V_8 , enum V_104 V_105 ,
int V_106 , int V_107 , bool V_108 )
{
const struct V_30 * V_31 = NULL ;
int V_35 ;
for ( V_35 = V_109 - 1 ; V_35 >= 0 ; V_35 -- ) {
V_31 = & V_110 [ V_105 ] [ V_35 ] ;
if ( ! V_31 -> V_34 )
continue;
if ( ( V_108 && V_31 -> V_106 <= V_106 &&
V_31 -> V_107 <= V_107 ) ||
( ! V_108 && V_31 -> V_106 == V_106 &&
V_31 -> V_107 == V_107 ) )
break;
}
if ( V_108 && V_35 < 0 )
V_31 = & V_110 [ V_105 ] [ 0 ] ;
return V_31 ;
}
static int F_31 (
struct V_1 * V_8 , const struct V_30 * V_31 )
{
T_3 V_111 , V_112 ;
T_3 V_113 , V_114 ;
T_3 V_115 , V_116 , V_117 ;
T_3 V_74 , V_118 , V_119 ;
T_3 V_120 ;
T_1 V_121 ;
int V_14 ;
if ( V_31 -> V_34 == NULL )
return - V_68 ;
V_14 = F_15 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_111 = V_14 ;
V_14 = F_28 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 && V_31 -> V_122 != V_123 &&
V_31 -> V_122 != V_124 )
V_111 *= 2 ;
V_14 = F_17 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_112 = V_14 ;
V_14 = F_9 ( V_8 , V_125 , & V_121 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_21 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_13 ( V_8 , V_31 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_23 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_117 = V_14 ;
V_14 = F_22 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
return - V_68 ;
V_116 = V_14 ;
V_14 = F_20 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
return - V_68 ;
V_115 = V_14 ;
V_14 = F_25 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_74 = V_14 ;
if ( V_74 == 60 ) {
V_118 = V_115 * 100 / V_116 * 100 / 120 ;
} else {
V_118 = V_115 * 100 / V_116 ;
}
if ( ! V_8 -> V_83 ) {
V_14 = F_20 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
return - V_68 ;
V_8 -> V_83 = V_14 ;
}
if ( ! V_118 )
return - V_68 ;
V_119 = ( int ) ( ( V_117 - 4 ) / V_118 ) ;
if ( V_121 > V_8 -> V_92 && V_121 < V_8 -> V_93 ) {
V_120 =
V_112 * V_111 *
V_115 / V_8 -> V_83 *
V_8 -> V_84 / V_116 *
V_8 -> V_126 / V_121 ;
} else {
V_120 =
V_112 * V_111 *
V_115 / V_8 -> V_83 *
V_8 -> V_84 / V_116 ;
}
if ( V_120 < ( V_118 * 16 ) ) {
V_113 = V_120 / 16 ;
if ( V_113 < 1 )
V_113 = 1 ;
V_114 = V_120 / V_113 ;
if ( V_114 < 16 )
V_114 = 16 ;
} else {
if ( V_120 > ( V_118 * V_119 * 16 ) ) {
V_113 = V_118 * V_119 ;
if ( ! V_113 )
return - V_68 ;
V_114 = V_120 / V_113 ;
} else {
V_113 =
( ( int ) ( V_120 / 16 / V_118 ) )
* V_118 ;
if ( ! V_113 )
return - V_68 ;
V_114 = V_120 / V_113 ;
}
}
V_14 = F_32 ( V_8 -> V_7 . V_44 , V_114 ) ;
if ( V_14 )
return V_14 ;
if ( V_113 > ( V_117 - 4 ) ) {
V_117 = V_113 + 4 ;
V_14 = F_24 ( V_8 , V_117 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return F_32 ( V_8 -> V_7 . V_43 , V_113 ) ;
}
static int F_33 ( struct V_1 * V_8 ,
const struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_34 == NULL )
return - V_68 ;
V_14 = F_13 ( V_8 , V_31 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_32 ( V_8 -> V_7 . V_127 , 1 ) ;
if ( V_14 )
return V_14 ;
return F_32 ( V_8 -> V_7 . V_128 , V_129 ) ;
}
static int F_34 ( struct V_1 * V_8 ,
const struct V_30 * V_130 )
{
const struct V_30 * V_31 = V_8 -> V_131 ;
enum V_132 V_133 , V_134 ;
int V_14 ;
V_133 = V_31 -> V_133 ;
V_134 = V_130 -> V_133 ;
V_14 = F_32 ( V_8 -> V_7 . V_127 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_32 ( V_8 -> V_7 . V_128 , V_135 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_133 == V_136 && V_134 == V_137 ) ||
( V_133 == V_137 && V_134 == V_136 ) ) {
V_14 = F_31 ( V_8 , V_31 ) ;
} else {
V_14 = F_33 ( V_8 , V_31 ) ;
}
if ( V_14 < 0 )
return V_14 ;
V_14 = F_27 ( V_8 , V_8 -> V_126 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_25 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_26 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_29 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 -> V_138 = false ;
return 0 ;
}
static int F_35 ( struct V_1 * V_8 )
{
int V_14 ;
V_14 = F_13 ( V_8 , & V_139 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_34 ( V_8 , & V_139 ) ;
}
static void F_36 ( struct V_1 * V_8 , bool V_140 )
{
if ( V_8 -> V_141 )
F_37 ( V_8 -> V_141 , V_140 ? 0 : 1 ) ;
}
static void F_38 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_142 )
return;
F_37 ( V_8 -> V_142 , 0 ) ;
F_36 ( V_8 , false ) ;
F_14 ( 5000 , 10000 ) ;
F_36 ( V_8 , true ) ;
F_14 ( 5000 , 10000 ) ;
F_37 ( V_8 -> V_142 , 1 ) ;
F_14 ( 1000 , 2000 ) ;
F_37 ( V_8 -> V_142 , 0 ) ;
F_14 ( 5000 , 10000 ) ;
}
static int F_39 ( struct V_1 * V_8 , bool V_46 )
{
int V_14 = 0 ;
if ( V_46 ) {
F_40 ( V_8 -> V_143 ) ;
V_14 = F_41 ( V_144 ,
V_8 -> V_145 ) ;
if ( V_14 )
goto V_146;
F_38 ( V_8 ) ;
F_36 ( V_8 , true ) ;
V_14 = F_4 ( V_8 ) ;
if ( V_14 )
goto V_147;
V_14 = F_35 ( V_8 ) ;
if ( V_14 )
goto V_147;
V_14 = F_18 ( V_8 , true ) ;
if ( V_14 )
goto V_147;
F_14 ( 1000 , 2000 ) ;
V_14 = F_18 ( V_8 , false ) ;
if ( V_14 )
goto V_147;
return 0 ;
}
V_147:
F_36 ( V_8 , false ) ;
F_42 ( V_144 , V_8 -> V_145 ) ;
V_146:
F_43 ( V_8 -> V_143 ) ;
return V_14 ;
}
static int F_44 ( struct V_2 * V_3 , int V_46 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_14 = 0 ;
F_45 ( & V_8 -> V_148 ) ;
if ( V_8 -> V_149 == ! V_46 ) {
V_14 = F_39 ( V_8 , ! ! V_46 ) ;
if ( V_14 )
goto V_150;
}
V_8 -> V_149 += V_46 ? 1 : - 1 ;
F_46 ( V_8 -> V_149 < 0 ) ;
V_150:
F_47 ( & V_8 -> V_148 ) ;
if ( V_46 && ! V_14 && V_8 -> V_149 == 1 ) {
V_14 = F_48 ( & V_8 -> V_7 . V_6 ) ;
}
return V_14 ;
}
static int F_49 ( struct V_1 * V_8 ,
struct V_151 * V_152 ,
T_3 V_106 , T_3 V_107 )
{
const struct V_30 * V_31 ;
T_3 V_153 , V_154 , V_155 ;
int V_14 ;
V_153 = V_156 [ V_157 ] ;
V_154 = V_156 [ V_158 ] ;
if ( V_152 -> V_159 == 0 ) {
V_152 -> V_160 = V_154 ;
V_152 -> V_159 = 1 ;
return V_158 ;
}
V_155 = F_50 ( V_152 -> V_160 , V_152 -> V_159 ) ;
V_152 -> V_159 = 1 ;
if ( V_155 > V_154 )
V_152 -> V_160 = V_154 ;
else if ( V_155 < V_153 )
V_152 -> V_160 = V_153 ;
else if ( 2 * V_155 >= 2 * V_153 + ( V_154 - V_153 ) )
V_152 -> V_160 = V_154 ;
else
V_152 -> V_160 = V_153 ;
V_14 = ( V_152 -> V_160 == V_153 ) ? V_157 : V_158 ;
V_31 = F_30 ( V_8 , V_14 , V_106 , V_107 , false ) ;
return V_31 ? V_14 : - V_68 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_163 * V_164 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_165 * V_166 ;
if ( V_164 -> V_167 != 0 )
return - V_68 ;
F_45 ( & V_8 -> V_148 ) ;
if ( V_164 -> V_168 == V_169 )
V_166 = F_52 ( & V_8 -> V_3 , V_162 ,
V_164 -> V_167 ) ;
else
V_166 = & V_8 -> V_166 ;
V_164 -> V_164 = * V_166 ;
F_47 ( & V_8 -> V_148 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_165 * V_166 ,
enum V_104 V_105 ,
const struct V_30 * * V_170 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_30 * V_31 ;
V_31 = F_30 ( V_8 , V_105 , V_166 -> V_106 , V_166 -> V_107 , true ) ;
if ( ! V_31 )
return - V_68 ;
V_166 -> V_106 = V_31 -> V_106 ;
V_166 -> V_107 = V_31 -> V_107 ;
V_166 -> V_171 = V_8 -> V_166 . V_171 ;
if ( V_170 )
* V_170 = V_31 ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_163 * V_164 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_30 * V_170 ;
int V_14 ;
if ( V_164 -> V_167 != 0 )
return - V_68 ;
F_45 ( & V_8 -> V_148 ) ;
if ( V_8 -> V_172 ) {
V_14 = - V_173 ;
goto V_150;
}
V_14 = F_53 ( V_3 , & V_164 -> V_164 ,
V_8 -> V_174 , & V_170 ) ;
if ( V_14 )
goto V_150;
if ( V_164 -> V_168 == V_169 ) {
struct V_165 * V_166 =
F_52 ( V_3 , V_162 , 0 ) ;
* V_166 = V_164 -> V_164 ;
goto V_150;
}
V_8 -> V_131 = V_170 ;
V_8 -> V_166 = V_164 -> V_164 ;
V_8 -> V_138 = true ;
V_150:
F_47 ( & V_8 -> V_148 ) ;
return V_14 ;
}
static int F_55 ( struct V_1 * V_8 , int V_175 )
{
int V_14 ;
if ( V_175 ) {
V_14 = F_12 ( V_8 , V_176 ,
F_19 ( 0 ) , F_19 ( 0 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_11 ( V_8 , V_177 , V_175 ) ;
} else {
V_14 = F_12 ( V_8 , V_176 , F_19 ( 0 ) , 0 ) ;
}
return V_14 ;
}
static int F_56 ( struct V_1 * V_8 , int V_175 )
{
int V_14 ;
if ( V_175 ) {
V_14 = F_12 ( V_8 , V_176 ,
F_19 ( 2 ) , F_19 ( 2 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_178 ,
V_175 & 0xff ) ;
} else {
V_14 = F_12 ( V_8 , V_176 , F_19 ( 2 ) , 0 ) ;
}
return V_14 ;
}
static int F_57 ( struct V_1 * V_8 , int V_175 )
{
int V_14 ;
if ( V_175 ) {
V_14 = F_12 ( V_8 , V_176 ,
F_19 ( 1 ) , F_19 ( 1 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_179 ,
V_175 & 0xff ) ;
if ( V_14 )
return V_14 ;
V_14 = F_7 ( V_8 , V_180 ,
V_175 & 0xff ) ;
} else {
V_14 = F_12 ( V_8 , V_176 , F_19 ( 1 ) , 0 ) ;
}
return V_14 ;
}
static int F_58 ( struct V_1 * V_8 , int V_181 )
{
int V_14 ;
V_14 = F_12 ( V_8 , V_182 ,
F_19 ( 0 ) , V_181 ? 0 : 1 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_181 ) {
T_2 V_183 = ( T_2 ) V_8 -> V_7 . V_184 -> V_24 ;
T_2 V_185 = ( T_2 ) V_8 -> V_7 . V_186 -> V_24 ;
V_14 = F_11 ( V_8 , V_187 , V_183 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_11 ( V_8 , V_188 , V_185 ) ;
}
return V_14 ;
}
static int F_59 ( struct V_1 * V_8 , int exp )
{
struct V_189 * V_7 = & V_8 -> V_7 ;
bool V_190 = ( exp == V_129 ) ;
int V_14 = 0 ;
if ( V_7 -> V_128 -> V_191 ) {
V_14 = F_12 ( V_8 , V_192 ,
F_19 ( 0 ) , V_190 ? 0 : F_19 ( 0 ) ) ;
if ( V_14 )
return V_14 ;
}
if ( ! V_190 && V_7 -> V_43 -> V_191 ) {
T_2 V_193 ;
V_14 = F_10 ( V_8 , V_194 ,
& V_193 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_23 ( V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_193 += V_14 ;
if ( V_7 -> V_43 -> V_24 < V_193 )
V_14 = F_16 ( V_8 , V_7 -> V_43 -> V_24 ) ;
}
return V_14 ;
}
static int F_60 ( struct V_1 * V_8 , int V_127 )
{
struct V_189 * V_7 = & V_8 -> V_7 ;
int V_14 = 0 ;
if ( V_7 -> V_127 -> V_191 ) {
V_14 = F_12 ( V_8 , V_192 ,
F_19 ( 1 ) , V_7 -> V_127 -> V_24 ? 0 : F_19 ( 1 ) ) ;
if ( V_14 )
return V_14 ;
}
if ( ! V_127 && V_7 -> V_44 -> V_191 ) {
T_2 V_44 = ( T_2 ) V_7 -> V_44 -> V_24 ;
V_14 = F_11 ( V_8 , V_45 ,
V_44 & 0x3ff ) ;
}
return V_14 ;
}
static int F_61 ( struct V_1 * V_8 , int V_175 )
{
return F_12 ( V_8 , V_195 ,
0xa4 , V_175 ? 0xa4 : 0 ) ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_24 ;
switch ( V_5 -> V_122 ) {
case V_196 :
if ( ! V_5 -> V_24 )
return 0 ;
V_24 = F_17 ( V_8 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 -> V_7 . V_44 -> V_24 = V_24 ;
break;
case V_197 :
if ( V_5 -> V_24 == V_135 )
return 0 ;
V_24 = F_15 ( V_8 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 -> V_7 . V_43 -> V_24 = V_24 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_14 ;
if ( V_8 -> V_149 == 0 )
return 0 ;
switch ( V_5 -> V_122 ) {
case V_196 :
V_14 = F_60 ( V_8 , V_5 -> V_24 ) ;
break;
case V_197 :
V_14 = F_59 ( V_8 , V_5 -> V_24 ) ;
break;
case V_198 :
V_14 = F_58 ( V_8 , V_5 -> V_24 ) ;
break;
case V_199 :
V_14 = F_55 ( V_8 , V_5 -> V_24 ) ;
break;
case V_200 :
V_14 = F_56 ( V_8 , V_5 -> V_24 ) ;
break;
case V_201 :
V_14 = F_57 ( V_8 , V_5 -> V_24 ) ;
break;
case V_202 :
V_14 = F_61 ( V_8 , V_5 -> V_24 ) ;
break;
default:
V_14 = - V_68 ;
break;
}
return V_14 ;
}
static int F_64 ( struct V_1 * V_8 )
{
const struct V_203 * V_204 = & V_205 ;
struct V_189 * V_7 = & V_8 -> V_7 ;
struct V_206 * V_207 = & V_7 -> V_6 ;
int V_14 ;
F_65 ( V_207 , 32 ) ;
V_207 -> V_148 = & V_8 -> V_148 ;
V_7 -> V_208 = F_66 ( V_207 , V_204 ,
V_198 ,
0 , 1 , 1 , 1 ) ;
V_7 -> V_186 = F_66 ( V_207 , V_204 , V_209 ,
0 , 4095 , 1 , 0 ) ;
V_7 -> V_184 = F_66 ( V_207 , V_204 , V_210 ,
0 , 4095 , 1 , 0 ) ;
V_7 -> V_128 = F_67 ( V_207 , V_204 ,
V_197 ,
V_135 , 0 ,
V_129 ) ;
V_7 -> V_43 = F_66 ( V_207 , V_204 , V_211 ,
0 , 65535 , 1 , 0 ) ;
V_7 -> V_127 = F_66 ( V_207 , V_204 , V_196 ,
0 , 1 , 1 , 1 ) ;
V_7 -> V_44 = F_66 ( V_207 , V_204 , V_212 ,
0 , 1023 , 1 , 0 ) ;
V_7 -> V_213 = F_66 ( V_207 , V_204 , V_201 ,
0 , 255 , 1 , 64 ) ;
V_7 -> V_214 = F_66 ( V_207 , V_204 , V_199 ,
0 , 359 , 1 , 0 ) ;
V_7 -> V_215 = F_66 ( V_207 , V_204 , V_200 ,
0 , 255 , 1 , 0 ) ;
V_7 -> V_216 =
F_68 ( V_207 , V_204 , V_202 ,
F_69 ( V_217 ) - 1 ,
0 , 0 , V_217 ) ;
if ( V_207 -> error ) {
V_14 = V_207 -> error ;
goto V_218;
}
V_7 -> V_44 -> V_18 |= V_219 ;
V_7 -> V_43 -> V_18 |= V_219 ;
F_70 ( 3 , & V_7 -> V_208 , 0 , false ) ;
F_70 ( 2 , & V_7 -> V_127 , 0 , true ) ;
F_70 ( 2 , & V_7 -> V_128 , 1 , true ) ;
V_8 -> V_3 . V_220 = V_207 ;
return 0 ;
V_218:
F_71 ( V_207 ) ;
return V_14 ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_221 * V_222 )
{
if ( V_222 -> V_167 != 0 )
return - V_68 ;
if ( V_222 -> V_223 >= V_109 )
return - V_68 ;
V_222 -> V_224 = V_222 -> V_225 =
V_110 [ 0 ] [ V_222 -> V_223 ] . V_106 ;
V_222 -> V_226 = V_222 -> V_227 =
V_110 [ 0 ] [ V_222 -> V_223 ] . V_107 ;
return 0 ;
}
static int F_73 (
struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_228 * V_229 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_151 V_230 ;
int V_14 ;
if ( V_229 -> V_167 != 0 )
return - V_68 ;
if ( V_229 -> V_223 >= V_231 )
return - V_68 ;
V_230 . V_159 = 1 ;
V_230 . V_160 = V_156 [ V_229 -> V_223 ] ;
V_14 = F_49 ( V_8 , & V_230 ,
V_229 -> V_106 , V_229 -> V_107 ) ;
if ( V_14 < 0 )
return - V_68 ;
V_229 -> V_232 = V_230 ;
return 0 ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_233 * V_152 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_45 ( & V_8 -> V_148 ) ;
V_152 -> V_232 = V_8 -> V_234 ;
F_47 ( & V_8 -> V_148 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_233 * V_152 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_30 * V_31 ;
int V_235 , V_14 = 0 ;
if ( V_152 -> V_167 != 0 )
return - V_68 ;
F_45 ( & V_8 -> V_148 ) ;
if ( V_8 -> V_172 ) {
V_14 = - V_173 ;
goto V_150;
}
V_31 = V_8 -> V_131 ;
V_235 = F_49 ( V_8 , & V_152 -> V_232 ,
V_31 -> V_106 , V_31 -> V_107 ) ;
if ( V_235 < 0 )
V_235 = V_157 ;
V_8 -> V_174 = V_235 ;
V_8 -> V_234 = V_152 -> V_232 ;
V_8 -> V_138 = true ;
V_150:
F_47 ( & V_8 -> V_148 ) ;
return V_14 ;
}
static int F_76 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_236 * V_171 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_171 -> V_167 != 0 )
return - V_68 ;
if ( V_171 -> V_223 != 0 )
return - V_68 ;
V_171 -> V_171 = V_8 -> V_166 . V_171 ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 , int V_140 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_14 = 0 ;
F_45 ( & V_8 -> V_148 ) ;
if ( V_8 -> V_172 == ! V_140 ) {
if ( V_140 && V_8 -> V_138 ) {
V_14 = F_34 ( V_8 , V_8 -> V_131 ) ;
if ( V_14 )
goto V_150;
}
V_14 = F_18 ( V_8 , V_140 ) ;
if ( ! V_14 )
V_8 -> V_172 = V_140 ;
}
V_150:
F_47 ( & V_8 -> V_148 ) ;
return V_14 ;
}
static int F_78 ( struct V_1 * V_8 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_144 ; V_35 ++ )
V_8 -> V_145 [ V_35 ] . V_237 = V_238 [ V_35 ] ;
return F_79 ( & V_8 -> V_9 -> V_21 ,
V_144 ,
V_8 -> V_145 ) ;
}
static int F_80 ( struct V_9 * V_10 ,
const struct V_239 * V_122 )
{
struct V_240 * V_21 = & V_10 -> V_21 ;
struct V_241 * V_242 ;
struct V_1 * V_8 ;
int V_14 ;
V_8 = F_81 ( V_21 , sizeof( * V_8 ) , V_243 ) ;
if ( ! V_8 )
return - V_244 ;
V_8 -> V_9 = V_10 ;
V_8 -> V_166 . V_171 = V_245 ;
V_8 -> V_166 . V_106 = 640 ;
V_8 -> V_166 . V_107 = 480 ;
V_8 -> V_166 . V_246 = V_247 ;
V_8 -> V_234 . V_159 = 1 ;
V_8 -> V_234 . V_160 = V_156 [ V_158 ] ;
V_8 -> V_174 = V_158 ;
V_8 -> V_131 =
& V_110 [ V_158 ] [ V_248 ] ;
V_8 -> V_138 = true ;
V_8 -> V_126 = 52 ;
V_242 = F_82 (
F_83 ( V_10 -> V_21 . V_249 ) , NULL ) ;
if ( ! V_242 ) {
F_6 ( V_21 , L_3 ) ;
return - V_68 ;
}
V_14 = F_84 ( V_242 , & V_8 -> V_250 ) ;
F_85 ( V_242 ) ;
if ( V_14 ) {
F_6 ( V_21 , L_4 ) ;
return V_14 ;
}
if ( V_8 -> V_250 . V_251 != V_252 ) {
F_6 ( V_21 , L_5 ) ;
return - V_68 ;
}
V_8 -> V_143 = F_86 ( V_21 , L_6 ) ;
if ( F_87 ( V_8 -> V_143 ) ) {
F_6 ( V_21 , L_7 ) ;
return F_88 ( V_8 -> V_143 ) ;
}
V_8 -> V_51 = F_89 ( V_8 -> V_143 ) ;
if ( V_8 -> V_51 < V_253 ||
V_8 -> V_51 > V_254 ) {
F_6 ( V_21 , L_8 ,
V_8 -> V_51 ) ;
return - V_68 ;
}
V_8 -> V_141 = F_90 ( V_21 , L_9 ,
V_255 ) ;
V_8 -> V_142 = F_90 ( V_21 , L_10 ,
V_255 ) ;
F_91 ( & V_8 -> V_3 , V_10 , & V_256 ) ;
V_8 -> V_3 . V_18 = V_257 ;
V_8 -> V_167 . V_18 = V_258 ;
V_8 -> V_3 . V_259 . V_260 = V_261 ;
V_14 = F_92 ( & V_8 -> V_3 . V_259 , 1 , & V_8 -> V_167 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_78 ( V_8 ) ;
if ( V_14 )
return V_14 ;
F_93 ( & V_8 -> V_148 ) ;
V_14 = F_64 ( V_8 ) ;
if ( V_14 )
goto V_262;
V_14 = F_94 ( & V_8 -> V_3 ) ;
if ( V_14 )
goto V_218;
return 0 ;
V_218:
F_71 ( & V_8 -> V_7 . V_6 ) ;
V_262:
F_95 ( & V_8 -> V_148 ) ;
F_96 ( & V_8 -> V_3 . V_259 ) ;
return V_14 ;
}
static int F_97 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_98 ( V_10 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_99 ( & V_8 -> V_3 ) ;
F_95 ( & V_8 -> V_148 ) ;
F_96 ( & V_8 -> V_3 . V_259 ) ;
F_71 ( & V_8 -> V_7 . V_6 ) ;
return 0 ;
}
