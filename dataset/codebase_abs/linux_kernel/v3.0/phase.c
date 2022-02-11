static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
switch ( V_2 -> V_6 . V_7 ) {
case V_8 :
case V_9 :
V_2 -> V_10 = 2 ;
V_2 -> V_11 = 2 ;
V_2 -> V_12 = 1 ;
break;
default:
F_2 () ;
return - V_13 ;
}
V_2 -> V_14 = F_3 ( sizeof( struct V_3 ) , V_15 ) ;
V_4 = V_2 -> V_14 ;
if ( ! V_4 )
return - V_16 ;
V_2 -> V_17 = 1 ;
switch ( V_2 -> V_6 . V_7 ) {
case V_8 :
case V_9 :
V_5 = F_4 ( V_4 , & V_18 ,
& V_19 , V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
}
return 0 ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
switch ( V_2 -> V_6 . V_7 ) {
case V_8 :
case V_9 :
V_5 = F_6 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_20 ,
unsigned int V_21 , int V_22 )
{
unsigned int V_23 ;
int V_24 ;
V_23 = F_8 ( V_2 ) ;
F_9 ( V_2 , ~ ( V_25 | V_26 |
V_27 | V_28 ) ) ;
V_23 |= V_25 ;
V_23 &= ~ V_20 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
for ( V_24 = V_22 - 1 ; V_24 >= 0 ; V_24 -- ) {
V_23 &= ~ V_27 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
if ( V_21 & ( 1 << V_24 ) )
V_23 |= V_26 ;
else
V_23 &= ~ V_26 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
V_23 |= V_27 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
}
V_23 &= ~ V_27 ;
V_23 |= V_20 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
V_23 |= V_27 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
}
static unsigned short F_12 ( struct V_1 * V_2 , int V_29 )
{
V_29 <<= 1 ;
return ( ( unsigned short ) V_2 -> V_14 [ 0 ] . V_30 [ V_29 ] << 8 ) |
V_2 -> V_14 [ 0 ] . V_30 [ V_29 + 1 ] ;
}
static void F_13 ( struct V_1 * V_2 , int V_29 , unsigned short V_31 )
{
F_7 ( V_2 , V_28 , ( V_29 << 9 ) | ( V_31 & 0x1ff ) , 16 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_29 , unsigned short V_31 )
{
F_13 ( V_2 , V_29 , V_31 ) ;
V_29 <<= 1 ;
V_2 -> V_14 [ 0 ] . V_30 [ V_29 ] = V_31 >> 8 ;
V_2 -> V_14 [ 0 ] . V_30 [ V_29 + 1 ] = V_31 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned short V_33 , unsigned short V_34 )
{
unsigned char V_35 ;
if ( ( V_34 & V_36 ) || ( V_33 & V_36 ) )
V_35 = 0 ;
else
V_35 = 127 - V_37 [ ( ( ( V_33 & ~ V_36 ) *
( V_34 & ~ V_36 ) ) / 127 ) & V_38 ] ;
F_14 ( V_2 , V_32 , V_35 ) ;
F_13 ( V_2 , V_32 , 0x180 | V_35 ) ;
}
static int F_16 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
F_18 ( & V_2 -> V_43 ) ;
V_42 -> V_44 . integer . V_44 [ 0 ] = ( F_12 ( V_2 , V_45 ) & 0x10 ) ?
0 : 1 ;
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
unsigned short V_46 , V_47 ;
int V_48 ;
F_21 ( V_2 ) ;
V_47 = F_12 ( V_2 , V_45 ) ;
V_46 = ( V_47 & ~ 0x10 ) | ( V_42 -> V_44 . integer . V_44 [ 0 ] ? 0 : 0x10 ) ;
V_48 = ( V_46 != V_47 ) ;
if ( V_48 )
F_14 ( V_2 , V_45 , V_46 ) ;
F_22 ( V_2 ) ;
return V_48 ;
}
static int F_23 ( struct V_39 * V_40 ,
struct V_49 * V_50 )
{
V_50 -> type = V_51 ;
V_50 -> V_52 = 2 ;
V_50 -> V_44 . integer . V_53 = 0 ;
V_50 -> V_44 . integer . V_54 = V_38 ;
return 0 ;
}
static int F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ )
V_42 -> V_44 . integer . V_44 [ V_24 ] = V_56 -> V_34 [ V_24 ] &
~ V_36 ;
return 0 ;
}
static int F_25 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_57 , V_48 = 0 ;
F_21 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
unsigned int V_33 = V_42 -> V_44 . integer . V_44 [ V_57 ] ;
if ( V_33 > V_38 )
continue;
V_33 |= V_56 -> V_34 [ V_57 ] & V_36 ;
if ( V_33 != V_56 -> V_34 [ V_57 ] ) {
int V_58 ;
V_56 -> V_34 [ V_57 ] = V_33 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_10 ; V_58 += 2 )
F_15 ( V_2 , V_59 + V_58 + V_57 ,
V_56 -> V_33 [ V_58 + V_57 ] ,
V_56 -> V_34 [ V_57 ] ) ;
V_48 = 1 ;
}
}
F_22 ( V_2 ) ;
return V_48 ;
}
static int T_1 F_26 ( struct V_1 * V_2 )
{
static const unsigned short V_60 [] = {
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
unsigned int V_23 ;
struct V_3 * V_4 ;
struct V_55 * V_56 ;
const unsigned short * V_61 ;
int V_24 ;
V_2 -> V_10 = 8 ;
V_2 -> V_11 = 2 ;
V_56 = F_3 ( sizeof( * V_56 ) , V_15 ) ;
if ( ! V_56 )
return - V_16 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_14 = F_3 ( sizeof( struct V_3 ) , V_15 ) ;
V_4 = V_2 -> V_14 ;
if ( ! V_4 )
return - V_16 ;
V_2 -> V_17 = 1 ;
F_27 ( V_2 , 0x5fffff ) ;
F_21 ( V_2 ) ;
F_9 ( V_2 , ~ ( V_62 | V_28 |
V_63 ) ) ;
V_23 = F_8 ( V_2 ) ;
V_23 &= ~ V_62 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
V_23 |= V_28 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
V_23 |= V_62 ;
F_10 ( V_2 , V_23 ) ;
F_11 ( 1 ) ;
V_61 = V_60 ;
for (; * V_61 != ( unsigned short ) - 1 ; V_61 += 2 )
F_14 ( V_2 , V_61 [ 0 ] , V_61 [ 1 ] ) ;
F_22 ( V_2 ) ;
V_56 -> V_34 [ 0 ] = V_36 ;
V_56 -> V_34 [ 1 ] = V_36 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_10 ; V_24 ++ ) {
V_56 -> V_33 [ V_24 ] = V_36 ;
F_15 ( V_2 , V_24 , V_56 -> V_33 [ V_24 ] , V_56 -> V_34 [ V_24 % 2 ] ) ;
}
return 0 ;
}
static int F_28 ( struct V_39 * V_40 ,
struct V_49 * V_50 )
{
int V_64 = V_40 -> V_65 >> 8 ;
V_50 -> type = V_51 ;
V_50 -> V_52 = V_64 ;
V_50 -> V_44 . integer . V_53 = 0 ;
V_50 -> V_44 . integer . V_54 = 0x7F ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_24 , V_66 , V_64 ;
V_64 = V_40 -> V_65 >> 8 ;
V_66 = V_40 -> V_65 & 0xff ;
for ( V_24 = 0 ; V_24 < V_64 ; V_24 ++ )
V_42 -> V_44 . integer . V_44 [ V_24 ] =
V_56 -> V_33 [ V_66 + V_24 ] & ~ V_36 ;
return 0 ;
}
static int F_30 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_24 , V_67 , V_66 , V_64 ;
int V_48 = 0 ;
V_64 = V_40 -> V_65 >> 8 ;
V_66 = V_40 -> V_65 & 0xff ;
F_21 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_64 ; V_24 ++ ) {
unsigned int V_33 ;
V_33 = V_42 -> V_44 . integer . V_44 [ V_24 ] ;
if ( V_33 > 0x7f )
continue;
V_33 |= V_56 -> V_33 [ V_66 + V_24 ] & V_36 ;
if ( V_33 != V_56 -> V_33 [ V_66 + V_24 ] ) {
V_56 -> V_33 [ V_66 + V_24 ] = V_33 ;
V_67 = V_59 + V_66 + V_24 ;
F_15 ( V_2 , V_67 , V_56 -> V_33 [ V_66 + V_24 ] ,
V_56 -> V_34 [ V_24 ] ) ;
V_48 = 1 ;
}
}
F_22 ( V_2 ) ;
return V_48 ;
}
static int F_31 ( struct V_39 * V_40 ,
struct V_49 * V_50 ) {
V_50 -> type = V_68 ;
V_50 -> V_52 = V_40 -> V_65 >> 8 ;
V_50 -> V_44 . integer . V_53 = 0 ;
V_50 -> V_44 . integer . V_54 = 1 ;
return 0 ;
}
static int F_32 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_64 , V_66 , V_24 ;
V_64 = V_40 -> V_65 >> 8 ;
V_66 = V_40 -> V_65 & 0xFF ;
for ( V_24 = 0 ; V_24 < V_64 ; V_24 ++ )
V_42 -> V_44 . integer . V_44 [ V_24 ] =
( V_56 -> V_33 [ V_66 + V_24 ] & V_36 ) ? 0 : 1 ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_48 = 0 , V_64 , V_66 , V_24 ;
V_64 = V_40 -> V_65 >> 8 ;
V_66 = V_40 -> V_65 & 0xFF ;
F_21 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_64 ; V_24 ++ ) {
int V_31 = ( V_56 -> V_33 [ V_66 + V_24 ] & V_36 ) ? 0 : 1 ;
if ( V_42 -> V_44 . integer . V_44 [ V_24 ] != V_31 ) {
V_56 -> V_33 [ V_66 + V_24 ] &= ~ V_36 ;
V_56 -> V_33 [ V_66 + V_24 ] |=
V_42 -> V_44 . integer . V_44 [ V_24 ] ? 0 :
V_36 ;
F_15 ( V_2 , V_66 + V_24 , V_56 -> V_33 [ V_66 + V_24 ] ,
V_56 -> V_34 [ V_24 ] ) ;
V_48 = 1 ;
}
}
F_22 ( V_2 ) ;
return V_48 ;
}
static int F_34 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
V_42 -> V_44 . integer . V_44 [ 0 ] =
( V_56 -> V_34 [ 0 ] & V_36 ) ? 0 : 1 ;
V_42 -> V_44 . integer . V_44 [ 1 ] =
( V_56 -> V_34 [ 1 ] & V_36 ) ? 0 : 1 ;
return 0 ;
}
static int F_35 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
struct V_55 * V_56 = V_2 -> V_56 ;
int V_48 = 0 , V_24 ;
F_21 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_31 = ( V_56 -> V_34 [ V_24 ] & V_36 ) ? 0 : 1 ;
if ( V_42 -> V_44 . integer . V_44 [ V_24 ] != V_31 ) {
int V_58 ;
V_56 -> V_34 [ V_24 ] &= ~ V_36 ;
V_56 -> V_34 [ V_24 ] |=
V_42 -> V_44 . integer . V_44 [ V_24 ] ? 0 :
V_36 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_10 ; V_58 += 2 )
F_15 ( V_2 , V_59 + V_58 + V_24 ,
V_56 -> V_33 [ V_58 + V_24 ] ,
V_56 -> V_34 [ V_24 ] ) ;
V_48 = 1 ;
}
}
F_22 ( V_2 ) ;
return V_48 ;
}
static int F_36 ( struct V_39 * V_40 ,
struct V_49 * V_50 )
{
V_50 -> type = V_51 ;
V_50 -> V_52 = 1 ;
V_50 -> V_44 . integer . V_53 = 0 ;
V_50 -> V_44 . integer . V_54 = V_69 ;
return 0 ;
}
static int F_37 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
unsigned short V_31 ;
F_18 ( & V_2 -> V_43 ) ;
V_31 = F_12 ( V_2 , V_70 ) & 0xff ;
V_31 = V_31 > V_71 ? ( V_31 - V_71 ) : 0 ;
V_42 -> V_44 . integer . V_44 [ 0 ] = V_31 ;
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_38 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
unsigned short V_72 , V_35 ;
int V_48 = 0 ;
V_35 = V_42 -> V_44 . integer . V_44 [ 0 ] ;
if ( V_35 > V_69 )
return - V_13 ;
F_21 ( V_2 ) ;
V_35 = ( V_35 ? ( V_35 + V_71 ) : 0 ) & 0xff ;
V_72 = F_12 ( V_2 , V_70 ) & 0xff ;
if ( V_72 != V_35 ) {
F_14 ( V_2 , V_70 , V_35 ) ;
F_13 ( V_2 , V_70 , V_35 | 0x100 ) ;
V_48 = 1 ;
}
F_22 ( V_2 ) ;
return V_48 ;
}
static int F_39 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
V_42 -> V_44 . integer . V_44 [ 0 ] = ( F_12 ( V_2 , V_73 ) & 0xf ) ==
0xf ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
int V_74 , V_75 ;
V_74 = F_12 ( V_2 , V_73 ) ;
V_75 = V_74 ;
if ( V_42 -> V_44 . integer . V_44 [ 0 ] )
V_74 |= 0xf ;
else
V_74 &= ~ 0xf ;
if ( V_74 != V_75 ) {
F_14 ( V_2 , V_73 , V_74 ) ;
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_39 * V_76 ,
struct V_49 * V_50 )
{
static char * V_77 [ 2 ] = { L_1 , L_2 } ;
V_50 -> type = V_78 ;
V_50 -> V_52 = 1 ;
V_50 -> V_44 . V_79 . V_80 = 2 ;
if ( V_50 -> V_44 . V_79 . V_81 >= V_50 -> V_44 . V_79 . V_80 )
V_50 -> V_44 . V_79 . V_81 = V_50 -> V_44 . V_79 . V_80 -
1 ;
strcpy ( V_50 -> V_44 . V_79 . V_82 ,
V_77 [ V_50 -> V_44 . V_79 . V_81 ] ) ;
return 0 ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
V_42 -> V_44 . V_79 . V_81 [ 0 ] = ( F_12 ( V_2 , V_83 ) & 0x8 ) ==
0x8 ;
return 0 ;
}
static int F_43 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
int V_74 , V_75 ;
struct V_1 * V_2 = F_17 ( V_40 ) ;
V_74 = F_12 ( V_2 , V_83 ) ;
V_75 = V_74 ;
if ( V_42 -> V_44 . V_79 . V_81 [ 0 ] )
V_74 |= 0x8 ;
else
V_74 &= ~ 0x8 ;
if ( V_74 != V_75 ) {
F_14 ( V_2 , V_83 , V_74 ) ;
return 1 ;
}
return 0 ;
}
static int T_1 F_44 ( struct V_1 * V_2 )
{
unsigned int V_24 , V_84 ;
int V_5 ;
V_84 = F_45 ( V_85 ) ;
for ( V_24 = 0 ; V_24 < V_84 ; V_24 ++ ) {
V_5 = F_46 ( V_2 -> V_86 ,
F_47 ( & V_85 [ V_24 ] ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
for ( V_24 = 0 ; V_24 < F_45 ( V_87 ) ; V_24 ++ ) {
V_5 = F_46 ( V_2 -> V_86 ,
F_47 ( & V_87 [ V_24 ] , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
