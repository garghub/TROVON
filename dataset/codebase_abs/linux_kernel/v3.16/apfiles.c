int F_1 ( char * V_1 )
{
struct V_2 V_3 ;
T_1 * V_4 ;
if ( ! V_2 ( V_1 , & V_3 ) ) {
fprintf ( V_5 ,
L_1 ) ;
if ( getchar () != 'y' ) {
return ( - 1 ) ;
}
}
V_4 = freopen ( V_1 , L_2 , stdout ) ;
if ( ! V_4 ) {
perror ( L_3 ) ;
return ( - 1 ) ;
}
V_6 = V_4 ;
V_7 = V_1 ;
return ( 0 ) ;
}
int F_2 ( struct V_8 * V_9 , T_2 V_10 )
{
char V_11 [ V_12 + 16 ] ;
char V_13 [ 16 ] ;
T_1 * V_4 ;
T_3 V_14 ;
T_2 V_15 ;
V_15 = F_3 ( V_9 ) ;
if ( F_4 ( V_9 -> V_16 ) ) {
F_5 ( V_11 , V_17 ) ;
} else {
F_5 ( V_11 , V_9 -> V_16 ) ;
}
V_11 [ 0 ] = ( char ) F_6 ( V_11 [ 0 ] ) ;
V_11 [ 1 ] = ( char ) F_6 ( V_11 [ 1 ] ) ;
V_11 [ 2 ] = ( char ) F_6 ( V_11 [ 2 ] ) ;
V_11 [ 3 ] = ( char ) F_6 ( V_11 [ 3 ] ) ;
V_11 [ V_12 ] = 0 ;
if ( V_10 > 0 ) {
sprintf ( V_13 , L_4 , V_10 ) ;
strcat ( V_11 , V_13 ) ;
}
strcat ( V_11 , V_18 ) ;
if ( V_19 ) {
fprintf ( V_5 ,
L_5 ,
V_9 -> V_16 , V_11 , V_9 -> V_20 ,
V_9 -> V_20 ) ;
}
V_4 = fopen ( V_11 , L_6 ) ;
if ( ! V_4 ) {
perror ( L_3 ) ;
return ( - 1 ) ;
}
V_14 = fwrite ( V_9 , 1 , V_15 , V_4 ) ;
if ( V_14 != V_15 ) {
perror ( L_7 ) ;
fclose ( V_4 ) ;
return ( - 1 ) ;
}
fclose ( V_4 ) ;
return ( 0 ) ;
}
struct V_8 * F_7 ( char * V_1 ,
T_2 * V_21 )
{
struct V_8 * V_22 = NULL ;
T_1 * V_4 ;
T_2 V_23 ;
T_3 V_14 ;
V_4 = fopen ( V_1 , L_8 ) ;
if ( ! V_4 ) {
perror ( L_9 ) ;
return ( NULL ) ;
}
V_23 = F_8 ( V_4 ) ;
if ( V_23 == V_24 ) {
fprintf ( V_5 ,
L_10 , V_1 ) ;
goto V_25;
}
V_22 = calloc ( 1 , V_23 ) ;
if ( ! V_22 ) {
fprintf ( V_5 ,
L_11 ,
V_23 ) ;
goto V_25;
}
V_14 = fread ( V_22 , 1 , V_23 , V_4 ) ;
if ( V_14 != V_23 ) {
fprintf ( V_5 , L_12 , V_1 ) ;
free ( V_22 ) ;
V_22 = NULL ;
goto V_25;
}
* V_21 = V_23 ;
V_25:
fclose ( V_4 ) ;
return ( V_22 ) ;
}
