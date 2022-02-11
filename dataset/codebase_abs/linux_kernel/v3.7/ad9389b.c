static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
return F_6 ( V_10 , V_8 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_11 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
int V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_12 = F_8 ( V_10 , V_8 , V_11 ) ;
if ( V_12 == 0 )
return 0 ;
}
F_9 ( V_3 , L_1 ) ;
return V_12 ;
}
static inline void F_10 ( struct V_2 * V_3 , T_1 V_8 ,
T_1 V_14 , T_1 V_15 )
{
F_7 ( V_3 , V_8 , ( F_4 ( V_3 , V_8 ) & V_14 ) | V_15 ) ;
}
static void F_11 ( struct V_2 * V_3 , T_2 V_16 , T_1 * V_17 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_13 ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ )
V_17 [ V_13 ] = F_6 ( V_18 -> V_21 , V_13 ) ;
}
static inline bool F_13 ( struct V_2 * V_3 )
{
return F_4 ( V_3 , 0x42 ) & V_22 ;
}
static inline bool F_14 ( struct V_2 * V_3 )
{
return F_4 ( V_3 , 0x42 ) & V_23 ;
}
static void F_15 ( struct V_2 * V_3 , T_1 V_24 )
{
F_10 ( V_3 , 0x17 , 0xe7 , ( V_24 & 0x3 ) << 3 ) ;
F_10 ( V_3 , 0x18 , 0x9f , ( V_24 & 0x3 ) << 5 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
T_2 V_25 , T_2 V_26 , T_2 V_27 , T_2 V_28 ,
T_2 V_29 , T_2 V_30 , T_2 V_31 , T_2 V_32 ,
T_2 V_33 , T_2 V_34 , T_2 V_35 , T_2 V_36 )
{
F_10 ( V_3 , 0x18 , 0xe0 , V_25 >> 8 ) ;
F_7 ( V_3 , 0x19 , V_25 ) ;
F_10 ( V_3 , 0x1A , 0xe0 , V_26 >> 8 ) ;
F_7 ( V_3 , 0x1B , V_26 ) ;
F_10 ( V_3 , 0x1c , 0xe0 , V_27 >> 8 ) ;
F_7 ( V_3 , 0x1d , V_27 ) ;
F_10 ( V_3 , 0x1e , 0xe0 , V_28 >> 8 ) ;
F_7 ( V_3 , 0x1f , V_28 ) ;
F_10 ( V_3 , 0x20 , 0xe0 , V_29 >> 8 ) ;
F_7 ( V_3 , 0x21 , V_29 ) ;
F_10 ( V_3 , 0x22 , 0xe0 , V_30 >> 8 ) ;
F_7 ( V_3 , 0x23 , V_30 ) ;
F_10 ( V_3 , 0x24 , 0xe0 , V_31 >> 8 ) ;
F_7 ( V_3 , 0x25 , V_31 ) ;
F_10 ( V_3 , 0x26 , 0xe0 , V_32 >> 8 ) ;
F_7 ( V_3 , 0x27 , V_32 ) ;
F_10 ( V_3 , 0x28 , 0xe0 , V_33 >> 8 ) ;
F_7 ( V_3 , 0x29 , V_33 ) ;
F_10 ( V_3 , 0x2A , 0xe0 , V_34 >> 8 ) ;
F_7 ( V_3 , 0x2B , V_34 ) ;
F_10 ( V_3 , 0x2C , 0xe0 , V_35 >> 8 ) ;
F_7 ( V_3 , 0x2D , V_35 ) ;
F_10 ( V_3 , 0x2E , 0xe0 , V_36 >> 8 ) ;
F_7 ( V_3 , 0x2F , V_36 ) ;
}
static void F_17 ( struct V_2 * V_3 , bool V_37 )
{
if ( V_37 ) {
T_1 V_38 = 0 ;
F_15 ( V_3 , V_38 ) ;
F_16 ( V_3 ,
4096 - 564 , 0 , 0 , 256 ,
0 , 4096 - 564 , 0 , 256 ,
0 , 0 , 4096 - 564 , 256 ) ;
F_10 ( V_3 , 0x3b , 0xfe , 0x1 ) ;
F_10 ( V_3 , 0xcd , 0xf9 , 0x02 ) ;
} else {
F_10 ( V_3 , 0x3b , 0xfe , 0x0 ) ;
F_10 ( V_3 , 0xcd , 0xf9 , 0x04 ) ;
}
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
if ( V_18 -> V_39 . V_40 . V_41 & V_42 ) {
F_10 ( V_3 , 0xcd , 0xbf , 0x00 ) ;
} else {
F_10 ( V_3 , 0xcd , 0xbf , 0x40 ) ;
}
}
static int F_19 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
switch ( V_5 -> V_11 ) {
case V_43 :
if ( V_18 -> V_39 . V_40 . V_41 & V_42 ) {
F_17 ( V_3 , true ) ;
} else {
F_17 ( V_3 , false ) ;
}
break;
case V_44 :
F_17 ( V_3 , true ) ;
break;
case V_45 :
F_17 ( V_3 , false ) ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_20 ( struct V_2 * V_3 , T_3 V_47 )
{
T_1 V_48 ;
if ( V_47 > 140000000 )
V_48 = 0xc0 ;
else if ( V_47 > 117000000 )
V_48 = 0xb0 ;
else if ( V_47 > 87000000 )
V_48 = 0xa0 ;
else if ( V_47 > 60000000 )
V_48 = 0x90 ;
else
V_48 = 0x80 ;
F_10 ( V_3 , 0x98 , 0x0f , V_48 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 ,
L_3 , V_20 , V_5 -> V_49 , V_5 -> V_11 ) ;
if ( V_18 -> V_50 == V_5 ) {
F_10 ( V_3 , 0xaf , 0xfd ,
V_5 -> V_11 == V_51 ? 0x02 : 0x00 ) ;
return 0 ;
}
if ( V_18 -> V_52 == V_5 )
return F_19 ( V_3 , V_5 ) ;
return - V_46 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_53 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
if ( ! F_23 ( V_10 , & V_8 -> V_54 ) )
return - V_46 ;
if ( ! F_24 ( V_55 ) )
return - V_56 ;
V_8 -> V_11 = F_4 ( V_3 , V_8 -> V_8 & 0xff ) ;
V_8 -> V_57 = 1 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_53 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
if ( ! F_23 ( V_10 , & V_8 -> V_54 ) )
return - V_46 ;
if ( ! F_24 ( V_55 ) )
return - V_56 ;
F_7 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_11 & 0xff ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
return F_27 ( V_10 , V_59 , V_60 , 0 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_61 * V_62 = & V_18 -> V_62 ;
static const char * const V_63 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 , L_11 , L_12 , L_13 , L_14 , L_15 , L_16 , L_17 , L_18 , L_19
} ;
static const char * const V_64 [] = {
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_13 , L_14 , L_15 , L_16 , L_17 , L_18 , L_19
} ;
T_1 V_65 ;
F_29 ( V_3 , L_29 , V_18 -> V_66 ) ;
F_29 ( V_3 , L_30 , V_18 -> V_67 ? L_31 : L_32 ) ;
F_29 ( V_3 , L_33 ,
( F_4 ( V_3 , 0x42 ) & V_22 ) ?
L_34 : L_35 ,
( F_4 ( V_3 , 0x42 ) & V_23 ) ?
L_34 : L_35 ,
V_62 -> V_68 ? L_36 : L_35 , V_62 -> V_69 ) ;
if ( V_18 -> V_70 ) {
F_29 ( V_3 , L_37 ,
( F_4 ( V_3 , 0xaf ) & 0x02 ) ?
L_38 : L_39 ,
( F_4 ( V_3 , 0xa1 ) & 0x3c ) ?
L_40 : L_41 ) ;
}
F_29 ( V_3 , L_42 , ( F_4 ( V_3 , 0xb8 ) & 0x40 ) ?
L_43 : L_44 ) ;
F_29 ( V_3 , L_45 ,
V_63 [ F_4 ( V_3 , 0xc8 ) & 0xf ] ,
V_64 [ F_4 ( V_3 , 0xc8 ) >> 4 ] ,
V_18 -> V_71 ,
F_4 ( V_3 , 0x94 ) , F_4 ( V_3 , 0x96 ) ) ;
V_65 = F_4 ( V_3 , 0x98 ) & 0x80 ;
F_29 ( V_3 , L_46 ,
F_4 ( V_3 , 0x3b ) & 0x01 ? L_47 : L_48 ) ;
F_29 ( V_3 , L_49 ,
V_65 ? L_50 : L_51 ,
V_65 ? ( ( F_4 ( V_3 , 0x98 ) & 0x70 ) >> 4 ) :
( ( F_4 ( V_3 , 0x9e ) & 0x0e ) >> 1 ) ) ;
if ( V_18 -> V_70 ) {
if ( F_4 ( V_3 , 0xaf ) & 0x02 ) {
T_1 V_72 = F_4 ( V_3 , 0x0a ) & 0x80 ;
T_3 V_73 = ( F_4 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x02 ) << 8 |
F_4 ( V_3 , 0x03 ) ;
T_1 V_74 = F_4 ( V_3 , 0x3e ) >> 2 ;
T_1 V_75 = F_4 ( V_3 , 0x3d ) & 0x3f ;
T_3 V_76 ;
if ( V_72 )
V_76 = ( F_4 ( V_3 , 0x07 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x08 ) << 8 |
F_4 ( V_3 , 0x09 ) ;
else
V_76 = ( F_4 ( V_3 , 0x04 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x05 ) << 8 |
F_4 ( V_3 , 0x06 ) ;
V_73 = ( F_4 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x02 ) << 8 |
F_4 ( V_3 , 0x03 ) ;
F_29 ( V_3 , L_52 ,
V_72 ? L_50 : L_51 , V_73 , V_76 ) ;
F_29 ( V_3 , L_53 ,
V_74 , V_75 ) ;
}
}
if ( V_18 -> V_39 . type == V_77 ) {
struct V_78 * V_40 = V_40 = & V_18 -> V_39 . V_40 ;
T_3 V_79 = V_40 -> V_80 + V_40 -> V_81 +
V_40 -> V_82 + V_40 -> V_83 ;
T_3 V_84 = V_40 -> V_85 + V_40 -> V_86 +
V_40 -> V_87 + V_40 -> V_88 ;
T_3 V_89 = V_79 * V_84 ;
F_29 ( V_3 , L_54 ,
V_40 -> V_80 , V_40 -> V_85 , V_40 -> V_90 ? L_55 : L_56 ,
V_89 > 0 ? ( unsigned ) V_40 -> V_47 / V_89 : 0 ,
V_79 , V_84 ,
( unsigned ) V_40 -> V_47 , V_40 -> V_91 ) ;
} else {
F_29 ( V_3 , L_57 ) ;
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , int V_92 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_93 * V_94 = & V_18 -> V_94 ;
const int V_95 = 20 ;
int V_13 ;
F_12 ( 1 , V_19 , V_3 , L_58 , V_20 , V_92 ? L_31 : L_32 ) ;
V_18 -> V_67 = V_92 ;
if ( ! V_92 ) {
F_10 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
return true ;
}
for ( V_13 = 0 ; V_13 < V_95 ; V_13 ++ ) {
F_10 ( V_3 , 0x41 , 0xbf , 0x0 ) ;
if ( ( F_4 ( V_3 , 0x41 ) & 0x40 ) == 0 )
break;
F_10 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
F_31 ( 10 ) ;
}
if ( V_13 == V_95 ) {
F_12 ( 1 , V_19 , V_3 , L_59 ) ;
F_30 ( V_3 , 0 ) ;
return false ;
}
if ( V_13 > 1 )
F_12 ( 1 , V_19 , V_3 ,
L_60 , V_13 ) ;
F_10 ( V_3 , 0xba , 0xef , 0x10 ) ;
F_10 ( V_3 , 0x98 , 0xf0 , 0x07 ) ;
F_7 ( V_3 , 0x9c , 0x38 ) ;
F_10 ( V_3 , 0x9d , 0xfc , 0x01 ) ;
if ( V_94 -> V_96 > 0 )
F_7 ( V_3 , 0xa2 , V_94 -> V_96 ) ;
else
F_7 ( V_3 , 0xa2 , 0x87 ) ;
if ( V_94 -> V_97 > 0 )
F_7 ( V_3 , 0xa3 , V_94 -> V_97 ) ;
else
F_7 ( V_3 , 0xa3 , 0x87 ) ;
F_7 ( V_3 , 0x0a , 0x01 ) ;
F_7 ( V_3 , 0xbb , 0xff ) ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
return true ;
}
static void F_32 ( struct V_2 * V_3 , bool V_37 )
{
T_1 V_98 = V_99 | V_100 ;
T_1 V_101 ;
int V_95 = 100 ;
if ( ! V_37 )
V_98 = 0 ;
else if ( F_13 ( V_3 ) )
V_98 |= V_102 ;
do {
F_7 ( V_3 , 0x94 , V_98 ) ;
V_101 = F_4 ( V_3 , 0x94 ) ;
} while ( V_95 -- && V_101 != V_98 );
if ( V_101 != V_98 )
F_9 ( V_3 , L_61 ) ;
}
static int F_33 ( struct V_2 * V_3 , T_3 V_103 , bool * V_104 )
{
T_1 V_105 ;
F_32 ( V_3 , false ) ;
V_105 = F_4 ( V_3 , 0x96 ) ;
F_7 ( V_3 , 0x96 , V_105 ) ;
if ( V_105 & ( V_99 | V_100 ) )
F_34 ( V_3 ) ;
if ( V_105 & V_102 )
F_35 ( V_3 ) ;
F_32 ( V_3 , true ) ;
* V_104 = true ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_106 * V_62 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
if ( V_62 -> V_107 != 0 )
return - V_46 ;
if ( V_62 -> V_69 == 0 || V_62 -> V_69 > 256 )
return - V_46 ;
if ( ! V_62 -> V_62 )
return - V_46 ;
if ( ! V_18 -> V_62 . V_68 ) {
F_12 ( 1 , V_19 , V_3 , L_62 ) ;
return - V_108 ;
}
if ( V_62 -> V_109 >= V_18 -> V_62 . V_68 * 2 )
return - V_110 ;
if ( V_62 -> V_69 + V_62 -> V_109 >= V_18 -> V_62 . V_68 * 2 )
V_62 -> V_69 = V_18 -> V_62 . V_68 * 2 - V_62 -> V_109 ;
memcpy ( V_62 -> V_62 , & V_18 -> V_62 . V_111 [ V_62 -> V_109 * 128 ] ,
128 * V_62 -> V_69 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , int V_37 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_63 , V_20 , ( V_37 ? L_64 : L_65 ) ) ;
F_10 ( V_3 , 0xa1 , ~ 0x3c , ( V_37 ? 0 : 0x3c ) ) ;
if ( V_37 ) {
F_34 ( V_3 ) ;
} else {
F_30 ( V_3 , 0 ) ;
V_18 -> V_70 = false ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_112 * V_113 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_13 ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
if ( V_113 -> type != V_77 )
return - V_46 ;
if ( V_113 -> V_40 . V_90 )
return - V_46 ;
if ( V_113 -> V_40 . V_47 < 27000000 ||
V_113 -> V_40 . V_47 > 170000000 )
return - V_46 ;
for ( V_13 = 0 ; V_114 [ V_13 ] . V_40 . V_80 ; V_13 ++ ) {
if ( F_39 ( V_113 , & V_114 [ V_13 ] , 0 ) ) {
* V_113 = V_114 [ V_13 ] ;
break;
}
}
V_113 -> V_40 . V_115 &= ~ V_116 ;
V_18 -> V_39 = * V_113 ;
F_19 ( V_3 , V_18 -> V_52 ) ;
if ( V_18 -> V_94 . V_117 == V_118 )
F_20 ( V_3 , ( T_3 ) V_113 -> V_40 . V_47 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_112 * V_113 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
if ( ! V_113 )
return - V_46 ;
* V_113 = V_18 -> V_39 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_119 * V_113 )
{
if ( V_113 -> V_120 >= F_42 ( V_114 ) )
return - V_46 ;
memset ( V_113 -> V_121 , 0 , sizeof( V_113 -> V_121 ) ) ;
V_113 -> V_113 = V_114 [ V_113 -> V_120 ] ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_122 * V_123 )
{
V_123 -> type = V_77 ;
V_123 -> V_40 . V_124 = 1920 ;
V_123 -> V_40 . V_125 = 1200 ;
V_123 -> V_40 . V_126 = 27000000 ;
V_123 -> V_40 . V_127 = 170000000 ;
V_123 -> V_40 . V_41 = V_42 | V_128 |
V_129 | V_130 ;
V_123 -> V_40 . V_131 = V_132 |
V_133 | V_134 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , int V_37 )
{
F_12 ( 1 , V_19 , V_3 , L_63 , V_20 , ( V_37 ? L_64 : L_65 ) ) ;
if ( V_37 )
F_10 ( V_3 , 0x45 , 0x3f , 0x80 ) ;
else
F_10 ( V_3 , 0x45 , 0x3f , 0x40 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , T_3 V_135 )
{
T_3 V_73 ;
switch ( V_135 ) {
case 32000 : V_73 = 4096 ; break;
case 44100 : V_73 = 6272 ; break;
case 48000 : V_73 = 6144 ; break;
case 88200 : V_73 = 12544 ; break;
case 96000 : V_73 = 12288 ; break;
case 176400 : V_73 = 25088 ; break;
case 192000 : V_73 = 24576 ; break;
default:
return - V_46 ;
}
F_7 ( V_3 , 0x01 , ( V_73 >> 16 ) & 0xf ) ;
F_7 ( V_3 , 0x02 , ( V_73 >> 8 ) & 0xff ) ;
F_7 ( V_3 , 0x03 , V_73 & 0xff ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , T_3 V_135 )
{
T_3 V_136 ;
switch ( V_135 ) {
case 32000 : V_136 = 0x30 ; break;
case 44100 : V_136 = 0x00 ; break;
case 48000 : V_136 = 0x20 ; break;
case 88200 : V_136 = 0x80 ; break;
case 96000 : V_136 = 0xa0 ; break;
case 176400 : V_136 = 0xc0 ; break;
case 192000 : V_136 = 0xe0 ; break;
default:
return - V_46 ;
}
F_10 ( V_3 , 0x15 , 0xf , V_136 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , T_3 V_137 , T_3 V_138 , T_3 V_139 )
{
F_10 ( V_3 , 0x50 , 0x1f , 0x20 ) ;
F_7 ( V_3 , 0x51 , 0x00 ) ;
F_10 ( V_3 , 0x14 , 0xf0 , 0x02 ) ;
return 0 ;
}
static void F_48 ( int V_140 , int V_19 , struct V_2 * V_3 ,
int V_141 , T_1 * V_17 )
{
int V_13 , V_142 ;
if ( V_19 < V_140 )
return;
F_12 ( V_140 , V_19 , V_3 , L_66 , V_141 ) ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 += 16 ) {
T_1 V_143 [ 128 ] ;
T_1 * V_144 = V_143 ;
if ( V_13 == 128 )
F_12 ( V_140 , V_19 , V_3 , L_67 ) ;
for ( V_142 = V_13 ; V_142 < V_13 + 16 ; V_142 ++ ) {
sprintf ( V_144 , L_68 , V_17 [ V_142 ] ) ;
V_144 += 6 ;
}
V_144 [ 0 ] = '\0' ;
F_12 ( V_140 , V_19 , V_3 , L_69 , V_143 ) ;
}
}
static void F_49 ( struct V_145 * V_146 )
{
struct V_147 * V_148 = F_50 ( V_146 ) ;
struct V_1 * V_18 = F_2 ( V_148 ,
struct V_1 , V_149 ) ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_150 V_151 ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
if ( F_35 ( V_3 ) ) {
return;
}
if ( F_13 ( V_3 ) ) {
if ( V_18 -> V_62 . V_152 ) {
V_18 -> V_62 . V_152 -- ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
F_51 ( V_18 -> V_153 ,
& V_18 -> V_149 , V_154 ) ;
return;
}
}
V_151 . V_155 = false ;
V_151 . V_141 = F_4 ( V_3 , 0xc4 ) ;
F_52 ( V_3 , V_156 , ( void * ) & V_151 ) ;
F_12 ( 1 , V_19 , V_3 , L_70 , V_20 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
F_12 ( 1 , V_19 , V_3 , L_69 , V_20 ) ;
F_46 ( V_3 , 48000 ) ;
F_45 ( V_3 , 48000 ) ;
F_47 ( V_3 , 0 , 0 , 0 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_69 , V_20 ) ;
F_10 ( V_3 , 0x15 , 0xf1 , 0x0 ) ;
F_10 ( V_3 , 0x16 , 0x3f , 0x0 ) ;
F_10 ( V_3 , 0x17 , 0xe1 , 0x0e ) ;
F_10 ( V_3 , 0x3b , 0x9e , 0x0 ) ;
F_10 ( V_3 , 0x45 , 0xc7 , 0x08 ) ;
F_10 ( V_3 , 0x46 , 0x3f , 0x80 ) ;
F_7 ( V_3 , 0x3c , 0x0 ) ;
F_7 ( V_3 , 0x47 , 0x80 ) ;
F_10 ( V_3 , 0xaf , 0xef , 0x0 ) ;
F_10 ( V_3 , 0xba , 0x1f , 0x60 ) ;
F_53 ( V_3 ) ;
F_55 ( & V_18 -> V_7 ) ;
F_18 ( V_3 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_157 V_158 ;
struct V_1 * V_18 = F_1 ( V_3 ) ;
V_158 . V_155 = V_18 -> V_70 ;
F_52 ( V_3 , V_159 , ( void * ) & V_158 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
T_1 V_103 = F_4 ( V_3 , 0x42 ) ;
F_12 ( 1 , V_19 , V_3 , L_71 ,
V_20 ,
V_103 ,
V_103 & V_22 ? L_72 : L_73 ,
V_103 & V_23 ? L_74 : L_73 ) ;
if ( ( V_103 & V_22 ) &&
( ( V_103 & V_23 ) || V_18 -> V_62 . V_68 ) ) {
F_12 ( 1 , V_19 , V_3 ,
L_75 , V_20 ) ;
if ( ! V_18 -> V_70 ) {
F_12 ( 1 , V_19 , V_3 , L_76 , V_20 ) ;
V_18 -> V_70 = true ;
F_32 ( V_3 , true ) ;
if ( ! F_30 ( V_3 , true ) ) {
F_12 ( 1 , V_19 , V_3 ,
L_77 , V_20 ) ;
return;
}
F_54 ( V_3 ) ;
F_56 ( V_3 ) ;
V_18 -> V_62 . V_152 = V_160 ;
F_51 ( V_18 -> V_153 ,
& V_18 -> V_149 , V_154 ) ;
}
} else if ( V_103 & V_22 ) {
F_12 ( 1 , V_19 , V_3 , L_78 , V_20 ) ;
V_18 -> V_62 . V_152 = V_160 ;
F_51 ( V_18 -> V_153 ,
& V_18 -> V_149 , V_154 ) ;
} else if ( ! ( V_103 & V_22 ) ) {
F_12 ( 1 , V_19 , V_3 , L_79 , V_20 ) ;
if ( V_18 -> V_70 ) {
F_12 ( 1 , V_19 , V_3 , L_80 , V_20 ) ;
V_18 -> V_70 = false ;
F_56 ( V_3 ) ;
}
F_30 ( V_3 , false ) ;
memset ( & V_18 -> V_62 , 0 , sizeof( struct V_61 ) ) ;
}
F_57 ( V_18 -> V_161 , F_13 ( V_3 ) ? 0x1 : 0x0 ) ;
F_57 ( V_18 -> V_162 , F_14 ( V_3 ) ? 0x1 : 0x0 ) ;
F_57 ( V_18 -> V_163 , V_18 -> V_62 . V_68 ? 0x1 : 0x0 ) ;
}
static bool F_58 ( T_1 * V_164 )
{
int V_13 ;
T_1 V_165 = 0 ;
for ( V_13 = 0 ; V_13 < 127 ; V_13 ++ )
V_165 += * ( V_164 + V_13 ) ;
return ( ( 255 - V_165 + 1 ) == V_164 [ 127 ] ) ;
}
static bool F_59 ( struct V_2 * V_3 , T_3 V_141 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
T_3 V_69 = V_18 -> V_62 . V_69 ;
T_1 * V_111 = V_18 -> V_62 . V_111 ;
if ( F_58 ( & V_111 [ V_141 * 256 ] ) ) {
if ( ( V_141 + 1 ) * 2 <= V_69 )
return F_58 ( & V_111 [ V_141 * 256 + 128 ] ) ;
return true ;
}
return false ;
}
static bool F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_150 V_151 ;
int V_141 ;
T_1 V_166 = F_4 ( V_3 , 0xc5 ) ;
F_12 ( 1 , V_19 , V_3 , L_81 ,
V_20 , V_160 - V_18 -> V_62 . V_152 ) ;
if ( ! ( V_166 & V_167 ) )
return false ;
V_141 = F_4 ( V_3 , 0xc4 ) ;
if ( V_141 >= V_168 ) {
F_9 ( V_3 , L_82 ) ;
return false ;
}
F_12 ( 1 , V_19 , V_3 , L_83 , V_20 , V_141 ) ;
F_11 ( V_3 , 256 , & V_18 -> V_62 . V_111 [ V_141 * 256 ] ) ;
F_48 ( 2 , V_19 , V_3 , V_141 ,
& V_18 -> V_62 . V_111 [ V_141 * 256 ] ) ;
if ( V_141 == 0 ) {
V_18 -> V_62 . V_69 = V_18 -> V_62 . V_111 [ 0x7e ] + 1 ;
F_12 ( 1 , V_19 , V_3 , L_84 ,
V_20 , V_18 -> V_62 . V_69 ) ;
}
if ( ! F_59 ( V_3 , V_141 ) ) {
F_30 ( V_3 , false ) ;
F_30 ( V_3 , true ) ;
return false ;
}
V_18 -> V_62 . V_68 = V_141 + 1 ;
if ( ( ( V_18 -> V_62 . V_111 [ 0x7e ] >> 1 ) + 1 ) > V_18 -> V_62 . V_68 ) {
F_12 ( 1 , V_19 , V_3 , L_85 ,
V_20 , V_18 -> V_62 . V_68 ) ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
F_7 ( V_3 , 0xc4 , V_18 -> V_62 . V_68 ) ;
V_18 -> V_62 . V_152 = V_160 ;
F_51 ( V_18 -> V_153 ,
& V_18 -> V_149 , V_154 ) ;
return false ;
}
V_151 . V_155 = true ;
V_151 . V_141 = 0 ;
F_52 ( V_3 , V_156 , ( void * ) & V_151 ) ;
V_18 -> V_71 ++ ;
F_57 ( V_18 -> V_163 , V_18 -> V_62 . V_68 ? 0x1 : 0x0 ) ;
return V_151 . V_155 ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_61 * V_62 = & V_18 -> V_62 ;
F_12 ( 1 , V_19 , V_3 , L_69 , V_20 ) ;
F_7 ( V_3 , 0x96 , 0xff ) ;
memset ( V_62 , 0 , sizeof( struct V_61 ) ) ;
V_18 -> V_70 = false ;
F_32 ( V_3 , false ) ;
}
static int F_61 ( struct V_9 * V_10 , const struct V_169 * V_49 )
{
const struct V_112 V_170 = V_171 ;
struct V_1 * V_18 ;
struct V_93 * V_94 = V_10 -> V_172 . V_173 ;
struct V_174 * V_7 ;
struct V_2 * V_3 ;
int V_175 = - V_176 ;
if ( ! F_62 ( V_10 -> V_177 , V_178 ) )
return - V_176 ;
F_63 ( 1 , V_19 , V_10 , L_86 ,
V_10 -> V_179 << 1 ) ;
V_18 = F_64 ( sizeof( struct V_1 ) , V_180 ) ;
if ( ! V_18 )
return - V_181 ;
if ( V_94 == NULL ) {
F_65 ( V_10 , L_87 ) ;
V_175 = - V_182 ;
goto V_183;
}
memcpy ( & V_18 -> V_94 , V_94 , sizeof( V_18 -> V_94 ) ) ;
V_3 = & V_18 -> V_3 ;
F_66 ( V_3 , V_10 , & V_184 ) ;
V_3 -> V_115 |= V_185 ;
V_7 = & V_18 -> V_7 ;
F_67 ( V_7 , 5 ) ;
V_18 -> V_50 = F_68 ( V_7 , & V_186 ,
V_187 , V_51 ,
0 , V_188 ) ;
V_18 -> V_50 -> V_189 = true ;
V_18 -> V_161 = F_69 ( V_7 , NULL ,
V_190 , 0 , 1 , 0 , 0 ) ;
V_18 -> V_161 -> V_189 = true ;
V_18 -> V_162 = F_69 ( V_7 , NULL ,
V_191 , 0 , 1 , 0 , 0 ) ;
V_18 -> V_162 -> V_189 = true ;
V_18 -> V_163 = F_69 ( V_7 , NULL ,
V_192 , 0 , 1 , 0 , 0 ) ;
V_18 -> V_163 -> V_189 = true ;
V_18 -> V_52 =
F_68 ( V_7 , & V_186 ,
V_193 , V_45 ,
0 , V_43 ) ;
V_18 -> V_52 -> V_189 = true ;
V_3 -> V_194 = V_7 ;
if ( V_7 -> error ) {
V_175 = V_7 -> error ;
goto V_195;
}
V_18 -> V_107 . V_115 = V_196 ;
V_175 = F_70 ( & V_3 -> V_197 , 1 , & V_18 -> V_107 , 0 ) ;
if ( V_175 )
goto V_195;
V_18 -> V_66 = F_4 ( V_3 , 0x0 ) ;
if ( V_18 -> V_66 != 2 ) {
F_9 ( V_3 , L_88 , V_18 -> V_66 ) ;
V_175 = - V_176 ;
goto V_198;
}
F_12 ( 1 , V_19 , V_3 , L_89 ,
F_4 ( V_3 , 0x41 ) , V_18 -> V_66 ) ;
V_18 -> V_21 = F_71 ( V_10 -> V_177 , ( 0x7e >> 1 ) ) ;
if ( V_18 -> V_21 == NULL ) {
F_9 ( V_3 , L_90 ) ;
goto V_198;
}
V_18 -> V_153 = F_72 ( V_3 -> V_199 ) ;
if ( V_18 -> V_153 == NULL ) {
F_9 ( V_3 , L_91 ) ;
goto V_200;
}
F_73 ( & V_18 -> V_149 , F_49 ) ;
V_18 -> V_39 = V_170 ;
F_60 ( V_3 ) ;
F_32 ( V_3 , true ) ;
F_29 ( V_3 , L_92 , V_10 -> V_199 ,
V_10 -> V_179 << 1 , V_10 -> V_177 -> V_199 ) ;
return 0 ;
V_200:
F_74 ( V_18 -> V_21 ) ;
V_198:
F_75 ( & V_3 -> V_197 ) ;
V_195:
F_76 ( & V_18 -> V_7 ) ;
V_183:
F_77 ( V_18 ) ;
return V_175 ;
}
static int F_78 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_79 ( V_10 ) ;
struct V_1 * V_18 = F_1 ( V_3 ) ;
V_18 -> V_66 = - 1 ;
F_12 ( 1 , V_19 , V_3 , L_93 , V_10 -> V_199 ,
V_10 -> V_179 << 1 , V_10 -> V_177 -> V_199 ) ;
F_37 ( V_3 , false ) ;
F_44 ( V_3 , false ) ;
F_60 ( V_3 ) ;
F_80 ( & V_18 -> V_149 ) ;
F_74 ( V_18 -> V_21 ) ;
F_81 ( V_18 -> V_153 ) ;
F_82 ( V_3 ) ;
F_75 ( & V_3 -> V_197 ) ;
F_76 ( V_3 -> V_194 ) ;
F_77 ( F_1 ( V_3 ) ) ;
return 0 ;
}
