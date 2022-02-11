static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( ( V_5 * ) ( V_3 + V_6 ) ,
( V_7 * ) ( V_2 + V_6 ) ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_5 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_12 ) {
F_6 ( V_3 , V_2 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
& V_1 -> V_14 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_6 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
& V_1 -> V_14 ) ;
return 1 ;
}
static int F_7 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_3 * V_15 = F_4 ( V_1 ) ;
# ifdef F_8
{
int V_6 ;
fprintf ( V_16 , L_1 , V_1 ,
V_1 -> V_17 ) ;
fprintf ( V_16 , L_2 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
fprintf ( V_16 , L_3 , V_1 -> V_13 [ V_6 ] ) ;
fprintf ( V_16 , L_4 ) ;
}
# endif
if ( V_15 -> V_18 . V_19 ) {
(* V_15 -> V_18 . V_19 ) ( V_3 , V_2 , V_4 , & V_15 -> V_20 , V_1 -> V_13 ) ;
return 1 ;
}
while ( V_4 >= V_12 ) {
F_9 ( V_3 , V_2 , ( long ) V_12 ,
& V_15 -> V_8 , & V_15 -> V_9 , & V_15 -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_9 ( V_3 , V_2 , ( long ) V_4 ,
& V_15 -> V_8 , & V_15 -> V_9 , & V_15 -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_12 ) {
F_11 ( V_3 , V_2 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
& V_1 -> V_14 , V_1 -> V_11 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_11 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
& V_1 -> V_14 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_2 V_21 ;
unsigned char V_22 [ 1 ] , V_23 [ 1 ] ;
for ( V_21 = 0 ; V_21 < V_4 ; ++ V_21 ) {
V_22 [ 0 ] = ( V_3 [ V_21 / 8 ] & ( 1 << ( 7 - V_21 % 8 ) ) ) ? 0x80 : 0 ;
F_13 ( V_22 , V_23 , 1 , 1 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
V_1 -> V_11 ) ;
V_2 [ V_21 / 8 ] = ( V_2 [ V_21 / 8 ] & ~ ( 0x80 >> ( unsigned int ) ( V_21 % 8 ) ) )
| ( ( V_23 [ 0 ] & 0x80 ) >> ( unsigned int ) ( V_21 % 8 ) ) ;
}
return 1 ;
}
static int F_14 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_12 ) {
F_13 ( V_3 , V_2 , 8 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
V_1 -> V_11 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_13 ( V_3 , V_2 , 8 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 , ( V_7 * ) V_1 -> V_13 ,
V_1 -> V_11 ) ;
return 1 ;
}
static int F_15 ( T_1 * V_1 , const unsigned char * V_24 ,
const unsigned char * V_13 , int V_25 )
{
V_7 * V_26 = ( V_7 * ) V_24 ;
T_3 * V_15 = F_4 ( V_1 ) ;
V_15 -> V_18 . V_19 = NULL ;
# if F_16 ( V_27 )
if ( V_27 ) {
int V_28 = V_1 -> V_29 -> V_30 & V_31 ;
if ( V_28 == V_32 ) {
F_17 ( & V_26 [ 0 ] , & V_15 -> V_8 ) ;
F_17 ( & V_26 [ 1 ] , & V_15 -> V_9 ) ;
memcpy ( & V_15 -> V_10 , & V_15 -> V_8 , sizeof( V_15 -> V_8 ) ) ;
V_15 -> V_18 . V_19 = V_25 ? V_33 :
V_34 ;
return 1 ;
}
}
# endif
# ifdef F_18
if ( F_19 ( & V_26 [ 0 ] , & V_15 -> V_8 )
! ! F_19 ( & V_26 [ 1 ] , & V_15 -> V_9 ) )
return 0 ;
# else
F_20 ( & V_26 [ 0 ] , & V_15 -> V_8 ) ;
F_20 ( & V_26 [ 1 ] , & V_15 -> V_9 ) ;
# endif
memcpy ( & V_15 -> V_10 , & V_15 -> V_8 , sizeof( V_15 -> V_8 ) ) ;
return 1 ;
}
static int F_21 ( T_1 * V_1 , const unsigned char * V_24 ,
const unsigned char * V_13 , int V_25 )
{
V_7 * V_26 = ( V_7 * ) V_24 ;
T_3 * V_15 = F_4 ( V_1 ) ;
# ifdef F_8
{
int V_6 ;
fprintf ( V_16 , L_5 , V_1 ) ;
fprintf ( V_16 , L_6 ) ;
for ( V_6 = 0 ; V_6 < 24 ; V_6 ++ )
fprintf ( V_16 , L_3 , V_24 [ V_6 ] ) ;
fprintf ( V_16 , L_4 ) ;
if ( V_13 ) {
fprintf ( V_16 , L_7 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
fprintf ( V_16 , L_3 , V_13 [ V_6 ] ) ;
fprintf ( V_16 , L_4 ) ;
}
}
# endif
V_15 -> V_18 . V_19 = NULL ;
# if F_16 ( V_27 )
if ( V_27 ) {
int V_28 = V_1 -> V_29 -> V_30 & V_31 ;
if ( V_28 == V_32 ) {
F_17 ( & V_26 [ 0 ] , & V_15 -> V_8 ) ;
F_17 ( & V_26 [ 1 ] , & V_15 -> V_9 ) ;
F_17 ( & V_26 [ 2 ] , & V_15 -> V_10 ) ;
V_15 -> V_18 . V_19 = V_25 ? V_33 :
V_34 ;
return 1 ;
}
}
# endif
# ifdef F_18
if ( F_19 ( & V_26 [ 0 ] , & V_15 -> V_8 )
|| F_19 ( & V_26 [ 1 ] , & V_15 -> V_9 )
|| F_19 ( & V_26 [ 2 ] , & V_15 -> V_10 ) )
return 0 ;
# else
F_20 ( & V_26 [ 0 ] , & V_15 -> V_8 ) ;
F_20 ( & V_26 [ 1 ] , & V_15 -> V_9 ) ;
F_20 ( & V_26 [ 2 ] , & V_15 -> V_10 ) ;
# endif
return 1 ;
}
static int F_22 ( T_1 * V_22 , int type , int V_35 , void * V_36 )
{
V_7 * V_26 = V_36 ;
switch ( type ) {
case V_37 :
if ( F_23 ( V_36 , V_22 -> V_38 ) <= 0 )
return 0 ;
F_24 ( V_26 ) ;
if ( V_22 -> V_38 >= 16 )
F_24 ( V_26 + 1 ) ;
if ( V_22 -> V_38 >= 24 )
F_24 ( V_26 + 2 ) ;
return 1 ;
default:
return - 1 ;
}
}
const T_4 * F_25 ( void )
{
return & V_39 ;
}
const T_4 * F_26 ( void )
{
return & V_40 ;
}
static int F_27 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
unsigned char V_41 [ 8 ] , V_13 [ 8 ] , V_42 [ V_43 ] ;
int V_44 = - 1 ;
if ( V_4 < 24 )
return - 1 ;
if ( ! V_2 )
return V_4 - 16 ;
memcpy ( V_1 -> V_13 , V_45 , 8 ) ;
F_7 ( V_1 , V_41 , V_3 , 8 ) ;
if ( V_2 == V_3 ) {
memmove ( V_2 , V_2 + 8 , V_4 - 8 ) ;
V_3 -= 8 ;
}
F_7 ( V_1 , V_2 , V_3 + 8 , V_4 - 16 ) ;
F_7 ( V_1 , V_13 , V_3 + V_4 - 8 , 8 ) ;
F_28 ( V_41 , NULL , 8 ) ;
F_28 ( V_2 , NULL , V_4 - 16 ) ;
F_28 ( V_1 -> V_13 , V_13 , 8 ) ;
F_7 ( V_1 , V_2 , V_2 , V_4 - 16 ) ;
F_7 ( V_1 , V_41 , V_41 , 8 ) ;
F_29 ( V_2 , V_4 - 16 , V_42 ) ;
if ( ! F_30 ( V_42 , V_41 , 8 ) )
V_44 = V_4 - 16 ;
F_31 ( V_41 , 8 ) ;
F_31 ( V_42 , V_43 ) ;
F_31 ( V_13 , 8 ) ;
F_31 ( V_1 -> V_13 , 8 ) ;
if ( V_44 == - 1 )
F_31 ( V_2 , V_4 - 16 ) ;
return V_44 ;
}
static int F_32 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
unsigned char V_42 [ V_43 ] ;
if ( ! V_2 )
return V_4 + 16 ;
memmove ( V_2 + 8 , V_3 , V_4 ) ;
F_29 ( V_3 , V_4 , V_42 ) ;
memcpy ( V_2 + V_4 + 8 , V_42 , 8 ) ;
F_31 ( V_42 , V_43 ) ;
F_23 ( V_1 -> V_13 , 8 ) ;
memcpy ( V_2 , V_1 -> V_13 , 8 ) ;
F_7 ( V_1 , V_2 + 8 , V_2 + 8 , V_4 + 8 ) ;
F_28 ( V_2 , NULL , V_4 + 16 ) ;
memcpy ( V_1 -> V_13 , V_45 , 8 ) ;
F_7 ( V_1 , V_2 , V_2 , V_4 + 16 ) ;
return V_4 + 16 ;
}
static int F_33 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
if ( V_4 >= V_12 || V_4 % 8 )
return - 1 ;
if ( V_1 -> V_11 )
return F_32 ( V_1 , V_2 , V_3 , V_4 ) ;
else
return F_27 ( V_1 , V_2 , V_3 , V_4 ) ;
}
const T_4 * F_34 ( void )
{
return & V_46 ;
}
