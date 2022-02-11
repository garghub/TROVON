struct V_1 * F_1 ( void )
{
return & ( V_2 . V_3 ) ;
}
int F_2 ( void * V_4 ,
T_1 V_5 ,
T_2 V_6 ,
T_2 V_7 ,
T_3 V_8 )
{
if ( V_2 . V_3 . V_5 )
return 0 ;
memset ( & ( V_2 . V_3 ) , 0x0 , sizeof( V_2 . V_3 ) ) ;
V_2 . V_3 . V_4 = V_4 ;
V_2 . V_3 . V_5 = V_5 ;
V_2 . V_3 . V_6 = V_6 ;
V_2 . V_3 . V_7 = V_7 ;
V_2 . V_3 . V_8 = V_8 ;
return 1 ;
}
