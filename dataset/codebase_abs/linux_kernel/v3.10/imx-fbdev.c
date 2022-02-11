static int T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 () ;
if ( ! V_2 )
return - V_3 ;
if ( V_4 != 16 && V_4 != 32 ) {
F_3 ( L_1 ) ;
V_4 = 16 ;
}
V_5 = F_4 ( V_2 , V_4 ,
V_2 -> V_6 . V_7 , V_8 ) ;
if ( F_5 ( V_5 ) ) {
F_6 () ;
return F_7 ( V_5 ) ;
}
F_8 ( V_5 ) ;
return 0 ;
}
static void T_2 F_9 ( void )
{
F_8 ( NULL ) ;
F_10 ( V_5 ) ;
F_6 () ;
}
