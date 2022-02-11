T_1 F_1 ( int V_1 )
{
return ( T_1 ) ( V_2 ) * 1000 * V_1 ;
}
static void F_2 ( T_2 * V_3 )
{
V_4 -> V_5 ( V_3 , V_6 ) ;
}
void F_3 ( const T_2 * V_3 , bool V_7 )
{
F_4 ( V_3 , V_7 ,
F_2 ) ;
}
static int F_5 ( unsigned int V_8 , struct V_9 * V_10 )
{
if ( F_6 ( V_10 ) )
return V_11 ;
return V_12 ;
}
static int T_3 F_7 ( void )
{
F_8 ( V_13 , F_5 ,
0 , L_1 ) ;
return 0 ;
}
