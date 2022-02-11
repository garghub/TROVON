int F_1 ( unsigned int V_1 )
{
int V_2 = 0 ;
unsigned int V_3 ;
F_2 ( & V_4 ) ;
if ( V_1 & V_5 ) {
V_2 = - V_6 ;
goto V_7;
}
V_5 |= V_1 ;
V_3 = F_3 ( V_8 ) ;
F_4 ( V_3 | V_1 , V_8 ) ;
F_4 ( V_3 , V_8 ) ;
V_7:
F_5 ( & V_4 ) ;
return V_2 ;
}
void F_6 ( unsigned int V_1 )
{
F_2 ( & V_4 ) ;
V_5 &= ~ V_1 ;
F_5 ( & V_4 ) ;
}
