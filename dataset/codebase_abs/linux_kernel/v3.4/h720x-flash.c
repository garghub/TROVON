static int T_1 F_1 ( void )
{
V_1 . V_2 = F_2 ( V_1 . V_3 , V_1 . V_4 ) ;
if ( ! V_1 . V_2 ) {
F_3 ( V_5 L_1 ) ;
return - V_6 ;
}
F_4 ( & V_1 ) ;
F_3 ( V_7 L_2 ) ;
V_8 = F_5 ( L_3 , & V_1 ) ;
if ( ! V_8 ) {
F_3 ( V_7 L_4 ) ;
V_1 . V_9 = 2 ;
V_8 = F_5 ( L_3 , & V_1 ) ;
}
if ( V_8 ) {
V_8 -> V_10 = V_11 ;
F_6 ( V_8 , NULL , NULL ,
V_12 , V_13 ) ;
return 0 ;
}
F_7 ( ( void * ) V_1 . V_2 ) ;
return - V_14 ;
}
static void T_2 F_8 ( void )
{
if ( V_8 ) {
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
}
if ( V_1 . V_2 ) {
F_7 ( ( void * ) V_1 . V_2 ) ;
V_1 . V_2 = 0 ;
}
}
