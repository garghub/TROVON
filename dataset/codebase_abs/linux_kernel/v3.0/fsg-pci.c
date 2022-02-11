void T_1 F_1 ( void )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
F_2 ( F_3 ( V_3 ) , V_2 ) ;
F_2 ( F_3 ( V_4 ) , V_2 ) ;
F_4 () ;
}
static int T_1 F_5 ( struct V_5 * V_6 , T_2 V_7 , T_2 V_8 )
{
static int V_9 [ V_10 ] = {
F_3 ( V_4 ) ,
F_3 ( V_3 ) ,
F_3 ( V_1 ) ,
} ;
int V_11 = - 1 ;
V_7 -= 11 ;
if ( V_7 >= 1 && V_7 <= V_12 && V_8 >= 1 && V_8 <= V_10 )
V_11 = V_9 [ V_7 - 1 ] ;
F_6 ( V_13 L_1 ,
V_14 , V_7 , V_8 , V_11 ) ;
return V_11 ;
}
int T_1 F_7 ( void )
{
if ( F_8 () )
F_9 ( & V_15 ) ;
return 0 ;
}
