int MAIN ( int V_1 , char * * V_2 )
{
char * * args , * V_3 = NULL , * V_4 = NULL ;
T_1 * V_5 = NULL , * V_6 = NULL ;
int V_7 = 0 ;
T_2 * V_8 = NULL ;
T_3 * V_9 = NULL ;
int V_10 , V_11 = 1 ;
int V_12 = 0 ;
if ( V_13 == NULL ) V_13 = F_1 ( V_14 , V_15 ) ;
F_2 () ;
args = V_2 + 1 ;
while ( ! V_12 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) V_7 = 1 ;
else if ( ! strcmp ( * args , L_2 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_3 = * args ;
} else V_12 = 1 ;
} else if ( ! strcmp ( * args , L_3 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else V_12 = 1 ;
} else V_12 = 1 ;
args ++ ;
}
if ( V_12 ) {
F_3 ( V_13 , L_4 ) ;
F_3 ( V_13 , L_5 ) ;
F_3 ( V_13 , L_6 ) ;
F_3 ( V_13 , L_7 ) ;
F_3 ( V_13 , L_8 ) ;
F_3 ( V_13 , L_9 ) ;
EXIT ( 1 ) ;
}
if ( V_3 ) {
if ( ! ( V_5 = F_4 ( V_3 , L_10 ) ) ) {
F_3 ( V_13 ,
L_11 , V_3 ) ;
goto V_16;
}
} else V_5 = F_1 ( V_17 , V_15 ) ;
if ( V_4 ) {
if ( ! ( V_6 = F_4 ( V_4 , L_12 ) ) ) {
F_3 ( V_13 ,
L_13 , V_4 ) ;
goto V_16;
}
} else V_6 = F_1 ( stdout , V_15 ) ;
if ( V_7 ) {
V_9 = F_5 () ;
V_9 -> V_18 = F_6 ( NULL ) ;
while( ( V_8 = F_7 ( V_5 , NULL , NULL , NULL ) ) )
F_8 ( V_9 -> V_18 , V_8 ) ;
if( ! F_9 ( V_9 -> V_18 ) )
{
F_3 ( V_13 , L_14 , V_3 ) ;
F_10 ( V_13 ) ;
goto V_16;
}
F_11 ( V_6 , V_9 ) ;
V_11 = 0 ;
goto V_16;
}
if ( ! ( V_9 = F_12 ( V_5 , NULL , NULL , NULL ) ) ) {
F_3 ( V_13 , L_15 , V_3 ) ;
F_10 ( V_13 ) ;
goto V_16;
}
for( V_10 = 0 ; V_10 < F_9 ( V_9 -> V_18 ) ; V_10 ++ ) {
V_8 = F_13 ( V_9 -> V_18 , V_10 ) ;
F_14 ( V_6 , V_8 ) ;
F_15 ( V_6 , V_8 ) ;
}
V_11 = 0 ;
V_16:
F_16 ( V_5 ) ;
F_16 ( V_6 ) ;
F_17 ( V_9 ) ;
EXIT ( V_11 ) ;
}
