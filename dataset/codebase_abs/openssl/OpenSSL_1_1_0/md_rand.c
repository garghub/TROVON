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
F_4 ( V_10 ) ;
F_4 ( V_11 ) ;
}
static int F_5 ( const void * V_12 , int V_13 , double V_14 )
{
int V_15 , V_16 , V_17 , V_18 ;
long V_19 [ 2 ] ;
unsigned char V_20 [ V_6 ] ;
T_2 * V_21 ;
int V_22 ;
int V_23 = 0 ;
if ( ! V_13 )
return 1 ;
V_21 = F_6 () ;
if ( V_21 == NULL )
goto V_24;
if ( ! F_7 ( & V_25 , V_26 ) )
goto V_24;
if ( V_27 ) {
T_3 V_28 = F_8 () ;
F_9 ( V_11 ) ;
V_22 = F_10 ( V_29 , V_28 ) ;
F_11 ( V_11 ) ;
} else
V_22 = 0 ;
if ( ! V_22 )
F_12 ( V_10 ) ;
V_18 = V_4 ;
V_19 [ 0 ] = V_7 [ 0 ] ;
V_19 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_20 , V_5 , sizeof V_5 ) ;
V_4 += V_13 ;
if ( V_4 >= V_30 ) {
V_4 %= V_30 ;
V_3 = V_30 ;
} else if ( V_3 < V_30 ) {
if ( V_4 > V_3 )
V_3 = V_4 ;
}
V_7 [ 1 ] += ( V_13 / V_6 ) + ( V_13 % V_6 > 0 ) ;
if ( ! V_22 )
F_11 ( V_10 ) ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 += V_6 ) {
V_16 = ( V_13 - V_15 ) ;
V_16 = ( V_16 > V_6 ) ? V_6 : V_16 ;
if ( ! F_13 ( V_21 ) )
goto V_24;
if ( ! F_14 ( V_21 , V_20 , V_6 ) )
goto V_24;
V_17 = ( V_18 + V_16 ) - V_30 ;
if ( V_17 > 0 ) {
if ( ! F_14 ( V_21 , & ( V_2 [ V_18 ] ) , V_16 - V_17 ) )
goto V_24;
if ( ! F_14 ( V_21 , & ( V_2 [ 0 ] ) , V_17 ) )
goto V_24;
} else if ( ! F_14 ( V_21 , & ( V_2 [ V_18 ] ) , V_16 ) )
goto V_24;
if ( ! F_14 ( V_21 , V_12 , V_16 ) )
goto V_24;
if ( ! F_14 ( V_21 , ( unsigned char * ) & ( V_19 [ 0 ] ) , sizeof( V_19 ) ) )
goto V_24;
if ( ! F_15 ( V_21 , V_20 ) )
goto V_24;
V_19 [ 1 ] ++ ;
V_12 = ( const char * ) V_12 + V_16 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
V_2 [ V_18 ++ ] ^= V_20 [ V_17 ] ;
if ( V_18 >= V_30 )
V_18 = 0 ;
}
}
if ( ! V_22 )
F_12 ( V_10 ) ;
for ( V_17 = 0 ; V_17 < ( int ) sizeof( V_5 ) ; V_17 ++ ) {
V_5 [ V_17 ] ^= V_20 [ V_17 ] ;
}
if ( V_8 < V_31 )
V_8 += V_14 ;
if ( ! V_22 )
F_11 ( V_10 ) ;
V_23 = 1 ;
V_24:
F_16 ( V_21 ) ;
return V_23 ;
}
static int F_17 ( const void * V_12 , int V_13 )
{
return F_5 ( V_12 , V_13 , ( double ) V_13 ) ;
}
static int F_18 ( unsigned char * V_12 , int V_13 , int V_32 )
{
static volatile int V_33 = 0 ;
int V_15 , V_16 , V_17 ;
T_4 V_34 , V_18 , V_35 ;
int V_36 ;
long V_19 [ 2 ] ;
unsigned char V_20 [ V_6 ] ;
T_2 * V_21 ;
#ifndef F_19
T_5 V_37 = F_20 () ;
#endif
T_6 V_38 = time ( NULL ) ;
int V_39 = 0 ;
#ifdef F_21
T_7 V_40 ;
# ifdef F_22
T_8 V_41 ;
F_23 ( & V_41 ) ;
F_24 ( & V_41 , & V_40 ) ;
# else
F_25 ( & V_40 ) ;
# endif
#elif F_26 ( V_42 )
struct V_43 V_40 ;
F_27 ( V_44 , & V_45 ) ;
#elif F_26 ( V_46 )
unsigned long long V_40 , V_47 () ;
V_40 = V_47 () ;
#else
struct V_48 V_40 ;
F_28 ( & V_40 , NULL ) ;
#endif
#ifdef F_29
if ( V_49 ) {
static unsigned char V_50 = 0 ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_12 [ V_15 ] = V_50 ++ ;
return ( 1 ) ;
}
#endif
if ( V_13 <= 0 )
return 1 ;
V_21 = F_6 () ;
if ( V_21 == NULL )
goto V_51;
V_34 =
( 1 + ( V_13 - 1 ) / ( V_6 / 2 ) ) * ( V_6 / 2 ) ;
if ( ! F_7 ( & V_25 , V_26 ) )
goto V_51;
F_12 ( V_10 ) ;
F_30 () ;
F_12 ( V_11 ) ;
V_29 = F_8 () ;
F_11 ( V_11 ) ;
V_27 = 1 ;
if ( ! V_9 ) {
F_31 () ;
V_9 = 1 ;
}
if ( ! V_33 )
V_39 = 1 ;
V_36 = ( V_8 >= V_31 ) ;
if ( ! V_36 ) {
V_8 -= V_13 ;
if ( V_8 < 0 )
V_8 = 0 ;
}
if ( V_39 ) {
int V_52 = V_30 ;
while ( V_52 > 0 ) {
#if V_6 > 20
# error "Please adjust DUMMY_SEED."
#endif
#define F_32 "...................."
F_5 ( F_32 , V_6 , 0.0 ) ;
V_52 -= V_6 ;
}
if ( V_36 )
V_33 = 1 ;
}
V_18 = V_4 ;
V_35 = V_3 ;
V_19 [ 0 ] = V_7 [ 0 ] ;
V_19 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_20 , V_5 , sizeof V_5 ) ;
V_4 += V_34 ;
if ( V_4 > V_3 )
V_4 %= V_3 ;
V_7 [ 0 ] += 1 ;
V_27 = 0 ;
F_33 () ;
F_11 ( V_10 ) ;
while ( V_13 > 0 ) {
V_16 = ( V_13 >= V_6 / 2 ) ? V_6 / 2 : V_13 ;
V_13 -= V_16 ;
if ( ! F_13 ( V_21 ) )
goto V_24;
#ifndef F_19
if ( V_37 ) {
if ( ! F_14 ( V_21 , ( unsigned char * ) & V_37 , sizeof V_37 ) )
goto V_24;
V_37 = 0 ;
}
#endif
if ( V_38 ) {
if ( ! F_14 ( V_21 , ( unsigned char * ) & V_38 , sizeof V_38 ) )
goto V_24;
if ( ! F_14 ( V_21 , ( unsigned char * ) & V_40 , sizeof V_40 ) )
goto V_24;
V_38 = 0 ;
if ( ! F_34 ( V_21 ) )
goto V_24;
}
if ( ! F_14 ( V_21 , V_20 , V_6 ) )
goto V_24;
if ( ! F_14 ( V_21 , ( unsigned char * ) & ( V_19 [ 0 ] ) , sizeof( V_19 ) ) )
goto V_24;
V_17 = ( V_18 + V_6 / 2 ) - V_35 ;
if ( V_17 > 0 ) {
if ( ! F_14 ( V_21 , & ( V_2 [ V_18 ] ) , V_6 / 2 - V_17 ) )
goto V_24;
if ( ! F_14 ( V_21 , & ( V_2 [ 0 ] ) , V_17 ) )
goto V_24;
} else if ( ! F_14 ( V_21 , & ( V_2 [ V_18 ] ) , V_6 / 2 ) )
goto V_24;
if ( ! F_15 ( V_21 , V_20 ) )
goto V_24;
for ( V_15 = 0 ; V_15 < V_6 / 2 ; V_15 ++ ) {
V_2 [ V_18 ++ ] ^= V_20 [ V_15 ] ;
if ( V_18 >= V_35 )
V_18 = 0 ;
if ( V_15 < V_16 )
* ( V_12 ++ ) = V_20 [ V_15 + V_6 / 2 ] ;
}
}
if ( ! F_13 ( V_21 )
|| ! F_14 ( V_21 , ( unsigned char * ) & ( V_19 [ 0 ] ) , sizeof( V_19 ) )
|| ! F_14 ( V_21 , V_20 , V_6 ) )
goto V_24;
F_12 ( V_10 ) ;
F_30 () ;
if ( ! F_14 ( V_21 , V_5 , V_6 ) || ! F_15 ( V_21 , V_5 ) ) {
F_11 ( V_10 ) ;
goto V_24;
}
F_33 () ;
F_11 ( V_10 ) ;
F_16 ( V_21 ) ;
if ( V_36 )
return ( 1 ) ;
else if ( V_32 )
return 0 ;
else {
F_35 ( V_53 , V_54 ) ;
F_36 ( 1 , L_1
L_2 ) ;
return ( 0 ) ;
}
V_24:
F_35 ( V_53 , V_55 ) ;
F_16 ( V_21 ) ;
return 0 ;
V_51:
F_35 ( V_53 , V_56 ) ;
F_16 ( V_21 ) ;
return 0 ;
}
static int F_37 ( unsigned char * V_12 , int V_13 )
{
return F_18 ( V_12 , V_13 , 0 ) ;
}
static int F_38 ( unsigned char * V_12 , int V_13 )
{
return F_18 ( V_12 , V_13 , 1 ) ;
}
static int F_39 ( void )
{
T_3 V_28 ;
int V_57 ;
int V_22 ;
if ( ! F_7 ( & V_25 , V_26 ) )
return 0 ;
V_28 = F_8 () ;
if ( V_27 ) {
F_9 ( V_11 ) ;
V_22 = F_10 ( V_29 , V_28 ) ;
F_11 ( V_11 ) ;
} else
V_22 = 0 ;
if ( ! V_22 ) {
F_12 ( V_10 ) ;
F_30 () ;
F_12 ( V_11 ) ;
V_29 = V_28 ;
F_11 ( V_11 ) ;
V_27 = 1 ;
}
if ( ! V_9 ) {
F_31 () ;
V_9 = 1 ;
}
V_57 = V_8 >= V_31 ;
if ( ! V_22 ) {
V_27 = 0 ;
F_33 () ;
F_11 ( V_10 ) ;
}
return V_57 ;
}
static int F_34 ( T_2 * V_58 )
{
int V_15 ;
if ( ! ( V_59 [ 1 ] & ( 1 << ( 62 - 32 ) ) ) )
return 1 ;
for ( V_15 = 0 ; V_15 < V_60 ; V_15 ++ ) {
T_4 V_61 ;
V_61 = F_40 () ;
if ( V_61 == 0 )
return 1 ;
if ( ! F_14 ( V_58 , ( unsigned char * ) & V_61 , sizeof( T_4 ) ) )
return 0 ;
}
return 1 ;
}
void F_41 ( unsigned char * V_12 , T_4 V_13 )
{
T_4 V_61 ;
if ( ! ( V_59 [ 1 ] & ( 1 << ( 62 - 32 ) ) ) )
return;
while ( V_13 >= sizeof( T_4 ) ) {
V_61 = F_40 () ;
if ( V_61 == 0 )
return;
* ( ( T_4 * ) V_12 ) ^= V_61 ;
V_12 += sizeof( T_4 ) ;
V_13 -= sizeof( T_4 ) ;
}
if ( V_13 ) {
V_61 = F_40 () ;
if ( V_61 == 0 )
return;
while ( V_13 ) {
* V_12 ^= V_61 & 0xff ;
V_61 >>= 8 ;
V_12 ++ ;
V_13 -- ;
}
}
}
static int F_34 ( T_2 * V_58 )
{
return 1 ;
}
void F_41 ( unsigned char * V_12 , T_4 V_13 )
{
return;
}
