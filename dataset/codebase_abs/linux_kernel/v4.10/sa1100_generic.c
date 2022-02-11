static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = - V_5 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 ) ; V_3 ++ ) {
V_4 = V_6 [ V_3 ] ( & V_2 -> V_2 ) ;
if ( V_4 == 0 )
break;
}
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 ) ;
int V_3 ;
F_5 ( V_2 , NULL ) ;
for ( V_3 = 0 ; V_3 < V_8 -> V_9 ; V_3 ++ )
F_6 ( & V_8 -> V_10 [ V_3 ] ) ;
return 0 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_11 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_11 ) ;
}
