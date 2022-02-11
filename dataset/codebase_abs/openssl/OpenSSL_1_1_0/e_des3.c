static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( ( V_5 * ) ( V_3 + V_6 ) ,
( V_7 * ) ( V_2 + V_6 ) ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , F_5 ( V_1 ) ) ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_11 ) {
int V_12 = F_7 ( V_1 ) ;
F_8 ( V_3 , V_2 , ( long ) V_11 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
& V_12 ) ;
F_10 ( V_1 , V_12 ) ;
V_4 -= V_11 ;
V_3 += V_11 ;
V_2 += V_11 ;
}
if ( V_4 ) {
int V_12 = F_7 ( V_1 ) ;
F_8 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
& V_12 ) ;
F_10 ( V_1 , V_12 ) ;
}
return 1 ;
}
static int F_11 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_3 * V_13 = F_4 ( V_1 ) ;
if ( V_13 -> V_14 . V_15 != NULL ) {
(* V_13 -> V_14 . V_15 ) ( V_3 , V_2 , V_4 , V_13 -> V_16 . V_16 ,
F_9 ( V_1 ) ) ;
return 1 ;
}
while ( V_4 >= V_11 ) {
F_12 ( V_3 , V_2 , ( long ) V_11 ,
& V_13 -> V_8 , & V_13 -> V_9 , & V_13 -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_4 -= V_11 ;
V_3 += V_11 ;
V_2 += V_11 ;
}
if ( V_4 )
F_12 ( V_3 , V_2 , ( long ) V_4 ,
& V_13 -> V_8 , & V_13 -> V_9 , & V_13 -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
return 1 ;
}
static int F_13 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_11 ) {
int V_12 = F_7 ( V_1 ) ;
F_14 ( V_3 , V_2 , ( long ) V_11 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
& V_12 , F_5 ( V_1 ) ) ;
F_10 ( V_1 , V_12 ) ;
V_4 -= V_11 ;
V_3 += V_11 ;
V_2 += V_11 ;
}
if ( V_4 ) {
int V_12 = F_7 ( V_1 ) ;
F_14 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
& V_12 , F_5 ( V_1 ) ) ;
F_10 ( V_1 , V_12 ) ;
}
return 1 ;
}
static int F_15 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_2 V_17 ;
unsigned char V_18 [ 1 ] , V_19 [ 1 ] ;
if ( ! F_16 ( V_1 , V_20 ) )
V_4 *= 8 ;
for ( V_17 = 0 ; V_17 < V_4 ; ++ V_17 ) {
V_18 [ 0 ] = ( V_3 [ V_17 / 8 ] & ( 1 << ( 7 - V_17 % 8 ) ) ) ? 0x80 : 0 ;
F_17 ( V_18 , V_19 , 1 , 1 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_2 [ V_17 / 8 ] = ( V_2 [ V_17 / 8 ] & ~ ( 0x80 >> ( unsigned int ) ( V_17 % 8 ) ) )
| ( ( V_19 [ 0 ] & 0x80 ) >> ( unsigned int ) ( V_17 % 8 ) ) ;
}
return 1 ;
}
static int F_18 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_11 ) {
F_17 ( V_3 , V_2 , 8 , ( long ) V_11 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_4 -= V_11 ;
V_3 += V_11 ;
V_2 += V_11 ;
}
if ( V_4 )
F_17 ( V_3 , V_2 , 8 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
( V_7 * ) F_9 ( V_1 ) ,
F_5 ( V_1 ) ) ;
return 1 ;
}
static int F_19 ( T_1 * V_1 , const unsigned char * V_21 ,
const unsigned char * V_22 , int V_23 )
{
V_7 * V_24 = ( V_7 * ) V_21 ;
T_3 * V_13 = F_4 ( V_1 ) ;
V_13 -> V_14 . V_15 = NULL ;
# if F_20 ( V_25 )
if ( V_25 ) {
int V_26 = F_21 ( V_1 ) ;
if ( V_26 == V_27 ) {
F_22 ( & V_24 [ 0 ] , & V_13 -> V_8 ) ;
F_22 ( & V_24 [ 1 ] , & V_13 -> V_9 ) ;
memcpy ( & V_13 -> V_10 , & V_13 -> V_8 , sizeof( V_13 -> V_8 ) ) ;
V_13 -> V_14 . V_15 = V_23 ? V_28 :
V_29 ;
return 1 ;
}
}
# endif
F_23 ( & V_24 [ 0 ] , & V_13 -> V_8 ) ;
F_23 ( & V_24 [ 1 ] , & V_13 -> V_9 ) ;
memcpy ( & V_13 -> V_10 , & V_13 -> V_8 , sizeof( V_13 -> V_8 ) ) ;
return 1 ;
}
static int F_24 ( T_1 * V_1 , const unsigned char * V_21 ,
const unsigned char * V_22 , int V_23 )
{
V_7 * V_24 = ( V_7 * ) V_21 ;
T_3 * V_13 = F_4 ( V_1 ) ;
V_13 -> V_14 . V_15 = NULL ;
# if F_20 ( V_25 )
if ( V_25 ) {
int V_26 = F_21 ( V_1 ) ;
if ( V_26 == V_27 ) {
F_22 ( & V_24 [ 0 ] , & V_13 -> V_8 ) ;
F_22 ( & V_24 [ 1 ] , & V_13 -> V_9 ) ;
F_22 ( & V_24 [ 2 ] , & V_13 -> V_10 ) ;
V_13 -> V_14 . V_15 = V_23 ? V_28 :
V_29 ;
return 1 ;
}
}
# endif
F_23 ( & V_24 [ 0 ] , & V_13 -> V_8 ) ;
F_23 ( & V_24 [ 1 ] , & V_13 -> V_9 ) ;
F_23 ( & V_24 [ 2 ] , & V_13 -> V_10 ) ;
return 1 ;
}
static int F_25 ( T_1 * V_1 , int type , int V_30 , void * V_31 )
{
V_7 * V_24 = V_31 ;
switch ( type ) {
case V_32 :
if ( F_26 ( V_31 , F_27 ( V_1 ) ) <= 0 )
return 0 ;
F_28 ( V_24 ) ;
if ( F_27 ( V_1 ) >= 16 )
F_28 ( V_24 + 1 ) ;
if ( F_27 ( V_1 ) >= 24 )
F_28 ( V_24 + 2 ) ;
return 1 ;
default:
return - 1 ;
}
}
const T_4 * F_29 ( void )
{
return & V_33 ;
}
const T_4 * F_30 ( void )
{
return & V_34 ;
}
static int F_31 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
unsigned char V_35 [ 8 ] , V_22 [ 8 ] , V_36 [ V_37 ] ;
int V_38 = - 1 ;
if ( V_4 < 24 )
return - 1 ;
if ( V_2 == NULL )
return V_4 - 16 ;
memcpy ( F_9 ( V_1 ) , V_39 , 8 ) ;
F_11 ( V_1 , V_35 , V_3 , 8 ) ;
if ( V_2 == V_3 ) {
memmove ( V_2 , V_2 + 8 , V_4 - 8 ) ;
V_3 -= 8 ;
}
F_11 ( V_1 , V_2 , V_3 + 8 , V_4 - 16 ) ;
F_11 ( V_1 , V_22 , V_3 + V_4 - 8 , 8 ) ;
F_32 ( V_35 , NULL , 8 ) ;
F_32 ( V_2 , NULL , V_4 - 16 ) ;
F_32 ( F_9 ( V_1 ) , V_22 , 8 ) ;
F_11 ( V_1 , V_2 , V_2 , V_4 - 16 ) ;
F_11 ( V_1 , V_35 , V_35 , 8 ) ;
F_33 ( V_2 , V_4 - 16 , V_36 ) ;
if ( ! F_34 ( V_36 , V_35 , 8 ) )
V_38 = V_4 - 16 ;
F_35 ( V_35 , 8 ) ;
F_35 ( V_36 , V_37 ) ;
F_35 ( V_22 , 8 ) ;
F_35 ( F_9 ( V_1 ) , 8 ) ;
if ( V_38 == - 1 )
F_35 ( V_2 , V_4 - 16 ) ;
return V_38 ;
}
static int F_36 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
unsigned char V_36 [ V_37 ] ;
if ( V_2 == NULL )
return V_4 + 16 ;
memmove ( V_2 + 8 , V_3 , V_4 ) ;
F_33 ( V_3 , V_4 , V_36 ) ;
memcpy ( V_2 + V_4 + 8 , V_36 , 8 ) ;
F_35 ( V_36 , V_37 ) ;
if ( F_26 ( F_9 ( V_1 ) , 8 ) <= 0 )
return - 1 ;
memcpy ( V_2 , F_9 ( V_1 ) , 8 ) ;
F_11 ( V_1 , V_2 + 8 , V_2 + 8 , V_4 + 8 ) ;
F_32 ( V_2 , NULL , V_4 + 16 ) ;
memcpy ( F_9 ( V_1 ) , V_39 , 8 ) ;
F_11 ( V_1 , V_2 , V_2 , V_4 + 16 ) ;
return V_4 + 16 ;
}
static int F_37 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
if ( V_4 >= V_11 || V_4 % 8 )
return - 1 ;
if ( F_5 ( V_1 ) )
return F_36 ( V_1 , V_2 , V_3 , V_4 ) ;
else
return F_31 ( V_1 , V_2 , V_3 , V_4 ) ;
}
const T_4 * F_38 ( void )
{
return & V_40 ;
}
