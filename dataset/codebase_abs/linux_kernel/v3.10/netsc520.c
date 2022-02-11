static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 ,
( unsigned long long ) V_2 . V_3 ,
( unsigned long long ) V_2 . V_4 ) ;
V_2 . V_5 = F_3 ( V_2 . V_4 , V_2 . V_3 ) ;
if ( ! V_2 . V_5 ) {
F_2 ( L_2 ) ;
return - V_6 ;
}
F_4 ( & V_2 ) ;
V_7 = F_5 ( L_3 , & V_2 ) ;
if( ! V_7 )
V_7 = F_5 ( L_4 , & V_2 ) ;
if( ! V_7 )
V_7 = F_5 ( L_5 , & V_2 ) ;
if ( ! V_7 ) {
F_6 ( V_2 . V_5 ) ;
return - V_8 ;
}
V_7 -> V_9 = V_10 ;
F_7 ( V_7 , V_11 , V_12 ) ;
return 0 ;
}
static void T_2 F_8 ( void )
{
if ( V_7 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
if ( V_2 . V_5 ) {
F_6 ( V_2 . V_5 ) ;
V_2 . V_5 = NULL ;
}
}
