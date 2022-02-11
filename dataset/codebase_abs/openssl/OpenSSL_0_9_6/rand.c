int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 , V_5 = 1 ;
int V_6 ;
char * V_7 = NULL ;
char * V_8 = NULL ;
int V_9 = 0 ;
T_1 * V_10 = NULL ;
int V_11 = - 1 ;
F_1 () ;
if ( V_12 == NULL )
if ( ( V_12 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_12 , V_13 , V_14 | V_15 ) ;
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
else if ( strcmp ( V_2 [ V_3 ] , L_2 ) == 0 )
{
if ( ( V_2 [ V_3 + 1 ] != NULL ) && ( V_8 == NULL ) )
V_8 = V_2 [ ++ V_3 ] ;
else
V_6 = 1 ;
}
else if ( strcmp ( V_2 [ V_3 ] , L_3 ) == 0 )
{
if ( ! V_9 )
V_9 = 1 ;
else
V_6 = 1 ;
}
else if ( isdigit ( ( unsigned char ) V_2 [ V_3 ] [ 0 ] ) )
{
if ( V_11 < 0 )
{
V_4 = sscanf ( V_2 [ V_3 ] , L_4 , & V_11 ) ;
if ( V_4 == 0 || V_11 < 0 )
V_6 = 1 ;
}
else
V_6 = 1 ;
}
else
V_6 = 1 ;
}
if ( V_11 < 0 )
V_6 = 1 ;
if ( V_6 )
{
F_5 ( V_12 , L_5 ) ;
F_5 ( V_12 , L_6 ) ;
F_5 ( V_12 , L_7 ) ;
F_5 ( V_12 , L_8 , V_16 , V_16 ) ;
F_5 ( V_12 , L_9 ) ;
goto V_17;
}
F_6 ( NULL , V_12 , ( V_8 != NULL ) ) ;
if ( V_8 != NULL )
F_5 ( V_12 , L_10 ,
F_7 ( V_8 ) ) ;
V_10 = F_2 ( F_3 () ) ;
if ( V_10 == NULL )
goto V_17;
if ( V_7 != NULL )
V_4 = F_8 ( V_10 , V_7 ) ;
else
{
V_4 = F_4 ( V_10 , stdout , V_14 | V_15 ) ;
#ifdef F_9
{
T_1 * V_18 = F_2 ( F_10 () ) ;
V_10 = F_11 ( V_18 , V_10 ) ;
}
#endif
}
if ( V_4 <= 0 )
goto V_17;
if ( V_9 )
{
T_1 * V_19 = F_2 ( F_12 () ) ;
if ( V_19 == NULL )
goto V_17;
V_10 = F_11 ( V_19 , V_10 ) ;
}
while ( V_11 > 0 )
{
unsigned char V_20 [ 4096 ] ;
int V_21 ;
V_21 = V_11 ;
if ( V_21 > sizeof V_20 )
V_21 = sizeof V_20 ;
V_4 = F_13 ( V_20 , V_21 ) ;
if ( V_4 <= 0 )
goto V_17;
F_14 ( V_10 , V_20 , V_21 ) ;
V_11 -= V_21 ;
}
F_15 ( V_10 ) ;
F_16 ( NULL , V_12 ) ;
V_5 = 0 ;
V_17:
F_17 ( V_12 ) ;
if ( V_10 )
F_18 ( V_10 ) ;
EXIT ( V_5 ) ;
}
