int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
int V_5 , V_6 = V_7 ;
long V_8 ;
T_2 * V_9 = NULL ;
unsigned long V_10 = V_11 ;
char * V_12 = NULL ;
char * V_13 = NULL , * V_14 = NULL ;
char * V_15 = NULL ;
T_3 * V_16 = NULL ;
F_1 () ;
if ( V_17 == NULL )
if ( ( V_17 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_17 , V_18 , V_19 | V_20 ) ;
if ( ( V_16 = F_2 ( F_3 () ) ) == NULL )
{
F_5 ( V_17 , L_1 ) ;
goto V_21;
}
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_10 = 3 ;
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_10 = V_11 ;
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_15 = * ( ++ V_2 ) ;
}
#ifndef F_6
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_9 = F_7 () ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_9 = F_8 () ;
#endif
#ifndef F_9
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_9 = F_10 () ;
#endif
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_13 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_10 , & V_6 ) == 0 ) || ( V_6 < 0 ) ) )
{
V_22:
F_5 ( V_17 , L_11 ) ;
F_5 ( V_17 , L_12 ) ;
F_5 ( V_17 , L_13 ) ;
#ifndef F_9
F_5 ( V_17 , L_14 ) ;
#endif
F_5 ( V_17 , L_15 ) ;
F_5 ( V_17 , L_16 ) ;
F_5 ( V_17 , L_17 ) ;
F_5 ( V_17 , L_18 ) ;
F_5 ( V_17 , L_19 ) ;
F_5 ( V_17 , L_20 ) ;
F_5 ( V_17 , L_21 ) ;
goto V_21;
}
F_11 () ;
if( ! F_12 ( V_17 , NULL , V_13 , NULL , & V_14 ) ) {
F_5 ( V_17 , L_22 ) ;
goto V_21;
}
if ( V_12 == NULL )
F_4 ( V_16 , stdout , V_19 ) ;
else
{
if ( F_13 ( V_16 , V_12 ) <= 0 )
{
perror ( V_12 ) ;
goto V_21;
}
}
if ( ! F_14 ( NULL , V_17 , 1 ) && V_15 == NULL )
{
F_5 ( V_17 , L_23 ) ;
}
if ( V_15 != NULL )
F_5 ( V_17 , L_24 ,
F_15 ( V_15 ) ) ;
F_5 ( V_17 , L_25 ,
V_6 ) ;
V_4 = F_16 ( V_6 , V_10 , V_23 , V_17 ) ;
F_17 ( NULL , V_17 ) ;
if ( V_4 == NULL ) goto V_21;
V_8 = 0L ;
for ( V_5 = 0 ; V_5 < V_4 -> V_24 -> V_25 ; V_5 ++ )
{
#ifndef F_18
V_8 <<= V_26 ;
V_8 <<= V_26 ;
#endif
V_8 += V_4 -> V_24 -> V_27 [ V_5 ] ;
}
F_5 ( V_17 , L_26 , V_8 , V_8 ) ;
if ( ! F_19 ( V_16 , V_4 , V_9 , NULL , 0 , NULL , V_14 ) )
goto V_21;
V_3 = 0 ;
V_21:
if ( V_4 != NULL ) F_20 ( V_4 ) ;
if ( V_16 != NULL ) F_21 ( V_16 ) ;
if( V_14 ) Free ( V_14 ) ;
if ( V_3 != 0 )
F_22 ( V_17 ) ;
EXIT ( V_3 ) ;
}
static void T_4 V_23 ( int V_28 , int V_29 , void * V_30 )
{
char V_31 = '*' ;
if ( V_28 == 0 ) V_31 = '.' ;
if ( V_28 == 1 ) V_31 = '+' ;
if ( V_28 == 2 ) V_31 = '*' ;
if ( V_28 == 3 ) V_31 = '\n' ;
F_23 ( ( T_3 * ) V_30 , & V_31 , 1 ) ;
( void ) F_24 ( ( T_3 * ) V_30 ) ;
#ifdef F_25
V_28 = V_29 ;
#endif
}
