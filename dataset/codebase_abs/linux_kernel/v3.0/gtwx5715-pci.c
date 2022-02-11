void T_1 F_1 ( void )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
F_2 ( F_3 ( V_3 ) , V_2 ) ;
F_4 () ;
}
static int T_1 F_5 ( struct V_4 * V_5 , T_2 V_6 , T_2 V_7 )
{
int V_8 = - 1 ;
if ( ( V_6 == V_9 && V_7 == 1 ) ||
( V_6 == V_10 && V_7 == 2 ) )
V_8 = F_3 ( V_1 ) ;
else if ( ( V_6 == V_9 && V_7 == 2 ) ||
( V_6 == V_10 && V_7 == 1 ) )
V_8 = F_3 ( V_3 ) ;
F_6 ( V_11 L_1 ,
V_12 , V_6 , V_7 , V_8 ) ;
return V_8 ;
}
int T_1 F_7 ( void )
{
if ( F_8 () )
F_9 ( & V_13 ) ;
return 0 ;
}
