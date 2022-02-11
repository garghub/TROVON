int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = 0 ;
unsigned int V_9 ;
V_9 = F_2 ( V_6 -> V_10 ) ;
if ( V_9 <= 7 ) {
V_8 = ( unsigned int ) F_3 ( V_11 -> V_12 + V_13 ) ;
* V_7 = ( V_8 >> V_9 ) & 0x1 ;
}
else {
F_4 ( L_1 ) ;
return - V_14 ;
}
return V_6 -> V_15 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_16 = V_7 [ 0 ] ;
unsigned int V_17 = 0 ;
unsigned int V_18 ;
V_18 = F_2 ( V_6 -> V_10 ) ;
* V_7 = ( unsigned int ) F_3 ( V_11 -> V_12 + V_13 ) ;
switch ( V_18 ) {
case 2 :
V_17 = 3 ;
* V_7 = ( * V_7 >> ( 2 * V_16 ) ) & V_17 ;
break;
case 4 :
V_17 = 15 ;
* V_7 = ( * V_7 >> ( 4 * V_16 ) ) & V_17 ;
break;
case 7 :
break;
default:
F_4 ( L_2 ) ;
return - V_14 ;
break;
}
return V_6 -> V_15 ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_11 -> V_19 = V_7 [ 0 ] ;
return V_6 -> V_15 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_20 , V_21 ;
unsigned int V_22 = F_2 ( V_6 -> V_10 ) ;
if ( V_11 -> V_19 ) {
V_20 = F_3 ( V_11 -> V_12 + V_23 ) ;
}
else {
V_20 = 0 ;
}
if ( V_7 [ 3 ] == 0 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ( V_7 [ 0 ] << V_22 ) | V_20 ;
F_8 ( V_7 [ 0 ] , V_11 -> V_12 + V_23 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
switch ( V_22 ) {
case 2 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 2 *
V_7 [ 2 ] ) ) | V_20 ;
break;
case 4 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 4 *
V_7 [ 2 ] ) ) | V_20 ;
break;
case 8 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 8 *
V_7 [ 2 ] ) ) | V_20 ;
break;
case 15 :
V_7 [ 0 ] = V_7 [ 0 ] | V_20 ;
break;
default:
F_9 ( V_2 , L_3 ) ;
return - V_14 ;
}
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 + V_23 ) ;
}
else {
F_4 ( L_4 ) ;
}
}
}
else {
if ( V_7 [ 3 ] == 1 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x1 ;
V_21 = 1 ;
V_21 = V_21 << V_22 ;
V_20 = V_20 | V_21 ;
V_7 [ 0 ] = ( V_7 [ 0 ] << V_22 ) ^ 0xffff ;
V_7 [ 0 ] = V_7 [ 0 ] & V_20 ;
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 + V_23 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
switch ( V_22 ) {
case 2 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x3 ;
V_21 = 3 ;
V_21 =
V_21 << 2 * V_7 [ 2 ] ;
V_20 = V_20 | V_21 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 2 *
V_7
[ 2 ] ) ) ^
0xffff ) & V_20 ;
break;
case 4 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xf ;
V_21 = 15 ;
V_21 =
V_21 << 4 * V_7 [ 2 ] ;
V_20 = V_20 | V_21 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 4 *
V_7
[ 2 ] ) ) ^
0xffff ) & V_20 ;
break;
case 8 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xff ;
V_21 = 255 ;
V_21 =
V_21 << 8 * V_7 [ 2 ] ;
V_20 = V_20 | V_21 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 8 *
V_7
[ 2 ] ) ) ^
0xffff ) & V_20 ;
break;
case 15 :
break;
default:
F_9 ( V_2 ,
L_3 ) ;
return - V_14 ;
}
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 +
V_23 ) ;
}
else {
F_4 ( L_4 ) ;
}
}
}
else {
F_4 ( L_5 ) ;
return - V_14 ;
}
}
return V_6 -> V_15 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_20 ;
unsigned int V_22 = F_2 ( V_6 -> V_10 ) ;
V_20 = V_7 [ 0 ] ;
* V_7 = F_3 ( V_11 -> V_12 + V_23 ) ;
if ( V_20 == 0 ) {
* V_7 = ( * V_7 >> V_22 ) & 0x1 ;
}
else {
if ( V_20 == 1 ) {
switch ( V_22 ) {
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
F_9 ( V_2 , L_3 ) ;
return - V_14 ;
}
}
else {
F_4 ( L_6 ) ;
}
}
return V_6 -> V_15 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] == 0 ) {
F_8 ( 0x0 ,
V_11 -> V_12 + V_24 +
V_25 ) ;
F_8 ( V_7 [ 1 ] ,
V_11 -> V_12 + V_24 +
V_26 ) ;
V_7 [ 1 ] = V_7 [ 1 ] >> 16 ;
F_8 ( V_7 [ 1 ] ,
V_11 -> V_12 + V_24 +
V_26 + 2 ) ;
}
else {
F_4 ( L_7 ) ;
return - V_14 ;
}
return V_6 -> V_15 ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
switch ( V_7 [ 0 ] ) {
case 0 :
F_8 ( 0x0 , V_11 -> V_12 + V_24 + V_25 ) ;
break;
case 1 :
F_8 ( 0x0001 ,
V_11 -> V_12 + V_24 +
V_25 ) ;
break;
case 2 :
F_8 ( 0x0201 ,
V_11 -> V_12 + V_24 +
V_25 ) ;
break;
default:
F_4 ( L_5 ) ;
return - V_14 ;
}
return V_6 -> V_15 ;
}
int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] =
F_3 ( V_11 -> V_12 + V_24 +
V_27 ) & 0x1 ;
return V_6 -> V_15 ;
}
int F_14 ( struct V_1 * V_2 )
{
F_8 ( 0x0 , V_11 -> V_12 + V_23 ) ;
F_8 ( 0x0 ,
V_11 -> V_12 + V_24 +
V_25 ) ;
F_8 ( 0x0 ,
V_11 -> V_12 + V_24 +
V_26 ) ;
F_8 ( 0x0 ,
V_11 -> V_12 + V_24 +
V_26 + 2 ) ;
return 0 ;
}
