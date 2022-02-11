unsigned char * F_1 ( unsigned char * V_1 , unsigned long V_2 , unsigned char * V_3 )
{
T_1 V_4 ;
static unsigned char V_5 [ V_6 ] ;
if ( V_3 == NULL ) V_3 = V_5 ;
F_2 ( & V_4 ) ;
F_3 ( & V_4 , V_1 , V_2 ) ;
F_4 ( V_3 , & V_4 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
return ( V_3 ) ;
}
