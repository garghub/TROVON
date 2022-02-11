int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL ;
T_2 * V_6 = NULL , * V_7 = NULL ;
T_3 * V_8 = NULL , * V_9 = NULL ;
T_4 * V_10 = NULL ;
int V_11 = 1 ;
F_1 () ;
F_2 () ;
V_5 = F_3 ( L_1 , L_2 ) ;
if ( ! V_5 )
goto V_12;
V_6 = F_4 ( V_5 , NULL , 0 , NULL ) ;
F_5 ( V_5 ) ;
V_8 = F_6 ( V_5 , NULL , 0 , NULL ) ;
F_7 ( V_5 ) ;
V_5 = F_3 ( L_3 , L_2 ) ;
if ( ! V_5 )
goto V_12;
V_7 = F_4 ( V_5 , NULL , 0 , NULL ) ;
F_5 ( V_5 ) ;
V_9 = F_6 ( V_5 , NULL , 0 , NULL ) ;
if ( ! V_7 || ! V_9 )
goto V_12;
V_3 = F_3 ( L_4 , L_2 ) ;
if ( ! V_3 )
goto V_12;
V_10 = F_8 ( NULL , NULL , NULL , V_3 , V_13 | V_14 ) ;
if ( ! V_10 )
goto V_12;
if ( ! F_9 ( V_10 , V_6 , V_8 , NULL , 0 ) )
goto V_12;
if ( ! F_9 ( V_10 , V_7 , V_9 , NULL , 0 ) )
goto V_12;
V_4 = F_3 ( L_5 , L_6 ) ;
if ( ! V_4 )
goto V_12;
if ( ! F_10 ( V_4 , V_10 , V_3 , V_13 ) )
goto V_12;
V_11 = 0 ;
V_12:
if ( V_11 )
{
fprintf ( V_15 , L_7 ) ;
F_11 ( V_15 ) ;
}
if ( V_10 )
F_12 ( V_10 ) ;
if ( V_6 )
F_13 ( V_6 ) ;
if ( V_8 )
F_14 ( V_8 ) ;
if ( V_7 )
F_13 ( V_7 ) ;
if ( V_8 )
F_14 ( V_9 ) ;
if ( V_3 )
F_7 ( V_3 ) ;
if ( V_4 )
F_7 ( V_4 ) ;
if ( V_5 )
F_7 ( V_5 ) ;
return V_11 ;
}
