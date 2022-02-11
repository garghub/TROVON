int MAIN ( int V_1 , char * * V_2 )
{
T_1 V_3 ;
#ifndef F_1
T_2 * V_4 = NULL ;
#endif
T_3 * V_5 = NULL ;
int V_6 = 1 , V_7 = V_8 ;
int V_9 = 2 ;
char * V_10 = NULL ;
char * V_11 = NULL ;
#ifndef F_1
char * V_12 = NULL ;
#endif
T_4 * V_13 = NULL ;
F_2 () ;
F_3 ( & V_3 , V_14 , V_15 ) ;
if ( V_15 == NULL )
if ( ( V_15 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_15 , V_16 , V_17 | V_18 ) ;
if ( ! F_7 ( V_15 , NULL ) )
goto V_19;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_9 = 2 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_9 = 5 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_12 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_20;
V_11 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_6 , & V_7 ) == 0 ) || ( V_7 < 0 ) ) )
{
V_20:
F_8 ( V_15 , L_7 ) ;
F_8 ( V_15 , L_8 ) ;
F_8 ( V_15 , L_9 ) ;
F_8 ( V_15 , L_10 ) ;
#ifndef F_1
F_8 ( V_15 , L_11 ) ;
#endif
F_8 ( V_15 , L_12 , V_21 , V_21 ) ;
F_8 ( V_15 , L_13 ) ;
F_8 ( V_15 , L_14 ) ;
goto V_19;
}
#ifndef F_1
V_4 = F_9 ( V_15 , V_12 , 0 ) ;
#endif
V_13 = F_4 ( F_5 () ) ;
if ( V_13 == NULL )
{
F_10 ( V_15 ) ;
goto V_19;
}
if ( V_10 == NULL )
{
F_6 ( V_13 , stdout , V_17 ) ;
#ifdef F_11
{
T_4 * V_22 = F_4 ( F_12 () ) ;
V_13 = F_13 ( V_22 , V_13 ) ;
}
#endif
}
else
{
if ( F_14 ( V_13 , V_10 ) <= 0 )
{
perror ( V_10 ) ;
goto V_19;
}
}
if ( ! F_15 ( NULL , V_15 , 1 ) && V_11 == NULL )
{
F_8 ( V_15 , L_15 ) ;
}
if ( V_11 != NULL )
F_8 ( V_15 , L_16 ,
F_16 ( V_11 ) ) ;
F_8 ( V_15 , L_17 , V_7 , V_9 ) ;
F_8 ( V_15 , L_18 ) ;
if( ( ( V_5 = F_17 () ) == NULL ) || ! F_18 ( V_5 , V_7 , V_9 , & V_3 ) )
goto V_19;
F_19 ( NULL , V_15 ) ;
if ( ! F_20 ( V_13 , V_5 ) )
goto V_19;
V_6 = 0 ;
V_19:
if ( V_6 != 0 )
F_10 ( V_15 ) ;
if ( V_13 != NULL ) F_21 ( V_13 ) ;
if ( V_5 != NULL ) F_22 ( V_5 ) ;
F_23 () ;
F_24 ( V_6 ) ;
}
static int T_5 V_14 ( int V_23 , int V_24 , T_1 * V_3 )
{
char V_25 = '*' ;
if ( V_23 == 0 ) V_25 = '.' ;
if ( V_23 == 1 ) V_25 = '+' ;
if ( V_23 == 2 ) V_25 = '*' ;
if ( V_23 == 3 ) V_25 = '\n' ;
F_25 ( V_3 -> V_26 , & V_25 , 1 ) ;
( void ) F_26 ( V_3 -> V_26 ) ;
#ifdef F_27
V_23 = V_24 ;
#endif
return 1 ;
}
