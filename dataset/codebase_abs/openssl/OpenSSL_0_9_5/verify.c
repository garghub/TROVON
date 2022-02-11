int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 1 ;
int V_5 = - 1 ;
char * V_6 = NULL , * V_7 = NULL ;
char * V_8 = NULL ;
F_1 ( V_9 ) * V_10 = NULL ;
T_1 * V_11 = NULL ;
T_2 * V_12 = NULL ;
V_11 = F_2 () ;
if ( V_11 == NULL ) goto V_13;
F_3 ( V_11 , V_14 ) ;
F_4 () ;
F_5 () ;
if ( V_15 == NULL )
if ( ( V_15 = F_6 ( F_7 () ) ) != NULL )
F_8 ( V_15 , V_16 , V_17 | V_18 ) ;
V_1 -- ;
V_2 ++ ;
for (; ; )
{
if ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_13;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_13;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
T_3 * V_19 ;
if ( V_1 -- < 1 ) goto V_13;
V_3 = F_9 ( * ( ++ V_2 ) ) ;
if( V_3 < 0 )
{
F_10 ( V_15 , L_4 ) ;
goto V_13;
}
V_19 = F_11 ( V_3 ) ;
V_5 = F_12 ( V_19 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_13;
V_8 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
goto V_13;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_20 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_13;
else
break;
V_1 -- ;
V_2 ++ ;
}
else
break;
}
V_12 = F_13 ( V_11 , F_14 () ) ;
if ( V_12 == NULL ) abort () ;
if ( V_7 ) {
V_3 = F_15 ( V_12 , V_7 , V_21 ) ;
if( ! V_3 ) {
F_10 ( V_15 , L_8 , V_7 ) ;
F_16 ( V_15 ) ;
goto V_13;
}
} else F_15 ( V_12 , NULL , V_22 ) ;
V_12 = F_13 ( V_11 , F_17 () ) ;
if ( V_12 == NULL ) abort () ;
if ( V_6 ) {
V_3 = F_18 ( V_12 , V_6 , V_21 ) ;
if( ! V_3 ) {
F_10 ( V_15 , L_9 , V_6 ) ;
F_16 ( V_15 ) ;
goto V_13;
}
} else F_18 ( V_12 , NULL , V_22 ) ;
F_19 () ;
if( V_8 ) {
if( ! ( V_10 = F_20 ( V_8 ) ) ) {
F_10 ( V_15 , L_10 , V_8 ) ;
F_16 ( V_15 ) ;
goto V_13;
}
}
if ( V_1 < 1 ) F_21 ( V_11 , NULL , V_10 , V_5 ) ;
else
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ )
F_21 ( V_11 , V_2 [ V_3 ] , V_10 , V_5 ) ;
V_4 = 0 ;
V_13:
if ( V_4 == 1 ) {
F_10 ( V_15 , L_11 ) ;
F_10 ( V_15 , L_12 ) ;
for( V_3 = 0 ; V_3 < F_22 () ; V_3 ++ ) {
T_3 * V_23 ;
V_23 = F_11 ( V_3 ) ;
F_10 ( V_15 , L_13 , F_23 ( V_23 ) ,
F_24 ( V_23 ) ) ;
}
}
if ( V_11 != NULL ) F_25 ( V_11 ) ;
F_26 ( V_10 , V_24 ) ;
EXIT ( V_4 ) ;
}
int T_4 V_14 ( int V_25 , T_5 * V_26 )
{
char V_27 [ 256 ] ;
if ( ! V_25 )
{
F_27 (
F_28 ( V_26 -> V_28 ) , V_27 , 256 ) ;
printf ( L_14 , V_27 ) ;
printf ( L_15 , V_26 -> error ,
V_26 -> V_29 ,
F_29 ( V_26 -> error ) ) ;
if ( V_26 -> error == V_30 ) V_25 = 1 ;
if ( V_26 -> error == V_31 ) V_25 = 1 ;
if ( V_26 -> error == V_32 ) V_25 = 1 ;
if ( V_26 -> error == V_33 ) V_25 = 1 ;
if ( V_26 -> error == V_34 ) V_25 = 1 ;
if ( V_26 -> error == V_31 ) V_25 = 1 ;
}
if ( ! V_20 )
F_19 () ;
return ( V_25 ) ;
}
