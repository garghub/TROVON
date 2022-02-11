int MAIN ( int V_1 , char * * V_2 )
{
char V_3 [ 200 ] ;
T_1 * V_4 = NULL ;
int V_5 = 1 , V_6 = V_7 ;
int V_8 = 2 ;
char * V_9 = NULL ;
char * V_10 = NULL , * V_11 ;
T_2 * V_12 = NULL ;
F_1 () ;
if ( V_13 == NULL )
if ( ( V_13 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_13 , V_14 , V_15 | V_16 ) ;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_9 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_8 = 2 ;
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_8 = 5 ;
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_10 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_5 , & V_6 ) == 0 ) || ( V_6 < 0 ) ) )
{
V_17:
F_5 ( V_13 , L_6 ) ;
F_5 ( V_13 , L_7 ) ;
F_5 ( V_13 , L_8 ) ;
F_5 ( V_13 , L_9 ) ;
F_5 ( V_13 , L_10 ) ;
F_5 ( V_13 , L_11 ) ;
F_5 ( V_13 , L_12 ) ;
goto V_18;
}
V_12 = F_2 ( F_3 () ) ;
if ( V_12 == NULL )
{
F_6 ( V_13 ) ;
goto V_18;
}
if ( V_9 == NULL )
F_4 ( V_12 , stdout , V_15 ) ;
else
{
if ( F_7 ( V_12 , V_9 ) <= 0 )
{
perror ( V_9 ) ;
goto V_18;
}
}
V_11 = F_8 ( V_3 , 200 ) ;
if ( ( V_11 == NULL ) || ! F_9 ( V_11 , 1024L * 1024L ) )
F_5 ( V_13 , L_13 ) ;
if ( V_10 == NULL )
F_5 ( V_13 , L_14 ) ;
else
{
F_5 ( V_13 , L_15 ,
F_10 ( V_10 ) ) ;
}
F_5 ( V_13 , L_16 , V_6 , V_8 ) ;
F_5 ( V_13 , L_17 ) ;
V_4 = F_11 ( V_6 , V_8 , V_19 , ( char * ) V_13 ) ;
if ( V_4 == NULL ) goto V_18;
if ( V_11 == NULL )
F_5 ( V_13 , L_18 ) ;
else
F_12 ( V_11 ) ;
if ( ! F_13 ( V_12 , V_4 ) )
goto V_18;
V_5 = 0 ;
V_18:
if ( V_5 != 0 )
F_6 ( V_13 ) ;
if ( V_12 != NULL ) F_14 ( V_12 ) ;
if ( V_4 != NULL ) F_15 ( V_4 ) ;
EXIT ( V_5 ) ;
}
static void T_3 V_19 ( int V_20 , int V_21 , char * V_22 )
{
char V_23 = '*' ;
if ( V_20 == 0 ) V_23 = '.' ;
if ( V_20 == 1 ) V_23 = '+' ;
if ( V_20 == 2 ) V_23 = '*' ;
if ( V_20 == 3 ) V_23 = '\n' ;
F_16 ( ( T_2 * ) V_22 , & V_23 , 1 ) ;
F_17 ( ( T_2 * ) V_22 ) ;
#ifdef F_18
V_20 = V_21 ;
#endif
}
static long F_10 ( char * V_24 )
{
char * V_20 , * V_21 ;
int V_25 ;
long V_26 = 0 ;
for (; ; )
{
V_25 = 0 ;
for ( V_20 = V_24 ; ( ( * V_20 != '\0' ) && ( * V_20 != V_27 ) ) ; V_20 ++ ) ;
if ( * V_20 == '\0' ) V_25 = 1 ;
* V_20 = '\0' ;
V_21 = V_24 ;
V_24 = V_20 + 1 ;
if ( * V_21 == '\0' ) break;
V_26 += F_9 ( V_21 , 1 ) ;
if ( V_25 ) break;
}
return ( V_26 ) ;
}
