void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_1 -> V_4 , V_3 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( & V_1 -> V_4 , V_3 ) ;
}
T_3
F_5 ( void )
{
unsigned long V_3 ;
T_3 V_5 ;
F_2 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
V_5 = V_6 -> V_9 ;
F_6 ( & V_6 -> V_9 ) ;
F_7 () ;
F_4 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
return V_5 ;
}
T_3 F_8 ( unsigned long V_10 )
{
unsigned long V_3 ;
T_3 V_5 ;
F_2 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
V_5 = V_6 -> V_9 ;
F_9 ( & V_6 -> V_9 , V_10 ) ;
F_7 () ;
F_4 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
return V_5 ;
}
T_3 F_10 ( unsigned long V_10 )
{
unsigned long V_3 ;
T_3 V_5 ;
F_2 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
V_5 = V_6 -> V_9 ;
F_9 ( & V_6 -> V_9 , ~ V_10 ) ;
F_7 () ;
F_4 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
return V_5 ;
}
void
F_11 ( T_3 V_5 )
{
unsigned long V_3 ;
F_2 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
V_6 -> V_9 = V_5 ;
F_7 () ;
F_4 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
}
int
F_12 ( void )
{
return F_13 ( V_6 ) ;
}
void
F_14 ( void )
{
unsigned long V_3 ;
F_2 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
F_15 ( V_6 , V_11 ) ;
F_4 ( & V_6 -> V_7 -> V_8 , V_3 ) ;
}
