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
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_18 -> V_56 ;
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
F_25 ( V_3 , L_29 , V_18 -> V_60 ) ;
F_25 ( V_3 , L_30 , V_18 -> V_61 ? L_31 : L_32 ) ;
F_25 ( V_3 , L_33 ,
( F_4 ( V_3 , 0x42 ) & V_22 ) ?
L_34 : L_35 ,
( F_4 ( V_3 , 0x42 ) & V_23 ) ?
L_34 : L_35 ,
V_56 -> V_62 ? L_36 : L_35 , V_56 -> V_63 ) ;
if ( V_18 -> V_64 ) {
F_25 ( V_3 , L_37 ,
( F_4 ( V_3 , 0xaf ) & 0x02 ) ?
L_38 : L_39 ,
( F_4 ( V_3 , 0xa1 ) & 0x3c ) ?
L_40 : L_41 ) ;
}
F_25 ( V_3 , L_42 , ( F_4 ( V_3 , 0xb8 ) & 0x40 ) ?
L_43 : L_44 ) ;
F_25 ( V_3 , L_45 ,
V_57 [ F_4 ( V_3 , 0xc8 ) & 0xf ] ,
V_58 [ F_4 ( V_3 , 0xc8 ) >> 4 ] ,
V_18 -> V_65 ,
F_4 ( V_3 , 0x94 ) , F_4 ( V_3 , 0x96 ) ) ;
V_59 = F_4 ( V_3 , 0x98 ) & 0x80 ;
F_25 ( V_3 , L_46 ,
F_4 ( V_3 , 0x3b ) & 0x01 ? L_47 : L_48 ) ;
F_25 ( V_3 , L_49 ,
V_59 ? L_50 : L_51 ,
V_59 ? ( ( F_4 ( V_3 , 0x98 ) & 0x70 ) >> 4 ) :
( ( F_4 ( V_3 , 0x9e ) & 0x0e ) >> 1 ) ) ;
if ( V_18 -> V_64 ) {
if ( F_4 ( V_3 , 0xaf ) & 0x02 ) {
T_1 V_66 = F_4 ( V_3 , 0x0a ) & 0x80 ;
T_3 V_67 = ( F_4 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x02 ) << 8 |
F_4 ( V_3 , 0x03 ) ;
T_1 V_68 = F_4 ( V_3 , 0x3e ) >> 2 ;
T_1 V_69 = F_4 ( V_3 , 0x3d ) & 0x3f ;
T_3 V_70 ;
if ( V_66 )
V_70 = ( F_4 ( V_3 , 0x07 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x08 ) << 8 |
F_4 ( V_3 , 0x09 ) ;
else
V_70 = ( F_4 ( V_3 , 0x04 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x05 ) << 8 |
F_4 ( V_3 , 0x06 ) ;
V_67 = ( F_4 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_4 ( V_3 , 0x02 ) << 8 |
F_4 ( V_3 , 0x03 ) ;
F_25 ( V_3 , L_52 ,
V_66 ? L_50 : L_51 , V_67 , V_70 ) ;
F_25 ( V_3 , L_53 ,
V_68 , V_69 ) ;
}
}
if ( V_18 -> V_39 . type == V_71 )
F_26 ( V_3 -> V_72 , L_54 ,
& V_18 -> V_39 , false ) ;
else
F_25 ( V_3 , L_55 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , int V_73 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_74 * V_75 = & V_18 -> V_75 ;
const int V_76 = 20 ;
int V_13 ;
F_12 ( 1 , V_19 , V_3 , L_56 , V_20 , V_73 ? L_31 : L_32 ) ;
V_18 -> V_61 = V_73 ;
if ( ! V_73 ) {
F_10 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
return true ;
}
for ( V_13 = 0 ; V_13 < V_76 ; V_13 ++ ) {
F_10 ( V_3 , 0x41 , 0xbf , 0x0 ) ;
if ( ( F_4 ( V_3 , 0x41 ) & 0x40 ) == 0 )
break;
F_10 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
F_28 ( 10 ) ;
}
if ( V_13 == V_76 ) {
F_12 ( 1 , V_19 , V_3 , L_57 ) ;
F_27 ( V_3 , 0 ) ;
return false ;
}
if ( V_13 > 1 )
F_12 ( 1 , V_19 , V_3 ,
L_58 , V_13 ) ;
F_10 ( V_3 , 0xba , 0xef , 0x10 ) ;
F_10 ( V_3 , 0x98 , 0xf0 , 0x07 ) ;
F_7 ( V_3 , 0x9c , 0x38 ) ;
F_10 ( V_3 , 0x9d , 0xfc , 0x01 ) ;
if ( V_75 -> V_77 > 0 )
F_7 ( V_3 , 0xa2 , V_75 -> V_77 ) ;
else
F_7 ( V_3 , 0xa2 , 0x87 ) ;
if ( V_75 -> V_78 > 0 )
F_7 ( V_3 , 0xa3 , V_75 -> V_78 ) ;
else
F_7 ( V_3 , 0xa3 , 0x87 ) ;
F_7 ( V_3 , 0x0a , 0x01 ) ;
F_7 ( V_3 , 0xbb , 0xff ) ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
return true ;
}
static void F_29 ( struct V_2 * V_3 , bool V_37 )
{
T_1 V_79 = V_80 | V_81 ;
T_1 V_82 ;
int V_76 = 100 ;
if ( ! V_37 )
V_79 = 0 ;
else if ( F_13 ( V_3 ) )
V_79 |= V_83 ;
do {
F_7 ( V_3 , 0x94 , V_79 ) ;
V_82 = F_4 ( V_3 , 0x94 ) ;
} while ( V_76 -- && V_82 != V_79 );
if ( V_82 != V_79 )
F_9 ( V_3 , L_59 ) ;
}
static int F_30 ( struct V_2 * V_3 , T_3 V_84 , bool * V_85 )
{
T_1 V_86 ;
F_29 ( V_3 , false ) ;
V_86 = F_4 ( V_3 , 0x96 ) ;
F_7 ( V_3 , 0x96 , V_86 ) ;
if ( V_86 & ( V_80 | V_81 ) )
F_31 ( V_3 ) ;
if ( V_86 & V_83 )
F_32 ( V_3 ) ;
F_29 ( V_3 , true ) ;
* V_85 = true ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_87 * V_56 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
if ( V_56 -> V_88 != 0 )
return - V_46 ;
if ( V_56 -> V_63 == 0 || V_56 -> V_63 > 256 )
return - V_46 ;
if ( ! V_56 -> V_56 )
return - V_46 ;
if ( ! V_18 -> V_56 . V_62 ) {
F_12 ( 1 , V_19 , V_3 , L_60 ) ;
return - V_89 ;
}
if ( V_56 -> V_90 >= V_18 -> V_56 . V_62 * 2 )
return - V_91 ;
if ( V_56 -> V_63 + V_56 -> V_90 >= V_18 -> V_56 . V_62 * 2 )
V_56 -> V_63 = V_18 -> V_56 . V_62 * 2 - V_56 -> V_90 ;
memcpy ( V_56 -> V_56 , & V_18 -> V_56 . V_92 [ V_56 -> V_90 * 128 ] ,
128 * V_56 -> V_63 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , int V_37 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_61 , V_20 , ( V_37 ? L_62 : L_63 ) ) ;
F_10 ( V_3 , 0xa1 , ~ 0x3c , ( V_37 ? 0 : 0x3c ) ) ;
if ( V_37 ) {
F_31 ( V_3 ) ;
} else {
F_27 ( V_3 , 0 ) ;
V_18 -> V_64 = false ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_93 * V_94 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
if ( ! F_36 ( V_94 , & V_95 , NULL , NULL ) )
return - V_46 ;
F_37 ( V_94 , & V_95 , 0 , NULL , NULL ) ;
V_94 -> V_40 . V_96 &= ~ V_97 ;
V_18 -> V_39 = * V_94 ;
F_19 ( V_3 , V_18 -> V_52 ) ;
if ( V_18 -> V_75 . V_98 == V_99 )
F_20 ( V_3 , ( T_3 ) V_94 -> V_40 . V_47 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_93 * V_94 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
if ( ! V_94 )
return - V_46 ;
* V_94 = V_18 -> V_39 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_100 * V_94 )
{
return F_40 ( V_94 , & V_95 ,
NULL , NULL ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_101 * V_102 )
{
* V_102 = V_95 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_37 )
{
F_12 ( 1 , V_19 , V_3 , L_61 , V_20 , ( V_37 ? L_62 : L_63 ) ) ;
if ( V_37 )
F_10 ( V_3 , 0x45 , 0x3f , 0x80 ) ;
else
F_10 ( V_3 , 0x45 , 0x3f , 0x40 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , T_3 V_103 )
{
T_3 V_67 ;
switch ( V_103 ) {
case 32000 : V_67 = 4096 ; break;
case 44100 : V_67 = 6272 ; break;
case 48000 : V_67 = 6144 ; break;
case 88200 : V_67 = 12544 ; break;
case 96000 : V_67 = 12288 ; break;
case 176400 : V_67 = 25088 ; break;
case 192000 : V_67 = 24576 ; break;
default:
return - V_46 ;
}
F_7 ( V_3 , 0x01 , ( V_67 >> 16 ) & 0xf ) ;
F_7 ( V_3 , 0x02 , ( V_67 >> 8 ) & 0xff ) ;
F_7 ( V_3 , 0x03 , V_67 & 0xff ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , T_3 V_103 )
{
T_3 V_104 ;
switch ( V_103 ) {
case 32000 : V_104 = 0x30 ; break;
case 44100 : V_104 = 0x00 ; break;
case 48000 : V_104 = 0x20 ; break;
case 88200 : V_104 = 0x80 ; break;
case 96000 : V_104 = 0xa0 ; break;
case 176400 : V_104 = 0xc0 ; break;
case 192000 : V_104 = 0xe0 ; break;
default:
return - V_46 ;
}
F_10 ( V_3 , 0x15 , 0xf , V_104 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , T_3 V_105 , T_3 V_106 , T_3 V_107 )
{
F_10 ( V_3 , 0x50 , 0x1f , 0x20 ) ;
F_7 ( V_3 , 0x51 , 0x00 ) ;
F_10 ( V_3 , 0x14 , 0xf0 , 0x02 ) ;
return 0 ;
}
static void F_46 ( int V_108 , int V_19 , struct V_2 * V_3 ,
int V_109 , T_1 * V_17 )
{
int V_13 , V_110 ;
if ( V_19 < V_108 )
return;
F_12 ( V_108 , V_19 , V_3 , L_64 , V_109 ) ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 += 16 ) {
T_1 V_111 [ 128 ] ;
T_1 * V_112 = V_111 ;
if ( V_13 == 128 )
F_12 ( V_108 , V_19 , V_3 , L_65 ) ;
for ( V_110 = V_13 ; V_110 < V_13 + 16 ; V_110 ++ ) {
sprintf ( V_112 , L_66 , V_17 [ V_110 ] ) ;
V_112 += 6 ;
}
V_112 [ 0 ] = '\0' ;
F_12 ( V_108 , V_19 , V_3 , L_67 , V_111 ) ;
}
}
static void F_47 ( struct V_113 * V_114 )
{
struct V_115 * V_116 = F_48 ( V_114 ) ;
struct V_1 * V_18 = F_2 ( V_116 ,
struct V_1 , V_117 ) ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_118 V_119 ;
F_12 ( 1 , V_19 , V_3 , L_2 , V_20 ) ;
if ( F_32 ( V_3 ) ) {
return;
}
if ( F_13 ( V_3 ) ) {
if ( V_18 -> V_56 . V_120 ) {
V_18 -> V_56 . V_120 -- ;
F_12 ( 1 , V_19 , V_3 , L_68 , V_20 ) ;
V_18 -> V_64 = false ;
F_27 ( V_3 , false ) ;
F_27 ( V_3 , true ) ;
F_49 ( V_18 -> V_121 ,
& V_18 -> V_117 , V_122 ) ;
return;
}
}
V_119 . V_123 = false ;
V_119 . V_109 = F_4 ( V_3 , 0xc4 ) ;
F_50 ( V_3 , V_124 , ( void * ) & V_119 ) ;
F_12 ( 1 , V_19 , V_3 , L_69 , V_20 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_12 ( 1 , V_19 , V_3 , L_67 , V_20 ) ;
F_44 ( V_3 , 48000 ) ;
F_43 ( V_3 , 48000 ) ;
F_45 ( V_3 , 0 , 0 , 0 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
F_12 ( 1 , V_19 , V_3 , L_67 , V_20 ) ;
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
F_53 ( & V_18 -> V_7 ) ;
F_18 ( V_3 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_125 V_126 ;
struct V_1 * V_18 = F_1 ( V_3 ) ;
V_126 . V_123 = V_18 -> V_64 ;
F_50 ( V_3 , V_127 , ( void * ) & V_126 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
T_1 V_84 = F_4 ( V_3 , 0x42 ) ;
F_12 ( 1 , V_19 , V_3 , L_70 ,
V_20 ,
V_84 ,
V_84 & V_22 ? L_71 : L_72 ,
V_84 & V_23 ? L_73 : L_72 ) ;
if ( ( V_84 & V_22 ) &&
( ( V_84 & V_23 ) || V_18 -> V_56 . V_62 ) ) {
F_12 ( 1 , V_19 , V_3 ,
L_74 , V_20 ) ;
if ( ! V_18 -> V_64 ) {
F_12 ( 1 , V_19 , V_3 , L_75 , V_20 ) ;
V_18 -> V_64 = true ;
F_29 ( V_3 , true ) ;
if ( ! F_27 ( V_3 , true ) ) {
F_12 ( 1 , V_19 , V_3 ,
L_76 , V_20 ) ;
return;
}
F_52 ( V_3 ) ;
F_54 ( V_3 ) ;
V_18 -> V_56 . V_120 = V_128 ;
F_49 ( V_18 -> V_121 ,
& V_18 -> V_117 , V_122 ) ;
}
} else if ( V_84 & V_22 ) {
F_12 ( 1 , V_19 , V_3 , L_77 , V_20 ) ;
V_18 -> V_56 . V_120 = V_128 ;
F_49 ( V_18 -> V_121 ,
& V_18 -> V_117 , V_122 ) ;
} else if ( ! ( V_84 & V_22 ) ) {
F_12 ( 1 , V_19 , V_3 , L_78 , V_20 ) ;
if ( V_18 -> V_64 ) {
F_12 ( 1 , V_19 , V_3 , L_79 , V_20 ) ;
V_18 -> V_64 = false ;
F_54 ( V_3 ) ;
}
F_27 ( V_3 , false ) ;
memset ( & V_18 -> V_56 , 0 , sizeof( struct V_55 ) ) ;
}
F_55 ( V_18 -> V_129 , F_13 ( V_3 ) ? 0x1 : 0x0 ) ;
F_55 ( V_18 -> V_130 , F_14 ( V_3 ) ? 0x1 : 0x0 ) ;
F_55 ( V_18 -> V_131 , V_18 -> V_56 . V_62 ? 0x1 : 0x0 ) ;
}
static bool F_56 ( T_1 * V_132 )
{
T_1 V_133 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 128 ; V_13 ++ )
V_133 += V_132 [ V_13 ] ;
return V_133 == 0 ;
}
static bool F_57 ( struct V_2 * V_3 , T_3 V_109 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
T_3 V_63 = V_18 -> V_56 . V_63 ;
T_1 * V_92 = V_18 -> V_56 . V_92 ;
if ( F_56 ( & V_92 [ V_109 * 256 ] ) ) {
if ( ( V_109 + 1 ) * 2 <= V_63 )
return F_56 ( & V_92 [ V_109 * 256 + 128 ] ) ;
return true ;
}
return false ;
}
static bool F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_118 V_119 ;
int V_109 ;
T_1 V_134 = F_4 ( V_3 , 0xc5 ) ;
F_12 ( 1 , V_19 , V_3 , L_80 ,
V_20 , V_128 - V_18 -> V_56 . V_120 ) ;
if ( ! ( V_134 & V_135 ) )
return false ;
V_109 = F_4 ( V_3 , 0xc4 ) ;
if ( V_109 >= V_136 ) {
F_9 ( V_3 , L_81 ) ;
return false ;
}
F_12 ( 1 , V_19 , V_3 , L_82 , V_20 , V_109 ) ;
F_11 ( V_3 , 256 , & V_18 -> V_56 . V_92 [ V_109 * 256 ] ) ;
F_46 ( 2 , V_19 , V_3 , V_109 ,
& V_18 -> V_56 . V_92 [ V_109 * 256 ] ) ;
if ( V_109 == 0 ) {
V_18 -> V_56 . V_63 = V_18 -> V_56 . V_92 [ 0x7e ] + 1 ;
F_12 ( 1 , V_19 , V_3 , L_83 ,
V_20 , V_18 -> V_56 . V_63 ) ;
}
if ( ! F_57 ( V_3 , V_109 ) ) {
F_9 ( V_3 , L_84 , V_20 ) ;
V_18 -> V_64 = false ;
F_27 ( V_3 , false ) ;
F_27 ( V_3 , true ) ;
return false ;
}
V_18 -> V_56 . V_62 = V_109 + 1 ;
if ( ( ( V_18 -> V_56 . V_92 [ 0x7e ] >> 1 ) + 1 ) > V_18 -> V_56 . V_62 ) {
F_12 ( 1 , V_19 , V_3 , L_85 ,
V_20 , V_18 -> V_56 . V_62 ) ;
F_7 ( V_3 , 0xc9 , 0xf ) ;
F_7 ( V_3 , 0xc4 , V_18 -> V_56 . V_62 ) ;
V_18 -> V_56 . V_120 = V_128 ;
F_49 ( V_18 -> V_121 ,
& V_18 -> V_117 , V_122 ) ;
return false ;
}
V_119 . V_123 = true ;
V_119 . V_109 = 0 ;
F_50 ( V_3 , V_124 , ( void * ) & V_119 ) ;
V_18 -> V_65 ++ ;
F_55 ( V_18 -> V_131 , V_18 -> V_56 . V_62 ? 0x1 : 0x0 ) ;
return V_119 . V_123 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_18 -> V_56 ;
F_12 ( 1 , V_19 , V_3 , L_67 , V_20 ) ;
F_7 ( V_3 , 0x96 , 0xff ) ;
memset ( V_56 , 0 , sizeof( struct V_55 ) ) ;
V_18 -> V_64 = false ;
F_29 ( V_3 , false ) ;
}
static int F_59 ( struct V_9 * V_10 , const struct V_137 * V_49 )
{
const struct V_93 V_138 = V_139 ;
struct V_1 * V_18 ;
struct V_74 * V_75 = V_10 -> V_140 . V_141 ;
struct V_142 * V_7 ;
struct V_2 * V_3 ;
int V_143 = - V_144 ;
if ( ! F_60 ( V_10 -> V_145 , V_146 ) )
return - V_144 ;
F_61 ( 1 , V_19 , V_10 , L_86 ,
V_10 -> V_147 << 1 ) ;
V_18 = F_62 ( & V_10 -> V_140 , sizeof( * V_18 ) , V_148 ) ;
if ( ! V_18 )
return - V_149 ;
if ( V_75 == NULL ) {
F_63 ( V_10 , L_87 ) ;
return - V_150 ;
}
memcpy ( & V_18 -> V_75 , V_75 , sizeof( V_18 -> V_75 ) ) ;
V_3 = & V_18 -> V_3 ;
F_64 ( V_3 , V_10 , & V_151 ) ;
V_3 -> V_96 |= V_152 ;
V_7 = & V_18 -> V_7 ;
F_65 ( V_7 , 5 ) ;
V_18 -> V_50 = F_66 ( V_7 , & V_153 ,
V_154 , V_51 ,
0 , V_155 ) ;
V_18 -> V_129 = F_67 ( V_7 , NULL ,
V_156 , 0 , 1 , 0 , 0 ) ;
V_18 -> V_130 = F_67 ( V_7 , NULL ,
V_157 , 0 , 1 , 0 , 0 ) ;
V_18 -> V_131 = F_67 ( V_7 , NULL ,
V_158 , 0 , 1 , 0 , 0 ) ;
V_18 -> V_52 =
F_66 ( V_7 , & V_153 ,
V_159 , V_45 ,
0 , V_43 ) ;
V_3 -> V_160 = V_7 ;
if ( V_7 -> error ) {
V_143 = V_7 -> error ;
goto V_161;
}
V_18 -> V_50 -> V_162 = true ;
V_18 -> V_129 -> V_162 = true ;
V_18 -> V_130 -> V_162 = true ;
V_18 -> V_131 -> V_162 = true ;
V_18 -> V_52 -> V_162 = true ;
V_18 -> V_88 . V_96 = V_163 ;
V_143 = F_68 ( & V_3 -> V_164 , 1 , & V_18 -> V_88 , 0 ) ;
if ( V_143 )
goto V_161;
V_18 -> V_60 = F_4 ( V_3 , 0x0 ) ;
if ( V_18 -> V_60 != 2 ) {
F_9 ( V_3 , L_88 , V_18 -> V_60 ) ;
V_143 = - V_144 ;
goto V_165;
}
F_12 ( 1 , V_19 , V_3 , L_89 ,
F_4 ( V_3 , 0x41 ) , V_18 -> V_60 ) ;
V_18 -> V_21 = F_69 ( V_10 -> V_145 , ( 0x7e >> 1 ) ) ;
if ( V_18 -> V_21 == NULL ) {
F_9 ( V_3 , L_90 ) ;
V_143 = - V_149 ;
goto V_165;
}
V_18 -> V_121 = F_70 ( V_3 -> V_72 ) ;
if ( V_18 -> V_121 == NULL ) {
F_9 ( V_3 , L_91 ) ;
V_143 = - V_149 ;
goto V_166;
}
F_71 ( & V_18 -> V_117 , F_47 ) ;
V_18 -> V_39 = V_138 ;
F_58 ( V_3 ) ;
F_29 ( V_3 , true ) ;
F_25 ( V_3 , L_92 , V_10 -> V_72 ,
V_10 -> V_147 << 1 , V_10 -> V_145 -> V_72 ) ;
return 0 ;
V_166:
F_72 ( V_18 -> V_21 ) ;
V_165:
F_73 ( & V_3 -> V_164 ) ;
V_161:
F_74 ( & V_18 -> V_7 ) ;
return V_143 ;
}
static int F_75 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_76 ( V_10 ) ;
struct V_1 * V_18 = F_1 ( V_3 ) ;
V_18 -> V_60 = - 1 ;
F_12 ( 1 , V_19 , V_3 , L_93 , V_10 -> V_72 ,
V_10 -> V_147 << 1 , V_10 -> V_145 -> V_72 ) ;
F_34 ( V_3 , false ) ;
F_42 ( V_3 , false ) ;
F_58 ( V_3 ) ;
F_77 ( & V_18 -> V_117 ) ;
F_72 ( V_18 -> V_21 ) ;
F_78 ( V_18 -> V_121 ) ;
F_79 ( V_3 ) ;
F_73 ( & V_3 -> V_164 ) ;
F_74 ( V_3 -> V_160 ) ;
return 0 ;
}
