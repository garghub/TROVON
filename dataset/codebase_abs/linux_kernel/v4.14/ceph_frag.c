int F_1 ( T_1 V_1 , T_1 V_2 )
{
unsigned V_3 = F_2 ( V_1 ) ;
unsigned V_4 = F_2 ( V_2 ) ;
if ( V_3 < V_4 )
return - 1 ;
if ( V_3 > V_4 )
return 1 ;
V_3 = F_3 ( V_1 ) ;
V_4 = F_3 ( V_2 ) ;
if ( V_3 < V_4 )
return - 1 ;
if ( V_3 > V_4 )
return 1 ;
return 0 ;
}
