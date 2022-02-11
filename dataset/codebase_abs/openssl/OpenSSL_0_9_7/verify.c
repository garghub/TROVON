int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 1 ;
int V_6 = - 1 ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
F_1 ( V_11 ) * V_12 = NULL , * V_13 = NULL ;
T_2 * V_14 = NULL ;
T_3 * V_15 = NULL ;
char * V_16 = NULL ;
V_14 = F_2 () ;
if ( V_14 == NULL ) goto V_17;
F_3 ( V_14 , V_18 ) ;
F_4 () ;
F_5 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_6 ( F_7 () ) ) != NULL )
F_8 ( V_19 , V_20 , V_21 | V_22 ) ;
if ( ! F_9 ( V_19 , NULL ) )
goto V_17;
V_1 -- ;
V_2 ++ ;
for (; ; )
{
if ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_17;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_17;
V_8 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
T_4 * V_23 ;
if ( V_1 -- < 1 ) goto V_17;
V_4 = F_10 ( * ( ++ V_2 ) ) ;
if( V_4 < 0 )
{
F_11 ( V_19 , L_4 ) ;
goto V_17;
}
V_23 = F_12 ( V_4 ) ;
V_6 = F_13 ( V_23 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_17;
V_9 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_17;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_16 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
goto V_17;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_24 |= V_25 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_24 |= V_26 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_24 |= V_27 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_24 |= V_27 | V_28 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_29 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_17;
else
break;
V_1 -- ;
V_2 ++ ;
}
else
break;
}
V_3 = F_14 ( V_19 , V_16 , 0 ) ;
V_15 = F_15 ( V_14 , F_16 () ) ;
if ( V_15 == NULL ) abort () ;
if ( V_8 ) {
V_4 = F_17 ( V_15 , V_8 , V_30 ) ;
if( ! V_4 ) {
F_11 ( V_19 , L_14 , V_8 ) ;
F_18 ( V_19 ) ;
goto V_17;
}
} else F_17 ( V_15 , NULL , V_31 ) ;
V_15 = F_15 ( V_14 , F_19 () ) ;
if ( V_15 == NULL ) abort () ;
if ( V_7 ) {
V_4 = F_20 ( V_15 , V_7 , V_30 ) ;
if( ! V_4 ) {
F_11 ( V_19 , L_15 , V_7 ) ;
F_18 ( V_19 ) ;
goto V_17;
}
} else F_20 ( V_15 , NULL , V_31 ) ;
F_21 () ;
if( V_9 ) {
if( ! ( V_12 = F_22 ( V_9 ) ) ) {
F_11 ( V_19 , L_16 , V_9 ) ;
F_18 ( V_19 ) ;
goto V_17;
}
}
if( V_10 ) {
if( ! ( V_13 = F_22 ( V_10 ) ) ) {
F_11 ( V_19 , L_16 , V_10 ) ;
F_18 ( V_19 ) ;
goto V_17;
}
}
if ( V_1 < 1 ) F_23 ( V_14 , NULL , V_12 , V_13 , V_6 , V_3 ) ;
else
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ )
F_23 ( V_14 , V_2 [ V_4 ] , V_12 , V_13 , V_6 , V_3 ) ;
V_5 = 0 ;
V_17:
if ( V_5 == 1 ) {
F_11 ( V_19 , L_17 ) ;
F_11 ( V_19 , L_18 ) ;
for( V_4 = 0 ; V_4 < F_24 () ; V_4 ++ ) {
T_4 * V_32 ;
V_32 = F_12 ( V_4 ) ;
F_11 ( V_19 , L_19 , F_25 ( V_32 ) ,
F_26 ( V_32 ) ) ;
}
}
if ( V_14 != NULL ) F_27 ( V_14 ) ;
F_28 ( V_12 , V_33 ) ;
F_28 ( V_13 , V_33 ) ;
F_29 () ;
F_30 ( V_5 ) ;
}
int T_5 V_18 ( int V_34 , T_6 * V_35 )
{
char V_36 [ 256 ] ;
if ( ! V_34 )
{
F_31 (
F_32 ( V_35 -> V_37 ) , V_36 ,
sizeof V_36 ) ;
printf ( L_20 , V_36 ) ;
printf ( L_21 , V_35 -> error ,
V_35 -> V_38 ,
F_33 ( V_35 -> error ) ) ;
if ( V_35 -> error == V_39 ) V_34 = 1 ;
if ( V_35 -> error == V_40 ) V_34 = 1 ;
if ( V_35 -> error == V_41 ) V_34 = 1 ;
if ( V_35 -> error == V_42 ) V_34 = 1 ;
if ( V_35 -> error == V_43 ) V_34 = 1 ;
if ( V_35 -> error == V_40 ) V_34 = 1 ;
if ( V_35 -> error == V_44 ) V_34 = 1 ;
if ( V_35 -> error == V_45 ) V_34 = 1 ;
if ( V_35 -> error == V_46 ) V_34 = 1 ;
}
if ( ! V_29 )
F_21 () ;
return ( V_34 ) ;
}
