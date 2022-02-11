void T_1 F_1 ( void )
{
F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
F_4 () ;
}
void T_1 F_5 ( void )
{
F_6 () ;
F_7 ( 0 , V_2 ,
F_3 ( V_2 ) ) ;
}
void T_1 F_8 ( int V_3 )
{
int V_4 ;
int V_5 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_5 = F_9 ( V_6 [ V_4 ] , NULL ) ;
if ( V_5 == 0 ) {
V_5 = F_10 (
V_6 [ V_4 ] , 1 ) ;
F_11 ( V_6 [ V_4 ] ) ;
}
if ( V_5 )
F_12 ( L_1 , V_4 + 1 ) ;
}
}
