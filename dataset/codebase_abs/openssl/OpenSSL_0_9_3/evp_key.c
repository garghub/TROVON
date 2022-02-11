void F_1 ( char * V_1 )
{
if ( V_1 == NULL )
V_2 [ 0 ] = '\0' ;
else
strncpy ( V_2 , V_1 , 79 ) ;
}
char * F_2 ( void )
{
if ( V_2 [ 0 ] == '\0' )
return ( NULL ) ;
else
return ( V_2 ) ;
}
int F_3 ( char * V_3 , int V_4 , const char * V_1 , int V_5 )
{
if ( ( V_1 == NULL ) && ( V_2 [ 0 ] != '\0' ) )
V_1 = V_2 ;
return ( F_4 ( V_3 , V_4 , V_1 , V_5 ) ) ;
}
int F_5 ( const T_1 * type , T_2 * V_6 , unsigned char * V_7 ,
unsigned char * V_8 , int V_9 , int V_10 , unsigned char * V_11 ,
unsigned char * V_12 )
{
T_3 V_13 ;
unsigned char V_14 [ V_15 ] ;
int V_16 , V_17 , V_18 = 0 ;
unsigned int V_19 = 0 , V_20 ;
V_17 = type -> V_21 ;
V_16 = type -> V_22 ;
if ( V_8 == NULL ) return ( V_17 ) ;
for (; ; )
{
F_6 ( & V_13 , V_6 ) ;
if ( V_18 ++ )
F_7 ( & V_13 , & ( V_14 [ 0 ] ) , V_19 ) ;
F_7 ( & V_13 , V_8 , V_9 ) ;
if ( V_7 != NULL )
F_7 ( & V_13 , V_7 , 8 ) ;
F_8 ( & V_13 , & ( V_14 [ 0 ] ) , & V_19 ) ;
for ( V_20 = 1 ; V_20 < ( unsigned int ) V_10 ; V_20 ++ )
{
F_6 ( & V_13 , V_6 ) ;
F_7 ( & V_13 , & ( V_14 [ 0 ] ) , V_19 ) ;
F_8 ( & V_13 , & ( V_14 [ 0 ] ) , & V_19 ) ;
}
V_20 = 0 ;
if ( V_17 )
{
for (; ; )
{
if ( V_17 == 0 ) break;
if ( V_20 == V_19 ) break;
if ( V_11 != NULL )
* ( V_11 ++ ) = V_14 [ V_20 ] ;
V_17 -- ;
V_20 ++ ;
}
}
if ( V_16 && ( V_20 != V_19 ) )
{
for (; ; )
{
if ( V_16 == 0 ) break;
if ( V_20 == V_19 ) break;
if ( V_12 != NULL )
* ( V_12 ++ ) = V_14 [ V_20 ] ;
V_16 -- ;
V_20 ++ ;
}
}
if ( ( V_17 == 0 ) && ( V_16 == 0 ) ) break;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
memset ( & ( V_14 [ 0 ] ) , 0 , V_15 ) ;
return ( type -> V_21 ) ;
}
