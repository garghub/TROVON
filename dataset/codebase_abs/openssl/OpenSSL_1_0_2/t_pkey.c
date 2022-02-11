int F_1 ( T_1 * V_1 , const char * V_2 , const T_2 * V_3 ,
unsigned char * V_4 , int V_5 )
{
int V_6 , V_7 ;
const char * V_8 ;
if ( V_3 == NULL )
return ( 1 ) ;
V_8 = ( F_2 ( V_3 ) ) ? L_1 : L_2 ;
if ( ! F_3 ( V_1 , V_5 , 128 ) )
return 0 ;
if ( F_4 ( V_3 ) ) {
if ( F_5 ( V_1 , L_3 , V_2 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_6 ( V_3 ) <= V_9 ) {
if ( F_5 ( V_1 , L_4 , V_2 , V_8 ,
( unsigned long ) V_3 -> V_10 [ 0 ] , V_8 ,
( unsigned long ) V_3 -> V_10 [ 0 ] )
<= 0 )
return ( 0 ) ;
} else {
V_4 [ 0 ] = 0 ;
if ( F_5 ( V_1 , L_5 , V_2 ,
( V_8 [ 0 ] == '-' ) ? L_6 : L_2 ) <= 0 )
return ( 0 ) ;
V_6 = F_7 ( V_3 , & V_4 [ 1 ] ) ;
if ( V_4 [ 1 ] & 0x80 )
V_6 ++ ;
else
V_4 ++ ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
if ( ( V_7 % 15 ) == 0 ) {
if ( F_8 ( V_1 , L_7 ) <= 0 || ! F_3 ( V_1 , V_5 + 4 , 128 ) )
return 0 ;
}
if ( F_5 ( V_1 , L_8 , V_4 [ V_7 ] , ( ( V_7 + 1 ) == V_6 ) ? L_2 : L_9 )
<= 0 )
return ( 0 ) ;
}
if ( F_9 ( V_1 , L_7 , 1 ) <= 0 )
return ( 0 ) ;
}
return ( 1 ) ;
}
