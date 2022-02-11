int F_1 ( void * (* F_2)( T_1 ) , void * (* F_3)( void * , T_1 ) ,
void (* F_4)( void * ) )
{
if ( ! V_1 )
return 0 ;
if ( ( F_2 == NULL ) || ( F_3 == NULL ) || ( F_4 == NULL ) )
return 0 ;
V_2 = F_2 ;
V_3 = F_3 ;
V_4 = F_4 ;
V_5 = F_2 ;
V_6 = F_4 ;
return 1 ;
}
int F_5 ( void * (* F_2)( T_1 ) , void (* F_4)( void * ) )
{
if ( ! V_1 )
return 0 ;
if ( ( F_2 == NULL ) || ( F_4 == NULL ) )
return 0 ;
V_5 = F_2 ;
V_6 = F_4 ;
return 1 ;
}
int F_6 ( void (* F_2)( void * , int , const char * , int , int ) ,
void (* F_3)( void * , void * , int , const char * , int , int ) ,
void (* F_4)( void * , int ) ,
void (* F_7)( long ) ,
long (* F_8)( void ) )
{
if ( ! V_7 )
return 0 ;
V_8 = F_2 ;
V_9 = F_3 ;
V_10 = F_4 ;
V_11 = F_7 ;
V_12 = F_8 ;
return 1 ;
}
void F_9 ( void * (* * F_2)( T_1 ) , void * (* * F_3)( void * , T_1 ) ,
void (* * F_4)( void * ) )
{
if ( F_2 != NULL ) * F_2 = V_2 ;
if ( F_3 != NULL ) * F_3 = V_3 ;
if ( F_4 != NULL ) * F_4 = V_4 ;
}
void F_10 ( void * (* * F_2)( T_1 ) , void (* * F_4)( void * ) )
{
if ( F_2 != NULL ) * F_2 = V_5 ;
if ( F_4 != NULL ) * F_4 = V_6 ;
}
void F_11 ( void (* * F_2)( void * , int , const char * , int , int ) ,
void (* * F_3)( void * , void * , int , const char * , int , int ) ,
void (* * F_4)( void * , int ) ,
void (* * F_7)( long ) ,
long (* * F_8)( void ) )
{
if ( F_2 != NULL ) * F_2 = V_8 ;
if ( F_3 != NULL ) * F_3 = V_9 ;
if ( F_4 != NULL ) * F_4 = V_10 ;
if ( F_7 != NULL ) * F_7 = V_11 ;
if ( F_8 != NULL ) * F_8 = V_12 ;
}
void * F_12 ( int V_13 , const char * V_14 , int line )
{
void * V_15 = NULL ;
V_1 = 0 ;
if ( V_8 != NULL )
{
V_7 = 0 ;
V_8 ( NULL , V_13 , V_14 , line , 0 ) ;
}
V_15 = V_5 ( V_13 ) ;
#ifdef F_13
fprintf ( V_16 , L_1 , V_15 , V_13 ) ;
#endif
if ( V_8 != NULL )
V_8 ( V_15 , V_13 , V_14 , line , 1 ) ;
return V_15 ;
}
void F_14 ( void * V_17 )
{
if ( V_10 != NULL )
V_10 ( V_17 , 0 ) ;
#ifdef F_13
fprintf ( V_16 , L_2 , V_17 ) ;
#endif
V_6 ( V_17 ) ;
if ( V_10 != NULL )
V_10 ( NULL , 1 ) ;
}
void * F_15 ( int V_13 , const char * V_14 , int line )
{
void * V_15 = NULL ;
V_1 = 0 ;
if ( V_8 != NULL )
{
V_7 = 0 ;
V_8 ( NULL , V_13 , V_14 , line , 0 ) ;
}
V_15 = V_2 ( V_13 ) ;
#ifdef F_13
fprintf ( V_16 , L_1 , V_15 , V_13 ) ;
#endif
if ( V_8 != NULL )
V_8 ( V_15 , V_13 , V_14 , line , 1 ) ;
return V_15 ;
}
void * F_16 ( void * V_17 , int V_13 , const char * V_14 , int line )
{
void * V_15 = NULL ;
if ( V_9 != NULL )
V_9 ( V_17 , NULL , V_13 , V_14 , line , 0 ) ;
V_15 = V_3 ( V_17 , V_13 ) ;
#ifdef F_13
fprintf ( V_16 , L_3 , V_17 , V_15 , V_13 ) ;
#endif
if ( V_9 != NULL )
V_9 ( V_17 , V_15 , V_13 , V_14 , line , 1 ) ;
return V_15 ;
}
void F_17 ( void * V_17 )
{
if ( V_10 != NULL )
V_10 ( V_17 , 0 ) ;
#ifdef F_13
fprintf ( V_16 , L_2 , V_17 ) ;
#endif
V_4 ( V_17 ) ;
if ( V_10 != NULL )
V_10 ( NULL , 1 ) ;
}
void * F_18 ( void * V_18 , int V_13 , const char * V_14 , int line )
{
if ( V_18 != NULL ) F_19 ( V_18 ) ;
V_18 = ( char * ) F_20 ( V_13 ) ;
return ( V_18 ) ;
}
void F_21 ( long V_19 )
{
if ( V_11 != NULL )
V_11 ( V_19 ) ;
}
long F_22 ( void )
{
if ( V_12 != NULL )
return V_12 () ;
return 0 ;
}
