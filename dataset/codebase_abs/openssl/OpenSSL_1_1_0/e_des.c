static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( ( V_5 * ) ( V_3 + V_6 ) , ( V_5 * ) ( V_2 + V_6 ) ,
F_4 ( V_1 ) ,
F_5 ( V_1 ) ) ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_7 ) {
int V_8 = F_7 ( V_1 ) ;
F_8 ( V_3 , V_2 , ( long ) V_7 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) , & V_8 ) ;
F_10 ( V_1 , V_8 ) ;
V_4 -= V_7 ;
V_3 += V_7 ;
V_2 += V_7 ;
}
if ( V_4 ) {
int V_8 = F_7 ( V_1 ) ;
F_8 ( V_3 , V_2 , ( long ) V_4 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) , & V_8 ) ;
F_10 ( V_1 , V_8 ) ;
}
return 1 ;
}
static int F_11 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_3 * V_9 = ( T_3 * ) F_4 ( V_1 ) ;
if ( V_9 -> V_10 . V_11 != NULL ) {
(* V_9 -> V_10 . V_11 ) ( V_3 , V_2 , V_4 , & V_9 -> V_12 . V_12 ,
F_9 ( V_1 ) ) ;
return 1 ;
}
while ( V_4 >= V_7 ) {
F_12 ( V_3 , V_2 , ( long ) V_7 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_4 -= V_7 ;
V_3 += V_7 ;
V_2 += V_7 ;
}
if ( V_4 )
F_12 ( V_3 , V_2 , ( long ) V_4 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
return 1 ;
}
static int F_13 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_7 ) {
int V_8 = F_7 ( V_1 ) ;
F_14 ( V_3 , V_2 , ( long ) V_7 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) , & V_8 ,
F_5 ( V_1 ) ) ;
F_10 ( V_1 , V_8 ) ;
V_4 -= V_7 ;
V_3 += V_7 ;
V_2 += V_7 ;
}
if ( V_4 ) {
int V_8 = F_7 ( V_1 ) ;
F_14 ( V_3 , V_2 , ( long ) V_4 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) , & V_8 ,
F_5 ( V_1 ) ) ;
F_10 ( V_1 , V_8 ) ;
}
return 1 ;
}
static int F_15 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_2 V_13 , V_14 = V_7 / 8 ;
unsigned char V_15 [ 1 ] , V_16 [ 1 ] ;
if ( V_4 < V_14 )
V_14 = V_4 ;
while ( V_4 && V_4 >= V_14 ) {
for ( V_13 = 0 ; V_13 < V_14 * 8 ; ++ V_13 ) {
V_15 [ 0 ] = ( V_3 [ V_13 / 8 ] & ( 1 << ( 7 - V_13 % 8 ) ) ) ? 0x80 : 0 ;
F_16 ( V_15 , V_16 , 1 , 1 , F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_2 [ V_13 / 8 ] =
( V_2 [ V_13 / 8 ] & ~ ( 0x80 >> ( unsigned int ) ( V_13 % 8 ) ) ) |
( ( V_16 [ 0 ] & 0x80 ) >> ( unsigned int ) ( V_13 % 8 ) ) ;
}
V_4 -= V_14 ;
V_3 += V_14 ;
V_2 += V_14 ;
if ( V_4 < V_14 )
V_14 = V_4 ;
}
return 1 ;
}
static int F_17 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_7 ) {
F_16 ( V_3 , V_2 , 8 , ( long ) V_7 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_4 -= V_7 ;
V_3 += V_7 ;
V_2 += V_7 ;
}
if ( V_4 )
F_16 ( V_3 , V_2 , 8 , ( long ) V_4 ,
F_4 ( V_1 ) ,
( V_5 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
return 1 ;
}
static int F_18 ( T_1 * V_1 , const unsigned char * V_17 ,
const unsigned char * V_18 , int V_19 )
{
V_5 * V_20 = ( V_5 * ) V_17 ;
T_3 * V_9 = ( T_3 * ) F_4 ( V_1 ) ;
V_9 -> V_10 . V_11 = NULL ;
# if F_19 ( V_21 )
if ( V_21 ) {
int V_22 = F_20 ( V_1 ) ;
if ( V_22 == V_23 ) {
F_21 ( V_17 , & V_9 -> V_12 . V_12 ) ;
V_9 -> V_10 . V_11 = V_19 ? V_24 : V_25 ;
return 1 ;
}
}
# endif
F_22 ( V_20 , F_4 ( V_1 ) ) ;
return 1 ;
}
static int F_23 ( T_1 * V_15 , int type , int V_26 , void * V_27 )
{
switch ( type ) {
case V_28 :
if ( F_24 ( V_27 , 8 ) <= 0 )
return 0 ;
F_25 ( ( V_5 * ) V_27 ) ;
return 1 ;
default:
return - 1 ;
}
}
