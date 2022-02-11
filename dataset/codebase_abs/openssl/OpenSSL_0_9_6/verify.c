int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 1 ;
int V_5 = - 1 ;
char * V_6 = NULL , * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL ;
F_1 ( V_10 ) * V_11 = NULL , * V_12 = NULL ;
T_1 * V_13 = NULL ;
T_2 * V_14 = NULL ;
V_13 = F_2 () ;
if ( V_13 == NULL ) goto V_15;
F_3 ( V_13 , V_16 ) ;
F_4 () ;
F_5 () ;
if ( V_17 == NULL )
if ( ( V_17 = F_6 ( F_7 () ) ) != NULL )
F_8 ( V_17 , V_18 , V_19 | V_20 ) ;
V_1 -- ;
V_2 ++ ;
for (; ; )
{
if ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_15;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_15;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
T_3 * V_21 ;
if ( V_1 -- < 1 ) goto V_15;
V_3 = F_9 ( * ( ++ V_2 ) ) ;
if( V_3 < 0 )
{
F_10 ( V_17 , L_4 ) ;
goto V_15;
}
V_21 = F_11 ( V_3 ) ;
V_5 = F_12 ( V_21 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_15;
V_8 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_15;
V_9 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
goto V_15;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_22 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_23 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_15;
else
break;
V_1 -- ;
V_2 ++ ;
}
else
break;
}
V_14 = F_13 ( V_13 , F_14 () ) ;
if ( V_14 == NULL ) abort () ;
if ( V_7 ) {
V_3 = F_15 ( V_14 , V_7 , V_24 ) ;
if( ! V_3 ) {
F_10 ( V_17 , L_10 , V_7 ) ;
F_16 ( V_17 ) ;
goto V_15;
}
} else F_15 ( V_14 , NULL , V_25 ) ;
V_14 = F_13 ( V_13 , F_17 () ) ;
if ( V_14 == NULL ) abort () ;
if ( V_6 ) {
V_3 = F_18 ( V_14 , V_6 , V_24 ) ;
if( ! V_3 ) {
F_10 ( V_17 , L_11 , V_6 ) ;
F_16 ( V_17 ) ;
goto V_15;
}
} else F_18 ( V_14 , NULL , V_25 ) ;
F_19 () ;
if( V_8 ) {
if( ! ( V_11 = F_20 ( V_8 ) ) ) {
F_10 ( V_17 , L_12 , V_8 ) ;
F_16 ( V_17 ) ;
goto V_15;
}
}
if( V_9 ) {
if( ! ( V_12 = F_20 ( V_9 ) ) ) {
F_10 ( V_17 , L_12 , V_9 ) ;
F_16 ( V_17 ) ;
goto V_15;
}
}
if ( V_1 < 1 ) F_21 ( V_13 , NULL , V_11 , V_12 , V_5 ) ;
else
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ )
F_21 ( V_13 , V_2 [ V_3 ] , V_11 , V_12 , V_5 ) ;
V_4 = 0 ;
V_15:
if ( V_4 == 1 ) {
F_10 ( V_17 , L_13 ) ;
F_10 ( V_17 , L_14 ) ;
for( V_3 = 0 ; V_3 < F_22 () ; V_3 ++ ) {
T_3 * V_26 ;
V_26 = F_11 ( V_3 ) ;
F_10 ( V_17 , L_15 , F_23 ( V_26 ) ,
F_24 ( V_26 ) ) ;
}
}
if ( V_13 != NULL ) F_25 ( V_13 ) ;
F_26 ( V_11 , V_27 ) ;
F_26 ( V_12 , V_27 ) ;
EXIT ( V_4 ) ;
}
int T_4 V_16 ( int V_28 , T_5 * V_29 )
{
char V_30 [ 256 ] ;
if ( ! V_28 )
{
F_27 (
F_28 ( V_29 -> V_31 ) , V_30 , 256 ) ;
printf ( L_16 , V_30 ) ;
printf ( L_17 , V_29 -> error ,
V_29 -> V_32 ,
F_29 ( V_29 -> error ) ) ;
if ( V_29 -> error == V_33 ) V_28 = 1 ;
if ( V_29 -> error == V_34 ) V_28 = 1 ;
if ( V_29 -> error == V_35 ) V_28 = 1 ;
if ( V_29 -> error == V_36 ) V_28 = 1 ;
if ( V_29 -> error == V_37 ) V_28 = 1 ;
if ( V_29 -> error == V_34 ) V_28 = 1 ;
}
if ( ! V_23 )
F_19 () ;
return ( V_28 ) ;
}
