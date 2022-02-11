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
static int F_5 ( struct V_1 * V_2 , T_2 V_21 )
{
switch ( V_21 ) {
case V_22 :
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x1 ) ;
F_1 ( V_2 , 0x5 , F_4 ( V_2 , 0x5 ) & 0xf7 ) ;
F_1 ( V_2 , 0x22 , F_4 ( V_2 , 0x22 ) & 0xef ) ;
break;
case V_23 :
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x1 ) ;
F_1 ( V_2 , 0x5 , F_4 ( V_2 , 0x5 ) | 0x08 ) ;
F_1 ( V_2 , 0x22 , F_4 ( V_2 , 0x22 ) | 0x10 ) ;
break;
case V_24 :
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) & 0xfe ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_3 V_26 )
{
static const int V_27 [ V_28 ] = { - 1 , 1 , 2 , 3 , 5 , 7 , - 1 } ;
static const int V_29 [ V_28 ] = { - 1 , 0x01 , 0x02 , 0x05 , 0x15 , 0x45 , - 1 } ;
static const int V_30 [ V_28 ] = { - 1 , 0x01 , 0x03 , 0x06 , 0x1a , 0x7a , - 1 } ;
if ( V_26 > V_28 )
V_26 = V_28 ;
if ( V_26 == V_28 ) {
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) & 0xdf ) ;
F_1 ( V_2 , 0x18 , 0xae ) ;
F_1 ( V_2 , 0x05 , ( F_4 ( V_2 , 0x05 ) & 0xf0 ) | 0x3 ) ;
F_1 ( V_2 , 0x22 , ( F_4 ( V_2 , 0x22 ) & 0xf0 ) | 0x3 ) ;
F_1 ( V_2 , 0x1a , 0x05 ) ;
F_1 ( V_2 , 0x1b , 0x06 ) ;
return 0 ;
} else {
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x20 ) ;
if ( V_27 [ V_26 ] < 0 )
return - V_25 ;
F_1 ( V_2 , 0x05 , ( F_4 ( V_2 , 0x05 ) & 0xf0 ) | V_27 [ V_26 ] ) ;
F_1 ( V_2 , 0x22 , ( F_4 ( V_2 , 0x22 ) & 0xf0 ) | V_27 [ V_26 ] ) ;
F_1 ( V_2 , 0x1a , V_29 [ V_26 ] ) ;
F_1 ( V_2 , 0x1b , V_30 [ V_26 ] ) ;
}
return 0 ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_4 ( V_2 , 0x22 ) & 0x0f ;
if( ! ( V_31 & 0x08 ) ) {
return V_32 + V_31 - 1 ;
} else {
return V_33 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_4 V_34 )
{
T_4 V_35 ;
T_4 V_36 , V_37 , V_38 ;
static const T_4 V_39 [] = { 5000000UL , 15000000UL , 90999000UL / 2 } ;
int V_31 ;
F_3 ( L_3 , V_15 , V_34 ) ;
if ( V_34 > 90999000UL / 2 )
V_34 = 90999000UL / 2 ;
if ( V_34 < 500000 )
V_34 = 500000 ;
for( V_31 = 0 ; ( V_31 < F_9 ( V_39 ) ) && ( V_34 > V_39 [ V_31 ] ) ; V_31 ++ )
;
V_36 = F_4 ( V_2 , 0x07 ) & 0xfc ;
if( V_34 < 90999000UL / 4 ) {
F_1 ( V_2 , 0x07 , V_36 ) ;
F_1 ( V_2 , 0x06 , 0x78 ) ;
V_37 = 90999000UL / 2 ;
} else if( V_34 < 60666000UL / 2 ) {
F_1 ( V_2 , 0x07 , V_36 | 0x1 ) ;
F_1 ( V_2 , 0x06 , 0xa5 ) ;
V_37 = 60666000UL ;
} else if( V_34 < 80888000UL / 2 ) {
F_1 ( V_2 , 0x07 , V_36 | 0x2 ) ;
F_1 ( V_2 , 0x06 , 0x87 ) ;
V_37 = 80888000UL ;
} else {
F_1 ( V_2 , 0x07 , V_36 | 0x3 ) ;
F_1 ( V_2 , 0x06 , 0x78 ) ;
V_37 = 90999000UL ;
}
F_3 ( L_4 , V_37 ) ;
V_36 = V_34 << 6 ;
V_38 = V_37 >> 2 ;
V_35 = ( V_36 / V_38 ) ;
V_36 = ( V_36 % V_38 ) << 8 ;
V_35 = ( V_35 << 8 ) + ( V_36 / V_38 ) ;
V_36 = ( V_36 % V_38 ) << 8 ;
V_35 = ( V_35 << 8 ) + ( V_36 / V_38 ) ;
V_36 = ( V_36 % V_38 ) << 1 ;
V_35 = ( V_35 << 1 ) + ( V_36 / V_38 ) ;
F_3 ( L_5 , V_34 , V_31 , V_39 [ V_31 ] ) ;
F_3 ( L_6 , V_37 ) ;
F_3 ( L_7 , V_35 ) ;
F_1 ( V_2 , 0x1 , ( V_35 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x2 , ( V_35 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x3 , ( V_35 ) & 0xff ) ;
return 0 ;
}
static int F_10 ( struct V_40 * V_41 , const T_1 V_5 [] , int V_12 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
if ( V_12 != 3 )
return - V_25 ;
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
static int F_11 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
int V_31 ;
F_3 ( L_8 , V_15 ) ;
for( V_31 = 0 ; V_31 < F_9 ( V_43 ) ; V_31 ++ ) {
F_1 ( V_2 , V_43 [ V_31 ] . V_3 , V_43 [ V_31 ] . V_4 ) ;
}
return 0 ;
}
static int F_12 ( struct V_40 * V_41 , T_5 V_44 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
switch ( V_44 ) {
case V_45 :
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & 0x3b ) | 0xc0 ) ;
case V_46 :
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & 0x3b ) | 0x40 ) ;
default:
return - V_25 ;
}
}
static int F_13 ( struct V_40 * V_41 , T_6 V_47 )
{
int V_48 , V_49 ;
struct V_1 * V_2 = V_41 -> V_42 ;
unsigned long V_50 ;
if ( V_47 == V_51 )
V_49 = 0x00 ;
else if ( V_47 == V_52 )
V_49 = 0x08 ;
else
return - V_25 ;
V_48 = F_4 ( V_2 , 0x77 ) ;
if ( ! ( V_48 & 0x04 ) )
F_1 ( V_2 , 0x77 , V_48 | 0x04 ) ;
V_48 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x76 , ( ( V_48 & 0x90 ) | 0x40 | V_49 ) ) ;
V_50 = V_53 + F_14 ( 100 ) ;
while ( ! F_15 ( V_53 , V_50 ) && ! ( F_4 ( V_2 , 0x76 ) & 0x40 ) )
;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 ,
struct V_54 * V_55 )
{
int V_31 , V_48 ;
struct V_1 * V_2 = V_41 -> V_42 ;
unsigned long V_50 ;
if ( V_55 -> V_56 < 3 || V_55 -> V_56 > 6 )
return - V_25 ;
for ( V_31 = 0 ; V_31 < V_55 -> V_56 ; V_31 ++ )
F_1 ( V_2 , 0x79 + V_31 , V_55 -> V_7 [ V_31 ] ) ;
V_48 = F_4 ( V_2 , 0x77 ) ;
if ( V_48 & 0x04 ) {
F_1 ( V_2 , 0x77 , V_48 & ~ 0x04 ) ;
F_17 ( 30 ) ;
}
V_48 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x76 , ( ( V_48 & 0x90 ) | 0x40 ) | ( ( V_55 -> V_56 - 3 ) & 3 ) ) ;
V_50 = V_53 + F_14 ( 100 ) ;
while ( ! F_15 ( V_53 , V_50 ) && ! ( F_4 ( V_2 , 0x76 ) & 0x40 ) )
;
return 0 ;
}
static int F_18 ( struct V_40 * V_41 , T_7 * V_57 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
int V_58 = F_4 ( V_2 , 0x55 ) ;
* V_57 = 0 ;
if ( V_58 & 0x10 )
* V_57 |= V_59 ;
if ( V_58 & 0x08 )
* V_57 |= V_60 ;
V_58 = F_4 ( V_2 , 0x08 ) ;
if ( V_58 & 0x40 )
* V_57 |= V_61 ;
if ( V_58 & 0x20 )
* V_57 |= V_62 ;
if ( ( V_58 & 0x60 ) == 0x60 )
* V_57 |= V_63 ;
return 0 ;
}
static int F_19 ( struct V_40 * V_41 , T_4 * V_64 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
if( F_4 ( V_2 , 0x24 ) & 0x10 ) {
F_1 ( V_2 , 0x24 , 0x04 ) ;
V_2 -> V_65 = F_4 ( V_2 , 0x25 ) |
( F_4 ( V_2 , 0x26 ) << 8 ) ;
F_1 ( V_2 , 0x24 , 0x04 ) ;
F_1 ( V_2 , 0x24 , 0x14 ) ;
}
* V_64 = V_2 -> V_65 ;
return 0 ;
}
static int F_20 ( struct V_40 * V_41 , T_8 * V_66 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 signal = F_4 ( V_2 , 0x27 ) + 128 ;
* V_66 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_21 ( struct V_40 * V_41 , T_8 * V_67 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
if( F_4 ( V_2 , 0x6a ) & 0x80 ) {
V_2 -> V_68 = F_4 ( V_2 , 0x69 ) |
( F_4 ( V_2 , 0x68 ) << 8 ) ;
F_1 ( V_2 , 0x6a , 0x84 ) ;
}
* V_67 = V_2 -> V_68 ;
return 0 ;
}
static int F_22 ( struct V_40 * V_41 , T_4 * V_69 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
if( F_4 ( V_2 , 0x10 ) & 0x40 ) {
F_1 ( V_2 , 0x10 , 0x60 ) ;
( void ) ( F_4 ( V_2 , 0x12 ) |
( F_4 ( V_2 , 0x13 ) << 8 ) |
( F_4 ( V_2 , 0x14 ) << 16 ) ) ;
F_1 ( V_2 , 0x10 , 0x70 ) ;
V_2 -> V_70 = F_4 ( V_2 , 0x12 ) |
( F_4 ( V_2 , 0x13 ) << 8 ) |
( F_4 ( V_2 , 0x14 ) << 16 ) ;
F_1 ( V_2 , 0x10 , 0x20 ) ;
}
* V_69 = V_2 -> V_70 ;
return 0 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_71 * V_72 = & V_41 -> V_73 ;
if ( V_41 -> V_74 . V_75 . V_76 ) {
V_41 -> V_74 . V_75 . V_76 ( V_41 ) ;
if ( V_41 -> V_74 . V_77 ) V_41 -> V_74 . V_77 ( V_41 , 0 ) ;
}
F_5 ( V_2 , V_72 -> V_21 ) ;
F_6 ( V_2 , V_72 -> V_78 ) ;
F_8 ( V_2 , V_72 -> V_79 ) ;
F_1 ( V_2 , 0x04 , 0x05 ) ;
return 0 ;
}
static int F_24 ( struct V_40 * V_41 )
{
struct V_71 * V_72 = & V_41 -> V_73 ;
struct V_1 * V_2 = V_41 -> V_42 ;
T_9 V_80 ; unsigned V_81 ;
V_81 = F_4 ( V_2 , 0x07 ) & 0x03 ;
if ( V_81 == 0 ) V_81 = 90999000L / 2L ;
else if ( V_81 == 1 ) V_81 = 60666000L ;
else if ( V_81 == 2 ) V_81 = 80888000L ;
else V_81 = 90999000L ;
V_81 >>= 8 ;
V_80 = V_81 * ( F_4 ( V_2 , 0x44 ) & 0x1f ) +
( ( V_81 * F_4 ( V_2 , 0x45 ) ) >> 8 ) +
( ( V_81 * F_4 ( V_2 , 0x46 ) ) >> 16 ) ;
V_72 -> V_82 += V_80 ;
V_72 -> V_21 = ( F_4 ( V_2 , 0x22 ) & 0x10 ) ?
V_23 : V_22 ;
V_72 -> V_78 = F_7 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_41 , T_10 V_83 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & ~ 0x10 ) | ( ( ( V_83 == V_84 ) ) ? 0x10 : 0 ) ) ;
}
static void F_26 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
F_27 ( V_2 ) ;
}
struct V_40 * F_28 ( const struct V_85 * V_9 ,
struct V_86 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_17 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_87 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_65 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_68 = 0 ;
V_17 = F_4 ( V_2 , 0x00 ) ;
if ( ( V_17 != 0x5a ) && ( V_17 != 0x69 ) ) goto error;
memcpy ( & V_2 -> V_88 . V_74 , & V_89 , sizeof( struct V_90 ) ) ;
V_2 -> V_88 . V_42 = V_2 ;
return & V_2 -> V_88 ;
error:
F_27 ( V_2 ) ;
return NULL ;
}
