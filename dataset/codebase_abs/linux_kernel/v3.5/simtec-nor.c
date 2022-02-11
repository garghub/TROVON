static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_6 L_1 , V_7 , V_3 ) ;
if ( V_3 )
V_4 |= V_8 ;
else
V_4 &= ~ V_8 ;
F_4 ( V_4 , V_5 ) ;
}
void T_1 F_5 ( void )
{
int V_9 ;
V_9 = F_6 ( & V_10 ) ;
if ( V_9 < 0 )
F_3 ( V_11 L_2 ) ;
else
F_1 ( NULL , 1 ) ;
}
