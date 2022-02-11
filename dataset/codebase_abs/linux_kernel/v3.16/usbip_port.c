static int F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
int V_4 ;
V_4 = F_2 () ;
if ( V_4 < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
printf ( L_2 ) ;
printf ( L_3 ) ;
for ( V_1 = 0 ; V_1 < V_5 -> V_6 ; V_1 ++ ) {
V_3 = & V_5 -> V_3 [ V_1 ] ;
if ( F_4 ( V_3 ) < 0 )
V_4 = - 1 ;
}
F_5 () ;
return V_4 ;
}
