static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
#if F_2 ( V_5 ) || F_2 ( V_6 )
F_3 ( V_2 ) ;
#elif F_2 ( V_7 ) || F_2 ( V_8 )
if ( V_4 -> V_9 == V_10 )
F_3 ( V_2 ) ;
#endif
return 1 ;
}
void T_1 F_4 ( void )
{
F_5 ( & V_11 ) ;
}
