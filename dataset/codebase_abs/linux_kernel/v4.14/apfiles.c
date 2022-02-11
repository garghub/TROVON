static int F_1 ( char * V_1 )
{
#if ! F_2 ( V_2 ) && ! F_2 ( V_3 )
struct V_4 V_5 ;
if ( ! V_4 ( V_1 , & V_5 ) ) {
fprintf ( V_6 ,
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
T_1 V_7 ;
if ( F_1 ( V_1 ) != 0 ) {
return ( - 1 ) ;
}
V_7 = fopen ( V_1 , L_2 ) ;
if ( ! V_7 ) {
fprintf ( V_6 , L_3 , V_1 ) ;
return ( - 1 ) ;
}
V_8 = V_7 ;
V_9 = V_1 ;
return ( 0 ) ;
}
int F_4 ( struct V_10 * V_11 , T_2 V_12 )
{
char V_13 [ V_14 + 16 ] ;
char V_15 [ 16 ] ;
T_1 V_7 ;
T_3 V_16 ;
T_2 V_17 ;
V_17 = F_5 ( V_11 ) ;
if ( F_6 ( V_11 -> V_18 ) ) {
F_7 ( V_13 , V_19 ) ;
} else {
F_7 ( V_13 , V_11 -> V_18 ) ;
}
V_13 [ 0 ] = ( char ) tolower ( ( int ) V_13 [ 0 ] ) ;
V_13 [ 1 ] = ( char ) tolower ( ( int ) V_13 [ 1 ] ) ;
V_13 [ 2 ] = ( char ) tolower ( ( int ) V_13 [ 2 ] ) ;
V_13 [ 3 ] = ( char ) tolower ( ( int ) V_13 [ 3 ] ) ;
V_13 [ V_14 ] = 0 ;
if ( V_12 > 0 ) {
snprintf ( V_15 , sizeof( V_15 ) , L_4 , V_12 ) ;
strcat ( V_13 , V_15 ) ;
}
strcat ( V_13 , V_20 ) ;
if ( V_21 ) {
fprintf ( V_6 ,
L_5 ,
V_11 -> V_18 , V_13 , V_11 -> V_22 ,
V_11 -> V_22 ) ;
}
V_7 = fopen ( V_13 , L_6 ) ;
if ( ! V_7 ) {
fprintf ( V_6 , L_3 , V_13 ) ;
return ( - 1 ) ;
}
V_16 = fwrite ( V_11 , 1 , V_17 , V_7 ) ;
if ( V_16 != V_17 ) {
fprintf ( V_6 , L_7 ,
V_13 ) ;
fclose ( V_7 ) ;
return ( - 1 ) ;
}
fclose ( V_7 ) ;
return ( 0 ) ;
}
struct V_10 * F_8 ( char * V_1 ,
T_2 * V_23 )
{
struct V_10 * V_24 = NULL ;
T_1 V_7 ;
T_2 V_25 ;
T_3 V_16 ;
V_7 = fopen ( V_1 , L_8 ) ;
if ( ! V_7 ) {
fprintf ( V_6 , L_9 , V_1 ) ;
return ( NULL ) ;
}
V_25 = F_9 ( V_7 ) ;
if ( V_25 == V_26 ) {
fprintf ( V_6 ,
L_10 , V_1 ) ;
goto V_27;
}
V_24 = F_10 ( V_25 ) ;
if ( ! V_24 ) {
fprintf ( V_6 ,
L_11 ,
V_25 ) ;
goto V_27;
}
V_16 = fread ( V_24 , 1 , V_25 , V_7 ) ;
if ( V_16 != V_25 ) {
fprintf ( V_6 , L_12 , V_1 ) ;
F_11 ( V_24 ) ;
V_24 = NULL ;
goto V_27;
}
* V_23 = V_25 ;
V_27:
fclose ( V_7 ) ;
return ( V_24 ) ;
}
