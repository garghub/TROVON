static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 V_6 [ 2 ] ;
unsigned int V_7 = 1 ;
int V_8 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 )
return - V_9 ;
V_8 = F_3 ( V_2 , 0 , & V_6 [ 0 ] ) ;
F_4 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_6 [ 0 ] . V_10 != F_5 ( 0 ) )
return - V_11 ;
V_2 = F_2 ( NULL , NULL , L_2 ) ;
if ( ! V_2 )
V_2 = F_2 ( NULL , NULL , L_3 ) ;
if ( V_2 ) {
F_4 ( V_2 ) ;
V_6 [ 1 ] . V_10 = 8 ;
V_6 [ 1 ] . V_12 = 8 ;
V_6 [ 1 ] . V_13 = V_14 ;
V_7 ++ ;
}
V_4 = F_6 ( L_4 , - 1 ,
& V_6 [ 0 ] , V_7 ) ;
return F_7 ( V_4 ) ;
}
