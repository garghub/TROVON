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
static int F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 ;
struct V_1 * V_2 ;
int V_22 = 0 , V_23 ;
T_2 V_24 ;
T_1 V_25 ;
T_2 V_26 , V_27 ;
T_2 V_28 , V_29 , V_30 , V_31 ;
T_1 V_32 [ 8 ] ;
T_1 V_33 = 0 ;
V_2 = V_18 -> V_34 ;
V_24 = V_20 -> V_35 / 1000 ;
F_7 ( 1 , L_4 , V_36 , V_24 ) ;
V_26 = V_24 + V_37 * 1000 ;
V_26 = ( V_26 / 250 ) * 250 ;
V_27 = V_26 - V_24 - V_38 ;
V_2 -> V_35 = ( V_26 - V_27 - V_38 ) * 1000 ;
V_29 = V_26 * 64 / ( V_39 / 128 ) ;
V_28 = V_29 / 8192 ;
V_29 &= 0x1fff ;
V_31 = V_27 * 64 / ( V_39 / 128 ) ;
V_30 = V_31 / 8192 ;
V_31 &= 0x1fff ;
if ( V_24 <= 82500 ) V_25 = 0x00 ; else
if ( V_24 <= 137500 ) V_25 = 0x01 ; else
if ( V_24 <= 192500 ) V_25 = 0x02 ; else
if ( V_24 <= 247500 ) V_25 = 0x03 ; else
if ( V_24 <= 302500 ) V_25 = 0x04 ; else
if ( V_24 <= 357500 ) V_25 = 0x05 ; else
if ( V_24 <= 412500 ) V_25 = 0x06 ; else
if ( V_24 <= 467500 ) V_25 = 0x07 ; else
if ( V_24 <= 522500 ) V_25 = 0x08 ; else
if ( V_24 <= 577500 ) V_25 = 0x09 ; else
if ( V_24 <= 632500 ) V_25 = 0x0A ; else
if ( V_24 <= 687500 ) V_25 = 0x0B ; else
if ( V_24 <= 742500 ) V_25 = 0x0C ; else
if ( V_24 <= 797500 ) V_25 = 0x0D ; else
if ( V_24 <= 852500 ) V_25 = 0x0E ; else
if ( V_24 <= 907500 ) V_25 = 0x0F ; else
if ( V_24 <= 962500 ) V_25 = 0x10 ; else
if ( V_24 <= 1017500 ) V_25 = 0x11 ; else
if ( V_24 <= 1072500 ) V_25 = 0x12 ; else V_25 = 0x13 ;
V_32 [ 0 ] = 1 ;
V_32 [ 1 ] = ( V_29 >> 5 ) & 0xFF ;
V_32 [ 2 ] = ( V_29 & 0x1F ) ;
V_32 [ 3 ] = V_28 ;
V_32 [ 4 ] = ( V_31 >> 5 ) & 0xFF ;
V_32 [ 5 ] = V_31 & 0x1F ;
V_32 [ 6 ] = V_30 ;
F_7 ( 1 , L_5 , V_37 , V_38 ) ;
F_7 ( 1 , L_6 , ( int ) V_24 , ( int ) V_25 ) ;
F_7 ( 1 , L_7 , ( int ) V_26 , ( int ) V_27 ) ;
F_7 ( 1 , L_8 ,
( int ) V_28 , ( int ) V_29 , ( int ) V_30 , ( int ) V_31 ) ;
F_7 ( 1 , L_9 ,
( int ) V_32 [ 1 ] , ( int ) V_32 [ 2 ] , ( int ) V_32 [ 3 ] , ( int ) V_32 [ 4 ] , ( int ) V_32 [ 5 ] ,
( int ) V_32 [ 6 ] ) ;
V_22 = F_5 ( V_2 , V_32 , 7 ) ;
if ( V_22 < 0 )
return V_22 ;
F_4 ( V_2 , 0x0b , V_25 ) ;
V_23 = 0 ;
do {
F_1 ( V_2 , 0x08 , & V_33 ) ;
if ( ( V_33 & 0x88 ) == 0x88 )
break;
F_8 ( 4 ) ;
V_23 ++ ;
} while ( V_23 < 10 );
return V_22 ;
}
static int F_9 ( struct V_17 * V_18 , T_2 * V_35 )
{
struct V_1 * V_2 = V_18 -> V_34 ;
F_7 ( 1 , L_10 , V_36 ) ;
* V_35 = V_2 -> V_35 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 , T_2 * V_40 )
{
struct V_1 * V_2 = V_18 -> V_34 ;
T_1 V_41 = 0 ;
T_1 V_42 = 0 ;
* V_40 = 0 ;
F_1 ( V_2 , 0x08 , & V_41 ) ;
if ( ( V_41 & 0x88 ) == 0x88 )
* V_40 = V_43 ;
F_1 ( V_2 , 0x09 , & V_42 ) ;
F_7 ( 1 , L_11 ,
V_36 , V_41 , V_42 ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_34 ;
int V_22 ;
F_7 ( 1 , L_10 , V_36 ) ;
if ( ( V_22 = F_5 ( V_2 , V_44 ,
sizeof( V_44 ) ) ) < 0 )
return V_22 ;
F_4 ( V_2 , 0x0b , 0x09 ) ;
F_4 ( V_2 , 0x15 , 0x47 ) ;
F_4 ( V_2 , 0x07 , 0xf2 ) ;
F_4 ( V_2 , 0x0b , 0x01 ) ;
if ( ( V_22 = F_5 ( V_2 , V_45 ,
sizeof( V_45 ) ) ) < 0 )
return V_22 ;
return V_22 ;
}
static void F_12 ( struct V_17 * V_18 )
{
F_7 ( 1 , L_10 , V_36 ) ;
F_13 ( V_18 -> V_34 ) ;
V_18 -> V_34 = NULL ;
}
struct V_17 * F_14 ( struct V_17 * V_18 ,
struct V_46 * V_14 ,
struct V_47 * V_8 , T_3 V_48 )
{
struct V_1 * V_2 = NULL ;
T_1 V_49 = 0 ;
F_7 ( 1 , L_10 , V_36 ) ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_50 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = V_14 ;
if ( F_1 ( V_2 , 0 , & V_49 ) != 0 ) {
F_13 ( V_2 ) ;
return NULL ;
}
if ( ( V_49 != 0x3E ) && ( V_49 != 0x3F ) ) {
F_3 ( V_51 L_12 ,
V_8 -> V_9 ) ;
F_13 ( V_2 ) ;
return NULL ;
}
F_3 ( V_52 L_13 ,
V_8 -> V_9 ) ;
memcpy ( & V_18 -> V_53 . V_54 , & V_55 ,
sizeof( struct V_56 ) ) ;
V_18 -> V_34 = V_2 ;
return V_18 ;
}
