int F_1 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
T_2 V_4 ;
T_3 V_5 , V_6 ;
for ( V_4 = V_3 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_5 = V_1 [ V_4 ] ;
V_6 = V_2 [ V_4 ] ;
if ( V_5 != V_6 )
goto V_7;
}
return 0 ;
V_7:
return ( V_5 > V_6 ) ? 1 : - 1 ;
}
