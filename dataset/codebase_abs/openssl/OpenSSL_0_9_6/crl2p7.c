int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 ;
T_1 * V_5 = NULL , * V_6 = NULL ;
int V_7 , V_8 ;
char * V_9 , * V_10 , * V_11 , * V_12 ;
T_2 * V_13 = NULL ;
T_3 * V_14 = NULL ;
T_4 * V_15 = NULL ;
T_5 * V_16 = NULL ;
F_1 ( T_4 ) * V_17 = NULL ;
F_1 ( V_18 ) * V_19 = NULL ;
int V_20 = 1 , V_21 = 0 ;
F_2 () ;
if ( V_22 == NULL )
if ( ( V_22 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_22 , V_23 , V_24 | V_25 ) ;
V_9 = NULL ;
V_10 = NULL ;
V_7 = V_26 ;
V_8 = V_26 ;
V_11 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_7 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_8 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_9 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_21 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
if( ! V_16 ) V_16 = F_7 () ;
F_8 ( V_16 , * ( ++ V_2 ) ) ;
}
else
{
F_9 ( V_22 , L_7 , * V_2 ) ;
V_4 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_4 )
{
V_27:
F_9 ( V_22 , L_8 , V_11 ) ;
F_9 ( V_22 , L_9 ) ;
F_9 ( V_22 , L_10 ) ;
F_9 ( V_22 , L_11 ) ;
F_9 ( V_22 , L_12 ) ;
F_9 ( V_22 , L_13 ) ;
F_9 ( V_22 , L_14 ) ;
F_9 ( V_22 , L_15 ) ;
F_9 ( V_22 , L_16 ) ;
EXIT ( 1 ) ;
}
F_10 () ;
V_5 = F_3 ( F_4 () ) ;
V_6 = F_3 ( F_4 () ) ;
if ( ( V_5 == NULL ) || ( V_6 == NULL ) )
{
F_11 ( V_22 ) ;
goto V_28;
}
if ( ! V_21 )
{
if ( V_9 == NULL )
F_5 ( V_5 , V_29 , V_24 ) ;
else
{
if ( F_12 ( V_5 , V_9 ) <= 0 )
{
perror ( V_9 ) ;
goto V_28;
}
}
if ( V_7 == V_30 )
V_15 = F_13 ( V_5 , NULL ) ;
else if ( V_7 == V_26 )
V_15 = F_14 ( V_5 , NULL , NULL , NULL ) ;
else {
F_9 ( V_22 , L_17 ) ;
goto V_28;
}
if ( V_15 == NULL )
{
F_9 ( V_22 , L_18 ) ;
F_11 ( V_22 ) ;
goto V_28;
}
}
if ( ( V_13 = F_15 () ) == NULL ) goto V_28;
if ( ( V_14 = F_16 () ) == NULL ) goto V_28;
V_13 -> type = F_17 ( V_31 ) ;
V_13 -> V_32 . V_33 = V_14 ;
V_14 -> V_34 -> type = F_17 ( V_35 ) ;
if ( ! F_18 ( V_14 -> V_36 , 1 ) ) goto V_28;
if ( ( V_17 = F_19 () ) == NULL ) goto V_28;
V_14 -> V_15 = V_17 ;
if ( V_15 != NULL )
{
F_20 ( V_17 , V_15 ) ;
V_15 = NULL ;
}
if ( ( V_19 = F_21 () ) == NULL ) goto V_28;
V_14 -> V_37 = V_19 ;
if( V_16 ) for( V_3 = 0 ; V_3 < F_22 ( V_16 ) ; V_3 ++ ) {
V_12 = F_23 ( V_16 , V_3 ) ;
if ( F_24 ( V_19 , V_12 ) < 0 )
{
F_9 ( V_22 , L_19 ) ;
F_11 ( V_22 ) ;
goto V_28;
}
}
F_25 ( V_16 ) ;
if ( V_10 == NULL )
{
F_5 ( V_6 , stdout , V_24 ) ;
#ifdef F_26
{
T_1 * V_38 = F_3 ( F_27 () ) ;
V_6 = F_28 ( V_38 , V_6 ) ;
}
#endif
}
else
{
if ( F_29 ( V_6 , V_10 ) <= 0 )
{
perror ( V_10 ) ;
goto V_28;
}
}
if ( V_8 == V_30 )
V_3 = F_30 ( V_6 , V_13 ) ;
else if ( V_8 == V_26 )
V_3 = F_31 ( V_6 , V_13 ) ;
else {
F_9 ( V_22 , L_20 ) ;
goto V_28;
}
if ( ! V_3 )
{
F_9 ( V_22 , L_21 ) ;
F_11 ( V_22 ) ;
goto V_28;
}
V_20 = 0 ;
V_28:
if ( V_5 != NULL ) F_32 ( V_5 ) ;
if ( V_6 != NULL ) F_33 ( V_6 ) ;
if ( V_13 != NULL ) F_34 ( V_13 ) ;
if ( V_15 != NULL ) F_35 ( V_15 ) ;
EXIT ( V_20 ) ;
}
