T_1
F_1 ( void )
{
unsigned long V_1 ;
T_1 V_2 ;
F_2 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
V_2 = V_3 -> V_6 ;
F_3 ( & V_3 -> V_6 ) ;
F_4 () ;
F_5 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
return V_2 ;
}
T_1 F_6 ( unsigned long V_7 )
{
unsigned long V_1 ;
T_1 V_2 ;
F_2 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
V_2 = V_3 -> V_6 ;
F_7 ( & V_3 -> V_6 , V_7 ) ;
F_4 () ;
F_5 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
return V_2 ;
}
T_1 F_8 ( unsigned long V_7 )
{
unsigned long V_1 ;
T_1 V_2 ;
F_2 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
V_2 = V_3 -> V_6 ;
F_7 ( & V_3 -> V_6 , ~ V_7 ) ;
F_4 () ;
F_5 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
return V_2 ;
}
void
F_9 ( T_1 V_2 )
{
unsigned long V_1 ;
F_2 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
V_3 -> V_6 = V_2 ;
F_4 () ;
F_5 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
}
void
F_10 ( void )
{
unsigned long V_1 ;
F_2 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
F_11 ( V_3 , V_8 ) ;
F_5 ( & V_3 -> V_4 -> V_5 , V_1 ) ;
}
