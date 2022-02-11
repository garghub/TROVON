int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * * args , * V_4 = NULL , * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL ;
T_2 * V_8 = NULL , * V_9 = NULL ;
const T_3 * V_10 = NULL ;
int V_11 , V_12 ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = 0 ;
T_4 * V_18 = NULL ;
char * V_19 = NULL , * V_20 = NULL ;
int V_21 = 0 ;
#ifndef F_1
char * V_22 = NULL ;
#endif
int V_23 = 1 ;
if ( V_24 == NULL )
V_24 = F_2 ( V_25 , V_26 ) ;
if ( ! F_3 ( V_24 , NULL ) )
goto V_27;
V_11 = V_28 ;
V_12 = V_28 ;
F_4 () ;
F_5 () ;
args = V_2 + 1 ;
while ( ! V_21 && * args && * args [ 0 ] == '-' )
{
if ( ! strcmp ( * args , L_1 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_11 = F_6 ( * args ) ;
}
else V_21 = 1 ;
}
else if ( ! strcmp ( * args , L_2 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_12 = F_6 ( * args ) ;
}
else V_21 = 1 ;
}
else if ( ! strcmp ( * args , L_3 ) )
{
if ( ! args [ 1 ] ) goto V_29;
V_6 = * ( ++ args ) ;
}
else if ( ! strcmp ( * args , L_4 ) )
{
if ( ! args [ 1 ] ) goto V_29;
V_7 = * ( ++ args ) ;
}
#ifndef F_1
else if ( strcmp ( * args , L_5 ) == 0 )
{
if ( ! args [ 1 ] ) goto V_29;
V_22 = * ( ++ args ) ;
}
#endif
else if ( ! strcmp ( * args , L_6 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_4 = * args ;
}
else V_21 = 1 ;
}
else if ( ! strcmp ( * args , L_7 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_5 = * args ;
}
else V_21 = 1 ;
}
else if ( strcmp ( * args , L_8 ) == 0 )
{
V_13 = 1 ;
V_14 = 1 ;
V_15 = 1 ;
}
else if ( strcmp ( * args , L_9 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * args , L_10 ) == 0 )
{
V_15 = 1 ;
V_16 = 1 ;
}
else if ( strcmp ( * args , L_11 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * args , L_12 ) == 0 )
V_17 = 1 ;
else
{
V_10 = F_7 ( * args + 1 ) ;
if ( ! V_10 )
{
F_8 ( V_24 , L_13 ,
* args + 1 ) ;
V_21 = 1 ;
}
}
args ++ ;
}
if ( V_21 )
{
V_29:
F_8 ( V_24 , L_14 ) ;
F_8 ( V_24 , L_15 ) ;
F_8 ( V_24 , L_16 ) ;
F_8 ( V_24 , L_17 ) ;
F_8 ( V_24 , L_18 ) ;
F_8 ( V_24 , L_19 ) ;
F_8 ( V_24 , L_20 ) ;
F_8 ( V_24 , L_21 ) ;
#ifndef F_1
F_8 ( V_24 , L_22 ) ;
#endif
return 1 ;
}
#ifndef F_1
V_3 = F_9 ( V_24 , V_22 , 0 ) ;
#endif
if ( ! F_10 ( V_24 , V_6 , V_7 , & V_19 , & V_20 ) )
{
F_8 ( V_24 , L_23 ) ;
goto V_27;
}
if ( V_5 )
{
if ( ! ( V_9 = F_11 ( V_5 , L_24 ) ) )
{
F_8 ( V_24 ,
L_25 , V_5 ) ;
goto V_27;
}
}
else
{
V_9 = F_2 ( stdout , V_26 ) ;
#ifdef F_12
{
T_2 * V_30 = F_13 ( F_14 () ) ;
V_9 = F_15 ( V_30 , V_9 ) ;
}
#endif
}
if ( V_13 )
V_18 = F_16 ( V_24 , V_4 , V_11 , 1 ,
V_19 , V_3 , L_26 ) ;
else
V_18 = F_17 ( V_24 , V_4 , V_11 , 1 ,
V_19 , V_3 , L_27 ) ;
if ( ! V_18 )
goto V_27;
if ( ! V_17 )
{
if ( V_12 == V_28 )
{
if ( V_14 )
F_18 ( V_9 , V_18 ) ;
else
F_19 ( V_9 , V_18 , V_10 ,
NULL , 0 , NULL , V_20 ) ;
}
else if ( V_12 == V_31 )
{
if ( V_14 )
F_20 ( V_9 , V_18 ) ;
else
F_21 ( V_9 , V_18 ) ;
}
else
{
F_8 ( V_24 , L_28 ) ;
goto V_27;
}
}
if ( V_16 )
{
if ( V_15 )
F_22 ( V_9 , V_18 , 0 , NULL ) ;
else
F_23 ( V_9 , V_18 , 0 , NULL ) ;
}
V_23 = 0 ;
V_27:
F_24 ( V_18 ) ;
F_25 ( V_9 ) ;
F_26 ( V_8 ) ;
if ( V_19 )
F_27 ( V_19 ) ;
if ( V_20 )
F_27 ( V_20 ) ;
return V_23 ;
}
