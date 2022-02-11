static int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = F_2 ( V_1 ) ;
if ( ( ( F_3 ( V_5 ) >> ( 4 * V_4 ) ) & 3 ) == 3 )
F_4 ( 1 << V_4 , V_6 ) ;
else
F_4 ( 1 << V_4 , V_7 ) ;
return 0 ;
}
static void T_1 F_5 ( unsigned int V_8 )
{
F_4 ( 0 , V_9 ) ;
F_4 ( F_6 ( V_10 ) , V_11 ) ;
F_7 ( V_12 , V_8 ) ;
}
