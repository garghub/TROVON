static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( ( V_5 * ) ( V_3 + V_6 ) , ( V_5 * ) ( V_2 + V_6 ) ,
V_1 -> V_7 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_4 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_9 ) {
F_5 ( V_3 , V_2 , ( long ) V_9 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , & V_1 -> V_11 ) ;
V_4 -= V_9 ;
V_3 += V_9 ;
V_2 += V_9 ;
}
if ( V_4 )
F_5 ( V_3 , V_2 , ( long ) V_4 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , & V_1 -> V_11 ) ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_3 * V_12 = ( T_3 * ) V_1 -> V_7 ;
if ( V_12 -> V_13 . V_14 ) {
(* V_12 -> V_13 . V_14 ) ( V_3 , V_2 , V_4 , & V_12 -> V_15 . V_15 , V_1 -> V_10 ) ;
return 1 ;
}
while ( V_4 >= V_9 ) {
F_7 ( V_3 , V_2 , ( long ) V_9 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , V_1 -> V_8 ) ;
V_4 -= V_9 ;
V_3 += V_9 ;
V_2 += V_9 ;
}
if ( V_4 )
F_7 ( V_3 , V_2 , ( long ) V_4 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_8 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_9 ) {
F_9 ( V_3 , V_2 , ( long ) V_9 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , & V_1 -> V_11 , V_1 -> V_8 ) ;
V_4 -= V_9 ;
V_3 += V_9 ;
V_2 += V_9 ;
}
if ( V_4 )
F_9 ( V_3 , V_2 , ( long ) V_4 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , & V_1 -> V_11 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_2 V_16 , V_17 = V_9 / 8 ;
unsigned char V_18 [ 1 ] , V_19 [ 1 ] ;
if ( V_4 < V_17 )
V_17 = V_4 ;
while ( V_4 && V_4 >= V_17 ) {
for ( V_16 = 0 ; V_16 < V_17 * 8 ; ++ V_16 ) {
V_18 [ 0 ] = ( V_3 [ V_16 / 8 ] & ( 1 << ( 7 - V_16 % 8 ) ) ) ? 0x80 : 0 ;
F_11 ( V_18 , V_19 , 1 , 1 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , V_1 -> V_8 ) ;
V_2 [ V_16 / 8 ] =
( V_2 [ V_16 / 8 ] & ~ ( 0x80 >> ( unsigned int ) ( V_16 % 8 ) ) ) |
( ( V_19 [ 0 ] & 0x80 ) >> ( unsigned int ) ( V_16 % 8 ) ) ;
}
V_4 -= V_17 ;
V_3 += V_17 ;
V_2 += V_17 ;
if ( V_4 < V_17 )
V_17 = V_4 ;
}
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_9 ) {
F_11 ( V_3 , V_2 , 8 , ( long ) V_9 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , V_1 -> V_8 ) ;
V_4 -= V_9 ;
V_3 += V_9 ;
V_2 += V_9 ;
}
if ( V_4 )
F_11 ( V_3 , V_2 , 8 , ( long ) V_4 , V_1 -> V_7 ,
( V_5 * ) V_1 -> V_10 , V_1 -> V_8 ) ;
return 1 ;
}
static int F_13 ( T_1 * V_1 , const unsigned char * V_20 ,
const unsigned char * V_10 , int V_21 )
{
V_5 * V_22 = ( V_5 * ) V_20 ;
T_3 * V_12 = ( T_3 * ) V_1 -> V_7 ;
V_12 -> V_13 . V_14 = NULL ;
# if F_14 ( V_23 )
if ( V_23 ) {
int V_24 = V_1 -> V_25 -> V_26 & V_27 ;
if ( V_24 == V_28 ) {
F_15 ( V_20 , & V_12 -> V_15 . V_15 ) ;
V_12 -> V_13 . V_14 = V_21 ? V_29 : V_30 ;
return 1 ;
}
}
# endif
# ifdef F_16
if ( F_17 ( V_22 , V_12 -> V_15 . V_15 ) != 0 )
return 0 ;
# else
F_18 ( V_22 , V_1 -> V_7 ) ;
# endif
return 1 ;
}
static int F_19 ( T_1 * V_18 , int type , int V_31 , void * V_32 )
{
switch ( type ) {
case V_33 :
if ( F_20 ( V_32 , 8 ) <= 0 )
return 0 ;
F_21 ( ( V_5 * ) V_32 ) ;
return 1 ;
default:
return - 1 ;
}
}
