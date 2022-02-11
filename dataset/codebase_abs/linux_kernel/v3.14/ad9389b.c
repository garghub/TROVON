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
F_9 ( V_3 , L_1 , V_14 , V_8 , V_11 ) ;
return V_12 ;
}
static inline void F_10 ( struct V_2 * V_3 , T_1 V_8 ,
T_1 V_15 , T_1 V_16 )
{
F_7 ( V_3 , V_8 , ( F_4 ( V_3 , V_8 ) & V_15 ) | V_16 ) ;
}
static void F_11 ( struct V_2 * V_3 , T_2 V_17 , T_1 * V_18 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
int V_13 ;
F_12 ( 1 , V_20 , V_3 , L_2 , V_14 ) ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ )
V_18 [ V_13 ] = F_6 ( V_19 -> V_21 , V_13 ) ;
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
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( V_19 -> V_39 . V_40 . V_41 & V_42 ) {
F_10 ( V_3 , 0xcd , 0xbf , 0x00 ) ;
} else {
F_10 ( V_3 , 0xcd , 0xbf , 0x40 ) ;
}
}
static int F_19 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
switch ( V_5 -> V_11 ) {
case V_43 :
if ( V_19 -> V_39 . V_40 . V_41 & V_42 ) {
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
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_12 ( 1 , V_20 , V_3 ,
L_3 , V_14 , V_5 -> V_49 , V_5 -> V_11 ) ;
if ( V_19 -> V_50 == V_5 ) {
F_10 ( V_3 , 0xaf , 0xfd ,
V_5 -> V_11 == V_51 ? 0x02 : 0x00 ) ;
return 0 ;
}
if ( V_19 -> V_52 == V_5 )
return F_19 ( V_3 , V_5 ) ;
return - V_46 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_53 * V_8 )
{
V_8 -> V_11 = F_4 ( V_3 , V_8 -> V_8 & 0xff ) ;
V_8 -> V_54 = 1 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , const struct V_53 * V_8 )
{
F_7 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_11 & 0xff ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_19 -> V_56 ;
static const char * const V_57 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 , L_11 , L_12 , L_13 , L_14 , L_15 , L_16 , L_17 , L_18 , L_19
} ;
static const char * const V_58 [] = {
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
T_1 V_59 ;
F_25 ( V_3 , L_29 , V_19 -> V_60 ) ;
F_25 ( V_3 , L_30 , V_19 -> V_61 ? L_31 : L_32 ) ;
F_25 ( V_3 , L_33 ,
( F_4 ( V_3 , 0x42 ) & V_22 ) ?
L_34 : L_35 ,
( F_4 ( V_3 , 0x42 ) & V_23 ) ?
L_34 : L_35 ,
V_56 -> V_62 ? L_36 : L_35 , V_56 -> V_63 ) ;
F_25 ( V_3 , L_37 ,
( F_4 ( V_3 , 0xaf ) & 0x02 ) ?
L_38 : L_39 ,
( F_4 ( V_3 , 0xa1 ) & 0x3c ) ?
L_40 : L_41 ) ;
F_25 ( V_3 , L_42 , ( F_4 ( V_3 , 0xb8 ) & 0x40 ) ?
L_43 : L_44 ) ;
F_25 ( V_3 , L_45 ,
V_57 [ F_4 ( V_3 , 0xc8 ) & 0xf ] ,
V_58 [ F_4 ( V_3 , 0xc8 ) >> 4 ] ,
V_19 -> V_64 ,
F_4 ( V_3 , 0x94 ) , F_4 ( V_3 , 0x96 ) ) ;
V_59 = F_4 ( V_3 , 0x98 ) & 0x80 ;
F_25 ( V_3 , L_46 ,
F_4 ( V_3 , 0x3b ) & 0x01 ? L_47 : L_48 ) ;
F_25 ( V_3 , L_49 ,
V_59 ? L_50 : L_51 ,
V_59 ? ( ( F_4 ( V_3 , 0x98 ) & 0x70 ) >> 4 ) :
( ( F_4 ( V_3 , 0x9e ) & 0x0e ) >> 1 ) ) ;
if ( F_4 ( V_3 , 0xaf ) & 0x02 ) {
T_1 V_65 = F_4 ( V_3 , 0x0a ) & 0x80 ;
T_3 V_66 = ( F_4 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x02 ) << 8 |
F_4 ( V_3 , 0x03 ) ;
T_1 V_67 = F_4 ( V_3 , 0x3e ) >> 2 ;
T_1 V_68 = F_4 ( V_3 , 0x3d ) & 0x3f ;
T_3 V_69 ;
if ( V_65 )
V_69 = ( F_4 ( V_3 , 0x07 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x08 ) << 8 |
F_4 ( V_3 , 0x09 ) ;
else
V_69 = ( F_4 ( V_3 , 0x04 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x05 ) << 8 |
F_4 ( V_3 , 0x06 ) ;
V_66 = ( F_4 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x02 ) << 8 |
F_4 ( V_3 , 0x03 ) ;
F_25 ( V_3 , L_52 ,
V_65 ? L_50 : L_51 , V_66 , V_69 ) ;
F_25 ( V_3 , L_53 ,
V_67 , V_68 ) ;
}
if ( V_19 -> V_39 . type == V_70 )
F_26 ( V_3 -> V_71 , L_54 ,
& V_19 -> V_39 , false ) ;
else
F_25 ( V_3 , L_55 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , int V_72 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_73 * V_74 = & V_19 -> V_74 ;
const int V_75 = 20 ;
int V_13 ;
F_12 ( 1 , V_20 , V_3 , L_56 , V_14 , V_72 ? L_31 : L_32 ) ;
V_19 -> V_61 = V_72 ;
if ( ! V_72 ) {
F_10 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
return true ;
}
for ( V_13 = 0 ; V_13 < V_75 ; V_13 ++ ) {
F_10 ( V_3 , 0x41 , 0xbf , 0x0 ) ;
if ( ( F_4 ( V_3 , 0x41 ) & 0x40 ) == 0 )
break;
F_10 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
F_28 ( 10 ) ;
}
if ( V_13 == V_75 ) {
F_12 ( 1 , V_20 , V_3 , L_57 ) ;
F_27 ( V_3 , 0 ) ;
return false ;
}
if ( V_13 > 1 )
F_12 ( 1 , V_20 , V_3 ,
L_58 , V_13 ) ;
F_10 ( V_3 , 0xba , 0xef , 0x10 ) ;
F_10 ( V_3 , 0x98 , 0xf0 , 0x07 ) ;
F_7 ( V_3 , 0x9c , 0x38 ) ;
F_10 ( V_3 , 0x9d , 0xfc , 0x01 ) ;
if ( V_74 -> V_76 > 0 )
F_7 ( V_3 , 0xa2 , V_74 -> V_76 ) ;
else
F_7 ( V_3 , 0xa2 , 0x87 ) ;
if ( V_74 -> V_77 > 0 )
F_7 ( V_3 , 0xa3 , V_74 -> V_77 ) ;
else
F_7 ( V_3 , 0xa3 , 0x87 ) ;
F_7 ( V_3 , 0x0a , 0x01 ) ;
F_7 ( V_3 , 0xbb , 0xff ) ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
return true ;
}
static void F_29 ( struct V_2 * V_3 , bool V_37 )
{
T_1 V_78 = V_79 | V_80 ;
T_1 V_81 ;
int V_75 = 100 ;
if ( ! V_37 )
V_78 = 0 ;
else if ( F_13 ( V_3 ) )
V_78 |= V_82 ;
do {
F_7 ( V_3 , 0x94 , V_78 ) ;
V_81 = F_4 ( V_3 , 0x94 ) ;
} while ( V_75 -- && V_81 != V_78 );
if ( V_81 != V_78 )
F_9 ( V_3 , L_59 ) ;
}
static int F_30 ( struct V_2 * V_3 , T_3 V_83 , bool * V_84 )
{
T_1 V_85 ;
F_29 ( V_3 , false ) ;
V_85 = F_4 ( V_3 , 0x96 ) ;
F_7 ( V_3 , 0x96 , V_85 ) ;
F_29 ( V_3 , true ) ;
F_12 ( 1 , V_20 , V_3 , L_60 , V_14 , V_85 ) ;
if ( V_85 & ( V_79 ) )
F_31 ( V_3 ) ;
if ( V_85 & V_82 )
F_32 ( V_3 ) ;
* V_84 = true ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_86 * V_56 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( V_56 -> V_87 != 0 )
return - V_46 ;
if ( V_56 -> V_63 == 0 || V_56 -> V_63 > 256 )
return - V_46 ;
if ( ! V_56 -> V_56 )
return - V_46 ;
if ( ! V_19 -> V_56 . V_62 ) {
F_12 ( 1 , V_20 , V_3 , L_61 ) ;
return - V_88 ;
}
if ( V_56 -> V_89 >= V_19 -> V_56 . V_62 * 2 )
return - V_90 ;
if ( V_56 -> V_63 + V_56 -> V_89 >= V_19 -> V_56 . V_62 * 2 )
V_56 -> V_63 = V_19 -> V_56 . V_62 * 2 - V_56 -> V_89 ;
memcpy ( V_56 -> V_56 , & V_19 -> V_56 . V_91 [ V_56 -> V_89 * 128 ] ,
128 * V_56 -> V_63 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , int V_37 )
{
F_12 ( 1 , V_20 , V_3 , L_62 , V_14 , ( V_37 ? L_63 : L_64 ) ) ;
F_10 ( V_3 , 0xa1 , ~ 0x3c , ( V_37 ? 0 : 0x3c ) ) ;
if ( V_37 ) {
F_31 ( V_3 ) ;
} else {
F_27 ( V_3 , 0 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_92 * V_93 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_12 ( 1 , V_20 , V_3 , L_2 , V_14 ) ;
if ( ! F_36 ( V_93 , & V_94 , NULL , NULL ) )
return - V_46 ;
F_37 ( V_93 , & V_94 , 0 , NULL , NULL ) ;
V_93 -> V_40 . V_95 &= ~ V_96 ;
V_19 -> V_39 = * V_93 ;
F_19 ( V_3 , V_19 -> V_52 ) ;
if ( V_19 -> V_74 . V_97 == V_98 )
F_20 ( V_3 , ( T_3 ) V_93 -> V_40 . V_47 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_92 * V_93 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_12 ( 1 , V_20 , V_3 , L_2 , V_14 ) ;
if ( ! V_93 )
return - V_46 ;
* V_93 = V_19 -> V_39 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_99 * V_93 )
{
return F_40 ( V_93 , & V_94 ,
NULL , NULL ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_100 * V_101 )
{
* V_101 = V_94 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_37 )
{
F_12 ( 1 , V_20 , V_3 , L_62 , V_14 , ( V_37 ? L_63 : L_64 ) ) ;
if ( V_37 )
F_10 ( V_3 , 0x45 , 0x3f , 0x80 ) ;
else
F_10 ( V_3 , 0x45 , 0x3f , 0x40 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , T_3 V_102 )
{
T_3 V_66 ;
switch ( V_102 ) {
case 32000 : V_66 = 4096 ; break;
case 44100 : V_66 = 6272 ; break;
case 48000 : V_66 = 6144 ; break;
case 88200 : V_66 = 12544 ; break;
case 96000 : V_66 = 12288 ; break;
case 176400 : V_66 = 25088 ; break;
case 192000 : V_66 = 24576 ; break;
default:
return - V_46 ;
}
F_7 ( V_3 , 0x01 , ( V_66 >> 16 ) & 0xf ) ;
F_7 ( V_3 , 0x02 , ( V_66 >> 8 ) & 0xff ) ;
F_7 ( V_3 , 0x03 , V_66 & 0xff ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , T_3 V_102 )
{
T_3 V_103 ;
switch ( V_102 ) {
case 32000 : V_103 = 0x30 ; break;
case 44100 : V_103 = 0x00 ; break;
case 48000 : V_103 = 0x20 ; break;
case 88200 : V_103 = 0x80 ; break;
case 96000 : V_103 = 0xa0 ; break;
case 176400 : V_103 = 0xc0 ; break;
case 192000 : V_103 = 0xe0 ; break;
default:
return - V_46 ;
}
F_10 ( V_3 , 0x15 , 0xf , V_103 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , T_3 V_104 , T_3 V_105 , T_3 V_106 )
{
F_10 ( V_3 , 0x50 , 0x1f , 0x20 ) ;
F_7 ( V_3 , 0x51 , 0x00 ) ;
F_10 ( V_3 , 0x14 , 0xf0 , 0x02 ) ;
return 0 ;
}
static void F_46 ( int V_107 , int V_20 , struct V_2 * V_3 ,
int V_108 , T_1 * V_18 )
{
int V_13 , V_109 ;
if ( V_20 < V_107 )
return;
F_12 ( V_107 , V_20 , V_3 , L_65 , V_108 ) ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 += 16 ) {
T_1 V_110 [ 128 ] ;
T_1 * V_111 = V_110 ;
if ( V_13 == 128 )
F_12 ( V_107 , V_20 , V_3 , L_66 ) ;
for ( V_109 = V_13 ; V_109 < V_13 + 16 ; V_109 ++ ) {
sprintf ( V_111 , L_67 , V_18 [ V_109 ] ) ;
V_111 += 6 ;
}
V_111 [ 0 ] = '\0' ;
F_12 ( V_107 , V_20 , V_3 , L_68 , V_110 ) ;
}
}
static void F_47 ( struct V_112 * V_113 )
{
struct V_114 * V_115 = F_48 ( V_113 ) ;
struct V_1 * V_19 =
F_2 ( V_115 , struct V_1 , V_116 ) ;
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_117 V_118 ;
F_12 ( 1 , V_20 , V_3 , L_2 , V_14 ) ;
if ( F_32 ( V_3 ) ) {
return;
}
if ( F_13 ( V_3 ) ) {
if ( V_19 -> V_56 . V_119 ) {
V_19 -> V_56 . V_119 -- ;
F_12 ( 1 , V_20 , V_3 , L_69 , V_14 ) ;
F_27 ( V_3 , false ) ;
F_27 ( V_3 , true ) ;
F_49 ( V_19 -> V_120 ,
& V_19 -> V_116 , V_121 ) ;
return;
}
}
V_118 . V_122 = false ;
V_118 . V_108 = F_4 ( V_3 , 0xc4 ) ;
F_50 ( V_3 , V_123 , ( void * ) & V_118 ) ;
F_12 ( 1 , V_20 , V_3 , L_70 , V_14 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_12 ( 1 , V_20 , V_3 , L_68 , V_14 ) ;
F_44 ( V_3 , 48000 ) ;
F_43 ( V_3 , 48000 ) ;
F_45 ( V_3 , 0 , 0 , 0 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_12 ( 1 , V_20 , V_3 , L_68 , V_14 ) ;
F_10 ( V_3 , 0x15 , 0xf1 , 0x0 ) ;
F_10 ( V_3 , 0x16 , 0x3f , 0x0 ) ;
F_10 ( V_3 , 0x17 , 0xf9 , 0x06 ) ;
F_10 ( V_3 , 0x45 , 0xc7 , 0x08 ) ;
F_10 ( V_3 , 0x46 , 0x3f , 0x80 ) ;
F_7 ( V_3 , 0x3c , 0x0 ) ;
F_7 ( V_3 , 0x47 , 0x80 ) ;
F_10 ( V_3 , 0xaf , 0xef , 0x0 ) ;
F_10 ( V_3 , 0xba , 0x1f , 0x60 ) ;
F_51 ( V_3 ) ;
F_53 ( & V_19 -> V_7 ) ;
F_18 ( V_3 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_124 V_125 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
V_125 . V_122 = V_19 -> V_126 ;
F_50 ( V_3 , V_127 , ( void * ) & V_125 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_83 = F_4 ( V_3 , 0x42 ) ;
F_12 ( 1 , V_20 , V_3 , L_71 ,
V_14 ,
V_83 ,
V_83 & V_22 ? L_72 : L_73 ,
V_83 & V_23 ? L_74 : L_73 ) ;
if ( V_83 & V_22 ) {
F_12 ( 1 , V_20 , V_3 , L_75 , V_14 ) ;
V_19 -> V_126 = true ;
if ( ! F_27 ( V_3 , true ) ) {
F_12 ( 1 , V_20 , V_3 ,
L_76 , V_14 ) ;
return;
}
F_52 ( V_3 ) ;
F_54 ( V_3 ) ;
V_19 -> V_56 . V_119 = V_128 ;
F_49 ( V_19 -> V_120 ,
& V_19 -> V_116 , V_121 ) ;
} else if ( ! ( V_83 & V_22 ) ) {
F_12 ( 1 , V_20 , V_3 , L_77 , V_14 ) ;
V_19 -> V_126 = false ;
F_54 ( V_3 ) ;
F_27 ( V_3 , false ) ;
memset ( & V_19 -> V_56 , 0 , sizeof( struct V_55 ) ) ;
}
F_56 ( V_19 -> V_129 , F_13 ( V_3 ) ? 0x1 : 0x0 ) ;
F_56 ( V_19 -> V_130 , F_14 ( V_3 ) ? 0x1 : 0x0 ) ;
F_56 ( V_19 -> V_131 , V_19 -> V_56 . V_62 ? 0x1 : 0x0 ) ;
F_21 ( V_19 -> V_52 ) ;
F_21 ( V_19 -> V_50 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
int V_132 = 0 ;
F_55 ( V_3 ) ;
while ( V_19 -> V_61 && ( F_4 ( V_3 , 0x41 ) & 0x40 ) ) {
if ( ++ V_132 > 5 ) {
F_9 ( V_3 , L_78 , V_132 ) ;
return;
}
F_12 ( 1 , V_20 , V_3 , L_79 , V_14 , V_132 ) ;
F_54 ( V_3 ) ;
F_57 ( & V_19 -> V_116 ) ;
memset ( & V_19 -> V_56 , 0 , sizeof( struct V_55 ) ) ;
F_27 ( V_3 , false ) ;
F_55 ( V_3 ) ;
}
}
static bool F_58 ( T_1 * V_133 )
{
T_1 V_134 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 128 ; V_13 ++ )
V_134 += V_133 [ V_13 ] ;
return V_134 == 0 ;
}
static bool F_59 ( struct V_2 * V_3 , T_3 V_108 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_3 V_63 = V_19 -> V_56 . V_63 ;
T_1 * V_91 = V_19 -> V_56 . V_91 ;
if ( F_58 ( & V_91 [ V_108 * 256 ] ) ) {
if ( ( V_108 + 1 ) * 2 <= V_63 )
return F_58 ( & V_91 [ V_108 * 256 + 128 ] ) ;
return true ;
}
return false ;
}
static bool F_60 ( struct V_2 * V_3 , T_3 V_108 )
{
static const T_1 V_135 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00
} ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 * V_91 = V_19 -> V_56 . V_91 ;
int V_13 ;
if ( V_108 )
return true ;
for ( V_13 = 0 ; V_13 < F_61 ( V_135 ) ; V_13 ++ )
if ( V_91 [ V_13 ] != V_135 [ V_13 ] )
return false ;
return true ;
}
static bool F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_117 V_118 ;
int V_108 ;
T_1 V_136 = F_4 ( V_3 , 0xc5 ) ;
F_12 ( 1 , V_20 , V_3 , L_80 ,
V_14 , V_128 - V_19 -> V_56 . V_119 ) ;
if ( ! ( V_136 & V_137 ) )
return false ;
V_108 = F_4 ( V_3 , 0xc4 ) ;
if ( V_108 >= V_138 ) {
F_9 ( V_3 , L_81 ) ;
return false ;
}
F_12 ( 1 , V_20 , V_3 , L_82 , V_14 , V_108 ) ;
F_11 ( V_3 , 256 , & V_19 -> V_56 . V_91 [ V_108 * 256 ] ) ;
F_46 ( 2 , V_20 , V_3 , V_108 ,
& V_19 -> V_56 . V_91 [ V_108 * 256 ] ) ;
if ( V_108 == 0 ) {
V_19 -> V_56 . V_63 = V_19 -> V_56 . V_91 [ 0x7e ] + 1 ;
F_12 ( 1 , V_20 , V_3 , L_83 ,
V_14 , V_19 -> V_56 . V_63 ) ;
}
if ( ! F_59 ( V_3 , V_108 ) ||
! F_60 ( V_3 , V_108 ) ) {
F_9 ( V_3 , L_84 , V_14 ) ;
F_27 ( V_3 , false ) ;
F_27 ( V_3 , true ) ;
return false ;
}
V_19 -> V_56 . V_62 = V_108 + 1 ;
if ( ( ( V_19 -> V_56 . V_91 [ 0x7e ] >> 1 ) + 1 ) > V_19 -> V_56 . V_62 ) {
F_12 ( 1 , V_20 , V_3 , L_85 ,
V_14 , V_19 -> V_56 . V_62 ) ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
F_7 ( V_3 , 0xc4 , V_19 -> V_56 . V_62 ) ;
V_19 -> V_56 . V_119 = V_128 ;
F_49 ( V_19 -> V_120 ,
& V_19 -> V_116 , V_121 ) ;
return false ;
}
V_118 . V_122 = true ;
V_118 . V_108 = 0 ;
F_50 ( V_3 , V_123 , ( void * ) & V_118 ) ;
V_19 -> V_64 ++ ;
F_56 ( V_19 -> V_131 , V_19 -> V_56 . V_62 ? 0x1 : 0x0 ) ;
return V_118 . V_122 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_19 -> V_56 ;
F_12 ( 1 , V_20 , V_3 , L_68 , V_14 ) ;
F_7 ( V_3 , 0x96 , 0xff ) ;
memset ( V_56 , 0 , sizeof( struct V_55 ) ) ;
V_19 -> V_126 = false ;
F_29 ( V_3 , false ) ;
}
static int F_63 ( struct V_9 * V_10 , const struct V_139 * V_49 )
{
const struct V_92 V_140 = V_141 ;
struct V_1 * V_19 ;
struct V_73 * V_74 = V_10 -> V_142 . V_143 ;
struct V_144 * V_7 ;
struct V_2 * V_3 ;
int V_145 = - V_146 ;
if ( ! F_64 ( V_10 -> V_147 , V_148 ) )
return - V_146 ;
F_65 ( 1 , V_20 , V_10 , L_86 ,
V_10 -> V_149 << 1 ) ;
V_19 = F_66 ( & V_10 -> V_142 , sizeof( * V_19 ) , V_150 ) ;
if ( ! V_19 )
return - V_151 ;
if ( V_74 == NULL ) {
F_67 ( V_10 , L_87 ) ;
return - V_152 ;
}
memcpy ( & V_19 -> V_74 , V_74 , sizeof( V_19 -> V_74 ) ) ;
V_3 = & V_19 -> V_3 ;
F_68 ( V_3 , V_10 , & V_153 ) ;
V_3 -> V_95 |= V_154 ;
V_7 = & V_19 -> V_7 ;
F_69 ( V_7 , 5 ) ;
V_19 -> V_50 = F_70 ( V_7 , & V_155 ,
V_156 , V_51 ,
0 , V_157 ) ;
V_19 -> V_129 = F_71 ( V_7 , NULL ,
V_158 , 0 , 1 , 0 , 0 ) ;
V_19 -> V_130 = F_71 ( V_7 , NULL ,
V_159 , 0 , 1 , 0 , 0 ) ;
V_19 -> V_131 = F_71 ( V_7 , NULL ,
V_160 , 0 , 1 , 0 , 0 ) ;
V_19 -> V_52 =
F_70 ( V_7 , & V_155 ,
V_161 , V_45 ,
0 , V_43 ) ;
V_3 -> V_162 = V_7 ;
if ( V_7 -> error ) {
V_145 = V_7 -> error ;
goto V_163;
}
V_19 -> V_50 -> V_164 = true ;
V_19 -> V_129 -> V_164 = true ;
V_19 -> V_130 -> V_164 = true ;
V_19 -> V_131 -> V_164 = true ;
V_19 -> V_52 -> V_164 = true ;
V_19 -> V_87 . V_95 = V_165 ;
V_145 = F_72 ( & V_3 -> V_166 , 1 , & V_19 -> V_87 , 0 ) ;
if ( V_145 )
goto V_163;
V_19 -> V_60 = F_4 ( V_3 , 0x0 ) ;
if ( V_19 -> V_60 != 2 ) {
F_9 ( V_3 , L_88 , V_19 -> V_60 ) ;
V_145 = - V_146 ;
goto V_167;
}
F_12 ( 1 , V_20 , V_3 , L_89 ,
F_4 ( V_3 , 0x41 ) , V_19 -> V_60 ) ;
V_19 -> V_21 = F_73 ( V_10 -> V_147 , ( 0x7e >> 1 ) ) ;
if ( V_19 -> V_21 == NULL ) {
F_9 ( V_3 , L_90 ) ;
V_145 = - V_151 ;
goto V_167;
}
V_19 -> V_120 = F_74 ( V_3 -> V_71 ) ;
if ( V_19 -> V_120 == NULL ) {
F_9 ( V_3 , L_91 ) ;
V_145 = - V_151 ;
goto V_168;
}
F_75 ( & V_19 -> V_116 , F_47 ) ;
V_19 -> V_39 = V_140 ;
F_62 ( V_3 ) ;
F_29 ( V_3 , true ) ;
F_25 ( V_3 , L_92 , V_10 -> V_71 ,
V_10 -> V_149 << 1 , V_10 -> V_147 -> V_71 ) ;
return 0 ;
V_168:
F_76 ( V_19 -> V_21 ) ;
V_167:
F_77 ( & V_3 -> V_166 ) ;
V_163:
F_78 ( & V_19 -> V_7 ) ;
return V_145 ;
}
static int F_79 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_80 ( V_10 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
V_19 -> V_60 = - 1 ;
F_12 ( 1 , V_20 , V_3 , L_93 , V_10 -> V_71 ,
V_10 -> V_149 << 1 , V_10 -> V_147 -> V_71 ) ;
F_34 ( V_3 , false ) ;
F_42 ( V_3 , false ) ;
F_62 ( V_3 ) ;
F_81 ( & V_19 -> V_116 ) ;
F_76 ( V_19 -> V_21 ) ;
F_82 ( V_19 -> V_120 ) ;
F_83 ( V_3 ) ;
F_77 ( & V_3 -> V_166 ) ;
F_78 ( V_3 -> V_162 ) ;
return 0 ;
}
