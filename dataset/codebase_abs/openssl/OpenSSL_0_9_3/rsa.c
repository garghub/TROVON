int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
int V_5 , V_6 = 0 ;
const T_2 * V_7 = NULL ;
T_3 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 ;
char * V_14 , * V_15 , * V_16 ;
int V_17 = 0 ;
F_1 () ;
if ( V_18 == NULL )
if ( ( V_18 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_18 , V_19 , V_20 | V_21 ) ;
V_14 = NULL ;
V_15 = NULL ;
V_10 = V_22 ;
V_11 = V_22 ;
V_16 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_11 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_17 = 1 ;
else if ( ( V_7 = F_6 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_7 ( V_18 , L_8 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_23:
F_7 ( V_18 , L_9 , V_16 ) ;
F_7 ( V_18 , L_10 ) ;
F_7 ( V_18 , L_11 ) ;
F_7 ( V_18 , L_12 ) ;
F_7 ( V_18 , L_13 ) ;
F_7 ( V_18 , L_14 ) ;
F_7 ( V_18 , L_15 ) ;
F_7 ( V_18 , L_16 ) ;
#ifndef F_8
F_7 ( V_18 , L_17 ) ;
#endif
F_7 ( V_18 , L_18 ) ;
F_7 ( V_18 , L_19 ) ;
F_7 ( V_18 , L_20 ) ;
goto V_24;
}
F_9 () ;
V_8 = F_2 ( F_3 () ) ;
V_9 = F_2 ( F_3 () ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
F_10 ( V_18 ) ;
goto V_24;
}
if ( V_14 == NULL )
F_4 ( V_8 , V_25 , V_20 ) ;
else
{
if ( F_11 ( V_8 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_24;
}
}
F_7 ( V_18 , L_21 ) ;
if ( V_10 == V_26 )
V_4 = F_12 ( V_8 , NULL ) ;
#ifndef F_13
else if ( V_10 == V_27 )
{
T_4 * V_28 = NULL ;
unsigned char * V_29 ;
int V_30 = 0 ;
V_28 = F_14 () ;
for (; ; )
{
if ( ( V_28 == NULL ) || ( ! F_15 ( V_28 , V_30 + 1024 * 10 ) ) )
goto V_24;
V_5 = F_16 ( V_8 , & ( V_28 -> V_31 [ V_30 ] ) , 1024 * 10 ) ;
V_30 += V_5 ;
if ( V_5 == 0 ) break;
if ( V_5 < 0 )
{
perror ( L_22 ) ;
F_17 ( V_28 ) ;
goto V_24;
}
}
V_29 = ( unsigned char * ) V_28 -> V_31 ;
V_4 = ( T_1 * ) F_18 ( NULL , & V_29 , ( long ) V_30 , NULL ) ;
F_17 ( V_28 ) ;
}
#endif
else if ( V_10 == V_22 )
V_4 = F_19 ( V_8 , NULL , NULL ) ;
else
{
F_7 ( V_18 , L_23 ) ;
goto V_24;
}
if ( V_4 == NULL )
{
F_7 ( V_18 , L_24 ) ;
F_10 ( V_18 ) ;
goto V_24;
}
if ( V_15 == NULL )
F_4 ( V_9 , stdout , V_20 ) ;
else
{
if ( F_20 ( V_9 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_24;
}
}
if ( V_12 )
if ( ! F_21 ( V_9 , V_4 , 0 ) )
{
perror ( V_15 ) ;
F_10 ( V_18 ) ;
goto V_24;
}
if ( V_17 )
{
fprintf ( stdout , L_25 ) ;
F_22 ( V_9 , V_4 -> V_32 ) ;
fprintf ( stdout , L_26 ) ;
}
if ( V_13 ) goto V_24;
F_7 ( V_18 , L_27 ) ;
if ( V_11 == V_26 )
V_5 = F_23 ( V_9 , V_4 ) ;
#ifndef F_13
else if ( V_11 == V_27 )
{
unsigned char * V_29 , * V_33 ;
int V_30 ;
V_5 = 1 ;
V_30 = F_24 ( V_4 , NULL , NULL ) ;
if ( ( V_29 = ( unsigned char * ) Malloc ( V_30 ) ) == NULL )
{
F_7 ( V_18 , L_28 ) ;
goto V_24;
}
V_33 = V_29 ;
F_24 ( V_4 , & V_29 , NULL ) ;
F_25 ( V_9 , ( char * ) V_33 , V_30 ) ;
Free ( V_33 ) ;
}
#endif
else if ( V_11 == V_22 )
V_5 = F_26 ( V_9 , V_4 , V_7 , NULL , 0 , NULL ) ;
else {
F_7 ( V_18 , L_29 ) ;
goto V_24;
}
if ( ! V_5 )
{
F_7 ( V_18 , L_30 ) ;
F_10 ( V_18 ) ;
}
else
V_3 = 0 ;
V_24:
if ( V_8 != NULL ) F_27 ( V_8 ) ;
if ( V_9 != NULL ) F_27 ( V_9 ) ;
if ( V_4 != NULL ) F_28 ( V_4 ) ;
EXIT ( V_3 ) ;
}
