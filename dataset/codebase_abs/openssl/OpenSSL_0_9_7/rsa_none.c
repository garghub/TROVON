int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 )
{
if ( V_4 > V_2 )
{
F_2 ( V_5 , V_6 ) ;
return ( 0 ) ;
}
if ( V_4 < V_2 )
{
F_2 ( V_5 , V_7 ) ;
return ( 0 ) ;
}
memcpy ( V_1 , V_3 , ( unsigned int ) V_4 ) ;
return ( 1 ) ;
}
int F_3 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_8 )
{
if ( V_4 > V_2 )
{
F_2 ( V_9 , V_10 ) ;
return ( - 1 ) ;
}
memset ( V_1 , 0 , V_2 - V_4 ) ;
memcpy ( V_1 + V_2 - V_4 , V_3 , V_4 ) ;
return ( V_2 ) ;
}
