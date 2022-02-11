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
static int F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
T_2 V_23 ;
T_2 V_24 ;
T_1 V_25 ;
T_1 V_26 [ 10 ] ;
int V_27 ;
T_1 V_28 ;
V_2 = V_18 -> V_29 ;
V_23 = V_2 -> V_30 / 1000 ;
if ( V_23 < 470000 && V_23 > 230000 )
return - V_31 ;
V_2 -> V_30 = V_20 -> V_30 ;
V_24 = 2 * V_23 * ( 8192 / 16 ) / ( V_32 / 16 ) ;
V_28 = ( V_23 < 300000 ) ? V_33 : V_34 ;
if ( V_28 == V_33 )
V_24 *= 2 ;
switch ( V_20 -> V_35 ) {
case 6000000 :
F_5 ( V_2 , V_36 ,
sizeof( V_36 ) ) ;
break;
case 8000000 :
F_5 ( V_2 , V_37 ,
sizeof( V_37 ) ) ;
break;
case 7000000 :
default:
F_5 ( V_2 , V_38 ,
sizeof( V_38 ) ) ;
break;
}
V_2 -> V_39 = V_20 -> V_35 ;
if ( V_28 == V_33 && V_2 -> V_28 == V_34 ) {
F_7 ( L_4 ) ;
F_4 ( V_2 , 0x05 , 0x04 ) ;
F_4 ( V_2 , 0x19 , 0x61 ) ;
F_5 ( V_2 , V_40 , sizeof( V_40 ) ) ;
} else if ( V_28 == V_34 && V_2 -> V_28 == V_33 ) {
F_7 ( L_5 ) ;
F_4 ( V_2 , 0x05 , 0x52 ) ;
F_4 ( V_2 , 0x19 , 0x61 ) ;
F_5 ( V_2 , V_41 , sizeof( V_41 ) ) ;
}
F_8 ( 10 ) ;
if ( V_23 <= 495000 )
V_25 = 0xEE ;
else if ( V_23 <= 525000 )
V_25 = 0xDD ;
else if ( V_23 <= 550000 )
V_25 = 0xCC ;
else if ( V_23 <= 580000 )
V_25 = 0xBB ;
else if ( V_23 <= 605000 )
V_25 = 0xAA ;
else if ( V_23 <= 630000 )
V_25 = 0x99 ;
else if ( V_23 <= 655000 )
V_25 = 0x88 ;
else if ( V_23 <= 685000 )
V_25 = 0x77 ;
else if ( V_23 <= 710000 )
V_25 = 0x66 ;
else if ( V_23 <= 735000 )
V_25 = 0x55 ;
else if ( V_23 <= 765000 )
V_25 = 0x44 ;
else if ( V_23 <= 802000 )
V_25 = 0x33 ;
else if ( V_23 <= 840000 )
V_25 = 0x22 ;
else
V_25 = 0x11 ;
V_26 [ 0 ] = V_42 ;
V_26 [ 1 ] = ( V_24 >> 8 ) & 0x1F ;
V_26 [ 2 ] = V_24 & 0xFF ;
V_26 [ 3 ] = V_24 >> 13 ;
F_5 ( V_2 , V_26 , 4 ) ;
F_7 ( L_6 ,
( int ) V_24 , ( int ) V_25 ,
( V_28 == V_34 ) ? L_7 : L_8 ) ;
F_7 ( L_9 ,
( int ) V_26 [ 1 ] , ( int ) V_26 [ 2 ] , ( int ) V_26 [ 3 ] ) ;
if ( V_28 == V_34 ) {
V_26 [ 0 ] = 0x05 ;
V_26 [ 1 ] = ( V_2 -> V_28 == V_33 ) ? 0x52 : 0x62 ;
V_26 [ 2 ] = V_25 ;
F_5 ( V_2 , V_26 , 3 ) ;
}
V_27 = 0 ;
do {
F_1 ( V_2 , V_43 , V_26 ) ;
if ( V_26 [ 0 ] & 0x40 )
break;
F_8 ( 10 ) ;
V_27 ++ ;
} while ( V_27 < 10 );
F_7 ( L_10 , ( int ) V_27 ) ;
if ( V_28 == V_34 && V_2 -> V_28 == V_33 )
F_4 ( V_2 , 0x05 , 0x62 ) ;
V_2 -> V_28 = V_28 ;
return V_22 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 0x11 , 0x03 ) ;
F_4 ( V_2 , 0x11 , 0x01 ) ;
F_5 ( V_2 , V_44 , sizeof( V_44 ) ) ;
F_5 ( V_2 , V_45 , sizeof( V_45 ) ) ;
F_4 ( V_2 , 0x33 , 0x5e ) ;
F_4 ( V_2 , 0x10 , 0x10 ) ;
F_4 ( V_2 , 0x10 , 0x00 ) ;
F_5 ( V_2 , V_37 , sizeof( V_37 ) ) ;
F_8 ( 25 ) ;
F_4 ( V_2 , 0x17 , 0x6d ) ;
F_4 ( V_2 , 0x1c , 0x00 ) ;
F_8 ( 75 ) ;
F_4 ( V_2 , 0x17 , 0x6d ) ;
F_4 ( V_2 , 0x1c , 0xff ) ;
}
static int F_10 ( struct V_17 * V_18 , T_2 * V_30 )
{
struct V_1 * V_2 = V_18 -> V_29 ;
* V_30 = V_2 -> V_30 ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , T_2 * V_39 )
{
struct V_1 * V_2 = V_18 -> V_29 ;
* V_39 = V_2 -> V_39 ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
int V_22 ;
struct V_1 * V_2 = V_18 -> V_29 ;
V_22 = F_4 ( V_2 , 0x17 , 0x6d ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_4 ( V_2 , 0x1c , 0xff ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_29 ;
F_4 ( V_2 , 0x17 , 0x6d ) ;
F_4 ( V_2 , 0x1c , 0x00 ) ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
F_15 ( V_18 -> V_29 ) ;
V_18 -> V_29 = NULL ;
return 0 ;
}
struct V_17 * F_16 ( struct V_17 * V_18 , struct V_46 * V_14 , struct V_47 * V_8 )
{
struct V_1 * V_2 = NULL ;
T_1 V_48 = 0 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_49 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_28 = V_34 ;
if ( F_1 ( V_2 , 0 , & V_48 ) ) {
F_15 ( V_2 ) ;
return NULL ;
}
if ( V_48 != V_50 ) {
F_15 ( V_2 ) ;
return NULL ;
}
F_3 ( V_51 L_11 ) ;
memcpy ( & V_18 -> V_52 . V_53 , & V_54 , sizeof( struct V_55 ) ) ;
V_18 -> V_29 = V_2 ;
F_9 ( V_2 ) ;
return V_18 ;
}
