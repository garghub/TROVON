T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned int V_4 , unsigned char * V_5 , unsigned int V_6 )
{
if ( V_6 == 0 || V_4 < ( V_6 - 1 ) )
{
return ( - 1 ) ;
}
* ( V_3 ++ ) = 0 ;
memcpy ( V_3 , V_5 , V_6 ) ;
return ( V_6 + 1 ) ;
}
static int F_3 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned int V_4 , unsigned char * V_5 , unsigned int V_6 )
{
int V_7 ;
if ( V_4 < ( V_6 - 1 ) )
{
return ( - 1 ) ;
}
V_7 = * ( V_5 ++ ) ;
if ( V_7 == 0 )
{
memcpy ( V_3 , V_5 , V_6 - 1 ) ;
}
return ( V_6 - 1 ) ;
}
