static int T_1 F_1 ( void )
{
int V_1 , V_2 = 0 ;
F_2 ( V_3 L_1 ) ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ )
if ( V_5 [ V_1 ] != NULL ) {
F_2 ( V_3 L_2 , V_1 , V_5 [ V_1 ] -> V_6 ) ;
V_2 ++ ;
}
if ( V_2 == 0 )
F_2 ( V_3 L_3 ) ;
return 0 ;
}
