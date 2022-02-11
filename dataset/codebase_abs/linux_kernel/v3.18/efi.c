void T_1 F_1 ( void )
{
T_2 * V_1 ;
V_1 = F_2 () ;
if ( V_1 == NULL )
return;
strncpy ( ( char * ) & V_2 . V_3 . V_4 , L_1 ,
sizeof( V_2 . V_3 . V_4 ) ) ;
V_2 . V_3 . V_5 = ( V_6 ) F_3 ( V_1 ) ;
V_2 . V_3 . V_7 = ( V_6 ) ( F_3 ( V_1 ) >> 32 ) ;
F_4 ( V_8 , & V_9 . V_10 ) ;
F_4 ( V_11 , & V_9 . V_10 ) ;
F_4 ( V_12 , & V_9 . V_10 ) ;
}
