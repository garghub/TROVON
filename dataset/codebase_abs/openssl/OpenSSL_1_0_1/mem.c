static void * F_1 ( T_1 V_1 , const char * V_2 , int line )
{ return F_2 ( V_1 ) ; }
static void * F_3 ( void * V_3 , T_1 V_1 ,
const char * V_2 , int line )
{ return F_4 ( V_3 , V_1 ) ; }
static void * F_5 ( T_1 V_1 , const char * V_2 , int line )
{ return F_6 ( V_1 ) ; }
int F_7 ( void * (* F_8)( T_1 ) , void * (* F_9)( void * , T_1 ) ,
void (* F_10)( void * ) )
{
F_11 () ;
if ( ! V_4 )
return 0 ;
if ( ( F_8 == 0 ) || ( F_9 == 0 ) || ( F_10 == 0 ) )
return 0 ;
F_2 = F_8 ; V_5 = F_1 ;
F_4 = F_9 ; V_6 = F_3 ;
V_7 = F_10 ;
F_6 = F_8 ; V_8 = F_5 ;
V_9 = F_10 ;
return 1 ;
}
int F_12 (
void * (* F_8)( T_1 , const char * , int ) ,
void * (* F_9)( void * , T_1 , const char * , int ) ,
void (* F_10)( void * ) )
{
if ( ! V_4 )
return 0 ;
if ( ( F_8 == 0 ) || ( F_9 == 0 ) || ( F_10 == 0 ) )
return 0 ;
F_2 = 0 ; V_5 = F_8 ;
F_4 = 0 ; V_6 = F_9 ;
V_7 = F_10 ;
F_6 = 0 ; V_8 = F_8 ;
V_9 = F_10 ;
return 1 ;
}
int F_13 ( void * (* F_8)( T_1 ) , void (* F_10)( void * ) )
{
if ( ! V_4 )
return 0 ;
if ( ( F_8 == NULL ) || ( F_10 == NULL ) )
return 0 ;
F_6 = F_8 ; V_8 = F_5 ;
V_9 = F_10 ;
return 1 ;
}
int F_14 (
void * (* F_8)( T_1 , const char * , int ) ,
void (* F_10)( void * ) )
{
if ( ! V_4 )
return 0 ;
if ( ( F_8 == NULL ) || ( F_10 == NULL ) )
return 0 ;
F_6 = 0 ; V_8 = F_8 ;
V_7 = F_10 ;
return 1 ;
}
int F_15 ( void (* F_8)( void * , int , const char * , int , int ) ,
void (* F_9)( void * , void * , int , const char * , int , int ) ,
void (* F_10)( void * , int ) ,
void (* F_16)( long ) ,
long (* F_17)( void ) )
{
if ( ! V_10 )
return 0 ;
F_11 () ;
V_11 = F_8 ;
V_12 = F_9 ;
V_13 = F_10 ;
V_14 = F_16 ;
V_15 = F_17 ;
return 1 ;
}
void F_18 ( void * (* * F_8)( T_1 ) , void * (* * F_9)( void * , T_1 ) ,
void (* * F_10)( void * ) )
{
if ( F_8 != NULL ) * F_8 = ( V_5 == F_1 ) ?
F_2 : 0 ;
if ( F_9 != NULL ) * F_9 = ( V_6 == F_3 ) ?
F_4 : 0 ;
if ( F_10 != NULL ) * F_10 = V_7 ;
}
void F_19 (
void * (* * F_8)( T_1 , const char * , int ) ,
void * (* * F_9)( void * , T_1 , const char * , int ) ,
void (* * F_10)( void * ) )
{
if ( F_8 != NULL ) * F_8 = ( V_5 != F_1 ) ?
V_5 : 0 ;
if ( F_9 != NULL ) * F_9 = ( V_6 != F_3 ) ?
V_6 : 0 ;
if ( F_10 != NULL ) * F_10 = V_7 ;
}
void F_20 ( void * (* * F_8)( T_1 ) , void (* * F_10)( void * ) )
{
if ( F_8 != NULL ) * F_8 = ( V_8 == F_5 ) ?
F_6 : 0 ;
if ( F_10 != NULL ) * F_10 = V_9 ;
}
void F_21 (
void * (* * F_8)( T_1 , const char * , int ) ,
void (* * F_10)( void * ) )
{
if ( F_8 != NULL ) * F_8 = ( V_8 != F_5 ) ?
V_8 : 0 ;
if ( F_10 != NULL ) * F_10 = V_9 ;
}
void F_22 ( void (* * F_8)( void * , int , const char * , int , int ) ,
void (* * F_9)( void * , void * , int , const char * , int , int ) ,
void (* * F_10)( void * , int ) ,
void (* * F_16)( long ) ,
long (* * F_17)( void ) )
{
if ( F_8 != NULL ) * F_8 = V_11 ;
if ( F_9 != NULL ) * F_9 = V_12 ;
if ( F_10 != NULL ) * F_10 = V_13 ;
if ( F_16 != NULL ) * F_16 = V_14 ;
if ( F_17 != NULL ) * F_17 = V_15 ;
}
void * F_23 ( int V_1 , const char * V_2 , int line )
{
void * V_16 = NULL ;
if ( V_1 <= 0 ) return NULL ;
V_4 = 0 ;
if ( V_11 != NULL )
{
V_10 = 0 ;
V_11 ( NULL , V_1 , V_2 , line , 0 ) ;
}
V_16 = V_8 ( V_1 , V_2 , line ) ;
#ifdef F_24
fprintf ( V_17 , L_1 , V_16 , V_1 ) ;
#endif
if ( V_11 != NULL )
V_11 ( V_16 , V_1 , V_2 , line , 1 ) ;
#ifndef F_25
if( V_16 && ( V_1 > 2048 ) )
{ extern unsigned char V_18 ;
( ( unsigned char * ) V_16 ) [ 0 ] = V_18 ;
}
#endif
return V_16 ;
}
void F_26 ( void * V_3 )
{
if ( V_13 != NULL )
V_13 ( V_3 , 0 ) ;
#ifdef F_24
fprintf ( V_17 , L_2 , V_3 ) ;
#endif
V_9 ( V_3 ) ;
if ( V_13 != NULL )
V_13 ( NULL , 1 ) ;
}
void * F_27 ( int V_1 , const char * V_2 , int line )
{
void * V_16 = NULL ;
if ( V_1 <= 0 ) return NULL ;
V_4 = 0 ;
if ( V_11 != NULL )
{
V_10 = 0 ;
V_11 ( NULL , V_1 , V_2 , line , 0 ) ;
}
V_16 = V_5 ( V_1 , V_2 , line ) ;
#ifdef F_24
fprintf ( V_17 , L_1 , V_16 , V_1 ) ;
#endif
if ( V_11 != NULL )
V_11 ( V_16 , V_1 , V_2 , line , 1 ) ;
#ifndef F_25
if( V_16 && ( V_1 > 2048 ) )
{ extern unsigned char V_18 ;
( ( unsigned char * ) V_16 ) [ 0 ] = V_18 ;
}
#endif
return V_16 ;
}
char * F_28 ( const char * V_3 , const char * V_2 , int line )
{
char * V_16 = F_27 ( strlen ( V_3 ) + 1 , V_2 , line ) ;
strcpy ( V_16 , V_3 ) ;
return V_16 ;
}
void * F_29 ( void * V_3 , int V_1 , const char * V_2 , int line )
{
void * V_16 = NULL ;
if ( V_3 == NULL )
return F_27 ( V_1 , V_2 , line ) ;
if ( V_1 <= 0 ) return NULL ;
if ( V_12 != NULL )
V_12 ( V_3 , NULL , V_1 , V_2 , line , 0 ) ;
V_16 = V_6 ( V_3 , V_1 , V_2 , line ) ;
#ifdef F_24
fprintf ( V_17 , L_3 , V_3 , V_16 , V_1 ) ;
#endif
if ( V_12 != NULL )
V_12 ( V_3 , V_16 , V_1 , V_2 , line , 1 ) ;
return V_16 ;
}
void * F_30 ( void * V_3 , int V_19 , int V_1 , const char * V_2 ,
int line )
{
void * V_16 = NULL ;
if ( V_3 == NULL )
return F_27 ( V_1 , V_2 , line ) ;
if ( V_1 <= 0 ) return NULL ;
if ( V_12 != NULL )
V_12 ( V_3 , NULL , V_1 , V_2 , line , 0 ) ;
V_16 = V_5 ( V_1 , V_2 , line ) ;
if( V_16 )
{
memcpy ( V_16 , V_3 , V_19 ) ;
F_31 ( V_3 , V_19 ) ;
V_7 ( V_3 ) ;
}
#ifdef F_24
fprintf ( V_17 ,
L_3 ,
V_3 , V_16 , V_1 ) ;
#endif
if ( V_12 != NULL )
V_12 ( V_3 , V_16 , V_1 , V_2 , line , 1 ) ;
return V_16 ;
}
void F_32 ( void * V_3 )
{
if ( V_13 != NULL )
V_13 ( V_3 , 0 ) ;
#ifdef F_24
fprintf ( V_17 , L_2 , V_3 ) ;
#endif
V_7 ( V_3 ) ;
if ( V_13 != NULL )
V_13 ( NULL , 1 ) ;
}
void * F_33 ( void * V_20 , int V_1 , const char * V_2 , int line )
{
if ( V_20 != NULL ) F_34 ( V_20 ) ;
V_20 = ( char * ) F_35 ( V_1 ) ;
return ( V_20 ) ;
}
void F_36 ( long V_21 )
{
if ( V_14 != NULL )
V_14 ( V_21 ) ;
}
long F_37 ( void )
{
if ( V_15 != NULL )
return V_15 () ;
return 0 ;
}
