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
}
static void F_3 ( const void * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 , V_13 , V_14 ;
T_2 V_15 ;
#ifdef F_4
return;
#endif
F_5 ( V_16 ) ;
V_13 = V_4 ;
V_14 = V_3 ;
V_4 = ( V_4 + V_9 ) ;
if ( V_4 >= V_17 )
{
V_4 %= V_17 ;
V_3 = V_17 ;
}
else if ( V_3 < V_17 )
{
if ( V_4 > V_3 )
V_3 = V_4 ;
}
F_6 ( V_16 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 += V_6 )
{
V_11 = ( V_9 - V_10 ) ;
V_11 = ( V_11 > V_6 ) ? V_6 : V_11 ;
F_7 ( & V_15 ) ;
F_8 ( & V_15 , V_5 , V_6 ) ;
V_12 = ( V_13 + V_11 ) - V_17 ;
if ( V_12 > 0 )
{
F_8 ( & V_15 , & ( V_2 [ V_13 ] ) , V_11 - V_12 ) ;
F_8 ( & V_15 , & ( V_2 [ 0 ] ) , V_12 ) ;
}
else
F_8 ( & V_15 , & ( V_2 [ V_13 ] ) , V_11 ) ;
F_8 ( & V_15 , V_8 , V_11 ) ;
F_8 ( & V_15 , ( unsigned char * ) & ( V_7 [ 0 ] ) , sizeof( V_7 ) ) ;
F_9 ( V_5 , & V_15 ) ;
V_7 [ 1 ] ++ ;
V_8 = ( const char * ) V_8 + V_11 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
{
V_2 [ V_13 ++ ] ^= V_5 [ V_12 ] ;
if ( V_13 >= V_17 )
{
V_13 = 0 ;
V_14 = V_17 ;
}
}
}
memset ( ( char * ) & V_15 , 0 , sizeof( V_15 ) ) ;
}
static void F_10 ( unsigned char * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 , V_14 , V_13 ;
T_2 V_15 ;
static int V_18 = 1 ;
unsigned long V_19 ;
#ifdef F_11
T_3 * V_20 ;
#endif
#ifdef F_12
{
static unsigned char V_21 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_8 [ V_10 ] = V_21 ++ ;
return;
}
#endif
F_5 ( V_16 ) ;
if ( V_18 )
{
F_6 ( V_16 ) ;
F_13 ( & V_15 , sizeof( V_15 ) ) ;
#ifndef F_14
V_19 = F_15 () ;
F_13 ( & V_19 , sizeof( V_19 ) ) ;
V_19 = F_16 () ;
F_13 ( & V_19 , sizeof( V_19 ) ) ;
#endif
V_19 = time ( NULL ) ;
F_13 ( & V_19 , sizeof( V_19 ) ) ;
if ( ( V_20 = fopen ( F_11 , L_1 ) ) != NULL )
{
unsigned char V_22 [ 32 ] ;
fread ( ( unsigned char * ) V_22 , 1 , 32 , V_20 ) ;
fclose ( V_20 ) ;
F_13 ( V_22 , 32 ) ;
memset ( V_22 , 0 , 32 ) ;
}
#ifdef F_17
memset ( V_2 , 0 , V_17 ) ;
memset ( V_5 , 0 , V_6 ) ;
#endif
F_5 ( V_16 ) ;
V_18 = 0 ;
}
V_13 = V_4 ;
V_14 = V_3 ;
V_4 += V_9 ;
if ( V_4 > V_3 )
V_4 = ( V_4 % V_3 ) ;
F_6 ( V_16 ) ;
while ( V_9 > 0 )
{
V_11 = ( V_9 >= V_6 / 2 ) ? V_6 / 2 : V_9 ;
V_9 -= V_11 ;
F_7 ( & V_15 ) ;
F_8 ( & V_15 , & ( V_5 [ V_6 / 2 ] ) , V_6 / 2 ) ;
F_8 ( & V_15 , ( unsigned char * ) & ( V_7 [ 0 ] ) , sizeof( V_7 ) ) ;
#ifndef F_17
F_8 ( & V_15 , V_8 , V_11 ) ;
#endif
V_12 = ( V_13 + V_11 ) - V_14 ;
if ( V_12 > 0 )
{
F_8 ( & V_15 , & ( V_2 [ V_13 ] ) , V_11 - V_12 ) ;
F_8 ( & V_15 , & ( V_2 [ 0 ] ) , V_12 ) ;
}
else
F_8 ( & V_15 , & ( V_2 [ V_13 ] ) , V_11 ) ;
F_9 ( V_5 , & V_15 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
{
if ( V_13 >= V_14 )
V_13 = 0 ;
V_2 [ V_13 ++ ] ^= V_5 [ V_10 ] ;
* ( V_8 ++ ) = V_5 [ V_10 + V_6 / 2 ] ;
}
}
F_7 ( & V_15 ) ;
F_8 ( & V_15 , ( unsigned char * ) & ( V_7 [ 0 ] ) , sizeof( V_7 ) ) ;
V_7 [ 0 ] ++ ;
F_8 ( & V_15 , V_5 , V_6 ) ;
F_9 ( V_5 , & V_15 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
}
void F_18 ( void )
{
T_4 V_23 ;
T_4 V_24 ;
T_5 V_25 ;
T_5 V_26 ;
T_6 V_27 ;
unsigned int V_28 ;
char * V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 = 16 ;
V_23 = F_19 ( L_2 , NULL , NULL , NULL ) ;
V_24 = F_20 ( V_23 ) ;
V_30 = F_21 ( V_23 , V_34 ) ;
V_31 = F_21 ( V_23 , V_35 ) ;
V_25 = F_22 ( V_23 , V_30 , V_33 ) ;
V_26 = F_23 ( V_24 , V_25 ) ;
F_24 ( V_25 , sizeof( T_6 ) , ( V_36 ) & V_27 ) ;
V_28 = ( unsigned int ) V_27 . V_37 * V_27 . V_38 * V_27 . V_39 ;
V_29 = Malloc ( V_28 ) ;
if ( V_29 ) {
for ( V_32 = 0 ; V_32 < V_31 - V_33 ; V_32 += V_33 )
{
unsigned char V_5 [ V_6 ] ;
F_25 ( V_24 , 0 , 0 , V_30 , V_33 , V_23 , 0 , V_32 , V_40 ) ;
F_26 ( V_25 , V_28 , V_29 ) ;
F_27 ( V_29 , V_28 , V_5 ) ;
F_13 ( V_5 , V_6 ) ;
}
Free ( V_29 ) ;
}
V_25 = F_23 ( V_24 , V_26 ) ;
F_28 ( V_25 ) ;
F_29 ( V_24 ) ;
F_29 ( V_23 ) ;
}
