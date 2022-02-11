int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 () ;
T_2 V_4 , * V_5 ;
T_3 error ;
V_4 = F_3 ( & V_6 , V_3 ) ;
error = ( T_3 ) V_4 ;
if ( error <= - 2 && error >= - 22 )
return 0 ;
V_5 = F_4 ( & V_7 , & V_3 ) ;
if ( V_5 )
* V_5 = V_4 ;
else
F_5 ( & V_7 , & V_3 , & V_4 , V_8 ) ;
return 0 ;
}
