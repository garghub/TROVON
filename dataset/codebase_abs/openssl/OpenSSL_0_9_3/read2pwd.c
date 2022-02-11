int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 )
{
int V_4 ;
char V_5 [ V_6 ] , V_7 [ V_6 ] ;
if ( ( V_4 = F_2 ( V_5 , V_7 , V_6 , V_2 , V_3 ) ) == 0 )
F_3 ( V_5 , V_1 ) ;
memset ( V_5 , 0 , V_6 ) ;
memset ( V_7 , 0 , V_6 ) ;
return ( V_4 ) ;
}
int F_4 ( T_1 * V_8 , T_1 * V_9 , const char * V_2 ,
int V_3 )
{
int V_4 ;
char V_5 [ V_6 ] , V_7 [ V_6 ] ;
if ( ( V_4 = F_2 ( V_5 , V_7 , V_6 , V_2 , V_3 ) ) == 0 )
F_5 ( V_5 , V_8 , V_9 ) ;
memset ( V_5 , 0 , V_6 ) ;
memset ( V_7 , 0 , V_6 ) ;
return ( V_4 ) ;
}
