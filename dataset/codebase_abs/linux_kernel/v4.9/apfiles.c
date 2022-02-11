static int F_1 ( char * V_1 )
{
#ifndef F_2
struct V_2 V_3 ;
if ( ! V_2 ( V_1 , & V_3 ) ) {
fprintf ( V_4 ,
L_1 ) ;
if ( getchar () != 'y' ) {
return ( - 1 ) ;
}
}
#endif
return 0 ;
}
int F_3 ( char * V_1 )
{
T_1 V_5 ;
if ( F_1 ( V_1 ) != 0 ) {
return ( - 1 ) ;
}
V_5 = fopen ( V_1 , L_2 ) ;
if ( ! V_5 ) {
fprintf ( V_4 , L_3 , V_1 ) ;
return ( - 1 ) ;
}
V_6 = V_5 ;
V_7 = V_1 ;
return ( 0 ) ;
}
int F_4 ( struct V_8 * V_9 , T_2 V_10 )
{
char V_11 [ V_12 + 16 ] ;
char V_13 [ 16 ] ;
T_1 V_5 ;
T_3 V_14 ;
T_2 V_15 ;
V_15 = F_5 ( V_9 ) ;
if ( F_6 ( V_9 -> V_16 ) ) {
F_7 ( V_11 , V_17 ) ;
} else {
F_7 ( V_11 , V_9 -> V_16 ) ;
}
V_11 [ 0 ] = ( char ) tolower ( ( int ) V_11 [ 0 ] ) ;
V_11 [ 1 ] = ( char ) tolower ( ( int ) V_11 [ 1 ] ) ;
V_11 [ 2 ] = ( char ) tolower ( ( int ) V_11 [ 2 ] ) ;
V_11 [ 3 ] = ( char ) tolower ( ( int ) V_11 [ 3 ] ) ;
V_11 [ V_12 ] = 0 ;
if ( V_10 > 0 ) {
snprintf ( V_13 , sizeof( V_13 ) , L_4 , V_10 ) ;
strcat ( V_11 , V_13 ) ;
}
strcat ( V_11 , V_18 ) ;
if ( V_19 ) {
fprintf ( V_4 ,
L_5 ,
V_9 -> V_16 , V_11 , V_9 -> V_20 ,
V_9 -> V_20 ) ;
}
V_5 = fopen ( V_11 , L_6 ) ;
if ( ! V_5 ) {
fprintf ( V_4 , L_3 , V_11 ) ;
return ( - 1 ) ;
}
V_14 = fwrite ( V_9 , 1 , V_15 , V_5 ) ;
if ( V_14 != V_15 ) {
fprintf ( V_4 , L_7 ,
V_11 ) ;
fclose ( V_5 ) ;
return ( - 1 ) ;
}
fclose ( V_5 ) ;
return ( 0 ) ;
}
struct V_8 * F_8 ( char * V_1 ,
T_2 * V_21 )
{
struct V_8 * V_22 = NULL ;
T_1 V_5 ;
T_2 V_23 ;
T_3 V_14 ;
V_5 = fopen ( V_1 , L_8 ) ;
if ( ! V_5 ) {
fprintf ( V_4 , L_9 , V_1 ) ;
return ( NULL ) ;
}
V_23 = F_9 ( V_5 ) ;
if ( V_23 == V_24 ) {
fprintf ( V_4 ,
L_10 , V_1 ) ;
goto V_25;
}
V_22 = F_10 ( V_23 ) ;
if ( ! V_22 ) {
fprintf ( V_4 ,
L_11 ,
V_23 ) ;
goto V_25;
}
V_14 = fread ( V_22 , 1 , V_23 , V_5 ) ;
if ( V_14 != V_23 ) {
fprintf ( V_4 , L_12 , V_1 ) ;
F_11 ( V_22 ) ;
V_22 = NULL ;
goto V_25;
}
* V_21 = V_23 ;
V_25:
fclose ( V_5 ) ;
return ( V_22 ) ;
}
