int MAIN ( int V_1 , char * * V_2 )
{
char * * args , * V_3 = NULL , * V_4 = NULL ;
T_1 * V_5 = NULL , * V_6 = NULL ;
int V_7 = 0 , V_8 = 0 ;
T_2 * V_9 = NULL ;
int V_10 = 0 ;
#ifndef F_1
T_3 * V_11 = NULL ;
char * V_12 = NULL ;
#endif
int V_13 = 1 ;
if ( V_14 == NULL )
V_14 = F_2 ( V_15 , V_16 ) ;
if ( ! F_3 ( V_14 , NULL ) )
goto V_17;
F_4 () ;
F_5 () ;
args = V_2 + 1 ;
while ( ! V_10 && * args && * args [ 0 ] == '-' )
{
if ( ! strcmp ( * args , L_1 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_3 = * args ;
}
else V_10 = 1 ;
}
else if ( ! strcmp ( * args , L_2 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_4 = * args ;
}
else V_10 = 1 ;
}
#ifndef F_1
else if ( strcmp ( * args , L_3 ) == 0 )
{
if ( ! args [ 1 ] ) goto V_18;
V_12 = * ( ++ args ) ;
}
#endif
else if ( strcmp ( * args , L_4 ) == 0 )
V_7 = 1 ;
else if ( strcmp ( * args , L_5 ) == 0 )
V_8 = 1 ;
args ++ ;
}
if ( V_10 )
{
#ifndef F_1
V_18:
#endif
F_6 ( V_14 , L_6 ) ;
F_6 ( V_14 , L_7 ) ;
F_6 ( V_14 , L_8 ) ;
F_6 ( V_14 , L_9 ) ;
F_6 ( V_14 , L_10 ) ;
F_6 ( V_14 , L_11 ) ;
#ifndef F_1
F_6 ( V_14 , L_12 ) ;
#endif
return 1 ;
}
#ifndef F_1
V_11 = F_7 ( V_14 , V_12 , 0 ) ;
#endif
if ( V_3 )
{
if ( ! ( V_5 = F_8 ( V_3 , L_13 ) ) )
{
F_6 ( V_14 ,
L_14 , V_3 ) ;
goto V_17;
}
}
else
V_5 = F_2 ( V_19 , V_16 ) ;
if ( V_4 )
{
if ( ! ( V_6 = F_8 ( V_4 , L_15 ) ) )
{
F_6 ( V_14 ,
L_16 , V_4 ) ;
goto V_17;
}
}
else
{
V_6 = F_2 ( stdout , V_16 ) ;
#ifdef F_9
{
T_1 * V_20 = F_10 ( F_11 () ) ;
V_6 = F_12 ( V_20 , V_6 ) ;
}
#endif
}
V_9 = F_13 ( V_5 , NULL ) ;
if ( ! V_9 )
{
F_6 ( V_14 , L_17 ) ;
F_14 ( V_14 ) ;
goto V_17;
}
if ( ! V_8 )
F_15 ( V_6 , V_9 ) ;
if ( V_7 )
F_16 ( V_6 , V_9 , 0 , NULL ) ;
V_13 = 0 ;
V_17:
F_17 ( V_9 ) ;
F_18 ( V_6 ) ;
F_19 ( V_5 ) ;
return V_13 ;
}
