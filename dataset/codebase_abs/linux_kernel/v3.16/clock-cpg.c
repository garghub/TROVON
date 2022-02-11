int T_1 T_2 F_1 ( void )
{
int V_1 , V_2 = 0 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_3 ) ; V_1 ++ ) {
struct V_4 * V_4 = V_3 [ V_1 ] ;
F_3 ( & V_4 -> V_5 , V_1 ) ;
if ( V_4 -> V_5 )
V_2 |= F_4 ( V_4 ) ;
}
F_5 ( V_6 , F_2 ( V_6 ) ) ;
F_6 ( L_1 , L_2 , L_3 , NULL ) ;
F_6 ( L_1 , L_4 , L_3 , NULL ) ;
F_6 ( L_1 , L_5 , L_3 , NULL ) ;
F_6 ( L_1 , L_6 , L_3 , NULL ) ;
F_6 ( L_1 , L_7 , L_3 , NULL ) ;
F_6 ( L_1 , L_8 , L_3 , NULL ) ;
F_6 ( L_1 , L_9 , L_3 , NULL ) ;
F_6 ( L_10 , NULL , L_3 , NULL ) ;
return V_2 ;
}
int T_1 __weak F_7 ( void )
{
return F_1 () ;
}
