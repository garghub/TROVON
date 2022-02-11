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
static inline void F_13 ( struct V_2 * V_3 , T_2 V_22 , T_2 V_25 , T_2 V_26 )
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
static void F_15 ( struct V_2 * V_3 , T_3 V_32 , T_4 * V_33 )
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
static inline int F_17 ( struct V_2 * V_3 , T_2 V_22 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
return F_18 ( V_34 -> V_38 , V_22 ) ;
}
static int F_19 ( struct V_2 * V_3 , T_2 V_22 , T_2 V_23 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_21 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ ) {
V_21 = F_11 ( V_34 -> V_38 , V_22 , V_23 ) ;
if ( V_21 == 0 )
return 0 ;
}
F_12 ( V_3 , L_7 , V_24 ) ;
return V_21 ;
}
static inline int F_20 ( struct V_2 * V_3 , T_2 V_22 , T_2 V_39 ,
T_2 V_23 )
{
return F_19 ( V_3 , V_22 , ( F_17 ( V_3 , V_22 ) & V_39 ) | V_23 ) ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_22 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
return F_7 ( V_34 -> V_40 , V_22 ) ;
}
static int F_22 ( struct V_2 * V_3 , T_2 V_22 , T_2 V_23 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_21 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ ) {
V_21 = F_11 ( V_34 -> V_40 , V_22 , V_23 ) ;
if ( V_21 == 0 )
return 0 ;
}
F_12 ( V_3 , L_4 , V_24 ) ;
return V_21 ;
}
static inline void F_23 ( struct V_2 * V_3 , T_2 V_22 , T_2 V_25 , T_2 V_26 )
{
F_22 ( V_3 , V_22 , ( F_21 ( V_3 , V_22 ) & V_25 ) | V_26 ) ;
}
static inline bool F_24 ( struct V_2 * V_3 )
{
return F_8 ( V_3 , 0x42 ) & V_41 ;
}
static inline bool F_25 ( struct V_2 * V_3 )
{
return F_8 ( V_3 , 0x42 ) & V_42 ;
}
static void F_26 ( struct V_2 * V_3 , T_2 V_43 )
{
F_13 ( V_3 , 0x18 , 0x9f , ( V_43 & 0x3 ) << 5 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
T_5 V_44 , T_5 V_45 , T_5 V_46 , T_5 V_47 ,
T_5 V_48 , T_5 V_49 , T_5 V_50 , T_5 V_51 ,
T_5 V_52 , T_5 V_53 , T_5 V_54 , T_5 V_55 )
{
F_13 ( V_3 , 0x18 , 0xe0 , V_44 >> 8 ) ;
F_10 ( V_3 , 0x19 , V_44 ) ;
F_13 ( V_3 , 0x1A , 0xe0 , V_45 >> 8 ) ;
F_10 ( V_3 , 0x1B , V_45 ) ;
F_13 ( V_3 , 0x1c , 0xe0 , V_46 >> 8 ) ;
F_10 ( V_3 , 0x1d , V_46 ) ;
F_13 ( V_3 , 0x1e , 0xe0 , V_47 >> 8 ) ;
F_10 ( V_3 , 0x1f , V_47 ) ;
F_13 ( V_3 , 0x20 , 0xe0 , V_48 >> 8 ) ;
F_10 ( V_3 , 0x21 , V_48 ) ;
F_13 ( V_3 , 0x22 , 0xe0 , V_49 >> 8 ) ;
F_10 ( V_3 , 0x23 , V_49 ) ;
F_13 ( V_3 , 0x24 , 0xe0 , V_50 >> 8 ) ;
F_10 ( V_3 , 0x25 , V_50 ) ;
F_13 ( V_3 , 0x26 , 0xe0 , V_51 >> 8 ) ;
F_10 ( V_3 , 0x27 , V_51 ) ;
F_13 ( V_3 , 0x28 , 0xe0 , V_52 >> 8 ) ;
F_10 ( V_3 , 0x29 , V_52 ) ;
F_13 ( V_3 , 0x2A , 0xe0 , V_53 >> 8 ) ;
F_10 ( V_3 , 0x2B , V_53 ) ;
F_13 ( V_3 , 0x2C , 0xe0 , V_54 >> 8 ) ;
F_10 ( V_3 , 0x2D , V_54 ) ;
F_13 ( V_3 , 0x2E , 0xe0 , V_55 >> 8 ) ;
F_10 ( V_3 , 0x2F , V_55 ) ;
}
static void F_28 ( struct V_2 * V_3 , bool V_56 )
{
if ( V_56 ) {
T_2 V_57 = 0 ;
F_26 ( V_3 , V_57 ) ;
F_27 ( V_3 ,
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
static void F_29 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( V_34 -> V_58 != V_59 ) {
F_28 ( V_3 , false ) ;
return;
}
switch ( V_5 -> V_23 ) {
case V_60 :
if ( V_34 -> V_61 . V_62 . V_16 & V_63 ) {
F_28 ( V_3 , true ) ;
} else {
F_28 ( V_3 , false ) ;
}
break;
case V_64 :
F_28 ( V_3 , true ) ;
break;
case V_65 :
F_28 ( V_3 , false ) ;
break;
}
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_8 , V_24 , V_5 -> V_66 , V_5 -> V_23 ) ;
if ( V_34 -> V_67 == V_5 ) {
F_13 ( V_3 , 0xaf , 0xfd , V_5 -> V_23 == V_68 ? 0x02 : 0x00 ) ;
return 0 ;
}
if ( V_34 -> V_69 == V_5 ) {
F_29 ( V_3 , V_5 ) ;
return 0 ;
}
if ( V_34 -> V_70 == V_5 ) {
T_2 V_71 , V_72 ;
V_34 -> V_73 = V_5 -> V_23 ;
V_71 = V_34 -> V_73 != V_74 ;
V_72 = V_71 ? V_34 -> V_73 : V_75 ;
F_13 ( V_3 , 0x57 , 0x7f , V_71 << 7 ) ;
F_13 ( V_3 , 0x59 , 0xcf , V_72 << 4 ) ;
return 0 ;
}
return - V_76 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_32 ( V_3 , L_9 ) ;
if ( V_34 -> V_38 )
F_32 ( V_3 , L_10 ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_77 * V_22 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
V_22 -> V_78 = 1 ;
switch ( V_22 -> V_22 >> 8 ) {
case 0 :
V_22 -> V_23 = F_8 ( V_3 , V_22 -> V_22 & 0xff ) ;
break;
case 1 :
if ( V_34 -> V_38 ) {
V_22 -> V_23 = F_17 ( V_3 , V_22 -> V_22 & 0xff ) ;
break;
}
default:
F_32 ( V_3 , L_11 , V_22 -> V_22 ) ;
F_31 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , const struct V_77 * V_22 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
switch ( V_22 -> V_22 >> 8 ) {
case 0 :
F_10 ( V_3 , V_22 -> V_22 & 0xff , V_22 -> V_23 & 0xff ) ;
break;
case 1 :
if ( V_34 -> V_38 ) {
F_19 ( V_3 , V_22 -> V_22 & 0xff , V_22 -> V_23 & 0xff ) ;
break;
}
default:
F_32 ( V_3 , L_11 , V_22 -> V_22 ) ;
F_31 ( V_3 ) ;
break;
}
return 0 ;
}
static T_2 F_35 ( T_2 * V_79 , T_6 V_78 )
{
T_2 V_80 = 0 ;
T_6 V_20 ;
for ( V_20 = 0 ; V_20 < V_78 ; V_20 ++ )
V_80 += V_79 [ V_20 ] ;
return 256 - V_80 ;
}
static void F_36 ( struct V_2 * V_3 , const struct V_81 * V_82 )
{
struct V_8 * V_9 = F_9 ( V_3 ) ;
struct V_83 * V_84 = & V_9 -> V_84 ;
union V_85 V_86 ;
T_2 V_87 [ 32 ] ;
T_2 V_32 ;
int V_20 ;
if ( ! ( F_8 ( V_3 , V_82 -> V_88 ) & V_82 -> V_89 ) ) {
F_32 ( V_3 , L_12 , V_82 -> V_90 ) ;
return;
}
memcpy ( V_87 , V_82 -> V_91 , sizeof( V_82 -> V_91 ) ) ;
V_32 = V_87 [ 2 ] ;
if ( V_32 + 4 > sizeof( V_87 ) ) {
F_12 ( V_3 , L_13 , V_24 , V_82 -> V_90 , V_32 ) ;
return;
}
if ( V_82 -> V_92 >= 0x100 ) {
for ( V_20 = 0 ; V_20 < V_32 ; V_20 ++ )
V_87 [ V_20 + 4 ] = F_21 ( V_3 , V_82 -> V_92 + V_20 - 0x100 ) ;
} else {
for ( V_20 = 0 ; V_20 < V_32 ; V_20 ++ )
V_87 [ V_20 + 4 ] = F_8 ( V_3 , V_82 -> V_92 + V_20 ) ;
}
V_87 [ 3 ] = 0 ;
V_87 [ 3 ] = F_35 ( V_87 , V_32 + 4 ) ;
if ( F_37 ( & V_86 , V_87 ) < 0 ) {
F_12 ( V_3 , L_14 , V_24 , V_82 -> V_90 ) ;
return;
}
F_38 ( V_93 , V_84 , & V_86 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
static const struct V_81 V_82 [] = {
{ L_15 , 0x44 , 0x10 , { 0x82 , 2 , 13 } , 0x55 } ,
{ L_16 , 0x44 , 0x08 , { 0x84 , 1 , 10 } , 0x73 } ,
{ L_17 , 0x40 , 0x40 , { 0x83 , 1 , 25 } , 0x103 } ,
} ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_40 ( V_82 ) ; V_20 ++ )
F_36 ( V_3 , & V_82 [ V_20 ] ) ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_94 * V_95 = & V_34 -> V_95 ;
int V_20 ;
static const char * const V_96 [] = {
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 , L_25 , L_26 , L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_33
} ;
static const char * const V_97 [] = {
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_33
} ;
F_32 ( V_3 , L_43 , V_34 -> V_98 ? L_44 : L_45 ) ;
F_32 ( V_3 , L_46 ,
( F_8 ( V_3 , 0x42 ) & V_41 ) ? L_47 : L_48 ,
( F_8 ( V_3 , 0x42 ) & V_42 ) ? L_47 : L_48 ,
V_95 -> V_99 ? L_49 : L_48 ,
V_95 -> V_100 ) ;
F_32 ( V_3 , L_50 ,
( F_8 ( V_3 , 0xaf ) & 0x02 ) ?
L_51 : L_52 ,
( F_8 ( V_3 , 0xa1 ) & 0x3c ) ?
L_53 : L_54 ) ;
F_32 ( V_3 , L_55 ,
V_96 [ F_8 ( V_3 , 0xc8 ) & 0xf ] ,
V_97 [ F_8 ( V_3 , 0xc8 ) >> 4 ] , V_34 -> V_101 ,
F_8 ( V_3 , 0x94 ) , F_8 ( V_3 , 0x96 ) ) ;
F_32 ( V_3 , L_56 , F_8 ( V_3 , 0x18 ) & 0x80 ? L_57 : L_58 ) ;
if ( F_8 ( V_3 , 0xaf ) & 0x02 ) {
T_2 V_102 = F_8 ( V_3 , 0x0a ) & 0x80 ;
T_7 V_103 = ( F_8 ( V_3 , 0x01 ) & 0xf ) << 16 |
F_8 ( V_3 , 0x02 ) << 8 |
F_8 ( V_3 , 0x03 ) ;
T_2 V_104 = F_8 ( V_3 , 0x3e ) >> 2 ;
T_2 V_105 = F_8 ( V_3 , 0x3d ) & 0x3f ;
T_7 V_106 ;
if ( V_102 )
V_106 = ( F_8 ( V_3 , 0x07 ) & 0xf ) << 16 |
F_8 ( V_3 , 0x08 ) << 8 |
F_8 ( V_3 , 0x09 ) ;
else
V_106 = ( F_8 ( V_3 , 0x04 ) & 0xf ) << 16 |
F_8 ( V_3 , 0x05 ) << 8 |
F_8 ( V_3 , 0x06 ) ;
F_32 ( V_3 , L_59 ,
V_102 ? L_60 : L_61 , V_103 , V_106 ) ;
F_32 ( V_3 , L_62 ,
V_104 , V_105 ) ;
F_39 ( V_3 ) ;
}
if ( V_34 -> V_61 . type == V_107 )
F_42 ( V_3 -> V_108 , L_63 ,
& V_34 -> V_61 , false ) ;
else
F_32 ( V_3 , L_64 ) ;
F_32 ( V_3 , L_65 , V_34 -> V_109 ) ;
if ( V_34 -> V_38 == NULL )
return 0 ;
F_32 ( V_3 , L_66 , V_34 -> V_110 ) ;
F_32 ( V_3 , L_67 , V_34 -> V_111 ?
L_54 : L_53 ) ;
if ( V_34 -> V_111 ) {
for ( V_20 = 0 ; V_20 < V_112 ; V_20 ++ ) {
bool V_113 = V_34 -> V_114 & ( 1 << V_20 ) ;
if ( V_113 )
F_32 ( V_3 , L_68 ,
V_34 -> V_115 [ V_20 ] ) ;
}
}
F_32 ( V_3 , L_69 , V_34 -> V_116 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , int V_117 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
const int V_118 = 20 ;
int V_20 ;
F_16 ( 1 , V_36 , V_3 , L_70 , V_24 , V_117 ? L_44 : L_45 ) ;
V_34 -> V_98 = V_117 ;
if ( ! V_117 ) {
F_13 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
return true ;
}
for ( V_20 = 0 ; V_20 < V_118 ; V_20 ++ ) {
F_13 ( V_3 , 0x41 , 0xbf , 0x0 ) ;
if ( ( F_8 ( V_3 , 0x41 ) & 0x40 ) == 0 )
break;
F_13 ( V_3 , 0x41 , 0xbf , 0x40 ) ;
F_44 ( 10 ) ;
}
if ( V_20 == V_118 ) {
F_16 ( 1 , V_36 , V_3 , L_71 , V_24 ) ;
F_43 ( V_3 , 0 ) ;
return false ;
}
if ( V_20 > 1 )
F_16 ( 1 , V_36 , V_3 , L_72 , V_24 , V_20 ) ;
F_10 ( V_3 , 0x98 , 0x03 ) ;
F_13 ( V_3 , 0x9a , 0xfe , 0x70 ) ;
F_10 ( V_3 , 0x9c , 0x30 ) ;
F_13 ( V_3 , 0x9d , 0xfc , 0x01 ) ;
F_10 ( V_3 , 0xa2 , 0xa4 ) ;
F_10 ( V_3 , 0xa3 , 0xa4 ) ;
F_10 ( V_3 , 0xe0 , 0xd0 ) ;
F_10 ( V_3 , 0xf9 , 0x00 ) ;
F_10 ( V_3 , 0x43 , V_34 -> V_109 ) ;
F_10 ( V_3 , 0x45 , V_34 -> V_116 ) ;
F_10 ( V_3 , 0xc9 , 0xf ) ;
return true ;
}
static int F_45 ( struct V_119 * V_120 , bool V_56 )
{
struct V_1 * V_34 = F_46 ( V_120 ) ;
struct V_2 * V_3 = & V_34 -> V_3 ;
if ( V_34 -> V_38 == NULL )
return - V_121 ;
if ( ! V_34 -> V_111 && V_56 ) {
F_20 ( V_3 , 0x4e , 0xfc , 0x01 ) ;
F_19 ( V_3 , 0x4a , 0x07 ) ;
F_19 ( V_3 , 0x4a , 0 ) ;
F_20 ( V_3 , 0x11 , 0xfe , 0 ) ;
if ( V_34 -> V_122 )
F_13 ( V_3 , 0x95 , 0xc0 , 0x39 ) ;
} else if ( V_34 -> V_111 && ! V_56 ) {
if ( V_34 -> V_122 )
F_13 ( V_3 , 0x95 , 0xc0 , 0x00 ) ;
F_20 ( V_3 , 0x4b , 0x8f , 0x00 ) ;
F_20 ( V_3 , 0x4e , 0xfc , 0x00 ) ;
V_34 -> V_114 = 0 ;
}
V_34 -> V_111 = V_56 ;
return 0 ;
}
static int F_47 ( struct V_119 * V_120 , T_2 V_15 )
{
struct V_1 * V_34 = F_46 ( V_120 ) ;
struct V_2 * V_3 = & V_34 -> V_3 ;
unsigned int V_20 , V_123 = V_112 ;
if ( ! V_34 -> V_111 )
return V_15 == V_124 ? 0 : - V_121 ;
if ( V_15 == V_124 ) {
F_20 ( V_3 , 0x4b , 0x8f , 0 ) ;
V_34 -> V_114 = 0 ;
return 0 ;
}
for ( V_20 = 0 ; V_20 < V_112 ; V_20 ++ ) {
bool V_113 = V_34 -> V_114 & ( 1 << V_20 ) ;
if ( V_123 == V_112 && ! V_113 )
V_123 = V_20 ;
if ( V_113 && V_34 -> V_115 [ V_20 ] == V_15 )
return 0 ;
}
if ( V_20 == V_112 ) {
V_20 = V_123 ;
if ( V_20 == V_112 )
return - V_125 ;
}
V_34 -> V_115 [ V_20 ] = V_15 ;
V_34 -> V_114 |= 1 << V_20 ;
switch ( V_20 ) {
case 0 :
F_20 ( V_3 , 0x4b , 0xef , 0x10 ) ;
F_20 ( V_3 , 0x4c , 0xf0 , V_15 ) ;
break;
case 1 :
F_20 ( V_3 , 0x4b , 0xdf , 0x20 ) ;
F_20 ( V_3 , 0x4c , 0x0f , V_15 << 4 ) ;
break;
case 2 :
F_20 ( V_3 , 0x4b , 0xbf , 0x40 ) ;
F_20 ( V_3 , 0x4d , 0xf0 , V_15 ) ;
break;
}
return 0 ;
}
static int F_48 ( struct V_119 * V_120 , T_2 V_126 ,
T_7 V_127 , struct V_128 * V_129 )
{
struct V_1 * V_34 = F_46 ( V_120 ) ;
struct V_2 * V_3 = & V_34 -> V_3 ;
T_2 V_32 = V_129 -> V_32 ;
unsigned int V_20 ;
F_16 ( 1 , V_36 , V_3 , L_73 , V_24 , V_32 ) ;
if ( V_32 > 16 ) {
F_12 ( V_3 , L_74 , V_24 , V_32 ) ;
return - V_76 ;
}
F_20 ( V_3 , 0x12 , ~ 0x70 , F_49 ( 1 , V_126 - 1 ) << 4 ) ;
F_13 ( V_3 , 0x97 , 0xc7 , 0x38 ) ;
for ( V_20 = 0 ; V_20 < V_32 ; V_20 ++ )
F_19 ( V_3 , V_20 , V_129 -> V_129 [ V_20 ] ) ;
F_19 ( V_3 , 0x10 , V_32 ) ;
F_19 ( V_3 , 0x11 , 0x01 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 , T_2 V_130 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( ( F_17 ( V_3 , 0x11 ) & 0x01 ) == 0 ) {
F_16 ( 1 , V_36 , V_3 , L_75 , V_24 ) ;
return;
}
if ( V_130 & 0x10 ) {
F_16 ( 1 , V_36 , V_3 ,
L_76 , V_24 ) ;
F_51 ( V_34 -> V_131 , V_132 ,
1 , 0 , 0 , 0 ) ;
return;
}
if ( V_130 & 0x08 ) {
T_2 V_133 ;
T_2 V_134 ;
T_2 V_135 ;
F_16 ( 1 , V_36 , V_3 , L_77 , V_24 ) ;
V_133 = V_136 ;
V_134 = F_17 ( V_3 , 0x14 ) & 0xf ;
if ( V_134 )
V_133 |= V_137 ;
V_135 = F_17 ( V_3 , 0x14 ) >> 4 ;
if ( V_135 )
V_133 |= V_138 ;
F_51 ( V_34 -> V_131 , V_133 ,
0 , V_134 , V_135 , 0 ) ;
return;
}
if ( V_130 & 0x20 ) {
F_16 ( 1 , V_36 , V_3 , L_78 , V_24 ) ;
F_51 ( V_34 -> V_131 , V_139 , 0 , 0 , 0 , 0 ) ;
return;
}
}
static void F_52 ( struct V_2 * V_3 , bool V_56 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_2 V_140 = V_141 | V_142 ;
T_2 V_143 ;
int V_118 = 100 ;
F_16 ( 2 , V_36 , V_3 , L_79 , V_24 , V_56 ? L_80 : L_81 ) ;
if ( V_34 -> V_122 == V_56 )
return;
V_34 -> V_122 = V_56 ;
if ( ! V_56 )
V_140 = 0 ;
else if ( F_24 ( V_3 ) )
V_140 |= V_144 ;
F_13 ( V_3 , 0x95 , 0xc0 ,
( V_34 -> V_111 && V_56 ) ? 0x39 : 0x00 ) ;
do {
F_10 ( V_3 , 0x94 , V_140 ) ;
V_143 = F_8 ( V_3 , 0x94 ) ;
} while ( V_118 -- && V_143 != V_140 );
if ( V_143 == V_140 )
return;
F_12 ( V_3 , L_82 ) ;
}
static int F_53 ( struct V_2 * V_3 , T_7 V_133 , bool * V_145 )
{
T_2 V_146 ;
T_2 V_147 ;
F_52 ( V_3 , false ) ;
V_146 = F_8 ( V_3 , 0x96 ) ;
V_147 = F_8 ( V_3 , 0x97 ) ;
F_10 ( V_3 , 0x96 , V_146 ) ;
F_10 ( V_3 , 0x97 , V_147 ) ;
F_16 ( 1 , V_36 , V_3 , L_83 , V_24 ,
V_146 , V_147 ) ;
if ( V_146 & ( V_141 | V_142 ) )
F_54 ( V_3 ) ;
if ( V_146 & V_144 )
F_55 ( V_3 ) ;
#if F_56 ( V_148 )
if ( V_147 & 0x38 )
F_50 ( V_3 , V_147 ) ;
if ( V_147 & 1 ) {
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_128 V_129 ;
V_129 . V_32 = F_17 ( V_3 , 0x25 ) & 0x1f ;
F_16 ( 1 , V_36 , V_3 , L_84 , V_24 ,
V_129 . V_32 ) ;
if ( V_129 . V_32 > 16 )
V_129 . V_32 = 16 ;
if ( V_129 . V_32 ) {
T_2 V_20 ;
for ( V_20 = 0 ; V_20 < V_129 . V_32 ; V_20 ++ )
V_129 . V_129 [ V_20 ] = F_17 ( V_3 , V_20 + 0x15 ) ;
F_19 ( V_3 , 0x4a , 1 ) ;
F_19 ( V_3 , 0x4a , 0 ) ;
F_57 ( V_34 -> V_131 , & V_129 ) ;
}
}
#endif
F_52 ( V_3 , true ) ;
if ( V_145 )
* V_145 = true ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 , int V_56 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_85 , V_24 , ( V_56 ? L_86 : L_87 ) ) ;
F_13 ( V_3 , 0xa1 , ~ 0x3c , ( V_56 ? 0 : 0x3c ) ) ;
if ( V_56 ) {
F_54 ( V_3 ) ;
} else {
F_43 ( V_3 , 0 ) ;
V_34 -> V_149 = false ;
}
return 0 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_150 * V_151 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_152 * V_62 = & V_151 -> V_62 ;
T_7 V_153 ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
if ( ! F_60 ( V_151 , & V_154 , NULL , NULL ) )
return - V_76 ;
F_61 ( V_151 , & V_154 , 0 , NULL , NULL ) ;
V_34 -> V_61 = * V_151 ;
F_13 ( V_3 , 0x17 , 0x9f ,
( ( V_62 -> V_155 & V_156 ) ? 0 : 0x40 ) |
( ( V_62 -> V_155 & V_157 ) ? 0 : 0x20 ) ) ;
V_153 = ( T_7 ) V_62 -> V_158 / ( F_62 ( V_62 ) * F_63 ( V_62 ) ) ;
switch ( V_153 ) {
case 24 :
F_13 ( V_3 , 0xfb , 0xf9 , 1 << 1 ) ;
break;
case 25 :
F_13 ( V_3 , 0xfb , 0xf9 , 2 << 1 ) ;
break;
case 30 :
F_13 ( V_3 , 0xfb , 0xf9 , 3 << 1 ) ;
break;
default:
F_13 ( V_3 , 0xfb , 0xf9 , 0 ) ;
break;
}
F_29 ( V_3 , V_34 -> V_69 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_150 * V_151 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
if ( ! V_151 )
return - V_76 ;
* V_151 = V_34 -> V_61 ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_159 * V_151 )
{
if ( V_151 -> V_160 != 0 )
return - V_76 ;
return F_66 ( V_151 , & V_154 , NULL , NULL ) ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_161 * V_162 )
{
if ( V_162 -> V_160 != 0 )
return - V_76 ;
* V_162 = V_154 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , int V_56 )
{
F_16 ( 1 , V_36 , V_3 , L_85 , V_24 , ( V_56 ? L_86 : L_87 ) ) ;
if ( V_56 )
F_13 ( V_3 , 0x4b , 0x3f , 0x80 ) ;
else
F_13 ( V_3 , 0x4b , 0x3f , 0x40 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , T_7 V_163 )
{
T_7 V_103 ;
switch ( V_163 ) {
case 32000 : V_103 = 4096 ; break;
case 44100 : V_103 = 6272 ; break;
case 48000 : V_103 = 6144 ; break;
case 88200 : V_103 = 12544 ; break;
case 96000 : V_103 = 12288 ; break;
case 176400 : V_103 = 25088 ; break;
case 192000 : V_103 = 24576 ; break;
default:
return - V_76 ;
}
F_10 ( V_3 , 0x01 , ( V_103 >> 16 ) & 0xf ) ;
F_10 ( V_3 , 0x02 , ( V_103 >> 8 ) & 0xff ) ;
F_10 ( V_3 , 0x03 , V_103 & 0xff ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , T_7 V_163 )
{
T_7 V_164 ;
switch ( V_163 ) {
case 32000 : V_164 = 0x30 ; break;
case 44100 : V_164 = 0x00 ; break;
case 48000 : V_164 = 0x20 ; break;
case 88200 : V_164 = 0x80 ; break;
case 96000 : V_164 = 0xa0 ; break;
case 176400 : V_164 = 0xc0 ; break;
case 192000 : V_164 = 0xe0 ; break;
default:
return - V_76 ;
}
F_13 ( V_3 , 0x15 , 0xf , V_164 ) ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 , T_7 V_165 , T_7 V_166 , T_7 V_167 )
{
F_13 ( V_3 , 0x73 , 0xf8 , 0x1 ) ;
F_10 ( V_3 , 0x76 , 0x00 ) ;
F_13 ( V_3 , 0x14 , 0xf0 , 0x02 ) ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 , struct V_168 * V_95 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
memset ( V_95 -> V_169 , 0 , sizeof( V_95 -> V_169 ) ) ;
if ( V_95 -> V_160 != 0 )
return - V_76 ;
if ( V_95 -> V_170 == 0 && V_95 -> V_100 == 0 ) {
V_95 -> V_100 = V_34 -> V_95 . V_99 * 2 ;
return 0 ;
}
if ( V_34 -> V_95 . V_99 == 0 )
return - V_171 ;
if ( V_95 -> V_170 >= V_34 -> V_95 . V_99 * 2 )
return - V_76 ;
if ( V_95 -> V_170 + V_95 -> V_100 > V_34 -> V_95 . V_99 * 2 )
V_95 -> V_100 = V_34 -> V_95 . V_99 * 2 - V_95 -> V_170 ;
memcpy ( V_95 -> V_95 , & V_34 -> V_95 . V_13 [ V_95 -> V_170 * 128 ] ,
128 * V_95 -> V_100 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_172 * V_173 ,
struct V_174 * V_175 )
{
if ( V_175 -> V_160 != 0 )
return - V_76 ;
switch ( V_175 -> V_176 ) {
case 0 :
V_175 -> V_175 = V_59 ;
break;
case 1 :
V_175 -> V_175 = V_177 ;
break;
case 2 :
V_175 -> V_175 = V_178 ;
break;
default:
return - V_76 ;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_34 ,
struct V_179 * V_180 )
{
V_180 -> V_181 = V_34 -> V_61 . V_62 . V_181 ;
V_180 -> V_182 = V_34 -> V_61 . V_62 . V_182 ;
V_180 -> V_183 = V_184 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_172 * V_173 ,
struct V_185 * V_180 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( V_180 -> V_160 != 0 )
return - V_76 ;
memset ( & V_180 -> V_180 , 0 , sizeof( V_180 -> V_180 ) ) ;
F_74 ( V_34 , & V_180 -> V_180 ) ;
if ( V_180 -> V_186 == V_187 ) {
struct V_179 * V_188 ;
V_188 = F_76 ( V_3 , V_173 , V_180 -> V_160 ) ;
V_180 -> V_180 . V_175 = V_188 -> V_175 ;
V_180 -> V_180 . V_189 = V_188 -> V_189 ;
V_180 -> V_180 . V_190 = V_188 -> V_190 ;
V_180 -> V_180 . V_191 = V_188 -> V_191 ;
V_180 -> V_180 . V_192 = V_188 -> V_192 ;
} else {
V_180 -> V_180 . V_175 = V_34 -> V_58 ;
V_180 -> V_180 . V_189 = V_34 -> V_189 ;
V_180 -> V_180 . V_190 = V_34 -> V_190 ;
V_180 -> V_180 . V_191 = V_34 -> V_191 ;
V_180 -> V_180 . V_192 = V_34 -> V_192 ;
}
return 0 ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_172 * V_173 ,
struct V_185 * V_180 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_2 V_193 = V_194 ;
T_2 V_195 = V_196 ;
T_2 V_197 = V_198 ;
T_2 V_199 = V_200 ;
T_2 V_201 = V_202 ;
T_2 V_71 = V_34 -> V_73 != V_74 ;
T_2 V_72 = V_71 ? V_34 -> V_73 : V_75 ;
if ( V_180 -> V_160 != 0 )
return - V_76 ;
switch ( V_180 -> V_180 . V_175 ) {
case V_178 :
case V_177 :
case V_59 :
break;
default:
return - V_76 ;
}
F_74 ( V_34 , & V_180 -> V_180 ) ;
if ( V_180 -> V_186 == V_187 ) {
struct V_179 * V_188 ;
V_188 = F_76 ( V_3 , V_173 , V_180 -> V_160 ) ;
V_188 -> V_175 = V_180 -> V_180 . V_175 ;
V_188 -> V_189 = V_180 -> V_180 . V_189 ;
V_188 -> V_190 = V_180 -> V_180 . V_190 ;
V_188 -> V_191 = V_180 -> V_180 . V_191 ;
V_188 -> V_192 = V_180 -> V_180 . V_192 ;
return 0 ;
}
switch ( V_180 -> V_180 . V_175 ) {
case V_178 :
F_13 ( V_3 , 0x15 , 0xf0 , 0x01 ) ;
F_13 ( V_3 , 0x16 , 0x03 , 0xb8 ) ;
V_197 = V_203 ;
break;
case V_177 :
F_13 ( V_3 , 0x15 , 0xf0 , 0x01 ) ;
F_13 ( V_3 , 0x16 , 0x03 , 0xbc ) ;
V_197 = V_203 ;
break;
case V_59 :
default:
F_13 ( V_3 , 0x15 , 0xf0 , 0x00 ) ;
F_13 ( V_3 , 0x16 , 0x03 , 0x00 ) ;
break;
}
V_34 -> V_58 = V_180 -> V_180 . V_175 ;
V_34 -> V_189 = V_180 -> V_180 . V_189 ;
V_34 -> V_190 = V_180 -> V_180 . V_190 ;
V_34 -> V_191 = V_180 -> V_180 . V_191 ;
V_34 -> V_192 = V_180 -> V_180 . V_192 ;
switch ( V_180 -> V_180 . V_189 ) {
case V_204 :
V_193 = V_205 ;
V_195 = V_197 ? V_206 :
V_207 ;
break;
case V_208 :
V_193 = V_197 ? V_209 : V_194 ;
if ( V_197 && V_180 -> V_180 . V_190 == V_210 ) {
V_193 = V_205 ;
V_195 = V_196 ;
}
break;
case V_211 :
V_193 = V_197 ? V_212 : V_194 ;
if ( V_197 && V_180 -> V_180 . V_190 == V_213 ) {
V_193 = V_205 ;
V_195 = V_214 ;
}
break;
case V_215 :
V_193 = V_197 ? V_205 : V_194 ;
V_195 = V_197 ? V_216 :
V_196 ;
break;
case V_217 :
V_193 = V_205 ;
if ( V_197 && V_180 -> V_180 . V_190 == V_218 )
V_195 = 5 ;
else
V_195 = 6 ;
break;
default:
break;
}
switch ( V_180 -> V_180 . V_191 ) {
case V_219 :
V_199 = V_197 ? V_200 :
V_220 ;
V_201 = V_199 ? V_199 - 1 : V_221 ;
break;
case V_222 :
V_199 = V_197 ? V_200 :
V_223 ;
V_201 = V_199 ? V_199 - 1 : V_202 ;
break;
}
F_13 ( V_3 , 0x4a , 0xbf , 0 ) ;
F_13 ( V_3 , 0x55 , 0x9f , V_197 << 5 ) ;
F_13 ( V_3 , 0x56 , 0x3f , V_193 << 6 ) ;
F_13 ( V_3 , 0x57 , 0x83 , ( V_195 << 4 ) | ( V_199 << 2 ) | ( V_71 << 7 ) ) ;
F_13 ( V_3 , 0x59 , 0x0f , ( V_201 << 6 ) | ( V_72 << 4 ) ) ;
F_13 ( V_3 , 0x4a , 0xff , 1 ) ;
F_29 ( V_3 , V_34 -> V_69 ) ;
return 0 ;
}
static void F_78 ( int V_224 , int V_36 , struct V_2 * V_3 , int V_225 , T_2 * V_33 )
{
if ( V_36 >= V_224 ) {
int V_20 , V_226 ;
F_16 ( V_224 , V_36 , V_3 , L_88 , V_225 ) ;
for ( V_20 = 0 ; V_20 < 256 ; V_20 += 16 ) {
T_2 V_227 [ 128 ] ;
T_2 * V_228 = V_227 ;
if ( V_20 == 128 )
F_16 ( V_224 , V_36 , V_3 , L_89 ) ;
for ( V_226 = V_20 ; V_226 < V_20 + 16 ; V_226 ++ ) {
sprintf ( V_228 , L_90 , V_33 [ V_226 ] ) ;
V_228 += 6 ;
}
V_228 [ 0 ] = '\0' ;
F_16 ( V_224 , V_36 , V_3 , L_91 , V_227 ) ;
}
}
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_229 V_230 ;
V_230 . V_231 = false ;
V_230 . V_225 = F_8 ( V_3 , 0xc4 ) ;
V_230 . V_232 = V_233 ;
F_80 ( V_34 -> V_131 , V_230 . V_232 , false ) ;
F_81 ( V_3 , V_234 , ( void * ) & V_230 ) ;
F_82 ( V_34 -> V_235 , 0x0 ) ;
}
static void F_83 ( struct V_236 * V_237 )
{
struct V_238 * V_239 = F_84 ( V_237 ) ;
struct V_1 * V_34 = F_2 ( V_239 , struct V_1 , V_240 ) ;
struct V_2 * V_3 = & V_34 -> V_3 ;
F_16 ( 1 , V_36 , V_3 , L_5 , V_24 ) ;
if ( F_55 ( V_3 ) ) {
return;
}
if ( F_24 ( V_3 ) ) {
if ( V_34 -> V_95 . V_241 ) {
V_34 -> V_95 . V_241 -- ;
F_16 ( 1 , V_36 , V_3 , L_92 , V_24 ) ;
V_34 -> V_149 = false ;
F_43 ( V_3 , false ) ;
F_43 ( V_3 , true ) ;
F_85 ( V_34 -> V_242 , & V_34 -> V_240 , V_243 ) ;
return;
}
}
F_79 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_93 , V_24 ) ;
}
static void F_86 ( struct V_2 * V_3 )
{
F_16 ( 1 , V_36 , V_3 , L_91 , V_24 ) ;
F_70 ( V_3 , 48000 ) ;
F_69 ( V_3 , 48000 ) ;
F_71 ( V_3 , 0 , 0 , 0 ) ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_16 ( 1 , V_36 , V_3 , L_91 , V_24 ) ;
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
F_86 ( V_3 ) ;
F_88 ( & V_34 -> V_7 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_244 V_245 ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
V_245 . V_231 = V_34 -> V_149 ;
F_81 ( V_3 , V_246 , ( void * ) & V_245 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_2 V_133 = F_8 ( V_3 , 0x42 ) ;
F_16 ( 1 , V_36 , V_3 , L_94 ,
V_24 ,
V_133 ,
V_133 & V_41 ? L_95 : L_96 ,
V_133 & V_42 ? L_97 : L_96 ) ;
F_82 ( V_34 -> V_247 , F_24 ( V_3 ) ? 0x1 : 0x0 ) ;
F_82 ( V_34 -> V_248 , F_25 ( V_3 ) ? 0x1 : 0x0 ) ;
if ( ( V_133 & V_41 ) && ( ( V_133 & V_42 ) || V_34 -> V_95 . V_99 ) ) {
F_16 ( 1 , V_36 , V_3 , L_98 , V_24 ) ;
if ( ! V_34 -> V_149 ) {
F_16 ( 1 , V_36 , V_3 , L_99 , V_24 ) ;
V_34 -> V_149 = true ;
F_52 ( V_3 , true ) ;
if ( ! F_43 ( V_3 , true ) ) {
F_16 ( 1 , V_36 , V_3 , L_100 , V_24 ) ;
return;
}
F_87 ( V_3 ) ;
F_89 ( V_3 ) ;
V_34 -> V_95 . V_241 = V_249 ;
F_85 ( V_34 -> V_242 , & V_34 -> V_240 , V_243 ) ;
}
} else if ( V_133 & V_41 ) {
F_16 ( 1 , V_36 , V_3 , L_101 , V_24 ) ;
V_34 -> V_95 . V_241 = V_249 ;
F_85 ( V_34 -> V_242 , & V_34 -> V_240 , V_243 ) ;
} else if ( ! ( V_133 & V_41 ) ) {
F_16 ( 1 , V_36 , V_3 , L_102 , V_24 ) ;
if ( V_34 -> V_149 ) {
F_16 ( 1 , V_36 , V_3 , L_103 , V_24 ) ;
V_34 -> V_149 = false ;
F_89 ( V_3 ) ;
}
F_43 ( V_3 , false ) ;
memset ( & V_34 -> V_95 , 0 , sizeof( struct V_94 ) ) ;
F_79 ( V_3 ) ;
}
}
static bool F_90 ( T_2 * V_250 )
{
T_2 V_251 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ )
V_251 += V_250 [ V_20 ] ;
return V_251 == 0 ;
}
static bool F_91 ( struct V_2 * V_3 , T_7 V_225 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_7 V_100 = V_34 -> V_95 . V_100 ;
T_2 * V_13 = V_34 -> V_95 . V_13 ;
if ( ! F_90 ( & V_13 [ V_225 * 256 ] ) )
return false ;
if ( ( V_225 + 1 ) * 2 <= V_100 )
return F_90 ( & V_13 [ V_225 * 256 + 128 ] ) ;
return true ;
}
static bool F_92 ( struct V_2 * V_3 , T_7 V_225 )
{
static const T_2 V_252 [] = {
0x00 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x00
} ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_2 * V_13 = V_34 -> V_95 . V_13 ;
if ( V_225 != 0 )
return true ;
return ! memcmp ( V_13 , V_252 , sizeof( V_252 ) ) ;
}
static bool F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
T_2 V_253 = F_8 ( V_3 , 0xc5 ) ;
F_16 ( 1 , V_36 , V_3 , L_104 ,
V_24 , V_249 - V_34 -> V_95 . V_241 ) ;
if ( V_34 -> V_95 . V_254 )
return true ;
if ( V_253 & V_255 ) {
int V_225 = F_8 ( V_3 , 0xc4 ) ;
struct V_229 V_230 ;
if ( V_225 >= V_256 ) {
F_12 ( V_3 , L_105 ) ;
return false ;
}
F_16 ( 1 , V_36 , V_3 , L_106 , V_24 , V_225 ) ;
F_15 ( V_3 , 256 , & V_34 -> V_95 . V_13 [ V_225 * 256 ] ) ;
F_78 ( 2 , V_36 , V_3 , V_225 , & V_34 -> V_95 . V_13 [ V_225 * 256 ] ) ;
if ( V_225 == 0 ) {
V_34 -> V_95 . V_100 = V_34 -> V_95 . V_13 [ 0x7e ] + 1 ;
F_16 ( 1 , V_36 , V_3 , L_107 , V_24 , V_34 -> V_95 . V_100 ) ;
}
if ( ! F_91 ( V_3 , V_225 ) ||
! F_92 ( V_3 , V_225 ) ) {
F_12 ( V_3 , L_108 , V_24 ) ;
V_34 -> V_149 = false ;
F_43 ( V_3 , false ) ;
F_43 ( V_3 , true ) ;
return false ;
}
V_34 -> V_95 . V_99 = V_225 + 1 ;
F_82 ( V_34 -> V_235 , 0x1 ) ;
if ( ( ( V_34 -> V_95 . V_13 [ 0x7e ] >> 1 ) + 1 ) > V_34 -> V_95 . V_99 ) {
F_16 ( 1 , V_36 , V_3 , L_109 , V_24 , V_34 -> V_95 . V_99 ) ;
F_10 ( V_3 , 0xc9 , 0xf ) ;
F_10 ( V_3 , 0xc4 , V_34 -> V_95 . V_99 ) ;
V_34 -> V_95 . V_241 = V_249 ;
F_85 ( V_34 -> V_242 , & V_34 -> V_240 , V_243 ) ;
return false ;
}
F_16 ( 1 , V_36 , V_3 , L_110 , V_24 , V_34 -> V_95 . V_99 ) ;
V_34 -> V_95 . V_254 = true ;
V_230 . V_232 = F_93 ( V_34 -> V_95 . V_13 ,
V_34 -> V_95 . V_99 * 256 ,
NULL ) ;
V_230 . V_231 = true ;
V_230 . V_225 = 0 ;
V_34 -> V_101 ++ ;
F_80 ( V_34 -> V_131 , V_230 . V_232 , false ) ;
F_81 ( V_3 , V_234 , ( void * ) & V_230 ) ;
return V_230 . V_231 ;
}
return false ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_9 ( V_3 ) ;
int V_35 ;
V_35 = F_95 ( V_34 -> V_131 , & V_9 -> V_84 ) ;
if ( V_35 )
F_96 ( V_34 -> V_131 ) ;
return V_35 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_98 ( V_34 -> V_131 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_94 * V_95 = & V_34 -> V_95 ;
T_7 V_257 = V_34 -> V_258 . V_257 ;
T_2 V_259 ;
F_16 ( 1 , V_36 , V_3 , L_91 , V_24 ) ;
F_10 ( V_3 , 0x96 , 0xff ) ;
F_10 ( V_3 , 0x97 , 0xff ) ;
F_13 ( V_3 , 0xd6 , 0x3f , 0xc0 ) ;
memset ( V_95 , 0 , sizeof( struct V_94 ) ) ;
V_34 -> V_149 = false ;
F_52 ( V_3 , false ) ;
F_58 ( V_3 , false ) ;
F_68 ( V_3 , false ) ;
if ( V_34 -> V_38 == NULL )
return;
F_16 ( 1 , V_36 , V_3 , L_111 , V_24 , V_257 ) ;
F_19 ( V_3 , 0x50 , 0x01 ) ;
F_19 ( V_3 , 0x50 , 0x00 ) ;
F_19 ( V_3 , 0x4a , 0x00 ) ;
if ( V_257 % 750000 != 0 )
F_12 ( V_3 , L_112 ,
V_24 , V_257 ) ;
V_259 = ( V_257 / 750000 ) - 1 ;
F_19 ( V_3 , 0x4e , V_259 << 2 ) ;
}
static int F_100 ( struct V_8 * V_9 , const struct V_260 * V_66 )
{
struct V_1 * V_34 ;
struct V_261 * V_258 = V_9 -> V_84 . V_262 ;
struct V_263 * V_7 ;
struct V_2 * V_3 ;
T_2 V_264 [ 2 ] ;
int V_35 = - V_121 ;
if ( ! F_101 ( V_9 -> V_14 , V_265 ) )
return - V_121 ;
V_34 = F_102 ( & V_9 -> V_84 , sizeof( struct V_1 ) , V_266 ) ;
if ( ! V_34 )
return - V_267 ;
if ( ! V_258 ) {
F_6 ( V_9 , L_113 ) ;
return - V_268 ;
}
memcpy ( & V_34 -> V_258 , V_258 , sizeof( V_34 -> V_258 ) ) ;
V_34 -> V_58 = V_59 ;
V_34 -> V_189 = V_215 ;
V_3 = & V_34 -> V_3 ;
F_16 ( 1 , V_36 , V_3 , L_114 ,
V_9 -> V_15 << 1 ) ;
F_103 ( V_3 , V_9 , & V_269 ) ;
V_3 -> V_270 = & V_271 ;
V_7 = & V_34 -> V_7 ;
F_104 ( V_7 , 10 ) ;
V_34 -> V_67 = F_105 ( V_7 , & V_272 ,
V_273 , V_68 ,
0 , V_274 ) ;
V_34 -> V_247 = F_106 ( V_7 , NULL ,
V_275 , 0 , 1 , 0 , 0 ) ;
V_34 -> V_248 = F_106 ( V_7 , NULL ,
V_276 , 0 , 1 , 0 , 0 ) ;
V_34 -> V_235 = F_106 ( V_7 , NULL ,
V_277 , 0 , 1 , 0 , 0 ) ;
V_34 -> V_69 =
F_105 ( V_7 , & V_272 ,
V_278 , V_65 ,
0 , V_60 ) ;
V_34 -> V_70 =
F_105 ( V_7 , & V_272 ,
V_279 , V_74 ,
0 , V_74 ) ;
V_3 -> V_280 = V_7 ;
if ( V_7 -> error ) {
V_35 = V_7 -> error ;
goto V_281;
}
V_34 -> V_160 . V_16 = V_282 ;
V_35 = F_107 ( & V_3 -> V_283 , 1 , & V_34 -> V_160 ) ;
if ( V_35 )
goto V_281;
V_34 -> V_109 = V_34 -> V_258 . V_37 << 1 ;
V_34 -> V_110 = V_34 -> V_258 . V_38 << 1 ;
V_34 -> V_116 = V_34 -> V_258 . V_40 << 1 ;
V_34 -> V_284 = F_8 ( V_3 , 0x0 ) ;
V_264 [ 0 ] = F_8 ( V_3 , 0xf5 ) ;
V_264 [ 1 ] = F_8 ( V_3 , 0xf6 ) ;
if ( V_264 [ 0 ] != 0x75 || V_264 [ 1 ] != 0x11 ) {
F_12 ( V_3 , L_115 , V_264 [ 0 ] ,
V_264 [ 1 ] ) ;
V_35 = - V_121 ;
goto V_285;
}
V_34 -> V_37 = F_108 ( V_9 -> V_14 ,
V_34 -> V_109 >> 1 ) ;
if ( V_34 -> V_37 == NULL ) {
F_12 ( V_3 , L_116 ) ;
V_35 = - V_267 ;
goto V_285;
}
F_10 ( V_3 , 0xe1 , V_34 -> V_110 ) ;
if ( V_34 -> V_258 . V_257 < 3000000 ||
V_34 -> V_258 . V_257 > 100000000 ) {
F_12 ( V_3 , L_117 ,
V_24 , V_34 -> V_258 . V_257 ) ;
V_34 -> V_258 . V_257 = 0 ;
}
if ( V_34 -> V_258 . V_257 ) {
V_34 -> V_38 = F_108 ( V_9 -> V_14 ,
V_34 -> V_110 >> 1 ) ;
if ( V_34 -> V_38 == NULL ) {
F_12 ( V_3 , L_118 ) ;
V_35 = - V_267 ;
goto V_286;
}
F_10 ( V_3 , 0xe2 , 0x00 ) ;
} else {
F_10 ( V_3 , 0xe2 , 0x01 ) ;
}
V_34 -> V_40 = F_108 ( V_9 -> V_14 , V_34 -> V_116 >> 1 ) ;
if ( V_34 -> V_40 == NULL ) {
F_12 ( V_3 , L_119 ) ;
V_35 = - V_267 ;
goto V_287;
}
V_34 -> V_242 = F_109 ( V_3 -> V_108 ) ;
if ( V_34 -> V_242 == NULL ) {
F_12 ( V_3 , L_120 ) ;
V_35 = - V_267 ;
goto V_288;
}
F_110 ( & V_34 -> V_240 , F_83 ) ;
F_99 ( V_3 ) ;
#if F_56 ( V_148 )
V_34 -> V_131 = F_111 ( & V_289 ,
V_34 , F_112 ( & V_9 -> V_84 ) , V_290 ,
V_112 ) ;
V_35 = F_113 ( V_34 -> V_131 ) ;
if ( V_35 ) {
F_114 ( V_34 -> V_242 ) ;
goto V_288;
}
#endif
F_52 ( V_3 , true ) ;
F_54 ( V_3 ) ;
F_32 ( V_3 , L_121 , V_9 -> V_108 ,
V_9 -> V_15 << 1 , V_9 -> V_14 -> V_108 ) ;
return 0 ;
V_288:
F_115 ( V_34 -> V_40 ) ;
V_287:
if ( V_34 -> V_38 )
F_115 ( V_34 -> V_38 ) ;
V_286:
F_115 ( V_34 -> V_37 ) ;
V_285:
F_116 ( & V_3 -> V_283 ) ;
V_281:
F_117 ( & V_34 -> V_7 ) ;
return V_35 ;
}
static int F_118 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_119 ( V_9 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
V_34 -> V_284 = - 1 ;
F_16 ( 1 , V_36 , V_3 , L_122 , V_9 -> V_108 ,
V_9 -> V_15 << 1 , V_9 -> V_14 -> V_108 ) ;
F_52 ( V_3 , false ) ;
F_99 ( V_3 ) ;
F_120 ( & V_34 -> V_240 ) ;
F_115 ( V_34 -> V_37 ) ;
if ( V_34 -> V_38 )
F_115 ( V_34 -> V_38 ) ;
F_115 ( V_34 -> V_40 ) ;
F_114 ( V_34 -> V_242 ) ;
F_121 ( V_3 ) ;
F_116 ( & V_3 -> V_283 ) ;
F_117 ( V_3 -> V_280 ) ;
return 0 ;
}
