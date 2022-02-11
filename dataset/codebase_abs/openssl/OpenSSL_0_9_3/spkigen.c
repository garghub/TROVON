int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
T_3 * V_1 = NULL ;
T_4 * V_2 = NULL ;
T_5 * V_3 = NULL ;
char V_4 [ 128 ] ;
int V_5 = 0 , V_6 ;
T_6 * V_7 ;
V_3 = F_1 () ;
if ( T_1 < 2 )
{
fprintf ( V_8 , L_1 ) ;
if ( ( V_1 = F_2 ( 512 , V_9 , NULL ) ) == NULL ) goto V_10;
}
else
{
if ( ( V_7 = fopen ( T_2 [ 1 ] , L_2 ) ) == NULL )
{ perror ( T_2 [ 1 ] ) ; goto V_10; }
if ( ( V_1 = F_3 ( V_7 , NULL , NULL ) ) == NULL )
goto V_10;
fclose ( V_7 ) ;
}
if ( ! F_4 ( V_3 , V_1 ) ) goto V_10;
V_1 = NULL ;
if ( ( V_2 = F_5 () ) == NULL ) goto V_10;
if ( ! F_6 ( V_2 , V_3 ) ) goto V_10;
fprintf ( V_8 , L_3 ) ;
fflush ( V_8 ) ;
fgets ( V_4 , 120 , V_11 ) ;
V_6 = strlen ( V_4 ) ;
if ( V_6 > 0 ) V_4 [ -- V_6 ] = '\0' ;
if ( ! F_7 ( ( V_12 * ) V_2 -> V_13 -> V_14 ,
V_4 , V_6 ) ) goto V_10;
if ( ! F_8 ( V_2 , V_3 , F_9 () ) ) goto V_10;
F_10 ( stdout , V_2 ) ;
if ( T_1 < 2 )
F_11 ( stdout , V_3 -> V_3 . V_1 , NULL , NULL , 0 , NULL ) ;
V_5 = 1 ;
V_10:
if ( ! V_5 )
{
fprintf ( V_8 , L_4 ) ;
F_12 ( V_8 ) ;
}
F_13 ( V_2 ) ;
F_14 ( V_3 ) ;
exit ( ! V_5 ) ;
}
int F_15 ( V_3 , type , T_7 )
T_5 * V_3 ;
int type ;
char * T_7 ;
{
if ( V_3 == NULL ) return ( 0 ) ;
if ( V_3 -> V_3 . V_15 != NULL )
{
if ( V_3 -> type == V_16 )
F_16 ( V_3 -> V_3 . V_1 ) ;
}
V_3 -> type = type ;
V_3 -> V_3 . V_15 = T_7 ;
return ( 1 ) ;
}
int F_6 ( T_8 , V_3 )
T_4 * T_8 ;
T_5 * V_3 ;
{
int V_5 = 0 ;
T_9 * V_17 ;
T_10 * V_18 ;
T_11 * V_19 ;
unsigned char * V_20 , * V_21 ;
int V_6 ;
if ( T_8 == NULL ) return ( 0 ) ;
if ( ( V_17 = F_17 () ) == NULL ) goto V_10;
V_18 = V_17 -> V_22 ;
if ( ( V_19 = F_18 ( V_3 -> type ) ) == NULL ) goto V_10;
F_19 ( V_18 -> V_23 ) ;
V_18 -> V_23 = V_19 ;
if ( ( V_18 -> V_24 == NULL ) || ( V_18 -> V_24 -> type != V_25 ) )
{
F_20 ( V_18 -> V_24 ) ;
V_18 -> V_24 = F_21 () ;
V_18 -> V_24 -> type = V_25 ;
}
V_6 = F_22 ( V_3 , NULL ) ;
if ( ( V_20 = ( unsigned char * ) malloc ( V_6 + 1 ) ) == NULL ) goto V_10;
V_21 = V_20 ;
F_22 ( V_3 , & V_21 ) ;
if ( ! F_23 ( V_17 -> V_26 , V_20 , V_6 ) ) goto V_10;
free ( V_20 ) ;
F_24 ( T_8 -> V_13 -> V_27 ) ;
T_8 -> V_13 -> V_27 = V_17 ;
V_17 = NULL ;
V_5 = 1 ;
V_10:
if ( V_17 != NULL ) F_24 ( V_17 ) ;
return ( V_5 ) ;
}
