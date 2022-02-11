static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_5 + 8 ) ;
V_3 &= ~ V_2 ;
V_3 |= V_1 ;
F_4 ( V_3 , V_5 + 8 ) ;
F_5 ( & V_4 ) ;
}
unsigned int T_1 F_6 ( void )
{
if ( ! V_5 ) {
V_5 = F_7 ( V_6 , V_7 ) ;
F_8 () ;
}
F_9 ( ! V_5 ) ;
return V_5 ? F_10 ( V_5 ) : 1 ;
}
int F_11 ( unsigned int V_8 )
{
return 0 ;
}
void T_2 F_12 ( unsigned int V_8 )
{
F_13 ( 0 ) ;
}
int T_2 F_14 ( unsigned int V_8 )
{
V_8 = F_15 ( V_8 ) ;
F_1 ( 0 , 3 << ( V_8 * 8 ) ) ;
F_16 ( F_17 ( V_9 ) ) ;
F_18 ( F_19 ( V_8 ) , 1 ) ;
return 0 ;
}
void T_1 F_20 ( void )
{
int V_8 = F_15 ( 0 ) ;
F_21 ( V_5 ) ;
F_1 ( 0 , 3 << ( V_8 * 8 ) ) ;
}
