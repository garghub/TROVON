T_1 F_1 ( T_2 * V_1 )
{
long V_2 ;
long V_3 ;
V_3 = ftell ( V_1 ) ;
if ( V_3 < 0 ) {
goto V_4;
}
if ( fseek ( V_1 , 0 , V_5 ) ) {
goto V_6;
}
V_2 = ftell ( V_1 ) ;
if ( V_2 < 0 ) {
goto V_4;
}
if ( fseek ( V_1 , V_3 , V_7 ) ) {
goto V_6;
}
return ( ( T_1 ) V_2 ) ;
V_4:
perror ( L_1 ) ;
return ( V_8 ) ;
V_6:
perror ( L_2 ) ;
return ( V_8 ) ;
}
