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
F_2 ( V_12 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_23 && ! V_24 )
V_22 = 40 ;
if ( V_23 && V_24 && ! V_2 -> V_35 ) {
F_8 ( V_12 , V_36 , V_20 ) ;
F_8 ( V_12 , V_37 , V_21 ) ;
F_8 ( V_12 , V_38 , 0 ) ;
F_4 ( V_12 , V_39 , 0 ) ;
F_5 ( V_12 ) ;
}
V_2 -> V_35 = V_24 ;
if ( V_22 > 30 )
F_4 ( V_12 , V_40 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_12 , V_40 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_12 , V_36 , V_20 ) ;
F_8 ( V_12 , V_37 , V_21 ) ;
}
F_8 ( V_12 , V_38 , V_22 ) ;
F_4 ( V_12 , V_39 , V_22 > 0 ) ;
if ( V_2 -> V_29 & V_41 )
F_7 ( V_12 , V_42 , ( ( V_19 [ 2 ] << 1 ) & 0x08 ) - ( ( V_19 [ 0 ] >> 4 ) & 0x07 ) ) ;
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
F_4 ( V_12 , V_43 , V_26 ) ;
F_4 ( V_12 , V_44 , V_25 ) ;
}
if ( V_2 -> V_29 & V_45 ) {
F_4 ( V_12 , V_46 , V_19 [ 2 ] & 4 ) ;
F_4 ( V_12 , V_47 , V_19 [ 0 ] & 0x10 ) ;
F_4 ( V_12 , V_48 , V_19 [ 3 ] & 4 ) ;
F_4 ( V_12 , V_49 , V_19 [ 0 ] & 0x20 ) ;
}
F_5 ( V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_52 , V_53 ;
unsigned int V_54 , V_55 ;
unsigned char V_56 , V_57 ;
unsigned char V_58 , V_59 , V_60 , V_61 ;
V_54 = V_51 -> V_54 ;
V_55 = V_51 -> V_55 ;
if ( ! V_54 || ! V_55 )
return;
V_58 = F_10 ( V_54 ) ;
V_59 = F_11 ( V_54 ) ;
V_60 = F_10 ( V_55 ) ;
V_61 = F_11 ( V_55 ) ;
if ( V_58 > V_2 -> V_62 || V_60 > V_2 -> V_63 )
return;
if ( V_51 -> V_64 > 1 ) {
V_56 = V_2 -> V_62 - V_58 ;
V_57 = V_2 -> V_62 - V_59 ;
V_52 = ( V_2 -> V_65 * ( V_56 + V_57 ) ) /
( 2 * ( V_2 -> V_62 - 1 ) ) ;
V_56 = V_61 - 1 ;
V_57 = V_60 - 1 ;
V_53 = ( V_2 -> V_66 * ( V_56 + V_57 ) ) /
( 2 * ( V_2 -> V_63 - 1 ) ) ;
V_51 -> V_67 [ 0 ] = V_51 -> V_68 ;
V_51 -> V_67 [ 1 ] . V_20 = 2 * V_52 - V_51 -> V_67 [ 0 ] . V_20 ;
V_51 -> V_67 [ 1 ] . V_21 = 2 * V_53 - V_51 -> V_67 [ 0 ] . V_21 ;
}
}
static void F_12 ( unsigned int V_69 ,
struct V_70 * V_71 ,
struct V_70 * V_72 ,
int * V_64 )
{
struct V_70 * V_73 ;
int V_74 , V_75 , V_76 = 0 ;
V_73 = V_71 ;
for ( V_74 = 0 ; V_69 != 0 ; V_74 ++ , V_69 >>= 1 ) {
V_75 = V_69 & 1 ;
if ( V_75 ) {
if ( ! V_76 ) {
V_73 -> V_56 = V_74 ;
V_73 -> V_77 = 0 ;
( * V_64 ) ++ ;
}
V_73 -> V_77 ++ ;
} else {
if ( V_76 )
V_73 = V_72 ;
}
V_76 = V_75 ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_74 , V_78 = 0 , V_79 = 0 , V_64 ;
struct V_70 V_80 = { 0 ,} , V_81 = { 0 ,} ;
struct V_70 V_82 = { 0 ,} , V_83 = { 0 ,} ;
if ( ! V_51 -> V_54 || ! V_51 -> V_55 )
return 0 ;
F_12 ( V_51 -> V_54 , & V_80 , & V_81 , & V_78 ) ;
F_12 ( V_51 -> V_55 , & V_82 , & V_83 , & V_79 ) ;
V_64 = F_14 ( V_78 , V_79 ) ;
if ( V_78 == 1 ) {
V_74 = ( V_80 . V_77 - 1 ) / 2 ;
V_80 . V_77 = V_80 . V_77 - V_74 ;
V_81 . V_56 = V_80 . V_56 + V_74 ;
V_81 . V_77 = F_14 ( V_74 , 1 ) ;
}
if ( V_79 == 1 ) {
V_74 = ( V_82 . V_77 - 1 ) / 2 ;
V_82 . V_77 = V_82 . V_77 - V_74 ;
V_83 . V_56 = V_82 . V_56 + V_74 ;
V_83 . V_77 = F_14 ( V_74 , 1 ) ;
}
V_51 -> V_67 [ 0 ] . V_20 =
( V_2 -> V_65 * ( 2 * V_80 . V_56 + V_80 . V_77 - 1 ) ) /
( 2 * ( V_2 -> V_62 - 1 ) ) ;
V_51 -> V_67 [ 0 ] . V_21 =
( V_2 -> V_66 * ( 2 * V_82 . V_56 + V_82 . V_77 - 1 ) ) /
( 2 * ( V_2 -> V_63 - 1 ) ) ;
V_51 -> V_67 [ 1 ] . V_20 =
( V_2 -> V_65 * ( 2 * V_81 . V_56 + V_81 . V_77 - 1 ) ) /
( 2 * ( V_2 -> V_62 - 1 ) ) ;
V_51 -> V_67 [ 1 ] . V_21 =
( V_2 -> V_66 * ( 2 * V_83 . V_56 + V_83 . V_77 - 1 ) ) /
( 2 * ( V_2 -> V_63 - 1 ) ) ;
if ( V_2 -> V_27 != V_84 ) {
V_51 -> V_67 [ 0 ] . V_21 = V_2 -> V_66 - V_51 -> V_67 [ 0 ] . V_21 ;
V_51 -> V_67 [ 1 ] . V_21 = V_2 -> V_66 - V_51 -> V_67 [ 1 ] . V_21 ;
}
return V_64 ;
}
static void F_15 ( struct V_6 * V_12 , int V_85 , int V_20 , int V_21 )
{
F_16 ( V_12 , V_85 ) ;
F_17 ( V_12 , V_86 , true ) ;
F_8 ( V_12 , V_87 , V_20 ) ;
F_8 ( V_12 , V_88 , V_21 ) ;
}
static void F_18 ( struct V_17 * V_17 , int V_89 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
int V_74 , V_85 [ V_91 ] ;
F_19 ( V_12 , V_85 , V_90 -> V_67 , V_89 , 0 ) ;
for ( V_74 = 0 ; V_74 < V_89 ; V_74 ++ )
F_15 ( V_12 , V_85 [ V_74 ] , V_90 -> V_67 [ V_74 ] . V_20 , V_90 -> V_67 [ V_74 ] . V_21 ) ;
F_20 ( V_12 ) ;
}
static void F_21 ( struct V_17 * V_17 , int V_64 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
if ( V_64 < 2 ) {
V_90 -> V_67 [ 0 ] . V_20 = V_90 -> V_68 . V_20 ;
V_90 -> V_67 [ 0 ] . V_21 = V_90 -> V_68 . V_21 ;
V_64 = V_90 -> V_92 > 0 ? 1 : 0 ;
}
F_18 ( V_17 , ( V_64 <= 2 ) ? V_64 : 2 ) ;
F_22 ( V_12 , V_64 ) ;
F_4 ( V_12 , V_13 , V_90 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_90 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_90 -> V_11 ) ;
F_8 ( V_12 , V_38 , V_90 -> V_92 ) ;
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
V_20 = ( V_93 ) ( ( ( V_19 [ 0 ] & 0x20 ) << 2 ) | ( V_19 [ 1 ] & 0x7f ) ) ;
V_21 = ( V_93 ) ( ( ( V_19 [ 0 ] & 0x10 ) << 3 ) | ( V_19 [ 2 ] & 0x7f ) ) ;
V_22 = ( V_19 [ 4 ] & 0x7c ) >> 2 ;
V_20 /= 8 ;
V_21 /= 8 ;
F_7 ( V_12 , V_33 , V_20 ) ;
F_7 ( V_12 , V_34 , - V_21 ) ;
V_9 = V_19 [ 3 ] & 0x01 ;
V_10 = V_19 [ 3 ] & 0x02 ;
V_11 = V_19 [ 3 ] & 0x04 ;
if ( ! ( V_2 -> V_94 & V_95 ) &&
( V_9 || V_10 || V_11 ) )
V_2 -> V_94 |= V_95 ;
if ( V_2 -> V_94 & V_95 ) {
F_4 ( V_12 , V_13 , V_9 ) ;
F_4 ( V_12 , V_15 , V_10 ) ;
F_4 ( V_12 , V_16 , V_11 ) ;
}
F_5 ( V_12 ) ;
return;
}
static void F_26 ( struct V_50 * V_90 , unsigned char * V_96 )
{
V_90 -> V_9 = ! ! ( V_96 [ 3 ] & 0x01 ) ;
V_90 -> V_10 = ! ! ( V_96 [ 3 ] & 0x02 ) ;
V_90 -> V_11 = ! ! ( V_96 [ 3 ] & 0x04 ) ;
V_90 -> V_97 = ! ! ( V_96 [ 3 ] & 0x10 ) ;
V_90 -> V_98 = ! ! ( V_96 [ 3 ] & 0x20 ) ;
V_90 -> V_99 = ! ! ( V_96 [ 3 ] & 0x40 ) ;
}
static int F_27 ( struct V_50 * V_90 , unsigned char * V_96 ,
struct V_17 * V_17 )
{
V_90 -> V_100 = ! ! ( V_96 [ 4 ] & 0x40 ) ;
V_90 -> V_101 = ! ! ( V_96 [ 0 ] & 0x40 ) ;
V_90 -> V_64 = ( V_96 [ 5 ] & 0x3 ) + 1 ;
V_90 -> V_54 = ( ( V_96 [ 4 ] & 0x7e ) << 8 ) |
( ( V_96 [ 1 ] & 0x7f ) << 2 ) |
( ( V_96 [ 0 ] & 0x30 ) >> 4 ) ;
V_90 -> V_55 = ( ( V_96 [ 3 ] & 0x70 ) << 4 ) |
( ( V_96 [ 2 ] & 0x7f ) << 1 ) |
( V_96 [ 4 ] & 0x01 ) ;
V_90 -> V_68 . V_20 = ( ( V_96 [ 1 ] & 0x7f ) << 4 ) | ( ( V_96 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_96 [ 0 ] & 0x30 ) >> 4 ) ;
V_90 -> V_68 . V_21 = ( ( V_96 [ 2 ] & 0x7f ) << 4 ) | ( V_96 [ 4 ] & 0x0f ) ;
V_90 -> V_92 = V_96 [ 5 ] & 0x7f ;
F_26 ( V_90 , V_96 ) ;
return 0 ;
}
static int F_28 ( struct V_50 * V_90 , unsigned char * V_96 ,
struct V_17 * V_17 )
{
F_27 ( V_90 , V_96 , V_17 ) ;
V_90 -> V_101 = ! ! ( V_96 [ 5 ] & 0x40 ) ;
V_90 -> V_64 = F_14 ( ( V_96 [ 5 ] & 0x3 ) , ( ( V_96 [ 5 ] >> 2 ) & 0x3 ) ) + 1 ;
V_90 -> V_54 |= ( V_96 [ 5 ] & 0x10 ) << 11 ;
V_90 -> V_55 |= ( V_96 [ 5 ] & 0x20 ) << 6 ;
return 0 ;
}
static int F_29 ( struct V_50 * V_90 , unsigned char * V_96 ,
struct V_17 * V_17 )
{
T_1 V_102 = 0 ;
struct V_1 * V_2 = V_17 -> V_18 ;
V_90 -> V_100 = ! ! ( V_96 [ 0 ] & 0x02 ) ;
V_90 -> V_101 = ! ! ( V_96 [ 0 ] & 0x20 ) ;
if ( ! V_90 -> V_101 ) {
V_90 -> V_68 . V_20 = ( ( V_96 [ 1 ] & 0x7f ) | ( ( V_96 [ 4 ] & 0x0f ) << 7 ) ) ;
V_90 -> V_68 . V_21 = ( ( V_96 [ 2 ] & 0x7f ) | ( ( V_96 [ 4 ] & 0xf0 ) << 3 ) ) ;
V_90 -> V_92 = ( V_96 [ 0 ] & 4 ) ? 0 : V_96 [ 5 ] & 0x7f ;
F_26 ( V_90 , V_96 ) ;
} else {
V_90 -> V_64 = ( ( V_96 [ 0 ] & 0x6 ) >> 1 |
( V_96 [ 0 ] & 0x10 ) >> 2 ) ;
V_102 = ( V_96 [ 1 ] & 0x7f ) |
( ( V_96 [ 2 ] & 0x7f ) << 7 ) |
( ( V_96 [ 4 ] & 0x7f ) << 14 ) |
( ( V_96 [ 5 ] & 0x7f ) << 21 ) |
( ( V_96 [ 3 ] & 0x07 ) << 28 ) |
( ( ( T_1 ) V_96 [ 3 ] & 0x70 ) << 27 ) |
( ( ( T_1 ) V_96 [ 0 ] & 0x01 ) << 34 ) ;
V_90 -> V_55 = V_102 & ( F_30 ( V_2 -> V_63 ) - 1 ) ;
V_90 -> V_54 = ( V_102 >> V_2 -> V_63 ) &
( F_30 ( V_2 -> V_62 ) - 1 ) ;
}
return 0 ;
}
static void F_31 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_8 = V_2 -> V_8 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
int V_64 = 0 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_2 -> V_103 ( V_90 , V_19 , V_17 ) ;
if ( V_2 -> V_104 ) {
if ( V_90 -> V_101 ) {
V_64 = V_90 -> V_64 ;
if ( V_2 -> V_27 == V_105 ||
V_2 -> V_27 == V_84 ) {
if ( F_13 ( V_2 , V_90 ) == 0 )
V_64 = 0 ;
V_2 -> V_103 ( V_90 , V_2 -> V_106 ,
V_17 ) ;
} else {
V_2 -> V_103 ( V_90 , V_2 -> V_106 ,
V_17 ) ;
F_9 ( V_2 , V_90 ) ;
}
} else {
V_2 -> V_104 = 0 ;
}
}
if ( V_90 -> V_101 )
return;
if ( ! V_2 -> V_104 && V_90 -> V_100 ) {
V_2 -> V_104 = 1 ;
memcpy ( V_2 -> V_106 , V_19 , sizeof( V_2 -> V_106 ) ) ;
return;
}
V_2 -> V_104 = 0 ;
if ( V_90 -> V_68 . V_20 && V_90 -> V_68 . V_21 && ! V_90 -> V_92 )
return;
F_21 ( V_17 , V_64 ) ;
if ( ( V_2 -> V_29 & V_32 ) &&
! ( V_2 -> V_94 & V_95 ) ) {
F_4 ( V_8 , V_13 , V_90 -> V_97 ) ;
F_4 ( V_8 , V_15 , V_90 -> V_98 ) ;
F_4 ( V_8 , V_16 , V_90 -> V_99 ) ;
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
F_4 ( V_12 , V_40 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_12 , V_40 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_12 , V_36 , V_20 ) ;
F_8 ( V_12 , V_37 , V_21 ) ;
}
F_8 ( V_12 , V_38 , V_22 ) ;
F_4 ( V_12 , V_39 , V_22 > 0 ) ;
F_4 ( V_12 , V_13 , V_9 ) ;
F_4 ( V_12 , V_15 , V_10 ) ;
F_5 ( V_12 ) ;
}
static void F_34 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
int V_107 ;
if ( V_19 [ 6 ] & 0x40 ) {
V_2 -> V_104 = 0 ;
}
if ( F_35 ( V_2 -> V_104 > 2 ) )
return;
V_107 = 2 * V_2 -> V_104 ;
V_2 -> V_106 [ V_107 ] = V_19 [ 6 ] ;
V_2 -> V_106 [ V_107 + 1 ] = V_19 [ 7 ] ;
if ( ++ V_2 -> V_104 > 2 ) {
V_2 -> V_104 = 0 ;
V_90 -> V_54 = ( ( V_2 -> V_106 [ 2 ] & 0x1f ) << 10 ) |
( ( V_2 -> V_106 [ 3 ] & 0x60 ) << 3 ) |
( ( V_2 -> V_106 [ 0 ] & 0x3f ) << 2 ) |
( ( V_2 -> V_106 [ 1 ] & 0x60 ) >> 5 ) ;
V_90 -> V_55 = ( ( V_2 -> V_106 [ 5 ] & 0x01 ) << 10 ) |
( ( V_2 -> V_106 [ 3 ] & 0x1f ) << 5 ) |
( V_2 -> V_106 [ 1 ] & 0x1f ) ;
V_90 -> V_64 = F_13 ( V_2 , V_90 ) ;
}
V_90 -> V_9 = ! ! ( V_19 [ 4 ] & 0x01 ) ;
V_90 -> V_10 = ! ! ( V_19 [ 4 ] & 0x02 ) ;
V_90 -> V_68 . V_20 = ( ( V_19 [ 1 ] & 0x7f ) << 4 ) | ( ( V_19 [ 3 ] & 0x30 ) >> 2 ) |
( ( V_19 [ 0 ] & 0x30 ) >> 4 ) ;
V_90 -> V_68 . V_21 = ( ( V_19 [ 2 ] & 0x7f ) << 4 ) | ( V_19 [ 3 ] & 0x0f ) ;
V_90 -> V_92 = V_19 [ 5 ] & 0x7f ;
F_21 ( V_17 , V_90 -> V_64 ) ;
}
static bool F_36 ( struct V_17 * V_17 )
{
switch ( V_17 -> V_108 ) {
case 3 :
return ( V_17 -> V_19 [ 2 ] & 0x40 ) == 0x40 ;
case 4 :
return ( V_17 -> V_19 [ 3 ] & 0x48 ) == 0x48 ;
case 6 :
return ( V_17 -> V_19 [ 5 ] & 0x40 ) == 0x00 ;
}
return true ;
}
static unsigned char F_37 ( char * V_109 )
{
unsigned char V_110 ;
if ( V_109 [ 4 ] & 0x40 )
V_110 = V_111 ;
else if ( V_109 [ 4 ] & 0x01 )
V_110 = V_112 ;
else if ( ( V_109 [ 0 ] & 0x10 ) && ! ( V_109 [ 4 ] & 0x43 ) )
V_110 = V_113 ;
else if ( V_109 [ 1 ] == 0x00 && V_109 [ 4 ] == 0x00 )
V_110 = V_114 ;
else
V_110 = V_115 ;
return V_110 ;
}
static void F_38 ( struct V_116 * V_67 ,
unsigned char * V_117 ,
unsigned char V_118 )
{
V_67 [ 0 ] . V_20 = ( ( V_117 [ 2 ] & 0x80 ) << 4 ) ;
V_67 [ 0 ] . V_20 |= ( ( V_117 [ 2 ] & 0x3F ) << 5 ) ;
V_67 [ 0 ] . V_20 |= ( ( V_117 [ 3 ] & 0x30 ) >> 1 ) ;
V_67 [ 0 ] . V_20 |= ( V_117 [ 3 ] & 0x07 ) ;
V_67 [ 0 ] . V_21 = ( V_117 [ 1 ] << 3 ) | ( V_117 [ 0 ] & 0x07 ) ;
V_67 [ 1 ] . V_20 = ( ( V_117 [ 3 ] & 0x80 ) << 4 ) ;
V_67 [ 1 ] . V_20 |= ( ( V_117 [ 4 ] & 0x80 ) << 3 ) ;
V_67 [ 1 ] . V_20 |= ( ( V_117 [ 4 ] & 0x3F ) << 4 ) ;
V_67 [ 1 ] . V_21 = ( ( V_117 [ 5 ] & 0x80 ) << 3 ) ;
V_67 [ 1 ] . V_21 |= ( ( V_117 [ 5 ] & 0x3F ) << 4 ) ;
switch ( V_118 ) {
case V_111 :
V_67 [ 1 ] . V_20 &= ~ 0x000F ;
V_67 [ 1 ] . V_21 |= 0x000F ;
break;
case V_112 :
V_67 [ 1 ] . V_20 &= ~ 0x003F ;
V_67 [ 1 ] . V_21 &= ~ 0x0020 ;
V_67 [ 1 ] . V_21 |= ( ( V_117 [ 4 ] & 0x02 ) << 4 ) ;
V_67 [ 1 ] . V_21 |= 0x001F ;
break;
case V_113 :
V_67 [ 1 ] . V_20 &= ~ 0x003F ;
V_67 [ 1 ] . V_20 |= ( V_117 [ 0 ] & 0x20 ) ;
V_67 [ 1 ] . V_21 |= 0x000F ;
break;
}
V_67 [ 0 ] . V_21 = 0x7FF - V_67 [ 0 ] . V_21 ;
V_67 [ 1 ] . V_21 = 0x7FF - V_67 [ 1 ] . V_21 ;
}
static int F_39 ( struct V_116 * V_67 )
{
int V_74 , V_64 = 0 ;
for ( V_74 = 0 ; V_74 < V_91 ; V_74 ++ ) {
if ( V_67 [ V_74 ] . V_20 != 0 || V_67 [ V_74 ] . V_21 != 0 )
V_64 ++ ;
}
return V_64 ;
}
static int F_40 ( struct V_50 * V_90 ,
unsigned char * V_96 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_118 ;
V_118 = F_37 ( V_96 ) ;
if ( V_118 == V_114 )
return 0 ;
if ( V_118 == V_115 )
return - 1 ;
if ( V_118 == V_113 )
return 1 ;
F_38 ( V_90 -> V_67 , V_96 , V_118 ) ;
if ( V_118 == V_111 )
V_90 -> V_64 = F_39 ( V_90 -> V_67 ) ;
else
V_90 -> V_64 = 3 + ( V_96 [ 5 ] & 0x03 ) ;
V_90 -> V_9 = ( V_96 [ 0 ] & 0x80 ) >> 7 ;
if ( V_2 -> V_29 & V_119 ) {
if ( V_96 [ 0 ] & 0x20 )
V_90 -> V_64 ++ ;
if ( V_96 [ 0 ] & 0x10 )
V_90 -> V_64 ++ ;
} else {
V_90 -> V_10 = ( V_96 [ 0 ] & 0x20 ) >> 5 ;
V_90 -> V_11 = ( V_96 [ 0 ] & 0x10 ) >> 4 ;
}
if ( V_90 -> V_64 == 1 && V_90 -> V_67 [ 0 ] . V_20 == 0 && V_90 -> V_67 [ 0 ] . V_21 == 0 ) {
V_90 -> V_67 [ 0 ] . V_20 = V_90 -> V_67 [ 1 ] . V_20 ;
V_90 -> V_67 [ 0 ] . V_21 = V_90 -> V_67 [ 1 ] . V_21 ;
V_90 -> V_67 [ 1 ] . V_20 = 0 ;
V_90 -> V_67 [ 1 ] . V_21 = 0 ;
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
F_7 ( V_8 , V_33 , ( char ) V_20 / 2 ) ;
F_7 ( V_8 , V_34 , - ( ( char ) V_21 / 2 ) ) ;
F_4 ( V_8 , V_13 , V_9 ) ;
F_4 ( V_8 , V_15 , V_10 ) ;
F_4 ( V_8 , V_16 , V_11 ) ;
F_5 ( V_8 ) ;
}
static void F_42 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
if ( V_2 -> V_103 ( V_90 , V_17 -> V_19 , V_17 ) )
return;
F_18 ( V_17 , F_39 ( V_90 -> V_67 ) ) ;
F_22 ( V_12 , V_90 -> V_64 ) ;
F_4 ( V_12 , V_13 , V_90 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_90 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_90 -> V_11 ) ;
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
static void F_44 ( struct V_120 * V_121 )
{
struct V_1 * V_2 =
F_45 ( V_121 , struct V_1 , V_122 . V_121 ) ;
struct V_17 * V_17 = V_2 -> V_17 ;
struct V_6 * V_123 ;
int error = 0 ;
F_46 ( & V_124 ) ;
if ( V_2 -> V_123 )
goto V_125;
V_123 = F_47 () ;
if ( ! V_123 ) {
F_48 ( V_17 , L_3 ) ;
error = - V_126 ;
goto V_125;
}
snprintf ( V_2 -> V_127 , sizeof( V_2 -> V_127 ) , L_4 ,
V_17 -> V_128 . V_129 -> V_130 ,
( V_2 -> V_8 ? L_5 : L_6 ) ) ;
V_123 -> V_130 = V_2 -> V_127 ;
V_123 -> V_131 = L_7 ;
V_123 -> V_132 . V_133 = V_134 ;
V_123 -> V_132 . V_135 = 0x0002 ;
V_123 -> V_132 . V_136 = V_137 ;
V_123 -> V_132 . V_138 = 0x0000 ;
V_123 -> V_12 . V_139 = & V_17 -> V_128 . V_129 -> V_12 ;
F_49 ( V_123 , V_140 , V_33 ) ;
F_49 ( V_123 , V_140 , V_34 ) ;
F_49 ( V_123 , V_141 , V_13 ) ;
F_49 ( V_123 , V_141 , V_15 ) ;
F_49 ( V_123 , V_141 , V_16 ) ;
F_50 ( V_142 , V_123 -> V_143 ) ;
error = F_51 ( V_123 ) ;
if ( error ) {
F_48 ( V_17 ,
L_8 ,
error ) ;
F_52 ( V_123 ) ;
goto V_125;
}
V_2 -> V_123 = V_123 ;
V_125:
if ( error )
V_2 -> V_123 = F_53 ( error ) ;
F_54 ( & V_124 ) ;
}
static void F_55 ( struct V_17 * V_17 ,
unsigned char V_19 [] ,
bool V_144 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 ;
if ( V_2 -> V_27 == V_145 &&
( V_2 -> V_29 & V_32 ) ) {
V_12 = V_2 -> V_8 ;
} else if ( F_56 ( F_57 ( V_2 -> V_123 ) ) ) {
if ( ! F_58 ( V_2 -> V_123 ) )
F_59 ( V_17 , & V_2 -> V_122 ,
0 ) ;
return;
} else {
V_12 = V_2 -> V_123 ;
}
if ( V_144 )
F_2 ( V_12 , NULL ,
V_19 [ 0 ] & 1 , V_19 [ 0 ] & 2 , V_19 [ 0 ] & 4 ) ;
F_7 ( V_12 , V_33 ,
V_19 [ 1 ] ? V_19 [ 1 ] - ( ( V_19 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_12 , V_34 ,
V_19 [ 2 ] ? ( ( V_19 [ 0 ] << 3 ) & 0x100 ) - V_19 [ 2 ] : 0 ) ;
F_5 ( V_12 ) ;
}
static T_2 F_60 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_17 -> V_108 < 6 )
return V_146 ;
if ( V_17 -> V_108 == 6 ) {
F_61 ( & V_2 -> V_147 , V_148 + F_62 ( 20 ) ) ;
return V_146 ;
}
F_63 ( & V_2 -> V_147 ) ;
if ( V_17 -> V_19 [ 6 ] & 0x80 ) {
if ( ( ( V_17 -> V_19 [ 3 ] |
V_17 -> V_19 [ 4 ] |
V_17 -> V_19 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_2 , V_17 -> V_19 [ 6 ] ) ) ) {
F_25 ( V_17 ,
L_9 ,
V_17 -> V_19 + 3 ) ;
return V_149 ;
}
V_2 -> V_150 ( V_17 ) ;
V_17 -> V_19 [ 0 ] = V_17 -> V_19 [ 6 ] ;
V_17 -> V_108 = 1 ;
} else {
F_55 ( V_17 , & V_17 -> V_19 [ 3 ] ,
false ) ;
V_17 -> V_19 [ 3 ] = V_17 -> V_19 [ 6 ] & 0xf7 ;
V_17 -> V_108 = 4 ;
}
return V_146 ;
}
static void F_64 ( unsigned long V_3 )
{
struct V_17 * V_17 = (struct V_17 * ) V_3 ;
struct V_1 * V_2 = V_17 -> V_18 ;
F_65 ( V_17 -> V_128 . V_129 ) ;
if ( V_17 -> V_108 == V_17 -> V_151 ) {
if ( ( V_17 -> V_19 [ 3 ] |
V_17 -> V_19 [ 4 ] |
V_17 -> V_19 [ 5 ] ) & 0x80 ) {
F_25 ( V_17 ,
L_10 ,
V_17 -> V_19 + 3 ) ;
} else {
V_2 -> V_150 ( V_17 ) ;
}
V_17 -> V_108 = 0 ;
}
F_66 ( V_17 -> V_128 . V_129 ) ;
}
static T_2 F_67 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( ! V_17 -> V_152 && ( V_17 -> V_19 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_17 -> V_108 == 3 ) {
F_55 ( V_17 , V_17 -> V_19 ,
true ) ;
return V_153 ;
}
return V_146 ;
}
if ( ( V_2 -> V_29 & V_154 ) &&
V_17 -> V_108 >= 4 && ( V_17 -> V_19 [ 3 ] & 0x0f ) == 0x0f ) {
return F_60 ( V_17 ) ;
}
if ( ! F_1 ( V_2 , V_17 -> V_19 [ 0 ] ) ) {
F_25 ( V_17 ,
L_11 ,
V_17 -> V_19 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_149 ;
}
if ( V_2 -> V_27 < V_155 &&
V_17 -> V_108 >= 2 && V_17 -> V_108 <= V_17 -> V_151 &&
( V_17 -> V_19 [ V_17 -> V_108 - 1 ] & 0x80 ) ) {
F_25 ( V_17 , L_12 ,
V_17 -> V_108 - 1 ,
V_17 -> V_19 [ V_17 -> V_108 - 1 ] ) ;
if ( V_2 -> V_27 == V_84 &&
V_17 -> V_108 == V_17 -> V_151 ) {
return V_153 ;
}
return V_149 ;
}
if ( V_2 -> V_27 == V_156 &&
! F_36 ( V_17 ) ) {
F_25 ( V_17 , L_12 ,
V_17 -> V_108 - 1 ,
V_17 -> V_19 [ V_17 -> V_108 - 1 ] ) ;
return V_149 ;
}
if ( V_17 -> V_108 == V_17 -> V_151 ) {
V_2 -> V_150 ( V_17 ) ;
return V_153 ;
}
return V_146 ;
}
static int F_68 ( struct V_17 * V_17 , int V_157 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_158 ;
unsigned char * V_159 ;
unsigned char V_160 [ 4 ] ;
F_69 ( V_157 > 0xf ) ;
V_158 = V_2 -> V_161 [ V_157 ] . V_158 ;
V_159 = ( V_158 & 0x0f00 ) ?
V_160 : ( unsigned char * ) & V_2 -> V_161 [ V_157 ] . V_3 ;
if ( F_70 ( V_128 , V_159 , V_158 ) )
return - 1 ;
return 0 ;
}
static int F_71 ( struct V_17 * V_17 , int V_162 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_74 , V_157 ;
if ( F_70 ( V_128 , NULL , V_2 -> V_163 ) )
return - 1 ;
for ( V_74 = 12 ; V_74 >= 0 ; V_74 -= 4 ) {
V_157 = ( V_162 >> V_74 ) & 0xf ;
if ( F_68 ( V_17 , V_157 ) )
return - 1 ;
}
return 0 ;
}
static int F_72 ( struct V_17 * V_17 , int V_162 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
unsigned char V_159 [ 4 ] ;
if ( F_70 ( V_128 , V_159 , V_164 ) )
return - 1 ;
if ( V_162 != ( ( V_159 [ 0 ] << 8 ) | V_159 [ 1 ] ) )
return - 1 ;
return V_159 [ 2 ] ;
}
static int F_73 ( struct V_17 * V_17 , int V_162 )
{
if ( F_71 ( V_17 , V_162 ) )
return - 1 ;
return F_72 ( V_17 , V_162 ) ;
}
static int F_74 ( struct V_17 * V_17 , T_3 V_165 )
{
if ( F_68 ( V_17 , ( V_165 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_68 ( V_17 , V_165 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_75 ( struct V_17 * V_17 , int V_162 ,
T_3 V_165 )
{
if ( F_71 ( V_17 , V_162 ) )
return - 1 ;
return F_74 ( V_17 , V_165 ) ;
}
static int F_76 ( struct V_17 * V_17 , int V_166 ,
int V_167 , unsigned char * V_159 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
V_159 [ 0 ] = 0 ;
if ( V_166 && F_70 ( V_128 , V_159 , V_166 ) )
return - V_168 ;
if ( F_70 ( V_128 , NULL , V_167 ) ||
F_70 ( V_128 , NULL , V_167 ) ||
F_70 ( V_128 , NULL , V_167 ) )
return - V_168 ;
V_159 [ 0 ] = V_159 [ 1 ] = V_159 [ 2 ] = 0xff ;
if ( F_70 ( V_128 , V_159 , V_164 ) )
return - V_168 ;
F_25 ( V_17 , L_13 ,
V_167 , V_159 ) ;
return 0 ;
}
static bool F_77 ( unsigned char V_132 [] )
{
if ( V_132 [ 0 ] == 0x73 )
return true ;
if ( V_132 [ 0 ] == 0x88 &&
( V_132 [ 1 ] == 0x07 ||
V_132 [ 1 ] == 0x08 ||
( V_132 [ 1 ] & 0xf0 ) == 0xb0 ||
( V_132 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
return true ;
}
return false ;
}
static int F_78 ( struct V_17 * V_17 )
{
unsigned char V_159 [ 4 ] ;
if ( F_76 ( V_17 , 0 , V_169 , V_159 ) ) {
F_48 ( V_17 , L_14 ) ;
return - 1 ;
}
if ( ! F_77 ( V_159 ) ) {
F_25 ( V_17 ,
L_15 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_79 ( struct V_17 * V_17 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
if ( F_70 ( V_128 , NULL , V_170 ) )
return - 1 ;
return 0 ;
}
static int F_80 ( struct V_17 * V_17 , bool V_171 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
int V_172 = V_171 ? V_173 : V_174 ;
if ( F_70 ( V_128 , NULL , V_172 ) ||
F_70 ( V_128 , NULL , V_172 ) ||
F_70 ( V_128 , NULL , V_172 ) ||
F_70 ( V_128 , NULL , V_175 ) )
return - 1 ;
F_81 ( V_128 , 3 , 100 ) ;
return 0 ;
}
static int F_82 ( struct V_17 * V_17 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
if ( F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_176 ) )
return - 1 ;
return F_70 ( & V_17 -> V_128 , NULL , V_177 ) ;
}
static int F_83 ( struct V_17 * V_17 , T_4 V_178 )
{
int V_74 , V_157 ;
for ( V_74 = 0 ; V_74 <= 8 ; V_74 += 4 ) {
V_157 = ( V_178 >> V_74 ) & 0xf ;
if ( F_68 ( V_17 , V_157 ) )
return - 1 ;
}
return 0 ;
}
static int F_84 ( struct V_17 * V_17 ,
T_4 V_162 , T_4 V_165 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
if ( F_70 ( V_128 , NULL , V_176 ) ||
F_83 ( V_17 , 0x0A0 ) ||
F_83 ( V_17 , V_162 ) ||
F_83 ( V_17 , V_165 ) ||
F_70 ( V_128 , NULL , V_175 ) )
return - 1 ;
return 0 ;
}
static int F_85 ( struct V_17 * V_17 , bool V_171 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
if ( V_171 ) {
if ( F_70 ( V_128 , NULL , V_169 ) ||
F_70 ( V_128 , NULL , V_164 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_173 ) ||
F_70 ( V_128 , NULL , V_174 ) ||
F_70 ( V_128 , NULL , V_173 ) ||
F_70 ( V_128 , NULL , V_164 ) )
return - 1 ;
} else {
if ( F_70 ( V_128 , NULL , V_169 ) )
return - 1 ;
}
return 0 ;
}
static int F_86 ( struct V_17 * V_17 )
{
T_4 V_179 = 0x181 ;
int V_180 = - 1 ;
if ( F_85 ( V_17 , true ) )
return - 1 ;
V_180 = F_84 ( V_17 , 0x000 , V_179 ) ;
if ( F_85 ( V_17 , false ) )
V_180 = - 1 ;
return V_180 ;
}
static int F_87 ( struct V_17 * V_17 , char * V_159 )
{
if ( F_76 ( V_17 , 0 , V_175 , V_159 ) )
return - 1 ;
return 0 ;
}
static int F_88 ( struct V_17 * V_17 , int V_171 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
int V_172 = V_171 ? V_181 : V_182 ;
unsigned char V_183 = V_171 ? 0x0A : 0x00 ;
unsigned char V_159 [ 4 ] ;
if ( F_70 ( V_128 , V_159 , V_164 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , NULL , V_175 ) ||
F_70 ( V_128 , & V_183 , V_172 ) )
return - 1 ;
if ( F_87 ( V_17 , V_159 ) )
return - 1 ;
return 0 ;
}
static int F_89 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_184 [ sizeof( V_17 -> V_19 ) ] ;
bool V_185 ;
if ( V_2 -> V_29 & V_186 )
F_80 ( V_17 , true ) ;
V_185 = F_70 ( & V_17 -> V_128 , V_184 ,
V_187 | ( V_17 -> V_151 << 8 ) ) < 0 ;
if ( V_2 -> V_29 & V_186 )
F_80 ( V_17 , false ) ;
if ( V_185 || ( V_184 [ 0 ] & V_2 -> V_4 ) != V_2 -> V_5 )
return - 1 ;
if ( ( V_17 -> V_188 & 0xc8 ) == 0x08 ) {
if ( F_70 ( & V_17 -> V_128 , V_184 , V_187 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_17 -> V_19 , V_184 , sizeof( V_184 ) ) ;
return 0 ;
}
static int F_90 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( ( V_2 -> V_29 & V_186 ) &&
F_80 ( V_17 , true ) ) {
return - 1 ;
}
if ( F_88 ( V_17 , true ) ) {
F_24 ( V_17 , L_16 ) ;
return - 1 ;
}
if ( F_82 ( V_17 ) ) {
F_48 ( V_17 , L_17 ) ;
return - 1 ;
}
if ( ( V_2 -> V_29 & V_186 ) &&
F_80 ( V_17 , false ) ) {
return - 1 ;
}
if ( F_70 ( & V_17 -> V_128 , NULL , V_170 ) ) {
F_48 ( V_17 , L_18 ) ;
return - 1 ;
}
return 0 ;
}
static int F_91 ( struct V_17 * V_17 )
{
unsigned char V_159 [ 2 ] = { 0xC8 , 0x14 } ;
if ( F_80 ( V_17 , true ) )
return - 1 ;
if ( F_70 ( & V_17 -> V_128 , NULL , V_174 ) ||
F_70 ( & V_17 -> V_128 , NULL , V_174 ) ||
F_70 ( & V_17 -> V_128 , NULL , V_174 ) ||
F_70 ( & V_17 -> V_128 , & V_159 [ 0 ] , V_181 ) ||
F_70 ( & V_17 -> V_128 , & V_159 [ 1 ] , V_181 ) )
return - 1 ;
if ( F_80 ( V_17 , false ) )
return - 1 ;
if ( F_86 ( V_17 ) ) {
F_48 ( V_17 , L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_92 ( struct V_17 * V_17 ,
int V_189 , bool V_171 )
{
int V_179 , V_180 = - 1 ;
if ( F_78 ( V_17 ) )
return - 1 ;
V_179 = F_73 ( V_17 , V_189 + 0x0008 ) ;
if ( V_179 == - 1 )
goto error;
if ( V_171 )
V_179 |= 0x01 ;
else
V_179 &= ~ 0x01 ;
V_180 = F_74 ( V_17 , V_179 ) ;
error:
if ( F_79 ( V_17 ) )
V_180 = - 1 ;
return V_180 ;
}
static int F_93 ( struct V_17 * V_17 )
{
int V_179 ;
V_179 = F_73 ( V_17 , 0x0004 ) ;
if ( V_179 == - 1 )
return - 1 ;
V_179 |= 0x06 ;
if ( F_74 ( V_17 , V_179 ) )
return - 1 ;
return 0 ;
}
static int F_94 ( struct V_17 * V_17 , int V_189 )
{
int V_180 = - V_168 , V_179 ;
if ( F_78 ( V_17 ) )
goto error;
V_179 = F_73 ( V_17 , V_189 + 0x08 ) ;
if ( V_179 == - 1 )
goto error;
V_180 = V_179 & 0x80 ? 0 : - V_190 ;
error:
F_79 ( V_17 ) ;
return V_180 ;
}
static int F_95 ( struct V_17 * V_17 , int V_189 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
int V_180 = 0 ;
unsigned char V_159 [ 4 ] ;
if ( F_92 ( V_17 , V_189 , true ) )
return - V_168 ;
if ( F_76 ( V_17 , 0 , V_173 , V_159 ) ) {
F_24 ( V_17 , L_19 ) ;
V_180 = - V_190 ;
} else {
F_25 ( V_17 , L_20 , V_159 ) ;
if ( F_70 ( V_128 , NULL , V_174 ) ||
F_70 ( V_128 , NULL , V_174 ) ||
F_70 ( V_128 , NULL , V_174 ) ||
F_68 ( V_17 , 0x9 ) ||
F_68 ( V_17 , 0x4 ) ) {
F_48 ( V_17 ,
L_21 ) ;
V_180 = - V_168 ;
goto error;
}
if ( F_78 ( V_17 ) ||
F_75 ( V_17 ,
V_189 + 0x08 , 0x82 ) ||
F_79 ( V_17 ) )
V_180 = - V_168 ;
}
error:
if ( F_92 ( V_17 , V_189 , false ) )
V_180 = - V_168 ;
return V_180 ;
}
static int F_96 ( struct V_17 * V_17 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
int V_179 ;
unsigned char V_159 [ 4 ] ;
V_179 = F_94 ( V_17 , V_191 ) ;
if ( V_179 == - V_168 )
goto error;
if ( V_179 == 0 &&
F_95 ( V_17 , V_191 ) == - V_168 )
goto error;
if ( F_78 ( V_17 ) ||
F_93 ( V_17 ) ) {
F_48 ( V_17 , L_22 ) ;
goto error;
}
V_179 = F_73 ( V_17 , 0x0006 ) ;
if ( V_179 == - 1 )
goto error;
if ( F_74 ( V_17 , V_179 | 0x01 ) )
goto error;
V_179 = F_73 ( V_17 , 0x0007 ) ;
if ( V_179 == - 1 )
goto error;
if ( F_74 ( V_17 , V_179 | 0x01 ) )
goto error;
if ( F_73 ( V_17 , 0x0144 ) == - 1 )
goto error;
if ( F_74 ( V_17 , 0x04 ) )
goto error;
if ( F_73 ( V_17 , 0x0159 ) == - 1 )
goto error;
if ( F_74 ( V_17 , 0x03 ) )
goto error;
if ( F_73 ( V_17 , 0x0163 ) == - 1 )
goto error;
if ( F_75 ( V_17 , 0x0163 , 0x03 ) )
goto error;
if ( F_73 ( V_17 , 0x0162 ) == - 1 )
goto error;
if ( F_75 ( V_17 , 0x0162 , 0x04 ) )
goto error;
F_79 ( V_17 ) ;
V_159 [ 0 ] = 0x64 ;
if ( F_70 ( V_128 , V_159 , V_181 ) ||
F_70 ( V_128 , NULL , V_176 ) ) {
F_48 ( V_17 , L_23 ) ;
return - 1 ;
}
return 0 ;
error:
F_79 ( V_17 ) ;
return - 1 ;
}
static int F_97 ( struct V_17 * V_17 , int V_192 )
{
int V_193 , V_194 , V_195 , V_196 , V_197 , V_198 , V_199 ;
struct V_1 * V_2 = V_17 -> V_18 ;
V_193 = F_73 ( V_17 , V_192 ) ;
if ( V_193 < 0 )
return V_193 ;
V_194 = ( char ) ( V_193 << 4 ) >> 4 ;
V_194 = 50 + 2 * V_194 ;
V_195 = ( char ) V_193 >> 4 ;
V_195 = 36 + 2 * V_195 ;
V_193 = F_73 ( V_17 , V_192 + 1 ) ;
if ( V_193 < 0 )
return V_193 ;
V_196 = ( char ) ( V_193 << 4 ) >> 4 ;
V_196 = 17 + V_196 ;
V_197 = ( char ) V_193 >> 4 ;
V_197 = 13 + V_197 ;
V_198 = V_194 * ( V_196 - 1 ) ;
V_199 = V_195 * ( V_197 - 1 ) ;
V_2 -> V_200 = V_2 -> V_65 * 10 / V_198 ;
V_2 -> V_201 = V_2 -> V_66 * 10 / V_199 ;
F_25 ( V_17 ,
L_24 ,
V_194 , V_195 , V_196 , V_197 ,
V_198 / 10 , V_199 / 10 , V_2 -> V_200 , V_2 -> V_201 ) ;
return 0 ;
}
static int F_98 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_128 * V_128 = & V_17 -> V_128 ;
int V_179 , V_180 = - 1 ;
if ( V_2 -> V_29 & V_32 ) {
V_179 = F_95 ( V_17 ,
V_202 ) ;
if ( V_179 == - V_168 )
goto error;
}
if ( F_78 ( V_17 ) ||
F_73 ( V_17 , 0xc2d9 ) == - 1 ||
F_75 ( V_17 , 0xc2cb , 0x00 ) )
goto error;
if ( F_97 ( V_17 , 0xc2da ) )
goto error;
V_179 = F_73 ( V_17 , 0xc2c6 ) ;
if ( V_179 == - 1 )
goto error;
if ( F_74 ( V_17 , V_179 & 0xfd ) )
goto error;
if ( F_75 ( V_17 , 0xc2c9 , 0x64 ) )
goto error;
V_179 = F_73 ( V_17 , 0xc2c4 ) ;
if ( V_179 == - 1 )
goto error;
if ( F_74 ( V_17 , V_179 | 0x02 ) )
goto error;
F_79 ( V_17 ) ;
return F_70 ( V_128 , NULL , V_176 ) ;
error:
F_79 ( V_17 ) ;
return V_180 ;
}
static int F_99 ( struct V_17 * V_17 )
{
int V_179 ;
V_179 = F_73 ( V_17 , 0x0004 ) ;
if ( V_179 == - 1 )
return - 1 ;
V_179 |= 0x02 ;
if ( F_74 ( V_17 , V_179 ) )
return - 1 ;
return 0 ;
}
static int F_100 ( struct V_17 * V_17 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
unsigned char V_159 [ 4 ] ;
if ( F_78 ( V_17 ) )
goto error;
if ( F_99 ( V_17 ) ) {
F_48 ( V_17 , L_22 ) ;
goto error;
}
if ( F_75 ( V_17 , 0x0007 , 0x8c ) )
goto error;
if ( F_75 ( V_17 , 0x0149 , 0x03 ) )
goto error;
if ( F_75 ( V_17 , 0x0160 , 0x03 ) )
goto error;
if ( F_75 ( V_17 , 0x017f , 0x15 ) )
goto error;
if ( F_75 ( V_17 , 0x0151 , 0x01 ) )
goto error;
if ( F_75 ( V_17 , 0x0168 , 0x03 ) )
goto error;
if ( F_75 ( V_17 , 0x014a , 0x03 ) )
goto error;
if ( F_75 ( V_17 , 0x0161 , 0x03 ) )
goto error;
F_79 ( V_17 ) ;
V_159 [ 0 ] = 0xc8 ;
V_159 [ 1 ] = 0x64 ;
V_159 [ 2 ] = 0x50 ;
if ( F_70 ( V_128 , & V_159 [ 0 ] , V_181 ) ||
F_70 ( V_128 , & V_159 [ 1 ] , V_181 ) ||
F_70 ( V_128 , & V_159 [ 2 ] , V_181 ) ||
F_70 ( V_128 , V_159 , V_203 ) )
return - 1 ;
V_159 [ 0 ] = 0x64 ;
if ( F_70 ( V_128 , V_159 , V_181 ) ||
F_70 ( V_128 , NULL , V_176 ) ) {
F_48 ( V_17 , L_23 ) ;
return - 1 ;
}
return 0 ;
error:
F_79 ( V_17 ) ;
return - 1 ;
}
static int F_101 ( struct V_17 * V_17 ,
struct V_1 * V_2 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
unsigned char V_159 [ 4 ] = { 0 } ;
int V_204 , V_205 ;
if ( F_78 ( V_17 ) )
return - 1 ;
V_159 [ 0 ] = 0x0a ;
if ( F_70 ( V_128 , NULL , V_169 ) ||
F_70 ( V_128 , NULL , V_177 ) ||
F_70 ( V_128 , NULL , V_177 ) ||
F_70 ( V_128 , & V_159 [ 0 ] , V_181 ) ||
F_70 ( V_128 , & V_159 [ 0 ] , V_181 ) )
return - 1 ;
if ( F_70 ( V_128 , V_159 , V_164 ) )
return - 1 ;
V_204 = V_206 + ( V_159 [ 2 ] & 0x0F ) ;
V_205 = V_207 + ( ( V_159 [ 2 ] >> 4 ) & 0x0F ) ;
V_2 -> V_62 = V_204 ;
V_2 -> V_63 = V_205 ;
V_2 -> V_65 = ( V_204 - 1 ) * V_208 ;
V_2 -> V_66 = ( V_205 - 1 ) * V_208 ;
if ( F_79 ( V_17 ) )
return - 1 ;
return 0 ;
}
static int F_102 ( struct V_17 * V_17 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
unsigned char V_159 [ 2 ] ;
V_159 [ 0 ] = 0x64 ;
V_159 [ 1 ] = 0x28 ;
if ( F_70 ( V_128 , NULL , V_170 ) ||
F_70 ( V_128 , & V_159 [ 0 ] , V_181 ) ||
F_70 ( V_128 , & V_159 [ 1 ] , V_181 ) )
return - 1 ;
return 0 ;
}
static int F_103 ( struct V_17 * V_17 )
{
struct V_128 * V_128 = & V_17 -> V_128 ;
int V_179 , V_180 = - 1 ;
if ( F_78 ( V_17 ) ||
F_73 ( V_17 , 0xc2d9 ) == - 1 )
goto error;
if ( F_97 ( V_17 , 0xc397 ) )
goto error;
if ( F_75 ( V_17 , 0xc2c9 , 0x64 ) )
goto error;
V_179 = F_73 ( V_17 , 0xc2c4 ) ;
if ( V_179 == - 1 )
goto error;
if ( F_74 ( V_17 , V_179 | 0x02 ) )
goto error;
F_79 ( V_17 ) ;
return F_70 ( V_128 , NULL , V_176 ) ;
error:
F_79 ( V_17 ) ;
return V_180 ;
}
static int F_104 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_209 * V_210 )
{
V_17 -> V_18 = V_2 ;
F_105 ( & V_2 -> V_147 , F_64 , ( unsigned long ) V_17 ) ;
V_2 -> V_27 = V_210 -> V_138 ;
V_2 -> V_5 = V_210 -> V_5 ;
V_2 -> V_4 = V_210 -> V_4 ;
V_2 -> V_29 = V_210 -> V_29 ;
V_2 -> V_65 = 2000 ;
V_2 -> V_66 = 1400 ;
V_2 -> V_62 = 15 ;
V_2 -> V_63 = 11 ;
switch ( V_2 -> V_27 ) {
case V_28 :
case V_145 :
V_2 -> V_211 = F_90 ;
V_2 -> V_150 = F_6 ;
V_2 -> V_212 = V_213 ;
V_2 -> V_65 = 1023 ;
V_2 -> V_66 = 767 ;
break;
case V_105 :
V_2 -> V_211 = F_96 ;
V_2 -> V_150 = F_32 ;
V_2 -> V_212 = V_214 ;
V_2 -> V_103 = F_27 ;
V_2 -> V_161 = V_215 ;
V_2 -> V_163 = V_169 ;
break;
case V_84 :
V_2 -> V_211 = F_98 ;
V_2 -> V_150 = F_32 ;
V_2 -> V_212 = V_214 ;
V_2 -> V_103 = F_28 ;
V_2 -> V_161 = V_215 ;
V_2 -> V_163 = V_169 ;
V_2 -> V_62 = 16 ;
V_2 -> V_63 = 12 ;
if ( F_94 ( V_17 ,
V_202 ) < 0 )
V_2 -> V_29 &= ~ V_32 ;
break;
case V_216 :
V_2 -> V_211 = F_100 ;
V_2 -> V_150 = F_34 ;
V_2 -> V_212 = V_214 ;
V_2 -> V_161 = V_217 ;
V_2 -> V_163 = V_175 ;
break;
case V_155 :
V_2 -> V_211 = F_102 ;
V_2 -> V_150 = F_31 ;
V_2 -> V_103 = F_29 ;
V_2 -> V_212 = V_214 ;
V_2 -> V_161 = V_215 ;
V_2 -> V_163 = V_169 ;
V_2 -> V_62 = 23 ;
V_2 -> V_63 = 12 ;
if ( F_101 ( V_17 , V_2 ) )
return - V_168 ;
break;
case V_218 :
V_2 -> V_211 = F_91 ;
V_2 -> V_150 = F_33 ;
V_2 -> V_212 = V_213 ;
V_2 -> V_161 = V_219 ;
V_2 -> V_65 = 2047 ;
V_2 -> V_66 = 1535 ;
break;
case V_156 :
V_2 -> V_211 = F_103 ;
V_2 -> V_150 = F_43 ;
V_2 -> V_103 = F_40 ;
V_2 -> V_212 = V_214 ;
V_2 -> V_161 = V_215 ;
V_2 -> V_163 = V_169 ;
V_2 -> V_65 = 0xfff ;
V_2 -> V_66 = 0x7ff ;
if ( V_2 -> V_220 [ 1 ] != 0xba )
V_2 -> V_29 |= V_119 ;
break;
}
return 0 ;
}
static const struct V_209 * F_106 ( unsigned char * V_221 ,
unsigned char * V_222 )
{
const struct V_223 * V_224 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < F_107 ( V_225 ) ; V_74 ++ ) {
V_224 = & V_225 [ V_74 ] ;
if ( ! memcmp ( V_221 , V_224 -> V_226 , sizeof( V_224 -> V_226 ) ) &&
( ! V_224 -> V_227 ||
V_224 -> V_227 == V_222 [ 2 ] ) ) {
return & V_224 -> V_228 ;
}
}
return NULL ;
}
static int F_108 ( struct V_17 * V_17 , struct V_1 * V_2 )
{
const struct V_209 * V_210 ;
unsigned char V_229 [ 4 ] , V_221 [ 4 ] , V_222 [ 4 ] ;
int error ;
if ( F_76 ( V_17 , V_182 ,
V_174 , V_229 ) )
return - V_168 ;
if ( ( V_229 [ 0 ] & 0xf8 ) != 0 || V_229 [ 1 ] != 0 || ( V_229 [ 2 ] != 10 && V_229 [ 2 ] != 100 ) )
return - V_230 ;
if ( F_76 ( V_17 , V_182 ,
V_173 , V_221 ) ||
F_76 ( V_17 , V_182 ,
V_169 , V_222 ) ||
F_79 ( V_17 ) )
return - V_168 ;
V_210 = F_106 ( V_221 , V_222 ) ;
if ( ! V_210 ) {
if ( V_221 [ 0 ] == 0x73 && V_221 [ 1 ] == 0x03 && V_221 [ 2 ] == 0x50 &&
V_222 [ 0 ] == 0x73 && ( V_222 [ 1 ] == 0x01 || V_222 [ 1 ] == 0x02 ) ) {
V_210 = & V_231 ;
} else if ( V_222 [ 0 ] == 0x88 &&
( ( V_222 [ 1 ] & 0xf0 ) == 0xb0 || ( V_222 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
V_210 = & V_232 ;
} else if ( V_222 [ 0 ] == 0x88 && V_222 [ 1 ] == 0x08 ) {
V_210 = & V_233 ;
} else if ( V_222 [ 0 ] == 0x88 && V_222 [ 1 ] == 0x07 &&
V_222 [ 2 ] >= 0x90 && V_222 [ 2 ] <= 0x9d ) {
V_210 = & V_234 ;
} else {
F_25 ( V_17 ,
L_25 , V_221 , V_222 ) ;
return - V_230 ;
}
}
if ( V_2 ) {
memcpy ( V_2 -> V_220 , V_222 , 3 ) ;
error = F_104 ( V_17 , V_2 , V_210 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_109 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_110 ( V_17 ) ;
if ( F_108 ( V_17 , V_2 ) < 0 )
return - 1 ;
return V_2 -> V_211 ( V_17 ) ;
}
static void F_111 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_110 ( V_17 ) ;
F_112 ( & V_2 -> V_147 ) ;
if ( V_2 -> V_8 )
F_113 ( V_2 -> V_8 ) ;
if ( ! F_57 ( V_2 -> V_123 ) )
F_113 ( V_2 -> V_123 ) ;
F_114 ( V_2 ) ;
}
static void V_213 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_115 ( V_7 , V_36 , 0 , V_2 -> V_65 , 0 , 0 ) ;
F_115 ( V_7 , V_37 , 0 , V_2 -> V_66 , 0 , 0 ) ;
}
static void V_214 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_115 ( V_7 , V_87 , 0 , V_2 -> V_65 , 0 , 0 ) ;
F_115 ( V_7 , V_88 , 0 , V_2 -> V_66 , 0 , 0 ) ;
F_116 ( V_7 , V_87 , V_2 -> V_200 ) ;
F_116 ( V_7 , V_88 , V_2 -> V_201 ) ;
F_117 ( V_7 , V_91 , V_235 |
V_236 | V_237 | V_238 ) ;
F_118 ( V_239 , V_7 -> V_240 ) ;
F_118 ( V_241 , V_7 -> V_240 ) ;
if ( V_2 -> V_27 == V_156 )
F_119 ( V_242 , V_7 -> V_143 ) ;
}
int F_120 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_7 = V_17 -> V_12 ;
int error ;
error = V_2 -> V_211 ( V_17 ) ;
if ( error )
goto V_243;
F_121 ( V_140 , V_7 -> V_244 ) ;
F_121 ( V_33 , V_7 -> V_245 ) ;
F_121 ( V_34 , V_7 -> V_245 ) ;
V_7 -> V_244 [ F_122 ( V_141 ) ] |= F_123 ( V_141 ) ;
V_7 -> V_240 [ F_122 ( V_40 ) ] |= F_123 ( V_40 ) ;
V_7 -> V_240 [ F_122 ( V_39 ) ] |= F_123 ( V_39 ) ;
V_7 -> V_240 [ F_122 ( V_13 ) ] |=
F_123 ( V_13 ) | F_123 ( V_15 ) ;
V_7 -> V_244 [ F_122 ( V_246 ) ] |= F_123 ( V_246 ) ;
V_2 -> V_212 ( V_2 , V_7 ) ;
if ( V_2 -> V_27 != V_156 )
F_115 ( V_7 , V_38 , 0 , 127 , 0 , 0 ) ;
if ( V_2 -> V_29 & V_41 ) {
V_7 -> V_244 [ F_122 ( V_140 ) ] |= F_123 ( V_140 ) ;
V_7 -> V_245 [ F_122 ( V_42 ) ] |= F_123 ( V_42 ) ;
}
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
V_7 -> V_240 [ F_122 ( V_43 ) ] |= F_123 ( V_43 ) ;
V_7 -> V_240 [ F_122 ( V_44 ) ] |= F_123 ( V_44 ) ;
}
if ( V_2 -> V_29 & V_45 ) {
V_7 -> V_240 [ F_122 ( V_46 ) ] |= F_123 ( V_46 ) ;
V_7 -> V_240 [ F_122 ( V_47 ) ] |= F_123 ( V_47 ) ;
V_7 -> V_240 [ F_122 ( V_48 ) ] |= F_123 ( V_48 ) ;
V_7 -> V_240 [ F_122 ( V_49 ) ] |= F_123 ( V_49 ) ;
} else if ( V_2 -> V_29 & V_119 ) {
F_118 ( V_247 , V_7 -> V_143 ) ;
F_119 ( V_15 , V_7 -> V_240 ) ;
} else {
V_7 -> V_240 [ F_122 ( V_16 ) ] |= F_123 ( V_16 ) ;
}
if ( V_2 -> V_29 & V_32 ) {
struct V_6 * V_8 ;
V_8 = F_47 () ;
if ( ! V_8 ) {
F_48 ( V_17 ,
L_26 ) ;
error = - V_126 ;
goto V_243;
}
snprintf ( V_2 -> V_248 , sizeof( V_2 -> V_248 ) , L_27 ,
V_17 -> V_128 . V_129 -> V_130 ) ;
V_8 -> V_130 = V_2 -> V_248 ;
V_8 -> V_131 = L_28 ;
V_8 -> V_132 . V_133 = V_134 ;
V_8 -> V_132 . V_135 = 0x0002 ;
V_8 -> V_132 . V_136 = V_249 ;
V_8 -> V_132 . V_138 = V_2 -> V_27 ;
V_8 -> V_12 . V_139 = & V_17 -> V_128 . V_129 -> V_12 ;
F_49 ( V_8 , V_140 , V_33 ) ;
F_49 ( V_8 , V_140 , V_34 ) ;
F_49 ( V_8 , V_141 , V_13 ) ;
F_49 ( V_8 , V_141 , V_15 ) ;
F_49 ( V_8 , V_141 , V_16 ) ;
F_50 ( V_142 , V_8 -> V_143 ) ;
F_50 ( V_250 , V_8 -> V_143 ) ;
error = F_51 ( V_8 ) ;
if ( error ) {
F_48 ( V_17 ,
L_29 ,
error ) ;
F_52 ( V_8 ) ;
goto V_243;
}
V_2 -> V_8 = V_8 ;
}
V_2 -> V_17 = V_17 ;
F_124 ( & V_2 -> V_122 ,
F_44 ) ;
V_17 -> V_251 = F_67 ;
V_17 -> V_252 = F_89 ;
V_17 -> V_253 = F_111 ;
V_17 -> V_254 = F_109 ;
V_17 -> V_151 = V_2 -> V_27 == V_216 ? 8 : 6 ;
V_17 -> V_255 = 0 ;
V_17 -> V_256 = V_17 -> V_151 * 2 ;
return 0 ;
V_243:
F_110 ( V_17 ) ;
F_114 ( V_17 -> V_18 ) ;
V_17 -> V_18 = NULL ;
return error ;
}
int F_125 ( struct V_17 * V_17 , bool V_257 )
{
struct V_1 * V_2 ;
int error ;
error = F_108 ( V_17 , NULL ) ;
if ( error )
return error ;
F_110 ( V_17 ) ;
V_2 = F_126 ( sizeof( struct V_1 ) , V_258 ) ;
if ( ! V_2 )
return - V_126 ;
error = F_108 ( V_17 , V_2 ) ;
if ( error ) {
F_114 ( V_2 ) ;
return error ;
}
if ( V_257 ) {
V_17 -> V_135 = L_30 ;
V_17 -> V_131 = V_2 -> V_29 & V_32 ?
L_31 : L_32 ;
V_17 -> V_224 = V_2 -> V_27 ;
} else {
F_114 ( V_2 ) ;
V_17 -> V_18 = NULL ;
}
return 0 ;
}
