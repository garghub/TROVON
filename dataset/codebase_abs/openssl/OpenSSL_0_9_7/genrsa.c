int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
T_2 * V_5 = NULL ;
int V_6 , V_7 = V_8 ;
long V_9 ;
const T_3 * V_10 = NULL ;
unsigned long V_11 = V_12 ;
char * V_13 = NULL ;
char * V_14 = NULL , * V_15 = NULL ;
char * V_16 = NULL ;
char * V_17 = NULL ;
T_4 * V_18 = NULL ;
F_1 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_19 , V_20 , V_21 | V_22 ) ;
if ( ! F_5 ( V_19 , NULL ) )
goto V_23;
if ( ( V_18 = F_2 ( F_3 () ) ) == NULL )
{
F_6 ( V_19 , L_1 ) ;
goto V_23;
}
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_11 = 3 ;
else if ( strcmp ( * V_2 , L_4 ) == 0 || strcmp ( * V_2 , L_5 ) == 0 )
V_11 = V_12 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_17 = * ( ++ V_2 ) ;
}
#ifndef F_7
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_10 = F_8 () ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_10 = F_9 () ;
#endif
#ifndef F_10
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_10 = F_11 () ;
#endif
#ifndef F_12
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_10 = F_13 () ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_10 = F_14 () ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_10 = F_15 () ;
#endif
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_14 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_15 , & V_7 ) == 0 ) || ( V_7 < 0 ) ) )
{
V_24:
F_6 ( V_19 , L_16 ) ;
F_6 ( V_19 , L_17 ) ;
F_6 ( V_19 , L_18 ) ;
#ifndef F_10
F_6 ( V_19 , L_19 ) ;
#endif
#ifndef F_12
F_6 ( V_19 , L_20 ) ;
F_6 ( V_19 , L_21 ) ;
#endif
F_6 ( V_19 , L_22 ) ;
F_6 ( V_19 , L_23 ) ;
F_6 ( V_19 , L_24 ) ;
F_6 ( V_19 , L_25 ) ;
F_6 ( V_19 , L_26 ) ;
F_6 ( V_19 , L_27 , V_25 , V_25 ) ;
F_6 ( V_19 , L_28 ) ;
F_6 ( V_19 , L_29 ) ;
goto V_23;
}
F_16 () ;
if( ! F_17 ( V_19 , NULL , V_14 , NULL , & V_15 ) ) {
F_6 ( V_19 , L_30 ) ;
goto V_23;
}
V_3 = F_18 ( V_19 , V_16 , 0 ) ;
if ( V_13 == NULL )
{
F_4 ( V_18 , stdout , V_21 ) ;
#ifdef F_19
{
T_4 * V_26 = F_2 ( F_20 () ) ;
V_18 = F_21 ( V_26 , V_18 ) ;
}
#endif
}
else
{
if ( F_22 ( V_18 , V_13 ) <= 0 )
{
perror ( V_13 ) ;
goto V_23;
}
}
if ( ! F_23 ( NULL , V_19 , 1 ) && V_17 == NULL
&& ! F_24 () )
{
F_6 ( V_19 , L_31 ) ;
}
if ( V_17 != NULL )
F_6 ( V_19 , L_32 ,
F_25 ( V_17 ) ) ;
F_6 ( V_19 , L_33 ,
V_7 ) ;
V_5 = F_26 ( V_7 , V_11 , V_27 , V_19 ) ;
F_27 ( NULL , V_19 ) ;
if ( V_5 == NULL ) goto V_23;
V_9 = 0L ;
for ( V_6 = 0 ; V_6 < V_5 -> V_3 -> V_28 ; V_6 ++ )
{
#ifndef F_28
V_9 <<= V_29 ;
V_9 <<= V_29 ;
#endif
V_9 += V_5 -> V_3 -> V_30 [ V_6 ] ;
}
F_6 ( V_19 , L_34 , V_9 , V_9 ) ;
{
T_5 V_31 ;
V_31 . V_32 = V_15 ;
V_31 . V_33 = V_13 ;
if ( ! F_29 ( V_18 , V_5 , V_10 , NULL , 0 ,
( V_34 * ) V_35 , & V_31 ) )
goto V_23;
}
V_4 = 0 ;
V_23:
if ( V_5 != NULL ) F_30 ( V_5 ) ;
if ( V_18 != NULL ) F_31 ( V_18 ) ;
if( V_15 ) F_32 ( V_15 ) ;
if ( V_4 != 0 )
F_33 ( V_19 ) ;
F_34 () ;
F_35 ( V_4 ) ;
}
static void T_6 V_27 ( int V_36 , int V_37 , void * V_38 )
{
char V_39 = '*' ;
if ( V_36 == 0 ) V_39 = '.' ;
if ( V_36 == 1 ) V_39 = '+' ;
if ( V_36 == 2 ) V_39 = '*' ;
if ( V_36 == 3 ) V_39 = '\n' ;
F_36 ( ( T_4 * ) V_38 , & V_39 , 1 ) ;
( void ) F_37 ( ( T_4 * ) V_38 ) ;
#ifdef F_38
V_36 = V_37 ;
#endif
}
