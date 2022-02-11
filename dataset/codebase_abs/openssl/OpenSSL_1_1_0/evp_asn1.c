int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 * V_4 ;
if ( ( V_4 = F_2 () ) == NULL )
return ( 0 ) ;
if ( ! F_3 ( V_4 , V_2 , V_3 ) ) {
F_4 ( V_4 ) ;
return 0 ;
}
F_5 ( V_1 , V_5 , V_4 ) ;
return ( 1 ) ;
}
int F_6 ( const T_1 * V_1 , unsigned char * V_2 , int V_6 )
{
int V_7 , V_8 ;
const unsigned char * V_9 ;
if ( ( V_1 -> type != V_5 ) || ( V_1 -> V_10 . V_11 == NULL ) ) {
F_7 ( V_12 , V_13 ) ;
return ( - 1 ) ;
}
V_9 = F_8 ( V_1 -> V_10 . V_11 ) ;
V_7 = F_9 ( V_1 -> V_10 . V_11 ) ;
if ( V_7 < V_6 )
V_8 = V_7 ;
else
V_8 = V_6 ;
memcpy ( V_2 , V_9 , V_8 ) ;
return ( V_7 ) ;
}
