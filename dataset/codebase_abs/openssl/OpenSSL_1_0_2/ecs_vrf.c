int F_1 ( const unsigned char * V_1 , int V_2 ,
const T_1 * V_3 , T_2 * V_4 )
{
T_3 * V_5 = F_2 ( V_4 ) ;
if ( V_5 == NULL )
return 0 ;
return V_5 -> V_6 -> V_7 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_3 ( int type , const unsigned char * V_1 , int V_2 ,
const unsigned char * V_8 , int V_9 , T_2 * V_4 )
{
T_1 * V_10 ;
const unsigned char * V_11 = V_8 ;
unsigned char * V_12 = NULL ;
int V_13 = - 1 ;
int V_14 = - 1 ;
V_10 = F_4 () ;
if ( V_10 == NULL )
return ( V_14 ) ;
if ( F_5 ( & V_10 , & V_11 , V_9 ) == NULL )
goto V_15;
V_13 = F_6 ( V_10 , & V_12 ) ;
if ( V_13 != V_9 || memcmp ( V_8 , V_12 , V_13 ) )
goto V_15;
V_14 = F_1 ( V_1 , V_2 , V_10 , V_4 ) ;
V_15:
if ( V_13 > 0 ) {
F_7 ( V_12 , V_13 ) ;
F_8 ( V_12 ) ;
}
F_9 ( V_10 ) ;
return ( V_14 ) ;
}
