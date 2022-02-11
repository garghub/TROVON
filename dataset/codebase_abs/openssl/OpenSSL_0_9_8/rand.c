int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
int V_4 , V_5 , V_6 = 1 ;
int V_7 ;
char * V_8 = NULL ;
char * V_9 = NULL ;
int V_10 = 0 ;
T_2 * V_11 = NULL ;
int V_12 = - 1 ;
#ifndef F_1
char * V_13 = NULL ;
#endif
F_2 () ;
if ( V_14 == NULL )
if ( ( V_14 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_14 , V_15 , V_16 | V_17 ) ;
if ( ! F_6 ( V_14 , NULL ) )
goto V_18;
V_7 = 0 ;
V_4 = 0 ;
while ( ! V_7 && V_2 [ ++ V_4 ] != NULL )
{
if ( strcmp ( V_2 [ V_4 ] , L_1 ) == 0 )
{
if ( ( V_2 [ V_4 + 1 ] != NULL ) && ( V_8 == NULL ) )
V_8 = V_2 [ ++ V_4 ] ;
else
V_7 = 1 ;
}
#ifndef F_1
else if ( strcmp ( V_2 [ V_4 ] , L_2 ) == 0 )
{
if ( ( V_2 [ V_4 + 1 ] != NULL ) && ( V_13 == NULL ) )
V_13 = V_2 [ ++ V_4 ] ;
else
V_7 = 1 ;
}
#endif
else if ( strcmp ( V_2 [ V_4 ] , L_3 ) == 0 )
{
if ( ( V_2 [ V_4 + 1 ] != NULL ) && ( V_9 == NULL ) )
V_9 = V_2 [ ++ V_4 ] ;
else
V_7 = 1 ;
}
else if ( strcmp ( V_2 [ V_4 ] , L_4 ) == 0 )
{
if ( ! V_10 )
V_10 = 1 ;
else
V_7 = 1 ;
}
else if ( isdigit ( ( unsigned char ) V_2 [ V_4 ] [ 0 ] ) )
{
if ( V_12 < 0 )
{
V_5 = sscanf ( V_2 [ V_4 ] , L_5 , & V_12 ) ;
if ( V_5 == 0 || V_12 < 0 )
V_7 = 1 ;
}
else
V_7 = 1 ;
}
else
V_7 = 1 ;
}
if ( V_12 < 0 )
V_7 = 1 ;
if ( V_7 )
{
F_7 ( V_14 , L_6 ) ;
F_7 ( V_14 , L_7 ) ;
F_7 ( V_14 , L_8 ) ;
#ifndef F_1
F_7 ( V_14 , L_9 ) ;
#endif
F_7 ( V_14 , L_10 , V_19 , V_19 ) ;
F_7 ( V_14 , L_11 ) ;
goto V_18;
}
#ifndef F_1
V_3 = F_8 ( V_14 , V_13 , 0 ) ;
#endif
F_9 ( NULL , V_14 , ( V_9 != NULL ) ) ;
if ( V_9 != NULL )
F_7 ( V_14 , L_12 ,
F_10 ( V_9 ) ) ;
V_11 = F_3 ( F_4 () ) ;
if ( V_11 == NULL )
goto V_18;
if ( V_8 != NULL )
V_5 = F_11 ( V_11 , V_8 ) ;
else
{
V_5 = F_5 ( V_11 , stdout , V_16 | V_17 ) ;
#ifdef F_12
{
T_2 * V_20 = F_3 ( F_13 () ) ;
V_11 = F_14 ( V_20 , V_11 ) ;
}
#endif
}
if ( V_5 <= 0 )
goto V_18;
if ( V_10 )
{
T_2 * V_21 = F_3 ( F_15 () ) ;
if ( V_21 == NULL )
goto V_18;
V_11 = F_14 ( V_21 , V_11 ) ;
}
while ( V_12 > 0 )
{
unsigned char V_22 [ 4096 ] ;
int V_23 ;
V_23 = V_12 ;
if ( V_23 > ( int ) sizeof( V_22 ) )
V_23 = sizeof V_22 ;
V_5 = F_16 ( V_22 , V_23 ) ;
if ( V_5 <= 0 )
goto V_18;
F_17 ( V_11 , V_22 , V_23 ) ;
V_12 -= V_23 ;
}
F_18 ( V_11 ) ;
F_19 ( NULL , V_14 ) ;
V_6 = 0 ;
V_18:
F_20 ( V_14 ) ;
if ( V_11 )
F_21 ( V_11 ) ;
F_22 () ;
F_23 ( V_6 ) ;
}
