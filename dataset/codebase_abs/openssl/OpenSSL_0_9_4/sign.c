int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
T_3 * V_1 ;
T_4 * V_2 ;
T_5 * V_3 ;
T_6 * V_4 ;
T_7 * V_5 ;
T_7 * V_6 , * V_7 ;
char V_8 [ 1024 * 4 ] ;
int V_9 ;
int V_10 = 0 ;
F_1 ( F_2 () ) ;
F_1 ( F_3 () ) ;
F_1 ( F_4 () ) ;
F_1 ( F_5 () ) ;
V_6 = F_6 ( F_7 () ) ;
V_11:
if ( T_1 > 1 )
{
if ( strcmp ( T_2 [ 1 ] , L_1 ) == 0 )
{
V_10 = 1 ;
T_2 ++ ; T_1 -- ;
goto V_11;
}
if ( ! F_8 ( V_6 , T_2 [ 1 ] ) )
goto V_12;
}
else
F_9 ( V_6 , V_13 , V_14 ) ;
if ( ( V_5 = F_10 ( L_2 , L_3 ) ) == NULL ) goto V_12;
if ( ( V_1 = F_11 ( V_5 , NULL , NULL ) ) == NULL ) goto V_12;
F_12 ( V_5 ) ;
if ( ( V_2 = F_13 ( V_5 , NULL , NULL ) ) == NULL ) goto V_12;
F_14 ( V_5 ) ;
V_3 = F_15 () ;
F_16 ( V_3 , V_15 ) ;
V_4 = F_17 ( V_3 , V_1 , V_2 , F_4 () ) ;
if ( V_4 == NULL ) goto V_12;
F_18 ( V_4 , V_16 , V_17 ,
F_19 ( V_18 ) ) ;
F_20 ( V_3 , V_1 ) ;
F_21 ( V_3 , V_18 ) ;
if ( ! V_10 )
F_22 ( V_3 , 1 ) ;
if ( ( V_7 = F_23 ( V_3 , NULL ) ) == NULL ) goto V_12;
for (; ; )
{
V_9 = F_24 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 <= 0 ) break;
F_25 ( V_7 , V_8 , V_9 ) ;
}
if ( ! F_26 ( V_3 , V_7 ) ) goto V_12;
F_14 ( V_7 ) ;
F_27 ( stdout , V_3 ) ;
F_28 ( V_3 ) ;
exit ( 0 ) ;
V_12:
F_29 () ;
F_30 ( V_19 ) ;
exit ( 1 ) ;
}
