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
V_19 = F_14 () ;
V_19 -> V_20 = ( V_19 -> V_20 + 1 ) % V_3 ;
if ( V_19 -> V_20 == V_19 -> V_21 )
V_19 -> V_21 = ( V_19 -> V_21 + 1 ) % V_3 ;
V_19 -> V_22 [ V_19 -> V_20 ] = F_9 ( V_10 , V_16 , V_17 ) ;
V_19 -> V_23 [ V_19 -> V_20 ] = V_18 ;
V_19 -> V_24 [ V_19 -> V_20 ] = line ;
F_2 ( V_19 , V_19 -> V_20 ) ;
}
void F_15 ( void )
{
T_1 * V_19 ;
V_19 = F_14 () ;
#if 0
for (i=0; i<ERR_NUM_ERRORS; i++)
{
es->err_buffer[i]=0;
es->err_file[i]=NULL;
es->err_line[i]= -1;
err_clear_data(es,i);
}
#endif
V_19 -> V_20 = V_19 -> V_21 = 0 ;
}
unsigned long F_16 ( void )
{ return ( F_17 ( 1 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_18 ( const char * * V_18 ,
int * line )
{ return ( F_17 ( 1 , V_18 , line , NULL , NULL ) ) ; }
unsigned long F_19 ( const char * * V_18 , int * line ,
const char * * V_25 , int * V_26 )
{ return ( F_17 ( 1 , V_18 , line ,
V_25 , V_26 ) ) ; }
unsigned long F_20 ( void )
{ return ( F_17 ( 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_21 ( const char * * V_18 ,
int * line )
{ return ( F_17 ( 0 , V_18 , line , NULL , NULL ) ) ; }
unsigned long F_22 ( const char * * V_18 , int * line ,
const char * * V_25 , int * V_26 )
{ return ( F_17 ( 0 , V_18 , line ,
V_25 , V_26 ) ) ; }
static unsigned long F_17 ( int V_27 , const char * * V_18 , int * line ,
const char * * V_25 , int * V_26 )
{
int V_2 = 0 ;
T_1 * V_19 ;
unsigned long V_28 ;
V_19 = F_14 () ;
if ( V_19 -> V_21 == V_19 -> V_20 ) return ( 0 ) ;
V_2 = ( V_19 -> V_21 + 1 ) % V_3 ;
V_28 = V_19 -> V_22 [ V_2 ] ;
if ( V_27 )
{
V_19 -> V_21 = V_2 ;
V_19 -> V_22 [ V_2 ] = 0 ;
}
if ( ( V_18 != NULL ) && ( line != NULL ) )
{
if ( V_19 -> V_23 [ V_2 ] == NULL )
{
* V_18 = L_1 ;
if ( line != NULL ) * line = 0 ;
}
else
{
* V_18 = V_19 -> V_23 [ V_2 ] ;
if ( line != NULL ) * line = V_19 -> V_24 [ V_2 ] ;
}
}
if ( V_25 != NULL )
{
if ( V_19 -> V_29 [ V_2 ] == NULL )
{
* V_25 = L_2 ;
if ( V_26 != NULL ) * V_26 = 0 ;
}
else
{
* V_25 = V_19 -> V_29 [ V_2 ] ;
if ( V_26 != NULL ) * V_26 = V_19 -> V_30 [ V_2 ] ;
}
}
return ( V_28 ) ;
}
char * F_23 ( unsigned long V_31 , char * V_28 )
{
static char V_32 [ 256 ] ;
const char * V_33 , * V_34 , * V_35 ;
unsigned long V_36 , V_37 , V_38 ;
int V_2 ;
V_36 = F_24 ( V_31 ) ;
V_37 = F_25 ( V_31 ) ;
V_38 = F_26 ( V_31 ) ;
V_33 = F_27 ( V_31 ) ;
V_34 = F_28 ( V_31 ) ;
V_35 = F_29 ( V_31 ) ;
if ( V_28 == NULL ) V_28 = V_32 ;
sprintf ( & ( V_28 [ 0 ] ) , L_3 , V_31 ) ;
V_2 = strlen ( V_28 ) ;
if ( V_33 == NULL )
sprintf ( & ( V_28 [ V_2 ] ) , L_4 , V_36 ) ;
else sprintf ( & ( V_28 [ V_2 ] ) , L_5 , V_33 ) ;
V_2 = strlen ( V_28 ) ;
if ( V_34 == NULL )
sprintf ( & ( V_28 [ V_2 ] ) , L_6 , V_37 ) ;
else sprintf ( & ( V_28 [ V_2 ] ) , L_7 , V_34 ) ;
V_2 = strlen ( V_28 ) ;
if ( V_35 == NULL )
sprintf ( & ( V_28 [ V_2 ] ) , L_8 , V_38 ) ;
else sprintf ( & ( V_28 [ V_2 ] ) , L_7 , V_35 ) ;
return ( V_28 ) ;
}
T_3 * F_30 ( void )
{
return ( V_12 ) ;
}
T_3 * F_31 ( void )
{
return ( V_39 ) ;
}
const char * F_27 ( unsigned long V_31 )
{
T_2 V_40 , * V_41 = NULL ;
unsigned long V_36 ;
V_36 = F_24 ( V_31 ) ;
F_32 ( V_13 ) ;
if ( V_12 != NULL )
{
V_40 . error = F_9 ( V_36 , 0 , 0 ) ;
V_41 = ( T_2 * ) F_33 ( V_12 , ( char * ) & V_40 ) ;
}
F_34 ( V_13 ) ;
return ( ( V_41 == NULL ) ? NULL : V_41 -> string ) ;
}
const char * F_28 ( unsigned long V_31 )
{
T_2 V_40 , * V_41 = NULL ;
unsigned long V_36 , V_37 ;
V_36 = F_24 ( V_31 ) ;
V_37 = F_25 ( V_31 ) ;
F_32 ( V_13 ) ;
if ( V_12 != NULL )
{
V_40 . error = F_9 ( V_36 , V_37 , 0 ) ;
V_41 = ( T_2 * ) F_33 ( V_12 , ( char * ) & V_40 ) ;
}
F_34 ( V_13 ) ;
return ( ( V_41 == NULL ) ? NULL : V_41 -> string ) ;
}
const char * F_29 ( unsigned long V_31 )
{
T_2 V_40 , * V_41 = NULL ;
unsigned long V_36 , V_38 ;
V_36 = F_24 ( V_31 ) ;
V_38 = F_26 ( V_31 ) ;
F_32 ( V_13 ) ;
if ( V_12 != NULL )
{
V_40 . error = F_9 ( V_36 , 0 , V_38 ) ;
V_41 = ( T_2 * ) F_33 ( V_12 , ( char * ) & V_40 ) ;
if ( V_41 == NULL )
{
V_40 . error = F_9 ( 0 , 0 , V_38 ) ;
V_41 = ( T_2 * ) F_33 ( V_12 ,
( char * ) & V_40 ) ;
}
}
F_34 ( V_13 ) ;
return ( ( V_41 == NULL ) ? NULL : V_41 -> string ) ;
}
static unsigned long V_14 ( T_2 * V_42 )
{
unsigned long V_28 , V_36 ;
V_36 = V_42 -> error ;
V_28 = V_36 ^ F_24 ( V_36 ) ^ F_25 ( V_36 ) ;
return ( V_28 ^ V_28 % 19 * 13 ) ;
}
static int V_15 ( T_2 * V_42 , T_2 * V_43 )
{
return ( ( int ) ( V_42 -> error - V_43 -> error ) ) ;
}
static unsigned long F_35 ( T_1 * V_42 )
{
return ( V_42 -> V_44 * 13 ) ;
}
static int F_36 ( T_1 * V_42 , T_1 * V_43 )
{
return ( ( int ) ( ( long ) V_42 -> V_44 - ( long ) V_43 -> V_44 ) ) ;
}
void F_37 ( unsigned long V_44 )
{
T_1 * V_41 , V_45 ;
if ( V_39 == NULL )
return;
if ( V_44 == 0 )
V_44 = ( unsigned long ) F_38 () ;
V_45 . V_44 = V_44 ;
F_4 ( V_5 ) ;
V_41 = ( T_1 * ) F_39 ( V_39 , ( char * ) & V_45 ) ;
F_5 ( V_5 ) ;
if ( V_41 != NULL ) F_1 ( V_41 ) ;
}
T_1 * F_14 ( void )
{
static T_1 V_46 ;
T_1 * V_28 = NULL , V_45 , * V_47 ;
int V_2 ;
unsigned long V_44 ;
V_44 = ( unsigned long ) F_38 () ;
F_32 ( V_5 ) ;
if ( V_39 == NULL )
{
F_34 ( V_5 ) ;
F_4 ( V_5 ) ;
if ( V_39 == NULL )
{
F_40 () ;
V_39 = F_8 ( F_35 , F_36 ) ;
F_41 () ;
F_5 ( V_5 ) ;
if ( V_39 == NULL ) return ( & V_46 ) ;
}
else
F_5 ( V_5 ) ;
}
else
{
V_45 . V_44 = V_44 ;
V_28 = ( T_1 * ) F_33 ( V_39 , ( char * ) & V_45 ) ;
F_34 ( V_5 ) ;
}
if ( V_28 == NULL )
{
V_28 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_28 == NULL ) return ( & V_46 ) ;
V_28 -> V_44 = V_44 ;
V_28 -> V_20 = 0 ;
V_28 -> V_21 = 0 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
{
V_28 -> V_29 [ V_2 ] = NULL ;
V_28 -> V_30 [ V_2 ] = 0 ;
}
F_4 ( V_5 ) ;
V_47 = ( T_1 * ) F_10 ( V_39 , ( char * ) V_28 ) ;
F_5 ( V_5 ) ;
if ( V_47 != NULL )
{
F_1 ( V_47 ) ;
}
}
return ( V_28 ) ;
}
int F_42 ( void )
{
static int V_48 = V_49 ;
return ( V_48 ++ ) ;
}
void F_43 ( char * V_25 , int V_26 )
{
T_1 * V_19 ;
int V_2 ;
V_19 = F_14 () ;
V_2 = V_19 -> V_20 ;
if ( V_2 == 0 )
V_2 = V_3 - 1 ;
V_19 -> V_29 [ V_2 ] = V_25 ;
V_19 -> V_30 [ V_19 -> V_20 ] = V_26 ;
}
void F_44 ( int V_50 , ... )
{
T_4 args ;
int V_2 , V_51 , V_1 ;
char * V_11 , * V_41 , * V_42 ;
V_1 = 64 ;
V_11 = Malloc ( V_1 + 1 ) ;
if ( V_11 == NULL ) return;
V_11 [ 0 ] = '\0' ;
va_start ( args , V_50 ) ;
V_51 = 0 ;
for ( V_2 = 0 ; V_2 < V_50 ; V_2 ++ )
{
V_42 = va_arg ( args , char * ) ;
if ( V_42 != NULL )
{
V_51 += strlen ( V_42 ) ;
if ( V_51 > V_1 )
{
V_1 = V_51 + 20 ;
V_41 = Realloc ( V_11 , V_1 + 1 ) ;
if ( V_41 == NULL )
{
Free ( V_11 ) ;
return;
}
else
V_11 = V_41 ;
}
strcat ( V_11 , V_42 ) ;
}
}
F_43 ( V_11 , V_52 | V_53 ) ;
va_end ( args ) ;
}
