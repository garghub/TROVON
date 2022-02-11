static int T_1 F_1 ( void )
{
int V_1 ;
if ( F_2 () ) {
F_3 ( V_2 L_1 ) ;
return ( - V_3 ) ;
}
if ( ( V_1 = F_4 ( & V_4 ) ) != V_5 ) {
F_5 () ;
F_3 ( V_2 L_2 , V_1 ) ;
return ( - V_3 ) ;
}
F_3 ( V_6 L_3 ) ;
return ( 0 ) ;
}
static void T_2 F_6 ( void )
{
unsigned long V_7 ;
int V_1 ;
F_7 ( & V_8 , V_7 ) ;
V_4 . V_9 = V_10 ;
if ( ( V_1 = F_4 ( & V_4 ) ) != V_5 ) {
F_3 ( V_2 L_4 , V_1 ) ;
F_8 ( & V_8 , V_7 ) ;
return;
}
if ( F_5 () ) {
F_3 ( V_2 L_5 ) ;
F_8 ( & V_8 , V_7 ) ;
return;
}
F_8 ( & V_8 , V_7 ) ;
F_9 ( - 1 ) ;
F_10 () ;
F_3 ( V_6 L_6 ) ;
}
