int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 , V_5 = V_6 ;
int V_7 = 2 ;
char * V_8 = NULL ;
char * V_9 = NULL ;
T_2 * V_10 = NULL ;
F_1 () ;
if ( V_11 == NULL )
if ( ( V_11 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_11 , V_12 , V_13 | V_14 ) ;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_15;
V_8 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_7 = 2 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_7 = 5 ;
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_15;
V_9 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_5 , & V_5 ) == 0 ) || ( V_5 < 0 ) ) )
{
V_15:
F_5 ( V_11 , L_6 ) ;
F_5 ( V_11 , L_7 ) ;
F_5 ( V_11 , L_8 ) ;
F_5 ( V_11 , L_9 ) ;
F_5 ( V_11 , L_10 ) ;
F_5 ( V_11 , L_11 ) ;
F_5 ( V_11 , L_12 ) ;
goto V_16;
}
V_10 = F_2 ( F_3 () ) ;
if ( V_10 == NULL )
{
F_6 ( V_11 ) ;
goto V_16;
}
if ( V_8 == NULL )
F_4 ( V_10 , stdout , V_13 ) ;
else
{
if ( F_7 ( V_10 , V_8 ) <= 0 )
{
perror ( V_8 ) ;
goto V_16;
}
}
if ( ! F_8 ( NULL , V_11 , 1 ) && V_9 == NULL )
{
F_5 ( V_11 , L_13 ) ;
}
if ( V_9 != NULL )
F_5 ( V_11 , L_14 ,
F_9 ( V_9 ) ) ;
F_5 ( V_11 , L_15 , V_5 , V_7 ) ;
F_5 ( V_11 , L_16 ) ;
V_3 = F_10 ( V_5 , V_7 , V_17 , V_11 ) ;
if ( V_3 == NULL ) goto V_16;
F_11 ( NULL , V_11 ) ;
if ( ! F_12 ( V_10 , V_3 ) )
goto V_16;
V_4 = 0 ;
V_16:
if ( V_4 != 0 )
F_6 ( V_11 ) ;
if ( V_10 != NULL ) F_13 ( V_10 ) ;
if ( V_3 != NULL ) F_14 ( V_3 ) ;
EXIT ( V_4 ) ;
}
static void T_3 V_17 ( int V_18 , int V_19 , void * V_20 )
{
char V_21 = '*' ;
if ( V_18 == 0 ) V_21 = '.' ;
if ( V_18 == 1 ) V_21 = '+' ;
if ( V_18 == 2 ) V_21 = '*' ;
if ( V_18 == 3 ) V_21 = '\n' ;
F_15 ( ( T_2 * ) V_20 , & V_21 , 1 ) ;
( void ) F_16 ( ( T_2 * ) V_20 ) ;
#ifdef F_17
V_18 = V_19 ;
#endif
}
