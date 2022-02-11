void F_1 ( void )
{
F_2 ( & V_1 ) ;
if ( ! V_2 ) {
F_3 ( V_3 ) ;
V_2 = TRUE ;
}
F_4 ( & V_1 ) ;
}
void F_5 ( void )
{
F_2 ( & V_1 ) ;
if ( V_2 ) {
F_6 ( V_3 ) ;
V_2 = FALSE ;
}
F_4 ( & V_1 ) ;
}
