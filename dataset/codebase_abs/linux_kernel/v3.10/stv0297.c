static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 2 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_16 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_17 , . V_13 = 1 }
} ;
if ( V_2 -> V_10 -> V_19 ) {
if ( ( V_5 = F_2 ( V_2 -> V_14 , & V_8 [ 0 ] , 1 ) ) != 1 ) {
F_3 ( L_3 , V_15 , V_3 , V_5 ) ;
return - 1 ;
}
if ( ( V_5 = F_2 ( V_2 -> V_14 , & V_8 [ 1 ] , 1 ) ) != 1 ) {
F_3 ( L_3 , V_15 , V_3 , V_5 ) ;
return - 1 ;
}
} else {
if ( ( V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ) != 2 ) {
F_3 ( L_3 , V_15 , V_3 , V_5 ) ;
return - 1 ;
}
}
return V_17 [ 0 ] ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_20 , T_1 V_4 )
{
int V_21 ;
V_21 = F_4 ( V_2 , V_3 ) ;
V_21 &= ~ V_20 ;
V_21 |= ( V_4 & V_20 ) ;
F_1 ( V_2 , V_3 , V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_22 , T_1 * V_23 , T_1 V_13 )
{
int V_5 ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 =
& V_22 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_23 , . V_13 = V_13 }
} ;
if ( V_2 -> V_10 -> V_19 ) {
if ( ( V_5 = F_2 ( V_2 -> V_14 , & V_8 [ 0 ] , 1 ) ) != 1 ) {
F_3 ( L_3 , V_15 , V_22 , V_5 ) ;
return - 1 ;
}
if ( ( V_5 = F_2 ( V_2 -> V_14 , & V_8 [ 1 ] , 1 ) ) != 1 ) {
F_3 ( L_3 , V_15 , V_22 , V_5 ) ;
return - 1 ;
}
} else {
if ( ( V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ) != 2 ) {
F_3 ( L_3 , V_15 , V_22 , V_5 ) ;
return - 1 ;
}
}
return 0 ;
}
static T_2 F_7 ( struct V_1 * V_2 )
{
T_3 V_24 ;
V_24 = F_4 ( V_2 , 0x55 ) ;
V_24 |= F_4 ( V_2 , 0x56 ) << 8 ;
V_24 |= F_4 ( V_2 , 0x57 ) << 16 ;
V_24 |= F_4 ( V_2 , 0x58 ) << 24 ;
V_24 *= V_25 ;
V_24 >>= 32 ;
return ( T_2 ) V_24 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_26 )
{
long V_24 ;
V_24 = 131072L * V_26 ;
V_24 = V_24 / ( V_25 / 4 ) ;
V_24 = V_24 * 8192L ;
F_1 ( V_2 , 0x55 , ( unsigned char ) ( V_24 & 0xFF ) ) ;
F_1 ( V_2 , 0x56 , ( unsigned char ) ( V_24 >> 8 ) ) ;
F_1 ( V_2 , 0x57 , ( unsigned char ) ( V_24 >> 16 ) ) ;
F_1 ( V_2 , 0x58 , ( unsigned char ) ( V_24 >> 24 ) ) ;
}
static void F_9 ( struct V_1 * V_2 , short V_27 , long V_28 )
{
long V_24 ;
V_24 = ( long ) V_27 * 262144L ;
V_24 /= V_28 ;
V_24 *= 1024 ;
if ( V_24 >= 0 ) {
V_24 += 500000 ;
} else {
V_24 -= 500000 ;
}
V_24 /= 1000000 ;
F_1 ( V_2 , 0x60 , V_24 & 0xFF ) ;
F_5 ( V_2 , 0x69 , 0xF0 , ( V_24 >> 4 ) & 0xf0 ) ;
}
static void F_10 ( struct V_1 * V_2 , long V_29 )
{
long V_24 ;
V_24 = V_29 * 26844L ;
if ( V_24 < 0 )
V_24 += 0x10000000 ;
V_24 &= 0x0FFFFFFF ;
F_1 ( V_2 , 0x66 , ( unsigned char ) ( V_24 & 0xFF ) ) ;
F_1 ( V_2 , 0x67 , ( unsigned char ) ( V_24 >> 8 ) ) ;
F_1 ( V_2 , 0x68 , ( unsigned char ) ( V_24 >> 16 ) ) ;
F_5 ( V_2 , 0x69 , 0x0F , ( V_24 >> 24 ) & 0x0f ) ;
}
static void F_11 ( struct V_1 * V_2 , long V_30 )
{
T_4 V_24 ;
if ( V_30 > 10000 )
V_30 -= V_25 ;
V_24 = ( V_25 * 1000 ) / ( 1 << 16 ) ;
V_24 = ( V_30 * 1000 ) / V_24 ;
if ( V_24 > 0xffff )
V_24 = 0xffff ;
F_5 ( V_2 , 0x25 , 0x80 , 0x80 ) ;
F_1 ( V_2 , 0x21 , V_24 >> 8 ) ;
F_1 ( V_2 , 0x20 , V_24 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_5 V_31 )
{
int V_21 = 0 ;
switch ( V_31 ) {
case V_32 :
V_21 = 0 ;
break;
case V_33 :
V_21 = 1 ;
break;
case V_34 :
V_21 = 4 ;
break;
case V_35 :
V_21 = 2 ;
break;
case V_36 :
V_21 = 3 ;
break;
default:
return - V_37 ;
}
F_5 ( V_2 , 0x00 , 0x70 , V_21 << 4 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_6 V_38 )
{
int V_21 = 0 ;
switch ( V_38 ) {
case V_39 :
V_21 = 0 ;
break;
case V_40 :
V_21 = 1 ;
break;
default:
return - V_37 ;
}
F_5 ( V_2 , 0x83 , 0x08 , V_21 << 3 ) ;
return 0 ;
}
static int F_14 ( struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
if ( V_43 ) {
F_1 ( V_2 , 0x87 , 0x78 ) ;
F_1 ( V_2 , 0x86 , 0xc8 ) ;
}
return 0 ;
}
static int F_15 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
int V_45 ;
for ( V_45 = 0 ; ! ( V_2 -> V_10 -> V_46 [ V_45 ] == 0xff && V_2 -> V_10 -> V_46 [ V_45 + 1 ] == 0xff ) ; V_45 += 2 )
F_1 ( V_2 , V_2 -> V_10 -> V_46 [ V_45 ] , V_2 -> V_10 -> V_46 [ V_45 + 1 ] ) ;
F_16 ( 200 ) ;
V_2 -> V_47 = 0 ;
return 0 ;
}
static int F_17 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
F_5 ( V_2 , 0x80 , 1 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 , T_7 * V_48 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
T_1 V_49 = F_4 ( V_2 , 0xDF ) ;
* V_48 = 0 ;
if ( V_49 & 0x80 )
* V_48 |=
V_50 | V_51 | V_52 | V_53 | V_54 ;
return 0 ;
}
static int F_19 ( struct V_41 * V_42 , T_2 * V_55 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
T_1 V_56 [ 3 ] ;
F_6 ( V_2 , 0xA0 , V_56 , 3 ) ;
if ( ! ( V_56 [ 0 ] & 0x80 ) ) {
V_2 -> V_47 = V_56 [ 2 ] << 8 | V_56 [ 1 ] ;
F_5 ( V_2 , 0xA0 , 0x80 , 0x80 ) ;
}
* V_55 = V_2 -> V_47 ;
return 0 ;
}
static int F_20 ( struct V_41 * V_42 , T_8 * V_57 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
T_1 V_58 [ 3 ] ;
T_8 V_24 ;
F_6 ( V_2 , 0x41 , V_58 , 3 ) ;
V_24 = ( V_58 [ 1 ] & 0x03 ) << 8 | V_58 [ 0 ] ;
if ( V_58 [ 2 ] & 0x20 ) {
if ( V_24 < 0x200 )
V_24 = 0 ;
else
V_24 = V_24 - 0x200 ;
} else {
if ( V_24 > 0x1ff )
V_24 = 0 ;
else
V_24 = 0x1ff - V_24 ;
}
* V_57 = ( V_24 << 7 ) | ( V_24 >> 2 ) ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 , T_8 * V_59 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
T_1 V_60 [ 2 ] ;
F_6 ( V_2 , 0x07 , V_60 , 2 ) ;
* V_59 = V_60 [ 1 ] << 8 | V_60 [ 0 ] ;
return 0 ;
}
static int F_22 ( struct V_41 * V_42 , T_2 * V_61 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
F_5 ( V_2 , 0xDF , 0x03 , 0x03 ) ;
* V_61 = ( F_4 ( V_2 , 0xD5 ) << 8 )
| F_4 ( V_2 , 0xD4 ) ;
F_5 ( V_2 , 0xDF , 0x03 , 0x02 ) ;
F_5 ( V_2 , 0xDF , 0x03 , 0x01 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 )
{
struct V_62 * V_63 = & V_42 -> V_64 ;
struct V_1 * V_2 = V_42 -> V_44 ;
int V_65 ;
int V_66 ;
int V_67 ;
int V_68 ;
int V_69 ;
int V_70 ;
unsigned long V_71 ;
T_6 V_38 ;
switch ( V_63 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 :
V_68 = 100 ;
V_69 = 1000 ;
break;
case V_35 :
case V_36 :
V_68 = 200 ;
V_69 = 500 ;
break;
default:
return - V_37 ;
}
V_38 = V_63 -> V_38 ;
if ( V_2 -> V_10 -> V_72 )
V_38 = ( V_38 == V_40 ) ? V_39 : V_40 ;
V_70 = - 330 ;
switch ( V_38 ) {
case V_39 :
break;
case V_40 :
V_69 = - V_69 ;
V_70 = - V_70 ;
break;
default:
return - V_37 ;
}
F_15 ( V_42 ) ;
if ( V_42 -> V_73 . V_74 . V_75 ) {
V_42 -> V_73 . V_74 . V_75 ( V_42 ) ;
if ( V_42 -> V_73 . V_76 ) V_42 -> V_73 . V_76 ( V_42 , 0 ) ;
}
F_1 ( V_2 , 0x82 , 0x0 ) ;
F_11 ( V_2 , 7250 ) ;
F_5 ( V_2 , 0x43 , 0x10 , 0x00 ) ;
F_1 ( V_2 , 0x41 , 0x00 ) ;
F_5 ( V_2 , 0x42 , 0x03 , 0x01 ) ;
F_5 ( V_2 , 0x36 , 0x60 , 0x00 ) ;
F_5 ( V_2 , 0x36 , 0x18 , 0x00 ) ;
F_5 ( V_2 , 0x71 , 0x80 , 0x80 ) ;
F_1 ( V_2 , 0x72 , 0x00 ) ;
F_1 ( V_2 , 0x73 , 0x00 ) ;
F_5 ( V_2 , 0x74 , 0x0F , 0x00 ) ;
F_5 ( V_2 , 0x43 , 0x08 , 0x00 ) ;
F_5 ( V_2 , 0x71 , 0x80 , 0x00 ) ;
F_5 ( V_2 , 0x5a , 0x20 , 0x20 ) ;
F_5 ( V_2 , 0x5b , 0x02 , 0x02 ) ;
F_5 ( V_2 , 0x5b , 0x02 , 0x00 ) ;
F_5 ( V_2 , 0x5b , 0x01 , 0x00 ) ;
F_5 ( V_2 , 0x5a , 0x40 , 0x40 ) ;
F_5 ( V_2 , 0x6a , 0x01 , 0x00 ) ;
F_5 ( V_2 , 0x81 , 0x01 , 0x01 ) ;
F_5 ( V_2 , 0x81 , 0x01 , 0x00 ) ;
F_5 ( V_2 , 0x83 , 0x20 , 0x20 ) ;
F_5 ( V_2 , 0x83 , 0x20 , 0x00 ) ;
V_65 = F_4 ( V_2 , 0x00 ) & 0xf ;
V_66 = F_4 ( V_2 , 0x01 ) >> 4 ;
V_67 = F_4 ( V_2 , 0x01 ) & 0xf ;
F_5 ( V_2 , 0x84 , 0x01 , 0x01 ) ;
F_5 ( V_2 , 0x84 , 0x01 , 0x00 ) ;
F_5 ( V_2 , 0x00 , 0x0f , V_65 ) ;
F_5 ( V_2 , 0x01 , 0xf0 , V_66 << 4 ) ;
F_5 ( V_2 , 0x01 , 0x0f , V_67 ) ;
F_5 ( V_2 , 0x87 , 0x80 , 0x00 ) ;
F_1 ( V_2 , 0x63 , 0x00 ) ;
F_1 ( V_2 , 0x64 , 0x00 ) ;
F_1 ( V_2 , 0x65 , 0x00 ) ;
F_1 ( V_2 , 0x66 , 0x00 ) ;
F_1 ( V_2 , 0x67 , 0x00 ) ;
F_1 ( V_2 , 0x68 , 0x00 ) ;
F_5 ( V_2 , 0x69 , 0x0f , 0x00 ) ;
F_12 ( V_2 , V_63 -> V_31 ) ;
F_8 ( V_2 , V_63 -> V_77 / 1000 ) ;
F_9 ( V_2 , V_69 , V_63 -> V_77 / 1000 ) ;
F_10 ( V_2 , V_70 ) ;
F_13 ( V_2 , V_38 ) ;
if ( V_63 -> V_31 == V_35 ||
V_63 -> V_31 == V_36 )
F_5 ( V_2 , 0x88 , 0x08 , 0x00 ) ;
else
F_5 ( V_2 , 0x88 , 0x08 , 0x08 ) ;
F_5 ( V_2 , 0x5a , 0x20 , 0x00 ) ;
F_5 ( V_2 , 0x6a , 0x01 , 0x01 ) ;
F_5 ( V_2 , 0x43 , 0x40 , 0x40 ) ;
F_5 ( V_2 , 0x5b , 0x30 , 0x00 ) ;
F_5 ( V_2 , 0x03 , 0x0c , 0x0c ) ;
F_5 ( V_2 , 0x03 , 0x03 , 0x03 ) ;
F_5 ( V_2 , 0x43 , 0x10 , 0x10 ) ;
V_71 = V_78 + F_24 ( 2000 ) ;
while ( F_25 ( V_78 , V_71 ) ) {
F_16 ( 10 ) ;
if ( F_4 ( V_2 , 0x43 ) & 0x08 )
break;
}
if ( F_26 ( V_78 , V_71 ) ) {
goto V_71;
}
F_16 ( 20 ) ;
V_71 = V_78 + F_24 ( 500 ) ;
while ( F_25 ( V_78 , V_71 ) ) {
F_16 ( 10 ) ;
if ( F_4 ( V_2 , 0x82 ) & 0x04 ) {
break;
}
}
if ( F_26 ( V_78 , V_71 ) ) {
goto V_71;
}
V_71 = V_78 + F_24 ( V_68 ) ;
while ( F_25 ( V_78 , V_71 ) ) {
F_16 ( 10 ) ;
if ( F_4 ( V_2 , 0x82 ) & 0x08 ) {
break;
}
}
if ( F_26 ( V_78 , V_71 ) ) {
goto V_71;
}
F_5 ( V_2 , 0x6a , 1 , 0 ) ;
F_5 ( V_2 , 0x88 , 8 , 0 ) ;
V_71 = V_78 + F_24 ( 20 ) ;
while ( F_25 ( V_78 , V_71 ) ) {
F_16 ( 10 ) ;
if ( F_4 ( V_2 , 0xDF ) & 0x80 ) {
break;
}
}
if ( F_26 ( V_78 , V_71 ) ) {
goto V_71;
}
F_16 ( 100 ) ;
if ( ! ( F_4 ( V_2 , 0xDF ) & 0x80 ) ) {
goto V_71;
}
F_5 ( V_2 , 0x5a , 0x40 , 0x00 ) ;
V_2 -> V_79 = V_63 -> V_80 ;
return 0 ;
V_71:
F_5 ( V_2 , 0x6a , 0x01 , 0x00 ) ;
return 0 ;
}
static int F_27 ( struct V_41 * V_42 )
{
struct V_62 * V_63 = & V_42 -> V_64 ;
struct V_1 * V_2 = V_42 -> V_44 ;
int V_81 , V_82 ;
V_81 = F_4 ( V_2 , 0x00 ) ;
V_82 = F_4 ( V_2 , 0x83 ) ;
V_63 -> V_80 = V_2 -> V_79 ;
V_63 -> V_38 = ( V_82 & 0x08 ) ? V_40 : V_39 ;
if ( V_2 -> V_10 -> V_72 )
V_63 -> V_38 = ( V_63 -> V_38 == V_40 ) ? V_39 : V_40 ;
V_63 -> V_77 = F_7 ( V_2 ) * 1000 ;
V_63 -> V_83 = V_84 ;
switch ( ( V_81 >> 4 ) & 0x7 ) {
case 0 :
V_63 -> V_31 = V_32 ;
break;
case 1 :
V_63 -> V_31 = V_33 ;
break;
case 2 :
V_63 -> V_31 = V_35 ;
break;
case 3 :
V_63 -> V_31 = V_36 ;
break;
case 4 :
V_63 -> V_31 = V_34 ;
break;
}
return 0 ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_44 ;
F_29 ( V_2 ) ;
}
struct V_41 * F_30 ( const struct V_85 * V_10 ,
struct V_86 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_87 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_47 = 0 ;
V_2 -> V_79 = 0 ;
if ( ( F_4 ( V_2 , 0x80 ) & 0x70 ) != 0x20 )
goto error;
memcpy ( & V_2 -> V_88 . V_73 , & V_89 , sizeof( struct V_90 ) ) ;
V_2 -> V_88 . V_44 = V_2 ;
return & V_2 -> V_88 ;
error:
F_29 ( V_2 ) ;
return NULL ;
}
