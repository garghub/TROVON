static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
}
static void F_2 ( void )
{
int V_5 = F_3 () ;
struct V_3 * V_4 = F_4 ( & V_6 ) ;
V_4 -> V_7 = L_1 ;
V_4 -> V_8 = V_9 |
V_10 |
V_11 ;
V_4 -> V_12 = 100 ;
V_4 -> V_13 = F_1 ;
V_4 -> V_14 = F_5 ( V_5 ) ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
if ( ( V_17 & ~ V_19 ) == V_20 )
F_2 () ;
return V_21 ;
}
static int T_1 F_8 ( void )
{
int V_22 = 0 ;
F_9 () ;
V_22 = F_10 ( & V_23 ) ;
if ( V_22 )
goto V_24;
if ( F_11 () > 1 )
F_2 () ;
V_24:
F_12 () ;
return V_22 ;
}
