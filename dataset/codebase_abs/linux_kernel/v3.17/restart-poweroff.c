static void F_1 ( void )
{
F_2 ( V_1 , NULL ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
if ( V_4 != NULL ) {
F_4 ( & V_3 -> V_5 ,
L_1 ) ;
return - V_6 ;
}
V_4 = & F_1 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
if ( V_4 == & F_1 )
V_4 = NULL ;
return 0 ;
}
