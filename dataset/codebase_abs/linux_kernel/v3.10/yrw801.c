int F_1 ( struct V_1 * V_2 )
{
char V_3 [ 15 ] ;
F_2 ( V_2 , V_3 , 0x001200 , 15 ) ;
if ( memcmp ( V_3 , L_1 , 15 ) )
return - V_4 ;
F_2 ( V_2 , V_3 , 0x1ffffe , 2 ) ;
if ( V_3 [ 0 ] != 0x01 )
return - V_4 ;
F_3 ( L_2 , V_3 [ 0 ] , V_3 [ 1 ] ) ;
return 0 ;
}
