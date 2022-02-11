int F_1 ( char * V_1 , int V_2 , const char * V_3 ,
int V_4 )
{
char V_5 [ V_6 ] ;
int V_7 ;
V_7 = F_2 ( V_1 , V_5 , ( V_2 > V_6 ) ? V_6 : V_2 , V_3 , V_4 ) ;
F_3 ( V_5 , V_6 ) ;
return ( V_7 ) ;
}
int F_2 ( char * V_1 , char * V_5 , int V_8 , const char * V_3 , int V_4 )
{
memset ( V_1 , 0 , V_8 ) ;
memset ( V_5 , 0 , V_8 ) ;
return ( 0 ) ;
}
int F_2 ( char * V_1 , char * V_5 , int V_8 , char * V_3 , int V_4 )
{
memset ( V_1 , 0 , V_8 ) ;
memset ( V_5 , 0 , V_8 ) ;
return ( 0 ) ;
}
static void F_4 ( T_1 * V_9 )
{
#define F_5 4
char V_1 [ F_5 + 1 ] ;
do {
fgets ( V_1 , F_5 , V_9 ) ;
} while ( strchr ( V_1 , '\n' ) == NULL );
}
int F_2 ( char * V_1 , char * V_5 , int V_8 , const char * V_3 ,
int V_4 )
{
#ifdef F_6
struct V_10 V_11 ;
F_7 ( V_12 , L_1 ) ;
long V_13 [ 3 ] , V_14 [ 3 ] ;
long V_15 ;
unsigned short V_16 = 0 ;
#else
#if ! F_8 ( V_17 ) || F_8 ( V_18 )
T_2 V_13 , V_14 ;
#endif
#endif
int V_19 ;
int V_20 ;
static int V_21 ;
int V_22 ;
static T_1 * V_23 ;
char * V_24 ;
if ( setjmp ( V_25 ) )
{
V_20 = 0 ;
goto error;
}
V_19 = 5 ;
V_20 = 0 ;
V_21 = 0 ;
V_22 = 1 ;
V_23 = NULL ;
#ifdef V_17
if ( ( V_23 = fopen ( L_2 , L_3 ) ) == NULL )
V_23 = V_26 ;
#elif F_8 ( V_27 ) || F_8 ( V_28 )
V_23 = V_26 ;
#else
#ifndef F_9
if ( ( V_23 = fopen ( L_4 , L_3 ) ) == NULL )
#endif
V_23 = V_26 ;
#endif
#if F_8 ( V_29 ) && ! F_8 ( F_6 )
if ( V_29 ( fileno ( V_23 ) , & V_13 ) == - 1 )
{
#ifdef F_10
if ( V_30 == F_10 )
V_22 = 0 ;
else
#endif
#ifdef F_11
if ( V_30 == F_11 )
V_22 = 0 ;
else
#endif
return ( - 1 ) ;
}
memcpy ( & ( V_14 ) , & ( V_13 ) , sizeof( V_13 ) ) ;
#endif
#ifdef F_6
V_15 = F_12 ( & V_12 , & V_16 , 0 , 0 ) ;
if ( V_15 != V_31 )
return ( - 1 ) ;
V_15 = F_13 ( 0 , V_16 , V_32 , & V_11 , 0 , 0 , V_13 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_15 != V_31 ) || ( V_11 . V_33 != V_31 ) )
return ( - 1 ) ;
#endif
F_14 () ;
V_21 = 1 ;
#ifdef F_15
V_14 . F_15 &= ~ V_34 ;
#endif
#if F_8 ( V_35 ) && ! F_8 ( F_6 )
if ( V_22 && ( V_35 ( fileno ( V_23 ) , & V_14 ) == - 1 ) )
#ifdef F_9
;
#else
return ( - 1 ) ;
#endif
#endif
#ifdef F_6
V_14 [ 0 ] = V_13 [ 0 ] ;
V_14 [ 1 ] = V_13 [ 1 ] | V_36 ;
V_14 [ 2 ] = V_13 [ 2 ] ;
V_15 = F_13 ( 0 , V_16 , V_37 , & V_11 , 0 , 0 , V_14 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_15 != V_31 ) || ( V_11 . V_33 != V_31 ) )
return ( - 1 ) ;
#endif
V_21 = 2 ;
while ( ( ! V_20 ) && ( V_19 -- ) )
{
fputs ( V_3 , V_38 ) ;
fflush ( V_38 ) ;
V_1 [ 0 ] = '\0' ;
fgets ( V_1 , V_8 , V_23 ) ;
if ( feof ( V_23 ) ) goto error;
if ( ferror ( V_23 ) ) goto error;
if ( ( V_24 = ( char * ) strchr ( V_1 , '\n' ) ) != NULL )
* V_24 = '\0' ;
else F_4 ( V_23 ) ;
if ( V_4 )
{
fprintf ( V_38 , L_5 , V_3 ) ;
fflush ( V_38 ) ;
V_5 [ 0 ] = '\0' ;
fgets ( V_5 , V_8 , V_23 ) ;
if ( feof ( V_23 ) ) goto error;
if ( ( V_24 = ( char * ) strchr ( V_5 , '\n' ) ) != NULL )
* V_24 = '\0' ;
else F_4 ( V_23 ) ;
if ( strcmp ( V_1 , V_5 ) != 0 )
{
fprintf ( V_38 , L_6 ) ;
fflush ( V_38 ) ;
break;
}
}
V_20 = 1 ;
}
error:
fprintf ( V_38 , L_7 ) ;
#if 0
perror("fgets(tty)");
#endif
#if F_8 ( V_35 ) && ! F_8 ( F_6 )
if ( V_21 >= 2 ) V_35 ( fileno ( V_23 ) , & V_13 ) ;
#endif
#ifdef F_6
if ( V_21 >= 2 )
V_15 = F_13 ( 0 , V_16 , V_37 , & V_11 , 0 , 0
, V_13 , 12 , 0 , 0 , 0 , 0 ) ;
#endif
if ( V_21 >= 1 ) F_16 () ;
if ( V_26 != V_23 ) fclose ( V_23 ) ;
#ifdef F_6
V_15 = F_17 ( V_16 ) ;
#endif
return ( ! V_20 ) ;
}
static void F_14 ( void )
{
int V_39 ;
#ifdef F_18
struct V_40 V_41 ;
memset ( & V_41 , 0 , sizeof V_41 ) ;
V_41 . V_42 = V_43 ;
#endif
for ( V_39 = 1 ; V_39 < V_44 ; V_39 ++ )
{
#ifdef F_19
if ( V_39 == F_19 )
continue;
#endif
#ifdef F_20
if ( V_39 == F_20 )
continue;
#endif
#ifdef F_18
V_40 ( V_39 , & V_41 , & V_45 [ V_39 ] ) ;
#else
V_45 [ V_39 ] = signal ( V_39 , V_43 ) ;
#endif
}
#ifdef F_21
signal ( F_21 , V_46 ) ;
#endif
}
static void F_16 ( void )
{
int V_39 ;
for ( V_39 = 1 ; V_39 < V_44 ; V_39 ++ )
{
#ifdef F_19
if ( V_39 == F_19 )
continue;
#endif
#ifdef F_20
if ( V_39 == F_20 )
continue;
#endif
#ifdef F_18
V_40 ( V_39 , & V_45 [ V_39 ] , NULL ) ;
#else
signal ( V_39 , V_45 [ V_39 ] ) ;
#endif
}
}
static void V_43 ( int V_39 )
{
longjmp ( V_25 , 1 ) ;
#ifdef F_22
V_39 = V_39 ;
#endif
}
static int F_23 ( char * V_1 , int V_8 , T_1 * V_23 )
{
int V_39 ;
char * V_24 ;
V_24 = V_1 ;
for (; ; )
{
if ( V_8 == 0 )
{
* V_24 = '\0' ;
break;
}
V_8 -- ;
#ifdef F_24
V_39 = F_25 () ;
#else
V_39 = F_26 () ;
#endif
if ( V_39 == '\r' ) V_39 = '\n' ;
* ( V_24 ++ ) = V_39 ;
if ( V_39 == '\n' )
{
* V_24 = '\0' ;
break;
}
}
#ifdef F_27
{
T_3 V_47 ;
V_47 = F_28 ( V_48 ) ;
F_29 ( V_47 ) ;
}
#endif
return ( strlen ( V_1 ) ) ;
}
