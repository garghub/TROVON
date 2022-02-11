static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_1 , L_2 ) ;
return 0 ;
}
static int F_3 ( void )
{
int V_4 ;
V_4 = F_4 ( & V_5 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_5 ( & V_5 ) ;
if ( V_4 ) {
F_6 ( F_7 ( & V_5 ) ) ;
return V_4 ;
}
return 0 ;
}
static void F_8 ( void )
{
F_6 ( F_9 ( & V_5 ) ) ;
F_6 ( F_7 ( & V_5 ) ) ;
}
