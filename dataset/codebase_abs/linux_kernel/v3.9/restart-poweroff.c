static void F_1 ( void )
{
F_2 ( 'h' , NULL ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_3 != NULL ) {
F_4 ( & V_2 -> V_4 ,
L_1 ) ;
return - V_5 ;
}
V_3 = & F_1 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( V_3 == & F_1 )
V_3 = NULL ;
return 0 ;
}
