int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
int V_5 , V_6 = 0 ;
const T_2 * V_7 = NULL ;
T_3 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
char * V_15 , * V_16 , * V_17 ;
int V_18 = 0 ;
F_1 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_19 , V_20 , V_21 | V_22 ) ;
V_15 = NULL ;
V_16 = NULL ;
V_10 = V_23 ;
V_11 = V_23 ;
V_17 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_11 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_18 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_13 = 1 ;
else if ( ( V_7 = F_6 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_7 ( V_19 , L_9 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_24:
F_7 ( V_19 , L_10 , V_17 ) ;
F_7 ( V_19 , L_11 ) ;
F_7 ( V_19 , L_12 ) ;
F_7 ( V_19 , L_13 ) ;
F_7 ( V_19 , L_14 ) ;
F_7 ( V_19 , L_15 ) ;
F_7 ( V_19 , L_16 ) ;
F_7 ( V_19 , L_17 ) ;
#ifndef F_8
F_7 ( V_19 , L_18 ) ;
#endif
F_7 ( V_19 , L_19 ) ;
F_7 ( V_19 , L_20 ) ;
F_7 ( V_19 , L_21 ) ;
F_7 ( V_19 , L_22 ) ;
goto V_25;
}
F_9 () ;
V_8 = F_2 ( F_3 () ) ;
V_9 = F_2 ( F_3 () ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
F_10 ( V_19 ) ;
goto V_25;
}
if ( V_15 == NULL )
F_4 ( V_8 , V_26 , V_21 ) ;
else
{
if ( F_11 ( V_8 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_25;
}
}
F_7 ( V_19 , L_23 ) ;
if ( V_10 == V_27 )
V_4 = F_12 ( V_8 , NULL ) ;
#ifndef F_13
else if ( V_10 == V_28 )
{
T_4 * V_29 = NULL ;
unsigned char * V_30 ;
int V_31 = 0 ;
V_29 = F_14 () ;
for (; ; )
{
if ( ( V_29 == NULL ) || ( ! F_15 ( V_29 , V_31 + 1024 * 10 ) ) )
goto V_25;
V_5 = F_16 ( V_8 , & ( V_29 -> V_32 [ V_31 ] ) , 1024 * 10 ) ;
V_31 += V_5 ;
if ( V_5 == 0 ) break;
if ( V_5 < 0 )
{
perror ( L_24 ) ;
F_17 ( V_29 ) ;
goto V_25;
}
}
V_30 = ( unsigned char * ) V_29 -> V_32 ;
V_4 = ( T_1 * ) F_18 ( NULL , & V_30 , ( long ) V_31 , NULL ) ;
F_17 ( V_29 ) ;
}
#endif
else if ( V_10 == V_23 )
V_4 = F_19 ( V_8 , NULL , NULL , NULL ) ;
else
{
F_7 ( V_19 , L_25 ) ;
goto V_25;
}
if ( V_4 == NULL )
{
F_7 ( V_19 , L_26 ) ;
F_10 ( V_19 ) ;
goto V_25;
}
if ( V_16 == NULL )
F_4 ( V_9 , stdout , V_21 ) ;
else
{
if ( F_20 ( V_9 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_25;
}
}
if ( V_12 )
if ( ! F_21 ( V_9 , V_4 , 0 ) )
{
perror ( V_16 ) ;
F_10 ( V_19 ) ;
goto V_25;
}
if ( V_18 )
{
fprintf ( stdout , L_27 ) ;
F_22 ( V_9 , V_4 -> V_33 ) ;
fprintf ( stdout , L_28 ) ;
}
if ( V_13 )
{
int V_34 = F_23 ( V_4 ) ;
if ( V_34 == 1 )
F_7 ( V_9 , L_29 ) ;
else if ( V_34 == 0 )
{
long V_35 ;
while ( ( V_35 = F_24 () ) != 0 &&
F_25 ( V_35 ) == V_36 &&
F_26 ( V_35 ) == V_37 &&
F_27 ( V_35 ) != V_38 )
{
F_7 ( V_9 , L_30 , F_28 ( V_35 ) ) ;
F_29 () ;
}
}
if ( V_34 == - 1 || F_24 () != 0 )
{
F_10 ( V_19 ) ;
goto V_25;
}
}
if ( V_14 ) goto V_25;
F_7 ( V_19 , L_31 ) ;
if ( V_11 == V_27 )
V_5 = F_30 ( V_9 , V_4 ) ;
#ifndef F_13
else if ( V_11 == V_28 )
{
unsigned char * V_30 , * V_39 ;
int V_31 ;
V_5 = 1 ;
V_31 = F_31 ( V_4 , NULL , NULL ) ;
if ( ( V_30 = ( unsigned char * ) Malloc ( V_31 ) ) == NULL )
{
F_7 ( V_19 , L_32 ) ;
goto V_25;
}
V_39 = V_30 ;
F_31 ( V_4 , & V_30 , NULL ) ;
F_32 ( V_9 , ( char * ) V_39 , V_31 ) ;
Free ( V_39 ) ;
}
#endif
else if ( V_11 == V_23 )
V_5 = F_33 ( V_9 , V_4 , V_7 , NULL , 0 , NULL , NULL ) ;
else {
F_7 ( V_19 , L_33 ) ;
goto V_25;
}
if ( ! V_5 )
{
F_7 ( V_19 , L_34 ) ;
F_10 ( V_19 ) ;
}
else
V_3 = 0 ;
V_25:
if ( V_8 != NULL ) F_34 ( V_8 ) ;
if ( V_9 != NULL ) F_34 ( V_9 ) ;
if ( V_4 != NULL ) F_35 ( V_4 ) ;
EXIT ( V_3 ) ;
}
