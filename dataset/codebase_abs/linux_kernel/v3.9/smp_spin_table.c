static int T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_2 , L_1 ,
& V_4 [ V_3 ] ) ) {
F_3 ( L_2 ,
V_3 ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_4 ( int V_3 )
{
void * * V_5 ;
if ( ! V_4 [ V_3 ] )
return - V_6 ;
V_5 = F_5 ( V_4 [ V_3 ] ) ;
V_5 [ 0 ] = ( void * ) F_6 ( V_7 ) ;
F_7 ( V_5 , sizeof( V_5 [ 0 ] ) ) ;
F_8 () ;
return 0 ;
}
