int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 = 1 ;
T_1 * V_6 = NULL , * V_7 = NULL , * V_8 = NULL ;
int V_9 = 0 , V_10 = 0 , V_11 = 0 ;
char * V_12 = NULL , * V_13 = NULL , * V_14 ;
char * V_15 = NULL , * V_16 = NULL ;
char * V_17 = L_1 , * V_18 = L_2 , * V_19 = NULL ;
char * V_20 = NULL , * V_21 = NULL ;
T_2 * V_22 = NULL ;
T_3 * V_23 = NULL ;
T_4 * V_24 = NULL ;
F_1 () ;
if ( ! V_25 ) V_25 = F_2 ( V_26 , V_27 ) ;
V_14 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_28;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_10 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_11 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_9 = 1 ;
else V_4 = 1 ;
V_1 -- ;
V_2 ++ ;
}
if ( V_4 )
{
V_28:
F_3 ( V_25 , L_13 , V_14 ) ;
F_3 ( V_25 , L_14 ) ;
F_3 ( V_25 , L_15 ) ;
F_3 ( V_25 , L_16 ) ;
F_3 ( V_25 , L_17 ) ;
F_3 ( V_25 , L_18 ) ;
F_3 ( V_25 , L_19 ) ;
F_3 ( V_25 , L_20 ) ;
F_3 ( V_25 , L_21 ) ;
F_3 ( V_25 , L_22 ) ;
F_3 ( V_25 , L_23 ) ;
goto V_29;
}
F_4 () ;
if( ! F_5 ( V_25 , V_15 , NULL , & V_16 , NULL ) ) {
F_3 ( V_25 , L_24 ) ;
goto V_29;
}
if( V_21 ) {
if( strcmp ( V_21 , L_25 ) ) V_8 = F_6 ( V_21 , L_26 ) ;
else V_8 = F_2 ( V_30 , V_27 ) ;
if( ! V_8 ) {
F_3 ( V_25 , L_27 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
V_24 = F_8 ( V_8 , NULL , NULL , V_16 ) ;
if( ! V_24 ) {
F_3 ( V_25 , L_28 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
V_23 = F_9 () ;
if( V_20 ) F_10 ( V_23 -> V_17 -> V_20 ,
V_20 , strlen ( V_20 ) ) ;
F_11 ( V_23 , V_24 ) ;
F_12 ( V_23 , V_24 , F_13 () ) ;
V_19 = F_14 ( V_23 ) ;
if ( V_13 ) V_7 = F_6 ( V_13 , L_29 ) ;
else V_7 = F_2 ( stdout , V_27 ) ;
if( ! V_7 ) {
F_3 ( V_25 , L_30 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
F_3 ( V_7 , L_31 , V_19 ) ;
Free ( V_19 ) ;
V_5 = 0 ;
goto V_29;
}
if ( V_12 ) V_6 = F_6 ( V_12 , L_26 ) ;
else V_6 = F_2 ( V_30 , V_27 ) ;
if( ! V_6 ) {
F_3 ( V_25 , L_32 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
V_22 = F_15 ( NULL , V_6 , NULL ) ;
if( ! V_22 ) {
F_3 ( V_25 , L_33 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
V_19 = F_16 ( V_22 , V_18 , V_17 ) ;
if( ! V_19 ) {
F_3 ( V_25 , L_34 , V_17 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
V_23 = F_17 ( V_19 , - 1 ) ;
if( ! V_23 ) {
F_3 ( V_25 , L_35 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
if ( V_13 ) V_7 = F_6 ( V_13 , L_29 ) ;
else V_7 = F_2 ( stdout , V_27 ) ;
if( ! V_7 ) {
F_3 ( V_25 , L_30 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
if( ! V_10 ) F_18 ( V_7 , V_23 ) ;
V_24 = F_19 ( V_23 ) ;
if( V_9 ) {
V_3 = F_20 ( V_23 , V_24 ) ;
if( V_3 ) F_3 ( V_25 , L_36 ) ;
else {
F_3 ( V_25 , L_37 ) ;
F_7 ( V_25 ) ;
goto V_29;
}
}
if( V_11 ) F_21 ( V_7 , V_24 ) ;
V_5 = 0 ;
V_29:
F_22 ( V_22 ) ;
F_23 ( V_23 ) ;
F_24 ( V_6 ) ;
F_24 ( V_7 ) ;
F_24 ( V_8 ) ;
F_25 ( V_24 ) ;
if( V_16 ) Free ( V_16 ) ;
EXIT ( V_5 ) ;
}
