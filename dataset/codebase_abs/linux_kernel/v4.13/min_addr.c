static void F_1 ( void )
{
#ifdef F_2
if ( V_1 > F_2 )
V_2 = V_1 ;
else
V_2 = F_2 ;
#else
V_2 = V_1 ;
#endif
}
int F_3 ( struct V_3 * V_4 , int V_5 ,
void T_1 * V_6 , T_2 * V_7 , T_3 * V_8 )
{
int V_9 ;
if ( V_5 && ! F_4 ( V_10 ) )
return - V_11 ;
V_9 = F_5 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
F_1 () ;
return V_9 ;
}
static int T_4 F_6 ( void )
{
F_1 () ;
return 0 ;
}
