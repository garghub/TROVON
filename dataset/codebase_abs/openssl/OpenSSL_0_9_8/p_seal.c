int F_1 ( T_1 * V_1 , const T_2 * type , unsigned char * * V_2 ,
int * V_3 , unsigned char * V_4 , T_3 * * V_5 , int V_6 )
{
unsigned char V_7 [ V_8 ] ;
int V_9 ;
if( type ) {
F_2 ( V_1 ) ;
if( ! F_3 ( V_1 , type , NULL , NULL , NULL ) ) return 0 ;
}
if ( ( V_6 <= 0 ) || ! V_5 )
return 1 ;
if ( F_4 ( V_1 , V_7 ) <= 0 )
return 0 ;
if ( F_5 ( V_1 ) )
F_6 ( V_4 , F_5 ( V_1 ) ) ;
if( ! F_3 ( V_1 , NULL , NULL , V_7 , V_4 ) ) return 0 ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ )
{
V_3 [ V_9 ] = F_7 ( V_2 [ V_9 ] , V_7 , F_8 ( V_1 ) ,
V_5 [ V_9 ] ) ;
if ( V_3 [ V_9 ] <= 0 ) return ( - 1 ) ;
}
return ( V_6 ) ;
}
int F_9 ( T_1 * V_1 , unsigned char * V_10 , int * V_11 )
{
int V_9 ;
V_9 = F_10 ( V_1 , V_10 , V_11 ) ;
F_3 ( V_1 , NULL , NULL , NULL , NULL ) ;
return V_9 ;
}
