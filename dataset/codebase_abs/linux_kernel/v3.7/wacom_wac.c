static int F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
switch ( V_3 [ 0 ] ) {
case 1 :
if ( V_3 [ 5 ] & 0x80 ) {
V_2 -> V_6 [ 0 ] = ( V_3 [ 5 ] & 0x20 ) ? V_7 : V_8 ;
V_2 -> V_9 [ 0 ] = ( V_3 [ 5 ] & 0x20 ) ? V_10 : V_11 ;
F_2 ( V_5 , V_2 -> V_6 [ 0 ] , 1 ) ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 0 ] ) ;
F_3 ( V_5 , V_13 , F_4 ( & V_3 [ 1 ] ) ) ;
F_3 ( V_5 , V_14 , F_4 ( & V_3 [ 3 ] ) ) ;
F_3 ( V_5 , V_15 , ( signed char ) V_3 [ 6 ] + 127 ) ;
F_2 ( V_5 , V_16 , ( ( signed char ) V_3 [ 6 ] > - 127 ) ) ;
F_2 ( V_5 , V_17 , ( V_3 [ 5 ] & 0x40 ) ) ;
} else {
F_2 ( V_5 , V_2 -> V_6 [ 0 ] , 0 ) ;
F_3 ( V_5 , V_12 , 0 ) ;
F_3 ( V_5 , V_15 , - 1 ) ;
F_2 ( V_5 , V_16 , 0 ) ;
}
break;
case 2 :
F_2 ( V_5 , V_8 , 1 ) ;
F_3 ( V_5 , V_12 , V_11 ) ;
F_3 ( V_5 , V_13 , F_4 ( & V_3 [ 1 ] ) ) ;
F_3 ( V_5 , V_14 , F_4 ( & V_3 [ 3 ] ) ) ;
F_3 ( V_5 , V_15 , ( signed char ) V_3 [ 6 ] + 127 ) ;
F_2 ( V_5 , V_16 , ( ( signed char ) V_3 [ 6 ] > - 80 ) && ! ( V_3 [ 5 ] & 0x20 ) ) ;
F_2 ( V_5 , V_17 , ( V_3 [ 5 ] & 0x40 ) ) ;
break;
default:
F_5 ( V_5 -> V_18 . V_19 ,
L_1 , V_20 , V_3 [ 0 ] ) ;
return 0 ;
}
return 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_23 , V_24 ;
if ( V_3 [ 0 ] != V_25 ) {
F_5 ( V_5 -> V_18 . V_19 ,
L_1 , V_20 , V_3 [ 0 ] ) ;
return 0 ;
}
V_23 = V_3 [ 1 ] & 0x40 ;
if ( V_23 ) {
V_2 -> V_9 [ 0 ] = V_10 ;
V_24 = ( signed char ) ( ( V_3 [ 7 ] << 1 ) | ( ( V_3 [ 4 ] >> 2 ) & 1 ) ) ;
if ( V_22 -> V_26 > 255 )
V_24 = ( V_24 << 1 ) | ( ( V_3 [ 4 ] >> 6 ) & 1 ) ;
V_24 += ( V_22 -> V_26 + 1 ) / 2 ;
if ( ! V_2 -> V_6 [ 0 ] ) {
if ( V_3 [ 1 ] & 0x10 )
V_2 -> V_6 [ 1 ] = V_7 ;
else
V_2 -> V_6 [ 1 ] = ( V_3 [ 4 ] & 0x20 ) ? V_7 : V_8 ;
} else {
if ( V_2 -> V_6 [ 1 ] == V_7 && ! ( V_3 [ 4 ] & 0x20 ) ) {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 0 ) ;
F_7 ( V_5 ) ;
V_2 -> V_6 [ 1 ] = V_8 ;
return 0 ;
}
}
if ( V_2 -> V_6 [ 1 ] != V_7 ) {
V_2 -> V_6 [ 1 ] = V_8 ;
V_2 -> V_9 [ 0 ] = V_11 ;
}
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , V_23 ) ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 0 ] ) ;
F_3 ( V_5 , V_13 , V_3 [ 3 ] | ( V_3 [ 2 ] << 7 ) | ( ( V_3 [ 1 ] & 0x03 ) << 14 ) ) ;
F_3 ( V_5 , V_14 , V_3 [ 6 ] | ( V_3 [ 5 ] << 7 ) | ( ( V_3 [ 4 ] & 0x03 ) << 14 ) ) ;
F_3 ( V_5 , V_15 , V_24 ) ;
F_2 ( V_5 , V_16 , V_3 [ 4 ] & 0x08 ) ;
F_2 ( V_5 , V_17 , V_3 [ 4 ] & 0x10 ) ;
F_2 ( V_5 , V_27 , ( V_2 -> V_6 [ 1 ] == V_8 ) && ( V_3 [ 4 ] & 0x20 ) ) ;
} else {
if ( V_2 -> V_6 [ 1 ] != V_7 ) {
V_2 -> V_6 [ 1 ] = V_8 ;
}
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , V_23 ) ;
}
V_2 -> V_6 [ 0 ] = V_23 ;
return 1 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 [ 0 ] != V_25 ) {
F_5 ( V_5 -> V_18 . V_19 ,
L_1 , V_20 , V_3 [ 0 ] ) ;
return 0 ;
}
if ( V_3 [ 1 ] & 0x04 ) {
F_2 ( V_5 , V_7 , V_3 [ 1 ] & 0x20 ) ;
F_2 ( V_5 , V_16 , V_3 [ 1 ] & 0x08 ) ;
V_2 -> V_9 [ 0 ] = V_10 ;
} else {
F_2 ( V_5 , V_8 , V_3 [ 1 ] & 0x20 ) ;
F_2 ( V_5 , V_16 , V_3 [ 1 ] & 0x01 ) ;
V_2 -> V_9 [ 0 ] = V_11 ;
}
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 0 ] ) ;
F_3 ( V_5 , V_13 , F_9 ( ( V_28 * ) & V_3 [ 2 ] ) ) ;
F_3 ( V_5 , V_14 , F_9 ( ( V_28 * ) & V_3 [ 4 ] ) ) ;
F_3 ( V_5 , V_15 , F_9 ( ( V_28 * ) & V_3 [ 6 ] ) ) ;
F_2 ( V_5 , V_17 , V_3 [ 1 ] & 0x02 ) ;
F_2 ( V_5 , V_27 , V_3 [ 1 ] & 0x10 ) ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_23 = V_3 [ 1 ] & 0x20 , V_24 ;
F_5 ( V_5 -> V_18 . V_19 ,
L_2 , V_20 , V_3 [ 0 ] ) ;
if ( V_23 ) {
V_2 -> V_6 [ 0 ] = ( V_3 [ 1 ] & 0x0c ) ? V_7 : V_8 ;
if ( V_2 -> V_6 [ 0 ] == V_8 )
V_2 -> V_9 [ 0 ] = V_11 ;
else
V_2 -> V_9 [ 0 ] = V_10 ;
}
F_2 ( V_5 , V_17 , V_3 [ 1 ] & 0x02 ) ;
F_2 ( V_5 , V_27 , V_3 [ 1 ] & 0x10 ) ;
F_3 ( V_5 , V_13 , F_9 ( ( V_28 * ) & V_3 [ 2 ] ) ) ;
F_3 ( V_5 , V_14 , F_9 ( ( V_28 * ) & V_3 [ 4 ] ) ) ;
V_24 = ( ( V_3 [ 7 ] & 0x01 ) << 8 ) | V_3 [ 6 ] ;
if ( V_24 < 0 )
V_24 = V_22 -> V_26 + V_24 + 1 ;
F_3 ( V_5 , V_15 , V_24 ) ;
F_2 ( V_5 , V_16 , V_3 [ 1 ] & 0x05 ) ;
if ( ! V_23 )
V_2 -> V_9 [ 0 ] = 0 ;
F_2 ( V_5 , V_2 -> V_6 [ 0 ] , V_23 ) ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 0 ] ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_23 ;
int V_29 = 0 ;
int V_30 = 0 ;
if ( V_3 [ 0 ] != V_25 ) {
F_5 ( V_5 -> V_18 . V_19 ,
L_1 , V_20 , V_3 [ 0 ] ) ;
goto exit;
}
V_23 = V_3 [ 1 ] & 0x80 ;
if ( V_23 || V_2 -> V_9 [ 0 ] ) {
if ( V_23 ) {
switch ( ( V_3 [ 1 ] >> 5 ) & 3 ) {
case 0 :
V_2 -> V_6 [ 0 ] = V_8 ;
V_2 -> V_9 [ 0 ] = V_11 ;
break;
case 1 :
V_2 -> V_6 [ 0 ] = V_7 ;
V_2 -> V_9 [ 0 ] = V_10 ;
break;
case 2 :
F_2 ( V_5 , V_31 , V_3 [ 1 ] & 0x04 ) ;
case 3 :
V_2 -> V_6 [ 0 ] = V_32 ;
V_2 -> V_9 [ 0 ] = V_33 ;
break;
}
}
F_3 ( V_5 , V_13 , F_9 ( ( V_28 * ) & V_3 [ 2 ] ) ) ;
F_3 ( V_5 , V_14 , F_9 ( ( V_28 * ) & V_3 [ 4 ] ) ) ;
if ( V_2 -> V_6 [ 0 ] != V_32 ) {
F_3 ( V_5 , V_15 , V_3 [ 6 ] | ( ( V_3 [ 7 ] & 0x03 ) << 8 ) ) ;
F_2 ( V_5 , V_16 , V_3 [ 1 ] & 0x01 ) ;
F_2 ( V_5 , V_17 , V_3 [ 1 ] & 0x02 ) ;
F_2 ( V_5 , V_27 , V_3 [ 1 ] & 0x04 ) ;
} else {
F_2 ( V_5 , V_34 , V_3 [ 1 ] & 0x01 ) ;
F_2 ( V_5 , V_35 , V_3 [ 1 ] & 0x02 ) ;
if ( V_22 -> type == V_36 ||
V_22 -> type == V_37 ) {
F_3 ( V_5 , V_38 , V_3 [ 6 ] & 0x3f ) ;
V_29 = ( V_3 [ 7 ] & 0x04 ) - ( V_3 [ 7 ] & 0x03 ) ;
} else {
F_3 ( V_5 , V_38 , V_3 [ 7 ] & 0x3f ) ;
V_29 = - ( signed char ) V_3 [ 6 ] ;
}
F_12 ( V_5 , V_39 , V_29 ) ;
}
if ( ! V_23 )
V_2 -> V_9 [ 0 ] = 0 ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 0 ] ) ;
F_2 ( V_5 , V_2 -> V_6 [ 0 ] , V_23 ) ;
F_13 ( V_5 , V_40 , V_41 , 1 ) ;
F_7 ( V_5 ) ;
}
switch ( V_22 -> type ) {
case V_36 :
V_23 = V_3 [ 7 ] & 0xf8 ;
if ( V_23 || V_2 -> V_9 [ 1 ] ) {
V_2 -> V_9 [ 1 ] = V_42 ;
F_2 ( V_5 , V_43 , ( V_3 [ 7 ] & 0x40 ) ) ;
F_2 ( V_5 , V_44 , ( V_3 [ 7 ] & 0x80 ) ) ;
V_29 = ( ( V_3 [ 7 ] & 0x18 ) >> 3 ) - ( ( V_3 [ 7 ] & 0x20 ) >> 3 ) ;
F_12 ( V_5 , V_39 , V_29 ) ;
if ( ! V_23 )
V_2 -> V_9 [ 1 ] = 0 ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 1 ] ) ;
F_13 ( V_5 , V_40 , V_41 , 0xf0 ) ;
V_30 = 1 ;
}
break;
case V_37 :
V_23 = ( V_3 [ 7 ] & 0xf8 ) || V_3 [ 8 ] ;
if ( V_23 || V_2 -> V_9 [ 1 ] ) {
V_2 -> V_9 [ 1 ] = V_42 ;
F_2 ( V_5 , V_43 , ( V_3 [ 7 ] & 0x08 ) ) ;
F_2 ( V_5 , V_34 , ( V_3 [ 7 ] & 0x20 ) ) ;
F_2 ( V_5 , V_44 , ( V_3 [ 7 ] & 0x10 ) ) ;
F_2 ( V_5 , V_35 , ( V_3 [ 7 ] & 0x40 ) ) ;
F_3 ( V_5 , V_45 , ( V_3 [ 8 ] & 0x7f ) ) ;
if ( ! V_23 )
V_2 -> V_9 [ 1 ] = 0 ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 1 ] ) ;
F_13 ( V_5 , V_40 , V_41 , 0xf0 ) ;
V_30 = 1 ;
}
break;
}
exit:
return V_30 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_46 = 0 ;
if ( V_22 -> type == V_47 )
V_46 = V_3 [ 1 ] & 0x01 ;
if ( ( V_3 [ 1 ] & 0xfc ) == 0xc0 ) {
if ( V_22 -> V_48 == V_49 )
V_2 -> V_50 -> V_51 = true ;
V_2 -> V_52 [ V_46 ] = ( ( V_3 [ 3 ] & 0x0f ) << 28 ) +
( V_3 [ 4 ] << 20 ) + ( V_3 [ 5 ] << 12 ) +
( V_3 [ 6 ] << 4 ) + ( V_3 [ 7 ] >> 4 ) ;
V_2 -> V_9 [ V_46 ] = ( V_3 [ 2 ] << 4 ) | ( V_3 [ 3 ] >> 4 ) |
( ( V_3 [ 7 ] & 0x0f ) << 20 ) | ( ( V_3 [ 8 ] & 0xf0 ) << 12 ) ;
switch ( V_2 -> V_9 [ V_46 ] & 0xfffff ) {
case 0x812 :
case 0x801 :
case 0x20802 :
case 0x012 :
V_2 -> V_6 [ V_46 ] = V_53 ;
break;
case 0x822 :
case 0x842 :
case 0x852 :
case 0x823 :
case 0x813 :
case 0x885 :
case 0x802 :
case 0x804 :
case 0x40802 :
case 0x022 :
V_2 -> V_6 [ V_46 ] = V_8 ;
break;
case 0x832 :
case 0x032 :
V_2 -> V_6 [ V_46 ] = V_54 ;
break;
case 0x007 :
case 0x09c :
case 0x094 :
case 0x017 :
case 0x806 :
V_2 -> V_6 [ V_46 ] = V_32 ;
break;
case 0x096 :
case 0x097 :
case 0x006 :
V_2 -> V_6 [ V_46 ] = V_55 ;
break;
case 0x82a :
case 0x85a :
case 0x91a :
case 0xd1a :
case 0x0fa :
case 0x82b :
case 0x81b :
case 0x91b :
case 0x80c :
case 0x80a :
case 0x4080a :
case 0x90a :
V_2 -> V_6 [ V_46 ] = V_7 ;
break;
case 0xd12 :
case 0x912 :
case 0x112 :
case 0x913 :
case 0x902 :
V_2 -> V_6 [ V_46 ] = V_56 ;
break;
default:
V_2 -> V_6 [ V_46 ] = V_8 ;
break;
}
return 1 ;
}
if ( ! ( ( V_2 -> V_9 [ V_46 ] >> 20 ) & 0x01 ) &&
( V_22 -> type == V_57 ) )
return 1 ;
if ( ( V_3 [ 1 ] & 0xfe ) == 0x80 ) {
if ( V_22 -> V_48 == V_49 )
V_2 -> V_50 -> V_51 = false ;
F_3 ( V_5 , V_13 , 0 ) ;
F_3 ( V_5 , V_14 , 0 ) ;
F_3 ( V_5 , V_38 , 0 ) ;
F_3 ( V_5 , V_58 , 0 ) ;
F_3 ( V_5 , V_59 , 0 ) ;
if ( V_2 -> V_6 [ V_46 ] >= V_32 ) {
F_2 ( V_5 , V_34 , 0 ) ;
F_2 ( V_5 , V_31 , 0 ) ;
F_2 ( V_5 , V_35 , 0 ) ;
F_2 ( V_5 , V_60 , 0 ) ;
F_2 ( V_5 , V_61 , 0 ) ;
F_3 ( V_5 , V_62 , 0 ) ;
F_3 ( V_5 , V_63 , 0 ) ;
} else {
F_3 ( V_5 , V_15 , 0 ) ;
F_2 ( V_5 , V_17 , 0 ) ;
F_2 ( V_5 , V_27 , 0 ) ;
F_2 ( V_5 , V_16 , 0 ) ;
F_3 ( V_5 , V_45 , 0 ) ;
if ( V_22 -> type >= V_64 )
F_3 ( V_5 , V_65 , 0 ) ;
}
F_2 ( V_5 , V_2 -> V_6 [ V_46 ] , 0 ) ;
F_3 ( V_5 , V_12 , 0 ) ;
F_13 ( V_5 , V_40 , V_41 , V_2 -> V_52 [ V_46 ] ) ;
V_2 -> V_9 [ V_46 ] = 0 ;
return 2 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_66 ;
if ( ( V_3 [ 1 ] & 0xb8 ) == 0xa0 ) {
V_66 = ( V_3 [ 6 ] << 2 ) | ( ( V_3 [ 7 ] >> 6 ) & 3 ) ;
if ( ( V_22 -> type >= V_67 && V_22 -> type <= V_68 ) ||
( V_22 -> type >= V_69 && V_22 -> type <= V_70 ) ||
( V_22 -> type >= V_57 && V_22 -> type <= V_71 ) ) {
V_66 = ( V_66 << 1 ) | ( V_3 [ 1 ] & 1 ) ;
}
F_3 ( V_5 , V_15 , V_66 ) ;
F_3 ( V_5 , V_58 ,
( ( V_3 [ 7 ] << 1 ) & 0x7e ) | ( V_3 [ 8 ] >> 7 ) ) ;
F_3 ( V_5 , V_59 , V_3 [ 8 ] & 0x7f ) ;
F_2 ( V_5 , V_17 , V_3 [ 1 ] & 2 ) ;
F_2 ( V_5 , V_27 , V_3 [ 1 ] & 4 ) ;
F_2 ( V_5 , V_16 , V_66 > 10 ) ;
}
if ( ( V_3 [ 1 ] & 0xbc ) == 0xb4 ) {
F_3 ( V_5 , V_45 ,
( V_3 [ 6 ] << 2 ) | ( ( V_3 [ 7 ] >> 6 ) & 3 ) ) ;
F_3 ( V_5 , V_58 ,
( ( V_3 [ 7 ] << 1 ) & 0x7e ) | ( V_3 [ 8 ] >> 7 ) ) ;
F_3 ( V_5 , V_59 , V_3 [ 8 ] & 0x7f ) ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
unsigned char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_66 ;
int V_46 = 0 , V_72 ;
if ( V_3 [ 0 ] != V_25 &&
V_3 [ 0 ] != V_73 &&
V_3 [ 0 ] != V_74 &&
V_3 [ 0 ] != V_75 &&
V_3 [ 0 ] != V_76 ) {
F_5 ( V_5 -> V_18 . V_19 ,
L_1 , V_20 , V_3 [ 0 ] ) ;
return 0 ;
}
if ( V_22 -> type == V_47 )
V_46 = V_3 [ 1 ] & 0x01 ;
if ( V_3 [ 0 ] == V_75 || V_3 [ 0 ] == V_76 ) {
if ( V_22 -> type >= V_67 && V_22 -> type <= V_68 ) {
F_2 ( V_5 , V_77 , ( V_3 [ 2 ] & 0x01 ) ) ;
F_2 ( V_5 , V_78 , ( V_3 [ 3 ] & 0x01 ) ) ;
F_2 ( V_5 , V_79 , ( V_3 [ 3 ] & 0x02 ) ) ;
F_2 ( V_5 , V_80 , ( V_3 [ 3 ] & 0x04 ) ) ;
F_2 ( V_5 , V_81 , ( V_3 [ 3 ] & 0x08 ) ) ;
F_2 ( V_5 , V_82 , ( V_3 [ 3 ] & 0x10 ) ) ;
F_2 ( V_5 , V_83 , ( V_3 [ 3 ] & 0x20 ) ) ;
if ( V_3 [ 1 ] & 0x80 ) {
F_3 ( V_5 , V_45 , ( V_3 [ 1 ] & 0x7f ) ) ;
} else {
F_3 ( V_5 , V_45 , 0 ) ;
}
if ( V_22 -> type != V_67 ) {
F_2 ( V_5 , V_84 , ( V_3 [ 3 ] & 0x40 ) ) ;
F_2 ( V_5 , V_85 , ( V_3 [ 3 ] & 0x80 ) ) ;
}
if ( V_3 [ 1 ] | ( V_3 [ 2 ] & 0x01 ) | V_3 [ 3 ] ) {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 1 ) ;
F_3 ( V_5 , V_12 , V_42 ) ;
} else {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 0 ) ;
F_3 ( V_5 , V_12 , 0 ) ;
}
} else if ( V_22 -> type == V_71 ) {
F_2 ( V_5 , V_77 , ( V_3 [ 6 ] & 0x01 ) ) ;
F_2 ( V_5 , V_78 , ( V_3 [ 6 ] & 0x02 ) ) ;
F_2 ( V_5 , V_79 , ( V_3 [ 6 ] & 0x04 ) ) ;
F_2 ( V_5 , V_80 , ( V_3 [ 6 ] & 0x08 ) ) ;
F_2 ( V_5 , V_81 , ( V_3 [ 6 ] & 0x10 ) ) ;
F_2 ( V_5 , V_82 , ( V_3 [ 6 ] & 0x20 ) ) ;
F_2 ( V_5 , V_83 , ( V_3 [ 6 ] & 0x40 ) ) ;
F_2 ( V_5 , V_84 , ( V_3 [ 6 ] & 0x80 ) ) ;
F_2 ( V_5 , V_85 , ( V_3 [ 8 ] & 0x01 ) ) ;
F_2 ( V_5 , V_86 , ( V_3 [ 8 ] & 0x02 ) ) ;
F_2 ( V_5 , V_87 , ( V_3 [ 8 ] & 0x04 ) ) ;
F_2 ( V_5 , V_88 , ( V_3 [ 8 ] & 0x08 ) ) ;
F_2 ( V_5 , V_89 , ( V_3 [ 8 ] & 0x10 ) ) ;
F_2 ( V_5 , V_90 , ( V_3 [ 8 ] & 0x20 ) ) ;
F_2 ( V_5 , V_91 , ( V_3 [ 8 ] & 0x40 ) ) ;
F_2 ( V_5 , V_92 , ( V_3 [ 8 ] & 0x80 ) ) ;
F_2 ( V_5 , V_93 , V_3 [ 4 ] & 0x07 ) ;
F_2 ( V_5 , V_94 , V_3 [ 4 ] & 0xE0 ) ;
F_2 ( V_5 , V_95 , V_3 [ 3 ] & 0x1C ) ;
if ( V_3 [ 1 ] & 0x80 ) {
F_3 ( V_5 , V_45 , ( V_3 [ 1 ] & 0x7f ) ) ;
} else {
F_3 ( V_5 , V_45 , 0 ) ;
}
if ( V_3 [ 2 ] & 0x80 ) {
F_3 ( V_5 , V_62 , ( V_3 [ 2 ] & 0x7f ) ) ;
} else {
F_3 ( V_5 , V_62 , 0 ) ;
}
if ( V_3 [ 1 ] | V_3 [ 2 ] | ( V_3 [ 3 ] & 0x1f ) | V_3 [ 4 ] | V_3 [ 6 ] | V_3 [ 8 ] ) {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 1 ) ;
F_3 ( V_5 , V_12 , V_42 ) ;
} else {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 0 ) ;
F_3 ( V_5 , V_12 , 0 ) ;
}
} else if ( V_22 -> type >= V_69 && V_22 -> type <= V_70 ) {
int V_96 ;
F_2 ( V_5 , V_77 , ( V_3 [ 3 ] & 0x01 ) ) ;
for ( V_96 = 0 ; V_96 < 8 ; V_96 ++ )
F_2 ( V_5 , V_78 + V_96 , V_3 [ 4 ] & ( 1 << V_96 ) ) ;
if ( V_3 [ 2 ] & 0x80 ) {
F_3 ( V_5 , V_45 , ( V_3 [ 2 ] & 0x7f ) ) ;
} else {
F_3 ( V_5 , V_45 , 0 ) ;
}
if ( V_3 [ 2 ] | ( V_3 [ 3 ] & 0x01 ) | V_3 [ 4 ] | V_3 [ 5 ] ) {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 1 ) ;
F_3 ( V_5 , V_12 , V_42 ) ;
} else {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 0 ) ;
F_3 ( V_5 , V_12 , 0 ) ;
}
} else {
if ( V_22 -> type == V_57 || V_22 -> type == V_97 ) {
F_2 ( V_5 , V_77 , ( V_3 [ 5 ] & 0x01 ) ) ;
F_2 ( V_5 , V_78 , ( V_3 [ 6 ] & 0x01 ) ) ;
F_2 ( V_5 , V_79 , ( V_3 [ 6 ] & 0x02 ) ) ;
F_2 ( V_5 , V_80 , ( V_3 [ 6 ] & 0x04 ) ) ;
F_2 ( V_5 , V_81 , ( V_3 [ 6 ] & 0x08 ) ) ;
F_2 ( V_5 , V_82 , ( V_3 [ 6 ] & 0x10 ) ) ;
F_2 ( V_5 , V_83 , ( V_3 [ 6 ] & 0x20 ) ) ;
F_2 ( V_5 , V_84 , ( V_3 [ 6 ] & 0x40 ) ) ;
F_2 ( V_5 , V_85 , ( V_3 [ 6 ] & 0x80 ) ) ;
F_2 ( V_5 , V_86 , ( V_3 [ 7 ] & 0x01 ) ) ;
F_2 ( V_5 , V_87 , ( V_3 [ 8 ] & 0x01 ) ) ;
F_2 ( V_5 , V_88 , ( V_3 [ 8 ] & 0x02 ) ) ;
F_2 ( V_5 , V_89 , ( V_3 [ 8 ] & 0x04 ) ) ;
F_2 ( V_5 , V_90 , ( V_3 [ 8 ] & 0x08 ) ) ;
F_2 ( V_5 , V_91 , ( V_3 [ 8 ] & 0x10 ) ) ;
F_2 ( V_5 , V_92 , ( V_3 [ 8 ] & 0x20 ) ) ;
F_2 ( V_5 , V_98 , ( V_3 [ 8 ] & 0x40 ) ) ;
F_2 ( V_5 , V_99 , ( V_3 [ 8 ] & 0x80 ) ) ;
if ( V_22 -> type == V_97 ) {
F_2 ( V_5 , V_93 , V_3 [ 9 ] & 0x01 ) ;
F_2 ( V_5 , V_94 , V_3 [ 9 ] & 0x02 ) ;
F_2 ( V_5 , V_95 , V_3 [ 9 ] & 0x04 ) ;
}
} else {
F_2 ( V_5 , V_77 , ( V_3 [ 5 ] & 0x01 ) ) ;
F_2 ( V_5 , V_78 , ( V_3 [ 5 ] & 0x02 ) ) ;
F_2 ( V_5 , V_79 , ( V_3 [ 5 ] & 0x04 ) ) ;
F_2 ( V_5 , V_80 , ( V_3 [ 5 ] & 0x08 ) ) ;
F_2 ( V_5 , V_81 , ( V_3 [ 6 ] & 0x01 ) ) ;
F_2 ( V_5 , V_82 , ( V_3 [ 6 ] & 0x02 ) ) ;
F_2 ( V_5 , V_83 , ( V_3 [ 6 ] & 0x04 ) ) ;
F_2 ( V_5 , V_84 , ( V_3 [ 6 ] & 0x08 ) ) ;
F_2 ( V_5 , V_85 , ( V_3 [ 5 ] & 0x10 ) ) ;
F_2 ( V_5 , V_86 , ( V_3 [ 6 ] & 0x10 ) ) ;
}
F_3 ( V_5 , V_100 , ( ( V_3 [ 1 ] & 0x1f ) << 8 ) | V_3 [ 2 ] ) ;
F_3 ( V_5 , V_101 , ( ( V_3 [ 3 ] & 0x1f ) << 8 ) | V_3 [ 4 ] ) ;
if ( ( V_3 [ 5 ] & 0x1f ) | V_3 [ 6 ] | ( V_3 [ 1 ] & 0x1f ) |
V_3 [ 2 ] | ( V_3 [ 3 ] & 0x1f ) | V_3 [ 4 ] | V_3 [ 8 ] |
( V_3 [ 7 ] & 0x01 ) ) {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 1 ) ;
F_3 ( V_5 , V_12 , V_42 ) ;
} else {
F_2 ( V_5 , V_2 -> V_6 [ 1 ] , 0 ) ;
F_3 ( V_5 , V_12 , 0 ) ;
}
}
F_13 ( V_5 , V_40 , V_41 , 0xffffffff ) ;
return 1 ;
}
V_72 = F_14 ( V_2 ) ;
if ( V_72 )
return V_72 - 1 ;
if ( ! V_2 -> V_9 [ V_46 ] )
return 0 ;
if ( V_2 -> V_6 [ V_46 ] == V_55 &&
( V_22 -> type == V_102 ||
V_22 -> type == V_64 ||
V_22 -> type == V_103 ||
V_22 -> type == V_67 ||
V_22 -> type == V_104 ||
V_22 -> type == V_69 ) ) {
return 0 ;
}
if ( V_22 -> type == V_105 && ! ( V_3 [ 1 ] & 0x40 ) )
return 0 ;
if ( V_22 -> type >= V_64 ) {
F_3 ( V_5 , V_13 , ( V_3 [ 2 ] << 9 ) | ( V_3 [ 3 ] << 1 ) | ( ( V_3 [ 9 ] >> 1 ) & 1 ) ) ;
F_3 ( V_5 , V_14 , ( V_3 [ 4 ] << 9 ) | ( V_3 [ 5 ] << 1 ) | ( V_3 [ 9 ] & 1 ) ) ;
F_3 ( V_5 , V_38 , ( ( V_3 [ 9 ] >> 2 ) & 0x3f ) ) ;
} else {
F_3 ( V_5 , V_13 , F_17 ( ( V_106 * ) & V_3 [ 2 ] ) ) ;
F_3 ( V_5 , V_14 , F_17 ( ( V_106 * ) & V_3 [ 4 ] ) ) ;
F_3 ( V_5 , V_38 , ( ( V_3 [ 9 ] >> 3 ) & 0x1f ) ) ;
}
F_15 ( V_2 ) ;
if ( ( V_3 [ 1 ] & 0xbc ) == 0xa8 || ( V_3 [ 1 ] & 0xbe ) == 0xb0 || ( V_3 [ 1 ] & 0xbc ) == 0xac ) {
if ( V_3 [ 1 ] & 0x02 ) {
if ( V_22 -> type >= V_64 ) {
V_66 = ( V_3 [ 6 ] << 3 ) | ( ( V_3 [ 7 ] >> 5 ) & 7 ) ;
V_66 = ( V_3 [ 7 ] & 0x20 ) ? ( ( V_66 > 900 ) ? ( ( V_66 - 1 ) / 2 - 1350 ) :
( ( V_66 - 1 ) / 2 + 450 ) ) : ( 450 - V_66 / 2 ) ;
F_3 ( V_5 , V_65 , V_66 ) ;
} else {
V_66 = ( V_3 [ 6 ] << 3 ) | ( ( V_3 [ 7 ] >> 5 ) & 7 ) ;
F_3 ( V_5 , V_63 , ( V_3 [ 7 ] & 0x20 ) ?
( ( V_66 - 1 ) / 2 ) : - V_66 / 2 ) ;
}
} else if ( ! ( V_3 [ 1 ] & 0x10 ) && V_22 -> type < V_64 ) {
F_2 ( V_5 , V_34 , V_3 [ 8 ] & 0x01 ) ;
F_2 ( V_5 , V_31 , V_3 [ 8 ] & 0x02 ) ;
F_2 ( V_5 , V_35 , V_3 [ 8 ] & 0x04 ) ;
F_2 ( V_5 , V_60 , V_3 [ 8 ] & 0x20 ) ;
F_2 ( V_5 , V_61 , V_3 [ 8 ] & 0x10 ) ;
V_66 = ( V_3 [ 6 ] << 2 ) | ( ( V_3 [ 7 ] >> 6 ) & 3 ) ;
F_3 ( V_5 , V_62 , ( V_3 [ 8 ] & 0x08 ) ? - V_66 : V_66 ) ;
} else if ( V_2 -> V_6 [ V_46 ] == V_32 ) {
if ( ( V_22 -> type >= V_67 && V_22 -> type <= V_68 ) ||
( V_22 -> type >= V_69 && V_22 -> type <= V_70 ) ) {
F_2 ( V_5 , V_34 , V_3 [ 6 ] & 0x01 ) ;
F_2 ( V_5 , V_31 , V_3 [ 6 ] & 0x02 ) ;
F_2 ( V_5 , V_35 , V_3 [ 6 ] & 0x04 ) ;
F_12 ( V_5 , V_39 , ( ( V_3 [ 7 ] & 0x80 ) >> 7 )
- ( ( V_3 [ 7 ] & 0x40 ) >> 6 ) ) ;
F_2 ( V_5 , V_60 , V_3 [ 6 ] & 0x08 ) ;
F_2 ( V_5 , V_61 , V_3 [ 6 ] & 0x10 ) ;
F_3 ( V_5 , V_58 ,
( ( V_3 [ 7 ] << 1 ) & 0x7e ) | ( V_3 [ 8 ] >> 7 ) ) ;
F_3 ( V_5 , V_59 , V_3 [ 8 ] & 0x7f ) ;
} else {
F_2 ( V_5 , V_34 , V_3 [ 8 ] & 0x04 ) ;
F_2 ( V_5 , V_31 , V_3 [ 8 ] & 0x08 ) ;
F_2 ( V_5 , V_35 , V_3 [ 8 ] & 0x10 ) ;
F_12 ( V_5 , V_39 , ( V_3 [ 8 ] & 0x01 )
- ( ( V_3 [ 8 ] & 0x02 ) >> 1 ) ) ;
if ( V_22 -> type >= V_64 && V_22 -> type <= V_107 ) {
F_2 ( V_5 , V_60 , V_3 [ 8 ] & 0x40 ) ;
F_2 ( V_5 , V_61 , V_3 [ 8 ] & 0x20 ) ;
}
}
} else if ( ( V_22 -> type < V_64 || V_22 -> type == V_107 ||
V_22 -> type == V_68 || V_22 -> type == V_70 ) &&
V_2 -> V_6 [ V_46 ] == V_55 ) {
F_2 ( V_5 , V_34 , V_3 [ 8 ] & 0x01 ) ;
F_2 ( V_5 , V_31 , V_3 [ 8 ] & 0x02 ) ;
F_2 ( V_5 , V_35 , V_3 [ 8 ] & 0x04 ) ;
F_2 ( V_5 , V_60 , V_3 [ 8 ] & 0x10 ) ;
F_2 ( V_5 , V_61 , V_3 [ 8 ] & 0x08 ) ;
}
}
F_3 ( V_5 , V_12 , V_2 -> V_9 [ V_46 ] ) ;
F_2 ( V_5 , V_2 -> V_6 [ V_46 ] , 1 ) ;
F_13 ( V_5 , V_40 , V_41 , V_2 -> V_52 [ V_46 ] ) ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 , int V_108 )
{
int V_109 = V_2 -> V_22 . V_109 ;
int V_96 ;
if ( ! V_2 -> V_110 )
return - 1 ;
for ( V_96 = 0 ; V_96 < V_109 ; ++ V_96 ) {
if ( V_2 -> V_110 [ V_96 ] == V_108 )
return V_96 ;
}
for ( V_96 = 0 ; V_96 < V_109 ; ++ V_96 ) {
if ( V_2 -> V_110 [ V_96 ] == - 1 )
return V_96 ;
}
return - 1 ;
}
static int F_19 ( int V_111 , int y1 , int V_112 , int V_113 )
{
int V_114 = V_112 - V_111 ;
int V_115 = V_113 - y1 ;
return F_20 ( V_114 * V_114 + V_115 * V_115 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char * V_3 = V_2 -> V_3 ;
int V_96 ;
int V_116 = V_3 [ 61 ] ;
int V_117 = 0 ;
if ( V_116 )
V_2 -> V_118 = V_116 ;
V_117 = F_22 ( 4 , V_2 -> V_118 ) ;
for ( V_96 = 0 ; V_96 < V_117 ; V_96 ++ ) {
int V_119 = ( V_120 * V_96 ) + 1 ;
bool V_121 = V_3 [ V_119 ] & 0x1 && ! V_2 -> V_50 -> V_51 ;
int V_9 = V_3 [ V_119 + 1 ] ;
int V_122 = F_18 ( V_2 , V_9 ) ;
if ( V_122 < 0 )
continue;
F_23 ( V_5 , V_122 ) ;
F_24 ( V_5 , V_123 , V_121 ) ;
if ( V_121 ) {
int V_124 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 2 ] ) ;
int V_125 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 4 ] ) ;
int V_126 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 6 ] ) ;
int V_127 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 8 ] ) ;
int V_128 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 10 ] ) ;
int V_129 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 12 ] ) ;
F_3 ( V_5 , V_130 , V_124 ) ;
F_3 ( V_5 , V_131 , V_126 ) ;
F_3 ( V_5 , V_132 , F_22 ( V_128 , V_129 ) ) ;
F_3 ( V_5 , V_133 , F_22 ( V_128 , V_129 ) + F_19 ( V_124 , V_126 , V_125 , V_127 ) ) ;
F_3 ( V_5 , V_134 , F_22 ( V_128 , V_129 ) ) ;
F_3 ( V_5 , V_135 , V_128 > V_129 ) ;
}
V_2 -> V_110 [ V_122 ] = V_121 ? V_9 : - 1 ;
}
F_25 ( V_5 , true ) ;
V_2 -> V_118 -= V_117 ;
if ( V_2 -> V_118 <= 0 )
V_2 -> V_118 = 0 ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
char * V_3 = V_2 -> V_3 ;
int V_96 ;
int V_116 = V_3 [ 2 ] ;
int V_117 = 0 ;
if ( V_116 )
V_2 -> V_118 = V_116 ;
V_117 = F_22 ( 5 , V_2 -> V_118 ) ;
for ( V_96 = 0 ; V_96 < V_117 ; V_96 ++ ) {
int V_119 = ( V_136 * V_96 ) + 3 ;
bool V_121 = V_3 [ V_119 ] & 0x1 ;
int V_9 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 1 ] ) ;
int V_122 = F_18 ( V_2 , V_9 ) ;
if ( V_122 < 0 )
continue;
F_23 ( V_5 , V_122 ) ;
F_24 ( V_5 , V_123 , V_121 ) ;
if ( V_121 ) {
int V_114 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 7 ] ) ;
int V_115 = F_9 ( ( V_28 * ) & V_3 [ V_119 + 9 ] ) ;
F_3 ( V_5 , V_130 , V_114 ) ;
F_3 ( V_5 , V_131 , V_115 ) ;
}
V_2 -> V_110 [ V_122 ] = V_121 ? V_9 : - 1 ;
}
F_25 ( V_5 , true ) ;
V_2 -> V_118 -= V_117 ;
if ( V_2 -> V_118 < 0 )
V_2 -> V_118 = 0 ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned char * V_3 = V_2 -> V_3 ;
int V_137 = 0 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < 2 ; V_96 ++ ) {
int V_138 = V_3 [ 1 ] & ( 1 << V_96 ) ;
bool V_121 = V_138 && ! V_2 -> V_50 -> V_51 ;
F_23 ( V_5 , V_96 ) ;
F_24 ( V_5 , V_123 , V_121 ) ;
if ( V_121 ) {
int V_114 = F_9 ( ( V_28 * ) & V_3 [ V_96 * 2 + 2 ] ) & 0x7fff ;
int V_115 = F_9 ( ( V_28 * ) & V_3 [ V_96 * 2 + 6 ] ) & 0x7fff ;
F_3 ( V_5 , V_130 , V_114 ) ;
F_3 ( V_5 , V_131 , V_115 ) ;
V_137 ++ ;
}
}
V_2 -> V_50 -> V_139 = ( V_137 > 0 ) ;
F_25 ( V_5 , true ) ;
return 1 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_140 )
{
char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
bool V_23 ;
int V_114 = 0 , V_115 = 0 ;
if ( V_2 -> V_22 . V_109 > 1 || V_140 > V_141 )
return 0 ;
if ( ! V_2 -> V_50 -> V_51 ) {
if ( V_140 == V_142 ) {
V_23 = V_3 [ 0 ] & 0x01 ;
V_114 = F_4 ( & V_3 [ 1 ] ) ;
V_115 = F_4 ( & V_3 [ 3 ] ) ;
} else {
V_23 = V_3 [ 1 ] & 0x01 ;
V_114 = F_9 ( ( V_28 * ) & V_3 [ 2 ] ) ;
V_115 = F_9 ( ( V_28 * ) & V_3 [ 4 ] ) ;
}
} else
V_23 = 0 ;
if ( V_23 ) {
F_3 ( V_5 , V_13 , V_114 ) ;
F_3 ( V_5 , V_14 , V_115 ) ;
}
F_2 ( V_5 , V_16 , V_23 ) ;
V_2 -> V_50 -> V_139 = V_23 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
char * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_24 ;
bool V_23 = V_3 [ 1 ] & 0x20 ;
if ( ! V_2 -> V_50 -> V_51 )
V_2 -> V_6 [ 0 ] = ( V_3 [ 1 ] & 0x0c ) ? V_7 : V_8 ;
V_2 -> V_50 -> V_51 = V_23 ;
if ( ! V_2 -> V_50 -> V_139 ) {
F_2 ( V_5 , V_17 , V_3 [ 1 ] & 0x02 ) ;
F_2 ( V_5 , V_27 , V_3 [ 1 ] & 0x10 ) ;
F_3 ( V_5 , V_13 , F_9 ( ( V_28 * ) & V_3 [ 2 ] ) ) ;
F_3 ( V_5 , V_14 , F_9 ( ( V_28 * ) & V_3 [ 4 ] ) ) ;
V_24 = ( ( V_3 [ 7 ] & 0x01 ) << 8 ) | V_3 [ 6 ] ;
if ( V_24 < 0 )
V_24 = V_22 -> V_26 + V_24 + 1 ;
F_3 ( V_5 , V_15 , V_24 ) ;
F_2 ( V_5 , V_16 , V_3 [ 1 ] & 0x05 ) ;
F_2 ( V_5 , V_2 -> V_6 [ 0 ] , V_23 ) ;
return 1 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_140 )
{
char * V_3 = V_2 -> V_3 ;
F_5 ( V_2 -> V_5 -> V_18 . V_19 ,
L_3 , V_20 , V_3 [ 0 ] ) ;
switch ( V_140 ) {
case V_142 :
return F_28 ( V_2 , V_140 ) ;
case V_141 :
return F_27 ( V_2 ) ;
default:
switch ( V_3 [ 0 ] ) {
case V_143 :
case V_144 :
case V_145 :
case V_146 :
return F_28 ( V_2 , V_140 ) ;
case V_147 :
return F_26 ( V_2 ) ;
case V_25 :
return F_29 ( V_2 ) ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_22 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned char * V_3 = V_2 -> V_3 ;
int V_96 ;
if ( V_3 [ 0 ] != 0x02 )
return 0 ;
for ( V_96 = 0 ; V_96 < 2 ; V_96 ++ ) {
int V_119 = ( V_3 [ 1 ] & 0x80 ) ? ( 8 * V_96 ) : ( 9 * V_96 ) ;
bool V_121 = V_3 [ V_119 + 3 ] & 0x80 ;
V_121 = V_121 && ! V_2 -> V_50 -> V_51 ;
F_23 ( V_5 , V_96 ) ;
F_24 ( V_5 , V_123 , V_121 ) ;
if ( V_121 ) {
int V_114 = F_32 ( & V_3 [ V_119 + 3 ] ) & 0x7ff ;
int V_115 = F_32 ( & V_3 [ V_119 + 5 ] ) & 0x7ff ;
if ( V_22 -> V_48 & V_148 ) {
V_114 <<= 5 ;
V_115 <<= 5 ;
}
F_3 ( V_5 , V_130 , V_114 ) ;
F_3 ( V_5 , V_131 , V_115 ) ;
}
}
F_25 ( V_5 , true ) ;
F_2 ( V_5 , V_34 , ( V_3 [ 1 ] & 0x08 ) != 0 ) ;
F_2 ( V_5 , V_44 , ( V_3 [ 1 ] & 0x04 ) != 0 ) ;
F_2 ( V_5 , V_43 , ( V_3 [ 1 ] & 0x02 ) != 0 ) ;
F_2 ( V_5 , V_35 , ( V_3 [ 1 ] & 0x01 ) != 0 ) ;
F_7 ( V_5 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_149 = V_3 [ 0 ] - 2 ;
bool V_121 = V_3 [ 1 ] & 0x80 ;
V_121 = V_121 && ! V_2 -> V_50 -> V_51 ;
F_23 ( V_5 , V_149 ) ;
F_24 ( V_5 , V_123 , V_121 ) ;
if ( V_121 ) {
int V_114 = ( V_3 [ 2 ] << 4 ) | ( V_3 [ 4 ] >> 4 ) ;
int V_115 = ( V_3 [ 3 ] << 4 ) | ( V_3 [ 4 ] & 0x0f ) ;
int V_150 = V_3 [ 5 ] ;
int V_151 = F_34 ( V_5 , V_13 ) ;
int V_152 = F_34 ( V_5 , V_14 ) ;
int V_153 = 2 * F_20 ( V_150 * V_154 ) ;
int V_155 = V_153 * V_152 / V_151 ;
F_3 ( V_5 , V_130 , V_114 ) ;
F_3 ( V_5 , V_131 , V_115 ) ;
F_3 ( V_5 , V_132 , V_153 ) ;
F_3 ( V_5 , V_156 , V_155 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_5 , V_34 , ( V_3 [ 1 ] & 0x08 ) != 0 ) ;
F_2 ( V_5 , V_44 , ( V_3 [ 1 ] & 0x04 ) != 0 ) ;
F_2 ( V_5 , V_43 , ( V_3 [ 1 ] & 0x02 ) != 0 ) ;
F_2 ( V_5 , V_35 , ( V_3 [ 1 ] & 0x01 ) != 0 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned char * V_3 = V_2 -> V_3 ;
int V_157 = V_3 [ 1 ] & 0x07 ;
int V_96 ;
if ( V_3 [ 0 ] != 0x02 )
return 0 ;
for ( V_96 = 0 ; V_96 < V_157 ; V_96 ++ ) {
int V_119 = ( 8 * V_96 ) + 2 ;
int V_158 = V_3 [ V_119 ] ;
if ( V_158 >= 2 && V_158 <= 17 )
F_33 ( V_2 , V_3 + V_119 ) ;
else if ( V_158 == 128 )
F_35 ( V_2 , V_3 + V_119 ) ;
}
F_25 ( V_5 , true ) ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned char * V_3 = V_2 -> V_3 ;
int V_23 = 0 , V_114 = 0 , V_115 = 0 , V_138 = 0 , V_159 = 0 , V_160 = 0 , V_161 = 0 , V_162 = 0 ;
if ( V_3 [ 0 ] != 0x02 )
return 0 ;
V_23 = ( V_3 [ 1 ] & 0x20 ) == 0x20 ;
if ( V_23 ) {
if ( ! V_2 -> V_50 -> V_51 ) {
if ( V_3 [ 1 ] & 0x08 ) {
V_2 -> V_6 [ 0 ] = V_7 ;
V_2 -> V_9 [ 0 ] = V_10 ;
} else {
V_2 -> V_6 [ 0 ] = V_8 ;
V_2 -> V_9 [ 0 ] = V_11 ;
}
V_2 -> V_50 -> V_51 = true ;
}
V_114 = F_9 ( ( V_28 * ) & V_3 [ 2 ] ) ;
V_115 = F_9 ( ( V_28 * ) & V_3 [ 4 ] ) ;
V_138 = F_9 ( ( V_28 * ) & V_3 [ 6 ] ) ;
if ( V_3 [ 8 ] <= V_2 -> V_22 . V_163 )
V_159 = V_2 -> V_22 . V_163 - V_3 [ 8 ] ;
V_160 = V_3 [ 1 ] & 0x01 ;
V_161 = V_3 [ 1 ] & 0x02 ;
V_162 = V_3 [ 1 ] & 0x04 ;
}
F_2 ( V_5 , V_16 , V_160 ) ;
F_2 ( V_5 , V_17 , V_161 ) ;
F_2 ( V_5 , V_27 , V_162 ) ;
F_3 ( V_5 , V_13 , V_114 ) ;
F_3 ( V_5 , V_14 , V_115 ) ;
F_3 ( V_5 , V_15 , V_138 ) ;
F_3 ( V_5 , V_38 , V_159 ) ;
if ( ! V_23 ) {
V_2 -> V_9 [ 0 ] = 0 ;
V_2 -> V_50 -> V_51 = false ;
}
F_2 ( V_5 , V_2 -> V_6 [ 0 ] , V_23 ) ;
F_3 ( V_5 , V_12 , V_2 -> V_9 [ 0 ] ) ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_140 )
{
if ( V_140 == V_164 )
return F_31 ( V_2 ) ;
else if ( V_140 == V_165 )
return F_36 ( V_2 ) ;
else if ( V_140 == V_166 || V_140 == V_167 )
return F_37 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_140 )
{
unsigned char * V_3 = V_2 -> V_3 ;
int V_168 ;
if ( V_140 != V_169 || V_3 [ 0 ] != 0x80 )
return 0 ;
V_168 = V_3 [ 1 ] & 0x01 ;
if ( V_168 ) {
int V_170 , V_171 ;
V_170 = F_32 ( & V_3 [ 6 ] ) ;
V_171 = V_3 [ 5 ] & 0x3f ;
if ( V_2 -> V_170 != V_170 ) {
V_2 -> V_170 = V_170 ;
F_40 ( V_2 ) ;
}
V_2 -> V_172 = V_171 ;
} else if ( V_2 -> V_170 != 0 ) {
V_2 -> V_170 = 0 ;
F_40 ( V_2 ) ;
V_2 -> V_172 = 0 ;
}
return 0 ;
}
void F_41 ( struct V_1 * V_1 , T_1 V_140 )
{
bool V_173 ;
switch ( V_1 -> V_22 . type ) {
case V_174 :
V_173 = F_1 ( V_1 ) ;
break;
case V_175 :
V_173 = F_6 ( V_1 ) ;
break;
case V_36 :
case V_176 :
case V_37 :
V_173 = F_11 ( V_1 ) ;
break;
case V_177 :
V_173 = F_8 ( V_1 ) ;
break;
case V_178 :
V_173 = F_10 ( V_1 ) ;
break;
case V_47 :
case V_64 :
case V_102 :
case V_107 :
case V_67 :
case V_103 :
case V_68 :
case V_105 :
case V_179 :
case V_57 :
case V_97 :
case V_71 :
V_173 = F_16 ( V_1 ) ;
break;
case V_180 :
V_173 = F_21 ( V_1 ) ;
break;
case V_69 :
case V_104 :
case V_70 :
if ( V_140 == V_165 )
V_173 = F_36 ( V_1 ) ;
else
V_173 = F_16 ( V_1 ) ;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
V_173 = F_30 ( V_1 , V_140 ) ;
break;
case V_185 :
V_173 = F_38 ( V_1 , V_140 ) ;
break;
case V_186 :
V_173 = F_39 ( V_1 , V_140 ) ;
break;
default:
V_173 = false ;
break;
}
if ( V_173 )
F_7 ( V_1 -> V_5 ) ;
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
F_43 ( V_4 , V_40 , V_41 ) ;
F_44 ( V_7 , V_4 -> V_187 ) ;
F_44 ( V_8 , V_4 -> V_187 ) ;
F_44 ( V_54 , V_4 -> V_187 ) ;
F_44 ( V_53 , V_4 -> V_187 ) ;
F_44 ( V_56 , V_4 -> V_187 ) ;
F_44 ( V_17 , V_4 -> V_187 ) ;
F_44 ( V_27 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_38 ,
0 , V_1 -> V_22 . V_163 , 0 , 0 ) ;
F_45 ( V_4 , V_45 , 0 , 1023 , 0 , 0 ) ;
F_45 ( V_4 , V_58 , 0 , 127 , 0 , 0 ) ;
F_45 ( V_4 , V_59 , 0 , 127 , 0 , 0 ) ;
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
F_43 ( V_4 , V_188 , V_39 ) ;
F_42 ( V_1 ) ;
F_44 ( V_34 , V_4 -> V_187 ) ;
F_44 ( V_35 , V_4 -> V_187 ) ;
F_44 ( V_31 , V_4 -> V_187 ) ;
F_44 ( V_60 , V_4 -> V_187 ) ;
F_44 ( V_61 , V_4 -> V_187 ) ;
F_44 ( V_32 , V_4 -> V_187 ) ;
F_44 ( V_55 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_63 , - 900 , 899 , 0 , 0 ) ;
F_45 ( V_4 , V_62 , - 1023 , 1023 , 0 , 0 ) ;
}
void F_47 ( struct V_21 * V_22 )
{
if ( V_22 -> V_189 == V_190 && ! V_22 -> V_191 ) {
V_22 -> V_191 = 1023 ;
V_22 -> V_192 = 1023 ;
}
if ( V_22 -> type >= V_186 ||
( V_22 -> type >= V_69 && V_22 -> type <= V_70 ) ||
( V_22 -> V_193 && V_22 -> V_194 ) )
V_22 -> V_48 |= V_49 ;
if ( V_22 -> type == V_185 &&
V_22 -> V_195 == V_164 ) {
V_22 -> V_191 <<= 5 ;
V_22 -> V_192 <<= 5 ;
V_22 -> V_196 <<= 5 ;
V_22 -> V_197 <<= 5 ;
V_22 -> V_48 |= V_148 ;
}
if ( V_22 -> type == V_186 ) {
V_22 -> V_48 |= V_198 ;
if ( ! V_22 -> V_189 )
V_22 -> V_48 |= V_199 ;
}
}
static unsigned int F_48 ( unsigned int V_200 ,
unsigned int V_201 )
{
return ( V_200 * 100 ) / V_201 ;
}
int F_49 ( struct V_4 * V_4 ,
struct V_1 * V_1 )
{
struct V_21 * V_22 = & V_1 -> V_22 ;
int V_96 ;
V_4 -> V_202 [ 0 ] |= F_50 ( V_203 ) | F_50 ( V_204 ) ;
F_44 ( V_16 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_13 , 0 , V_22 -> V_191 ,
V_22 -> V_196 , 0 ) ;
F_45 ( V_4 , V_14 , 0 , V_22 -> V_192 ,
V_22 -> V_197 , 0 ) ;
if ( V_22 -> V_189 == V_8 ) {
F_45 ( V_4 , V_15 , 0 , V_22 -> V_26 ,
V_22 -> V_205 , 0 ) ;
F_51 ( V_4 , V_13 , V_22 -> V_206 ) ;
F_51 ( V_4 , V_14 , V_22 -> V_207 ) ;
} else {
F_51 ( V_4 , V_13 ,
F_48 ( V_22 -> V_191 ,
V_22 -> V_208 ) ) ;
F_51 ( V_4 , V_14 ,
F_48 ( V_22 -> V_192 ,
V_22 -> V_209 ) ) ;
}
F_44 ( V_12 , V_4 -> V_210 ) ;
switch ( V_1 -> V_22 . type ) {
case V_37 :
F_45 ( V_4 , V_45 , 0 , 71 , 0 , 0 ) ;
case V_36 :
F_43 ( V_4 , V_40 , V_41 ) ;
F_44 ( V_43 , V_4 -> V_187 ) ;
F_44 ( V_44 , V_4 -> V_187 ) ;
case V_176 :
F_43 ( V_4 , V_188 , V_39 ) ;
F_44 ( V_34 , V_4 -> V_187 ) ;
F_44 ( V_35 , V_4 -> V_187 ) ;
F_44 ( V_31 , V_4 -> V_187 ) ;
F_44 ( V_7 , V_4 -> V_187 ) ;
F_44 ( V_8 , V_4 -> V_187 ) ;
F_44 ( V_32 , V_4 -> V_187 ) ;
F_44 ( V_17 , V_4 -> V_187 ) ;
F_44 ( V_27 , V_4 -> V_187 ) ;
F_44 ( V_211 , V_4 -> V_212 ) ;
break;
case V_71 :
F_44 ( V_87 , V_4 -> V_187 ) ;
F_44 ( V_88 , V_4 -> V_187 ) ;
F_44 ( V_89 , V_4 -> V_187 ) ;
F_44 ( V_90 , V_4 -> V_187 ) ;
F_44 ( V_91 , V_4 -> V_187 ) ;
F_44 ( V_92 , V_4 -> V_187 ) ;
for ( V_96 = 0 ; V_96 < 10 ; V_96 ++ )
F_44 ( V_77 + V_96 , V_4 -> V_187 ) ;
F_44 ( V_93 , V_4 -> V_187 ) ;
F_44 ( V_94 , V_4 -> V_187 ) ;
F_44 ( V_95 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_65 , - 900 , 899 , 0 , 0 ) ;
F_45 ( V_4 , V_62 , 0 , 71 , 0 , 0 ) ;
F_44 ( V_213 , V_4 -> V_212 ) ;
F_42 ( V_1 ) ;
break;
case V_97 :
F_44 ( V_93 , V_4 -> V_187 ) ;
F_44 ( V_94 , V_4 -> V_187 ) ;
F_44 ( V_95 , V_4 -> V_187 ) ;
case V_57 :
F_44 ( V_87 , V_4 -> V_187 ) ;
F_44 ( V_88 , V_4 -> V_187 ) ;
F_44 ( V_89 , V_4 -> V_187 ) ;
F_44 ( V_90 , V_4 -> V_187 ) ;
F_44 ( V_91 , V_4 -> V_187 ) ;
F_44 ( V_92 , V_4 -> V_187 ) ;
F_44 ( V_98 , V_4 -> V_187 ) ;
F_44 ( V_99 , V_4 -> V_187 ) ;
case V_179 :
F_44 ( V_85 , V_4 -> V_187 ) ;
F_44 ( V_86 , V_4 -> V_187 ) ;
case V_105 :
for ( V_96 = 0 ; V_96 < 8 ; V_96 ++ )
F_44 ( V_77 + V_96 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_100 , 0 , 4096 , 0 , 0 ) ;
F_45 ( V_4 , V_101 , 0 , 4096 , 0 , 0 ) ;
F_45 ( V_4 , V_65 , - 900 , 899 , 0 , 0 ) ;
F_44 ( V_213 , V_4 -> V_212 ) ;
F_42 ( V_1 ) ;
break;
case V_102 :
case V_107 :
F_44 ( V_81 , V_4 -> V_187 ) ;
F_44 ( V_82 , V_4 -> V_187 ) ;
F_44 ( V_83 , V_4 -> V_187 ) ;
F_44 ( V_84 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_101 , 0 , 4096 , 0 , 0 ) ;
case V_64 :
F_44 ( V_77 , V_4 -> V_187 ) ;
F_44 ( V_78 , V_4 -> V_187 ) ;
F_44 ( V_79 , V_4 -> V_187 ) ;
F_44 ( V_80 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_100 , 0 , 4096 , 0 , 0 ) ;
F_45 ( V_4 , V_65 , - 900 , 899 , 0 , 0 ) ;
case V_47 :
F_44 ( V_211 , V_4 -> V_212 ) ;
F_46 ( V_1 ) ;
break;
case V_104 :
case V_70 :
if ( V_22 -> V_189 == V_8 ) {
F_44 ( V_84 , V_4 -> V_187 ) ;
F_44 ( V_85 , V_4 -> V_187 ) ;
}
case V_69 :
F_44 ( V_211 , V_4 -> V_212 ) ;
if ( V_22 -> V_189 == V_8 ) {
for ( V_96 = 0 ; V_96 < 7 ; V_96 ++ )
F_44 ( V_77 + V_96 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_38 , 0 ,
V_22 -> V_163 ,
0 , 0 ) ;
F_45 ( V_4 , V_65 , - 900 , 899 , 0 , 0 ) ;
F_46 ( V_1 ) ;
} else if ( V_22 -> V_189 == V_190 ) {
F_52 ( V_12 , V_4 -> V_210 ) ;
F_44 ( V_190 , V_4 -> V_187 ) ;
F_44 ( V_214 , V_4 -> V_187 ) ;
F_44 ( V_215 , V_4 -> V_187 ) ;
F_44 ( V_216 , V_4 -> V_187 ) ;
F_53 ( V_4 , V_22 -> V_109 , 0 ) ;
F_45 ( V_4 , V_132 ,
0 , V_22 -> V_191 , 0 , 0 ) ;
F_45 ( V_4 , V_156 ,
0 , V_22 -> V_192 , 0 , 0 ) ;
F_45 ( V_4 , V_130 ,
0 , V_22 -> V_191 ,
V_22 -> V_196 , 0 ) ;
F_45 ( V_4 , V_131 ,
0 , V_22 -> V_192 ,
V_22 -> V_197 , 0 ) ;
}
break;
case V_103 :
case V_68 :
F_44 ( V_84 , V_4 -> V_187 ) ;
F_44 ( V_85 , V_4 -> V_187 ) ;
case V_67 :
for ( V_96 = 0 ; V_96 < 7 ; V_96 ++ )
F_44 ( V_77 + V_96 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_65 , - 900 , 899 , 0 , 0 ) ;
F_46 ( V_1 ) ;
F_44 ( V_211 , V_4 -> V_212 ) ;
break;
case V_180 :
if ( V_22 -> V_189 == V_190 ) {
F_45 ( V_4 , V_132 , 0 , V_22 -> V_191 , 0 , 0 ) ;
F_45 ( V_4 , V_133 , 0 , V_22 -> V_191 , 0 , 0 ) ;
F_45 ( V_4 , V_134 , 0 , V_22 -> V_192 , 0 , 0 ) ;
F_45 ( V_4 , V_135 , 0 , 1 , 0 , 0 ) ;
}
case V_184 :
if ( V_22 -> V_189 == V_190 ) {
V_1 -> V_110 = F_54 ( V_22 -> V_109 *
sizeof( int ) ,
V_217 ) ;
if ( ! V_1 -> V_110 )
return - V_218 ;
for ( V_96 = 0 ; V_96 < V_22 -> V_109 ; V_96 ++ )
V_1 -> V_110 [ V_96 ] = - 1 ;
}
case V_183 :
if ( V_22 -> V_189 == V_190 ) {
F_53 ( V_4 , V_22 -> V_109 , 0 ) ;
F_45 ( V_4 , V_219 ,
0 , V_220 , 0 , 0 ) ;
F_45 ( V_4 , V_130 ,
0 , V_22 -> V_191 , 0 , 0 ) ;
F_45 ( V_4 , V_131 ,
0 , V_22 -> V_192 , 0 , 0 ) ;
}
case V_181 :
case V_182 :
F_52 ( V_12 , V_4 -> V_210 ) ;
F_44 ( V_213 , V_4 -> V_212 ) ;
if ( V_22 -> V_189 != V_8 )
break;
case V_175 :
case V_178 :
F_44 ( V_8 , V_4 -> V_187 ) ;
F_44 ( V_7 , V_4 -> V_187 ) ;
F_44 ( V_17 , V_4 -> V_187 ) ;
F_44 ( V_27 , V_4 -> V_187 ) ;
F_44 ( V_213 , V_4 -> V_212 ) ;
break;
case V_177 :
F_44 ( V_27 , V_4 -> V_187 ) ;
case V_174 :
F_44 ( V_8 , V_4 -> V_187 ) ;
F_44 ( V_7 , V_4 -> V_187 ) ;
F_44 ( V_17 , V_4 -> V_187 ) ;
F_44 ( V_211 , V_4 -> V_212 ) ;
break;
case V_185 :
F_52 ( V_12 , V_4 -> V_210 ) ;
F_44 ( V_211 , V_4 -> V_212 ) ;
if ( V_22 -> V_189 == V_190 ) {
F_44 ( V_34 , V_4 -> V_187 ) ;
F_44 ( V_44 , V_4 -> V_187 ) ;
F_44 ( V_43 , V_4 -> V_187 ) ;
F_44 ( V_35 , V_4 -> V_187 ) ;
F_44 ( V_190 , V_4 -> V_187 ) ;
F_44 ( V_214 , V_4 -> V_187 ) ;
F_53 ( V_4 , V_22 -> V_109 , 0 ) ;
if ( V_22 -> V_195 == V_165 ) {
F_44 ( V_215 ,
V_4 -> V_187 ) ;
F_44 ( V_216 ,
V_4 -> V_187 ) ;
F_45 ( V_4 ,
V_132 ,
0 , V_22 -> V_191 , 0 , 0 ) ;
F_45 ( V_4 ,
V_156 ,
0 , V_22 -> V_192 , 0 , 0 ) ;
}
F_45 ( V_4 , V_130 ,
0 , V_22 -> V_191 ,
V_22 -> V_196 , 0 ) ;
F_45 ( V_4 , V_131 ,
0 , V_22 -> V_192 ,
V_22 -> V_197 , 0 ) ;
} else if ( V_22 -> V_189 == V_8 ) {
F_44 ( V_7 , V_4 -> V_187 ) ;
F_44 ( V_8 , V_4 -> V_187 ) ;
F_44 ( V_17 , V_4 -> V_187 ) ;
F_44 ( V_27 , V_4 -> V_187 ) ;
F_45 ( V_4 , V_38 , 0 ,
V_22 -> V_163 ,
0 , 0 ) ;
}
break;
}
return 0 ;
}
