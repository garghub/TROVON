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
unsigned int V_31 ;
F_52 ( V_2 , 1 ) ;
F_53 ( V_2 , 1 ) ;
F_54 ( V_2 , 1 ) ;
F_55 ( V_2 , 1 ) ;
F_56 ( V_2 , 0xFFFFFFFFU ) ;
{
unsigned int V_41 = ( 8U < V_42 ) ? 0x3U :
( ( 4U < V_42 ) ? 0x2U :
( ( 2U < V_42 ) ? 0x1U : 0x0 ) ) ;
for ( V_31 = 0 ; V_31 < V_43 ; V_31 ++ )
F_57 ( V_2 , V_41 , V_31 ) ;
F_58 ( V_2 , 0x61AU ) ;
F_59 ( V_2 , 0 ) ;
F_60 ( V_2 , 2 ) ;
F_61 ( V_2 , 1U ) ;
F_62 ( V_2 , 2U ) ;
F_63 ( V_2 , 0U ) ;
F_64 ( V_2 , 10U ) ;
F_65 ( V_2 , 1U ) ;
F_66 ( V_2 , V_24 -> V_44 ? 0xFFFFFFFFU : 0U ) ;
}
return F_19 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_68 ( V_2 , 0x0FF6U ) ;
F_69 ( V_2 , 0x0FF6U ) ;
F_70 ( V_2 , 0x0F7FU ) ;
F_71 ( V_2 , 1U ) ;
F_72 ( V_2 , 0x00007040U , F_73 ( V_45 ) ?
0x00010000U : 0x00000000U ) ;
F_74 ( V_2 , 0U ) ;
F_75 ( V_2 , 0U ) ;
F_76 ( V_2 , 1U ) ;
return F_19 ( V_2 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_24 ;
int V_31 ;
F_78 ( V_2 , 1U ) ;
F_79 ( V_2 , 1U ) ;
F_80 ( V_2 , V_30 -> V_34 ?
0xB3333333U : 0x00000000U ) ;
for ( V_31 = V_46 ; V_31 -- ; ) {
F_81 ( V_2 , ( V_31 == 0U ) ? 1U : 0U , V_31 ) ;
F_82 ( V_2 , 1U , V_31 ) ;
}
F_83 ( V_2 , 0x00000000U ) ;
F_84 ( V_2 , 0x00010FFFU , 0U ) ;
F_85 ( V_2 , 0x88A8U ) ;
F_86 ( V_2 , 0x8100U ) ;
if ( V_30 -> V_47 ) {
F_87 ( V_2 , 1U , 0U ) ;
F_88 ( V_2 , 0U , 0U ) ;
F_89 ( V_2 , 0U , 0U ) ;
F_90 ( V_2 , 1U ) ;
F_91 ( V_2 , 1U ) ;
F_87 ( V_2 , 1U , 1U ) ;
F_88 ( V_2 , V_30 -> V_47 , 0U ) ;
F_89 ( V_2 , 1U , 1U ) ;
} else {
F_92 ( V_2 , 1 ) ;
}
F_93 ( V_2 , 1U ) ;
F_72 ( V_2 , 0x00005040U ,
F_73 ( V_48 ) ? 0x000F0000U : 0x00000000U ) ;
F_94 ( V_2 , 1U ) ;
F_95 ( V_2 , 0xFFFFU & ( ~ 0U / 256U ) ) ;
F_96 ( V_2 , 0U ) ;
F_97 ( V_2 , 0U ) ;
return F_19 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 , T_2 * V_49 )
{
int V_16 = 0 ;
unsigned int V_50 = 0U ;
unsigned int V_51 = 0U ;
if ( ! V_49 ) {
V_16 = - V_52 ;
goto V_13;
}
V_50 = ( V_49 [ 0 ] << 8 ) | ( V_49 [ 1 ] ) ;
V_51 = ( V_49 [ 2 ] << 24 ) | ( V_49 [ 3 ] << 16 ) |
( V_49 [ 4 ] << 8 ) | V_49 [ 5 ] ;
F_81 ( V_2 , 0U , V_53 ) ;
F_99 ( V_2 , V_51 , V_53 ) ;
F_100 ( V_2 , V_50 , V_53 ) ;
F_81 ( V_2 , 1U , V_53 ) ;
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_29 * V_24 ,
T_2 * V_49 )
{
static T_1 V_54 [ 4 ] [ 2 ] = {
{ 0x20000000U , 0x20000000U } ,
{ 0x20000080U , 0x20000080U } ,
{ 0x20000021U , 0x20000025U } ,
{ 0x20000022U , 0x20000026U }
} ;
int V_16 = 0 ;
V_2 -> V_24 = V_24 ;
F_102 ( V_2 ,
& V_55 -> V_56 ) ;
F_67 ( V_2 ) ;
F_77 ( V_2 ) ;
F_98 ( V_2 , V_49 ) ;
F_18 ( V_2 , V_57 , V_24 -> V_58 ) ;
F_20 ( V_2 ) ;
F_44 ( V_2 , & V_24 -> V_59 ) ;
F_38 ( V_2 , & V_24 -> V_59 ) ;
V_16 = F_19 ( V_2 ) ;
if ( V_16 < 0 )
goto V_13;
F_103 ( V_2 ,
V_54 [ V_24 -> V_60 ]
[ ( V_24 -> V_61 > 1U ) ?
1 : 0 ] ) ;
F_104 ( V_2 , V_24 -> V_4 -> V_62 ) ;
F_105 ( V_2 ,
( ( V_63 << 0x18 ) | ( 1U << 0x1F ) ) |
( ( V_63 << 0x10 ) | ( 1U << 0x17 ) ) , 0U ) ;
F_51 ( V_2 , V_24 ) ;
V_13:
return V_16 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_107 ( V_2 , 1 , V_65 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_109 ( V_2 , 1 , V_65 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
F_111 ( V_2 , 1 ) ;
F_112 ( V_2 , 1 ) ;
return F_19 ( V_2 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_114 ( V_2 , V_65 -> V_67 , V_65 -> V_66 ) ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned int V_68 )
{
struct V_69 * V_70 = NULL ;
struct V_71 * V_72 = NULL ;
unsigned int V_73 = 0U ;
unsigned int V_74 = 0U ;
unsigned int V_75 = 0U ;
bool V_76 = false ;
V_70 = & V_65 -> V_77 [ V_65 -> V_67 ] ;
V_74 = ( V_70 -> V_78 && V_70 -> V_79 ) ? V_70 -> V_80 : V_70 -> V_81 ;
for ( V_75 = 0 ; V_75 < V_68 ; V_75 ++ ) {
V_72 = (struct V_71 * ) & V_65 -> V_82 [ V_65 -> V_67 *
V_83 ] ;
V_72 -> V_84 = 0 ;
V_72 -> V_85 = 0 ;
V_72 -> V_86 = 0 ;
V_70 = & V_65 -> V_77 [ V_65 -> V_67 ] ;
if ( V_70 -> V_87 ) {
V_72 -> V_84 |= ( V_70 -> V_88 << 31 ) |
( V_70 -> V_89 << 24 ) |
V_90 |
V_91 ;
V_72 -> V_85 |= ( V_70 -> V_92 << 16 ) |
( V_70 -> V_93 << 8 ) |
( V_70 -> V_88 >> 1 ) ;
V_74 -= ( V_70 -> V_93 +
V_70 -> V_88 +
V_70 -> V_89 ) ;
V_76 = true ;
if ( V_70 -> V_94 )
V_72 -> V_84 |= V_95 ;
} else {
V_73 = V_70 -> V_80 ;
V_72 -> V_86 = V_70 -> V_96 ;
V_72 -> V_84 |= ( V_97 &
( ( T_1 ) V_73 << 4 ) ) ;
V_72 -> V_84 |= V_98 ;
V_72 -> V_85 |= V_99 & ( V_74 << 14 ) ;
if ( V_76 ) {
V_72 -> V_84 |= V_100 ;
V_72 -> V_85 |= V_101 ;
}
if ( V_70 -> V_102 )
V_72 -> V_84 |= V_103 ;
if ( V_70 -> V_104 || V_70 -> V_105 )
V_72 -> V_84 |= V_106 ;
if ( F_116 ( V_70 -> V_78 ) ) {
V_72 -> V_84 |= V_107 ;
V_72 -> V_84 |= V_108 ;
V_76 = false ;
}
}
V_65 -> V_67 = F_117 ( V_65 , V_65 -> V_67 ) ;
}
F_113 ( V_2 , V_65 ) ;
return F_19 ( V_2 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_64 * V_109 ,
struct V_110 * V_111 )
{
T_1 V_112 = ( T_1 ) V_109 -> V_113 ;
T_1 V_114 = ( T_1 ) ( ( ( V_115 ) V_109 -> V_113 ) >> 32 ) ;
F_109 ( V_2 , false , V_109 -> V_66 ) ;
F_119 ( V_2 , 0U , V_109 -> V_66 ) ;
F_120 ( V_2 , V_112 ,
V_109 -> V_66 ) ;
F_121 ( V_2 ,
V_114 , V_109 -> V_66 ) ;
F_122 ( V_2 , V_109 -> V_116 / 8U , V_109 -> V_66 ) ;
F_123 ( V_2 ,
V_117 / 1024U ,
V_109 -> V_66 ) ;
F_124 ( V_2 , 0U , V_109 -> V_66 ) ;
F_119 ( V_2 , 0U , V_109 -> V_66 ) ;
F_125 ( V_2 , 0U , V_109 -> V_66 ) ;
F_126 ( V_2 , V_111 -> V_118 , V_109 -> V_66 ) ;
F_127 ( V_2 , true , V_109 -> V_66 ) ;
F_128 ( V_2 , V_111 -> V_119 , V_109 -> V_66 ) ;
F_129 ( V_2 , 0U , V_109 -> V_66 ) ;
F_130 ( V_2 , 0U , V_109 -> V_66 ) ;
F_131 ( V_2 , 0U , V_109 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_64 * V_109 ,
struct V_110 * V_111 )
{
T_1 V_120 = ( T_1 ) V_109 -> V_113 ;
T_1 V_121 = ( T_1 ) ( ( ( V_115 ) V_109 -> V_113 ) >> 32 ) ;
F_133 ( V_2 , V_120 ,
V_109 -> V_66 ) ;
F_134 ( V_2 , V_121 ,
V_109 -> V_66 ) ;
F_135 ( V_2 , V_109 -> V_116 / 8U , V_109 -> V_66 ) ;
F_113 ( V_2 , V_109 ) ;
F_136 ( V_2 , 0U , V_109 -> V_66 ) ;
F_137 ( V_2 , V_111 -> V_118 , V_109 -> V_66 ) ;
F_138 ( V_2 , true , V_109 -> V_66 ) ;
F_139 ( V_2 , V_111 -> V_119 , V_109 -> V_66 ) ;
F_140 ( V_2 , 0U , V_109 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned int V_122 )
{
for (; V_122 != V_65 -> V_67 ;
V_122 = F_117 ( V_65 , V_122 ) ) {
struct V_123 * V_124 =
(struct V_123 * ) & V_65 -> V_82 [ V_122 *
V_125 ] ;
struct V_69 * V_70 = & V_65 -> V_77 [ V_122 ] ;
V_124 -> V_86 = V_70 -> V_96 ;
V_124 -> V_126 = 0U ;
}
F_142 ( V_2 , V_122 , V_65 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
int V_16 = 0 ;
unsigned int V_127 = F_144 ( V_2 , V_65 -> V_66 ) ;
if ( F_145 ( & V_2 -> V_128 . V_129 , V_130 ) ) {
V_16 = - V_131 ;
goto V_13;
}
V_65 -> V_132 = V_127 ;
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_133 * V_134 = F_147 ( V_65 -> V_135 ) ;
for (; V_65 -> V_132 != V_65 -> V_67 ;
V_65 -> V_132 = F_117 ( V_65 , V_65 -> V_132 ) ) {
struct V_69 * V_70 = NULL ;
struct V_136 * V_137 = (struct V_136 * )
& V_65 -> V_82 [ V_65 -> V_132 * V_125 ] ;
unsigned int V_138 = 1U ;
unsigned int V_139 = 0U ;
unsigned int V_140 = 0U ;
if ( ! ( V_137 -> V_141 & 0x1U ) ) {
break;
}
V_70 = & V_65 -> V_77 [ V_65 -> V_132 ] ;
V_138 = ( 0x0000003CU & V_137 -> V_141 ) ;
V_139 = ( V_137 -> type ) & ( 0x3U << 19 ) ;
V_138 &= ~ 0x20U ;
V_140 = 0xFFU & ( V_137 -> type >> 4 ) ;
if ( V_139 ) {
if ( 0x0U == ( V_140 & 0x3U ) )
V_70 -> V_102 = ( V_138 & 0x08U ) ? 0U : 1U ;
if ( 0x4U == ( V_140 & 0x1CU ) )
V_70 -> V_104 = V_70 -> V_142 ? 0U : 1U ;
else if ( 0x0U == ( V_140 & 0x1CU ) )
V_70 -> V_105 = V_70 -> V_142 ? 0U : 1U ;
}
V_138 &= ~ 0x18U ;
F_148 ( V_134 , V_70 -> V_96 , V_70 -> V_80 , V_143 ) ;
if ( V_138 || V_137 -> type & 0x1000U ) {
V_70 -> V_144 = 1U ;
} else {
if ( V_2 -> V_24 -> V_34 ) {
T_3 V_145 = V_137 -> type & 0xFU ;
if ( V_145 && V_145 < 0x8U ) {
V_70 -> V_146 = ( V_145 == 0x4 ||
V_145 == 0x5 ) ;
V_70 -> V_147 = V_137 -> V_147 ;
}
}
if ( V_148 & V_137 -> V_141 ) {
V_70 -> V_80 = V_137 -> V_74 %
V_117 ;
V_70 -> V_80 = V_70 -> V_80 ?
V_70 -> V_80 : V_117 ;
V_70 -> V_149 = 0U ;
V_70 -> V_78 = 1U ;
} else {
if ( V_150 &
V_137 -> V_141 ) {
V_70 -> V_149 = V_137 -> V_151 ;
++ V_65 -> V_152 . V_153 . V_154 ;
} else {
V_70 -> V_149 =
F_117 ( V_65 ,
V_65 -> V_132 ) ;
++ V_65 -> V_152 . V_153 . V_155 ;
}
}
}
}
return F_19 ( V_2 ) ;
}
static int F_149 ( struct V_1 * V_2 , V_115 V_156 )
{
F_150 ( V_2 , F_151 ( V_156 ) ) ;
return F_19 ( V_2 ) ;
}
static int F_152 ( struct V_1 * V_2 , V_115 V_156 )
{
F_153 ( V_2 , F_151 ( V_156 ) ) ;
F_154 ( V_2 , F_151 ( V_156 ) ) ;
F_155 ( & V_55 -> V_157 ) ;
return F_19 ( V_2 ) ;
}
static int F_156 ( struct V_1 * V_2 , V_115 * V_156 )
{
* V_156 = F_157 ( V_2 ) ;
return F_19 ( V_2 ) ;
}
static int F_158 ( struct V_1 * V_2 ,
unsigned int V_158 )
{
unsigned int V_31 = 0U ;
F_159 ( V_2 , F_160 ( V_159 ) ) ;
F_161 ( V_2 ,
F_160 ( V_160 ) , 0 ) ;
F_162 ( V_2 ,
F_160 ( V_161 ) ) ;
F_163 ( V_2 , F_160 ( V_162 ) ) ;
V_2 -> V_24 -> V_163 = F_160 ( V_160 ) ;
for ( V_31 = V_164 ; V_31 < V_46 ; ++ V_31 )
F_81 ( V_2 ,
( V_2 -> V_24 -> V_163 &&
( V_31 <= V_2 -> V_24 -> V_165 ) ) ?
1U : 0U , V_31 ) ;
return F_19 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
T_2 V_166
[ V_167 ]
[ V_168 ] ,
T_1 V_169 )
{
int V_16 = 0 ;
if ( V_169 > ( V_46 - V_164 ) ) {
V_16 = - V_170 ;
goto V_13;
}
for ( V_2 -> V_24 -> V_165 = 0U ;
V_2 -> V_24 -> V_165 < V_169 ;
++ V_2 -> V_24 -> V_165 ) {
T_1 V_31 = V_2 -> V_24 -> V_165 ;
T_1 V_50 = ( V_166 [ V_31 ] [ 0 ] << 8 ) | ( V_166 [ V_31 ] [ 1 ] ) ;
T_1 V_51 = ( V_166 [ V_31 ] [ 2 ] << 24 ) | ( V_166 [ V_31 ] [ 3 ] << 16 ) |
( V_166 [ V_31 ] [ 4 ] << 8 ) | V_166 [ V_31 ] [ 5 ] ;
F_81 ( V_2 , 0U , V_164 + V_31 ) ;
F_99 ( V_2 ,
V_51 , V_164 + V_31 ) ;
F_100 ( V_2 ,
V_50 , V_164 + V_31 ) ;
F_81 ( V_2 ,
( V_2 -> V_24 -> V_163 ) ,
V_164 + V_31 ) ;
}
V_16 = F_19 ( V_2 ) ;
V_13:
return V_16 ;
}
static int F_165 ( struct V_1 * V_2 ,
bool V_171 )
{
unsigned int V_31 = 0U ;
if ( V_171 && V_2 -> V_24 -> V_172 ) {
F_71 ( V_2 , 0U ) ;
F_166 ( V_2 , 1U ) ;
F_93 ( V_2 , 0U ) ;
F_167 ( V_2 , 1U ) ;
V_55 -> V_173 = 2U ;
V_55 -> V_174 = 2U ;
if ( V_2 -> V_24 -> V_172 != 0xFFFFU ) {
unsigned int V_175 = V_2 -> V_24 -> V_172 / 2U ;
unsigned int V_176 = V_2 -> V_24 -> V_172 / 32U ;
V_175 = F_168 ( 0x1FFU , V_175 ) ;
V_176 = F_168 ( 0xFFU , V_176 ) ;
V_55 -> V_173 |= V_176 << 0x8U ;
V_55 -> V_173 |= V_175 << 0x10U ;
V_55 -> V_174 |= V_176 << 0x8U ;
V_55 -> V_174 |= V_175 << 0x10U ;
} else {
static unsigned int V_177 [] [ 2 ] = {
{ 0xffU , 0xffU } ,
{ 0xffU , 0x1ffU } ,
{ 0xffU , 0x1ffU } ,
{ 0xffU , 0x1ffU } ,
{ 0xffU , 0x1ffU } ,
{ 0xffU , 0x1ffU } ,
} ;
static unsigned int V_178 [] [ 2 ] = {
{ 0x6U , 0x38U } ,
{ 0xCU , 0x70U } ,
{ 0xCU , 0x70U } ,
{ 0x18U , 0xE0U } ,
{ 0x30U , 0x80U } ,
{ 0x4U , 0x50U } ,
} ;
unsigned int V_179 =
F_169 (
V_2 -> V_180 . V_181 ) ;
V_55 -> V_173 |=
V_177 [ V_179 ]
[ 0 ] << 0x8U ;
V_55 -> V_173 |=
V_177 [ V_179 ]
[ 1 ] << 0x10U ;
V_55 -> V_174 |=
V_178 [ V_179 ]
[ 0 ] << 0x8U ;
V_55 -> V_174 |=
V_178 [ V_179 ]
[ 1 ] << 0x10U ;
}
} else {
F_71 ( V_2 , 1U ) ;
F_166 ( V_2 , 0U ) ;
F_93 ( V_2 , 1U ) ;
F_167 ( V_2 , 0U ) ;
V_55 -> V_173 = 0U ;
V_55 -> V_174 = 0U ;
}
for ( V_31 = V_43 ; V_31 -- ; ) {
F_170 ( V_2 ,
V_55 -> V_173 , V_31 ) ;
F_171 ( V_2 ,
V_55 -> V_174 , V_31 ) ;
}
return F_19 ( V_2 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
F_152 ( V_2 , V_182 ) ;
return F_19 ( V_2 ) ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_107 ( V_2 , 0U , V_65 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_174 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_109 ( V_2 , 0U , V_65 -> V_66 ) ;
return F_19 ( V_2 ) ;
}
static int F_175 ( struct V_1 * V_2 , T_1 V_183 )
{
int V_16 = 0 ;
V_16 = F_176 ( V_2 , V_183 , V_57 ) ;
if ( V_16 < 0 )
goto V_13;
V_13:
return V_16 ;
}
struct V_9 * F_177 ( struct V_184 * V_185 )
{
bool V_186 = ( V_185 -> V_187 == V_188 ) ;
bool V_189 = ( ( V_185 -> V_133 == V_190 ) ||
( V_185 -> V_133 == V_191 ) ||
( V_185 -> V_133 == V_192 ) ||
( V_185 -> V_133 == V_193 ) ||
( V_185 -> V_133 == V_194 ) ) ;
bool V_195 = ( V_185 -> V_196 == 2U ) ;
return ( V_186 && V_189 && V_195 ) ? & V_197 : NULL ;
}
