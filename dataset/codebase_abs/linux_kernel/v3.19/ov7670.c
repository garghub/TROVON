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
T_2 * V_67 )
{
if ( V_66 >= V_68 )
return - V_69 ;
* V_67 = V_70 [ V_66 ] . V_45 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_71 * V_44 ,
struct V_72 * * V_73 ,
struct V_74 * * V_75 )
{
int V_66 , V_76 ;
struct V_74 * V_77 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned int V_78 = V_25 -> V_79 -> V_78 ;
unsigned int V_80 = V_78 ;
for ( V_66 = 0 ; V_66 < V_68 ; V_66 ++ )
if ( V_70 [ V_66 ] . V_45 == V_44 -> V_67 )
break;
if ( V_66 >= V_68 ) {
V_66 = 0 ;
V_44 -> V_67 = V_70 [ 0 ] . V_45 ;
}
if ( V_73 != NULL )
* V_73 = V_70 + V_66 ;
V_44 -> V_81 = V_82 ;
if ( V_25 -> V_83 || V_25 -> V_84 )
for ( V_76 = 0 ; V_76 < V_78 ; V_76 ++ ) {
V_77 = V_25 -> V_79 -> V_85 + V_76 ;
if ( V_77 -> V_86 < V_25 -> V_83 ||
V_77 -> V_87 < V_25 -> V_84 ) {
V_80 = V_76 ;
break;
}
}
for ( V_77 = V_25 -> V_79 -> V_85 ;
V_77 < V_25 -> V_79 -> V_85 + V_80 ; V_77 ++ )
if ( V_44 -> V_86 >= V_77 -> V_86 && V_44 -> V_87 >= V_77 -> V_87 )
break;
if ( V_77 >= V_25 -> V_79 -> V_85 + V_80 )
V_77 -- ;
if ( V_75 != NULL )
* V_75 = V_77 ;
V_44 -> V_86 = V_77 -> V_86 ;
V_44 -> V_87 = V_77 -> V_87 ;
V_44 -> V_88 = V_70 [ V_66 ] . V_88 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_71 * V_44 )
{
return F_26 ( V_3 , V_44 , NULL , NULL ) ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_71 * V_44 )
{
struct V_72 * V_89 ;
struct V_74 * V_77 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned char V_90 ;
int V_12 ;
V_12 = F_26 ( V_3 , V_44 , & V_89 , & V_77 ) ;
if ( V_12 )
return V_12 ;
V_90 = V_89 -> V_91 [ 0 ] . V_9 ;
V_90 |= V_77 -> V_92 ;
F_15 ( V_3 , V_13 , V_90 ) ;
F_16 ( V_3 , V_89 -> V_91 + 1 ) ;
F_24 ( V_3 , V_77 -> V_56 , V_77 -> V_57 , V_77 -> V_58 ,
V_77 -> V_59 ) ;
V_12 = 0 ;
if ( V_77 -> V_91 )
V_12 = F_16 ( V_3 , V_77 -> V_91 ) ;
V_25 -> V_44 = V_89 ;
if ( V_12 == 0 )
V_12 = F_15 ( V_3 , V_55 , V_25 -> V_40 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_93 * V_94 )
{
struct V_95 * V_96 = & V_94 -> V_97 . V_98 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_94 -> type != V_99 )
return - V_69 ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
V_96 -> V_100 = V_101 ;
V_25 -> V_79 -> V_102 ( V_3 , & V_96 -> V_103 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_93 * V_94 )
{
struct V_95 * V_96 = & V_94 -> V_97 . V_98 ;
struct V_38 * V_39 = & V_96 -> V_103 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( V_94 -> type != V_99 )
return - V_69 ;
if ( V_96 -> V_104 != 0 )
return - V_69 ;
return V_25 -> V_79 -> V_105 ( V_3 , V_39 ) ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_106 * V_107 )
{
if ( V_107 -> V_66 >= F_32 ( V_108 ) )
return - V_69 ;
V_107 -> type = V_109 ;
V_107 -> V_110 . V_47 = 1 ;
V_107 -> V_110 . V_48 = V_108 [ V_107 -> V_66 ] ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_111 * V_112 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_76 ;
int V_113 = - 1 ;
T_3 V_66 = V_112 -> V_66 ;
unsigned int V_78 = V_25 -> V_79 -> V_78 ;
for ( V_76 = 0 ; V_76 < V_78 ; V_76 ++ ) {
struct V_74 * V_114 = & V_25 -> V_79 -> V_85 [ V_76 ] ;
if ( V_25 -> V_83 && V_114 -> V_86 < V_25 -> V_83 )
continue;
if ( V_25 -> V_84 && V_114 -> V_87 < V_25 -> V_84 )
continue;
if ( V_66 == ++ V_113 ) {
V_112 -> type = V_115 ;
V_112 -> V_110 . V_86 = V_114 -> V_86 ;
V_112 -> V_110 . V_87 = V_114 -> V_87 ;
return 0 ;
}
}
return - V_69 ;
}
static int F_34 ( struct V_2 * V_3 ,
int V_116 [ V_117 ] )
{
int V_76 , V_12 ;
unsigned char V_118 = 0 ;
V_12 = F_14 ( V_3 , V_119 , & V_118 ) ;
V_118 &= 0xc0 ;
for ( V_76 = 0 ; V_76 < V_117 ; V_76 ++ ) {
unsigned char V_120 ;
if ( V_116 [ V_76 ] < 0 ) {
V_118 |= ( 1 << V_76 ) ;
if ( V_116 [ V_76 ] < - 255 )
V_120 = 0xff ;
else
V_120 = ( - 1 * V_116 [ V_76 ] ) & 0xff ;
}
else {
if ( V_116 [ V_76 ] > 255 )
V_120 = 0xff ;
else
V_120 = V_116 [ V_76 ] & 0xff ;
}
V_12 += F_15 ( V_3 , V_121 + V_76 , V_120 ) ;
}
V_12 += F_15 ( V_3 , V_119 , V_118 ) ;
return V_12 ;
}
static int F_35 ( int V_122 )
{
int V_123 = 1 ;
int V_124 ;
if ( V_122 < 0 ) {
V_122 = - V_122 ;
V_123 = - 1 ;
}
if ( V_122 <= 90 )
V_124 = V_125 [ V_122 / V_126 ] ;
else {
V_122 -= 90 ;
V_124 = 1000 - V_125 [ V_122 / V_126 ] ;
}
return V_124 * V_123 ;
}
static int F_36 ( int V_122 )
{
V_122 = 90 - V_122 ;
if ( V_122 > 180 )
V_122 -= 360 ;
else if ( V_122 < - 180 )
V_122 += 360 ;
return F_35 ( V_122 ) ;
}
static void F_37 ( struct V_1 * V_25 ,
int V_116 [ V_117 ] , int V_127 , int V_128 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_117 ; V_76 ++ )
V_116 [ V_76 ] = ( V_25 -> V_44 -> V_129 [ V_76 ] * V_127 ) >> 7 ;
if ( V_128 != 0 ) {
int V_130 , V_131 , V_132 [ V_117 ] ;
memcpy ( V_132 , V_116 , V_117 * sizeof( int ) ) ;
V_130 = F_35 ( V_128 ) ;
V_131 = F_36 ( V_128 ) ;
V_116 [ 0 ] = ( V_116 [ 3 ] * V_130 + V_116 [ 0 ] * V_131 ) / 1000 ;
V_116 [ 1 ] = ( V_116 [ 4 ] * V_130 + V_116 [ 1 ] * V_131 ) / 1000 ;
V_116 [ 2 ] = ( V_116 [ 5 ] * V_130 + V_116 [ 2 ] * V_131 ) / 1000 ;
V_116 [ 3 ] = ( V_116 [ 3 ] * V_131 - V_116 [ 0 ] * V_130 ) / 1000 ;
V_116 [ 4 ] = ( V_116 [ 4 ] * V_131 - V_116 [ 1 ] * V_130 ) / 1000 ;
V_116 [ 5 ] = ( V_116 [ 5 ] * V_131 - V_116 [ 2 ] * V_130 ) / 1000 ;
}
}
static int F_38 ( struct V_2 * V_3 , int V_127 , int V_128 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_116 [ V_117 ] ;
int V_12 ;
F_37 ( V_25 , V_116 , V_127 , V_128 ) ;
V_12 = F_34 ( V_3 , V_116 ) ;
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
unsigned char V_133 = 0 , V_32 ;
int V_12 ;
F_14 ( V_3 , V_134 , & V_133 ) ;
V_133 &= ~ V_135 ;
F_15 ( V_3 , V_134 , V_133 ) ;
V_32 = F_39 ( V_9 ) ;
V_12 = F_15 ( V_3 , V_136 , V_32 ) ;
return V_12 ;
}
static int F_41 ( struct V_2 * V_3 , int V_9 )
{
return F_15 ( V_3 , V_137 , ( unsigned char ) V_9 ) ;
}
static int F_42 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_32 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_138 , & V_32 ) ;
if ( V_9 )
V_32 |= V_139 ;
else
V_32 &= ~ V_139 ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_138 , V_32 ) ;
return V_12 ;
}
static int F_43 ( struct V_2 * V_3 , int V_9 )
{
unsigned char V_32 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_138 , & V_32 ) ;
if ( V_9 )
V_32 |= V_140 ;
else
V_32 &= ~ V_140 ;
F_9 ( 10 ) ;
V_12 += F_15 ( V_3 , V_138 , V_32 ) ;
return V_12 ;
}
static int F_44 ( struct V_2 * V_3 , T_4 * V_9 )
{
int V_12 ;
unsigned char V_141 ;
V_12 = F_14 ( V_3 , V_142 , & V_141 ) ;
* V_9 = V_141 ;
return V_12 ;
}
static int F_45 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_133 ;
V_12 = F_15 ( V_3 , V_142 , V_9 & 0xff ) ;
if ( V_12 == 0 ) {
V_12 = F_14 ( V_3 , V_134 , & V_133 ) ;
V_12 = F_15 ( V_3 , V_134 , V_133 & ~ V_143 ) ;
}
return V_12 ;
}
static int F_46 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_133 ;
V_12 = F_14 ( V_3 , V_134 , & V_133 ) ;
if ( V_12 == 0 ) {
if ( V_9 )
V_133 |= V_143 ;
else
V_133 &= ~ V_143 ;
V_12 = F_15 ( V_3 , V_134 , V_133 ) ;
}
return V_12 ;
}
static int F_47 ( struct V_2 * V_3 , int V_9 )
{
int V_12 ;
unsigned char V_144 , V_133 , V_145 , V_146 ;
V_12 = F_14 ( V_3 , V_147 , & V_144 ) +
F_14 ( V_3 , V_134 , & V_133 ) ;
F_14 ( V_3 , V_148 , & V_146 ) ;
if ( V_12 )
return V_12 ;
V_144 = ( V_144 & 0xfc ) | ( V_9 & 0x03 ) ;
V_145 = ( V_9 >> 2 ) & 0xff ;
V_146 = ( V_146 & 0xc0 ) | ( ( V_9 >> 10 ) & 0x3f ) ;
V_12 = F_15 ( V_3 , V_147 , V_144 ) +
F_15 ( V_3 , V_149 , V_145 ) +
F_15 ( V_3 , V_148 , V_146 ) ;
if ( V_12 == 0 )
V_12 = F_15 ( V_3 , V_134 , V_133 & ~ V_135 ) ;
return V_12 ;
}
static int F_48 ( struct V_2 * V_3 ,
enum V_150 V_9 )
{
int V_12 ;
unsigned char V_133 ;
V_12 = F_14 ( V_3 , V_134 , & V_133 ) ;
if ( V_12 == 0 ) {
if ( V_9 == V_151 )
V_133 |= V_135 ;
else
V_133 &= ~ V_135 ;
V_12 = F_15 ( V_3 , V_134 , V_133 ) ;
}
return V_12 ;
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
switch ( V_5 -> V_152 ) {
case V_153 :
return F_44 ( V_3 , & V_25 -> V_141 -> V_30 ) ;
}
return - V_69 ;
}
static int F_50 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
switch ( V_5 -> V_152 ) {
case V_154 :
return F_40 ( V_3 , V_5 -> V_30 ) ;
case V_155 :
return F_41 ( V_3 , V_5 -> V_30 ) ;
case V_156 :
return F_38 ( V_3 ,
V_25 -> V_157 -> V_30 , V_25 -> V_128 -> V_30 ) ;
case V_158 :
return F_43 ( V_3 , V_5 -> V_30 ) ;
case V_159 :
return F_42 ( V_3 , V_5 -> V_30 ) ;
case V_153 :
if ( ! V_5 -> V_30 ) {
return F_45 ( V_3 , V_25 -> V_141 -> V_30 ) ;
}
return F_46 ( V_3 , V_5 -> V_30 ) ;
case V_160 :
if ( V_5 -> V_30 == V_161 ) {
return F_47 ( V_3 , V_25 -> V_162 -> V_30 ) ;
}
return F_48 ( V_3 , V_5 -> V_30 ) ;
}
return - V_69 ;
}
static int F_51 ( struct V_2 * V_3 , struct V_163 * V_8 )
{
unsigned char V_30 = 0 ;
int V_12 ;
V_12 = F_14 ( V_3 , V_8 -> V_8 & 0xff , & V_30 ) ;
V_8 -> V_30 = V_30 ;
V_8 -> V_164 = 1 ;
return V_12 ;
}
static int F_52 ( struct V_2 * V_3 , const struct V_163 * V_8 )
{
F_15 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_30 & 0xff ) ;
return 0 ;
}
static int F_53 ( struct V_10 * V_11 ,
const struct V_165 * V_152 )
{
struct V_38 V_39 ;
struct V_2 * V_3 ;
struct V_1 * V_25 ;
int V_12 ;
V_25 = F_54 ( & V_11 -> V_166 , sizeof( * V_25 ) , V_167 ) ;
if ( V_25 == NULL )
return - V_168 ;
V_3 = & V_25 -> V_3 ;
F_55 ( V_3 , V_11 , & V_169 ) ;
V_25 -> V_49 = 30 ;
if ( V_11 -> V_166 . V_170 ) {
struct V_171 * V_172 = V_11 -> V_166 . V_170 ;
V_25 -> V_83 = V_172 -> V_83 ;
V_25 -> V_84 = V_172 -> V_84 ;
V_25 -> V_26 = V_172 -> V_26 ;
if ( V_172 -> V_49 )
V_25 -> V_49 = V_172 -> V_49 ;
if ( V_172 -> V_42 && V_152 -> V_173 != V_174 )
V_25 -> V_42 = true ;
if ( V_172 -> V_175 )
V_25 -> V_175 = true ;
}
V_12 = F_19 ( V_3 ) ;
if ( V_12 ) {
F_56 ( 1 , V_176 , V_11 ,
L_2 ,
V_11 -> V_18 << 1 , V_11 -> V_22 -> V_177 ) ;
return V_12 ;
}
F_57 ( V_11 , L_3 ,
V_11 -> V_18 << 1 , V_11 -> V_22 -> V_177 ) ;
V_25 -> V_79 = & V_178 [ V_152 -> V_173 ] ;
V_25 -> V_44 = & V_70 [ 0 ] ;
V_25 -> V_40 = 0 ;
V_39 . V_47 = 1 ;
V_39 . V_48 = 30 ;
V_25 -> V_79 -> V_105 ( V_3 , & V_39 ) ;
if ( V_25 -> V_175 )
F_15 ( V_3 , V_179 , V_180 ) ;
F_58 ( & V_25 -> V_7 , 10 ) ;
F_59 ( & V_25 -> V_7 , & V_181 ,
V_154 , 0 , 255 , 1 , 128 ) ;
F_59 ( & V_25 -> V_7 , & V_181 ,
V_155 , 0 , 127 , 1 , 64 ) ;
F_59 ( & V_25 -> V_7 , & V_181 ,
V_158 , 0 , 1 , 1 , 0 ) ;
F_59 ( & V_25 -> V_7 , & V_181 ,
V_159 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_157 = F_59 ( & V_25 -> V_7 , & V_181 ,
V_156 , 0 , 256 , 1 , 128 ) ;
V_25 -> V_128 = F_59 ( & V_25 -> V_7 , & V_181 ,
V_182 , - 180 , 180 , 5 , 0 ) ;
V_25 -> V_141 = F_59 ( & V_25 -> V_7 , & V_181 ,
V_183 , 0 , 255 , 1 , 128 ) ;
V_25 -> V_184 = F_59 ( & V_25 -> V_7 , & V_181 ,
V_153 , 0 , 1 , 1 , 1 ) ;
V_25 -> V_162 = F_59 ( & V_25 -> V_7 , & V_181 ,
V_185 , 0 , 65535 , 1 , 500 ) ;
V_25 -> V_186 = F_60 ( & V_25 -> V_7 , & V_181 ,
V_160 , V_161 , 0 ,
V_151 ) ;
V_3 -> V_187 = & V_25 -> V_7 ;
if ( V_25 -> V_7 . error ) {
int V_188 = V_25 -> V_7 . error ;
F_61 ( & V_25 -> V_7 ) ;
return V_188 ;
}
F_62 ( 2 , & V_25 -> V_184 , 0 , true ) ;
F_62 ( 2 , & V_25 -> V_186 ,
V_161 , false ) ;
F_63 ( 2 , & V_25 -> V_157 ) ;
F_64 ( & V_25 -> V_7 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_66 ( V_11 ) ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_67 ( V_3 ) ;
F_61 ( & V_25 -> V_7 ) ;
return 0 ;
}
