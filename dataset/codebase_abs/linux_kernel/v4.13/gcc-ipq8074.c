static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = F_3 ( & V_2 -> V_6 , V_5 [ V_4 ] ) ;
if ( V_3 )
return V_3 ;
}
return F_4 ( V_2 , & V_7 ) ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_8 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_8 ) ;
}
