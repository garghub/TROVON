static int F_1 ( char * V_1 )
{
#ifndef F_2
struct V_2 V_3 ;
if ( ! V_2 ( V_1 , & V_3 ) ) {
F_3 ( L_1 ) ;
if ( getchar () != 'y' ) {
return ( - 1 ) ;
}
}
#endif
return 0 ;
}
int F_4 ( char * V_1 )
{
T_1 V_4 ;
if ( F_1 ( V_1 ) != 0 ) {
return ( - 1 ) ;
}
V_4 = F_5 ( V_1 , V_5 ) ;
if ( ! V_4 ) {
F_3 ( L_2 , V_1 ) ;
return ( - 1 ) ;
}
V_6 = V_4 ;
V_7 = V_1 ;
return ( 0 ) ;
}
int F_6 ( struct V_8 * V_9 , T_2 V_10 )
{
char V_11 [ V_12 + 16 ] ;
char V_13 [ 16 ] ;
T_1 V_4 ;
T_3 V_14 ;
T_2 V_15 ;
V_15 = F_7 ( V_9 ) ;
if ( F_8 ( V_9 -> V_16 ) ) {
F_9 ( V_11 , V_17 ) ;
} else {
F_9 ( V_11 , V_9 -> V_16 ) ;
}
V_11 [ 0 ] = ( char ) F_10 ( V_11 [ 0 ] ) ;
V_11 [ 1 ] = ( char ) F_10 ( V_11 [ 1 ] ) ;
V_11 [ 2 ] = ( char ) F_10 ( V_11 [ 2 ] ) ;
V_11 [ 3 ] = ( char ) F_10 ( V_11 [ 3 ] ) ;
V_11 [ V_12 ] = 0 ;
if ( V_10 > 0 ) {
F_11 ( V_13 , sizeof( V_13 ) , L_3 ,
V_10 ) ;
F_12 ( V_11 , V_13 ) ;
}
F_12 ( V_11 , V_18 ) ;
if ( V_19 ) {
F_3
( L_4 ,
V_9 -> V_16 , V_11 , V_9 -> V_20 , V_9 -> V_20 ) ;
}
V_4 = F_5 ( V_11 ,
V_5 | V_21 ) ;
if ( ! V_4 ) {
F_3 ( L_2 , V_11 ) ;
return ( - 1 ) ;
}
V_14 = F_13 ( V_4 , V_9 , 1 , V_15 ) ;
if ( V_14 != V_15 ) {
F_3 ( L_5 ,
V_11 ) ;
F_14 ( V_4 ) ;
return ( - 1 ) ;
}
F_14 ( V_4 ) ;
return ( 0 ) ;
}
struct V_8 * F_15 ( char * V_1 ,
T_2 * V_22 )
{
struct V_8 * V_23 = NULL ;
T_1 V_4 ;
T_2 V_24 ;
T_3 V_14 ;
V_4 =
F_5 ( V_1 , V_25 | V_21 ) ;
if ( ! V_4 ) {
F_3 ( L_6 , V_1 ) ;
return ( NULL ) ;
}
V_24 = F_16 ( V_4 ) ;
if ( V_24 == V_26 ) {
F_3 ( L_7 , V_1 ) ;
goto V_27;
}
V_23 = F_17 ( V_24 ) ;
if ( ! V_23 ) {
F_3 ( L_8 ,
V_24 ) ;
goto V_27;
}
V_14 = F_18 ( V_4 , V_23 , 1 , V_24 ) ;
if ( V_14 != V_24 ) {
F_3 ( L_9 , V_1 ) ;
F_19 ( V_23 ) ;
V_23 = NULL ;
goto V_27;
}
* V_22 = V_24 ;
V_27:
F_14 ( V_4 ) ;
return ( V_23 ) ;
}
