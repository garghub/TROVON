static bool F_1 ( void )
{
static bool V_1 ;
int V_2 ;
if ( V_1 )
return true ;
V_2 = F_2 ( V_3 , F_3 ( V_3 ) ) ;
if ( V_2 )
F_4 ( L_1 , V_4 ) ;
else
V_1 = true ;
return V_1 ;
}
static void F_5 ( int V_5 )
{
if ( ! F_1 () )
return;
F_6 ( V_6 , V_5 ) ;
F_6 ( V_7 , V_5 ) ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
V_8 &= ~ 0x000001fb ;
}
static int F_9 ( struct V_9 * V_10 , unsigned int V_11 )
{
F_6 ( V_12 , V_11 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 , unsigned int V_13 )
{
F_6 ( V_14 , ! ( V_13 < 4000000 ) ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
return F_2 ( V_15 , sizeof( V_15 ) ) ;
}
static void F_12 ( struct V_9 * V_10 )
{
return F_13 ( V_15 , sizeof( V_15 ) ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_16 , F_3 ( V_16 ) ) ;
F_16 () ;
F_17 ( & V_17 ) ;
F_18 ( & V_18 ) ;
}
