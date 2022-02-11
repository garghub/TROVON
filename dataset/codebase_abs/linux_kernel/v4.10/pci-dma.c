static int T_1 F_1 ( void )
{
if ( V_1 )
F_2 () ;
return 0 ;
}
void F_3 ( void )
{
return;
}
void T_1
F_4 ( void )
{
return;
}
int F_5 ( struct V_2 * V_3 , T_2 V_4 )
{
if ( V_4 < F_6 ( 24 ) )
return 0 ;
if ( V_5 && ( V_4 >= F_6 ( 40 ) ) ) {
F_7 ( V_3 , L_1 , V_4 ) ;
return 0 ;
}
return 1 ;
}
void T_1 F_8 ( void )
{
V_6 = & V_7 ;
V_6 -> V_8 = V_9 ;
V_6 -> V_10 = V_11 ;
V_6 -> V_12 = V_9 ;
V_6 -> V_13 = V_11 ;
V_6 -> V_14 = F_5 ;
F_9 () ;
#ifdef F_10
F_11 () ;
#endif
}
