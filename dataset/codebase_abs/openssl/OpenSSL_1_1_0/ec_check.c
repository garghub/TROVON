int F_1 ( const T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 0 ;
const T_3 * V_4 ;
T_2 * V_5 = NULL ;
T_4 * V_6 = NULL ;
if ( ( V_1 -> V_7 -> V_8 & V_9 ) != 0 )
return 1 ;
if ( V_2 == NULL ) {
V_2 = V_5 = F_2 () ;
if ( V_2 == NULL ) {
F_3 ( V_10 , V_11 ) ;
goto V_12;
}
}
if ( ! F_4 ( V_1 , V_2 ) ) {
F_3 ( V_10 , V_13 ) ;
goto V_12;
}
if ( V_1 -> V_14 == NULL ) {
F_3 ( V_10 , V_15 ) ;
goto V_12;
}
if ( F_5 ( V_1 , V_1 -> V_14 , V_2 ) <= 0 ) {
F_3 ( V_10 , V_16 ) ;
goto V_12;
}
if ( ( V_6 = F_6 ( V_1 ) ) == NULL )
goto V_12;
V_4 = F_7 ( V_1 ) ;
if ( V_4 == NULL )
goto V_12;
if ( F_8 ( V_4 ) ) {
F_3 ( V_10 , V_17 ) ;
goto V_12;
}
if ( ! F_9 ( V_1 , V_6 , V_4 , NULL , NULL , V_2 ) )
goto V_12;
if ( ! F_10 ( V_1 , V_6 ) ) {
F_3 ( V_10 , V_18 ) ;
goto V_12;
}
V_3 = 1 ;
V_12:
F_11 ( V_5 ) ;
F_12 ( V_6 ) ;
return V_3 ;
}
