int F_1 ( const unsigned char * V_1 , int V_2 , T_1 * V_3 ,
T_2 * V_4 )
{
return V_4 -> V_5 -> V_6 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_2 ( int type , const unsigned char * V_1 , int V_2 ,
unsigned char * V_7 , int V_8 , T_2 * V_4 )
{
T_1 * V_9 ;
int V_10 = - 1 ;
V_9 = F_3 () ;
if ( V_9 == NULL ) return ( V_10 ) ;
if ( F_4 ( & V_9 , & V_7 , V_8 ) == NULL ) goto V_11;
V_10 = F_1 ( V_1 , V_2 , V_9 , V_4 ) ;
V_11:
F_5 ( V_9 ) ;
return ( V_10 ) ;
}
