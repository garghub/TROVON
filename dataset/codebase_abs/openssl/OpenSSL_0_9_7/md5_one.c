unsigned char * F_1 ( const unsigned char * V_1 , unsigned long V_2 , unsigned char * V_3 )
{
T_1 V_4 ;
static unsigned char V_5 [ V_6 ] ;
if ( V_3 == NULL ) V_3 = V_5 ;
F_2 ( & V_4 ) ;
#ifndef F_3
F_4 ( & V_4 , V_1 , V_2 ) ;
#else
{
char V_7 [ 1024 ] ;
unsigned long V_8 ;
while ( V_2 > 0 )
{
V_8 = ( V_2 > sizeof( V_7 ) ) ? sizeof( V_7 ) : V_2 ;
F_5 ( V_7 , V_1 , V_8 ) ;
F_4 ( & V_4 , V_7 , V_8 ) ;
V_2 -= V_8 ;
V_1 += V_8 ;
}
}
#endif
F_6 ( V_3 , & V_4 ) ;
F_7 ( & V_4 , sizeof( V_4 ) ) ;
return ( V_3 ) ;
}
