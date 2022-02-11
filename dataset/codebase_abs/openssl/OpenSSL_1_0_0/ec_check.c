int F_1 ( const T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 0 ;
T_3 * V_4 ;
T_2 * V_5 = NULL ;
T_4 * V_6 = NULL ;
if ( V_2 == NULL )
{
V_2 = V_5 = F_2 () ;
if ( V_2 == NULL )
{
F_3 ( V_7 , V_8 ) ;
goto V_9;
}
}
F_4 ( V_2 ) ;
if ( ( V_4 = F_5 ( V_2 ) ) == NULL ) goto V_9;
if ( ! F_6 ( V_1 , V_2 ) )
{
F_3 ( V_7 , V_10 ) ;
goto V_9;
}
if ( V_1 -> V_11 == NULL )
{
F_3 ( V_7 , V_12 ) ;
goto V_9;
}
if ( ! F_7 ( V_1 , V_1 -> V_11 , V_2 ) )
{
F_3 ( V_7 , V_13 ) ;
goto V_9;
}
if ( ( V_6 = F_8 ( V_1 ) ) == NULL ) goto V_9;
if ( ! F_9 ( V_1 , V_4 , V_2 ) ) goto V_9;
if ( F_10 ( V_4 ) )
{
F_3 ( V_7 , V_14 ) ;
goto V_9;
}
if ( ! F_11 ( V_1 , V_6 , V_4 , NULL , NULL , V_2 ) ) goto V_9;
if ( ! F_12 ( V_1 , V_6 ) )
{
F_3 ( V_7 , V_15 ) ;
goto V_9;
}
V_3 = 1 ;
V_9:
if ( V_2 != NULL )
F_13 ( V_2 ) ;
if ( V_5 != NULL )
F_14 ( V_5 ) ;
if ( V_6 )
F_15 ( V_6 ) ;
return V_3 ;
}
