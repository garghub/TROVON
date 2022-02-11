int F_1 ( T_1 * V_1 , T_2 * type , unsigned char * * V_2 ,
int * V_3 , unsigned char * V_4 , T_3 * * V_5 , int V_6 )
{
unsigned char V_7 [ V_8 ] ;
int V_9 ;
if ( V_6 <= 0 ) return ( 0 ) ;
if ( F_2 ( V_7 , V_8 ) <= 0 )
return ( 0 ) ;
if ( type -> V_10 > 0 )
F_3 ( V_4 , type -> V_10 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 , type , V_7 , V_4 ) ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ )
{
V_3 [ V_9 ] = F_6 ( V_2 [ V_9 ] , V_7 , F_7 ( type ) ,
V_5 [ V_9 ] ) ;
if ( V_3 [ V_9 ] <= 0 ) return ( - 1 ) ;
}
return ( V_6 ) ;
}
void F_8 ( T_1 * V_1 , unsigned char * V_11 , int * V_12 )
{
F_9 ( V_1 , V_11 , V_12 ) ;
F_5 ( V_1 , NULL , NULL , NULL ) ;
}
