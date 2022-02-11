static int T_1 F_1 ( void )
{
int V_1 = 0 ;
V_2 . V_3 = F_2 ( V_2 . V_4 , V_2 . V_5 ) ;
if ( ! V_2 . V_3 ) {
F_3 ( V_6 L_1 ) ;
V_1 = - V_7 ;
goto V_8;
}
F_4 ( & V_2 ) ;
V_9 = F_5 ( L_2 , & V_2 ) ;
if ( ! V_9 )
V_9 = F_5 ( L_3 , & V_2 ) ;
if ( ! V_9 ) {
V_1 = - V_10 ;
goto V_11;
}
V_9 -> V_12 = V_13 ;
F_6 ( V_9 , V_14 , V_15 ) ;
return 0 ;
V_11:
F_7 ( V_2 . V_3 ) ;
V_8:
return V_1 ;
}
static void T_2 F_8 ( void )
{
if ( V_9 ) {
F_9 ( V_9 ) ;
F_10 ( V_9 ) ;
}
if ( V_2 . V_3 ) {
F_7 ( V_2 . V_3 ) ;
V_2 . V_3 = NULL ;
}
}
