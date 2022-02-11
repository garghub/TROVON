int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 , V_4 ;
int V_5 = 0 , V_6 = 0 ;
const char * * V_7 ;
const char * V_8 ;
int V_9 = 0 ;
T_1 * V_10 = NULL ;
T_2 * V_11 = NULL ;
char * V_12 = NULL ;
const T_3 * V_13 = NULL ;
F_1 ( V_14 ) * V_15 ;
char V_16 [ 512 ] ;
T_4 * STDout = NULL ;
#if ! F_2 ( V_17 ) && ! F_2 ( V_18 )
V_13 = F_3 () ;
#elif ! F_2 ( V_18 )
V_13 = F_4 () ;
#elif ! F_2 ( V_17 )
V_13 = F_5 () ;
#endif
F_6 () ;
if ( V_19 == NULL )
V_19 = F_7 ( V_20 , V_21 ) ;
STDout = F_7 ( stdout , V_21 ) ;
#ifdef F_8
{
T_4 * V_22 = F_9 ( F_10 () ) ;
STDout = F_11 ( V_22 , STDout ) ;
}
#endif
if ( ! F_12 ( V_19 , NULL ) )
goto V_23;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_5 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_5 = V_6 = 1 ;
#ifndef V_17
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_13 = F_13 () ;
#endif
#ifndef V_18
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_13 = F_14 () ;
#endif
#ifndef F_15
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_13 = F_16 () ;
#endif
else if ( ( strncmp ( * V_2 , L_6 , 2 ) == 0 ) ||
( strcmp ( * V_2 , L_7 ) == 0 ) )
{
V_9 = 1 ;
break;
}
else
{
V_12 = * V_2 ;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_9 )
{
for ( V_7 = V_24 ; ( * V_7 != NULL ) ; V_7 ++ )
F_17 ( V_19 , L_8 , * V_7 ) ;
goto V_23;
}
F_18 () ;
V_10 = F_19 ( V_13 ) ;
if ( V_10 == NULL ) goto V_25;
if ( V_12 != NULL ) {
if( ! F_20 ( V_10 , V_12 ) ) {
F_17 ( V_19 , L_9 ) ;
goto V_25;
}
}
V_11 = F_21 ( V_10 ) ;
if ( V_11 == NULL ) goto V_25;
if ( ! V_5 )
{
for ( V_4 = 0 ; ; V_4 ++ )
{
V_8 = F_22 ( V_11 , V_4 ) ;
if ( V_8 == NULL ) break;
if ( V_4 != 0 ) F_17 ( STDout , L_10 ) ;
F_17 ( STDout , L_8 , V_8 ) ;
}
F_17 ( STDout , L_11 ) ;
}
else
{
V_15 = F_23 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < F_24 ( V_15 ) ; V_4 ++ )
{
V_14 * V_26 ;
V_26 = F_25 ( V_15 , V_4 ) ;
if ( V_6 )
{
unsigned long V_27 = F_26 ( V_26 ) ;
int V_28 = ( int ) ( V_27 >> 24 ) ;
int V_29 = ( int ) ( ( V_27 >> 16 ) & 0xffL ) ;
int V_30 = ( int ) ( ( V_27 >> 8 ) & 0xffL ) ;
int V_31 = ( int ) ( V_27 & 0xffL ) ;
if ( ( V_27 & 0xff000000L ) == 0x02000000L )
F_17 ( STDout , L_12 , V_29 , V_30 , V_31 ) ;
else if ( ( V_27 & 0xff000000L ) == 0x03000000L )
F_17 ( STDout , L_13 , V_30 , V_31 ) ;
else
F_17 ( STDout , L_14 , V_28 , V_29 , V_30 , V_31 ) ;
}
F_27 ( STDout , F_28 ( V_26 , V_16 , sizeof V_16 ) ) ;
}
}
V_3 = 0 ;
if ( 0 )
{
V_25:
F_29 () ;
F_30 ( V_19 ) ;
}
V_23:
if ( V_10 != NULL ) F_31 ( V_10 ) ;
if ( V_11 != NULL ) F_32 ( V_11 ) ;
if ( STDout != NULL ) F_33 ( STDout ) ;
F_34 () ;
F_35 ( V_3 ) ;
}
