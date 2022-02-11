int MAIN ( int V_1 , char * * V_2 )
{
char V_3 [ 200 ] ;
T_1 * V_4 = NULL ;
int V_5 = 1 ;
char * V_6 = NULL ;
char * V_7 = NULL , * V_8 , * V_9 = NULL ;
T_2 * V_10 = NULL , * V_11 = NULL ;
T_3 * V_12 = NULL ;
F_1 () ;
if ( V_13 == NULL )
if ( ( V_13 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_13 , V_14 , V_15 | V_16 ) ;
V_2 ++ ;
V_1 -- ;
for (; ; )
{
if ( V_1 <= 0 ) break;
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_17;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
goto V_17;
else if ( V_9 == NULL )
{
V_9 = * V_2 ;
}
#ifndef F_5
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_12 = F_6 () ;
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_12 = F_7 () ;
#endif
#ifndef F_8
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_12 = F_9 () ;
#endif
else
goto V_17;
V_2 ++ ;
V_1 -- ;
}
if ( V_9 == NULL )
{
V_17:
F_10 ( V_13 , L_7 ) ;
F_10 ( V_13 , L_8 ) ;
#ifndef F_5
F_10 ( V_13 , L_9 ) ;
F_10 ( V_13 , L_10 ) ;
#endif
#ifndef F_8
F_10 ( V_13 , L_11 ) ;
#endif
F_10 ( V_13 , L_12 ) ;
F_10 ( V_13 , L_13 ) ;
F_10 ( V_13 , L_14 ) ;
F_10 ( V_13 , L_15 ) ;
F_10 ( V_13 , L_16 ) ;
goto V_18;
}
V_11 = F_2 ( F_3 () ) ;
if ( ! ( F_11 ( V_11 , V_9 ) ) )
{
perror ( V_9 ) ;
goto V_18;
}
if ( ( V_4 = F_12 ( V_11 , NULL , NULL ) ) == NULL )
{
F_10 ( V_13 , L_17 ) ;
goto V_18;
}
F_13 ( V_11 ) ;
V_10 = F_2 ( F_3 () ) ;
if ( V_10 == NULL ) goto V_18;
if ( V_6 == NULL )
F_4 ( V_10 , stdout , V_15 ) ;
else
{
if ( F_14 ( V_10 , V_6 ) <= 0 )
{
perror ( V_6 ) ;
goto V_18;
}
}
V_8 = F_15 ( V_3 , 200 ) ;
if ( ( V_8 == NULL ) || ! F_16 ( V_8 , 1024L * 1024L ) )
F_10 ( V_13 , L_18 ) ;
if ( V_7 == NULL )
F_10 ( V_13 , L_19 ) ;
else
{
F_10 ( V_13 , L_20 ,
F_17 ( V_7 ) ) ;
}
F_10 ( V_13 , L_21 ,
F_18 ( V_4 -> V_19 ) ) ;
if ( ! F_19 ( V_4 ) ) goto V_18;
if ( V_8 == NULL )
F_10 ( V_13 , L_22 ) ;
else
F_20 ( V_8 ) ;
if ( ! F_21 ( V_10 , V_4 , V_12 , NULL , 0 , NULL ) )
goto V_18;
V_5 = 0 ;
V_18:
if ( V_5 != 0 )
F_22 ( V_13 ) ;
if ( V_10 != NULL ) F_13 ( V_10 ) ;
if ( V_4 != NULL ) F_23 ( V_4 ) ;
EXIT ( V_5 ) ;
}
static long F_17 ( char * V_20 )
{
char * V_19 , * V_21 ;
int V_22 ;
long V_23 = 0 ;
for (; ; )
{
V_22 = 0 ;
for ( V_19 = V_20 ; ( ( * V_19 != '\0' ) && ( * V_19 != V_24 ) ) ; V_19 ++ ) ;
if ( * V_19 == '\0' ) V_22 = 1 ;
* V_19 = '\0' ;
V_21 = V_20 ;
V_20 = V_19 + 1 ;
if ( * V_21 == '\0' ) break;
V_23 += F_16 ( V_21 , 1 ) ;
if ( V_22 ) break;
}
return ( V_23 ) ;
}
