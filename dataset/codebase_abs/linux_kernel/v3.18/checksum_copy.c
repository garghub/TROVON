unsigned int F_1 ( const char * V_1 , char * V_2 ,
int V_3 , unsigned int V_4 )
{
V_4 = F_2 ( V_1 , V_3 , V_4 ) ;
memcpy ( V_2 , V_1 , V_3 ) ;
return V_4 ;
}
unsigned int F_3 ( const char * V_1 , char * V_2 ,
int V_3 , unsigned int V_4 ,
int * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_1 , V_3 ) ;
if ( V_6 ) {
memset ( V_2 + V_3 - V_6 , 0 , V_6 ) ;
* V_5 = - V_7 ;
}
return F_2 ( V_2 , V_3 , V_4 ) ;
}
