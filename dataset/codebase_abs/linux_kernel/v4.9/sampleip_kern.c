int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 * V_4 , V_5 = 1 ;
V_3 = F_2 ( & V_2 -> V_6 ) ;
V_4 = F_3 ( & V_7 , & V_3 ) ;
if ( V_4 )
* V_4 += 1 ;
else
F_4 ( & V_7 , & V_3 , & V_5 , V_8 ) ;
return 0 ;
}
