static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned char V_4 ,
unsigned char * V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_8 ;
V_8 = F_5 ( V_7 , V_4 ) ;
if ( V_8 >= 0 ) {
* V_5 = ( unsigned char ) V_8 ;
V_8 = 0 ;
}
return V_8 ;
}
static int F_6 ( struct V_2 * V_3 , unsigned char V_4 ,
unsigned char V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_8 = F_7 ( V_7 , V_4 , V_5 ) ;
if ( V_4 == V_9 && ( V_5 & V_10 ) )
F_8 ( 5 ) ;
return V_8 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned char V_4 ,
unsigned char * V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
T_1 V_11 = V_4 ;
struct V_12 V_13 ;
int V_8 ;
V_13 . V_14 = V_7 -> V_14 ;
V_13 . V_15 = 0 ;
V_13 . V_16 = 1 ;
V_13 . V_17 = & V_11 ;
V_8 = F_10 ( V_7 -> V_18 , & V_13 , 1 ) ;
if ( V_8 < 0 ) {
F_11 ( V_19 L_1 , V_8 ) ;
return V_8 ;
}
V_13 . V_15 = V_20 ;
V_8 = F_10 ( V_7 -> V_18 , & V_13 , 1 ) ;
if ( V_8 >= 0 ) {
* V_5 = V_11 ;
V_8 = 0 ;
}
return V_8 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned char V_4 ,
unsigned char V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_12 V_13 ;
unsigned char V_11 [ 2 ] = { V_4 , V_5 } ;
int V_8 ;
V_13 . V_14 = V_7 -> V_14 ;
V_13 . V_15 = 0 ;
V_13 . V_16 = 2 ;
V_13 . V_17 = V_11 ;
V_8 = F_10 ( V_7 -> V_18 , & V_13 , 1 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
if ( V_4 == V_9 && ( V_5 & V_10 ) )
F_8 ( 5 ) ;
return V_8 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned char V_4 ,
unsigned char * V_5 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_21 -> V_22 )
return F_3 ( V_3 , V_4 , V_5 ) ;
else
return F_9 ( V_3 , V_4 , V_5 ) ;
}
static int F_14 ( struct V_2 * V_3 , unsigned char V_4 ,
unsigned char V_5 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_21 -> V_22 )
return F_6 ( V_3 , V_4 , V_5 ) ;
else
return F_12 ( V_3 , V_4 , V_5 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
while ( V_24 -> V_25 != 0xff || V_24 -> V_5 != 0xff ) {
int V_8 = F_14 ( V_3 , V_24 -> V_25 , V_24 -> V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
V_24 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , T_2 V_26 )
{
F_14 ( V_3 , V_9 , V_10 ) ;
F_8 ( 1 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , T_2 V_26 )
{
return F_15 ( V_3 , V_27 ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
unsigned char V_28 ;
int V_8 ;
V_8 = F_17 ( V_3 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_13 ( V_3 , V_29 , & V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_28 != 0x7f )
return - V_30 ;
V_8 = F_13 ( V_3 , V_31 , & V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_28 != 0xa2 )
return - V_30 ;
V_8 = F_13 ( V_3 , V_32 , & V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_28 != 0x76 )
return - V_30 ;
V_8 = F_13 ( V_3 , V_33 , & V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_28 != 0x73 )
return - V_30 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , int V_34 , int V_35 ,
int V_36 , int V_37 )
{
int V_8 ;
unsigned char V_28 ;
V_8 = F_14 ( V_3 , V_38 , ( V_34 >> 3 ) & 0xff ) ;
V_8 += F_14 ( V_3 , V_39 , ( V_35 >> 3 ) & 0xff ) ;
V_8 += F_13 ( V_3 , V_40 , & V_28 ) ;
V_28 = ( V_28 & 0xc0 ) | ( ( V_35 & 0x7 ) << 3 ) | ( V_34 & 0x7 ) ;
F_8 ( 10 ) ;
V_8 += F_14 ( V_3 , V_40 , V_28 ) ;
V_8 += F_14 ( V_3 , V_41 , ( V_36 >> 2 ) & 0xff ) ;
V_8 += F_14 ( V_3 , V_42 , ( V_37 >> 2 ) & 0xff ) ;
V_8 += F_13 ( V_3 , V_43 , & V_28 ) ;
V_28 = ( V_28 & 0xf0 ) | ( ( V_37 & 0x3 ) << 2 ) | ( V_36 & 0x3 ) ;
F_8 ( 10 ) ;
V_8 += F_14 ( V_3 , V_43 , V_28 ) ;
return V_8 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_44 ,
enum V_45 * V_46 )
{
if ( V_44 >= V_47 )
return - V_48 ;
* V_46 = V_49 [ V_44 ] . V_50 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_53 * * V_54 ,
struct V_55 * * V_56 )
{
int V_44 ;
struct V_55 * V_57 ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ )
if ( V_49 [ V_44 ] . V_50 == V_52 -> V_46 )
break;
if ( V_44 >= V_47 ) {
V_44 = 0 ;
V_52 -> V_46 = V_49 [ 0 ] . V_50 ;
}
if ( V_54 != NULL )
* V_54 = V_49 + V_44 ;
V_52 -> V_58 = V_59 ;
for ( V_57 = V_60 ; V_57 < V_60 + V_61 ;
V_57 ++ )
if ( V_52 -> V_62 >= V_57 -> V_62 && V_52 -> V_63 >= V_57 -> V_63 )
break;
if ( V_57 >= V_60 + V_61 )
V_57 -- ;
if ( V_56 != NULL )
* V_56 = V_57 ;
V_52 -> V_62 = V_57 -> V_62 ;
V_52 -> V_63 = V_57 -> V_63 ;
V_52 -> V_64 = V_49 [ V_44 ] . V_64 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
return F_21 ( V_3 , V_52 , NULL , NULL ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_53 * V_65 ;
struct V_55 * V_57 ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
unsigned char V_66 ;
int V_8 ;
V_8 = F_21 ( V_3 , V_52 , & V_65 , & V_57 ) ;
if ( V_8 )
return V_8 ;
V_66 = V_65 -> V_67 [ 0 ] . V_5 ;
V_66 |= V_57 -> V_68 ;
F_14 ( V_3 , V_9 , V_66 ) ;
F_15 ( V_3 , V_65 -> V_67 + 1 ) ;
F_19 ( V_3 , V_57 -> V_34 , V_57 -> V_35 , V_57 -> V_36 ,
V_57 -> V_37 ) ;
V_8 = 0 ;
if ( V_57 -> V_67 )
V_8 = F_15 ( V_3 , V_57 -> V_67 ) ;
V_21 -> V_52 = V_65 ;
if ( V_8 == 0 )
V_8 = F_14 ( V_3 , V_69 , V_21 -> V_70 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_75 . V_76 ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_72 -> type != V_77 )
return - V_48 ;
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 -> V_78 = V_79 ;
V_74 -> V_80 . V_81 = 1 ;
V_74 -> V_80 . V_82 = V_21 -> V_83 ;
if ( ( V_21 -> V_70 & V_84 ) == 0 && ( V_21 -> V_70 & V_85 ) > 1 )
V_74 -> V_80 . V_82 /= ( V_21 -> V_70 & V_85 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_75 . V_76 ;
struct V_86 * V_87 = & V_74 -> V_80 ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
int div ;
if ( V_72 -> type != V_77 )
return - V_48 ;
if ( V_74 -> V_88 != 0 )
return - V_48 ;
if ( V_87 -> V_81 == 0 || V_87 -> V_82 == 0 )
div = 1 ;
else
div = ( V_87 -> V_81 * V_21 -> V_83 ) / V_87 -> V_82 ;
if ( div == 0 )
div = 1 ;
else if ( div > V_85 )
div = V_85 ;
V_21 -> V_70 = ( V_21 -> V_70 & 0x80 ) | div ;
V_87 -> V_81 = 1 ;
V_87 -> V_82 = V_21 -> V_83 / div ;
return F_14 ( V_3 , V_69 , V_21 -> V_70 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_89 * V_90 )
{
if ( V_90 -> V_44 >= F_27 ( V_91 ) )
return - V_48 ;
V_90 -> type = V_92 ;
V_90 -> V_93 . V_81 = 1 ;
V_90 -> V_93 . V_82 = V_91 [ V_90 -> V_44 ] ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_94 * V_95 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_96 ;
int V_97 = - 1 ;
T_3 V_44 = V_95 -> V_44 ;
for ( V_96 = 0 ; V_96 < V_61 ; V_96 ++ ) {
struct V_55 * V_98 = & V_60 [ V_44 ] ;
if ( V_21 -> V_99 && V_98 -> V_62 < V_21 -> V_99 )
continue;
if ( V_21 -> V_100 && V_98 -> V_63 < V_21 -> V_100 )
continue;
if ( V_44 == ++ V_97 ) {
V_95 -> type = V_101 ;
V_95 -> V_93 . V_62 = V_98 -> V_62 ;
V_95 -> V_93 . V_63 = V_98 -> V_63 ;
return 0 ;
}
}
return - V_48 ;
}
static int F_29 ( struct V_2 * V_3 ,
int V_102 [ V_103 ] )
{
int V_96 , V_8 ;
unsigned char V_104 = 0 ;
V_8 = F_13 ( V_3 , V_105 , & V_104 ) ;
V_104 &= 0xc0 ;
for ( V_96 = 0 ; V_96 < V_103 ; V_96 ++ ) {
unsigned char V_106 ;
if ( V_102 [ V_96 ] < 0 ) {
V_104 |= ( 1 << V_96 ) ;
if ( V_102 [ V_96 ] < - 255 )
V_106 = 0xff ;
else
V_106 = ( - 1 * V_102 [ V_96 ] ) & 0xff ;
}
else {
if ( V_102 [ V_96 ] > 255 )
V_106 = 0xff ;
else
V_106 = V_102 [ V_96 ] & 0xff ;
}
V_8 += F_14 ( V_3 , V_107 + V_96 , V_106 ) ;
}
V_8 += F_14 ( V_3 , V_105 , V_104 ) ;
return V_8 ;
}
static int F_30 ( int V_108 )
{
int V_109 = 1 ;
int V_110 ;
if ( V_108 < 0 ) {
V_108 = - V_108 ;
V_109 = - 1 ;
}
if ( V_108 <= 90 )
V_110 = V_111 [ V_108 / V_112 ] ;
else {
V_108 -= 90 ;
V_110 = 1000 - V_111 [ V_108 / V_112 ] ;
}
return V_110 * V_109 ;
}
static int F_31 ( int V_108 )
{
V_108 = 90 - V_108 ;
if ( V_108 > 180 )
V_108 -= 360 ;
else if ( V_108 < - 180 )
V_108 += 360 ;
return F_30 ( V_108 ) ;
}
static void F_32 ( struct V_1 * V_21 ,
int V_102 [ V_103 ] )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_103 ; V_96 ++ )
V_102 [ V_96 ] = ( V_21 -> V_52 -> V_113 [ V_96 ] * V_21 -> V_114 ) >> 7 ;
if ( V_21 -> V_115 != 0 ) {
int V_116 , V_117 , V_118 [ V_103 ] ;
memcpy ( V_118 , V_102 , V_103 * sizeof( int ) ) ;
V_116 = F_30 ( V_21 -> V_115 ) ;
V_117 = F_31 ( V_21 -> V_115 ) ;
V_102 [ 0 ] = ( V_102 [ 3 ] * V_116 + V_102 [ 0 ] * V_117 ) / 1000 ;
V_102 [ 1 ] = ( V_102 [ 4 ] * V_116 + V_102 [ 1 ] * V_117 ) / 1000 ;
V_102 [ 2 ] = ( V_102 [ 5 ] * V_116 + V_102 [ 2 ] * V_117 ) / 1000 ;
V_102 [ 3 ] = ( V_102 [ 3 ] * V_117 - V_102 [ 0 ] * V_116 ) / 1000 ;
V_102 [ 4 ] = ( V_102 [ 4 ] * V_117 - V_102 [ 1 ] * V_116 ) / 1000 ;
V_102 [ 5 ] = ( V_102 [ 5 ] * V_117 - V_102 [ 2 ] * V_116 ) / 1000 ;
}
}
static int F_33 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_102 [ V_103 ] ;
int V_8 ;
V_21 -> V_114 = V_5 ;
F_32 ( V_21 , V_102 ) ;
V_8 = F_29 ( V_3 , V_102 ) ;
return V_8 ;
}
static int F_34 ( struct V_2 * V_3 , T_4 * V_5 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
* V_5 = V_21 -> V_114 ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_102 [ V_103 ] ;
int V_8 ;
if ( V_5 < - 180 || V_5 > 180 )
return - V_48 ;
V_21 -> V_115 = V_5 ;
F_32 ( V_21 , V_102 ) ;
V_8 = F_29 ( V_3 , V_102 ) ;
return V_8 ;
}
static int F_36 ( struct V_2 * V_3 , T_4 * V_5 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
* V_5 = V_21 -> V_115 ;
return 0 ;
}
static unsigned char F_37 ( unsigned char V_28 )
{
if ( ( V_28 & 0x80 ) == 0 )
return V_28 + 128 ;
return 128 - ( V_28 & 0x7f ) ;
}
static unsigned char F_38 ( unsigned char V_28 )
{
if ( V_28 > 127 )
return V_28 & 0x7f ;
return ( 128 - V_28 ) | 0x80 ;
}
static int F_39 ( struct V_2 * V_3 , int V_5 )
{
unsigned char V_119 = 0 , V_28 ;
int V_8 ;
F_13 ( V_3 , V_120 , & V_119 ) ;
V_119 &= ~ V_121 ;
F_14 ( V_3 , V_120 , V_119 ) ;
V_28 = F_38 ( V_5 ) ;
V_8 = F_14 ( V_3 , V_122 , V_28 ) ;
return V_8 ;
}
static int F_40 ( struct V_2 * V_3 , T_4 * V_5 )
{
unsigned char V_28 = 0 ;
int V_8 = F_13 ( V_3 , V_122 , & V_28 ) ;
* V_5 = F_37 ( V_28 ) ;
return V_8 ;
}
static int F_41 ( struct V_2 * V_3 , int V_5 )
{
return F_14 ( V_3 , V_123 , ( unsigned char ) V_5 ) ;
}
static int F_42 ( struct V_2 * V_3 , T_4 * V_5 )
{
unsigned char V_28 = 0 ;
int V_8 = F_13 ( V_3 , V_123 , & V_28 ) ;
* V_5 = V_28 ;
return V_8 ;
}
static int F_43 ( struct V_2 * V_3 , T_4 * V_5 )
{
int V_8 ;
unsigned char V_28 = 0 ;
V_8 = F_13 ( V_3 , V_124 , & V_28 ) ;
* V_5 = ( V_28 & V_125 ) == V_125 ;
return V_8 ;
}
static int F_44 ( struct V_2 * V_3 , int V_5 )
{
unsigned char V_28 = 0 ;
int V_8 ;
V_8 = F_13 ( V_3 , V_124 , & V_28 ) ;
if ( V_5 )
V_28 |= V_125 ;
else
V_28 &= ~ V_125 ;
F_8 ( 10 ) ;
V_8 += F_14 ( V_3 , V_124 , V_28 ) ;
return V_8 ;
}
static int F_45 ( struct V_2 * V_3 , T_4 * V_5 )
{
int V_8 ;
unsigned char V_28 = 0 ;
V_8 = F_13 ( V_3 , V_124 , & V_28 ) ;
* V_5 = ( V_28 & V_126 ) == V_126 ;
return V_8 ;
}
static int F_46 ( struct V_2 * V_3 , int V_5 )
{
unsigned char V_28 = 0 ;
int V_8 ;
V_8 = F_13 ( V_3 , V_124 , & V_28 ) ;
if ( V_5 )
V_28 |= V_126 ;
else
V_28 &= ~ V_126 ;
F_8 ( 10 ) ;
V_8 += F_14 ( V_3 , V_124 , V_28 ) ;
return V_8 ;
}
static int F_47 ( struct V_2 * V_3 , T_4 * V_5 )
{
int V_8 ;
unsigned char V_127 ;
V_8 = F_13 ( V_3 , V_128 , & V_127 ) ;
* V_5 = V_127 ;
return V_8 ;
}
static int F_48 ( struct V_2 * V_3 , int V_5 )
{
int V_8 ;
unsigned char V_119 ;
V_8 = F_14 ( V_3 , V_128 , V_5 & 0xff ) ;
if ( V_8 == 0 ) {
V_8 = F_13 ( V_3 , V_120 , & V_119 ) ;
V_8 = F_14 ( V_3 , V_120 , V_119 & ~ V_129 ) ;
}
return V_8 ;
}
static int F_49 ( struct V_2 * V_3 , T_4 * V_5 )
{
int V_8 ;
unsigned char V_119 ;
V_8 = F_13 ( V_3 , V_120 , & V_119 ) ;
* V_5 = ( V_119 & V_129 ) != 0 ;
return V_8 ;
}
static int F_50 ( struct V_2 * V_3 , int V_5 )
{
int V_8 ;
unsigned char V_119 ;
V_8 = F_13 ( V_3 , V_120 , & V_119 ) ;
if ( V_8 == 0 ) {
if ( V_5 )
V_119 |= V_129 ;
else
V_119 &= ~ V_129 ;
V_8 = F_14 ( V_3 , V_120 , V_119 ) ;
}
return V_8 ;
}
static int F_51 ( struct V_2 * V_3 , T_4 * V_5 )
{
int V_8 ;
unsigned char V_130 , V_131 , V_132 ;
V_8 = F_13 ( V_3 , V_133 , & V_130 ) +
F_13 ( V_3 , V_134 , & V_131 ) +
F_13 ( V_3 , V_135 , & V_132 ) ;
* V_5 = ( ( V_132 & 0x3f ) << 10 ) | ( V_131 << 2 ) | ( V_130 & 0x03 ) ;
return V_8 ;
}
static int F_52 ( struct V_2 * V_3 , int V_5 )
{
int V_8 ;
unsigned char V_130 , V_119 , V_131 , V_132 ;
V_8 = F_13 ( V_3 , V_133 , & V_130 ) +
F_13 ( V_3 , V_120 , & V_119 ) ;
F_13 ( V_3 , V_135 , & V_132 ) ;
if ( V_8 )
return V_8 ;
V_130 = ( V_130 & 0xfc ) | ( V_5 & 0x03 ) ;
V_131 = ( V_5 >> 2 ) & 0xff ;
V_132 = ( V_132 & 0xc0 ) | ( ( V_5 >> 10 ) & 0x3f ) ;
V_8 = F_14 ( V_3 , V_133 , V_130 ) +
F_14 ( V_3 , V_134 , V_131 ) +
F_14 ( V_3 , V_135 , V_132 ) ;
if ( V_8 == 0 )
V_8 = F_14 ( V_3 , V_120 , V_119 & ~ V_121 ) ;
return V_8 ;
}
static int F_53 ( struct V_2 * V_3 , T_4 * V_5 )
{
int V_8 ;
unsigned char V_119 ;
enum V_136 * V_137 = (enum V_136 * ) V_5 ;
V_8 = F_13 ( V_3 , V_120 , & V_119 ) ;
if ( V_119 & V_121 )
* V_137 = V_138 ;
else
* V_137 = V_139 ;
return V_8 ;
}
static int F_54 ( struct V_2 * V_3 ,
enum V_136 V_5 )
{
int V_8 ;
unsigned char V_119 ;
V_8 = F_13 ( V_3 , V_120 , & V_119 ) ;
if ( V_8 == 0 ) {
if ( V_5 == V_138 )
V_119 |= V_121 ;
else
V_119 &= ~ V_121 ;
V_8 = F_14 ( V_3 , V_120 , V_119 ) ;
}
return V_8 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_140 * V_141 )
{
switch ( V_141 -> V_142 ) {
case V_143 :
return F_56 ( V_141 , 0 , 255 , 1 , 128 ) ;
case V_144 :
return F_56 ( V_141 , 0 , 127 , 1 , 64 ) ;
case V_145 :
case V_146 :
return F_56 ( V_141 , 0 , 1 , 1 , 0 ) ;
case V_147 :
return F_56 ( V_141 , 0 , 256 , 1 , 128 ) ;
case V_148 :
return F_56 ( V_141 , - 180 , 180 , 5 , 0 ) ;
case V_149 :
return F_56 ( V_141 , 0 , 255 , 1 , 128 ) ;
case V_150 :
return F_56 ( V_141 , 0 , 1 , 1 , 1 ) ;
case V_151 :
return F_56 ( V_141 , 0 , 65535 , 1 , 500 ) ;
case V_152 :
return F_56 ( V_141 , 0 , 1 , 1 , 0 ) ;
}
return - V_48 ;
}
static int F_57 ( struct V_2 * V_3 , struct V_153 * V_154 )
{
switch ( V_154 -> V_142 ) {
case V_143 :
return F_40 ( V_3 , & V_154 -> V_5 ) ;
case V_144 :
return F_42 ( V_3 , & V_154 -> V_5 ) ;
case V_147 :
return F_34 ( V_3 , & V_154 -> V_5 ) ;
case V_148 :
return F_36 ( V_3 , & V_154 -> V_5 ) ;
case V_145 :
return F_45 ( V_3 , & V_154 -> V_5 ) ;
case V_146 :
return F_43 ( V_3 , & V_154 -> V_5 ) ;
case V_149 :
return F_47 ( V_3 , & V_154 -> V_5 ) ;
case V_150 :
return F_49 ( V_3 , & V_154 -> V_5 ) ;
case V_151 :
return F_51 ( V_3 , & V_154 -> V_5 ) ;
case V_152 :
return F_53 ( V_3 , & V_154 -> V_5 ) ;
}
return - V_48 ;
}
static int F_58 ( struct V_2 * V_3 , struct V_153 * V_154 )
{
switch ( V_154 -> V_142 ) {
case V_143 :
return F_39 ( V_3 , V_154 -> V_5 ) ;
case V_144 :
return F_41 ( V_3 , V_154 -> V_5 ) ;
case V_147 :
return F_33 ( V_3 , V_154 -> V_5 ) ;
case V_148 :
return F_35 ( V_3 , V_154 -> V_5 ) ;
case V_145 :
return F_46 ( V_3 , V_154 -> V_5 ) ;
case V_146 :
return F_44 ( V_3 , V_154 -> V_5 ) ;
case V_149 :
return F_48 ( V_3 , V_154 -> V_5 ) ;
case V_150 :
return F_50 ( V_3 , V_154 -> V_5 ) ;
case V_151 :
return F_52 ( V_3 , V_154 -> V_5 ) ;
case V_152 :
return F_54 ( V_3 ,
(enum V_136 ) V_154 -> V_5 ) ;
}
return - V_48 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_155 * V_156 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_60 ( V_7 , V_156 , V_157 , 0 ) ;
}
static int F_61 ( struct V_2 * V_3 , struct V_158 * V_4 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
unsigned char V_26 = 0 ;
int V_8 ;
if ( ! F_62 ( V_7 , & V_4 -> V_159 ) )
return - V_48 ;
if ( ! F_63 ( V_160 ) )
return - V_161 ;
V_8 = F_13 ( V_3 , V_4 -> V_4 & 0xff , & V_26 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_162 = 1 ;
return V_8 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_158 * V_4 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
if ( ! F_62 ( V_7 , & V_4 -> V_159 ) )
return - V_48 ;
if ( ! F_63 ( V_160 ) )
return - V_161 ;
F_14 ( V_3 , V_4 -> V_4 & 0xff , V_4 -> V_26 & 0xff ) ;
return 0 ;
}
static int F_65 ( struct V_6 * V_7 ,
const struct V_163 * V_142 )
{
struct V_2 * V_3 ;
struct V_1 * V_21 ;
int V_8 ;
V_21 = F_66 ( sizeof( struct V_1 ) , V_164 ) ;
if ( V_21 == NULL )
return - V_165 ;
V_3 = & V_21 -> V_3 ;
F_67 ( V_3 , V_7 , & V_166 ) ;
V_21 -> V_83 = 30 ;
if ( V_7 -> V_167 . V_168 ) {
struct V_169 * V_170 = V_7 -> V_167 . V_168 ;
V_21 -> V_99 = V_170 -> V_99 ;
V_21 -> V_100 = V_170 -> V_100 ;
V_21 -> V_22 = V_170 -> V_22 ;
if ( V_170 -> V_83 )
V_21 -> V_83 = V_170 -> V_83 ;
}
V_8 = F_18 ( V_3 ) ;
if ( V_8 ) {
F_68 ( 1 , V_171 , V_7 ,
L_2 ,
V_7 -> V_14 << 1 , V_7 -> V_18 -> V_172 ) ;
F_69 ( V_21 ) ;
return V_8 ;
}
F_70 ( V_7 , L_3 ,
V_7 -> V_14 << 1 , V_7 -> V_18 -> V_172 ) ;
V_21 -> V_52 = & V_49 [ 0 ] ;
V_21 -> V_114 = 128 ;
V_21 -> V_70 = V_21 -> V_83 / 30 ;
return 0 ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_72 ( V_7 ) ;
F_73 ( V_3 ) ;
F_69 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_5 int F_74 ( void )
{
return F_75 ( & V_173 ) ;
}
static T_6 void F_76 ( void )
{
F_77 ( & V_173 ) ;
}
