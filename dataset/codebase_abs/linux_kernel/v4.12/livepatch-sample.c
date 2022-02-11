static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_1 , L_2 ) ;
return 0 ;
}
static int F_3 ( void )
{
int V_4 ;
if ( ! F_4 () && ! V_5 . V_6 ) {
V_5 . V_6 = true ;
F_5 ( L_3 ) ;
}
V_4 = F_6 ( & V_5 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_7 ( & V_5 ) ;
if ( V_4 ) {
F_8 ( F_9 ( & V_5 ) ) ;
return V_4 ;
}
return 0 ;
}
static void F_10 ( void )
{
F_8 ( F_9 ( & V_5 ) ) ;
}
