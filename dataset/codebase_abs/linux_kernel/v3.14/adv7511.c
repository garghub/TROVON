static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static T_1 F_4 ( struct V_8 * V_9 ,
T_2 V_10 , bool V_11 )
{
union V_12 V_13 ;
if ( ! F_5 ( V_9 -> V_14 , V_9 -> V_15 , V_9 -> V_16 ,
V_17 , V_10 ,
V_18 , & V_13 ) )
return V_13 . V_19 ;
if ( V_11 )
F_6 ( V_9 , L_1 ,
V_9 -> V_15 , V_10 ) ;
return - 1 ;
}
static T_1 F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ ) {
int V_21 = F_4 ( V_9 , V_10 , true ) ;
if ( V_21 >= 0 ) {
if ( V_20 )
F_6 ( V_9 , L_2 , V_20 ) ;
return V_21 ;
}
}
F_6 ( V_9 , L_3 ) ;
return - 1 ;
}
static int F_8 ( struct V_2 * V_3 , T_2 V_22 )
{
struct V_8 * V_9 = F_9 ( V_3 ) ;
return F_7 ( V_9 , V_22 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_22 , T_2 V_23 )
{
struct V_8 * V_9 = F_9 ( V_3 ) ;
int V_21 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ ) {
V_21 = F_11 ( V_9 , V_22 , V_23 ) ;
if ( V_21 == 0 )
return 0 ;
}
F_12 ( V_3 , L_4 , V_24 ) ;
return V_21 ;
}
static inline void F_13 ( struct V_2 * V_3 , T_2 V_22 , T_3 V_25 , T_3 V_26 )
{
F_10 ( V_3 , V_22 , ( F_8 ( V_3 , V_22 ) & V_25 ) | V_26 ) ;
}
static int F_14 ( struct V_8 * V_9 ,
T_2 V_10 , unsigned V_27 , T_2 * V_28 )
{
union V_12 V_13 ;
int V_21 ;
if ( V_27 > V_29 )
V_27 = V_29 ;
V_13 . V_30 [ 0 ] = V_27 ;
V_21 = F_5 ( V_9 -> V_14 , V_9 -> V_15 , V_9 -> V_16 ,
V_17 , V_10 ,
V_31 , & V_13 ) ;
memcpy ( V_28 , V_13 . V_30 + 1 , V_27 ) ;
return V_21 ;
}
static inline void F_15 ( struct V_2 * V_3 , T_4 V_32 , T_3 * V_33 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_20 ;
int V_35 = 0 ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
for ( V_20 = 0 ; ! V_35 && V_20 < V_32 ; V_20 += V_29 )
V_35 = F_14 ( V_34 -> V_37 , V_20 ,
V_29 , V_33 + V_20 ) ;
if ( V_35 )
F_12 ( V_3 , L_6 , V_24 ) ;
}
static inline bool F_17 ( struct V_2 * V_3 )
{
return F_8 ( V_3 , 0x42 ) & V_38 ;
}
static inline bool F_18 ( struct V_2 * V_3 )
{
return F_8 ( V_3 , 0x42 ) & V_39 ;
}
static void F_19 ( struct V_2 * V_3 , T_3 V_40 )
{
F_13 ( V_3 , 0x18 , 0x9f , ( V_40 & 0x3 ) << 5 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
T_5 V_41 , T_5 V_42 , T_5 V_43 , T_5 V_44 ,
T_5 V_45 , T_5 V_46 , T_5 V_47 , T_5 V_48 ,
T_5 V_49 , T_5 V_50 , T_5 V_51 , T_5 V_52 )
{
F_13 ( V_3 , 0x18 , 0xe0 , V_41 >> 8 ) ;
F_10 ( V_3 , 0x19 , V_41 ) ;
F_13 ( V_3 , 0x1A , 0xe0 , V_42 >> 8 ) ;
F_10 ( V_3 , 0x1B , V_42 ) ;
F_13 ( V_3 , 0x1c , 0xe0 , V_43 >> 8 ) ;
F_10 ( V_3 , 0x1d , V_43 ) ;
F_13 ( V_3 , 0x1e , 0xe0 , V_44 >> 8 ) ;
F_10 ( V_3 , 0x1f , V_44 ) ;
F_13 ( V_3 , 0x20 , 0xe0 , V_45 >> 8 ) ;
F_10 ( V_3 , 0x21 , V_45 ) ;
F_13 ( V_3 , 0x22 , 0xe0 , V_46 >> 8 ) ;
F_10 ( V_3 , 0x23 , V_46 ) ;
F_13 ( V_3 , 0x24 , 0xe0 , V_47 >> 8 ) ;
F_10 ( V_3 , 0x25 , V_47 ) ;
F_13 ( V_3 , 0x26 , 0xe0 , V_48 >> 8 ) ;
F_10 ( V_3 , 0x27 , V_48 ) ;
F_13 ( V_3 , 0x28 , 0xe0 , V_49 >> 8 ) ;
F_10 ( V_3 , 0x29 , V_49 ) ;
F_13 ( V_3 , 0x2A , 0xe0 , V_50 >> 8 ) ;
F_10 ( V_3 , 0x2B , V_50 ) ;
F_13 ( V_3 , 0x2C , 0xe0 , V_51 >> 8 ) ;
F_10 ( V_3 , 0x2D , V_51 ) ;
F_13 ( V_3 , 0x2E , 0xe0 , V_52 >> 8 ) ;
F_10 ( V_3 , 0x2F , V_52 ) ;
}
static void F_21 ( struct V_2 * V_3 , bool V_53 )
{
if ( V_53 ) {
T_3 V_54 = 0 ;
F_19 ( V_3 , V_54 ) ;
F_20 ( V_3 ,
4096 - 564 , 0 , 0 , 256 ,
0 , 4096 - 564 , 0 , 256 ,
0 , 0 , 4096 - 564 , 256 ) ;
F_13 ( V_3 , 0x18 , 0x7f , 0x80 ) ;
F_13 ( V_3 , 0x57 , 0xf3 , 0x04 ) ;
} else {
F_13 ( V_3 , 0x18 , 0x7f , 0x0 ) ;
F_13 ( V_3 , 0x57 , 0xf3 , 0x08 ) ;
}
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( V_34 -> V_55 . V_56 . V_57 & V_58 ) {
F_13 ( V_3 , 0x57 , 0x7f , 0x00 ) ;
} else {
F_13 ( V_3 , 0x57 , 0x7f , 0x80 ) ;
}
}
static int F_23 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
switch ( V_5 -> V_23 ) {
default:
return - V_59 ;
break;
case V_60 : {
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( V_34 -> V_55 . V_56 . V_57 & V_58 ) {
F_21 ( V_3 , true ) ;
} else {
F_21 ( V_3 , false ) ;
}
}
break;
case V_61 :
F_21 ( V_3 , true ) ;
break;
case V_62 :
F_21 ( V_3 , false ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_7 , V_24 , V_5 -> V_63 , V_5 -> V_23 ) ;
if ( V_34 -> V_64 == V_5 ) {
F_13 ( V_3 , 0xaf , 0xfd , V_5 -> V_23 == V_65 ? 0x02 : 0x00 ) ;
return 0 ;
}
if ( V_34 -> V_66 == V_5 )
return F_23 ( V_3 , V_5 ) ;
return - V_59 ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_26 ( V_3 , L_8 ) ;
}
static int F_27 ( struct V_2 * V_3 , struct V_67 * V_22 )
{
V_22 -> V_68 = 1 ;
switch ( V_22 -> V_22 >> 8 ) {
case 0 :
V_22 -> V_23 = F_8 ( V_3 , V_22 -> V_22 & 0xff ) ;
break;
default:
F_26 ( V_3 , L_9 , V_22 -> V_22 ) ;
F_25 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , const struct V_67 * V_22 )
{
switch ( V_22 -> V_22 >> 8 ) {
case 0 :
F_10 ( V_3 , V_22 -> V_22 & 0xff , V_22 -> V_23 & 0xff ) ;
break;
default:
F_26 ( V_3 , L_9 , V_22 -> V_22 ) ;
F_25 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_69 * V_70 = & V_34 -> V_70 ;
static const char * const V_71 [] = {
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 , L_17 , L_18 , L_19 , L_20 , L_21 , L_22 , L_23 , L_24 , L_25
} ;
static const char * const V_72 [] = {
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_19 , L_20 , L_21 , L_22 , L_23 , L_24 , L_25
} ;
F_26 ( V_3 , L_35 , V_34 -> V_73 ? L_36 : L_37 ) ;
F_26 ( V_3 , L_38 ,
( F_8 ( V_3 , 0x42 ) & V_38 ) ? L_39 : L_40 ,
( F_8 ( V_3 , 0x42 ) & V_39 ) ? L_39 : L_40 ,
V_70 -> V_74 ? L_41 : L_40 ,
V_70 -> V_75 ) ;
F_26 ( V_3 , L_42 ,
( F_8 ( V_3 , 0xaf ) & 0x02 ) ?
L_43 : L_44 ,
( F_8 ( V_3 , 0xa1 ) & 0x3c ) ?
L_45 : L_46 ) ;
F_26 ( V_3 , L_47 ,
V_71 [ F_8 ( V_3 , 0xc8 ) & 0xf ] ,
V_72 [ F_8 ( V_3 , 0xc8 ) >> 4 ] , V_34 -> V_76 ,
F_8 ( V_3 , 0x94 ) , F_8 ( V_3 , 0x96 ) ) ;
F_26 ( V_3 , L_48 , F_8 ( V_3 , 0x18 ) & 0x80 ? L_49 : L_50 ) ;
if ( F_8 ( V_3 , 0xaf ) & 0x02 ) {
T_2 V_77 = F_8 ( V_3 , 0x0a ) & 0x80 ;
T_6 V_78 = ( F_8 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_8 ( V_3 , 0x02 ) << 8 |
F_8 ( V_3 , 0x03 ) ;
T_2 V_79 = F_8 ( V_3 , 0x3e ) >> 2 ;
T_2 V_80 = F_8 ( V_3 , 0x3d ) & 0x3f ;
T_6 V_81 ;
if ( V_77 )
V_81 = ( F_8 ( V_3 , 0x07 ) & 0xf ) << 16 |
F_8 ( V_3 , 0x08 ) << 8 |
F_8 ( V_3 , 0x09 ) ;
else
V_81 = ( F_8 ( V_3 , 0x04 ) & 0xf ) << 16 |
F_8 ( V_3 , 0x05 ) << 8 |
F_8 ( V_3 , 0x06 ) ;
F_26 ( V_3 , L_51 ,
V_77 ? L_52 : L_53 , V_78 , V_81 ) ;
F_26 ( V_3 , L_54 ,
V_79 , V_80 ) ;
}
if ( V_34 -> V_55 . type == V_82 )
F_30 ( V_3 -> V_83 , L_55 ,
& V_34 -> V_55 , false ) ;
else
F_26 ( V_3 , L_56 ) ;
F_26 ( V_3 , L_57 , V_34 -> V_84 ) ;
F_26 ( V_3 , L_58 , V_34 -> V_85 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , int V_86 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
const int V_87 = 20 ;
int V_20 ;
F_16 ( 1 , V_36 , V_3 , L_59 , V_24 , V_86 ? L_36 : L_37 ) ;
V_34 -> V_73 = V_86 ;
if ( ! V_86 ) {
F_13 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
return true ;
}
for ( V_20 = 0 ; V_20 < V_87 ; V_20 ++ ) {
F_13 ( V_3 , 0x41 , 0xbf , 0x0 ) ;
if ( ( F_8 ( V_3 , 0x41 ) & 0x40 ) == 0 )
break;
F_13 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
F_32 ( 10 ) ;
}
if ( V_20 == V_87 ) {
F_16 ( 1 , V_36 , V_3 , L_60 , V_24 ) ;
F_31 ( V_3 , 0 ) ;
return false ;
}
if ( V_20 > 1 )
F_16 ( 1 , V_36 , V_3 , L_61 , V_24 , V_20 ) ;
F_10 ( V_3 , 0x98 , 0x03 ) ;
F_13 ( V_3 , 0x9a , 0xfe , 0x70 ) ;
F_10 ( V_3 , 0x9c , 0x30 ) ;
F_13 ( V_3 , 0x9d , 0xfc , 0x01 ) ;
F_10 ( V_3 , 0xa2 , 0xa4 ) ;
F_10 ( V_3 , 0xa3 , 0xa4 ) ;
F_10 ( V_3 , 0xe0 , 0xd0 ) ;
F_10 ( V_3 , 0xf9 , 0x00 ) ;
F_10 ( V_3 , 0x43 , V_34 -> V_84 ) ;
F_10 ( V_3 , 0xc9 , 0xf ) ;
return true ;
}
static void F_33 ( struct V_2 * V_3 , bool V_53 )
{
T_3 V_88 = V_89 | V_90 ;
T_3 V_91 ;
int V_87 = 100 ;
F_16 ( 2 , V_36 , V_3 , L_62 , V_24 , V_53 ? L_63 : L_64 ) ;
if ( ! V_53 )
V_88 = 0 ;
else if ( F_17 ( V_3 ) )
V_88 |= V_92 ;
do {
F_10 ( V_3 , 0x94 , V_88 ) ;
V_91 = F_8 ( V_3 , 0x94 ) ;
} while ( V_87 -- && V_91 != V_88 );
if ( V_91 == V_88 )
return;
F_12 ( V_3 , L_65 ) ;
}
static int F_34 ( struct V_2 * V_3 , T_6 V_93 , bool * V_94 )
{
T_3 V_95 ;
F_33 ( V_3 , false ) ;
V_95 = F_8 ( V_3 , 0x96 ) ;
F_10 ( V_3 , 0x96 , V_95 ) ;
F_16 ( 1 , V_36 , V_3 , L_66 , V_24 , V_95 ) ;
if ( V_95 & ( V_89 | V_90 ) )
F_35 ( V_3 ) ;
if ( V_95 & V_92 )
F_36 ( V_3 ) ;
F_33 ( V_3 , true ) ;
if ( V_94 )
* V_94 = true ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_96 * V_70 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( V_70 -> V_97 != 0 )
return - V_59 ;
if ( ( V_70 -> V_75 == 0 ) || ( V_70 -> V_75 > 256 ) )
return - V_59 ;
if ( ! V_70 -> V_70 )
return - V_59 ;
if ( ! V_34 -> V_70 . V_74 ) {
F_16 ( 1 , V_36 , V_3 , L_67 ) ;
return - V_98 ;
}
if ( V_70 -> V_99 >= V_34 -> V_70 . V_74 * 2 )
return - V_100 ;
if ( ( V_70 -> V_75 + V_70 -> V_99 ) >= V_34 -> V_70 . V_74 * 2 )
V_70 -> V_75 = V_34 -> V_70 . V_74 * 2 - V_70 -> V_99 ;
memcpy ( V_70 -> V_70 , & V_34 -> V_70 . V_13 [ V_70 -> V_99 * 128 ] ,
128 * V_70 -> V_75 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , int V_53 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_68 , V_24 , ( V_53 ? L_69 : L_70 ) ) ;
F_13 ( V_3 , 0xa1 , ~ 0x3c , ( V_53 ? 0 : 0x3c ) ) ;
if ( V_53 ) {
F_35 ( V_3 ) ;
} else {
F_31 ( V_3 , 0 ) ;
V_34 -> V_101 = false ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
if ( ! F_40 ( V_103 , & V_104 , NULL , NULL ) )
return - V_59 ;
F_41 ( V_103 , & V_104 , 0 , NULL , NULL ) ;
V_103 -> V_56 . V_16 &= ~ V_105 ;
V_34 -> V_55 = * V_103 ;
F_23 ( V_3 , V_34 -> V_66 ) ;
F_22 ( V_3 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
if ( ! V_103 )
return - V_59 ;
* V_103 = V_34 -> V_55 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_106 * V_103 )
{
return F_44 ( V_103 , & V_104 , NULL , NULL ) ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_107 * V_108 )
{
* V_108 = V_104 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , int V_53 )
{
F_16 ( 1 , V_36 , V_3 , L_68 , V_24 , ( V_53 ? L_69 : L_70 ) ) ;
if ( V_53 )
F_13 ( V_3 , 0x4b , 0x3f , 0x80 ) ;
else
F_13 ( V_3 , 0x4b , 0x3f , 0x40 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , T_6 V_109 )
{
T_6 V_78 ;
switch ( V_109 ) {
case 32000 : V_78 = 4096 ; break;
case 44100 : V_78 = 6272 ; break;
case 48000 : V_78 = 6144 ; break;
case 88200 : V_78 = 12544 ; break;
case 96000 : V_78 = 12288 ; break;
case 176400 : V_78 = 25088 ; break;
case 192000 : V_78 = 24576 ; break;
default:
return - V_59 ;
}
F_10 ( V_3 , 0x01 , ( V_78 >> 16 ) & 0xf ) ;
F_10 ( V_3 , 0x02 , ( V_78 >> 8 ) & 0xff ) ;
F_10 ( V_3 , 0x03 , V_78 & 0xff ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 , T_6 V_109 )
{
T_6 V_110 ;
switch ( V_109 ) {
case 32000 : V_110 = 0x30 ; break;
case 44100 : V_110 = 0x00 ; break;
case 48000 : V_110 = 0x20 ; break;
case 88200 : V_110 = 0x80 ; break;
case 96000 : V_110 = 0xa0 ; break;
case 176400 : V_110 = 0xc0 ; break;
case 192000 : V_110 = 0xe0 ; break;
default:
return - V_59 ;
}
F_13 ( V_3 , 0x15 , 0xf , V_110 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_6 V_111 , T_6 V_112 , T_6 V_113 )
{
F_13 ( V_3 , 0x73 , 0xf8 , 0x1 ) ;
F_10 ( V_3 , 0x76 , 0x00 ) ;
F_13 ( V_3 , 0x14 , 0xf0 , 0x02 ) ;
return 0 ;
}
static void F_50 ( int V_114 , int V_36 , struct V_2 * V_3 , int V_115 , T_3 * V_33 )
{
if ( V_36 >= V_114 ) {
int V_20 , V_116 ;
F_16 ( V_114 , V_36 , V_3 , L_71 , V_115 ) ;
for ( V_20 = 0 ; V_20 < 256 ; V_20 += 16 ) {
T_2 V_117 [ 128 ] ;
T_2 * V_118 = V_117 ;
if ( V_20 == 128 )
F_16 ( V_114 , V_36 , V_3 , L_72 ) ;
for ( V_116 = V_20 ; V_116 < V_20 + 16 ; V_116 ++ ) {
sprintf ( V_118 , L_73 , V_33 [ V_116 ] ) ;
V_118 += 6 ;
}
V_118 [ 0 ] = '\0' ;
F_16 ( V_114 , V_36 , V_3 , L_74 , V_117 ) ;
}
}
}
static void F_51 ( struct V_119 * V_120 )
{
struct V_121 * V_122 = F_52 ( V_120 ) ;
struct V_1 * V_34 = F_2 ( V_122 , struct V_1 , V_123 ) ;
struct V_2 * V_3 = & V_34 -> V_3 ;
struct V_124 V_125 ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
if ( F_36 ( V_3 ) ) {
return;
}
if ( F_17 ( V_3 ) ) {
if ( V_34 -> V_70 . V_126 ) {
V_34 -> V_70 . V_126 -- ;
F_16 ( 1 , V_36 , V_3 , L_75 , V_24 ) ;
V_34 -> V_101 = false ;
F_31 ( V_3 , false ) ;
F_31 ( V_3 , true ) ;
F_53 ( V_34 -> V_127 , & V_34 -> V_123 , V_128 ) ;
return;
}
}
V_125 . V_129 = false ;
V_125 . V_115 = F_8 ( V_3 , 0xc4 ) ;
F_54 ( V_3 , V_130 , ( void * ) & V_125 ) ;
F_16 ( 1 , V_36 , V_3 , L_76 , V_24 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_16 ( 1 , V_36 , V_3 , L_74 , V_24 ) ;
F_48 ( V_3 , 48000 ) ;
F_47 ( V_3 , 48000 ) ;
F_49 ( V_3 , 0 , 0 , 0 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_74 , V_24 ) ;
F_13 ( V_3 , 0x15 , 0xf0 , 0x0 ) ;
F_13 ( V_3 , 0x16 , 0x7f , 0x0 ) ;
F_13 ( V_3 , 0x17 , 0xf9 , 0x06 ) ;
F_13 ( V_3 , 0x3b , 0x9f , 0x0 ) ;
F_13 ( V_3 , 0x18 , 0x7f , 0x0 ) ;
F_13 ( V_3 , 0x55 , 0x9c , 0x12 ) ;
F_13 ( V_3 , 0x44 , 0xe7 , 0x10 ) ;
F_10 ( V_3 , 0x56 , 0xa8 ) ;
F_13 ( V_3 , 0xaf , 0xed , 0x0 ) ;
F_13 ( V_3 , 0xba , 0x1f , 0x60 ) ;
F_55 ( V_3 ) ;
F_57 ( & V_34 -> V_7 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_131 V_132 ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
V_132 . V_129 = V_34 -> V_101 ;
F_54 ( V_3 , V_133 , ( void * ) & V_132 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_3 V_93 = F_8 ( V_3 , 0x42 ) ;
F_16 ( 1 , V_36 , V_3 , L_77 ,
V_24 ,
V_93 ,
V_93 & V_38 ? L_78 : L_79 ,
V_93 & V_39 ? L_80 : L_79 ) ;
F_59 ( V_34 -> V_134 , F_17 ( V_3 ) ? 0x1 : 0x0 ) ;
F_59 ( V_34 -> V_135 , F_18 ( V_3 ) ? 0x1 : 0x0 ) ;
F_59 ( V_34 -> V_136 , V_34 -> V_70 . V_74 ? 0x1 : 0x0 ) ;
if ( ( V_93 & V_38 ) && ( ( V_93 & V_39 ) || V_34 -> V_70 . V_74 ) ) {
F_16 ( 1 , V_36 , V_3 , L_81 , V_24 ) ;
if ( ! V_34 -> V_101 ) {
F_16 ( 1 , V_36 , V_3 , L_82 , V_24 ) ;
V_34 -> V_101 = true ;
F_33 ( V_3 , true ) ;
if ( ! F_31 ( V_3 , true ) ) {
F_16 ( 1 , V_36 , V_3 , L_83 , V_24 ) ;
return;
}
F_56 ( V_3 ) ;
F_58 ( V_3 ) ;
V_34 -> V_70 . V_126 = V_137 ;
F_53 ( V_34 -> V_127 , & V_34 -> V_123 , V_128 ) ;
}
} else if ( V_93 & V_38 ) {
F_16 ( 1 , V_36 , V_3 , L_84 , V_24 ) ;
V_34 -> V_70 . V_126 = V_137 ;
F_53 ( V_34 -> V_127 , & V_34 -> V_123 , V_128 ) ;
} else if ( ! ( V_93 & V_38 ) ) {
F_16 ( 1 , V_36 , V_3 , L_85 , V_24 ) ;
if ( V_34 -> V_101 ) {
F_16 ( 1 , V_36 , V_3 , L_86 , V_24 ) ;
V_34 -> V_101 = false ;
F_58 ( V_3 ) ;
}
F_31 ( V_3 , false ) ;
memset ( & V_34 -> V_70 , 0 , sizeof( struct V_69 ) ) ;
}
}
static bool F_60 ( T_3 * V_138 )
{
T_3 V_139 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ )
V_139 += V_138 [ V_20 ] ;
return V_139 == 0 ;
}
static bool F_61 ( struct V_2 * V_3 , T_6 V_115 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_6 V_75 = V_34 -> V_70 . V_75 ;
T_3 * V_13 = V_34 -> V_70 . V_13 ;
if ( ! F_60 ( & V_13 [ V_115 * 256 ] ) )
return false ;
if ( ( V_115 + 1 ) * 2 <= V_75 )
return F_60 ( & V_13 [ V_115 * 256 + 128 ] ) ;
return true ;
}
static bool F_62 ( struct V_2 * V_3 , T_6 V_115 )
{
static const T_2 V_140 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00
} ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_2 * V_13 = V_34 -> V_70 . V_13 ;
if ( V_115 != 0 )
return true ;
return ! memcmp ( V_13 , V_140 , sizeof( V_140 ) ) ;
}
static bool F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_3 V_141 = F_8 ( V_3 , 0xc5 ) ;
F_16 ( 1 , V_36 , V_3 , L_87 ,
V_24 , V_137 - V_34 -> V_70 . V_126 ) ;
if ( V_34 -> V_70 . V_142 )
return true ;
if ( V_141 & V_143 ) {
int V_115 = F_8 ( V_3 , 0xc4 ) ;
struct V_124 V_125 ;
if ( V_115 >= V_144 ) {
F_12 ( V_3 , L_88 ) ;
return false ;
}
F_16 ( 1 , V_36 , V_3 , L_89 , V_24 , V_115 ) ;
F_15 ( V_3 , 256 , & V_34 -> V_70 . V_13 [ V_115 * 256 ] ) ;
F_50 ( 2 , V_36 , V_3 , V_115 , & V_34 -> V_70 . V_13 [ V_115 * 256 ] ) ;
if ( V_115 == 0 ) {
V_34 -> V_70 . V_75 = V_34 -> V_70 . V_13 [ 0x7e ] + 1 ;
F_16 ( 1 , V_36 , V_3 , L_90 , V_24 , V_34 -> V_70 . V_75 ) ;
}
if ( ! F_61 ( V_3 , V_115 ) ||
! F_62 ( V_3 , V_115 ) ) {
F_12 ( V_3 , L_91 , V_24 ) ;
V_34 -> V_101 = false ;
F_31 ( V_3 , false ) ;
F_31 ( V_3 , true ) ;
return false ;
}
V_34 -> V_70 . V_74 = V_115 + 1 ;
if ( ( ( V_34 -> V_70 . V_13 [ 0x7e ] >> 1 ) + 1 ) > V_34 -> V_70 . V_74 ) {
F_16 ( 1 , V_36 , V_3 , L_92 , V_24 , V_34 -> V_70 . V_74 ) ;
F_10 ( V_3 , 0xc9 , 0xf ) ;
F_10 ( V_3 , 0xc4 , V_34 -> V_70 . V_74 ) ;
V_34 -> V_70 . V_126 = V_137 ;
F_53 ( V_34 -> V_127 , & V_34 -> V_123 , V_128 ) ;
return false ;
}
F_16 ( 1 , V_36 , V_3 , L_93 , V_24 , V_34 -> V_70 . V_74 ) ;
V_34 -> V_70 . V_142 = true ;
V_125 . V_129 = true ;
V_125 . V_115 = 0 ;
V_34 -> V_76 ++ ;
F_59 ( V_34 -> V_136 , V_34 -> V_70 . V_74 ? 0x1 : 0x0 ) ;
F_54 ( V_3 , V_130 , ( void * ) & V_125 ) ;
return V_125 . V_129 ;
}
return false ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_69 * V_70 = & V_34 -> V_70 ;
F_16 ( 1 , V_36 , V_3 , L_74 , V_24 ) ;
F_10 ( V_3 , 0x96 , 0xff ) ;
F_13 ( V_3 , 0xd6 , 0x3f , 0xc0 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_34 -> V_101 = false ;
F_33 ( V_3 , false ) ;
F_38 ( V_3 , false ) ;
F_46 ( V_3 , false ) ;
}
static int F_64 ( struct V_8 * V_9 , const struct V_145 * V_63 )
{
struct V_1 * V_34 ;
struct V_146 * V_147 = V_9 -> V_148 . V_149 ;
struct V_150 * V_7 ;
struct V_2 * V_3 ;
T_2 V_151 [ 2 ] ;
int V_35 = - V_152 ;
if ( ! F_65 ( V_9 -> V_14 , V_153 ) )
return - V_152 ;
V_34 = F_66 ( & V_9 -> V_148 , sizeof( struct V_1 ) , V_154 ) ;
if ( ! V_34 )
return - V_155 ;
if ( ! V_147 ) {
F_6 ( V_9 , L_94 ) ;
return - V_156 ;
}
memcpy ( & V_34 -> V_147 , V_147 , sizeof( V_34 -> V_147 ) ) ;
V_3 = & V_34 -> V_3 ;
F_16 ( 1 , V_36 , V_3 , L_95 ,
V_9 -> V_15 << 1 ) ;
F_67 ( V_3 , V_9 , & V_157 ) ;
V_7 = & V_34 -> V_7 ;
F_68 ( V_7 , 10 ) ;
V_34 -> V_64 = F_69 ( V_7 , & V_158 ,
V_159 , V_65 ,
0 , V_160 ) ;
V_34 -> V_134 = F_70 ( V_7 , NULL ,
V_161 , 0 , 1 , 0 , 0 ) ;
V_34 -> V_135 = F_70 ( V_7 , NULL ,
V_162 , 0 , 1 , 0 , 0 ) ;
V_34 -> V_136 = F_70 ( V_7 , NULL ,
V_163 , 0 , 1 , 0 , 0 ) ;
V_34 -> V_66 =
F_69 ( V_7 , & V_158 ,
V_164 , V_62 ,
0 , V_60 ) ;
V_3 -> V_165 = V_7 ;
if ( V_7 -> error ) {
V_35 = V_7 -> error ;
goto V_166;
}
V_34 -> V_64 -> V_167 = true ;
V_34 -> V_134 -> V_167 = true ;
V_34 -> V_135 -> V_167 = true ;
V_34 -> V_136 -> V_167 = true ;
V_34 -> V_66 -> V_167 = true ;
V_34 -> V_97 . V_16 = V_168 ;
V_35 = F_71 ( & V_3 -> V_169 , 1 , & V_34 -> V_97 , 0 ) ;
if ( V_35 )
goto V_166;
V_34 -> V_84 = V_34 -> V_147 . V_37 << 1 ;
V_34 -> V_85 = V_34 -> V_147 . V_170 << 1 ;
V_34 -> V_171 = F_8 ( V_3 , 0x0 ) ;
V_151 [ 0 ] = F_8 ( V_3 , 0xf5 ) ;
V_151 [ 1 ] = F_8 ( V_3 , 0xf6 ) ;
if ( V_151 [ 0 ] != 0x75 || V_151 [ 1 ] != 0x11 ) {
F_12 ( V_3 , L_96 , V_151 [ 0 ] , V_151 [ 1 ] ) ;
V_35 = - V_152 ;
goto V_172;
}
V_34 -> V_37 = F_72 ( V_9 -> V_14 , V_34 -> V_84 >> 1 ) ;
if ( V_34 -> V_37 == NULL ) {
F_12 ( V_3 , L_97 ) ;
V_35 = - V_155 ;
goto V_172;
}
F_10 ( V_3 , 0xe2 , 0x01 ) ;
V_34 -> V_127 = F_73 ( V_3 -> V_83 ) ;
if ( V_34 -> V_127 == NULL ) {
F_12 ( V_3 , L_98 ) ;
V_35 = - V_155 ;
goto V_173;
}
F_74 ( & V_34 -> V_123 , F_51 ) ;
F_63 ( V_3 ) ;
F_33 ( V_3 , true ) ;
F_35 ( V_3 ) ;
F_26 ( V_3 , L_99 , V_9 -> V_83 ,
V_9 -> V_15 << 1 , V_9 -> V_14 -> V_83 ) ;
return 0 ;
V_173:
F_75 ( V_34 -> V_37 ) ;
V_172:
F_76 ( & V_3 -> V_169 ) ;
V_166:
F_77 ( & V_34 -> V_7 ) ;
return V_35 ;
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_79 ( V_9 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
V_34 -> V_171 = - 1 ;
F_16 ( 1 , V_36 , V_3 , L_100 , V_9 -> V_83 ,
V_9 -> V_15 << 1 , V_9 -> V_14 -> V_83 ) ;
F_63 ( V_3 ) ;
F_80 ( & V_34 -> V_123 ) ;
F_75 ( V_34 -> V_37 ) ;
F_81 ( V_34 -> V_127 ) ;
F_82 ( V_3 ) ;
F_76 ( & V_3 -> V_169 ) ;
F_77 ( V_3 -> V_165 ) ;
return 0 ;
}
