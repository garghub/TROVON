void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int F_3 ( unsigned int V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = F_4 ( V_2 ) ;
if ( ( ( F_5 ( V_6 ) >> ( 4 * V_5 ) ) & 3 ) == 3 )
F_6 ( 1 << V_5 , V_7 ) ;
else
F_6 ( 1 << V_5 , V_8 ) ;
return 0 ;
}
static void T_1 F_7 ( unsigned int V_9 )
{
F_6 ( 0 , V_10 ) ;
F_6 ( F_8 ( V_11 ) , V_12 ) ;
V_13 = F_9 ( V_14 ) ;
F_10 ( V_9 ) ;
}
