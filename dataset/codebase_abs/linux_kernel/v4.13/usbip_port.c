static int F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
int V_4 ;
if ( F_2 ( V_5 ) )
F_3 ( L_1 , V_5 ) ;
V_4 = F_4 () ;
if ( V_4 < 0 ) {
F_3 ( L_2 ) ;
goto V_6;
}
printf ( L_3 ) ;
printf ( L_4 ) ;
for ( V_1 = 0 ; V_1 < V_7 -> V_8 ; V_1 ++ ) {
V_3 = & V_7 -> V_3 [ V_1 ] ;
if ( F_5 ( V_3 ) < 0 )
goto V_9;
}
F_6 () ;
F_7 () ;
return V_4 ;
V_9:
F_6 () ;
V_6:
F_7 () ;
return - 1 ;
}
