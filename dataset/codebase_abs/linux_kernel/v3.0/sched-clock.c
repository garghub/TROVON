unsigned long long T_1 F_1 ( void )
{
if ( V_1 ) {
T_2 V_2 = F_2 ( V_1 ) ;
return F_3 ( & V_3 , V_2 , ( T_2 ) ~ 0 ,
V_4 , V_5 ) ;
} else
return 0 ;
}
static void T_1 F_4 ( void )
{
T_2 V_2 = F_2 ( V_1 ) ;
F_5 ( & V_3 , V_2 , ( T_2 ) ~ 0 ) ;
}
void T_3 F_6 ( void T_4 * V_6 , unsigned long V_7 )
{
V_1 = V_6 ;
F_7 ( & V_3 , F_4 ,
32 , V_7 , V_4 , V_5 ) ;
}
