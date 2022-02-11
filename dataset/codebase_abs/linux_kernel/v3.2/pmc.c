static void F_1 ( void )
{
#ifdef F_2
F_3 ( 0x00 , V_1 ) ;
#endif
F_4 ( F_5 ( V_2 ) | V_3 , V_2 ) ;
#ifdef F_2
F_3 ( V_1 , 0x00 ) ;
#endif
}
static int T_1 F_6 ( struct V_4 * V_5 )
{
V_6 = F_7 ( & V_5 -> V_7 [ 0 ] , 0 ,
F_8 ( & V_5 -> V_7 [ 0 ] ) , V_8 ) ;
if ( ! V_6 ) {
F_9 ( V_9 L_1 , V_10 ) ;
return - V_11 ;
}
#ifndef F_10
V_12 = F_1 ;
#endif
F_9 ( V_13 L_2 , V_10 ) ;
return 0 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_14 ) ;
}
