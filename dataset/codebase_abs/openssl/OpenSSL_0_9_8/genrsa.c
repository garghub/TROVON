int MAIN ( int V_1 , char * * V_2 )
{
T_1 V_3 ;
#ifndef F_1
T_2 * V_4 = NULL ;
#endif
int V_5 = 1 ;
int V_6 , V_7 = V_8 ;
long V_9 ;
const T_3 * V_10 = NULL ;
unsigned long V_11 = V_12 ;
char * V_13 = NULL ;
char * V_14 = NULL , * V_15 = NULL ;
#ifndef F_1
char * V_16 = NULL ;
#endif
char * V_17 = NULL ;
T_4 * V_18 = NULL ;
T_5 * V_19 = F_2 () ;
T_6 * V_20 = F_3 () ;
if( ! V_19 || ! V_20 ) goto V_21;
F_4 () ;
F_5 ( & V_3 , V_22 , V_23 ) ;
if ( V_23 == NULL )
if ( ( V_23 = F_6 ( F_7 () ) ) != NULL )
F_8 ( V_23 , V_24 , V_25 | V_26 ) ;
if ( ! F_9 ( V_23 , NULL ) )
goto V_21;
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL )
{
F_10 ( V_23 , L_1 ) ;
goto V_21;
}
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_11 = 3 ;
else if ( strcmp ( * V_2 , L_4 ) == 0 || strcmp ( * V_2 , L_5 ) == 0 )
V_11 = V_12 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_16 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_17 = * ( ++ V_2 ) ;
}
#ifndef F_11
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_10 = F_12 () ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_10 = F_13 () ;
#endif
#ifndef F_14
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_10 = F_15 () ;
#endif
#ifndef F_16
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_10 = F_17 () ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_10 = F_18 () ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_10 = F_19 () ;
#endif
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_14 = * ( ++ V_2 ) ;
}
else
break;
V_2 ++ ;
V_1 -- ;
}
if ( ( V_1 >= 1 ) && ( ( sscanf ( * V_2 , L_15 , & V_7 ) == 0 ) || ( V_7 < 0 ) ) )
{
V_27:
F_10 ( V_23 , L_16 ) ;
F_10 ( V_23 , L_17 ) ;
F_10 ( V_23 , L_18 ) ;
#ifndef F_14
F_10 ( V_23 , L_19 ) ;
#endif
#ifndef F_16
F_10 ( V_23 , L_20 ) ;
F_10 ( V_23 , L_21 ) ;
#endif
F_10 ( V_23 , L_22 ) ;
F_10 ( V_23 , L_23 ) ;
F_10 ( V_23 , L_24 ) ;
F_10 ( V_23 , L_25 ) ;
#ifndef F_1
F_10 ( V_23 , L_26 ) ;
#endif
F_10 ( V_23 , L_27 , V_28 , V_28 ) ;
F_10 ( V_23 , L_28 ) ;
F_10 ( V_23 , L_29 ) ;
goto V_21;
}
F_20 () ;
if( ! F_21 ( V_23 , NULL , V_14 , NULL , & V_15 ) ) {
F_10 ( V_23 , L_30 ) ;
goto V_21;
}
#ifndef F_1
V_4 = F_22 ( V_23 , V_16 , 0 ) ;
#endif
if ( V_13 == NULL )
{
F_8 ( V_18 , stdout , V_25 ) ;
#ifdef F_23
{
T_4 * V_29 = F_6 ( F_24 () ) ;
V_18 = F_25 ( V_29 , V_18 ) ;
}
#endif
}
else
{
if ( F_26 ( V_18 , V_13 ) <= 0 )
{
perror ( V_13 ) ;
goto V_21;
}
}
if ( ! F_27 ( NULL , V_23 , 1 ) && V_17 == NULL
&& ! F_28 () )
{
F_10 ( V_23 , L_31 ) ;
}
if ( V_17 != NULL )
F_10 ( V_23 , L_32 ,
F_29 ( V_17 ) ) ;
F_10 ( V_23 , L_33 ,
V_7 ) ;
if( ! F_30 ( V_19 , V_11 ) || ! F_31 ( V_20 , V_7 , V_19 , & V_3 ) )
goto V_21;
F_32 ( NULL , V_23 ) ;
V_9 = 0L ;
for ( V_6 = 0 ; V_6 < V_20 -> V_4 -> V_30 ; V_6 ++ )
{
#ifndef F_33
V_9 <<= V_31 ;
V_9 <<= V_31 ;
#endif
V_9 += V_20 -> V_4 -> V_32 [ V_6 ] ;
}
F_10 ( V_23 , L_34 , V_9 , V_9 ) ;
{
T_7 V_33 ;
V_33 . V_34 = V_15 ;
V_33 . V_35 = V_13 ;
if ( ! F_34 ( V_18 , V_20 , V_10 , NULL , 0 ,
( V_36 * ) V_37 , & V_33 ) )
goto V_21;
}
V_5 = 0 ;
V_21:
if ( V_19 ) F_35 ( V_19 ) ;
if ( V_20 ) F_36 ( V_20 ) ;
if ( V_18 ) F_37 ( V_18 ) ;
if( V_15 ) F_38 ( V_15 ) ;
if ( V_5 != 0 )
F_39 ( V_23 ) ;
F_40 () ;
F_41 ( V_5 ) ;
}
static int T_8 V_22 ( int V_38 , int V_39 , T_1 * V_3 )
{
char V_40 = '*' ;
if ( V_38 == 0 ) V_40 = '.' ;
if ( V_38 == 1 ) V_40 = '+' ;
if ( V_38 == 2 ) V_40 = '*' ;
if ( V_38 == 3 ) V_40 = '\n' ;
F_42 ( V_3 -> V_41 , & V_40 , 1 ) ;
( void ) F_43 ( V_3 -> V_41 ) ;
#ifdef F_44
V_38 = V_39 ;
#endif
return 1 ;
}
