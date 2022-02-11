static int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
V_2 = F_2 ( V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_3 ) ;
F_4 () ;
F_5 ( L_1 ) ;
return 1 ;
}
static void F_6 ( void )
{
F_7 ( V_3 ,
V_5 , F_8 ( V_5 ) ) ;
}
static int F_9 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_10 = F_6 ;
V_11 = F_1 ;
return 0 ;
}
static T_1 int F_10 ( void )
{
return F_11 ( & V_12 ) ;
}
static int F_12 ( void )
{
F_13 ( V_13 , F_8 ( V_13 ) ) ;
return 0 ;
}
static void F_14 ( void )
{
unsigned long V_2 ;
V_2 = F_2 ( V_3 ) ;
V_2 &= ~ V_14 ;
V_2 |= V_15 ;
F_3 ( V_2 , V_3 ) ;
F_15 ( V_13 , F_8 ( V_13 ) ) ;
}
