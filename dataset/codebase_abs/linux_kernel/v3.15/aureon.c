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
V_19 -> type = V_21 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . V_24 . V_25 = 3 ;
if ( V_19 -> V_23 . V_24 . V_26 >= V_19 -> V_23 . V_24 . V_25 )
V_19 -> V_23 . V_24 . V_26 = V_19 -> V_23 . V_24 . V_25 - 1 ;
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_20 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
return 0 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
V_29 -> V_23 . V_24 . V_26 [ 0 ] = V_31 -> V_32 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
unsigned char V_33 , V_34 ;
int V_35 ;
V_34 = V_29 -> V_23 . V_24 . V_26 [ 0 ] ;
if ( V_34 >= 3 )
return - V_36 ;
F_10 ( V_2 ) ;
V_33 = V_31 -> V_32 ;
V_35 = ( V_33 != V_34 ) ;
if ( V_35 ) {
F_1 ( V_2 , V_37 , V_34 ) ;
V_31 -> V_32 = V_34 ;
}
F_11 ( V_2 ) ;
return V_35 ;
}
static void F_12 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_10 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
unsigned int V_5 ;
V_5 = ( F_2 ( V_2 ) & ~ 0xFF ) | ( V_3 & 0x7F ) ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_38 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_38 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_39 ;
V_5 |= V_10 & V_39 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_40 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_40 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_39 ;
V_5 |= ( V_10 >> 8 ) & V_39 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_41 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_41 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 |= V_42 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_5 &= ~ V_42 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 10 ) ;
V_31 -> V_43 [ ( V_3 & 0x7F ) >> 1 ] = V_10 ;
}
static unsigned short F_13 ( struct V_1 * V_2 , unsigned short V_3 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
return V_31 -> V_43 [ ( V_3 & 0x7F ) >> 1 ] ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
int V_6 ;
static const unsigned short V_44 [] = {
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
V_5 = ( F_2 ( V_2 ) | V_45 ) & ~ V_39 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 3 ) ;
V_5 &= ~ V_45 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 3 ) ;
V_5 |= V_45 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 3 ) ;
memset ( & V_31 -> V_43 , 0 , sizeof( V_31 -> V_43 ) ) ;
for ( V_6 = 0 ; V_44 [ V_6 ] != ( unsigned short ) - 1 ; V_6 += 2 )
V_31 -> V_43 [ ( V_44 [ V_6 ] ) >> 1 ] = V_44 [ V_6 + 1 ] ;
F_12 ( V_2 , V_46 , 0x0000 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_47 ;
V_19 -> V_22 = V_17 -> V_48 & V_49 ? 2 : 1 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = 31 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_52 ;
F_17 ( & V_2 -> V_53 ) ;
V_52 = F_13 ( V_2 , V_17 -> V_48 & 0x7F ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = 0x1F - ( V_52 & 0x1F ) ;
if ( V_17 -> V_48 & V_49 )
V_29 -> V_23 . integer . V_23 [ 1 ] = 0x1F - ( ( V_52 >> 8 ) & 0x1F ) ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_54 , V_55 ;
int V_35 ;
F_10 ( V_2 ) ;
V_54 = F_13 ( V_2 , V_17 -> V_48 & 0x7F ) ;
V_55 = ( 0x1F - V_29 -> V_23 . integer . V_23 [ 0 ] ) & 0x001F ;
if ( V_17 -> V_48 & V_49 )
V_55 |= ( ( 0x1F - V_29 -> V_23 . integer . V_23 [ 1 ] ) << 8 ) & 0x1F00 ;
V_55 |= V_54 & ~ 0x1F1F ;
V_35 = ( V_54 != V_55 ) ;
if ( V_35 )
F_12 ( V_2 , V_17 -> V_48 & 0x7F , V_55 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_20 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_17 ( & V_2 -> V_53 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = F_13 ( V_2 ,
V_17 -> V_48 & 0x7F ) & 0x8000 ? 0 : 1 ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_54 , V_55 ;
int V_35 ;
F_10 ( V_2 ) ;
V_54 = F_13 ( V_2 , V_17 -> V_48 & 0x7F ) ;
V_55 = ( V_29 -> V_23 . integer . V_23 [ 0 ] ? 0x0000 : 0x8000 ) | ( V_54 & ~ 0x8000 ) ;
V_35 = ( V_54 != V_55 ) ;
if ( V_35 )
F_12 ( V_2 , V_17 -> V_48 & 0x7F , V_55 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_22 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_17 ( & V_2 -> V_53 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = F_13 ( V_2 , V_56 ) & 0x0020 ? 0 : 1 ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_54 , V_55 ;
int V_35 ;
F_10 ( V_2 ) ;
V_54 = F_13 ( V_2 , V_56 ) ;
V_55 = ( V_29 -> V_23 . integer . V_23 [ 0 ] ? 0x0000 : 0x0020 ) | ( V_54 & ~ 0x0020 ) ;
V_35 = ( V_54 != V_55 ) ;
if ( V_35 )
F_12 ( V_2 , V_56 , V_55 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_57 , unsigned int V_4 , int V_58 )
{
unsigned int V_5 ;
int V_6 ;
unsigned int V_59 , V_60 ;
V_5 = F_2 ( V_2 ) ;
if ( V_2 -> V_61 . V_62 == V_63 ||
V_2 -> V_61 . V_62 == V_64 ) {
F_3 ( V_2 , ~ ( V_65 | V_66 | V_67 ) ) ;
V_59 = V_65 ;
V_60 = V_66 ;
} else {
F_3 ( V_2 , ~ ( V_13 | V_11 | V_12 |
V_14 | V_15 ) ) ;
V_59 = V_11 ;
V_60 = V_12 ;
V_5 |= V_13 ;
}
V_5 &= ~ V_57 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
for ( V_6 = V_58 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_5 &= ~ V_60 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
if ( V_4 & ( 1 << V_6 ) )
V_5 |= V_59 ;
else
V_5 &= ~ V_59 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_60 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
V_5 &= ~ V_60 ;
V_5 |= V_57 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_60 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_57 ,
unsigned int V_4 , int V_58 , unsigned char * V_68 , int V_69 )
{
int V_6 , V_7 ;
unsigned int V_5 ;
V_5 = ( F_2 ( V_2 ) & ~ V_12 ) | V_15 | V_14 ;
F_4 ( V_2 , V_5 ) ;
V_5 &= ~ V_57 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
for ( V_6 = V_58 - 1 ; V_6 >= 0 ; V_6 -- ) {
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
for ( V_7 = 0 ; V_7 < V_69 ; V_7 ++ ) {
unsigned char V_70 = 0 ;
for ( V_6 = 7 ; V_6 >= 0 ; V_6 -- ) {
V_5 = F_2 ( V_2 ) ;
V_70 <<= 1 ;
V_70 |= ( V_5 & V_71 ) ? 1 : 0 ;
F_5 ( 1 ) ;
V_5 |= V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
}
V_68 [ V_7 ] = V_70 ;
}
V_5 |= V_57 ;
F_4 ( V_2 , V_5 ) ;
}
static unsigned char F_26 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_10 ;
F_24 ( V_2 , V_15 , 0x2000 | V_3 , 16 ) ;
F_25 ( V_2 , V_15 , 0x21 , 8 , & V_10 , 1 ) ;
return V_10 ;
}
static void F_27 ( struct V_1 * V_2 , int V_3 ,
unsigned char * V_68 , int V_69 )
{
F_24 ( V_2 , V_15 , 0x2000 | V_3 , 16 ) ;
F_25 ( V_2 , V_15 , 0x21 , 8 , V_68 , V_69 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
F_24 ( V_2 , V_15 , 0x200000 | ( V_3 << 8 ) | V_10 , 24 ) ;
}
static unsigned short F_29 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= 1 ;
return ( ( unsigned short ) V_2 -> V_72 [ 0 ] . V_73 [ V_3 ] << 8 ) |
V_2 -> V_72 [ 0 ] . V_73 [ V_3 + 1 ] ;
}
static void F_30 ( struct V_1 * V_2 , int V_3 , unsigned short V_10 )
{
F_24 ( V_2 ,
( ( V_2 -> V_61 . V_62 == V_63 ||
V_2 -> V_61 . V_62 == V_64 ) ?
V_67 : V_14 ) ,
( V_3 << 9 ) | ( V_10 & 0x1ff ) , 16 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 , unsigned short V_10 )
{
F_30 ( V_2 , V_3 , V_10 ) ;
V_3 <<= 1 ;
V_2 -> V_72 [ 0 ] . V_73 [ V_3 ] = V_10 >> 8 ;
V_2 -> V_72 [ 0 ] . V_73 [ V_3 + 1 ] = V_10 ;
}
static int F_32 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_17 ( & V_2 -> V_53 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = ( F_29 ( V_2 , V_74 ) >> 1 ) & 0x01 ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_54 , V_55 ;
int V_35 ;
F_10 ( V_2 ) ;
V_54 = F_29 ( V_2 , V_74 ) ;
V_55 = ( V_54 & ~ 0x02 ) | ( V_29 -> V_23 . integer . V_23 [ 0 ] ? 0x02 : 0x00 ) ;
V_35 = ( V_54 != V_55 ) ;
if ( V_35 )
F_31 ( V_2 , V_74 , V_55 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static void F_34 ( struct V_1 * V_2 , unsigned int V_75 , unsigned short V_52 , unsigned short V_76 )
{
unsigned char V_55 ;
if ( ( V_76 & V_77 ) || ( V_52 & V_77 ) ) {
V_55 = 0 ;
} else {
V_55 = ( ( V_52 % V_78 ) * ( V_76 % V_78 ) ) /
V_79 ;
V_55 += 0x1b ;
}
F_31 ( V_2 , V_75 , V_55 ) ;
F_30 ( V_2 , V_75 , 0x180 | V_55 ) ;
}
static int F_35 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_17 ( & V_2 -> V_53 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = ( F_29 ( V_2 , V_80 ) & 0x10 ) ? 0 : 1 ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_34 , V_33 ;
int V_35 ;
F_10 ( V_2 ) ;
V_33 = F_29 ( V_2 , V_80 ) ;
V_34 = ( V_33 & ~ 0x10 ) | ( V_29 -> V_23 . integer . V_23 [ 0 ] ? 0 : 0x10 ) ;
V_35 = ( V_33 != V_34 ) ;
if ( V_35 )
F_31 ( V_2 , V_80 , V_34 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_37 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_47 ;
V_19 -> V_22 = 2 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = V_79 ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ )
V_29 -> V_23 . integer . V_23 [ V_6 ] =
V_31 -> V_76 [ V_6 ] & ~ V_77 ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_81 , V_35 = 0 ;
F_10 ( V_2 ) ;
for ( V_81 = 0 ; V_81 < 2 ; V_81 ++ ) {
unsigned int V_52 = V_29 -> V_23 . integer . V_23 [ V_81 ] ;
if ( V_52 > V_79 )
V_52 = V_79 ;
V_52 |= V_31 -> V_76 [ V_81 ] & V_77 ;
if ( V_52 != V_31 -> V_76 [ V_81 ] ) {
int V_82 ;
V_31 -> V_76 [ V_81 ] = V_52 ;
for ( V_82 = 0 ; V_82 < V_2 -> V_83 ; V_82 += 2 )
F_34 ( V_2 , V_84 + V_82 + V_81 ,
V_31 -> V_52 [ V_82 + V_81 ] ,
V_31 -> V_76 [ V_81 ] ) ;
V_35 = 1 ;
}
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_40 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_85 = V_17 -> V_48 >> 8 ;
V_19 -> type = V_47 ;
V_19 -> V_22 = V_85 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = V_79 ;
return 0 ;
}
static int F_41 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_6 , V_86 , V_85 ;
V_85 = V_17 -> V_48 >> 8 ;
V_86 = V_17 -> V_48 & 0xff ;
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ )
V_29 -> V_23 . integer . V_23 [ V_6 ] =
V_31 -> V_52 [ V_86 + V_6 ] & ~ V_77 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_6 , V_87 , V_86 , V_85 ;
int V_35 = 0 ;
V_85 = V_17 -> V_48 >> 8 ;
V_86 = V_17 -> V_48 & 0xff ;
F_10 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ ) {
unsigned int V_52 = V_29 -> V_23 . integer . V_23 [ V_6 ] ;
if ( V_52 > V_79 )
V_52 = V_79 ;
V_52 |= V_31 -> V_52 [ V_86 + V_6 ] & V_77 ;
if ( V_52 != V_31 -> V_52 [ V_86 + V_6 ] ) {
V_31 -> V_52 [ V_86 + V_6 ] = V_52 ;
V_87 = V_84 + V_86 + V_6 ;
F_34 ( V_2 , V_87 , V_31 -> V_52 [ V_86 + V_6 ] ,
V_31 -> V_76 [ V_6 ] ) ;
V_35 = 1 ;
}
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_43 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_88 ;
V_19 -> V_22 = V_17 -> V_48 >> 8 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = 1 ;
return 0 ;
}
static int F_44 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_85 , V_86 , V_6 ;
V_85 = V_17 -> V_48 >> 8 ;
V_86 = V_17 -> V_48 & 0xFF ;
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ )
V_29 -> V_23 . integer . V_23 [ V_6 ] =
( V_31 -> V_52 [ V_86 + V_6 ] & V_77 ) ? 0 : 1 ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_35 = 0 , V_85 , V_86 , V_6 ;
V_85 = V_17 -> V_48 >> 8 ;
V_86 = V_17 -> V_48 & 0xFF ;
F_10 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ ) {
int V_10 = ( V_31 -> V_52 [ V_86 + V_6 ] & V_77 ) ? 0 : 1 ;
if ( V_29 -> V_23 . integer . V_23 [ V_6 ] != V_10 ) {
V_31 -> V_52 [ V_86 + V_6 ] &= ~ V_77 ;
V_31 -> V_52 [ V_86 + V_6 ] |=
V_29 -> V_23 . integer . V_23 [ V_6 ] ? 0 : V_77 ;
F_34 ( V_2 , V_86 + V_6 , V_31 -> V_52 [ V_86 + V_6 ] ,
V_31 -> V_76 [ V_6 ] ) ;
V_35 = 1 ;
}
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_46 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
V_29 -> V_23 . integer . V_23 [ 0 ] =
( V_31 -> V_76 [ 0 ] & V_77 ) ? 0 : 1 ;
V_29 -> V_23 . integer . V_23 [ 1 ] =
( V_31 -> V_76 [ 1 ] & V_77 ) ? 0 : 1 ;
return 0 ;
}
static int F_47 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
int V_35 = 0 , V_6 ;
F_10 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
int V_10 = ( V_31 -> V_76 [ V_6 ] & V_77 ) ? 0 : 1 ;
if ( V_29 -> V_23 . integer . V_23 [ V_6 ] != V_10 ) {
int V_82 ;
V_31 -> V_76 [ V_6 ] &= ~ V_77 ;
V_31 -> V_76 [ V_6 ] |=
V_29 -> V_23 . integer . V_23 [ V_6 ] ? 0 : V_77 ;
for ( V_82 = 0 ; V_82 < V_2 -> V_83 ; V_82 += 2 )
F_34 ( V_2 , V_84 + V_82 + V_6 ,
V_31 -> V_52 [ V_82 + V_6 ] ,
V_31 -> V_76 [ V_6 ] ) ;
V_35 = 1 ;
}
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_48 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_47 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = V_89 ;
return 0 ;
}
static int F_49 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_10 ;
F_17 ( & V_2 -> V_53 ) ;
V_10 = F_29 ( V_2 , V_90 ) & 0xff ;
V_10 = V_10 > V_91 ? ( V_10 - V_91 ) : 0 ;
V_29 -> V_23 . integer . V_23 [ 0 ] = V_10 ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_50 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_54 , V_55 ;
int V_35 = 0 ;
V_55 = V_29 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_55 > V_89 )
return - V_36 ;
F_10 ( V_2 ) ;
V_55 = ( V_55 ? ( V_55 + V_91 ) : 0 ) & 0xff ;
V_54 = F_29 ( V_2 , V_90 ) & 0xff ;
if ( V_54 != V_55 ) {
F_31 ( V_2 , V_90 , V_55 ) ;
F_30 ( V_2 , V_90 , V_55 | 0x100 ) ;
V_35 = 1 ;
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_51 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_10 ;
int V_6 ;
F_17 ( & V_2 -> V_53 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_10 = F_29 ( V_2 , V_92 + V_6 ) ;
V_29 -> V_23 . integer . V_23 [ V_6 ] = ~ V_10 >> 5 & 0x1 ;
}
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_52 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_93 , V_94 ;
int V_6 , V_35 = 0 ;
F_10 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_94 = F_29 ( V_2 , V_92 + V_6 ) ;
V_93 = ( ~ V_29 -> V_23 . integer . V_23 [ V_6 ] << 5 & 0x20 ) | ( V_94 & ~ 0x20 ) ;
if ( V_93 != V_94 ) {
F_31 ( V_2 , V_92 + V_6 , V_93 ) ;
V_35 = 1 ;
}
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_53 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_47 ;
V_19 -> V_22 = 2 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = 0x1f ;
return 0 ;
}
static int F_54 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_6 , V_87 ;
unsigned short V_52 ;
F_17 ( & V_2 -> V_53 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_87 = V_92 + V_6 ;
V_52 = F_29 ( V_2 , V_87 ) & 0x1f ;
V_29 -> V_23 . integer . V_23 [ V_6 ] = V_52 ;
}
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_55 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_6 , V_87 ;
unsigned short V_54 , V_55 ;
int V_35 = 0 ;
F_10 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_87 = V_92 + V_6 ;
V_55 = V_29 -> V_23 . integer . V_23 [ V_6 ] & 0x1f ;
V_54 = F_29 ( V_2 , V_87 ) ;
if ( ( V_54 & 0x1f ) != V_55 ) {
F_31 ( V_2 , V_87 , V_55 | ( V_54 & ~ 0x1f ) ) ;
V_35 = 1 ;
}
}
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_56 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
static const char * const V_20 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8
} ;
static const char * const V_95 [] = {
L_9 ,
L_4 ,
L_10 ,
L_6 ,
L_11 ,
L_7 ,
L_12 ,
L_8
} ;
struct V_1 * V_2 = F_8 ( V_17 ) ;
V_19 -> type = V_21 ;
V_19 -> V_22 = 2 ;
if ( V_2 -> V_61 . V_62 == V_96 ) {
V_19 -> V_23 . V_24 . V_25 = 8 ;
if ( V_19 -> V_23 . V_24 . V_26 >= V_19 -> V_23 . V_24 . V_25 )
V_19 -> V_23 . V_24 . V_26 = V_19 -> V_23 . V_24 . V_25 - 1 ;
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_95 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
} else {
V_19 -> V_23 . V_24 . V_25 = 5 ;
if ( V_19 -> V_23 . V_24 . V_26 >= V_19 -> V_23 . V_24 . V_25 )
V_19 -> V_23 . V_24 . V_26 = V_19 -> V_23 . V_24 . V_25 - 1 ;
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_20 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
}
return 0 ;
}
static int F_57 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_10 ;
F_17 ( & V_2 -> V_53 ) ;
V_10 = F_29 ( V_2 , V_97 ) ;
V_29 -> V_23 . V_24 . V_26 [ 0 ] = V_10 & 7 ;
V_29 -> V_23 . V_24 . V_26 [ 1 ] = ( V_10 >> 4 ) & 7 ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_58 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned short V_33 , V_34 ;
int V_35 ;
F_10 ( V_2 ) ;
V_33 = F_29 ( V_2 , V_97 ) ;
V_34 = V_33 & ~ 0x77 ;
V_34 |= V_29 -> V_23 . V_24 . V_26 [ 0 ] & 7 ;
V_34 |= ( V_29 -> V_23 . V_24 . V_26 [ 1 ] & 7 ) << 4 ;
V_35 = ( V_33 != V_34 ) ;
if ( V_35 )
F_31 ( V_2 , V_97 , V_34 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_59 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
static const char * const V_98 [] = {
L_4 ,
L_13
} ;
static const char * const V_99 [] = {
L_4 ,
L_14
} ;
V_19 -> type = V_21 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . V_24 . V_25 = 2 ;
if ( V_19 -> V_23 . V_24 . V_26 >= V_19 -> V_23 . V_24 . V_25 )
V_19 -> V_23 . V_24 . V_26 = V_19 -> V_23 . V_24 . V_25 - 1 ;
if ( V_2 -> V_61 . V_62 == V_100 )
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_99 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
else
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_98 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
return 0 ;
}
static int F_60 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
V_29 -> V_23 . V_24 . V_26 [ 0 ] = V_31 -> V_101 ;
return 0 ;
}
static int F_61 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
unsigned short V_33 , V_34 ;
int V_35 ;
F_10 ( V_2 ) ;
V_33 = F_26 ( V_2 , V_102 ) ;
V_34 = V_33 & ~ 0x07 ;
V_34 |= V_29 -> V_23 . V_24 . V_26 [ 0 ] & 7 ;
V_35 = ( V_33 != V_34 ) ;
if ( V_35 )
F_28 ( V_2 , V_102 , V_34 ) ;
F_11 ( V_2 ) ;
V_31 -> V_101 = V_29 -> V_23 . V_24 . V_26 [ 0 ] ;
return V_35 ;
}
static int F_62 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_47 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . integer . V_50 = 0 ;
V_19 -> V_23 . integer . V_51 = 192000 ;
return 0 ;
}
static int F_63 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned char V_103 ;
V_103 = F_26 ( V_2 , V_104 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = ( int ) ( ( unsigned int ) V_103 * 750 ) ;
return 0 ;
}
static int F_64 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_10 ( V_2 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = ( F_26 ( V_2 , V_105 ) & 0x20 ) ? 0 : 1 ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
unsigned char V_33 , V_34 ;
int V_35 ;
F_10 ( V_2 ) ;
V_33 = F_26 ( V_2 , V_105 ) ;
if ( V_29 -> V_23 . integer . V_23 [ 0 ] )
V_34 = V_33 & ~ 0x20 ;
else
V_34 = V_33 | 0x20 ;
V_35 = ( V_33 != V_34 ) ;
if ( V_35 )
F_28 ( V_2 , V_105 , V_34 ) ;
F_11 ( V_2 ) ;
return V_35 ;
}
static int F_66 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_106 ;
V_19 -> V_22 = 10 ;
return 0 ;
}
static int F_67 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_10 ( V_2 ) ;
F_27 ( V_2 , V_107 , V_29 -> V_23 . V_108 . V_4 , 10 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
V_19 -> type = V_109 ;
V_19 -> V_22 = 1 ;
return 0 ;
}
static int F_69 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
memset ( V_29 -> V_23 . V_110 . V_111 , 0xFF , 24 ) ;
return 0 ;
}
static int F_70 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_10 ( V_2 ) ;
F_27 ( V_2 , V_112 , V_29 -> V_23 . V_110 . V_111 , 24 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int V_113 )
{
unsigned int V_5 , V_114 ;
V_114 = V_5 = F_2 ( V_2 ) ;
if ( V_113 )
if ( V_2 -> V_61 . V_62 != V_63 &&
V_2 -> V_61 . V_62 != V_64 )
V_5 |= V_115 ;
else
V_5 |= V_116 ;
else
if ( V_2 -> V_61 . V_62 != V_63 &&
V_2 -> V_61 . V_62 != V_64 )
V_5 &= ~ V_115 ;
else
V_5 &= ~ V_116 ;
if ( V_5 != V_114 ) {
F_4 ( V_2 , V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_2 ( V_2 ) ;
return ( V_5 & V_115 ) != 0 ;
}
static int F_73 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = F_72 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
return F_71 ( V_2 , V_29 -> V_23 . integer . V_23 [ 0 ] ) ;
}
static int F_75 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = ( F_29 ( V_2 , V_117 ) & 0xf ) == 0xf ;
return 0 ;
}
static int F_76 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_118 , V_119 ;
V_119 = V_118 = F_29 ( V_2 , V_117 ) ;
if ( V_29 -> V_23 . integer . V_23 [ 0 ] )
V_118 |= 0xf ;
else
V_118 &= ~ 0xf ;
if ( V_118 != V_119 ) {
F_31 ( V_2 , V_117 , V_118 ) ;
return 1 ;
}
return 0 ;
}
static int F_77 ( struct V_16 * V_120 , struct V_18 * V_19 )
{
static const char * const V_20 [ 2 ] = { L_15 , L_16 } ;
V_19 -> type = V_21 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . V_24 . V_25 = 2 ;
if ( V_19 -> V_23 . V_24 . V_26 >= V_19 -> V_23 . V_24 . V_25 )
V_19 -> V_23 . V_24 . V_26 = V_19 -> V_23 . V_24 . V_25 - 1 ;
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_20 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
return 0 ;
}
static int F_78 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
V_29 -> V_23 . V_24 . V_26 [ 0 ] = ( F_29 ( V_2 , V_121 ) & 0x8 ) == 0x8 ;
return 0 ;
}
static int F_79 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
int V_118 , V_119 ;
struct V_1 * V_2 = F_8 ( V_17 ) ;
V_119 = V_118 = F_29 ( V_2 , V_121 ) ;
if ( V_29 -> V_23 . V_24 . V_26 [ 0 ] )
V_118 |= 0x8 ;
else
V_118 &= ~ 0x8 ;
if ( V_118 != V_119 ) {
F_31 ( V_2 , V_121 , V_118 ) ;
return 1 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
unsigned int V_6 , V_122 ;
int V_123 ;
V_122 = F_81 ( V_124 ) ;
if ( V_2 -> V_61 . V_62 == V_125 )
V_122 -= 2 ;
for ( V_6 = 0 ; V_6 < V_122 ; V_6 ++ ) {
V_123 = F_82 ( V_2 -> V_126 , F_83 ( & V_124 [ V_6 ] , V_2 ) ) ;
if ( V_123 < 0 )
return V_123 ;
}
for ( V_6 = 0 ; V_6 < F_81 ( V_127 ) ; V_6 ++ ) {
V_123 = F_82 ( V_2 -> V_126 , F_83 ( & V_127 [ V_6 ] , V_2 ) ) ;
if ( V_123 < 0 )
return V_123 ;
}
if ( V_2 -> V_61 . V_62 == V_96 ) {
for ( V_6 = 0 ; V_6 < F_81 ( V_128 ) ; V_6 ++ ) {
V_123 = F_82 ( V_2 -> V_126 , F_83 ( & V_128 [ V_6 ] , V_2 ) ) ;
if ( V_123 < 0 )
return V_123 ;
}
} else if ( V_2 -> V_61 . V_62 != V_63 &&
V_2 -> V_61 . V_62 != V_64 ) {
for ( V_6 = 0 ; V_6 < F_81 ( V_129 ) ; V_6 ++ ) {
V_123 = F_82 ( V_2 -> V_126 , F_83 ( & V_129 [ V_6 ] , V_2 ) ) ;
if ( V_123 < 0 )
return V_123 ;
}
}
if ( V_2 -> V_61 . V_62 != V_63 &&
V_2 -> V_61 . V_62 != V_64 ) {
unsigned char V_130 ;
F_10 ( V_2 ) ;
V_130 = F_26 ( V_2 , V_131 ) ;
if ( V_130 != 0x41 )
F_84 ( V_2 -> V_126 -> V_8 ,
L_17 ) ;
else if ( ( V_130 & 0x0F ) != 0x01 )
F_84 ( V_2 -> V_126 -> V_8 ,
L_18 ,
( char ) ( ( V_130 & 0x0F ) + 'A' - 1 ) ) ;
else {
for ( V_6 = 0 ; V_6 < F_81 ( V_132 ) ; V_6 ++ ) {
struct V_16 * V_133 ;
V_123 = F_82 ( V_2 -> V_126 , ( V_133 = F_83 ( & V_132 [ V_6 ] , V_2 ) ) ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_6 > 1 )
V_133 -> V_130 . V_134 = V_2 -> V_135 -> V_134 ;
}
}
F_11 ( V_2 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
static const unsigned short V_136 [] = {
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
static const unsigned short V_137 [] = {
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
static const unsigned short V_138 [] = {
0x0441 ,
0x0180 ,
0x0201 ,
0x0605 ,
( unsigned short ) - 1
} ;
unsigned int V_5 ;
const unsigned short * V_139 ;
int V_123 ;
struct V_30 * V_31 = V_2 -> V_31 ;
V_123 = F_14 ( V_2 ) ;
if ( V_123 != 0 )
return V_123 ;
F_86 ( V_2 , 0x5fffff ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , ~ ( V_140 | V_14 | V_15 | V_115 ) ) ;
V_5 = F_2 ( V_2 ) ;
V_5 &= ~ V_140 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_14 | V_15 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
V_5 |= V_140 ;
F_4 ( V_2 , V_5 ) ;
F_5 ( 1 ) ;
if ( V_2 -> V_61 . V_62 == V_100 ||
V_2 -> V_61 . V_62 == V_63 ||
V_2 -> V_61 . V_62 == V_64 )
V_139 = V_137 ;
else
V_139 = V_136 ;
for (; * V_139 != ( unsigned short ) - 1 ; V_139 += 2 )
F_31 ( V_2 , V_139 [ 0 ] , V_139 [ 1 ] ) ;
if ( V_2 -> V_61 . V_62 != V_63 &&
V_2 -> V_61 . V_62 != V_64 ) {
for ( V_139 = V_138 ; * V_139 != ( unsigned short ) - 1 ; V_139 ++ )
F_24 ( V_2 , V_15 , * V_139 | 0x200000 , 24 ) ;
V_31 -> V_101 = 1 ;
F_71 ( V_2 , 1 ) ;
}
F_11 ( V_2 ) ;
F_1 ( V_2 , V_141 , 0x00 ) ;
F_1 ( V_2 , V_37 , 0x00 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
int V_123 , V_6 ;
V_123 = F_85 ( V_2 ) ;
if ( V_123 != 0 )
return V_123 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_83 ; V_6 ++ )
F_34 ( V_2 , V_6 , V_31 -> V_52 [ V_6 ] , V_31 -> V_76 [ V_6 % 2 ] ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
int V_6 , V_123 ;
V_31 = F_89 ( sizeof( * V_31 ) , V_142 ) ;
if ( ! V_31 )
return - V_143 ;
V_2 -> V_31 = V_31 ;
if ( V_2 -> V_61 . V_62 == V_125 ) {
V_2 -> V_83 = 6 ;
V_2 -> V_144 = 2 ;
} else {
V_2 -> V_83 = 8 ;
V_2 -> V_144 = 2 ;
}
V_2 -> V_72 = F_89 ( sizeof( struct V_145 ) , V_142 ) ;
if ( ! V_2 -> V_72 )
return - V_143 ;
V_2 -> V_146 = 1 ;
V_123 = F_85 ( V_2 ) ;
if ( V_123 != 0 )
return V_123 ;
V_31 -> V_76 [ 0 ] = V_77 ;
V_31 -> V_76 [ 1 ] = V_77 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_83 ; V_6 ++ ) {
V_31 -> V_52 [ V_6 ] = V_77 ;
F_34 ( V_2 , V_6 , V_31 -> V_52 [ V_6 ] , V_31 -> V_76 [ V_6 % 2 ] ) ;
}
#ifdef F_90
V_2 -> V_147 = F_87 ;
V_2 -> V_148 = 1 ;
#endif
return 0 ;
}
