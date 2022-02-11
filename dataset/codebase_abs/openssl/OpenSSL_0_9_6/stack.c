T_1 * F_1 ( int (* F_2)( const char * const * , const char * const * ) )
{
T_1 * V_1 ;
int V_2 ;
if ( ( V_1 = ( T_1 * ) F_3 ( sizeof( T_1 ) ) ) == NULL )
goto V_3;
if ( ( V_1 -> V_4 = ( char * * ) F_3 ( sizeof( char * ) * V_5 ) ) == NULL )
goto V_6;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ )
V_1 -> V_4 [ V_2 ] = NULL ;
V_1 -> V_7 = F_2 ;
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
V_1 -> V_10 = 0 ;
return ( V_1 ) ;
V_6:
F_4 ( V_1 ) ;
V_3:
return ( NULL ) ;
}
int F_5 ( T_1 * V_11 , char * V_4 , int V_12 )
{
char * * V_13 ;
if( V_11 == NULL ) return 0 ;
if ( V_11 -> V_8 <= V_11 -> V_9 + 1 )
{
V_13 = ( char * * ) F_6 ( ( char * ) V_11 -> V_4 ,
( unsigned int ) sizeof( char * ) * V_11 -> V_8 * 2 ) ;
if ( V_13 == NULL )
return ( 0 ) ;
V_11 -> V_4 = V_13 ;
V_11 -> V_8 *= 2 ;
}
if ( ( V_12 >= ( int ) V_11 -> V_9 ) || ( V_12 < 0 ) )
V_11 -> V_4 [ V_11 -> V_9 ] = V_4 ;
else
{
int V_2 ;
char * * V_14 , * * V_15 ;
V_14 = ( char * * ) V_11 -> V_4 ;
V_15 = ( char * * ) & ( V_11 -> V_4 [ 1 ] ) ;
for ( V_2 = V_11 -> V_9 ; V_2 >= V_12 ; V_2 -- )
V_15 [ V_2 ] = V_14 [ V_2 ] ;
#ifdef undef
memmove ( ( char * ) & ( V_11 -> V_4 [ V_12 + 1 ] ) ,
( char * ) & ( V_11 -> V_4 [ V_12 ] ) ,
sizeof( char * ) * ( V_11 -> V_9 - V_12 ) ) ;
#endif
V_11 -> V_4 [ V_12 ] = V_4 ;
}
V_11 -> V_9 ++ ;
V_11 -> V_10 = 0 ;
return ( V_11 -> V_9 ) ;
}
char * F_7 ( T_1 * V_11 , char * V_16 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_11 -> V_9 ; V_2 ++ )
if ( V_11 -> V_4 [ V_2 ] == V_16 )
return ( F_8 ( V_11 , V_2 ) ) ;
return ( NULL ) ;
}
char * F_8 ( T_1 * V_11 , int V_12 )
{
char * V_1 ;
int V_2 , V_17 ;
if ( ( V_11 == NULL ) || ( V_11 -> V_9 == 0 ) || ( V_12 < 0 )
|| ( V_12 >= V_11 -> V_9 ) ) return ( NULL ) ;
V_1 = V_11 -> V_4 [ V_12 ] ;
if ( V_12 != V_11 -> V_9 - 1 )
{
V_17 = V_11 -> V_9 - 1 ;
for ( V_2 = V_12 ; V_2 < V_17 ; V_2 ++ )
V_11 -> V_4 [ V_2 ] = V_11 -> V_4 [ V_2 + 1 ] ;
}
V_11 -> V_9 -- ;
return ( V_1 ) ;
}
int F_9 ( T_1 * V_11 , char * V_4 )
{
char * * V_18 ;
int V_2 ;
int (* F_10)( const void * , const void * );
if( V_11 == NULL ) return - 1 ;
if ( V_11 -> V_7 == NULL )
{
for ( V_2 = 0 ; V_2 < V_11 -> V_9 ; V_2 ++ )
if ( V_11 -> V_4 [ V_2 ] == V_4 )
return ( V_2 ) ;
return ( - 1 ) ;
}
F_11 ( V_11 ) ;
if ( V_4 == NULL ) return ( - 1 ) ;
F_10 = ( int ( * ) ( const void * , const void * ) ) ( V_11 -> V_7 ) ;
V_18 = ( char * * ) bsearch ( & V_4 , ( char * ) V_11 -> V_4 ,
V_11 -> V_9 , sizeof( char * ) , F_10 ) ;
if ( V_18 == NULL ) return ( - 1 ) ;
V_2 = ( int ) ( V_18 - V_11 -> V_4 ) ;
for ( ; V_2 > 0 ; V_2 -- )
if ( (* V_11 -> V_7 )( ( const char * const * ) & ( V_11 -> V_4 [ V_2 - 1 ] ) ,
( const char * const * ) & V_4 ) < 0 )
break;
return ( V_2 ) ;
}
int F_12 ( T_1 * V_11 , char * V_4 )
{
return ( F_5 ( V_11 , V_4 , V_11 -> V_9 ) ) ;
}
int F_13 ( T_1 * V_11 , char * V_4 )
{
return ( F_5 ( V_11 , V_4 , 0 ) ) ;
}
char * F_14 ( T_1 * V_11 )
{
if ( V_11 == NULL ) return ( NULL ) ;
if ( V_11 -> V_9 <= 0 ) return ( NULL ) ;
return ( F_8 ( V_11 , 0 ) ) ;
}
char * F_15 ( T_1 * V_11 )
{
if ( V_11 == NULL ) return ( NULL ) ;
if ( V_11 -> V_9 <= 0 ) return ( NULL ) ;
return ( F_8 ( V_11 , V_11 -> V_9 - 1 ) ) ;
}
void F_16 ( T_1 * V_11 )
{
if ( V_11 == NULL ) return;
if ( V_11 -> V_9 <= 0 ) return;
memset ( ( char * ) V_11 -> V_4 , 0 , sizeof( V_11 -> V_4 ) * V_11 -> V_9 ) ;
V_11 -> V_9 = 0 ;
}
void F_17 ( T_1 * V_11 , void (* F_18)( void * ) )
{
int V_2 ;
if ( V_11 == NULL ) return;
for ( V_2 = 0 ; V_2 < V_11 -> V_9 ; V_2 ++ )
if ( V_11 -> V_4 [ V_2 ] != NULL )
F_18 ( V_11 -> V_4 [ V_2 ] ) ;
F_19 ( V_11 ) ;
}
void F_19 ( T_1 * V_11 )
{
if ( V_11 == NULL ) return;
if ( V_11 -> V_4 != NULL ) F_4 ( V_11 -> V_4 ) ;
F_4 ( V_11 ) ;
}
int F_20 ( const T_1 * V_11 )
{
if( V_11 == NULL ) return - 1 ;
return V_11 -> V_9 ;
}
char * F_21 ( const T_1 * V_11 , int V_2 )
{
if( V_11 == NULL ) return NULL ;
return V_11 -> V_4 [ V_2 ] ;
}
char * F_22 ( T_1 * V_11 , int V_2 , char * V_19 )
{
if( V_11 == NULL ) return NULL ;
return ( V_11 -> V_4 [ V_2 ] = V_19 ) ;
}
void F_11 ( T_1 * V_11 )
{
if ( ! V_11 -> V_10 )
{
int (* F_10)( const void * , const void * );
F_10 = ( int ( * ) ( const void * , const void * ) ) ( V_11 -> V_7 ) ;
qsort ( V_11 -> V_4 , V_11 -> V_9 , sizeof( char * ) , F_10 ) ;
V_11 -> V_10 = 1 ;
}
}
