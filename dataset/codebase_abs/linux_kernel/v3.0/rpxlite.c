static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 , V_2 * 4 , V_3 ) ;
V_4 . V_5 = F_3 ( V_3 , V_2 * 4 ) ;
if ( ! V_4 . V_5 ) {
F_2 ( L_2 ) ;
return - V_6 ;
}
F_4 ( & V_4 ) ;
V_7 = F_5 ( L_3 , & V_4 ) ;
if ( V_7 ) {
V_7 -> V_8 = V_9 ;
F_6 ( V_7 , NULL , 0 ) ;
return 0 ;
}
F_7 ( ( void * ) V_4 . V_5 ) ;
return - V_10 ;
}
static void T_2 F_8 ( void )
{
if ( V_7 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
if ( V_4 . V_5 ) {
F_7 ( ( void * ) V_4 . V_5 ) ;
V_4 . V_5 = 0 ;
}
}
