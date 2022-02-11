static int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
int V_4 ;
T_3 * V_5 ;
V_4 = F_2 ( V_2 , V_3 , - 1 ) ;
if ( V_4 < 0 )
return 1 ;
V_5 = F_3 ( V_2 , V_4 ) ;
if ( ! F_4 ( & V_1 -> V_6 , V_5 ) )
return 0 ;
return 1 ;
}
