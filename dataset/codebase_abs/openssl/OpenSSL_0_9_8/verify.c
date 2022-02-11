int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 1 , V_6 = 0 ;
int V_7 = - 1 ;
char * V_8 = NULL , * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
F_1 ( V_12 ) * V_13 = NULL , * V_14 = NULL ;
T_2 * V_15 = NULL ;
T_3 * V_16 = NULL ;
T_4 * V_17 = NULL ;
#ifndef F_2
char * V_18 = NULL ;
#endif
V_15 = F_3 () ;
if ( V_15 == NULL ) goto V_19;
F_4 ( V_15 , V_20 ) ;
F_5 () ;
F_6 () ;
if ( V_21 == NULL )
if ( ( V_21 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_21 , V_22 , V_23 | V_24 ) ;
if ( ! F_10 ( V_21 , NULL ) )
goto V_19;
V_1 -- ;
V_2 ++ ;
for (; ; )
{
if ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_19;
V_8 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_19;
V_9 = * ( ++ V_2 ) ;
}
else if ( F_11 ( & V_2 , & V_1 , & V_6 , V_21 ,
& V_17 ) )
{
if ( V_6 )
goto V_19;
continue;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_19;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_19;
V_11 = * ( ++ V_2 ) ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_19;
V_18 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_6 ) == 0 )
goto V_19;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_25 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_19;
else
break;
V_1 -- ;
V_2 ++ ;
}
else
break;
}
#ifndef F_2
V_3 = F_12 ( V_21 , V_18 , 0 ) ;
#endif
if ( V_17 )
F_13 ( V_15 , V_17 ) ;
V_16 = F_14 ( V_15 , F_15 () ) ;
if ( V_16 == NULL ) abort () ;
if ( V_9 ) {
V_4 = F_16 ( V_16 , V_9 , V_26 ) ;
if( ! V_4 ) {
F_17 ( V_21 , L_8 , V_9 ) ;
F_18 ( V_21 ) ;
goto V_19;
}
} else F_16 ( V_16 , NULL , V_27 ) ;
V_16 = F_14 ( V_15 , F_19 () ) ;
if ( V_16 == NULL ) abort () ;
if ( V_8 ) {
V_4 = F_20 ( V_16 , V_8 , V_26 ) ;
if( ! V_4 ) {
F_17 ( V_21 , L_9 , V_8 ) ;
F_18 ( V_21 ) ;
goto V_19;
}
} else F_20 ( V_16 , NULL , V_27 ) ;
F_21 () ;
if( V_10 ) {
if( ! ( V_13 = F_22 ( V_10 ) ) ) {
F_17 ( V_21 , L_10 , V_10 ) ;
F_18 ( V_21 ) ;
goto V_19;
}
}
if( V_11 ) {
if( ! ( V_14 = F_22 ( V_11 ) ) ) {
F_17 ( V_21 , L_10 , V_11 ) ;
F_18 ( V_21 ) ;
goto V_19;
}
}
if ( V_1 < 1 ) F_23 ( V_15 , NULL , V_13 , V_14 , V_7 , V_3 ) ;
else
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ )
F_23 ( V_15 , V_2 [ V_4 ] , V_13 , V_14 , V_7 , V_3 ) ;
V_5 = 0 ;
V_19:
if ( V_5 == 1 ) {
F_17 ( V_21 , L_11 ) ;
#ifndef F_2
F_17 ( V_21 , L_12 ) ;
#endif
F_17 ( V_21 , L_13 ) ;
F_17 ( V_21 , L_14 ) ;
for( V_4 = 0 ; V_4 < F_24 () ; V_4 ++ ) {
T_5 * V_28 ;
V_28 = F_25 ( V_4 ) ;
F_17 ( V_21 , L_15 , F_26 ( V_28 ) ,
F_27 ( V_28 ) ) ;
}
}
if ( V_17 ) F_28 ( V_17 ) ;
if ( V_15 != NULL ) F_29 ( V_15 ) ;
F_30 ( V_13 , V_29 ) ;
F_30 ( V_14 , V_29 ) ;
F_31 () ;
F_32 ( V_5 ) ;
}
int T_6 V_20 ( int V_30 , T_7 * V_31 )
{
char V_32 [ 256 ] ;
if ( ! V_30 )
{
if ( V_31 -> V_33 )
{
F_33 (
F_34 ( V_31 -> V_33 ) , V_32 ,
sizeof V_32 ) ;
printf ( L_16 , V_32 ) ;
}
printf ( L_17 , V_31 -> error ,
V_31 -> V_34 ,
F_35 ( V_31 -> error ) ) ;
if ( V_31 -> error == V_35 ) V_30 = 1 ;
if ( V_31 -> error == V_36 ) V_30 = 1 ;
if ( V_31 -> error == V_37 ) V_30 = 1 ;
if ( V_31 -> error == V_38 ) V_30 = 1 ;
if ( V_31 -> error == V_39 ) V_30 = 1 ;
if ( V_31 -> error == V_40 ) V_30 = 1 ;
if ( V_31 -> error == V_36 ) V_30 = 1 ;
if ( V_31 -> error == V_41 ) V_30 = 1 ;
if ( V_31 -> error == V_42 ) V_30 = 1 ;
if ( V_31 -> error == V_43 ) V_30 = 1 ;
if ( V_31 -> error == V_44 )
F_36 ( NULL , V_31 ) ;
return V_30 ;
}
if ( ( V_31 -> error == V_45 ) && ( V_30 == 2 ) )
F_36 ( NULL , V_31 ) ;
if ( ! V_25 )
F_21 () ;
return ( V_30 ) ;
}
