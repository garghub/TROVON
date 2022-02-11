int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 , * V_4 , * V_5 ;
F_2 ( V_6 ) ;
F_3 () ;
V_3 = F_4 ( NULL , L_1 ) ;
V_4 = F_4 ( NULL , L_2 ) ;
V_5 = F_4 ( NULL , L_3 ) ;
V_1 = F_5 ( V_3 , V_4 ) ;
if ( ! V_1 )
V_1 = F_6 ( V_5 , V_7 ) ;
if ( V_1 )
F_7 ( L_4 , V_8 ) ;
V_5 = F_4 ( NULL , L_5 ) ;
V_1 = F_6 ( V_5 , V_7 * 2 ) ;
if ( V_1 )
F_7 ( L_6 , V_8 ) ;
V_5 = F_4 ( NULL , L_7 ) ;
V_1 = F_6 ( V_5 , V_9 ) ;
if ( V_1 )
F_7 ( L_8 , V_8 ) ;
return V_1 ;
}
