const char * F_1 ( void )
{
return ( L_1 ) ;
}
void F_2 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 * V_3 )
{
unsigned long V_4 , V_5 , V_6 [ 2 ] ;
F_3 ( V_1 , V_4 ) ;
V_6 [ 0 ] = V_4 ;
F_3 ( V_1 , V_5 ) ;
V_6 [ 1 ] = V_5 ;
F_4 ( V_6 , V_3 ) ;
V_4 = V_6 [ 0 ] ;
F_5 ( V_4 , V_2 ) ;
V_5 = V_6 [ 1 ] ;
F_5 ( V_5 , V_2 ) ;
V_4 = V_5 = V_6 [ 0 ] = V_6 [ 1 ] = 0 ;
}
