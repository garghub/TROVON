static void F_1 ( T_1 * V_1 )
{
int V_2 ;
if( V_1 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
{
F_2 ( V_1 , V_2 ) ;
}
Free ( V_1 ) ;
}
void F_3 ( void )
{
static int V_4 = 1 ;
if ( V_4 )
{
F_4 ( V_5 ) ;
if ( V_4 == 0 )
{
F_5 ( V_5 ) ;
return;
}
V_4 = 0 ;
F_5 ( V_5 ) ;
#ifndef F_6
F_7 ( 0 , V_6 ) ;
F_7 ( 0 , V_7 ) ;
F_7 ( V_8 , V_9 ) ;
#endif
}
}
void F_7 ( int V_10 , T_2 * V_11 )
{
if ( V_12 == NULL )
{
F_4 ( V_13 ) ;
V_12 = F_8 ( V_14 , V_15 ) ;
if ( V_12 == NULL )
{
F_5 ( V_13 ) ;
return;
}
F_5 ( V_13 ) ;
F_3 () ;
}
F_4 ( V_13 ) ;
while ( V_11 -> error )
{
V_11 -> error |= F_9 ( V_10 , 0 , 0 ) ;
F_10 ( V_12 , ( char * ) V_11 ) ;
V_11 ++ ;
}
F_5 ( V_13 ) ;
}
void F_11 ( void )
{
F_4 ( V_5 ) ;
if ( V_12 != NULL )
{
F_12 ( V_12 ) ;
V_12 = NULL ;
}
F_5 ( V_5 ) ;
}
void F_13 ( int V_10 , int V_16 , int V_17 , const char * V_18 ,
int line )
{
T_1 * V_19 ;
#ifdef F_14
if ( strncmp ( V_18 , L_1 , sizeof( L_1 ) - 1 ) == 0 ) {
char * V_20 ;
V_18 += sizeof( L_1 ) - 1 ;
V_20 = & V_18 [ strlen ( V_18 ) - 1 ] ;
if ( * V_20 == ')' )
* V_20 = '\0' ;
if ( ( V_20 = strrchr ( V_18 , '/' ) ) != NULL )
V_18 = & V_20 [ 1 ] ;
}
#endif
V_19 = F_15 () ;
V_19 -> V_21 = ( V_19 -> V_21 + 1 ) % V_3 ;
if ( V_19 -> V_21 == V_19 -> V_22 )
V_19 -> V_22 = ( V_19 -> V_22 + 1 ) % V_3 ;
V_19 -> V_23 [ V_19 -> V_21 ] = F_9 ( V_10 , V_16 , V_17 ) ;
V_19 -> V_24 [ V_19 -> V_21 ] = V_18 ;
V_19 -> V_25 [ V_19 -> V_21 ] = line ;
F_2 ( V_19 , V_19 -> V_21 ) ;
}
void F_16 ( void )
{
T_1 * V_19 ;
V_19 = F_15 () ;
#if 0
for (i=0; i<ERR_NUM_ERRORS; i++)
{
es->err_buffer[i]=0;
es->err_file[i]=NULL;
es->err_line[i]= -1;
err_clear_data(es,i);
}
#endif
V_19 -> V_21 = V_19 -> V_22 = 0 ;
}
unsigned long F_17 ( void )
{ return ( F_18 ( 1 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_19 ( const char * * V_18 ,
int * line )
{ return ( F_18 ( 1 , V_18 , line , NULL , NULL ) ) ; }
unsigned long F_20 ( const char * * V_18 , int * line ,
const char * * V_26 , int * V_27 )
{ return ( F_18 ( 1 , V_18 , line ,
V_26 , V_27 ) ) ; }
unsigned long F_21 ( void )
{ return ( F_18 ( 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_22 ( const char * * V_18 ,
int * line )
{ return ( F_18 ( 0 , V_18 , line , NULL , NULL ) ) ; }
unsigned long F_23 ( const char * * V_18 , int * line ,
const char * * V_26 , int * V_27 )
{ return ( F_18 ( 0 , V_18 , line ,
V_26 , V_27 ) ) ; }
static unsigned long F_18 ( int V_28 , const char * * V_18 , int * line ,
const char * * V_26 , int * V_27 )
{
int V_2 = 0 ;
T_1 * V_19 ;
unsigned long V_29 ;
V_19 = F_15 () ;
if ( V_19 -> V_22 == V_19 -> V_21 ) return ( 0 ) ;
V_2 = ( V_19 -> V_22 + 1 ) % V_3 ;
V_29 = V_19 -> V_23 [ V_2 ] ;
if ( V_28 )
{
V_19 -> V_22 = V_2 ;
V_19 -> V_23 [ V_2 ] = 0 ;
}
if ( ( V_18 != NULL ) && ( line != NULL ) )
{
if ( V_19 -> V_24 [ V_2 ] == NULL )
{
* V_18 = L_2 ;
if ( line != NULL ) * line = 0 ;
}
else
{
* V_18 = V_19 -> V_24 [ V_2 ] ;
if ( line != NULL ) * line = V_19 -> V_25 [ V_2 ] ;
}
}
if ( V_26 != NULL )
{
if ( V_19 -> V_30 [ V_2 ] == NULL )
{
* V_26 = L_3 ;
if ( V_27 != NULL ) * V_27 = 0 ;
}
else
{
* V_26 = V_19 -> V_30 [ V_2 ] ;
if ( V_27 != NULL ) * V_27 = V_19 -> V_31 [ V_2 ] ;
}
}
return ( V_29 ) ;
}
char * F_24 ( unsigned long V_32 , char * V_29 )
{
static char V_33 [ 256 ] ;
const char * V_34 , * V_35 , * V_36 ;
unsigned long V_37 , V_38 , V_39 ;
int V_2 ;
V_37 = F_25 ( V_32 ) ;
V_38 = F_26 ( V_32 ) ;
V_39 = F_27 ( V_32 ) ;
V_34 = F_28 ( V_32 ) ;
V_35 = F_29 ( V_32 ) ;
V_36 = F_30 ( V_32 ) ;
if ( V_29 == NULL ) V_29 = V_33 ;
sprintf ( & ( V_29 [ 0 ] ) , L_4 , V_32 ) ;
V_2 = strlen ( V_29 ) ;
if ( V_34 == NULL )
sprintf ( & ( V_29 [ V_2 ] ) , L_5 , V_37 ) ;
else sprintf ( & ( V_29 [ V_2 ] ) , L_6 , V_34 ) ;
V_2 = strlen ( V_29 ) ;
if ( V_35 == NULL )
sprintf ( & ( V_29 [ V_2 ] ) , L_7 , V_38 ) ;
else sprintf ( & ( V_29 [ V_2 ] ) , L_8 , V_35 ) ;
V_2 = strlen ( V_29 ) ;
if ( V_36 == NULL )
sprintf ( & ( V_29 [ V_2 ] ) , L_9 , V_39 ) ;
else sprintf ( & ( V_29 [ V_2 ] ) , L_8 , V_36 ) ;
return ( V_29 ) ;
}
T_3 * F_31 ( void )
{
return ( V_12 ) ;
}
T_3 * F_32 ( void )
{
return ( V_40 ) ;
}
const char * F_28 ( unsigned long V_32 )
{
T_2 V_41 , * V_42 = NULL ;
unsigned long V_37 ;
V_37 = F_25 ( V_32 ) ;
F_33 ( V_13 ) ;
if ( V_12 != NULL )
{
V_41 . error = F_9 ( V_37 , 0 , 0 ) ;
V_42 = ( T_2 * ) F_34 ( V_12 , ( char * ) & V_41 ) ;
}
F_35 ( V_13 ) ;
return ( ( V_42 == NULL ) ? NULL : V_42 -> string ) ;
}
const char * F_29 ( unsigned long V_32 )
{
T_2 V_41 , * V_42 = NULL ;
unsigned long V_37 , V_38 ;
V_37 = F_25 ( V_32 ) ;
V_38 = F_26 ( V_32 ) ;
F_33 ( V_13 ) ;
if ( V_12 != NULL )
{
V_41 . error = F_9 ( V_37 , V_38 , 0 ) ;
V_42 = ( T_2 * ) F_34 ( V_12 , ( char * ) & V_41 ) ;
}
F_35 ( V_13 ) ;
return ( ( V_42 == NULL ) ? NULL : V_42 -> string ) ;
}
const char * F_30 ( unsigned long V_32 )
{
T_2 V_41 , * V_42 = NULL ;
unsigned long V_37 , V_39 ;
V_37 = F_25 ( V_32 ) ;
V_39 = F_27 ( V_32 ) ;
F_33 ( V_13 ) ;
if ( V_12 != NULL )
{
V_41 . error = F_9 ( V_37 , 0 , V_39 ) ;
V_42 = ( T_2 * ) F_34 ( V_12 , ( char * ) & V_41 ) ;
if ( V_42 == NULL )
{
V_41 . error = F_9 ( 0 , 0 , V_39 ) ;
V_42 = ( T_2 * ) F_34 ( V_12 ,
( char * ) & V_41 ) ;
}
}
F_35 ( V_13 ) ;
return ( ( V_42 == NULL ) ? NULL : V_42 -> string ) ;
}
static unsigned long V_14 ( T_2 * V_43 )
{
unsigned long V_29 , V_37 ;
V_37 = V_43 -> error ;
V_29 = V_37 ^ F_25 ( V_37 ) ^ F_26 ( V_37 ) ;
return ( V_29 ^ V_29 % 19 * 13 ) ;
}
static int V_15 ( T_2 * V_43 , T_2 * V_44 )
{
return ( ( int ) ( V_43 -> error - V_44 -> error ) ) ;
}
static unsigned long F_36 ( T_1 * V_43 )
{
return ( V_43 -> V_45 * 13 ) ;
}
static int F_37 ( T_1 * V_43 , T_1 * V_44 )
{
return ( ( int ) ( ( long ) V_43 -> V_45 - ( long ) V_44 -> V_45 ) ) ;
}
void F_38 ( unsigned long V_45 )
{
T_1 * V_42 , V_46 ;
if ( V_40 == NULL )
return;
if ( V_45 == 0 )
V_45 = ( unsigned long ) F_39 () ;
V_46 . V_45 = V_45 ;
F_4 ( V_5 ) ;
V_42 = ( T_1 * ) F_40 ( V_40 , ( char * ) & V_46 ) ;
F_5 ( V_5 ) ;
if ( V_42 != NULL ) F_1 ( V_42 ) ;
}
T_1 * F_15 ( void )
{
static T_1 V_47 ;
T_1 * V_29 = NULL , V_46 , * V_48 ;
int V_2 ;
unsigned long V_45 ;
V_45 = ( unsigned long ) F_39 () ;
F_33 ( V_5 ) ;
if ( V_40 == NULL )
{
F_35 ( V_5 ) ;
F_4 ( V_5 ) ;
if ( V_40 == NULL )
{
F_41 () ;
V_40 = F_8 ( F_36 , F_37 ) ;
F_42 () ;
F_5 ( V_5 ) ;
if ( V_40 == NULL ) return ( & V_47 ) ;
}
else
F_5 ( V_5 ) ;
}
else
{
V_46 . V_45 = V_45 ;
V_29 = ( T_1 * ) F_34 ( V_40 , ( char * ) & V_46 ) ;
F_35 ( V_5 ) ;
}
if ( V_29 == NULL )
{
V_29 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_29 == NULL ) return ( & V_47 ) ;
V_29 -> V_45 = V_45 ;
V_29 -> V_21 = 0 ;
V_29 -> V_22 = 0 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
{
V_29 -> V_30 [ V_2 ] = NULL ;
V_29 -> V_31 [ V_2 ] = 0 ;
}
F_4 ( V_5 ) ;
V_48 = ( T_1 * ) F_10 ( V_40 , ( char * ) V_29 ) ;
F_5 ( V_5 ) ;
if ( V_48 != NULL )
{
F_1 ( V_48 ) ;
}
}
return ( V_29 ) ;
}
int F_43 ( void )
{
static int V_49 = V_50 ;
return ( V_49 ++ ) ;
}
void F_44 ( char * V_26 , int V_27 )
{
T_1 * V_19 ;
int V_2 ;
V_19 = F_15 () ;
V_2 = V_19 -> V_21 ;
if ( V_2 == 0 )
V_2 = V_3 - 1 ;
V_19 -> V_30 [ V_2 ] = V_26 ;
V_19 -> V_31 [ V_19 -> V_21 ] = V_27 ;
}
void F_45 ( int V_51 , ... )
{
T_4 args ;
int V_2 , V_52 , V_1 ;
char * V_11 , * V_42 , * V_43 ;
V_1 = 64 ;
V_11 = Malloc ( V_1 + 1 ) ;
if ( V_11 == NULL ) return;
V_11 [ 0 ] = '\0' ;
va_start ( args , V_51 ) ;
V_52 = 0 ;
for ( V_2 = 0 ; V_2 < V_51 ; V_2 ++ )
{
V_43 = va_arg ( args , char * ) ;
if ( V_43 != NULL )
{
V_52 += strlen ( V_43 ) ;
if ( V_52 > V_1 )
{
V_1 = V_52 + 20 ;
V_42 = Realloc ( V_11 , V_1 + 1 ) ;
if ( V_42 == NULL )
{
Free ( V_11 ) ;
return;
}
else
V_11 = V_42 ;
}
strcat ( V_11 , V_43 ) ;
}
}
F_44 ( V_11 , V_53 | V_54 ) ;
va_end ( args ) ;
}
