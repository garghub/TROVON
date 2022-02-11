void
F_1 ( T_1 * T_2 V_1 )
{
T_3 V_2 [ 4 ] ;
char V_3 [ 0x40 ] ;
unsigned V_4 ;
if ( ! F_2 ( V_2 , 0x80000000 ) )
return;
V_4 = V_2 [ 0 ] ;
if( V_4 < 0x80000005 )
return;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
F_2 ( V_2 , 0x80000002 ) ;
memcpy ( V_3 , V_2 , sizeof( V_2 ) ) ;
F_2 ( V_2 , 0x80000003 ) ;
memcpy ( V_3 + 16 , V_2 , sizeof( V_2 ) ) ;
F_2 ( V_2 , 0x80000004 ) ;
memcpy ( V_3 + 32 , V_2 , sizeof( V_2 ) ) ;
F_3 ( T_2 , L_1 , V_3 ) ;
if ( F_4 () )
F_5 ( T_2 , L_2 ) ;
}
