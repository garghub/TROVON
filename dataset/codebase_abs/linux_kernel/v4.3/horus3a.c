static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , const T_1 * V_5 , T_2 V_6 )
{
F_2 ( & V_2 -> V_7 -> V_8 , L_1 ,
( V_4 == 0 ? L_2 : L_3 ) , V_3 , V_6 ) ;
F_3 ( L_4 ,
V_9 , V_5 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , const T_1 * V_5 , T_2 V_6 )
{
int V_10 ;
T_1 V_11 [ V_12 + 1 ] ;
struct V_13 V_14 [ 1 ] = {
{
. V_15 = V_2 -> V_16 ,
. V_17 = 0 ,
. V_6 = V_6 + 1 ,
. V_11 = V_11 ,
}
} ;
if ( V_6 + 1 >= sizeof( V_11 ) ) {
F_5 ( & V_2 -> V_7 -> V_8 , L_5 ,
V_3 , V_6 + 1 ) ;
return - V_18 ;
}
F_1 ( V_2 , V_3 , 1 , V_5 , V_6 ) ;
V_11 [ 0 ] = V_3 ;
memcpy ( & V_11 [ 1 ] , V_5 , V_6 ) ;
V_10 = F_6 ( V_2 -> V_7 , V_14 , 1 ) ;
if ( V_10 >= 0 && V_10 != 1 )
V_10 = - V_19 ;
if ( V_10 < 0 ) {
F_5 ( & V_2 -> V_7 -> V_8 ,
L_6 ,
V_20 , V_10 , V_3 , V_6 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_21 )
{
return F_4 ( V_2 , V_3 , & V_21 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] ;
F_2 ( & V_2 -> V_7 -> V_8 , L_7 , V_22 ) ;
if ( V_2 -> V_23 == V_24 )
return 0 ;
F_7 ( V_2 , 0x2a , 0x79 ) ;
F_7 ( V_2 , 0x29 , 0x70 ) ;
F_7 ( V_2 , 0x28 , 0x3e ) ;
F_7 ( V_2 , 0x2a , 0x19 ) ;
F_7 ( V_2 , 0x1c , 0x00 ) ;
V_5 [ 0 ] = 0xC0 ;
V_5 [ 1 ] = 0xA7 ;
F_4 ( V_2 , 0x11 , V_5 , sizeof( V_5 ) ) ;
V_2 -> V_23 = V_24 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] ;
F_2 ( & V_2 -> V_7 -> V_8 , L_7 , V_22 ) ;
if ( V_2 -> V_23 == V_25 )
return 0 ;
V_5 [ 0 ] = 0x00 ;
V_5 [ 1 ] = 0xa7 ;
F_4 ( V_2 , 0x11 , V_5 , sizeof( V_5 ) ) ;
F_7 ( V_2 , 0x2a , 0x79 ) ;
F_7 ( V_2 , 0x1c , 0xc0 ) ;
F_7 ( V_2 , 0x29 , 0x71 ) ;
F_10 ( 5000 , 7000 ) ;
V_2 -> V_23 = V_25 ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_7 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_7 , V_22 ) ;
F_13 ( V_27 -> V_28 ) ;
V_27 -> V_28 = NULL ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_7 , V_22 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_29 * V_30 = & V_27 -> V_31 ;
struct V_1 * V_2 = V_27 -> V_28 ;
T_2 V_32 = V_30 -> V_32 ;
T_2 V_33 = V_30 -> V_33 / 1000 ;
T_1 V_34 = 0 ;
T_1 V_35 = 0 ;
T_2 V_36 = 0 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
T_1 V_39 = 0 ;
T_1 V_5 [ 5 ] ;
F_2 ( & V_2 -> V_7 -> V_8 , L_8 ,
V_22 , V_32 , V_33 ) ;
if ( V_2 -> V_40 )
V_2 -> V_40 ( V_2 -> V_41 , 0 ) ;
if ( V_2 -> V_23 == V_24 )
F_9 ( V_2 ) ;
V_32 = F_16 ( V_32 , 1000 ) * 1000 ;
if ( V_32 <= 1155000 ) {
V_34 = 4 ;
V_35 = 1 ;
} else {
V_34 = 2 ;
V_35 = 0 ;
}
V_36 = F_16 ( ( V_32 * V_34 ) / 2 , 1000 ) ;
if ( V_36 > 0x7FFF ) {
F_17 ( & V_2 -> V_7 -> V_8 , L_9 ,
V_32 ) ;
return - V_42 ;
}
if ( V_32 < 975000 ) {
V_37 = 0x1C ;
V_38 = 0x01 ;
} else if ( V_32 < 1050000 ) {
V_37 = 0x18 ;
V_38 = 0x02 ;
} else if ( V_32 < 1150000 ) {
V_37 = 0x14 ;
V_38 = 0x02 ;
} else if ( V_32 < 1250000 ) {
V_37 = 0x10 ;
V_38 = 0x03 ;
} else if ( V_32 < 1350000 ) {
V_37 = 0x0C ;
V_38 = 0x04 ;
} else if ( V_32 < 1450000 ) {
V_37 = 0x0A ;
V_38 = 0x04 ;
} else if ( V_32 < 1600000 ) {
V_37 = 0x07 ;
V_38 = 0x05 ;
} else if ( V_32 < 1800000 ) {
V_37 = 0x04 ;
V_38 = 0x02 ;
} else if ( V_32 < 2000000 ) {
V_37 = 0x02 ;
V_38 = 0x01 ;
} else {
V_37 = 0x00 ;
V_38 = 0x00 ;
}
if ( V_30 -> V_43 == V_44 ) {
if ( V_33 <= 4300 )
V_39 = 5 ;
else if ( V_33 <= 10000 )
V_39 = ( T_1 ) F_18 ( V_33 * 47 , 40000 ) ;
else
V_39 = ( T_1 ) F_18 ( V_33 * 27 , 40000 ) + 5 ;
if ( V_39 > 36 )
V_39 = 36 ;
} else if ( V_30 -> V_43 == V_45 ) {
int V_46 ;
switch ( V_30 -> V_46 ) {
case V_47 :
V_46 = 35 ;
break;
case V_48 :
V_46 = 25 ;
break;
case V_49 :
V_46 = 20 ;
break;
case V_50 :
default:
F_17 ( & V_2 -> V_7 -> V_8 ,
L_10 ) ;
return - V_42 ;
}
if ( V_33 <= 4500 )
V_39 = 5 ;
else if ( V_33 <= 10000 )
V_39 = ( T_1 ) F_18 (
V_33 * ( 200 + V_46 ) , 200000 ) ;
else
V_39 = ( T_1 ) F_18 (
V_33 * ( 100 + V_46 ) , 200000 ) + 5 ;
if ( V_39 > 36 )
V_39 = 36 ;
} else {
F_17 ( & V_2 -> V_7 -> V_8 ,
L_11 ,
V_30 -> V_43 ) ;
return - V_42 ;
}
V_5 [ 0 ] = ( T_1 ) ( ( V_36 >> 7 ) & 0xFF ) ;
V_5 [ 1 ] = ( T_1 ) ( ( V_36 << 1 ) & 0xFF ) ;
V_5 [ 2 ] = 0x00 ;
V_5 [ 3 ] = 0x00 ;
V_5 [ 4 ] = ( T_1 ) ( V_35 << 7 ) ;
F_4 ( V_2 , 0x00 , V_5 , sizeof( V_5 ) ) ;
F_7 ( V_2 , 0x09 , ( T_1 ) ( ( V_38 << 5 ) | V_37 ) ) ;
F_7 ( V_2 , 0x37 , ( T_1 ) ( 0x80 | ( V_39 << 1 ) ) ) ;
F_7 ( V_2 , 0x05 , 0x80 ) ;
F_7 ( V_2 , 0x2a , 0x7b ) ;
F_19 ( 60 ) ;
V_2 -> V_32 = V_36 * 2 * 1000 / V_34 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 , T_2 * V_32 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
* V_32 = V_2 -> V_32 ;
return 0 ;
}
struct V_26 * F_21 ( struct V_26 * V_27 ,
const struct V_51 * V_52 ,
struct V_53 * V_7 )
{
T_1 V_11 [ 3 ] , V_21 ;
struct V_1 * V_2 = NULL ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_54 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_16 = ( V_52 -> V_16 >> 1 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_41 = V_52 -> V_55 ;
V_2 -> V_40 = V_52 -> V_56 ;
if ( V_27 -> V_57 . V_58 )
V_27 -> V_57 . V_58 ( V_27 , 1 ) ;
F_10 ( 4000 , 6000 ) ;
F_7 ( V_2 , 0x2a , 0x79 ) ;
V_11 [ 0 ] = V_52 -> V_59 ;
V_11 [ 1 ] = V_52 -> V_59 ;
V_11 [ 2 ] = 0 ;
F_4 ( V_2 , 0x6 , V_11 , 3 ) ;
F_7 ( V_2 , 0x0a , 0x40 ) ;
switch ( V_52 -> V_59 ) {
case 27 :
V_21 = 0x1f ;
break;
case 24 :
V_21 = 0x10 ;
break;
case 16 :
V_21 = 0xc ;
break;
default:
V_21 = 0 ;
F_5 ( & V_2 -> V_7 -> V_8 ,
L_12 ,
V_52 -> V_59 ) ;
break;
}
V_21 <<= 2 ;
F_7 ( V_2 , 0x0e , V_21 ) ;
F_8 ( V_2 ) ;
F_10 ( 3000 , 5000 ) ;
if ( V_27 -> V_57 . V_58 )
V_27 -> V_57 . V_58 ( V_27 , 0 ) ;
memcpy ( & V_27 -> V_57 . V_60 , & V_61 ,
sizeof( struct V_62 ) ) ;
V_27 -> V_28 = V_2 ;
F_23 ( & V_2 -> V_7 -> V_8 ,
L_13 ,
V_2 -> V_16 , V_2 -> V_7 ) ;
return V_27 ;
}
