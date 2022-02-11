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
F_6 ( stdout , V_4 ) ;
F_7 ( V_4 ) ;
F_8 ( V_5 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
return ( 0 ) ;
}
static void F_13 ( int V_10 , int V_11 , void * V_12 )
{
char V_13 = 'B' ;
if ( V_10 == 0 ) V_13 = '.' ;
if ( V_10 == 1 ) V_13 = '+' ;
if ( V_10 == 2 ) V_13 = '*' ;
if ( V_10 == 3 ) V_13 = '\n' ;
fputc ( V_13 , V_7 ) ;
}
int F_3 ( T_2 * * V_4 , T_3 * * V_14 , int V_15 , int V_16 , int V_17 )
{
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_9 ;
T_5 * V_20 = NULL ;
F_14 ( V_21 ) * V_22 = NULL ;
if ( ( V_19 = F_15 () ) == NULL )
goto V_23;
if ( ( V_18 = F_16 () ) == NULL )
goto V_23;
V_9 = F_17 ( V_15 , V_24 , F_13 , NULL ) ;
if ( ! F_18 ( V_19 , V_9 ) )
goto V_23;
V_9 = NULL ;
F_19 ( V_18 , V_19 ) ;
V_20 = F_20 ( V_18 ) ;
F_21 ( V_20 , L_1 ,
V_25 , L_2 , - 1 , - 1 , 0 ) ;
F_21 ( V_20 , L_3 ,
V_25 , L_4 , - 1 , - 1 , 0 ) ;
#ifdef F_22
V_22 = F_23 () ;
F_24 ( V_22 , V_26 , L_5 ) ;
F_24 ( V_22 , V_27 , L_6 ) ;
F_24 ( V_22 , V_28 , L_7 ) ;
#ifdef F_25
{
int V_29 ;
V_29 = F_26 ( L_8 , L_9 , L_10 ) ;
F_27 ( V_29 , V_30 ) ;
F_24 ( V_18 , V_29 , L_11 ) ;
}
#endif
F_28 ( V_18 , V_22 ) ;
F_29 ( V_22 , V_31 ) ;
#endif
if ( ! F_30 ( V_18 , V_19 , F_31 () ) )
goto V_23;
* V_4 = V_18 ;
* V_14 = V_19 ;
return ( 1 ) ;
V_23:
return ( 0 ) ;
}
