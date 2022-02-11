int F_1 ( char * V_1 , int V_2 , const char * V_3 ,
int V_4 )
{
char V_5 [ V_6 ] ;
int V_7 ;
V_7 = F_2 ( V_1 , V_5 , ( V_2 > V_6 ) ? V_6 : V_2 , V_3 , V_4 ) ;
memset ( V_5 , 0 , V_6 ) ;
return ( V_7 ) ;
}
static void F_3 ( T_1 * V_8 )
{
#define F_4 4
char V_1 [ F_4 + 1 ] ;
do {
fgets ( V_1 , F_4 , V_8 ) ;
} while ( strchr ( V_1 , '\n' ) == NULL );
}
int F_2 ( char * V_1 , char * V_5 , int V_9 , const char * V_3 ,
int V_4 )
{
#ifdef F_5
struct V_10 V_11 ;
F_6 ( V_12 , L_1 ) ;
long V_13 [ 3 ] , V_14 [ 3 ] ;
long V_15 ;
unsigned short V_16 = 0 ;
#else
#ifndef F_7
T_2 V_13 , V_14 ;
#endif
#endif
int V_17 ;
int V_18 ;
static int V_19 ;
int V_20 ;
static T_1 * V_21 ;
char * V_22 ;
if ( setjmp ( V_23 ) )
{
V_18 = 0 ;
goto error;
}
V_17 = 5 ;
V_18 = 0 ;
V_19 = 0 ;
V_20 = 1 ;
V_21 = NULL ;
#ifndef F_7
if ( ( V_21 = fopen ( L_2 , L_3 ) ) == NULL )
V_21 = V_24 ;
#else
if ( ( V_21 = fopen ( L_4 , L_3 ) ) == NULL )
V_21 = V_24 ;
#endif
#if F_8 ( V_25 ) && ! F_8 ( F_5 )
if ( V_25 ( fileno ( V_21 ) , & V_13 ) == - 1 )
{
#ifdef F_9
if ( V_26 == F_9 )
V_20 = 0 ;
else
#endif
#ifdef F_10
if ( V_26 == F_10 )
V_20 = 0 ;
else
#endif
return ( - 1 ) ;
}
memcpy ( & ( V_14 ) , & ( V_13 ) , sizeof( V_13 ) ) ;
#endif
#ifdef F_5
V_15 = F_11 ( & V_12 , & V_16 , 0 , 0 ) ;
if ( V_15 != V_27 )
return ( - 1 ) ;
V_15 = F_12 ( 0 , V_16 , V_28 , & V_11 , 0 , 0 , V_13 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_15 != V_27 ) || ( V_11 . V_29 != V_27 ) )
return ( - 1 ) ;
#endif
F_13 () ;
V_19 = 1 ;
#ifdef F_14
V_14 . F_14 &= ~ V_30 ;
#endif
#if F_8 ( V_31 ) && ! F_8 ( F_5 )
if ( V_20 && ( V_31 ( fileno ( V_21 ) , & V_14 ) == - 1 ) )
return ( - 1 ) ;
#endif
#ifdef F_5
V_14 [ 0 ] = V_13 [ 0 ] ;
V_14 [ 1 ] = V_13 [ 1 ] | V_32 ;
V_14 [ 2 ] = V_13 [ 2 ] ;
V_15 = F_12 ( 0 , V_16 , V_33 , & V_11 , 0 , 0 , V_14 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_15 != V_27 ) || ( V_11 . V_29 != V_27 ) )
return ( - 1 ) ;
#endif
V_19 = 2 ;
while ( ( ! V_18 ) && ( V_17 -- ) )
{
fputs ( V_3 , V_34 ) ;
fflush ( V_34 ) ;
V_1 [ 0 ] = '\0' ;
fgets ( V_1 , V_9 , V_21 ) ;
if ( feof ( V_21 ) ) goto error;
if ( ferror ( V_21 ) ) goto error;
if ( ( V_22 = ( char * ) strchr ( V_1 , '\n' ) ) != NULL )
* V_22 = '\0' ;
else F_3 ( V_21 ) ;
if ( V_4 )
{
fprintf ( V_34 , L_5 , V_3 ) ;
fflush ( V_34 ) ;
V_5 [ 0 ] = '\0' ;
fgets ( V_5 , V_9 , V_21 ) ;
if ( feof ( V_21 ) ) goto error;
if ( ( V_22 = ( char * ) strchr ( V_5 , '\n' ) ) != NULL )
* V_22 = '\0' ;
else F_3 ( V_21 ) ;
if ( strcmp ( V_1 , V_5 ) != 0 )
{
fprintf ( V_34 , L_6 ) ;
fflush ( V_34 ) ;
break;
}
}
V_18 = 1 ;
}
error:
fprintf ( V_34 , L_7 ) ;
#ifdef F_15
perror ( L_8 ) ;
#endif
#if F_8 ( V_31 ) && ! F_8 ( F_5 )
if ( V_19 >= 2 ) V_31 ( fileno ( V_21 ) , & V_13 ) ;
#endif
#ifdef F_5
if ( V_19 >= 2 )
V_15 = F_12 ( 0 , V_16 , V_33 , & V_11 , 0 , 0
, V_13 , 12 , 0 , 0 , 0 , 0 ) ;
#endif
if ( V_19 >= 1 ) F_16 () ;
if ( V_24 != V_21 ) fclose ( V_21 ) ;
#ifdef F_5
V_15 = F_17 ( V_16 ) ;
#endif
return ( ! V_18 ) ;
}
int F_2 ( char * V_1 , char * V_5 , int V_9 , char * V_3 , int V_4 )
{
memset ( V_1 , 0 , V_9 ) ;
memset ( V_5 , 0 , V_9 ) ;
return ( 0 ) ;
}
static void F_13 ( void )
{
int V_35 ;
#ifdef F_18
struct V_36 V_37 ;
memset ( & V_37 , 0 , sizeof V_37 ) ;
V_37 . V_38 = V_39 ;
#endif
for ( V_35 = 1 ; V_35 < V_40 ; V_35 ++ )
{
#ifdef F_19
if ( V_35 == F_19 )
continue;
#endif
#ifdef F_20
if ( V_35 == F_20 )
continue;
#endif
#ifdef F_18
V_36 ( V_35 , & V_37 , & V_41 [ V_35 ] ) ;
#else
V_41 [ V_35 ] = signal ( V_35 , V_39 ) ;
#endif
}
#ifdef F_21
signal ( F_21 , V_42 ) ;
#endif
}
static void F_16 ( void )
{
int V_35 ;
for ( V_35 = 1 ; V_35 < V_40 ; V_35 ++ )
{
#ifdef F_19
if ( V_35 == F_19 )
continue;
#endif
#ifdef F_20
if ( V_35 == F_20 )
continue;
#endif
#ifdef F_18
V_36 ( V_35 , & V_41 [ V_35 ] , NULL ) ;
#else
signal ( V_35 , V_41 [ V_35 ] ) ;
#endif
}
}
static void V_39 ( int V_35 )
{
longjmp ( V_23 , 1 ) ;
#ifdef F_22
V_35 = V_35 ;
#endif
}
static int F_23 ( char * V_1 , int V_9 , T_1 * V_21 )
{
int V_35 ;
char * V_22 ;
V_22 = V_1 ;
for (; ; )
{
if ( V_9 == 0 )
{
* V_22 = '\0' ;
break;
}
V_9 -- ;
#ifdef F_24
V_35 = F_25 () ;
#else
V_35 = F_26 () ;
#endif
if ( V_35 == '\r' ) V_35 = '\n' ;
* ( V_22 ++ ) = V_35 ;
if ( V_35 == '\n' )
{
* V_22 = '\0' ;
break;
}
}
#ifdef F_27
{
T_3 V_43 ;
V_43 = F_28 ( V_44 ) ;
F_29 ( V_43 ) ;
}
#endif
return ( strlen ( V_1 ) ) ;
}
