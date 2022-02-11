int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 0 ;
int V_4 = 20 ;
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 = 0 ;
T_1 * V_8 = NULL ;
T_2 * V_9 ;
F_1 () ;
if ( V_10 == NULL )
if ( ( V_10 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_10 , V_11 , V_12 | V_13 ) ;
-- V_1 ;
++ V_2 ;
while ( V_1 >= 1 && * * V_2 == '-' )
{
if( ! strcmp ( * V_2 , L_1 ) )
V_3 = 1 ;
else if( ! strcmp ( * V_2 , L_2 ) )
V_5 = 1 ;
else if( ! strcmp ( * V_2 , L_3 ) )
if( -- V_1 < 1 )
goto V_14;
else
V_6 = atoi ( * ++ V_2 ) ;
else if( ! strcmp ( * V_2 , L_4 ) )
V_7 = 1 ;
else if( ! strcmp ( * V_2 , L_5 ) )
if( -- V_1 < 1 )
goto V_14;
else
V_4 = atoi ( * ++ V_2 ) ;
else
{
F_5 ( V_10 , L_6 , * V_2 ) ;
goto V_14;
}
-- V_1 ;
++ V_2 ;
}
if ( V_2 [ 0 ] == NULL && ! V_5 )
{
F_5 ( V_10 , L_7 ) ;
goto V_14;
}
if ( ( V_9 = F_2 ( F_3 () ) ) != NULL )
{
F_4 ( V_9 , stdout , V_12 ) ;
#ifdef F_6
{
T_2 * V_15 = F_2 ( F_7 () ) ;
V_9 = F_8 ( V_15 , V_9 ) ;
}
#endif
}
if( V_5 )
{
char * V_16 ;
if( ! V_6 )
{
F_5 ( V_10 , L_8 ) ;
return 1 ;
}
V_8 = F_9 () ;
F_10 ( V_8 , V_6 , V_7 , NULL , NULL , NULL ) ;
V_16 = V_3 ? F_11 ( V_8 ) : F_12 ( V_8 ) ;
F_5 ( V_9 , L_9 , V_16 ) ;
F_13 ( V_16 ) ;
}
else
{
if( V_3 )
F_14 ( & V_8 , V_2 [ 0 ] ) ;
else
F_15 ( & V_8 , V_2 [ 0 ] ) ;
F_16 ( V_9 , V_8 ) ;
F_5 ( V_9 , L_10 ,
F_17 ( V_8 , V_4 , NULL , NULL ) ? L_11 : L_12 ) ;
}
F_18 ( V_8 ) ;
F_19 ( V_9 ) ;
return 0 ;
V_14:
F_5 ( V_10 , L_13 ) ;
F_5 ( V_10 , L_14 , L_1 ) ;
F_5 ( V_10 , L_15 , L_16 ) ;
return 1 ;
}
