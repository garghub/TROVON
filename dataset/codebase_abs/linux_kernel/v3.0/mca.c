int F_1 ( void )
{
struct V_1 V_2 , V_3 ;
T_1 V_4 ;
F_2 ( & V_2 ) ;
V_2 . V_5 = 0xc0 ;
F_3 ( 0x15 , & V_2 , & V_3 ) ;
if ( V_3 . V_6 & V_7 )
return - 1 ;
F_4 ( V_3 . V_8 ) ;
V_4 = F_5 ( V_3 . V_9 ) ;
if ( V_4 > sizeof( V_10 . V_11 ) )
V_4 = sizeof( V_10 . V_11 ) ;
F_6 ( & V_10 . V_11 , V_3 . V_9 , V_4 ) ;
return 0 ;
}
