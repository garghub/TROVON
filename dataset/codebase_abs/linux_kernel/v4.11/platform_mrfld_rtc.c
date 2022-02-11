static int T_1 F_1 ( void )
{
struct V_1 V_2 ;
int V_3 ;
if ( ! V_4 . V_5 . V_6 )
return - V_7 ;
F_2 ( & V_2 , V_8 , 1 , 0 ) ;
V_3 = F_3 ( V_9 , V_10 , & V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( L_1 ) ;
V_4 . V_5 . V_6 = 0 ;
return V_3 ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
if ( F_6 () != V_11 )
return - V_7 ;
return F_1 () ;
}
