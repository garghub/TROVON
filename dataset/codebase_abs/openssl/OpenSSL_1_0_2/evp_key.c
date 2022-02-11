void F_1 ( const char * V_1 )
{
if ( V_1 == NULL )
V_2 [ 0 ] = '\0' ;
else {
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
return F_4 ( V_3 , 0 , V_4 , V_1 , V_5 ) ;
}
int F_4 ( char * V_3 , int V_6 , int V_4 , const char * V_1 ,
int V_5 )
{
int V_7 ;
char V_8 [ V_9 ] ;
T_1 * V_10 ;
if ( ( V_1 == NULL ) && ( V_2 [ 0 ] != '\0' ) )
V_1 = V_2 ;
V_10 = F_5 () ;
F_6 ( V_10 , V_1 , 0 , V_3 , V_6 ,
( V_4 >= V_9 ) ? V_9 - 1 : V_4 ) ;
if ( V_5 )
F_7 ( V_10 , V_1 , 0 ,
V_8 , V_6 , ( V_4 >= V_9 ) ? V_9 - 1 : V_4 ,
V_3 ) ;
V_7 = F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
F_10 ( V_8 , V_9 ) ;
return V_7 ;
}
int F_11 ( const T_2 * type , const T_3 * V_11 ,
const unsigned char * V_12 , const unsigned char * V_13 ,
int V_14 , int V_15 , unsigned char * V_16 ,
unsigned char * V_17 )
{
T_4 V_18 ;
unsigned char V_19 [ V_20 ] ;
int V_21 , V_22 , V_23 = 0 ;
unsigned int V_24 = 0 , V_25 ;
int V_26 = 0 ;
V_22 = type -> V_27 ;
V_21 = type -> V_28 ;
F_12 ( V_22 <= V_29 ) ;
F_12 ( V_21 <= V_30 ) ;
if ( V_13 == NULL )
return ( V_22 ) ;
F_13 ( & V_18 ) ;
for (; ; ) {
if ( ! F_14 ( & V_18 , V_11 , NULL ) )
return 0 ;
if ( V_23 ++ )
if ( ! F_15 ( & V_18 , & ( V_19 [ 0 ] ) , V_24 ) )
goto V_31;
if ( ! F_15 ( & V_18 , V_13 , V_14 ) )
goto V_31;
if ( V_12 != NULL )
if ( ! F_15 ( & V_18 , V_12 , V_32 ) )
goto V_31;
if ( ! F_16 ( & V_18 , & ( V_19 [ 0 ] ) , & V_24 ) )
goto V_31;
for ( V_25 = 1 ; V_25 < ( unsigned int ) V_15 ; V_25 ++ ) {
if ( ! F_14 ( & V_18 , V_11 , NULL ) )
goto V_31;
if ( ! F_15 ( & V_18 , & ( V_19 [ 0 ] ) , V_24 ) )
goto V_31;
if ( ! F_16 ( & V_18 , & ( V_19 [ 0 ] ) , & V_24 ) )
goto V_31;
}
V_25 = 0 ;
if ( V_22 ) {
for (; ; ) {
if ( V_22 == 0 )
break;
if ( V_25 == V_24 )
break;
if ( V_16 != NULL )
* ( V_16 ++ ) = V_19 [ V_25 ] ;
V_22 -- ;
V_25 ++ ;
}
}
if ( V_21 && ( V_25 != V_24 ) ) {
for (; ; ) {
if ( V_21 == 0 )
break;
if ( V_25 == V_24 )
break;
if ( V_17 != NULL )
* ( V_17 ++ ) = V_19 [ V_25 ] ;
V_21 -- ;
V_25 ++ ;
}
}
if ( ( V_22 == 0 ) && ( V_21 == 0 ) )
break;
}
V_26 = type -> V_27 ;
V_31:
F_17 ( & V_18 ) ;
F_10 ( & ( V_19 [ 0 ] ) , V_20 ) ;
return V_26 ;
}
