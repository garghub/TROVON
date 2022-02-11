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
T_3 V_22 ;
F_5 ( & V_22 ) ;
F_6 ( V_23 ) ;
V_20 = ! F_7 ( & V_24 , & V_22 ) ;
F_8 ( V_23 ) ;
}
else
V_20 = 0 ;
if ( ! V_20 ) F_9 ( V_25 ) ;
V_16 = V_4 ;
V_17 [ 0 ] = V_7 [ 0 ] ;
V_17 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_18 , V_5 , sizeof V_5 ) ;
V_4 += V_11 ;
if ( V_4 >= V_26 )
{
V_4 %= V_26 ;
V_3 = V_26 ;
}
else if ( V_3 < V_26 )
{
if ( V_4 > V_3 )
V_3 = V_4 ;
}
V_7 [ 1 ] += ( V_11 / V_6 ) + ( V_11 % V_6 > 0 ) ;
if ( ! V_20 ) F_10 ( V_25 ) ;
F_11 ( & V_19 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 += V_6 )
{
V_14 = ( V_11 - V_13 ) ;
V_14 = ( V_14 > V_6 ) ? V_6 : V_14 ;
F_12 ( & V_19 ) ;
F_13 ( & V_19 , V_18 , V_6 ) ;
V_15 = ( V_16 + V_14 ) - V_26 ;
if ( V_15 > 0 )
{
F_13 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 - V_15 ) ;
F_13 ( & V_19 , & ( V_2 [ 0 ] ) , V_15 ) ;
}
else
F_13 ( & V_19 , & ( V_2 [ V_16 ] ) , V_14 ) ;
F_13 ( & V_19 , V_10 , V_14 ) ;
F_13 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
F_14 ( & V_19 , V_18 ) ;
V_17 [ 1 ] ++ ;
V_10 = ( const char * ) V_10 + V_14 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
{
V_2 [ V_16 ++ ] ^= V_18 [ V_15 ] ;
if ( V_16 >= V_26 )
V_16 = 0 ;
}
}
F_15 ( & V_19 ) ;
if ( ! V_20 ) F_9 ( V_25 ) ;
for ( V_15 = 0 ; V_15 < ( int ) sizeof( V_5 ) ; V_15 ++ )
{
V_5 [ V_15 ] ^= V_18 [ V_15 ] ;
}
if ( V_8 < V_27 )
V_8 += V_12 ;
if ( ! V_20 ) F_10 ( V_25 ) ;
#if ! F_16 ( V_28 ) && ! F_16 ( V_29 )
assert ( V_17 [ 1 ] == V_7 [ 1 ] ) ;
#endif
}
static void F_17 ( const void * V_10 , int V_11 )
{
F_4 ( V_10 , V_11 , ( double ) V_11 ) ;
}
static int F_18 ( unsigned char * V_10 , int V_11 , int V_30 )
{
static volatile int V_31 = 0 ;
int V_13 , V_14 , V_15 , V_32 , V_16 ;
int V_33 ;
int V_34 ;
long V_17 [ 2 ] ;
unsigned char V_18 [ V_6 ] ;
T_2 V_19 ;
#ifndef F_19
T_4 V_35 = F_20 () ;
#endif
int V_36 = 0 ;
#ifdef F_21
if ( V_37 )
{
static unsigned char V_38 = 0 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_10 [ V_13 ] = V_38 ++ ;
return ( 1 ) ;
}
#endif
if ( V_11 <= 0 )
return 1 ;
F_11 ( & V_19 ) ;
V_33 = ( 1 + ( V_11 - 1 ) / ( V_6 / 2 ) ) * ( V_6 / 2 ) ;
F_9 ( V_25 ) ;
F_9 ( V_23 ) ;
F_5 ( & V_24 ) ;
F_10 ( V_23 ) ;
V_21 = 1 ;
if ( ! V_9 )
{
F_22 () ;
V_9 = 1 ;
}
if ( ! V_31 )
V_36 = 1 ;
V_34 = ( V_8 >= V_27 ) ;
if ( ! V_34 )
{
V_8 -= V_11 ;
if ( V_8 < 0 )
V_8 = 0 ;
}
if ( V_36 )
{
int V_39 = V_26 ;
while ( V_39 > 0 )
{
#if V_6 > 20
# error "Please adjust DUMMY_SEED."
#endif
#define F_23 "...................."
F_4 ( F_23 , V_6 , 0.0 ) ;
V_39 -= V_6 ;
}
if ( V_34 )
V_31 = 1 ;
}
V_16 = V_4 ;
V_32 = V_3 ;
V_17 [ 0 ] = V_7 [ 0 ] ;
V_17 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_18 , V_5 , sizeof V_5 ) ;
V_4 += V_33 ;
if ( V_4 > V_3 )
V_4 %= V_3 ;
V_7 [ 0 ] += 1 ;
V_21 = 0 ;
F_10 ( V_25 ) ;
while ( V_11 > 0 )
{
V_14 = ( V_11 >= V_6 / 2 ) ? V_6 / 2 : V_11 ;
V_11 -= V_14 ;
F_12 ( & V_19 ) ;
#ifndef F_19
if ( V_35 )
{
F_13 ( & V_19 , ( unsigned char * ) & V_35 , sizeof V_35 ) ;
V_35 = 0 ;
}
#endif
F_13 ( & V_19 , V_18 , V_6 ) ;
F_13 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
#ifndef F_24
F_13 ( & V_19 , V_10 , V_14 ) ;
#endif
V_15 = ( V_16 + V_6 / 2 ) - V_32 ;
if ( V_15 > 0 )
{
F_13 ( & V_19 , & ( V_2 [ V_16 ] ) , V_6 / 2 - V_15 ) ;
F_13 ( & V_19 , & ( V_2 [ 0 ] ) , V_15 ) ;
}
else
F_13 ( & V_19 , & ( V_2 [ V_16 ] ) , V_6 / 2 ) ;
F_14 ( & V_19 , V_18 ) ;
for ( V_13 = 0 ; V_13 < V_6 / 2 ; V_13 ++ )
{
V_2 [ V_16 ++ ] ^= V_18 [ V_13 ] ;
if ( V_16 >= V_32 )
V_16 = 0 ;
if ( V_13 < V_14 )
* ( V_10 ++ ) = V_18 [ V_13 + V_6 / 2 ] ;
}
}
F_12 ( & V_19 ) ;
F_13 ( & V_19 , ( unsigned char * ) & ( V_17 [ 0 ] ) , sizeof( V_17 ) ) ;
F_13 ( & V_19 , V_18 , V_6 ) ;
F_9 ( V_25 ) ;
F_13 ( & V_19 , V_5 , V_6 ) ;
F_14 ( & V_19 , V_5 ) ;
F_10 ( V_25 ) ;
F_15 ( & V_19 ) ;
if ( V_34 )
return ( 1 ) ;
else if ( V_30 )
return 0 ;
else
{
F_25 ( V_40 , V_41 ) ;
F_26 ( 1 , L_1
L_2 ) ;
return ( 0 ) ;
}
}
static int F_27 ( unsigned char * V_10 , int V_11 )
{
return F_18 ( V_10 , V_11 , 0 ) ;
}
static int F_28 ( unsigned char * V_10 , int V_11 )
{
return F_18 ( V_10 , V_11 , 1 ) ;
}
static int F_29 ( void )
{
T_3 V_22 ;
int V_42 ;
int V_20 ;
F_5 ( & V_22 ) ;
if ( V_21 )
{
F_6 ( V_23 ) ;
V_20 = ! F_7 ( & V_24 , & V_22 ) ;
F_8 ( V_23 ) ;
}
else
V_20 = 0 ;
if ( ! V_20 )
{
F_9 ( V_25 ) ;
F_9 ( V_23 ) ;
F_30 ( & V_24 , & V_22 ) ;
F_10 ( V_23 ) ;
V_21 = 1 ;
}
if ( ! V_9 )
{
F_22 () ;
V_9 = 1 ;
}
V_42 = V_8 >= V_27 ;
if ( ! V_20 )
{
V_21 = 0 ;
F_10 ( V_25 ) ;
}
return V_42 ;
}
