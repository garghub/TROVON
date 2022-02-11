static bool T_1 F_1 ( void )
{
T_2 V_1 ;
T_2 V_2 [ 3 ] ;
if ( ! F_2 ( V_3 ) )
return false ;
F_3 ( V_4 ,
& V_1 , & V_2 [ 0 ] , & V_2 [ 1 ] , & V_2 [ 2 ] ) ;
return V_1 >= V_5 &&
V_1 <= V_6 &&
! memcmp ( L_1 , V_2 , 12 ) ;
}
static void T_1 F_4 ( void )
{
V_7 . V_8 = F_5 ( V_9 ) ;
V_7 . V_10 = F_5 ( V_11 ) ;
F_6 ( V_12 L_2 ,
V_7 . V_8 , V_7 . V_10 ) ;
}
