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
if ( V_2 -> V_29 & V_35 ) {
V_9 |= V_19 [ 0 ] & 1 ;
V_10 |= V_19 [ 0 ] & 2 ;
V_11 |= V_19 [ 0 ] & 4 ;
}
F_2 ( V_12 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_23 && ! V_24 )
V_22 = 40 ;
if ( V_23 && V_24 && ! V_2 -> V_36 ) {
F_8 ( V_12 , V_37 , V_20 ) ;
F_8 ( V_12 , V_38 , V_21 ) ;
F_8 ( V_12 , V_39 , 0 ) ;
F_4 ( V_12 , V_40 , 0 ) ;
F_5 ( V_12 ) ;
}
V_2 -> V_36 = V_24 ;
if ( V_22 > 30 )
F_4 ( V_12 , V_41 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_12 , V_41 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_12 , V_37 , V_20 ) ;
F_8 ( V_12 , V_38 , V_21 ) ;
}
F_8 ( V_12 , V_39 , V_22 ) ;
F_4 ( V_12 , V_40 , V_22 > 0 ) ;
if ( V_2 -> V_29 & V_42 )
F_7 ( V_12 , V_43 , ( ( V_19 [ 2 ] << 1 ) & 0x08 ) - ( ( V_19 [ 0 ] >> 4 ) & 0x07 ) ) ;
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
F_4 ( V_12 , V_44 , V_26 ) ;
F_4 ( V_12 , V_45 , V_25 ) ;
}
if ( V_2 -> V_29 & V_46 ) {
F_4 ( V_12 , V_47 , V_19 [ 2 ] & 4 ) ;
F_4 ( V_12 , V_48 , V_19 [ 0 ] & 0x10 ) ;
F_4 ( V_12 , V_49 , V_19 [ 3 ] & 4 ) ;
F_4 ( V_12 , V_50 , V_19 [ 0 ] & 0x20 ) ;
}
F_5 ( V_12 ) ;
}
static void F_9 ( unsigned int V_51 ,
struct V_52 * V_53 ,
struct V_52 * V_54 ,
int * V_55 )
{
struct V_52 * V_56 ;
int V_57 , V_58 , V_59 = 0 ;
V_56 = V_53 ;
for ( V_57 = 0 ; V_51 != 0 ; V_57 ++ , V_51 >>= 1 ) {
V_58 = V_51 & 1 ;
if ( V_58 ) {
if ( ! V_59 ) {
V_56 -> V_60 = V_57 ;
V_56 -> V_61 = 0 ;
( * V_55 ) ++ ;
}
V_56 -> V_61 ++ ;
} else {
if ( V_59 )
V_56 = V_54 ;
}
V_59 = V_58 ;
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
int V_57 , V_64 = 0 , V_65 = 0 , V_55 , V_66 ;
struct V_52 V_67 = { 0 ,} , V_68 = { 0 ,} ;
struct V_52 V_69 = { 0 ,} , V_70 = { 0 ,} ;
struct V_71 V_72 [ 4 ] ;
if ( ! V_63 -> V_73 || ! V_63 -> V_74 )
return 0 ;
F_9 ( V_63 -> V_73 , & V_67 , & V_68 , & V_64 ) ;
F_9 ( V_63 -> V_74 , & V_69 , & V_70 , & V_65 ) ;
V_55 = F_11 ( V_64 , V_65 ) ;
if ( V_64 == 1 ) {
V_57 = ( V_67 . V_61 - 1 ) / 2 ;
V_67 . V_61 = V_67 . V_61 - V_57 ;
V_68 . V_60 = V_67 . V_60 + V_57 ;
V_68 . V_61 = F_11 ( V_57 , 1 ) ;
}
if ( V_65 == 1 ) {
V_57 = ( V_69 . V_61 - 1 ) / 2 ;
V_69 . V_61 = V_69 . V_61 - V_57 ;
V_70 . V_60 = V_69 . V_60 + V_57 ;
V_70 . V_61 = F_11 ( V_57 , 1 ) ;
}
V_72 [ 0 ] . V_20 =
( V_2 -> V_75 * ( 2 * V_67 . V_60 + V_67 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_76 - 1 ) ) ;
V_72 [ 0 ] . V_21 =
( V_2 -> V_77 * ( 2 * V_69 . V_60 + V_69 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_78 - 1 ) ) ;
V_72 [ 1 ] . V_20 =
( V_2 -> V_75 * ( 2 * V_68 . V_60 + V_68 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_76 - 1 ) ) ;
V_72 [ 1 ] . V_21 =
( V_2 -> V_77 * ( 2 * V_69 . V_60 + V_69 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_78 - 1 ) ) ;
V_72 [ 2 ] . V_20 =
( V_2 -> V_75 * ( 2 * V_68 . V_60 + V_68 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_76 - 1 ) ) ;
V_72 [ 2 ] . V_21 =
( V_2 -> V_77 * ( 2 * V_70 . V_60 + V_70 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_78 - 1 ) ) ;
V_72 [ 3 ] . V_20 =
( V_2 -> V_75 * ( 2 * V_67 . V_60 + V_67 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_76 - 1 ) ) ;
V_72 [ 3 ] . V_21 =
( V_2 -> V_77 * ( 2 * V_70 . V_60 + V_70 . V_61 - 1 ) ) /
( 2 * ( V_2 -> V_78 - 1 ) ) ;
if ( V_2 -> V_27 == V_79 ) {
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ )
V_72 [ V_57 ] . V_20 = V_2 -> V_75 - V_72 [ V_57 ] . V_20 ;
}
if ( V_2 -> V_27 == V_80 ||
V_2 -> V_27 == V_81 ) {
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ )
V_72 [ V_57 ] . V_21 = V_2 -> V_77 - V_72 [ V_57 ] . V_21 ;
}
if ( V_2 -> V_82 == - 1 ) {
V_66 = 0x7fffffff ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
int V_83 = V_63 -> V_84 . V_20 - V_72 [ V_57 ] . V_20 ;
int V_85 = V_63 -> V_84 . V_21 - V_72 [ V_57 ] . V_21 ;
int V_86 = V_83 * V_83 + V_85 * V_85 ;
if ( V_86 < V_66 ) {
V_2 -> V_82 = V_57 ;
V_66 = V_86 ;
}
}
V_2 -> V_82 = ( V_2 -> V_82 + 2 ) % 4 ;
}
V_63 -> V_87 [ 0 ] = V_63 -> V_84 ;
V_63 -> V_87 [ 1 ] = V_72 [ V_2 -> V_82 ] ;
return V_55 ;
}
static void F_12 ( struct V_6 * V_12 , int V_88 , int V_20 , int V_21 )
{
F_13 ( V_12 , V_88 ) ;
F_14 ( V_12 , V_89 , true ) ;
F_8 ( V_12 , V_90 , V_20 ) ;
F_8 ( V_12 , V_91 , V_21 ) ;
}
static void F_15 ( struct V_17 * V_17 , int V_92 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_62 * V_93 = & V_2 -> V_93 ;
int V_57 , V_88 [ V_94 ] ;
F_16 ( V_12 , V_88 , V_93 -> V_87 , V_92 , 0 ) ;
for ( V_57 = 0 ; V_57 < V_92 ; V_57 ++ )
F_12 ( V_12 , V_88 [ V_57 ] , V_93 -> V_87 [ V_57 ] . V_20 , V_93 -> V_87 [ V_57 ] . V_21 ) ;
F_17 ( V_12 ) ;
}
static void F_18 ( struct V_17 * V_17 , int V_55 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_62 * V_93 = & V_2 -> V_93 ;
if ( V_55 < 2 ) {
V_93 -> V_87 [ 0 ] . V_20 = V_93 -> V_84 . V_20 ;
V_93 -> V_87 [ 0 ] . V_21 = V_93 -> V_84 . V_21 ;
V_55 = V_93 -> V_95 > 0 ? 1 : 0 ;
V_2 -> V_82 = - 1 ;
}
if ( V_55 >= 1 )
F_12 ( V_12 , 0 , V_93 -> V_87 [ 0 ] . V_20 , V_93 -> V_87 [ 0 ] . V_21 ) ;
if ( V_55 >= 2 )
F_12 ( V_12 , 1 , V_93 -> V_87 [ 1 ] . V_20 , V_93 -> V_87 [ 1 ] . V_21 ) ;
F_17 ( V_12 ) ;
F_19 ( V_12 , V_55 ) ;
F_4 ( V_12 , V_13 , V_93 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_93 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_93 -> V_11 ) ;
F_8 ( V_12 , V_39 , V_93 -> V_95 ) ;
F_5 ( V_12 ) ;
}
static void F_20 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_9 , V_10 , V_11 ;
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_21 ( V_17 ,
L_1 ) ;
return;
}
if ( ! ( V_19 [ 0 ] & 0x40 ) ) {
F_22 ( V_17 , L_2 ) ;
return;
}
if ( V_19 [ 1 ] == 0x7f && V_19 [ 2 ] == 0x7f && V_19 [ 4 ] == 0x7f )
return;
V_20 = ( V_96 ) ( ( ( V_19 [ 0 ] & 0x20 ) << 2 ) | ( V_19 [ 1 ] & 0x7f ) ) ;
V_21 = ( V_96 ) ( ( ( V_19 [ 0 ] & 0x10 ) << 3 ) | ( V_19 [ 2 ] & 0x7f ) ) ;
V_22 = ( V_19 [ 4 ] & 0x7c ) >> 2 ;
V_20 /= 8 ;
V_21 /= 8 ;
F_7 ( V_12 , V_33 , V_20 ) ;
F_7 ( V_12 , V_34 , - V_21 ) ;
V_9 = V_19 [ 3 ] & 0x01 ;
V_10 = V_19 [ 3 ] & 0x02 ;
V_11 = V_19 [ 3 ] & 0x04 ;
if ( ! ( V_2 -> V_97 & V_98 ) &&
( V_9 || V_10 || V_11 ) )
V_2 -> V_97 |= V_98 ;
if ( V_2 -> V_97 & V_98 ) {
F_4 ( V_12 , V_13 , V_9 ) ;
F_4 ( V_12 , V_15 , V_10 ) ;
F_4 ( V_12 , V_16 , V_11 ) ;
}
F_5 ( V_12 ) ;
return;
}
static void F_23 ( struct V_62 * V_93 , unsigned char * V_99 )
{
V_93 -> V_9 = ! ! ( V_99 [ 3 ] & 0x01 ) ;
V_93 -> V_10 = ! ! ( V_99 [ 3 ] & 0x02 ) ;
V_93 -> V_11 = ! ! ( V_99 [ 3 ] & 0x04 ) ;
V_93 -> V_100 = ! ! ( V_99 [ 3 ] & 0x10 ) ;
V_93 -> V_101 = ! ! ( V_99 [ 3 ] & 0x20 ) ;
V_93 -> V_102 = ! ! ( V_99 [ 3 ] & 0x40 ) ;
}
static int F_24 ( struct V_62 * V_93 , unsigned char * V_99 ,
struct V_17 * V_17 )
{
V_93 -> V_103 = ! ! ( V_99 [ 4 ] & 0x40 ) ;
V_93 -> V_104 = ! ! ( V_99 [ 0 ] & 0x40 ) ;
if ( V_93 -> V_104 ) {
V_93 -> V_55 = ( V_99 [ 5 ] & 0x3 ) + 1 ;
V_93 -> V_73 = ( ( V_99 [ 4 ] & 0x7e ) << 8 ) |
( ( V_99 [ 1 ] & 0x7f ) << 2 ) |
( ( V_99 [ 0 ] & 0x30 ) >> 4 ) ;
V_93 -> V_74 = ( ( V_99 [ 3 ] & 0x70 ) << 4 ) |
( ( V_99 [ 2 ] & 0x7f ) << 1 ) |
( V_99 [ 4 ] & 0x01 ) ;
} else {
V_93 -> V_84 . V_20 = ( ( V_99 [ 1 ] & 0x7f ) << 4 ) | ( ( V_99 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_99 [ 0 ] & 0x30 ) >> 4 ) ;
V_93 -> V_84 . V_21 = ( ( V_99 [ 2 ] & 0x7f ) << 4 ) | ( V_99 [ 4 ] & 0x0f ) ;
V_93 -> V_95 = V_99 [ 5 ] & 0x7f ;
F_23 ( V_93 , V_99 ) ;
}
return 0 ;
}
static int F_25 ( struct V_62 * V_93 , unsigned char * V_99 ,
struct V_17 * V_17 )
{
V_93 -> V_103 = ! ! ( V_99 [ 4 ] & 0x40 ) ;
V_93 -> V_104 = ! ! ( V_99 [ 5 ] & 0x40 ) ;
if ( V_93 -> V_104 ) {
V_93 -> V_55 = F_11 ( ( V_99 [ 5 ] & 0x3 ) , ( ( V_99 [ 5 ] >> 2 ) & 0x3 ) ) + 1 ;
V_93 -> V_73 = ( ( V_99 [ 5 ] & 0x10 ) << 11 ) |
( ( V_99 [ 4 ] & 0x7e ) << 8 ) |
( ( V_99 [ 1 ] & 0x7f ) << 2 ) |
( ( V_99 [ 0 ] & 0x30 ) >> 4 ) ;
V_93 -> V_74 = ( ( V_99 [ 5 ] & 0x20 ) << 6 ) |
( ( V_99 [ 3 ] & 0x70 ) << 4 ) |
( ( V_99 [ 2 ] & 0x7f ) << 1 ) |
( V_99 [ 4 ] & 0x01 ) ;
} else {
V_93 -> V_84 . V_20 = ( ( V_99 [ 1 ] & 0x7f ) << 4 ) | ( ( V_99 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_99 [ 0 ] & 0x30 ) >> 4 ) ;
V_93 -> V_84 . V_21 = ( ( V_99 [ 2 ] & 0x7f ) << 4 ) | ( V_99 [ 4 ] & 0x0f ) ;
V_93 -> V_95 = V_99 [ 5 ] & 0x7f ;
F_23 ( V_93 , V_99 ) ;
}
return 0 ;
}
static int F_26 ( struct V_62 * V_93 , unsigned char * V_99 ,
struct V_17 * V_17 )
{
T_1 V_105 = 0 ;
struct V_1 * V_2 = V_17 -> V_18 ;
V_93 -> V_103 = ! ! ( V_99 [ 0 ] & 0x02 ) ;
V_93 -> V_104 = ! ! ( V_99 [ 0 ] & 0x20 ) ;
if ( ! V_93 -> V_104 ) {
V_93 -> V_84 . V_20 = ( ( V_99 [ 1 ] & 0x7f ) | ( ( V_99 [ 4 ] & 0x0f ) << 7 ) ) ;
V_93 -> V_84 . V_21 = ( ( V_99 [ 2 ] & 0x7f ) | ( ( V_99 [ 4 ] & 0xf0 ) << 3 ) ) ;
V_93 -> V_95 = ( V_99 [ 0 ] & 4 ) ? 0 : V_99 [ 5 ] & 0x7f ;
F_23 ( V_93 , V_99 ) ;
} else {
V_93 -> V_55 = ( ( V_99 [ 0 ] & 0x6 ) >> 1 |
( V_99 [ 0 ] & 0x10 ) >> 2 ) ;
V_105 = ( V_99 [ 1 ] & 0x7f ) |
( ( V_99 [ 2 ] & 0x7f ) << 7 ) |
( ( V_99 [ 4 ] & 0x7f ) << 14 ) |
( ( V_99 [ 5 ] & 0x7f ) << 21 ) |
( ( V_99 [ 3 ] & 0x07 ) << 28 ) |
( ( ( T_1 ) V_99 [ 3 ] & 0x70 ) << 27 ) |
( ( ( T_1 ) V_99 [ 0 ] & 0x01 ) << 34 ) ;
V_93 -> V_74 = V_105 & ( F_27 ( V_2 -> V_78 ) - 1 ) ;
V_93 -> V_73 = ( V_105 >> V_2 -> V_78 ) &
( F_27 ( V_2 -> V_76 ) - 1 ) ;
}
return 0 ;
}
static void F_28 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_8 = V_2 -> V_8 ;
struct V_62 * V_93 = & V_2 -> V_93 ;
int V_55 = 0 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_2 -> V_106 ( V_93 , V_19 , V_17 ) ;
if ( V_2 -> V_107 ) {
if ( V_93 -> V_104 ) {
V_55 = V_93 -> V_55 ;
V_2 -> V_106 ( V_93 , V_2 -> V_108 , V_17 ) ;
if ( F_10 ( V_2 , V_93 ) == 0 )
V_55 = 0 ;
} else {
V_2 -> V_107 = 0 ;
}
}
if ( V_93 -> V_104 )
return;
if ( ! V_2 -> V_107 && V_93 -> V_103 ) {
V_2 -> V_107 = 1 ;
memcpy ( V_2 -> V_108 , V_19 , sizeof( V_2 -> V_108 ) ) ;
return;
}
V_2 -> V_107 = 0 ;
if ( V_93 -> V_84 . V_20 && V_93 -> V_84 . V_21 && ! V_93 -> V_95 )
return;
F_18 ( V_17 , V_55 ) ;
if ( ( V_2 -> V_29 & V_32 ) &&
! ( V_2 -> V_97 & V_98 ) ) {
F_4 ( V_8 , V_13 , V_93 -> V_100 ) ;
F_4 ( V_8 , V_15 , V_93 -> V_101 ) ;
F_4 ( V_8 , V_16 , V_93 -> V_102 ) ;
F_5 ( V_8 ) ;
}
}
static void F_29 ( struct V_17 * V_17 )
{
unsigned char * V_19 = V_17 -> V_19 ;
if ( V_19 [ 5 ] == 0x3f ) {
F_20 ( V_17 ) ;
return;
}
F_28 ( V_17 ) ;
}
static void F_30 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_6 * V_8 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_9 , V_10 , V_11 ;
if ( V_19 [ 5 ] == 0x7F ) {
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_21 ( V_17 ,
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
F_4 ( V_12 , V_41 , 1 ) ;
if ( V_22 < 25 )
F_4 ( V_12 , V_41 , 0 ) ;
if ( V_22 > 0 ) {
F_8 ( V_12 , V_37 , V_20 ) ;
F_8 ( V_12 , V_38 , V_21 ) ;
}
F_8 ( V_12 , V_39 , V_22 ) ;
F_4 ( V_12 , V_40 , V_22 > 0 ) ;
F_4 ( V_12 , V_13 , V_9 ) ;
F_4 ( V_12 , V_15 , V_10 ) ;
F_5 ( V_12 ) ;
}
static void F_31 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_62 * V_93 = & V_2 -> V_93 ;
int V_109 ;
if ( V_19 [ 6 ] & 0x40 ) {
V_2 -> V_107 = 0 ;
}
if ( F_32 ( V_2 -> V_107 > 2 ) )
return;
V_109 = 2 * V_2 -> V_107 ;
V_2 -> V_108 [ V_109 ] = V_19 [ 6 ] ;
V_2 -> V_108 [ V_109 + 1 ] = V_19 [ 7 ] ;
V_93 -> V_9 = ! ! ( V_19 [ 4 ] & 0x01 ) ;
V_93 -> V_10 = ! ! ( V_19 [ 4 ] & 0x02 ) ;
V_93 -> V_84 . V_20 = ( ( V_19 [ 1 ] & 0x7f ) << 4 ) | ( ( V_19 [ 3 ] & 0x30 ) >> 2 ) |
( ( V_19 [ 0 ] & 0x30 ) >> 4 ) ;
V_93 -> V_84 . V_21 = ( ( V_19 [ 2 ] & 0x7f ) << 4 ) | ( V_19 [ 3 ] & 0x0f ) ;
V_93 -> V_95 = V_19 [ 5 ] & 0x7f ;
if ( ++ V_2 -> V_107 > 2 ) {
V_2 -> V_107 = 0 ;
V_93 -> V_73 = ( ( V_2 -> V_108 [ 2 ] & 0x1f ) << 10 ) |
( ( V_2 -> V_108 [ 3 ] & 0x60 ) << 3 ) |
( ( V_2 -> V_108 [ 0 ] & 0x3f ) << 2 ) |
( ( V_2 -> V_108 [ 1 ] & 0x60 ) >> 5 ) ;
V_93 -> V_74 = ( ( V_2 -> V_108 [ 5 ] & 0x01 ) << 10 ) |
( ( V_2 -> V_108 [ 3 ] & 0x1f ) << 5 ) |
( V_2 -> V_108 [ 1 ] & 0x1f ) ;
V_93 -> V_55 = F_10 ( V_2 , V_93 ) ;
}
F_18 ( V_17 , V_93 -> V_55 ) ;
}
static bool F_33 ( struct V_17 * V_17 )
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
static unsigned char F_34 ( char * V_111 )
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
static void F_35 ( struct V_71 * V_87 ,
unsigned char * V_118 ,
unsigned char V_119 )
{
V_87 [ 0 ] . V_20 = ( ( V_118 [ 2 ] & 0x80 ) << 4 ) ;
V_87 [ 0 ] . V_20 |= ( ( V_118 [ 2 ] & 0x3F ) << 5 ) ;
V_87 [ 0 ] . V_20 |= ( ( V_118 [ 3 ] & 0x30 ) >> 1 ) ;
V_87 [ 0 ] . V_20 |= ( V_118 [ 3 ] & 0x07 ) ;
V_87 [ 0 ] . V_21 = ( V_118 [ 1 ] << 3 ) | ( V_118 [ 0 ] & 0x07 ) ;
V_87 [ 1 ] . V_20 = ( ( V_118 [ 3 ] & 0x80 ) << 4 ) ;
V_87 [ 1 ] . V_20 |= ( ( V_118 [ 4 ] & 0x80 ) << 3 ) ;
V_87 [ 1 ] . V_20 |= ( ( V_118 [ 4 ] & 0x3F ) << 4 ) ;
V_87 [ 1 ] . V_21 = ( ( V_118 [ 5 ] & 0x80 ) << 3 ) ;
V_87 [ 1 ] . V_21 |= ( ( V_118 [ 5 ] & 0x3F ) << 4 ) ;
switch ( V_119 ) {
case V_113 :
V_87 [ 1 ] . V_20 &= ~ 0x000F ;
V_87 [ 1 ] . V_21 |= 0x000F ;
if ( V_87 [ 1 ] . V_21 == 0x7ff && V_87 [ 1 ] . V_20 == 0xff0 ) {
V_87 [ 1 ] . V_20 = 0 ;
}
break;
case V_114 :
V_87 [ 1 ] . V_20 &= ~ 0x003F ;
V_87 [ 1 ] . V_21 &= ~ 0x0020 ;
V_87 [ 1 ] . V_21 |= ( ( V_118 [ 4 ] & 0x02 ) << 4 ) ;
V_87 [ 1 ] . V_21 |= 0x001F ;
break;
case V_115 :
V_87 [ 1 ] . V_20 &= ~ 0x003F ;
V_87 [ 1 ] . V_20 |= ( V_118 [ 0 ] & 0x20 ) ;
V_87 [ 1 ] . V_21 |= 0x000F ;
break;
}
V_87 [ 0 ] . V_21 = 0x7FF - V_87 [ 0 ] . V_21 ;
V_87 [ 1 ] . V_21 = 0x7FF - V_87 [ 1 ] . V_21 ;
}
static int F_36 ( struct V_71 * V_87 )
{
int V_57 , V_55 = 0 ;
for ( V_57 = 0 ; V_57 < V_94 ; V_57 ++ ) {
if ( V_87 [ V_57 ] . V_20 != 0 || V_87 [ V_57 ] . V_21 != 0 )
V_55 ++ ;
}
return V_55 ;
}
static int F_37 ( struct V_62 * V_93 ,
unsigned char * V_99 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_119 ;
V_119 = F_34 ( V_99 ) ;
if ( V_119 == V_116 )
return 0 ;
if ( V_119 == V_117 )
return - 1 ;
if ( V_119 == V_115 )
return 1 ;
F_35 ( V_93 -> V_87 , V_99 , V_119 ) ;
if ( V_119 == V_113 )
V_93 -> V_55 = F_36 ( V_93 -> V_87 ) ;
else
V_93 -> V_55 = 3 + ( V_99 [ 5 ] & 0x03 ) ;
V_93 -> V_9 = ( V_99 [ 0 ] & 0x80 ) >> 7 ;
if ( V_2 -> V_29 & V_120 ) {
if ( V_99 [ 0 ] & 0x20 )
V_93 -> V_55 ++ ;
if ( V_99 [ 0 ] & 0x10 )
V_93 -> V_55 ++ ;
} else {
V_93 -> V_10 = ( V_99 [ 0 ] & 0x20 ) >> 5 ;
V_93 -> V_11 = ( V_99 [ 0 ] & 0x10 ) >> 4 ;
}
if ( V_93 -> V_55 == 1 && V_93 -> V_87 [ 0 ] . V_20 == 0 && V_93 -> V_87 [ 0 ] . V_21 == 0 ) {
V_93 -> V_87 [ 0 ] . V_20 = V_93 -> V_87 [ 1 ] . V_20 ;
V_93 -> V_87 [ 0 ] . V_21 = V_93 -> V_87 [ 1 ] . V_21 ;
V_93 -> V_87 [ 1 ] . V_20 = 0 ;
V_93 -> V_87 [ 1 ] . V_21 = 0 ;
}
return 0 ;
}
static void F_38 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_8 = V_2 -> V_8 ;
int V_20 , V_21 , V_22 , V_9 , V_10 , V_11 ;
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_21 ( V_17 ,
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
static void F_39 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_62 * V_93 = & V_2 -> V_93 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
if ( V_2 -> V_106 ( V_93 , V_17 -> V_19 , V_17 ) )
return;
F_15 ( V_17 , F_36 ( V_93 -> V_87 ) ) ;
F_19 ( V_12 , V_93 -> V_55 ) ;
F_4 ( V_12 , V_13 , V_93 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_93 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_93 -> V_11 ) ;
F_5 ( V_12 ) ;
}
static void F_40 ( struct V_17 * V_17 )
{
unsigned char * V_19 = V_17 -> V_19 ;
if ( V_19 [ 0 ] == 0x48 && ( V_19 [ 4 ] & 0x47 ) == 0x06 )
F_38 ( V_17 ) ;
else
F_39 ( V_17 ) ;
}
static unsigned char F_41 ( unsigned char * V_111 )
{
unsigned char V_119 = V_121 ;
switch ( V_111 [ 3 ] & 0x30 ) {
case 0x00 :
if ( V_111 [ 0 ] == 0x18 && V_111 [ 1 ] == 0x10 && V_111 [ 2 ] == 0x00 &&
( V_111 [ 3 ] & 0x88 ) == 0x08 && V_111 [ 4 ] == 0x10 &&
V_111 [ 5 ] == 0x00 ) {
V_119 = V_121 ;
} else {
V_119 = V_122 ;
}
break;
case 0x10 :
V_119 = V_123 ;
break;
case 0x20 :
V_119 = V_124 ;
break;
case 0x30 :
V_119 = V_125 ;
break;
}
return V_119 ;
}
static int F_42 ( struct V_62 * V_93 ,
unsigned char * V_99 , struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_119 ;
unsigned int V_126 , V_127 ;
V_119 = F_41 ( V_99 ) ;
switch ( V_119 ) {
case V_122 :
V_93 -> V_87 [ 0 ] . V_20 = F_43 ( V_99 ) ;
V_93 -> V_87 [ 0 ] . V_21 = F_44 ( V_99 ) ;
V_93 -> V_95 = ( ( F_45 ( V_99 ) ) * 2 ) & 0x7f ;
V_93 -> V_55 = V_93 -> V_95 > 0 ? 1 : 0 ;
V_93 -> V_103 = 0 ;
V_93 -> V_104 = 0 ;
break;
case V_123 :
if ( V_2 -> V_29 & V_120 ) {
V_93 -> V_87 [ 0 ] . V_20 = F_46 ( V_99 , 0 ) ;
V_93 -> V_87 [ 0 ] . V_21 = F_47 ( V_99 , 0 ) ;
V_93 -> V_87 [ 1 ] . V_20 = F_46 ( V_99 , 1 ) ;
V_93 -> V_87 [ 1 ] . V_21 = F_47 ( V_99 , 1 ) ;
} else {
V_93 -> V_87 [ 0 ] . V_20 = F_48 ( V_99 , 0 ) ;
V_93 -> V_87 [ 0 ] . V_21 = F_49 ( V_99 , 0 ) ;
V_93 -> V_87 [ 1 ] . V_20 = F_48 ( V_99 , 1 ) ;
V_93 -> V_87 [ 1 ] . V_21 = F_49 ( V_99 , 1 ) ;
}
V_93 -> V_95 = F_50 ( V_99 , 0 ) ? 0x30 : 0 ;
if ( F_51 ( V_99 ) ) {
V_93 -> V_103 = 1 ;
} else {
V_93 -> V_55 = 2 ;
V_93 -> V_103 = 0 ;
}
V_93 -> V_104 = 0 ;
break;
case V_125 :
if ( V_2 -> V_29 & V_120 ) {
V_93 -> V_87 [ 2 ] . V_20 = F_46 ( V_99 , 0 ) ;
V_93 -> V_87 [ 2 ] . V_21 = F_47 ( V_99 , 0 ) ;
V_93 -> V_87 [ 3 ] . V_20 = F_46 ( V_99 , 1 ) ;
V_93 -> V_87 [ 3 ] . V_21 = F_47 ( V_99 , 1 ) ;
V_126 = V_128 ;
V_127 = V_129 ;
} else {
V_93 -> V_87 [ 2 ] . V_20 = F_48 ( V_99 , 0 ) ;
V_93 -> V_87 [ 2 ] . V_21 = F_49 ( V_99 , 0 ) ;
V_93 -> V_87 [ 3 ] . V_20 = F_48 ( V_99 , 1 ) ;
V_93 -> V_87 [ 3 ] . V_21 = F_49 ( V_99 , 1 ) ;
V_126 = V_130 ;
V_127 = V_131 ;
}
V_93 -> V_103 = 0 ;
V_93 -> V_104 = 1 ;
if ( F_52 ( V_99 ) ) {
V_93 -> V_55 = 5 ;
} else if ( V_93 -> V_87 [ 3 ] . V_20 == V_126 &&
V_93 -> V_87 [ 3 ] . V_21 == V_127 ) {
V_93 -> V_87 [ 3 ] . V_20 = 0 ;
V_93 -> V_87 [ 3 ] . V_21 = 0 ;
V_93 -> V_55 = 3 ;
} else {
V_93 -> V_55 = 4 ;
}
break;
case V_124 :
if ( ! ( V_2 -> V_29 & V_32 ) ) {
F_21 ( V_17 ,
L_1 ) ;
} else {
int V_20 = ( V_96 ) ( ( ( V_99 [ 0 ] & 1 ) << 7 ) | ( V_99 [ 1 ] & 0x7f ) ) ;
int V_21 = ( V_96 ) ( ( ( V_99 [ 3 ] & 1 ) << 7 ) | ( V_99 [ 2 ] & 0x7f ) ) ;
int V_95 = ( V_96 ) ( V_99 [ 4 ] & 0x7f ) ;
F_7 ( V_2 -> V_8 , V_33 , V_20 ) ;
F_7 ( V_2 -> V_8 , V_34 , - V_21 ) ;
F_8 ( V_2 -> V_8 , V_39 , V_95 ) ;
}
break;
case V_121 :
default:
memset ( V_93 , 0 , sizeof( struct V_62 ) ) ;
break;
}
if ( V_119 == V_124 ) {
V_93 -> V_100 = ! ! ( F_53 ( V_99 ) & 0x01 ) ;
if ( ! ( V_2 -> V_29 & V_120 ) ) {
V_93 -> V_101 = ! ! ( F_53 ( V_99 ) & 0x02 ) ;
V_93 -> V_102 = ! ! ( F_53 ( V_99 ) & 0x04 ) ;
}
} else {
V_93 -> V_9 = ! ! ( F_53 ( V_99 ) & 0x01 ) ;
if ( ! ( V_2 -> V_29 & V_120 ) ) {
V_93 -> V_10 = ! ! ( F_53 ( V_99 ) & 0x02 ) ;
V_93 -> V_11 = ! ! ( F_53 ( V_99 ) & 0x04 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_19 ;
struct V_6 * V_12 = V_17 -> V_12 ;
struct V_6 * V_8 = V_2 -> V_8 ;
struct V_62 * V_93 = & V_2 -> V_93 ;
memset ( V_93 , 0 , sizeof( struct V_62 ) ) ;
V_2 -> V_106 ( V_93 , V_19 , V_17 ) ;
if ( V_2 -> V_107 ) {
if ( V_93 -> V_104 ) {
V_2 -> V_106 ( V_93 , V_2 -> V_108 , V_17 ) ;
} else {
V_2 -> V_107 = 0 ;
}
}
if ( V_93 -> V_104 )
return;
if ( ! V_2 -> V_107 && V_93 -> V_103 ) {
V_2 -> V_107 = 1 ;
memcpy ( V_2 -> V_108 , V_19 , sizeof( V_2 -> V_108 ) ) ;
return;
}
V_2 -> V_107 = 0 ;
F_15 ( V_17 , ( V_93 -> V_55 <= 4 ) ? V_93 -> V_55 : 4 ) ;
F_19 ( V_12 , V_93 -> V_55 ) ;
F_4 ( V_12 , V_13 , V_93 -> V_9 ) ;
F_4 ( V_12 , V_15 , V_93 -> V_10 ) ;
F_4 ( V_12 , V_16 , V_93 -> V_11 ) ;
F_8 ( V_12 , V_39 , V_93 -> V_95 ) ;
F_5 ( V_12 ) ;
if ( V_2 -> V_29 & V_32 ) {
F_4 ( V_8 , V_13 , V_93 -> V_100 ) ;
F_4 ( V_8 , V_15 , V_93 -> V_101 ) ;
F_4 ( V_8 , V_16 , V_93 -> V_102 ) ;
F_5 ( V_8 ) ;
}
}
static bool F_55 ( struct V_17 * V_17 )
{
if ( V_17 -> V_110 == 4 && ( ( V_17 -> V_19 [ 3 ] & 0x08 ) != 0x08 ) )
return false ;
if ( V_17 -> V_110 == 6 && ( ( V_17 -> V_19 [ 5 ] & 0x10 ) != 0x0 ) )
return false ;
return true ;
}
static void F_56 ( struct V_132 * V_133 )
{
struct V_1 * V_2 =
F_57 ( V_133 , struct V_1 , V_134 . V_133 ) ;
struct V_17 * V_17 = V_2 -> V_17 ;
struct V_6 * V_135 ;
int error = 0 ;
F_58 ( & V_136 ) ;
if ( V_2 -> V_135 )
goto V_137;
V_135 = F_59 () ;
if ( ! V_135 ) {
F_60 ( V_17 , L_3 ) ;
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
F_61 ( V_135 , V_152 , V_33 ) ;
F_61 ( V_135 , V_152 , V_34 ) ;
F_61 ( V_135 , V_153 , V_13 ) ;
F_61 ( V_135 , V_153 , V_15 ) ;
F_61 ( V_135 , V_153 , V_16 ) ;
F_62 ( V_154 , V_135 -> V_155 ) ;
error = F_63 ( V_135 ) ;
if ( error ) {
F_60 ( V_17 ,
L_8 ,
error ) ;
F_64 ( V_135 ) ;
goto V_137;
}
V_2 -> V_135 = V_135 ;
V_137:
if ( error )
V_2 -> V_135 = F_65 ( error ) ;
F_66 ( & V_136 ) ;
}
static void F_67 ( struct V_17 * V_17 ,
unsigned char V_19 [] ,
bool V_156 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_12 , * V_8 = NULL ;
if ( V_2 -> V_27 == V_157 &&
( V_2 -> V_29 & V_32 ) ) {
V_12 = V_2 -> V_8 ;
V_8 = V_17 -> V_12 ;
} else if ( F_68 ( F_69 ( V_2 -> V_135 ) ) ) {
if ( ! F_70 ( V_2 -> V_135 ) )
F_71 ( V_17 , & V_2 -> V_134 ,
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
static T_2 F_72 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_17 -> V_110 < 6 )
return V_158 ;
if ( V_17 -> V_110 == 6 ) {
F_73 ( & V_2 -> V_159 , V_160 + F_74 ( 20 ) ) ;
return V_158 ;
}
F_75 ( & V_2 -> V_159 ) ;
if ( V_17 -> V_19 [ 6 ] & 0x80 ) {
if ( ( ( V_17 -> V_19 [ 3 ] |
V_17 -> V_19 [ 4 ] |
V_17 -> V_19 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_2 , V_17 -> V_19 [ 6 ] ) ) ) {
F_22 ( V_17 ,
L_9 ,
V_17 -> V_19 + 3 ) ;
return V_161 ;
}
V_2 -> V_162 ( V_17 ) ;
V_17 -> V_19 [ 0 ] = V_17 -> V_19 [ 6 ] ;
V_17 -> V_110 = 1 ;
} else {
F_67 ( V_17 , & V_17 -> V_19 [ 3 ] ,
false ) ;
V_17 -> V_19 [ 3 ] = V_17 -> V_19 [ 6 ] & 0xf7 ;
V_17 -> V_110 = 4 ;
}
return V_158 ;
}
static void F_76 ( unsigned long V_3 )
{
struct V_17 * V_17 = (struct V_17 * ) V_3 ;
struct V_1 * V_2 = V_17 -> V_18 ;
F_77 ( V_17 -> V_140 . V_141 ) ;
if ( V_17 -> V_110 == V_17 -> V_163 ) {
if ( ( V_17 -> V_19 [ 3 ] |
V_17 -> V_19 [ 4 ] |
V_17 -> V_19 [ 5 ] ) & 0x80 ) {
F_22 ( V_17 ,
L_10 ,
V_17 -> V_19 + 3 ) ;
} else {
V_2 -> V_162 ( V_17 ) ;
}
V_17 -> V_110 = 0 ;
}
F_78 ( V_17 -> V_140 . V_141 ) ;
}
static T_2 F_79 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_2 -> V_27 != V_164 &&
! V_17 -> V_165 &&
( V_17 -> V_19 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_17 -> V_110 == 3 ) {
F_67 ( V_17 , V_17 -> V_19 ,
true ) ;
return V_166 ;
}
return V_158 ;
}
if ( ( V_2 -> V_29 & V_167 ) &&
V_17 -> V_110 >= 4 && ( V_17 -> V_19 [ 3 ] & 0x0f ) == 0x0f ) {
return F_72 ( V_17 ) ;
}
if ( ! F_1 ( V_2 , V_17 -> V_19 [ 0 ] ) ) {
F_22 ( V_17 ,
L_11 ,
V_17 -> V_19 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_161 ;
}
if ( V_2 -> V_27 < V_79 &&
V_17 -> V_110 >= 2 && V_17 -> V_110 <= V_17 -> V_163 &&
( V_17 -> V_19 [ V_17 -> V_110 - 1 ] & 0x80 ) ) {
F_22 ( V_17 , L_12 ,
V_17 -> V_110 - 1 ,
V_17 -> V_19 [ V_17 -> V_110 - 1 ] ) ;
if ( V_2 -> V_27 == V_168 &&
V_17 -> V_110 == V_17 -> V_163 ) {
return V_166 ;
}
return V_161 ;
}
if ( ( V_2 -> V_27 == V_169 &&
! F_33 ( V_17 ) ) ||
( V_2 -> V_27 == V_164 &&
! F_55 ( V_17 ) ) ) {
F_22 ( V_17 , L_12 ,
V_17 -> V_110 - 1 ,
V_17 -> V_19 [ V_17 -> V_110 - 1 ] ) ;
return V_161 ;
}
if ( V_17 -> V_110 == V_17 -> V_163 ) {
V_2 -> V_162 ( V_17 ) ;
return V_166 ;
}
return V_158 ;
}
static int F_80 ( struct V_17 * V_17 , int V_170 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_171 ;
unsigned char * V_172 ;
unsigned char V_173 [ 4 ] ;
F_81 ( V_170 > 0xf ) ;
V_171 = V_2 -> V_174 [ V_170 ] . V_171 ;
V_172 = ( V_171 & 0x0f00 ) ?
V_173 : ( unsigned char * ) & V_2 -> V_174 [ V_170 ] . V_3 ;
if ( F_82 ( V_140 , V_172 , V_171 ) )
return - 1 ;
return 0 ;
}
static int F_83 ( struct V_17 * V_17 , int V_175 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_57 , V_170 ;
if ( F_82 ( V_140 , NULL , V_2 -> V_176 ) )
return - 1 ;
for ( V_57 = 12 ; V_57 >= 0 ; V_57 -= 4 ) {
V_170 = ( V_175 >> V_57 ) & 0xf ;
if ( F_80 ( V_17 , V_170 ) )
return - 1 ;
}
return 0 ;
}
static int F_84 ( struct V_17 * V_17 , int V_175 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_172 [ 4 ] ;
if ( F_82 ( V_140 , V_172 , V_177 ) )
return - 1 ;
if ( V_175 != ( ( V_172 [ 0 ] << 8 ) | V_172 [ 1 ] ) )
return - 1 ;
return V_172 [ 2 ] ;
}
static int F_85 ( struct V_17 * V_17 , int V_175 )
{
if ( F_83 ( V_17 , V_175 ) )
return - 1 ;
return F_84 ( V_17 , V_175 ) ;
}
static int F_86 ( struct V_17 * V_17 , T_3 V_178 )
{
if ( F_80 ( V_17 , ( V_178 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_80 ( V_17 , V_178 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_87 ( struct V_17 * V_17 , int V_175 ,
T_3 V_178 )
{
if ( F_83 ( V_17 , V_175 ) )
return - 1 ;
return F_86 ( V_17 , V_178 ) ;
}
static int F_88 ( struct V_17 * V_17 , int V_179 ,
int V_180 , unsigned char * V_172 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
V_172 [ 0 ] = 0 ;
if ( V_179 && F_82 ( V_140 , V_172 , V_179 ) )
return - V_181 ;
if ( F_82 ( V_140 , NULL , V_180 ) ||
F_82 ( V_140 , NULL , V_180 ) ||
F_82 ( V_140 , NULL , V_180 ) )
return - V_181 ;
V_172 [ 0 ] = V_172 [ 1 ] = V_172 [ 2 ] = 0xff ;
if ( F_82 ( V_140 , V_172 , V_177 ) )
return - V_181 ;
F_22 ( V_17 , L_13 ,
V_180 , V_172 ) ;
return 0 ;
}
static bool F_89 ( unsigned char V_144 [] )
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
static int F_90 ( struct V_17 * V_17 )
{
unsigned char V_172 [ 4 ] ;
if ( F_88 ( V_17 , 0 , V_182 , V_172 ) ) {
F_60 ( V_17 , L_14 ) ;
return - 1 ;
}
if ( ! F_89 ( V_172 ) ) {
F_22 ( V_17 ,
L_15 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_91 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( F_82 ( V_140 , NULL , V_183 ) )
return - 1 ;
return 0 ;
}
static int F_92 ( struct V_17 * V_17 , bool V_184 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_185 = V_184 ? V_186 : V_187 ;
if ( F_82 ( V_140 , NULL , V_185 ) ||
F_82 ( V_140 , NULL , V_185 ) ||
F_82 ( V_140 , NULL , V_185 ) ||
F_82 ( V_140 , NULL , V_188 ) )
return - 1 ;
F_93 ( V_140 , 3 , 100 ) ;
return 0 ;
}
static int F_94 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_189 ) )
return - 1 ;
return F_82 ( & V_17 -> V_140 , NULL , V_190 ) ;
}
static int F_95 ( struct V_17 * V_17 , T_4 V_191 )
{
int V_57 , V_170 ;
for ( V_57 = 0 ; V_57 <= 8 ; V_57 += 4 ) {
V_170 = ( V_191 >> V_57 ) & 0xf ;
if ( F_80 ( V_17 , V_170 ) )
return - 1 ;
}
return 0 ;
}
static int F_96 ( struct V_17 * V_17 ,
T_4 V_175 , T_4 V_178 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( F_82 ( V_140 , NULL , V_189 ) ||
F_95 ( V_17 , 0x0A0 ) ||
F_95 ( V_17 , V_175 ) ||
F_95 ( V_17 , V_178 ) ||
F_82 ( V_140 , NULL , V_188 ) )
return - 1 ;
return 0 ;
}
static int F_97 ( struct V_17 * V_17 , bool V_184 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
if ( V_184 ) {
if ( F_82 ( V_140 , NULL , V_182 ) ||
F_82 ( V_140 , NULL , V_177 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_186 ) ||
F_82 ( V_140 , NULL , V_187 ) ||
F_82 ( V_140 , NULL , V_186 ) ||
F_82 ( V_140 , NULL , V_177 ) )
return - 1 ;
} else {
if ( F_82 ( V_140 , NULL , V_182 ) )
return - 1 ;
}
return 0 ;
}
static int F_98 ( struct V_17 * V_17 )
{
T_4 V_192 = 0x181 ;
int V_193 = - 1 ;
if ( F_97 ( V_17 , true ) )
return - 1 ;
V_193 = F_96 ( V_17 , 0x000 , V_192 ) ;
if ( F_97 ( V_17 , false ) )
V_193 = - 1 ;
return V_193 ;
}
static int F_99 ( struct V_17 * V_17 , char * V_172 )
{
if ( F_88 ( V_17 , 0 , V_188 , V_172 ) )
return - 1 ;
return 0 ;
}
static int F_100 ( struct V_17 * V_17 , int V_184 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_185 = V_184 ? V_194 : V_195 ;
unsigned char V_196 = V_184 ? 0x0A : 0x00 ;
unsigned char V_172 [ 4 ] ;
if ( F_82 ( V_140 , V_172 , V_177 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , NULL , V_188 ) ||
F_82 ( V_140 , & V_196 , V_185 ) )
return - 1 ;
if ( F_99 ( V_17 , V_172 ) )
return - 1 ;
return 0 ;
}
static int F_101 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned char V_197 [ sizeof( V_17 -> V_19 ) ] ;
bool V_198 ;
if ( V_2 -> V_29 & V_199 )
F_92 ( V_17 , true ) ;
V_198 = F_82 ( & V_17 -> V_140 , V_197 ,
V_200 | ( V_17 -> V_163 << 8 ) ) < 0 ;
if ( V_2 -> V_29 & V_199 )
F_92 ( V_17 , false ) ;
if ( V_198 || ( V_197 [ 0 ] & V_2 -> V_4 ) != V_2 -> V_5 )
return - 1 ;
if ( ( V_17 -> V_201 & 0xc8 ) == 0x08 ) {
if ( F_82 ( & V_17 -> V_140 , V_197 , V_200 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_17 -> V_19 , V_197 , sizeof( V_197 ) ) ;
return 0 ;
}
static int F_102 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( ( V_2 -> V_29 & V_199 ) &&
F_92 ( V_17 , true ) ) {
return - 1 ;
}
if ( F_100 ( V_17 , true ) ) {
F_21 ( V_17 , L_16 ) ;
return - 1 ;
}
if ( F_94 ( V_17 ) ) {
F_60 ( V_17 , L_17 ) ;
return - 1 ;
}
if ( ( V_2 -> V_29 & V_199 ) &&
F_92 ( V_17 , false ) ) {
return - 1 ;
}
if ( F_82 ( & V_17 -> V_140 , NULL , V_183 ) ) {
F_60 ( V_17 , L_18 ) ;
return - 1 ;
}
return 0 ;
}
static int F_103 ( struct V_17 * V_17 )
{
unsigned char V_172 [ 2 ] = { 0xC8 , 0x14 } ;
if ( F_92 ( V_17 , true ) )
return - 1 ;
if ( F_82 ( & V_17 -> V_140 , NULL , V_187 ) ||
F_82 ( & V_17 -> V_140 , NULL , V_187 ) ||
F_82 ( & V_17 -> V_140 , NULL , V_187 ) ||
F_82 ( & V_17 -> V_140 , & V_172 [ 0 ] , V_194 ) ||
F_82 ( & V_17 -> V_140 , & V_172 [ 1 ] , V_194 ) )
return - 1 ;
if ( F_92 ( V_17 , false ) )
return - 1 ;
if ( F_98 ( V_17 ) ) {
F_60 ( V_17 , L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_104 ( struct V_17 * V_17 ,
int V_202 , bool V_184 )
{
int V_192 , V_193 = - 1 ;
if ( F_90 ( V_17 ) )
return - 1 ;
V_192 = F_85 ( V_17 , V_202 + 0x0008 ) ;
if ( V_192 == - 1 )
goto error;
if ( V_184 )
V_192 |= 0x01 ;
else
V_192 &= ~ 0x01 ;
V_193 = F_86 ( V_17 , V_192 ) ;
error:
if ( F_91 ( V_17 ) )
V_193 = - 1 ;
return V_193 ;
}
static int F_105 ( struct V_17 * V_17 )
{
int V_192 ;
V_192 = F_85 ( V_17 , 0x0004 ) ;
if ( V_192 == - 1 )
return - 1 ;
V_192 |= 0x06 ;
if ( F_86 ( V_17 , V_192 ) )
return - 1 ;
return 0 ;
}
static int F_106 ( struct V_17 * V_17 , int V_202 )
{
int V_193 = - V_181 , V_192 ;
if ( F_90 ( V_17 ) )
goto error;
V_192 = F_85 ( V_17 , V_202 + 0x08 ) ;
if ( V_192 == - 1 )
goto error;
V_193 = V_192 & 0x80 ? 0 : - V_203 ;
error:
F_91 ( V_17 ) ;
return V_193 ;
}
static int F_107 ( struct V_17 * V_17 , int V_202 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_193 = 0 ;
unsigned char V_172 [ 4 ] ;
if ( F_104 ( V_17 , V_202 , true ) )
return - V_181 ;
if ( F_88 ( V_17 , 0 , V_186 , V_172 ) ) {
F_21 ( V_17 , L_19 ) ;
V_193 = - V_203 ;
} else {
F_22 ( V_17 , L_20 , V_172 ) ;
if ( F_82 ( V_140 , NULL , V_187 ) ||
F_82 ( V_140 , NULL , V_187 ) ||
F_82 ( V_140 , NULL , V_187 ) ||
F_80 ( V_17 , 0x9 ) ||
F_80 ( V_17 , 0x4 ) ) {
F_60 ( V_17 ,
L_21 ) ;
V_193 = - V_181 ;
goto error;
}
if ( F_90 ( V_17 ) ||
F_87 ( V_17 ,
V_202 + 0x08 , 0x82 ) ||
F_91 ( V_17 ) )
V_193 = - V_181 ;
}
error:
if ( F_104 ( V_17 , V_202 , false ) )
V_193 = - V_181 ;
return V_193 ;
}
static int F_108 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_192 ;
unsigned char V_172 [ 4 ] ;
if ( ( V_2 -> V_29 & V_32 ) &&
F_107 ( V_17 , V_204 ) == - V_181 )
goto error;
if ( F_90 ( V_17 ) ||
F_105 ( V_17 ) ) {
F_60 ( V_17 , L_22 ) ;
goto error;
}
V_192 = F_85 ( V_17 , 0x0006 ) ;
if ( V_192 == - 1 )
goto error;
if ( F_86 ( V_17 , V_192 | 0x01 ) )
goto error;
V_192 = F_85 ( V_17 , 0x0007 ) ;
if ( V_192 == - 1 )
goto error;
if ( F_86 ( V_17 , V_192 | 0x01 ) )
goto error;
if ( F_85 ( V_17 , 0x0144 ) == - 1 )
goto error;
if ( F_86 ( V_17 , 0x04 ) )
goto error;
if ( F_85 ( V_17 , 0x0159 ) == - 1 )
goto error;
if ( F_86 ( V_17 , 0x03 ) )
goto error;
if ( F_85 ( V_17 , 0x0163 ) == - 1 )
goto error;
if ( F_87 ( V_17 , 0x0163 , 0x03 ) )
goto error;
if ( F_85 ( V_17 , 0x0162 ) == - 1 )
goto error;
if ( F_87 ( V_17 , 0x0162 , 0x04 ) )
goto error;
F_91 ( V_17 ) ;
V_172 [ 0 ] = 0x64 ;
if ( F_82 ( V_140 , V_172 , V_194 ) ||
F_82 ( V_140 , NULL , V_189 ) ) {
F_60 ( V_17 , L_23 ) ;
return - 1 ;
}
return 0 ;
error:
F_91 ( V_17 ) ;
return - 1 ;
}
static int F_109 ( struct V_17 * V_17 , int V_205 )
{
int V_206 , V_207 , V_208 , V_209 , V_210 , V_211 , V_212 ;
struct V_1 * V_2 = V_17 -> V_18 ;
V_206 = F_85 ( V_17 , V_205 ) ;
if ( V_206 < 0 )
return V_206 ;
V_207 = ( char ) ( V_206 << 4 ) >> 4 ;
V_207 = 50 + 2 * V_207 ;
V_208 = ( char ) V_206 >> 4 ;
V_208 = 36 + 2 * V_208 ;
V_206 = F_85 ( V_17 , V_205 + 1 ) ;
if ( V_206 < 0 )
return V_206 ;
V_209 = ( char ) ( V_206 << 4 ) >> 4 ;
V_209 = 17 + V_209 ;
V_210 = ( char ) V_206 >> 4 ;
V_210 = 13 + V_210 ;
V_211 = V_207 * ( V_209 - 1 ) ;
V_212 = V_208 * ( V_210 - 1 ) ;
V_2 -> V_213 = V_2 -> V_75 * 10 / V_211 ;
V_2 -> V_214 = V_2 -> V_77 * 10 / V_212 ;
F_22 ( V_17 ,
L_24 ,
V_207 , V_208 , V_209 , V_210 ,
V_211 / 10 , V_212 / 10 , V_2 -> V_213 , V_2 -> V_214 ) ;
return 0 ;
}
static int F_110 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_192 , V_193 = - 1 ;
if ( V_2 -> V_29 & V_32 ) {
V_192 = F_107 ( V_17 ,
V_215 ) ;
if ( V_192 == - V_181 )
goto error;
}
if ( F_90 ( V_17 ) ||
F_85 ( V_17 , 0xc2d9 ) == - 1 ||
F_87 ( V_17 , 0xc2cb , 0x00 ) )
goto error;
if ( F_109 ( V_17 , 0xc2da ) )
goto error;
V_192 = F_85 ( V_17 , 0xc2c6 ) ;
if ( V_192 == - 1 )
goto error;
if ( F_86 ( V_17 , V_192 & 0xfd ) )
goto error;
if ( F_87 ( V_17 , 0xc2c9 , 0x64 ) )
goto error;
V_192 = F_85 ( V_17 , 0xc2c4 ) ;
if ( V_192 == - 1 )
goto error;
if ( F_86 ( V_17 , V_192 | 0x02 ) )
goto error;
F_91 ( V_17 ) ;
return F_82 ( V_140 , NULL , V_189 ) ;
error:
F_91 ( V_17 ) ;
return V_193 ;
}
static int F_111 ( struct V_17 * V_17 )
{
int V_192 ;
V_192 = F_85 ( V_17 , 0x0004 ) ;
if ( V_192 == - 1 )
return - 1 ;
V_192 |= 0x02 ;
if ( F_86 ( V_17 , V_192 ) )
return - 1 ;
return 0 ;
}
static int F_112 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_172 [ 4 ] ;
if ( F_90 ( V_17 ) )
goto error;
if ( F_111 ( V_17 ) ) {
F_60 ( V_17 , L_22 ) ;
goto error;
}
if ( F_87 ( V_17 , 0x0007 , 0x8c ) )
goto error;
if ( F_87 ( V_17 , 0x0149 , 0x03 ) )
goto error;
if ( F_87 ( V_17 , 0x0160 , 0x03 ) )
goto error;
if ( F_87 ( V_17 , 0x017f , 0x15 ) )
goto error;
if ( F_87 ( V_17 , 0x0151 , 0x01 ) )
goto error;
if ( F_87 ( V_17 , 0x0168 , 0x03 ) )
goto error;
if ( F_87 ( V_17 , 0x014a , 0x03 ) )
goto error;
if ( F_87 ( V_17 , 0x0161 , 0x03 ) )
goto error;
F_91 ( V_17 ) ;
V_172 [ 0 ] = 0xc8 ;
V_172 [ 1 ] = 0x64 ;
V_172 [ 2 ] = 0x50 ;
if ( F_82 ( V_140 , & V_172 [ 0 ] , V_194 ) ||
F_82 ( V_140 , & V_172 [ 1 ] , V_194 ) ||
F_82 ( V_140 , & V_172 [ 2 ] , V_194 ) ||
F_82 ( V_140 , V_172 , V_216 ) )
return - 1 ;
V_172 [ 0 ] = 0x64 ;
if ( F_82 ( V_140 , V_172 , V_194 ) ||
F_82 ( V_140 , NULL , V_189 ) ) {
F_60 ( V_17 , L_23 ) ;
return - 1 ;
}
return 0 ;
error:
F_91 ( V_17 ) ;
return - 1 ;
}
static int F_113 ( struct V_17 * V_17 ,
unsigned char V_217 , unsigned char V_218 [] )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
switch ( V_217 ) {
case 0 :
if ( F_82 ( V_140 , NULL , V_183 ) ||
F_82 ( V_140 , NULL , V_183 ) ||
F_82 ( V_140 , V_218 , V_177 ) )
return - 1 ;
break;
case 1 :
if ( F_82 ( V_140 , NULL , V_190 ) ||
F_82 ( V_140 , NULL , V_190 ) ||
F_82 ( V_140 , V_218 , V_177 ) )
return - 1 ;
break;
}
return 0 ;
}
static int F_114 ( unsigned char V_218 [] [ 4 ] ,
struct V_1 * V_2 )
{
int V_219 ;
int V_220 ;
int V_207 , V_208 , V_211 , V_212 ;
V_219 = V_221 + ( V_218 [ 1 ] [ 0 ] & 0x0F ) ;
V_220 = V_222 + ( ( V_218 [ 1 ] [ 0 ] >> 4 ) & 0x0F ) ;
V_2 -> V_75 = ( V_219 - 1 ) * V_223 ;
V_2 -> V_77 = ( V_220 - 1 ) * V_223 ;
V_207 = ( ( V_218 [ 1 ] [ 2 ] >> 2 ) & 0x07 ) + V_224 ;
V_208 = ( ( V_218 [ 1 ] [ 2 ] >> 5 ) & 0x07 ) + V_224 ;
V_211 = V_207 * ( V_219 - 1 ) ;
V_212 = V_208 * ( V_220 - 1 ) ;
V_2 -> V_213 = V_2 -> V_75 * 10 / V_211 ;
V_2 -> V_214 = V_2 -> V_77 * 10 / V_212 ;
return 0 ;
}
static int F_115 ( unsigned char V_218 [] [ 4 ] ,
struct V_1 * V_2 )
{
unsigned char V_225 ;
V_225 = ( V_218 [ 1 ] [ 1 ] >> 3 ) & 0x01 ;
if ( V_225 )
V_2 -> V_29 |= V_120 ;
return 0 ;
}
static int F_116 ( struct V_17 * V_17 ,
struct V_1 * V_2 )
{
unsigned char V_218 [ 2 ] [ 4 ] ;
memset ( V_218 , 0 , sizeof( V_218 ) ) ;
if ( F_113 ( V_17 , 0 , & V_218 [ 0 ] [ 0 ] ) ||
F_113 ( V_17 , 1 , & V_218 [ 1 ] [ 0 ] ) )
return - 1 ;
F_114 ( V_218 , V_2 ) ;
F_115 ( V_218 , V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_17 * V_17 ,
struct V_1 * V_2 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_172 [ 4 ] = { 0 } ;
int V_219 , V_220 ;
if ( F_90 ( V_17 ) )
return - 1 ;
V_172 [ 0 ] = 0x0a ;
if ( F_82 ( V_140 , NULL , V_182 ) ||
F_82 ( V_140 , NULL , V_190 ) ||
F_82 ( V_140 , NULL , V_190 ) ||
F_82 ( V_140 , & V_172 [ 0 ] , V_194 ) ||
F_82 ( V_140 , & V_172 [ 0 ] , V_194 ) )
return - 1 ;
if ( F_82 ( V_140 , V_172 , V_177 ) )
return - 1 ;
V_219 = V_226 + ( V_172 [ 2 ] & 0x0F ) ;
V_220 = V_227 + ( ( V_172 [ 2 ] >> 4 ) & 0x0F ) ;
V_2 -> V_76 = V_219 ;
V_2 -> V_78 = V_220 ;
V_2 -> V_75 = ( V_219 - 1 ) * V_228 ;
V_2 -> V_77 = ( V_220 - 1 ) * V_228 ;
if ( F_91 ( V_17 ) )
return - 1 ;
return 0 ;
}
static int F_118 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
unsigned char V_172 [ 2 ] ;
V_172 [ 0 ] = 0x64 ;
V_172 [ 1 ] = 0x28 ;
if ( F_82 ( V_140 , NULL , V_183 ) ||
F_82 ( V_140 , & V_172 [ 0 ] , V_194 ) ||
F_82 ( V_140 , & V_172 [ 1 ] , V_194 ) )
return - 1 ;
return 0 ;
}
static int F_119 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
int V_192 , V_193 = - 1 ;
if ( F_90 ( V_17 ) ||
F_85 ( V_17 , 0xc2d9 ) == - 1 )
goto error;
if ( F_109 ( V_17 , 0xc397 ) )
goto error;
if ( F_87 ( V_17 , 0xc2c9 , 0x64 ) )
goto error;
V_192 = F_85 ( V_17 , 0xc2c4 ) ;
if ( V_192 == - 1 )
goto error;
if ( F_86 ( V_17 , V_192 | 0x02 ) )
goto error;
F_91 ( V_17 ) ;
return F_82 ( V_140 , NULL , V_189 ) ;
error:
F_91 ( V_17 ) ;
return V_193 ;
}
static int F_120 ( struct V_17 * V_17 )
{
struct V_140 * V_140 = & V_17 -> V_140 ;
char V_172 [ 2 ] = { 0x64 , 0x28 } ;
int V_193 = - 1 ;
if ( F_82 ( V_140 , NULL , V_183 ) ||
F_82 ( V_140 , NULL , V_183 ) ||
F_82 ( V_140 , & V_172 [ 0 ] , V_194 ) ||
F_82 ( V_140 , & V_172 [ 1 ] , V_194 ) ) {
goto error;
}
if ( F_91 ( V_17 ) ||
F_90 ( V_17 ) ||
F_87 ( V_17 , 0x001D , 0x20 ) ) {
goto error;
}
F_91 ( V_17 ) ;
return F_82 ( V_140 , NULL , V_189 ) ;
error:
F_91 ( V_17 ) ;
return V_193 ;
}
static int F_121 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_229 * V_230 )
{
V_17 -> V_18 = V_2 ;
F_122 ( & V_2 -> V_159 , F_76 , ( unsigned long ) V_17 ) ;
V_2 -> V_27 = V_230 -> V_150 ;
V_2 -> V_5 = V_230 -> V_5 ;
V_2 -> V_4 = V_230 -> V_4 ;
V_2 -> V_29 = V_230 -> V_29 ;
V_2 -> V_75 = 2000 ;
V_2 -> V_77 = 1400 ;
V_2 -> V_76 = 15 ;
V_2 -> V_78 = 11 ;
switch ( V_2 -> V_27 ) {
case V_28 :
case V_157 :
V_2 -> V_231 = F_102 ;
V_2 -> V_162 = F_6 ;
V_2 -> V_232 = V_233 ;
V_2 -> V_75 = 1023 ;
V_2 -> V_77 = 767 ;
if ( F_123 ( V_234 ) )
V_2 -> V_29 |= V_35 ;
break;
case V_80 :
V_2 -> V_231 = F_108 ;
V_2 -> V_162 = F_29 ;
V_2 -> V_232 = V_235 ;
V_2 -> V_106 = F_24 ;
V_2 -> V_174 = V_236 ;
V_2 -> V_176 = V_182 ;
if ( F_106 ( V_17 ,
V_204 ) < 0 )
V_2 -> V_29 &= ~ V_32 ;
break;
case V_168 :
V_2 -> V_231 = F_110 ;
V_2 -> V_162 = F_29 ;
V_2 -> V_232 = V_235 ;
V_2 -> V_106 = F_25 ;
V_2 -> V_174 = V_236 ;
V_2 -> V_176 = V_182 ;
V_2 -> V_76 = 16 ;
V_2 -> V_78 = 12 ;
if ( F_106 ( V_17 ,
V_215 ) < 0 )
V_2 -> V_29 &= ~ V_32 ;
break;
case V_81 :
V_2 -> V_231 = F_112 ;
V_2 -> V_162 = F_31 ;
V_2 -> V_232 = V_235 ;
V_2 -> V_174 = V_237 ;
V_2 -> V_176 = V_188 ;
break;
case V_79 :
V_2 -> V_231 = F_118 ;
V_2 -> V_162 = F_28 ;
V_2 -> V_106 = F_26 ;
V_2 -> V_232 = V_235 ;
V_2 -> V_174 = V_236 ;
V_2 -> V_176 = V_182 ;
V_2 -> V_76 = 23 ;
V_2 -> V_78 = 12 ;
if ( F_117 ( V_17 , V_2 ) )
return - V_181 ;
break;
case V_238 :
V_2 -> V_231 = F_103 ;
V_2 -> V_162 = F_30 ;
V_2 -> V_232 = V_233 ;
V_2 -> V_174 = V_239 ;
V_2 -> V_75 = 2047 ;
V_2 -> V_77 = 1535 ;
break;
case V_169 :
V_2 -> V_231 = F_119 ;
V_2 -> V_162 = F_40 ;
V_2 -> V_106 = F_37 ;
V_2 -> V_232 = V_240 ;
V_2 -> V_174 = V_236 ;
V_2 -> V_176 = V_182 ;
V_2 -> V_75 = 0xfff ;
V_2 -> V_77 = 0x7ff ;
if ( V_2 -> V_241 [ 1 ] != 0xba )
V_2 -> V_29 |= V_120 ;
if ( F_106 ( V_17 , V_242 ) < 0 )
V_2 -> V_29 &= ~ V_32 ;
break;
case V_164 :
V_2 -> V_231 = F_120 ;
V_2 -> V_162 = F_54 ;
V_2 -> V_106 = F_42 ;
V_2 -> V_232 = V_243 ;
V_2 -> V_174 = V_236 ;
V_2 -> V_176 = V_182 ;
if ( F_116 ( V_17 , V_2 ) )
return - V_181 ;
if ( V_2 -> V_241 [ 1 ] == 0x1 )
V_2 -> V_29 |= V_32 |
V_244 ;
break;
}
return 0 ;
}
static const struct V_229 * F_124 ( unsigned char * V_245 ,
unsigned char * V_246 )
{
const struct V_247 * V_248 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < F_125 ( V_249 ) ; V_57 ++ ) {
V_248 = & V_249 [ V_57 ] ;
if ( ! memcmp ( V_245 , V_248 -> V_250 , sizeof( V_248 -> V_250 ) ) &&
( ! V_248 -> V_251 ||
V_248 -> V_251 == V_246 [ 2 ] ) ) {
return & V_248 -> V_252 ;
}
}
return NULL ;
}
static int F_126 ( struct V_17 * V_17 , struct V_1 * V_2 )
{
const struct V_229 * V_230 ;
unsigned char V_253 [ 4 ] , V_245 [ 4 ] , V_246 [ 4 ] ;
int error ;
if ( F_88 ( V_17 , V_195 ,
V_187 , V_253 ) )
return - V_181 ;
if ( ( V_253 [ 0 ] & 0xf8 ) != 0 || V_253 [ 1 ] != 0 || ( V_253 [ 2 ] != 10 && V_253 [ 2 ] != 100 ) )
return - V_254 ;
if ( F_88 ( V_17 , V_195 ,
V_186 , V_245 ) ||
F_88 ( V_17 , V_195 ,
V_182 , V_246 ) ||
F_91 ( V_17 ) )
return - V_181 ;
V_230 = F_124 ( V_245 , V_246 ) ;
if ( ! V_230 ) {
if ( V_245 [ 0 ] == 0x73 && V_245 [ 1 ] == 0x03 && V_245 [ 2 ] == 0x50 &&
V_246 [ 0 ] == 0x73 && ( V_246 [ 1 ] == 0x01 || V_246 [ 1 ] == 0x02 ) ) {
V_230 = & V_255 ;
} else if ( V_246 [ 0 ] == 0x88 &&
( ( V_246 [ 1 ] & 0xf0 ) == 0xb0 || ( V_246 [ 1 ] & 0xf0 ) == 0xc0 ) ) {
V_230 = & V_256 ;
} else if ( V_246 [ 0 ] == 0x88 && V_246 [ 1 ] == 0x08 ) {
V_230 = & V_257 ;
} else if ( V_246 [ 0 ] == 0x88 && V_246 [ 1 ] == 0x07 &&
V_246 [ 2 ] >= 0x90 && V_246 [ 2 ] <= 0x9d ) {
V_230 = & V_258 ;
} else if ( V_245 [ 0 ] == 0x73 && V_245 [ 1 ] == 0x03 &&
V_245 [ 2 ] == 0x14 && V_246 [ 1 ] == 0x02 ) {
V_230 = & V_259 ;
} else if ( V_245 [ 0 ] == 0x73 && V_245 [ 1 ] == 0x03 &&
V_245 [ 2 ] == 0x28 && V_246 [ 1 ] == 0x01 ) {
V_230 = & V_259 ;
} else {
F_22 ( V_17 ,
L_25 , V_245 , V_246 ) ;
return - V_254 ;
}
}
if ( V_2 ) {
memcpy ( V_2 -> V_241 , V_246 , 3 ) ;
error = F_121 ( V_17 , V_2 , V_230 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_127 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_128 ( V_17 ) ;
if ( F_126 ( V_17 , V_2 ) < 0 )
return - 1 ;
return V_2 -> V_231 ( V_17 ) ;
}
static void F_129 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_128 ( V_17 ) ;
F_130 ( & V_2 -> V_159 ) ;
if ( V_2 -> V_8 )
F_131 ( V_2 -> V_8 ) ;
if ( ! F_69 ( V_2 -> V_135 ) )
F_131 ( V_2 -> V_135 ) ;
F_132 ( V_2 ) ;
}
static void V_233 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_133 ( V_7 , V_37 , 0 , V_2 -> V_75 , 0 , 0 ) ;
F_133 ( V_7 , V_38 , 0 , V_2 -> V_77 , 0 , 0 ) ;
F_133 ( V_7 , V_39 , 0 , 127 , 0 , 0 ) ;
}
static void F_134 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_133 ( V_7 , V_90 , 0 , V_2 -> V_75 , 0 , 0 ) ;
F_133 ( V_7 , V_91 , 0 , V_2 -> V_77 , 0 , 0 ) ;
F_135 ( V_7 , V_90 , V_2 -> V_213 ) ;
F_135 ( V_7 , V_91 , V_2 -> V_214 ) ;
F_136 ( V_260 , V_7 -> V_261 ) ;
F_136 ( V_262 , V_7 -> V_261 ) ;
}
static void V_235 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_134 ( V_2 , V_7 ) ;
F_133 ( V_7 , V_39 , 0 , 127 , 0 , 0 ) ;
F_137 ( V_7 , V_94 ,
V_263 | V_264 |
V_265 ) ;
}
static void V_240 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_134 ( V_2 , V_7 ) ;
F_136 ( V_266 , V_7 -> V_261 ) ;
F_137 ( V_7 , V_94 ,
V_263 | V_264 |
V_267 ) ;
F_136 ( V_266 , V_7 -> V_261 ) ;
}
static void V_243 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_134 ( V_2 , V_7 ) ;
F_133 ( V_7 , V_39 , 0 , 127 , 0 , 0 ) ;
F_136 ( V_266 , V_7 -> V_261 ) ;
F_137 ( V_7 , V_94 ,
V_263 | V_264 |
V_267 ) ;
}
int F_138 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_6 * V_7 = V_17 -> V_12 ;
int error ;
error = V_2 -> V_231 ( V_17 ) ;
if ( error )
goto V_268;
F_139 ( V_152 , V_7 -> V_269 ) ;
F_139 ( V_33 , V_7 -> V_270 ) ;
F_139 ( V_34 , V_7 -> V_270 ) ;
V_7 -> V_269 [ F_140 ( V_153 ) ] |= F_141 ( V_153 ) ;
V_7 -> V_261 [ F_140 ( V_41 ) ] |= F_141 ( V_41 ) ;
V_7 -> V_261 [ F_140 ( V_40 ) ] |= F_141 ( V_40 ) ;
V_7 -> V_261 [ F_140 ( V_13 ) ] |=
F_141 ( V_13 ) | F_141 ( V_15 ) ;
V_7 -> V_269 [ F_140 ( V_271 ) ] |= F_141 ( V_271 ) ;
V_2 -> V_232 ( V_2 , V_7 ) ;
if ( V_2 -> V_29 & V_42 ) {
V_7 -> V_269 [ F_140 ( V_152 ) ] |= F_141 ( V_152 ) ;
V_7 -> V_270 [ F_140 ( V_43 ) ] |= F_141 ( V_43 ) ;
}
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
V_7 -> V_261 [ F_140 ( V_44 ) ] |= F_141 ( V_44 ) ;
V_7 -> V_261 [ F_140 ( V_45 ) ] |= F_141 ( V_45 ) ;
}
if ( V_2 -> V_29 & V_46 ) {
V_7 -> V_261 [ F_140 ( V_47 ) ] |= F_141 ( V_47 ) ;
V_7 -> V_261 [ F_140 ( V_48 ) ] |= F_141 ( V_48 ) ;
V_7 -> V_261 [ F_140 ( V_49 ) ] |= F_141 ( V_49 ) ;
V_7 -> V_261 [ F_140 ( V_50 ) ] |= F_141 ( V_50 ) ;
} else if ( V_2 -> V_29 & V_120 ) {
F_136 ( V_272 , V_7 -> V_155 ) ;
F_142 ( V_15 , V_7 -> V_261 ) ;
} else {
V_7 -> V_261 [ F_140 ( V_16 ) ] |= F_141 ( V_16 ) ;
}
if ( V_2 -> V_29 & V_32 ) {
struct V_6 * V_8 ;
V_8 = F_59 () ;
if ( ! V_8 ) {
F_60 ( V_17 ,
L_26 ) ;
error = - V_138 ;
goto V_268;
}
snprintf ( V_2 -> V_273 , sizeof( V_2 -> V_273 ) , L_27 ,
V_17 -> V_140 . V_141 -> V_142 ) ;
V_8 -> V_142 = V_2 -> V_273 ;
V_8 -> V_143 = L_28 ;
V_8 -> V_144 . V_145 = V_146 ;
V_8 -> V_144 . V_147 = 0x0002 ;
V_8 -> V_144 . V_148 = V_274 ;
V_8 -> V_144 . V_150 = V_2 -> V_27 ;
V_8 -> V_12 . V_151 = & V_17 -> V_140 . V_141 -> V_12 ;
F_61 ( V_8 , V_152 , V_33 ) ;
F_61 ( V_8 , V_152 , V_34 ) ;
if ( V_2 -> V_29 & V_244 ) {
F_61 ( V_8 , V_271 , V_39 ) ;
F_133 ( V_8 , V_39 , 0 , 127 , 0 , 0 ) ;
}
F_61 ( V_8 , V_153 , V_13 ) ;
F_61 ( V_8 , V_153 , V_15 ) ;
F_61 ( V_8 , V_153 , V_16 ) ;
F_62 ( V_154 , V_8 -> V_155 ) ;
F_62 ( V_275 , V_8 -> V_155 ) ;
error = F_63 ( V_8 ) ;
if ( error ) {
F_60 ( V_17 ,
L_29 ,
error ) ;
F_64 ( V_8 ) ;
goto V_268;
}
V_2 -> V_8 = V_8 ;
}
V_2 -> V_17 = V_17 ;
F_143 ( & V_2 -> V_134 ,
F_56 ) ;
V_17 -> V_276 = F_79 ;
V_17 -> V_277 = F_101 ;
V_17 -> V_278 = F_129 ;
V_17 -> V_279 = F_127 ;
V_17 -> V_163 = V_2 -> V_27 == V_81 ? 8 : 6 ;
V_17 -> V_280 = 0 ;
V_17 -> V_281 = V_17 -> V_163 * 2 ;
return 0 ;
V_268:
F_128 ( V_17 ) ;
F_132 ( V_17 -> V_18 ) ;
V_17 -> V_18 = NULL ;
return error ;
}
int F_144 ( struct V_17 * V_17 , bool V_282 )
{
struct V_1 * V_2 ;
int error ;
error = F_126 ( V_17 , NULL ) ;
if ( error )
return error ;
F_128 ( V_17 ) ;
V_2 = F_145 ( sizeof( struct V_1 ) , V_283 ) ;
if ( ! V_2 )
return - V_138 ;
error = F_126 ( V_17 , V_2 ) ;
if ( error ) {
F_132 ( V_2 ) ;
return error ;
}
if ( V_282 ) {
V_17 -> V_147 = L_30 ;
V_17 -> V_143 = V_2 -> V_29 & V_32 ?
L_31 : L_32 ;
V_17 -> V_248 = V_2 -> V_27 ;
} else {
F_132 ( V_2 ) ;
V_17 -> V_18 = NULL ;
}
return 0 ;
}
