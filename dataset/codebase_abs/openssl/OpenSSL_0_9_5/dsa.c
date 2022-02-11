int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
int V_5 , V_6 = 0 ;
const T_2 * V_7 = NULL ;
T_3 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 ;
int V_14 = 0 , V_15 = 0 ;
char * V_16 , * V_17 , * V_18 ;
char * V_19 = NULL , * V_20 = NULL ;
char * V_21 = NULL , * V_22 = NULL ;
int V_23 = 0 ;
F_1 () ;
if ( V_24 == NULL )
if ( ( V_24 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_24 , V_25 , V_26 | V_27 ) ;
V_16 = NULL ;
V_17 = NULL ;
V_10 = V_28 ;
V_11 = V_28 ;
V_18 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_11 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_29;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_23 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_15 = 1 ;
else if ( ( V_7 = F_6 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_7 ( V_24 , L_12 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_29:
F_7 ( V_24 , L_13 , V_18 ) ;
F_7 ( V_24 , L_14 ) ;
F_7 ( V_24 , L_15 ) ;
F_7 ( V_24 , L_16 ) ;
F_7 ( V_24 , L_17 ) ;
F_7 ( V_24 , L_18 ) ;
F_7 ( V_24 , L_19 ) ;
F_7 ( V_24 , L_20 ) ;
F_7 ( V_24 , L_21 ) ;
F_7 ( V_24 , L_22 ) ;
#ifndef F_8
F_7 ( V_24 , L_23 ) ;
#endif
F_7 ( V_24 , L_24 ) ;
F_7 ( V_24 , L_25 ) ;
F_7 ( V_24 , L_26 ) ;
goto V_30;
}
F_9 () ;
if( ! F_10 ( V_24 , V_19 , V_20 , & V_21 , & V_22 ) ) {
F_7 ( V_24 , L_27 ) ;
goto V_30;
}
V_8 = F_2 ( F_3 () ) ;
V_9 = F_2 ( F_3 () ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
F_11 ( V_24 ) ;
goto V_30;
}
if ( V_16 == NULL )
F_4 ( V_8 , V_31 , V_26 ) ;
else
{
if ( F_12 ( V_8 , V_16 ) <= 0 )
{
perror ( V_16 ) ;
goto V_30;
}
}
F_7 ( V_24 , L_28 ) ;
if ( V_10 == V_32 ) {
if( V_14 ) V_4 = F_13 ( V_8 , NULL ) ;
else V_4 = F_14 ( V_8 , NULL ) ;
} else if ( V_10 == V_28 ) {
if( V_14 ) V_4 = F_15 ( V_8 , NULL , NULL , NULL ) ;
else V_4 = F_16 ( V_8 , NULL , NULL , V_21 ) ;
} else
{
F_7 ( V_24 , L_29 ) ;
goto V_30;
}
if ( V_4 == NULL )
{
F_7 ( V_24 , L_30 ) ;
F_11 ( V_24 ) ;
goto V_30;
}
if ( V_17 == NULL )
F_4 ( V_9 , stdout , V_26 ) ;
else
{
if ( F_17 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_30;
}
}
if ( V_12 )
if ( ! F_18 ( V_9 , V_4 , 0 ) )
{
perror ( V_17 ) ;
F_11 ( V_24 ) ;
goto V_30;
}
if ( V_23 )
{
fprintf ( stdout , L_31 ) ;
F_19 ( V_9 , V_4 -> V_33 ) ;
fprintf ( stdout , L_32 ) ;
}
if ( V_13 ) goto V_30;
F_7 ( V_24 , L_33 ) ;
if ( V_11 == V_32 ) {
if( V_14 || V_15 ) V_5 = F_20 ( V_9 , V_4 ) ;
else V_5 = F_21 ( V_9 , V_4 ) ;
} else if ( V_11 == V_28 ) {
if( V_14 || V_15 )
V_5 = F_22 ( V_9 , V_4 ) ;
else V_5 = F_23 ( V_9 , V_4 , V_7 ,
NULL , 0 , NULL , V_22 ) ;
} else {
F_7 ( V_24 , L_34 ) ;
goto V_30;
}
if ( ! V_5 )
{
F_7 ( V_24 , L_35 ) ;
F_11 ( V_24 ) ;
}
else
V_3 = 0 ;
V_30:
if( V_8 != NULL ) F_24 ( V_8 ) ;
if( V_9 != NULL ) F_24 ( V_9 ) ;
if( V_4 != NULL ) F_25 ( V_4 ) ;
if( V_21 ) Free ( V_21 ) ;
if( V_22 ) Free ( V_22 ) ;
EXIT ( V_3 ) ;
}
