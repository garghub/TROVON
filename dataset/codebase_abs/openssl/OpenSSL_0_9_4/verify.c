int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 1 ;
char * V_5 = NULL , * V_6 = NULL ;
T_1 * V_7 = NULL ;
T_2 * V_8 = NULL ;
V_7 = F_1 () ;
if ( V_7 == NULL ) goto V_9;
F_2 ( V_7 , V_10 ) ;
F_3 () ;
F_4 () ;
if ( V_11 == NULL )
if ( ( V_11 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_11 , V_12 , V_13 | V_14 ) ;
V_1 -- ;
V_2 ++ ;
for (; ; )
{
if ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_9;
V_5 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_9;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
goto V_9;
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_15 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_9;
else
break;
V_1 -- ;
V_2 ++ ;
}
else
break;
}
V_8 = F_8 ( V_7 , F_9 () ) ;
if ( V_8 == NULL ) abort () ;
if ( ! F_10 ( V_8 , V_6 , V_16 ) )
F_10 ( V_8 , NULL , V_17 ) ;
V_8 = F_8 ( V_7 , F_11 () ) ;
if ( V_8 == NULL ) abort () ;
if ( ! F_12 ( V_8 , V_5 , V_16 ) )
F_12 ( V_8 , NULL , V_17 ) ;
F_13 () ;
if ( V_1 < 1 ) F_14 ( V_7 , NULL ) ;
else
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ )
F_14 ( V_7 , V_2 [ V_3 ] ) ;
V_4 = 0 ;
V_9:
if ( V_4 == 1 )
F_15 ( V_11 , L_5 ) ;
if ( V_7 != NULL ) F_16 ( V_7 ) ;
EXIT ( V_4 ) ;
}
static int F_14 ( T_1 * V_18 , char * V_19 )
{
T_3 * V_20 = NULL ;
T_4 * V_21 = NULL ;
int V_3 = 0 , V_4 = 0 ;
T_5 V_22 ;
V_21 = F_5 ( F_6 () ) ;
if ( V_21 == NULL )
{
F_17 ( V_11 ) ;
goto V_9;
}
if ( V_19 == NULL )
F_7 ( V_21 , V_23 , V_13 ) ;
else
{
if ( F_18 ( V_21 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_9;
}
}
V_20 = F_19 ( V_21 , NULL , NULL , NULL ) ;
if ( V_20 == NULL )
{
fprintf ( stdout , L_6 ,
( V_19 == NULL ) ? L_7 : V_19 ) ;
F_17 ( V_11 ) ;
goto V_9;
}
fprintf ( stdout , L_8 , ( V_19 == NULL ) ? L_7 : V_19 ) ;
F_20 ( & V_22 , V_18 , V_20 , NULL ) ;
V_3 = F_21 ( & V_22 ) ;
F_22 ( & V_22 ) ;
V_4 = 0 ;
V_9:
if ( V_3 )
{
fprintf ( stdout , L_9 ) ;
V_4 = 1 ;
}
else
F_17 ( V_11 ) ;
if ( V_20 != NULL ) F_23 ( V_20 ) ;
if ( V_21 != NULL ) F_24 ( V_21 ) ;
return ( V_4 ) ;
}
static int T_6 V_10 ( int V_24 , T_5 * V_18 )
{
char V_25 [ 256 ] ;
if ( ! V_24 )
{
if ( V_18 -> error == V_26 )
V_24 = 1 ;
else
{
F_25 (
F_26 ( V_18 -> V_27 ) , V_25 , 256 ) ;
printf ( L_10 , V_25 ) ;
printf ( L_11 , V_18 -> error ,
V_18 -> V_28 ,
F_27 ( V_18 -> error ) ) ;
if ( V_18 -> error == V_29 )
V_24 = 1 ;
}
}
if ( ! V_15 )
F_13 () ;
return ( V_24 ) ;
}
