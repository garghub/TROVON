int F_1 ( void )
{
char V_1 [ 20 ] ;
T_1 V_2 ;
T_2 V_3 [ V_4 ] ;
if ( V_5 == 0 ) {
T_2 V_6 = F_2 ( V_1 , sizeof( V_1 ) , L_1 , & V_5 ) ;
if ( V_6 == 0 ) {
V_6 = F_3 ( V_5 , 976 , NULL , ( V_7 * ) & V_8 ) ;
if ( V_6 )
V_8 = NULL ;
V_6 = F_3 ( V_5 , 368 , NULL , ( V_7 * ) & V_9 ) ;
if ( V_6 )
V_9 = NULL ;
}
}
F_4 ( & V_2 ) ;
F_5 ( & V_2 , sizeof( V_2 ) , 2 ) ;
F_6 ( 1 , V_4 , V_3 , sizeof( V_3 ) ) ;
F_5 ( V_3 , sizeof( V_3 ) , 4 ) ;
if ( V_8 ) {
T_3 V_10 ;
if ( V_8 ( V_11 , ( T_2 ) & V_10 , 0 , 0 ) == 0 ) {
F_5 ( & V_10 , sizeof( V_10 ) , 10 ) ;
}
else {
V_8 = NULL ;
}
}
if ( V_9 ) {
char * V_12 = F_7 ( 256 * 1024 ) ;
if ( V_9 ( 0x1F , 0 , 0 , 0 , V_12 , 256 * 1024 ) == 0 ) {
F_5 ( V_12 , 256 * 1024 , * * ( T_2 * * ) V_12 ) ;
}
F_8 ( V_12 ) ;
return 1 ;
}
return 0 ;
}
