static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
if ( ( V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ) != 1 ) {
F_3 ( L_1
L_2 , V_15 , V_13 , V_3 , V_4 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_17 ;
T_1 V_18 [] = { V_3 } ;
T_1 V_19 [] = { 0 } ;
struct V_6 V_7 [] = { { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_18 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_20 , . V_5 = V_19 , . V_12 = 1 } } ;
V_17 = F_2 ( V_2 -> V_14 , V_7 , 2 ) ;
if ( V_17 != 2 ) return V_17 ;
return V_19 [ 0 ] ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_21 V_22 )
{
switch ( V_22 ) {
case V_23 :
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x1 ) ;
F_1 ( V_2 , 0x5 , F_4 ( V_2 , 0x5 ) & 0xf7 ) ;
F_1 ( V_2 , 0x22 , F_4 ( V_2 , 0x22 ) & 0xef ) ;
break;
case V_24 :
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x1 ) ;
F_1 ( V_2 , 0x5 , F_4 ( V_2 , 0x5 ) | 0x08 ) ;
F_1 ( V_2 , 0x22 , F_4 ( V_2 , 0x22 ) | 0x10 ) ;
break;
case V_25 :
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) & 0xfe ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , enum V_27 V_28 )
{
static const int V_29 [ V_30 ] = { - 1 , 1 , 2 , 3 , 5 , 7 , - 1 } ;
static const int V_31 [ V_30 ] = { - 1 , 0x01 , 0x02 , 0x05 , 0x15 , 0x45 , - 1 } ;
static const int V_32 [ V_30 ] = { - 1 , 0x01 , 0x03 , 0x06 , 0x1a , 0x7a , - 1 } ;
if ( V_28 > V_30 )
V_28 = V_30 ;
if ( V_28 == V_30 ) {
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) & 0xdf ) ;
F_1 ( V_2 , 0x18 , 0xae ) ;
F_1 ( V_2 , 0x05 , ( F_4 ( V_2 , 0x05 ) & 0xf0 ) | 0x3 ) ;
F_1 ( V_2 , 0x22 , ( F_4 ( V_2 , 0x22 ) & 0xf0 ) | 0x3 ) ;
F_1 ( V_2 , 0x1a , 0x05 ) ;
F_1 ( V_2 , 0x1b , 0x06 ) ;
return 0 ;
} else {
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x20 ) ;
if ( V_29 [ V_28 ] < 0 )
return - V_26 ;
F_1 ( V_2 , 0x05 , ( F_4 ( V_2 , 0x05 ) & 0xf0 ) | V_29 [ V_28 ] ) ;
F_1 ( V_2 , 0x22 , ( F_4 ( V_2 , 0x22 ) & 0xf0 ) | V_29 [ V_28 ] ) ;
F_1 ( V_2 , 0x1a , V_31 [ V_28 ] ) ;
F_1 ( V_2 , 0x1b , V_32 [ V_28 ] ) ;
}
return 0 ;
}
static enum V_27 F_7 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_4 ( V_2 , 0x22 ) & 0x0f ;
if( ! ( V_33 & 0x08 ) ) {
return V_34 + V_33 - 1 ;
} else {
return V_35 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_2 V_36 )
{
T_2 V_37 ;
T_2 V_38 , V_39 , V_40 ;
static const T_2 V_41 [] = { 5000000UL , 15000000UL , 90999000UL / 2 } ;
int V_33 ;
F_3 ( L_3 , V_15 , V_36 ) ;
if ( V_36 > 90999000UL / 2 )
V_36 = 90999000UL / 2 ;
if ( V_36 < 500000 )
V_36 = 500000 ;
for( V_33 = 0 ; ( V_33 < F_9 ( V_41 ) ) && ( V_36 > V_41 [ V_33 ] ) ; V_33 ++ )
;
V_38 = F_4 ( V_2 , 0x07 ) & 0xfc ;
if( V_36 < 90999000UL / 4 ) {
F_1 ( V_2 , 0x07 , V_38 ) ;
F_1 ( V_2 , 0x06 , 0x78 ) ;
V_39 = 90999000UL / 2 ;
} else if( V_36 < 60666000UL / 2 ) {
F_1 ( V_2 , 0x07 , V_38 | 0x1 ) ;
F_1 ( V_2 , 0x06 , 0xa5 ) ;
V_39 = 60666000UL ;
} else if( V_36 < 80888000UL / 2 ) {
F_1 ( V_2 , 0x07 , V_38 | 0x2 ) ;
F_1 ( V_2 , 0x06 , 0x87 ) ;
V_39 = 80888000UL ;
} else {
F_1 ( V_2 , 0x07 , V_38 | 0x3 ) ;
F_1 ( V_2 , 0x06 , 0x78 ) ;
V_39 = 90999000UL ;
}
F_3 ( L_4 , V_39 ) ;
V_38 = V_36 << 6 ;
V_40 = V_39 >> 2 ;
V_37 = ( V_38 / V_40 ) ;
V_38 = ( V_38 % V_40 ) << 8 ;
V_37 = ( V_37 << 8 ) + ( V_38 / V_40 ) ;
V_38 = ( V_38 % V_40 ) << 8 ;
V_37 = ( V_37 << 8 ) + ( V_38 / V_40 ) ;
V_38 = ( V_38 % V_40 ) << 1 ;
V_37 = ( V_37 << 1 ) + ( V_38 / V_40 ) ;
F_3 ( L_5 , V_36 , V_33 , V_41 [ V_33 ] ) ;
F_3 ( L_6 , V_39 ) ;
F_3 ( L_7 , V_37 ) ;
F_1 ( V_2 , 0x1 , ( V_37 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x2 , ( V_37 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x3 , ( V_37 ) & 0xff ) ;
return 0 ;
}
static int F_10 ( struct V_42 * V_43 , const T_1 V_5 [] , int V_12 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
if ( V_12 != 3 )
return - V_26 ;
F_1 ( V_2 , 0x6d , 0x30 ) ;
F_1 ( V_2 , 0x70 , 0x15 ) ;
while ( F_4 ( V_2 , 0x6d ) & 0x80 )
F_1 ( V_2 , 0x72 , 0 ) ;
F_1 ( V_2 , 0x72 , V_5 [ 0 ] ) ;
while ( ( F_4 ( V_2 , 0x6d ) & 0xc0 ) == 0x80 )
;
F_1 ( V_2 , 0x72 , V_5 [ 1 ] ) ;
while ( ( F_4 ( V_2 , 0x6d ) & 0xc0 ) == 0x80 )
;
F_1 ( V_2 , 0x72 , V_5 [ 2 ] ) ;
while ( ( F_4 ( V_2 , 0x6d ) & 0xc0 ) == 0x80 )
;
F_1 ( V_2 , 0x6d , 0x32 ) ;
F_1 ( V_2 , 0x6d , 0x30 ) ;
return 0 ;
}
static int F_11 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
int V_33 ;
F_3 ( L_8 , V_15 ) ;
for( V_33 = 0 ; V_33 < F_9 ( V_45 ) ; V_33 ++ ) {
F_1 ( V_2 , V_45 [ V_33 ] . V_3 , V_45 [ V_33 ] . V_4 ) ;
}
return 0 ;
}
static int F_12 ( struct V_42 * V_43 ,
enum V_46 V_47 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
switch ( V_47 ) {
case V_48 :
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & 0x3b ) | 0xc0 ) ;
case V_49 :
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & 0x3b ) | 0x40 ) ;
default:
return - V_26 ;
}
}
static int F_13 ( struct V_42 * V_43 ,
enum V_50 V_51 )
{
int V_52 , V_53 ;
struct V_1 * V_2 = V_43 -> V_44 ;
unsigned long V_54 ;
if ( V_51 == V_55 )
V_53 = 0x00 ;
else if ( V_51 == V_56 )
V_53 = 0x08 ;
else
return - V_26 ;
V_52 = F_4 ( V_2 , 0x77 ) ;
if ( ! ( V_52 & 0x04 ) )
F_1 ( V_2 , 0x77 , V_52 | 0x04 ) ;
V_52 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x76 , ( ( V_52 & 0x90 ) | 0x40 | V_53 ) ) ;
V_54 = V_57 + F_14 ( 100 ) ;
while ( ! F_15 ( V_57 , V_54 ) && ! ( F_4 ( V_2 , 0x76 ) & 0x40 ) )
;
return 0 ;
}
static int F_16 ( struct V_42 * V_43 ,
struct V_58 * V_59 )
{
int V_33 , V_52 ;
struct V_1 * V_2 = V_43 -> V_44 ;
unsigned long V_54 ;
if ( V_59 -> V_60 < 3 || V_59 -> V_60 > 6 )
return - V_26 ;
for ( V_33 = 0 ; V_33 < V_59 -> V_60 ; V_33 ++ )
F_1 ( V_2 , 0x79 + V_33 , V_59 -> V_7 [ V_33 ] ) ;
V_52 = F_4 ( V_2 , 0x77 ) ;
if ( V_52 & 0x04 ) {
F_1 ( V_2 , 0x77 , V_52 & ~ 0x04 ) ;
F_17 ( 30 ) ;
}
V_52 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x76 , ( ( V_52 & 0x90 ) | 0x40 ) | ( ( V_59 -> V_60 - 3 ) & 3 ) ) ;
V_54 = V_57 + F_14 ( 100 ) ;
while ( ! F_15 ( V_57 , V_54 ) && ! ( F_4 ( V_2 , 0x76 ) & 0x40 ) )
;
return 0 ;
}
static int F_18 ( struct V_42 * V_43 ,
enum V_61 * V_62 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
int V_63 = F_4 ( V_2 , 0x55 ) ;
* V_62 = 0 ;
if ( V_63 & 0x10 )
* V_62 |= V_64 ;
if ( V_63 & 0x08 )
* V_62 |= V_65 ;
V_63 = F_4 ( V_2 , 0x08 ) ;
if ( V_63 & 0x40 )
* V_62 |= V_66 ;
if ( V_63 & 0x20 )
* V_62 |= V_67 ;
if ( ( V_63 & 0x60 ) == 0x60 )
* V_62 |= V_68 ;
return 0 ;
}
static int F_19 ( struct V_42 * V_43 , T_2 * V_69 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
if( F_4 ( V_2 , 0x24 ) & 0x10 ) {
F_1 ( V_2 , 0x24 , 0x04 ) ;
V_2 -> V_70 = F_4 ( V_2 , 0x25 ) |
( F_4 ( V_2 , 0x26 ) << 8 ) ;
F_1 ( V_2 , 0x24 , 0x04 ) ;
F_1 ( V_2 , 0x24 , 0x14 ) ;
}
* V_69 = V_2 -> V_70 ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 , T_3 * V_71 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
T_1 signal = F_4 ( V_2 , 0x27 ) + 128 ;
* V_71 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_21 ( struct V_42 * V_43 , T_3 * V_72 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
if( F_4 ( V_2 , 0x6a ) & 0x80 ) {
V_2 -> V_73 = F_4 ( V_2 , 0x69 ) |
( F_4 ( V_2 , 0x68 ) << 8 ) ;
F_1 ( V_2 , 0x6a , 0x84 ) ;
}
* V_72 = V_2 -> V_73 ;
return 0 ;
}
static int F_22 ( struct V_42 * V_43 , T_2 * V_74 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
if( F_4 ( V_2 , 0x10 ) & 0x40 ) {
F_1 ( V_2 , 0x10 , 0x60 ) ;
( void ) ( F_4 ( V_2 , 0x12 ) |
( F_4 ( V_2 , 0x13 ) << 8 ) |
( F_4 ( V_2 , 0x14 ) << 16 ) ) ;
F_1 ( V_2 , 0x10 , 0x70 ) ;
V_2 -> V_75 = F_4 ( V_2 , 0x12 ) |
( F_4 ( V_2 , 0x13 ) << 8 ) |
( F_4 ( V_2 , 0x14 ) << 16 ) ;
F_1 ( V_2 , 0x10 , 0x20 ) ;
}
* V_74 = V_2 -> V_75 ;
return 0 ;
}
static int F_23 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_76 * V_77 = & V_43 -> V_78 ;
if ( V_43 -> V_79 . V_80 . V_81 ) {
V_43 -> V_79 . V_80 . V_81 ( V_43 ) ;
if ( V_43 -> V_79 . V_82 ) V_43 -> V_79 . V_82 ( V_43 , 0 ) ;
}
F_5 ( V_2 , V_77 -> V_22 ) ;
F_6 ( V_2 , V_77 -> V_83 ) ;
F_8 ( V_2 , V_77 -> V_84 ) ;
F_1 ( V_2 , 0x04 , 0x05 ) ;
return 0 ;
}
static int F_24 ( struct V_42 * V_43 )
{
struct V_76 * V_77 = & V_43 -> V_78 ;
struct V_1 * V_2 = V_43 -> V_44 ;
T_4 V_85 ; unsigned V_86 ;
V_86 = F_4 ( V_2 , 0x07 ) & 0x03 ;
if ( V_86 == 0 ) V_86 = 90999000L / 2L ;
else if ( V_86 == 1 ) V_86 = 60666000L ;
else if ( V_86 == 2 ) V_86 = 80888000L ;
else V_86 = 90999000L ;
V_86 >>= 8 ;
V_85 = V_86 * ( F_4 ( V_2 , 0x44 ) & 0x1f ) +
( ( V_86 * F_4 ( V_2 , 0x45 ) ) >> 8 ) +
( ( V_86 * F_4 ( V_2 , 0x46 ) ) >> 16 ) ;
V_77 -> V_87 += V_85 ;
V_77 -> V_22 = ( F_4 ( V_2 , 0x22 ) & 0x10 ) ?
V_24 : V_23 ;
V_77 -> V_83 = F_7 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_42 * V_43 ,
enum V_88 V_89 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & ~ 0x10 ) | ( ( ( V_89 == V_90 ) ) ? 0x10 : 0 ) ) ;
}
static void F_26 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
F_27 ( V_2 ) ;
}
struct V_42 * F_28 ( const struct V_91 * V_9 ,
struct V_92 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_17 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_93 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_70 = 0 ;
V_2 -> V_75 = 0 ;
V_2 -> V_73 = 0 ;
V_17 = F_4 ( V_2 , 0x00 ) ;
if ( ( V_17 != 0x5a ) && ( V_17 != 0x69 ) ) goto error;
memcpy ( & V_2 -> V_94 . V_79 , & V_95 , sizeof( struct V_96 ) ) ;
V_2 -> V_94 . V_44 = V_2 ;
return & V_2 -> V_94 ;
error:
F_27 ( V_2 ) ;
return NULL ;
}
