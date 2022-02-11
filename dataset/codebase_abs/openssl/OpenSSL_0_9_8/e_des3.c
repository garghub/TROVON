static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
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
const unsigned char * V_3 , unsigned int V_4 )
{
F_6 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_12 , & V_1 -> V_13 ) ;
return 1 ;
}
static int F_7 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
#ifdef F_8
{
int V_6 ;
char * V_14 ;
printf ( L_1 , V_1 , V_1 -> V_15 ) ;
printf ( L_2 ) ;
for( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
printf ( L_3 , V_1 -> V_12 [ V_6 ] ) ;
printf ( L_4 ) ;
}
#endif
F_9 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_12 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_11 ( V_3 , V_2 , ( long ) V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_12 , & V_1 -> V_13 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
unsigned int V_16 ;
unsigned char V_17 [ 1 ] , V_18 [ 1 ] ;
for( V_16 = 0 ; V_16 < V_4 ; ++ V_16 )
{
V_17 [ 0 ] = ( V_3 [ V_16 / 8 ] & ( 1 << ( 7 - V_16 % 8 ) ) ) ? 0x80 : 0 ;
F_13 ( V_17 , V_18 , 1 , 1 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_12 , V_1 -> V_11 ) ;
V_2 [ V_16 / 8 ] = ( V_2 [ V_16 / 8 ] & ~ ( 0x80 >> ( V_16 % 8 ) ) ) | ( ( V_18 [ 0 ] & 0x80 ) >> ( V_16 % 8 ) ) ;
}
return 1 ;
}
static int F_14 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_13 ( V_3 , V_2 , 8 , V_4 ,
& F_4 ( V_1 ) -> V_8 , & F_4 ( V_1 ) -> V_9 , & F_4 ( V_1 ) -> V_10 ,
( V_7 * ) V_1 -> V_12 , V_1 -> V_11 ) ;
return 1 ;
}
static int F_15 ( T_1 * V_1 , const unsigned char * V_19 ,
const unsigned char * V_12 , int V_20 )
{
V_7 * V_21 = ( V_7 * ) V_19 ;
#ifdef F_16
if ( F_17 ( & V_21 [ 0 ] , & F_4 ( V_1 ) -> V_8 )
! ! F_17 ( & V_21 [ 1 ] , & F_4 ( V_1 ) -> V_9 ) )
return 0 ;
#else
F_18 ( & V_21 [ 0 ] , & F_4 ( V_1 ) -> V_8 ) ;
F_18 ( & V_21 [ 1 ] , & F_4 ( V_1 ) -> V_9 ) ;
#endif
memcpy ( & F_4 ( V_1 ) -> V_10 , & F_4 ( V_1 ) -> V_8 ,
sizeof( F_4 ( V_1 ) -> V_8 ) ) ;
return 1 ;
}
static int F_19 ( T_1 * V_1 , const unsigned char * V_19 ,
const unsigned char * V_12 , int V_20 )
{
V_7 * V_21 = ( V_7 * ) V_19 ;
#ifdef F_8
{
int V_6 ;
printf ( L_5 , V_1 ) ;
printf ( L_6 ) ;
for( V_6 = 0 ; V_6 < 24 ; V_6 ++ ) printf ( L_3 , V_19 [ V_6 ] ) ; printf ( L_4 ) ;
printf ( L_7 ) ;
for( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) printf ( L_3 , V_12 [ V_6 ] ) ; printf ( L_4 ) ;
}
#endif
#ifdef F_16
if ( F_17 ( & V_21 [ 0 ] , & F_4 ( V_1 ) -> V_8 )
|| F_17 ( & V_21 [ 1 ] , & F_4 ( V_1 ) -> V_9 )
|| F_17 ( & V_21 [ 2 ] , & F_4 ( V_1 ) -> V_10 ) )
return 0 ;
#else
F_18 ( & V_21 [ 0 ] , & F_4 ( V_1 ) -> V_8 ) ;
F_18 ( & V_21 [ 1 ] , & F_4 ( V_1 ) -> V_9 ) ;
F_18 ( & V_21 [ 2 ] , & F_4 ( V_1 ) -> V_10 ) ;
#endif
return 1 ;
}
static int F_20 ( T_1 * V_17 , int type , int V_22 , void * V_23 )
{
V_7 * V_21 = V_23 ;
switch( type )
{
case V_24 :
if ( F_21 ( V_23 , V_17 -> V_25 ) <= 0 )
return 0 ;
F_22 ( V_21 ) ;
if ( V_17 -> V_25 >= 16 )
F_22 ( V_21 + 1 ) ;
if ( V_17 -> V_25 >= 24 )
F_22 ( V_21 + 2 ) ;
return 1 ;
default:
return - 1 ;
}
}
const T_2 * F_23 ( void )
{
return & V_26 ;
}
const T_2 * F_24 ( void )
{
return & V_27 ;
}
