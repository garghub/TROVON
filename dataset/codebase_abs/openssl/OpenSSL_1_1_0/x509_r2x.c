T_1 * F_1 ( T_2 * V_1 , int V_2 , T_3 * V_3 )
{
T_1 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_5 * V_6 ;
T_3 * V_7 = NULL ;
if ( ( V_4 = F_2 () ) == NULL ) {
F_3 ( V_8 , V_9 ) ;
return NULL ;
}
V_5 = & V_4 -> V_10 ;
if ( F_4 ( V_1 -> V_11 . V_12 ) != 0 ) {
if ( ( V_5 -> V_13 = F_5 () ) == NULL )
goto V_14;
if ( ! F_6 ( V_5 -> V_13 , 2 ) )
goto V_14;
}
V_6 = F_7 ( V_1 ) ;
if ( F_8 ( V_4 , V_6 ) == 0 )
goto V_14;
if ( F_9 ( V_4 , V_6 ) == 0 )
goto V_14;
if ( F_10 ( V_5 -> V_15 . V_16 , 0 ) == NULL )
goto V_14;
if ( F_10 ( V_5 -> V_15 . V_17 , ( long ) 60 * 60 * 24 * V_2 ) ==
NULL )
goto V_14;
V_7 = F_11 ( V_1 ) ;
if ( V_7 == NULL || ! F_12 ( V_4 , V_7 ) )
goto V_14;
if ( ! F_13 ( V_4 , V_3 , F_14 () ) )
goto V_14;
return V_4 ;
V_14:
F_15 ( V_4 ) ;
return NULL ;
}
