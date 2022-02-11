static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 )
{
if ( V_2 -> V_6 != F_2 ( 64 ) )
V_5 |= V_7 ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
}
void T_4 F_4 ( void )
{
V_8 = & V_9 ;
F_5 ( 1 ) ;
}
void T_4 F_6 ( void )
{
if ( ! V_10 ) {
#ifdef F_7
V_11 = 1 ;
F_8 ( V_12 L_1 ) ;
F_9 ( L_2 ) ;
F_5 ( 1 ) ;
V_8 = & V_9 ;
#else
F_10 ( L_3 ) ;
#endif
}
}
