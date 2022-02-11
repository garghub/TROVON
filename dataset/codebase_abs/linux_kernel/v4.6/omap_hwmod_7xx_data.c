static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
F_2 ( V_2 , V_2 -> V_5 [ V_3 ] . V_6 ) ;
F_3 ( V_2 , V_2 -> V_5 [ V_3 ] . V_6 ) ;
}
return 0 ;
}
int T_1 F_4 ( void )
{
int V_7 ;
F_5 () ;
V_7 = F_6 ( V_8 ) ;
if ( ! V_7 && F_7 () )
return F_6 ( V_9 ) ;
else if ( ! V_7 && F_8 () )
return F_6 ( V_10 ) ;
return V_7 ;
}
