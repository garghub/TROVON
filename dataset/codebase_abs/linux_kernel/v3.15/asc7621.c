static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 ,
L_1 , V_3 ) ;
return 0 ;
}
return V_4 & 0xff ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
int V_4 = F_5 ( V_2 , V_3 , V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 ,
L_2 ,
V_6 , V_3 ) ;
}
return V_4 ;
}
static T_2 F_6 ( struct V_7 * V_5 , struct V_8 * V_9 ,
char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
return sprintf ( V_10 , L_3 , V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] ) ;
}
static T_2 F_8 ( struct V_7 * V_5 , struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
V_14 = F_11 ( V_14 , 0 , 255 ) ;
F_12 ( & V_6 -> V_16 ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_14 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_14 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_14 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
return sprintf ( V_10 , L_3 ,
( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 ->
V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ) ;
}
static T_2 F_15 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
T_1 V_19 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
V_14 = F_11 ( V_14 , 0 , V_11 -> V_18 [ 0 ] ) ;
V_14 = ( V_14 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
F_12 ( & V_6 -> V_16 ) ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_14 |= ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_14 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_14 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_16 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_4 V_20 ;
F_12 ( & V_6 -> V_16 ) ;
V_20 = ( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] << 8 ) | V_6 -> V_3 [ V_11 -> V_21 [ 0 ] ] ;
F_13 ( & V_6 -> V_16 ) ;
return sprintf ( V_10 , L_3 ,
( V_20 == 0 ? - 1 : ( V_20 ) ==
0xffff ? 0 : 5400000 / V_20 ) ) ;
}
static T_2 F_17 ( struct V_7 * V_5 ,
struct V_8 * V_9 , const char * V_10 ,
T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
V_14 =
( V_14 <= 0 ? 0xffff : F_11 ( 5400000 / V_14 , 0 , 0xfffe ) ) ;
F_12 ( & V_6 -> V_16 ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = ( V_14 >> 8 ) & 0xff ;
V_6 -> V_3 [ V_11 -> V_21 [ 0 ] ] = V_14 & 0xff ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] ) ;
F_4 ( V_2 , V_11 -> V_21 [ 0 ] , V_6 -> V_3 [ V_11 -> V_21 [ 0 ] ] ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_18 ( struct V_7 * V_5 , struct V_8 * V_9 ,
char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_4 V_20 ;
T_1 V_22 = V_23 -> V_24 ;
F_12 ( & V_6 -> V_16 ) ;
V_20 = ( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] << 8 ) | ( V_6 -> V_3 [ V_11 -> V_21 [ 0 ] ] ) ;
F_13 ( & V_6 -> V_16 ) ;
V_20 = ( V_20 >> 6 ) * V_25 [ V_22 ] / ( 0xc0 << 2 ) ;
return sprintf ( V_10 , L_3 , V_20 ) ;
}
static T_2 F_19 ( struct V_7 * V_5 , struct V_8 * V_9 ,
char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_22 = V_23 -> V_24 ;
return sprintf ( V_10 , L_3 ,
( ( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] *
V_25 [ V_22 ] ) / 0xc0 ) ) ;
}
static T_2 F_20 ( struct V_7 * V_5 , struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
T_1 V_22 = V_23 -> V_24 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
V_14 = F_11 ( V_14 , 0 , 0xffff ) ;
V_14 = V_14 * 0xc0 / V_25 [ V_22 ] ;
V_14 = F_11 ( V_14 , 0 , 0xff ) ;
F_12 ( & V_6 -> V_16 ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_14 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_14 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_21 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
return sprintf ( V_10 , L_4 , ( ( V_26 ) V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] ) * 1000 ) ;
}
static T_2 F_22 ( struct V_7 * V_5 ,
struct V_8 * V_9 , const char * V_10 ,
T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
V_26 V_27 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
V_14 = F_11 ( V_14 , - 127000 , 127000 ) ;
V_27 = V_14 / 1000 ;
F_12 ( & V_6 -> V_16 ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_27 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_27 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_23 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_12 , V_21 ;
int V_27 ;
F_12 ( & V_6 -> V_16 ) ;
V_12 = V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] ;
V_21 = ( V_6 -> V_3 [ V_11 -> V_21 [ 0 ] ] >> 6 ) & 0x03 ;
V_27 = ( ( ( V_26 ) V_12 ) * 1000 ) + ( V_21 * 250 ) ;
F_13 ( & V_6 -> V_16 ) ;
return sprintf ( V_10 , L_4 , V_27 ) ;
}
static T_2 F_24 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_20 = V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] ;
int V_27 = ( ( V_26 ) ( V_20 & 0xfc ) * 1000 ) + ( ( V_20 & 0x03 ) * 250 ) ;
return sprintf ( V_10 , L_4 , V_27 ) ;
}
static T_2 F_25 ( struct V_7 * V_5 ,
struct V_8 * V_9 , const char * V_10 ,
T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 , V_28 , V_29 ;
V_26 V_27 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
V_14 = F_11 ( V_14 , - 32000 , 31750 ) ;
V_28 = V_14 / 1000 ;
V_29 = V_14 - ( V_28 * 1000 ) ;
V_27 = V_28 << 2 ;
V_27 |= V_29 / 250 ;
F_12 ( & V_6 -> V_16 ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_27 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_27 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_26 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
long V_30 ;
T_1 V_20 ;
int V_27 ;
F_12 ( & V_6 -> V_16 ) ;
V_30 = ( ( V_26 ) V_6 -> V_3 [ V_11 -> V_12 [ 1 ] ] ) * 1000 ;
V_20 =
( ( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 -> V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ) ;
V_27 = V_30 + V_31 [ F_11 ( V_20 , 0 , 15 ) ] ;
F_13 ( & V_6 -> V_16 ) ;
return sprintf ( V_10 , L_4 , V_27 ) ;
}
static T_2 F_27 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 , V_30 ;
int V_28 ;
T_1 V_19 , V_32 = 0 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
F_12 ( & V_6 -> V_16 ) ;
V_30 = V_6 -> V_3 [ V_11 -> V_12 [ 1 ] ] * 1000 ;
V_14 = F_11 ( V_14 , V_30 + 2000 , V_30 + 80000 ) ;
for ( V_28 = F_28 ( V_31 ) - 1 ; V_28 >= 0 ; V_28 -- ) {
if ( V_14 >= V_30 + V_31 [ V_28 ] ) {
V_32 = V_28 ;
break;
}
}
V_32 = ( V_32 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_32 |= ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_32 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_29 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_33 , V_34 , V_20 ;
T_1 V_35 [] = {
0x01 , 0x02 , 0x04 , 0x1f , 0x00 , 0x06 , 0x07 , 0x10 ,
0x08 , 0x0f , 0x1f , 0x1f , 0x1f , 0x1f , 0x1f , 0x1f
} ;
F_12 ( & V_6 -> V_16 ) ;
V_33 = ( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 -> V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ;
V_34 = ( V_6 -> V_3 [ V_11 -> V_12 [ 1 ] ] >> V_11 -> V_17 [ 1 ] ) & V_11 -> V_18 [ 1 ] ;
V_20 = V_33 | ( V_34 << 3 ) ;
F_13 ( & V_6 -> V_16 ) ;
return sprintf ( V_10 , L_3 , V_35 [ F_11 ( V_20 , 0 , 15 ) ] ) ;
}
static T_2 F_30 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
unsigned long V_14 ;
T_1 V_19 , V_33 , V_34 , V_32 ;
T_4 V_35 [] = {
0x04 , 0x00 , 0x01 , 0xff , 0x02 , 0xff , 0x05 , 0x06 ,
0x08 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x0f ,
0x07 , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0x03 ,
} ;
if ( F_31 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
if ( V_14 > 31 )
return - V_15 ;
V_14 = V_35 [ V_14 ] ;
if ( V_14 == 0xff )
return - V_15 ;
V_33 = V_14 & 0x07 ;
V_34 = ( V_14 >> 3 ) & 0x01 ;
V_33 = ( V_33 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
V_34 = ( V_34 & V_11 -> V_18 [ 1 ] ) << V_11 -> V_17 [ 1 ] ;
F_12 ( & V_6 -> V_16 ) ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_32 = V_33 | ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_32 = V_34 | ( V_32 & ~ ( V_11 -> V_18 [ 1 ] << V_11 -> V_17 [ 1 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_32 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_32 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_33 , V_34 , V_36 , V_37 , V_32 ;
F_12 ( & V_6 -> V_16 ) ;
V_33 = ( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 -> V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ;
V_34 = ( V_6 -> V_3 [ V_11 -> V_12 [ 1 ] ] >> V_11 -> V_17 [ 1 ] ) & V_11 -> V_18 [ 1 ] ;
V_36 = ( V_6 -> V_3 [ V_11 -> V_12 [ 2 ] ] >> V_11 -> V_17 [ 2 ] ) & V_11 -> V_18 [ 2 ] ;
F_13 ( & V_6 -> V_16 ) ;
V_37 = V_33 | ( V_34 << 3 ) ;
V_32 = 0 ;
if ( V_37 == 3 || V_37 >= 10 )
V_32 = 255 ;
else if ( V_37 == 4 )
V_32 = 0 ;
else if ( V_37 == 7 )
V_32 = 1 ;
else if ( V_36 == 1 )
V_32 = 2 ;
else
V_32 = 3 ;
return sprintf ( V_10 , L_3 , V_32 ) ;
}
static T_2 F_33 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
T_1 V_19 , V_33 , V_34 , V_32 , V_36 = 255 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
switch ( V_14 ) {
case 0 :
V_32 = 0x04 ;
break;
case 1 :
V_32 = 0x07 ;
break;
case 2 :
V_32 = 0x00 ;
V_36 = 1 ;
break;
case 3 :
V_32 = 0x00 ;
V_36 = 0 ;
break;
case 255 :
V_32 = 0x03 ;
break;
default:
return - V_15 ;
}
V_33 = V_32 & 0x07 ;
V_34 = ( V_32 >> 3 ) & 0x01 ;
F_12 ( & V_6 -> V_16 ) ;
V_33 = ( V_33 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
V_34 = ( V_34 & V_11 -> V_18 [ 1 ] ) << V_11 -> V_17 [ 1 ] ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_32 = V_33 | ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_32 = V_34 | ( V_32 & ~ ( V_11 -> V_18 [ 1 ] << V_11 -> V_17 [ 1 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_32 ) ;
if ( V_36 < 255 ) {
V_36 = ( V_36 & V_11 -> V_18 [ 2 ] ) << V_11 -> V_17 [ 2 ] ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 2 ] ) ;
V_32 =
V_36 | ( V_19 & ~ ( V_11 -> V_18 [ 2 ] << V_11 -> V_17 [ 2 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 2 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 2 ] , V_32 ) ;
}
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_34 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_20 =
( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 -> V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ;
V_20 = F_11 ( V_20 , 0 , 15 ) ;
return sprintf ( V_10 , L_3 , V_38 [ V_20 ] ) ;
}
static T_2 F_35 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
unsigned long V_14 ;
T_1 V_19 , V_32 = 255 ;
int V_28 ;
if ( F_31 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
for ( V_28 = 0 ; V_28 < F_28 ( V_38 ) ; V_28 ++ ) {
if ( V_14 == V_38 [ V_28 ] ) {
V_32 = V_28 ;
break;
}
}
if ( V_32 == 255 )
return - V_15 ;
V_32 = ( V_32 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
F_12 ( & V_6 -> V_16 ) ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_32 |= ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_32 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_36 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_20 =
( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 -> V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ;
V_20 = F_11 ( V_20 , 0 , 7 ) ;
return sprintf ( V_10 , L_3 , V_39 [ V_20 ] ) ;
}
static T_2 F_37 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
T_1 V_19 , V_32 = 255 ;
T_5 V_28 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
for ( V_28 = 0 ; V_28 < F_28 ( V_39 ) ; V_28 ++ ) {
if ( V_14 == V_39 [ V_28 ] ) {
V_32 = V_28 ;
break;
}
}
if ( V_32 == 255 )
return - V_15 ;
V_32 = ( V_32 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
F_12 ( & V_6 -> V_16 ) ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_32 |= ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_32 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static T_2 F_38 ( struct V_7 * V_5 ,
struct V_8 * V_9 , char * V_10 )
{
F_7 ( V_5 , V_9 ) ;
T_1 V_20 =
( V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] >> V_11 -> V_17 [ 0 ] ) & V_11 -> V_18 [ 0 ] ;
V_20 = F_11 ( V_20 , 0 , 7 ) ;
return sprintf ( V_10 , L_3 , V_40 [ V_20 ] ) ;
}
static T_2 F_39 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_13 )
{
F_9 ( V_5 , V_9 ) ;
long V_14 ;
T_1 V_19 , V_32 = 255 ;
T_5 V_28 ;
if ( F_10 ( V_10 , 10 , & V_14 ) )
return - V_15 ;
for ( V_28 = 0 ; V_28 < F_28 ( V_40 ) ; V_28 ++ ) {
if ( V_14 == V_40 [ V_28 ] ) {
V_32 = V_28 ;
break;
}
}
if ( V_32 == 255 )
return - V_15 ;
V_32 = ( V_32 & V_11 -> V_18 [ 0 ] ) << V_11 -> V_17 [ 0 ] ;
F_12 ( & V_6 -> V_16 ) ;
V_19 = F_1 ( V_2 , V_11 -> V_12 [ 0 ] ) ;
V_32 |= ( V_19 & ~ ( V_11 -> V_18 [ 0 ] << V_11 -> V_17 [ 0 ] ) ) ;
V_6 -> V_3 [ V_11 -> V_12 [ 0 ] ] = V_32 ;
F_4 ( V_2 , V_11 -> V_12 [ 0 ] , V_32 ) ;
F_13 ( & V_6 -> V_16 ) ;
return V_13 ;
}
static struct V_41 * F_40 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_41 ( V_5 ) ;
struct V_41 * V_6 = F_42 ( V_2 ) ;
int V_28 ;
F_12 ( & V_6 -> V_16 ) ;
if ( ! V_6 -> V_42 ||
F_43 ( V_43 , V_6 -> V_44 + V_45 ) ) {
for ( V_28 = 0 ; V_28 < F_28 ( V_46 ) ; V_28 ++ ) {
if ( V_46 [ V_28 ] == V_47 ) {
V_6 -> V_3 [ V_28 ] =
F_2 ( V_2 , V_28 ) & 0xff ;
}
}
V_6 -> V_44 = V_43 ;
}
if ( ! V_6 -> V_42 ||
F_43 ( V_43 , V_6 -> V_48 + V_49 ) ) {
for ( V_28 = 0 ; V_28 < F_28 ( V_50 ) ; V_28 ++ ) {
if ( V_46 [ V_28 ] == V_51 ) {
V_6 -> V_3 [ V_28 ] =
F_2 ( V_2 , V_28 ) & 0xff ;
}
}
V_6 -> V_48 = V_43 ;
}
V_6 -> V_42 = 1 ;
F_13 ( & V_6 -> V_16 ) ;
return V_6 ;
}
static inline int F_44 ( int V_52 , int V_53 )
{
int V_28 ;
for ( V_28 = 0 ; V_54 [ V_52 ] . V_55 [ V_28 ] != V_56 ;
V_28 ++ ) {
if ( V_54 [ V_52 ] . V_55 [ V_28 ] == V_53 )
return 1 ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_1 ( V_2 , 0x40 ) ;
if ( V_57 & 0x02 ) {
F_3 ( & V_2 -> V_5 ,
L_5 ,
F_46 ( V_2 -> V_58 ) , V_2 -> V_59 ) ;
}
if ( ! ( V_57 & 0x04 ) ) {
F_3 ( & V_2 -> V_5 , L_6 ,
F_46 ( V_2 -> V_58 ) , V_2 -> V_59 ) ;
}
V_57 = ( V_57 & ~ 0x02 ) | 0x01 ;
F_4 ( V_2 , 0x40 , V_57 & 0xff ) ;
}
static int
F_47 ( struct V_1 * V_2 , const struct V_60 * V_61 )
{
struct V_41 * V_6 ;
int V_28 , V_62 ;
if ( ! F_48 ( V_2 -> V_58 , V_63 ) )
return - V_64 ;
V_6 = F_49 ( & V_2 -> V_5 , sizeof( struct V_41 ) ,
V_65 ) ;
if ( V_6 == NULL )
return - V_66 ;
F_50 ( V_2 , V_6 ) ;
F_51 ( & V_6 -> V_16 ) ;
F_45 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < F_28 ( V_50 ) ; V_28 ++ ) {
V_62 =
F_52 ( & V_2 -> V_5 ,
& ( V_50 [ V_28 ] . V_23 . V_67 ) ) ;
if ( V_62 )
goto V_68;
}
V_6 -> V_69 = F_53 ( & V_2 -> V_5 ) ;
if ( F_54 ( V_6 -> V_69 ) ) {
V_62 = F_55 ( V_6 -> V_69 ) ;
goto V_68;
}
return 0 ;
V_68:
for ( V_28 = 0 ; V_28 < F_28 ( V_50 ) ; V_28 ++ ) {
F_56 ( & V_2 -> V_5 ,
& ( V_50 [ V_28 ] . V_23 . V_67 ) ) ;
}
return V_62 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_72 * V_58 = V_2 -> V_58 ;
int V_73 , V_74 , V_75 ;
if ( ! F_48 ( V_58 , V_63 ) )
return - V_76 ;
for ( V_75 = V_77 ; V_75 <= V_78 ; V_75 ++ ) {
if ( ! F_44 ( V_75 , V_2 -> V_59 ) )
continue;
V_73 = F_1 ( V_2 ,
V_54 [ V_75 ] . V_79 ) ;
V_74 = F_1 ( V_2 ,
V_54 [ V_75 ] . V_80 ) ;
if ( V_73 == V_54 [ V_75 ] . V_81 &&
V_74 == V_54 [ V_75 ] . V_82 ) {
F_58 ( V_71 -> type , V_54 [ V_75 ] . V_83 ,
V_84 ) ;
F_59 ( & V_58 -> V_5 , L_7 ,
V_54 [ V_75 ] . V_83 , V_2 -> V_59 ) ;
return 0 ;
}
}
return - V_76 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_41 * V_6 = F_42 ( V_2 ) ;
int V_28 ;
F_61 ( V_6 -> V_69 ) ;
for ( V_28 = 0 ; V_28 < F_28 ( V_50 ) ; V_28 ++ ) {
F_56 ( & V_2 -> V_5 ,
& ( V_50 [ V_28 ] . V_23 . V_67 ) ) ;
}
return 0 ;
}
static int T_6 F_62 ( void )
{
int V_28 , V_85 ;
for ( V_28 = 0 ; V_28 < F_28 ( V_50 ) ; V_28 ++ ) {
for ( V_85 = 0 ; V_85 < F_28 ( V_50 [ V_28 ] . V_12 ) ; V_85 ++ )
V_46 [ V_50 [ V_28 ] . V_12 [ V_85 ] ] =
V_50 [ V_28 ] . V_86 ;
for ( V_85 = 0 ; V_85 < F_28 ( V_50 [ V_28 ] . V_21 ) ; V_85 ++ )
V_46 [ V_50 [ V_28 ] . V_21 [ V_85 ] ] =
V_50 [ V_28 ] . V_86 ;
}
return F_63 ( & V_87 ) ;
}
static void T_7 F_64 ( void )
{
F_65 ( & V_87 ) ;
}
