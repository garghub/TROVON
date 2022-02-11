static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 , V_5 ;
F_2 ( V_2 , L_1 ) ;
F_3 (i)
F_4 ( V_2 , L_2 , V_4 ) ;
F_5 ( V_2 , '\n' ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
F_4 ( V_2 , L_3 , V_7 [ V_4 ] ) ;
F_3 (j)
F_4 ( V_2 , L_4 , F_6 ( V_4 , V_5 ) ) ;
F_5 ( V_2 , '\n' ) ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
return F_8 ( V_9 , F_1 , NULL ) ;
}
static int T_1 F_9 ( void )
{
F_10 ( L_5 , 0 , NULL , & V_10 ) ;
return 0 ;
}
