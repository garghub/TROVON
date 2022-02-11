void F_1 ( void )
{
V_1 ++ ;
if ( ! F_2 ( & V_2 ) )
F_3 ( & V_2 , V_3 + F_4 ( 10 ) ) ;
}
static void F_5 ( unsigned long V_4 )
{
if ( V_5 != V_1 ) {
V_5 = V_1 ;
F_6 ( V_6 , V_7 ) ;
F_3 ( & V_2 , V_3 + F_4 ( 10 ) ) ;
} else {
F_6 ( V_6 , V_8 ) ;
}
}
static int T_1 F_7 ( void )
{
F_8 ( L_1 , & V_6 ) ;
return 0 ;
}
static void T_2 F_9 ( void )
{
F_10 ( V_6 ) ;
}
