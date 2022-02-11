static int T_1 F_1 ( void )
{
F_2 (KERN_INFO OSM_DESCRIPTION L_1 OSM_VERSION L_2 ) ;
if ( F_3 ( & V_1 ) ) {
F_4 ( L_3 ) ;
return - V_2 ;
}
#ifdef F_5
if ( F_6 () ) {
F_4 ( L_4 ) ;
F_7 ( & V_1 ) ;
return - V_2 ;
}
#endif
return 0 ;
}
static void F_8 ( void )
{
#ifdef F_5
F_9 () ;
#endif
F_7 ( & V_1 ) ;
}
