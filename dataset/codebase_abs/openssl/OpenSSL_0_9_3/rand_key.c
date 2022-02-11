void F_1 ( T_1 * V_1 )
{
memcpy ( & V_2 , V_1 , sizeof( T_1 ) ) ;
V_3 = 1 ;
}
void F_2 ( T_1 * V_4 )
{
T_2 V_5 ;
static T_3 V_6 = 0 ;
static unsigned short V_7 = 0 ;
static T_1 V_8 = { 0x01 , 0x23 , 0x45 , 0x67 , 0x89 , 0xab , 0xcd , 0xef } ;
T_1 V_1 ;
unsigned char * V_9 ;
T_3 V_10 ;
int V_11 ;
#ifdef F_3
V_7 = 1 ;
#else
if ( ! V_7 ) V_7 = F_4 () ;
#endif
V_9 = V_1 ;
if ( V_3 )
{
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
{
V_8 [ V_11 ] ^= V_2 [ V_11 ] ;
V_2 [ V_11 ] = 0 ;
}
V_3 = 0 ;
}
V_10 = ( T_3 ) time ( NULL ) ;
F_5 ( V_10 , V_9 ) ;
V_10 = ( T_3 ) ( ( V_7 ) | ( ( V_6 ++ ) << 16 ) ) ;
F_5 ( V_10 , V_9 ) ;
F_6 ( & V_8 ) ;
F_7 ( & V_8 , V_5 ) ;
F_8 ( V_1 , & V_1 , sizeof( V_1 ) , V_5 , & V_8 ) ;
F_6 ( & V_1 ) ;
F_7 ( & V_1 , V_5 ) ;
F_8 ( V_1 , & V_8 , sizeof( V_1 ) , V_5 , & V_1 ) ;
memcpy ( V_4 , V_8 , sizeof( V_1 ) ) ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_10 = 0 ;
}
