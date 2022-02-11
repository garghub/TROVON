static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_5 ;
int V_6 ;
int V_7 ;
V_5 = F_2 ( V_2 , & V_8 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
for ( V_7 = 0 ; V_7 < F_5 ( V_9 ) ; V_7 ++ ) {
V_6 = F_6 ( V_4 , V_9 [ V_7 ] ) ;
if ( V_6 )
return V_6 ;
}
return F_7 ( V_2 , & V_8 , V_5 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_10 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_10 ) ;
}
