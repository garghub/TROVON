static bool F_1 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
return ( V_3 & V_2 -> V_4 ) == V_2 -> V_5 ;
}
static void F_2 ( struct V_6 * V_6 ,
struct V_7 * V_8 , struct V_7 * V_9 ,
int V_10 , int V_11 , int V_12 )
{
struct V_7 * V_13 ;
V_13 = F_3 ( V_14 , V_9 -> V_15 ) ? V_9 : V_8 ;
F_4 ( V_13 , V_14 , V_10 ) ;
V_13 = F_3 ( V_16 , V_9 -> V_15 ) ? V_9 : V_8 ;
F_4 ( V_13 , V_16 , V_11 ) ;
V_13 = F_3 ( V_17 , V_9 -> V_15 ) ? V_9 : V_8 ;
F_4 ( V_13 , V_17 , V_12 ) ;
F_5 ( V_9 ) ;
}
static void F_6 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_2 -> V_9 ;
int V_20 , V_21 , V_22 , V_23 , V_24 , V_10 , V_11 , V_12 ;
int V_25 = 0 , V_26 = 0 ;
if ( V_2 -> V_27 == V_28 ) {
V_10 = V_19 [ 2 ] & 0x10 ;
V_11 = V_19 [ 2 ] & 0x08 ;
V_12 = 0 ;
V_20 = V_19 [ 1 ] | ( ( V_19 [ 0 ] & 0x07 ) << 7 ) ;
V_21 = V_19 [ 4 ] | ( ( V_19 [ 3 ] & 0x07 ) << 7 ) ;
V_22 = V_19 [ 5 ] ;
} else {
V_10 = V_19 [ 3 ] & 1 ;
V_11 = V_19 [ 3 ] & 2 ;
V_12 = V_19 [ 3 ] & 4 ;
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
if ( ( V_12 = V_26 && V_25 ) )
V_26 = V_25 = 0 ;
}
V_23 = V_19 [ 2 ] & 1 ;
V_24 = V_19 [ 2 ] & 2 ;
if ( ( V_2 -> V_29 & V_32 ) && V_22 == 127 ) {
F_7 ( V_9 , V_33 , ( V_20 > 383 ? ( V_20 - 768 ) : V_20 ) ) ;
F_7 ( V_9 , V_34 , - ( V_21 > 255 ? ( V_21 - 512 ) : V_21 ) ) ;
F_2 ( V_6 , V_9 , V_13 , V_10 , V_11 , V_12 ) ;
F_5 ( V_9 ) ;
return;
}
F_2 ( V_6 , V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_23 && ! V_24 )
V_22 = 40 ;
if ( V_23 && V_24 && ! V_2 -> V_35 ) {
F_8 ( V_13 , V_36 , V_20 ) ;
F_8 ( V_13 , V_37 , V_21 ) ;
F_8 ( V_13 , V_38 , 0 ) ;
F_4 ( V_13 , V_39 , 0 ) ;
F_5 ( V_13 ) ;
}
V_2 -> V_35 = V_24 ;
if ( V_22 > 30 )
F_4 ( V_13 , V_40 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_13 , V_40 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_13 , V_36 , V_20 ) ;
F_8 ( V_13 , V_37 , V_21 ) ;
}
F_8 ( V_13 , V_38 , V_22 ) ;
F_4 ( V_13 , V_39 , V_22 > 0 ) ;
if ( V_2 -> V_29 & V_41 )
F_7 ( V_13 , V_42 , ( ( V_19 [ 2 ] << 1 ) & 0x08 ) - ( ( V_19 [ 0 ] >> 4 ) & 0x07 ) ) ;
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
F_4 ( V_13 , V_43 , V_26 ) ;
F_4 ( V_13 , V_44 , V_25 ) ;
}
if ( V_2 -> V_29 & V_45 ) {
F_4 ( V_13 , V_46 , V_19 [ 2 ] & 4 ) ;
F_4 ( V_13 , V_47 , V_19 [ 0 ] & 0x10 ) ;
F_4 ( V_13 , V_48 , V_19 [ 3 ] & 4 ) ;
F_4 ( V_13 , V_49 , V_19 [ 0 ] & 0x20 ) ;
}
F_5 ( V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_50 , unsigned int V_51 ,
int * V_52 , int * y1 , int * V_53 , int * V_54 )
{
struct V_55 {
int V_56 ;
int V_57 ;
};
int V_58 = 0 , V_59 = 0 , V_60 ;
int V_61 , V_62 , V_63 ;
struct V_55 V_64 = { 0 ,} , V_65 = { 0 ,} ;
struct V_55 V_66 = { 0 ,} , V_67 = { 0 ,} ;
struct V_55 * V_68 ;
if ( ! V_50 || ! V_51 )
return 0 ;
* V_52 = * y1 = * V_53 = * V_54 = 0 ;
V_63 = 0 ;
V_68 = & V_64 ;
for ( V_61 = 0 ; V_50 != 0 ; V_61 ++ , V_50 >>= 1 ) {
V_62 = V_50 & 1 ;
if ( V_62 ) {
if ( ! V_63 ) {
V_68 -> V_56 = V_61 ;
V_58 ++ ;
}
V_68 -> V_57 ++ ;
} else {
if ( V_63 )
V_68 = & V_65 ;
else
V_68 -> V_57 = 0 ;
}
V_63 = V_62 ;
}
V_51 = V_51 << ( sizeof( V_51 ) * V_69 - V_2 -> V_70 ) ;
V_63 = 0 ;
V_68 = & V_66 ;
for ( V_61 = 0 ; V_51 != 0 ; V_61 ++ , V_51 <<= 1 ) {
V_62 = V_51 & ( 1 << ( sizeof( V_51 ) * V_69 - 1 ) ) ;
if ( V_62 ) {
if ( ! V_63 ) {
V_68 -> V_56 = V_61 ;
V_59 ++ ;
}
V_68 -> V_57 ++ ;
} else {
if ( V_63 )
V_68 = & V_67 ;
else
V_68 -> V_57 = 0 ;
}
V_63 = V_62 ;
}
V_60 = F_10 ( V_58 , V_59 ) ;
if ( V_60 > 1 ) {
if ( V_58 == 1 ) {
V_61 = V_64 . V_57 / 2 ;
V_64 . V_57 = V_64 . V_57 - V_61 ;
V_65 . V_56 = V_64 . V_56 + V_61 ;
V_65 . V_57 = F_10 ( V_61 , 1 ) ;
} else if ( V_59 == 1 ) {
V_61 = V_66 . V_57 / 2 ;
V_66 . V_57 = V_66 . V_57 - V_61 ;
V_67 . V_56 = V_66 . V_56 + V_61 ;
V_67 . V_57 = F_10 ( V_61 , 1 ) ;
}
}
* V_52 = ( V_2 -> V_71 * ( 2 * V_64 . V_56 + V_64 . V_57 - 1 ) ) /
( 2 * ( V_2 -> V_72 - 1 ) ) ;
* y1 = ( V_2 -> V_73 * ( 2 * V_66 . V_56 + V_66 . V_57 - 1 ) ) /
( 2 * ( V_2 -> V_70 - 1 ) ) ;
if ( V_60 > 1 ) {
* V_53 = ( V_2 -> V_71 *
( 2 * V_65 . V_56 + V_65 . V_57 - 1 ) ) /
( 2 * ( V_2 -> V_72 - 1 ) ) ;
* V_54 = ( V_2 -> V_73 *
( 2 * V_67 . V_56 + V_67 . V_57 - 1 ) ) /
( 2 * ( V_2 -> V_70 - 1 ) ) ;
}
return V_60 ;
}
static void F_11 ( struct V_7 * V_13 , int V_74 , bool V_75 ,
int V_20 , int V_21 )
{
F_12 ( V_13 , V_74 ) ;
F_13 ( V_13 , V_76 , V_75 ) ;
if ( V_75 ) {
F_8 ( V_13 , V_77 , V_20 ) ;
F_8 ( V_13 , V_78 , V_21 ) ;
}
}
static void F_14 ( struct V_7 * V_13 , int V_79 ,
int V_52 , int y1 , int V_53 , int V_54 )
{
F_11 ( V_13 , 0 , V_79 != 0 , V_52 , y1 ) ;
F_11 ( V_13 , 1 , V_79 == 2 , V_53 , V_54 ) ;
}
static void F_15 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_2 -> V_9 ;
int V_20 , V_21 , V_22 , V_10 , V_11 , V_12 ;
if ( ! ( V_19 [ 0 ] & 0x40 ) ) {
F_16 ( V_6 , L_1 ) ;
return;
}
if ( V_19 [ 1 ] == 0x7f && V_19 [ 2 ] == 0x7f && V_19 [ 4 ] == 0x7f )
return;
V_20 = ( V_80 ) ( ( ( V_19 [ 0 ] & 0x20 ) << 2 ) | ( V_19 [ 1 ] & 0x7f ) ) ;
V_21 = ( V_80 ) ( ( ( V_19 [ 0 ] & 0x10 ) << 3 ) | ( V_19 [ 2 ] & 0x7f ) ) ;
V_22 = ( V_19 [ 4 ] & 0x7c ) >> 2 ;
V_20 /= 8 ;
V_21 /= 8 ;
F_7 ( V_13 , V_33 , V_20 ) ;
F_7 ( V_13 , V_34 , - V_21 ) ;
V_10 = V_19 [ 3 ] & 0x01 ;
V_11 = V_19 [ 3 ] & 0x02 ;
V_12 = V_19 [ 3 ] & 0x04 ;
if ( ! ( V_2 -> V_81 & V_82 ) &&
( V_10 || V_11 || V_12 ) )
V_2 -> V_81 |= V_82 ;
if ( V_2 -> V_81 & V_82 ) {
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_4 ( V_13 , V_17 , V_12 ) ;
}
F_5 ( V_13 ) ;
return;
}
static void F_17 ( struct V_83 * V_84 , unsigned char * V_85 )
{
V_84 -> V_10 = ! ! ( V_85 [ 3 ] & 0x01 ) ;
V_84 -> V_11 = ! ! ( V_85 [ 3 ] & 0x02 ) ;
V_84 -> V_12 = ! ! ( V_85 [ 3 ] & 0x04 ) ;
V_84 -> V_86 = ! ! ( V_85 [ 3 ] & 0x10 ) ;
V_84 -> V_87 = ! ! ( V_85 [ 3 ] & 0x20 ) ;
V_84 -> V_88 = ! ! ( V_85 [ 3 ] & 0x40 ) ;
}
static void F_18 ( struct V_83 * V_84 , unsigned char * V_85 )
{
V_84 -> V_89 = ! ! ( V_85 [ 4 ] & 0x40 ) ;
V_84 -> V_90 = ! ! ( V_85 [ 0 ] & 0x40 ) ;
V_84 -> V_60 = ( V_85 [ 5 ] & 0x3 ) + 1 ;
V_84 -> V_50 = ( ( V_85 [ 4 ] & 0x7e ) << 8 ) |
( ( V_85 [ 1 ] & 0x7f ) << 2 ) |
( ( V_85 [ 0 ] & 0x30 ) >> 4 ) ;
V_84 -> V_51 = ( ( V_85 [ 3 ] & 0x70 ) << 4 ) |
( ( V_85 [ 2 ] & 0x7f ) << 1 ) |
( V_85 [ 4 ] & 0x01 ) ;
V_84 -> V_20 = ( ( V_85 [ 1 ] & 0x7f ) << 4 ) | ( ( V_85 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_85 [ 0 ] & 0x30 ) >> 4 ) ;
V_84 -> V_21 = ( ( V_85 [ 2 ] & 0x7f ) << 4 ) | ( V_85 [ 4 ] & 0x0f ) ;
V_84 -> V_22 = V_85 [ 5 ] & 0x7f ;
F_17 ( V_84 , V_85 ) ;
}
static void F_19 ( struct V_83 * V_84 , unsigned char * V_85 )
{
F_18 ( V_84 , V_85 ) ;
V_84 -> V_50 |= ( V_85 [ 5 ] & 0x10 ) << 11 ;
V_84 -> V_51 |= ( V_85 [ 5 ] & 0x20 ) << 6 ;
}
static void F_20 ( struct V_83 * V_84 , unsigned char * V_85 )
{
V_84 -> V_89 = ! ! ( V_85 [ 0 ] & 0x02 ) ;
V_84 -> V_90 = ! ! ( V_85 [ 0 ] & 0x20 ) ;
V_84 -> V_60 = ( ( V_85 [ 0 ] & 0x6 ) >> 1 |
( V_85 [ 0 ] & 0x10 ) >> 2 ) ;
V_84 -> V_50 = ( ( V_85 [ 2 ] & 0x60 ) >> 5 ) |
( ( V_85 [ 4 ] & 0x7f ) << 2 ) |
( ( V_85 [ 5 ] & 0x7f ) << 9 ) |
( ( V_85 [ 3 ] & 0x07 ) << 16 ) |
( ( V_85 [ 3 ] & 0x70 ) << 15 ) |
( ( V_85 [ 0 ] & 0x01 ) << 22 ) ;
V_84 -> V_51 = ( V_85 [ 1 ] & 0x7f ) |
( ( V_85 [ 2 ] & 0x1f ) << 7 ) ;
V_84 -> V_20 = ( ( V_85 [ 1 ] & 0x7f ) | ( ( V_85 [ 4 ] & 0x0f ) << 7 ) ) ;
V_84 -> V_21 = ( ( V_85 [ 2 ] & 0x7f ) | ( ( V_85 [ 4 ] & 0xf0 ) << 3 ) ) ;
V_84 -> V_22 = ( V_85 [ 0 ] & 4 ) ? 0 : V_85 [ 5 ] & 0x7f ;
F_17 ( V_84 , V_85 ) ;
}
static void F_21 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_2 -> V_9 ;
int V_52 = 0 , y1 = 0 , V_53 = 0 , V_54 = 0 ;
int V_60 = 0 , V_91 ;
struct V_83 V_84 ;
V_2 -> V_92 ( & V_84 , V_19 ) ;
if ( V_2 -> V_93 ) {
if ( V_84 . V_90 ) {
V_60 = V_84 . V_60 ;
V_91 = F_9 ( V_2 ,
V_84 . V_50 , V_84 . V_51 ,
& V_52 , & y1 , & V_53 , & V_54 ) ;
if ( V_60 > 1 && V_91 < 2 )
V_60 = V_91 ;
V_2 -> V_92 ( & V_84 , V_2 -> V_94 ) ;
} else {
V_2 -> V_93 = 0 ;
}
}
if ( V_84 . V_90 )
return;
if ( ! V_2 -> V_93 && V_84 . V_89 ) {
V_2 -> V_93 = 1 ;
memcpy ( V_2 -> V_94 , V_19 , sizeof( V_2 -> V_94 ) ) ;
return;
}
V_2 -> V_93 = 0 ;
if ( V_84 . V_20 && V_84 . V_21 && ! V_84 . V_22 )
return;
if ( ! V_60 ) {
V_52 = V_84 . V_20 ;
y1 = V_84 . V_21 ;
V_60 = V_84 . V_22 > 0 ? 1 : 0 ;
}
if ( V_84 . V_22 >= 64 )
F_4 ( V_13 , V_40 , 1 ) ;
else
F_4 ( V_13 , V_40 , 0 ) ;
F_14 ( V_13 , V_60 , V_52 , y1 , V_53 , V_54 ) ;
F_22 ( V_13 , V_60 ) ;
F_4 ( V_13 , V_14 , V_84 . V_10 ) ;
F_4 ( V_13 , V_16 , V_84 . V_11 ) ;
F_4 ( V_13 , V_17 , V_84 . V_12 ) ;
if ( V_84 . V_22 > 0 ) {
F_8 ( V_13 , V_36 , V_84 . V_20 ) ;
F_8 ( V_13 , V_37 , V_84 . V_21 ) ;
}
F_8 ( V_13 , V_38 , V_84 . V_22 ) ;
F_5 ( V_13 ) ;
if ( ! ( V_2 -> V_81 & V_82 ) ) {
F_4 ( V_9 , V_14 , V_84 . V_86 ) ;
F_4 ( V_9 , V_16 , V_84 . V_87 ) ;
F_4 ( V_9 , V_17 , V_84 . V_88 ) ;
F_5 ( V_9 ) ;
}
}
static void F_23 ( struct V_6 * V_6 )
{
unsigned char * V_19 = V_6 -> V_19 ;
if ( V_19 [ 5 ] == 0x3f ) {
F_15 ( V_6 ) ;
return;
}
F_21 ( V_6 ) ;
}
static void F_24 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_6 -> V_13 ;
int V_95 ;
int V_20 , V_21 , V_22 ;
int V_10 , V_11 ;
int V_52 , y1 , V_53 , V_54 ;
int V_60 = 0 ;
unsigned int V_96 , V_97 ;
if ( V_19 [ 6 ] & 0x40 ) {
V_2 -> V_93 = 0 ;
}
if ( F_25 ( V_2 -> V_93 > 2 ) )
return;
V_95 = 2 * V_2 -> V_93 ;
V_2 -> V_94 [ V_95 ] = V_19 [ 6 ] ;
V_2 -> V_94 [ V_95 + 1 ] = V_19 [ 7 ] ;
if ( ++ V_2 -> V_93 > 2 ) {
V_2 -> V_93 = 0 ;
V_96 = ( ( V_2 -> V_94 [ 2 ] & 0x1f ) << 10 ) |
( ( V_2 -> V_94 [ 3 ] & 0x60 ) << 3 ) |
( ( V_2 -> V_94 [ 0 ] & 0x3f ) << 2 ) |
( ( V_2 -> V_94 [ 1 ] & 0x60 ) >> 5 ) ;
V_97 = ( ( V_2 -> V_94 [ 5 ] & 0x01 ) << 10 ) |
( ( V_2 -> V_94 [ 3 ] & 0x1f ) << 5 ) |
( V_2 -> V_94 [ 1 ] & 0x1f ) ;
V_60 = F_9 ( V_2 , V_96 , V_97 ,
& V_52 , & y1 , & V_53 , & V_54 ) ;
V_2 -> V_60 = V_60 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_53 = V_53 ;
V_2 -> y1 = y1 ;
V_2 -> V_54 = V_54 ;
}
V_10 = V_19 [ 4 ] & 0x01 ;
V_11 = V_19 [ 4 ] & 0x02 ;
V_20 = ( ( V_19 [ 1 ] & 0x7f ) << 4 ) | ( ( V_19 [ 3 ] & 0x30 ) >> 2 ) |
( ( V_19 [ 0 ] & 0x30 ) >> 4 ) ;
V_21 = ( ( V_19 [ 2 ] & 0x7f ) << 4 ) | ( V_19 [ 3 ] & 0x0f ) ;
V_22 = V_19 [ 5 ] & 0x7f ;
if ( V_2 -> V_60 < 2 ) {
V_52 = V_20 ;
y1 = V_21 ;
V_60 = V_22 > 0 ? 1 : 0 ;
} else {
V_60 = V_2 -> V_60 ;
V_52 = V_2 -> V_52 ;
V_53 = V_2 -> V_53 ;
y1 = V_2 -> y1 ;
V_54 = V_2 -> V_54 ;
}
if ( V_22 >= 64 )
F_4 ( V_13 , V_40 , 1 ) ;
else
F_4 ( V_13 , V_40 , 0 ) ;
F_14 ( V_13 , V_60 , V_52 , y1 , V_53 , V_54 ) ;
F_22 ( V_13 , V_60 ) ;
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
if ( V_22 > 0 ) {
F_8 ( V_13 , V_36 , V_20 ) ;
F_8 ( V_13 , V_37 , V_21 ) ;
}
F_8 ( V_13 , V_38 , V_22 ) ;
F_5 ( V_13 ) ;
}
static void F_26 ( struct V_6 * V_6 ,
unsigned char V_19 [] ,
bool V_98 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_7 * V_9 = V_2 -> V_9 ;
if ( V_98 )
F_2 ( V_6 , V_9 , V_6 -> V_13 ,
V_19 [ 0 ] & 1 , V_19 [ 0 ] & 2 , V_19 [ 0 ] & 4 ) ;
F_7 ( V_9 , V_33 ,
V_19 [ 1 ] ? V_19 [ 1 ] - ( ( V_19 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_9 , V_34 ,
V_19 [ 2 ] ? ( ( V_19 [ 0 ] << 3 ) & 0x100 ) - V_19 [ 2 ] : 0 ) ;
F_5 ( V_9 ) ;
}
static T_1 F_27 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( V_6 -> V_99 < 6 )
return V_100 ;
if ( V_6 -> V_99 == 6 ) {
F_28 ( & V_2 -> V_101 , V_102 + F_29 ( 20 ) ) ;
return V_100 ;
}
F_30 ( & V_2 -> V_101 ) ;
if ( V_6 -> V_19 [ 6 ] & 0x80 ) {
if ( ( ( V_6 -> V_19 [ 3 ] |
V_6 -> V_19 [ 4 ] |
V_6 -> V_19 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_2 , V_6 -> V_19 [ 6 ] ) ) ) {
F_16 ( V_6 ,
L_2 ,
V_6 -> V_19 + 3 ) ;
return V_103 ;
}
V_2 -> V_104 ( V_6 ) ;
V_6 -> V_19 [ 0 ] = V_6 -> V_19 [ 6 ] ;
V_6 -> V_99 = 1 ;
} else {
F_26 ( V_6 , & V_6 -> V_19 [ 3 ] ,
false ) ;
V_6 -> V_19 [ 3 ] = V_6 -> V_19 [ 6 ] & 0xf7 ;
V_6 -> V_99 = 4 ;
}
return V_100 ;
}
static void F_31 ( unsigned long V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_1 * V_2 = V_6 -> V_18 ;
F_32 ( V_6 -> V_105 . V_106 ) ;
if ( V_6 -> V_99 == V_6 -> V_107 ) {
if ( ( V_6 -> V_19 [ 3 ] |
V_6 -> V_19 [ 4 ] |
V_6 -> V_19 [ 5 ] ) & 0x80 ) {
F_16 ( V_6 ,
L_3 ,
V_6 -> V_19 + 3 ) ;
} else {
V_2 -> V_104 ( V_6 ) ;
}
V_6 -> V_99 = 0 ;
}
F_33 ( V_6 -> V_105 . V_106 ) ;
}
static T_1 F_34 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( ( V_6 -> V_19 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_6 -> V_99 == 3 ) {
F_26 ( V_6 , V_6 -> V_19 ,
true ) ;
return V_108 ;
}
return V_100 ;
}
if ( ( V_2 -> V_29 & V_109 ) &&
V_6 -> V_99 >= 4 && ( V_6 -> V_19 [ 3 ] & 0x0f ) == 0x0f ) {
return F_27 ( V_6 ) ;
}
if ( ! F_1 ( V_2 , V_6 -> V_19 [ 0 ] ) ) {
F_16 ( V_6 ,
L_4 ,
V_6 -> V_19 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_103 ;
}
if ( V_2 -> V_27 != V_110 &&
V_6 -> V_99 >= 2 && V_6 -> V_99 <= V_6 -> V_107 &&
( V_6 -> V_19 [ V_6 -> V_99 - 1 ] & 0x80 ) ) {
F_16 ( V_6 , L_5 ,
V_6 -> V_99 - 1 ,
V_6 -> V_19 [ V_6 -> V_99 - 1 ] ) ;
return V_103 ;
}
if ( V_6 -> V_99 == V_6 -> V_107 ) {
V_2 -> V_104 ( V_6 ) ;
return V_108 ;
}
return V_100 ;
}
static int F_35 ( struct V_6 * V_6 , int V_111 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
struct V_1 * V_2 = V_6 -> V_18 ;
int V_112 ;
unsigned char * V_113 ;
unsigned char V_114 [ 4 ] ;
F_36 ( V_111 > 0xf ) ;
V_112 = V_2 -> V_115 [ V_111 ] . V_112 ;
V_113 = ( V_112 & 0x0f00 ) ?
V_114 : ( unsigned char * ) & V_2 -> V_115 [ V_111 ] . V_3 ;
if ( F_37 ( V_105 , V_113 , V_112 ) )
return - 1 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_6 , int V_116 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
struct V_1 * V_2 = V_6 -> V_18 ;
int V_61 , V_111 ;
if ( F_37 ( V_105 , NULL , V_2 -> V_117 ) )
return - 1 ;
for ( V_61 = 12 ; V_61 >= 0 ; V_61 -= 4 ) {
V_111 = ( V_116 >> V_61 ) & 0xf ;
if ( F_35 ( V_6 , V_111 ) )
return - 1 ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_6 , int V_116 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
unsigned char V_113 [ 4 ] ;
if ( F_37 ( V_105 , V_113 , V_118 ) )
return - 1 ;
if ( V_116 != ( ( V_113 [ 0 ] << 8 ) | V_113 [ 1 ] ) )
return - 1 ;
return V_113 [ 2 ] ;
}
static int F_40 ( struct V_6 * V_6 , int V_116 )
{
if ( F_38 ( V_6 , V_116 ) )
return - 1 ;
return F_39 ( V_6 , V_116 ) ;
}
static int F_41 ( struct V_6 * V_6 , T_2 V_119 )
{
if ( F_35 ( V_6 , ( V_119 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_35 ( V_6 , V_119 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_42 ( struct V_6 * V_6 , int V_116 ,
T_2 V_119 )
{
if ( F_38 ( V_6 , V_116 ) )
return - 1 ;
return F_41 ( V_6 , V_119 ) ;
}
static int F_43 ( struct V_6 * V_6 , int V_120 ,
int V_121 , unsigned char * V_113 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
V_113 [ 0 ] = 0 ;
if ( V_120 && F_37 ( V_105 , V_113 , V_120 ) )
return - V_122 ;
if ( F_37 ( V_105 , NULL , V_121 ) ||
F_37 ( V_105 , NULL , V_121 ) ||
F_37 ( V_105 , NULL , V_121 ) )
return - V_122 ;
V_113 [ 0 ] = V_113 [ 1 ] = V_113 [ 2 ] = 0xff ;
if ( F_37 ( V_105 , V_113 , V_118 ) )
return - V_122 ;
F_16 ( V_6 , L_6 ,
V_121 , V_113 ) ;
return 0 ;
}
static int F_44 ( struct V_6 * V_6 )
{
unsigned char V_113 [ 4 ] ;
if ( F_43 ( V_6 , 0 , V_123 , V_113 ) ) {
F_45 ( V_6 , L_7 ) ;
return - 1 ;
}
if ( ( V_113 [ 0 ] != 0x88 || ( V_113 [ 1 ] != 0x07 && V_113 [ 1 ] != 0x08 ) ) &&
V_113 [ 0 ] != 0x73 ) {
F_16 ( V_6 ,
L_8 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_46 ( struct V_6 * V_6 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
if ( F_37 ( V_105 , NULL , V_124 ) )
return - 1 ;
return 0 ;
}
static int F_47 ( struct V_6 * V_6 , bool V_125 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
int V_126 = V_125 ? V_127 : V_128 ;
if ( F_37 ( V_105 , NULL , V_126 ) ||
F_37 ( V_105 , NULL , V_126 ) ||
F_37 ( V_105 , NULL , V_126 ) ||
F_37 ( V_105 , NULL , V_129 ) )
return - 1 ;
F_48 ( V_105 , 3 , 100 ) ;
return 0 ;
}
static int F_49 ( struct V_6 * V_6 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
if ( F_37 ( V_105 , NULL , V_129 ) ||
F_37 ( V_105 , NULL , V_129 ) ||
F_37 ( V_105 , NULL , V_129 ) ||
F_37 ( V_105 , NULL , V_129 ) ||
F_37 ( V_105 , NULL , V_130 ) )
return - 1 ;
return F_37 ( & V_6 -> V_105 , NULL , V_131 ) ;
}
static int F_50 ( struct V_6 * V_6 , char * V_113 )
{
if ( F_43 ( V_6 , 0 , V_129 , V_113 ) )
return - 1 ;
return 0 ;
}
static int F_51 ( struct V_6 * V_6 , int V_125 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
int V_126 = V_125 ? V_132 : V_133 ;
unsigned char V_134 = V_125 ? 0x0A : 0x00 ;
unsigned char V_113 [ 4 ] ;
if ( F_37 ( V_105 , V_113 , V_118 ) ||
F_37 ( V_105 , NULL , V_129 ) ||
F_37 ( V_105 , NULL , V_129 ) ||
F_37 ( V_105 , & V_134 , V_126 ) )
return - 1 ;
if ( F_50 ( V_6 , V_113 ) )
return - 1 ;
return 0 ;
}
static int F_52 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char V_135 [ sizeof( V_6 -> V_19 ) ] ;
bool V_136 ;
if ( V_2 -> V_29 & V_137 )
F_47 ( V_6 , true ) ;
V_136 = F_37 ( & V_6 -> V_105 , V_135 ,
V_138 | ( V_6 -> V_107 << 8 ) ) < 0 ;
if ( V_2 -> V_29 & V_137 )
F_47 ( V_6 , false ) ;
if ( V_136 || ( V_135 [ 0 ] & V_2 -> V_4 ) != V_2 -> V_5 )
return - 1 ;
if ( ( V_6 -> V_139 & 0xc8 ) == 0x08 ) {
if ( F_37 ( & V_6 -> V_105 , V_135 , V_138 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_6 -> V_19 , V_135 , sizeof( V_135 ) ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( ( V_2 -> V_29 & V_137 ) &&
F_47 ( V_6 , true ) ) {
return - 1 ;
}
if ( F_51 ( V_6 , true ) ) {
F_54 ( V_6 , L_9 ) ;
return - 1 ;
}
if ( F_49 ( V_6 ) ) {
F_45 ( V_6 , L_10 ) ;
return - 1 ;
}
if ( ( V_2 -> V_29 & V_137 ) &&
F_47 ( V_6 , false ) ) {
return - 1 ;
}
if ( F_37 ( & V_6 -> V_105 , NULL , V_124 ) ) {
F_45 ( V_6 , L_11 ) ;
return - 1 ;
}
return 0 ;
}
static int F_55 ( struct V_6 * V_6 ,
int V_140 , bool V_125 )
{
int V_141 , V_142 = - 1 ;
if ( F_44 ( V_6 ) )
return - 1 ;
V_141 = F_40 ( V_6 , V_140 + 0x0008 ) ;
if ( V_141 == - 1 )
goto error;
if ( V_125 )
V_141 |= 0x01 ;
else
V_141 &= ~ 0x01 ;
V_142 = F_41 ( V_6 , V_141 ) ;
error:
if ( F_46 ( V_6 ) )
V_142 = - 1 ;
return V_142 ;
}
static int F_56 ( struct V_6 * V_6 )
{
int V_141 ;
V_141 = F_40 ( V_6 , 0x0004 ) ;
if ( V_141 == - 1 )
return - 1 ;
V_141 |= 0x06 ;
if ( F_41 ( V_6 , V_141 ) )
return - 1 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_6 , int V_140 )
{
int V_142 = - V_122 , V_141 ;
if ( F_44 ( V_6 ) )
goto error;
V_141 = F_40 ( V_6 , V_140 + 0x08 ) ;
if ( V_141 == - 1 )
goto error;
V_142 = V_141 & 0x80 ? 0 : - V_143 ;
error:
F_46 ( V_6 ) ;
return V_142 ;
}
static int F_58 ( struct V_6 * V_6 , int V_140 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
int V_142 = 0 ;
unsigned char V_113 [ 4 ] ;
if ( F_55 ( V_6 , V_140 , true ) )
return - V_122 ;
if ( F_43 ( V_6 , 0 , V_127 , V_113 ) ) {
F_54 ( V_6 , L_12 ) ;
V_142 = - V_143 ;
} else {
F_16 ( V_6 , L_13 , V_113 ) ;
if ( F_37 ( V_105 , NULL , V_128 ) ||
F_37 ( V_105 , NULL , V_128 ) ||
F_37 ( V_105 , NULL , V_128 ) ||
F_35 ( V_6 , 0x9 ) ||
F_35 ( V_6 , 0x4 ) ) {
F_45 ( V_6 ,
L_14 ) ;
V_142 = - V_122 ;
goto error;
}
if ( F_44 ( V_6 ) ||
F_42 ( V_6 ,
V_140 + 0x08 , 0x82 ) ||
F_46 ( V_6 ) )
V_142 = - V_122 ;
}
error:
if ( F_55 ( V_6 , V_140 , false ) )
V_142 = - V_122 ;
return V_142 ;
}
static int F_59 ( struct V_6 * V_6 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
int V_141 ;
unsigned char V_113 [ 4 ] ;
V_141 = F_57 ( V_6 , V_144 ) ;
if ( V_141 == - V_122 )
goto error;
if ( V_141 == 0 &&
F_58 ( V_6 , V_144 ) == - V_122 )
goto error;
if ( F_44 ( V_6 ) ||
F_56 ( V_6 ) ) {
F_45 ( V_6 , L_15 ) ;
goto error;
}
V_141 = F_40 ( V_6 , 0x0006 ) ;
if ( V_141 == - 1 )
goto error;
if ( F_41 ( V_6 , V_141 | 0x01 ) )
goto error;
V_141 = F_40 ( V_6 , 0x0007 ) ;
if ( V_141 == - 1 )
goto error;
if ( F_41 ( V_6 , V_141 | 0x01 ) )
goto error;
if ( F_40 ( V_6 , 0x0144 ) == - 1 )
goto error;
if ( F_41 ( V_6 , 0x04 ) )
goto error;
if ( F_40 ( V_6 , 0x0159 ) == - 1 )
goto error;
if ( F_41 ( V_6 , 0x03 ) )
goto error;
if ( F_40 ( V_6 , 0x0163 ) == - 1 )
goto error;
if ( F_42 ( V_6 , 0x0163 , 0x03 ) )
goto error;
if ( F_40 ( V_6 , 0x0162 ) == - 1 )
goto error;
if ( F_42 ( V_6 , 0x0162 , 0x04 ) )
goto error;
F_46 ( V_6 ) ;
V_113 [ 0 ] = 0x64 ;
if ( F_37 ( V_105 , V_113 , V_132 ) ||
F_37 ( V_105 , NULL , V_130 ) ) {
F_45 ( V_6 , L_16 ) ;
return - 1 ;
}
return 0 ;
error:
F_46 ( V_6 ) ;
return - 1 ;
}
static int F_60 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_105 * V_105 = & V_6 -> V_105 ;
int V_141 , V_142 = - 1 ;
if ( V_2 -> V_29 & V_32 ) {
V_141 = F_58 ( V_6 ,
V_145 ) ;
if ( V_141 == - V_122 )
goto error;
if ( V_141 == - V_143 )
V_2 -> V_29 &= ~ V_32 ;
}
if ( F_44 ( V_6 ) ||
F_40 ( V_6 , 0xc2d9 ) == - 1 ||
F_42 ( V_6 , 0xc2cb , 0x00 ) )
goto error;
V_141 = F_40 ( V_6 , 0xc2c6 ) ;
if ( V_141 == - 1 )
goto error;
if ( F_41 ( V_6 , V_141 & 0xfd ) )
goto error;
if ( F_42 ( V_6 , 0xc2c9 , 0x64 ) )
goto error;
V_141 = F_40 ( V_6 , 0xc2c4 ) ;
if ( V_141 == - 1 )
goto error;
if ( F_41 ( V_6 , V_141 | 0x02 ) )
goto error;
F_46 ( V_6 ) ;
return F_37 ( V_105 , NULL , V_130 ) ;
error:
F_46 ( V_6 ) ;
return V_142 ;
}
static int F_61 ( struct V_6 * V_6 )
{
int V_141 ;
V_141 = F_40 ( V_6 , 0x0004 ) ;
if ( V_141 == - 1 )
return - 1 ;
V_141 |= 0x02 ;
if ( F_41 ( V_6 , V_141 ) )
return - 1 ;
return 0 ;
}
static int F_62 ( struct V_6 * V_6 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
unsigned char V_113 [ 4 ] ;
if ( F_44 ( V_6 ) )
goto error;
if ( F_61 ( V_6 ) ) {
F_45 ( V_6 , L_15 ) ;
goto error;
}
if ( F_42 ( V_6 , 0x0007 , 0x8c ) )
goto error;
if ( F_42 ( V_6 , 0x0149 , 0x03 ) )
goto error;
if ( F_42 ( V_6 , 0x0160 , 0x03 ) )
goto error;
if ( F_42 ( V_6 , 0x017f , 0x15 ) )
goto error;
if ( F_42 ( V_6 , 0x0151 , 0x01 ) )
goto error;
if ( F_42 ( V_6 , 0x0168 , 0x03 ) )
goto error;
if ( F_42 ( V_6 , 0x014a , 0x03 ) )
goto error;
if ( F_42 ( V_6 , 0x0161 , 0x03 ) )
goto error;
F_46 ( V_6 ) ;
V_113 [ 0 ] = 0xc8 ;
V_113 [ 1 ] = 0x64 ;
V_113 [ 2 ] = 0x50 ;
if ( F_37 ( V_105 , & V_113 [ 0 ] , V_132 ) ||
F_37 ( V_105 , & V_113 [ 1 ] , V_132 ) ||
F_37 ( V_105 , & V_113 [ 2 ] , V_132 ) ||
F_37 ( V_105 , V_113 , V_146 ) )
return - 1 ;
V_113 [ 0 ] = 0x64 ;
if ( F_37 ( V_105 , V_113 , V_132 ) ||
F_37 ( V_105 , NULL , V_130 ) ) {
F_45 ( V_6 , L_16 ) ;
return - 1 ;
}
return 0 ;
error:
F_46 ( V_6 ) ;
return - 1 ;
}
static int F_63 ( struct V_6 * V_6 )
{
struct V_105 * V_105 = & V_6 -> V_105 ;
unsigned char V_113 [ 2 ] ;
V_113 [ 0 ] = 0x64 ;
V_113 [ 1 ] = 0x28 ;
if ( F_37 ( V_105 , NULL , V_124 ) ||
F_37 ( V_105 , & V_113 [ 0 ] , V_132 ) ||
F_37 ( V_105 , & V_113 [ 1 ] , V_132 ) )
return - 1 ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
V_2 -> V_5 = 0x8f ;
V_2 -> V_4 = 0x8f ;
V_2 -> V_29 = V_32 ;
V_2 -> V_71 = 2000 ;
V_2 -> V_73 = 1400 ;
V_2 -> V_72 = 15 ;
V_2 -> V_70 = 11 ;
switch ( V_2 -> V_27 ) {
case V_28 :
case V_147 :
V_2 -> V_148 = F_53 ;
V_2 -> V_104 = F_6 ;
V_2 -> V_149 = V_150 ;
break;
case V_151 :
V_2 -> V_148 = F_59 ;
V_2 -> V_104 = F_23 ;
V_2 -> V_149 = V_152 ;
V_2 -> V_92 = F_18 ;
V_2 -> V_115 = V_153 ;
V_2 -> V_117 = V_123 ;
break;
case V_154 :
V_2 -> V_148 = F_62 ;
V_2 -> V_104 = F_24 ;
V_2 -> V_149 = V_152 ;
V_2 -> V_115 = V_155 ;
V_2 -> V_117 = V_129 ;
break;
case V_110 :
V_2 -> V_148 = F_63 ;
V_2 -> V_104 = F_23 ;
V_2 -> V_92 = F_20 ;
V_2 -> V_149 = V_152 ;
V_2 -> V_115 = V_153 ;
V_2 -> V_117 = V_123 ;
V_2 -> V_5 = 0xc8 ;
V_2 -> V_4 = 0xc8 ;
V_2 -> V_29 = 0 ;
V_2 -> V_71 = 1360 ;
V_2 -> V_73 = 660 ;
V_2 -> V_72 = 23 ;
V_2 -> V_70 = 12 ;
break;
}
}
static int F_65 ( struct V_6 * V_6 , struct V_1 * V_2 ,
unsigned char * V_156 , unsigned char * V_157 )
{
const struct V_158 * V_159 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_66 ( V_160 ) ; V_61 ++ ) {
V_159 = & V_160 [ V_61 ] ;
if ( ! memcmp ( V_156 , V_159 -> V_161 , sizeof( V_159 -> V_161 ) ) &&
( ! V_159 -> V_162 ||
V_159 -> V_162 == V_157 [ 2 ] ) ) {
V_2 -> V_27 = V_159 -> V_27 ;
F_64 ( V_2 ) ;
V_2 -> V_29 = V_159 -> V_29 ;
V_2 -> V_5 = V_159 -> V_5 ;
V_2 -> V_4 = V_159 -> V_4 ;
return 0 ;
}
}
return - V_163 ;
}
static int F_67 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
unsigned char V_164 [ 4 ] , V_156 [ 4 ] , V_157 [ 4 ] ;
if ( F_43 ( V_6 , V_133 ,
V_128 , V_164 ) )
return - V_122 ;
if ( ( V_164 [ 0 ] & 0xf8 ) != 0 || V_164 [ 1 ] != 0 || ( V_164 [ 2 ] != 10 && V_164 [ 2 ] != 100 ) )
return - V_163 ;
if ( F_43 ( V_6 , V_133 ,
V_127 , V_156 ) ||
F_43 ( V_6 , V_133 ,
V_123 , V_157 ) ||
F_46 ( V_6 ) )
return - V_122 ;
if ( F_65 ( V_6 , V_2 , V_156 , V_157 ) == 0 ) {
return 0 ;
} else if ( V_156 [ 0 ] == 0x73 && V_156 [ 1 ] == 0x03 && V_156 [ 2 ] == 0x50 &&
V_157 [ 0 ] == 0x73 && V_157 [ 1 ] == 0x01 ) {
V_2 -> V_27 = V_110 ;
F_64 ( V_2 ) ;
return 0 ;
} else if ( V_157 [ 0 ] == 0x88 && V_157 [ 1 ] == 0x08 ) {
V_2 -> V_27 = V_151 ;
F_64 ( V_2 ) ;
V_2 -> V_148 = F_60 ;
V_2 -> V_92 = F_19 ;
V_2 -> V_72 = 16 ;
V_2 -> V_70 = 12 ;
V_6 -> V_18 = V_2 ;
if ( F_57 ( V_6 , V_145 ) )
V_2 -> V_29 &= ~ V_32 ;
return 0 ;
} else if ( V_157 [ 0 ] == 0x88 && V_157 [ 1 ] == 0x07 &&
V_157 [ 2 ] >= 0x90 && V_157 [ 2 ] <= 0x9d ) {
V_2 -> V_27 = V_151 ;
F_64 ( V_2 ) ;
return 0 ;
}
F_68 ( V_6 ,
L_17 , V_156 , V_157 ) ;
return - V_163 ;
}
static int F_69 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
F_70 ( V_6 ) ;
if ( F_67 ( V_6 , V_2 ) < 0 )
return - 1 ;
return V_2 -> V_148 ( V_6 ) ;
}
static void F_71 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
F_70 ( V_6 ) ;
F_72 ( & V_2 -> V_101 ) ;
F_73 ( V_2 -> V_9 ) ;
F_74 ( V_2 ) ;
}
static void V_150 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_75 ( V_8 , V_36 , 0 , 1023 , 0 , 0 ) ;
F_75 ( V_8 , V_37 , 0 , 767 , 0 , 0 ) ;
}
static void V_152 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_76 ( V_165 , V_8 -> V_166 ) ;
F_77 ( V_8 , 2 , 0 ) ;
F_75 ( V_8 , V_77 , 0 , V_2 -> V_71 , 0 , 0 ) ;
F_75 ( V_8 , V_78 , 0 , V_2 -> V_73 , 0 , 0 ) ;
F_76 ( V_167 , V_8 -> V_168 ) ;
F_76 ( V_169 , V_8 -> V_168 ) ;
F_76 ( V_170 , V_8 -> V_168 ) ;
F_75 ( V_8 , V_36 , 0 , V_2 -> V_71 , 0 , 0 ) ;
F_75 ( V_8 , V_37 , 0 , V_2 -> V_73 , 0 , 0 ) ;
}
int F_78 ( struct V_6 * V_6 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_6 -> V_13 , * V_9 ;
V_2 = F_79 ( sizeof( struct V_1 ) , V_171 ) ;
V_9 = F_80 () ;
if ( ! V_2 || ! V_9 )
goto V_172;
V_2 -> V_9 = V_9 ;
F_81 ( & V_2 -> V_101 , F_31 , ( unsigned long ) V_6 ) ;
V_6 -> V_18 = V_2 ;
F_70 ( V_6 ) ;
if ( F_67 ( V_6 , V_2 ) < 0 )
goto V_172;
if ( V_2 -> V_148 ( V_6 ) )
goto V_172;
F_82 ( V_173 , V_8 -> V_174 ) ;
F_82 ( V_33 , V_8 -> V_175 ) ;
F_82 ( V_34 , V_8 -> V_175 ) ;
V_8 -> V_174 [ F_83 ( V_176 ) ] |= F_84 ( V_176 ) ;
V_8 -> V_168 [ F_83 ( V_40 ) ] |= F_84 ( V_40 ) ;
V_8 -> V_168 [ F_83 ( V_39 ) ] |= F_84 ( V_39 ) ;
V_8 -> V_168 [ F_83 ( V_14 ) ] |=
F_84 ( V_14 ) | F_84 ( V_16 ) ;
V_8 -> V_174 [ F_83 ( V_177 ) ] |= F_84 ( V_177 ) ;
V_2 -> V_149 ( V_2 , V_8 ) ;
F_75 ( V_8 , V_38 , 0 , 127 , 0 , 0 ) ;
if ( V_2 -> V_29 & V_41 ) {
V_8 -> V_174 [ F_83 ( V_173 ) ] |= F_84 ( V_173 ) ;
V_8 -> V_175 [ F_83 ( V_42 ) ] |= F_84 ( V_42 ) ;
}
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
V_8 -> V_168 [ F_83 ( V_43 ) ] |= F_84 ( V_43 ) ;
V_8 -> V_168 [ F_83 ( V_44 ) ] |= F_84 ( V_44 ) ;
}
if ( V_2 -> V_29 & V_45 ) {
V_8 -> V_168 [ F_83 ( V_46 ) ] |= F_84 ( V_46 ) ;
V_8 -> V_168 [ F_83 ( V_47 ) ] |= F_84 ( V_47 ) ;
V_8 -> V_168 [ F_83 ( V_48 ) ] |= F_84 ( V_48 ) ;
V_8 -> V_168 [ F_83 ( V_49 ) ] |= F_84 ( V_49 ) ;
} else {
V_8 -> V_168 [ F_83 ( V_17 ) ] |= F_84 ( V_17 ) ;
}
snprintf ( V_2 -> V_178 , sizeof( V_2 -> V_178 ) , L_18 , V_6 -> V_105 . V_106 -> V_178 ) ;
V_9 -> V_178 = V_2 -> V_178 ;
V_9 -> V_179 = ( V_2 -> V_29 & V_32 ) ?
L_19 : L_20 ;
V_9 -> V_180 . V_181 = V_182 ;
V_9 -> V_180 . V_183 = 0x0002 ;
V_9 -> V_180 . V_184 = V_185 ;
V_9 -> V_180 . V_186 = 0x0000 ;
V_9 -> V_13 . V_187 = & V_6 -> V_105 . V_106 -> V_13 ;
V_9 -> V_174 [ 0 ] = F_84 ( V_176 ) | F_84 ( V_173 ) ;
V_9 -> V_175 [ F_83 ( V_33 ) ] = F_84 ( V_33 ) | F_84 ( V_34 ) ;
V_9 -> V_168 [ F_83 ( V_14 ) ] =
F_84 ( V_14 ) | F_84 ( V_17 ) | F_84 ( V_16 ) ;
if ( F_85 ( V_2 -> V_9 ) )
goto V_172;
V_6 -> V_188 = F_34 ;
V_6 -> V_189 = F_52 ;
V_6 -> V_190 = F_71 ;
V_6 -> V_191 = F_69 ;
V_6 -> V_107 = V_2 -> V_27 == V_154 ? 8 : 6 ;
V_6 -> V_192 = 0 ;
return 0 ;
V_172:
F_70 ( V_6 ) ;
F_86 ( V_9 ) ;
F_74 ( V_2 ) ;
V_6 -> V_18 = NULL ;
return - 1 ;
}
int F_87 ( struct V_6 * V_6 , bool V_193 )
{
struct V_1 V_114 ;
if ( F_67 ( V_6 , & V_114 ) < 0 )
return - 1 ;
if ( V_193 ) {
V_6 -> V_183 = L_21 ;
V_6 -> V_179 = V_114 . V_29 & V_32 ?
L_22 : L_23 ;
V_6 -> V_159 = V_114 . V_27 << 8 ;
}
return 0 ;
}
