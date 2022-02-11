T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( void )
{
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_3 = 0 ;
V_4 = 0 ;
memset ( V_5 , 0 , V_6 ) ;
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = 0 ;
V_8 = 0 ;
V_9 = 0 ;
}
static void F_3 ( const void * V_10 , int V_11 , double V_12 )
{
int V_13 , V_14 , V_15 , V_16 ;
long V_17 [ 2 ] ;
unsigned char V_18 [ V_6 ] ;
T_2 V_19 ;
if ( ! V_20 ) F_4 ( V_21 ) ;
V_16 = V_4 ;
V_17 [ 0 ] = V_7 [ 0 ] ;
V_17 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_18 , V_5 , sizeof V_5 ) ;
V_4 += V_11 ;
if ( V_4 >= V_22 )
{
V_4 %= V_22 ;
V_3 = V_22 ;
}
else if ( V_3 < V_22 )
{
if ( V_4 > V_3 )
V_3 = V_4 ;
}
V_7 [ 1 ] += ( V_11 / V_6 ) + ( V_11 % V_6 > 0 ) ;
if ( ! V_20 ) F_5 ( V_21 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 += V_6 )
{
V_14 = ( V_11 - V_13 ) ;
V_14 = ( V_14 > V_6 ) ? V_6 : V_14 ;
F_6 ( & V_19 ) ;
F_7 ( & V_19 , V_18 , V_6 ) ;
V_15 = ( V_16 + V_14 ) - V_22 ;
if ( V_15 > 0 )
{
F_7 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 - V_15 ) ;
F_7 ( & V_19 , & ( V_2 [ 0 ] ) , V_15 ) ;
}
else
F_7 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 ) ;
F_7 ( & V_19 , V_10 , V_14 ) ;
F_7 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
F_8 ( V_18 , & V_19 ) ;
V_17 [ 1 ] ++ ;
V_10 = ( const char * ) V_10 + V_14 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
{
V_2 [ V_16 ++ ] ^= V_18 [ V_15 ] ;
if ( V_16 >= V_22 )
V_16 = 0 ;
}
}
memset ( ( char * ) & V_19 , 0 , sizeof( V_19 ) ) ;
if ( ! V_20 ) F_4 ( V_21 ) ;
for ( V_15 = 0 ; V_15 < sizeof V_5 ; V_15 ++ )
{
V_5 [ V_15 ] ^= V_18 [ V_15 ] ;
}
if ( V_8 < V_23 )
V_8 += V_12 ;
if ( ! V_20 ) F_5 ( V_21 ) ;
#if ! F_9 ( V_24 ) && ! F_9 ( V_25 )
assert ( V_17 [ 1 ] == V_7 [ 1 ] ) ;
#endif
}
static void F_10 ( const void * V_10 , int V_11 )
{
F_3 ( V_10 , V_11 , V_11 ) ;
}
static int F_11 ( unsigned char * V_10 , int V_11 )
{
static volatile int V_26 = 0 ;
int V_13 , V_14 , V_15 , V_27 , V_16 ;
int V_28 ;
long V_17 [ 2 ] ;
unsigned char V_18 [ V_6 ] ;
T_2 V_19 ;
#ifndef F_12
T_3 V_29 = F_13 () ;
#endif
int V_30 = 0 ;
#ifdef F_14
if ( V_31 )
{
static unsigned char V_32 = 0 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_10 [ V_13 ] = V_32 ++ ;
return ( 1 ) ;
}
#endif
if ( ! V_9 )
F_15 () ;
F_4 ( V_21 ) ;
V_20 = 1 ;
V_9 = 1 ;
if ( ! V_26 )
V_30 = 1 ;
V_28 = ( V_8 >= V_23 ) ;
if ( ! V_28 )
{
V_8 -= V_11 ;
if ( V_8 < 0 )
V_8 = 0 ;
}
if ( V_30 )
{
int V_33 = V_22 ;
while ( V_33 > 0 )
{
#if V_6 > 20
# error "Please adjust DUMMY_SEED."
#endif
#define F_16 "...................."
F_3 ( F_16 , V_6 , 0.0 ) ;
V_33 -= V_6 ;
}
if ( V_28 )
V_26 = 1 ;
}
V_16 = V_4 ;
V_27 = V_3 ;
V_17 [ 0 ] = V_7 [ 0 ] ;
V_17 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_18 , V_5 , sizeof V_5 ) ;
V_4 += V_11 ;
if ( V_4 > V_3 )
V_4 %= V_3 ;
V_7 [ 0 ] += 1 ;
V_20 = 0 ;
F_5 ( V_21 ) ;
while ( V_11 > 0 )
{
V_14 = ( V_11 >= V_6 / 2 ) ? V_6 / 2 : V_11 ;
V_11 -= V_14 ;
F_6 ( & V_19 ) ;
#ifndef F_12
if ( V_29 )
{
F_7 ( & V_19 , ( unsigned char * ) & V_29 , sizeof V_29 ) ;
V_29 = 0 ;
}
#endif
F_7 ( & V_19 , & ( V_18 [ V_6 / 2 ] ) , V_6 / 2 ) ;
F_7 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
#ifndef F_17
F_7 ( & V_19 , V_10 , V_14 ) ;
#endif
V_15 = ( V_16 + V_14 ) - V_27 ;
if ( V_15 > 0 )
{
F_7 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 - V_15 ) ;
F_7 ( & V_19 , & ( V_2 [ 0 ] ) , V_15 ) ;
}
else
F_7 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 ) ;
F_8 ( V_18 , & V_19 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
{
V_2 [ V_16 ++ ] ^= V_18 [ V_13 ] ;
* ( V_10 ++ ) = V_18 [ V_13 + V_6 / 2 ] ;
if ( V_16 >= V_27 )
V_16 = 0 ;
}
}
F_6 ( & V_19 ) ;
F_7 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
F_7 ( & V_19 , V_18 , V_6 ) ;
F_4 ( V_21 ) ;
F_7 ( & V_19 , V_5 , V_6 ) ;
F_8 ( V_5 , & V_19 ) ;
F_5 ( V_21 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
if ( V_28 )
return ( 1 ) ;
else
{
F_18 ( V_34 , V_35 ) ;
F_19 ( 1 , L_1
L_2 ) ;
return ( 0 ) ;
}
}
static int F_20 ( unsigned char * V_10 , int V_11 )
{
int V_36 , V_37 ;
V_36 = F_21 ( V_10 , V_11 ) ;
if ( V_36 == 0 )
{
V_37 = F_22 () ;
if ( F_23 ( V_37 ) == V_38 &&
F_24 ( V_37 ) == V_35 )
( void ) F_25 () ;
}
return ( V_36 ) ;
}
static int F_26 ( void )
{
int V_36 ;
if ( ! V_9 )
F_15 () ;
F_4 ( V_21 ) ;
V_9 = 1 ;
V_36 = V_8 >= V_23 ;
F_5 ( V_21 ) ;
return V_36 ;
}
