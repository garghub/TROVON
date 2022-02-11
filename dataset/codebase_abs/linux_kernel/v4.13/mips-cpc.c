T_1 __weak F_1 ( void )
{
return 0 ;
}
static T_1 F_2 ( void )
{
unsigned long V_1 ;
if ( ! F_3 () )
return 0 ;
if ( ! ( F_4 () & V_2 ) )
return 0 ;
V_1 = F_5 () ;
if ( V_1 & V_3 )
return V_1 & V_4 ;
V_1 = F_1 () ;
if ( ! V_1 )
return V_1 ;
F_6 ( V_1 | V_3 ) ;
return V_1 ;
}
int F_7 ( void )
{
T_1 V_5 ;
unsigned int V_6 ;
F_8 (cpu)
F_9 ( & F_10 ( V_7 , V_6 ) ) ;
V_5 = F_2 () ;
if ( ! V_5 )
return - V_8 ;
V_9 = F_11 ( V_5 , 0x8000 ) ;
if ( ! V_9 )
return - V_10 ;
return 0 ;
}
void F_12 ( unsigned int V_11 )
{
unsigned int V_12 ;
if ( F_13 () >= V_13 )
return;
F_14 () ;
V_12 = V_14 . V_11 ;
F_15 ( & F_10 ( V_7 , V_12 ) ,
F_10 ( V_15 , V_12 ) ) ;
F_16 ( V_11 << V_16 ) ;
F_17 () ;
}
void F_18 ( void )
{
unsigned int V_12 ;
if ( F_13 () >= V_13 )
return;
V_12 = V_14 . V_11 ;
F_19 ( & F_10 ( V_7 , V_12 ) ,
F_10 ( V_15 , V_12 ) ) ;
F_20 () ;
}
