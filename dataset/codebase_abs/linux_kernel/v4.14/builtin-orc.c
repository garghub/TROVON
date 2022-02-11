int F_1 ( int V_1 , const char * * V_2 )
{
const char * V_3 ;
V_1 -- ; V_2 ++ ;
if ( ! strncmp ( V_2 [ 0 ] , L_1 , 3 ) ) {
V_1 = F_2 ( V_1 , V_2 , V_4 , V_5 , 0 ) ;
if ( V_1 != 1 )
F_3 ( V_5 , V_4 ) ;
V_3 = V_2 [ 0 ] ;
return F_4 ( V_3 , V_6 , V_7 , true ) ;
}
if ( ! strcmp ( V_2 [ 0 ] , L_2 ) ) {
if ( V_1 != 2 )
F_3 ( V_5 , V_4 ) ;
V_3 = V_2 [ 1 ] ;
return F_5 ( V_3 ) ;
}
F_3 ( V_5 , V_4 ) ;
return 0 ;
}
