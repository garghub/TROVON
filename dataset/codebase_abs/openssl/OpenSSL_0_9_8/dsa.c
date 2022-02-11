int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
int V_4 = 1 ;
T_2 * V_5 = NULL ;
int V_6 , V_7 = 0 ;
const T_3 * V_8 = NULL ;
T_4 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 ;
int V_15 = 0 , V_16 = 0 ;
char * V_17 , * V_18 , * V_19 ;
#ifndef F_1
char * V_20 ;
#endif
char * V_21 = NULL , * V_22 = NULL ;
char * V_23 = NULL , * V_24 = NULL ;
int V_25 = 0 ;
F_2 () ;
if ( V_26 == NULL )
if ( ( V_26 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_26 , V_27 , V_28 | V_29 ) ;
if ( ! F_6 ( V_26 , NULL ) )
goto V_30;
#ifndef F_1
V_20 = NULL ;
#endif
V_17 = NULL ;
V_18 = NULL ;
V_11 = V_31 ;
V_12 = V_31 ;
V_19 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_11 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_12 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_22 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_20 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_16 = 1 ;
else if ( ( V_8 = F_8 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_9 ( V_26 , L_13 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_32:
F_9 ( V_26 , L_14 , V_19 ) ;
F_9 ( V_26 , L_15 ) ;
F_9 ( V_26 , L_16 ) ;
F_9 ( V_26 , L_17 ) ;
F_9 ( V_26 , L_18 ) ;
F_9 ( V_26 , L_19 ) ;
F_9 ( V_26 , L_20 ) ;
F_9 ( V_26 , L_21 ) ;
#ifndef F_1
F_9 ( V_26 , L_22 ) ;
#endif
F_9 ( V_26 , L_23 ) ;
F_9 ( V_26 , L_24 ) ;
#ifndef F_10
F_9 ( V_26 , L_25 ) ;
#endif
#ifndef F_11
F_9 ( V_26 , L_26 ) ;
F_9 ( V_26 , L_27 ) ;
#endif
F_9 ( V_26 , L_28 ) ;
F_9 ( V_26 , L_29 ) ;
F_9 ( V_26 , L_30 ) ;
goto V_30;
}
F_12 () ;
#ifndef F_1
V_3 = F_13 ( V_26 , V_20 , 0 ) ;
#endif
if( ! F_14 ( V_26 , V_21 , V_22 , & V_23 , & V_24 ) ) {
F_9 ( V_26 , L_31 ) ;
goto V_30;
}
V_9 = F_3 ( F_4 () ) ;
V_10 = F_3 ( F_4 () ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
F_15 ( V_26 ) ;
goto V_30;
}
if ( V_17 == NULL )
F_5 ( V_9 , V_33 , V_28 ) ;
else
{
if ( F_16 ( V_9 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_30;
}
}
F_9 ( V_26 , L_32 ) ;
if ( V_11 == V_34 ) {
if( V_15 ) V_5 = F_17 ( V_9 , NULL ) ;
else V_5 = F_18 ( V_9 , NULL ) ;
} else if ( V_11 == V_31 ) {
if( V_15 ) V_5 = F_19 ( V_9 , NULL , NULL , NULL ) ;
else V_5 = F_20 ( V_9 , NULL , NULL , V_23 ) ;
} else
{
F_9 ( V_26 , L_33 ) ;
goto V_30;
}
if ( V_5 == NULL )
{
F_9 ( V_26 , L_34 ) ;
F_15 ( V_26 ) ;
goto V_30;
}
if ( V_18 == NULL )
{
F_5 ( V_10 , stdout , V_28 ) ;
#ifdef F_21
{
T_4 * V_35 = F_3 ( F_22 () ) ;
V_10 = F_23 ( V_35 , V_10 ) ;
}
#endif
}
else
{
if ( F_24 ( V_10 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_30;
}
}
if ( V_13 )
if ( ! F_25 ( V_10 , V_5 , 0 ) )
{
perror ( V_18 ) ;
F_15 ( V_26 ) ;
goto V_30;
}
if ( V_25 )
{
fprintf ( stdout , L_35 ) ;
F_26 ( V_10 , V_5 -> V_36 ) ;
fprintf ( stdout , L_36 ) ;
}
if ( V_14 ) goto V_30;
F_9 ( V_26 , L_37 ) ;
if ( V_12 == V_34 ) {
if( V_15 || V_16 ) V_6 = F_27 ( V_10 , V_5 ) ;
else V_6 = F_28 ( V_10 , V_5 ) ;
} else if ( V_12 == V_31 ) {
if( V_15 || V_16 )
V_6 = F_29 ( V_10 , V_5 ) ;
else V_6 = F_30 ( V_10 , V_5 , V_8 ,
NULL , 0 , NULL , V_24 ) ;
} else {
F_9 ( V_26 , L_38 ) ;
goto V_30;
}
if ( ! V_6 )
{
F_9 ( V_26 , L_39 ) ;
F_15 ( V_26 ) ;
}
else
V_4 = 0 ;
V_30:
if( V_9 != NULL ) F_31 ( V_9 ) ;
if( V_10 != NULL ) F_32 ( V_10 ) ;
if( V_5 != NULL ) F_33 ( V_5 ) ;
if( V_23 ) F_34 ( V_23 ) ;
if( V_24 ) F_34 ( V_24 ) ;
F_35 () ;
F_36 ( V_4 ) ;
}
