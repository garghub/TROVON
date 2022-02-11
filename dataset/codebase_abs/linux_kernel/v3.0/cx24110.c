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
static const int V_27 [] = { - 1 , 1 , 2 , 3 , 5 , 7 , - 1 } ;
static const int V_28 [] = { - 1 , 0x01 , 0x02 , 0x05 , 0x15 , 0x45 , - 1 } ;
static const int V_29 [] = { - 1 , 0x01 , 0x03 , 0x06 , 0x1a , 0x7a , - 1 } ;
if ( V_26 > V_30 )
V_26 = V_30 ;
if ( V_26 == V_30 ) {
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) & 0xdf ) ;
F_1 ( V_2 , 0x18 , 0xae ) ;
F_1 ( V_2 , 0x05 , ( F_4 ( V_2 , 0x05 ) & 0xf0 ) | 0x3 ) ;
F_1 ( V_2 , 0x22 , ( F_4 ( V_2 , 0x22 ) & 0xf0 ) | 0x3 ) ;
F_1 ( V_2 , 0x1a , 0x05 ) ; F_1 ( V_2 , 0x1b , 0x06 ) ;
return 0 ;
} else {
F_1 ( V_2 , 0x37 , F_4 ( V_2 , 0x37 ) | 0x20 ) ;
if( V_27 [ V_26 ] > 0 ) {
F_1 ( V_2 , 0x05 , ( F_4 ( V_2 , 0x05 ) & 0xf0 ) | V_27 [ V_26 ] ) ;
F_1 ( V_2 , 0x22 , ( F_4 ( V_2 , 0x22 ) & 0xf0 ) | V_27 [ V_26 ] ) ;
F_1 ( V_2 , 0x1a , V_28 [ V_26 ] ) ;
F_1 ( V_2 , 0x1b , V_29 [ V_26 ] ) ;
} else
return - V_31 ;
} ;
return 0 ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_4 ( V_2 , 0x22 ) & 0x0f ;
if( ! ( V_32 & 0x08 ) ) {
return V_33 + V_32 - 1 ;
} else {
return V_34 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_4 V_35 )
{
T_4 V_36 ;
T_4 V_37 , V_38 , V_39 ;
static const T_4 V_40 [] = { 5000000UL , 15000000UL , 90999000UL / 2 } ;
int V_32 ;
F_3 ( L_3 , V_15 , V_35 ) ;
if ( V_35 > 90999000UL / 2 )
V_35 = 90999000UL / 2 ;
if ( V_35 < 500000 )
V_35 = 500000 ;
for( V_32 = 0 ; ( V_32 < F_9 ( V_40 ) ) && ( V_35 > V_40 [ V_32 ] ) ; V_32 ++ )
;
V_37 = F_4 ( V_2 , 0x07 ) & 0xfc ;
if( V_35 < 90999000UL / 4 ) {
F_1 ( V_2 , 0x07 , V_37 ) ;
F_1 ( V_2 , 0x06 , 0x78 ) ;
V_38 = 90999000UL / 2 ;
} else if( V_35 < 60666000UL / 2 ) {
F_1 ( V_2 , 0x07 , V_37 | 0x1 ) ;
F_1 ( V_2 , 0x06 , 0xa5 ) ;
V_38 = 60666000UL ;
} else if( V_35 < 80888000UL / 2 ) {
F_1 ( V_2 , 0x07 , V_37 | 0x2 ) ;
F_1 ( V_2 , 0x06 , 0x87 ) ;
V_38 = 80888000UL ;
} else {
F_1 ( V_2 , 0x07 , V_37 | 0x3 ) ;
F_1 ( V_2 , 0x06 , 0x78 ) ;
V_38 = 90999000UL ;
} ;
F_3 ( L_4 , V_38 ) ;
V_37 = V_35 << 6 ;
V_39 = V_38 >> 2 ;
V_36 = ( V_37 / V_39 ) ;
V_37 = ( V_37 % V_39 ) << 8 ;
V_36 = ( V_36 << 8 ) + ( V_37 / V_39 ) ;
V_37 = ( V_37 % V_39 ) << 8 ;
V_36 = ( V_36 << 8 ) + ( V_37 / V_39 ) ;
V_37 = ( V_37 % V_39 ) << 1 ;
V_36 = ( V_36 << 1 ) + ( V_37 / V_39 ) ;
F_3 ( L_5 , V_35 , V_32 , V_40 [ V_32 ] ) ;
F_3 ( L_6 , V_38 ) ;
F_3 ( L_7 , V_36 ) ;
F_1 ( V_2 , 0x1 , ( V_36 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x2 , ( V_36 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x3 , ( V_36 ) & 0xff ) ;
return 0 ;
}
static int F_10 ( struct V_41 * V_42 , const T_1 V_5 [] , int V_12 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
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
static int F_11 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
int V_32 ;
F_3 ( L_8 , V_15 ) ;
for( V_32 = 0 ; V_32 < F_9 ( V_44 ) ; V_32 ++ ) {
F_1 ( V_2 , V_44 [ V_32 ] . V_3 , V_44 [ V_32 ] . V_4 ) ;
} ;
return 0 ;
}
static int F_12 ( struct V_41 * V_42 , T_5 V_45 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
switch ( V_45 ) {
case V_46 :
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & 0x3b ) | 0xc0 ) ;
case V_47 :
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & 0x3b ) | 0x40 ) ;
default:
return - V_25 ;
} ;
}
static int F_13 ( struct V_41 * V_42 , T_6 V_48 )
{
int V_49 , V_50 ;
struct V_1 * V_2 = V_42 -> V_43 ;
unsigned long V_51 ;
if ( V_48 == V_52 )
V_50 = 0x00 ;
else if ( V_48 == V_53 )
V_50 = 0x08 ;
else
return - V_25 ;
V_49 = F_4 ( V_2 , 0x77 ) ;
if ( ! ( V_49 & 0x04 ) )
F_1 ( V_2 , 0x77 , V_49 | 0x04 ) ;
V_49 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x76 , ( ( V_49 & 0x90 ) | 0x40 | V_50 ) ) ;
V_51 = V_54 + F_14 ( 100 ) ;
while ( ! F_15 ( V_54 , V_51 ) && ! ( F_4 ( V_2 , 0x76 ) & 0x40 ) )
;
return 0 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_55 * V_56 )
{
int V_32 , V_49 ;
struct V_1 * V_2 = V_42 -> V_43 ;
unsigned long V_51 ;
if ( V_56 -> V_57 < 3 || V_56 -> V_57 > 6 )
return - V_25 ;
for ( V_32 = 0 ; V_32 < V_56 -> V_57 ; V_32 ++ )
F_1 ( V_2 , 0x79 + V_32 , V_56 -> V_7 [ V_32 ] ) ;
V_49 = F_4 ( V_2 , 0x77 ) ;
if ( V_49 & 0x04 ) {
F_1 ( V_2 , 0x77 , V_49 & ~ 0x04 ) ;
F_17 ( 30 ) ;
}
V_49 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x76 , ( ( V_49 & 0x90 ) | 0x40 ) | ( ( V_56 -> V_57 - 3 ) & 3 ) ) ;
V_51 = V_54 + F_14 ( 100 ) ;
while ( ! F_15 ( V_54 , V_51 ) && ! ( F_4 ( V_2 , 0x76 ) & 0x40 ) )
;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 , T_7 * V_58 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
int V_59 = F_4 ( V_2 , 0x55 ) ;
* V_58 = 0 ;
if ( V_59 & 0x10 )
* V_58 |= V_60 ;
if ( V_59 & 0x08 )
* V_58 |= V_61 ;
V_59 = F_4 ( V_2 , 0x08 ) ;
if ( V_59 & 0x40 )
* V_58 |= V_62 ;
if ( V_59 & 0x20 )
* V_58 |= V_63 ;
if ( ( V_59 & 0x60 ) == 0x60 )
* V_58 |= V_64 ;
return 0 ;
}
static int F_19 ( struct V_41 * V_42 , T_4 * V_65 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
if( F_4 ( V_2 , 0x24 ) & 0x10 ) {
F_1 ( V_2 , 0x24 , 0x04 ) ;
V_2 -> V_66 = F_4 ( V_2 , 0x25 ) |
( F_4 ( V_2 , 0x26 ) << 8 ) ;
F_1 ( V_2 , 0x24 , 0x04 ) ;
F_1 ( V_2 , 0x24 , 0x14 ) ;
}
* V_65 = V_2 -> V_66 ;
return 0 ;
}
static int F_20 ( struct V_41 * V_42 , T_8 * V_67 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
T_1 signal = F_4 ( V_2 , 0x27 ) + 128 ;
* V_67 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 , T_8 * V_68 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
if( F_4 ( V_2 , 0x6a ) & 0x80 ) {
V_2 -> V_69 = F_4 ( V_2 , 0x69 ) |
( F_4 ( V_2 , 0x68 ) << 8 ) ;
F_1 ( V_2 , 0x6a , 0x84 ) ;
}
* V_68 = V_2 -> V_69 ;
return 0 ;
}
static int F_22 ( struct V_41 * V_42 , T_4 * V_70 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
T_4 V_71 ;
if( F_4 ( V_2 , 0x10 ) & 0x40 ) {
F_1 ( V_2 , 0x10 , 0x60 ) ;
V_71 = F_4 ( V_2 , 0x12 ) |
( F_4 ( V_2 , 0x13 ) << 8 ) |
( F_4 ( V_2 , 0x14 ) << 16 ) ;
F_1 ( V_2 , 0x10 , 0x70 ) ;
V_2 -> V_72 = F_4 ( V_2 , 0x12 ) |
( F_4 ( V_2 , 0x13 ) << 8 ) |
( F_4 ( V_2 , 0x14 ) << 16 ) ;
F_1 ( V_2 , 0x10 , 0x20 ) ;
}
* V_70 = V_2 -> V_72 ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 , struct V_73 * V_74 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
if ( V_42 -> V_75 . V_76 . V_77 ) {
V_42 -> V_75 . V_76 . V_77 ( V_42 , V_74 ) ;
if ( V_42 -> V_75 . V_78 ) V_42 -> V_75 . V_78 ( V_42 , 0 ) ;
}
F_5 ( V_2 , V_74 -> V_21 ) ;
F_6 ( V_2 , V_74 -> V_79 . V_80 . V_81 ) ;
F_8 ( V_2 , V_74 -> V_79 . V_80 . V_82 ) ;
F_1 ( V_2 , 0x04 , 0x05 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 , struct V_73 * V_74 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
T_9 V_83 ; unsigned V_84 ;
V_84 = F_4 ( V_2 , 0x07 ) & 0x03 ;
if ( V_84 == 0 ) V_84 = 90999000L / 2L ;
else if ( V_84 == 1 ) V_84 = 60666000L ;
else if ( V_84 == 2 ) V_84 = 80888000L ;
else V_84 = 90999000L ;
V_84 >>= 8 ;
V_83 = V_84 * ( F_4 ( V_2 , 0x44 ) & 0x1f ) +
( ( V_84 * F_4 ( V_2 , 0x45 ) ) >> 8 ) +
( ( V_84 * F_4 ( V_2 , 0x46 ) ) >> 16 ) ;
V_74 -> V_85 += V_83 ;
V_74 -> V_21 = ( F_4 ( V_2 , 0x22 ) & 0x10 ) ?
V_23 : V_22 ;
V_74 -> V_79 . V_80 . V_81 = F_7 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_41 * V_42 , T_10 V_86 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
return F_1 ( V_2 , 0x76 , ( F_4 ( V_2 , 0x76 ) & ~ 0x10 ) | ( ( ( V_86 == V_87 ) ) ? 0x10 : 0 ) ) ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
F_27 ( V_2 ) ;
}
struct V_41 * F_28 ( const struct V_88 * V_9 ,
struct V_89 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_17 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_90 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_66 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_69 = 0 ;
V_17 = F_4 ( V_2 , 0x00 ) ;
if ( ( V_17 != 0x5a ) && ( V_17 != 0x69 ) ) goto error;
memcpy ( & V_2 -> V_91 . V_75 , & V_92 , sizeof( struct V_93 ) ) ;
V_2 -> V_91 . V_43 = V_2 ;
return & V_2 -> V_91 ;
error:
F_27 ( V_2 ) ;
return NULL ;
}
