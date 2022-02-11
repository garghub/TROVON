int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = 0 ;
V_9 -> V_10 = V_11 ;
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_2 ( V_2 ,
L_1 ) ;
return - V_12 ;
}
if ( V_7 [ 0 ] ) {
V_9 -> V_13 = V_14 ;
}
else {
V_9 -> V_13 = V_15 ;
}
if ( V_7 [ 1 ] == V_14 ) {
V_8 = V_8 | 0x1 ;
}
else {
V_8 = V_8 & 0xFFFFFFFE ;
}
if ( V_7 [ 2 ] == V_14 ) {
V_8 = V_8 | 0x2 ;
}
else {
V_8 = V_8 & 0xFFFFFFFD ;
}
F_3 ( V_8 , V_9 -> V_16 + V_17 ) ;
V_18 = F_4 ( V_9 -> V_16 + V_17 ) ;
return V_6 -> V_19 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_20 , V_21 ;
unsigned int V_22 = F_6 ( V_6 -> V_23 ) ;
if ( V_9 -> V_13 ) {
V_20 = F_4 ( V_9 -> V_16 + V_24 ) ;
}
else {
V_20 = 0 ;
}
if ( V_7 [ 3 ] == 0 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ( V_7 [ 0 ] << V_22 ) | V_20 ;
F_3 ( V_7 [ 0 ] , V_9 -> V_16 + V_24 ) ;
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
case 16 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 16 *
V_7 [ 2 ] ) ) | V_20 ;
break;
case 31 :
V_7 [ 0 ] = V_7 [ 0 ] | V_20 ;
break;
default:
F_2 ( V_2 , L_2 ) ;
return - V_12 ;
}
F_3 ( V_7 [ 0 ] ,
V_9 -> V_16 + V_24 ) ;
}
else {
F_7 ( L_3 ) ;
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
V_7 [ 0 ] =
( V_7 [ 0 ] << V_22 ) ^
0xffffffff ;
V_7 [ 0 ] = V_7 [ 0 ] & V_20 ;
F_3 ( V_7 [ 0 ] ,
V_9 -> V_16 + V_24 ) ;
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
0xffffffff ) & V_20 ;
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
0xffffffff ) & V_20 ;
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
0xffffffff ) & V_20 ;
break;
case 16 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xffff ;
V_21 = 65535 ;
V_21 =
V_21 << 16 *
V_7 [ 2 ] ;
V_20 = V_20 | V_21 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 16 *
V_7
[ 2 ] ) ) ^
0xffffffff ) & V_20 ;
break;
case 31 :
break;
default:
F_2 ( V_2 ,
L_2 ) ;
return - V_12 ;
}
F_3 ( V_7 [ 0 ] ,
V_9 -> V_16 +
V_24 ) ;
}
else {
F_7 ( L_3 ) ;
}
}
}
else {
F_7 ( L_4 ) ;
return - V_12 ;
}
}
return V_6 -> V_19 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_20 ;
unsigned int V_22 ;
V_22 = F_6 ( V_6 -> V_23 ) ;
V_20 = V_7 [ 0 ] ;
* V_7 = F_4 ( V_9 -> V_16 + V_25 ) ;
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
case 16 :
* V_7 = ( * V_7 >> ( 16 * V_7 [ 1 ] ) ) & 65535 ;
break;
case 31 :
break;
default:
F_2 ( V_2 , L_2 ) ;
return - V_12 ;
}
}
else {
F_7 ( L_5 ) ;
}
}
return V_6 -> V_19 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] == 0 ) {
F_3 ( 0x0 ,
V_9 -> V_16 + V_26 +
V_27 ) ;
F_3 ( V_7 [ 1 ] ,
V_9 -> V_16 + V_26 +
V_28 ) ;
} else {
F_7 ( L_6 ) ;
return - V_12 ;
}
return V_6 -> V_19 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
switch ( V_7 [ 0 ] ) {
case 0 :
F_3 ( 0x0 , V_9 -> V_16 + V_26 + V_27 ) ;
break;
case 1 :
F_3 ( 0x0001 ,
V_9 -> V_16 + V_26 +
V_27 ) ;
break;
case 2 :
F_3 ( 0x0201 ,
V_9 -> V_16 + V_26 +
V_27 ) ;
break;
default:
F_7 ( L_4 ) ;
return - V_12 ;
}
return V_6 -> V_19 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] =
F_4 ( V_9 -> V_16 + V_26 +
V_29 ) & 0x1 ;
return V_6 -> V_19 ;
}
void F_12 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
unsigned int V_32 ;
V_32 = F_4 ( V_9 -> V_16 + V_33 ) & 0x1 ;
if ( V_32 == 0 ) {
F_7 ( L_7 ) ;
}
if ( V_32 ) {
V_34 =
F_4 ( V_9 -> V_16 +
V_35 ) & 0x3 ;
F_3 ( 0x0 ,
V_9 -> V_16 + V_24 +
V_17 ) ;
if ( V_34 == 1 ) {
F_13 ( V_36 , V_9 -> V_10 , 0 ) ;
}
else {
if ( V_34 == 2 ) {
F_13 ( V_36 , V_9 -> V_10 , 0 ) ;
}
}
}
return;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
* V_7 = V_34 ;
return V_6 -> V_19 ;
}
int F_15 ( struct V_1 * V_2 )
{
V_9 -> V_37 = 0 ;
V_34 = 0 ;
F_3 ( 0x0 , V_9 -> V_16 + V_24 ) ;
F_3 ( 0x0 , V_9 -> V_16 + V_17 ) ;
F_3 ( 0x0 , V_9 -> V_16 + V_26 + V_27 ) ;
F_3 ( 0x0 , V_9 -> V_16 + V_26 + V_28 ) ;
return 0 ;
}
