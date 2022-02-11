void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int F_3 ( unsigned int V_2 )
{
struct V_3 * V_4 = NULL ;
int V_5 = - V_6 ;
V_2 = F_4 ( V_2 ) ;
if ( V_2 < F_5 ( V_7 ) )
V_4 = V_7 [ V_2 ] ;
if ( V_4 )
V_5 = F_6 ( V_4 ) ;
return V_5 ? V_5 : 1 ;
}
static int F_7 ( unsigned int V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = NULL ;
unsigned int V_10 = F_4 ( V_2 ) ;
int V_5 ;
if ( V_10 < F_5 ( V_7 ) )
V_4 = V_7 [ V_10 ] ;
if ( V_4 )
V_5 = F_8 ( V_4 ) ;
else
V_5 = - V_6 ;
return V_5 ;
}
static void T_1 F_9 ( unsigned int V_11 )
{
F_10 ( F_11 ( V_12 ) , V_13 ) ;
V_14 = F_12 ( V_15 ) ;
V_16 = ( unsigned long ) V_17 ;
V_17 = F_13 ( V_18 ) ;
F_14 ( V_11 ) ;
F_15 () ;
F_3 ( 1 ) ;
F_3 ( 2 ) ;
F_3 ( 3 ) ;
}
static int F_16 ( unsigned int V_2 )
{
if ( F_17 ( V_2 ) )
return F_3 ( V_2 ) ;
return 0 ;
}
static int F_18 ( unsigned int V_2 )
{
return V_2 == 0 ? - V_19 : 0 ;
}
