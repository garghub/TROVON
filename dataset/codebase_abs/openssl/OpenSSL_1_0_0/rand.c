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
int V_11 = 0 ;
T_2 * V_12 = NULL ;
int V_13 = - 1 ;
#ifndef F_1
char * V_14 = NULL ;
#endif
F_2 () ;
if ( V_15 == NULL )
if ( ( V_15 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_15 , V_16 , V_17 | V_18 ) ;
if ( ! F_6 ( V_15 , NULL ) )
goto V_19;
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
if ( ( V_2 [ V_4 + 1 ] != NULL ) && ( V_14 == NULL ) )
V_14 = V_2 [ ++ V_4 ] ;
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
else if ( strcmp ( V_2 [ V_4 ] , L_5 ) == 0 )
{
if ( ! V_11 )
V_11 = 1 ;
else
V_7 = 1 ;
}
else if ( isdigit ( ( unsigned char ) V_2 [ V_4 ] [ 0 ] ) )
{
if ( V_13 < 0 )
{
V_5 = sscanf ( V_2 [ V_4 ] , L_6 , & V_13 ) ;
if ( V_5 == 0 || V_13 < 0 )
V_7 = 1 ;
}
else
V_7 = 1 ;
}
else
V_7 = 1 ;
}
if ( V_11 && V_10 )
V_7 = 1 ;
if ( V_13 < 0 )
V_7 = 1 ;
if ( V_7 )
{
F_7 ( V_15 , L_7 ) ;
F_7 ( V_15 , L_8 ) ;
F_7 ( V_15 , L_9 ) ;
#ifndef F_1
F_7 ( V_15 , L_10 ) ;
#endif
F_7 ( V_15 , L_11 , V_20 , V_20 ) ;
F_7 ( V_15 , L_12 ) ;
F_7 ( V_15 , L_13 ) ;
goto V_19;
}
#ifndef F_1
V_3 = F_8 ( V_15 , V_14 , 0 ) ;
#endif
F_9 ( NULL , V_15 , ( V_9 != NULL ) ) ;
if ( V_9 != NULL )
F_7 ( V_15 , L_14 ,
F_10 ( V_9 ) ) ;
V_12 = F_3 ( F_4 () ) ;
if ( V_12 == NULL )
goto V_19;
if ( V_8 != NULL )
V_5 = F_11 ( V_12 , V_8 ) ;
else
{
V_5 = F_5 ( V_12 , stdout , V_17 | V_18 ) ;
#ifdef F_12
{
T_2 * V_21 = F_3 ( F_13 () ) ;
V_12 = F_14 ( V_21 , V_12 ) ;
}
#endif
}
if ( V_5 <= 0 )
goto V_19;
if ( V_10 )
{
T_2 * V_22 = F_3 ( F_15 () ) ;
if ( V_22 == NULL )
goto V_19;
V_12 = F_14 ( V_22 , V_12 ) ;
}
while ( V_13 > 0 )
{
unsigned char V_23 [ 4096 ] ;
int V_24 ;
V_24 = V_13 ;
if ( V_24 > ( int ) sizeof( V_23 ) )
V_24 = sizeof V_23 ;
V_5 = F_16 ( V_23 , V_24 ) ;
if ( V_5 <= 0 )
goto V_19;
if ( ! V_11 )
F_17 ( V_12 , V_23 , V_24 ) ;
else
{
for ( V_4 = 0 ; V_4 < V_24 ; V_4 ++ )
F_7 ( V_12 , L_15 , V_23 [ V_4 ] ) ;
}
V_13 -= V_24 ;
}
if ( V_11 )
F_18 ( V_12 , L_16 ) ;
( void ) F_19 ( V_12 ) ;
F_20 ( NULL , V_15 ) ;
V_6 = 0 ;
V_19:
F_21 ( V_15 ) ;
if ( V_12 )
F_22 ( V_12 ) ;
F_23 () ;
F_24 ( V_6 ) ;
}
