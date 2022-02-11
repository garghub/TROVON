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
static int F_25 ( struct V_2 * V_3 , unsigned V_66 ,
enum V_67 * V_68 )
{
if ( V_66 >= V_69 )
return - V_70 ;
* V_68 = V_71 [ V_66 ] . V_45 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_72 * V_44 ,
struct V_73 * * V_74 ,
struct V_75 * * V_76 )
{
int V_66 , V_77 ;
struct V_75 * V_78 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned int V_79 = V_25 -> V_80 -> V_79 ;
unsigned int V_81 = V_79 ;
for ( V_66 = 0 ; V_66 < V_69 ; V_66 ++ )
if ( V_71 [ V_66 ] . V_45 == V_44 -> V_68 )
break;
if ( V_66 >= V_69 ) {
V_66 = 0 ;
V_44 -> V_68 = V_71 [ 0 ] . V_45 ;
}
if ( V_74 != NULL )
* V_74 = V_71 + V_66 ;
V_44 -> V_82 = V_83 ;
if ( V_25 -> V_84 || V_25 -> V_85 )
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
V_78 = V_25 -> V_80 -> V_86 + V_77 ;
if ( V_78 -> V_87 < V_25 -> V_84 ||
V_78 -> V_88 < V_25 -> V_85 ) {
V_81 = V_77 ;
break;
}
}
for ( V_78 = V_25 -> V_80 -> V_86 ;
V_78 < V_25 -> V_80 -> V_86 + V_81 ; V_78 ++ )
if ( V_44 -> V_87 >= V_78 -> V_87 && V_44 -> V_88 >= V_78 -> V_88 )
break;
if ( V_78 >= V_25 -> V_80 -> V_86 + V_81 )
V_78 -- ;
if ( V_76 != NULL )
* V_76 = V_78 ;
V_44 -> V_87 = V_78 -> V_87 ;
V_44 -> V_88 = V_78 -> V_88 ;
V_44 -> V_89 = V_71 [ V_66 ] . V_89 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_72 * V_44 )
{
return F_26 ( V_3 , V_44 , NULL , NULL ) ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_72 * V_44 )
{
struct V_73 * V_90 ;
struct V_75 * V_78 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned char V_91 ;
int V_12 ;
V_12 = F_26 ( V_3 , V_44 , & V_90 , & V_78 ) ;
if ( V_12 )
return V_12 ;
V_91 = V_90 -> V_92 [ 0 ] . V_9 ;
V_91 |= V_78 -> V_93 ;
F_15 ( V_3 , V_13 , V_91 ) ;
F_16 ( V_3 , V_90 -> V_92 + 1 ) ;
F_24 ( V_3 , V_78 -> V_56 , V_78 -> V_57 , V_78 -> V_58 ,
V_78 -> V_59 ) ;
V_12 = 0 ;
if ( V_78 -> V_92 )
V_12 = F_16 ( V_3 , V_78 -> V_92 ) ;
V_25 -> V_44 = V_90 ;
if ( V_12 == 0 )
V_12 = F_15 ( V_3 , V_55 , V_25 -> V_40 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_99 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_95 -> type != V_100 )
return - V_70 ;
memset ( V_97 , 0 , sizeof( struct V_96 ) ) ;
V_97 -> V_101 = V_102 ;
V_25 -> V_80 -> V_103 ( V_3 , & V_97 -> V_104 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_99 ;
struct V_38 * V_39 = & V_97 -> V_104 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_95 -> type != V_100 )
return - V_70 ;
if ( V_97 -> V_105 != 0 )
return - V_70 ;
return V_25 -> V_80 -> V_106 ( V_3 , V_39 ) ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_107 * V_108 )
{
if ( V_108 -> V_66 >= F_32 ( V_109 ) )
return - V_70 ;
V_108 -> type = V_110 ;
V_108 -> V_111 . V_47 = 1 ;
V_108 -> V_111 . V_48 = V_109 [ V_108 -> V_66 ] ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_112 * V_113 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_77 ;
int V_114 = - 1 ;
T_3 V_66 = V_113 -> V_66 ;
unsigned int V_79 = V_25 -> V_80 -> V_79 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
struct V_75 * V_115 = & V_25 -> V_80 -> V_86 [ V_66 ] ;
if ( V_25 -> V_84 && V_115 -> V_87 < V_25 -> V_84 )
continue;
if ( V_25 -> V_85 && V_115 -> V_88 < V_25 -> V_85 )
continue;
if ( V_66 == ++ V_114 ) {
V_113 -> type = V_116 ;
V_113 -> V_111 . V_87 = V_115 -> V_87 ;
V_113 -> V_111 . V_88 = V_115 -> V_88 ;
return 0 ;
}
}
return - V_70 ;
}
static int F_34 ( struct V_2 * V_3 ,
int V_117 [ V_118 ] )
{
int V_77 , V_12 ;
unsigned char V_119 = 0 ;
V_12 = F_14 ( V_3 , V_120 , & V_119 ) ;
V_119 &= 0xc0 ;
for ( V_77 = 0 ; V_77 < V_118 ; V_77 ++ ) {
unsigned char V_121 ;
if ( V_117 [ V_77 ] < 0 ) {
V_119 |= ( 1 << V_77 ) ;
if ( V_117 [ V_77 ] < - 255 )
V_121 = 0xff ;
else
V_121 = ( - 1 * V_117 [ V_77 ] ) & 0xff ;
}
else {
if ( V_117 [ V_77 ] > 255 )
V_121 = 0xff ;
else
V_121 = V_117 [ V_77 ] & 0xff ;
}
V_12 += F_15 ( V_3 , V_122 + V_77 , V_121 ) ;
}
V_12 += F_15 ( V_3 , V_120 , V_119 ) ;
return V_12 ;
}
static int F_35 ( int V_123 )
{
int V_124 = 1 ;
int V_125 ;
if ( V_123 < 0 ) {
V_123 = - V_123 ;
V_124 = - 1 ;
}
if ( V_123 <= 90 )
V_125 = V_126 [ V_123 / V_127 ] ;
else {
V_123 -= 90 ;
V_125 = 1000 - V_126 [ V_123 / V_127 ] ;
}
return V_125 * V_124 ;
}
static int F_36 ( int V_123 )
{
V_123 = 90 - V_123 ;
if ( V_123 > 180 )
V_123 -= 360 ;
else if ( V_123 < - 180 )
V_123 += 360 ;
return F_35 ( V_123 ) ;
}
static void F_37 ( struct V_1 * V_25 ,
int V_117 [ V_118 ] , int V_128 , int V_129 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_118 ; V_77 ++ )
V_117 [ V_77 ] = ( V_25 -> V_44 -> V_130 [ V_77 ] * V_128 ) >> 7 ;
if ( V_129 != 0 ) {
int V_131 , V_132 , V_133 [ V_118 ] ;
memcpy ( V_133 , V_117 , V_118 * sizeof( int ) ) ;
V_131 = F_35 ( V_129 ) ;
V_132 = F_36 ( V_129 ) ;
V_117 [ 0 ] = ( V_117 [ 3 ] * V_131 + V_117 [ 0 ] * V_132 ) / 1000 ;
V_117 [ 1 ] = ( V_117 [ 4 ] * V_131 + V_117 [ 1 ] * V_132 ) / 1000 ;
V_117 [ 2 ] = ( V_117 [ 5 ] * V_131 + V_117 [ 2 ] * V_132 ) / 1000 ;
V_117 [ 3 ] = ( V_117 [ 3 ] * V_132 - V_117 [ 0 ] * V_131 ) / 1000 ;
V_117 [ 4 ] = ( V_117 [ 4 ] * V_132 - V_117 [ 1 ] * V_131 ) / 1000 ;
V_117 [ 5 ] = ( V_117 [ 5 ] * V_132 - V_117 [ 2 ] * V_131 ) / 1000 ;
}
}
static int F_38 ( struct V_2 * V_3 , int V_128 , int V_129 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_117 [ V_118 ] ;
int V_12 ;
F_37 ( V_25 , V_117 , V_128 , V_129 ) ;
V_12 = F_34 ( V_3 , V_117 ) ;
return V_12 ;
}
static unsigned char F_39 ( unsigned char V_32 )
{
if ( V_32 > 127 )
return V_32 & 0x7f ;
return ( 128 - V_32 ) | 0x80 ;
}
static int F_40 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_134 = 0 , V_32 ;
int V_12 ;
F_14 ( V_3 , V_135 , & V_134 ) ;
V_134 &= ~ V_136 ;
F_15 ( V_3 , V_135 , V_134 ) ;
V_32 = F_39 ( V_9 ) ;
V_12 = F_15 ( V_3 , V_137 , V_32 ) ;
return V_12 ;
}
static int F_41 ( struct V_2 * V_3 , int V_9 )
{
return F_15 ( V_3 , V_138 , ( unsigned char ) V_9 ) ;
}
static int F_42 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_32 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_139 , & V_32 ) ;
if ( V_9 )
V_32 |= V_140 ;
else
V_32 &= ~ V_140 ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_139 , V_32 ) ;
return V_12 ;
}
static int F_43 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_32 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_139 , & V_32 ) ;
if ( V_9 )
V_32 |= V_141 ;
else
V_32 &= ~ V_141 ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_139 , V_32 ) ;
return V_12 ;
}
static int F_44 ( struct V_2 * V_3 , T_4 * V_9 )
{
int V_12 ;
unsigned char V_142 ;
V_12 = F_14 ( V_3 , V_143 , & V_142 ) ;
* V_9 = V_142 ;
return V_12 ;
}
static int F_45 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_134 ;
V_12 = F_15 ( V_3 , V_143 , V_9 & 0xff ) ;
if ( V_12 == 0 ) {
V_12 = F_14 ( V_3 , V_135 , & V_134 ) ;
V_12 = F_15 ( V_3 , V_135 , V_134 & ~ V_144 ) ;
}
return V_12 ;
}
static int F_46 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_134 ;
V_12 = F_14 ( V_3 , V_135 , & V_134 ) ;
if ( V_12 == 0 ) {
if ( V_9 )
V_134 |= V_144 ;
else
V_134 &= ~ V_144 ;
V_12 = F_15 ( V_3 , V_135 , V_134 ) ;
}
return V_12 ;
}
static int F_47 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_145 , V_134 , V_146 , V_147 ;
V_12 = F_14 ( V_3 , V_148 , & V_145 ) +
F_14 ( V_3 , V_135 , & V_134 ) ;
F_14 ( V_3 , V_149 , & V_147 ) ;
if ( V_12 )
return V_12 ;
V_145 = ( V_145 & 0xfc ) | ( V_9 & 0x03 ) ;
V_146 = ( V_9 >> 2 ) & 0xff ;
V_147 = ( V_147 & 0xc0 ) | ( ( V_9 >> 10 ) & 0x3f ) ;
V_12 = F_15 ( V_3 , V_148 , V_145 ) +
F_15 ( V_3 , V_150 , V_146 ) +
F_15 ( V_3 , V_149 , V_147 ) ;
if ( V_12 == 0 )
V_12 = F_15 ( V_3 , V_135 , V_134 & ~ V_136 ) ;
return V_12 ;
}
static int F_48 ( struct V_2 * V_3 ,
enum V_151 V_9 )
{
int V_12 ;
unsigned char V_134 ;
V_12 = F_14 ( V_3 , V_135 , & V_134 ) ;
if ( V_12 == 0 ) {
if ( V_9 == V_152 )
V_134 |= V_136 ;
else
V_134 &= ~ V_136 ;
V_12 = F_15 ( V_3 , V_135 , V_134 ) ;
}
return V_12 ;
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
switch ( V_5 -> V_153 ) {
case V_154 :
return F_44 ( V_3 , & V_25 -> V_142 -> V_30 ) ;
}
return - V_70 ;
}
static int F_50 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
switch ( V_5 -> V_153 ) {
case V_155 :
return F_40 ( V_3 , V_5 -> V_30 ) ;
case V_156 :
return F_41 ( V_3 , V_5 -> V_30 ) ;
case V_157 :
return F_38 ( V_3 ,
V_25 -> V_158 -> V_30 , V_25 -> V_129 -> V_30 ) ;
case V_159 :
return F_43 ( V_3 , V_5 -> V_30 ) ;
case V_160 :
return F_42 ( V_3 , V_5 -> V_30 ) ;
case V_154 :
if ( ! V_5 -> V_30 ) {
return F_45 ( V_3 , V_25 -> V_142 -> V_30 ) ;
}
return F_46 ( V_3 , V_5 -> V_30 ) ;
case V_161 :
if ( V_5 -> V_30 == V_162 ) {
return F_47 ( V_3 , V_25 -> V_163 -> V_30 ) ;
}
return F_48 ( V_3 , V_5 -> V_30 ) ;
}
return - V_70 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_164 * V_165 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_52 ( V_11 , V_165 , V_166 , 0 ) ;
}
static int F_53 ( struct V_2 * V_3 , struct V_167 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
unsigned char V_30 = 0 ;
int V_12 ;
if ( ! F_54 ( V_11 , & V_8 -> V_168 ) )
return - V_70 ;
if ( ! F_55 ( V_169 ) )
return - V_170 ;
V_12 = F_14 ( V_3 , V_8 -> V_8 & 0xff , & V_30 ) ;
V_8 -> V_30 = V_30 ;
V_8 -> V_171 = 1 ;
return V_12 ;
}
static int F_56 ( struct V_2 * V_3 , const struct V_167 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
if ( ! F_54 ( V_11 , & V_8 -> V_168 ) )
return - V_70 ;
if ( ! F_55 ( V_169 ) )
return - V_170 ;
F_15 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_30 & 0xff ) ;
return 0 ;
}
static int F_57 ( struct V_10 * V_11 ,
const struct V_172 * V_153 )
{
struct V_38 V_39 ;
struct V_2 * V_3 ;
struct V_1 * V_25 ;
int V_12 ;
V_25 = F_58 ( sizeof( struct V_1 ) , V_173 ) ;
if ( V_25 == NULL )
return - V_174 ;
V_3 = & V_25 -> V_3 ;
F_59 ( V_3 , V_11 , & V_175 ) ;
V_25 -> V_49 = 30 ;
if ( V_11 -> V_176 . V_177 ) {
struct V_178 * V_179 = V_11 -> V_176 . V_177 ;
V_25 -> V_84 = V_179 -> V_84 ;
V_25 -> V_85 = V_179 -> V_85 ;
V_25 -> V_26 = V_179 -> V_26 ;
if ( V_179 -> V_49 )
V_25 -> V_49 = V_179 -> V_49 ;
if ( V_179 -> V_42 && V_153 -> V_180 != V_181 )
V_25 -> V_42 = true ;
if ( V_179 -> V_182 )
V_25 -> V_182 = true ;
}
V_12 = F_19 ( V_3 ) ;
if ( V_12 ) {
F_60 ( 1 , V_183 , V_11 ,
L_2 ,
V_11 -> V_18 << 1 , V_11 -> V_22 -> V_184 ) ;
F_61 ( V_25 ) ;
return V_12 ;
}
F_62 ( V_11 , L_3 ,
V_11 -> V_18 << 1 , V_11 -> V_22 -> V_184 ) ;
V_25 -> V_80 = & V_185 [ V_153 -> V_180 ] ;
V_25 -> V_44 = & V_71 [ 0 ] ;
V_25 -> V_40 = 0 ;
V_39 . V_47 = 1 ;
V_39 . V_48 = 30 ;
V_25 -> V_80 -> V_106 ( V_3 , & V_39 ) ;
if ( V_25 -> V_182 )
F_15 ( V_3 , V_186 , V_187 ) ;
F_63 ( & V_25 -> V_7 , 10 ) ;
F_64 ( & V_25 -> V_7 , & V_188 ,
V_155 , 0 , 255 , 1 , 128 ) ;
F_64 ( & V_25 -> V_7 , & V_188 ,
V_156 , 0 , 127 , 1 , 64 ) ;
F_64 ( & V_25 -> V_7 , & V_188 ,
V_159 , 0 , 1 , 1 , 0 ) ;
F_64 ( & V_25 -> V_7 , & V_188 ,
V_160 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_158 = F_64 ( & V_25 -> V_7 , & V_188 ,
V_157 , 0 , 256 , 1 , 128 ) ;
V_25 -> V_129 = F_64 ( & V_25 -> V_7 , & V_188 ,
V_189 , - 180 , 180 , 5 , 0 ) ;
V_25 -> V_142 = F_64 ( & V_25 -> V_7 , & V_188 ,
V_190 , 0 , 255 , 1 , 128 ) ;
V_25 -> V_191 = F_64 ( & V_25 -> V_7 , & V_188 ,
V_154 , 0 , 1 , 1 , 1 ) ;
V_25 -> V_163 = F_64 ( & V_25 -> V_7 , & V_188 ,
V_192 , 0 , 65535 , 1 , 500 ) ;
V_25 -> V_193 = F_65 ( & V_25 -> V_7 , & V_188 ,
V_161 , V_162 , 0 ,
V_152 ) ;
V_3 -> V_194 = & V_25 -> V_7 ;
if ( V_25 -> V_7 . error ) {
int V_195 = V_25 -> V_7 . error ;
F_66 ( & V_25 -> V_7 ) ;
F_61 ( V_25 ) ;
return V_195 ;
}
F_67 ( 2 , & V_25 -> V_191 , 0 , true ) ;
F_67 ( 2 , & V_25 -> V_193 ,
V_162 , false ) ;
F_68 ( 2 , & V_25 -> V_158 ) ;
F_69 ( & V_25 -> V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_71 ( V_11 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_72 ( V_3 ) ;
F_66 ( & V_25 -> V_7 ) ;
F_61 ( V_25 ) ;
return 0 ;
}
