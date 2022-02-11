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
#ifdef F_7
if ( ( V_21 = fopen ( L_2 , L_3 ) ) == NULL )
V_21 = V_24 ;
#elif F_8 ( V_25 )
V_21 = V_24 ;
#else
#ifndef F_9
if ( ( V_21 = fopen ( L_4 , L_3 ) ) == NULL )
#endif
V_21 = V_24 ;
#endif
#if F_8 ( V_26 ) && ! F_8 ( F_5 )
if ( V_26 ( fileno ( V_21 ) , & V_13 ) == - 1 )
{
#ifdef F_10
if ( V_27 == F_10 )
V_20 = 0 ;
else
#endif
#ifdef F_11
if ( V_27 == F_11 )
V_20 = 0 ;
else
#endif
return ( - 1 ) ;
}
memcpy ( & ( V_14 ) , & ( V_13 ) , sizeof( V_13 ) ) ;
#endif
#ifdef F_5
V_15 = F_12 ( & V_12 , & V_16 , 0 , 0 ) ;
if ( V_15 != V_28 )
return ( - 1 ) ;
V_15 = F_13 ( 0 , V_16 , V_29 , & V_11 , 0 , 0 , V_13 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_15 != V_28 ) || ( V_11 . V_30 != V_28 ) )
return ( - 1 ) ;
#endif
F_14 () ;
V_19 = 1 ;
#ifdef F_15
V_14 . F_15 &= ~ V_31 ;
#endif
#if F_8 ( V_32 ) && ! F_8 ( F_5 )
if ( V_20 && ( V_32 ( fileno ( V_21 ) , & V_14 ) == - 1 ) )
#ifdef F_9
;
#else
return ( - 1 ) ;
#endif
#endif
#ifdef F_5
V_14 [ 0 ] = V_13 [ 0 ] ;
V_14 [ 1 ] = V_13 [ 1 ] | V_33 ;
V_14 [ 2 ] = V_13 [ 2 ] ;
V_15 = F_13 ( 0 , V_16 , V_34 , & V_11 , 0 , 0 , V_14 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_15 != V_28 ) || ( V_11 . V_30 != V_28 ) )
return ( - 1 ) ;
#endif
V_19 = 2 ;
while ( ( ! V_18 ) && ( V_17 -- ) )
{
fputs ( V_3 , V_35 ) ;
fflush ( V_35 ) ;
V_1 [ 0 ] = '\0' ;
fgets ( V_1 , V_9 , V_21 ) ;
if ( feof ( V_21 ) ) goto error;
if ( ferror ( V_21 ) ) goto error;
if ( ( V_22 = ( char * ) strchr ( V_1 , '\n' ) ) != NULL )
* V_22 = '\0' ;
else F_3 ( V_21 ) ;
if ( V_4 )
{
fprintf ( V_35 , L_5 , V_3 ) ;
fflush ( V_35 ) ;
V_5 [ 0 ] = '\0' ;
fgets ( V_5 , V_9 , V_21 ) ;
if ( feof ( V_21 ) ) goto error;
if ( ( V_22 = ( char * ) strchr ( V_5 , '\n' ) ) != NULL )
* V_22 = '\0' ;
else F_3 ( V_21 ) ;
if ( strcmp ( V_1 , V_5 ) != 0 )
{
fprintf ( V_35 , L_6 ) ;
fflush ( V_35 ) ;
break;
}
}
V_18 = 1 ;
}
error:
fprintf ( V_35 , L_7 ) ;
#ifdef F_16
perror ( L_8 ) ;
#endif
#if F_8 ( V_32 ) && ! F_8 ( F_5 )
if ( V_19 >= 2 ) V_32 ( fileno ( V_21 ) , & V_13 ) ;
#endif
#ifdef F_5
if ( V_19 >= 2 )
V_15 = F_13 ( 0 , V_16 , V_34 , & V_11 , 0 , 0
, V_13 , 12 , 0 , 0 , 0 , 0 ) ;
#endif
if ( V_19 >= 1 ) F_17 () ;
if ( V_24 != V_21 ) fclose ( V_21 ) ;
#ifdef F_5
V_15 = F_18 ( V_16 ) ;
#endif
return ( ! V_18 ) ;
}
int F_2 ( char * V_1 , char * V_5 , int V_9 , char * V_3 , int V_4 )
{
memset ( V_1 , 0 , V_9 ) ;
memset ( V_5 , 0 , V_9 ) ;
return ( 0 ) ;
}
static void F_14 ( void )
{
int V_36 ;
#ifdef F_19
struct V_37 V_38 ;
memset ( & V_38 , 0 , sizeof V_38 ) ;
V_38 . V_39 = V_40 ;
#endif
for ( V_36 = 1 ; V_36 < V_41 ; V_36 ++ )
{
#ifdef F_20
if ( V_36 == F_20 )
continue;
#endif
#ifdef F_21
if ( V_36 == F_21 )
continue;
#endif
#ifdef F_19
V_37 ( V_36 , & V_38 , & V_42 [ V_36 ] ) ;
#else
V_42 [ V_36 ] = signal ( V_36 , V_40 ) ;
#endif
}
#ifdef F_22
signal ( F_22 , V_43 ) ;
#endif
}
static void F_17 ( void )
{
int V_36 ;
for ( V_36 = 1 ; V_36 < V_41 ; V_36 ++ )
{
#ifdef F_20
if ( V_36 == F_20 )
continue;
#endif
#ifdef F_21
if ( V_36 == F_21 )
continue;
#endif
#ifdef F_19
V_37 ( V_36 , & V_42 [ V_36 ] , NULL ) ;
#else
signal ( V_36 , V_42 [ V_36 ] ) ;
#endif
}
}
static void V_40 ( int V_36 )
{
longjmp ( V_23 , 1 ) ;
#ifdef F_23
V_36 = V_36 ;
#endif
}
static int F_24 ( char * V_1 , int V_9 , T_1 * V_21 )
{
int V_36 ;
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
#ifdef F_25
V_36 = F_26 () ;
#else
V_36 = F_27 () ;
#endif
if ( V_36 == '\r' ) V_36 = '\n' ;
* ( V_22 ++ ) = V_36 ;
if ( V_36 == '\n' )
{
* V_22 = '\0' ;
break;
}
}
#ifdef F_28
{
T_3 V_44 ;
V_44 = F_29 ( V_45 ) ;
F_30 ( V_44 ) ;
}
#endif
return ( strlen ( V_1 ) ) ;
}
