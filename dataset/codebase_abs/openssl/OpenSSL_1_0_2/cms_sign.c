int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL ;
T_2 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_4 * V_8 = NULL ;
int V_9 = 1 ;
int V_10 = V_11 | V_12 ;
F_1 () ;
F_2 () ;
V_5 = F_3 ( L_1 , L_2 ) ;
if ( ! V_5 )
goto V_13;
V_6 = F_4 ( V_5 , NULL , 0 , NULL ) ;
F_5 ( V_5 ) ;
V_7 = F_6 ( V_5 , NULL , 0 , NULL ) ;
if ( ! V_6 || ! V_7 )
goto V_13;
V_3 = F_3 ( L_3 , L_2 ) ;
if ( ! V_3 )
goto V_13;
V_8 = F_7 ( V_6 , V_7 , NULL , V_3 , V_10 ) ;
if ( ! V_8 )
goto V_13;
V_4 = F_3 ( L_4 , L_5 ) ;
if ( ! V_4 )
goto V_13;
if ( ! ( V_10 & V_12 ) )
F_5 ( V_3 ) ;
if ( ! F_8 ( V_4 , V_8 , V_3 , V_10 ) )
goto V_13;
V_9 = 0 ;
V_13:
if ( V_9 ) {
fprintf ( V_14 , L_6 ) ;
F_9 ( V_14 ) ;
}
if ( V_8 )
F_10 ( V_8 ) ;
if ( V_6 )
F_11 ( V_6 ) ;
if ( V_7 )
F_12 ( V_7 ) ;
if ( V_3 )
F_13 ( V_3 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
if ( V_5 )
F_13 ( V_5 ) ;
return V_9 ;
}
