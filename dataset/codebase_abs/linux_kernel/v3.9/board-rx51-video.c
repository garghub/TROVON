static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 1 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 0 ) ;
}
static int T_1 F_4 ( void )
{
if ( ! F_5 () )
return 0 ;
if ( F_6 ( V_4 , V_5 ) ) {
F_7 ( L_1 , V_6 ) ;
return 0 ;
}
if ( F_8 ( V_4 , V_7 ,
L_2 ) ) {
F_7 ( L_3 , V_6 ) ;
return 0 ;
}
F_9 ( & V_8 ) ;
return 0 ;
}
