static void F_1 ( int V_1 )
{
F_2 ( V_2 , V_1 ) ;
}
void F_3 ( void )
{
T_1 V_3 ;
struct V_4 V_5 , V_6 ;
if ( V_7 [ 0 ] )
return;
V_7 [ 0 ] = 1UL << ( 8 * sizeof( unsigned long ) - 1 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_8 = F_1 ;
F_4 ( & V_5 . V_9 ) ;
F_5 ( & V_5 . V_9 , V_10 ) ;
F_5 ( & V_5 . V_9 , V_11 ) ;
F_6 ( V_12 , & V_5 . V_9 , & V_3 ) ;
V_4 ( V_10 , & V_5 , & V_6 ) ;
if ( F_7 ( V_2 , 1 ) == 0 )
F_8 () ;
V_4 ( V_10 , & V_6 , NULL ) ;
F_6 ( V_12 , & V_3 , NULL ) ;
}
