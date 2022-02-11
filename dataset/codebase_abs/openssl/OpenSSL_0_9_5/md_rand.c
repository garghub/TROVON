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
}
static void F_3 ( const void * V_9 , int V_10 , double V_11 )
{
int V_12 , V_13 , V_14 , V_15 ;
long V_16 [ 2 ] ;
unsigned char V_17 [ V_6 ] ;
T_2 V_18 ;
#ifdef F_4
return;
#endif
F_5 ( V_19 ) ;
V_15 = V_4 ;
V_16 [ 0 ] = V_7 [ 0 ] ;
V_16 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_17 , V_5 , sizeof V_5 ) ;
V_4 += V_10 ;
if ( V_4 >= V_20 )
{
V_4 %= V_20 ;
V_3 = V_20 ;
}
else if ( V_3 < V_20 )
{
if ( V_4 > V_3 )
V_3 = V_4 ;
}
V_7 [ 1 ] += ( V_10 / V_6 ) + ( V_10 % V_6 > 0 ) ;
F_6 ( V_19 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 += V_6 )
{
V_13 = ( V_10 - V_12 ) ;
V_13 = ( V_13 > V_6 ) ? V_6 : V_13 ;
F_7 ( & V_18 ) ;
F_8 ( & V_18 , V_17 , V_6 ) ;
V_14 = ( V_15 + V_13 ) - V_20 ;
if ( V_14 > 0 )
{
F_8 ( & V_18 , & ( V_2 [ V_15 ] ) , V_13 - V_14 ) ;
F_8 ( & V_18 , & ( V_2 [ 0 ] ) , V_14 ) ;
}
else
F_8 ( & V_18 , & ( V_2 [ V_15 ] ) , V_13 ) ;
F_8 ( & V_18 , V_9 , V_13 ) ;
F_8 ( & V_18 , ( unsigned char * ) & ( V_16 [ 0 ] ) , sizeof( V_16 ) ) ;
F_9 ( V_17 , & V_18 ) ;
V_16 [ 1 ] ++ ;
V_9 = ( const char * ) V_9 + V_13 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
{
V_2 [ V_15 ++ ] ^= V_17 [ V_14 ] ;
if ( V_15 >= V_20 )
V_15 = 0 ;
}
}
memset ( ( char * ) & V_18 , 0 , sizeof( V_18 ) ) ;
F_5 ( V_19 ) ;
for ( V_14 = 0 ; V_14 < sizeof V_5 ; V_14 ++ )
{
V_5 [ V_14 ] ^= V_17 [ V_14 ] ;
}
if ( V_8 < V_21 )
V_8 += V_11 ;
F_6 ( V_19 ) ;
#ifndef F_10
assert ( V_16 [ 1 ] == V_7 [ 1 ] ) ;
#endif
}
static void F_11 ( const void * V_9 , int V_10 )
{
F_3 ( V_9 , V_10 , V_10 ) ;
}
static void F_12 ( void )
{
unsigned long V_22 ;
#ifndef F_13
T_3 V_23 = F_14 () ;
#endif
#ifdef F_15
T_4 * V_24 ;
#endif
F_6 ( V_19 ) ;
#ifndef F_13
V_22 = V_23 ;
F_16 ( & V_22 , sizeof( V_22 ) , 0 ) ;
V_22 = F_17 () ;
F_16 ( & V_22 , sizeof( V_22 ) , 0 ) ;
#endif
V_22 = time ( NULL ) ;
F_16 ( & V_22 , sizeof( V_22 ) , 0 ) ;
#ifdef F_15
if ( ( V_24 = fopen ( F_15 , L_1 ) ) != NULL )
{
unsigned char V_25 [ V_21 ] ;
int V_26 ;
setvbuf ( V_24 , NULL , V_27 , 0 ) ;
V_26 = fread ( ( unsigned char * ) V_25 , 1 , V_21 , V_24 ) ;
fclose ( V_24 ) ;
F_16 ( V_25 , sizeof V_25 , V_26 ) ;
memset ( V_25 , 0 , V_26 ) ;
}
#endif
#ifdef F_18
memset ( V_2 , 0 , V_20 ) ;
memset ( V_5 , 0 , V_6 ) ;
#endif
F_5 ( V_19 ) ;
V_28 = 1 ;
}
static int F_19 ( unsigned char * V_9 , int V_10 )
{
int V_12 , V_13 , V_14 , V_29 , V_15 ;
int V_30 ;
long V_16 [ 2 ] ;
unsigned char V_17 [ V_6 ] ;
T_2 V_18 ;
#ifndef F_13
T_3 V_23 = F_14 () ;
#endif
#ifdef F_20
{
static unsigned char V_31 = 0 ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
V_9 [ V_12 ] = V_31 ++ ;
return ( 1 ) ;
}
#endif
F_5 ( V_19 ) ;
if ( ! V_28 )
F_12 () ;
V_30 = ( V_8 >= V_21 ) ;
if ( ! V_30 )
{
V_8 -= V_10 ;
if ( V_8 < 0 )
V_8 = 0 ;
}
V_15 = V_4 ;
V_29 = V_3 ;
V_16 [ 0 ] = V_7 [ 0 ] ;
V_16 [ 1 ] = V_7 [ 1 ] ;
memcpy ( V_17 , V_5 , sizeof V_5 ) ;
V_4 += V_10 ;
if ( V_4 > V_3 )
V_4 %= V_3 ;
V_7 [ 0 ] += 1 ;
F_6 ( V_19 ) ;
while ( V_10 > 0 )
{
V_13 = ( V_10 >= V_6 / 2 ) ? V_6 / 2 : V_10 ;
V_10 -= V_13 ;
F_7 ( & V_18 ) ;
#ifndef F_13
if ( V_23 )
{
F_8 ( & V_18 , ( unsigned char * ) & V_23 , sizeof V_23 ) ;
V_23 = 0 ;
}
#endif
F_8 ( & V_18 , & ( V_17 [ V_6 / 2 ] ) , V_6 / 2 ) ;
F_8 ( & V_18 , ( unsigned char * ) & ( V_16 [ 0 ] ) , sizeof( V_16 ) ) ;
#ifndef F_18
F_8 ( & V_18 , V_9 , V_13 ) ;
#endif
V_14 = ( V_15 + V_13 ) - V_29 ;
if ( V_14 > 0 )
{
F_8 ( & V_18 , & ( V_2 [ V_15 ] ) , V_13 - V_14 ) ;
F_8 ( & V_18 , & ( V_2 [ 0 ] ) , V_14 ) ;
}
else
F_8 ( & V_18 , & ( V_2 [ V_15 ] ) , V_13 ) ;
F_9 ( V_17 , & V_18 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
{
V_2 [ V_15 ++ ] ^= V_17 [ V_12 ] ;
* ( V_9 ++ ) = V_17 [ V_12 + V_6 / 2 ] ;
if ( V_15 >= V_29 )
V_15 = 0 ;
}
}
F_7 ( & V_18 ) ;
F_8 ( & V_18 , ( unsigned char * ) & ( V_16 [ 0 ] ) , sizeof( V_16 ) ) ;
F_8 ( & V_18 , V_17 , V_6 ) ;
F_5 ( V_19 ) ;
F_8 ( & V_18 , V_5 , V_6 ) ;
F_9 ( V_5 , & V_18 ) ;
F_6 ( V_19 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
if ( V_30 )
return ( 1 ) ;
else
{
F_21 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
}
static int F_22 ( unsigned char * V_9 , int V_10 )
{
int V_34 , V_35 ;
V_34 = F_23 ( V_9 , V_10 ) ;
if ( V_34 == 0 )
{
V_35 = F_24 () ;
if ( F_25 ( V_35 ) == V_36 &&
F_26 ( V_35 ) == V_33 )
( void ) F_27 () ;
}
return ( V_34 ) ;
}
int F_28 ( void )
{
if ( ! V_28 )
F_12 () ;
return ( V_8 >= V_21 ) ;
}
void F_29 ( void )
{
T_5 V_37 ;
T_5 V_38 ;
T_6 V_39 ;
T_6 V_40 ;
T_7 V_41 ;
unsigned int V_42 ;
char * V_43 ;
int V_44 ;
int V_45 ;
int V_46 ;
int V_26 = 16 ;
V_37 = F_30 ( L_2 , NULL , NULL , NULL ) ;
V_38 = F_31 ( V_37 ) ;
V_44 = F_32 ( V_37 , V_47 ) ;
V_45 = F_32 ( V_37 , V_48 ) ;
V_39 = F_33 ( V_37 , V_44 , V_26 ) ;
V_40 = F_34 ( V_38 , V_39 ) ;
F_35 ( V_39 , sizeof( T_7 ) , ( V_49 ) & V_41 ) ;
V_42 = ( unsigned int ) V_41 . V_50 * V_41 . V_51 * V_41 . V_52 ;
V_43 = Malloc ( V_42 ) ;
if ( V_43 ) {
for ( V_46 = 0 ; V_46 < V_45 - V_26 ; V_46 += V_26 )
{
unsigned char V_5 [ V_6 ] ;
F_36 ( V_38 , 0 , 0 , V_44 , V_26 , V_37 , 0 , V_46 , V_53 ) ;
F_37 ( V_39 , V_42 , V_43 ) ;
F_38 ( V_43 , V_42 , V_5 ) ;
F_39 ( V_5 , V_6 ) ;
}
Free ( V_43 ) ;
}
V_39 = F_34 ( V_38 , V_40 ) ;
F_40 ( V_39 ) ;
F_41 ( V_38 ) ;
F_41 ( V_37 ) ;
}
