static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( ( V_5 * ) ( V_3 + V_6 ) ,
( V_7 * ) ( V_2 + V_6 ) ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 ,
& F_4 ( V_1 ) -> V_10 ,
V_1 -> V_11 ) ;
return 1 ;
}
static int F_5 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
if ( V_4 >= V_12 )
{
F_6 ( V_3 , V_2 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , & V_1 -> V_14 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_6 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , & V_1 -> V_14 ) ;
return 1 ;
}
static int F_7 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
#ifdef F_8
{
int V_6 ;
char * V_15 ;
printf ( L_1 , V_1 , V_1 -> V_16 ) ;
printf ( L_2 ) ;
for( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
printf ( L_3 , V_1 -> V_13 [ V_6 ] ) ;
printf ( L_4 ) ;
}
#endif
if ( V_4 >= V_12 )
{
F_9 ( V_3 , V_2 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_9 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
if ( V_4 >= V_12 )
{
F_11 ( V_3 , V_2 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , & V_1 -> V_14 , V_1 -> V_11 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_11 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , & V_1 -> V_14 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
T_2 V_17 ;
unsigned char V_18 [ 1 ] , V_19 [ 1 ] ;
for( V_17 = 0 ; V_17 < V_4 ; ++ V_17 )
{
V_18 [ 0 ] = ( V_3 [ V_17 / 8 ] & ( 1 << ( 7 - V_17 % 8 ) ) ) ? 0x80 : 0 ;
F_13 ( V_18 , V_19 , 1 , 1 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
V_2 [ V_17 / 8 ] = ( V_2 [ V_17 / 8 ] & ~ ( 0x80 >> ( unsigned int ) ( V_17 % 8 ) ) ) |
( ( V_19 [ 0 ] & 0x80 ) >> ( unsigned int ) ( V_17 % 8 ) ) ;
}
return 1 ;
}
static int F_14 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
while ( V_4 >= V_12 )
{
F_13 ( V_3 , V_2 , 8 , ( long ) V_12 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
V_4 -= V_12 ;
V_3 += V_12 ;
V_2 += V_12 ;
}
if ( V_4 )
F_13 ( V_3 , V_2 , 8 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_13 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_15 ( T_1 * V_1 , const unsigned char * V_20 ,
const unsigned char * V_13 , int V_21 )
{
V_7 * V_22 = ( V_7 * ) V_20 ;
#ifdef F_16
if ( F_17 ( & V_22 [ 0 ] , & F_4 ( V_1 ) -> V_8 )
! ! F_17 ( & V_22 [ 1 ] , & F_4 ( V_1 ) -> V_9 ) )
return 0 ;
#else
F_18 ( & V_22 [ 0 ] , & F_4 ( V_1 ) -> V_8 ) ;
F_18 ( & V_22 [ 1 ] , & F_4 ( V_1 ) -> V_9 ) ;
#endif
memcpy ( & F_4 ( V_1 ) -> V_10 , & F_4 ( V_1 ) -> V_8 ,
sizeof( F_4 ( V_1 ) -> V_8 ) ) ;
return 1 ;
}
static int F_19 ( T_1 * V_1 , const unsigned char * V_20 ,
const unsigned char * V_13 , int V_21 )
{
V_7 * V_22 = ( V_7 * ) V_20 ;
#ifdef F_8
{
int V_6 ;
printf ( L_5 , V_1 ) ;
printf ( L_6 ) ;
for( V_6 = 0 ; V_6 < 24 ; V_6 ++ ) printf ( L_3 , V_20 [ V_6 ] ) ; printf ( L_4 ) ;
printf ( L_7 ) ;
for( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) printf ( L_3 , V_13 [ V_6 ] ) ; printf ( L_4 ) ;
}
#endif
#ifdef F_16
if ( F_17 ( & V_22 [ 0 ] , & F_4 ( V_1 ) -> V_8 )
|| F_17 ( & V_22 [ 1 ] , & F_4 ( V_1 ) -> V_9 )
|| F_17 ( & V_22 [ 2 ] , & F_4 ( V_1 ) -> V_10 ) )
return 0 ;
#else
F_18 ( & V_22 [ 0 ] , & F_4 ( V_1 ) -> V_8 ) ;
F_18 ( & V_22 [ 1 ] , & F_4 ( V_1 ) -> V_9 ) ;
F_18 ( & V_22 [ 2 ] , & F_4 ( V_1 ) -> V_10 ) ;
#endif
return 1 ;
}
static int F_20 ( T_1 * V_18 , int type , int V_23 , void * V_24 )
{
V_7 * V_22 = V_24 ;
switch( type )
{
case V_25 :
if ( F_21 ( V_24 , V_18 -> V_26 ) <= 0 )
return 0 ;
F_22 ( V_22 ) ;
if ( V_18 -> V_26 >= 16 )
F_22 ( V_22 + 1 ) ;
if ( V_18 -> V_26 >= 24 )
F_22 ( V_22 + 2 ) ;
return 1 ;
default:
return - 1 ;
}
}
const T_3 * F_23 ( void )
{
return & V_27 ;
}
const T_3 * F_24 ( void )
{
return & V_28 ;
}
