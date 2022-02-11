main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
T_3 * V_1 ;
T_4 * V_2 ;
T_5 * V_3 ;
T_5 * V_4 ;
T_6 * V_5 ;
T_7 * V_6 ;
T_7 * V_7 , * V_8 ;
char V_9 [ 1024 * 4 ] ;
int V_10 , V_11 ;
int V_12 = 0 ;
F_1 ( F_2 () ) ;
F_1 ( F_3 () ) ;
F_1 ( F_4 () ) ;
F_1 ( F_5 () ) ;
V_7 = F_6 ( F_7 () ) ;
V_13:
if ( T_1 > 1 )
{
if ( strcmp ( T_2 [ 1 ] , L_1 ) == 0 )
{
V_12 = 1 ;
T_2 ++ ; T_1 -- ;
goto V_13;
}
if ( ! F_8 ( V_7 , T_2 [ 1 ] ) )
goto V_14;
}
else
F_9 ( V_7 , V_15 , V_16 ) ;
if ( ( V_6 = F_10 ( L_2 , L_3 ) ) == NULL ) goto V_14;
if ( ( V_1 = F_11 ( V_6 , NULL , NULL ) ) == NULL ) goto V_14;
F_12 ( V_6 ) ;
if ( ( V_2 = F_13 ( V_6 , NULL , NULL ) ) == NULL ) goto V_14;
F_14 ( V_6 ) ;
V_3 = F_15 () ;
F_16 ( V_3 , V_17 ) ;
V_5 = F_17 ( V_3 , V_1 , V_2 , F_4 () ) ;
if ( V_5 == NULL ) goto V_14;
F_18 ( V_5 , V_18 , V_19 ,
F_19 ( V_20 ) ) ;
F_20 ( V_3 , V_1 ) ;
F_21 ( V_3 , V_20 ) ;
if ( ! V_12 )
F_22 ( V_3 , 1 ) ;
if ( ( V_8 = F_23 ( V_3 , NULL ) ) == NULL ) goto V_14;
for (; ; )
{
V_10 = F_24 ( V_7 , V_9 , sizeof( V_9 ) ) ;
if ( V_10 <= 0 ) break;
F_25 ( V_8 , V_9 , V_10 ) ;
}
if ( ! F_26 ( V_3 , V_8 ) ) goto V_14;
F_14 ( V_8 ) ;
F_27 ( stdout , V_3 ) ;
F_28 ( V_3 ) ;
exit ( 0 ) ;
V_14:
F_29 () ;
F_30 ( V_21 ) ;
exit ( 1 ) ;
}
