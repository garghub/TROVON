int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
void T_1 * V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
unsigned long V_6 ;
V_3 = ( V_1 & V_7 ) ? V_8 : V_9 ;
V_6 = 3 << F_2 ( V_1 ) ;
F_3 ( V_5 ) ;
V_4 = F_4 ( V_3 ) ;
V_4 &= ~ V_6 ;
V_4 |= V_2 & V_6 ;
F_5 ( V_4 , V_3 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
