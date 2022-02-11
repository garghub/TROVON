const char * F_1 ( void )
{
if ( sizeof( short ) != sizeof( V_1 ) )
return ( L_1 ) ;
else
return ( L_2 ) ;
}
void F_2 ( unsigned char * V_2 , unsigned char * V_3 ,
T_1 * V_4 )
{
unsigned long V_5 , V_6 , V_7 [ 2 ] ;
F_3 ( V_2 , V_5 ) ; V_7 [ 0 ] = V_5 ;
F_3 ( V_2 , V_6 ) ; V_7 [ 1 ] = V_6 ;
F_4 ( V_7 , V_4 ) ;
V_5 = V_7 [ 0 ] ; F_5 ( V_5 , V_3 ) ;
V_6 = V_7 [ 1 ] ; F_5 ( V_6 , V_3 ) ;
V_5 = V_6 = V_7 [ 0 ] = V_7 [ 1 ] = 0 ;
}
