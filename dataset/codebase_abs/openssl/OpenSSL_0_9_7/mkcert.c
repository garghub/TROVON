int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL ;
F_1 ( V_6 ) ;
V_3 = F_2 ( V_7 , V_8 ) ;
F_3 ( & V_4 , & V_5 , 512 , 0 , 365 ) ;
F_4 ( stdout , V_5 -> V_5 . V_9 , 0 ) ;
F_5 ( stdout , V_4 ) ;
F_6 ( stdout , V_5 , NULL , NULL , 0 , NULL , NULL ) ;
F_7 ( stdout , V_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_5 ) ;
F_10 () ;
F_11 () ;
F_12 ( V_3 ) ;
F_13 ( V_3 ) ;
return ( 0 ) ;
}
static void F_14 ( int V_10 , int V_11 , void * V_12 )
{
char V_13 = 'B' ;
if ( V_10 == 0 ) V_13 = '.' ;
if ( V_10 == 1 ) V_13 = '+' ;
if ( V_10 == 2 ) V_13 = '*' ;
if ( V_10 == 3 ) V_13 = '\n' ;
fputc ( V_13 , V_7 ) ;
}
int F_3 ( T_2 * * V_14 , T_3 * * V_15 , int V_16 , int V_17 , int V_18 )
{
T_2 * V_19 ;
T_3 * V_20 ;
T_4 * V_9 ;
T_5 * V_21 = NULL ;
if ( ( V_15 == NULL ) || ( * V_15 == NULL ) )
{
if ( ( V_20 = F_15 () ) == NULL )
{
abort () ;
return ( 0 ) ;
}
}
else
V_20 = * V_15 ;
if ( ( V_14 == NULL ) || ( * V_14 == NULL ) )
{
if ( ( V_19 = F_16 () ) == NULL )
goto V_22;
}
else
V_19 = * V_14 ;
V_9 = F_17 ( V_16 , V_23 , F_14 , NULL ) ;
if ( ! F_18 ( V_20 , V_9 ) )
{
abort () ;
goto V_22;
}
V_9 = NULL ;
F_19 ( V_19 , 2 ) ;
F_20 ( F_21 ( V_19 ) , V_17 ) ;
F_22 ( F_23 ( V_19 ) , 0 ) ;
F_22 ( F_24 ( V_19 ) , ( long ) 60 * 60 * 24 * V_18 ) ;
F_25 ( V_19 , V_20 ) ;
V_21 = F_26 ( V_19 ) ;
F_27 ( V_21 , L_1 ,
V_24 , L_2 , - 1 , - 1 , 0 ) ;
F_27 ( V_21 , L_3 ,
V_24 , L_4 , - 1 , - 1 , 0 ) ;
F_28 ( V_19 , V_21 ) ;
F_29 ( V_19 , V_25 , L_5 ) ;
F_29 ( V_19 , V_26 , L_6 ) ;
F_29 ( V_19 , V_27 , L_7 ) ;
F_29 ( V_19 , V_28 , L_8 ) ;
F_29 ( V_19 , V_29 , L_9 ) ;
#ifdef F_30
{
int V_30 ;
V_30 = F_31 ( L_10 , L_11 , L_12 ) ;
F_32 ( V_30 , V_29 ) ;
F_29 ( V_19 , V_30 , L_13 ) ;
}
#endif
if ( ! F_33 ( V_19 , V_20 , F_34 () ) )
goto V_22;
* V_14 = V_19 ;
* V_15 = V_20 ;
return ( 1 ) ;
V_22:
return ( 0 ) ;
}
int F_29 ( T_2 * V_31 , int V_30 , char * V_32 )
{
T_6 * V_33 ;
T_7 V_34 ;
F_35 ( & V_34 ) ;
F_36 ( & V_34 , V_31 , V_31 , NULL , NULL , 0 ) ;
V_33 = F_37 ( NULL , & V_34 , V_30 , V_32 ) ;
if ( ! V_33 )
return 0 ;
F_38 ( V_31 , V_33 , - 1 ) ;
F_39 ( V_33 ) ;
return 1 ;
}
