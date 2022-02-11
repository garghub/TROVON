T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( void )
{
F_3 ( V_2 , sizeof( V_2 ) ) ;
V_3 = 0 ;
V_4 = 0 ;
F_3 ( V_5 , V_6 ) ;
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = 0 ;
V_8 = 0 ;
V_9 = 0 ;
}
static void F_4 ( const void * V_10 , int V_11 , double V_12 )
{
int V_13 , V_14 , V_15 , V_16 ;
long V_17 [ 2 ] ;
unsigned char V_18 [ V_6 ] ;
T_2 V_19 ;
int V_20 ;
if ( V_21 )
{
F_5 ( V_22 ) ;
V_20 = ( V_23 == F_6 () ) ;
F_7 ( V_22 ) ;
}
else
V_20 = 0 ;
if ( ! V_20 ) F_8 ( V_24 ) ;
V_16 = V_4 ;
V_17 [ 0 ] = V_7 [ 0 ] ;
V_17 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_18 , V_5 , sizeof V_5 ) ;
V_4 += V_11 ;
if ( V_4 >= V_25 )
{
V_4 %= V_25 ;
V_3 = V_25 ;
}
else if ( V_3 < V_25 )
{
if ( V_4 > V_3 )
V_3 = V_4 ;
}
V_7 [ 1 ] += ( V_11 / V_6 ) + ( V_11 % V_6 > 0 ) ;
if ( ! V_20 ) F_9 ( V_24 ) ;
F_10 ( & V_19 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 += V_6 )
{
V_14 = ( V_11 - V_13 ) ;
V_14 = ( V_14 > V_6 ) ? V_6 : V_14 ;
F_11 ( & V_19 ) ;
F_12 ( & V_19 , V_18 , V_6 ) ;
V_15 = ( V_16 + V_14 ) - V_25 ;
if ( V_15 > 0 )
{
F_12 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 - V_15 ) ;
F_12 ( & V_19 , & ( V_2 [ 0 ] ) , V_15 ) ;
}
else
F_12 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 ) ;
F_12 ( & V_19 , V_10 , V_14 ) ;
F_12 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
F_13 ( & V_19 , V_18 ) ;
V_17 [ 1 ] ++ ;
V_10 = ( const char * ) V_10 + V_14 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
{
V_2 [ V_16 ++ ] ^= V_18 [ V_15 ] ;
if ( V_16 >= V_25 )
V_16 = 0 ;
}
}
F_14 ( & V_19 ) ;
if ( ! V_20 ) F_8 ( V_24 ) ;
for ( V_15 = 0 ; V_15 < sizeof V_5 ; V_15 ++ )
{
V_5 [ V_15 ] ^= V_18 [ V_15 ] ;
}
if ( V_8 < V_26 )
V_8 += V_12 ;
if ( ! V_20 ) F_9 ( V_24 ) ;
#if ! F_15 ( V_27 ) && ! F_15 ( V_28 )
assert ( V_17 [ 1 ] == V_7 [ 1 ] ) ;
#endif
}
static void F_16 ( const void * V_10 , int V_11 )
{
F_4 ( V_10 , V_11 , V_11 ) ;
}
static int F_17 ( unsigned char * V_10 , int V_11 )
{
static volatile int V_29 = 0 ;
int V_13 , V_14 , V_15 , V_30 , V_16 ;
int V_31 ;
int V_32 ;
long V_17 [ 2 ] ;
unsigned char V_18 [ V_6 ] ;
T_2 V_19 ;
#ifndef F_18
T_3 V_33 = F_19 () ;
#endif
int V_34 = 0 ;
#ifdef F_20
if ( V_35 )
{
static unsigned char V_36 = 0 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_10 [ V_13 ] = V_36 ++ ;
return ( 1 ) ;
}
#endif
if ( V_11 <= 0 )
return 1 ;
F_10 ( & V_19 ) ;
V_31 = ( 1 + ( V_11 - 1 ) / ( V_6 / 2 ) ) * ( V_6 / 2 ) ;
F_8 ( V_24 ) ;
F_8 ( V_22 ) ;
V_23 = F_6 () ;
F_9 ( V_22 ) ;
V_21 = 1 ;
if ( ! V_9 )
{
F_21 () ;
V_9 = 1 ;
}
if ( ! V_29 )
V_34 = 1 ;
V_32 = ( V_8 >= V_26 ) ;
if ( ! V_32 )
{
V_8 -= V_11 ;
if ( V_8 < 0 )
V_8 = 0 ;
}
if ( V_34 )
{
int V_37 = V_25 ;
while ( V_37 > 0 )
{
#if V_6 > 20
# error "Please adjust DUMMY_SEED."
#endif
#define F_22 "...................."
F_4 ( F_22 , V_6 , 0.0 ) ;
V_37 -= V_6 ;
}
if ( V_32 )
V_29 = 1 ;
}
V_16 = V_4 ;
V_30 = V_3 ;
V_17 [ 0 ] = V_7 [ 0 ] ;
V_17 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_18 , V_5 , sizeof V_5 ) ;
V_4 += V_31 ;
if ( V_4 > V_3 )
V_4 %= V_3 ;
V_7 [ 0 ] += 1 ;
V_21 = 0 ;
F_9 ( V_24 ) ;
while ( V_11 > 0 )
{
V_14 = ( V_11 >= V_6 / 2 ) ? V_6 / 2 : V_11 ;
V_11 -= V_14 ;
F_11 ( & V_19 ) ;
#ifndef F_18
if ( V_33 )
{
F_12 ( & V_19 , ( unsigned char * ) & V_33 , sizeof V_33 ) ;
V_33 = 0 ;
}
#endif
F_12 ( & V_19 , V_18 , V_6 ) ;
F_12 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
#ifndef F_23
F_12 ( & V_19 , V_10 , V_14 ) ;
#endif
V_15 = ( V_16 + V_6 / 2 ) - V_30 ;
if ( V_15 > 0 )
{
F_12 ( & V_19 , & ( V_2 [ V_16 ] ) , V_6 / 2 - V_15 ) ;
F_12 ( & V_19 , & ( V_2 [ 0 ] ) , V_15 ) ;
}
else
F_12 ( & V_19 , & ( V_2 [ V_16 ] ) , V_6 / 2 ) ;
F_13 ( & V_19 , V_18 ) ;
for ( V_13 = 0 ; V_13 < V_6 / 2 ; V_13 ++ )
{
V_2 [ V_16 ++ ] ^= V_18 [ V_13 ] ;
if ( V_16 >= V_30 )
V_16 = 0 ;
if ( V_13 < V_14 )
* ( V_10 ++ ) = V_18 [ V_13 + V_6 / 2 ] ;
}
}
F_11 ( & V_19 ) ;
F_12 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
F_12 ( & V_19 , V_18 , V_6 ) ;
F_8 ( V_24 ) ;
F_12 ( & V_19 , V_5 , V_6 ) ;
F_13 ( & V_19 , V_5 ) ;
F_9 ( V_24 ) ;
F_14 ( & V_19 ) ;
if ( V_32 )
return ( 1 ) ;
else
{
F_24 ( V_38 , V_39 ) ;
F_25 ( 1 , L_1
L_2 ) ;
return ( 0 ) ;
}
}
static int F_26 ( unsigned char * V_10 , int V_11 )
{
int V_40 ;
unsigned long V_41 ;
V_40 = F_27 ( V_10 , V_11 ) ;
if ( V_40 == 0 )
{
V_41 = F_28 () ;
if ( F_29 ( V_41 ) == V_42 &&
F_30 ( V_41 ) == V_39 )
( void ) F_31 () ;
}
return ( V_40 ) ;
}
static int F_32 ( void )
{
int V_40 ;
int V_20 ;
if ( V_21 )
{
F_5 ( V_22 ) ;
V_20 = ( V_23 == F_6 () ) ;
F_7 ( V_22 ) ;
}
else
V_20 = 0 ;
if ( ! V_20 )
{
F_8 ( V_24 ) ;
F_8 ( V_22 ) ;
V_23 = F_6 () ;
F_9 ( V_22 ) ;
V_21 = 1 ;
}
if ( ! V_9 )
{
F_21 () ;
V_9 = 1 ;
}
V_40 = V_8 >= V_26 ;
if ( ! V_20 )
{
V_21 = 0 ;
F_9 ( V_24 ) ;
}
return V_40 ;
}
