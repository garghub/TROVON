int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 , V_4 ;
int V_5 = 0 ;
char * * V_6 ;
const char * V_7 ;
int V_8 = 0 ;
T_1 * V_9 = NULL ;
T_2 * V_10 = NULL ;
char * V_11 = NULL ;
T_3 * V_12 = NULL ;
F_1 ( V_13 ) * V_14 ;
char V_15 [ 512 ] ;
T_4 * STDout = NULL ;
#if ! F_2 ( V_16 ) && ! F_2 ( V_17 )
V_12 = F_3 () ;
#elif ! F_2 ( V_17 )
V_12 = F_4 () ;
#elif ! F_2 ( V_16 )
V_12 = F_5 () ;
#endif
F_6 () ;
if ( V_18 == NULL )
V_18 = F_7 ( V_19 , V_20 ) ;
STDout = F_7 ( stdout , V_20 ) ;
#ifdef F_8
{
T_4 * V_21 = F_9 ( F_10 () ) ;
STDout = F_11 ( V_21 , STDout ) ;
}
#endif
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_5 = 1 ;
#ifndef V_16
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_12 = F_12 () ;
#endif
#ifndef V_17
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_12 = F_13 () ;
#endif
#ifndef F_14
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_12 = F_15 () ;
#endif
else if ( ( strncmp ( * V_2 , L_5 , 2 ) == 0 ) ||
( strcmp ( * V_2 , L_6 ) == 0 ) )
{
V_8 = 1 ;
break;
}
else
{
V_11 = * V_2 ;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_8 )
{
for ( V_6 = V_22 ; ( * V_6 != NULL ) ; V_6 ++ )
F_16 ( V_18 , L_7 , * V_6 ) ;
goto V_23;
}
F_17 () ;
V_9 = F_18 ( V_12 ) ;
if ( V_9 == NULL ) goto V_24;
if ( V_11 != NULL ) {
if( ! F_19 ( V_9 , V_11 ) ) {
F_16 ( V_18 , L_8 ) ;
goto V_24;
}
}
V_10 = F_20 ( V_9 ) ;
if ( V_10 == NULL ) goto V_24;
if ( ! V_5 )
{
for ( V_4 = 0 ; ; V_4 ++ )
{
V_7 = F_21 ( V_10 , V_4 ) ;
if ( V_7 == NULL ) break;
if ( V_4 != 0 ) F_16 ( STDout , L_9 ) ;
F_16 ( STDout , L_7 , V_7 ) ;
}
F_16 ( STDout , L_10 ) ;
}
else
{
V_14 = F_22 ( V_10 ) ;
for ( V_4 = 0 ; V_4 < F_23 ( V_14 ) ; V_4 ++ )
{
F_24 ( STDout , F_25 (
F_26 ( V_14 , V_4 ) ,
V_15 , sizeof V_15 ) ) ;
}
}
V_3 = 0 ;
if ( 0 )
{
V_24:
F_27 () ;
F_28 ( V_18 ) ;
}
V_23:
if ( V_9 != NULL ) F_29 ( V_9 ) ;
if ( V_10 != NULL ) F_30 ( V_10 ) ;
if ( STDout != NULL ) F_31 ( STDout ) ;
F_32 () ;
F_33 ( V_3 ) ;
}
