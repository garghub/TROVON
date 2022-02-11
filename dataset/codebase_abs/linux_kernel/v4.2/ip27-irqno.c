int F_1 ( void )
{
int V_1 ;
V_2:
V_1 = F_2 ( V_3 , V_4 ) ;
if ( V_1 >= V_4 )
return - V_5 ;
if ( F_3 ( V_1 , V_3 ) )
goto V_2;
return V_1 ;
}
void T_1 F_4 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 <= 16 ; V_6 ++ )
F_5 ( F_3 ( V_6 , V_3 ) ) ;
}
void F_6 ( unsigned int V_1 )
{
F_7 () ;
F_8 ( V_1 , V_3 ) ;
F_9 () ;
}
