static void F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
unsigned int V_5 ;
int V_6 , V_7 ;
unsigned char V_8 = V_9 ;
unsigned char V_10 = 0 ;
V_5 = F_2 ( V_2 ) ;
F_3 ( V_2 , ~ ( V_11 | V_12 |
V_13 | V_14 |
V_15 ) ) ;
V_5 |= V_13 ;
V_5 |= V_15 | V_14 ;
V_5 &= ~ V_11 ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 50 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 50 ) ;
V_5 |= V_11 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 100 ) ;
V_5 &= ~ V_11 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 50 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 100 ) ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
switch ( V_7 ) {
case 0 :
V_10 = V_8 ;
break;
case 1 :
V_10 = V_3 ;
break;
case 2 :
V_10 = V_4 ;
break;
}
for ( V_6 = 7 ; V_6 >= 0 ; V_6 -- ) {
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
if ( V_10 & ( 1 << V_6 ) )
V_5 |= V_11 ;
else
V_5 &= ~ V_11 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
}
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
}
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
V_5 &= ~ V_11 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 40 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 50 ) ;
V_5 |= V_11 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 100 ) ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
static const char * const V_20 [ 3 ] =
{ L_1 , L_2 , L_3 } ;
return F_7 ( V_19 , 1 , 3 , V_20 ) ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_22 -> V_25 . V_26 . V_27 [ 0 ] = V_24 -> V_28 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
unsigned char V_29 , V_30 ;
int V_31 ;
V_30 = V_22 -> V_25 . V_26 . V_27 [ 0 ] ;
if ( V_30 >= 3 )
return - V_32 ;
F_11 ( V_2 ) ;
V_29 = V_24 -> V_28 ;
V_31 = ( V_29 != V_30 ) ;
if ( V_31 ) {
F_1 ( V_2 , V_33 , V_30 ) ;
V_24 -> V_28 = V_30 ;
}
F_12 ( V_2 ) ;
return V_31 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_10 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
unsigned int V_5 ;
V_5 = ( F_2 ( V_2 ) & ~ 0xFF ) | ( V_3 & 0x7F ) ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_34 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_34 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_35 ;
V_5 |= V_10 & V_35 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_36 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_36 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_35 ;
V_5 |= ( V_10 >> 8 ) & V_35 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_37 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_37 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_38 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_38 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_24 -> V_39 [ ( V_3 & 0x7F ) >> 1 ] = V_10 ;
}
static unsigned short F_14 ( struct V_1 * V_2 , unsigned short V_3 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
return V_24 -> V_39 [ ( V_3 & 0x7F ) >> 1 ] ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
int V_6 ;
static const unsigned short V_40 [] = {
0x00 , 0x9640 ,
0x02 , 0x8000 ,
0x04 , 0x8000 ,
0x06 , 0x8000 ,
0x0C , 0x8008 ,
0x0E , 0x8008 ,
0x10 , 0x8808 ,
0x12 , 0x8808 ,
0x14 , 0x8808 ,
0x16 , 0x8808 ,
0x18 , 0x8808 ,
0x1C , 0x8000 ,
0x26 , 0x000F ,
0x28 , 0x0201 ,
0x2C , 0xBB80 ,
0x32 , 0xBB80 ,
0x7C , 0x8384 ,
0x7E , 0x7644 ,
( unsigned short ) - 1
} ;
unsigned int V_5 ;
V_5 = ( F_2 ( V_2 ) | V_41 ) & ~ V_35 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 3 ) ;
V_5 &= ~ V_41 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 3 ) ;
V_5 |= V_41 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 3 ) ;
memset ( & V_24 -> V_39 , 0 , sizeof( V_24 -> V_39 ) ) ;
for ( V_6 = 0 ; V_40 [ V_6 ] != ( unsigned short ) - 1 ; V_6 += 2 )
V_24 -> V_39 [ ( V_40 [ V_6 ] ) >> 1 ] = V_40 [ V_6 + 1 ] ;
F_13 ( V_2 , V_42 , 0x0000 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_43 ;
V_19 -> V_44 = V_17 -> V_45 & V_46 ? 2 : 1 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = 31 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_49 ;
F_18 ( & V_2 -> V_50 ) ;
V_49 = F_14 ( V_2 , V_17 -> V_45 & 0x7F ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = 0x1F - ( V_49 & 0x1F ) ;
if ( V_17 -> V_45 & V_46 )
V_22 -> V_25 . integer . V_25 [ 1 ] = 0x1F - ( ( V_49 >> 8 ) & 0x1F ) ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_51 , V_52 ;
int V_31 ;
F_11 ( V_2 ) ;
V_51 = F_14 ( V_2 , V_17 -> V_45 & 0x7F ) ;
V_52 = ( 0x1F - V_22 -> V_25 . integer . V_25 [ 0 ] ) & 0x001F ;
if ( V_17 -> V_45 & V_46 )
V_52 |= ( ( 0x1F - V_22 -> V_25 . integer . V_25 [ 1 ] ) << 8 ) & 0x1F00 ;
V_52 |= V_51 & ~ 0x1F1F ;
V_31 = ( V_51 != V_52 ) ;
if ( V_31 )
F_13 ( V_2 , V_17 -> V_45 & 0x7F , V_52 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_18 ( & V_2 -> V_50 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = F_14 ( V_2 ,
V_17 -> V_45 & 0x7F ) & 0x8000 ? 0 : 1 ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_51 , V_52 ;
int V_31 ;
F_11 ( V_2 ) ;
V_51 = F_14 ( V_2 , V_17 -> V_45 & 0x7F ) ;
V_52 = ( V_22 -> V_25 . integer . V_25 [ 0 ] ? 0x0000 : 0x8000 ) | ( V_51 & ~ 0x8000 ) ;
V_31 = ( V_51 != V_52 ) ;
if ( V_31 )
F_13 ( V_2 , V_17 -> V_45 & 0x7F , V_52 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_23 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_18 ( & V_2 -> V_50 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = F_14 ( V_2 , V_53 ) & 0x0020 ? 0 : 1 ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_24 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_51 , V_52 ;
int V_31 ;
F_11 ( V_2 ) ;
V_51 = F_14 ( V_2 , V_53 ) ;
V_52 = ( V_22 -> V_25 . integer . V_25 [ 0 ] ? 0x0000 : 0x0020 ) | ( V_51 & ~ 0x0020 ) ;
V_31 = ( V_51 != V_52 ) ;
if ( V_31 )
F_13 ( V_2 , V_53 , V_52 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_54 , unsigned int V_4 , int V_55 )
{
unsigned int V_5 ;
int V_6 ;
unsigned int V_56 , V_57 ;
V_5 = F_2 ( V_2 ) ;
if ( V_2 -> V_58 . V_59 == V_60 ||
V_2 -> V_58 . V_59 == V_61 ) {
F_3 ( V_2 , ~ ( V_62 | V_63 | V_64 ) ) ;
V_56 = V_62 ;
V_57 = V_63 ;
} else {
F_3 ( V_2 , ~ ( V_13 | V_11 | V_12 |
V_14 | V_15 ) ) ;
V_56 = V_11 ;
V_57 = V_12 ;
V_5 |= V_13 ;
}
V_5 &= ~ V_54 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
for ( V_6 = V_55 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_5 &= ~ V_57 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
if ( V_4 & ( 1 << V_6 ) )
V_5 |= V_56 ;
else
V_5 &= ~ V_56 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_57 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
V_5 &= ~ V_57 ;
V_5 |= V_54 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_57 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned int V_4 , int V_55 , unsigned char * V_65 , int V_66 )
{
int V_6 , V_7 ;
unsigned int V_5 ;
V_5 = ( F_2 ( V_2 ) & ~ V_12 ) | V_15 | V_14 ;
F_4 ( V_2 , V_5 ) ;
V_5 &= ~ V_54 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
for ( V_6 = V_55 - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_4 & ( 1 << V_6 ) )
V_5 |= V_11 ;
else
V_5 &= ~ V_11 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
for ( V_7 = 0 ; V_7 < V_66 ; V_7 ++ ) {
unsigned char V_67 = 0 ;
for ( V_6 = 7 ; V_6 >= 0 ; V_6 -- ) {
V_5 = F_2 ( V_2 ) ;
V_67 <<= 1 ;
V_67 |= ( V_5 & V_68 ) ? 1 : 0 ;
F_5 ( 1 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
V_65 [ V_7 ] = V_67 ;
}
V_5 |= V_54 ;
F_4 ( V_2 , V_5 ) ;
}
static unsigned char F_27 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_10 ;
F_25 ( V_2 , V_15 , 0x2000 | V_3 , 16 ) ;
F_26 ( V_2 , V_15 , 0x21 , 8 , & V_10 , 1 ) ;
return V_10 ;
}
static void F_28 ( struct V_1 * V_2 , int V_3 ,
unsigned char * V_65 , int V_66 )
{
F_25 ( V_2 , V_15 , 0x2000 | V_3 , 16 ) ;
F_26 ( V_2 , V_15 , 0x21 , 8 , V_65 , V_66 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
F_25 ( V_2 , V_15 , 0x200000 | ( V_3 << 8 ) | V_10 , 24 ) ;
}
static unsigned short F_30 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= 1 ;
return ( ( unsigned short ) V_2 -> V_69 [ 0 ] . V_70 [ V_3 ] << 8 ) |
V_2 -> V_69 [ 0 ] . V_70 [ V_3 + 1 ] ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 , unsigned short V_10 )
{
F_25 ( V_2 ,
( ( V_2 -> V_58 . V_59 == V_60 ||
V_2 -> V_58 . V_59 == V_61 ) ?
V_64 : V_14 ) ,
( V_3 << 9 ) | ( V_10 & 0x1ff ) , 16 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_3 , unsigned short V_10 )
{
F_31 ( V_2 , V_3 , V_10 ) ;
V_3 <<= 1 ;
V_2 -> V_69 [ 0 ] . V_70 [ V_3 ] = V_10 >> 8 ;
V_2 -> V_69 [ 0 ] . V_70 [ V_3 + 1 ] = V_10 ;
}
static int F_33 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_18 ( & V_2 -> V_50 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = ( F_30 ( V_2 , V_71 ) >> 1 ) & 0x01 ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_34 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_51 , V_52 ;
int V_31 ;
F_11 ( V_2 ) ;
V_51 = F_30 ( V_2 , V_71 ) ;
V_52 = ( V_51 & ~ 0x02 ) | ( V_22 -> V_25 . integer . V_25 [ 0 ] ? 0x02 : 0x00 ) ;
V_31 = ( V_51 != V_52 ) ;
if ( V_31 )
F_32 ( V_2 , V_71 , V_52 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_72 , unsigned short V_49 , unsigned short V_73 )
{
unsigned char V_52 ;
if ( ( V_73 & V_74 ) || ( V_49 & V_74 ) ) {
V_52 = 0 ;
} else {
V_52 = ( ( V_49 % V_75 ) * ( V_73 % V_75 ) ) /
V_76 ;
V_52 += 0x1b ;
}
F_32 ( V_2 , V_72 , V_52 ) ;
F_31 ( V_2 , V_72 , 0x180 | V_52 ) ;
}
static int F_36 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_18 ( & V_2 -> V_50 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = ( F_30 ( V_2 , V_77 ) & 0x10 ) ? 0 : 1 ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_37 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_30 , V_29 ;
int V_31 ;
F_11 ( V_2 ) ;
V_29 = F_30 ( V_2 , V_77 ) ;
V_30 = ( V_29 & ~ 0x10 ) | ( V_22 -> V_25 . integer . V_25 [ 0 ] ? 0 : 0x10 ) ;
V_31 = ( V_29 != V_30 ) ;
if ( V_31 )
F_32 ( V_2 , V_77 , V_30 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_38 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_43 ;
V_19 -> V_44 = 2 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = V_76 ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ )
V_22 -> V_25 . integer . V_25 [ V_6 ] =
V_24 -> V_73 [ V_6 ] & ~ V_74 ;
return 0 ;
}
static int F_40 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_78 , V_31 = 0 ;
F_11 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
unsigned int V_49 = V_22 -> V_25 . integer . V_25 [ V_78 ] ;
if ( V_49 > V_76 )
V_49 = V_76 ;
V_49 |= V_24 -> V_73 [ V_78 ] & V_74 ;
if ( V_49 != V_24 -> V_73 [ V_78 ] ) {
int V_79 ;
V_24 -> V_73 [ V_78 ] = V_49 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_80 ; V_79 += 2 )
F_35 ( V_2 , V_81 + V_79 + V_78 ,
V_24 -> V_49 [ V_79 + V_78 ] ,
V_24 -> V_73 [ V_78 ] ) ;
V_31 = 1 ;
}
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_41 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_82 = V_17 -> V_45 >> 8 ;
V_19 -> type = V_43 ;
V_19 -> V_44 = V_82 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = V_76 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_6 , V_83 , V_82 ;
V_82 = V_17 -> V_45 >> 8 ;
V_83 = V_17 -> V_45 & 0xff ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ )
V_22 -> V_25 . integer . V_25 [ V_6 ] =
V_24 -> V_49 [ V_83 + V_6 ] & ~ V_74 ;
return 0 ;
}
static int F_43 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_6 , V_84 , V_83 , V_82 ;
int V_31 = 0 ;
V_82 = V_17 -> V_45 >> 8 ;
V_83 = V_17 -> V_45 & 0xff ;
F_11 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ ) {
unsigned int V_49 = V_22 -> V_25 . integer . V_25 [ V_6 ] ;
if ( V_49 > V_76 )
V_49 = V_76 ;
V_49 |= V_24 -> V_49 [ V_83 + V_6 ] & V_74 ;
if ( V_49 != V_24 -> V_49 [ V_83 + V_6 ] ) {
V_24 -> V_49 [ V_83 + V_6 ] = V_49 ;
V_84 = V_81 + V_83 + V_6 ;
F_35 ( V_2 , V_84 , V_24 -> V_49 [ V_83 + V_6 ] ,
V_24 -> V_73 [ V_6 ] ) ;
V_31 = 1 ;
}
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_44 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_85 ;
V_19 -> V_44 = V_17 -> V_45 >> 8 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = 1 ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_82 , V_83 , V_6 ;
V_82 = V_17 -> V_45 >> 8 ;
V_83 = V_17 -> V_45 & 0xFF ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ )
V_22 -> V_25 . integer . V_25 [ V_6 ] =
( V_24 -> V_49 [ V_83 + V_6 ] & V_74 ) ? 0 : 1 ;
return 0 ;
}
static int F_46 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_31 = 0 , V_82 , V_83 , V_6 ;
V_82 = V_17 -> V_45 >> 8 ;
V_83 = V_17 -> V_45 & 0xFF ;
F_11 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ ) {
int V_10 = ( V_24 -> V_49 [ V_83 + V_6 ] & V_74 ) ? 0 : 1 ;
if ( V_22 -> V_25 . integer . V_25 [ V_6 ] != V_10 ) {
V_24 -> V_49 [ V_83 + V_6 ] &= ~ V_74 ;
V_24 -> V_49 [ V_83 + V_6 ] |=
V_22 -> V_25 . integer . V_25 [ V_6 ] ? 0 : V_74 ;
F_35 ( V_2 , V_83 + V_6 , V_24 -> V_49 [ V_83 + V_6 ] ,
V_24 -> V_73 [ V_6 ] ) ;
V_31 = 1 ;
}
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_47 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_22 -> V_25 . integer . V_25 [ 0 ] =
( V_24 -> V_73 [ 0 ] & V_74 ) ? 0 : 1 ;
V_22 -> V_25 . integer . V_25 [ 1 ] =
( V_24 -> V_73 [ 1 ] & V_74 ) ? 0 : 1 ;
return 0 ;
}
static int F_48 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_31 = 0 , V_6 ;
F_11 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
int V_10 = ( V_24 -> V_73 [ V_6 ] & V_74 ) ? 0 : 1 ;
if ( V_22 -> V_25 . integer . V_25 [ V_6 ] != V_10 ) {
int V_79 ;
V_24 -> V_73 [ V_6 ] &= ~ V_74 ;
V_24 -> V_73 [ V_6 ] |=
V_22 -> V_25 . integer . V_25 [ V_6 ] ? 0 : V_74 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_80 ; V_79 += 2 )
F_35 ( V_2 , V_81 + V_79 + V_6 ,
V_24 -> V_49 [ V_79 + V_6 ] ,
V_24 -> V_73 [ V_6 ] ) ;
V_31 = 1 ;
}
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_49 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_43 ;
V_19 -> V_44 = 1 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = V_86 ;
return 0 ;
}
static int F_50 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_10 ;
F_18 ( & V_2 -> V_50 ) ;
V_10 = F_30 ( V_2 , V_87 ) & 0xff ;
V_10 = V_10 > V_88 ? ( V_10 - V_88 ) : 0 ;
V_22 -> V_25 . integer . V_25 [ 0 ] = V_10 ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_51 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_51 , V_52 ;
int V_31 = 0 ;
V_52 = V_22 -> V_25 . integer . V_25 [ 0 ] ;
if ( V_52 > V_86 )
return - V_32 ;
F_11 ( V_2 ) ;
V_52 = ( V_52 ? ( V_52 + V_88 ) : 0 ) & 0xff ;
V_51 = F_30 ( V_2 , V_87 ) & 0xff ;
if ( V_51 != V_52 ) {
F_32 ( V_2 , V_87 , V_52 ) ;
F_31 ( V_2 , V_87 , V_52 | 0x100 ) ;
V_31 = 1 ;
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_52 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_10 ;
int V_6 ;
F_18 ( & V_2 -> V_50 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_10 = F_30 ( V_2 , V_89 + V_6 ) ;
V_22 -> V_25 . integer . V_25 [ V_6 ] = ~ V_10 >> 5 & 0x1 ;
}
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_90 , V_91 ;
int V_6 , V_31 = 0 ;
F_11 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_91 = F_30 ( V_2 , V_89 + V_6 ) ;
V_90 = ( ~ V_22 -> V_25 . integer . V_25 [ V_6 ] << 5 & 0x20 ) | ( V_91 & ~ 0x20 ) ;
if ( V_90 != V_91 ) {
F_32 ( V_2 , V_89 + V_6 , V_90 ) ;
V_31 = 1 ;
}
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_54 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_43 ;
V_19 -> V_44 = 2 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = 0x1f ;
return 0 ;
}
static int F_55 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_6 , V_84 ;
unsigned short V_49 ;
F_18 ( & V_2 -> V_50 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_84 = V_89 + V_6 ;
V_49 = F_30 ( V_2 , V_84 ) & 0x1f ;
V_22 -> V_25 . integer . V_25 [ V_6 ] = V_49 ;
}
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_56 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_6 , V_84 ;
unsigned short V_51 , V_52 ;
int V_31 = 0 ;
F_11 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_84 = V_89 + V_6 ;
V_52 = V_22 -> V_25 . integer . V_25 [ V_6 ] & 0x1f ;
V_51 = F_30 ( V_2 , V_84 ) ;
if ( ( V_51 & 0x1f ) != V_52 ) {
F_32 ( V_2 , V_84 , V_52 | ( V_51 & ~ 0x1f ) ) ;
V_31 = 1 ;
}
}
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_57 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
static const char * const V_20 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8
} ;
static const char * const V_92 [] = {
L_9 ,
L_4 ,
L_10 ,
L_6 ,
L_11 ,
L_7 ,
L_12 ,
L_8
} ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( V_2 -> V_58 . V_59 == V_93 )
return F_7 ( V_19 , 2 , 8 , V_92 ) ;
else
return F_7 ( V_19 , 2 , 5 , V_20 ) ;
}
static int F_58 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_10 ;
F_18 ( & V_2 -> V_50 ) ;
V_10 = F_30 ( V_2 , V_94 ) ;
V_22 -> V_25 . V_26 . V_27 [ 0 ] = V_10 & 7 ;
V_22 -> V_25 . V_26 . V_27 [ 1 ] = ( V_10 >> 4 ) & 7 ;
F_19 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_59 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned short V_29 , V_30 ;
int V_31 ;
F_11 ( V_2 ) ;
V_29 = F_30 ( V_2 , V_94 ) ;
V_30 = V_29 & ~ 0x77 ;
V_30 |= V_22 -> V_25 . V_26 . V_27 [ 0 ] & 7 ;
V_30 |= ( V_22 -> V_25 . V_26 . V_27 [ 1 ] & 7 ) << 4 ;
V_31 = ( V_29 != V_30 ) ;
if ( V_31 )
F_32 ( V_2 , V_94 , V_30 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_60 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
static const char * const V_95 [] = {
L_4 ,
L_13
} ;
static const char * const V_96 [] = {
L_4 ,
L_14
} ;
if ( V_2 -> V_58 . V_59 == V_97 )
return F_7 ( V_19 , 1 , 2 , V_96 ) ;
else
return F_7 ( V_19 , 1 , 2 , V_95 ) ;
}
static int F_61 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_22 -> V_25 . V_26 . V_27 [ 0 ] = V_24 -> V_98 ;
return 0 ;
}
static int F_62 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
unsigned short V_29 , V_30 ;
int V_31 ;
F_11 ( V_2 ) ;
V_29 = F_27 ( V_2 , V_99 ) ;
V_30 = V_29 & ~ 0x07 ;
V_30 |= V_22 -> V_25 . V_26 . V_27 [ 0 ] & 7 ;
V_31 = ( V_29 != V_30 ) ;
if ( V_31 )
F_29 ( V_2 , V_99 , V_30 ) ;
F_12 ( V_2 ) ;
V_24 -> V_98 = V_22 -> V_25 . V_26 . V_27 [ 0 ] ;
return V_31 ;
}
static int F_63 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_43 ;
V_19 -> V_44 = 1 ;
V_19 -> V_25 . integer . V_47 = 0 ;
V_19 -> V_25 . integer . V_48 = 192000 ;
return 0 ;
}
static int F_64 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_100 ;
V_100 = F_27 ( V_2 , V_101 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = ( int ) ( ( unsigned int ) V_100 * 750 ) ;
return 0 ;
}
static int F_65 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_11 ( V_2 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = ( F_27 ( V_2 , V_102 ) & 0x20 ) ? 0 : 1 ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned char V_29 , V_30 ;
int V_31 ;
F_11 ( V_2 ) ;
V_29 = F_27 ( V_2 , V_102 ) ;
if ( V_22 -> V_25 . integer . V_25 [ 0 ] )
V_30 = V_29 & ~ 0x20 ;
else
V_30 = V_29 | 0x20 ;
V_31 = ( V_29 != V_30 ) ;
if ( V_31 )
F_29 ( V_2 , V_102 , V_30 ) ;
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_67 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_103 ;
V_19 -> V_44 = 10 ;
return 0 ;
}
static int F_68 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_11 ( V_2 ) ;
F_28 ( V_2 , V_104 , V_22 -> V_25 . V_105 . V_4 , 10 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_106 ;
V_19 -> V_44 = 1 ;
return 0 ;
}
static int F_70 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
memset ( V_22 -> V_25 . V_107 . V_108 , 0xFF , 24 ) ;
return 0 ;
}
static int F_71 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_11 ( V_2 ) ;
F_28 ( V_2 , V_109 , V_22 -> V_25 . V_107 . V_108 , 24 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , int V_110 )
{
unsigned int V_5 , V_111 ;
V_111 = V_5 = F_2 ( V_2 ) ;
if ( V_110 )
if ( V_2 -> V_58 . V_59 != V_60 &&
V_2 -> V_58 . V_59 != V_61 )
V_5 |= V_112 ;
else
V_5 |= V_113 ;
else
if ( V_2 -> V_58 . V_59 != V_60 &&
V_2 -> V_58 . V_59 != V_61 )
V_5 &= ~ V_112 ;
else
V_5 &= ~ V_113 ;
if ( V_5 != V_111 ) {
F_4 ( V_2 , V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_2 ( V_2 ) ;
return ( V_5 & V_112 ) != 0 ;
}
static int F_74 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = F_73 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
return F_72 ( V_2 , V_22 -> V_25 . integer . V_25 [ 0 ] ) ;
}
static int F_76 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_22 -> V_25 . integer . V_25 [ 0 ] = ( F_30 ( V_2 , V_114 ) & 0xf ) == 0xf ;
return 0 ;
}
static int F_77 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_115 , V_116 ;
V_116 = V_115 = F_30 ( V_2 , V_114 ) ;
if ( V_22 -> V_25 . integer . V_25 [ 0 ] )
V_115 |= 0xf ;
else
V_115 &= ~ 0xf ;
if ( V_115 != V_116 ) {
F_32 ( V_2 , V_114 , V_115 ) ;
return 1 ;
}
return 0 ;
}
static int F_78 ( struct V_16 * V_117 , struct V_18 * V_19 )
{
static const char * const V_20 [ 2 ] = { L_15 , L_16 } ;
return F_7 ( V_19 , 1 , 2 , V_20 ) ;
}
static int F_79 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_22 -> V_25 . V_26 . V_27 [ 0 ] = ( F_30 ( V_2 , V_118 ) & 0x8 ) == 0x8 ;
return 0 ;
}
static int F_80 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
int V_115 , V_116 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_116 = V_115 = F_30 ( V_2 , V_118 ) ;
if ( V_22 -> V_25 . V_26 . V_27 [ 0 ] )
V_115 |= 0x8 ;
else
V_115 &= ~ 0x8 ;
if ( V_115 != V_116 ) {
F_32 ( V_2 , V_118 , V_115 ) ;
return 1 ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
unsigned int V_6 , V_119 ;
int V_120 ;
V_119 = F_82 ( V_121 ) ;
if ( V_2 -> V_58 . V_59 == V_122 )
V_119 -= 2 ;
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ ) {
V_120 = F_83 ( V_2 -> V_123 , F_84 ( & V_121 [ V_6 ] , V_2 ) ) ;
if ( V_120 < 0 )
return V_120 ;
}
for ( V_6 = 0 ; V_6 < F_82 ( V_124 ) ; V_6 ++ ) {
V_120 = F_83 ( V_2 -> V_123 , F_84 ( & V_124 [ V_6 ] , V_2 ) ) ;
if ( V_120 < 0 )
return V_120 ;
}
if ( V_2 -> V_58 . V_59 == V_93 ) {
for ( V_6 = 0 ; V_6 < F_82 ( V_125 ) ; V_6 ++ ) {
V_120 = F_83 ( V_2 -> V_123 , F_84 ( & V_125 [ V_6 ] , V_2 ) ) ;
if ( V_120 < 0 )
return V_120 ;
}
} else if ( V_2 -> V_58 . V_59 != V_60 &&
V_2 -> V_58 . V_59 != V_61 ) {
for ( V_6 = 0 ; V_6 < F_82 ( V_126 ) ; V_6 ++ ) {
V_120 = F_83 ( V_2 -> V_123 , F_84 ( & V_126 [ V_6 ] , V_2 ) ) ;
if ( V_120 < 0 )
return V_120 ;
}
}
if ( V_2 -> V_58 . V_59 != V_60 &&
V_2 -> V_58 . V_59 != V_61 ) {
unsigned char V_127 ;
F_11 ( V_2 ) ;
V_127 = F_27 ( V_2 , V_128 ) ;
if ( V_127 != 0x41 )
F_85 ( V_2 -> V_123 -> V_8 ,
L_17 ) ;
else if ( ( V_127 & 0x0F ) != 0x01 )
F_85 ( V_2 -> V_123 -> V_8 ,
L_18 ,
( char ) ( ( V_127 & 0x0F ) + 'A' - 1 ) ) ;
else {
for ( V_6 = 0 ; V_6 < F_82 ( V_129 ) ; V_6 ++ ) {
struct V_16 * V_130 ;
V_120 = F_83 ( V_2 -> V_123 , ( V_130 = F_84 ( & V_129 [ V_6 ] , V_2 ) ) ) ;
if ( V_120 < 0 )
return V_120 ;
if ( V_6 > 1 )
V_130 -> V_127 . V_131 = V_2 -> V_132 -> V_131 ;
}
}
F_12 ( V_2 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
static const unsigned short V_133 [] = {
0x1b , 0x044 ,
0x1c , 0x00B ,
0x1d , 0x009 ,
0x18 , 0x000 ,
0x16 , 0x122 ,
0x17 , 0x022 ,
0x00 , 0 ,
0x01 , 0 ,
0x02 , 0 ,
0x03 , 0 ,
0x04 , 0 ,
0x05 , 0 ,
0x06 , 0 ,
0x07 , 0 ,
0x08 , 0x100 ,
0x09 , 0xff ,
0x0a , 0xff ,
0x0b , 0xff ,
0x0c , 0xff ,
0x0d , 0xff ,
0x0e , 0xff ,
0x0f , 0xff ,
0x10 , 0xff ,
0x11 , 0x1ff ,
0x12 , 0x000 ,
0x13 , 0x090 ,
0x14 , 0x000 ,
0x15 , 0x000 ,
0x19 , 0x000 ,
0x1a , 0x000 ,
( unsigned short ) - 1
} ;
static const unsigned short V_134 [] = {
0x1b , 0x000 ,
0x1c , 0x009 ,
0x1d , 0x009 ,
0x18 , 0x000 ,
0x16 , 0x022 ,
0x17 , 0x006 ,
0x00 , 0 ,
0x01 , 0 ,
0x02 , 0 ,
0x03 , 0 ,
0x04 , 0 ,
0x05 , 0 ,
0x06 , 0 ,
0x07 , 0 ,
0x08 , 0x100 ,
0x09 , 0x7f ,
0x0a , 0x7f ,
0x0b , 0x7f ,
0x0c , 0x7f ,
0x0d , 0x7f ,
0x0e , 0x7f ,
0x0f , 0x7f ,
0x10 , 0x7f ,
0x11 , 0x1FF ,
0x12 , 0x000 ,
0x13 , 0x090 ,
0x14 , 0x000 ,
0x15 , 0x000 ,
0x19 , 0x000 ,
0x1a , 0x000 ,
( unsigned short ) - 1
} ;
static const unsigned short V_135 [] = {
0x0441 ,
0x0180 ,
0x0201 ,
0x0605 ,
( unsigned short ) - 1
} ;
unsigned int V_5 ;
const unsigned short * V_136 ;
int V_120 ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_120 = F_15 ( V_2 ) ;
if ( V_120 != 0 )
return V_120 ;
F_87 ( V_2 , 0x5fffff ) ;
F_11 ( V_2 ) ;
F_3 ( V_2 , ~ ( V_137 | V_14 | V_15 | V_112 ) ) ;
V_5 = F_2 ( V_2 ) ;
V_5 &= ~ V_137 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_14 | V_15 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_137 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
if ( V_2 -> V_58 . V_59 == V_97 ||
V_2 -> V_58 . V_59 == V_60 ||
V_2 -> V_58 . V_59 == V_61 )
V_136 = V_134 ;
else
V_136 = V_133 ;
for (; * V_136 != ( unsigned short ) - 1 ; V_136 += 2 )
F_32 ( V_2 , V_136 [ 0 ] , V_136 [ 1 ] ) ;
if ( V_2 -> V_58 . V_59 != V_60 &&
V_2 -> V_58 . V_59 != V_61 ) {
for ( V_136 = V_135 ; * V_136 != ( unsigned short ) - 1 ; V_136 ++ )
F_25 ( V_2 , V_15 , * V_136 | 0x200000 , 24 ) ;
V_24 -> V_98 = 1 ;
F_72 ( V_2 , 1 ) ;
}
F_12 ( V_2 ) ;
F_1 ( V_2 , V_138 , 0x00 ) ;
F_1 ( V_2 , V_33 , 0x00 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
int V_120 , V_6 ;
V_120 = F_86 ( V_2 ) ;
if ( V_120 != 0 )
return V_120 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_80 ; V_6 ++ )
F_35 ( V_2 , V_6 , V_24 -> V_49 [ V_6 ] , V_24 -> V_73 [ V_6 % 2 ] ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
int V_6 , V_120 ;
V_24 = F_90 ( sizeof( * V_24 ) , V_139 ) ;
if ( ! V_24 )
return - V_140 ;
V_2 -> V_24 = V_24 ;
if ( V_2 -> V_58 . V_59 == V_122 ) {
V_2 -> V_80 = 6 ;
V_2 -> V_141 = 2 ;
} else {
V_2 -> V_80 = 8 ;
V_2 -> V_141 = 2 ;
}
V_2 -> V_69 = F_90 ( sizeof( struct V_142 ) , V_139 ) ;
if ( ! V_2 -> V_69 )
return - V_140 ;
V_2 -> V_143 = 1 ;
V_120 = F_86 ( V_2 ) ;
if ( V_120 != 0 )
return V_120 ;
V_24 -> V_73 [ 0 ] = V_74 ;
V_24 -> V_73 [ 1 ] = V_74 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_80 ; V_6 ++ ) {
V_24 -> V_49 [ V_6 ] = V_74 ;
F_35 ( V_2 , V_6 , V_24 -> V_49 [ V_6 ] , V_24 -> V_73 [ V_6 % 2 ] ) ;
}
#ifdef F_91
V_2 -> V_144 = F_88 ;
V_2 -> V_145 = 1 ;
#endif
return 0 ;
}
