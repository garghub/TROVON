int main ()
{
T_1 * V_1 ;
T_2 * V_2 = NULL ;
T_3 * V_3 = NULL ;
F_1 ( V_4 ) ;
F_2 () ;
if ( ( V_1 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_1 , V_5 , V_6 ) ;
F_6 ( & V_2 , & V_3 , 512 , 0 , 365 ) ;
F_7 ( stdout , V_3 -> V_3 . V_7 , 0 ) ;
F_8 ( stdout , V_2 ) ;
F_9 ( stdout , V_3 -> V_3 . V_7 , NULL , NULL , 0 , NULL ) ;
F_10 ( stdout , V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_3 ) ;
F_13 ( V_1 ) ;
F_14 () ;
F_15 ( V_1 ) ;
return ( 0 ) ;
}
static void T_4 F_16 ( T_5 , T_6 )
int T_5 ;
int T_6 ;
{
char V_8 = 'B' ;
if ( T_5 == 0 ) V_8 = '.' ;
if ( T_5 == 1 ) V_8 = '+' ;
if ( T_5 == 2 ) V_8 = '*' ;
if ( T_5 == 3 ) V_8 = '\n' ;
fputc ( V_8 , V_5 ) ;
}
int F_6 ( T_7 , T_8 , T_9 , T_10 , T_11 )
T_2 * * T_7 ;
T_3 * * T_8 ;
int T_9 ;
int T_10 ;
int T_11 ;
{
T_2 * V_9 ;
T_3 * V_10 ;
T_12 * V_7 ;
char * V_11 ;
T_13 * V_12 = NULL ;
T_14 * V_13 = NULL ;
T_15 * V_14 = NULL ;
T_16 * V_15 = NULL ;
if ( ( T_8 == NULL ) || ( * T_8 == NULL ) )
{
if ( ( V_10 = F_17 () ) == NULL )
{
abort () ;
return ( 0 ) ;
}
}
else
V_10 = * T_8 ;
if ( ( T_7 == NULL ) || ( * T_7 == NULL ) )
{
if ( ( V_9 = F_18 () ) == NULL )
goto V_16;
}
else
V_9 = * T_7 ;
V_7 = F_19 ( T_9 , V_17 , F_16 ) ;
if ( ! F_20 ( V_10 , V_7 ) )
{
abort () ;
goto V_16;
}
V_7 = NULL ;
F_21 ( V_9 , 3 ) ;
F_22 ( F_23 ( V_9 ) , T_10 ) ;
F_24 ( F_25 ( V_9 ) , 0 ) ;
F_24 ( F_26 ( V_9 ) , ( long ) 60 * 60 * 24 * T_11 ) ;
F_27 ( V_9 , V_10 ) ;
V_12 = F_28 () ;
V_13 = F_29 ( NULL , V_18 ,
V_19 , L_1 , - 1 ) ;
F_30 ( V_12 , V_13 , 0 , 0 ) ;
F_29 ( & V_13 , V_20 ,
V_19 , L_2 , - 1 ) ;
F_30 ( V_12 , V_13 , 1 , 0 ) ;
F_31 ( V_13 ) ;
F_32 ( V_9 , V_12 ) ;
F_33 ( V_9 , V_12 ) ;
F_34 ( V_12 ) ;
V_15 = F_35 ( NULL , V_21 ,
L_3 , 1 ) ;
V_14 = F_36 ( NULL , V_22 , 0 , V_15 ) ;
F_37 ( V_9 , V_14 , - 1 ) ;
F_35 ( & V_15 , V_23 ,
L_4 , - 1 ) ;
F_36 ( & V_14 , V_24 , 0 , V_15 ) ;
F_37 ( V_9 , V_14 , - 1 ) ;
F_35 ( & V_15 , V_21 ,
L_5 , - 1 ) ;
F_36 ( & V_14 , V_25 , 0 , V_15 ) ;
F_37 ( V_9 , V_14 , - 1 ) ;
F_38 ( V_14 ) ;
F_39 ( V_15 ) ;
if ( ! F_40 ( V_9 , V_10 , F_41 () ) )
goto V_16;
* T_7 = V_9 ;
* T_8 = V_10 ;
return ( 1 ) ;
V_16:
return ( 0 ) ;
}
