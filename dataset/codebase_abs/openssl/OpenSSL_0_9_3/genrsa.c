int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
char V_4 [ 200 ] ;
T_1 * V_5 = NULL ;
int V_6 , V_7 = V_8 ;
long V_9 = 0 , V_10 ;
T_2 * V_11 = NULL ;
unsigned long V_12 = V_13 ;
char * V_14 = NULL ;
char * V_15 = NULL , * V_16 ;
T_3 * V_17 = NULL ;
F_1 () ;
if ( V_18 == NULL )
if ( ( V_18 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_18 , V_19 , V_20 | V_21 ) ;
if ( ( V_17 = F_2 ( F_3 () ) ) == NULL )
{
F_5 ( V_18 , L_1 ) ;
goto V_22;
}
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_12 = 3 ;
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_12 = V_13 ;
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_15 = * ( ++ V_2 ) ;
}
#ifndef F_6
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_11 = F_7 () ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_11 = F_8 () ;
#endif
#ifndef F_9
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_11 = F_10 () ;
#endif
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_9 , & V_7 ) == 0 ) || ( V_7 < 0 ) ) )
{
V_23:
F_5 ( V_18 , L_10 ) ;
F_5 ( V_18 , L_11 ) ;
F_5 ( V_18 , L_12 ) ;
#ifndef F_9
F_5 ( V_18 , L_13 ) ;
#endif
F_5 ( V_18 , L_14 ) ;
F_5 ( V_18 , L_15 ) ;
F_5 ( V_18 , L_16 ) ;
F_5 ( V_18 , L_17 ) ;
F_5 ( V_18 , L_18 ) ;
F_5 ( V_18 , L_19 ) ;
goto V_22;
}
F_11 () ;
if ( V_14 == NULL )
F_4 ( V_17 , stdout , V_20 ) ;
else
{
if ( F_12 ( V_17 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_22;
}
}
#ifdef F_13
F_5 ( V_18 , L_20 ) ;
F_14 ( V_18 ) ;
F_15 () ;
F_5 ( V_18 , L_21 ) ;
#endif
V_16 = F_16 ( V_4 , 200 ) ;
if ( ( V_16 == NULL ) ||
! ( V_9 = ( long ) F_17 ( V_16 , 1024L * 1024L ) ) )
{
F_5 ( V_18 , L_22 ) ;
}
if ( V_15 == NULL )
{
if ( V_9 == 0 )
{
F_5 ( V_18 , L_23 ) ;
}
}
else
{
V_9 += F_18 ( V_15 ) ;
}
if ( V_9 != 0 )
F_5 ( V_18 , L_24 , V_9 ) ;
F_5 ( V_18 , L_25 ,
V_7 ) ;
V_5 = F_19 ( V_7 , V_12 , V_24 , ( char * ) V_18 ) ;
if ( V_16 == NULL )
F_5 ( V_18 , L_26 ) ;
else
F_20 ( V_16 ) ;
if ( V_5 == NULL ) goto V_22;
V_10 = 0L ;
for ( V_6 = 0 ; V_6 < V_5 -> V_25 -> V_26 ; V_6 ++ )
{
#ifndef F_21
V_10 <<= V_27 ;
V_10 <<= V_27 ;
#endif
V_10 += V_5 -> V_25 -> V_28 [ V_6 ] ;
}
F_5 ( V_18 , L_27 , V_10 , V_10 ) ;
if ( ! F_22 ( V_17 , V_5 , V_11 , NULL , 0 , NULL ) )
goto V_22;
V_3 = 0 ;
V_22:
if ( V_5 != NULL ) F_23 ( V_5 ) ;
if ( V_17 != NULL ) F_24 ( V_17 ) ;
if ( V_3 != 0 )
F_25 ( V_18 ) ;
EXIT ( V_3 ) ;
}
static void T_4 V_24 ( int V_29 , int V_30 , char * V_31 )
{
char V_32 = '*' ;
if ( V_29 == 0 ) V_32 = '.' ;
if ( V_29 == 1 ) V_32 = '+' ;
if ( V_29 == 2 ) V_32 = '*' ;
if ( V_29 == 3 ) V_32 = '\n' ;
F_26 ( ( T_3 * ) V_31 , & V_32 , 1 ) ;
F_14 ( ( T_3 * ) V_31 ) ;
#ifdef F_27
V_29 = V_30 ;
#endif
}
static long F_18 ( char * V_33 )
{
char * V_29 , * V_30 ;
int V_34 ;
long V_35 = 0 ;
for (; ; )
{
V_34 = 0 ;
for ( V_29 = V_33 ; ( ( * V_29 != '\0' ) && ( * V_29 != V_36 ) ) ; V_29 ++ ) ;
if ( * V_29 == '\0' ) V_34 = 1 ;
* V_29 = '\0' ;
V_30 = V_33 ;
V_33 = V_29 + 1 ;
if ( * V_30 == '\0' ) break;
V_35 += F_17 ( V_30 , 1024L * 1024L ) ;
if ( V_34 ) break;
}
return ( V_35 ) ;
}
