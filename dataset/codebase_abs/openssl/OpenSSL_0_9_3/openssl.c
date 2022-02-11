static void F_1 ( int V_1 )
{
char * V_2 = NULL ;
* V_2 = '\0' ;
}
int main ( int V_3 , char * V_4 [] )
{
ARGS V_5 ;
#define F_2 16
char V_6 [ F_2 ] ;
T_1 V_7 , * V_8 ;
T_2 char * V_9 , V_10 [ 1024 ] , V_11 [ 256 ] ;
int V_12 , V_1 , V_13 = 0 ;
int V_14 ;
char * * V_15 , * V_16 ;
T_3 * V_17 = NULL ;
long V_18 ;
V_5 . V_19 = NULL ;
V_5 . V_20 = 0 ;
F_3 () ;
#if F_4 ( V_21 ) && ! F_4 ( V_22 ) && ! F_4 ( V_23 )
#ifdef F_5
signal ( F_5 , F_1 ) ;
#endif
#ifdef F_6
signal ( F_6 , F_1 ) ;
#endif
#endif
if ( V_24 == NULL )
if ( ( V_24 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_24 , V_25 , V_26 | V_27 ) ;
F_10 ( V_28 ) ;
F_11 () ;
V_16 = getenv ( L_1 ) ;
if ( V_16 == NULL )
V_16 = getenv ( L_2 ) ;
if ( V_16 == NULL )
{
strcpy ( V_11 , F_12 () ) ;
#ifndef F_13
strcat ( V_11 , L_3 ) ;
#endif
strcat ( V_11 , V_29 ) ;
V_16 = V_11 ;
}
V_30 = V_16 ;
V_31 = F_14 ( V_31 , V_16 , & V_18 ) ;
if ( V_31 == NULL ) F_15 () ;
V_17 = F_16 () ;
F_17 ( V_4 [ 0 ] , V_6 , F_2 ) ;
V_7 . V_32 = V_6 ;
V_8 = ( T_1 * ) F_18 ( V_17 , ( char * ) & V_7 ) ;
if ( V_8 != NULL )
{
V_4 [ 0 ] = V_6 ;
V_13 = V_8 -> V_33 ( V_3 , V_4 ) ;
goto V_34;
}
if ( V_3 != 1 )
{
V_3 -- ;
V_4 ++ ;
V_13 = F_19 ( V_17 , V_3 , V_4 ) ;
if ( V_13 < 0 ) V_13 = 0 ;
goto V_34;
}
for (; ; )
{
V_13 = 0 ;
V_16 = V_10 ;
V_12 = 1024 ;
V_1 = 0 ;
for (; ; )
{
V_16 [ 0 ] = '\0' ;
if ( V_1 ++ )
V_9 = L_4 ;
else V_9 = L_5 ;
fputs ( V_9 , stdout ) ;
fflush ( stdout ) ;
fgets ( V_16 , V_12 , V_35 ) ;
if ( V_16 [ 0 ] == '\0' ) goto V_34;
V_1 = strlen ( V_16 ) ;
if ( V_1 <= 1 ) break;
if ( V_16 [ V_1 - 2 ] != '\\' ) break;
V_1 -= 2 ;
V_16 += V_1 ;
V_12 -= V_1 ;
}
if ( ! F_20 ( & V_5 , V_10 , & V_14 , & V_15 ) ) break;
V_13 = F_19 ( V_17 , V_14 , V_15 ) ;
if ( V_13 < 0 )
{
V_13 = 0 ;
goto V_34;
}
if ( V_13 != 0 )
F_21 ( V_24 , L_6 , V_15 [ 0 ] ) ;
F_22 ( V_24 ) ;
}
F_21 ( V_24 , L_7 ) ;
V_13 = 1 ;
V_34:
if ( V_31 != NULL )
{
F_23 ( V_31 ) ;
V_31 = NULL ;
}
if ( V_17 != NULL ) F_24 ( V_17 ) ;
if ( V_5 . V_19 != NULL ) Free ( V_5 . V_19 ) ;
F_25 ( 0 ) ;
F_26 () ;
F_27 () ;
F_28 ( V_24 ) ;
if ( V_24 != NULL )
{
F_29 ( V_24 ) ;
V_24 = NULL ;
}
EXIT ( V_13 ) ;
}
static int F_19 ( T_3 * V_17 , int V_14 , char * V_15 [] )
{
T_1 V_7 , * V_8 ;
int V_1 , V_13 = 1 , V_36 , V_37 ;
if ( ( V_14 <= 0 ) || ( V_15 [ 0 ] == NULL ) )
{ V_13 = 0 ; goto V_34; }
V_7 . V_32 = V_15 [ 0 ] ;
V_8 = ( T_1 * ) F_18 ( V_17 , ( char * ) & V_7 ) ;
if ( V_8 != NULL )
{
V_13 = V_8 -> V_33 ( V_14 , V_15 ) ;
}
else if ( ( strcmp ( V_15 [ 0 ] , L_8 ) == 0 ) ||
( strcmp ( V_15 [ 0 ] , L_9 ) == 0 ) ||
( strcmp ( V_15 [ 0 ] , L_10 ) == 0 ) ||
( strcmp ( V_15 [ 0 ] , L_11 ) == 0 ) )
{
V_13 = - 1 ;
goto V_34;
}
else if ( ( strcmp ( V_15 [ 0 ] , V_38 ) == 0 ) ||
( strcmp ( V_15 [ 0 ] , V_39 ) == 0 ) ||
( strcmp ( V_15 [ 0 ] , V_40 ) == 0 ) )
{
int V_41 ;
T_4 * V_42 ;
if ( strcmp ( V_15 [ 0 ] , V_38 ) == 0 )
V_41 = V_43 ;
else if ( strcmp ( V_15 [ 0 ] , V_39 ) == 0 )
V_41 = V_44 ;
else
V_41 = V_45 ;
V_42 = F_30 ( stdout , V_26 ) ;
for ( V_8 = V_46 ; V_8 -> V_32 != NULL ; V_8 ++ )
if ( V_8 -> type == V_41 )
F_21 ( V_42 , L_12 , V_8 -> V_32 ) ;
F_29 ( V_42 ) ;
V_13 = 0 ;
goto V_34;
}
else
{
F_21 ( V_24 , L_13 ,
V_15 [ 0 ] ) ;
F_21 ( V_24 , L_14 ) ;
V_1 = 0 ;
V_36 = 0 ;
for ( V_8 = V_46 ; V_8 -> V_32 != NULL ; V_8 ++ )
{
V_37 = 0 ;
if ( ( ( V_1 ++ ) % 5 ) == 0 )
{
F_21 ( V_24 , L_15 ) ;
V_37 = 1 ;
}
if ( V_8 -> type != V_36 )
{
V_36 = V_8 -> type ;
if ( ! V_37 ) F_21 ( V_24 , L_15 ) ;
if ( V_36 == V_44 )
{
V_1 = 1 ;
F_21 ( V_24 ,
L_16 ) ;
}
else if ( V_36 == V_45 )
{
V_1 = 1 ;
F_21 ( V_24 , L_17 ) ;
}
}
F_21 ( V_24 , L_18 , V_8 -> V_32 ) ;
}
F_21 ( V_24 , L_19 ) ;
V_13 = 0 ;
}
V_34:
return ( V_13 ) ;
}
static int F_31 ( const void * V_47 , const void * V_48 )
{
const T_1 * V_49 = V_47 ;
const T_1 * V_50 = V_48 ;
if( V_49 -> type != V_50 -> type )
return V_49 -> type - V_50 -> type ;
return strcmp ( V_49 -> V_32 , V_50 -> V_32 ) ;
}
static T_3 * F_16 ( void )
{
T_3 * V_13 ;
T_1 * V_7 ;
int V_1 ;
for( V_1 = 0 , V_7 = V_46 ; V_7 -> V_32 != NULL ; ++ V_7 , ++ V_1 )
;
qsort ( V_46 , V_1 , sizeof *V_46 , F_31 ) ;
if ( ( V_13 = F_32 ( V_51 , V_52 ) ) == NULL ) return ( NULL ) ;
for ( V_7 = V_46 ; V_7 -> V_32 != NULL ; V_7 ++ )
F_33 ( V_13 , ( char * ) V_7 ) ;
return ( V_13 ) ;
}
static int T_5 V_52 ( T_1 * V_2 , T_1 * V_53 )
{
return ( strncmp ( V_2 -> V_32 , V_53 -> V_32 , 8 ) ) ;
}
static unsigned long T_5 V_51 ( T_1 * V_2 )
{
return ( F_34 ( V_2 -> V_32 ) ) ;
}
