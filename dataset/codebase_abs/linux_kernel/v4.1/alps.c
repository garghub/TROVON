static bool F_1 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
return ( V_3 & V_2 -> V_4 ) == V_2 -> V_5 ;
}
static void F_2 ( struct V_6 * V_7 , struct V_6 * V_8 ,
int V_9 , int V_10 , int V_11 )
{
struct V_6 * V_12 ;
V_12 = ( V_8 && F_3 ( V_13 , V_8 -> V_14 ) ) ? V_8 : V_7 ;
F_4 ( V_12 , V_13 , V_9 ) ;
V_12 = ( V_8 && F_3 ( V_15 , V_8 -> V_14 ) ) ? V_8 : V_7 ;
F_4 ( V_12 , V_15 , V_10 ) ;
V_12 = ( V_8 && F_3 ( V_16 , V_8 -> V_14 ) ) ? V_8 : V_7 ;
F_4 ( V_12 , V_16 , V_11 ) ;
if ( V_8 )
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_6 * V_8 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_23 , V_24 , V_9 , V_10 , V_11 ;
int V_25 = 0 , V_26 = 0 ;
if ( V_2 -> V_27 == V_28 ) {
V_9 = V_19 [ 2 ] & 0x10 ;
V_10 = V_19 [ 2 ] & 0x08 ;
V_11 = 0 ;
V_20 = V_19 [ 1 ] | ( ( V_19 [ 0 ] & 0x07 ) << 7 ) ;
V_21 = V_19 [ 4 ] | ( ( V_19 [ 3 ] & 0x07 ) << 7 ) ;
V_22 = V_19 [ 5 ] ;
} else {
V_9 = V_19 [ 3 ] & 1 ;
V_10 = V_19 [ 3 ] & 2 ;
V_11 = V_19 [ 3 ] & 4 ;
V_20 = V_19 [ 1 ] | ( ( V_19 [ 2 ] & 0x78 ) << ( 7 - 3 ) ) ;
V_21 = V_19 [ 4 ] | ( ( V_19 [ 3 ] & 0x70 ) << ( 7 - 4 ) ) ;
V_22 = V_19 [ 5 ] ;
}
if ( V_2 -> V_29 & V_30 ) {
V_25 = V_19 [ 0 ] & 0x10 ;
V_26 = V_19 [ 2 ] & 4 ;
}
if ( V_2 -> V_29 & V_31 ) {
V_25 = V_19 [ 3 ] & 4 ;
V_26 = V_19 [ 2 ] & 4 ;
if ( ( V_11 = V_26 && V_25 ) )
V_26 = V_25 = 0 ;
}
V_23 = V_19 [ 2 ] & 1 ;
V_24 = V_19 [ 2 ] & 2 ;
if ( ( V_2 -> V_29 & V_32 ) && V_22 == 127 ) {
F_7 ( V_8 , V_33 , ( V_20 > 383 ? ( V_20 - 768 ) : V_20 ) ) ;
F_7 ( V_8 , V_34 , - ( V_21 > 255 ? ( V_21 - 512 ) : V_21 ) ) ;
F_2 ( V_8 , V_12 , V_9 , V_10 , V_11 ) ;
F_5 ( V_8 ) ;
return;
}
if ( V_2 -> V_27 == V_35 &&
V_2 -> V_29 == ( V_36 | V_32 ) ) {
V_9 |= V_19 [ 0 ] & 1 ;
V_10 |= V_19 [ 0 ] & 2 ;
V_11 |= V_19 [ 0 ] & 4 ;
}
F_2 ( V_12 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_23 && ! V_24 )
V_22 = 40 ;
if ( V_23 && V_24 && ! V_2 -> V_37 ) {
F_8 ( V_12 , V_38 , V_20 ) ;
F_8 ( V_12 , V_39 , V_21 ) ;
F_8 ( V_12 , V_40 , 0 ) ;
F_4 ( V_12 , V_41 , 0 ) ;
F_5 ( V_12 ) ;
}
V_2 -> V_37 = V_24 ;
if ( V_22 > 30 )
F_4 ( V_12 , V_42 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_12 , V_42 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_12 , V_38 , V_20 ) ;
F_8 ( V_12 , V_39 , V_21 ) ;
}
F_8 ( V_12 , V_40 , V_22 ) ;
F_4 ( V_12 , V_41 , V_22 > 0 ) ;
if ( V_2 -> V_29 & V_43 )
F_7 ( V_12 , V_44 , ( ( V_19 [ 2 ] << 1 ) & 0x08 ) - ( ( V_19 [ 0 ] >> 4 ) & 0x07 ) ) ;
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
F_4 ( V_12 , V_45 , V_26 ) ;
F_4 ( V_12 , V_46 , V_25 ) ;
}
if ( V_2 -> V_29 & V_47 ) {
F_4 ( V_12 , V_48 , V_19 [ 2 ] & 4 ) ;
F_4 ( V_12 , V_49 , V_19 [ 0 ] & 0x10 ) ;
F_4 ( V_12 , V_50 , V_19 [ 3 ] & 4 ) ;
F_4 ( V_12 , V_51 , V_19 [ 0 ] & 0x20 ) ;
}
F_5 ( V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
int V_54 , V_55 ;
unsigned int V_56 , V_57 ;
unsigned char V_58 , V_59 ;
unsigned char V_60 , V_61 , V_62 , V_63 ;
V_56 = V_53 -> V_56 ;
V_57 = V_53 -> V_57 ;
if ( ! V_56 || ! V_57 )
return;
V_60 = F_10 ( V_56 ) ;
V_61 = F_11 ( V_56 ) ;
V_62 = F_10 ( V_57 ) ;
V_63 = F_11 ( V_57 ) ;
if ( V_60 > V_2 -> V_64 || V_62 > V_2 -> V_65 )
return;
if ( V_53 -> V_66 > 1 ) {
V_58 = V_2 -> V_64 - V_60 ;
V_59 = V_2 -> V_64 - V_61 ;
V_54 = ( V_2 -> V_67 * ( V_58 + V_59 ) ) /
( 2 * ( V_2 -> V_64 - 1 ) ) ;
V_58 = V_63 - 1 ;
V_59 = V_62 - 1 ;
V_55 = ( V_2 -> V_68 * ( V_58 + V_59 ) ) /
( 2 * ( V_2 -> V_65 - 1 ) ) ;
V_53 -> V_69 [ 0 ] = V_53 -> V_70 ;
V_53 -> V_69 [ 1 ] . V_20 = 2 * V_54 - V_53 -> V_69 [ 0 ] . V_20 ;
V_53 -> V_69 [ 1 ] . V_21 = 2 * V_55 - V_53 -> V_69 [ 0 ] . V_21 ;
}
}
static void F_12 ( unsigned int V_71 ,
struct V_72 * V_73 ,
struct V_72 * V_74 ,
int * V_66 )
{
struct V_72 * V_75 ;
int V_76 , V_77 , V_78 = 0 ;
V_75 = V_73 ;
for ( V_76 = 0 ; V_71 != 0 ; V_76 ++ , V_71 >>= 1 ) {
V_77 = V_71 & 1 ;
if ( V_77 ) {
if ( ! V_78 ) {
V_75 -> V_58 = V_76 ;
V_75 -> V_79 = 0 ;
( * V_66 ) ++ ;
}
V_75 -> V_79 ++ ;
} else {
if ( V_78 )
V_75 = V_74 ;
}
V_78 = V_77 ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
int V_76 , V_80 = 0 , V_81 = 0 , V_66 ;
struct V_72 V_82 = { 0 ,} , V_83 = { 0 ,} ;
struct V_72 V_84 = { 0 ,} , V_85 = { 0 ,} ;
if ( ! V_53 -> V_56 || ! V_53 -> V_57 )
return 0 ;
F_12 ( V_53 -> V_56 , & V_82 , & V_83 , & V_80 ) ;
F_12 ( V_53 -> V_57 , & V_84 , & V_85 , & V_81 ) ;
V_66 = F_14 ( V_80 , V_81 ) ;
if ( V_80 == 1 ) {
V_76 = ( V_82 . V_79 - 1 ) / 2 ;
V_82 . V_79 = V_82 . V_79 - V_76 ;
V_83 . V_58 = V_82 . V_58 + V_76 ;
V_83 . V_79 = F_14 ( V_76 , 1 ) ;
}
if ( V_81 == 1 ) {
V_76 = ( V_84 . V_79 - 1 ) / 2 ;
V_84 . V_79 = V_84 . V_79 - V_76 ;
V_85 . V_58 = V_84 . V_58 + V_76 ;
V_85 . V_79 = F_14 ( V_76 , 1 ) ;
}
V_53 -> V_69 [ 0 ] . V_20 =
( V_2 -> V_67 * ( 2 * V_82 . V_58 + V_82 . V_79 - 1 ) ) /
( 2 * ( V_2 -> V_64 - 1 ) ) ;
V_53 -> V_69 [ 0 ] . V_21 =
( V_2 -> V_68 * ( 2 * V_84 . V_58 + V_84 . V_79 - 1 ) ) /
( 2 * ( V_2 -> V_65 - 1 ) ) ;
V_53 -> V_69 [ 1 ] . V_20 =
( V_2 -> V_67 * ( 2 * V_83 . V_58 + V_83 . V_79 - 1 ) ) /
( 2 * ( V_2 -> V_64 - 1 ) ) ;
V_53 -> V_69 [ 1 ] . V_21 =
( V_2 -> V_68 * ( 2 * V_85 . V_58 + V_85 . V_79 - 1 ) ) /
( 2 * ( V_2 -> V_65 - 1 ) ) ;
if ( V_2 -> V_27 != V_86 ) {
V_53 -> V_69 [ 0 ] . V_21 = V_2 -> V_68 - V_53 -> V_69 [ 0 ] . V_21 ;
V_53 -> V_69 [ 1 ] . V_21 = V_2 -> V_68 - V_53 -> V_69 [ 1 ] . V_21 ;
}
return V_66 ;
}
static void F_15 ( struct V_6 * V_12 , int V_87 , int V_20 , int V_21 )
{
F_16 ( V_12 , V_87 ) ;
F_17 ( V_12 , V_88 , true ) ;
F_8 ( V_12 , V_89 , V_20 ) ;
F_8 ( V_12 , V_90 , V_21 ) ;
}
static void F_18 ( struct V_17 * V_17 , int V_91 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_52 * V_92 = & V_2 -> V_92 ;
int V_76 , V_87 [ V_93 ] ;
F_19 ( V_12 , V_87 , V_92 -> V_69 , V_91 , 0 ) ;
for ( V_76 = 0 ; V_76 < V_91 ; V_76 ++ )
F_15 ( V_12 , V_87 [ V_76 ] , V_92 -> V_69 [ V_76 ] . V_20 , V_92 -> V_69 [ V_76 ] . V_21 ) ;
F_20 ( V_12 ) ;
}
static void F_21 ( struct V_17 * V_17 , int V_66 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_52 * V_92 = & V_2 -> V_92 ;
if ( V_66 < 2 ) {
V_92 -> V_69 [ 0 ] . V_20 = V_92 -> V_70 . V_20 ;
V_92 -> V_69 [ 0 ] . V_21 = V_92 -> V_70 . V_21 ;
V_66 = V_92 -> V_94 > 0 ? 1 : 0 ;
}
F_18 ( V_17 , ( V_66 <= 2 ) ? V_66 : 2 ) ;
F_22 ( V_12 , V_66 ) ;
F_4 ( V_12 , V_13 , V_92 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_92 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_92 -> V_11 ) ;
F_8 ( V_12 , V_40 , V_92 -> V_94 ) ;
F_5 ( V_12 ) ;
}
static void F_23 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_9 , V_10 , V_11 ;
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_24 ( V_17 ,
L_1 ) ;
return;
}
if ( ! ( V_19 [ 0 ] & 0x40 ) ) {
F_25 ( V_17 , L_2 ) ;
return;
}
if ( V_19 [ 1 ] == 0x7f && V_19 [ 2 ] == 0x7f && V_19 [ 4 ] == 0x7f )
return;
V_20 = ( V_95 ) ( ( ( V_19 [ 0 ] & 0x20 ) << 2 ) | ( V_19 [ 1 ] & 0x7f ) ) ;
V_21 = ( V_95 ) ( ( ( V_19 [ 0 ] & 0x10 ) << 3 ) | ( V_19 [ 2 ] & 0x7f ) ) ;
V_22 = ( V_19 [ 4 ] & 0x7c ) >> 2 ;
V_20 /= 8 ;
V_21 /= 8 ;
F_7 ( V_12 , V_33 , V_20 ) ;
F_7 ( V_12 , V_34 , - V_21 ) ;
V_9 = V_19 [ 3 ] & 0x01 ;
V_10 = V_19 [ 3 ] & 0x02 ;
V_11 = V_19 [ 3 ] & 0x04 ;
if ( ! ( V_2 -> V_96 & V_97 ) &&
( V_9 || V_10 || V_11 ) )
V_2 -> V_96 |= V_97 ;
if ( V_2 -> V_96 & V_97 ) {
F_4 ( V_12 , V_13 , V_9 ) ;
F_4 ( V_12 , V_15 , V_10 ) ;
F_4 ( V_12 , V_16 , V_11 ) ;
}
F_5 ( V_12 ) ;
return;
}
static void F_26 ( struct V_52 * V_92 , unsigned char * V_98 )
{
V_92 -> V_9 = ! ! ( V_98 [ 3 ] & 0x01 ) ;
V_92 -> V_10 = ! ! ( V_98 [ 3 ] & 0x02 ) ;
V_92 -> V_11 = ! ! ( V_98 [ 3 ] & 0x04 ) ;
V_92 -> V_99 = ! ! ( V_98 [ 3 ] & 0x10 ) ;
V_92 -> V_100 = ! ! ( V_98 [ 3 ] & 0x20 ) ;
V_92 -> V_101 = ! ! ( V_98 [ 3 ] & 0x40 ) ;
}
static int F_27 ( struct V_52 * V_92 , unsigned char * V_98 ,
struct V_17 * V_17 )
{
V_92 -> V_102 = ! ! ( V_98 [ 4 ] & 0x40 ) ;
V_92 -> V_103 = ! ! ( V_98 [ 0 ] & 0x40 ) ;
V_92 -> V_66 = ( V_98 [ 5 ] & 0x3 ) + 1 ;
V_92 -> V_56 = ( ( V_98 [ 4 ] & 0x7e ) << 8 ) |
( ( V_98 [ 1 ] & 0x7f ) << 2 ) |
( ( V_98 [ 0 ] & 0x30 ) >> 4 ) ;
V_92 -> V_57 = ( ( V_98 [ 3 ] & 0x70 ) << 4 ) |
( ( V_98 [ 2 ] & 0x7f ) << 1 ) |
( V_98 [ 4 ] & 0x01 ) ;
V_92 -> V_70 . V_20 = ( ( V_98 [ 1 ] & 0x7f ) << 4 ) | ( ( V_98 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_98 [ 0 ] & 0x30 ) >> 4 ) ;
V_92 -> V_70 . V_21 = ( ( V_98 [ 2 ] & 0x7f ) << 4 ) | ( V_98 [ 4 ] & 0x0f ) ;
V_92 -> V_94 = V_98 [ 5 ] & 0x7f ;
F_26 ( V_92 , V_98 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_92 , unsigned char * V_98 ,
struct V_17 * V_17 )
{
F_27 ( V_92 , V_98 , V_17 ) ;
V_92 -> V_103 = ! ! ( V_98 [ 5 ] & 0x40 ) ;
V_92 -> V_66 = F_14 ( ( V_98 [ 5 ] & 0x3 ) , ( ( V_98 [ 5 ] >> 2 ) & 0x3 ) ) + 1 ;
V_92 -> V_56 |= ( V_98 [ 5 ] & 0x10 ) << 11 ;
V_92 -> V_57 |= ( V_98 [ 5 ] & 0x20 ) << 6 ;
return 0 ;
}
static int F_29 ( struct V_52 * V_92 , unsigned char * V_98 ,
struct V_17 * V_17 )
{
T_1 V_104 = 0 ;
struct V_1 * V_2 = V_17 -> V_18 ;
V_92 -> V_102 = ! ! ( V_98 [ 0 ] & 0x02 ) ;
V_92 -> V_103 = ! ! ( V_98 [ 0 ] & 0x20 ) ;
if ( ! V_92 -> V_103 ) {
V_92 -> V_70 . V_20 = ( ( V_98 [ 1 ] & 0x7f ) | ( ( V_98 [ 4 ] & 0x0f ) << 7 ) ) ;
V_92 -> V_70 . V_21 = ( ( V_98 [ 2 ] & 0x7f ) | ( ( V_98 [ 4 ] & 0xf0 ) << 3 ) ) ;
V_92 -> V_94 = ( V_98 [ 0 ] & 4 ) ? 0 : V_98 [ 5 ] & 0x7f ;
F_26 ( V_92 , V_98 ) ;
} else {
V_92 -> V_66 = ( ( V_98 [ 0 ] & 0x6 ) >> 1 |
( V_98 [ 0 ] & 0x10 ) >> 2 ) ;
V_104 = ( V_98 [ 1 ] & 0x7f ) |
( ( V_98 [ 2 ] & 0x7f ) << 7 ) |
( ( V_98 [ 4 ] & 0x7f ) << 14 ) |
( ( V_98 [ 5 ] & 0x7f ) << 21 ) |
( ( V_98 [ 3 ] & 0x07 ) << 28 ) |
( ( ( T_1 ) V_98 [ 3 ] & 0x70 ) << 27 ) |
( ( ( T_1 ) V_98 [ 0 ] & 0x01 ) << 34 ) ;
V_92 -> V_57 = V_104 & ( F_30 ( V_2 -> V_65 ) - 1 ) ;
V_92 -> V_56 = ( V_104 >> V_2 -> V_65 ) &
( F_30 ( V_2 -> V_64 ) - 1 ) ;
}
return 0 ;
}
static void F_31 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_8 = V_2 -> V_8 ;
struct V_52 * V_92 = & V_2 -> V_92 ;
int V_66 = 0 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_2 -> V_105 ( V_92 , V_19 , V_17 ) ;
if ( V_2 -> V_106 ) {
if ( V_92 -> V_103 ) {
V_66 = V_92 -> V_66 ;
if ( V_2 -> V_27 == V_107 ||
V_2 -> V_27 == V_86 ) {
if ( F_13 ( V_2 , V_92 ) == 0 )
V_66 = 0 ;
V_2 -> V_105 ( V_92 , V_2 -> V_108 ,
V_17 ) ;
} else {
V_2 -> V_105 ( V_92 , V_2 -> V_108 ,
V_17 ) ;
F_9 ( V_2 , V_92 ) ;
}
} else {
V_2 -> V_106 = 0 ;
}
}
if ( V_92 -> V_103 )
return;
if ( ! V_2 -> V_106 && V_92 -> V_102 ) {
V_2 -> V_106 = 1 ;
memcpy ( V_2 -> V_108 , V_19 , sizeof( V_2 -> V_108 ) ) ;
return;
}
V_2 -> V_106 = 0 ;
if ( V_92 -> V_70 . V_20 && V_92 -> V_70 . V_21 && ! V_92 -> V_94 )
return;
F_21 ( V_17 , V_66 ) ;
if ( ( V_2 -> V_29 & V_32 ) &&
! ( V_2 -> V_96 & V_97 ) ) {
F_4 ( V_8 , V_13 , V_92 -> V_99 ) ;
F_4 ( V_8 , V_15 , V_92 -> V_100 ) ;
F_4 ( V_8 , V_16 , V_92 -> V_101 ) ;
F_5 ( V_8 ) ;
}
}
static void F_32 ( struct V_17 * V_17 )
{
unsigned char * V_19 = V_17 -> V_19 ;
if ( V_19 [ 5 ] == 0x3f ) {
F_23 ( V_17 ) ;
return;
}
F_31 ( V_17 ) ;
}
static void F_33 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_6 * V_8 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_9 , V_10 , V_11 ;
if ( V_19 [ 5 ] == 0x7F ) {
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_24 ( V_17 ,
L_1 ) ;
return;
}
V_20 = V_19 [ 1 ] | ( ( V_19 [ 3 ] & 0x20 ) << 2 ) ;
V_21 = V_19 [ 2 ] | ( ( V_19 [ 3 ] & 0x40 ) << 1 ) ;
V_22 = V_19 [ 4 ] ;
V_9 = V_19 [ 3 ] & 0x01 ;
V_10 = V_19 [ 3 ] & 0x02 ;
V_11 = V_19 [ 3 ] & 0x04 ;
if ( V_20 == 0x7F && V_21 == 0x7F && V_22 == 0x7F )
V_20 = V_21 = V_22 = 0 ;
F_7 ( V_8 , V_33 , ( char ) V_20 / 4 ) ;
F_7 ( V_8 , V_34 , - ( ( char ) V_21 / 4 ) ) ;
F_4 ( V_8 , V_13 , V_9 ) ;
F_4 ( V_8 , V_15 , V_10 ) ;
F_4 ( V_8 , V_16 , V_11 ) ;
F_5 ( V_8 ) ;
return;
}
V_20 = V_19 [ 1 ] | ( ( V_19 [ 3 ] & 0x78 ) << 4 ) ;
V_21 = V_19 [ 2 ] | ( ( V_19 [ 4 ] & 0x78 ) << 4 ) ;
V_22 = V_19 [ 5 ] ;
V_9 = V_19 [ 3 ] & 0x01 ;
V_10 = V_19 [ 3 ] & 0x02 ;
if ( V_22 > 30 )
F_4 ( V_12 , V_42 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_12 , V_42 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_12 , V_38 , V_20 ) ;
F_8 ( V_12 , V_39 , V_21 ) ;
}
F_8 ( V_12 , V_40 , V_22 ) ;
F_4 ( V_12 , V_41 , V_22 > 0 ) ;
F_4 ( V_12 , V_13 , V_9 ) ;
F_4 ( V_12 , V_15 , V_10 ) ;
F_5 ( V_12 ) ;
}
static void F_34 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_52 * V_92 = & V_2 -> V_92 ;
int V_109 ;
if ( V_19 [ 6 ] & 0x40 ) {
V_2 -> V_106 = 0 ;
}
if ( F_35 ( V_2 -> V_106 > 2 ) )
return;
V_109 = 2 * V_2 -> V_106 ;
V_2 -> V_108 [ V_109 ] = V_19 [ 6 ] ;
V_2 -> V_108 [ V_109 + 1 ] = V_19 [ 7 ] ;
if ( ++ V_2 -> V_106 > 2 ) {
V_2 -> V_106 = 0 ;
V_92 -> V_56 = ( ( V_2 -> V_108 [ 2 ] & 0x1f ) << 10 ) |
( ( V_2 -> V_108 [ 3 ] & 0x60 ) << 3 ) |
( ( V_2 -> V_108 [ 0 ] & 0x3f ) << 2 ) |
( ( V_2 -> V_108 [ 1 ] & 0x60 ) >> 5 ) ;
V_92 -> V_57 = ( ( V_2 -> V_108 [ 5 ] & 0x01 ) << 10 ) |
( ( V_2 -> V_108 [ 3 ] & 0x1f ) << 5 ) |
( V_2 -> V_108 [ 1 ] & 0x1f ) ;
V_92 -> V_66 = F_13 ( V_2 , V_92 ) ;
}
V_92 -> V_9 = ! ! ( V_19 [ 4 ] & 0x01 ) ;
V_92 -> V_10 = ! ! ( V_19 [ 4 ] & 0x02 ) ;
V_92 -> V_70 . V_20 = ( ( V_19 [ 1 ] & 0x7f ) << 4 ) | ( ( V_19 [ 3 ] & 0x30 ) >> 2 ) |
( ( V_19 [ 0 ] & 0x30 ) >> 4 ) ;
V_92 -> V_70 . V_21 = ( ( V_19 [ 2 ] & 0x7f ) << 4 ) | ( V_19 [ 3 ] & 0x0f ) ;
V_92 -> V_94 = V_19 [ 5 ] & 0x7f ;
F_21 ( V_17 , V_92 -> V_66 ) ;
}
static bool F_36 ( struct V_17 * V_17 )
{
switch ( V_17 -> V_110 ) {
case 3 :
return ( V_17 -> V_19 [ 2 ] & 0x40 ) == 0x40 ;
case 4 :
return ( V_17 -> V_19 [ 3 ] & 0x48 ) == 0x48 ;
case 6 :
return ( V_17 -> V_19 [ 5 ] & 0x40 ) == 0x00 ;
}
return true ;
}
static unsigned char F_37 ( char * V_111 )
{
unsigned char V_112 ;
if ( V_111 [ 4 ] & 0x40 )
V_112 = V_113 ;
else if ( V_111 [ 4 ] & 0x01 )
V_112 = V_114 ;
else if ( ( V_111 [ 0 ] & 0x10 ) && ! ( V_111 [ 4 ] & 0x43 ) )
V_112 = V_115 ;
else if ( V_111 [ 1 ] == 0x00 && V_111 [ 4 ] == 0x00 )
V_112 = V_116 ;
else
V_112 = V_117 ;
return V_112 ;
}
static void F_38 ( struct V_118 * V_69 ,
unsigned char * V_119 ,
unsigned char V_120 )
{
V_69 [ 0 ] . V_20 = ( ( V_119 [ 2 ] & 0x80 ) << 4 ) ;
V_69 [ 0 ] . V_20 |= ( ( V_119 [ 2 ] & 0x3F ) << 5 ) ;
V_69 [ 0 ] . V_20 |= ( ( V_119 [ 3 ] & 0x30 ) >> 1 ) ;
V_69 [ 0 ] . V_20 |= ( V_119 [ 3 ] & 0x07 ) ;
V_69 [ 0 ] . V_21 = ( V_119 [ 1 ] << 3 ) | ( V_119 [ 0 ] & 0x07 ) ;
V_69 [ 1 ] . V_20 = ( ( V_119 [ 3 ] & 0x80 ) << 4 ) ;
V_69 [ 1 ] . V_20 |= ( ( V_119 [ 4 ] & 0x80 ) << 3 ) ;
V_69 [ 1 ] . V_20 |= ( ( V_119 [ 4 ] & 0x3F ) << 4 ) ;
V_69 [ 1 ] . V_21 = ( ( V_119 [ 5 ] & 0x80 ) << 3 ) ;
V_69 [ 1 ] . V_21 |= ( ( V_119 [ 5 ] & 0x3F ) << 4 ) ;
switch ( V_120 ) {
case V_113 :
V_69 [ 1 ] . V_20 &= ~ 0x000F ;
V_69 [ 1 ] . V_21 |= 0x000F ;
if ( V_69 [ 1 ] . V_21 == 0x7ff && V_69 [ 1 ] . V_20 == 0xff0 ) {
V_69 [ 1 ] . V_20 = 0 ;
}
break;
case V_114 :
V_69 [ 1 ] . V_20 &= ~ 0x003F ;
V_69 [ 1 ] . V_21 &= ~ 0x0020 ;
V_69 [ 1 ] . V_21 |= ( ( V_119 [ 4 ] & 0x02 ) << 4 ) ;
V_69 [ 1 ] . V_21 |= 0x001F ;
break;
case V_115 :
V_69 [ 1 ] . V_20 &= ~ 0x003F ;
V_69 [ 1 ] . V_20 |= ( V_119 [ 0 ] & 0x20 ) ;
V_69 [ 1 ] . V_21 |= 0x000F ;
break;
}
V_69 [ 0 ] . V_21 = 0x7FF - V_69 [ 0 ] . V_21 ;
V_69 [ 1 ] . V_21 = 0x7FF - V_69 [ 1 ] . V_21 ;
}
static int F_39 ( struct V_118 * V_69 )
{
int V_76 , V_66 = 0 ;
for ( V_76 = 0 ; V_76 < V_93 ; V_76 ++ ) {
if ( V_69 [ V_76 ] . V_20 != 0 || V_69 [ V_76 ] . V_21 != 0 )
V_66 ++ ;
}
return V_66 ;
}
static int F_40 ( struct V_52 * V_92 ,
unsigned char * V_98 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_120 ;
V_120 = F_37 ( V_98 ) ;
if ( V_120 == V_116 )
return 0 ;
if ( V_120 == V_117 )
return - 1 ;
if ( V_120 == V_115 )
return 1 ;
F_38 ( V_92 -> V_69 , V_98 , V_120 ) ;
if ( V_120 == V_113 )
V_92 -> V_66 = F_39 ( V_92 -> V_69 ) ;
else
V_92 -> V_66 = 3 + ( V_98 [ 5 ] & 0x03 ) ;
V_92 -> V_9 = ( V_98 [ 0 ] & 0x80 ) >> 7 ;
if ( V_2 -> V_29 & V_121 ) {
if ( V_98 [ 0 ] & 0x20 )
V_92 -> V_66 ++ ;
if ( V_98 [ 0 ] & 0x10 )
V_92 -> V_66 ++ ;
} else {
V_92 -> V_10 = ( V_98 [ 0 ] & 0x20 ) >> 5 ;
V_92 -> V_11 = ( V_98 [ 0 ] & 0x10 ) >> 4 ;
}
if ( V_92 -> V_66 == 1 && V_92 -> V_69 [ 0 ] . V_20 == 0 && V_92 -> V_69 [ 0 ] . V_21 == 0 ) {
V_92 -> V_69 [ 0 ] . V_20 = V_92 -> V_69 [ 1 ] . V_20 ;
V_92 -> V_69 [ 0 ] . V_21 = V_92 -> V_69 [ 1 ] . V_21 ;
V_92 -> V_69 [ 1 ] . V_20 = 0 ;
V_92 -> V_69 [ 1 ] . V_21 = 0 ;
}
return 0 ;
}
static void F_41 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_8 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_9 , V_10 , V_11 ;
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_24 ( V_17 ,
L_1 ) ;
return;
}
V_20 = ( ( V_19 [ 2 ] & 0xbf ) ) | ( ( V_19 [ 3 ] & 0x10 ) << 2 ) ;
V_21 = ( V_19 [ 3 ] & 0x07 ) | ( V_19 [ 4 ] & 0xb8 ) |
( ( V_19 [ 3 ] & 0x20 ) << 1 ) ;
V_22 = ( V_19 [ 5 ] & 0x3f ) | ( ( V_19 [ 3 ] & 0x80 ) >> 1 ) ;
V_9 = ( V_19 [ 1 ] & 0x01 ) ;
V_10 = ( V_19 [ 1 ] & 0x02 ) >> 1 ;
V_11 = ( V_19 [ 1 ] & 0x04 ) >> 2 ;
F_7 ( V_8 , V_33 , ( char ) V_20 ) ;
F_7 ( V_8 , V_34 , - ( ( char ) V_21 ) ) ;
F_4 ( V_8 , V_13 , V_9 ) ;
F_4 ( V_8 , V_15 , V_10 ) ;
F_4 ( V_8 , V_16 , V_11 ) ;
F_5 ( V_8 ) ;
}
static void F_42 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_52 * V_92 = & V_2 -> V_92 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
if ( V_2 -> V_105 ( V_92 , V_17 -> V_19 , V_17 ) )
return;
F_18 ( V_17 , F_39 ( V_92 -> V_69 ) ) ;
F_22 ( V_12 , V_92 -> V_66 ) ;
F_4 ( V_12 , V_13 , V_92 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_92 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_92 -> V_11 ) ;
F_5 ( V_12 ) ;
}
static void F_43 ( struct V_17 * V_17 )
{
unsigned char * V_19 = V_17 -> V_19 ;
if ( V_19 [ 0 ] == 0x48 && ( V_19 [ 4 ] & 0x47 ) == 0x06 )
F_41 ( V_17 ) ;
else
F_42 ( V_17 ) ;
}
static unsigned char F_44 ( unsigned char * V_111 )
{
unsigned char V_120 = V_122 ;
if ( V_111 [ 0 ] == 0x18 && V_111 [ 1 ] == 0x10 && V_111 [ 2 ] == 0x00 &&
( V_111 [ 3 ] & 0x88 ) == 0x08 && V_111 [ 4 ] == 0x10 && V_111 [ 5 ] == 0x00 ) {
V_120 = V_122 ;
} else if ( ! ( V_111 [ 3 ] & 0x10 ) ) {
V_120 = V_123 ;
} else if ( ! ( V_111 [ 3 ] & 0x20 ) ) {
V_120 = V_124 ;
} else {
V_120 = V_125 ;
}
return V_120 ;
}
static int F_45 ( struct V_52 * V_92 ,
unsigned char * V_98 , struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_120 ;
unsigned int V_126 , V_127 ;
V_120 = F_44 ( V_98 ) ;
switch ( V_120 ) {
case V_123 :
V_92 -> V_69 [ 0 ] . V_20 = F_46 ( V_98 ) ;
V_92 -> V_69 [ 0 ] . V_21 = F_47 ( V_98 ) ;
V_92 -> V_94 = ( ( F_48 ( V_98 ) ) * 2 ) & 0x7f ;
V_92 -> V_66 = 1 ;
V_92 -> V_102 = 0 ;
V_92 -> V_103 = 0 ;
break;
case V_124 :
if ( V_2 -> V_29 & V_121 ) {
V_92 -> V_69 [ 0 ] . V_20 = F_49 ( V_98 , 0 ) ;
V_92 -> V_69 [ 0 ] . V_21 = F_50 ( V_98 , 0 ) ;
V_92 -> V_69 [ 1 ] . V_20 = F_49 ( V_98 , 1 ) ;
V_92 -> V_69 [ 1 ] . V_21 = F_50 ( V_98 , 1 ) ;
} else {
V_92 -> V_69 [ 0 ] . V_20 = F_51 ( V_98 , 0 ) ;
V_92 -> V_69 [ 0 ] . V_21 = F_52 ( V_98 , 0 ) ;
V_92 -> V_69 [ 1 ] . V_20 = F_51 ( V_98 , 1 ) ;
V_92 -> V_69 [ 1 ] . V_21 = F_52 ( V_98 , 1 ) ;
}
V_92 -> V_94 = F_53 ( V_98 , 0 ) ? 0x30 : 0 ;
if ( F_54 ( V_98 ) ) {
V_92 -> V_102 = 1 ;
} else {
V_92 -> V_66 = 2 ;
V_92 -> V_102 = 0 ;
}
V_92 -> V_103 = 0 ;
break;
case V_125 :
if ( V_2 -> V_29 & V_121 ) {
V_92 -> V_69 [ 2 ] . V_20 = F_49 ( V_98 , 0 ) ;
V_92 -> V_69 [ 2 ] . V_21 = F_50 ( V_98 , 0 ) ;
V_92 -> V_69 [ 3 ] . V_20 = F_49 ( V_98 , 1 ) ;
V_92 -> V_69 [ 3 ] . V_21 = F_50 ( V_98 , 1 ) ;
V_126 = V_128 ;
V_127 = V_129 ;
} else {
V_92 -> V_69 [ 2 ] . V_20 = F_51 ( V_98 , 0 ) ;
V_92 -> V_69 [ 2 ] . V_21 = F_52 ( V_98 , 0 ) ;
V_92 -> V_69 [ 3 ] . V_20 = F_51 ( V_98 , 1 ) ;
V_92 -> V_69 [ 3 ] . V_21 = F_52 ( V_98 , 1 ) ;
V_126 = V_130 ;
V_127 = V_131 ;
}
V_92 -> V_102 = 0 ;
V_92 -> V_103 = 1 ;
if ( F_55 ( V_98 ) ) {
V_92 -> V_66 = 5 ;
} else if ( V_92 -> V_69 [ 3 ] . V_20 == V_126 &&
V_92 -> V_69 [ 3 ] . V_21 == V_127 ) {
V_92 -> V_69 [ 3 ] . V_20 = 0 ;
V_92 -> V_69 [ 3 ] . V_21 = 0 ;
V_92 -> V_66 = 3 ;
} else {
V_92 -> V_66 = 4 ;
}
break;
case V_122 :
default:
memset ( V_92 , 0 , sizeof( struct V_52 ) ) ;
break;
}
V_92 -> V_9 = ! ! ( F_56 ( V_98 ) & 0x01 ) ;
if ( ! ( V_2 -> V_29 & V_121 ) ) {
V_92 -> V_10 = ! ! ( F_56 ( V_98 ) & 0x02 ) ;
V_92 -> V_11 = ! ! ( F_56 ( V_98 ) & 0x04 ) ;
}
return 0 ;
}
static void F_57 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_52 * V_92 = & V_2 -> V_92 ;
memset ( V_92 , 0 , sizeof( struct V_52 ) ) ;
V_2 -> V_105 ( V_92 , V_19 , V_17 ) ;
if ( V_2 -> V_106 ) {
if ( V_92 -> V_103 ) {
V_2 -> V_105 ( V_92 , V_2 -> V_108 , V_17 ) ;
} else {
V_2 -> V_106 = 0 ;
}
}
if ( V_92 -> V_103 )
return;
if ( ! V_2 -> V_106 && V_92 -> V_102 ) {
V_2 -> V_106 = 1 ;
memcpy ( V_2 -> V_108 , V_19 , sizeof( V_2 -> V_108 ) ) ;
return;
}
V_2 -> V_106 = 0 ;
F_18 ( V_17 , ( V_92 -> V_66 <= 4 ) ? V_92 -> V_66 : 4 ) ;
F_22 ( V_12 , V_92 -> V_66 ) ;
F_4 ( V_12 , V_13 , V_92 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_92 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_92 -> V_11 ) ;
F_8 ( V_12 , V_40 , V_92 -> V_94 ) ;
F_5 ( V_12 ) ;
}
static bool F_58 ( struct V_17 * V_17 )
{
if ( V_17 -> V_110 == 4 && ( ( V_17 -> V_19 [ 3 ] & 0x08 ) != 0x08 ) )
return false ;
if ( V_17 -> V_110 == 6 && ( ( V_17 -> V_19 [ 5 ] & 0x10 ) != 0x0 ) )
return false ;
return true ;
}
static void F_59 ( struct V_132 * V_133 )
{
struct V_1 * V_2 =
F_60 ( V_133 , struct V_1 , V_134 . V_133 ) ;
struct V_17 * V_17 = V_2 -> V_17 ;
struct V_6 * V_135 ;
int error = 0 ;
F_61 ( & V_136 ) ;
if ( V_2 -> V_135 )
goto V_137;
V_135 = F_62 () ;
if ( ! V_135 ) {
F_63 ( V_17 , L_3 ) ;
error = - V_138 ;
goto V_137;
}
snprintf ( V_2 -> V_139 , sizeof( V_2 -> V_139 ) , L_4 ,
V_17 -> V_140 . V_141 -> V_142 ,
( V_2 -> V_8 ? L_5 : L_6 ) ) ;
V_135 -> V_142 = V_2 -> V_139 ;
V_135 -> V_143 = L_7 ;
V_135 -> V_144 . V_145 = V_146 ;
V_135 -> V_144 . V_147 = 0x0002 ;
V_135 -> V_144 . V_148 = V_149 ;
V_135 -> V_144 . V_150 = 0x0000 ;
V_135 -> V_12 . V_151 = & V_17 -> V_140 . V_141 -> V_12 ;
F_64 ( V_135 , V_152 , V_33 ) ;
F_64 ( V_135 , V_152 , V_34 ) ;
F_64 ( V_135 , V_153 , V_13 ) ;
F_64 ( V_135 , V_153 , V_15 ) ;
F_64 ( V_135 , V_153 , V_16 ) ;
F_65 ( V_154 , V_135 -> V_155 ) ;
error = F_66 ( V_135 ) ;
if ( error ) {
F_63 ( V_17 ,
L_8 ,
error ) ;
F_67 ( V_135 ) ;
goto V_137;
}
V_2 -> V_135 = V_135 ;
V_137:
if ( error )
V_2 -> V_135 = F_68 ( error ) ;
F_69 ( & V_136 ) ;
}
static void F_70 ( struct V_17 * V_17 ,
unsigned char V_19 [] ,
bool V_156 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 , * V_8 = NULL ;
if ( V_2 -> V_27 == V_35 &&
( V_2 -> V_29 & V_32 ) ) {
V_12 = V_2 -> V_8 ;
V_8 = V_17 -> V_12 ;
} else if ( F_71 ( F_72 ( V_2 -> V_135 ) ) ) {
if ( ! F_73 ( V_2 -> V_135 ) )
F_74 ( V_17 , & V_2 -> V_134 ,
0 ) ;
return;
} else {
V_12 = V_2 -> V_135 ;
}
if ( V_156 )
F_2 ( V_12 , V_8 ,
V_19 [ 0 ] & 1 , V_19 [ 0 ] & 2 , V_19 [ 0 ] & 4 ) ;
F_7 ( V_12 , V_33 ,
V_19 [ 1 ] ? V_19 [ 1 ] - ( ( V_19 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_12 , V_34 ,
V_19 [ 2 ] ? ( ( V_19 [ 0 ] << 3 ) & 0x100 ) - V_19 [ 2 ] : 0 ) ;
F_5 ( V_12 ) ;
}
static T_2 F_75 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_17 -> V_110 < 6 )
return V_157 ;
if ( V_17 -> V_110 == 6 ) {
F_76 ( & V_2 -> V_158 , V_159 + F_77 ( 20 ) ) ;
return V_157 ;
}
F_78 ( & V_2 -> V_158 ) ;
if ( V_17 -> V_19 [ 6 ] & 0x80 ) {
if ( ( ( V_17 -> V_19 [ 3 ] |
V_17 -> V_19 [ 4 ] |
V_17 -> V_19 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_2 , V_17 -> V_19 [ 6 ] ) ) ) {
F_25 ( V_17 ,
L_9 ,
V_17 -> V_19 + 3 ) ;
return V_160 ;
}
V_2 -> V_161 ( V_17 ) ;
V_17 -> V_19 [ 0 ] = V_17 -> V_19 [ 6 ] ;
V_17 -> V_110 = 1 ;
} else {
F_70 ( V_17 , & V_17 -> V_19 [ 3 ] ,
false ) ;
V_17 -> V_19 [ 3 ] = V_17 -> V_19 [ 6 ] & 0xf7 ;
V_17 -> V_110 = 4 ;
}
return V_157 ;
}
static void F_79 ( unsigned long V_3 )
{
struct V_17 * V_17 = (struct V_17 * ) V_3 ;
struct V_1 * V_2 = V_17 -> V_18 ;
F_80 ( V_17 -> V_140 . V_141 ) ;
if ( V_17 -> V_110 == V_17 -> V_162 ) {
if ( ( V_17 -> V_19 [ 3 ] |
V_17 -> V_19 [ 4 ] |
V_17 -> V_19 [ 5 ] ) & 0x80 ) {
F_25 ( V_17 ,
L_10 ,
V_17 -> V_19 + 3 ) ;
} else {
V_2 -> V_161 ( V_17 ) ;
}
V_17 -> V_110 = 0 ;
}
F_81 ( V_17 -> V_140 . V_141 ) ;
}
static T_2 F_82 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_2 -> V_27 != V_163 &&
! V_17 -> V_164 &&
( V_17 -> V_19 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_17 -> V_110 == 3 ) {
F_70 ( V_17 , V_17 -> V_19 ,
true ) ;
return V_165 ;
}
return V_157 ;
}
if ( ( V_2 -> V_29 & V_166 ) &&
V_17 -> V_110 >= 4 && ( V_17 -> V_19 [ 3 ] & 0x0f ) == 0x0f ) {
return F_75 ( V_17 ) ;
}
if ( ! F_1 ( V_2 , V_17 -> V_19 [ 0 ] ) ) {
F_25 ( V_17 ,
L_11 ,
V_17 -> V_19 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_160 ;
}
if ( V_2 -> V_27 < V_167 &&
V_17 -> V_110 >= 2 && V_17 -> V_110 <= V_17 -> V_162 &&
( V_17 -> V_19 [ V_17 -> V_110 - 1 ] & 0x80 ) ) {
F_25 ( V_17 , L_12 ,
V_17 -> V_110 - 1 ,
V_17 -> V_19 [ V_17 -> V_110 - 1 ] ) ;
if ( V_2 -> V_27 == V_86 &&
V_17 -> V_110 == V_17 -> V_162 ) {
return V_165 ;
}
return V_160 ;
}
if ( ( V_2 -> V_27 == V_168 &&
! F_36 ( V_17 ) ) ||
( V_2 -> V_27 == V_163 &&
! F_58 ( V_17 ) ) ) {
F_25 ( V_17 , L_12 ,
V_17 -> V_110 - 1 ,
V_17 -> V_19 [ V_17 -> V_110 - 1 ] ) ;
return V_160 ;
}
if ( V_17 -> V_110 == V_17 -> V_162 ) {
V_2 -> V_161 ( V_17 ) ;
return V_165 ;
}
return V_157 ;
}
static int F_83 ( struct V_17 * V_17 , int V_169 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_170 ;
unsigned char * V_171 ;
unsigned char V_172 [ 4 ] ;
F_84 ( V_169 > 0xf ) ;
V_170 = V_2 -> V_173 [ V_169 ] . V_170 ;
V_171 = ( V_170 & 0x0f00 ) ?
V_172 : ( unsigned char * ) & V_2 -> V_173 [ V_169 ] . V_3 ;
if ( F_85 ( V_140 , V_171 , V_170 ) )
return - 1 ;
return 0 ;
}
static int F_86 ( struct V_17 * V_17 , int V_174 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_76 , V_169 ;
if ( F_85 ( V_140 , NULL , V_2 -> V_175 ) )
return - 1 ;
for ( V_76 = 12 ; V_76 >= 0 ; V_76 -= 4 ) {
V_169 = ( V_174 >> V_76 ) & 0xf ;
if ( F_83 ( V_17 , V_169 ) )
return - 1 ;
}
return 0 ;
}
static int F_87 ( struct V_17 * V_17 , int V_174 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_171 [ 4 ] ;
if ( F_85 ( V_140 , V_171 , V_176 ) )
return - 1 ;
if ( V_174 != ( ( V_171 [ 0 ] << 8 ) | V_171 [ 1 ] ) )
return - 1 ;
return V_171 [ 2 ] ;
}
static int F_88 ( struct V_17 * V_17 , int V_174 )
{
if ( F_86 ( V_17 , V_174 ) )
return - 1 ;
return F_87 ( V_17 , V_174 ) ;
}
static int F_89 ( struct V_17 * V_17 , T_3 V_177 )
{
if ( F_83 ( V_17 , ( V_177 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_83 ( V_17 , V_177 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_90 ( struct V_17 * V_17 , int V_174 ,
T_3 V_177 )
{
if ( F_86 ( V_17 , V_174 ) )
return - 1 ;
return F_89 ( V_17 , V_177 ) ;
}
static int F_91 ( struct V_17 * V_17 , int V_178 ,
int V_179 , unsigned char * V_171 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
V_171 [ 0 ] = 0 ;
if ( V_178 && F_85 ( V_140 , V_171 , V_178 ) )
return - V_180 ;
if ( F_85 ( V_140 , NULL , V_179 ) ||
F_85 ( V_140 , NULL , V_179 ) ||
F_85 ( V_140 , NULL , V_179 ) )
return - V_180 ;
V_171 [ 0 ] = V_171 [ 1 ] = V_171 [ 2 ] = 0xff ;
if ( F_85 ( V_140 , V_171 , V_176 ) )
return - V_180 ;
F_25 ( V_17 , L_13 ,
V_179 , V_171 ) ;
return 0 ;
}
static bool F_92 ( unsigned char V_144 [] )
{
if ( V_144 [ 0 ] == 0x73 )
return true ;
if ( V_144 [ 0 ] == 0x88 &&
( V_144 [ 1 ] == 0x07 ||
V_144 [ 1 ] == 0x08 ||
( V_144 [ 1 ] & 0xf0 ) == 0xb0 ||
( V_144 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
return true ;
}
return false ;
}
static int F_93 ( struct V_17 * V_17 )
{
unsigned char V_171 [ 4 ] ;
if ( F_91 ( V_17 , 0 , V_181 , V_171 ) ) {
F_63 ( V_17 , L_14 ) ;
return - 1 ;
}
if ( ! F_92 ( V_171 ) ) {
F_25 ( V_17 ,
L_15 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_94 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( F_85 ( V_140 , NULL , V_182 ) )
return - 1 ;
return 0 ;
}
static int F_95 ( struct V_17 * V_17 , bool V_183 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_184 = V_183 ? V_185 : V_186 ;
if ( F_85 ( V_140 , NULL , V_184 ) ||
F_85 ( V_140 , NULL , V_184 ) ||
F_85 ( V_140 , NULL , V_184 ) ||
F_85 ( V_140 , NULL , V_187 ) )
return - 1 ;
F_96 ( V_140 , 3 , 100 ) ;
return 0 ;
}
static int F_97 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_188 ) )
return - 1 ;
return F_85 ( & V_17 -> V_140 , NULL , V_189 ) ;
}
static int F_98 ( struct V_17 * V_17 , T_4 V_190 )
{
int V_76 , V_169 ;
for ( V_76 = 0 ; V_76 <= 8 ; V_76 += 4 ) {
V_169 = ( V_190 >> V_76 ) & 0xf ;
if ( F_83 ( V_17 , V_169 ) )
return - 1 ;
}
return 0 ;
}
static int F_99 ( struct V_17 * V_17 ,
T_4 V_174 , T_4 V_177 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( F_85 ( V_140 , NULL , V_188 ) ||
F_98 ( V_17 , 0x0A0 ) ||
F_98 ( V_17 , V_174 ) ||
F_98 ( V_17 , V_177 ) ||
F_85 ( V_140 , NULL , V_187 ) )
return - 1 ;
return 0 ;
}
static int F_100 ( struct V_17 * V_17 , bool V_183 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( V_183 ) {
if ( F_85 ( V_140 , NULL , V_181 ) ||
F_85 ( V_140 , NULL , V_176 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_185 ) ||
F_85 ( V_140 , NULL , V_186 ) ||
F_85 ( V_140 , NULL , V_185 ) ||
F_85 ( V_140 , NULL , V_176 ) )
return - 1 ;
} else {
if ( F_85 ( V_140 , NULL , V_181 ) )
return - 1 ;
}
return 0 ;
}
static int F_101 ( struct V_17 * V_17 )
{
T_4 V_191 = 0x181 ;
int V_192 = - 1 ;
if ( F_100 ( V_17 , true ) )
return - 1 ;
V_192 = F_99 ( V_17 , 0x000 , V_191 ) ;
if ( F_100 ( V_17 , false ) )
V_192 = - 1 ;
return V_192 ;
}
static int F_102 ( struct V_17 * V_17 , char * V_171 )
{
if ( F_91 ( V_17 , 0 , V_187 , V_171 ) )
return - 1 ;
return 0 ;
}
static int F_103 ( struct V_17 * V_17 , int V_183 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_184 = V_183 ? V_193 : V_194 ;
unsigned char V_195 = V_183 ? 0x0A : 0x00 ;
unsigned char V_171 [ 4 ] ;
if ( F_85 ( V_140 , V_171 , V_176 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , NULL , V_187 ) ||
F_85 ( V_140 , & V_195 , V_184 ) )
return - 1 ;
if ( F_102 ( V_17 , V_171 ) )
return - 1 ;
return 0 ;
}
static int F_104 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_196 [ sizeof( V_17 -> V_19 ) ] ;
bool V_197 ;
if ( V_2 -> V_29 & V_36 )
F_95 ( V_17 , true ) ;
V_197 = F_85 ( & V_17 -> V_140 , V_196 ,
V_198 | ( V_17 -> V_162 << 8 ) ) < 0 ;
if ( V_2 -> V_29 & V_36 )
F_95 ( V_17 , false ) ;
if ( V_197 || ( V_196 [ 0 ] & V_2 -> V_4 ) != V_2 -> V_5 )
return - 1 ;
if ( ( V_17 -> V_199 & 0xc8 ) == 0x08 ) {
if ( F_85 ( & V_17 -> V_140 , V_196 , V_198 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_17 -> V_19 , V_196 , sizeof( V_196 ) ) ;
return 0 ;
}
static int F_105 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( ( V_2 -> V_29 & V_36 ) &&
F_95 ( V_17 , true ) ) {
return - 1 ;
}
if ( F_103 ( V_17 , true ) ) {
F_24 ( V_17 , L_16 ) ;
return - 1 ;
}
if ( F_97 ( V_17 ) ) {
F_63 ( V_17 , L_17 ) ;
return - 1 ;
}
if ( ( V_2 -> V_29 & V_36 ) &&
F_95 ( V_17 , false ) ) {
return - 1 ;
}
if ( F_85 ( & V_17 -> V_140 , NULL , V_182 ) ) {
F_63 ( V_17 , L_18 ) ;
return - 1 ;
}
return 0 ;
}
static int F_106 ( struct V_17 * V_17 )
{
unsigned char V_171 [ 2 ] = { 0xC8 , 0x14 } ;
if ( F_95 ( V_17 , true ) )
return - 1 ;
if ( F_85 ( & V_17 -> V_140 , NULL , V_186 ) ||
F_85 ( & V_17 -> V_140 , NULL , V_186 ) ||
F_85 ( & V_17 -> V_140 , NULL , V_186 ) ||
F_85 ( & V_17 -> V_140 , & V_171 [ 0 ] , V_193 ) ||
F_85 ( & V_17 -> V_140 , & V_171 [ 1 ] , V_193 ) )
return - 1 ;
if ( F_95 ( V_17 , false ) )
return - 1 ;
if ( F_101 ( V_17 ) ) {
F_63 ( V_17 , L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_107 ( struct V_17 * V_17 ,
int V_200 , bool V_183 )
{
int V_191 , V_192 = - 1 ;
if ( F_93 ( V_17 ) )
return - 1 ;
V_191 = F_88 ( V_17 , V_200 + 0x0008 ) ;
if ( V_191 == - 1 )
goto error;
if ( V_183 )
V_191 |= 0x01 ;
else
V_191 &= ~ 0x01 ;
V_192 = F_89 ( V_17 , V_191 ) ;
error:
if ( F_94 ( V_17 ) )
V_192 = - 1 ;
return V_192 ;
}
static int F_108 ( struct V_17 * V_17 )
{
int V_191 ;
V_191 = F_88 ( V_17 , 0x0004 ) ;
if ( V_191 == - 1 )
return - 1 ;
V_191 |= 0x06 ;
if ( F_89 ( V_17 , V_191 ) )
return - 1 ;
return 0 ;
}
static int F_109 ( struct V_17 * V_17 , int V_200 )
{
int V_192 = - V_180 , V_191 ;
if ( F_93 ( V_17 ) )
goto error;
V_191 = F_88 ( V_17 , V_200 + 0x08 ) ;
if ( V_191 == - 1 )
goto error;
V_192 = V_191 & 0x80 ? 0 : - V_201 ;
error:
F_94 ( V_17 ) ;
return V_192 ;
}
static int F_110 ( struct V_17 * V_17 , int V_200 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_192 = 0 ;
unsigned char V_171 [ 4 ] ;
if ( F_107 ( V_17 , V_200 , true ) )
return - V_180 ;
if ( F_91 ( V_17 , 0 , V_185 , V_171 ) ) {
F_24 ( V_17 , L_19 ) ;
V_192 = - V_201 ;
} else {
F_25 ( V_17 , L_20 , V_171 ) ;
if ( F_85 ( V_140 , NULL , V_186 ) ||
F_85 ( V_140 , NULL , V_186 ) ||
F_85 ( V_140 , NULL , V_186 ) ||
F_83 ( V_17 , 0x9 ) ||
F_83 ( V_17 , 0x4 ) ) {
F_63 ( V_17 ,
L_21 ) ;
V_192 = - V_180 ;
goto error;
}
if ( F_93 ( V_17 ) ||
F_90 ( V_17 ,
V_200 + 0x08 , 0x82 ) ||
F_94 ( V_17 ) )
V_192 = - V_180 ;
}
error:
if ( F_107 ( V_17 , V_200 , false ) )
V_192 = - V_180 ;
return V_192 ;
}
static int F_111 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_191 ;
unsigned char V_171 [ 4 ] ;
V_191 = F_109 ( V_17 , V_202 ) ;
if ( V_191 == - V_180 )
goto error;
if ( V_191 == 0 &&
F_110 ( V_17 , V_202 ) == - V_180 )
goto error;
if ( F_93 ( V_17 ) ||
F_108 ( V_17 ) ) {
F_63 ( V_17 , L_22 ) ;
goto error;
}
V_191 = F_88 ( V_17 , 0x0006 ) ;
if ( V_191 == - 1 )
goto error;
if ( F_89 ( V_17 , V_191 | 0x01 ) )
goto error;
V_191 = F_88 ( V_17 , 0x0007 ) ;
if ( V_191 == - 1 )
goto error;
if ( F_89 ( V_17 , V_191 | 0x01 ) )
goto error;
if ( F_88 ( V_17 , 0x0144 ) == - 1 )
goto error;
if ( F_89 ( V_17 , 0x04 ) )
goto error;
if ( F_88 ( V_17 , 0x0159 ) == - 1 )
goto error;
if ( F_89 ( V_17 , 0x03 ) )
goto error;
if ( F_88 ( V_17 , 0x0163 ) == - 1 )
goto error;
if ( F_90 ( V_17 , 0x0163 , 0x03 ) )
goto error;
if ( F_88 ( V_17 , 0x0162 ) == - 1 )
goto error;
if ( F_90 ( V_17 , 0x0162 , 0x04 ) )
goto error;
F_94 ( V_17 ) ;
V_171 [ 0 ] = 0x64 ;
if ( F_85 ( V_140 , V_171 , V_193 ) ||
F_85 ( V_140 , NULL , V_188 ) ) {
F_63 ( V_17 , L_23 ) ;
return - 1 ;
}
return 0 ;
error:
F_94 ( V_17 ) ;
return - 1 ;
}
static int F_112 ( struct V_17 * V_17 , int V_203 )
{
int V_204 , V_205 , V_206 , V_207 , V_208 , V_209 , V_210 ;
struct V_1 * V_2 = V_17 -> V_18 ;
V_204 = F_88 ( V_17 , V_203 ) ;
if ( V_204 < 0 )
return V_204 ;
V_205 = ( char ) ( V_204 << 4 ) >> 4 ;
V_205 = 50 + 2 * V_205 ;
V_206 = ( char ) V_204 >> 4 ;
V_206 = 36 + 2 * V_206 ;
V_204 = F_88 ( V_17 , V_203 + 1 ) ;
if ( V_204 < 0 )
return V_204 ;
V_207 = ( char ) ( V_204 << 4 ) >> 4 ;
V_207 = 17 + V_207 ;
V_208 = ( char ) V_204 >> 4 ;
V_208 = 13 + V_208 ;
V_209 = V_205 * ( V_207 - 1 ) ;
V_210 = V_206 * ( V_208 - 1 ) ;
V_2 -> V_211 = V_2 -> V_67 * 10 / V_209 ;
V_2 -> V_212 = V_2 -> V_68 * 10 / V_210 ;
F_25 ( V_17 ,
L_24 ,
V_205 , V_206 , V_207 , V_208 ,
V_209 / 10 , V_210 / 10 , V_2 -> V_211 , V_2 -> V_212 ) ;
return 0 ;
}
static int F_113 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_191 , V_192 = - 1 ;
if ( V_2 -> V_29 & V_32 ) {
V_191 = F_110 ( V_17 ,
V_213 ) ;
if ( V_191 == - V_180 )
goto error;
}
if ( F_93 ( V_17 ) ||
F_88 ( V_17 , 0xc2d9 ) == - 1 ||
F_90 ( V_17 , 0xc2cb , 0x00 ) )
goto error;
if ( F_112 ( V_17 , 0xc2da ) )
goto error;
V_191 = F_88 ( V_17 , 0xc2c6 ) ;
if ( V_191 == - 1 )
goto error;
if ( F_89 ( V_17 , V_191 & 0xfd ) )
goto error;
if ( F_90 ( V_17 , 0xc2c9 , 0x64 ) )
goto error;
V_191 = F_88 ( V_17 , 0xc2c4 ) ;
if ( V_191 == - 1 )
goto error;
if ( F_89 ( V_17 , V_191 | 0x02 ) )
goto error;
F_94 ( V_17 ) ;
return F_85 ( V_140 , NULL , V_188 ) ;
error:
F_94 ( V_17 ) ;
return V_192 ;
}
static int F_114 ( struct V_17 * V_17 )
{
int V_191 ;
V_191 = F_88 ( V_17 , 0x0004 ) ;
if ( V_191 == - 1 )
return - 1 ;
V_191 |= 0x02 ;
if ( F_89 ( V_17 , V_191 ) )
return - 1 ;
return 0 ;
}
static int F_115 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_171 [ 4 ] ;
if ( F_93 ( V_17 ) )
goto error;
if ( F_114 ( V_17 ) ) {
F_63 ( V_17 , L_22 ) ;
goto error;
}
if ( F_90 ( V_17 , 0x0007 , 0x8c ) )
goto error;
if ( F_90 ( V_17 , 0x0149 , 0x03 ) )
goto error;
if ( F_90 ( V_17 , 0x0160 , 0x03 ) )
goto error;
if ( F_90 ( V_17 , 0x017f , 0x15 ) )
goto error;
if ( F_90 ( V_17 , 0x0151 , 0x01 ) )
goto error;
if ( F_90 ( V_17 , 0x0168 , 0x03 ) )
goto error;
if ( F_90 ( V_17 , 0x014a , 0x03 ) )
goto error;
if ( F_90 ( V_17 , 0x0161 , 0x03 ) )
goto error;
F_94 ( V_17 ) ;
V_171 [ 0 ] = 0xc8 ;
V_171 [ 1 ] = 0x64 ;
V_171 [ 2 ] = 0x50 ;
if ( F_85 ( V_140 , & V_171 [ 0 ] , V_193 ) ||
F_85 ( V_140 , & V_171 [ 1 ] , V_193 ) ||
F_85 ( V_140 , & V_171 [ 2 ] , V_193 ) ||
F_85 ( V_140 , V_171 , V_214 ) )
return - 1 ;
V_171 [ 0 ] = 0x64 ;
if ( F_85 ( V_140 , V_171 , V_193 ) ||
F_85 ( V_140 , NULL , V_188 ) ) {
F_63 ( V_17 , L_23 ) ;
return - 1 ;
}
return 0 ;
error:
F_94 ( V_17 ) ;
return - 1 ;
}
static int F_116 ( struct V_17 * V_17 ,
unsigned char V_215 , unsigned char V_216 [] )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
switch ( V_215 ) {
case 0 :
if ( F_85 ( V_140 , NULL , V_182 ) ||
F_85 ( V_140 , NULL , V_182 ) ||
F_85 ( V_140 , V_216 , V_176 ) )
return - 1 ;
break;
case 1 :
if ( F_85 ( V_140 , NULL , V_189 ) ||
F_85 ( V_140 , NULL , V_189 ) ||
F_85 ( V_140 , V_216 , V_176 ) )
return - 1 ;
break;
}
return 0 ;
}
static int F_117 ( unsigned char V_216 [] [ 4 ] ,
struct V_1 * V_2 )
{
int V_217 ;
int V_218 ;
int V_205 , V_206 , V_209 , V_210 ;
V_217 = V_219 + ( V_216 [ 1 ] [ 0 ] & 0x0F ) ;
V_218 = V_220 + ( ( V_216 [ 1 ] [ 0 ] >> 4 ) & 0x0F ) ;
V_2 -> V_67 = ( V_217 - 1 ) * V_221 ;
V_2 -> V_68 = ( V_218 - 1 ) * V_221 ;
V_205 = ( ( V_216 [ 1 ] [ 2 ] >> 2 ) & 0x07 ) + V_222 ;
V_206 = ( ( V_216 [ 1 ] [ 2 ] >> 5 ) & 0x07 ) + V_222 ;
V_209 = V_205 * ( V_217 - 1 ) ;
V_210 = V_206 * ( V_218 - 1 ) ;
V_2 -> V_211 = V_2 -> V_67 * 10 / V_209 ;
V_2 -> V_212 = V_2 -> V_68 * 10 / V_210 ;
return 0 ;
}
static int F_118 ( unsigned char V_216 [] [ 4 ] ,
struct V_1 * V_2 )
{
unsigned char V_223 ;
V_223 = ( V_216 [ 1 ] [ 1 ] >> 3 ) & 0x01 ;
if ( V_223 )
V_2 -> V_29 |= V_121 ;
return 0 ;
}
static int F_119 ( struct V_17 * V_17 ,
struct V_1 * V_2 )
{
unsigned char V_216 [ 2 ] [ 4 ] ;
memset ( V_216 , 0 , sizeof( V_216 ) ) ;
if ( F_116 ( V_17 , 0 , & V_216 [ 0 ] [ 0 ] ) ||
F_116 ( V_17 , 1 , & V_216 [ 1 ] [ 0 ] ) )
return - 1 ;
F_117 ( V_216 , V_2 ) ;
F_118 ( V_216 , V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_17 * V_17 ,
struct V_1 * V_2 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_171 [ 4 ] = { 0 } ;
int V_217 , V_218 ;
if ( F_93 ( V_17 ) )
return - 1 ;
V_171 [ 0 ] = 0x0a ;
if ( F_85 ( V_140 , NULL , V_181 ) ||
F_85 ( V_140 , NULL , V_189 ) ||
F_85 ( V_140 , NULL , V_189 ) ||
F_85 ( V_140 , & V_171 [ 0 ] , V_193 ) ||
F_85 ( V_140 , & V_171 [ 0 ] , V_193 ) )
return - 1 ;
if ( F_85 ( V_140 , V_171 , V_176 ) )
return - 1 ;
V_217 = V_224 + ( V_171 [ 2 ] & 0x0F ) ;
V_218 = V_225 + ( ( V_171 [ 2 ] >> 4 ) & 0x0F ) ;
V_2 -> V_64 = V_217 ;
V_2 -> V_65 = V_218 ;
V_2 -> V_67 = ( V_217 - 1 ) * V_226 ;
V_2 -> V_68 = ( V_218 - 1 ) * V_226 ;
if ( F_94 ( V_17 ) )
return - 1 ;
return 0 ;
}
static int F_121 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_171 [ 2 ] ;
V_171 [ 0 ] = 0x64 ;
V_171 [ 1 ] = 0x28 ;
if ( F_85 ( V_140 , NULL , V_182 ) ||
F_85 ( V_140 , & V_171 [ 0 ] , V_193 ) ||
F_85 ( V_140 , & V_171 [ 1 ] , V_193 ) )
return - 1 ;
return 0 ;
}
static int F_122 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_191 , V_192 = - 1 ;
if ( F_93 ( V_17 ) ||
F_88 ( V_17 , 0xc2d9 ) == - 1 )
goto error;
if ( F_112 ( V_17 , 0xc397 ) )
goto error;
if ( F_90 ( V_17 , 0xc2c9 , 0x64 ) )
goto error;
V_191 = F_88 ( V_17 , 0xc2c4 ) ;
if ( V_191 == - 1 )
goto error;
if ( F_89 ( V_17 , V_191 | 0x02 ) )
goto error;
F_94 ( V_17 ) ;
return F_85 ( V_140 , NULL , V_188 ) ;
error:
F_94 ( V_17 ) ;
return V_192 ;
}
static int F_123 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
char V_171 [ 2 ] = { 0x64 , 0x28 } ;
int V_192 = - 1 ;
if ( F_85 ( V_140 , NULL , V_182 ) ||
F_85 ( V_140 , NULL , V_182 ) ||
F_85 ( V_140 , & V_171 [ 0 ] , V_193 ) ||
F_85 ( V_140 , & V_171 [ 1 ] , V_193 ) ) {
goto error;
}
if ( F_94 ( V_17 ) ||
F_93 ( V_17 ) ||
F_90 ( V_17 , 0x001D , 0x20 ) ) {
goto error;
}
F_94 ( V_17 ) ;
return F_85 ( V_140 , NULL , V_188 ) ;
error:
F_94 ( V_17 ) ;
return V_192 ;
}
static int F_124 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_227 * V_228 )
{
V_17 -> V_18 = V_2 ;
F_125 ( & V_2 -> V_158 , F_79 , ( unsigned long ) V_17 ) ;
V_2 -> V_27 = V_228 -> V_150 ;
V_2 -> V_5 = V_228 -> V_5 ;
V_2 -> V_4 = V_228 -> V_4 ;
V_2 -> V_29 = V_228 -> V_29 ;
V_2 -> V_67 = 2000 ;
V_2 -> V_68 = 1400 ;
V_2 -> V_64 = 15 ;
V_2 -> V_65 = 11 ;
switch ( V_2 -> V_27 ) {
case V_28 :
case V_35 :
V_2 -> V_229 = F_105 ;
V_2 -> V_161 = F_6 ;
V_2 -> V_230 = V_231 ;
V_2 -> V_67 = 1023 ;
V_2 -> V_68 = 767 ;
break;
case V_107 :
V_2 -> V_229 = F_111 ;
V_2 -> V_161 = F_32 ;
V_2 -> V_230 = V_232 ;
V_2 -> V_105 = F_27 ;
V_2 -> V_173 = V_233 ;
V_2 -> V_175 = V_181 ;
break;
case V_86 :
V_2 -> V_229 = F_113 ;
V_2 -> V_161 = F_32 ;
V_2 -> V_230 = V_232 ;
V_2 -> V_105 = F_28 ;
V_2 -> V_173 = V_233 ;
V_2 -> V_175 = V_181 ;
V_2 -> V_64 = 16 ;
V_2 -> V_65 = 12 ;
if ( F_109 ( V_17 ,
V_213 ) < 0 )
V_2 -> V_29 &= ~ V_32 ;
break;
case V_234 :
V_2 -> V_229 = F_115 ;
V_2 -> V_161 = F_34 ;
V_2 -> V_230 = V_232 ;
V_2 -> V_173 = V_235 ;
V_2 -> V_175 = V_187 ;
break;
case V_167 :
V_2 -> V_229 = F_121 ;
V_2 -> V_161 = F_31 ;
V_2 -> V_105 = F_29 ;
V_2 -> V_230 = V_232 ;
V_2 -> V_173 = V_233 ;
V_2 -> V_175 = V_181 ;
V_2 -> V_64 = 23 ;
V_2 -> V_65 = 12 ;
if ( F_120 ( V_17 , V_2 ) )
return - V_180 ;
break;
case V_236 :
V_2 -> V_229 = F_106 ;
V_2 -> V_161 = F_33 ;
V_2 -> V_230 = V_231 ;
V_2 -> V_173 = V_237 ;
V_2 -> V_67 = 2047 ;
V_2 -> V_68 = 1535 ;
break;
case V_168 :
V_2 -> V_229 = F_122 ;
V_2 -> V_161 = F_43 ;
V_2 -> V_105 = F_40 ;
V_2 -> V_230 = V_238 ;
V_2 -> V_173 = V_233 ;
V_2 -> V_175 = V_181 ;
V_2 -> V_67 = 0xfff ;
V_2 -> V_68 = 0x7ff ;
if ( V_2 -> V_239 [ 1 ] != 0xba )
V_2 -> V_29 |= V_121 ;
break;
case V_163 :
V_2 -> V_229 = F_123 ;
V_2 -> V_161 = F_57 ;
V_2 -> V_105 = F_45 ;
V_2 -> V_230 = V_240 ;
V_2 -> V_173 = V_233 ;
V_2 -> V_175 = V_181 ;
if ( F_119 ( V_17 , V_2 ) )
return - V_180 ;
break;
}
return 0 ;
}
static const struct V_227 * F_126 ( unsigned char * V_241 ,
unsigned char * V_242 )
{
const struct V_243 * V_244 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_127 ( V_245 ) ; V_76 ++ ) {
V_244 = & V_245 [ V_76 ] ;
if ( ! memcmp ( V_241 , V_244 -> V_246 , sizeof( V_244 -> V_246 ) ) &&
( ! V_244 -> V_247 ||
V_244 -> V_247 == V_242 [ 2 ] ) ) {
return & V_244 -> V_248 ;
}
}
return NULL ;
}
static int F_128 ( struct V_17 * V_17 , struct V_1 * V_2 )
{
const struct V_227 * V_228 ;
unsigned char V_249 [ 4 ] , V_241 [ 4 ] , V_242 [ 4 ] ;
int error ;
if ( F_91 ( V_17 , V_194 ,
V_186 , V_249 ) )
return - V_180 ;
if ( ( V_249 [ 0 ] & 0xf8 ) != 0 || V_249 [ 1 ] != 0 || ( V_249 [ 2 ] != 10 && V_249 [ 2 ] != 100 ) )
return - V_250 ;
if ( F_91 ( V_17 , V_194 ,
V_185 , V_241 ) ||
F_91 ( V_17 , V_194 ,
V_181 , V_242 ) ||
F_94 ( V_17 ) )
return - V_180 ;
V_228 = F_126 ( V_241 , V_242 ) ;
if ( ! V_228 ) {
if ( V_241 [ 0 ] == 0x73 && V_241 [ 1 ] == 0x03 && V_241 [ 2 ] == 0x50 &&
V_242 [ 0 ] == 0x73 && ( V_242 [ 1 ] == 0x01 || V_242 [ 1 ] == 0x02 ) ) {
V_228 = & V_251 ;
} else if ( V_242 [ 0 ] == 0x88 &&
( ( V_242 [ 1 ] & 0xf0 ) == 0xb0 || ( V_242 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
V_228 = & V_252 ;
} else if ( V_242 [ 0 ] == 0x88 && V_242 [ 1 ] == 0x08 ) {
V_228 = & V_253 ;
} else if ( V_242 [ 0 ] == 0x88 && V_242 [ 1 ] == 0x07 &&
V_242 [ 2 ] >= 0x90 && V_242 [ 2 ] <= 0x9d ) {
V_228 = & V_254 ;
} else if ( V_241 [ 0 ] == 0x73 && V_241 [ 1 ] == 0x03 &&
V_241 [ 2 ] == 0x14 && V_242 [ 1 ] == 0x02 ) {
V_228 = & V_255 ;
} else {
F_25 ( V_17 ,
L_25 , V_241 , V_242 ) ;
return - V_250 ;
}
}
if ( V_2 ) {
memcpy ( V_2 -> V_239 , V_242 , 3 ) ;
error = F_124 ( V_17 , V_2 , V_228 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_129 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_130 ( V_17 ) ;
if ( F_128 ( V_17 , V_2 ) < 0 )
return - 1 ;
return V_2 -> V_229 ( V_17 ) ;
}
static void F_131 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_130 ( V_17 ) ;
F_132 ( & V_2 -> V_158 ) ;
if ( V_2 -> V_8 )
F_133 ( V_2 -> V_8 ) ;
if ( ! F_72 ( V_2 -> V_135 ) )
F_133 ( V_2 -> V_135 ) ;
F_134 ( V_2 ) ;
}
static void V_231 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_135 ( V_7 , V_38 , 0 , V_2 -> V_67 , 0 , 0 ) ;
F_135 ( V_7 , V_39 , 0 , V_2 -> V_68 , 0 , 0 ) ;
F_135 ( V_7 , V_40 , 0 , 127 , 0 , 0 ) ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_135 ( V_7 , V_89 , 0 , V_2 -> V_67 , 0 , 0 ) ;
F_135 ( V_7 , V_90 , 0 , V_2 -> V_68 , 0 , 0 ) ;
F_137 ( V_7 , V_89 , V_2 -> V_211 ) ;
F_137 ( V_7 , V_90 , V_2 -> V_212 ) ;
F_138 ( V_256 , V_7 -> V_257 ) ;
F_138 ( V_258 , V_7 -> V_257 ) ;
}
static void V_232 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_136 ( V_2 , V_7 ) ;
F_135 ( V_7 , V_40 , 0 , 127 , 0 , 0 ) ;
F_139 ( V_7 , V_93 ,
V_259 | V_260 |
V_261 | V_262 ) ;
}
static void V_238 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_136 ( V_2 , V_7 ) ;
F_138 ( V_263 , V_7 -> V_257 ) ;
F_139 ( V_7 , V_93 ,
V_259 | V_260 |
V_261 ) ;
F_138 ( V_263 , V_7 -> V_257 ) ;
}
static void V_240 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_136 ( V_2 , V_7 ) ;
F_135 ( V_7 , V_40 , 0 , 127 , 0 , 0 ) ;
F_138 ( V_263 , V_7 -> V_257 ) ;
F_139 ( V_7 , V_93 ,
V_259 | V_260 |
V_261 ) ;
}
int F_140 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_7 = V_17 -> V_12 ;
int error ;
error = V_2 -> V_229 ( V_17 ) ;
if ( error )
goto V_264;
F_141 ( V_152 , V_7 -> V_265 ) ;
F_141 ( V_33 , V_7 -> V_266 ) ;
F_141 ( V_34 , V_7 -> V_266 ) ;
V_7 -> V_265 [ F_142 ( V_153 ) ] |= F_143 ( V_153 ) ;
V_7 -> V_257 [ F_142 ( V_42 ) ] |= F_143 ( V_42 ) ;
V_7 -> V_257 [ F_142 ( V_41 ) ] |= F_143 ( V_41 ) ;
V_7 -> V_257 [ F_142 ( V_13 ) ] |=
F_143 ( V_13 ) | F_143 ( V_15 ) ;
V_7 -> V_265 [ F_142 ( V_267 ) ] |= F_143 ( V_267 ) ;
V_2 -> V_230 ( V_2 , V_7 ) ;
if ( V_2 -> V_29 & V_43 ) {
V_7 -> V_265 [ F_142 ( V_152 ) ] |= F_143 ( V_152 ) ;
V_7 -> V_266 [ F_142 ( V_44 ) ] |= F_143 ( V_44 ) ;
}
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
V_7 -> V_257 [ F_142 ( V_45 ) ] |= F_143 ( V_45 ) ;
V_7 -> V_257 [ F_142 ( V_46 ) ] |= F_143 ( V_46 ) ;
}
if ( V_2 -> V_29 & V_47 ) {
V_7 -> V_257 [ F_142 ( V_48 ) ] |= F_143 ( V_48 ) ;
V_7 -> V_257 [ F_142 ( V_49 ) ] |= F_143 ( V_49 ) ;
V_7 -> V_257 [ F_142 ( V_50 ) ] |= F_143 ( V_50 ) ;
V_7 -> V_257 [ F_142 ( V_51 ) ] |= F_143 ( V_51 ) ;
} else if ( V_2 -> V_29 & V_121 ) {
F_138 ( V_268 , V_7 -> V_155 ) ;
F_144 ( V_15 , V_7 -> V_257 ) ;
} else {
V_7 -> V_257 [ F_142 ( V_16 ) ] |= F_143 ( V_16 ) ;
}
if ( V_2 -> V_29 & V_32 ) {
struct V_6 * V_8 ;
V_8 = F_62 () ;
if ( ! V_8 ) {
F_63 ( V_17 ,
L_26 ) ;
error = - V_138 ;
goto V_264;
}
snprintf ( V_2 -> V_269 , sizeof( V_2 -> V_269 ) , L_27 ,
V_17 -> V_140 . V_141 -> V_142 ) ;
V_8 -> V_142 = V_2 -> V_269 ;
V_8 -> V_143 = L_28 ;
V_8 -> V_144 . V_145 = V_146 ;
V_8 -> V_144 . V_147 = 0x0002 ;
V_8 -> V_144 . V_148 = V_270 ;
V_8 -> V_144 . V_150 = V_2 -> V_27 ;
V_8 -> V_12 . V_151 = & V_17 -> V_140 . V_141 -> V_12 ;
F_64 ( V_8 , V_152 , V_33 ) ;
F_64 ( V_8 , V_152 , V_34 ) ;
F_64 ( V_8 , V_153 , V_13 ) ;
F_64 ( V_8 , V_153 , V_15 ) ;
F_64 ( V_8 , V_153 , V_16 ) ;
F_65 ( V_154 , V_8 -> V_155 ) ;
F_65 ( V_271 , V_8 -> V_155 ) ;
error = F_66 ( V_8 ) ;
if ( error ) {
F_63 ( V_17 ,
L_29 ,
error ) ;
F_67 ( V_8 ) ;
goto V_264;
}
V_2 -> V_8 = V_8 ;
}
V_2 -> V_17 = V_17 ;
F_145 ( & V_2 -> V_134 ,
F_59 ) ;
V_17 -> V_272 = F_82 ;
V_17 -> V_273 = F_104 ;
V_17 -> V_274 = F_131 ;
V_17 -> V_275 = F_129 ;
V_17 -> V_162 = V_2 -> V_27 == V_234 ? 8 : 6 ;
V_17 -> V_276 = 0 ;
V_17 -> V_277 = V_17 -> V_162 * 2 ;
return 0 ;
V_264:
F_130 ( V_17 ) ;
F_134 ( V_17 -> V_18 ) ;
V_17 -> V_18 = NULL ;
return error ;
}
int F_146 ( struct V_17 * V_17 , bool V_278 )
{
struct V_1 * V_2 ;
int error ;
error = F_128 ( V_17 , NULL ) ;
if ( error )
return error ;
F_130 ( V_17 ) ;
V_2 = F_147 ( sizeof( struct V_1 ) , V_279 ) ;
if ( ! V_2 )
return - V_138 ;
error = F_128 ( V_17 , V_2 ) ;
if ( error ) {
F_134 ( V_2 ) ;
return error ;
}
if ( V_278 ) {
V_17 -> V_147 = L_30 ;
V_17 -> V_143 = V_2 -> V_29 & V_32 ?
L_31 : L_32 ;
V_17 -> V_244 = V_2 -> V_27 ;
} else {
F_134 ( V_2 ) ;
V_17 -> V_18 = NULL ;
}
return 0 ;
}
