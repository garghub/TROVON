int F_1 ( T_1 * V_1 , int type , const void * V_2 , int V_3 )
{
int V_4 ;
#ifndef F_2
if ( ( F_3 ( V_1 ) && ! F_4 ( V_1 ) ) ||
( F_5 ( F_6 ( V_1 ) ) &&
F_7 ( V_1 ) ) )
#else
if ( F_3 ( V_1 ) && ! F_4 ( V_1 ) )
#endif
{
V_4 = V_1 -> V_5 ( V_1 ) ;
if ( V_4 < 0 )
return ( V_4 ) ;
if ( V_4 == 0 ) {
F_8 ( V_6 ,
V_7 ) ;
return - 1 ;
}
}
if ( V_3 > V_8 ) {
F_8 ( V_6 , V_9 ) ;
return - 1 ;
}
V_4 = F_9 ( V_1 , type , V_2 , V_3 ) ;
return V_4 ;
}
int F_10 ( T_1 * V_1 )
{
int V_4 , V_10 ;
void (* F_11) ( const T_1 * V_11 , int type , int V_12 ) = NULL ;
unsigned char V_13 [ V_14 ] ;
unsigned char * V_15 = & V_13 [ 0 ] ;
V_1 -> V_16 -> V_17 = 0 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
* V_15 ++ = V_1 -> V_16 -> V_18 [ 0 ] ;
* V_15 ++ = V_1 -> V_16 -> V_18 [ 1 ] ;
#ifdef F_12
if ( V_1 -> V_16 -> V_18 [ 1 ] == F_12 ) {
F_13 ( V_1 -> V_19 -> V_20 , V_15 ) ;
F_14 ( V_1 -> V_19 -> V_21 . V_22 , V_15 ) ;
}
#endif
V_4 = F_15 ( V_1 , V_23 , & V_13 [ 0 ] , sizeof( V_13 ) , 0 ) ;
if ( V_4 <= 0 ) {
V_1 -> V_16 -> V_17 = 1 ;
} else {
if ( V_1 -> V_16 -> V_18 [ 0 ] == V_24
#ifdef F_12
|| V_1 -> V_16 -> V_18 [ 1 ] == F_12
#endif
)
( void ) F_16 ( V_1 -> V_25 ) ;
if ( V_1 -> V_26 )
V_1 -> V_26 ( 1 , V_1 -> V_27 , V_23 , V_1 -> V_16 -> V_18 ,
2 , V_1 , V_1 -> V_28 ) ;
if ( V_1 -> V_29 != NULL )
F_11 = V_1 -> V_29 ;
else if ( V_1 -> V_30 -> V_29 != NULL )
F_11 = V_1 -> V_30 -> V_29 ;
if ( F_11 != NULL ) {
V_10 = ( V_1 -> V_16 -> V_18 [ 0 ] << 8 ) | V_1 -> V_16 -> V_18 [ 1 ] ;
F_11 ( V_1 , V_31 , V_10 ) ;
}
}
return ( V_4 ) ;
}
