int F_1 (
void * (* F_2)( T_1 , const char * , int ) ,
void * (* F_3)( void * , T_1 , const char * , int ) ,
void (* F_4)( void * , const char * , int ) )
{
if ( ! V_1 )
return 0 ;
if ( F_2 )
V_2 = F_2 ;
if ( F_3 )
V_3 = F_3 ;
if ( F_4 )
V_4 = F_4 ;
return 1 ;
}
int F_5 ( int V_5 )
{
if ( ! V_1 )
return 0 ;
V_6 = V_5 ;
return 1 ;
}
void F_6 (
void * (* * F_2)( T_1 , const char * , int ) ,
void * (* * F_3)( void * , T_1 , const char * , int ) ,
void (* * F_4)( void * , const char * , int ) )
{
if ( F_2 != NULL )
* F_2 = V_2 ;
if ( F_3 != NULL )
* F_3 = V_3 ;
if ( F_4 != NULL )
* F_4 = V_4 ;
}
void * F_7 ( T_1 V_7 , const char * V_8 , int line )
{
void * V_9 = NULL ;
if ( V_2 != NULL && V_2 != F_7 )
return V_2 ( V_7 , V_8 , line ) ;
if ( V_7 <= 0 )
return NULL ;
V_1 = 0 ;
#ifndef F_8
if ( V_6 ) {
F_9 ( NULL , V_7 , 0 , V_8 , line ) ;
V_9 = malloc ( V_7 ) ;
F_9 ( V_9 , V_7 , 1 , V_8 , line ) ;
} else {
V_9 = malloc ( V_7 ) ;
}
#else
F_10 ( V_8 ) ; F_10 ( line ) ;
V_9 = malloc ( V_7 ) ;
#endif
return V_9 ;
}
void * F_11 ( T_1 V_7 , const char * V_8 , int line )
{
void * V_9 = F_7 ( V_7 , V_8 , line ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_7 ) ;
return V_9 ;
}
void * F_12 ( void * V_10 , T_1 V_7 , const char * V_8 , int line )
{
if ( V_3 != NULL && V_3 != & F_12 )
return V_3 ( V_10 , V_7 , V_8 , line ) ;
if ( V_10 == NULL )
return F_7 ( V_7 , V_8 , line ) ;
if ( V_7 == 0 ) {
F_13 ( V_10 , V_8 , line ) ;
return NULL ;
}
V_1 = 0 ;
#ifndef F_8
if ( V_6 ) {
void * V_9 ;
F_14 ( V_10 , NULL , V_7 , 0 , V_8 , line ) ;
V_9 = realloc ( V_10 , V_7 ) ;
F_14 ( V_10 , V_9 , V_7 , 1 , V_8 , line ) ;
return V_9 ;
}
#else
F_10 ( V_8 ) ; F_10 ( line ) ;
#endif
return realloc ( V_10 , V_7 ) ;
}
void * F_15 ( void * V_10 , T_1 V_11 , T_1 V_7 ,
const char * V_8 , int line )
{
void * V_9 = NULL ;
if ( V_10 == NULL )
return F_7 ( V_7 , V_8 , line ) ;
if ( V_7 == 0 ) {
F_16 ( V_10 , V_11 , V_8 , line ) ;
return NULL ;
}
if ( V_7 < V_11 ) {
F_17 ( ( char * ) V_10 + V_7 , V_11 - V_7 ) ;
return V_10 ;
}
V_9 = F_7 ( V_7 , V_8 , line ) ;
if ( V_9 != NULL ) {
memcpy ( V_9 , V_10 , V_11 ) ;
F_16 ( V_10 , V_11 , V_8 , line ) ;
}
return V_9 ;
}
void F_13 ( void * V_10 , const char * V_8 , int line )
{
if ( V_4 != NULL && V_4 != & F_13 ) {
V_4 ( V_10 , V_8 , line ) ;
return;
}
#ifndef F_8
if ( V_6 ) {
F_18 ( V_10 , 0 , V_8 , line ) ;
free ( V_10 ) ;
F_18 ( V_10 , 1 , V_8 , line ) ;
} else {
free ( V_10 ) ;
}
#else
free ( V_10 ) ;
#endif
}
void F_16 ( void * V_10 , T_1 V_7 , const char * V_8 , int line )
{
if ( V_10 == NULL )
return;
if ( V_7 )
F_17 ( V_10 , V_7 ) ;
F_13 ( V_10 , V_8 , line ) ;
}
