T_1 F_1 ( T_2 V_1 )
{
long V_2 ;
long V_3 ;
T_3 V_4 ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 < 0 ) {
goto V_5;
}
V_4 = F_3 ( V_1 , 0 , V_6 ) ;
if ( F_4 ( V_4 ) ) {
goto V_7;
}
V_2 = F_2 ( V_1 ) ;
if ( V_2 < 0 ) {
goto V_5;
}
V_4 = F_3 ( V_1 , V_3 , V_8 ) ;
if ( F_4 ( V_4 ) ) {
goto V_7;
}
return ( ( T_1 ) V_2 ) ;
V_5:
F_5 ( L_1 ) ;
return ( V_9 ) ;
V_7:
F_5 ( L_2 ) ;
return ( V_9 ) ;
}
