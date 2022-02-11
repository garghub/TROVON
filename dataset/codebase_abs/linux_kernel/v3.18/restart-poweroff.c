static void F_1 ( void )
{
V_1 = V_2 ;
F_2 ( NULL ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
if ( V_5 != NULL ) {
F_4 ( & V_4 -> V_6 ,
L_1 ) ;
return - V_7 ;
}
V_5 = & F_1 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 )
{
if ( V_5 == & F_1 )
V_5 = NULL ;
return 0 ;
}
