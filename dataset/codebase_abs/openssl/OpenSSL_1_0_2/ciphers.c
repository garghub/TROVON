int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 , V_4 ;
int V_5 = 0 , V_6 = 0 ;
#ifndef F_1
int V_7 = 0 ;
#endif
const char * * V_8 ;
const char * V_9 ;
int V_10 = 0 ;
T_1 * V_11 = NULL ;
T_2 * V_12 = NULL ;
char * V_13 = NULL ;
const T_3 * V_14 = NULL ;
F_2 ( V_15 ) * V_16 ;
char V_17 [ 512 ] ;
T_4 * STDout = NULL ;
V_14 = F_3 () ;
F_4 () ;
if ( V_18 == NULL )
V_18 = F_5 ( V_19 , V_20 ) ;
STDout = F_5 ( stdout , V_20 ) ;
#ifdef F_6
{
T_4 * V_21 = F_7 ( F_8 () ) ;
STDout = F_9 ( V_21 , STDout ) ;
}
#endif
if ( ! F_10 ( V_18 , NULL ) )
goto V_22;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 ) {
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_5 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
V_5 = V_6 = 1 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_3 ) == 0 )
V_7 = V_5 = 1 ;
#endif
#ifndef F_11
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_14 = F_12 () ;
#endif
#ifndef F_13
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_14 = F_14 () ;
#endif
#ifndef F_15
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_14 = F_16 () ;
#endif
else if ( ( strncmp ( * V_2 , L_7 , 2 ) == 0 ) || ( strcmp ( * V_2 , L_8 ) == 0 ) ) {
V_10 = 1 ;
break;
} else {
V_13 = * V_2 ;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_10 ) {
for ( V_8 = V_23 ; ( * V_8 != NULL ) ; V_8 ++ )
F_17 ( V_18 , L_9 , * V_8 ) ;
goto V_22;
}
F_18 () ;
V_11 = F_19 ( V_14 ) ;
if ( V_11 == NULL )
goto V_24;
if ( V_13 != NULL ) {
if ( ! F_20 ( V_11 , V_13 ) ) {
F_17 ( V_18 , L_10 ) ;
goto V_24;
}
}
V_12 = F_21 ( V_11 ) ;
if ( V_12 == NULL )
goto V_24;
if ( ! V_5 ) {
for ( V_4 = 0 ; ; V_4 ++ ) {
V_9 = F_22 ( V_12 , V_4 ) ;
if ( V_9 == NULL )
break;
if ( V_4 != 0 )
F_17 ( STDout , L_11 ) ;
F_17 ( STDout , L_9 , V_9 ) ;
}
F_17 ( STDout , L_12 ) ;
} else {
V_16 = F_23 ( V_12 ) ;
for ( V_4 = 0 ; V_4 < F_24 ( V_16 ) ; V_4 ++ ) {
V_15 * V_25 ;
V_25 = F_25 ( V_16 , V_4 ) ;
if ( V_6 ) {
unsigned long V_26 = F_26 ( V_25 ) ;
int V_27 = ( int ) ( V_26 >> 24 ) ;
int V_28 = ( int ) ( ( V_26 >> 16 ) & 0xffL ) ;
int V_29 = ( int ) ( ( V_26 >> 8 ) & 0xffL ) ;
int V_30 = ( int ) ( V_26 & 0xffL ) ;
if ( ( V_26 & 0xff000000L ) == 0x02000000L ) {
F_17 ( STDout , L_13 , V_28 ,
V_29 , V_30 ) ;
} else if ( ( V_26 & 0xff000000L ) == 0x03000000L ) {
F_17 ( STDout , L_14 , V_29 ,
V_30 ) ;
} else {
F_17 ( STDout , L_15 , V_27 ,
V_28 , V_29 , V_30 ) ;
}
}
#ifndef F_1
if ( V_7 ) {
const char * V_31 = F_27 ( V_25 ) ;
if ( V_31 == NULL )
V_31 = L_16 ;
F_17 ( STDout , L_17 , V_31 ) ;
}
#endif
F_28 ( STDout , F_29 ( V_25 , V_17 , sizeof V_17 ) ) ;
}
}
V_3 = 0 ;
if ( 0 ) {
V_24:
F_30 () ;
F_31 ( V_18 ) ;
}
V_22:
if ( V_11 != NULL )
F_32 ( V_11 ) ;
if ( V_12 != NULL )
F_33 ( V_12 ) ;
if ( STDout != NULL )
F_34 ( STDout ) ;
F_35 () ;
F_36 ( V_3 ) ;
}
