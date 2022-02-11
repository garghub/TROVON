void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int F_3 ( unsigned int V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = F_4 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( ( ( F_6 ( V_7 ) >> ( 4 * V_5 ) ) & 3 ) == 3 )
F_7 ( 1 << V_5 , V_8 ) ;
else
F_7 ( 1 << V_5 , V_9 ) ;
return 0 ;
}
static void T_1 F_8 ( unsigned int V_10 )
{
F_7 ( 0 , V_11 ) ;
F_7 ( F_9 ( V_12 ) , V_13 ) ;
V_14 = F_10 ( V_15 ) ;
F_11 ( V_10 ) ;
}
static int F_12 ( unsigned int V_2 )
{
return 0 ;
}
