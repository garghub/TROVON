static T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
if ( ! V_7 ( V_2 , 'd' , & V_8 ) ) {
if ( V_8 . V_9 == 1 && V_8 . V_10 >= 2 ) {
T_1 V_11 = F_2 ( V_2 , V_8 . V_12 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0x00 ) ;
switch ( * V_3 ) {
case 0x21 :
case 0x30 :
case 0x40 :
* V_4 = F_3 ( V_2 , V_11 + 0x01 ) ;
* V_6 = F_3 ( V_2 , V_11 + 0x02 ) ;
* V_5 = F_3 ( V_2 , V_11 + 0x03 ) ;
return V_11 ;
default:
break;
}
}
}
}
return 0x0000 ;
}
static T_1
F_4 ( struct V_1 * V_2 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_1 V_11 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_11 && V_13 < * V_5 ) {
T_1 V_14 = F_2 ( V_2 , V_11 + * V_4 + V_13 * * V_6 ) ;
switch ( * V_3 * ! ! V_14 ) {
case 0x21 :
case 0x30 :
* V_4 = F_3 ( V_2 , V_11 + 0x04 ) ;
* V_6 = F_3 ( V_2 , V_11 + 0x05 ) ;
* V_5 = F_3 ( V_2 , V_14 + 0x04 ) ;
break;
case 0x40 :
* V_4 = F_3 ( V_2 , V_11 + 0x04 ) ;
* V_5 = 0 ;
* V_6 = 0 ;
break;
default:
break;
}
return V_14 ;
}
* V_3 = 0x00 ;
return 0x0000 ;
}
T_1
F_5 ( struct V_1 * V_2 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_15 * V_16 )
{
T_1 V_11 = F_4 ( V_2 , V_13 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_16 , 0x00 , sizeof( * V_16 ) ) ;
if ( V_11 && * V_3 ) {
V_16 -> type = F_2 ( V_2 , V_11 + 0x00 ) ;
V_16 -> V_17 = F_2 ( V_2 , V_11 + 0x02 ) ;
switch ( * V_3 ) {
case 0x21 :
case 0x30 :
V_16 -> V_18 = F_3 ( V_2 , V_11 + 0x05 ) ;
V_16 -> V_19 [ 0 ] = F_2 ( V_2 , V_11 + 0x06 ) ;
V_16 -> V_19 [ 1 ] = F_2 ( V_2 , V_11 + 0x08 ) ;
V_16 -> V_20 = F_2 ( V_2 , V_11 + 0x0a ) ;
if ( * V_6 >= 0x0f ) {
V_16 -> V_19 [ 2 ] = F_2 ( V_2 , V_11 + 0x0c ) ;
V_16 -> V_19 [ 3 ] = F_2 ( V_2 , V_11 + 0x0e ) ;
}
if ( * V_6 >= 0x11 )
V_16 -> V_19 [ 4 ] = F_2 ( V_2 , V_11 + 0x10 ) ;
break;
case 0x40 :
V_16 -> V_18 = F_3 ( V_2 , V_11 + 0x04 ) ;
V_16 -> V_19 [ 0 ] = F_2 ( V_2 , V_11 + 0x05 ) ;
V_16 -> V_19 [ 1 ] = F_2 ( V_2 , V_11 + 0x07 ) ;
V_16 -> V_20 = F_2 ( V_2 , V_11 + 0x09 ) ;
V_16 -> V_19 [ 2 ] = F_2 ( V_2 , V_11 + 0x0b ) ;
V_16 -> V_19 [ 3 ] = F_2 ( V_2 , V_11 + 0x0d ) ;
V_16 -> V_19 [ 4 ] = F_2 ( V_2 , V_11 + 0x0f ) ;
break;
default:
V_11 = 0x0000 ;
break;
}
}
return V_11 ;
}
T_1
F_6 ( struct V_1 * V_2 , T_1 type , T_1 V_17 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_15 * V_16 )
{
T_1 V_11 , V_13 = 0 ;
while ( ( V_11 = F_5 ( V_2 , V_13 ++ , V_3 , V_4 , V_5 , V_6 , V_16 ) ) || * V_3 ) {
if ( V_11 && V_16 -> type == type ) {
if ( ( V_16 -> V_17 & V_17 ) == V_17 )
break;
}
}
return V_11 ;
}
static T_1
F_7 ( struct V_1 * V_2 , T_1 V_14 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
if ( * V_3 >= 0x40 ) {
V_14 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
* V_4 = * V_4 + ( * V_6 * * V_5 ) ;
* V_6 = F_3 ( V_2 , V_14 + 0x06 ) ;
* V_5 = F_3 ( V_2 , V_14 + 0x07 ) ;
}
if ( V_13 < * V_5 )
return V_14 + * V_4 + ( V_13 * * V_6 ) ;
return 0x0000 ;
}
T_1
F_8 ( struct V_1 * V_2 , T_1 V_14 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_21 * V_16 )
{
T_1 V_11 = F_7 ( V_2 , V_14 , V_13 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_16 , 0x00 , sizeof( * V_16 ) ) ;
if ( V_11 ) {
switch ( * V_3 ) {
case 0x21 :
V_16 -> V_22 = F_3 ( V_2 , V_11 + 0x02 ) ;
V_16 -> V_23 = F_3 ( V_2 , V_11 + 0x03 ) ;
V_16 -> V_24 = F_3 ( V_2 , V_11 + 0x04 ) ;
break;
case 0x30 :
case 0x40 :
V_16 -> V_25 = F_3 ( V_2 , V_11 + 0x00 ) ;
V_16 -> V_22 = F_3 ( V_2 , V_11 + 0x01 ) ;
V_16 -> V_23 = F_3 ( V_2 , V_11 + 0x02 ) ;
V_16 -> V_24 = F_3 ( V_2 , V_11 + 0x03 ) ;
break;
default:
V_11 = 0x0000 ;
break;
}
}
return V_11 ;
}
T_1
F_9 ( struct V_1 * V_2 , T_1 V_14 , T_2 V_25 , T_2 V_26 , T_2 V_23 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_21 * V_16 )
{
T_2 V_13 = 0xff ;
T_1 V_11 ;
if ( * V_3 >= 0x30 ) {
const T_2 V_27 [] = { 0 , 4 , 7 , 9 } ;
V_13 = ( V_25 * 10 ) + V_27 [ V_26 ] + V_23 ;
} else {
while ( ( V_11 = F_7 ( V_2 , V_14 , ++ V_13 ,
V_3 , V_4 , V_5 , V_6 ) ) ) {
if ( F_3 ( V_2 , V_11 + 0x00 ) == V_26 &&
F_3 ( V_2 , V_11 + 0x01 ) == V_23 )
break;
}
}
return F_8 ( V_2 , V_14 , V_13 , V_3 , V_4 , V_5 , V_6 , V_16 ) ;
}
