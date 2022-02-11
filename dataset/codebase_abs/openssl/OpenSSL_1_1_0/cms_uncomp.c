int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
int V_6 = 1 ;
F_1 () ;
F_2 () ;
V_3 = F_3 ( L_1 , L_2 ) ;
if ( ! V_3 )
goto V_7;
V_5 = F_4 ( V_3 , NULL ) ;
if ( ! V_5 )
goto V_7;
V_4 = F_3 ( L_3 , L_4 ) ;
if ( ! V_4 )
goto V_7;
if ( ! F_5 ( V_5 , V_4 , NULL , 0 ) )
goto V_7;
V_6 = 0 ;
V_7:
if ( V_6 ) {
fprintf ( V_8 , L_5 ) ;
F_6 ( V_8 ) ;
}
F_7 ( V_5 ) ;
F_8 ( V_3 ) ;
F_8 ( V_4 ) ;
return V_6 ;
}
