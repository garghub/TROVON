static bool F_1 ( const struct V_1 * V_2 ,
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
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
unsigned char * V_22 = V_6 -> V_22 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_19 -> V_9 ;
int V_23 , V_24 , V_25 , V_26 , V_27 , V_10 , V_11 , V_12 ;
int V_28 = 0 , V_29 = 0 ;
if ( V_2 -> V_30 == V_31 ) {
V_10 = V_22 [ 2 ] & 0x10 ;
V_11 = V_22 [ 2 ] & 0x08 ;
V_12 = 0 ;
V_23 = V_22 [ 1 ] | ( ( V_22 [ 0 ] & 0x07 ) << 7 ) ;
V_24 = V_22 [ 4 ] | ( ( V_22 [ 3 ] & 0x07 ) << 7 ) ;
V_25 = V_22 [ 5 ] ;
} else {
V_10 = V_22 [ 3 ] & 1 ;
V_11 = V_22 [ 3 ] & 2 ;
V_12 = V_22 [ 3 ] & 4 ;
V_23 = V_22 [ 1 ] | ( ( V_22 [ 2 ] & 0x78 ) << ( 7 - 3 ) ) ;
V_24 = V_22 [ 4 ] | ( ( V_22 [ 3 ] & 0x70 ) << ( 7 - 4 ) ) ;
V_25 = V_22 [ 5 ] ;
}
if ( V_2 -> V_32 & V_33 ) {
V_28 = V_22 [ 0 ] & 0x10 ;
V_29 = V_22 [ 2 ] & 4 ;
}
if ( V_2 -> V_32 & V_34 ) {
V_28 = V_22 [ 3 ] & 4 ;
V_29 = V_22 [ 2 ] & 4 ;
if ( ( V_12 = V_29 && V_28 ) )
V_29 = V_28 = 0 ;
}
V_26 = V_22 [ 2 ] & 1 ;
V_27 = V_22 [ 2 ] & 2 ;
if ( ( V_2 -> V_32 & V_35 ) && V_25 == 127 ) {
F_7 ( V_9 , V_36 , ( V_23 > 383 ? ( V_23 - 768 ) : V_23 ) ) ;
F_7 ( V_9 , V_37 , - ( V_24 > 255 ? ( V_24 - 512 ) : V_24 ) ) ;
F_2 ( V_6 , V_9 , V_13 , V_10 , V_11 , V_12 ) ;
F_5 ( V_9 ) ;
return;
}
F_2 ( V_6 , V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_26 && ! V_27 )
V_25 = 40 ;
if ( V_26 && V_27 && ! V_19 -> V_38 ) {
F_8 ( V_13 , V_39 , V_23 ) ;
F_8 ( V_13 , V_40 , V_24 ) ;
F_8 ( V_13 , V_41 , 0 ) ;
F_4 ( V_13 , V_42 , 0 ) ;
F_5 ( V_13 ) ;
}
V_19 -> V_38 = V_27 ;
if ( V_25 > 30 )
F_4 ( V_13 , V_43 , 1 ) ;
if ( V_25 < 25 )
F_4 ( V_13 , V_43 , 0 ) ;
if ( V_25 > 0 ) {
F_8 ( V_13 , V_39 , V_23 ) ;
F_8 ( V_13 , V_40 , V_24 ) ;
}
F_8 ( V_13 , V_41 , V_25 ) ;
F_4 ( V_13 , V_42 , V_25 > 0 ) ;
if ( V_2 -> V_32 & V_44 )
F_7 ( V_13 , V_45 , ( ( V_22 [ 2 ] << 1 ) & 0x08 ) - ( ( V_22 [ 0 ] >> 4 ) & 0x07 ) ) ;
if ( V_2 -> V_32 & ( V_33 | V_34 ) ) {
F_4 ( V_13 , V_46 , V_29 ) ;
F_4 ( V_13 , V_47 , V_28 ) ;
}
if ( V_2 -> V_32 & V_48 ) {
F_4 ( V_13 , V_49 , V_22 [ 2 ] & 4 ) ;
F_4 ( V_13 , V_50 , V_22 [ 0 ] & 0x10 ) ;
F_4 ( V_13 , V_51 , V_22 [ 3 ] & 4 ) ;
F_4 ( V_13 , V_52 , V_22 [ 0 ] & 0x20 ) ;
}
F_5 ( V_13 ) ;
}
static int F_9 ( unsigned int V_53 , unsigned int V_54 ,
int * V_55 , int * y1 , int * V_56 , int * V_57 )
{
struct V_58 {
int V_59 ;
int V_60 ;
};
int V_61 = 0 , V_62 = 0 , V_63 ;
int V_21 , V_64 , V_65 ;
struct V_58 V_66 = { 0 ,} , V_67 = { 0 ,} ;
struct V_58 V_68 = { 0 ,} , V_69 = { 0 ,} ;
struct V_58 * V_70 ;
if ( ! V_53 || ! V_54 )
return 0 ;
* V_55 = * y1 = * V_56 = * V_57 = 0 ;
V_65 = 0 ;
V_70 = & V_66 ;
for ( V_21 = 0 ; V_53 != 0 ; V_21 ++ , V_53 >>= 1 ) {
V_64 = V_53 & 1 ;
if ( V_64 ) {
if ( ! V_65 ) {
V_70 -> V_59 = V_21 ;
V_61 ++ ;
}
V_70 -> V_60 ++ ;
} else {
if ( V_65 )
V_70 = & V_67 ;
else
V_70 -> V_60 = 0 ;
}
V_65 = V_64 ;
}
V_54 = V_54 << ( sizeof( V_54 ) * V_71 - V_72 ) ;
V_65 = 0 ;
V_70 = & V_68 ;
for ( V_21 = 0 ; V_54 != 0 ; V_21 ++ , V_54 <<= 1 ) {
V_64 = V_54 & ( 1 << ( sizeof( V_54 ) * V_71 - 1 ) ) ;
if ( V_64 ) {
if ( ! V_65 ) {
V_70 -> V_59 = V_21 ;
V_62 ++ ;
}
V_70 -> V_60 ++ ;
} else {
if ( V_65 )
V_70 = & V_69 ;
else
V_70 -> V_60 = 0 ;
}
V_65 = V_64 ;
}
V_63 = F_10 ( V_61 , V_62 ) ;
if ( V_63 > 1 ) {
if ( V_61 == 1 ) {
V_21 = V_66 . V_60 / 2 ;
V_66 . V_60 = V_66 . V_60 - V_21 ;
V_67 . V_59 = V_66 . V_59 + V_21 ;
V_67 . V_60 = F_10 ( V_21 , 1 ) ;
} else if ( V_62 == 1 ) {
V_21 = V_68 . V_60 / 2 ;
V_68 . V_60 = V_68 . V_60 - V_21 ;
V_69 . V_59 = V_68 . V_59 + V_21 ;
V_69 . V_60 = F_10 ( V_21 , 1 ) ;
}
}
* V_55 = ( V_73 * ( 2 * V_66 . V_59 + V_66 . V_60 - 1 ) ) /
( 2 * ( V_74 - 1 ) ) ;
* y1 = ( V_75 * ( 2 * V_68 . V_59 + V_68 . V_60 - 1 ) ) /
( 2 * ( V_72 - 1 ) ) ;
if ( V_63 > 1 ) {
* V_56 = ( V_73 * ( 2 * V_67 . V_59 + V_67 . V_60 - 1 ) ) /
( 2 * ( V_74 - 1 ) ) ;
* V_57 = ( V_75 * ( 2 * V_69 . V_59 + V_69 . V_60 - 1 ) ) /
( 2 * ( V_72 - 1 ) ) ;
}
return V_63 ;
}
static void F_11 ( struct V_7 * V_13 , int V_76 , bool V_77 ,
int V_23 , int V_24 )
{
F_12 ( V_13 , V_76 ) ;
F_13 ( V_13 , V_78 , V_77 ) ;
if ( V_77 ) {
F_8 ( V_13 , V_79 , V_23 ) ;
F_8 ( V_13 , V_80 , V_24 ) ;
}
}
static void F_14 ( struct V_7 * V_13 , int V_81 ,
int V_55 , int y1 , int V_56 , int V_57 )
{
F_11 ( V_13 , 0 , V_81 != 0 , V_55 , y1 ) ;
F_11 ( V_13 , 1 , V_81 == 2 , V_56 , V_57 ) ;
}
static void F_15 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
unsigned char * V_22 = V_6 -> V_22 ;
struct V_7 * V_13 = V_19 -> V_9 ;
int V_23 , V_24 , V_25 , V_10 , V_11 , V_12 ;
if ( ! ( V_22 [ 0 ] & 0x40 ) ) {
F_16 ( V_6 , L_1 ) ;
return;
}
if ( V_22 [ 1 ] == 0x7f && V_22 [ 2 ] == 0x7f && V_22 [ 4 ] == 0x7f )
return;
V_23 = ( V_82 ) ( ( ( V_22 [ 0 ] & 0x20 ) << 2 ) | ( V_22 [ 1 ] & 0x7f ) ) ;
V_24 = ( V_82 ) ( ( ( V_22 [ 0 ] & 0x10 ) << 3 ) | ( V_22 [ 2 ] & 0x7f ) ) ;
V_25 = ( V_22 [ 4 ] & 0x7c ) >> 2 ;
V_23 /= 8 ;
V_24 /= 8 ;
F_7 ( V_13 , V_36 , V_23 ) ;
F_7 ( V_13 , V_37 , - V_24 ) ;
V_10 = V_22 [ 3 ] & 0x01 ;
V_11 = V_22 [ 3 ] & 0x02 ;
V_12 = V_22 [ 3 ] & 0x04 ;
if ( ! ( V_19 -> V_83 & V_84 ) &&
( V_10 || V_11 || V_12 ) )
V_19 -> V_83 |= V_84 ;
if ( V_19 -> V_83 & V_84 ) {
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_4 ( V_13 , V_17 , V_12 ) ;
}
F_5 ( V_13 ) ;
return;
}
static void F_17 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
unsigned char * V_22 = V_6 -> V_22 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_19 -> V_9 ;
int V_23 , V_24 , V_25 ;
int V_10 , V_11 , V_12 ;
int V_55 = 0 , y1 = 0 , V_56 = 0 , V_57 = 0 ;
int V_63 = 0 , V_85 ;
unsigned int V_86 , V_87 ;
if ( V_19 -> V_88 ) {
if ( V_22 [ 0 ] & 0x40 ) {
V_63 = ( V_22 [ 5 ] & 0x3 ) + 1 ;
V_86 = ( ( V_22 [ 4 ] & 0x7e ) << 8 ) |
( ( V_22 [ 1 ] & 0x7f ) << 2 ) |
( ( V_22 [ 0 ] & 0x30 ) >> 4 ) ;
V_87 = ( ( V_22 [ 3 ] & 0x70 ) << 4 ) |
( ( V_22 [ 2 ] & 0x7f ) << 1 ) |
( V_22 [ 4 ] & 0x01 ) ;
V_85 = F_9 ( V_86 , V_87 ,
& V_55 , & y1 , & V_56 , & V_57 ) ;
if ( V_63 > 1 && V_85 < 2 )
V_63 = V_85 ;
V_22 = V_19 -> V_89 ;
} else {
V_19 -> V_88 = 0 ;
}
}
if ( V_22 [ 0 ] & 0x40 )
return;
if ( ! V_19 -> V_88 && ( V_22 [ 4 ] & 0x40 ) ) {
V_19 -> V_88 = 1 ;
memcpy ( V_19 -> V_89 , V_22 , sizeof( V_19 -> V_89 ) ) ;
return;
}
V_19 -> V_88 = 0 ;
V_10 = V_22 [ 3 ] & 0x01 ;
V_11 = V_22 [ 3 ] & 0x02 ;
V_12 = V_22 [ 3 ] & 0x04 ;
V_23 = ( ( V_22 [ 1 ] & 0x7f ) << 4 ) | ( ( V_22 [ 4 ] & 0x30 ) >> 2 ) |
( ( V_22 [ 0 ] & 0x30 ) >> 4 ) ;
V_24 = ( ( V_22 [ 2 ] & 0x7f ) << 4 ) | ( V_22 [ 4 ] & 0x0f ) ;
V_25 = V_22 [ 5 ] & 0x7f ;
if ( V_23 && V_24 && ! V_25 )
return;
if ( ! V_63 ) {
V_55 = V_23 ;
y1 = V_24 ;
V_63 = V_25 > 0 ? 1 : 0 ;
}
if ( V_25 >= 64 )
F_4 ( V_13 , V_43 , 1 ) ;
else
F_4 ( V_13 , V_43 , 0 ) ;
F_14 ( V_13 , V_63 , V_55 , y1 , V_56 , V_57 ) ;
F_4 ( V_13 , V_42 , V_63 == 1 ) ;
F_4 ( V_13 , V_90 , V_63 == 2 ) ;
F_4 ( V_13 , V_91 , V_63 == 3 ) ;
F_4 ( V_13 , V_92 , V_63 == 4 ) ;
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_4 ( V_13 , V_17 , V_12 ) ;
if ( V_25 > 0 ) {
F_8 ( V_13 , V_39 , V_23 ) ;
F_8 ( V_13 , V_40 , V_24 ) ;
}
F_8 ( V_13 , V_41 , V_25 ) ;
F_5 ( V_13 ) ;
if ( ! ( V_19 -> V_83 & V_84 ) ) {
V_10 = V_22 [ 3 ] & 0x10 ;
V_11 = V_22 [ 3 ] & 0x20 ;
V_12 = V_22 [ 3 ] & 0x40 ;
F_4 ( V_9 , V_14 , V_10 ) ;
F_4 ( V_9 , V_16 , V_11 ) ;
F_4 ( V_9 , V_17 , V_12 ) ;
F_5 ( V_9 ) ;
}
}
static void F_18 ( struct V_6 * V_6 )
{
unsigned char * V_22 = V_6 -> V_22 ;
if ( V_22 [ 5 ] == 0x3f ) {
F_15 ( V_6 ) ;
return;
}
F_17 ( V_6 ) ;
}
static void F_19 ( struct V_6 * V_6 )
{
unsigned char * V_22 = V_6 -> V_22 ;
struct V_7 * V_13 = V_6 -> V_13 ;
int V_23 , V_24 , V_25 ;
int V_10 , V_11 ;
V_10 = V_22 [ 4 ] & 0x01 ;
V_11 = V_22 [ 4 ] & 0x02 ;
V_23 = ( ( V_22 [ 1 ] & 0x7f ) << 4 ) | ( ( V_22 [ 3 ] & 0x30 ) >> 2 ) |
( ( V_22 [ 0 ] & 0x30 ) >> 4 ) ;
V_24 = ( ( V_22 [ 2 ] & 0x7f ) << 4 ) | ( V_22 [ 3 ] & 0x0f ) ;
V_25 = V_22 [ 5 ] & 0x7f ;
if ( V_25 >= 64 )
F_4 ( V_13 , V_43 , 1 ) ;
else
F_4 ( V_13 , V_43 , 0 ) ;
if ( V_25 > 0 ) {
F_8 ( V_13 , V_39 , V_23 ) ;
F_8 ( V_13 , V_40 , V_24 ) ;
}
F_8 ( V_13 , V_41 , V_25 ) ;
F_4 ( V_13 , V_42 , V_25 > 0 ) ;
F_4 ( V_13 , V_14 , V_10 ) ;
F_4 ( V_13 , V_16 , V_11 ) ;
F_5 ( V_13 ) ;
}
static void F_20 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
switch ( V_2 -> V_30 ) {
case V_31 :
case V_93 :
F_6 ( V_6 ) ;
break;
case V_94 :
F_18 ( V_6 ) ;
break;
case V_95 :
F_19 ( V_6 ) ;
break;
}
}
static void F_21 ( struct V_6 * V_6 ,
unsigned char V_22 [] ,
bool V_96 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
struct V_7 * V_9 = V_19 -> V_9 ;
if ( V_96 )
F_2 ( V_6 , V_9 , V_6 -> V_13 ,
V_22 [ 0 ] & 1 , V_22 [ 0 ] & 2 , V_22 [ 0 ] & 4 ) ;
F_7 ( V_9 , V_36 ,
V_22 [ 1 ] ? V_22 [ 1 ] - ( ( V_22 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_9 , V_37 ,
V_22 [ 2 ] ? ( ( V_22 [ 0 ] << 3 ) & 0x100 ) - V_22 [ 2 ] : 0 ) ;
F_5 ( V_9 ) ;
}
static T_1 F_22 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_6 -> V_97 < 6 )
return V_98 ;
if ( V_6 -> V_97 == 6 ) {
F_23 ( & V_19 -> V_99 , V_100 + F_24 ( 20 ) ) ;
return V_98 ;
}
F_25 ( & V_19 -> V_99 ) ;
if ( V_6 -> V_22 [ 6 ] & 0x80 ) {
if ( ( ( V_6 -> V_22 [ 3 ] |
V_6 -> V_22 [ 4 ] |
V_6 -> V_22 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_19 -> V_21 , V_6 -> V_22 [ 6 ] ) ) ) {
F_16 ( V_6 ,
L_2 ,
V_6 -> V_22 [ 3 ] , V_6 -> V_22 [ 4 ] ,
V_6 -> V_22 [ 5 ] , V_6 -> V_22 [ 6 ] ) ;
return V_101 ;
}
F_20 ( V_6 ) ;
V_6 -> V_22 [ 0 ] = V_6 -> V_22 [ 6 ] ;
V_6 -> V_97 = 1 ;
} else {
F_21 ( V_6 , & V_6 -> V_22 [ 3 ] ,
false ) ;
V_6 -> V_22 [ 3 ] = V_6 -> V_22 [ 6 ] & 0xf7 ;
V_6 -> V_97 = 4 ;
}
return V_98 ;
}
static void F_26 ( unsigned long V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
F_27 ( V_6 -> V_102 . V_103 ) ;
if ( V_6 -> V_97 == V_6 -> V_104 ) {
if ( ( V_6 -> V_22 [ 3 ] |
V_6 -> V_22 [ 4 ] |
V_6 -> V_22 [ 5 ] ) & 0x80 ) {
F_16 ( V_6 ,
L_3 ,
V_6 -> V_22 [ 3 ] , V_6 -> V_22 [ 4 ] ,
V_6 -> V_22 [ 5 ] ) ;
} else {
F_20 ( V_6 ) ;
}
V_6 -> V_97 = 0 ;
}
F_28 ( V_6 -> V_102 . V_103 ) ;
}
static T_1 F_29 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
if ( ( V_6 -> V_22 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_6 -> V_97 == 3 ) {
F_21 ( V_6 , V_6 -> V_22 ,
true ) ;
return V_105 ;
}
return V_98 ;
}
if ( ( V_2 -> V_32 & V_106 ) &&
V_6 -> V_97 >= 4 && ( V_6 -> V_22 [ 3 ] & 0x0f ) == 0x0f ) {
return F_22 ( V_6 ) ;
}
if ( ! F_1 ( V_2 , V_6 -> V_22 [ 0 ] ) ) {
F_16 ( V_6 ,
L_4 ,
V_6 -> V_22 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_101 ;
}
if ( V_6 -> V_97 >= 2 && V_6 -> V_97 <= V_6 -> V_104 &&
( V_6 -> V_22 [ V_6 -> V_97 - 1 ] & 0x80 ) ) {
F_16 ( V_6 , L_5 ,
V_6 -> V_97 - 1 ,
V_6 -> V_22 [ V_6 -> V_97 - 1 ] ) ;
return V_101 ;
}
if ( V_6 -> V_97 == V_6 -> V_104 ) {
F_20 ( V_6 ) ;
return V_105 ;
}
return V_98 ;
}
static int F_30 ( struct V_6 * V_6 , int V_107 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
struct V_18 * V_19 = V_6 -> V_20 ;
int V_108 ;
unsigned char * V_109 ;
unsigned char V_110 [ 4 ] ;
F_31 ( V_107 > 0xf ) ;
V_108 = V_19 -> V_111 [ V_107 ] . V_108 ;
V_109 = ( V_108 & 0x0f00 ) ?
V_110 : ( unsigned char * ) & V_19 -> V_111 [ V_107 ] . V_3 ;
if ( F_32 ( V_102 , V_109 , V_108 ) )
return - 1 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_6 , int V_112 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
struct V_18 * V_19 = V_6 -> V_20 ;
int V_21 , V_107 ;
if ( F_32 ( V_102 , NULL , V_19 -> V_113 ) )
return - 1 ;
for ( V_21 = 12 ; V_21 >= 0 ; V_21 -= 4 ) {
V_107 = ( V_112 >> V_21 ) & 0xf ;
if ( F_30 ( V_6 , V_107 ) )
return - 1 ;
}
return 0 ;
}
static int F_34 ( struct V_6 * V_6 , int V_112 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
unsigned char V_109 [ 4 ] ;
if ( F_32 ( V_102 , V_109 , V_114 ) )
return - 1 ;
if ( V_112 != ( ( V_109 [ 0 ] << 8 ) | V_109 [ 1 ] ) )
return - 1 ;
return V_109 [ 2 ] ;
}
static int F_35 ( struct V_6 * V_6 , int V_112 )
{
if ( F_33 ( V_6 , V_112 ) )
return - 1 ;
return F_34 ( V_6 , V_112 ) ;
}
static int F_36 ( struct V_6 * V_6 , T_2 V_115 )
{
if ( F_30 ( V_6 , ( V_115 >> 4 ) & 0xf ) )
return - 1 ;
if ( F_30 ( V_6 , V_115 & 0xf ) )
return - 1 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_6 , int V_112 ,
T_2 V_115 )
{
if ( F_33 ( V_6 , V_112 ) )
return - 1 ;
return F_36 ( V_6 , V_115 ) ;
}
static int F_38 ( struct V_6 * V_6 ,
unsigned char * V_116 )
{
unsigned char V_109 [ 4 ] ;
struct V_102 * V_102 = & V_6 -> V_102 ;
if ( F_32 ( V_102 , NULL , V_117 ) ||
F_32 ( V_102 , NULL , V_117 ) ||
F_32 ( V_102 , NULL , V_117 ) ||
F_32 ( V_102 , V_109 , V_114 ) ) {
F_39 ( V_6 , L_6 ) ;
return - 1 ;
}
if ( V_109 [ 0 ] != 0x88 && V_109 [ 1 ] != 0x07 ) {
F_16 ( V_6 ,
L_7 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ) ;
return - 1 ;
}
if ( V_116 )
* V_116 = V_109 [ 2 ] ;
return 0 ;
}
static inline int F_40 ( struct V_6 * V_6 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
if ( F_32 ( V_102 , NULL , V_118 ) )
return - 1 ;
return 0 ;
}
static const struct V_1 * F_41 ( struct V_6 * V_6 , int * V_119 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
static const unsigned char V_120 [] = { 0 , 10 , 20 , 40 , 60 , 80 , 100 , 200 } ;
unsigned char V_109 [ 4 ] ;
const struct V_1 * V_2 = NULL ;
int V_21 ;
V_109 [ 0 ] = 0 ;
if ( F_32 ( V_102 , V_109 , V_121 ) ||
F_32 ( V_102 , NULL , V_122 ) ||
F_32 ( V_102 , NULL , V_122 ) ||
F_32 ( V_102 , NULL , V_122 ) )
return NULL ;
V_109 [ 0 ] = V_109 [ 1 ] = V_109 [ 2 ] = 0xff ;
if ( F_32 ( V_102 , V_109 , V_114 ) )
return NULL ;
F_16 ( V_6 , L_8 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ) ;
if ( ( V_109 [ 0 ] & 0xf8 ) != 0 || V_109 [ 1 ] != 0 ||
( V_109 [ 2 ] != 10 && V_109 [ 2 ] != 100 ) )
return NULL ;
V_109 [ 0 ] = 0 ;
if ( F_32 ( V_102 , V_109 , V_121 ) ||
F_32 ( V_102 , NULL , V_123 ) ||
F_32 ( V_102 , NULL , V_123 ) ||
F_32 ( V_102 , NULL , V_123 ) )
return NULL ;
V_109 [ 0 ] = V_109 [ 1 ] = V_109 [ 2 ] = 0xff ;
if ( F_32 ( V_102 , V_109 , V_114 ) )
return NULL ;
F_16 ( V_6 , L_9 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ) ;
if ( V_119 ) {
for ( V_21 = 0 ; V_21 < F_42 ( V_120 ) && V_109 [ 2 ] != V_120 [ V_21 ] ; V_21 ++ )
;
* V_119 = ( V_109 [ 0 ] << 8 ) | ( V_109 [ 1 ] << 4 ) | V_21 ;
}
for ( V_21 = 0 ; V_21 < F_42 ( V_124 ) ; V_21 ++ ) {
if ( ! memcmp ( V_109 , V_124 [ V_21 ] . V_125 ,
sizeof( V_124 [ V_21 ] . V_125 ) ) ) {
V_2 = V_124 + V_21 ;
break;
}
}
if ( V_2 && V_2 -> V_30 > V_93 ) {
V_2 = NULL ;
if ( F_38 ( V_6 , V_109 ) ) {
F_43 ( V_6 ,
L_10 ) ;
} else {
for ( V_21 = 0 ; V_21 < F_42 ( V_124 ) ; V_21 ++ ) {
if ( V_124 [ V_21 ] . V_30 > V_93 &&
V_124 [ V_21 ] . V_126 == V_109 [ 0 ] ) {
V_2 = V_124 + V_21 ;
break;
}
}
F_40 ( V_6 ) ;
if ( ! V_2 )
F_16 ( V_6 ,
L_11 ,
V_109 [ 0 ] ) ;
}
}
return V_2 ;
}
static int F_44 ( struct V_6 * V_6 , bool V_127 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
int V_128 = V_127 ? V_123 : V_122 ;
if ( F_32 ( V_102 , NULL , V_128 ) ||
F_32 ( V_102 , NULL , V_128 ) ||
F_32 ( V_102 , NULL , V_128 ) ||
F_32 ( V_102 , NULL , V_129 ) )
return - 1 ;
F_45 ( V_102 , 3 , 100 ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_6 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
if ( F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_130 ) )
return - 1 ;
return F_32 ( & V_6 -> V_102 , NULL , V_131 ) ;
}
static int F_47 ( struct V_6 * V_6 , char * V_109 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
if ( F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , V_109 , V_114 ) )
return - 1 ;
F_16 ( V_6 , L_12 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_6 , int V_127 )
{
struct V_102 * V_102 = & V_6 -> V_102 ;
int V_128 = V_127 ? V_132 : V_121 ;
unsigned char V_133 = V_127 ? 0x0A : 0x00 ;
unsigned char V_109 [ 4 ] ;
if ( F_32 ( V_102 , V_109 , V_114 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , NULL , V_129 ) ||
F_32 ( V_102 , & V_133 , V_128 ) )
return - 1 ;
if ( F_47 ( V_6 , V_109 ) )
return - 1 ;
return 0 ;
}
static int F_49 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
unsigned char V_134 [ sizeof( V_6 -> V_22 ) ] ;
bool V_135 ;
if ( V_19 -> V_21 -> V_32 & V_136 )
F_44 ( V_6 , true ) ;
V_135 = F_32 ( & V_6 -> V_102 , V_134 ,
V_137 | ( V_6 -> V_104 << 8 ) ) < 0 ;
if ( V_19 -> V_21 -> V_32 & V_136 )
F_44 ( V_6 , false ) ;
if ( V_135 || ( V_134 [ 0 ] & V_19 -> V_21 -> V_4 ) != V_19 -> V_21 -> V_5 )
return - 1 ;
if ( ( V_6 -> V_138 & 0xc8 ) == 0x08 ) {
if ( F_32 ( & V_6 -> V_102 , V_134 , V_137 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_6 -> V_22 , V_134 , sizeof( V_134 ) ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
if ( ( V_2 -> V_32 & V_136 ) &&
F_44 ( V_6 , true ) ) {
return - 1 ;
}
if ( F_48 ( V_6 , true ) ) {
F_43 ( V_6 , L_13 ) ;
return - 1 ;
}
if ( F_46 ( V_6 ) ) {
F_39 ( V_6 , L_14 ) ;
return - 1 ;
}
if ( ( V_2 -> V_32 & V_136 ) &&
F_44 ( V_6 , false ) ) {
return - 1 ;
}
if ( F_32 ( & V_6 -> V_102 , NULL , V_118 ) ) {
F_39 ( V_6 , L_15 ) ;
return - 1 ;
}
return 0 ;
}
static int F_51 ( struct V_6 * V_6 , bool V_127 )
{
int V_139 ;
V_139 = F_35 ( V_6 , 0x0008 ) ;
if ( V_139 == - 1 )
return - 1 ;
if ( V_127 )
V_139 |= 0x01 ;
else
V_139 &= ~ 0x01 ;
if ( F_36 ( V_6 , V_139 ) )
return - 1 ;
return 0 ;
}
static int F_52 ( struct V_6 * V_6 )
{
int V_139 ;
V_139 = F_35 ( V_6 , 0x0004 ) ;
if ( V_139 == - 1 )
return - 1 ;
V_139 |= 0x06 ;
if ( F_36 ( V_6 , V_139 ) )
return - 1 ;
return 0 ;
}
static int F_53 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
struct V_102 * V_102 = & V_6 -> V_102 ;
int V_139 ;
unsigned char V_109 [ 4 ] ;
V_19 -> V_111 = V_140 ;
V_19 -> V_113 = V_117 ;
if ( F_38 ( V_6 , NULL ) )
goto error;
V_139 = F_35 ( V_6 , 0x0008 ) ;
if ( V_139 == - 1 )
goto error;
if ( V_139 & 0x80 ) {
if ( F_51 ( V_6 , true ) )
goto error;
if ( F_40 ( V_6 ) )
goto error;
V_109 [ 0 ] = 0x64 ;
if ( F_32 ( V_102 , NULL , V_123 ) ||
F_32 ( V_102 , NULL , V_123 ) ||
F_32 ( V_102 , NULL , V_123 ) ||
F_32 ( V_102 , V_109 , V_114 ) ) {
F_43 ( V_6 , L_16 ) ;
} else {
F_16 ( V_6 ,
L_17 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ) ;
if ( F_32 ( V_102 , NULL , V_122 ) ||
F_32 ( V_102 , NULL , V_122 ) ||
F_32 ( V_102 , NULL , V_122 ) ||
F_30 ( V_6 , 0x9 ) ||
F_30 ( V_6 , 0x4 ) ) {
F_39 ( V_6 ,
L_18 ) ;
goto V_141;
}
}
if ( F_38 ( V_6 , NULL ) )
goto V_141;
if ( F_51 ( V_6 , false ) )
goto error;
}
if ( F_52 ( V_6 ) ) {
F_39 ( V_6 , L_19 ) ;
goto error;
}
V_139 = F_35 ( V_6 , 0x0006 ) ;
if ( V_139 == - 1 )
goto error;
if ( F_36 ( V_6 , V_139 | 0x01 ) )
goto error;
V_139 = F_35 ( V_6 , 0x0007 ) ;
if ( V_139 == - 1 )
goto error;
if ( F_36 ( V_6 , V_139 | 0x01 ) )
goto error;
if ( F_35 ( V_6 , 0x0144 ) == - 1 )
goto error;
if ( F_36 ( V_6 , 0x04 ) )
goto error;
if ( F_35 ( V_6 , 0x0159 ) == - 1 )
goto error;
if ( F_36 ( V_6 , 0x03 ) )
goto error;
if ( F_35 ( V_6 , 0x0163 ) == - 1 )
goto error;
if ( F_37 ( V_6 , 0x0163 , 0x03 ) )
goto error;
if ( F_35 ( V_6 , 0x0162 ) == - 1 )
goto error;
if ( F_37 ( V_6 , 0x0162 , 0x04 ) )
goto error;
if ( F_37 ( V_6 , 0x0008 , 0x82 ) )
goto error;
F_40 ( V_6 ) ;
V_109 [ 0 ] = 0x64 ;
if ( F_32 ( V_102 , V_109 , V_132 ) ||
F_32 ( V_102 , NULL , V_130 ) ) {
F_39 ( V_6 , L_20 ) ;
return - 1 ;
}
return 0 ;
V_141:
if ( ! F_38 ( V_6 , NULL ) )
F_51 ( V_6 , false ) ;
error:
F_40 ( V_6 ) ;
return - 1 ;
}
static int F_54 ( struct V_6 * V_6 )
{
int V_139 ;
V_139 = F_35 ( V_6 , 0x0004 ) ;
if ( V_139 == - 1 )
return - 1 ;
V_139 |= 0x02 ;
if ( F_36 ( V_6 , V_139 ) )
return - 1 ;
return 0 ;
}
static int F_55 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
struct V_102 * V_102 = & V_6 -> V_102 ;
unsigned char V_109 [ 4 ] ;
V_19 -> V_111 = V_142 ;
V_19 -> V_113 = V_129 ;
if ( F_38 ( V_6 , NULL ) )
goto error;
if ( F_54 ( V_6 ) ) {
F_39 ( V_6 , L_19 ) ;
goto error;
}
if ( F_37 ( V_6 , 0x0007 , 0x8c ) )
goto error;
if ( F_37 ( V_6 , 0x0149 , 0x03 ) )
goto error;
if ( F_37 ( V_6 , 0x0160 , 0x03 ) )
goto error;
if ( F_37 ( V_6 , 0x017f , 0x15 ) )
goto error;
if ( F_37 ( V_6 , 0x0151 , 0x01 ) )
goto error;
if ( F_37 ( V_6 , 0x0168 , 0x03 ) )
goto error;
if ( F_37 ( V_6 , 0x014a , 0x03 ) )
goto error;
if ( F_37 ( V_6 , 0x0161 , 0x03 ) )
goto error;
F_40 ( V_6 ) ;
V_109 [ 0 ] = 0xc8 ;
V_109 [ 1 ] = 0x64 ;
V_109 [ 2 ] = 0x50 ;
if ( F_32 ( V_102 , & V_109 [ 0 ] , V_132 ) ||
F_32 ( V_102 , & V_109 [ 1 ] , V_132 ) ||
F_32 ( V_102 , & V_109 [ 2 ] , V_132 ) ||
F_32 ( V_102 , V_109 , V_143 ) )
return - 1 ;
V_109 [ 0 ] = 0x64 ;
if ( F_32 ( V_102 , V_109 , V_132 ) ||
F_32 ( V_102 , NULL , V_130 ) ) {
F_39 ( V_6 , L_20 ) ;
return - 1 ;
}
return 0 ;
error:
F_40 ( V_6 ) ;
return - 1 ;
}
static int F_56 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
int V_144 = - 1 ;
switch ( V_2 -> V_30 ) {
case V_31 :
case V_93 :
V_144 = F_50 ( V_6 ) ;
break;
case V_94 :
V_144 = F_53 ( V_6 ) ;
break;
case V_95 :
V_144 = F_55 ( V_6 ) ;
break;
}
return V_144 ;
}
static int F_57 ( struct V_6 * V_6 )
{
const struct V_1 * V_2 ;
F_58 ( V_6 ) ;
V_2 = F_41 ( V_6 , NULL ) ;
if ( ! V_2 )
return - 1 ;
return F_56 ( V_6 ) ;
}
static void F_59 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
F_58 ( V_6 ) ;
F_60 ( & V_19 -> V_99 ) ;
F_61 ( V_19 -> V_9 ) ;
F_62 ( V_19 ) ;
}
int F_63 ( struct V_6 * V_6 )
{
struct V_18 * V_19 ;
const struct V_1 * V_2 ;
struct V_7 * V_8 = V_6 -> V_13 , * V_9 ;
int V_119 ;
V_19 = F_64 ( sizeof( struct V_18 ) , V_145 ) ;
V_9 = F_65 () ;
if ( ! V_19 || ! V_9 )
goto V_146;
V_19 -> V_9 = V_9 ;
F_66 ( & V_19 -> V_99 , F_26 , ( unsigned long ) V_6 ) ;
V_6 -> V_20 = V_19 ;
F_58 ( V_6 ) ;
V_2 = F_41 ( V_6 , & V_119 ) ;
if ( ! V_2 )
goto V_146;
V_19 -> V_21 = V_2 ;
if ( F_56 ( V_6 ) )
goto V_146;
F_67 ( V_147 , V_8 -> V_148 ) ;
F_67 ( V_36 , V_8 -> V_149 ) ;
F_67 ( V_37 , V_8 -> V_149 ) ;
V_8 -> V_148 [ F_68 ( V_150 ) ] |= F_69 ( V_150 ) ;
V_8 -> V_151 [ F_68 ( V_43 ) ] |= F_69 ( V_43 ) ;
V_8 -> V_151 [ F_68 ( V_42 ) ] |= F_69 ( V_42 ) ;
V_8 -> V_151 [ F_68 ( V_14 ) ] |=
F_69 ( V_14 ) | F_69 ( V_16 ) ;
V_8 -> V_148 [ F_68 ( V_152 ) ] |= F_69 ( V_152 ) ;
switch ( V_2 -> V_30 ) {
case V_31 :
case V_93 :
F_70 ( V_8 , V_39 , 0 , 1023 , 0 , 0 ) ;
F_70 ( V_8 , V_40 , 0 , 767 , 0 , 0 ) ;
break;
case V_94 :
F_71 ( V_153 , V_8 -> V_154 ) ;
F_72 ( V_8 , 2 ) ;
F_70 ( V_8 , V_79 , 0 , V_73 , 0 , 0 ) ;
F_70 ( V_8 , V_80 , 0 , V_75 , 0 , 0 ) ;
F_71 ( V_90 , V_8 -> V_151 ) ;
F_71 ( V_91 , V_8 -> V_151 ) ;
F_71 ( V_92 , V_8 -> V_151 ) ;
case V_95 :
F_70 ( V_8 , V_39 , 0 , V_73 , 0 , 0 ) ;
F_70 ( V_8 , V_40 , 0 , V_75 , 0 , 0 ) ;
break;
}
F_70 ( V_8 , V_41 , 0 , 127 , 0 , 0 ) ;
if ( V_2 -> V_32 & V_44 ) {
V_8 -> V_148 [ F_68 ( V_147 ) ] |= F_69 ( V_147 ) ;
V_8 -> V_149 [ F_68 ( V_45 ) ] |= F_69 ( V_45 ) ;
}
if ( V_2 -> V_32 & ( V_33 | V_34 ) ) {
V_8 -> V_151 [ F_68 ( V_46 ) ] |= F_69 ( V_46 ) ;
V_8 -> V_151 [ F_68 ( V_47 ) ] |= F_69 ( V_47 ) ;
}
if ( V_2 -> V_32 & V_48 ) {
V_8 -> V_151 [ F_68 ( V_49 ) ] |= F_69 ( V_49 ) ;
V_8 -> V_151 [ F_68 ( V_50 ) ] |= F_69 ( V_50 ) ;
V_8 -> V_151 [ F_68 ( V_51 ) ] |= F_69 ( V_51 ) ;
V_8 -> V_151 [ F_68 ( V_52 ) ] |= F_69 ( V_52 ) ;
} else {
V_8 -> V_151 [ F_68 ( V_17 ) ] |= F_69 ( V_17 ) ;
}
snprintf ( V_19 -> V_155 , sizeof( V_19 -> V_155 ) , L_21 , V_6 -> V_102 . V_103 -> V_155 ) ;
V_9 -> V_155 = V_19 -> V_155 ;
V_9 -> V_156 = ( V_2 -> V_32 & V_35 ) ? L_22 : L_23 ;
V_9 -> V_157 . V_158 = V_159 ;
V_9 -> V_157 . V_160 = 0x0002 ;
V_9 -> V_157 . V_161 = V_162 ;
V_9 -> V_157 . V_119 = 0x0000 ;
V_9 -> V_13 . V_163 = & V_6 -> V_102 . V_103 -> V_13 ;
V_9 -> V_148 [ 0 ] = F_69 ( V_150 ) | F_69 ( V_147 ) ;
V_9 -> V_149 [ F_68 ( V_36 ) ] = F_69 ( V_36 ) | F_69 ( V_37 ) ;
V_9 -> V_151 [ F_68 ( V_14 ) ] =
F_69 ( V_14 ) | F_69 ( V_17 ) | F_69 ( V_16 ) ;
if ( F_73 ( V_19 -> V_9 ) )
goto V_146;
V_6 -> V_164 = F_29 ;
V_6 -> V_165 = F_49 ;
V_6 -> V_166 = F_59 ;
V_6 -> V_167 = F_57 ;
V_6 -> V_104 = V_2 -> V_30 == V_95 ? 8 : 6 ;
V_6 -> V_168 = 0 ;
return 0 ;
V_146:
F_58 ( V_6 ) ;
F_74 ( V_9 ) ;
F_62 ( V_19 ) ;
V_6 -> V_20 = NULL ;
return - 1 ;
}
int F_75 ( struct V_6 * V_6 , bool V_169 )
{
int V_119 ;
const struct V_1 * V_2 ;
V_2 = F_41 ( V_6 , & V_119 ) ;
if ( ! V_2 )
return - 1 ;
if ( V_169 ) {
V_6 -> V_160 = L_24 ;
V_6 -> V_156 = V_2 -> V_32 & V_35 ?
L_25 : L_26 ;
V_6 -> V_2 = V_119 ;
}
return 0 ;
}
