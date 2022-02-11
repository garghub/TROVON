void F_1 ( const char * V_1 )
{
if ( V_1 == NULL )
V_2 [ 0 ] = '\0' ;
else
{
strncpy ( V_2 , V_1 , 79 ) ;
V_2 [ 79 ] = '\0' ;
}
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
int V_6 ;
char V_7 [ V_8 ] ;
T_1 * V_9 ;
if ( ( V_1 == NULL ) && ( V_2 [ 0 ] != '\0' ) )
V_1 = V_2 ;
V_9 = F_4 () ;
F_5 ( V_9 , V_1 , 0 , V_3 , 0 , ( V_4 >= V_8 ) ? V_8 - 1 : V_4 ) ;
if ( V_5 )
F_6 ( V_9 , V_1 , 0 ,
V_7 , 0 , ( V_4 >= V_8 ) ? V_8 - 1 : V_4 , V_3 ) ;
V_6 = F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_7 , V_8 ) ;
return V_6 ;
}
int F_10 ( const T_2 * type , const T_3 * V_10 ,
const unsigned char * V_11 , const unsigned char * V_12 , int V_13 ,
int V_14 , unsigned char * V_15 , unsigned char * V_16 )
{
T_4 V_17 ;
unsigned char V_18 [ V_19 ] ;
int V_20 , V_21 , V_22 = 0 ;
unsigned int V_23 = 0 , V_24 ;
V_21 = type -> V_25 ;
V_20 = type -> V_26 ;
F_11 ( V_21 <= V_27 ) ;
F_11 ( V_20 <= V_28 ) ;
if ( V_12 == NULL ) return ( V_21 ) ;
F_12 ( & V_17 ) ;
for (; ; )
{
F_13 ( & V_17 , V_10 , NULL ) ;
if ( V_22 ++ )
F_14 ( & V_17 , & ( V_18 [ 0 ] ) , V_23 ) ;
F_14 ( & V_17 , V_12 , V_13 ) ;
if ( V_11 != NULL )
F_14 ( & V_17 , V_11 , V_29 ) ;
F_15 ( & V_17 , & ( V_18 [ 0 ] ) , & V_23 ) ;
for ( V_24 = 1 ; V_24 < ( unsigned int ) V_14 ; V_24 ++ )
{
F_13 ( & V_17 , V_10 , NULL ) ;
F_14 ( & V_17 , & ( V_18 [ 0 ] ) , V_23 ) ;
F_15 ( & V_17 , & ( V_18 [ 0 ] ) , & V_23 ) ;
}
V_24 = 0 ;
if ( V_21 )
{
for (; ; )
{
if ( V_21 == 0 ) break;
if ( V_24 == V_23 ) break;
if ( V_15 != NULL )
* ( V_15 ++ ) = V_18 [ V_24 ] ;
V_21 -- ;
V_24 ++ ;
}
}
if ( V_20 && ( V_24 != V_23 ) )
{
for (; ; )
{
if ( V_20 == 0 ) break;
if ( V_24 == V_23 ) break;
if ( V_16 != NULL )
* ( V_16 ++ ) = V_18 [ V_24 ] ;
V_20 -- ;
V_24 ++ ;
}
}
if ( ( V_21 == 0 ) && ( V_20 == 0 ) ) break;
}
F_16 ( & V_17 ) ;
F_9 ( & ( V_18 [ 0 ] ) , V_19 ) ;
return ( type -> V_25 ) ;
}
