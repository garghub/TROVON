static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [ 2 ] = {
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_11 = & V_3 , . V_12 = 1 } ,
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = V_13 , . V_11 = V_4 , . V_12 = 1 } ,
} ;
if ( F_2 ( V_2 -> V_14 , V_6 , 2 ) != 2 ) {
F_3 ( V_15 L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_11 [ 2 ] = { V_3 , V_4 } ;
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_11 = V_11 , . V_12 = 2
} ;
if ( F_2 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_3 ( V_15 L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_11 , T_1 V_12 )
{
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_11 = V_11 , . V_12 = V_12
} ;
if ( F_2 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_3 ( V_15 L_3 , ( int ) V_12 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_21 = 0 ;
T_2 V_22 ;
T_2 V_23 ;
T_1 V_24 ;
T_1 V_25 [ 10 ] ;
int V_26 ;
T_1 V_27 ;
V_2 = V_18 -> V_28 ;
V_22 = V_20 -> V_29 / 1000 ;
if ( V_22 < 470000 && V_22 > 230000 )
return - V_30 ;
V_2 -> V_31 = ( V_18 -> V_32 . V_33 . type == V_34 ) ? V_20 -> V_35 . V_36 . V_31 : 0 ;
V_2 -> V_29 = V_22 * 1000 ;
V_23 = 2 * V_22 * ( 8192 / 16 ) / ( V_37 / 16 ) ;
V_27 = ( V_22 < 300000 ) ? V_38 : V_39 ;
if ( V_27 == V_38 )
V_23 *= 2 ;
switch ( V_20 -> V_35 . V_36 . V_31 ) {
case V_40 :
F_5 ( V_2 , V_41 ,
sizeof( V_41 ) ) ;
break;
case V_42 :
F_5 ( V_2 , V_43 ,
sizeof( V_43 ) ) ;
break;
case V_44 :
default:
F_5 ( V_2 , V_45 ,
sizeof( V_45 ) ) ;
break;
}
if ( V_27 == V_38 && V_2 -> V_27 == V_39 ) {
F_7 ( L_4 ) ;
F_4 ( V_2 , 0x05 , 0x04 ) ;
F_4 ( V_2 , 0x19 , 0x61 ) ;
F_5 ( V_2 , V_46 , sizeof( V_46 ) ) ;
} else if ( V_27 == V_39 && V_2 -> V_27 == V_38 ) {
F_7 ( L_5 ) ;
F_4 ( V_2 , 0x05 , 0x52 ) ;
F_4 ( V_2 , 0x19 , 0x61 ) ;
F_5 ( V_2 , V_47 , sizeof( V_47 ) ) ;
}
F_8 ( 10 ) ;
if ( V_22 <= 495000 )
V_24 = 0xEE ;
else if ( V_22 <= 525000 )
V_24 = 0xDD ;
else if ( V_22 <= 550000 )
V_24 = 0xCC ;
else if ( V_22 <= 580000 )
V_24 = 0xBB ;
else if ( V_22 <= 605000 )
V_24 = 0xAA ;
else if ( V_22 <= 630000 )
V_24 = 0x99 ;
else if ( V_22 <= 655000 )
V_24 = 0x88 ;
else if ( V_22 <= 685000 )
V_24 = 0x77 ;
else if ( V_22 <= 710000 )
V_24 = 0x66 ;
else if ( V_22 <= 735000 )
V_24 = 0x55 ;
else if ( V_22 <= 765000 )
V_24 = 0x44 ;
else if ( V_22 <= 802000 )
V_24 = 0x33 ;
else if ( V_22 <= 840000 )
V_24 = 0x22 ;
else
V_24 = 0x11 ;
V_25 [ 0 ] = V_48 ;
V_25 [ 1 ] = ( V_23 >> 8 ) & 0x1F ;
V_25 [ 2 ] = V_23 & 0xFF ;
V_25 [ 3 ] = V_23 >> 13 ;
F_5 ( V_2 , V_25 , 4 ) ;
F_7 ( L_6 ,
( int ) V_23 , ( int ) V_24 ,
( V_27 == V_39 ) ? L_7 : L_8 ) ;
F_7 ( L_9 ,
( int ) V_25 [ 1 ] , ( int ) V_25 [ 2 ] , ( int ) V_25 [ 3 ] ) ;
if ( V_27 == V_39 ) {
V_25 [ 0 ] = 0x05 ;
V_25 [ 1 ] = ( V_2 -> V_27 == V_38 ) ? 0x52 : 0x62 ;
V_25 [ 2 ] = V_24 ;
F_5 ( V_2 , V_25 , 3 ) ;
}
V_26 = 0 ;
do {
F_1 ( V_2 , V_49 , V_25 ) ;
if ( V_25 [ 0 ] & 0x40 )
break;
F_8 ( 10 ) ;
V_26 ++ ;
} while ( V_26 < 10 );
F_7 ( L_10 , ( int ) V_26 ) ;
if ( V_27 == V_39 && V_2 -> V_27 == V_38 )
F_4 ( V_2 , 0x05 , 0x62 ) ;
V_2 -> V_27 = V_27 ;
return V_21 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 0x11 , 0x03 ) ;
F_4 ( V_2 , 0x11 , 0x01 ) ;
F_5 ( V_2 , V_50 , sizeof( V_50 ) ) ;
F_5 ( V_2 , V_51 , sizeof( V_51 ) ) ;
F_4 ( V_2 , 0x33 , 0x5e ) ;
F_4 ( V_2 , 0x10 , 0x10 ) ;
F_4 ( V_2 , 0x10 , 0x00 ) ;
F_5 ( V_2 , V_45 , sizeof( V_45 ) ) ;
F_8 ( 25 ) ;
F_4 ( V_2 , 0x17 , 0x6d ) ;
F_4 ( V_2 , 0x1c , 0x00 ) ;
F_8 ( 75 ) ;
F_4 ( V_2 , 0x17 , 0x6d ) ;
F_4 ( V_2 , 0x1c , 0xff ) ;
}
static int F_10 ( struct V_17 * V_18 , T_2 * V_29 )
{
struct V_1 * V_2 = V_18 -> V_28 ;
* V_29 = V_2 -> V_29 ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , T_2 * V_31 )
{
struct V_1 * V_2 = V_18 -> V_28 ;
* V_31 = V_2 -> V_31 ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
int V_21 ;
struct V_1 * V_2 = V_18 -> V_28 ;
V_21 = F_4 ( V_2 , 0x17 , 0x6d ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_4 ( V_2 , 0x1c , 0xff ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_28 ;
F_4 ( V_2 , 0x17 , 0x6d ) ;
F_4 ( V_2 , 0x1c , 0x00 ) ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
F_15 ( V_18 -> V_28 ) ;
V_18 -> V_28 = NULL ;
return 0 ;
}
struct V_17 * F_16 ( struct V_17 * V_18 , struct V_52 * V_14 , struct V_53 * V_8 )
{
struct V_1 * V_2 = NULL ;
T_1 V_54 = 0 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_55 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_27 = V_39 ;
if ( F_1 ( V_2 , 0 , & V_54 ) ) {
F_15 ( V_2 ) ;
return NULL ;
}
if ( V_54 != V_56 ) {
F_15 ( V_2 ) ;
return NULL ;
}
F_3 ( V_57 L_11 ) ;
memcpy ( & V_18 -> V_32 . V_58 , & V_59 , sizeof( struct V_60 ) ) ;
V_18 -> V_28 = V_2 ;
F_9 ( V_2 ) ;
return V_18 ;
}
