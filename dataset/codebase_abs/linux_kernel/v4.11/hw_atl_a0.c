static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memcpy ( V_4 , & V_5 , sizeof( * V_4 ) ) ;
return 0 ;
}
static struct V_1 * F_2 ( struct V_6 * V_7 ,
unsigned int V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_2 = NULL ;
V_2 = F_3 ( sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
goto V_13;
V_2 -> V_14 . V_7 = V_7 ;
V_2 -> V_14 . V_15 = 0x10U ;
V_13:
return (struct V_1 * ) V_2 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
F_7 ( V_2 , 1U ) ;
F_8 ( V_2 , 0U ) ;
F_9 ( V_2 , 0U ) ;
F_10 ( V_2 , 0U ) ;
F_11 () ;
F_12 ( V_2 , 1 ) ;
F_13 ( F_14 ( V_2 ) == 0 , 1000U , 10U ) ;
if ( V_16 < 0 )
goto V_13;
F_15 ( V_2 , 0U ) ;
F_16 ( V_2 , 1U ) ;
F_13 ( F_17 ( V_2 ) == 0 , 1000U , 10U ) ;
if ( V_16 < 0 )
goto V_13;
F_18 ( V_2 , V_17 , 0x0U ) ;
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_18 = 0U ;
T_1 V_19 = 0U ;
unsigned int V_20 = 0U ;
bool V_21 = false ;
F_21 ( V_2 , 0x0U ) ;
F_22 ( V_2 , 0xA ) ;
F_23 ( V_2 , 0U ) ;
F_24 ( V_2 , 0U ) ;
F_25 ( V_2 , 0U ) ;
F_26 ( V_2 , 0xFFF , 0U ) ;
F_27 ( V_2 , 0x64 , 0U ) ;
F_28 ( V_2 , 0x50 , 0U ) ;
F_29 ( V_2 , 0x1E , 0U ) ;
V_19 = V_22 ;
F_30 ( V_2 , V_19 , V_18 ) ;
F_31 ( V_2 ,
( V_19 * ( 1024 / 32U ) * 66U ) /
100U , V_18 ) ;
F_32 ( V_2 ,
( V_19 * ( 1024 / 32U ) * 50U ) /
100U , V_18 ) ;
V_18 = 0 ;
V_21 = ( V_23 & V_2 -> V_24 -> V_25 ) ;
V_19 = V_26 ;
F_33 ( V_2 , V_19 , V_18 ) ;
F_34 ( V_2 ,
( V_19 *
( 1024U / 32U ) * 66U ) /
100U , V_18 ) ;
F_35 ( V_2 ,
( V_19 *
( 1024U / 32U ) * 50U ) /
100U , V_18 ) ;
F_36 ( V_2 , V_21 ? 1U : 0U , V_18 ) ;
for ( V_20 = 8U ; V_20 -- ; )
F_37 ( V_2 , V_20 , 0U ) ;
return F_19 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = NULL ;
int V_16 = 0 ;
unsigned int V_31 = 0U ;
unsigned int V_32 = 0U ;
V_30 = V_2 -> V_24 ;
for ( V_31 = 10 , V_32 = 0U ; V_31 -- ; ++ V_32 ) {
T_1 V_33 = V_30 -> V_34 ?
F_39 ( V_28 -> V_35 [ V_31 ] ) : 0U ;
F_40 ( V_2 , V_33 ) ;
F_41 ( V_2 , V_32 ) ;
F_42 ( V_2 , 1U ) ;
F_13 ( F_43 ( V_2 ) == 0 , 1000U , 10U ) ;
if ( V_16 < 0 )
goto V_13;
}
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
T_2 * V_36 = V_28 -> V_36 ;
T_1 V_31 = 0U ;
T_1 V_37 = F_45 ( 1U , V_2 -> V_24 -> V_37 ) ;
int V_16 = 0 ;
T_3 V_38 [ ( V_39 *
V_40 / 16U ) ] ;
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
for ( V_31 = V_39 ; V_31 -- ; ) {
( * ( T_1 * ) ( V_38 + ( ( V_31 * 3U ) / 16U ) ) ) |=
( ( V_36 [ V_31 ] % V_37 ) <<
( ( V_31 * 3U ) & 0xFU ) ) ;
}
for ( V_31 = F_46 ( V_38 ) ; V_31 -- ; ) {
F_47 ( V_2 , V_38 [ V_31 ] ) ;
F_48 ( V_2 , V_31 ) ;
F_49 ( V_2 , 1U ) ;
F_13 ( F_50 ( V_2 ) == 0 , 1000U , 10U ) ;
if ( V_16 < 0 )
goto V_13;
}
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_29 * V_24 )
{
int V_16 = 0 ;
F_52 ( V_2 , 1 ) ;
F_53 ( V_2 , 1 ) ;
if ( V_16 < 0 )
goto V_13;
F_54 ( V_2 , 1 ) ;
F_55 ( V_2 , 1 ) ;
if ( V_16 < 0 )
goto V_13;
F_56 ( V_2 , 0xFFFFFFFFU ) ;
if ( V_16 < 0 )
goto V_13;
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 , 0x0FF6U ) ;
F_59 ( V_2 , 0x0FF6U ) ;
F_60 ( V_2 , 0x0F7FU ) ;
F_61 ( V_2 , 1U ) ;
F_62 ( V_2 , 0x00007040U , F_63 ( V_41 ) ?
0x00010000U : 0x00000000U ) ;
F_64 ( V_2 , 0U ) ;
F_65 ( V_2 , 0U ) ;
F_66 ( V_2 , 1U ) ;
return F_19 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_24 ;
int V_31 ;
F_68 ( V_2 , 1U ) ;
F_69 ( V_2 , 1U ) ;
F_70 ( V_2 , V_30 -> V_34 ?
0xB3333333U : 0x00000000U ) ;
for ( V_31 = V_42 ; V_31 -- ; ) {
F_71 ( V_2 , ( V_31 == 0U ) ? 1U : 0U , V_31 ) ;
F_72 ( V_2 , 1U , V_31 ) ;
}
F_73 ( V_2 , 0x00000000U ) ;
F_74 ( V_2 , 0x00010FFFU , 0U ) ;
F_75 ( V_2 , 0x88A8U ) ;
F_76 ( V_2 , 0x8100U ) ;
F_77 ( V_2 , 1 ) ;
F_78 ( V_2 , 1U ) ;
F_79 ( V_2 , 1U ) ;
F_80 ( V_2 , 0xFFFFU & ( ~ 0U / 256U ) ) ;
F_81 ( V_2 , 0U ) ;
F_82 ( V_2 , 0U ) ;
return F_19 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 , T_2 * V_43 )
{
int V_16 = 0 ;
unsigned int V_44 = 0U ;
unsigned int V_45 = 0U ;
if ( ! V_43 ) {
V_16 = - V_46 ;
goto V_13;
}
V_44 = ( V_43 [ 0 ] << 8 ) | ( V_43 [ 1 ] ) ;
V_45 = ( V_43 [ 2 ] << 24 ) | ( V_43 [ 3 ] << 16 ) |
( V_43 [ 4 ] << 8 ) | V_43 [ 5 ] ;
F_71 ( V_2 , 0U , V_47 ) ;
F_84 ( V_2 , V_45 , V_47 ) ;
F_85 ( V_2 , V_44 , V_47 ) ;
F_71 ( V_2 , 1U , V_47 ) ;
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_29 * V_24 ,
T_2 * V_43 )
{
static T_1 V_48 [ 4 ] [ 2 ] = {
{ 0x20000000U , 0x20000000U } ,
{ 0x20000080U , 0x20000080U } ,
{ 0x20000021U , 0x20000025U } ,
{ 0x20000022U , 0x20000026U }
} ;
int V_16 = 0 ;
V_2 -> V_24 = V_24 ;
F_87 ( V_2 ,
& V_49 -> V_50 ) ;
F_57 ( V_2 ) ;
F_67 ( V_2 ) ;
F_83 ( V_2 , V_43 ) ;
F_18 ( V_2 , V_51 , V_24 -> V_52 ) ;
F_88 ( V_2 , 0x800000b8U ) ;
F_88 ( V_2 , 0x000000b8U ) ;
F_20 ( V_2 ) ;
F_44 ( V_2 , & V_24 -> V_53 ) ;
F_38 ( V_2 , & V_24 -> V_53 ) ;
V_16 = F_19 ( V_2 ) ;
if ( V_16 < 0 )
goto V_13;
F_89 ( V_2 ,
V_48 [ V_24 -> V_54 ]
[ ( V_24 -> V_55 > 1U ) ?
1 : 0 ] ) ;
F_90 ( V_2 , V_24 -> V_4 -> V_56 ) ;
F_91 ( V_2 ,
( ( V_57 << 0x18 ) | ( 1U << 0x1F ) ) |
( ( V_57 << 0x10 ) | ( 1U << 0x17 ) ) |
( ( V_57 << 8 ) | ( 1U << 0xF ) ) |
( ( V_57 ) | ( 1U << 0x7 ) ) , 0U ) ;
F_51 ( V_2 , V_24 ) ;
V_13:
return V_16 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
F_93 ( V_2 , 1 , V_59 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
F_95 ( V_2 , 1 , V_59 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
F_97 ( V_2 , 1 ) ;
F_98 ( V_2 , 1 ) ;
return F_19 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
F_100 ( V_2 , V_59 -> V_61 , V_59 -> V_60 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
unsigned int V_62 )
{
struct V_63 * V_64 = NULL ;
struct V_65 * V_66 = NULL ;
unsigned int V_67 = 0U ;
unsigned int V_68 = 0U ;
unsigned int V_69 = 0U ;
bool V_70 = false ;
V_64 = & V_59 -> V_71 [ V_59 -> V_61 ] ;
V_68 = ( V_64 -> V_72 && V_64 -> V_73 ) ? V_64 -> V_74 : V_64 -> V_75 ;
for ( V_69 = 0 ; V_69 < V_62 ; V_69 ++ ) {
V_66 = (struct V_65 * ) & V_59 -> V_76 [ V_59 -> V_61 *
V_77 ] ;
V_66 -> V_78 = 0 ;
V_66 -> V_79 = 0 ;
V_66 -> V_80 = 0 ;
V_64 = & V_59 -> V_71 [ V_59 -> V_61 ] ;
if ( V_64 -> V_81 ) {
V_66 -> V_78 |= ( V_64 -> V_82 << 31 ) |
( V_64 -> V_83 << 24 ) |
V_84 |
V_85 ;
V_66 -> V_79 |= ( V_64 -> V_86 << 16 ) |
( V_64 -> V_87 << 8 ) |
( V_64 -> V_82 >> 1 ) ;
V_68 -= ( V_64 -> V_87 +
V_64 -> V_82 +
V_64 -> V_83 ) ;
V_70 = true ;
if ( V_64 -> V_88 )
V_66 -> V_78 |= V_89 ;
} else {
V_67 = V_64 -> V_74 ;
V_66 -> V_80 = V_64 -> V_90 ;
V_66 -> V_78 |= ( V_91 &
( ( T_1 ) V_67 << 4 ) ) ;
V_66 -> V_78 |= V_92 ;
V_66 -> V_79 |= V_93 & ( V_68 << 14 ) ;
if ( V_70 ) {
V_66 -> V_78 |= V_94 ;
V_66 -> V_79 |= V_95 ;
}
if ( V_64 -> V_96 )
V_66 -> V_78 |= V_97 ;
if ( V_64 -> V_98 || V_64 -> V_99 )
V_66 -> V_78 |= V_100 ;
if ( F_102 ( V_64 -> V_72 ) ) {
V_66 -> V_78 |= V_101 ;
V_66 -> V_78 |= V_102 ;
V_70 = false ;
}
}
V_59 -> V_61 = F_103 ( V_59 , V_59 -> V_61 ) ;
}
F_99 ( V_2 , V_59 ) ;
return F_19 ( V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_58 * V_103 ,
struct V_104 * V_105 )
{
T_1 V_106 = ( T_1 ) V_103 -> V_107 ;
T_1 V_108 = ( T_1 ) ( ( ( V_109 ) V_103 -> V_107 ) >> 32 ) ;
F_95 ( V_2 , false , V_103 -> V_60 ) ;
F_105 ( V_2 , 0U , V_103 -> V_60 ) ;
F_106 ( V_2 , V_106 ,
V_103 -> V_60 ) ;
F_107 ( V_2 ,
V_108 , V_103 -> V_60 ) ;
F_108 ( V_2 , V_103 -> V_110 / 8U , V_103 -> V_60 ) ;
F_109 ( V_2 ,
V_111 / 1024U ,
V_103 -> V_60 ) ;
F_110 ( V_2 , 0U , V_103 -> V_60 ) ;
F_105 ( V_2 , 0U , V_103 -> V_60 ) ;
F_111 ( V_2 , 0U , V_103 -> V_60 ) ;
F_112 ( V_2 , V_105 -> V_112 , V_103 -> V_60 ) ;
F_113 ( V_2 , true , V_103 -> V_60 ) ;
F_114 ( V_2 , V_105 -> V_113 , V_103 -> V_60 ) ;
F_115 ( V_2 , 0U , V_103 -> V_60 ) ;
F_116 ( V_2 , 0U , V_103 -> V_60 ) ;
F_117 ( V_2 , 0U , V_103 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_58 * V_103 ,
struct V_104 * V_105 )
{
T_1 V_114 = ( T_1 ) V_103 -> V_107 ;
T_1 V_115 = ( T_1 ) ( ( ( V_109 ) V_103 -> V_107 ) >> 32 ) ;
F_119 ( V_2 , V_114 ,
V_103 -> V_60 ) ;
F_120 ( V_2 , V_115 ,
V_103 -> V_60 ) ;
F_121 ( V_2 , V_103 -> V_110 / 8U , V_103 -> V_60 ) ;
F_99 ( V_2 , V_103 ) ;
F_122 ( V_2 , 0U , V_103 -> V_60 ) ;
F_123 ( V_2 , V_105 -> V_112 , V_103 -> V_60 ) ;
F_124 ( V_2 , true , V_103 -> V_60 ) ;
F_125 ( V_2 , V_105 -> V_113 , V_103 -> V_60 ) ;
F_126 ( V_2 , 0U , V_103 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
unsigned int V_116 )
{
for (; V_116 != V_59 -> V_61 ;
V_116 = F_103 ( V_59 , V_116 ) ) {
struct V_117 * V_118 =
(struct V_117 * ) & V_59 -> V_76 [ V_116 *
V_119 ] ;
struct V_63 * V_64 = & V_59 -> V_71 [ V_116 ] ;
V_118 -> V_80 = V_64 -> V_90 ;
V_118 -> V_120 = 0U ;
}
F_128 ( V_2 , V_116 , V_59 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
int V_16 = 0 ;
unsigned int V_121 = F_130 ( V_2 , V_59 -> V_60 ) ;
if ( F_131 ( & V_2 -> V_122 . V_123 , V_124 ) ) {
V_16 = - V_125 ;
goto V_13;
}
V_59 -> V_126 = V_121 ;
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_127 * V_128 = F_133 ( V_59 -> V_129 ) ;
for (; V_59 -> V_126 != V_59 -> V_61 ;
V_59 -> V_126 = F_103 ( V_59 , V_59 -> V_126 ) ) {
struct V_63 * V_64 = NULL ;
struct V_130 * V_131 = (struct V_130 * )
& V_59 -> V_76 [ V_59 -> V_126 * V_119 ] ;
unsigned int V_132 = 1U ;
unsigned int V_133 = 0U ;
unsigned int V_134 = 0U ;
if ( ! ( V_131 -> V_135 & 0x5U ) ) {
if ( ( 1U << 4 ) &
F_134 ( V_2 , V_59 -> V_60 ) ) {
F_95 ( V_2 , false , V_59 -> V_60 ) ;
F_135 ( V_2 , true , V_59 -> V_60 ) ;
F_135 ( V_2 , false , V_59 -> V_60 ) ;
F_95 ( V_2 , true , V_59 -> V_60 ) ;
}
if ( V_59 -> V_126 ||
( F_136 ( V_2 , V_59 -> V_60 ) < 2U ) ) {
break;
} else if ( ! ( V_131 -> V_135 & 0x1U ) ) {
struct V_130 * V_136 =
(struct V_130 * )
( & V_59 -> V_76 [ ( 1U ) *
V_119 ] ) ;
if ( ( V_136 -> V_135 & 0x1U ) ) {
V_131 -> V_68 = 1514U ;
V_131 -> V_135 = 3U ;
} else {
break;
}
}
}
V_64 = & V_59 -> V_71 [ V_59 -> V_126 ] ;
if ( 0x3U != ( V_131 -> V_135 & 0x3U ) )
V_131 -> V_135 |= 4 ;
V_132 = ( 0x0000001CU & V_131 -> V_135 ) ;
V_133 = ( V_131 -> type ) & ( 0x3U << 19 ) ;
V_134 = 0xFFU & ( V_131 -> type >> 4 ) ;
if ( V_133 ) {
if ( 0x0U == ( V_134 & 0x3U ) )
V_64 -> V_96 = ( V_132 & 0x08U ) ? 0 : 1 ;
if ( 0x4U == ( V_134 & 0x1CU ) )
V_64 -> V_98 = ( V_132 & 0x10U ) ? 0 : 1 ;
else if ( 0x0U == ( V_134 & 0x1CU ) )
V_64 -> V_99 = ( V_132 & 0x10U ) ? 0 : 1 ;
}
V_132 &= ~ 0x18U ;
V_132 &= ~ 0x04U ;
F_137 ( V_128 , V_64 -> V_90 , V_64 -> V_74 , V_137 ) ;
if ( V_132 || V_131 -> type & 0x1000U ) {
V_64 -> V_138 = 1U ;
} else {
if ( V_2 -> V_24 -> V_34 ) {
T_3 V_139 = V_131 -> type & 0xFU ;
if ( V_139 && V_139 < 0x8U ) {
V_64 -> V_140 = ( V_139 == 0x4 ||
V_139 == 0x5 ) ;
V_64 -> V_141 = V_131 -> V_141 ;
}
}
if ( V_142 & V_131 -> V_135 ) {
V_64 -> V_74 = V_131 -> V_68 %
V_111 ;
V_64 -> V_74 = V_64 -> V_74 ?
V_64 -> V_74 : V_111 ;
V_64 -> V_143 = 0U ;
V_64 -> V_72 = 1U ;
} else {
V_64 -> V_143 = F_103 ( V_59 ,
V_59 -> V_126 ) ;
++ V_59 -> V_144 . V_145 . V_146 ;
}
}
}
return F_19 ( V_2 ) ;
}
static int F_138 ( struct V_1 * V_2 , V_109 V_147 )
{
F_139 ( V_2 , F_140 ( V_147 ) |
( 1U << V_57 ) ) ;
return F_19 ( V_2 ) ;
}
static int F_141 ( struct V_1 * V_2 , V_109 V_147 )
{
F_142 ( V_2 , F_140 ( V_147 ) ) ;
F_143 ( V_2 , F_140 ( V_147 ) ) ;
if ( ( 1U << 16 ) & F_144 ( V_2 ) )
F_145 ( & V_49 -> V_148 ) ;
return F_19 ( V_2 ) ;
}
static int F_146 ( struct V_1 * V_2 , V_109 * V_147 )
{
* V_147 = F_147 ( V_2 ) ;
return F_19 ( V_2 ) ;
}
static int F_148 ( struct V_1 * V_2 ,
unsigned int V_149 )
{
unsigned int V_31 = 0U ;
F_149 ( V_2 , F_150 ( V_150 ) ) ;
F_151 ( V_2 , F_150 ( V_151 ) , 0 ) ;
F_152 ( V_2 , F_150 ( V_152 ) ) ;
V_2 -> V_24 -> V_153 =
F_150 ( V_151 ) ;
for ( V_31 = V_154 ; V_31 < V_42 ; ++ V_31 )
F_71 ( V_2 ,
( V_2 -> V_24 -> V_153 &&
( V_31 <= V_2 -> V_24 -> V_155 ) ) ?
1U : 0U , V_31 ) ;
return F_19 ( V_2 ) ;
}
static int F_153 ( struct V_1 * V_2 ,
T_2 V_156
[ V_157 ]
[ V_158 ] ,
T_1 V_159 )
{
int V_16 = 0 ;
if ( V_159 > ( V_42 - V_154 ) ) {
V_16 = V_160 ;
goto V_13;
}
for ( V_2 -> V_24 -> V_155 = 0U ;
V_2 -> V_24 -> V_155 < V_159 ;
++ V_2 -> V_24 -> V_155 ) {
T_1 V_31 = V_2 -> V_24 -> V_155 ;
T_1 V_44 = ( V_156 [ V_31 ] [ 0 ] << 8 ) | ( V_156 [ V_31 ] [ 1 ] ) ;
T_1 V_45 = ( V_156 [ V_31 ] [ 2 ] << 24 ) | ( V_156 [ V_31 ] [ 3 ] << 16 ) |
( V_156 [ V_31 ] [ 4 ] << 8 ) | V_156 [ V_31 ] [ 5 ] ;
F_71 ( V_2 , 0U , V_154 + V_31 ) ;
F_84 ( V_2 ,
V_45 , V_154 + V_31 ) ;
F_85 ( V_2 ,
V_44 , V_154 + V_31 ) ;
F_71 ( V_2 ,
( V_2 -> V_24 -> V_153 ) ,
V_154 + V_31 ) ;
}
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_154 ( struct V_1 * V_2 ,
bool V_161 )
{
unsigned int V_31 = 0U ;
if ( V_161 && V_2 -> V_24 -> V_162 ) {
if ( V_2 -> V_24 -> V_162 != 0xFFFFU ) {
T_1 V_163 = ( V_2 -> V_24 -> V_162 >> 1 ) ;
V_163 = F_155 ( V_164 , V_163 ) ;
V_49 -> V_165 = 0x80000000U |
( V_163 << 0x10 ) ;
} else {
T_1 V_166 = 0xFFFFU & F_156 ( V_2 , 0x00002A00U ) ;
if ( V_166 < V_2 -> V_167 . V_168 ) {
V_49 -> V_165 = 0U ;
} else {
static unsigned int V_169 [] = {
0x01CU ,
0x039U ,
0x039U ,
0x073U ,
0x120U ,
0x1FFU ,
} ;
unsigned int V_170 =
F_157 (
V_2 -> V_167 . V_168 ) ;
V_49 -> V_165 =
0x80000000U |
( V_169 [ V_170 ] << 0x10U ) ;
}
F_62 ( V_2 , 0x00002A00U , 0x40000000U ) ;
F_62 ( V_2 , 0x00002A00U , 0x8D000000U ) ;
}
} else {
V_49 -> V_165 = 0U ;
}
for ( V_31 = V_171 ; V_31 -- ; )
F_158 ( V_2 , V_49 -> V_165 , V_31 ) ;
return F_19 ( V_2 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
F_141 ( V_2 , V_172 ) ;
return F_19 ( V_2 ) ;
}
static int F_160 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
F_93 ( V_2 , 0U , V_59 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
F_95 ( V_2 , 0U , V_59 -> V_60 ) ;
return F_19 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 , T_1 V_173 )
{
int V_16 = 0 ;
V_16 = F_163 ( V_2 , V_173 , V_51 ) ;
if ( V_16 < 0 )
goto V_13;
V_13:
return V_16 ;
}
struct V_9 * F_164 ( struct V_174 * V_175 )
{
bool V_176 = ( V_175 -> V_177 == V_178 ) ;
bool V_179 = ( ( V_175 -> V_127 == V_180 ) ||
( V_175 -> V_127 == V_181 ) ||
( V_175 -> V_127 == V_182 ) ||
( V_175 -> V_127 == V_183 ) ||
( V_175 -> V_127 == V_184 ) ) ;
bool V_185 = ( V_175 -> V_186 == 1U ) ;
return ( V_176 && V_179 && V_185 ) ? & V_187 : NULL ;
}
