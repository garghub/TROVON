int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_2 ( V_2 ,
L_1 ) ;
return - V_8 ;
}
if ( V_7 [ 0 ] ) {
V_9 -> V_10 = V_11 ;
}
else {
V_9 -> V_10 = V_12 ;
}
return V_6 -> V_13 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_14 ;
unsigned int V_15 , V_16 ;
V_14 = F_4 ( V_6 -> V_17 ) ;
if ( V_14 > 15 ) {
F_2 ( V_2 ,
L_2 ) ;
return - V_8 ;
}
if ( V_9 -> V_10 ) {
V_15 = F_5 ( V_9 -> V_18 + V_19 ) ;
}
else {
V_15 = 0 ;
}
if ( ( V_7 [ 1 ] != 0 ) && ( V_7 [ 1 ] != 1 ) ) {
F_2 ( V_2 ,
L_3 ) ;
return - V_8 ;
}
if ( V_7 [ 3 ] == 0 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ( V_7 [ 0 ] << V_14 ) | V_15 ;
F_6 ( V_7 [ 0 ] , V_9 -> V_18 + V_19 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
switch ( V_14 ) {
case 2 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 2 *
V_7 [ 2 ] ) ) | V_15 ;
break;
case 4 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 4 *
V_7 [ 2 ] ) ) | V_15 ;
break;
case 8 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 8 *
V_7 [ 2 ] ) ) | V_15 ;
break;
case 15 :
V_7 [ 0 ] = V_7 [ 0 ] | V_15 ;
break;
default:
F_2 ( V_2 , L_4 ) ;
return - V_8 ;
}
F_6 ( V_7 [ 0 ] ,
V_9 -> V_18 + V_19 ) ;
}
else {
F_7 ( L_5 ) ;
}
}
}
else {
if ( V_7 [ 3 ] == 1 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x1 ;
V_16 = 1 ;
V_16 = V_16 << V_14 ;
V_15 = V_15 | V_16 ;
V_7 [ 0 ] = ( V_7 [ 0 ] << V_14 ) ^ 0xffff ;
V_7 [ 0 ] = V_7 [ 0 ] & V_15 ;
F_6 ( V_7 [ 0 ] ,
V_9 -> V_18 + V_19 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
switch ( V_14 ) {
case 2 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x3 ;
V_16 = 3 ;
V_16 =
V_16 << 2 * V_7 [ 2 ] ;
V_15 = V_15 | V_16 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 2 *
V_7
[ 2 ] ) ) ^
0xffff ) & V_15 ;
break;
case 4 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xf ;
V_16 = 15 ;
V_16 =
V_16 << 4 * V_7 [ 2 ] ;
V_15 = V_15 | V_16 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 4 *
V_7
[ 2 ] ) ) ^
0xffff ) & V_15 ;
break;
case 8 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xff ;
V_16 = 255 ;
V_16 =
V_16 << 8 * V_7 [ 2 ] ;
V_15 = V_15 | V_16 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 8 *
V_7
[ 2 ] ) ) ^
0xffff ) & V_15 ;
break;
case 15 :
break;
default:
F_2 ( V_2 ,
L_4 ) ;
return - V_8 ;
}
F_6 ( V_7 [ 0 ] ,
V_9 -> V_18 +
V_19 ) ;
}
else {
F_7 ( L_5 ) ;
}
}
}
else {
F_7 ( L_6 ) ;
return - V_8 ;
}
}
return V_6 -> V_13 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_15 ;
unsigned int V_14 ;
V_14 = F_4 ( V_6 -> V_17 ) ;
if ( V_14 > 15 ) {
F_2 ( V_2 ,
L_2 ) ;
return - V_8 ;
}
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_2 ( V_2 ,
L_7 ) ;
return - V_8 ;
}
V_15 = V_7 [ 0 ] ;
* V_7 = F_5 ( V_9 -> V_18 + V_20 ) ;
if ( V_15 == 0 ) {
* V_7 = ( * V_7 >> V_14 ) & 0x1 ;
}
else {
if ( V_15 == 1 ) {
switch ( V_14 ) {
case 2 :
* V_7 = ( * V_7 >> ( 2 * V_7 [ 1 ] ) ) & 3 ;
break;
case 4 :
* V_7 = ( * V_7 >> ( 4 * V_7 [ 1 ] ) ) & 15 ;
break;
case 8 :
* V_7 = ( * V_7 >> ( 8 * V_7 [ 1 ] ) ) & 255 ;
break;
case 15 :
break;
default:
F_2 ( V_2 , L_4 ) ;
return - V_8 ;
}
}
else {
F_7 ( L_8 ) ;
}
}
return V_6 -> V_13 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] == 0 ) {
F_6 ( 0x0 ,
V_9 -> V_21 +
V_22 ) ;
F_6 ( V_7 [ 1 ] ,
V_9 -> V_21 +
V_23 ) ;
V_7 [ 1 ] = V_7 [ 1 ] >> 16 ;
F_6 ( V_7 [ 1 ] ,
V_9 -> V_21 +
V_23 + 2 ) ;
} else {
F_7 ( L_9 ) ;
}
return V_6 -> V_13 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
switch ( V_7 [ 0 ] ) {
case 0 :
F_6 ( 0x0 , V_9 -> V_21 + V_22 ) ;
break;
case 1 :
F_6 ( 0x0001 ,
V_9 -> V_21 +
V_22 ) ;
break;
case 2 :
F_6 ( 0x0201 ,
V_9 -> V_21 +
V_22 ) ;
break;
default:
F_7 ( L_6 ) ;
return - V_8 ;
}
return V_6 -> V_13 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_12 ( 5 ) ;
V_7 [ 0 ] = F_5 ( V_9 -> V_21 + V_24 ) & 0x1 ;
return V_6 -> V_13 ;
}
int F_13 ( struct V_1 * V_2 )
{
F_6 ( 0x0 , V_9 -> V_18 + V_19 ) ;
F_6 ( 0x0 , V_9 -> V_21 + V_22 ) ;
F_6 ( 0x0 , V_9 -> V_21 + V_23 ) ;
F_6 ( 0x0 , V_9 -> V_21 + V_23 + 2 ) ;
return 0 ;
}
