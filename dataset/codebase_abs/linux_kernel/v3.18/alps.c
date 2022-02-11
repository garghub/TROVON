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
if ( ! ( V_2 -> V_29 & V_84 ) ) {
V_51 -> V_67 [ 0 ] . V_21 = V_2 -> V_66 - V_51 -> V_67 [ 0 ] . V_21 ;
V_51 -> V_67 [ 1 ] . V_21 = V_2 -> V_66 - V_51 -> V_67 [ 1 ] . V_21 ;
}
return V_64 ;
}
static void F_15 ( struct V_7 * V_13 , int V_85 , int V_20 , int V_21 )
{
F_16 ( V_13 , V_85 ) ;
F_17 ( V_13 , V_86 , true ) ;
F_8 ( V_13 , V_87 , V_20 ) ;
F_8 ( V_13 , V_88 , V_21 ) ;
}
static void F_18 ( struct V_6 * V_6 , int V_89 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
int V_74 , V_85 [ V_91 ] ;
F_19 ( V_13 , V_85 , V_90 -> V_67 , V_89 ) ;
for ( V_74 = 0 ; V_74 < V_89 ; V_74 ++ )
F_15 ( V_13 , V_85 [ V_74 ] , V_90 -> V_67 [ V_74 ] . V_20 , V_90 -> V_67 [ V_74 ] . V_21 ) ;
F_20 ( V_13 ) ;
}
static void F_21 ( struct V_6 * V_6 , int V_64 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
if ( V_64 < 2 ) {
V_90 -> V_67 [ 0 ] . V_20 = V_90 -> V_68 . V_20 ;
V_90 -> V_67 [ 0 ] . V_21 = V_90 -> V_68 . V_21 ;
V_64 = V_90 -> V_92 > 0 ? 1 : 0 ;
}
F_18 ( V_6 , ( V_64 <= 2 ) ? V_64 : 2 ) ;
F_22 ( V_13 , V_64 ) ;
F_4 ( V_13 , V_14 , V_90 -> V_10 ) ;
F_4 ( V_13 , V_16 , V_90 -> V_11 ) ;
F_4 ( V_13 , V_17 , V_90 -> V_12 ) ;
F_8 ( V_13 , V_38 , V_90 -> V_92 ) ;
F_5 ( V_13 ) ;
}
static void F_23 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_2 -> V_9 ;
int V_20 , V_21 , V_22 , V_10 , V_11 , V_12 ;
if ( ! ( V_19 [ 0 ] & 0x40 ) ) {
F_24 ( V_6 , L_1 ) ;
return;
}
if ( V_19 [ 1 ] == 0x7f && V_19 [ 2 ] == 0x7f && V_19 [ 4 ] == 0x7f )
return;
V_20 = ( V_93 ) ( ( ( V_19 [ 0 ] & 0x20 ) << 2 ) | ( V_19 [ 1 ] & 0x7f ) ) ;
V_21 = ( V_93 ) ( ( ( V_19 [ 0 ] & 0x10 ) << 3 ) | ( V_19 [ 2 ] & 0x7f ) ) ;
V_22 = ( V_19 [ 4 ] & 0x7c ) >> 2 ;
V_20 /= 8 ;
V_21 /= 8 ;
F_7 ( V_13 , V_33 , V_20 ) ;
F_7 ( V_13 , V_34 , - V_21 ) ;
V_10 = V_19 [ 3 ] & 0x01 ;
V_11 = V_19 [ 3 ] & 0x02 ;
V_12 = V_19 [ 3 ] & 0x04 ;
if ( ! ( V_2 -> V_94 & V_95 ) &&
( V_10 || V_11 || V_12 ) )
V_2 -> V_94 |= V_95 ;
if ( V_2 -> V_94 & V_95 ) {
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_4 ( V_13 , V_17 , V_12 ) ;
}
F_5 ( V_13 ) ;
return;
}
static void F_25 ( struct V_50 * V_90 , unsigned char * V_96 )
{
V_90 -> V_10 = ! ! ( V_96 [ 3 ] & 0x01 ) ;
V_90 -> V_11 = ! ! ( V_96 [ 3 ] & 0x02 ) ;
V_90 -> V_12 = ! ! ( V_96 [ 3 ] & 0x04 ) ;
V_90 -> V_97 = ! ! ( V_96 [ 3 ] & 0x10 ) ;
V_90 -> V_98 = ! ! ( V_96 [ 3 ] & 0x20 ) ;
V_90 -> V_99 = ! ! ( V_96 [ 3 ] & 0x40 ) ;
}
static int F_26 ( struct V_50 * V_90 , unsigned char * V_96 ,
struct V_6 * V_6 )
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
F_25 ( V_90 , V_96 ) ;
return 0 ;
}
static int F_27 ( struct V_50 * V_90 , unsigned char * V_96 ,
struct V_6 * V_6 )
{
F_26 ( V_90 , V_96 , V_6 ) ;
V_90 -> V_101 = ! ! ( V_96 [ 5 ] & 0x40 ) ;
V_90 -> V_64 = F_14 ( ( V_96 [ 5 ] & 0x3 ) , ( ( V_96 [ 5 ] >> 2 ) & 0x3 ) ) + 1 ;
V_90 -> V_54 |= ( V_96 [ 5 ] & 0x10 ) << 11 ;
V_90 -> V_55 |= ( V_96 [ 5 ] & 0x20 ) << 6 ;
return 0 ;
}
static int F_28 ( struct V_50 * V_90 , unsigned char * V_96 ,
struct V_6 * V_6 )
{
T_1 V_102 = 0 ;
struct V_1 * V_2 = V_6 -> V_18 ;
V_90 -> V_100 = ! ! ( V_96 [ 0 ] & 0x02 ) ;
V_90 -> V_101 = ! ! ( V_96 [ 0 ] & 0x20 ) ;
if ( ! V_90 -> V_101 ) {
V_90 -> V_68 . V_20 = ( ( V_96 [ 1 ] & 0x7f ) | ( ( V_96 [ 4 ] & 0x0f ) << 7 ) ) ;
V_90 -> V_68 . V_21 = ( ( V_96 [ 2 ] & 0x7f ) | ( ( V_96 [ 4 ] & 0xf0 ) << 3 ) ) ;
V_90 -> V_92 = ( V_96 [ 0 ] & 4 ) ? 0 : V_96 [ 5 ] & 0x7f ;
F_25 ( V_90 , V_96 ) ;
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
V_90 -> V_55 = V_102 & ( F_29 ( V_2 -> V_63 ) - 1 ) ;
V_90 -> V_54 = ( V_102 >> V_2 -> V_63 ) &
( F_29 ( V_2 -> V_62 ) - 1 ) ;
}
return 0 ;
}
static void F_30 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_9 = V_2 -> V_9 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
int V_64 = 0 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_2 -> V_103 ( V_90 , V_19 , V_6 ) ;
if ( V_2 -> V_104 ) {
if ( V_90 -> V_101 ) {
V_64 = V_90 -> V_64 ;
if ( V_2 -> V_27 == V_105 ) {
if ( F_13 ( V_2 , V_90 ) == 0 )
V_64 = 0 ;
V_2 -> V_103 ( V_90 , V_2 -> V_106 ,
V_6 ) ;
} else {
V_2 -> V_103 ( V_90 , V_2 -> V_106 ,
V_6 ) ;
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
F_21 ( V_6 , V_64 ) ;
if ( ! ( V_2 -> V_94 & V_95 ) ) {
F_4 ( V_9 , V_14 , V_90 -> V_97 ) ;
F_4 ( V_9 , V_16 , V_90 -> V_98 ) ;
F_4 ( V_9 , V_17 , V_90 -> V_99 ) ;
F_5 ( V_9 ) ;
}
}
static void F_31 ( struct V_6 * V_6 )
{
unsigned char * V_19 = V_6 -> V_19 ;
if ( V_19 [ 5 ] == 0x3f ) {
F_23 ( V_6 ) ;
return;
}
F_30 ( V_6 ) ;
}
static void F_32 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_2 -> V_9 ;
int V_20 , V_21 , V_22 , V_10 , V_11 , V_12 ;
if ( V_19 [ 5 ] == 0x7F ) {
if ( ! ( V_2 -> V_29 & V_32 ) )
return;
V_20 = V_19 [ 1 ] | ( ( V_19 [ 3 ] & 0x20 ) << 2 ) ;
V_21 = V_19 [ 2 ] | ( ( V_19 [ 3 ] & 0x40 ) << 1 ) ;
V_22 = V_19 [ 4 ] ;
V_10 = V_19 [ 3 ] & 0x01 ;
V_11 = V_19 [ 3 ] & 0x02 ;
V_12 = V_19 [ 3 ] & 0x04 ;
if ( V_20 == 0x7F && V_21 == 0x7F && V_22 == 0x7F )
V_20 = V_21 = V_22 = 0 ;
F_7 ( V_9 , V_33 , ( char ) V_20 / 4 ) ;
F_7 ( V_9 , V_34 , - ( ( char ) V_21 / 4 ) ) ;
F_4 ( V_9 , V_14 , V_10 ) ;
F_4 ( V_9 , V_16 , V_11 ) ;
F_4 ( V_9 , V_17 , V_12 ) ;
F_5 ( V_9 ) ;
return;
}
V_20 = V_19 [ 1 ] | ( ( V_19 [ 3 ] & 0x78 ) << 4 ) ;
V_21 = V_19 [ 2 ] | ( ( V_19 [ 4 ] & 0x78 ) << 4 ) ;
V_22 = V_19 [ 5 ] ;
V_10 = V_19 [ 3 ] & 0x01 ;
V_11 = V_19 [ 3 ] & 0x02 ;
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
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_5 ( V_13 ) ;
}
static void F_33 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
int V_107 ;
if ( V_19 [ 6 ] & 0x40 ) {
V_2 -> V_104 = 0 ;
}
if ( F_34 ( V_2 -> V_104 > 2 ) )
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
V_90 -> V_10 = ! ! ( V_19 [ 4 ] & 0x01 ) ;
V_90 -> V_11 = ! ! ( V_19 [ 4 ] & 0x02 ) ;
V_90 -> V_68 . V_20 = ( ( V_19 [ 1 ] & 0x7f ) << 4 ) | ( ( V_19 [ 3 ] & 0x30 ) >> 2 ) |
( ( V_19 [ 0 ] & 0x30 ) >> 4 ) ;
V_90 -> V_68 . V_21 = ( ( V_19 [ 2 ] & 0x7f ) << 4 ) | ( V_19 [ 3 ] & 0x0f ) ;
V_90 -> V_92 = V_19 [ 5 ] & 0x7f ;
F_21 ( V_6 , V_90 -> V_64 ) ;
}
static bool F_35 ( struct V_6 * V_6 )
{
switch ( V_6 -> V_108 ) {
case 3 :
return ( V_6 -> V_19 [ 2 ] & 0x40 ) == 0x40 ;
case 4 :
return ( V_6 -> V_19 [ 3 ] & 0x48 ) == 0x48 ;
case 6 :
return ( V_6 -> V_19 [ 5 ] & 0x40 ) == 0x00 ;
}
return true ;
}
static unsigned char F_36 ( char * V_109 )
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
static void F_37 ( struct V_116 * V_67 ,
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
static int F_38 ( struct V_116 * V_67 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_91 && V_67 [ V_74 ] . V_20 != 0 && V_67 [ V_74 ] . V_21 != 0 ; V_74 ++ )
;
return V_74 ;
}
static int F_39 ( struct V_50 * V_90 ,
unsigned char * V_96 ,
struct V_6 * V_6 )
{
unsigned char V_118 ;
V_118 = F_36 ( V_96 ) ;
if ( V_118 == V_114 )
return 0 ;
if ( V_118 == V_115 )
return - 1 ;
F_37 ( V_90 -> V_67 , V_96 , V_118 ) ;
if ( V_118 == V_111 || V_118 == V_112 ) {
V_90 -> V_10 = ( V_96 [ 0 ] & 0x80 ) >> 7 ;
V_90 -> V_11 = ( V_96 [ 0 ] & 0x20 ) >> 5 ;
V_90 -> V_12 = ( V_96 [ 0 ] & 0x10 ) >> 4 ;
}
if ( V_118 == V_111 )
V_90 -> V_64 = F_38 ( V_90 -> V_67 ) ;
else if ( V_118 == V_112 )
V_90 -> V_64 = 3 + ( V_96 [ 5 ] & 0x03 ) ;
return 0 ;
}
static void F_40 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_9 = V_2 -> V_9 ;
int V_20 , V_21 , V_22 , V_10 , V_11 , V_12 ;
V_20 = ( ( V_19 [ 2 ] & 0xbf ) ) | ( ( V_19 [ 3 ] & 0x10 ) << 2 ) ;
V_21 = ( V_19 [ 3 ] & 0x07 ) | ( V_19 [ 4 ] & 0xb8 ) |
( ( V_19 [ 3 ] & 0x20 ) << 1 ) ;
V_22 = ( V_19 [ 5 ] & 0x3f ) | ( ( V_19 [ 3 ] & 0x80 ) >> 1 ) ;
V_10 = ( V_19 [ 1 ] & 0x01 ) ;
V_11 = ( V_19 [ 1 ] & 0x02 ) >> 1 ;
V_12 = ( V_19 [ 1 ] & 0x04 ) >> 2 ;
F_7 ( V_9 , V_33 , ( char ) V_20 / 2 ) ;
F_7 ( V_9 , V_34 , - ( ( char ) V_21 / 2 ) ) ;
F_4 ( V_9 , V_14 , V_10 ) ;
F_4 ( V_9 , V_16 , V_11 ) ;
F_4 ( V_9 , V_17 , V_12 ) ;
F_5 ( V_9 ) ;
}
static void F_41 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_50 * V_90 = & V_2 -> V_90 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
if ( V_2 -> V_103 ( V_90 , V_6 -> V_19 , V_6 ) )
return;
F_18 ( V_6 , F_38 ( V_90 -> V_67 ) ) ;
F_22 ( V_13 , V_90 -> V_64 ) ;
F_4 ( V_13 , V_14 , V_90 -> V_10 ) ;
F_4 ( V_13 , V_16 , V_90 -> V_11 ) ;
F_4 ( V_13 , V_17 , V_90 -> V_12 ) ;
F_5 ( V_13 ) ;
}
static void F_42 ( struct V_6 * V_6 )
{
unsigned char * V_19 = V_6 -> V_19 ;
if ( V_19 [ 0 ] == 0x48 && ( V_19 [ 4 ] & 0x47 ) == 0x06 )
F_40 ( V_6 ) ;
else
F_41 ( V_6 ) ;
}
static void F_43 ( struct V_6 * V_6 ,
unsigned char V_19 [] ,
bool V_119 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_7 * V_9 = V_2 -> V_9 ;
if ( V_119 )
F_2 ( V_6 , V_9 , V_6 -> V_13 ,
V_19 [ 0 ] & 1 , V_19 [ 0 ] & 2 , V_19 [ 0 ] & 4 ) ;
F_7 ( V_9 , V_33 ,
V_19 [ 1 ] ? V_19 [ 1 ] - ( ( V_19 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_9 , V_34 ,
V_19 [ 2 ] ? ( ( V_19 [ 0 ] << 3 ) & 0x100 ) - V_19 [ 2 ] : 0 ) ;
F_5 ( V_9 ) ;
}
static T_2 F_44 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( V_6 -> V_108 < 6 )
return V_120 ;
if ( V_6 -> V_108 == 6 ) {
F_45 ( & V_2 -> V_121 , V_122 + F_46 ( 20 ) ) ;
return V_120 ;
}
F_47 ( & V_2 -> V_121 ) ;
if ( V_6 -> V_19 [ 6 ] & 0x80 ) {
if ( ( ( V_6 -> V_19 [ 3 ] |
V_6 -> V_19 [ 4 ] |
V_6 -> V_19 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_2 , V_6 -> V_19 [ 6 ] ) ) ) {
F_24 ( V_6 ,
L_2 ,
V_6 -> V_19 + 3 ) ;
return V_123 ;
}
V_2 -> V_124 ( V_6 ) ;
V_6 -> V_19 [ 0 ] = V_6 -> V_19 [ 6 ] ;
V_6 -> V_108 = 1 ;
} else {
F_43 ( V_6 , & V_6 -> V_19 [ 3 ] ,
false ) ;
V_6 -> V_19 [ 3 ] = V_6 -> V_19 [ 6 ] & 0xf7 ;
V_6 -> V_108 = 4 ;
}
return V_120 ;
}
static void F_48 ( unsigned long V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_1 * V_2 = V_6 -> V_18 ;
F_49 ( V_6 -> V_125 . V_126 ) ;
if ( V_6 -> V_108 == V_6 -> V_127 ) {
if ( ( V_6 -> V_19 [ 3 ] |
V_6 -> V_19 [ 4 ] |
V_6 -> V_19 [ 5 ] ) & 0x80 ) {
F_24 ( V_6 ,
L_3 ,
V_6 -> V_19 + 3 ) ;
} else {
V_2 -> V_124 ( V_6 ) ;
}
V_6 -> V_108 = 0 ;
}
F_50 ( V_6 -> V_125 . V_126 ) ;
}
static T_2 F_51 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( ! V_6 -> V_128 && ( V_6 -> V_19 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_6 -> V_108 == 3 ) {
F_43 ( V_6 , V_6 -> V_19 ,
true ) ;
return V_129 ;
}
return V_120 ;
}
if ( ( V_2 -> V_29 & V_130 ) &&
V_6 -> V_108 >= 4 && ( V_6 -> V_19 [ 3 ] & 0x0f ) == 0x0f ) {
return F_44 ( V_6 ) ;
}
if ( ! F_1 ( V_2 , V_6 -> V_19 [ 0 ] ) ) {
F_24 ( V_6 ,
L_4 ,
V_6 -> V_19 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_123 ;
}
if ( V_2 -> V_27 < V_131 &&
V_6 -> V_108 >= 2 && V_6 -> V_108 <= V_6 -> V_127 &&
( V_6 -> V_19 [ V_6 -> V_108 - 1 ] & 0x80 ) ) {
F_24 ( V_6 , L_5 ,
V_6 -> V_108 - 1 ,
V_6 -> V_19 [ V_6 -> V_108 - 1 ] ) ;
if ( V_2 -> V_27 == V_105 &&
V_6 -> V_108 == V_6 -> V_127 ) {
return V_129 ;
}
return V_123 ;
}
if ( V_2 -> V_27 == V_132 &&
! F_35 ( V_6 ) ) {
F_24 ( V_6 , L_5 ,
V_6 -> V_108 - 1 ,
V_6 -> V_19 [ V_6 -> V_108 - 1 ] ) ;
return V_123 ;
}
if ( V_6 -> V_108 == V_6 -> V_127 ) {
V_2 -> V_124 ( V_6 ) ;
return V_129 ;
}
return V_120 ;
}
static int F_52 ( struct V_6 * V_6 , int V_133 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
struct V_1 * V_2 = V_6 -> V_18 ;
int V_134 ;
unsigned char * V_135 ;
unsigned char V_136 [ 4 ] ;
F_53 ( V_133 > 0xf ) ;
V_134 = V_2 -> V_137 [ V_133 ] . V_134 ;
V_135 = ( V_134 & 0x0f00 ) ?
V_136 : ( unsigned char * ) & V_2 -> V_137 [ V_133 ] . V_3 ;
if ( F_54 ( V_125 , V_135 , V_134 ) )
return - 1 ;
return 0 ;
}
static int F_55 ( struct V_6 * V_6 , int V_138 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
struct V_1 * V_2 = V_6 -> V_18 ;
int V_74 , V_133 ;
if ( F_54 ( V_125 , NULL , V_2 -> V_139 ) )
return - 1 ;
for ( V_74 = 12 ; V_74 >= 0 ; V_74 -= 4 ) {
V_133 = ( V_138 >> V_74 ) & 0xf ;
if ( F_52 ( V_6 , V_133 ) )
return - 1 ;
}
return 0 ;
}
static int F_56 ( struct V_6 * V_6 , int V_138 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
unsigned char V_135 [ 4 ] ;
if ( F_54 ( V_125 , V_135 , V_140 ) )
return - 1 ;
if ( V_138 != ( ( V_135 [ 0 ] << 8 ) | V_135 [ 1 ] ) )
return - 1 ;
return V_135 [ 2 ] ;
}
static int F_57 ( struct V_6 * V_6 , int V_138 )
{
if ( F_55 ( V_6 , V_138 ) )
return - 1 ;
return F_56 ( V_6 , V_138 ) ;
}
static int F_58 ( struct V_6 * V_6 , T_3 V_141 )
{
if ( F_52 ( V_6 , ( V_141 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_52 ( V_6 , V_141 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_59 ( struct V_6 * V_6 , int V_138 ,
T_3 V_141 )
{
if ( F_55 ( V_6 , V_138 ) )
return - 1 ;
return F_58 ( V_6 , V_141 ) ;
}
static int F_60 ( struct V_6 * V_6 , int V_142 ,
int V_143 , unsigned char * V_135 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
V_135 [ 0 ] = 0 ;
if ( V_142 && F_54 ( V_125 , V_135 , V_142 ) )
return - V_144 ;
if ( F_54 ( V_125 , NULL , V_143 ) ||
F_54 ( V_125 , NULL , V_143 ) ||
F_54 ( V_125 , NULL , V_143 ) )
return - V_144 ;
V_135 [ 0 ] = V_135 [ 1 ] = V_135 [ 2 ] = 0xff ;
if ( F_54 ( V_125 , V_135 , V_140 ) )
return - V_144 ;
F_24 ( V_6 , L_6 ,
V_143 , V_135 ) ;
return 0 ;
}
static bool F_61 ( unsigned char V_145 [] )
{
if ( V_145 [ 0 ] == 0x73 )
return true ;
if ( V_145 [ 0 ] == 0x88 &&
( V_145 [ 1 ] == 0x07 ||
V_145 [ 1 ] == 0x08 ||
( V_145 [ 1 ] & 0xf0 ) == 0xb0 ||
( V_145 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
return true ;
}
return false ;
}
static int F_62 ( struct V_6 * V_6 )
{
unsigned char V_135 [ 4 ] ;
if ( F_60 ( V_6 , 0 , V_146 , V_135 ) ) {
F_63 ( V_6 , L_7 ) ;
return - 1 ;
}
if ( ! F_61 ( V_135 ) ) {
F_24 ( V_6 ,
L_8 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_64 ( struct V_6 * V_6 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
if ( F_54 ( V_125 , NULL , V_147 ) )
return - 1 ;
return 0 ;
}
static int F_65 ( struct V_6 * V_6 , bool V_148 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
int V_149 = V_148 ? V_150 : V_151 ;
if ( F_54 ( V_125 , NULL , V_149 ) ||
F_54 ( V_125 , NULL , V_149 ) ||
F_54 ( V_125 , NULL , V_149 ) ||
F_54 ( V_125 , NULL , V_152 ) )
return - 1 ;
F_66 ( V_125 , 3 , 100 ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_6 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
if ( F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_153 ) )
return - 1 ;
return F_54 ( & V_6 -> V_125 , NULL , V_154 ) ;
}
static int F_68 ( struct V_6 * V_6 , T_4 V_155 )
{
int V_74 , V_133 ;
for ( V_74 = 0 ; V_74 <= 8 ; V_74 += 4 ) {
V_133 = ( V_155 >> V_74 ) & 0xf ;
if ( F_52 ( V_6 , V_133 ) )
return - 1 ;
}
return 0 ;
}
static int F_69 ( struct V_6 * V_6 ,
T_4 V_138 , T_4 V_141 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
if ( F_54 ( V_125 , NULL , V_153 ) ||
F_68 ( V_6 , 0x0A0 ) ||
F_68 ( V_6 , V_138 ) ||
F_68 ( V_6 , V_141 ) ||
F_54 ( V_125 , NULL , V_152 ) )
return - 1 ;
return 0 ;
}
static int F_70 ( struct V_6 * V_6 , bool V_148 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
if ( V_148 ) {
if ( F_54 ( V_125 , NULL , V_146 ) ||
F_54 ( V_125 , NULL , V_140 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_150 ) ||
F_54 ( V_125 , NULL , V_151 ) ||
F_54 ( V_125 , NULL , V_150 ) ||
F_54 ( V_125 , NULL , V_140 ) )
return - 1 ;
} else {
if ( F_54 ( V_125 , NULL , V_146 ) )
return - 1 ;
}
return 0 ;
}
static int F_71 ( struct V_6 * V_6 )
{
T_4 V_156 = 0x181 ;
int V_157 = - 1 ;
if ( F_70 ( V_6 , true ) )
return - 1 ;
V_157 = F_69 ( V_6 , 0x000 , V_156 ) ;
if ( F_70 ( V_6 , false ) )
V_157 = - 1 ;
return V_157 ;
}
static int F_72 ( struct V_6 * V_6 , char * V_135 )
{
if ( F_60 ( V_6 , 0 , V_152 , V_135 ) )
return - 1 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_6 , int V_148 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
int V_149 = V_148 ? V_158 : V_159 ;
unsigned char V_160 = V_148 ? 0x0A : 0x00 ;
unsigned char V_135 [ 4 ] ;
if ( F_54 ( V_125 , V_135 , V_140 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , NULL , V_152 ) ||
F_54 ( V_125 , & V_160 , V_149 ) )
return - 1 ;
if ( F_72 ( V_6 , V_135 ) )
return - 1 ;
return 0 ;
}
static int F_74 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char V_161 [ sizeof( V_6 -> V_19 ) ] ;
bool V_162 ;
if ( V_2 -> V_29 & V_163 )
F_65 ( V_6 , true ) ;
V_162 = F_54 ( & V_6 -> V_125 , V_161 ,
V_164 | ( V_6 -> V_127 << 8 ) ) < 0 ;
if ( V_2 -> V_29 & V_163 )
F_65 ( V_6 , false ) ;
if ( V_162 || ( V_161 [ 0 ] & V_2 -> V_4 ) != V_2 -> V_5 )
return - 1 ;
if ( ( V_6 -> V_165 & 0xc8 ) == 0x08 ) {
if ( F_54 ( & V_6 -> V_125 , V_161 , V_164 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_6 -> V_19 , V_161 , sizeof( V_161 ) ) ;
return 0 ;
}
static int F_75 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( ( V_2 -> V_29 & V_163 ) &&
F_65 ( V_6 , true ) ) {
return - 1 ;
}
if ( F_73 ( V_6 , true ) ) {
F_76 ( V_6 , L_9 ) ;
return - 1 ;
}
if ( F_67 ( V_6 ) ) {
F_63 ( V_6 , L_10 ) ;
return - 1 ;
}
if ( ( V_2 -> V_29 & V_163 ) &&
F_65 ( V_6 , false ) ) {
return - 1 ;
}
if ( F_54 ( & V_6 -> V_125 , NULL , V_147 ) ) {
F_63 ( V_6 , L_11 ) ;
return - 1 ;
}
return 0 ;
}
static int F_77 ( struct V_6 * V_6 )
{
unsigned char V_135 [ 2 ] = { 0xC8 , 0x14 } ;
if ( F_65 ( V_6 , true ) )
return - 1 ;
if ( F_54 ( & V_6 -> V_125 , NULL , V_151 ) ||
F_54 ( & V_6 -> V_125 , NULL , V_151 ) ||
F_54 ( & V_6 -> V_125 , NULL , V_151 ) ||
F_54 ( & V_6 -> V_125 , & V_135 [ 0 ] , V_158 ) ||
F_54 ( & V_6 -> V_125 , & V_135 [ 1 ] , V_158 ) )
return - 1 ;
if ( F_65 ( V_6 , false ) )
return - 1 ;
if ( F_71 ( V_6 ) ) {
F_63 ( V_6 , L_10 ) ;
return - 1 ;
}
return 0 ;
}
static int F_78 ( struct V_6 * V_6 ,
int V_166 , bool V_148 )
{
int V_156 , V_157 = - 1 ;
if ( F_62 ( V_6 ) )
return - 1 ;
V_156 = F_57 ( V_6 , V_166 + 0x0008 ) ;
if ( V_156 == - 1 )
goto error;
if ( V_148 )
V_156 |= 0x01 ;
else
V_156 &= ~ 0x01 ;
V_157 = F_58 ( V_6 , V_156 ) ;
error:
if ( F_64 ( V_6 ) )
V_157 = - 1 ;
return V_157 ;
}
static int F_79 ( struct V_6 * V_6 )
{
int V_156 ;
V_156 = F_57 ( V_6 , 0x0004 ) ;
if ( V_156 == - 1 )
return - 1 ;
V_156 |= 0x06 ;
if ( F_58 ( V_6 , V_156 ) )
return - 1 ;
return 0 ;
}
static int F_80 ( struct V_6 * V_6 , int V_166 )
{
int V_157 = - V_144 , V_156 ;
if ( F_62 ( V_6 ) )
goto error;
V_156 = F_57 ( V_6 , V_166 + 0x08 ) ;
if ( V_156 == - 1 )
goto error;
V_157 = V_156 & 0x80 ? 0 : - V_167 ;
error:
F_64 ( V_6 ) ;
return V_157 ;
}
static int F_81 ( struct V_6 * V_6 , int V_166 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
int V_157 = 0 ;
unsigned char V_135 [ 4 ] ;
if ( F_78 ( V_6 , V_166 , true ) )
return - V_144 ;
if ( F_60 ( V_6 , 0 , V_150 , V_135 ) ) {
F_76 ( V_6 , L_12 ) ;
V_157 = - V_167 ;
} else {
F_24 ( V_6 , L_13 , V_135 ) ;
if ( F_54 ( V_125 , NULL , V_151 ) ||
F_54 ( V_125 , NULL , V_151 ) ||
F_54 ( V_125 , NULL , V_151 ) ||
F_52 ( V_6 , 0x9 ) ||
F_52 ( V_6 , 0x4 ) ) {
F_63 ( V_6 ,
L_14 ) ;
V_157 = - V_144 ;
goto error;
}
if ( F_62 ( V_6 ) ||
F_59 ( V_6 ,
V_166 + 0x08 , 0x82 ) ||
F_64 ( V_6 ) )
V_157 = - V_144 ;
}
error:
if ( F_78 ( V_6 , V_166 , false ) )
V_157 = - V_144 ;
return V_157 ;
}
static int F_82 ( struct V_6 * V_6 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
int V_156 ;
unsigned char V_135 [ 4 ] ;
V_156 = F_80 ( V_6 , V_168 ) ;
if ( V_156 == - V_144 )
goto error;
if ( V_156 == 0 &&
F_81 ( V_6 , V_168 ) == - V_144 )
goto error;
if ( F_62 ( V_6 ) ||
F_79 ( V_6 ) ) {
F_63 ( V_6 , L_15 ) ;
goto error;
}
V_156 = F_57 ( V_6 , 0x0006 ) ;
if ( V_156 == - 1 )
goto error;
if ( F_58 ( V_6 , V_156 | 0x01 ) )
goto error;
V_156 = F_57 ( V_6 , 0x0007 ) ;
if ( V_156 == - 1 )
goto error;
if ( F_58 ( V_6 , V_156 | 0x01 ) )
goto error;
if ( F_57 ( V_6 , 0x0144 ) == - 1 )
goto error;
if ( F_58 ( V_6 , 0x04 ) )
goto error;
if ( F_57 ( V_6 , 0x0159 ) == - 1 )
goto error;
if ( F_58 ( V_6 , 0x03 ) )
goto error;
if ( F_57 ( V_6 , 0x0163 ) == - 1 )
goto error;
if ( F_59 ( V_6 , 0x0163 , 0x03 ) )
goto error;
if ( F_57 ( V_6 , 0x0162 ) == - 1 )
goto error;
if ( F_59 ( V_6 , 0x0162 , 0x04 ) )
goto error;
F_64 ( V_6 ) ;
V_135 [ 0 ] = 0x64 ;
if ( F_54 ( V_125 , V_135 , V_158 ) ||
F_54 ( V_125 , NULL , V_153 ) ) {
F_63 ( V_6 , L_16 ) ;
return - 1 ;
}
return 0 ;
error:
F_64 ( V_6 ) ;
return - 1 ;
}
static int F_83 ( struct V_6 * V_6 , int V_169 )
{
int V_170 , V_171 , V_172 , V_173 , V_174 , V_175 , V_176 ;
struct V_1 * V_2 = V_6 -> V_18 ;
V_170 = F_57 ( V_6 , V_169 ) ;
if ( V_170 < 0 )
return V_170 ;
V_171 = ( char ) ( V_170 << 4 ) >> 4 ;
V_171 = 50 + 2 * V_171 ;
V_172 = ( char ) V_170 >> 4 ;
V_172 = 36 + 2 * V_172 ;
V_170 = F_57 ( V_6 , V_169 + 1 ) ;
if ( V_170 < 0 )
return V_170 ;
V_173 = ( char ) ( V_170 << 4 ) >> 4 ;
V_173 = 17 + V_173 ;
V_174 = ( char ) V_170 >> 4 ;
V_174 = 13 + V_174 ;
V_175 = V_171 * ( V_173 - 1 ) ;
V_176 = V_172 * ( V_174 - 1 ) ;
V_2 -> V_177 = V_2 -> V_65 * 10 / V_175 ;
V_2 -> V_178 = V_2 -> V_66 * 10 / V_176 ;
F_24 ( V_6 ,
L_17 ,
V_171 , V_172 , V_173 , V_174 ,
V_175 / 10 , V_176 / 10 , V_2 -> V_177 , V_2 -> V_178 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_125 * V_125 = & V_6 -> V_125 ;
int V_156 , V_157 = - 1 ;
if ( V_2 -> V_29 & V_32 ) {
V_156 = F_81 ( V_6 ,
V_179 ) ;
if ( V_156 == - V_144 )
goto error;
if ( V_156 == - V_167 )
V_2 -> V_29 &= ~ V_32 ;
}
if ( F_62 ( V_6 ) ||
F_57 ( V_6 , 0xc2d9 ) == - 1 ||
F_59 ( V_6 , 0xc2cb , 0x00 ) )
goto error;
if ( F_83 ( V_6 , 0xc2da ) )
goto error;
V_156 = F_57 ( V_6 , 0xc2c6 ) ;
if ( V_156 == - 1 )
goto error;
if ( F_58 ( V_6 , V_156 & 0xfd ) )
goto error;
if ( F_59 ( V_6 , 0xc2c9 , 0x64 ) )
goto error;
V_156 = F_57 ( V_6 , 0xc2c4 ) ;
if ( V_156 == - 1 )
goto error;
if ( F_58 ( V_6 , V_156 | 0x02 ) )
goto error;
F_64 ( V_6 ) ;
return F_54 ( V_125 , NULL , V_153 ) ;
error:
F_64 ( V_6 ) ;
return V_157 ;
}
static int F_85 ( struct V_6 * V_6 )
{
int V_156 ;
V_156 = F_57 ( V_6 , 0x0004 ) ;
if ( V_156 == - 1 )
return - 1 ;
V_156 |= 0x02 ;
if ( F_58 ( V_6 , V_156 ) )
return - 1 ;
return 0 ;
}
static int F_86 ( struct V_6 * V_6 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
unsigned char V_135 [ 4 ] ;
if ( F_62 ( V_6 ) )
goto error;
if ( F_85 ( V_6 ) ) {
F_63 ( V_6 , L_15 ) ;
goto error;
}
if ( F_59 ( V_6 , 0x0007 , 0x8c ) )
goto error;
if ( F_59 ( V_6 , 0x0149 , 0x03 ) )
goto error;
if ( F_59 ( V_6 , 0x0160 , 0x03 ) )
goto error;
if ( F_59 ( V_6 , 0x017f , 0x15 ) )
goto error;
if ( F_59 ( V_6 , 0x0151 , 0x01 ) )
goto error;
if ( F_59 ( V_6 , 0x0168 , 0x03 ) )
goto error;
if ( F_59 ( V_6 , 0x014a , 0x03 ) )
goto error;
if ( F_59 ( V_6 , 0x0161 , 0x03 ) )
goto error;
F_64 ( V_6 ) ;
V_135 [ 0 ] = 0xc8 ;
V_135 [ 1 ] = 0x64 ;
V_135 [ 2 ] = 0x50 ;
if ( F_54 ( V_125 , & V_135 [ 0 ] , V_158 ) ||
F_54 ( V_125 , & V_135 [ 1 ] , V_158 ) ||
F_54 ( V_125 , & V_135 [ 2 ] , V_158 ) ||
F_54 ( V_125 , V_135 , V_180 ) )
return - 1 ;
V_135 [ 0 ] = 0x64 ;
if ( F_54 ( V_125 , V_135 , V_158 ) ||
F_54 ( V_125 , NULL , V_153 ) ) {
F_63 ( V_6 , L_16 ) ;
return - 1 ;
}
return 0 ;
error:
F_64 ( V_6 ) ;
return - 1 ;
}
static int F_87 ( struct V_6 * V_6 ,
struct V_1 * V_2 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
unsigned char V_135 [ 4 ] = { 0 } ;
int V_181 , V_182 ;
if ( F_62 ( V_6 ) )
return - 1 ;
V_135 [ 0 ] = 0x0a ;
if ( F_54 ( V_125 , NULL , V_146 ) ||
F_54 ( V_125 , NULL , V_154 ) ||
F_54 ( V_125 , NULL , V_154 ) ||
F_54 ( V_125 , & V_135 [ 0 ] , V_158 ) ||
F_54 ( V_125 , & V_135 [ 0 ] , V_158 ) )
return - 1 ;
if ( F_54 ( V_125 , V_135 , V_140 ) )
return - 1 ;
V_181 = V_183 + ( V_135 [ 2 ] & 0x0F ) ;
V_182 = V_184 + ( ( V_135 [ 2 ] >> 4 ) & 0x0F ) ;
V_2 -> V_62 = V_181 ;
V_2 -> V_63 = V_182 ;
V_2 -> V_65 = ( V_181 - 1 ) * V_185 ;
V_2 -> V_66 = ( V_182 - 1 ) * V_185 ;
if ( F_64 ( V_6 ) )
return - 1 ;
return 0 ;
}
static int F_88 ( struct V_6 * V_6 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
unsigned char V_135 [ 2 ] ;
V_135 [ 0 ] = 0x64 ;
V_135 [ 1 ] = 0x28 ;
if ( F_54 ( V_125 , NULL , V_147 ) ||
F_54 ( V_125 , & V_135 [ 0 ] , V_158 ) ||
F_54 ( V_125 , & V_135 [ 1 ] , V_158 ) )
return - 1 ;
return 0 ;
}
static int F_89 ( struct V_6 * V_6 )
{
struct V_125 * V_125 = & V_6 -> V_125 ;
int V_156 , V_157 = - 1 ;
if ( F_62 ( V_6 ) ||
F_57 ( V_6 , 0xc2d9 ) == - 1 )
goto error;
if ( F_83 ( V_6 , 0xc397 ) )
goto error;
if ( F_59 ( V_6 , 0xc2c9 , 0x64 ) )
goto error;
V_156 = F_57 ( V_6 , 0xc2c4 ) ;
if ( V_156 == - 1 )
goto error;
if ( F_58 ( V_6 , V_156 | 0x02 ) )
goto error;
F_64 ( V_6 ) ;
return F_54 ( V_125 , NULL , V_153 ) ;
error:
F_64 ( V_6 ) ;
return V_157 ;
}
static void F_90 ( struct V_1 * V_2 )
{
V_2 -> V_5 = 0x8f ;
V_2 -> V_4 = 0x8f ;
V_2 -> V_29 = V_32 ;
V_2 -> V_65 = 2000 ;
V_2 -> V_66 = 1400 ;
V_2 -> V_62 = 15 ;
V_2 -> V_63 = 11 ;
switch ( V_2 -> V_27 ) {
case V_28 :
case V_186 :
V_2 -> V_187 = F_75 ;
V_2 -> V_124 = F_6 ;
V_2 -> V_188 = V_189 ;
V_2 -> V_65 = 1023 ;
V_2 -> V_66 = 767 ;
break;
case V_105 :
V_2 -> V_187 = F_82 ;
V_2 -> V_124 = F_31 ;
V_2 -> V_188 = V_190 ;
V_2 -> V_103 = F_26 ;
V_2 -> V_137 = V_191 ;
V_2 -> V_139 = V_146 ;
break;
case V_192 :
V_2 -> V_187 = F_86 ;
V_2 -> V_124 = F_33 ;
V_2 -> V_188 = V_190 ;
V_2 -> V_137 = V_193 ;
V_2 -> V_139 = V_152 ;
break;
case V_131 :
V_2 -> V_187 = F_88 ;
V_2 -> V_124 = F_30 ;
V_2 -> V_103 = F_28 ;
V_2 -> V_188 = V_190 ;
V_2 -> V_137 = V_191 ;
V_2 -> V_139 = V_146 ;
V_2 -> V_5 = 0xc8 ;
V_2 -> V_4 = 0xd8 ;
V_2 -> V_29 = 0 ;
V_2 -> V_65 = 1360 ;
V_2 -> V_66 = 660 ;
V_2 -> V_62 = 23 ;
V_2 -> V_63 = 12 ;
break;
case V_194 :
V_2 -> V_187 = F_77 ;
V_2 -> V_124 = F_32 ;
V_2 -> V_188 = V_189 ;
V_2 -> V_137 = V_195 ;
V_2 -> V_65 = 2047 ;
V_2 -> V_66 = 1535 ;
break;
case V_132 :
V_2 -> V_187 = F_89 ;
V_2 -> V_124 = F_42 ;
V_2 -> V_103 = F_39 ;
V_2 -> V_188 = V_190 ;
V_2 -> V_137 = V_191 ;
V_2 -> V_139 = V_146 ;
V_2 -> V_65 = 0xfff ;
V_2 -> V_66 = 0x7ff ;
V_2 -> V_5 = 0x48 ;
V_2 -> V_4 = 0x48 ;
if ( V_2 -> V_196 [ 1 ] != 0xba )
V_2 -> V_29 |= V_197 ;
break;
}
}
static int F_91 ( struct V_6 * V_6 , struct V_1 * V_2 ,
unsigned char * V_198 , unsigned char * V_199 )
{
const struct V_200 * V_201 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < F_92 ( V_202 ) ; V_74 ++ ) {
V_201 = & V_202 [ V_74 ] ;
if ( ! memcmp ( V_198 , V_201 -> V_203 , sizeof( V_201 -> V_203 ) ) &&
( ! V_201 -> V_204 ||
V_201 -> V_204 == V_199 [ 2 ] ) ) {
V_2 -> V_27 = V_201 -> V_27 ;
F_90 ( V_2 ) ;
V_2 -> V_29 = V_201 -> V_29 ;
V_2 -> V_5 = V_201 -> V_5 ;
V_2 -> V_4 = V_201 -> V_4 ;
return 0 ;
}
}
return - V_205 ;
}
static int F_93 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
unsigned char V_206 [ 4 ] , V_198 [ 4 ] , V_199 [ 4 ] ;
if ( F_60 ( V_6 , V_159 ,
V_151 , V_206 ) )
return - V_144 ;
if ( ( V_206 [ 0 ] & 0xf8 ) != 0 || V_206 [ 1 ] != 0 || ( V_206 [ 2 ] != 10 && V_206 [ 2 ] != 100 ) )
return - V_205 ;
if ( F_60 ( V_6 , V_159 ,
V_150 , V_198 ) ||
F_60 ( V_6 , V_159 ,
V_146 , V_199 ) ||
F_64 ( V_6 ) )
return - V_144 ;
memcpy ( V_2 -> V_196 , V_199 , 3 ) ;
if ( F_91 ( V_6 , V_2 , V_198 , V_199 ) == 0 ) {
return 0 ;
} else if ( V_198 [ 0 ] == 0x73 && V_198 [ 1 ] == 0x03 && V_198 [ 2 ] == 0x50 &&
V_199 [ 0 ] == 0x73 && ( V_199 [ 1 ] == 0x01 || V_199 [ 1 ] == 0x02 ) ) {
V_2 -> V_27 = V_131 ;
F_90 ( V_2 ) ;
if ( F_87 ( V_6 , V_2 ) )
return - V_144 ;
else
return 0 ;
} else if ( V_199 [ 0 ] == 0x88 &&
( ( V_199 [ 1 ] & 0xf0 ) == 0xb0 || ( V_199 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
V_2 -> V_27 = V_132 ;
F_90 ( V_2 ) ;
return 0 ;
} else if ( V_199 [ 0 ] == 0x88 && V_199 [ 1 ] == 0x08 ) {
V_2 -> V_27 = V_105 ;
F_90 ( V_2 ) ;
V_2 -> V_187 = F_84 ;
V_2 -> V_103 = F_27 ;
V_2 -> V_62 = 16 ;
V_2 -> V_63 = 12 ;
V_2 -> V_29 |= V_84 ;
V_6 -> V_18 = V_2 ;
if ( F_80 ( V_6 , V_179 ) )
V_2 -> V_29 &= ~ V_32 ;
return 0 ;
} else if ( V_199 [ 0 ] == 0x88 && V_199 [ 1 ] == 0x07 &&
V_199 [ 2 ] >= 0x90 && V_199 [ 2 ] <= 0x9d ) {
V_2 -> V_27 = V_105 ;
F_90 ( V_2 ) ;
return 0 ;
}
F_24 ( V_6 ,
L_18 , V_198 , V_199 ) ;
return - V_205 ;
}
static int F_94 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
F_95 ( V_6 ) ;
if ( F_93 ( V_6 , V_2 ) < 0 )
return - 1 ;
return V_2 -> V_187 ( V_6 ) ;
}
static void F_96 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
F_95 ( V_6 ) ;
F_97 ( & V_2 -> V_121 ) ;
F_98 ( V_2 -> V_9 ) ;
F_99 ( V_2 ) ;
}
static void V_189 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_100 ( V_8 , V_36 , 0 , V_2 -> V_65 , 0 , 0 ) ;
F_100 ( V_8 , V_37 , 0 , V_2 -> V_66 , 0 , 0 ) ;
}
static void V_190 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_100 ( V_8 , V_87 , 0 , V_2 -> V_65 , 0 , 0 ) ;
F_100 ( V_8 , V_88 , 0 , V_2 -> V_66 , 0 , 0 ) ;
F_101 ( V_8 , V_87 , V_2 -> V_177 ) ;
F_101 ( V_8 , V_88 , V_2 -> V_178 ) ;
F_102 ( V_8 , V_91 , V_207 |
V_208 | V_209 | V_210 ) ;
F_103 ( V_211 , V_8 -> V_212 ) ;
F_103 ( V_213 , V_8 -> V_212 ) ;
if ( V_2 -> V_27 == V_132 )
F_104 ( V_214 , V_8 -> V_215 ) ;
}
int F_105 ( struct V_6 * V_6 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_6 -> V_13 , * V_9 ;
V_2 = F_106 ( sizeof( struct V_1 ) , V_216 ) ;
V_9 = F_107 () ;
if ( ! V_2 || ! V_9 )
goto V_217;
V_2 -> V_9 = V_9 ;
F_108 ( & V_2 -> V_121 , F_48 , ( unsigned long ) V_6 ) ;
V_6 -> V_18 = V_2 ;
F_95 ( V_6 ) ;
if ( F_93 ( V_6 , V_2 ) < 0 )
goto V_217;
if ( V_2 -> V_187 ( V_6 ) )
goto V_217;
F_109 ( V_218 , V_8 -> V_219 ) ;
F_109 ( V_33 , V_8 -> V_220 ) ;
F_109 ( V_34 , V_8 -> V_220 ) ;
V_8 -> V_219 [ F_110 ( V_221 ) ] |= F_111 ( V_221 ) ;
V_8 -> V_212 [ F_110 ( V_40 ) ] |= F_111 ( V_40 ) ;
V_8 -> V_212 [ F_110 ( V_39 ) ] |= F_111 ( V_39 ) ;
V_8 -> V_212 [ F_110 ( V_14 ) ] |=
F_111 ( V_14 ) | F_111 ( V_16 ) ;
V_8 -> V_219 [ F_110 ( V_222 ) ] |= F_111 ( V_222 ) ;
V_2 -> V_188 ( V_2 , V_8 ) ;
if ( V_2 -> V_27 != V_132 )
F_100 ( V_8 , V_38 , 0 , 127 , 0 , 0 ) ;
if ( V_2 -> V_29 & V_41 ) {
V_8 -> V_219 [ F_110 ( V_218 ) ] |= F_111 ( V_218 ) ;
V_8 -> V_220 [ F_110 ( V_42 ) ] |= F_111 ( V_42 ) ;
}
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
V_8 -> V_212 [ F_110 ( V_43 ) ] |= F_111 ( V_43 ) ;
V_8 -> V_212 [ F_110 ( V_44 ) ] |= F_111 ( V_44 ) ;
}
if ( V_2 -> V_29 & V_45 ) {
V_8 -> V_212 [ F_110 ( V_46 ) ] |= F_111 ( V_46 ) ;
V_8 -> V_212 [ F_110 ( V_47 ) ] |= F_111 ( V_47 ) ;
V_8 -> V_212 [ F_110 ( V_48 ) ] |= F_111 ( V_48 ) ;
V_8 -> V_212 [ F_110 ( V_49 ) ] |= F_111 ( V_49 ) ;
} else if ( V_2 -> V_29 & V_197 ) {
F_103 ( V_223 , V_8 -> V_215 ) ;
F_104 ( V_16 , V_8 -> V_212 ) ;
} else {
V_8 -> V_212 [ F_110 ( V_17 ) ] |= F_111 ( V_17 ) ;
}
snprintf ( V_2 -> V_224 , sizeof( V_2 -> V_224 ) , L_19 , V_6 -> V_125 . V_126 -> V_224 ) ;
V_9 -> V_224 = V_2 -> V_224 ;
V_9 -> V_225 = ( V_2 -> V_29 & V_32 ) ?
L_20 : L_21 ;
V_9 -> V_145 . V_226 = V_227 ;
V_9 -> V_145 . V_228 = 0x0002 ;
V_9 -> V_145 . V_229 = V_230 ;
V_9 -> V_145 . V_231 = 0x0000 ;
V_9 -> V_13 . V_232 = & V_6 -> V_125 . V_126 -> V_13 ;
V_9 -> V_219 [ 0 ] = F_111 ( V_221 ) | F_111 ( V_218 ) ;
V_9 -> V_220 [ F_110 ( V_33 ) ] = F_111 ( V_33 ) | F_111 ( V_34 ) ;
V_9 -> V_212 [ F_110 ( V_14 ) ] =
F_111 ( V_14 ) | F_111 ( V_17 ) | F_111 ( V_16 ) ;
F_112 ( V_233 , V_9 -> V_215 ) ;
if ( V_2 -> V_29 & V_32 )
F_112 ( V_234 , V_9 -> V_215 ) ;
if ( F_113 ( V_2 -> V_9 ) )
goto V_217;
V_6 -> V_235 = F_51 ;
V_6 -> V_236 = F_74 ;
V_6 -> V_237 = F_96 ;
V_6 -> V_238 = F_94 ;
V_6 -> V_127 = V_2 -> V_27 == V_192 ? 8 : 6 ;
V_6 -> V_239 = 0 ;
V_6 -> V_240 = V_6 -> V_127 * 2 ;
return 0 ;
V_217:
F_95 ( V_6 ) ;
F_114 ( V_9 ) ;
F_99 ( V_2 ) ;
V_6 -> V_18 = NULL ;
return - 1 ;
}
int F_115 ( struct V_6 * V_6 , bool V_241 )
{
struct V_1 V_136 ;
if ( F_93 ( V_6 , & V_136 ) < 0 )
return - 1 ;
if ( V_241 ) {
V_6 -> V_228 = L_22 ;
V_6 -> V_225 = V_136 . V_29 & V_32 ?
L_23 : L_24 ;
V_6 -> V_201 = V_136 . V_27 << 8 ;
}
return 0 ;
}
