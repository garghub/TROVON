static void F_1 ()
{
static char V_1 [ V_2 ] [ V_3 ] ;
int V_4 ;
F_2 ( V_5 ) ;
for ( V_4 = 1 ; V_4 <= V_2 ; V_4 ++ )
{
T_1 * V_6 = & V_7 [ V_4 - 1 ] ;
V_6 -> error = ( unsigned long ) V_4 ;
if ( V_6 -> string == NULL )
{
char ( * V_8 ) [ V_3 ] = & ( V_1 [ V_4 - 1 ] ) ;
char * V_9 = strerror ( V_4 ) ;
if ( V_9 != NULL )
{
strncpy ( * V_8 , V_9 , sizeof *V_8 ) ;
( * V_8 ) [ sizeof *V_8 - 1] = '\0' ;
V_6 -> string = * V_8 ;
}
}
if ( V_6 -> string == NULL )
V_6 -> string = L_1 ;
}
F_3 ( V_5 ) ;
}
static void F_4 ( T_2 * V_10 )
{
int V_4 ;
if( V_10 == NULL )
return;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ )
{
F_5 ( V_10 , V_4 ) ;
}
F_6 ( V_10 ) ;
}
void F_7 ( void )
{
static int V_12 = 1 ;
if ( V_12 )
{
F_2 ( V_13 ) ;
if ( V_12 == 0 )
{
F_3 ( V_13 ) ;
return;
}
F_3 ( V_13 ) ;
#ifndef F_8
F_9 ( 0 , V_14 ) ;
F_9 ( 0 , V_15 ) ;
F_9 ( V_16 , V_17 ) ;
F_1 () ;
F_9 ( V_16 , V_7 ) ;
#endif
V_12 = 0 ;
}
}
void F_9 ( int V_18 , T_1 * V_6 )
{
if ( V_19 == NULL )
{
F_2 ( V_5 ) ;
V_19 = F_10 ( V_20 , V_21 ) ;
if ( V_19 == NULL )
{
F_3 ( V_5 ) ;
return;
}
F_3 ( V_5 ) ;
F_7 () ;
}
F_2 ( V_5 ) ;
while ( V_6 -> error )
{
V_6 -> error |= F_11 ( V_18 , 0 , 0 ) ;
F_12 ( V_19 , V_6 ) ;
V_6 ++ ;
}
F_3 ( V_5 ) ;
}
void F_13 ( void )
{
F_2 ( V_13 ) ;
if ( V_19 != NULL )
{
F_14 ( V_19 ) ;
V_19 = NULL ;
}
F_3 ( V_13 ) ;
}
void F_15 ( int V_18 , int V_22 , int V_23 , const char * V_24 ,
int line )
{
T_2 * V_25 ;
#ifdef F_16
if ( strncmp ( V_24 , L_2 , sizeof( L_2 ) - 1 ) == 0 ) {
char * V_26 ;
V_24 += sizeof( L_2 ) - 1 ;
V_26 = & V_24 [ strlen ( V_24 ) - 1 ] ;
if ( * V_26 == ')' )
* V_26 = '\0' ;
if ( ( V_26 = strrchr ( V_24 , '/' ) ) != NULL )
V_24 = & V_26 [ 1 ] ;
}
#endif
V_25 = F_17 () ;
V_25 -> V_27 = ( V_25 -> V_27 + 1 ) % V_11 ;
if ( V_25 -> V_27 == V_25 -> V_28 )
V_25 -> V_28 = ( V_25 -> V_28 + 1 ) % V_11 ;
V_25 -> V_29 [ V_25 -> V_27 ] = F_11 ( V_18 , V_22 , V_23 ) ;
V_25 -> V_30 [ V_25 -> V_27 ] = V_24 ;
V_25 -> V_31 [ V_25 -> V_27 ] = line ;
F_5 ( V_25 , V_25 -> V_27 ) ;
}
void F_18 ( void )
{
T_2 * V_25 ;
V_25 = F_17 () ;
#if 0
for (i=0; i<ERR_NUM_ERRORS; i++)
{
es->err_buffer[i]=0;
es->err_file[i]=NULL;
es->err_line[i]= -1;
err_clear_data(es,i);
}
#endif
V_25 -> V_27 = V_25 -> V_28 = 0 ;
}
unsigned long F_19 ( void )
{ return ( F_20 ( 1 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_21 ( const char * * V_24 ,
int * line )
{ return ( F_20 ( 1 , V_24 , line , NULL , NULL ) ) ; }
unsigned long F_22 ( const char * * V_24 , int * line ,
const char * * V_32 , int * V_33 )
{ return ( F_20 ( 1 , V_24 , line ,
V_32 , V_33 ) ) ; }
unsigned long F_23 ( void )
{ return ( F_20 ( 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_24 ( const char * * V_24 ,
int * line )
{ return ( F_20 ( 0 , V_24 , line , NULL , NULL ) ) ; }
unsigned long F_25 ( const char * * V_24 , int * line ,
const char * * V_32 , int * V_33 )
{ return ( F_20 ( 0 , V_24 , line ,
V_32 , V_33 ) ) ; }
static unsigned long F_20 ( int V_34 , const char * * V_24 , int * line ,
const char * * V_32 , int * V_33 )
{
int V_4 = 0 ;
T_2 * V_25 ;
unsigned long V_35 ;
V_25 = F_17 () ;
if ( V_25 -> V_28 == V_25 -> V_27 ) return ( 0 ) ;
V_4 = ( V_25 -> V_28 + 1 ) % V_11 ;
V_35 = V_25 -> V_29 [ V_4 ] ;
if ( V_34 )
{
V_25 -> V_28 = V_4 ;
V_25 -> V_29 [ V_4 ] = 0 ;
}
if ( ( V_24 != NULL ) && ( line != NULL ) )
{
if ( V_25 -> V_30 [ V_4 ] == NULL )
{
* V_24 = L_3 ;
if ( line != NULL ) * line = 0 ;
}
else
{
* V_24 = V_25 -> V_30 [ V_4 ] ;
if ( line != NULL ) * line = V_25 -> V_31 [ V_4 ] ;
}
}
if ( V_32 != NULL )
{
if ( V_25 -> V_36 [ V_4 ] == NULL )
{
* V_32 = L_4 ;
if ( V_33 != NULL ) * V_33 = 0 ;
}
else
{
* V_32 = V_25 -> V_36 [ V_4 ] ;
if ( V_33 != NULL ) * V_33 = V_25 -> V_37 [ V_4 ] ;
}
}
return ( V_35 ) ;
}
void F_26 ( unsigned long V_38 , char * V_39 , T_3 V_40 )
{
char V_41 [ 64 ] , V_42 [ 64 ] , V_43 [ 64 ] ;
const char * V_44 , * V_45 , * V_46 ;
unsigned long V_47 , V_48 , V_49 ;
V_47 = F_27 ( V_38 ) ;
V_48 = F_28 ( V_38 ) ;
V_49 = F_29 ( V_38 ) ;
V_44 = F_30 ( V_38 ) ;
V_45 = F_31 ( V_38 ) ;
V_46 = F_32 ( V_38 ) ;
if ( V_44 == NULL )
F_33 ( V_41 , sizeof( V_41 ) , L_5 , V_47 ) ;
if ( V_45 == NULL )
F_33 ( V_42 , sizeof( V_42 ) , L_6 , V_48 ) ;
if ( V_46 == NULL )
F_33 ( V_43 , sizeof( V_43 ) , L_7 , V_49 ) ;
F_33 ( V_39 , V_40 , L_8 , V_38 , V_44 ? V_44 : V_41 ,
V_45 ? V_45 : V_42 , V_46 ? V_46 : V_43 ) ;
if ( strlen ( V_39 ) == V_40 - 1 )
{
#define F_34 4
if ( V_40 > F_34 )
{
int V_4 ;
char * V_10 = V_39 ;
for ( V_4 = 0 ; V_4 < F_34 ; V_4 ++ )
{
char * V_50 = strchr ( V_10 , ':' ) ;
if ( V_50 == NULL || V_50 > & V_39 [ V_40 - 1 ] - F_34 + V_4 )
{
V_50 = & V_39 [ V_40 - 1 ] - F_34 + V_4 ;
* V_50 = ':' ;
}
V_10 = V_50 + 1 ;
}
}
}
}
char * F_35 ( unsigned long V_38 , char * V_35 )
{
static char V_39 [ 256 ] ;
if ( V_35 == NULL ) V_35 = V_39 ;
F_26 ( V_38 , V_35 , 256 ) ;
return ( V_35 ) ;
}
T_4 * F_36 ( void )
{
return ( V_19 ) ;
}
T_4 * F_37 ( void )
{
return ( V_51 ) ;
}
const char * F_30 ( unsigned long V_38 )
{
T_1 V_52 , * V_53 = NULL ;
unsigned long V_47 ;
V_47 = F_27 ( V_38 ) ;
F_2 ( V_5 ) ;
if ( V_19 != NULL )
{
V_52 . error = F_11 ( V_47 , 0 , 0 ) ;
V_53 = ( T_1 * ) F_38 ( V_19 , & V_52 ) ;
}
F_3 ( V_5 ) ;
return ( ( V_53 == NULL ) ? NULL : V_53 -> string ) ;
}
const char * F_31 ( unsigned long V_38 )
{
T_1 V_52 , * V_53 = NULL ;
unsigned long V_47 , V_48 ;
V_47 = F_27 ( V_38 ) ;
V_48 = F_28 ( V_38 ) ;
F_2 ( V_5 ) ;
if ( V_19 != NULL )
{
V_52 . error = F_11 ( V_47 , V_48 , 0 ) ;
V_53 = ( T_1 * ) F_38 ( V_19 , & V_52 ) ;
}
F_3 ( V_5 ) ;
return ( ( V_53 == NULL ) ? NULL : V_53 -> string ) ;
}
const char * F_32 ( unsigned long V_38 )
{
T_1 V_52 , * V_53 = NULL ;
unsigned long V_47 , V_49 ;
V_47 = F_27 ( V_38 ) ;
V_49 = F_29 ( V_38 ) ;
F_2 ( V_5 ) ;
if ( V_19 != NULL )
{
V_52 . error = F_11 ( V_47 , 0 , V_49 ) ;
V_53 = ( T_1 * ) F_38 ( V_19 , & V_52 ) ;
if ( V_53 == NULL )
{
V_52 . error = F_11 ( 0 , 0 , V_49 ) ;
V_53 = ( T_1 * ) F_38 ( V_19 , & V_52 ) ;
}
}
F_3 ( V_5 ) ;
return ( ( V_53 == NULL ) ? NULL : V_53 -> string ) ;
}
static unsigned long V_20 ( T_1 * V_54 )
{
unsigned long V_35 , V_47 ;
V_47 = V_54 -> error ;
V_35 = V_47 ^ F_27 ( V_47 ) ^ F_28 ( V_47 ) ;
return ( V_35 ^ V_35 % 19 * 13 ) ;
}
static int V_21 ( T_1 * V_54 , T_1 * V_55 )
{
return ( ( int ) ( V_54 -> error - V_55 -> error ) ) ;
}
static unsigned long F_39 ( T_2 * V_54 )
{
return ( V_54 -> V_56 * 13 ) ;
}
static int F_40 ( T_2 * V_54 , T_2 * V_55 )
{
return ( ( int ) ( ( long ) V_54 -> V_56 - ( long ) V_55 -> V_56 ) ) ;
}
void F_41 ( unsigned long V_56 )
{
T_2 * V_53 = NULL , V_57 ;
if ( V_51 == NULL )
return;
if ( V_56 == 0 )
V_56 = ( unsigned long ) F_42 () ;
V_57 . V_56 = V_56 ;
F_2 ( V_13 ) ;
if ( V_51 )
{
V_53 = ( T_2 * ) F_43 ( V_51 , & V_57 ) ;
if ( F_44 ( V_51 ) == 0 )
{
F_14 ( V_51 ) ;
V_51 = NULL ;
}
}
F_3 ( V_13 ) ;
if ( V_53 != NULL ) F_4 ( V_53 ) ;
}
T_2 * F_17 ( void )
{
static T_2 V_58 ;
T_2 * V_35 = NULL , V_57 , * V_59 = NULL ;
int V_60 ;
int V_4 ;
unsigned long V_56 ;
V_56 = ( unsigned long ) F_42 () ;
F_2 ( V_13 ) ;
if ( V_51 != NULL )
{
V_57 . V_56 = V_56 ;
V_35 = ( T_2 * ) F_38 ( V_51 , & V_57 ) ;
}
F_3 ( V_13 ) ;
if ( V_35 == NULL )
{
V_35 = ( T_2 * ) F_45 ( sizeof( T_2 ) ) ;
if ( V_35 == NULL ) return ( & V_58 ) ;
V_35 -> V_56 = V_56 ;
V_35 -> V_27 = 0 ;
V_35 -> V_28 = 0 ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ )
{
V_35 -> V_36 [ V_4 ] = NULL ;
V_35 -> V_37 [ V_4 ] = 0 ;
}
F_2 ( V_13 ) ;
if ( V_51 == NULL )
V_51 = F_10 ( F_39 , F_40 ) ;
if ( V_51 == NULL )
V_60 = 0 ;
else
{
V_59 = ( T_2 * ) F_12 ( V_51 , V_35 ) ;
V_60 = 1 ;
}
F_3 ( V_13 ) ;
if ( ! V_60 )
{
F_4 ( V_35 ) ;
return ( & V_58 ) ;
}
if ( V_59 != NULL )
{
F_4 ( V_59 ) ;
}
}
return ( V_35 ) ;
}
int F_46 ( void )
{
static int V_61 = V_62 ;
return ( V_61 ++ ) ;
}
void F_47 ( char * V_32 , int V_33 )
{
T_2 * V_25 ;
int V_4 ;
V_25 = F_17 () ;
V_4 = V_25 -> V_27 ;
if ( V_4 == 0 )
V_4 = V_11 - 1 ;
V_25 -> V_36 [ V_4 ] = V_32 ;
V_25 -> V_37 [ V_25 -> V_27 ] = V_33 ;
}
void F_48 ( int V_63 , ... )
{
T_5 args ;
int V_4 , V_64 , V_10 ;
char * V_6 , * V_53 , * V_54 ;
V_10 = 64 ;
V_6 = F_45 ( V_10 + 1 ) ;
if ( V_6 == NULL ) return;
V_6 [ 0 ] = '\0' ;
va_start ( args , V_63 ) ;
V_64 = 0 ;
for ( V_4 = 0 ; V_4 < V_63 ; V_4 ++ )
{
V_54 = va_arg ( args , char * ) ;
if ( V_54 != NULL )
{
V_64 += strlen ( V_54 ) ;
if ( V_64 > V_10 )
{
V_10 = V_64 + 20 ;
V_53 = F_49 ( V_6 , V_10 + 1 ) ;
if ( V_53 == NULL )
{
F_6 ( V_6 ) ;
return;
}
else
V_6 = V_53 ;
}
strcat ( V_6 , V_54 ) ;
}
}
F_47 ( V_6 , V_65 | V_66 ) ;
va_end ( args ) ;
}
