static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
F_2 ( V_5 ) ;
V_4 = F_3 ( V_6 ) ;
F_4 ( V_7 L_1 , V_8 , V_3 ) ;
if ( V_3 )
V_4 |= V_9 ;
else
V_4 &= ~ V_9 ;
F_5 ( V_4 , V_6 ) ;
F_6 ( V_5 ) ;
}
void T_1 F_7 ( void )
{
int V_10 ;
V_10 = F_8 ( & V_11 ) ;
if ( V_10 < 0 )
F_4 ( V_12 L_2 ) ;
else
F_1 ( NULL , 1 ) ;
}
