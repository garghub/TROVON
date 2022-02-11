int F_1 ( char * V_1 , int V_2 , const char * V_3 ,
int V_4 )
{
char V_5 [ V_6 ] ;
int V_7 ;
V_7 =
F_2 ( V_1 , V_5 , ( V_2 > V_6 ) ? V_6 : V_2 ,
V_3 , V_4 ) ;
F_3 ( V_5 , V_6 ) ;
return ( V_7 ) ;
}
int F_2 ( char * V_1 , char * V_5 , int V_8 , const char * V_3 ,
int V_4 )
{
int V_9 = 0 ;
T_1 * V_10 ;
if ( V_8 < 1 )
return - 1 ;
V_10 = F_4 () ;
if ( V_10 != NULL ) {
V_9 = F_5 ( V_10 , V_3 , 0 , V_1 , 0 , V_8 - 1 ) ;
if ( V_9 >= 0 && V_4 )
V_9 = F_6 ( V_10 , V_3 , 0 , V_5 , 0 , V_8 - 1 , V_1 ) ;
if ( V_9 >= 0 )
V_9 = F_7 ( V_10 ) ;
F_8 ( V_10 ) ;
}
if ( V_9 > 0 )
V_9 = 0 ;
return ( V_9 ) ;
}
