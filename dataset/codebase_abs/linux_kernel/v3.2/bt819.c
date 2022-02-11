static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_1 * V_8 , T_1 V_9 , T_1 V_10 )
{
struct V_11 * V_12 = F_5 ( & V_8 -> V_3 ) ;
V_8 -> V_9 [ V_9 ] = V_10 ;
return F_6 ( V_12 , V_9 , V_10 ) ;
}
static inline int F_7 ( struct V_1 * V_8 , T_1 V_9 , T_1 V_13 , T_1 V_10 )
{
return F_4 ( V_8 , V_9 ,
( V_8 -> V_9 [ V_9 ] & ~ ( 1 << V_13 ) ) | ( V_10 ? ( 1 << V_13 ) : 0 ) ) ;
}
static int F_8 ( struct V_1 * V_8 , const T_1 * V_14 , unsigned int V_15 )
{
struct V_11 * V_12 = F_5 ( & V_8 -> V_3 ) ;
int V_16 = - 1 ;
T_1 V_9 ;
if ( F_9 ( V_12 -> V_17 , V_18 ) ) {
T_1 V_19 [ 32 ] ;
int V_20 ;
while ( V_15 >= 2 ) {
V_20 = 0 ;
V_19 [ V_20 ++ ] = V_9 = V_14 [ 0 ] ;
do {
V_19 [ V_20 ++ ] =
V_8 -> V_9 [ V_9 ++ ] = V_14 [ 1 ] ;
V_15 -= 2 ;
V_14 += 2 ;
} while ( V_15 >= 2 && V_14 [ 0 ] == V_9 && V_20 < 32 );
V_16 = F_10 ( V_12 , V_19 , V_20 ) ;
if ( V_16 < 0 )
break;
}
} else {
while ( V_15 >= 2 ) {
V_9 = * V_14 ++ ;
V_16 = F_4 ( V_8 , V_9 , * V_14 ++ ) ;
if ( V_16 < 0 )
break;
V_15 -= 2 ;
}
}
return V_16 ;
}
static inline int F_11 ( struct V_1 * V_8 , T_1 V_9 )
{
struct V_11 * V_12 = F_5 ( & V_8 -> V_3 ) ;
return F_12 ( V_12 , V_9 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
static unsigned char V_21 [] = {
0x01 , 0x59 ,
0x02 , 0x00 ,
0x03 , 0x12 ,
0x04 , 0x16 ,
0x05 , 0xe0 ,
0x06 , 0x80 ,
0x07 , 0xd0 ,
0x08 , 0x00 ,
0x09 , 0xf8 ,
0x0a , 0x00 ,
0x0b , 0x30 ,
0x0c , 0xd8 ,
0x0d , 0xfe ,
0x0e , 0xb4 ,
0x0f , 0x00 ,
0x12 , 0x04 ,
0x13 , 0x20 ,
0x14 , 0x00 ,
0x16 , 0x07 ,
0x18 , 0x68 ,
0x19 , 0x5d ,
0x1a , 0x80 ,
} ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_22 * V_22 = & V_23 [ ( V_8 -> V_24 & V_25 ) ? 1 : 0 ] ;
V_21 [ 0x03 * 2 - 1 ] =
( ( ( V_22 -> V_26 >> 8 ) & 0x03 ) << 6 ) |
( ( ( V_22 -> V_27 >> 8 ) & 0x03 ) << 4 ) |
( ( ( V_22 -> V_28 >> 8 ) & 0x03 ) << 2 ) |
( ( V_22 -> V_29 >> 8 ) & 0x03 ) ;
V_21 [ 0x04 * 2 - 1 ] = V_22 -> V_26 & 0xff ;
V_21 [ 0x05 * 2 - 1 ] = V_22 -> V_27 & 0xff ;
V_21 [ 0x06 * 2 - 1 ] = V_22 -> V_28 & 0xff ;
V_21 [ 0x07 * 2 - 1 ] = V_22 -> V_29 & 0xff ;
V_21 [ 0x08 * 2 - 1 ] = V_22 -> V_30 >> 8 ;
V_21 [ 0x09 * 2 - 1 ] = V_22 -> V_30 & 0xff ;
V_21 [ 0x15 * 2 - 1 ] = ( V_8 -> V_24 & V_31 ) ? 115 : 93 ;
F_4 ( V_8 , 0x1f , 0x00 ) ;
F_14 ( 1 ) ;
return F_8 ( V_8 , V_21 , sizeof( V_21 ) ) ;
}
static int F_15 ( struct V_2 * V_3 , T_2 * V_32 , T_3 * V_33 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_34 = F_11 ( V_8 , 0x00 ) ;
int V_35 = V_36 ;
T_3 V_37 ;
if ( ( V_34 & 0x80 ) )
V_35 = 0 ;
if ( ( V_34 & 0x10 ) )
V_37 = V_38 ;
else
V_37 = V_39 ;
if ( V_33 )
* V_33 = V_37 ;
if ( V_32 )
* V_32 = V_35 ;
F_16 ( 1 , V_40 , V_3 , L_1 , V_34 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , T_3 * V_37 )
{
return F_15 ( V_3 , NULL , V_37 ) ;
}
static int F_18 ( struct V_2 * V_3 , T_2 * V_34 )
{
return F_15 ( V_3 , V_34 , NULL ) ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_37 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_22 * V_22 = NULL ;
F_16 ( 1 , V_40 , V_3 , L_2 , ( unsigned long long ) V_37 ) ;
if ( V_3 -> V_41 == NULL || V_3 -> V_41 -> V_42 == NULL )
F_20 ( V_3 , L_3 ) ;
if ( V_37 & V_39 ) {
F_21 ( V_3 , V_43 , NULL ) ;
F_7 ( V_8 , 0x01 , 0 , 1 ) ;
F_7 ( V_8 , 0x01 , 1 , 0 ) ;
F_7 ( V_8 , 0x01 , 5 , 0 ) ;
F_4 ( V_8 , 0x18 , 0x68 ) ;
F_4 ( V_8 , 0x19 , 0x5d ) ;
V_22 = & V_23 [ 1 ] ;
} else if ( V_37 & V_38 ) {
F_21 ( V_3 , V_43 , NULL ) ;
F_7 ( V_8 , 0x01 , 0 , 1 ) ;
F_7 ( V_8 , 0x01 , 1 , 1 ) ;
F_7 ( V_8 , 0x01 , 5 , 1 ) ;
F_4 ( V_8 , 0x18 , 0x7f ) ;
F_4 ( V_8 , 0x19 , 0x72 ) ;
V_22 = & V_23 [ 0 ] ;
} else {
F_16 ( 1 , V_40 , V_3 , L_4 ,
( unsigned long long ) V_37 ) ;
return - V_44 ;
}
F_4 ( V_8 , 0x03 ,
( ( ( V_22 -> V_26 >> 8 ) & 0x03 ) << 6 ) |
( ( ( V_22 -> V_27 >> 8 ) & 0x03 ) << 4 ) |
( ( ( V_22 -> V_28 >> 8 ) & 0x03 ) << 2 ) |
( ( V_22 -> V_29 >> 8 ) & 0x03 ) ) ;
F_4 ( V_8 , 0x04 , V_22 -> V_26 & 0xff ) ;
F_4 ( V_8 , 0x05 , V_22 -> V_27 & 0xff ) ;
F_4 ( V_8 , 0x06 , V_22 -> V_28 & 0xff ) ;
F_4 ( V_8 , 0x07 , V_22 -> V_29 & 0xff ) ;
F_4 ( V_8 , 0x08 , ( V_22 -> V_30 >> 8 ) & 0xff ) ;
F_4 ( V_8 , 0x09 , V_22 -> V_30 & 0xff ) ;
V_8 -> V_24 = V_37 ;
F_21 ( V_3 , V_45 , NULL ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
T_2 V_46 , T_2 V_47 , T_2 V_48 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_16 ( 1 , V_40 , V_3 , L_5 , V_46 ) ;
if ( V_46 > 7 )
return - V_44 ;
if ( V_3 -> V_41 == NULL || V_3 -> V_41 -> V_42 == NULL )
F_20 ( V_3 , L_3 ) ;
if ( V_8 -> V_46 != V_46 ) {
F_21 ( V_3 , V_43 , NULL ) ;
V_8 -> V_46 = V_46 ;
if ( V_8 -> V_46 == 0 ) {
F_7 ( V_8 , 0x0b , 6 , 0 ) ;
F_7 ( V_8 , 0x1a , 1 , 1 ) ;
} else {
F_7 ( V_8 , 0x0b , 6 , 1 ) ;
F_7 ( V_8 , 0x1a , 1 , 0 ) ;
}
F_21 ( V_3 , V_45 , NULL ) ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_49 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_16 ( 1 , V_40 , V_3 , L_6 , V_49 ) ;
if ( V_8 -> V_49 != V_49 ) {
V_8 -> V_49 = V_49 ;
F_7 ( V_8 , 0x16 , 7 , ! V_49 ) ;
}
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_50 ;
switch ( V_5 -> V_51 ) {
case V_52 :
F_4 ( V_8 , 0x0a , V_5 -> V_53 ) ;
break;
case V_54 :
F_4 ( V_8 , 0x0c , V_5 -> V_53 & 0xff ) ;
F_7 ( V_8 , 0x0b , 2 , ( ( V_5 -> V_53 >> 8 ) & 0x01 ) ) ;
break;
case V_55 :
F_4 ( V_8 , 0x0d , ( V_5 -> V_53 >> 7 ) & 0xff ) ;
F_7 ( V_8 , 0x0b , 1 , ( ( V_5 -> V_53 >> 15 ) & 0x01 ) ) ;
V_50 = ( V_5 -> V_53 * 180 ) / 254 ;
F_4 ( V_8 , 0x0e , ( V_50 >> 7 ) & 0xff ) ;
F_7 ( V_8 , 0x0b , 0 , ( V_50 >> 15 ) & 0x01 ) ;
break;
case V_56 :
F_4 ( V_8 , 0x0f , V_5 -> V_53 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
return F_26 ( V_12 , V_58 , V_8 -> V_59 , 0 ) ;
}
static int F_27 ( struct V_11 * V_12 ,
const struct V_60 * V_51 )
{
int V_61 , V_62 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
const char * V_63 ;
if ( ! F_9 ( V_12 -> V_17 , V_64 ) )
return - V_65 ;
V_8 = F_28 ( sizeof( struct V_1 ) , V_66 ) ;
if ( V_8 == NULL )
return - V_67 ;
V_3 = & V_8 -> V_3 ;
F_29 ( V_3 , V_12 , & V_68 ) ;
V_62 = F_11 ( V_8 , 0x17 ) ;
switch ( V_62 & 0xf0 ) {
case 0x70 :
V_63 = L_7 ;
V_8 -> V_59 = V_69 ;
break;
case 0x60 :
V_63 = L_8 ;
V_8 -> V_59 = V_70 ;
break;
case 0x20 :
V_63 = L_9 ;
V_8 -> V_59 = V_71 ;
break;
default:
F_16 ( 1 , V_40 , V_3 ,
L_10 , V_62 ) ;
return - V_65 ;
}
F_30 ( V_12 , L_11 , V_63 ,
V_12 -> V_72 << 1 , V_12 -> V_17 -> V_63 ) ;
V_8 -> V_24 = V_39 ;
V_8 -> V_46 = 0 ;
V_8 -> V_49 = 1 ;
V_61 = F_13 ( V_3 ) ;
if ( V_61 < 0 )
F_16 ( 1 , V_40 , V_3 , L_12 , V_61 ) ;
F_31 ( & V_8 -> V_7 , 4 ) ;
F_32 ( & V_8 -> V_7 , & V_73 ,
V_52 , - 128 , 127 , 1 , 0 ) ;
F_32 ( & V_8 -> V_7 , & V_73 ,
V_54 , 0 , 511 , 1 , 0xd8 ) ;
F_32 ( & V_8 -> V_7 , & V_73 ,
V_55 , 0 , 511 , 1 , 0xfe ) ;
F_32 ( & V_8 -> V_7 , & V_73 ,
V_56 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_74 = & V_8 -> V_7 ;
if ( V_8 -> V_7 . error ) {
int V_75 = V_8 -> V_7 . error ;
F_33 ( & V_8 -> V_7 ) ;
F_34 ( V_8 ) ;
return V_75 ;
}
F_35 ( & V_8 -> V_7 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_37 ( V_12 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_38 ( V_3 ) ;
F_33 ( & V_8 -> V_7 ) ;
F_34 ( V_8 ) ;
return 0 ;
}
static T_4 int F_39 ( void )
{
return F_40 ( & V_76 ) ;
}
static T_5 void F_41 ( void )
{
F_42 ( & V_76 ) ;
}
