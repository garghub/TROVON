int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 , * V_4 , * V_5 , * V_6 ;
F_2 ( V_7 ) ;
F_3 () ;
V_3 = F_4 ( NULL , L_1 ) ;
V_5 = F_4 ( NULL , L_2 ) ;
V_1 = F_5 ( V_3 , V_5 ) ;
V_4 = F_4 ( NULL , L_3 ) ;
if ( ! V_1 )
V_1 = F_6 ( V_4 , V_8 ) ;
if ( V_1 )
F_7 ( L_4 , V_9 ) ;
V_4 = F_4 ( NULL , L_5 ) ;
if ( ! V_1 )
V_1 = F_6 ( V_4 , V_8 * 2 ) ;
if ( V_1 )
F_7 ( L_6 , V_9 ) ;
V_6 = F_4 ( NULL , L_7 ) ;
V_1 = F_6 ( V_6 , V_10 ) ;
if ( V_1 )
F_7 ( L_8 , V_9 ) ;
V_6 = F_4 ( NULL , L_9 ) ;
V_1 = F_6 ( V_6 , V_10 / 2 ) ;
if ( V_1 )
F_7 ( L_10 , V_9 ) ;
return 0 ;
}
