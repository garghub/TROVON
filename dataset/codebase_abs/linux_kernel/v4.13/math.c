static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
if ( F_2 ( F_2 ) > 0 )
V_4 -> V_7 |= 1 ;
else
V_4 -> V_7 &= ~ 1 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
if ( F_2 ( F_2 ) == 0 )
V_4 -> V_7 |= 1 ;
else
V_4 -> V_7 &= ~ 1 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
F_5 ( V_8 , V_9 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
F_5 ( V_8 , V_10 ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
F_5 ( V_8 , V_11 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
F_5 ( V_8 , DIV ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
V_12 ;
F_10 ( V_13 ) ;
F_10 ( V_14 ) ;
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
F_10 ( V_17 ) ;
F_11 ( V_15 , V_18 ) ;
F_11 ( V_16 , V_19 ) ;
F_11 ( V_17 , V_20 ) ;
F_12 ( V_14 , V_16 , V_15 ) ;
F_13 ( V_13 , V_17 , V_14 ) ;
F_14 ( V_20 , V_13 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_6 ) ;
F_17 ( V_20 , V_22 + V_23 + 4 ) ;
V_6 ++ ;
F_17 ( V_20 , V_22 + V_23 ) ;
} else {
F_17 ( V_20 , V_22 + V_23 ) ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_6 ) ;
F_17 ( V_20 , V_22 + 4 ) ;
V_6 ++ ;
F_17 ( V_20 , V_22 ) ;
} else {
F_17 ( V_20 , V_22 ) ;
}
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_6 ) ;
F_17 ( V_20 , V_22 + 4 ) ;
V_6 ++ ;
F_17 ( V_20 , V_22 ) ;
V_22 += 8 ;
} else {
F_17 ( V_20 , V_22 ) ;
V_22 += 4 ;
}
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_5 ) ;
F_21 ( V_19 , V_24 + V_23 + 4 ) ;
V_5 ++ ;
F_21 ( V_19 , V_24 + V_23 ) ;
} else {
F_21 ( V_19 , V_24 + V_23 ) ;
}
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_5 ) ;
F_21 ( V_19 , V_24 + 4 ) ;
V_5 ++ ;
F_21 ( V_19 , V_24 ) ;
} else {
F_21 ( V_19 , V_24 ) ;
}
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_5 ) ;
V_24 -= 8 ;
F_21 ( V_19 , V_24 + 4 ) ;
V_5 ++ ;
F_21 ( V_19 , V_24 ) ;
} else {
V_24 -= 4 ;
F_21 ( V_19 , V_24 ) ;
}
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 )
{
if ( V_21 ) {
F_16 ( V_5 ) ;
F_16 ( V_6 ) ;
V_25 = V_26 ;
} else {
V_20 = V_19 ;
}
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
return - V_27 ;
}
static int F_26 ( struct V_1 * V_2 , int V_6 )
{
V_12 ;
if ( V_28 )
F_27 ( V_29 , V_25 ) ;
else
F_27 ( V_30 , V_20 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_6 )
{
V_12 ;
if ( V_28 )
F_29 ( V_29 , V_25 ) ;
else
F_29 ( V_30 , V_20 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_6 )
{
V_12 ;
F_10 ( V_17 ) ;
F_31 ( V_13 ) ;
F_11 ( V_17 , V_31 ) ;
F_32 ( V_29 , V_30 , 2 , 1 , V_13 , V_17 ) ;
F_33 ( V_25 , V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_6 )
{
V_12 ;
F_31 ( V_17 ) ;
F_10 ( V_13 ) ;
F_35 ( V_17 , V_25 ) ;
F_32 ( V_30 , V_29 , 1 , 2 , V_13 , V_17 ) ;
F_14 ( V_31 , V_13 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_32 )
{
V_33 ^= V_32 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_6 )
{
V_20 = V_31 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_6 )
{
V_31 = V_20 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_6 )
{
V_20 ^= ( 1 << ( V_34 - 1 ) ) ;
return 0 ;
}
static int fabs ( struct V_1 * V_2 , int V_6 )
{
V_20 &= ~ ( 1 << ( V_34 - 1 ) ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_6 )
{
V_20 = 0 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_6 )
{
V_20 = ( V_35 << ( V_36 - 1 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_6 )
{
return - V_27 ;
}
static int F_43 ( struct V_1 * V_2 , int V_37 )
{
const int V_32 [] = { V_21 , V_28 , V_38 , 0 } ;
switch ( V_37 & 3 ) {
case 3 :
F_36 ( V_2 , V_32 [ V_37 >> 2 ] ) ;
break;
case 1 :
F_44 ( V_2 , V_37 - 1 ) ;
break;
default:
F_45 ( V_2 , V_37 ) ;
}
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_37 , int V_6 )
{
return ( V_39 [ V_37 ] ) ( V_2 , V_6 ) ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_40 )
{
int V_6 = ( V_40 >> 8 ) & 0xf , V_5 = ( V_40 >> 4 ) & 0xf , V_37 = V_40 & 0xf ;
return ( V_41 [ V_37 ] ) ( V_2 , V_4 , V_5 , V_6 ) ;
}
static int
F_48 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_40 )
{
int V_6 = ( ( V_40 >> 8 ) & 0xf ) ;
unsigned long * V_42 = ( V_40 & 0x0010 ) ? & V_31 : & V_33 ;
switch ( V_40 & 0xf0ff ) {
case 0x005a :
case 0x006a :
V_24 = * V_42 ;
break;
case 0x405a :
case 0x406a :
* V_42 = V_24 ;
break;
case 0x4052 :
case 0x4062 :
V_24 -= 4 ;
F_21 ( * V_42 , V_24 ) ;
break;
case 0x4056 :
case 0x4066 :
F_17 ( * V_42 , V_24 ) ;
V_24 += 4 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_49 ( T_1 V_40 , struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ( V_40 & 0xf000 ) == 0xf000 )
return F_47 ( V_2 , V_4 , V_40 ) ;
else
return F_48 ( V_2 , V_4 , V_40 ) ;
}
static void F_50 ( struct V_1 * V_43 , int V_6 )
{
unsigned long V_44 , V_45 ;
unsigned long V_37 = V_43 -> V_46 ;
int exp = 1023 - 126 ;
if ( V_37 != 0 && ( V_37 & 0x7f800000 ) == 0 ) {
V_44 = ( V_37 & 0x80000000 ) ;
while ( ( V_37 & 0x00800000 ) == 0 ) {
V_37 <<= 1 ;
exp -- ;
}
V_37 &= 0x007fffff ;
V_44 |= ( exp << 20 ) | ( V_37 >> 3 ) ;
V_45 = V_37 << 29 ;
V_43 -> V_47 [ V_6 ] = V_44 ;
V_43 -> V_47 [ V_6 + 1 ] = V_45 ;
}
}
static int F_51 ( struct V_3 * V_4 )
{
unsigned short V_48 = * ( unsigned short * ) V_4 -> V_49 ;
unsigned short V_50 ;
unsigned long V_51 ;
T_2 V_52 ;
int V_53 [ 4 ] = {
( V_48 >> 12 ) & 0xf ,
( V_48 >> 8 ) & 0xf ,
( V_48 >> 4 ) & 0xf ,
V_48 & 0xf } ;
if ( V_53 [ 0 ] == 0xb ||
( V_53 [ 0 ] == 0x4 && V_53 [ 2 ] == 0x0 && V_53 [ 3 ] == 0xb ) )
V_4 -> V_54 = V_4 -> V_49 + 4 ;
if ( V_53 [ 0 ] == 0xa || V_53 [ 0 ] == 0xb ) {
V_51 = V_4 -> V_49 + 4 + ( ( short ) ( ( V_48 & 0xfff ) << 4 ) >> 3 ) ;
V_50 = * ( unsigned short * ) ( V_4 -> V_49 + 2 ) ;
} else if ( V_53 [ 0 ] == 0x8 && V_53 [ 1 ] == 0xd ) {
if ( V_4 -> V_7 & 1 )
V_51 = V_4 -> V_49 + 4 + ( ( char ) ( V_48 & 0xff ) << 1 ) ;
else
V_51 = V_4 -> V_49 + 4 ;
V_50 = * ( unsigned short * ) ( V_4 -> V_49 + 2 ) ;
} else if ( V_53 [ 0 ] == 0x8 && V_53 [ 1 ] == 0xf ) {
if ( V_4 -> V_7 & 1 )
V_51 = V_4 -> V_49 + 4 ;
else
V_51 = V_4 -> V_49 + 4 + ( ( char ) ( V_48 & 0xff ) << 1 ) ;
V_50 = * ( unsigned short * ) ( V_4 -> V_49 + 2 ) ;
} else if ( V_53 [ 0 ] == 0x4 && V_53 [ 3 ] == 0xb &&
( V_53 [ 2 ] == 0x0 || V_53 [ 2 ] == 0x2 ) ) {
V_51 = V_4 -> V_4 [ V_53 [ 1 ] ] ;
V_50 = * ( unsigned short * ) ( V_4 -> V_49 + 2 ) ;
} else if ( V_53 [ 0 ] == 0x0 && V_53 [ 3 ] == 0x3 &&
( V_53 [ 2 ] == 0x0 || V_53 [ 2 ] == 0x2 ) ) {
V_51 = V_4 -> V_49 + 4 + V_4 -> V_4 [ V_53 [ 1 ] ] ;
V_50 = * ( unsigned short * ) ( V_4 -> V_49 + 2 ) ;
} else if ( V_48 == 0x000b ) {
V_51 = V_4 -> V_54 ;
V_50 = * ( unsigned short * ) ( V_4 -> V_49 + 2 ) ;
} else {
V_51 = V_4 -> V_49 + 2 ;
V_50 = V_48 ;
}
if ( ( V_50 & 0xf1ff ) == 0xf0ad ) {
struct V_55 * V_56 = V_57 ;
if ( ( V_56 -> V_58 . V_59 -> V_60 . V_61 & ( 1 << 17 ) ) ) {
F_50 ( & V_56 -> V_58 . V_59 -> V_60 ,
( V_50 >> 8 ) & 0xf ) ;
V_56 -> V_58 . V_59 -> V_60 . V_61 &=
~ ( V_62 | V_63 ) ;
F_52 ( V_56 ) -> V_64 |= V_65 ;
} else {
V_52 . V_66 = V_67 ;
V_52 . V_68 = 0 ;
V_52 . V_69 = V_70 ;
V_52 . V_71 = ( void V_72 * ) V_4 -> V_49 ;
F_53 ( V_67 , & V_52 , V_56 ) ;
}
V_4 -> V_49 = V_51 ;
return 1 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_43 )
{
int V_73 ;
V_43 -> V_61 = V_74 ;
V_43 -> V_46 = 0 ;
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ ) {
V_43 -> V_47 [ V_73 ] = 0 ;
V_43 -> V_75 [ V_73 ] = 0 ;
}
}
int F_55 ( unsigned short V_76 , struct V_3 * V_4 )
{
struct V_55 * V_56 = V_57 ;
struct V_1 * V_43 = & ( V_56 -> V_58 . V_59 -> V_60 ) ;
F_56 ( V_77 , 1 , V_4 , 0 ) ;
if ( ! ( F_52 ( V_56 ) -> V_64 & V_65 ) ) {
F_54 ( V_43 ) ;
F_52 ( V_56 ) -> V_64 |= V_65 ;
}
return F_49 ( V_76 , V_43 , V_4 ) ;
}
