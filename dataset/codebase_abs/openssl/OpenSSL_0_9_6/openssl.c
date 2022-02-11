int main ( int V_1 , char * V_2 [] )
{
ARGS V_3 ;
#define F_1 16
char V_4 [ F_1 ] ;
T_1 V_5 , * V_6 ;
T_2 char * V_7 , V_8 [ 1024 ] , V_9 [ 256 ] ;
int V_10 , V_11 , V_12 = 0 ;
int V_13 ;
char * * V_14 , * V_15 ;
T_3 * V_16 = NULL ;
long V_17 ;
V_3 . V_18 = NULL ;
V_3 . V_19 = 0 ;
if ( getenv ( L_1 ) != NULL )
F_2 () ;
F_3 ( V_20 ) ;
F_4 () ;
if ( V_21 == NULL )
if ( ( V_21 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_21 , V_22 , V_23 | V_24 ) ;
F_8 () ;
V_15 = getenv ( L_2 ) ;
if ( V_15 == NULL )
V_15 = getenv ( L_3 ) ;
if ( V_15 == NULL )
{
strcpy ( V_9 , F_9 () ) ;
#ifndef F_10
strcat ( V_9 , L_4 ) ;
#endif
strcat ( V_9 , V_25 ) ;
V_15 = V_9 ;
}
V_26 = V_15 ;
V_27 = F_11 ( V_27 , V_15 , & V_17 ) ;
if ( V_27 == NULL ) F_12 () ;
V_16 = F_13 () ;
F_14 ( V_2 [ 0 ] , V_4 , F_1 ) ;
V_5 . V_28 = V_4 ;
V_6 = ( T_1 * ) F_15 ( V_16 , & V_5 ) ;
if ( V_6 != NULL )
{
V_2 [ 0 ] = V_4 ;
V_12 = V_6 -> V_29 ( V_1 , V_2 ) ;
goto V_30;
}
if ( V_1 != 1 )
{
V_1 -- ;
V_2 ++ ;
V_12 = F_16 ( V_16 , V_1 , V_2 ) ;
if ( V_12 < 0 ) V_12 = 0 ;
goto V_30;
}
for (; ; )
{
V_12 = 0 ;
V_15 = V_8 ;
V_10 = 1024 ;
V_11 = 0 ;
for (; ; )
{
V_15 [ 0 ] = '\0' ;
if ( V_11 ++ )
V_7 = L_5 ;
else V_7 = L_6 ;
fputs ( V_7 , stdout ) ;
fflush ( stdout ) ;
fgets ( V_15 , V_10 , V_31 ) ;
if ( V_15 [ 0 ] == '\0' ) goto V_30;
V_11 = strlen ( V_15 ) ;
if ( V_11 <= 1 ) break;
if ( V_15 [ V_11 - 2 ] != '\\' ) break;
V_11 -= 2 ;
V_15 += V_11 ;
V_10 -= V_11 ;
}
if ( ! F_17 ( & V_3 , V_8 , & V_13 , & V_14 ) ) break;
V_12 = F_16 ( V_16 , V_13 , V_14 ) ;
if ( V_12 < 0 )
{
V_12 = 0 ;
goto V_30;
}
if ( V_12 != 0 )
F_18 ( V_21 , L_7 , V_14 [ 0 ] ) ;
( void ) F_19 ( V_21 ) ;
}
F_18 ( V_21 , L_8 ) ;
V_12 = 1 ;
V_30:
if ( V_27 != NULL )
{
F_20 ( V_27 ) ;
V_27 = NULL ;
}
if ( V_16 != NULL ) F_21 ( V_16 ) ;
if ( V_3 . V_18 != NULL ) F_22 ( V_3 . V_18 ) ;
F_23 ( 0 ) ;
F_24 () ;
F_25 () ;
F_26 ( V_21 ) ;
if ( V_21 != NULL )
{
F_27 ( V_21 ) ;
V_21 = NULL ;
}
EXIT ( V_12 ) ;
}
static int F_16 ( T_3 * V_16 , int V_13 , char * V_14 [] )
{
T_1 V_5 , * V_6 ;
int V_11 , V_12 = 1 , V_32 , V_33 ;
if ( ( V_13 <= 0 ) || ( V_14 [ 0 ] == NULL ) )
{ V_12 = 0 ; goto V_30; }
V_5 . V_28 = V_14 [ 0 ] ;
V_6 = ( T_1 * ) F_15 ( V_16 , & V_5 ) ;
if ( V_6 != NULL )
{
V_12 = V_6 -> V_29 ( V_13 , V_14 ) ;
}
else if ( ( strncmp ( V_14 [ 0 ] , L_9 , 3 ) ) == 0 )
{
T_4 * V_34 = F_28 ( stdout , V_23 ) ;
#ifdef F_10
{
T_4 * V_35 = F_5 ( F_29 () ) ;
V_34 = F_30 ( V_35 , V_34 ) ;
}
#endif
V_5 . V_28 = V_14 [ 0 ] + 3 ;
V_12 = ( F_15 ( V_16 , & V_5 ) != NULL ) ;
if ( ! V_12 )
F_18 ( V_34 , L_10 , V_14 [ 0 ] ) ;
else
F_18 ( V_34 , L_10 , V_14 [ 0 ] + 3 ) ;
F_31 ( V_34 ) ;
goto V_30;
}
else if ( ( strcmp ( V_14 [ 0 ] , L_11 ) == 0 ) ||
( strcmp ( V_14 [ 0 ] , L_12 ) == 0 ) ||
( strcmp ( V_14 [ 0 ] , L_13 ) == 0 ) ||
( strcmp ( V_14 [ 0 ] , L_14 ) == 0 ) )
{
V_12 = - 1 ;
goto V_30;
}
else if ( ( strcmp ( V_14 [ 0 ] , V_36 ) == 0 ) ||
( strcmp ( V_14 [ 0 ] , V_37 ) == 0 ) ||
( strcmp ( V_14 [ 0 ] , V_38 ) == 0 ) )
{
int V_39 ;
T_4 * V_34 ;
if ( strcmp ( V_14 [ 0 ] , V_36 ) == 0 )
V_39 = V_40 ;
else if ( strcmp ( V_14 [ 0 ] , V_37 ) == 0 )
V_39 = V_41 ;
else
V_39 = V_42 ;
V_34 = F_28 ( stdout , V_23 ) ;
#ifdef F_10
{
T_4 * V_35 = F_5 ( F_29 () ) ;
V_34 = F_30 ( V_35 , V_34 ) ;
}
#endif
for ( V_6 = V_43 ; V_6 -> V_28 != NULL ; V_6 ++ )
if ( V_6 -> type == V_39 )
F_18 ( V_34 , L_10 , V_6 -> V_28 ) ;
F_31 ( V_34 ) ;
V_12 = 0 ;
goto V_30;
}
else
{
F_18 ( V_21 , L_15 ,
V_14 [ 0 ] ) ;
F_18 ( V_21 , L_16 ) ;
V_11 = 0 ;
V_32 = 0 ;
for ( V_6 = V_43 ; V_6 -> V_28 != NULL ; V_6 ++ )
{
V_33 = 0 ;
if ( ( ( V_11 ++ ) % 5 ) == 0 )
{
F_18 ( V_21 , L_17 ) ;
V_33 = 1 ;
}
if ( V_6 -> type != V_32 )
{
V_32 = V_6 -> type ;
if ( ! V_33 ) F_18 ( V_21 , L_17 ) ;
if ( V_32 == V_41 )
{
V_11 = 1 ;
F_18 ( V_21 ,
L_18 ) ;
}
else if ( V_32 == V_42 )
{
V_11 = 1 ;
F_18 ( V_21 , L_19 ) ;
}
}
F_18 ( V_21 , L_20 , V_6 -> V_28 ) ;
}
F_18 ( V_21 , L_21 ) ;
V_12 = 0 ;
}
V_30:
return ( V_12 ) ;
}
static int F_32 ( const void * V_44 , const void * V_45 )
{
const T_1 * V_46 = V_44 ;
const T_1 * V_47 = V_45 ;
if( V_46 -> type != V_47 -> type )
return V_46 -> type - V_47 -> type ;
return strcmp ( V_46 -> V_28 , V_47 -> V_28 ) ;
}
static T_3 * F_13 ( void )
{
T_3 * V_12 ;
T_1 * V_5 ;
int V_11 ;
for( V_11 = 0 , V_5 = V_43 ; V_5 -> V_28 != NULL ; ++ V_5 , ++ V_11 )
;
qsort ( V_43 , V_11 , sizeof *V_43 , F_32 ) ;
if ( ( V_12 = F_33 ( V_48 , V_49 ) ) == NULL ) return ( NULL ) ;
for ( V_5 = V_43 ; V_5 -> V_28 != NULL ; V_5 ++ )
F_34 ( V_12 , V_5 ) ;
return ( V_12 ) ;
}
static int T_5 V_49 ( T_1 * V_50 , T_1 * V_51 )
{
return ( strncmp ( V_50 -> V_28 , V_51 -> V_28 , 8 ) ) ;
}
static unsigned long T_5 V_48 ( T_1 * V_50 )
{
return ( F_35 ( V_50 -> V_28 ) ) ;
}
