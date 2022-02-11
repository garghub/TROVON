static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 [] = { V_4 , V_5 } ;
struct V_8 V_9 = { . V_3 = V_3 , . V_10 = 0 , . V_7 = V_7 , . V_11 = 2 } ;
V_6 = F_2 ( V_2 -> V_12 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_3 ( V_13 L_1 ,
V_14 , V_3 , V_4 , V_5 , V_6 ) ;
return ( V_6 != 1 ) ? - 1 : 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_6 ;
T_1 V_15 [] = { V_4 } ;
T_1 V_16 [] = { 0 } ;
struct V_8 V_9 [] = {
{ . V_3 = V_3 , . V_10 = 0 , . V_7 = V_15 , . V_11 = 1 } ,
{ . V_3 = V_3 , . V_10 = V_17 , . V_7 = V_16 , . V_11 = 1 }
} ;
V_6 = F_2 ( V_2 -> V_12 , V_9 , 2 ) ;
if ( V_6 != 2 )
F_3 ( V_13 L_2 ,
V_14 , V_6 ) ;
return V_16 [ 0 ] ;
}
static int F_5 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_6 ( struct V_18 * V_19 ,
T_2 V_20 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
T_1 V_4 = 0 ;
V_4 = F_4 ( V_2 , V_22 , 0x2E ) ;
V_4 &= ~ ( 0x0C ) ;
switch ( V_20 ) {
case 6 :
V_4 |= 0x08 ;
break;
case 7 :
V_4 |= 0x04 ;
break;
case 8 :
V_4 |= 0x00 ;
break;
default:
return 0 ;
}
F_1 ( V_2 , V_22 , 0x2E , V_4 ) ;
return 1 ;
}
static int F_7 ( struct V_18 * V_19 , T_2 V_23 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
switch ( V_23 ) {
case V_24 :
F_1 ( V_2 , V_22 , 0xe4 , 0x55 ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0x55 ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0x15 ) ;
break;
case V_25 :
F_1 ( V_2 , V_22 , 0xe4 , 0x00 ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0x00 ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0x40 ) ;
break;
case V_26 :
F_1 ( V_2 , V_22 , 0xe4 , 0x00 ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0x00 ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0xe0 ) ;
break;
case V_27 :
F_1 ( V_2 , V_22 , 0xe4 , 0x66 ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0x66 ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0xEE ) ;
break;
case V_28 :
F_1 ( V_2 , V_22 , 0xe4 , 0x55 ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0x55 ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0xED ) ;
break;
case V_29 :
F_1 ( V_2 , V_22 , 0xe4 , 0xAA ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0xAA ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0xEA ) ;
break;
default:
{
T_2 V_30 = 0 ;
V_30 = ( T_2 ) ( ( ( 48000 - ( V_23 / 1000 ) ) * 512 *
( T_2 ) 32768 ) / ( 48 * 1000 ) ) ;
F_3 ( V_31
L_3 ,
V_23 , V_30 ) ;
F_1 ( V_2 , V_22 , 0xe4 ,
( T_1 ) V_30 & 0xFF ) ;
F_1 ( V_2 , V_22 , 0xe5 ,
( T_1 ) ( V_30 >> 8 ) & 0xFF ) ;
F_1 ( V_2 , V_22 , 0xe7 ,
( T_1 ) ( V_30 >> 16 ) & 0xFF ) ;
break;
}
}
return 1 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = & V_19 -> V_34 ;
T_2 V_35 = 8 ;
struct V_1 * V_2 = V_19 -> V_21 ;
if ( V_33 -> V_36 == V_2 -> V_37 ) {
} else {
V_19 -> V_38 . V_39 . V_40 ( V_19 ) ;
F_9 ( 300 ) ;
F_6 ( V_19 , V_35 ) ;
switch ( V_33 -> V_41 ) {
case 6000000 :
V_35 = 6 ;
F_7 ( V_19 , V_29 ) ;
break;
case 7000000 :
V_35 = 7 ;
F_7 ( V_19 , V_29 ) ;
break;
case 8000000 :
V_35 = 8 ;
F_7 ( V_19 , V_29 ) ;
break;
default:
return 0 ;
}
F_9 ( 30 ) ;
F_1 ( V_2 , V_22 , 0x09 , 0x1a ) ;
F_9 ( 30 ) ;
F_1 ( V_2 , V_22 , 0x09 , 0x1b ) ;
F_6 ( V_19 , V_35 ) ;
switch ( V_33 -> V_41 ) {
case 6000000 :
V_35 = 6 ;
F_7 ( V_19 , V_29 ) ;
break;
case 7000000 :
V_35 = 7 ;
F_7 ( V_19 , V_29 ) ;
break;
case 8000000 :
V_35 = 8 ;
F_7 ( V_19 , V_29 ) ;
break;
default:
return 0 ;
}
F_9 ( 30 ) ;
F_1 ( V_2 , V_22 , 0x09 , 0x1a ) ;
F_9 ( 30 ) ;
F_1 ( V_2 , V_22 , 0x09 , 0x1b ) ;
}
V_2 -> V_37 = V_33 -> V_36 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
T_1 V_4 = 0 ;
V_2 -> V_37 = 0 ;
F_3 ( V_31 L_4 ) ;
F_1 ( V_2 , V_22 , 0x04 , 0xa8 ) ;
F_1 ( V_2 , V_22 , 0x05 , 0x01 ) ;
F_1 ( V_2 , V_22 , 0x07 , 0x70 ) ;
F_1 ( V_2 , V_22 , 0x19 , 0x80 ) ;
F_1 ( V_2 , V_22 , 0x1b , 0x9D ) ;
F_1 ( V_2 , V_22 , 0x1c , 0x30 ) ;
F_1 ( V_2 , V_22 , 0x1d , 0x20 ) ;
F_1 ( V_2 , V_22 , 0x1e , 0x1B ) ;
F_1 ( V_2 , V_22 , 0x2e , 0x40 ) ;
F_1 ( V_2 , V_22 , 0x42 , 0x84 ) ;
F_1 ( V_2 , V_22 , 0x50 , 0x5a ) ;
F_1 ( V_2 , V_22 , 0x5a , 0xd3 ) ;
F_1 ( V_2 , V_22 , 0x68 , 0x50 ) ;
F_1 ( V_2 , V_22 , 0xb8 , 0x3c ) ;
F_1 ( V_2 , V_22 , 0xc4 , 0x10 ) ;
F_1 ( V_2 , V_22 , 0xcc , 0x9c ) ;
F_1 ( V_2 , V_22 , 0xDA , 0x00 ) ;
F_1 ( V_2 , V_22 , 0xe1 , 0x94 ) ;
F_1 ( V_2 , V_22 , 0xf9 , 0x00 ) ;
F_1 ( V_2 , V_22 , 0xe4 , 0x66 ) ;
F_1 ( V_2 , V_22 , 0xe5 , 0x66 ) ;
F_1 ( V_2 , V_22 , 0xe7 , 0xEE ) ;
F_1 ( V_2 , V_22 , 0x1e , 0x31 ) ;
V_4 = F_4 ( V_2 , V_22 , 0x42 ) ;
V_4 |= 0x80 ;
F_1 ( V_2 , V_22 , 0x42 , V_4 ) ;
F_1 ( V_2 , V_22 , 0x09 , 0x1a ) ;
F_9 ( 30 ) ;
F_1 ( V_2 , V_22 , 0x09 , 0x1b ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 , enum V_42 * V_43 )
{
return 0 ;
}
static int F_12 ( struct V_18 * V_19 ,
T_3 * V_44 )
{
return 0 ;
}
static int F_13 ( struct V_18 * V_19 , T_3 * V_45 )
{
return 0 ;
}
static int F_14 ( struct V_18 * V_19 , T_2 * V_46 )
{
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , T_2 * V_47 )
{
return 0 ;
}
static int F_16 ( struct V_18 * V_19 ,
struct V_48 * V_49 )
{
return 0 ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
F_18 ( V_2 ) ;
}
struct V_18 * F_19 ( const struct V_50 * V_51 ,
struct V_52 * V_12 )
{
struct V_1 * V_2 = NULL ;
F_3 ( V_31 L_5 ) ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_51 = V_51 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = V_2 -> V_51 -> V_56 ;
memcpy ( & V_2 -> V_57 . V_38 , & V_58 ,
sizeof( struct V_59 ) ) ;
V_2 -> V_57 . V_21 = V_2 ;
return & V_2 -> V_57 ;
}
