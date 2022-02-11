int F_1 ( T_1 V_1 , const T_1 V_2 , const T_1 V_3 )
{
T_1 V_4 = NULL , V_5 = NULL ;
if ( F_2 ( & V_4 , V_2 ) < 0 )
goto V_6;
if ( F_2 ( & V_5 , V_3 ) < 0 )
goto V_6;
V_4 -> V_7 = 0 ;
V_5 -> V_7 = 0 ;
while ( F_3 ( V_5 , 0 ) ) {
if ( F_4 ( V_1 , V_4 , V_5 ) < 0 )
goto V_6;
if ( F_5 ( V_4 , V_5 ) < 0 )
goto V_6;
if ( F_5 ( V_5 , V_1 ) < 0 )
goto V_6;
}
if ( F_5 ( V_1 , V_4 ) < 0 )
goto V_6;
F_6 ( V_4 ) ;
F_6 ( V_5 ) ;
return ! F_3 ( V_1 , 1 ) ;
V_6:
F_6 ( V_4 ) ;
F_6 ( V_5 ) ;
return - V_8 ;
}
