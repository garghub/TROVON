int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 , V_5 = 1 ;
int V_6 ;
char * V_7 = NULL ;
char * V_8 = NULL ;
int V_9 = 0 ;
int V_10 = 0 ;
T_1 * V_11 = NULL ;
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
V_6 = 0 ;
V_3 = 0 ;
while ( ! V_6 && V_2 [ ++ V_3 ] != NULL )
{
if ( strcmp ( V_2 [ V_3 ] , L_1 ) == 0 )
{
if ( ( V_2 [ V_3 + 1 ] != NULL ) && ( V_7 == NULL ) )
V_7 = V_2 [ ++ V_3 ] ;
else
V_6 = 1 ;
}
#ifndef F_1
else if ( strcmp ( V_2 [ V_3 ] , L_2 ) == 0 )
{
if ( ( V_2 [ V_3 + 1 ] != NULL ) && ( V_13 == NULL ) )
V_13 = V_2 [ ++ V_3 ] ;
else
V_6 = 1 ;
}
#endif
else if ( strcmp ( V_2 [ V_3 ] , L_3 ) == 0 )
{
if ( ( V_2 [ V_3 + 1 ] != NULL ) && ( V_8 == NULL ) )
V_8 = V_2 [ ++ V_3 ] ;
else
V_6 = 1 ;
}
else if ( strcmp ( V_2 [ V_3 ] , L_4 ) == 0 )
{
if ( ! V_9 )
V_9 = 1 ;
else
V_6 = 1 ;
}
else if ( strcmp ( V_2 [ V_3 ] , L_5 ) == 0 )
{
if ( ! V_10 )
V_10 = 1 ;
else
V_6 = 1 ;
}
else if ( isdigit ( ( unsigned char ) V_2 [ V_3 ] [ 0 ] ) )
{
if ( V_12 < 0 )
{
V_4 = sscanf ( V_2 [ V_3 ] , L_6 , & V_12 ) ;
if ( V_4 == 0 || V_12 < 0 )
V_6 = 1 ;
}
else
V_6 = 1 ;
}
else
V_6 = 1 ;
}
if ( V_10 && V_9 )
V_6 = 1 ;
if ( V_12 < 0 )
V_6 = 1 ;
if ( V_6 )
{
F_7 ( V_14 , L_7 ) ;
F_7 ( V_14 , L_8 ) ;
F_7 ( V_14 , L_9 ) ;
#ifndef F_1
F_7 ( V_14 , L_10 ) ;
#endif
F_7 ( V_14 , L_11 , V_19 , V_19 ) ;
F_7 ( V_14 , L_12 ) ;
F_7 ( V_14 , L_13 ) ;
goto V_18;
}
#ifndef F_1
F_8 ( V_14 , V_13 , 0 ) ;
#endif
F_9 ( NULL , V_14 , ( V_8 != NULL ) ) ;
if ( V_8 != NULL )
F_7 ( V_14 , L_14 ,
F_10 ( V_8 ) ) ;
V_11 = F_3 ( F_4 () ) ;
if ( V_11 == NULL )
goto V_18;
if ( V_7 != NULL )
V_4 = F_11 ( V_11 , V_7 ) ;
else
{
V_4 = F_5 ( V_11 , stdout , V_16 | V_17 ) ;
#ifdef F_12
{
T_1 * V_20 = F_3 ( F_13 () ) ;
V_11 = F_14 ( V_20 , V_11 ) ;
}
#endif
}
if ( V_4 <= 0 )
goto V_18;
if ( V_9 )
{
T_1 * V_21 = F_3 ( F_15 () ) ;
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
V_4 = F_16 ( V_22 , V_23 ) ;
if ( V_4 <= 0 )
goto V_18;
if ( ! V_10 )
F_17 ( V_11 , V_22 , V_23 ) ;
else
{
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ )
F_7 ( V_11 , L_15 , V_22 [ V_3 ] ) ;
}
V_12 -= V_23 ;
}
if ( V_10 )
F_18 ( V_11 , L_16 ) ;
( void ) F_19 ( V_11 ) ;
F_20 ( NULL , V_14 ) ;
V_5 = 0 ;
V_18:
F_21 ( V_14 ) ;
if ( V_11 )
F_22 ( V_11 ) ;
F_23 () ;
F_24 ( V_5 ) ;
}
