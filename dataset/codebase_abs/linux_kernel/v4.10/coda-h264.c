int F_1 ( int V_1 , char * V_2 )
{
int V_3 ;
int V_4 ;
V_4 = V_1 - ( V_1 & ~ 0x7 ) ;
if ( V_4 == 0 )
return 0 ;
V_3 = V_5 [ V_4 ] ;
memcpy ( V_2 , V_6 , V_3 ) ;
* ( V_2 + V_3 - 1 ) = 0x80 ;
return V_3 ;
}
