static void F_1 ( void )
{
int V_1 = F_2 () ;
struct V_2 * V_3 = F_3 ( & V_4 ) ;
V_3 -> V_5 = L_1 ;
V_3 -> V_6 = V_7 |
V_8 |
V_9 ;
V_3 -> V_10 = 100 ;
V_3 -> V_11 = F_4 ( V_1 ) ;
F_5 ( V_3 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
if ( ( V_14 & ~ V_16 ) == V_17 )
F_1 () ;
return V_18 ;
}
static int T_1 F_7 ( void )
{
int V_19 = 0 ;
F_8 () ;
V_19 = F_9 ( & V_20 ) ;
if ( V_19 )
goto V_21;
if ( F_10 () > 1 )
F_1 () ;
V_21:
F_11 () ;
return V_19 ;
}
