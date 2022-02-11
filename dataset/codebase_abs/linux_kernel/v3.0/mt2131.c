static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [ 2 ] = {
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 ,
. V_11 = & V_3 , . V_12 = 1 } ,
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = V_13 ,
. V_11 = V_4 , . V_12 = 1 } ,
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
struct V_5 V_6 = { . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 ,
. V_11 = V_11 , . V_12 = 2 } ;
if ( F_2 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_3 ( V_15 L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_11 , T_1 V_12 )
{
struct V_5 V_6 = { . V_7 = V_2 -> V_8 -> V_9 ,
. V_10 = 0 , . V_11 = V_11 , . V_12 = V_12 } ;
if ( F_2 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_3 ( V_15 L_3 ,
( int ) V_12 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_21 = 0 , V_22 ;
T_2 V_23 ;
T_1 V_24 ;
T_2 V_25 , V_26 ;
T_2 V_27 , V_28 , V_29 , V_30 ;
T_1 V_31 [ 8 ] ;
T_1 V_32 = 0 ;
V_2 = V_18 -> V_33 ;
if ( V_18 -> V_34 . V_35 . type == V_36 )
V_2 -> V_37 = V_20 -> V_38 . V_39 . V_37 ;
else
V_2 -> V_37 = 0 ;
V_23 = V_20 -> V_40 / 1000 ;
F_7 ( 1 , L_4 , V_41 , V_23 ) ;
V_25 = V_23 + V_42 * 1000 ;
V_25 = ( V_25 / 250 ) * 250 ;
V_26 = V_25 - V_23 - V_43 ;
V_2 -> V_40 = ( V_25 - V_26 - V_43 ) * 1000 ;
V_28 = V_25 * 64 / ( V_44 / 128 ) ;
V_27 = V_28 / 8192 ;
V_28 &= 0x1fff ;
V_30 = V_26 * 64 / ( V_44 / 128 ) ;
V_29 = V_30 / 8192 ;
V_30 &= 0x1fff ;
if ( V_23 <= 82500 ) V_24 = 0x00 ; else
if ( V_23 <= 137500 ) V_24 = 0x01 ; else
if ( V_23 <= 192500 ) V_24 = 0x02 ; else
if ( V_23 <= 247500 ) V_24 = 0x03 ; else
if ( V_23 <= 302500 ) V_24 = 0x04 ; else
if ( V_23 <= 357500 ) V_24 = 0x05 ; else
if ( V_23 <= 412500 ) V_24 = 0x06 ; else
if ( V_23 <= 467500 ) V_24 = 0x07 ; else
if ( V_23 <= 522500 ) V_24 = 0x08 ; else
if ( V_23 <= 577500 ) V_24 = 0x09 ; else
if ( V_23 <= 632500 ) V_24 = 0x0A ; else
if ( V_23 <= 687500 ) V_24 = 0x0B ; else
if ( V_23 <= 742500 ) V_24 = 0x0C ; else
if ( V_23 <= 797500 ) V_24 = 0x0D ; else
if ( V_23 <= 852500 ) V_24 = 0x0E ; else
if ( V_23 <= 907500 ) V_24 = 0x0F ; else
if ( V_23 <= 962500 ) V_24 = 0x10 ; else
if ( V_23 <= 1017500 ) V_24 = 0x11 ; else
if ( V_23 <= 1072500 ) V_24 = 0x12 ; else V_24 = 0x13 ;
V_31 [ 0 ] = 1 ;
V_31 [ 1 ] = ( V_28 >> 5 ) & 0xFF ;
V_31 [ 2 ] = ( V_28 & 0x1F ) ;
V_31 [ 3 ] = V_27 ;
V_31 [ 4 ] = ( V_30 >> 5 ) & 0xFF ;
V_31 [ 5 ] = V_30 & 0x1F ;
V_31 [ 6 ] = V_29 ;
F_7 ( 1 , L_5 , V_42 , V_43 ) ;
F_7 ( 1 , L_6 , ( int ) V_23 , ( int ) V_24 ) ;
F_7 ( 1 , L_7 , ( int ) V_25 , ( int ) V_26 ) ;
F_7 ( 1 , L_8 ,
( int ) V_27 , ( int ) V_28 , ( int ) V_29 , ( int ) V_30 ) ;
F_7 ( 1 , L_9 ,
( int ) V_31 [ 1 ] , ( int ) V_31 [ 2 ] , ( int ) V_31 [ 3 ] , ( int ) V_31 [ 4 ] , ( int ) V_31 [ 5 ] ,
( int ) V_31 [ 6 ] ) ;
V_21 = F_5 ( V_2 , V_31 , 7 ) ;
if ( V_21 < 0 )
return V_21 ;
F_4 ( V_2 , 0x0b , V_24 ) ;
V_22 = 0 ;
do {
F_1 ( V_2 , 0x08 , & V_32 ) ;
if ( ( V_32 & 0x88 ) == 0x88 )
break;
F_8 ( 4 ) ;
V_22 ++ ;
} while ( V_22 < 10 );
return V_21 ;
}
static int F_9 ( struct V_17 * V_18 , T_2 * V_40 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
F_7 ( 1 , L_10 , V_41 ) ;
* V_40 = V_2 -> V_40 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 , T_2 * V_37 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
F_7 ( 1 , L_10 , V_41 ) ;
* V_37 = V_2 -> V_37 ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , T_2 * V_45 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
T_1 V_46 = 0 ;
T_1 V_47 = 0 ;
* V_45 = 0 ;
F_1 ( V_2 , 0x08 , & V_46 ) ;
if ( ( V_46 & 0x88 ) == 0x88 )
* V_45 = V_48 ;
F_1 ( V_2 , 0x09 , & V_47 ) ;
F_7 ( 1 , L_11 ,
V_41 , V_46 , V_47 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
int V_21 ;
F_7 ( 1 , L_10 , V_41 ) ;
if ( ( V_21 = F_5 ( V_2 , V_49 ,
sizeof( V_49 ) ) ) < 0 )
return V_21 ;
F_4 ( V_2 , 0x0b , 0x09 ) ;
F_4 ( V_2 , 0x15 , 0x47 ) ;
F_4 ( V_2 , 0x07 , 0xf2 ) ;
F_4 ( V_2 , 0x0b , 0x01 ) ;
if ( ( V_21 = F_5 ( V_2 , V_50 ,
sizeof( V_50 ) ) ) < 0 )
return V_21 ;
return V_21 ;
}
static int F_13 ( struct V_17 * V_18 )
{
F_7 ( 1 , L_10 , V_41 ) ;
F_14 ( V_18 -> V_33 ) ;
V_18 -> V_33 = NULL ;
return 0 ;
}
struct V_17 * F_15 ( struct V_17 * V_18 ,
struct V_51 * V_14 ,
struct V_52 * V_8 , T_3 V_53 )
{
struct V_1 * V_2 = NULL ;
T_1 V_54 = 0 ;
F_7 ( 1 , L_10 , V_41 ) ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_55 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_37 = 6000000 ;
V_2 -> V_14 = V_14 ;
if ( F_1 ( V_2 , 0 , & V_54 ) != 0 ) {
F_14 ( V_2 ) ;
return NULL ;
}
if ( ( V_54 != 0x3E ) && ( V_54 != 0x3F ) ) {
F_3 ( V_56 L_12 ,
V_8 -> V_9 ) ;
F_14 ( V_2 ) ;
return NULL ;
}
F_3 ( V_57 L_13 ,
V_8 -> V_9 ) ;
memcpy ( & V_18 -> V_34 . V_58 , & V_59 ,
sizeof( struct V_60 ) ) ;
V_18 -> V_33 = V_2 ;
return V_18 ;
}
