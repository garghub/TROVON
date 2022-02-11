static T_1 F_1 ( void )
{
unsigned long V_1 ;
if ( ! F_2 () )
return 0 ;
if ( ! ( F_3 () & V_2 ) )
return 0 ;
V_1 = F_4 () ;
if ( V_1 & V_3 )
return V_1 & V_4 ;
V_1 = F_5 () ;
F_6 ( V_1 | V_3 ) ;
return V_1 ;
}
int F_7 ( void )
{
T_1 V_5 ;
unsigned V_6 ;
F_8 (cpu)
F_9 ( & F_10 ( V_7 , V_6 ) ) ;
V_5 = F_1 () ;
if ( ! V_5 )
return - V_8 ;
V_9 = F_11 ( V_5 , 0x8000 ) ;
if ( ! V_9 )
return - V_10 ;
return 0 ;
}
void F_12 ( unsigned int V_11 )
{
unsigned V_12 ;
F_13 () ;
V_12 = V_13 . V_11 ;
F_14 ( & F_10 ( V_7 , V_12 ) ,
F_10 ( V_14 , V_12 ) ) ;
F_15 ( V_11 << V_15 ) ;
}
void F_16 ( void )
{
unsigned V_12 = V_13 . V_11 ;
F_17 ( & F_10 ( V_7 , V_12 ) ,
F_10 ( V_14 , V_12 ) ) ;
F_18 () ;
}
