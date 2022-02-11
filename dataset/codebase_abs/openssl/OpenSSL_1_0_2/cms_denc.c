int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
T_2 * V_7 = NULL ;
F_1 ( T_2 ) * V_8 = NULL ;
T_3 * V_9 = NULL ;
int V_10 = 1 ;
int V_11 = V_12 | V_13 ;
F_2 () ;
F_3 () ;
V_5 = F_4 ( L_1 , L_2 ) ;
if ( ! V_5 )
goto V_14;
V_7 = F_5 ( V_5 , NULL , 0 , NULL ) ;
if ( ! V_7 )
goto V_14;
V_8 = F_6 () ;
if ( ! V_8 || ! F_7 ( V_8 , V_7 ) )
goto V_14;
V_7 = NULL ;
V_3 = F_4 ( L_3 , L_2 ) ;
V_6 = F_4 ( L_4 , L_5 ) ;
if ( ! V_3 )
goto V_14;
V_9 = F_8 ( V_8 , V_3 , F_9 () , V_11 ) ;
if ( ! V_9 )
goto V_14;
V_4 = F_4 ( L_6 , L_7 ) ;
if ( ! V_4 )
goto V_14;
if ( ! F_10 ( V_9 , V_3 , V_6 , V_11 ) )
goto V_14;
if ( ! F_11 ( V_4 , V_9 ) )
goto V_14;
V_10 = 0 ;
V_14:
if ( V_10 ) {
fprintf ( V_15 , L_8 ) ;
F_12 ( V_15 ) ;
}
if ( V_9 )
F_13 ( V_9 ) ;
if ( V_7 )
F_14 ( V_7 ) ;
if ( V_8 )
F_15 ( V_8 , F_14 ) ;
if ( V_3 )
F_16 ( V_3 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
if ( V_6 )
F_16 ( V_6 ) ;
if ( V_5 )
F_16 ( V_5 ) ;
return V_10 ;
}
