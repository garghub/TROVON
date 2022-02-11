enum V_1 F_1 ( T_1 * V_2 )
{
T_2 V_3 ;
T_3 V_4 , V_5 , V_6 ;
unsigned long V_7 ;
T_4 V_8 ;
V_7 = sizeof( V_4 ) ;
V_8 = F_2 ( V_9 , & V_10 ,
NULL , & V_7 , & V_4 ) ;
if ( V_8 == V_11 )
return V_12 ;
if ( V_8 != V_13 )
goto V_14;
V_7 = sizeof( V_5 ) ;
V_8 = F_2 ( V_15 , & V_10 ,
NULL , & V_7 , & V_5 ) ;
if ( V_8 != V_13 )
goto V_14;
if ( V_4 == 0 || V_5 == 1 )
return V_12 ;
V_7 = sizeof( V_6 ) ;
V_8 = F_2 ( V_16 , & V_17 ,
& V_3 , & V_7 , & V_6 ) ;
if ( V_8 != V_13 )
goto V_18;
if ( ! ( V_3 & V_19 ) && V_6 == 1 )
return V_12 ;
V_18:
F_3 ( V_2 , L_1 ) ;
return V_20 ;
V_14:
F_4 ( V_2 , L_2 ) ;
return V_21 ;
}
