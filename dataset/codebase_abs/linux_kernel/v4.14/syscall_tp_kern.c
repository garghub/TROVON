static T_1 void F_1 ( void * V_1 )
{
T_2 V_2 = 0 ;
T_2 * V_3 , V_4 = 1 ;
V_3 = F_2 ( V_1 , & V_2 ) ;
if ( V_3 )
* V_3 += 1 ;
else
F_3 ( V_1 , & V_2 , & V_4 , V_5 ) ;
}
int F_4 ( struct V_6 * V_7 )
{
F_1 ( ( void * ) & V_8 ) ;
return 0 ;
}
int F_5 ( struct V_9 * V_7 )
{
F_1 ( ( void * ) & V_10 ) ;
return 0 ;
}
