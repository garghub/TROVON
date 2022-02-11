static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
V_6 = F_2 ( V_8 , V_9 , & V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_4 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
return F_3 ( V_8 , V_9 , V_7 ) ;
}
void T_2 F_4 ( void )
{
V_11 [ 0 ] = & V_12 ;
F_5 ( V_11 , V_13 ) ;
}
void T_2 F_4 ( void )
{
}
