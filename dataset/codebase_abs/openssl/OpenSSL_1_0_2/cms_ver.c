int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
T_2 * V_7 = NULL ;
T_3 * V_8 = NULL ;
T_4 * V_9 = NULL ;
int V_10 = 1 ;
F_1 () ;
F_2 () ;
V_7 = F_3 () ;
V_5 = F_4 ( L_1 , L_2 ) ;
if ( ! V_5 )
goto V_11;
V_8 = F_5 ( V_5 , NULL , 0 , NULL ) ;
if ( ! V_8 )
goto V_11;
if ( ! F_6 ( V_7 , V_8 ) )
goto V_11;
V_3 = F_4 ( L_3 , L_2 ) ;
if ( ! V_3 )
goto V_11;
V_9 = F_7 ( V_3 , & V_6 ) ;
if ( ! V_9 )
goto V_11;
V_4 = F_4 ( L_4 , L_5 ) ;
if ( ! V_4 )
goto V_11;
if ( ! F_8 ( V_9 , NULL , V_7 , V_6 , V_4 , 0 ) ) {
fprintf ( V_12 , L_6 ) ;
goto V_11;
}
fprintf ( V_12 , L_7 ) ;
V_10 = 0 ;
V_11:
if ( V_10 ) {
fprintf ( V_12 , L_8 ) ;
F_9 ( V_12 ) ;
}
if ( V_9 )
F_10 ( V_9 ) ;
if ( V_8 )
F_11 ( V_8 ) ;
if ( V_3 )
F_12 ( V_3 ) ;
if ( V_4 )
F_12 ( V_4 ) ;
if ( V_5 )
F_12 ( V_5 ) ;
return V_10 ;
}
