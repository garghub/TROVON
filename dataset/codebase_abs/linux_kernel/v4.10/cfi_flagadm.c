static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 ,
V_2 , V_3 ) ;
V_4 . V_5 = V_3 ;
V_4 . V_6 = F_3 ( V_3 ,
V_2 ) ;
if ( ! V_4 . V_6 ) {
F_2 ( L_2 ) ;
return - V_7 ;
}
F_4 ( & V_4 ) ;
V_8 = F_5 ( L_3 , & V_4 ) ;
if ( V_8 ) {
V_8 -> V_9 = V_10 ;
F_6 ( V_8 , V_11 , V_12 ) ;
F_2 ( V_1 L_4 ) ;
return 0 ;
}
F_7 ( ( void V_13 * ) V_4 . V_6 ) ;
return - V_14 ;
}
static void T_2 F_8 ( void )
{
if ( V_8 ) {
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
}
if ( V_4 . V_6 ) {
F_7 ( ( void V_13 * ) V_4 . V_6 ) ;
V_4 . V_6 = NULL ;
}
}
