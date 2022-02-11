T_1 F_1 ( T_2 V_1 )
{
long V_2 ;
long V_3 ;
T_3 V_4 ;
V_3 = ftell ( V_1 ) ;
if ( V_3 < 0 ) {
goto V_5;
}
V_4 = fseek ( V_1 , 0 , V_6 ) ;
if ( F_2 ( V_4 ) ) {
goto V_7;
}
V_2 = ftell ( V_1 ) ;
if ( V_2 < 0 ) {
goto V_5;
}
V_4 = fseek ( V_1 , V_3 , V_8 ) ;
if ( F_2 ( V_4 ) ) {
goto V_7;
}
return ( ( T_1 ) V_2 ) ;
V_5:
fprintf ( V_9 , L_1 ) ;
return ( V_10 ) ;
V_7:
fprintf ( V_9 , L_2 ) ;
return ( V_10 ) ;
}
