static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char * V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
int V_12 ;
V_12 = F_6 ( V_11 , V_8 ) ;
if ( V_12 >= 0 ) {
* V_9 = ( unsigned char ) V_12 ;
V_12 = 0 ;
}
return V_12 ;
}
static int F_7 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
int V_12 = F_8 ( V_11 , V_8 , V_9 ) ;
if ( V_8 == V_13 && ( V_9 & V_14 ) )
F_9 ( 5 ) ;
return V_12 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char * V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
T_1 V_15 = V_8 ;
struct V_16 V_17 ;
int V_12 ;
V_17 . V_18 = V_11 -> V_18 ;
V_17 . V_19 = 0 ;
V_17 . V_20 = 1 ;
V_17 . V_21 = & V_15 ;
V_12 = F_11 ( V_11 -> V_22 , & V_17 , 1 ) ;
if ( V_12 < 0 ) {
F_12 ( V_23 L_1 , V_12 ) ;
return V_12 ;
}
V_17 . V_19 = V_24 ;
V_12 = F_11 ( V_11 -> V_22 , & V_17 , 1 ) ;
if ( V_12 >= 0 ) {
* V_9 = V_15 ;
V_12 = 0 ;
}
return V_12 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
struct V_16 V_17 ;
unsigned char V_15 [ 2 ] = { V_8 , V_9 } ;
int V_12 ;
V_17 . V_18 = V_11 -> V_18 ;
V_17 . V_19 = 0 ;
V_17 . V_20 = 2 ;
V_17 . V_21 = V_15 ;
V_12 = F_11 ( V_11 -> V_22 , & V_17 , 1 ) ;
if ( V_12 > 0 )
V_12 = 0 ;
if ( V_8 == V_13 && ( V_9 & V_14 ) )
F_9 ( 5 ) ;
return V_12 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char * V_9 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_25 -> V_26 )
return F_4 ( V_3 , V_8 , V_9 ) ;
else
return F_10 ( V_3 , V_8 , V_9 ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_9 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_25 -> V_26 )
return F_7 ( V_3 , V_8 , V_9 ) ;
else
return F_13 ( V_3 , V_8 , V_9 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_27 * V_28 )
{
while ( V_28 -> V_29 != 0xff || V_28 -> V_9 != 0xff ) {
int V_12 = F_15 ( V_3 , V_28 -> V_29 , V_28 -> V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_28 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , T_2 V_30 )
{
F_15 ( V_3 , V_13 , V_14 ) ;
F_9 ( 1 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , T_2 V_30 )
{
return F_16 ( V_3 , V_31 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
unsigned char V_32 ;
int V_12 ;
V_12 = F_18 ( V_3 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_14 ( V_3 , V_33 , & V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_32 != 0x7f )
return - V_34 ;
V_12 = F_14 ( V_3 , V_35 , & V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_32 != 0xa2 )
return - V_34 ;
V_12 = F_14 ( V_3 , V_36 , & V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_32 != 0x76 )
return - V_34 ;
V_12 = F_14 ( V_3 , V_37 , & V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_32 != 0x73 )
return - V_34 ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_2 V_40 = V_25 -> V_40 ;
int V_41 ;
if ( V_25 -> V_42 )
V_41 = 1 ;
else
V_41 = V_43 ;
V_40 ++ ;
if ( V_25 -> V_44 -> V_45 == V_46 )
V_40 = ( V_40 >> 1 ) ;
V_39 -> V_47 = 1 ;
V_39 -> V_48 = ( 5 * V_41 * V_25 -> V_49 ) /
( 4 * V_40 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_2 V_40 ;
int V_41 ;
int V_12 ;
if ( V_25 -> V_42 ) {
V_41 = 1 ;
V_12 = F_15 ( V_3 , V_50 , V_51 ) ;
} else {
V_41 = V_43 ;
V_12 = F_15 ( V_3 , V_50 , V_52 ) ;
}
if ( V_12 < 0 )
return V_12 ;
if ( V_39 -> V_47 == 0 || V_39 -> V_48 == 0 ) {
V_40 = 0 ;
} else {
V_40 = ( 5 * V_41 * V_25 -> V_49 * V_39 -> V_47 ) /
( 4 * V_39 -> V_48 ) ;
if ( V_25 -> V_44 -> V_45 == V_46 )
V_40 = ( V_40 << 1 ) ;
V_40 -- ;
}
if ( V_40 <= 0 )
V_40 = V_53 ;
else if ( V_40 > V_54 )
V_40 = V_54 ;
V_25 -> V_40 = V_40 ;
F_20 ( V_3 , V_39 ) ;
V_12 = F_15 ( V_3 , V_55 , V_25 -> V_40 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_15 ( V_3 , V_50 , V_52 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_39 -> V_47 = 1 ;
V_39 -> V_48 = V_25 -> V_49 ;
if ( ( V_25 -> V_40 & V_53 ) == 0 && ( V_25 -> V_40 & V_54 ) > 1 )
V_39 -> V_48 /= ( V_25 -> V_40 & V_54 ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int div ;
if ( V_39 -> V_47 == 0 || V_39 -> V_48 == 0 )
div = 1 ;
else
div = ( V_39 -> V_47 * V_25 -> V_49 ) / V_39 -> V_48 ;
if ( div == 0 )
div = 1 ;
else if ( div > V_54 )
div = V_54 ;
V_25 -> V_40 = ( V_25 -> V_40 & 0x80 ) | div ;
V_39 -> V_47 = 1 ;
V_39 -> V_48 = V_25 -> V_49 / div ;
return F_15 ( V_3 , V_55 , V_25 -> V_40 ) ;
}
static int F_24 ( struct V_2 * V_3 , int V_56 , int V_57 ,
int V_58 , int V_59 )
{
int V_12 ;
unsigned char V_32 ;
V_12 = F_15 ( V_3 , V_60 , ( V_56 >> 3 ) & 0xff ) ;
V_12 += F_15 ( V_3 , V_61 , ( V_57 >> 3 ) & 0xff ) ;
V_12 += F_14 ( V_3 , V_62 , & V_32 ) ;
V_32 = ( V_32 & 0xc0 ) | ( ( V_57 & 0x7 ) << 3 ) | ( V_56 & 0x7 ) ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_62 , V_32 ) ;
V_12 += F_15 ( V_3 , V_63 , ( V_58 >> 2 ) & 0xff ) ;
V_12 += F_15 ( V_3 , V_64 , ( V_59 >> 2 ) & 0xff ) ;
V_12 += F_14 ( V_3 , V_65 , & V_32 ) ;
V_32 = ( V_32 & 0xf0 ) | ( ( V_59 & 0x3 ) << 2 ) | ( V_58 & 0x3 ) ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_65 , V_32 ) ;
return V_12 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_66 * V_67 ,
struct V_68 * V_69 )
{
if ( V_69 -> V_70 || V_69 -> V_71 >= V_72 )
return - V_73 ;
V_69 -> V_69 = V_74 [ V_69 -> V_71 ] . V_45 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_75 * V_44 ,
struct V_76 * * V_77 ,
struct V_78 * * V_79 )
{
int V_71 , V_80 ;
struct V_78 * V_81 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned int V_82 = V_25 -> V_83 -> V_82 ;
unsigned int V_84 = V_82 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
if ( V_74 [ V_71 ] . V_45 == V_44 -> V_69 )
break;
if ( V_71 >= V_72 ) {
V_71 = 0 ;
V_44 -> V_69 = V_74 [ 0 ] . V_45 ;
}
if ( V_77 != NULL )
* V_77 = V_74 + V_71 ;
V_44 -> V_85 = V_86 ;
if ( V_25 -> V_87 || V_25 -> V_88 )
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
V_81 = V_25 -> V_83 -> V_89 + V_80 ;
if ( V_81 -> V_90 < V_25 -> V_87 ||
V_81 -> V_91 < V_25 -> V_88 ) {
V_84 = V_80 ;
break;
}
}
for ( V_81 = V_25 -> V_83 -> V_89 ;
V_81 < V_25 -> V_83 -> V_89 + V_84 ; V_81 ++ )
if ( V_44 -> V_90 >= V_81 -> V_90 && V_44 -> V_91 >= V_81 -> V_91 )
break;
if ( V_81 >= V_25 -> V_83 -> V_89 + V_84 )
V_81 -- ;
if ( V_79 != NULL )
* V_79 = V_81 ;
V_44 -> V_90 = V_81 -> V_90 ;
V_44 -> V_91 = V_81 -> V_91 ;
V_44 -> V_92 = V_74 [ V_71 ] . V_92 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_66 * V_67 ,
struct V_93 * V_94 )
{
struct V_76 * V_95 ;
struct V_78 * V_81 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned char V_96 ;
int V_12 ;
if ( V_94 -> V_70 )
return - V_73 ;
if ( V_94 -> V_97 == V_98 ) {
V_12 = F_26 ( V_3 , & V_94 -> V_94 , NULL , NULL ) ;
if ( V_12 )
return V_12 ;
V_67 -> V_99 = V_94 -> V_94 ;
return 0 ;
}
V_12 = F_26 ( V_3 , & V_94 -> V_94 , & V_95 , & V_81 ) ;
if ( V_12 )
return V_12 ;
V_96 = V_95 -> V_100 [ 0 ] . V_9 ;
V_96 |= V_81 -> V_101 ;
F_15 ( V_3 , V_13 , V_96 ) ;
F_16 ( V_3 , V_95 -> V_100 + 1 ) ;
F_24 ( V_3 , V_81 -> V_56 , V_81 -> V_57 , V_81 -> V_58 ,
V_81 -> V_59 ) ;
V_12 = 0 ;
if ( V_81 -> V_100 )
V_12 = F_16 ( V_3 , V_81 -> V_100 ) ;
V_25 -> V_44 = V_95 ;
if ( V_12 == 0 )
V_12 = F_15 ( V_3 , V_55 , V_25 -> V_40 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_102 * V_103 )
{
struct V_104 * V_105 = & V_103 -> V_106 . V_107 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_103 -> type != V_108 )
return - V_73 ;
V_105 -> V_109 = V_110 ;
V_25 -> V_83 -> V_111 ( V_3 , & V_105 -> V_112 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_102 * V_103 )
{
struct V_104 * V_105 = & V_103 -> V_106 . V_107 ;
struct V_38 * V_39 = & V_105 -> V_112 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_103 -> type != V_108 )
return - V_73 ;
V_105 -> V_109 = V_110 ;
return V_25 -> V_83 -> V_113 ( V_3 , V_39 ) ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_66 * V_67 ,
struct V_114 * V_115 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned int V_82 = V_25 -> V_83 -> V_82 ;
int V_80 ;
if ( V_115 -> V_70 )
return - V_73 ;
if ( V_115 -> V_71 >= F_31 ( V_116 ) )
return - V_73 ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
struct V_78 * V_117 = & V_25 -> V_83 -> V_89 [ V_80 ] ;
if ( V_25 -> V_87 && V_117 -> V_90 < V_25 -> V_87 )
continue;
if ( V_25 -> V_88 && V_117 -> V_91 < V_25 -> V_88 )
continue;
if ( V_115 -> V_90 == V_117 -> V_90 && V_115 -> V_91 == V_117 -> V_91 )
break;
}
if ( V_80 == V_82 )
return - V_73 ;
V_115 -> V_118 . V_47 = 1 ;
V_115 -> V_118 . V_48 = V_116 [ V_115 -> V_71 ] ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_66 * V_67 ,
struct V_119 * V_120 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_80 ;
int V_121 = - 1 ;
T_3 V_71 = V_120 -> V_71 ;
unsigned int V_82 = V_25 -> V_83 -> V_82 ;
if ( V_120 -> V_70 )
return - V_73 ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
struct V_78 * V_117 = & V_25 -> V_83 -> V_89 [ V_80 ] ;
if ( V_25 -> V_87 && V_117 -> V_90 < V_25 -> V_87 )
continue;
if ( V_25 -> V_88 && V_117 -> V_91 < V_25 -> V_88 )
continue;
if ( V_71 == ++ V_121 ) {
V_120 -> V_87 = V_120 -> V_122 = V_117 -> V_90 ;
V_120 -> V_88 = V_120 -> V_123 = V_117 -> V_91 ;
return 0 ;
}
}
return - V_73 ;
}
static int F_33 ( struct V_2 * V_3 ,
int V_124 [ V_125 ] )
{
int V_80 , V_12 ;
unsigned char V_126 = 0 ;
V_12 = F_14 ( V_3 , V_127 , & V_126 ) ;
V_126 &= 0xc0 ;
for ( V_80 = 0 ; V_80 < V_125 ; V_80 ++ ) {
unsigned char V_128 ;
if ( V_124 [ V_80 ] < 0 ) {
V_126 |= ( 1 << V_80 ) ;
if ( V_124 [ V_80 ] < - 255 )
V_128 = 0xff ;
else
V_128 = ( - 1 * V_124 [ V_80 ] ) & 0xff ;
}
else {
if ( V_124 [ V_80 ] > 255 )
V_128 = 0xff ;
else
V_128 = V_124 [ V_80 ] & 0xff ;
}
V_12 += F_15 ( V_3 , V_129 + V_80 , V_128 ) ;
}
V_12 += F_15 ( V_3 , V_127 , V_126 ) ;
return V_12 ;
}
static int F_34 ( int V_130 )
{
int V_131 = 1 ;
int V_132 ;
if ( V_130 < 0 ) {
V_130 = - V_130 ;
V_131 = - 1 ;
}
if ( V_130 <= 90 )
V_132 = V_133 [ V_130 / V_134 ] ;
else {
V_130 -= 90 ;
V_132 = 1000 - V_133 [ V_130 / V_134 ] ;
}
return V_132 * V_131 ;
}
static int F_35 ( int V_130 )
{
V_130 = 90 - V_130 ;
if ( V_130 > 180 )
V_130 -= 360 ;
else if ( V_130 < - 180 )
V_130 += 360 ;
return F_34 ( V_130 ) ;
}
static void F_36 ( struct V_1 * V_25 ,
int V_124 [ V_125 ] , int V_135 , int V_136 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_125 ; V_80 ++ )
V_124 [ V_80 ] = ( V_25 -> V_44 -> V_137 [ V_80 ] * V_135 ) >> 7 ;
if ( V_136 != 0 ) {
int V_138 , V_139 , V_140 [ V_125 ] ;
memcpy ( V_140 , V_124 , V_125 * sizeof( int ) ) ;
V_138 = F_34 ( V_136 ) ;
V_139 = F_35 ( V_136 ) ;
V_124 [ 0 ] = ( V_124 [ 3 ] * V_138 + V_124 [ 0 ] * V_139 ) / 1000 ;
V_124 [ 1 ] = ( V_124 [ 4 ] * V_138 + V_124 [ 1 ] * V_139 ) / 1000 ;
V_124 [ 2 ] = ( V_124 [ 5 ] * V_138 + V_124 [ 2 ] * V_139 ) / 1000 ;
V_124 [ 3 ] = ( V_124 [ 3 ] * V_139 - V_124 [ 0 ] * V_138 ) / 1000 ;
V_124 [ 4 ] = ( V_124 [ 4 ] * V_139 - V_124 [ 1 ] * V_138 ) / 1000 ;
V_124 [ 5 ] = ( V_124 [ 5 ] * V_139 - V_124 [ 2 ] * V_138 ) / 1000 ;
}
}
static int F_37 ( struct V_2 * V_3 , int V_135 , int V_136 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_124 [ V_125 ] ;
int V_12 ;
F_36 ( V_25 , V_124 , V_135 , V_136 ) ;
V_12 = F_33 ( V_3 , V_124 ) ;
return V_12 ;
}
static unsigned char F_38 ( unsigned char V_32 )
{
if ( V_32 > 127 )
return V_32 & 0x7f ;
return ( 128 - V_32 ) | 0x80 ;
}
static int F_39 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_141 = 0 , V_32 ;
int V_12 ;
F_14 ( V_3 , V_142 , & V_141 ) ;
V_141 &= ~ V_143 ;
F_15 ( V_3 , V_142 , V_141 ) ;
V_32 = F_38 ( V_9 ) ;
V_12 = F_15 ( V_3 , V_144 , V_32 ) ;
return V_12 ;
}
static int F_40 ( struct V_2 * V_3 , int V_9 )
{
return F_15 ( V_3 , V_145 , ( unsigned char ) V_9 ) ;
}
static int F_41 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_32 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_146 , & V_32 ) ;
if ( V_9 )
V_32 |= V_147 ;
else
V_32 &= ~ V_147 ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_146 , V_32 ) ;
return V_12 ;
}
static int F_42 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_32 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_146 , & V_32 ) ;
if ( V_9 )
V_32 |= V_148 ;
else
V_32 &= ~ V_148 ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_146 , V_32 ) ;
return V_12 ;
}
static int F_43 ( struct V_2 * V_3 , T_4 * V_9 )
{
int V_12 ;
unsigned char V_149 ;
V_12 = F_14 ( V_3 , V_150 , & V_149 ) ;
* V_9 = V_149 ;
return V_12 ;
}
static int F_44 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_141 ;
V_12 = F_15 ( V_3 , V_150 , V_9 & 0xff ) ;
if ( V_12 == 0 ) {
V_12 = F_14 ( V_3 , V_142 , & V_141 ) ;
V_12 = F_15 ( V_3 , V_142 , V_141 & ~ V_151 ) ;
}
return V_12 ;
}
static int F_45 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_141 ;
V_12 = F_14 ( V_3 , V_142 , & V_141 ) ;
if ( V_12 == 0 ) {
if ( V_9 )
V_141 |= V_151 ;
else
V_141 &= ~ V_151 ;
V_12 = F_15 ( V_3 , V_142 , V_141 ) ;
}
return V_12 ;
}
static int F_46 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_152 , V_141 , V_153 , V_154 ;
V_12 = F_14 ( V_3 , V_155 , & V_152 ) +
F_14 ( V_3 , V_142 , & V_141 ) +
F_14 ( V_3 , V_156 , & V_154 ) ;
if ( V_12 )
return V_12 ;
V_152 = ( V_152 & 0xfc ) | ( V_9 & 0x03 ) ;
V_153 = ( V_9 >> 2 ) & 0xff ;
V_154 = ( V_154 & 0xc0 ) | ( ( V_9 >> 10 ) & 0x3f ) ;
V_12 = F_15 ( V_3 , V_155 , V_152 ) +
F_15 ( V_3 , V_157 , V_153 ) +
F_15 ( V_3 , V_156 , V_154 ) ;
if ( V_12 == 0 )
V_12 = F_15 ( V_3 , V_142 , V_141 & ~ V_143 ) ;
return V_12 ;
}
static int F_47 ( struct V_2 * V_3 ,
enum V_158 V_9 )
{
int V_12 ;
unsigned char V_141 ;
V_12 = F_14 ( V_3 , V_142 , & V_141 ) ;
if ( V_12 == 0 ) {
if ( V_9 == V_159 )
V_141 |= V_143 ;
else
V_141 &= ~ V_143 ;
V_12 = F_15 ( V_3 , V_142 , V_141 ) ;
}
return V_12 ;
}
static int F_48 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
switch ( V_5 -> V_160 ) {
case V_161 :
return F_43 ( V_3 , & V_25 -> V_149 -> V_30 ) ;
}
return - V_73 ;
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
switch ( V_5 -> V_160 ) {
case V_162 :
return F_39 ( V_3 , V_5 -> V_30 ) ;
case V_163 :
return F_40 ( V_3 , V_5 -> V_30 ) ;
case V_164 :
return F_37 ( V_3 ,
V_25 -> V_165 -> V_30 , V_25 -> V_136 -> V_30 ) ;
case V_166 :
return F_42 ( V_3 , V_5 -> V_30 ) ;
case V_167 :
return F_41 ( V_3 , V_5 -> V_30 ) ;
case V_161 :
if ( ! V_5 -> V_30 ) {
return F_44 ( V_3 , V_25 -> V_149 -> V_30 ) ;
}
return F_45 ( V_3 , V_5 -> V_30 ) ;
case V_168 :
if ( V_5 -> V_30 == V_169 ) {
return F_46 ( V_3 , V_25 -> V_170 -> V_30 ) ;
}
return F_47 ( V_3 , V_5 -> V_30 ) ;
}
return - V_73 ;
}
static int F_50 ( struct V_2 * V_3 , struct V_171 * V_8 )
{
unsigned char V_30 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_8 -> V_8 & 0xff , & V_30 ) ;
V_8 -> V_30 = V_30 ;
V_8 -> V_172 = 1 ;
return V_12 ;
}
static int F_51 ( struct V_2 * V_3 , const struct V_171 * V_8 )
{
F_15 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_30 & 0xff ) ;
return 0 ;
}
static int F_52 ( struct V_10 * V_11 , struct V_1 * V_25 )
{
V_25 -> V_173 = F_53 ( & V_11 -> V_174 , L_2 ,
V_175 ) ;
if ( F_54 ( V_25 -> V_173 ) ) {
F_55 ( & V_11 -> V_174 , L_3 , L_2 ) ;
return F_56 ( V_25 -> V_173 ) ;
}
V_25 -> V_176 = F_53 ( & V_11 -> V_174 , L_4 ,
V_175 ) ;
if ( F_54 ( V_25 -> V_176 ) ) {
F_55 ( & V_11 -> V_174 , L_3 , L_4 ) ;
return F_56 ( V_25 -> V_176 ) ;
}
F_57 ( 3000 , 5000 ) ;
return 0 ;
}
static int F_58 ( struct V_10 * V_11 ,
const struct V_177 * V_160 )
{
struct V_38 V_39 ;
struct V_2 * V_3 ;
struct V_1 * V_25 ;
int V_12 ;
V_25 = F_59 ( & V_11 -> V_174 , sizeof( * V_25 ) , V_178 ) ;
if ( V_25 == NULL )
return - V_179 ;
V_3 = & V_25 -> V_3 ;
F_60 ( V_3 , V_11 , & V_180 ) ;
V_25 -> V_49 = 30 ;
if ( V_11 -> V_174 . V_181 ) {
struct V_182 * V_183 = V_11 -> V_174 . V_181 ;
V_25 -> V_87 = V_183 -> V_87 ;
V_25 -> V_88 = V_183 -> V_88 ;
V_25 -> V_26 = V_183 -> V_26 ;
if ( V_183 -> V_49 )
V_25 -> V_49 = V_183 -> V_49 ;
if ( V_183 -> V_42 && V_160 -> V_184 != V_185 )
V_25 -> V_42 = true ;
if ( V_183 -> V_186 )
V_25 -> V_186 = true ;
}
V_25 -> V_187 = F_61 ( & V_11 -> V_174 , L_5 ) ;
if ( F_54 ( V_25 -> V_187 ) )
return F_56 ( V_25 -> V_187 ) ;
V_12 = F_62 ( V_25 -> V_187 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_52 ( V_11 , V_25 ) ;
if ( V_12 )
goto V_188;
V_25 -> V_49 = F_63 ( V_25 -> V_187 ) / 1000000 ;
if ( V_25 -> V_49 < 10 || V_25 -> V_49 > 48 ) {
V_12 = - V_73 ;
goto V_188;
}
V_12 = F_19 ( V_3 ) ;
if ( V_12 ) {
F_64 ( 1 , V_189 , V_11 ,
L_6 ,
V_11 -> V_18 << 1 , V_11 -> V_22 -> V_190 ) ;
goto V_188;
}
F_65 ( V_11 , L_7 ,
V_11 -> V_18 << 1 , V_11 -> V_22 -> V_190 ) ;
V_25 -> V_83 = & V_191 [ V_160 -> V_184 ] ;
V_25 -> V_44 = & V_74 [ 0 ] ;
V_25 -> V_40 = 0 ;
V_39 . V_47 = 1 ;
V_39 . V_48 = 30 ;
V_25 -> V_83 -> V_113 ( V_3 , & V_39 ) ;
if ( V_25 -> V_186 )
F_15 ( V_3 , V_192 , V_193 ) ;
F_66 ( & V_25 -> V_7 , 10 ) ;
F_67 ( & V_25 -> V_7 , & V_194 ,
V_162 , 0 , 255 , 1 , 128 ) ;
F_67 ( & V_25 -> V_7 , & V_194 ,
V_163 , 0 , 127 , 1 , 64 ) ;
F_67 ( & V_25 -> V_7 , & V_194 ,
V_166 , 0 , 1 , 1 , 0 ) ;
F_67 ( & V_25 -> V_7 , & V_194 ,
V_167 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_165 = F_67 ( & V_25 -> V_7 , & V_194 ,
V_164 , 0 , 256 , 1 , 128 ) ;
V_25 -> V_136 = F_67 ( & V_25 -> V_7 , & V_194 ,
V_195 , - 180 , 180 , 5 , 0 ) ;
V_25 -> V_149 = F_67 ( & V_25 -> V_7 , & V_194 ,
V_196 , 0 , 255 , 1 , 128 ) ;
V_25 -> V_197 = F_67 ( & V_25 -> V_7 , & V_194 ,
V_161 , 0 , 1 , 1 , 1 ) ;
V_25 -> V_170 = F_67 ( & V_25 -> V_7 , & V_194 ,
V_198 , 0 , 65535 , 1 , 500 ) ;
V_25 -> V_199 = F_68 ( & V_25 -> V_7 , & V_194 ,
V_168 , V_169 , 0 ,
V_159 ) ;
V_3 -> V_200 = & V_25 -> V_7 ;
if ( V_25 -> V_7 . error ) {
V_12 = V_25 -> V_7 . error ;
goto V_201;
}
F_69 ( 2 , & V_25 -> V_197 , 0 , true ) ;
F_69 ( 2 , & V_25 -> V_199 ,
V_169 , false ) ;
F_70 ( 2 , & V_25 -> V_165 ) ;
F_71 ( & V_25 -> V_7 ) ;
V_12 = F_72 ( & V_25 -> V_3 ) ;
if ( V_12 < 0 )
goto V_201;
return 0 ;
V_201:
F_73 ( & V_25 -> V_7 ) ;
V_188:
F_74 ( V_25 -> V_187 ) ;
return V_12 ;
}
static int F_75 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_76 ( V_11 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_77 ( V_3 ) ;
F_73 ( & V_25 -> V_7 ) ;
F_74 ( V_25 -> V_187 ) ;
return 0 ;
}
