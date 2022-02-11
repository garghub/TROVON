int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 , V_6 = 1 ;
T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 = 0 , V_10 = 0 , V_11 = 0 ;
char * V_12 = NULL , * V_13 = NULL , * V_14 ;
char * V_15 = NULL , * V_16 = NULL ;
const char * V_17 = L_1 , * V_18 = L_2 ;
char * V_19 = NULL ;
char * V_20 = NULL , * V_21 = NULL ;
T_3 * V_22 = NULL ;
T_4 * V_23 = NULL ;
T_5 * V_24 = NULL ;
#ifndef F_1
char * V_25 = NULL ;
#endif
F_2 () ;
if ( ! V_26 ) V_26 = F_3 ( V_27 , V_28 ) ;
if ( ! F_4 ( V_26 , NULL ) )
goto V_29;
V_14 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_18 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_25 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_10 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_11 = 1 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_9 = 1 ;
else V_5 = 1 ;
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
V_30:
F_5 ( V_26 , L_14 , V_14 ) ;
F_5 ( V_26 , L_15 ) ;
F_5 ( V_26 , L_16 ) ;
F_5 ( V_26 , L_17 ) ;
F_5 ( V_26 , L_18 ) ;
F_5 ( V_26 , L_19 ) ;
F_5 ( V_26 , L_20 ) ;
F_5 ( V_26 , L_21 ) ;
F_5 ( V_26 , L_22 ) ;
F_5 ( V_26 , L_23 ) ;
F_5 ( V_26 , L_24 ) ;
#ifndef F_1
F_5 ( V_26 , L_25 ) ;
#endif
goto V_29;
}
F_6 () ;
if( ! F_7 ( V_26 , V_15 , NULL , & V_16 , NULL ) ) {
F_5 ( V_26 , L_26 ) ;
goto V_29;
}
#ifndef F_1
V_3 = F_8 ( V_26 , V_25 , 0 ) ;
#endif
if( V_21 ) {
V_24 = F_9 ( V_26 ,
strcmp ( V_21 , L_27 ) ? V_21 : NULL ,
V_31 , 1 , V_16 , V_3 , L_28 ) ;
if( ! V_24 ) {
goto V_29;
}
V_23 = F_10 () ;
if( V_20 ) F_11 ( V_23 -> V_17 -> V_20 ,
V_20 , ( int ) strlen ( V_20 ) ) ;
F_12 ( V_23 , V_24 ) ;
F_13 ( V_23 , V_24 , F_14 () ) ;
V_19 = F_15 ( V_23 ) ;
if ( V_13 ) V_8 = F_16 ( V_13 , L_29 ) ;
else {
V_8 = F_3 ( stdout , V_28 ) ;
#ifdef F_17
{
T_2 * V_32 = F_18 ( F_19 () ) ;
V_8 = F_20 ( V_32 , V_8 ) ;
}
#endif
}
if( ! V_8 ) {
F_5 ( V_26 , L_30 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
F_5 ( V_8 , L_31 , V_19 ) ;
F_22 ( V_19 ) ;
V_6 = 0 ;
goto V_29;
}
if ( V_12 ) V_7 = F_16 ( V_12 , L_32 ) ;
else V_7 = F_3 ( V_33 , V_28 ) ;
if( ! V_7 ) {
F_5 ( V_26 , L_33 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
V_22 = F_23 ( NULL ) ;
V_4 = F_24 ( V_22 , V_7 , NULL ) ;
if( ! V_4 ) {
F_5 ( V_26 , L_34 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
V_19 = F_25 ( V_22 , V_18 , V_17 ) ;
if( ! V_19 ) {
F_5 ( V_26 , L_35 , V_17 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
V_23 = F_26 ( V_19 , - 1 ) ;
if( ! V_23 ) {
F_5 ( V_26 , L_36 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
if ( V_13 ) V_8 = F_16 ( V_13 , L_29 ) ;
else {
V_8 = F_3 ( stdout , V_28 ) ;
#ifdef F_17
{
T_2 * V_32 = F_18 ( F_19 () ) ;
V_8 = F_20 ( V_32 , V_8 ) ;
}
#endif
}
if( ! V_8 ) {
F_5 ( V_26 , L_30 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
if( ! V_10 ) F_27 ( V_8 , V_23 ) ;
V_24 = F_28 ( V_23 ) ;
if( V_9 ) {
V_4 = F_29 ( V_23 , V_24 ) ;
if ( V_4 > 0 ) F_5 ( V_26 , L_37 ) ;
else {
F_5 ( V_26 , L_38 ) ;
F_21 ( V_26 ) ;
goto V_29;
}
}
if( V_11 ) F_30 ( V_8 , V_24 ) ;
V_6 = 0 ;
V_29:
F_31 ( V_22 ) ;
F_32 ( V_23 ) ;
F_33 ( V_7 ) ;
F_34 ( V_8 ) ;
F_35 ( V_24 ) ;
if( V_16 ) F_22 ( V_16 ) ;
F_36 () ;
F_37 ( V_6 ) ;
}
