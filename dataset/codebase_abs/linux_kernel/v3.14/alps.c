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
struct V_50 * V_51 ,
int * V_52 , int * y1 , int * V_53 , int * V_54 )
{
int V_55 , V_56 ;
unsigned int V_57 , V_58 ;
unsigned char V_59 , V_60 ;
unsigned char V_61 , V_62 , V_63 , V_64 ;
V_57 = V_51 -> V_57 ;
V_58 = V_51 -> V_58 ;
if ( ! V_57 || ! V_58 )
return;
V_61 = F_10 ( V_57 ) ;
V_62 = F_11 ( V_57 ) ;
V_63 = F_10 ( V_58 ) ;
V_64 = F_11 ( V_58 ) ;
if ( V_61 > V_2 -> V_65 || V_63 > V_2 -> V_66 )
return;
* V_52 = * y1 = * V_53 = * V_54 = 0 ;
if ( V_51 -> V_67 > 1 ) {
V_59 = V_2 -> V_65 - V_61 ;
V_60 = V_2 -> V_65 - V_62 ;
V_55 = ( V_2 -> V_68 * ( V_59 + V_60 ) ) /
( 2 * ( V_2 -> V_65 - 1 ) ) ;
V_59 = V_64 - 1 ;
V_60 = V_63 - 1 ;
V_56 = ( V_2 -> V_69 * ( V_59 + V_60 ) ) /
( 2 * ( V_2 -> V_66 - 1 ) ) ;
* V_52 = V_51 -> V_20 ;
* y1 = V_51 -> V_21 ;
* V_53 = 2 * V_55 - * V_52 ;
* V_54 = 2 * V_56 - * y1 ;
}
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_57 , unsigned int V_58 ,
int * V_52 , int * y1 , int * V_53 , int * V_54 )
{
struct V_70 {
int V_59 ;
int V_71 ;
};
int V_72 = 0 , V_73 = 0 , V_67 ;
int V_74 , V_75 , V_76 ;
struct V_70 V_77 = { 0 ,} , V_78 = { 0 ,} ;
struct V_70 V_79 = { 0 ,} , V_80 = { 0 ,} ;
struct V_70 * V_81 ;
if ( ! V_57 || ! V_58 )
return 0 ;
* V_52 = * y1 = * V_53 = * V_54 = 0 ;
V_76 = 0 ;
V_81 = & V_77 ;
for ( V_74 = 0 ; V_57 != 0 ; V_74 ++ , V_57 >>= 1 ) {
V_75 = V_57 & 1 ;
if ( V_75 ) {
if ( ! V_76 ) {
V_81 -> V_59 = V_74 ;
V_72 ++ ;
}
V_81 -> V_71 ++ ;
} else {
if ( V_76 )
V_81 = & V_78 ;
else
V_81 -> V_71 = 0 ;
}
V_76 = V_75 ;
}
V_58 = V_58 << ( sizeof( V_58 ) * V_82 - V_2 -> V_66 ) ;
V_76 = 0 ;
V_81 = & V_79 ;
for ( V_74 = 0 ; V_58 != 0 ; V_74 ++ , V_58 <<= 1 ) {
V_75 = V_58 & ( 1 << ( sizeof( V_58 ) * V_82 - 1 ) ) ;
if ( V_75 ) {
if ( ! V_76 ) {
V_81 -> V_59 = V_74 ;
V_73 ++ ;
}
V_81 -> V_71 ++ ;
} else {
if ( V_76 )
V_81 = & V_80 ;
else
V_81 -> V_71 = 0 ;
}
V_76 = V_75 ;
}
V_67 = F_13 ( V_72 , V_73 ) ;
if ( V_67 > 1 ) {
if ( V_72 == 1 ) {
V_74 = V_77 . V_71 / 2 ;
V_77 . V_71 = V_77 . V_71 - V_74 ;
V_78 . V_59 = V_77 . V_59 + V_74 ;
V_78 . V_71 = F_13 ( V_74 , 1 ) ;
} else if ( V_73 == 1 ) {
V_74 = V_79 . V_71 / 2 ;
V_79 . V_71 = V_79 . V_71 - V_74 ;
V_80 . V_59 = V_79 . V_59 + V_74 ;
V_80 . V_71 = F_13 ( V_74 , 1 ) ;
}
}
* V_52 = ( V_2 -> V_68 * ( 2 * V_77 . V_59 + V_77 . V_71 - 1 ) ) /
( 2 * ( V_2 -> V_65 - 1 ) ) ;
* y1 = ( V_2 -> V_69 * ( 2 * V_79 . V_59 + V_79 . V_71 - 1 ) ) /
( 2 * ( V_2 -> V_66 - 1 ) ) ;
if ( V_67 > 1 ) {
* V_53 = ( V_2 -> V_68 *
( 2 * V_78 . V_59 + V_78 . V_71 - 1 ) ) /
( 2 * ( V_2 -> V_65 - 1 ) ) ;
* V_54 = ( V_2 -> V_69 *
( 2 * V_80 . V_59 + V_80 . V_71 - 1 ) ) /
( 2 * ( V_2 -> V_66 - 1 ) ) ;
}
return V_67 ;
}
static void F_14 ( struct V_7 * V_13 , int V_83 , bool V_84 ,
int V_20 , int V_21 )
{
F_15 ( V_13 , V_83 ) ;
F_16 ( V_13 , V_85 , V_84 ) ;
if ( V_84 ) {
F_8 ( V_13 , V_86 , V_20 ) ;
F_8 ( V_13 , V_87 , V_21 ) ;
}
}
static void F_17 ( struct V_7 * V_13 , int V_88 ,
int V_52 , int y1 , int V_53 , int V_54 )
{
F_14 ( V_13 , 0 , V_88 != 0 , V_52 , y1 ) ;
F_14 ( V_13 , 1 , V_88 == 2 , V_53 , V_54 ) ;
}
static void F_18 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_2 -> V_9 ;
int V_20 , V_21 , V_22 , V_10 , V_11 , V_12 ;
if ( ! ( V_19 [ 0 ] & 0x40 ) ) {
F_19 ( V_6 , L_1 ) ;
return;
}
if ( V_19 [ 1 ] == 0x7f && V_19 [ 2 ] == 0x7f && V_19 [ 4 ] == 0x7f )
return;
V_20 = ( V_89 ) ( ( ( V_19 [ 0 ] & 0x20 ) << 2 ) | ( V_19 [ 1 ] & 0x7f ) ) ;
V_21 = ( V_89 ) ( ( ( V_19 [ 0 ] & 0x10 ) << 3 ) | ( V_19 [ 2 ] & 0x7f ) ) ;
V_22 = ( V_19 [ 4 ] & 0x7c ) >> 2 ;
V_20 /= 8 ;
V_21 /= 8 ;
F_7 ( V_13 , V_33 , V_20 ) ;
F_7 ( V_13 , V_34 , - V_21 ) ;
V_10 = V_19 [ 3 ] & 0x01 ;
V_11 = V_19 [ 3 ] & 0x02 ;
V_12 = V_19 [ 3 ] & 0x04 ;
if ( ! ( V_2 -> V_90 & V_91 ) &&
( V_10 || V_11 || V_12 ) )
V_2 -> V_90 |= V_91 ;
if ( V_2 -> V_90 & V_91 ) {
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_4 ( V_13 , V_17 , V_12 ) ;
}
F_5 ( V_13 ) ;
return;
}
static void F_20 ( struct V_50 * V_92 , unsigned char * V_93 )
{
V_92 -> V_10 = ! ! ( V_93 [ 3 ] & 0x01 ) ;
V_92 -> V_11 = ! ! ( V_93 [ 3 ] & 0x02 ) ;
V_92 -> V_12 = ! ! ( V_93 [ 3 ] & 0x04 ) ;
V_92 -> V_94 = ! ! ( V_93 [ 3 ] & 0x10 ) ;
V_92 -> V_95 = ! ! ( V_93 [ 3 ] & 0x20 ) ;
V_92 -> V_96 = ! ! ( V_93 [ 3 ] & 0x40 ) ;
}
static void F_21 ( struct V_50 * V_92 , unsigned char * V_93 ,
struct V_6 * V_6 )
{
V_92 -> V_97 = ! ! ( V_93 [ 4 ] & 0x40 ) ;
V_92 -> V_98 = ! ! ( V_93 [ 0 ] & 0x40 ) ;
V_92 -> V_67 = ( V_93 [ 5 ] & 0x3 ) + 1 ;
V_92 -> V_57 = ( ( V_93 [ 4 ] & 0x7e ) << 8 ) |
( ( V_93 [ 1 ] & 0x7f ) << 2 ) |
( ( V_93 [ 0 ] & 0x30 ) >> 4 ) ;
V_92 -> V_58 = ( ( V_93 [ 3 ] & 0x70 ) << 4 ) |
( ( V_93 [ 2 ] & 0x7f ) << 1 ) |
( V_93 [ 4 ] & 0x01 ) ;
V_92 -> V_20 = ( ( V_93 [ 1 ] & 0x7f ) << 4 ) | ( ( V_93 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_93 [ 0 ] & 0x30 ) >> 4 ) ;
V_92 -> V_21 = ( ( V_93 [ 2 ] & 0x7f ) << 4 ) | ( V_93 [ 4 ] & 0x0f ) ;
V_92 -> V_22 = V_93 [ 5 ] & 0x7f ;
F_20 ( V_92 , V_93 ) ;
}
static void F_22 ( struct V_50 * V_92 , unsigned char * V_93 ,
struct V_6 * V_6 )
{
F_21 ( V_92 , V_93 , V_6 ) ;
V_92 -> V_57 |= ( V_93 [ 5 ] & 0x10 ) << 11 ;
V_92 -> V_58 |= ( V_93 [ 5 ] & 0x20 ) << 6 ;
}
static void F_23 ( struct V_50 * V_92 , unsigned char * V_93 ,
struct V_6 * V_6 )
{
T_1 V_99 = 0 ;
struct V_1 * V_2 = V_6 -> V_18 ;
V_92 -> V_97 = ! ! ( V_93 [ 0 ] & 0x02 ) ;
V_92 -> V_98 = ! ! ( V_93 [ 0 ] & 0x20 ) ;
if ( ! V_92 -> V_98 ) {
V_92 -> V_20 = ( ( V_93 [ 1 ] & 0x7f ) | ( ( V_93 [ 4 ] & 0x0f ) << 7 ) ) ;
V_92 -> V_21 = ( ( V_93 [ 2 ] & 0x7f ) | ( ( V_93 [ 4 ] & 0xf0 ) << 3 ) ) ;
V_92 -> V_22 = ( V_93 [ 0 ] & 4 ) ? 0 : V_93 [ 5 ] & 0x7f ;
F_20 ( V_92 , V_93 ) ;
} else {
V_92 -> V_67 = ( ( V_93 [ 0 ] & 0x6 ) >> 1 |
( V_93 [ 0 ] & 0x10 ) >> 2 ) ;
V_99 = ( V_93 [ 1 ] & 0x7f ) |
( ( V_93 [ 2 ] & 0x7f ) << 7 ) |
( ( V_93 [ 4 ] & 0x7f ) << 14 ) |
( ( V_93 [ 5 ] & 0x7f ) << 21 ) |
( ( V_93 [ 3 ] & 0x07 ) << 28 ) |
( ( ( T_1 ) V_93 [ 3 ] & 0x70 ) << 27 ) |
( ( ( T_1 ) V_93 [ 0 ] & 0x01 ) << 34 ) ;
V_92 -> V_58 = V_99 & ( F_24 ( V_2 -> V_66 ) - 1 ) ;
V_92 -> V_57 = ( V_99 >> V_2 -> V_66 ) &
( F_24 ( V_2 -> V_65 ) - 1 ) ;
}
}
static void F_25 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_2 -> V_9 ;
int V_52 = 0 , y1 = 0 , V_53 = 0 , V_54 = 0 ;
int V_67 = 0 , V_100 ;
struct V_50 V_92 = { 0 } ;
V_2 -> V_101 ( & V_92 , V_19 , V_6 ) ;
if ( V_2 -> V_102 ) {
if ( V_92 . V_98 ) {
V_67 = V_92 . V_67 ;
if ( V_2 -> V_27 == V_103 ) {
V_100 = F_12 ( V_2 , V_92 . V_57 ,
V_92 . V_58 , & V_52 , & y1 ,
& V_53 , & V_54 ) ;
if ( V_67 > 1 && V_100 < 2 )
V_67 = V_100 ;
V_2 -> V_101 ( & V_92 , V_2 -> V_104 ,
V_6 ) ;
} else {
V_2 -> V_101 ( & V_92 , V_2 -> V_104 ,
V_6 ) ;
F_9 ( V_2 , & V_92 , & V_52 , & y1 ,
& V_53 , & V_54 ) ;
}
} else {
V_2 -> V_102 = 0 ;
}
}
if ( V_92 . V_98 )
return;
if ( ! V_2 -> V_102 && V_92 . V_97 ) {
V_2 -> V_102 = 1 ;
memcpy ( V_2 -> V_104 , V_19 , sizeof( V_2 -> V_104 ) ) ;
return;
}
V_2 -> V_102 = 0 ;
if ( V_92 . V_20 && V_92 . V_21 && ! V_92 . V_22 )
return;
if ( ! V_67 ) {
V_52 = V_92 . V_20 ;
y1 = V_92 . V_21 ;
V_67 = V_92 . V_22 > 0 ? 1 : 0 ;
}
if ( V_92 . V_22 >= 64 )
F_4 ( V_13 , V_40 , 1 ) ;
else
F_4 ( V_13 , V_40 , 0 ) ;
F_17 ( V_13 , V_67 , V_52 , y1 , V_53 , V_54 ) ;
F_26 ( V_13 , V_67 ) ;
F_4 ( V_13 , V_14 , V_92 . V_10 ) ;
F_4 ( V_13 , V_16 , V_92 . V_11 ) ;
F_4 ( V_13 , V_17 , V_92 . V_12 ) ;
if ( V_92 . V_22 > 0 ) {
F_8 ( V_13 , V_36 , V_92 . V_20 ) ;
F_8 ( V_13 , V_37 , V_92 . V_21 ) ;
}
F_8 ( V_13 , V_38 , V_92 . V_22 ) ;
F_5 ( V_13 ) ;
if ( ! ( V_2 -> V_90 & V_91 ) ) {
F_4 ( V_9 , V_14 , V_92 . V_94 ) ;
F_4 ( V_9 , V_16 , V_92 . V_95 ) ;
F_4 ( V_9 , V_17 , V_92 . V_96 ) ;
F_5 ( V_9 ) ;
}
}
static void F_27 ( struct V_6 * V_6 )
{
unsigned char * V_19 = V_6 -> V_19 ;
if ( V_19 [ 5 ] == 0x3f ) {
F_18 ( V_6 ) ;
return;
}
F_25 ( V_6 ) ;
}
static void F_28 ( struct V_6 * V_6 )
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
static void F_29 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char * V_19 = V_6 -> V_19 ;
struct V_7 * V_13 = V_6 -> V_13 ;
int V_105 ;
int V_20 , V_21 , V_22 ;
int V_10 , V_11 ;
int V_52 , y1 , V_53 , V_54 ;
int V_67 = 0 ;
unsigned int V_106 , V_107 ;
if ( V_19 [ 6 ] & 0x40 ) {
V_2 -> V_102 = 0 ;
}
if ( F_30 ( V_2 -> V_102 > 2 ) )
return;
V_105 = 2 * V_2 -> V_102 ;
V_2 -> V_104 [ V_105 ] = V_19 [ 6 ] ;
V_2 -> V_104 [ V_105 + 1 ] = V_19 [ 7 ] ;
if ( ++ V_2 -> V_102 > 2 ) {
V_2 -> V_102 = 0 ;
V_106 = ( ( V_2 -> V_104 [ 2 ] & 0x1f ) << 10 ) |
( ( V_2 -> V_104 [ 3 ] & 0x60 ) << 3 ) |
( ( V_2 -> V_104 [ 0 ] & 0x3f ) << 2 ) |
( ( V_2 -> V_104 [ 1 ] & 0x60 ) >> 5 ) ;
V_107 = ( ( V_2 -> V_104 [ 5 ] & 0x01 ) << 10 ) |
( ( V_2 -> V_104 [ 3 ] & 0x1f ) << 5 ) |
( V_2 -> V_104 [ 1 ] & 0x1f ) ;
V_67 = F_12 ( V_2 , V_106 , V_107 ,
& V_52 , & y1 , & V_53 , & V_54 ) ;
V_2 -> V_67 = V_67 ;
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
if ( V_2 -> V_67 < 2 ) {
V_52 = V_20 ;
y1 = V_21 ;
V_67 = V_22 > 0 ? 1 : 0 ;
} else {
V_67 = V_2 -> V_67 ;
V_52 = V_2 -> V_52 ;
V_53 = V_2 -> V_53 ;
y1 = V_2 -> y1 ;
V_54 = V_2 -> V_54 ;
}
if ( V_22 >= 64 )
F_4 ( V_13 , V_40 , 1 ) ;
else
F_4 ( V_13 , V_40 , 0 ) ;
F_17 ( V_13 , V_67 , V_52 , y1 , V_53 , V_54 ) ;
F_26 ( V_13 , V_67 ) ;
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
if ( V_22 > 0 ) {
F_8 ( V_13 , V_36 , V_20 ) ;
F_8 ( V_13 , V_37 , V_21 ) ;
}
F_8 ( V_13 , V_38 , V_22 ) ;
F_5 ( V_13 ) ;
}
static void F_31 ( struct V_6 * V_6 ,
unsigned char V_19 [] ,
bool V_108 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_7 * V_9 = V_2 -> V_9 ;
if ( V_108 )
F_2 ( V_6 , V_9 , V_6 -> V_13 ,
V_19 [ 0 ] & 1 , V_19 [ 0 ] & 2 , V_19 [ 0 ] & 4 ) ;
F_7 ( V_9 , V_33 ,
V_19 [ 1 ] ? V_19 [ 1 ] - ( ( V_19 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_9 , V_34 ,
V_19 [ 2 ] ? ( ( V_19 [ 0 ] << 3 ) & 0x100 ) - V_19 [ 2 ] : 0 ) ;
F_5 ( V_9 ) ;
}
static T_2 F_32 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( V_6 -> V_109 < 6 )
return V_110 ;
if ( V_6 -> V_109 == 6 ) {
F_33 ( & V_2 -> V_111 , V_112 + F_34 ( 20 ) ) ;
return V_110 ;
}
F_35 ( & V_2 -> V_111 ) ;
if ( V_6 -> V_19 [ 6 ] & 0x80 ) {
if ( ( ( V_6 -> V_19 [ 3 ] |
V_6 -> V_19 [ 4 ] |
V_6 -> V_19 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_2 , V_6 -> V_19 [ 6 ] ) ) ) {
F_19 ( V_6 ,
L_2 ,
V_6 -> V_19 + 3 ) ;
return V_113 ;
}
V_2 -> V_114 ( V_6 ) ;
V_6 -> V_19 [ 0 ] = V_6 -> V_19 [ 6 ] ;
V_6 -> V_109 = 1 ;
} else {
F_31 ( V_6 , & V_6 -> V_19 [ 3 ] ,
false ) ;
V_6 -> V_19 [ 3 ] = V_6 -> V_19 [ 6 ] & 0xf7 ;
V_6 -> V_109 = 4 ;
}
return V_110 ;
}
static void F_36 ( unsigned long V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_1 * V_2 = V_6 -> V_18 ;
F_37 ( V_6 -> V_115 . V_116 ) ;
if ( V_6 -> V_109 == V_6 -> V_117 ) {
if ( ( V_6 -> V_19 [ 3 ] |
V_6 -> V_19 [ 4 ] |
V_6 -> V_19 [ 5 ] ) & 0x80 ) {
F_19 ( V_6 ,
L_3 ,
V_6 -> V_19 + 3 ) ;
} else {
V_2 -> V_114 ( V_6 ) ;
}
V_6 -> V_109 = 0 ;
}
F_38 ( V_6 -> V_115 . V_116 ) ;
}
static T_2 F_39 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( ( V_6 -> V_19 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_6 -> V_109 == 3 ) {
F_31 ( V_6 , V_6 -> V_19 ,
true ) ;
return V_118 ;
}
return V_110 ;
}
if ( ( V_2 -> V_29 & V_119 ) &&
V_6 -> V_109 >= 4 && ( V_6 -> V_19 [ 3 ] & 0x0f ) == 0x0f ) {
return F_32 ( V_6 ) ;
}
if ( ! F_1 ( V_2 , V_6 -> V_19 [ 0 ] ) ) {
F_19 ( V_6 ,
L_4 ,
V_6 -> V_19 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_113 ;
}
if ( ( V_2 -> V_27 < V_120 ) &&
V_6 -> V_109 >= 2 && V_6 -> V_109 <= V_6 -> V_117 &&
( V_6 -> V_19 [ V_6 -> V_109 - 1 ] & 0x80 ) ) {
F_19 ( V_6 , L_5 ,
V_6 -> V_109 - 1 ,
V_6 -> V_19 [ V_6 -> V_109 - 1 ] ) ;
return V_113 ;
}
if ( V_6 -> V_109 == V_6 -> V_117 ) {
V_2 -> V_114 ( V_6 ) ;
return V_118 ;
}
return V_110 ;
}
static int F_40 ( struct V_6 * V_6 , int V_121 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
struct V_1 * V_2 = V_6 -> V_18 ;
int V_122 ;
unsigned char * V_123 ;
unsigned char V_124 [ 4 ] ;
F_41 ( V_121 > 0xf ) ;
V_122 = V_2 -> V_125 [ V_121 ] . V_122 ;
V_123 = ( V_122 & 0x0f00 ) ?
V_124 : ( unsigned char * ) & V_2 -> V_125 [ V_121 ] . V_3 ;
if ( F_42 ( V_115 , V_123 , V_122 ) )
return - 1 ;
return 0 ;
}
static int F_43 ( struct V_6 * V_6 , int V_126 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
struct V_1 * V_2 = V_6 -> V_18 ;
int V_74 , V_121 ;
if ( F_42 ( V_115 , NULL , V_2 -> V_127 ) )
return - 1 ;
for ( V_74 = 12 ; V_74 >= 0 ; V_74 -= 4 ) {
V_121 = ( V_126 >> V_74 ) & 0xf ;
if ( F_40 ( V_6 , V_121 ) )
return - 1 ;
}
return 0 ;
}
static int F_44 ( struct V_6 * V_6 , int V_126 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
unsigned char V_123 [ 4 ] ;
if ( F_42 ( V_115 , V_123 , V_128 ) )
return - 1 ;
if ( V_126 != ( ( V_123 [ 0 ] << 8 ) | V_123 [ 1 ] ) )
return - 1 ;
return V_123 [ 2 ] ;
}
static int F_45 ( struct V_6 * V_6 , int V_126 )
{
if ( F_43 ( V_6 , V_126 ) )
return - 1 ;
return F_44 ( V_6 , V_126 ) ;
}
static int F_46 ( struct V_6 * V_6 , T_3 V_129 )
{
if ( F_40 ( V_6 , ( V_129 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_40 ( V_6 , V_129 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_47 ( struct V_6 * V_6 , int V_126 ,
T_3 V_129 )
{
if ( F_43 ( V_6 , V_126 ) )
return - 1 ;
return F_46 ( V_6 , V_129 ) ;
}
static int F_48 ( struct V_6 * V_6 , int V_130 ,
int V_131 , unsigned char * V_123 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
V_123 [ 0 ] = 0 ;
if ( V_130 && F_42 ( V_115 , V_123 , V_130 ) )
return - V_132 ;
if ( F_42 ( V_115 , NULL , V_131 ) ||
F_42 ( V_115 , NULL , V_131 ) ||
F_42 ( V_115 , NULL , V_131 ) )
return - V_132 ;
V_123 [ 0 ] = V_123 [ 1 ] = V_123 [ 2 ] = 0xff ;
if ( F_42 ( V_115 , V_123 , V_128 ) )
return - V_132 ;
F_19 ( V_6 , L_6 ,
V_131 , V_123 ) ;
return 0 ;
}
static int F_49 ( struct V_6 * V_6 )
{
unsigned char V_123 [ 4 ] ;
if ( F_48 ( V_6 , 0 , V_133 , V_123 ) ) {
F_50 ( V_6 , L_7 ) ;
return - 1 ;
}
if ( ( V_123 [ 0 ] != 0x88 || ( V_123 [ 1 ] != 0x07 && V_123 [ 1 ] != 0x08 ) ) &&
V_123 [ 0 ] != 0x73 ) {
F_19 ( V_6 ,
L_8 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_51 ( struct V_6 * V_6 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
if ( F_42 ( V_115 , NULL , V_134 ) )
return - 1 ;
return 0 ;
}
static int F_52 ( struct V_6 * V_6 , bool V_135 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
int V_136 = V_135 ? V_137 : V_138 ;
if ( F_42 ( V_115 , NULL , V_136 ) ||
F_42 ( V_115 , NULL , V_136 ) ||
F_42 ( V_115 , NULL , V_136 ) ||
F_42 ( V_115 , NULL , V_139 ) )
return - 1 ;
F_53 ( V_115 , 3 , 100 ) ;
return 0 ;
}
static int F_54 ( struct V_6 * V_6 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
if ( F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_140 ) )
return - 1 ;
return F_42 ( & V_6 -> V_115 , NULL , V_141 ) ;
}
static int F_55 ( struct V_6 * V_6 , T_4 V_142 )
{
int V_74 , V_121 ;
for ( V_74 = 0 ; V_74 <= 8 ; V_74 += 4 ) {
V_121 = ( V_142 >> V_74 ) & 0xf ;
if ( F_40 ( V_6 , V_121 ) )
return - 1 ;
}
return 0 ;
}
static int F_56 ( struct V_6 * V_6 ,
T_4 V_126 , T_4 V_129 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
if ( F_42 ( V_115 , NULL , V_140 ) ||
F_55 ( V_6 , 0x0A0 ) ||
F_55 ( V_6 , V_126 ) ||
F_55 ( V_6 , V_129 ) ||
F_42 ( V_115 , NULL , V_139 ) )
return - 1 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_6 , bool V_135 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
if ( V_135 ) {
if ( F_42 ( V_115 , NULL , V_133 ) ||
F_42 ( V_115 , NULL , V_128 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_137 ) ||
F_42 ( V_115 , NULL , V_138 ) ||
F_42 ( V_115 , NULL , V_137 ) ||
F_42 ( V_115 , NULL , V_128 ) )
return - 1 ;
} else {
if ( F_42 ( V_115 , NULL , V_133 ) )
return - 1 ;
}
return 0 ;
}
static int F_58 ( struct V_6 * V_6 )
{
T_4 V_143 = 0x181 ;
int V_144 = - 1 ;
if ( F_57 ( V_6 , true ) )
return - 1 ;
V_144 = F_56 ( V_6 , 0x000 , V_143 ) ;
if ( F_57 ( V_6 , false ) )
V_144 = - 1 ;
return V_144 ;
}
static int F_59 ( struct V_6 * V_6 , char * V_123 )
{
if ( F_48 ( V_6 , 0 , V_139 , V_123 ) )
return - 1 ;
return 0 ;
}
static int F_60 ( struct V_6 * V_6 , int V_135 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
int V_136 = V_135 ? V_145 : V_146 ;
unsigned char V_147 = V_135 ? 0x0A : 0x00 ;
unsigned char V_123 [ 4 ] ;
if ( F_42 ( V_115 , V_123 , V_128 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , NULL , V_139 ) ||
F_42 ( V_115 , & V_147 , V_136 ) )
return - 1 ;
if ( F_59 ( V_6 , V_123 ) )
return - 1 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned char V_148 [ sizeof( V_6 -> V_19 ) ] ;
bool V_149 ;
if ( V_2 -> V_29 & V_150 )
F_52 ( V_6 , true ) ;
V_149 = F_42 ( & V_6 -> V_115 , V_148 ,
V_151 | ( V_6 -> V_117 << 8 ) ) < 0 ;
if ( V_2 -> V_29 & V_150 )
F_52 ( V_6 , false ) ;
if ( V_149 || ( V_148 [ 0 ] & V_2 -> V_4 ) != V_2 -> V_5 )
return - 1 ;
if ( ( V_6 -> V_152 & 0xc8 ) == 0x08 ) {
if ( F_42 ( & V_6 -> V_115 , V_148 , V_151 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_6 -> V_19 , V_148 , sizeof( V_148 ) ) ;
return 0 ;
}
static int F_62 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
if ( ( V_2 -> V_29 & V_150 ) &&
F_52 ( V_6 , true ) ) {
return - 1 ;
}
if ( F_60 ( V_6 , true ) ) {
F_63 ( V_6 , L_9 ) ;
return - 1 ;
}
if ( F_54 ( V_6 ) ) {
F_50 ( V_6 , L_10 ) ;
return - 1 ;
}
if ( ( V_2 -> V_29 & V_150 ) &&
F_52 ( V_6 , false ) ) {
return - 1 ;
}
if ( F_42 ( & V_6 -> V_115 , NULL , V_134 ) ) {
F_50 ( V_6 , L_11 ) ;
return - 1 ;
}
return 0 ;
}
static int F_64 ( struct V_6 * V_6 )
{
unsigned char V_123 [ 2 ] = { 0xC8 , 0x14 } ;
if ( F_52 ( V_6 , true ) )
return - 1 ;
if ( F_42 ( & V_6 -> V_115 , NULL , V_138 ) ||
F_42 ( & V_6 -> V_115 , NULL , V_138 ) ||
F_42 ( & V_6 -> V_115 , NULL , V_138 ) ||
F_42 ( & V_6 -> V_115 , & V_123 [ 0 ] , V_145 ) ||
F_42 ( & V_6 -> V_115 , & V_123 [ 1 ] , V_145 ) )
return - 1 ;
if ( F_52 ( V_6 , false ) )
return - 1 ;
if ( F_58 ( V_6 ) ) {
F_50 ( V_6 , L_10 ) ;
return - 1 ;
}
return 0 ;
}
static int F_65 ( struct V_6 * V_6 ,
int V_153 , bool V_135 )
{
int V_143 , V_144 = - 1 ;
if ( F_49 ( V_6 ) )
return - 1 ;
V_143 = F_45 ( V_6 , V_153 + 0x0008 ) ;
if ( V_143 == - 1 )
goto error;
if ( V_135 )
V_143 |= 0x01 ;
else
V_143 &= ~ 0x01 ;
V_144 = F_46 ( V_6 , V_143 ) ;
error:
if ( F_51 ( V_6 ) )
V_144 = - 1 ;
return V_144 ;
}
static int F_66 ( struct V_6 * V_6 )
{
int V_143 ;
V_143 = F_45 ( V_6 , 0x0004 ) ;
if ( V_143 == - 1 )
return - 1 ;
V_143 |= 0x06 ;
if ( F_46 ( V_6 , V_143 ) )
return - 1 ;
return 0 ;
}
static int F_67 ( struct V_6 * V_6 , int V_153 )
{
int V_144 = - V_132 , V_143 ;
if ( F_49 ( V_6 ) )
goto error;
V_143 = F_45 ( V_6 , V_153 + 0x08 ) ;
if ( V_143 == - 1 )
goto error;
V_144 = V_143 & 0x80 ? 0 : - V_154 ;
error:
F_51 ( V_6 ) ;
return V_144 ;
}
static int F_68 ( struct V_6 * V_6 , int V_153 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
int V_144 = 0 ;
unsigned char V_123 [ 4 ] ;
if ( F_65 ( V_6 , V_153 , true ) )
return - V_132 ;
if ( F_48 ( V_6 , 0 , V_137 , V_123 ) ) {
F_63 ( V_6 , L_12 ) ;
V_144 = - V_154 ;
} else {
F_19 ( V_6 , L_13 , V_123 ) ;
if ( F_42 ( V_115 , NULL , V_138 ) ||
F_42 ( V_115 , NULL , V_138 ) ||
F_42 ( V_115 , NULL , V_138 ) ||
F_40 ( V_6 , 0x9 ) ||
F_40 ( V_6 , 0x4 ) ) {
F_50 ( V_6 ,
L_14 ) ;
V_144 = - V_132 ;
goto error;
}
if ( F_49 ( V_6 ) ||
F_47 ( V_6 ,
V_153 + 0x08 , 0x82 ) ||
F_51 ( V_6 ) )
V_144 = - V_132 ;
}
error:
if ( F_65 ( V_6 , V_153 , false ) )
V_144 = - V_132 ;
return V_144 ;
}
static int F_69 ( struct V_6 * V_6 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
int V_143 ;
unsigned char V_123 [ 4 ] ;
V_143 = F_67 ( V_6 , V_155 ) ;
if ( V_143 == - V_132 )
goto error;
if ( V_143 == 0 &&
F_68 ( V_6 , V_155 ) == - V_132 )
goto error;
if ( F_49 ( V_6 ) ||
F_66 ( V_6 ) ) {
F_50 ( V_6 , L_15 ) ;
goto error;
}
V_143 = F_45 ( V_6 , 0x0006 ) ;
if ( V_143 == - 1 )
goto error;
if ( F_46 ( V_6 , V_143 | 0x01 ) )
goto error;
V_143 = F_45 ( V_6 , 0x0007 ) ;
if ( V_143 == - 1 )
goto error;
if ( F_46 ( V_6 , V_143 | 0x01 ) )
goto error;
if ( F_45 ( V_6 , 0x0144 ) == - 1 )
goto error;
if ( F_46 ( V_6 , 0x04 ) )
goto error;
if ( F_45 ( V_6 , 0x0159 ) == - 1 )
goto error;
if ( F_46 ( V_6 , 0x03 ) )
goto error;
if ( F_45 ( V_6 , 0x0163 ) == - 1 )
goto error;
if ( F_47 ( V_6 , 0x0163 , 0x03 ) )
goto error;
if ( F_45 ( V_6 , 0x0162 ) == - 1 )
goto error;
if ( F_47 ( V_6 , 0x0162 , 0x04 ) )
goto error;
F_51 ( V_6 ) ;
V_123 [ 0 ] = 0x64 ;
if ( F_42 ( V_115 , V_123 , V_145 ) ||
F_42 ( V_115 , NULL , V_140 ) ) {
F_50 ( V_6 , L_16 ) ;
return - 1 ;
}
return 0 ;
error:
F_51 ( V_6 ) ;
return - 1 ;
}
static int F_70 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
struct V_115 * V_115 = & V_6 -> V_115 ;
int V_143 , V_144 = - 1 ;
if ( V_2 -> V_29 & V_32 ) {
V_143 = F_68 ( V_6 ,
V_156 ) ;
if ( V_143 == - V_132 )
goto error;
if ( V_143 == - V_154 )
V_2 -> V_29 &= ~ V_32 ;
}
if ( F_49 ( V_6 ) ||
F_45 ( V_6 , 0xc2d9 ) == - 1 ||
F_47 ( V_6 , 0xc2cb , 0x00 ) )
goto error;
V_143 = F_45 ( V_6 , 0xc2c6 ) ;
if ( V_143 == - 1 )
goto error;
if ( F_46 ( V_6 , V_143 & 0xfd ) )
goto error;
if ( F_47 ( V_6 , 0xc2c9 , 0x64 ) )
goto error;
V_143 = F_45 ( V_6 , 0xc2c4 ) ;
if ( V_143 == - 1 )
goto error;
if ( F_46 ( V_6 , V_143 | 0x02 ) )
goto error;
F_51 ( V_6 ) ;
return F_42 ( V_115 , NULL , V_140 ) ;
error:
F_51 ( V_6 ) ;
return V_144 ;
}
static int F_71 ( struct V_6 * V_6 )
{
int V_143 ;
V_143 = F_45 ( V_6 , 0x0004 ) ;
if ( V_143 == - 1 )
return - 1 ;
V_143 |= 0x02 ;
if ( F_46 ( V_6 , V_143 ) )
return - 1 ;
return 0 ;
}
static int F_72 ( struct V_6 * V_6 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
unsigned char V_123 [ 4 ] ;
if ( F_49 ( V_6 ) )
goto error;
if ( F_71 ( V_6 ) ) {
F_50 ( V_6 , L_15 ) ;
goto error;
}
if ( F_47 ( V_6 , 0x0007 , 0x8c ) )
goto error;
if ( F_47 ( V_6 , 0x0149 , 0x03 ) )
goto error;
if ( F_47 ( V_6 , 0x0160 , 0x03 ) )
goto error;
if ( F_47 ( V_6 , 0x017f , 0x15 ) )
goto error;
if ( F_47 ( V_6 , 0x0151 , 0x01 ) )
goto error;
if ( F_47 ( V_6 , 0x0168 , 0x03 ) )
goto error;
if ( F_47 ( V_6 , 0x014a , 0x03 ) )
goto error;
if ( F_47 ( V_6 , 0x0161 , 0x03 ) )
goto error;
F_51 ( V_6 ) ;
V_123 [ 0 ] = 0xc8 ;
V_123 [ 1 ] = 0x64 ;
V_123 [ 2 ] = 0x50 ;
if ( F_42 ( V_115 , & V_123 [ 0 ] , V_145 ) ||
F_42 ( V_115 , & V_123 [ 1 ] , V_145 ) ||
F_42 ( V_115 , & V_123 [ 2 ] , V_145 ) ||
F_42 ( V_115 , V_123 , V_157 ) )
return - 1 ;
V_123 [ 0 ] = 0x64 ;
if ( F_42 ( V_115 , V_123 , V_145 ) ||
F_42 ( V_115 , NULL , V_140 ) ) {
F_50 ( V_6 , L_16 ) ;
return - 1 ;
}
return 0 ;
error:
F_51 ( V_6 ) ;
return - 1 ;
}
static int F_73 ( struct V_6 * V_6 ,
struct V_1 * V_2 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
unsigned char V_123 [ 4 ] = { 0 } ;
int V_158 , V_159 ;
if ( F_49 ( V_6 ) )
return - 1 ;
V_123 [ 0 ] = 0x0a ;
if ( F_42 ( V_115 , NULL , V_133 ) ||
F_42 ( V_115 , NULL , V_141 ) ||
F_42 ( V_115 , NULL , V_141 ) ||
F_42 ( V_115 , & V_123 [ 0 ] , V_145 ) ||
F_42 ( V_115 , & V_123 [ 0 ] , V_145 ) )
return - 1 ;
if ( F_42 ( V_115 , V_123 , V_128 ) )
return - 1 ;
V_158 = V_160 + ( V_123 [ 2 ] & 0x0F ) ;
V_159 = V_161 + ( ( V_123 [ 2 ] >> 4 ) & 0x0F ) ;
V_2 -> V_65 = V_158 ;
V_2 -> V_66 = V_159 ;
V_2 -> V_68 = ( V_158 - 1 ) * V_162 ;
V_2 -> V_69 = ( V_159 - 1 ) * V_162 ;
if ( F_51 ( V_6 ) )
return - 1 ;
return 0 ;
}
static int F_74 ( struct V_6 * V_6 )
{
struct V_115 * V_115 = & V_6 -> V_115 ;
unsigned char V_123 [ 2 ] ;
V_123 [ 0 ] = 0x64 ;
V_123 [ 1 ] = 0x28 ;
if ( F_42 ( V_115 , NULL , V_134 ) ||
F_42 ( V_115 , & V_123 [ 0 ] , V_145 ) ||
F_42 ( V_115 , & V_123 [ 1 ] , V_145 ) )
return - 1 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
V_2 -> V_5 = 0x8f ;
V_2 -> V_4 = 0x8f ;
V_2 -> V_29 = V_32 ;
V_2 -> V_68 = 2000 ;
V_2 -> V_69 = 1400 ;
V_2 -> V_65 = 15 ;
V_2 -> V_66 = 11 ;
switch ( V_2 -> V_27 ) {
case V_28 :
case V_163 :
V_2 -> V_164 = F_62 ;
V_2 -> V_114 = F_6 ;
V_2 -> V_165 = V_166 ;
V_2 -> V_68 = 1023 ;
V_2 -> V_69 = 767 ;
break;
case V_103 :
V_2 -> V_164 = F_69 ;
V_2 -> V_114 = F_27 ;
V_2 -> V_165 = V_167 ;
V_2 -> V_101 = F_21 ;
V_2 -> V_125 = V_168 ;
V_2 -> V_127 = V_133 ;
break;
case V_169 :
V_2 -> V_164 = F_72 ;
V_2 -> V_114 = F_29 ;
V_2 -> V_165 = V_167 ;
V_2 -> V_125 = V_170 ;
V_2 -> V_127 = V_139 ;
break;
case V_120 :
V_2 -> V_164 = F_74 ;
V_2 -> V_114 = F_25 ;
V_2 -> V_101 = F_23 ;
V_2 -> V_165 = V_167 ;
V_2 -> V_125 = V_168 ;
V_2 -> V_127 = V_133 ;
V_2 -> V_5 = 0xc8 ;
V_2 -> V_4 = 0xd8 ;
V_2 -> V_29 = 0 ;
V_2 -> V_68 = 1360 ;
V_2 -> V_69 = 660 ;
V_2 -> V_65 = 23 ;
V_2 -> V_66 = 12 ;
break;
case V_171 :
V_2 -> V_164 = F_64 ;
V_2 -> V_114 = F_28 ;
V_2 -> V_165 = V_166 ;
V_2 -> V_125 = V_172 ;
V_2 -> V_68 = 2047 ;
V_2 -> V_69 = 1535 ;
break;
}
}
static int F_76 ( struct V_6 * V_6 , struct V_1 * V_2 ,
unsigned char * V_173 , unsigned char * V_174 )
{
const struct V_175 * V_176 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < F_77 ( V_177 ) ; V_74 ++ ) {
V_176 = & V_177 [ V_74 ] ;
if ( ! memcmp ( V_173 , V_176 -> V_178 , sizeof( V_176 -> V_178 ) ) &&
( ! V_176 -> V_179 ||
V_176 -> V_179 == V_174 [ 2 ] ) ) {
V_2 -> V_27 = V_176 -> V_27 ;
F_75 ( V_2 ) ;
V_2 -> V_29 = V_176 -> V_29 ;
V_2 -> V_5 = V_176 -> V_5 ;
V_2 -> V_4 = V_176 -> V_4 ;
return 0 ;
}
}
return - V_180 ;
}
static int F_78 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
unsigned char V_181 [ 4 ] , V_173 [ 4 ] , V_174 [ 4 ] ;
if ( F_48 ( V_6 , V_146 ,
V_138 , V_181 ) )
return - V_132 ;
if ( ( V_181 [ 0 ] & 0xf8 ) != 0 || V_181 [ 1 ] != 0 || ( V_181 [ 2 ] != 10 && V_181 [ 2 ] != 100 ) )
return - V_180 ;
if ( F_48 ( V_6 , V_146 ,
V_137 , V_173 ) ||
F_48 ( V_6 , V_146 ,
V_133 , V_174 ) ||
F_51 ( V_6 ) )
return - V_132 ;
if ( F_76 ( V_6 , V_2 , V_173 , V_174 ) == 0 ) {
return 0 ;
} else if ( V_173 [ 0 ] == 0x73 && V_173 [ 1 ] == 0x03 && V_173 [ 2 ] == 0x50 &&
V_174 [ 0 ] == 0x73 && ( V_174 [ 1 ] == 0x01 || V_174 [ 1 ] == 0x02 ) ) {
V_2 -> V_27 = V_120 ;
F_75 ( V_2 ) ;
if ( F_73 ( V_6 , V_2 ) )
return - V_132 ;
else
return 0 ;
} else if ( V_174 [ 0 ] == 0x88 && V_174 [ 1 ] == 0x08 ) {
V_2 -> V_27 = V_103 ;
F_75 ( V_2 ) ;
V_2 -> V_164 = F_70 ;
V_2 -> V_101 = F_22 ;
V_2 -> V_65 = 16 ;
V_2 -> V_66 = 12 ;
V_6 -> V_18 = V_2 ;
if ( F_67 ( V_6 , V_156 ) )
V_2 -> V_29 &= ~ V_32 ;
return 0 ;
} else if ( V_174 [ 0 ] == 0x88 && V_174 [ 1 ] == 0x07 &&
V_174 [ 2 ] >= 0x90 && V_174 [ 2 ] <= 0x9d ) {
V_2 -> V_27 = V_103 ;
F_75 ( V_2 ) ;
return 0 ;
}
F_79 ( V_6 ,
L_17 , V_173 , V_174 ) ;
return - V_180 ;
}
static int F_80 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
F_81 ( V_6 ) ;
if ( F_78 ( V_6 , V_2 ) < 0 )
return - 1 ;
return V_2 -> V_164 ( V_6 ) ;
}
static void F_82 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
F_81 ( V_6 ) ;
F_83 ( & V_2 -> V_111 ) ;
F_84 ( V_2 -> V_9 ) ;
F_85 ( V_2 ) ;
}
static void V_166 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_86 ( V_8 , V_36 , 0 , V_2 -> V_68 , 0 , 0 ) ;
F_86 ( V_8 , V_37 , 0 , V_2 -> V_69 , 0 , 0 ) ;
}
static void V_167 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_87 ( V_182 , V_8 -> V_183 ) ;
F_88 ( V_8 , 2 , 0 ) ;
F_86 ( V_8 , V_86 , 0 , V_2 -> V_68 , 0 , 0 ) ;
F_86 ( V_8 , V_87 , 0 , V_2 -> V_69 , 0 , 0 ) ;
F_87 ( V_184 , V_8 -> V_185 ) ;
F_87 ( V_186 , V_8 -> V_185 ) ;
F_87 ( V_187 , V_8 -> V_185 ) ;
F_86 ( V_8 , V_36 , 0 , V_2 -> V_68 , 0 , 0 ) ;
F_86 ( V_8 , V_37 , 0 , V_2 -> V_69 , 0 , 0 ) ;
}
int F_89 ( struct V_6 * V_6 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_6 -> V_13 , * V_9 ;
V_2 = F_90 ( sizeof( struct V_1 ) , V_188 ) ;
V_9 = F_91 () ;
if ( ! V_2 || ! V_9 )
goto V_189;
V_2 -> V_9 = V_9 ;
F_92 ( & V_2 -> V_111 , F_36 , ( unsigned long ) V_6 ) ;
V_6 -> V_18 = V_2 ;
F_81 ( V_6 ) ;
if ( F_78 ( V_6 , V_2 ) < 0 )
goto V_189;
if ( V_2 -> V_164 ( V_6 ) )
goto V_189;
F_93 ( V_190 , V_8 -> V_191 ) ;
F_93 ( V_33 , V_8 -> V_192 ) ;
F_93 ( V_34 , V_8 -> V_192 ) ;
V_8 -> V_191 [ F_94 ( V_193 ) ] |= F_95 ( V_193 ) ;
V_8 -> V_185 [ F_94 ( V_40 ) ] |= F_95 ( V_40 ) ;
V_8 -> V_185 [ F_94 ( V_39 ) ] |= F_95 ( V_39 ) ;
V_8 -> V_185 [ F_94 ( V_14 ) ] |=
F_95 ( V_14 ) | F_95 ( V_16 ) ;
V_8 -> V_191 [ F_94 ( V_194 ) ] |= F_95 ( V_194 ) ;
V_2 -> V_165 ( V_2 , V_8 ) ;
F_86 ( V_8 , V_38 , 0 , 127 , 0 , 0 ) ;
if ( V_2 -> V_29 & V_41 ) {
V_8 -> V_191 [ F_94 ( V_190 ) ] |= F_95 ( V_190 ) ;
V_8 -> V_192 [ F_94 ( V_42 ) ] |= F_95 ( V_42 ) ;
}
if ( V_2 -> V_29 & ( V_30 | V_31 ) ) {
V_8 -> V_185 [ F_94 ( V_43 ) ] |= F_95 ( V_43 ) ;
V_8 -> V_185 [ F_94 ( V_44 ) ] |= F_95 ( V_44 ) ;
}
if ( V_2 -> V_29 & V_45 ) {
V_8 -> V_185 [ F_94 ( V_46 ) ] |= F_95 ( V_46 ) ;
V_8 -> V_185 [ F_94 ( V_47 ) ] |= F_95 ( V_47 ) ;
V_8 -> V_185 [ F_94 ( V_48 ) ] |= F_95 ( V_48 ) ;
V_8 -> V_185 [ F_94 ( V_49 ) ] |= F_95 ( V_49 ) ;
} else {
V_8 -> V_185 [ F_94 ( V_17 ) ] |= F_95 ( V_17 ) ;
}
snprintf ( V_2 -> V_195 , sizeof( V_2 -> V_195 ) , L_18 , V_6 -> V_115 . V_116 -> V_195 ) ;
V_9 -> V_195 = V_2 -> V_195 ;
V_9 -> V_196 = ( V_2 -> V_29 & V_32 ) ?
L_19 : L_20 ;
V_9 -> V_197 . V_198 = V_199 ;
V_9 -> V_197 . V_200 = 0x0002 ;
V_9 -> V_197 . V_201 = V_202 ;
V_9 -> V_197 . V_203 = 0x0000 ;
V_9 -> V_13 . V_204 = & V_6 -> V_115 . V_116 -> V_13 ;
V_9 -> V_191 [ 0 ] = F_95 ( V_193 ) | F_95 ( V_190 ) ;
V_9 -> V_192 [ F_94 ( V_33 ) ] = F_95 ( V_33 ) | F_95 ( V_34 ) ;
V_9 -> V_185 [ F_94 ( V_14 ) ] =
F_95 ( V_14 ) | F_95 ( V_17 ) | F_95 ( V_16 ) ;
if ( F_96 ( V_2 -> V_9 ) )
goto V_189;
V_6 -> V_205 = F_39 ;
V_6 -> V_206 = F_61 ;
V_6 -> V_207 = F_82 ;
V_6 -> V_208 = F_80 ;
V_6 -> V_117 = V_2 -> V_27 == V_169 ? 8 : 6 ;
V_6 -> V_209 = 0 ;
return 0 ;
V_189:
F_81 ( V_6 ) ;
F_97 ( V_9 ) ;
F_85 ( V_2 ) ;
V_6 -> V_18 = NULL ;
return - 1 ;
}
int F_98 ( struct V_6 * V_6 , bool V_210 )
{
struct V_1 V_124 ;
if ( F_78 ( V_6 , & V_124 ) < 0 )
return - 1 ;
if ( V_210 ) {
V_6 -> V_200 = L_21 ;
V_6 -> V_196 = V_124 . V_29 & V_32 ?
L_22 : L_23 ;
V_6 -> V_176 = V_124 . V_27 << 8 ;
}
return 0 ;
}
