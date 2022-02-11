static void F_1 ( int V_1 , int type , const char * V_2 , int line )
{
static int V_3 [ V_4 ] ;
const char * V_5 = NULL ;
int V_6 ;
V_6 = V_1 & ( V_7 | V_8 ) ;
if ( ! ( ( V_6 == V_7 ) || ( V_6 == V_8 ) ) )
{
V_5 = L_1 ;
goto V_9;
}
if ( type < 0 || type > V_4 )
{
V_5 = L_2 ;
goto V_9;
}
if ( V_1 & V_10 )
{
if ( V_3 [ type ] )
{
V_5 = L_3 ;
goto V_9;
}
V_3 [ type ] = V_6 ;
}
else if ( V_1 & V_11 )
{
if ( ! V_3 [ type ] )
{
V_5 = L_4 ;
goto V_9;
}
if ( V_3 [ type ] != V_6 )
{
V_5 = ( V_6 == V_7 ) ?
L_5 :
L_6 ;
}
V_3 [ type ] = 0 ;
}
else
{
V_5 = L_1 ;
goto V_9;
}
V_9:
if ( V_5 )
{
fprintf ( V_12 , L_7 ,
V_5 , V_1 , type , V_2 , line ) ;
}
}
int main ( int V_13 , char * V_14 [] )
{
ARGS V_15 ;
#define F_2 39
char V_16 [ F_2 + 1 ] ;
T_1 V_17 , * V_18 ;
T_2 char * V_19 , V_20 [ 1024 ] ;
char * V_21 = NULL ;
int V_22 , V_23 , V_24 = 0 ;
int V_25 ;
char * * V_26 , * V_27 ;
T_3 * V_28 = NULL ;
long V_29 ;
V_15 . V_30 = NULL ;
V_15 . V_31 = 0 ;
if ( V_32 == NULL )
if ( ( V_32 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_32 , V_12 , V_33 | V_34 ) ;
if ( getenv ( L_8 ) != NULL )
{
if ( ! ( 0 == strcmp ( getenv ( L_8 ) , L_9 ) ) )
{
F_6 () ;
F_7 ( V_35 ) ;
}
else
{
F_8 ( 0 , 0 , 0 , 0 , 0 ) ;
}
}
F_9 ( V_36 ) ;
#if 0
if (getenv("OPENSSL_DEBUG_LOCKING") != NULL)
#endif
{
F_10 ( F_1 ) ;
}
F_11 () ;
V_27 = getenv ( L_10 ) ;
if ( V_27 == NULL )
V_27 = getenv ( L_11 ) ;
if ( V_27 == NULL )
V_27 = V_21 = F_12 () ;
V_37 = V_27 ;
V_38 = F_13 ( NULL ) ;
V_23 = F_14 ( V_38 , V_27 , & V_29 ) ;
if ( V_23 == 0 )
{
F_15 ( V_38 ) ;
V_38 = NULL ;
F_16 () ;
}
V_28 = F_17 () ;
F_18 ( V_14 [ 0 ] , V_16 , sizeof V_16 ) ;
V_17 . V_39 = V_16 ;
V_18 = ( T_1 * ) F_19 ( V_28 , & V_17 ) ;
if ( V_18 != NULL )
{
V_14 [ 0 ] = V_16 ;
V_24 = V_18 -> V_40 ( V_13 , V_14 ) ;
goto V_41;
}
if ( V_13 != 1 )
{
V_13 -- ;
V_14 ++ ;
V_24 = F_20 ( V_28 , V_13 , V_14 ) ;
if ( V_24 < 0 ) V_24 = 0 ;
goto V_41;
}
for (; ; )
{
V_24 = 0 ;
V_27 = V_20 ;
V_22 = sizeof V_20 ;
V_23 = 0 ;
for (; ; )
{
V_27 [ 0 ] = '\0' ;
if ( V_23 ++ )
V_19 = L_12 ;
else V_19 = L_13 ;
fputs ( V_19 , stdout ) ;
fflush ( stdout ) ;
fgets ( V_27 , V_22 , V_42 ) ;
if ( V_27 [ 0 ] == '\0' ) goto V_41;
V_23 = strlen ( V_27 ) ;
if ( V_23 <= 1 ) break;
if ( V_27 [ V_23 - 2 ] != '\\' ) break;
V_23 -= 2 ;
V_27 += V_23 ;
V_22 -= V_23 ;
}
if ( ! F_21 ( & V_15 , V_20 , & V_25 , & V_26 ) ) break;
V_24 = F_20 ( V_28 , V_25 , V_26 ) ;
if ( V_24 < 0 )
{
V_24 = 0 ;
goto V_41;
}
if ( V_24 != 0 )
F_22 ( V_32 , L_14 , V_26 [ 0 ] ) ;
( void ) F_23 ( V_32 ) ;
}
F_22 ( V_32 , L_15 ) ;
V_24 = 1 ;
V_41:
if ( V_21 )
F_24 ( V_21 ) ;
if ( V_38 != NULL )
{
F_15 ( V_38 ) ;
V_38 = NULL ;
}
if ( V_28 != NULL ) F_25 ( V_28 ) ;
if ( V_15 . V_30 != NULL ) F_24 ( V_15 . V_30 ) ;
F_26 () ;
F_27 ( V_32 ) ;
if ( V_32 != NULL )
{
F_28 ( V_32 ) ;
V_32 = NULL ;
}
F_29 ( V_24 ) ;
}
static int F_20 ( T_3 * V_28 , int V_25 , char * V_26 [] )
{
T_1 V_17 , * V_18 ;
int V_23 , V_24 = 1 , V_43 , V_44 ;
if ( ( V_25 <= 0 ) || ( V_26 [ 0 ] == NULL ) )
{ V_24 = 0 ; goto V_41; }
V_17 . V_39 = V_26 [ 0 ] ;
V_18 = ( T_1 * ) F_19 ( V_28 , & V_17 ) ;
if ( V_18 != NULL )
{
V_24 = V_18 -> V_40 ( V_25 , V_26 ) ;
}
else if ( ( strncmp ( V_26 [ 0 ] , L_16 , 3 ) ) == 0 )
{
T_4 * V_45 = F_30 ( stdout , V_33 ) ;
#ifdef F_31
{
T_4 * V_46 = F_3 ( F_32 () ) ;
V_45 = F_33 ( V_46 , V_45 ) ;
}
#endif
V_17 . V_39 = V_26 [ 0 ] + 3 ;
V_24 = ( F_19 ( V_28 , & V_17 ) != NULL ) ;
if ( ! V_24 )
F_22 ( V_45 , L_17 , V_26 [ 0 ] ) ;
else
F_22 ( V_45 , L_17 , V_26 [ 0 ] + 3 ) ;
F_34 ( V_45 ) ;
goto V_41;
}
else if ( ( strcmp ( V_26 [ 0 ] , L_18 ) == 0 ) ||
( strcmp ( V_26 [ 0 ] , L_19 ) == 0 ) ||
( strcmp ( V_26 [ 0 ] , L_20 ) == 0 ) ||
( strcmp ( V_26 [ 0 ] , L_21 ) == 0 ) )
{
V_24 = - 1 ;
goto V_41;
}
else if ( ( strcmp ( V_26 [ 0 ] , V_47 ) == 0 ) ||
( strcmp ( V_26 [ 0 ] , V_48 ) == 0 ) ||
( strcmp ( V_26 [ 0 ] , V_49 ) == 0 ) )
{
int V_50 ;
T_4 * V_45 ;
if ( strcmp ( V_26 [ 0 ] , V_47 ) == 0 )
V_50 = V_51 ;
else if ( strcmp ( V_26 [ 0 ] , V_48 ) == 0 )
V_50 = V_52 ;
else
V_50 = V_53 ;
V_45 = F_30 ( stdout , V_33 ) ;
#ifdef F_31
{
T_4 * V_46 = F_3 ( F_32 () ) ;
V_45 = F_33 ( V_46 , V_45 ) ;
}
#endif
for ( V_18 = V_54 ; V_18 -> V_39 != NULL ; V_18 ++ )
if ( V_18 -> type == V_50 )
F_22 ( V_45 , L_17 , V_18 -> V_39 ) ;
F_34 ( V_45 ) ;
V_24 = 0 ;
goto V_41;
}
else
{
F_22 ( V_32 , L_22 ,
V_26 [ 0 ] ) ;
F_22 ( V_32 , L_23 ) ;
V_23 = 0 ;
V_43 = 0 ;
for ( V_18 = V_54 ; V_18 -> V_39 != NULL ; V_18 ++ )
{
V_44 = 0 ;
if ( ( ( V_23 ++ ) % 5 ) == 0 )
{
F_22 ( V_32 , L_24 ) ;
V_44 = 1 ;
}
if ( V_18 -> type != V_43 )
{
V_43 = V_18 -> type ;
if ( ! V_44 ) F_22 ( V_32 , L_24 ) ;
if ( V_43 == V_52 )
{
V_23 = 1 ;
F_22 ( V_32 ,
L_25 ) ;
}
else if ( V_43 == V_53 )
{
V_23 = 1 ;
F_22 ( V_32 , L_26 ) ;
}
}
F_22 ( V_32 , L_27 , V_18 -> V_39 ) ;
}
F_22 ( V_32 , L_28 ) ;
V_24 = 0 ;
}
V_41:
return ( V_24 ) ;
}
static int F_35 ( const void * V_55 , const void * V_56 )
{
const T_1 * V_57 = V_55 ;
const T_1 * V_58 = V_56 ;
if( V_57 -> type != V_58 -> type )
return V_57 -> type - V_58 -> type ;
return strcmp ( V_57 -> V_39 , V_58 -> V_39 ) ;
}
static T_3 * F_17 ( void )
{
T_3 * V_24 ;
T_1 * V_17 ;
int V_23 ;
for( V_23 = 0 , V_17 = V_54 ; V_17 -> V_39 != NULL ; ++ V_17 , ++ V_23 )
;
qsort ( V_54 , V_23 , sizeof *V_54 , F_35 ) ;
if ( ( V_24 = F_36 ( V_59 , V_60 ) ) == NULL )
return ( NULL ) ;
for ( V_17 = V_54 ; V_17 -> V_39 != NULL ; V_17 ++ )
F_37 ( V_24 , V_17 ) ;
return ( V_24 ) ;
}
static int T_5 V_60 ( const void * V_61 , const void * V_62 )
{
return ( strncmp ( ( ( T_1 * ) V_61 ) -> V_39 ,
( ( T_1 * ) V_62 ) -> V_39 , 8 ) ) ;
}
static unsigned long T_5 V_59 ( const void * V_61 )
{
return ( F_38 ( ( ( T_1 * ) V_61 ) -> V_39 ) ) ;
}
